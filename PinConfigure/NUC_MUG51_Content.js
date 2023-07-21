// chip content
NUTOOL_PIN.g_cfg_chips = [
    { name: "MUG51TB9AE", pkg: "QFN33" }
];

NUTOOL_PIN.g_cfg_pkgs = {
    "QFN33": [
        'P2.5', 'P2.4', 'P2.3', 'P2.2', 'P2.1', 'P2.0', 'P5.5', 'P5.4', 'P5.3', 'P5.2', 
        'P0.3', 'P0.2', 'P0.1', 'P0.0', 'NC', 'nRESET', 'P5.0', 'P5.1', 'P4.1', 'P4.0', 
        'NC', 'NC', 'P1.6', 'P1.7', 'VSS', 'LDO', 'VDD', 'P3.3', 'P3.2', 'P3.1', 
        'P3.0', 'NC', 'NC'
    ]
};

NUTOOL_PIN.g_cfg_gpios = [
    { f: ['P0.0:0', 'SPI0_MOSI:3', 'UART2_TXD:6', 'UART0_RXD:7', 'PWM0_CH5:13']},
    { f: ['P0.1:0', 'PINV:1', 'SPI0_MISO:3', 'UART2_RXD:6', 'UART0_TXD:7', 'PWM0_CH4:13', 'PBUF:14']},
    { f: ['P0.2:0', 'PINV:1', 'SPI0_CLK:3', 'UART1_RXD:8', 'I2C1_SDA:9', 'PWM0_CH3:13', 'PBUF:14']},
    { f: ['P0.3:0', 'PINV:1', 'PBUF:2', 'SPI0_SS:3', 'UART1_TXD:8', 'I2C1_SCL:9', 'STADC:11', 'PWM0_CH2:13', 'CLKO:14']},
    { f: ['P0.4:0']},
    { f: ['P0.5:0']},
    { f: ['P0.6:0']},
    { f: ['P0.7:0']},

    { f: ['P1.0:0']},
    { f: ['P1.1:0']},
    { f: ['P1.2:0']},
    { f: ['P1.3:0']},
    { f: ['P1.4:0']},
    { f: ['P1.5:0']},
    { f: ['P1.6:0', 'PINV:1', 'UART0_TXD:3', 'PBUF:12']},
    { f: ['P1.7:0', 'PINV:1', 'UART0_RXD:3', 'PBUF:12']},

    { f: ['P2.0:0', 'ACMP0_N1:1', 'UART2_RXD:7', 'I2C1_SDA:9', 'PWM0_CH5:11', 'PWM0_BRAKE:13']},
    { f: ['P2.1:0', 'ACMP0_P2:1', 'ACMP1_P2:1', 'PINV:3', 'PBUF:4', 'UART2_TXD:7', 'I2C1_SCL:9', 'PWM0_CH4:11', 'PWM0_BRAKE:13']},
    { f: ['P2.2:0', 'ACMP1_N0:1', 'PINV:3', 'I2C1_SDA:4', 'UART1_RXD:6', 'PBUF:7', 'PWM0_CH3:11']},
    { f: ['P2.3:0', 'ACMP0_P1:1', 'ACMP1_P1:1', 'PINV:3', 'I2C1_SCL:4', 'UART1_TXD:6', 'PBUF:7', 'PWM0_CH2:11', 'PWM0_BRAKE:13', 'T0:14', 'INT0:15']},
    { f: ['P2.4:0', 'ACMP0_N0:1', 'PINV:3', 'I2C0_SDA:6', 'PBUF:7', 'PWM0_CH1:11', 'UART2_RXD:13', 'T1:14', 'INT1:15']},
    { f: ['P2.5:0', 'ACMP0_P0:1', 'ACMP1_P0:1', 'PINV:3', 'I2C0_SCL:6', 'PBUF:7', 'PWM0_CH0:11', 'UART2_TXD:13', 'T0:14', 'INT0:15']},
    { f: ['P2.6:0']},
    { f: ['P2.7:0']},

    { f: ['P3.0:0', 'UART0_RXD:6', 'IC0:13']},
    { f: ['P3.1:0', 'ADC_CH6:1', 'ACMP0_P3:1', 'ACMP1_P3:1', 'PINV:3', 'UART0_TXD:6', 'PBUF:7', 'IC2:13']},
    { f: ['P3.2:0', 'ADC_CH7:1', 'ACMP1_N1:1', 'PINV:3', 'PBUF:7', 'IC1:13', 'CLKO:14']},
    { f: ['P3.3:0', 'PINV:3', 'PBUF:7', 'IC0:13', 'PWM0_BRAKE:15']},
    { f: ['P3.4:0']},
    { f: ['P3.5:0']},
    { f: ['P3.6:0']},
    { f: ['P3.7:0']},

    { f: ['P4.0:0', 'UART2_RXD:8', 'I2C0_SDA:9', 'ACMP1_O:14', 'INT1:15']},
    { f: ['P4.1:0', 'PINV:3', 'UART2_TXD:8', 'I2C0_SCL:9', 'PBUF:11', 'ACMP0_O:14']},
    { f: ['P4.2:0']},
    { f: ['P4.3:0']},
    { f: ['P4.4:0']},
    { f: ['P4.5:0']},
    { f: ['P4.6:0']},
    { f: ['P4.7:0']},

    { f: ['P5.0:0', 'UART1_TXD:2', 'I2C1_SCL:3', 'UART0_TXD:4', 'ICE_DAT:14']},
    { f: ['P5.1:0', 'PINV:1', 'UART1_RXD:2', 'I2C1_SDA:3', 'UART0_RXD:4', 'PBUF:7', 'ICE_CLK:14']},
    { f: ['P5.2:0', 'PINV:1', 'UART0_RXD:3', 'I2C0_SDA:4', 'PBUF:9']},
    { f: ['P5.3:0', 'PINV:1', 'UART0_TXD:3', 'I2C0_SCL:4', 'PBUF:9']},
    { f: ['P5.4:0', 'PINV:1', 'UART2_TXD:2', 'PWM0_CH1:7', 'PBUF:9']},
    { f: ['P5.5:0', 'PINV:1', 'UART2_RXD:2', 'PWM0_CH0:7', 'PBUF:9', 'STADC:11']},
    { f: ['P5.6:0']},
    { f: ['P5.7:0']}
];

