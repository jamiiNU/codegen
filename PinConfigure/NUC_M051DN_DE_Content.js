// chip content
NUTOOL_PIN.g_cfg_chips = [
	//M051DN
	{ name: "M052LDN", pkg: "LQFP48" },
	{ name: "M054LDN", pkg: "LQFP48" },
	{ name: "M058LDN", pkg: "LQFP48" },
	{ name: "M0516LDN", pkg: "LQFP48" },

	{ name: "M052ZDN", pkg: "QFN33" },
	{ name: "M054ZDN", pkg: "QFN33" },
	{ name: "M058ZDN", pkg: "QFN33" },
	{ name: "M0516ZDN", pkg: "QFN33" },
	//M051DE
	{ name: "M052LDE", pkg: "LQFP48" },
	{ name: "M054LDE", pkg: "LQFP48" },
	{ name: "M058LDE", pkg: "LQFP48" },
	{ name: "M0516LDE", pkg: "LQFP48" },

	{ name: "M052ZDE", pkg: "QFN33" },
	{ name: "M054ZDE", pkg: "QFN33" },
	{ name: "M058ZDE", pkg: "QFN33" },
	{ name: "M0516ZDE", pkg: "QFN33" },
	//M0515LDE
	{ name: "M0515LDE", pkg: "LQFP48" },
	//M058S
	{ name: "M058SLAN", pkg: "LQFP48" },
	{ name: "M058SZAN", pkg: "QFN33" },
	{ name: "M058SSAN", pkg: "LQFP64" },
	{ name: "M058SFAN", pkg: "TSSOP20" }
];

NUTOOL_PIN.g_cfg_pkgs = {
	"LQFP48": [
		'P1.5', 'P1.6', 'P1.7', 'nRST', 'P3.0', 'AVSS', 'P3.1', 'P3.2', 'P3.3', 'P3.4',
		'P3.5', 'P4.3',
		'P3.6', 'P3.7', 'XTAL2', 'XTAL1', 'VSS', 'LDO_CAP', 'P2.0', 'P2.1', 'P2.2', 'P2.3',
		'P2.4', 'P4.0',
		'P2.5', 'P2.6', 'P2.7', 'P4.4', 'P4.5', 'P4.6', 'P4.7', 'P0.7', 'P0.6', 'P0.5',
		'P0.4', 'P4.1',
		'P0.3', 'P0.2', 'P0.1', 'P0.0', 'VDD', 'AVDD', 'P1.0', 'P1.1', 'P1.2', 'P1.3',
		'P1.4', 'P4.2'
	],
	"QFN33": [
		'P1.5', 'nRST', 'P3.0', 'AVSS', 'P3.1', 'P3.2', 'P3.4', 'P3.5',
		'P3.6', 'XTAL2', 'XTAL1', 'VSS', 'LDO_CAP', 'P2.2', 'P2.3', 'P2.4',
		'P2.5', 'P2.6', 'P4.6', 'P4.7', 'P0.7', 'P0.6', 'P0.5', 'P0.4',
		'P0.1', 'P0.0', 'VDD', 'AVDD', 'P1.0', 'P1.2', 'P1.3', 'P1.4'
	],
	"QFN20": [
		'nRST', 'P3.0', 'AVSS', 'P3.1', 'P3.2',
		'P3.4', 'P3.5', 'VSS', 'LDO_CAP', 'P2.2',
		'P4.6', 'P4.7', 'P0.7', 'P0.6', 'P0.5',
		'P0.4', 'VDD', 'AVDD', 'P1.0', 'P1.2'
	]
};

NUTOOL_PIN.g_cfg_OrCAD = {};

