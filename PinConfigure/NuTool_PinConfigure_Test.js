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

function loadCorrespondingJS(mcu, oldChipType) {
    var chipType;

    chipType = S.eval('NUTOOL_PIN.decideNewChipType("' + mcu + '");');

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
        chipType = S.eval('NUTOOL_PIN.decideNewChipType("' + mcu + '");');

    pinName = pinName.replace('GP', 'P'); // 'GPAXXX' -> 'PAXXX'
    if (chipType === "NM1500" || chipType === "M0519" ||
        chipType === "M051DN_DE" || chipType === "M051BN" || chipType === "M051AN" || chipType === "M058S" ||
        chipType === "MINI51AN" || chipType === "MINI51DE" || chipType === "MINI55" || chipType === "MINI58" ||
        chipType === "NUC029AE" || chipType === "NUC029AN" ||
        chipType === "NM1200") {
        returnResult.push(parseInt(pinName.slice(1, 2), 16) * 8);
        returnResult.push(returnResult[0] + 8);
    }
    else if (chipType === "ML51" || chipType.indexOf("MS51") === 0 || chipType === "MUG51" || chipType.indexOf("KM1M7") === 0) {
        returnResult.push(parseInt(pinName.slice(1, 2), 16) * 8);
        returnResult.push(returnResult[0] + 8);
    }
    else if (chipType === "MINI57" || chipType === "NM1120" || chipType === "NDA102") {
        returnResult.push((pinName.slice(1, 2).charCodeAt(0) - 'A'.charCodeAt(0)) * 8);
        returnResult.push(returnResult[0] + 8);
    }
    else {
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
                    for (j = 0, maxJ = unusedObject[currentPinName].length; j < maxJ; j = j + 1) {
                        tempString = unusedObject[currentPinName][j];
                        tempString = tempString.slice(0, tempString.indexOf(':'));
                        if (tempString === targetMultiFunctionName) {
                            matchedMFPvalue = unusedObject[currentPinName][j];
                            matchedMFPvalue = parseInt(matchedMFPvalue.slice(matchedMFPvalue.indexOf(":") + 1), 10);
                            // do not forget to update pinName
                            pinName = currentPinName;
                        }
                    }
                }
            }
        }
    }

    // verify matchedMFPvalue
    if (matchedMFPvalue > 0 && (typeof (NUTOOL_PIN.g_cfg_gpioMatrix) === 'undefined' || NUTOOL_PIN.g_cfg_gpioMatrix.length === 0)) {
        bReturnResult = false;
        // for ISD9100 and ISD9300
        if (mcu.indexOf('I91') !== -1 || mcu.indexOf('I93') !== -1) {
            shiftBitUnit = 2;
            maskUnit = 0x3;
        }
        // 如果一次占8個bit的就要用這個
        else if (mcu.indexOf('M0A2') === 0 || mcu.indexOf('M46') === 0 || mcu.indexOf('M2L31') === 0 || mcu.indexOf('M55M1') === 0) {
            shiftBitUnit = 8;
            maskUnit = 0xFF;
        }
        else {
            shiftBitUnit = 4;
            maskUnit = 0xF;
        }

        if (currentPinName.indexOf('.') !== -1) {
            // e.g. tempString1=PB
            tempString1 = currentPinName.slice(0, currentPinName.indexOf('.'));
            // e.g. tempString2=6
            tempString2 = currentPinName.slice(currentPinName.indexOf('.') + 1);
        }

        for (j = 0, maxJ = targetMFPValueArray.length; j < maxJ; j += 1) {
            // e.g. targetMFPValue=GPB_MFPL:0x0B000000
            targetMFPValue = targetMFPValueArray[j];
            if (targetMFPValue.indexOf(tempString1) !== -1) {
                // e.g. registerValue=0x0B000000
                registerValue = parseInt(targetMFPValue.slice(targetMFPValue.indexOf('0x') + 2), 16);
                // e.g. shiftBitNumber=6*4=24
                shiftBitNumber = parseInt(tempString2, 10) * shiftBitUnit;
                // e.g. mask=0x0F000000
                mask = (maskUnit << shiftBitNumber) >>> 0;
                // 看mask是不是正好對到對應的bit
                // e.g. registerValue=0x0B000000
                registerValue = (registerValue & mask) >>> 0;
                // e.g. registerValue=0xB
                registerValue = (registerValue >>> shiftBitNumber) >>> 0;
                // matchedMFPvalue要對照NUTOOL_PIN.g_cfg_gpios後面的數字
                // registerValue=0xB, matchedMFPvalue=11
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

function isGPIOPin(pinName) {
    if (typeof (pinName) !== 'undefined' &&
        pinName.slice(0, 1) === 'P' &&
        pinName.slice(2, 3) === '.' &&
        isNumberic(pinName.sliceAfterX('.'))) {
        return true;
    }
    else {
        return false;
    }
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
        // insert to the appropriate position
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
        matchedFPSvalue = -1,
        powerNumber,
        tempString1,
        tempString2,
        shiftBitNumber,
        shiftBitUnit,
        mask,
        targetMFPValue,
        registerValue,
        targetFPSValue,
        FPSMapping,
        FPSRegisterName,
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
                    for (j = 0, maxJ = unusedObject[currentPinName].length; j < maxJ; j = j + 1) {
                        tempString = unusedObject[currentPinName][j];
                        tempString = tempString.slice(0, tempString.indexOf(':'));
                        if (tempString === targetMultiFunctionName) {
                            matchedMFPvalue = unusedObject[currentPinName][j];
                            matchedMFPvalue = parseInt(matchedMFPvalue.slice(matchedMFPvalue.indexOf(":") + 1), 10);
                            // do not forget to update pinName
                            pinName = currentPinName;
                        }
                    }
                }
            }
        }
    }

    // verify matchedMFPvalue
    if (matchedMFPvalue > 0 && (typeof (NUTOOL_PIN.g_cfg_gpioMatrix) === 'undefined' || NUTOOL_PIN.g_cfg_gpioMatrix.length === 0)) {
        bReturnResult = false;
        // for ISD9100 and ISD9300
        if (mcu.indexOf('I91') !== -1 || mcu.indexOf('I93') !== -1) {
            shiftBitUnit = 2;
        }
        // 如果一次占8個bit的就要用這個
        else if (mcu.indexOf('M0A2') === 0 || mcu.indexOf('M46') === 0 || mcu.indexOf('M2L31') === 0 || mcu.indexOf('M55M1') === 0) {
            shiftBitUnit = 8;
        }
        else {
            shiftBitUnit = 4;
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

        // KM1M7CF - test MFP registers
        if (mcu.indexOf('KM1M7CF') !== -1) {
            for (i = 0, max = NUTOOL_PIN.g_cfg_gpios_FPS_mapping.length; i < max; i += 1) {
                FPSMapping = NUTOOL_PIN.g_cfg_gpios_FPS_mapping[i];
                if (FPSMapping.indexOf(currentPinName) !== -1) {
                    FPSRegisterName = FPSMapping.slice(NUTOOL_PIN.g_cfg_gpios_FPS_mapping[i].indexOf(":") + 1);
                    break;
                }
            }
            for (j = 0, maxJ = targetMFPValueArray.length; j < maxJ; j += 1) {
                targetMFPValue = targetMFPValueArray[j];
                // 抓到的targetMFPValueArray裡面有包含FPSRegisterName的話再繼續確認
                if (targetMFPValue.indexOf(FPSRegisterName) !== -1) {
                    // 從g_cfg_gpios_FPS_value中找到對應的function name的值(matchedFPSvalue)
                    for (i = 0, max = NUTOOL_PIN.g_cfg_gpios_FPS_value.length; i < max; i += 1) {
                        targetFPSValue = NUTOOL_PIN.g_cfg_gpios_FPS_value[i];
                        multiFunctionName = targetFPSValue.slice(0, targetFPSValue.indexOf(":"));
                        if (multiFunctionName === targetMultiFunctionName) {
                            matchedFPSvalue = parseInt(targetFPSValue.slice(targetFPSValue.indexOf(":") + 1), 10);
                            break;
                        }
                    }
                    // 檢查UI上的值是否和g_cfg_gpios_FPS_value裡的一致 (不用shift)
                    registerValue = parseInt(targetMFPValue.slice(targetMFPValue.indexOf('0x') + 2), 16);
                    if (registerValue == matchedFPSvalue) {
                        bReturnResult = true;
                    } else {
                        bReturnResult = false;
                        break;  // 有一個錯誤就跳出
                    }
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
            for (j = allPossibleMultiFunctionsArray.length - 1; j >= 0; j -= 1) {
                if (allPossibleMultiFunctionsArray[j].indexOf(unusedObject.ALL[i]) === 0 ||
                    allPossibleMultiFunctionsArray[j] === unusedObject.ALL[i]) {
                    allPossibleMultiFunctionsArray.splice(j, 1);
                }
            }
        }
    }
    if (typeof (unusedObject.PARTIAL) !== 'undefined') {
        for (i = 0; i < unusedObject.PARTIAL.length; i += 1) {
            for (j = allPossibleMultiFunctionsArray.length - 1; j >= 0; j -= 1) {
                if (allPossibleMultiFunctionsArray[j] === unusedObject.PARTIAL[i]) {
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
    // compare the possible and all supported multifunction arrays
    allSupportedMultiFunctionsArray.sort();
    allPossibleMultiFunctionsArray.sort();
    bReturnResult = allSupportedMultiFunctionsArray.equals(allPossibleMultiFunctionsArray);

    return bReturnResult;
}


function operationsAfterMouseMove(whichSide, currentPin, ALTRegisters, mcu, bCreateTable, bAlphabeticalOrder, bTooltipBeReady, bModularizedBeReady) {
    var j,
        k,
        maxJ,
        maxK,
        innerText,
        currentFPSName,
        currentPinName,
        updatedPinName,
        innerTextPrimitive,
        innerTextPrimitive_tooltip,
        nextInnerTextPrimitive,
        currentGPIORegister,
        ALTRegisterValue,
        assumedMaxMultiFunctionOption = 70,
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

    updatedPinName = S.eval('NUTOOL_PIN.updatePinName("' + currentPin + '");');
    NUTOOL_PIN.decidepackageNumber(mcu);
    if (allSupportedMultiFunctionsArray.length === 0 &&
        isGPIOPin(NUTOOL_PIN.g_cfg_pkgs[NUTOOL_PIN.g_packageNumberIndex][currentPin - 1])) {
        ok(false, 'Failed: Pin' + updatedPinName + ': ' + 'Pin failed to be clicked. Please check it!');
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
            // getting innerText should be prior to click function
            innerTextPrimitive = innerText = S('#Pin_MultiFunction_Selection_' + j).attr("innerText");
            if (isGPIOPin(innerText)) {
                currentGPIORegister = "P" + innerText.slice(1, 2);
                currentPinName = innerText;
                // For KM1M7CF
                if (NUTOOL_PIN.g_cfg_gpios_FPS_mapping != undefined && NUTOOL_PIN.g_cfg_gpios_FPS_mapping != null) {
                    for (var m = 0, maxM = NUTOOL_PIN.g_cfg_gpios_FPS_mapping.length; m < maxM; m += 1) {
                        if (NUTOOL_PIN.g_cfg_gpios_FPS_mapping[m].indexOf(currentPinName) === 0) {
                            currentFPSName = NUTOOL_PIN.g_cfg_gpios_FPS_mapping[m].sliceAfterX(':');
                            break;
                        }
                    }
                }
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
            S.eval('NUTOOL_PIN.getIncludeHeadFile();');
            S.eval('NUTOOL_PIN.getDataUsedToCreateText();');

            if (innerText.indexOf('Reset') === -1) {
                if (!S('#' + innerText + '_Pin' + currentPin).hasClass('jstree-checked')) {
                    ok(false, 'Failed: Pin' + updatedPinName + ': ' + innerTextPrimitive + ' was not checked.');
                }
                else if (S('#NUC_PinConfiguration_Canvas').attr("innerText").replaceSpecialCharacters() !== innerText) {
                    ok(false, 'Failed: Pin' + updatedPinName + ': ' + innerTextPrimitive + ' was not drawn on the canvas.');
                }
                else if (bTooltipBeReady && NUTOOL_PIN.g_cfg_gpiosDescriptions.length > 0 && currentPinName.replaceSpecialCharacters() !== innerText && (typeof innerTextPrimitive_tooltip === 'undefined' || innerTextPrimitive_tooltip === 'undefined' || innerTextPrimitive_tooltip === "unknown")) {
                    ok(false, 'Failed: Pin' + updatedPinName + ': the tooltip of ' + innerTextPrimitive + ' was unknown.');
                }
                else if (NUTOOL_PIN.g_cfg_gpiosDefines.length > 0 && currentPinName.replaceSpecialCharacters() !== innerText && (S('#NUC_PinConfiguration_Canvas').attr("innerHTML") === 'undefined' || S('#NUC_PinConfiguration_Canvas').attr("innerHTML") === "")) {
                    ok(false, 'Failed: Pin' + updatedPinName + ': the generated code of ' + innerTextPrimitive + ' was missing.');
                }
                else if (j === 0 && !verifyAllSupportedMultiFunctions(currentPinName, allSupportedMultiFunctionsArray, mcu)) {
                    ok(false, 'Failed: Pin' + updatedPinName + ': ' + allSupportedMultiFunctionsString + ' was wrong. Please check it.');
                }
                else {
                    shownMessage = 'Pin' + updatedPinName + ': ' + innerTextPrimitive + ' checked. ' +
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

                    if (S('#G' + currentGPIORegister + '_MFP3').size() !== 0) {
                        tempString = S('#G' + currentGPIORegister + '_MFP3').text();
                        tempValue = parseInt(tempString.slice(tempString.indexOf('0x') + 2), 16);
                        if (tempValue > 0) {
                            raisedMFPRegisters.push(tempString);
                            shownMessage = shownMessage + ' ' + tempString;
                            if (typeof (tableContentArray[innerTextPrimitive]) === 'undefined') {
                                tableContentArray[innerTextPrimitive] = [];
                            }
                            tableContentArray[innerTextPrimitive].push('G' + currentGPIORegister + '_MFP3/' + tempValue);
                        }
                    }

                    if (S('#G' + currentGPIORegister + '_MFP2').size() !== 0) {
                        tempString = S('#G' + currentGPIORegister + '_MFP2').text();
                        tempValue = parseInt(tempString.slice(tempString.indexOf('0x') + 2), 16);
                        if (tempValue > 0) {
                            raisedMFPRegisters.push(tempString);
                            shownMessage = shownMessage + ' ' + tempString;
                            if (typeof (tableContentArray[innerTextPrimitive]) === 'undefined') {
                                tableContentArray[innerTextPrimitive] = [];
                            }
                            tableContentArray[innerTextPrimitive].push('G' + currentGPIORegister + '_MFP2/' + tempValue);
                        }
                    }

                    if (S('#G' + currentGPIORegister + '_MFP1').size() !== 0) {
                        tempString = S('#G' + currentGPIORegister + '_MFP1').text();
                        tempValue = parseInt(tempString.slice(tempString.indexOf('0x') + 2), 16);
                        if (tempValue > 0) {
                            raisedMFPRegisters.push(tempString);
                            shownMessage = shownMessage + ' ' + tempString;
                            if (typeof (tableContentArray[innerTextPrimitive]) === 'undefined') {
                                tableContentArray[innerTextPrimitive] = [];
                            }
                            tableContentArray[innerTextPrimitive].push('G' + currentGPIORegister + '_MFP1/' + tempValue);
                        }
                    }

                    if (S('#G' + currentGPIORegister + '_MFP0').size() !== 0) {
                        tempString = S('#G' + currentGPIORegister + '_MFP0').text();
                        tempValue = parseInt(tempString.slice(tempString.indexOf('0x') + 2), 16);
                        if (tempValue > 0) {
                            raisedMFPRegisters.push(tempString);
                            shownMessage = shownMessage + ' ' + tempString;
                            if (typeof (tableContentArray[innerTextPrimitive]) === 'undefined') {
                                tableContentArray[innerTextPrimitive] = [];
                            }
                            tableContentArray[innerTextPrimitive].push('G' + currentGPIORegister + '_MFP0/' + tempValue);
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

                    if (S('#IO' + currentGPIORegister + 'MD').size() !== 0) {
                        tempString = S('#IO' + currentGPIORegister + 'MD').text();
                        tempValue = parseInt(tempString.slice(tempString.indexOf('0x') + 2), 16);
                        if (tempValue > 0) {
                            raisedMFPRegisters.push(tempString);
                            shownMessage = shownMessage + ' ' + tempString;
                            if (typeof (tableContentArray[innerTextPrimitive]) === 'undefined') {
                                tableContentArray[innerTextPrimitive] = [];
                            }
                            tableContentArray[innerTextPrimitive].push('IO' + currentGPIORegister + 'MD/' + tempValue);
                        }
                    }

                    if (S('#' + currentFPSName + '_SEL').size() !== 0) {
                        tempString = S('#' + currentFPSName + '_SEL').text();
                        tempValue = parseInt(tempString.slice(tempString.indexOf('0x') + 2), 16);
                        if (tempValue > 0) {
                            raisedMFPRegisters.push(tempString);
                            shownMessage = shownMessage + ' ' + tempString;
                            if (typeof (tableContentArray[innerTextPrimitive]) === 'undefined') {
                                tableContentArray[innerTextPrimitive] = [];
                            }
                            tableContentArray[innerTextPrimitive].push(currentFPSName + '_SEL/' + tempValue);
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

            if (bModularizedBeReady && innerText.indexOf('Reset') === -1) {
                // get the Modularized code
                S.eval('NUTOOL_PIN.getModularizedDataUsedToCreateText();');
                tempString = S.eval('NUTOOL_PIN.retrieveGenerateCodeContent();');
                if (tempString.indexOf('did not generate modularized code!!') !== -1) {
                    ok(false, "Failed: " + tempString.slicePriorToX('<br />'));
                }
                document.body.innerHTML += tempString;
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

g_showErrorMessage = false;
function showErrorMessage(errorMessage) {
    ok(false, errorMessage);
    g_showErrorMessage = true;
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
        success: function (data) {
            ok(true, 'Node.js fs.writeFile ' + fileName + ' successfully');
        },
        error: function (xhr, status, error) {
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
        success: function (data) {
            ok(true, fileName + ' notified the PythonApp of the work finish successfully');
        },
        error: function (xhr, status, error) {
            var errorMessage = xhr.status;
            showErrorMessage(fileName + ' failed to notify the PythonApp/' + errorMessage);
        }
    });
}

(function mainTest() {
    var x,
        maxX,
        targetChips = [
            "MUG51/MUG51TC9AE(QFN33)"
        ],
        chipSeries,
        mcu = "",
        oldChipType = "",
        currentIndexForNode = 0,
        currentIndexForPin = 0,
        bEnableClickAllofTheNodes = true,
        bEnableClickAllofThePins = true,
        bEnableClickMFPRegisterNodes = false, // optional
        bEnableClickAllofTheNodesRandomly = false, // optional
        bEnableGenerateChipCSVFiles = false, // optional
        startNodeItem = 0, // 0 means that begin from the first node
        startPin = -1, // -1 means that begin from pin 1
        endPin = -1,   // -1 means that end at the last pin
        bCreateTable = false, // to decide whether to create the multi-function table
        bAlphabeticalOrder = true, // to arrange the tables in the alphabetical order
        bTooltipBeReady = true, // to decide whether to test the tooltip
        bModularizedBeReady = true, // to decide whether to test the modularized code
        NUC_Pin_Width = 18,    // this will be dependent on the real pin width displayed on the monitor. It must be integer and even number.
        NUC_Pin_Radius = 30,   // this will be dependent on the real pin width displayed on the monitor. It must be integer and even number.
        NUC_Pin_Interval = 14; // this will be dependent on the real pin width displayed on the monitor. It must be integer and even number.
    // decide what is testing
    if (bEnableGenerateChipCSVFiles) {
        bEnableClickAllofTheNodes = false;
        bEnableClickAllofThePins = false;
        bEnableClickMFPRegisterNodes = false;
        bEnableClickAllofTheNodesRandomly = false;
    }
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
                    FPSRegisters = [],
                    MFPRegisters = [],
                    ALTRegisterValue,
                    FPSRegisterValue,
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
                // for KM1M7CF: check how many FPS registers exist
                for (i = 0, max = 9; i <= max; i = i + 1) {
                    if (S('#FPSA0' + i + '_SEL').size() !== 0) {
                        FPSRegisters.push('#FPSA0' + i + '_SEL');
                    }
                    if (S('#FPSB0' + i + '_SEL').size() !== 0) {
                        FPSRegisters.push('#FPSB0' + i + '_SEL');
                    }
                }
                for (i = 10, max = 13; i <= max; i = i + 1) {
                    if (S('#FPSA' + i + '_SEL').size() !== 0) {
                        FPSRegisters.push('#FPSA' + i + '_SEL');
                    }
                }
                for (i = 10, max = 11; i <= max; i = i + 1) {
                    if (S('#FPSB' + i + '_SEL').size() !== 0) {
                        FPSRegisters.push('#FPSB' + i + '_SEL');
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
                    if (S('#IOP' + i + 'MD').size() !== 0) {
                        MFPRegisters.push('#IOP' + i + 'MD');
                    }
                    if (S('#P' + i + 'MF76543210').size() !== 0) {
                        MFPRegisters.push('#P' + i + 'MF76543210');
                    }
                }
                for (i = "A".charCodeAt(0), max = "X".charCodeAt(0); i <= max; i = i + 1) {
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
                    if (S('#GP' + String.fromCharCode(i) + '_MFP3').size() !== 0) {
                        MFPRegisters.push('#GP' + String.fromCharCode(i) + '_MFP3');
                    }
                    if (S('#GP' + String.fromCharCode(i) + '_MFP2').size() !== 0) {
                        MFPRegisters.push('#GP' + String.fromCharCode(i) + '_MFP2');
                    }
                    if (S('#GP' + String.fromCharCode(i) + '_MFP1').size() !== 0) {
                        MFPRegisters.push('#GP' + String.fromCharCode(i) + '_MFP1');
                    }
                    if (S('#GP' + String.fromCharCode(i) + '_MFP0').size() !== 0) {
                        MFPRegisters.push('#GP' + String.fromCharCode(i) + '_MFP0');
                    }
                    if (S('#P' + String.fromCharCode(i) + '_H_MFP').size() !== 0) {
                        MFPRegisters.push('#P' + String.fromCharCode(i) + '_H_MFP');
                    }
                    if (S('#P' + String.fromCharCode(i) + '_L_MFP').size() !== 0) {
                        MFPRegisters.push('#P' + String.fromCharCode(i) + '_L_MFP');
                    }
                    if (S('#IOP' + String.fromCharCode(i) + 'MD').size() !== 0) {
                        MFPRegisters.push('#IOP' + String.fromCharCode(i) + 'MD');
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

                for (i = startNodeItem, max = S('#moduleTree').children().children().length; i < max; i = i + 1) {
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
                            for (j = 0, maxJ = S('#moduleTree').children().children().eq(i).children().eq(2).children().length; j < maxJ; j = j + 1) {
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

                                for (k = 0, maxK = FPSRegisters.length; k < maxK; k = k + 1) {
                                    FPSRegisterValue = S(FPSRegisters[k]).text();
                                    if (parseInt(FPSRegisterValue.slice(FPSRegisterValue.indexOf('0x') + 2), 16) > 0) {
                                        raisedMFPRegisters.push(FPSRegisterValue);
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
                    for (j = 0, maxJ = S('#moduleTree').children().children().eq(i).children().eq(2).children().length; j < maxJ; j = j + 1) {
                        TreeNodeId = S('#moduleTree').children().children().eq(i).children().eq(2).children().eq(j)[0].id;

                        if (TreeNodeId.indexOf('_Intermediate') === -1) {
                            S.eval('$("#moduleTree").jstree("check_node", $("#' + TreeNodeId + '"));');

                            TreeNode = TreeNodeId.slice(0, TreeNodeId.indexOf('_Pin'));
                            currentPin = TreeNodeId.slice(TreeNodeId.indexOf('_Pin') + 4);
                            currentPin = S.eval('NUTOOL_PIN.updatePinName("' + currentPin + '");');

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
                            for (m = 0, maxM = S('#moduleTree').children().children().eq(i).children().eq(2).children().eq(j).children().eq(2).children().length; m < maxM; m = m + 1) {
                                TreeNodeId = S('#moduleTree').children().children().eq(i).children().eq(2).children().eq(j).children().eq(2).children().eq(m)[0].id;

                                S.eval('$("#moduleTree").jstree("check_node", $("#' + TreeNodeId + '"));');

                                TreeNode = TreeNodeId.slice(0, TreeNodeId.indexOf('_Pin'));
                                currentPin = TreeNodeId.slice(TreeNodeId.indexOf('_Pin') + 4);
                                currentPin = S.eval('NUTOOL_PIN.updatePinName("' + currentPin + '");');

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
                    NUC_Pin_Total_Number = 0,
                    NUC_Pin_Down_Number = 0,
                    NUC_Pin_Right_Number = 0,
                    NUC_Pin_Upper_Number = 0,
                    NUC_Pin_Left_Number = 0,
                    NUC_Pin_Horizontal_Number = 0,
                    NUC_Pin_Vertial_Number = 0,
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
                if (Math.sqrt(NUC_Pin_Total_Number) % 1 !== 0) {
                    NUTOOL_PIN.decidepackageNumber(mcu);
                    NUC_Pin_Total_Number = NUTOOL_PIN.g_packageNumber;
                    NUC_Pin_Total_Number = parseInt(NUC_Pin_Total_Number.slice(NUC_Pin_Total_Number.indexOf(NUC_Pin_Total_Number.match(/\d/))), 10);
                }
                NUC_Pin_Horizontal_Number = NUC_Pin_Vertial_Number = Math.sqrt(NUC_Pin_Total_Number);
                // since QFP33 has virtually 32 pins
                if (NUC_Pin_Total_Number === 33) {
                    NUC_Pin_Total_Number = 32;
                }
                NUTOOL_PIN.decidepackageNumber(mcu);
                if (NUTOOL_PIN.g_packageNumberIndex.toLowerCase().indexOf('pin:') !== -1) {
                    NUC_Pin_Down_Number = parseInt(NUTOOL_PIN.g_packageNumberIndex.sliceBetweenXandX('D', 'R'), 10);
                    NUC_Pin_Right_Number = parseInt(NUTOOL_PIN.g_packageNumberIndex.sliceBetweenXandX('R', 'U'), 10);
                    NUC_Pin_Upper_Number = parseInt(NUTOOL_PIN.g_packageNumberIndex.sliceBetweenXandX('U', 'L'), 10);
                    NUC_Pin_Left_Number = parseInt(NUTOOL_PIN.g_packageNumberIndex.sliceBetweenXandX('L', ')'), 10);
                }
                else {
                    NUC_Pin_Down_Number = NUC_Pin_Total_Number / 4;
                    NUC_Pin_Right_Number = NUC_Pin_Total_Number / 4;
                    NUC_Pin_Upper_Number = NUC_Pin_Total_Number / 4;
                    NUC_Pin_Left_Number = NUC_Pin_Total_Number / 4;
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
                if (S("#MCUselect").val().indexOf('SOP') !== -1) {
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
                                operationsAfterMouseMove('#pin_side_0', currentPin, ALTRegisters, mcu, bCreateTable, bAlphabeticalOrder, bTooltipBeReady, bModularizedBeReady);
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
                                operationsAfterMouseMove('#pin_side_1', currentPin, ALTRegisters, mcu, bCreateTable, bAlphabeticalOrder, bTooltipBeReady, bModularizedBeReady);
                                currentPin = currentPin + 1;
                            });
                        }
                    }
                }
                else if (S("#MCUselect").val().indexOf('WLCSP') !== -1 || S("#MCUselect").val().indexOf('BGA') !== -1) {
                    for (i = startPin - 1, max = endPin; i < max; i = i + 1) {
                        // click all of the pins
                        // inside
                        if ((NUC_Pin_Horizontal_Number) % 2 === 0) {
                            moveLength = Math.floor(NUC_Pin_Horizontal_Number / 2) - 1;
                            moveLength = (Math.floor(i / NUC_Pin_Vertial_Number) - moveLength) * (NUC_Pin_Radius * 2 + NUC_Pin_Interval) - (NUC_Pin_Radius * 2 + NUC_Pin_Interval) / 2;
                        }
                        else {
                            moveLength = Math.floor(NUC_Pin_Horizontal_Number / 2);
                            moveLength = (Math.floor(i / NUC_Pin_Vertial_Number) - moveLength) * (NUC_Pin_Radius * 2 + NUC_Pin_Interval);
                        }
                        if (moveLength >= 0) {
                            clickLocationString = '+' + Math.abs(moveLength);
                        }
                        else {
                            clickLocationString = '-' + Math.abs(moveLength);
                        }

                        if (NUC_Pin_Vertial_Number % 2 === 0) {
                            moveLength = Math.floor(NUC_Pin_Vertial_Number / 2) - 1;
                            moveLength = (i % NUC_Pin_Vertial_Number - moveLength) * (NUC_Pin_Radius * 2 + NUC_Pin_Interval) - (NUC_Pin_Radius * 2 + NUC_Pin_Interval) / 2;
                        }
                        else {
                            moveLength = Math.floor(NUC_Pin_Vertial_Number / 2);
                            moveLength = (i % NUC_Pin_Vertial_Number - moveLength) * (NUC_Pin_Radius * 2 + NUC_Pin_Interval);
                        }
                        if (moveLength >= 0) {
                            clickLocationString += ' -' + Math.abs(moveLength);
                        }
                        else {
                            clickLocationString += ' +' + Math.abs(moveLength);
                        }
                        S('#pin_side_0').move(clickLocationString).then(function () {
                            operationsAfterMouseMove('#pin_side_0', currentPin, ALTRegisters, mcu, bCreateTable, bAlphabeticalOrder, bTooltipBeReady, bModularizedBeReady);
                            currentPin = currentPin + 1;
                        });
                    }
                }
                else {
                    for (i = startPin - 1, max = endPin; i < max; i = i + 1) {
                        // click all of the pins
                        // down side
                        if (i < NUC_Pin_Down_Number) {
                            if ((NUC_Pin_Down_Number) % 2 === 0) {
                                moveLength = Math.floor(NUC_Pin_Down_Number / 2) - 1;
                                moveLength = (i - moveLength) * NUC_Pin_Width - NUC_Pin_Width / 2;
                            }
                            else {
                                moveLength = Math.floor(NUC_Pin_Down_Number / 2);
                                moveLength = (i - moveLength) * NUC_Pin_Width;
                            }

                            if (moveLength >= 0) {
                                clickLocationString = '+' + Math.abs(moveLength) + ' +0';
                            }
                            else {
                                clickLocationString = '-' + Math.abs(moveLength) + ' +0';
                            }
                            S('#pin_side_0').move(clickLocationString).then(function () {
                                operationsAfterMouseMove('#pin_side_0', currentPin, ALTRegisters, mcu, bCreateTable, bAlphabeticalOrder, bTooltipBeReady, bModularizedBeReady);
                                currentPin = currentPin + 1;
                            });
                        }
                        // right side
                        else if (i >= NUC_Pin_Down_Number && i < NUC_Pin_Down_Number + NUC_Pin_Right_Number) {
                            if ((NUC_Pin_Right_Number) % 2 === 0) {
                                moveLength = NUC_Pin_Down_Number + Math.floor(NUC_Pin_Right_Number / 2) - 1;
                                moveLength = (i - moveLength) * NUC_Pin_Width - NUC_Pin_Width / 2;
                            }
                            else {
                                moveLength = NUC_Pin_Down_Number + Math.floor(NUC_Pin_Right_Number / 2);
                                moveLength = (i - moveLength) * NUC_Pin_Width;
                            }

                            if (moveLength >= 0) {
                                clickLocationString = '+0 -' + Math.abs(moveLength);
                            }
                            else {
                                clickLocationString = '+0 +' + Math.abs(moveLength);
                            }

                            S('#pin_side_1').move(clickLocationString).then(function () {
                                operationsAfterMouseMove('#pin_side_1', currentPin, ALTRegisters, mcu, bCreateTable, bAlphabeticalOrder, bTooltipBeReady, bModularizedBeReady);
                                currentPin = currentPin + 1;
                            });
                        }
                        // upper side
                        else if (i >= NUC_Pin_Down_Number + NUC_Pin_Right_Number && i < NUC_Pin_Down_Number + NUC_Pin_Right_Number + NUC_Pin_Upper_Number) {
                            if ((NUC_Pin_Upper_Number) % 2 === 0) {
                                moveLength = NUC_Pin_Down_Number + NUC_Pin_Right_Number + Math.floor(NUC_Pin_Upper_Number / 2) - 1;
                                moveLength = (i - moveLength) * NUC_Pin_Width - NUC_Pin_Width / 2;
                            }
                            else {
                                moveLength = NUC_Pin_Down_Number + NUC_Pin_Right_Number + Math.floor(NUC_Pin_Upper_Number / 2);
                                moveLength = (i - moveLength) * NUC_Pin_Width;
                            }

                            if (moveLength >= 0) {
                                clickLocationString = '-' + Math.abs(moveLength) + ' +0';
                            }
                            else {
                                clickLocationString = '+' + Math.abs(moveLength) + ' +0';
                            }

                            S('#pin_side_2').move(clickLocationString).then(function () {
                                operationsAfterMouseMove('#pin_side_2', currentPin, ALTRegisters, mcu, bCreateTable, bAlphabeticalOrder, bTooltipBeReady, bModularizedBeReady);
                                currentPin = currentPin + 1;
                            });
                        }
                        // left side
                        else {
                            if ((NUC_Pin_Left_Number) % 2 === 0) {
                                moveLength = NUC_Pin_Down_Number + NUC_Pin_Right_Number + NUC_Pin_Upper_Number + Math.floor(NUC_Pin_Left_Number / 2) - 1;
                                moveLength = (i - moveLength) * NUC_Pin_Width - NUC_Pin_Width / 2;
                            }
                            else {
                                moveLength = NUC_Pin_Down_Number + NUC_Pin_Right_Number + NUC_Pin_Upper_Number + Math.floor(NUC_Pin_Left_Number / 2);
                                moveLength = (i - moveLength) * NUC_Pin_Width;
                            }

                            if (moveLength >= 0) {
                                clickLocationString = '+0 +' + Math.abs(moveLength);
                            }
                            else {
                                clickLocationString = '+0 -' + Math.abs(moveLength);
                            }

                            S('#pin_side_3').move(clickLocationString).then(function () {
                                operationsAfterMouseMove('#pin_side_3', currentPin, ALTRegisters, mcu, bCreateTable, bAlphabeticalOrder, bTooltipBeReady, bModularizedBeReady);
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
                    FPSRegisters = [],
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
                // for KM1M7CF: check how many FPS registers exist
                for (i = 0, max = 9; i <= max; i = i + 1) {
                    if (S('#FPSA0' + i + '_SEL').size() !== 0) {
                        FPSRegisters.push('#FPSA0' + i + '_SEL');
                    }
                    if (S('#FPSB0' + i + '_SEL').size() !== 0) {
                        FPSRegisters.push('#FPSB0' + i + '_SEL');
                    }
                }
                for (i = 10, max = 13; i <= max; i = i + 1) {
                    if (S('#FPSA' + i + '_SEL').size() !== 0) {
                        FPSRegisters.push('#FPSA' + i + '_SEL');
                    }
                }
                for (i = 10, max = 11; i <= max; i = i + 1) {
                    if (S('#FPSB' + i + '_SEL').size() !== 0) {
                        FPSRegisters.push('#FPSB' + i + '_SEL');
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
                    if (S('#IOP' + i + 'MD').size() !== 0) {
                        MFPRegisters.push('#IOP' + i + 'MD');
                    }
                    if (S('#P' + i + 'MF76543210').size() !== 0) {
                        MFPRegisters.push('#P' + i + 'MF76543210');
                    }
                }
                for (i = "A".charCodeAt(0), max = "X".charCodeAt(0); i <= max; i = i + 1) {
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
                    if (S('#GP' + String.fromCharCode(i) + '_MFP1').size() !== 0) {
                        MFPRegisters.push('#GP' + String.fromCharCode(i) + '_MFP1');
                    }
                    if (S('#GP' + String.fromCharCode(i) + '_MFP0').size() !== 0) {
                        MFPRegisters.push('#GP' + String.fromCharCode(i) + '_MFP0');
                    }
                    if (S('#P' + String.fromCharCode(i) + '_H_MFP').size() !== 0) {
                        MFPRegisters.push('#P' + String.fromCharCode(i) + '_H_MFP');
                    }
                    if (S('#P' + String.fromCharCode(i) + '_L_MFP').size() !== 0) {
                        MFPRegisters.push('#P' + String.fromCharCode(i) + '_L_MFP');
                    }
                    if (S('#IOP' + String.fromCharCode(i) + 'MD').size() !== 0) {
                        MFPRegisters.push('#IOP' + String.fromCharCode(i) + 'MD');
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

                // for ISD9100 and ISD9300
                if (mcu.indexOf('I91') !== -1 || mcu.indexOf('I93') !== -1) {
                    shiftBitUnit = 2;
                }
                // 如果一次占8個bit的就要用這個
                else if (mcu.indexOf('M0A2') === 0 || mcu.indexOf('M46') === 0 || mcu.indexOf('M2L31') === 0 || mcu.indexOf('M55M1') === 0) {
                    shiftBitUnit = 8;
                }
                else {
                    shiftBitUnit = 4;
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
                for (k = 0, maxK = MFPRegisters.length; k < maxK; k = k + 1) {
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
                                        ok(true, 'Input ' + MFPRegisterValue + ':0x' + decimalToHex(registerValue).toUpperCase() + ' Expected: ' + pinName + ' Result: ' + innerText);
                                    }
                                    else if (lastMatchedMFPvalue === matchedMFPvalue) {
                                        ok(true, 'Input ' + MFPRegisterValue + ':0x' + decimalToHex(registerValue).toUpperCase() + ' Expected: ' + pinName + ' Result: ' + innerText + ' Identical MFP value:' + matchedMFPvalue);
                                    }
                                    else {
                                        ok(false, 'Input ' + MFPRegisterValue + ':0x' + decimalToHex(registerValue).toUpperCase() + ' Expected: ' + pinName + ' Result: ' + innerText);
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

                for (i = 0, max = S('#moduleTree').children().children().length; i < max; i = i + 1) {
                    TreeNodeId = S('#moduleTree').children().children().eq(i)[0].id;
                    TreeNodeIdArray.push(TreeNodeId);
                    for (j = 0, maxJ = S('#moduleTree').children().children().eq(i).children().eq(2).children().length; j < maxJ; j = j + 1) {
                        TreeNodeIdArray.push(TreeNodeId);
                        TreeNodeId = S('#moduleTree').children().children().eq(i).children().eq(2).children().eq(j)[0].id;
                        if (TreeNodeId.indexOf('_Intermediate') === -1) {
                            TreeNodeIdArray.push(TreeNodeId);
                        }
                        else {
                            TreeNodeIdArray.push(TreeNodeId);
                            for (m = 0, maxM = S('#moduleTree').children().children().eq(i).children().eq(2).children().eq(j).children().eq(2).children().length; m < maxM; m = m + 1) {
                                TreeNodeId = S('#moduleTree').children().children().eq(i).children().eq(2).children().eq(j).children().eq(2).children().eq(m)[0].id;
                                TreeNodeIdArray.push(TreeNodeId);
                            }
                        }
                    }
                }

                for (i = 0, max = Math.floor(TreeNodeIdArray.length * homManyLoops); i < max; i = i + 1) {
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

        if (bEnableGenerateChipCSVFiles) {
            test("Generate Chip CSV Files", function () {
                var i,
                    j,
                    m,
                    max,
                    maxJ,
                    maxM,
                    mcuArray = [],
                    localQueryParams = {},
                    localChipSeriesArray = [],
                    localChipSeriesTable = {
                        'M031': ['M031', 'M031G', 'M031I', 'M031KM', 'M031BT'],
                        'M051': ['M051DN_DE', 'M058S'],
                        'M451': ['M451HD', 'M451LD', 'M4521'],
                        'M480': ['M480', 'M480LD'],
                        'M0564': ['M0564', 'M05641'],
                        'MINI51': ['MINI51DE', 'MINI55', 'MINI57', 'MINI58'],
                        'MS51': ['MS51_8K', 'MS51_8KDB', 'MS51_16K', 'MS51_32K'],
                        'NANO100': ['NANO100AN', 'NANO100BN', 'NANO103', 'NANO112'],
                        'NUC029': ['NUC029AE', 'NUC029AN', 'NUC029KGE', 'NUC029TAE', 'NUC029xDE', 'NUC029xEE', 'NUC029xGE', 'NUC029ZAN'],
                        'NUC100': ['NUC100CN', 'NUC100DN', 'NUC121AE', 'NUC123AE', 'NUC123AN', 'NUC126', 'NUC131', 'NUC1261', 'NUC1311'],
                        'NUC200': ['NUC200AN', 'NUC200AE', 'NUC2201']
                    },
                    localData,
                    currentDate,
                    dateTime,
                    sendAjaxRequestData = '',
                    bFound = false,
                    bshowErrorMessage = false;

                S.eval('NUTOOL_PIN.g_bFunctionalTesting = true;');
                // decide chipSeries and mcu
                localQueryParams = JSON.parse($.ajax({ url: 'FunctionalTesting/csvGenerator.txt', async: false }).responseText.replace(/\r/g, ""));
                if (typeof localQueryParams.chipSeries !== 'undefined') {
                    chipSeries = localQueryParams.chipSeries.toString().toUpperCase();
                    // decide Test Time
                    currentDate = new Date();
                    dateTime = "Test Time: " + currentDate.getDate() + "/" + (currentDate.getMonth() + 1) + "/" + currentDate.getFullYear() + " at " + currentDate.getHours() + ":" + currentDate.getMinutes() + ":" + currentDate.getSeconds();
                    ok(true, 'Chip Series: ' + chipSeries + ' ' + dateTime);

                    if (typeof localChipSeriesTable[chipSeries] !== 'undefined') {
                        localChipSeriesArray = localChipSeriesTable[chipSeries];
                    }
                    else {
                        localChipSeriesArray.push(chipSeries);
                    }
                    for (m = 0, maxM = localChipSeriesArray.length; m < maxM; m = m + 1) {
                        loadjscssFile('NUC_' + localChipSeriesArray[m] + '_Content.js', "js");
                        if (typeof localQueryParams.partNumber !== 'undefined') {
                            mcuArray = localQueryParams.partNumber.toString().toUpperCase().split('+');
                        }
                        else {
                            showErrorMessage('Failed: Something wrong in the partNumber field of csvGenerator.txt.');
                            bshowErrorMessage = true;
                        }
                        if (S("#ChipTypeSelect").val() !== chipSeries) {
                            S.eval('NUTOOL_PIN.g_bModuleTreeLoaded = false;');
                            S.eval('$("#ChipTypeSelect").val("' + chipSeries + '").change();');
                            while (!S.eval('NUTOOL_PIN.g_bModuleTreeLoaded')) { /*waiting*/ }
                        }
                        if (mcuArray[0] === 'ALL') {
                            for (j = 0, maxJ = NUTOOL_PIN.g_cfg_chips.length; j < maxJ; j += 1) {
                                mcu = NUTOOL_PIN.g_cfg_chips[j].name + '(' + NUTOOL_PIN.g_cfg_chips[j].pkg + ')';
                                if (S.eval('NUTOOL_PIN.decideNewChipType("' + mcu + '");') === localChipSeriesArray[m]) {
                                    if (S("#MCUselect").val() !== mcu) {
                                        S.eval('NUTOOL_PIN.g_bModuleTreeLoaded = false;');
                                        S.eval('$("#MCUselect").val("' + mcu + '").change();');
                                        while (!S.eval('NUTOOL_PIN.g_bModuleTreeLoaded')) { /*waiting*/ }
                                    }
                                    S.eval('NUTOOL_PIN.get_pin_descriptions();');
                                    sendAjaxRequestData += '//fileName:' + NUTOOL_PIN.g_cfg_chips[j].name + '.csv\n';
                                    sendAjaxRequestData += 'MCU:' + mcu + '\n';
                                    sendAjaxRequestData += S.eval('NUTOOL_PIN.getg_pin_descriptions();');
                                }
                            }
                        }
                        else {
                            for (i = 0, max = mcuArray.length; i < max; i = i + 1) {
                                mcu = mcuArray[i];
                                bFound = false;
                                for (j = 0, maxJ = NUTOOL_PIN.g_cfg_chips.length; j < maxJ; j += 1) {
                                    if (NUTOOL_PIN.g_cfg_chips[j].name === mcu) {
                                        mcu = NUTOOL_PIN.g_cfg_chips[j].name + '(' + NUTOOL_PIN.g_cfg_chips[j].pkg + ')';
                                        bFound = true;
                                        break;
                                    }
                                }
                                if (S.eval('NUTOOL_PIN.decideNewChipType("' + mcu + '");') === localChipSeriesArray[m]) {
                                    if (bFound) {
                                        if (S("#MCUselect").val() !== mcu) {
                                            S.eval('NUTOOL_PIN.g_bModuleTreeLoaded = false;');
                                            S.eval('$("#MCUselect").val("' + mcu + '").change();');
                                            while (!S.eval('NUTOOL_PIN.g_bModuleTreeLoaded')) { /*waiting*/ }
                                        }
                                        S.eval('NUTOOL_PIN.get_pin_descriptions();');
                                        sendAjaxRequestData += '//fileName:' + NUTOOL_PIN.g_cfg_chips[j].name + '.csv\n';
                                        sendAjaxRequestData += 'MCU:' + mcu + '\n';
                                        sendAjaxRequestData += S.eval('NUTOOL_PIN.getg_pin_descriptions();');
                                    }
                                    else {
                                        showErrorMessage('Failed: Something wrong in the partNumber field of csvGenerator.txt.');
                                    }
                                }
                            }
                        }
                    }
                }
                else {
                    showErrorMessage('Failed: Something wrong in the chipSeries field of csvGenerator.txt.');
                }
                localData = '';
                if (g_showErrorMessage) {
                    localData = 'showErrorMessage;';
                }
                sendAjaxRequest('AllData.csv', sendAjaxRequestData);
                sendAjaxRequestToPythonApp(chipSeries, localData + 'shutdown');
            });
        }
    } // for (x = 0, maxX = targetChips.length; x < maxX; x = x + 1) {
}(NUTOOL_PIN, this));
