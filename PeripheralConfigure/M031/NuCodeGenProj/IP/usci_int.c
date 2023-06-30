
#if (NUCODEGEN_USCI0_I2C || NUCODEGEN_USCI1_I2C || NUCODEGEN_USCI0_UART || NUCODEGEN_USCI1_UART || NUCODEGEN_USCI0_SPI || NUCODEGEN_USCI1_SPI)

#if NUCODEGEN_UI2C0_INT_EN
void UI2C0_IRQHandler(void)	
{
    /* UI2C0 Interrupt status */
    uint32_t u32Status;

    u32Status = (UI2C0->PROTSTS);

    (void)u32Status; /*To remove complier warning. The code is unnecessary if u32Status is used.*/

#if NUCODEGEN_UI2C0_WAKEUP_EN
    if((UI2C0->WKSTS & UI2C_WKSTS_WKF_Msk) == UI2C_WKSTS_WKF_Msk)
    {

        while((UI2C0->PROTSTS & UI2C_PROTSTS_WKAKDONE_Msk) == 0) {};

        /* Clear WK flag */
        UI2C_CLR_WAKEUP_FLAG(UI2C0);
        UI2C0->PROTSTS = UI2C_PROTSTS_WKAKDONE_Msk;

        return;
    }
#endif /*NUCODEGEN_UI2C0_WAKEUP_EN*/

    if (UI2C_GET_TIMEOUT_FLAG(UI2C0))
    {
        /* Clear USCI_I2C0 Timeout Flag */
        UI2C_ClearTimeoutFlag(UI2C0);

        /*TODO: put user code here*/
    }
    else
    {
        /*TODO: put user code here*/
    }
}    
#endif /*NUCODEGEN_UI2C0_INT_EN*/

#if NUCODEGEN_UI2C1_INT_EN
void UI2C1_IRQHandler(void)
{
    /* UI2C1 Interrupt status */	
    uint32_t u32Status;

    u32Status = (UI2C1->PROTSTS);

    (void)u32Status; /*To remove complier warning. The code is unnecessary if u32Status is used.*/

#if NUCODEGEN_UI2C1_WAKEUP_EN
    if((UI2C1->WKSTS & UI2C_WKSTS_WKF_Msk) == UI2C_WKSTS_WKF_Msk)
    {

        while((UI2C1->PROTSTS & UI2C_PROTSTS_WKAKDONE_Msk) == 0) {};

        /* Clear WK flag */
        UI2C_CLR_WAKEUP_FLAG(UI2C1);
        UI2C1->PROTSTS = UI2C_PROTSTS_WKAKDONE_Msk;

        return;
    }
#endif /*NUCODEGEN_UI2C1_WAKEUP_EN*/

    if (UI2C_GET_TIMEOUT_FLAG(UI2C1))
    {
        /* Clear USCI_I2C1 Timeout Flag */
        UI2C_ClearTimeoutFlag(UI2C1);

        /*TODO: put user code here*/
    }
    else
    {
        /*TODO: put user code here*/
    }
}
#endif /*NUCODEGEN_UI2C1_INT_EN*/

#if (NUCODEGEN_UUART0_INT_ENABLE)
void UUART0_IRQHandler(void)
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

#if (NUCODEGEN_UUART1_INT_ENABLE)
void UUART1_IRQHandler(void)
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

#if (NUCODEGEN_USPI0_INT_EN)
void USPI0_IRQHandler(void)
{
    uint32_t u32IntFlag;
    /* USCI0 is configured as USPI function */
    /* Get USPI interrupt flag */
    u32IntFlag = USPI_GetIntFlag(USPI0, NUCODEGEN_USPI0_INT_SEL);

    /* Clear USPI interrupt flag */
    USPI_ClearIntFlag(USPI0, u32IntFlag);
}
#endif /* NUCODEGEN_USPI0_INT_EN */

#if (NUCODEGEN_USPI1_INT_EN)
void USPI1_IRQHandler(void)
{
    uint32_t u32IntFlag;
    /* USCI1 is configured as USPI function */
    /* Get USPI interrupt flag */
    u32IntFlag = USPI_GetIntFlag(USPI1, NUCODEGEN_USPI1_INT_SEL);

    /* Clear USPI interrupt flag */
    USPI_ClearIntFlag(USPI1, u32IntFlag);
}
#endif /* NUCODEGEN_USPI1_INT_EN */

#if (NUCODEGEN_UI2C0_INT_EN || NUCODEGEN_UI2C1_INT_EN || NUCODEGEN_UUART0_INT_ENABLE || NUCODEGEN_UUART1_INT_ENABLE || NUCODEGEN_USPI0_INT_EN || NUCODEGEN_USPI1_INT_EN)
/*---------------------------------------------------------------------------------------------------------*/
/*  USCI IRQ Handler                                                                                       */
/*---------------------------------------------------------------------------------------------------------*/
void USCI01_IRQHandler(void)
{
#if NUCODEGEN_UI2C0_INT_EN
    UI2C0_IRQHandler();
#endif /*NUCODEGEN_UI2C0_INT_EN*/

#if NUCODEGEN_UI2C1_INT_EN
    UI2C1_IRQHandler();
#endif /*NUCODEGEN_UI2C1_INT_EN*/    

#if NUCODEGEN_UUART0_INT_ENABLE
    UUART0_IRQHandler();
#endif /*NUCODEGEN_UUART0_INT_ENABLE*/

#if NUCODEGEN_UUART1_INT_ENABLE
    UUART1_IRQHandler();
#endif /*NUCODEGEN_UUART1_INT_ENABLE*/

#if NUCODEGEN_USPI0_INT_EN
    USPI0_IRQHandler();
#endif /*NUCODEGEN_USPI0_INT_EN*/

#if NUCODEGEN_USPI1_INT_EN
    USPI1_IRQHandler();
#endif /*NUCODEGEN_USPI1_INT_EN*/
}

#endif /*(NUCODEGEN_UI2C0_INT_EN || NUCODEGEN_UI2C1_INT_EN || NUCODEGEN_UUART0_INT_ENABLE || NUCODEGEN_UUART1_INT_ENABLE || NUCODEGEN_USPI0_INT_EN || NUCODEGEN_USPI1_INT_EN)*/
#endif /*(NUCODEGEN_USCI0_I2C || NUCODEGEN_USCI1_I2C || NUCODEGEN_USCI0_UART || NUCODEGEN_USCI1_UART || NUCODEGEN_USCI0_SPI || NUCODEGEN_USCI1_SPI)*/
