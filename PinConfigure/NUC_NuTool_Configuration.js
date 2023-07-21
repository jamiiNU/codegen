// Please keep this file synchronization between ipConfig, Clock Config and CodeGen.
Function.prototype.method = function (name, func) {
    if (!this.prototype[name]) {
        this.prototype[name] = func;
    }
    return this;
};

Number.method('toHzString', function () {
    var returnHzString;

    if (this >= 1000000) {
        returnHzString = (this / 1000000 % 1 === 0) ? (this / 1000000).toFixed(0) + 'MHz' : parseFloat((this / 1000000).toFixed(4)) + 'MHz';
    }
    else if (this < 1000000 && this >= 1000) {
        returnHzString = (this / 1000 % 1 === 0) ? (this / 1000).toFixed(0) + 'kHz' : parseFloat((this / 1000).toFixed(4)) + 'kHz';
    }
    else if (this === 0) {
        returnHzString = 'Disabled';
    }
    else { // Hz
        returnHzString = (this % 1 === 0) ? this.toFixed(0) + 'Hz' : parseFloat(this.toFixed(4)) + 'Hz';
    }

    return returnHzString;
});

String.method('toFloat', function () {
    var returnFloatValue;
    if (this.indexOf('kHz') !== -1) {
        returnFloatValue = parseFloat(this.slice(0, this.length - 3)) * 1000;
    }
    else if (this.indexOf('MHz') !== -1) {
        returnFloatValue = parseFloat(this.slice(0, this.length - 3)) * 1000000;
    }
    else { // Hz
        returnFloatValue = parseFloat(this.slice(0, this.length - 2));
    }
    return returnFloatValue; // Note: the type of returned result will be Object, not String.
});

String.method('toEquivalent', function () {
    var returnName;

    returnName = this;
    if (typeof NUTOOL_CLOCK.g_equivalentName[this] !== 'undefined') {
        returnName = NUTOOL_CLOCK.g_equivalentName[this];
    }
    return returnName; // Note: the type of returned result will be Object, not String.
});

String.method('slicePriorToX', function (xChar) {
    var returnValue;
    if (this.indexOf(xChar) !== -1) {
        returnValue = this.slice(0, this.indexOf(xChar));
    }
    else {
        returnValue = this;
    }

    return returnValue; // Note: the type of returned result will be Object, not String.
});

String.method('slicePriorToLastX', function (xChar) {
    var returnValue;
    if (this.lastIndexOf(xChar) > 0) {
        returnValue = this.slice(0, this.lastIndexOf(xChar));
    }
    else {
        returnValue = this;
    }

    return returnValue; // Note: the type of returned result will be Object, not String.
});

String.method('sliceAfterX', function (xChar) {
    var returnValue;
    if (this.indexOf(xChar) >= 0) {
        returnValue = this.slice(this.indexOf(xChar) + xChar.length);
    }
    else {
        returnValue = this;
    }

    return returnValue; // Note: the type of returned result will be Object, not String.
});

String.method('sliceBetweenXandX', function (xChar, xChar1) {
    var returnValue;
    if (this.indexOf(xChar) !== -1 && this.indexOf(xChar1) !== -1) {
        returnValue = this.slice(this.indexOf(xChar) + xChar.length, this.indexOf(xChar1));
    }
    else {
        returnValue = this;
    }

    return returnValue; // Note: the type of returned result will be Object, not String.
});
// since jstree's selector does not recognize the special character, such as '.' and '+',
// we must replace them with other suitable one
String.method('replaceSpecialCharacters', function () {
    var returnValue;

    returnValue = this.toString().replace(/\+/g, '_add');
    returnValue = returnValue.toString().replace(/\./g, '_dot');
    returnValue = returnValue.toString().replace(/\[/g, 'PriorBracket');
    returnValue = returnValue.toString().replace(/\]/g, 'EndBracket');
    returnValue = returnValue.toString().replace(/\-/g, 'Dash');
    //returnValue = returnValue.replace('/', 'Slash');

    return returnValue; // Note: the type of returned result will be Object, not String
});

String.method('restoreSpecialCharacters', function () {
    var returnValue;

    returnValue = this.toString().replace(/_add/g, '+');
    returnValue = returnValue.toString().replace(/_dot/g, '.');
    returnValue = returnValue.toString().replace(/PriorBracket/g, '[');
    returnValue = returnValue.toString().replace(/EndBracket/g, ']');
    returnValue = returnValue.toString().replace(/Dash/g, '-');
    //returnValue = returnValue.replace('Slash', '/');

    return returnValue; // Note: the type of returned result will be Object, not String
});

String.method('restorePinTreeNodeName', function () {
    var i,
        max,
        replacedWords = ['_Pin', '_Intermediate', '_Root'],
        returnValue = this;

    for (i = 0, max = replacedWords.length; i < max; i += 1) {
        if (returnValue.indexOf(replacedWords[i]) !== -1) {
            returnValue = returnValue.slice(0, returnValue.indexOf(replacedWords[i]));
        }
    }

    return returnValue; // Note: the type of returned result will be Object, not String
});
// attach the .compare method to Array's prototype to call it on any array
Array.method('compare', function (array) {
    var i, l;
    // if the other array is a false value, return
    if (!array) {
        return false;
    }

    // compare lengths - can save a lot of time
    if (this.length !== array.length) {
        return false;
    }

    for (i = 0, l = this.length; i < l; i++) {
        // Check if we have nested arrays
        if (this[i] instanceof Array && array[i] instanceof Array) {
            // recurse into the nested arrays
            if (!this[i].compare(array[i])) {
                return false;
            }
        }
        else if (this[i] != array[i]) {
            // Warning - two different object instances will never be equal: {x:20} != {x:20}
            return false;
        }
    }
    return true;
});
// attach the .equals method to Array's prototype to call it on any array
Array.method('equals', function (array) {
    // if the other array is a false value, return
    if (!array) { return false; }

    // compare lengths - can save a lot of time
    if (this.length != array.length) { return false; }

    for (var i = 0, l = this.length; i < l; i++) {
        // Check if we have nested arrays
        if (this[i] instanceof Array && array[i] instanceof Array) {
            // recurse into the nested arrays
            if (!this[i].equals(array[i])) { return false; }
        }
        else if (this[i] != array[i]) {
            // Warning - two different object instances will never be equal: {x:20} != {x:20}
            return false;
        }
    }
    return true;
});
// for IE8 compatibility
if (typeof String.prototype.trim !== 'function') {
    String.prototype.trim = function () {
        return this.replace(/^\s+|\s+$/g, '');
    };
}

if (typeof Array.prototype.indexOf !== 'function') {
    Array.prototype.indexOf = function (elt /*, from*/) {
        var len = this.length >>> 0;

        var from = Number(arguments[1]) || 0;
        from = (from < 0)
            ? Math.ceil(from)
            : Math.floor(from);
        if (from < 0)
            from += len;

        for (; from < len; from++) {
            if (from in this &&
                this[from] === elt)
                return from;
        }
        return -1;
    };
}
