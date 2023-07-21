// chip content
NUTOOL_PIN.g_cfg_chips = [
	// 8K
	// { name: "MS51IA9AE", pkg: "SOP8" },
	{ name: "MS51BA9AE", pkg: "MSOP10" },
	{ name: "MS51DA9AE", pkg: "TSSOP14" },
	// 16K
	{ name: "MS51XB9AE", pkg: "QFN20" },
	{ name: "MS51XB9BE", pkg: "QFN20" },
	{ name: "MS51FB9AE", pkg: "TSSOP20" },
	// 32K
	{ name: "MS51FC0AE", pkg: "TSSOP20" },
	{ name: "MS51XC0BE", pkg: "QFN20" },
	{ name: "MS51EB0AE", pkg: "TSSOP28" },
	{ name: "MS51EC0AE", pkg: "TSSOP28" },
	{ name: "MS51PC0AE", pkg: "LQFP32" },
	{ name: "MS51TC0AE", pkg: "QFN33" }
];

NUTOOL_PIN.g_cfg_pkgs = {
	"SOP8": [
		'P0.1', 'P0.4', 'P0.2', 'P2.0',
		'VSS', 'VDD', 'P1.0', 'P0.0'
	]
};

NUTOOL_PIN.g_cfg_OrCAD = {};

NUTOOL_PIN.g_cfg_gpios = [
	{ f: ['P0.0:0', 'PWM0_CH3:2', 'SPI0_MOSI:4', 'IC3:5', 'T1:6']},
	{ f: ['P0.1:0', 'ADC_CH6:1', 'PWM0_CH4:2', 'I2C0_SCL:3', 'SPI0_MISO:4', 'IC4:5', 'CLKO:6', 'STADC:7']},
	{ f: ['P0.2:0', 'ADC_CH3:1', 'PWM0_CH0:2', 'UART0_TXD:3', 'UART1_RXD:4', 'IC0:5', 'I2C0_SCL:6', 'ICE_CLK:9']},
	{ f: ['P0.3:0']},
	{ f: ['P0.4:0', 'ADC_CH4:1', 'PWM0_CH3:2', 'I2C0_SDA:3', 'SPI0_SS:4', 'IC3:5', 'T0:6', 'PWM0_BRAKE:7', 'STADC:8']},
	{ f: ['P0.5:0']},
	{ f: ['P0.6:0']},
	{ f: ['P0.7:0']},

	{ f: ['P1.0:0', 'ADC_CH1:1', 'PWM0_CH2:2', 'UART1_TXD:3', 'SPI0_CLK:4', 'IC2:5', 'INT0:6', 'OSCIN:7', 'I2C0_SDA:8', 'ICE_DAT:9']},
	{ f: ['P1.1:0']},
	{ f: ['P1.2:0']},
	{ f: ['P1.3:0']},
	{ f: ['P1.4:0']},
	{ f: ['P1.5:0']},
	{ f: ['P1.6:0']},
	{ f: ['P1.7:0']},

	{ f: ['P2.0:0', 'UART0_RXD:1', 'nRESET:9']},
	{ f: ['P2.1:0']},
	{ f: ['P2.2:0']},
	{ f: ['P2.3:0']},
	{ f: ['P2.4:0']},
	{ f: ['P2.5:0']},
	{ f: ['P2.6:0']},
	{ f: ['P2.7:0']}
];

