/****************************************************************************
 * @file     periph_conf.h
 * @version  V0.00
 * @Date     2019/03/28-12:06:28
 * @brief    NuMicro generated code file
 *
 * Copyright (C) 2016-2019 Nuvoton Technology Corp. All rights reserved.
*****************************************************************************/

/********************
MCU:M252KG6AE(LQFP128)
********************/

#define NUCODEGEN_ADC 0
#define NUCODEGEN_TIMER0 1
#define NUCODEGEN_TIMER1 1
#define NUCODEGEN_TIMER2 1
#define NUCODEGEN_TIMER3 1
#define NUCODEGEN_UART0 1

//TIMER0
#define TIMER0_FUNC_TIMER	0
#define TIMER0_FUNC_PWM		1

#define NUCODEGEN_TIMER0_FUNC		TIMER0_FUNC_PWM

#if (NUCODEGEN_TIMER0_FUNC == TIMER0_FUNC_TIMER)
#define TIMER0_MODE					

#define TIMER0_TOUT_PIN				

#define TIMER0_FREQ					

#define NUCODEGEN_TIMER0_VALUE		

#if NUCODEGEN_TIMER0_VALUE
	#define TIMER0_PRESCALE_VALUE	
	#define TIMER0_CMP_VALUE		
#endif //NUCODEGEN_TIMER0_VALUE

#define NUCODEGEN_TIMER0_EVENT_CNT	

#if NUCODEGEN_TIMER0_EVENT_CNT
    #define TIMER0_COUNTER_PHASE	
	#define NUCODEGEN_TIMER0_EVENT_CNTDB	
#endif //NUCODEGEN_TIMER0_EVENT_CNT

#define NUCODEGEN_TIMER0_CAP				

#if NUCODEGEN_TIMER0_CAP
    #define TIMER0_CAP_SRC					

    #define TIMER0_INTERCAP_SRC												 

	#define TIMER0_CAP_EDGE					

	#define TIMER0_CAP_MODE					
	#define NUCODEGEN_TIMER0_CAPDB			
#endif //NUCODEGEN_TIMER0_CAP

#define NUCODEGEN_TIMER0_WAKEUP				

#define NUCODEGEN_TIMER0_INT				

#define NUCODEGEN_TIMER0_CAP_INT			

#define NUCODEGEN_TIMER0_TRG				

#if NUCODEGEN_TIMER0_TRG
	#define TIMER0_TRG_SRC					

	#define TIMER0_TRG_TARGET				
#endif //NUCODEGEN_TIMER0_TRG
#endif //(NUCODEGEN_TIMER0_FUNC == TIMER0_FUNC_TIMER)------------------------------------------------------------------------------------------------------

#if (NUCODEGEN_TIMER0_FUNC == TIMER0_FUNC_PWM)
#define TPWM0_CONFIG_FREQ_DUTY	0
#define TPWM0_CONFIG_VALUE		1

#define NUCODEGEN_TPWM0_CONFIG		TPWM0_CONFIG_FREQ_DUTY

#if (NUCODEGEN_TPWM0_CONFIG == TPWM0_CONFIG_FREQ_DUTY)
	#define TPWM0_FREQ					100000
	#define TPWM0_DUTY					20
#endif

#if (NUCODEGEN_TPWM0_CONFIG == TPWM0_CONFIG_VALUE)
	#define TPWM0_PRESCALE_VALUE	
	#define TPWM0_PERIOD_VALUE		
	#define TPWM0_CMP_VALUE			
#endif

#define NUCODEGEN_TPWM0_OUTPUT		1
#if NUCODEGEN_TPWM0_OUTPUT
    #define TPWM0_TOUT_PIN			TPWM_TOUT_PIN_FROM_TX
    
    #define NUCODEGEN_TPWM0_OUT_INV	1
#endif //NUCODEGEN_TPWM0_OUTPUT

#define NUCODEGEN_TPWM0_WAKEUP		0

#define NUCODEGEN_TPWM0_PERIOD_INT	1

