
#if NUCODEGEN_TIMER0
void TIMER0_Init()
{
        TIMER_Open(TIMER0, TIMER0_MODE, TIMER0_FREQ);

#if (TIMER0_MODE == TIMER_TOGGLE_MODE)
        TIMER_SELECT_TOUT_PIN(TIMER0, NUCODEGEN_TIMER0_TOUT_PIN);
#endif

#if NUCODEGEN_TIMER0_VALUE
        // Set value will change frequency
        TIMER_SET_PRESCALE_VALUE(TIMER0, TIMER0_PRESCALE_VALUE);
        TIMER_SET_CMP_VALUE(TIMER0, TIMER0_CMP_VALUE);
#endif

#if NUCODEGEN_TIMER0_EVENT_CNT
        TIMER_EnableEventCounter(TIMER0, NUCODEGEN_TIMER0_COUNTER_PHASE);
        #if NUCODEGEN_TIMER0_EVENT_CNTDB
        TIMER_EnableEventCounterDebounce(TIMER0);
        #endif
#endif

#if NUCODEGEN_TIMER0_CAP
        // Set capture source
        TIMER_CaptureSelect(TIMER0, NUCODEGEN_TIMER0_CAP_SRC);

        // Configure Timer capture mode, capture edge
        TIMER_EnableCapture(TIMER0, NUCODEGEN_TIMER0_CAP_MODE, NUCODEGEN_TIMER0_CAP_EDGE);

        #if NUCODEGEN_TIMER0_CAPDB
        TIMER_EnableCaptureDebounce(TIMER0);
        #endif

        #if NUCODEGEN_TIMER0_CAP_INT
        // Enable timer capture interrupt
        TIMER_EnableCaptureInt(TIMER0);
        #endif
#endif

#if NUCODEGEN_TIMER0_WAKEUP
        TIMER_EnableWakeup(TIMER0);
#endif

#if NUCODEGEN_TIMER0_INT
        // Enable timer time-out interrupt
        TIMER_EnableInt(TIMER0);
#endif

#if NUCODEGEN_TIMER0_TRG
        TIMER_SetTriggerSource(TIMER0, NUCODEGEN_TIMER0_TRG_SRC);
        TIMER_SetTriggerTarget(TIMER0, NUCODEGEN_TIMER0_TRG_TARGET);
#endif

#if (NUCODEGEN_TIMER0_INT || NUCODEGEN_TIMER0_CAP_INT)
        NVIC_EnableIRQ(TMR0_IRQn);
#endif
}
#endif //NUCODEGEN_TIMER0

#if NUCODEGEN_TIMER1
void TIMER1_Init()
{
        TIMER_Open(TIMER1, TIMER1_MODE, TIMER1_FREQ);

#if (TIMER1_MODE == TIMER_TOGGLE_MODE)
        TIMER_SELECT_TOUT_PIN(TIMER1, NUCODEGEN_TIMER1_TOUT_PIN);
#endif

#if NUCODEGEN_TIMER1_VALUE
        // Set value will change frequency
        TIMER_SET_PRESCALE_VALUE(TIMER1, TIMER1_PRESCALE_VALUE);
        TIMER_SET_CMP_VALUE(TIMER1, TIMER1_CMP_VALUE);
#endif

#if NUCODEGEN_TIMER1_EVENT_CNT
        TIMER_EnableEventCounter(TIMER1, NUCODEGEN_TIMER1_COUNTER_PHASE);
        #if NUCODEGEN_TIMER1_EVENT_CNTDB
        TIMER_EnableEventCounterDebounce(TIMER1);
        #endif
#endif

#if NUCODEGEN_TIMER1_CAP
        // Set capture source
        TIMER_CaptureSelect(TIMER1, NUCODEGEN_TIMER1_CAP_SRC);

        // Configure Timer capture mode, capture edge
        TIMER_EnableCapture(TIMER1, NUCODEGEN_TIMER1_CAP_MODE, NUCODEGEN_TIMER1_CAP_EDGE);

        #if NUCODEGEN_TIMER1_CAPDB
        TIMER_EnableCaptureDebounce(TIMER1);
        #endif

        #if NUCODEGEN_TIMER1_CAP_INT
        // Enable timer capture interrupt
        TIMER_EnableCaptureInt(TIMER1);
        #endif
#endif

#if NUCODEGEN_TIMER1_WAKEUP
        TIMER_EnableWakeup(TIMER1);
#endif

#if NUCODEGEN_TIMER1_INT
        // Enable timer time-out interrupt
        TIMER_EnableInt(TIMER1);
#endif

#if NUCODEGEN_TIMER1_TRG
        TIMER_SetTriggerSource(TIMER1, NUCODEGEN_TIMER1_TRG_SRC);
        TIMER_SetTriggerTarget(TIMER1, NUCODEGEN_TIMER1_TRG_TARGET);
#endif

#if (NUCODEGEN_TIMER1_INT || NUCODEGEN_TIMER1_CAP_INT)
        NVIC_EnableIRQ(TMR1_IRQn);
#endif
}
#endif //NUCODEGEN_TIMER1

