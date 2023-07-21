// chip content
NUTOOL_PIN.g_cfg_chips = [
	//NUC505
	{ name: "NUC505YO13Y", pkg: "QFN88" },
	//{ name: "NUC505DR13Y", pkg: "LQFP64" },
	{ name: "NUC505DS13Y", pkg: "LQFP64" },
	{ name: "NUC505DSA", pkg: "LQFP64" },
	{ name: "NUC505DL13Y", pkg: "LQFP48" },
	{ name: "NUC505DLA", pkg: "LQFP48" },
	{ name: "NUC505YLA2Y", pkg: "QFN48" },
	{ name: "NUC505YLA", pkg: "QFN48" }
];

NUTOOL_PIN.g_cfg_pkgs = {
	"QFN88": [
		'nRESET', 'PD.0', 'PD.1', 'PB.13', 'PB.14', 'PB.15', 'PC.0', 'PC.1', 'PC.2', 'VDD',
		'PC.3', 'PC.4', 'PC.5', 'PC.6', 'VDD12', 'XT1_IN', 'XT1_OUT', 'VDD12', 'USB_D-', 'USB_D+',
		'AVDDUSB', 'USB_REXT',
		'VBAT', 'RTC_RPWR', 'RTC_nRWAKE', 'X32_IN', 'X32_OUT', 'PA.8', 'PA.9', 'PA.10', 'PA.11', 'PA.12',
		'PA.13', 'PA.14', 'PA.15', 'PC.7', 'PC.8', 'PC.9', 'PC.10', 'VDD', 'PB.0', 'PB.1',
		'PB.2', 'PB.3',
		'PB.4', 'PB.5', 'PB.6', 'PB.7', 'USB_VBUS', 'PB.8', 'PB.9', 'VDD', 'AVDDHP', 'LHPOUT',
		'VCMBF', 'RHPOUT', 'AVSSHP', 'VMID', 'AVDDCODEC', 'MIC0_P', 'MIC0_N', 'MIC_BIAS', 'VDD12', 'PD.2',
		'PD.3', 'PD.4',
		'AVDDADC', 'AVSSADC', 'PA.0', 'PA.1', 'PA.2', 'PA.3', 'PA.4', 'PA.5', 'PA.6', 'PA.7',
		'VDD12', 'PB.10', 'PB.11', 'PB.12', 'VDD', 'PC.11', 'PC.12', 'PC.13', 'PC.14', 'VDD',
		'LDO_CAP', 'VSS'
	],
	"LQFP64_0": [
		'nRESET', 'PD.0', 'PD.1', 'PB.13', 'PB.14', 'PB.15', 'PC.0', 'VDD', 'VSS', 'XT1_IN',
		'XT1_OUT', 'VDD12', 'USB_D-', 'USB_D+', 'AVDDUSB', 'USB_REXT',
		'VBAT', 'RTC_RPWR', 'RTC_nRWAKE', 'PA.8', 'PA.9', 'PA.10', 'PA.11', 'PA.12', 'PA.13', 'PA.14',
		'PA.15', 'VDD', 'PB.0', 'PB.1', 'PB.2', 'PB.3',
		'PB.4', 'PB.5', 'PB.6', 'PB.7', 'USB_VBUS', 'PB.8', 'PB.9', 'VSS', 'AVDDHP', 'LHPOUT',
		'RHPOUT', 'AVSSHP', 'VMID', 'AVDDCODEC', 'AVDDADC', 'AVSSADC',
		'PA.0', 'PA.1', 'PA.2', 'PA.3', 'PA.4', 'PA.5', 'PA.6', 'PA.7', 'VDD12', 'PB.10',
		'PB.11', 'PB.12', 'VDD', 'VDD', 'LDO_CAP', 'VSS'
	],
	"LQFP64_1": [
		'nRESET', 'PD.0', 'PD.1', 'PB.13', 'PB.14', 'PB.15', 'PC.0', 'VDD', 'VSS', 'XT1_IN',
		'XT1_OUT', 'VDD12', 'USB_D-', 'USB_D+', 'AVDDUSB', 'USB_REXT',
		'PA.8', 'PA.9', 'PA.10', 'PA.11', 'PA.12', 'PA.13', 'PA.14', 'PA.15', 'PC.8', 'PC.9',
		'PC.10', 'VDD', 'PB.0', 'PB.1', 'PB.2', 'PB.3',
		'PB.4', 'PB.5', 'USB_VBUS', 'VSS', 'AVDDHP', 'LHPOUT', 'RHPOUT', 'AVSSHP', 'VMID', 'AVDDCODEC',
		'MIC0_P', 'MIC0_N', 'MIC_BIAS', 'VDD12', 'PD.4', 'AVDDADC',
		'AVSSADC', 'PA.0', 'PA.1', 'PA.2', 'PA.3', 'PA.4', 'VDD12', 'PB.10', 'PB.11', 'PB.12',
		'VDD', 'PC.11', 'PC.12', 'VDD', 'LDO_CAP', 'VSS'
	],
	"LQFP48(CODEC)": [
		'nRESET', 'PD.0', 'PD.1', 'PB.14', 'PB.15', 'VDD', 'XT1_IN', 'XT1_OUT', 'VDD12', 'USB_D-',
		'USB_D+', 'AVDDUSB',
		'USB_REXT', 'PA.8', 'PA.9', 'PA.10', 'PA.11', 'VDD', 'PB.0', 'PB.1', 'PB.2', 'PB.3',
		'PB.4', 'PB.5',
		'USB_VBUS', 'VSS', 'AVDDHP', 'LHPOUT', 'RHPOUT', 'AVSSHP', 'VMID', 'AVDDCODEC', 'MIC0_P', 'MIC0_N',
		'MIC_BIAS', 'VDD12',
		'PD.4', 'AVDDADC', 'AVSSADC', 'PA.0', 'PA.1', 'PA.2', 'PA.3', 'PA.4', 'VDD12', 'VDD',
		'LDO_CAP', 'VSS'
	],
	"LQFP48": [
		'nRESET', 'PD.0', 'PD.1', 'PB.13', 'VDD', 'VSS', 'XT1_IN', 'XT1_OUT', 'VDD12', 'USB_D-',
		'USB_D+', 'AVDDUSB',
		'USB_REXT', 'VBAT', 'RTC_RPWR', 'RTC_nRWAKE', 'PA.8', 'PA.9', 'PA.10', 'PA.11', 'VDD', 'PB.0',
		'PB.1', 'PB.2',
		'PB.3', 'PB.4', 'PB.5', 'PB.6', 'PB.7', 'USB_VBUS', 'PB.8', 'PB.9', 'VSS', 'AVDDADC',
		'AVSSADC', 'PA.0',
		'PA.1', 'PA.2', 'PA.3', 'PA.4', 'VDD12', 'PB.10', 'PB.11', 'PB.12', 'VDD', 'VDD',
		'LDO_CAP', 'VSS'
	]
};

