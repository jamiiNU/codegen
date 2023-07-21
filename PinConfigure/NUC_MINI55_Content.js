// chip content
NUTOOL_PIN.g_cfg_chips = [
	//MINI51DE
	{ name: "MINI51LDE", pkg: "LQFP48" },
	{ name: "MINI52LDE", pkg: "LQFP48" },
	{ name: "MINI54LDE", pkg: "LQFP48" },

	{ name: "MINI51ZDE", pkg: "QFN33" },
	{ name: "MINI52ZDE", pkg: "QFN33" },
	{ name: "MINI54ZDE", pkg: "QFN33" },

	{ name: "MINI51TDE", pkg: "QFN33" },
	{ name: "MINI52TDE", pkg: "QFN33" },
	{ name: "MINI54TDE", pkg: "QFN33" },

	{ name: "MINI51FDE", pkg: "TSSOP20" },
	{ name: "MINI52FDE", pkg: "TSSOP20" },
	{ name: "MINI54FDE", pkg: "TSSOP20" },

	//{ name: "MINI54FHC", pkg: "TSSOP20" },
	//MINI55
	//{ name: "NVS06AL", pkg: "LQFP48" },
	{ name: "MINI55LDE", pkg: "LQFP48" },
	{ name: "MINI55ZDE", pkg: "QFN33" },

	//{ name: "MINI51XLAE", pkg: "LQFP48" },
	//{ name: "MINI52XLAE", pkg: "LQFP48" },
	//{ name: "MINI54XLAE", pkg: "LQFP48" },

	//{ name: "MINI55TDE", pkg: "QFN33" },
	//{ name: "MINI51XZAE", pkg: "QFN33" },
	//{ name: "MINI52XZAE", pkg: "QFN33" },
	//{ name: "MINI54XZAE", pkg: "QFN33" },
	//{ name: "MINI54XFHC", pkg: "TSSOP20" },
	//MINI57
	{ name: "MINI57TDE", pkg: "QFN33" },
	{ name: "MINI57EDE", pkg: "TSSOP28" },
	{ name: "MINI57FDE", pkg: "TSSOP20" },
	//MINI58
	{ name: "MINI58LDE", pkg: "LQFP48" },

	{ name: "MINI58ZDE", pkg: "QFN33" },
	{ name: "MINI58TDE", pkg: "QFN33" },

	{ name: "MINI58FDE", pkg: "TSSOP20" }
];

NUTOOL_PIN.g_cfg_pkgs = {
	"LQFP48": [
		'NC', 'P1.5', '/RESET', 'P3.0', 'AVSS', 'P5.4', 'P3.1', 'P3.2', 'P3.4', 'P3.5',
		'P3.7', 'NC',
		'NC', 'P3.6', 'P5.1', 'P5.0', 'VSS', 'LDO_CAP', 'P5.5', 'P5.2', 'NC', 'P2.2',
		'P2.3', 'P2.4',
		'P2.5', 'P2.6', 'P2.7', 'NC', 'P4.6', 'P4.7', 'NC', 'P0.7', 'P0.6', 'P0.5',
		'P0.4', 'NC',
		'P0.1', 'P0.0', 'NC', 'NC', 'P5.3', 'VDD', 'AVDD', 'P1.0', 'P1.2', 'P1.3',
		'P1.4', 'P1.6'
	],
	"QFN33": [
		'P1.5', '/RESET', 'P3.0', 'P5.4', 'P3.1', 'P3.2', 'P3.4', 'P3.5',
		'P3.6', 'P5.1', 'P5.0', 'VSS', 'P5.2', 'P2.2', 'P2.3', 'P2.4',
		'P2.5', 'P2.6', 'P4.6', 'P4.7', 'P0.7', 'P0.6', 'P0.5', 'P0.4',
		'P0.1', 'P0.0', 'P5.3', 'VDD', 'P1.0', 'P1.2', 'P1.3', 'P1.4'
	],
	"TSSOP20": [
		'VDD', 'P1.2', 'P1.3', 'P1.4', '/RESET',
		'P3.2', 'P3.4', 'P3.5', 'VSS', 'P2.2',
		'P2.3', 'P2.4', 'P2.5', 'P2.6', 'P4.6',
		'P4.7', 'P0.7', 'P0.6', 'P0.5', 'P0.4'
	]
};