NUTOOL_PIN.g_cfg_gpios = [
	{ f: ['P0.0:0', 'AD0:1', 'CTS1:2', 'TXD1:3', 'ACMP3_P:4'] },
	{ f: ['P0.1:0', 'AD1:1', 'RTS1:2', 'RXD1:3', 'ACMP3_N:4'] },
	{ f: ['P0.2:0', 'AD2:1', 'CTS0:2', 'TXD:3'] },
	{ f: ['P0.3:0', 'AD3:1', 'RTS0:2', 'RXD:3'] },
	{ f: ['P0.4:0', 'AD4:1', 'SPISS1:2'] },
	{ f: ['P0.5:0', 'AD5:1', 'MOSI_1:2'] },
	{ f: ['P0.6:0', 'AD6:1', 'MISO_1:2'] },
	{ f: ['P0.7:0', 'AD7:1', 'SPICLK1:2'] },

	{ f: ['P1.0:0', 'AIN0:1', 'T2:2', 'nWRL:3'] },
	{ f: ['P1.1:0', 'AIN1:1', 'T3:2', 'nWRH:3'] },
	{ f: ['P1.2:0', 'AIN2:1', 'RXD1:2'] },
	{ f: ['P1.3:0', 'AIN3:1', 'TXD1:2'] },
	{ f: ['P1.4:0', 'AIN4:1', 'SPISS0:2', 'ACMP0_N:3'] },
	{ f: ['P1.5:0', 'AIN5:1', 'MOSI_0:2', 'ACMP0_P:3'] },
	{ f: ['P1.6:0', 'AIN6:1', 'MISO_0:2', 'ACMP2_N:3'] },
	{ f: ['P1.7:0', 'AIN7:1', 'SPICLK0:2', 'ACMP2_P:3'] },

	{ f: ['P2.0:0', 'AD8:1', 'PWM0:2'] },
	{ f: ['P2.1:0', 'AD9:1', 'PWM1:2'] },
	{ f: ['P2.2:0', 'AD10:1', 'PWM2:2'] },
	{ f: ['P2.3:0', 'AD11:1', 'PWM3:2'] },
	{ f: ['P2.4:0', 'AD12:1', 'PWM4:2', 'SCL1:3'] },
	{ f: ['P2.5:0', 'AD13:1', 'PWM5:2', 'SDA1:3'] },
	{ f: ['P2.6:0', 'AD14:1', 'PWM6:2', 'ACMP1_O:3'] },
	{ f: ['P2.7:0', 'AD15:1', 'PWM7:2'] },

	{ f: ['P3.0:0', 'RXD:1', 'ACMP1_N:2'] },
	{ f: ['P3.1:0', 'TXD:1', 'ACMP1_P:2'] },
	{ f: ['P3.2:0', 'nINT0:1', 'T0EX:2', 'STADC:3'] },
	{ f: ['P3.3:0', 'nINT1:1', 'MCLK:2', 'T1EX:3'] },
	{ f: ['P3.4:0', 'T0:1', 'SDA0:2'] },
	{ f: ['P3.5:0', 'T1:1', 'SCL0:2', 'CKO:3'] },
	{ f: ['P3.6:0', 'nWR:1', 'CKO:2', 'ACMP0_O:3'] },
	{ f: ['P3.7:0', 'nRD:1'] },

	{ f: ['P4.0:0', 'PWM0:1', 'T2EX:2'] },
	{ f: ['P4.1:0', 'PWM1:1', 'T3EX:2'] },
	{ f: ['P4.2:0', 'PWM2:1'] },
	{ f: ['P4.3:0', 'PWM3:1'] },
	{ f: ['P4.4:0', 'nCS:1', 'SCL1:2'] },
	{ f: ['P4.5:0', 'ALE:1', 'SDA1:2'] },
	{ f: ['P4.6:0', 'ICE_CLK:1'] },
	{ f: ['P4.7:0', 'ICE_DAT:1'] }
];

