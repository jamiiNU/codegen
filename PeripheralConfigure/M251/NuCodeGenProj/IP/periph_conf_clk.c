
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
    /* NVIC enable clock power down wake-up interrupt */
    NVIC_EnableIRQ(PWRWU_IRQn);
    
    /* Enable the power down wake-up interrupt in clock controller. */
    CLK->PWRCTL |= (CLK_PWRCTL_PDWKIEN_Msk);
#endif

#if (NUCODEGEN_CLK_CLKFAIL_INT_ENABLE)
    /* NVIC enable clock fail interrupt */
    NVIC_EnableIRQ(CLKFAIL_IRQn);
    
    /* Enable the selected clock detector interrupt source in clock controller. */
    CLK->CLKDCTL |= (NUCODEGEN_CLK_CLKFAIL_INT_CONFIG);
#endif

#if (NUCODEGEN_CLK_POWER_DOWN_ENABLE)
    /* Unlock protected registers before we configure power down settings. */
    SYS_UnlockReg();
    
    /* Set power manager control to default first for safe. */
    CLK->PMUCTL = 0;
    
    /* Select clock power down mode */
    CLK_SetPowerDownMode(NUCODEGEN_CLK_POWER_DOWN_MODE);
    
#if (NUCODEGEN_CLK_POWER_DOWN_IS_DPD)
#if (NUCODEGEN_CLK_WKPINDB_ENABLE)
    /* Enable DPD wake-up pin debounce */
    CLK_ENABLE_WKPINDB();
#else
    /* Disable DPD wake-up pin debounce */
    CLK_DISABLE_WKPINDB();
#endif /* NUCODEGEN_CLK_WKPINDB_ENABLED */

#if (NUCODEGEN_CLK_DPDWKPIN0_ENABLE)
    /* Enable DPD wake-up pin 0 */
    CLK_EnableDPDWKPin0(NUCODEGEN_CLK_DPDWKPIN0_CONFIG);
#endif

#if (NUCODEGEN_CLK_DPDWKPIN1_ENABLE)
    /* Enable DPD wake-up pin 1 */
    CLK_EnableDPDWKPin1(NUCODEGEN_CLK_DPDWKPIN1_CONFIG);
#endif

#if (NUCODEGEN_CLK_DPDWKPIN2_ENABLE)
    /* Enable DPD wake-up pin 2 */
    CLK_EnableDPDWKPin2(NUCODEGEN_CLK_DPDWKPIN2_CONFIG);
#endif

#if (NUCODEGEN_CLK_DPDWKPIN3_ENABLE)
    /* Enable DPD wake-up pin 3 */
    CLK_EnableDPDWKPin3(NUCODEGEN_CLK_DPDWKPIN3_CONFIG);
#endif

#if (NUCODEGEN_CLK_DPDWKPIN4_ENABLE)
    /* Enable DPD wake-up pin 4 */
    CLK_EnableDPDWKPin4(NUCODEGEN_CLK_DPDWKPIN4_CONFIG);
#endif

#if (NUCODEGEN_CLK_DPDRTCWK_ENABLE)

    /* Enable DPD wake-up by RTC interrupt source */
    CLK_ENABLE_RTCWK();    
#endif /* NUCODEGEN_CLK_DPDRTCWK_ENABLE */

#if (NUCODEGEN_CLK_DPDWKTMR_ENABLE)
    /* Configure the timeout interval of Wake-up Timer */
    CLK_SET_WKTMR_INTERVAL(NUCODEGEN_CLK_DPDWKTMR_CONFIG);
    
    /* Enable Wake-up Timer */
    CLK_ENABLE_WKTMR();
#endif /* NUCODEGEN_CLK_DPDWKTMR_ENABLE */
#endif /* NUCODEGEN_CLK_POWER_DOWN_IS_DPD */
#endif /* NUCODEGEN_CLK_POWER_DOWN_ENABLE */
}
#endif /* NUCODEGEN_CLK */
