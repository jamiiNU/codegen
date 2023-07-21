// chip content
NUTOOL_PIN.g_cfg_chips = [
	//NM1120
	{ name: "NM1120FC1AE", pkg: "TSSOP20" },
	{ name: "NM1120EC1AE", pkg: "TSSOP28" },
	{ name: "NM1120XC1AE", pkg: "QFN20" },
	{ name: "NM1120TC1AE", pkg: "QFN33" },
	{ name: "NM1120ZC1AE", pkg: "QFN33" },
	{ name: "NM1120FB0AE", pkg: "TSSOP20" },
	{ name: "NM1120EB0AE", pkg: "TSSOP28" },
	{ name: "NM1120XB0AE", pkg: "QFN20" },
	{ name: "NM1120TB0AE", pkg: "QFN33" },
	{ name: "NM1120ZB0AE", pkg: "QFN33" }
];

NUTOOL_PIN.g_cfg_pkgs = {
	"TSSOP28": [
		'VDD', 'PD.6', 'PB.0', 'PB.1', 'PB.2', 'PB.4', 'PC.1',
		'nRESET', 'PB.3', 'PC.2', 'PD.2', 'PD.3', 'NC', 'NC',
		'PC.0', 'PD.4', 'PD.1', 'PC.3', 'PD.5', 'PA.5', 'PA.4',
		'PA.3', 'PA.2', 'PA.1', 'PA.0', 'PC.4', 'LDO_CAP', 'VSS'
	],
	"TSSOP20": [
		'VDD', 'PB.0', 'PB.1', 'PB.2', 'PB.4',
		'PC.1', 'nRESET', 'PB.3', 'PC.2', 'PD.2',
		'PC.0', 'PD.1', 'PC.3', 'PA.5', 'PA.4',
		'PA.3', 'PA.2', 'PA.1', 'PA.0', 'VSS'
	],
	"QFN33": [
		'LDO_CAP', 'VSS', 'VDD', 'PD.6', 'PB.0', 'PB.1', 'PB.2', 'PB.4',
		'PC.1', 'nRESET', 'PB.3', 'PC.2', 'PD.2', 'PD.3', 'NC', 'NC',
		'NC', 'NC', 'PD.5', 'PA.5', 'PA.4', 'NC', 'PA.3', 'PA.2',
		'PA.1', 'PA.0', 'PC.4', 'PC.0', 'PD.4', 'PD.1', 'PC.3', 'NC'
	],
	"QFN20": [
		'VDD', 'PB.0', 'PB.1', 'PB.2', 'PB.4',
		'PC.1', 'nRESET', 'PB.3', 'PC.2', 'PD.2',
		'PC.0', 'PD.1', 'PC.3', 'PA.5', 'PA.4',
		'PA.3', 'PA.2', 'PA.1', 'PA.0', 'VSS'
	]
};

NUTOOL_PIN.g_cfg_OrCAD = {};

