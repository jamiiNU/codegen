// chip content
NUTOOL_CLOCK.g_cfg_chips = [
    { name: "M2003FC1AE", pkg: "TSSOP20" },
    { name: "M2003XC1AE", pkg: "QFN20" }
    //{ name: "M2003XC1BE", pkg: "QFN20" }
];

NUTOOL_CLOCK.g_register_map = [];
NUTOOL_CLOCK.g_register_map.PWRCTL = ['PDEN:7', 'PDWKIF:6', 'PDWKIEN:5', 'LIRCEN:3', 'HIRCEN:2'];
NUTOOL_CLOCK.g_register_map.AHBCLK = ['GPFCKEN:21', 'GPECKEN:20', 'GPCCKEN:18', 'GPBCKEN:17', 'SRAM0CKEN:8', 'STCKEN:3', 'ISPCKEN:1', 'FMCIDLE:0'];
NUTOOL_CLOCK.g_register_map.APBCLK0 = ['ADCCKEN:28', 'UART1CKEN:17', 'UART0CKEN:16', 'I2C0CKEN:8', 'CLKOCKEN:6', 'TMR3CKEN:5', 'TMR2CKEN:4', 'TMR1CKEN:3', 'TMR0CKEN:2', 'WDTCKEN:0'];
NUTOOL_CLOCK.g_register_map.APBCLK1 = ['ECAP0CKEN:26', 'PWM0CKEN:16', 'USCI0CKEN:8'];
NUTOOL_CLOCK.g_register_map.CLKSEL0 = ['STCLKSEL:5-3', 'HCLKSEL:2-0'];
NUTOOL_CLOCK.g_register_map.CLKSEL1 = ['WWDTSEL:31-30', 'CLKOSEL:29-28', 'TMR3SEL:22-20', 'TMR2SEL:18-16', 'TMR1SEL:14-12', 'TMR0SEL:10-8', 'WDTSEL:1-0'];
NUTOOL_CLOCK.g_register_map.CLKSEL2 = ['ADCSEL:25-24', 'UART1SEL:22-20', 'UART0SEL:18-16', 'PWM0SEL:0'];
NUTOOL_CLOCK.g_register_map.CLKDIV0 = ['ADCDIV:23-16', 'UART1DIV:15-12', 'UART0DIV:11-8', 'HCLKDIV:3-0'];
NUTOOL_CLOCK.g_register_map.PCLKDIV = ['APB2DIV:10-8', 'APB1DIV:6-4', 'APB0DIV:2-0'];
NUTOOL_CLOCK.g_register_map.CLKOCTL = ['DIV1EN:5', 'CLKOEN:4', 'FREQSEL:3-0'];
//NUTOOL_CLOCK.g_register_map.PMUCTL = ['WKPINEN3:29-28', 'WKPINEN2:27-26', 'WKPINEN1:25-24', 'WKTMRIS:11-9', 'WKTMREN:8', 'WRBUSY:7', 'PDMSEL:2-0'];
//NUTOOL_CLOCK.g_register_map.SWKDBCTL = ['SWKDBCLKSEL:3-0'];
//NUTOOL_CLOCK.g_register_map.PBSWKCTL = ['DBEN:8', 'WKPSEL:7-4', 'PFWKEN:2', 'PRWKEN:1', 'WKEN:0'];
//NUTOOL_CLOCK.g_register_map.PCSWKCTL = ['DBEN:8', 'WKPSEL:7-4', 'PFWKEN:2', 'PRWKEN:1', 'WKEN:0'];
//NUTOOL_CLOCK.g_register_map.IOPDCTL = ['IOHR:0'];
NUTOOL_CLOCK.g_register_map.SYST_CTRL = ['COUNTFLAG:16', 'CLKSRC:2', 'TICKINT:1', 'ENABLE:0'];

