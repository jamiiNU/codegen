
#if (NUCODEGEN_TIMER0_INT || NUCODEGEN_TIMER0_CAP_INT)
void TMR0_IRQHandler(void)
{
#if NUCODEGEN_TIMER0_CAP_INT
    if (TIMER_GetCaptureIntFlag(TIMER0))
    {   /* Clear Timer0 capture trigger interrupt flag */
        TIMER_ClearCaptureIntFlag(TIMER0);
    }
#endif
#if NUCODEGEN_TIMER0_INT
    if (TIMER_GetIntFlag(TIMER0))
    {   /* Clear Timer0 time-out interrupt flag */
        TIMER_ClearIntFlag(TIMER0);
    }
#endif
#if NUCODEGEN_TIMER0_WAKEUP
    if (TIMER_GetWakeupFlag(TIMER0))
    {   /* Clear Timer0 wake-up flag */
        TIMER_ClearWakeupFlag(TIMER0);
    }
#endif
}
#endif /* NUCODEGEN_TIMER0_INT || NUCODEGEN_TIMER0_CAP_INT */


#if (NUCODEGEN_TIMER1_INT || NUCODEGEN_TIMER1_CAP_INT)
void TMR1_IRQHandler(void)
{
#if NUCODEGEN_TIMER1_CAP_INT
    if (TIMER_GetCaptureIntFlag(TIMER1))
    {   /* Clear TIMER1 capture trigger interrupt flag */
        TIMER_ClearCaptureIntFlag(TIMER1);
    }
#endif
#if NUCODEGEN_TIMER1_INT
    if (TIMER_GetIntFlag(TIMER1))
    {   /* Clear TIMER1 time-out interrupt flag */
        TIMER_ClearIntFlag(TIMER1);
    }
#endif
#if NUCODEGEN_TIMER1_WAKEUP
    if (TIMER_GetWakeupFlag(TIMER1))
    {   /* Clear TIMER1 wake-up flag */
        TIMER_ClearWakeupFlag(TIMER1);
    }
#endif
}
#endif /* NUCODEGEN_TIMER1_INT || NUCODEGEN_TIMER1_CAP_INT */


#if (NUCODEGEN_TIMER2_INT || NUCODEGEN_TIMER2_CAP_INT)
void TMR2_IRQHandler(void)
{
#if NUCODEGEN_TIMER2_CAP_INT
    if (TIMER_GetCaptureIntFlag(TIMER2))
    {   /* Clear TIMER2 capture trigger interrupt flag */
        TIMER_ClearCaptureIntFlag(TIMER2);
    }
#endif
#if NUCODEGEN_TIMER2_INT
    if (TIMER_GetIntFlag(TIMER2))
    {   /* Clear TIMER2 time-out interrupt flag */
        TIMER_ClearIntFlag(TIMER2);
    }
#endif
#if NUCODEGEN_TIMER2_WAKEUP
    if (TIMER_GetWakeupFlag(TIMER2))
    {   /* Clear TIMER2 wake-up flag */
        TIMER_ClearWakeupFlag(TIMER2);
    }
#endif
}
#endif /* NUCODEGEN_TIMER2_INT || NUCODEGEN_TIMER2_CAP_INT */


#if (NUCODEGEN_TIMER3_INT || NUCODEGEN_TIMER3_CAP_INT)
void TMR3_IRQHandler(void)
{
#if NUCODEGEN_TIMER3_CAP_INT
    if (TIMER_GetCaptureIntFlag(TIMER3))
    {   /* Clear TIMER3 capture trigger interrupt flag */
        TIMER_ClearCaptureIntFlag(TIMER3);
    }
#endif
#if NUCODEGEN_TIMER3_INT
    if (TIMER_GetIntFlag(TIMER3))
    {   /* Clear TIMER3 time-out interrupt flag */
        TIMER_ClearIntFlag(TIMER3);
    }
#endif
#if NUCODEGEN_TIMER3_WAKEUP
    if (TIMER_GetWakeupFlag(TIMER3))
    {   /* Clear TIMER3 wake-up flag */
        TIMER_ClearWakeupFlag(TIMER3);
    }
#endif
}
#endif /* NUCODEGEN_TIMER3_INT || NUCODEGEN_TIMER3_CAP_INT */
