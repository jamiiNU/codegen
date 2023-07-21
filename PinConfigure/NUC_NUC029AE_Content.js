// chip content
NUTOOL_PIN.g_cfg_chips = [
	// NUC029AE
	{ name: "NUC029FAE", pkg: "TSSOP20" },
	// NUC029TAE
	{ name: "NUC029TAE", pkg: "QFN33" },
	// NUC029AN
	{ name: "NUC029LAN", pkg: "LQFP48" },
	{ name: "NUC029NAN", pkg: "QFN48" },
	{ name: "NUC029TAN", pkg: "QFN33" },
	// NUC029xDE
	{ name: "NUC029LDE", pkg: "LQFP48" },
	{ name: "NUC029SDE", pkg: "LQFP64" },
	// NUC029xGE
	{ name: "NUC029LGE", pkg: "LQFP48" },
	{ name: "NUC029SGE", pkg: "LQFP64" },
	// NUC029KGE
	{ name: "NUC029KGE", pkg: "LQFP128" },
	// NUC029xEE
	{ name: "NUC029LEE", pkg: "LQFP48" },
	{ name: "NUC029SEE", pkg: "LQFP64" },
	// NUC029MDE
	//{ name: "NUC029MDE", pkg: "LQFP44" },
	// NUC029ZAN
	{ name: "NUC029ZAN", pkg: "QFN33" }
];

NUTOOL_PIN.g_cfg_pkgs = {
	"TSSOP20": [
		'P1.2', 'P1.3', 'P1.4', 'P1.5', 'nRST',
		'P3.2', 'P3.4', 'P3.5', 'P5.1', 'P5.0',
		'VSS', 'P2.4', 'P2.5', 'P4.6', 'P4.7',
		'P0.7', 'P0.6', 'P0.5', 'P0.4', 'VDD'
	]
};

NUTOOL_PIN.g_cfg_OrCAD = {};

NUTOOL_PIN.g_cfg_gpios = [
	{ f: ['P0.0:0', 'CTSn:2', 'TX:3'] },
	{ f: ['P0.1:0', 'SPISS:1', 'RTSn:2', 'RX:3'] },
	{ f: ['P0.2:0'] },
	{ f: ['P0.3:0'] },
	{ f: ['P0.4:0', 'SPISS0:2', 'PWM5:3'] },
	{ f: ['P0.5:0', 'MOSI_0:2'] },
	{ f: ['P0.6:0', 'MISO_0:2'] },
	{ f: ['P0.7:0', 'SPICLK0:2'] },

	{ f: ['P1.0:0', 'AIN1:1', 'ACMP0_P:3'] },
	{ f: ['P1.1:0'] },
	{ f: ['P1.2:0', 'AIN2:1', 'RXD:2', 'ACMP0_P:3'] },
	{ f: ['P1.3:0', 'AIN3:1', 'TXD:2', 'ACMP0_P:3'] },
	{ f: ['P1.4:0', 'AIN4:1', 'ACMP0_N:3'] },
	{ f: ['P1.5:0', 'AIN5:1', 'ACMP0_P:3'] },
	{ f: ['P1.6:0'] },
	{ f: ['P1.7:0'] },

	{ f: ['P2.0:0'] },
	{ f: ['P2.1:0'] },
	{ f: ['P2.2:0', 'PWM0:2'] },
	{ f: ['P2.3:0', 'PWM1:2'] },
	{ f: ['P2.4:0', 'PWM2:2'] },
	{ f: ['P2.5:0', 'PWM3:2'] },
	{ f: ['P2.6:0', 'PWM4:2', 'ACMP1_O:3'] },
	{ f: ['P2.7:0'] },

	{ f: ['P3.0:0', 'ACMP1_N:2', 'AIN6:3'] },
	{ f: ['P3.1:0', 'ACMP1_P:2', 'AIN7:3'] },
	{ f: ['P3.2:0', 'nINT0:1', 'T0EX:2', 'STADC:3', 'ACMP1_P:4'] },
	{ f: ['P3.3:0'] },
	{ f: ['P3.4:0', 'T0:1', 'SDA0:2', 'ACMP1_P:3'] },
	{ f: ['P3.5:0', 'T1:1', 'SCL0:2', 'ACMP1_P:3'] },
	{ f: ['P3.6:0', 'T1EX:1', 'CKO:2', 'ACMP0_O:3'] },
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
	{ f: ['P5.3:0', 'AIN0:1'] },
	{ f: ['P5.4:0'] },
	{ f: ['P5.5:0'] }
];

