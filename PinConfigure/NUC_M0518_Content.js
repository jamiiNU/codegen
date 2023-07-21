NUTOOL_PIN.g_cfg_chips = [
//M0518
	{ name: "M0518LD2AE", pkg: "LQFP48" },
	{ name: "M0518LC2AE", pkg: "LQFP48" },
	{ name: "M0518SD2AE", pkg: "LQFP64" },
	{ name: "M0518SC2AE", pkg: "LQFP64" }
];

NUTOOL_PIN.g_cfg_pkgs = {
	"LQFP64": [
		'PB.14', 'PB.13', 'PB.12', 'PF.5', 'PF.4', 'PA.11', 'PA.10', 'PA.9', 'PA.8', 'PB.4',
		'PB.5', 'PB.6', 'PB.7', 'LDO_CAP', 'VDD', 'VSS',
		'PB.0', 'PB.1', 'PB.2', 'PB.3', 'PD.6', 'PD.7', 'PD.14', 'PD.15', 'PC.3', 'PC.2',
		'PC.1', 'PC.0', 'PE.5', 'PB.11', 'PB.10', 'PB.9',
		'PC.11', 'PC.10', 'PC.9', 'PC.8', 'PA.15', 'PA.14', 'PA.13', 'PA.12', 'PF.7', 'PF.6',
		'AVSS', 'PA.0', 'PA.1', 'PA.2', 'PA.3', 'PA.4',
		'PA.5', 'PA.6', 'PA.7', 'AVDD', 'PC.7', 'PC.6', 'PC.15', 'PC.14', 'PB.15', 'XT1_OUT/PF.0',
		'XT1_IN/PF.1', 'nRESET', 'VSS', 'VDD', 'PF.8', 'PB.8'
	],
	"LQFP48": [
		'PB.12', 'PF.5', 'PF.4', 'PA.11', 'PA.10', 'PA.9', 'PA.8', 'PB.4', 'PB.5', 'LDO_CAP',
		'VDD', 'VSS',
		'PB.0', 'PB.1', 'PB.2', 'PB.3', 'PD.6', 'PD.7', 'PD.14', 'PD.15', 'PC.3', 'PC.2',
		'PC.1', 'PC.0',
		'PA.15', 'PA.14', 'PA.13', 'PA.12', 'PF.7', 'PF.6', 'AVSS', 'PA.0', 'PA.1', 'PA.2',
		'PA.3', 'PA.4',
		'PA.5', 'PA.6', 'PA.7', 'AVDD', 'PC.7', 'PC.6', 'PB.15', 'XT1_OUT/PF.0', 'XT1_IN/PF.1', 'nRESET',
		'PF.8', 'PB.8'
	]
};

NUTOOL_PIN.g_cfg_OrCAD = {};

