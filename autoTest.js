/* eslint-disable no-restricted-globals */
const APP = {
	parsingexcel: "parsingexcel.exe",
	headerGenerator: "headerGenerator.exe",
	basic_test: "basic_test.exe",
}

const ERR_STR = {
	Unexpected_parameter: "Unexpected parameter",
}

function isString(object) {
    return typeof object === "string" ? true : false;
};

function isLegalChipType(chipType) {
	if (g_chipTypes.includes(chipType)){
		return true;
	}
	else {
		return false;
	}
};

function isLegalPartNo(partNo) {
	if(/^[A-Z0-9()]+$/.test(partNo)){
		return true;
	}
	else {
		return false;
	}
};

const pause = async (s) => {
	return new Promise(resolve => {
		setTimeout(resolve,s); 
	});
};

const getTypeById = (id) => {
	for(let obj of g_perControls[g_snippetName]){
		if (id === obj.id) {
			return obj["type"];
		}
	}
	return null;
};

const updateLocalPerControlsV2 = function(id, newData, dependencies, dependenciesOption) {
	//let controls = g_perControls[g_snippetName];
	if(dependencies === "none"){
		// NOOP
	}
	else if ( typeof dependencies === "string"){
		if (dependencies.includes("|") || dependencies.includes("&")) {
			// should redirect to case "typeof dependencies === object"
			dependencies = dependencies.split(/[|&() ]/).filter(x => x !== "");
			updateLocalPerControlsV2(id, newData, dependencies, dependenciesOption);
			return;
		}
		else {
			if(typeof dependenciesOption[dependencies] !== "undefined"){
				dependenciesOption = dependenciesOption[dependencies];
			}
			// Just match one
			if (typeof dependenciesOption === "object"){
				dependenciesOption = dependenciesOption[0];
			}
			if (typeof dependenciesOption === "string"){
				if (dependenciesOption.includes("|")) {
					// EX: dependenciesOption:{"PWM0CH01BrakeSRCMultiselect":"PWM_FB_EDGE_BKP0|PWM_FB_EDGE_BKP1"};
					if(EXPORT_REACT.CONF_TYPE.MULTIPLESELECT === getTypeById(dependencies)){
						// NOOP
					}
					else {
						// EX: dependenciesOption:NUCODEGEN_UART0_FUNCSEL_UART|NUCODEGEN_UART0_FUNCSEL_SINGLE_WIRE|NUCODEGEN_UART0_FUNCSEL_IrDA;
						dependenciesOption = dependenciesOption.split(/[|() ]/).filter(x => x !== "")[0];
					}
				}
				// EX: =16, ==16, >=16, <=16
				else if(dependenciesOption.includes("=")){
					dependenciesOption = dependenciesOption.replace(/[^0-9]/ig,"");
				}
				// EX: >16
				else if(dependenciesOption.includes(">")){
					dependenciesOption = Number(dependenciesOption.replace(/[^0-9]/ig,"")) + 1;
				}
				// EX: <16
				else if(dependenciesOption.includes("<")){
					dependenciesOption = Number(dependenciesOption.replace(/[^0-9]/ig,"")) - 1;
				}
			}
			// Handle dependencies for deep layers
			let dependenciesObj = g_perControls[g_snippetName].find(x => x.id === dependencies);
			updateLocalPerControlsV2(
				dependencies, // Same as dependenciesObj.id
				dependenciesOption,
				dependenciesObj && dependenciesObj.dependencies,
				dependenciesObj && dependenciesObj.dependenciesOption
			);
		}
	}
	// EX: [CLK_PowerDownEnableRadio, CLK_PowerDownModeSelect]
	else if (typeof dependencies === "object") {
		for(let dependency of dependencies){
			// Handle dependencies for deep layers
			let dependenciesObj = g_perControls[g_snippetName].find(x => x.id === dependency);
			updateLocalPerControlsV2(
				dependency, // Same as dependenciesObj.id
				dependenciesOption[dependency],
				dependenciesObj && dependenciesObj.dependencies,
				dependenciesObj && dependenciesObj.dependenciesOption
			);
		}
	}
	else {
		// NOOP
	}

	for(let obj of g_perControls[g_snippetName]){
		if (id === obj.id) {
			obj["data"] = newData;
			// obj["default"] = [newData];
		}
		if(id === obj.observable) {
			obj["data"] = obj["listener"][newData];
		}
	}
}