NUTOOL_PIN.g_cfg_OrCAD = {};

NUTOOL_PIN.g_cfg_gpios = [
	{ f: ['PA.0:0', 'ADC_CH0:1'] },
	{ f: ['PA.1:0', 'ADC_CH1:1'] },
	{ f: ['PA.2:0', 'ADC_CH2:1', 'I2S_MCLK:2'] },
	{ f: ['PA.3:0', 'ADC_CH3:1', 'I2S_DI:2'] },
	{ f: ['PA.4:0', 'ADC_CH4:1', 'I2S_DO:2'] },
	{ f: ['PA.5:0', 'ADC_CH5:1'] },
	{ f: ['PA.6:0', 'ADC_CH6:1'] },
	{ f: ['PA.7:0', 'ADC_CH7:1'] },
	{ f: ['PA.8:0', 'SPIM_SS:1', 'I2S_LRCLK:2', 'UART1_TXD:3'] },
	{ f: ['PA.9:0', 'SPIM_CLK:1', 'I2S_BCLK:2', 'UART1_RXD:3'] },
	{ f: ['PA.10:0', 'SPIM_MOSI:1', 'I2C1_SCL:2', 'SD_CLK:4'] },
	{ f: ['PA.11:0', 'SPIM_MISO:1', 'I2C1_SDA:2', 'SD_CMD:4'] },
	{ f: ['PA.12:0', 'SPIM_D2:1', 'TM0_CNT_OUT:2'] },
	{ f: ['PA.13:0', 'SPIM_D3:1', 'TM0_EXT:2', 'SD_nCD:4'] },
	{ f: ['PA.14:0', 'I2C0_SCL:2', 'SD_DAT0:4'] },
	{ f: ['PA.15:0', 'I2C0_SDA:2', 'SD_DAT1:4'] },

	{ f: ['PB.0:0', 'I2C0_SCL:2', 'UART0_TXD:3', 'SD_DAT2:4'] },
	{ f: ['PB.1:0', 'I2C0_SDA:2', 'UART0_RXD:3', 'SD_DAT3:4'] },
	{ f: ['PB.2:0', 'SPI0_SS:1', 'SD_CMD:4'] },
	{ f: ['PB.3:0', 'SPI0_CLK:1', 'SD_CLK:4'] },
	{ f: ['PB.4:0', 'SPI0_MOSI:1'] },
	{ f: ['PB.5:0', 'SPI0_MISO:1', 'SD_nCD:4'] },
	{ f: ['PB.6:0', 'UART1_TXD:3', 'SD_DAT0:4'] },
	{ f: ['PB.7:0', 'UART1_RXD:3', 'SD_DAT1:4'] },
	{ f: ['PB.8:0', 'USBH_PWEN:1', 'TM1_CNT_OUT:2', 'UART1_nCTS:3', 'SD_DAT2:4'] },
	{ f: ['PB.9:0', 'USBH_VOD:1', 'TM1_EXT:2', 'UART1_nRTS:3', 'SD_DAT3:4'] },
	{ f: ['PB.10:0', 'SPI1_SS:1', 'I2C1_SCL:2', 'UART2_TXD:3', 'PWM_CH0:4'] },
	{ f: ['PB.11:0', 'SPI1_CLK:1', 'I2C1_SDA:2', 'UART2_RXD:3', 'PWM_CH1:4'] },
	{ f: ['PB.12:0', 'SPI1_MOSI:1', 'USBH1_D+:2', 'UART2_nCTS:3', 'PWM_CH2:4'] },
	{ f: ['PB.13:0', 'SPI1_MISO:1', 'USBH1_D-:2', 'UART2_nRTS:3', 'PWM_CH3:4'] },
	{ f: ['PB.14:0', 'USBH1_D+:1', 'I2C1_SCL:2'] },
	{ f: ['PB.15:0', 'USBH1_D-:1', 'I2C1_SDA:2'] },

	{ f: ['PC.0:0', 'SD_CMD:1'] },
	{ f: ['PC.1:0', 'SD_CLK:1'] },
	{ f: ['PC.2:0', 'SD_nCD:1'] },
	{ f: ['PC.3:0'] },
	{ f: ['PC.4:0', 'SD_DAT0:1'] },
	{ f: ['PC.5:0', 'SD_DAT1:1'] },
	{ f: ['PC.6:0', 'SD_DAT2:1'] },
	{ f: ['PC.7:0', 'SD_DAT3:1'] },
	{ f: ['PC.8:0', 'I2S_MCLK:1'] },
	{ f: ['PC.9:0', 'I2S_DI:1', 'TM2_CNT_OUT:2', 'PWM_CH0:3'] },
	{ f: ['PC.10:0', 'I2S_DO:1', 'TM2_EXT:2', 'PWM_CH1:3'] },
	{ f: ['PC.11:0', 'I2S_LRCLK:1', 'TM3_CNT_OUT:2', 'PWM_CH2:3'] },
	{ f: ['PC.12:0', 'I2S_BCLK:1', 'TM3_EXT:2', 'PWM_CH3:3'] },
	{ f: ['PC.13:0', 'USBH2_D+:1'] },
	{ f: ['PC.14:0', 'USBH2_D-:1'] },
	{ f: ['PC.15:0'] },

	{ f: ['PD.0:0', 'ICE_CLK_IN_ICE_MODE:0', 'I2C0_SCL:2'] },
	{ f: ['PD.1:0', 'ICE_DAT_IN_ICE_MODE:0', 'I2C0_SDA:2'] },
	{ f: ['PD.2:0', 'MIC1_P:1'] },
	{ f: ['PD.3:0', 'MIC1_N:1'] },
	{ f: ['PD.4:0', 'RLINEIN:1'] }
];

