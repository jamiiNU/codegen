// chip content
NUTOOL_PIN.g_cfg_chips = [
	{ name: "M0519VE3AE", pkg: "LQFP100" },

	{ name: "M0519SE3AE", pkg: "LQFP64" },
	{ name: "M0519SD3AE", pkg: "LQFP64" },

	{ name: "M0519LE3AE", pkg: "LQFP48" },
	{ name: "M0519LD3AE", pkg: "LQFP48" }
];

NUTOOL_PIN.g_cfg_pkgs = {
	"LQFP100": [
		'PVSS', 'P9.7', 'P3.7', 'P3.6', 'P3.5', 'P3.4', 'P3.2', 'P1.7', 'LDO_CAP', 'VDD',
		'VSS', 'PA.1', 'PA.0', 'P5.7', 'P5.6', 'P1.6', 'P1.5', 'P1.4', 'P1.3', 'P1.2',
		'P4.4', 'P4.5', 'P4.0', 'P4.1', 'P4.2',
		'P4.3', 'P3.3', 'P4.6', 'P1.1', 'P1.0', 'P3.0', 'P3.1', 'P4.7', 'VDD', 'VSS',
		'P5.0', 'P5.1', 'P2.7', 'P2.6', 'P2.5', 'P2.4', 'P0.7', 'P0.6', 'P0.5', 'P0.4',
		'P2.3', 'P2.2', 'P2.1', 'P2.0', 'P5.2',
		'P5.3', 'P5.4', 'P5.5', 'P0.3', 'P0.2', 'P0.1', 'P0.0', 'P8.7', 'P8.6', 'VSS',
		'VDD', 'P6.7', 'P6.6', 'P6.5', 'P6.4', 'P6.3', 'P6.2', 'P6.1', 'P6.0', 'P8.2',
		'P8.1', 'P8.0', 'AVSS', 'AVDD', 'VREF',
		'P7.7', 'P7.6', 'P7.5', 'P7.4', 'P7.3', 'P7.2', 'P7.1', 'P7.0', 'P8.4', 'P8.3',
		'P9.0', 'P9.1', 'P9.2', 'VDD', 'VSS', 'P8.5', 'P9.3', 'nRESET', 'XOUT', 'XIN',
		'ICE_DAT', 'ICE_CLK', 'P9.4', 'P9.5', 'P9.6'
	],
	"LQFP64": [
		'P3.5', 'P3.4', 'P3.2', 'P1.7', 'LDO_CAP', 'VDD', 'VSS', 'PA.1', 'PA.0', 'P5.7',
		'P5.6', 'P1.6', 'P1.5', 'P1.4', 'P1.3', 'P1.2',
		'P1.1', 'P1.0', 'P3.0', 'P3.1', 'VDD', 'VSS', 'P5.0', 'P5.1', 'P2.7', 'P2.6',
		'P2.5', 'P2.4', 'P0.5', 'P0.4', 'P2.0', 'P5.2',
		'P5.3', 'P5.4', 'P6.7', 'P6.6', 'P6.5', 'P6.4', 'P6.3', 'P6.2', 'P6.1', 'P6.0',
		'P8.2', 'P8.1', 'P8.0', 'AVSS', 'AVDD', 'VREF',
		'P7.7', 'P7.6', 'P7.5', 'P7.4', 'P7.3', 'P7.2', 'P7.1', 'P7.0', 'P9.0', 'P9.1',
		'P9.2', 'nRESET', 'XOUT', 'XIN', 'ICE_DAT', 'ICE_CLK'
	],
	"LQFP48": [
		'ICE_CLK', 'ICE_DAT', 'XIN', 'XOUT', 'P1.7', 'LDO_CAP', 'VDD', 'VSS', 'PA.1', 'PA.0',
		'P5.7', 'P5.6',
		'P1.2', 'P1.3', 'P1.4', 'P1.5', 'P3.0', 'P3.1', 'P5.0', 'P5.1', 'P2.7', 'P2.6',
		'P0.7', 'P6.7',
		'P6.6', 'P6.5', 'P6.4', 'P6.3', 'P6.2', 'P6.1', 'P6.0', 'P8.2', 'P8.1', 'P8.0',
		'AVSS', 'AVDD',
		'P7.7', 'P7.6', 'P7.5', 'P7.4', 'P7.3', 'P7.2', 'P7.1', 'P7.0', 'P9.0', 'P9.1',
		'P9.2', 'nRESET'
	]
};

NUTOOL_PIN.g_cfg_OrCAD = {};