NUTOOL_PIN.g_cfg_gpios = [
	{ f: ['PA.0:0', 'CLKO:1', 'EPWM_CH0:3', 'I2C1_SCL:8', 'SPI0_SS:9', 'SPI1_CLK:10', 'UART1_TXD:11']},
	{ f: ['PA.1:0', 'EPWM_CH1:3', 'I2C1_SDA:8', 'SPI0_MISO:9', 'SPI1_MOSI:10', 'UART1_RXD:11']},
	{ f: ['PA.2:0', 'EPWM_CH2:3', 'I2C0_SDA:8', 'SPI0_MOSI:9', 'SPI1_MISO:10', 'UART0_RXD:11']},
	{ f: ['PA.3:0', 'EPWM_CH3:3', 'I2C0_SCL:8', 'SPI0_CLK:9', 'SPI1_SS:10', 'UART0_TXD:11']},
	{ f: ['PA.4:0', 'XT_IN:1', 'EPWM_CH4:3']},
	{ f: ['PA.5:0', 'XT_OUT:1', 'EPWM_CH5:3', 'ACMP0_O:4']},
	{ f: ['PA.6:0']},
	{ f: ['PA.7:0']},

	{ f: ['PB.0:0', 'ADC0_CH0:2', 'ACMP0_P0:4', 'ECAP_P0:7']},
	{ f: ['PB.1:0', 'ADC0_CH1:2', 'ACMP0_P1:4', 'ECAP_P1:7']},
	{ f: ['PB.2:0', 'ADC0_CH2:2', 'BPWM_CH1:3', 'ACMP0_P2:4', 'ECAP_P2:7']},
	{ f: ['PB.3:0', 'ACMP1_N:5', 'PGA_I:6', 'TM0:7']},
	{ f: ['PB.4:0', 'ADC1_CH0:2', 'ACMP0_N:4', 'TM1:7']},
	{ f: ['PB.5:0']},
	{ f: ['PB.6:0']},
	{ f: ['PB.7:0']},

	{ f: ['PC.0:0', 'ADC0_CH3:2', 'BPWM_CH0:3', 'ACMP1_P0:5', 'I2C1_SCL:8', 'SPI0_SS:9', 'SPI1_CLK:10', 'UART1_TXD:11']},
	{ f: ['PC.1:0', 'ADC0_CH4:2', 'STADC:3', 'ACMP0_P3:4', 'ACMP1_P1:5', 'SPI0_MOSI:9', 'SPI1_MISO:10']},
	{ f: ['PC.2:0', 'ADC1_CH2:2', 'BRAKE:3', 'CCAP_P1:7', 'I2C1_SDA:8', 'SPI0_MISO:9', 'SPI1_MOSI:10', 'UART1_RXD:11']},
	{ f: ['PC.3:0', 'ACMP1_O:5', 'PGA_O:6', 'SPI0_CLK:9', 'SPI1_SS:10']},
	{ f: ['PC.4:0', 'ECAP_P3:7']},
	{ f: ['PC.5:0']},
	{ f: ['PC.6:0']},
	{ f: ['PC.7:0']},

	{ f: ['PD.0:0']},
	{ f: ['PD.1:0', 'ICE_CLK:1', 'ACMP1_P2:5', 'I2C0_SCL:8', 'SPI0_CLK:9', 'SPI1_SS:10', 'UART0_TXD:11']},
	{ f: ['PD.2:0', 'ICE_DAT:1', 'ADC1_CH1:2', 'CCAP_P0:7', 'I2C0_SDA:8', 'SPI0_MOSI:9', 'SPI1_MISO:10', 'UART0_RXD:11']},
	{ f: ['PD.3:0', 'BPWM_CH1:3', 'UART1_TXD:11']},
	{ f: ['PD.4:0', 'BPWM_CH0:3', 'UART1_RXD:11']},
	{ f: ['PD.5:0', 'UART0_TXD:11']},
	{ f: ['PD.6:0', 'UART0_RXD:11']},
	{ f: ['PD.7:0']}
];