// Be careful. The order of g_register_map_default will affect the result in the generated code.
NUTOOL_CLOCK.g_register_map_default = [];
NUTOOL_CLOCK.g_register_map_default.PWRCTL    = '0x0200000C';
NUTOOL_CLOCK.g_register_map_default.AHBCLK    = '0x00000101';
NUTOOL_CLOCK.g_register_map_default.APBCLK0   = '0x00000001';
NUTOOL_CLOCK.g_register_map_default.APBCLK1   = '0x00000000';
NUTOOL_CLOCK.g_register_map_default.CLKSEL0   = '0x0000001D';
NUTOOL_CLOCK.g_register_map_default.CLKSEL1   = '0xA0222203';
NUTOOL_CLOCK.g_register_map_default.CLKSEL2   = '0x024401A1';
NUTOOL_CLOCK.g_register_map_default.CLKDIV0   = '0x00011100';
NUTOOL_CLOCK.g_register_map_default.PCLKDIV   = '0x00000000';
NUTOOL_CLOCK.g_register_map_default.CLKOCTL   = '0x00000000';
NUTOOL_CLOCK.g_register_map_default.SYST_CTRL = '0x00000000';

NUTOOL_CLOCK.g_register_map_description = [];
NUTOOL_CLOCK.g_register_map_description.PWRCTL    = '0x40000200';
NUTOOL_CLOCK.g_register_map_description.AHBCLK    = '0x40000204';
NUTOOL_CLOCK.g_register_map_description.APBCLK0   = '0x40000208';
NUTOOL_CLOCK.g_register_map_description.APBCLK1   = '0x4000020C';
NUTOOL_CLOCK.g_register_map_description.CLKSEL0   = '0x40000210';
NUTOOL_CLOCK.g_register_map_description.CLKSEL1   = '0x40000214';
NUTOOL_CLOCK.g_register_map_description.CLKSEL2   = '0x40000218';
NUTOOL_CLOCK.g_register_map_description.CLKDIV0   = '0x40000220';
NUTOOL_CLOCK.g_register_map_description.PCLKDIV   = '0x40000234';
NUTOOL_CLOCK.g_register_map_description.CLKOCTL   = '0x40000260';
NUTOOL_CLOCK.g_register_map_description.SYST_CTRL = '0xE000E010';

NUTOOL_CLOCK.g_CLKSEL = [];
NUTOOL_CLOCK.g_CLKSEL.APB0DIV = ['HCLK:0', 'HCLK/2:1', 'HCLK/4:2', 'HCLK/8:3'];
NUTOOL_CLOCK.g_CLKSEL.APB1DIV = ['HCLK:0', 'HCLK/2:1', 'HCLK/4:2', 'HCLK/8:3', 'HCLK/16:4', 'HCLK/32:4'];
NUTOOL_CLOCK.g_CLKSEL.APB2DIV = ['HCLK:0', 'HCLK/2:1', 'HCLK/4:2', 'HCLK/8:3', 'HCLK/16:4', 'HCLK/32:4'];
NUTOOL_CLOCK.g_CLKSEL.ADCSEL = ['PCLK2:2', 'HIRC:3'];
NUTOOL_CLOCK.g_CLKSEL.CLKOSEL = ['HCLK:2', 'HIRC:3'];
NUTOOL_CLOCK.g_CLKSEL.HCLKSEL = ['LIRC:3', 'HIRC:5'];
NUTOOL_CLOCK.g_CLKSEL.PWM0SEL = ['PCLK0:1'];
NUTOOL_CLOCK.g_CLKSEL.STCLKSEL = ['HCLK/2:3', 'HIRC/2:4']; // !!!! need check rules !!!!
NUTOOL_CLOCK.g_CLKSEL.TMR0SEL = ['PCLK0:2', 'LIRC:4', 'HIRC:5']; // 'external:3'
NUTOOL_CLOCK.g_CLKSEL.TMR1SEL = ['PCLK0:2', 'LIRC:4', 'HIRC:5']; // 'external:3'
NUTOOL_CLOCK.g_CLKSEL.TMR2SEL = ['PCLK1:2', 'LIRC:4', 'HIRC:5']; // 'external:3'
NUTOOL_CLOCK.g_CLKSEL.TMR3SEL = ['PCLK1:2', 'LIRC:4', 'HIRC:5']; // 'external:3'
NUTOOL_CLOCK.g_CLKSEL.UART0SEL = ['HIRC:3', 'PCLK0:4'];
NUTOOL_CLOCK.g_CLKSEL.UART1SEL = ['HIRC:3', 'PCLK1:4'];
NUTOOL_CLOCK.g_CLKSEL.WDTSEL = ['HCLK/2048:2', 'LIRC:3'];
NUTOOL_CLOCK.g_CLKSEL.WWDTSEL = ['HCLK/2048:2', 'LIRC:3'];
NUTOOL_CLOCK.g_CLKSEL_EXTENDED = [];