NUTOOL_PIN.g_cfg_gpios = [
	{ f: ['P0.0:0', 'EPWM0_CH0:1', 'ECAP1_IC0:3']},
	{ f: ['P0.1:0', 'EPWM0_CH1:1', 'ECAP1_IC1:3']},
	{ f: ['P0.2:0', 'EPWM0_CH2:1', 'ECAP1_IC2:3']},
	{ f: ['P0.3:0', 'EPWM0_CH3:1', 'STADC:3']},
	{ f: ['P0.4:0', 'EPWM0_CH4:1']},
	{ f: ['P0.5:0', 'EPWM0_CH5:1']},
	{ f: ['P0.6:0', 'EPWM0_BRAKE1:1']},
	{ f: ['P0.7:0', 'STADC:1']},

	{ f: ['P1.0:0', 'EPWM1_CH0:1']},
	{ f: ['P1.1:0', 'EPWM1_CH1:1']},
	{ f: ['P1.2:0', 'EPWM1_CH2:1']},
	{ f: ['P1.3:0', 'EPWM1_CH3:1']},
	{ f: ['P1.4:0', 'EPWM1_CH4:1']},
	{ f: ['P1.5:0', 'EPWM1_CH5:1']},
	{ f: ['P1.6:0', 'EPWM0_BRAKE0:1']},
	{ f: ['P1.7:0', 'EPWM1_BRAKE0:1']},

	{ f: ['P2.0:0', 'SPI2_MOSI:1', 'ACMP2_O:2']},
	{ f: ['P2.1:0', 'ECAP0_IC2:1']},
	{ f: ['P2.2:0', 'ECAP0_IC1:1']},
	{ f: ['P2.3:0', 'ECAP0_IC0:1']},
	{ f: ['P2.4:0']},
	{ f: ['P2.5:0']},
	{ f: ['P2.6:0', 'SPI0_SS:2', 'UART1_nCTS:3']},
	{ f: ['P2.7:0', 'SPI0_CLK:2', 'UART1_nRTS:3']},

	{ f: ['P3.0:0', 'UART0_RXD:1', 'CLKO:2']},
	{ f: ['P3.1:0', 'UART0_TXD:1', 'ACMP0_O:2']},
	{ f: ['P3.2:0', 'INT0:1']},
	{ f: ['P3.3:0', 'INT1:1']},
	{ f: ['P3.4:0', 'TM0:1', 'I2C0_SDA:2']},
	{ f: ['P3.5:0', 'TM1:1', 'I2C0_SCL:2']},
	{ f: ['P3.6:0']},
	{ f: ['P3.7:0']},

	{ f: ['P4.0:0', 'ECAP1_IC0:1']},
	{ f: ['P4.1:0', 'ECAP1_IC1:1']},
	{ f: ['P4.2:0', 'ECAP1_IC2:1']},
	{ f: ['P4.3:0']},
	{ f: ['P4.4:0']},
	{ f: ['P4.5:0']},
	{ f: ['P4.6:0', 'TM2:1']},
	{ f: ['P4.7:0', 'TM3:1']},

	{ f: ['P5.0:0', 'SPI0_MOSI:1', 'UART0_nRTS:2', 'I2C0_SCL:3']},
	{ f: ['P5.1:0', 'SPI0_MISO:1', 'UART0_nCTS:2', 'I2C0_SDA:3']},
	{ f: ['P5.2:0', 'SPI2_MISO:1', 'ACMP1_O:2']},
	{ f: ['P5.3:0', 'SPI2_CLK:1']},
	{ f: ['P5.4:0', 'SPI2_SS:1']},
	{ f: ['P5.5:0', 'CLKO:1']},
	{ f: ['P5.6:0', 'BPWM0_CH0:1']},
	{ f: ['P5.7:0', 'BPWM0_CH1:1']},

	{ f: ['P6.0:0', 'EADC0_CH0:1']},
	{ f: ['P6.1:0', 'EADC0_CH1:1']},
	{ f: ['P6.2:0', 'EADC0_CH2:1']},
	{ f: ['P6.3:0', 'EADC0_CH3:1']},
	{ f: ['P6.4:0', 'EADC0_CH4_and_ACMP1_N:1']},
	{ f: ['P6.5:0', 'EADC0_CH5_and_ACMP1_P:1']},
	{ f: ['P6.6:0', 'EADC0_CH6:1']},
	{ f: ['P6.7:0', 'EADC0_CH7:1']},

	{ f: ['P7.0:0', 'EADC1_CH0:1']},
	{ f: ['P7.1:0', 'EADC1_CH1:1']},
	{ f: ['P7.2:0', 'EADC1_CH2:1']},
	{ f: ['P7.3:0', 'EADC1_CH3:1']},
	{ f: ['P7.4:0', 'EADC1_CH4_and_ACMP2_N:1'] },
	{ f: ['P7.5:0', 'EADC1_CH5_and_ACMP2_P:1'] },
	{ f: ['P7.6:0', 'EADC1_CH6:1']},
	{ f: ['P7.7:0', 'EADC1_CH7:1']},

	{ f: ['P8.0:0', 'OP0_P:1']},
	{ f: ['P8.1:0', 'OP0_N:1']},
	{ f: ['P8.2:0', 'OP0_O:1']},
	{ f: ['P8.3:0', 'ACMP0_N:1']},
	{ f: ['P8.4:0', 'ACMP0_P:1']},
	{ f: ['P8.5:0']},
	{ f: ['P8.6:0']},
	{ f: ['P8.7:0', 'ACMP0_O:1']},

	{ f: ['P9.0:0', 'OP1_O:1']},
	{ f: ['P9.1:0', 'OP1_N:1']},
	{ f: ['P9.2:0', 'OP1_P:1']},
	{ f: ['P9.3:0', 'EPWM1_BRAKE1:1']},
	{ f: ['P9.4:0', 'SPI1_CLK:1']},
	{ f: ['P9.5:0', 'SPI1_MISO:1']},
	{ f: ['P9.6:0', 'SPI1_MOSI:1']},
	{ f: ['P9.7:0', 'SPI1_SS:1'] },

	{ f: ['PA.0:0', 'UART1_TXD:1', 'I2C0_SDA:3']},
	{ f: ['PA.1:0', 'UART1_RXD:1', 'I2C0_SCL:3']}
];

