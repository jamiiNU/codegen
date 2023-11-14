/* eslint-disable no-restricted-globals */
const getToolVersion = () => {
	var g_toolVersion = NUTOOL_PER.getg_toolVersion();
	var sToolVersion = "V1.00";
    if (g_toolVersion.includes('V'))
	{
		sToolVersion = g_toolVersion.substr(0, g_toolVersion.lastIndexOf("."));
	}
	return sToolVersion;
}

const standardArgv = (argv) => {
	return '"' + argv + '" ';
}


// BOOL CNuCodeGeneratorToolDlg::generateCodeFromJS(LPCTSTR userProject1, LPCTSTR userInput1, LPCTSTR userCheckbox1, LPCTSTR userHeader1)
external.generateCodeFromJS = function(userProject1, userInput1, userCheckbox1, userHeader1){
	const { exec } = window.child_process;
	const { copy, emptydir, ensureDir, move, outputFile, remove } = window.fs;
	// const { windows, moveRemove } =  window.rimraf;
    const m_appPathCString = window.__dirname;
    var userProject = userProject1;
	var userInput = userInput1;
	var userCheckbox = userCheckbox1;
	// var userHeader = userHeader1;
	// std::string g_chipType;
	// std::string g_partNumber_package;
	// std::string g_cfg_projectLoaction;
	// std::string g_cfg_thidrPartyLibLoaction;
	// std::string g_generatedCodeFromPerString;
	// std::string g_enabledThirdPartyLibString;
	// std::string g_toolVersion;
	var bModularizeCode = false;
	// EX: ~\BSP\...\SampleCode\NuCodeGen
	var agendaPath;

	g_chipType =  NUTOOL_PER.getg_chipType();
	g_cfg_projectLoaction = NUTOOL_PER.getg_cfg_projectLoaction();
	g_cfg_thidrPartyLibLoaction = NUTOOL_PER.getg_cfg_thidrPartyLibLoaction();
	// g_generatedCodeFromPerString = NUTOOL_PER.getg_generatedCodeFromPerString();
	g_enabledThirdPartyLibString = NUTOOL_PER.getg_enabledThirdPartyLibString();
	// g_toolVersion = NUTOOL_PER.getg_toolVersion();

	if (userCheckbox.includes("CheckModularizeCode:true")) {
		bModularizeCode = true;
	}
    else {
    }

    // var sToolVersion = "V1.00";
    // if (g_toolVersion.includes('V'))
	// {
	// 	sToolVersion = g_toolVersion.substr(0, g_toolVersion.lastIndexOf("."));
	// }

    // Where to copy
    // EX: ~\public\PeripheralConfigure\M251\NuCodeGenProj
	var convertedCString = m_appPathCString + "\\PeripheralConfigure\\" + g_chipType + g_cfg_projectLoaction;
	// Where to generate
	// EX: ~\BSP\...\SampleCode
	var convertedCString1;

	// EX: ~\public\PeripheralConfigure\M251\NuCodeGen
	var convertedCString2 = m_appPathCString + "\\PeripheralConfigure\\" + g_chipType + "\\NuCodeGen";;

	if(userInput1 === "generateCodeDialogInput:none"){
		return true;
	}
	else {
		// EX: ~\BSP\...\SampleCode
		convertedCString1 = userInput;
	}

	new Promise(resolve => { resolve() })
		.then(() => {
			// $("#generateCodeDialog_buttonOk").button("disable");
			console.log("[Generate code] Start...");
			EXPORT_REACT.mask();
		})
		.then(x => {
			return new Promise(resolve => {
				// do Create
				// EX: ~\BSP\...\SampleCode\NuCodeGen
				agendaPath = convertedCString1 + "\\NuCodeGen";
				ensureDir(agendaPath).then(() => {
					resolve("[ensureDir success]" + agendaPath);
				});
			});
		})
		.then(x => {
			console.log(x);
			return new Promise(resolve => {
				// do project check
				if (userCheckbox.includes("renameCheckbox:true")){
					// EX: ~\BSP\...\SampleCode\NuCodeGen\MyProject
					agendaPath = agendaPath + '\\' + userProject;
				}
				else {
					// EX: ~\BSP\...\SampleCode\NuCodeGen\NuCodeGenProj
					agendaPath = agendaPath + '\\' + g_cfg_projectLoaction;
				}
				// do Delete
				emptydir(agendaPath).then(() => {
					resolve("[emptydir success]" + agendaPath);
				});
			});
		})
		.then(x => {
			console.log(x);
			return new Promise(resolve => {
				// do Duplicate
				// EX: ~\public\PeripheralConfigure\M251\NuCodeGen
				convertedCString2 = m_appPathCString + "\\PeripheralConfigure\\" + g_chipType + "\\NuCodeGen";
				emptydir(convertedCString2).then(() => {
					resolve("[emptydir success]" + convertedCString2);
				});
			})
		})
		.then(x => {
			console.log(x);
			return new Promise(resolve => {
				// EX: ~\public\PeripheralConfigure\M251\NuCodeGen\NuCodeGenProj
				agendaPath = convertedCString2 + "\\" + g_cfg_projectLoaction;
				ensureDir(agendaPath).then(() => {
					resolve("[ensureDir success]" + agendaPath);
				});
			})
		})
		.then(x => {
			console.log(x);
			return new Promise(resolve => {
				// From ~\public\PeripheralConfigure\M251\NuCodeGenProj
				// To   ~\public\PeripheralConfigure\M251\NuCodeGen\NuCodeGenProj
				copy(convertedCString, agendaPath).then(() => {
					resolve("[copy success]\n\t" + convertedCString + "\n => " + agendaPath);
				});
			});
		})
		.then(x => {
			console.log(x);
			return new Promise(resolve => {
				NUTOOL_PER.concatenate_generated_code(resolve);
			});
		})
		.then(x => {
			console.log(x);
			return new Promise(resolve => {
				//////////////////////////////////////////// PeripheralConfigure //////////////////////////////////////////
				// write the new perFunctionString to js file
				var perHText = external.generatePer_h();
				var perHPath = convertedCString2 + "\\" + g_cfg_projectLoaction + "\\periph_conf.h"; 
				outputFile(perHPath, perHText).then(() => {
					resolve("[outputFile periph_conf.h success]");
				});
			});
		})
		.then(x => {
			console.log(x);
			//////////////////////////////////////////// PinConfigure /////////////////////////////////////////////////
			var pinCText = external.generatePin_c(bModularizeCode);
			var pinCPath = convertedCString2 + "\\" + g_cfg_projectLoaction + "\\pin_conf.c"; 
			outputFile(pinCPath, pinCText, function(err){
				if (err) return console.error(err);
				console.log("[outputFile pin_conf.c success]");
			});

			if(bModularizeCode) {
				var pinHText = external.generatePin_h();
				var pinHPath = convertedCString2 + "\\" + g_cfg_projectLoaction + "\\pin_conf.h"; 
				outputFile(pinHPath, pinHText, function(err){
					if (err) return console.error(err);
					console.log("[outputFile pin_conf.h success]");
				});
			}
		})
		.then(() => {
			//////////////////////////////////////////// ClockConfigure ///////////////////////////////////////////////
			var clkCText = external.generateClk_c(bModularizeCode);
			var clkCPath = convertedCString2 + "\\" + g_cfg_projectLoaction + "\\clk_conf.c"; 
			outputFile(clkCPath, clkCText, function(err){
				if (err) return console.error(err);
				console.log("[outputFile clk_conf.c success]");
			});

			if(bModularizeCode) {
				var clkHText = external.generateClk_h();
				var clkHPath = convertedCString2 + "\\" + g_cfg_projectLoaction + "\\clk_conf.h"; 
				outputFile(clkHPath, clkHText, function(err){
					if (err) return console.error(err);
					console.log("[outputFile clk_conf.h success]");
				});
			}
		})
		.then(() => {
			// [Workaround] Timeout 1 sec."
			return new Promise(resolve => {
				setTimeout(() => {
					resolve("[Workaround] Delayed for 2 sec.");
				}, 2000);
			});
		})
		.then(x => {
			console.log(x);
			//////////////////////////////////////////// post-processing //////////////////////////////////////////////
			console.log("[Post-processing] Start");

			var fileString;
			var parametersString;
			return new Promise(resolve => { // [Workaround] Debug mode will failed.
				if (userCheckbox.includes("projfileCheckbox:true")) {
					// run projfile
					fileString = standardArgv(m_appPathCString + "\\projfile.exe");
					parametersString =
						standardArgv(convertedCString2 + "\\" + g_cfg_projectLoaction)
						+ NUTOOL_CLOCK.getg_clockRegsString1();
					exec(fileString + parametersString, (err, stdout, stderr) => {
						if (err) {
							console.error("[projfile.exe] " + err);
							//return;
						}
						resolve("[projfile.exe] Finish. " + stdout);
					});
				}
				else {
					resolve("[projfile.exe] Skip.");
				}
			});
		})
		.then(x => {
			console.log(x);
			return new Promise(resolve => {
				if (userCheckbox.includes("cppcmdCheckbox:true")) {
					// run cppcmd
					fileString =  standardArgv(convertedCString2 + "\\" + g_cfg_projectLoaction + "\\cppcmd.bat");
					parametersString = standardArgv(m_appPathCString);
					directoryString = convertedCString2 + "\\" + g_cfg_projectLoaction;
					exec(fileString + parametersString, { cwd: directoryString }, (err, stdout, stderr) => {
						if (err) {
							console.error("[cppcmd.bat] " + err);
							//return;
						}
						resolve("[cppcmd.bat] Finish. " + stdout);
						
					})
				}
				else {
					resolve("[cppcmd.bat] Skip.");
				}
			});
		})
		.then(x => {
			console.log(x);
			return new Promise(resolve => {
				remove(convertedCString2 + "\\" + g_cfg_projectLoaction + "\\IP", function(err){
					if (err) {
						console.error("[remove \\IP] " + err);
					}
					resolve( "[remove \\IP] Finish.")
				});
			})
		})
		.then(x => {
			console.log(x);
			return new Promise(resolve => {
				if (userCheckbox.includes("astyleCheckbox:true")) {
					// run astyle
					fileString = standardArgv(m_appPathCString + "\\AStyle.exe");
					parametersString =
						"--options="
						+ standardArgv(m_appPathCString + "\\AStyle_BSP.txt")
						+ "--ascii --recursive "
						+ standardArgv(convertedCString2 + "\\" + g_cfg_projectLoaction + "\\*.c,*.h");

					exec(fileString + parametersString,(err, stdout, stderr) => {
						if (err) {
							console.error("[AStyle.exe] " + err);
							//return;
						}
						resolve("[AStyle.exe] Finish. " + stdout);
					})
				}
				else {
					resolve("[AStyle.exe] Skip.");
				}
			});
		})
		.then(x => {
			console.log(x);
			return new Promise(resolve => {
				if (userCheckbox.includes("renameCheckbox:true")) {
					// run rename
					fileString = standardArgv(m_appPathCString + "\\rename.exe");
					parametersString =
						standardArgv(convertedCString1 + "\\NuCodeGen")
						+ standardArgv(convertedCString2)
						+ standardArgv(g_cfg_projectLoaction.substr(1))
						+ standardArgv(userProject)
						+ standardArgv(NUTOOL_PER.getg_partNumber_package().slicePriorToX("("))
						+ standardArgv("-1");
					exec(fileString + parametersString, (err, stdout, stderr) => {
						if (err) {
							console.error("[rename.exe] " + err);
						}
						resolve("[rename.exe] Finish. " + stdout);
					})
				}
				else {
					userProject = g_cfg_projectLoaction;
					resolve("[rename.exe] Skip.");
				}
			});
		})
		.then(x => {
			console.log(x);
			console.log("[Post-processing] End");
			return new Promise(resolve => {
				///////////////////////////////////// move the project to the specified path //////////////////////////////
				convertedCString = m_appPathCString + "\\PeripheralConfigure\\" + g_chipType + "\\NuCodeGen\\" + userProject;
				agendaPath = convertedCString1 + "\\NuCodeGen\\" + userProject;
				//emptydir(agendaPath).then(() => {
				move(convertedCString, agendaPath, { overwrite: true }).then(() => {
					resolve("[copy success]\n\t" + convertedCString + "\n => " + agendaPath);
				});
				//});
			});
		})
		.then(x => {
			console.log(x);
			return new Promise(resolve => {
				//////////////////////////////////////////// save a config file ///////////////////////////////////////////
				var ncfgText = external.generatePackage_ncfg();
				var ncfgPath = userInput + "\\NuCodeGen\\" + userProject + "\\" + userProject + ".ncfg";
				outputFile(ncfgPath, ncfgText).then(() => {
					resolve("[outputFile .ncfg success]");
				});
			})
		})
		.then(x => {
			console.log(x);
			document.getElementsByClassName("ui-icon-closethick")[0].click();
			EXPORT_REACT.notification_success("[Generate code]", "Done.");
		})
		.catch( err => {
			console.error(err)
			EXPORT_REACT.notification_error("[Generate code]", err);
		})
		.finally(() => {
			EXPORT_REACT.unmask();
		});
};

