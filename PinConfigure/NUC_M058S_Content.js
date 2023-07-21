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
	"LQFP64": [
		'P1.5', 'P1.6', 'P1.7', 'nRST', 'P3.0', 'AVSS', 'P5.1', 'P5.2', 'P5.3', 'P3.1',
		'P3.2', 'P3.3', 'P3.4', 'P3.5', 'P4.3', 'P3.6',
		'P3.7', 'XTAL2/P7.0', 'XTAL1/P7.1', 'VSS', 'VDD', 'LDO_CAP', 'P5.4', 'P5.5', 'P5.6', 'P5.7',
		'P2.0', 'P2.1', 'P2.2', 'P2.3', 'P2.4', 'P4.0',
		'P2.5', 'P2.6', 'P2.7', 'P4.4', 'P4.5', 'P4.6', 'P4.7', 'P6.0', 'P6.1', 'P6.2',
		'P6.3', 'P0.7', 'P0.6', 'P0.5', 'P0.4', 'P4.1',
		'P0.3', 'P0.2', 'P0.1', 'P0.0', 'VSS', 'VDD', 'AVDD', 'Vref', 'P6.6', 'P6.7',
		'P1.0', 'P1.1', 'P1.2', 'P1.3', 'P1.4', 'P4.2'
	],
	"LQFP48": [
		'P1.5', 'P1.6', 'P1.7', 'nRST', 'P3.0', 'AVSS', 'P3.1', 'P3.2', 'P3.3', 'P3.4',
		'P3.5', 'P4.3',
		'P3.6', 'P3.7', 'XTAL2/P7.0', 'XTAL1/P7.1', 'VSS', 'LDO_CAP', 'P2.0', 'P2.1', 'P2.2', 'P2.3',
		'P2.4', 'P4.0',
		'P2.5', 'P2.6', 'P2.7', 'P4.4', 'P4.5', 'P4.6', 'P4.7', 'P0.7', 'P0.6', 'P0.5',
		'P0.4', 'P4.1',
		'P0.3', 'P0.2', 'P0.1', 'P0.0', 'VDD', 'AVDD', 'P1.0', 'P1.1', 'P1.2', 'P1.3',
		'P1.4', 'P4.2'
	],
	"QFN33": [
		'P1.5', 'nRST', 'P3.0', 'AVSS', 'P3.1', 'P3.2', 'P3.4', 'P3.5',
		'P3.6', 'XTAL2/P7.0', 'XTAL1/P7.1', 'VSS', 'LDO_CAP', 'P2.2', 'P2.3', 'P2.4',
		'P2.5', 'P2.6', 'P4.6', 'P4.7', 'P0.7', 'P0.6', 'P0.5', 'P0.4',
		'P0.1', 'P0.0', 'VDD', 'AVDD', 'P1.0', 'P1.2', 'P1.3', 'P1.4'
	],
	"TSSOP20": [
		'P1.0', 'P1.4', 'nRST', 'P3.0', 'AVSS',
		'P3.1', 'P3.4', 'P3.5', 'XTAL2/P7.0', 'XTAL1/P7.1',
		'VSS', 'LDO_CAP', 'P2.3', 'P4.6', 'P4.7',
		'P0.7', 'P0.6', 'P0.5', 'VDD', 'AVDD'
	]
};

NUTOOL_PIN.g_cfg_OrCAD = {};