NUTOOL_PIN.g_cfg_gpiosDefines = [
	{ f: ['PA.0', 'GPIO:SYS_GPA_MFPL_PA0MFP_GPIO@GPA_MFPL', 'ADC_CH0:SYS_GPA_MFPL_PA0MFP_ADC_CH0@GPA_MFPL'] },
	{ f: ['PA.1', 'GPIO:SYS_GPA_MFPL_PA1MFP_GPIO@GPA_MFPL', 'ADC_CH1:SYS_GPA_MFPL_PA1MFP_ADC_CH1@GPA_MFPL'] },
	{ f: ['PA.2', 'GPIO:SYS_GPA_MFPL_PA2MFP_GPIO@GPA_MFPL', 'ADC_CH2:SYS_GPA_MFPL_PA2MFP_ADC_CH2@GPA_MFPL', 'I2S_MCLK:SYS_GPA_MFPL_PA2MFP_I2S_MCLK@GPA_MFPL'] },
	{ f: ['PA.3', 'GPIO:SYS_GPA_MFPL_PA3MFP_GPIO@GPA_MFPL', 'ADC_CH3:SYS_GPA_MFPL_PA3MFP_ADC_CH3@GPA_MFPL', 'I2S_DI:SYS_GPA_MFPL_PA3MFP_I2S_DIN@GPA_MFPL'] },
	{ f: ['PA.4', 'GPIO:SYS_GPA_MFPL_PA4MFP_GPIO@GPA_MFPL', 'ADC_CH4:SYS_GPA_MFPL_PA4MFP_ADC_CH4@GPA_MFPL', 'I2S_DO:SYS_GPA_MFPL_PA4MFP_I2S_DOUT@GPA_MFPL'] },
	{ f: ['PA.5', 'GPIO:SYS_GPA_MFPL_PA5MFP_GPIO@GPA_MFPL', 'ADC_CH5:SYS_GPA_MFPL_PA5MFP_ADC_CH5@GPA_MFPL'] },
	{ f: ['PA.6', 'GPIO:SYS_GPA_MFPL_PA6MFP_GPIO@GPA_MFPL', 'ADC_CH6:SYS_GPA_MFPL_PA6MFP_ADC_CH6@GPA_MFPL'] },
	{ f: ['PA.7', 'GPIO:SYS_GPA_MFPL_PA7MFP_GPIO@GPA_MFPL', 'ADC_CH7:SYS_GPA_MFPL_PA7MFP_ADC_CH7@GPA_MFPL'] },
	{ f: ['PA.8', 'GPIO:SYS_GPA_MFPH_PA8MFP_GPIO@GPA_MFPH', 'SPIM_SS:SYS_GPA_MFPH_PA8MFP_SPIM_SS@GPA_MFPH', 'I2S_LRCLK:SYS_GPA_MFPH_PA8MFP_I2S_LRCLK@GPA_MFPH', 'UART1_TXD:SYS_GPA_MFPH_PA8MFP_UART1_TXD@GPA_MFPH'] },
	{ f: ['PA.9', 'GPIO:SYS_GPA_MFPH_PA9MFP_GPIO@GPA_MFPH', 'SPIM_CLK:SYS_GPA_MFPH_PA9MFP_SPIM_CLK@GPA_MFPH', 'I2S_BCLK:SYS_GPA_MFPH_PA9MFP_I2S_BCLK@GPA_MFPH', 'UART1_RXD:SYS_GPA_MFPH_PA9MFP_UART1_RXD@GPA_MFPH'] },
	{ f: ['PA.10', 'GPIO:SYS_GPA_MFPH_PA10MFP_GPIO@GPA_MFPH', 'SPIM_MOSI:SYS_GPA_MFPH_PA10MFP_SPIM_MOSI@GPA_MFPH', 'I2C1_SCL:SYS_GPA_MFPH_PA10MFP_I2C1_SCL@GPA_MFPH', 'SD_CLK:SYS_GPA_MFPH_PA10MFP_SD_CLK@GPA_MFPH'] },
	{ f: ['PA.11', 'GPIO:SYS_GPA_MFPH_PA11MFP_GPIO@GPA_MFPH', 'SPIM_MISO:SYS_GPA_MFPH_PA11MFP_SPIM_MISO@GPA_MFPH', 'I2C1_SDA:SYS_GPA_MFPH_PA11MFP_I2C1_SDA@GPA_MFPH', 'SD_CMD:SYS_GPA_MFPH_PA11MFP_SD_CMD@GPA_MFPH'] },
	{ f: ['PA.12', 'GPIO:SYS_GPA_MFPH_PA12MFP_GPIO@GPA_MFPH', 'SPIM_D2:SYS_GPA_MFPH_PA12MFP_SPIM_D2@GPA_MFPH', 'TM0_CNT_OUT:SYS_GPA_MFPH_PA12MFP_TM0_CNT_OUT@GPA_MFPH'] },
	{ f: ['PA.13', 'GPIO:SYS_GPA_MFPH_PA13MFP_GPIO@GPA_MFPH', 'SPIM_D3:SYS_GPA_MFPH_PA13MFP_SPIM_D3@GPA_MFPH', 'TM0_EXT:SYS_GPA_MFPH_PA13MFP_TM0_EXT@GPA_MFPH', 'SD_nCD:SYS_GPA_MFPH_PA13MFP_SD_nCD@GPA_MFPH'] },
	{ f: ['PA.14', 'GPIO:SYS_GPA_MFPH_PA14MFP_GPIO@GPA_MFPH', 'I2C0_SCL:SYS_GPA_MFPH_PA14MFP_I2C0_SCL@GPA_MFPH', 'SD_DAT0:SYS_GPA_MFPH_PA14MFP_SD_DAT0@GPA_MFPH'] },
	{ f: ['PA.15', 'GPIO:SYS_GPA_MFPH_PA15MFP_GPIO@GPA_MFPH', 'I2C0_SDA:SYS_GPA_MFPH_PA15MFP_I2C0_SDA@GPA_MFPH', 'SD_DAT1:SYS_GPA_MFPH_PA15MFP_SD_DAT1@GPA_MFPH'] },

	{ f: ['PB.0', 'GPIO:SYS_GPB_MFPL_PB0MFP_GPIO@GPB_MFPL', 'I2C0_SCL:SYS_GPB_MFPL_PB0MFP_I2C0_SCL@GPB_MFPL', 'UART0_TXD:SYS_GPB_MFPL_PB0MFP_UART0_TXD@GPB_MFPL', 'SD_DAT2:SYS_GPB_MFPL_PB0MFP_SD_DAT2@GPB_MFPL'] },
	{ f: ['PB.1', 'GPIO:SYS_GPB_MFPL_PB1MFP_GPIO@GPB_MFPL', 'I2C0_SDA:SYS_GPB_MFPL_PB1MFP_I2C0_SDA@GPB_MFPL', 'UART0_RXD:SYS_GPB_MFPL_PB1MFP_UART0_RXD@GPB_MFPL', 'SD_DAT3:SYS_GPB_MFPL_PB1MFP_SD_DAT3@GPB_MFPL'] },
	{ f: ['PB.2', 'GPIO:SYS_GPB_MFPL_PB2MFP_GPIO@GPB_MFPL', 'SPI0_SS:SYS_GPB_MFPL_PB2MFP_SPI0_SS@GPB_MFPL', 'SD_CMD:SYS_GPB_MFPL_PB2MFP_SD_CMD@GPB_MFPL'] },
	{ f: ['PB.3', 'GPIO:SYS_GPB_MFPL_PB3MFP_GPIO@GPB_MFPL', 'SPI0_CLK:SYS_GPB_MFPL_PB3MFP_SPI0_CLK@GPB_MFPL', 'SD_CLK:SYS_GPB_MFPL_PB3MFP_SD_CLK@GPB_MFPL'] },
	{ f: ['PB.4', 'GPIO:SYS_GPB_MFPL_PB4MFP_GPIO@GPB_MFPL', 'SPI0_MOSI:SYS_GPB_MFPL_PB4MFP_SPI0_MOSI@GPB_MFPL'] },
	{ f: ['PB.5', 'GPIO:SYS_GPB_MFPL_PB5MFP_GPIO@GPB_MFPL', 'SPI0_MISO:SYS_GPB_MFPL_PB5MFP_SPI0_MISO@GPB_MFPL', 'SD_nCD:SYS_GPB_MFPL_PB5MFP_SD_nCD@GPB_MFPL'] },
	{ f: ['PB.6', 'GPIO:SYS_GPB_MFPL_PB6MFP_GPIO@GPB_MFPL', 'UART1_TXD:SYS_GPB_MFPL_PB6MFP_UART1_TXD@GPB_MFPL', 'SD_DAT0:SYS_GPB_MFPL_PB6MFP_SD_DAT0@GPB_MFPL'] },
	{ f: ['PB.7', 'GPIO:SYS_GPB_MFPL_PB7MFP_GPIO@GPB_MFPL', 'UART1_RXD:SYS_GPB_MFPL_PB7MFP_UART1_RXD@GPB_MFPL', 'SD_DAT1:SYS_GPB_MFPL_PB7MFP_SD_DAT1@GPB_MFPL'] },
	{ f: ['PB.8', 'GPIO:SYS_GPB_MFPH_PB8MFP_GPIO@GPB_MFPH', 'USBH_PWEN:SYS_GPB_MFPH_PB8MFP_USBH_PWEN@GPB_MFPH', 'TM1_CNT_OUT:SYS_GPB_MFPH_PB8MFP_TM1_CNT_OUT@GPB_MFPH', 'UART1_nCTS:SYS_GPB_MFPH_PB8MFP_UART1_nCTS@GPB_MFPH', 'SD_DAT2:SYS_GPB_MFPH_PB8MFP_SD_DAT2@GPB_MFPH'] },
	{ f: ['PB.9', 'GPIO:SYS_GPB_MFPH_PB9MFP_GPIO@GPB_MFPH', 'USBH_VOD:SYS_GPB_MFPH_PB9MFP_USBH_OVD@GPB_MFPH', 'TM1_EXT:SYS_GPB_MFPH_PB9MFP_TM1_EXT@GPB_MFPH', 'UART1_nRTS:SYS_GPB_MFPH_PB9MFP_UART1_nRTS@GPB_MFPH', 'SD_DAT3:SYS_GPB_MFPH_PB9MFP_SD_DAT3@GPB_MFPH'] },
	{ f: ['PB.10', 'GPIO:SYS_GPB_MFPH_PB10MFP_GPIO@GPB_MFPH', 'SPI1_SS:SYS_GPB_MFPH_PB10MFP_SPI1_SS@GPB_MFPH', 'I2C1_SCL:SYS_GPB_MFPH_PB10MFP_I2C1_SCL@GPB_MFPH', 'UART2_TXD:SYS_GPB_MFPH_PB10MFP_UART2_TXD@GPB_MFPH', 'PWM_CH0:SYS_GPB_MFPH_PB10MFP_PWM_CH0@GPB_MFPH'] },
	{ f: ['PB.11', 'GPIO:SYS_GPB_MFPH_PB11MFP_GPIO@GPB_MFPH', 'SPI1_CLK:SYS_GPB_MFPH_PB11MFP_SPI1_CLK@GPB_MFPH', 'I2C1_SDA:SYS_GPB_MFPH_PB11MFP_I2C1_SDA@GPB_MFPH', 'UART2_RXD:SYS_GPB_MFPH_PB11MFP_UART2_RXD@GPB_MFPH', 'PWM_CH1:SYS_GPB_MFPH_PB11MFP_PWM_CH1@GPB_MFPH'] },
	{ f: ['PB.12', 'GPIO:SYS_GPB_MFPH_PB12MFP_GPIO@GPB_MFPH', 'SPI1_MOSI:SYS_GPB_MFPH_PB12MFP_SPI1_MOSI@GPB_MFPH', 'USBH1_D+:SYS_GPB_MFPH_PB12MFP_USBH1_DP@GPB_MFPH', 'UART2_nCTS:SYS_GPB_MFPH_PB12MFP_UART2_nCTS@GPB_MFPH', 'PWM_CH2:SYS_GPB_MFPH_PB12MFP_PWM_CH2@GPB_MFPH'] },
	{ f: ['PB.13', 'GPIO:SYS_GPB_MFPH_PB13MFP_GPIO@GPB_MFPH', 'SPI1_MISO:SYS_GPB_MFPH_PB13MFP_SPI1_MISO@GPB_MFPH', 'USBH1_D-:SYS_GPB_MFPH_PB13MFP_USBH1_DM@GPB_MFPH', 'UART2_nRTS:SYS_GPB_MFPH_PB13MFP_UART2_nRTS@GPB_MFPH', 'PWM_CH3:SYS_GPB_MFPH_PB13MFP_PWM_CH3@GPB_MFPH'] },
	{ f: ['PB.14', 'GPIO:SYS_GPB_MFPH_PB14MFP_GPIO@GPB_MFPH', 'USBH1_D+:SYS_GPB_MFPH_PB14MFP_USBH1_DP@GPB_MFPH', 'I2C1_SCL:SYS_GPB_MFPH_PB14MFP_I2C1_SCL@GPB_MFPH'] },
	{ f: ['PB.15', 'GPIO:SYS_GPB_MFPH_PB15MFP_GPIO@GPB_MFPH', 'USBH1_D-:SYS_GPB_MFPH_PB15MFP_USBH1_DM@GPB_MFPH', 'I2C1_SDA:SYS_GPB_MFPH_PB15MFP_I2C1_SDA@GPB_MFPH'] },

	{ f: ['PC.0', 'GPIO:SYS_GPC_MFPL_PC0MFP_GPIO@GPC_MFPL', 'SD_CMD:SYS_GPC_MFPL_PC0MFP_SD_CMD@GPC_MFPL'] },
	{ f: ['PC.1', 'GPIO:SYS_GPC_MFPL_PC1MFP_GPIO@GPC_MFPL', 'SD_CLK:SYS_GPC_MFPL_PC1MFP_SD_CLK@GPC_MFPL'] },
	{ f: ['PC.2', 'GPIO:SYS_GPC_MFPL_PC2MFP_GPIO@GPC_MFPL', 'SD_nCD:SYS_GPC_MFPL_PC2MFP_SD_nCD@GPC_MFPL'] },
	{ f: ['PC.3', 'GPIO:SYS_GPC_MFPL_PC3MFP_GPIO@GPC_MFPL'] },
	{ f: ['PC.4', 'GPIO:SYS_GPC_MFPL_PC4MFP_GPIO@GPC_MFPL', 'SD_DAT0:SYS_GPC_MFPL_PC4MFP_SD_DAT0@GPC_MFPL'] },
	{ f: ['PC.5', 'GPIO:SYS_GPC_MFPL_PC5MFP_GPIO@GPC_MFPL', 'SD_DAT1:SYS_GPC_MFPL_PC5MFP_SD_DAT1@GPC_MFPL'] },
	{ f: ['PC.6', 'GPIO:SYS_GPC_MFPL_PC6MFP_GPIO@GPC_MFPL', 'SD_DAT2:SYS_GPC_MFPL_PC6MFP_SD_DAT2@GPC_MFPL'] },
	{ f: ['PC.7', 'GPIO:SYS_GPC_MFPL_PC7MFP_GPIO@GPC_MFPL', 'SD_DAT3:SYS_GPC_MFPL_PC7MFP_SD_DAT3@GPC_MFPL'] },
	{ f: ['PC.8', 'GPIO:SYS_GPC_MFPH_PC8MFP_GPIO@GPC_MFPH', 'I2S_MCLK:SYS_GPC_MFPH_PC8MFP_I2S_MCLK@GPC_MFPH'] },
	{ f: ['PC.9', 'GPIO:SYS_GPC_MFPH_PC9MFP_GPIO@GPC_MFPH', 'I2S_DI:SYS_GPC_MFPH_PC9MFP_I2S_DIN@GPC_MFPH', 'TM2_CNT_OUT:SYS_GPC_MFPH_PC9MFP_TM2_CNT_OUT@GPC_MFPH', 'PWM_CH0:SYS_GPC_MFPH_PC9MFP_PWM_CH0@GPC_MFPH'] },
	{ f: ['PC.10', 'GPIO:SYS_GPC_MFPH_PC10MFP_GPIO@GPC_MFPH', 'I2S_DO:SYS_GPC_MFPH_PC10MFP_I2S_DOUT@GPC_MFPH', 'TM2_EXT:SYS_GPC_MFPH_PC10MFP_TM2_EXT@GPC_MFPH', 'PWM_CH1:SYS_GPC_MFPH_PC10MFP_PWM_CH1@GPC_MFPH'] },
	{ f: ['PC.11', 'GPIO:SYS_GPC_MFPH_PC11MFP_GPIO@GPC_MFPH', 'I2S_LRCLK:SYS_GPC_MFPH_PC11MFP_I2S_LRCLK@GPC_MFPH', 'TM3_CNT_OUT:SYS_GPC_MFPH_PC11MFP_TM3_CNT_OUT@GPC_MFPH', 'PWM_CH2:SYS_GPC_MFPH_PC11MFP_PWM_CH2@GPC_MFPH'] },
	{ f: ['PC.12', 'GPIO:SYS_GPC_MFPH_PC12MFP_GPIO@GPC_MFPH', 'I2S_BCLK:SYS_GPC_MFPH_PC12MFP_I2S_BCLK@GPC_MFPH', 'TM3_EXT:SYS_GPC_MFPH_PC12MFP_TM3_EXT@GPC_MFPH', 'PWM_CH3:SYS_GPC_MFPH_PC12MFP_PWM_CH3@GPC_MFPH'] },
	{ f: ['PC.13', 'GPIO:SYS_GPC_MFPH_PC13MFP_GPIO@GPC_MFPH', 'USBH2_D+:SYS_GPC_MFPH_PC13MFP_USBH2_DP@GPC_MFPH'] },
	{ f: ['PC.14', 'GPIO:SYS_GPC_MFPH_PC14MFP_GPIO@GPC_MFPH', 'USBH2_D-:SYS_GPC_MFPH_PC14MFP_USBH2_DM@GPC_MFPH'] },

	{ f: ['PD.0', 'GPIO:SYS_GPD_MFPL_PD0MFP_GPIO@GPD_MFPL', 'ICE_CLK_IN_ICE_MODE:SYS_GPD_MFPL_PD0MFP_GPIO@GPD_MFPL', 'I2C0_SCL:SYS_GPD_MFPL_PD0MFP_I2C0_SCL@GPD_MFPL'] },
	{ f: ['PD.1', 'GPIO:SYS_GPD_MFPL_PD1MFP_GPIO@GPD_MFPL', 'ICE_DAT_IN_ICE_MODE:SYS_GPD_MFPL_PD1MFP_GPIO@GPD_MFPL', 'I2C0_SDA:SYS_GPD_MFPL_PD1MFP_I2C0_SDA@GPD_MFPL'] },
	{ f: ['PD.2', 'GPIO:SYS_GPD_MFPL_PD2MFP_GPIO@GPD_MFPL', 'MIC1_P:SYS_GPD_MFPL_PD2MFP_MIC1_P@GPD_MFPL'] },
	{ f: ['PD.3', 'GPIO:SYS_GPD_MFPL_PD3MFP_GPIO@GPD_MFPL', 'MIC1_N:SYS_GPD_MFPL_PD3MFP_MIC1_N@GPD_MFPL'] },
	{ f: ['PD.4', 'GPIO:SYS_GPD_MFPL_PD4MFP_GPIO@GPD_MFPL', 'RLINEIN:SYS_GPD_MFPL_PD4MFP_RLINEIN@GPD_MFPL'] }
];