NUTOOL_PIN.g_cfg_gpiosDefines = [
	{ f: ['P0.0', 'CTSn:SYS_MFP_P00_CTS@P0_MFP', 'TX:SYS_MFP_P00_TXD@P0_MFP'] },
	{ f: ['P0.1', 'SPISS:SYS_MFP_P01_SPISS@P0_MFP', 'RTSn:SYS_MFP_P01_RTS@P0_MFP', 'RX:SYS_MFP_P01_RXD@P0_MFP'] },
	{ f: ['P0.2'] },
	{ f: ['P0.3'] },
	{ f: ['P0.4', 'SPISS0:SYS_MFP_P04_SPISS@P0_MFP', 'PWM5:SYS_MFP_P04_PWM5@P0_MFP'] },
	{ f: ['P0.5', 'MOSI_0:SYS_MFP_P05_MOSI@P0_MFP'] },
	{ f: ['P0.6', 'MISO_0:SYS_MFP_P06_MISO@P0_MFP'] },
	{ f: ['P0.7', 'SPICLK0:SYS_MFP_P07_SPICLK@P0_MFP'] },

	{ f: ['P1.0', 'AIN1:SYS_MFP_P10_AIN1@P1_MFP', 'ACMP0_P:SYS_MFP_P10_CPP0@P1_MFP'] },
	{ f: ['P1.1'] },
	{ f: ['P1.2', 'AIN2:SYS_MFP_P12_AIN2@P1_MFP', 'RXD:SYS_MFP_P12_RXD@P1_MFP', 'ACMP0_P:SYS_MFP_P12_CPP0@P1_MFP'] },
	{ f: ['P1.3', 'AIN3:SYS_MFP_P13_AIN3@P1_MFP', 'TXD:SYS_MFP_P13_TXD@P1_MFP', 'ACMP0_P:SYS_MFP_P13_CPP0@P1_MFP'] },
	{ f: ['P1.4', 'AIN4:SYS_MFP_P14_AIN4@P1_MFP', 'ACMP0_N:SYS_MFP_P14_CPN0@P1_MFP'] },
	{ f: ['P1.5', 'AIN5:SYS_MFP_P15_AIN5@P1_MFP', 'ACMP0_P:SYS_MFP_P15_CPP0@P1_MFP'] },
	{ f: ['P1.6'] },
	{ f: ['P1.7'] },

	{ f: ['P2.0'] },
	{ f: ['P2.1'] },
	{ f: ['P2.2', 'PWM0:SYS_MFP_P22_PWM0@P2_MFP'] },
	{ f: ['P2.3', 'PWM1:SYS_MFP_P23_PWM1@P2_MFP'] },
	{ f: ['P2.4', 'PWM2:SYS_MFP_P24_PWM2@P2_MFP'] },
	{ f: ['P2.5', 'PWM3:SYS_MFP_P25_PWM3@P2_MFP'] },
	{ f: ['P2.6', 'PWM4:SYS_MFP_P26_PWM4@P2_MFP', 'ACMP1_O:SYS_MFP_P26_CPO1@P2_MFP'] },
	{ f: ['P2.7'] },

	{ f: ['P3.0', 'ACMP1_N:SYS_MFP_P30_CPN1@P3_MFP', 'AIN6:SYS_MFP_P30_AIN6@P3_MFP'] },
	{ f: ['P3.1', 'ACMP1_P:SYS_MFP_P31_CPP1@P3_MFP', 'AIN7:SYS_MFP_P31_AIN7@P3_MFP'] },
	{ f: ['P3.2', 'nINT0:SYS_MFP_P32_INT0@P3_MFP', 'T0EX:SYS_MFP_P32_T0EX@P3_MFP', 'STADC:SYS_MFP_P32_STADC@P3_MFP', 'ACMP1_P:SYS_MFP_P32_CPP1@P3_MFP'] },
	{ f: ['P3.3'] },
	{ f: ['P3.4', 'T0:SYS_MFP_P34_T0@P3_MFP', 'SDA0:SYS_MFP_P34_SDA@P3_MFP', 'ACMP1_P:SYS_MFP_P34_CPP1@P3_MFP'] },
	{ f: ['P3.5', 'T1:SYS_MFP_P35_T1@P3_MFP', 'SCL0:SYS_MFP_P35_SCL@P3_MFP', 'ACMP1_P:SYS_MFP_P35_CPP1@P3_MFP'] },
	{ f: ['P3.6', 'T1EX:SYS_MFP_P36_T1EX@P3_MFP', 'CKO:SYS_MFP_P36_CKO@P3_MFP', 'ACMP0_O:SYS_MFP_P36_CPO0@P3_MFP'] },
	{ f: ['P3.7'] },

	{ f: ['P4.0'] },
	{ f: ['P4.1'] },
	{ f: ['P4.2'] },
	{ f: ['P4.3'] },
	{ f: ['P4.4'] },
	{ f: ['P4.5'] },
	{ f: ['P4.6', 'ICE_CLK:SYS_MFP_P46_ICE_CLK@P4_MFP'] },
	{ f: ['P4.7', 'ICE_DAT:SYS_MFP_P47_ICE_DAT@P4_MFP'] },

	{ f: ['P5.0', 'XTAL1:SYS_MFP_P50_XTAL1@P5_MFP'] },
	{ f: ['P5.1', 'XTAL2:SYS_MFP_P51_XTAL2@P5_MFP'] },
	{ f: ['P5.2', 'INT1:SYS_MFP_P52_INT1@P5_MFP'] },
	{ f: ['P5.3', 'AIN0:SYS_MFP_P53_AIN0@P5_MFP'] },
	{ f: ['P5.4'] },
	{ f: ['P5.5'] }
];