NUTOOL_PIN.g_cfg_gpiosDefines = [
	{ f: ['P0.0', 'GPIO:SYS_MFP_P00_GPIO@P0_MFP', 'EPWM0_CH0:SYS_MFP_P00_EPWM0_CH0@P0_MFP', 'ECAP1_IC0:SYS_MFP_P00_ECAP1_IC0@P0_MFP'] },
	{ f: ['P0.1', 'GPIO:SYS_MFP_P01_GPIO@P0_MFP', 'EPWM0_CH1:SYS_MFP_P01_EPWM0_CH1@P0_MFP', 'ECAP1_IC1:SYS_MFP_P01_ECAP1_IC1@P0_MFP'] },
	{ f: ['P0.2', 'GPIO:SYS_MFP_P02_GPIO@P0_MFP', 'EPWM0_CH2:SYS_MFP_P02_EPWM0_CH2@P0_MFP', 'ECAP1_IC2:SYS_MFP_P02_ECAP1_IC2@P0_MFP'] },
	{ f: ['P0.3', 'GPIO:SYS_MFP_P03_GPIO@P0_MFP', 'EPWM0_CH3:SYS_MFP_P03_EPWM0_CH3@P0_MFP', 'STADC:SYS_MFP_P03_STADC@P0_MFP'] },
	{ f: ['P0.4', 'GPIO:SYS_MFP_P04_GPIO@P0_MFP', 'EPWM0_CH4:SYS_MFP_P04_EPWM0_CH4@P0_MFP'] },
	{ f: ['P0.5', 'GPIO:SYS_MFP_P05_GPIO@P0_MFP', 'EPWM0_CH5:SYS_MFP_P05_EPWM0_CH5@P0_MFP'] },
	{ f: ['P0.6', 'GPIO:SYS_MFP_P06_GPIO@P0_MFP', 'EPWM0_BRAKE1:SYS_MFP_P06_EPWM0_BRAKE1@P0_MFP'] },
	{ f: ['P0.7', 'GPIO:SYS_MFP_P07_GPIO@P0_MFP', 'STADC:SYS_MFP_P07_STADC@P0_MFP'] },

	{ f: ['P1.0', 'GPIO:SYS_MFP_P10_GPIO@P1_MFP', 'EPWM1_CH0:SYS_MFP_P10_EPWM1_CH0@P1_MFP'] },
	{ f: ['P1.1', 'GPIO:SYS_MFP_P11_GPIO@P1_MFP', 'EPWM1_CH1:SYS_MFP_P11_EPWM1_CH1@P1_MFP'] },
	{ f: ['P1.2', 'GPIO:SYS_MFP_P12_GPIO@P1_MFP', 'EPWM1_CH2:SYS_MFP_P12_EPWM1_CH2@P1_MFP'] },
	{ f: ['P1.3', 'GPIO:SYS_MFP_P13_GPIO@P1_MFP', 'EPWM1_CH3:SYS_MFP_P13_EPWM1_CH3@P1_MFP'] },
	{ f: ['P1.4', 'GPIO:SYS_MFP_P14_GPIO@P1_MFP', 'EPWM1_CH4:SYS_MFP_P14_EPWM1_CH4@P1_MFP'] },
	{ f: ['P1.5', 'GPIO:SYS_MFP_P15_GPIO@P1_MFP', 'EPWM1_CH5:SYS_MFP_P15_EPWM1_CH5@P1_MFP'] },
	{ f: ['P1.6', 'GPIO:SYS_MFP_P16_GPIO@P1_MFP', 'EPWM0_BRAKE0:SYS_MFP_P16_EPWM0_BRAKE0@P1_MFP'] },
	{ f: ['P1.7', 'GPIO:SYS_MFP_P17_GPIO@P1_MFP', 'EPWM1_BRAKE0:SYS_MFP_P17_EPWM1_BRAKE0@P1_MFP'] },

	{ f: ['P2.0', 'GPIO:SYS_MFP_P20_GPIO@P2_MFP', 'SPI2_MOSI:SYS_MFP_P20_SPI2_MOSI@P2_MFP', 'ACMP2_O:SYS_MFP_P20_ACMP2_O@P2_MFP'] },
	{ f: ['P2.1', 'GPIO:SYS_MFP_P21_GPIO@P2_MFP', 'ECAP0_IC2:SYS_MFP_P21_ECAP0_IC2@P2_MFP'] },
	{ f: ['P2.2', 'GPIO:SYS_MFP_P22_GPIO@P2_MFP', 'ECAP0_IC1:SYS_MFP_P22_ECAP0_IC1@P2_MFP'] },
	{ f: ['P2.3', 'GPIO:SYS_MFP_P23_GPIO@P2_MFP', 'ECAP0_IC0:SYS_MFP_P23_ECAP0_IC0@P2_MFP'] },
	{ f: ['P2.4', 'GPIO:SYS_MFP_P24_GPIO@P2_MFP'] },
	{ f: ['P2.5', 'GPIO:SYS_MFP_P25_GPIO@P2_MFP'] },
	{ f: ['P2.6', 'GPIO:SYS_MFP_P26_GPIO@P2_MFP', 'SPI0_SS:SYS_MFP_P26_SPI0_SS@P2_MFP', 'UART1_nCTS:SYS_MFP_P26_UART1_nCTS@P2_MFP'] },
	{ f: ['P2.7', 'GPIO:SYS_MFP_P27_GPIO@P2_MFP', 'SPI0_CLK:SYS_MFP_P27_SPI0_CLK@P2_MFP', 'UART1_nRTS:SYS_MFP_P27_UART1_nRTS@P2_MFP'] },

	{ f: ['P3.0', 'GPIO:SYS_MFP_P30_GPIO@P3_MFP', 'UART0_RXD:SYS_MFP_P30_UART0_RXD@P3_MFP', 'CLKO:SYS_MFP_P30_CLKO@P3_MFP'] },
	{ f: ['P3.1', 'GPIO:SYS_MFP_P31_GPIO@P3_MFP', 'UART0_TXD:SYS_MFP_P31_UART0_TXD@P3_MFP', 'ACMP0_O:SYS_MFP_P31_ACMP0_O@P3_MFP'] },
	{ f: ['P3.2', 'GPIO:SYS_MFP_P32_GPIO@P3_MFP', 'INT0:SYS_MFP_P32_INT0@P3_MFP'] },
	{ f: ['P3.3', 'GPIO:SYS_MFP_P33_GPIO@P3_MFP', 'INT1:SYS_MFP_P33_INT1@P3_MFP'] },
	{ f: ['P3.4', 'GPIO:SYS_MFP_P34_GPIO@P3_MFP', 'TM0:SYS_MFP_P34_TM0@P3_MFP', 'I2C0_SDA:SYS_MFP_P34_I2C0_SDA@P3_MFP'] },
	{ f: ['P3.5', 'GPIO:SYS_MFP_P35_GPIO@P3_MFP', 'TM1:SYS_MFP_P35_TM1@P3_MFP', 'I2C0_SCL:SYS_MFP_P35_I2C0_SCL@P3_MFP'] },
	{ f: ['P3.6', 'GPIO:SYS_MFP_P36_GPIO@P3_MFP'] },
	{ f: ['P3.7', 'GPIO:SYS_MFP_P37_GPIO@P3_MFP'] },

	{ f: ['P4.0', 'GPIO:SYS_MFP_P40_GPIO@P4_MFP', 'ECAP1_IC0:SYS_MFP_P40_ECAP1_IC0@P4_MFP'] },
	{ f: ['P4.1', 'GPIO:SYS_MFP_P41_GPIO@P4_MFP', 'ECAP1_IC1:SYS_MFP_P41_ECAP1_IC1@P4_MFP'] },
	{ f: ['P4.2', 'GPIO:SYS_MFP_P42_GPIO@P4_MFP', 'ECAP1_IC2:SYS_MFP_P42_ECAP1_IC2@P4_MFP'] },
	{ f: ['P4.3', 'GPIO:SYS_MFP_P43_GPIO@P4_MFP'] },
	{ f: ['P4.4', 'GPIO:SYS_MFP_P44_GPIO@P4_MFP'] },
	{ f: ['P4.5', 'GPIO:SYS_MFP_P45_GPIO@P4_MFP'] },
	{ f: ['P4.6', 'GPIO:SYS_MFP_P46_GPIO@P4_MFP', 'TM2:SYS_MFP_P46_TM2@P4_MFP'] },
	{ f: ['P4.7', 'GPIO:SYS_MFP_P47_GPIO@P4_MFP', 'TM3:SYS_MFP_P47_TM3@P4_MFP'] },

	{ f: ['P5.0', 'GPIO:SYS_MFP_P50_GPIO@P5_MFP', 'SPI0_MOSI:SYS_MFP_P50_SPI0_MOSI@P5_MFP', 'UART0_nRTS:SYS_MFP_P50_UART0_nRTS@P5_MFP', 'I2C0_SCL:SYS_MFP_P50_I2C0_SCL@P5_MFP'] },
	{ f: ['P5.1', 'GPIO:SYS_MFP_P51_GPIO@P5_MFP', 'SPI0_MISO:SYS_MFP_P51_SPI0_MISO@P5_MFP', 'UART0_nCTS:SYS_MFP_P51_UART0_nCTS@P5_MFP', 'I2C0_SDA:SYS_MFP_P51_I2C0_SDA@P5_MFP'] },
	{ f: ['P5.2', 'GPIO:SYS_MFP_P52_GPIO@P5_MFP', 'SPI2_MISO:SYS_MFP_P52_SPI2_MISO@P5_MFP', 'ACMP1_O:SYS_MFP_P52_ACMP1_O@P5_MFP'] },
	{ f: ['P5.3', 'GPIO:SYS_MFP_P53_GPIO@P5_MFP', 'SPI2_CLK:SYS_MFP_P53_SPI2_CLK@P5_MFP'] },
	{ f: ['P5.4', 'GPIO:SYS_MFP_P54_GPIO@P5_MFP', 'SPI2_SS:SYS_MFP_P54_SPI2_SS@P5_MFP'] },
	{ f: ['P5.5', 'GPIO:SYS_MFP_P55_GPIO@P5_MFP', 'CLKO:SYS_MFP_P55_CLKO@P5_MFP'] },
	{ f: ['P5.6', 'GPIO:SYS_MFP_P56_GPIO@P5_MFP', 'BPWM0_CH0:SYS_MFP_P56_BPWM0_CH0@P5_MFP'] },
	{ f: ['P5.7', 'GPIO:SYS_MFP_P57_GPIO@P5_MFP', 'BPWM0_CH1:SYS_MFP_P57_BPWM0_CH1@P5_MFP'] },

	{ f: ['P6.0', 'GPIO:SYS_MFP_P60_GPIO@P6_MFP', 'EADC0_CH0:SYS_MFP_P60_EADC0_CH0@P6_MFP'] },
	{ f: ['P6.1', 'GPIO:SYS_MFP_P61_GPIO@P6_MFP', 'EADC0_CH1:SYS_MFP_P61_EADC0_CH1@P6_MFP'] },
	{ f: ['P6.2', 'GPIO:SYS_MFP_P62_GPIO@P6_MFP', 'EADC0_CH2:SYS_MFP_P62_EADC0_CH2@P6_MFP'] },
	{ f: ['P6.3', 'GPIO:SYS_MFP_P63_GPIO@P6_MFP', 'EADC0_CH3:SYS_MFP_P63_EADC0_CH3@P6_MFP'] },
	{ f: ['P6.4', 'GPIO:SYS_MFP_P64_GPIO@P6_MFP', 'EADC0_CH4_and_ACMP1_N:SYS_MFP_P64_EADC0_CH4@P6_MFP', 'EADC0_CH4:SYS_MFP_P64_EADC0_CH4@P6_MFP', 'ACMP1_N:SYS_MFP_P64_ACMP1_N@P6_MFP'] },
	{ f: ['P6.5', 'GPIO:SYS_MFP_P65_GPIO@P6_MFP', 'EADC0_CH5_and_ACMP1_P:SYS_MFP_P65_EADC0_CH5@P6_MFP', 'EADC0_CH5:SYS_MFP_P65_EADC0_CH5@P6_MFP', 'ACMP1_P:SYS_MFP_P65_ACMP1_P@P6_MFP'] },
	{ f: ['P6.6', 'GPIO:SYS_MFP_P66_GPIO@P6_MFP', 'EADC0_CH6:SYS_MFP_P66_EADC0_CH6@P6_MFP'] },
	{ f: ['P6.7', 'GPIO:SYS_MFP_P67_GPIO@P6_MFP', 'EADC0_CH7:SYS_MFP_P67_EADC0_CH7@P6_MFP'] },

	{ f: ['P7.0', 'GPIO:SYS_MFP_P70_GPIO@P7_MFP', 'EADC1_CH0:SYS_MFP_P70_EADC1_CH0@P7_MFP'] },
	{ f: ['P7.1', 'GPIO:SYS_MFP_P71_GPIO@P7_MFP', 'EADC1_CH1:SYS_MFP_P71_EADC1_CH1@P7_MFP'] },
	{ f: ['P7.2', 'GPIO:SYS_MFP_P72_GPIO@P7_MFP', 'EADC1_CH2:SYS_MFP_P72_EADC1_CH2@P7_MFP'] },
	{ f: ['P7.3', 'GPIO:SYS_MFP_P73_GPIO@P7_MFP', 'EADC1_CH3:SYS_MFP_P73_EADC1_CH3@P7_MFP'] },
	{ f: ['P7.4', 'GPIO:SYS_MFP_P74_GPIO@P7_MFP', 'EADC1_CH4_and_ACMP2_N:SYS_MFP_P74_EADC1_CH4@P7_MFP', 'EADC1_CH4:SYS_MFP_P74_EADC1_CH4@P7_MFP', 'ACMP2_N:SYS_MFP_P74_ACMP2_N@P7_MFP'] },
	{ f: ['P7.5', 'GPIO:SYS_MFP_P75_GPIO@P7_MFP', 'EADC1_CH5_and_ACMP2_P:SYS_MFP_P75_EADC1_CH5@P7_MFP', 'EADC1_CH5:SYS_MFP_P75_EADC1_CH5@P7_MFP', 'ACMP2_P:SYS_MFP_P75_ACMP2_P@P7_MFP'] },
	{ f: ['P7.6', 'GPIO:SYS_MFP_P76_GPIO@P7_MFP', 'EADC1_CH6:SYS_MFP_P76_EADC1_CH6@P7_MFP'] },
	{ f: ['P7.7', 'GPIO:SYS_MFP_P77_GPIO@P7_MFP', 'EADC1_CH7:SYS_MFP_P77_EADC1_CH7@P7_MFP'] },

	{ f: ['P8.0', 'GPIO:SYS_MFP_P80_GPIO@P8_MFP', 'OP0_P:SYS_MFP_P80_OP0_P@P8_MFP'] },
	{ f: ['P8.1', 'GPIO:SYS_MFP_P81_GPIO@P8_MFP', 'OP0_N:SYS_MFP_P81_OP0_N@P8_MFP'] },
	{ f: ['P8.2', 'GPIO:SYS_MFP_P82_GPIO@P8_MFP', 'OP0_O:SYS_MFP_P82_OP0_O@P8_MFP'] },
	{ f: ['P8.3', 'GPIO:SYS_MFP_P83_GPIO@P8_MFP', 'ACMP0_N:SYS_MFP_P83_ACMP0_N@P8_MFP'] },
	{ f: ['P8.4', 'GPIO:SYS_MFP_P84_GPIO@P8_MFP', 'ACMP0_P:SYS_MFP_P84_ACMP0_P@P8_MFP'] },
	{ f: ['P8.5', 'GPIO:SYS_MFP_P85_GPIO@P8_MFP'] },
	{ f: ['P8.6', 'GPIO:SYS_MFP_P86_GPIO@P8_MFP'] },
	{ f: ['P8.7', 'GPIO:SYS_MFP_P87_GPIO@P8_MFP', 'ACMP0_O:SYS_MFP_P87_ACMP0_O@P8_MFP'] },

	{ f: ['P9.0', 'GPIO:SYS_MFP_P90_GPIO@P9_MFP', 'OP1_O:SYS_MFP_P90_OP1_O@P9_MFP'] },
	{ f: ['P9.1', 'GPIO:SYS_MFP_P91_GPIO@P9_MFP', 'OP1_N:SYS_MFP_P91_OP1_N@P9_MFP'] },
	{ f: ['P9.2', 'GPIO:SYS_MFP_P92_GPIO@P9_MFP', 'OP1_P:SYS_MFP_P92_OP1_P@P9_MFP'] },
	{ f: ['P9.3', 'GPIO:SYS_MFP_P93_GPIO@P9_MFP', 'EPWM1_BRAKE1:SYS_MFP_P93_EPWM1_BRAKE1@P9_MFP'] },
	{ f: ['P9.4', 'GPIO:SYS_MFP_P94_GPIO@P9_MFP', 'SPI1_CLK:SYS_MFP_P94_SPI1_CLK@P9_MFP'] },
	{ f: ['P9.5', 'GPIO:SYS_MFP_P95_GPIO@P9_MFP', 'SPI1_MISO:SYS_MFP_P95_SPI1_MISO@P9_MFP'] },
	{ f: ['P9.6', 'GPIO:SYS_MFP_P96_GPIO@P9_MFP', 'SPI1_MOSI:SYS_MFP_P96_SPI1_MOSI@P9_MFP'] },
	{ f: ['P9.7', 'GPIO:SYS_MFP_P97_GPIO@P9_MFP', 'SPI1_SS:SYS_MFP_P97_SPI1_SS@P9_MFP'] },

	{ f: ['PA.0', 'GPIO:SYS_MFP_PA0_GPIO@PA_MFP', 'UART1_TXD:SYS_MFP_PA0_UART1_TXD@PA_MFP', 'I2C0_SDA:SYS_MFP_PA0_I2C0_SDA@PA_MFP'] },
	{ f: ['PA.1', 'GPIO:SYS_MFP_PA1_GPIO@PA_MFP', 'UART1_RXD:SYS_MFP_PA1_UART1_RXD@PA_MFP', 'I2C0_SCL:SYS_MFP_PA1_I2C0_SCL@PA_MFP'] }
];

