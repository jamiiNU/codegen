// chip content
NUTOOL_PIN.g_cfg_chips = [
	//NUC200AN
	{ name: "NUC200VE3AN", pkg: "LQFP100" },
	{ name: "NUC220VE3AN", pkg: "LQFP100" },

	{ name: "NUC200SC2AN", pkg: "LQFP64" },
	{ name: "NUC200SD2AN", pkg: "LQFP64" },
	{ name: "NUC200SE3AN", pkg: "LQFP64" },
	{ name: "NUC220SC2AN", pkg: "LQFP64" },
	{ name: "NUC220SD2AN", pkg: "LQFP64" },
	{ name: "NUC220SE3AN", pkg: "LQFP64" },

	{ name: "NUC200LC2AN", pkg: "LQFP48" },
	{ name: "NUC200LD2AN", pkg: "LQFP48" },
	{ name: "NUC200LE3AN", pkg: "LQFP48" },
	{ name: "NUC220LC2AN", pkg: "LQFP48" },
	{ name: "NUC220LD2AN", pkg: "LQFP48" },
	{ name: "NUC220LE3AN", pkg: "LQFP48" },
	//NUC200AE
	{ name: "NUC240VE3AE", pkg: "LQFP100" },
	{ name: "NUC230VE3AE", pkg: "LQFP100" },
	{ name: "NUC240SE3AE", pkg: "LQFP64" },
	{ name: "NUC240SD2AE", pkg: "LQFP64" },
	{ name: "NUC240SC2AE", pkg: "LQFP64" },
	{ name: "NUC230SE3AE", pkg: "LQFP64" },
	{ name: "NUC230SD2AE", pkg: "LQFP64" },
	{ name: "NUC230SC2AE", pkg: "LQFP64" },
	{ name: "NUC240LE3AE", pkg: "LQFP48" },
	{ name: "NUC240LD2AE", pkg: "LQFP48" },
	{ name: "NUC240LC2AE", pkg: "LQFP48" },
	{ name: "NUC230LE3AE", pkg: "LQFP48" },
	{ name: "NUC230LD2AE", pkg: "LQFP48" },
	{ name: "NUC230LC2AE", pkg: "LQFP48" },
	//NUC2201
	{ name: "NUC2201LE3AE", pkg: "LQFP48" },
	{ name: "NUC2201SE3AE", pkg: "LQFP64" }
];