NUTOOL_PIN.g_cfg_gpios = [
	{ f: ['PA.0:0', 'ADC_CH0:1', 'I2C1_SCL:3', 'UART5_TXD:5', 'PWM0_CH4:9'] },
	{ f: ['PA.1:0', 'ADC_CH1:1', 'I2C1_SDA:3', 'UART5_RXD:5', 'PWM0_CH5:9'] },
	{ f: ['PA.2:0', 'ADC_CH2:1', 'UART3_TXD:3', 'PWM1_CH0:5'] },
	{ f: ['PA.3:0', 'ADC_CH3:1', 'UART3_RXD:3', 'PWM1_CH1:5'] },
	{ f: ['PA.4:0', 'ADC_CH4:1'] },
	{ f: ['PA.5:0', 'ADC_CH5:1', 'UART3_RXD:3'] },
	{ f: ['PA.6:0', 'ADC_CH6:1', 'UART3_TXD:3'] },
	{ f: ['PA.7:0', 'ADC_CH7:1', 'VREF:3'] },
	{ f: ['PA.8:0', 'I2C0_SDA:1', 'UART1_nRTS:3'] },
	{ f: ['PA.9:0', 'I2C0_SCL:1', 'UART1_nCTS:3'] },
	{ f: ['PA.10:0', 'I2C1_SDA:1', 'PWM1_CH2:3'] },
	{ f: ['PA.11:0', 'I2C1_SCL:1', 'PWM1_CH3:3'] },
	{ f: ['PA.12:0', 'PWM0_CH0:1', 'UART5_RXD:3'] },
	{ f: ['PA.13:0', 'PWM0_CH1:1', 'UART5_TXD:3'] },
	{ f: ['PA.14:0', 'PWM0_CH2:1'] },
	{ f: ['PA.15:0', 'PWM0_CH3:1'] },

	{ f: ['PB.0:0', 'UART0_RXD:1'] },
	{ f: ['PB.1:0', 'UART0_TXD:1'] },
	{ f: ['PB.2:0', 'UART0_nRTS:1', 'TM2_EXT:3', 'PWM1_BRAKE1:5', 'TM2:9'] },
	{ f: ['PB.3:0', 'UART0_nCTS:1', 'TM3_EXT:3', 'PWM1_BRAKE0:5', 'TM3:9'] },
	{ f: ['PB.4:0', 'UART1_RXD:1'] },
	{ f: ['PB.5:0', 'UART1_TXD:1'] },
	{ f: ['PB.6:0', 'UART1_nRTS:1'] },
	{ f: ['PB.7:0', 'UART1_nCTS:1'] },
	{ f: ['PB.8:0', 'TM0:1', 'STADC:2', 'CLKO:3', 'BPWM1_CH2:5'] },
	{ f: ['PB.9:0', 'TM1:1'] },
	{ f: ['PB.10:0', 'TM2:1'] },
	{ f: ['PB.11:0', 'TM3:1', 'PWM0_CH4:3'] },
	{ f: ['PB.12:0', 'CLKO:1', 'BPWM1_CH3:3'] },
	{ f: ['PB.13:0'] },
	{ f: ['PB.14:0', 'INT0:1'] },
	{ f: ['PB.15:0', 'INT1:1', 'TM0:3', 'TM0_EXT:5', 'BPWM1_CH5:11'] },

	{ f: ['PC.0:0', 'SPI0_SS0:1', 'BPWM0_CH0:3'] },
	{ f: ['PC.1:0', 'SPI0_CLK:1', 'BPWM0_CH1:3'] },
	{ f: ['PC.2:0', 'SPI0_MISO0:1', 'BPWM0_CH2:3'] },
	{ f: ['PC.3:0', 'SPI0_MOSI0:1', 'BPWM0_CH3:3'] },
	{ f: ['PC.4:0'] },
	{ f: ['PC.5:0'] },
	{ f: ['PC.6:0', 'UART4_TXD:1', 'I2C0_SDA:3', 'PWM0_BRAKE0:5'] },
	{ f: ['PC.7:0', 'UART4_RXD:1', 'I2C0_SCL:3', 'PWM0_BRAKE1:5'] },
	{ f: ['PC.8:0', 'PWM0_BRAKE0:1'] },
	{ f: ['PC.9:0', 'PWM0_BRAKE1:1'] },
	{ f: ['PC.10:0', 'PWM1_BRAKE0:1'] },
	{ f: ['PC.11:0', 'PWM1_BRAKE1:1'] },
	{ f: ['PC.12:0'] },
	{ f: ['PC.13:0'] },
	{ f: ['PC.14:0'] },
	{ f: ['PC.15:0'] },

	{ f: ['PD.0:0'] },
	{ f: ['PD.1:0'] },
	{ f: ['PD.2:0'] },
	{ f: ['PD.3:0'] },
	{ f: ['PD.4:0'] },
	{ f: ['PD.5:0'] },
	{ f: ['PD.6:0', 'BPWM1_CH1:3'] },
	{ f: ['PD.7:0', 'BPWM1_CH0:3'] },
	{ f: ['PD.8:0'] },
	{ f: ['PD.9:0'] },
	{ f: ['PD.10:0'] },
	{ f: ['PD.11:0'] },
	{ f: ['PD.12:0'] },
	{ f: ['PD.13:0'] },
	{ f: ['PD.14:0', 'UART2_RXD:1', 'BPWM0_CH5:3'] },
	{ f: ['PD.15:0', 'UART2_TXD:1', 'BPWM0_CH4:3'] },

	{ f: ['PE.0:0'] },
	{ f: ['PE.1:0'] },
	{ f: ['PE.2:0'] },
	{ f: ['PE.3:0'] },
	{ f: ['PE.4:0'] },
	{ f: ['PE.5:0', 'PWM0_CH5:1', 'TM1:3', 'TM1_EXT:5'] },
	{ f: ['PE.6:0'] },
	{ f: ['PE.7:0'] },
	{ f: ['PE.8:0'] },
	{ f: ['PE.9:0'] },
	{ f: ['PE.10:0'] },
	{ f: ['PE.11:0'] },
	{ f: ['PE.12:0'] },
	{ f: ['PE.13:0'] },
	{ f: ['PE.14:0'] },
	{ f: ['PE.15:0'] },

	{ f: ['PF.0:0'] },
	{ f: ['PF.1:0'] },
	{ f: ['PF.2:0'] },
	{ f: ['PF.3:0'] },
	{ f: ['PF.4:0', 'I2C0_SDA:1', 'PWM1_CH4:3'] },
	{ f: ['PF.5:0', 'I2C0_SCL:1', 'PWM1_CH5:3'] },
	{ f: ['PF.6:0', 'ICE_CLK:1'] },
	{ f: ['PF.7:0', 'ICE_DAT:1'] },
	{ f: ['PF.8:0', 'CLKO:1', 'BPWM1_CH4:2'] }
];

