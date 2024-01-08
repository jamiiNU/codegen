// chip content
NUTOOL_PER.g_cfg_chips = [
    // M031_B
    {   name: "M031FB0AE", pkg: "TSSOP20", type: "M031_B" },
    {   name: "M031EB0AE", pkg: "TSSOP28", type: "M031_B" },
    {   name: "M031TB0AE", pkg: "QFN33",   type: "M031_B" },
    // M031_C
    {   name: "M031FC1AE", pkg: "TSSOP20", type: "M031_C" },
    {   name: "M031EC1AE", pkg: "TSSOP28", type: "M031_C" },
    {   name: "M031TC1AE", pkg: "QFN33",   type: "M031_C" },
    {   name: "M031LC2AE", pkg: "LQFP48",  type: "M031_C" },
    {   name: "M031SC2AE", pkg: "LQFP64",  type: "M031_C" },
    // M031_D
    {   name: "M031TD2AE", pkg: "QFN33",   type: "M031_D" },
    {   name: "M031LD2AE", pkg: "LQFP48",  type: "M031_D" },
    {   name: "M031SD2AE", pkg: "LQFP64",  type: "M031_D" },
    // M031_E
    {   name: "M031TE3AE", pkg: "QFN33",   type: "M031_E" },
    {   name: "M031LE3AE", pkg: "LQFP48",  type: "M031_E" },
    {   name: "M031SE3AE", pkg: "LQFP64",  type: "M031_E" },
    // M031_G
    {   name: "M031LG6AE", pkg: "LQFP48",  type: "M031_G" },
    {   name: "M031SG6AE", pkg: "LQFP64",  type: "M031_G" },
    {   name: "M031KG6AE", pkg: "LQFP128", type: "M031_G" },
    {   name: "M031LG8AE", pkg: "LQFP48",  type: "M031_G" },
    {   name: "M031SG8AE", pkg: "LQFP64",  type: "M031_G" },
    {   name: "M031KG8AE", pkg: "LQFP128", type: "M031_G" },
    // M031_I
    {   name: "M031SIAAE", pkg: "LQFP64",  type: "M031_I" },
    {   name: "M031KIAAE", pkg: "LQFP128", type: "M031_I" },
    // M032_C (Mouse)
    {   name: "M032FC1AE", pkg: "TSSOP20", type: "M032_C" },
    {   name: "M032EC1AE", pkg: "TSSOP28", type: "M032_C" },
    {   name: "M032TC1AE", pkg: "QFN33",   type: "M032_C" },
    //{   name: "M032TC2AE", pkg: "QFN33",   type: "M032_C" }, //Update in 2021/02/22
    {   name: "M032LC2AE", pkg: "LQFP48",  type: "M032_C" },
    // M032_D (Keyboard)
    {   name: "M032TD2AE", pkg: "QFN33",   type: "M032_D" },
    {   name: "M032LD2AE", pkg: "LQFP48",  type: "M032_D" },
    // M032_E
    {   name: "M032LE3AE", pkg: "LQFP48",  type: "M032_E" },
    {   name: "M032SE3AE", pkg: "LQFP64",  type: "M032_E" },
    // M032_G
    {   name: "M032LG6AE", pkg: "LQFP48",  type: "M032_G" },
    {   name: "M032SG6AE", pkg: "LQFP64",  type: "M032_G" },
    {   name: "M032KG6AE", pkg: "LQFP128", type: "M032_G" },
    {   name: "M032LG8AE", pkg: "LQFP48",  type: "M032_G" },
    {   name: "M032SG8AE", pkg: "LQFP64",  type: "M032_G" },
    {   name: "M032KG8AE", pkg: "LQFP128", type: "M032_G" },
    // M032_I
    {   name: "M032SIAAE", pkg: "LQFP64",  type: "M032_I" },
    {   name: "M032KIAAE", pkg: "LQFP128", type: "M032_I" },

    // M031_BT (Unclear SPEC/TBD)
    //{ name: "M031BTYD2AN", pkg: "QFN48", type: "M031_E" },
    //{ name: "M031BTYE3AN", pkg: "QFN48", type: "M031_D" }
];

