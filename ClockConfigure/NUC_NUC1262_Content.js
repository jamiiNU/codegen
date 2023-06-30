// chip content
NUTOOL_CLOCK.g_cfg_chips = [
	//NUC100CN
	{ name: "NUC130VE3CN", pkg: "LQFP100" },
	{ name: "NUC140VE3CN", pkg: "LQFP100" },
	{ name: "NUC130RC1CN", pkg: "LQFP64" },
	{ name: "NUC130RD2CN", pkg: "LQFP64" },
	{ name: "NUC130RE3CN", pkg: "LQFP64" },
	{ name: "NUC140RC1CN", pkg: "LQFP64" },
	{ name: "NUC140RD2CN", pkg: "LQFP64" },
	{ name: "NUC140RE3CN", pkg: "LQFP64" },
	{ name: "NUC130LC1CN", pkg: "LQFP48" },
	{ name: "NUC130LD2CN", pkg: "LQFP48" },
	{ name: "NUC130LE3CN", pkg: "LQFP48" },
	{ name: "NUC140LC1CN", pkg: "LQFP48" },
	{ name: "NUC140LD2CN", pkg: "LQFP48" },
	{ name: "NUC140LE3CN", pkg: "LQFP48" },
	//NUC100DN
	{ name: "NUC100VE3DN", pkg: "LQFP100" },
	{ name: "NUC100RC1DN", pkg: "LQFP64" },
	{ name: "NUC100RD1DN", pkg: "LQFP64" },
	{ name: "NUC100RD2DN", pkg: "LQFP64" },
	{ name: "NUC100RE3DN", pkg: "LQFP64" },
	{ name: "NUC100LC1DN", pkg: "LQFP48" },
	{ name: "NUC100LD2DN", pkg: "LQFP48" },
	{ name: "NUC100LE3DN", pkg: "LQFP48" },
	{ name: "NUC120VE3DN", pkg: "LQFP100" },
	{ name: "NUC120RC1DN", pkg: "LQFP64" },
	{ name: "NUC120RD2DN", pkg: "LQFP64" },
	{ name: "NUC120RE3DN", pkg: "LQFP64" },
	{ name: "NUC120LC1DN", pkg: "LQFP48" },
	{ name: "NUC120LD2DN", pkg: "LQFP48" },
	{ name: "NUC120LE3DN", pkg: "LQFP48" },
	//NUC131
	{ name: "NUC131SC2AE", pkg: "LQFP64" },
	{ name: "NUC131SD2AE", pkg: "LQFP64" },
	{ name: "NUC131LC2AE", pkg: "LQFP48" },
	{ name: "NUC131LD2AE", pkg: "LQFP48" },
	//NUC121AE
	{ name: "NUC121SC2AE", pkg: "LQFP64" },
	{ name: "NUC121LC2AE", pkg: "LQFP48" },
	{ name: "NUC121ZC2AE", pkg: "QFN33" },
	{ name: "NUC125SC2AE", pkg: "LQFP64" },
	{ name: "NUC125LC2AE", pkg: "LQFP48" },
	{ name: "NUC125ZC2AE", pkg: "QFN33" },
	//NUC123AN
	{ name: "NUC123ZD4AN0", pkg: "QFN33" },
	{ name: "NUC123ZC2AN1", pkg: "QFN33" },
	{ name: "NUC123LD4AN0", pkg: "LQFP48" },
	{ name: "NUC123LC2AN1", pkg: "LQFP48" },
	{ name: "NUC123SD4AN0", pkg: "LQFP64" },
	{ name: "NUC123SC2AN1", pkg: "LQFP64" },
	//NUC123AE
	{ name: "NUC123ZD4AE0", pkg: "QFN33" },
	{ name: "NUC123ZC2AE1", pkg: "QFN33" },
	{ name: "NUC123SD4AE0", pkg: "LQFP64" },
	{ name: "NUC123SC2AE1", pkg: "LQFP64" },
	{ name: "NUC123LD4AE0", pkg: "LQFP48" },
	{ name: "NUC123LC2AE1", pkg: "LQFP48" },
	//NUC126
	{ name: "NUC126LE4AE", pkg: "LQFP48" },
	{ name: "NUC126LG4AE", pkg: "LQFP48" },
	{ name: "NUC126SE4AE", pkg: "LQFP64" },
	{ name: "NUC126SG4AE", pkg: "LQFP64" },
	{ name: "NUC126VG4AE", pkg: "LQFP100" },
	// NUC1261
	{ name: "NUC1261LG4AE", pkg: "LQFP48" },
	{ name: "NUC1261LE4AE", pkg: "LQFP48" },
	{ name: "NUC1261NE4AE", pkg: "LQFP48" },
	{ name: "NUC1261SG4AE", pkg: "LQFP64" },
	{ name: "NUC1261SE4AE", pkg: "LQFP64" },
	// NUC1262
	{ name: "NUC1262NE4AE", pkg: "QFN48" },
	{ name: "NUC1262LE4AE", pkg: "LQFP48" },
	{ name: "NUC1262SE4AE", pkg: "LQFP64" },
	// NUC1263
	{ name: "NUC1263", pkg: "QFN48" }
];