NUTOOL_PIN.g_cfg_gpiosDefines = [
	// { f: ['PA.0', 'CLKO:SYS_GPA_MFP_PA0_CLKO@GPA_MFP', 'EPWM_CH0:SYS_GPA_MFP_PA0_EPWM_CH0@GPA_MFP', 'I2C1_SCL:SYS_GPA_MFP_PA0_I2C1_SCL@GPA_MFP', 'SPI0_SS:SYS_GPA_MFP_PA0_SPI0_SS@GPA_MFP', 'SPI1_CLK:SYS_GPA_MFP_PA0_SPI1_CLK@GPA_MFP', 'UART1_TXD:SYS_GPA_MFP_PA0_UART1_TXD@GPA_MFP', 'SMP0:SYS_GPA_MFP_PA0_SMP0@GPA_MFP'] },
	// { f: ['PA.1', 'EPWM_CH1:SYS_GPA_MFP_PA1_EPWM_CH1@GPA_MFP', 'I2C1_SDA:SYS_GPA_MFP_PA1_I2C1_SDA@GPA_MFP', 'SPI0_MISO:SYS_GPA_MFP_PA1_SPI0_MISO@GPA_MFP', 'SPI1_MOSI:SYS_GPA_MFP_PA1_SPI1_MOSI@GPA_MFP', 'UART1_RXD:SYS_GPA_MFP_PA1_UART1_RXD@GPA_MFP', 'SMP1:SYS_GPA_MFP_PA1_SMP1@GPA_MFP'] },
	// { f: ['PA.2', 'EPWM_CH2:SYS_GPA_MFP_PA2_EPWM_CH2@GPA_MFP', 'I2C0_SDA:SYS_GPA_MFP_PA2_I2C0_SDA@GPA_MFP', 'SPI0_MOSI:SYS_GPA_MFP_PA2_SPI0_MOSI@GPA_MFP', 'SPI1_MISO:SYS_GPA_MFP_PA2_SPI1_MISO@GPA_MFP', 'UART0_RXD:SYS_GPA_MFP_PA2_UART0_RXD@GPA_MFP'] },
	// { f: ['PA.3', 'EPWM_CH3:SYS_GPA_MFP_PA3_EPWM_CH3@GPA_MFP', 'I2C0_SCL:SYS_GPA_MFP_PA3_I2C0_SCL@GPA_MFP', 'SPI0_CLK:SYS_GPA_MFP_PA3_SPI0_CLK@GPA_MFP', 'SPI1_SS:SYS_GPA_MFP_PA3_SPI1_SS@GPA_MFP', 'UART0_TXD:SYS_GPA_MFP_PA3_UART0_TXD@GPA_MFP'] },
	// { f: ['PA.4', 'XT_IN:SYS_GPA_MFP_PA4_XT_IN@GPA_MFP', 'EPWM_CH4:SYS_GPA_MFP_PA4_EPWM_CH4@GPA_MFP'] },
	// { f: ['PA.5', 'XT_OUT:SYS_GPA_MFP_PA5_XT_OUT@GPA_MFP', 'EPWM_CH5:SYS_GPA_MFP_PA5_EPWM_CH5@GPA_MFP', 'ACMP0_O:SYS_GPA_MFP_PA5_ACMP0_O@GPA_MFP'] },
	// { f: ['PA.6']},
	// { f: ['PA.7']},

	// { f: ['PB.0', 'ADC0_CH0:SYS_GPB_MFP_PB0_ADC0_CH0@GPB_MFP', 'ACMP0_P0:SYS_GPB_MFP_PB0_ACMP0_P0@GPB_MFP', 'ECAP0:SYS_GPB_MFP_PB0_ECAP0@GPB_MFP', 'SMP2:SYS_GPB_MFP_PB0_SMP2@GPB_MFP'] },
	// { f: ['PB.1', 'ADC0_CH1:SYS_GPB_MFP_PB1_ADC0_CH1@GPB_MFP', 'ACMP0_P1:SYS_GPB_MFP_PB1_ACMP0_P1@GPB_MFP', 'ECAP1:SYS_GPB_MFP_PB1_ECAP1@GPB_MFP', 'SMP3:SYS_GPB_MFP_PB1_SMP3@GPB_MFP'] },
	// { f: ['PB.2', 'ADC0_CH2:SYS_GPB_MFP_PB2_ADC0_CH2@GPB_MFP', 'BPWM_CH1:SYS_GPB_MFP_PB2_BPWM_CH1@GPB_MFP', 'ACMP0_P2:SYS_GPB_MFP_PB2_ACMP0_P2@GPB_MFP', 'ECAP2:SYS_GPB_MFP_PB2_ECAP2@GPB_MFP'] },
	// { f: ['PB.3', 'ACMP1_N:SYS_GPB_MFP_PB3_ACMP1_N@GPB_MFP', 'PGA_I:SYS_GPB_MFP_PB3_PGA_I@GPB_MFP', 'T0:SYS_GPB_MFP_PB3_T0@GPB_MFP'] },
	// { f: ['PB.4', 'ADC1_CH0:SYS_GPB_MFP_PB4_ADC1_CH0@GPB_MFP', 'ACMP0_N:SYS_GPB_MFP_PB4_ACMP0_N@GPB_MFP', 'T1:SYS_GPB_MFP_PB4_T1@GPB_MFP'] },
	// { f: ['PB.5']},
	// { f: ['PB.6']},
	// { f: ['PB.7']},

	// { f: ['PC.0', 'ADC0_CH3:SYS_GPC_MFP_PC0_ADC0_CH3@GPC_MFP', 'BPWM_CH0:SYS_GPC_MFP_PC0_BPWM_CH0@GPC_MFP', 'ACMP1_P0:SYS_GPC_MFP_PC0_ACMP1_P0@GPC_MFP', 'I2C1_SCL:SYS_GPC_MFP_PC0_I2C1_SCL@GPC_MFP', 'SPI0_SS:SYS_GPC_MFP_PC0_SPI0_SS@GPC_MFP', 'SPI1_CLK:SYS_GPC_MFP_PC0_SPI1_CLK@GPC_MFP', 'UART1_TXD:SYS_GPC_MFP_PC0_UART1_TXD@GPC_MFP'] },
	// { f: ['PC.1', 'ADC0_CH4:SYS_GPC_MFP_PC1_ADC0_CH4@GPC_MFP', 'STADC:SYS_GPC_MFP_PC1_STADC@GPC_MFP', 'ACMP0_P3:SYS_GPC_MFP_PC1_ACMP0_P3@GPC_MFP', 'ACMP1_P1:SYS_GPC_MFP_PC1_ACMP1_P1@GPC_MFP', 'SPI0_MOSI:SYS_GPC_MFP_PC1_SPI0_MOSI@GPC_MFP', 'SPI1_MISO:SYS_GPC_MFP_PC1_SPI1_MISO@GPC_MFP'] },
	// { f: ['PC.2', 'ADC1_CH2:SYS_GPC_MFP_PC2_ADC1_CH2@GPC_MFP', 'PWM_BRAKE:SYS_GPC_MFP_PC2_PWM_BRAKE@GPC_MFP', 'CCAP:SYS_GPC_MFP_PC2_CCAP@GPC_MFP', 'I2C1_SDA:SYS_GPC_MFP_PC2_I2C1_SDA@GPC_MFP', 'SPI0_MISO:SYS_GPC_MFP_PC2_SPI0_MISO@GPC_MFP', 'SPI1_MOSI:SYS_GPC_MFP_PC2_SPI1_MOSI@GPC_MFP', 'UART1_RXD:SYS_GPC_MFP_PC2_UART1_RXD@GPC_MFP'] },
	// { f: ['PC.3', 'ACMP1_O:SYS_GPC_MFP_PC3_ACMP1_O@GPC_MFP', 'PGA_O:SYS_GPC_MFP_PC3_PGA_O@GPC_MFP', 'SPI0_CLK:SYS_GPC_MFP_PC3_SPI0_CLK@GPC_MFP', 'SPI1_SS:SYS_GPC_MFP_PC3_SPI1_SS@GPC_MFP'] },
	// { f: ['PC.4', 'ECAP0:SYS_GPC_MFP_PC4_ECAP0@GPC_MFP'] },
	// { f: ['PC.5']},
	// { f: ['PC.6']},
	// { f: ['PC.7']},

	// { f: ['PD.0', 'nRESET:SYS_GPD_MFP_PD0_nRESET@GPD_MFP'] },
	// { f: ['PD.1', 'ICE_CLK:SYS_GPD_MFP_PD1_ICE_CLK@GPD_MFP', 'ACMP1_P2:SYS_GPD_MFP_PD1_ACMP1_P2@GPD_MFP', 'I2C0_SCL:SYS_GPD_MFP_PD1_I2C0_SCL@GPD_MFP', 'SPI0_CLK:SYS_GPD_MFP_PD1_SPI0_CLK@GPD_MFP', 'SPI1_SS:SYS_GPD_MFP_PD1_SPI1_SS@GPD_MFP', 'UART0_TXD:SYS_GPD_MFP_PD1_UART0_TXD@GPD_MFP'] },
	// { f: ['PD.2', 'ICE_DAT:SYS_GPD_MFP_PD2_ICE_DAT@GPD_MFP', 'ADC1_CH1:SYS_GPD_MFP_PD2_ADC1_CH1@GPD_MFP', 'CCAP:SYS_GPD_MFP_PD2_CCAP@GPD_MFP', 'I2C0_SDA:SYS_GPD_MFP_PD2_I2C0_SDA@GPD_MFP', 'SPI0_MOSI:SYS_GPD_MFP_PD2_SPI0_MOSI@GPD_MFP', 'SPI1_MISO:SYS_GPD_MFP_PD2_SPI1_MISO@GPD_MFP', 'UART0_RXD:SYS_GPD_MFP_PD2_UART0_RXD@GPD_MFP'] },
	// { f: ['PD.3', 'BPWM_CH1:SYS_GPD_MFP_PD3_BPWM_CH1@GPD_MFP', 'UART1_TXD:SYS_GPD_MFP_PD3_UART1_TXD@GPD_MFP'] },
	// { f: ['PD.4', 'BPWM_CH0:SYS_GPD_MFP_PD4_BPWM_CH0@GPD_MFP', 'UART1_RXD:SYS_GPD_MFP_PD4_UART1_RXD@GPD_MFP'] },
	// { f: ['PD.5', 'UART0_TXD:SYS_GPD_MFP_PD5_UART0_TXD@GPD_MFP'] },
	// { f: ['PD.6', 'UART0_RXD:SYS_GPD_MFP_PD6_UART0_RXD@GPD_MFP'] },
	// { f: ['PD.7']}
];

