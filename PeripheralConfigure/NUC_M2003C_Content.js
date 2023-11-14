// chip content
NUTOOL_PER.g_cfg_chips = [
    { name: "M2003FC1AE", pkg: "TSSOP20" },
    // { name: "M2003FC1AE", pkg: "QFN20" },
    { name: "M2003XC1AE", pkg: "QFN20" }
    // { name: "M2003FC1BE", pkg: "QFN20" },

    // { name: "M2003EC1AE", pkg: "TSSOP28" },
    // { name: "M2003PC1AE", pkg: "LQFP32 32K" },
    // { name: "M2003PE3AE", pkg: "LQFP32 128K" },

    // { name: "M2003TC1AE", pkg: "QFN33 32K" },
    // { name: "M2003TE3AE", pkg: "QFN33 128K" },
    // { name: "M2003LE3AE", pkg: "LQFP48" },
    // { name: "M2003SE3AE", pkg: "LQFP64" },
];

NUTOOL_PER.g_cfg_unusedPerFunctions = {

}

// NUTOOL_PER.g_cfg_downloadBSP = {
//     repository: "NUC1262BSP",
//     commitID: {
//         "V0.41.0015": "3a8d8219022709f8cb76d71aa0d4127177d99454"
//     }
// }

// relative to the location of the directory containing tags
NUTOOL_PER.g_cfg_projectLoaction = "\\NuCodeGenProj";
NUTOOL_PER.g_cfg_thidrPartyLibLoaction = "";
NUTOOL_PER.g_cfg_thirdPartyLibs = [];
NUTOOL_PER.g_cfg_perFuncMutex = ["USCI0"];
// if you want to dynamically load .txt files, keep this array empty.
NUTOOL_PER.g_cfg_perFunctions = [
'FMC.txt',
'I2C0.txt',
];