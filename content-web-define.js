// main code of NuTool - IpConfigure
// the sole global variable denoted by capital letters
var NUTOOL_PIN = {};


// main code of NuTool - ClockConfigure
// the sole global variable denoted by capital letters
var NUTOOL_CLOCK = {};


// main code of NuTool - Peripheral
// the sole global variable denoted by capital letters
var NUTOOL_PER = {};

// all the global variables within the immediately-invoked function scope
var //
    // g_bLessThanOrEqualIE8,
    // g_unPrintedCharacters,
    // g_utility = {
    //     getContext: null,
    //     removeContext: null,
    //     addEvent: null,
    //     triggerEvent: null
    // },
    // g_NUC_TreeView_Width = 0,
    // g_Dialog_Width,
    // g_Dialog_Height,
    g_chipTypes = ["M251", "M253", "M031", "NUC100"],
    // g_chipTypesDeveloping = ["M030G", "DEMO"],
    g_chipType = "",
    // g_updatedSnippetFile = "",
    // g_selectedPartNoValue = "",
    g_partNumber_package = "",
    g_partNumber_type = "",
    g_supportedGPIOPins = {},
    // g_userHeader = "",
    // g_generatedCodeFromPerString = "",
    // g_enabledThirdPartyLibString = "",
    // g_enabledPeripheralFunctionString = "",
    // g_currentSnippetFilePath = "",
    // g_currentSnippetLayoutath = "",                      No use
    // g_lastCheckedSnippetNode = "",
    g_currentTool = "PeripheralConfigure",
    g_groupIds = {},
    g_recordedIds = {},
    g_perControls = {},
    // g_enabledThirdPartyLibNodes = [],
    // g_enabledPeripheralFunctionNodes = [],
    g_enabledPeripheralFunctionData = {},
    // g_field1SubDIVs = [],
    // g_field1SubDIVsCache = {},
    // g_module_snippet = [],
    // g_module_snippet_primitive = [],
    // g_module_snippet_buttonId = [],
    // g_module_snippet_code = [],
    // g_module_snippet_header = [],
    // g_module_snippet_pin = [],
    // g_module_snippet_clock = [],
    // g_module_snippet_peripheral = [],
    // g_alpacaFormRepository = [],
    // g_object = {},
    // g_toast_pin,
    // g_toast_clock,
    // g_toast_peripheral,
    // g_alpacaFormIndex = 0,
    // g_field1SubIndex = 0,
    // g_thirdPartyLibTreeHeight = 0,
    // g_readConfigFile,
    // g_userSelectUIlanguage,
    g_bReadyForRelease = true; // should be true For Release
    // g_bDevelopingTool = true,  // should be false For Release
    // g_bPressEnter = false,
    // g_bInvokedByCDHtmlDialog = true,
    // g_bAlpacaValidationResult = true,
    // g_bCheckNodesBasedOnConfigFile = true;





// Only web version use!!!
var g_bWebVersion = true;
var g_snippetName = "";
var g_perControlsFilter = {}