NUTOOL_PIN.g_cfg_pkgs = {
	"LQFP100(NUC200)": [
		'PE.15', 'PE.14', 'PE.13', 'PB.14', 'PB.13', 'VBAT', 'X32_OUT', 'X32_IN', 'PA.11', 'PA.10',
		'PA.9', 'PA.8', 'PD.8', 'PD.9', 'PD.10', 'PD.11', 'PD.12', 'PD.13', 'PB.4', 'PB.5',
		'PB.6', 'PB.7', 'LDO_CAP', 'VDD', 'VSS',
		'PE.12', 'PE.11', 'PE.10', 'PE.9', 'PE.8', 'PE.7', 'PB.0', 'PB.1', 'PB.2', 'PB.3',
		'PD.6', 'PD.7', 'PD.14', 'PD.15', 'PC.5', 'PC.4', 'PC.3', 'PC.2', 'PC.1', 'PC.0',
		'PE.6', 'PE.5', 'PB.11', 'PB.10', 'PB.9',
		'PE.4', 'PE.3', 'PE.2', 'PE.1', 'PE.0', 'PC.13', 'PC.12', 'PC.11', 'PC.10', 'PC.9',
		'PC.8', 'PA.15', 'PA.14', 'PA.13', 'PA.12', 'ICE_DAT', 'ICE_CLK', 'VDD', 'VSS', 'AVSS',
		'PA.0', 'PA.1', 'PA.2', 'PA.3', 'PA.4',
		'PA.5', 'PA.6', 'PA.7', 'VREF', 'AVDD', 'PD.0', 'PD.1', 'PD.2', 'PD.3', 'PD.4',
		'PD.5', 'PC.7', 'PC.6', 'PC.15', 'PC.14', 'PB.15', 'XT1_OUT/PF.0', 'XT1_IN/PF.1', 'nRESET', 'VSS',
		'VDD', 'PF.2', 'PF.3', 'PVSS', 'PB.8'
	],
	"LQFP64(NUC200)": [
		'PB.14', 'PB.13', 'VBAT', 'X32_OUT', 'X32_IN', 'PA.11', 'PA.10', 'PA.9', 'PA.8', 'PB.4',
		'PB.5', 'PB.6', 'PB.7', 'LDO_CAP', 'VDD', 'VSS',
		'PB.0', 'PB.1', 'PB.2', 'PB.3', 'PD.6', 'PD.7', 'PD.14', 'PD.15', 'PC.3', 'PC.2',
		'PC.1', 'PC.0', 'PE.5', 'PB.11', 'PB.10', 'PB.9',
		'PC.11', 'PC.10', 'PC.9', 'PC.8', 'PA.15', 'PA.14', 'PA.13', 'PA.12', 'ICE_DAT', 'ICE_CLK',
		'AVSS', 'PA.0', 'PA.1', 'PA.2', 'PA.3', 'PA.4',
		'PA.5', 'PA.6', 'VREF', 'AVDD', 'PC.7', 'PC.6', 'PC.15', 'PC.14', 'PB.15', 'XT1_OUT/PF.0',
		'XT1_IN/PF.1', 'nRESET', 'VSS', 'VDD', 'PVSS', 'PB.8'
	],
	"LQFP48(NUC200)": [
		'VBAT', 'X32_OUT', 'X32_IN', 'PA.11', 'PA.10', 'PA.9', 'PA.8', 'PB.4', 'PB.5', 'LDO_CAP',
		'VDD', 'VSS',
		'PB.0', 'PB.1', 'PB.2', 'PB.3', 'PC.3', 'PC.2', 'PC.1', 'PC.0', 'PE.5', 'PB.11',
		'PB.10', 'PB.9',
		'PA.15', 'PA.14', 'PA.13', 'PA.12', 'ICE_DAT', 'ICE_CLK', 'AVSS', 'PA.0', 'PA.1', 'PA.2',
		'PA.3', 'PA.4',
		'PA.5', 'PA.6', 'VREF', 'AVDD', 'PC.7', 'PC.6', 'PB.15', 'XT1_OUT/PF.0', 'XT1_IN/PF.1', 'nRESET',
		'PVSS', 'PB.8'
	],
	"LQFP100(NUC220)": [
		'PE.15', 'PE.14', 'PE.13', 'PB.14', 'PB.13', 'VBAT', 'X32_OUT', 'X32_IN', 'PA.11', 'PA.10',
		'PA.9', 'PA.8', 'PD.8', 'PD.9', 'PD.10', 'PD.11', 'PD.12', 'PD.13', 'PB.4', 'PB.5',
		'PB.6', 'PB.7', 'LDO_CAP', 'VDD', 'VSS',
		'PE.8', 'PE.7', 'USB_VBUS', 'USB_VDD33_CAP', 'USB_D-', 'USB_D+', 'PB.0', 'PB.1', 'PB.2', 'PB.3',
		'PD.6', 'PD.7', 'PD.14', 'PD.15', 'PC.5', 'PC.4', 'PC.3', 'PC.2', 'PC.1', 'PC.0',
		'PE.6', 'PE.5', 'PB.11', 'PB.10', 'PB.9',
		'PE.4', 'PE.3', 'PE.2', 'PE.1', 'PE.0', 'PC.13', 'PC.12', 'PC.11', 'PC.10', 'PC.9',
		'PC.8', 'PA.15', 'PA.14', 'PA.13', 'PA.12', 'ICE_DAT', 'ICE_CLK', 'VDD', 'VSS', 'AVSS',
		'PA.0', 'PA.1', 'PA.2', 'PA.3', 'PA.4',
		'PA.5', 'PA.6', 'PA.7', 'VREF', 'AVDD', 'PD.0', 'PD.1', 'PD.2', 'PD.3', 'PD.4',
		'PD.5', 'PC.7', 'PC.6', 'PC.15', 'PC.14', 'PB.15', 'XT1_OUT/PF.0', 'XT1_IN/PF.1', 'nRESET', 'VSS',
		'VDD', 'PF.2', 'PF.3', 'PVSS', 'PB.8'
	],
	"LQFP64(NUC220)": [
		'PB.14', 'PB.13', 'VBAT', 'X32_OUT', 'X32_IN', 'PA.11', 'PA.10', 'PA.9', 'PA.8', 'PB.4',
		'PB.5', 'PB.6', 'PB.7', 'LDO_CAP', 'VDD', 'VSS',
		'USB_VBUS', 'USB_VDD33_CAP', 'USB_D-', 'USB_D+', 'PB.0', 'PB.1', 'PB.2', 'PB.3', 'PC.3', 'PC.2',
		'PC.1', 'PC.0', 'PE.5', 'PB.11', 'PB.10', 'PB.9',
		'PC.11', 'PC.10', 'PC.9', 'PC.8', 'PA.15', 'PA.14', 'PA.13', 'PA.12', 'ICE_DAT', 'ICE_CLK',
		'AVSS', 'PA.0', 'PA.1', 'PA.2', 'PA.3', 'PA.4',
		'PA.5', 'PA.6', 'VREF', 'AVDD', 'PC.7', 'PC.6', 'PC.15', 'PC.14', 'PB.15', 'XT1_OUT/PF.0',
		'XT1_IN/PF.1', 'nRESET', 'VSS', 'VDD', 'PVSS', 'PB.8'
	],
	"LQFP48(NUC220)": [
		'VBAT', 'X32_OUT', 'X32_IN', 'PA.11', 'PA.10', 'PA.9', 'PA.8', 'PB.4', 'PB.5', 'LDO_CAP',
		'VDD', 'VSS',
		'USB_VBUS', 'USB_VDD33_CAP', 'USB_D-', 'USB_D+', 'PB.0', 'PB.1', 'PB.2', 'PB.3', 'PC.3', 'PC.2',
		'PC.1', 'PC.0',
		'PA.15', 'PA.14', 'PA.13', 'PA.12', 'ICE_DAT', 'ICE_CLK', 'AVSS', 'PA.0', 'PA.1', 'PA.2',
		'PA.3', 'PA.4',
		'PA.5', 'PA.6', 'VREF', 'AVDD', 'PC.7', 'PC.6', 'PB.15', 'XT1_OUT/PF.0', 'XT1_IN/PF.1', 'nRESET',
		'PVSS', 'PB.8'
	]
};

NUTOOL_PIN.g_cfg_OrCAD = {};

