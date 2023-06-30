// chip content
NUTOOL_CLOCK.g_cfg_chips = [
	// M031
	{ name: "M031FB0AE", pkg: "TSSOP20" },
	{ name: "M031FC1AE", pkg: "TSSOP20" },
	{ name: "M031EB0AE", pkg: "TSSOP28" },
	{ name: "M031EC1AE", pkg: "TSSOP28" },
	{ name: "M031TB0AE", pkg: "QFN33" },
	{ name: "M031TC1AE", pkg: "QFN33" },
	{ name: "M031TD2AE", pkg: "QFN33" },
	{ name: "M031TE3AE", pkg: "QFN33" },
	{ name: "M031LC2AE", pkg: "LQFP48" },
	{ name: "M031LD2AE", pkg: "LQFP48" },
	{ name: "M031LE3AE", pkg: "LQFP48" },
	{ name: "M032LE3AE", pkg: "LQFP48" },
	{ name: "M031SC2AE", pkg: "LQFP64" },
	{ name: "M031SD2AE", pkg: "LQFP64" },
	{ name: "M031SE3AE", pkg: "LQFP64" },
	{ name: "M032SE3AE", pkg: "LQFP64" },
	// M031G
	{ name: "M031LG6AE", pkg: "LQFP48" },
	{ name: "M031SG6AE", pkg: "LQFP64" },
	{ name: "M031KG6AE", pkg: "LQFP128" },
	{ name: "M031LG8AE", pkg: "LQFP48" },
	{ name: "M031SG8AE", pkg: "LQFP64" },
	{ name: "M031KG8AE", pkg: "LQFP128" },
	{ name: "M032LG6AE", pkg: "LQFP48" },
	{ name: "M032SG6AE", pkg: "LQFP64" },
	{ name: "M032KG6AE", pkg: "LQFP128" },
	{ name: "M032LG8AE", pkg: "LQFP48" },
	{ name: "M032SG8AE", pkg: "LQFP64" },
	{ name: "M032KG8AE", pkg: "LQFP128" },
	// { name: "M032BTAG8AN", pkg: "QFN68" },
	// M031I
	{ name: "M031SIAAE", pkg: "LQFP64" },
	{ name: "M031KIAAE", pkg: "LQFP128" },
	{ name: "M032SIAAE", pkg: "LQFP64" },
	{ name: "M032KIAAE", pkg: "LQFP128" },
	// { name: "M032BTAIAAN", pkg: "QFN68" },
	// M031KM
	// { name: "M030FD2AE", pkg: "TSSOP20" },
	// { name: "M030TD2AE", pkg: "QFN33" },
	// { name: "M030LD2AE", pkg: "LQFP48" },
	{ name: "M032FC1AE", pkg: "TSSOP20" },
	{ name: "M032EC1AE", pkg: "TSSOP28" },
	{ name: "M032TC1AE", pkg: "QFN33" },
	{ name: "M032TD2AE", pkg: "QFN33" },
	{ name: "M032LC2AE", pkg: "LQFP48" },
	{ name: "M032LD2AE", pkg: "LQFP48" },
	// M031BT
	{ name: "M031BTYD2AN", pkg: "QFN48" },
	{ name: "M031BTYE3AN", pkg: "QFN48" }
];