NUTOOL_CLOCK.g_register_map = [];
NUTOOL_CLOCK.g_register_map.PWRCTL = ['LIRCEN:3', 'HIRCEN:2', 'LXTEN:1', 'HXTEN:0'];
NUTOOL_CLOCK.g_register_map.AHBCLK = ['GPIOFCKEN:21', 'GPIODCKEN:19', 'GPIOCCKEN:18', 'GPIOBCKEN:17', 'GPIOACKEN:16', 'FMCIDLE:15', 'CRCCKEN:7', 'ISPCKEN:2', 'PDMACKEN:1'];
NUTOOL_CLOCK.g_register_map.APBCLK0 = ['ADCCKEN:28', 'USBDCKEN:27', 'BPWM3CKEN:23', 'BPWM2CKEN:22', 'BPWM1CKEN:21', 'BPWM0CKEN:20', 'UART1CKEN:17', 'UART0CKEN:16', 'SPI1CKEN:13', 'SPI0CKEN:12', 'I2C1CKEN:9', 'I2C0CKEN:8', 'CLKOCKEN:6', 'TMR3CKEN:5', 'TMR2CKEN:4', 'TMR1CKEN:3', 'TMR0CKEN:2', 'WDTCKEN:0'];
NUTOOL_CLOCK.g_register_map.APBCLK1 = ['LLSI9CKEN:25', 'LLSI8CKEN:24', 'LLSI7CKEN:23', 'LLSI6CKEN:22', 'LLSI5CKEN:21', 'LLSI4CKEN:20', 'LLSI3CKEN:19', 'LLSI2CKEN:18', 'LLSI1CKEN:17', 'LLSI0CKEN:16'];
NUTOOL_CLOCK.g_register_map.CLKSEL0 = ['PCLK1SEL:7', 'PCLK0SEL:6', 'STCLKSEL:5-3', 'HCLKSEL:2-0'];
NUTOOL_CLOCK.g_register_map.CLKSEL1 = ['UART1SEL:27-26', 'UART0SEL:25-24', 'TMR3SEL:22-20', 'TMR2SEL:18-16', 'TMR1SEL:14-12', 'TMR0SEL:10-8', 'ADCSEL:3-2', 'WDTSEL:1-0'];
NUTOOL_CLOCK.g_register_map.CLKSEL2 = ['SPI1SEL:27-26', 'SPI0SEL:25-24', 'WWDTSEL:17-16', 'CLKOSEL:4-2'];
NUTOOL_CLOCK.g_register_map.CLKSEL3 = ['USBDSEL:8'];
NUTOOL_CLOCK.g_register_map.CLKDIV0 = ['ADCDIV:23-16', 'UART1DIV:15-12', 'UART0DIV:11-8', 'USBDIV:7-4', 'HCLKDIV:3-0'];
NUTOOL_CLOCK.g_register_map.PLLCTL = ['PLL_SRC:19', 'OE:18', 'BP:17', 'PD:16', 'OUT_DV:15-14', 'IN_DV:13-9', 'FB_DV:8-0'];
NUTOOL_CLOCK.g_register_map.CLKOCTL = ['DIV1EN:5', 'CLKOEN:4', 'FREQSEL:3-0'];
NUTOOL_CLOCK.g_register_map.SYST_CTRL = ['CLKSRC:2', 'ENABLE:0'];

