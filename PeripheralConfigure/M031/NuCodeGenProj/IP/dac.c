

#if (NUCODEGEN_DAC)
void DAC_Init()
{
    /* Enable DAC */
    DAC_Open(NUCODEGEN_DAC_MODULE_SEL, DAC_MODULE_0, NUCODEGEN_DAC_TRIGGER_SEL);

    /* DAC delay time */
    DAC_SetDelayTime(NUCODEGEN_DAC_MODULE_SEL, NUCODEDEF_DAC_DLY_TIME);

#if (NUCODEGEN_DAC0_GROUP_EN)
    /* Enable DAC group function */

#endif /* NUCODEGEN_DAC0_GROUP_EN */

#if (NUCODEGEN_DAC_DAT_WIDTH)
    /* Setting DAC data width */
    DAC_WIDTH(DAC_BIT_8);
#else
#if (NUCODEGEN_DAC_DAT_ALIGN)
    /* Setting DAC data width */
    DAC_WIDTH(DAC_BIT_12);

    /* Enable DAC data left align */
    DAC_ENABLE_LEFT_ALIGN(NUCODEGEN_DAC_MODULE_SEL);
#endif /* NUCODEGEN_DAC_DAT_ALIGN */
#endif /* NUCODEGEN_DAC_DAT_WIDTH */

#if (NUCODEGEN_DAC_ADVANCED)

#if (NUCODEGEN_DAC_INT_EN)
    /* Enable DAC interrupt */
    DAC_ENABLE_INT(NUCODEGEN_DAC_MODULE_SEL, DAC_MODULE_0);

    /* Enable DAC interrupt */
    NVIC_EnableIRQ(NUCODEGEN_DAC_IRQ_MODULE_SEL);
#endif /* NUCODEGEN_DAC_ADVANCED */

#if (NUCODEGEN_DAC_INT_DMA_UNDERRUN)
    /* Enable DAC DMA under run interrupt */
    DAC_ENABLE_DMAUDR_INT(NUCODEGEN_DAC_MODULE_SEL);
#endif /* NUCODEGEN_DAC_INT_DMA_UNDERRUN */

#if (NUCODEGEN_DAC_DMA_EN)
    /* Enable DAC PDMA mode */
    DAC_ENABLE_PDMA(NUCODEGEN_DAC_MODULE_SEL);
#endif /* NUCODEGEN_DAC_DMA_EN */

#if (!NUCODEGEN_DAC_VOLT_BUF_EN)
    /* DAC bypass buffer */
    DAC_ENABLE_BYPASS_BUFFER(NUCODEGEN_DAC_MODULE_SEL);
#endif /* NUCODEGEN_DAC_VOLT_BUF_EN */

#endif /* NUCODEGEN_DAC_ADVANCED */
}
#endif /* NUCODEGEN_DAC */