NUTOOL_CLOCK.g_register_map = [];
NUTOOL_CLOCK.g_register_map.PWRCTL = ['LIRCEN:3', 'HIRCEN:2', 'LXTEN:1', 'HXTEN:0'];
NUTOOL_CLOCK.g_register_map.AHBCLK = ['CRCCKEN:7', 'HDIVCKEN:4', 'ISPCKEN:2', 'PDMACKEN:1'];
NUTOOL_CLOCK.g_register_map.APBCLK0 = ['ADCCKEN:28', 'UART2CKEN:18', 'UART1CKEN:17', 'UART0CKEN:16', 'SPI0CKEN:13', 'I2C1CKEN:9', 'I2C0CKEN:8', 'ACMP01CKEN:7', 'CLKOCKEN:6', 'TMR3CKEN:5', 'TMR2CKEN:4', 'TMR1CKEN:3', 'TMR0CKEN:2', 'WDTCKEN:0'];
NUTOOL_CLOCK.g_register_map.APBCLK1 = ['PWM1CKEN:17', 'PWM0CKEN:16', 'USCI0CKEN:8'];
NUTOOL_CLOCK.g_register_map.CLKSEL0 = ['STCLKSEL:5-3', 'HCLKSEL:2-0'];
NUTOOL_CLOCK.g_register_map.CLKSEL1 = ['UART1SEL:30-28', 'UART0SEL:26-24', 'TMR3SEL:22-20', 'TMR2SEL:18-16', 'TMR1SEL:14-12', 'TMR0SEL:10-8', 'CLKOSEL:6-4', 'WWDTSEL:3-2', 'WDTSEL:1-0'];
NUTOOL_CLOCK.g_register_map.CLKSEL2 = ['ADCSEL:21-20', 'SPI0SEL:5-4', 'PWM1SEL:1', 'PWM0SEL:0'];
NUTOOL_CLOCK.g_register_map.CLKSEL3 = ['UART2SEL:26-24'];
NUTOOL_CLOCK.g_register_map.CLKDIV0 = ['ADCDIV:23-16', 'UART1DIV:15-12', 'UART0DIV:11-8', 'HCLKDIV:3-0'];
NUTOOL_CLOCK.g_register_map.CLKDIV4 = ['UART2DIV:3-0'];
NUTOOL_CLOCK.g_register_map.PCLKDIV = ['APB1DIV:6-4', 'APB0DIV:2-0'];
NUTOOL_CLOCK.g_register_map.PLLCTL = ['PLL_SRC:19', 'OE:18', 'BP:17', 'PD:16', 'OUTDIV:15-14', 'INDIV:13-9', 'FBDIV:8-0'];
NUTOOL_CLOCK.g_register_map.CLKOCTL = ['DIV1EN:5', 'CLKOEN:4', 'FREQSEL:3-0'];
NUTOOL_CLOCK.g_register_map.SYST_CTRL = ['CLKSRC:2', 'ENABLE:0'];

// Be careful. The order of g_register_map_default will affect the result in the generated code.
NUTOOL_CLOCK.g_register_map_default = [];
NUTOOL_CLOCK.g_register_map_default.CLKDIV0    = '0x00000000';
NUTOOL_CLOCK.g_register_map_default.CLKDIV4    = '0x00000000';
NUTOOL_CLOCK.g_register_map_default.PCLKDIV    = '0x00000000';
NUTOOL_CLOCK.g_register_map_default.CLKSEL0    = '0x0000003F';
NUTOOL_CLOCK.g_register_map_default.CLKSEL1    = '0x4477773B';
NUTOOL_CLOCK.g_register_map_default.CLKSEL2    = '0x00200023';
NUTOOL_CLOCK.g_register_map_default.CLKSEL3    = '0x04000000';
NUTOOL_CLOCK.g_register_map_default.PWRCTL     = '0x0231001F';
NUTOOL_CLOCK.g_register_map_default.AHBCLK     = '0x00000004';
NUTOOL_CLOCK.g_register_map_default.APBCLK0    = '0x00000001';
NUTOOL_CLOCK.g_register_map_default.APBCLK1    = '0x00000000';
NUTOOL_CLOCK.g_register_map_default.PLLCTL     = '0x0005C25E';
NUTOOL_CLOCK.g_register_map_default.CLKOCTL    = '0x00000000';
NUTOOL_CLOCK.g_register_map_default.SYST_CTRL  = '0x00000000';

NUTOOL_CLOCK.g_register_map_description = [];
NUTOOL_CLOCK.g_register_map_description.PWRCTL     = '0x40000200';
NUTOOL_CLOCK.g_register_map_description.AHBCLK     = '0x40000204';
NUTOOL_CLOCK.g_register_map_description.APBCLK0    = '0x40000208';
NUTOOL_CLOCK.g_register_map_description.APBCLK1    = '0x4000020C';
NUTOOL_CLOCK.g_register_map_description.CLKSEL0    = '0x40000210';
NUTOOL_CLOCK.g_register_map_description.CLKSEL1    = '0x40000214';
NUTOOL_CLOCK.g_register_map_description.CLKSEL2    = '0x40000218';
NUTOOL_CLOCK.g_register_map_description.CLKSEL3    = '0x4000021C';
NUTOOL_CLOCK.g_register_map_description.CLKDIV0    = '0x40000220';
NUTOOL_CLOCK.g_register_map_description.CLKDIV4    = '0x40000230';
NUTOOL_CLOCK.g_register_map_description.PCLKDIV    = '0x40000234';
NUTOOL_CLOCK.g_register_map_description.PLLCTL     = '0x40000240';
NUTOOL_CLOCK.g_register_map_description.CLKOCTL    = '0x40000260';
NUTOOL_CLOCK.g_register_map_description.SYST_CTRL  = '0xE000E010';

