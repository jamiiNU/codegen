
#if (NUCODEGEN_USCI0_I2C)
void USCI0_I2C_Init()
{
    /* Open USCI_I2C0 and set clock*/
    UI2C_Open(UI2C0, NUCODEGEN_UI2C0_CLOCK);

#if (NUCODEGEN_UI2C0_ADDR0_EN)
    /* Set UI2C0 Slave Addresses 0 */
    UI2C_SetSlaveAddr(UI2C0, 0, NUCODEGEN_UI2C0_ADDR0, NUCODEGEN_UI2C0_ADDR0_GC_SEL);
    UI2C_SetSlaveAddrMask(UI2C0, 0, NUCODEGEN_UI2C0_ADDRMSK0);
#endif

#if (NUCODEGEN_UI2C0_ADDR1_EN)
    /* Set UI2C0 Slave Addresses 1 */
    UI2C_SetSlaveAddr(UI2C0, 1, NUCODEGEN_UI2C0_ADDR1, NUCODEGEN_UI2C0_ADDR1_GC_SEL);
    UI2C_SetSlaveAddrMask(UI2C0, 1, NUCODEGEN_UI2C0_ADDRMSK1);
#endif

#if (NUCODEGEN_UI2C0_10BIT_FORMAT_EN)
    /* Enable UI2C0 10-bit address mode */
    UI2C_ENABLE_10BIT_ADDR_MODE(UI2C0);
#endif /* NUCODEGEN_UI2C0_10BIT_FORMAT_EN */

#if NUCODEGEN_UI2C0_WAKEUP_EN
    UI2C_EnableWakeup(UI2C0, NUCODEGEN_UI2C0_WAKEUP_SEL);
#endif /* NUCODEGEN_UI2C0_WAKEUP_EN */

#if NUCODEGEN_UI2C0_TIMEOUT_EN
    UI2C_EnableTimeout(UI2C0, NUCODEGEN_UI2C0_TIMEOUT_CNT);
#endif /* NUCODEGEN_UI2C0_TIMEOUT_EN */

#if NUCODEGEN_UI2C0_INT_EN
    /* Enable UI2C0 protocol interrupt */
    UI2C_ENABLE_PROT_INT(UI2C0, (UI2C_PROTIEN_ACKIEN_Msk | UI2C_PROTIEN_NACKIEN_Msk | UI2C_PROTIEN_STORIEN_Msk | UI2C_PROTIEN_STARIEN_Msk));
    NVIC_EnableIRQ(USCI0_IRQn);
#endif /* NUCODEGEN_UI2C0_INT_EN */

}
#endif /*NUCODEGEN_USCI0_I2C*/