NUTOOL_PIN.g_cfg_gpiosDefines = [
	{ f: ['P0.0', 'GPIO:SYS_MFP_P00_GPIO@P0_MFP', 'AD0:SYS_MFP_P00_AD0@P0_MFP', 'CTS1:SYS_MFP_P00_CTS1@P0_MFP', 'TXD1:SYS_MFP_P00_TXD1@P0_MFP', 'ACMP3_P:SYS_MFP_P00_ACMP3_P@P0_MFP'] },
	{ f: ['P0.1', 'GPIO:SYS_MFP_P01_GPIO@P0_MFP', 'AD1:SYS_MFP_P01_AD1@P0_MFP', 'RTS1:SYS_MFP_P01_RTS1@P0_MFP', 'RXD1:SYS_MFP_P01_RXD1@P0_MFP', 'ACMP3_N:SYS_MFP_P01_ACMP3_N@P0_MFP'] },
	{ f: ['P0.2', 'GPIO:SYS_MFP_P02_GPIO@P0_MFP', 'AD2:SYS_MFP_P02_AD2@P0_MFP', 'CTS0:SYS_MFP_P02_CTS0@P0_MFP', 'TXD:SYS_MFP_P02_TXD@P0_MFP'] },
	{ f: ['P0.3', 'GPIO:SYS_MFP_P03_GPIO@P0_MFP', 'AD3:SYS_MFP_P03_AD3@P0_MFP', 'RTS0:SYS_MFP_P03_RTS0@P0_MFP', 'RXD:SYS_MFP_P03_RXD@P0_MFP'] },
	{ f: ['P0.4', 'GPIO:SYS_MFP_P04_GPIO@P0_MFP', 'AD4:SYS_MFP_P04_AD4@P0_MFP', 'SPISS1:SYS_MFP_P04_SPISS1@P0_MFP'] },
	{ f: ['P0.5', 'GPIO:SYS_MFP_P05_GPIO@P0_MFP', 'AD5:SYS_MFP_P05_AD5@P0_MFP', 'MOSI_1:SYS_MFP_P05_MOSI_1@P0_MFP'] },
	{ f: ['P0.6', 'GPIO:SYS_MFP_P06_GPIO@P0_MFP', 'AD6:SYS_MFP_P06_AD6@P0_MFP', 'MISO_1:SYS_MFP_P06_MISO_1@P0_MFP'] },
	{ f: ['P0.7', 'GPIO:SYS_MFP_P07_GPIO@P0_MFP', 'AD7:SYS_MFP_P07_AD7@P0_MFP', 'SPICLK1:SYS_MFP_P07_SPICLK1@P0_MFP'] },

	{ f: ['P1.0', 'GPIO:SYS_MFP_P10_GPIO@P1_MFP', 'AIN0:SYS_MFP_P10_AIN0@P1_MFP', 'T2:SYS_MFP_P10_T2@P1_MFP', 'nWRL:SYS_MFP_P10_nWRL@P1_MFP'] },
	{ f: ['P1.1', 'GPIO:SYS_MFP_P11_GPIO@P1_MFP', 'AIN1:SYS_MFP_P11_AIN1@P1_MFP', 'T3:SYS_MFP_P11_T3@P1_MFP', 'nWRH:SYS_MFP_P11_nWRH@P1_MFP'] },
	{ f: ['P1.2', 'GPIO:SYS_MFP_P12_GPIO@P1_MFP', 'AIN2:SYS_MFP_P12_AIN2@P1_MFP', 'RXD1:SYS_MFP_P12_RXD1@P1_MFP'] },
	{ f: ['P1.3', 'GPIO:SYS_MFP_P13_GPIO@P1_MFP', 'AIN3:SYS_MFP_P13_AIN3@P1_MFP', 'TXD1:SYS_MFP_P13_TXD1@P1_MFP'] },
	{ f: ['P1.4', 'GPIO:SYS_MFP_P14_GPIO@P1_MFP', 'AIN4:SYS_MFP_P14_AIN4@P1_MFP', 'SPISS0:SYS_MFP_P14_SPISS0@P1_MFP', 'ACMP0_N:SYS_MFP_P14_ACMP0_N@P1_MFP'] },
	{ f: ['P1.5', 'GPIO:SYS_MFP_P15_GPIO@P1_MFP', 'AIN5:SYS_MFP_P15_AIN5@P1_MFP', 'MOSI_0:SYS_MFP_P15_MOSI_0@P1_MFP', 'ACMP0_P:SYS_MFP_P15_ACMP0_P@P1_MFP'] },
	{ f: ['P1.6', 'GPIO:SYS_MFP_P16_GPIO@P1_MFP', 'AIN6:SYS_MFP_P16_AIN6@P1_MFP', 'MISO_0:SYS_MFP_P16_MISO_0@P1_MFP', 'ACMP2_N:SYS_MFP_P16_ACMP2_N@P1_MFP'] },
	{ f: ['P1.7', 'GPIO:SYS_MFP_P17_GPIO@P1_MFP', 'AIN7:SYS_MFP_P17_AIN7@P1_MFP', 'SPICLK0:SYS_MFP_P17_SPICLK0@P1_MFP', 'ACMP2_P:SYS_MFP_P17_ACMP2_P@P1_MFP'] },

	{ f: ['P2.0', 'GPIO:SYS_MFP_P20_GPIO@P2_MFP', 'AD8:SYS_MFP_P20_AD8@P2_MFP', 'PWM0:SYS_MFP_P20_PWM0@P2_MFP'] },
	{ f: ['P2.1', 'GPIO:SYS_MFP_P21_GPIO@P2_MFP', 'AD9:SYS_MFP_P21_AD9@P2_MFP', 'PWM1:SYS_MFP_P21_PWM1@P2_MFP'] },
	{ f: ['P2.2', 'GPIO:SYS_MFP_P22_GPIO@P2_MFP', 'AD10:SYS_MFP_P22_AD10@P2_MFP', 'PWM2:SYS_MFP_P22_PWM2@P2_MFP'] },
	{ f: ['P2.3', 'GPIO:SYS_MFP_P23_GPIO@P2_MFP', 'AD11:SYS_MFP_P23_AD11@P2_MFP', 'PWM3:SYS_MFP_P23_PWM3@P2_MFP'] },
	{ f: ['P2.4', 'GPIO:SYS_MFP_P24_GPIO@P2_MFP', 'AD12:SYS_MFP_P24_AD12@P2_MFP', 'PWM4:SYS_MFP_P24_PWM4@P2_MFP', 'SCL1:SYS_MFP_P24_SCL1@P2_MFP'] },
	{ f: ['P2.5', 'GPIO:SYS_MFP_P25_GPIO@P2_MFP', 'AD13:SYS_MFP_P25_AD13@P2_MFP', 'PWM5:SYS_MFP_P25_PWM5@P2_MFP', 'SDA1:SYS_MFP_P25_SDA1@P2_MFP'] },
	{ f: ['P2.6', 'GPIO:SYS_MFP_P26_GPIO@P2_MFP', 'AD14:SYS_MFP_P26_AD14@P2_MFP', 'PWM6:SYS_MFP_P26_PWM6@P2_MFP', 'ACMP1_O:SYS_MFP_P26_ACMP1_O@P2_MFP'] },
	{ f: ['P2.7', 'GPIO:SYS_MFP_P27_GPIO@P2_MFP', 'AD15:SYS_MFP_P27_AD15@P2_MFP', 'PWM7:SYS_MFP_P27_PWM7@P2_MFP'] },

	{ f: ['P3.0', 'GPIO:SYS_MFP_P30_GPIO@P3_MFP', 'RXD:SYS_MFP_P30_RXD@P3_MFP', 'ACMP1_N:SYS_MFP_P30_ACMP1_N@P3_MFP'] },
	{ f: ['P3.1', 'GPIO:SYS_MFP_P31_GPIO@P3_MFP', 'TXD:SYS_MFP_P31_TXD@P3_MFP', 'ACMP1_P:SYS_MFP_P31_ACMP1_P@P3_MFP'] },
	{ f: ['P3.2', 'GPIO:SYS_MFP_P32_GPIO@P3_MFP', 'nINT0:SYS_MFP_P32_nINT0@P3_MFP', 'T0EX:SYS_MFP_P32_T0EX@P3_MFP', 'STADC:SYS_MFP_P32_STADC@P3_MFP'] },
	{ f: ['P3.3', 'GPIO:SYS_MFP_P33_GPIO@P3_MFP', 'nINT1:SYS_MFP_P33_nINT1@P3_MFP', 'MCLK:SYS_MFP_P33_MCLK@P3_MFP', 'T1EX:SYS_MFP_P33_T1EX@P3_MFP'] },
	{ f: ['P3.4', 'GPIO:SYS_MFP_P34_GPIO@P3_MFP', 'T0:SYS_MFP_P34_T0@P3_MFP', 'SDA0:SYS_MFP_P34_SDA0@P3_MFP'] },
	{ f: ['P3.5', 'GPIO:SYS_MFP_P35_GPIO@P3_MFP', 'T1:SYS_MFP_P35_T1@P3_MFP', 'SCL0:SYS_MFP_P35_SCL0@P3_MFP', 'CKO:SYS_MFP_P35_CKO@P3_MFP'] },
	{ f: ['P3.6', 'GPIO:SYS_MFP_P36_GPIO@P3_MFP', 'nWR:SYS_MFP_P36_nWR@P3_MFP', 'CKO:SYS_MFP_P36_CKO@P3_MFP', 'ACMP0_O:SYS_MFP_P36_ACMP0_O@P3_MFP'] },
	{ f: ['P3.7', 'GPIO:SYS_MFP_P37_GPIO@P3_MFP', 'nRD:SYS_MFP_P37_nRD@P3_MFP'] },

	{ f: ['P4.0', 'GPIO:SYS_MFP_P40_GPIO@P4_MFP', 'PWM0:SYS_MFP_P40_PWM0@P4_MFP', 'T2EX:SYS_MFP_P40_T2EX@P4_MFP'] },
	{ f: ['P4.1', 'GPIO:SYS_MFP_P41_GPIO@P4_MFP', 'PWM1:SYS_MFP_P41_PWM1@P4_MFP', 'T3EX:SYS_MFP_P41_T3EX@P4_MFP'] },
	{ f: ['P4.2', 'GPIO:SYS_MFP_P42_GPIO@P4_MFP', 'PWM2:SYS_MFP_P42_PWM2@P4_MFP'] },
	{ f: ['P4.3', 'GPIO:SYS_MFP_P43_GPIO@P4_MFP', 'PWM3:SYS_MFP_P43_PWM3@P4_MFP'] },
	{ f: ['P4.4', 'GPIO:SYS_MFP_P44_GPIO@P4_MFP', 'nCS:SYS_MFP_P44_nCS@P4_MFP', 'SCL1:SYS_MFP_P44_SCL1@P4_MFP'] },
	{ f: ['P4.5', 'GPIO:SYS_MFP_P45_GPIO@P4_MFP', 'ALE:SYS_MFP_P45_ALE@P4_MFP', 'SDA1:SYS_MFP_P45_SDA1@P4_MFP'] },
	{ f: ['P4.6', 'GPIO:SYS_MFP_P46_GPIO@P4_MFP', 'ICE_CLK:SYS_MFP_P46_ICE_CLK@P4_MFP'] },
	{ f: ['P4.7', 'GPIO:SYS_MFP_P47_GPIO@P4_MFP', 'ICE_DAT:SYS_MFP_P47_ICE_DAT@P4_MFP'] }
];