const updateDom = async (func) => {
	try {
		await func();
	}
	catch(e){
		// console.warn(" error]");
		EXPORT_REACT._D("[updateDom] " + e);
	}
}

external.changePartNo = async function(partNo){
	if (!partNo) return;
	return new Promise(resolve => {
		let newChipType = EXPORT_REACT.decideNewChipType(partNo);
		let oldfilename = 'NUC_' + g_chipType + '_Content.js';
		let newfilename = 'NUC_' + newChipType + '_Content.js';

		EXPORT_REACT.replacejscssfile(oldfilename, newfilename, 'js', function(){
			let newPartNumberPkg = EXPORT_REACT.decideNewPartNumberPkg(partNo);
			let newPartNumberType = EXPORT_REACT.decideNewPartNumberType(partNo);
			let newPartNumberPackage = partNo + "(" + newPartNumberPkg + ")";
			EXPORT_REACT.initializeAll();
			EXPORT_REACT.setChipType(newChipType);
			EXPORT_REACT.set_partNumber_package(newPartNumberPackage);
			EXPORT_REACT.set_partNumber_type((newPartNumberType));
			EXPORT_REACT.set_cfg_perFunctions([]);
			EXPORT_REACT.setSnippetName('');
			resolve();
		});
	});
};

external.parsingexcel = async function(chipType, peripherals){
	const { exec } = window.child_process;
	const m_appPathCString = window.__dirname;

	// Handle params chipType
	if (isLegalChipType(chipType)){
		// NOOP
	}
	else if(isString(chipType)){
		EXPORT_REACT.notification_error(ERR_STR.Unexpected_parameter, "'chipType' in parsingexcel(): " + chipType);
		return;
	}
	else {
		chipType = g_chipType;
	}

	// Handle params peripheralsStr
	if(/^[A-Z0-9_+ ]+$/.test(peripherals) || peripherals === "all") {
		peripherals = peripherals.replaceAll("+", " ");
	}
	else if(isString(peripherals)){
		EXPORT_REACT.notification_error(ERR_STR.Unexpected_parameter, "'peripherals' in parsingexcel(): " + peripherals);
		return;
	}
	else {
		peripherals = "all";
	}
	////////////////////////////////////////////

	var directoryString = m_appPathCString + PATH.AutoTest;
	var fileString = standardArgv(directoryString + APP.parsingexcel);
	var parametersString = standardArgv(chipType + " TagReg Mapping Table.xlsx") + peripherals;

	EXPORT_REACT.mask(APP.parsingexcel);
	return new Promise(resolve => {
		exec(fileString + parametersString, { cwd: directoryString }, (err, stdout, stderr) => {
			EXPORT_REACT.unmask();
			if (err) {
				console.error(APP.parsingexcel + "\n" + stderr);
				EXPORT_REACT.notification_error(APP.parsingexcel, stderr);
			}
			else {
				console.log(APP.parsingexcel + "\n" + stdout);
				EXPORT_REACT.notification_success(APP.parsingexcel, stdout, 5);
				resolve();
			}
		})
	});
};