NUTOOL_PIN.g_cfg_gpios = [
	{ f: ['P0.0:0'] },
	{ f: ['P0.1:0'] },
	{ f: ['P0.2:0', 'CTS0:2', 'TXD:3'] },
	{ f: ['P0.3:0', 'RTS0:2', 'RXD:3'] },
	{ f: ['P0.4:0', 'SPISS:2'] },
	{ f: ['P0.5:0', 'MOSI:2'] },
	{ f: ['P0.6:0', 'MISO:2'] },
	{ f: ['P0.7:0', 'SPICLK:2'] },

	{ f: ['P1.0:0', 'AIN0:1', 'T2:2'] },
	{ f: ['P1.1:0', 'AIN1:1', 'T3:2'] },
	{ f: ['P1.2:0', 'AIN2:1'] },
	{ f: ['P1.3:0', 'AIN3:1'] },
	{ f: ['P1.4:0', 'AIN4:1', 'SPISS:2'] },
	{ f: ['P1.5:0', 'AIN5:1', 'MOSI:2'] },
	{ f: ['P1.6:0', 'AIN6:1', 'MISO:2'] },
	{ f: ['P1.7:0', 'AIN7:1', 'SPICLK:2'] },

	{ f: ['P2.0:0', 'PWM0:2'] },
	{ f: ['P2.1:0', 'PWM1:2'] },
	{ f: ['P2.2:0', 'PWM2:2'] },
	{ f: ['P2.3:0', 'PWM3:2'] },
	{ f: ['P2.4:0'] },
	{ f: ['P2.5:0'] },
	{ f: ['P2.6:0'] },
	{ f: ['P2.7:0'] },

	{ f: ['P3.0:0', 'RXD:1'] },
	{ f: ['P3.1:0', 'TXD:1'] },
	{ f: ['P3.2:0', 'nINT0:1', 'T0EX:2', 'STADC:3'] },
	{ f: ['P3.3:0', 'nINT1:1', 'T1EX:3'] },
	{ f: ['P3.4:0', 'T0:1', 'SDA0:2'] },
	{ f: ['P3.5:0', 'T1:1', 'SCL0:2', 'CKO:3'] },
	{ f: ['P3.6:0', 'CKO:2'] },
	{ f: ['P3.7:0'] },

	{ f: ['P4.0:0', 'PWM0:1', 'T2EX:2'] },
	{ f: ['P4.1:0', 'PWM1:1', 'T3EX:2'] },
	{ f: ['P4.2:0', 'PWM2:1'] },
	{ f: ['P4.3:0', 'PWM3:1'] },
	{ f: ['P4.4:0', 'SCL1:2'] },
	{ f: ['P4.5:0', 'SDA1:2'] },
	{ f: ['P4.6:0', 'ICE_CLK:1'] },
	{ f: ['P4.7:0', 'ICE_DAT:1'] },

	{ f: ['P5.0:0'] },
	{ f: ['P5.1:0', 'T1EX:1'] },
	{ f: ['P5.2:0', 'SDA0:1'] },
	{ f: ['P5.3:0', 'SCL0:1'] },
	{ f: ['P5.4:0'] },
	{ f: ['P5.5:0'] },
	{ f: ['P5.6:0'] },
	{ f: ['P5.7:0'] },

	{ f: ['P6.0:0'] },
	{ f: ['P6.1:0'] },
	{ f: ['P6.2:0'] },
	{ f: ['P6.3:0'] },
	{ f: ['P6.4:0'] },
	{ f: ['P6.5:0'] },
	{ f: ['P6.6:0'] },
	{ f: ['P6.7:0'] },

	{ f: ['P7.0:0'] },
	{ f: ['P7.1:0'] },
	{ f: ['P7.2:0'] },
	{ f: ['P7.3:0'] },
	{ f: ['P7.4:0'] },
	{ f: ['P7.5:0'] },
	{ f: ['P7.6:0'] },
	{ f: ['P7.7:0'] }
];