#define NUCODEGEN_TPWM0_CMP_UP_INT	1

#define NUCODEGEN_TPWM0_TRG			0

#if NUCODEGEN_TPWM0_TRG
	#define TPWM0_TRG_SRC			
								 
	#define TPWM0_TRG_TARGET		
#endif //NUCODEGEN_TPWM0_TRG
#endif //(NUCODEGEN_TIMER0_FUNC == TIMER_FUNC_PWM)

//TIMER1
#define TIMER1_FUNC_TIMER	0
#define TIMER1_FUNC_PWM		1

#define NUCODEGEN_TIMER1_FUNC		TIMER1_FUNC_PWM

#if (NUCODEGEN_TIMER1_FUNC == TIMER1_FUNC_TIMER)
#define TIMER1_MODE					

#define TIMER1_TOUT_PIN				

#define TIMER1_FREQ					

#define NUCODEGEN_TIMER1_VALUE		

#if NUCODEGEN_TIMER1_VALUE
	#define TIMER1_PRESCALE_VALUE	
	#define TIMER1_CMP_VALUE		
#endif //NUCODEGEN_TIMER1_VALUE

#define NUCODEGEN_TIMER1_EVENT_CNT	

#if NUCODEGEN_TIMER1_EVENT_CNT
    #define TIMER1_COUNTER_PHASE	
	#define NUCODEGEN_TIMER1_EVENT_CNTDB	
#endif //NUCODEGEN_TIMER1_EVENT_CNT

#define NUCODEGEN_TIMER1_CAP				

#if NUCODEGEN_TIMER1_CAP
    #define TIMER1_CAP_SRC					

    #define TIMER1_INTERCAP_SRC												 

	#define TIMER1_CAP_EDGE					

	#define TIMER1_CAP_MODE					
	#define NUCODEGEN_TIMER1_CAPDB			
#endif //NUCODEGEN_TIMER1_CAP

#define NUCODEGEN_TIMER1_WAKEUP				

#define NUCODEGEN_TIMER1_INT				

#define NUCODEGEN_TIMER1_CAP_INT			

#define NUCODEGEN_TIMER1_TRG				

#if NUCODEGEN_TIMER1_TRG
	#define TIMER1_TRG_SRC					

	#define TIMER1_TRG_TARGET				
#endif //NUCODEGEN_TIMER1_TRG
#endif //(NUCODEGEN_TIMER1_FUNC == TIMER1_FUNC_TIMER)------------------------------------------------------------------------------------------------------

#if (NUCODEGEN_TIMER1_FUNC == TIMER1_FUNC_PWM)
#define TPWM1_CONFIG_FREQ_DUTY	0
#define TPWM1_CONFIG_VALUE		1

#define NUCODEGEN_TPWM1_CONFIG		TPWM1_CONFIG_FREQ_DUTY

#if (NUCODEGEN_TPWM1_CONFIG == TPWM1_CONFIG_FREQ_DUTY)
	#define TPWM1_FREQ					100000
	#define TPWM1_DUTY					20
#endif

#if (NUCODEGEN_TPWM1_CONFIG == TPWM1_CONFIG_VALUE)
	#define TPWM1_PRESCALE_VALUE	
	#define TPWM1_PERIOD_VALUE		
	#define TPWM1_CMP_VALUE			
#endif

#define NUCODEGEN_TPWM1_OUTPUT		1
#if NUCODEGEN_TPWM1_OUTPUT
    #define TPWM1_TOUT_PIN			TPWM_TOUT_PIN_FROM_TX
    
    #define NUCODEGEN_TPWM1_OUT_INV	0
#endif //NUCODEGEN_TPWM1_OUTPUT

#define NUCODEGEN_TPWM1_WAKEUP		0

#define NUCODEGEN_TPWM1_PERIOD_INT	1

#define NUCODEGEN_TPWM1_CMP_UP_INT	1

#define NUCODEGEN_TPWM1_TRG			0