NUTOOL_PIN.g_cfg_gpiosDescriptions = [
	'ACMP0_N:Comparator0 negative input pin',
	'ACMP0_O:Analog comparator0 output pin',
	'ACMP0_P:Comparator0 positive input pin',
	'ACMP1_N:Comparator1 negative input pin',
	'ACMP1_O:Analog comparator1 output pin',
	'ACMP1_P:Comparator1 positive input pin',
	'ACMP2_N:Comparator2 negative input pin',
	'ACMP2_P:Comparator2 positive input pin',
	'ACMP3_N:Comparator3 negative input pin',
	'ACMP3_P:Comparator3 positive input pin',

	'AD0:EBI Address/Data bus bit0',
	'AD1:EBI Address/Data bus bit1',
	'AD2:EBI Address/Data bus bit2',
	'AD3:EBI Address/Data bus bit3',
	'AD4:EBI Address/Data bus bit4',
	'AD5:EBI Address/Data bus bit5',
	'AD6:EBI Address/Data bus bit6',
	'AD7:EBI Address/Data bus bit7',
	'AD8:EBI Address/Data bus bit8',
	'AD9:EBI Address/Data bus bit9',
	'AD10:EBI Address/Data bus bit10',
	'AD11:EBI Address/Data bus bit11',
	'AD12:EBI Address/Data bus bit12',
	'AD13:EBI Address/Data bus bit13',
	'AD14:EBI Address/Data bus bit14',
	'AD15:EBI Address/Data bus bit15',

	'AIN0:ADC0 analog input',
	'AIN1:ADC1 analog input',
	'AIN2:ADC2 analog input',
	'AIN3:ADC3 analog input',
	'AIN4:ADC4 analog input',
	'AIN5:ADC5 analog input',
	'AIN6:ADC6 analog input',
	'AIN7:ADC7 analog input',

	'ALE:EBI address latch enable output pin',
	'AVDD:Power supply for internal analog circuit',
	'AVSS:Ground pin for analog circuit',

	'CKO:Frequency divider output pin',

	'CTS0:Clear to Send input pin for UART0',
	'CTS1:Clear to Send input pin for UART1',

	'ICE_CLK:Serial Wired Debugger Clock pin',
	'ICE_DAT:Serial Wired Debugger Data pin',

	'LDO_CAP:LDO output pin',
	'MCLK:EBI external clock output pin',
	'MISO_0:SPI0 MISO (Master In, Slave Out) pin',
	'MISO_1:SPI1 MISO (Master In, Slave Out) pin',
	'MOSI_0:SPI0 MOSI (Master Out, Slave In) pin',
	'MOSI_1:SPI1 MOSI (Master Out, Slave In) pin',

	'nCS:EBI chip select enable output pin',
	'nINT0:External interrupt0 input pin',
	'nINT1:External interrupt1 input pin',
	'nRD:EBI read enable output pin',
	'nRST:External reset input: active LOW, with an internal pull-up. Set this pin low reset chip to initial state',
	'nWR:EBI write enable output pin',
	'nWRH:EBI high byte write enable output pin',
	'nWRL:EBI low byte write enable output pin',

	'PWM0:PWM0 output/Capture input',
	'PWM1:PWM1 output/Capture input',
	'PWM2:PWM0 output',
	'PWM2:PWM2 output/Capture input',
	'PWM3:PWM3 output',
	'PWM3:PWM3 output/Capture input',
	'PWM4:PWM4 output/Capture input',
	'PWM5:PWM5 output/Capture input',
	'PWM6:PWM6 output/Capture input',
	'PWM7:PWM7 output/Capture input',

	'RTS0:Request to Send output pin for UART0',
	'RTS1:Request to Send output pin for UART1',

	'RXD:Data receiver input pin for UART0',
	'RXD1:Data receiver input pin for UART1',

	'SCL0:I2C0 clock I/O pin',
	'SCL1:I2C1 clock I/O pin',

	'SDA0:I2C0 data input/output pin',
	'SDA1:I2C1 data input/output pin',

	'SPICLK0:SPI0 serial clock pin',
	'SPICLK1:SPI1 serial clock pin',
	'SPISS0:SPI0 slave select pin',
	'SPISS1:SPI1 slave select pin',

	'STADC:ADC external trigger input',

	'T0:Timer0 external event counter input pin',
	'T0EX:Timer0 external capture/reset trigger input pin',
	'T1:Timer1 external event counter input pin',
	'T1EX:Timer1 external capture/reset trigger input pin',
	'T2:Timer2 external event counter input pin',
	'T2EX:Timer2 external capture/reset trigger input pin',
	'T3:Timer3 external event counter input pin',
	'T3EX:Timer3 external capture/reset trigger input pin',
	'TIEX:Timer1 external capture/reset trigger input pin',
	'TXD:Data transmitter output pin for UART0',
	'TXD1:Data transmitter output pin for UART1',

	'VDD:Power supply for I/O ports and LDO source for internal PLL and digital circuit',
	'VSS:Ground pin for digital circuit',

	'XTAL1:External 4~24 MHz (high speed) crystal input pin',
	'XTAL2:External 4~24 MHz (high speed) crystal output pin'
];