NUTOOL_PIN.g_cfg_OrCAD = {};

NUTOOL_PIN.g_cfg_gpios = [
	{ f: ['P0.0:0', 'CTSn:2', 'TX0:3'] },
	{ f: ['P0.1:0', 'SPISS:1', 'RTSn:2', 'RX0:3'] },
	{ f: ['P0.2:0'] },
	{ f: ['P0.3:0'] },
	{ f: ['P0.4:0', 'SPISS:2', 'PWM5:3'] },
	{ f: ['P0.5:0', 'MOSI:2'] },
	{ f: ['P0.6:0', 'MISO:2'] },
	{ f: ['P0.7:0', 'SPICLK:2'] },

	{ f: ['P1.0:0', 'AIN1:1', 'ACMP0_P:3'] },
	{ f: ['P1.1:0'] },
	{ f: ['P1.2:0', 'AIN2:1', 'RX0:2', 'ACMP0_P:3'] },
	{ f: ['P1.3:0', 'AIN3:1', 'TX0:2', 'ACMP0_P:3', 'INT0:5'] },
	{ f: ['P1.4:0', 'AIN4:1', 'RX1:2', 'ACMP0_N:3'] },
	{ f: ['P1.5:0', 'AIN5:1', 'TX1:2', 'ACMP0_P:3'] },
	{ f: ['P1.6:0'] },
	{ f: ['P1.7:0'] },

	{ f: ['P2.0:0'] },
	{ f: ['P2.1:0'] },
	{ f: ['P2.2:0', 'PWM0:2'] },
	{ f: ['P2.3:0', 'PWM1:2'] },
	{ f: ['P2.4:0', 'PWM2:2', 'RX1:3'] },
	{ f: ['P2.5:0', 'PWM3:2', 'TX1:3'] },
	{ f: ['P2.6:0', 'PWM4:2', 'ACMP1_O:3'] },
	{ f: ['P2.7:0'] },

	{ f: ['P3.0:0', 'ACMP1_N:2', 'AIN6:3'] },
	{ f: ['P3.1:0', 'ACMP1_P:2', 'AIN7:3'] },
	{ f: ['P3.2:0', 'INT0:1', 'T0EX:2', 'STADC:3', 'ACMP1_P:7'] },
	{ f: ['P3.3:0'] },
	{ f: ['P3.4:0', 'T0:1', 'SDA:2', 'ACMP1_P_and_AIN9:3'] },
	{ f: ['P3.5:0', 'T1:1', 'SCL:2', 'ACMP1_P_and_AIN10:3'] },
	{ f: ['P3.6:0', 'T1EX:1', 'CKO:2', 'ACMP0_O:3', 'AIN11:7'] },
	{ f: ['P3.7:0'] },

	{ f: ['P4.0:0'] },
	{ f: ['P4.1:0'] },
	{ f: ['P4.2:0'] },
	{ f: ['P4.3:0'] },
	{ f: ['P4.4:0'] },
	{ f: ['P4.5:0'] },
	{ f: ['P4.6:0', 'ICE_CLK:1'] },
	{ f: ['P4.7:0', 'ICE_DAT:1'] },

	{ f: ['P5.0:0', 'XTAL1:1'] },
	{ f: ['P5.1:0', 'XTAL2:1'] },
	{ f: ['P5.2:0', 'INT1:1'] },
	{ f: ['P5.3:0', 'AIN0:1', 'ADC_VREF:5'] },
	{ f: ['P5.4:0', 'AIN8:3'] },
	{ f: ['P5.5:0'] },
	{ f: ['P5.6:0'] },
	{ f: ['P5.7:0'] }
];

