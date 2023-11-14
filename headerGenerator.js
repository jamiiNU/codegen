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
	if(/^[A-Z0-9]+$/.test(partNo)){
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

const updateLocalPerControlsV2 = function(id, newData, dependencies, dependenciesOption) {
	//let controls = g_perControls[g_snippetName];
	if(dependencies === "none"){
		// NOOP
	}
	else if ( typeof dependencies === "string"){
		if(dependenciesOption[dependencies] !== undefined){
			dependenciesOption = dependenciesOption[dependencies];
		}
		if (typeof dependenciesOption === "object"){
			dependenciesOption = dependenciesOption[0];
		}
		updateLocalPerControlsV2(dependencies, dependenciesOption);
		EXPORT_REACT.forceUpdateV2();
	}
	else if (typeof dependencies === "object") {
		for(let dependency of dependencies){
			let dependencyOption = dependenciesOption[dependency];
			updateLocalPerControlsV2(dependency, dependencyOption);
			EXPORT_REACT.forceUpdateV2();
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
		console.error("[updateDom() error]");
		console.log(e);
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
		EXPORT_REACT.notification_error(ERR_STR.Unexpected_parameter, "In parsingexcel(): " + chipType);
		return;
	}
	else {
		chipType = g_chipType;
	}

	// Handle params peripheralsStr
	if(/^[A-Z0-9_ ]+$/.test(peripherals) || peripherals === "all") {
		// NOOP
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

	EXPORT_REACT.mask("Execute parsingexcel.exe...");
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
		EXPORT_REACT.set_cfg_perFunctions(peripherals);
	}
	else if(/^[A-Z0-9_+]+$/.test(peripherals)){
		peripherals = peripherals.split("+").map(x => x.trim());
		EXPORT_REACT.set_cfg_perFunctions(peripherals);
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
		EXPORT_REACT.setSnippetName(peripheral);
		EXPORT_REACT.mask("Generate " + peripheral + "'s header files...");
		await pause(1000);
		for(var obj of g_perControls[peripheral]){
			let { id, dependencies, dependenciesOption, optionLabels} = obj;

			// Handle params tagId
			if(isString(tagId) && tagId !== id){
				continue;
			}

			switch(obj.type) {
				case CONF_TYPE.RADIO:
					for(let val of obj.enum){
						// Force UI update
						updateLocalPerControlsV2(id, val, dependencies, dependenciesOption);
						await updateDom(() => {
							document.getElementById(id + "-" + val).click();
						});
						await external.generateHeaderFile(id, val)
					}
					break;
				case CONF_TYPE.SELECT:
					for(let idx=0; idx<obj.enum.length; idx++){
						let val = obj.enum[idx];
						let label = optionLabels[idx];

						// Force UI update
						updateLocalPerControlsV2(id, val, dependencies, dependenciesOption);
						await updateDom(() => {
							let cmp = document.getElementById(id).parentElement.parentElement.lastChild;
							cmp.textContent = label;
						});
						await external.generateHeaderFile(id, val);
					}
					break
				case CONF_TYPE.MULTIPLESELECT:
					for(let idx=0; idx<obj.enum.length; idx++){
						let val = obj.enum[idx];

						// Force UI update
						updateLocalPerControlsV2(id, val, dependencies, dependenciesOption);
						await updateDom(async () => {
							// TODO
							await EXPORT_REACT.forceUpdateV2();
						});
						await external.generateHeaderFile(id, val)
					}
					break;
				case CONF_TYPE.CHECKBOX:
				case CONF_TYPE.CHECKBOXBOOLEAN:
					// Fixed obj.enum is undefined. EX: M031/BPWM0.txt UseBPWM0CH1ENBoolean
					for(let val of (obj.enum || ["true"])){
						// Force UI update
						updateLocalPerControlsV2(id, val, dependencies, dependenciesOption);
						await updateDom(async () => {
							for(let cmp of document.getElementById(id).getElementsByTagName("input")){
								if(cmp.value === val) {
									// check target
									if(!cmp.checked){
										if(optionLabels) {
											// Workaround: sometime cmp.click() did not work. 
											document.querySelector("input[name=" + id +"][value=\"" + val + "\"]").click();
										}
										else {
											cmp.click();
										}
									}
								}
								else {
									// uncheck others
									if(cmp.checked){
										cmp.click();
									}
								}
								await pause(100);
							}
						})
						await external.generateHeaderFile(id, val);
					}
					break;
				case CONF_TYPE.HEXTEXT:
				case CONF_TYPE.INTEGER:
					for(let val of [obj.data, obj.maximum, obj.minimum]){
						if(!val) {
							continue;
						}
						// Force UI update
						updateLocalPerControlsV2(id, val, dependencies, dependenciesOption);
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
	NUTOOL_PER.g_bFunctionalTesting = false;
};

external.basic_test = async function(mode, chipType){
	const { exec } = window.child_process;
	const m_appPathCString = window.__dirname;
	const modeAry= [
		"-keil",
		"-keil+download",
		"-iar",
		"-gcc",
		"-all",
	];

	// Handle params mode
	if(modeAry.includes(mode)){
		// NOOP
	}
	else if(isString(mode)){
		EXPORT_REACT.notification_error(ERR_STR.Unexpected_parameter, "'mode' in headerGenerator(): " + mode);
		return;
	}
	else {
		mode = "-keil";
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
	var fileString = standardArgv(directoryString + APP.basic_test);
	var parametersString = chipType + ' -keil "C:\\Keil_v5\\UV4\\UV4.exe" -nonstop 1';

	EXPORT_REACT.mask("Execute basic_test.exe, it might take a long time...");
	exec(fileString + parametersString,
		{
			cwd: directoryString,
			maxBuffer: 1024*1024*10,
			windowsHide: true,
		}, (err, stdout, stderr) => {
		EXPORT_REACT.unmask();
		if (err) {
			console.error(APP.basic_test + "\n" + stderr);
			EXPORT_REACT.notification_error(APP.basic_test, stderr);
		}
		else {
			console.log(APP.basic_test + "\n" + stdout);
			let tag = "<--------------------------------------------------------->";
			EXPORT_REACT.info(APP.basic_test, stdout.sliceAfterX(tag));
		}
	})
};

external.generateHeaderFile = async function(cmpId, cmpVal, callpre, callback){
	const { outputFile } = window.fs;
	const m_appPathCString = window.__dirname;
	var fileName = g_snippetName + "&" + cmpId + "&" + cmpVal + ".h";
	// Fixed cmpVal inculdes "|". EX: M031/BPWM0.txt UseBPWM0CH0CapReloadSelect
	fileName = fileName.replace("|", "-")

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
			console.log("[outputFile success] %c" + fileName, 'color: green');
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
	.then(async (x) => {
		console.log(x)
		await external.headerGenerator(partNo, peripherals);
	})
	.then(async () => {
		await external.basic_test(mode, chipType);
	})
};

external.autoTestHelper = function() {
	let titleCSS = "color:DarkBlue; font-weight:bold; font-size:18px;"
	let exCSS = "color:DarkKhaki;";
	let dfCSS = "color:GoldenRod;";
	let redColor = "color:red;";

	console.log('\n\n// Generate test_database.txt by parsing Mapping Table.');
	console.log('%cexternal.parsingexcel(chipType, peripherals)', titleCSS);
	console.log('\tchipType: %c "M251"/"M031"/..., %c default=GUI selected', exCSS, dfCSS);
	console.log('\tperipherals: %c "all"/"CRC"/"CRC FMC"/..., %c default="all"', exCSS, dfCSS);
	console.log('%cNotice: Require "XXX TagReg Mapping Table.xlsx".', redColor);

	console.log('\n\n// Generate header files.');
	console.log('%cexternal.headerGenerator(partNo, peripherals, tagId)', titleCSS);
	console.log('\tpartNo: %c "M251EC2AE"/"M031EB0AE"/..., %c default=GUI selected', exCSS, dfCSS);
	console.log('\tperipherals: %c "All"/"CRC"/"CRC+FMC"/..., %c default=GUI selected', exCSS, dfCSS);
	console.log('\ttagId: %c "CLK_HXT_FailDetectorRadio"/"WWDT_PrescalerSelect"/..., %c default=null', exCSS, dfCSS);

	console.log('\n\n// Verify whether "~/result/header files" and "test_database.txt" are consistent');
	console.log('%cexternal.basic_test(mode, chipType)', titleCSS);
	// console.log('\tmode: %c "-keil"/"-keil+download"/"-iar"/"-gcc"/"-all", %c default="-keil"', exCSS, dfCSS);
	console.log('\tmode: %c "-keil", %c default="-keil"', exCSS, dfCSS);
	console.log('\tchipType: %c "M251"/"M031"/..., %c default=GUI selected', exCSS, dfCSS);
	console.log('%cNotice: Require related application(Keil/Iar/Gcc).', redColor);

	console.log('\n\n// Execute parsingexcel + headerGenerator + basic_test.');
	console.log('%cexternal.execAllFunctionalTests(chipType, partNo, peripherals, mode)', titleCSS);
	console.log('\tchipType: %c "M251"/"M031"/..., %c default=GUI selected', exCSS, dfCSS);
	console.log('\tpartNo: %c "M251EC2AE"/"M031EB0AE"/..., %c default=GUI selected', exCSS, dfCSS);
	console.log('\tperipherals: %c "All"/"CRC"/"CRC+FMC"/..., %c default=GUI selected', exCSS, dfCSS);
	//  console.log('\tmode: %c "-keil"/"-keil+download"/"-iar"/"-gcc"/"-all", %c default="-keil"', exCSS, dfCSS);
	console.log('\tmode: %c "-keil", %c default="-keil"', exCSS, dfCSS);
};