// Need to call concatenate_generated_cfg (~/src/content-web-commonLib.js) first !!
external.generatePackage_ncfg = function(){
	var g_partNumber_packageString = NUTOOL_PER.getg_partNumber_package();
	var text;
	NUTOOL_PER.concatenate_generated_cfg();
	NUTOOL_PIN.get_gpio_MFPsNames();
	NUTOOL_CLOCK.concatenate_g_clockRegsString();
	text = `/****************************************************************************\n`
		+ ` * @file     ${g_partNumber_packageString}.ncfg\n`
		// + ` * @version  ${NUTOOL_PER.getg_toolVersion()}\n`
		+ ` * @version  ${getToolVersion()}\n`
		+ ` * @Date     ${new Date()}\n`
		+ ` * @brief    ${NUTOOL_PIN.getg_briefName()} Config File\n`
		+ ` *\n`
		+ ` * @note Please do not modify this file.\n`
		+ ` *       Otherwise, it may not be loaded successfully.\n`
		+ ` *\n`
		+ ` * SPDX-License-Identifier: Apache-2.0\n`
		+ ` *\n`
		+ ` * Copyright (C) 2016-${(new Date()).getFullYear()}${NUTOOL_PIN.getg_copyrightCompanyName()} All rights reserved.\n`
		+ `*****************************************************************************/\n`
		+ `MCU:${g_partNumber_packageString}\n`
		// TODO
		+ `ThirdPartyLibs:${NUTOOL_PER.getg_enabledThirdPartyLibString()}\n`
		+ `PeripheralFunctions:${NUTOOL_PER.getg_enabledPeripheralFunctionString()}\n`
		+ `PeripheralFunctionData:${NUTOOL_PER.getg_generatedCodeFromPerString()}\n`
		+ `${NUTOOL_PIN.getg_pinCurrentStateString()}`
		+ `${NUTOOL_PIN.getg_pinsConfiguredByGPIOstring()}` // TODO: no show
		+ `${NUTOOL_PIN.getg_userDefinedPinString()}`
		+ `${NUTOOL_PIN.getg_gpio_MFPsString()}`
		+ `${NUTOOL_CLOCK.getg_clockRegsString()}`
		+ `/*** (C) COPYRIGHT 2016-${(new Date()).getFullYear()}${NUTOOL_PIN.getg_copyrightCompanyName()} ***/\n`;

	return text.replace(/\n/g, "\r\n") // Unix(LF) -> Windows(CRLF)
};

