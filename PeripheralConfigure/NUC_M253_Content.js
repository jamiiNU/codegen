// chip content
NUTOOL_PER.g_cfg_chips = [
    //M253
    { name: "M253ZE3AE", pkg: "QFN33",  type: "M253"  },
    { name: "M253LD3AE", pkg: "LQFP48", type: "M253"  },
    { name: "M253LE3AE", pkg: "LQFP48", type: "M253"  }
];

NUTOOL_PER.g_cfg_unusedPerFunctions = {}
NUTOOL_PER.g_cfg_downloadBSP = {
    repository: "M253BSP",
    commitID: {
        "V0.41.0009": "11a65cb3ca7008610637613bfae2e010a3b0ff89"
    }
}

// relative to the location of the directory containing tags
NUTOOL_PER.g_cfg_projectLoaction = "\\NuCodeGenProj";
NUTOOL_PER.g_cfg_thidrPartyLibLoaction = "";
NUTOOL_PER.g_cfg_thirdPartyLibs = [];
NUTOOL_PER.g_cfg_perFuncMutex = [];
// if you want to dynamically load .txt files, keep this array empty.
NUTOOL_PER.g_cfg_perFunctions = [
'BPWM0.txt',
'CANFD0.txt',
'CLK.txt',
'CRC.txt',
'EADC.txt',
'FMC.txt',
'GPIO_DB.txt',
'GPIO_PA.txt',
'GPIO_PB.txt',
'GPIO_PC.txt',
'GPIO_PF.txt',
'I2C0.txt',
'I2C1.txt',
'PDMA_CH0.txt',
'PDMA_CH1.txt',
'PDMA_CH2.txt',
'PDMA_CH3.txt',
'PDMA_CH4.txt',
'RTC.txt',
'SPII2S0.txt',
'SYS.txt',
'TIMER0.txt',
'TIMER1.txt',
'TIMER2.txt',
'TIMER3.txt',
'UART0.txt',
'UART1.txt',
'UART2.txt',
'UART3.txt',
'UART4.txt',
'USBD.txt',
'USCI0_I2C.txt',
'USCI0_SPI.txt',
'USCI0_UART.txt',
'WDT.txt',
'WWDT.txt'
];
