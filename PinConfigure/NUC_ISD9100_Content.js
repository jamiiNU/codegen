// chip content
NUTOOL_PIN.g_cfg_chips = [
	{ name: "I9160FI", pkg: "LQFP48" },
	{ name: "I9160VFI", pkg: "LQFP48" }
];

NUTOOL_PIN.g_cfg_pkgs = {
	"LQFP48": [
		'WAKEUP', 'PB.7', 'PB.6', 'PB.5', 'PB.4', 'PB.3', 'PB.2', 'PB.1', 'PB.0', 'VCCD',
		'VREG', 'NC',
		'NC', 'PA.15', 'PA.9', 'PA.8', 'VCCSPK', 'SPK+', 'VSSSPK', 'SPK-', 'VCCSPK', 'RESETN',
		'ICE_DAT', 'ICE_CLK',
		'VSSD', 'PA.7', 'PA.6', 'PA.5', 'PA.4', 'PA.3', 'PA.2', 'VDD33', 'PA.1', 'PA.0',
		'VCCLDO', 'PA.14',
		'PA.13', 'PA.12', 'XO32K', 'XI32K', 'VSSA', 'VMID', 'MIC+', 'MIC-', 'MICBIAS', 'VCCA',
		'PA.11', 'PA.10'
	]
};

NUTOOL_PIN.g_cfg_OrCAD = {};

NUTOOL_PIN.g_cfg_gpios = [
	{ f: ['PA.0:0', 'SPI_MOSI0:1', 'MCLK:2'] },
	{ f: ['PA.1:0', 'SPI_SCLK:1', 'I2C_SCL:2'] },
	{ f: ['PA.2:0', 'SPI_SSB0:1'] },
	{ f: ['PA.3:0', 'SPI_MISO0:1', 'I2C_SDA:2'] },
	{ f: ['PA.4:0', 'I2S_FS:1'] },
	{ f: ['PA.5:0', 'I2S_BCLK:1'] },
	{ f: ['PA.6:0', 'I2S_SDI:1'] },
	{ f: ['PA.7:0', 'I2S_SDO:1'] },
	{ f: ['PA.8:0', 'UART_TX:1', 'I2S_FS:2'] },
	{ f: ['PA.9:0', 'UART_RX:1', 'I2S_BCLK:2'] },
	{ f: ['PA.10:0', 'I2C_SDA:1', 'I2S_SDI:2', 'UART_RTSn:3'] },
	{ f: ['PA.11:0', 'I2C_SCL:1', 'I2S_SDO:2', 'UART_CTSn:3'] },
	{ f: ['PA.12:0', 'PWM0CH0:1', 'SPKP:2', 'I2S_FS:3'] },
	{ f: ['PA.13:0', 'PWM0CH1:1', 'SPKM:2', 'I2S_BCLK:3'] },
	{ f: ['PA.14:0', 'TM0:1', 'SDCLK:2', 'SDCLKn:3'] },
	{ f: ['PA.15:0', 'TM1:1', 'SDIN:2'] },

	{ f: ['PB.0:0', 'SPI_SSB1:1', 'CMP0:2', 'SPI_SSB0:3'] },
	{ f: ['PB.1:0', 'MCLK:1', 'CMP1:2', 'SPI_SSB1:3'] },
	{ f: ['PB.2:0', 'I2C_SCL:1', 'CMP2:2', 'SPI_SCLK:3'] },
	{ f: ['PB.3:0', 'I2C_SDA:1', 'CMP3:2', 'SPI_MISO0:3'] },
	{ f: ['PB.4:0', 'PWM0CH0_INV:1', 'CMP4:2', 'SPI_MOSI0:3'] },
	{ f: ['PB.5:0', 'PWM0CH1_INV:1', 'CMP5:2', 'SPI_MISO1:3'] },
	{ f: ['PB.6:0', 'I2S_SDI:1', 'CMP6:2', 'SPI_MOSI1:3'] },
	{ f: ['PB.7:0', 'I2S_SDO:1', 'CMP7:2'] }
];