//FULL: Exclude the file if file name full match
//SUBSTRING:�@Exclude the file if file name just partial match
NUTOOL_PER.g_cfg_unusedPerFunctions = {
    "M032_I": {},
    "M032_G": {},
    "M032_C": {"FULL": ["EBI", "CRC", "RTC", "ACMP"],
               "SUBSTRING": ["I2C"]},
    "M032_D": {"FULL": ["EBI", "CRC", "RTC", "ACMP"],
               "SUBSTRING": ["I2C"]},
    "M032_E": {"FULL": ["QSPI", "RTC"]},
    "M031_I": {"FULL": ["USBD"]},
    "M031_G": {"FULL": ["USBD"]},
    "M031_B": {"FULL": ["QSPI", "EBI", "RTC", "ACMP", "USBD"],
               "SUBSTRING": ["USCI", "PDMA"]},
    "M031_C": {"FULL": ["QSPI", "EBI", "RTC", "USBD"]},
    "M031_D": {"FULL": ["QSPI", "EBI", "RTC", "USBD"]},
    "M031_E": {"FULL": ["QSPI", "RTC", "USBD"]},

    //M031_B
    "M031FB0AE": {"FULL": ["TIMER2", "TIMER3", "UART3", "UART4", "UART5", "UART6", "UART7", "PWM1", "BPWM0", "BPWM1"],
                  "SUBSTRING": ["PDMA"]},
    "M031EB0AE": {"FULL": ["TIMER2", "TIMER3", "UART3", "UART4", "UART5", "UART6", "UART7", "PWM1", "BPWM0", "BPWM1"],
                  "SUBSTRING": ["PDMA"]},
    "M031TB0AE": {"FULL": ["TIMER2", "TIMER3", "UART3", "UART4", "UART5", "UART6", "UART7", "PWM1", "BPWM0", "BPWM1"],
                  "SUBSTRING": ["PDMA"]},
    //M031_C
    "M031FC1AE": {"FULL": ["UART3", "UART4", "UART5", "UART6", "UART7", "PWM1", "BPWM0", "BPWM1", "PDMA_CH2", "PDMA_CH3", "PDMA_CH4", "PDMA_CH5", "PDMA_CH6", "PDMA_CH7", "PDMA_CH8", "ACMP"],
                  "SUBSTRING": ["USCI0", "USCI1"]},
    "M031EC1AE": {"FULL": ["UART3", "UART4", "UART5", "UART6", "UART7", "PWM1", "BPWM0", "BPWM1", "PDMA_CH2", "PDMA_CH3", "PDMA_CH4", "PDMA_CH5", "PDMA_CH6", "PDMA_CH7", "PDMA_CH8", "ACMP"],
                  "SUBSTRING": ["USCI0", "USCI1"]},
    "M031TC1AE": {"FULL": ["UART3", "UART4", "UART5", "UART6", "UART7", "PWM1", "BPWM0", "BPWM1", "PDMA_CH2", "PDMA_CH3", "PDMA_CH4", "PDMA_CH5", "PDMA_CH6", "PDMA_CH7", "PDMA_CH8", "ACMP"],
                  "SUBSTRING": ["USCI0", "USCI1"]},
    //Chip is M031_D. But classify it as M031_C by name
    "M031LC2AE": {"FULL": ["UART3", "UART4", "UART5", "UART6", "UART7", "BPWM0", "BPWM1", "PDMA_CH5", "PDMA_CH6", "PDMA_CH7", "PDMA_CH8"],
                  "SUBSTRING": ["USCI1"]},
    //Chip is M031_D. But classify it as M031_C by name
    "M031SC2AE": {"FULL": ["UART3", "UART4", "UART5", "UART6", "UART7", "BPWM0", "BPWM1", "PDMA_CH5", "PDMA_CH6", "PDMA_CH7", "PDMA_CH8"],
                 "SUBSTRING": ["USCI1"]},
    //M031_D
    "M031TD2AE": {"FULL": ["UART3", "UART4", "UART5", "UART6", "UART7", "BPWM0", "BPWM1", "PDMA_CH5", "PDMA_CH6", "PDMA_CH7", "PDMA_CH8"],
                 "SUBSTRING": ["USCI1"]},
    "M031LD2AE": {"FULL": ["UART3", "UART4", "UART5", "UART6", "UART7", "BPWM0", "BPWM1", "PDMA_CH5", "PDMA_CH6", "PDMA_CH7", "PDMA_CH8"],
                 "SUBSTRING": ["USCI1"]},
    "M031SD2AE": {"FULL": ["UART3", "UART4", "UART5", "UART6", "UART7", "BPWM0", "BPWM1", "PDMA_CH5", "PDMA_CH6", "PDMA_CH7", "PDMA_CH8"],
                 "SUBSTRING": ["USCI1"]},
    //M031_E
    "M031TE3AE": {"FULL": ["UART3", "UART4", "UART5", "UART6", "UART7", "BPWM0", "BPWM1", "PDMA_CH5", "PDMA_CH6", "PDMA_CH7", "PDMA_CH8", "EBI"],
                 "SUBSTRING": ["USCI1"]},
    "M031LE3AE": {"FULL": ["UART3", "UART4", "UART5", "UART6", "UART7", "BPWM0", "BPWM1", "PDMA_CH5", "PDMA_CH6", "PDMA_CH7", "PDMA_CH8"],
                 "SUBSTRING": ["USCI1"]},
    "M031SE3AE": {"FULL": ["UART3", "UART4", "UART5", "UART6", "UART7", "BPWM0", "BPWM1", "PDMA_CH5", "PDMA_CH6", "PDMA_CH7", "PDMA_CH8"],
                 "SUBSTRING": ["USCI1"]},
    //M031_G
    "M031LG6AE": {"FULL": ["UART6", "UART7", "PDMA_CH7", "PDMA_CH8"]},
    "M031SG6AE": {"FULL": ["UART6", "UART7", "PDMA_CH7", "PDMA_CH8"]},
    "M031KG6AE": {"FULL": ["UART6", "UART7", "PDMA_CH7", "PDMA_CH8"]},
    "M031LG8AE": {"FULL": ["UART6", "UART7", "PDMA_CH7", "PDMA_CH8"]},
    "M031SG8AE": {"FULL": ["UART6", "UART7", "PDMA_CH7", "PDMA_CH8"]},
    "M031KG8AE": {"FULL": ["UART6", "UART7", "PDMA_CH7", "PDMA_CH8"]},

    //M031_I
    //"M031SIAAE"    //First level has filtered out USB
    //"M031KIAAE"    //First level has filtered out USB

    //M032_C (Mouse)
    "M032FC1AE": {"FULL": ["TIMER2", "TIMER3", "UART1", "UART2", "UART3", "UART4", "UART5", "UART6", "UART7", "PWM0", "PWM1", "BPWM1", "QSPI", "HDIV"],
                  "SUBSTRING": ["USCI0", "PDMA"]}, //M032_C (Mouse) only supports USCI1
    "M032EC1AE": {"FULL": ["TIMER2", "TIMER3", "UART1", "UART2", "UART3", "UART4", "UART5", "UART6", "UART7", "PWM0", "PWM1", "BPWM1", "QSPI", "HDIV"],
                  "SUBSTRING": ["USCI0", "PDMA"]}, //M032_C (Mouse) only supports USCI1
    "M032TC1AE": {"FULL": ["TIMER2", "TIMER3", "UART1", "UART2", "UART3", "UART4", "UART5", "UART6", "UART7", "PWM0", "PWM1", "BPWM1", "QSPI", "HDIV"],
                  "SUBSTRING": ["USCI0", "PDMA"]}, //M032_C (Mouse) only supports USCI1
    //Chip is M032_D. But classify it as M032_C by name
    "M032TC2AE": {"FULL": ["UART1", "UART2", "UART3", "UART4", "UART5", "UART6", "UART7", "PWM0", "PWM1", "PDMA_CH5", "PDMA_CH6", "PDMA_CH7", "PDMA_CH8"]},
    //Chip is M032_D. But classify it as M032_C by name
    "M032LC2AE": {"FULL": ["UART1", "UART2", "UART3", "UART4", "UART5", "UART6", "UART7", "PWM0", "PWM1", "PDMA_CH5", "PDMA_CH6", "PDMA_CH7", "PDMA_CH8"]},

    //M032_D (Keyboard)
    "M032TD2AE": {"FULL": ["UART1", "UART2", "UART3", "UART4", "UART5", "UART6", "UART7", "PWM0", "PWM1", "PDMA_CH5", "PDMA_CH6", "PDMA_CH7", "PDMA_CH8"]},
    "M032LD2AE": {"FULL": ["UART1", "UART2", "UART3", "UART4", "UART5", "UART6", "UART7", "PWM0", "PWM1", "PDMA_CH5", "PDMA_CH6", "PDMA_CH7", "PDMA_CH8"]},

    //M032_E
    "M032LE3AE": {"FULL": ["UART3", "UART4", "UART5", "UART6", "UART7", "PWM0", "PWM1", "PDMA_CH5", "PDMA_CH6", "PDMA_CH7", "PDMA_CH8"],
                 "SUBSTRING": ["USCI1"]},
    "M032SE3AE": {"FULL": ["UART3", "UART4", "UART5", "UART6", "UART7", "PWM0", "PWM1", "PDMA_CH5", "PDMA_CH6", "PDMA_CH7", "PDMA_CH8"],
                 "SUBSTRING": ["USCI1"]},

    //M032_G
    "M032LG6AE": {"FULL": ["UART6", "UART7", "PDMA_CH7", "PDMA_CH8"]},
    "M032SG6AE": {"FULL": ["UART6", "UART7", "PDMA_CH7", "PDMA_CH8"]},
    "M032KG6AE": {"FULL": ["UART6", "UART7", "PDMA_CH7", "PDMA_CH8"]},
    "M032LG8AE": {"FULL": ["UART6", "UART7", "PDMA_CH7", "PDMA_CH8"]},
    "M032SG8AE": {"FULL": ["UART6", "UART7", "PDMA_CH7", "PDMA_CH8"]},
    "M032KG8AE": {"FULL": ["UART6", "UART7", "PDMA_CH7", "PDMA_CH8"]},

    //M032_I
    //"M032SIAAE"
    //"M032KIAAE"

};

