// chip content
NUTOOL_CLOCK.g_cfg_chips = [
	//M251
	{ name: "M251FB2AE", pkg: "TSSOP20" },
	{ name: "M251FC2AE", pkg: "TSSOP20" },
	{ name: "M251EB2AE", pkg: "TSSOP28" },
	{ name: "M251EC2AE", pkg: "TSSOP28" },
	{ name: "M251ZB2AE", pkg: "QFN33" },
	{ name: "M251ZC2AE", pkg: "QFN33" },
	{ name: "M251ZD2AE", pkg: "QFN33" },
	{ name: "M251LC2AE", pkg: "LQFP48" },
	{ name: "M251LD2AE", pkg: "LQFP48" },
	{ name: "M251LE3AE", pkg: "LQFP48" },
	{ name: "M251LG6AE", pkg: "LQFP48" },
	{ name: "M251SC2AE", pkg: "LQFP64" },
	{ name: "M251SD2AE", pkg: "LQFP64" },
	{ name: "M251SE3AE", pkg: "LQFP64" },
	{ name: "M251SG6AE", pkg: "LQFP64" },
	{ name: "M251KE3AE", pkg: "LQFP128" },
	{ name: "M251KG6AE", pkg: "LQFP128" },
	//M252
	{ name: "M252FC2AE", pkg: "TSSOP20" },
	{ name: "M252EC2AE", pkg: "TSSOP28" },
	{ name: "M252ZC2AE", pkg: "QFN33" },
	{ name: "M252ZD2AE", pkg: "QFN33" },
	{ name: "M252LC2AE", pkg: "LQFP48" },
	{ name: "M252LD2AE", pkg: "LQFP48" },
	{ name: "M252LE3AE", pkg: "LQFP48" },
	{ name: "M252LG6AE", pkg: "LQFP48" },
	{ name: "M252SC2AE", pkg: "LQFP64" },
	{ name: "M252SD2AE", pkg: "LQFP64" },
	{ name: "M252SE3AE", pkg: "LQFP64" },
	{ name: "M252SG6AE", pkg: "LQFP64" },
	{ name: "M252KE3AE", pkg: "LQFP128" },
	{ name: "M252KG6AE", pkg: "LQFP128" },
	//M253
	{ name: "M253ZE3AE", pkg: "QFN33" },
	{ name: "M253LD3AE", pkg: "LQFP48" },
	{ name: "M253LE3AE", pkg: "LQFP48" },
	//M256D
	{ name: "M254MD2AE", pkg: "LQFP44" },
	{ name: "M256MD2AE", pkg: "LQFP44" },
	{ name: "M254SD2AE", pkg: "LQFP64" },
	{ name: "M256SD2AE", pkg: "LQFP64" },
	//M258
	// { name: "M254SD3AE", pkg: "LQFP64" },
	{ name: "M254SE3AE", pkg: "LQFP64" },
	// { name: "M254QD3AE", pkg: "LQFP80" },
	//{ name: "M254QE3AE", pkg: "LQFP80" }, // Remove LQFP80 pkg
	// { name: "M254KD3AE", pkg: "LQFP128" },
	{ name: "M254KE3AE", pkg: "LQFP128" },
	//{ name: "M254ME3AE", pkg: "LQFP44" },
	// { name: "M256SD3AE", pkg: "LQFP64" },
	{ name: "M256SE3AE", pkg: "LQFP64" },
	// { name: "M256QD3AE", pkg: "LQFP80" },
	//{ name: "M256QE3AE", pkg: "LQFP80" }, // Remove LQFP80 pkg
	// { name: "M256KD3AE", pkg: "LQFP128" },
	{ name: "M256KE3AE", pkg: "LQFP128" },
	// { name: "M258SD3AE", pkg: "LQFP64" },
	{ name: "M258SE3AE", pkg: "LQFP64" },
	// { name: "M258QD3AE", pkg: "LQFP80" },
	//{ name: "M258QE3AE", pkg: "LQFP80" }, // Remove LQFP80 pkg
	// { name: "M258KD3AE", pkg: "LQFP128" },
	{ name: "M258KE3AE", pkg: "LQFP128" },
	//M258G
	{ name: "M254SG6AE", pkg: "LQFP64" },
	{ name: "M258SG6AE", pkg: "LQFP64" },
	//{ name: "M256QG6AE", pkg: "LQFP80" }, // Remove LQFP80 pkg
	//{ name: "M258QG6AE", pkg: "LQFP80" }, // Remove LQFP80 pkg
	{ name: "M254KG6AE", pkg: "LQFP128" },
	{ name: "M258KG6AE", pkg: "LQFP128" }
];

