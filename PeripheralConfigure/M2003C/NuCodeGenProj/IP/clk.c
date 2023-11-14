
#if NUCODEGEN_CLK
void CLK_Init(void)
{
#if (NUCODEGEN_CLK_DET_ENABLE)
    /* Configure clock detector functions, which are able to monitor the operations of HXT and LXT */
    CLK->CLKDCTL = (NUCODEGEN_CLK_DET_CONFIG);
#endif

#if (NUCODEGEN_CLK_HXT_FREQ_DET_ENABLE)
    /* Configure the upper bound and lower bound of HXT frequency range detetor */
    CLK->CDUPB  = CLK_HXT_FREQUENCY_RANGE_UPPER_BOUND;
    CLK->CDLOWB = CLK_HXT_FREQUENCY_RANGE_LOWER_BOUND;
#endif

#if (NUCODEGEN_CLK_PDWK_INT_ENABLE)
    /* Unlock protected registers before we configure power-down wakeup settings. */
    SYS_UnlockReg();

    /* NVIC enable clock power down wake-up interrupt */
    NVIC_EnableIRQ(PWRWU_IRQn);

    /* Enable the power down wake-up interrupt in clock controller. */
    CLK->PWRCTL |= (CLK_PWRCTL_PDWKIEN_Msk);

    /* Lock protected registers after we configure power-down wakeup settings. */
    SYS_LockReg();
#endif

#if (NUCODEGEN_CLK_CLKFAIL_INT_ENABLE)
    /* NVIC enable clock fail interrupt */
    NVIC_EnableIRQ(CKFAIL_IRQn);

    /* Enable the selected clock detector interrupt source in clock controller. */
    CLK->CLKDCTL |= (NUCODEGEN_CLK_CLKFAIL_INT_CONFIG);
#endif
}
#endif /* NUCODEGEN_CLK */
