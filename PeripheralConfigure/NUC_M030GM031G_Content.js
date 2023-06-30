// chip content
NUTOOL_PER.g_cfg_chips = [
	// M030GM031G
	{ name: "M030GGD1AE", pkg: "QFN24" },
	{ name: "M030GGC1AE", pkg: "QFN24" },
	{ name: "M030GTC1AE", pkg: "QFN33" },
	{ name: "M030GTD1AE", pkg: "QFN33" },
	{ name: "M031GGD2AE", pkg: "QFN24" },
	{ name: "M031GGC2AE", pkg: "QFN24" },
	{ name: "M031GTD2AE", pkg: "QFN33" },
	{ name: "M031GTC2AE", pkg: "QFN33" }
];

NUTOOL_PER.g_cfg_unusedPerFunctions = {}
NUTOOL_PER.g_cfg_downloadBSP = {
    repository: "M030GBSP",
    commitID: {
        "V0.41.0006": "b8837adb0dc1a7e075c0d66473d0509a460c2254"
    }
}

// relative to the location of the directory containing tags
NUTOOL_PER.g_cfg_projectLoaction = {
	'ByDefault':  '\\NuCodeGenProj'
};

NUTOOL_PER.g_cfg_thidrPartyLibLoaction = "";
NUTOOL_PER.g_cfg_thirdPartyLibs = [];
NUTOOL_PER.g_cfg_perFuncMutex = [];
// if you want to dynamically load .txt files, keep this array empty.
NUTOOL_PER.g_cfg_perFunctions = [];