NUTOOL_PIN.g_cfg_gpiosDefines = [
	{ f: ['PA.0', 'SPI_MOSI0:SYS_GPA_MFP_PA0MFP_SPI_MOSI0@GPA_MFP', 'MCLK:SYS_GPA_MFP_PA0MFP_MCLK@GPA_MFP'] },
	{ f: ['PA.1', 'SPI_SCLK:SYS_GPA_MFP_PA1MFP_SPI_SCLK@GPA_MFP', 'I2C_SCL:SYS_GPA_MFP_PA1MFP_I2C_SCL@GPA_MFP'] },
	{ f: ['PA.2', 'SPI_SSB0:SYS_GPA_MFP_PA2MFP_SPI_SSB0@GPA_MFP'] },
	{ f: ['PA.3', 'SPI_MISO0:SYS_GPA_MFP_PA3MFP_SPI_MISO0@GPA_MFP', 'I2C_SDA:SYS_GPA_MFP_PA3MFP_I2C_SDA@GPA_MFP'] },
	{ f: ['PA.4', 'I2S_FS:SYS_GPA_MFP_PA4MFP_I2S_FS@GPA_MFP'] },
	{ f: ['PA.5', 'I2S_BCLK:SYS_GPA_MFP_PA5MFP_I2S_BCLK@GPA_MFP'] },
	{ f: ['PA.6', 'I2S_SDI:SYS_GPA_MFP_PA6MFP_I2S_SDI@GPA_MFP'] },
	{ f: ['PA.7', 'I2S_SDO:SYS_GPA_MFP_PA7MFP_I2S_SDO@GPA_MFP'] },
	{ f: ['PA.8', 'UART_TX:SYS_GPA_MFP_PA8MFP_UART_TX@GPA_MFP', 'I2S_FS:SYS_GPA_MFP_PA8MFP_I2S_FS@GPA_MFP'] },
	{ f: ['PA.9', 'UART_RX:SYS_GPA_MFP_PA9MFP_UART_RX@GPA_MFP', 'I2S_BCLK:SYS_GPA_MFP_PA9MFP_I2S_BCLK@GPA_MFP'] },
	{ f: ['PA.10', 'I2C_SDA:SYS_GPA_MFP_PA10MFP_I2C_SDA@GPA_MFP', 'I2S_SDI:SYS_GPA_MFP_PA10MFP_I2S_SDI@GPA_MFP', 'UART_RTSn:SYS_GPA_MFP_PA10MFP_UART_RTSn@GPA_MFP'] },
	{ f: ['PA.11', 'I2C_SCL:SYS_GPA_MFP_PA11MFP_I2C_SCL@GPA_MFP', 'I2S_SDO:SYS_GPA_MFP_PA11MFP_I2S_SDO@GPA_MFP', 'UART_CTSn:SYS_GPA_MFP_PA11MFP_UART_CTSn@GPA_MFP'] },
	{ f: ['PA.12', 'PWM0CH0:SYS_GPA_MFP_PA12MFP_PWM0CH0@GPA_MFP', 'SPKP:SYS_GPA_MFP_PA12MFP_SPKP@GPA_MFP', 'I2S_FS:SYS_GPA_MFP_PA12MFP_I2S_FS@GPA_MFP'] },
	{ f: ['PA.13', 'PWM0CH1:SYS_GPA_MFP_PA13MFP_PWM0CH1@GPA_MFP', 'SPKM:SYS_GPA_MFP_PA13MFP_SPKM@GPA_MFP', 'I2S_BCLK:SYS_GPA_MFP_PA13MFP_I2S_BCLK@GPA_MFP'] },
	{ f: ['PA.14', 'TM0:SYS_GPA_MFP_PA14MFP_TM0@GPA_MFP', 'SDCLK:SYS_GPA_MFP_PA14MFP_SDCLK@GPA_MFP', 'SDCLKn:SYS_GPA_MFP_PA14MFP_SDCLKn@GPA_MFP'] },
	{ f: ['PA.15', 'TM1:SYS_GPA_MFP_PA15MFP_TM1@GPA_MFP', 'SDIN:SYS_GPA_MFP_PA15MFP_SDIN@GPA_MFP'] },
	{ f: ['PB.0', 'SPI_SSB1:SYS_GPB_MFP_PB0MFP_SPI_SSB1@GPB_MFP', 'CMP0:SYS_GPB_MFP_PB0MFP_CMP0@GPB_MFP', 'SPI_SSB0:SYS_GPB_MFP_PB0MFP_SPI_SSB0@GPB_MFP'] },
	{ f: ['PB.1', 'MCLK:SYS_GPB_MFP_PB1MFP_MCLK@GPB_MFP', 'CMP1:SYS_GPB_MFP_PB1MFP_CMP1@GPB_MFP', 'SPI_SSB1:SYS_GPB_MFP_PB1MFP_SPI_SSB1@GPB_MFP'] },
	{ f: ['PB.2', 'I2C_SCL:SYS_GPB_MFP_PB2MFP_I2C_SCL@GPB_MFP', 'CMP2:SYS_GPB_MFP_PB2MFP_CMP2@GPB_MFP', 'SPI_SCLK:SYS_GPB_MFP_PB2MFP_SPI_SCLK@GPB_MFP'] },
	{ f: ['PB.3', 'I2C_SDA:SYS_GPB_MFP_PB3MFP_I2C_SDA@GPB_MFP', 'CMP3:SYS_GPB_MFP_PB3MFP_CMP3@GPB_MFP', 'SPI_MISO0:SYS_GPB_MFP_PB3MFP_SPI_MISO0@GPB_MFP'] },
	{ f: ['PB.4', 'PWM0CH0_INV:SYS_GPB_MFP_PB4MFP_PWM0CH0_INV@GPB_MFP', 'CMP4:SYS_GPB_MFP_PB4MFP_CMP4@GPB_MFP', 'SPI_MOSI0:SYS_GPB_MFP_PB4MFP_SPI_MOSI0@GPB_MFP'] },
	{ f: ['PB.5', 'PWM0CH1_INV:SYS_GPB_MFP_PB5MFP_PWM0CH1_INV@GPB_MFP', 'CMP5:SYS_GPB_MFP_PB5MFP_CMP5@GPB_MFP', 'SPI_MISO1:SYS_GPB_MFP_PB5MFP_SPI_MISO1@GPB_MFP'] },
	{ f: ['PB.6', 'I2S_SDI:SYS_GPB_MFP_PB6MFP_I2S_SDI@GPB_MFP', 'CMP6:SYS_GPB_MFP_PB6MFP_CMP6@GPB_MFP', 'SPI_MOSI1:SYS_GPB_MFP_PB6MFP_SPI_MOSI1@GPB_MFP'] },
	{ f: ['PB.7', 'I2S_SDO:SYS_GPB_MFP_PB7MFP_I2S_SDO@GPB_MFP', 'CMP7:SYS_GPB_MFP_PB7MFP_CMP7@GPB_MFP'] }
];

