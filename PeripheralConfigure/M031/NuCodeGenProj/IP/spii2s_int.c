
#if (NUCODEGEN_SPII2S)
#if ((NUCODEGEN_SPI_INT_EN) || (NUCODEGEN_I2S_INT_EN))
void SPI0_IRQHandler(void)
{
    uint32_t u32IntFlag;
#if(NUCODEGEN_SPII2S_MODE==NUCODEGEN_SPI_MODE)
#if (NUCODEGEN_SPI_INT_EN)
    u32IntFlag = SPI_GetIntFlag(SPI0, NUCODEGEN_SPI_INT_SEL);
    if(u32IntFlag){
        printf("SPI INT Flag:0x%x\n", u32IntFlag);
    }else{
        printf("Unknown INT occurred!\n");
    }
#endif //NUCODEGEN_SPI_INT_EN
#else
#if (NUCODEGEN_I2S_INT_EN)
    u32IntFlag = SPI0->I2SSTS;
    SPI0->I2SSTS = u32IntFlag;
    if(u32IntFlag){
        printf("I2S INT Flag:0x%x\n", u32IntFlag);
    }else{
        printf("Unknown INT occurred!\n");
    }
#endif //NUCODEGEN_I2S_INT_EN
#endif  //NUCODEGEN_SPII2S_MODE
}
#endif //NUCODEGEN_SPII2S_INT_EN
#endif //NUCODEGEN_SPII2S