external.headerGenerator = async function(partNo, peripherals, tagId) {
	// Constants
	const { CONF_TYPE, HEXTEXT_PREFIX } = EXPORT_REACT;

	// Handle params partNo
	if (isLegalPartNo(partNo)){
		await external.changePartNo(partNo.trim());
	}
	else if(isString(partNo)){
		EXPORT_REACT.notification_error(ERR_STR.Unexpected_parameter, "'partNo' in headerGenerator(): " + partNo);
		return;
	}
	else {
		partNo = g_partNumber_package;
	}

	// Handle params peripherals
	if(peripherals === "All"){
		peripherals = [];
		var moduleNames = EXPORT_REACT.getPropertyNames(g_module_snippet_primitive);
		for(let module of moduleNames) {
			for(let snippet of g_module_snippet_primitive[module]){
				peripherals.push(snippet);
			}
		}
	}
	else if(/^[A-Z0-9_+ ]+$/.test(peripherals)){
		peripherals = peripherals.split("+").map(x => x.trim());
	}
	else if(isString(peripherals)){
		EXPORT_REACT.notification_error(ERR_STR.Unexpected_parameter, "'peripherals' in headerGenerator(): " + peripherals);
		return;
	}
	else {
		peripherals = g_cfg_perFunctions;
	}
	////////////////////////////////////////////

	NUTOOL_PER.g_bFunctionalTesting = true;
	await EXPORT_REACT.prepare_generated_code(peripherals);

	for(let peripheral of peripherals){
		EXPORT_REACT.set_cfg_perFunctions([peripheral]);
		EXPORT_REACT.setSnippetName(peripheral);
		EXPORT_REACT.mask(APP.headerGenerator, "Generating " + peripheral + "'s header files...");
		await pause(1000);
		for(var obj of g_perControlsAutoTest[peripheral]){
			// [Workaround] This case can not use Object.assign()
			g_perControls[peripheral] = JSON.parse(JSON.stringify(g_perControlsAutoTest[peripheral]));
			let { id, dependencies, dependenciesOption, functionalTest } = obj;
			external.headerGenerator_tagId = id;

			// Handle params tagId
			if(isString(tagId) && tagId !== id){
				continue;
			}

			switch(obj.type) {
				case CONF_TYPE.RADIO:
				case CONF_TYPE.SELECT:
				case CONF_TYPE.MULTIPLESELECT:
				case CONF_TYPE.CHECKBOX:
				case CONF_TYPE.CHECKBOXBOOLEAN:
					// Fixed obj.enum is undefined. EX: M031/BPWM0.txt UseBPWM0CH1ENBoolean
					for(let val of (obj.enum || ["true"])){
						// Force UI update
						updateLocalPerControlsV2(id, val, dependencies, dependenciesOption);
						// functionalTest
						if(typeof functionalTest === "object"){
							for (let key in functionalTest) {
								updateLocalPerControlsV2(id, val, key, functionalTest[key]);
							}
						}
						await updateDom(async () => {
							await EXPORT_REACT.forceUpdateV2();
						});
						await external.generateHeaderFile(id, val)
					}
					break;
				case CONF_TYPE.HEXTEXT:
				case CONF_TYPE.INTEGER:
					for(let val of [obj.default, obj.maximum, obj.minimum]){
						if(!val) {
							continue;
						}
						// Force UI update
						updateLocalPerControlsV2(id, val, dependencies, dependenciesOption);
						// functionalTest
						if(typeof functionalTest === "object"){
							for (let key in functionalTest) {
								updateLocalPerControlsV2(id, val, key, functionalTest[key]);
							}
						}
						await updateDom(() => {
							document.getElementById(id).value = val.replace(HEXTEXT_PREFIX, "");
						});
						await external.generateHeaderFile(id, val);
					}
					break;
				default:
					break;
			}
		};
		EXPORT_REACT.unmask();
	}
	EXPORT_REACT.set_cfg_perFunctions(peripherals);
	NUTOOL_PER.g_bFunctionalTesting = false;
	delete external.headerGenerator_tagId;
};

external.basic_test = async function(mode, chipType){
	// const { exec } = window.child_process;
	const m_appPathCString = window.__dirname;
	const modeAry = {
		"-keil": ["-keil", PATH.Keil_exe],
		"-keil+download": ["-keil", PATH.Keil_exe, "-download", PATH.NuLink_exe],
		"-iar": ["-iar", PATH.Iar_exe],
		"-gcc": ["-gcc", PATH.Gcc_exe],
		"-all": ["-keil", PATH.Keil_exe, "-iar", PATH.Iar_exe, "-gcc", PATH.Gcc_exe],
	};

	// Handle params mode
	if(EXPORT_REACT.getPropertyNames(modeAry).includes(mode)){
		// NOOP
	}
	else if(isString(mode)){
		EXPORT_REACT.notification_error(ERR_STR.Unexpected_parameter, "'mode' in headerGenerator(): " + mode);
		return;
	}
	else {
		mode = "-keil+download";
	}

	// Handle params chipType
	if (isLegalChipType(chipType)){
		// NOOP
	}
	else if(isString(chipType)){
		EXPORT_REACT.notification_error(ERR_STR.Unexpected_parameter, "'chipType' in headerGenerator(): " + chipType);
		return;
	}
	else {
		chipType = g_chipType;
	}
	////////////////////////////////////////////

	var directoryString = m_appPathCString + PATH.AutoTest;
	//var fileString = standardArgv(directoryString + APP.basic_test);
	// var parametersString = chipType + ' -keil "C:\\Keil_v5\\UV4\\UV4.exe" -nonstop 1';
	var parametersAry = [chipType, "-nonstop", "1", ...modeAry[mode]];

	NUTOOL_PER.g_bFunctionalTesting = true;
	g_basic_test_mode = mode;
	EXPORT_REACT.mask(APP.basic_test);
	await window.electronAPI.child_process_spawn(
		directoryString + APP.basic_test,
		parametersAry,
		{
			cwd: directoryString,
		}
	);
};