NUTOOL_PIN.g_cfg_regDescriptions = {};
NUTOOL_PIN.g_cfg_regDescriptions.P0_MFP = '0x50000030';
NUTOOL_PIN.g_cfg_regDescriptions.P1_MFP = '0x50000034';
NUTOOL_PIN.g_cfg_regDescriptions.P2_MFP = '0x50000038';
NUTOOL_PIN.g_cfg_regDescriptions.P3_MFP = '0x5000003C';
NUTOOL_PIN.g_cfg_regDescriptions.P4_MFP = '0x50000040';
NUTOOL_PIN.g_cfg_regDescriptions.P5_MFP = '0x50000044';

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
	{ f: ['P1.3', 'P1_MFP[3]:0', 'P1_MFP[11]:1'] },
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
	{ f: ['P3.6', 'P3_MFP[6]:0', 'P3_MFP[14]:1'] },
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
	{ f: ['P5.3', 'P5_MFP[3]:0', 'P5_MFP[11]:1'] },
	{ f: ['P5.4', 'P5_MFP[4]:0', 'P5_MFP[12]:1'] },
	{ f: ['P5.5', 'P5_MFP[5]:0', 'P5_MFP[13]:1'] }
];

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
	default: // 'TSSOP20'
		NUTOOL_PIN.g_packageNumberIndex = "TSSOP20";
		break;
	}
	partNumber_package = null;
	partNumber = null;
};
