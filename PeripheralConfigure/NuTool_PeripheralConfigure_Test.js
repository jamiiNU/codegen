// the sole global variable denoted by capital letters
var NUTOOL_PER = {};

module("Peripheral Configure Tool", {
	setup: function () {
		S.open("../index.htm", function onOpenSuccess() {
			var localQueryParams;

			localQueryParams = JSON.parse($.ajax({ url: 'FunctionalTesting/headerGenerator.txt', async: false }).responseText.replace(/\r/g, ""));
			if (typeof localQueryParams.server !== 'undefined' &&
				localQueryParams.server.toLowerCase().indexOf('d') === 0) {
				S.win.resizeTo(screen.availWidth, screen.availHeight * 1 / 2);
				S.win.moveTo(0, screen.availHeight * 1 / 2);
			}
			else {
				S.win.resizeTo(0, 0);
				S.win.moveTo(0, 0);
			}
		});
	},
	teardown: function () {
		//S.win.close();
	}
});

window.onbeforeunload = function (event) {
	sendAjaxRequestToPythonApp("the tester", "shutdown");
};

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
		targetelement = (filetype === "js") ? "script" : (filetype === "css") ? "link" : "none", //determine element type to create nodelist using
		targetattr = (filetype === "js") ? "src" : (filetype === "css") ? "href" : "none", //determine corresponding attribute to test for
		allsuspects = window.document.getElementsByTagName(targetelement),
		newelement = null;

	if (typeof NUTOOL_PIN !== 'undefined' && filetype === "js") {
		// Add the preceding path
		oldfilename = "PeripheralConfigure/" + oldfilename;
		newfilename = "PeripheralConfigure/" + newfilename;
	}

	if (newfilename !== "PeripheralConfigure/") {
		newelement = createjscssfile(newfilename, filetype);
	}

	if (window.console) { window.console.log("In replacejscssfile, oldfilename:" + oldfilename + " / newfilename:" + newfilename); }

	// To update the data in js file fresh, remove the matched files and add the new one.
	for (i = allsuspects.length; i >= 0; i -= 1) { //search backwards within nodelist for matching elements to remove
		if (allsuspects[i] && allsuspects[i].getAttribute(targetattr) !== null) {
			if (allsuspects[i].getAttribute(targetattr) === oldfilename) {
				allsuspects[i].parentNode.removeChild(allsuspects[i]);
			}
			else if (allsuspects[i].getAttribute(targetattr) === newfilename && newfilename !== '') {
				allsuspects[i].parentNode.removeChild(allsuspects[i]);
			}
		}
	}
	if (newelement !== null) {
		allsuspects[0].parentNode.appendChild(newelement);
	}
}

function getRandomInt(max) {
  return Math.floor(Math.random() * Math.floor(max));
}

function loadCorrespondingJS(mcu, oldChipType) {
	var chipType;

	chipType = S.eval('NUTOOL_PER.decideNewChipType("' + mcu +'");');

	if (oldChipType === "") {
		// load the relevant content js file
		loadjscssFile('NUC_' + chipType + '_Content.js', "js");
	}
	else {
		replacejscssfile('NUC_' + oldChipType + '_Content.js', 'NUC_' + chipType + '_Content.js', "js");
	}
	oldChipType = chipType;

	return oldChipType;
}

function loadPeripheralTestJS(chipType, newfilename, oldfilename) {
	if (typeof oldfilename === 'undefined') {
		replacejscssfile(chipType + '/' + newfilename + '.js', chipType + '/' + newfilename + '.js', "js");
	}
	else {
		replacejscssfile(chipType + '/' + oldfilename + '.js', chipType + '/' + newfilename + '.js', "js");
	}
}