NUTOOL_PIN.g_cfg_gpiosDefines = [
	{ f: ['PA.0', 'ADC_CH0:SYS_GPA_MFP_PA0_ADC0@GPA_MFP', 'I2C1_SCL:SYS_GPA_MFP_PA0_I2C1_SCL@GPA_MFP/SYS_ALT_MFP4_PA0_I2C1_SCL@ALT_MFP4', 'UART5_TXD:SYS_GPA_MFP_PA0_UART5_TXD@GPA_MFP/SYS_ALT_MFP4_PA0_UART5_TXD@ALT_MFP4', 'PWM0_CH4:SYS_GPA_MFP_PA0_PWM0_CH4@GPA_MFP/SYS_ALT_MFP3_PA0_PWM0_CH4@ALT_MFP3'] },
	{ f: ['PA.1', 'ADC_CH1:SYS_GPA_MFP_PA1_ADC1@GPA_MFP', 'I2C1_SDA:SYS_GPA_MFP_PA1_I2C1_SDA@GPA_MFP/SYS_ALT_MFP4_PA1_I2C1_SDA@ALT_MFP4', 'UART5_RXD:SYS_GPA_MFP_PA1_UART5_RXD@GPA_MFP/SYS_ALT_MFP4_PA1_UART5_RXD@ALT_MFP4', 'PWM0_CH5:SYS_GPA_MFP_PA1_PWM0_CH5@GPA_MFP/SYS_ALT_MFP3_PA1_PWM0_CH5@ALT_MFP3'] },
	{ f: ['PA.2', 'ADC_CH2:SYS_GPA_MFP_PA2_ADC2@GPA_MFP', 'UART3_TXD:SYS_GPA_MFP_PA2_UART3_TXD@GPA_MFP/SYS_ALT_MFP4_PA2_UART3_TXD@ALT_MFP4', 'PWM1_CH0:SYS_GPA_MFP_PA2_PWM1_CH0@GPA_MFP/SYS_ALT_MFP3_PA2_PWM1_CH0@ALT_MFP3'] },
	{ f: ['PA.3', 'ADC_CH3:SYS_GPA_MFP_PA3_ADC3@GPA_MFP', 'UART3_RXD:SYS_GPA_MFP_PA3_UART3_RXD@GPA_MFP/SYS_ALT_MFP4_PA3_UART3_RXD@ALT_MFP4', 'PWM1_CH1:SYS_GPA_MFP_PA3_PWM1_CH1@GPA_MFP/SYS_ALT_MFP3_PA3_PWM1_CH1@ALT_MFP3'] },
	{ f: ['PA.4', 'ADC_CH4:SYS_GPA_MFP_PA4_ADC4@GPA_MFP'] },
	{ f: ['PA.5', 'ADC_CH5:SYS_GPA_MFP_PA5_ADC5@GPA_MFP', 'UART3_RXD:SYS_GPA_MFP_PA5_UART3_RXD@GPA_MFP/SYS_ALT_MFP4_PA5_UART3_RXD@ALT_MFP4'] },
	{ f: ['PA.6', 'ADC_CH6:SYS_GPA_MFP_PA6_ADC6@GPA_MFP', 'UART3_TXD:SYS_GPA_MFP_PA6_UART3_TXD@GPA_MFP/SYS_ALT_MFP4_PA6_UART3_TXD@ALT_MFP4'] },
	{ f: ['PA.7', 'ADC_CH7:SYS_GPA_MFP_PA7_ADC7@GPA_MFP', 'VREF:SYS_GPA_MFP_PA7_Vref@GPA_MFP/SYS_ALT_MFP4_PA7_Vref@ALT_MFP4'] },
	{ f: ['PA.8', 'I2C0_SDA:SYS_GPA_MFP_PA8_I2C0_SDA@GPA_MFP', 'UART1_nRTS:SYS_GPA_MFP_PA8_UART1_nRTS@GPA_MFP/SYS_ALT_MFP4_PA8_UART1_nRTS@ALT_MFP4'] },
	{ f: ['PA.9', 'I2C0_SCL:SYS_GPA_MFP_PA9_I2C0_SCL@GPA_MFP', 'UART1_nCTS:SYS_GPA_MFP_PA9_UART1_nCTS@GPA_MFP/SYS_ALT_MFP4_PA9_UART1_nCTS@ALT_MFP4'] },
	{ f: ['PA.10', 'I2C1_SDA:SYS_GPA_MFP_PA10_I2C1_SDA@GPA_MFP', 'PWM1_CH2:SYS_GPA_MFP_PA10_PWM1_CH2@GPA_MFP/SYS_ALT_MFP3_PA10_PWM1_CH2@ALT_MFP3'] },
	{ f: ['PA.11', 'I2C1_SCL:SYS_GPA_MFP_PA11_I2C1_SCL@GPA_MFP', 'PWM1_CH3:SYS_GPA_MFP_PA11_PWM1_CH3@GPA_MFP/SYS_ALT_MFP3_PA11_PWM1_CH3@ALT_MFP3'] },
	{ f: ['PA.12', 'PWM0_CH0:SYS_GPA_MFP_PA12_PWM0_CH0@GPA_MFP', 'UART5_RXD:SYS_GPA_MFP_PA12_UART5_RXD@GPA_MFP/SYS_ALT_MFP4_PA12_UART5_RXD@ALT_MFP4'] },
	{ f: ['PA.13', 'PWM0_CH1:SYS_GPA_MFP_PA13_PWM0_CH1@GPA_MFP', 'UART5_TXD:SYS_GPA_MFP_PA13_UART5_TXD@GPA_MFP/SYS_ALT_MFP4_PA13_UART5_TXD@ALT_MFP4'] },
	{ f: ['PA.14', 'PWM0_CH2:SYS_GPA_MFP_PA14_PWM0_CH2@GPA_MFP'] },
	{ f: ['PA.15', 'PWM0_CH3:SYS_GPA_MFP_PA15_PWM0_CH3@GPA_MFP'] },

	{ f: ['PB.0', 'UART0_RXD:SYS_GPB_MFP_PB0_UART0_RXD@GPB_MFP'] },
	{ f: ['PB.1', 'UART0_TXD:SYS_GPB_MFP_PB1_UART0_TXD@GPB_MFP'] },
	{ f: ['PB.2', 'UART0_nRTS:SYS_GPB_MFP_PB2_UART0_nRTS@GPB_MFP', 'TM2_EXT:SYS_GPB_MFP_PB2_TM2_EXT@GPB_MFP/SYS_ALT_MFP_PB2_TM2_EXT@ALT_MFP', 'PWM1_BRAKE1:SYS_GPB_MFP_PB2_PWM1_BRAKE1@GPB_MFP/SYS_ALT_MFP3_PB2_PWM1_BRAKE1@ALT_MFP3', 'TM2:SYS_GPB_MFP_PB2_TM2@GPB_MFP/SYS_ALT_MFP2_PB2_TM2@ALT_MFP2'] },
	{ f: ['PB.3', 'UART0_nCTS:SYS_GPB_MFP_PB3_UART0_nCTS@GPB_MFP', 'TM3_EXT:SYS_GPB_MFP_PB3_TM3_EXT@GPB_MFP/SYS_ALT_MFP_PB3_TM3_EXT@ALT_MFP', 'PWM1_BRAKE0:SYS_GPB_MFP_PB3_PWM1_BRAKE0@GPB_MFP/SYS_ALT_MFP3_PB3_PWM1_BRAKE0@ALT_MFP3', 'TM3:SYS_GPB_MFP_PB3_TM3@GPB_MFP/SYS_ALT_MFP_PB3_TM3@ALT_MFP/SYS_ALT_MFP2_PB3_TM3@ALT_MFP2'] },
	{ f: ['PB.4', 'UART1_RXD:SYS_GPB_MFP_PB4_UART1_RXD@GPB_MFP'] },
	{ f: ['PB.5', 'UART1_TXD:SYS_GPB_MFP_PB5_UART1_TXD@GPB_MFP'] },
	{ f: ['PB.6', 'UART1_nRTS:SYS_GPB_MFP_PB6_UART1_nRTS@GPB_MFP'] },
	{ f: ['PB.7', 'UART1_nCTS:SYS_GPB_MFP_PB7_UART1_nCTS@GPB_MFP'] },
	{ f: ['PB.8', 'TM0:SYS_GPB_MFP_PB8_TM0@GPB_MFP', 'CLKO:SYS_GPB_MFP_PB8_CLKO@GPB_MFP/SYS_ALT_MFP_PB8_CLKO@ALT_MFP', 'BPWM1_CH2:SYS_GPB_MFP_PB8_BPWM1_CH2@GPB_MFP/SYS_ALT_MFP3_PB8_BPWM1_CH2@ALT_MFP3'] },
	{ f: ['PB.9', 'TM1:SYS_GPB_MFP_PB9_TM1@GPB_MFP'] },
	{ f: ['PB.10', 'TM2:SYS_GPB_MFP_PB10_TM2@GPB_MFP'] },
	{ f: ['PB.11', 'TM3:SYS_GPB_MFP_PB11_TM3@GPB_MFP', 'PWM0_CH4:SYS_GPB_MFP_PB11_PWM0_CH4@GPB_MFP/SYS_ALT_MFP3_PB11_PWM0_CH4@ALT_MFP3'] },
	{ f: ['PB.12', 'CLKO:SYS_GPB_MFP_PB12_CLKO@GPB_MFP', 'BPWM1_CH3:SYS_GPB_MFP_PB12_BPWM1_CH3@GPB_MFP/SYS_ALT_MFP3_PB12_BPWM1_CH3@ALT_MFP3'] },
	{ f: ['PB.13'] },
	{ f: ['PB.14', 'INT0:SYS_GPB_MFP_PB14_INT0@GPB_MFP'] },
	{ f: ['PB.15', 'INT1:SYS_GPB_MFP_PB15_INT1@GPB_MFP', 'TM0:SYS_GPB_MFP_PB15_TM0@GPB_MFP/SYS_ALT_MFP2_PB15_TM0@ALT_MFP2', 'TM0_EXT:SYS_GPB_MFP_PB15_TM0_EXT@GPB_MFP/SYS_ALT_MFP_PB15_TM0_EXT@ALT_MFP', 'BPWM1_CH5:SYS_GPB_MFP_PB15_BPWM1_CH5@GPB_MFP/SYS_ALT_MFP2_PB15_BPWM1_CH5@ALT_MFP2/SYS_ALT_MFP3_PB15_BPWM1_CH5@ALT_MFP3'] },

	{ f: ['PC.0', 'SPI0_SS0:SYS_GPC_MFP_PC0_SPI0_SS0@GPC_MFP', 'BPWM0_CH0:SYS_GPC_MFP_PC0_BPWM0_CH0@GPC_MFP/SYS_ALT_MFP3_PC0_BPWM0_CH0@ALT_MFP3'] },
	{ f: ['PC.1', 'SPI0_CLK:SYS_GPC_MFP_PC1_SPI0_CLK@GPC_MFP', 'BPWM0_CH1:SYS_GPC_MFP_PC1_BPWM0_CH1@GPC_MFP/SYS_ALT_MFP3_PC1_BPWM0_CH1@ALT_MFP3'] },
	{ f: ['PC.2', 'SPI0_MISO0:SYS_GPC_MFP_PC2_SPI0_MISO0@GPC_MFP', 'BPWM0_CH2:SYS_GPC_MFP_PC2_BPWM0_CH2@GPC_MFP/SYS_ALT_MFP3_PC2_BPWM0_CH2@ALT_MFP3'] },
	{ f: ['PC.3', 'SPI0_MOSI0:SYS_GPC_MFP_PC3_SPI0_MOSI0@GPC_MFP', 'BPWM0_CH3:SYS_GPC_MFP_PC3_BPWM0_CH3@GPC_MFP/SYS_ALT_MFP3_PC3_BPWM0_CH3@ALT_MFP3'] },
	{ f: ['PC.4'] },
	{ f: ['PC.5'] },
	{ f: ['PC.6', 'UART4_TXD:SYS_GPC_MFP_PC6_UART4_TXD@GPC_MFP', 'I2C0_SDA:SYS_GPC_MFP_PC6_I2C0_SDA@GPC_MFP/SYS_ALT_MFP4_PC6_I2C0_SDA@ALT_MFP4', 'PWM0_BRAKE0:SYS_GPC_MFP_PC6_PWM0_BRAKE0@GPC_MFP/SYS_ALT_MFP3_PC6_PWM0_BRAKE0@ALT_MFP3'] },
	{ f: ['PC.7', 'UART4_RXD:SYS_GPC_MFP_PC7_UART4_RXD@GPC_MFP', 'I2C0_SCL:SYS_GPC_MFP_PC7_I2C0_SCL@GPC_MFP/SYS_ALT_MFP4_PC7_I2C0_SCL@ALT_MFP4', 'PWM0_BRAKE1:SYS_GPC_MFP_PC7_PWM0_BRAKE1@GPC_MFP/SYS_ALT_MFP3_PC7_PWM0_BRAKE1@ALT_MFP3'] },
	{ f: ['PC.8', 'PWM0_BRAKE0:SYS_GPC_MFP_PC8_PWM0_BRAKE0@GPC_MFP'] },
	{ f: ['PC.9', 'PWM0_BRAKE1:SYS_GPC_MFP_PC9_PWM0_BRAKE1@GPC_MFP'] },
	{ f: ['PC.10', 'PWM1_BRAKE0:SYS_GPC_MFP_PC10_PWM1_BRAKE0@GPC_MFP'] },
	{ f: ['PC.11', 'PWM1_BRAKE1:SYS_GPC_MFP_PC11_PWM1_BRAKE1@GPC_MFP'] },
	{ f: ['PC.12'] },
	{ f: ['PC.13'] },
	{ f: ['PC.14'] },
	{ f: ['PC.15'] },

	{ f: ['PD.0'] },
	{ f: ['PD.1'] },
	{ f: ['PD.2'] },
	{ f: ['PD.3'] },
	{ f: ['PD.4'] },
	{ f: ['PD.5'] },
	{ f: ['PD.6', 'BPWM1_CH1:SYS_GPD_MFP_PD6_BPWM1_CH1@GPD_MFP/SYS_ALT_MFP3_PD6_BPWM1_CH1@ALT_MFP3'] },
	{ f: ['PD.7', 'BPWM1_CH0:SYS_GPD_MFP_PD7_BPWM1_CH0@GPD_MFP/SYS_ALT_MFP3_PD7_BPWM1_CH0@ALT_MFP3'] },
	{ f: ['PD.8'] },
	{ f: ['PD.9'] },
	{ f: ['PD.10'] },
	{ f: ['PD.11'] },
	{ f: ['PD.12'] },
	{ f: ['PD.13'] },
	{ f: ['PD.14', 'UART2_RXD:SYS_GPD_MFP_PD14_UART2_RXD@GPD_MFP', 'BPWM0_CH5:SYS_GPD_MFP_PD14_BPWM0_CH5@GPD_MFP/SYS_ALT_MFP3_PD14_BPWM0_CH5@ALT_MFP3'] },
	{ f: ['PD.15', 'UART2_TXD:SYS_GPD_MFP_PD15_UART2_TXD@GPD_MFP', 'BPWM0_CH4:SYS_GPD_MFP_PD15_BPWM0_CH4@GPD_MFP/SYS_ALT_MFP3_PD15_BPWM0_CH4@ALT_MFP3'] },

	{ f: ['PE.0'] },
	{ f: ['PE.1'] },
	{ f: ['PE.2'] },
	{ f: ['PE.3'] },
	{ f: ['PE.4'] },
	{ f: ['PE.5', 'PWM0_CH5:SYS_GPE_MFP_PE5_PWM0_CH5@GPE_MFP', 'TM1:SYS_GPE_MFP_PE5_TM1@GPE_MFP/SYS_ALT_MFP2_PE5_TM1@ALT_MFP2', 'TM1_EXT:SYS_GPE_MFP_PE5_TM1_EXT@GPE_MFP/SYS_ALT_MFP_PE5_TM1_EXT@ALT_MFP'] },
	{ f: ['PE.6'] },
	{ f: ['PE.7'] },
	{ f: ['PE.8'] },
	{ f: ['PE.9'] },
	{ f: ['PE.10'] },
	{ f: ['PE.11'] },
	{ f: ['PE.12'] },
	{ f: ['PE.13'] },
	{ f: ['PE.14'] },
	{ f: ['PE.15'] },

	{ f: ['PF.0', 'XT1_OUT:SYS_GPF_MFP_PF0_XT1_OUT@GPF_MFP'] },
	{ f: ['PF.1', 'XT1_IN:SYS_GPF_MFP_PF1_XT1_IN@GPF_MFP'] },
	{ f: ['PF.2'] },
	{ f: ['PF.3'] },
	{ f: ['PF.4', 'I2C0_SDA:SYS_GPF_MFP_PF4_I2C0_SDA@GPF_MFP', 'PWM1_CH4:SYS_GPF_MFP_PF4_PWM1_CH4@GPF_MFP/SYS_ALT_MFP3_PF4_PWM1_CH4@ALT_MFP3'] },
	{ f: ['PF.5', 'I2C0_SCL:SYS_GPF_MFP_PF5_I2C0_SCL@GPF_MFP', 'PWM1_CH5:SYS_GPF_MFP_PF5_PWM1_CH5@GPF_MFP/SYS_ALT_MFP3_PF5_PWM1_CH5@ALT_MFP3'] },
	{ f: ['PF.6', 'ICE_CLK:SYS_GPF_MFP_PF6_ICE_CLK@GPF_MFP'] },
	{ f: ['PF.7', 'ICE_DAT:SYS_GPF_MFP_PF7_ICE_DAT@GPF_MFP'] },
	{ f: ['PF.8', 'CLKO:SYS_GPF_MFP_PF8_CLKO@GPF_MFP', 'BPWM1_CH4:SYS_ALT_MFP3_PF8_BPWM1_CH4@ALT_MFP3'] }
];