#if NUCODEGEN_TPWM1_TRG
	#define TPWM1_TRG_SRC			
								 
	#define TPWM1_TRG_TARGET		
#endif //NUCODEGEN_TPWM1_TRG
#endif //(NUCODEGEN_TIMER1_FUNC == TIMER_FUNC_PWM)

//TIMER2
#define TIMER2_FUNC_TIMER	0
#define TIMER2_FUNC_PWM		1

#define NUCODEGEN_TIMER2_FUNC		TIMER2_FUNC_PWM

#if (NUCODEGEN_TIMER2_FUNC == TIMER2_FUNC_TIMER)
#define TIMER2_MODE					

#define TIMER2_TOUT_PIN				

#define TIMER2_FREQ					

#define NUCODEGEN_TIMER2_VALUE		

#if NUCODEGEN_TIMER2_VALUE
	#define TIMER2_PRESCALE_VALUE	
	#define TIMER2_CMP_VALUE		
#endif //NUCODEGEN_TIMER2_VALUE

#define NUCODEGEN_TIMER2_EVENT_CNT	

#if NUCODEGEN_TIMER2_EVENT_CNT
    #define TIMER2_COUNTER_PHASE	
	#define NUCODEGEN_TIMER2_EVENT_CNTDB	
#endif //NUCODEGEN_TIMER2_EVENT_CNT

#define NUCODEGEN_TIMER2_CAP				

#if NUCODEGEN_TIMER2_CAP
    #define TIMER2_CAP_SRC					

    #define TIMER2_INTERCAP_SRC												 

	#define TIMER2_CAP_EDGE					

	#define TIMER2_CAP_MODE					
	#define NUCODEGEN_TIMER2_CAPDB			
#endif //NUCODEGEN_TIMER2_CAP

#define NUCODEGEN_TIMER2_WAKEUP				

#define NUCODEGEN_TIMER2_INT				

#define NUCODEGEN_TIMER2_CAP_INT			

#define NUCODEGEN_TIMER2_TRG				

#if NUCODEGEN_TIMER2_TRG
	#define TIMER2_TRG_SRC					

	#define TIMER2_TRG_TARGET				
#endif //NUCODEGEN_TIMER2_TRG
#endif //(NUCODEGEN_TIMER2_FUNC == TIMER2_FUNC_TIMER)------------------------------------------------------------------------------------------------------

#if (NUCODEGEN_TIMER2_FUNC == TIMER2_FUNC_PWM)
#define TPWM2_CONFIG_FREQ_DUTY	0
#define TPWM2_CONFIG_VALUE		1

#define NUCODEGEN_TPWM2_CONFIG		TPWM2_CONFIG_FREQ_DUTY

#if (NUCODEGEN_TPWM2_CONFIG == TPWM2_CONFIG_FREQ_DUTY)
	#define TPWM2_FREQ					100000
	#define TPWM2_DUTY					20
#endif

#if (NUCODEGEN_TPWM2_CONFIG == TPWM2_CONFIG_VALUE)
	#define TPWM2_PRESCALE_VALUE	
	#define TPWM2_PERIOD_VALUE		
	#define TPWM2_CMP_VALUE			
#endif

#define NUCODEGEN_TPWM2_OUTPUT		1
#if NUCODEGEN_TPWM2_OUTPUT
    #define TPWM2_TOUT_PIN			TPWM_TOUT_PIN_FROM_TX
    
    #define NUCODEGEN_TPWM2_OUT_INV	1
#endif //NUCODEGEN_TPWM2_OUTPUT

#define NUCODEGEN_TPWM2_WAKEUP		0

#define NUCODEGEN_TPWM2_PERIOD_INT	1

#define NUCODEGEN_TPWM2_CMP_UP_INT	1

#define NUCODEGEN_TPWM2_TRG			0

#if NUCODEGEN_TPWM2_TRG
	#define TPWM2_TRG_SRC			
								 
	#define TPWM2_TRG_TARGET		