#if NUCODEGEN_TIMER2
void TIMER2_Init()
{
        TIMER_Open(TIMER2, TIMER2_MODE, TIMER2_FREQ);

#if (TIMER2_MODE == TIMER_TOGGLE_MODE)
        TIMER_SELECT_TOUT_PIN(TIMER2, NUCODEGEN_TIMER2_TOUT_PIN);
#endif

#if NUCODEGEN_TIMER2_VALUE
        // Set value will change frequency
        TIMER_SET_PRESCALE_VALUE(TIMER2, TIMER2_PRESCALE_VALUE);
        TIMER_SET_CMP_VALUE(TIMER2, TIMER2_CMP_VALUE);
#endif

#if NUCODEGEN_TIMER2_EVENT_CNT
        TIMER_EnableEventCounter(TIMER2, NUCODEGEN_TIMER2_COUNTER_PHASE);
        #if NUCODEGEN_TIMER2_EVENT_CNTDB
        TIMER_EnableEventCounterDebounce(TIMER2);
        #endif
#endif

#if NUCODEGEN_TIMER2_CAP
        // Set capture source
        TIMER_CaptureSelect(TIMER2, NUCODEGEN_TIMER2_CAP_SRC);

        // Configure Timer capture mode, capture edge
        TIMER_EnableCapture(TIMER2, NUCODEGEN_TIMER2_CAP_MODE, NUCODEGEN_TIMER2_CAP_EDGE);

        #if NUCODEGEN_TIMER2_CAPDB
        TIMER_EnableCaptureDebounce(TIMER2);
        #endif

        #if NUCODEGEN_TIMER2_CAP_INT
        // Enable timer capture interrupt
        TIMER_EnableCaptureInt(TIMER2);
        #endif
#endif

#if NUCODEGEN_TIMER2_WAKEUP
        TIMER_EnableWakeup(TIMER2);
#endif

#if NUCODEGEN_TIMER2_INT
        // Enable timer time-out interrupt
        TIMER_EnableInt(TIMER2);
#endif

#if NUCODEGEN_TIMER2_TRG
        TIMER_SetTriggerSource(TIMER2, NUCODEGEN_TIMER2_TRG_SRC);
        TIMER_SetTriggerTarget(TIMER2, NUCODEGEN_TIMER2_TRG_TARGET);
#endif

#if (NUCODEGEN_TIMER2_INT || NUCODEGEN_TIMER2_CAP_INT)
        NVIC_EnableIRQ(TMR2_IRQn);
#endif
}
#endif //NUCODEGEN_TIMER2

#if NUCODEGEN_TIMER3
void TIMER3_Init()
{
        TIMER_Open(TIMER3, TIMER3_MODE, TIMER3_FREQ);

#if (TIMER3_MODE == TIMER_TOGGLE_MODE)
        TIMER_SELECT_TOUT_PIN(TIMER3, NUCODEGEN_TIMER3_TOUT_PIN);
#endif

#if NUCODEGEN_TIMER3_VALUE
        // Set value will change frequency
        TIMER_SET_PRESCALE_VALUE(TIMER3, TIMER3_PRESCALE_VALUE);
        TIMER_SET_CMP_VALUE(TIMER3, TIMER3_CMP_VALUE);
#endif

#if NUCODEGEN_TIMER3_EVENT_CNT
        TIMER_EnableEventCounter(TIMER3, NUCODEGEN_TIMER3_COUNTER_PHASE);
        #if NUCODEGEN_TIMER3_EVENT_CNTDB
        TIMER_EnableEventCounterDebounce(TIMER3);
        #endif
#endif

#if NUCODEGEN_TIMER3_CAP
        // Set capture source
        TIMER_CaptureSelect(TIMER3, NUCODEGEN_TIMER3_CAP_SRC);

        // Configure Timer capture mode, capture edge
        TIMER_EnableCapture(TIMER3, NUCODEGEN_TIMER3_CAP_MODE, NUCODEGEN_TIMER3_CAP_EDGE);

        #if NUCODEGEN_TIMER3_CAPDB
        TIMER_EnableCaptureDebounce(TIMER3);
        #endif

        #if NUCODEGEN_TIMER3_CAP_INT
        // Enable timer capture interrupt
        TIMER_EnableCaptureInt(TIMER3);
        #endif
#endif

#if NUCODEGEN_TIMER3_WAKEUP
        TIMER_EnableWakeup(TIMER3);
#endif

#if NUCODEGEN_TIMER3_INT
        // Enable timer time-out interrupt
        TIMER_EnableInt(TIMER3);
#endif

#if NUCODEGEN_TIMER3_TRG
        TIMER_SetTriggerSource(TIMER3, NUCODEGEN_TIMER3_TRG_SRC);
        TIMER_SetTriggerTarget(TIMER3, NUCODEGEN_TIMER3_TRG_TARGET);
#endif

#if (NUCODEGEN_TIMER3_INT || NUCODEGEN_TIMER3_CAP_INT)
        NVIC_EnableIRQ(TMR3_IRQn);
#endif
}
#endif //NUCODEGEN_TIMER3
