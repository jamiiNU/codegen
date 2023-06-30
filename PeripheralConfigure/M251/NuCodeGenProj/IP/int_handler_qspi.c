
#if (NUCODEGEN_QSPI0)
#if (NUCODEGEN_QSPI0_INT_EN)
void QSPI0_IRQHandler(void)
{
    uint32_t u32IntFlag;

    u32IntFlag = QSPI_GetIntFlag(QSPI0, NUCODEGEN_QSPI0_INT_SEL);
    if (u32IntFlag)
    {
        printf("0x%x\n", u32IntFlag);
    }

}
#endif //NUCODEGEN_QSPI0_INT_EN
#endif //NUCODEGEN_QSPI0