NUTOOL_CLOCK.g_register_map = [];
NUTOOL_CLOCK.g_register_map.PWRCTL = ['LIRCEN:3', 'HIRCEN:2', 'LXTEN:1', 'HXTEN:0', 'MIRCEN:19'];
NUTOOL_CLOCK.g_register_map.AHBCLK = ['GPFCKEN:29', 'GPECKEN:28', 'GPDCKEN:27', 'GPCCKEN:26', 'GPBCKEN:25', 'GPACKEN:24', 'FMCIDLE:15', 'CRPTCKEN:12', 'CRCCKEN:7', 'EXSTCKEN:4', 'EBICKEN:3', 'ISPCKEN:2', 'PDMACKEN:1'];
NUTOOL_CLOCK.g_register_map.APBCLK0 = ['TKCKEN:29', 'EADCCKEN:28', 'USBDCKEN:27', 'UART3CKEN:19', 'UART2CKEN:18', 'UART1CKEN:17', 'UART0CKEN:16', 'SPI1CKEN:14', 'SPI0CKEN:13', 'QSPI0CKEN:12', 'I2C1CKEN:9', 'I2C0CKEN:8', 'ACMP01CKEN:7', 'CLKOCKEN:6', 'TMR3CKEN:5', 'TMR2CKEN:4', 'TMR1CKEN:3', 'TMR0CKEN:2', 'RTCCKEN:1', 'WDTCKEN:0'];
NUTOOL_CLOCK.g_register_map.APBCLK1 = ['PSIOCKEN:31', 'OPACKEN:30', 'BPWM1CKEN:19', 'BPWM0CKEN:18', 'PWM1CKEN:17', 'PWM0CKEN:16', 'LCDCPCKEN:15', 'LCDCKEN:14', 'DACCKEN:12', 'USCI2CKEN:10', 'USCI1CKEN:9', 'USCI0CKEN:8', 'SC0CKEN:0'];
NUTOOL_CLOCK.g_register_map.CLKSEL0 = ['USBDSEL:8', 'STCLKSEL:5-3', 'HCLKSEL:2-0'];
NUTOOL_CLOCK.g_register_map.CLKSEL1 = ['UART1SEL:30-28', 'UART0SEL:26-24', 'TMR3SEL:22-20', 'TMR2SEL:18-16', 'TMR1SEL:14-12', 'TMR0SEL:10-8', 'CLKOSEL:6-4', 'WWDTSEL:3-2', 'WDTSEL:1-0'];
NUTOOL_CLOCK.g_register_map.CLKSEL2 = ['PSIOSEL:30-28', 'LCDCPSEL:25', 'LCDSEL:24', 'BPWM1SEL:9', 'BPWM0SEL:8', 'SPI1SEL:7-6', 'SPI0SEL:5-4', 'QSPI0SEL:3-2', 'PWM1SEL:1', 'PWM0SEL:0'];
NUTOOL_CLOCK.g_register_map.CLKSEL3 = ['UART3SEL:30-28', 'UART2SEL:26-24', 'SC0SEL:1-0'];
NUTOOL_CLOCK.g_register_map.CLKDIV0 = ['EADCDIV:23-16', 'UART1DIV:15-12', 'UART0DIV:11-8', 'USBDIV:7-4', 'HCLKDIV:3-0'];
NUTOOL_CLOCK.g_register_map.CLKDIV1 = ['PSIODIV:31-24', 'SC0DIV:7-0'];
NUTOOL_CLOCK.g_register_map.CLKDIV4 = ['UART3DIV:7-4', 'UART2DIV:3-0'];
NUTOOL_CLOCK.g_register_map.PCLKDIV = ['APB1DIV:6-4', 'APB0DIV:2-0'];
NUTOOL_CLOCK.g_register_map.PLLCTL = ['PLL_SRC:20-19', 'OE:18', 'BP:17', 'PD:16', 'OUTDIV:15-14', 'INDIV:12-9', 'FBDIV:5-0'];
NUTOOL_CLOCK.g_register_map.CLKOCTL = ['CLK1HZEN:6', 'DIV1EN:5', 'CLKOEN:4', 'FREQSEL:3-0'];
NUTOOL_CLOCK.g_register_map.SYST_CTRL = ['CLKSRC:2', 'ENABLE:0'];
NUTOOL_CLOCK.g_register_map.RTC_LXTCTL = ['RTCSEL:7', 'RTCSEL/32768:7'];