NUTOOL_PIN.g_cfg_gpiosDefines = [
	// { f: ['P0.0', 'CTS:SYS_MFP_P00_CTS@MFP_P00', 'TXD:SYS_MFP_P00_TXD@MFP_P00'] },
	// { f: ['P0.1', 'SPISS:SYS_MFP_P01_SPISS@MFP_P01', 'RTS:SYS_MFP_P01_RTS@MFP_P01', 'RXD:SYS_MFP_P01_RXD@MFP_P01'] },
	// { f: ['P0.4', 'SPISS:SYS_MFP_P04_SPISS@MFP_P04', 'PWM5:SYS_MFP_P04_PWM5@MFP_P04'] },
	// { f: ['P0.5', 'MOSI:SYS_MFP_P05_MOSI@MFP_P05'] },
	// { f: ['P0.6', 'MISO:SYS_MFP_P06_MISO@MFP_P06'] },
	// { f: ['P0.7', 'SPICLK:SYS_MFP_P07_SPICLK@MFP_P07'] },
	// { f: ['P1.0', 'AIN1:SYS_MFP_P10_AIN1@MFP_P10', 'CPP0:SYS_MFP_P10_CPP0@MFP_P10'] },
	// { f: ['P1.2', 'AIN2:SYS_MFP_P12_AIN2@MFP_P12', 'RXD:SYS_MFP_P12_RXD@MFP_P12', 'CPP0:SYS_MFP_P12_CPP0@MFP_P12'] },
	// { f: ['P1.3', 'AIN3:SYS_MFP_P13_AIN3@MFP_P13', 'TXD:SYS_MFP_P13_TXD@MFP_P13', 'CPP0:SYS_MFP_P13_CPP0@MFP_P13'] },
	// { f: ['P1.4', 'AIN4:SYS_MFP_P14_AIN4@MFP_P14', 'CPN0:SYS_MFP_P14_CPN0@MFP_P14'] },
	// { f: ['P1.5', 'AIN5:SYS_MFP_P15_AIN5@MFP_P15', 'CPP0:SYS_MFP_P15_CPP0@MFP_P15'] },
	// { f: ['P2.2', 'PWM0:SYS_MFP_P22_PWM0@MFP_P22'] },
	// { f: ['P2.3', 'PWM1:SYS_MFP_P23_PWM1@MFP_P23'] },
	// { f: ['P2.4', 'PWM2:SYS_MFP_P24_PWM2@MFP_P24', 'RX1:SYS_MFP_P24_RX1@MFP_P24'] },
	// { f: ['P2.5', 'PWM3:SYS_MFP_P25_PWM3@MFP_P25', 'TX1:SYS_MFP_P25_TX1@MFP_P25'] },
	// { f: ['P2.6', 'PWM4:SYS_MFP_P26_PWM4@MFP_P26', 'CPO1:SYS_MFP_P26_CPO1@MFP_P26'] },
	// { f: ['P3.0', 'CPN1:SYS_MFP_P30_CPN1@MFP_P30', 'AIN6:SYS_MFP_P30_AIN6@MFP_P30'] },
	// { f: ['P3.1', 'CPP1:SYS_MFP_P31_CPP1@MFP_P31', 'AIN7:SYS_MFP_P31_AIN7@MFP_P31'] },
	// { f: ['P3.2', 'INT0:SYS_MFP_P32_INT0@MFP_P32', 'T0EX:SYS_MFP_P32_T0EX@MFP_P32', 'STADC:SYS_MFP_P32_STADC@MFP_P32'] },
	// { f: ['P3.4', 'T0:SYS_MFP_P34_T0@MFP_P34', 'SDA:SYS_MFP_P34_SDA@MFP_P34', 'CPP1:SYS_MFP_P34_CPP1@MFP_P34'] },
	// { f: ['P3.5', 'T1:SYS_MFP_P35_T1@MFP_P35', 'SCL:SYS_MFP_P35_SCL@MFP_P35', 'CPP1:SYS_MFP_P35_CPP1@MFP_P35'] },
	// { f: ['P3.6', 'T1EX:SYS_MFP_P36_T1EX@MFP_P36', 'CKO:SYS_MFP_P36_CKO@MFP_P36', 'CPO0:SYS_MFP_P36_CPO0@MFP_P36'] },
	// { f: ['P4.6', 'ICE_CLK:SYS_MFP_P46_ICE_CLK@MFP_P46'] },
	// { f: ['P4.7', 'ICE_DAT:SYS_MFP_P47_ICE_DAT@MFP_P47'] },
	// { f: ['P5.0', 'XTAL1:SYS_MFP_P50_XTAL1@MFP_P50'] },
	// { f: ['P5.1', 'XTAL2:SYS_MFP_P51_XTAL2@MFP_P51'] },
	// { f: ['P5.2', 'INT1:SYS_MFP_P52_INT1@MFP_P52'] },
	// { f: ['P5.3', 'AIN0:SYS_MFP_P53_AIN0@MFP_P53'] },
	// { f: ['P5.4'] },
	// { f: ['P5.5'] }
];