NUTOOL_PIN.g_cfg_gpiosDescriptions = [
	'ACMP0_N:Comparator0 negative input pin',
	'ACMP0_O:Analog comparator0 output pin',
	'ACMP0_P:Comparator0 positive input pin',
	'ACMP1_N:Comparator1 negative input pin',
	'ACMP1_O:Analog comparator1 output pin',
	'ACMP1_P:Comparator1 positive input pin',
	'ACMP2_N:Comparator2 negative input pin',
	'ACMP2_P:Comparator2 positive input pin',
	'ACMP3_N:Comparator3 negative input pin',
	'ACMP3_P:Comparator3 positive input pin',

	'AD0:EBI Address/Data bus bit0',
	'AD1:EBI Address/Data bus bit1',
	'AD2:EBI Address/Data bus bit2',
	'AD3:EBI Address/Data bus bit3',
	'AD4:EBI Address/Data bus bit4',
	'AD5:EBI Address/Data bus bit5',
	'AD6:EBI Address/Data bus bit6',
	'AD7:EBI Address/Data bus bit7',
	'AD8:EBI Address/Data bus bit8',
	'AD9:EBI Address/Data bus bit9',
	'AD10:EBI Address/Data bus bit10',
	'AD11:EBI Address/Data bus bit11',
	'AD12:EBI Address/Data bus bit12',
	'AD13:EBI Address/Data bus bit13',
	'AD14:EBI Address/Data bus bit14',
	'AD15:EBI Address/Data bus bit15',

	'AIN0:ADC0 analog input',
	'AIN1:ADC1 analog input',
	'AIN2:ADC2 analog input',
	'AIN3:ADC3 analog input',
	'AIN4:ADC4 analog input',
	'AIN5:ADC5 analog input',
	'AIN6:ADC6 analog input',
	'AIN7:ADC7 analog input',

	'ALE:EBI address latch enable output pin',
	'AVDD:Power supply for internal analog circuit',
	'AVSS:Ground pin for analog circuit',

	'CKO:Frequency divider output pin',

	'CTS0:Clear to Send input pin for UART0',
	'CTS1:Clear to Send input pin for UART1',

	'ICE_CLK:Serial Wired Debugger Clock pin',
	'ICE_DAT:Serial Wired Debugger Data pin',

	'LDO_CAP:LDO output pin',
	'MCLK:EBI external clock output pin',
	'MISO_0:SPI0 MISO (Master In, Slave Out) pin',
	'MISO_1:SPI1 MISO (Master In, Slave Out) pin',
	'MOSI_0:SPI0 MISO (Master Out, Slave In) pin',
	'MOSI_1:SPI1 MISO (Master Out, Slave In) pin',

	'nCS:EBI chip select enable output pin',
	'nINT0:External interrupt0 input pin',
	'nINT1:External interrupt1 input pin',
	'nRD:EBI read enable output pin',
	'nRST:External reset input: active LOW, with an internal pull-up. Set this pin low reset chip to initial state',
	'nWR:EBI write enable output pin',
	'nWRH:EBI high byte write enable output pin',
	'nWRL:EBI low byte write enable output pin',

	'PWM0:PWM0 output/Capture input',
	'PWM1:PWM1 output/Capture input',
	'PWM2:PWM2 output/Capture input',
	'PWM3:PWM3 output/Capture input',
	'PWM4:PWM4 output/Capture input',
	'PWM5:PWM5 output/Capture input',
	'PWM6:PWM6 output/Capture input',
	'PWM7:PWM7 output/Capture input',

	'RTS0:Request to Send output pin for UART0',
	'RTS1:Request to Send output pin for UART1',

	'RXD:Data receiver input pin for UART0',
	'RXD1:Data receiver input pin for UART1',

	'SCL0:I2C0 clock I/O pin',
	'SCL1:I2C1 clock I/O pin',

	'SDA0:I2C0 data input/output pin',
	'SDA1:I2C1 data input/output pin',

	'SPICLK0:SPI0 serial clock pin',
	'SPICLK1:SPI1 serial clock pin',
	'SPISS0:SPI0 slave select pin',
	'SPISS1:SPI1 slave select pin',

	'STADC:ADC external trigger input',

	'T0:Timer0 external event counter input pin',
	'T0EX:Timer0 external capture/reset trigger input pin',
	'T1:Timer1 external event counter input pin',
	'T1EX:Timer1 external capture/reset trigger input pin',
	'T2:Timer2 external event counter input pin',
	'T2EX:Timer2 external capture/reset trigger input pin',
	'T3:Timer3 external event counter input pin',
	'T3EX:Timer3 external capture/reset trigger input pin',
	'TIEX:Timer1 external capture/reset trigger input pin',
	'TXD:Data transmitter output pin for UART0',
	'TXD1:Data transmitter output pin for UART1',

	'VDD:Power supply for I/O ports and LDO source for internal PLL and digital circuit',
	'VSS:Ground pin for digital circuit',

	'XTAL1:External 4~24 MHz (high speed) crystal input pin',
	'XTAL2:External 4~24 MHz (high speed) crystal output pin'
];

