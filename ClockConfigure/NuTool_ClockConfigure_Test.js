var NUTOOL_CLOCK = {};

module("Clock Configure Tool", {
	setup: function () {
		S.open("//index.htm", function onOpenSuccess() {
			S.win.resizeTo(screen.availWidth, screen.availHeight);//(0, 0)
			S.win.moveTo(0, 0);
		});
	},
	teardown: function () {
		//S.win.print();
	}
});

function verifyNodeFrequency(currentNode) {
	var showMessage;

	// try to check the frequency of a node
	showMessage = S.eval('NUTOOL_CLOCK.checkD3NodeFrequency(' + currentNode + ');');
	if (showMessage.indexOf('Failed:') === -1) {
		ok(true, showMessage);
	}
	else {
		ok(false, showMessage);
	}
}

function verifySelectorValue(currentNode, selectField, selectFieldArrayElement) {
	var k,
		maxK,
		selectFieldValue,
		bVerifiedResult = true,
		selectFieldNameExtended,
		selectFieldNameExtendedShiftBit,
		tempString,
		showMessage;

	// try to check the value of a selector
	bVerifiedResult = false;
	if (currentNode !== 'SYSTICK') {
		if (!NUTOOL_CLOCK.g_CLKSEL_EXTENDED.hasOwnProperty(selectField)) {
			selectFieldValue = S.eval('NUTOOL_CLOCK.readValueFromClockRegs("' + selectField + '")');
			//newSelectorOrDividerValue = parseInt(fullFieldName.sliceAfterX(':'), 10);
			//writeNewValueToClockRegs(selectField, newSelectorOrDividerValue);
		}
		else {
			selectFieldNameExtended = NUTOOL_CLOCK.g_CLKSEL_EXTENDED[selectField][0];
			selectFieldNameExtendedShiftBit = parseInt(selectFieldNameExtended.sliceAfterX(':'), 10);
			selectFieldNameExtended = selectFieldNameExtended.slicePriorToX(':');
			selectFieldValue = S.eval('NUTOOL_CLOCK.readValueFromClockRegs("' + selectField + '")') +
				(S.eval('NUTOOL_CLOCK.readValueFromClockRegs("' + selectFieldNameExtended + '")') << selectFieldNameExtendedShiftBit) >>> 0;
		}

		for (k = 0, maxK = NUTOOL_CLOCK.g_CLKSEL[selectField].length; k < maxK; k += 1) {
			tempString = NUTOOL_CLOCK.g_CLKSEL[selectField][k];
			if (tempString.sliceAfterX(':') === selectFieldValue.toString() && tempString.indexOf(selectFieldArrayElement) === 0) {
				bVerifiedResult = true;
				showMessage = currentNode + ': its clock source is changed to ' + selectFieldArrayElement + '. The value of ' + selectField + ' field is ' + selectFieldValue + '.';
				break;
			}
		}

		if (!bVerifiedResult) {
			showMessage = 'Failed: ' + currentNode + ': its clock source is changed to ' + selectFieldArrayElement + '. But the value of ' + selectField + ' field (' + selectFieldValue + ') is incorrect.';
		}
	}
	else {
		if (selectFieldArrayElement.indexOf('HCLK') === 0 && (selectFieldValue = S.eval('NUTOOL_CLOCK.readValueFromClockRegs("CLKSRC")')) === 0) {
			bVerifiedResult = true;
			showMessage = currentNode + ': its clock source is changed to ' + selectFieldArrayElement + '. The value of CLKSRC field is 0.';
		}
		else if (selectFieldArrayElement !== 'CPUCLK' && S.eval('NUTOOL_CLOCK.readValueFromClockRegs("CLKSRC")') === 0) {
			selectFieldValue = S.eval('NUTOOL_CLOCK.readValueFromClockRegs("' + selectField + '")');
			if (selectFieldValue !== -1) {
				for (k = 0, maxK = NUTOOL_CLOCK.g_CLKSEL[selectField].length; k < maxK; k += 1) {
					tempString = NUTOOL_CLOCK.g_CLKSEL[selectField][k];
					if (tempString.sliceAfterX(':') === selectFieldValue.toString() && tempString.indexOf(selectFieldArrayElement) === 0) {
						bVerifiedResult = true;
						showMessage = currentNode + ': its clock source is changed to ' + selectFieldArrayElement + '. The value of ' + selectField + ' field is ' + selectFieldValue + '. The value of CLKSRC field is 0.';
						break;
					}
				}
			}
			else {
				bVerifiedResult = true;
				showMessage = currentNode + ': its clock source is changed to ' + selectFieldArrayElement + '. The value of CLKSRC field is 0.';
			}
		}
		else if (selectFieldArrayElement === 'CPUCLK' && (selectFieldValue = S.eval('NUTOOL_CLOCK.readValueFromClockRegs("CLKSRC")')) === 1) {
			bVerifiedResult = true;
			showMessage = currentNode + ': its clock source is changed to ' + selectFieldArrayElement + '. The value of CLKSRC field is 1.';

		}
		else {
			showMessage = 'Failed: ' + currentNode + ': its clock source is changed to ' + selectFieldArrayElement + '. The value of ' + S.eval('NUTOOL_CLOCK.readValueFromClockRegs("' + selectField + '")') + ' field is ' + selectFieldValue + '. The value of CLKSRC field is .' + S.eval('NUTOOL_CLOCK.readValueFromClockRegs("CLKSRC")');
		}
	}

	if (bVerifiedResult) {
		ok(true, showMessage);
	}
	else {
		ok(false, showMessage);
	}

	verifyNodeFrequency(currentNode);
}

