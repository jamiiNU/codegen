// chip content
NUTOOL_PIN.g_cfg_chips = [
	{ name: "NM1530VE3AE", pkg: "LQFP100" },
	{ name: "NM1530VD3AE", pkg: "LQFP100" },

	{ name: "NM1520RD2AE", pkg: "LQFP64" },
	{ name: "NM1520RC2AE", pkg: "LQFP64" },

	{ name: "NM1520LD2AE", pkg: "LQFP48" },
	{ name: "NM1520LC2AE", pkg: "LQFP48" },
	{ name: "NM1510LC1AE", pkg: "LQFP48" },
	{ name: "NM1510LB1AE", pkg: "LQFP48" }
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
		'P9.0', 'P9.1', 'P9.2', 'VDD', 'VSS', 'P8.5', 'P9.3', '/RESET', 'XT1_Out', 'XT1_In',
		'ICE_DAT', 'ICE_CLK', 'P9.4', 'P9.5', 'P9.6'
	],
	"LQFP64": [
		'PVSS', 'P9.7', 'P3.5', 'P3.4', 'P1.7', 'LDO_CAP', 'VDD', 'VSS', 'PA.1', 'PA.0',
		'P5.6', 'P1.6', 'P1.5', 'P1.4', 'P1.3', 'P1.2',
		'P3.3', 'P1.1', 'P1.0', 'P3.0', 'P3.1', 'VSS', 'P5.0', 'P5.1', 'P2.7', 'P2.6',
		'P2.5', 'P2.4', 'P0.7', 'P0.6', 'P0.5', 'P0.4',
		'P0.3', 'P0.2', 'P0.1', 'P0.0', 'P6.6', 'P6.5', 'P6.4', 'P6.3', 'P6.2', 'P6.1',
		'P6.0', 'P8.2', 'P8.1', 'P8.0', 'AVSS', 'AVDD',
		'P7.6', 'P7.5', 'P7.4', 'P7.3', 'P7.2', 'P7.1', 'P7.0', 'P9.0', 'P9.1', 'P9.2',
		'VDD', '/RESET', 'XT1_Out', 'XT1_In', 'ICE_DAT', 'ICE_CLK'
	],
	"LQFP48": [
		'PVSS', 'P3.2', 'P1.7', 'LDO_CAP', 'VDD', 'VSS', 'PA.1', 'PA.0', 'P1.5', 'P1.4',
		'P1.3', 'P1.2',
		'P1.1', 'P1.0', 'P3.0', 'P3.1', 'P5.0', 'P5.1', 'P2.7', 'P2.6', 'P2.5', 'P2.4',
		'P0.4', 'P5.2',
		'P0.2', 'P0.0', 'P6.5', 'P6.4', 'P6.3', 'P6.2', 'P6.1', 'P8.2', 'P8.1', 'P8.0',
		'AVSS', 'AVDD',
		'P7.5', 'P7.3', 'P7.2', 'P7.1', 'P9.0', 'P9.1', 'P9.2', '/RESET', 'XT1_Out', 'XT1_In',
		'ICE_DAT', 'ICE_CLK'
	]
};

NUTOOL_PIN.g_cfg_OrCAD = {};

