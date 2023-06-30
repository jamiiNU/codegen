
#if ((NUCODEGEN_WDT) || (NUCODEGEN_WWDT))
void WDT_IRQHandler(void)
{
#if (NUCODEGEN_WDT_INT_ENABLE)
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
#endif /* NUCODEGEN_WDT_INT_ENABLE*/

#if (NUCODEGEN_WWDT_INT_ENABLE)
    /* Get WWDT interrupt flag */
    if (WWDT_GET_INT_FLAG())
    {
        /* Clear WWDT interrupt flag */
        WWDT_CLEAR_INT_FLAG();
    }

    /* To prevent system from reset by WWDT, it is necessary to reload WWDT counter
       by software before WWDT counter reaches zero. */
    WWDT_RELOAD_COUNTER();
#endif /* NUCODEGEN_WWDT_INT_ENABLE */
}
#endif /* NUCODEGEN_WDT | NUCODEGEN_WWDT */