function verifyDividerValue(currentNode, dividerField, newValue) {
	if (newValue === S.eval('NUTOOL_CLOCK.readValueFromClockRegs("' + dividerField + '")')) {
		ok(true, currentNode + ': input the ' + dividerField + ' field with the new value (' + newValue + ').');
	}
	else {
		ok(false, 'Failed: ' + currentNode + ': input the ' + dividerField + ' field with the new value (' + newValue + '). But the value still is ' + S.eval('NUTOOL_CLOCK.readValueFromClockRegs("' + dividerField + '")'));
	}

	verifyNodeFrequency(currentNode);
}

function loadjscssFile(filename, filetype) {
	var fileref;

	if (filetype == "js") { //if filename is a external JavaScript file
		fileref = document.createElement('script');
		fileref.setAttribute("type", "text/javascript");
		fileref.setAttribute("src", filename);
	}
	else if (filetype == "css") { //if filename is an external CSS file
		fileref = document.createElement("link");
		fileref.setAttribute("rel", "stylesheet");
		fileref.setAttribute("type", "text/css");
		fileref.setAttribute("href", filename);
	}
	if (typeof fileref != "undefined") {
		document.getElementsByTagName("head")[0].appendChild(fileref);
	}
}

function createjscssfile(filename, filetype) {
	var fileref;
	if (filetype === "js") { //if filename is a external JavaScript file
		fileref = document.createElement('script');
		fileref.setAttribute("type", "text/javascript");
		fileref.setAttribute("src", filename);
	}
	else if (filetype === "css") { //if filename is an external CSS file
		fileref = document.createElement("link");
		fileref.setAttribute("rel", "stylesheet");
		fileref.setAttribute("type", "text/css");
		fileref.setAttribute("href", filename);
	}
	return fileref;
}

function replacejscssfile(oldfilename, newfilename, filetype) {
	var i,
		targetelement,
		targetattr,
		allsuspects,
		newelement;

	targetelement = (filetype === "js") ? "script" : (filetype === "css") ? "link" : "none"; //determine element type to create nodelist using
	targetattr = (filetype === "js") ? "src" : (filetype === "css") ? "href" : "none"; //determine corresponding attribute to test for
	allsuspects = document.getElementsByTagName(targetelement);
	for (i = allsuspects.length; i >= 0; i -= 1) { //search backwards within nodelist for matching elements to remove
		if (allsuspects[i] && allsuspects[i].getAttribute(targetattr) !== null && allsuspects[i].getAttribute(targetattr).indexOf(oldfilename) !== -1) {
			newelement = createjscssfile(newfilename, filetype);
			allsuspects[i].parentNode.replaceChild(newelement, allsuspects[i]);
		}
	}
}