external.generatePer_h = function(){
	var g_partNumber_packageString;
	var g_generatedCodeFromPerString;
	var text;

	// AccessJSVarOrPerformMethod("NUTOOL_PER", "g_perFunctionString", DISPATCH_PROPERTYPUT, strToken);
	// NUTOOL_PER.concatenate_generated_code()	
	g_partNumber_packageString = NUTOOL_CLOCK.getg_partNumber_package();
	g_generatedCodeFromPerString =  NUTOOL_PER.getg_generatedCodeFromPerString();

	text = `/****************************************************************************\n`
		+ ` * @file     periph_conf.h\n`
		// + ` * @version  ${NUTOOL_PER.getg_toolVersion()}\n`
		+ ` * @version  ${getToolVersion()}\n`
		+ ` * @Date     ${new Date()}\n`
		+ ` * @brief    NuMicro generated code file\n`
		+ ` *\n`
		+ ` * SPDX-License-Identifier: Apache-2.0\n`
		+ ` *\n`
		+ ` * Copyright (C) 2016-${(new Date()).getFullYear()}${NUTOOL_PIN.getg_copyrightCompanyName()} All rights reserved.\n`
		+ `*****************************************************************************/\n\n`
		+ `/********************\n`
		+ `MCU:${g_partNumber_packageString}\n`
		+ `********************/\n\n`
		+ `${g_generatedCodeFromPerString}\n`
		+ `/*** (C) COPYRIGHT 2016-${(new Date()).getFullYear()}${NUTOOL_PIN.getg_copyrightCompanyName()} ***/\n`;

	return text.replace(/\n/g, "\r\n") // Unix(LF) -> Windows(CRLF)
};