NUTOOL_PIN.g_cfg_gpiosDescriptions = [
	'ADC_CH0:ADC_CH0 analog input',
	'ADC_CH1:ADC_CH1 analog input',
	'ADC_CH2:ADC_CH2 analog input',
	'ADC_CH3:ADC_CH3 analog input',
	'ADC_CH4:ADC_CH4 analog input',
	'ADC_CH5:ADC_CH5 analog input',
	'ADC_CH6:ADC_CH6 analog input',
	'ADC_CH7:ADC_CH7 analog input',

	'AVDD:Power supply for internal analog circuit',
	'AVSS:Ground pin for analog circuit',

	'BPWM0_CH0:BPWM0 CH0 input/Capture input',
	'BPWM0_CH1:BPWM0 CH1 input/Capture input',
	'BPWM0_CH2:BPWM0 CH2 input/Capture input',
	'BPWM0_CH3:BPWM0 CH3 input/Capture input',
	'BPWM0_CH4:BPWM0 CH4 input/Capture input',
	'BPWM0_CH5:BPWM0 CH5 output/Capture input',
	'BPWM1_CH0:BPWM1 CH0 output/Capture input',
	'BPWM1_CH1:BPWM1 CH1 output/Capture input',
	'BPWM1_CH2:BPWM1 CH2 output/Capture input',
	'BPWM1_CH3:BPWM1 CH3 output/Capture input',
	'BPWM1_CH4:BPWM1 CH4 output/Capture input',
	'BPWM1_CH5:BPWM1 CH5 output/Capture input',

	'CLKO:Frequency divider clock output pin',

	'I2C0_SCL:I2C0 clock pin',
	'I2C0_SDA:I2C0 data input/output pin',
	'I2C1_SCL:I2C1 clock pin',
	'I2C1_SDA:I2C1 data input/output pin',

	'ICE_CLK:Serial wire debugger clock pin',
	'ICE_DAT:Serial wire debugger data pin',

	'INT0:External interrupt0 input pin',
	'INT1:External interrupt1 input pin',

	'LDO_CAP:LDO output pin',

	'nRESET:External reset input: active LOW, with an internal pull-up. Set this pin low reset chip to initial state',

	'PWM0_BRAKE0:PWM0 brake input pin',
	'PWM0_BRAKE1:PWM0 brake input pin',
	'PWM0_CH0:PWM0 CH0 output/Capture input',
	'PWM0_CH1:PWM0 CH1 output/Capture input',
	'PWM0_CH2:PWM0 CH2 output/Capture input',
	'PWM0_CH3:PWM0 CH3 output/Capture input',
	'PWM0_CH4:PWM0 CH4 output/Capture input',
	'PWM0_CH5:PWM0 CH5 output/Capture input',
	'PWM1_BRAKE0:PWM1 brake input pin',
	'PWM1_BRAKE1:PWM1 brake input pin',
	'PWM1_CH0:PWM1 CH0 output/Capture input',
	'PWM1_CH1:PWM1 CH1 output/Capture input',
	'PWM1_CH2:PWM1 CH2 output/Capture input',
	'PWM1_CH3:PWM1 CH3 output/Capture input',
	'PWM1_CH4:PWM1 CH4 output/Capture input',
	'PWM1_CH5:PWM1 CH5 output/Capture input',

	'SPI0_CLK:SPI0 serial clock pin',
	'SPI0_MISO0:SPI0 MISO (Master In, Slave Out) pin',
	'SPI0_MOSI0:SPI0 MOSI (Master Out, Slave In) pin',
	'SPI0_SS0:SPI0 slave select pin',

	'STADC:ADC external trigger input',

	'TM0@PB.8:Timer0 event counter input / toggle output',
	'TM0@PB.15:Timer0 toggle output pin',
	'TM0_EXT:Timer0 external capture input pin',
	'TM1@PB.9:Timer1 event counter input / toggle output',
	'TM1@PE.5:Timer1 toggle output pin',
	'TM1_EXT:Timer1 external capture input pin',
	'TM2@PB.10:Timer2 event counter input / toggle output',
	'TM2@PB.2:Timer2 toggle output pin',
	'TM2_EXT:Timer2 external capture input pin',
	'TM3@PB.11:Timer3 event counter input / toggle output',
	'TM3@PB.3:Timer3 toggle output pin',
	'TM3_EXT:Timer3 external capture input pin',

	'UART0_nCTS:Clear to Send input pin for UART0',
	'UART0_nRTS:Request to Send output pin for UART0',
	'UART0_RXD:Data receiver input pin for UART0',
	'UART0_TXD:Data transmitter output pin for UART0',
	'UART1_nCTS:Clear to Send input pin for UART1',
	'UART1_nRTS:Request to Send output pin for UART1',
	'UART1_RXD:Data receiver input pin for UART1',
	'UART1_TXD:Data transmitter output pin for UART1',
	'UART2_RXD:Data receiver input pin for UART2',
	'UART2_TXD:Data transmitter output pin for UART2',
	'UART3_RXD:Data receiver input pin for UART3',
	'UART3_TXD:Data transmitter output pin for UART3',
	'UART4_RXD:Data reveiver input pin for UART4',
	'UART4_TXD:Data transmitter output pin for UART4',
	'UART5_RXD:Data receiver input pin for UART5',
	'UART5_TXD:Data transmitter output pin for UART5',

	'VDD:Power supply for I/O ports and LDO source for internal PLL and digital circuit',
	'VREF:Voltage reference input for ADC',
	'VSS:Ground pin for digital circuit',

	'XT1_IN:External 4~24 MHz (high speed) crystal input pin',
	'XT1_OUT:External 4~24 MHz (high speed) crystal output pin'
];

