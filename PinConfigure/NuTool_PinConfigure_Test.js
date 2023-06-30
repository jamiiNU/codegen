// main code of NuPinConfigureTool
// the sole global variable denoted by capital letters
var NUTOOL_PIN = {};

module("Pin Configure Tool", {
	setup: function () {
		S.open("//index.htm", function onOpenSuccess() {
			S.win.resizeTo(screen.availWidth, screen.availHeight);
			S.win.moveTo(0, 0);
		});
	},
	teardown: function () {
		//S.win.print();
	}
});

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

function getRandomInt(max) {
  return Math.floor(Math.random() * Math.floor(max));
}

function decideNewChipType(newPartNumber_package) {
	var newChipType;

	// newPartNumber_package obtained from OpenOCD does not contain the package information
	if (newPartNumber_package.indexOf('(') === -1) {
		newPartNumber_package = newPartNumber_package + '(';
	}

	// decide chip type from part number name
	// the sequence is sensitive. do not disorder them.
	if (newPartNumber_package.indexOf('NDA102') === 0) {
		newChipType = 'NDA102';
	}
	else if (newPartNumber_package.indexOf('M05641') === 0) {
		newChipType = 'M05641';
	}
	else if (newPartNumber_package.indexOf('M0564') === 0) {
		newChipType = 'M0564';
	}
	else if (newPartNumber_package.indexOf('M4521') === 0) {
		newChipType = 'M4521';
	}
	else if (newPartNumber_package.indexOf('M45') === 0 || newPartNumber_package.indexOf('M4TK') === 0) {
		newChipType = newPartNumber_package;
		newChipType = newChipType.slicePriorToX('(');
		newChipType = newChipType.slice(newChipType.length - 4, newChipType.length - 3);
		if (newChipType === 'D' || newChipType === 'C') {
			newChipType = 'M451LD';
		}
		else {
			newChipType = 'M451HD';
		}
	}
	else if (newPartNumber_package.indexOf('M48') === 0) {
		if (newPartNumber_package.indexOf('8AE') !== -1 || newPartNumber_package.indexOf('CAE') !== -1) {
			newChipType = 'M480LD';
		}
		else {
			newChipType = 'M480';
		}
	}
	else if (newPartNumber_package.indexOf('M251') === 0 || newPartNumber_package.indexOf('M252') === 0) {
		newChipType = 'M251';
	}
	else if (newPartNumber_package.indexOf('M26') === 0) {
		newChipType = 'M261';
	}
	else if (newPartNumber_package.indexOf('M2351') === 0) {
		newChipType = 'M2351';
	}
	else if (newPartNumber_package.indexOf('M032FC1AE') === 0 ||
			 newPartNumber_package.indexOf('M032EC1AE') === 0 ||
			 newPartNumber_package.indexOf('M032TC1AE') === 0 ||
			 newPartNumber_package.indexOf('M032TD2AE') === 0 ||
			 newPartNumber_package.indexOf('M032LC2AE') === 0 ||
			 newPartNumber_package.indexOf('M032LD2AE') === 0) {
		newChipType = 'M031KM';
	}
	else if ((newPartNumber_package.indexOf('M031') === 0 || newPartNumber_package.indexOf('M032') === 0) &&
			  newPartNumber_package.charAt(5) === 'G') {
		newChipType = 'M031G';
	}
	else if ((newPartNumber_package.indexOf('M031') === 0 || newPartNumber_package.indexOf('M032') === 0) &&
			  newPartNumber_package.charAt(5) === 'I') {
		newChipType = 'M031I';
	}
	else if (newPartNumber_package.indexOf('M031') === 0 || newPartNumber_package.indexOf('M032') === 0) {
		newChipType = 'M031';
	}
	else if (newPartNumber_package.indexOf('M0518') === 0) {
		newChipType = 'M0518';
	}
	else if (newPartNumber_package.indexOf('ML51') === 0) {
		newChipType = 'ML51';
	}
	else if (newPartNumber_package.indexOf('MS51') === 0 && (newPartNumber_package.indexOf('C0AE(') !== -1 ||
			newPartNumber_package.indexOf('C0BE(') !== -1)) {
		newChipType = 'MS51_32K';
	}
	else if (newPartNumber_package.indexOf('MS51') === 0 && (newPartNumber_package.indexOf('B9AE(') !== -1 ||
			newPartNumber_package.indexOf('B9BE(') !== -1)) {
		newChipType = 'MS51_16K';
	}
	else if (newPartNumber_package.indexOf('MS51') === 0 && newPartNumber_package.indexOf('A9AE(') !== -1) {
		newChipType = 'MS51_8K';
	}
	else if (newPartNumber_package.indexOf('M0519') === 0) {
		newChipType = 'M0519';
	}
	else if (newPartNumber_package.indexOf('M05') === 0 && (newPartNumber_package.indexOf('DN(') !== -1 ||
			newPartNumber_package.indexOf('DE(') !== -1)) {
		newChipType = 'M051DN_DE';
	}
	else if (newPartNumber_package.indexOf('MHC54ZDN') === 0 || newPartNumber_package.indexOf('PL054TDN') === 0) {
		newChipType = 'M051DN_DE';
	}
	else if (newPartNumber_package.indexOf('M05') === 0 && newPartNumber_package.indexOf('BN(') !== -1) {
		newChipType = 'M051BN';
	}
	else if (newPartNumber_package.indexOf('E32') === 0) {
		newChipType = 'M051BN';
	}
	else if (newPartNumber_package.indexOf('M058S') === 0) {
		newChipType = 'M058S';
	}
	else if (newPartNumber_package.indexOf('M05') === 0 && newPartNumber_package.indexOf('AN(') !== -1) {
		newChipType = 'M051AN';
	}
	else if (newPartNumber_package.indexOf('MINI57') === 0) {
		newChipType = 'MINI57';
	}
	else if (newPartNumber_package.indexOf('MINI58') === 0) {
		newChipType = 'MINI58';
	}
	else if (newPartNumber_package.indexOf('MINI5') === 0 && newPartNumber_package.indexOf('AN(') !== -1) {
		newChipType = 'MINI51AN';
	}
	else if ((newPartNumber_package.indexOf('MINI5') === 0 && newPartNumber_package.indexOf('AE(') !== -1) ||
		newPartNumber_package.indexOf('MINI54XFHC') === 0 ||
		newPartNumber_package.indexOf('MINI55') === 0 ||
		newPartNumber_package.indexOf('NVS06AL') === 0) {
		newChipType = 'MINI55';
	}
	else if ((newPartNumber_package.indexOf('MINI5') === 0 && newPartNumber_package.indexOf('DE(') !== -1) ||
		newPartNumber_package.indexOf('MINI54FHC') === 0) {
		newChipType = 'MINI51DE';
	}
	else if (newPartNumber_package.indexOf('NUC2201') === 0) {
		newChipType = 'NUC2201';
	}
	else if (newPartNumber_package.indexOf('NUC2') === 0 && newPartNumber_package.indexOf('AN(') !== -1) {
		newChipType = 'NUC200AN';
	}
	else if (newPartNumber_package.indexOf('NUC2') === 0 && newPartNumber_package.indexOf('AE(') !== -1) {
		newChipType = 'NUC200AE';
	}
	else if (newPartNumber_package.indexOf('NUC029KGE') === 0) {
		newChipType = 'NUC029KGE';
	}
	else if (newPartNumber_package.indexOf('NUC029LDE') === 0 || newPartNumber_package.indexOf('NUC029SDE') === 0) {
		newChipType = 'NUC029xDE';
	}
	else if (newPartNumber_package.indexOf('NUC029LGE') === 0 || newPartNumber_package.indexOf('NUC029SGE') === 0) {
		newChipType = 'NUC029xGE';
	}
	else if (newPartNumber_package.indexOf('NUC029LEE') === 0 || newPartNumber_package.indexOf('NUC029SEE') === 0) {
		newChipType = 'NUC029xEE';
	}
	else if (newPartNumber_package.indexOf('NUC029') === 0 && newPartNumber_package.indexOf('AE(') !== -1) {
		newChipType = 'NUC029AE';
	}
	else if (newPartNumber_package.indexOf('NUC029') === 0 && newPartNumber_package.indexOf('AN(') !== -1) {
		newChipType = 'NUC029AN';
	}
	else if ((newPartNumber_package.indexOf('NANO120') === 0 || newPartNumber_package.indexOf('NANO100') === 0) &&
		newPartNumber_package.indexOf('AN(') !== -1) {
		newChipType = 'NANO100AN';
	}
	else if ((newPartNumber_package.indexOf('NANO100') === 0 || newPartNumber_package.indexOf('NANO110') === 0 || newPartNumber_package.indexOf('NANO120') === 0 || newPartNumber_package.indexOf('NANO130') === 0) &&
		newPartNumber_package.indexOf('BN(') !== -1) {
		newChipType = 'NANO100BN';
	}
	else if (newPartNumber_package.indexOf('NANO103') === 0 && newPartNumber_package.indexOf('AE(') !== -1) {
		newChipType = 'NANO103';
	}
	else if (newPartNumber_package.indexOf('NANO1') === 0 && newPartNumber_package.indexOf('AN(') !== -1) {
		newChipType = 'NANO112';
	}
	else if (newPartNumber_package.indexOf('NM112') === 0) {
		newChipType = 'NM1120';
	}
	else if (newPartNumber_package.indexOf('NM11') === 0 || newPartNumber_package.indexOf('NM12') === 0) {
		newChipType = 'NM1200';
	}
	else if (newPartNumber_package.indexOf('NM15') === 0) {
		newChipType = 'NM1500';
	}
	else if (newPartNumber_package.indexOf('NUC121') === 0 || newPartNumber_package.indexOf('NUC125') === 0) {
		newChipType = 'NUC121AE';
	}
	else if (newPartNumber_package.indexOf('NUC122') === 0 && newPartNumber_package.indexOf('AN(') !== -1) {
		newChipType = 'NUC122AN';
	}
	else if (newPartNumber_package.indexOf('NUC123') === 0 && (newPartNumber_package.indexOf('AN0(') !== -1 || newPartNumber_package.indexOf('AN1(') !== -1)) {
		newChipType = 'NUC123AN';
	}
	else if (newPartNumber_package.indexOf('NUC123') === 0 && (newPartNumber_package.indexOf('AE0(') !== -1 || newPartNumber_package.indexOf('AE1(') !== -1)) {
		newChipType = 'NUC123AE';
	}
	else if (newPartNumber_package.indexOf('NUC1') === 0 && (newPartNumber_package.indexOf('AN(') !== -1 || newPartNumber_package.indexOf('BN(') !== -1)) {
		newChipType = 'NUC100AN_BN';
	}
	else if (newPartNumber_package.indexOf('NUC1') === 0 && newPartNumber_package.indexOf('CN(') !== -1) {
		newChipType = 'NUC100CN';
	}
	else if (newPartNumber_package.indexOf('NUC1') === 0 && newPartNumber_package.indexOf('DN(') !== -1) {
		newChipType = 'NUC100DN';
	}
	else if (newPartNumber_package.indexOf('NUC1311') === 0) {
		newChipType = 'NUC1311';
	}
	else if (newPartNumber_package.indexOf('NUC13') === 0) {
		newChipType = 'NUC131';
	}
	else if (newPartNumber_package.indexOf('NUC1261') === 0) {
		newChipType = 'NUC1261';
	}
	else if (newPartNumber_package.indexOf('NUC126') === 0) {
		newChipType = 'NUC126';
	}
	else if (newPartNumber_package.indexOf('NUC505') === 0) {
		newChipType = 'NUC505';
	}
	else if (newPartNumber_package.indexOf('I91') === 0) {
		newChipType = 'ISD9100';
	}
	else if (newPartNumber_package.indexOf('I93') === 0) {
		newChipType = 'ISD9300';
	}
	else {
		newChipType = 'NUC400';
	}
	return newChipType;
}

