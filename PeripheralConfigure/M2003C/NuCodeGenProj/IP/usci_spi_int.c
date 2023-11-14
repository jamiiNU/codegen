
#if (NUCODEGEN_USCI0_SPI)
#if (NUCODEGEN_USPI0_INT_EN)
void USCI0_IRQHandler(void)
{
    uint32_t u32IntFlag;
    /* USCI0 is configured as USPI function */
    /* Get USPI interrupt flag */
    u32IntFlag = USPI_GetIntFlag(USPI0, NUCODEGEN_USPI0_INT_SEL);
    
    /* Clear USPI interrupt flag */
    USPI_ClearIntFlag(USPI0, u32IntFlag);
}
#endif /* NUCODEGEN_USPI0_INT_EN */
#endif /* NUCODEGEN_USCI0_SPI*/
