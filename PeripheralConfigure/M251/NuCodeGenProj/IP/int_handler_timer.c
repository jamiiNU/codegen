
#if (NUCODEGEN_TIMER0_INT || NUCODEGEN_TIMER0_CAP_INT || NUCODEGEN_TPWM0_PERIOD_INT || NUCODEGEN_TPWM0_CMP_UP_INT)
void TMR0_IRQHandler(void)
{
#if NUCODEGEN_TIMER0_CAP_INT
        if (TIMER_GetCaptureIntFlag(TIMER0))
        {       /* Clear Timer0 capture trigger interrupt flag */
                TIMER_ClearCaptureIntFlag(TIMER0);
        }
#endif
#if NUCODEGEN_TIMER0_INT
        if (TIMER_GetIntFlag(TIMER0))
        {       /* Clear Timer0 time-out interrupt flag */
                TIMER_ClearIntFlag(TIMER0);
        }
#endif
#if NUCODEGEN_TIMER0_WAKEUP
        if (TIMER_GetWakeupFlag(TIMER0))
        {       /* Clear Timer0 wake-up flag */
                TIMER_ClearWakeupFlag(TIMER0);
        }
#endif
#if NUCODEGEN_TPWM0_PERIOD_INT
        if (TPWM_GET_PERIOD_INT_FLAG(TIMER0))
        {       /* Clear TPWM0 period interrupt flag */
                TPWM_CLEAR_PERIOD_INT_FLAG(TIMER0);
        }
#endif
#if NUCODEGEN_TPWM0_CMP_UP_INT
        if (TPWM_GET_CMP_UP_INT_FLAG(TIMER0))
        {       /* Clear TPWM0 compare up interrupt flag */
                TPWM_CLEAR_CMP_UP_INT_FLAG(TIMER0);
        }
#endif
#if NUCODEGEN_TPWM0_WAKEUP
        if (TPWM_GetWakeupFlag(TIMER0))
        {       /* Clear TPWM0 wake-up flag */
                TPWM_ClearWakeupFlag(TIMER0);
        }
#endif
}
#endif //NUCODEGEN_TIMER0_INT || NUCODEGEN_TIMER0_CAP_INT || NUCODEGEN_TPWM0_PERIOD_INT || NUCODEGEN_TPWM0_CMP_UP_INT

#if (NUCODEGEN_TIMER1_INT || NUCODEGEN_TIMER1_CAP_INT || NUCODEGEN_TPWM1_PERIOD_INT || NUCODEGEN_TPWM1_CMP_UP_INT)
void TMR1_IRQHandler(void)
{
#if NUCODEGEN_TIMER1_CAP_INT
        if (TIMER_GetCaptureIntFlag(TIMER1))
        {       /* Clear TIMER1 capture trigger interrupt flag */
                TIMER_ClearCaptureIntFlag(TIMER1);
        }
#endif
#if NUCODEGEN_TIMER1_INT
        if (TIMER_GetIntFlag(TIMER1))
        {       /* Clear TIMER1 time-out interrupt flag */
                TIMER_ClearIntFlag(TIMER1);
        }
#endif
#if NUCODEGEN_TIMER1_WAKEUP
        if (TIMER_GetWakeupFlag(TIMER1))
        {       /* Clear TIMER1 wake-up flag */
                TIMER_ClearWakeupFlag(TIMER1);
        }
#endif
#if NUCODEGEN_TPWM1_PERIOD_INT
        if (TPWM_GET_PERIOD_INT_FLAG(TIMER1))
        {       /* Clear TPWM1 period interrupt flag */
                TPWM_CLEAR_PERIOD_INT_FLAG(TIMER1);
        }
#endif
#if NUCODEGEN_TPWM1_CMP_UP_INT
        if (TPWM_GET_CMP_UP_INT_FLAG(TIMER1))
        {       /* Clear TPWM1 compare up interrupt flag */
                TPWM_CLEAR_CMP_UP_INT_FLAG(TIMER1);
        }
#endif
#if NUCODEGEN_TPWM1_WAKEUP
        if (TPWM_GetWakeupFlag(TIMER1))
        {       /* Clear TPWM1 wake-up flag */
                TPWM_ClearWakeupFlag(TIMER1);
        }
#endif
}
#endif //NUCODEGEN_TIMER1_INT || NUCODEGEN_TIMER1_CAP_INT || NUCODEGEN_TPWM1_PERIOD_INT || NUCODEGEN_TPWM1_CMP_UP_INT