NUTOOL_PIN.g_cfg_gpiosDescriptions = [
	'/RESET:The Schmitt trigger input pin for hardware device reset. A "Low" on this pin for 768 clock counter of Internal RC 22.1184 MHz while the system clock is running will reset the device. /RESET pin has an internal pull-up resistor allowing power-on reset by simply connecting an external capacitor to GND',

	'ACMP0_N:Analog comparator negative input pin',
	'ACMP0_O:Analog comparator output pin',
	'ACMP0_P:Analog comparator positive input pin',
	'ACMP1_N:Analog comparator negative input pin',
	'ACMP1_O:Analog comparator output pin',
	'ACMP1_P:Analog comparator positive input pin',
	'ACMP1_P_and_AIN9:Analog comparator positive input pin / ADC analog input pin',
	'ACMP1_P_and_AIN10:Analog comparator positive input pin / ADC analog input pin',

	'ADC_VREF:External voltage reference of ADC',

	'AIN0:ADC analog input pin',
	'AIN1:ADC analog input pin',
	'AIN2:ADC analog input pin',
	'AIN3:ADC analog input pin',
	'AIN4:PWM5: PWM output/Capture input',
	'AIN5:ADC analog input pin',
	'AIN6:ADC analog input pin',
	'AIN7:ADC analog input pin',
	'AIN8:ADC analog input pin',
	'AIN9:ADC analog input pin',
	'AIN10:ADC analog input pin',
	'AIN11:ADC analog input pin',

	'AVDD:Power supply for analog circuit',
	'AVSS:Ground pin for analog circuit',

	'CKO:Frequency divider output pin',
	'CTSn:UART0 CTS pin',

	'ICE_CLK:Serial wired debugger clock pin',
	'ICE_DAT:Serial wired debugger data pin',
	'INT0:External interrupt 0 input pin',
	'INT1:External interrupt 1 input pin',
	'LDO_CAP:LDO output pin',

	'MISO:SPI MISO (master in/slave out) pin',
	'MOSI:SPI MOSI (master out/slave in) pin',
	'NC:Not connected',

	'PWM0:PWM0 output of PWM unit',
	'PWM1:PWM1 output of PWM unit',
	'PWM2:PWM2 output of PWM unit',
	'PWM3:PWM3 output of PWM unit',
	'PWM4:PWM4 output of PWM unit',
	'PWM5:PWM5 output of PWM unit',

	'RTSn:UART0 RTS pin',
	'RX:UART data receiver input pin',
	'RX0:UART0 data receiver input pin',
	'RX1:UART1 data receiver input pin',

	'SCL:I2C clock I/O pin',
	'SDA:I2C data I/O pin',
	'SPICLK:SPI serial clock pin',
	'SPISS:SPI slave select pin',
	'STADC:ADC external trigger input pin',

	'T0:Timer 0 external event counter input pin',
	'T0EX:Timer 0 external capture/reset trigger input pin',
	'T1:Timer 1 external event counter input pin',
	'T1EX:Timer 1 external capture/reset trigger input pin',
	'TX:UART transmitter output pin',
	'TX0:UART0 transmitter output pin',
	'TX1:UART1 transmitter output pin',

	'VDD:Power supply for digital circuit',
	'VSS:Ground pin for digital circuit',

	'XTAL1:The input pin to the internal inverting amplifier. The system clock could be from external crystal or resonator',
	'XTAL2:The output pin from the internal inverting amplifier. It emits the inverted signal of XTAL1'
];

NUTOOL_PIN.g_cfg_regDescriptions = {};
NUTOOL_PIN.g_cfg_regDescriptions.P0_MFP = '0x50000030';
NUTOOL_PIN.g_cfg_regDescriptions.P1_MFP = '0x50000034';
NUTOOL_PIN.g_cfg_regDescriptions.P2_MFP = '0x50000038';
NUTOOL_PIN.g_cfg_regDescriptions.P3_MFP = '0x5000003C';
NUTOOL_PIN.g_cfg_regDescriptions.P4_MFP = '0x50000040';
NUTOOL_PIN.g_cfg_regDescriptions.P5_MFP = '0x50000044';
NUTOOL_PIN.g_cfg_regDescriptions.ADCHER = '0x400E0024';

