
#if (NUCODEGEN_WDT)
#if (NUCODEGEN_WDT_INT_ENABLE)
void WDT_IRQHandler(void)
{
    /* Get WDT Time-out interrupt flag */
    if (WDT_GET_TIMEOUT_INT_FLAG())
    {
        /* Clear WDT time-out interrupt flag */
        WDT_CLEAR_TIMEOUT_INT_FLAG();
    }

    /* Get WDT time-out wakeup  flag */
    if (WDT_GET_TIMEOUT_WAKEUP_FLAG())
    {
        /* Clear WDT time-out wakeup  flag */
        WDT_CLEAR_TIMEOUT_WAKEUP_FLAG();
    }

    /* To prevent system from reset by WDT, it is necessary to clear WDT counter
       by software before WDT counter reaches the reset delay time after time-out occurs. */
    WDT_RESET_COUNTER();
}
#endif /* NUCODEGEN_WDT_INT_ENABLE*/ 
#endif /* NUCODEGEN_WDT */