function loadCorrespondingJS(mcu, oldChipType) {
	var chipType;

	if (mcu.indexOf('M451T90NM') === 0) {
		chipType = 'TC8222';
	}
	else if (mcu.indexOf('M45') === 0 || mcu.indexOf('M4TK') === 0) {
		chipType = 'M451';
	}
	else if (mcu.indexOf('M48') === 0) {
		chipType = 'M480';
	}
	else if (mcu.indexOf('M251') === 0 || mcu.indexOf('M252') === 0) {
		chipType = 'M251';
	}
	else if (mcu.indexOf('M031') === 0 || mcu.indexOf('M032') === 0) {
		chipType = 'M031';
	}
	else if (mcu.indexOf('M2351') === 0) {
		chipType = 'M2351';
	}
	else if (mcu.indexOf('M0518') === 0) {
		chipType = 'M0518';
	}
	else if (mcu.indexOf('M0519') === 0) {
		chipType = 'M0519';
	}
	else if (mcu.indexOf('M05') === 0 && mcu.indexOf('DN(') !== -1) {
		chipType = 'M051DN';
	}
	else if (mcu.indexOf('M05') === 0 && mcu.indexOf('DE(') !== -1) {
		chipType = 'M051DE';
	}
	else if (mcu.indexOf('M05') === 0 && mcu.indexOf('BN(') !== -1) {
		chipType = 'M051BN';
	}
	else if (mcu.indexOf('E32') === 0) {
		chipType = 'M051BN';
	}
	else if (mcu.indexOf('M058S') === 0) {
		chipType = 'M058S';
	}
	else if (mcu.indexOf('M05') === 0 && mcu.indexOf('AN(') !== -1) {
		chipType = 'M051AN';
	}
	else if (mcu.indexOf('MINI58') === 0) {
		chipType = 'MINI58';
	}
	else if (mcu.indexOf('MINI5') === 0 && mcu.indexOf('AN(') !== -1) {
		chipType = 'MINI51AN';
	}
	else if ((mcu.indexOf('MINI5') === 0 && mcu.indexOf('AE(') !== -1) ||
		mcu.indexOf('MINI54XFHC') === 0 ||
		mcu.indexOf('MINI55') === 0 ||
		mcu.indexOf('NVS06AL') === 0) {
		chipType = 'MINI55';
	}
	else if ((mcu.indexOf('MINI5') === 0 && mcu.indexOf('DE(') !== -1) ||
		mcu.indexOf('MINI54FHC') === 0) {
		chipType = 'MINI51DE';
	}
	else if (mcu.indexOf('NUC2201') === 0) {
		chipType = 'NUC2201';
	}
	else if (mcu.indexOf('NUC2') === 0 && mcu.indexOf('AN(') !== -1) {
		chipType = 'NUC200AN';
	}
	else if (mcu.indexOf('NUC029KGE') === 0) {
		chipType = 'NUC029KGE';
	}
	else if (mcu.indexOf('NUC029LDE') === 0 || mcu.indexOf('NUC029SDE') === 0) {
		chipType = 'NUC029xDE';
	}
	else if (mcu.indexOf('NUC029LGE') === 0 || mcu.indexOf('NUC029SGE') === 0) {
		chipType = 'NUC029xGE';
	}
	else if (mcu.indexOf('NUC029LEE') === 0 || mcu.indexOf('NUC029SEE') === 0) {
		chipType = 'NUC029xEE';
	}
	else if (mcu.indexOf('NUC029TAE') === 0) {
		chipType = 'NUC029TAE';
	}
	else if (mcu.indexOf('NUC2') === 0 && mcu.indexOf('AE(') !== -1) {
		chipType = 'NUC200AE';
	}
	else if (mcu.indexOf('NUC029') === 0 && mcu.indexOf('AE(') !== -1) {
		chipType = 'NUC029AE';
	}
	else if (mcu.indexOf('NUC029') === 0 && mcu.indexOf('AN(') !== -1) {
		chipType = 'NUC029AN';
	}
	else if ((mcu.indexOf('NANO120') === 0 || mcu.indexOf('NANO100') === 0) &&
		mcu.indexOf('AN(') !== -1) {
		chipType = 'NANO100AN';
	}
	else if ((mcu.indexOf('NANO100') === 0 || mcu.indexOf('NANO110') === 0 || mcu.indexOf('NANO120') === 0 || mcu.indexOf('NANO130') === 0) &&
		mcu.indexOf('BN(') !== -1) {
		chipType = 'NANO100BN';
	}
	else if (mcu.indexOf('NANO103') === 0 && mcu.indexOf('AE(') !== -1) {
		chipType = 'NANO103';
	}
	else if (mcu.indexOf('NANO1') === 0 && mcu.indexOf('AN(') !== -1) {
		chipType = 'NANO112';
	}
	else if (mcu.indexOf('NM11') === 0 || mcu.indexOf('NM12') === 0) {
		chipType = 'NM1200';
	}
	else if (mcu.indexOf('NM15') === 0) {
		chipType = 'NM1500';
	}
	else if (mcu.indexOf('NUC121') === 0 || mcu.indexOf('NUC125') === 0) {
		chipType = 'NUC121AE';
	}
	else if (mcu.indexOf('NUC122') === 0 && mcu.indexOf('AN(') !== -1) {
		chipType = 'NUC122AN';
	}
	else if (mcu.indexOf('NUC123') === 0 &&
			(mcu.indexOf('AN0(') !== -1 || mcu.indexOf('AN1(') !== -1 ||
			mcu.indexOf('AE0(') !== -1 || mcu.indexOf('AE1(') !== -1)) {
		chipType = 'NUC123AN_AE';
	}
	else if (mcu.indexOf('NUC1') === 0 && mcu.indexOf('AN(') !== -1) {
		chipType = 'NUC100AN';
	}
	else if (mcu.indexOf('NUC1') === 0 && mcu.indexOf('BN(') !== -1) {
		chipType = 'NUC100BN';
	}
	else if (mcu.indexOf('NUC1') === 0 && mcu.indexOf('CN(') !== -1) {
		chipType = 'NUC100CN';
	}
	else if (mcu.indexOf('NUC1') === 0 && mcu.indexOf('DN(') !== -1) {
		chipType = 'NUC100DN';
	}
	else if (mcu.indexOf('NUC1261') === 0) {
		chipType = 'NUC1261';
	}
	else if (mcu.indexOf('NUC126') === 0) {
		chipType = 'NUC126';
	}
	else if (mcu.indexOf('NUC13') === 0) {
		chipType = 'NUC131';
	}
	else if (mcu.indexOf('NUC505') === 0) {
		chipType = 'NUC505';
	}
	else if (mcu.indexOf('I91') === 0) {
		chipType = 'ISD9100';
	}
	else if (mcu.indexOf('I93') === 0) {
		chipType = 'ISD9300';
	}
	else {
		chipType = 'NUC400';
	}

	if (oldChipType === "") {
		// load the relevant content js file
		loadjscssFile('NUC_' + chipType + '_Content.js', "js");
	}
	else {
		replacejscssfile('NUC_' + oldChipType + '_Content.js', 'NUC_' + chipType + '_Content.js', "js");
		//startPin = -1;
		//endPin = -1; // return to default
	}
	oldChipType = chipType;
	//window.alert(chipType)

	return oldChipType;
}

function getPropertyNames(obj) {
	var moduleNames = [],
		index = 0,
		name;
	for (name in obj) {
		if (obj.hasOwnProperty(name)) {
			moduleNames[index] = name;
			index += 1;
		}
	}
	index = null;

	return moduleNames;
}

