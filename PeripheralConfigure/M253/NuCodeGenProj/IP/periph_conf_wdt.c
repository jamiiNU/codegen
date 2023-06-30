
#if (NUCODEGEN_WDT)
void WDT_Init(void)
{
    /* Unlock protected registers */
    SYS_UnlockReg();

    /* Setup WDT Configuration */
    WDT_Open(WDT_TOUTSEL_CONFIG, WDT_RSTDSEL_CONFIG, WDT_RSTEN_CONFIG, WDT_WKEN_CONFIG);

#if (NUCODEGEN_WDT_INT_ENABLE)
    /* Enable WDT Time-out Interrupt */
    WDT_EnableInt();
    
    /* NVIC Enable WDT Interrupt */
    NVIC_EnableIRQ(WDT_IRQn);
#endif /* NUCODEGEN_WDT_INT_ENABLE */
}
#endif /* NUCODEGEN_WDT */