NUTOOL_PIN.g_cfg_gpiosDefines = [
    { f: ['P0.0', 'SPI0_MOSI:MFP_P00_SPI0_MOSI@P0MF76543210', 'UART2_TXD:MFP_P00_UART2_TXD@P0MF76543210', 'UART0_RXD:MFP_P00_UART0_RXD@P0MF76543210', 'PWM0_CH5:MFP_P00_PWM0_CH5@P0MF76543210'] },
    { f: ['P0.1', 'PINV:MFP_P01_PINV@P0MF76543210', 'SPI0_MISO:MFP_P01_SPI0_MISO@P0MF76543210', 'UART2_RXD:MFP_P01_UART2_RXD@P0MF76543210', 'UART0_TXD:MFP_P01_UART0_TXD@P0MF76543210', 'PWM0_CH4:MFP_P01_PWM0_CH4@P0MF76543210', 'PBUF:MFP_P01_PBUF@P0MF76543210'] },
    { f: ['P0.2', 'PINV:MFP_P02_PINV@P0MF76543210', 'SPI0_CLK:MFP_P02_SPI0_CLK@P0MF76543210', 'UART1_RXD:MFP_P02_UART1_RXD@P0MF76543210', 'I2C1_SDA:MFP_P02_I2C1_SDA@P0MF76543210', 'PWM0_CH3:MFP_P02_PWM0_CH3@P0MF76543210', 'PBUF:MFP_P02_PBUF@P0MF76543210'] },
    { f: ['P0.3', 'PINV:MFP_P03_PINV@P0MF76543210', 'PBUF:MFP_P03_PBUF@P0MF76543210', 'SPI0_SS:MFP_P03_SPI0_SS@P0MF76543210', 'UART1_TXD:MFP_P03_UART1_TXD@P0MF76543210', 'I2C1_SCL:MFP_P03_I2C1_SCL@P0MF76543210', 'STADC:MFP_P03_STADC@P0MF76543210', 'PWM0_CH2:MFP_P03_PWM0_CH2@P0MF76543210', 'CLKO:MFP_P03_CLKO@P0MF76543210'] },

    { f: ['P1.6', 'PINV:MFP_P16_PINV@P1MF76543210', 'UART0_TXD:MFP_P16_UART0_TXD@P1MF76543210', 'PBUF:MFP_P16_PBUF@P1MF76543210'] },
    { f: ['P1.7', 'PINV:MFP_P17_PINV@P1MF76543210', 'UART0_RXD:MFP_P17_UART0_RXD@P1MF76543210', 'PBUF:MFP_P17_PBUF@P1MF76543210'] },

    { f: ['P2.0', 'ACMP0_N1:MFP_P20_ACMP0_N1@P2MF76543210', 'UART2_RXD:MFP_P20_UART2_RXD@P2MF76543210', 'I2C1_SDA:MFP_P20_I2C1_SDA@P2MF76543210', 'PWM0_CH5:MFP_P20_PWM0_CH5@P2MF76543210', 'PWM0_BRAKE:MFP_P20_PWM0_BRAKE@P2MF76543210'] },
    { f: ['P2.1', 'ACMP0_P2:MFP_P21_ACMP0_P2@P2MF76543210', 'ACMP1_P2:MFP_P21_ACMP1_P2@P2MF76543210', 'PINV:MFP_P21_PINV@P2MF76543210', 'PBUF:MFP_P21_PBUF@P2MF76543210', 'UART2_TXD:MFP_P21_UART2_TXD@P2MF76543210', 'I2C1_SCL:MFP_P21_I2C1_SCL@P2MF76543210', 'PWM0_CH4:MFP_P21_PWM0_CH4@P2MF76543210', 'PWM0_BRAKE:MFP_P21_PWM0_BRAKE@P2MF76543210'] },
    { f: ['P2.2', 'ACMP1_N0:MFP_P22_ACMP1_N0@P2MF76543210', 'PINV:MFP_P22_PINV@P2MF76543210', 'I2C1_SDA:MFP_P22_I2C1_SDA@P2MF76543210', 'UART1_RXD:MFP_P22_UART1_RXD@P2MF76543210', 'PBUF:MFP_P22_PBUF@P2MF76543210', 'PWM0_CH3:MFP_P22_PWM0_CH3@P2MF76543210'] },
    { f: ['P2.3', 'ACMP0_P1:MFP_P23_ACMP0_P1@P2MF76543210', 'ACMP1_P1:MFP_P23_ACMP1_P1@P2MF76543210', 'PINV:MFP_P23_PINV@P2MF76543210', 'I2C1_SCL:MFP_P23_I2C1_SCL@P2MF76543210', 'UART1_TXD:MFP_P23_UART1_TXD@P2MF76543210', 'PBUF:MFP_P23_PBUF@P2MF76543210', 'PWM0_CH2:MFP_P23_PWM0_CH2@P2MF76543210', 'PWM0_BRAKE:MFP_P23_PWM0_BRAKE@P2MF76543210', 'T0:MFP_P23_T0@P2MF76543210', 'INT0:MFP_P23_INT0@P2MF76543210'] },
    { f: ['P2.4', 'ACMP0_N0:MFP_P24_ACMP0_N0@P2MF76543210', 'PINV:MFP_P24_PINV@P2MF76543210', 'I2C0_SDA:MFP_P24_I2C0_SDA@P2MF76543210', 'PBUF:MFP_P24_PBUF@P2MF76543210', 'PWM0_CH1:MFP_P24_PWM0_CH1@P2MF76543210', 'UART2_RXD:MFP_P24_UART2_RXD@P2MF76543210', 'T1:MFP_P24_T1@P2MF76543210', 'INT1:MFP_P24_INT1@P2MF76543210'] },
    { f: ['P2.5', 'ACMP0_P0:MFP_P25_ACMP0_P0@P2MF76543210', 'ACMP1_P0:MFP_P25_ACMP1_P0@P2MF76543210', 'PINV:MFP_P25_PINV@P2MF76543210', 'I2C0_SCL:MFP_P25_I2C0_SCL@P2MF76543210', 'PBUF:MFP_P25_PBUF@P2MF76543210', 'PWM0_CH0:MFP_P25_PWM0_CH0@P2MF76543210', 'UART2_TXD:MFP_P25_UART2_TXD@P2MF76543210', 'T0:MFP_P25_T0@P2MF76543210', 'INT0:MFP_P25_INT0@P2MF76543210'] },

    { f: ['P3.0', 'UART0_RXD:MFP_P30_UART0_RXD@P3MF76543210', 'IC0:MFP_P30_IC0@P3MF76543210'] },
    { f: ['P3.1', 'ADC_CH6:MFP_P31_ADC_CH6@P3MF76543210', 'ACMP0_P3:MFP_P31_ACMP0_P3@P3MF76543210', 'ACMP1_P3:MFP_P31_ACMP1_P3@P3MF76543210', 'PINV:MFP_P31_PINV@P3MF76543210', 'UART0_TXD:MFP_P31_UART0_TXD@P3MF76543210', 'PBUF:MFP_P31_PBUF@P3MF76543210', 'IC2:MFP_P31_IC2@P3MF76543210'] },
    { f: ['P3.2', 'ADC_CH7:MFP_P32_ADC_CH7@P3MF76543210', 'ACMP1_N1:MFP_P32_ACMP1_N1@P3MF76543210', 'PINV:MFP_P32_PINV@P3MF76543210', 'PBUF:MFP_P32_PBUF@P3MF76543210', 'IC1:MFP_P32_IC1@P3MF76543210', 'CLKO:MFP_P32_CLKO@P3MF76543210'] },
    { f: ['P3.3', 'PINV:MFP_P33_PINV@P3MF76543210', 'PBUF:MFP_P33_PBUF@P3MF76543210', 'IC0:MFP_P33_IC0@P3MF76543210', 'PWM0_BRAKE:MFP_P33_PWM0_BRAKE@P3MF76543210'] },

    { f: ['P4.0', 'UART2_RXD:MFP_P40_UART2_RXD@P4MF76543210', 'I2C0_SDA:MFP_P40_I2C0_SDA@P4MF76543210', 'ACMP1_O:MFP_P40_ACMP1_O@P4MF76543210', 'INT1:MFP_P40_INT1@P4MF76543210'] },
    { f: ['P4.1', 'PINV:MFP_P41_PINV@P4MF76543210', 'UART2_TXD:MFP_P41_UART2_TXD@P4MF76543210', 'I2C0_SCL:MFP_P41_I2C0_SCL@P4MF76543210', 'PBUF:MFP_P41_PBUF@P4MF76543210', 'ACMP0_O:MFP_P41_ACMP0_O@P4MF76543210'] },

    { f: ['P5.0', 'UART1_TXD:MFP_P50_UART1_TXD@P5MF76543210', 'I2C1_SCL:MFP_P50_I2C1_SCL@P5MF76543210', 'UART0_TXD:MFP_P50_UART0_TXD@P5MF76543210', 'ICE_DAT:MFP_P50_ICE_DAT@P5MF76543210'] },
    { f: ['P5.1', 'PINV:MFP_P51_PINV@P5MF76543210', 'UART1_RXD:MFP_P51_UART1_RXD@P5MF76543210', 'I2C1_SDA:MFP_P51_I2C1_SDA@P5MF76543210', 'UART0_RXD:MFP_P51_UART0_RXD@P5MF76543210', 'PBUF:MFP_P51_PBUF@P5MF76543210', 'ICE_CLK:MFP_P51_ICE_CLK@P5MF76543210'] },
    { f: ['P5.2', 'PINV:MFP_P52_PINV@P5MF76543210', 'UART0_RXD:MFP_P52_UART0_RXD@P5MF76543210', 'I2C0_SDA:MFP_P52_I2C0_SDA@P5MF76543210', 'PBUF:MFP_P52_PBUF@P5MF76543210'] },
    { f: ['P5.3', 'PINV:MFP_P53_PINV@P5MF76543210', 'UART0_TXD:MFP_P53_UART0_TXD@P5MF76543210', 'I2C0_SCL:MFP_P53_I2C0_SCL@P5MF76543210', 'PBUF:MFP_P53_PBUF@P5MF76543210'] },
    { f: ['P5.4', 'PINV:MFP_P54_PINV@P5MF76543210', 'UART2_TXD:MFP_P54_UART2_TXD@P5MF76543210', 'PWM0_CH1:MFP_P54_PWM0_CH1@P5MF76543210', 'PBUF:MFP_P54_PBUF@P5MF76543210'] },
    { f: ['P5.5', 'PINV:MFP_P55_PINV@P5MF76543210', 'UART2_RXD:MFP_P55_UART2_RXD@P5MF76543210', 'PWM0_CH0:MFP_P55_PWM0_CH0@P5MF76543210', 'PBUF:MFP_P55_PBUF@P5MF76543210', 'STADC:MFP_P55_STADC@P5MF76543210'] },
];