(function mainTest() {
	var x,
		maxX,
		targetChips = [
			"NUC029/NUC029LDE(LQFP48)"//"NUC505/NUC505DL13Y(LQFP48)" "NANO100/NANO103LD3AE(LQFP48)" "M051/M058LDE(LQFP48)""NANO100/NANO100LE3BN(LQFP48)" "M0518/M0518LC2AE(LQFP48)" "NUC100/NUC123LC2AN1(LQFP48)" "MINI51/MINI58LDE(LQFP48)" "MINI51/MINI54LDE(LQFP48)" "MINI51/MINI55LDE(LQFP48)" "NUC029/NUC029FAE(TSSOP20)" "NM1500/NM1510LC1AE(LQFP48)" "NM1200/NM1200LBAE(LQFP48)" "MINI51/MINI52XLAE(LQFP48)" "M0519/M0519LD3AE(LQFP48)" "M051/M058SLAN(LQFP48)""NUC200/NUC240LD2AE(LQFP48)" "NUC200/NUC200LD2AN(LQFP48)" "NUC100/NUC123LD4AE0(LQFP48)" "NUC100/NUC122LC1AN(LQFP48)" "NUC100/NUC100LE3AN(LQFP48)" "NUC100/NUC130LE3CN(LQFP48)" "NUC029/NUC029LAN(LQFP48)" "NUC100/NUC120LD1DN(LQFP48)" "NUC400/NUC472VI8AE(LQFP100)" "M451/M451VG6AE(LQFP100)" "M051/M058LAN(LQFP48)"
		],
		chipSeries,
		mcu,
		oldChipType = "",
		exclusiveSource,
		replacedSource,
		selectorNames,
		currentIndexForNode = 0,
		currentIndexForCanvas = 0,
		bManipulateD3Nodes = true,
		bManipulateModuleCanvas = true,
		moduleNamesForD3Nodes = [], // If the array is assigned, the test will not run all the modules. Instead, it only runs the assigned modules.
		moduleNamesForModuleCanvas = [], // // If the array is assigned, the test will not run all the modules. Instead, it only runs the assigned modules.
		g_clockRegisterNames;

	for (x = 0, maxX = targetChips.length; x < maxX; x = x + 1) {
		// decide chipSeries and mcu
		chipSeries = targetChips[currentIndexForNode];
		chipSeries = chipSeries.slicePriorToX('/');

		mcu = targetChips[currentIndexForNode];
		mcu = mcu.sliceAfterX('/');

		oldChipType = loadCorrespondingJS(mcu, oldChipType);

		if (bManipulateD3Nodes) {
			test("Manipulate the Module Tree", function () {
				var i,
					j,
					max,
					maxJ,
					moduleNames = [],
					currentDate,
					dateTime,
					partNumber_package,
					currentNode,
					enableField,
					selectField,
					enableFieldArray = [],
					selectFieldArray = [],
					whileCount = 0,
					bVerifiedResult = true,
					bChecked = true,
					bHXTorLXT = false,
					tempString,
					showMessage,
					sSTCLK_S,
					index,
					unusedObject = {};

				if (S("#ChipTypeSelect").val() !== chipSeries) {
					S.eval('$("#ChipTypeSelect").val("' + chipSeries + '").change();');
				}
				if (S("#MCUselect").val() !== mcu) {
					S.eval('$("#MCUselect").val("' + mcu + '").change();');
				}

				// decide Test Time
				currentDate = new Date();
				dateTime = "Test Time: " + currentDate.getDate() + "/" + (currentDate.getMonth() + 1) + "/" + currentDate.getFullYear() + " at " + currentDate.getHours() + ":" + currentDate.getMinutes() + ":" + currentDate.getSeconds();

				// decide the total pin number
				partNumber_package = S("#MCUselect").val();

				ok(true, 'Chip Series: ' + S("#ChipTypeSelect").val() + ' Part No: ' + partNumber_package + ' ' + dateTime);

				// Initialization
				S.eval('NUTOOL_CLOCK.initializationByTest();');
				sSTCLK_S = 'STCLK_S'.toEquivalent().toString();
				// get g_clockRegisterNames
				g_clockRegisterNames = getPropertyNames(NUTOOL_CLOCK.g_register_map_default);
				// get moduleNames
				if (moduleNamesForD3Nodes.length === 0) {
					moduleNames = getPropertyNames(NUTOOL_CLOCK.g_Module);
				}
				else {
					moduleNames = moduleNamesForD3Nodes;
				}

				// trim some unused module if exists
				if (typeof (NUTOOL_CLOCK.g_unusedModule) !== 'undefined' && typeof (NUTOOL_CLOCK.g_unusedModule[mcu]) !== 'undefined') {
					if (typeof (NUTOOL_CLOCK.g_unusedModule[mcu]) == "function") {
						unusedObject = NUTOOL_CLOCK.g_unusedModule[mcu]();
					}
					else {
						unusedObject = NUTOOL_CLOCK.g_unusedModule[mcu];
					}

					for (i = 0; i < unusedObject.length; i += 1) {
						index = $.inArray(unusedObject[i], moduleNames);
						if (index !== -1) {
							// remove old data
							moduleNames.splice(index, 1);
						}
					}
				}

				// exclusive source of LXT and HXT
				bHXTorLXT = false;
				selectorNames = getPropertyNames(NUTOOL_CLOCK.g_CLKSEL);
				for (i = 0, max = selectorNames.length; i < max; i += 1) {
					for (j = 0, maxJ = NUTOOL_CLOCK.g_CLKSEL[selectorNames[i]].length; j < maxJ; j += 1) {
						if (NUTOOL_CLOCK.g_CLKSEL[selectorNames[i]][j].indexOf('HXTorLXT') === 0) {
							bHXTorLXT = true;
							break;
						}
						if (bHXTorLXT) {
							break;
						}
					}
				}
				if (bHXTorLXT) {
					if (S.eval('NUTOOL_CLOCK.isFieldBe1("' + 'XTL32K_EN'.toEquivalent() + '")')) {
						exclusiveSource = "LXT";
						replacedSource = "HXT";
					}
					else {
						exclusiveSource = "HXT";
						replacedSource = "LXT";
					}

					selectorNames = getPropertyNames(NUTOOL_CLOCK.g_CLKSEL);
					for (i = 0, max = selectorNames.length; i < max; i += 1) {
						for (j = 0, maxJ = NUTOOL_CLOCK.g_CLKSEL[selectorNames[i]].length; j < maxJ; j += 1) {
							if (NUTOOL_CLOCK.g_CLKSEL[selectorNames[i]][j].indexOf(replacedSource) !== -1) {
								if (NUTOOL_CLOCK.g_CLKSEL[selectorNames[i]][j].indexOf('HXTorLXT') !== -1) {
									NUTOOL_CLOCK.g_CLKSEL[selectorNames[i]][j] = NUTOOL_CLOCK.g_CLKSEL[selectorNames[i]][j].replace('HXTorLXT', exclusiveSource);

								}
								else {
									NUTOOL_CLOCK.g_CLKSEL[selectorNames[i]][j] = NUTOOL_CLOCK.g_CLKSEL[selectorNames[i]][j].replace(replacedSource, exclusiveSource);
								}
							}
						}
					}
				}

				S.eval('NUTOOL_CLOCK.uncheckAllNodes_core();');
				for (i = 0, max = moduleNames.length; i < max; i += 1) {
					currentNode = moduleNames[i];
					enableField = NUTOOL_CLOCK.g_Module[currentNode][1];
					enableFieldArray = [];
					whileCount = 0;
					if (enableField.indexOf('/') === -1) {
						enableFieldArray.push(enableField);
					}
					else {
						while (enableField.indexOf('/') !== -1) {
							enableFieldArray.push(enableField.slicePriorToX('/'));
							enableField = enableField.sliceAfterX('/');

							whileCount = whileCount + 1;
							if (whileCount > 10) {
								break;
							}
						}

						enableFieldArray.push(enableField);
					}

					bVerifiedResult = true;
					for (j = 0, maxJ = enableFieldArray.length; j < maxJ; j += 1) {
						if (S.eval('NUTOOL_CLOCK.isFieldBe1("' + enableFieldArray[j] + '")')) {
							bVerifiedResult = false;
							break;
						}
					}

					if (!bVerifiedResult) {
						ok(false, 'Initialization: unchecked all nodes unsuccessfully.');
						return;
					}
				}

				// display the frequencies of base clocks
				ok(true, "Base Clocks: " + S.eval('NUTOOL_CLOCK.reportBaseClockFrequencies();'));

				// retrieve the generated code
				S.eval('NUTOOL_CLOCK.retrieveGenerateCodeContent(0);');

				for (i = 0, max = moduleNames.length; i < max; i += 1) {
					currentNode = moduleNames[i];
					// prepare enableFieldArray
					enableField = NUTOOL_CLOCK.g_Module[currentNode][1];
					enableFieldArray = [];
					whileCount = 0;
					if (enableField.indexOf('/') === -1) {
						enableFieldArray.push(enableField);
					}
					else {
						while (enableField.indexOf('/') !== -1) {
							enableFieldArray.push(enableField.slicePriorToX('/'));
							enableField = enableField.sliceAfterX('/');

							whileCount = whileCount + 1;
							if (whileCount > 10) {
								break;
							}
						}

						enableFieldArray.push(enableField);
					}
					// prepare selectField and selectFieldArray
					selectFieldArray = [];
					if (currentNode !== 'SYSTICK') {
						selectField = NUTOOL_CLOCK.g_Module[currentNode][0];
						if (NUTOOL_CLOCK.g_CLKSEL.hasOwnProperty(selectField)) {
							for (j = 0, maxJ = NUTOOL_CLOCK.g_CLKSEL[selectField].length; j < maxJ; j += 1) {
								tempString = NUTOOL_CLOCK.g_CLKSEL[selectField][j].slicePriorToX(':').slicePriorToX('/').toString();

								if ($.inArray(tempString, selectFieldArray) === -1) {
									selectFieldArray.push(tempString);
								}
							}
						}
					}
					else {
						selectField = sSTCLK_S;
						if (NUTOOL_CLOCK.g_CLKSEL.hasOwnProperty(sSTCLK_S)) {
							for (j = 0, maxJ = NUTOOL_CLOCK.g_CLKSEL[sSTCLK_S].length; j < maxJ; j += 1) {
								tempString = NUTOOL_CLOCK.g_CLKSEL[selectField][j].slicePriorToX(':').slicePriorToX('/').toString();

								if ($.inArray(tempString, selectFieldArray) === -1) {
									selectFieldArray.push(tempString);
								}
							}
						}
						else {
							selectFieldArray.push(NUTOOL_CLOCK.g_Module[currentNode][0].slicePriorToX(':').slicePriorToX('/').toString());
						}
						selectFieldArray.push('CPUCLK');
					}

					bChecked = true;
					// try to enable a node
					S.eval('NUTOOL_CLOCK.doubleClickD3Node(' + currentNode + ');');
					for (j = 0, maxJ = enableFieldArray.length; j < maxJ; j += 1) {
						if (!S.eval('NUTOOL_CLOCK.isEnabled("' + enableFieldArray[j] + '")')) {
							bChecked = false;
							break;
						}
					}
					if (bChecked) {
						ok(true, currentNode + ': it was enabled by double-clicking.');

						// display the tooltip
						showMessage = S.eval('NUTOOL_CLOCK.retrieveNodeTooltip();');
						showMessage = showMessage.replace(/\((.*?)\)/g, "");
						showMessage = showMessage.replace(/<\/br>/g, " ");
						showMessage = showMessage.replace(/<hr>/g, " ");
						ok(true, currentNode + ': Tooltip: ' + showMessage);

						// try to drag a node
						if (selectFieldArray.length > 0) {
							for (j = 0, maxJ = selectFieldArray.length; j < maxJ; j += 1) {
								S.eval('NUTOOL_CLOCK.dragD3Node(' + currentNode + ', ' + selectFieldArray[j] + ');');
								verifySelectorValue(currentNode, selectField, selectFieldArray[j]);
								if (j === 0) {
									// retrieve the generated code
									S.eval('NUTOOL_CLOCK.retrieveGenerateCodeContent(1);');
									ok(true, currentNode + ': ' + S.eval('NUTOOL_CLOCK.retrieveGenerateCodeContent(3);'));
								}
								else {
									// retrieve the generated code
									S.eval('NUTOOL_CLOCK.retrieveGenerateCodeContent(2);');
									ok(true, currentNode + ': ' + S.eval('NUTOOL_CLOCK.retrieveGenerateCodeContent(3);'));
								}
							}
						}
						else {
							verifyNodeFrequency(currentNode);
							// retrieve the generated code
							S.eval('NUTOOL_CLOCK.retrieveGenerateCodeContent(1);');
							ok(true, currentNode + ': ' + S.eval('NUTOOL_CLOCK.retrieveGenerateCodeContent(3);'));
						}

						// try to disable a node
						S.eval('NUTOOL_CLOCK.uncheckAllNodes_core();');
						//S.eval('NUTOOL_CLOCK.doubleClickD3Node(' + currentNode + ');');
						bVerifiedResult = true;
						for (j = 0, maxJ = enableFieldArray.length; j < maxJ; j += 1) {
							if (S.eval('NUTOOL_CLOCK.isFieldBe1("' + enableFieldArray[j] + '")')) {
								bVerifiedResult = false;
								break;
							}
						}
						if (bVerifiedResult) {
							ok(true, currentNode + ': it was disabled by double-clicking.');
							//ok(true, currentNode + ': Code:' + S.eval('NUTOOL_CLOCK.retrieveGenerateCodeContent(3);'));
						}
						else {
							ok(false, 'Failed: ' + currentNode + ': it failed to be disabled by double-clicking. (' + enableFieldArray[j] + ')');
						}
					}
					else {
						ok(false, 'Failed: ' + currentNode + ': it failed to be enabled by double-clicking. (' + enableFieldArray[j] + ')');
					}
				}
				// load the relevant content js file
				// loadOrRemoveJsCssFile('NUC_' + chipType + '_Content.js', "js", "remove");
				// jump to the next chip
				currentIndexForNode = currentIndexForNode + 1;

				// retrieve the generated code to check HCLK more.
				S.eval('NUTOOL_CLOCK.retrieveGenerateCodeContent(4);');

				// copy the generated code into the clip board.
				window.clipboardData.setData("Text", "/********************\n" + S.eval('NUTOOL_CLOCK.retrieveGenerateCodeContent(100);'));

				if (targetChips.length === 1 && bManipulateModuleCanvas === false) {
					window.alert('has copied the generated code into the clip board.');
				}
			});
		}

		if (bManipulateModuleCanvas) {
			test("Manipulate Module Canvases", function () {
				var i,
					j,
					k,
					m,
					max,
					maxJ,
					maxK,
					index,
					moduleNames = [],
					currentDate,
					dateTime,
					partNumber_package,
					currentNode,
					enableField,
					selectField,
					dividerField,
					enableFieldArray = [],
					selectFieldArray = [],
					whileCount = 0,
					canvasIdString,
					clockRegName,
					fullFieldName,
					dividerUpperLimit,
					canvasWidth = 0,
					canvasHeight = 0,
					unusedObject,
					bVerifiedResult = true,
					bChecked = true,
					bHXTorLXT = false,
					tempString,
					showMessage,
					sSTCLK_S;

				if (S("#ChipTypeSelect").val() !== chipSeries) {
					S.eval('$("#ChipTypeSelect").val("' + chipSeries + '").change();');
				}
				if (S("#MCUselect").val() !== mcu) {
					S.eval('$("#MCUselect").val("' + mcu + '").change();');
				}
				// decide Test Time
				currentDate = new Date();
				dateTime = "Test Time: " + currentDate.getDate() + "/" + (currentDate.getMonth() + 1) + "/" + currentDate.getFullYear() + " at " + currentDate.getHours() + ":" + currentDate.getMinutes() + ":" + currentDate.getSeconds();
				// decide the total pin number
				partNumber_package = S("#MCUselect").val();

				ok(true, 'Chip Series: ' + S("#ChipTypeSelect").val() + ' Part No: ' + partNumber_package + ' ' + dateTime);

				// Initialization
				S.eval('NUTOOL_CLOCK.initializationByTest();');
				sSTCLK_S = 'STCLK_S'.toEquivalent().toString();

				// get g_clockRegisterNames
				g_clockRegisterNames = getPropertyNames(NUTOOL_CLOCK.g_register_map_default);
				// get moduleNames
				if (moduleNamesForModuleCanvas.length === 0) {
					moduleNames = getPropertyNames(NUTOOL_CLOCK.g_Module);
				}
				else {
					moduleNames = moduleNamesForModuleCanvas;
				}

				// trim some unused module if exists
				if (typeof (NUTOOL_CLOCK.g_unusedModule) !== 'undefined' && typeof (NUTOOL_CLOCK.g_unusedModule[mcu]) !== 'undefined') {
					if (typeof (NUTOOL_CLOCK.g_unusedModule[mcu]) == "function") {
						unusedObject = NUTOOL_CLOCK.g_unusedModule[mcu]();
					}
					else {
						unusedObject = NUTOOL_CLOCK.g_unusedModule[mcu];
					}

					for (i = 0; i < unusedObject.length; i += 1) {
						index = $.inArray(unusedObject[i], moduleNames);
						if (index !== -1) {
							// remove old data
							moduleNames.splice(index, 1);
						}
					}
				}

				// exclusive source of LXT and HXT
				bHXTorLXT = false;
				selectorNames = getPropertyNames(NUTOOL_CLOCK.g_CLKSEL);
				for (i = 0, max = selectorNames.length; i < max; i += 1) {
					for (j = 0, maxJ = NUTOOL_CLOCK.g_CLKSEL[selectorNames[i]].length; j < maxJ; j += 1) {
						if (NUTOOL_CLOCK.g_CLKSEL[selectorNames[i]][j].indexOf('HXTorLXT') === 0) {
							bHXTorLXT = true;
							break;
						}
					}
					if (bHXTorLXT) {
						break;
					}
				}
				if (bHXTorLXT) {
					if (S.eval('NUTOOL_CLOCK.isFieldBe1("' + 'XTL32K_EN'.toEquivalent() + '")')) {
						exclusiveSource = "LXT";
						replacedSource = "HXT";
					}
					else {
						exclusiveSource = "HXT";
						replacedSource = "LXT";
					}

					selectorNames = getPropertyNames(NUTOOL_CLOCK.g_CLKSEL);
					for (i = 0, max = selectorNames.length; i < max; i += 1) {
						for (j = 0, maxJ = NUTOOL_CLOCK.g_CLKSEL[selectorNames[i]].length; j < maxJ; j += 1) {
							if (NUTOOL_CLOCK.g_CLKSEL[selectorNames[i]][j].indexOf(replacedSource) !== -1) {
								NUTOOL_CLOCK.g_CLKSEL[selectorNames[i]][j] = exclusiveSource + ':' + NUTOOL_CLOCK.g_CLKSEL[selectorNames[i]][j].sliceAfterX(':');
							}
						}
					}
				}

				S.eval('NUTOOL_CLOCK.uncheckAllNodes_core();');
				for (i = 0, max = moduleNames.length; i < max; i += 1) {
					currentNode = moduleNames[i];
					enableField = NUTOOL_CLOCK.g_Module[currentNode][1];
					enableFieldArray = [];
					whileCount = 0;
					if (enableField.indexOf('/') === -1) {
						enableFieldArray.push(enableField);
					}
					else {
						while (enableField.indexOf('/') !== -1) {
							enableFieldArray.push(enableField.slicePriorToX('/'));
							enableField = enableField.sliceAfterX('/');

							whileCount = whileCount + 1;
							if (whileCount > 10) {
								break;
							}
						}

						enableFieldArray.push(enableField);
					}

					bVerifiedResult = true;
					for (j = 0, maxJ = enableFieldArray.length; j < maxJ; j += 1) {
						if (S.eval('NUTOOL_CLOCK.isFieldBe1("' + enableFieldArray[j] + '")')) {
							bVerifiedResult = false;
							break;
						}
					}

					if (!bVerifiedResult) {
						ok(false, 'Initialization: unchecked all nodes unsuccessfully.');
						return;
					}
				}

				// display the frequencies of base clocks
				ok(true, "Base Clocks: " + S.eval('NUTOOL_CLOCK.reportBaseClockFrequencies();'));

				for (i = 0, max = moduleNames.length; i < max; i += 1) {
					currentNode = moduleNames[i];
					// prepare enableFieldArray
					enableField = NUTOOL_CLOCK.g_Module[currentNode][1];
					enableFieldArray = [];
					whileCount = 0;
					if (enableField.indexOf('/') === -1) {
						enableFieldArray.push(enableField);
					}
					else {
						while (enableField.indexOf('/') !== -1) {
							enableFieldArray.push(enableField.slicePriorToX('/'));
							enableField = enableField.sliceAfterX('/');

							whileCount = whileCount + 1;
							if (whileCount > 10) {
								break;
							}
						}

						enableFieldArray.push(enableField);
					}
					// prepare selectField and selectFieldArray
					selectFieldArray = [];
					if (currentNode !== 'SYSTICK') {
						selectField = NUTOOL_CLOCK.g_Module[currentNode][0];
						if (NUTOOL_CLOCK.g_CLKSEL.hasOwnProperty(selectField)) {
							for (j = 0, maxJ = NUTOOL_CLOCK.g_CLKSEL[selectField].length; j < maxJ; j += 1) {
								tempString = NUTOOL_CLOCK.g_CLKSEL[selectField][j].slicePriorToX(':').toString();
								selectFieldArray.push(tempString);
							}
						}
					}
					else {
						selectField = sSTCLK_S;
						if (NUTOOL_CLOCK.g_CLKSEL.hasOwnProperty(sSTCLK_S)) {
							for (j = 0, maxJ = NUTOOL_CLOCK.g_CLKSEL[sSTCLK_S].length; j < maxJ; j += 1) {
								tempString = NUTOOL_CLOCK.g_CLKSEL[selectField][j].slicePriorToX(':').toString();
								selectFieldArray.push(tempString);
							}
						}
						else {
							selectFieldArray.push(NUTOOL_CLOCK.g_Module[currentNode][0]);
						}
						selectFieldArray.push('CPUCLK');
					}
					// prepare dividerField
					dividerField = NUTOOL_CLOCK.g_Module[currentNode][2];

					bChecked = true;
					// try to enable a node
					S.eval('NUTOOL_CLOCK.doubleClickD3Node(' + currentNode + ');');
					for (j = 0, maxJ = enableFieldArray.length; j < maxJ; j += 1) {
						if (!S.eval('NUTOOL_CLOCK.isEnabled("' + enableFieldArray[j] + '")')) {
							bChecked = false;
							break;
						}
					}
					if (bChecked) {
						ok(true, currentNode + ': it was enabled by double-clicking.');

						// display the tooltip
						showMessage = S.eval('NUTOOL_CLOCK.retrieveNodeTooltip();');
						showMessage = showMessage.replace(/\((.*?)\)/g, "");
						showMessage = showMessage.replace(/<\/br>/g, " ");
						showMessage = showMessage.replace(/<hr>/g, " ");
						ok(true, currentNode + ': Tooltip: ' + showMessage);

						// try to click the module canvas
						canvasIdString = currentNode + '_canvas';

						canvasWidth = S("#" + canvasIdString).css('width');
						canvasHeight = S("#" + canvasIdString).css('height');

						canvasWidth = parseFloat(canvasWidth.slice(0, canvasWidth.length - 2));
						canvasHeight = parseFloat(canvasHeight.slice(0, canvasHeight.length - 2));

						// check select part
						m = 0;
						if (selectFieldArray.length > 0) {
							for (j = 0, maxJ = selectFieldArray.length; j < maxJ; j += 1) {
								S.eval('NUTOOL_CLOCK.clickModuleCanvas(' + currentNode + ', ' + j + ');');
								verifySelectorValue(currentNode, selectField, selectFieldArray[j]);
							}
						}
						else {
							verifyNodeFrequency(moduleNames[i]);
						}

						// check divider part
						if (dividerField !== 'none') {
							// determine dividerUpperLimit
							for (j = 0, maxJ = g_clockRegisterNames.length; j < maxJ; j += 1) {
								clockRegName = g_clockRegisterNames[j];
								for (k = 0, maxK = NUTOOL_CLOCK.g_register_map[clockRegName].length; k < maxK; k += 1) {
									fullFieldName = NUTOOL_CLOCK.g_register_map[clockRegName][k];
									if (fullFieldName.indexOf(dividerField) !== -1 && fullFieldName.indexOf(':') === dividerField.length) {
										if (fullFieldName.indexOf('-') !== -1) {
											dividerUpperLimit = parseInt(fullFieldName.sliceBetweenXandX(':', '-'), 10) - parseInt(fullFieldName.sliceAfterX('-'), 10) + 1;
										}
										else {
											dividerUpperLimit = parseInt(fullFieldName.sliceAfterX(':'), 10);
										}

										dividerUpperLimit = Math.pow(2, dividerUpperLimit) - 1;
										break;
									}
								}
							}

							S.eval('NUTOOL_CLOCK.clickModuleCanvas(' + currentNode + ', 100);');
							S.eval('NUTOOL_CLOCK.changeDividerDialogInput("' + dividerField + '", 0);');
							verifyDividerValue(currentNode, dividerField, 0);
							S.eval('NUTOOL_CLOCK.changeDividerDialogInput("' + dividerField + '", ' + Math.floor(dividerUpperLimit / 2) + ');');
							verifyDividerValue(currentNode, dividerField, Math.floor(dividerUpperLimit / 2));
							S.eval('NUTOOL_CLOCK.changeDividerDialogInput("' + dividerField + '", ' + Math.floor(dividerUpperLimit) + ');');
							verifyDividerValue(currentNode, dividerField, Math.floor(dividerUpperLimit));

							// restore the value of divider to 0
							S.eval('NUTOOL_CLOCK.changeDividerDialogInput("' + dividerField + '", 0);');

							//moveLength = Math.floor(canvasWidth / 2 - arrowConstantLineLength - (currentNode.length * 18) - canvas_startPointX);
							//if (moveLength >= 0) {
							//	clickLocationString = '+' + Math.abs(moveLength);
							//}
							//else {
							//	clickLocationString = '-' + Math.abs(moveLength);
							//}

							//moveLength = 0;
							//if (moveLength >= 0) {
							//	clickLocationString = clickLocationString + ' +' + Math.abs(moveLength);
							//}
							//else {
							//	clickLocationString = clickLocationString + ' -' + Math.abs(moveLength);
							//}

							//S('#' + canvasIdString).move(clickLocationString).then(function () {
							//	S("#" + canvasIdString).click().then(function () {
							//		verifyDividerValue(currentNode, dividerField, 0);
							//		verifyDividerValue(currentNode, dividerField, dividerUpperLimit / 2);
							//		verifyDividerValue(currentNode, dividerField, dividerUpperLimit);
							//	});
							//});
						}

						// try to disable the node
						S.eval('NUTOOL_CLOCK.uncheckAllNodes_core();');
						//S.eval('NUTOOL_CLOCK.doubleClickD3Node(' + moduleNames[i] + ');');
						bVerifiedResult = true;
						for (j = 0, maxJ = enableFieldArray.length; j < maxJ; j += 1) {
							if (S.eval('NUTOOL_CLOCK.isFieldBe1("' + enableFieldArray[j] + '")')) {
								bVerifiedResult = false;
								break;
							}
						}
						if (bVerifiedResult) {
							ok(true, moduleNames[i] + ': it was disabled by double-clicking.');
						}
						else {
							ok(false, 'Failed: ' + moduleNames[i] + ': it failed to be disabled by double-clicking. (' + enableFieldArray[j] + ')');
						}

						// restore the index of module canvases to the default value (-1)
						S.eval('NUTOOL_CLOCK.clickModuleCanvas("", -1);');
					}
					else {
						ok(false, 'Failed: ' + moduleNames[i] + ': it failed to be enabled by double-clicking. (' + enableFieldArray[j] + ')');
					}
				}

				// load the relevant content js file
				// loadOrRemoveJsCssFile('NUC_' + chipType + '_Content.js', "js", "remove");
				// jump to the next chip
				currentIndexForCanvas = currentIndexForCanvas + 1;

				if (targetChips.length === 1 && bManipulateD3Nodes === true) {
					window.alert('has copied the generated code into the clip board.');
				}
			});
		}
	}
}());