external.kill_basic_test  = async function() {
	const { exec } = window.child_process;
	exec("taskkill /f /im " + APP.basic_test);
};

external.generateHeaderFile = async function(cmpId, cmpVal, callpre, callback){
	const { outputFile } = window.fs;
	const m_appPathCString = window.__dirname;
	var fileName = g_snippetName + "&" + cmpId + "&" + cmpVal + ".h";
	// Fixed cmpVal inculdes "|". EX: M031/BPWM0.txt UseBPWM0CH0CapReloadSelect
	fileName = fileName.replaceAll("|", "-");
	// EX: M251/USCI0_UART UUART0_PDMAConfigSelect UUART_PDMACTL_PDMAEN_Msk | UUART_PDMACTL_RXPDMAEN_Msk | UUART_PDMACTL_TXPDMAEN_Msk
	fileName = fileName.replaceAll(" ", "")

	if(fileName.match(/[?]/g)) {
		EXPORT_REACT.notification_error("Illegal Path", fileName);
		console.error("[Illegal Path]:" + fileName);
		return;
	}
	else {
		if(typeof callpre === "function"){
			await callpre();
		}
		await NUTOOL_PER.concatenate_generated_code();

		var perHText = `${NUTOOL_PER.getg_generatedCodeFromPerString()}\n`.replaceAll("\r", "");
		var perHPath = m_appPathCString + PATH.result + fileName;
		await outputFile(perHPath, perHText).then(() => {
			if(!g_bReadyForRelease) console.log("[outputFile success] %c" + fileName, 'color: green');
			EXPORT_REACT.notification_success("[outputFile success]", fileName, 2);
		});
		if(typeof callback === "function"){
			await callback();
		}
		// await pause(100);
	}
};

external.execAllFunctionalTests = async function(
	chipType,
	partNo,
	peripherals,
	mode,
) {

	new Promise(resolve => { resolve() })
	.then(async () => {
		await external.parsingexcel(chipType, peripherals);
	})
	.then(async () => {
		await external.headerGenerator(partNo, peripherals);
	})
	.then(async () => {
		await pause(2000);
		await external.basic_test(mode, chipType);
	})
};

setTimeout(()=> {
	try{
		window.electronAPI.child_process_spawn_io((event, type, msg) => {
			// EXPORT_REACT._D("child_process_spawn_io type = " + type + "\n" + msg);
			let newTitle = APP.basic_test + " (" + g_basic_test_mode + ", " + g_chipType + ")";
			let _TEST = "Test", _finish = "finish", _current = "current/total:";
			if(type === "data") {
				// [Workaround]
				// Single test finish.
				if(msg.includes(_TEST) && msg.includes(_finish)){
					// -------------------------------------------------------------fail
					if(msg.includes("-------------------------------------------------------------fail")){
						EXPORT_REACT.notification_error(
							newTitle,
							msg.substring(0, msg.indexOf(_finish) + 6)
						);
					}
					// pass
					else{
						EXPORT_REACT.notification_success(
							newTitle,
							msg.substring(msg.indexOf(_TEST), msg.indexOf(_finish) + 6),
							4
						);
					}
				}
				// All tests Finish.
				else if (!msg.includes("Start to test") && msg.includes(_current)){
					EXPORT_REACT.notification_info(newTitle, msg.substring(msg.indexOf(_current)));
				}
				else if( msg === "\f"
					|| msg === "\r\n\r\n<--------------------------------------------------------->\r\n"
					|| (msg.includes("Directory") && msg.includes("*.c,*.h"))
				){
					// NOOP
					return;
				}
				else {
					EXPORT_REACT.unmask();
					EXPORT_REACT.mask(newTitle, msg);
				}
			}
			else if(type === "error") {
				// basic_test -keil+download
				if(msg.includes("INFO:pyocd") || msg.includes("WARNING:pyocd")){
					// NOOP
					return;
					// EXPORT_REACT.notification_warning(APP.basic_test, msg, 1);
				}
				else {
					EXPORT_REACT.notification_error(newTitle, msg);
				}
			}
			else if (type === "close") {
				NUTOOL_PER.g_bFunctionalTesting = false;
				EXPORT_REACT.unmask();
			}
			else if (type === "exit") {
				NUTOOL_PER.g_bFunctionalTesting = false;
				EXPORT_REACT.unmask();
			}
	
			EXPORT_REACT._D("child_process_spawn_io type = " + type + "\n" + msg);
		})
	}
	catch(e){
		console.error(e);
	}
}, 3000);


