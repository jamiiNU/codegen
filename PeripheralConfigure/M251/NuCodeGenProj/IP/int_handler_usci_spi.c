
#if (NUCODEGEN_USCI0_SPI)
#if (NUCODEGEN_USPI0_INT_EN)
void USCI0_IRQHandler(void)
{
    uint32_t u32IntFlag;
    /* USCI0 is configured as USPI function */
    /* Get SPI interrupt flag */
    u32IntFlag = USPI_GetIntFlag(USPI0, NUCODEGEN_USPI0_INT_SEL);
    
    /* Clear USPI interrupt flag */
    USPI_ClearIntFlag(USPI0, u32IntFlag);
}
#endif /* NUCODEGEN_USPI0_INT_EN */
#endif /* NUCODEGEN_USCI0_SPI*/

#if (NUCODEGEN_USCI1_SPI)
#if (NUCODEGEN_USPI1_INT_EN)
void USCI1_IRQHandler(void)
{
    uint32_t u32IntFlag;
    /* USCI0 is configured as USPI function */
    /* Get SPI interrupt flag */
    u32IntFlag = USPI_GetIntFlag(USPI1, NUCODEGEN_USPI1_INT_SEL);
    
    /* Clear USPI interrupt flag */
    USPI_ClearIntFlag(USPI1, u32IntFlag);
}
#endif /* NUCODEGEN_USPI1_INT_EN */
#endif /* NUCODEGEN_USCI1_SPI */

#if (NUCODEGEN_USCI2_SPI)
#if (NUCODEGEN_USPI2_INT_EN)
void USCI2_IRQHandler(void)
{
    uint32_t u32IntFlag;
    /* USCI0 is configured as USPI function */
    /* Get SPI interrupt flag */
    u32IntFlag = USPI_GetIntFlag(USPI2, NUCODEGEN_USPI2_INT_SEL);
    
    /* Clear USPI interrupt flag */
    USPI_ClearIntFlag(USPI2, u32IntFlag);
}
#endif /* NUCODEGEN_USPI2_INT_EN */
#endif /* NUCODEGEN_USCI2_SPI*/