NUTOOL_PIN.g_cfg_gpios = [
	{ f: ['PA.0:0', 'ADC0:1', 'SC0_PWR:3'] },
	{ f: ['PA.1:0', 'ADC1:1', 'SC0_RST:3'] },
	{ f: ['PA.2:0', 'ADC2:1', 'SC0_CLK:3'] },
	{ f: ['PA.3:0', 'ADC3:1', 'SC0_DAT:3'] },
	{ f: ['PA.4:0', 'ADC4:1', 'SC1_PWR:3'] },
	{ f: ['PA.5:0', 'ADC5:1', 'SC1_RST:3'] },
	{ f: ['PA.6:0', 'ADC6:1', 'SC1_CLK:3'] },
	{ f: ['PA.7:0', 'ADC7:1', 'SPI2_SS1:3', 'SC1_DAT:5'] },
	{ f: ['PA.8:0', 'I2C0_SDA:1'] },
	{ f: ['PA.9:0', 'I2C0_SCL:1'] },
	{ f: ['PA.10:0', 'I2C1_SDA:1'] },
	{ f: ['PA.11:0', 'I2C1_SCL:1'] },
	{ f: ['PA.12:0', 'PWM0:1', 'SC2_DAT:3'] },
	{ f: ['PA.13:0', 'PWM1:1', 'SC2_CLK:3'] },
	{ f: ['PA.14:0', 'PWM2:1', 'SC2_RST:3'] },
	{ f: ['PA.15:0', 'PWM3:1', 'I2S_MCLK:3', 'SC2_PWR:5'] },

	{ f: ['PB.0:0', 'UART0_RXD:1'] },
	{ f: ['PB.1:0', 'UART0_TXD:1'] },
	{ f: ['PB.2:0', 'UART0_nRTS:1', 'TM2_EXT:3', 'ACMP0_O:5'] },
	{ f: ['PB.3:0', 'UART0_nCTS:1', 'TM3_EXT:3', 'SC2_CD:5'] },
	{ f: ['PB.4:0', 'UART1_RXD:1'] },
	{ f: ['PB.5:0', 'UART1_TXD:1'] },
	{ f: ['PB.6:0', 'UART1_nRTS:1'] },
	{ f: ['PB.7:0', 'UART1_nCTS:1'] },
	{ f: ['PB.8:0', 'TM0:1', 'STADC:2', 'CLKO:3'] },
	{ f: ['PB.9:0', 'TM1:1', 'SPI1_SS1:3'] },
	{ f: ['PB.10:0', 'TM2:1', 'SPI0_SS1:3'] },
	{ f: ['PB.11:0', 'TM3:1', 'PWM4:3'] },
	{ f: ['PB.12:0'] },
	{ f: ['PB.13:0', 'ACMP1_O:1'] },
	{ f: ['PB.14:0', 'INT0:1', 'SPI3_SS1:3'] },
	{ f: ['PB.15:0', 'INT1:1', 'TM0_EXT:3'] },

	{ f: ['PC.0:0', 'SPI0_SS0:1', 'I2S_LRCLK:3'] },
	{ f: ['PC.1:0', 'SPI0_CLK:1', 'I2S_BCLK:3'] },
	{ f: ['PC.2:0', 'SPI0_MISO0:1', 'I2S_DI:3'] },
	{ f: ['PC.3:0', 'SPI0_MOSI0:1', 'I2S_DO:3'] },
	{ f: ['PC.4:0', 'SPI0_MISO1:1'] },
	{ f: ['PC.5:0', 'SPI0_MOSI1:1'] },
	{ f: ['PC.6:0', 'ACMP0_P:1', 'SC0_CD:3'] },
	{ f: ['PC.7:0', 'ACMP0_N:1', 'SC1_CD:3'] },
	{ f: ['PC.8:0', 'SPI1_SS0:1'] },
	{ f: ['PC.9:0', 'SPI1_CLK:1'] },
	{ f: ['PC.10:0', 'SPI1_MISO0:1'] },
	{ f: ['PC.11:0', 'SPI1_MOSI0:1'] },
	{ f: ['PC.12:0', 'SPI1_MISO1:1'] },
	{ f: ['PC.13:0', 'SPI1_MOSI1:1'] },
	{ f: ['PC.14:0', 'ACMP1_P:1'] },
	{ f: ['PC.15:0', 'ACMP1_N:1'] },

	{ f: ['PD.0:0', 'SPI2_SS0:1'] },
	{ f: ['PD.1:0', 'SPI2_CLK:1'] },
	{ f: ['PD.2:0', 'SPI2_MISO0:1'] },
	{ f: ['PD.3:0', 'SPI2_MOSI0:1'] },
	{ f: ['PD.4:0', 'SPI2_MISO1:1'] },
	{ f: ['PD.5:0', 'SPI2_MOSI1:1'] },
	{ f: ['PD.6:0'] },
	{ f: ['PD.7:0'] },
	{ f: ['PD.8:0', 'SPI3_SS0:1'] },
	{ f: ['PD.9:0', 'SPI3_CLK:1'] },
	{ f: ['PD.10:0', 'SPI3_MISO0:1'] },
	{ f: ['PD.11:0', 'SPI3_MOSI0:1'] },
	{ f: ['PD.12:0', 'SPI3_MISO1:1'] },
	{ f: ['PD.13:0', 'SPI3_MOSI1:1'] },
	{ f: ['PD.14:0', 'UART2_RXD:1'] },
	{ f: ['PD.15:0', 'UART2_TXD:1'] },

	{ f: ['PE.0:0', 'PWM6:1'] },
	{ f: ['PE.1:0', 'PWM7:1'] },
	{ f: ['PE.2:0'] },
	{ f: ['PE.3:0'] },
	{ f: ['PE.4:0'] },
	{ f: ['PE.5:0', 'PWM5:1', 'TM1_EXT:3'] },
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
	{ f: ['PF.2:0', 'PS2_DAT:1'] },
	{ f: ['PF.3:0', 'PS2_CLK:1'] }
];