NUTOOL_PIN.g_cfg_gpiosDescriptions = [
	'ADC_CH0:ADC0 analog input',
	'ADC_CH1:ADC1 analog input',
	'ADC_CH2:ADC2 analog input',
	'ADC_CH3:ADC3 analog input',
	'ADC_CH4:ADC4 analog input',
	'ADC_CH5:ADC5 analog input',
	'ADC_CH6:ADC6 analog input',
	'ADC_CH7:ADC7 analog input',

	'I2C0_SCL:I2C0 clock pin',
	'I2C0_SDA:I2C0 data input/output pin',

	'I2C1_SCL:I2C1 clock pin',
	'I2C1_SDA:I2C1 data input/output pin',

	'I2S_BCLK:I2S bit clock pin',
	'I2S_DI:I2S data input',
	'I2S_DO:I2S data output',
	'I2S_LRCLK:I2S left right channel pin',
	'I2S_MCLK:I2S master clock output pin',

	'ICE_CLK_IN_ICE_MODE:Serial wired debugger clock pin (In ICE mode)',
	'ICE_DAT_IN_ICE_MODE:Serial wired debugger data pin (In ICE mode)',

	'MIC1_N:Audio MIC1 analog negative input pin',
	'MIC1_P:Audio MIC1 analog positive input pin',

	'PWM_CH0:PWM output/capture input',
	'PWM_CH1:PWM output/capture input',
	'PWM_CH2:PWM output/capture input',
	'PWM_CH3:PWM output/capture input',

	'RLINEIN:Audio right line-in analog pin',

	'SD_CLK:SD/SDH mode - clock',
	'SD_CMD:SD/SDH mode - command/response',
	'SD_DAT0:SD/SDH mode data line bit 0',
	'SD_DAT1:SD/SDH mode data line bit 1',
	'SD_DAT2:SD/SDH mode data line bit 2',
	'SD_DAT3:SD/SDH mode data line bit 3',
	'SD_nCD:SD/SDH mode - card detect',

	'SPI0_CLK:SPI0 serial clock pin',
	'SPI0_MISO:SPI0 MISO (Master In, Slave Out) pin',
	'SPI0_MOSI:SPI0 MOSI (Master Out, Slave In) pin',
	'SPI0_SS:SPI0 slave select pin',

	'SPI1_CLK:SPI1 serial clock pin',
	'SPI1_MISO:SPI1 MISO (Master In, Slave Out) pin',
	'SPI1_MOSI:SPI1 MOSI (Master Out, Slave In) pin',
	'SPI1_SS:SPI1 slave select pin',

	'SPIM_CLK:SPIM serial clock pin',
	'SPIM_D2:SPIM data-2 bit in quad mode',
	'SPIM_D3:SPIM data-3 bit in quad mode',
	'SPIM_MISO:SPIM MISO (Master In, Slave Out) pin',
	'SPIM_MOSI:SPIM MOSI (Master Out, Slave In) pin',
	'SPIM_SS:SPIM slave select pin',

	'TM0_CNT_OUT:Timer0 event counter input / toggle output',
	'TM0_EXT:Timer0 external counter input',

	'TM1_CNT_OUT:Timer1 event counter input / toggle output',
	'TM1_EXT:Timer1 external counter input',

	'TM2_CNT_OUT:Timer2 event counter input / toggle output',
	'TM2_EXT:Timer2 external counter input',

	'TM3_CNT_OUT:Timer3 event counter input / toggle output',
	'TM3_EXT:Timer3 external counter input',

	'UART0_RXD:Data receiver input pin for UART0',
	'UART0_TXD:Data transmitter output pin for UART0',

	'UART1_nCTS:Clear to Send input pin for UART1',
	'UART1_nRTS:Request to Send output pin for UART1',
	'UART1_RXD:Data receiver input pin for UART1',
	'UART1_TXD:Data transmitter output pin for UART1',

	'UART2_nCTS:Clear to Send input pin for UART2',
	'UART2_nRTS:Request to Send output pin for UART2',
	'UART2_RXD:Data receiver input pin for UART2',
	'UART2_TXD:Data transmitter output pin for UART2',

	'USBH_PWEN:USB host to control an external overcurrent source',
	'USBH_VOD:USB host lite over voltage detector',

	'USBH1_D-:USB host lite 1 differential signal D-',
	'USBH1_D+:USB host lite 1 differential signal D+',

	'USBH2_D-:USB host lite 2 differential signal D-',
	'USBH2_D+:USB host lite 2 differential signal D+'
];