// Be careful. The order of g_register_map_default will affect the result in the generated code.
NUTOOL_CLOCK.g_register_map_default = [];
NUTOOL_CLOCK.g_register_map_default.CLKDIV0    = '0x00000000';
NUTOOL_CLOCK.g_register_map_default.CLKDIV1    = '0x00000000';
NUTOOL_CLOCK.g_register_map_default.CLKDIV4    = '0x00000000';
NUTOOL_CLOCK.g_register_map_default.PCLKDIV    = '0x00000000';
NUTOOL_CLOCK.g_register_map_default.CLKSEL0    = '0x0000001F';
NUTOOL_CLOCK.g_register_map_default.CLKSEL1    = '0x4422222B';
NUTOOL_CLOCK.g_register_map_default.CLKSEL2    = '0x200003AB';
NUTOOL_CLOCK.g_register_map_default.CLKSEL3    = '0x44000002';
NUTOOL_CLOCK.g_register_map_default.PWRCTL     = {
							"NuClockConfig":     '0x0079001F',
							"NuClockConfigTest": '0x0079001F',
							"NuCodeGenTool":     '0x0079001F',
							"NuCodeGenTest":     '0x0079001E'
};
NUTOOL_CLOCK.g_register_map_default.AHBCLK     = '0x00008004';
NUTOOL_CLOCK.g_register_map_default.APBCLK0    = '0x00000001';
NUTOOL_CLOCK.g_register_map_default.APBCLK1    = '0x00000000';
NUTOOL_CLOCK.g_register_map_default.PLLCTL     = '0x00054618';
NUTOOL_CLOCK.g_register_map_default.CLKOCTL    = '0x00000000';
NUTOOL_CLOCK.g_register_map_default.SYST_CTRL  = '0x00000000';
NUTOOL_CLOCK.g_register_map_default.RTC_LXTCTL = '0x780F000E';

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
NUTOOL_CLOCK.g_register_map_description.CLKDIV1    = '0x40000224';
NUTOOL_CLOCK.g_register_map_description.CLKDIV4    = '0x40000230';
NUTOOL_CLOCK.g_register_map_description.PCLKDIV    = '0x40000234';
NUTOOL_CLOCK.g_register_map_description.PLLCTL     = '0x40000240';
NUTOOL_CLOCK.g_register_map_description.CLKOCTL    = '0x40000260';
NUTOOL_CLOCK.g_register_map_description.SYST_CTRL  = '0xE000E010';
NUTOOL_CLOCK.g_register_map_description.RTC_LXTCTL = '0x40041100';