function decide_cfg_gpiosIndex(pinName, mcu) {
	var returnResult = [],
		chipType = S.eval('NUTOOL_PER.decideNewChipType("' + mcu +'");');

	pinName = pinName.replace('GP', 'P'); // 'GPAXXX' -> 'PAXXX'
	if (chipType === "NM1500" || chipType === "M0519" ||
		chipType === "M051DN_DE" || chipType === "M051BN" || chipType === "M051AN" || chipType === "M058S" ||
		chipType === "MINI51AN" || chipType === "MINI51DE" || chipType === "MINI55" || chipType === "MINI58" ||
		chipType === "NUC029AE" || chipType === "NUC029AN" ||
		chipType === "NM1200") {
		returnResult.push(parseInt(pinName.slice(1, 2), 16) * 8);
		returnResult.push(returnResult[0] + 8);
	}
	else if (chipType === "ML51") {
		returnResult.push(parseInt(pinName.slice(1, 2), 16) * 8);
		returnResult.push(returnResult[0] + 8);
	}
	else if (chipType === "MINI57" || chipType === "NM1120" || chipType === "NDA102") {
		returnResult.push((pinName.slice(1, 2).charCodeAt(0) - 'A'.charCodeAt(0)) * 8);
		returnResult.push(returnResult[0] + 8);
	}
	else  {
		returnResult.push((pinName.slice(1, 2).charCodeAt(0) - 'A'.charCodeAt(0)) * 16);
		returnResult.push(returnResult[0] + 16);
	}

	return returnResult;
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

function decimalToHex(d, padding) {
	var hex = Number(d).toString(16);
	padding = typeof (padding) === "undefined" || padding === null ? padding = 8 : padding;

	while (hex.length < padding) {
		hex = "0" + hex;
	}

	return hex;
}

function isNumberic(n) {
	n = n.replace(/\b(\d+)[kmgtpe]\b/g,"10");
	return !isNaN(parseFloat(n)) && isFinite(n);
}

function isTrue(s) {
	var bResult = false;
	s = s.toString().toLowerCase();
	if (s === 'true' || s === '1') {
		bResult = true;
	}
	return bResult;
}

function isObject(obj) {
	var type = typeof obj;
	return type === 'function' || type === 'object' && !!obj;
}

g_showErrorMessage = false;
function showErrorMessage(errorMessage) {
	ok(false, errorMessage);
	g_showErrorMessage = true;
}

function checkWordsInTag(id, field, fieldText, localQueryEnglishWords, localNuvotonWords, localNuvotonUnitWords) {
	var i,
		j,
		max,
		maxJ,
		bFound,
		localDataArray = [],
		localDataArray1 = [],
		searchNuvotonWords,
		returnData = "";

	searchNuvotonWords = function (localData) {
		bFound = false;
		for (j = 0, maxJ = localNuvotonWords.length; j < maxJ; j = j + 1) {
			if (localNuvotonWords[j].length > 1 &&
				((localData === localNuvotonWords[j]) || (localData.indexOf(localNuvotonWords[j] + '_') !== -1) || (localData.indexOf('_' + localNuvotonWords[j]) !== -1) ||
				(localNuvotonWords[j].indexOf('?') !== -1 &&
				((localData.indexOf(localNuvotonWords[j].toString().slicePriorToX('?')) === 0 &&
				  localNuvotonWords[j].toString().slicePriorToX('?') !== "" &&
				  (localData === localNuvotonWords[j].toString().slicePriorToX('?') || (localData.indexOf(localNuvotonWords[j].toString().slicePriorToX('?') + '_') !== -1) || (localData.indexOf('_' + localNuvotonWords[j].toString().slicePriorToX('?')) !== -1) ||
				   isNumberic(localData.sliceAfterX(localNuvotonWords[j].toString().slicePriorToX('?')).slicePriorToX('_')))) ||
				 (localData.lastIndexOf(localNuvotonWords[j].toString().sliceAfterX('?')) !== -1 &&
				 (localData.lastIndexOf(localNuvotonWords[j].toString().sliceAfterX('?')) + localNuvotonWords[j].toString().sliceAfterX('?').length === localData.length) &&
				  (localData === localNuvotonWords[j].toString().sliceAfterX('?') || (localData.indexOf(localNuvotonWords[j].toString().sliceAfterX('?') + '_') !== -1) || (localData.indexOf('_' + localNuvotonWords[j].toString().sliceAfterX('?')) !== -1) ||
				   isNumberic(localData.slicePriorToX(localNuvotonWords[j].toString().sliceAfterX('?')).sliceAfterX('_')))))))) {
				bFound = true;
				break;
			}
		}
		if (!bFound) {
			for (j = 0, maxJ = localNuvotonUnitWords.length; j < maxJ; j = j + 1) {
				if ((localData.lastIndexOf(localNuvotonUnitWords[j]) !== -1 && (localData.lastIndexOf(localNuvotonUnitWords[j]) + localNuvotonUnitWords[j].length === localData.length)) &&
					isNumberic(localData.slicePriorToX(localNuvotonUnitWords[j]))) {
					bFound = true;
					break;
				}
			}
		}

		return bFound;
	};

	localDataArray = fieldText.toString().split(/[ ,':;!@#$%&*?+~<>(){}|\^\-\.\/\[\]\\]+/);
	$.each(localDataArray, function(i, el){
		if($.inArray(el, localDataArray1) === -1 && fieldText.toString().indexOf('(' + el + ')') === -1) localDataArray1.push(el);
	});
	for (i = 0, max = localDataArray1.length; i < max ; i = i + 1) {
		if (localQueryEnglishWords.indexOf(localDataArray1[i].trim().toLowerCase()) === -1 &&
			!searchNuvotonWords(localDataArray1[i].trim().toLowerCase()) &&
			localDataArray1[i].trim() !== "" &&
			!isNumberic(localDataArray1[i].trim().toLowerCase())) {
			returnData = id + ',' + field + ',' + localDataArray1[i] + '\n';
		}
	}

	return returnData;
}

function makeDependencyValid(id, local_perControls_info, local_perControls_cfg, cachedIds) {
	var i,
		j,
		k,
		m,
		n,
		max,
		maxJ,
		maxK,
		maxM,
		maxN,
		localEnum,
		localData,
		localArray,
		localControl,
		localDependenciesOption,
		localDependenciesArray = [],
		ar = [],
		sp = [],
		sub = [],
		dependenciesId,
		dependenciesGroupId,
		parseIntBase,
		bFound;
		valid = false;

	if (typeof cachedIds === 'undefined') {
		cachedIds = [];
	}
	if (cachedIds.indexOf(id) !== -1) {
		//ok(true, 'cachedIds happened in makeDependencyValid: ' + id);
		valid = true;
		return valid;
	}
	else {
		cachedIds.push(id);
	}
	localControl = local_perControls_info[id];
	localDependenciesArray = [];
	if (typeof localControl.dependencies !== 'undefined' &&
		localControl.dependencies !== 'none' &&
		localControl.dependencies !== '') {
		if (Array.isArray(localControl.dependencies)) {
			localDependenciesArray = localControl.dependencies;
		}
		else if (localControl.dependencies.toString().indexOf('|') !== -1 ||
				 localControl.dependencies.toString().indexOf('&') !== -1) {
			sp = localControl.dependencies.toString().split('|');
			ar = [];
			for (j = 0; j < sp.length; j++)
			{
				sub = sp[j].split('&');
				for (k = 0; k < sub.length; k++)
				{
					localDependenciesArray.push(sub[k].replace(/\(/g, '').replace(/\)/g, '').replace(/\!/g, '').replace(/\s/g, ''));
				}
			}
		}
		else {
			localDependenciesArray[0] = localControl.dependencies;
		}
	}

	if (localDependenciesArray.length !== 0 &&
		(typeof localControl.dependenciesOption === 'undefined' ||
		localControl.dependenciesOption === 'none' ||
		localControl.dependenciesOption === '')) {
			return valid;
	}

	valid = true;
	for (i = 0, max = localDependenciesArray.length; i < max ; i = i + 1) {
		dependenciesId = localDependenciesArray[i];
		if (typeof local_perControls_info[dependenciesId] !== 'undefined') {
			if (local_perControls_info[dependenciesId].groupId === '') {
				dependenciesGroupId = '';
			}
			else {
				dependenciesGroupId = local_perControls_info[dependenciesId].groupId + '_';
			}
			// recursively handle dependencies
			makeDependencyValid(dependenciesId, local_perControls_info, local_perControls_cfg, cachedIds);

			if (typeof localControl.dependenciesOption == 'object' &&
				typeof localControl.dependenciesOption[dependenciesId] !== 'undefined') {
				localDependenciesOption = localControl.dependenciesOption[dependenciesId];
			}
			else {
				localDependenciesOption = localControl.dependenciesOption;
			}
			if (Array.isArray(localDependenciesOption)) {
				if (local_perControls_info[dependenciesId].type === 'select') {
					manipulateSelectControl(dependenciesId, dependenciesGroupId, localDependenciesOption[0], local_perControls_cfg);
				}
				else if (local_perControls_info[dependenciesId].type === 'multipleselect') {
					manipulateMultipleSelectControl(dependenciesId, dependenciesGroupId, localDependenciesOption, local_perControls_cfg);
				}
				else if (local_perControls_info[dependenciesId].type === 'radio') {
					manipulateRadioControl(dependenciesId, dependenciesGroupId, local_perControls_info[dependenciesId].enum, localDependenciesOption[0], local_perControls_cfg);
				}
				else if (local_perControls_info[dependenciesId].type === 'checkbox') {
					manipulateCheckboxControl(dependenciesId, dependenciesGroupId, local_perControls_info[dependenciesId].enum, localDependenciesOption, local_perControls_cfg);
				}
				else if (local_perControls_info[dependenciesId].type === 'integer') {
					manipulateIntegerOrHexTextControl(dependenciesId, dependenciesGroupId, parseInt(localDependenciesOption[0], 10), local_perControls_cfg);
				}
				else if (local_perControls_info[dependenciesId].type === 'hextext') {
					manipulateIntegerOrHexTextControl(dependenciesId, dependenciesGroupId, parseInt(localDependenciesOption[0], 16), local_perControls_cfg);
				}
				else {
					showErrorMessage('something strange a1 in makeDependencyValid: ' + dependenciesId);
				}
			}
			else if (localDependenciesOption.toString().indexOf('|') !== -1 ||
					 localDependenciesOption.toString().indexOf('&') !== -1) {
				sp = localDependenciesOption.toString().split('|');
				ar = [];
				for (m = 0; m < sp.length; m++)
				{
					sub = sp[m].split('&');
					for (n = 0; n < sub.length; n++)
					{
						ar.push(sub[n].replace(/\(/g, '').replace(/\)/g, '').replace(/\!/g, '').replace(/\s/g, ''));
					}
				}
				if (local_perControls_info[dependenciesId].type === 'select') {
					manipulateSelectControl(dependenciesId, dependenciesGroupId, ar[0], local_perControls_cfg);
				}
				else if (local_perControls_info[dependenciesId].type === 'multipleselect') {
					manipulateMultipleSelectControl(dependenciesId, dependenciesGroupId, ar, local_perControls_cfg);
				}
				else if (local_perControls_info[dependenciesId].type === 'radio') {
					manipulateRadioControl(dependenciesId, dependenciesGroupId, local_perControls_info[dependenciesId].enum, ar[0], local_perControls_cfg);
				}
				else if (local_perControls_info[dependenciesId].type === 'checkbox') {
					manipulateCheckboxControl(dependenciesId, dependenciesGroupId, local_perControls_info[dependenciesId].enum, ar, local_perControls_cfg);
				}
				else {
					showErrorMessage('something strange b1 in makeDependencyValid: ' + dependenciesId);
				}
			}
			else if (localDependenciesOption.toString().indexOf('>') !== -1 ||
					 localDependenciesOption.toString().indexOf('<') !== -1 ||
					 localDependenciesOption.toString().indexOf('=') !== -1) {
				localData = localDependenciesOption.sliceAfterX('>').sliceAfterX('<').sliceAfterX('=').sliceAfterX('=');
				if (local_perControls_info[dependenciesId].type === 'integer' ||
					local_perControls_info[dependenciesId].type === 'hextext') {
					if (local_perControls_info[dependenciesId].type === 'integer') {
						parseIntBase = 10;
					}
					else {
						parseIntBase = 16;
					}
					if (localDependenciesOption.toString().indexOf('>') !== -1) {
						manipulateIntegerOrHexTextControl(dependenciesId, dependenciesGroupId, parseInt(localData, parseIntBase) + 1, local_perControls_cfg);
					}
					else if (localDependenciesOption.toString().indexOf('<') !== -1) {
						manipulateIntegerOrHexTextControl(dependenciesId, dependenciesGroupId, parseInt(localData, parseIntBase) - 1, local_perControls_cfg);
					}
					else { // localDependenciesOption.toString().indexOf('=')
						manipulateIntegerOrHexTextControl(dependenciesId, dependenciesGroupId, parseInt(localData, parseIntBase), local_perControls_cfg);
					}
				}
				else if (local_perControls_info[dependenciesId].type === 'select' ||
						 local_perControls_info[dependenciesId].type === 'radio') {
					bFound = false;
					parseIntBase = 16;
					for (m = 0; m < local_perControls_info[dependenciesId].enum.length; m++) {
						localEnum = local_perControls_info[dependenciesId].enum[m];
						if (localDependenciesOption.replace(/[0-9]/g, '') === '>' &&
							parseInt(localEnum, parseIntBase) > parseInt(localData, parseIntBase)) {
							bFound = true;
							break;
						}
						else if (localDependenciesOption.replace(/[0-9]/g, '') === '>=' &&
								 parseInt(localEnum, parseIntBase) >= parseInt(localData, parseIntBase)) {
							bFound = true;
							break;
						}
						else if (localDependenciesOption.replace(/[0-9]/g, '') === '<' &&
								 parseInt(localEnum, parseIntBase) < parseInt(localData, parseIntBase)) {
							bFound = true;
							break;
						}
						else if (localDependenciesOption.replace(/[0-9]/g, '') === '<=' &&
								 parseInt(localEnum, parseIntBase) <= parseInt(localData, parseIntBase)) {
							bFound = true;
							break;
						}
						else if ((localDependenciesOption.replace(/[0-9]/g, '') === '='  ||
								  localDependenciesOption.replace(/[0-9]/g, '') === '==' ||
								  localDependenciesOption.replace(/[0-9]/g, '') === '')&&
								 parseInt(localEnum, parseIntBase) == parseInt(localData, parseIntBase)) {
							bFound = true;
							break;
						}
					}
					if (bFound) {
						if (local_perControls_info[dependenciesId].type === 'select') {
							manipulateSelectControl(dependenciesId, dependenciesGroupId, localEnum, local_perControls_cfg);
						 }
						else if (local_perControls_info[dependenciesId].type === 'radio') {
							manipulateRadioControl(dependenciesId, dependenciesGroupId, local_perControls_info[dependenciesId].enum, localEnum, local_perControls_cfg);
						}
					}
					else {
						showErrorMessage('something strange b2 in makeDependencyValid: ' + dependenciesId);
					}
				}
			}
			else {
				if (local_perControls_info[dependenciesId].type === 'select') {
					manipulateSelectControl(dependenciesId, dependenciesGroupId, localDependenciesOption, local_perControls_cfg);
				}
				else if (local_perControls_info[dependenciesId].type === 'multipleselect') {
					manipulateMultipleSelectControl(dependenciesId, dependenciesGroupId, localDependenciesOption, local_perControls_cfg);
				}
				else if (local_perControls_info[dependenciesId].type === 'radio') {
					manipulateRadioControl(dependenciesId, dependenciesGroupId, local_perControls_info[dependenciesId].enum, localDependenciesOption, local_perControls_cfg);
				}
				else if (local_perControls_info[dependenciesId].type === 'checkbox') {
					manipulateCheckboxControl(dependenciesId, dependenciesGroupId, local_perControls_info[dependenciesId].enum, localDependenciesOption, local_perControls_cfg);
				}
				else if (local_perControls_info[dependenciesId].type === 'checkboxBoolean') {
					manipulateCheckboxBooleanControl(dependenciesId, dependenciesGroupId, localDependenciesOption, local_perControls_cfg);
				}
				else {
					manipulateIntegerOrHexTextControl(dependenciesId, dependenciesGroupId, localDependenciesOption, local_perControls_cfg);
				}
			}
		} // if (typeof local_perControls_info[dependenciesId] !== 'undefined') {
		// to make the dependent UI valid, we must fresh its dependencies
		if (dependenciesGroupId === '') {
			S.eval('NUTOOL_PER.g_postRender_control.childrenByPropertyId["' + dependenciesId + '"].refresh();');
		}
		else {
			S.eval('NUTOOL_PER.g_postRender_control.childrenByPropertyId["' + dependenciesGroupId.slice(0, -1) + '"].childrenByPropertyId["' + dependenciesId + '"].refresh();');
		}
	} // for (i = 0, max = localDependenciesArray.length; i < max ; i = i + 1) {

	return valid;
}

function prepareFunctionalTest(id, local_perControls_info, local_perControls_cfg) {
	var i,
		j,
		k,
		m,
		n,
		max,
		maxJ,
		maxK,
		maxM,
		maxN,
		localEnum,
		localData,
		localArray,
		localControl,
		localFunctionalTest,
		ar = [],
		sp = [],
		sub = [],
		functionalTestId,
		functionalTestGroupId,
		functionalTestIdArray = [],
		parseIntBase,
		bFound;
		valid = false;

	if (typeof local_perControls_info[id].functionalTest === 'undefined') {
		valid = true;
		return valid;
	}

	localControl = local_perControls_info[id];
	if (localControl.functionalTest !== 'none' &&
		localControl.functionalTest !== '') {
		functionalTestIdArray = getPropertyNames(localControl.functionalTest);
	}

	valid = true;
	for (i = 0, max = functionalTestIdArray.length; i < max ; i = i + 1) {
		functionalTestId = functionalTestIdArray[i];
		if (typeof local_perControls_info[functionalTestId] !== 'undefined') {
			if (local_perControls_info[functionalTestId].groupId === '') {
				functionalTestGroupId = '';
			}
			else {
				functionalTestGroupId = local_perControls_info[functionalTestId].groupId + '_';
			}

			if (typeof localControl.functionalTest == 'object' &&
				typeof localControl.functionalTest[functionalTestId] !== 'undefined') {
				localFunctionalTest = localControl.functionalTest[functionalTestId];
			}
			else {
				localFunctionalTest = localControl.functionalTest;
			}
			if (Array.isArray(localFunctionalTest)) {
				if (local_perControls_info[functionalTestId].type === 'select') {
					manipulateSelectControl(functionalTestId, functionalTestGroupId, localFunctionalTest[0], local_perControls_cfg);
				}
				else if (local_perControls_info[functionalTestId].type === 'multipleselect') {
					manipulateMultipleSelectControl(functionalTestId, functionalTestGroupId, localFunctionalTest, local_perControls_cfg);
				}
				else if (local_perControls_info[functionalTestId].type === 'radio') {
					manipulateRadioControl(functionalTestId, functionalTestGroupId, local_perControls_info[functionalTestId].enum, localFunctionalTest[0], local_perControls_cfg);
				}
				else if (local_perControls_info[functionalTestId].type === 'checkbox') {
					manipulateCheckboxControl(functionalTestId, functionalTestGroupId, local_perControls_info[functionalTestId].enum, localFunctionalTest, local_perControls_cfg);
				}
				else if (local_perControls_info[functionalTestId].type === 'integer') {
					manipulateIntegerOrHexTextControl(functionalTestId, functionalTestGroupId, parseInt(localFunctionalTest[0], 10), local_perControls_cfg);
				}
				else if (local_perControls_info[functionalTestId].type === 'hextext') {
					manipulateIntegerOrHexTextControl(functionalTestId, functionalTestGroupId, parseInt(localFunctionalTest[0], 16), local_perControls_cfg);
				}
				else {
					showErrorMessage('something strange a1 in prepareFunctionalTest: ' + functionalTestId);
				}
			}
			else if (localFunctionalTest.toString().indexOf('|') !== -1 ||
					 localFunctionalTest.toString().indexOf('&') !== -1) {
				sp = localFunctionalTest.toString().split('|');
				ar = [];
				for (m = 0; m < sp.length; m++)
				{
					sub = sp[m].split('&');
					for (n = 0; n < sub.length; n++)
					{
						ar.push(sub[n].replace(/\(/g, '').replace(/\)/g, '').replace(/\!/g, '').replace(/\s/g, ''));
					}
				}
				if (local_perControls_info[functionalTestId].type === 'select') {
					manipulateSelectControl(functionalTestId, functionalTestGroupId, ar[0], local_perControls_cfg);
				}
				else if (local_perControls_info[functionalTestId].type === 'multipleselect') {
					manipulateMultipleSelectControl(functionalTestId, functionalTestGroupId, ar, local_perControls_cfg);
				}
				else if (local_perControls_info[functionalTestId].type === 'radio') {
					manipulateRadioControl(functionalTestId, functionalTestGroupId, local_perControls_info[functionalTestId].enum, ar[0], local_perControls_cfg);
				}
				else if (local_perControls_info[functionalTestId].type === 'checkbox') {
					manipulateCheckboxControl(functionalTestId, functionalTestGroupId, local_perControls_info[functionalTestId].enum, ar, local_perControls_cfg);
				}
				else {
					showErrorMessage('something strange b1 in prepareFunctionalTest: ' + functionalTestId);
				}
			}
			else if (localFunctionalTest.toString().indexOf('>') !== -1 ||
					 localFunctionalTest.toString().indexOf('<') !== -1 ||
					 localFunctionalTest.toString().indexOf('=') !== -1) {
				localData = localFunctionalTest.sliceAfterX('>').sliceAfterX('<').sliceAfterX('=').sliceAfterX('=');
				if (local_perControls_info[functionalTestId].type === 'integer' ||
					local_perControls_info[functionalTestId].type === 'hextext') {
					if (local_perControls_info[functionalTestId].type === 'integer') {
						parseIntBase = 10;
					}
					else {
						parseIntBase = 16;
					}
					if (localFunctionalTest.toString().indexOf('>') !== -1) {
						manipulateIntegerOrHexTextControl(functionalTestId, functionalTestGroupId, parseInt(localData, parseIntBase) + 1, local_perControls_cfg);
					}
					else if (localFunctionalTest.toString().indexOf('<') !== -1) {
						manipulateIntegerOrHexTextControl(functionalTestId, functionalTestGroupId, parseInt(localData, parseIntBase) - 1, local_perControls_cfg);
					}
					else { // localFunctionalTest.toString().indexOf('=')
						manipulateIntegerOrHexTextControl(functionalTestId, functionalTestGroupId, parseInt(localData, parseIntBase), local_perControls_cfg);
					}
				}
				else if (local_perControls_info[functionalTestId].type === 'select' ||
						 local_perControls_info[functionalTestId].type === 'radio') {
					bFound = false;
					parseIntBase = 16;
					for (m = 0; m < local_perControls_info[functionalTestId].enum.length; m++) {
						localEnum = local_perControls_info[functionalTestId].enum[m];
						if (localFunctionalTest.replace(/[0-9]/g, '') === '>' &&
							parseInt(localEnum, parseIntBase) > parseInt(localData, parseIntBase)) {
							bFound = true;
							break;
						}
						else if (localFunctionalTest.replace(/[0-9]/g, '') === '>=' &&
								 parseInt(localEnum, parseIntBase) >= parseInt(localData, parseIntBase)) {
							bFound = true;
							break;
						}
						else if (localFunctionalTest.replace(/[0-9]/g, '') === '<' &&
								 parseInt(localEnum, parseIntBase) < parseInt(localData, parseIntBase)) {
							bFound = true;
							break;
						}
						else if (localFunctionalTest.replace(/[0-9]/g, '') === '<=' &&
								 parseInt(localEnum, parseIntBase) <= parseInt(localData, parseIntBase)) {
							bFound = true;
							break;
						}
						else if ((localFunctionalTest.replace(/[0-9]/g, '') === '='  ||
								  localFunctionalTest.replace(/[0-9]/g, '') === '==' ||
								  localFunctionalTest.replace(/[0-9]/g, '') === '')&&
								 parseInt(localEnum, parseIntBase) == parseInt(localData, parseIntBase)) {
							bFound = true;
							break;
						}
					}
					if (bFound) {
						if (local_perControls_info[functionalTestId].type === 'select') {
							manipulateSelectControl(functionalTestId, functionalTestGroupId, localEnum, local_perControls_cfg);
						 }
						else if (local_perControls_info[functionalTestId].type === 'radio') {
							manipulateRadioControl(functionalTestId, functionalTestGroupId, local_perControls_info[functionalTestId].enum, localEnum, local_perControls_cfg);
						}
					}
					else {
						showErrorMessage('something strange b2 in prepareFunctionalTest: ' + functionalTestId);
					}
				}
			}
			else {
				if (local_perControls_info[functionalTestId].type === 'select') {
					manipulateSelectControl(functionalTestId, functionalTestGroupId, localFunctionalTest, local_perControls_cfg);
				}
				else if (local_perControls_info[functionalTestId].type === 'multipleselect') {
					manipulateMultipleSelectControl(functionalTestId, functionalTestGroupId, localFunctionalTest, local_perControls_cfg);
				}
				else if (local_perControls_info[functionalTestId].type === 'radio') {
					manipulateRadioControl(functionalTestId, functionalTestGroupId, local_perControls_info[functionalTestId].enum, localFunctionalTest, local_perControls_cfg);
				}
				else if (local_perControls_info[functionalTestId].type === 'checkbox') {
					manipulateCheckboxControl(functionalTestId, functionalTestGroupId, local_perControls_info[functionalTestId].enum, localFunctionalTest, local_perControls_cfg);
				}
				else if (local_perControls_info[functionalTestId].type === 'checkboxBoolean') {
					manipulateCheckboxBooleanControl(functionalTestId, functionalTestGroupId, localFunctionalTest, local_perControls_cfg);
				}
				else {
					manipulateIntegerOrHexTextControl(functionalTestId, functionalTestGroupId, localFunctionalTest, local_perControls_cfg);
				}
			}
		} // if (typeof local_perControls_info[functionalTestId] !== 'undefined') {
		// to make the dependent UI valid, we must fresh its functionalTest
		if (functionalTestGroupId === '') {
			S.eval('NUTOOL_PER.g_postRender_control.childrenByPropertyId["' + functionalTestId + '"].refresh();');
		}
		else {
			S.eval('NUTOOL_PER.g_postRender_control.childrenByPropertyId["' + functionalTestGroupId.slice(0, -1) + '"].childrenByPropertyId["' + functionalTestId + '"].refresh();');
		}
	} // for (i = 0, max = functionalTestIdArray.length; i < max ; i = i + 1) {

	return valid;
}

// manipulate controls
function manipulateSelectControl(id, groupId, data, local_perControls_cfg) {
	var dependenciesElement = S('#field1_sub' + g_field1SubIndex + ' select[name=' + groupId + id + ']');

	if (dependenciesElement.length) {
		ok(true, 'select or multipleselect control ' + id + ' found. Try to select ' + data);
	}
	else {
		showErrorMessage('select or multipleselect control ' + id + ' not found.');
		return;
	}

	if (typeof local_perControls_cfg[id] !== 'undefined') {
		if (local_perControls_cfg[id] !== data.toString()) {
			local_perControls_cfg[id] = data.toString();
			dependenciesElement[0].value = data;
			dependenciesElement.change();
			// for observers
			S.eval('NUTOOL_PER.g_postRender_f1("' + data + '", "' + id + '");');
		}
	}
	else {
		showErrorMessage('local_perControls_cfg did not have the id:' + id);
	}
}

function manipulateMultipleSelectControl(id, groupId, data, local_perControls_cfg) {
	var i,
		j,
		max,
		maxJ,
		local_data,
		dependenciesElement = S('#field1_sub' + g_field1SubIndex + ' select[name=' + groupId + id + ']');

	if (dependenciesElement.length) {
		ok(true, 'select or multipleselect control ' + id + ' found. Try to select ' + data);
	}
	else {
		showErrorMessage('select or multipleselect control ' + id + ' not found.');
		return;
	}

	if (typeof local_perControls_cfg[id] !== 'undefined') {
		if (local_perControls_cfg[id] !== data.toString()) {
			local_perControls_cfg[id] = data.toString();
			if (Array.isArray(data)) {
				for (j = 0; j < 100; j = j + 1) {
					if (typeof dependenciesElement[0].children[j] !== 'undefined') {
						dependenciesElement[0].children[j].selected = false;
					}
					else {
						break;
					}
				}
				for (i = 0, max = data.length; i < max ; i = i + 1) {
					local_data = data[i];
					for (j = 0; j < 100; j = j + 1) {
						if (typeof dependenciesElement[0].children[j] !== 'undefined') {
							if (dependenciesElement[0].children[j].value === local_data) {
								dependenciesElement[0].children[j].selected = true;
							}
						}
						else {
							break;
						}
					}
				}
			}
			else {
				dependenciesElement[0].value = data;
			}
			dependenciesElement.change();
			// for observers
			S.eval('NUTOOL_PER.g_postRender_f1("' + data + '", "' + id + '");');
		}
	}
	else {
		showErrorMessage('local_perControls_cfg did not have the id:' + id);
	}
}

function manipulateRadioControl(id, groupId, _enum, data, local_perControls_cfg) {
	var i,
		max,
		dependenciesElement = S('#field1_sub' + g_field1SubIndex + ' input:radio[name=' + groupId + id + ']');

	if (dependenciesElement.length) {
		ok(true, 'radio control ' + id + ' found. Try to choose ' + data);
	}
	else {
		showErrorMessage('radio control ' + id + ' not found.');
		return;
	}

	if (typeof local_perControls_cfg[id] !== 'undefined') {
		if (local_perControls_cfg[id] !== data.toString()) {
			local_perControls_cfg[id] = data.toString();
			if (typeof _enum !== 'undefined' && _enum.length > 0) {
				for (i = 0, max = _enum.length; i < max ; i = i + 1) {
					if (_enum[i] === data) {
						dependenciesElement[i].checked = true;
					}
					else {
						dependenciesElement[i].checked = false;
					}
				}
			}
			else {
				if (isTrue(data)) {
					dependenciesElement[0].checked = true;
				}
				else {
					dependenciesElement[0].checked = false;
				}
			}
			dependenciesElement.change();
			// for observers
			S.eval('NUTOOL_PER.g_postRender_f1("' + data + '", "' + id + '");');
		}
	}
	else {
		showErrorMessage('local_perControls_cfg did not have the id:' + id);
	}
}

function manipulateCheckboxControl(id, groupId, _enum, data, local_perControls_cfg) {
	var i,
		max,
		dependenciesElement = S('#field1_sub' + g_field1SubIndex + ' div[name=' + groupId + id + ']');

	if (dependenciesElement.length) {
		ok(true, 'checkbox control ' + id + ' found. Try to check ' + data);
	}
	else {
		showErrorMessage('checkbox control ' + id + ' not found.');
		return;
	}

	if (typeof local_perControls_cfg[id] !== 'undefined') {
		if (local_perControls_cfg[id] !== data.toString()) {
			local_perControls_cfg[id] = data.toString();
			if (typeof _enum !== 'undefined' && _enum.length > 0) {
				for (i = 0, max = _enum.length; i < max ; i = i + 1) {
					if (data.toString().indexOf(_enum[i]) !== -1) {
						dependenciesElement[i].children[0].children[0].checked = true;
					}
					else {
						dependenciesElement[i].children[0].children[0].checked = false;
					}
				}
			}
			else {
				if (isTrue(data)) {
					dependenciesElement[0].children[0].children[0].checked = true;
				}
				else {
					dependenciesElement[0].children[0].children[0].checked = false;
				}
			}
			// for observers
			S.eval('NUTOOL_PER.g_postRender_f1("' + data + '", "' + id + '");');
		}
	}
	else {
		showErrorMessage('local_perControls_cfg did not have the id:' + id);
	}

}

function manipulateCheckboxBooleanControl(id, groupId, data, local_perControls_cfg) {
	var i,
		max,
		dependenciesElement = S('#field1_sub' + g_field1SubIndex + ' div[name=' + groupId + id + ']');

	if (dependenciesElement.length) {
		ok(true, 'checkbox control ' + id + ' found. Try to check ' + data);
	}
	else {
		showErrorMessage('checkbox control ' + id + ' not found.');
		return;
	}

	if (typeof local_perControls_cfg[id] !== 'undefined') {
		if (local_perControls_cfg[id] !== data.toString()) {
			local_perControls_cfg[id] = data.toString();
			if (data.toString().toLowerCase() === 'true') {
				dependenciesElement[0].children[0].children[0].checked = true;
			}
			else {
				dependenciesElement[0].children[0].children[0].checked = false;
			}
			dependenciesElement.change();
			// for observers
			S.eval('NUTOOL_PER.g_postRender_f1("' + data + '", "' + id + '");');
		}
	}
	else {
		showErrorMessage('local_perControls_cfg did not have the id:' + id);
	}
}

function manipulateIntegerOrHexTextControl(id, groupId, data, local_perControls_cfg) {
	var dependenciesElement = S('#field1_sub' + g_field1SubIndex + ' input[name=' + groupId + id + ']');

	if (dependenciesElement.length) {
		ok(true, 'integer or hexText control ' + id + ' found. Try to input ' + data);
	}
	else {
		showErrorMessage('integer or hexText control ' + id + ' not found.');
		return;
	}

	if (typeof local_perControls_cfg[id] !== 'undefined') {
		if (local_perControls_cfg[id] !== data.toString()) {
			local_perControls_cfg[id] = data.toString();
			dependenciesElement[0].value = data;
			dependenciesElement.change();
			// for observers
			S.eval('NUTOOL_PER.g_postRender_f1("' + data + '", "' + id + '");');
		}
	}
	else {
		showErrorMessage('local_perControls_cfg did not have the id:' + id);
	}
}

function sendAjaxRequest(fileName, body) {
	$.ajax({
		url: 'http://127.0.0.1:4560/' + fileName,
		crossDomain: false,
		data: body,
		type: 'POST',
		dataType: "json",
		contentType: 'application/json; charset=UTF-8',
		jsonCallback: 'callback',
		success: function(data) {
			ok(true, 'Node.js fs.writeFile ' + fileName + ' successfully');
		},
		error: function(xhr, status, error) {
			var errorMessage = xhr.status;
			showErrorMessage('Node.js failed to fs.writeFile ' + fileName + '/' + errorMessage);
		}
	});
}

function sendAjaxRequestToPythonApp(fileName, body) {
	$.ajax({
		url: 'http://127.0.0.1:8081/',
		crossDomain: false,
		data: body,
		type: 'POST',
		dataType: "text",
		contentType: 'application/json; charset=UTF-8',
		jsonCallback: 'callback',
		success: function(data) {
			ok(true, fileName + ' notified the PythonApp of the work finish successfully');
		},
		error: function(xhr, status, error) {
			var errorMessage = xhr.status;
			showErrorMessage(fileName + ' failed to notify the PythonApp/' + errorMessage);
		}
	});
}

var g_field1SubIndex = 0;
(function mainTest() {
	var x,
		maxX,
		targetChips = [
			"DEMO/NUC122LD2AN(LQFP48)"//"DEMO/NUC122LD2AN(LQFP48)"//"M251/M252KG6AE(LQFP128)"
		],
		targetNodes = [
			// 'test'
		],
		chipSeries,
		mcu,
		oldChipType = "",
		currentIndexForNode = 0,
		bEnableClickAllofTheNodes = true,
		bSendAjaxRequestOnce = true,
		sendAjaxRequestData = "",
		tagCheckingTableData = [],
		tagRegMappingTableData = [];

	for (x = 0, maxX = targetChips.length; x < maxX; x = x + 1) {
		if (bEnableClickAllofTheNodes) {
			test("Click all of the Peripheral Functions", function () {
				var i,
					j,
					k,
					m,
					max,
					maxJ,
					maxK,
					maxM,
					forBase = 10,
					forBaseIndex = -1,
					TreeNodeId,
					TreeNodeIdArray = [],
					currentDate,
					dateTime,
					partNumber_package,
					functionalTestMode = 'autoTestWithWebServer', //loadPeripheralTestJS autoTestWithWebServer localTest
					local_perControls,
					local_perControls_info,
					local_perControls_cfg,
					local_generatedCodeFromPerString = [],
					localControlUsingEnum = ['select', 'radio', 'checkbox', 'multipleselect'],
					localControl,
					localId,
					localGroupId,
					localDefault,
					localEnum,
					localData,
					localDataArray = [],
					localNuvotonWords = [],
					localNuvotonUnitWords = [],
					localNuvotonDictionaries = [],
					localObject,
					localQueryParams = {},
					localQueryEnglishWords = {},
					localQueryNuvotonWords = {},
					dataSentToPythonApp = 'running';

				// get arguments from the external application
				localQueryParams = JSON.parse($.ajax({ url: 'FunctionalTesting/headerGenerator.txt', async: false }).responseText.replace(/\r/g, ""));
				localQueryEnglishWords = JSON.parse($.ajax({ url: 'FunctionalTesting/EnglishWords.json', async: false }).responseText.replace(/\r/g, ""));
				localQueryNuvotonWords = JSON.parse($.ajax({ url: 'FunctionalTesting/NuvotonWords.json', async: false }).responseText.replace(/\r/g, ""));
				// prepare localNuvotonWords
				localNuvotonDictionaries = getPropertyNames(localQueryNuvotonWords);
				for (i = 0, max = localNuvotonDictionaries.length; i < max ; i = i + 1) {
					if (localNuvotonDictionaries[i] !== 'rule' && localQueryNuvotonWords[localNuvotonDictionaries[i]].length > 0) {
						localNuvotonWords = localNuvotonWords.concat(localQueryNuvotonWords[localNuvotonDictionaries[i]]);
					}
					if (localNuvotonDictionaries[i] === 'unit' && localQueryNuvotonWords[localNuvotonDictionaries[i]].length > 0) {
						localNuvotonUnitWords = localNuvotonUnitWords.concat(localQueryNuvotonWords[localNuvotonDictionaries[i]]);
					}
				}
				localNuvotonWords = localNuvotonWords.map(function (value, index) { return value.toLowerCase(); });
				localNuvotonUnitWords = localNuvotonUnitWords.map(function (value, index) { return value.toLowerCase(); });

				if (typeof localQueryParams.fileName !== 'undefined') {
					targetNodes = [];
					targetNodes.push(localQueryParams.fileName.toString().toUpperCase());
				}
				// decide chipSeries and mcu
				if (functionalTestMode === 'autoTestWithWebServer' &&
					typeof localQueryParams.chipName !== 'undefined') {
					mcu = localQueryParams.chipName.toString().toUpperCase();
					oldChipType = loadCorrespondingJS(mcu, oldChipType);
					chipSeries = S.eval('NUTOOL_PER.chipTypeToChipSeries("' + oldChipType +'");');
					for (i = 0, max = NUTOOL_PER.g_cfg_chips.length; i < max; i += 1) {
						if (NUTOOL_PER.g_cfg_chips[i].name === mcu) {
							mcu = NUTOOL_PER.g_cfg_chips[i].name + '(' + NUTOOL_PER.g_cfg_chips[i].pkg + ')';
							break;
						}
					}
				}
				else {
					chipSeries = targetChips[currentIndexForNode];
					chipSeries = chipSeries.slice(0, chipSeries.indexOf('/'));

					mcu = targetChips[currentIndexForNode];
					mcu = mcu.slice(mcu.indexOf('/') + 1);

					oldChipType = loadCorrespondingJS(mcu, oldChipType);
				}

				if (S("#ChipTypeSelect_Peripheral").val() !== chipSeries) {
					S.eval('$("#ChipTypeSelect_Peripheral").val("' + chipSeries + '").change();');
				}
				if (S("#MCUselect_Peripheral").val() !== mcu) {
					S.eval('$("#MCUselect_Peripheral").val("' + mcu + '").change();');
				}

				// decide Test Time
				currentDate = new Date();
				dateTime = "Test Time: " + currentDate.getDate() + "/" + (currentDate.getMonth() + 1) + "/" + currentDate.getFullYear() + " at " + currentDate.getHours() + ":" + currentDate.getMinutes() + ":" + currentDate.getSeconds();

				// decide the total pin number
				partNumber_package = S("#MCUselect_Peripheral").val();

				ok(true, 'Chip Series: ' + S("#ChipTypeSelect_Peripheral").val() + ' Part No: ' + partNumber_package + ' ' + dateTime);

				S.eval('NUTOOL_PER.g_bFunctionalTesting = true;');
				if (functionalTestMode === 'loadPeripheralTestJS') {
					for (i = 0, max = S('#perFunctionTree').children().children().length; i < max ; i = i + 1) {
						// click the modules
						TreeNodeId = S('#perFunctionTree').children().children().eq(i)[0].id;
						S.eval('$("#perFunctionTree").jstree("check_node", $("#' + TreeNodeId + '"));');
						loadPeripheralTestJS(chipSeries, TreeNodeId.slicePriorToX('_PeripheralConfigure'));
					}
				}
				else if (functionalTestMode === 'autoTestWithWebServer') {
					for (k = 0, maxK = S('#perFunctionTree').children().children().length; k < maxK ; k = k + 1) {
						TreeNodeId = S('#perFunctionTree').children().children().eq(k)[0].id.slicePriorToX('_PeripheralConfigure');
						maxM = S('#perFunctionTree').children().children().eq(k).children().eq(2).children().length;
						if (maxM === 0 &&
							(targetNodes.indexOf(TreeNodeId.toUpperCase()) !== -1 || targetNodes.length === 0)) {
							TreeNodeIdArray.push(TreeNodeId);
						}
						for (m = 0; m < maxM; m = m + 1) {
							TreeNodeId = S('#perFunctionTree').children().children().eq(k).children().eq(2).children().eq(m)[0].id.slicePriorToX('_PeripheralConfigure');
							if (targetNodes.indexOf(TreeNodeId.toUpperCase()) !== -1 || targetNodes.length === 0) {
								TreeNodeIdArray.push(TreeNodeId);
							}
						}
					}
					if (TreeNodeIdArray.length === 0) {
						sendAjaxRequestToPythonApp("the tester", "shutdown");
					}
					for (k = 0, maxK = TreeNodeIdArray.length; k < maxK ; k = k + 1) {
						// click the modules
						TreeNodeId = TreeNodeIdArray[k];
						if (TreeNodeId.indexOf('_') !== -1) {
							S.eval('$("#perFunctionTree").jstree("open_node", $("#' + TreeNodeId.slicePriorToX('_') + '_PeripheralConfigure"));');
						}
						S.eval('$("#perFunctionTree").jstree("check_node", $("#' + TreeNodeId + '_PeripheralConfigure"));');
						while(!S.eval('NUTOOL_PER.checkAlpacaReady();'));
						S.eval('NUTOOL_PER.g_perFunctionString = "periph_conf.h";');
						local_perControls = S.eval('NUTOOL_PER.getg_perControls();');
						local_perControls_info = {};
						local_perControls_cfg = {};
						localData = -1;
						for (m = 0, maxM = local_perControls[TreeNodeId].length; m < maxM; m = m + 1) {
							if (typeof local_perControls[TreeNodeId][m].id !== 'undefined') {
								localId = local_perControls[TreeNodeId][m].id;
								local_perControls_info[localId] = {};
								local_perControls_info[localId].type = local_perControls[TreeNodeId][m].type;
								if (typeof local_perControls[TreeNodeId][m].enum !== 'undefined' &&
									local_perControls[TreeNodeId][m].enum !== 'none' &&
									local_perControls[TreeNodeId][m].enum !== '') {
									local_perControls_info[localId].enum = local_perControls[TreeNodeId][m].enum;
								}
								if (typeof local_perControls[TreeNodeId][m].dependencies !== 'undefined' &&
									local_perControls[TreeNodeId][m].dependencies !== 'none' &&
									local_perControls[TreeNodeId][m].dependencies !== '') {
									local_perControls_info[localId].dependencies = local_perControls[TreeNodeId][m].dependencies;
								}
								if (typeof local_perControls[TreeNodeId][m].dependenciesOption !== 'undefined' &&
									local_perControls[TreeNodeId][m].dependenciesOption !== 'none' &&
									local_perControls[TreeNodeId][m].dependenciesOption !== '') {
									local_perControls_info[localId].dependenciesOption = local_perControls[TreeNodeId][m].dependenciesOption;
								}
								if (typeof local_perControls[TreeNodeId][m].functionalTest !== 'undefined' &&
									local_perControls[TreeNodeId][m].functionalTest !== 'none' &&
									local_perControls[TreeNodeId][m].functionalTest !== '') {
									local_perControls_info[localId].functionalTest = local_perControls[TreeNodeId][m].functionalTest;
								}
								local_perControls_info[localId].groupId = '';
								if (typeof local_perControls[TreeNodeId][m].groupId !== 'undefined' &&
									local_perControls[TreeNodeId][m].groupId !== 'none' &&
									local_perControls[TreeNodeId][m].groupId !== '') {
									local_perControls_info[localId].groupId = local_perControls[TreeNodeId][m].groupId;
								}
								if (typeof local_perControls[TreeNodeId][m].data !== 'undefined') {
									local_perControls_cfg[localId] = local_perControls[TreeNodeId][m].data.toString();
								}
								else if (typeof local_perControls[TreeNodeId][m].default !== 'undefined') {
									local_perControls_cfg[localId] = local_perControls[TreeNodeId][m].default.toString();
								}
								else {
									local_perControls_cfg[localId] = '';
								}
								if (typeof localQueryParams.tagId !== 'undefined' &&
									localQueryParams.tagId === localId) {
									localData = m;
								}
							}
						}
						// decide how many tags to run
						if (typeof localQueryParams.server !== 'undefined' &&
							localQueryParams.server !== '0' &&
							localQueryParams.server !== 'd0') {
							forBaseIndex = parseInt(localQueryParams.forBaseIndex, 10);
							if (localData !== -1) {
								m = localData;
								forBaseIndex = Math.floor(m/forBase);
							}
							else {
								m = forBase * forBaseIndex;
							}
							maxM = (forBase * (forBaseIndex + 1));
							if (maxM >= local_perControls[TreeNodeId].length) {
								maxM = local_perControls[TreeNodeId].length;
								dataSentToPythonApp = 'shutdown';
							}
							else if (localQueryParams.runNumber === '1') {
								if (m === 0) {
									maxM = m + 2;
								}
								else {
									maxM = m + 1;
								}
								dataSentToPythonApp = 'shutdown';
							}
							else {
								dataSentToPythonApp = 'forBaseIndex(' + forBaseIndex + ')';
							}
						}
						else if (localData !== -1) {
							m = localData;
							maxM = localData + 1;
							if (typeof localQueryParams.runNumber !== 'undefined' &&
								localQueryParams.runNumber !== '-1') {
								maxM = m + parseInt(localQueryParams.runNumber, 10);
							}
							if (maxM > local_perControls[TreeNodeId].length) {
								maxM = local_perControls[TreeNodeId].length;
							}
						}
						else if (typeof localQueryParams.runNumber !== 'undefined' &&
							localQueryParams.runNumber !== '-1') {
							m = 0;
							maxM = parseInt(localQueryParams.runNumber, 10);
							if (maxM > local_perControls[TreeNodeId].length) {
								maxM = local_perControls[TreeNodeId].length;
							}
						}
						else if (forBaseIndex !== -1) {
							m = forBase * forBaseIndex;
							maxM = (forBase * (forBaseIndex + 1));
							if (maxM > local_perControls[TreeNodeId].length) {
								maxM = local_perControls[TreeNodeId].length;
							}
							if ((m > local_perControls[TreeNodeId].length - 1) ||
								(maxM > local_perControls[TreeNodeId].length)) {
									alert('exceeded the range of perControls. TreeNodeId:' + TreeNodeId + '/m:' + m + '/maxM:' + maxM + '/local_perControls[TreeNodeId].length:' + local_perControls[TreeNodeId].length);
									break;
							}
						}
						else {
							m = 0;
							maxM = local_perControls[TreeNodeId].length;
						}
						sendAjaxRequestData = '';
						tagCheckingTableData = [];
						tagRegMappingTableData = [];
						for (; m < maxM; m = m + 1) {
							localControl = local_perControls[TreeNodeId][m];
							if (typeof localControl.id !== 'undefined' &&
								localControl.type !== 'hidden') {
								localId = localControl.id;
								localGroupId = '';
								if (!makeDependencyValid(localId, local_perControls_info, local_perControls_cfg)) {
									//showErrorMessage('something strange o1 in makeDependencyValid: ' + localId);
								}
								if (!prepareFunctionalTest(localId, local_perControls_info, local_perControls_cfg)) {
									//showErrorMessage('something strange o1 in prepareFunctionalTest: ' + localId);
								}
								if (typeof localControl.groupId !== 'undefined' &&
									localControl.groupId !== 'none' &&
									localControl.groupId !== '') {
									localGroupId = localControl.groupId + '_';
								}
								// checking tags
								if (typeof localControl.label !== 'undefined') {
									localData = checkWordsInTag(localId, 'label', localControl.label, localQueryEnglishWords, localNuvotonWords, localNuvotonUnitWords);
									if (localData !== "" && tagCheckingTableData.indexOf(localData) === -1) {
										tagCheckingTableData.push(localData);
									}
								}
								if (typeof localControl.helper !== 'undefined') {
									localData = checkWordsInTag(localId, 'helper', localControl.helper, localQueryEnglishWords, localNuvotonWords, localNuvotonUnitWords);
									if (localData !== "" && tagCheckingTableData.indexOf(localData) === -1) {
										tagCheckingTableData.push(localData);
									}
								}
								if (typeof localControl.optionLabels !== 'undefined') {
									for (i = 0, max = localControl.optionLabels.length; i < max ; i = i + 1) {
										localData = checkWordsInTag(localId, 'optionLabels', localControl.optionLabels[i], localQueryEnglishWords, localNuvotonWords, localNuvotonUnitWords);
										if (localData !== "" && tagCheckingTableData.indexOf(localData) === -1) {
											tagCheckingTableData.push(localData);
										}
									}
								}
								// check default in tags
								if (typeof localControl.default === 'undefined' ||
									localControl.default === 'none' ||
									localControl.default === "") {
									localData = localId + ',default,missing\n';
									tagCheckingTableData.push(localData);
								}
								else {
									localDefault = localControl.default;
									if (typeof localControl.enum !== 'undefined' &&
										localControl.enum !== 'none' &&
										localControl.enum !== '') {
										localEnum = localControl.enum;
										if (Array.isArray(localDefault)) {
											for (i = 0, max = localDefault.length; i < max ; i = i + 1) {
												if (Array.isArray(localEnum) && localEnum.indexOf(localDefault[i]) == -1 &&
													localDefault[i] !== '' && localDefault[i] !== '0' &&
													(localEnum.length !==1 || !isTrue(localEnum[0]))) {
													localData = localId + ',default,' + localDefault[i] + ' not found in enum\n';
													tagCheckingTableData.push(localData);
												}
												else if (!Array.isArray(localEnum) && localEnum != localDefault[i] &&
													localDefault[i] !== '' && localDefault[i] !== '0') {
													localData = localId + ',default,' + localDefault[i] + ' not found in enum\n';
													tagCheckingTableData.push(localData);
												}
											}
										}
										else {
											if (Array.isArray(localEnum) && localEnum.indexOf(localDefault) == -1 &&
												localDefault !== '0' &&
												(localEnum.length !==1 || !isTrue(localEnum[0]))) {
												localData = localId + ',default,' + localDefault + ' not found in enum\n';
												tagCheckingTableData.push(localData);
											}
											else if (!Array.isArray(localEnum) && localEnum != localDefault &&
												localDefault !== '0') {
												localData = localId + ',default,' + localDefault + ' not found in enum\n';
												tagCheckingTableData.push(localData);
											}
										}
									}
									if (localControl.type === 'integer' ||
										localControl.type === 'hextext') {
										if (typeof localControl.minimum === 'undefined') {
											localData = localId + ',minimum,missing\n';
											tagCheckingTableData.push(localData);
										}
										else if (parseInt(localDefault, 16) < parseInt(localControl.minimum, 16)) {
											localData = localId + ',default,lower than minimum\n';
											tagCheckingTableData.push(localData);
										}
										if (typeof localControl.maximum === 'undefined') {
											localData = localId + ',maximum,missing';
											tagCheckingTableData.push(localData);
										}
										else if (parseInt(localDefault, 16) > parseInt(localControl.maximum, 16)) {
											localData = localId + ',default,higher than maximum\n';
											tagCheckingTableData.push(localData);
										}
									}
									// check data in tags
									if (typeof localControl.data === 'undefined' ||
										localControl.data === 'none' ||
										localControl.data === "") {
										localData = localId + ',data,missing\n';
										tagCheckingTableData.push(localData);
									}
									else if (!isObject(localDefault) &&
											localControl.data !== localDefault &&
											(localControl.data !== 0 || localDefault !== false)) {
										localData = localId + ',data,should be the same with the default\n';
										tagCheckingTableData.push(localData);
									}
								}
								// manipulate tags
								if (localControlUsingEnum.indexOf(localControl.type) !== -1) {
									if (typeof localControl.enum !== 'undefined') {
										localEnum = localControl.enum;
										for (i = 0, max = localEnum.length; i < max ; i = i + 1) {
											if (localControl.type === 'select') {
												manipulateSelectControl(localId, localGroupId, localEnum[i], local_perControls_cfg);
											}
											else if (localControl.type === 'multipleselect') {
												manipulateMultipleSelectControl(localId, localGroupId, localEnum[i], local_perControls_cfg);
											}
											else if (localControl.type === 'radio') {
												manipulateRadioControl(localId, localGroupId, localEnum, localEnum[i], local_perControls_cfg);
											}
											else if (localControl.type === 'checkbox') {
												manipulateCheckboxControl(localId, localGroupId, localEnum, localEnum[i], local_perControls_cfg);
											}
											localObject = {};
											localObject[TreeNodeId] = local_perControls_cfg;
											local_generatedCodeFromPerString = "//PeripheralFunctionData:" + JSON.stringify(localObject) + "\n\n";
											S.eval('$("#field1_sub' + g_field1SubIndex + '").alpaca("get").form.getButtonEl("submit").click();');
											S.eval('NUTOOL_PER.concatenate_generated_code();');
											local_generatedCodeFromPerString += S.eval('NUTOOL_PER.getg_generatedCodeFromPerString();');
											if (bSendAjaxRequestOnce) {
												sendAjaxRequestData += '//fileName:' + TreeNodeId + '&' + localId + '&' + localEnum[i] + '.h\n';
												sendAjaxRequestData += local_generatedCodeFromPerString + '\n';
												localData = localId + ',' + localEnum[i] + '\n';
												if (tagRegMappingTableData.indexOf(localData) === -1) {
													tagRegMappingTableData.push(localData);
												}
											}
											else {
												sendAjaxRequest(TreeNodeId + '&' + localId + '&' + localEnum[i] + '.h', local_generatedCodeFromPerString);
											}
										}
									}
									else {
										if (typeof localControl.default !== 'undefined') {
											localData = localControl.default;
										}
										else {
											localData = localControl.data;
										}
										if (localData.toString().toLowerCase() === 'false' || localData.toString().toLowerCase() === 'true') {
											localData = 'true';
										}
										if (localData.toString() === '0' || localData.toString() === '1') {
											localData = '1';
										}
										if (localControl.type === 'select') {
											manipulateSelectControl(localId, localGroupId, localData, local_perControls_cfg);
										}
										else if (localControl.type === 'multipleselect') {
											manipulateMultipleSelectControl(localId, localGroupId, localData, local_perControls_cfg);
										}
										else if (localControl.type === 'radio') {
											manipulateRadioControl(localId, localGroupId, [], localData, local_perControls_cfg);
										}
										else if (localControl.type === 'checkbox') {
											manipulateCheckboxControl(localId, localGroupId, [], localData, local_perControls_cfg);
										}
										localObject = {};
										localObject[TreeNodeId] = local_perControls_cfg;
										local_generatedCodeFromPerString = "//PeripheralFunctionData:" + JSON.stringify(localObject) + "\n\n";
										S.eval('$("#field1_sub' + g_field1SubIndex + '").alpaca("get").form.getButtonEl("submit").click();');
										S.eval('NUTOOL_PER.concatenate_generated_code();');
										local_generatedCodeFromPerString += S.eval('NUTOOL_PER.getg_generatedCodeFromPerString();');
										if (bSendAjaxRequestOnce) {
											sendAjaxRequestData += '//fileName:' + TreeNodeId + '&' + localId + '&' + localControl.data + '.h\n';
											sendAjaxRequestData += local_generatedCodeFromPerString + '\n';
											localData = localId + ',' + localControl.data + '\n';
											if (tagRegMappingTableData.indexOf(localData) === -1) {
												tagRegMappingTableData.push(localData);
											}
										}
										else {
											sendAjaxRequest(TreeNodeId + '&' + localId + '&' + localControl.data + '.h', local_generatedCodeFromPerString);
										}
									}
								}
								else {
									if (localControl.type === 'checkboxBoolean') {
										manipulateCheckboxBooleanControl(localId, localGroupId, true, local_perControls_cfg);
										localObject = {};
										localObject[TreeNodeId] = local_perControls_cfg;
										local_generatedCodeFromPerString = "//PeripheralFunctionData:" + JSON.stringify(localObject) + "\n\n";
										S.eval('$("#field1_sub' + g_field1SubIndex + '").alpaca("get").form.getButtonEl("submit").click();');
										S.eval('NUTOOL_PER.concatenate_generated_code();');
										local_generatedCodeFromPerString += S.eval('NUTOOL_PER.getg_generatedCodeFromPerString();');
										if (bSendAjaxRequestOnce) {
											sendAjaxRequestData += '//fileName:' + TreeNodeId + '&' + localId + '&true.h\n';
											sendAjaxRequestData += local_generatedCodeFromPerString + '\n';
											localData = localId + ',true\n';
											if (tagRegMappingTableData.indexOf(localData) === -1) {
												tagRegMappingTableData.push(localData);
											}
										}
										else {
											sendAjaxRequest(TreeNodeId + '&' + localId + '&true.h', local_generatedCodeFromPerString);
										}
										manipulateCheckboxBooleanControl(localId, localGroupId, false, local_perControls_cfg);
										localObject = {};
										localObject[TreeNodeId] = local_perControls_cfg;
										local_generatedCodeFromPerString = "//PeripheralFunctionData:" + JSON.stringify(localObject) + "\n\n";
										S.eval('$("#field1_sub' + g_field1SubIndex + '").alpaca("get").form.getButtonEl("submit").click();');
										S.eval('NUTOOL_PER.concatenate_generated_code();');
										local_generatedCodeFromPerString += S.eval('NUTOOL_PER.getg_generatedCodeFromPerString();');
										if (bSendAjaxRequestOnce) {
											sendAjaxRequestData += '//fileName:' + TreeNodeId + '&' + localId + '&false.h\n';
											sendAjaxRequestData += local_generatedCodeFromPerString + '\n';
											localData = localId + ',false\n';
											if (tagRegMappingTableData.indexOf(localData) === -1) {
												tagRegMappingTableData.push(localData);
											}
										}
										else {
											sendAjaxRequest(TreeNodeId + '&' + localId + '&false.h', local_generatedCodeFromPerString);
										}
									}
									else if (localControl.type === 'integer' ||
											 localControl.type === 'hextext') {
										localDataArray = [];
										if (typeof localControl.default !== 'undefined' &&
											localControl.default !== 'none' &&
											localControl.default !== '') {
											localDataArray.push(localControl.default);
										}
										if (typeof localControl.minimum !== 'undefined' &&
											localControl.minimum !== 'none' &&
											localControl.minimum !== '') {
											localDataArray.push(localControl.minimum);
										}
										if (typeof localControl.maximum !== 'undefined' &&
											localControl.maximum !== 'none' &&
											localControl.maximum !== '') {
											localDataArray.push(localControl.maximum);
										}
										if (localDataArray.length === 0) {
											localDataArray.push(0);
										}
										for (i = 0, max = localDataArray.length; i < max ; i = i + 1) {
											localData = localDataArray[i];
											manipulateIntegerOrHexTextControl(localId, localGroupId, localData, local_perControls_cfg);
											localObject = {};
											localObject[TreeNodeId] = local_perControls_cfg;
											local_generatedCodeFromPerString = "//PeripheralFunctionData:" + JSON.stringify(localObject) + "\n\n";
											S.eval('$("#field1_sub' + g_field1SubIndex + '").alpaca("get").form.getButtonEl("submit").click();');
											S.eval('NUTOOL_PER.concatenate_generated_code();');
											local_generatedCodeFromPerString += S.eval('NUTOOL_PER.getg_generatedCodeFromPerString();');
											if (localControl.type === 'hextext' &&
												localData.indexOf('0x') === -1) {
												localData = '0x' + localData;
											 }
											if (bSendAjaxRequestOnce) {
												sendAjaxRequestData += '//fileName:' + TreeNodeId + '&' + localId + '&' + localData + '.h\n';
												sendAjaxRequestData += local_generatedCodeFromPerString + '\n';
												localData = localId + ',' + localData + '\n';
												if (tagRegMappingTableData.indexOf(localData) === -1) {
													tagRegMappingTableData.push(localData);
												}
											}
											else {
												sendAjaxRequest(TreeNodeId + '&' + localId + '&' + localData + '.h', local_generatedCodeFromPerString);
											}
										}
									} //else if (localControl.type === 'integer' ||
								} //else {
							} // if (typeof localControl.id !== 'undefined') {
						} //for (m = 0, maxM = local_perControls[TreeNodeId].length; m < maxM ; m = m + 1) {
						if (bSendAjaxRequestOnce) {
							if (tagCheckingTableData.length !== 0) {
								sendAjaxRequestData += '//fileName:TagCheckingTable_' + currentDate.getFullYear() + (((currentDate.getMonth() + 1) < 10)?"0":"") + (currentDate.getMonth() + 1) + ((currentDate.getDate() < 10)?"0":"") + currentDate.getDate() + ((currentDate.getHours() < 10)?"0":"") + currentDate.getHours() + ((currentDate.getMinutes() < 10)?"0":"") + currentDate.getMinutes() + ((currentDate.getSeconds() < 10)?"0":"") + currentDate.getSeconds() + '.csv\n';
								for (i = 0, max = tagCheckingTableData.length; i < max ; i = i + 1) {
									sendAjaxRequestData += tagCheckingTableData[i];
								}
							}
							if (tagRegMappingTableData.length !== 0) {
								sendAjaxRequestData += '//fileName:TagRegMappingTable_' + currentDate.getFullYear() + (((currentDate.getMonth() + 1) < 10)?"0":"") + (currentDate.getMonth() + 1) + ((currentDate.getDate() < 10)?"0":"") + currentDate.getDate() + ((currentDate.getHours() < 10)?"0":"") + currentDate.getHours() + ((currentDate.getMinutes() < 10)?"0":"") + currentDate.getMinutes() + ((currentDate.getSeconds() < 10)?"0":"") + currentDate.getSeconds() + '.csv\n';
								for (i = 0, max = tagRegMappingTableData.length; i < max ; i = i + 1) {
									sendAjaxRequestData += tagRegMappingTableData[i];
								}
							}
							sendAjaxRequest('AllData.h', sendAjaxRequestData);
						}
						if (typeof localQueryParams.server !== 'undefined') {
							localData = '';
							if (g_showErrorMessage) {
								localData = 'showErrorMessage;';
							}
							if (localQueryParams.server !== '0' &&
								localQueryParams.server !== 'd0') {
								sendAjaxRequestToPythonApp(TreeNodeId, localData + dataSentToPythonApp);
							}
							else {
								sendAjaxRequestToPythonApp(TreeNodeId, localData + 'shutdown');
							}
							break;
						}
						g_field1SubIndex = g_field1SubIndex + 1;
						//S.eval('$("#perFunctionTree").jstree("uncheck_node", $("#' + TreeNodeId + '_PeripheralConfigure"));');
					} //for (k = 0, maxK = TreeNodeIdArray.length; k < maxK ; k = k + 1) {
				} //else if (functionalTestMode === 'autoTestWithWebServer') {
				else if (functionalTestMode === 'localTest') {
					TreeNodeId = "Test";
					S.eval('$("#perFunctionTree").jstree("check_node", $("#' + TreeNodeId + '_PeripheralConfigure"));');

					var dependenciesElement = S('#field1_sub' + g_field1SubIndex + ' input:radio[name=sc0_submode_select]'),
						dependenciesElement1 = S('#field1_sub' + g_field1SubIndex + ' div[name=Group_SC_gr4_sc0_interrupt_en]'),
						dependenciesCheckedElement = S('#field1_sub' + g_field1SubIndex + ' input:radio[name=sc0_submode_select]:checked');

					equal(dependenciesElement.length, 2, 'control sc0_submode_select found.');
					equal(dependenciesCheckedElement.length, 1, "control sc0_submode_select Checked found.");
					equal(dependenciesCheckedElement.val(), "NUCODEGEN_SC0_SUBMODE_SC", 'control sc0_submode_select value NUCODEGEN_SC0_SUBMODE_SC checked.');
					dependenciesElement[0].checked = false;
					dependenciesElement[1].checked = true;
					dependenciesElement.change();
					dependenciesCheckedElement = S('#field1_sub' + g_field1SubIndex + ' input:radio[name=sc0_submode_select]:checked');
					equal(dependenciesCheckedElement.length, 1, "control sc0_submode_select Checked found.");
					equal(dependenciesCheckedElement.val(), "NUCODEGEN_SC0_SUBMODE_SCUART", 'control sc0_submode_select value NUCODEGEN_SC0_SUBMODE_SCUART checked.');

					equal(dependenciesElement1.length, 1, 'control sc0_interrupt_en found.');
					dependenciesElement1[0].children[0].children[0].checked= true;
					dependenciesElement1.change();
					S.wait(500, function() {
						S.eval('$("#field1_sub' + g_field1SubIndex + '").alpaca("get").form.getButtonEl("submit").click();');
					});
				}
				// // // load the relevant content js file
				// loadOrRemoveJsCssFile('NUC_' + chipType + '_Content.js', "js", "remove");
				// jump to the next chip
				currentIndexForNode = currentIndexForNode + 1;
			});
		}
	}
}(NUTOOL_PER, this));