NUTOOL_CLOCK.g_Module = [];
NUTOOL_CLOCK.g_Module.ADC = ['ADCSEL', 'ADCCKEN', 'none'];
NUTOOL_CLOCK.g_Module.ECAP0 = ['PCLK0', 'ECAP0CKEN', 'none'];
NUTOOL_CLOCK.g_Module.FMC = ['HCLK', 'FMCIDLE', 'none'];
NUTOOL_CLOCK.g_Module.GPIOB = ['HCLK', 'GPBCKEN', 'none'];
NUTOOL_CLOCK.g_Module.GPIOC = ['HCLK', 'GPCCKEN', 'none'];
NUTOOL_CLOCK.g_Module.GPIOE = ['HCLK', 'GPECKEN', 'none'];
NUTOOL_CLOCK.g_Module.GPIOF = ['HCLK', 'GPFCKEN', 'none'];
NUTOOL_CLOCK.g_Module.I2C0 = ['PCLK0', 'I2C0CKEN', 'none'];
NUTOOL_CLOCK.g_Module.ISP = ['HCLK', 'ISPCKEN', 'none'];
NUTOOL_CLOCK.g_Module.PWM0 = ['PWM0SEL', 'PWM0CKEN', 'none'];
NUTOOL_CLOCK.g_Module.SRAM = ['HCLK', 'SRAM0CKEN', 'none'];
NUTOOL_CLOCK.g_Module.ST = ['HCLK', 'STCKEN', 'none'];
NUTOOL_CLOCK.g_Module.TMR0 = ['TMR0SEL', 'TMR0CKEN', 'none'];
NUTOOL_CLOCK.g_Module.TMR1 = ['TMR1SEL', 'TMR1CKEN', 'none'];
NUTOOL_CLOCK.g_Module.TMR2 = ['TMR2SEL', 'TMR2CKEN', 'none'];
NUTOOL_CLOCK.g_Module.TMR3 = ['TMR3SEL', 'TMR3CKEN', 'none'];
NUTOOL_CLOCK.g_Module.UART0 = ['UART0SEL', 'UART0CKEN', 'UART0DIV'];
NUTOOL_CLOCK.g_Module.UART1 = ['UART1SEL', 'UART1CKEN', 'UART1DIV'];
NUTOOL_CLOCK.g_Module.USCI0 = ['PCLK0', 'USCI0CKEN', 'none'];
NUTOOL_CLOCK.g_Module.WDT = ['WDTSEL', 'WDTCKEN', 'none'];
NUTOOL_CLOCK.g_Module.WWDT = ['WWDTSEL', 'WDTCKEN', 'none'];
NUTOOL_CLOCK.g_Module.CLKO = ['CLKOSEL', 'CLKOCKEN/DIV1EN/CLKOEN', 'none'];
NUTOOL_CLOCK.g_Module.CLKO_Divider = ['CLKOSEL', 'CLKOCKEN/!DIV1EN/CLKOEN', 'FREQSEL'];
NUTOOL_CLOCK.g_Module.SYSTICK = ['STCLKSEL/SYST_CTRL[2]', 'ENABLE', 'none'];