NUTOOL_PIN.g_cfg_gpiosDescriptions = [
	'ACMP0_N:Analog comparator0 negative input pin',
	'ACMP0_O:Analog comparator0 output',
	'ACMP0_P:Analog comparator0 positive input pin',
	'ACMP1_O:Analog comparator1 output',
	'ACMP2_O:Analog comparator2 output',

	'AVDD:Power supply for internal analog circuit',
	'AVSS:Ground pin for analog circuit',

	'BPWM0_CH0:BPWM0 channel0 output/capture input',
	'BPWM0_CH1:BPWM0 channel1 output/capture input',

	'CLKO:Clock Output',

	'EADC0_CH0:EADC0 channel0 analog input',
	'EADC0_CH1:EADC0 channel1 analog input',
	'EADC0_CH2:EADC0 channel2 analog input',
	'EADC0_CH3:EADC0 channel3 analog input',
	'EADC0_CH4_and_ACMP1_N:EADC0 channel4 analog input or Analog comparator1 negative input pin',
	'EADC0_CH5_and_ACMP1_P:EADC0 channel5 analog input or Analog comparator1 positive input pin',
	'EADC0_CH6:EADC0 channel6 analog input',
	'EADC0_CH7:EADC0 channel7 analog input',
	'EADC1_CH0:EADC1 channel0 analog input',
	'EADC1_CH1:EADC1 channel1 analog input',
	'EADC1_CH2:EADC1 channel2 analog input',
	'EADC1_CH3:EADC1 channel3 analog input',
	'EADC1_CH4_and_ACMP2_N:EADC1 channel4 analog input or Analog comparator2 negative input pin',
	'EADC1_CH5_and_ACMP2_P:EADC1 channel5 analog input or Analog comparator2 positive input pin',
	'EADC1_CH6:EADC1 channel6 analog input',
	'EADC1_CH7:EADC1 channel7 analog input',

	'ECAP0_IC0:Input 0 of enhanced capture unit 0',
	'ECAP0_IC1:Input 1 of enhanced capture unit 0',
	'ECAP0_IC2:Input 2 of enhanced capture unit 0',
	'ECAP1_IC0:Input 0 of enhanced capture unit 1',
	'ECAP1_IC1:Input 1 of enhanced capture unit 1',
	'ECAP1_IC2:Input 2 of enhanced capture unit 1',

	'EPWM0_BRAKE0:Brake input pin 0 of EPWM0',
	'EPWM0_BRAKE1:Brake input pin 1 of EPWM0',
	'EPWM0_CH0:EPWM0 channel0 output',
	'EPWM0_CH1:EPWM0 channel1 output',
	'EPWM0_CH2:EPWM0 channel2 output',
	'EPWM0_CH3:EPWM0 channel3 output',
	'EPWM0_CH4:EPWM0 channel4 output',
	'EPWM0_CH5:EPWM0 channel5 output',
	'EPWM1_BRAKE0:Brake input pin 0 of EPWM1',
	'EPWM1_BRAKE1:Brake input pin 1 of EPWM1',
	'EPWM1_CH0:EPWM1 channel0 output',
	'EPWM1_CH1:EPWM1 channel1 output',
	'EPWM1_CH2:EPWM1 channel2 output',
	'EPWM1_CH3:EPWM1 channel3 output',
	'EPWM1_CH4:EPWM1 channel4 output',
	'EPWM1_CH5:EPWM1 channel5 output',

	'I2C0_SCL:I2C0 clock pin',
	'I2C0_SDA:I2C0 data input/output pin',

	'ICE_CLK:Serial wired debugger clock pin',
	'ICE_DAT:Serial wired debugger data pin',

	'INT0:External interrupt0 input pin',
	'INT1:External interrupt1 input pin',

	'LDO_CAP:LDO output pin',
	'nRESET:External reset input: active LOW, with an internal pull-up. Set this pin low reset to initial state',

	'OP0_N:Operational amplifier negative input pin',
	'OP0_O:Operational amplifier output pin',
	'OP0_P:Operational amplifier positive input pin',
	'OP1_N:Operational amplifier negative input pin',
	'OP1_O:Operational amplifier output pin',
	'OP1_P:Operational amplifier positive input pin',

	'SPI0_CLK:SPI0 serial clock pin',
	'SPI0_MISO:1st SPI0 MISO (Master In, Slave Out) pin',
	'SPI0_MOSI:1st SPI0 MOSI (Master Out, Slave In) pin',
	'SPI0_SS:1st SPI0 slave select pin',
	'SPI1_CLK:SPI1 serial clock pin',
	'SPI1_MISO:1st SPI1 MISO (Master In, Slave Out) pin',
	'SPI1_MOSI:1st SPI1 MOSI (Master Out, Slave In) pin',
	'SPI1_SS:1st SPI1 slave select pin',
	'SPI2_CLK:SPI2 serial clock pin',
	'SPI2_MISO:1st SPI2 MISO (Master In, Slave Out) pin',
	'SPI2_MOSI:1st SPI2 MOSI (Master Out, Slave In) pin',
	'SPI2_SS:1st SPI2 slave select pin',

	'STADC:ADC external trigger input',

	'TM0:Timer0 event counter input/external capture input/toggle output',
	'TM1:Timer1 event counter input/external capture input/toggle output',
	'TM2:Timer2 event counter input/external capture input/toggle output',
	'TM3:Timer3 event counter input/external capture input/toggle output',

	'UART0_nCTS:Clear to Send input pin for UART0',
	'UART0_nRTS:Request to Send output pin for UART0',
	'UART0_RXD:Data receiver input pin for UART0',
	'UART0_TXD:Data transmitter output pin for UART0',
	'UART1_nCTS:Clear to Send input pin for UART1',
	'UART1_nRTS:Request to Send output pin for UART1',
	'UART1_RXD:Data receiver input pin for UART1',
	'UART1_TXD:Data transmitter output pin for UART1',

	'VDD:Power supply for I/O ports and LDO source for internal PLL and digital circuit',
	'VREF:Voltage reference input for ADC',
	'VSS:Ground pin for digital circuit',

	'XT1_IN:External 4~24 MHz (high speed) crystal input pin',
	'XT1_OUT:External 4~24 MHz (high speed) crystal output pin'
];