NUTOOL_PIN.g_cfg_regDescriptions = {};
NUTOOL_PIN.g_cfg_regDescriptions.GPA_MFP = '0x50000030';
NUTOOL_PIN.g_cfg_regDescriptions.GPB_MFP = '0x50000034';
NUTOOL_PIN.g_cfg_regDescriptions.GPC_MFP = '0x50000038';
NUTOOL_PIN.g_cfg_regDescriptions.GPD_MFP = '0x5000003C';
NUTOOL_PIN.g_cfg_regDescriptions.GPE_MFP = '0x50000040';
NUTOOL_PIN.g_cfg_regDescriptions.GPF_MFP = '0x50000044';
NUTOOL_PIN.g_cfg_regDescriptions.ALT_MFP = '0x50000050';
NUTOOL_PIN.g_cfg_regDescriptions.ALT_MFP2 = '0x5000005C';
NUTOOL_PIN.g_cfg_regDescriptions.ALT_MFP3 = '0x50000060';
NUTOOL_PIN.g_cfg_regDescriptions.ALT_MFP4 = '0x50000064';

NUTOOL_PIN.g_cfg_gpioMatrix = [
	{ f: ['PA.0', 'GPA_MFP[0]:0', 'ALT_MFP4[12]:1', 'ALT_MFP4[7]:2', 'ALT_MFP3[4]:3'] },
	{ f: ['PA.1', 'GPA_MFP[1]:0', 'ALT_MFP4[13]:1', 'ALT_MFP4[6]:2', 'ALT_MFP3[5]:3'] },
	{ f: ['PA.2', 'GPA_MFP[2]:0', 'ALT_MFP4[3]:1', 'ALT_MFP3[6]:2'] },
	{ f: ['PA.3', 'GPA_MFP[3]:0', 'ALT_MFP4[2]:1', 'ALT_MFP3[7]:2'] },
	{ f: ['PA.4', 'GPA_MFP[4]:0'] },
	{ f: ['PA.5', 'GPA_MFP[5]:0', 'ALT_MFP4[4]:1'] },
	{ f: ['PA.6', 'GPA_MFP[6]:0', 'ALT_MFP4[5]:1'] },
	{ f: ['PA.7', 'GPA_MFP[7]:0', 'ALT_MFP4[14]:1'] },
	{ f: ['PA.8', 'GPA_MFP[8]:0', 'ALT_MFP4[0]:1'] },
	{ f: ['PA.9', 'GPA_MFP[9]:0', 'ALT_MFP4[1]:1'] },
	{ f: ['PA.10', 'GPA_MFP[10]:0', 'ALT_MFP3[8]:1'] },
	{ f: ['PA.11', 'GPA_MFP[11]:0', 'ALT_MFP3[9]:1'] },
	{ f: ['PA.12', 'GPA_MFP[12]:0', 'ALT_MFP4[8]:1'] },
	{ f: ['PA.13', 'GPA_MFP[13]:0', 'ALT_MFP4[9]:1'] },
	{ f: ['PA.14', 'GPA_MFP[14]:0'] },
	{ f: ['PA.15', 'GPA_MFP[15]:0'] },

	{ f: ['PB.0', 'GPB_MFP[0]:0'] },
	{ f: ['PB.1', 'GPB_MFP[1]:0'] },
	{ f: ['PB.2', 'GPB_MFP[2]:0', 'ALT_MFP[26]:1', 'ALT_MFP3[31]:2', 'ALT_MFP2[4]:3'] },
	{ f: ['PB.3', 'GPB_MFP[3]:0', 'ALT_MFP[27]:1', 'ALT_MFP3[30]:2', 'ALT_MFP2[5]:3'] },
	{ f: ['PB.4', 'GPB_MFP[4]:0'] },
	{ f: ['PB.5', 'GPB_MFP[5]:0'] },
	{ f: ['PB.6', 'GPB_MFP[6]:0'] },
	{ f: ['PB.7', 'GPB_MFP[7]:0'] },
	{ f: ['PB.8', 'GPB_MFP[8]:0', 'ALT_MFP[29]:1', 'ALT_MFP3[20]:2'] },
	{ f: ['PB.9', 'GPB_MFP[9]:0'] },
	{ f: ['PB.10', 'GPB_MFP[10]:0'] },
	{ f: ['PB.11', 'GPB_MFP[11]:0', 'ALT_MFP3[24]:1'] },
	{ f: ['PB.12', 'GPB_MFP[12]:0', 'ALT_MFP3[21]:1'] },
	{ f: ['PB.13', 'GPB_MFP[13]:0'] },
	{ f: ['PB.14', 'GPB_MFP[14]:0'] },
	{ f: ['PB.15', 'GPB_MFP[15]:0', 'ALT_MFP2[2]:1', 'ALT_MFP[24]:2', 'ALT_MFP3[23]:3'] },

	{ f: ['PC.0', 'GPC_MFP[0]:0', 'ALT_MFP3[12]:1'] },
	{ f: ['PC.1', 'GPC_MFP[1]:0', 'ALT_MFP3[13]:1'] },
	{ f: ['PC.2', 'GPC_MFP[2]:0', 'ALT_MFP3[14]:1'] },
	{ f: ['PC.3', 'GPC_MFP[3]:0', 'ALT_MFP3[15]:1'] },
	{ f: ['PC.4'] },
	{ f: ['PC.5'] },
	{ f: ['PC.6', 'GPC_MFP[6]:0', 'ALT_MFP4[10]:1', 'ALT_MFP3[28]:2'] },
	{ f: ['PC.7', 'GPC_MFP[7]:0', 'ALT_MFP4[11]:1', 'ALT_MFP3[29]:2'] },
	{ f: ['PC.8', 'GPC_MFP[8]:0'] },
	{ f: ['PC.9', 'GPC_MFP[9]:0'] },
	{ f: ['PC.10', 'GPC_MFP[10]:0'] },
	{ f: ['PC.11', 'GPC_MFP[11]:0'] },
	{ f: ['PC.12'] },
	{ f: ['PC.13'] },
	{ f: ['PC.14', 'GPC_MFP[14]:0'] },
	{ f: ['PC.15', 'GPC_MFP[15]:0'] },

	{ f: ['PD.0'] },
	{ f: ['PD.1'] },
	{ f: ['PD.2'] },
	{ f: ['PD.3'] },
	{ f: ['PD.4'] },
	{ f: ['PD.5'] },
	{ f: ['PD.6', 'GPD_MFP[6]:0', 'ALT_MFP3[19]:1'] },
	{ f: ['PD.7', 'GPD_MFP[7]:0', 'ALT_MFP3[18]:1'] },
	{ f: ['PD.8'] },
	{ f: ['PD.9'] },
	{ f: ['PD.10'] },
	{ f: ['PD.11'] },
	{ f: ['PD.12'] },
	{ f: ['PD.13'] },
	{ f: ['PD.14', 'GPD_MFP[14]:0', 'ALT_MFP3[17]:1'] },
	{ f: ['PD.15', 'GPD_MFP[15]:0', 'ALT_MFP3[16]:1'] },

	{ f: ['PE.0'] },
	{ f: ['PE.1'] },
	{ f: ['PE.2'] },
	{ f: ['PE.3'] },
	{ f: ['PE.4'] },
	{ f: ['PE.5', 'GPE_MFP[5]:0', 'ALT_MFP2[3]:1', 'ALT_MFP[25]:2'] },
	{ f: ['PE.6'] },
	{ f: ['PE.7'] },
	{ f: ['PE.8'] },
	{ f: ['PE.9'] },
	{ f: ['PE.10'] },
	{ f: ['PE.11'] },
	{ f: ['PE.12'] },
	{ f: ['PE.13'] },
	{ f: ['PE.14'] },
	{ f: ['PE.15'] },

	{ f: ['PF.0'] },
	{ f: ['PF.1'] },
	{ f: ['PF.2'] },
	{ f: ['PF.3'] },
	{ f: ['PF.4', 'GPF_MFP[4]:0', 'ALT_MFP3[10]:1'] },
	{ f: ['PF.5', 'GPF_MFP[5]:0', 'ALT_MFP3[11]:1'] },
	{ f: ['PF.6', 'GPF_MFP[6]:0'] },
	{ f: ['PF.7', 'GPF_MFP[7]:0'] },
	{ f: ['PF.8', 'GPF_MFP[8]:0', 'ALT_MFP3[22]:1'] }
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