NUTOOL_CLOCK.g_unusedModule = {
    "M2003FC1AE(TSSOP20)": ["BPWM0", "CAN", "RTC", "SPI0", "SPI1", "I2C1", "USCI1", "TAMPER0", "ACMP0", "ACMP1", "VREF", "HXT", "LXT"],
    "M2003XC1AE(QFN20)": ["BPWM0", "CAN", "RTC", "SPI0", "SPI1", "I2C1", "USCI1", "TAMPER0", "ACMP0", "ACMP1", "VREF", "HXT", "LXT"],
    "M2003XC1BE(QFN20)": ["BPWM0", "CAN", "RTC", "SPI0", "SPI1", "I2C1", "USCI1", "TAMPER0", "ACMP0", "ACMP1", "VREF", "HXT", "LXT"]
};

NUTOOL_CLOCK.g_equivalentName = [];
NUTOOL_CLOCK.g_equivalentName._S = 'SEL';
NUTOOL_CLOCK.g_equivalentName.OSC10K_EN = 'LIRCEN';
NUTOOL_CLOCK.g_equivalentName.OSC22M_EN = 'HIRCEN';
NUTOOL_CLOCK.g_equivalentName.XTL32K_EN = 'LXTEN';
NUTOOL_CLOCK.g_equivalentName.XTL12M_EN = 'HXTEN';
NUTOOL_CLOCK.g_equivalentName.WDT_EN = 'WDTCKEN';
NUTOOL_CLOCK.g_equivalentName.SYST_CSR = 'SYST_CTRL';
NUTOOL_CLOCK.g_equivalentName.HCLK_S = 'HCLKSEL';
NUTOOL_CLOCK.g_equivalentName.STCLK_S = 'STCLKSEL';
NUTOOL_CLOCK.g_equivalentName['STCLK_S/SYST_CSR[2]'] = 'STCLKSEL/SYST_CTRL[2]';
NUTOOL_CLOCK.g_equivalentName.HCLK_N = 'HCLKDIV';
NUTOOL_CLOCK.g_equivalentName.PWRCON = 'PWRCTL';
NUTOOL_CLOCK.g_equivalentName.PLLCON = 'PLLCTL';
NUTOOL_CLOCK.g_equivalentName.PCLK0SEL = 'APB0DIV';
NUTOOL_CLOCK.g_equivalentName.PCLK1SEL = 'APB1DIV';
NUTOOL_CLOCK.g_equivalentName.PCLK2SEL = 'APB2DIV';

NUTOOL_CLOCK.g_BusNonExistent = [];
NUTOOL_CLOCK.g_BusFromPCLK1 = ['TMR2', 'TMR3', 'UART1'];
NUTOOL_CLOCK.g_BusFromPCLK2 = ['ADC'];
NUTOOL_CLOCK.g_DIV_Module_Defines = [];
NUTOOL_CLOCK.g_CPUCLKLimit = 72 * 1000000;
NUTOOL_CLOCK.g_HXTfrequency = 0;
NUTOOL_CLOCK.g_HIRCfrequencyArray = [];
NUTOOL_CLOCK.g_HIRCfrequency = 24000000;
NUTOOL_CLOCK.g_HIRC2frequencyArray = [];
NUTOOL_CLOCK.g_HIRC2frequency = 0;
NUTOOL_CLOCK.g_HIRC48frequency = 0;
NUTOOL_CLOCK.g_LIRCfrequency = 10 * 1000;
NUTOOL_CLOCK.g_MIRCfrequency = 0;
NUTOOL_CLOCK.g_MIRC1P2Mfrequency = 0;
NUTOOL_CLOCK.g_RTC32kfrequency = 0;
NUTOOL_CLOCK.g_PLL480Mfrequency = 0;
NUTOOL_CLOCK.g_HSUSBOTGPHYfrequency = 0;