NUTOOL_PIN.g_cfg_regDescriptions = {};
NUTOOL_PIN.g_cfg_regDescriptions.P0_MFP = '0x50000030';
NUTOOL_PIN.g_cfg_regDescriptions.P1_MFP = '0x50000034';
NUTOOL_PIN.g_cfg_regDescriptions.P2_MFP = '0x50000038';
NUTOOL_PIN.g_cfg_regDescriptions.P3_MFP = '0x5000003C';
NUTOOL_PIN.g_cfg_regDescriptions.P4_MFP = '0x50000040';
NUTOOL_PIN.g_cfg_regDescriptions.P5_MFP = '0x50000044';
NUTOOL_PIN.g_cfg_regDescriptions.P6_MFP = '0x50000048';
NUTOOL_PIN.g_cfg_regDescriptions.P7_MFP = '0x5000004C';
NUTOOL_PIN.g_cfg_regDescriptions.P8_MFP = '0x50000050';
NUTOOL_PIN.g_cfg_regDescriptions.P9_MFP = '0x50000054';
NUTOOL_PIN.g_cfg_regDescriptions.PA_MFP = '0x50000058';

NUTOOL_PIN.g_cfg_gpioMatrix = [
	{ f: ['P0.0', 'P0_MFP[0]:0', 'P0_MFP[8]:1'] },
	{ f: ['P0.1', 'P0_MFP[1]:0', 'P0_MFP[9]:1'] },
	{ f: ['P0.2', 'P0_MFP[2]:0', 'P0_MFP[10]:1'] },
	{ f: ['P0.3', 'P0_MFP[3]:0', 'P0_MFP[11]:1'] },
	{ f: ['P0.4', 'P0_MFP[4]:0'] },
	{ f: ['P0.5', 'P0_MFP[5]:0'] },
	{ f: ['P0.6', 'P0_MFP[6]:0'] },
	{ f: ['P0.7', 'P0_MFP[7]:0'] },

	{ f: ['P1.0', 'P1_MFP[0]:0'] },
	{ f: ['P1.1', 'P1_MFP[1]:0'] },
	{ f: ['P1.2', 'P1_MFP[2]:0'] },
	{ f: ['P1.3', 'P1_MFP[3]:0'] },
	{ f: ['P1.4', 'P1_MFP[4]:0'] },
	{ f: ['P1.5', 'P1_MFP[5]:0'] },
	{ f: ['P1.6', 'P1_MFP[6]:0'] },
	{ f: ['P1.7', 'P1_MFP[7]:0'] },

	{ f: ['P2.0', 'P2_MFP[0]:0', 'P2_MFP[8]:1'] },
	{ f: ['P2.1', 'P2_MFP[1]:0'] },
	{ f: ['P2.2', 'P2_MFP[2]:0'] },
	{ f: ['P2.3', 'P2_MFP[3]:0'] },
	{ f: ['P2.4', 'P2_MFP[4]:0', 'P2_MFP[12]:1'] },
	{ f: ['P2.5', 'P2_MFP[5]:0', 'P2_MFP[13]:1'] },
	{ f: ['P2.6', 'P2_MFP[6]:0', 'P2_MFP[14]:1'] },
	{ f: ['P2.7', 'P2_MFP[7]:0', 'P2_MFP[15]:1'] },

	{ f: ['P3.0', 'P3_MFP[0]:0', 'P3_MFP[8]:1'] },
	{ f: ['P3.1', 'P3_MFP[1]:0', 'P3_MFP[9]:1'] },
	{ f: ['P3.2', 'P3_MFP[2]:0'] },
	{ f: ['P3.3', 'P3_MFP[3]:0'] },
	{ f: ['P3.4', 'P3_MFP[4]:0', 'P3_MFP[12]:1'] },
	{ f: ['P3.5', 'P3_MFP[5]:0', 'P3_MFP[13]:1'] },
	{ f: ['P3.6', 'P3_MFP[6]:0'] },
	{ f: ['P3.7', 'P3_MFP[7]:0'] },

	{ f: ['P4.0', 'P4_MFP[0]:0'] },
	{ f: ['P4.1', 'P4_MFP[1]:0'] },
	{ f: ['P4.2', 'P4_MFP[2]:0'] },
	{ f: ['P4.3', 'P4_MFP[3]:0'] },
	{ f: ['P4.4', 'P4_MFP[4]:0'] },
	{ f: ['P4.5', 'P4_MFP[5]:0'] },
	{ f: ['P4.6', 'P4_MFP[6]:0', 'P4_MFP[14]:1'] },
	{ f: ['P4.7', 'P4_MFP[7]:0'] },

	{ f: ['P5.0', 'P5_MFP[0]:0', 'P5_MFP[8]:1'] },
	{ f: ['P5.1', 'P5_MFP[1]:0', 'P5_MFP[9]:1'] },
	{ f: ['P5.2', 'P5_MFP[2]:0', 'P5_MFP[10]:1'] },
	{ f: ['P5.3', 'P5_MFP[3]:0'] },
	{ f: ['P5.4', 'P5_MFP[4]:0'] },
	{ f: ['P5.5', 'P5_MFP[5]:0'] },
	{ f: ['P5.6', 'P5_MFP[6]:0'] },
	{ f: ['P5.7', 'P5_MFP[7]:0'] },

	{ f: ['P6.0', 'P6_MFP[0]:0'] },
	{ f: ['P6.1', 'P6_MFP[1]:0'] },
	{ f: ['P6.2', 'P6_MFP[2]:0'] },
	{ f: ['P6.3', 'P6_MFP[3]:0'] },
	{ f: ['P6.4', 'P6_MFP[4]:0'] },
	{ f: ['P6.5', 'P6_MFP[5]:0'] },
	{ f: ['P6.6', 'P6_MFP[6]:0'] },
	{ f: ['P6.7', 'P6_MFP[7]:0'] },

	{ f: ['P7.0', 'P7_MFP[0]:0'] },
	{ f: ['P7.1', 'P7_MFP[1]:0'] },
	{ f: ['P7.2', 'P7_MFP[2]:0'] },
	{ f: ['P7.3', 'P7_MFP[3]:0'] },
	{ f: ['P7.4', 'P7_MFP[4]:0'] },
	{ f: ['P7.5', 'P7_MFP[5]:0'] },
	{ f: ['P7.6', 'P7_MFP[6]:0'] },
	{ f: ['P7.7', 'P7_MFP[7]:0'] },

	{ f: ['P8.0', 'P8_MFP[0]:0'] },
	{ f: ['P8.1', 'P8_MFP[1]:0'] },
	{ f: ['P8.2', 'P8_MFP[2]:0'] },
	{ f: ['P8.3', 'P8_MFP[3]:0'] },
	{ f: ['P8.4', 'P8_MFP[4]:0'] },
	{ f: ['P8.5'] },
	{ f: ['P8.6'] },
	{ f: ['P8.7', 'P8_MFP[7]:0'] },

	{ f: ['P9.0', 'P9_MFP[0]:0'] },
	{ f: ['P9.1', 'P9_MFP[1]:0'] },
	{ f: ['P9.2', 'P9_MFP[2]:0'] },
	{ f: ['P9.3', 'P9_MFP[3]:0'] },
	{ f: ['P9.4', 'P9_MFP[4]:0'] },
	{ f: ['P9.5', 'P9_MFP[5]:0'] },
	{ f: ['P9.6', 'P9_MFP[6]:0'] },
	{ f: ['P9.7', 'P9_MFP[7]:0'] },

	{ f: ['PA.0', 'PA_MFP[0]:0', 'PA_MFP[8]:1'] },
	{ f: ['PA.1', 'PA_MFP[1]:0', 'PA_MFP[9]:1'] }
];

NUTOOL_PIN.g_cfg_shareBits = [];
NUTOOL_PIN.g_cfg_addGPIO = {};
NUTOOL_PIN.g_cfg_unusedGPIO = {
	"M0519SE3AE(LQFP64)": {
		"P3.1": ["ACMP0_O"]
	},
	"M0519SD2AE(LQFP64)": function () {
		return this["M0519SE3AE(LQFP64)"];
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