NUTOOL_PIN.g_cfg_gpiosDescriptions = [
    'ACMP0_N0:Analog comparator 0 negative input 0 pin.',
    'ACMP0_N1:Analog comparator 0 negative input 1 pin.',
    'ACMP0_O:Analog comparator 0 output pin.',
    'ACMP0_P0:Analog comparator 0 positive input 0 pin.',
    'ACMP0_P1:Analog comparator 0 positive input 1 pin.',
    'ACMP0_P2:Analog comparator 0 positive input 2 pin.',
    'ACMP0_P3:Analog comparator 0 positive input 3 pin.',
    'ACMP1_N0:Analog comparator 1 negative input 0 pin.',
    'ACMP1_N1:Analog comparator 1 negative input 1 pin.',
    'ACMP1_O:Analog comparator 1 output pin.',
    'ACMP1_P0:Analog comparator 1 positive input 0 pin.',
    'ACMP1_P1:Analog comparator 1 positive input 1 pin.',
    'ACMP1_P2:Analog comparator 1 positive input 2 pin.',
    'ACMP1_P3:Analog comparator 1 positive input 3 pin.',
    'CLKO:Clock Out',
    'I2C0_SCL:I2C0 clock pin.',
    'I2C0_SDA:I2C0 data input/output pin.',
    'I2C1_SCL:I2C1 clock pin.',
    'I2C1_SDA:I2C1 data input/output pin.',
    'IC0:Input Capture channel 0',
    'IC1:Input Capture channel 1',
    'IC2:Input Capture channel 2',
    'ICE_CLK:Serial wired debugger clock pin.',
    'ICE_DAT:Serial wired debugger data pin.',
    'INT0:External interrupt 0 input pin.',
    'INT1:External interrupt 1 input pin.',
    'nRESET:External reset input: active LOW, with an internal pull-up. Set this pin low reset to initial state.',
    'Pin Name:Description',
    'PWM0_BRAKE:PWM0 Brake input pin.',
    'PWM0_CH0:PWM0 channel 0 output/capture input.',
    'PWM0_CH1:PWM0 channel 1 output/capture input.',
    'PWM0_CH2:PWM0 channel 2 output/capture input.',
    'PWM0_CH3:PWM0 channel 3 output/capture input.',
    'PWM0_CH4:PWM0 channel 4 output/capture input.',
    'PWM0_CH5:PWM0 channel 5 output/capture input.',
    'SPI0_CLK:SPI0 serial clock pin.',
    'SPI0_MISO:SPI0 MISO (Master In, Slave Out) pin.',
    'SPI0_MOSI:SPI0 MOSI (Master Out, Slave In) pin.',
    'SPI0_SS:SPI0 slave select pin.',
    'T0:External count input to Timer/Counter 0 or its toggle output.',
    'T1:External count input to Timer/Counter 1 or its toggle output.',
    'UART0_RXD:UART0 data receiver input pin.',
    'UART0_TXD:UART0 data transmitter output pin.',
    'UART1_RXD:UART1 data receiver input pin.',
    'UART1_TXD:UART1 data transmitter output pin.',
    'UART2_RXD:UART2 data receiver input pin.',
    'UART2_TXD:UART2 data transmitter output pin.',
    'PINV:GPIO Internal Inverter output enable',
    'PBUF:GPIO Intenral Buffer output enable'

];

NUTOOL_PIN.g_cfg_regDescriptions = {};
NUTOOL_PIN.g_cfg_regDescriptions.P0MF76543210 = 'This register is nonexistent';
NUTOOL_PIN.g_cfg_regDescriptions.P1MF76543210 = 'This register is nonexistent';
NUTOOL_PIN.g_cfg_regDescriptions.P2MF76543210 = 'This register is nonexistent';
NUTOOL_PIN.g_cfg_regDescriptions.P3MF76543210 = 'This register is nonexistent';
NUTOOL_PIN.g_cfg_regDescriptions.P4MF76543210 = 'This register is nonexistent';
NUTOOL_PIN.g_cfg_regDescriptions.P5MF76543210 = 'This register is nonexistent';
NUTOOL_PIN.g_cfg_regDescriptions.P6MF76543210 = 'This register is nonexistent';

NUTOOL_PIN.g_cfg_unusedGPIO = {
    'MUG51TB9AE(QFN33)': {
        'ALL': ['ADC', 'PWM1', 'PWM2', 'PWM3', 'SPI1', 'UART3', 'X32', 'XT1', 'LCD', 'TK']
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