NUTOOL_PIN.g_cfg_gpiosDefines = [
	{ f: ['P0.0', 'PWM0_CH3:P00_PUSHPULL_MODE;ENABLE_PWM0_CH3_P00_OUTPUT;@P0MF76543210', 'SPI0_MOSI:P00_QUASI_MODE;@P0MF76543210', 'IC3:P00_INPUT_MODE;@P0MF76543210', 'T1:P00_QUASI_MODE;@P0MF76543210'] },
	{ f: ['P0.1', 'PWM0_CH4:P01_PUSHPULL_MODE;ENABLE_PWM0_CH4_P01_OUTPUT;@P0MF76543210', 'IC4:P01_INPUT_MODE;@P0MF76543210', 'SPI0_MISO:P01_QUASI_MODE;@P0MF76543210'] },
	{ f: ['P0.2', 'ICE_CLK:@P0MF76543210', 'UART1_RXD:P01_INPUT_MODE;@P0MF76543210', 'I2C0_SCL:P01_OPENDRAIN_MODE;@P0MF76543210'] },
	{ f: ['P0.3', 'ADC_CH6:ENABLE_ADC_CH6;@P0MF76543210', 'PWM0_CH5:P03_PUSHPULL_MODE;ENABLE_PWM0_CH5_P03_OUTPUT;@P0MF76543210', 'IC5:P03_INPUT_MODE;@P0MF76543210'] },
	{ f: ['P0.4', 'PWM0_CH3:P04_PUSHPULL_MODE;ENABLE_PWM0_CH3_P04_OUTPUT;@P0MF76543210', 'IC3:P04_INPUT_MODE;@P0MF76543210', 'ADC_CH5:ENABLE_ADC_CH5;@P0MF76543210', 'STADC:P04_QUASI_MODE;P04_FALLINGEDGE_TRIG_ADC;@P0MF76543210'] },
	{ f: ['P0.5', 'PWM0_CH2:P05_PUSHPULL_MODE;ENABLE_PWM0_CH2_P05_OUTPUT;@P0MF76543210', 'IC6:P05_INPUT_MODE;@P0MF76543210', 'T0:P05_QUASI_MODE;@P0MF76543210', 'ADC_CH4:ENABLE_ADC_CH4;@P0MF76543210'] },
	{ f: ['P0.6', 'UART0_TXD:P06_QUASI_MODE;@P0MF76543210', 'ADC_CH3:ENABLE_ADC_CH3;@P0MF76543210'] },
	{ f: ['P0.7', 'UART0_RXD:P07_INPUT_MODE;@P0MF76543210', 'ADC_CH2:ENABLE_ADC_CH2;@P0MF76543210'] },
	{ f: ['P1.0', 'PWM0_CH2:P10_PUSHPULL_MODE;ENABLE_PWM0_CH2_P10_OUTPUT;@P1MF76543210', 'IC2:P10_INPUT_MODE;@P1MF76543210', 'SPI0_CLK:P10_QUASI_MODE;@P1MF76543210'] },
	{ f: ['P1.1', 'PWM0_CH1:P11_PUSHPULL_MODE;ENABLE_PWM0_CH1_P11_OUTPUT;@P1MF76543210', 'IC1:P11_INPUT_MODE;@P1MF76543210', 'ADC_CH7:ENABLE_ADC_CH7;@P1MF76543210', 'CLKO:P11_PUSHPULL_MODE;@P1MF76543210'] },
	{ f: ['P1.2', 'PWM0_CH0:P12_PUSHPULL_MODE;ENABLE_PWM0_CH0_P12_OUTPUT;@P1MF76543210', 'IC0:P12_INPUT_MODE;@P1MF76543210'] },
	{ f: ['P1.3', 'I2C0_SCL:P13_OPENDRAIN_MODE;@P1MF76543210', 'STADC:P13_QUASI_MODE;P13_FALLINGEDGE_TRIG_ADC;@P1MF76543210'] },
	{ f: ['P1.4', 'PWM0_CH1:P14_PUSHPULL_MODE;ENABLE_PWM0_CH1_P14_OUTPUT;@P1MF76543210', 'I2C0_SDA:P14_OPENDRAIN_MODE;clr_I2CON_I2CPX;@P1MF76543210', 'PWM0_BRAKE:P14_INPUT_MODE;@P1MF76543210'] },
	{ f: ['P1.5', 'PWM0_CH5:P15_PUSHPULL_MODE;ENABLE_PWM0_CH5_P15_OUTPUT;@P1MF76543210', 'IC7:P15_INPUT_MODE;@P1MF76543210', 'SPI0_SS:P15_QUASI_MODE;@P1MF76543210'] },
	{ f: ['P1.6', 'ICE_DAT:@P1MF76543210', 'UART1_TXD:P16_QUASI_MODE;@P1MF76543210', 'I2C0_SDA:P16_OPENDRAIN_MODE;set_I2CON_I2CPX;@P1MF76543210'] },
	{ f: ['P1.7', 'INT1:P17_QUASI_MODE;@P1MF76543210', 'ADC_CH0:ENABLE_ADC_CH0;@P1MF76543210'] },
	{ f: ['P2.0', 'nRESET:@P2MF76543210'] },
	{ f: ['P3.0', 'ADC_CH1:ENABLE_ADC_CH1;@P3MF76543210', 'INT0:P30_QUASI_MODE;@P3MF76543210', 'OSCIN:P30_INPUT_MODE;@P3MF76543210'] }
];

NUTOOL_PIN.g_cfg_gpiosDescriptions = [
	'ADC_CH0:ADC input channel 0',
	'ADC_CH1:ADC input channel 1',
	'ADC_CH3:ADC input channel 3',
	'ADC_CH4:ADC input channel 4',
	'ADC_CH5:ADC input channel 5',
	'ADC_CH6:ADC input channel 6',
	'ADC_CH7:ADC input channel 7',
	'CLKO:Clock output',
	'I2C0_SCL:I2C0 clock pin',
	'I2C0_SDA:I2C0 data pin',
	'IC0:Input Capture channel 0',
	'IC2:Input capture channel 2',
	'IC3:Input capture channel 3',
	'IC4:Input capture channel 4',
	'IC5:Input capture channel 5',
	'IC6:Input capture channel 6',
	'ICE_CLK:ICP clock input',
	'ICE_DAT:ICP / ICE data input or output',
	'INT0:External interrupt 0 input',
	'INT1:External interrupt 1 input',
	'nRESET:nRESET pin',
	'OSCIN:the external clock input pin',
	'PWM0_BRAKE:PWM0 Fault Brake input',
	'PWM0_CH0:PWM0 channel 0',
	'PWM0_CH2:PWM output channel 2',
	'PWM0_CH3:PWM output channel 3',
	'PWM0_CH4:PWM output channel 4',
	'PWM0_CH5:PWM output channel',
	'SPI0_CLK:SPI clock',
	'SPI0_MISO:SPI master input/slave output',
	'SPI0_MOSI:SPI master output/slave input',
	'SPI0_SS:SPI0 slave select input',
	'STADC:External start ADC trigger',
	'T0:External count input to Timer/Counter 0 or its toggle output',
	'T1:External count input to Timer/Counter 1 or its toggle output',
	'UART0_RXD:Serial port 0 receive input',
	'UART0_TXD:Serial port 0 transmit data output',
	'UART1_RXD:Serial port 1 receive input',
	'UART1_TXD:Serial port 1 transmit data output'
];

NUTOOL_PIN.g_cfg_regDescriptions = {};
NUTOOL_PIN.g_cfg_regDescriptions.P0MF76543210 = 'This register is nonexistent';
NUTOOL_PIN.g_cfg_regDescriptions.P1MF76543210 = 'This register is nonexistent';
NUTOOL_PIN.g_cfg_regDescriptions.P2MF76543210 = 'This register is nonexistent';
NUTOOL_PIN.g_cfg_regDescriptions.P3MF76543210 = 'This register is nonexistent';

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
