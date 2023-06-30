// chip content
NUTOOL_PER.g_cfg_chips = [
	//NUC1262
	{ name: "NUC1262NE4AE", pkg: "QFN48" },
	{ name: "NUC1262LE4AE", pkg: "LQFP48" },
	{ name: "NUC1262SE4AE", pkg: "LQFP64" },
];

NUTOOL_PER.g_cfg_unusedPerFunctions = {

}

NUTOOL_PER.g_cfg_downloadBSP = {
    repository: "NUC1262BSP",
    commitID: {
        "V0.41.0015": "3a8d8219022709f8cb76d71aa0d4127177d99454"
    }
}

// relative to the location of the directory containing tags
NUTOOL_PER.g_cfg_projectLoaction = "\\NuCodeGenProj";
NUTOOL_PER.g_cfg_thidrPartyLibLoaction = "";
NUTOOL_PER.g_cfg_thirdPartyLibs = [];
NUTOOL_PER.g_cfg_perFuncMutex = [];
// if you want to dynamically load .txt files, keep this array empty.
NUTOOL_PER.g_cfg_perFunctions = [
'ADC.txt',
'BPWM0.txt',
'BPWM1.txt',
'BPWM2.txt',
'BPWM3.txt',
'CLK.txt',
'CRC.txt',
'FMC.txt',
'GPIO_DB.txt',
'GPIO_PA.txt',
'GPIO_PB.txt',
'GPIO_PC.txt',
'GPIO_PD.txt',
'GPIO_PF.txt',
'I2C0.txt',
'I2C1.txt',
'LLSI0.txt',
'LLSI1.txt',
'LLSI2.txt',
'LLSI3.txt',
'LLSI4.txt',
'LLSI5.txt',
'LLSI6.txt',
'LLSI7.txt',
'LLSI8.txt',
'LLSI9.txt',
'PDMA_CH0.txt',
'PDMA_CH1.txt',
'PDMA_CH2.txt',
'PDMA_CH3.txt',
'PDMA_CH4.txt',
'PDMA_CH5.txt',
'PDMA_CH6.txt',
'PDMA_CH7.txt',
'PDMA_CH8.txt',
'PDMA_CH9.txt',
'SPII2S0.txt',
'SPII2S1.txt',
'SYS.txt',
'TIMER0.txt',
'TIMER1.txt',
'TIMER2.txt',
'TIMER3.txt',
'UART0.txt',
'UART1.txt',
'USBD.txt',
'WDT.txt',
'WWDT.txt'
];