///////////////          help command           ///////////////
var titleCSS = "color:DarkBlue; font-weight:bold; font-size:18px;";
var exCSS = "color:DarkKhaki;";
var dfCSS = "color:GoldenRod;";
var redColor = "color:red;";

external.help = {
	// external.help.parsingexcel
	parsingexcel: function() {
		console.log('\n\n// Generate test_database.txt by parsing Mapping Table.');
		console.log('%cexternal.parsingexcel(chipType, peripherals)', titleCSS);
		console.log('\tchipType: %c "M251"/"M031"/..., %c default=GUI selected', exCSS, dfCSS);
		console.log('\tperipherals: %c "all"/"CRC"/"CRC FMC"/..., %c default="all"', exCSS, dfCSS);
		console.log('%cNotice: Require "XXX TagReg Mapping Table.xlsx".', redColor);
	},

	// external.help.headerGenerator
	headerGenerator: function() {
		console.log('\n\n// Generate header files.');
		console.log('%cexternal.headerGenerator(partNo, peripherals, tagId)', titleCSS);
		console.log('\tpartNo: %c "M251EC2AE"/"M031EB0AE"/..., %c default=GUI selected', exCSS, dfCSS);
		console.log('\tperipherals: %c "All"/"CRC"/"CRC+FMC"/..., %c default=GUI selected', exCSS, dfCSS);
		console.log('\ttagId: %c "CLK_HXT_FailDetectorRadio"/"WWDT_PrescalerSelect"/..., %c default=null', exCSS, dfCSS);
	},

	// external.help.basic_test
	basic_test: function() {
		console.log('\n\n// Verify whether "~/result/header files" and "test_database.txt" are consistent');
		console.log('%cexternal.basic_test(mode, chipType)', titleCSS);
		console.log('\tmode: %c "-keil"/"-keil+download"/"-iar"/"-gcc"/"-all", %c default="-keil+download"', exCSS, dfCSS);
		console.log('\tchipType: %c "M251"/"M031"/..., %c default=GUI selected', exCSS, dfCSS);
		console.log('%cNotice: Require related application(Keil/Iar/Gcc).', redColor);
		external.help.exe_path();
	},

	exe_path: function() {
		console.log('\n%cCan modify exe paths in content-web-define.js or console, current path as below:', redColor);
		console.log('\tPATH.Keil_exe = %c'+ PATH.Keil_exe, exCSS)
		console.log('\tPATH.Iar_exe = %c'+ PATH.Iar_exe, exCSS)
		console.log('\tPATH.Gcc_exe =  %c'+ PATH.Gcc_exe, exCSS)
		console.log('\tPATH.NuLink_exe = %c'+ PATH.NuLink_exe, exCSS)
	},

	// external.help.execAllFunctionalTests
	execAllFunctionalTests: function() {
		console.log('\n\n// Execute parsingexcel + headerGenerator + basic_test.');
		console.log('%cexternal.execAllFunctionalTests(chipType, partNo, peripherals, mode)', titleCSS);
		console.log('\tchipType: %c "M251"/"M031"/..., %c default=GUI selected', exCSS, dfCSS);
		console.log('\tpartNo: %c "M251EC2AE"/"M031EB0AE"/..., %c default=GUI selected', exCSS, dfCSS);
		console.log('\tperipherals: %c "All"/"CRC"/"CRC+FMC"/..., %c default=GUI selected', exCSS, dfCSS);
		console.log('\tmode: %c "-keil"/"-keil+download"/"-iar"/"-gcc"/"-all", %c default="-keil+download"', exCSS, dfCSS);
	}
};

external.autoTestHelper = function() {
	external.help.parsingexcel();
	external.help.headerGenerator();
	external.help.basic_test();
	external.help.execAllFunctionalTests();
};
////////////////////////////////////////////////////////////