external.generatePin_c = function(bModularizeCode){
	var g_gpio_MFPsString;
	var g_partNumber_packageString;
	var g_includeHeadFileString;
	var g_userDefinedPinString;
	var g_generatedCodeByPinString;
	var g_generatedCodeByModuleString;
	var g_generatedCodeByGPIOstring;

	NUTOOL_PIN.getGeneratedCodeByPin(); 
	NUTOOL_PIN.getGeneratedCodeByModule();
	NUTOOL_PIN.getGeneratedCodeByGPIO();

	g_generatedCodeByPinString = NUTOOL_PIN.getg_generatedCodeByPinString();
	g_generatedCodeByModuleString = NUTOOL_PIN.getg_generatedCodeByModuleString();
	g_generatedCodeByGPIOstring = NUTOOL_PIN.getg_generatedCodeByGPIOstring();
	g_partNumber_packageString = NUTOOL_PIN.getg_partNumber_package();

	var text;
	if(!bModularizeCode){
		// getDataUsedToCreateText has to be invoked then the related data will be generated.
		NUTOOL_PIN.getDataUsedToCreateText();
		g_gpio_MFPsString = NUTOOL_PIN.getg_gpio_MFPsString();
		g_includeHeadFileString = NUTOOL_PIN.getg_includeHeadFileString();
		g_userDefinedPinString = NUTOOL_PIN.getg_userDefinedPinString();
		text = `/****************************************************************************\n`
			+ ` * @file     pin_conf.c\n`
			// + ` * @version  ${NUTOOL_PER.getg_toolVersion()}\n`
			+ ` * @version  ${getToolVersion()}\n`
			+ ` * @Date     ${new Date()}\n`
			+ ` * @brief    NuMicro generated code file\n`
			+ ` *\n`
			+ ` * SPDX-License-Identifier: Apache-2.0\n`
			+ ` *\n`
			+ ` * Copyright (C) 2016-${(new Date()).getFullYear()}${NUTOOL_PIN.getg_copyrightCompanyName()} All rights reserved.\n`
			+ `*****************************************************************************/\n\n`
			+ `/********************\n`
			+ `MCU:${g_partNumber_packageString}\n`;
	
		if (!!g_generatedCodeByPinString)
		{
			text += `Pin Configuration:\n${g_generatedCodeByPinString}`;
		}
		if (!!g_generatedCodeByModuleString)
		{
			text += `Module Configuration:\n${g_generatedCodeByModuleString}`;
		}
		if (!!g_generatedCodeByGPIOstring)
		{
			text += `GPIO Configuration:\n${g_generatedCodeByGPIOstring}`;
		}
		text += `********************/\n\n`;
		text += `${g_includeHeadFileString}`;
		if (!!g_userDefinedPinString)
		{
			text += `\n${g_userDefinedPinString}`;
		}
		text = text
			+ `\n/*\n`
			+ ` * @brief This function provides the configured MFP registers\n`
			+ ` * @param None\n`
			+ ` * @return None\n`
			+ ` */\n`
			+ `void Pin_Init(void)\n{\n`
			+ `${g_gpio_MFPsString}`
			+ `\n    return;\n}\n\n`
			+ `/*** (C) COPYRIGHT 2016-${(new Date()).getFullYear()}${NUTOOL_PIN.getg_copyrightCompanyName()} ***/\n`;
	}
	else {
		// getModularizedDataUsedToCreateText has to be invoked then the related data will be generated.
		NUTOOL_PIN.getModularizedDataUsedToCreateText();
		g_includeHeadFileString = NUTOOL_PIN.getg_includeHeadFileString();
		g_userDefinedPinString = NUTOOL_PIN.getg_userDefinedPinString();
		g_gpio_MFPsString = NUTOOL_PIN.getg_gpio_MFPsString();

		// save .c file
		text = `/****************************************************************************\n`
			+ ` * @file     pin_conf.c\n`
			// + ` * @version  ${NUTOOL_PER.getg_toolVersion()}\n`
			+ ` * @version  ${getToolVersion()}\n`
			+ ` * @Date     ${new Date()}\n`
			+ ` * @brief    NuMicro generated code file\n`
			+ ` *\n`
			+ ` * SPDX-License-Identifier: Apache-2.0\n`
			+ ` *\n`
			+ ` * Copyright (C) 2016-${(new Date()).getFullYear()}${NUTOOL_PIN.getg_copyrightCompanyName()} All rights reserved.\n`
			+ `*****************************************************************************/\n\n`
			+ `/********************\n`
			+ `MCU:${g_partNumber_packageString}\n`;
	
		if (!!g_generatedCodeByPinString)
		{
			text += `Pin Configuration:\n${g_generatedCodeByPinString}`;
		}
		if (!!g_generatedCodeByModuleString)
		{
			text += `Module Configuration:\n${g_generatedCodeByModuleString}`;
		}
		if (!!g_generatedCodeByGPIOstring)
		{
			text += `GPIO Configuration:\n${g_generatedCodeByGPIOstring}`;
		}
		text += `********************/\n\n`;
		text += `${g_includeHeadFileString}`;
		text += `#include \"pin_conf.h\"\n\n`;
		if (!!g_userDefinedPinString)
		{
			text += `${g_userDefinedPinString}\n`;
		}
		text += `${g_gpio_MFPsString}\n\n`;
		text += `/*** (C) COPYRIGHT 2016-${(new Date()).getFullYear()}${NUTOOL_PIN.getg_copyrightCompanyName()} ***/\n`;
	}

	return text.replace(/\n/g, "\r\n") // Unix(LF) -> Windows(CRLF)
};