NUTOOL_PIN.g_cfg_gpiosDefines = [
	{ f: ['PA.0', 'ADC0:SYS_GPA_MFP_PA0_ADC0@GPA_MFP', 'SC0_PWR:SYS_GPA_MFP_PA0_SC0_PWR@GPA_MFP/SYS_ALT_MFP1_PA0_SC0_PWR@ALT_MFP1'] },
	{ f: ['PA.1', 'ADC1:SYS_GPA_MFP_PA1_ADC1@GPA_MFP', 'SC0_RST:SYS_GPA_MFP_PA1_SC0_RST@GPA_MFP/SYS_ALT_MFP1_PA1_SC0_RST@ALT_MFP1'] },
	{ f: ['PA.2', 'ADC2:SYS_GPA_MFP_PA2_ADC2@GPA_MFP', 'SC0_CLK:SYS_GPA_MFP_PA2_SC0_CLK@GPA_MFP/SYS_ALT_MFP1_PA2_SC0_CLK@ALT_MFP1'] },
	{ f: ['PA.3', 'ADC3:SYS_GPA_MFP_PA3_ADC3@GPA_MFP', 'SC0_DAT:SYS_GPA_MFP_PA3_SC0_DAT@GPA_MFP/SYS_ALT_MFP1_PA3_SC0_DAT@ALT_MFP1'] },
	{ f: ['PA.4', 'ADC4:SYS_GPA_MFP_PA4_ADC4@GPA_MFP', 'SC1_PWR:SYS_GPA_MFP_PA4_SC1_PWR@GPA_MFP/SYS_ALT_MFP1_PA4_SC1_PWR@ALT_MFP1'] },
	{ f: ['PA.5', 'ADC5:SYS_GPA_MFP_PA5_ADC5@GPA_MFP', 'SC1_RST:SYS_GPA_MFP_PA5_SC1_RST@GPA_MFP/SYS_ALT_MFP1_PA5_SC1_RST@ALT_MFP1'] },
	{ f: ['PA.6', 'ADC6:SYS_GPA_MFP_PA6_ADC6@GPA_MFP', 'SC1_CLK:SYS_GPA_MFP_PA6_SC1_CLK@GPA_MFP/SYS_ALT_MFP1_PA6_SC1_CLK@ALT_MFP1'] },
	{ f: ['PA.7', 'ADC7:SYS_GPA_MFP_PA7_ADC7@GPA_MFP', 'SPI2_SS1:SYS_GPA_MFP_PA7_SPI2_SS1@GPA_MFP/SYS_ALT_MFP_PA7_SPI2_SS1@ALT_MFP', 'SC1_DAT:SYS_GPA_MFP_PA7_SC1_DAT@GPA_MFP/SYS_ALT_MFP1_PA7_SC1_DAT@ALT_MFP1'] },
	{ f: ['PA.8', 'I2C0_SDA:SYS_GPA_MFP_PA8_I2C0_SDA@GPA_MFP'] },
	{ f: ['PA.9', 'I2C0_SCL:SYS_GPA_MFP_PA9_I2C0_SCL@GPA_MFP'] },
	{ f: ['PA.10', 'I2C1_SDA:SYS_GPA_MFP_PA10_I2C1_SDA@GPA_MFP'] },
	{ f: ['PA.11', 'I2C1_SCL:SYS_GPA_MFP_PA11_I2C1_SCL@GPA_MFP'] },
	{ f: ['PA.12', 'PWM0:SYS_GPA_MFP_PA12_PWM0@GPA_MFP', 'SC2_DAT:SYS_GPA_MFP_PA12_SC2_DAT@GPA_MFP/SYS_ALT_MFP1_PA12_SC2_DAT@ALT_MFP1'] },
	{ f: ['PA.13', 'PWM1:SYS_GPA_MFP_PA13_PWM1@GPA_MFP', 'SC2_CLK:SYS_GPA_MFP_PA13_SC2_CLK@GPA_MFP/SYS_ALT_MFP1_PA13_SC2_CLK@ALT_MFP1'] },
	{ f: ['PA.14', 'PWM2:SYS_GPA_MFP_PA14_PWM2@GPA_MFP', 'SC2_RST:SYS_GPA_MFP_PA14_SC2_RST@GPA_MFP/SYS_ALT_MFP1_PA14_SC2_RST@ALT_MFP1'] },
	{ f: ['PA.15', 'PWM3:SYS_GPA_MFP_PA15_PWM3@GPA_MFP', 'I2S_MCLK:SYS_GPA_MFP_PA15_I2S_MCLK@GPA_MFP/SYS_ALT_MFP_PA15_I2S_MCLK@ALT_MFP', 'SC2_PWR:SYS_GPA_MFP_PA15_SC2_PWR@GPA_MFP/SYS_ALT_MFP1_PA15_SC2_PWR@ALT_MFP1'] },

	{ f: ['PB.0', 'UART0_RXD:SYS_GPB_MFP_PB0_UART0_RXD@GPB_MFP'] },
	{ f: ['PB.1', 'UART0_TXD:SYS_GPB_MFP_PB1_UART0_TXD@GPB_MFP'] },
	{ f: ['PB.2', 'UART0_nRTS:SYS_GPB_MFP_PB2_UART0_nRTS@GPB_MFP', 'TM2_EXT:SYS_GPB_MFP_PB2_TM2_EXT@GPB_MFP/SYS_ALT_MFP_PB2_TM2_EXT@ALT_MFP', 'ACMP0_O:SYS_GPB_MFP_PB2_ACMP0_O@GPB_MFP/SYS_ALT_MFP_PB2_ACMP0_O@ALT_MFP', 'CMP0_O:SYS_GPB_MFP_PB2_CMP0_O@GPB_MFP/SYS_ALT_MFP_PB2_CMP0_O@ALT_MFP'] },
	{ f: ['PB.3', 'UART0_nCTS:SYS_GPB_MFP_PB3_UART0_nCTS@GPB_MFP', 'TM3_EXT:SYS_GPB_MFP_PB3_TM3_EXT@GPB_MFP/SYS_ALT_MFP_PB3_TM3_EXT@ALT_MFP', 'SC2_CD:SYS_GPB_MFP_PB3_SC2_CD@GPB_MFP/SYS_ALT_MFP1_PB3_SC2_CD@ALT_MFP1'] },
	{ f: ['PB.4', 'UART1_RXD:SYS_GPB_MFP_PB4_UART1_RXD@GPB_MFP'] },
	{ f: ['PB.5', 'UART1_TXD:SYS_GPB_MFP_PB5_UART1_TXD@GPB_MFP'] },
	{ f: ['PB.6', 'UART1_nRTS:SYS_GPB_MFP_PB6_UART1_nRTS@GPB_MFP'] },
	{ f: ['PB.7', 'UART1_nCTS:SYS_GPB_MFP_PB7_UART1_nCTS@GPB_MFP'] },
	{ f: ['PB.8', 'TM0:SYS_GPB_MFP_PB8_TM0@GPB_MFP', 'CLKO:SYS_GPB_MFP_PB8_CLKO@GPB_MFP/SYS_ALT_MFP_PB8_CLKO@ALT_MFP'] },
	{ f: ['PB.9', 'TM1:SYS_GPB_MFP_PB9_TM1@GPB_MFP', 'SPI1_SS1:SYS_GPB_MFP_PB9_SPI1_SS1@GPB_MFP/SYS_ALT_MFP_PB9_SPI1_SS1@ALT_MFP'] },
	{ f: ['PB.10', 'TM2:SYS_GPB_MFP_PB10_TM2@GPB_MFP', 'SPI0_SS1:SYS_GPB_MFP_PB10_SPI0_SS1@GPB_MFP/SYS_ALT_MFP_PB10_SPI0_SS1@ALT_MFP'] },
	{ f: ['PB.11', 'TM3:SYS_GPB_MFP_PB11_TM3@GPB_MFP', 'PWM4:SYS_GPB_MFP_PB11_PWM4@GPB_MFP/SYS_ALT_MFP_PB11_PWM4@ALT_MFP'] },
	{ f: ['PB.12'] },
	{ f: ['PB.13', 'ACMP1_O:SYS_GPB_MFP_PB13_ACMP1_O@GPB_MFP', 'CMP1_O:SYS_GPB_MFP_PB13_CMP1_O@GPB_MFP'] },
	{ f: ['PB.14', 'INT0:SYS_GPB_MFP_PB14_INT0@GPB_MFP', 'SPI3_SS1:SYS_GPB_MFP_PB14_SPI3_SS1@GPB_MFP/SYS_ALT_MFP_PB14_SPI3_SS1@ALT_MFP'] },
	{ f: ['PB.15', 'INT1:SYS_GPB_MFP_PB15_INT1@GPB_MFP', 'TM0_EXT:SYS_GPB_MFP_PB15_TM0_EXT@GPB_MFP/SYS_ALT_MFP_PB15_TM0_EXT@ALT_MFP'] },

	{ f: ['PC.0', 'SPI0_SS0:SYS_GPC_MFP_PC0_SPI0_SS0@GPC_MFP', 'I2S_LRCLK:SYS_GPC_MFP_PC0_I2S_LRCLK@GPC_MFP/SYS_ALT_MFP_PC0_I2S_LRCLK@ALT_MFP', 'I2S_LRCK:SYS_GPC_MFP_PC0_I2S_LRCK@GPC_MFP/SYS_ALT_MFP_PC0_I2S_LRCK@ALT_MFP'] },
	{ f: ['PC.1', 'SPI0_CLK:SYS_GPC_MFP_PC1_SPI0_CLK@GPC_MFP', 'I2S_BCLK:SYS_GPC_MFP_PC1_I2S_BCLK@GPC_MFP/SYS_ALT_MFP_PC1_I2S_BCLK@ALT_MFP'] },
	{ f: ['PC.2', 'SPI0_MISO0:SYS_GPC_MFP_PC2_SPI0_MISO0@GPC_MFP', 'I2S_DI:SYS_GPC_MFP_PC2_I2S_DI@GPC_MFP/SYS_ALT_MFP_PC2_I2S_DI@ALT_MFP'] },
	{ f: ['PC.3', 'SPI0_MOSI0:SYS_GPC_MFP_PC3_SPI0_MOSI0@GPC_MFP', 'I2S_DO:SYS_GPC_MFP_PC3_I2S_DO@GPC_MFP/SYS_ALT_MFP_PC3_I2S_DO@ALT_MFP'] },
	{ f: ['PC.4', 'SPI0_MISO1:SYS_GPC_MFP_PC4_SPI0_MISO1@GPC_MFP'] },
	{ f: ['PC.5', 'SPI0_MOSI1:SYS_GPC_MFP_PC5_SPI0_MOSI1@GPC_MFP'] },
	{ f: ['PC.6', 'ACMP0_P:SYS_GPC_MFP_PC6_ACMP0_P@GPC_MFP', 'CMP0_P:SYS_GPC_MFP_PC6_CMP0_P@GPC_MFP', 'SC0_CD:SYS_GPC_MFP_PC6_SC0_CD@GPC_MFP/SYS_ALT_MFP1_PC6_SC0_CD@ALT_MFP1'] },
	{ f: ['PC.7', 'ACMP0_N:SYS_GPC_MFP_PC7_ACMP0_N@GPC_MFP', 'CMP0_N:SYS_GPC_MFP_PC7_CMP0_N@GPC_MFP', 'SC1_CD:SYS_GPC_MFP_PC7_SC1_CD@GPC_MFP/SYS_ALT_MFP1_PC7_SC1_CD@ALT_MFP1'] },
	{ f: ['PC.8', 'SPI1_SS0:SYS_GPC_MFP_PC8_SPI1_SS0@GPC_MFP'] },
	{ f: ['PC.9', 'SPI1_CLK:SYS_GPC_MFP_PC9_SPI1_CLK@GPC_MFP'] },
	{ f: ['PC.10', 'SPI1_MISO0:SYS_GPC_MFP_PC10_SPI1_MISO0@GPC_MFP'] },
	{ f: ['PC.11', 'SPI1_MOSI0:SYS_GPC_MFP_PC11_SPI1_MOSI0@GPC_MFP'] },
	{ f: ['PC.12', 'SPI1_MISO1:SYS_GPC_MFP_PC12_SPI1_MISO1@GPC_MFP'] },
	{ f: ['PC.13', 'SPI1_MOSI1:SYS_GPC_MFP_PC13_SPI1_MOSI1@GPC_MFP'] },
	{ f: ['PC.14', 'ACMP1_P:SYS_GPC_MFP_PC14_ACMP1_P@GPC_MFP', 'CMP1_P:SYS_GPC_MFP_PC14_CMP1_P@GPC_MFP'] },
	{ f: ['PC.15', 'ACMP1_N:SYS_GPC_MFP_PC15_ACMP1_N@GPC_MFP', 'CMP1_N:SYS_GPC_MFP_PC15_CMP1_N@GPC_MFP'] },

	{ f: ['PD.0', 'SPI2_SS0:SYS_GPD_MFP_PD0_SPI2_SS0@GPD_MFP'] },
	{ f: ['PD.1', 'SPI2_CLK:SYS_GPD_MFP_PD1_SPI2_CLK@GPD_MFP'] },
	{ f: ['PD.2', 'SPI2_MISO0:SYS_GPD_MFP_PD2_SPI2_MISO0@GPD_MFP'] },
	{ f: ['PD.3', 'SPI2_MOSI0:SYS_GPD_MFP_PD3_SPI2_MOSI0@GPD_MFP'] },
	{ f: ['PD.4', 'SPI2_MISO1:SYS_GPD_MFP_PD4_SPI2_MISO1@GPD_MFP'] },
	{ f: ['PD.5', 'SPI2_MOSI1:SYS_GPD_MFP_PD5_SPI2_MOSI1@GPD_MFP'] },
	{ f: ['PD.6'] },
	{ f: ['PD.7'] },
	{ f: ['PD.8', 'SPI3_SS0:SYS_GPD_MFP_PD8_SPI3_SS0@GPD_MFP'] },
	{ f: ['PD.9', 'SPI3_CLK:SYS_GPD_MFP_PD9_SPI3_CLK@GPD_MFP'] },
	{ f: ['PD.10', 'SPI3_MISO0:SYS_GPD_MFP_PD10_SPI3_MISO0@GPD_MFP'] },
	{ f: ['PD.11', 'SPI3_MOSI0:SYS_GPD_MFP_PD11_SPI3_MOSI0@GPD_MFP'] },
	{ f: ['PD.12', 'SPI3_MISO1:SYS_GPD_MFP_PD12_SPI3_MISO1@GPD_MFP'] },
	{ f: ['PD.13', 'SPI3_MOSI1:SYS_GPD_MFP_PD13_SPI3_MOSI1@GPD_MFP'] },
	{ f: ['PD.14', 'UART2_RXD:SYS_GPD_MFP_PD14_UART2_RXD@GPD_MFP'] },
	{ f: ['PD.15', 'UART2_TXD:SYS_GPD_MFP_PD15_UART2_TXD@GPD_MFP'] },

	{ f: ['PE.0', 'PWM6:SYS_GPE_MFP_PE0_PWM6@GPE_MFP'] },
	{ f: ['PE.1', 'PWM7:SYS_GPE_MFP_PE1_PWM7@GPE_MFP'] },
	{ f: ['PE.2'] },
	{ f: ['PE.3'] },
	{ f: ['PE.4'] },
	{ f: ['PE.5', 'PWM5:SYS_GPE_MFP_PE5_PWM5@GPE_MFP', 'TM1_EXT:SYS_GPE_MFP_PE5_TM1_EXT@GPE_MFP/SYS_ALT_MFP_PE5_TM1_EXT@ALT_MFP'] },
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
	{ f: ['PF.2', 'PS2_DAT:SYS_GPF_MFP_PF2_PS2_DAT@GPF_MFP'] },
	{ f: ['PF.3', 'PS2_CLK:SYS_GPF_MFP_PF3_PS2_CLK@GPF_MFP'] }
];