NUTOOL_CLOCK.g_CLKSEL = [];
NUTOOL_CLOCK.g_CLKSEL.APB0DIV = ['HCLK:0', 'HCLK/2:1', 'HCLK/4:2', 'HCLK/8:3', 'HCLK/16:4', 'HCLK/32:5'];
NUTOOL_CLOCK.g_CLKSEL.APB1DIV = ['HCLK:0', 'HCLK/2:1', 'HCLK/4:2', 'HCLK/8:3', 'HCLK/16:4', 'HCLK/32:5'];
NUTOOL_CLOCK.g_CLKSEL.BPWM0SEL = ['PLL:0', 'PCLK0:1'];
NUTOOL_CLOCK.g_CLKSEL.BPWM1SEL = ['PLL:0', 'PCLK1:1'];
NUTOOL_CLOCK.g_CLKSEL.CLKOSEL = ['HXT:0', 'LXT:1', 'HCLK:2', 'HIRC:3', 'LIRC:4', 'MIRC:5', 'PLL:6' /*'USBSOF:7'*/];
NUTOOL_CLOCK.g_CLKSEL.HCLKSEL = ['HXT:0', 'LXT:1', 'PLL:2', 'LIRC:3', 'MIRC:5', 'HIRC:7'];
NUTOOL_CLOCK.g_CLKSEL.LCDCPSEL = ['MIRC1P2M:0', 'MIRC:1'];
NUTOOL_CLOCK.g_CLKSEL.LCDSEL = ['LIRC:0', 'LXT:1'];
NUTOOL_CLOCK.g_CLKSEL.PSIOSEL = ['HXT:0', 'LXT:1', 'PCLK1:2', 'PLL:3', 'LIRC:4', 'HIRC:7'];
NUTOOL_CLOCK.g_CLKSEL.PWM0SEL = ['PLL:0', 'PCLK0:1'];
NUTOOL_CLOCK.g_CLKSEL.PWM1SEL = ['PLL:0', 'PCLK1:1'];
NUTOOL_CLOCK.g_CLKSEL.QSPI0SEL = ['HXT:0', 'PLL:1', 'PCLK0:2', 'HIRC:3'];
NUTOOL_CLOCK.g_CLKSEL.RTCSEL = ['LXT:0', 'LIRC:1'];
NUTOOL_CLOCK.g_CLKSEL['RTCSEL/32768'] = ['LXT/32768:0', 'LIRC/32768:1'];
NUTOOL_CLOCK.g_CLKSEL.SC0SEL = ['HXT:0', 'PLL:1', 'PCLK0:2', 'HIRC:3'];
NUTOOL_CLOCK.g_CLKSEL.SPI0SEL = ['HXT:0', 'PLL:1', 'PCLK1:2', 'HIRC:3'];
NUTOOL_CLOCK.g_CLKSEL.SPI1SEL = ['HXT:0', 'PLL:1', 'PCLK0:2', 'HIRC:3'];
NUTOOL_CLOCK.g_CLKSEL.STCLKSEL = ['HXT:0', 'LXT:1', 'HXT/2:2', 'HCLK/2:3', 'HIRC/2:7'];
NUTOOL_CLOCK.g_CLKSEL.TMR0SEL = ['HXT:0', 'LXT:1', 'PCLK0:2', 'LIRC:5', 'HIRC:7']; // 'external:3'
NUTOOL_CLOCK.g_CLKSEL.TMR1SEL = ['HXT:0', 'LXT:1', 'PCLK0:2', 'LIRC:5', 'HIRC:7']; // 'external:3'
NUTOOL_CLOCK.g_CLKSEL.TMR2SEL = ['HXT:0', 'LXT:1', 'PCLK1:2', 'LIRC:5', 'HIRC:7']; // 'external:3'
NUTOOL_CLOCK.g_CLKSEL.TMR3SEL = ['HXT:0', 'LXT:1', 'PCLK1:2', 'LIRC:5', 'HIRC:7']; // 'external:3'
NUTOOL_CLOCK.g_CLKSEL.UART0SEL = ['HXT:0', 'PLL:1', 'LXT:2', 'HIRC:3', 'PCLK0:4', 'LIRC:5'];
NUTOOL_CLOCK.g_CLKSEL.UART1SEL = ['HXT:0', 'PLL:1', 'LXT:2', 'HIRC:3', 'PCLK1:4', 'LIRC:5'];
NUTOOL_CLOCK.g_CLKSEL.UART2SEL = ['HXT:0', 'PLL:1', 'LXT:2', 'HIRC:3', 'PCLK0:4', 'LIRC:5'];
NUTOOL_CLOCK.g_CLKSEL.UART3SEL = ['HXT:0', 'PLL:1', 'LXT:2', 'HIRC:3', 'PCLK1:4', 'LIRC:5'];
NUTOOL_CLOCK.g_CLKSEL.USBDSEL = ['HIRC:0', 'PLL/(USBDIV+1):1'];
NUTOOL_CLOCK.g_CLKSEL.WDTSEL = ['LXT:1', 'HCLK/2048:2', 'LIRC:3'];
NUTOOL_CLOCK.g_CLKSEL.WWDTSEL = ['HCLK/2048:2', 'LIRC:3'];