NUTOOL_PIN.g_cfg_gpiosDescriptions = [
	'CMP0:Configure as relaxation oscillator for capacitive touch sensing',
	'CMP1:Configure as relaxation oscillator for capacitive touch sensing',
	'CMP2:Configure as relaxation oscillator for capacitive touch sensing',
	'CMP3:Configure as relaxation oscillator for capacitive touch sensing',
	'CMP4:Configure as relaxation oscillator for capacitive touch sensing',
	'CMP5:Configure as relaxation oscillator for capacitive touch sensing',
	'CMP6:Configure as relaxation oscillator for capacitive touch sensing',
	'CMP7:Configure as relaxation oscillator for capacitive touch sensing',

	'I2C_SCL:Serial Clock, I2C interface',
	'I2C_SDA:Serial Data, I2C interface',
	'I2S_BCLK:Bit Clock for I2S interface',

	'I2S_FS:Frame Sync Clock for I2S interface',
	'I2S_SDI:Serial Data Input for I2S interface',
	'I2S_SDO:Serial Data Output for I2S interface',

	'ICE_CLK:Serial Wire Debug port clock pin. Has internal weak pull-up',
	'ICE_DAT:Serial Wire Debug port data pin. Has internal weak pull-up',

	'MCLK:Master clock output for synchronizing external device',
	'MIC-:Negative microphone input',
	'MIC+:Positive microphone input',
	'MICBIAS:Microphone bias output',
	'NC :Should remain unconnected',

	'PWM0CH0:PWM0 channel 0 Output',
	'PWM0CH0_INV:Invert PWM0 channel 0 output pin',
	'PWM0CH1:PWM0 channel 1 Output',
	'PWM0CH1_INV:Invert PWM0 channel 1 output pin',

	'RESETN:External reset input. Pull this pin low to reset device to initial state. Has internal weak pull-up',

	'SDCLK:Clock output for digital microphone mode',
	'SDCLKn:Inverse Clock output for digital microphone mode',
	'SDIN:Sigma Delta bit stream input for digital MIC mode',

	'SPI_MISO0:Master In, Slave Out channel 0 for SPI interface',
	'SPI_MISO1:Master In, Slave Out channel 1 for SPI interface',
	'SPI_MOSI0:Master Out, Slave In channel 0 for SPI interface',
	'SPI_MOSI1:Master Out, Slave In channel 1 for SPI interface',
	'SPI_SCLK:Serial Clock for SPI interface',
	'SPI_SSB0:Slave Select Bar 0 for SPI interface',
	'SPI_SSB1:Slave Select Bar 1 for SPI interface',

	'SPK-:Negative Speaker Driver Output',
	'SPK+:Positive Speaker Driver Output',
	'SPKM:Equivalent to SPK-',
	'SPKP:Equivalent to SPK+',

	'TM0:External input to Timer 0',
	'TM1:External input to Timer 1',

	'UART_CTSn:UART Clear to Send Input',
	'UART_RTSn:UART Request to Send Output',
	'UART_RX:Receive channel of UART',
	'UART_TX:Transmit  channel of UART',

	'VCCA:Analog power supply',
	'VCCD:Main Digital Supply for Chip. Supplies all IO except analog, Speaker Driver and PA<7:0>',
	'VCCLDO:Power Supply for LDO, should be connected to VCCD',
	'VCCSPK:Power Supply for PWM Speaker Driver',
	'VDD33:LDO Regulator Output. If used, a 1&#181F capacitor must be placed to ground. If not used then tie to VCCD',

	'VMID:Mid rail reference. Connect 4.7&#181F to VSSA',
	'VREG:Logic regulator output decoupling pin. A 1&#181F capacitor returning to VSSD must be placed on this pin',
	'VSSA:Ground for analog circuitry',
	'VSSD:Digital Ground',
	'VSSSPK:Ground for PWM Speaker Driver',

	'WAKEUP:Pull low to wake part from deep power down',

	'XI32K:32.768kHz Crystal Oscillator Input. Max Voltage 1.8V',
	'XO32K:32.768kHz Crystal Oscillator Output'
];

NUTOOL_PIN.g_cfg_regDescriptions = {};
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
