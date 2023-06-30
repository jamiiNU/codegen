
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


#if (NUCODEGEN_USCI1_I2C)
#if NUCODEGEN_UI2C1_INT_EN
/*---------------------------------------------------------------------------------------------------------*/
/*  USCI_I2C IRQ Handler                                                                                   */
/*---------------------------------------------------------------------------------------------------------*/
void USCI1_IRQHandler(void)
{
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
#endif /*NUCODEGEN_USCI1*/

#if (NUCODEGEN_USCI2_I2C)
#if NUCODEGEN_UI2C2_INT_EN
/*---------------------------------------------------------------------------------------------------------*/
/*  USCI_I2C IRQ Handler                                                                                   */
/*---------------------------------------------------------------------------------------------------------*/
void USCI2_IRQHandler(void)
{
    uint32_t u32Status;

    u32Status = (UI2C2->PROTSTS);
    
    (void)u32Status; /*To remove complier warning. The code is unnecessary if u32Status is used.*/
    
    #if NUCODEGEN_UI2C2_WAKEUP_EN
    if((UI2C2->WKSTS & UI2C_WKSTS_WKF_Msk) == UI2C_WKSTS_WKF_Msk)
    {

        while((UI2C2->PROTSTS & UI2C_PROTSTS_WKAKDONE_Msk) == 0) {};

        /* Clear WK flag */
        UI2C_CLR_WAKEUP_FLAG(UI2C2);
        UI2C2->PROTSTS = UI2C_PROTSTS_WKAKDONE_Msk;

        return;
    }
    #endif /*NUCODEGEN_UI2C2_WAKEUP_EN*/

    if (UI2C_GET_TIMEOUT_FLAG(UI2C2))
    {
        /* Clear USCI_I2C2 Timeout Flag */
        UI2C_ClearTimeoutFlag(UI2C2);

        /*TODO: put user code here*/
    }
    else
    {
        /*TODO: put user code here*/
    }
}

#endif /*NUCODEGEN_UI2C2_INT_EN*/
#endif /*NUCODEGEN_USCI2*/
