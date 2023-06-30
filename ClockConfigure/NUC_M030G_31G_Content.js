// chip content
NUTOOL_CLOCK.g_cfg_chips = [
	// M030G_31G
	{ name: "M030GGD1AE", pkg: "QFN24" },
	{ name: "M030GGC1AE", pkg: "QFN24" },
	{ name: "M030GTC1AE", pkg: "QFN33" },
	{ name: "M030GTD1AE", pkg: "QFN33" },
	{ name: "M031GGD2AE", pkg: "QFN24" },
	{ name: "M031GGC2AE", pkg: "QFN24" },
	{ name: "M031GTD2AE", pkg: "QFN33" },
	{ name: "M031GTC2AE", pkg: "QFN33" }
];

NUTOOL_CLOCK.g_register_map = [];
NUTOOL_CLOCK.g_register_map.PWRCTL = ['HIRCEN:2'];
NUTOOL_CLOCK.g_register_map.AHBCLK = ['CRCCKEN:7', 'ISPCKEN:2', 'PDMACKEN:1'];
NUTOOL_CLOCK.g_register_map.APBCLK0 = ['ADCCKEN:28', 'UART0CKEN:16', 'SPI0CKEN:13', 'I2C1CKEN:9', 'I2C0CKEN:8', 'CLKOCKEN:6', 'TMR3CKEN:5', 'TMR2CKEN:4', 'TMR1CKEN:3', 'TMR0CKEN:2', 'WDTCKEN:0'];
NUTOOL_CLOCK.g_register_map.APBCLK1 = ['TMR5CKEN:29', 'TMR4CKEN:28', 'MANCHCKEN:24', 'BPWM1CKEN:19', 'DAC23CKEN:13', 'DAC01CKEN:12'];
NUTOOL_CLOCK.g_register_map.CLKSEL0 = ['STCLKSEL:5-3', 'HCLKSEL:2-0'];
NUTOOL_CLOCK.g_register_map.CLKSEL1 = ['UART0SEL:26-24', 'TMR3SEL:22-20', 'TMR2SEL:18-16', 'TMR1SEL:14-12', 'TMR0SEL:10-8', 'CLKOSEL:6-4', 'WWDTSEL:3-2', 'WDTSEL:1-0'];
NUTOOL_CLOCK.g_register_map.CLKSEL2 = ['ADCSEL:21-20', 'TMR5SEL:18-16', 'TMR4SEL:14-12', 'BPWM1SEL:9', 'SPI0SEL:5-4'];
NUTOOL_CLOCK.g_register_map.CLKDIV0 = ['ADCDIV:23-16', 'UART0DIV:11-8', 'HCLKDIV:3-0'];
NUTOOL_CLOCK.g_register_map.PCLKDIV = ['APB1DIV:6-4', 'APB0DIV:2-0'];
NUTOOL_CLOCK.g_register_map.PLLCTL = ['OE:18', 'BP:17', 'PD:16', 'OUTDIV:15-14', 'INDIV:13-9', 'FBDIV:8-0'];
NUTOOL_CLOCK.g_register_map.CLKOCTL = ['DIV1EN:5', 'CLKOEN:4', 'FREQSEL:3-0'];
NUTOOL_CLOCK.g_register_map.SYST_CTRL = ['CLKSRC:2', 'ENABLE:0'];

// Be careful. The order of g_register_map_default will affect the result in the generated code.
NUTOOL_CLOCK.g_register_map_default = [];
NUTOOL_CLOCK.g_register_map_default.CLKDIV0    = '0x00000000';
NUTOOL_CLOCK.g_register_map_default.PCLKDIV    = '0x00000000';
NUTOOL_CLOCK.g_register_map_default.CLKSEL0    = '0x0000003F';
NUTOOL_CLOCK.g_register_map_default.CLKSEL1    = '0x4477773B';
NUTOOL_CLOCK.g_register_map_default.CLKSEL2    = '0x0027732B';
NUTOOL_CLOCK.g_register_map_default.PWRCTL     = '0x02310014';
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
NUTOOL_CLOCK.g_register_map_description.CLKDIV0    = '0x40000220';
NUTOOL_CLOCK.g_register_map_description.PCLKDIV    = '0x40000234';
NUTOOL_CLOCK.g_register_map_description.PLLCTL     = '0x40000240';
NUTOOL_CLOCK.g_register_map_description.CLKOCTL    = '0x40000260';
NUTOOL_CLOCK.g_register_map_description.SYST_CTRL  = '0xE000E010';