#if (NUCODEGEN_TIMER2_INT || NUCODEGEN_TIMER2_CAP_INT || NUCODEGEN_TPWM2_PERIOD_INT || NUCODEGEN_TPWM2_CMP_UP_INT)
void TMR2_IRQHandler(void)
{
#if NUCODEGEN_TIMER2_CAP_INT
        if (TIMER_GetCaptureIntFlag(TIMER2))
        {       /* Clear TIMER2 capture trigger interrupt flag */
                TIMER_ClearCaptureIntFlag(TIMER2);
        }
#endif
#if NUCODEGEN_TIMER2_INT
        if (TIMER_GetIntFlag(TIMER2))
        {       /* Clear TIMER2 time-out interrupt flag */
                TIMER_ClearIntFlag(TIMER2);
        }
#endif
#if NUCODEGEN_TIMER2_WAKEUP
        if (TIMER_GetWakeupFlag(TIMER2))
        {       /* Clear TIMER2 wake-up flag */
                TIMER_ClearWakeupFlag(TIMER2);
        }
#endif
#if NUCODEGEN_TPWM2_PERIOD_INT
        if (TPWM_GET_PERIOD_INT_FLAG(TIMER2))
        {       /* Clear TPWM2 period interrupt flag */
                TPWM_CLEAR_PERIOD_INT_FLAG(TIMER2);
        }
#endif
#if NUCODEGEN_TPWM2_CMP_UP_INT
        if (TPWM_GET_CMP_UP_INT_FLAG(TIMER2))
        {       /* Clear TPWM2 compare up interrupt flag */
                TPWM_CLEAR_CMP_UP_INT_FLAG(TIMER2);
        }
#endif
#if NUCODEGEN_TPWM2_WAKEUP
        if (TPWM_GetWakeupFlag(TIMER2))
        {       /* Clear TPWM2 wake-up flag */
                TPWM_ClearWakeupFlag(TIMER2);
        }
#endif
}
#endif //NUCODEGEN_TIMER2_INT || NUCODEGEN_TIMER2_CAP_INT || NUCODEGEN_TPWM2_PERIOD_INT || NUCODEGEN_TPWM2_CMP_UP_INT

#if (NUCODEGEN_TIMER3_INT || NUCODEGEN_TIMER3_CAP_INT || NUCODEGEN_TPWM3_PERIOD_INT || NUCODEGEN_TPWM3_CMP_UP_INT)
void TMR3_IRQHandler(void)
{
#if NUCODEGEN_TIMER3_CAP_INT
        if (TIMER_GetCaptureIntFlag(TIMER3))
        {       /* Clear TIMER3 capture trigger interrupt flag */
                TIMER_ClearCaptureIntFlag(TIMER3);
        }
#endif
#if NUCODEGEN_TIMER3_INT
        if (TIMER_GetIntFlag(TIMER3))
        {       /* Clear TIMER3 time-out interrupt flag */
                TIMER_ClearIntFlag(TIMER3);
        }
#endif
#if NUCODEGEN_TIMER3_WAKEUP
        if (TIMER_GetWakeupFlag(TIMER3))
        {       /* Clear TIMER3 wake-up flag */
                TIMER_ClearWakeupFlag(TIMER3);
        }
#endif
#if NUCODEGEN_TPWM3_PERIOD_INT
        if (TPWM_GET_PERIOD_INT_FLAG(TIMER3))
        {       /* Clear TPWM3 period interrupt flag */
                TPWM_CLEAR_PERIOD_INT_FLAG(TIMER3);
        }
#endif
#if NUCODEGEN_TPWM3_CMP_UP_INT
        if (TPWM_GET_CMP_UP_INT_FLAG(TIMER3))
        {       /* Clear TPWM3 compare up interrupt flag */
                TPWM_CLEAR_CMP_UP_INT_FLAG(TIMER3);
        }
#endif
#if NUCODEGEN_TPWM3_WAKEUP
        if (TPWM_GetWakeupFlag(TIMER3))
        {       /* Clear TPWM3 wake-up flag */
                TPWM_ClearWakeupFlag(TIMER3);
        }
#endif
}
#endif //NUCODEGEN_TIMER3_INT || NUCODEGEN_TIMER3_CAP_INT || NUCODEGEN_TPWM3_PERIOD_INT || NUCODEGEN_TPWM3_CMP_UP_INT
