
#if (NUCODEGEN_USCI0_I2C)
#if NUCODEGEN_UI2C0_INT_EN
/*---------------------------------------------------------------------------------------------------------*/
/*  USCI_I2C IRQ Handler                                                                                   */
/*---------------------------------------------------------------------------------------------------------*/
void USCI0_IRQHandler(void)
{
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
#endif /*NUCODEGEN_USCI0*/