NUTOOL_CLOCK.g_CLKSEL = [];
NUTOOL_CLOCK.g_CLKSEL.APB0DIV = ['HCLK:0', 'HCLK/2:1', 'HCLK/4:2', 'HCLK/8:3', 'HCLK/16:4'];
NUTOOL_CLOCK.g_CLKSEL.APB1DIV = ['HCLK:0', 'HCLK/2:1', 'HCLK/4:2', 'HCLK/8:3', 'HCLK/16:4'];
NUTOOL_CLOCK.g_CLKSEL.ADCSEL = ['HXT:0', 'PLL:1', 'PCLK1:2', 'HIRC:3'];
NUTOOL_CLOCK.g_CLKSEL.CLKOSEL = ['HXT:0', 'LXT:1', 'HCLK:2', 'HIRC:3', 'LIRC:4',/* 'HIRC:5',*/ 'PLL:6'];
NUTOOL_CLOCK.g_CLKSEL.HCLKSEL = ['HXT:0', 'LXT:1', 'PLL:2', 'LIRC:3', 'HIRC:7'];
NUTOOL_CLOCK.g_CLKSEL.PWM0SEL = ['PLL:0', 'PCLK0:1'];
NUTOOL_CLOCK.g_CLKSEL.PWM1SEL = ['PLL:0', 'PCLK1:1'];
NUTOOL_CLOCK.g_CLKSEL.SPI0SEL = ['HXT:0', 'PLL:1', 'PCLK1:2', 'HIRC:3'];
NUTOOL_CLOCK.g_CLKSEL.STCLKSEL = ['HXT:0', 'LXT:1', 'HXT/2:2', 'HCLK/2:3', 'HIRC/2:7'];
NUTOOL_CLOCK.g_CLKSEL.TMR0SEL = ['HXT:0', 'LXT:1', 'PCLK0:2', 'LIRC:5', 'HIRC:7']; // 'external:3'
NUTOOL_CLOCK.g_CLKSEL.TMR1SEL = ['HXT:0', 'LXT:1', 'PCLK0:2', 'LIRC:5', 'HIRC:7']; // 'external:3'
NUTOOL_CLOCK.g_CLKSEL.TMR2SEL = ['HXT:0', 'LXT:1', 'PCLK1:2', 'LIRC:5', 'HIRC:7']; // 'external:3'
NUTOOL_CLOCK.g_CLKSEL.TMR3SEL = ['HXT:0', 'LXT:1', 'PCLK1:2', 'LIRC:5', 'HIRC:7']; // 'external:3'
NUTOOL_CLOCK.g_CLKSEL.UART0SEL = ['HXT:0', 'PLL:1', 'LXT:2', 'HIRC:3', 'PCLK0:4', 'LIRC:5'];
NUTOOL_CLOCK.g_CLKSEL.UART1SEL = ['HXT:0', 'PLL:1', 'LXT:2', 'HIRC:3', 'PCLK1:4', 'LIRC:5'];
NUTOOL_CLOCK.g_CLKSEL.UART2SEL = ['HXT:0', 'PLL:1', 'LXT:2', 'HIRC:3', 'PCLK0:4', 'LIRC:5'];
NUTOOL_CLOCK.g_CLKSEL.WDTSEL = ['LXT:1', 'HCLK/2048:2', 'LIRC:3'];
NUTOOL_CLOCK.g_CLKSEL.WWDTSEL = ['HCLK/2048:2', 'LIRC:3'];
NUTOOL_CLOCK.g_CLKSEL_EXTENDED = [];