#endif //NUCODEGEN_TPWM2_TRG
#endif //(NUCODEGEN_TIMER2_FUNC == TIMER_FUNC_PWM)

//TIMER3
#define TIMER3_FUNC_TIMER	0
#define TIMER3_FUNC_PWM		1

#define NUCODEGEN_TIMER3_FUNC		TIMER3_FUNC_PWM

#if (NUCODEGEN_TIMER3_FUNC == TIMER3_FUNC_TIMER)
#define TIMER3_MODE					

#define TIMER3_TOUT_PIN				

#define TIMER3_FREQ					

#define NUCODEGEN_TIMER3_VALUE		

#if NUCODEGEN_TIMER3_VALUE
	#define TIMER3_PRESCALE_VALUE	
	#define TIMER3_CMP_VALUE		
#endif //NUCODEGEN_TIMER3_VALUE

#define NUCODEGEN_TIMER3_EVENT_CNT	

#if NUCODEGEN_TIMER3_EVENT_CNT
    #define TIMER3_COUNTER_PHASE	
	#define NUCODEGEN_TIMER3_EVENT_CNTDB	
#endif //NUCODEGEN_TIMER3_EVENT_CNT

#define NUCODEGEN_TIMER3_CAP				

#if NUCODEGEN_TIMER3_CAP
    #define TIMER3_CAP_SRC					

    #define TIMER3_INTERCAP_SRC												 

	#define TIMER3_CAP_EDGE					

	#define TIMER3_CAP_MODE					
	#define NUCODEGEN_TIMER3_CAPDB			
#endif //NUCODEGEN_TIMER3_CAP

#define NUCODEGEN_TIMER3_WAKEUP				

#define NUCODEGEN_TIMER3_INT				

#define NUCODEGEN_TIMER3_CAP_INT			

#define NUCODEGEN_TIMER3_TRG				

#if NUCODEGEN_TIMER3_TRG
	#define TIMER3_TRG_SRC					

	#define TIMER3_TRG_TARGET				
#endif //NUCODEGEN_TIMER3_TRG
#endif //(NUCODEGEN_TIMER3_FUNC == TIMER3_FUNC_TIMER)------------------------------------------------------------------------------------------------------

#if (NUCODEGEN_TIMER3_FUNC == TIMER3_FUNC_PWM)
#define TPWM3_CONFIG_FREQ_DUTY	0
#define TPWM3_CONFIG_VALUE		1

#define NUCODEGEN_TPWM3_CONFIG		TPWM3_CONFIG_FREQ_DUTY

#if (NUCODEGEN_TPWM3_CONFIG == TPWM3_CONFIG_FREQ_DUTY)
	#define TPWM3_FREQ					100000
	#define TPWM3_DUTY					20
#endif

#if (NUCODEGEN_TPWM3_CONFIG == TPWM3_CONFIG_VALUE)
	#define TPWM3_PRESCALE_VALUE	
	#define TPWM3_PERIOD_VALUE		
	#define TPWM3_CMP_VALUE			
#endif

#define NUCODEGEN_TPWM3_OUTPUT		1
#if NUCODEGEN_TPWM3_OUTPUT
    #define TPWM3_TOUT_PIN			TPWM_TOUT_PIN_FROM_TX
    
    #define NUCODEGEN_TPWM3_OUT_INV	0
#endif //NUCODEGEN_TPWM3_OUTPUT

#define NUCODEGEN_TPWM3_WAKEUP		0

#define NUCODEGEN_TPWM3_PERIOD_INT	1

#define NUCODEGEN_TPWM3_CMP_UP_INT	1

#define NUCODEGEN_TPWM3_TRG			0

#if NUCODEGEN_TPWM3_TRG
	#define TPWM3_TRG_SRC			
								 
	#define TPWM3_TRG_TARGET		
#endif //NUCODEGEN_TPWM3_TRG
#endif //(NUCODEGEN_TIMER3_FUNC == TIMER_FUNC_PWM)

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


/*** (C) COPYRIGHT 2016-2019 Nuvoton Technology Corp. ***/