NUTOOL_PIN.g_cfg_gpiosDescriptions = [
	'ACMP0_N:Analog comparator0 negative input pin',
	'ACMP0_O:Analog comparator0 output',
	'ACMP0_P0:Analog comparator0 positive input pin',
	'ACMP0_P1:Analog comparator0 positive input pin',
	'ACMP0_P2:Analog comparator0 positive input pin',
	'ACMP0_P3:Analog comparator0 positive input pin',
	'ACMP1_N:Analog comparator1 negative input pin',
	'ACMP1_O:Analog comparator1 output',
	'ACMP1_P0:Analog comparator1 positive input pin',
	'ACMP1_P1:Analog comparator1 positive input pin',
	'ACMP1_P2:Analog comparator1 positive input pin',
	'ADC0_CH0:ADC0 channel0 analog input',
	'ADC0_CH1:ADC0 channel1 analog input',
	'ADC0_CH2:ADC0 channel2 analog input',
	'ADC0_CH3:ADC0 channel3 analog input',
	'ADC0_CH4:ADC0 channel4 analog input',
	'ADC1_CH0:ADC1 channel0 analog input',
	'ADC1_CH1:ADC1 channel1 analog input',
	'ADC1_CH2:ADC1 channel2 analog input',
	'BPWM_CH0:PWM channel0 output/capture input',
	'BPWM_CH1:PWM channel1 output/capture input',
	'BRAKE:Brake input pin of EPWM',
	'CCAP_P0:Timer Continuous Capture input pin',
	'CCAP_P1:Timer Continuous Capture input pin',
	'CLKO:Clock Out',
	'ECAP_P0:Enhanced Input Capture input pin',
	'ECAP_P1:Enhanced Input Capture input pin',
	'ECAP_P2:Enhanced Input Capture input pin',
	'ECAP_P3:Enhanced Input Capture input pin',
	'EPWM_CH0:PWM channel0 output/capture input',
	'EPWM_CH1:PWM channel1 output/capture input',
	'EPWM_CH2:PWM channel2 output/capture input',
	'EPWM_CH3:PWM channel3 output/capture input',
	'EPWM_CH4:PWM channel4 output/capture input',
	'EPWM_CH5:PWM channel5 output/capture input',
	'I2C0_SCL:I2C0 clock pin',
	'I2C0_SDA:I2C0 data input/output pin',
	'I2C1_SCL:I2C1 clock pin',
	'I2C1_SDA:I2C1 data input/output pin',
	'ICE_CLK:Serial wired debugger clock pin',
	'ICE_DAT:Serial wired debugger data pin',
	'LDO_CAP:LDO output pin',
	'NC:No Connection',
	'nRESET:External reset input: active LOW, with an internal pull-up. Set this pin low reset to initial state',
	'PGA_I:PGA input pin',
	'PGA_O:PGA output pin',
	'SPI0_CLK:SPI0 serial clock pin',
	'SPI0_MISO:SPI0 1st MISO (Master In, Slave Out) pin',
	'SPI0_MOSI:SPI0 1st MOSI (Master Out, Slave In) pin',
	'SPI0_SS:SPI0 slave select pin',
	'SPI1_CLK:SPI1 serial clock pin',
	'SPI1_MISO:SPI1 MISO (Master In, Slave Out) pin',
	'SPI1_MOSI:SPI1 MOSI (Master Out, Slave In) pin',
	'SPI1_SS:SPI1 slave select pin',
	'STADC:ADC external trigger input',
	'TM0:Timer0event counter input / toggle output',
	'TM1:Timer1 event counter input / toggle output',
	'UART0_RXD:Data receiver input pin for UART0',
	'UART0_TXD:Data transmitter output pin for UART0',
	'UART1_RXD:Data receiver input pin for UART1',
	'UART1_TXD:Data transmitter output pin for UART1',
	'VDD:Power supply for I/O ports and LDO source for internal PLL and digital function',
	'VSS:Ground pin for digital circuit',
	'XT_IN:External 4~24 MHz (high speed) crystal input pin',
	'XT_OUT:External 4~24 MHz (high speed) crystal output pin'
];

NUTOOL_PIN.g_cfg_regDescriptions = {};
NUTOOL_PIN.g_cfg_regDescriptions.GPA_MFP = '0x50000030';
NUTOOL_PIN.g_cfg_regDescriptions.GPB_MFP = '0x50000034';
NUTOOL_PIN.g_cfg_regDescriptions.GPC_MFP = '0x50000038';
NUTOOL_PIN.g_cfg_regDescriptions.GPD_MFP = '0x5000003C';

NUTOOL_PIN.g_cfg_gpioMatrix = [];
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