NUTOOL_PIN.g_cfg_regDescriptions = {};
NUTOOL_PIN.g_cfg_regDescriptions.GPA_MFPL = '0x40000030';
NUTOOL_PIN.g_cfg_regDescriptions.GPA_MFPH = '0x40000034';
NUTOOL_PIN.g_cfg_regDescriptions.GPB_MFPL = '0x40000038';
NUTOOL_PIN.g_cfg_regDescriptions.GPB_MFPH = '0x4000003C';
NUTOOL_PIN.g_cfg_regDescriptions.GPC_MFPL = '0x40000040';
NUTOOL_PIN.g_cfg_regDescriptions.GPC_MFPH = '0x40000044';
NUTOOL_PIN.g_cfg_regDescriptions.GPD_MFPL = '0x40000048';

NUTOOL_PIN.g_cfg_gpioMatrix = [];
NUTOOL_PIN.g_cfg_shareBits = [];
NUTOOL_PIN.g_cfg_addGPIO = {};
NUTOOL_PIN.g_cfg_unusedGPIO = {};
NUTOOL_PIN.g_cfg_WPPin = [];

NUTOOL_PIN.decidepackageNumber = function (given_partNumber_package) {
	var partNumber_package,
		partNumber;

	if (typeof given_partNumber_package === 'undefined') {
		partNumber_package = NUTOOL_PIN.getg_partNumber_package();
	}
	else {
		partNumber_package = given_partNumber_package;
	}

	NUTOOL_PIN.g_packageNumber = partNumber_package.substring(partNumber_package.indexOf('(') + 1);
	NUTOOL_PIN.g_packageNumber = NUTOOL_PIN.g_packageNumber.substring(0, NUTOOL_PIN.g_packageNumber.indexOf(')'));

	partNumber = partNumber_package.substring(0, partNumber_package.indexOf('('));
	switch (NUTOOL_PIN.g_packageNumber) {
	case 'QFN88':
		NUTOOL_PIN.g_packageNumberIndex = "QFN88";
		break;
	case 'LQFP64':
		switch (partNumber) {
		case "NUC505DS13Y":
			NUTOOL_PIN.g_packageNumberIndex = "LQFP64_0";
			break;
		case "NUC505DSA":
			NUTOOL_PIN.g_packageNumberIndex = "LQFP64_1";
			break;
		default:
			NUTOOL_PIN.g_packageNumberIndex = "LQFP64_0";
			break;
		}
		break;
	case 'LQFP48':
		switch (partNumber) {
		case "NUC505DL13Y":
			NUTOOL_PIN.g_packageNumberIndex = "LQFP48";
			break;
		case "NUC505DLA":
			NUTOOL_PIN.g_packageNumberIndex = "LQFP48(CODEC)";
			break;
		default:
			NUTOOL_PIN.g_packageNumberIndex = "LQFP48";
			break;
		}
		break;
	case 'QFN48':
		switch (partNumber) {
		case "NUC505YLA2Y":
			NUTOOL_PIN.g_packageNumberIndex = "LQFP48";
			break;
		case "NUC505YLA":
			NUTOOL_PIN.g_packageNumberIndex = "LQFP48(CODEC)";
			break;
		default:
			NUTOOL_PIN.g_packageNumberIndex = "LQFP48";
			break;
		}
		break;
	}
	partNumber_package = null;
	partNumber = null;
};
