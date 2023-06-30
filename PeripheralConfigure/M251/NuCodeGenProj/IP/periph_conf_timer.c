
#if NUCODEGEN_TIMER0
void TIMER0_Init()
{
#if (NUCODEGEN_TIMER0_FUNC == NUCODEGEN_TIMER0_FUNC_TIMER)
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
#endif //(NUCODEGEN_TIMER0_FUNC == TIMER0_FUNC_TIMER)

#if (NUCODEGEN_TIMER0_FUNC == NUCODEGEN_TIMER0_FUNC_PWM)
        /* Change Timer to PWM counter mode */
        TPWM_ENABLE_PWM_MODE(TIMER0);

#if (NUCODEGEN_TPWM0_CONFIG == NUCODEGEN_TPWM0_CONFIG_FREQ_DUTY)
        /* Set Timer PWM output frequency, duty% */
        TPWM_ConfigOutputFreqAndDuty(TIMER0, TPWM0_FREQ, TPWM0_DUTY);
#endif

#if (NUCODEGEN_TPWM0_CONFIG == NUCODEGEN_TPWM0_CONFIG_VALUE)
        // Set value will change frequency and duty
        TPWM_SET_PRESCALER(TIMER0, TPWM0_PRESCALE_VALUE);
        TPWM_SET_PERIOD(TIMER0, TPWM0_PERIOD_VALUE);
        TPWM_SET_CMPDAT(TIMER0, TPWM0_CMP_VALUE);
#endif

#if NUCODEGEN_TPWM0_OUTPUT
        /* Enable output of PWM_CH0 */
        TPWM_ENABLE_OUTPUT(TIMER0, TPWM_CH0);
        TPWM_SELECT_TOUT_PIN(TIMER0, NUCODEGEN_TPWM0_TOUT_PIN);
        #if NUCODEGEN_TPWM0_OUT_INV
        TPWM_SET_OUTPUT_INVERSE(TIMER0, TPWM_CH0);
        #endif
#endif

#if NUCODEGEN_TPWM0_WAKEUP
        TPWM_EnableWakeup(TIMER0);
#endif

#if NUCODEGEN_TPWM0_PERIOD_INT
        /* Enable period interrupt */
        TPWM_ENABLE_PERIOD_INT(TIMER0);
#endif

#if NUCODEGEN_TPWM0_CMP_UP_INT
        /* Enable compare up interrupt */
        TPWM_ENABLE_CMP_UP_INT(TIMER0);
#endif

#if NUCODEGEN_TPWM0_TRG
        TPWM_EnableTrigger(TIMER0, NUCODEGEN_TPWM0_TRG_TARGET, NUCODEGEN_TPWM0_TRG_SRC);
#endif

#if (NUCODEGEN_TPWM0_PERIOD_INT || NUCODEGEN_TPWM0_CMP_UP_INT)
        NVIC_EnableIRQ(TMR0_IRQn);
#endif
#endif //(NUCODEGEN_TIMER0_FUNC == TIMER0_FUNC_PWM)
}
#endif //NUCODEGEN_TIMER0

