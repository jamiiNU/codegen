
#if (NUCODEGEN_SPII2S0)
#if ((NUCODEGEN_SPI0_INT_EN) || (NUCODEGEN_I2S0_INT_EN))
void SPI0_IRQHandler(void)
{
    uint32_t u32IntFlag;
#if(NUCODEGEN_SPII2S0_MODE==NUCODEGEN_SPI0_MODE)
#if (NUCODEGEN_SPI0_INT_EN)
    u32IntFlag = SPI_GetIntFlag(SPI0, NUCODEGEN_SPI0_INT_SEL);
    if (u32IntFlag)
    {
        printf("SPI INT Flag:0x%x\n", u32IntFlag);
    }
    else
    {
        printf("Unknown INT occurred!\n");
    }
#endif //NUCODEGEN_SPI0_INT_EN
#else
#if (NUCODEGEN_I2S0_INT_EN)
    u32IntFlag = SPI0->I2SSTS;
    SPI0->I2SSTS = u32IntFlag;
    if (u32IntFlag)
    {
        printf("I2S INT Flag:0x%x\n", u32IntFlag);
    }
    else
    {
        printf("Unknown INT occurred!\n");
    }
#endif //NUCODEGEN_I2S0_INT_EN
#endif //NUCODEGEN_SPII2S0_MODE
}
#endif //NUCODEGEN_SPII2S0_INT_EN
#endif //NUCODEGEN_SPII2S0
