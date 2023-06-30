/****************************************************************************
 * @file     periph_conf.h
 * @version  V0.00
 * @brief    NuMicro generated code file
 * Copyright (C) 2021 Nuvoton Technology Corp. All rights reserved.
*****************************************************************************/

/********************
MCU:NUC1262SE4AE(LQFP64)
********************/

#define NUCODEGEN_ADC 0
#define NUCODEGEN_TIMER0 1
#define NUCODEGEN_TIMER1 1
#define NUCODEGEN_TIMER2 1
#define NUCODEGEN_TIMER3 1
#define NUCODEGEN_UART0 1

//TIMER0
#define TIMER0_FUNC_TIMER	0

#define NUCODEGEN_TIMER0_FUNC		TIMER0_FUNC_TIMER

#if (NUCODEGEN_TIMER0_FUNC == TIMER0_FUNC_TIMER)
#define TIMER0_MODE

#define NUCODEGEN_TIMER0_TOUT_PIN

#define TIMER0_FREQ

#define NUCODEGEN_TIMER0_VALUE
#if NUCODEGEN_TIMER0_VALUE
	#define TIMER0_PRESCALE_VALUE
	#define TIMER0_CMP_VALUE
#endif //NUCODEGEN_TIMER0_VALUE

#define NUCODEGEN_TIMER0_WAKEUP

#define NUCODEGEN_TIMER0_INT

#define NUCODEGEN_TIMER0_EVENT_CNT
#if NUCODEGEN_TIMER0_EVENT_CNT
    #define NUCODEGEN_TIMER0_COUNTER_PHASE
	#define NUCODEGEN_TIMER0_EVENT_CNTDB
#endif //NUCODEGEN_TIMER0_EVENT_CNT

#define NUCODEGEN_TIMER0_CAP
#if NUCODEGEN_TIMER0_CAP
    #define NUCODEGEN_TIMER0_CAP_SRC
    #define NUCODEGEN_TIMER0_CAP_EDGE
    #define NUCODEGEN_TIMER0_CAP_MODE
    #define NUCODEGEN_TIMER0_CAPDB
    #define NUCODEGEN_TIMER0_CAP_INT
#endif //NUCODEGEN_TIMER0_CAP

#define NUCODEGEN_TIMER0_TRG
#if NUCODEGEN_TIMER0_TRG
	#define NUCODEGEN_TIMER0_TRG_SRC
	#define NUCODEGEN_TIMER0_TRG_TARGET
#endif //NUCODEGEN_TIMER0_TRG
#endif //(NUCODEGEN_TIMER0_FUNC == TIMER0_FUNC_TIMER)------------------------------------------------------------------------------------------------------


//TIMER1
#define TIMER1_FUNC_TIMER	0

#define NUCODEGEN_TIMER1_FUNC		TIMER1_FUNC_TIMER

#if (NUCODEGEN_TIMER1_FUNC == TIMER1_FUNC_TIMER)
#define TIMER1_MODE

#define NUCODEGEN_TIMER1_TOUT_PIN

#define TIMER1_FREQ

#define NUCODEGEN_TIMER1_VALUE
#if NUCODEGEN_TIMER1_VALUE
	#define TIMER1_PRESCALE_VALUE
	#define TIMER1_CMP_VALUE
#endif //NUCODEGEN_TIMER1_VALUE

#define NUCODEGEN_TIMER1_WAKEUP

#define NUCODEGEN_TIMER1_INT

#define NUCODEGEN_TIMER1_EVENT_CNT
#if NUCODEGEN_TIMER1_EVENT_CNT
    #define NUCODEGEN_TIMER1_COUNTER_PHASE
	#define NUCODEGEN_TIMER1_EVENT_CNTDB
#endif //NUCODEGEN_TIMER1_EVENT_CNT

#define NUCODEGEN_TIMER1_CAP
#if NUCODEGEN_TIMER1_CAP
    #define NUCODEGEN_TIMER1_CAP_SRC
    #define NUCODEGEN_TIMER1_CAP_EDGE
    #define NUCODEGEN_TIMER1_CAP_MODE
    #define NUCODEGEN_TIMER1_CAPDB
    #define NUCODEGEN_TIMER1_CAP_INT
#endif //NUCODEGEN_TIMER1_CAP

#define NUCODEGEN_TIMER1_TRG
#if NUCODEGEN_TIMER1_TRG
	#define NUCODEGEN_TIMER1_TRG_SRC
	#define NUCODEGEN_TIMER1_TRG_TARGET
#endif //NUCODEGEN_TIMER1_TRG
#endif //(NUCODEGEN_TIMER1_FUNC == TIMER1_FUNC_TIMER)------------------------------------------------------------------------------------------------------


//TIMER2
#define TIMER2_FUNC_TIMER	0

#define NUCODEGEN_TIMER2_FUNC		TIMER2_FUNC_TIMER