external.generatePin_h = function(){
	var g_gpio_MFPsString = NUTOOL_PIN.getg_gpio_MFPsString1();
	var text = `/****************************************************************************\n`
	+ ` * @file     pin_conf.h\n`
	// + ` * @version  ${NUTOOL_PER.getg_toolVersion()}\n`
	+ ` * @version  ${getToolVersion()}\n`
	+ ` * @Date     ${new Date()}\n`
	+ ` * @brief    NuMicro generated code file\n`
	+ ` *\n`
	+ ` * SPDX-License-Identifier: Apache-2.0\n`
	+ ` *\n`
	+ ` * Copyright (C) 2016-${(new Date()).getFullYear()}${NUTOOL_PIN.getg_copyrightCompanyName()} All rights reserved.\n`
	+ `*****************************************************************************/\n\n`
	+ `#ifndef __PIN_CONF_H__\n`
	+ `#define __PIN_CONF_H__\n\n`
	+ `#ifdef __cplusplus\nextern \"C\"\n{\n#endif\n`
	+ `${g_gpio_MFPsString}`
	+ `#ifdef __cplusplus\n}\n#endif\n`
	+ `#endif /*__PIN_CONF_H__*/\n\n`
	+ `/*** (C) COPYRIGHT 2016-${(new Date()).getFullYear()}${NUTOOL_PIN.getg_copyrightCompanyName()} ***/\n`;

	return text.replace(/\n/g, "\r\n") // Unix(LF) -> Windows(CRLF)
};