// Be careful. The order of g_register_map_default will affect the result in the generated code.
NUTOOL_CLOCK.g_register_map_default = [];
NUTOOL_CLOCK.g_register_map_default.CLKDIV0  = '0x00000000';
NUTOOL_CLOCK.g_register_map_default.CLKSEL0  = '0x0000003F';
NUTOOL_CLOCK.g_register_map_default.CLKSEL1  = '0x0F77770F';
NUTOOL_CLOCK.g_register_map_default.CLKSEL2  = '0x00020008';
NUTOOL_CLOCK.g_register_map_default.CLKSEL3  = '0x00000000';
NUTOOL_CLOCK.g_register_map_default.PWRCTL   = '0x0000001F';
NUTOOL_CLOCK.g_register_map_default.AHBCLK   = {
								"NuClockConfig":     '0x003F8004',
								"NuClockConfigTest": '0x003F8004',
								"NuCodeGenTool":     '0x003F8004',
								"NuCodeGenTest":     '0x003F8086'
};
NUTOOL_CLOCK.g_register_map_default.APBCLK0  = {
								"NuClockConfig":     '0x00000001',
								"NuClockConfigTest": '0x00000001',
								"NuCodeGenTool":     '0x00000001',
								"NuCodeGenTest":     '0x18F3337D'
};
NUTOOL_CLOCK.g_register_map_default.APBCLK1  = {
								"NuClockConfig":     '0x00000000',
								"NuClockConfigTest": '0x00000000',
								"NuCodeGenTool":     '0x00000000',
								"NuCodeGenTest":     '0x03FF0000'
};
NUTOOL_CLOCK.g_register_map_default.PLLCTL   = {
								"NuClockConfig":     '0x008D8016',
								"NuClockConfigTest": '0x008D8016',
								"NuCodeGenTool":     '0x008D8016',
								"NuCodeGenTest":     '0x008A0012'
};
NUTOOL_CLOCK.g_register_map_default.CLKOCTL  = {
								"NuClockConfig":     '0x00000000',
								"NuClockConfigTest": '0x00000000',
								"NuCodeGenTool":     '0x00000000',
								"NuCodeGenTest":     '0x00000030'
};
NUTOOL_CLOCK.g_register_map_default.SYST_CTRL = {
								"NuClockConfig":     '0x00000000',
								"NuClockConfigTest": '0x00000000',
								"NuCodeGenTool":     '0x00000000',
								"NuCodeGenTest":     '0x00000001'
};

NUTOOL_CLOCK.g_register_map_description = [];
NUTOOL_CLOCK.g_register_map_description.PWRCTL   = '0x50000200';
NUTOOL_CLOCK.g_register_map_description.AHBCLK   = '0x50000204';
NUTOOL_CLOCK.g_register_map_description.APBCLK0  = '0x50000208';
NUTOOL_CLOCK.g_register_map_description.APBCLK1  = '0x50000230';
NUTOOL_CLOCK.g_register_map_description.CLKSEL0  = '0x50000210';
NUTOOL_CLOCK.g_register_map_description.CLKSEL1  = '0x50000214';
NUTOOL_CLOCK.g_register_map_description.CLKSEL2  = '0x5000021C';
NUTOOL_CLOCK.g_register_map_description.CLKSEL3  = '0x50000234';
NUTOOL_CLOCK.g_register_map_description.CLKDIV0  = '0x50000218';
NUTOOL_CLOCK.g_register_map_description.PLLCTL   = '0x50000220';
NUTOOL_CLOCK.g_register_map_description.CLKOCTL  = '0x50000224';
NUTOOL_CLOCK.g_register_map_description.SYST_CTRL = '0xE000E010';