NUTOOL_PIN.g_cfg_regDescriptions = {};
NUTOOL_PIN.g_cfg_regDescriptions.P0_MFP = '0x50000030';
NUTOOL_PIN.g_cfg_regDescriptions.P1_MFP = '0x50000034';
NUTOOL_PIN.g_cfg_regDescriptions.P2_MFP = '0x50000038';
NUTOOL_PIN.g_cfg_regDescriptions.P3_MFP = '0x5000003C';
NUTOOL_PIN.g_cfg_regDescriptions.P4_MFP = '0x50000040';

NUTOOL_PIN.g_cfg_gpioMatrix = [
	{ f: ['P0.0', 'P0_MFP[0]:0', 'P0_MFP[8]:1', 'P0_MFP[24]:2'] },
	{ f: ['P0.1', 'P0_MFP[1]:0', 'P0_MFP[9]:1', 'P0_MFP[25]:2'] },
	{ f: ['P0.2', 'P0_MFP[2]:0', 'P0_MFP[10]:1'] },
	{ f: ['P0.3', 'P0_MFP[3]:0', 'P0_MFP[11]:1'] },
	{ f: ['P0.4', 'P0_MFP[4]:0', 'P0_MFP[12]:1'] },
	{ f: ['P0.5', 'P0_MFP[5]:0', 'P0_MFP[13]:1'] },
	{ f: ['P0.6', 'P0_MFP[6]:0', 'P0_MFP[14]:1'] },
	{ f: ['P0.7', 'P0_MFP[7]:0', 'P0_MFP[15]:1'] },

	{ f: ['P1.0', 'P1_MFP[0]:0', 'P1_MFP[8]:1'] },
	{ f: ['P1.1', 'P1_MFP[1]:0', 'P1_MFP[9]:1'] },
	{ f: ['P1.2', 'P1_MFP[2]:0', 'P1_MFP[10]:1'] },
	{ f: ['P1.3', 'P1_MFP[3]:0', 'P1_MFP[11]:1'] },
	{ f: ['P1.4', 'P1_MFP[4]:0', 'P1_MFP[12]:1'] },
	{ f: ['P1.5', 'P1_MFP[5]:0', 'P1_MFP[13]:1'] },
	{ f: ['P1.6', 'P1_MFP[6]:0', 'P1_MFP[14]:1'] },
	{ f: ['P1.7', 'P1_MFP[7]:0', 'P1_MFP[15]:1'] },

	{ f: ['P2.0', 'P2_MFP[0]:0', 'P2_MFP[8]:1'] },
	{ f: ['P2.1', 'P2_MFP[1]:0', 'P2_MFP[9]:1'] },
	{ f: ['P2.2', 'P2_MFP[2]:0', 'P2_MFP[10]:1'] },
	{ f: ['P2.3', 'P2_MFP[3]:0', 'P2_MFP[11]:1'] },
	{ f: ['P2.4', 'P2_MFP[4]:0', 'P2_MFP[12]:1'] },
	{ f: ['P2.5', 'P2_MFP[5]:0', 'P2_MFP[13]:1'] },
	{ f: ['P2.6', 'P2_MFP[6]:0', 'P2_MFP[14]:1'] },
	{ f: ['P2.7', 'P2_MFP[7]:0', 'P2_MFP[15]:1'] },

	{ f: ['P3.0', 'P3_MFP[0]:0', 'P3_MFP[8]:1'] },
	{ f: ['P3.1', 'P3_MFP[1]:0', 'P3_MFP[9]:1'] },
	{ f: ['P3.2', 'P3_MFP[2]:0', 'P3_MFP[10]:1'] },
	{ f: ['P3.3', 'P3_MFP[3]:0', 'P3_MFP[11]:1'] },
	{ f: ['P3.4', 'P3_MFP[4]:0', 'P3_MFP[12]:1'] },
	{ f: ['P3.5', 'P3_MFP[5]:0', 'P3_MFP[13]:1'] },
	{ f: ['P3.6', 'P3_MFP[6]:0', 'P3_MFP[14]:1'] },
	{ f: ['P3.7', 'P3_MFP[7]:0', 'P3_MFP[15]:1'] },

	{ f: ['P4.0', 'P4_MFP[0]:0', 'P4_MFP[8]:1'] },
	{ f: ['P4.1', 'P4_MFP[1]:0', 'P4_MFP[9]:1'] },
	{ f: ['P4.2', 'P4_MFP[2]:0', 'P4_MFP[10]:1'] },
	{ f: ['P4.3', 'P4_MFP[3]:0', 'P4_MFP[11]:1'] },
	{ f: ['P4.4', 'P4_MFP[4]:0', 'P4_MFP[12]:1'] },
	{ f: ['P4.5', 'P4_MFP[5]:0', 'P4_MFP[13]:1'] },
	{ f: ['P4.6', 'P4_MFP[6]:0', 'P4_MFP[14]:1'] },
	{ f: ['P4.7', 'P4_MFP[7]:0', 'P4_MFP[15]:1'] }
];