NUTOOL_CLOCK.g_CLKSEL_EXTENDED = [];

NUTOOL_CLOCK.g_Module = [];
NUTOOL_CLOCK.g_Module.ACMP01 = ['PCLK1', 'ACMP01CKEN', 'none'];
NUTOOL_CLOCK.g_Module.BPWM0 = ['BPWM0SEL', 'BPWM0CKEN', 'none'];
NUTOOL_CLOCK.g_Module.BPWM1 = ['BPWM1SEL', 'BPWM1CKEN', 'none'];
NUTOOL_CLOCK.g_Module.CRPT = ['HCLK', 'CRPTCKEN', 'none'];
NUTOOL_CLOCK.g_Module.CRC = ['HCLK', 'CRCCKEN', 'none'];
NUTOOL_CLOCK.g_Module.DAC = ['PCLK1', 'DACCKEN', 'none'];
NUTOOL_CLOCK.g_Module.EADC = ['PCLK1', 'EADCCKEN', 'EADCDIV'];
NUTOOL_CLOCK.g_Module.EBI = ['HCLK', 'EBICKEN', 'none'];
NUTOOL_CLOCK.g_Module.EXST = ['HCLK', 'EXSTCKEN', 'none'];
NUTOOL_CLOCK.g_Module.FMCIDLE = ['HIRC', 'FMCIDLE', 'none'];
NUTOOL_CLOCK.g_Module.GPA = ['HCLK', 'GPACKEN', 'none'];
NUTOOL_CLOCK.g_Module.GPB = ['HCLK', 'GPBCKEN', 'none'];
NUTOOL_CLOCK.g_Module.GPC = ['HCLK', 'GPCCKEN', 'none'];
NUTOOL_CLOCK.g_Module.GPD = ['HCLK', 'GPDCKEN', 'none'];
NUTOOL_CLOCK.g_Module.GPE = ['HCLK', 'GPECKEN', 'none'];
NUTOOL_CLOCK.g_Module.GPF = ['HCLK', 'GPFCKEN', 'none'];
NUTOOL_CLOCK.g_Module.I2C0 = ['PCLK0', 'I2C0CKEN', 'none'];
NUTOOL_CLOCK.g_Module.I2C1 = ['PCLK1', 'I2C1CKEN', 'none'];
NUTOOL_CLOCK.g_Module.ISP = ['HCLK', 'ISPCKEN', 'none'];
NUTOOL_CLOCK.g_Module.LCD = ['LCDSEL', 'LCDCKEN', 'none'];
NUTOOL_CLOCK.g_Module.LCDCP = ['LCDCPSEL', 'LCDCPCKEN', 'none'];
NUTOOL_CLOCK.g_Module.OPA = ['PCLK0', 'OPACKEN', 'none'];
NUTOOL_CLOCK.g_Module.PDMA = ['HCLK', 'PDMACKEN', 'none'];
NUTOOL_CLOCK.g_Module.PSIO = ['PSIOSEL', 'PSIOCKEN', 'PSIODIV'];
NUTOOL_CLOCK.g_Module.PWM0 = ['PWM0SEL', 'PWM0CKEN', 'none'];
NUTOOL_CLOCK.g_Module.PWM1 = ['PWM1SEL', 'PWM1CKEN', 'none'];
NUTOOL_CLOCK.g_Module.QSPI0 = ['QSPI0SEL', 'QSPI0CKEN', 'none'];
NUTOOL_CLOCK.g_Module.RTC = ['RTCSEL', 'RTCCKEN', 'none'];
NUTOOL_CLOCK.g_Module.SC0 = ['SC0SEL', 'SC0CKEN', 'SC0DIV'];
NUTOOL_CLOCK.g_Module.SPI0 = ['SPI0SEL', 'SPI0CKEN', 'none'];
NUTOOL_CLOCK.g_Module.SPI1 = ['SPI1SEL', 'SPI1CKEN', 'none'];
NUTOOL_CLOCK.g_Module.TK = ['MIRC', 'TKCKEN', 'none'];
NUTOOL_CLOCK.g_Module.TMR0 = ['TMR0SEL', 'TMR0CKEN', 'none'];
NUTOOL_CLOCK.g_Module.TMR1 = ['TMR1SEL', 'TMR1CKEN', 'none'];
NUTOOL_CLOCK.g_Module.TMR2 = ['TMR2SEL', 'TMR2CKEN', 'none'];
NUTOOL_CLOCK.g_Module.TMR3 = ['TMR3SEL', 'TMR3CKEN', 'none'];
NUTOOL_CLOCK.g_Module.UART0 = ['UART0SEL', 'UART0CKEN', 'UART0DIV'];
NUTOOL_CLOCK.g_Module.UART1 = ['UART1SEL', 'UART1CKEN', 'UART1DIV'];
NUTOOL_CLOCK.g_Module.UART2 = ['UART2SEL', 'UART2CKEN', 'UART2DIV'];
NUTOOL_CLOCK.g_Module.UART3 = ['UART3SEL', 'UART3CKEN', 'UART3DIV'];
NUTOOL_CLOCK.g_Module.USBD = ['USBDSEL', 'USBDCKEN', 'none'];
NUTOOL_CLOCK.g_Module.USCI0 = ['PCLK0', 'USCI0CKEN', 'none'];
NUTOOL_CLOCK.g_Module.USCI1 = ['PCLK1', 'USCI1CKEN', 'none'];
NUTOOL_CLOCK.g_Module.USCI2 = ['PCLK0', 'USCI2CKEN', 'none'];
NUTOOL_CLOCK.g_Module.WDT = ['WDTSEL', 'WDTCKEN', 'none'];
NUTOOL_CLOCK.g_Module.WWDT = ['WWDTSEL', 'WDTCKEN', 'none'];
NUTOOL_CLOCK.g_Module.CLKO = ['CLKOSEL', 'CLKOCKEN/DIV1EN/CLKOEN/!CLK1HZEN', 'none'];
NUTOOL_CLOCK.g_Module.CLKO_1Hz = ['RTCSEL/32768', 'CLK1HZEN', 'none'];
NUTOOL_CLOCK.g_Module.CLKO_Divider = ['CLKOSEL', 'CLKOCKEN/!DIV1EN/CLKOEN/!CLK1HZEN', 'FREQSEL'];
NUTOOL_CLOCK.g_Module.SYSTICK = ['STCLKSEL/SYST_CTRL[2]', 'ENABLE', 'none'];