NUTOOL_CLOCK.g_CLKSEL = [];
NUTOOL_CLOCK.g_CLKSEL.APB0DIV = ['HCLK:0', 'HCLK/2:1', 'HCLK/4:2', 'HCLK/8:3', 'HCLK/16:4'];
NUTOOL_CLOCK.g_CLKSEL.APB1DIV = ['HCLK:0', 'HCLK/2:1', 'HCLK/4:2', 'HCLK/8:3', 'HCLK/16:4'];
NUTOOL_CLOCK.g_CLKSEL.ADCSEL = ['PLL:1', 'PCLK1:2', 'HIRC:3'];
NUTOOL_CLOCK.g_CLKSEL.BPWM1SEL = ['PLL:0', 'PCLK1:1'];
NUTOOL_CLOCK.g_CLKSEL.CLKOSEL = ['HCLK:2', 'HIRC:3', 'LIRC:4', 'HIRC:5', 'PLL:6'];
NUTOOL_CLOCK.g_CLKSEL.HCLKSEL = ['PLL:2', 'HIRC:7'];
NUTOOL_CLOCK.g_CLKSEL.SPI0SEL = ['PLL:1', 'PCLK1:2', 'HIRC:3'];
NUTOOL_CLOCK.g_CLKSEL.STCLKSEL = ['HCLK/2:3', 'HIRC/2:7'];
NUTOOL_CLOCK.g_CLKSEL.TMR0SEL = ['PCLK0:2', 'LIRC:5', 'HIRC:7']; // 'external:3'
NUTOOL_CLOCK.g_CLKSEL.TMR1SEL = ['PCLK0:2', 'LIRC:5', 'HIRC:7']; // 'external:3'
NUTOOL_CLOCK.g_CLKSEL.TMR2SEL = ['PCLK1:2', 'LIRC:5', 'HIRC:7']; // 'external:3'
NUTOOL_CLOCK.g_CLKSEL.TMR3SEL = ['PCLK1:2', 'LIRC:5', 'HIRC:7']; // 'external:3'
NUTOOL_CLOCK.g_CLKSEL.TMR4SEL = ['PCLK0:2', 'LIRC:5', 'HIRC:7']; // 'external:3'
NUTOOL_CLOCK.g_CLKSEL.TMR5SEL = ['PCLK0:2', 'LIRC:5', 'HIRC:7']; // 'external:3'
NUTOOL_CLOCK.g_CLKSEL.UART0SEL = ['PLL:1', 'HIRC:3', 'PCLK0:4', 'LIRC:5'];
NUTOOL_CLOCK.g_CLKSEL.WDTSEL = ['HCLK/2048:2', 'LIRC:3'];
NUTOOL_CLOCK.g_CLKSEL.WWDTSEL = ['HCLK/2048:2', 'LIRC:3'];
NUTOOL_CLOCK.g_CLKSEL_EXTENDED = [];

