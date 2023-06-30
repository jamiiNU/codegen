
#if (NUCODEGEN_CLK)
#if (NUCODEGEN_CLK_CLKFAIL_INT_ENABLE)
void CKFAIL_IRQHandler(void)
{
    volatile uint32_t u32Reg;

    /* Unlock protected registers */
    SYS_UnlockReg();

    u32Reg = CLK->CLKDSTS;

#if (NUCODEGEN_CLK_HXT_FAIL_DET_ENABLE)
    if (u32Reg & CLK_CLKDSTS_HXTFIF_Msk)
    {
        /* HCLK is switched to HIRC automatically if HXT clock fail interrupt is happened */
        printf("HXT Clock is stopped! HCLK is switched to HIRC.\n");

        /* Disable HXT clock fail interrupt */
        CLK->CLKDCTL &= ~(CLK_CLKDCTL_HXTFDEN_Msk | CLK_CLKDCTL_HXTFIEN_Msk);

        /* Write 1 to clear HXT Clock fail interrupt flag */
        CLK->CLKDSTS = CLK_CLKDSTS_HXTFIF_Msk;
    }
#endif /* NUCODEGEN_CLK_HXT_FAIL_DET_ENABLE */

#if (NUCODEGEN_CLK_LXT_FAIL_DET_ENABLE)
    if (u32Reg & CLK_CLKDSTS_LXTFIF_Msk)
    {
        /* LXT clock fail interrupt is happened */
        printf("LXT Clock is stopped!\n");

        /* Disable HXT clock fail interrupt */
        CLK->CLKDCTL &= ~(CLK_CLKDCTL_LXTFIEN_Msk | CLK_CLKDCTL_LXTFDEN_Msk);

        /* Write 1 to clear LXT Clock fail interrupt flag */
        CLK->CLKDSTS = CLK_CLKDSTS_LXTFIF_Msk;
    }
#endif /* NUCODEGEN_CLK_LXT_FAIL_DET_ENABLE */

#if (NUCODEGEN_CLK_HXT_FREQ_DET_ENABLE)
    if (u32Reg & CLK_CLKDSTS_HXTFQIF_Msk)
    {
        /* HCLK should be switched to HIRC if HXT clock frequency monitor interrupt is happened */
        CLK_SetHCLK(CLK_CLKSEL0_HCLKSEL_HIRC, CLK_CLKDIV0_HCLK(1));
        printf("HXT Frequency is abnormal! HCLK is switched to HIRC.\n");

        /* Disable HXT clock frequency monitor interrupt */
        CLK->CLKDCTL &= ~(CLK_CLKDCTL_HXTFQDEN_Msk | CLK_CLKDCTL_HXTFQIEN_Msk);

        /* Write 1 to clear HXT Clock frequency monitor interrupt */
        CLK->CLKDSTS = CLK_CLKDSTS_HXTFQIF_Msk;
    }
#endif /* NUCODEGEN_CLK_HXT_FREQ_DET_ENABLE */

    /* Lock protected registers */
    SYS_LockReg();
}
#endif /* NUCODEGEN_CLK_CLKFAIL_INT_ENABLE */
#endif /* NUCODEGEN_CLK */


#if (NUCODEGEN_CLK)
#if (NUCODEGEN_CLK_PDWK_INT_ENABLE)
void PWRWU_IRQHandler(void)
{
    /* Check system power down mode wake-up interrupt status flag */
    if (CLK->PWRCTL & CLK_PWRCTL_PDWKIF_Msk)
    {
        /* Clear system power down wake-up interrupt flag */
        CLK->PWRCTL |= CLK_PWRCTL_PDWKIF_Msk;

        printf("System wake-up from Power-down mode.\n");
    }
}
#endif /* NUCODEGEN_CLK_PDWK_INT_ENABLE */
#endif /* NUCODEGEN_CLK */