NUTOOL_CLOCK.g_unusedModule = {
	"M254MD2AE": ["CRPT", "PLL", "PWM0", "PWM1", "BPWM1", "USCI1", "USCI2", "UART3", "QSPI0", "SPI1", "I2C1", "EBI", "PSIO", "DAC", "OPA", "TK", "USBD"],
	"M254SD2AE": ["CRPT", "PLL", "PWM0", "PWM1", "BPWM1", "USCI1", "USCI2", "UART3", "QSPI0", "SPI1", "I2C1", "EBI", "PSIO", "DAC", "OPA", "TK", "USBD"],
	"M254SD3AE": ["CRPT", "PLL", "PWM0", "PWM1", "BPWM1", "USCI1", "USCI2", "UART3", "QSPI0", "SPI1", "I2C1", "EBI", "PSIO", "DAC", "OPA", "TK", "USBD"],
	"M254SE3AE": ["CRPT", "PLL", "PWM0", "PWM1", "BPWM1", "USCI1", "USCI2", "UART3", "QSPI0", "SPI1", "I2C1", "EBI", "PSIO", "DAC", "OPA", "TK", "USBD"],
	"M254QD3AE": ["CRPT", "PLL", "PWM0", "PWM1", "BPWM1", "USCI1", "USCI2", "UART3", "QSPI0", "SPI1", "I2C1", "EBI", "PSIO", "DAC", "OPA", "TK", "USBD"],
	"M254QE3AE": ["CRPT", "PLL", "PWM0", "PWM1", "BPWM1", "USCI1", "USCI2", "UART3", "QSPI0", "SPI1", "I2C1", "EBI", "PSIO", "DAC", "OPA", "TK", "USBD"],
	"M254KD3AE": ["CRPT", "PLL", "PWM0", "PWM1", "BPWM1", "USCI1", "USCI2", "UART3", "QSPI0", "SPI1", "I2C1", "EBI", "PSIO", "DAC", "OPA", "TK", "USBD"],
	"M254KE3AE": ["CRPT", "PLL", "PWM0", "PWM1", "BPWM1", "USCI1", "USCI2", "UART3", "QSPI0", "SPI1", "I2C1", "EBI", "PSIO", "DAC", "OPA", "TK", "USBD"],
	"M254SG6AE": ["PLL", "PWM0", "PWM1", "USCI2", "QSPI0", "EBI", "PSIO", "OPA", "TK", "USBD"],
	"M254KG6AE": ["PLL", "PWM0", "PWM1", "USCI2", "QSPI0", "EBI", "PSIO", "OPA", "TK", "USBD"],

	"M256MD2AE": ["CRPT", "PLL", "PWM0", "PWM1", "BPWM1", "USCI1", "USCI2", "UART3", "QSPI0", "SPI1", "I2C1", "EBI", "PSIO", "DAC", "OPA", "USBD"],
	"M256SD2AE": ["CRPT", "PLL", "PWM0", "PWM1", "BPWM1", "USCI1", "USCI2", "UART3", "QSPI0", "SPI1", "I2C1", "EBI", "PSIO", "DAC", "OPA", "USBD"],
	"M256SD3AE": ["CRPT", "PLL", "PWM0", "PWM1", "BPWM1", "USCI1", "USCI2", "UART3", "QSPI0", "SPI1", "I2C1", "EBI", "PSIO", "DAC", "OPA", "USBD"],
	"M256SE3AE": ["CRPT", "PLL", "PWM0", "PWM1", "BPWM1", "USCI1", "USCI2", "UART3", "QSPI0", "SPI1", "I2C1", "EBI", "PSIO", "DAC", "OPA", "USBD"],
	"M256QD3AE": ["CRPT", "PLL", "PWM0", "PWM1", "BPWM1", "USCI1", "USCI2", "UART3", "QSPI0", "SPI1", "I2C1", "EBI", "PSIO", "DAC", "OPA", "USBD"],
	"M256QE3AE": ["CRPT", "PLL", "PWM0", "PWM1", "BPWM1", "USCI1", "USCI2", "UART3", "QSPI0", "SPI1", "I2C1", "EBI", "PSIO", "DAC", "OPA", "USBD"],
	"M256QG6AE": ["PLL", "PWM0", "PWM1", "USCI2", "QSPI0", "EBI", "PSIO", "OPA", "USBD"],
	"M256KD3AE": ["CRPT", "PLL", "PWM0", "PWM1", "BPWM1", "USCI1", "USCI2", "UART3", "QSPI0", "SPI1", "I2C1", "EBI", "PSIO", "DAC", "OPA", "USBD"],
	"M256KE3AE": ["CRPT", "PLL", "PWM0", "PWM1", "BPWM1", "USCI1", "USCI2", "UART3", "QSPI0", "SPI1", "I2C1", "EBI", "PSIO", "DAC", "OPA", "USBD"],

	"M258SD3AE": ["CRPT", "PLL", "PWM0", "PWM1", "BPWM1", "USCI1", "USCI2", "UART3", "QSPI0", "SPI1", "I2C1", "EBI", "PSIO", "DAC", "OPA"],
	"M258SE3AE": ["CRPT", "PLL", "PWM0", "PWM1", "BPWM1", "USCI1", "USCI2", "UART3", "QSPI0", "SPI1", "I2C1", "EBI", "PSIO", "DAC", "OPA"],
	"M258SG6AE": ["PLL", "PWM0", "PWM1", "USCI2", "QSPI0", "EBI", "PSIO", "OPA"],
	"M258QD3AE": ["CRPT", "PLL", "PWM0", "PWM1", "BPWM1", "USCI1", "USCI2", "UART3", "QSPI0", "SPI1", "I2C1", "EBI", "PSIO", "DAC", "OPA"],
	"M258QE3AE": ["CRPT", "PLL", "PWM0", "PWM1", "BPWM1", "USCI1", "USCI2", "UART3", "QSPI0", "SPI1", "I2C1", "EBI", "PSIO", "DAC", "OPA"],
	"M258KD3AE": ["CRPT", "PLL", "PWM0", "PWM1", "BPWM1", "USCI1", "USCI2", "UART3", "QSPI0", "SPI1", "I2C1", "EBI", "PSIO", "DAC", "OPA"],
	"M258KE3AE": ["CRPT", "PLL", "PWM0", "PWM1", "BPWM1", "USCI1", "USCI2", "UART3", "QSPI0", "SPI1", "I2C1", "EBI", "PSIO", "DAC", "OPA"],
	"M258QG6AE": ["PLL", "PWM0", "PWM1", "USCI2", "QSPI0", "EBI", "PSIO", "OPA"],
	"M258KG6AE": ["PLL", "PWM0", "PWM1", "USCI2", "QSPI0", "EBI", "PSIO", "OPA"]
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

NUTOOL_CLOCK.g_BusNonExistent = ['EXST', 'LCDCP'];
NUTOOL_CLOCK.g_BusFromPCLK1 = ['ACMP01', 'BPWM1', 'DAC', 'EADC', 'I2C1', 'PSIO', 'PWM1', 'SPI0', 'TMR2', 'TMR3', 'UART1', 'UART3', 'USCI1', 'LCD'];
NUTOOL_CLOCK.g_DIV_Module_Defines = ['USBD:USB'];
NUTOOL_CLOCK.g_CPUCLKLimit = 48 * 1000000;
NUTOOL_CLOCK.g_HXTRange = '4~32MHz';
NUTOOL_CLOCK.g_HXTfrequency = 12 * 1000000;
NUTOOL_CLOCK.g_HIRCfrequencyArray = [];
NUTOOL_CLOCK.g_HIRCfrequency = 48 * 1000000;
NUTOOL_CLOCK.g_HIRC2frequencyArray = [];
NUTOOL_CLOCK.g_HIRC2frequency = 0;
NUTOOL_CLOCK.g_HIRC48frequency = 0;
NUTOOL_CLOCK.g_LIRCfrequency = 38.4 * 1000;
NUTOOL_CLOCK.g_MIRCfrequency = 4 * 1000000;
NUTOOL_CLOCK.g_MIRC1P2Mfrequency = 1.2 * 1000000;
NUTOOL_CLOCK.g_RTC32kfrequency = 0;
NUTOOL_CLOCK.g_PLL480Mfrequency = 0;
NUTOOL_CLOCK.g_HSUSBOTGPHYfrequency = 0;