NUTOOL_PIN.g_cfg_gpioMatrix = [
	{ f: ['P0.0', 'P0_MFP[0]:0', 'P0_MFP[8]:1'] },
	{ f: ['P0.1', 'P0_MFP[1]:0', 'P0_MFP[9]:1'] },
	{ f: ['P0.2'] },
	{ f: ['P0.3'] },
	{ f: ['P0.4', 'P0_MFP[4]:0', 'P0_MFP[12]:1'] },
	{ f: ['P0.5', 'P0_MFP[5]:0', 'P0_MFP[13]:1'] },
	{ f: ['P0.6', 'P0_MFP[6]:0', 'P0_MFP[14]:1'] },
	{ f: ['P0.7', 'P0_MFP[7]:0', 'P0_MFP[15]:1'] },

	{ f: ['P1.0', 'P1_MFP[0]:0', 'P1_MFP[8]:1'] },
	{ f: ['P1.1'] },
	{ f: ['P1.2', 'P1_MFP[2]:0', 'P1_MFP[10]:1'] },
	{ f: ['P1.3', 'P1_MFP[3]:0', 'P1_MFP[11]:1', 'PIN_SEL[0]:2'] },
	{ f: ['P1.4', 'P1_MFP[4]:0', 'P1_MFP[12]:1'] },
	{ f: ['P1.5', 'P1_MFP[5]:0', 'P1_MFP[13]:1'] },
	{ f: ['P1.6'] },
	{ f: ['P1.7'] },

	{ f: ['P2.0'] },
	{ f: ['P2.1'] },
	{ f: ['P2.2', 'P2_MFP[2]:0', 'P2_MFP[10]:1'] },
	{ f: ['P2.3', 'P2_MFP[3]:0', 'P2_MFP[11]:1'] },
	{ f: ['P2.4', 'P2_MFP[4]:0', 'P2_MFP[12]:1'] },
	{ f: ['P2.5', 'P2_MFP[5]:0', 'P2_MFP[13]:1'] },
	{ f: ['P2.6', 'P2_MFP[6]:0', 'P2_MFP[14]:1'] },
	{ f: ['P2.7'] },

	{ f: ['P3.0', 'P3_MFP[0]:0', 'P3_MFP[8]:1'] },
	{ f: ['P3.1', 'P3_MFP[1]:0', 'P3_MFP[9]:1'] },
	{ f: ['P3.2', 'P3_MFP[2]:0', 'P3_MFP[10]:1', 'P3_MFP[24]:2'] },
	{ f: ['P3.3'] },
	{ f: ['P3.4', 'P3_MFP[4]:0', 'P3_MFP[12]:1'] },
	{ f: ['P3.5', 'P3_MFP[5]:0', 'P3_MFP[13]:1'] },
	{ f: ['P3.6', 'P3_MFP[6]:0', 'P3_MFP[14]:1', 'ADCHER[12]:2'] },
	{ f: ['P3.7'] },

	{ f: ['P4.0'] },
	{ f: ['P4.1'] },
	{ f: ['P4.2'] },
	{ f: ['P4.3'] },
	{ f: ['P4.4'] },
	{ f: ['P4.5'] },
	{ f: ['P4.6', 'P4_MFP[6]:0', 'P4_MFP[14]:1'] },
	{ f: ['P4.7', 'P4_MFP[7]:0', 'P4_MFP[15]:1'] },

	{ f: ['P5.0', 'P5_MFP[0]:0', 'P5_MFP[8]:1'] },
	{ f: ['P5.1', 'P5_MFP[1]:0', 'P5_MFP[9]:1'] },
	{ f: ['P5.2', 'P5_MFP[2]:0', 'P5_MFP[10]:1'] },
	{ f: ['P5.3', 'P5_MFP[3]:0', 'P5_MFP[11]:1', 'ADCR[12]:2'] },
	{ f: ['P5.4', 'P5_MFP[4]:0', 'P5_MFP[12]:1'] },
	{ f: ['P5.5'] },
	{ f: ['P5.6'] },
	{ f: ['P5.7'] }
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