NUTOOL_PIN.g_cfg_shareBits = [];
NUTOOL_PIN.g_cfg_addGPIO = {};
NUTOOL_PIN.g_cfg_unusedGPIO = {
	"M052ZDE(QFN33)": {
		"P1.5": ["MOSI_0"],
		"P3.6": ["nWR"],
		"P2.2": ["AD10"],
		"P2.3": ["AD11"],
		"P2.4": ["AD12"],
		"P2.5": ["AD13"],
		"P2.6": ["AD14"],
		"P0.7": ["AD7"],
		"P0.6": ["AD6"],
		"P0.5": ["AD5"],
		"P0.4": ["AD4"],
		"P0.1": ["AD1"],
		"P0.0": ["AD0"],
		"P1.0": ["nWRL"],
		"P1.4": ["SPISS0"]
	},
	"M054ZDE(QFN33)": function () {
		return this["M052ZDE(QFN33)"];
	},
	"M058ZDE(QFN33)": function () {
		return this["M052ZDE(QFN33)"];
	},
	"M0516ZDE(QFN33)": function () {
		return this["M052ZDE(QFN33)"];
	},
	"M052TDE(QFN33)": function () {
		return this["M052ZDE(QFN33)"];
	},
	"M054TDE(QFN33)": function () {
		return this["M052ZDE(QFN33)"];
	},
	"M058TDE(QFN33)": function () {
		return this["M052ZDE(QFN33)"];
	},
	"M0516TDE(QFN33)": function () {
		return this["M052ZDE(QFN33)"];
	},
	"M052ZDN(QFN33)": function () {
		return this["M052ZDE(QFN33)"];
	},
	"M054ZDN(QFN33)": function () {
		return this["M052ZDE(QFN33)"];
	},
	"M058ZDN(QFN33)": function () {
		return this["M052ZDE(QFN33)"];
	},
	"M0516ZDN(QFN33)": function () {
		return this["M052ZDE(QFN33)"];
	},
	"M052TDN(QFN33)": function () {
		return this["M052ZDE(QFN33)"];
	},
	"M054TDN(QFN33)": function () {
		return this["M052ZDE(QFN33)"];
	},
	"M058TDN(QFN33)": function () {
		return this["M052ZDE(QFN33)"];
	},
	"M0516TDN(QFN33)": function () {
		return this["M052ZDE(QFN33)"];
	},
	"MHC54ZDN(QFN33)": function () {
		return this["M052ZDE(QFN33)"];
	},
	"M052XDN(QFN20)": {
		"P2.2": ["AD10"],
		"P0.7": ["AD7"],
		"P0.6": ["AD6"],
		"P0.5": ["AD5"],
		"P0.4": ["AD4"],
		"P1.0": ["nWRL"],
		"P1.2": ["RXD1"]
	},
	"M054XDN(QFN20)": function () {
		return this["M052XDN(QFN20)"];
	},
	"PL054TDN(QFN20)": function () {
		return this["M052XDN(QFN20)"];
	},
	"M058XDN(QFN20)": function () {
		return this["M052XDN(QFN20)"];
	},
	"M0516XDN(QFN20)": function () {
		return this["M052XDN(QFN20)"];
	},
	"E32(QFN20)": function () {
		return this["M052XDN(QFN20)"];
	}
};
NUTOOL_PIN.g_cfg_WPPin = [];

NUTOOL_PIN.decidepackageNumber = function (given_partNumber_package) {
	var partNumber_package;

	if (typeof given_partNumber_package === 'undefined') {
		partNumber_package = NUTOOL_PIN.getg_partNumber_package();
	}
	else {
		partNumber_package = given_partNumber_package;
	}

	NUTOOL_PIN.g_packageNumber = partNumber_package.substring(partNumber_package.indexOf('(') + 1);
	NUTOOL_PIN.g_packageNumber = NUTOOL_PIN.g_packageNumber.substring(0, NUTOOL_PIN.g_packageNumber.indexOf(')'));
	NUTOOL_PIN.g_packageNumberIndex = NUTOOL_PIN.g_packageNumber;

	partNumber_package = null;
};
