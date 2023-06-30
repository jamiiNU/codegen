//chip content
NUTOOL_PIN.g_cfg_chips = [
	// M030G
	{ name: "M030GGC0AE", pkg: "QFN24" },
	{ name: "M030GGD1AE", pkg: "QFN24" },
	{ name: "M030GGC1AE", pkg: "QFN24" },
	{ name: "M030GTC1AE", pkg: "QFN33" },
	{ name: "M030GTC0AE", pkg: "QFN33" },
	{ name: "M030GTD1AE", pkg: "QFN33" },
	// M030G_31G
	{ name: "M031GGD2AE", pkg: "QFN24" },
	{ name: "M031GGC2AE", pkg: "QFN24" },
	{ name: "M031GGC1AE", pkg: "QFN24" },
	{ name: "M031GTD2AE", pkg: "QFN33" },
	{ name: "M031GTC2AE", pkg: "QFN33" },
	{ name: "M031GTC1AE", pkg: "QFN33" },
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
	{ name: "M032BTAG8AN", pkg: "QFN68" },
	// M031I
	{ name: "M031SIAAE", pkg: "LQFP64" },
	{ name: "M031KIAAE", pkg: "LQFP128" },
	{ name: "M032SIAAE", pkg: "LQFP64" },
	{ name: "M032KIAAE", pkg: "LQFP128" },
	{ name: "M032BTAIAAN", pkg: "QFN68" },
	// M031KM
	{ name: "M030FD2AE", pkg: "TSSOP20" },
	{ name: "M030TD2AE", pkg: "QFN33" },
	{ name: "M030LD2AE", pkg: "LQFP48" },
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

NUTOOL_PIN.g_cfg_pkgs = {
	"QFN24": [
		'PB.0', 'VREF', 'VSS', 'VDD', 'nRESET/ICE_CLK', 'PF.0',
		'PA.3', 'PA.2', 'PA.1', 'PA.0', 'PB.12', 'PB.11',
		'PF.3', 'PF.2', 'VSS', 'PB.8', 'PB.7', 'PB.6',
		'PB.5', 'PB.4', 'PB.3', 'PB.2', 'PC.1', 'PB.1'
	],
	"QFN33": [
		'VREF', 'VDD', 'AVDD', 'nRESET/ICE_CLK', 'PF.0', 'PA.15', 'PA.3', 'PA.2',
		'PA.1', 'PA.0', 'PB.15', 'PB.14', 'PB.13', 'PB.12', 'PB.11', 'PF.3',
		'PF.2', 'PB.10', 'PB.9', 'PB.8', 'PB.7', 'PB.6', 'PB.5', 'PB.4',
		'PB.3', 'PB.2', 'PC.1', 'PB.1', 'PA.14', 'PA.12', 'PA.13', 'PB.0'
	]
};

NUTOOL_PIN.g_cfg_gpios = [
	{ f: ['PA.0:0', 'DAC0_OUT:1', 'SPI0_MOSI:4', 'UART0_RXD:7', 'BPWM1_CH0:12', 'BPWM1_CH4:15']},
	{ f: ['PA.1:0', 'DAC1_OUT:1', 'SPI0_MISO:4', 'UART0_TXD:7', 'BPWM1_CH1:12', 'MANCH_RXD:15']},
	{ f: ['PA.2:0', 'DAC2_OUT:1', 'SPI0_CLK:4', 'I2C0_SMBSUS:7', 'I2C1_SDA:9', 'BPWM1_CH2:12', 'MANCH_TXD:15']},
	{ f: ['PA.3:0', 'DAC3_OUT:1', 'SPI0_SS:4', 'I2C0_SMBAL:7', 'I2C1_SCL:9', 'BPWM1_CH3:12', 'CLKO:14', 'BPWM1_CH5:15']},
	{ f: ['PA.4:0']},
	{ f: ['PA.5:0']},
	{ f: ['PA.6:0']},
	{ f: ['PA.7:0']},
	{ f: ['PA.8:0']},
	{ f: ['PA.9:0']},
	{ f: ['PA.10:0']},
	{ f: ['PA.11:0']},
	{ f: ['PA.12:0', 'I2C1_SCL:4', 'BPWM1_CH2:11', 'TM4:14']},
	{ f: ['PA.13:0', 'I2C1_SDA:4', 'BPWM1_CH3:11', 'TM5:14']},
	{ f: ['PA.14:0', 'UART0_TXD:3', 'I2C1_SCL:4', 'BPWM1_CH4:11', 'TM4_EXT:14']},
	{ f: ['PA.15:0', 'UART0_RXD:3', 'BPWM1_CH5:11', 'TM5_EXT:14']},

	{ f: ['PB.0:0', 'ADC0_CH0:1', 'I2C1_SDA:9']},
	{ f: ['PB.1:0', 'ADC0_CH1:1', 'UART0_RXD:3', 'I2C1_SDA:4', 'I2C1_SCL:9', 'BPWM1_CH4:14']},
	{ f: ['PB.2:0', 'ADC0_CH2:1', 'I2C1_SDA:4', 'TM5:5', 'I2C1_SCL:9', 'BPWM1_CH3:10', 'TM1:12', 'MANCH_RXD:13', 'TM3:14', 'INT3:15']},
	{ f: ['PB.3:0', 'ADC0_CH3:1', 'I2C1_SCL:4', 'BPWM1_CH2:10', 'TM0:12', 'MANCH_TXD:13', 'TM2:14', 'INT2:15']},
	{ f: ['PB.4:0', 'ADC0_CH4:1', 'I2C0_SDA:6', 'TM1:14', 'INT1:15']},
	{ f: ['PB.5:0', 'ADC0_CH5:1', 'I2C0_SCL:6', 'TM0:14', 'INT0:15']},
	{ f: ['PB.6:0', 'ADC0_CH6:1', 'MANCH_RXD:9', 'BPWM1_CH5:10', 'INT4:13']},
	{ f: ['PB.7:0', 'ADC0_CH7:1', 'MANCH_TXD:9', 'BPWM1_CH4:10', 'INT5:13']},
	{ f: ['PB.8:0', 'ADC0_CH8:1', 'UART0_RXD:5', 'BPWM1_CH3:10']},
	{ f: ['PB.9:0', 'ADC0_CH9:1', 'UART0_TXD:5', 'BPWM1_CH2:10']},
	{ f: ['PB.10:0', 'ADC0_CH10:1', 'UART0_nRTS:5', 'I2C1_SDA:7', 'BPWM1_CH1:10']},
	{ f: ['PB.11:0', 'ADC0_CH11:1', 'UART0_nCTS:5', 'UART0_TXD:6', 'I2C1_SCL:7', 'BPWM1_CH0:10', 'EXTCLK_IN:14', 'MANCH_RXD:15']},
	{ f: ['PB.12:0', 'ADC0_CH12:1', 'SPI0_MOSI:4', 'UART0_RXD:6', 'TM5_EXT:10', 'EXTCLK_IN:12', 'TM3_EXT:13', 'TM1_EXT:14', 'MANCH_TXD:15']},
	{ f: ['PB.13:0', 'ADC0_CH13:1', 'SPI0_MISO:4', 'UART0_TXD:6', 'TM4_EXT:10', 'TM2_EXT:13', 'TM0_EXT:14']},
	{ f: ['PB.14:0', 'ADC0_CH14:1', 'SPI0_CLK:4', 'UART0_nRTS:6', 'TM1_EXT:13', 'CLKO:14']},
	{ f: ['PB.15:0', 'ADC0_CH15:1', 'SPI0_SS:4', 'UART0_nCTS:6', 'TM0_EXT:13']},

	{ f: ['PC.0:0']},
	{ f: ['PC.1:0', 'I2C1_SCL:4', 'I2C0_SCL:9', 'ADC0_ST:15']},
	{ f: ['PC.2:0']},
	{ f: ['PC.3:0']},
	{ f: ['PC.4:0']},
	{ f: ['PC.5:0']},
	{ f: ['PC.6:0']},
	{ f: ['PC.7:0']},
	{ f: ['PC.8:0']},
	{ f: ['PC.9:0']},
	{ f: ['PC.10:0']},
	{ f: ['PC.11:0']},
	{ f: ['PC.12:0']},
	{ f: ['PC.13:0']},
	{ f: ['PC.14:0']},
	{ f: ['PC.15:0']},

	{ f: ['PD.0:0']},
	{ f: ['PD.1:0']},
	{ f: ['PD.2:0']},
	{ f: ['PD.3:0']},
	{ f: ['PD.4:0']},
	{ f: ['PD.5:0']},
	{ f: ['PD.6:0']},
	{ f: ['PD.7:0']},
	{ f: ['PD.8:0']},
	{ f: ['PD.9:0']},
	{ f: ['PD.10:0']},
	{ f: ['PD.11:0']},
	{ f: ['PD.12:0']},
	{ f: ['PD.13:0']},
	{ f: ['PD.14:0']},
	{ f: ['PD.15:0']},

	{ f: ['PE.0:0']},
	{ f: ['PE.1:0']},
	{ f: ['PE.2:0']},
	{ f: ['PE.3:0']},
	{ f: ['PE.4:0']},
	{ f: ['PE.5:0']},
	{ f: ['PE.6:0']},
	{ f: ['PE.7:0']},
	{ f: ['PE.8:0']},
	{ f: ['PE.9:0']},
	{ f: ['PE.10:0']},
	{ f: ['PE.11:0']},
	{ f: ['PE.12:0']},
	{ f: ['PE.13:0']},
	{ f: ['PE.14:0']},
	{ f: ['PE.15:0']},

	{ f: ['PF.0:0', 'ICE_DAT:14']},
	{ f: ['PF.1:0']},
	{ f: ['PF.2:0', 'UART0_RXD:3', 'I2C0_SDA:4', 'BPWM1_CH1:11']},
	{ f: ['PF.3:0', 'UART0_TXD:3', 'I2C0_SCL:4', 'EXTCLK_IN:9', 'BPWM1_CH0:11']},
	{ f: ['PF.4:0']},
	{ f: ['PF.5:0']},
	{ f: ['PF.6:0']},
	{ f: ['PF.7:0']},
	{ f: ['PF.8:0']},
	{ f: ['PF.9:0']},
	{ f: ['PF.10:0']},
	{ f: ['PF.11:0']},
	{ f: ['PF.12:0']},
	{ f: ['PF.13:0']},
	{ f: ['PF.14:0']},
	{ f: ['PF.15:0']}
];

NUTOOL_PIN.g_cfg_gpiosDefines = [
	{ f: ['PA.0', 'GPIO:SYS_GPA_MFPL_PA0MFP_GPIO@GPA_MFPL', 'DAC0_OUT:SYS_GPA_MFPL_PA0MFP_DAC0_OUT@GPA_MFPL', 'SPI0_MOSI:SYS_GPA_MFPL_PA0MFP_SPI0_MOSI@GPA_MFPL', 'UART0_RXD:SYS_GPA_MFPL_PA0MFP_UART0_RXD@GPA_MFPL', 'BPWM1_CH0:SYS_GPA_MFPL_PA0MFP_BPWM1_CH0@GPA_MFPL', 'BPWM1_CH4:SYS_GPA_MFPL_PA0MFP_BPWM1_CH4@GPA_MFPL'] },
	{ f: ['PA.1', 'GPIO:SYS_GPA_MFPL_PA1MFP_GPIO@GPA_MFPL', 'DAC1_OUT:SYS_GPA_MFPL_PA1MFP_DAC1_OUT@GPA_MFPL', 'SPI0_MISO:SYS_GPA_MFPL_PA1MFP_SPI0_MISO@GPA_MFPL', 'UART0_TXD:SYS_GPA_MFPL_PA1MFP_UART0_TXD@GPA_MFPL', 'BPWM1_CH1:SYS_GPA_MFPL_PA1MFP_BPWM1_CH1@GPA_MFPL', 'MANCH_RXD:SYS_GPA_MFPL_PA1MFP_MANCH_RXD@GPA_MFPL'] },
	{ f: ['PA.2', 'GPIO:SYS_GPA_MFPL_PA2MFP_GPIO@GPA_MFPL', 'DAC2_OUT:SYS_GPA_MFPL_PA2MFP_DAC2_OUT@GPA_MFPL', 'SPI0_CLK:SYS_GPA_MFPL_PA2MFP_SPI0_CLK@GPA_MFPL', 'I2C0_SMBSUS:SYS_GPA_MFPL_PA2MFP_I2C0_SMBSUS@GPA_MFPL', 'I2C1_SDA:SYS_GPA_MFPL_PA2MFP_I2C1_SDA@GPA_MFPL', 'BPWM1_CH2:SYS_GPA_MFPL_PA2MFP_BPWM1_CH2@GPA_MFPL', 'MANCH_TXD:SYS_GPA_MFPL_PA2MFP_MANCH_TXD@GPA_MFPL'] },
	{ f: ['PA.3', 'GPIO:SYS_GPA_MFPL_PA3MFP_GPIO@GPA_MFPL', 'DAC3_OUT:SYS_GPA_MFPL_PA3MFP_DAC3_OUT@GPA_MFPL', 'SPI0_SS:SYS_GPA_MFPL_PA3MFP_SPI0_SS@GPA_MFPL', 'I2C0_SMBAL:SYS_GPA_MFPL_PA3MFP_I2C0_SMBAL@GPA_MFPL', 'I2C1_SCL:SYS_GPA_MFPL_PA3MFP_I2C1_SCL@GPA_MFPL', 'BPWM1_CH3:SYS_GPA_MFPL_PA3MFP_BPWM1_CH3@GPA_MFPL', 'CLKO:SYS_GPA_MFPL_PA3MFP_CLKO@GPA_MFPL', 'BPWM1_CH5:SYS_GPA_MFPL_PA3MFP_BPWM1_CH5@GPA_MFPL'] },
	{ f: ['PA.12', 'GPIO:SYS_GPA_MFPH_PA12MFP_GPIO@GPA_MFPH', 'I2C1_SCL:SYS_GPA_MFPH_PA12MFP_I2C1_SCL@GPA_MFPH', 'BPWM1_CH2:SYS_GPA_MFPH_PA12MFP_BPWM1_CH2@GPA_MFPH', 'TM4:SYS_GPA_MFPH_PA12MFP_TM4@GPA_MFPH'] },
	{ f: ['PA.13', 'GPIO:SYS_GPA_MFPH_PA13MFP_GPIO@GPA_MFPH', 'I2C1_SDA:SYS_GPA_MFPH_PA13MFP_I2C1_SDA@GPA_MFPH', 'BPWM1_CH3:SYS_GPA_MFPH_PA13MFP_BPWM1_CH3@GPA_MFPH', 'TM5:SYS_GPA_MFPH_PA13MFP_TM5@GPA_MFPH'] },
	{ f: ['PA.14', 'GPIO:SYS_GPA_MFPH_PA14MFP_GPIO@GPA_MFPH', 'UART0_TXD:SYS_GPA_MFPH_PA14MFP_UART0_TXD@GPA_MFPH', 'I2C1_SCL:SYS_GPA_MFPH_PA14MFP_I2C1_SCL@GPA_MFPH', 'BPWM1_CH4:SYS_GPA_MFPH_PA14MFP_BPWM1_CH4@GPA_MFPH', 'TM4_EXT:SYS_GPA_MFPH_PA14MFP_TM4_EXT@GPA_MFPH'] },
	{ f: ['PA.15', 'GPIO:SYS_GPA_MFPH_PA15MFP_GPIO@GPA_MFPH', 'UART0_RXD:SYS_GPA_MFPH_PA15MFP_UART0_RXD@GPA_MFPH', 'BPWM1_CH5:SYS_GPA_MFPH_PA15MFP_BPWM1_CH5@GPA_MFPH', 'TM5_EXT:SYS_GPA_MFPH_PA15MFP_TM5_EXT@GPA_MFPH'] },

	{ f: ['PB.0', 'GPIO:SYS_GPB_MFPL_PB0MFP_GPIO@GPB_MFPL', 'ADC0_CH0:SYS_GPB_MFPL_PB0MFP_ADC0_CH0@GPB_MFPL', 'I2C1_SDA:SYS_GPB_MFPL_PB0MFP_I2C1_SDA@GPB_MFPL'] },
	{ f: ['PB.1', 'GPIO:SYS_GPB_MFPL_PB1MFP_GPIO@GPB_MFPL', 'ADC0_CH1:SYS_GPB_MFPL_PB1MFP_ADC0_CH1@GPB_MFPL', 'UART0_RXD:SYS_GPB_MFPL_PB1MFP_UART0_RXD@GPB_MFPL', 'I2C1_SDA:SYS_GPB_MFPL_PB1MFP_I2C1_SDA@GPB_MFPL', 'I2C1_SCL:SYS_GPB_MFPL_PB1MFP_I2C1_SCL@GPB_MFPL', 'BPWM1_CH4:SYS_GPB_MFPL_PB1MFP_BPWM1_CH4@GPB_MFPL'] },
	{ f: ['PB.2', 'GPIO:SYS_GPB_MFPL_PB2MFP_GPIO@GPB_MFPL', 'ADC0_CH2:SYS_GPB_MFPL_PB2MFP_ADC0_CH2@GPB_MFPL', 'I2C1_SDA:SYS_GPB_MFPL_PB2MFP_I2C1_SDA@GPB_MFPL', 'TM5:SYS_GPB_MFPL_PB2MFP_TM5@GPB_MFPL', 'I2C1_SCL:SYS_GPB_MFPL_PB2MFP_I2C1_SCL@GPB_MFPL', 'BPWM1_CH3:SYS_GPB_MFPL_PB2MFP_BPWM1_CH3@GPB_MFPL', 'TM1:SYS_GPB_MFPL_PB2MFP_TM1@GPB_MFPL', 'MANCH_RXD:SYS_GPB_MFPL_PB2MFP_MANCH_RXD@GPB_MFPL', 'TM3:SYS_GPB_MFPL_PB2MFP_TM3@GPB_MFPL', 'INT3:SYS_GPB_MFPL_PB2MFP_INT3@GPB_MFPL'] },
	{ f: ['PB.3', 'GPIO:SYS_GPB_MFPL_PB3MFP_GPIO@GPB_MFPL', 'ADC0_CH3:SYS_GPB_MFPL_PB3MFP_ADC0_CH3@GPB_MFPL', 'I2C1_SCL:SYS_GPB_MFPL_PB3MFP_I2C1_SCL@GPB_MFPL', 'TM4:SYS_GPB_MFPL_PB3MFP_TM4@GPB_MFPL', 'BPWM1_CH2:SYS_GPB_MFPL_PB3MFP_BPWM1_CH2@GPB_MFPL', 'TM0:SYS_GPB_MFPL_PB3MFP_TM0@GPB_MFPL', 'MANCH_TXD:SYS_GPB_MFPL_PB3MFP_MANCH_TXD@GPB_MFPL', 'TM2:SYS_GPB_MFPL_PB3MFP_TM2@GPB_MFPL', 'INT2:SYS_GPB_MFPL_PB3MFP_INT2@GPB_MFPL'] },
	{ f: ['PB.4', 'GPIO:SYS_GPB_MFPL_PB4MFP_GPIO@GPB_MFPL', 'ADC0_CH4:SYS_GPB_MFPL_PB4MFP_ADC0_CH4@GPB_MFPL', 'I2C0_SDA:SYS_GPB_MFPL_PB4MFP_I2C0_SDA@GPB_MFPL', 'TM1:SYS_GPB_MFPL_PB4MFP_TM1@GPB_MFPL', 'INT1:SYS_GPB_MFPL_PB4MFP_INT1@GPB_MFPL'] },
	{ f: ['PB.5', 'GPIO:SYS_GPB_MFPL_PB5MFP_GPIO@GPB_MFPL', 'ADC0_CH5:SYS_GPB_MFPL_PB5MFP_ADC0_CH5@GPB_MFPL', 'I2C0_SCL:SYS_GPB_MFPL_PB5MFP_I2C0_SCL@GPB_MFPL', 'TM0:SYS_GPB_MFPL_PB5MFP_TM0@GPB_MFPL', 'INT0:SYS_GPB_MFPL_PB5MFP_INT0@GPB_MFPL'] },
	{ f: ['PB.6', 'GPIO:SYS_GPB_MFPL_PB6MFP_GPIO@GPB_MFPL', 'ADC0_CH6:SYS_GPB_MFPL_PB6MFP_ADC0_CH6@GPB_MFPL', 'MANCH_RXD:SYS_GPB_MFPL_PB6MFP_MANCH_RXD@GPB_MFPL', 'BPWM1_CH5:SYS_GPB_MFPL_PB6MFP_BPWM1_CH5@GPB_MFPL', 'INT4:SYS_GPB_MFPL_PB6MFP_INT4@GPB_MFPL'] },
	{ f: ['PB.7', 'GPIO:SYS_GPB_MFPL_PB7MFP_GPIO@GPB_MFPL', 'ADC0_CH7:SYS_GPB_MFPL_PB7MFP_ADC0_CH7@GPB_MFPL', 'MANCH_TXD:SYS_GPB_MFPL_PB7MFP_MANCH_TXD@GPB_MFPL', 'BPWM1_CH4:SYS_GPB_MFPL_PB7MFP_BPWM1_CH4@GPB_MFPL', 'INT5:SYS_GPB_MFPL_PB7MFP_INT5@GPB_MFPL'] },
	{ f: ['PB.8', 'GPIO:SYS_GPB_MFPH_PB8MFP_GPIO@GPB_MFPH', 'ADC0_CH8:SYS_GPB_MFPH_PB8MFP_ADC0_CH8@GPB_MFPH', 'UART0_RXD:SYS_GPB_MFPH_PB8MFP_UART0_RXD@GPB_MFPH', 'BPWM1_CH3:SYS_GPB_MFPH_PB8MFP_BPWM1_CH3@GPB_MFPH'] },
	{ f: ['PB.9', 'GPIO:SYS_GPB_MFPH_PB9MFP_GPIO@GPB_MFPH', 'ADC0_CH9:SYS_GPB_MFPH_PB9MFP_ADC0_CH9@GPB_MFPH', 'UART0_TXD:SYS_GPB_MFPH_PB9MFP_UART0_TXD@GPB_MFPH', 'BPWM1_CH2:SYS_GPB_MFPH_PB9MFP_BPWM1_CH2@GPB_MFPH'] },
	{ f: ['PB.10', 'GPIO:SYS_GPB_MFPH_PB10MFP_GPIO@GPB_MFPH', 'ADC0_CH10:SYS_GPB_MFPH_PB10MFP_ADC0_CH10@GPB_MFPH', 'UART0_nRTS:SYS_GPB_MFPH_PB10MFP_UART0_nRTS@GPB_MFPH', 'I2C1_SDA:SYS_GPB_MFPH_PB10MFP_I2C1_SDA@GPB_MFPH', 'BPWM1_CH1:SYS_GPB_MFPH_PB10MFP_BPWM1_CH1@GPB_MFPH'] },
	{ f: ['PB.11', 'GPIO:SYS_GPB_MFPH_PB11MFP_GPIO@GPB_MFPH', 'ADC0_CH11:SYS_GPB_MFPH_PB11MFP_ADC0_CH11@GPB_MFPH', 'UART0_nCTS:SYS_GPB_MFPH_PB11MFP_UART0_nCTS@GPB_MFPH', 'UART0_TXD:SYS_GPB_MFPH_PB11MFP_UART0_TXD@GPB_MFPH', 'I2C1_SCL:SYS_GPB_MFPH_PB11MFP_I2C1_SCL@GPB_MFPH', 'BPWM1_CH0:SYS_GPB_MFPH_PB11MFP_BPWM1_CH0@GPB_MFPH', 'EXTCLK_IN:SYS_GPB_MFPH_PB11MFP_EXTCLK_IN@GPB_MFPH', 'MANCH_RXD:SYS_GPB_MFPH_PB11MFP_MANCH_RXD@GPB_MFPH'] },
	{ f: ['PB.12', 'GPIO:SYS_GPB_MFPH_PB12MFP_GPIO@GPB_MFPH', 'ADC0_CH12:SYS_GPB_MFPH_PB12MFP_ADC0_CH12@GPB_MFPH', 'SPI0_MOSI:SYS_GPB_MFPH_PB12MFP_SPI0_MOSI@GPB_MFPH', 'UART0_RXD:SYS_GPB_MFPH_PB12MFP_UART0_RXD@GPB_MFPH', 'EXTCLK_IN:SYS_GPB_MFPH_PB12MFP_EXTCLK_IN@GPB_MFPH', 'TM5_EXT:SYS_GPB_MFPH_PB12MFP_TM5_EXT@GPB_MFPH', 'BPWM1_CH2:SYS_GPB_MFPH_PB12MFP_BPWM1_CH2@GPB_MFPH', 'TM3_EXT:SYS_GPB_MFPH_PB12MFP_TM3_EXT@GPB_MFPH', 'TM1_EXT:SYS_GPB_MFPH_PB12MFP_TM1_EXT@GPB_MFPH', 'MANCH_TXD:SYS_GPB_MFPH_PB12MFP_MANCH_TXD@GPB_MFPH'] },
	{ f: ['PB.13', 'GPIO:SYS_GPB_MFPH_PB13MFP_GPIO@GPB_MFPH', 'ADC0_CH13:SYS_GPB_MFPH_PB13MFP_ADC0_CH13@GPB_MFPH', 'SPI0_MISO:SYS_GPB_MFPH_PB13MFP_SPI0_MISO@GPB_MFPH', 'UART0_TXD:SYS_GPB_MFPH_PB13MFP_UART0_TXD@GPB_MFPH', 'TM4_EXT:SYS_GPB_MFPH_PB13MFP_TM4_EXT@GPB_MFPH', 'TM2_EXT:SYS_GPB_MFPH_PB13MFP_TM2_EXT@GPB_MFPH', 'TM0_EXT:SYS_GPB_MFPH_PB13MFP_TM0_EXT@GPB_MFPH'] },
	{ f: ['PB.14', 'GPIO:SYS_GPB_MFPH_PB14MFP_GPIO@GPB_MFPH', 'ADC0_CH14:SYS_GPB_MFPH_PB14MFP_ADC0_CH14@GPB_MFPH', 'SPI0_CLK:SYS_GPB_MFPH_PB14MFP_SPI0_CLK@GPB_MFPH', 'UART0_nRTS:SYS_GPB_MFPH_PB14MFP_UART0_nRTS@GPB_MFPH', 'TM1_EXT:SYS_GPB_MFPH_PB14MFP_TM1_EXT@GPB_MFPH', 'CLKO:SYS_GPB_MFPH_PB14MFP_CLKO@GPB_MFPH'] },
	{ f: ['PB.15', 'GPIO:SYS_GPB_MFPH_PB15MFP_GPIO@GPB_MFPH', 'ADC0_CH15:SYS_GPB_MFPH_PB15MFP_ADC0_CH15@GPB_MFPH', 'SPI0_SS:SYS_GPB_MFPH_PB15MFP_SPI0_SS@GPB_MFPH', 'UART0_nCTS:SYS_GPB_MFPH_PB15MFP_UART0_nCTS@GPB_MFPH', 'TM0_EXT:SYS_GPB_MFPH_PB15MFP_TM0_EXT@GPB_MFPH'] },

	{ f: ['PC.1', 'GPIO:SYS_GPC_MFPL_PC1MFP_GPIO@GPC_MFPL', 'I2C1_SCL:SYS_GPC_MFPL_PC1MFP_I2C1_SCL@GPC_MFPL', 'I2C0_SCL:SYS_GPC_MFPL_PC1MFP_I2C0_SCL@GPC_MFPL', 'ADC0_ST:SYS_GPC_MFPL_PC1MFP_ADC0_ST@GPC_MFPL'] },

	{ f: ['PF.0', 'GPIO:SYS_GPF_MFPL_PF0MFP_GPIO@GPF_MFPL', 'ICE_DAT:SYS_GPF_MFPL_PF0MFP_ICE_DAT@GPF_MFPL'] },
	{ f: ['PF.2', 'GPIO:SYS_GPF_MFPL_PF2MFP_GPIO@GPF_MFPL', 'UART0_RXD:SYS_GPF_MFPL_PF2MFP_UART0_RXD@GPF_MFPL', 'I2C0_SDA:SYS_GPF_MFPL_PF2MFP_I2C0_SDA@GPF_MFPL', 'BPWM1_CH1:SYS_GPF_MFPL_PF2MFP_BPWM1_CH1@GPF_MFPL'] },
	{ f: ['PF.3', 'GPIO:SYS_GPF_MFPL_PF3MFP_GPIO@GPF_MFPL', 'UART0_TXD:SYS_GPF_MFPL_PF3MFP_UART0_TXD@GPF_MFPL', 'I2C0_SCL:SYS_GPF_MFPL_PF3MFP_I2C0_SCL@GPF_MFPL', 'EXTCLK_IN:SYS_GPF_MFPL_PF3MFP_EXTCLK_IN@GPF_MFPL', 'BPWM1_CH0:SYS_GPF_MFPL_PF3MFP_BPWM1_CH0@GPF_MFPL'] }
];

NUTOOL_PIN.g_cfg_gpiosDescriptions = [
	'ADC0_CH0:ADC0 channel 0 analog input',
	'ADC0_CH1:ADC0 channel 1 analog input',
	'ADC0_CH2:ADC0 channel 2 analog input',
	'ADC0_CH3:ADC0 channel 3 analog input',
	'ADC0_CH4:ADC0 channel 4 analog input',
	'ADC0_CH5:ADC0 channel 5 analog input',
	'ADC0_CH6:ADC0 channel 6 analog input',
	'ADC0_CH7:ADC0 channel 7 analog input',
	'ADC0_CH8:ADC0 channel 8 analog input',
	'ADC0_CH9:ADC0 channel 9 analog input',
	'ADC0_CH10:ADC0 channel 10 analog input',
	'ADC0_CH11:ADC0 channel 11 analog input',
	'ADC0_CH12:ADC0 channel 12 analog input',
	'ADC0_CH13:ADC0 channel 13 analog input',
	'ADC0_CH14:ADC0 channel 14 analog input',
	'ADC0_CH15:ADC0 channel 15 analog input',
	'ADC0_ST:ADC0 external trigger input pin',
	'BPWM1_CH0:BPWM1 channel 0 output/capture input',
	'BPWM1_CH1:BPWM1 channel 1 output/capture input',
	'BPWM1_CH2:BPWM1 channel 2 output/capture input',
	'BPWM1_CH3:BPWM1 channel 3 output/capture input',
	'BPWM1_CH4:BPWM1 channel 4 output/capture input',
	'BPWM1_CH5:BPWM1 channel 5 output/capture input',
	'CLKO:Clock Out',
	'DAC0_OUT:DAC0 channel analog output',
	'DAC1_OUT:DAC1 channel analog output',
	'DAC2_OUT:DAC2 channel analog output',
	'DAC3_OUT:DAC3 channel analog output',
	'EXTCLK_IN:External Clock pin for PLLFin source',
	'I2C0_SCL:I2C0 clock pin',
	'I2C0_SDA:I2C0 data input/output pin',
	'I2C0_SMBAL:I2C0 SMBus SMBALTER pin ',
	'I2C0_SMBSUS:I2C0 SMBus SMBSUS pin (PMBus CONTROL pin)',
	'I2C1_SCL:I2C1 clock pin',
	'I2C1_SDA:I2C1 data input/output pin',
	'ICE_DAT:Serial wired debugger data pin',
	'INT0:External interrupt 0 input pin',
	'INT1:External interrupt 1 input pin',
	'INT2:External interrupt 2 input pin',
	'INT3:External interrupt 3 input pin',
	'INT4:External interrupt 4 input pin',
	'INT5:External interrupt 5 input pin',
	'MANCH_RXD:Manchester data receiver input pin',
	'MANCH_TXD:Manchester data transmitter output pin',
	'SPI0_CLK:SPI0 serial clock pin',
	'SPI0_MISO:SPI0 MISO (Master In, Slave Out) pin',
	'SPI0_MOSI:SPI0 MOSI (Master Out, Slave In) pin',
	'SPI0_SS:SPI0 slave select pin',
	'TM0:Timer0 event counter input/toggle output pin',
	'TM0_EXT:Timer0 external capture input/toggle output pin',
	'TM1:Timer1 event counter input/toggle output pin',
	'TM1_EXT:Timer1 external capture input/toggle output pin',
	'TM2:Timer2 event counter input/toggle output pin',
	'TM2_EXT:Timer2 external capture input/toggle output pin',
	'TM3:Timer3 event counter input/toggle output pin',
	'TM3_EXT:Timer3 external capture input/toggle output pin',
	'TM4:Timer4 event counter input/toggle output pin',
	'TM4_EXT:Timer4 external capture input/toggle output pin',
	'TM5:Timer5 event counter input/toggle output pin',
	'TM5_EXT:Timer5 external capture input/toggle output pin',
	'UART0_nCTS:UART0 clear to Send input pin',
	'UART0_nRTS:UART0 request to Send output pin',
	'UART0_RXD:UART0 data receiver input pin',
	'UART0_TXD:UART0 data transmitter output pin'
];

NUTOOL_PIN.g_cfg_regDescriptions = {};
NUTOOL_PIN.g_cfg_regDescriptions.GPA_MFPL = '0x40000030';
NUTOOL_PIN.g_cfg_regDescriptions.GPA_MFPH = '0x40000034';
NUTOOL_PIN.g_cfg_regDescriptions.GPB_MFPL = '0x40000038';
NUTOOL_PIN.g_cfg_regDescriptions.GPB_MFPH = '0x4000003C';
NUTOOL_PIN.g_cfg_regDescriptions.GPC_MFPL = '0x40000040';
NUTOOL_PIN.g_cfg_regDescriptions.GPF_MFPL = '0x40000058';
NUTOOL_PIN.g_cfg_regDescriptions.GPF_MFPH = '0x4000005C';

NUTOOL_PIN.g_cfg_gpioMatrix = [];
NUTOOL_PIN.g_cfg_shareBits = [];
NUTOOL_PIN.g_cfg_addGPIO = {};
NUTOOL_PIN.g_cfg_unusedGPIO = {
	"M031GGD2AE(QFN24)": {
		"ALL": ["ACMP0", "ACMP1", "EBI", "PWM0", "PWM1", "BPWM0", "UART1", "UART2", "UART3", "UART4", "UART5", "UART6", "UART7", "USCI0", "USCI1", "X32", "XT1", "USB", "RTC", "QSPI"]
	},
	"M031GGC2AE(QFN24)": function () {
		return this["M031GGD2AE(QFN24)"];
	},
	"M031GGC1AE(QFN24)": function () {
		return this["M031GGD2AE(QFN24)"];
	},
	"M031GTD2AE(QFN33)": function () {
		return this["M031GGD2AE(QFN24)"];
	},
	"M031GTC2AE(QFN33)": function () {
		return this["M031GGD2AE(QFN24)"];
	},
	"M031GTC1AE(QFN33)": function () {
		return this["M031GGD2AE(QFN24)"];
	}
};

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
