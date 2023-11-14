
#if (NUCODEGEN_USCI0_UART)
#if (NUCODEGEN_UUART0_INT_ENABLE)
void USCI0_IRQHandler(void)
{
    uint32_t u32IntFlag;
    /* USCI0 is configured as UUART function */
    /* Get UUART interrupt flag */
    u32IntFlag = UUART_GetIntFlag(UUART0, UUART0_INT_CONFIG);

    /* Clear UUART interrupt flag */
    UUART_ClearIntFlag(UUART0, u32IntFlag);

    /* Get UUART wakeup flag */
    if (UUART_GET_WAKEUP_FLAG(UUART0))
    {
        /* Clear UUART wakeup flag */
        UUART_CLR_WAKEUP_FLAG(UUART0);
    }
}
#endif /* NUCODEGEN_UUART0_INT_ENABLE */
#endif /* NUCODEGEN_USCI0_UART*/
