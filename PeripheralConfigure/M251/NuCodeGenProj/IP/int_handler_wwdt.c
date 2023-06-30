
#if (NUCODEGEN_WWDT)
#if (NUCODEGEN_WWDT_INT_ENABLE)
void WWDT_IRQHandler(void)
{
    /* Get WWDT interrupt flag */
    if (WWDT_GET_INT_FLAG())
    {
        /* Clear WWDT interrupt flag */
        WWDT_CLEAR_INT_FLAG();
    }
    
    /* To prevent system from reset by WWDT, it is necessary to reload WWDT counter
       by software before WWDT counter reaches zero. */
    WWDT_RELOAD_COUNTER();
}
#endif /* NUCODEGEN_WWDT_INT_ENABLE */
#endif /* NUCODEGEN_WWDT */
