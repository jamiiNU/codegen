
#if (NUCODEGEN_DAC0 || NUCODEGEN_DAC1)
#if (NUCODEGEN_DAC0_INT_EN || NUCODEGEN_DAC1_INT_EN)
void DAC_IRQHandler(void)
{
#if (NUCODEGEN_DAC0_INT_EN)
    /* Check DAC0 interrupt flag */
    if (DAC_GET_INT_FLAG(NUCODEGEN_DAC0_MODULE_SEL, DAC0_MODULE_0))
    {
        /* Clear DAC0 interrupt flag */
        DAC_CLR_INT_FLAG(NUCODEGEN_DAC0_MODULE_SEL, DAC0_MODULE_0);

        /* insert next convert data of DAC0. Ex: DAC_WRITE_DATA(DAC0, 0, 0xFF); */
    }
#endif
#if (NUCODEGEN_DAC1_INT_EN)
    /* Check DAC interrupt flag */
    if (DAC_GET_INT_FLAG(NUCODEGEN_DAC1_MODULE_SEL, DAC1_MODULE_0))
    {
        /* Clear DAC interrupt flag */
        DAC_CLR_INT_FLAG(NUCODEGEN_DAC1_MODULE_SEL, DAC1_MODULE_0);

        /* insert next convert data of DAC1. Ex: DAC_WRITE_DATA(DAC1, 0, 0xFF); */
    }
#endif
}
#endif /* NUCODEGEN_DAC0_INT_EN or NUCODEGEN_DAC1_INT_EN*/
#endif /* NUCODEGEN_DAC */