NUTOOL_CLOCK.g_Module = [];
NUTOOL_CLOCK.g_Module.ACMP01 = ['PCLK1', 'ACMP01CKEN', 'none'];
NUTOOL_CLOCK.g_Module.ADC = ['ADCSEL', 'ADCCKEN', 'ADCDIV'];
NUTOOL_CLOCK.g_Module.CRC = ['HCLK', 'CRCCKEN', 'none'];
NUTOOL_CLOCK.g_Module.HDIV = ['HCLK', 'HDIVCKEN', 'none'];
NUTOOL_CLOCK.g_Module.I2C0 = ['PCLK0', 'I2C0CKEN', 'none'];
NUTOOL_CLOCK.g_Module.I2C1 = ['PCLK1', 'I2C1CKEN', 'none'];
NUTOOL_CLOCK.g_Module.ISP = ['HIRC', 'ISPCKEN', 'none'];
NUTOOL_CLOCK.g_Module.PDMA = ['HCLK', 'PDMACKEN', 'none'];
NUTOOL_CLOCK.g_Module.PWM0 = ['PWM0SEL', 'PWM0CKEN', 'none'];
NUTOOL_CLOCK.g_Module.PWM1 = ['PWM1SEL', 'PWM1CKEN', 'none'];
NUTOOL_CLOCK.g_Module.SPI0 = ['SPI0SEL', 'SPI0CKEN', 'none'];
NUTOOL_CLOCK.g_Module.TMR0 = ['TMR0SEL', 'TMR0CKEN', 'none'];
NUTOOL_CLOCK.g_Module.TMR1 = ['TMR1SEL', 'TMR1CKEN', 'none'];
NUTOOL_CLOCK.g_Module.TMR2 = ['TMR2SEL', 'TMR2CKEN', 'none'];
NUTOOL_CLOCK.g_Module.TMR3 = ['TMR3SEL', 'TMR3CKEN', 'none'];
NUTOOL_CLOCK.g_Module.UART0 = ['UART0SEL', 'UART0CKEN', 'UART0DIV'];
NUTOOL_CLOCK.g_Module.UART1 = ['UART1SEL', 'UART1CKEN', 'UART1DIV'];
NUTOOL_CLOCK.g_Module.UART2 = ['UART2SEL', 'UART2CKEN', 'UART2DIV'];
NUTOOL_CLOCK.g_Module.USCI0 = ['PCLK0', 'USCI0CKEN', 'none'];
NUTOOL_CLOCK.g_Module.WDT = ['WDTSEL', 'WDTCKEN', 'none'];
NUTOOL_CLOCK.g_Module.WWDT = ['WWDTSEL', 'WDTCKEN', 'none'];
NUTOOL_CLOCK.g_Module.CLKO = ['CLKOSEL', 'CLKOCKEN/DIV1EN/CLKOEN', 'none'];
NUTOOL_CLOCK.g_Module.CLKO_Divider = ['CLKOSEL', 'CLKOCKEN/!DIV1EN/CLKOEN', 'FREQSEL'];
NUTOOL_CLOCK.g_Module.SYSTICK = ['STCLKSEL/SYST_CTRL[2]', 'ENABLE', 'none'];

NUTOOL_CLOCK.g_unusedModule = {};
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

NUTOOL_CLOCK.g_BusNonExistent = [];
NUTOOL_CLOCK.g_BusFromPCLK1 = ['ACMP01', 'ADC', 'I2C1', 'PWM1', 'SPI0', 'TMR2', 'TMR3', 'UART1'];
NUTOOL_CLOCK.g_DIV_Module_Defines = [];
NUTOOL_CLOCK.g_CPUCLKLimit = 48 * 1000000;
NUTOOL_CLOCK.g_HXTRange = '4~32MHz';
NUTOOL_CLOCK.g_HXTfrequency = 32 * 1000000;
NUTOOL_CLOCK.g_HIRCfrequencyArray = [];
NUTOOL_CLOCK.g_HIRCfrequency = 48 * 1000000;
NUTOOL_CLOCK.g_HIRC2frequencyArray = [];
NUTOOL_CLOCK.g_HIRC2frequency = 0;
NUTOOL_CLOCK.g_HIRC48frequency = 0;
NUTOOL_CLOCK.g_LIRCfrequency = 38.4 * 1000;
NUTOOL_CLOCK.g_MIRCfrequency = 0;
NUTOOL_CLOCK.g_MIRC1P2Mfrequency = 0;
NUTOOL_CLOCK.g_RTC32kfrequency = 0;
NUTOOL_CLOCK.g_PLL480Mfrequency = 0;
NUTOOL_CLOCK.g_HSUSBOTGPHYfrequency = 0;