NUTOOL_PIN.g_cfg_gpiosDescriptions = [
	'ACMP0_N:Comparator0 negative input pin',
	'ACMP0_O:Comparator0 output pin',
	'ACMP0_P:Comparator0 positive input pin',
	'ACMP1_N:Comparator1 negative input pin',
	'ACMP1_O:Comparator1 output pin',
	'ACMP1_P:Comparator1 positive input pin',

	'ADC0:ADC0 analog input',
	'ADC1:ADC1 analog input',
	'ADC2:ADC2 analog input',
	'ADC3:ADC3 analog input',
	'ADC4:ADC4 analog input',
	'ADC5:ADC5 analog input',
	'ADC6:ADC6 analog input',
	'ADC7:ADC7 analog input',

	'AVDD:Power supply for internal analog circuit',
	'AVSS:Ground pin for analog circuit',

	'CLKO:Frequency divider clock output pin',

	'I2C0_SCL:I2C0 clock pin',
	'I2C0_SDA:I2C0 data input/output pin',
	'I2C1_SCL:I2C1 clock pin',
	'I2C1_SDA:I2C1 data input/output pin',

	'I2S_BCLK:I2S bit clock pin',
	'I2S_DI:I2S data input',
	'I2S_DO:I2S data output',
	'I2S_LRCLK:I2S left right channel clock',
	'I2S_MCLK:I2S master clock output pin',

	'ICE_CLK:Serial wire debugger clock pin',
	'ICE_DAT:Serial wire debugger data pin',

	'INT0:External interrupt0 input pin',
	'INT1:External interrupt1 input pin',

	'LDO_CAP:LDO output pin',

	'nRESET:External reset input: active LOW, with an internal pull-up. Set this pin low reset chip to initial state',

	'PS2_CLK:PS/2 clock pin',
	'PS2_DAT:PS/2 data pin',

	'PVSS:PLL ground',

	'PWM0:PWM0 output/Capture input',
	'PWM1:PWM1 output/Capture input',
	'PWM2:PWM2 output/Capture input',
	'PWM3:PWM3 output/Capture input',
	'PWM4:PWM4 output/Capture input',
	'PWM5:PWM5 output/Capture input',
	'PWM6:PWM6 output/Capture input',
	'PWM7:PWM7 output/Capture input',

	'SC0_CD:SmartCard0 card detect pin',
	'SC0_CLK:SmartCard0 clock pin',
	'SC0_DAT:SmartCard0 data pin',
	'SC0_PWR:SmartCard0 power pin',
	'SC0_RST:SmartCard0 reset pin',
	'SC1_CD:SmartCard1 card detect pin',
	'SC1_CLK:SmartCard1 clock pin',
	'SC1_DAT:SmartCard1 data pin',
	'SC1_PWR:SmartCard1 power pin',
	'SC1_RST:SmartCard1 reset pin',
	'SC2_CD:SmartCard2 card detect pin',
	'SC2_CLK:SmartCard2 clock pin',
	'SC2_DAT:SmartCard2 data pin',
	'SC2_PWR:SmartCard2 power pin',
	'SC2_RST:SmartCard2 reset pin',

	'SPI0_CLK:SPI0 serial clock pin',
	'SPI0_MISO0:1st SPI0 MISO (Master In, Slave Out) pin',
	'SPI0_MISO1:2nd SPI0 MISO (Master In, Slave Out) pin',
	'SPI0_MOSI0:1st SPI0 MOSI (Master Out, Slave In) pin',
	'SPI0_MOSI1:2nd SPI0 MOSI (Master Out, Slave In) pin',
	'SPI0_SS0:1st SPI0 slave select pin',
	'SPI0_SS1:2nd SPI0 slave select pin',
	'SPI1_CLK:SPI1 serial clock pin',
	'SPI1_MISO0:1st SPI1 MISO (Master In, Slave Out) pin',
	'SPI1_MISO1:2nd SPI1 MISO (Master In, Slave Out) pin',
	'SPI1_MOSI0:1st SPI1 MOSI (Master Out, Slave In) pin',
	'SPI1_MOSI1:2nd SPI1 MOSI (Master Out, Slave In) pin',
	'SPI1_SS0:1st SPI1 slave select pin',
	'SPI1_SS1:2nd SPI1 slave select pin',
	'SPI2_CLK:SPI2 serial clock pin',
	'SPI2_MISO0:1st SPI2 MISO (Master In, Slave Out) pin',
	'SPI2_MISO1:2nd SPI2 MISO (Master In, Slave Out) pin',
	'SPI2_MOSI0:1st SPI2 MOSI (Master Out, Slave In) pin',
	'SPI2_MOSI1:2nd SPI2 MOSI (Master Out, Slave In) pin',
	'SPI2_SS0:1st SPI2 slave select pin',
	'SPI2_SS1:2nd SPI2 slave select pin',
	'SPI3_CLK:SPI3 serial clock pin',
	'SPI3_MISO0:1st SPI3 MISO (Master In, Slave Out) pin',
	'SPI3_MISO1:2nd SPI3 MISO (Master In, Slave Out) pin',
	'SPI3_MOSI0:1st SPI3 MOSI (Master Out, Slave In) pin',
	'SPI3_MOSI1:2nd SPI3 MOSI (Master Out, Slave In) pin',
	'SPI3_SS0:1st SPI3 slave select pin',
	'SPI3_SS1:2nd SPI3 slave select pin',

	'STADC:ADC external trigger input',

	'TM0:Timer0 event counter input / toggle output',
	'TM0_EXT:Timer0 external capture input pin',
	'TM1:Timer1 event counter input / toggle output',
	'TM1_EXT:Timer1 external capture input pin',
	'TM2:Timer2 event counter input / toggle output',
	'TM2_EXT:Timer2 external capture input pin',
	'TM3:Timer3 event counter input / toggle output',
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

	'USB_D-:USB differential signal D-',
	'USB_D+:USB differential signal D+',
	'USB_VBUS:Power supply from USB host or HUB',
	'USB_VDD33_CAP:Internal power regulator output 3.3V decoupling pin',

	'VBAT:Power supply by batteries for RTC',
	'VDD:Power supply for I/O ports and LDO source for internal PLL and digital circuit',
	'VREF:Voltage reference input for ADC',
	'VSS :Ground pin for digital circuit',
	'VSS:Ground pin for digital circuit',

	'X32_IN:External 32.768 kHz (low speed) crystal input pin',
	'X32_OUT:External 32.768 kHz (low speed) crystal output pin',

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
NUTOOL_PIN.g_cfg_regDescriptions.ALT_MFP1 = '0x50000058';

NUTOOL_PIN.g_cfg_gpioMatrix = [
	{ f: ['PA.0', 'GPA_MFP[0]:0', 'ALT_MFP1[2]:1'] },
	{ f: ['PA.1', 'GPA_MFP[1]:0', 'ALT_MFP1[3]:1'] },
	{ f: ['PA.2', 'GPA_MFP[2]:0', 'ALT_MFP1[0]:1'] },
	{ f: ['PA.3', 'GPA_MFP[3]:0', 'ALT_MFP1[1]:1'] },
	{ f: ['PA.4', 'GPA_MFP[4]:0', 'ALT_MFP1[7]:1'] },
	{ f: ['PA.5', 'GPA_MFP[5]:0', 'ALT_MFP1[8]:1'] },
	{ f: ['PA.6', 'GPA_MFP[6]:0', 'ALT_MFP1[5]:1'] },
	{ f: ['PA.7', 'GPA_MFP[7]:0', 'ALT_MFP[2]:1', 'ALT_MFP1[6]:2'] },
	{ f: ['PA.8', 'GPA_MFP[8]:0'] },
	{ f: ['PA.9', 'GPA_MFP[9]:0'] },
	{ f: ['PA.10', 'GPA_MFP[10]:0'] },
	{ f: ['PA.11', 'GPA_MFP[11]:0'] },
	{ f: ['PA.12', 'GPA_MFP[12]:0', 'ALT_MFP1[11]:1'] },
	{ f: ['PA.13', 'GPA_MFP[13]:0', 'ALT_MFP1[10]:1'] },
	{ f: ['PA.14', 'GPA_MFP[14]:0', 'ALT_MFP1[13]:1'] },
	{ f: ['PA.15', 'GPA_MFP[15]:0', 'ALT_MFP[9]:1', 'ALT_MFP1[12]:2'] },

	{ f: ['PB.0', 'GPB_MFP[0]:0'] },
	{ f: ['PB.1', 'GPB_MFP[1]:0'] },
	{ f: ['PB.2', 'GPB_MFP[2]:0', 'ALT_MFP[26]:1', 'ALT_MFP[30]:2'] },
	{ f: ['PB.3', 'GPB_MFP[3]:0', 'ALT_MFP[27]:1', 'ALT_MFP1[14]:2'] },
	{ f: ['PB.4', 'GPB_MFP[4]:0'] },
	{ f: ['PB.5', 'GPB_MFP[5]:0'] },
	{ f: ['PB.6', 'GPB_MFP[6]:0'] },
	{ f: ['PB.7', 'GPB_MFP[7]:0'] },
	{ f: ['PB.8', 'GPB_MFP[8]:0', 'ALT_MFP[29]:1'] },
	{ f: ['PB.9', 'GPB_MFP[9]:0', 'ALT_MFP[1]:1'] },
	{ f: ['PB.10', 'GPB_MFP[10]:0', 'ALT_MFP[0]:1'] },
	{ f: ['PB.11', 'GPB_MFP[11]:0', 'ALT_MFP[4]:1'] },
	{ f: ['PB.12'] },
	{ f: ['PB.13', 'GPB_MFP[13]:0'] },
	{ f: ['PB.14', 'GPB_MFP[14]:0', 'ALT_MFP[3]:1'] },
	{ f: ['PB.15', 'GPB_MFP[15]:0', 'ALT_MFP[24]:1'] },

	{ f: ['PC.0', 'GPC_MFP[0]:0', 'ALT_MFP[5]:1'] },
	{ f: ['PC.1', 'GPC_MFP[1]:0', 'ALT_MFP[6]:1'] },
	{ f: ['PC.2', 'GPC_MFP[2]:0', 'ALT_MFP[7]:1'] },
	{ f: ['PC.3', 'GPC_MFP[3]:0', 'ALT_MFP[8]:1'] },
	{ f: ['PC.4', 'GPC_MFP[4]:0'] },
	{ f: ['PC.5', 'GPC_MFP[5]:0'] },
	{ f: ['PC.6', 'GPC_MFP[6]:0', 'ALT_MFP1[4]:1'] },
	{ f: ['PC.7', 'GPC_MFP[7]:0', 'ALT_MFP1[9]:1'] },
	{ f: ['PC.8', 'GPC_MFP[8]:0'] },
	{ f: ['PC.9', 'GPC_MFP[9]:0'] },
	{ f: ['PC.10', 'GPC_MFP[10]:0'] },
	{ f: ['PC.11', 'GPC_MFP[11]:0'] },
	{ f: ['PC.12', 'GPC_MFP[12]:0'] },
	{ f: ['PC.13', 'GPC_MFP[13]:0'] },
	{ f: ['PC.14', 'GPC_MFP[14]:0'] },
	{ f: ['PC.15', 'GPC_MFP[15]:0'] },

	{ f: ['PD.0', 'GPD_MFP[0]:0'] },
	{ f: ['PD.1', 'GPD_MFP[1]:0'] },
	{ f: ['PD.2', 'GPD_MFP[2]:0'] },
	{ f: ['PD.3', 'GPD_MFP[3]:0'] },
	{ f: ['PD.4', 'GPD_MFP[4]:0'] },
	{ f: ['PD.5', 'GPD_MFP[5]:0'] },
	{ f: ['PD.6'] },
	{ f: ['PD.7'] },
	{ f: ['PD.8', 'GPD_MFP[8]:0'] },
	{ f: ['PD.9', 'GPD_MFP[9]:0'] },
	{ f: ['PD.10', 'GPD_MFP[10]:0'] },
	{ f: ['PD.11', 'GPD_MFP[11]:0'] },
	{ f: ['PD.12', 'GPD_MFP[12]:0'] },
	{ f: ['PD.13', 'GPD_MFP[13]:0'] },
	{ f: ['PD.14', 'GPD_MFP[14]:0'] },
	{ f: ['PD.15', 'GPD_MFP[15]:0'] },

	{ f: ['PE.0', 'GPE_MFP[0]:0'] },
	{ f: ['PE.1', 'GPE_MFP[1]:0'] },
	{ f: ['PE.2'] },
	{ f: ['PE.3'] },
	{ f: ['PE.4'] },
	{ f: ['PE.5', 'GPE_MFP[5]:0', 'ALT_MFP[25]:1'] },
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
	{ f: ['PF.2', 'GPF_MFP[2]:0'] },
	{ f: ['PF.3', 'GPF_MFP[3]:0'] }
];

NUTOOL_PIN.g_cfg_shareBits = [];
NUTOOL_PIN.g_cfg_addGPIO = {};
NUTOOL_PIN.g_cfg_unusedGPIO = {
	"NUC200SC2AN(LQFP64)": {
		"PB.14": ["SPI3_SS1"],
		"PB.10": ["SPI0_SS1"],
		"PB.9": ["SPI1_SS1"],
		"PA.4": ["SC1_PWR"],
		"PA.5": ["SC1_RST"],
		"PA.6": ["SC1_CLK"],
		"PC.7": ["SC1_CD"]
	},
	"NUC200SD2AN(LQFP64)": function () {
		return this["NUC200SC2AN(LQFP64)"];
	},
	"NUC200SE3AN(LQFP64)": function () {
		return this["NUC200SC2AN(LQFP64)"];
	},
	"NUC200LC2AN(LQFP48)": {
		"PB.10": ["SPI0_SS1"],
		"PB.9": ["SPI1_SS1"],
		"PA.4": ["SC1_PWR"],
		"PA.5": ["SC1_RST"],
		"PA.6": ["SC1_CLK"],
		"PC.7": ["SC1_CD"]
	},
	"NUC200LD2AN(LQFP48)": function () {
		return this["NUC200LC2AN(LQFP48)"];
	},
	"NUC200LE3AN(LQFP48)": function () {
		return this["NUC200LC2AN(LQFP48)"];
	},
	"NUC220SC2AN(LQFP64)": {
		"PB.14": ["SPI3_SS1"],
		"PB.10": ["SPI0_SS1"],
		"PB.9": ["SPI1_SS1"],
		"PA.4": ["SC1_PWR"],
		"PA.5": ["SC1_RST"],
		"PA.6": ["SC1_CLK"],
		"PC.7": ["SC1_CD"]
	},
	"NUC220SD2AN(LQFP64)": function () {
		return this["NUC220SC2AN(LQFP64)"];
	},
	"NUC220SE3AN(LQFP64)": function () {
		return this["NUC220SC2AN(LQFP64)"];
	},
	"NUC220LC2AN(LQFP48)": {
		"PA.4": ["SC1_PWR"],
		"PA.5": ["SC1_RST"],
		"PA.6": ["SC1_CLK"],
		"PC.7": ["SC1_CD"]
	},
	"NUC220LD2AN(LQFP48)": function () {
		return this["NUC220LC2AN(LQFP48)"];
	},
	"NUC220LE3AN(LQFP48)": function () {
		return this["NUC220LC2AN(LQFP48)"];
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
	NUTOOL_PIN.g_packageNumberIndex = NUTOOL_PIN.g_packageNumber + '(' + partNumber_package.slice(0, 6) + ')';

	partNumber_package = null;
};