#if NUCODEGEN_TIMER1
void TIMER1_Init()
{
#if (NUCODEGEN_TIMER1_FUNC == NUCODEGEN_TIMER1_FUNC_TIMER)
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
#endif //(NUCODEGEN_TIMER1_FUNC == TIMER1_FUNC_TIMER)

#if (NUCODEGEN_TIMER1_FUNC == NUCODEGEN_TIMER1_FUNC_PWM)
        /* Change Timer to PWM counter mode */
        TPWM_ENABLE_PWM_MODE(TIMER1);

#if (NUCODEGEN_TPWM1_CONFIG == NUCODEGEN_TPWM1_CONFIG_FREQ_DUTY)
        /* Set Timer PWM output frequency, duty% */
        TPWM_ConfigOutputFreqAndDuty(TIMER1, TPWM1_FREQ, TPWM1_DUTY);
#endif

#if (NUCODEGEN_TPWM1_CONFIG == NUCODEGEN_TPWM1_CONFIG_VALUE)
        // Set value will change frequency and duty
        TPWM_SET_PRESCALER(TIMER1, TPWM1_PRESCALE_VALUE);
        TPWM_SET_PERIOD(TIMER1, TPWM1_PERIOD_VALUE);
        TPWM_SET_CMPDAT(TIMER1, TPWM1_CMP_VALUE);
#endif

#if NUCODEGEN_TPWM1_OUTPUT
        /* Enable output of PWM_CH0 */
        TPWM_ENABLE_OUTPUT(TIMER1, TPWM_CH0);
        TPWM_SELECT_TOUT_PIN(TIMER1, NUCODEGEN_TPWM1_TOUT_PIN);
        #if NUCODEGEN_TPWM1_OUT_INV
        TPWM_SET_OUTPUT_INVERSE(TIMER1, TPWM_CH0);
        #endif
#endif

#if NUCODEGEN_TPWM1_WAKEUP
        TPWM_EnableWakeup(TIMER1);
#endif

#if NUCODEGEN_TPWM1_PERIOD_INT
        /* Enable period interrupt */
        TPWM_ENABLE_PERIOD_INT(TIMER1);
#endif

#if NUCODEGEN_TPWM1_CMP_UP_INT
        /* Enable compare up interrupt */
        TPWM_ENABLE_CMP_UP_INT(TIMER1);
#endif

#if NUCODEGEN_TPWM1_TRG
        TPWM_EnableTrigger(TIMER1, NUCODEGEN_TPWM1_TRG_TARGET, NUCODEGEN_TPWM1_TRG_SRC);
#endif

#if (NUCODEGEN_TPWM1_PERIOD_INT || NUCODEGEN_TPWM1_CMP_UP_INT)
        NVIC_EnableIRQ(TMR1_IRQn);
#endif
#endif //(NUCODEGEN_TIMER1_FUNC == TIMER1_FUNC_PWM)
}
#endif //NUCODEGEN_TIMER1

#if NUCODEGEN_TIMER2
void TIMER2_Init()
{
#if (NUCODEGEN_TIMER2_FUNC == NUCODEGEN_TIMER2_FUNC_TIMER)
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
#endif //(NUCODEGEN_TIMER2_FUNC == TIMER2_FUNC_TIMER)

#if (NUCODEGEN_TIMER2_FUNC == NUCODEGEN_TIMER2_FUNC_PWM)
        /* Change Timer to PWM counter mode */
        TPWM_ENABLE_PWM_MODE(TIMER2);

#if (NUCODEGEN_TPWM2_CONFIG == NUCODEGEN_TPWM2_CONFIG_FREQ_DUTY)
        /* Set Timer PWM output frequency, duty% */
        TPWM_ConfigOutputFreqAndDuty(TIMER2, TPWM2_FREQ, TPWM2_DUTY);
#endif

#if (NUCODEGEN_TPWM2_CONFIG == NUCODEGEN_TPWM2_CONFIG_VALUE)
        // Set value will change frequency and duty
        TPWM_SET_PRESCALER(TIMER2, TPWM2_PRESCALE_VALUE);
        TPWM_SET_PERIOD(TIMER2, TPWM2_PERIOD_VALUE);
        TPWM_SET_CMPDAT(TIMER2, TPWM2_CMP_VALUE);
#endif

#if NUCODEGEN_TPWM2_OUTPUT
        /* Enable output of PWM_CH0 */
        TPWM_ENABLE_OUTPUT(TIMER2, TPWM_CH0);
        TPWM_SELECT_TOUT_PIN(TIMER2, NUCODEGEN_TPWM2_TOUT_PIN);
        #if NUCODEGEN_TPWM2_OUT_INV
        TPWM_SET_OUTPUT_INVERSE(TIMER2, TPWM_CH0);
        #endif
#endif

#if NUCODEGEN_TPWM2_WAKEUP
        TPWM_EnableWakeup(TIMER2);
#endif

#if NUCODEGEN_TPWM2_PERIOD_INT
        /* Enable period interrupt */
        TPWM_ENABLE_PERIOD_INT(TIMER2);
#endif

#if NUCODEGEN_TPWM2_CMP_UP_INT
        /* Enable compare up interrupt */
        TPWM_ENABLE_CMP_UP_INT(TIMER2);
#endif

#if NUCODEGEN_TPWM2_TRG
        TPWM_EnableTrigger(TIMER2, NUCODEGEN_TPWM2_TRG_TARGET, NUCODEGEN_TPWM2_TRG_SRC);
#endif

#if (NUCODEGEN_TPWM2_PERIOD_INT || NUCODEGEN_TPWM2_CMP_UP_INT)
        NVIC_EnableIRQ(TMR2_IRQn);
#endif
#endif //(NUCODEGEN_TIMER2_FUNC == TIMER2_FUNC_PWM)
}
#endif //NUCODEGEN_TIMER2