function loadCorrespondingJS(mcu, oldChipType) {
	var chipType;

	chipType = decideNewChipType(mcu);

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

	return oldChipType;
}

function decide_cfg_gpiosIndex(pinName, mcu) {
	var returnResult = [],
		chipType = decideNewChipType(mcu);

	pinName = pinName.replace('GP', 'P'); // 'GPAXXX' -> 'PAXXX'
	if (chipType === "NM1500" || chipType === "M0519" ||
		chipType === "M051DN_DE" || chipType === "M051BN" || chipType === "M051AN" || chipType === "M058S" ||
		chipType === "MINI51AN" || chipType === "MINI51DE" || chipType === "MINI55" || chipType === "MINI58" ||
		chipType === "NUC029AE" || chipType === "NUC029AN" ||
		chipType === "NM1200") {
		returnResult.push(parseInt(pinName.slice(1, 2), 16) * 8);
		returnResult.push(returnResult[0] + 8);
	}
	else if (chipType === "ML51" || chipType.indexOf("MS51") === 0) {
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

function verifyMFPValueOnlyByFunctionName(currentPin, targetMultiFunctionName, targetMFPValueArray, mcu) {
	var i,
		j,
		max,
		maxJ,
		multiFunctionName,
		currentPinName,
		pinName,
		matchedMFPvalue = -1,
		powerNumber,
		tempString1,
		tempString2,
		shiftBitNumber,
		shiftBitUnit,
		mask,
		maskUnit,
		targetMFPValue,
		registerValue,
		bReturnResult = false,
		tempString = "",
		unusedObject = {},
		GPIOProperties = [];

	// get the current pin name
	NUTOOL_PIN.decidepackageNumber(mcu);
	currentPinName = NUTOOL_PIN.g_cfg_pkgs[NUTOOL_PIN.g_packageNumberIndex][currentPin - 1];

	targetMultiFunctionName = targetMultiFunctionName.restoreSpecialCharacters();
	// find the matched pin and MFP value
	for (i = 0, max = NUTOOL_PIN.g_cfg_gpios.length; i < max; i += 1) {
		for (j = 0, maxJ = NUTOOL_PIN.g_cfg_gpios[i].f.length; j < maxJ; j += 1) {
			multiFunctionName = NUTOOL_PIN.g_cfg_gpios[i].f[j];
			multiFunctionName = multiFunctionName.slice(0, multiFunctionName.indexOf(":"));
			if (multiFunctionName === targetMultiFunctionName) {
				pinName = NUTOOL_PIN.g_cfg_gpios[i].f[0];
				pinName = pinName.slice(0, pinName.indexOf(":"));

				if (pinName === currentPinName) {
					matchedMFPvalue = NUTOOL_PIN.g_cfg_gpios[i].f[j];
					matchedMFPvalue = parseInt(matchedMFPvalue.slice(matchedMFPvalue.indexOf(":") + 1), 10);

					break;
				}

			}
		}

		if (matchedMFPvalue !== -1) {
			break;
		}
	}

	if (matchedMFPvalue === -1) {
		// add some unused GPIO functions if exists
		if (typeof (NUTOOL_PIN.g_cfg_addGPIO) !== 'undefined' && typeof (NUTOOL_PIN.g_cfg_addGPIO[mcu]) !== 'undefined') {
			if (typeof (NUTOOL_PIN.g_cfg_addGPIO[mcu]) == "function") {
				unusedObject = NUTOOL_PIN.g_cfg_addGPIO[mcu]();
			}
			else {
				unusedObject = NUTOOL_PIN.g_cfg_addGPIO[mcu];
			}

			GPIOProperties = getPropertyNames(unusedObject);
			for (i = 0; i < GPIOProperties.length; i += 1) {
				if (GPIOProperties[i] === currentPinName) {
					tempString = unusedObject[currentPinName][0];
					tempString = tempString.slice(0, tempString.indexOf(':'));
					if (tempString === targetMultiFunctionName) {
						matchedMFPvalue = unusedObject[currentPinName][0];
						matchedMFPvalue = parseInt(matchedMFPvalue.slice(matchedMFPvalue.indexOf(":") + 1), 10);
						// do not forget to update pinName
						pinName = currentPinName;
					}
				}
			}
		}
	}

	// verify matchedMFPvalue
	if (matchedMFPvalue > 0 && (typeof (NUTOOL_PIN.g_cfg_gpioMatrix) === 'undefined' || NUTOOL_PIN.g_cfg_gpioMatrix.length === 0)) {
		bReturnResult = false;
		// for NUC400, M51 and NANO100
		if (mcu.indexOf('I91') === -1 && mcu.indexOf('I93') === -1) {
			shiftBitUnit = 4;
			maskUnit = 0xF;
		}
		// for ISD9100 and ISD9300
		else {
			shiftBitUnit = 2;
			maskUnit = 0x3;
		}

		if (currentPinName.indexOf('.') !== -1) {
			tempString1 = currentPinName.slice(0, currentPinName.indexOf('.'));
			tempString2 = currentPinName.slice(currentPinName.indexOf('.') + 1);
		}

		for (j = 0, maxJ = targetMFPValueArray.length; j < maxJ; j += 1) {
			targetMFPValue = targetMFPValueArray[j];
			if (targetMFPValue.indexOf(tempString1) !== -1) {
				registerValue = parseInt(targetMFPValue.slice(targetMFPValue.indexOf('0x') + 2), 16);

				shiftBitNumber = parseInt(tempString2, 10) * shiftBitUnit;
				//mask = (0xF << tempString2 * shiftBitUnit) >>> 0;
				mask = (maskUnit << shiftBitNumber) >>> 0;
				registerValue = (registerValue & mask) >>> 0;
				registerValue = (registerValue >>> shiftBitNumber) >>> 0;

				if (registerValue === matchedMFPvalue) {
					bReturnResult = true;
					break;
				}
			}
		}
	}
	else if (matchedMFPvalue > 0 && NUTOOL_PIN.g_cfg_gpioMatrix.length > 0) {
		for (i = 0, max = NUTOOL_PIN.g_cfg_gpioMatrix.length; i < max; i += 1) {
			if (pinName === NUTOOL_PIN.g_cfg_gpioMatrix[i].f[0]) {
				powerNumber = Math.floor(Math.log(matchedMFPvalue) / Math.log(2));

				while (powerNumber >= 0) {
					tempString1 = NUTOOL_PIN.g_cfg_gpioMatrix[i].f[powerNumber + 1];
					shiftBitNumber = parseInt(tempString1.slice(tempString1.indexOf('[') + 1, tempString1.indexOf(']')), 10);
					mask = (0x1 << shiftBitNumber) >>> 0;
					tempString2 = tempString1.slice(0, tempString1.indexOf('['));

					bReturnResult = false;
					for (j = 0, maxJ = targetMFPValueArray.length; j < maxJ; j += 1) {
						targetMFPValue = targetMFPValueArray[j];
						if (targetMFPValue.indexOf(tempString2) !== -1) {
							registerValue = parseInt(targetMFPValue.slice(targetMFPValue.indexOf('0x') + 2), 16);
							if (registerValue & mask) {
								bReturnResult = true;
								break;
							}
						}
					}
					// fail to match. the result of verifying is unsuccessful.
					if (!bReturnResult) {
						return bReturnResult;
					}

					// prepare to the next one
					if (matchedMFPvalue > 2) {
						matchedMFPvalue = matchedMFPvalue - Math.pow(2, powerNumber);
						if (matchedMFPvalue > 0) {
							powerNumber = Math.floor(Math.log(matchedMFPvalue) / Math.log(2));
						}
						else {
							break;
						}
					}
					else {
						break;
					}

				}

				break;
			}
		}
	}
	else if (matchedMFPvalue === 0) {
		bReturnResult = true;
	}

	return bReturnResult;
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
	return !isNaN(parseFloat(n)) && isFinite(n);
}


function createMultiFunctioinTable(tableContentArray, mcu, bAlphabeticalOrder) {
	var i,
		j,
		k,
		max,
		maxJ,
		maxK,
		multiFunctionProperties = [],
		possibleFields = [],
		table = document.createElement('table'),
		tr,
		tdArray = [],
		fieldString,
		valueString,
		insertString,
		bodyChildren = [],
		id1String,
		id2String,
		bInsertGeneratedCodeField = false,
		bInsertPinDescriptionField = false;
	// css setting
	table.style.border = "1px ridge black";
	table.cellpadding = "5";
	table.cellspacing = "5";
	table.frame = "border";
	table.rules = "all";

	multiFunctionProperties = getPropertyNames(tableContentArray);

	for (i = 0, max = multiFunctionProperties.length; i < max; i++) {
		for (j = 0, maxJ = tableContentArray[multiFunctionProperties[i]].length; j < maxJ; j++) {
			fieldString = tableContentArray[multiFunctionProperties[i]][j];
			if (fieldString.indexOf('/') !== -1) {
				fieldString = fieldString.slice(0, fieldString.indexOf('/'));

				if ($.inArray(fieldString, possibleFields) === -1 && fieldString !== "Generated Code" && fieldString !== "Pin Description") {
					possibleFields.push(fieldString);
				}

				if (fieldString === "Generated Code") {
					bInsertGeneratedCodeField = true;
				}

				if (fieldString === "Pin Description") {
					bInsertPinDescriptionField = true;
				}
			}
		}
	}

	if (bInsertGeneratedCodeField) {
		possibleFields.push("Generated Code");
	}

	if (bInsertPinDescriptionField) {
		possibleFields.splice(0, 0, "Pin Description");
	}

	// create the first row
	tr = document.createElement('tr');
	tr.style.border = "1px solid black";
	tdArray[0] = document.createElement('td');
	tdArray[0].appendChild(document.createTextNode(""));
	tr.appendChild(tdArray[0]);
	for (i = 0, max = possibleFields.length; i < max; i++) {
		tdArray.push(document.createElement('td'));
		tdArray[i + 1].appendChild(document.createTextNode(possibleFields[i]));
		tr.appendChild(tdArray[i + 1]);
	}
	table.appendChild(tr);

	// create the remaining rows
	for (i = 0, max = multiFunctionProperties.length; i < max; i++) {
		if (i === 0) {
			table.setAttribute("id", multiFunctionProperties[i]);
			table.className = mcu;
		}

		tr = document.createElement('tr');
		tr.style.border = "1px solid black";
		tdArray = [];
		tdArray[0] = document.createElement('td');
		tdArray[0].appendChild(document.createTextNode(multiFunctionProperties[i]));
		tr.appendChild(tdArray[0]);

		for (j = 0, maxJ = possibleFields.length; j < maxJ; j++) {
			tdArray.push(document.createElement('td'));
			for (k = 0, maxK = tableContentArray[multiFunctionProperties[i]].length; k < maxK; k++) {
				valueString = fieldString = tableContentArray[multiFunctionProperties[i]][k];
				if (fieldString.indexOf('/') !== -1) {
					fieldString = fieldString.slice(0, fieldString.indexOf('/'));
					valueString = valueString.slice(valueString.indexOf('/') + 1);
				}

				if (possibleFields[j] === fieldString) {
					if (isNumberic(valueString)) {
						tdArray[j + 1].appendChild(document.createTextNode('0x' + decimalToHex(parseInt(valueString, 10)).toLocaleUpperCase()));
					}
					else if (possibleFields[j] === "Generated Code") {
						do {
							if (valueString.indexOf(";") !== -1) {
								insertString = valueString.slice(0, valueString.indexOf(";"));
								valueString = valueString.slice(valueString.indexOf(";") + 1);
							}
							tdArray[j + 1].appendChild(document.createTextNode(insertString));
							tdArray[j + 1].appendChild(document.createElement("br"));
						}
						while (valueString.length);
					}
					else if (possibleFields[j] === "Pin Description") {
						tdArray[j + 1].appendChild(document.createTextNode(valueString));
					}

					tr.appendChild(tdArray[j + 1]);
					break;
				}
				else if (parseInt(valueString, 10) === 0 || k === maxK - 1) {
					if (possibleFields[j] !== "Generated Code" && possibleFields[j] !== "Pin Description") {
						tdArray[j + 1].appendChild(document.createTextNode('0x' + decimalToHex(0)));
					}
					else {
						tdArray[j + 1].appendChild(document.createTextNode(""));
					}
					tr.appendChild(tdArray[j + 1]);
					break;
				}
			}
		}

		table.appendChild(tr);
	}

	if (bAlphabeticalOrder) {
		// isnert to the appropriate position
		bodyChildren = document.body.children;
		for (i = bodyChildren.length - 1; i > 0; i = i - 1) {
			if (bodyChildren[i].className !== mcu) {
				bodyChildren[i].parentNode.insertBefore(table, bodyChildren[i].nextSibling);
				break;
			}
			else {
				id1String = table.id;
				id2String = bodyChildren[i].id;
				if (id1String.slice(1, 2).charCodeAt(0) > id2String.slice(1, 2).charCodeAt(0) || (
					id1String.slice(1, 2) === id2String.slice(1, 2) &&
					(parseInt(id1String.slice(id1String.indexOf('.') + 1), 10) > parseInt(id2String.slice(id2String.indexOf('.') + 1), 10)))) {
					bodyChildren[i].parentNode.insertBefore(table, bodyChildren[i].nextSibling);
					break;
				}
			}
		}
	}
	else {
		document.body.appendChild(table);
	}
}

function verifyMFPValue(currentPinName, targetMultiFunctionName, targetMFPValueArray, mcu) {
	var i,
		j,
		max,
		maxJ,
		multiFunctionName,
		pinName,
		matchedMFPvalue = -1,
		powerNumber,
		tempString1,
		tempString2,
		shiftBitNumber,
		shiftBitUnit,
		mask,
		targetMFPValue,
		registerValue,
		bReturnResult = false,
		tempString = "",
		unusedObject = [],
		GPIOProperties = [];

	// find the matched pin and MFP value
	for (i = 0, max = NUTOOL_PIN.g_cfg_gpios.length; i < max; i += 1) {
		for (j = 0, maxJ = NUTOOL_PIN.g_cfg_gpios[i].f.length; j < maxJ; j += 1) {
			multiFunctionName = NUTOOL_PIN.g_cfg_gpios[i].f[j];
			multiFunctionName = multiFunctionName.slice(0, multiFunctionName.indexOf(":"));
			if (multiFunctionName === targetMultiFunctionName) {
				pinName = NUTOOL_PIN.g_cfg_gpios[i].f[0];
				pinName = pinName.slice(0, pinName.indexOf(":"));

				if (pinName === currentPinName) {
					matchedMFPvalue = NUTOOL_PIN.g_cfg_gpios[i].f[j];
					matchedMFPvalue = parseInt(matchedMFPvalue.slice(matchedMFPvalue.indexOf(":") + 1), 10);

					break;
				}
			}
		}

		if (matchedMFPvalue !== -1) {
			break;
		}
	}

	if (matchedMFPvalue === -1) {
		// add some unused GPIO functions if exists
		if (typeof (NUTOOL_PIN.g_cfg_addGPIO) !== 'undefined' && typeof (NUTOOL_PIN.g_cfg_addGPIO[mcu]) !== 'undefined') {
			if (typeof (NUTOOL_PIN.g_cfg_addGPIO[mcu]) == "function") {
				unusedObject = NUTOOL_PIN.g_cfg_addGPIO[mcu]();
			}
			else {
				unusedObject = NUTOOL_PIN.g_cfg_addGPIO[mcu];
			}

			GPIOProperties = getPropertyNames(unusedObject);
			for (i = 0; i < GPIOProperties.length; i += 1) {
				if (GPIOProperties[i] === currentPinName) {
					tempString = unusedObject[currentPinName][0];
					tempString = tempString.slice(0, tempString.indexOf(':'));
					if (tempString === targetMultiFunctionName) {
						matchedMFPvalue = unusedObject[currentPinName][0];
						matchedMFPvalue = parseInt(matchedMFPvalue.slice(matchedMFPvalue.indexOf(":") + 1), 10);
						// do not forget to update pinName
						pinName = currentPinName;
					}
				}
			}
		}
	}

	// verify matchedMFPvalue
	if (matchedMFPvalue > 0 && (typeof (NUTOOL_PIN.g_cfg_gpioMatrix) === 'undefined' || NUTOOL_PIN.g_cfg_gpioMatrix.length === 0)) {
		bReturnResult = false;
		// for NUC400, M51 and NANO100
		if (mcu.indexOf('I91') === -1 && mcu.indexOf('I93') === -1) {
			shiftBitUnit = 4;
		}
		// for ISD9100 and ISD9300
		else {
			shiftBitUnit = 2;
		}

		if (currentPinName.indexOf('.') !== -1) {
			tempString1 = currentPinName.slice(0, currentPinName.indexOf('.'));
			tempString2 = currentPinName.slice(currentPinName.indexOf('.') + 1);
		}

		for (j = 0, maxJ = targetMFPValueArray.length; j < maxJ; j += 1) {
			targetMFPValue = targetMFPValueArray[j];
			if (targetMFPValue.indexOf(tempString1) !== -1) {
				registerValue = parseInt(targetMFPValue.slice(targetMFPValue.indexOf('0x') + 2), 16);

				shiftBitNumber = parseInt(tempString2, 10) * shiftBitUnit;
				registerValue = (registerValue >>> shiftBitNumber) >>> 0;

				if (registerValue === matchedMFPvalue) {
					bReturnResult = true;
					break;
				}
			}
		}
	}
	else if (matchedMFPvalue > 0 && NUTOOL_PIN.g_cfg_gpioMatrix.length > 0) {
		for (i = 0, max = NUTOOL_PIN.g_cfg_gpioMatrix.length; i < max; i += 1) {
			if (pinName === NUTOOL_PIN.g_cfg_gpioMatrix[i].f[0]) {
				powerNumber = Math.floor(Math.log(matchedMFPvalue) / Math.log(2));

				while (powerNumber >= 0) {
					tempString1 = NUTOOL_PIN.g_cfg_gpioMatrix[i].f[powerNumber + 1];
					shiftBitNumber = parseInt(tempString1.slice(tempString1.indexOf('[') + 1, tempString1.indexOf(']')), 10);
					mask = (0x1 << shiftBitNumber) >>> 0;
					tempString2 = tempString1.slice(0, tempString1.indexOf('['));

					bReturnResult = false;
					for (j = 0, maxJ = targetMFPValueArray.length; j < maxJ; j += 1) {
						targetMFPValue = targetMFPValueArray[j];
						if (targetMFPValue.indexOf(tempString2) !== -1) {
							registerValue = parseInt(targetMFPValue.slice(targetMFPValue.indexOf('0x') + 2), 16);
							if (registerValue & mask) {
								bReturnResult = true;
								break;
							}
						}
					}
					// fail to match. the result of verifying is unsuccessful.
					if (!bReturnResult) {
						return bReturnResult;
					}

					// prepare to the next one
					if (matchedMFPvalue > 2) {
						matchedMFPvalue = matchedMFPvalue - Math.pow(2, powerNumber);
						if (matchedMFPvalue > 0) {
							powerNumber = Math.floor(Math.log(matchedMFPvalue) / Math.log(2));
						}
						else {
							break;
						}
					}
					else {
						break;
					}

				}

				break;
			}
		}
	}
	else if (matchedMFPvalue === 0) {
		bReturnResult = true;
	}

	return bReturnResult;
}

function verifyAllSupportedMultiFunctions(currentPinName, allSupportedMultiFunctionsArray, mcu) {
	var i,
		j,
		max,
		maxJ,
		bReturnResult = false,
		allPossibleMultiFunctionsArray = [],
		pinName = "",
		tempString = "",
		unusedObject = {};

	for (i = 0, max = NUTOOL_PIN.g_cfg_gpios.length; i < max; i += 1) {
		pinName = NUTOOL_PIN.g_cfg_gpios[i].f[0];
		pinName = pinName.slice(0, pinName.indexOf(":"));

		if (pinName === currentPinName) {
			for (j = 0, maxJ = NUTOOL_PIN.g_cfg_gpios[i].f.length; j < maxJ; j += 1) {
				pinName = NUTOOL_PIN.g_cfg_gpios[i].f[j];
				pinName = pinName.slice(0, pinName.indexOf(":"));
				allPossibleMultiFunctionsArray.push(pinName);
			}

			break;
		}
	}

	// trim some unused GPIO functions if exists
	if (typeof (NUTOOL_PIN.g_cfg_unusedGPIO) !== 'undefined' && typeof (NUTOOL_PIN.g_cfg_unusedGPIO[mcu]) !== 'undefined') {
		if (typeof (NUTOOL_PIN.g_cfg_unusedGPIO[mcu]) == "function") {
			unusedObject = NUTOOL_PIN.g_cfg_unusedGPIO[mcu]();
		}
		else {
			unusedObject = NUTOOL_PIN.g_cfg_unusedGPIO[mcu];
		}
	}
	else if (typeof (NUTOOL_PIN.g_cfg_unusedGPIO) !== 'undefined' && typeof (NUTOOL_PIN.g_cfg_unusedGPIO[NUTOOL_PIN.g_packageNumberIndex]) !== 'undefined') {
		if (typeof (NUTOOL_PIN.g_cfg_unusedGPIO[NUTOOL_PIN.g_packageNumberIndex]) == "function") {
			unusedObject = NUTOOL_PIN.g_cfg_unusedGPIO[NUTOOL_PIN.g_packageNumberIndex]();
		}
		else {
			unusedObject = NUTOOL_PIN.g_cfg_unusedGPIO[NUTOOL_PIN.g_packageNumberIndex];
		}

	}

	if (typeof (unusedObject[currentPinName]) !== 'undefined') {
		for (i = 0; i < unusedObject[currentPinName].length; i += 1) {
			allPossibleMultiFunctionsArray.splice($.inArray(unusedObject[currentPinName][i], allPossibleMultiFunctionsArray), 1);
		}
	}
	if (typeof (unusedObject.ALL) !== 'undefined') {
		for (i = 0; i < unusedObject.ALL.length; i += 1) {
			for (j = 0; j < allPossibleMultiFunctionsArray.length; j += 1) {
				if (allPossibleMultiFunctionsArray[j].indexOf(unusedObject.ALL[i] + '_') === 0) {
					allPossibleMultiFunctionsArray.splice(j, 1);
				}
			}
		}
	}
	if (typeof (unusedObject.PARTIAL) !== 'undefined') {
		for (i = 0; i < unusedObject.PARTIAL.length; i += 1) {
			for (j = 0; j < allPossibleMultiFunctionsArray.length; j += 1) {
				if (allPossibleMultiFunctionsArray[j].indexOf(unusedObject.PARTIAL[i]) === 0) {
					allPossibleMultiFunctionsArray.splice(j, 1);
				}
			}
		}
	}

	// add some unused GPIO functions if exists
	if (typeof (NUTOOL_PIN.g_cfg_addGPIO) !== 'undefined' && typeof (NUTOOL_PIN.g_cfg_addGPIO[mcu]) !== 'undefined') {
		if (typeof (NUTOOL_PIN.g_cfg_addGPIO[mcu]) == "function") {
			unusedObject = NUTOOL_PIN.g_cfg_addGPIO[mcu]();
		}
		else {
			unusedObject = NUTOOL_PIN.g_cfg_addGPIO[mcu];
		}

		if (typeof (unusedObject[currentPinName]) !== 'undefined') {
			for (i = 0; i < unusedObject[currentPinName].length; i += 1) {
				tempString = unusedObject[currentPinName][i];
				tempString = tempString.slice(0, tempString.indexOf(':'));
				allPossibleMultiFunctionsArray.push(tempString);
			}
		}
	}

	allPossibleMultiFunctionsArray.push('Reset');
	// compare the possible and all supported multifunctions arrays
	allSupportedMultiFunctionsArray.sort();
	allPossibleMultiFunctionsArray.sort();
	bReturnResult = allSupportedMultiFunctionsArray.equals(allPossibleMultiFunctionsArray);

	return bReturnResult;
}


function operationsAfterMouseMove(whichSide, currentPin, ALTRegisters, mcu, bCreateTable, bAlphabeticalOrder, bTooltipBeReady) {
	var j,
		k,
		maxJ,
		maxK,
		innerText,
		currentPinName,
		innerTextPrimitive,
		innerTextPrimitive_tooltip,
		nextInnerTextPrimitive,
		currentGPIORegister,
		ALTRegisterValue,
		assumedMaxMultiFunctionOption = 17, // since M4 use 4 bits
		bThereIsNextOne,
		tempValue,
		tempString,
		raisedMFPRegisters = [],
		allSupportedMultiFunctionsArray = [],
		tableContentArray = [],
		allSupportedMultiFunctionsString = "",
		shownMessage;

	S.eval('$("' + whichSide + '").click();');
	// assemble allSupportedMultiFunctionsString
	for (j = 0, maxJ = assumedMaxMultiFunctionOption; j < maxJ; j = j + 1) {
		if (S('#Pin_MultiFunction_Selection_' + j).size() !== 0) {
			innerText = S('#Pin_MultiFunction_Selection_' + j).attr("innerText");
			allSupportedMultiFunctionsArray.push(innerText);
			allSupportedMultiFunctionsString = allSupportedMultiFunctionsString + innerText;

			if (S('#Pin_MultiFunction_Selection_' + (j + 1)).size() !== 0) {
				allSupportedMultiFunctionsString = allSupportedMultiFunctionsString + '/';
			}
		}
	}

	NUTOOL_PIN.decidepackageNumber(mcu);
	if (allSupportedMultiFunctionsArray.length === 0 &&
		NUTOOL_PIN.g_cfg_pkgs[NUTOOL_PIN.g_packageNumberIndex][currentPin - 1].indexOf('P') === 0 && NUTOOL_PIN.g_cfg_pkgs[NUTOOL_PIN.g_packageNumberIndex][currentPin - 1].indexOf('.') === 2) {
		ok(false, 'Failed: Pin' + currentPin + ': ' + 'Pin failed to be clicked. Please check it!');
		return;
	}

	// individual selection operation
	for (j = 0, maxJ = assumedMaxMultiFunctionOption; j < maxJ; j = j + 1) {
		if (S('#Pin_MultiFunction_Selection_' + j).size() !== 0) {
			//getting the tooltip
			if (NUTOOL_PIN.g_cfg_gpiosDescriptions.length > 0) {
				S.eval('$("#Pin_MultiFunction_Selection_' + j + '").mouseenter();');
				innerTextPrimitive_tooltip = "";
				innerTextPrimitive_tooltip = S('#Pin_MultiFunction_Selection_' + j + '_tooltip').attr("innerText");
			}
			// getting innerText shold be prior to click function
			innerTextPrimitive = innerText = S('#Pin_MultiFunction_Selection_' + j).attr("innerText");
			if (innerText.slice(0, 1) === 'P' && innerText.slice(2, 3) === '.') {
				currentGPIORegister = "P" + innerText.slice(1, 2);
				currentPinName = innerText;
			}
			innerText = innerText.replaceSpecialCharacters();

			bThereIsNextOne = false;
			if (S('#Pin_MultiFunction_Selection_' + (j + 1)).size() !== 0) {
				bThereIsNextOne = true;
				nextInnerTextPrimitive = S('#Pin_MultiFunction_Selection_' + (j + 1)).attr("innerText");
			}

			S.eval('$("#Pin_MultiFunction_Selection_' + j + '").mouseenter();');
			S.eval('$("#Pin_MultiFunction_Selection_' + j + '").click();');

			// get the generated code
			S.eval('NUTOOL_PIN.getDataUsedToCreateText();');

			if (innerText.indexOf('Reset') === -1) {
				if (!S('#' + innerText + '_Pin' + currentPin).hasClass('jstree-checked')) {
					ok(false, 'Failed: Pin' + currentPin + ': ' + innerTextPrimitive + ' was not checked.');
				}
				else if (S('#NUC_PinConfiguration_Canvas').attr("innerText").replaceSpecialCharacters() !== innerText) {
					ok(false, 'Failed: Pin' + currentPin + ': ' + innerTextPrimitive + ' was not drawn on the canvas.');
				}
				else if (bTooltipBeReady && NUTOOL_PIN.g_cfg_gpiosDescriptions.length > 0 && currentPinName.replaceSpecialCharacters() !== innerText && (typeof innerTextPrimitive_tooltip === 'undefined' || innerTextPrimitive_tooltip === 'undefined' || innerTextPrimitive_tooltip === "unknown")) {
					ok(false, 'Failed: Pin' + currentPin + ': the tooltip of ' + innerTextPrimitive + ' was unknown.');
				}
				else if (NUTOOL_PIN.g_cfg_gpiosDefines.length > 0 && currentPinName.replaceSpecialCharacters() !== innerText && (S('#NUC_PinConfiguration_Canvas').attr("innerHTML") === 'undefined' || S('#NUC_PinConfiguration_Canvas').attr("innerHTML") === "")) {
					ok(false, 'Failed: Pin' + currentPin + ': the generated code of ' + innerTextPrimitive + ' was missing.');
				}
				else if (j === 0 && !verifyAllSupportedMultiFunctions(currentPinName, allSupportedMultiFunctionsArray, mcu)) {
					ok(false, 'Failed: Pin' + currentPin + ': ' + allSupportedMultiFunctionsString + ' was wrong. Please check it.');
				}
				else {
					shownMessage = 'Pin' + currentPin + ': ' + innerTextPrimitive + ' checked. ' +
						innerTextPrimitive + ' drawn.';

					if (j === 0) {
						shownMessage = shownMessage + ' ' + allSupportedMultiFunctionsString + ' was verified.';
						if (typeof (tableContentArray[innerTextPrimitive]) === 'undefined') {
							tableContentArray[innerTextPrimitive] = [];
						}
						tableContentArray[innerTextPrimitive].push('0');
					}

					raisedMFPRegisters = [];
					if (S('#G' + currentGPIORegister + '_MFPH').size() !== 0) {
						tempString = S('#G' + currentGPIORegister + '_MFPH').text();
						tempValue = parseInt(tempString.slice(tempString.indexOf('0x') + 2), 16);
						if (tempValue > 0) {
							raisedMFPRegisters.push(tempString);
							shownMessage = shownMessage + ' ' + tempString;
							if (typeof (tableContentArray[innerTextPrimitive]) === 'undefined') {
								tableContentArray[innerTextPrimitive] = [];
							}
							tableContentArray[innerTextPrimitive].push('G' + currentGPIORegister + '_MFPH/' + tempValue);
						}
					}

					if (S('#G' + currentGPIORegister + '_MFPL').size() !== 0) {
						tempString = S('#G' + currentGPIORegister + '_MFPL').text();
						tempValue = parseInt(tempString.slice(tempString.indexOf('0x') + 2), 16);
						if (tempValue > 0) {
							raisedMFPRegisters.push(tempString);
							shownMessage = shownMessage + ' ' + tempString;
							if (typeof (tableContentArray[innerTextPrimitive]) === 'undefined') {
								tableContentArray[innerTextPrimitive] = [];
							}
							tableContentArray[innerTextPrimitive].push('G' + currentGPIORegister + '_MFPL/' + tempValue);
						}
					}

					if (S('#' + currentGPIORegister + '_H_MFP').size() !== 0) {
						tempString = S('#' + currentGPIORegister + '_H_MFP').text();
						tempValue = parseInt(tempString.slice(tempString.indexOf('0x') + 2), 16);
						if (tempValue > 0) {
							raisedMFPRegisters.push(tempString);
							shownMessage = shownMessage + ' ' + tempString;
							if (typeof (tableContentArray[innerTextPrimitive]) === 'undefined') {
								tableContentArray[innerTextPrimitive] = [];
							}
							tableContentArray[innerTextPrimitive].push(currentGPIORegister + '_H_MFP/' + tempValue);
						}
					}

					if (S('#' + currentGPIORegister + '_L_MFP').size() !== 0) {
						tempString = S('#' + currentGPIORegister + '_L_MFP').text();
						tempValue = parseInt(tempString.slice(tempString.indexOf('0x') + 2), 16);
						if (tempValue > 0) {
							raisedMFPRegisters.push(tempString);
							shownMessage = shownMessage + ' ' + tempString;
							if (typeof (tableContentArray[innerTextPrimitive]) === 'undefined') {
								tableContentArray[innerTextPrimitive] = [];
							}
							tableContentArray[innerTextPrimitive].push(currentGPIORegister + '_L_MFP/' + tempValue);
						}
					}

					for (k = 0, maxK = ALTRegisters.length; k < maxK; k = k + 1) {
						ALTRegisterValue = S("#" + ALTRegisters[k]).text();
						tempValue = parseInt(ALTRegisterValue.slice(ALTRegisterValue.indexOf('0x') + 2), 16);
						if (tempValue > 0) {
							raisedMFPRegisters.push(ALTRegisterValue);
							shownMessage = shownMessage + ' ' + ALTRegisterValue;
							if (typeof (tableContentArray[innerTextPrimitive]) === 'undefined') {
								tableContentArray[innerTextPrimitive] = [];
							}
							tableContentArray[innerTextPrimitive].push(ALTRegisters[k] + '/' + tempValue);
						}
					}

					if (S('#G' + currentGPIORegister + '_MFP').size() !== 0) {
						tempString = S('#G' + currentGPIORegister + '_MFP').text();
						tempValue = parseInt(tempString.slice(tempString.indexOf('0x') + 2), 16);
						if (tempValue > 0) {
							raisedMFPRegisters.push(tempString);
							shownMessage = shownMessage + ' ' + tempString;
							if (typeof (tableContentArray[innerTextPrimitive]) === 'undefined') {
								tableContentArray[innerTextPrimitive] = [];
							}
							tableContentArray[innerTextPrimitive].push('G' + currentGPIORegister + '_MFP/' + tempValue);
						}
					}

					if (S('#' + currentGPIORegister + '_MFP').size() !== 0) {
						tempString = S('#' + currentGPIORegister + '_MFP').text();
						tempValue = parseInt(tempString.slice(tempString.indexOf('0x') + 2), 16);
						if (tempValue > 0) {
							raisedMFPRegisters.push(tempString);
							shownMessage = shownMessage + ' ' + tempString;
							if (typeof (tableContentArray[innerTextPrimitive]) === 'undefined') {
								tableContentArray[innerTextPrimitive] = [];
							}
							tableContentArray[innerTextPrimitive].push(currentGPIORegister + '_MFP/' + tempValue);
						}
					}

					if (S('#' + currentGPIORegister + 'MF76543210').size() !== 0) {
						tempString = S('#' + currentGPIORegister + 'MF76543210').text();
						tempValue = parseInt(tempString.slice(tempString.indexOf('0x') + 2), 16);
						if (tempValue > 0) {
							raisedMFPRegisters.push(tempString);
							shownMessage = shownMessage + ' ' + tempString;
							if (typeof (tableContentArray[innerTextPrimitive]) === 'undefined') {
								tableContentArray[innerTextPrimitive] = [];
							}
							tableContentArray[innerTextPrimitive].push(currentGPIORegister + 'MF76543210/' + tempValue);
						}
					}

					if (S('#ADCHER').size() !== 0) {
						tempString = S('#ADCHER').text();
						tempValue = parseInt(tempString.slice(tempString.indexOf('0x') + 2), 16);
						if (tempValue > 0) {
							raisedMFPRegisters.push(tempString);
							shownMessage = shownMessage + ' ' + tempString;
							if (typeof (tableContentArray[innerTextPrimitive]) === 'undefined') {
								tableContentArray[innerTextPrimitive] = [];
							}
							tableContentArray[innerTextPrimitive].push('ADCHER/' + tempValue);
						}
					}

					if (S('#ADCR').size() !== 0) {
						tempString = S('#ADCR').text();
						tempValue = parseInt(tempString.slice(tempString.indexOf('0x') + 2), 16);
						if (tempValue > 0) {
							raisedMFPRegisters.push(tempString);
							shownMessage = shownMessage + ' ' + tempString;
							if (typeof (tableContentArray[innerTextPrimitive]) === 'undefined') {
								tableContentArray[innerTextPrimitive] = [];
							}
							tableContentArray[innerTextPrimitive].push('ADCR/' + tempValue);
						}
					}

					if (S('#PIN_SEL').size() !== 0) {
						tempString = S('#PIN_SEL').text();
						tempValue = parseInt(tempString.slice(tempString.indexOf('0x') + 2), 16);
						if (tempValue > 0) {
							raisedMFPRegisters.push(tempString);
							shownMessage = shownMessage + ' ' + tempString;
							if (typeof (tableContentArray[innerTextPrimitive]) === 'undefined') {
								tableContentArray[innerTextPrimitive] = [];
							}
							tableContentArray[innerTextPrimitive].push('PIN_SEL' + tempValue);
						}
					}

					if (typeof tableContentArray[innerTextPrimitive] === 'undefined') {
						tableContentArray[innerTextPrimitive] = [];
					}

					// insert the generated code into tableContentArray
					if (S('#NUC_PinConfiguration_Canvas').attr("innerHTML") !== 'undefined' && S('#NUC_PinConfiguration_Canvas').attr("innerHTML") !== "") {
						tableContentArray[innerTextPrimitive].push("Generated Code/" + S('#NUC_PinConfiguration_Canvas').attr("innerHTML"));
					}

					// insert the tooltip into tableContentArray
					if (NUTOOL_PIN.g_cfg_gpiosDescriptions.length > 0 && innerTextPrimitive_tooltip !== 'undefined' && innerTextPrimitive_tooltip !== "") {
						tableContentArray[innerTextPrimitive].push("Pin Description/" + innerTextPrimitive_tooltip);
					}

					if (verifyMFPValue(currentPinName, innerTextPrimitive, raisedMFPRegisters, mcu)) {
						if (raisedMFPRegisters.length > 1) {
							shownMessage = shownMessage + " was verified.";
						}
						else if (raisedMFPRegisters.length === 1) {
							shownMessage = shownMessage + " was verified.";
						}

						if (bCreateTable && nextInnerTextPrimitive == 'Reset') {
							createMultiFunctioinTable(tableContentArray, mcu, bAlphabeticalOrder);
						}

						ok(true, shownMessage);
					}
					else {
						ok(false, "Failed: " + shownMessage + ". At least one of the values of MFP registers was incorrect.");
					}
				}
				window.scrollTo(0, document.body.scrollHeight);
			}

			if (bThereIsNextOne) {
				S.eval('$("' + whichSide + '").click();');
			}
		}
		else {
			break;
		}
	}
}

(function mainTest() {
	var x,
		maxX,
		targetChips = [
			"M480/M483KGCAE2A(LQFP128)"//"M031/M032KG8AE(LQFP128)"//"M031/M032KG8AE(LQFP128)" //"M251/M251SC2AE(LQFP64)", "NANO100/NANO100NC2BN(QFN48)", "NANO100/NANO102ZC2AN(QFN33)", "NUC100/NUC123ZD4AE0(QFN33)", "MINI51/MINI57TDE(QFN33)", "M480/M487JIDAE(LQFP144)", "MINI51/MINI57TDE(QFN33)", "MINI51/MINI57TDE(QFN33)", "M2351/M2351KIAAE(ULQFP128)", "M480/M487JIDAE(LQFP144)", "NUC505/NUC505DLA(LQFP48)", "NUC505/NUC505DSA(LQFP64)"
		],
		chipSeries,
		mcu,
		oldChipType = "",
		currentIndexForNode = 0,
		currentIndexForPin = 0,
		bEnableClickAllofTheNodes = false,
		bEnableClickAllofThePins = true,
		bEnableClickMFPRegisterNodes = false, // optional
		bEnableClickAllofTheNodesRandomly = false, // optional
		startNodeItem = 0, // 0 means that begin from the first node
		startPin = -1, // -1 means that begin from pin 1
		endPin = -1,   // -1 means that end at the last pin
		bCreateTable = true, // to decide whether to create the multi-function table
		bAlphabeticalOrder = true, // to arrange the tables in the alphabetical order
		bTooltipBeReady = true, // to decide whether to test the tooltip
		NUC_Pin_Width = 18; // this will be depenent on the real pin width displayed on the monitor. It must be integer and even number.

	for (x = 0, maxX = targetChips.length; x < maxX; x = x + 1) {
		if (bEnableClickAllofTheNodes) {
			test("Click all of the Nodes", function () {
				var i,
					j,
					k,
					m,
					max,
					maxJ,
					maxK,
					maxM,
					TreeNode,
					TreeNodeId,
					currentDate,
					dateTime,
					partNumber_package,
					currentPin,
					ALTRegisters = [],
					MFPRegisters = [],
					ALTRegisterValue,
					MFPRegisterValue,
					raisedMFPRegisters = [],
					bVerifiedResult,
					shownMessage;

				// decide chipSeries and mcu
				chipSeries = targetChips[currentIndexForNode];
				chipSeries = chipSeries.slice(0, chipSeries.indexOf('/'));

				mcu = targetChips[currentIndexForNode];
				mcu = mcu.slice(mcu.indexOf('/') + 1);

				oldChipType = loadCorrespondingJS(mcu, oldChipType);

				if (S("#ChipTypeSelect").val() !== chipSeries) {
					S.eval('$("#ChipTypeSelect").val("' + chipSeries + '").change();');
				}
				if (S("#MCUselect").val() !== mcu) {
					S.eval('$("#MCUselect").val("' + mcu + '").change();');
				}

				S.eval('NUTOOL_PIN.uncheckAllNodes_core();');

				// decide Test Time
				currentDate = new Date();
				dateTime = "Test Time: " + currentDate.getDate() + "/" + (currentDate.getMonth() + 1) + "/" + currentDate.getFullYear() + " at " + currentDate.getHours() + ":" + currentDate.getMinutes() + ":" + currentDate.getSeconds();

				// decide the total pin number
				partNumber_package = S("#MCUselect").val();

				ok(true, 'Chip Series: ' + S("#ChipTypeSelect").val() + ' Part No: ' + partNumber_package + ' ' + dateTime);

				// check how many ALT registers exist
				if (S('#ALT_MFP').size() !== 0) {
					ALTRegisters.push('#ALT_MFP');
				}
				for (i = 1, max = 5; i < max; i = i + 1) {
					if (S('#ALT_MFP' + i).size() !== 0) {
						ALTRegisters.push('#ALT_MFP' + i);
					}
				}

				// check how many MFP registers exist
				for (i = 0, max = 9; i <= max; i = i + 1) {
					if (S('#GP' + i + '_MFP').size() !== 0) {
						MFPRegisters.push('#GP' + i + '_MFP');
					}
					if (S('#P' + i + '_MFP').size() !== 0) {
						MFPRegisters.push('#P' + i + '_MFP');
					}
					if (S('#P' + i + 'MF76543210').size() !== 0) {
						MFPRegisters.push('#P' + i + 'MF76543210');
					}
				}
				for (i = "A".charCodeAt(0), max = "M".charCodeAt(0) ; i <= max; i = i + 1) {
					if (S('#GP' + String.fromCharCode(i) + '_MFP').size() !== 0) {
						MFPRegisters.push('#GP' + String.fromCharCode(i) + '_MFP');
					}
					if (S('#P' + String.fromCharCode(i) + '_MFP').size() !== 0) {
						MFPRegisters.push('#P' + String.fromCharCode(i) + '_MFP');
					}
					if (S('#GP' + String.fromCharCode(i) + '_MFPH').size() !== 0) {
						MFPRegisters.push('#GP' + String.fromCharCode(i) + '_MFPH');
					}
					if (S('#GP' + String.fromCharCode(i) + '_MFPL').size() !== 0) {
						MFPRegisters.push('#GP' + String.fromCharCode(i) + '_MFPL');
					}
					if (S('#P' + String.fromCharCode(i) + '_H_MFP').size() !== 0) {
						MFPRegisters.push('#P' + String.fromCharCode(i) + '_H_MFP');
					}
					if (S('#P' + String.fromCharCode(i) + '_L_MFP').size() !== 0) {
						MFPRegisters.push('#P' + String.fromCharCode(i) + '_L_MFP');
					}
				}
				// for MINI51X
				if (S('#ADCHER').size() !== 0) {
					MFPRegisters.push('#ADCHER');
				}
				if (S('#ADCR').size() !== 0) {
					MFPRegisters.push('#ADCR');
				}
				if (S('#PIN_SEL').size() !== 0) {
					MFPRegisters.push('#PIN_SEL');
				}

				for (i = startNodeItem, max = S('#moduleTree').children().children().length; i < max ; i = i + 1) {
					// click the modules
					TreeNodeId = S('#moduleTree').children().children().eq(i)[0].id;
					if (!S('#' + TreeNodeId).hasClass('semi-disabled')) {
						S.eval('$("#moduleTree").jstree("check_node", $("#' + TreeNodeId + '"));');
						if (S('#NUC_PinConfiguration_Canvas').attr("innerText").replaceSpecialCharacters().indexOf(TreeNodeId.slicePriorToX('_Root')) !== 0) {
							ok(false, 'Failed: Module ' + TreeNodeId + ': ' + 'failed to be clicked.');
						}
						else {
							// check the values of MFP registers
							bVerifiedResult = true;
							for (j = 0, maxJ = S('#moduleTree').children().children().eq(i).children().eq(2).children().length ; j < maxJ ; j = j + 1) {
								TreeNode = S('#moduleTree').children().children().eq(i).children().eq(2).children().eq(j)[0].id;
								currentPin = TreeNode.slice(TreeNode.indexOf('_Pin') + 4);
								TreeNode = TreeNode.slice(0, TreeNode.indexOf('_Pin'));

								raisedMFPRegisters = [];
								for (k = 0, maxK = MFPRegisters.length; k < maxK; k = k + 1) {
									MFPRegisterValue = S(MFPRegisters[k]).text();
									if (parseInt(MFPRegisterValue.slice(MFPRegisterValue.indexOf('0x') + 2), 16) > 0) {
										raisedMFPRegisters.push(MFPRegisterValue);
									}
								}

								for (k = 0, maxK = ALTRegisters.length; k < maxK; k = k + 1) {
									ALTRegisterValue = S(ALTRegisters[k]).text();
									if (parseInt(ALTRegisterValue.slice(ALTRegisterValue.indexOf('0x') + 2), 16) > 0) {
										raisedMFPRegisters.push(ALTRegisterValue);
									}
								}

								if (!verifyMFPValueOnlyByFunctionName(parseInt(currentPin, 10), TreeNode, raisedMFPRegisters, mcu)) {
									bVerifiedResult = false;
									ok(false, 'Failed: Module ' + TreeNodeId + ': ' + TreeNode + ' related MFP value was incorrect.');
								}
							}

							if (bVerifiedResult) {
								ok(ok, 'Module ' + TreeNodeId + ': ' + 'was clicked successfully and all of the related MFP values had been verified.');
							}
						}
						S.eval('$("#moduleTree").jstree("uncheck_node", $("#' + TreeNodeId + '"));');
					}
					// click the features
					for (j = 0, maxJ = S('#moduleTree').children().children().eq(i).children().eq(2).children().length ; j < maxJ ; j = j + 1) {
						TreeNodeId = S('#moduleTree').children().children().eq(i).children().eq(2).children().eq(j)[0].id;

						if (TreeNodeId.indexOf('_Intermediate') === -1) {
							S.eval('$("#moduleTree").jstree("check_node", $("#' + TreeNodeId + '"));');

							TreeNode = TreeNodeId.slice(0, TreeNodeId.indexOf('_Pin'));
							currentPin = TreeNodeId.slice(TreeNodeId.indexOf('_Pin') + 4);

							if (S('#NUC_PinConfiguration_Canvas').attr("innerText").replaceSpecialCharacters() !== TreeNode) {
								ok(false, 'Failed: Pin' + currentPin + ': ' + TreeNode.restoreSpecialCharacters() + ' was not drawn on the canvas.');
							}
							else {
								shownMessage = 'Pin' + currentPin + ': ' + TreeNode.restoreSpecialCharacters() + ' drawn. ';

								for (k = 0, maxK = MFPRegisters.length; k < maxK; k = k + 1) {
									MFPRegisterValue = S(MFPRegisters[k]).text();
									if (parseInt(MFPRegisterValue.slice(MFPRegisterValue.indexOf('0x') + 2), 16) > 0) {
										shownMessage = shownMessage + ' ' + MFPRegisterValue;
									}
								}

								for (k = 0, maxK = ALTRegisters.length; k < maxK; k = k + 1) {
									ALTRegisterValue = S(ALTRegisters[k]).text();
									if (parseInt(ALTRegisterValue.slice(ALTRegisterValue.indexOf('0x') + 2), 16) > 0) {
										shownMessage = shownMessage + ' ' + ALTRegisterValue;
									}
								}

								ok(true, shownMessage);
							}
							window.scrollTo(0, document.body.scrollHeight);

							S.eval('$("#moduleTree").jstree("uncheck_node", $("#' + TreeNodeId + '"));');
						}
						else {
							for (m = 0, maxM = S('#moduleTree').children().children().eq(i).children().eq(2).children().eq(j).children().eq(2).children().length ; m < maxM ; m = m + 1) {
								TreeNodeId = S('#moduleTree').children().children().eq(i).children().eq(2).children().eq(j).children().eq(2).children().eq(m)[0].id;

								S.eval('$("#moduleTree").jstree("check_node", $("#' + TreeNodeId + '"));');

								TreeNode = TreeNodeId.slice(0, TreeNodeId.indexOf('_Pin'));
								currentPin = TreeNodeId.slice(TreeNodeId.indexOf('_Pin') + 4);

								if (S('#NUC_PinConfiguration_Canvas').attr("innerText").replaceSpecialCharacters() !== TreeNode) {
									ok(false, 'Failed: Pin' + currentPin + ': ' + TreeNode.restoreSpecialCharacters() + ' was not drawn on the canvas.');
								}
								else {
									shownMessage = 'Pin' + currentPin + ': ' + TreeNode.restoreSpecialCharacters() + ' drawn. ';

									for (k = 0, maxK = MFPRegisters.length; k < maxK; k = k + 1) {
										MFPRegisterValue = S(MFPRegisters[k]).text();
										if (parseInt(MFPRegisterValue.slice(MFPRegisterValue.indexOf('0x') + 2), 16) > 0) {
											shownMessage = shownMessage + ' ' + MFPRegisterValue;
										}
									}

									for (k = 0, maxK = ALTRegisters.length; k < maxK; k = k + 1) {
										ALTRegisterValue = S(ALTRegisters[k]).text();
										if (parseInt(ALTRegisterValue.slice(ALTRegisterValue.indexOf('0x') + 2), 16) > 0) {
											shownMessage = shownMessage + ' ' + ALTRegisterValue;
										}
									}

									ok(true, shownMessage);
								}
								window.scrollTo(0, document.body.scrollHeight);

								S.eval('$("#moduleTree").jstree("uncheck_node", $("#' + TreeNodeId + '"));');
							}
						}
					}
				}

				// load the relevant content js file
				// loadOrRemoveJsCssFile('NUC_' + chipType + '_Content.js', "js", "remove");
				// jump to the next chip
				currentIndexForNode = currentIndexForNode + 1;
			});
		}

		if (bEnableClickAllofThePins) {
			test("Click all of the Pins", function () {
				var i,
					max,
					partNumber_package,
					NUC_Pin_Total_Number,
					moveLength,
					currentDate,
					dateTime,
					clickLocationString,
					ALTRegisters = [],
					currentPin = 1,
					tempString = "",
					tempString1 = "",
					bFound = false;

				// decide chipSeries and mcu
				chipSeries = targetChips[currentIndexForPin];
				chipSeries = chipSeries.slice(0, chipSeries.indexOf('/'));

				mcu = targetChips[currentIndexForPin];
				mcu = mcu.slice(mcu.indexOf('/') + 1);

				if (oldChipType !== "") {
					startPin = -1;
					endPin = -1; // return to default
				}

				oldChipType = loadCorrespondingJS(mcu, oldChipType);

				// verify chipSeries and mcu
				bFound = false;
				for (i = 0, max = NUTOOL_PIN.g_cfg_chips.length; i < max; i += 1) {
					tempString = NUTOOL_PIN.g_cfg_chips[i].name + '(' + NUTOOL_PIN.g_cfg_chips[i].pkg + ')';

					if (tempString === mcu) {
						bFound = true;
						break;
					}
					tempString1 = tempString1 + tempString + '\n';
				}

				if (!bFound) {
					ok(false, "Failed: " + mcu + " was not found in the eligible list:\n" + tempString1);
					return;
				}


				if (S("#ChipTypeSelect").val() !== chipSeries) {
					S.eval('$("#ChipTypeSelect").val("' + chipSeries + '").change();');
				}
				if (S("#MCUselect").val() !== mcu) {
					S.eval('$("#MCUselect").val("' + mcu + '").change();');
				}

				S.eval('NUTOOL_PIN.uncheckAllNodes_core();');

				// decide the total pin number
				partNumber_package = S("#MCUselect").val();
				NUC_Pin_Total_Number = partNumber_package.substring(partNumber_package.indexOf('(') + 1);
				NUC_Pin_Total_Number = NUC_Pin_Total_Number.substring(0, NUC_Pin_Total_Number.indexOf(')'));
				NUC_Pin_Total_Number = parseInt(NUC_Pin_Total_Number.slice(NUC_Pin_Total_Number.indexOf(NUC_Pin_Total_Number.match(/\d/))), 10);
				// since QFP33 has virtually 32 pins
				if (NUC_Pin_Total_Number === 33) {
					NUC_Pin_Total_Number = 32;
				}
				// decide Test Time
				currentDate = new Date();

				dateTime = "Test Time: " + currentDate.getDate() + "/" + (currentDate.getMonth() + 1) + "/" + currentDate.getFullYear() + " at " + currentDate.getHours() + ":" + currentDate.getMinutes() + ":" + currentDate.getSeconds();
				ok(true, 'Chip Series: ' + S("#ChipTypeSelect").val() + ' Part No: ' + partNumber_package + ' ' + dateTime);
				// check how many ALT registers exist
				if (S('#ALT_MFP').size() !== 0) {
					ALTRegisters.push('ALT_MFP');
				}
				for (i = 1, max = 5; i < max; i = i + 1) {
					if (S('#ALT_MFP' + i).size() !== 0) {
						ALTRegisters.push('ALT_MFP' + i);
					}
				}

				// decide start and end pins
				if (startPin < 1) {
					startPin = 1;
				}
				if (endPin < 1 || endPin > NUC_Pin_Total_Number) {
					endPin = NUC_Pin_Total_Number;
				}

				currentPin = startPin;
				if (S("#MCUselect").val().indexOf('TSSOP') === -1) {
					for (i = startPin - 1, max = endPin; i < max; i = i + 1) {
						// click all of the pins
						// down side
						if (i < NUC_Pin_Total_Number / 4) {
							if ((NUC_Pin_Total_Number / 4) % 2 === 0) {
								moveLength = Math.floor(NUC_Pin_Total_Number / 8) - 1;
								moveLength = (i - moveLength) * NUC_Pin_Width - NUC_Pin_Width / 2;
							}
							else {
								moveLength = Math.floor(NUC_Pin_Total_Number / 8);
								moveLength = (i - moveLength) * NUC_Pin_Width;
							}

							if (moveLength >= 0) {
								clickLocationString = '+' + Math.abs(moveLength) + ' +0';
							}
							else {
								clickLocationString = '-' + Math.abs(moveLength) + ' +0';
							}
							S('#pin_side_0').move(clickLocationString).then(function () {
								operationsAfterMouseMove('#pin_side_0', currentPin, ALTRegisters, mcu, bCreateTable, bAlphabeticalOrder, bTooltipBeReady);
								currentPin = currentPin + 1;
							});
						}
							// right side
						else if (i >= NUC_Pin_Total_Number / 4 && i < NUC_Pin_Total_Number / 2) {
							if ((NUC_Pin_Total_Number / 4) % 2 === 0) {
								moveLength = NUC_Pin_Total_Number / 4 + Math.floor(NUC_Pin_Total_Number / 8) - 1;
								moveLength = (i - moveLength) * NUC_Pin_Width - NUC_Pin_Width / 2;
							}
							else {
								moveLength = NUC_Pin_Total_Number / 4 + Math.floor(NUC_Pin_Total_Number / 8);
								moveLength = (i - moveLength) * NUC_Pin_Width;
							}

							if (moveLength >= 0) {
								clickLocationString = '+0 -' + Math.abs(moveLength);
							}
							else {
								clickLocationString = '+0 +' + Math.abs(moveLength);
							}

							S('#pin_side_1').move(clickLocationString).then(function () {
								operationsAfterMouseMove('#pin_side_1', currentPin, ALTRegisters, mcu, bCreateTable, bAlphabeticalOrder);
								currentPin = currentPin + 1;
							});
						}
							// upper side
						else if (i >= NUC_Pin_Total_Number / 2 && i < NUC_Pin_Total_Number / 4 * 3) {
							if ((NUC_Pin_Total_Number / 4) % 2 === 0) {
								moveLength = NUC_Pin_Total_Number / 2 + Math.floor(NUC_Pin_Total_Number / 8) - 1;
								moveLength = (i - moveLength) * NUC_Pin_Width - NUC_Pin_Width / 2;
							}
							else {
								moveLength = NUC_Pin_Total_Number / 2 + Math.floor(NUC_Pin_Total_Number / 8);
								moveLength = (i - moveLength) * NUC_Pin_Width;
							}

							if (moveLength >= 0) {
								clickLocationString = '-' + Math.abs(moveLength) + ' +0';
							}
							else {
								clickLocationString = '+' + Math.abs(moveLength) + ' +0';
							}

							S('#pin_side_2').move(clickLocationString).then(function () {
								operationsAfterMouseMove('#pin_side_2', currentPin, ALTRegisters, mcu, bCreateTable, bAlphabeticalOrder);
								currentPin = currentPin + 1;
							});
						}
						else {
							if ((NUC_Pin_Total_Number / 4) % 2 === 0) {
								moveLength = NUC_Pin_Total_Number * 3 / 4 + Math.floor(NUC_Pin_Total_Number / 8) - 1;
								moveLength = (i - moveLength) * NUC_Pin_Width - NUC_Pin_Width / 2;
							}
							else {
								moveLength = NUC_Pin_Total_Number * 3 / 4 + Math.floor(NUC_Pin_Total_Number / 8);
								moveLength = (i - moveLength) * NUC_Pin_Width;
							}

							if (moveLength >= 0) {
								clickLocationString = '+0 +' + Math.abs(moveLength);
							}
							else {
								clickLocationString = '+0 -' + Math.abs(moveLength);
							}

							S('#pin_side_3').move(clickLocationString).then(function () {
								operationsAfterMouseMove('#pin_side_3', currentPin, ALTRegisters, mcu, bCreateTable, bAlphabeticalOrder);
								currentPin = currentPin + 1;
							});
						}
					}
				}
				else {
					for (i = startPin - 1, max = endPin; i < max; i = i + 1) {
						// click all of the pins
						// left side
						if (i < NUC_Pin_Total_Number / 2) {
							if ((NUC_Pin_Total_Number / 2) % 2 === 0) {
								moveLength = Math.floor(NUC_Pin_Total_Number / 4) - 1;
								moveLength = (i - moveLength) * NUC_Pin_Width - NUC_Pin_Width / 2;
							}
							else {
								moveLength = Math.floor(NUC_Pin_Total_Number / 4);
								moveLength = (i - moveLength) * NUC_Pin_Width;
							}

							if (moveLength >= 0) {
								clickLocationString = '+0 +' + Math.abs(moveLength);
							}
							else {
								clickLocationString = '+0 -' + Math.abs(moveLength);
							}

							S('#pin_side_0').move(clickLocationString).then(function () {
								operationsAfterMouseMove('#pin_side_0', currentPin, ALTRegisters, mcu, bCreateTable, bAlphabeticalOrder);
								currentPin = currentPin + 1;
							});
						}
							// right side
						else {
							if ((NUC_Pin_Total_Number / 2) % 2 === 0) {
								moveLength = NUC_Pin_Total_Number / 2 + Math.floor(NUC_Pin_Total_Number / 4) - 1;
								moveLength = (i - moveLength) * NUC_Pin_Width - NUC_Pin_Width / 2;
							}
							else {
								moveLength = NUC_Pin_Total_Number / 2 + Math.floor(NUC_Pin_Total_Number / 4);
								moveLength = (i - moveLength) * NUC_Pin_Width;
							}

							if (moveLength >= 0) {
								clickLocationString = '+0 -' + Math.abs(moveLength);
							}
							else {
								clickLocationString = '+0 +' + Math.abs(moveLength);
							}

							S('#pin_side_1').move(clickLocationString).then(function () {
								operationsAfterMouseMove('#pin_side_1', currentPin, ALTRegisters, mcu, bCreateTable, bAlphabeticalOrder);
								currentPin = currentPin + 1;
							});
						}
					}
				}
				// jump to the next chip
				currentIndexForPin = currentIndexForPin + 1;
			});
		}

		if (bEnableClickMFPRegisterNodes) {
			test("Click MFPRegister Nodes", function () {
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
					currentDate,
					dateTime,
					partNumber_package,
					ALTRegisters = [],
					MFPRegisters = [],
					MFPRegisterValue,
					GPIOProperties = [],
					unusedObject = {},
					g_cfg_pkgsIndexArray = [],
					bL,
					bL1,
					mask,
					shiftBitUnit,
					shiftBitNumber,
					register,
					bitShift,
					bitNumber,
					assigningValue,
					backupValue,
					pinName,
					GPIOName,
					registerValue,
					tempString,
					tempString1,
					tempString2,
					matchedMFPvalue,
					lastMatchedMFPvalue,
					innerText,
					bContinue = true;

				// decide chipSeries and mcu
				chipSeries = targetChips[currentIndexForNode];
				chipSeries = chipSeries.slice(0, chipSeries.indexOf('/'));

				mcu = targetChips[currentIndexForNode];
				mcu = mcu.slice(mcu.indexOf('/') + 1);

				oldChipType = loadCorrespondingJS(mcu, oldChipType);

				if (S("#ChipTypeSelect").val() !== chipSeries) {
					S.eval('$("#ChipTypeSelect").val("' + chipSeries + '").change();');
				}

				if (S("#MCUselect").val() !== mcu) {
					S.eval('$("#MCUselect").val("' + mcu + '").change();');
				}

				S.eval('NUTOOL_PIN.uncheckAllNodes_core();');

				// decide Test Time
				currentDate = new Date();
				dateTime = "Test Time: " + currentDate.getDate() + "/" + (currentDate.getMonth() + 1) + "/" + currentDate.getFullYear() + " at " + currentDate.getHours() + ":" + currentDate.getMinutes() + ":" + currentDate.getSeconds();

				// decide the total pin number
				partNumber_package = S("#MCUselect").val();


				// check how many ALT registers exist
				if (S('#ALT_MFP').size() !== 0) {
					ALTRegisters.push('#ALT_MFP');
				}
				for (i = 1, max = 5; i < max; i = i + 1) {
					if (S('#ALT_MFP' + i).size() !== 0) {
						ALTRegisters.push('#ALT_MFP' + i);
					}
				}

				// check how many MFP registers exist
				for (i = 0, max = 9; i <= max; i = i + 1) {
					if (S('#GP' + i + '_MFP').size() !== 0) {
						MFPRegisters.push('#GP' + i + '_MFP');
					}
					if (S('#P' + i + '_MFP').size() !== 0) {
						MFPRegisters.push('#P' + i + '_MFP');
					}
				}
				for (i = "A".charCodeAt(0), max = "M".charCodeAt(0) ; i <= max; i = i + 1) {
					if (S('#GP' + String.fromCharCode(i) + '_MFP').size() !== 0) {
						MFPRegisters.push('#GP' + String.fromCharCode(i) + '_MFP');
					}
					if (S('#P' + String.fromCharCode(i) + '_MFP').size() !== 0) {
						MFPRegisters.push('#P' + String.fromCharCode(i) + '_MFP');
					}
					if (S('#GP' + String.fromCharCode(i) + '_MFPH').size() !== 0) {
						MFPRegisters.push('#GP' + String.fromCharCode(i) + '_MFPH');
					}
					if (S('#GP' + String.fromCharCode(i) + '_MFPL').size() !== 0) {
						MFPRegisters.push('#GP' + String.fromCharCode(i) + '_MFPL');
					}
					if (S('#P' + String.fromCharCode(i) + '_H_MFP').size() !== 0) {
						MFPRegisters.push('#P' + String.fromCharCode(i) + '_H_MFP');
					}
					if (S('#P' + String.fromCharCode(i) + '_L_MFP').size() !== 0) {
						MFPRegisters.push('#P' + String.fromCharCode(i) + '_L_MFP');
					}
				}
				// for MINI51X
				if (S('#ADCHER').size() !== 0) {
					MFPRegisters.push('#ADCHER');
					bContinue = false;
				}
				if (S('#ADCR').size() !== 0) {
					MFPRegisters.push('#ADCR');
					bContinue = false;
				}
				if (S('#PIN_SEL').size() !== 0) {
					MFPRegisters.push('#PIN_SEL');
					bContinue = false;
				}

				if (ALTRegisters.length > 0) {
					bContinue = false;
				}

				if (bContinue) {
					ok(true, 'Chip Series: ' + S("#ChipTypeSelect").val() + ' Part No: ' + partNumber_package + ' ' + dateTime);
				}
				else {
					ok(false, 'Chip Series: ' + S("#ChipTypeSelect").val() + ' Part No: ' + partNumber_package + ' ' + dateTime + '. We failed because this chip was not allowed to do the test.');
					return;
				}

				// for NUC400, M51 and NANO100
				if (mcu.indexOf('I91') === -1 && mcu.indexOf('I93') === -1) {
					shiftBitUnit = 4;
				}
				// for ISD9100 and ISD9300
				else {
					shiftBitUnit = 2;
				}

				NUTOOL_PIN.decidepackageNumber(mcu);
				// trim some unused GPIO functions if exists
				if (typeof (NUTOOL_PIN.g_cfg_unusedGPIO) !== 'undefined' && typeof (NUTOOL_PIN.g_cfg_unusedGPIO[NUTOOL_PIN.g_packageNumberIndex]) !== 'undefined') {
					if (typeof (NUTOOL_PIN.g_cfg_unusedGPIO[mcu]) == "function") {
						unusedObject = NUTOOL_PIN.g_cfg_unusedGPIO[NUTOOL_PIN.g_packageNumberIndex]();
					}
					else {
						unusedObject = NUTOOL_PIN.g_cfg_unusedGPIO[NUTOOL_PIN.g_packageNumberIndex];
					}
					GPIOProperties = getPropertyNames(unusedObject);

					for (i = 0; i < GPIOProperties.length; i += 1) {
						if (GPIOProperties[i].indexOf('ALL') !== 0) {
							pinName = GPIOProperties[i] + ':0';
							// trim the unused GPIO function in NUTOOL_PIN.g_cfg_gpios
							for (m = 0, maxM = NUTOOL_PIN.g_cfg_gpios.length; m < maxM; m += 1) {
								if (pinName === NUTOOL_PIN.g_cfg_gpios[m].f[0]) {
									for (j = 0, maxJ = unusedObject[GPIOProperties[i]].length; j < maxJ; j = j + 1) {
										GPIOName = unusedObject[GPIOProperties[i]][j];
										for (n = NUTOOL_PIN.g_cfg_gpios[m].f.length - 1; n >= 0; n -= 1) {
											if (NUTOOL_PIN.g_cfg_gpios[m].f[n].indexOf(GPIOName) === 0) {
												NUTOOL_PIN.g_cfg_gpios[m].f.splice(n, 1);
											}
										}
									}
									break;
								}
							}

						}
						else {
							// trim the unused GPIO function for the specific module
							for (m = 0, maxM = NUTOOL_PIN.g_cfg_gpios.length; m < maxM; m += 1) {
								for (j = 0, maxJ = unusedObject[GPIOProperties[i]].length; j < maxJ; j = j + 1) {
									GPIOName = unusedObject[GPIOProperties[i]][j];
									for (n = NUTOOL_PIN.g_cfg_gpios[m].f.length - 1; n >= 0; n -= 1) {
										if (NUTOOL_PIN.g_cfg_gpios[m].f[n].indexOf(GPIOName) === 0) {
											NUTOOL_PIN.g_cfg_gpios[m].f.splice(n, 1);
										}
									}
								}
							}
						}
					}
				}
				else if (typeof (NUTOOL_PIN.g_cfg_unusedGPIO) !== 'undefined' && typeof (NUTOOL_PIN.g_cfg_unusedGPIO[mcu]) !== 'undefined') {
					if (typeof (NUTOOL_PIN.g_cfg_unusedGPIO[mcu]) == "function") {
						unusedObject = NUTOOL_PIN.g_cfg_unusedGPIO[mcu]();
					}
					else {
						unusedObject = NUTOOL_PIN.g_cfg_unusedGPIO[mcu];
					}
					GPIOProperties = getPropertyNames(unusedObject);

					for (i = 0; i < GPIOProperties.length; i += 1) {
						if (GPIOProperties[i].indexOf('ALL') !== 0) {
							pinName = GPIOProperties[i] + ':0';
							// trim the unused GPIO function in NUTOOL_PIN.g_cfg_gpios
							for (m = 0, maxM = NUTOOL_PIN.g_cfg_gpios.length; m < maxM; m += 1) {
								if (pinName === NUTOOL_PIN.g_cfg_gpios[m].f[0]) {
									for (j = 0, maxJ = unusedObject[GPIOProperties[i]].length; j < maxJ; j = j + 1) {
										GPIOName = unusedObject[GPIOProperties[i]][j];
										for (n = NUTOOL_PIN.g_cfg_gpios[m].f.length - 1; n >= 0; n -= 1) {
											if (NUTOOL_PIN.g_cfg_gpios[m].f[n].indexOf(GPIOName) === 0) {
												NUTOOL_PIN.g_cfg_gpios[m].f.splice(n, 1);
											}
										}
									}
									break;
								}
							}

						}
						else {
							// trim the unused GPIO function for the specific module
							for (m = 0, maxM = NUTOOL_PIN.g_cfg_gpios.length; m < maxM; m += 1) {
								for (j = 0, maxJ = unusedObject[GPIOProperties[i]].length; j < maxJ; j = j + 1) {
									GPIOName = unusedObject[GPIOProperties[i]][j];
									for (n = NUTOOL_PIN.g_cfg_gpios[m].f.length - 1; n >= 0; n -= 1) {
										if (NUTOOL_PIN.g_cfg_gpios[m].f[n].indexOf(GPIOName) === 0) {
											NUTOOL_PIN.g_cfg_gpios[m].f.splice(n, 1);
										}
									}
								}
							}
						}
					}
				}

				// the test starts from here
				for (k = 0, maxK = MFPRegisters.length; k < maxK ; k = k + 1) {
					MFPRegisterValue = MFPRegisters[k].slice(1);
					g_cfg_pkgsIndexArray = decide_cfg_gpiosIndex(MFPRegisterValue, mcu);

					if (MFPRegisterValue.indexOf('MFPH') !== -1 || MFPRegisterValue.indexOf('_H_MFP') !== -1) {
						bL = false;
					}
					else {
						bL = true;
					}

					for (i = g_cfg_pkgsIndexArray[0], max = g_cfg_pkgsIndexArray[1]; i < max; i += 1) {
						if (typeof (NUTOOL_PIN.g_cfg_gpios[i]) === 'undefined') {
							break;
						}

						pinName = NUTOOL_PIN.g_cfg_gpios[i].f[0];
						pinName = pinName.slice(0, pinName.indexOf(":"));
						register = pinName;

						lastMatchedMFPvalue = -1;

						if (pinName.indexOf('.') !== -1) {
							tempString1 = pinName.slice(0, pinName.indexOf('.'));
							tempString2 = pinName.slice(pinName.indexOf('.') + 1);
						}

						if (tempString2 < 8) {
							bL1 = true;
						}
						else {
							bL1 = false;
						}

						if (MFPRegisterValue.indexOf(tempString1) !== -1 &&
							bL != bL1) {
							i = i + 7;
						}
						else {
							if (MFPRegisterValue.indexOf(tempString1) !== -1 &&
								$.inArray(pinName, NUTOOL_PIN.g_cfg_pkgs[NUTOOL_PIN.g_packageNumberIndex]) !== -1) {
								for (j = 1, maxJ = NUTOOL_PIN.g_cfg_gpios[i].f.length; j < maxJ; j += 1) {
									matchedMFPvalue = NUTOOL_PIN.g_cfg_gpios[i].f[j];
									pinName = matchedMFPvalue.slicePriorToX(':');
									matchedMFPvalue = parseInt(matchedMFPvalue.slice(matchedMFPvalue.indexOf(":") + 1), 10);

									if (typeof (NUTOOL_PIN.g_cfg_gpioMatrix) === 'undefined' || NUTOOL_PIN.g_cfg_gpioMatrix.length === 0) {
										if (!bL) {
										tempString2 = tempString2 - 8;
										}

										shiftBitNumber = parseInt(tempString2, 10) * shiftBitUnit;
										registerValue = (matchedMFPvalue << shiftBitNumber) >>> 0;
									}
									else {
										registerValue = 0;
										for (m = 0, maxM = NUTOOL_PIN.g_cfg_gpioMatrix.length; m < maxM; m += 1) {
											if (register === NUTOOL_PIN.g_cfg_gpioMatrix[m].f[0]) {
												for (n = 1, maxN = NUTOOL_PIN.g_cfg_gpioMatrix[m].f.length; n < maxN; n += 1) {
													tempString = NUTOOL_PIN.g_cfg_gpioMatrix[m].f[n];

													bitShift = parseInt(tempString.slice(tempString.indexOf('[') + 1, tempString.indexOf(']')), 10);
													bitNumber = parseInt(tempString.sliceAfterX(':'), 10);

													mask = (0x1 << bitShift) >>> 0;
													assigningValue = 0;
													if (matchedMFPvalue & 0x1 << bitNumber) {
														assigningValue = (0x1 << bitShift) >>> 0;
													}

													backupValue = (registerValue & ~mask) >>> 0;
													registerValue = (backupValue | assigningValue) >>> 0;
												}
												break;
											}
										}
									}

									S.eval('$("#mfpTree").jstree("rename_node", "' + MFPRegisters[k] + '", "' + MFPRegisterValue + ':0x' + decimalToHex(registerValue).toUpperCase() + '");');
									S.eval('$("#mfpTree").jstree("rename", "' + MFPRegisters[k] + '");');
									if (k < maxK - 2) {
										S.eval('$("#mfpTree").jstree("rename", "' + MFPRegisters[k + 2] + '");');
									}
									else if (k < maxK - 1) {
										S.eval('$("#mfpTree").jstree("rename", "' + MFPRegisters[0] + '");');
									}
									else {
										S.eval('$("#mfpTree").jstree("rename", "' + MFPRegisters[1] + '");');
									}

									innerText = S('#NUC_PinConfiguration_Canvas').attr("innerText").restoreSpecialCharacters();

									if (typeof innerText != "undefined" && innerText.indexOf(pinName) === 0) {
										ok(true, 'Input ' + MFPRegisterValue + ':0x' + decimalToHex(registerValue).toUpperCase() + ' Expected: ' + pinName + ' Result: '  + innerText);
									}
									else if (lastMatchedMFPvalue === matchedMFPvalue) {
										ok(true, 'Input ' + MFPRegisterValue + ':0x' + decimalToHex(registerValue).toUpperCase() + ' Expected: ' + pinName + ' Result: '  + innerText + ' Identical MFP value:'  + matchedMFPvalue);
									}
									else {
										ok(false, 'Input ' + MFPRegisterValue + ':0x' + decimalToHex(registerValue).toUpperCase() + ' Expected: ' + pinName + ' Result: '  + innerText);
									}

									// reset to 0x00000000
									S.eval('$("#mfpTree").jstree("rename_node", "' + MFPRegisters[k] + '", "' + MFPRegisterValue + ':0x' + decimalToHex(0).toUpperCase() + '");');
									S.eval('$("#mfpTree").jstree("rename", "' + MFPRegisters[k] + '");');
									if (k < maxK - 2) {
										S.eval('$("#mfpTree").jstree("rename", "' + MFPRegisters[k + 2] + '");');
									}
									else if (k < maxK - 1) {
										S.eval('$("#mfpTree").jstree("rename", "' + MFPRegisters[0] + '");');
									}
									else {
										S.eval('$("#mfpTree").jstree("rename", "' + MFPRegisters[1] + '");');
									}

									lastMatchedMFPvalue = matchedMFPvalue;
								}
							}
							else if (MFPRegisterValue.indexOf(tempString1) === -1) {
								if (i + 8 < max &&
									NUTOOL_PIN.g_cfg_gpios[i].f[0].slicePriorToX('.') !== NUTOOL_PIN.g_cfg_gpios[i + 8].f[0].slicePriorToX('.')) {
									i = i + 7;
								}
								else {
									i = i + 15;
								}
							}
						}
					}
				}

				// load the relevant content js file
				// loadOrRemoveJsCssFile('NUC_' + chipType + '_Content.js', "js", "remove");
				// jump to the next chip
				currentIndexForNode = currentIndexForNode + 1;
			});
		}

		if (bEnableClickAllofTheNodesRandomly) {
			test("Click all of the Nodes", function () {
				var i,
					j,
					m,
					max,
					maxJ,
					maxM,
					TreeNodeId,
					TreeNodeIdArray = [],
					currentDate,
					dateTime,
					partNumber_package,
					homManyLoops = 1,
					conflictReport;

				// decide chipSeries and mcu
				chipSeries = targetChips[currentIndexForNode];
				chipSeries = chipSeries.slice(0, chipSeries.indexOf('/'));

				mcu = targetChips[currentIndexForNode];
				mcu = mcu.slice(mcu.indexOf('/') + 1);

				oldChipType = loadCorrespondingJS(mcu, oldChipType);

				if (S("#ChipTypeSelect").val() !== chipSeries) {
					S.eval('$("#ChipTypeSelect").val("' + chipSeries + '").change();');
				}
				if (S("#MCUselect").val() !== mcu) {
					S.eval('$("#MCUselect").val("' + mcu + '").change();');
				}

				S.eval('NUTOOL_PIN.uncheckAllNodes_core();');

				// decide Test Time
				currentDate = new Date();
				dateTime = "Test Time: " + currentDate.getDate() + "/" + (currentDate.getMonth() + 1) + "/" + currentDate.getFullYear() + " at " + currentDate.getHours() + ":" + currentDate.getMinutes() + ":" + currentDate.getSeconds();

				// decide the total pin number
				partNumber_package = S("#MCUselect").val();

				ok(true, 'Chip Series: ' + S("#ChipTypeSelect").val() + ' Part No: ' + partNumber_package + ' ' + dateTime);

				for (i = 0, max = S('#moduleTree').children().children().length; i < max ; i = i + 1) {
					TreeNodeId = S('#moduleTree').children().children().eq(i)[0].id;
					TreeNodeIdArray.push(TreeNodeId);
					for (j = 0, maxJ = S('#moduleTree').children().children().eq(i).children().eq(2).children().length ; j < maxJ ; j = j + 1) {
						TreeNodeIdArray.push(TreeNodeId);
						TreeNodeId = S('#moduleTree').children().children().eq(i).children().eq(2).children().eq(j)[0].id;
						if (TreeNodeId.indexOf('_Intermediate') === -1) {
							TreeNodeIdArray.push(TreeNodeId);
						}
						else {
							TreeNodeIdArray.push(TreeNodeId);
							for (m = 0, maxM = S('#moduleTree').children().children().eq(i).children().eq(2).children().eq(j).children().eq(2).children().length ; m < maxM ; m = m + 1) {
								TreeNodeId = S('#moduleTree').children().children().eq(i).children().eq(2).children().eq(j).children().eq(2).children().eq(m)[0].id;
								TreeNodeIdArray.push(TreeNodeId);
							}
						}
					}
				}

				for (i = 0, max = Math.floor(TreeNodeIdArray.length * homManyLoops); i < max ; i = i + 1) {
					TreeNodeId = TreeNodeIdArray[getRandomInt(TreeNodeIdArray.length)];
					S.eval('$("#moduleTree").jstree("check_node", $("#' + TreeNodeId + '"));');
					ok(true, TreeNodeId);
				}

				conflictReport = S('#NUC_PinConfiguration_Canvas').attr("innerText");
				if (conflictReport.indexOf('Failed') !== -1) {
					ok(false, conflictReport);
				}

				// load the relevant content js file
				// loadOrRemoveJsCssFile('NUC_' + chipType + '_Content.js', "js", "remove");
				// jump to the next chip
				currentIndexForNode = currentIndexForNode + 1;
			});
		}
	}
}(NUTOOL_PIN, this));