NUTOOL_CLOCK.g_CLKSEL = [];
NUTOOL_CLOCK.g_CLKSEL.ADCSEL = ['HXT:0', 'PLL:1', 'PCLK0:2', 'HIRC/2:3'];
NUTOOL_CLOCK.g_CLKSEL.CLKOSEL = ['HXT:0', 'LXT:1', 'HCLK:2', 'HIRC/2:3', 'HIRC:5'];
NUTOOL_CLOCK.g_CLKSEL.HCLKSEL = ['HXT:0', 'LXT:1', 'PLL/2:2', 'LIRC:3', 'HIRC:4', 'HIRC/2:7'];
NUTOOL_CLOCK.g_CLKSEL.PCLK0SEL = ['HCLK:0', 'HCLK/2:1'];
NUTOOL_CLOCK.g_CLKSEL.PCLK1SEL = ['HCLK:0', 'HCLK/2:1'];
NUTOOL_CLOCK.g_CLKSEL.SPI0SEL = ['HXT:0', 'PLL/2:1', 'PCLK0:2', 'HIRC:3'];
NUTOOL_CLOCK.g_CLKSEL.SPI1SEL = ['HXT:0', 'PLL/2:1', 'PCLK0:2', 'HIRC:3'];
NUTOOL_CLOCK.g_CLKSEL.STCLKSEL = ['HXT:0', 'LXT:1', 'HXT/2:2', 'HCLK/2:3', 'HIRC/4:7'];
NUTOOL_CLOCK.g_CLKSEL.TMR0SEL = ['HXT:0', 'LXT:1', 'PCLK0:2', 'LIRC:5', 'HIRC/2:7']; //'external:3',
NUTOOL_CLOCK.g_CLKSEL.TMR1SEL = ['HXT:0', 'LXT:1', 'PCLK0:2', 'LIRC:5', 'HIRC/2:7']; //'external:3',
NUTOOL_CLOCK.g_CLKSEL.TMR2SEL = ['HXT:0', 'LXT:1', 'PCLK1:2', 'LIRC:5', 'HIRC/2:7']; //'external:3',
NUTOOL_CLOCK.g_CLKSEL.TMR3SEL = ['HXT:0', 'LXT:1', 'PCLK1:2', 'LIRC:5', 'HIRC/2:7']; //'external:3',
NUTOOL_CLOCK.g_CLKSEL.UART0SEL = ['HXT:0', 'PLL/2:1', 'LXT:2', 'HIRC/2:3'];
NUTOOL_CLOCK.g_CLKSEL.UART1SEL = ['HXT:0', 'PLL/2:1', 'LXT:2', 'HIRC/2:3'];
NUTOOL_CLOCK.g_CLKSEL.USBDSEL = ['HIRC:0', 'PLL/(USBDIV+1):1'];
NUTOOL_CLOCK.g_CLKSEL.WDTSEL = ['LXT:1', 'HCLK/2048:2', 'LIRC:3'];
NUTOOL_CLOCK.g_CLKSEL.WWDTSEL = ['HCLK/2048:2', 'LIRC:3'];

NUTOOL_CLOCK.g_CLKSEL_EXTENDED = [];