NUTOOL_CLOCK.g_Module = [];
NUTOOL_CLOCK.g_Module.ADC = ['ADCSEL', 'ADCCKEN', 'ADCDIV'];
NUTOOL_CLOCK.g_Module.BPWM1 = ['BPWM1SEL', 'BPWM1CKEN', 'none'];
NUTOOL_CLOCK.g_Module.CRC = ['HCLK', 'CRCCKEN', 'none'];
NUTOOL_CLOCK.g_Module.DAC01 = ['PCLK1', 'DAC01CKEN', 'none'];
NUTOOL_CLOCK.g_Module.DAC23 = ['PCLK1', 'DAC23CKEN', 'none'];
NUTOOL_CLOCK.g_Module.I2C0 = ['PCLK0', 'I2C0CKEN', 'none'];
NUTOOL_CLOCK.g_Module.I2C1 = ['PCLK1', 'I2C1CKEN', 'none'];
NUTOOL_CLOCK.g_Module.ISP = ['HIRC', 'ISPCKEN', 'none'];
NUTOOL_CLOCK.g_Module.MANCH = ['PCLK0', 'MANCHCKEN', 'none'];
NUTOOL_CLOCK.g_Module.PDMA = ['HCLK', 'PDMACKEN', 'none'];
NUTOOL_CLOCK.g_Module.SPI0 = ['SPI0SEL', 'SPI0CKEN', 'none'];
NUTOOL_CLOCK.g_Module.TMR0 = ['TMR0SEL', 'TMR0CKEN', 'none'];
NUTOOL_CLOCK.g_Module.TMR1 = ['TMR1SEL', 'TMR1CKEN', 'none'];
NUTOOL_CLOCK.g_Module.TMR2 = ['TMR2SEL', 'TMR2CKEN', 'none'];
NUTOOL_CLOCK.g_Module.TMR3 = ['TMR3SEL', 'TMR3CKEN', 'none'];
NUTOOL_CLOCK.g_Module.TMR4 = ['TMR4SEL', 'TMR4CKEN', 'none'];
NUTOOL_CLOCK.g_Module.TMR5 = ['TMR5SEL', 'TMR5CKEN', 'none'];
NUTOOL_CLOCK.g_Module.UART0 = ['UART0SEL', 'UART0CKEN', 'UART0DIV'];
NUTOOL_CLOCK.g_Module.WDT = ['WDTSEL', 'WDTCKEN', 'none'];
NUTOOL_CLOCK.g_Module.WWDT = ['WWDTSEL', 'WDTCKEN', 'none'];
NUTOOL_CLOCK.g_Module.CLKO = ['CLKOSEL', 'CLKOCKEN/DIV1EN/CLKOEN', 'none'];
NUTOOL_CLOCK.g_Module.CLKO_Divider = ['CLKOSEL', 'CLKOCKEN/!DIV1EN/CLKOEN', 'FREQSEL'];
NUTOOL_CLOCK.g_Module.SYSTICK = ['STCLKSEL/SYST_CTRL[2]', 'ENABLE', 'none'];

NUTOOL_CLOCK.g_unusedModule = {
	"M030GGD1AE(QFN24)": ["PLL", "TMR2", "TMR3", "TMR4", "TMR5", "MANCH"],
	"M030GGC1AE(QFN24)": ["PLL", "TMR2", "TMR3", "TMR4", "TMR5", "MANCH"],
	"M030GTC1AE(QFN33)": ["PLL", "TMR2", "TMR3", "TMR4", "TMR5", "MANCH"],
	"M030GTD1AE(QFN33)": ["PLL", "TMR2", "TMR3", "TMR4", "TMR5", "MANCH"]
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

NUTOOL_CLOCK.g_BusNonExistent = [];
NUTOOL_CLOCK.g_BusFromPCLK1 = ['ADC', 'I2C1', 'BPWM1', 'TMR2', 'TMR3', 'DAC01', 'DAC23', 'SPI0'];
NUTOOL_CLOCK.g_DIV_Module_Defines = [];
NUTOOL_CLOCK.g_CPUCLKLimit = {
	// 48MHz
	'M030GGD1AE': '48000000',
	'M030GGC1AE': '48000000',
	'M030GTC1AE': '48000000',
	'M030GTD1AE': '48000000',
	// 72MHz
	'M031GGD2AE': '72000000',
	'M031GGC2AE': '72000000',
	'M031GTD2AE': '72000000',
	'M031GTC2AE': '72000000'
};
NUTOOL_CLOCK.g_HXTRange = '';
NUTOOL_CLOCK.g_HXTfrequency = 0;
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
