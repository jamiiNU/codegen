#if (NUCODEGEN_I2C0)
void I2C0_Init()
{
    I2C_Open(I2C0, NUCODEGEN_I2C0_BUSCLOCK);

#if (NUCODEGEN_I2C0_ADDR0_EN)
    I2C_SetSlaveAddr(I2C0, 0, NUCODEGEN_I2C0_ADDR0, NUCODEGEN_I2C0_ADDR0_GC_SEL);
    I2C_SetSlaveAddrMask(I2C0, 0, NUCODEGEN_I2C0_ADDRMSK0);
#endif
#if (NUCODEGEN_I2C0_ADDR1_EN)
    I2C_SetSlaveAddr(I2C0, 1, NUCODEGEN_I2C0_ADDR1, NUCODEGEN_I2C0_ADDR1_GC_SEL);
    I2C_SetSlaveAddrMask(I2C0, 1, NUCODEGEN_I2C0_ADDRMSK1);
#endif
#if (NUCODEGEN_I2C0_ADDR2_EN)
    I2C_SetSlaveAddr(I2C0, 2, NUCODEGEN_I2C0_ADDR2, NUCODEGEN_I2C0_ADDR2_GC_SEL);
    I2C_SetSlaveAddrMask(I2C0, 2, NUCODEGEN_I2C0_ADDRMSK2);
#endif

#if (NUCODEGEN_I2C0_ADDR3_EN)
    I2C_SetSlaveAddr(I2C0, 3, NUCODEGEN_I2C0_ADDR3, NUCODEGEN_I2C0_ADDR3_GC_SEL);
    I2C_SetSlaveAddrMask(I2C0, 3, NUCODEGEN_I2C0_ADDRMSK3);
#endif

#if (NUCODEGEN_I2C0_TIMEOUT_EN)
    I2C_EnableTimeout(I2C0, I2C0_TIMEOUT_SEL);
#endif

#if NUCODEGEN_I2C0_WAKEUP_EN
    /* Enable I2C wake-up */
    I2C_EnableWakeup(I2C0);
#endif /*NUCODEGEN_I2C0_WAKEUP_EN*/

#if(NUCODEGEN_I2C0_SUBMODE_SEL==NUCODEGEN_I2C0_SUBMODE_NORMAL)
#if (NUCODEGEN_I2C0_10BIT_ADDRESSING_EN)
    I2C0->CTL1 |= I2C_CTL1_ADDR10EN_Msk;
#endif

#if (NUCODEGEN_I2C0_PDMA_EN)
    I2C0->CTL1 |= I2C_CTL1_TXPDMAEN_Msk | I2C_CTL1_RXPDMAEN_Msk;
#endif

#endif /*(NUCODEGEN_I2C0_SUBMODE_SEL==I2C0_SUBMODE_NORMAL)*/

#if (NUCODEGEN_I2C0_SUBMODE_SEL == NUCODEGEN_I2C0_SUBMODE_SMBUS)

    /* I2C0 Bus management enable */
    I2C_SMBusOpen(I2C0, NUCODEGEN_I2C0_SMBUS_ROLE_SEL);

    /* I2C0 Bus PEC check and transmit enable */
    I2C_SMBusPECTxEnable(I2C0, NUCODEGEN_I2C0_SMBUS_PEC_EN);

#endif /*(NUCODEGEN_I2C0_SUBMODE_SEL == NUCODEGEN_I2C0_SUBMODE_SMBUS)*/

#if NUCODEGEN_I2C0_INT_EN

    I2C_EnableInt(I2C0);
    NVIC_EnableIRQ(I2C0_IRQn);
#endif

}

#endif /*NUCODEGEN_I2C0*/




#if (NUCODEGEN_I2C1)
void I2C1_Init()
{
    I2C_Open(I2C1, NUCODEGEN_I2C1_BUSCLOCK);

#if (NUCODEGEN_I2C1_ADDR0_EN)
    I2C_SetSlaveAddr(I2C1, 0, NUCODEGEN_I2C1_ADDR0, NUCODEGEN_I2C1_ADDR0_GC_SEL);
    I2C_SetSlaveAddrMask(I2C1, 0, NUCODEGEN_I2C1_ADDRMSK0);
#endif
#if (NUCODEGEN_I2C1_ADDR1_EN)
    I2C_SetSlaveAddr(I2C1, 1, NUCODEGEN_I2C1_ADDR1, NUCODEGEN_I2C1_ADDR1_GC_SEL);
    I2C_SetSlaveAddrMask(I2C1, 1, NUCODEGEN_I2C1_ADDRMSK1);
#endif
#if (NUCODEGEN_I2C1_ADDR2_EN)
    I2C_SetSlaveAddr(I2C1, 2, NUCODEGEN_I2C1_ADDR2, NUCODEGEN_I2C1_ADDR2_GC_SEL);
    I2C_SetSlaveAddrMask(I2C1, 2, NUCODEGEN_I2C1_ADDRMSK2);
#endif

#if (NUCODEGEN_I2C1_ADDR3_EN)
    I2C_SetSlaveAddr(I2C1, 3, NUCODEGEN_I2C1_ADDR3, NUCODEGEN_I2C1_ADDR3_GC_SEL);
    I2C_SetSlaveAddrMask(I2C1, 3, NUCODEGEN_I2C1_ADDRMSK3);
#endif

#if (NUCODEGEN_I2C1_TIMEOUT_EN)
    I2C_EnableTimeout(I2C1, I2C1_TIMEOUT_SEL);
#endif

#if NUCODEGEN_I2C1_WAKEUP_EN
    /* Enable I2C wake-up */
    I2C_EnableWakeup(I2C1);
#endif /*NUCODEGEN_I2C1_WAKEUP_EN*/

#if(NUCODEGEN_I2C1_SUBMODE_SEL==NUCODEGEN_I2C1_SUBMODE_NORMAL)
#if (NUCODEGEN_I2C1_10BIT_ADDRESSING_EN)
    I2C1->CTL1 |= I2C_CTL1_ADDR10EN_Msk;
#endif

#if (NUCODEGEN_I2C1_PDMA_EN)
    I2C1->CTL1 |= I2C_CTL1_TXPDMAEN_Msk | I2C_CTL1_RXPDMAEN_Msk;
#endif

#endif /*(NUCODEGEN_I2C1_SUBMODE_SEL==I2C1_SUBMODE_NORMAL)*/

#if (NUCODEGEN_I2C1_SUBMODE_SEL == NUCODEGEN_I2C1_SUBMODE_SMBUS)

    /* I2C1 Bus management enable */
    I2C_SMBusOpen(I2C1, NUCODEGEN_I2C1_SMBUS_ROLE_SEL);

    /* I2C1 Bus PEC check and transmit enable */
    I2C_SMBusPECTxEnable(I2C1, NUCODEGEN_I2C1_SMBUS_PEC_EN);

#endif /*(NUCODEGEN_I2C1_SUBMODE_SEL == NUCODEGEN_I2C1_SUBMODE_SMBUS)*/

#if NUCODEGEN_I2C1_INT_EN

    I2C_EnableInt(I2C1);
    NVIC_EnableIRQ(I2C1_IRQn);
#endif

}

#endif /*NUCODEGEN_I2C1*/