external.generateClk_c = function(bModularizeCode){
	var g_partNumber_packageString;
	var g_clockRegsString;
	var text;
	if(!bModularizeCode){
		NUTOOL_CLOCK.concatenate_generated_code();
	}
	else {
		NUTOOL_CLOCK.concatenate_generated_modularizedCode();
	}
	g_partNumber_packageString = NUTOOL_CLOCK.getg_partNumber_package();
	g_clockRegsString = NUTOOL_CLOCK.getg_clockRegsString();
	// g_clockRegsString1 = NUTOOL_CLOCK.getg_clockRegsString1();
	text = `/****************************************************************************\n`
		+ ` * @file     clk_conf.c\n`
		// + ` * @version  ${NUTOOL_PER.getg_toolVersion()}\n`
		+ ` * @version  ${getToolVersion()}\n`
		+ ` * @Date     ${new Date()}\n`
		+ ` * @brief    NuMicro generated code file\n`
		+ ` *\n`
		+ ` * SPDX-License-Identifier: Apache-2.0\n`
		+ ` *\n`
		+ ` * Copyright (C) 2016-${(new Date()).getFullYear()}${NUTOOL_PIN.getg_copyrightCompanyName()} All rights reserved.\n`
		+ `*****************************************************************************/\n\n`
		+ `/********************\n`
		+ `MCU:${g_partNumber_packageString}\n`
		+ `${g_clockRegsString}`
		+ `/*** (C) COPYRIGHT 2016-${(new Date()).getFullYear()}${NUTOOL_PIN.getg_copyrightCompanyName()} ***/\n`;

	return text.replace(/\n/g, "\r\n") // Unix(LF) -> Windows(CRLF)
};

