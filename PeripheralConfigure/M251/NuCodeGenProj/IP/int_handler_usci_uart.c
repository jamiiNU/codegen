
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



#if (NUCODEGEN_USCI1_UART)
#if (NUCODEGEN_UUART1_INT_ENABLE)
void USCI1_IRQHandler(void)
{
    uint32_t u32IntFlag;
    /* USCI1 is configured as UUART function */
    /* Get UUART interrupt flag */
    u32IntFlag = UUART_GetIntFlag(UUART1, UUART1_INT_CONFIG);
    
    /* Clear UUART interrupt flag */
    UUART_ClearIntFlag(UUART1, u32IntFlag);
    
    /* Get UUART wakeup flag */
    if (UUART_GET_WAKEUP_FLAG(UUART1))
    {
        /* Clear UUART wakeup flag */
        UUART_CLR_WAKEUP_FLAG(UUART1);
    }
}
#endif /* NUCODEGEN_UUART1_INT_ENABLE */
#endif /* NUCODEGEN_USCI1_UART*/



#if (NUCODEGEN_USCI2_UART)
#if (NUCODEGEN_UUART2_INT_ENABLE)
void USCI2_IRQHandler(void)
{
    uint32_t u32IntFlag;
    /* USCI2 is configured as UUART function */
    /* Get UUART interrupt flag */
    u32IntFlag = UUART_GetIntFlag(UUART2, UUART2_INT_CONFIG);
    
    /* Clear UUART interrupt flag */
    UUART_ClearIntFlag(UUART2, u32IntFlag);
    
    /* Get UUART wakeup flag */
    if (UUART_GET_WAKEUP_FLAG(UUART2))
    {
        /* Clear UUART wakeup flag */
        UUART_CLR_WAKEUP_FLAG(UUART2);
    }
}
#endif /* NUCODEGEN_UUART2_INT_ENABLE */
#endif /* NUCODEGEN_USCI2_UART*/