NUTOOL_PIN.g_cfg_gpios = [
	{ f: ['P0.0:0', 'PWM00:1', 'IC10:3'] },
	{ f: ['P0.1:0', 'PWM01:1', 'IC11:3'] },
	{ f: ['P0.2:0', 'PWM02:1', 'IC12:3'] },
	{ f: ['P0.3:0', 'PWM03:1', 'STADC:3'] },
	{ f: ['P0.4:0', 'PWM04:1'] },
	{ f: ['P0.5:0', 'PWM05:1'] },
	{ f: ['P0.6:0', 'BKP01:1'] },
	{ f: ['P0.7:0', 'STADC:1'] },

	{ f: ['P1.0:0', 'PWM10:1'] },
	{ f: ['P1.1:0', 'PWM11:1'] },
	{ f: ['P1.2:0', 'PWM12:1'] },
	{ f: ['P1.3:0', 'PWM13:1'] },
	{ f: ['P1.4:0', 'PWM14:1'] },
	{ f: ['P1.5:0', 'PWM15:1'] },
	{ f: ['P1.6:0', 'BKP00:1'] },
	{ f: ['P1.7:0', 'BKP10:1'] },

	{ f: ['P2.0:0', 'MOSI2:1', 'CPO2:2'] },
	{ f: ['P2.1:0', 'IC02:1'] },
	{ f: ['P2.2:0', 'IC01:1'] },
	{ f: ['P2.3:0', 'IC00:1'] },
	{ f: ['P2.4:0', 'QEIA0:1', 'CANRX:3'] },
	{ f: ['P2.5:0', 'QEIB0:1', 'CANTX:3'] },
	{ f: ['P2.6:0', 'IDX0:1', 'SS0:2', 'CTS1:3'] },
	{ f: ['P2.7:0', 'SPI_CLK0:2', 'RTS1:3'] },

	{ f: ['P3.0:0', 'RX0:1', 'CLKO:2'] },
	{ f: ['P3.1:0', 'TX0:1', 'CPO0:2'] },
	{ f: ['P3.2:0', 'INT0:1'] },
	{ f: ['P3.3:0', 'INT1:1'] },
	{ f: ['P3.4:0', 'T0:1', 'I2CSDA:2'] },
	{ f: ['P3.5:0', 'T1:1', 'I2CSCL:2'] },
	{ f: ['P3.6:0', 'CANRX:1'] },
	{ f: ['P3.7:0', 'CANTX:1'] },

	{ f: ['P4.0:0', 'IC10:1'] },
	{ f: ['P4.1:0', 'IC11:1'] },
	{ f: ['P4.2:0', 'IC12:1'] },
	{ f: ['P4.3:0'] },
	{ f: ['P4.4:0', 'QEIA1:1'] },
	{ f: ['P4.5:0', 'QEIB1:1'] },
	{ f: ['P4.6:0', 'T2:1', 'IDX1:2'] },
	{ f: ['P4.7:0', 'T3:1'] },

	{ f: ['P5.0:0', 'MOSI0:1', 'RTS0:2', 'I2CSCL:3'] },
	{ f: ['P5.1:0', 'MISO0:1', 'CTS0:2', 'I2CSDA:3'] },
	{ f: ['P5.2:0', 'MISO2:1', 'CPO1:2'] },
	{ f: ['P5.3:0', 'SPI_CLK2:1'] },
	{ f: ['P5.4:0', 'SS2:1'] },
	{ f: ['P5.5:0', 'CLKO:1'] },
	{ f: ['P5.6:0', 'PWM20:1'] },
	{ f: ['P5.7:0', 'PWM21:1'] },

	{ f: ['P6.0:0', 'AINA0:1'] },
	{ f: ['P6.1:0', 'AINA1:1'] },
	{ f: ['P6.2:0', 'AINA2:1'] },
	{ f: ['P6.3:0', 'AINA3:1'] },
	{ f: ['P6.4:0', 'AINA4:1', 'CPN1:1'] },
	{ f: ['P6.5:0', 'AINA5:1', 'CPP1:1'] },
	{ f: ['P6.6:0', 'AINA6:1'] },
	{ f: ['P6.7:0', 'AINA7:1'] },

	{ f: ['P7.0:0', 'AINB0:1'] },
	{ f: ['P7.1:0', 'AINB1:1'] },
	{ f: ['P7.2:0', 'AINB2:1'] },
	{ f: ['P7.3:0', 'AINB3:1'] },
	{ f: ['P7.4:0', 'AINB4:1', 'CPN2:1'] },
	{ f: ['P7.5:0', 'AINB5:1', 'CPP2:1'] },
	{ f: ['P7.6:0', 'AINB6:1'] },
	{ f: ['P7.7:0', 'AINB7:1'] },

	{ f: ['P8.0:0', 'OPP0:1'] },
	{ f: ['P8.1:0', 'OPN0:1'] },
	{ f: ['P8.2:0', 'OPO0:1'] },
	{ f: ['P8.3:0', 'CPN0:1'] },
	{ f: ['P8.4:0', 'CPP0:1'] },
	{ f: ['P8.5:0'] },
	{ f: ['P8.6:0'] },
	{ f: ['P8.7:0', 'CPO0:1'] },

	{ f: ['P9.0:0', 'OPO1:1'] },
	{ f: ['P9.1:0', 'OPN1:1'] },
	{ f: ['P9.2:0', 'OPP1:1'] },
	{ f: ['P9.3:0', 'BKP11:1'] },
	{ f: ['P9.4:0', 'SPI_CLK1:1'] },
	{ f: ['P9.5:0', 'MISO1:1'] },
	{ f: ['P9.6:0', 'MOSI1:1'] },
	{ f: ['P9.7:0', 'SS1:1'] },

	{ f: ['PA.0:0', 'TX1:1', 'I2CSDA:3'] },
	{ f: ['PA.1:0', 'RX1:1', 'I2CSCL:3'] }
];

NUTOOL_PIN.g_cfg_gpiosDefines = [];
NUTOOL_PIN.g_cfg_gpiosDescriptions = [];
NUTOOL_PIN.g_cfg_regDescriptions = {};
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
	"NM1520RD2AE(LQFP64)": {
		"P0.0": ["IC10"],
		"P0.1": ["IC11"],
		"P0.2": ["IC12"],
		"P0.3": ["STADC"],
		"P2.4": ["CANRX"],
		"P2.5": ["CANTX"],
		"P3.0": ["CLKO"],
		"PA.0": ["I2CSDA"],
		"PA.1": ["I2CSCL"]
	},
	"NM1520RC2AE(LQFP64)": function () {
		return this["NM1520RD2AE(LQFP64)"];
	},
	"NM1520LD2AE(LQFP48)": function () {
		return this["NM1520RD2AE(LQFP64)"];
	},
	"NM1520LC2AE(LQFP48)": function () {
		return this["NM1520RD2AE(LQFP64)"];
	},
	"NM1510LC1AE(LQFP48)": function () {
		return this["NM1520RD2AE(LQFP64)"];
	},
	"NM1510LB1AE(LQFP48)": function () {
		return this["NM1520RD2AE(LQFP64)"];
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