#if (NUCODEGEN_TIMER2_FUNC == TIMER2_FUNC_TIMER)
#define TIMER2_MODE

#define NUCODEGEN_TIMER2_TOUT_PIN

#define TIMER2_FREQ

#define NUCODEGEN_TIMER2_VALUE
#if NUCODEGEN_TIMER1_VALUE
	#define TIMER2_PRESCALE_VALUE
	#define TIMER2_CMP_VALUE
#endif //NUCODEGEN_TIMER2_VALUE

#define NUCODEGEN_TIMER2_WAKEUP

#define NUCODEGEN_TIMER2_INT

#define NUCODEGEN_TIMER2_EVENT_CNT
#if NUCODEGEN_TIMER2_EVENT_CNT
    #define NUCODEGEN_TIMER2_COUNTER_PHASE
	#define NUCODEGEN_TIMER2_EVENT_CNTDB
#endif //NUCODEGEN_TIMER2_EVENT_CNT

#define NUCODEGEN_TIMER2_CAP
#if NUCODEGEN_TIMER2_CAP
    #define NUCODEGEN_TIMER2_CAP_SRC
    #define NUCODEGEN_TIMER2_CAP_EDGE
    #define NUCODEGEN_TIMER2_CAP_MODE
    #define NUCODEGEN_TIMER2_CAPDB
    #define NUCODEGEN_TIMER2_CAP_INT
#endif //NUCODEGEN_TIMER2_CAP

#define NUCODEGEN_TIMER2_TRG
#if NUCODEGEN_TIMER2_TRG
	#define NUCODEGEN_TIMER2_TRG_SRC
	#define NUCODEGEN_TIMER2_TRG_TARGET
#endif //NUCODEGEN_TIMER2_TRG
#endif //(NUCODEGEN_TIMER2_FUNC == TIMER2_FUNC_TIMER)------------------------------------------------------------------------------------------------------


//TIMER3
#define TIMER3_FUNC_TIMER	0

#define NUCODEGEN_TIMER3_FUNC		TIMER3_FUNC_TIMER

#if (NUCODEGEN_TIMER3_FUNC == TIMER3_FUNC_TIMER)
#define TIMER3_MODE

#define NUCODEGEN_TIMER3_TOUT_PIN

#define TIMER3_FREQ

#define NUCODEGEN_TIMER3_VALUE
#if NUCODEGEN_TIMER3_VALUE
	#define TIMER3_PRESCALE_VALUE
	#define TIMER3_CMP_VALUE
#endif //NUCODEGEN_TIMER3_VALUE

#define NUCODEGEN_TIMER3_WAKEUP

#define NUCODEGEN_TIMER3_INT

#define NUCODEGEN_TIMER3_EVENT_CNT
#if NUCODEGEN_TIMER3_EVENT_CNT
    #define NUCODEGEN_TIMER3_COUNTER_PHASE
	#define NUCODEGEN_TIMER3_EVENT_CNTDB
#endif //NUCODEGEN_TIMER3_EVENT_CNT

#define NUCODEGEN_TIMER3_CAP
#if NUCODEGEN_TIMER3_CAP
    #define NUCODEGEN_TIMER3_CAP_SRC
    #define NUCODEGEN_TIMER3_CAP_EDGE
    #define NUCODEGEN_TIMER3_CAP_MODE
    #define NUCODEGEN_TIMER3_CAPDB
    #define NUCODEGEN_TIMER3_CAP_INT
#endif //NUCODEGEN_TIMER3_CAP

#define NUCODEGEN_TIMER3_TRG
#if NUCODEGEN_TIMER3_TRG
	#define NUCODEGEN_TIMER3_TRG_SRC
	#define NUCODEGEN_TIMER3_TRG_TARGET
#endif //NUCODEGEN_TIMER3_TRG
#endif //(NUCODEGEN_TIMER3_FUNC == TIMER3_FUNC_TIMER)------------------------------------------------------------------------------------------------------


//UART0
#define UART0_BAUD               115200
#define NUCODEGEN_UART0_FUNCSEL            UART_FUNCSEL_UART
#if (NUCODEGEN_UART0_FUNCSEL == UART_FUNCSEL_RS485)
    #define UART0_RS485_ALTCTL
    #define UART0_RS485_ADDRV
#elif (NUCODEGEN_UART0_FUNCSEL == UART_FUNCSEL_IrDA)
    #define UART0_IRDA_TX_ENABLE
#endif
#define UART0_TRGLEVEL           UART_FIFO_RFITL_1BYTE
#define UART0_RTSTRGLEVEL        UART_FIFO_RTSTRGLV_1BYTE

#define UART0_TOCNT              40
#define UART0_WORD_LEN           UART_WORD_LEN_8
#define UART0_PARITY             UART_PARITY_NONE
#define UART0_STOP_BIT           UART_STOP_BIT_1

#define NUCODEGEN_UART0_INT      0