external.generateClk_h = function(){
	var g_clockRegsString2 = NUTOOL_CLOCK.getg_clockRegsString2();
	var text = `/****************************************************************************\n`
	+ ` * @file     clk_conf.h\n`
	// + ` * @version  ${NUTOOL_PER.getg_toolVersion()}\n`
	+ ` * @version  ${getToolVersion()}\n`
	+ ` * @Date     ${new Date()}\n`
	+ ` * @brief    NuMicro generated code file\n`
	+ ` *\n`
	+ ` * SPDX-License-Identifier: Apache-2.0\n`
	+ ` *\n`
	+ ` * Copyright (C) 2016-${(new Date()).getFullYear()}${NUTOOL_PIN.getg_copyrightCompanyName()} All rights reserved.\n`
	+ `*****************************************************************************/\n\n`
	+ `#ifndef __CLK_CONF_H__\n`
	+ `#define __CLK_CONF_H__\n\n`
	+ `#ifdef __cplusplus\nextern \"C\"\n{\n#endif\n`
	+ `${g_clockRegsString2}`
	+ `#ifdef __cplusplus\n}\n#endif\n`
	+ `#endif /*__CLK_CONF_H__*/\n\n`
	+ `/*** (C) COPYRIGHT 2016-${(new Date()).getFullYear()}${NUTOOL_PIN.getg_copyrightCompanyName()} ***/\n`;

	return text.replace(/\n/g, "\r\n") // Unix(LF) -> Windows(CRLF)
};