NUTOOL_CLOCK.g_Module = [];
NUTOOL_CLOCK.g_Module.ADC = ['ADCSEL', 'ADCCKEN', 'ADCDIV'];
NUTOOL_CLOCK.g_Module.BPWM0 = ['PCLK0', 'BPWM0CKEN', 'none'];
NUTOOL_CLOCK.g_Module.BPWM1 = ['PCLK1', 'BPWM1CKEN', 'none'];
NUTOOL_CLOCK.g_Module.BPWM2 = ['PCLK0', 'BPWM2CKEN', 'none'];
NUTOOL_CLOCK.g_Module.BPWM3 = ['PCLK1', 'BPWM3CKEN', 'none'];
NUTOOL_CLOCK.g_Module.CRC = ['HCLK', 'CRCCKEN', 'none'];
NUTOOL_CLOCK.g_Module.GPIOA = ['HCLK', 'GPIOACKEN', 'none'];
NUTOOL_CLOCK.g_Module.GPIOB = ['HCLK', 'GPIOBCKEN', 'none'];
NUTOOL_CLOCK.g_Module.GPIOC = ['HCLK', 'GPIOCCKEN', 'none'];
NUTOOL_CLOCK.g_Module.GPIOD = ['HCLK', 'GPIODCKEN', 'none'];
NUTOOL_CLOCK.g_Module.GPIOF = ['HCLK', 'GPIOFCKEN', 'none'];
NUTOOL_CLOCK.g_Module.I2C0 = ['PCLK0', 'I2C0CKEN', 'none'];
NUTOOL_CLOCK.g_Module.I2C1 = ['PCLK1', 'I2C1CKEN', 'none'];
NUTOOL_CLOCK.g_Module.ISP = ['HIRC', 'ISPCKEN', 'none'];
NUTOOL_CLOCK.g_Module.LLSI0 = ['PCLK0', 'LLSI0CKEN', 'none'];
NUTOOL_CLOCK.g_Module.LLSI1 = ['PCLK1', 'LLSI1CKEN', 'none'];
NUTOOL_CLOCK.g_Module.LLSI2 = ['PCLK0', 'LLSI2CKEN', 'none'];
NUTOOL_CLOCK.g_Module.LLSI3 = ['PCLK1', 'LLSI3CKEN', 'none'];
NUTOOL_CLOCK.g_Module.LLSI4 = ['PCLK0', 'LLSI4CKEN', 'none'];
NUTOOL_CLOCK.g_Module.LLSI5 = ['PCLK1', 'LLSI5CKEN', 'none'];
NUTOOL_CLOCK.g_Module.LLSI6 = ['PCLK0', 'LLSI6CKEN', 'none'];
NUTOOL_CLOCK.g_Module.LLSI7 = ['PCLK1', 'LLSI7CKEN', 'none'];
NUTOOL_CLOCK.g_Module.LLSI8 = ['PCLK0', 'LLSI8CKEN', 'none'];
NUTOOL_CLOCK.g_Module.LLSI9 = ['PCLK1', 'LLSI9CKEN', 'none'];
NUTOOL_CLOCK.g_Module.PDMA = ['HCLK', 'PDMACKEN', 'none'];
NUTOOL_CLOCK.g_Module.SPI0 = ['SPI0SEL', 'SPI0CKEN', 'none'];
NUTOOL_CLOCK.g_Module.SPI1 = ['SPI1SEL', 'SPI1CKEN', 'none'];
NUTOOL_CLOCK.g_Module.TMR0 = ['TMR0SEL', 'TMR0CKEN', 'none'];
NUTOOL_CLOCK.g_Module.TMR1 = ['TMR1SEL', 'TMR1CKEN', 'none'];
NUTOOL_CLOCK.g_Module.TMR2 = ['TMR2SEL', 'TMR2CKEN', 'none'];
NUTOOL_CLOCK.g_Module.TMR3 = ['TMR3SEL', 'TMR3CKEN', 'none'];
NUTOOL_CLOCK.g_Module.UART0 = ['UART0SEL', 'UART0CKEN', 'UART0DIV'];
NUTOOL_CLOCK.g_Module.UART1 = ['UART1SEL', 'UART1CKEN', 'UART1DIV'];
NUTOOL_CLOCK.g_Module.USBD = ['USBDSEL', 'USBDCKEN', 'none'];
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

NUTOOL_CLOCK.g_BusNonExistent = [];
NUTOOL_CLOCK.g_BusFromPCLK1 = ['LLSI1', 'LLSI3', 'LLSI5', 'LLSI7', 'LLSI9'];
NUTOOL_CLOCK.g_DIV_Module_Defines = ['USBD:USB'];
NUTOOL_CLOCK.g_CPUCLKLimit = 72 * 1000000;
NUTOOL_CLOCK.g_HXTRange = '4~24MHz';
NUTOOL_CLOCK.g_HXTfrequency = 12 * 1000000;
NUTOOL_CLOCK.g_HIRCfrequencyArray = [];
NUTOOL_CLOCK.g_HIRCfrequency = 48 * 1000000;
NUTOOL_CLOCK.g_HIRC2frequencyArray = [];
NUTOOL_CLOCK.g_HIRC2frequency = 0;
NUTOOL_CLOCK.g_HIRC48frequency = 0;
NUTOOL_CLOCK.g_LIRCfrequency = 10 * 1000;
NUTOOL_CLOCK.g_MIRCfrequency = 0;
NUTOOL_CLOCK.g_MIRC1P2Mfrequency = 0;
NUTOOL_CLOCK.g_RTC32kfrequency = 0;
NUTOOL_CLOCK.g_PLL480Mfrequency = 0;
NUTOOL_CLOCK.g_HSUSBOTGPHYfrequency = 0;