NUTOOL_PIN.g_cfg_gpiosDefines = [
	{ f: ['P0.0', 'GPIO:SYS_MFP_P00_GPIO@P0_MFP'] },
	{ f: ['P0.1', 'GPIO:SYS_MFP_P01_GPIO@P0_MFP'] },
	{ f: ['P0.2', 'GPIO:SYS_MFP_P02_GPIO@P0_MFP', 'CTS0:SYS_MFP_P02_CTS@P0_MFP', 'TXD:SYS_MFP_P02_TXD@P0_MFP'] },
	{ f: ['P0.3', 'GPIO:SYS_MFP_P03_GPIO@P0_MFP', 'RTS0:SYS_MFP_P03_RTS@P0_MFP', 'RXD:SYS_MFP_P03_RXD@P0_MFP'] },
	{ f: ['P0.4', 'GPIO:SYS_MFP_P04_GPIO@P0_MFP', 'SPISS:SYS_MFP_P04_SPISS@P0_MFP'] },
	{ f: ['P0.5', 'GPIO:SYS_MFP_P05_GPIO@P0_MFP', 'MOSI:SYS_MFP_P05_MOSI@P0_MFP'] },
	{ f: ['P0.6', 'GPIO:SYS_MFP_P06_GPIO@P0_MFP', 'MISO:SYS_MFP_P06_MISO@P0_MFP'] },
	{ f: ['P0.7', 'GPIO:SYS_MFP_P07_GPIO@P0_MFP', 'SPICLK:SYS_MFP_P07_SPICLK@P0_MFP'] },

	{ f: ['P1.0', 'GPIO:SYS_MFP_P10_GPIO@P1_MFP', 'AIN0:SYS_MFP_P10_AIN0@P1_MFP', 'T2:SYS_MFP_P10_T2@P1_MFP'] },
	{ f: ['P1.1', 'GPIO:SYS_MFP_P11_GPIO@P1_MFP', 'AIN1:SYS_MFP_P11_AIN1@P1_MFP', 'T3:SYS_MFP_P11_T3@P1_MFP'] },
	{ f: ['P1.2', 'GPIO:SYS_MFP_P12_GPIO@P1_MFP', 'AIN2:SYS_MFP_P12_AIN2@P1_MFP'] },
	{ f: ['P1.3', 'GPIO:SYS_MFP_P13_GPIO@P1_MFP', 'AIN3:SYS_MFP_P13_AIN3@P1_MFP'] },
	{ f: ['P1.4', 'GPIO:SYS_MFP_P14_GPIO@P1_MFP', 'AIN4:SYS_MFP_P14_AIN4@P1_MFP', 'SPISS:SYS_MFP_P14_SPISS@P1_MFP'] },
	{ f: ['P1.5', 'GPIO:SYS_MFP_P15_GPIO@P1_MFP', 'AIN5:SYS_MFP_P15_AIN5@P1_MFP', 'MOSI:SYS_MFP_P15_MOSI@P1_MFP'] },
	{ f: ['P1.6', 'GPIO:SYS_MFP_P16_GPIO@P1_MFP', 'AIN6:SYS_MFP_P16_AIN6@P1_MFP', 'MISO:SYS_MFP_P16_MISO@P1_MFP'] },
	{ f: ['P1.7', 'GPIO:SYS_MFP_P17_GPIO@P1_MFP', 'AIN7:SYS_MFP_P17_AIN7@P1_MFP', 'SPICLK:SYS_MFP_P17_SPICLK@P1_MFP'] },

	{ f: ['P2.0', 'GPIO:SYS_MFP_P20_GPIO@P2_MFP', 'PWM0:SYS_MFP_P20_PWM0@P2_MFP'] },
	{ f: ['P2.1', 'GPIO:SYS_MFP_P21_GPIO@P2_MFP', 'PWM1:SYS_MFP_P21_PWM1@P2_MFP'] },
	{ f: ['P2.2', 'GPIO:SYS_MFP_P22_GPIO@P2_MFP', 'PWM2:SYS_MFP_P22_PWM2@P2_MFP'] },
	{ f: ['P2.3', 'GPIO:SYS_MFP_P23_GPIO@P2_MFP', 'PWM3:SYS_MFP_P23_PWM3@P2_MFP'] },
	{ f: ['P2.4', 'GPIO:SYS_MFP_P24_GPIO@P2_MFP'] },
	{ f: ['P2.5', 'GPIO:SYS_MFP_P25_GPIO@P2_MFP'] },
	{ f: ['P2.6', 'GPIO:SYS_MFP_P26_GPIO@P2_MFP'] },
	{ f: ['P2.7', 'GPIO:SYS_MFP_P27_GPIO@P2_MFP'] },

	{ f: ['P3.0', 'GPIO:SYS_MFP_P30_GPIO@P3_MFP', 'RXD:SYS_MFP_P30_RXD@P3_MFP'] },
	{ f: ['P3.1', 'GPIO:SYS_MFP_P31_GPIO@P3_MFP', 'TXD:SYS_MFP_P31_TXD@P3_MFP'] },
	{ f: ['P3.2', 'GPIO:SYS_MFP_P32_GPIO@P3_MFP', 'nINT0:SYS_MFP_P32_nINT0@P3_MFP', 'T0EX:SYS_MFP_P32_T0EX@P3_MFP', 'STADC:SYS_MFP_P32_STADC@P3_MFP'] },
	{ f: ['P3.3', 'GPIO:SYS_MFP_P33_GPIO@P3_MFP', 'nINT1:SYS_MFP_P33_nINT1@P3_MFP', 'T1EX:SYS_MFP_P33_T1EX@P3_MFP'] },
	{ f: ['P3.4', 'GPIO:SYS_MFP_P34_GPIO@P3_MFP', 'T0:SYS_MFP_P34_T0@P3_MFP', 'SDA0:SYS_MFP_P34_SDA0@P3_MFP'] },
	{ f: ['P3.5', 'GPIO:SYS_MFP_P35_GPIO@P3_MFP', 'T1:SYS_MFP_P35_T1@P3_MFP', 'SCL0:SYS_MFP_P35_SCL0@P3_MFP', 'CKO:SYS_MFP_P35_CKO@P3_MFP'] },
	{ f: ['P3.6', 'GPIO:SYS_MFP_P36_GPIO@P3_MFP', 'CKO:SYS_MFP_P36_CKO@P3_MFP'] },
	{ f: ['P3.7', 'GPIO:SYS_MFP_P37_GPIO@P3_MFP'] },

	{ f: ['P4.0', 'GPIO:SYS_MFP_P40_GPIO@P4_MFP', 'PWM0:SYS_MFP_P40_PWM0@P4_MFP', 'T2EX:SYS_MFP_P40_T2EX@P4_MFP'] },
	{ f: ['P4.1', 'GPIO:SYS_MFP_P41_GPIO@P4_MFP', 'PWM1:SYS_MFP_P41_PWM1@P4_MFP', 'T3EX:SYS_MFP_P41_T3EX@P4_MFP'] },
	{ f: ['P4.2', 'GPIO:SYS_MFP_P42_GPIO@P4_MFP', 'PWM2:SYS_MFP_P42_PWM2@P4_MFP'] },
	{ f: ['P4.3', 'GPIO:SYS_MFP_P43_GPIO@P4_MFP', 'PWM3:SYS_MFP_P43_PWM3@P4_MFP'] },
	{ f: ['P4.4', 'GPIO:SYS_MFP_P44_GPIO@P4_MFP', 'SCL1:SYS_MFP_P44_SCL1@P4_MFP'] },
	{ f: ['P4.5', 'GPIO:SYS_MFP_P45_GPIO@P4_MFP', 'SDA1:SYS_MFP_P45_SDA1@P4_MFP'] },
	{ f: ['P4.6', 'GPIO:SYS_MFP_P46_GPIO@P4_MFP', 'ICE_CLK:SYS_MFP_P46_ICE_CLK@P4_MFP'] },
	{ f: ['P4.7', 'GPIO:SYS_MFP_P47_GPIO@P4_MFP', 'ICE_DAT:SYS_MFP_P47_ICE_DAT@P4_MFP'] },

	{ f: ['P5.0', 'GPIO:SYS_MFP_P50_GPIO@P5_MFP', 'T0EX:SYS_MFP_P50_T0EX@P5_MFP'] },
	{ f: ['P5.1', 'GPIO:SYS_MFP_P51_GPIO@P5_MFP', 'T1EX:SYS_MFP_P51_T1EX@P5_MFP'] },
	{ f: ['P5.2', 'GPIO:SYS_MFP_P52_GPIO@P5_MFP', 'SDA0:SYS_MFP_P52_SDA0@P5_MFP'] },
	{ f: ['P5.3', 'GPIO:SYS_MFP_P53_GPIO@P5_MFP', 'SCL0:SYS_MFP_P53_SCL0@P5_MFP'] },
	{ f: ['P5.4', 'GPIO:SYS_MFP_P54_GPIO@P5_MFP'] },
	{ f: ['P5.5', 'GPIO:SYS_MFP_P55_GPIO@P5_MFP'] },
	{ f: ['P5.6', 'GPIO:SYS_MFP_P56_GPIO@P5_MFP'] },
	{ f: ['P5.7', 'GPIO:SYS_MFP_P57_GPIO@P5_MFP'] },

	{ f: ['P6.0', 'GPIO:SYS_MFP_P60_GPIO@P6_MFP'] },
	{ f: ['P6.1', 'GPIO:SYS_MFP_P61_GPIO@P6_MFP'] },
	{ f: ['P6.2', 'GPIO:SYS_MFP_P62_GPIO@P6_MFP'] },
	{ f: ['P6.3', 'GPIO:SYS_MFP_P63_GPIO@P6_MFP'] },
	{ f: ['P6.4', 'GPIO:SYS_MFP_P64_GPIO@P6_MFP'] },
	{ f: ['P6.5', 'GPIO:SYS_MFP_P65_GPIO@P6_MFP'] },
	{ f: ['P6.6', 'GPIO:SYS_MFP_P66_GPIO@P6_MFP'] },
	{ f: ['P6.7', 'GPIO:SYS_MFP_P67_GPIO@P6_MFP'] },

	{ f: ['P7.0', 'GPIO:SYS_MFP_P70_GPIO@P7_MFP'] },
	{ f: ['P7.1', 'GPIO:SYS_MFP_P71_GPIO@P7_MFP'] },
	{ f: ['P7.2', 'GPIO:SYS_MFP_P72_GPIO@P7_MFP'] },
	{ f: ['P7.3', 'GPIO:SYS_MFP_P73_GPIO@P7_MFP'] },
	{ f: ['P7.4', 'GPIO:SYS_MFP_P74_GPIO@P7_MFP'] },
	{ f: ['P7.5', 'GPIO:SYS_MFP_P75_GPIO@P7_MFP'] },
	{ f: ['P7.6', 'GPIO:SYS_MFP_P76_GPIO@P7_MFP'] },
	{ f: ['P7.7', 'GPIO:SYS_MFP_P77_GPIO@P7_MFP'] }
];