#if NUCODEGEN_TIMER3
void TIMER3_Init()
{
#if (NUCODEGEN_TIMER3_FUNC == NUCODEGEN_TIMER3_FUNC_TIMER)
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
#endif //(NUCODEGEN_TIMER3_FUNC == TIMER3_FUNC_TIMER)

#if (NUCODEGEN_TIMER3_FUNC == NUCODEGEN_TIMER3_FUNC_PWM)
        /* Change Timer to PWM counter mode */
        TPWM_ENABLE_PWM_MODE(TIMER3);

#if (NUCODEGEN_TPWM3_CONFIG == NUCODEGEN_TPWM3_CONFIG_FREQ_DUTY)
        /* Set Timer PWM output frequency, duty% */
        TPWM_ConfigOutputFreqAndDuty(TIMER3, TPWM3_FREQ, TPWM3_DUTY);
#endif

#if (NUCODEGEN_TPWM3_CONFIG == NUCODEGEN_TPWM3_CONFIG_VALUE)
        // Set value will change frequency and duty
        TPWM_SET_PRESCALER(TIMER3, TPWM3_PRESCALE_VALUE);
        TPWM_SET_PERIOD(TIMER3, TPWM3_PERIOD_VALUE);
        TPWM_SET_CMPDAT(TIMER3, TPWM3_CMP_VALUE);
#endif

#if NUCODEGEN_TPWM3_OUTPUT
        /* Enable output of PWM_CH0 */
        TPWM_ENABLE_OUTPUT(TIMER3, TPWM_CH0);
        TPWM_SELECT_TOUT_PIN(TIMER3, NUCODEGEN_TPWM3_TOUT_PIN);
        #if NUCODEGEN_TPWM3_OUT_INV
        TPWM_SET_OUTPUT_INVERSE(TIMER3, TPWM_CH0);
        #endif
#endif

#if NUCODEGEN_TPWM3_WAKEUP
        TPWM_EnableWakeup(TIMER3);
#endif

#if NUCODEGEN_TPWM3_PERIOD_INT
        /* Enable period interrupt */
        TPWM_ENABLE_PERIOD_INT(TIMER3);
#endif

#if NUCODEGEN_TPWM3_CMP_UP_INT
        /* Enable compare up interrupt */
        TPWM_ENABLE_CMP_UP_INT(TIMER3);
#endif

#if NUCODEGEN_TPWM3_TRG
        TPWM_EnableTrigger(TIMER3, NUCODEGEN_TPWM3_TRG_TARGET, NUCODEGEN_TPWM3_TRG_SRC);
#endif

#if (NUCODEGEN_TPWM3_PERIOD_INT || NUCODEGEN_TPWM3_CMP_UP_INT)
        NVIC_EnableIRQ(TMR3_IRQn);
#endif
#endif //(NUCODEGEN_TIMER3_FUNC == TIMER3_FUNC_PWM)
}
#endif //NUCODEGEN_TIMER3