NUTOOL_PER.g_cfg_downloadBSP = {
    repository: "M031BSP",
    commitID: {
        "V0.42.0002": "889f298a9665dfb30533ca437600113487b12c5a"
    }
}

// relative to the location of the directory containing tags
NUTOOL_PER.g_cfg_projectLoaction = {
    'ByDefault': '\\NuCodeGenProj'
};

NUTOOL_PER.g_cfg_thidrPartyLibLoaction = "";
NUTOOL_PER.g_cfg_thirdPartyLibs = [];
NUTOOL_PER.g_cfg_perFuncMutex = ["USCI0", "USCI1"];
// if you want to dynamically load .txt files, keep this array empty.
NUTOOL_PER.g_cfg_perFunctions = [
'ACMP.txt',
'ADC.txt',
'BPWM0.txt',
'BPWM1.txt',
'CLK.txt',
'CRC.txt',
// 'DAC.txt',
'EBI_BANK0.txt',
'EBI_BANK1.txt',
// 'EBI_BANK2.txt',
'FMC.txt',
'GPIO_DB.txt',
'GPIO_PA.txt',
'GPIO_PB.txt',
'GPIO_PC.txt',
'GPIO_PD.txt',
'GPIO_PE.txt',
'GPIO_PF.txt',
'GPIO_PG.txt',
'GPIO_PH.txt',
'HDIV.txt',
'I2C0.txt',
'I2C1.txt',
'PDMA_CH0.txt',
'PDMA_CH1.txt',
'PDMA_CH2.txt',
'PDMA_CH3.txt',
'PDMA_CH4.txt',
'PDMA_CH5.txt',
'PDMA_CH6.txt',
'PDMA_CH7.txt',
'PDMA_CH8.txt',
'PWM0_CH0CH1.txt',
'PWM0_CH2CH3.txt',
'PWM0_CH4CH5.txt',
'PWM1_CH0CH1.txt',
'PWM1_CH2CH3.txt',
'PWM1_CH4CH5.txt',
'QSPI.txt',
'RTC.txt',
'SPII2S.txt',
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
'UART5.txt',
'UART6.txt',
'UART7.txt',
'USBD.txt',
'USCI0_I2C.txt',
'USCI0_SPI.txt',
'USCI0_UART.txt',
'USCI1_I2C.txt',
'USCI1_SPI.txt',
'USCI1_UART.txt',
'WDT.txt',
'WWDT.txt'
];