NUTOOL_PIN.g_cfg_gpiosDescriptions = [];
NUTOOL_PIN.g_cfg_regDescriptions = {};
NUTOOL_PIN.g_cfg_regDescriptions.P0_MFP = '0x50000030';
NUTOOL_PIN.g_cfg_regDescriptions.P1_MFP = '0x50000034';
NUTOOL_PIN.g_cfg_regDescriptions.P2_MFP = '0x50000038';
NUTOOL_PIN.g_cfg_regDescriptions.P3_MFP = '0x5000003C';
NUTOOL_PIN.g_cfg_regDescriptions.P4_MFP = '0x50000040';
NUTOOL_PIN.g_cfg_regDescriptions.P5_MFP = '0x50000044';
NUTOOL_PIN.g_cfg_regDescriptions.P6_MFP = '0x50000048';

NUTOOL_PIN.g_cfg_gpioMatrix = [
	{ f: ['P0.0', 'P0_MFP[0]:0', 'P0_MFP[8]:1'] },
	{ f: ['P0.1', 'P0_MFP[1]:0', 'P0_MFP[9]:1'] },
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
	{ f: ['P4.7', 'P4_MFP[7]:0', 'P4_MFP[15]:1'] },

	{ f: ['P5.0'] },
	{ f: ['P5.1', 'P5_MFP[1]:0', 'P5_MFP[9]:1'] },
	{ f: ['P5.2', 'P5_MFP[2]:0', 'P5_MFP[10]:1'] },
	{ f: ['P5.3', 'P5_MFP[3]:0', 'P5_MFP[11]:1'] },
	{ f: ['P5.4'] },
	{ f: ['P5.5'] },
	{ f: ['P5.6'] },
	{ f: ['P5.7'] },

	{ f: ['P6.0'] },
	{ f: ['P6.1'] },
	{ f: ['P6.2'] },
	{ f: ['P6.3'] },
	{ f: ['P6.4'] },
	{ f: ['P6.5'] },
	{ f: ['P6.6'] },
	{ f: ['P6.7'] },

	{ f: ['P7.0'] },
	{ f: ['P7.1'] },
	{ f: ['P7.2'] },
	{ f: ['P7.3'] },
	{ f: ['P7.4'] },
	{ f: ['P7.5'] },
	{ f: ['P7.6'] },
	{ f: ['P7.7'] }
];

NUTOOL_PIN.g_cfg_shareBits = [];
NUTOOL_PIN.g_cfg_addGPIO = {};
NUTOOL_PIN.g_cfg_unusedGPIO = {};
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
