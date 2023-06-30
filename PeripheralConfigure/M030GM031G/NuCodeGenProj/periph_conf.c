#include "NuCodeGenProj.h"

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
    /* Enable I2C0 10-bit address mode */
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


#if (NUCODEGEN_USCI1_I2C)
void USCI1_I2C_Init()
{
    /* Open USCI_I2C1 and set clock*/
    UI2C_Open(UI2C1, NUCODEGEN_UI2C1_CLOCK);

#if (NUCODEGEN_UI2C1_ADDR0_EN)
    /* Set UI2C1 Slave Addresses 0 */
    UI2C_SetSlaveAddr(UI2C1, 0, NUCODEGEN_UI2C1_ADDR0, NUCODEGEN_UI2C1_ADDR0_GC_SEL);
    UI2C_SetSlaveAddrMask(UI2C1, 0, NUCODEGEN_UI2C1_ADDRMSK0);
#endif

#if (NUCODEGEN_UI2C1_ADDR1_EN)
    /* Set UI2C1 Slave Addresses 1 */
    UI2C_SetSlaveAddr(UI2C1, 1, NUCODEGEN_UI2C1_ADDR1, NUCODEGEN_UI2C1_ADDR1_GC_SEL);
    UI2C_SetSlaveAddrMask(UI2C1, 1, NUCODEGEN_UI2C1_ADDRMSK1);
#endif

#if (NUCODEGEN_UI2C1_10BIT_FORMAT_EN)
    /* Enable I2C1 10-bit address mode */
    UI2C_ENABLE_10BIT_ADDR_MODE(UI2C1);
#endif /* NUCODEGEN_UI2C1_10BIT_FORMAT_EN */

#if NUCODEGEN_UI2C1_WAKEUP_EN
    UI2C_EnableWakeup(UI2C1, NUCODEGEN_UI2C1_WAKEUP_SEL);
#endif /* NUCODEGEN_UI2C1_WAKEUP_EN */

#if NUCODEGEN_UI2C1_TIMEOUT_EN
    UI2C_EnableTimeout(UI2C1, NUCODEGEN_UI2C1_TIMEOUT_CNT);
#endif /* NUCODEGEN_UI2C1_TIMEOUT_EN */

#if NUCODEGEN_UI2C1_INT_EN
    /* Enable UI2C1 protocol interrupt */
    UI2C_ENABLE_PROT_INT(UI2C1, (UI2C_PROTIEN_ACKIEN_Msk | UI2C_PROTIEN_NACKIEN_Msk | UI2C_PROTIEN_STORIEN_Msk | UI2C_PROTIEN_STARIEN_Msk));
    NVIC_EnableIRQ(USCI1_IRQn);
#endif /* NUCODEGEN_UI2C1_INT_EN */

}
#endif /*NUCODEGEN_USCI1_I2C*/

#if (NUCODEGEN_USCI2_I2C)
void USCI2_I2C_Init()
{
    /* Open USCI_I2C2 and set clock*/
    UI2C_Open(UI2C2, NUCODEGEN_UI2C2_CLOCK);

#if (NUCODEGEN_UI2C2_ADDR0_EN)
    /* Set UI2C2 Slave Addresses 0 */
    UI2C_SetSlaveAddr(UI2C2, 0, NUCODEGEN_UI2C2_ADDR0, NUCODEGEN_UI2C2_ADDR0_GC_SEL);
    UI2C_SetSlaveAddrMask(UI2C2, 0, NUCODEGEN_UI2C2_ADDRMSK0);
#endif

#if (NUCODEGEN_UI2C2_ADDR1_EN)
    /* Set UI2C2 Slave Addresses 1 */
    UI2C_SetSlaveAddr(UI2C2, 1, NUCODEGEN_UI2C2_ADDR1, NUCODEGEN_UI2C2_ADDR1_GC_SEL);
    UI2C_SetSlaveAddrMask(UI2C2, 1, NUCODEGEN_UI2C2_ADDRMSK1);
#endif

#if (NUCODEGEN_UI2C2_10BIT_FORMAT_EN)
    /* Enable I2C2 10-bit address mode */
    UI2C_ENABLE_10BIT_ADDR_MODE(UI2C2);
#endif /* NUCODEGEN_UI2C2_10BIT_FORMAT_EN */

#if NUCODEGEN_UI2C2_WAKEUP_EN
    UI2C_EnableWakeup(UI2C2, NUCODEGEN_UI2C2_WAKEUP_SEL);
#endif /* NUCODEGEN_UI2C2_WAKEUP_EN */

#if NUCODEGEN_UI2C2_TIMEOUT_EN
    UI2C_EnableTimeout(UI2C2, NUCODEGEN_UI2C2_TIMEOUT_CNT);
#endif /* NUCODEGEN_UI2C2_TIMEOUT_EN */

#if NUCODEGEN_UI2C2_INT_EN
    /* Enable UI2C2 protocol interrupt */
    UI2C_ENABLE_PROT_INT(UI2C2, (UI2C_PROTIEN_ACKIEN_Msk | UI2C_PROTIEN_NACKIEN_Msk | UI2C_PROTIEN_STORIEN_Msk | UI2C_PROTIEN_STARIEN_Msk));
    NVIC_EnableIRQ(USCI2_IRQn);
#endif /* NUCODEGEN_UI2C2_INT_EN */

}
#endif /*NUCODEGEN_USCI2_I2C*/


#if (NUCODEGEN_USCI0_UART)
void USCI0_UART_Init(void)
{
    /* Open UUART and configure baudrate settings. */
    UUART_Open(UUART0, UUART0_BAUDRATE);

    /* Set UUART line configuration */
    UUART_SetLine_Config(UUART0, 0, NUCODEGEN_UUART0_WORD_LEN, NUCODEGEN_UUART0_PARITY_BIT, NUCODEGEN_UUART0_STOP_BIT);

#if (NUCODEGEN_UUART0_ABR_ENABLE)
    /* Configure auto-baudrate settings. CLKDIV shall be equal to DSCNT when auto-baudrate function is eanbled.
     * Enable timing measurement counter and set the counter source to f_DIV_CLK */
    UUART0->BRGEN = ((UUART0_ABR_BRGEN_CLKDIV << UUART_BRGEN_CLKDIV_Pos) |
                     (UUART0_ABR_BRGEN_DSCNT << UUART_BRGEN_DSCNT_Pos) |
                     (UUART_BRGEN_TMCNTEN_Msk) | (UUART_BRGEN_TMCNTSRC_Msk));

    /* Enable auto baud rate detect function */
    UUART0->PROTCTL |= UUART_PROTCTL_ABREN_Msk;
#endif

#if (NUCODEGEN_UUART0_FUNC_SEL == NUCODEGEN_UUART0_FUNC_UART)
#if (NUCODEGEN_UUART0_FLOW_CTRL_ENABLE)
    /* Enable Flow Control */
    UUART_EnableFlowCtrl(UUART0);
#else
    /* Disable Flow Control */
    UUART_DisableFlowCtrl(UUART0);
#endif /* NUCODEGEN_UUART0_FLOW_CTRL_ENABLE */
#endif /* NUCODEGN_UUART0_FUNC_SEL == NUCODEGEN_UUART0_FUNC_UART*/

#if (NUCODEGEN_UUART0_FUNC_SEL == NUCODEGEN_UUART0_FUNC_RS485)
    /* Configure RS485 Mode. Set UART line configuration and control signal output inverse */
    UUART0->LINECTL |= UUART_LINECTL_CTLOINV_Msk;

    /* Enable RTS auto direction function for RS485 mode. */
    UUART0->PROTCTL |= UUART_PROTCTL_RTSAUDIREN_Msk;
#endif /* NUCODEGN_UUART0_FUNC_SEL == NUCODEGEN_UUART0_FUNC_RS485 */

#if (NUCODEGEN_UUART0_INT_ENABLE)
    /* Enable UUART Interrupt Function */
    UUART_EnableInt(UUART0, UUART0_INT_CONFIG);

#if NUCODEGEN_UUART0_WKEN_ENABLE
    /* Enable UUART Wakeup Function */
    UUART_EnableWakeup(UUART0, NUCODEGEN_UUART0_WAKEUP_CONFIG);
#endif

    /* NVIC Enable USCI0 Interrupt */
    NVIC_EnableIRQ(USCI0_IRQn);
#endif /* NUCODEGEN_UUART0_NVIC_ENALBE */

#if NUCODEGEN_UUART0_PDMA_ENABLE
    /* Configure UUART0 PDMA Function */
    UUART0->PDMACTL = NUCODEGEN_UUART0_PDMA_CONFIG;
#endif
}
#endif /* NUCODEGEN_USCI0_UART*/

#if (NUCODEGEN_USCI1_UART)
void USCI1_UART_Init(void)
{
    /* Open UUART and configure baudrate settings. */
    UUART_Open(UUART1, UUART1_BAUDRATE);

    /* Set UUART line configuration */
    UUART_SetLine_Config(UUART1, 0, NUCODEGEN_UUART1_WORD_LEN, NUCODEGEN_UUART1_PARITY_BIT, NUCODEGEN_UUART1_STOP_BIT);

#if (NUCODEGEN_UUART1_ABR_ENABLE)
    /* Configure auto-baudrate settings. CLKDIV shall be equal to DSCNT when auto-baudrate function is eanbled.
     * Enable timing measurement counter and set the counter source to f_DIV_CLK */
    UUART1->BRGEN = ((UUART1_ABR_BRGEN_CLKDIV << UUART_BRGEN_CLKDIV_Pos) |
                     (UUART1_ABR_BRGEN_DSCNT << UUART_BRGEN_DSCNT_Pos) |
                     (UUART_BRGEN_TMCNTEN_Msk) | (UUART_BRGEN_TMCNTSRC_Msk));

    /* Enable auto baud rate detect function */
    UUART1->PROTCTL |= UUART_PROTCTL_ABREN_Msk;
#endif

#if (NUCODEGEN_UUART1_FUNC_SEL == NUCODEGEN_UUART1_FUNC_UART)
#if (NUCODEGEN_UUART1_FLOW_CTRL_ENABLE)
    /* Enable Flow Control */
    UUART_EnableFlowCtrl(UUART1);
#else
    /* Disable Flow Control */
    UUART_DisableFlowCtrl(UUART1);
#endif /* NUCODEGEN_UUART1_FLOW_CTRL_ENABLE */
#endif /* NUCODEGN_UUART1_FUNC_SEL == NUCODEGEN_UUART1_FUNC_UART*/

#if (NUCODEGEN_UUART1_FUNC_SEL == NUCODEGEN_UUART1_FUNC_RS485)
    /* Configure RS485 Mode. Set UART line configuration and control signal output inverse */
    UUART1->LINECTL |= UUART_LINECTL_CTLOINV_Msk;

    /* Enable RTS auto direction function for RS485 mode. */
    UUART1->PROTCTL |= UUART_PROTCTL_RTSAUDIREN_Msk;
#endif /* NUCODEGN_UUART1_FUNC_SEL == NUCODEGEN_UUART1_FUNC_RS485 */

#if (NUCODEGEN_UUART1_INT_ENABLE)
    /* Enable UUART Interrupt Function */
    UUART_EnableInt(UUART1, UUART1_INT_CONFIG);

#if NUCODEGEN_UUART1_WKEN_ENABLE
    /* Enable UUART Wakeup Function */
    UUART_EnableWakeup(UUART1, NUCODEGEN_UUART1_WAKEUP_CONFIG);
#endif
    /* NVIC Enable USCI0 Interrupt */
    NVIC_EnableIRQ(USCI1_IRQn);
#endif /* NUCODEGEN_UUART1_NVIC_ENALBE */

#if NUCODEGEN_UUART1_PDMA_ENABLE
    /* Configure UUART1 PDMA Function */
    UUART1->PDMACTL = NUCODEGEN_UUART1_PDMA_CONFIG;
#endif
}
#endif /* NUCODEGEN_USCI1_UART*/

#if (NUCODEGEN_USCI2_UART)
void USCI2_UART_Init(void)
{
    /* Open UUART and configure baudrate settings. */
    UUART_Open(UUART2, UUART2_BAUDRATE);

    /* Set UUART line configuration */
    UUART_SetLine_Config(UUART2, 0, NUCODEGEN_UUART2_WORD_LEN, NUCODEGEN_UUART2_PARITY_BIT, NUCODEGEN_UUART2_STOP_BIT);

#if (NUCODEGEN_UUART2_ABR_ENABLE)
    /* Configure auto-baudrate settings. CLKDIV shall be equal to DSCNT when auto-baudrate function is eanbled.
     * Enable timing measurement counter and set the counter source to f_DIV_CLK */
    UUART2->BRGEN = ((UUART2_ABR_BRGEN_CLKDIV << UUART_BRGEN_CLKDIV_Pos) |
                     (UUART2_ABR_BRGEN_DSCNT << UUART_BRGEN_DSCNT_Pos) |
                     (UUART_BRGEN_TMCNTEN_Msk) | (UUART_BRGEN_TMCNTSRC_Msk));

    /* Enable auto baud rate detect function */
    UUART2->PROTCTL |= UUART_PROTCTL_ABREN_Msk;
#endif

#if (NUCODEGEN_UUART2_FUNC_SEL == NUCODEGEN_UUART2_FUNC_UART)
#if (NUCODEGEN_UUART2_FLOW_CTRL_ENABLE)
    /* Enable Flow Control */
    UUART_EnableFlowCtrl(UUART2);
#else
    /* Disable Flow Control */
    UUART_DisableFlowCtrl(UUART2);
#endif /* NUCODEGEN_UUART2_FLOW_CTRL_ENABLE */
#endif /* NUCODEGN_UUART2_FUNC_SEL == NUCODEGEN_UUART2_FUNC_UART*/

#if (NUCODEGEN_UUART2_FUNC_SEL == NUCODEGEN_UUART2_FUNC_RS485)
    /* Configure RS485 Mode. Set UART line configuration and control signal output inverse */
    UUART2->LINECTL |= UUART_LINECTL_CTLOINV_Msk;

    /* Enable RTS auto direction function for RS485 mode. */
    UUART2->PROTCTL |= UUART_PROTCTL_RTSAUDIREN_Msk;
#endif /* NUCODEGN_UUART2_FUNC_SEL == NUCODEGEN_UUART2_FUNC_RS485 */

#if (NUCODEGEN_UUART2_INT_ENABLE)
    /* Enable UUART Interrupt Function */
    UUART_EnableInt(UUART2, UUART2_INT_CONFIG);

#if NUCODEGEN_UUART2_WKEN_ENABLE
    /* Enable UUART Wakeup Function */
    UUART_EnableWakeup(UUART2, NUCODEGEN_UUART2_WAKEUP_CONFIG);

#endif
    /* NVIC Enable USCI2 Interrupt */
    NVIC_EnableIRQ(USCI2_IRQn);
#endif /* NUCODEGEN_UUART2_NVIC_ENALBE */


#if NUCODEGEN_UUART2_PDMA_ENABLE
    /* Configure UUART2 PDMA Function */
    UUART2->PDMACTL = NUCODEGEN_UUART2_PDMA_CONFIG;
#endif

}
#endif /* NUCODEGEN_USCI1_UART*/


#if (NUCODEGEN_USCI0_SPI)
void USCI0_SPI_Init(void)
{
    /* Init USCI_SPI0 */
    USPI_Open(USPI0, NUCODEGEN_USPI0_MASTER_SLAVE, NUCODEGEN_USPI0_TIME_MODE,  NUCODEGEN_USPI0_DATAWIDTH, NUCODEGEN_USPI0_BUSCLOCK);


#if (NUCODEGEN_USPI0_HALF_DUPLEX_EN)

    /* Enable half- duplex function */
    USPI0->PROTCTL = (USPI0->PROTCTL & ~USPI_PROTCTL_TSMSEL_Msk) | (0x4<<USPI_PROTCTL_TSMSEL_Pos);

#if (NUCODEGEN_USPI0_DATA_DIR)

    /* Set data direction as output */
    USPI0->TXDAT = USPI0->TXDAT & ~USPI_TXDAT_PORTDIR_Msk ;

#else

    /* Set data direction as input */
    USPI0->TXDAT = USPI0->TXDAT | USPI_TXDAT_PORTDIR_Msk ;

#endif /* NUCODEGEN_USPI0_DATA_DIR */

#endif /* NUCODEGEN_USPI0_HALF_DUPLEX_EN */

#if (NUCODEGEN_USPI0_AUTOSS_EN)

    /* Enable auto SS function */
    USPI_EnableAutoSS(USPI0, 0, NUCODEGEN_USPI0_MASTER_SS_LEVEL);

    /* Enable SS function */
    USPI0->PROTCTL |= USPI_PROTCTL_SS_Msk;

#endif /* NUCODEGEN_USPI_AUTOSS_EN */

#if (NUCODEGEN_USPI0_SS_EN)

    /* Enable SS function */
    USPI0->PROTCTL |= USPI_PROTCTL_SS_Msk;

#endif /* NUCODEGEN_USPI_SS_EN */

#if (NUCODEGEN_USPI0_3WIRE_EN)

    /* Enable 3 wire mode */
    USPI_ENABLE_3WIRE_MODE(USPI0);

#endif /* NUCODEGEN_USPI_3WIRE_EN */

    /* Master SS active level */
    USPI0->LINECTL = (USPI0->LINECTL & ~USPI_LINECTL_CTLOINV_Msk) | NUCODEGEN_USPI0_MASTER_SS_LEVEL;

    /* Slave SS active level */
    USPI0->CTLIN0 = ( USPI0->CTLIN0 & ~USPI_CTLIN0_ININV_Msk) | NUCODEGEN_USPI0_SLAVE_SS_LEVEL;

#if (NUCODEGEN_USPI0_ORDER)
    /* Set transfer sequence as MSB */
    USPI_SET_MSB_FIRST(USPI0);
#else
    /* Set transfer sequence as LSB */
    USPI_SET_LSB_FIRST(USPI0);
#endif /* NUCODEGEN_USPI_ORDER */

#if (NUCODEGEN_USPI0_TX_PDMA_EN)
    /* Enable TX PDMA function */
    USPI_TRIGGER_TX_PDMA(USPI0);
#endif /* NUCODEGEN_USPI_TX_PDMA_EN */

#if (NUCODEGEN_USPI0_RX_PDMA_EN)
    /* Enable RX PDMA function */
    USPI_TRIGGER_RX_PDMA(USPI0);
#endif /* NUCODEGEN_USPI_RX_PDMA_EN */

#if (NUCODEGEN_USPI0_WAKE_UP_EN)
    /* Enable wake up function */
    USPI_EnableWakeup(USPI0);
#endif /* NUCODEGEN_USPI_WAKE_UP_EN */

#if (NUCODEGEN_USPI0_INT_EN)
    /* Enable USPI Interrupt Function */
    USPI_EnableInt(USPI0, NUCODEGEN_USPI0_INT_SEL);

    /* Enable USCI0 NVIC */
    NVIC_EnableIRQ(USCI0_IRQn);
#endif /* NUCODEGEN_USPI0_INT_EN */
}
#endif /* NUCODEGEN_USCI0_SPI*/

#if (NUCODEGEN_USCI1_SPI)
void USCI1_SPI_Init(void)
{

    /* Init USCI_SPI0 */
    USPI_Open(USPI1, NUCODEGEN_USPI1_MASTER_SLAVE, NUCODEGEN_USPI1_TIME_MODE,  NUCODEGEN_USPI1_DATAWIDTH, NUCODEGEN_USPI1_BUSCLOCK);


#if (NUCODEGEN_USPI1_HALF_DUPLEX_EN)

    /* Enable half- duplex function */
    USPI1->PROTCTL = (USPI1->PROTCTL & ~USPI_PROTCTL_TSMSEL_Msk) | (0x4<<USPI_PROTCTL_TSMSEL_Pos);

#if (NUCODEGEN_USPI1_DATA_DIR)

    /* Set data direction as output */
    USPI1->TXDAT = USPI1->TXDAT & ~USPI_TXDAT_PORTDIR_Msk ;

#else

    /* Set data direction as input */
    USPI1->TXDAT = USPI1->TXDAT | USPI_TXDAT_PORTDIR_Msk ;

#endif /* NUCODEGEN_USPI1_DATA_DIR */

#endif /* NUCODEGEN_USPI1_HALF_DUPLEX_EN */

#if (NUCODEGEN_USPI1_AUTOSS_EN)

    /* Enable auto SS function */
    USPI_EnableAutoSS(USPI1, 0, NUCODEGEN_USPI1_MASTER_SS_LEVEL);

    /* Enable SS function */
    USPI1->PROTCTL |= USPI_PROTCTL_SS_Msk;

#endif /* NUCODEGEN_USPI_AUTOSS_EN */

#if (NUCODEGEN_USPI1_SS_EN)

    /* Enable SS function */
    USPI1->PROTCTL |= USPI_PROTCTL_SS_Msk;

#endif /* NUCODEGEN_USPI_SS_EN */

#if (NUCODEGEN_USPI1_3WIRE_EN)

    /* Enable 3 wire mode */
    USPI_ENABLE_3WIRE_MODE(USPI1);

#endif /* NUCODEGEN_USPI_3WIRE_EN */

    /* Master SS active level */
    USPI1->LINECTL = (USPI1->LINECTL & ~USPI_LINECTL_CTLOINV_Msk) | NUCODEGEN_USPI1_MASTER_SS_LEVEL;

    /* Slave SS active level */
    USPI1->CTLIN0 = (USPI1->CTLIN0 & ~USPI_CTLIN0_ININV_Msk) | NUCODEGEN_USPI1_SLAVE_SS_LEVEL;

#if (NUCODEGEN_USPI1_ORDER)

    /* Set transfer sequence as MSB */
    USPI_SET_MSB_FIRST(USPI1);

#else

    /* Set transfer sequence as LSB */
    USPI_SET_LSB_FIRST(USPI1);

#endif /* NUCODEGEN_USPI_ORDER */

#if (NUCODEGEN_USPI1_TX_PDMA_EN)

    /* Enable TX PDMA function */
    USPI_TRIGGER_TX_PDMA(USPI1);

#endif /* NUCODEGEN_USPI_TX_PDMA_EN */

#if (NUCODEGEN_USPI1_RX_PDMA_EN)

    /* Enable RX PDMA function */
    USPI_TRIGGER_RX_PDMA(USPI1);

#endif /* NUCODEGEN_USPI_RX_PDMA_EN */

#if (NUCODEGEN_USPI1_WAKE_UP_EN)

    /* Enable wake up function */
    USPI_EnableWakeup(USPI1);

#endif /* NUCODEGEN_USPI_WAKE_UP_EN */

#if (NUCODEGEN_USPI1_INT_EN)

    /* Enable USPI Interrupt Function */
    USPI_EnableInt(USPI1, NUCODEGEN_USPI1_INT_SEL);

    /* Enable USCI1 NVIC */
    NVIC_EnableIRQ(USCI1_IRQn);

#endif /* NUCODEGEN_USPI1_INT_EN */
}
#endif /* NUCODEGEN_USCI1_SPI*/

#if (NUCODEGEN_USCI2_SPI)
void USCI2_SPI_Init(void)
{

    /* Init USCI_SPI0 */
    USPI_Open(USPI2, NUCODEGEN_USPI2_MASTER_SLAVE, NUCODEGEN_USPI2_TIME_MODE,  NUCODEGEN_USPI2_DATAWIDTH, NUCODEGEN_USPI2_BUSCLOCK);

#if (NUCODEGEN_USPI2_HALF_DUPLEX_EN)

    /* Enable half- duplex function */
    USPI2->PROTCTL = (USPI2->PROTCTL & ~USPI_PROTCTL_TSMSEL_Msk) | (0x4<<USPI_PROTCTL_TSMSEL_Pos);

#if (NUCODEGEN_USPI2_DATA_DIR)

    /* Set data direction as output */
    USPI2->TXDAT = USPI2->TXDAT & ~USPI_TXDAT_PORTDIR_Msk ;

#else

    /* Set data direction as input */
    USPI2->TXDAT = USPI2->TXDAT | USPI_TXDAT_PORTDIR_Msk ;

#endif /* NUCODEGEN_USPI2_DATA_DIR */

#endif /* NUCODEGEN_USPI2_HALF_DUPLEX_EN */

#if (NUCODEGEN_USPI2_AUTOSS_EN)

    /* Enable auto SS function */
    USPI_EnableAutoSS(USPI2, 0, NUCODEGEN_USPI2_MASTER_SS_LEVEL);

    /* Enable SS function */
    USPI2->PROTCTL |= USPI_PROTCTL_SS_Msk;

#endif /* NUCODEGEN_USPI_AUTOSS_EN */

#if (NUCODEGEN_USPI2_SS_EN)

    /* Enable SS function */
    USPI2->PROTCTL |= USPI_PROTCTL_SS_Msk;

#endif /* NUCODEGEN_USPI_SS_EN */

#if (NUCODEGEN_USPI2_3WIRE_EN)

    /* Enable 3 wire mode */
    USPI_ENABLE_3WIRE_MODE(USPI2);

#endif /* NUCODEGEN_USPI_3WIRE_EN */

    /* Master SS active level */
    USPI2->LINECTL = (USPI2->LINECTL & ~USPI_LINECTL_CTLOINV_Msk) | NUCODEGEN_USPI2_MASTER_SS_LEVEL;

    /* Slave SS active level */
    USPI2->CTLIN0 = (USPI2->CTLIN0 & ~USPI_CTLIN0_ININV_Msk) | NUCODEGEN_USPI2_SLAVE_SS_LEVEL;

#if (NUCODEGEN_USPI2_ORDER)

    /* Set transfer sequence as MSB */
    USPI_SET_MSB_FIRST(USPI2);

#else

    /* Set transfer sequence as LSB */
    USPI_SET_LSB_FIRST(USPI2);

#endif /* NUCODEGEN_USPI_ORDER */

#if (NUCODEGEN_USPI2_TX_PDMA_EN)

    /* Enable TX PDMA function */
    USPI_TRIGGER_TX_PDMA(USPI2);

#endif /* NUCODEGEN_USPI_TX_PDMA_EN */

#if (NUCODEGEN_USPI2_RX_PDMA_EN)

    /* Enable RX PDMA function */
    USPI_TRIGGER_RX_PDMA(USPI2);

#endif /* NUCODEGEN_USPI_RX_PDMA_EN */

#if (NUCODEGEN_USPI2_WAKE_UP_EN)

    /* Enable wake up function */
    USPI_EnableWakeup(USPI2);

#endif /* NUCODEGEN_USPI_WAKE_UP_EN */

#if (NUCODEGEN_USPI2_INT_EN)

    /* Enable USPI Interrupt Function */
    USPI_EnableInt(USPI2, NUCODEGEN_USPI2_INT_SEL);

    /* Enable USCI2 NVIC */
    NVIC_EnableIRQ(USCI2_IRQn);

#endif /* NUCODEGEN_USPI2_INT_EN */
}
#endif /* NUCODEGEN_USCI2_SPI*/

#if (NUCODEGEN_USBD)

void USBD_Init(void)
{

#if ( NUCODEGEN_CLASS_SEL==NUCODEGEN_CLASS_NONE )
    USBD_Open(NULL, NULL, NULL);
#endif /*NUCODEGEN_CLASS_SEL==NUCODEGEN_CLASS_NONE*/

#if (NUCODEGEN_CLASS_SEL==NUCODEGEN_CLASS_HID)
    USBD_Open(&gsInfo, HID_ClassRequest, NULL);

    /* Endpoint configuration */
    HID_Init();
#endif /*NUCODEGEN_CLASS_SEL==NUCODEGEN_CLASS_HID*/

#if ( NUCODEGEN_CLASS_SEL==NUCODEGEN_CLASS_MSC )
    USBD_Open(&gsInfo, MSC_ClassRequest, NULL);

    /* Endpoint configuration */
    MSC_Init();

    USBD_SetConfigCallback(MSC_SetConfig);
#endif /*NUCODEGEN_CLASS_SEL==NUCODEGEN_CLASS_MSC*/


#if NUCODEGEN_USB_INT_EN
    NVIC_EnableIRQ(USBD_IRQn);
#endif
}
#endif

#if (NUCODEGEN_SC0)
void SC0_Init(void)
{
#if (NUCODEGEN_SC0_SUBMODE_SEL==NUCODEGEN_SC0_SUBMODE_SC)
    /*
        Open smartcard interface 0. CD pin state low indicates card insert and PWR pin low raise VCC pin to card
        The second and third parameter needs to be set according to the board design
    */
    SC_Open(SC0, NUCODEGEN_SC0_PIN_STATE_CARDDETECT, NUCODEGEN_SC0_PIN_STATE_PWR);
    NVIC_EnableIRQ(SC0_IRQn);
#endif /*NUCODEGEN_SC0_SUBMODE_SEL==NUCODEGEN_SC0_SUBMODE_SC*/

#if (NUCODEGEN_SC0_SUBMODE_SEL == NUCODEGEN_SC0_SUBMODE_SCUART)
    // Open smartcard interface 0 in UART mode. The line config will be 115200-8n1
    // Can call SCUART_SetLineConfig() later if necessary
    SCUART_Open(SC0, NUCODEGEN_SC0_UART_BAUDRATE);

#if (NUCODEGEN_SC0_INT_EN)
    SCUART_ENABLE_INT(SC0, NUCODEGEN_SCUART0_INTSEL);
#endif /*NUCODEGEN_SC0_INT_EN*/

#if (NUCODEGEN_SC0_INT_EN)
    NVIC_EnableIRQ(SC0_IRQn);
#endif /*NUCODEGEN_SC0_INT_EN*/

#endif /*NUCODEGEN_SC0_SUBMODE_SEL == NUCODEGEN_SC0_SUBMODE_SCUART*/



}
#endif /*NUCODEGEN_SC0*/


#if ((NUCODEGEN_BPWM0) || (NUCODEGEN_BPWM1))

void BPWM_SetMaskOutput(BPWM_T *bpwm, uint32_t u32ChannelNum, uint32_t u32LevelMask)
{
    (bpwm)->MSKEN |= 0x1<<u32ChannelNum;
    (bpwm)->MSK |= (u32LevelMask<<u32ChannelNum);
}

#endif

#if (NUCODEGEN_BPWM0)
void BPWM0_Init()
{

#if (NUCODEGEN_BPWM0_FUNC_SEL==0)

#if (NUCODEGEN_BPWM0_OUTPUT_FUNC_SETMODE==0)

#if NUCODEGEN_BPWM0_CH0_ENABLE

    /* Set BPWM0 channel 0 configuration */
    BPWM_ConfigOutputChannel(BPWM0, 0, NUCODEGEN_BPWM0_FREQ, NUCODEGEN_BPWM0_CH0_DUTY);

    /* Enable output of BPWM0 channel 0 */
    BPWM_EnableOutput(BPWM0, BPWM_CH_0_MASK);

#endif /*NUCODEGEN_BPWM0_CH0_ENABLE*/

#if NUCODEGEN_BPWM0_CH1_ENABLE

    /* Set BPWM0 channel 1 configuration */
    BPWM_ConfigOutputChannel(BPWM0, 1, NUCODEGEN_BPWM0_FREQ, NUCODEGEN_BPWM0_CH1_DUTY);

    /* Enable output of BPWM0 channel 1 */
    BPWM_EnableOutput(BPWM0, BPWM_CH_1_MASK);

#endif /*NUCODEGEN_BPWM0_CH1_ENABLE*/

#if NUCODEGEN_BPWM0_CH2_ENABLE
    /* Set BPWM0 channel 2 configuration */
    BPWM_ConfigOutputChannel(BPWM0, 2, NUCODEGEN_BPWM0_FREQ, NUCODEGEN_BPWM0_CH2_DUTY);
    /* Enable output of BPWM0 channel 2 */
    BPWM_EnableOutput(BPWM0, BPWM_CH_2_MASK);

#endif /*NUCODEGEN_BPWM0_CH2_ENABLE*/

#if NUCODEGEN_BPWM0_CH3_ENABLE
    /* Set BPWM0 channel 3 configuration */
    BPWM_ConfigOutputChannel(BPWM0, 3, NUCODEGEN_BPWM0_FREQ, NUCODEGEN_BPWM0_CH3_DUTY);
    /* Enable output of BPWM0 channel 3 */
    BPWM_EnableOutput(BPWM0, BPWM_CH_3_MASK);

#endif /*NUCODEGEN_BPWM0_CH3_ENABLE*/

#if NUCODEGEN_BPWM0_CH4_ENABLE
    /* Set BPWM0 channel 4 configuration */
    BPWM_ConfigOutputChannel(BPWM0, 4, NUCODEGEN_BPWM0_FREQ, NUCODEGEN_BPWM0_CH4_DUTY);
    /* Enable output of BPWM0 channel 4 */
    BPWM_EnableOutput(BPWM0, BPWM_CH_4_MASK);


#endif /*NUCODEGEN_BPWM0_CH4_ENABLE*/

#if NUCODEGEN_BPWM0_CH5_ENABLE

    /* Set BPWM0 channel 5 configuration */
    BPWM_ConfigOutputChannel(BPWM0, 5, NUCODEGEN_BPWM0_FREQ, NUCODEGEN_BPWM0_CH5_DUTY);

    /* Enable output of BPWM0 channel 5 */
    BPWM_EnableOutput(BPWM0, BPWM_CH_5_MASK);

#endif /*NUCODEGEN_BPWM0_CH5_ENABLE*/

#else

    /* Set BPWM0 clock source */
    BPWM_SetClockSource(BPWM0, 0, NUCODEGEN_BPWM0_CLKSRC);

    /* Set BPWM0 counter behavior type */
    BPWM_SET_ALIGNED_TYPE(BPWM0, BPWM_CH_0_MASK, NUCODEGEN_BPWM0_CNTTYPE);

    /* Set the prescaler of BPWM0  */
    BPWM_SET_PRESCALER(BPWM0, 0,NUCODEGEN_BPWM0_PRESCALER);

    /* Set the period of BPWM0 */
    BPWM_SET_CNR(BPWM0, 0, NUCODEGEN_BPWM0_PERIOD);

#if NUCODEGEN_BPWM0_SYNCSTART_ENABLE

    /* Enable timer synchronous start counting function */
    BPWM_ENABLE_TIMER_SYNC(BPWM0, BIT0, NUCODEGEN_BPWM0_SYNCSTART_SRC) ;

#endif /*NUCODEGEN_BPWM0_SYNCSTART_ENABLE*/

#if (((NUCODEGEN_BPWM0_CH0_INT_SEL) & 1)||((NUCODEGEN_BPWM0_CH1_INT_SEL) & 1)||((NUCODEGEN_BPWM0_CH2_INT_SEL) & 1)||((NUCODEGEN_BPWM0_CH3_INT_SEL) & 1)||((NUCODEGEN_BPWM0_CH4_INT_SEL) & 1)||((NUCODEGEN_BPWM0_CH5_INT_SEL) & 1))

    /* Enable zero interrupt - BPWM0 has only one controller  */
    BPWM_EnableZeroInt(BPWM0, 0) ;

#endif

#if (((NUCODEGEN_BPWM0_CH0_INT_SEL) & 2)||((NUCODEGEN_BPWM0_CH1_INT_SEL) & 2)||((NUCODEGEN_BPWM0_CH2_INT_SEL) & 2)||((NUCODEGEN_BPWM0_CH3_INT_SEL) & 2)||((NUCODEGEN_BPWM0_CH4_INT_SEL) & 2)||((NUCODEGEN_BPWM0_CH5_INT_SEL) & 2))

    /* Enable period interrupt - BPWM0 has only one controller  */
    BPWM_EnablePeriodInt(BPWM0, 0, 0) ;

#endif

#if NUCODEGEN_BPWM0_CH0_ENABLE

    /* Set the duty of BPWM0 CH0*/
    BPWM_SET_CMR(BPWM0, 0, NUCODEGEN_BPWM0_CH0_CMPDATA);

    /* Set output level of BPWM0 CH0*/
    BPWM_SET_OUTPUT_LEVEL(BPWM0, BIT0, NUCODEGEN_BPWM0_CH0_WAVEOUT_ZERO, NUCODEGEN_BPWM0_CH0_WAVEOUT_CMPUP, NUCODEGEN_BPWM0_CH0_WAVEOUT_PERIOD, NUCODEGEN_BPWM0_CH0_WAVEOUT_CMPDOWN);

    /* Enable output of BPWM0 channel 0 */
    BPWM_EnableOutput(BPWM0, BPWM_CH_0_MASK);

#if NUCODEGEN_BPWM0_CH0_ADVANCED

#if (NUCODEGEN_BPWM0_CH0_LOAD_MODE == 0)

    /* Period loading mode*/
    BPWM_DisableLoadMode(BPWM0, 0, BPWM_LOAD_MODE_IMMEDIATE|BPWM_LOAD_MODE_CENTER) ;

#elif (NUCODEGEN_BPWM0_CH0_LOAD_MODE == 1)

    /*Immediate loading mode*/
    BPWM_EnableLoadMode(BPWM0, 0, BPWM_LOAD_MODE_IMMEDIATE) ;

#elif (NUCODEGEN_BPWM0_CH0_LOAD_MODE == 2)

    /*Center loading mode*/
    BPWM_EnableLoadMode(BPWM0, 0, BPWM_LOAD_MODE_CENTER) ;

#endif /*NUCODEGEN_BPWM0_CH0_LOAD_MODE*/

#if (NUCODEGEN_BPWM0_CH0_OTHER_OUTPUT==1)

    /* Enable mask output and output high or low*/
    BPWM_SetMaskOutput(BPWM0, 0, NUCODEGEN_BPWM0_CH0_MASK_DATA);

#elif (NUCODEGEN_BPWM0_CH0_OTHER_OUTPUT==2)

    /* Enable inverter output */
    BPWM0->POLCTL |= BPWM_CH_0_MASK ;

#endif /*NUCODEGEN_BPWM0_CH0_OTHER_OUTPUT*/

#if NUCODEGEN_BPWM0_CH0_TRIGER_EADC_ENABLE

    /* Set trigger ADC and trigger source*/
    BPWM_EnableADCTrigger(BPWM0, 0, NUCODEGEN_BPWM0_CH0_TRIGER_EADCSRC) ;

#endif /*NUCODEGEN_BPWM0_CH0_TRIGER_EADC_ENABLE*/

#if ((NUCODEGEN_BPWM0_CH0_INT_SEL) & 4)

    /* Enable duty interrupt - count up interrupt */
    BPWM_EnableDutyInt(BPWM0, 0, BPWM_DUTY_INT_UP_COUNT_MATCH_CMP) ;

#endif /*(NUCODEGEN_BPWM0_CH0_INT_SEL)*/

#if ((NUCODEGEN_BPWM0_CH0_INT_SEL) & 8)

    /* Enable duty interrupt - count down interrupt */
    BPWM_EnableDutyInt(BPWM0, 0, BPWM_DUTY_INT_DOWN_COUNT_MATCH_CMP) ;

#endif /*NUCODEGEN_BPWM0_CH0_INT_SEL*/

#endif /*NUCODEGEN_BPWM0_CH0_ADVANCED*/

#endif /*NUCODEGEN_BPWM0_CH0_ENABLE*/

#if NUCODEGEN_BPWM0_CH1_ENABLE

    /* Set the duty of BPWM0 CH1*/
    BPWM_SET_CMR(BPWM0, 1, NUCODEGEN_BPWM0_CH1_CMPDATA);

    /* Set output level of BPWM0 CH1*/
    BPWM_SET_OUTPUT_LEVEL(BPWM0, BIT1, NUCODEGEN_BPWM0_CH1_WAVEOUT_ZERO, NUCODEGEN_BPWM0_CH1_WAVEOUT_CMPUP, NUCODEGEN_BPWM0_CH1_WAVEOUT_PERIOD, NUCODEGEN_BPWM0_CH1_WAVEOUT_CMPDOWN);

    /* Enable output of BPWM0 channel 1 */
    BPWM_EnableOutput(BPWM0, BPWM_CH_1_MASK);

#if NUCODEGEN_BPWM0_CH1_ADVANCED

#if (NUCODEGEN_BPWM0_CH1_LOAD_MODE == 0)

    /* Period loading mode*/
    BPWM_DisableLoadMode(BPWM0, 1, BPWM_LOAD_MODE_IMMEDIATE|BPWM_LOAD_MODE_CENTER) ;

#elif (NUCODEGEN_BPWM0_CH1_LOAD_MODE == 1)

    /*Immediate loading mode*/
    BPWM_EnableLoadMode(BPWM0, 1, BPWM_LOAD_MODE_IMMEDIATE) ;

#elif (NUCODEGEN_BPWM0_CH1_LOAD_MODE == 2)

    /*Center loading mode*/
    BPWM_EnableLoadMode(BPWM0, 1, BPWM_LOAD_MODE_CENTER) ;

#endif /*NUCODEGEN_BPWM0_CH1_LOAD_MODE*/

#if (NUCODEGEN_BPWM0_CH1_OTHER_OUTPUT==1)

    /* Enable mask output and output high or low*/
    BPWM_SetMaskOutput(BPWM0, 1, NUCODEGEN_BPWM0_CH1_MASK_DATA);

#elif (NUCODEGEN_BPWM0_CH1_OTHER_OUTPUT==2)

    /* Enable inverter output */
    BPWM0->POLCTL |= BPWM_CH_1_MASK ;

#endif /*NUCODEGEN_BPWM0_CH1_OTHER_OUTPUT*/

#if NUCODEGEN_BPWM0_CH1_TRIGER_EADC_ENABLE

    /* Set trigger ADC and trigger source*/
    BPWM_EnableADCTrigger(BPWM0, 1, NUCODEGEN_BPWM0_CH1_TRIGER_EADCSRC) ;

#endif /*NUCODEGEN_BPWM0_CH1_TRIGER_EADC_ENABLE*/

#if ((NUCODEGEN_BPWM0_CH1_INT_SEL) & 4)

    /* Enable duty interrupt - count up interrupt */
    BPWM_EnableDutyInt(BPWM0, 1, BPWM_DUTY_INT_UP_COUNT_MATCH_CMP) ;

#endif /*NUCODEGEN_BPWM0_CH1_INT_SEL*/

#if ((NUCODEGEN_BPWM0_CH1_INT_SEL) & 8)

    /* Enable duty interrupt - count down interrupt */
    BPWM_EnableDutyInt(BPWM0, 1, BPWM_DUTY_INT_DOWN_COUNT_MATCH_CMP) ;

#endif /*NUCODEGEN_BPWM0_CH1_INT_SEL*/

#endif /*NUCODEGEN_BPWM0_CH1_ADVANCED*/

#endif /*NUCODEGEN_BPWM0_CH1_ENABLE*/

#if NUCODEGEN_BPWM0_CH2_ENABLE

    /* Set the duty of BPWM0 CH2*/
    BPWM_SET_CMR(BPWM0, 2, NUCODEGEN_BPWM0_CH2_CMPDATA);

    /* Set output level of BPWM0 CH2*/
    BPWM_SET_OUTPUT_LEVEL(BPWM0, BIT2, NUCODEGEN_BPWM0_CH2_WAVEOUT_ZERO, NUCODEGEN_BPWM0_CH2_WAVEOUT_CMPUP, NUCODEGEN_BPWM0_CH2_WAVEOUT_PERIOD, NUCODEGEN_BPWM0_CH2_WAVEOUT_CMPDOWN);

    /* Enable output of BPWM0 channel 2 */
    BPWM_EnableOutput(BPWM0, BPWM_CH_2_MASK);

#if NUCODEGEN_BPWM0_CH2_ADVANCED

#if (NUCODEGEN_BPWM0_CH2_LOAD_MODE == 0)

    /* Period loading mode*/
    BPWM_DisableLoadMode(BPWM0, 2, BPWM_LOAD_MODE_IMMEDIATE|BPWM_LOAD_MODE_CENTER) ;

#elif (NUCODEGEN_BPWM0_CH2_LOAD_MODE == 1)

    /*Immediate loading mode*/
    BPWM_EnableLoadMode(BPWM0, 2, BPWM_LOAD_MODE_IMMEDIATE) ;

#elif (NUCODEGEN_BPWM0_CH2_LOAD_MODE == 2)

    /*Center loading mode*/
    BPWM_EnableLoadMode(BPWM0, 2, BPWM_LOAD_MODE_CENTER) ;

#endif /*NUCODEGEN_BPWM0_CH2_LOAD_MODE*/

#if (NUCODEGEN_BPWM0_CH2_OTHER_OUTPUT==1)

    /* Enable mask output and output high or low*/
    BPWM_SetMaskOutput(BPWM0, 2, NUCODEGEN_BPWM0_CH2_MASK_DATA);

#elif (NUCODEGEN_BPWM0_CH2_OTHER_OUTPUT==2)

    /* Enable inverter output */
    BPWM0->POLCTL |= BPWM_CH_2_MASK ;

#endif /*NUCODEGEN_BPWM0_CH2_OTHER_OUTPUT*/

#if NUCODEGEN_BPWM0_CH2_TRIGER_EADC_ENABLE

    /* Set trigger ADC and trigger source*/
    BPWM_EnableADCTrigger(BPWM0, 2, NUCODEGEN_BPWM0_CH2_TRIGER_EADCSRC) ;

#endif /*NUCODEGEN_BPWM0_CH2_TRIGER_EADC_ENABLE*/

#if ((NUCODEGEN_BPWM0_CH2_INT_SEL) & 4)

    /* Enable duty interrupt - count up interrupt */
    BPWM_EnableDutyInt(BPWM0, 2, BPWM_DUTY_INT_UP_COUNT_MATCH_CMP) ;

#endif /*NUCODEGEN_BPWM0_CH2_INT_SEL*/

#if ((NUCODEGEN_BPWM0_CH2_INT_SEL) & 8)

    /* Enable duty interrupt - count down interrupt */
    BPWM_EnableDutyInt(BPWM0, 2, BPWM_DUTY_INT_DOWN_COUNT_MATCH_CMP) ;

#endif /*NUCODEGEN_BPWM0_CH2_INT_SEL*/

#endif /*NUCODEGEN_BPWM0_CH2_ADVANCED*/

#endif /*NUCODEGEN_BPWM0_CH2_ENABLE*/

#if NUCODEGEN_BPWM0_CH3_ENABLE

    /* Set the duty of BPWM0 CH3*/
    BPWM_SET_CMR(BPWM0, 3, NUCODEGEN_BPWM0_CH3_CMPDATA);

    /* Set output level of BPWM0 CH3*/
    BPWM_SET_OUTPUT_LEVEL(BPWM0, BIT3, NUCODEGEN_BPWM0_CH3_WAVEOUT_ZERO, NUCODEGEN_BPWM0_CH3_WAVEOUT_CMPUP, NUCODEGEN_BPWM0_CH3_WAVEOUT_PERIOD, NUCODEGEN_BPWM0_CH3_WAVEOUT_CMPDOWN);

    /* Enable output of BPWM0 channel 3 */
    BPWM_EnableOutput(BPWM0, BPWM_CH_3_MASK);

#if NUCODEGEN_BPWM0_CH3_ADVANCED

#if (NUCODEGEN_BPWM0_CH3_LOAD_MODE == 0)

    /* Period loading mode*/
    BPWM_DisableLoadMode(BPWM0, 3, BPWM_LOAD_MODE_IMMEDIATE|BPWM_LOAD_MODE_CENTER) ;

#elif (NUCODEGEN_BPWM0_CH3_LOAD_MODE == 1)

    /*Immediate loading mode*/
    BPWM_EnableLoadMode(BPWM0, 3, BPWM_LOAD_MODE_IMMEDIATE) ;

#elif (NUCODEGEN_BPWM0_CH3_LOAD_MODE == 2)

    /*Center loading mode*/
    BPWM_EnableLoadMode(BPWM0, 3, BPWM_LOAD_MODE_CENTER) ;

#endif /*NUCODEGEN_BPWM0_CH3_LOAD_MODE*/

#if (NUCODEGEN_BPWM0_CH3_OTHER_OUTPUT==1)

    /* Enable mask output and output high or low*/
    BPWM_SetMaskOutput(BPWM0, 3, NUCODEGEN_BPWM0_CH3_MASK_DATA);

#elif (NUCODEGEN_BPWM0_CH3_OTHER_OUTPUT==2)

    /* Enable inverter output */
    BPWM0->POLCTL |= BPWM_CH_3_MASK;

#endif /*NUCODEGEN_BPWM0_CH3_OTHER_OUTPUT*/

#if NUCODEGEN_BPWM0_CH3_TRIGER_EADC_ENABLE

    /* Set trigger ADC and trigger source*/
    BPWM_EnableADCTrigger(BPWM0, 3, NUCODEGEN_BPWM0_CH3_TRIGER_EADCSRC) ;

#endif /*NUCODEGEN_BPWM0_CH3_TRIGER_EADC_ENABLE*/

#if ((NUCODEGEN_BPWM0_CH3_INT_SEL) & 4)

    /* Enable duty interrupt - count up interrupt */
    BPWM_EnableDutyInt(BPWM0, 3, BPWM_DUTY_INT_UP_COUNT_MATCH_CMP) ;

#endif /*NUCODEGEN_BPWM0_CH3_INT_SEL*/

#if ((NUCODEGEN_BPWM0_CH3_INT_SEL) & 8)

    /* Enable duty interrupt - count down interrupt */
    BPWM_EnableDutyInt(BPWM0, 3, BPWM_DUTY_INT_DOWN_COUNT_MATCH_CMP) ;

#endif /*NUCODEGEN_BPWM0_CH3_INT_SEL*/

#endif /*NUCODEGEN_BPWM0_CH3_ADVANCED*/

#endif /*NUCODEGEN_BPWM0_CH3_ENABLE*/

#if NUCODEGEN_BPWM0_CH4_ENABLE

    /* Set the duty of BPWM0 CH4*/
    BPWM_SET_CMR(BPWM0, 4, NUCODEGEN_BPWM0_CH4_CMPDATA);

    /* Set output level of BPWM0 CH4*/
    BPWM_SET_OUTPUT_LEVEL(BPWM0, BIT4, NUCODEGEN_BPWM0_CH4_WAVEOUT_ZERO, NUCODEGEN_BPWM0_CH4_WAVEOUT_CMPUP, NUCODEGEN_BPWM0_CH4_WAVEOUT_PERIOD, NUCODEGEN_BPWM0_CH4_WAVEOUT_CMPDOWN);

    /* Enable output of BPWM0 channel 4 */
    BPWM_EnableOutput(BPWM0, BPWM_CH_4_MASK);

#if NUCODEGEN_BPWM0_CH4_ADVANCED

#if (NUCODEGEN_BPWM0_CH4_LOAD_MODE == 0)

    /* Period loading mode*/
    BPWM_DisableLoadMode(BPWM0, 4, BPWM_LOAD_MODE_IMMEDIATE|BPWM_LOAD_MODE_CENTER) ;

#elif (NUCODEGEN_BPWM0_CH4_LOAD_MODE == 1)

    /*Immediate loading mode*/
    BPWM_EnableLoadMode(BPWM0, 4, BPWM_LOAD_MODE_IMMEDIATE) ;

#elif (NUCODEGEN_BPWM0_CH4_LOAD_MODE == 2)

    /*Center loading mode*/
    BPWM_EnableLoadMode(BPWM0, 4, BPWM_LOAD_MODE_CENTER) ;

#endif /*NUCODEGEN_BPWM0_CH4_LOAD_MODE*/

#if (NUCODEGEN_BPWM0_CH4_OTHER_OUTPUT==1)

    /* Enable mask output and output high or low*/
    BPWM_SetMaskOutput(BPWM0, 4, NUCODEGEN_BPWM0_CH4_MASK_DATA);

#elif (NUCODEGEN_BPWM0_CH4_OTHER_OUTPUT==2)

    /* Enable inverter output */
    BPWM0->POLCTL |= BPWM_CH_4_MASK;

#endif /*NUCODEGEN_BPWM0_CH4_OTHER_OUTPUT*/

#if NUCODEGEN_BPWM0_CH4_TRIGER_EADC_ENABLE

    /* Set trigger ADC and trigger source*/
    BPWM_EnableADCTrigger(BPWM0, 4, NUCODEGEN_BPWM0_CH4_TRIGER_EADCSRC) ;

#endif /*NUCODEGEN_BPWM0_CH4_TRIGER_EADC_ENABLE*/

#if ((NUCODEGEN_BPWM0_CH4_INT_SEL) & 4)

    /* Enable duty interrupt - count up interrupt */
    BPWM_EnableDutyInt(BPWM0, 4, BPWM_DUTY_INT_UP_COUNT_MATCH_CMP) ;

#endif /*NUCODEGEN_BPWM0_CH4_INT_SEL*/

#if ((NUCODEGEN_BPWM0_CH4_INT_SEL) & 8)

    /* Enable duty interrupt - count down interrupt */
    BPWM_EnableDutyInt(BPWM0, 4, BPWM_DUTY_INT_DOWN_COUNT_MATCH_CMP) ;

#endif /*NUCODEGEN_BPWM0_CH4_INT_SEL*/

#endif /*NUCODEGEN_BPWM0_CH4_ADVANCED*/

#endif /*NUCODEGEN_BPWM0_CH4_ENABLE*/

#if NUCODEGEN_BPWM0_CH5_ENABLE

    /* Set the duty of BPWM0 CH5*/
    BPWM_SET_CMR(BPWM0, 5, NUCODEGEN_BPWM0_CH5_CMPDATA);

    /* Set output level of BPWM0 CH5*/
    BPWM_SET_OUTPUT_LEVEL(BPWM0, BIT5, NUCODEGEN_BPWM0_CH5_WAVEOUT_ZERO, NUCODEGEN_BPWM0_CH5_WAVEOUT_CMPUP, NUCODEGEN_BPWM0_CH5_WAVEOUT_PERIOD, NUCODEGEN_BPWM0_CH5_WAVEOUT_CMPDOWN);

    /* Enable output of BPWM0 channel 5 */
    BPWM_EnableOutput(BPWM0, BPWM_CH_5_MASK);

#if NUCODEGEN_BPWM0_CH5_ADVANCED

#if (NUCODEGEN_BPWM0_CH5_LOAD_MODE == 0)

    /* Period loading mode*/
    BPWM_DisableLoadMode(BPWM0, 5, BPWM_LOAD_MODE_IMMEDIATE|BPWM_LOAD_MODE_CENTER) ;

#elif (NUCODEGEN_BPWM0_CH5_LOAD_MODE == 1)

    /*Immediate loading mode*/
    BPWM_EnableLoadMode(BPWM0, 5, BPWM_LOAD_MODE_IMMEDIATE) ;

#elif (NUCODEGEN_BPWM0_CH5_LOAD_MODE == 2)

    /*Center loading mode*/
    BPWM_EnableLoadMode(BPWM0, 5, BPWM_LOAD_MODE_CENTER) ;

#endif /*NUCODEGEN_BPWM0_CH5_LOAD_MODE*/

#if (NUCODEGEN_BPWM0_CH5_OTHER_OUTPUT==1)

    /* Enable mask output and output high or low*/
    BPWM_SetMaskOutput(BPWM0, 5, NUCODEGEN_BPWM0_CH5_MASK_DATA);

#elif (NUCODEGEN_BPWM0_CH5_OTHER_OUTPUT==2)

    /* Enable inverter output */
    BPWM0->POLCTL |= BPWM_CH_5_MASK;

#endif /*NUCODEGEN_BPWM0_CH5_OTHER_OUTPUT*/

#if NUCODEGEN_BPWM0_CH5_TRIGER_EADC_ENABLE

    /* Set trigger ADC and trigger source*/
    BPWM_EnableADCTrigger(BPWM0, 5, NUCODEGEN_BPWM0_CH5_TRIGER_EADCSRC) ;

#endif /*NUCODEGEN_BPWM0_CH5_TRIGER_EADC_ENABLE*/

#if (((NUCODEGEN_BPWM0_CH5_INT_SEL) & 4))

    /* Enable duty interrupt - count up interrupt */
    BPWM_EnableDutyInt(BPWM0, 5, BPWM_DUTY_INT_UP_COUNT_MATCH_CMP) ;

#endif /*NUCODEGEN_BPWM0_CH5_INT_SEL*/

#if (((NUCODEGEN_BPWM0_CH5_INT_SEL) & 8))

    /* Enable duty interrupt - count down interrupt */
    BPWM_EnableDutyInt(BPWM0, 5, BPWM_DUTY_INT_DOWN_COUNT_MATCH_CMP) ;

#endif /*NUCODEGEN_BPWM0_CH5_INT_SEL*/

#endif /*NUCODEGEN_BPWM0_CH5_ADVANCED*/

#endif /*NUCODEGEN_BPWM0_CH5_ENABLE*/


#endif /*NUCODEGEN_BPWM0_OUTPUT_FUNC_SETMODE*/

#else

    /* Configure BPWM capture and get the nearest unit time */
    BPWM_ConfigCaptureChannel(BPWM0, 0, NUCODEGEN_BPWM0_CAP_UNITTIME, 0);

#if NUCODEGEN_BPWM0_CH0_CAP_ENABLE

    /* Set Reload Mode */
    BPWM0->CAPCTL |= (NUCODEGEN_BPWM0_CH0_CAP_RELOAD)<<BPWM_CAPCTL_RCRLDEN0_Pos;

    /* Enable Capture Function for BPWM0 channel 0 */
    BPWM_EnableCapture(BPWM0, BPWM_CH_0_MASK);

#if NUCODEGEN_BPWM0_CH0_CAP_ADVANCED

#if (NUCODEGEN_BPWM0_CH0_CAP_INT_SEL == 1)

    /*Enable rising latch capture interrupt*/
    BPWM_EnableCaptureInt(BPWM0, 0, BPWM_CAPTURE_INT_RISING_LATCH) ;

#elif (NUCODEGEN_BPWM0_CH0_CAP_INT_SEL == 2)

    /*Enable falling latch capture interrupt*/
    BPWM_EnableCaptureInt(BPWM0, 0, BPWM_CAPTURE_INT_FALLING_LATCH) ;

#elif (NUCODEGEN_BPWM0_CH0_CAP_INT_SEL == 3)

    /*Enable rising and falling latch capture interrupt*/
    BPWM_EnableCaptureInt(BPWM0, 0, BPWM_CAPTURE_INT_RISING_LATCH|BPWM_CAPTURE_INT_FALLING_LATCH) ;

#endif /*NUCODEGEN_BPWM0_CH0_CAP_INT_SEL*/

#endif /*NUCODEGEN_BPWM0_CH0_CAP_ADVANCED*/

#endif /*NUCODEGEN_BPWM0_CH0_CAP_ENABLE*/

#if NUCODEGEN_BPWM0_CH1_CAP_ENABLE

    /* Set Reload Mode */
    BPWM0->CAPCTL |= (NUCODEGEN_BPWM0_CH1_CAP_RELOAD)<<BPWM_CAPCTL_RCRLDEN1_Pos;

    /* Enable Timer for BPWM0 channel 1 */
    BPWM_Start(BPWM0, BPWM_CH_1_MASK);

    /* Enable Capture Function for BPWM0 channel 1 */
    BPWM_EnableCapture(BPWM0, BPWM_CH_1_MASK);

#if NUCODEGEN_BPWM0_CH1_CAP_ADVANCED

#if (NUCODEGEN_BPWM0_CH1_CAP_INT_SEL == 1)

    /*Enable rising latch capture interrupt*/
    BPWM_EnableCaptureInt(BPWM0, 1, BPWM_CAPTURE_INT_RISING_LATCH) ;

#elif (NUCODEGEN_BPWM0_CH1_CAP_INT_SEL == 2)

    /*Enable falling latch capture interrupt*/
    BPWM_EnableCaptureInt(BPWM0, 1, BPWM_CAPTURE_INT_FALLING_LATCH) ;

#elif (NUCODEGEN_BPWM0_CH1_CAP_INT_SEL == 3)

    /*Enable rising and falling latch capture interrupt*/
    BPWM_EnableCaptureInt(BPWM0, 1, BPWM_CAPTURE_INT_RISING_LATCH|BPWM_CAPTURE_INT_FALLING_LATCH) ;

#endif /*NUCODEGEN_BPWM0_CH1_CAP_INT_SEL*/

#endif /*NUCODEGEN_BPWM0_CH1_CAP_ADVANCED*/

#endif /*NUCODEGEN_BPWM0_CH1_CAP_ENABLE*/

#if NUCODEGEN_BPWM0_CH2_CAP_ENABLE

    /* Set Reload Mode */
    BPWM0->CAPCTL |= (NUCODEGEN_BPWM0_CH2_CAP_RELOAD)<<BPWM_CAPCTL_RCRLDEN2_Pos;

    /* Enable Capture Function for BPWM0 channel 2 */
    BPWM_EnableCapture(BPWM0, BPWM_CH_2_MASK);

#if NUCODEGEN_BPWM0_CH2_CAP_ADVANCED

#if (NUCODEGEN_BPWM0_CH2_CAP_INT_SEL == 1)

    /*Enable rising latch capture interrupt*/
    BPWM_EnableCaptureInt(BPWM0, 2, BPWM_CAPTURE_INT_RISING_LATCH) ;

#elif (NUCODEGEN_BPWM0_CH2_CAP_INT_SEL == 2)

    /*Enable falling latch capture interrupt*/
    BPWM_EnableCaptureInt(BPWM0, 2, BPWM_CAPTURE_INT_FALLING_LATCH) ;

#elif (NUCODEGEN_BPWM0_CH2_CAP_INT_SEL == 3)

    /*Enable rising and falling latch capture interrupt*/
    BPWM_EnableCaptureInt(BPWM0, 2, BPWM_CAPTURE_INT_RISING_LATCH|BPWM_CAPTURE_INT_FALLING_LATCH) ;

#endif /*NUCODEGEN_BPWM0_CH2_CAP_INT_SEL*/

#endif /*NUCODEGEN_BPWM0_CH2_CAP_ADVANCED*/

#endif /*NUCODEGEN_BPWM0_CH2_CAP_ENABLE*/

#if NUCODEGEN_BPWM0_CH3_CAP_ENABLE

    /* Set Reload Mode */
    BPWM0->CAPCTL |= (NUCODEGEN_BPWM0_CH3_CAP_RELOAD)<<BPWM_CAPCTL_RCRLDEN3_Pos;

    /* Enable Capture Function for BPWM0 channel 3 */
    BPWM_EnableCapture(BPWM0, BPWM_CH_3_MASK);

#if NUCODEGEN_BPWM0_CH3_CAP_ADVANCED

#if (NUCODEGEN_BPWM0_CH3_CAP_INT_SEL == 1)

    /*Enable rising latch capture interrupt*/
    BPWM_EnableCaptureInt(BPWM0, 3, BPWM_CAPTURE_INT_RISING_LATCH) ;

#elif (NUCODEGEN_BPWM0_CH3_CAP_INT_SEL == 2)

    /*Enable falling latch capture interrupt*/
    BPWM_EnableCaptureInt(BPWM0, 3, BPWM_CAPTURE_INT_FALLING_LATCH) ;

#elif (NUCODEGEN_BPWM0_CH3_CAP_INT_SEL == 3)

    /*Enable rising and falling latch capture interrupt*/
    BPWM_EnableCaptureInt(BPWM0, 3, BPWM_CAPTURE_INT_RISING_LATCH|BPWM_CAPTURE_INT_FALLING_LATCH) ;

#endif /*NUCODEGEN_BPWM0_CH3_CAP_INT_SEL*/

#endif /*NUCODEGEN_BPWM0_CH3_CAP_ADVANCED*/

#endif /*NUCODEGEN_BPWM0_CH3_CAP_ENABLE*/

#if NUCODEGEN_BPWM0_CH4_CAP_ENABLE

    /* Set Reload Mode */
    BPWM0->CAPCTL |= (NUCODEGEN_BPWM0_CH4_CAP_RELOAD)<<BPWM_CAPCTL_RCRLDEN4_Pos;

    /* Enable Capture Function for BPWM0 channel 4 */
    BPWM_EnableCapture(BPWM0, BPWM_CH_4_MASK);

#if NUCODEGEN_BPWM0_CH4_CAP_ADVANCED

#if (NUCODEGEN_BPWM0_CH4_CAP_INT_SEL == 1)

    /*Enable rising latch capture interrupt*/
    BPWM_EnableCaptureInt(BPWM0, 4, BPWM_CAPTURE_INT_RISING_LATCH) ;

#elif (NUCODEGEN_BPWM0_CH4_CAP_INT_SEL == 2)

    /*Enable falling latch capture interrupt*/
    BPWM_EnableCaptureInt(BPWM0, 4, BPWM_CAPTURE_INT_FALLING_LATCH) ;

#elif (NUCODEGEN_BPWM0_CH4_CAP_INT_SEL == 3)

    /*Enable rising and falling latch capture interrupt*/
    BPWM_EnableCaptureInt(BPWM0, 4, BPWM_CAPTURE_INT_RISING_LATCH|BPWM_CAPTURE_INT_FALLING_LATCH) ;

#endif /*NUCODEGEN_BPWM0_CH4_CAP_INT_SEL*/

#endif /*NUCODEGEN_BPWM0_CH4_CAP_ADVANCED*/

#endif /*NUCODEGEN_BPWM0_CH4_CAP_ENABLE*/

#if NUCODEGEN_BPWM0_CH5_CAP_ENABLE

    /* Set Reload Mode */
    BPWM0->CAPCTL |= (NUCODEGEN_BPWM0_CH5_CAP_RELOAD)<<BPWM_CAPCTL_RCRLDEN5_Pos;

    /* Enable Capture Function for BPWM0 channel 5 */
    BPWM_EnableCapture(BPWM0, BPWM_CH_5_MASK);

#if NUCODEGEN_BPWM0_CH5_CAP_ADVANCED

#if (NUCODEGEN_BPWM0_CH5_CAP_INT_SEL == 1)

    /*Enable rising latch capture interrupt*/
    BPWM_EnableCaptureInt(BPWM0, 5, BPWM_CAPTURE_INT_RISING_LATCH) ;

#elif (NUCODEGEN_BPWM0_CH5_CAP_INT_SEL == 2)

    /*Enable falling latch capture interrupt*/
    BPWM_EnableCaptureInt(BPWM0, 5, BPWM_CAPTURE_INT_FALLING_LATCH) ;

#elif (NUCODEGEN_BPWM0_CH5_CAP_INT_SEL == 3)

    /*Enable rising and falling latch capture interrupt*/
    BPWM_EnableCaptureInt(BPWM0, 5, BPWM_CAPTURE_INT_RISING_LATCH|BPWM_CAPTURE_INT_FALLING_LATCH) ;

#endif /*NUCODEGEN_BPWM0_CH5_CAP_INT_SEL*/

#endif /*NUCODEGEN_BPWM0_CH5_CAP_ADVANCED*/

#endif /*NUCODEGEN_BPWM0_CH5_CAP_ENABLE*/

#endif /*NUCODEGEN_BPWM0_FUNC_SEL*/

}

#endif //NUCODEGEN_BPWM0

#if (NUCODEGEN_BPWM1)
void BPWM1_Init()
{

#if (NUCODEGEN_BPWM1_FUNC_SEL==0)

#if (NUCODEGEN_BPWM1_OUTPUT_FUNC_SETMODE==0)

#if NUCODEGEN_BPWM1_CH0_ENABLE

    /* Set BPWM1 channel 0 configuration */
    BPWM_ConfigOutputChannel(BPWM1, 0, NUCODEGEN_BPWM1_FREQ, NUCODEGEN_BPWM1_CH0_DUTY);

    /* Enable output of BPWM1 channel 0 */
    BPWM_EnableOutput(BPWM1, BPWM_CH_0_MASK);

#endif /*NUCODEGEN_BPWM1_CH0_ENABLE*/

#if NUCODEGEN_BPWM1_CH1_ENABLE

    /* Set BPWM1 channel 1 configuration */
    BPWM_ConfigOutputChannel(BPWM1, 1, NUCODEGEN_BPWM1_FREQ, NUCODEGEN_BPWM1_CH1_DUTY);

    /* Enable output of BPWM1 channel 1 */
    BPWM_EnableOutput(BPWM1, BPWM_CH_1_MASK);

#endif /*NUCODEGEN_BPWM1_CH1_ENABLE*/

#if NUCODEGEN_BPWM1_CH2_ENABLE
    /* Set BPWM1 channel 2 configuration */
    BPWM_ConfigOutputChannel(BPWM1, 2, NUCODEGEN_BPWM1_FREQ, NUCODEGEN_BPWM1_CH2_DUTY);
    /* Enable output of BPWM1 channel 2 */
    BPWM_EnableOutput(BPWM1, BPWM_CH_2_MASK);

#endif /*NUCODEGEN_BPWM1_CH2_ENABLE*/

#if NUCODEGEN_BPWM1_CH3_ENABLE
    /* Set BPWM1 channel 3 configuration */
    BPWM_ConfigOutputChannel(BPWM1, 3, NUCODEGEN_BPWM1_FREQ, NUCODEGEN_BPWM1_CH3_DUTY);
    /* Enable output of BPWM1 channel 3 */
    BPWM_EnableOutput(BPWM1, BPWM_CH_3_MASK);

#endif /*NUCODEGEN_BPWM1_CH3_ENABLE*/

#if NUCODEGEN_BPWM1_CH4_ENABLE
    /* Set BPWM1 channel 4 configuration */
    BPWM_ConfigOutputChannel(BPWM1, 4, NUCODEGEN_BPWM1_FREQ, NUCODEGEN_BPWM1_CH4_DUTY);
    /* Enable output of BPWM1 channel 4 */
    BPWM_EnableOutput(BPWM1, BPWM_CH_4_MASK);


#endif /*NUCODEGEN_BPWM1_CH4_ENABLE*/

#if NUCODEGEN_BPWM1_CH5_ENABLE

    /* Set BPWM1 channel 5 configuration */
    BPWM_ConfigOutputChannel(BPWM1, 5, NUCODEGEN_BPWM1_FREQ, NUCODEGEN_BPWM1_CH5_DUTY);

    /* Enable output of BPWM1 channel 5 */
    BPWM_EnableOutput(BPWM1, BPWM_CH_5_MASK);

#endif /*NUCODEGEN_BPWM1_CH5_ENABLE*/

#else

    /* Set BPWM1 clock source */
    BPWM_SetClockSource(BPWM1, 0, NUCODEGEN_BPWM1_CLKSRC);

    /* Set BPWM1 counter behavior type */
    BPWM_SET_ALIGNED_TYPE(BPWM1, BPWM_CH_0_MASK, NUCODEGEN_BPWM1_CNTTYPE);

    /* Set the prescaler of BPWM1  */
    BPWM_SET_PRESCALER(BPWM1, 0,NUCODEGEN_BPWM1_PRESCALER);

    /* Set the period of BPWM1 */
    BPWM_SET_CNR(BPWM1, 0, NUCODEGEN_BPWM1_PERIOD);

#if NUCODEGEN_BPWM1_SYNCSTART_ENABLE

    /* Enable timer synchronous start counting function */
    BPWM_ENABLE_TIMER_SYNC(BPWM1, BIT0, NUCODEGEN_BPWM1_SYNCSTART_SRC) ;

#endif /*NUCODEGEN_BPWM1_SYNCSTART_ENABLE*/


#if (((NUCODEGEN_BPWM1_CH0_INT_SEL) & 1)||((NUCODEGEN_BPWM1_CH1_INT_SEL) & 1)||((NUCODEGEN_BPWM1_CH2_INT_SEL) & 1)||((NUCODEGEN_BPWM1_CH3_INT_SEL) & 1)||((NUCODEGEN_BPWM1_CH4_INT_SEL) & 1)||((NUCODEGEN_BPWM1_CH5_INT_SEL) & 1))

    /* Enable zero interrupt */
    BPWM_EnableZeroInt(BPWM1, 0) ;

#endif

#if (((NUCODEGEN_BPWM1_CH0_INT_SEL) & 2)||((NUCODEGEN_BPWM1_CH1_INT_SEL) & 2)||((NUCODEGEN_BPWM1_CH2_INT_SEL) & 2)||((NUCODEGEN_BPWM1_CH3_INT_SEL) & 2)||((NUCODEGEN_BPWM1_CH4_INT_SEL) & 2)||((NUCODEGEN_BPWM1_CH5_INT_SEL) & 2))

    /* Enable period interrupt */
    BPWM_EnablePeriodInt(BPWM1, 0, 0) ;

#endif

#if NUCODEGEN_BPWM1_CH0_ENABLE

    /* Set the duty of BPWM1 CH0*/
    BPWM_SET_CMR(BPWM1, 0, NUCODEGEN_BPWM1_CH0_CMPDATA);

    /* Set output level of BPWM1 CH0*/
    BPWM_SET_OUTPUT_LEVEL(BPWM1, BIT0, NUCODEGEN_BPWM1_CH0_WAVEOUT_ZERO, NUCODEGEN_BPWM1_CH0_WAVEOUT_CMPUP, NUCODEGEN_BPWM1_CH0_WAVEOUT_PERIOD, NUCODEGEN_BPWM1_CH0_WAVEOUT_CMPDOWN);

    /* Enable output of BPWM1 channel 0 */
    BPWM_EnableOutput(BPWM1, BPWM_CH_0_MASK);

#if NUCODEGEN_BPWM1_CH0_ADVANCED

#if (NUCODEGEN_BPWM1_CH0_LOAD_MODE == 0)

    /* Period loading mode*/
    BPWM_DisableLoadMode(BPWM1, 0, BPWM_LOAD_MODE_IMMEDIATE|BPWM_LOAD_MODE_CENTER) ;

#elif (NUCODEGEN_BPWM1_CH0_LOAD_MODE == 1)

    /*Immediate loading mode*/
    BPWM_EnableLoadMode(BPWM1, 0, BPWM_LOAD_MODE_IMMEDIATE) ;

#elif (NUCODEGEN_BPWM1_CH0_LOAD_MODE == 2)

    /*Center loading mode*/
    BPWM_EnableLoadMode(BPWM1, 0, BPWM_LOAD_MODE_CENTER) ;

#endif /*NUCODEGEN_BPWM1_CH0_LOAD_MODE*/

#if (NUCODEGEN_BPWM1_CH0_OTHER_OUTPUT==1)

    /* Enable mask output and output high or low*/
    BPWM_SetMaskOutput(BPWM1, 0, NUCODEGEN_BPWM1_CH0_MASK_DATA);

#elif (NUCODEGEN_BPWM1_CH0_OTHER_OUTPUT==2)

    /* Enable inverter output */
    BPWM1->POLCTL |= BPWM_CH_0_MASK;

#endif /*NUCODEGEN_BPWM1_CH0_OTHER_OUTPUT*/

#if NUCODEGEN_BPWM1_CH0_TRIGER_EADC_ENABLE

    /* Set trigger ADC and trigger source*/
    BPWM_EnableADCTrigger(BPWM1, 0, NUCODEGEN_BPWM1_CH0_TRIGER_EADCSRC) ;

#endif /*NUCODEGEN_BPWM1_CH0_TRIGER_EADC_ENABLE*/

#if ((NUCODEGEN_BPWM1_CH0_INT_SEL) & 4)

    /* Enable duty interrupt - count up interrupt */
    BPWM_EnableDutyInt(BPWM1, 0, BPWM_DUTY_INT_UP_COUNT_MATCH_CMP) ;

#endif /*NUCODEGEN_BPWM1_CH0_INT_SEL*/

#if ((NUCODEGEN_BPWM1_CH0_INT_SEL) & 8)

    /* Enable duty interrupt - count down interrupt */
    BPWM_EnableDutyInt(BPWM1, 0, BPWM_DUTY_INT_DOWN_COUNT_MATCH_CMP) ;

#endif /*NUCODEGEN_BPWM1_CH0_INT_SEL*/

#endif /*NUCODEGEN_BPWM1_CH0_ADVANCED*/

#endif /*NUCODEGEN_BPWM1_CH0_ENABLE*/

#if NUCODEGEN_BPWM1_CH1_ENABLE

    /* Set the duty of BPWM1 CH1*/
    BPWM_SET_CMR(BPWM1, 1, NUCODEGEN_BPWM1_CH1_CMPDATA);

    /* Set output level of BPWM1 CH1*/
    BPWM_SET_OUTPUT_LEVEL(BPWM1, BIT1, NUCODEGEN_BPWM1_CH1_WAVEOUT_ZERO, NUCODEGEN_BPWM1_CH1_WAVEOUT_CMPUP, NUCODEGEN_BPWM1_CH1_WAVEOUT_PERIOD, NUCODEGEN_BPWM1_CH1_WAVEOUT_CMPDOWN);

    /* Enable output of BPWM1 channel 1 */
    BPWM_EnableOutput(BPWM1, BPWM_CH_1_MASK);

#if NUCODEGEN_BPWM1_CH1_ADVANCED

#if (NUCODEGEN_BPWM1_CH1_LOAD_MODE == 0)

    /* Period loading mode*/
    BPWM_DisableLoadMode(BPWM1, 1, BPWM_LOAD_MODE_IMMEDIATE|BPWM_LOAD_MODE_CENTER) ;

#elif (NUCODEGEN_BPWM1_CH1_LOAD_MODE == 1)

    /*Immediate loading mode*/
    BPWM_EnableLoadMode(BPWM1, 1, BPWM_LOAD_MODE_IMMEDIATE) ;

#elif (NUCODEGEN_BPWM1_CH1_LOAD_MODE == 2)

    /*Center loading mode*/
    BPWM_EnableLoadMode(BPWM1, 1, BPWM_LOAD_MODE_CENTER) ;

#endif /*NUCODEGEN_BPWM1_CH1_LOAD_MODE*/

#if (NUCODEGEN_BPWM1_CH1_OTHER_OUTPUT==1)

    /* Enable mask output and output high or low*/
    BPWM_SetMaskOutput(BPWM1, 1, NUCODEGEN_BPWM1_CH1_MASK_DATA);

#elif (NUCODEGEN_BPWM1_CH1_OTHER_OUTPUT==2)

    /* Enable inverter output */
    BPWM1->POLCTL |= BPWM_CH_1_MASK;

#endif /*NUCODEGEN_BPWM1_CH1_OTHER_OUTPUT*/

#if NUCODEGEN_BPWM1_CH1_TRIGER_EADC_ENABLE

    /* Set trigger ADC and trigger source*/
    BPWM_EnableADCTrigger(BPWM1, 1, NUCODEGEN_BPWM1_CH1_TRIGER_EADCSRC) ;

#endif /*NUCODEGEN_BPWM1_CH1_TRIGER_EADC_ENABLE*/

#if (((NUCODEGEN_BPWM1_CH1_INT_SEL) & 4))

    /* Enable duty interrupt - count up interrupt */
    BPWM_EnableDutyInt(BPWM1, 1, BPWM_DUTY_INT_UP_COUNT_MATCH_CMP) ;

#endif /*NUCODEGEN_BPWM1_CH1_INT_SEL*/

#if (((NUCODEGEN_BPWM1_CH1_INT_SEL) & 8))

    /* Enable duty interrupt - count down interrupt */
    BPWM_EnableDutyInt(BPWM1, 1, BPWM_DUTY_INT_DOWN_COUNT_MATCH_CMP) ;

#endif /*NUCODEGEN_BPWM1_CH1_INT_SEL*/

#endif /*NUCODEGEN_BPWM1_CH1_ADVANCED*/

#endif /*NUCODEGEN_BPWM1_CH1_ENABLE*/

#if NUCODEGEN_BPWM1_CH2_ENABLE

    /* Set the duty of BPWM1 CH2*/
    BPWM_SET_CMR(BPWM1, 2, NUCODEGEN_BPWM1_CH2_CMPDATA);

    /* Set output level of BPWM1 CH2*/
    BPWM_SET_OUTPUT_LEVEL(BPWM1, BIT2, NUCODEGEN_BPWM1_CH2_WAVEOUT_ZERO, NUCODEGEN_BPWM1_CH2_WAVEOUT_CMPUP, NUCODEGEN_BPWM1_CH2_WAVEOUT_PERIOD, NUCODEGEN_BPWM1_CH2_WAVEOUT_CMPDOWN);

    /* Enable output of BPWM1 channel 2 */
    BPWM_EnableOutput(BPWM1, BPWM_CH_2_MASK);

#if NUCODEGEN_BPWM1_CH2_ADVANCED

#if (NUCODEGEN_BPWM1_CH2_LOAD_MODE == 0)

    /* Period loading mode*/
    BPWM_DisableLoadMode(BPWM1, 2, BPWM_LOAD_MODE_IMMEDIATE|BPWM_LOAD_MODE_CENTER) ;

#elif (NUCODEGEN_BPWM1_CH2_LOAD_MODE == 1)

    /*Immediate loading mode*/
    BPWM_EnableLoadMode(BPWM1, 2, BPWM_LOAD_MODE_IMMEDIATE) ;

#elif (NUCODEGEN_BPWM1_CH2_LOAD_MODE == 2)

    /*Center loading mode*/
    BPWM_EnableLoadMode(BPWM1, 2, BPWM_LOAD_MODE_CENTER) ;

#endif /*NUCODEGEN_BPWM1_CH2_LOAD_MODE*/

#if (NUCODEGEN_BPWM1_CH2_OTHER_OUTPUT==1)

    /* Enable mask output and output high or low*/
    BPWM_SetMaskOutput(BPWM1, 2, NUCODEGEN_BPWM1_CH2_MASK_DATA);

#elif (NUCODEGEN_BPWM1_CH2_OTHER_OUTPUT==2)

    /* Enable inverter output */
    BPWM1->POLCTL |= BPWM_CH_2_MASK;

#endif /*NUCODEGEN_BPWM1_CH2_OTHER_OUTPUT*/

#if NUCODEGEN_BPWM1_CH2_TRIGER_EADC_ENABLE

    /* Set trigger ADC and trigger source*/
    BPWM_EnableADCTrigger(BPWM1, 2, NUCODEGEN_BPWM1_CH2_TRIGER_EADCSRC) ;

#endif /*NUCODEGEN_BPWM1_CH2_TRIGER_EADC_ENABLE*/

#if (((NUCODEGEN_BPWM1_CH2_INT_SEL) & 4))

    /* Enable duty interrupt - count up interrupt */
    BPWM_EnableDutyInt(BPWM1, 2, BPWM_DUTY_INT_UP_COUNT_MATCH_CMP) ;

#endif /*NUCODEGEN_BPWM1_CH2_INT_SEL*/

#if (((NUCODEGEN_BPWM1_CH2_INT_SEL) & 8))

    /* Enable duty interrupt - count down interrupt */
    BPWM_EnableDutyInt(BPWM1, 2, BPWM_DUTY_INT_DOWN_COUNT_MATCH_CMP) ;

#endif /*NUCODEGEN_BPWM1_CH2_INT_SEL*/

#endif /*NUCODEGEN_BPWM1_CH2_ADVANCED*/

#endif /*NUCODEGEN_BPWM1_CH2_ENABLE*/

#if NUCODEGEN_BPWM1_CH3_ENABLE

    /* Set the duty of BPWM1 CH3*/
    BPWM_SET_CMR(BPWM1, 3, NUCODEGEN_BPWM1_CH3_CMPDATA);

    /* Set output level of BPWM1 CH3*/
    BPWM_SET_OUTPUT_LEVEL(BPWM1, BIT3, NUCODEGEN_BPWM1_CH3_WAVEOUT_ZERO, NUCODEGEN_BPWM1_CH3_WAVEOUT_CMPUP, NUCODEGEN_BPWM1_CH3_WAVEOUT_PERIOD, NUCODEGEN_BPWM1_CH3_WAVEOUT_CMPDOWN);

    /* Enable output of BPWM1 channel 3 */
    BPWM_EnableOutput(BPWM1, BPWM_CH_3_MASK);

#if NUCODEGEN_BPWM1_CH3_ADVANCED

#if (NUCODEGEN_BPWM1_CH3_LOAD_MODE == 0)

    /* Period loading mode*/
    BPWM_DisableLoadMode(BPWM1, 3, BPWM_LOAD_MODE_IMMEDIATE|BPWM_LOAD_MODE_CENTER) ;

#elif (NUCODEGEN_BPWM1_CH3_LOAD_MODE == 1)

    /*Immediate loading mode*/
    BPWM_EnableLoadMode(BPWM1, 3, BPWM_LOAD_MODE_IMMEDIATE) ;

#elif (NUCODEGEN_BPWM1_CH3_LOAD_MODE == 2)

    /*Center loading mode*/
    BPWM_EnableLoadMode(BPWM1, 3, BPWM_LOAD_MODE_CENTER) ;

#endif /*NUCODEGEN_BPWM1_CH3_LOAD_MODE*/

#if (NUCODEGEN_BPWM1_CH3_OTHER_OUTPUT==1)

    /* Enable mask output and output high or low*/
    BPWM_SetMaskOutput(BPWM1, 3, NUCODEGEN_BPWM1_CH3_MASK_DATA);

#elif (NUCODEGEN_BPWM1_CH3_OTHER_OUTPUT==2)

    /* Enable inverter output */
    BPWM1->POLCTL |= BPWM_CH_3_MASK;

#endif /*NUCODEGEN_BPWM1_CH3_OTHER_OUTPUT*/

#if NUCODEGEN_BPWM1_CH3_TRIGER_EADC_ENABLE

    /* Set trigger ADC and trigger source*/
    BPWM_EnableADCTrigger(BPWM1, 3, NUCODEGEN_BPWM1_CH3_TRIGER_EADCSRC) ;

#endif /*NUCODEGEN_BPWM1_CH3_TRIGER_EADC_ENABLE*/

#if (((NUCODEGEN_BPWM1_CH3_INT_SEL) & 4))

    /* Enable duty interrupt - count up interrupt */
    BPWM_EnableDutyInt(BPWM1, 3, BPWM_DUTY_INT_UP_COUNT_MATCH_CMP) ;

#endif /*NUCODEGEN_BPWM1_CH3_INT_SEL*/

#if (((NUCODEGEN_BPWM1_CH3_INT_SEL) & 8))

    /* Enable duty interrupt - count down interrupt */
    BPWM_EnableDutyInt(BPWM1, 3, BPWM_DUTY_INT_DOWN_COUNT_MATCH_CMP) ;

#endif /*NUCODEGEN_BPWM1_CH3_INT_SEL*/

#endif /*NUCODEGEN_BPWM1_CH3_ADVANCED*/

#endif /*NUCODEGEN_BPWM1_CH3_ENABLE*/

#if NUCODEGEN_BPWM1_CH4_ENABLE

    /* Set the duty of BPWM1 CH4*/
    BPWM_SET_CMR(BPWM1, 4, NUCODEGEN_BPWM1_CH4_CMPDATA);

    /* Set output level of BPWM1 CH4*/
    BPWM_SET_OUTPUT_LEVEL(BPWM1, BIT4, NUCODEGEN_BPWM1_CH4_WAVEOUT_ZERO, NUCODEGEN_BPWM1_CH4_WAVEOUT_CMPUP, NUCODEGEN_BPWM1_CH4_WAVEOUT_PERIOD, NUCODEGEN_BPWM1_CH4_WAVEOUT_CMPDOWN);

    /* Enable output of BPWM1 channel 4 */
    BPWM_EnableOutput(BPWM1, BPWM_CH_4_MASK);

#if NUCODEGEN_BPWM1_CH4_ADVANCED

#if (NUCODEGEN_BPWM1_CH4_LOAD_MODE == 0)

    /* Period loading mode*/
    BPWM_DisableLoadMode(BPWM1, 4, BPWM_LOAD_MODE_IMMEDIATE|BPWM_LOAD_MODE_CENTER) ;

#elif (NUCODEGEN_BPWM1_CH4_LOAD_MODE == 1)

    /*Immediate loading mode*/
    BPWM_EnableLoadMode(BPWM1, 4, BPWM_LOAD_MODE_IMMEDIATE) ;

#elif (NUCODEGEN_BPWM1_CH4_LOAD_MODE == 2)

    /*Center loading mode*/
    BPWM_EnableLoadMode(BPWM1, 4, BPWM_LOAD_MODE_CENTER) ;

#endif /*NUCODEGEN_BPWM1_CH4_LOAD_MODE*/

#if (NUCODEGEN_BPWM1_CH4_OTHER_OUTPUT==1)

    /* Enable mask output and output high or low*/
    BPWM_SetMaskOutput(BPWM1, 4, NUCODEGEN_BPWM1_CH4_MASK_DATA);

#elif (NUCODEGEN_BPWM1_CH4_OTHER_OUTPUT==2)

    /* Enable inverter output */
    BPWM1->POLCTL |= BPWM_CH_4_MASK;

#endif /*NUCODEGEN_BPWM1_CH4_OTHER_OUTPUT*/

#if NUCODEGEN_BPWM1_CH4_TRIGER_EADC_ENABLE

    /* Set trigger ADC and trigger source*/
    BPWM_EnableADCTrigger(BPWM1, 4, NUCODEGEN_BPWM1_CH4_TRIGER_EADCSRC) ;

#endif /*NUCODEGEN_BPWM1_CH4_TRIGER_EADC_ENABLE*/

#if (((NUCODEGEN_BPWM1_CH4_INT_SEL) & 4))

    /* Enable duty interrupt - count up interrupt */
    BPWM_EnableDutyInt(BPWM1, 4, BPWM_DUTY_INT_UP_COUNT_MATCH_CMP) ;

#endif /*NUCODEGEN_BPWM1_CH4_INT_SEL*/

#if (((NUCODEGEN_BPWM1_CH4_INT_SEL) & 8))

    /* Enable duty interrupt - count down interrupt */
    BPWM_EnableDutyInt(BPWM1, 4, BPWM_DUTY_INT_DOWN_COUNT_MATCH_CMP) ;

#endif /*NUCODEGEN_BPWM1_CH4_INT_SEL*/

#endif /*NUCODEGEN_BPWM1_CH4_ADVANCED*/

#endif /*NUCODEGEN_BPWM1_CH4_ENABLE*/

#if NUCODEGEN_BPWM1_CH5_ENABLE

    /* Set the duty of BPWM1 CH5*/
    BPWM_SET_CMR(BPWM1, 5, NUCODEGEN_BPWM1_CH5_CMPDATA);

    /* Set output level of BPWM1 CH5*/
    BPWM_SET_OUTPUT_LEVEL(BPWM1, BIT5, NUCODEGEN_BPWM1_CH5_WAVEOUT_ZERO, NUCODEGEN_BPWM1_CH5_WAVEOUT_CMPUP, NUCODEGEN_BPWM1_CH5_WAVEOUT_PERIOD, NUCODEGEN_BPWM1_CH5_WAVEOUT_CMPDOWN);

    /* Enable output of BPWM1 channel 5 */
    BPWM_EnableOutput(BPWM1, BPWM_CH_5_MASK);

#if NUCODEGEN_BPWM1_CH5_ADVANCED

#if (NUCODEGEN_BPWM1_CH5_LOAD_MODE == 0)

    /* Period loading mode*/
    BPWM_DisableLoadMode(BPWM1, 5, BPWM_LOAD_MODE_IMMEDIATE|BPWM_LOAD_MODE_CENTER) ;

#elif (NUCODEGEN_BPWM1_CH5_LOAD_MODE == 1)

    /*Immediate loading mode*/
    BPWM_EnableLoadMode(BPWM1, 5, BPWM_LOAD_MODE_IMMEDIATE) ;

#elif (NUCODEGEN_BPWM1_CH5_LOAD_MODE == 2)

    /*Center loading mode*/
    BPWM_EnableLoadMode(BPWM1, 5, BPWM_LOAD_MODE_CENTER) ;

#endif /*NUCODEGEN_BPWM1_CH5_LOAD_MODE*/

#if (NUCODEGEN_BPWM1_CH5_OTHER_OUTPUT==1)

    /* Enable mask output and output high or low*/
    BPWM_SetMaskOutput(BPWM1, 5, NUCODEGEN_BPWM1_CH5_MASK_DATA);

#elif (NUCODEGEN_BPWM1_CH5_OTHER_OUTPUT==2)

    /* Enable inverter output */
    BPWM1->POLCTL |= BPWM_CH_5_MASK;

#endif /*NUCODEGEN_BPWM1_CH5_OTHER_OUTPUT*/

#if NUCODEGEN_BPWM1_CH5_TRIGER_EADC_ENABLE

    /* Set trigger ADC and trigger source*/
    BPWM_EnableADCTrigger(BPWM1, 5, NUCODEGEN_BPWM1_CH5_TRIGER_EADCSRC) ;

#endif /*NUCODEGEN_BPWM1_CH5_TRIGER_EADC_ENABLE*/

#if (((NUCODEGEN_BPWM1_CH5_INT_SEL) & 4))

    /* Enable duty interrupt - count up interrupt */
    BPWM_EnableDutyInt(BPWM1, 5, BPWM_DUTY_INT_UP_COUNT_MATCH_CMP) ;

#endif /*NUCODEGEN_BPWM1_CH5_INT_SEL*/

#if (((NUCODEGEN_BPWM1_CH5_INT_SEL) & 8))

    /* Enable duty interrupt - count down interrupt */
    BPWM_EnableDutyInt(BPWM1, 5, BPWM_DUTY_INT_DOWN_COUNT_MATCH_CMP) ;

#endif /*NUCODEGEN_BPWM1_CH5_INT_SEL*/

#endif /*NUCODEGEN_BPWM1_CH5_ADVANCED*/

#endif /*NUCODEGEN_BPWM1_CH5_ENABLE*/

#endif /*NUCODEGEN_BPWM1_OUTPUT_FUNC_SETMODE*/

#else

    /* Configure BPWM capture and get the nearest unit time */
    BPWM_ConfigCaptureChannel(BPWM1, 0, NUCODEGEN_BPWM1_CAP_UNITTIME, 0);

#if NUCODEGEN_BPWM1_CH0_CAP_ENABLE

    /* Set Reload Mode */
    BPWM1->CAPCTL |= (NUCODEGEN_BPWM1_CH0_CAP_RELOAD)<<BPWM_CAPCTL_RCRLDEN0_Pos;

    /* Enable Capture Function for BPWM1 channel 0 */
    BPWM_EnableCapture(BPWM1, BPWM_CH_0_MASK);

#if NUCODEGEN_BPWM1_CH0_CAP_ADVANCED

#if (NUCODEGEN_BPWM1_CH0_CAP_INT_SEL == 1)

    /*Enable rising latch capture interrupt*/
    BPWM_EnableCaptureInt(BPWM1, 0, BPWM_CAPTURE_INT_RISING_LATCH) ;

#elif (NUCODEGEN_BPWM1_CH0_CAP_INT_SEL == 2)

    /*Enable falling latch capture interrupt*/
    BPWM_EnableCaptureInt(BPWM1, 0, BPWM_CAPTURE_INT_FALLING_LATCH) ;

#elif (NUCODEGEN_BPWM1_CH0_CAP_INT_SEL == 3)

    /*Enable rising and falling latch capture interrupt*/
    BPWM_EnableCaptureInt(BPWM1, 0, BPWM_CAPTURE_INT_RISING_LATCH|BPWM_CAPTURE_INT_FALLING_LATCH) ;

#endif /*NUCODEGEN_BPWM1_CH0_CAP_INT_SEL*/

#endif /*NUCODEGEN_BPWM1_CH0_CAP_ADVANCED*/

#endif /*NUCODEGEN_BPWM1_CH0_CAP_ENABLE*/

#if NUCODEGEN_BPWM1_CH1_CAP_ENABLE

    /* Set Reload Mode */
    BPWM1->CAPCTL |= (NUCODEGEN_BPWM1_CH1_CAP_RELOAD)<<BPWM_CAPCTL_RCRLDEN1_Pos;

    /* Enable Capture Function for BPWM1 channel 1 */
    BPWM_EnableCapture(BPWM1, BPWM_CH_1_MASK);

#if NUCODEGEN_BPWM1_CH1_CAP_ADVANCED

#if (NUCODEGEN_BPWM1_CH1_CAP_INT_SEL == 1)

    /*Enable rising latch capture interrupt*/
    BPWM_EnableCaptureInt(BPWM1, 1, BPWM_CAPTURE_INT_RISING_LATCH) ;

#elif (NUCODEGEN_BPWM1_CH1_CAP_INT_SEL == 2)

    /*Enable falling latch capture interrupt*/
    BPWM_EnableCaptureInt(BPWM1, 1, BPWM_CAPTURE_INT_FALLING_LATCH) ;

#elif (NUCODEGEN_BPWM1_CH1_CAP_INT_SEL == 3)

    /*Enable rising and falling latch capture interrupt*/
    BPWM_EnableCaptureInt(BPWM1, 1, BPWM_CAPTURE_INT_RISING_LATCH|BPWM_CAPTURE_INT_FALLING_LATCH) ;

#endif /*NUCODEGEN_BPWM1_CH1_CAP_INT_SEL*/

#endif /*NUCODEGEN_BPWM1_CH1_CAP_ADVANCED*/

#endif /*NUCODEGEN_BPWM1_CH1_CAP_ENABLE*/

#if NUCODEGEN_BPWM1_CH2_CAP_ENABLE

    /* Set Reload Mode */
    BPWM1->CAPCTL |= (NUCODEGEN_BPWM1_CH2_CAP_RELOAD)<<BPWM_CAPCTL_RCRLDEN2_Pos;

    /* Enable Capture Function for BPWM1 channel 2 */
    BPWM_EnableCapture(BPWM1, BPWM_CH_2_MASK);

#if NUCODEGEN_BPWM1_CH2_CAP_ADVANCED

#if (NUCODEGEN_BPWM1_CH2_CAP_INT_SEL == 1)

    /*Enable rising latch capture interrupt*/
    BPWM_EnableCaptureInt(BPWM1, 2, BPWM_CAPTURE_INT_RISING_LATCH) ;

#elif (NUCODEGEN_BPWM1_CH2_CAP_INT_SEL == 2)

    /*Enable falling latch capture interrupt*/
    BPWM_EnableCaptureInt(BPWM1, 2, BPWM_CAPTURE_INT_FALLING_LATCH) ;

#elif (NUCODEGEN_BPWM1_CH2_CAP_INT_SEL == 3)

    /*Enable rising and falling latch capture interrupt*/
    BPWM_EnableCaptureInt(BPWM1, 2, BPWM_CAPTURE_INT_RISING_LATCH|BPWM_CAPTURE_INT_FALLING_LATCH) ;

#endif /*NUCODEGEN_BPWM1_CH2_CAP_INT_SEL*/

#endif /*NUCODEGEN_BPWM1_CH2_CAP_ADVANCED*/

#endif /*NUCODEGEN_BPWM1_CH2_CAP_ENABLE*/

#if NUCODEGEN_BPWM1_CH3_CAP_ENABLE

    /* Set Reload Mode */
    BPWM1->CAPCTL |= (NUCODEGEN_BPWM1_CH3_CAP_RELOAD)<<BPWM_CAPCTL_RCRLDEN3_Pos;

    /* Enable Capture Function for BPWM1 channel 3 */
    BPWM_EnableCapture(BPWM1, BPWM_CH_3_MASK);

#if NUCODEGEN_BPWM1_CH3_CAP_ADVANCED

#if (NUCODEGEN_BPWM1_CH3_CAP_INT_SEL == 1)

    /*Enable rising latch capture interrupt*/
    BPWM_EnableCaptureInt(BPWM1, 3, BPWM_CAPTURE_INT_RISING_LATCH) ;

#elif (NUCODEGEN_BPWM1_CH3_CAP_INT_SEL == 2)

    /*Enable falling latch capture interrupt*/
    BPWM_EnableCaptureInt(BPWM1, 3, BPWM_CAPTURE_INT_FALLING_LATCH) ;

#elif (NUCODEGEN_BPWM1_CH3_CAP_INT_SEL == 3)

    /*Enable rising and falling latch capture interrupt*/
    BPWM_EnableCaptureInt(BPWM1, 3, BPWM_CAPTURE_INT_RISING_LATCH|BPWM_CAPTURE_INT_FALLING_LATCH) ;

#endif /*NUCODEGEN_BPWM1_CH3_CAP_INT_SEL*/

#endif /*NUCODEGEN_BPWM1_CH3_CAP_ADVANCED*/

#endif /*NUCODEGEN_BPWM1_CH3_CAP_ENABLE*/

#if NUCODEGEN_BPWM1_CH4_CAP_ENABLE

    /* Set Reload Mode */
    BPWM1->CAPCTL |= (NUCODEGEN_BPWM1_CH4_CAP_RELOAD)<<BPWM_CAPCTL_RCRLDEN4_Pos;

    /* Enable Capture Function for BPWM1 channel 4 */
    BPWM_EnableCapture(BPWM1, BPWM_CH_4_MASK);

#if NUCODEGEN_BPWM1_CH4_CAP_ADVANCED

#if (NUCODEGEN_BPWM1_CH4_CAP_INT_SEL == 1)

    /*Enable rising latch capture interrupt*/
    BPWM_EnableCaptureInt(BPWM1, 4, BPWM_CAPTURE_INT_RISING_LATCH) ;

#elif (NUCODEGEN_BPWM1_CH4_CAP_INT_SEL == 2)

    /*Enable falling latch capture interrupt*/
    BPWM_EnableCaptureInt(BPWM1, 4, BPWM_CAPTURE_INT_FALLING_LATCH) ;

#elif (NUCODEGEN_BPWM1_CH4_CAP_INT_SEL == 3)

    /*Enable rising and falling latch capture interrupt*/
    BPWM_EnableCaptureInt(BPWM1, 4, BPWM_CAPTURE_INT_RISING_LATCH|BPWM_CAPTURE_INT_FALLING_LATCH) ;

#endif /*NUCODEGEN_BPWM1_CH4_CAP_INT_SEL*/

#endif /*NUCODEGEN_BPWM1_CH4_CAP_ADVANCED*/

#endif /*NUCODEGEN_BPWM1_CH4_CAP_ENABLE*/

#if NUCODEGEN_BPWM1_CH5_CAP_ENABLE

    /* Set Reload Mode */
    BPWM1->CAPCTL |= (NUCODEGEN_BPWM1_CH5_CAP_RELOAD)<<BPWM_CAPCTL_RCRLDEN5_Pos;

    /* Enable Capture Function for BPWM1 channel 5 */
    BPWM_EnableCapture(BPWM1, BPWM_CH_5_MASK);

#if NUCODEGEN_BPWM1_CH5_CAP_ADVANCED

#if (NUCODEGEN_BPWM1_CH5_CAP_INT_SEL == 1)

    /*Enable rising latch capture interrupt*/
    BPWM_EnableCaptureInt(BPWM1, 5, BPWM_CAPTURE_INT_RISING_LATCH) ;

#elif (NUCODEGEN_BPWM1_CH5_CAP_INT_SEL == 2)

    /*Enable falling latch capture interrupt*/
    BPWM_EnableCaptureInt(BPWM1, 5, BPWM_CAPTURE_INT_FALLING_LATCH) ;

#elif (NUCODEGEN_BPWM1_CH5_CAP_INT_SEL == 3)

    /*Enable rising and falling latch capture interrupt*/
    BPWM_EnableCaptureInt(BPWM1, 5, BPWM_CAPTURE_INT_RISING_LATCH|BPWM_CAPTURE_INT_FALLING_LATCH) ;

#endif /*NUCODEGEN_BPWM1_CH5_CAP_INT_SEL*/

#endif /*NUCODEGEN_BPWM1_CH5_CAP_ADVANCED*/

#endif /*NUCODEGEN_BPWM1_CH5_CAP_ENABLE*/

#endif /*NUCODEGEN_BPWM1_FUNC_SEL*/

}

#endif //NUCODEGEN_BPWM1


#if ((NUCODEGEN_PWM0) || (NUCODEGEN_PWM1) )

void PWM_SetMaskOutput(PWM_T *pwm, uint32_t u32ChannelNum, uint32_t u32LevelMask)
{
    (pwm)->MSKEN |= 0x1<<u32ChannelNum;
    (pwm)->MSK |= (u32LevelMask<<u32ChannelNum);
}

void PWM_EnableBrake(PWM_T *pwm, uint32_t u32ChannelMask, uint32_t u32LevelMask, uint32_t u32BrakeSource, uint32_t u32BrakeTrigger)
{
    uint32_t i;

    for (i = 0UL; i < PWM_CHANNEL_NUM; i ++)
    {
        if (u32ChannelMask & (1UL << i))
        {
            if (u32BrakeSource & 0xF00)
            {
                (pwm)->BRKCTL[i >> 1UL] |= ((u32BrakeSource & 0xFF)<<u32BrakeTrigger);
                (pwm)->FAILBRK |= ((u32BrakeSource & 0xF00)>>8);
            }
            else
            {
                (pwm)->BRKCTL[i >> 1UL] |= (u32BrakeSource<<u32BrakeTrigger);
            }

            if ((i & 0x1UL) == 0UL)
            {
                switch ((u32LevelMask & (0x3UL << (i<<1)))>>(i<<1))
                {
                    case 0:
                        (pwm)->BRKCTL[i >> 1UL] |= ((0UL) << PWM_BRKCTL0_1_BRKAEVEN_Pos);
                        break ;
                    case 1:
                        (pwm)->BRKCTL[i >> 1UL] |= ((1UL) << PWM_BRKCTL0_1_BRKAEVEN_Pos);
                        break ;
                    case 2:
                        (pwm)->BRKCTL[i >> 1UL] |= ((2UL) << PWM_BRKCTL0_1_BRKAEVEN_Pos);
                        break ;
                    case 3:
                        (pwm)->BRKCTL[i >> 1UL] |= ((3UL) << PWM_BRKCTL0_1_BRKAEVEN_Pos);
                        break ;
                    default:
                        (pwm)->BRKCTL[i >> 1UL] |= ((0UL) << PWM_BRKCTL0_1_BRKAEVEN_Pos);
                        break ;
                }
            }
            else
            {
                switch ((u32LevelMask & (0x3UL << (i<<1)))>>(i<<1))
                {
                    case 0:
                        (pwm)->BRKCTL[i >> 1UL] |= ((0UL) << PWM_BRKCTL0_1_BRKAODD_Pos);
                        break ;
                    case 1:
                        (pwm)->BRKCTL[i >> 1UL] |= ((1UL) << PWM_BRKCTL0_1_BRKAODD_Pos);
                        break ;
                    case 2:
                        (pwm)->BRKCTL[i >> 1UL] |= ((2UL) << PWM_BRKCTL0_1_BRKAODD_Pos);
                        break ;
                    case 3:
                        (pwm)->BRKCTL[i >> 1UL] |= ((3UL) << PWM_BRKCTL0_1_BRKAODD_Pos);
                        break ;
                    default:
                        (pwm)->BRKCTL[i >> 1UL] |= ((0UL) << PWM_BRKCTL0_1_BRKAODD_Pos);
                        break ;
                }
            }
        }
    }

}

void PWM_EnableBrakeFilter(PWM_T *pwm, uint32_t u32BrakeSrc, uint32_t u32ClkCnt, uint32_t u32ClkDivSel)
{
    uint32_t u32SetData ;

    u32SetData = ((u32ClkCnt << PWM_BNF_BRK0NFCNT_Pos) | (u32ClkDivSel << PWM_BNF_BRK0NFSEL_Pos) | PWM_BNF_BRK0FEN_Msk);

    if (u32BrakeSrc & (PWM_FB_EDGE_BKP0))
        (pwm)->BNF |= (u32SetData<< (0 * PWM_BNF_BRK1FEN_Pos));
    if (u32BrakeSrc & (PWM_FB_EDGE_BKP1))
        (pwm)->BNF |= (u32SetData << (1 * PWM_BNF_BRK1FEN_Pos));
}

void PWM_EnableBrakePinInv(PWM_T *pwm, uint32_t u32BrakeSrc)
{
    uint32_t u32SetData ;

    u32SetData = (1<< PWM_BNF_BRK0PINV_Pos);

    if (u32BrakeSrc & (PWM_FB_EDGE_BKP0))
        (pwm)->BNF |= (u32SetData<< (0 * PWM_BNF_BRK1FEN_Pos));
    if (u32BrakeSrc & (PWM_FB_EDGE_BKP1))
        (pwm)->BNF |= (u32SetData << (1 * PWM_BNF_BRK1FEN_Pos));
}

#endif

#if (NUCODEGEN_PWM0)
void PWM0_Init()
{

#if NUCODEGEN_PWM0_CH0CH1

#if (NUCODEGEN_PWM0_CH0_1_FUNC_SEL==0)

#if (NUCODEGEN_PWM0_CH0_1_OUTPUT_FUNC_SETMODE==0)

#if NUCODEGEN_PWM0_CH0_ENABLE

    /* Set PWM0 channel 0 configuration */
    PWM_ConfigOutputChannel(PWM0, 0, NUCODEGEN_PWM0_CH0_1_FREQ, NUCODEGEN_PWM0_CH0_DUTY);

    /* Enable output of PWM0 channel 0 */
    PWM_EnableOutput(PWM0, PWM_CH_0_MASK);

#endif /*NUCODEGEN_PWM0_CH0_ENABLE*/

#if NUCODEGEN_PWM0_CH1_ENABLE

    /* Set PWM0 channel 1 configuration */
    PWM_ConfigOutputChannel(PWM0, 1, NUCODEGEN_PWM0_CH0_1_FREQ, NUCODEGEN_PWM0_CH1_DUTY);

    /* Enable output of PWM0 channel 1 */
    PWM_EnableOutput(PWM0, PWM_CH_1_MASK);

#endif /*NUCODEGEN_PWM0_CH1_ENABLE*/

#else

#if (NUCODEGEN_PWM0_CH0_ENABLE||NUCODEGEN_PWM0_CH1_ENABLE)

    /* Set PWM0 CH0_1 clock source */
    PWM_SetClockSource(PWM0, 0, NUCODEGEN_PWM0_CH0_1_CLKSRC);

    /* Set PWM0 CH0_1 counter behavior type */
    PWM_SET_ALIGNED_TYPE(PWM0, PWM_CH_0_MASK, NUCODEGEN_PWM0_CH0_1_CNTTYPE);

    /* Set the prescaler of PWM0 CH0_1*/
    PWM_SET_PRESCALER(PWM0, 0,NUCODEGEN_PWM0_CH0_1_PRESCALER);

    /* Set the period of PWM0 CH0_1*/
    PWM_SET_CNR(PWM0, 0, NUCODEGEN_PWM0_CH0_1_PERIOD);

#if NUCODEGEN_PWM0_CH0_1_SYNCSTART_ENABLE

    /* Enable timer synchronous start counting function */
    PWM_ENABLE_TIMER_SYNC(PWM0, BIT0, NUCODEGEN_PWM0_SYNCSTART_SRC) ;

#endif /*NUCODEGEN_PWM0_CH0_1_SYNCSTART_ENABLE*/

#if NUCODEGEN_PWM0_CH0_1_COMPLEMATARY_ENABLE

    /* Enable complementary mode */
    PWM0->CTL1 = PWM0->CTL1 | PWM_CTL1_OUTMODE0_Msk;

#if NUCODEGEN_PWM0_CH0_1_DEADTIME_ENABLE

    /* Enable Dead zone and set counter */
    PWM_EnableDeadZone(PWM0, 0, NUCODEGEN_PWM0_CH0_1_DEADTIME_CNT) ;

    /* Set Dead zone clock source */
    PWM_SET_DEADZONE_CLK_SRC(PWM0, 0, NUCODEGEN_PWM0_CH0_1_DEADTIME_CLKSRC) ;

#endif /*NUCODEGEN_PWM0_CH0_1_DEADTIME_ENABLE*/

#endif /*NUCODEGEN_PWM0_CH0_1_COMPLEMATARY_ENABLE*/

#if NUCODEGEN_PWM0_CH0_1_BRAKE_ENABLE

	/* Enable brake function and set the brake source */
    PWM_EnableBrake(PWM0, PWM_CH_0_MASK|PWM_CH_1_MASK, (NUCODEGEN_PWM0_CH1_BRAKE_ACTION<<(1*2))| NUCODEGEN_PWM0_CH0_BRAKE_ACTION, NUCODEGEN_PWM0_CH0_1_BRAKE_SRC, NUCODEGEN_PWM0_CH0_1_BRAKE_DETECT_TYPE) ;

#endif /*NUCODEGEN_PWM0_CH0_1_BRAKE_ENABLE*/

#if (((NUCODEGEN_PWM0_CH0_INT_SEL) & 1) || ((NUCODEGEN_PWM0_CH1_INT_SEL) & 1))

    /* Enable zero interrupt - PWM two channals has one controller  */
    PWM_EnableZeroInt(PWM0, 0) ;

#endif /*NUCODEGEN_PWM0_CH0_INT_SEL*/

#if (((NUCODEGEN_PWM0_CH0_INT_SEL) & 2) || ((NUCODEGEN_PWM0_CH1_INT_SEL) & 2))

    /* Enable period interrupt - PWM two channals has one controller  */
    PWM_EnablePeriodInt(PWM0, 0, 0) ;

#endif /*NUCODEGEN_PWM0_CH0_INT_SEL*/

#if (((NUCODEGEN_PWM0_CH0_INT_SEL) & 16) || ((NUCODEGEN_PWM0_CH1_INT_SEL) & 16))

    /* Enable fault brake interrupt */
    PWM0->INTEN1 |= (1 << NUCODEGEN_PWM0_CH0_1_BRAKE_DETECT_TYPE);

#endif /*NUCODEGEN_PWM0_CH0_INT_SEL*/

#if NUCODEGEN_PWM0_CH0_ENABLE

    /* Set the duty of PWM0 CH0*/
    PWM_SET_CMR(PWM0, 0, NUCODEGEN_PWM0_CH0_CMPDATA);

    /* Set output level of PWM0 CH0*/
    PWM_SET_OUTPUT_LEVEL(PWM0, PWM_CH_0_MASK, NUCODEGEN_PWM0_CH0_WAVEOUT_ZERO, NUCODEGEN_PWM0_CH0_WAVEOUT_CMPUP, NUCODEGEN_PWM0_CH0_WAVEOUT_PERIOD, NUCODEGEN_PWM0_CH0_WAVEOUT_CMPDOWN);

    /* Enable output of PWM0 channel 0 */
    PWM_EnableOutput(PWM0, PWM_CH_0_MASK);

#if NUCODEGEN_PWM0_CH0_ADVANCED

#if (NUCODEGEN_PWM0_CH0_LOAD_MODE == 0)

    /* Period loading mode*/
    PWM_DisableLoadMode(PWM0, 0, PWM_LOAD_MODE_IMMEDIATE|PWM_LOAD_MODE_CENTER) ;

#elif (NUCODEGEN_PWM0_CH0_LOAD_MODE == 1)

    /*Immediate loading mode*/
    PWM_EnableLoadMode(PWM0, 0, PWM_LOAD_MODE_IMMEDIATE) ;

#elif (NUCODEGEN_PWM0_CH0_LOAD_MODE == 2)

    /*Center loading mode*/
    PWM_EnableLoadMode(PWM0, 0, PWM_LOAD_MODE_CENTER) ;

#endif /*NUCODEGEN_PWM0_CH0_LOAD_MODE*/

#if (NUCODEGEN_PWM0_CH0_OTHER_OUTPUT==1)

    /* Enable mask output and output high or low*/
    PWM_SetMaskOutput(PWM0, 0, NUCODEGEN_PWM0_CH0_MASK_DATA);

#elif (NUCODEGEN_PWM0_CH0_OTHER_OUTPUT==2)

    /* Enable inverter output */
    PWM0->POLCTL |= PWM_CH_0_MASK;

#endif /*NUCODEGEN_PWM0_CH0_OTHER_OUTPUT*/

#if NUCODEGEN_PWM0_CH0_TRIGER_EADC_ENABLE

    /* Set trigger EADC and trigger source*/
    PWM_EnableADCTrigger(PWM0, 0, NUCODEGEN_PWM0_CH0_TRIGER_EADCSRC) ;

#endif /*NUCODEGEN_PWM0_CH0_TRIGER_EADC_ENABLE*/

#if ((NUCODEGEN_PWM0_CH0_INT_SEL) & 4)

    /* Enable duty interrupt - count up interrupt */
    PWM_EnableDutyInt(PWM0, 0, PWM_DUTY_INT_UP_COUNT_MATCH_CMP) ;

#endif /*NUCODEGEN_PWM0_CH0_INT_SEL*/

#if ((NUCODEGEN_PWM0_CH0_INT_SEL) & 8)

    /* Enable duty interrupt - count down interrupt */
    PWM_EnableDutyInt(PWM0, 0, PWM_DUTY_INT_DOWN_COUNT_MATCH_CMP) ;

#endif /*NUCODEGEN_PWM0_CH0_INT_SEL*/

#endif /*NUCODEGEN_PWM0_CH0_ADVANCED*/

#endif /*NUCODEGEN_PWM0_CH0_ENABLE*/

#if NUCODEGEN_PWM0_CH1_ENABLE

    /* Set the duty of PWM0 CH1*/
    PWM_SET_CMR(PWM0, 1, NUCODEGEN_PWM0_CH1_CMPDATA);

    /* Set output level of PWM0 CH1*/
    PWM_SET_OUTPUT_LEVEL(PWM0, PWM_CH_1_MASK, NUCODEGEN_PWM0_CH1_WAVEOUT_ZERO, NUCODEGEN_PWM0_CH1_WAVEOUT_CMPUP, NUCODEGEN_PWM0_CH1_WAVEOUT_PERIOD, NUCODEGEN_PWM0_CH1_WAVEOUT_CMPDOWN);

    /* Enable output of PWM0 channel 1 */
    PWM_EnableOutput(PWM0, PWM_CH_1_MASK);

#if NUCODEGEN_PWM0_CH1_ADVANCED

#if (NUCODEGEN_PWM0_CH1_LOAD_MODE == 0)

    /* Period loading mode*/
    PWM_DisableLoadMode(PWM0, 1, PWM_LOAD_MODE_IMMEDIATE|PWM_LOAD_MODE_CENTER) ;

#elif (NUCODEGEN_PWM0_CH1_LOAD_MODE == 1)

    /*Immediate loading mode*/
    PWM_EnableLoadMode(PWM0, 1, PWM_LOAD_MODE_IMMEDIATE) ;

#elif (NUCODEGEN_PWM0_CH1_LOAD_MODE == 2)

    /*Center loading mode*/
    PWM_EnableLoadMode(PWM0, 1, PWM_LOAD_MODE_CENTER) ;

#endif /*NUCODEGEN_PWM0_CH1_LOAD_MODE*/

#if (NUCODEGEN_PWM0_CH1_OTHER_OUTPUT==1)

    /* Enable mask output and output high or low*/
    PWM_SetMaskOutput(PWM0, 1, NUCODEGEN_PWM0_CH1_MASK_DATA);

#elif (NUCODEGEN_PWM0_CH1_OTHER_OUTPUT==2)

    /* Enable inverter output */
    PWM0->POLCTL |= PWM_CH_1_MASK;

#endif /*NUCODEGEN_PWM0_CH1_OTHER_OUTPUT*/

#if NUCODEGEN_PWM0_CH1_TRIGER_EADC_ENABLE

    /* Set trigger EADC and trigger source*/
    PWM_EnableADCTrigger(PWM0, 1, NUCODEGEN_PWM0_CH1_TRIGER_EADCSRC) ;

#endif /*NUCODEGEN_PWM0_CH1_TRIGER_EADC_ENABLE*/

#if ((NUCODEGEN_PWM0_CH1_INT_SEL) & 4)

    /* Enable duty interrupt - count up interrupt */
    PWM_EnableDutyInt(PWM0, 1, PWM_DUTY_INT_UP_COUNT_MATCH_CMP) ;

#endif /*NUCODEGEN_PWM0_CH1_INT_SEL*/

#if ((NUCODEGEN_PWM0_CH1_INT_SEL) & 8)

    /* Enable duty interrupt - count down interrupt */
    PWM_EnableDutyInt(PWM0, 1, PWM_DUTY_INT_DOWN_COUNT_MATCH_CMP) ;

#endif /*NUCODEGEN_PWM0_CH1_INT_SEL*/

#endif /*NUCODEGEN_PWM0_CH1_ADVANCED*/

#endif /*NUCODEGEN_PWM0_CH1_ENABLE*/



#endif /*NUCODEGEN_PWM0_CH0_ENABLE,NUCODEGEN_PWM0_CH1_ENABLE*/

#endif /*NUCODEGEN_PWM0_CH0_1_OUTPUT_FUNC_SETMODE*/

#else

#if (NUCODEGEN_PWM0_CH0_CAP_ENABLE || NUCODEGEN_PWM0_CH1_CAP_ENABLE)

    /* Configure PWM capture and get the nearest unit time */
    PWM_ConfigCaptureChannel(PWM0, 0, NUCODEGEN_PWM0_CH0_1_CAP_UNITTIME, 0);

#if NUCODEGEN_PWM0_CH0_1_CAP_PDMA_ENABLE

#if ((NUCODEGEN_PWM0_CH0_CAP_ADVANCED == 1) && (NUCODEGEN_PWM0_CH1_CAP_ADVANCED == 0))

    /* Enables PDMA transfer of selected channel for PWM capture */
    PWM_EnablePDMA(PWM0, 0, NUCODEGEN_PWM0_CH0_1_CAP_PDMA_FIRST_SEL, NUCODEGEN_PWM0_CH0_1_CAP_PDMA_DATA_SEL) ;

#elif ((NUCODEGEN_PWM0_CH0_CAP_ADVANCED == 0) && (NUCODEGEN_PWM0_CH1_CAP_ADVANCED == 1))

    /* Enables PDMA transfer of selected channel for PWM capture */
    PWM_EnablePDMA(PWM0, 1, NUCODEGEN_PWM0_CH0_1_CAP_PDMA_FIRST_SEL, NUCODEGEN_PWM0_CH0_1_CAP_PDMA_DATA_SEL) ;

#elif ((NUCODEGEN_PWM0_CH0_CAP_ADVANCED == 1) && (NUCODEGEN_PWM0_CH1_CAP_ADVANCED == 1))

    /* Enables PDMA transfer of selected channel for PWM capture */
    PWM_EnablePDMA(PWM0, NUCODEGEN_PWM0_CH0_1_CAP_PDMA_CH_SEL, NUCODEGEN_PWM0_CH0_1_CAP_PDMA_FIRST_SEL, NUCODEGEN_PWM0_CH0_1_CAP_PDMA_DATA_SEL) ;

#endif /*NUCODEGEN_PWM0_CH0_CAP_ADVANCED*/

#endif /*NUCODEGEN_PWM0_CH0_1_CAP_PDMA_ENABLE*/


#if NUCODEGEN_PWM0_CH0_CAP_ENABLE

    /* Set Reload Mode */
    PWM0->CAPCTL |= (NUCODEGEN_PWM0_CH0_CAP_RELOAD)<<PWM_CAPCTL_RCRLDEN0_Pos;

    /* Enable Capture Function for PWM0 channel 0 */
    PWM_EnableCapture(PWM0, PWM_CH_0_MASK);

#if NUCODEGEN_PWM0_CH0_CAP_ADVANCED

#if (NUCODEGEN_PWM0_CH0_CAP_INT_SEL == 1)

    /*Enable rising latch capture interrupt*/
    PWM_EnableCaptureInt(PWM0, 0, PWM_CAPTURE_INT_RISING_LATCH) ;

#elif (NUCODEGEN_PWM0_CH0_CAP_INT_SEL == 2)

    /*Enable falling latch capture interrupt*/
    PWM_EnableCaptureInt(PWM0, 0, PWM_CAPTURE_INT_FALLING_LATCH) ;

#elif (NUCODEGEN_PWM0_CH0_CAP_INT_SEL == 3)

    /*Enable rising and falling latch capture interrupt*/
    PWM_EnableCaptureInt(PWM0, 0, PWM_CAPTURE_INT_RISING_LATCH|PWM_CAPTURE_INT_FALLING_LATCH) ;

#endif /*NUCODEGEN_PWM0_CH0_CAP_INT_SEL*/

#endif /*NUCODEGEN_PWM0_CH0_CAP_ADVANCED*/

#endif /*NUCODEGEN_PWM0_CH0_CAP_ENABLE*/

#if NUCODEGEN_PWM0_CH1_CAP_ENABLE

    /* Set Reload Mode */
    PWM0->CAPCTL |= (NUCODEGEN_PWM0_CH1_CAP_RELOAD)<<PWM_CAPCTL_RCRLDEN1_Pos;

    /* Enable Capture Function for PWM0 channel 1 */
    PWM_EnableCapture(PWM0, PWM_CH_1_MASK);

#if NUCODEGEN_PWM0_CH1_CAP_ADVANCED

#if (NUCODEGEN_PWM0_CH1_CAP_INT_SEL == 1)

    /*Enable rising latch capture interrupt*/
    PWM_EnableCaptureInt(PWM0, 1, PWM_CAPTURE_INT_RISING_LATCH) ;

#elif (NUCODEGEN_PWM0_CH1_CAP_INT_SEL == 2)

    /*Enable falling latch capture interrupt*/
    PWM_EnableCaptureInt(PWM0, 1, PWM_CAPTURE_INT_FALLING_LATCH) ;

#elif (NUCODEGEN_PWM0_CH1_CAP_INT_SEL == 3)

    /*Enable rising and falling latch capture interrupt*/
    PWM_EnableCaptureInt(PWM0, 1, PWM_CAPTURE_INT_RISING_LATCH|PWM_CAPTURE_INT_FALLING_LATCH) ;

#endif /*NUCODEGEN_PWM0_CH1_CAP_INT_SEL*/

#endif /*NUCODEGEN_PWM0_CH1_CAP_ADVANCED*/

#endif /*NUCODEGEN_PWM0_CH1_CAP_ENABLE*/

#endif /*NUCODEGEN_PWM0_CH0_CAP_ENABLE, NUCODEGEN_PWM0_CH1_CAP_ENABLE*/

#endif /*NUCODEGEN_PWM0_FUNC_SEL*/

#endif /*NUCODEGEN_PWM0_CH0CH1*/

#if NUCODEGEN_PWM0_CH2CH3

#if (NUCODEGEN_PWM0_CH2_3_FUNC_SEL==0)

#if (NUCODEGEN_PWM0_CH2_3_OUTPUT_FUNC_SETMODE==0)

#if NUCODEGEN_PWM0_CH2_ENABLE

    /* Set PWM0 channel 2 configuration */
    PWM_ConfigOutputChannel(PWM0, 2, NUCODEGEN_PWM0_CH2_3_FREQ, NUCODEGEN_PWM0_CH2_DUTY);

    /* Enable output of PWM0 channel 2 */
    PWM_EnableOutput(PWM0, PWM_CH_2_MASK);

#endif /*NUCODEGEN_PWM0_CH2_ENABLE*/

#if NUCODEGEN_PWM0_CH3_ENABLE

    /* Set PWM0 channel 3 configuration */
    PWM_ConfigOutputChannel(PWM0, 3, NUCODEGEN_PWM0_CH2_3_FREQ, NUCODEGEN_PWM0_CH3_DUTY);

    /* Enable output of PWM0 channel 3 */
    PWM_EnableOutput(PWM0, PWM_CH_3_MASK);

#endif /*NUCODEGEN_PWM0_CH3_ENABLE*/

#else

#if (NUCODEGEN_PWM0_CH2_ENABLE||NUCODEGEN_PWM0_CH3_ENABLE)

    /* Set PWM0 CH2_3 clock source */
    PWM_SetClockSource(PWM0, 2, NUCODEGEN_PWM0_CH2_3_CLKSRC);

    /* Set PWM0 CH2_3 counter behavior type */
    PWM_SET_ALIGNED_TYPE(PWM0, PWM_CH_2_MASK, NUCODEGEN_PWM0_CH2_3_CNTTYPE);

    /* Set the prescaler of PWM0 CH2_3*/
    PWM_SET_PRESCALER(PWM0, 2, NUCODEGEN_PWM0_CH2_3_PRESCALER);

    /* Set the period of PWM0 CH2_3*/
    PWM_SET_CNR(PWM0, 2, NUCODEGEN_PWM0_CH2_3_PERIOD);

#if NUCODEGEN_PWM0_CH2_3_SYNCSTART_ENABLE

    /* Enable timer synchronous start counting function */
    PWM_ENABLE_TIMER_SYNC(PWM0, BIT2, NUCODEGEN_PWM0_SYNCSTART_SRC) ;

#endif /*NUCODEGEN_PWM0_CH2_3_SYNCSTART_ENABLE*/

#if NUCODEGEN_PWM0_CH2_3_COMPLEMATARY_ENABLE

    /* Enable complementary mode */
    PWM0->CTL1 = PWM0->CTL1 | PWM_CTL1_OUTMODE2_Msk;

#if NUCODEGEN_PWM0_CH2_3_DEADTIME_ENABLE

    /* Enable Dead zone and set counter */
    PWM_EnableDeadZone(PWM0, 2, NUCODEGEN_PWM0_CH2_3_DEADTIME_CNT) ;

    /* Set Dead zone clock source */
    PWM_SET_DEADZONE_CLK_SRC(PWM0, 2, NUCODEGEN_PWM0_CH2_3_DEADTIME_CLKSRC) ;

#endif /*NUCODEGEN_PWM0_CH2_3_DEADTIME_ENABLE*/

#endif /*NUCODEGEN_PWM0_CH2_3_COMPLEMATARY_ENABLE*/


#if NUCODEGEN_PWM0_CH2_3_BRAKE_ENABLE

	/* Enable brake function and set the brake source */
    PWM_EnableBrake(PWM0, PWM_CH_2_MASK|PWM_CH_3_MASK, (NUCODEGEN_PWM0_CH3_BRAKE_ACTION<<(3*2))| (NUCODEGEN_PWM0_CH2_BRAKE_ACTION<<(2*2)), NUCODEGEN_PWM0_CH2_3_BRAKE_SRC, NUCODEGEN_PWM0_CH2_3_BRAKE_DETECT_TYPE) ;

#endif /*NUCODEGEN_PWM0_CH2_3_BRAKE_ENABLE*/

#if (((NUCODEGEN_PWM0_CH2_INT_SEL) & 1) || ((NUCODEGEN_PWM0_CH3_INT_SEL) & 1))

    /* Enable zero interrupt - PWM two channals has one controller  */
    PWM_EnableZeroInt(PWM0, 2) ;

#endif /*NUCODEGEN_PWM0_CH2_INT_SEL*/

#if (((NUCODEGEN_PWM0_CH2_INT_SEL) & 2) || ((NUCODEGEN_PWM0_CH3_INT_SEL) & 2))

    /* Enable period interrupt - PWM two channals has one controller  */
    PWM_EnablePeriodInt(PWM0, 2, 0) ;

#endif /*NUCODEGEN_PWM0_CH2_INT_SEL*/

#if (((NUCODEGEN_PWM0_CH2_INT_SEL) & 16) || ((NUCODEGEN_PWM0_CH3_INT_SEL) & 16))

    /* Enable fault brake interrupt */
    PWM0->INTEN1 |= (0x2 << NUCODEGEN_PWM0_CH2_3_BRAKE_DETECT_TYPE);

#endif /*NUCODEGEN_PWM0_CH2_INT_SEL*/

#if NUCODEGEN_PWM0_CH2_ENABLE

    /* Set the duty of PWM0 CH2*/
    PWM_SET_CMR(PWM0, 2, NUCODEGEN_PWM0_CH2_CMPDATA);

    /* Set output level of PWM0 CH2*/
    PWM_SET_OUTPUT_LEVEL(PWM0, PWM_CH_2_MASK, NUCODEGEN_PWM0_CH2_WAVEOUT_ZERO, NUCODEGEN_PWM0_CH2_WAVEOUT_CMPUP, NUCODEGEN_PWM0_CH2_WAVEOUT_PERIOD, NUCODEGEN_PWM0_CH2_WAVEOUT_CMPDOWN);

    /* Enable output of PWM0 channel 2 */
    PWM_EnableOutput(PWM0, PWM_CH_2_MASK);

#if NUCODEGEN_PWM0_CH2_ADVANCED

#if (NUCODEGEN_PWM0_CH2_LOAD_MODE == 0)

    /* Period loading mode*/
    PWM_DisableLoadMode(PWM0, 2, PWM_LOAD_MODE_IMMEDIATE|PWM_LOAD_MODE_CENTER) ;

#elif (NUCODEGEN_PWM0_CH2_LOAD_MODE == 1)

    /*Immediate loading mode*/
    PWM_EnableLoadMode(PWM0, 2, PWM_LOAD_MODE_IMMEDIATE) ;

#elif (NUCODEGEN_PWM0_CH2_LOAD_MODE == 2)

    /*Center loading mode*/
    PWM_EnableLoadMode(PWM0, 2, PWM_LOAD_MODE_CENTER) ;

#endif /*NUCODEGEN_PWM0_CH2_LOAD_MODE*/

#if (NUCODEGEN_PWM0_CH2_OTHER_OUTPUT==1)

    /* Enable mask output and output high or low*/
    PWM_SetMaskOutput(PWM0, 2, NUCODEGEN_PWM0_CH2_MASK_DATA);

#elif (NUCODEGEN_PWM0_CH2_OTHER_OUTPUT==2)

    /* Enable inverter output */
    PWM0->POLCTL |= PWM_CH_2_MASK;

#endif /*NUCODEGEN_PWM0_CH2_OTHER_OUTPUT*/

#if NUCODEGEN_PWM0_CH2_TRIGER_EADC_ENABLE

    /* Set trigger EADC and trigger source*/
    PWM_EnableADCTrigger(PWM0, 2, NUCODEGEN_PWM0_CH2_TRIGER_EADCSRC) ;

#endif /*NUCODEGEN_PWM0_CH2_TRIGER_EADC_ENABLE*/

#if ((NUCODEGEN_PWM0_CH2_INT_SEL) & 4)

    /* Enable duty interrupt - count up interrupt */
    PWM_EnableDutyInt(PWM0, 2, PWM_DUTY_INT_UP_COUNT_MATCH_CMP) ;

#endif /*NUCODEGEN_PWM0_CH2_INT_SEL*/

#if ((NUCODEGEN_PWM0_CH2_INT_SEL) & 8)

    /* Enable duty interrupt - count down interrupt */
    PWM_EnableDutyInt(PWM0, 2, PWM_DUTY_INT_DOWN_COUNT_MATCH_CMP) ;

#endif /*NUCODEGEN_PWM0_CH2_INT_SEL*/

#endif /*NUCODEGEN_PWM0_CH2_ADVANCED*/

#endif /*NUCODEGEN_PWM0_CH2_ENABLE*/

#if NUCODEGEN_PWM0_CH3_ENABLE

    /* Set the duty of PWM0 CH3*/
    PWM_SET_CMR(PWM0, 3, NUCODEGEN_PWM0_CH3_CMPDATA);

    /* Set output level of PWM0 CH3*/
    PWM_SET_OUTPUT_LEVEL(PWM0, PWM_CH_3_MASK, NUCODEGEN_PWM0_CH3_WAVEOUT_ZERO, NUCODEGEN_PWM0_CH3_WAVEOUT_CMPUP, NUCODEGEN_PWM0_CH3_WAVEOUT_PERIOD, NUCODEGEN_PWM0_CH3_WAVEOUT_CMPDOWN);

    /* Enable output of PWM0 channel 3 */
    PWM_EnableOutput(PWM0, PWM_CH_3_MASK);

#if NUCODEGEN_PWM0_CH3_ADVANCED

#if (NUCODEGEN_PWM0_CH3_LOAD_MODE == 0)

    /* Period loading mode*/
    PWM_DisableLoadMode(PWM0, 3, PWM_LOAD_MODE_IMMEDIATE|PWM_LOAD_MODE_CENTER) ;

#elif (NUCODEGEN_PWM0_CH3_LOAD_MODE == 1)

    /*Immediate loading mode*/
    PWM_EnableLoadMode(PWM0, 3, PWM_LOAD_MODE_IMMEDIATE) ;

#elif (NUCODEGEN_PWM0_CH3_LOAD_MODE == 2)

    /*Center loading mode*/
    PWM_EnableLoadMode(PWM0, 3, PWM_LOAD_MODE_CENTER) ;

#endif /*NUCODEGEN_PWM0_CH3_LOAD_MODE*/

#if (NUCODEGEN_PWM0_CH3_OTHER_OUTPUT==1)

    /* Enable mask output and output high or low*/
    PWM_SetMaskOutput(PWM0, 3, NUCODEGEN_PWM0_CH3_MASK_DATA);

#elif (NUCODEGEN_PWM0_CH3_OTHER_OUTPUT==2)

    /* Enable inverter output */
    PWM0->POLCTL |= PWM_CH_3_MASK;

#endif /*NUCODEGEN_PWM0_CH3_OTHER_OUTPUT*/

#if NUCODEGEN_PWM0_CH3_TRIGER_EADC_ENABLE

    /* Set trigger EADC and trigger source*/
    PWM_EnableADCTrigger(PWM0, 3, NUCODEGEN_PWM0_CH3_TRIGER_EADCSRC) ;

#endif /*NUCODEGEN_PWM0_CH3_TRIGER_EADC_ENABLE*/

#if ((NUCODEGEN_PWM0_CH3_INT_SEL) & 4)

    /* Enable duty interrupt - count up interrupt */
    PWM_EnableDutyInt(PWM0, 3, PWM_DUTY_INT_UP_COUNT_MATCH_CMP) ;

#endif /*NUCODEGEN_PWM0_CH3_INT_SEL*/

#if ((NUCODEGEN_PWM0_CH3_INT_SEL) & 8)

    /* Enable duty interrupt - count down interrupt */
    PWM_EnableDutyInt(PWM0, 3, PWM_DUTY_INT_DOWN_COUNT_MATCH_CMP) ;

#endif /*NUCODEGEN_PWM0_CH3_INT_SEL*/

#endif /*NUCODEGEN_PWM0_CH3_ADVANCED*/

#endif /*NUCODEGEN_PWM0_CH3_ENABLE*/

#endif /*NUCODEGEN_PWM0_CH2_ENABLE,NUCODEGEN_PWM0_CH3_ENABLE*/

#endif /*NUCODEGEN_PWM0_CH2_3_OUTPUT_FUNC_SETMODE*/

#else

#if (NUCODEGEN_PWM0_CH2_CAP_ENABLE || NUCODEGEN_PWM0_CH3_CAP_ENABLE)

    /* Configure PWM capture and get the nearest unit time */
    PWM_ConfigCaptureChannel(PWM0, 2, NUCODEGEN_PWM0_CH2_3_CAP_UNITTIME, 0);

#if NUCODEGEN_PWM0_CH2_3_CAP_PDMA_ENABLE

#if ((NUCODEGEN_PWM0_CH2_CAP_ADVANCED == 1) && (NUCODEGEN_PWM0_CH3_CAP_ADVANCED == 0))

    /* Enables PDMA transfer of selected channel for PWM capture */
    PWM_EnablePDMA(PWM0, 2, NUCODEGEN_PWM0_CH2_3_CAP_PDMA_FIRST_SEL, NUCODEGEN_PWM0_CH2_3_CAP_PDMA_DATA_SEL) ;

#elif ((NUCODEGEN_PWM0_CH2_CAP_ADVANCED == 0) && (NUCODEGEN_PWM0_CH3_CAP_ADVANCED == 1))

    /* Enables PDMA transfer of selected channel for PWM capture */
    PWM_EnablePDMA(PWM0, 3, NUCODEGEN_PWM0_CH2_3_CAP_PDMA_FIRST_SEL, NUCODEGEN_PWM0_CH2_3_CAP_PDMA_DATA_SEL) ;

#elif ((NUCODEGEN_PWM0_CH2_CAP_ADVANCED == 1) && (NUCODEGEN_PWM0_CH3_CAP_ADVANCED == 1))

    /* Enables PDMA transfer of selected channel for PWM capture */
    PWM_EnablePDMA(PWM0, NUCODEGEN_PWM0_CH2_3_CAP_PDMA_CH_SEL, NUCODEGEN_PWM0_CH2_3_CAP_PDMA_FIRST_SEL, NUCODEGEN_PWM0_CH2_3_CAP_PDMA_DATA_SEL) ;

#endif /*NUCODEGEN_PWM0_CH2_CAP_ADVANCED*/

#endif /*NUCODEGEN_PWM0_CH2_3_CAP_PDMA_ENABLE*/


#if NUCODEGEN_PWM0_CH2_CAP_ENABLE

    /* Set Reload Mode */
    PWM0->CAPCTL |= (NUCODEGEN_PWM0_CH2_CAP_RELOAD)<<PWM_CAPCTL_RCRLDEN2_Pos;

    /* Enable Capture Function for PWM0 channel 2 */
    PWM_EnableCapture(PWM0, PWM_CH_2_MASK);

#if NUCODEGEN_PWM0_CH2_CAP_ADVANCED

#if (NUCODEGEN_PWM0_CH2_CAP_INT_SEL == 1)

    /*Enable rising latch capture interrupt*/
    PWM_EnableCaptureInt(PWM0, 2, PWM_CAPTURE_INT_RISING_LATCH) ;

#elif (NUCODEGEN_PWM0_CH2_CAP_INT_SEL == 2)

    /*Enable falling latch capture interrupt*/
    PWM_EnableCaptureInt(PWM0, 2, PWM_CAPTURE_INT_FALLING_LATCH) ;

#elif (NUCODEGEN_PWM0_CH2_CAP_INT_SEL == 3)

    /*Enable rising and falling latch capture interrupt*/
    PWM_EnableCaptureInt(PWM0, 2, PWM_CAPTURE_INT_RISING_LATCH|PWM_CAPTURE_INT_FALLING_LATCH) ;

#endif /*NUCODEGEN_PWM0_CH2_CAP_INT_SEL*/

#endif /*NUCODEGEN_PWM0_CH2_CAP_ADVANCED*/

#endif /*NUCODEGEN_PWM0_CH2_CAP_ENABLE*/

#if NUCODEGEN_PWM0_CH3_CAP_ENABLE

    /* Set Reload Mode */
    PWM0->CAPCTL |= (NUCODEGEN_PWM0_CH3_CAP_RELOAD)<<PWM_CAPCTL_RCRLDEN3_Pos;

    /* Enable Capture Function for PWM0 channel 3 */
    PWM_EnableCapture(PWM0, PWM_CH_3_MASK);

#if NUCODEGEN_PWM0_CH3_CAP_ADVANCED

#if (NUCODEGEN_PWM0_CH3_CAP_INT_SEL == 1)

    /*Enable rising latch capture interrupt*/
    PWM_EnableCaptureInt(PWM0, 3, PWM_CAPTURE_INT_RISING_LATCH) ;

#elif (NUCODEGEN_PWM0_CH3_CAP_INT_SEL == 2)

    /*Enable falling latch capture interrupt*/
    PWM_EnableCaptureInt(PWM0, 3, PWM_CAPTURE_INT_FALLING_LATCH) ;

#elif (NUCODEGEN_PWM0_CH3_CAP_INT_SEL == 3)

    /*Enable rising and falling latch capture interrupt*/
    PWM_EnableCaptureInt(PWM0, 3, PWM_CAPTURE_INT_RISING_LATCH|PWM_CAPTURE_INT_FALLING_LATCH) ;

#endif /*NUCODEGEN_PWM0_CH3_CAP_INT_SEL*/

#endif /*NUCODEGEN_PWM0_CH3_CAP_ADVANCED*/

#endif /*NUCODEGEN_PWM0_CH3_CAP_ENABLE*/

#endif /*NUCODEGEN_PWM0_CH2_CAP_ENABLE, NUCODEGEN_PWM0_CH3_CAP_ENABLE*/

#endif /*NUCODEGEN_PWM0_CH2_3_FUNC_SEL*/

#endif /*NUCODEGEN_PWM0_CH2CH3*/

#if NUCODEGEN_PWM0_CH4CH5

#if (NUCODEGEN_PWM0_CH4_5_FUNC_SEL==0)

#if (NUCODEGEN_PWM0_CH4_5_OUTPUT_FUNC_SETMODE==0)

#if NUCODEGEN_PWM0_CH4_ENABLE

    /* Set PWM0 channel 4 configuration */
    PWM_ConfigOutputChannel(PWM0, 4, NUCODEGEN_PWM0_CH4_5_FREQ, NUCODEGEN_PWM0_CH4_DUTY);

    /* Enable output of PWM0 channel 4 */
    PWM_EnableOutput(PWM0, PWM_CH_4_MASK);

#endif /*NUCODEGEN_PWM0_CH4_ENABLE*/

#if NUCODEGEN_PWM0_CH5_ENABLE

    /* Set PWM0 channel 5 configuration */
    PWM_ConfigOutputChannel(PWM0, 5, NUCODEGEN_PWM0_CH4_5_FREQ, NUCODEGEN_PWM0_CH5_DUTY);

    /* Enable output of PWM0 channel 5 */
    PWM_EnableOutput(PWM0, PWM_CH_5_MASK);

#endif /*NUCODEGEN_PWM0_CH5_ENABLE*/

#else

#if (NUCODEGEN_PWM0_CH4_ENABLE||NUCODEGEN_PWM0_CH5_ENABLE)

    /* Set PWM0 CH4_5 clock source */
    PWM_SetClockSource(PWM0, 4, NUCODEGEN_PWM0_CH4_5_CLKSRC);

    /* Set PWM0 CH4_5 counter behavior type */
    PWM_SET_ALIGNED_TYPE(PWM0, PWM_CH_4_MASK, NUCODEGEN_PWM0_CH4_5_CNTTYPE);

    /* Set the prescaler of PWM0 CH4_5*/
    PWM_SET_PRESCALER(PWM0, 4, NUCODEGEN_PWM0_CH4_5_PRESCALER);

    /* Set the period of PWM0 CH4_5*/
    PWM_SET_CNR(PWM0, 4, NUCODEGEN_PWM0_CH4_5_PERIOD);

#if NUCODEGEN_PWM0_CH4_5_SYNCSTART_ENABLE

    /* Enable timer synchronous start counting function */
    PWM_ENABLE_TIMER_SYNC(PWM0, BIT4, NUCODEGEN_PWM0_SYNCSTART_SRC) ;

#endif /*NUCODEGEN_PWM0_CH4_5_SYNCSTART_ENABLE*/

#if NUCODEGEN_PWM0_CH4_5_COMPLEMATARY_ENABLE

    /* Enable complementary mode */
    PWM0->CTL1 = PWM0->CTL1 | PWM_CTL1_OUTMODE4_Msk;

#if NUCODEGEN_PWM0_CH4_5_DEADTIME_ENABLE

    /* Enable Dead zone and set counter */
    PWM_EnableDeadZone(PWM0, 4, NUCODEGEN_PWM0_CH4_5_DEADTIME_CNT) ;

    /* Set Dead zone clock source */
    PWM_SET_DEADZONE_CLK_SRC(PWM0, 4, NUCODEGEN_PWM0_CH4_5_DEADTIME_CLKSRC) ;

#endif /*NUCODEGEN_PWM0_CH4_5_DEADTIME_ENABLE*/

#endif /*NUCODEGEN_PWM0_CH4_5_COMPLEMATARY_ENABLE*/

#if NUCODEGEN_PWM0_CH4_5_BRAKE_ENABLE

	/* Enable brake function and set the brake source */
    PWM_EnableBrake(PWM0, PWM_CH_4_MASK|PWM_CH_5_MASK, (NUCODEGEN_PWM0_CH5_BRAKE_ACTION<<(5*2))| (NUCODEGEN_PWM0_CH4_BRAKE_ACTION<<(4*2)), NUCODEGEN_PWM0_CH4_5_BRAKE_SRC, NUCODEGEN_PWM0_CH4_5_BRAKE_DETECT_TYPE) ;

#endif /*NUCODEGEN_PWM0_CH0_1_BRAKE_ENABLE*/

#if (((NUCODEGEN_PWM0_CH4_INT_SEL) & 1) || ((NUCODEGEN_PWM0_CH5_INT_SEL) & 1))

    /* Enable zero interrupt - PWM two channals has one controller  */
    PWM_EnableZeroInt(PWM0, 4) ;

#endif /*NUCODEGEN_PWM0_CH4_INT_SEL*/

#if (((NUCODEGEN_PWM0_CH4_INT_SEL) & 2) || ((NUCODEGEN_PWM0_CH5_INT_SEL) & 2))

    /* Enable period interrupt - PWM two channals has one controller  */
    PWM_EnablePeriodInt(PWM0, 4, 0) ;

#endif /*NUCODEGEN_PWM0_CH4_INT_SEL*/

#if (((NUCODEGEN_PWM0_CH0_INT_SEL) & 16) || ((NUCODEGEN_PWM0_CH1_INT_SEL) & 16))

    /* Enable fault brake interrupt */
    PWM0->INTEN1 |= (0x4 << NUCODEGEN_PWM0_CH4_5_BRAKE_DETECT_TYPE);

#endif /*NUCODEGEN_PWM0_CH0_INT_SEL*/

#if NUCODEGEN_PWM0_CH4_ENABLE

    /* Set the duty of PWM0 CH4*/
    PWM_SET_CMR(PWM0, 4, NUCODEGEN_PWM0_CH4_CMPDATA);

    /* Set output level of PWM0 CH4*/
    PWM_SET_OUTPUT_LEVEL(PWM0, PWM_CH_4_MASK, NUCODEGEN_PWM0_CH4_WAVEOUT_ZERO, NUCODEGEN_PWM0_CH4_WAVEOUT_CMPUP, NUCODEGEN_PWM0_CH4_WAVEOUT_PERIOD, NUCODEGEN_PWM0_CH4_WAVEOUT_CMPDOWN);

    /* Enable output of PWM0 channel 4 */
    PWM_EnableOutput(PWM0, PWM_CH_4_MASK);

#if NUCODEGEN_PWM0_CH4_ADVANCED

#if (NUCODEGEN_PWM0_CH4_LOAD_MODE == 0)

    /* Period loading mode*/
    PWM_DisableLoadMode(PWM0, 4, PWM_LOAD_MODE_IMMEDIATE|PWM_LOAD_MODE_CENTER) ;

#elif (NUCODEGEN_PWM0_CH4_LOAD_MODE == 1)

    /*Immediate loading mode*/
    PWM_EnableLoadMode(PWM0, 4, PWM_LOAD_MODE_IMMEDIATE) ;

#elif (NUCODEGEN_PWM0_CH4_LOAD_MODE == 2)

    /*Center loading mode*/
    PWM_EnableLoadMode(PWM0, 4, PWM_LOAD_MODE_CENTER) ;

#endif /*NUCODEGEN_PWM0_CH4_LOAD_MODE*/

#if (NUCODEGEN_PWM0_CH4_OTHER_OUTPUT==1)

    /* Enable mask output and output high or low*/
    PWM_SetMaskOutput(PWM0, 4, NUCODEGEN_PWM0_CH4_MASK_DATA);

#elif (NUCODEGEN_PWM0_CH4_OTHER_OUTPUT==2)

    /* Enable inverter output */
    PWM0->POLCTL |= PWM_CH_4_MASK;

#endif /*NUCODEGEN_PWM0_CH4_OTHER_OUTPUT*/

#if NUCODEGEN_PWM0_CH4_TRIGER_EADC_ENABLE

    /* Set trigger EADC and trigger source*/
    PWM_EnableADCTrigger(PWM0, 4, NUCODEGEN_PWM0_CH4_TRIGER_EADCSRC) ;

#endif /*NUCODEGEN_PWM0_CH4_TRIGER_EADC_ENABLE*/

#if ((NUCODEGEN_PWM0_CH4_INT_SEL) & 4)

    /* Enable duty interrupt - count up interrupt */
    PWM_EnableDutyInt(PWM0, 4, PWM_DUTY_INT_UP_COUNT_MATCH_CMP) ;

#endif /*NUCODEGEN_PWM0_CH4_INT_SEL*/

#if ((NUCODEGEN_PWM0_CH4_INT_SEL) & 8)

    /* Enable duty interrupt - count down interrupt */
    PWM_EnableDutyInt(PWM0, 4, PWM_DUTY_INT_DOWN_COUNT_MATCH_CMP) ;

#endif /*NUCODEGEN_PWM0_CH4_INT_SEL*/

#endif /*NUCODEGEN_PWM0_CH4_ADVANCED*/

#endif /*NUCODEGEN_PWM0_CH4_ENABLE*/

#if NUCODEGEN_PWM0_CH5_ENABLE

    /* Set the duty of PWM0 CH5*/
    PWM_SET_CMR(PWM0, 5, NUCODEGEN_PWM0_CH5_CMPDATA);

    /* Set output level of PWM0 CH5*/
    PWM_SET_OUTPUT_LEVEL(PWM0, PWM_CH_5_MASK, NUCODEGEN_PWM0_CH5_WAVEOUT_ZERO, NUCODEGEN_PWM0_CH5_WAVEOUT_CMPUP, NUCODEGEN_PWM0_CH5_WAVEOUT_PERIOD, NUCODEGEN_PWM0_CH5_WAVEOUT_CMPDOWN);

    /* Enable output of PWM0 channel 5 */
    PWM_EnableOutput(PWM0, PWM_CH_5_MASK);

#if NUCODEGEN_PWM0_CH5_ADVANCED

#if (NUCODEGEN_PWM0_CH5_LOAD_MODE == 0)

    /* Period loading mode*/
    PWM_DisableLoadMode(PWM0, 5, PWM_LOAD_MODE_IMMEDIATE|PWM_LOAD_MODE_CENTER) ;

#elif (NUCODEGEN_PWM0_CH5_LOAD_MODE == 1)

    /*Center loading mode*/
    PWM_EnableLoadMode(PWM0, 5, PWM_LOAD_MODE_IMMEDIATE) ;

#elif (NUCODEGEN_PWM0_CH5_LOAD_MODE == 2)

    /*Center loading mode*/
    PWM_EnableLoadMode(PWM0, 5, PWM_LOAD_MODE_CENTER) ;

#endif /*NUCODEGEN_PWM0_CH5_LOAD_MODE*/

#if (NUCODEGEN_PWM0_CH5_OTHER_OUTPUT==1)

    /* Enable mask output and output high or low*/
    PWM_SetMaskOutput(PWM0, 5, NUCODEGEN_PWM0_CH5_MASK_DATA);

#elif (NUCODEGEN_PWM0_CH5_OTHER_OUTPUT==2)

    /* Enable inverter output */
    PWM0->POLCTL |= PWM_CH_5_MASK;

#endif /*NUCODEGEN_PWM0_CH5_OTHER_OUTPUT*/

#if NUCODEGEN_PWM0_CH5_TRIGER_EADC_ENABLE

    /* Set trigger EADC and trigger source*/
    PWM_EnableADCTrigger(PWM0, 5, NUCODEGEN_PWM0_CH5_TRIGER_EADCSRC) ;

#endif /*NUCODEGEN_PWM0_CH5_TRIGER_EADC_ENABLE*/

#if ((NUCODEGEN_PWM0_CH5_INT_SEL) & 4)

    /* Enable duty interrupt - count up interrupt */
    PWM_EnableDutyInt(PWM0, 5, PWM_DUTY_INT_UP_COUNT_MATCH_CMP) ;

#endif /*NUCODEGEN_PWM0_CH5_INT_SEL*/

#if ((NUCODEGEN_PWM0_CH5_INT_SEL) & 8)

    /* Enable duty interrupt - count down interrupt */
    PWM_EnableDutyInt(PWM0, 5, PWM_DUTY_INT_DOWN_COUNT_MATCH_CMP) ;

#endif /*NUCODEGEN_PWM0_CH5_INT_SEL*/

#endif /*NUCODEGEN_PWM0_CH5_ADVANCED*/

#endif /*NUCODEGEN_PWM0_CH5_ENABLE*/

#endif

#endif /*NUCODEGEN_PWM0_CH4_5_OUTPUT_FUNC_SETMODE*/

#else

#if (NUCODEGEN_PWM0_CH4_CAP_ENABLE || NUCODEGEN_PWM0_CH5_CAP_ENABLE)

    /* Configure PWM capture and get the nearest unit time */
    PWM_ConfigCaptureChannel(PWM0, 4, NUCODEGEN_PWM0_CH4_5_CAP_UNITTIME, 0);

#if NUCODEGEN_PWM0_CH4_5_CAP_PDMA_ENABLE

#if ((NUCODEGEN_PWM0_CH4_CAP_ADVANCED == 1) && (NUCODEGEN_PWM0_CH5_CAP_ADVANCED == 0))

    /* Enables PDMA transfer of selected channel for PWM capture */
    PWM_EnablePDMA(PWM0, 4, NUCODEGEN_PWM0_CH4_5_CAP_PDMA_FIRST_SEL, NUCODEGEN_PWM0_CH4_5_CAP_PDMA_DATA_SEL) ;

#elif ((NUCODEGEN_PWM0_CH4_CAP_ADVANCED == 0) && (NUCODEGEN_PWM0_CH5_CAP_ADVANCED == 1))

    /* Enables PDMA transfer of selected channel for PWM capture */
    PWM_EnablePDMA(PWM0, 5, NUCODEGEN_PWM0_CH4_5_CAP_PDMA_FIRST_SEL, NUCODEGEN_PWM0_CH4_5_CAP_PDMA_DATA_SEL) ;

#elif ((NUCODEGEN_PWM0_CH4_CAP_ADVANCED == 1) && (NUCODEGEN_PWM0_CH5_CAP_ADVANCED == 1))

    /* Enables PDMA transfer of selected channel for PWM capture */
    PWM_EnablePDMA(PWM0, NUCODEGEN_PWM0_CH4_5_CAP_PDMA_CH_SEL, NUCODEGEN_PWM0_CH4_5_CAP_PDMA_FIRST_SEL, NUCODEGEN_PWM0_CH4_5_CAP_PDMA_DATA_SEL) ;

#endif /*NUCODEGEN_PWM0_CH4_CAP_ADVANCED*/

#endif /*NUCODEGEN_PWM0_CH4_5_CAP_PDMA_ENABLE*/


#if NUCODEGEN_PWM0_CH4_CAP_ENABLE

    /* Set Reload Mode */
    PWM0->CAPCTL |= (NUCODEGEN_PWM0_CH4_CAP_RELOAD)<<PWM_CAPCTL_RCRLDEN4_Pos;

    /* Enable Capture Function for PWM0 channel 4 */
    PWM_EnableCapture(PWM0, PWM_CH_4_MASK);

#if NUCODEGEN_PWM0_CH4_CAP_ADVANCED

#if (NUCODEGEN_PWM0_CH4_CAP_INT_SEL == 1)

    /*Enable rising latch capture interrupt*/
    PWM_EnableCaptureInt(PWM0, 4, PWM_CAPTURE_INT_RISING_LATCH) ;

#elif (NUCODEGEN_PWM0_CH4_CAP_INT_SEL == 2)

    /*Enable falling latch capture interrupt*/
    PWM_EnableCaptureInt(PWM0, 4, PWM_CAPTURE_INT_FALLING_LATCH) ;

#elif (NUCODEGEN_PWM0_CH4_CAP_INT_SEL == 3)

    /*Enable rising and falling latch capture interrupt*/
    PWM_EnableCaptureInt(PWM0, 4, PWM_CAPTURE_INT_RISING_LATCH|PWM_CAPTURE_INT_FALLING_LATCH) ;

#endif /*NUCODEGEN_PWM0_CH4_CAP_INT_SEL*/

#endif /*NUCODEGEN_PWM0_CH4_CAP_ADVANCED*/

#endif /*NUCODEGEN_PWM0_CH4_CAP_ENABLE*/

#if NUCODEGEN_PWM0_CH5_CAP_ENABLE

    /* Set Reload Mode */
    PWM0->CAPCTL |= (NUCODEGEN_PWM0_CH5_CAP_RELOAD)<<PWM_CAPCTL_RCRLDEN5_Pos;

    /* Enable Capture Function for PWM0 channel 5 */
    PWM_EnableCapture(PWM0, PWM_CH_5_MASK);

#if NUCODEGEN_PWM0_CH5_CAP_ADVANCED

#if (NUCODEGEN_PWM0_CH5_CAP_INT_SEL == 1)

    /*Enable rising latch capture interrupt*/
    PWM_EnableCaptureInt(PWM0, 5, PWM_CAPTURE_INT_RISING_LATCH) ;

#elif (NUCODEGEN_PWM0_CH5_CAP_INT_SEL == 2)

    /*Enable falling latch capture interrupt*/
    PWM_EnableCaptureInt(PWM0, 5, PWM_CAPTURE_INT_FALLING_LATCH) ;

#elif (NUCODEGEN_PWM0_CH5_CAP_INT_SEL == 3)

    /*Enable rising and falling latch capture interrupt*/
    PWM_EnableCaptureInt(PWM0, 5, PWM_CAPTURE_INT_RISING_LATCH|PWM_CAPTURE_INT_FALLING_LATCH) ;

#endif /*NUCODEGEN_PWM0_CH5_CAP_INT_SEL*/

#endif /*NUCODEGEN_PWM0_CH5_CAP_ADVANCED*/

#endif /*NUCODEGEN_PWM0_CH5_CAP_ENABLE*/

#endif /*NUCODEGEN_PWM0_CH4_CAP_ENABLE, NUCODEGEN_PWM0_CH5_CAP_ENABLE*/

#endif /*NUCODEGEN_PWM0_CH4_5_FUNC_SEL*/

#endif /*NUCODEGEN_PWM0_CH4CH5*/

#if NUCODEGEN_PWM0_CH0_1_BRAKE_PIN_INV

    /* Enable PWM brake noise filter */
    PWM_EnableBrakePinInv(PWM0, NUCODEGEN_PWM0_CH0_1_BRAKE_SRC);

#elif NUCODEGEN_PWM0_CH2_3_BRAKE_PIN_INV

    /* Enable PWM brake noise filter */
    PWM_EnableBrakePinInv(PWM0, NUCODEGEN_PWM0_CH2_3_BRAKE_SRC);

#elif NUCODEGEN_PWM0_CH4_5_BRAKE_PIN_INV

    /* Enable PWM brake noise filter */
    PWM_EnableBrakePinInv(PWM0, NUCODEGEN_PWM0_CH4_5_BRAKE_SRC);

#endif /*NUCODEGEN_PWM1_CH0_1_BRAKE_PIN_INV*/

#if NUCODEGEN_PWM0_CH0_1_BRAKE_FILTER_ENABLE

    /* Enable PWM brake noise filter */
    PWM_EnableBrakeFilter(PWM0, NUCODEGEN_PWM0_CH0_1_BRAKE_SRC|NUCODEGEN_PWM0_CH2_3_BRAKE_SRC|NUCODEGEN_PWM0_CH4_5_BRAKE_SRC, NUCODEGEN_PWM0_CH0_1_BRAKE_FILTER_CNT, NUCODEGEN_PWM0_CH0_1_BRAKE_FILTER_CLK);

#elif NUCODEGEN_PWM0_CH2_3_BRAKE_FILTER_ENABLE

    /* Enable PWM brake noise filter */
    PWM_EnableBrakeFilter(PWM0, NUCODEGEN_PWM0_CH2_3_BRAKE_SRC|NUCODEGEN_PWM0_CH4_5_BRAKE_SRC, NUCODEGEN_PWM0_CH2_3_BRAKE_FILTER_CNT, NUCODEGEN_PWM0_CH2_3_BRAKE_FILTER_CLK);

#elif NUCODEGEN_PWM0_CH4_5_BRAKE_FILTER_ENABLE

    /* Enable PWM brake noise filter */
    PWM_EnableBrakeFilter(PWM0, NUCODEGEN_PWM0_CH4_5_BRAKE_SRC, NUCODEGEN_PWM0_CH4_5_BRAKE_FILTER_CNT, NUCODEGEN_PWM0_CH4_5_BRAKE_FILTER_CLK);

#endif /*NUCODEGEN_PWM0_CH0_1_BRAKE_FILTER_ENABLE*/

}

#endif //NUCODEGEN_PWM0

#if (NUCODEGEN_PWM1)
void PWM1_Init()
{

#if NUCODEGEN_PWM1_CH0CH1

#if (NUCODEGEN_PWM1_CH0_1_FUNC_SEL==0)

#if (NUCODEGEN_PWM1_CH0_1_OUTPUT_FUNC_SETMODE==0)

#if NUCODEGEN_PWM1_CH0_ENABLE

    /* Set PWM1 channel 0 configuration */
    PWM_ConfigOutputChannel(PWM1, 0, NUCODEGEN_PWM1_CH0_1_FREQ, NUCODEGEN_PWM1_CH0_DUTY);

    /* Enable output of PWM1 channel 0 */
    PWM_EnableOutput(PWM1, PWM_CH_0_MASK);

#endif /*NUCODEGEN_PWM1_CH0_ENABLE*/

#if NUCODEGEN_PWM1_CH1_ENABLE

    /* Set PWM1 channel 1 configuration */
    PWM_ConfigOutputChannel(PWM1, 1, NUCODEGEN_PWM1_CH0_1_FREQ, NUCODEGEN_PWM1_CH1_DUTY);

    /* Enable output of PWM1 channel 1 */
    PWM_EnableOutput(PWM1, PWM_CH_1_MASK);

#endif /*NUCODEGEN_PWM1_CH1_ENABLE*/

#else

#if (NUCODEGEN_PWM1_CH0_ENABLE||NUCODEGEN_PWM1_CH1_ENABLE)

    /* Set PWM1 CH0_1 clock source */
    PWM_SetClockSource(PWM1, 0, NUCODEGEN_PWM1_CH0_1_CLKSRC);

    /* Set PWM1 CH0_1 counter behavior type */
    PWM_SET_ALIGNED_TYPE(PWM1, PWM_CH_0_MASK, NUCODEGEN_PWM1_CH0_1_CNTTYPE);

    /* Set the prescaler of PWM1 CH0_1*/
    PWM_SET_PRESCALER(PWM1, 0,NUCODEGEN_PWM1_CH0_1_PRESCALER);

    /* Set the period of PWM1 CH0_1*/
    PWM_SET_CNR(PWM1, 0, NUCODEGEN_PWM1_CH0_1_PERIOD);

#if NUCODEGEN_PWM1_CH0_1_SYNCSTART_ENABLE

    /* Enable timer synchronous start counting function */
    PWM_ENABLE_TIMER_SYNC(PWM1, BIT0, NUCODEGEN_PWM1_SYNCSTART_SRC) ;

#endif /*NUCODEGEN_PWM1_CH0_1_SYNCSTART_ENABLE*/

#if NUCODEGEN_PWM1_CH0_1_COMPLEMATARY_ENABLE

    /* Enable complementary mode */
    PWM1->CTL1 = PWM1->CTL1 | PWM_CTL1_OUTMODE0_Msk;

#if NUCODEGEN_PWM1_CH0_1_DEADTIME_ENABLE

    /* Enable Dead zone and set counter */
    PWM_EnableDeadZone(PWM1, 0, NUCODEGEN_PWM1_CH0_1_DEADTIME_CNT) ;

    /* Set Dead zone clock source */
    PWM_SET_DEADZONE_CLK_SRC(PWM1, 0, NUCODEGEN_PWM1_CH0_1_DEADTIME_CLKSRC) ;

#endif /*NUCODEGEN_PWM1_CH0_1_DEADTIME_ENABLE*/

#endif /*NUCODEGEN_PWM1_CH0_1_COMPLEMATARY_ENABLE*/

#if NUCODEGEN_PWM1_CH0_1_BRAKE_ENABLE

	/* Enable brake function and set the brake source */
    PWM_EnableBrake(PWM1, PWM_CH_0_MASK|PWM_CH_1_MASK, (NUCODEGEN_PWM1_CH1_BRAKE_ACTION<<(1*2))| (NUCODEGEN_PWM1_CH0_BRAKE_ACTION<<(0*2)), NUCODEGEN_PWM1_CH0_1_BRAKE_SRC, NUCODEGEN_PWM1_CH0_1_BRAKE_DETECT_TYPE) ;

#endif /*NUCODEGEN_PWM1_CH0_1_BRAKE_ENABLE*/

#if (((NUCODEGEN_PWM1_CH0_INT_SEL) & 1) || ((NUCODEGEN_PWM1_CH1_INT_SEL) & 1))

    /* Enable zero interrupt - PWM two channals has one controller  */
    PWM_EnableZeroInt(PWM1, 0) ;

#endif /*NUCODEGEN_PWM1_CH0_INT_SEL*/

#if (((NUCODEGEN_PWM1_CH0_INT_SEL) & 2) || ((NUCODEGEN_PWM1_CH1_INT_SEL) & 2))

    /* Enable period interrupt - PWM two channals has one controller  */
    PWM_EnablePeriodInt(PWM1, 0, 0) ;

#endif /*NUCODEGEN_PWM1_CH0_INT_SEL*/

#if (((NUCODEGEN_PWM1_CH0_INT_SEL) & 16) || ((NUCODEGEN_PWM1_CH1_INT_SEL) & 16))

    /* Enable fault brake interrupt */
    PWM1->INTEN1 |= (1 << NUCODEGEN_PWM1_CH0_1_BRAKE_DETECT_TYPE);

#endif /*NUCODEGEN_PWM1_CH0_INT_SEL*/

#if NUCODEGEN_PWM1_CH0_ENABLE

    /* Set the duty of PWM1 CH0*/
    PWM_SET_CMR(PWM1, 0, NUCODEGEN_PWM1_CH0_CMPDATA);

    /* Set output level of PWM1 CH0*/
    PWM_SET_OUTPUT_LEVEL(PWM1, PWM_CH_0_MASK, NUCODEGEN_PWM1_CH0_WAVEOUT_ZERO, NUCODEGEN_PWM1_CH0_WAVEOUT_CMPUP, NUCODEGEN_PWM1_CH0_WAVEOUT_PERIOD, NUCODEGEN_PWM1_CH0_WAVEOUT_CMPDOWN);

    /* Enable output of PWM1 channel 0 */
    PWM_EnableOutput(PWM1, PWM_CH_0_MASK);

#if NUCODEGEN_PWM1_CH0_ADVANCED

#if (NUCODEGEN_PWM1_CH0_LOAD_MODE == 0)

    /* Period loading mode*/
    PWM_DisableLoadMode(PWM1, 0, PWM_LOAD_MODE_IMMEDIATE|PWM_LOAD_MODE_CENTER) ;

#elif (NUCODEGEN_PWM1_CH0_LOAD_MODE == 1)

    /*Immediate loading mode*/
    PWM_EnableLoadMode(PWM1, 0, PWM_LOAD_MODE_IMMEDIATE) ;

#elif (NUCODEGEN_PWM1_CH0_LOAD_MODE == 2)

    /*Center loading mode*/
    PWM_EnableLoadMode(PWM1, 0, PWM_LOAD_MODE_CENTER) ;

#endif /*NUCODEGEN_PWM1_CH0_LOAD_MODE*/

#if (NUCODEGEN_PWM1_CH0_OTHER_OUTPUT==1)

    /* Enable mask output and output high or low*/
    PWM_SetMaskOutput(PWM1, 0, NUCODEGEN_PWM1_CH0_MASK_DATA);

#elif (NUCODEGEN_PWM1_CH0_OTHER_OUTPUT==2)

    /* Enable inverter output */
    PWM1->POLCTL |= PWM_CH_0_MASK;

#endif /*NUCODEGEN_PWM1_CH0_OTHER_OUTPUT*/

#if NUCODEGEN_PWM1_CH0_TRIGER_EADC_ENABLE

    /* Set trigger EADC and trigger source*/
    PWM_EnableADCTrigger(PWM1, 0, NUCODEGEN_PWM1_CH0_TRIGER_EADCSRC) ;

#endif /*NUCODEGEN_PWM1_CH0_TRIGER_EADC_ENABLE*/

#if ((NUCODEGEN_PWM1_CH0_INT_SEL) & 4)

    /* Enable duty interrupt - count up interrupt */
    PWM_EnableDutyInt(PWM1, 0, PWM_DUTY_INT_UP_COUNT_MATCH_CMP) ;

#endif /*NUCODEGEN_PWM1_CH0_INT_SEL*/

#if ((NUCODEGEN_PWM1_CH0_INT_SEL) & 8)

    /* Enable duty interrupt - count down interrupt */
    PWM_EnableDutyInt(PWM1, 0, PWM_DUTY_INT_DOWN_COUNT_MATCH_CMP) ;

#endif /*NUCODEGEN_PWM1_CH0_INT_SEL*/

#endif /*NUCODEGEN_PWM1_CH0_ADVANCED*/

#endif /*NUCODEGEN_PWM1_CH0_ENABLE*/

#if NUCODEGEN_PWM1_CH1_ENABLE

    /* Set the duty of PWM1 CH1*/
    PWM_SET_CMR(PWM1, 1, NUCODEGEN_PWM1_CH1_CMPDATA);

    /* Set output level of PWM1 CH1*/
    PWM_SET_OUTPUT_LEVEL(PWM1, PWM_CH_1_MASK, NUCODEGEN_PWM1_CH1_WAVEOUT_ZERO, NUCODEGEN_PWM1_CH1_WAVEOUT_CMPUP, NUCODEGEN_PWM1_CH1_WAVEOUT_PERIOD, NUCODEGEN_PWM1_CH1_WAVEOUT_CMPDOWN);

    /* Enable output of PWM1 channel 1 */
    PWM_EnableOutput(PWM1, PWM_CH_1_MASK);

#if NUCODEGEN_PWM1_CH1_ADVANCED

#if (NUCODEGEN_PWM1_CH1_LOAD_MODE == 0)

    /* Period loading mode*/
    PWM_DisableLoadMode(PWM1, 1, PWM_LOAD_MODE_IMMEDIATE|PWM_LOAD_MODE_CENTER) ;

#elif (NUCODEGEN_PWM1_CH1_LOAD_MODE == 1)

    /*Immediate loading mode*/
    PWM_EnableLoadMode(PWM1, 1, PWM_LOAD_MODE_IMMEDIATE) ;

#elif (NUCODEGEN_PWM1_CH1_LOAD_MODE == 2)

    /*Center loading mode*/
    PWM_EnableLoadMode(PWM1, 1, PWM_LOAD_MODE_CENTER) ;

#endif /*NUCODEGEN_PWM1_CH1_LOAD_MODE*/

#if (NUCODEGEN_PWM1_CH1_OTHER_OUTPUT==1)

    /* Enable mask output and output high or low*/
    PWM_SetMaskOutput(PWM1, 1, NUCODEGEN_PWM1_CH1_MASK_DATA);

#elif (NUCODEGEN_PWM1_CH1_OTHER_OUTPUT==2)

    /* Enable inverter output */
    PWM1->POLCTL |= PWM_CH_1_MASK;

#endif /*NUCODEGEN_PWM1_CH1_OTHER_OUTPUT*/

#if NUCODEGEN_PWM1_CH1_TRIGER_EADC_ENABLE

    /* Set trigger EADC and trigger source*/
    PWM_EnableADCTrigger(PWM1, 1, NUCODEGEN_PWM1_CH1_TRIGER_EADCSRC) ;

#endif /*NUCODEGEN_PWM1_CH1_TRIGER_EADC_ENABLE*/

#if ((NUCODEGEN_PWM1_CH1_INT_SEL) & 4)

    /* Enable duty interrupt - count up interrupt */
    PWM_EnableDutyInt(PWM1, 1, PWM_DUTY_INT_UP_COUNT_MATCH_CMP) ;

#endif /*NUCODEGEN_PWM1_CH1_INT_SEL*/

#if ((NUCODEGEN_PWM1_CH1_INT_SEL) & 8)

    /* Enable duty interrupt - count down interrupt */
    PWM_EnableDutyInt(PWM1, 1, PWM_DUTY_INT_DOWN_COUNT_MATCH_CMP) ;

#endif /*NUCODEGEN_PWM1_CH1_INT_SEL*/

#endif /*NUCODEGEN_PWM1_CH1_ADVANCED*/

#endif /*NUCODEGEN_PWM1_CH1_ENABLE*/

#endif

#endif /*NUCODEGEN_PWM1_CH0_1_OUTPUT_FUNC_SETMODE*/

#else

#if (NUCODEGEN_PWM1_CH0_CAP_ENABLE || NUCODEGEN_PWM1_CH1_CAP_ENABLE)

    /* Configure PWM capture and get the nearest unit time */
    PWM_ConfigCaptureChannel(PWM1, 0, NUCODEGEN_PWM1_CH0_1_CAP_UNITTIME, 0);

#if NUCODEGEN_PWM1_CH0_1_CAP_PDMA_ENABLE

#if ((NUCODEGEN_PWM1_CH0_CAP_ADVANCED == 1) && (NUCODEGEN_PWM1_CH1_CAP_ADVANCED == 0))

    /* Enables PDMA transfer of selected channel for PWM capture */
    PWM_EnablePDMA(PWM1, 0, NUCODEGEN_PWM1_CH0_1_CAP_PDMA_FIRST_SEL, NUCODEGEN_PWM1_CH0_1_CAP_PDMA_DATA_SEL) ;

#elif ((NUCODEGEN_PWM1_CH0_CAP_ADVANCED == 0) && (NUCODEGEN_PWM1_CH1_CAP_ADVANCED == 1))

    /* Enables PDMA transfer of selected channel for PWM capture */
    PWM_EnablePDMA(PWM1, 1, NUCODEGEN_PWM1_CH0_1_CAP_PDMA_FIRST_SEL, NUCODEGEN_PWM1_CH0_1_CAP_PDMA_DATA_SEL) ;

#elif ((NUCODEGEN_PWM1_CH0_CAP_ADVANCED == 1) && (NUCODEGEN_PWM1_CH1_CAP_ADVANCED == 1))

    /* Enables PDMA transfer of selected channel for PWM capture */
    PWM_EnablePDMA(PWM1, NUCODEGEN_PWM1_CH0_1_CAP_PDMA_CH_SEL, NUCODEGEN_PWM1_CH0_1_CAP_PDMA_FIRST_SEL, NUCODEGEN_PWM1_CH0_1_CAP_PDMA_DATA_SEL) ;

#endif /*NUCODEGEN_PWM1_CH0_CAP_ADVANCED*/

#endif /*NUCODEGEN_PWM1_CH0_1_CAP_PDMA_ENABLE*/


#if NUCODEGEN_PWM1_CH0_CAP_ENABLE

    /* Set Reload Mode */
    PWM1->CAPCTL |= (NUCODEGEN_PWM1_CH0_CAP_RELOAD)<<PWM_CAPCTL_RCRLDEN0_Pos;

    /* Enable Capture Function for PWM1 channel 0 */
    PWM_EnableCapture(PWM1, PWM_CH_0_MASK);

#if NUCODEGEN_PWM1_CH0_CAP_ADVANCED

#if (NUCODEGEN_PWM1_CH0_CAP_INT_SEL == 1)

    /*Enable rising latch capture interrupt*/
    PWM_EnableCaptureInt(PWM1, 0, PWM_CAPTURE_INT_RISING_LATCH) ;

#elif (NUCODEGEN_PWM1_CH0_CAP_INT_SEL == 2)

    /*Enable falling latch capture interrupt*/
    PWM_EnableCaptureInt(PWM1, 0, PWM_CAPTURE_INT_FALLING_LATCH) ;

#elif (NUCODEGEN_PWM1_CH0_CAP_INT_SEL == 3)

    /*Enable rising and falling latch capture interrupt*/
    PWM_EnableCaptureInt(PWM1, 0, PWM_CAPTURE_INT_RISING_LATCH|PWM_CAPTURE_INT_FALLING_LATCH) ;

#endif /*NUCODEGEN_PWM1_CH0_CAP_INT_SEL*/

#endif /*NUCODEGEN_PWM1_CH0_CAP_ADVANCED*/

#endif /*NUCODEGEN_PWM1_CH0_CAP_ENABLE*/

#if NUCODEGEN_PWM1_CH1_CAP_ENABLE

    /* Set Reload Mode */
    PWM1->CAPCTL |= (NUCODEGEN_PWM1_CH1_CAP_RELOAD)<<PWM_CAPCTL_RCRLDEN1_Pos;

    /* Enable Capture Function for PWM1 channel 1 */
    PWM_EnableCapture(PWM1, PWM_CH_1_MASK);

#if NUCODEGEN_PWM1_CH1_CAP_ADVANCED

#if (NUCODEGEN_PWM1_CH1_CAP_INT_SEL == 1)

    /*Enable rising latch capture interrupt*/
    PWM_EnableCaptureInt(PWM1, 1, PWM_CAPTURE_INT_RISING_LATCH) ;

#elif (NUCODEGEN_PWM1_CH1_CAP_INT_SEL == 2)

    /*Enable falling latch capture interrupt*/
    PWM_EnableCaptureInt(PWM1, 1, PWM_CAPTURE_INT_FALLING_LATCH) ;

#elif (NUCODEGEN_PWM1_CH1_CAP_INT_SEL == 3)

    /*Enable rising and falling latch capture interrupt*/
    PWM_EnableCaptureInt(PWM1, 1, PWM_CAPTURE_INT_RISING_LATCH|PWM_CAPTURE_INT_FALLING_LATCH) ;

#endif /*NUCODEGEN_PWM1_CH1_CAP_INT_SEL*/

#endif /*NUCODEGEN_PWM1_CH1_CAP_ADVANCED*/

#endif /*NUCODEGEN_PWM1_CH1_CAP_ENABLE*/

#endif /*NUCODEGEN_PWM1_CH0_CAP_ENABLE, NUCODEGEN_PWM1_CH1_CAP_ENABLE*/

#endif /*NUCODEGEN_PWM1_FUNC_SEL*/

#endif /*NUCODEGEN_PWM1_CH0CH1*/

#if NUCODEGEN_PWM1_CH2CH3

#if (NUCODEGEN_PWM1_CH2_3_FUNC_SEL==0)

#if (NUCODEGEN_PWM1_CH2_3_OUTPUT_FUNC_SETMODE==0)

#if NUCODEGEN_PWM1_CH2_ENABLE

    /* Set PWM1 channel 2 configuration */
    PWM_ConfigOutputChannel(PWM1, 2, NUCODEGEN_PWM1_CH2_3_FREQ, NUCODEGEN_PWM1_CH2_DUTY);

    /* Enable output of PWM1 channel 2 */
    PWM_EnableOutput(PWM1, PWM_CH_2_MASK);

#endif /*NUCODEGEN_PWM1_CH2_ENABLE*/

#if NUCODEGEN_PWM1_CH3_ENABLE

    /* Set PWM1 channel 3 configuration */
    PWM_ConfigOutputChannel(PWM1, 3, NUCODEGEN_PWM1_CH2_3_FREQ, NUCODEGEN_PWM1_CH3_DUTY);

    /* Enable output of PWM1 channel 3 */
    PWM_EnableOutput(PWM1, PWM_CH_3_MASK);

#endif /*NUCODEGEN_PWM1_CH3_ENABLE*/

#else

#if (NUCODEGEN_PWM1_CH2_ENABLE||NUCODEGEN_PWM1_CH3_ENABLE)

    /* Set PWM1 CH2_3 clock source */
    PWM_SetClockSource(PWM1, 2, NUCODEGEN_PWM1_CH2_3_CLKSRC);

    /* Set PWM1 CH2_3 counter behavior type */
    PWM_SET_ALIGNED_TYPE(PWM1, PWM_CH_2_MASK, NUCODEGEN_PWM1_CH2_3_CNTTYPE);

    /* Set the prescaler of PWM1 CH2_3*/
    PWM_SET_PRESCALER(PWM1, 2, NUCODEGEN_PWM1_CH2_3_PRESCALER);

    /* Set the period of PWM1 CH2_3*/
    PWM_SET_CNR(PWM1, 2, NUCODEGEN_PWM1_CH2_3_PERIOD);

#if NUCODEGEN_PWM1_CH2_3_SYNCSTART_ENABLE

    /* Enable timer synchronous start counting function */
    PWM_ENABLE_TIMER_SYNC(PWM1, BIT2, NUCODEGEN_PWM1_SYNCSTART_SRC) ;

#endif /*NUCODEGEN_PWM1_CH2_3_SYNCSTART_ENABLE*/

#if NUCODEGEN_PWM1_CH2_3_COMPLEMATARY_ENABLE

    /* Enable complementary mode */
    PWM1->CTL1 = PWM1->CTL1 | PWM_CTL1_OUTMODE2_Msk;

#if NUCODEGEN_PWM1_CH2_3_DEADTIME_ENABLE

    /* Enable Dead zone and set counter */
    PWM_EnableDeadZone(PWM1, 2, NUCODEGEN_PWM1_CH2_3_DEADTIME_CNT) ;

    /* Set Dead zone clock source */
    PWM_SET_DEADZONE_CLK_SRC(PWM1, 2, NUCODEGEN_PWM1_CH2_3_DEADTIME_CLKSRC) ;

#endif /*NUCODEGEN_PWM1_CH2_3_DEADTIME_ENABLE*/

#endif /*NUCODEGEN_PWM1_CH2_3_COMPLEMATARY_ENABLE*/

#if NUCODEGEN_PWM1_CH2_3_BRAKE_ENABLE

	/* Enable brake function and set the brake source */
    PWM_EnableBrake(PWM1, PWM_CH_2_MASK|PWM_CH_3_MASK, (NUCODEGEN_PWM1_CH2_BRAKE_ACTION<<(2*2))| (NUCODEGEN_PWM1_CH3_BRAKE_ACTION<<(3*2)), NUCODEGEN_PWM1_CH2_3_BRAKE_SRC, NUCODEGEN_PWM1_CH2_3_BRAKE_DETECT_TYPE) ;

#endif /*NUCODEGEN_PWM1_CH2_3_BRAKE_ENABLE*/

#if (((NUCODEGEN_PWM1_CH2_INT_SEL) & 1) || ((NUCODEGEN_PWM1_CH3_INT_SEL) & 1))

    /* Enable zero interrupt - PWM two channals has one controller  */
    PWM_EnableZeroInt(PWM1, 2) ;

#endif /*NUCODEGEN_PWM1_CH2_INT_SEL*/

#if (((NUCODEGEN_PWM1_CH2_INT_SEL) & 2) || ((NUCODEGEN_PWM1_CH3_INT_SEL) & 2))

    /* Enable period interrupt - PWM two channals has one controller  */
    PWM_EnablePeriodInt(PWM1, 2, 0) ;

#endif /*NUCODEGEN_PWM1_CH2_INT_SEL*/

#if (((NUCODEGEN_PWM1_CH2_INT_SEL) & 16) || ((NUCODEGEN_PWM1_CH3_INT_SEL) & 16))

    /* Enable fault brake interrupt */
    PWM1->INTEN1 |= (0x2 << NUCODEGEN_PWM1_CH2_3_BRAKE_DETECT_TYPE);

#endif /*NUCODEGEN_PWM1_CH2_INT_SEL*/

#if NUCODEGEN_PWM1_CH2_ENABLE

    /* Set the duty of PWM1 CH2*/
    PWM_SET_CMR(PWM1, 2, NUCODEGEN_PWM1_CH2_CMPDATA);

    /* Set output level of PWM1 CH2*/
    PWM_SET_OUTPUT_LEVEL(PWM1, PWM_CH_2_MASK, NUCODEGEN_PWM1_CH2_WAVEOUT_ZERO, NUCODEGEN_PWM1_CH2_WAVEOUT_CMPUP, NUCODEGEN_PWM1_CH2_WAVEOUT_PERIOD, NUCODEGEN_PWM1_CH2_WAVEOUT_CMPDOWN);

    /* Enable output of PWM1 channel 2 */
    PWM_EnableOutput(PWM1, PWM_CH_2_MASK);

#if NUCODEGEN_PWM1_CH2_ADVANCED

#if (NUCODEGEN_PWM1_CH2_LOAD_MODE == 0)

    /* Period loading mode*/
    PWM_DisableLoadMode(PWM1, 2, PWM_LOAD_MODE_IMMEDIATE|PWM_LOAD_MODE_CENTER) ;

#elif (NUCODEGEN_PWM1_CH2_LOAD_MODE == 1)

    /*Immediate loading mode*/
    PWM_EnableLoadMode(PWM1, 2, PWM_LOAD_MODE_IMMEDIATE) ;

#elif (NUCODEGEN_PWM1_CH2_LOAD_MODE == 2)

    /*Center loading mode*/
    PWM_EnableLoadMode(PWM1, 2, PWM_LOAD_MODE_CENTER) ;

#endif /*NUCODEGEN_PWM1_CH2_LOAD_MODE*/

#if (NUCODEGEN_PWM1_CH2_OTHER_OUTPUT==1)

    /* Enable mask output and output high or low*/
    PWM_SetMaskOutput(PWM1, 2, NUCODEGEN_PWM1_CH2_MASK_DATA);

#elif (NUCODEGEN_PWM1_CH2_OTHER_OUTPUT==2)

    /* Enable inverter output */
    PWM1->POLCTL |= PWM_CH_2_MASK;

#endif /*NUCODEGEN_PWM1_CH2_OTHER_OUTPUT*/

#if NUCODEGEN_PWM1_CH2_TRIGER_EADC_ENABLE

    /* Set trigger EADC and trigger source*/
    PWM_EnableADCTrigger(PWM1, 2, NUCODEGEN_PWM1_CH2_TRIGER_EADCSRC) ;

#endif /*NUCODEGEN_PWM1_CH2_TRIGER_EADC_ENABLE*/

#if ((NUCODEGEN_PWM1_CH2_INT_SEL) & 4)

    /* Enable duty interrupt - count up interrupt */
    PWM_EnableDutyInt(PWM1, 2, PWM_DUTY_INT_UP_COUNT_MATCH_CMP) ;

#endif /*NUCODEGEN_PWM1_CH2_INT_SEL*/

#if ((NUCODEGEN_PWM1_CH2_INT_SEL) & 8)

    /* Enable duty interrupt - count down interrupt */
    PWM_EnableDutyInt(PWM1, 2, PWM_DUTY_INT_DOWN_COUNT_MATCH_CMP) ;

#endif /*NUCODEGEN_PWM1_CH2_INT_SEL*/

#endif /*NUCODEGEN_PWM1_CH2_ADVANCED*/

#endif /*NUCODEGEN_PWM1_CH2_ENABLE*/

#if NUCODEGEN_PWM1_CH3_ENABLE

    /* Set the duty of PWM1 CH3*/
    PWM_SET_CMR(PWM1, 3, NUCODEGEN_PWM1_CH3_CMPDATA);

    /* Set output level of PWM1 CH3*/
    PWM_SET_OUTPUT_LEVEL(PWM1, PWM_CH_3_MASK, NUCODEGEN_PWM1_CH3_WAVEOUT_ZERO, NUCODEGEN_PWM1_CH3_WAVEOUT_CMPUP, NUCODEGEN_PWM1_CH3_WAVEOUT_PERIOD, NUCODEGEN_PWM1_CH3_WAVEOUT_CMPDOWN);

    /* Enable output of PWM1 channel 3 */
    PWM_EnableOutput(PWM1, PWM_CH_3_MASK);

#if NUCODEGEN_PWM1_CH3_ADVANCED

#if (NUCODEGEN_PWM1_CH3_LOAD_MODE == 0)

    /* Period loading mode*/
    PWM_DisableLoadMode(PWM1, 3, PWM_LOAD_MODE_IMMEDIATE|PWM_LOAD_MODE_CENTER) ;

#elif (NUCODEGEN_PWM1_CH3_LOAD_MODE == 1)

    /*Immediate loading mode*/
    PWM_EnableLoadMode(PWM1, 3, PWM_LOAD_MODE_IMMEDIATE) ;

#elif (NUCODEGEN_PWM1_CH3_LOAD_MODE == 2)

    /*Center loading mode*/
    PWM_EnableLoadMode(PWM1, 3, PWM_LOAD_MODE_CENTER) ;

#endif /*NUCODEGEN_PWM1_CH3_LOAD_MODE*/

#if (NUCODEGEN_PWM1_CH3_OTHER_OUTPUT==1)

    /* Enable mask output and output high or low*/
    PWM_SetMaskOutput(PWM1, 3, NUCODEGEN_PWM1_CH3_MASK_DATA);

#elif (NUCODEGEN_PWM1_CH3_OTHER_OUTPUT==2)

    /* Enable inverter output */
    PWM1->POLCTL |= PWM_CH_3_MASK;

#endif /*NUCODEGEN_PWM1_CH3_OTHER_OUTPUT*/

#if NUCODEGEN_PWM1_CH3_TRIGER_EADC_ENABLE

    /* Set trigger EADC and trigger source*/
    PWM_EnableADCTrigger(PWM1, 3, NUCODEGEN_PWM1_CH3_TRIGER_EADCSRC) ;

#endif /*NUCODEGEN_PWM1_CH3_TRIGER_EADC_ENABLE*/

#if ((NUCODEGEN_PWM1_CH3_INT_SEL) & 4)

    /* Enable duty interrupt - count up interrupt */
    PWM_EnableDutyInt(PWM1, 3, PWM_DUTY_INT_UP_COUNT_MATCH_CMP) ;

#endif /*NUCODEGEN_PWM1_CH3_INT_SEL*/

#if ((NUCODEGEN_PWM1_CH3_INT_SEL) & 8)

    /* Enable duty interrupt - count down interrupt */
    PWM_EnableDutyInt(PWM1, 3, PWM_DUTY_INT_DOWN_COUNT_MATCH_CMP) ;

#endif /*NUCODEGEN_PWM1_CH3_INT_SEL*/

#endif /*NUCODEGEN_PWM1_CH3_ADVANCED*/

#endif /*NUCODEGEN_PWM1_CH3_ENABLE*/

#endif

#endif /*NUCODEGEN_PWM1_CH2_3_OUTPUT_FUNC_SETMODE*/

#else

#if (NUCODEGEN_PWM1_CH2_CAP_ENABLE || NUCODEGEN_PWM1_CH3_CAP_ENABLE)

    /* Configure PWM capture and get the nearest unit time */
    PWM_ConfigCaptureChannel(PWM1, 2, NUCODEGEN_PWM1_CH2_3_CAP_UNITTIME, 0);

#if NUCODEGEN_PWM1_CH2_3_CAP_PDMA_ENABLE

#if ((NUCODEGEN_PWM1_CH2_CAP_ADVANCED == 1) && (NUCODEGEN_PWM1_CH3_CAP_ADVANCED == 0))

    /* Enables PDMA transfer of selected channel for PWM capture */
    PWM_EnablePDMA(PWM1, 2, NUCODEGEN_PWM1_CH2_3_CAP_PDMA_FIRST_SEL, NUCODEGEN_PWM1_CH2_3_CAP_PDMA_DATA_SEL) ;

#elif ((NUCODEGEN_PWM1_CH2_CAP_ADVANCED == 0) && (NUCODEGEN_PWM1_CH3_CAP_ADVANCED == 1))

    /* Enables PDMA transfer of selected channel for PWM capture */
    PWM_EnablePDMA(PWM1, 3, NUCODEGEN_PWM1_CH2_3_CAP_PDMA_FIRST_SEL, NUCODEGEN_PWM1_CH2_3_CAP_PDMA_DATA_SEL) ;

#elif ((NUCODEGEN_PWM1_CH2_CAP_ADVANCED == 1) && (NUCODEGEN_PWM1_CH3_CAP_ADVANCED == 1))

    /* Enables PDMA transfer of selected channel for PWM capture */
    PWM_EnablePDMA(PWM1, NUCODEGEN_PWM1_CH2_3_CAP_PDMA_CH_SEL, NUCODEGEN_PWM1_CH2_3_CAP_PDMA_FIRST_SEL, NUCODEGEN_PWM1_CH2_3_CAP_PDMA_DATA_SEL) ;

#endif /*NUCODEGEN_PWM1_CH2_CAP_ADVANCED*/

#endif /*NUCODEGEN_PWM1_CH2_3_CAP_PDMA_ENABLE*/


#if NUCODEGEN_PWM1_CH2_CAP_ENABLE

    /* Set Reload Mode */
    PWM1->CAPCTL |= (NUCODEGEN_PWM1_CH2_CAP_RELOAD)<<PWM_CAPCTL_RCRLDEN2_Pos;

    /* Enable Capture Function for PWM1 channel 2 */
    PWM_EnableCapture(PWM1, PWM_CH_2_MASK);

#if NUCODEGEN_PWM0_CH2_CAP_ADVANCED

#if (NUCODEGEN_PWM1_CH2_CAP_INT_SEL == 1)

    /*Enable rising latch capture interrupt*/
    PWM_EnableCaptureInt(PWM1, 2, PWM_CAPTURE_INT_RISING_LATCH) ;

#elif (NUCODEGEN_PWM1_CH2_CAP_INT_SEL == 2)

    /*Enable falling latch capture interrupt*/
    PWM_EnableCaptureInt(PWM1, 2, PWM_CAPTURE_INT_FALLING_LATCH) ;

#elif (NUCODEGEN_PWM1_CH2_CAP_INT_SEL == 3)

    /*Enable rising and falling latch capture interrupt*/
    PWM_EnableCaptureInt(PWM1, 2, PWM_CAPTURE_INT_RISING_LATCH|PWM_CAPTURE_INT_FALLING_LATCH) ;

#endif /*NUCODEGEN_PWM1_CH2_CAP_INT_SEL*/

#endif /*NUCODEGEN_PWM1_CH2_CAP_ADVANCED*/

#endif /*NUCODEGEN_PWM1_CH2_CAP_ENABLE*/

#if NUCODEGEN_PWM1_CH3_CAP_ENABLE

    /* Set Reload Mode */
    PWM1->CAPCTL |= (NUCODEGEN_PWM1_CH3_CAP_RELOAD)<<PWM_CAPCTL_RCRLDEN3_Pos;

    /* Enable Capture Function for PWM1 channel 3 */
    PWM_EnableCapture(PWM1, PWM_CH_3_MASK);

#if NUCODEGEN_PWM1_CH3_CAP_ADVANCED

#if (NUCODEGEN_PWM1_CH3_CAP_INT_SEL == 1)

    /*Enable rising latch capture interrupt*/
    PWM_EnableCaptureInt(PWM1, 3, PWM_CAPTURE_INT_RISING_LATCH) ;

#elif (NUCODEGEN_PWM1_CH3_CAP_INT_SEL == 2)

    /*Enable falling latch capture interrupt*/
    PWM_EnableCaptureInt(PWM1, 3, PWM_CAPTURE_INT_FALLING_LATCH) ;

#elif (NUCODEGEN_PWM1_CH3_CAP_INT_SEL == 3)

    /*Enable rising and falling latch capture interrupt*/
    PWM_EnableCaptureInt(PWM1, 3, PWM_CAPTURE_INT_RISING_LATCH|PWM_CAPTURE_INT_FALLING_LATCH) ;

#endif /*NUCODEGEN_PWM1_CH3_CAP_INT_SEL*/

#endif /*NUCODEGEN_PWM1_CH3_CAP_ADVANCED*/

#endif /*NUCODEGEN_PWM1_CH3_CAP_ENABLE*/

#endif /*NUCODEGEN_PWM1_CH2_CAP_ENABLE, NUCODEGEN_PWM1_CH3_CAP_ENABLE*/

#endif /*NUCODEGEN_PWM1_CH2_3_FUNC_SEL*/


#endif /*NUCODEGEN_PWM1_CH2CH3*/

#if NUCODEGEN_PWM1_CH4CH5

#if (NUCODEGEN_PWM1_CH4_5_FUNC_SEL==0)

#if (NUCODEGEN_PWM1_CH4_5_OUTPUT_FUNC_SETMODE==0)

#if NUCODEGEN_PWM1_CH4_ENABLE

    /* Set PWM1 channel 4 configuration */
    PWM_ConfigOutputChannel(PWM1, 4, NUCODEGEN_PWM1_CH4_5_FREQ, NUCODEGEN_PWM1_CH4_DUTY);

    /* Enable output of PWM1 channel 4 */
    PWM_EnableOutput(PWM1, PWM_CH_4_MASK);

#endif /*NUCODEGEN_PWM1_CH4_ENABLE*/

#if NUCODEGEN_PWM1_CH5_ENABLE

    /* Set PWM1 channel 5 configuration */
    PWM_ConfigOutputChannel(PWM1, 5, NUCODEGEN_PWM1_CH4_5_FREQ, NUCODEGEN_PWM1_CH5_DUTY);

    /* Enable output of PWM1 channel 5 */
    PWM_EnableOutput(PWM1, PWM_CH_5_MASK);

#endif /*NUCODEGEN_PWM1_CH5_ENABLE*/

#else

#if (NUCODEGEN_PWM1_CH4_ENABLE||NUCODEGEN_PWM1_CH5_ENABLE)

    /* Set PWM1 CH4_5 clock source */
    PWM_SetClockSource(PWM1, 4, NUCODEGEN_PWM1_CH4_5_CLKSRC);

    /* Set PWM1 CH4_5 counter behavior type */
    PWM_SET_ALIGNED_TYPE(PWM1, PWM_CH_4_MASK, NUCODEGEN_PWM1_CH4_5_CNTTYPE);

    /* Set the prescaler of PWM1 CH4_5*/
    PWM_SET_PRESCALER(PWM1, 4, NUCODEGEN_PWM1_CH4_5_PRESCALER);

    /* Set the period of PWM1 CH4_5*/
    PWM_SET_CNR(PWM1, 4, NUCODEGEN_PWM1_CH4_5_PERIOD);

#if NUCODEGEN_PWM1_CH4_5_SYNCSTART_ENABLE

    /* Enable timer synchronous start counting function */
    PWM_ENABLE_TIMER_SYNC(PWM1, BIT4, NUCODEGEN_PWM1_SYNCSTART_SRC) ;

#endif /*NUCODEGEN_PWM1_CH4_5_SYNCSTART_ENABLE*/

#if NUCODEGEN_PWM1_CH4_5_COMPLEMATARY_ENABLE

    /* Enable complementary mode */
    PWM1->CTL1 = PWM1->CTL1 | PWM_CTL1_OUTMODE4_Msk;

#if NUCODEGEN_PWM1_CH4_5_DEADTIME_ENABLE

    /* Enable Dead zone and set counter */
    PWM_EnableDeadZone(PWM1, 4, NUCODEGEN_PWM1_CH4_5_DEADTIME_CNT) ;

    /* Set Dead zone clock source */
    PWM_SET_DEADZONE_CLK_SRC(PWM1, 4, NUCODEGEN_PWM1_CH4_5_DEADTIME_CLKSRC) ;

#endif /*NUCODEGEN_PWM1_CH4_5_DEADTIME_ENABLE*/

#endif /*NUCODEGEN_PWM1_CH4_5_COMPLEMATARY_ENABLE*/

#if NUCODEGEN_PWM1_CH4_5_BRAKE_ENABLE

	/* Enable brake function and set the brake source */
    PWM_EnableBrake(PWM1, PWM_CH_4_MASK|PWM_CH_5_MASK, (NUCODEGEN_PWM1_CH4_BRAKE_ACTION<<(4*2))| (NUCODEGEN_PWM1_CH5_BRAKE_ACTION<<(5*2)), NUCODEGEN_PWM1_CH4_5_BRAKE_SRC, NUCODEGEN_PWM1_CH4_5_BRAKE_DETECT_TYPE) ;

#endif /*NUCODEGEN_PWM1_CH4_5_BRAKE_ENABLE*/

#if (((NUCODEGEN_PWM1_CH4_INT_SEL) & 1) || ((NUCODEGEN_PWM1_CH5_INT_SEL) & 1))

    /* Enable zero interrupt - PWM two channals has one controller  */
    PWM_EnableZeroInt(PWM1, 4) ;

#endif /*NUCODEGEN_PWM1_CH4_INT_SEL*/

#if (((NUCODEGEN_PWM1_CH4_INT_SEL) & 2) || ((NUCODEGEN_PWM1_CH5_INT_SEL) & 2))

    /* Enable period interrupt - PWM two channals has one controller  */
    PWM_EnablePeriodInt(PWM1, 4, 0) ;

#endif /*NUCODEGEN_PWM1_CH4_INT_SEL*/

#if (((NUCODEGEN_PWM1_CH4_INT_SEL) & 16) || ((NUCODEGEN_PWM1_CH5_INT_SEL) & 16))

    /* Enable fault brake interrupt */
    PWM1->INTEN1 |= (0x4 << NUCODEGEN_PWM1_CH4_5_BRAKE_DETECT_TYPE);

#endif /*NUCODEGEN_PWM1_CH4_INT_SEL*/

#if NUCODEGEN_PWM1_CH4_ENABLE

    /* Set the duty of PWM1 CH4*/
    PWM_SET_CMR(PWM1, 4, NUCODEGEN_PWM1_CH4_CMPDATA);

    /* Set output level of PWM1 CH4*/
    PWM_SET_OUTPUT_LEVEL(PWM1, PWM_CH_4_MASK, NUCODEGEN_PWM1_CH4_WAVEOUT_ZERO, NUCODEGEN_PWM1_CH4_WAVEOUT_CMPUP, NUCODEGEN_PWM1_CH4_WAVEOUT_PERIOD, NUCODEGEN_PWM1_CH4_WAVEOUT_CMPDOWN);

    /* Enable output of PWM1 channel 4 */
    PWM_EnableOutput(PWM1, PWM_CH_4_MASK);

#if NUCODEGEN_PWM1_CH4_ADVANCED

#if (NUCODEGEN_PWM1_CH4_LOAD_MODE == 0)

    /* Period loading mode*/
    PWM_DisableLoadMode(PWM1, 4, PWM_LOAD_MODE_IMMEDIATE|PWM_LOAD_MODE_CENTER) ;

#elif (NUCODEGEN_PWM1_CH4_LOAD_MODE == 1)

    /*Immediate loading mode*/
    PWM_EnableLoadMode(PWM1, 4, PWM_LOAD_MODE_IMMEDIATE) ;

#elif (NUCODEGEN_PWM1_CH4_LOAD_MODE == 2)

    /*Center loading mode*/
    PWM_EnableLoadMode(PWM1, 4, PWM_LOAD_MODE_CENTER) ;

#endif /*NUCODEGEN_PWM1_CH4_LOAD_MODE*/

#if (NUCODEGEN_PWM1_CH4_OTHER_OUTPUT==1)

    /* Enable mask output and output high or low*/
    PWM_SetMaskOutput(PWM1, 4, NUCODEGEN_PWM1_CH4_MASK_DATA);

#elif (NUCODEGEN_PWM1_CH4_OTHER_OUTPUT==2)

    /* Enable inverter output */
    PWM1->POLCTL |= PWM_CH_4_MASK;

#endif /*NUCODEGEN_PWM1_CH4_OTHER_OUTPUT*/

#if NUCODEGEN_PWM1_CH4_TRIGER_EADC_ENABLE

    /* Set trigger EADC and trigger source*/
    PWM_EnableADCTrigger(PWM1, 4, NUCODEGEN_PWM1_CH4_TRIGER_EADCSRC) ;

#endif /*NUCODEGEN_PWM1_CH4_TRIGER_EADC_ENABLE*/

#if ((NUCODEGEN_PWM1_CH4_INT_SEL) & 4)

    /* Enable duty interrupt - count up interrupt */
    PWM_EnableDutyInt(PWM1, 4, PWM_DUTY_INT_UP_COUNT_MATCH_CMP) ;

#endif /*NUCODEGEN_PWM1_CH4_INT_SEL*/

#if ((NUCODEGEN_PWM1_CH4_INT_SEL) & 8)

    /* Enable duty interrupt - count down interrupt */
    PWM_EnableDutyInt(PWM1, 4, PWM_DUTY_INT_DOWN_COUNT_MATCH_CMP) ;

#endif /*NUCODEGEN_PWM1_CH4_INT_SEL*/

#endif /*NUCODEGEN_PWM1_CH4_ADVANCED*/

#endif /*NUCODEGEN_PWM1_CH4_ENABLE*/

#if NUCODEGEN_PWM1_CH5_ENABLE

    /* Set the duty of PWM1 CH5*/
    PWM_SET_CMR(PWM1, 5, NUCODEGEN_PWM1_CH5_CMPDATA);

    /* Set output level of PWM1 CH5*/
    PWM_SET_OUTPUT_LEVEL(PWM1, PWM_CH_5_MASK, NUCODEGEN_PWM1_CH5_WAVEOUT_ZERO, NUCODEGEN_PWM1_CH5_WAVEOUT_CMPUP, NUCODEGEN_PWM1_CH5_WAVEOUT_PERIOD, NUCODEGEN_PWM1_CH5_WAVEOUT_CMPDOWN);

    /* Enable output of PWM1 channel 5 */
    PWM_EnableOutput(PWM1, PWM_CH_5_MASK);

#if NUCODEGEN_PWM1_CH5_ADVANCED

#if (NUCODEGEN_PWM1_CH5_LOAD_MODE == 0)

    /* Period loading mode*/
    PWM_DisableLoadMode(PWM1, 5, PWM_LOAD_MODE_IMMEDIATE|PWM_LOAD_MODE_CENTER) ;

#elif (NUCODEGEN_PWM1_CH5_LOAD_MODE == 1)

    /*Immediate loading mode*/
    PWM_EnableLoadMode(PWM1, 5, PWM_LOAD_MODE_IMMEDIATE) ;

#elif (NUCODEGEN_PWM1_CH5_LOAD_MODE == 2)

    /*Center loading mode*/
    PWM_EnableLoadMode(PWM1, 5, PWM_LOAD_MODE_CENTER) ;

#endif /*NUCODEGEN_PWM1_CH5_LOAD_MODE*/

#if (NUCODEGEN_PWM1_CH5_OTHER_OUTPUT==1)

    /* Enable mask output and output high or low*/
    PWM_SetMaskOutput(PWM1, 5, NUCODEGEN_PWM1_CH5_MASK_DATA);

#elif (NUCODEGEN_PWM1_CH5_OTHER_OUTPUT==2)

    /* Enable inverter output */
    PWM1->POLCTL |= PWM_CH_5_MASK ;

#endif /*NUCODEGEN_PWM1_CH5_OTHER_OUTPUT*/

#if NUCODEGEN_PWM1_CH5_TRIGER_EADC_ENABLE

    /* Set trigger EADC and trigger source*/
    PWM_EnableADCTrigger(PWM1, 5, NUCODEGEN_PWM1_CH5_TRIGER_EADCSRC) ;

#endif /*NUCODEGEN_PWM1_CH5_TRIGER_EADC_ENABLE*/

#if ((NUCODEGEN_PWM1_CH5_INT_SEL) & 4)

    /* Enable duty interrupt - count up interrupt */
    PWM_EnableDutyInt(PWM1, 5, PWM_DUTY_INT_UP_COUNT_MATCH_CMP) ;

#endif /*NUCODEGEN_PWM1_CH5_INT_SEL*/

#if ((NUCODEGEN_PWM1_CH5_INT_SEL) & 8)

    /* Enable duty interrupt - count down interrupt */
    PWM_EnableDutyInt(PWM1, 5, PWM_DUTY_INT_DOWN_COUNT_MATCH_CMP) ;

#endif /*NUCODEGEN_PWM1_CH5_INT_SEL*/

#endif /*NUCODEGEN_PWM1_CH5_ADVANCED*/

#endif /*NUCODEGEN_PWM1_CH5_ENABLE*/

#endif

#endif /*NUCODEGEN_PWM1_CH4_5_OUTPUT_FUNC_SETMODE*/

#else

#if (NUCODEGEN_PWM1_CH4_CAP_ENABLE || NUCODEGEN_PWM1_CH5_CAP_ENABLE)

    /* Configure PWM capture and get the nearest unit time */
    PWM_ConfigCaptureChannel(PWM1, 4, NUCODEGEN_PWM1_CH4_5_CAP_UNITTIME, 0);

#if NUCODEGEN_PWM1_CH4_5_CAP_PDMA_ENABLE

#if ((NUCODEGEN_PWM1_CH4_CAP_ADVANCED == 1) && (NUCODEGEN_PWM1_CH5_CAP_ADVANCED == 0))

    /* Enables PDMA transfer of selected channel for PWM capture */
    PWM_EnablePDMA(PWM1, 4, NUCODEGEN_PWM1_CH4_5_CAP_PDMA_FIRST_SEL, NUCODEGEN_PWM1_CH4_5_CAP_PDMA_DATA_SEL) ;

#elif ((NUCODEGEN_PWM1_CH4_CAP_ADVANCED == 0) && (NUCODEGEN_PWM1_CH5_CAP_ADVANCED == 1))

    /* Enables PDMA transfer of selected channel for PWM capture */
    PWM_EnablePDMA(PWM1, 5, NUCODEGEN_PWM1_CH4_5_CAP_PDMA_FIRST_SEL, NUCODEGEN_PWM1_CH4_5_CAP_PDMA_DATA_SEL) ;

#elif ((NUCODEGEN_PWM1_CH4_CAP_ADVANCED == 1) && (NUCODEGEN_PWM1_CH5_CAP_ADVANCED == 1))

    /* Enables PDMA transfer of selected channel for PWM capture */
    PWM_EnablePDMA(PWM1, NUCODEGEN_PWM1_CH4_5_CAP_PDMA_CH_SEL, NUCODEGEN_PWM1_CH4_5_CAP_PDMA_FIRST_SEL, NUCODEGEN_PWM1_CH4_5_CAP_PDMA_DATA_SEL) ;

#endif /*NUCODEGEN_PWM1_CH4_CAP_ADVANCED*/

#endif /*NUCODEGEN_PWM1_CH4_5_CAP_PDMA_ENABLE*/


#if NUCODEGEN_PWM1_CH4_CAP_ENABLE

    /* Set Reload Mode */
    PWM1->CAPCTL |= (NUCODEGEN_PWM1_CH4_CAP_RELOAD)<<PWM_CAPCTL_RCRLDEN4_Pos;

    /* Enable Capture Function for PWM1 channel 4 */
    PWM_EnableCapture(PWM1, PWM_CH_4_MASK);

#if NUCODEGEN_PWM1_CH4_CAP_ADVANCED

#if (NUCODEGEN_PWM1_CH4_CAP_INT_SEL == 1)

    /*Enable rising latch capture interrupt*/
    PWM_EnableCaptureInt(PWM1, 4, PWM_CAPTURE_INT_RISING_LATCH) ;

#elif (NUCODEGEN_PWM1_CH4_CAP_INT_SEL == 2)

    /*Enable falling latch capture interrupt*/
    PWM_EnableCaptureInt(PWM1, 4, PWM_CAPTURE_INT_FALLING_LATCH) ;

#elif (NUCODEGEN_PWM1_CH4_CAP_INT_SEL == 3)

    /*Enable rising and falling latch capture interrupt*/
    PWM_EnableCaptureInt(PWM1, 4, PWM_CAPTURE_INT_RISING_LATCH|PWM_CAPTURE_INT_FALLING_LATCH) ;

#endif /*NUCODEGEN_PWM1_CH4_CAP_INT_SEL*/

#endif /*NUCODEGEN_PWM1_CH4_CAP_ADVANCED*/

#endif /*NUCODEGEN_PWM1_CH4_CAP_ENABLE*/

#if NUCODEGEN_PWM1_CH5_CAP_ENABLE

    /* Set Reload Mode */
    PWM1->CAPCTL |= (NUCODEGEN_PWM1_CH5_CAP_RELOAD)<<PWM_CAPCTL_RCRLDEN5_Pos;

    /* Enable Capture Function for PWM1 channel 5 */
    PWM_EnableCapture(PWM1, PWM_CH_5_MASK);

#if NUCODEGEN_PWM1_CH5_CAP_ADVANCED

#if (NUCODEGEN_PWM1_CH5_CAP_INT_SEL == 1)

    /*Enable rising latch capture interrupt*/
    PWM_EnableCaptureInt(PWM1, 5, PWM_CAPTURE_INT_RISING_LATCH) ;

#elif (NUCODEGEN_PWM1_CH5_CAP_INT_SEL == 2)

    /*Enable falling latch capture interrupt*/
    PWM_EnableCaptureInt(PWM1, 5, PWM_CAPTURE_INT_FALLING_LATCH) ;

#elif (NUCODEGEN_PWM1_CH5_CAP_INT_SEL == 3)

    /*Enable rising and falling latch capture interrupt*/
    PWM_EnableCaptureInt(PWM1, 5, PWM_CAPTURE_INT_RISING_LATCH|PWM_CAPTURE_INT_FALLING_LATCH) ;

#endif /*NUCODEGEN_PWM1_CH5_CAP_INT_SEL*/

#endif /*NUCODEGEN_PWM1_CH5_CAP_ADVANCED*/

#endif /*NUCODEGEN_PWM1_CH5_CAP_ENABLE*/

#endif /*NUCODEGEN_PWM1_CH4_CAP_ENABLE, NUCODEGEN_PWM1_CH5_CAP_ENABLE*/

#endif /*NUCODEGEN_PWM1_CH4_5_FUNC_SEL*/

#endif /*NUCODEGEN_PWM1_CH4CH5*/

#if NUCODEGEN_PWM1_CH0_1_BRAKE_PIN_INV

    /* Enable PWM brake noise filter */
    PWM_EnableBrakePinInv(PWM1, NUCODEGEN_PWM1_CH0_1_BRAKE_SRC);

#elif NUCODEGEN_PWM1_CH2_3_BRAKE_PIN_INV

    /* Enable PWM brake noise filter */
    PWM_EnableBrakePinInv(PWM1, NUCODEGEN_PWM1_CH2_3_BRAKE_SRC);

#elif NUCODEGEN_PWM1_CH4_5_BRAKE_PIN_INV

    /* Enable PWM brake noise filter */
    PWM_EnableBrakePinInv(PWM1, NUCODEGEN_PWM1_CH4_5_BRAKE_SRC);

#endif /*NUCODEGEN_PWM1_CH0_1_BRAKE_PIN_INV*/


#if NUCODEGEN_PWM1_CH0_1_BRAKE_FILTER_ENABLE

    /* Enable PWM brake noise filter */
    PWM_EnableBrakeFilter(PWM1, NUCODEGEN_PWM1_CH0_1_BRAKE_SRC|NUCODEGEN_PWM1_CH2_3_BRAKE_SRC|NUCODEGEN_PWM1_CH4_5_BRAKE_SRC, NUCODEGEN_PWM1_CH0_1_BRAKE_FILTER_CNT, NUCODEGEN_PWM1_CH0_1_BRAKE_FILTER_CLK);

#elif NUCODEGEN_PWM1_CH2_3_BRAKE_FILTER_ENABLE

    /* Enable PWM brake noise filter */
    PWM_EnableBrakeFilter(PWM1, NUCODEGEN_PWM1_CH2_3_BRAKE_SRC|NUCODEGEN_PWM1_CH4_5_BRAKE_SRC, NUCODEGEN_PWM1_CH2_3_BRAKE_FILTER_CNT, NUCODEGEN_PWM1_CH2_3_BRAKE_FILTER_CLK);

#elif NUCODEGEN_PWM1_CH4_5_BRAKE_FILTER_ENABLE

    /* Enable PWM brake noise filter */
    PWM_EnableBrakeFilter(PWM1, NUCODEGEN_PWM1_CH4_5_BRAKE_SRC, NUCODEGEN_PWM1_CH4_5_BRAKE_FILTER_CNT, NUCODEGEN_PWM1_CH4_5_BRAKE_FILTER_CLK);

#endif /*NUCODEGEN_PWM1_CH0_1_BRAKE_FILTER_ENABLE*/

}

#endif /*NUCODEGEN_PWM1*/

#if(NUCODEGEN_GPIO)
/*--------------------------------------------------------------------------------------------*/
/* GPIO                                                                                     */
/*--------------------------------------------------------------------------------------------*/
void GPIO_Init()
{
		const uint32_t u32RegDefault = 0;
#if(NUCODEGEN_GPIO_DB)
    GPIO_SET_DEBOUNCE_TIME(NUCODEGEN_GPIO_DBCLKSRC, NUCODEGEN_GPIO_DBCLKSEL);
#endif

#if(NUCODEGEN_GPIO_PA)
    //GPIO_PA mode
    PA->MODE =
#if NUCODEGEN_GPIO_PA_PIN0_EN
								(NUCODEGEN_GPIO_PA_PIN0_MODE << GPIO_MODE_MODE0_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN1_EN
                (NUCODEGEN_GPIO_PA_PIN1_MODE << GPIO_MODE_MODE1_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN2_EN
                (NUCODEGEN_GPIO_PA_PIN2_MODE << GPIO_MODE_MODE2_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN3_EN
                (NUCODEGEN_GPIO_PA_PIN3_MODE << GPIO_MODE_MODE3_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN4_EN
                (NUCODEGEN_GPIO_PA_PIN4_MODE << GPIO_MODE_MODE4_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN5_EN
                (NUCODEGEN_GPIO_PA_PIN5_MODE << GPIO_MODE_MODE5_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN6_EN
                (NUCODEGEN_GPIO_PA_PIN6_MODE << GPIO_MODE_MODE6_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN7_EN
                (NUCODEGEN_GPIO_PA_PIN7_MODE << GPIO_MODE_MODE7_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN8_EN
                (NUCODEGEN_GPIO_PA_PIN8_MODE << GPIO_MODE_MODE8_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN9_EN
                (NUCODEGEN_GPIO_PA_PIN9_MODE << GPIO_MODE_MODE9_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN10_EN
                (NUCODEGEN_GPIO_PA_PIN10_MODE << GPIO_MODE_MODE10_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN11_EN
                (NUCODEGEN_GPIO_PA_PIN11_MODE << GPIO_MODE_MODE11_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN12_EN
                (NUCODEGEN_GPIO_PA_PIN12_MODE << GPIO_MODE_MODE12_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN13_EN
                (NUCODEGEN_GPIO_PA_PIN13_MODE << GPIO_MODE_MODE13_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN14_EN
                (NUCODEGEN_GPIO_PA_PIN14_MODE << GPIO_MODE_MODE14_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN15_EN
                (NUCODEGEN_GPIO_PA_PIN15_MODE << GPIO_MODE_MODE15_Pos) |
#endif
								u32RegDefault;

    //GPIO_PA disable digital input path
    PA->DINOFF =
#if NUCODEGEN_GPIO_PA_PIN0_EN
								 (NUCODEGEN_GPIO_PA_PIN0_DINOFF << GPIO_DINOFF_DINOFF0_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN1_EN
                 (NUCODEGEN_GPIO_PA_PIN1_DINOFF << GPIO_DINOFF_DINOFF1_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN2_EN
                 (NUCODEGEN_GPIO_PA_PIN2_DINOFF << GPIO_DINOFF_DINOFF2_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN3_EN
                 (NUCODEGEN_GPIO_PA_PIN3_DINOFF << GPIO_DINOFF_DINOFF3_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN4_EN
                 (NUCODEGEN_GPIO_PA_PIN4_DINOFF << GPIO_DINOFF_DINOFF4_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN5_EN
                 (NUCODEGEN_GPIO_PA_PIN5_DINOFF << GPIO_DINOFF_DINOFF5_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN6_EN
                 (NUCODEGEN_GPIO_PA_PIN6_DINOFF << GPIO_DINOFF_DINOFF6_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN7_EN
                 (NUCODEGEN_GPIO_PA_PIN7_DINOFF << GPIO_DINOFF_DINOFF7_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN8_EN
                 (NUCODEGEN_GPIO_PA_PIN8_DINOFF << GPIO_DINOFF_DINOFF8_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN9_EN
                 (NUCODEGEN_GPIO_PA_PIN9_DINOFF << GPIO_DINOFF_DINOFF9_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN10_EN
                 (NUCODEGEN_GPIO_PA_PIN10_DINOFF << GPIO_DINOFF_DINOFF10_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN11_EN
                 (NUCODEGEN_GPIO_PA_PIN11_DINOFF << GPIO_DINOFF_DINOFF11_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN12_EN
                 (NUCODEGEN_GPIO_PA_PIN12_DINOFF << GPIO_DINOFF_DINOFF12_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN13_EN
                 (NUCODEGEN_GPIO_PA_PIN13_DINOFF << GPIO_DINOFF_DINOFF13_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN14_EN
                 (NUCODEGEN_GPIO_PA_PIN14_DINOFF << GPIO_DINOFF_DINOFF14_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN15_EN
                 (NUCODEGEN_GPIO_PA_PIN15_DINOFF << GPIO_DINOFF_DINOFF15_Pos) |
#endif
								u32RegDefault;

    //GPIO_PA out data
    PA->DOUT =
#if NUCODEGEN_GPIO_PA_PIN0_EN
								(NUCODEGEN_GPIO_PA_PIN0_DOUT << GPIO_DOUT_DOUT0_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN1_EN
                (NUCODEGEN_GPIO_PA_PIN1_DOUT << GPIO_DOUT_DOUT1_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN2_EN
                (NUCODEGEN_GPIO_PA_PIN2_DOUT << GPIO_DOUT_DOUT2_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN3_EN
                (NUCODEGEN_GPIO_PA_PIN3_DOUT << GPIO_DOUT_DOUT3_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN4_EN
                (NUCODEGEN_GPIO_PA_PIN4_DOUT << GPIO_DOUT_DOUT4_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN5_EN
                (NUCODEGEN_GPIO_PA_PIN5_DOUT << GPIO_DOUT_DOUT5_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN6_EN
                (NUCODEGEN_GPIO_PA_PIN6_DOUT << GPIO_DOUT_DOUT6_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN7_EN
                (NUCODEGEN_GPIO_PA_PIN7_DOUT << GPIO_DOUT_DOUT7_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN8_EN
                (NUCODEGEN_GPIO_PA_PIN8_DOUT << GPIO_DOUT_DOUT8_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN9_EN
                (NUCODEGEN_GPIO_PA_PIN9_DOUT << GPIO_DOUT_DOUT9_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN10_EN
                (NUCODEGEN_GPIO_PA_PIN10_DOUT << GPIO_DOUT_DOUT10_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN11_EN
                (NUCODEGEN_GPIO_PA_PIN11_DOUT << GPIO_DOUT_DOUT11_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN12_EN
                (NUCODEGEN_GPIO_PA_PIN12_DOUT << GPIO_DOUT_DOUT12_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN13_EN
                (NUCODEGEN_GPIO_PA_PIN13_DOUT << GPIO_DOUT_DOUT13_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN14_EN
                (NUCODEGEN_GPIO_PA_PIN14_DOUT << GPIO_DOUT_DOUT14_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN15_EN
                (NUCODEGEN_GPIO_PA_PIN15_DOUT << GPIO_DOUT_DOUT15_Pos) |
#endif
								u32RegDefault;

    //GPIO_PA DOUT mask
    PA->DATMSK =
#if NUCODEGEN_GPIO_PA_PIN0_EN
								 (NUCODEGEN_GPIO_PA_PIN0_DATMSK << GPIO_DATMSK_DATMSK0_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN1_EN
                 (NUCODEGEN_GPIO_PA_PIN1_DATMSK << GPIO_DATMSK_DATMSK1_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN2_EN
                 (NUCODEGEN_GPIO_PA_PIN2_DATMSK << GPIO_DATMSK_DATMSK2_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN3_EN
                 (NUCODEGEN_GPIO_PA_PIN3_DATMSK << GPIO_DATMSK_DATMSK3_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN4_EN
                 (NUCODEGEN_GPIO_PA_PIN4_DATMSK << GPIO_DATMSK_DATMSK4_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN5_EN
                 (NUCODEGEN_GPIO_PA_PIN5_DATMSK << GPIO_DATMSK_DATMSK5_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN6_EN
                 (NUCODEGEN_GPIO_PA_PIN6_DATMSK << GPIO_DATMSK_DATMSK6_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN7_EN
                 (NUCODEGEN_GPIO_PA_PIN7_DATMSK << GPIO_DATMSK_DATMSK7_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN8_EN
                 (NUCODEGEN_GPIO_PA_PIN8_DATMSK << GPIO_DATMSK_DATMSK8_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN9_EN
                 (NUCODEGEN_GPIO_PA_PIN9_DATMSK << GPIO_DATMSK_DATMSK9_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN10_EN
                 (NUCODEGEN_GPIO_PA_PIN10_DATMSK << GPIO_DATMSK_DATMSK10_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN11_EN
                 (NUCODEGEN_GPIO_PA_PIN11_DATMSK << GPIO_DATMSK_DATMSK11_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN12_EN
                 (NUCODEGEN_GPIO_PA_PIN12_DATMSK << GPIO_DATMSK_DATMSK12_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN13_EN
                 (NUCODEGEN_GPIO_PA_PIN13_DATMSK << GPIO_DATMSK_DATMSK13_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN14_EN
                 (NUCODEGEN_GPIO_PA_PIN14_DATMSK << GPIO_DATMSK_DATMSK14_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN15_EN
                 (NUCODEGEN_GPIO_PA_PIN15_DATMSK << GPIO_DATMSK_DATMSK15_Pos) |
#endif
								u32RegDefault;

    //GPIO_PA enable de-bounce
    PA->DBEN =
#if NUCODEGEN_GPIO_PA_PIN0_EN
								(NUCODEGEN_GPIO_PA_PIN0_DBEN << GPIO_DBEN_DBEN0_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN1_EN
                (NUCODEGEN_GPIO_PA_PIN1_DBEN << GPIO_DBEN_DBEN1_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN2_EN
                (NUCODEGEN_GPIO_PA_PIN2_DBEN << GPIO_DBEN_DBEN2_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN3_EN
                (NUCODEGEN_GPIO_PA_PIN3_DBEN << GPIO_DBEN_DBEN3_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN4_EN
                (NUCODEGEN_GPIO_PA_PIN4_DBEN << GPIO_DBEN_DBEN4_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN5_EN
                (NUCODEGEN_GPIO_PA_PIN5_DBEN << GPIO_DBEN_DBEN5_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN6_EN
                (NUCODEGEN_GPIO_PA_PIN6_DBEN << GPIO_DBEN_DBEN6_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN7_EN
                (NUCODEGEN_GPIO_PA_PIN7_DBEN << GPIO_DBEN_DBEN7_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN8_EN
                (NUCODEGEN_GPIO_PA_PIN8_DBEN << GPIO_DBEN_DBEN8_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN9_EN
                (NUCODEGEN_GPIO_PA_PIN9_DBEN << GPIO_DBEN_DBEN9_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN10_EN
                (NUCODEGEN_GPIO_PA_PIN10_DBEN << GPIO_DBEN_DBEN10_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN11_EN
                (NUCODEGEN_GPIO_PA_PIN11_DBEN << GPIO_DBEN_DBEN11_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN12_EN
                (NUCODEGEN_GPIO_PA_PIN12_DBEN << GPIO_DBEN_DBEN12_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN13_EN
                (NUCODEGEN_GPIO_PA_PIN13_DBEN << GPIO_DBEN_DBEN13_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN14_EN
                (NUCODEGEN_GPIO_PA_PIN14_DBEN << GPIO_DBEN_DBEN14_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN15_EN
                (NUCODEGEN_GPIO_PA_PIN15_DBEN << GPIO_DBEN_DBEN15_Pos) |
#endif
								u32RegDefault;

    //GPIO_PA edge or level interrupt
    PA->INTTYPE =
#if NUCODEGEN_GPIO_PA_PIN0_EN
									(NUCODEGEN_GPIO_PA_PIN0_INTTYPE << GPIO_INTTYPE_TYPE0_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN1_EN
                  (NUCODEGEN_GPIO_PA_PIN1_INTTYPE << GPIO_INTTYPE_TYPE1_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN2_EN
                  (NUCODEGEN_GPIO_PA_PIN2_INTTYPE << GPIO_INTTYPE_TYPE2_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN3_EN
                  (NUCODEGEN_GPIO_PA_PIN3_INTTYPE << GPIO_INTTYPE_TYPE3_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN4_EN
                  (NUCODEGEN_GPIO_PA_PIN4_INTTYPE << GPIO_INTTYPE_TYPE4_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN5_EN
                  (NUCODEGEN_GPIO_PA_PIN5_INTTYPE << GPIO_INTTYPE_TYPE5_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN6_EN
                  (NUCODEGEN_GPIO_PA_PIN6_INTTYPE << GPIO_INTTYPE_TYPE6_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN7_EN
                  (NUCODEGEN_GPIO_PA_PIN7_INTTYPE << GPIO_INTTYPE_TYPE7_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN8_EN
                  (NUCODEGEN_GPIO_PA_PIN8_INTTYPE << GPIO_INTTYPE_TYPE8_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN9_EN
                  (NUCODEGEN_GPIO_PA_PIN9_INTTYPE << GPIO_INTTYPE_TYPE9_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN10_EN
                  (NUCODEGEN_GPIO_PA_PIN10_INTTYPE << GPIO_INTTYPE_TYPE10_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN11_EN
                  (NUCODEGEN_GPIO_PA_PIN11_INTTYPE << GPIO_INTTYPE_TYPE11_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN12_EN
                  (NUCODEGEN_GPIO_PA_PIN12_INTTYPE << GPIO_INTTYPE_TYPE12_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN13_EN
                  (NUCODEGEN_GPIO_PA_PIN13_INTTYPE << GPIO_INTTYPE_TYPE13_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN14_EN
                  (NUCODEGEN_GPIO_PA_PIN14_INTTYPE << GPIO_INTTYPE_TYPE14_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN15_EN
                  (NUCODEGEN_GPIO_PA_PIN15_INTTYPE << GPIO_INTTYPE_TYPE15_Pos) |
#endif
								u32RegDefault;

    //GPIO_PA enable falling(edge) or low(level) interrupt
    PA->INTEN =
#if NUCODEGEN_GPIO_PA_PIN0_EN
								(NUCODEGEN_GPIO_PA_PIN0_FLIEN << GPIO_INTEN_FLIEN0_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN1_EN
                (NUCODEGEN_GPIO_PA_PIN1_FLIEN << GPIO_INTEN_FLIEN1_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN2_EN
                (NUCODEGEN_GPIO_PA_PIN2_FLIEN << GPIO_INTEN_FLIEN2_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN3_EN
                (NUCODEGEN_GPIO_PA_PIN3_FLIEN << GPIO_INTEN_FLIEN3_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN4_EN
                (NUCODEGEN_GPIO_PA_PIN4_FLIEN << GPIO_INTEN_FLIEN4_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN5_EN
                (NUCODEGEN_GPIO_PA_PIN5_FLIEN << GPIO_INTEN_FLIEN5_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN6_EN
                (NUCODEGEN_GPIO_PA_PIN6_FLIEN << GPIO_INTEN_FLIEN6_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN7_EN
                (NUCODEGEN_GPIO_PA_PIN7_FLIEN << GPIO_INTEN_FLIEN7_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN8_EN
                (NUCODEGEN_GPIO_PA_PIN8_FLIEN << GPIO_INTEN_FLIEN8_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN9_EN
                (NUCODEGEN_GPIO_PA_PIN9_FLIEN << GPIO_INTEN_FLIEN9_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN10_EN
                (NUCODEGEN_GPIO_PA_PIN10_FLIEN << GPIO_INTEN_FLIEN10_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN11_EN
                (NUCODEGEN_GPIO_PA_PIN11_FLIEN << GPIO_INTEN_FLIEN11_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN12_EN
                (NUCODEGEN_GPIO_PA_PIN12_FLIEN << GPIO_INTEN_FLIEN12_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN13_EN
                (NUCODEGEN_GPIO_PA_PIN13_FLIEN << GPIO_INTEN_FLIEN13_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN14_EN
                (NUCODEGEN_GPIO_PA_PIN14_FLIEN << GPIO_INTEN_FLIEN14_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN15_EN
                (NUCODEGEN_GPIO_PA_PIN15_FLIEN << GPIO_INTEN_FLIEN15_Pos) |
#endif
								u32RegDefault;

    //GPIO_PA enable rising(edge) or high(level) interrupt
    PA->INTEN |=
#if NUCODEGEN_GPIO_PA_PIN0_EN
								 (NUCODEGEN_GPIO_PA_PIN0_RHIEN << GPIO_INTEN_RHIEN0_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN1_EN
                 (NUCODEGEN_GPIO_PA_PIN1_RHIEN << GPIO_INTEN_RHIEN1_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN2_EN
                 (NUCODEGEN_GPIO_PA_PIN2_RHIEN << GPIO_INTEN_RHIEN2_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN3_EN
                 (NUCODEGEN_GPIO_PA_PIN3_RHIEN << GPIO_INTEN_RHIEN3_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN4_EN
                 (NUCODEGEN_GPIO_PA_PIN4_RHIEN << GPIO_INTEN_RHIEN4_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN5_EN
                 (NUCODEGEN_GPIO_PA_PIN5_RHIEN << GPIO_INTEN_RHIEN5_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN6_EN
                 (NUCODEGEN_GPIO_PA_PIN6_RHIEN << GPIO_INTEN_RHIEN6_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN7_EN
                 (NUCODEGEN_GPIO_PA_PIN7_RHIEN << GPIO_INTEN_RHIEN7_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN8_EN
                 (NUCODEGEN_GPIO_PA_PIN8_RHIEN << GPIO_INTEN_RHIEN8_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN9_EN
                 (NUCODEGEN_GPIO_PA_PIN9_RHIEN << GPIO_INTEN_RHIEN9_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN10_EN
                 (NUCODEGEN_GPIO_PA_PIN10_RHIEN << GPIO_INTEN_RHIEN10_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN11_EN
                 (NUCODEGEN_GPIO_PA_PIN11_RHIEN << GPIO_INTEN_RHIEN11_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN12_EN
                 (NUCODEGEN_GPIO_PA_PIN12_RHIEN << GPIO_INTEN_RHIEN12_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN13_EN
                 (NUCODEGEN_GPIO_PA_PIN13_RHIEN << GPIO_INTEN_RHIEN13_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN14_EN
                 (NUCODEGEN_GPIO_PA_PIN14_RHIEN << GPIO_INTEN_RHIEN14_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN15_EN
                 (NUCODEGEN_GPIO_PA_PIN15_RHIEN << GPIO_INTEN_RHIEN15_Pos) |
#endif
								u32RegDefault;

    //GPIO_PA slew rate
    PA->SLEWCTL =
#if NUCODEGEN_GPIO_PA_PIN0_EN
									(NUCODEGEN_GPIO_PA_PIN0_SLEW << GPIO_SLEWCTL_HSREN0_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN1_EN
                  (NUCODEGEN_GPIO_PA_PIN1_SLEW << GPIO_SLEWCTL_HSREN1_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN2_EN
                  (NUCODEGEN_GPIO_PA_PIN2_SLEW << GPIO_SLEWCTL_HSREN2_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN3_EN
                  (NUCODEGEN_GPIO_PA_PIN3_SLEW << GPIO_SLEWCTL_HSREN3_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN4_EN
                  (NUCODEGEN_GPIO_PA_PIN4_SLEW << GPIO_SLEWCTL_HSREN4_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN5_EN
                  (NUCODEGEN_GPIO_PA_PIN5_SLEW << GPIO_SLEWCTL_HSREN5_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN6_EN
                  (NUCODEGEN_GPIO_PA_PIN6_SLEW << GPIO_SLEWCTL_HSREN6_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN7_EN
                  (NUCODEGEN_GPIO_PA_PIN7_SLEW << GPIO_SLEWCTL_HSREN7_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN8_EN
                  (NUCODEGEN_GPIO_PA_PIN8_SLEW << GPIO_SLEWCTL_HSREN8_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN9_EN
                  (NUCODEGEN_GPIO_PA_PIN9_SLEW << GPIO_SLEWCTL_HSREN9_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN10_EN
                  (NUCODEGEN_GPIO_PA_PIN10_SLEW << GPIO_SLEWCTL_HSREN10_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN11_EN
                  (NUCODEGEN_GPIO_PA_PIN11_SLEW << GPIO_SLEWCTL_HSREN11_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN12_EN
                  (NUCODEGEN_GPIO_PA_PIN12_SLEW << GPIO_SLEWCTL_HSREN12_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN13_EN
                  (NUCODEGEN_GPIO_PA_PIN13_SLEW << GPIO_SLEWCTL_HSREN13_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN14_EN
                  (NUCODEGEN_GPIO_PA_PIN14_SLEW << GPIO_SLEWCTL_HSREN14_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN15_EN
                  (NUCODEGEN_GPIO_PA_PIN15_SLEW << GPIO_SLEWCTL_HSREN15_Pos) |
#endif
								u32RegDefault;

    //GPIO_PA pull-up or pull-down
    PA->PUSEL =
#if NUCODEGEN_GPIO_PA_PIN0_EN
								(NUCODEGEN_GPIO_PA_PIN0_PUSEL << GPIO_PUSEL_PUSEL0_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN1_EN
                (NUCODEGEN_GPIO_PA_PIN1_PUSEL << GPIO_PUSEL_PUSEL1_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN2_EN
                (NUCODEGEN_GPIO_PA_PIN2_PUSEL << GPIO_PUSEL_PUSEL2_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN3_EN
                (NUCODEGEN_GPIO_PA_PIN3_PUSEL << GPIO_PUSEL_PUSEL3_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN4_EN
                (NUCODEGEN_GPIO_PA_PIN4_PUSEL << GPIO_PUSEL_PUSEL4_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN5_EN
                (NUCODEGEN_GPIO_PA_PIN5_PUSEL << GPIO_PUSEL_PUSEL5_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN6_EN
                (NUCODEGEN_GPIO_PA_PIN6_PUSEL << GPIO_PUSEL_PUSEL6_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN7_EN
                (NUCODEGEN_GPIO_PA_PIN7_PUSEL << GPIO_PUSEL_PUSEL7_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN8_EN
                (NUCODEGEN_GPIO_PA_PIN8_PUSEL << GPIO_PUSEL_PUSEL8_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN9_EN
                (NUCODEGEN_GPIO_PA_PIN9_PUSEL << GPIO_PUSEL_PUSEL9_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN10_EN
                (NUCODEGEN_GPIO_PA_PIN10_PUSEL << GPIO_PUSEL_PUSEL10_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN11_EN
                (NUCODEGEN_GPIO_PA_PIN11_PUSEL << GPIO_PUSEL_PUSEL11_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN12_EN
                (NUCODEGEN_GPIO_PA_PIN12_PUSEL << GPIO_PUSEL_PUSEL12_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN13_EN
                (NUCODEGEN_GPIO_PA_PIN13_PUSEL << GPIO_PUSEL_PUSEL13_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN14_EN
                (NUCODEGEN_GPIO_PA_PIN14_PUSEL << GPIO_PUSEL_PUSEL14_Pos) |
#endif
#if NUCODEGEN_GPIO_PA_PIN15_EN
                (NUCODEGEN_GPIO_PA_PIN15_PUSEL << GPIO_PUSEL_PUSEL15_Pos) |
#endif
								u32RegDefault;

#if(NUCODEGEN_GPIO_PA_CLR_DB_ICLKON)
    GPIO_CLR_DEBOUNCE_ICLKON(PA);
#endif

#if(NUCODEGEN_GPIO_PA_INT)
    NVIC_EnableIRQ(GPA_IRQn);
#endif

#if(NUCODEGEN_GPIO_PA_EINT0)
    NVIC_EnableIRQ(EINT0_IRQn);//PA.6
#endif

#if(NUCODEGEN_GPIO_PA_EINT1)
    NVIC_EnableIRQ(EINT1_IRQn);//PA.7
#endif

#if(NUCODEGEN_GPIO_PA_EINT4)
    NVIC_EnableIRQ(EINT4_IRQn);//PA.8
#endif
#endif //NUCODEGEN_GPIO_PA

#if(NUCODEGEN_GPIO_PB)
    //GPIO_PB mode
    PB->MODE =
#if NUCODEGEN_GPIO_PB_PIN0_EN
								(NUCODEGEN_GPIO_PB_PIN0_MODE << GPIO_MODE_MODE0_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN1_EN
                (NUCODEGEN_GPIO_PB_PIN1_MODE << GPIO_MODE_MODE1_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN2_EN
                (NUCODEGEN_GPIO_PB_PIN2_MODE << GPIO_MODE_MODE2_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN3_EN
                (NUCODEGEN_GPIO_PB_PIN3_MODE << GPIO_MODE_MODE3_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN4_EN
                (NUCODEGEN_GPIO_PB_PIN4_MODE << GPIO_MODE_MODE4_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN5_EN
                (NUCODEGEN_GPIO_PB_PIN5_MODE << GPIO_MODE_MODE5_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN6_EN
                (NUCODEGEN_GPIO_PB_PIN6_MODE << GPIO_MODE_MODE6_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN7_EN
                (NUCODEGEN_GPIO_PB_PIN7_MODE << GPIO_MODE_MODE7_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN8_EN
                (NUCODEGEN_GPIO_PB_PIN8_MODE << GPIO_MODE_MODE8_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN9_EN
                (NUCODEGEN_GPIO_PB_PIN9_MODE << GPIO_MODE_MODE9_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN10_EN
                (NUCODEGEN_GPIO_PB_PIN10_MODE << GPIO_MODE_MODE10_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN11_EN
                (NUCODEGEN_GPIO_PB_PIN11_MODE << GPIO_MODE_MODE11_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN12_EN
                (NUCODEGEN_GPIO_PB_PIN12_MODE << GPIO_MODE_MODE12_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN13_EN
                (NUCODEGEN_GPIO_PB_PIN13_MODE << GPIO_MODE_MODE13_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN14_EN
                (NUCODEGEN_GPIO_PB_PIN14_MODE << GPIO_MODE_MODE14_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN15_EN
                (NUCODEGEN_GPIO_PB_PIN15_MODE << GPIO_MODE_MODE15_Pos) |
#endif
								u32RegDefault;

    //GPIO_PB disable digital input path
    PB->DINOFF =
#if NUCODEGEN_GPIO_PB_PIN0_EN
								 (NUCODEGEN_GPIO_PB_PIN0_DINOFF << GPIO_DINOFF_DINOFF0_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN1_EN
                 (NUCODEGEN_GPIO_PB_PIN1_DINOFF << GPIO_DINOFF_DINOFF1_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN2_EN
                 (NUCODEGEN_GPIO_PB_PIN2_DINOFF << GPIO_DINOFF_DINOFF2_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN3_EN
                 (NUCODEGEN_GPIO_PB_PIN3_DINOFF << GPIO_DINOFF_DINOFF3_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN4_EN
                 (NUCODEGEN_GPIO_PB_PIN4_DINOFF << GPIO_DINOFF_DINOFF4_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN5_EN
                 (NUCODEGEN_GPIO_PB_PIN5_DINOFF << GPIO_DINOFF_DINOFF5_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN6_EN
                 (NUCODEGEN_GPIO_PB_PIN6_DINOFF << GPIO_DINOFF_DINOFF6_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN7_EN
                 (NUCODEGEN_GPIO_PB_PIN7_DINOFF << GPIO_DINOFF_DINOFF7_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN8_EN
                 (NUCODEGEN_GPIO_PB_PIN8_DINOFF << GPIO_DINOFF_DINOFF8_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN9_EN
                 (NUCODEGEN_GPIO_PB_PIN9_DINOFF << GPIO_DINOFF_DINOFF9_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN10_EN
                 (NUCODEGEN_GPIO_PB_PIN10_DINOFF << GPIO_DINOFF_DINOFF10_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN11_EN
                 (NUCODEGEN_GPIO_PB_PIN11_DINOFF << GPIO_DINOFF_DINOFF11_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN12_EN
                 (NUCODEGEN_GPIO_PB_PIN12_DINOFF << GPIO_DINOFF_DINOFF12_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN13_EN
                 (NUCODEGEN_GPIO_PB_PIN13_DINOFF << GPIO_DINOFF_DINOFF13_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN14_EN
                 (NUCODEGEN_GPIO_PB_PIN14_DINOFF << GPIO_DINOFF_DINOFF14_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN15_EN
                 (NUCODEGEN_GPIO_PB_PIN15_DINOFF << GPIO_DINOFF_DINOFF15_Pos) |
#endif
								u32RegDefault;

    //GPIO_PB out data
    PB->DOUT =
#if NUCODEGEN_GPIO_PB_PIN0_EN
								(NUCODEGEN_GPIO_PB_PIN0_DOUT << GPIO_DOUT_DOUT0_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN1_EN
                (NUCODEGEN_GPIO_PB_PIN1_DOUT << GPIO_DOUT_DOUT1_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN2_EN
                (NUCODEGEN_GPIO_PB_PIN2_DOUT << GPIO_DOUT_DOUT2_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN3_EN
                (NUCODEGEN_GPIO_PB_PIN3_DOUT << GPIO_DOUT_DOUT3_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN4_EN
                (NUCODEGEN_GPIO_PB_PIN4_DOUT << GPIO_DOUT_DOUT4_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN5_EN
                (NUCODEGEN_GPIO_PB_PIN5_DOUT << GPIO_DOUT_DOUT5_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN6_EN
                (NUCODEGEN_GPIO_PB_PIN6_DOUT << GPIO_DOUT_DOUT6_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN7_EN
                (NUCODEGEN_GPIO_PB_PIN7_DOUT << GPIO_DOUT_DOUT7_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN8_EN
                (NUCODEGEN_GPIO_PB_PIN8_DOUT << GPIO_DOUT_DOUT8_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN9_EN
                (NUCODEGEN_GPIO_PB_PIN9_DOUT << GPIO_DOUT_DOUT9_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN10_EN
                (NUCODEGEN_GPIO_PB_PIN10_DOUT << GPIO_DOUT_DOUT10_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN11_EN
                (NUCODEGEN_GPIO_PB_PIN11_DOUT << GPIO_DOUT_DOUT11_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN12_EN
                (NUCODEGEN_GPIO_PB_PIN12_DOUT << GPIO_DOUT_DOUT12_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN13_EN
                (NUCODEGEN_GPIO_PB_PIN13_DOUT << GPIO_DOUT_DOUT13_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN14_EN
                (NUCODEGEN_GPIO_PB_PIN14_DOUT << GPIO_DOUT_DOUT14_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN15_EN
                (NUCODEGEN_GPIO_PB_PIN15_DOUT << GPIO_DOUT_DOUT15_Pos) |
#endif
								u32RegDefault;

    //GPIO_PB DOUT mask
    PB->DATMSK =
#if NUCODEGEN_GPIO_PB_PIN0_EN
								 (NUCODEGEN_GPIO_PB_PIN0_DATMSK << GPIO_DATMSK_DATMSK0_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN1_EN
                 (NUCODEGEN_GPIO_PB_PIN1_DATMSK << GPIO_DATMSK_DATMSK1_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN2_EN
                 (NUCODEGEN_GPIO_PB_PIN2_DATMSK << GPIO_DATMSK_DATMSK2_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN3_EN
                 (NUCODEGEN_GPIO_PB_PIN3_DATMSK << GPIO_DATMSK_DATMSK3_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN4_EN
                 (NUCODEGEN_GPIO_PB_PIN4_DATMSK << GPIO_DATMSK_DATMSK4_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN5_EN
                 (NUCODEGEN_GPIO_PB_PIN5_DATMSK << GPIO_DATMSK_DATMSK5_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN6_EN
                 (NUCODEGEN_GPIO_PB_PIN6_DATMSK << GPIO_DATMSK_DATMSK6_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN7_EN
                 (NUCODEGEN_GPIO_PB_PIN7_DATMSK << GPIO_DATMSK_DATMSK7_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN8_EN
                 (NUCODEGEN_GPIO_PB_PIN8_DATMSK << GPIO_DATMSK_DATMSK8_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN9_EN
                 (NUCODEGEN_GPIO_PB_PIN9_DATMSK << GPIO_DATMSK_DATMSK9_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN10_EN
                 (NUCODEGEN_GPIO_PB_PIN10_DATMSK << GPIO_DATMSK_DATMSK10_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN11_EN
                 (NUCODEGEN_GPIO_PB_PIN11_DATMSK << GPIO_DATMSK_DATMSK11_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN12_EN
                 (NUCODEGEN_GPIO_PB_PIN12_DATMSK << GPIO_DATMSK_DATMSK12_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN13_EN
                 (NUCODEGEN_GPIO_PB_PIN13_DATMSK << GPIO_DATMSK_DATMSK13_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN14_EN
                 (NUCODEGEN_GPIO_PB_PIN14_DATMSK << GPIO_DATMSK_DATMSK14_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN15_EN
                 (NUCODEGEN_GPIO_PB_PIN15_DATMSK << GPIO_DATMSK_DATMSK15_Pos) |
#endif
								u32RegDefault;

    //GPIO_PB enable de-bounce
    PB->DBEN =
#if NUCODEGEN_GPIO_PB_PIN0_EN
								(NUCODEGEN_GPIO_PB_PIN0_DBEN << GPIO_DBEN_DBEN0_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN1_EN
                (NUCODEGEN_GPIO_PB_PIN1_DBEN << GPIO_DBEN_DBEN1_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN2_EN
                (NUCODEGEN_GPIO_PB_PIN2_DBEN << GPIO_DBEN_DBEN2_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN3_EN
                (NUCODEGEN_GPIO_PB_PIN3_DBEN << GPIO_DBEN_DBEN3_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN4_EN
                (NUCODEGEN_GPIO_PB_PIN4_DBEN << GPIO_DBEN_DBEN4_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN5_EN
                (NUCODEGEN_GPIO_PB_PIN5_DBEN << GPIO_DBEN_DBEN5_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN6_EN
                (NUCODEGEN_GPIO_PB_PIN6_DBEN << GPIO_DBEN_DBEN6_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN7_EN
                (NUCODEGEN_GPIO_PB_PIN7_DBEN << GPIO_DBEN_DBEN7_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN8_EN
                (NUCODEGEN_GPIO_PB_PIN8_DBEN << GPIO_DBEN_DBEN8_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN9_EN
                (NUCODEGEN_GPIO_PB_PIN9_DBEN << GPIO_DBEN_DBEN9_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN10_EN
                (NUCODEGEN_GPIO_PB_PIN10_DBEN << GPIO_DBEN_DBEN10_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN11_EN
                (NUCODEGEN_GPIO_PB_PIN11_DBEN << GPIO_DBEN_DBEN11_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN12_EN
                (NUCODEGEN_GPIO_PB_PIN12_DBEN << GPIO_DBEN_DBEN12_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN13_EN
                (NUCODEGEN_GPIO_PB_PIN13_DBEN << GPIO_DBEN_DBEN13_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN14_EN
                (NUCODEGEN_GPIO_PB_PIN14_DBEN << GPIO_DBEN_DBEN14_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN15_EN
                (NUCODEGEN_GPIO_PB_PIN15_DBEN << GPIO_DBEN_DBEN15_Pos) |
#endif
								u32RegDefault;

    //GPIO_PB edge or level interrupt
    PB->INTTYPE =
#if NUCODEGEN_GPIO_PB_PIN0_EN
									(NUCODEGEN_GPIO_PB_PIN0_INTTYPE << GPIO_INTTYPE_TYPE0_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN1_EN
                  (NUCODEGEN_GPIO_PB_PIN1_INTTYPE << GPIO_INTTYPE_TYPE1_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN2_EN
                  (NUCODEGEN_GPIO_PB_PIN2_INTTYPE << GPIO_INTTYPE_TYPE2_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN3_EN
                  (NUCODEGEN_GPIO_PB_PIN3_INTTYPE << GPIO_INTTYPE_TYPE3_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN4_EN
                  (NUCODEGEN_GPIO_PB_PIN4_INTTYPE << GPIO_INTTYPE_TYPE4_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN5_EN
                  (NUCODEGEN_GPIO_PB_PIN5_INTTYPE << GPIO_INTTYPE_TYPE5_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN6_EN
                  (NUCODEGEN_GPIO_PB_PIN6_INTTYPE << GPIO_INTTYPE_TYPE6_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN7_EN
                  (NUCODEGEN_GPIO_PB_PIN7_INTTYPE << GPIO_INTTYPE_TYPE7_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN8_EN
                  (NUCODEGEN_GPIO_PB_PIN8_INTTYPE << GPIO_INTTYPE_TYPE8_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN9_EN
                  (NUCODEGEN_GPIO_PB_PIN9_INTTYPE << GPIO_INTTYPE_TYPE9_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN10_EN
                  (NUCODEGEN_GPIO_PB_PIN10_INTTYPE << GPIO_INTTYPE_TYPE10_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN11_EN
                  (NUCODEGEN_GPIO_PB_PIN11_INTTYPE << GPIO_INTTYPE_TYPE11_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN12_EN
                  (NUCODEGEN_GPIO_PB_PIN12_INTTYPE << GPIO_INTTYPE_TYPE12_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN13_EN
                  (NUCODEGEN_GPIO_PB_PIN13_INTTYPE << GPIO_INTTYPE_TYPE13_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN14_EN
                  (NUCODEGEN_GPIO_PB_PIN14_INTTYPE << GPIO_INTTYPE_TYPE14_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN15_EN
                  (NUCODEGEN_GPIO_PB_PIN15_INTTYPE << GPIO_INTTYPE_TYPE15_Pos) |
#endif
								u32RegDefault;

    //GPIO_PB enable falling(edge) or low(level) interrupt
    PB->INTEN =
#if NUCODEGEN_GPIO_PB_PIN0_EN
								(NUCODEGEN_GPIO_PB_PIN0_FLIEN << GPIO_INTEN_FLIEN0_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN1_EN
                (NUCODEGEN_GPIO_PB_PIN1_FLIEN << GPIO_INTEN_FLIEN1_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN2_EN
                (NUCODEGEN_GPIO_PB_PIN2_FLIEN << GPIO_INTEN_FLIEN2_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN3_EN
                (NUCODEGEN_GPIO_PB_PIN3_FLIEN << GPIO_INTEN_FLIEN3_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN4_EN
                (NUCODEGEN_GPIO_PB_PIN4_FLIEN << GPIO_INTEN_FLIEN4_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN5_EN
                (NUCODEGEN_GPIO_PB_PIN5_FLIEN << GPIO_INTEN_FLIEN5_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN6_EN
                (NUCODEGEN_GPIO_PB_PIN6_FLIEN << GPIO_INTEN_FLIEN6_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN7_EN
                (NUCODEGEN_GPIO_PB_PIN7_FLIEN << GPIO_INTEN_FLIEN7_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN8_EN
                (NUCODEGEN_GPIO_PB_PIN8_FLIEN << GPIO_INTEN_FLIEN8_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN9_EN
                (NUCODEGEN_GPIO_PB_PIN9_FLIEN << GPIO_INTEN_FLIEN9_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN10_EN
                (NUCODEGEN_GPIO_PB_PIN10_FLIEN << GPIO_INTEN_FLIEN10_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN11_EN
                (NUCODEGEN_GPIO_PB_PIN11_FLIEN << GPIO_INTEN_FLIEN11_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN12_EN
                (NUCODEGEN_GPIO_PB_PIN12_FLIEN << GPIO_INTEN_FLIEN12_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN13_EN
                (NUCODEGEN_GPIO_PB_PIN13_FLIEN << GPIO_INTEN_FLIEN13_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN14_EN
                (NUCODEGEN_GPIO_PB_PIN14_FLIEN << GPIO_INTEN_FLIEN14_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN15_EN
                (NUCODEGEN_GPIO_PB_PIN15_FLIEN << GPIO_INTEN_FLIEN15_Pos) |
#endif
								u32RegDefault;

    //GPIO_PB enable rising(edge) or high(level) interrupt
    PB->INTEN |=
#if NUCODEGEN_GPIO_PB_PIN0_EN
								 (NUCODEGEN_GPIO_PB_PIN0_RHIEN << GPIO_INTEN_RHIEN0_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN1_EN
                 (NUCODEGEN_GPIO_PB_PIN1_RHIEN << GPIO_INTEN_RHIEN1_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN2_EN
                 (NUCODEGEN_GPIO_PB_PIN2_RHIEN << GPIO_INTEN_RHIEN2_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN3_EN
                 (NUCODEGEN_GPIO_PB_PIN3_RHIEN << GPIO_INTEN_RHIEN3_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN4_EN
                 (NUCODEGEN_GPIO_PB_PIN4_RHIEN << GPIO_INTEN_RHIEN4_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN5_EN
                 (NUCODEGEN_GPIO_PB_PIN5_RHIEN << GPIO_INTEN_RHIEN5_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN6_EN
                 (NUCODEGEN_GPIO_PB_PIN6_RHIEN << GPIO_INTEN_RHIEN6_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN7_EN
                 (NUCODEGEN_GPIO_PB_PIN7_RHIEN << GPIO_INTEN_RHIEN7_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN8_EN
                 (NUCODEGEN_GPIO_PB_PIN8_RHIEN << GPIO_INTEN_RHIEN8_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN9_EN
                 (NUCODEGEN_GPIO_PB_PIN9_RHIEN << GPIO_INTEN_RHIEN9_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN10_EN
                 (NUCODEGEN_GPIO_PB_PIN10_RHIEN << GPIO_INTEN_RHIEN10_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN11_EN
                 (NUCODEGEN_GPIO_PB_PIN11_RHIEN << GPIO_INTEN_RHIEN11_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN12_EN
                 (NUCODEGEN_GPIO_PB_PIN12_RHIEN << GPIO_INTEN_RHIEN12_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN13_EN
                 (NUCODEGEN_GPIO_PB_PIN13_RHIEN << GPIO_INTEN_RHIEN13_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN14_EN
                 (NUCODEGEN_GPIO_PB_PIN14_RHIEN << GPIO_INTEN_RHIEN14_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN15_EN
                 (NUCODEGEN_GPIO_PB_PIN15_RHIEN << GPIO_INTEN_RHIEN15_Pos) |
#endif
								u32RegDefault;

    //GPIO_PB slew rate
    PB->SLEWCTL =
#if NUCODEGEN_GPIO_PB_PIN0_EN
									(NUCODEGEN_GPIO_PB_PIN0_SLEW << GPIO_SLEWCTL_HSREN0_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN1_EN
                  (NUCODEGEN_GPIO_PB_PIN1_SLEW << GPIO_SLEWCTL_HSREN1_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN2_EN
                  (NUCODEGEN_GPIO_PB_PIN2_SLEW << GPIO_SLEWCTL_HSREN2_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN3_EN
                  (NUCODEGEN_GPIO_PB_PIN3_SLEW << GPIO_SLEWCTL_HSREN3_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN4_EN
                  (NUCODEGEN_GPIO_PB_PIN4_SLEW << GPIO_SLEWCTL_HSREN4_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN5_EN
                  (NUCODEGEN_GPIO_PB_PIN5_SLEW << GPIO_SLEWCTL_HSREN5_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN6_EN
                  (NUCODEGEN_GPIO_PB_PIN6_SLEW << GPIO_SLEWCTL_HSREN6_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN7_EN
                  (NUCODEGEN_GPIO_PB_PIN7_SLEW << GPIO_SLEWCTL_HSREN7_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN8_EN
                  (NUCODEGEN_GPIO_PB_PIN8_SLEW << GPIO_SLEWCTL_HSREN8_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN9_EN
                  (NUCODEGEN_GPIO_PB_PIN9_SLEW << GPIO_SLEWCTL_HSREN9_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN10_EN
                  (NUCODEGEN_GPIO_PB_PIN10_SLEW << GPIO_SLEWCTL_HSREN10_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN11_EN
                  (NUCODEGEN_GPIO_PB_PIN11_SLEW << GPIO_SLEWCTL_HSREN11_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN12_EN
                  (NUCODEGEN_GPIO_PB_PIN12_SLEW << GPIO_SLEWCTL_HSREN12_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN13_EN
                  (NUCODEGEN_GPIO_PB_PIN13_SLEW << GPIO_SLEWCTL_HSREN13_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN14_EN
                  (NUCODEGEN_GPIO_PB_PIN14_SLEW << GPIO_SLEWCTL_HSREN14_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN15_EN
                  (NUCODEGEN_GPIO_PB_PIN15_SLEW << GPIO_SLEWCTL_HSREN15_Pos) |
#endif
								u32RegDefault;

    //GPIO_PB pull-up or pull-down
    PB->PUSEL =
#if NUCODEGEN_GPIO_PB_PIN0_EN
								(NUCODEGEN_GPIO_PB_PIN0_PUSEL << GPIO_PUSEL_PUSEL0_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN1_EN
                (NUCODEGEN_GPIO_PB_PIN1_PUSEL << GPIO_PUSEL_PUSEL1_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN2_EN
                (NUCODEGEN_GPIO_PB_PIN2_PUSEL << GPIO_PUSEL_PUSEL2_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN3_EN
                (NUCODEGEN_GPIO_PB_PIN3_PUSEL << GPIO_PUSEL_PUSEL3_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN4_EN
                (NUCODEGEN_GPIO_PB_PIN4_PUSEL << GPIO_PUSEL_PUSEL4_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN5_EN
                (NUCODEGEN_GPIO_PB_PIN5_PUSEL << GPIO_PUSEL_PUSEL5_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN6_EN
                (NUCODEGEN_GPIO_PB_PIN6_PUSEL << GPIO_PUSEL_PUSEL6_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN7_EN
                (NUCODEGEN_GPIO_PB_PIN7_PUSEL << GPIO_PUSEL_PUSEL7_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN8_EN
                (NUCODEGEN_GPIO_PB_PIN8_PUSEL << GPIO_PUSEL_PUSEL8_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN9_EN
                (NUCODEGEN_GPIO_PB_PIN9_PUSEL << GPIO_PUSEL_PUSEL9_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN10_EN
                (NUCODEGEN_GPIO_PB_PIN10_PUSEL << GPIO_PUSEL_PUSEL10_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN11_EN
                (NUCODEGEN_GPIO_PB_PIN11_PUSEL << GPIO_PUSEL_PUSEL11_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN12_EN
                (NUCODEGEN_GPIO_PB_PIN12_PUSEL << GPIO_PUSEL_PUSEL12_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN13_EN
                (NUCODEGEN_GPIO_PB_PIN13_PUSEL << GPIO_PUSEL_PUSEL13_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN14_EN
                (NUCODEGEN_GPIO_PB_PIN14_PUSEL << GPIO_PUSEL_PUSEL14_Pos) |
#endif
#if NUCODEGEN_GPIO_PB_PIN15_EN
                (NUCODEGEN_GPIO_PB_PIN15_PUSEL << GPIO_PUSEL_PUSEL15_Pos) |
#endif
								u32RegDefault;

#if(NUCODEGEN_GPIO_PB_CLR_DB_ICLKON)
    GPIO_CLR_DEBOUNCE_ICLKON(PB);
#endif

#if(NUCODEGEN_GPIO_PB_INT)
    NVIC_EnableIRQ(GPB_IRQn);
#endif

#if(NUCODEGEN_GPIO_PB_EINT0)
    NVIC_EnableIRQ(EINT0_IRQn);//PB.5
#endif

#if(NUCODEGEN_GPIO_PB_EINT1)
    NVIC_EnableIRQ(EINT1_IRQn);//PB.4
#endif

#if(NUCODEGEN_GPIO_PB_EINT2)
    NVIC_EnableIRQ(EINT2_IRQn);//PB.3
#endif

#if(NUCODEGEN_GPIO_PB_EINT3)
    NVIC_EnableIRQ(EINT3_IRQn);//PB.2
#endif

#if(NUCODEGEN_GPIO_PB_EINT4)
    NVIC_EnableIRQ(EINT4_IRQn);//PB.6
#endif

#if(NUCODEGEN_GPIO_PB_EINT5)
    NVIC_EnableIRQ(EINT5_IRQn);//PB.7
#endif
#endif //NUCODEGEN_GPIO_PB

#if(NUCODEGEN_GPIO_PC)
    //GPIO_PC mode
    PC->MODE =
#if NUCODEGEN_GPIO_PC_PIN0_EN
								(NUCODEGEN_GPIO_PC_PIN0_MODE << GPIO_MODE_MODE0_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN1_EN
                (NUCODEGEN_GPIO_PC_PIN1_MODE << GPIO_MODE_MODE1_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN2_EN
                (NUCODEGEN_GPIO_PC_PIN2_MODE << GPIO_MODE_MODE2_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN3_EN
                (NUCODEGEN_GPIO_PC_PIN3_MODE << GPIO_MODE_MODE3_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN4_EN
                (NUCODEGEN_GPIO_PC_PIN4_MODE << GPIO_MODE_MODE4_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN5_EN
                (NUCODEGEN_GPIO_PC_PIN5_MODE << GPIO_MODE_MODE5_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN6_EN
                (NUCODEGEN_GPIO_PC_PIN6_MODE << GPIO_MODE_MODE6_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN7_EN
                (NUCODEGEN_GPIO_PC_PIN7_MODE << GPIO_MODE_MODE7_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN8_EN
                (NUCODEGEN_GPIO_PC_PIN8_MODE << GPIO_MODE_MODE8_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN9_EN
                (NUCODEGEN_GPIO_PC_PIN9_MODE << GPIO_MODE_MODE9_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN10_EN
                (NUCODEGEN_GPIO_PC_PIN10_MODE << GPIO_MODE_MODE10_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN11_EN
                (NUCODEGEN_GPIO_PC_PIN11_MODE << GPIO_MODE_MODE11_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN12_EN
                (NUCODEGEN_GPIO_PC_PIN12_MODE << GPIO_MODE_MODE12_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN13_EN
                (NUCODEGEN_GPIO_PC_PIN13_MODE << GPIO_MODE_MODE13_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN14_EN
                (NUCODEGEN_GPIO_PC_PIN14_MODE << GPIO_MODE_MODE14_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN15_EN
                (NUCODEGEN_GPIO_PC_PIN15_MODE << GPIO_MODE_MODE15_Pos) |
#endif
								u32RegDefault;

    //GPIO_PC disable digital input path
    PC->DINOFF =
#if NUCODEGEN_GPIO_PC_PIN0_EN
								 (NUCODEGEN_GPIO_PC_PIN0_DINOFF << GPIO_DINOFF_DINOFF0_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN1_EN
                 (NUCODEGEN_GPIO_PC_PIN1_DINOFF << GPIO_DINOFF_DINOFF1_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN2_EN
                 (NUCODEGEN_GPIO_PC_PIN2_DINOFF << GPIO_DINOFF_DINOFF2_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN3_EN
                 (NUCODEGEN_GPIO_PC_PIN3_DINOFF << GPIO_DINOFF_DINOFF3_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN4_EN
                 (NUCODEGEN_GPIO_PC_PIN4_DINOFF << GPIO_DINOFF_DINOFF4_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN5_EN
                 (NUCODEGEN_GPIO_PC_PIN5_DINOFF << GPIO_DINOFF_DINOFF5_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN6_EN
                 (NUCODEGEN_GPIO_PC_PIN6_DINOFF << GPIO_DINOFF_DINOFF6_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN7_EN
                 (NUCODEGEN_GPIO_PC_PIN7_DINOFF << GPIO_DINOFF_DINOFF7_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN8_EN
                 (NUCODEGEN_GPIO_PC_PIN8_DINOFF << GPIO_DINOFF_DINOFF8_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN9_EN
                 (NUCODEGEN_GPIO_PC_PIN9_DINOFF << GPIO_DINOFF_DINOFF9_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN10_EN
                 (NUCODEGEN_GPIO_PC_PIN10_DINOFF << GPIO_DINOFF_DINOFF10_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN11_EN
                 (NUCODEGEN_GPIO_PC_PIN11_DINOFF << GPIO_DINOFF_DINOFF11_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN12_EN
                 (NUCODEGEN_GPIO_PC_PIN12_DINOFF << GPIO_DINOFF_DINOFF12_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN13_EN
                 (NUCODEGEN_GPIO_PC_PIN13_DINOFF << GPIO_DINOFF_DINOFF13_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN14_EN
                 (NUCODEGEN_GPIO_PC_PIN14_DINOFF << GPIO_DINOFF_DINOFF14_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN15_EN
                 (NUCODEGEN_GPIO_PC_PIN15_DINOFF << GPIO_DINOFF_DINOFF15_Pos) |
#endif
								u32RegDefault;

    //GPIO_PC out data
    PC->DOUT =
#if NUCODEGEN_GPIO_PC_PIN0_EN
								(NUCODEGEN_GPIO_PC_PIN0_DOUT << GPIO_DOUT_DOUT0_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN1_EN
                (NUCODEGEN_GPIO_PC_PIN1_DOUT << GPIO_DOUT_DOUT1_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN2_EN
                (NUCODEGEN_GPIO_PC_PIN2_DOUT << GPIO_DOUT_DOUT2_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN3_EN
                (NUCODEGEN_GPIO_PC_PIN3_DOUT << GPIO_DOUT_DOUT3_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN4_EN
                (NUCODEGEN_GPIO_PC_PIN4_DOUT << GPIO_DOUT_DOUT4_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN5_EN
                (NUCODEGEN_GPIO_PC_PIN5_DOUT << GPIO_DOUT_DOUT5_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN6_EN
                (NUCODEGEN_GPIO_PC_PIN6_DOUT << GPIO_DOUT_DOUT6_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN7_EN
                (NUCODEGEN_GPIO_PC_PIN7_DOUT << GPIO_DOUT_DOUT7_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN8_EN
                (NUCODEGEN_GPIO_PC_PIN8_DOUT << GPIO_DOUT_DOUT8_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN9_EN
                (NUCODEGEN_GPIO_PC_PIN9_DOUT << GPIO_DOUT_DOUT9_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN10_EN
                (NUCODEGEN_GPIO_PC_PIN10_DOUT << GPIO_DOUT_DOUT10_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN11_EN
                (NUCODEGEN_GPIO_PC_PIN11_DOUT << GPIO_DOUT_DOUT11_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN12_EN
                (NUCODEGEN_GPIO_PC_PIN12_DOUT << GPIO_DOUT_DOUT12_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN13_EN
                (NUCODEGEN_GPIO_PC_PIN13_DOUT << GPIO_DOUT_DOUT13_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN14_EN
                (NUCODEGEN_GPIO_PC_PIN14_DOUT << GPIO_DOUT_DOUT14_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN15_EN
                (NUCODEGEN_GPIO_PC_PIN15_DOUT << GPIO_DOUT_DOUT15_Pos) |
#endif
								u32RegDefault;

    //GPIO_PC DOUT mask
    PC->DATMSK =
#if NUCODEGEN_GPIO_PC_PIN0_EN
								 (NUCODEGEN_GPIO_PC_PIN0_DATMSK << GPIO_DATMSK_DATMSK0_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN1_EN
                 (NUCODEGEN_GPIO_PC_PIN1_DATMSK << GPIO_DATMSK_DATMSK1_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN2_EN
                 (NUCODEGEN_GPIO_PC_PIN2_DATMSK << GPIO_DATMSK_DATMSK2_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN3_EN
                 (NUCODEGEN_GPIO_PC_PIN3_DATMSK << GPIO_DATMSK_DATMSK3_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN4_EN
                 (NUCODEGEN_GPIO_PC_PIN4_DATMSK << GPIO_DATMSK_DATMSK4_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN5_EN
                 (NUCODEGEN_GPIO_PC_PIN5_DATMSK << GPIO_DATMSK_DATMSK5_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN6_EN
                 (NUCODEGEN_GPIO_PC_PIN6_DATMSK << GPIO_DATMSK_DATMSK6_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN7_EN
                 (NUCODEGEN_GPIO_PC_PIN7_DATMSK << GPIO_DATMSK_DATMSK7_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN8_EN
                 (NUCODEGEN_GPIO_PC_PIN8_DATMSK << GPIO_DATMSK_DATMSK8_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN9_EN
                 (NUCODEGEN_GPIO_PC_PIN9_DATMSK << GPIO_DATMSK_DATMSK9_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN10_EN
                 (NUCODEGEN_GPIO_PC_PIN10_DATMSK << GPIO_DATMSK_DATMSK10_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN11_EN
                 (NUCODEGEN_GPIO_PC_PIN11_DATMSK << GPIO_DATMSK_DATMSK11_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN12_EN
                 (NUCODEGEN_GPIO_PC_PIN12_DATMSK << GPIO_DATMSK_DATMSK12_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN13_EN
                 (NUCODEGEN_GPIO_PC_PIN13_DATMSK << GPIO_DATMSK_DATMSK13_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN14_EN
                 (NUCODEGEN_GPIO_PC_PIN14_DATMSK << GPIO_DATMSK_DATMSK14_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN15_EN
                 (NUCODEGEN_GPIO_PC_PIN15_DATMSK << GPIO_DATMSK_DATMSK15_Pos) |
#endif
								u32RegDefault;

    //GPIO_PC enable de-bounce
    PC->DBEN =
#if NUCODEGEN_GPIO_PC_PIN0_EN
								(NUCODEGEN_GPIO_PC_PIN0_DBEN << GPIO_DBEN_DBEN0_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN1_EN
                (NUCODEGEN_GPIO_PC_PIN1_DBEN << GPIO_DBEN_DBEN1_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN2_EN
                (NUCODEGEN_GPIO_PC_PIN2_DBEN << GPIO_DBEN_DBEN2_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN3_EN
                (NUCODEGEN_GPIO_PC_PIN3_DBEN << GPIO_DBEN_DBEN3_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN4_EN
                (NUCODEGEN_GPIO_PC_PIN4_DBEN << GPIO_DBEN_DBEN4_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN5_EN
                (NUCODEGEN_GPIO_PC_PIN5_DBEN << GPIO_DBEN_DBEN5_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN6_EN
                (NUCODEGEN_GPIO_PC_PIN6_DBEN << GPIO_DBEN_DBEN6_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN7_EN
                (NUCODEGEN_GPIO_PC_PIN7_DBEN << GPIO_DBEN_DBEN7_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN8_EN
                (NUCODEGEN_GPIO_PC_PIN8_DBEN << GPIO_DBEN_DBEN8_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN9_EN
                (NUCODEGEN_GPIO_PC_PIN9_DBEN << GPIO_DBEN_DBEN9_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN10_EN
                (NUCODEGEN_GPIO_PC_PIN10_DBEN << GPIO_DBEN_DBEN10_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN11_EN
                (NUCODEGEN_GPIO_PC_PIN11_DBEN << GPIO_DBEN_DBEN11_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN12_EN
                (NUCODEGEN_GPIO_PC_PIN12_DBEN << GPIO_DBEN_DBEN12_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN13_EN
                (NUCODEGEN_GPIO_PC_PIN13_DBEN << GPIO_DBEN_DBEN13_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN14_EN
                (NUCODEGEN_GPIO_PC_PIN14_DBEN << GPIO_DBEN_DBEN14_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN15_EN
                (NUCODEGEN_GPIO_PC_PIN15_DBEN << GPIO_DBEN_DBEN15_Pos) |
#endif
								u32RegDefault;

    //GPIO_PC edge or level interrupt
    PC->INTTYPE =
#if NUCODEGEN_GPIO_PC_PIN0_EN
									(NUCODEGEN_GPIO_PC_PIN0_INTTYPE << GPIO_INTTYPE_TYPE0_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN1_EN
                  (NUCODEGEN_GPIO_PC_PIN1_INTTYPE << GPIO_INTTYPE_TYPE1_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN2_EN
                  (NUCODEGEN_GPIO_PC_PIN2_INTTYPE << GPIO_INTTYPE_TYPE2_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN3_EN
                  (NUCODEGEN_GPIO_PC_PIN3_INTTYPE << GPIO_INTTYPE_TYPE3_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN4_EN
                  (NUCODEGEN_GPIO_PC_PIN4_INTTYPE << GPIO_INTTYPE_TYPE4_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN5_EN
                  (NUCODEGEN_GPIO_PC_PIN5_INTTYPE << GPIO_INTTYPE_TYPE5_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN6_EN
                  (NUCODEGEN_GPIO_PC_PIN6_INTTYPE << GPIO_INTTYPE_TYPE6_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN7_EN
                  (NUCODEGEN_GPIO_PC_PIN7_INTTYPE << GPIO_INTTYPE_TYPE7_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN8_EN
                  (NUCODEGEN_GPIO_PC_PIN8_INTTYPE << GPIO_INTTYPE_TYPE8_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN9_EN
                  (NUCODEGEN_GPIO_PC_PIN9_INTTYPE << GPIO_INTTYPE_TYPE9_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN10_EN
                  (NUCODEGEN_GPIO_PC_PIN10_INTTYPE << GPIO_INTTYPE_TYPE10_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN11_EN
                  (NUCODEGEN_GPIO_PC_PIN11_INTTYPE << GPIO_INTTYPE_TYPE11_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN12_EN
                  (NUCODEGEN_GPIO_PC_PIN12_INTTYPE << GPIO_INTTYPE_TYPE12_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN13_EN
                  (NUCODEGEN_GPIO_PC_PIN13_INTTYPE << GPIO_INTTYPE_TYPE13_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN14_EN
                  (NUCODEGEN_GPIO_PC_PIN14_INTTYPE << GPIO_INTTYPE_TYPE14_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN15_EN
                  (NUCODEGEN_GPIO_PC_PIN15_INTTYPE << GPIO_INTTYPE_TYPE15_Pos) |
#endif
								u32RegDefault;

    //GPIO_PC enable falling(edge) or low(level) interrupt
    PC->INTEN =
#if NUCODEGEN_GPIO_PC_PIN0_EN
								(NUCODEGEN_GPIO_PC_PIN0_FLIEN << GPIO_INTEN_FLIEN0_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN1_EN
                (NUCODEGEN_GPIO_PC_PIN1_FLIEN << GPIO_INTEN_FLIEN1_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN2_EN
                (NUCODEGEN_GPIO_PC_PIN2_FLIEN << GPIO_INTEN_FLIEN2_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN3_EN
                (NUCODEGEN_GPIO_PC_PIN3_FLIEN << GPIO_INTEN_FLIEN3_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN4_EN
                (NUCODEGEN_GPIO_PC_PIN4_FLIEN << GPIO_INTEN_FLIEN4_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN5_EN
                (NUCODEGEN_GPIO_PC_PIN5_FLIEN << GPIO_INTEN_FLIEN5_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN6_EN
                (NUCODEGEN_GPIO_PC_PIN6_FLIEN << GPIO_INTEN_FLIEN6_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN7_EN
                (NUCODEGEN_GPIO_PC_PIN7_FLIEN << GPIO_INTEN_FLIEN7_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN8_EN
                (NUCODEGEN_GPIO_PC_PIN8_FLIEN << GPIO_INTEN_FLIEN8_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN9_EN
                (NUCODEGEN_GPIO_PC_PIN9_FLIEN << GPIO_INTEN_FLIEN9_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN10_EN
                (NUCODEGEN_GPIO_PC_PIN10_FLIEN << GPIO_INTEN_FLIEN10_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN11_EN
                (NUCODEGEN_GPIO_PC_PIN11_FLIEN << GPIO_INTEN_FLIEN11_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN12_EN
                (NUCODEGEN_GPIO_PC_PIN12_FLIEN << GPIO_INTEN_FLIEN12_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN13_EN
                (NUCODEGEN_GPIO_PC_PIN13_FLIEN << GPIO_INTEN_FLIEN13_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN14_EN
                (NUCODEGEN_GPIO_PC_PIN14_FLIEN << GPIO_INTEN_FLIEN14_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN15_EN
                (NUCODEGEN_GPIO_PC_PIN15_FLIEN << GPIO_INTEN_FLIEN15_Pos) |
#endif
								u32RegDefault;

    //GPIO_PC enable rising(edge) or high(level) interrupt
    PC->INTEN |=
#if NUCODEGEN_GPIO_PC_PIN0_EN
								 (NUCODEGEN_GPIO_PC_PIN0_RHIEN << GPIO_INTEN_RHIEN0_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN1_EN
                 (NUCODEGEN_GPIO_PC_PIN1_RHIEN << GPIO_INTEN_RHIEN1_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN2_EN
                 (NUCODEGEN_GPIO_PC_PIN2_RHIEN << GPIO_INTEN_RHIEN2_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN3_EN
                 (NUCODEGEN_GPIO_PC_PIN3_RHIEN << GPIO_INTEN_RHIEN3_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN4_EN
                 (NUCODEGEN_GPIO_PC_PIN4_RHIEN << GPIO_INTEN_RHIEN4_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN5_EN
                 (NUCODEGEN_GPIO_PC_PIN5_RHIEN << GPIO_INTEN_RHIEN5_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN6_EN
                 (NUCODEGEN_GPIO_PC_PIN6_RHIEN << GPIO_INTEN_RHIEN6_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN7_EN
                 (NUCODEGEN_GPIO_PC_PIN7_RHIEN << GPIO_INTEN_RHIEN7_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN8_EN
                 (NUCODEGEN_GPIO_PC_PIN8_RHIEN << GPIO_INTEN_RHIEN8_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN9_EN
                 (NUCODEGEN_GPIO_PC_PIN9_RHIEN << GPIO_INTEN_RHIEN9_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN10_EN
                 (NUCODEGEN_GPIO_PC_PIN10_RHIEN << GPIO_INTEN_RHIEN10_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN11_EN
                 (NUCODEGEN_GPIO_PC_PIN11_RHIEN << GPIO_INTEN_RHIEN11_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN12_EN
                 (NUCODEGEN_GPIO_PC_PIN12_RHIEN << GPIO_INTEN_RHIEN12_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN13_EN
                 (NUCODEGEN_GPIO_PC_PIN13_RHIEN << GPIO_INTEN_RHIEN13_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN14_EN
                 (NUCODEGEN_GPIO_PC_PIN14_RHIEN << GPIO_INTEN_RHIEN14_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN15_EN
                 (NUCODEGEN_GPIO_PC_PIN15_RHIEN << GPIO_INTEN_RHIEN15_Pos) |
#endif
								u32RegDefault;

    //GPIO_PC slew rate
    PC->SLEWCTL =
#if NUCODEGEN_GPIO_PC_PIN0_EN
									(NUCODEGEN_GPIO_PC_PIN0_SLEW << GPIO_SLEWCTL_HSREN0_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN1_EN
                  (NUCODEGEN_GPIO_PC_PIN1_SLEW << GPIO_SLEWCTL_HSREN1_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN2_EN
                  (NUCODEGEN_GPIO_PC_PIN2_SLEW << GPIO_SLEWCTL_HSREN2_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN3_EN
                  (NUCODEGEN_GPIO_PC_PIN3_SLEW << GPIO_SLEWCTL_HSREN3_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN4_EN
                  (NUCODEGEN_GPIO_PC_PIN4_SLEW << GPIO_SLEWCTL_HSREN4_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN5_EN
                  (NUCODEGEN_GPIO_PC_PIN5_SLEW << GPIO_SLEWCTL_HSREN5_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN6_EN
                  (NUCODEGEN_GPIO_PC_PIN6_SLEW << GPIO_SLEWCTL_HSREN6_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN7_EN
                  (NUCODEGEN_GPIO_PC_PIN7_SLEW << GPIO_SLEWCTL_HSREN7_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN8_EN
                  (NUCODEGEN_GPIO_PC_PIN8_SLEW << GPIO_SLEWCTL_HSREN8_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN9_EN
                  (NUCODEGEN_GPIO_PC_PIN9_SLEW << GPIO_SLEWCTL_HSREN9_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN10_EN
                  (NUCODEGEN_GPIO_PC_PIN10_SLEW << GPIO_SLEWCTL_HSREN10_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN11_EN
                  (NUCODEGEN_GPIO_PC_PIN11_SLEW << GPIO_SLEWCTL_HSREN11_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN12_EN
                  (NUCODEGEN_GPIO_PC_PIN12_SLEW << GPIO_SLEWCTL_HSREN12_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN13_EN
                  (NUCODEGEN_GPIO_PC_PIN13_SLEW << GPIO_SLEWCTL_HSREN13_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN14_EN
                  (NUCODEGEN_GPIO_PC_PIN14_SLEW << GPIO_SLEWCTL_HSREN14_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN15_EN
                  (NUCODEGEN_GPIO_PC_PIN15_SLEW << GPIO_SLEWCTL_HSREN15_Pos) |
#endif
								u32RegDefault;

    //GPIO_PC pull-up or pull-down
    PC->PUSEL =
#if NUCODEGEN_GPIO_PC_PIN0_EN
								(NUCODEGEN_GPIO_PC_PIN0_PUSEL << GPIO_PUSEL_PUSEL0_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN1_EN
                (NUCODEGEN_GPIO_PC_PIN1_PUSEL << GPIO_PUSEL_PUSEL1_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN2_EN
                (NUCODEGEN_GPIO_PC_PIN2_PUSEL << GPIO_PUSEL_PUSEL2_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN3_EN
                (NUCODEGEN_GPIO_PC_PIN3_PUSEL << GPIO_PUSEL_PUSEL3_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN4_EN
                (NUCODEGEN_GPIO_PC_PIN4_PUSEL << GPIO_PUSEL_PUSEL4_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN5_EN
                (NUCODEGEN_GPIO_PC_PIN5_PUSEL << GPIO_PUSEL_PUSEL5_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN6_EN
                (NUCODEGEN_GPIO_PC_PIN6_PUSEL << GPIO_PUSEL_PUSEL6_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN7_EN
                (NUCODEGEN_GPIO_PC_PIN7_PUSEL << GPIO_PUSEL_PUSEL7_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN8_EN
                (NUCODEGEN_GPIO_PC_PIN8_PUSEL << GPIO_PUSEL_PUSEL8_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN9_EN
                (NUCODEGEN_GPIO_PC_PIN9_PUSEL << GPIO_PUSEL_PUSEL9_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN10_EN
                (NUCODEGEN_GPIO_PC_PIN10_PUSEL << GPIO_PUSEL_PUSEL10_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN11_EN
                (NUCODEGEN_GPIO_PC_PIN11_PUSEL << GPIO_PUSEL_PUSEL11_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN12_EN
                (NUCODEGEN_GPIO_PC_PIN12_PUSEL << GPIO_PUSEL_PUSEL12_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN13_EN
                (NUCODEGEN_GPIO_PC_PIN13_PUSEL << GPIO_PUSEL_PUSEL13_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN14_EN
                (NUCODEGEN_GPIO_PC_PIN14_PUSEL << GPIO_PUSEL_PUSEL14_Pos) |
#endif
#if NUCODEGEN_GPIO_PC_PIN15_EN
                (NUCODEGEN_GPIO_PC_PIN15_PUSEL << GPIO_PUSEL_PUSEL15_Pos) |
#endif
								u32RegDefault;

#if(NUCODEGEN_GPIO_PC_CLR_DB_ICLKON)
    GPIO_CLR_DEBOUNCE_ICLKON(PC);
#endif

#if(NUCODEGEN_GPIO_PC_INT)
    NVIC_EnableIRQ(GPC_IRQn);
#endif

#if(NUCODEGEN_GPIO_PC_EINT2)
    NVIC_EnableIRQ(EINT2_IRQn);//PC.6
#endif

#if(NUCODEGEN_GPIO_PC_EINT3)
    NVIC_EnableIRQ(EINT3_IRQn);//PC.7
#endif
#endif //NUCODEGEN_GPIO_PC

#if(NUCODEGEN_GPIO_PD)
    //GPIO_PD mode
    PD->MODE =
#if NUCODEGEN_GPIO_PD_PIN0_EN
								(NUCODEGEN_GPIO_PD_PIN0_MODE << GPIO_MODE_MODE0_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN1_EN
                (NUCODEGEN_GPIO_PD_PIN1_MODE << GPIO_MODE_MODE1_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN2_EN
                (NUCODEGEN_GPIO_PD_PIN2_MODE << GPIO_MODE_MODE2_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN3_EN
                (NUCODEGEN_GPIO_PD_PIN3_MODE << GPIO_MODE_MODE3_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN4_EN
                (NUCODEGEN_GPIO_PD_PIN4_MODE << GPIO_MODE_MODE4_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN5_EN
                (NUCODEGEN_GPIO_PD_PIN5_MODE << GPIO_MODE_MODE5_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN6_EN
                (NUCODEGEN_GPIO_PD_PIN6_MODE << GPIO_MODE_MODE6_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN7_EN
                (NUCODEGEN_GPIO_PD_PIN7_MODE << GPIO_MODE_MODE7_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN8_EN
                (NUCODEGEN_GPIO_PD_PIN8_MODE << GPIO_MODE_MODE8_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN9_EN
                (NUCODEGEN_GPIO_PD_PIN9_MODE << GPIO_MODE_MODE9_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN10_EN
                (NUCODEGEN_GPIO_PD_PIN10_MODE << GPIO_MODE_MODE10_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN11_EN
                (NUCODEGEN_GPIO_PD_PIN11_MODE << GPIO_MODE_MODE11_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN12_EN
                (NUCODEGEN_GPIO_PD_PIN12_MODE << GPIO_MODE_MODE12_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN13_EN
                (NUCODEGEN_GPIO_PD_PIN13_MODE << GPIO_MODE_MODE13_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN14_EN
                (NUCODEGEN_GPIO_PD_PIN14_MODE << GPIO_MODE_MODE14_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN15_EN
                (NUCODEGEN_GPIO_PD_PIN15_MODE << GPIO_MODE_MODE15_Pos) |
#endif
								u32RegDefault;

    //GPIO_PD disable digital input path
    PD->DINOFF =
#if NUCODEGEN_GPIO_PD_PIN0_EN
								 (NUCODEGEN_GPIO_PD_PIN0_DINOFF << GPIO_DINOFF_DINOFF0_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN1_EN
                 (NUCODEGEN_GPIO_PD_PIN1_DINOFF << GPIO_DINOFF_DINOFF1_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN2_EN
                 (NUCODEGEN_GPIO_PD_PIN2_DINOFF << GPIO_DINOFF_DINOFF2_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN3_EN
                 (NUCODEGEN_GPIO_PD_PIN3_DINOFF << GPIO_DINOFF_DINOFF3_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN4_EN
                 (NUCODEGEN_GPIO_PD_PIN4_DINOFF << GPIO_DINOFF_DINOFF4_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN5_EN
                 (NUCODEGEN_GPIO_PD_PIN5_DINOFF << GPIO_DINOFF_DINOFF5_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN6_EN
                 (NUCODEGEN_GPIO_PD_PIN6_DINOFF << GPIO_DINOFF_DINOFF6_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN7_EN
                 (NUCODEGEN_GPIO_PD_PIN7_DINOFF << GPIO_DINOFF_DINOFF7_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN8_EN
                 (NUCODEGEN_GPIO_PD_PIN8_DINOFF << GPIO_DINOFF_DINOFF8_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN9_EN
                 (NUCODEGEN_GPIO_PD_PIN9_DINOFF << GPIO_DINOFF_DINOFF9_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN10_EN
                 (NUCODEGEN_GPIO_PD_PIN10_DINOFF << GPIO_DINOFF_DINOFF10_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN11_EN
                 (NUCODEGEN_GPIO_PD_PIN11_DINOFF << GPIO_DINOFF_DINOFF11_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN12_EN
                 (NUCODEGEN_GPIO_PD_PIN12_DINOFF << GPIO_DINOFF_DINOFF12_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN13_EN
                 (NUCODEGEN_GPIO_PD_PIN13_DINOFF << GPIO_DINOFF_DINOFF13_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN14_EN
                 (NUCODEGEN_GPIO_PD_PIN14_DINOFF << GPIO_DINOFF_DINOFF14_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN15_EN
                 (NUCODEGEN_GPIO_PD_PIN15_DINOFF << GPIO_DINOFF_DINOFF15_Pos) |
#endif
								u32RegDefault;

    //GPIO_PD out data
    PD->DOUT =
#if NUCODEGEN_GPIO_PD_PIN0_EN
								(NUCODEGEN_GPIO_PD_PIN0_DOUT << GPIO_DOUT_DOUT0_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN1_EN
                (NUCODEGEN_GPIO_PD_PIN1_DOUT << GPIO_DOUT_DOUT1_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN2_EN
                (NUCODEGEN_GPIO_PD_PIN2_DOUT << GPIO_DOUT_DOUT2_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN3_EN
                (NUCODEGEN_GPIO_PD_PIN3_DOUT << GPIO_DOUT_DOUT3_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN4_EN
                (NUCODEGEN_GPIO_PD_PIN4_DOUT << GPIO_DOUT_DOUT4_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN5_EN
                (NUCODEGEN_GPIO_PD_PIN5_DOUT << GPIO_DOUT_DOUT5_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN6_EN
                (NUCODEGEN_GPIO_PD_PIN6_DOUT << GPIO_DOUT_DOUT6_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN7_EN
                (NUCODEGEN_GPIO_PD_PIN7_DOUT << GPIO_DOUT_DOUT7_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN8_EN
                (NUCODEGEN_GPIO_PD_PIN8_DOUT << GPIO_DOUT_DOUT8_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN9_EN
                (NUCODEGEN_GPIO_PD_PIN9_DOUT << GPIO_DOUT_DOUT9_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN10_EN
                (NUCODEGEN_GPIO_PD_PIN10_DOUT << GPIO_DOUT_DOUT10_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN11_EN
                (NUCODEGEN_GPIO_PD_PIN11_DOUT << GPIO_DOUT_DOUT11_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN12_EN
                (NUCODEGEN_GPIO_PD_PIN12_DOUT << GPIO_DOUT_DOUT12_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN13_EN
                (NUCODEGEN_GPIO_PD_PIN13_DOUT << GPIO_DOUT_DOUT13_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN14_EN
                (NUCODEGEN_GPIO_PD_PIN14_DOUT << GPIO_DOUT_DOUT14_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN15_EN
                (NUCODEGEN_GPIO_PD_PIN15_DOUT << GPIO_DOUT_DOUT15_Pos) |
#endif
								u32RegDefault;

    //GPIO_PD DOUT mask
    PD->DATMSK =
#if NUCODEGEN_GPIO_PD_PIN0_EN
								 (NUCODEGEN_GPIO_PD_PIN0_DATMSK << GPIO_DATMSK_DATMSK0_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN1_EN
                 (NUCODEGEN_GPIO_PD_PIN1_DATMSK << GPIO_DATMSK_DATMSK1_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN2_EN
                 (NUCODEGEN_GPIO_PD_PIN2_DATMSK << GPIO_DATMSK_DATMSK2_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN3_EN
                 (NUCODEGEN_GPIO_PD_PIN3_DATMSK << GPIO_DATMSK_DATMSK3_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN4_EN
                 (NUCODEGEN_GPIO_PD_PIN4_DATMSK << GPIO_DATMSK_DATMSK4_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN5_EN
                 (NUCODEGEN_GPIO_PD_PIN5_DATMSK << GPIO_DATMSK_DATMSK5_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN6_EN
                 (NUCODEGEN_GPIO_PD_PIN6_DATMSK << GPIO_DATMSK_DATMSK6_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN7_EN
                 (NUCODEGEN_GPIO_PD_PIN7_DATMSK << GPIO_DATMSK_DATMSK7_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN8_EN
                 (NUCODEGEN_GPIO_PD_PIN8_DATMSK << GPIO_DATMSK_DATMSK8_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN9_EN
                 (NUCODEGEN_GPIO_PD_PIN9_DATMSK << GPIO_DATMSK_DATMSK9_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN10_EN
                 (NUCODEGEN_GPIO_PD_PIN10_DATMSK << GPIO_DATMSK_DATMSK10_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN11_EN
                 (NUCODEGEN_GPIO_PD_PIN11_DATMSK << GPIO_DATMSK_DATMSK11_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN12_EN
                 (NUCODEGEN_GPIO_PD_PIN12_DATMSK << GPIO_DATMSK_DATMSK12_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN13_EN
                 (NUCODEGEN_GPIO_PD_PIN13_DATMSK << GPIO_DATMSK_DATMSK13_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN14_EN
                 (NUCODEGEN_GPIO_PD_PIN14_DATMSK << GPIO_DATMSK_DATMSK14_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN15_EN
                 (NUCODEGEN_GPIO_PD_PIN15_DATMSK << GPIO_DATMSK_DATMSK15_Pos) |
#endif
								u32RegDefault;

    //GPIO_PD enable de-bounce
    PD->DBEN =
#if NUCODEGEN_GPIO_PD_PIN0_EN
								(NUCODEGEN_GPIO_PD_PIN0_DBEN << GPIO_DBEN_DBEN0_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN1_EN
                (NUCODEGEN_GPIO_PD_PIN1_DBEN << GPIO_DBEN_DBEN1_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN2_EN
                (NUCODEGEN_GPIO_PD_PIN2_DBEN << GPIO_DBEN_DBEN2_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN3_EN
                (NUCODEGEN_GPIO_PD_PIN3_DBEN << GPIO_DBEN_DBEN3_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN4_EN
                (NUCODEGEN_GPIO_PD_PIN4_DBEN << GPIO_DBEN_DBEN4_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN5_EN
                (NUCODEGEN_GPIO_PD_PIN5_DBEN << GPIO_DBEN_DBEN5_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN6_EN
                (NUCODEGEN_GPIO_PD_PIN6_DBEN << GPIO_DBEN_DBEN6_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN7_EN
                (NUCODEGEN_GPIO_PD_PIN7_DBEN << GPIO_DBEN_DBEN7_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN8_EN
                (NUCODEGEN_GPIO_PD_PIN8_DBEN << GPIO_DBEN_DBEN8_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN9_EN
                (NUCODEGEN_GPIO_PD_PIN9_DBEN << GPIO_DBEN_DBEN9_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN10_EN
                (NUCODEGEN_GPIO_PD_PIN10_DBEN << GPIO_DBEN_DBEN10_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN11_EN
                (NUCODEGEN_GPIO_PD_PIN11_DBEN << GPIO_DBEN_DBEN11_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN12_EN
                (NUCODEGEN_GPIO_PD_PIN12_DBEN << GPIO_DBEN_DBEN12_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN13_EN
                (NUCODEGEN_GPIO_PD_PIN13_DBEN << GPIO_DBEN_DBEN13_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN14_EN
                (NUCODEGEN_GPIO_PD_PIN14_DBEN << GPIO_DBEN_DBEN14_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN15_EN
                (NUCODEGEN_GPIO_PD_PIN15_DBEN << GPIO_DBEN_DBEN15_Pos) |
#endif
								u32RegDefault;

    //GPIO_PD edge or level interrupt
    PD->INTTYPE =
#if NUCODEGEN_GPIO_PD_PIN0_EN
									(NUCODEGEN_GPIO_PD_PIN0_INTTYPE << GPIO_INTTYPE_TYPE0_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN1_EN
                  (NUCODEGEN_GPIO_PD_PIN1_INTTYPE << GPIO_INTTYPE_TYPE1_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN2_EN
                  (NUCODEGEN_GPIO_PD_PIN2_INTTYPE << GPIO_INTTYPE_TYPE2_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN3_EN
                  (NUCODEGEN_GPIO_PD_PIN3_INTTYPE << GPIO_INTTYPE_TYPE3_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN4_EN
                  (NUCODEGEN_GPIO_PD_PIN4_INTTYPE << GPIO_INTTYPE_TYPE4_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN5_EN
                  (NUCODEGEN_GPIO_PD_PIN5_INTTYPE << GPIO_INTTYPE_TYPE5_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN6_EN
                  (NUCODEGEN_GPIO_PD_PIN6_INTTYPE << GPIO_INTTYPE_TYPE6_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN7_EN
                  (NUCODEGEN_GPIO_PD_PIN7_INTTYPE << GPIO_INTTYPE_TYPE7_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN8_EN
                  (NUCODEGEN_GPIO_PD_PIN8_INTTYPE << GPIO_INTTYPE_TYPE8_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN9_EN
                  (NUCODEGEN_GPIO_PD_PIN9_INTTYPE << GPIO_INTTYPE_TYPE9_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN10_EN
                  (NUCODEGEN_GPIO_PD_PIN10_INTTYPE << GPIO_INTTYPE_TYPE10_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN11_EN
                  (NUCODEGEN_GPIO_PD_PIN11_INTTYPE << GPIO_INTTYPE_TYPE11_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN12_EN
                  (NUCODEGEN_GPIO_PD_PIN12_INTTYPE << GPIO_INTTYPE_TYPE12_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN13_EN
                  (NUCODEGEN_GPIO_PD_PIN13_INTTYPE << GPIO_INTTYPE_TYPE13_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN14_EN
                  (NUCODEGEN_GPIO_PD_PIN14_INTTYPE << GPIO_INTTYPE_TYPE14_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN15_EN
                  (NUCODEGEN_GPIO_PD_PIN15_INTTYPE << GPIO_INTTYPE_TYPE15_Pos) |
#endif
								u32RegDefault;

    //GPIO_PD enable falling(edge) or low(level) interrupt
    PD->INTEN =
#if NUCODEGEN_GPIO_PD_PIN0_EN
								(NUCODEGEN_GPIO_PD_PIN0_FLIEN << GPIO_INTEN_FLIEN0_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN1_EN
                (NUCODEGEN_GPIO_PD_PIN1_FLIEN << GPIO_INTEN_FLIEN1_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN2_EN
                (NUCODEGEN_GPIO_PD_PIN2_FLIEN << GPIO_INTEN_FLIEN2_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN3_EN
                (NUCODEGEN_GPIO_PD_PIN3_FLIEN << GPIO_INTEN_FLIEN3_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN4_EN
                (NUCODEGEN_GPIO_PD_PIN4_FLIEN << GPIO_INTEN_FLIEN4_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN5_EN
                (NUCODEGEN_GPIO_PD_PIN5_FLIEN << GPIO_INTEN_FLIEN5_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN6_EN
                (NUCODEGEN_GPIO_PD_PIN6_FLIEN << GPIO_INTEN_FLIEN6_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN7_EN
                (NUCODEGEN_GPIO_PD_PIN7_FLIEN << GPIO_INTEN_FLIEN7_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN8_EN
                (NUCODEGEN_GPIO_PD_PIN8_FLIEN << GPIO_INTEN_FLIEN8_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN9_EN
                (NUCODEGEN_GPIO_PD_PIN9_FLIEN << GPIO_INTEN_FLIEN9_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN10_EN
                (NUCODEGEN_GPIO_PD_PIN10_FLIEN << GPIO_INTEN_FLIEN10_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN11_EN
                (NUCODEGEN_GPIO_PD_PIN11_FLIEN << GPIO_INTEN_FLIEN11_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN12_EN
                (NUCODEGEN_GPIO_PD_PIN12_FLIEN << GPIO_INTEN_FLIEN12_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN13_EN
                (NUCODEGEN_GPIO_PD_PIN13_FLIEN << GPIO_INTEN_FLIEN13_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN14_EN
                (NUCODEGEN_GPIO_PD_PIN14_FLIEN << GPIO_INTEN_FLIEN14_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN15_EN
                (NUCODEGEN_GPIO_PD_PIN15_FLIEN << GPIO_INTEN_FLIEN15_Pos) |
#endif
								u32RegDefault;

    //GPIO_PD enable rising(edge) or high(level) interrupt
    PD->INTEN |=
#if NUCODEGEN_GPIO_PD_PIN0_EN
								 (NUCODEGEN_GPIO_PD_PIN0_RHIEN << GPIO_INTEN_RHIEN0_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN1_EN
                 (NUCODEGEN_GPIO_PD_PIN1_RHIEN << GPIO_INTEN_RHIEN1_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN2_EN
                 (NUCODEGEN_GPIO_PD_PIN2_RHIEN << GPIO_INTEN_RHIEN2_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN3_EN
                 (NUCODEGEN_GPIO_PD_PIN3_RHIEN << GPIO_INTEN_RHIEN3_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN4_EN
                 (NUCODEGEN_GPIO_PD_PIN4_RHIEN << GPIO_INTEN_RHIEN4_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN5_EN
                 (NUCODEGEN_GPIO_PD_PIN5_RHIEN << GPIO_INTEN_RHIEN5_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN6_EN
                 (NUCODEGEN_GPIO_PD_PIN6_RHIEN << GPIO_INTEN_RHIEN6_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN7_EN
                 (NUCODEGEN_GPIO_PD_PIN7_RHIEN << GPIO_INTEN_RHIEN7_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN8_EN
                 (NUCODEGEN_GPIO_PD_PIN8_RHIEN << GPIO_INTEN_RHIEN8_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN9_EN
                 (NUCODEGEN_GPIO_PD_PIN9_RHIEN << GPIO_INTEN_RHIEN9_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN10_EN
                 (NUCODEGEN_GPIO_PD_PIN10_RHIEN << GPIO_INTEN_RHIEN10_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN11_EN
                 (NUCODEGEN_GPIO_PD_PIN11_RHIEN << GPIO_INTEN_RHIEN11_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN12_EN
                 (NUCODEGEN_GPIO_PD_PIN12_RHIEN << GPIO_INTEN_RHIEN12_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN13_EN
                 (NUCODEGEN_GPIO_PD_PIN13_RHIEN << GPIO_INTEN_RHIEN13_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN14_EN
                 (NUCODEGEN_GPIO_PD_PIN14_RHIEN << GPIO_INTEN_RHIEN14_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN15_EN
                 (NUCODEGEN_GPIO_PD_PIN15_RHIEN << GPIO_INTEN_RHIEN15_Pos) |
#endif
								u32RegDefault;

    //GPIO_PD slew rate
    PD->SLEWCTL =
#if NUCODEGEN_GPIO_PD_PIN0_EN
									(NUCODEGEN_GPIO_PD_PIN0_SLEW << GPIO_SLEWCTL_HSREN0_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN1_EN
                  (NUCODEGEN_GPIO_PD_PIN1_SLEW << GPIO_SLEWCTL_HSREN1_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN2_EN
                  (NUCODEGEN_GPIO_PD_PIN2_SLEW << GPIO_SLEWCTL_HSREN2_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN3_EN
                  (NUCODEGEN_GPIO_PD_PIN3_SLEW << GPIO_SLEWCTL_HSREN3_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN4_EN
                  (NUCODEGEN_GPIO_PD_PIN4_SLEW << GPIO_SLEWCTL_HSREN4_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN5_EN
                  (NUCODEGEN_GPIO_PD_PIN5_SLEW << GPIO_SLEWCTL_HSREN5_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN6_EN
                  (NUCODEGEN_GPIO_PD_PIN6_SLEW << GPIO_SLEWCTL_HSREN6_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN7_EN
                  (NUCODEGEN_GPIO_PD_PIN7_SLEW << GPIO_SLEWCTL_HSREN7_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN8_EN
                  (NUCODEGEN_GPIO_PD_PIN8_SLEW << GPIO_SLEWCTL_HSREN8_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN9_EN
                  (NUCODEGEN_GPIO_PD_PIN9_SLEW << GPIO_SLEWCTL_HSREN9_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN10_EN
                  (NUCODEGEN_GPIO_PD_PIN10_SLEW << GPIO_SLEWCTL_HSREN10_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN11_EN
                  (NUCODEGEN_GPIO_PD_PIN11_SLEW << GPIO_SLEWCTL_HSREN11_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN12_EN
                  (NUCODEGEN_GPIO_PD_PIN12_SLEW << GPIO_SLEWCTL_HSREN12_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN13_EN
                  (NUCODEGEN_GPIO_PD_PIN13_SLEW << GPIO_SLEWCTL_HSREN13_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN14_EN
                  (NUCODEGEN_GPIO_PD_PIN14_SLEW << GPIO_SLEWCTL_HSREN14_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN15_EN
                  (NUCODEGEN_GPIO_PD_PIN15_SLEW << GPIO_SLEWCTL_HSREN15_Pos) |
#endif
								u32RegDefault;

    //GPIO_PD pull-up or pull-down
    PD->PUSEL =
#if NUCODEGEN_GPIO_PD_PIN0_EN
								(NUCODEGEN_GPIO_PD_PIN0_PUSEL << GPIO_PUSEL_PUSEL0_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN1_EN
                (NUCODEGEN_GPIO_PD_PIN1_PUSEL << GPIO_PUSEL_PUSEL1_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN2_EN
                (NUCODEGEN_GPIO_PD_PIN2_PUSEL << GPIO_PUSEL_PUSEL2_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN3_EN
                (NUCODEGEN_GPIO_PD_PIN3_PUSEL << GPIO_PUSEL_PUSEL3_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN4_EN
                (NUCODEGEN_GPIO_PD_PIN4_PUSEL << GPIO_PUSEL_PUSEL4_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN5_EN
                (NUCODEGEN_GPIO_PD_PIN5_PUSEL << GPIO_PUSEL_PUSEL5_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN6_EN
                (NUCODEGEN_GPIO_PD_PIN6_PUSEL << GPIO_PUSEL_PUSEL6_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN7_EN
                (NUCODEGEN_GPIO_PD_PIN7_PUSEL << GPIO_PUSEL_PUSEL7_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN8_EN
                (NUCODEGEN_GPIO_PD_PIN8_PUSEL << GPIO_PUSEL_PUSEL8_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN9_EN
                (NUCODEGEN_GPIO_PD_PIN9_PUSEL << GPIO_PUSEL_PUSEL9_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN10_EN
                (NUCODEGEN_GPIO_PD_PIN10_PUSEL << GPIO_PUSEL_PUSEL10_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN11_EN
                (NUCODEGEN_GPIO_PD_PIN11_PUSEL << GPIO_PUSEL_PUSEL11_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN12_EN
                (NUCODEGEN_GPIO_PD_PIN12_PUSEL << GPIO_PUSEL_PUSEL12_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN13_EN
                (NUCODEGEN_GPIO_PD_PIN13_PUSEL << GPIO_PUSEL_PUSEL13_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN14_EN
                (NUCODEGEN_GPIO_PD_PIN14_PUSEL << GPIO_PUSEL_PUSEL14_Pos) |
#endif
#if NUCODEGEN_GPIO_PD_PIN15_EN
                (NUCODEGEN_GPIO_PD_PIN15_PUSEL << GPIO_PUSEL_PUSEL15_Pos) |
#endif
								u32RegDefault;

#if(NUCODEGEN_GPIO_PD_CLR_DB_ICLKON)
    GPIO_CLR_DEBOUNCE_ICLKON(PD);
#endif

#if(NUCODEGEN_GPIO_PD_INT)
    NVIC_EnableIRQ(GPD_IRQn);
#endif

#if(NUCODEGEN_GPIO_PD_EINT1)
    NVIC_EnableIRQ(EINT1_IRQn);//PD.15
#endif

#if(NUCODEGEN_GPIO_PD_EINT5)
    NVIC_EnableIRQ(EINT5_IRQn);//PD.12
#endif
#endif //NUCODEGEN_GPIO_PD

#if(NUCODEGEN_GPIO_PE)
    //GPIO_PE mode
    PE->MODE =
#if NUCODEGEN_GPIO_PE_PIN0_EN
								(NUCODEGEN_GPIO_PE_PIN0_MODE << GPIO_MODE_MODE0_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN1_EN
                (NUCODEGEN_GPIO_PE_PIN1_MODE << GPIO_MODE_MODE1_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN2_EN
                (NUCODEGEN_GPIO_PE_PIN2_MODE << GPIO_MODE_MODE2_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN3_EN
                (NUCODEGEN_GPIO_PE_PIN3_MODE << GPIO_MODE_MODE3_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN4_EN
                (NUCODEGEN_GPIO_PE_PIN4_MODE << GPIO_MODE_MODE4_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN5_EN
                (NUCODEGEN_GPIO_PE_PIN5_MODE << GPIO_MODE_MODE5_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN6_EN
                (NUCODEGEN_GPIO_PE_PIN6_MODE << GPIO_MODE_MODE6_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN7_EN
                (NUCODEGEN_GPIO_PE_PIN7_MODE << GPIO_MODE_MODE7_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN8_EN
                (NUCODEGEN_GPIO_PE_PIN8_MODE << GPIO_MODE_MODE8_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN9_EN
                (NUCODEGEN_GPIO_PE_PIN9_MODE << GPIO_MODE_MODE9_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN10_EN
                (NUCODEGEN_GPIO_PE_PIN10_MODE << GPIO_MODE_MODE10_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN11_EN
                (NUCODEGEN_GPIO_PE_PIN11_MODE << GPIO_MODE_MODE11_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN12_EN
                (NUCODEGEN_GPIO_PE_PIN12_MODE << GPIO_MODE_MODE12_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN13_EN
                (NUCODEGEN_GPIO_PE_PIN13_MODE << GPIO_MODE_MODE13_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN14_EN
                (NUCODEGEN_GPIO_PE_PIN14_MODE << GPIO_MODE_MODE14_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN15_EN
                (NUCODEGEN_GPIO_PE_PIN15_MODE << GPIO_MODE_MODE15_Pos) |
#endif
								u32RegDefault;

    //GPIO_PE disable digital input path
    PE->DINOFF =
#if NUCODEGEN_GPIO_PE_PIN0_EN
								 (NUCODEGEN_GPIO_PE_PIN0_DINOFF << GPIO_DINOFF_DINOFF0_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN1_EN
                 (NUCODEGEN_GPIO_PE_PIN1_DINOFF << GPIO_DINOFF_DINOFF1_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN2_EN
                 (NUCODEGEN_GPIO_PE_PIN2_DINOFF << GPIO_DINOFF_DINOFF2_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN3_EN
                 (NUCODEGEN_GPIO_PE_PIN3_DINOFF << GPIO_DINOFF_DINOFF3_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN4_EN
                 (NUCODEGEN_GPIO_PE_PIN4_DINOFF << GPIO_DINOFF_DINOFF4_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN5_EN
                 (NUCODEGEN_GPIO_PE_PIN5_DINOFF << GPIO_DINOFF_DINOFF5_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN6_EN
                 (NUCODEGEN_GPIO_PE_PIN6_DINOFF << GPIO_DINOFF_DINOFF6_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN7_EN
                 (NUCODEGEN_GPIO_PE_PIN7_DINOFF << GPIO_DINOFF_DINOFF7_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN8_EN
                 (NUCODEGEN_GPIO_PE_PIN8_DINOFF << GPIO_DINOFF_DINOFF8_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN9_EN
                 (NUCODEGEN_GPIO_PE_PIN9_DINOFF << GPIO_DINOFF_DINOFF9_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN10_EN
                 (NUCODEGEN_GPIO_PE_PIN10_DINOFF << GPIO_DINOFF_DINOFF10_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN11_EN
                 (NUCODEGEN_GPIO_PE_PIN11_DINOFF << GPIO_DINOFF_DINOFF11_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN12_EN
                 (NUCODEGEN_GPIO_PE_PIN12_DINOFF << GPIO_DINOFF_DINOFF12_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN13_EN
                 (NUCODEGEN_GPIO_PE_PIN13_DINOFF << GPIO_DINOFF_DINOFF13_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN14_EN
                 (NUCODEGEN_GPIO_PE_PIN14_DINOFF << GPIO_DINOFF_DINOFF14_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN15_EN
                 (NUCODEGEN_GPIO_PE_PIN15_DINOFF << GPIO_DINOFF_DINOFF15_Pos) |
#endif
								u32RegDefault;

    //GPIO_PE out data
    PE->DOUT =
#if NUCODEGEN_GPIO_PE_PIN0_EN
								(NUCODEGEN_GPIO_PE_PIN0_DOUT << GPIO_DOUT_DOUT0_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN1_EN
                (NUCODEGEN_GPIO_PE_PIN1_DOUT << GPIO_DOUT_DOUT1_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN2_EN
                (NUCODEGEN_GPIO_PE_PIN2_DOUT << GPIO_DOUT_DOUT2_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN3_EN
                (NUCODEGEN_GPIO_PE_PIN3_DOUT << GPIO_DOUT_DOUT3_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN4_EN
                (NUCODEGEN_GPIO_PE_PIN4_DOUT << GPIO_DOUT_DOUT4_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN5_EN
                (NUCODEGEN_GPIO_PE_PIN5_DOUT << GPIO_DOUT_DOUT5_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN6_EN
                (NUCODEGEN_GPIO_PE_PIN6_DOUT << GPIO_DOUT_DOUT6_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN7_EN
                (NUCODEGEN_GPIO_PE_PIN7_DOUT << GPIO_DOUT_DOUT7_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN8_EN
                (NUCODEGEN_GPIO_PE_PIN8_DOUT << GPIO_DOUT_DOUT8_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN9_EN
                (NUCODEGEN_GPIO_PE_PIN9_DOUT << GPIO_DOUT_DOUT9_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN10_EN
                (NUCODEGEN_GPIO_PE_PIN10_DOUT << GPIO_DOUT_DOUT10_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN11_EN
                (NUCODEGEN_GPIO_PE_PIN11_DOUT << GPIO_DOUT_DOUT11_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN12_EN
                (NUCODEGEN_GPIO_PE_PIN12_DOUT << GPIO_DOUT_DOUT12_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN13_EN
                (NUCODEGEN_GPIO_PE_PIN13_DOUT << GPIO_DOUT_DOUT13_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN14_EN
                (NUCODEGEN_GPIO_PE_PIN14_DOUT << GPIO_DOUT_DOUT14_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN15_EN
                (NUCODEGEN_GPIO_PE_PIN15_DOUT << GPIO_DOUT_DOUT15_Pos) |
#endif
								u32RegDefault;

    //GPIO_PE DOUT mask
    PE->DATMSK =
#if NUCODEGEN_GPIO_PE_PIN0_EN
								 (NUCODEGEN_GPIO_PE_PIN0_DATMSK << GPIO_DATMSK_DATMSK0_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN1_EN
                 (NUCODEGEN_GPIO_PE_PIN1_DATMSK << GPIO_DATMSK_DATMSK1_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN2_EN
                 (NUCODEGEN_GPIO_PE_PIN2_DATMSK << GPIO_DATMSK_DATMSK2_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN3_EN
                 (NUCODEGEN_GPIO_PE_PIN3_DATMSK << GPIO_DATMSK_DATMSK3_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN4_EN
                 (NUCODEGEN_GPIO_PE_PIN4_DATMSK << GPIO_DATMSK_DATMSK4_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN5_EN
                 (NUCODEGEN_GPIO_PE_PIN5_DATMSK << GPIO_DATMSK_DATMSK5_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN6_EN
                 (NUCODEGEN_GPIO_PE_PIN6_DATMSK << GPIO_DATMSK_DATMSK6_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN7_EN
                 (NUCODEGEN_GPIO_PE_PIN7_DATMSK << GPIO_DATMSK_DATMSK7_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN8_EN
                 (NUCODEGEN_GPIO_PE_PIN8_DATMSK << GPIO_DATMSK_DATMSK8_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN9_EN
                 (NUCODEGEN_GPIO_PE_PIN9_DATMSK << GPIO_DATMSK_DATMSK9_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN10_EN
                 (NUCODEGEN_GPIO_PE_PIN10_DATMSK << GPIO_DATMSK_DATMSK10_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN11_EN
                 (NUCODEGEN_GPIO_PE_PIN11_DATMSK << GPIO_DATMSK_DATMSK11_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN12_EN
                 (NUCODEGEN_GPIO_PE_PIN12_DATMSK << GPIO_DATMSK_DATMSK12_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN13_EN
                 (NUCODEGEN_GPIO_PE_PIN13_DATMSK << GPIO_DATMSK_DATMSK13_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN14_EN
                 (NUCODEGEN_GPIO_PE_PIN14_DATMSK << GPIO_DATMSK_DATMSK14_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN15_EN
                 (NUCODEGEN_GPIO_PE_PIN15_DATMSK << GPIO_DATMSK_DATMSK15_Pos) |
#endif
								u32RegDefault;

    //GPIO_PE enable de-bounce
    PE->DBEN =
#if NUCODEGEN_GPIO_PE_PIN0_EN
								(NUCODEGEN_GPIO_PE_PIN0_DBEN << GPIO_DBEN_DBEN0_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN1_EN
                (NUCODEGEN_GPIO_PE_PIN1_DBEN << GPIO_DBEN_DBEN1_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN2_EN
                (NUCODEGEN_GPIO_PE_PIN2_DBEN << GPIO_DBEN_DBEN2_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN3_EN
                (NUCODEGEN_GPIO_PE_PIN3_DBEN << GPIO_DBEN_DBEN3_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN4_EN
                (NUCODEGEN_GPIO_PE_PIN4_DBEN << GPIO_DBEN_DBEN4_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN5_EN
                (NUCODEGEN_GPIO_PE_PIN5_DBEN << GPIO_DBEN_DBEN5_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN6_EN
                (NUCODEGEN_GPIO_PE_PIN6_DBEN << GPIO_DBEN_DBEN6_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN7_EN
                (NUCODEGEN_GPIO_PE_PIN7_DBEN << GPIO_DBEN_DBEN7_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN8_EN
                (NUCODEGEN_GPIO_PE_PIN8_DBEN << GPIO_DBEN_DBEN8_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN9_EN
                (NUCODEGEN_GPIO_PE_PIN9_DBEN << GPIO_DBEN_DBEN9_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN10_EN
                (NUCODEGEN_GPIO_PE_PIN10_DBEN << GPIO_DBEN_DBEN10_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN11_EN
                (NUCODEGEN_GPIO_PE_PIN11_DBEN << GPIO_DBEN_DBEN11_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN12_EN
                (NUCODEGEN_GPIO_PE_PIN12_DBEN << GPIO_DBEN_DBEN12_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN13_EN
                (NUCODEGEN_GPIO_PE_PIN13_DBEN << GPIO_DBEN_DBEN13_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN14_EN
                (NUCODEGEN_GPIO_PE_PIN14_DBEN << GPIO_DBEN_DBEN14_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN15_EN
                (NUCODEGEN_GPIO_PE_PIN15_DBEN << GPIO_DBEN_DBEN15_Pos) |
#endif
								u32RegDefault;

    //GPIO_PE edge or level interrupt
    PE->INTTYPE =
#if NUCODEGEN_GPIO_PE_PIN0_EN
									(NUCODEGEN_GPIO_PE_PIN0_INTTYPE << GPIO_INTTYPE_TYPE0_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN1_EN
                  (NUCODEGEN_GPIO_PE_PIN1_INTTYPE << GPIO_INTTYPE_TYPE1_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN2_EN
                  (NUCODEGEN_GPIO_PE_PIN2_INTTYPE << GPIO_INTTYPE_TYPE2_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN3_EN
                  (NUCODEGEN_GPIO_PE_PIN3_INTTYPE << GPIO_INTTYPE_TYPE3_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN4_EN
                  (NUCODEGEN_GPIO_PE_PIN4_INTTYPE << GPIO_INTTYPE_TYPE4_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN5_EN
                  (NUCODEGEN_GPIO_PE_PIN5_INTTYPE << GPIO_INTTYPE_TYPE5_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN6_EN
                  (NUCODEGEN_GPIO_PE_PIN6_INTTYPE << GPIO_INTTYPE_TYPE6_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN7_EN
                  (NUCODEGEN_GPIO_PE_PIN7_INTTYPE << GPIO_INTTYPE_TYPE7_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN8_EN
                  (NUCODEGEN_GPIO_PE_PIN8_INTTYPE << GPIO_INTTYPE_TYPE8_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN9_EN
                  (NUCODEGEN_GPIO_PE_PIN9_INTTYPE << GPIO_INTTYPE_TYPE9_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN10_EN
                  (NUCODEGEN_GPIO_PE_PIN10_INTTYPE << GPIO_INTTYPE_TYPE10_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN11_EN
                  (NUCODEGEN_GPIO_PE_PIN11_INTTYPE << GPIO_INTTYPE_TYPE11_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN12_EN
                  (NUCODEGEN_GPIO_PE_PIN12_INTTYPE << GPIO_INTTYPE_TYPE12_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN13_EN
                  (NUCODEGEN_GPIO_PE_PIN13_INTTYPE << GPIO_INTTYPE_TYPE13_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN14_EN
                  (NUCODEGEN_GPIO_PE_PIN14_INTTYPE << GPIO_INTTYPE_TYPE14_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN15_EN
                  (NUCODEGEN_GPIO_PE_PIN15_INTTYPE << GPIO_INTTYPE_TYPE15_Pos) |
#endif
								u32RegDefault;

    //GPIO_PE enable falling(edge) or low(level) interrupt
    PE->INTEN =
#if NUCODEGEN_GPIO_PE_PIN0_EN
								(NUCODEGEN_GPIO_PE_PIN0_FLIEN << GPIO_INTEN_FLIEN0_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN1_EN
                (NUCODEGEN_GPIO_PE_PIN1_FLIEN << GPIO_INTEN_FLIEN1_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN2_EN
                (NUCODEGEN_GPIO_PE_PIN2_FLIEN << GPIO_INTEN_FLIEN2_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN3_EN
                (NUCODEGEN_GPIO_PE_PIN3_FLIEN << GPIO_INTEN_FLIEN3_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN4_EN
                (NUCODEGEN_GPIO_PE_PIN4_FLIEN << GPIO_INTEN_FLIEN4_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN5_EN
                (NUCODEGEN_GPIO_PE_PIN5_FLIEN << GPIO_INTEN_FLIEN5_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN6_EN
                (NUCODEGEN_GPIO_PE_PIN6_FLIEN << GPIO_INTEN_FLIEN6_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN7_EN
                (NUCODEGEN_GPIO_PE_PIN7_FLIEN << GPIO_INTEN_FLIEN7_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN8_EN
                (NUCODEGEN_GPIO_PE_PIN8_FLIEN << GPIO_INTEN_FLIEN8_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN9_EN
                (NUCODEGEN_GPIO_PE_PIN9_FLIEN << GPIO_INTEN_FLIEN9_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN10_EN
                (NUCODEGEN_GPIO_PE_PIN10_FLIEN << GPIO_INTEN_FLIEN10_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN11_EN
                (NUCODEGEN_GPIO_PE_PIN11_FLIEN << GPIO_INTEN_FLIEN11_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN12_EN
                (NUCODEGEN_GPIO_PE_PIN12_FLIEN << GPIO_INTEN_FLIEN12_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN13_EN
                (NUCODEGEN_GPIO_PE_PIN13_FLIEN << GPIO_INTEN_FLIEN13_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN14_EN
                (NUCODEGEN_GPIO_PE_PIN14_FLIEN << GPIO_INTEN_FLIEN14_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN15_EN
                (NUCODEGEN_GPIO_PE_PIN15_FLIEN << GPIO_INTEN_FLIEN15_Pos) |
#endif
								u32RegDefault;

    //GPIO_PE enable rising(edge) or high(level) interrupt
    PE->INTEN |=
#if NUCODEGEN_GPIO_PE_PIN0_EN
								 (NUCODEGEN_GPIO_PE_PIN0_RHIEN << GPIO_INTEN_RHIEN0_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN1_EN
                 (NUCODEGEN_GPIO_PE_PIN1_RHIEN << GPIO_INTEN_RHIEN1_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN2_EN
                 (NUCODEGEN_GPIO_PE_PIN2_RHIEN << GPIO_INTEN_RHIEN2_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN3_EN
                 (NUCODEGEN_GPIO_PE_PIN3_RHIEN << GPIO_INTEN_RHIEN3_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN4_EN
                 (NUCODEGEN_GPIO_PE_PIN4_RHIEN << GPIO_INTEN_RHIEN4_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN5_EN
                 (NUCODEGEN_GPIO_PE_PIN5_RHIEN << GPIO_INTEN_RHIEN5_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN6_EN
                 (NUCODEGEN_GPIO_PE_PIN6_RHIEN << GPIO_INTEN_RHIEN6_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN7_EN
                 (NUCODEGEN_GPIO_PE_PIN7_RHIEN << GPIO_INTEN_RHIEN7_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN8_EN
                 (NUCODEGEN_GPIO_PE_PIN8_RHIEN << GPIO_INTEN_RHIEN8_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN9_EN
                 (NUCODEGEN_GPIO_PE_PIN9_RHIEN << GPIO_INTEN_RHIEN9_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN10_EN
                 (NUCODEGEN_GPIO_PE_PIN10_RHIEN << GPIO_INTEN_RHIEN10_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN11_EN
                 (NUCODEGEN_GPIO_PE_PIN11_RHIEN << GPIO_INTEN_RHIEN11_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN12_EN
                 (NUCODEGEN_GPIO_PE_PIN12_RHIEN << GPIO_INTEN_RHIEN12_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN13_EN
                 (NUCODEGEN_GPIO_PE_PIN13_RHIEN << GPIO_INTEN_RHIEN13_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN14_EN
                 (NUCODEGEN_GPIO_PE_PIN14_RHIEN << GPIO_INTEN_RHIEN14_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN15_EN
                 (NUCODEGEN_GPIO_PE_PIN15_RHIEN << GPIO_INTEN_RHIEN15_Pos) |
#endif
								u32RegDefault;

    //GPIO_PE slew rate
    PE->SLEWCTL =
#if NUCODEGEN_GPIO_PE_PIN0_EN
									(NUCODEGEN_GPIO_PE_PIN0_SLEW << GPIO_SLEWCTL_HSREN0_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN1_EN
                  (NUCODEGEN_GPIO_PE_PIN1_SLEW << GPIO_SLEWCTL_HSREN1_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN2_EN
                  (NUCODEGEN_GPIO_PE_PIN2_SLEW << GPIO_SLEWCTL_HSREN2_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN3_EN
                  (NUCODEGEN_GPIO_PE_PIN3_SLEW << GPIO_SLEWCTL_HSREN3_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN4_EN
                  (NUCODEGEN_GPIO_PE_PIN4_SLEW << GPIO_SLEWCTL_HSREN4_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN5_EN
                  (NUCODEGEN_GPIO_PE_PIN5_SLEW << GPIO_SLEWCTL_HSREN5_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN6_EN
                  (NUCODEGEN_GPIO_PE_PIN6_SLEW << GPIO_SLEWCTL_HSREN6_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN7_EN
                  (NUCODEGEN_GPIO_PE_PIN7_SLEW << GPIO_SLEWCTL_HSREN7_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN8_EN
                  (NUCODEGEN_GPIO_PE_PIN8_SLEW << GPIO_SLEWCTL_HSREN8_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN9_EN
                  (NUCODEGEN_GPIO_PE_PIN9_SLEW << GPIO_SLEWCTL_HSREN9_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN10_EN
                  (NUCODEGEN_GPIO_PE_PIN10_SLEW << GPIO_SLEWCTL_HSREN10_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN11_EN
                  (NUCODEGEN_GPIO_PE_PIN11_SLEW << GPIO_SLEWCTL_HSREN11_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN12_EN
                  (NUCODEGEN_GPIO_PE_PIN12_SLEW << GPIO_SLEWCTL_HSREN12_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN13_EN
                  (NUCODEGEN_GPIO_PE_PIN13_SLEW << GPIO_SLEWCTL_HSREN13_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN14_EN
                  (NUCODEGEN_GPIO_PE_PIN14_SLEW << GPIO_SLEWCTL_HSREN14_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN15_EN
                  (NUCODEGEN_GPIO_PE_PIN15_SLEW << GPIO_SLEWCTL_HSREN15_Pos) |
#endif
								u32RegDefault;

    //GPIO_PE pull-up or pull-down
    PE->PUSEL =
#if NUCODEGEN_GPIO_PE_PIN0_EN
								(NUCODEGEN_GPIO_PE_PIN0_PUSEL << GPIO_PUSEL_PUSEL0_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN1_EN
                (NUCODEGEN_GPIO_PE_PIN1_PUSEL << GPIO_PUSEL_PUSEL1_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN2_EN
                (NUCODEGEN_GPIO_PE_PIN2_PUSEL << GPIO_PUSEL_PUSEL2_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN3_EN
                (NUCODEGEN_GPIO_PE_PIN3_PUSEL << GPIO_PUSEL_PUSEL3_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN4_EN
                (NUCODEGEN_GPIO_PE_PIN4_PUSEL << GPIO_PUSEL_PUSEL4_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN5_EN
                (NUCODEGEN_GPIO_PE_PIN5_PUSEL << GPIO_PUSEL_PUSEL5_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN6_EN
                (NUCODEGEN_GPIO_PE_PIN6_PUSEL << GPIO_PUSEL_PUSEL6_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN7_EN
                (NUCODEGEN_GPIO_PE_PIN7_PUSEL << GPIO_PUSEL_PUSEL7_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN8_EN
                (NUCODEGEN_GPIO_PE_PIN8_PUSEL << GPIO_PUSEL_PUSEL8_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN9_EN
                (NUCODEGEN_GPIO_PE_PIN9_PUSEL << GPIO_PUSEL_PUSEL9_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN10_EN
                (NUCODEGEN_GPIO_PE_PIN10_PUSEL << GPIO_PUSEL_PUSEL10_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN11_EN
                (NUCODEGEN_GPIO_PE_PIN11_PUSEL << GPIO_PUSEL_PUSEL11_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN12_EN
                (NUCODEGEN_GPIO_PE_PIN12_PUSEL << GPIO_PUSEL_PUSEL12_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN13_EN
                (NUCODEGEN_GPIO_PE_PIN13_PUSEL << GPIO_PUSEL_PUSEL13_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN14_EN
                (NUCODEGEN_GPIO_PE_PIN14_PUSEL << GPIO_PUSEL_PUSEL14_Pos) |
#endif
#if NUCODEGEN_GPIO_PE_PIN15_EN
                (NUCODEGEN_GPIO_PE_PIN15_PUSEL << GPIO_PUSEL_PUSEL15_Pos) |
#endif
								u32RegDefault;

#if(NUCODEGEN_GPIO_PE_CLR_DB_ICLKON)
    GPIO_CLR_DEBOUNCE_ICLKON(PE);
#endif

#if(NUCODEGEN_GPIO_PE_INT)
    NVIC_EnableIRQ(GPE_IRQn);
#endif
#endif //NUCODEGEN_GPIO_PE

#if(NUCODEGEN_GPIO_PF)
    //GPIO_PF mode
    PF->MODE =
#if NUCODEGEN_GPIO_PF_PIN0_EN
								(NUCODEGEN_GPIO_PF_PIN0_MODE << GPIO_MODE_MODE0_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN1_EN
                (NUCODEGEN_GPIO_PF_PIN1_MODE << GPIO_MODE_MODE1_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN2_EN
                (NUCODEGEN_GPIO_PF_PIN2_MODE << GPIO_MODE_MODE2_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN3_EN
                (NUCODEGEN_GPIO_PF_PIN3_MODE << GPIO_MODE_MODE3_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN4_EN
                (NUCODEGEN_GPIO_PF_PIN4_MODE << GPIO_MODE_MODE4_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN5_EN
                (NUCODEGEN_GPIO_PF_PIN5_MODE << GPIO_MODE_MODE5_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN6_EN
                (NUCODEGEN_GPIO_PF_PIN6_MODE << GPIO_MODE_MODE6_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN7_EN
                (NUCODEGEN_GPIO_PF_PIN7_MODE << GPIO_MODE_MODE7_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN8_EN
                (NUCODEGEN_GPIO_PF_PIN8_MODE << GPIO_MODE_MODE8_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN9_EN
                (NUCODEGEN_GPIO_PF_PIN9_MODE << GPIO_MODE_MODE9_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN10_EN
                (NUCODEGEN_GPIO_PF_PIN10_MODE << GPIO_MODE_MODE10_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN11_EN
                (NUCODEGEN_GPIO_PF_PIN11_MODE << GPIO_MODE_MODE11_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN12_EN
                (NUCODEGEN_GPIO_PF_PIN12_MODE << GPIO_MODE_MODE12_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN13_EN
                (NUCODEGEN_GPIO_PF_PIN13_MODE << GPIO_MODE_MODE13_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN14_EN
                (NUCODEGEN_GPIO_PF_PIN14_MODE << GPIO_MODE_MODE14_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN15_EN
                (NUCODEGEN_GPIO_PF_PIN15_MODE << GPIO_MODE_MODE15_Pos) |
#endif
								u32RegDefault;

    //GPIO_PF disable digital input path
    PF->DINOFF =
#if NUCODEGEN_GPIO_PF_PIN0_EN
								 (NUCODEGEN_GPIO_PF_PIN0_DINOFF << GPIO_DINOFF_DINOFF0_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN1_EN
                 (NUCODEGEN_GPIO_PF_PIN1_DINOFF << GPIO_DINOFF_DINOFF1_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN2_EN
                 (NUCODEGEN_GPIO_PF_PIN2_DINOFF << GPIO_DINOFF_DINOFF2_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN3_EN
                 (NUCODEGEN_GPIO_PF_PIN3_DINOFF << GPIO_DINOFF_DINOFF3_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN4_EN
                 (NUCODEGEN_GPIO_PF_PIN4_DINOFF << GPIO_DINOFF_DINOFF4_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN5_EN
                 (NUCODEGEN_GPIO_PF_PIN5_DINOFF << GPIO_DINOFF_DINOFF5_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN6_EN
                 (NUCODEGEN_GPIO_PF_PIN6_DINOFF << GPIO_DINOFF_DINOFF6_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN7_EN
                 (NUCODEGEN_GPIO_PF_PIN7_DINOFF << GPIO_DINOFF_DINOFF7_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN8_EN
                 (NUCODEGEN_GPIO_PF_PIN8_DINOFF << GPIO_DINOFF_DINOFF8_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN9_EN
                 (NUCODEGEN_GPIO_PF_PIN9_DINOFF << GPIO_DINOFF_DINOFF9_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN10_EN
                 (NUCODEGEN_GPIO_PF_PIN10_DINOFF << GPIO_DINOFF_DINOFF10_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN11_EN
                 (NUCODEGEN_GPIO_PF_PIN11_DINOFF << GPIO_DINOFF_DINOFF11_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN12_EN
                 (NUCODEGEN_GPIO_PF_PIN12_DINOFF << GPIO_DINOFF_DINOFF12_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN13_EN
                 (NUCODEGEN_GPIO_PF_PIN13_DINOFF << GPIO_DINOFF_DINOFF13_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN14_EN
                 (NUCODEGEN_GPIO_PF_PIN14_DINOFF << GPIO_DINOFF_DINOFF14_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN15_EN
                 (NUCODEGEN_GPIO_PF_PIN15_DINOFF << GPIO_DINOFF_DINOFF15_Pos) |
#endif
								u32RegDefault;

    //GPIO_PF out data
    PF->DOUT =
#if NUCODEGEN_GPIO_PF_PIN0_EN
								(NUCODEGEN_GPIO_PF_PIN0_DOUT << GPIO_DOUT_DOUT0_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN1_EN
                (NUCODEGEN_GPIO_PF_PIN1_DOUT << GPIO_DOUT_DOUT1_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN2_EN
                (NUCODEGEN_GPIO_PF_PIN2_DOUT << GPIO_DOUT_DOUT2_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN3_EN
                (NUCODEGEN_GPIO_PF_PIN3_DOUT << GPIO_DOUT_DOUT3_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN4_EN
                (NUCODEGEN_GPIO_PF_PIN4_DOUT << GPIO_DOUT_DOUT4_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN5_EN
                (NUCODEGEN_GPIO_PF_PIN5_DOUT << GPIO_DOUT_DOUT5_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN6_EN
                (NUCODEGEN_GPIO_PF_PIN6_DOUT << GPIO_DOUT_DOUT6_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN7_EN
                (NUCODEGEN_GPIO_PF_PIN7_DOUT << GPIO_DOUT_DOUT7_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN8_EN
                (NUCODEGEN_GPIO_PF_PIN8_DOUT << GPIO_DOUT_DOUT8_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN9_EN
                (NUCODEGEN_GPIO_PF_PIN9_DOUT << GPIO_DOUT_DOUT9_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN10_EN
                (NUCODEGEN_GPIO_PF_PIN10_DOUT << GPIO_DOUT_DOUT10_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN11_EN
                (NUCODEGEN_GPIO_PF_PIN11_DOUT << GPIO_DOUT_DOUT11_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN12_EN
                (NUCODEGEN_GPIO_PF_PIN12_DOUT << GPIO_DOUT_DOUT12_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN13_EN
                (NUCODEGEN_GPIO_PF_PIN13_DOUT << GPIO_DOUT_DOUT13_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN14_EN
                (NUCODEGEN_GPIO_PF_PIN14_DOUT << GPIO_DOUT_DOUT14_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN15_EN
                (NUCODEGEN_GPIO_PF_PIN15_DOUT << GPIO_DOUT_DOUT15_Pos) |
#endif
								u32RegDefault;

    //GPIO_PF DOUT mask
    PF->DATMSK =
#if NUCODEGEN_GPIO_PF_PIN0_EN
								 (NUCODEGEN_GPIO_PF_PIN0_DATMSK << GPIO_DATMSK_DATMSK0_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN1_EN
                 (NUCODEGEN_GPIO_PF_PIN1_DATMSK << GPIO_DATMSK_DATMSK1_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN2_EN
                 (NUCODEGEN_GPIO_PF_PIN2_DATMSK << GPIO_DATMSK_DATMSK2_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN3_EN
                 (NUCODEGEN_GPIO_PF_PIN3_DATMSK << GPIO_DATMSK_DATMSK3_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN4_EN
                 (NUCODEGEN_GPIO_PF_PIN4_DATMSK << GPIO_DATMSK_DATMSK4_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN5_EN
                 (NUCODEGEN_GPIO_PF_PIN5_DATMSK << GPIO_DATMSK_DATMSK5_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN6_EN
                 (NUCODEGEN_GPIO_PF_PIN6_DATMSK << GPIO_DATMSK_DATMSK6_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN7_EN
                 (NUCODEGEN_GPIO_PF_PIN7_DATMSK << GPIO_DATMSK_DATMSK7_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN8_EN
                 (NUCODEGEN_GPIO_PF_PIN8_DATMSK << GPIO_DATMSK_DATMSK8_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN9_EN
                 (NUCODEGEN_GPIO_PF_PIN9_DATMSK << GPIO_DATMSK_DATMSK9_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN10_EN
                 (NUCODEGEN_GPIO_PF_PIN10_DATMSK << GPIO_DATMSK_DATMSK10_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN11_EN
                 (NUCODEGEN_GPIO_PF_PIN11_DATMSK << GPIO_DATMSK_DATMSK11_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN12_EN
                 (NUCODEGEN_GPIO_PF_PIN12_DATMSK << GPIO_DATMSK_DATMSK12_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN13_EN
                 (NUCODEGEN_GPIO_PF_PIN13_DATMSK << GPIO_DATMSK_DATMSK13_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN14_EN
                 (NUCODEGEN_GPIO_PF_PIN14_DATMSK << GPIO_DATMSK_DATMSK14_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN15_EN
                 (NUCODEGEN_GPIO_PF_PIN15_DATMSK << GPIO_DATMSK_DATMSK15_Pos) |
#endif
								u32RegDefault;

    //GPIO_PF enable de-bounce
    PF->DBEN =
#if NUCODEGEN_GPIO_PF_PIN0_EN
								(NUCODEGEN_GPIO_PF_PIN0_DBEN << GPIO_DBEN_DBEN0_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN1_EN
                (NUCODEGEN_GPIO_PF_PIN1_DBEN << GPIO_DBEN_DBEN1_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN2_EN
                (NUCODEGEN_GPIO_PF_PIN2_DBEN << GPIO_DBEN_DBEN2_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN3_EN
                (NUCODEGEN_GPIO_PF_PIN3_DBEN << GPIO_DBEN_DBEN3_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN4_EN
                (NUCODEGEN_GPIO_PF_PIN4_DBEN << GPIO_DBEN_DBEN4_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN5_EN
                (NUCODEGEN_GPIO_PF_PIN5_DBEN << GPIO_DBEN_DBEN5_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN6_EN
                (NUCODEGEN_GPIO_PF_PIN6_DBEN << GPIO_DBEN_DBEN6_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN7_EN
                (NUCODEGEN_GPIO_PF_PIN7_DBEN << GPIO_DBEN_DBEN7_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN8_EN
                (NUCODEGEN_GPIO_PF_PIN8_DBEN << GPIO_DBEN_DBEN8_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN9_EN
                (NUCODEGEN_GPIO_PF_PIN9_DBEN << GPIO_DBEN_DBEN9_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN10_EN
                (NUCODEGEN_GPIO_PF_PIN10_DBEN << GPIO_DBEN_DBEN10_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN11_EN
                (NUCODEGEN_GPIO_PF_PIN11_DBEN << GPIO_DBEN_DBEN11_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN12_EN
                (NUCODEGEN_GPIO_PF_PIN12_DBEN << GPIO_DBEN_DBEN12_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN13_EN
                (NUCODEGEN_GPIO_PF_PIN13_DBEN << GPIO_DBEN_DBEN13_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN14_EN
                (NUCODEGEN_GPIO_PF_PIN14_DBEN << GPIO_DBEN_DBEN14_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN15_EN
                (NUCODEGEN_GPIO_PF_PIN15_DBEN << GPIO_DBEN_DBEN15_Pos) |
#endif
								u32RegDefault;

    //GPIO_PF edge or level interrupt
    PF->INTTYPE =
#if NUCODEGEN_GPIO_PF_PIN0_EN
									(NUCODEGEN_GPIO_PF_PIN0_INTTYPE << GPIO_INTTYPE_TYPE0_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN1_EN
                  (NUCODEGEN_GPIO_PF_PIN1_INTTYPE << GPIO_INTTYPE_TYPE1_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN2_EN
                  (NUCODEGEN_GPIO_PF_PIN2_INTTYPE << GPIO_INTTYPE_TYPE2_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN3_EN
                  (NUCODEGEN_GPIO_PF_PIN3_INTTYPE << GPIO_INTTYPE_TYPE3_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN4_EN
                  (NUCODEGEN_GPIO_PF_PIN4_INTTYPE << GPIO_INTTYPE_TYPE4_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN5_EN
                  (NUCODEGEN_GPIO_PF_PIN5_INTTYPE << GPIO_INTTYPE_TYPE5_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN6_EN
                  (NUCODEGEN_GPIO_PF_PIN6_INTTYPE << GPIO_INTTYPE_TYPE6_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN7_EN
                  (NUCODEGEN_GPIO_PF_PIN7_INTTYPE << GPIO_INTTYPE_TYPE7_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN8_EN
                  (NUCODEGEN_GPIO_PF_PIN8_INTTYPE << GPIO_INTTYPE_TYPE8_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN9_EN
                  (NUCODEGEN_GPIO_PF_PIN9_INTTYPE << GPIO_INTTYPE_TYPE9_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN10_EN
                  (NUCODEGEN_GPIO_PF_PIN10_INTTYPE << GPIO_INTTYPE_TYPE10_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN11_EN
                  (NUCODEGEN_GPIO_PF_PIN11_INTTYPE << GPIO_INTTYPE_TYPE11_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN12_EN
                  (NUCODEGEN_GPIO_PF_PIN12_INTTYPE << GPIO_INTTYPE_TYPE12_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN13_EN
                  (NUCODEGEN_GPIO_PF_PIN13_INTTYPE << GPIO_INTTYPE_TYPE13_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN14_EN
                  (NUCODEGEN_GPIO_PF_PIN14_INTTYPE << GPIO_INTTYPE_TYPE14_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN15_EN
                  (NUCODEGEN_GPIO_PF_PIN15_INTTYPE << GPIO_INTTYPE_TYPE15_Pos) |
#endif
								u32RegDefault;

    //GPIO_PF enable falling(edge) or low(level) interrupt
    PF->INTEN =
#if NUCODEGEN_GPIO_PF_PIN0_EN
								(NUCODEGEN_GPIO_PF_PIN0_FLIEN << GPIO_INTEN_FLIEN0_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN1_EN
                (NUCODEGEN_GPIO_PF_PIN1_FLIEN << GPIO_INTEN_FLIEN1_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN2_EN
                (NUCODEGEN_GPIO_PF_PIN2_FLIEN << GPIO_INTEN_FLIEN2_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN3_EN
                (NUCODEGEN_GPIO_PF_PIN3_FLIEN << GPIO_INTEN_FLIEN3_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN4_EN
                (NUCODEGEN_GPIO_PF_PIN4_FLIEN << GPIO_INTEN_FLIEN4_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN5_EN
                (NUCODEGEN_GPIO_PF_PIN5_FLIEN << GPIO_INTEN_FLIEN5_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN6_EN
                (NUCODEGEN_GPIO_PF_PIN6_FLIEN << GPIO_INTEN_FLIEN6_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN7_EN
                (NUCODEGEN_GPIO_PF_PIN7_FLIEN << GPIO_INTEN_FLIEN7_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN8_EN
                (NUCODEGEN_GPIO_PF_PIN8_FLIEN << GPIO_INTEN_FLIEN8_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN9_EN
                (NUCODEGEN_GPIO_PF_PIN9_FLIEN << GPIO_INTEN_FLIEN9_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN10_EN
                (NUCODEGEN_GPIO_PF_PIN10_FLIEN << GPIO_INTEN_FLIEN10_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN11_EN
                (NUCODEGEN_GPIO_PF_PIN11_FLIEN << GPIO_INTEN_FLIEN11_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN12_EN
                (NUCODEGEN_GPIO_PF_PIN12_FLIEN << GPIO_INTEN_FLIEN12_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN13_EN
                (NUCODEGEN_GPIO_PF_PIN13_FLIEN << GPIO_INTEN_FLIEN13_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN14_EN
                (NUCODEGEN_GPIO_PF_PIN14_FLIEN << GPIO_INTEN_FLIEN14_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN15_EN
                (NUCODEGEN_GPIO_PF_PIN15_FLIEN << GPIO_INTEN_FLIEN15_Pos) |
#endif
								u32RegDefault;

    //GPIO_PF enable rising(edge) or high(level) interrupt
    PF->INTEN |=
#if NUCODEGEN_GPIO_PF_PIN0_EN
								 (NUCODEGEN_GPIO_PF_PIN0_RHIEN << GPIO_INTEN_RHIEN0_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN1_EN
                 (NUCODEGEN_GPIO_PF_PIN1_RHIEN << GPIO_INTEN_RHIEN1_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN2_EN
                 (NUCODEGEN_GPIO_PF_PIN2_RHIEN << GPIO_INTEN_RHIEN2_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN3_EN
                 (NUCODEGEN_GPIO_PF_PIN3_RHIEN << GPIO_INTEN_RHIEN3_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN4_EN
                 (NUCODEGEN_GPIO_PF_PIN4_RHIEN << GPIO_INTEN_RHIEN4_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN5_EN
                 (NUCODEGEN_GPIO_PF_PIN5_RHIEN << GPIO_INTEN_RHIEN5_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN6_EN
                 (NUCODEGEN_GPIO_PF_PIN6_RHIEN << GPIO_INTEN_RHIEN6_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN7_EN
                 (NUCODEGEN_GPIO_PF_PIN7_RHIEN << GPIO_INTEN_RHIEN7_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN8_EN
                 (NUCODEGEN_GPIO_PF_PIN8_RHIEN << GPIO_INTEN_RHIEN8_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN9_EN
                 (NUCODEGEN_GPIO_PF_PIN9_RHIEN << GPIO_INTEN_RHIEN9_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN10_EN
                 (NUCODEGEN_GPIO_PF_PIN10_RHIEN << GPIO_INTEN_RHIEN10_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN11_EN
                 (NUCODEGEN_GPIO_PF_PIN11_RHIEN << GPIO_INTEN_RHIEN11_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN12_EN
                 (NUCODEGEN_GPIO_PF_PIN12_RHIEN << GPIO_INTEN_RHIEN12_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN13_EN
                 (NUCODEGEN_GPIO_PF_PIN13_RHIEN << GPIO_INTEN_RHIEN13_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN14_EN
                 (NUCODEGEN_GPIO_PF_PIN14_RHIEN << GPIO_INTEN_RHIEN14_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN15_EN
                 (NUCODEGEN_GPIO_PF_PIN15_RHIEN << GPIO_INTEN_RHIEN15_Pos) |
#endif
								u32RegDefault;

    //GPIO_PF slew rate
    PF->SLEWCTL =
#if NUCODEGEN_GPIO_PF_PIN0_EN
									(NUCODEGEN_GPIO_PF_PIN0_SLEW << GPIO_SLEWCTL_HSREN0_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN1_EN
                  (NUCODEGEN_GPIO_PF_PIN1_SLEW << GPIO_SLEWCTL_HSREN1_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN2_EN
                  (NUCODEGEN_GPIO_PF_PIN2_SLEW << GPIO_SLEWCTL_HSREN2_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN3_EN
                  (NUCODEGEN_GPIO_PF_PIN3_SLEW << GPIO_SLEWCTL_HSREN3_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN4_EN
                  (NUCODEGEN_GPIO_PF_PIN4_SLEW << GPIO_SLEWCTL_HSREN4_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN5_EN
                  (NUCODEGEN_GPIO_PF_PIN5_SLEW << GPIO_SLEWCTL_HSREN5_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN6_EN
                  (NUCODEGEN_GPIO_PF_PIN6_SLEW << GPIO_SLEWCTL_HSREN6_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN7_EN
                  (NUCODEGEN_GPIO_PF_PIN7_SLEW << GPIO_SLEWCTL_HSREN7_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN8_EN
                  (NUCODEGEN_GPIO_PF_PIN8_SLEW << GPIO_SLEWCTL_HSREN8_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN9_EN
                  (NUCODEGEN_GPIO_PF_PIN9_SLEW << GPIO_SLEWCTL_HSREN9_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN10_EN
                  (NUCODEGEN_GPIO_PF_PIN10_SLEW << GPIO_SLEWCTL_HSREN10_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN11_EN
                  (NUCODEGEN_GPIO_PF_PIN11_SLEW << GPIO_SLEWCTL_HSREN11_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN12_EN
                  (NUCODEGEN_GPIO_PF_PIN12_SLEW << GPIO_SLEWCTL_HSREN12_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN13_EN
                  (NUCODEGEN_GPIO_PF_PIN13_SLEW << GPIO_SLEWCTL_HSREN13_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN14_EN
                  (NUCODEGEN_GPIO_PF_PIN14_SLEW << GPIO_SLEWCTL_HSREN14_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN15_EN
                  (NUCODEGEN_GPIO_PF_PIN15_SLEW << GPIO_SLEWCTL_HSREN15_Pos) |
#endif
								u32RegDefault;

    //GPIO_PF pull-up or pull-down
    PF->PUSEL =
#if NUCODEGEN_GPIO_PF_PIN0_EN
								(NUCODEGEN_GPIO_PF_PIN0_PUSEL << GPIO_PUSEL_PUSEL0_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN1_EN
                (NUCODEGEN_GPIO_PF_PIN1_PUSEL << GPIO_PUSEL_PUSEL1_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN2_EN
                (NUCODEGEN_GPIO_PF_PIN2_PUSEL << GPIO_PUSEL_PUSEL2_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN3_EN
                (NUCODEGEN_GPIO_PF_PIN3_PUSEL << GPIO_PUSEL_PUSEL3_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN4_EN
                (NUCODEGEN_GPIO_PF_PIN4_PUSEL << GPIO_PUSEL_PUSEL4_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN5_EN
                (NUCODEGEN_GPIO_PF_PIN5_PUSEL << GPIO_PUSEL_PUSEL5_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN6_EN
                (NUCODEGEN_GPIO_PF_PIN6_PUSEL << GPIO_PUSEL_PUSEL6_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN7_EN
                (NUCODEGEN_GPIO_PF_PIN7_PUSEL << GPIO_PUSEL_PUSEL7_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN8_EN
                (NUCODEGEN_GPIO_PF_PIN8_PUSEL << GPIO_PUSEL_PUSEL8_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN9_EN
                (NUCODEGEN_GPIO_PF_PIN9_PUSEL << GPIO_PUSEL_PUSEL9_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN10_EN
                (NUCODEGEN_GPIO_PF_PIN10_PUSEL << GPIO_PUSEL_PUSEL10_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN11_EN
                (NUCODEGEN_GPIO_PF_PIN11_PUSEL << GPIO_PUSEL_PUSEL11_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN12_EN
                (NUCODEGEN_GPIO_PF_PIN12_PUSEL << GPIO_PUSEL_PUSEL12_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN13_EN
                (NUCODEGEN_GPIO_PF_PIN13_PUSEL << GPIO_PUSEL_PUSEL13_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN14_EN
                (NUCODEGEN_GPIO_PF_PIN14_PUSEL << GPIO_PUSEL_PUSEL14_Pos) |
#endif
#if NUCODEGEN_GPIO_PF_PIN15_EN
                (NUCODEGEN_GPIO_PF_PIN15_PUSEL << GPIO_PUSEL_PUSEL15_Pos) |
#endif
								u32RegDefault;

#if(NUCODEGEN_GPIO_PF_CLR_DB_ICLKON)
    GPIO_CLR_DEBOUNCE_ICLKON(PF);
#endif

#if(NUCODEGEN_GPIO_PF_INT)
    NVIC_EnableIRQ(GPF_IRQn);
#endif
#endif //NUCODEGEN_GPIO_PF
}
#endif //NUCODEGEN_GPIO

#if NUCODEGEN_CLK
void CLK_Init(void)
{
#if (NUCODEGEN_CLK_DET_ENABLE)
    /* Configure clock detector functions, which are able to monitor the operations of HXT and LXT */
    CLK->CLKDCTL = (NUCODEGEN_CLK_DET_CONFIG);
#endif

#if (NUCODEGEN_CLK_HXT_FREQ_DET_ENABLE)
    /* Configure the upper bound and lower bound of HXT frequency range detetor */
    CLK->CDUPB  = CLK_HXT_FREQUENCY_RANGE_UPPER_BOUND;
    CLK->CDLOWB = CLK_HXT_FREQUENCY_RANGE_LOWER_BOUND;
#endif

#if (NUCODEGEN_CLK_PDWK_INT_ENABLE)
    /* NVIC enable clock power down wake-up interrupt */
    NVIC_EnableIRQ(PWRWU_IRQn);

    /* Enable the power down wake-up interrupt in clock controller. */
    CLK->PWRCTL |= (CLK_PWRCTL_PDWKIEN_Msk);
#endif

#if (NUCODEGEN_CLK_CLKFAIL_INT_ENABLE)
    /* NVIC enable clock fail interrupt */
    NVIC_EnableIRQ(CLKFAIL_IRQn);

    /* Enable the selected clock detector interrupt source in clock controller. */
    CLK->CLKDCTL |= (NUCODEGEN_CLK_CLKFAIL_INT_CONFIG);
#endif

#if (NUCODEGEN_CLK_POWER_DOWN_ENABLE)
    /* Unlock protected registers before we configure power down settings. */
    SYS_UnlockReg();

    /* Select clock power down mode */
    CLK_SetPowerDownMode(NUCODEGEN_CLK_POWER_DOWN_MODE);

#if (NUCODEGEN_CLK_POWER_DOWN_IS_DPD)
#if (NUCODEGEN_CLK_WKPINDB_ENABLE)
    /* Enable DPD wake-up pin debounce */
    CLK_ENABLE_WKPINDB();
#else
    /* Disable DPD wake-up pin debounce */
    CLK_DISABLE_WKPINDB();
#endif /* NUCODEGEN_CLK_WKPINDB_ENABLED */

#if (NUCODEGEN_CLK_DPDWKPIN0_ENABLE)
    /* Enable DPD wake-up pin 0 */
    CLK_EnableDPDWKPin0(NUCODEGEN_CLK_DPDWKPIN0_CONFIG);
#endif

#if (NUCODEGEN_CLK_DPDWKPIN1_ENABLE)
    /* Enable DPD wake-up pin 1 */
    CLK_EnableDPDWKPin1(NUCODEGEN_CLK_DPDWKPIN1_CONFIG);
#endif

#if (NUCODEGEN_CLK_DPDWKPIN2_ENABLE)
    /* Enable DPD wake-up pin 2 */
    CLK_EnableDPDWKPin2(NUCODEGEN_CLK_DPDWKPIN2_CONFIG);
#endif

#if (NUCODEGEN_CLK_DPDWKPIN3_ENABLE)
    /* Enable DPD wake-up pin 3 */
    CLK_EnableDPDWKPin3(NUCODEGEN_CLK_DPDWKPIN3_CONFIG);
#endif

#if (NUCODEGEN_CLK_DPDWKPIN4_ENABLE)
    /* Enable DPD wake-up pin 4 */
    CLK_EnableDPDWKPin4(NUCODEGEN_CLK_DPDWKPIN4_CONFIG);
#endif

#if (NUCODEGEN_CLK_DPDRTCWK_ENABLE)

    /* Enable DPD wake-up by RTC interrupt source */
    CLK_ENABLE_RTCWK();
#endif /* NUCODEGEN_CLK_DPDRTCWK_ENABLE */

#if (NUCODEGEN_CLK_DPDWKTMR_ENABLE)
    /* Configure the timeout interval of Wake-up Timer */
    CLK_SET_WKTMR_INTERVAL(NUCODEGEN_CLK_DPDWKTMR_CONFIG);

    /* Enable Wake-up Timer */
    CLK_ENABLE_WKTMR();
#endif /* NUCODEGEN_CLK_DPDWKTMR_ENABLE */
#endif /* NUCODEGEN_CLK_POWER_DOWN_IS_DPD */
#endif /* NUCODEGEN_CLK_POWER_DOWN_ENABLE */
}
#endif /* NUCODEGEN_CLK */

#if NUCODEGEN_SYS
void SYS_Init(void)
{
#if (NUCODEGEN_SYS_BODEN_CONFIG)
    /* Brown-Out Detector initialization */
    SYS_EnableBOD(NUCODEGEN_SYS_BODRSTEN_CONFIG, NUCODEGEN_SYS_BODVL_CONFIG);

    /* Setup BOD de-glitch time */
    SYS->BODCTL = (SYS->BODCTL & ~SYS_BODCTL_BODDGSEL_Msk) | NUCODEGEN_SYS_BODDG_CONFIG;

#if (NUCODEGEN_SYS_BODLPM_CONFIG)
    /* Setup BOD mode as Low-Power Mode */
    SYS_SET_BOD_LPM();
#else
    /* Setup BOD mode as Normal-Power Mode */
    SYS_CLEAR_BOD_LPM();
#endif /* NUCODEGEN_SYS_BODLPM_CONFIG */

#if (NUCODEGEN_SYS_BOD_INT_ENABLE)
    /* Enable BOD NVIC interrupt */
    NVIC_EnableIRQ(BOD_IRQn);
#endif

#else
    /* Disable Brown-Out Detector function */
    SYS_DisableBOD();
#endif /* NUCODEGEN_SYS_BODEN_CONFIG */

#if (NUCODEGEN_SYS_LVREN_CONFIG)
    /* Low-Voltage Detector initialization */
    SYS_ENABLE_LVR();

    /* Setup LVR de-glitch time */
    SYS->BODCTL = (SYS->BODCTL & ~SYS_BODCTL_LVRDGSEL_Msk) | NUCODEGEN_SYS_LVRDG_CONFIG;
#else
    /* Dsiable Low-Voltage Detector function */
    SYS_DISABLE_LVR();
#endif /* NUCODEGEN_SYS_LVREN_CONFIG */

#if (NUCODEGEN_SYS_IVREN_ENABLE)
    /* Configure Internal Voltage Reference Module */
    SYS->VREFCTL = SYS_VREFCTL_IVREN_Msk | NUCODEGEN_SYS_IVRS_CONFIG;
#endif /* NUCODEGEN_SYS_IVREN_ENABLE */

#if (NUCODEGEN_SYS_HIRCTRIM_EN)

    SYS->HIRCTRIMCTL = ((SYS->HIRCTRIMCTL & ~(SYS_HIRCTRIMCTL_FREQSEL_Msk | SYS_HIRCTRIMCTL_LOOPSEL_Msk | SYS_HIRCTRIMCTL_RETRYCNT_Msk |
                                              SYS_HIRCTRIMCTL_REFCKSEL_Msk | SYS_HIRCTRIMCTL_BOUNDEN_Msk | SYS_HIRCTRIMCTL_BOUNDARY_Msk | SYS_HIRCTRIMCTL_CESTOPEN_Msk))
                                             | (NUCODEGEN_SYS_HIRCTRIM_RETRYCNT << SYS_HIRCTRIMCTL_RETRYCNT_Pos)
                                             | (NUCODEGEN_SYS_HIRCTRIM_LOOPSEL << SYS_HIRCTRIMCTL_LOOPSEL_Pos)
                                             | (NUCODEGEN_SYS_HIRCTRIM_REFCLOCK << SYS_HIRCTRIMCTL_REFCKSEL_Pos)
                                             | (NUCODEGEN_SYS_HIRCTRIM_BOUND_EN << SYS_HIRCTRIMCTL_BOUNDEN_Pos)
                                             | (NUCODEGEN_SYS_HIRCTRIM_BOUND_RANGE << SYS_HIRCTRIMCTL_BOUNDARY_Pos)
                                             | (NUCODEGEN_SYS_HIRCTRIM_ERRSTOP_EN << SYS_HIRCTRIMCTL_CESTOPEN_Pos)
                                             | (0x1 << SYS_HIRCTRIMCTL_FREQSEL_Pos));

#if (NUCODEGEN_SYS_HIRCTRIM_INT_EN)
    /* Enable HIRC Trim Interrupt */
    SYS->HIRCTRIMIEN = (NUCODEGEN_SYS_HIRCTRIM_INT_SEL);
#endif  /* NUCODEGEN_SYS_HIRCTRIM_INT_EN */
#endif  /* NUCODEGEN_SYS_HIRCTRIM_EN  */

#if (NUCODEGEN_SYS_MIRCTRIM_EN)

    SYS->MIRCTRIMCTL = ((SYS->MIRCTRIMCTL & ~(SYS_MIRCTRIMCTL_FREQSEL_Msk | SYS_MIRCTRIMCTL_LOOPSEL_Msk | SYS_MIRCTRIMCTL_RETRYCNT_Msk |
                                              SYS_MIRCTRIMCTL_REFCKSEL_Msk | SYS_MIRCTRIMCTL_BOUNDEN_Msk | SYS_MIRCTRIMCTL_BOUNDARY_Msk | SYS_MIRCTRIMCTL_CESTOPEN_Msk))
                                             | (NUCODEGEN_SYS_MIRCTRIM_RETRYCNT << SYS_MIRCTRIMCTL_RETRYCNT_Pos)
                                             | (NUCODEGEN_SYS_MIRCTRIM_LOOPSEL << SYS_MIRCTRIMCTL_LOOPSEL_Pos)
                                             | (NUCODEGEN_SYS_MIRCTRIM_REFCLOCK << SYS_MIRCTRIMCTL_REFCKSEL_Pos)
                                             | (NUCODEGEN_SYS_MIRCTRIM_BOUND_EN << SYS_MIRCTRIMCTL_BOUNDEN_Pos)
                                             | (NUCODEGEN_SYS_MIRCTRIM_BOUND_RANGE << SYS_MIRCTRIMCTL_BOUNDARY_Pos)
                                             | (NUCODEGEN_SYS_MIRCTRIM_ERRSTOP_EN << SYS_MIRCTRIMCTL_CESTOPEN_Pos)
                                             | (0x2 << SYS_MIRCTRIMCTL_FREQSEL_Pos));

#if (NUCODEGEN_SYS_MIRCTRIM_INT_EN)
    /* Enable MIRC Trim Interrupt */
    SYS->MIRCTRIMIEN = (NUCODEGEN_SYS_MIRCTRIM_INT_SEL);
#endif /* NUCODEGEN_SYS_MIRCTRIM_INT_EN */
#endif /* NUCODEGEN_SYS_MIRCTRIM_EN */

#if (NUCODEGEN_SYS_MIRCTRIM_INT_EN || NUCODEGEN_SYS_HIRCTRIM_INT_EN)
    /* NVIC Enable RC Trim Interrupt */
    NVIC_EnableIRQ(IRCTRIM_IRQn);
#endif
}
#endif /* NUCODEGEN_SYS */

#if NUCODEGEN_CRYPTO
void CRYPTO_Init()
{
#if NUCODEGEN_CRYPTO_PRNG
        PRNG_Open(CRPT, NUCODEGEN_PRNG_KEYSIZE, NUCODEGEN_PRNG_SEED_MODE, PRNG_SEED);

        #if NUCODEGEN_PRNG_INT
    PRNG_ENABLE_INT(CRPT);
        #endif
#endif

#if NUCODEGEN_CRYPTO_AES

static uint32_t au32MyAESKey[8] =
{
    AES_KEY0, AES_KEY1, AES_KEY2, AES_KEY3,
    AES_KEY4, AES_KEY5, AES_KEY6, AES_KEY7
};

static uint32_t au32MyAESIV[4] =
{
    AES_IV0, AES_IV1, AES_IV2, AES_IV3
};

#ifdef __ICCARM__
#pragma data_alignment=4
static uint8_t au8InputData[] =
{
#else
static __attribute__((aligned(4))) uint8_t au8InputData[] =
{
#endif
    0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88,
    0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff
};

#ifdef __ICCARM__
    #pragma data_alignment=4
    static uint8_t au8OutputData[1024];
#else
    static __attribute__((aligned(4))) uint8_t au8OutputData[1024];
#endif

        AES_Open(CRPT, AES_CHANNEL, NUCODEGEN_AES_CRYPT, NUCODEGEN_AES_OP_MODE, NUCODEGEN_AES_KEYSIZE, NUCODEGEN_AES_SWAP_TYPE);
    AES_SetKey(CRPT, AES_CHANNEL, au32MyAESKey, NUCODEGEN_AES_KEYSIZE);
    AES_SetInitVect(CRPT, AES_CHANNEL, au32MyAESIV);
    AES_SetDMATransfer(CRPT, AES_CHANNEL, (uint32_t)au8InputData, (uint32_t)au8OutputData, sizeof(au8InputData));

        #if NUCODEGEN_AES_KEY_PROT
        AES_ENABLE_KEY_PROTECT(CRPT);
        #endif

        #if NUCODEGEN_AES_INT
    AES_ENABLE_INT(CRPT);
        #endif
#endif

#if (NUCODEGEN_AES_INT || NUCODEGEN_PRNG_INT)
    NVIC_EnableIRQ(CRPT_IRQn);
#endif
}
#endif //NUCODEGEN_CRYPTO_AES

#if NUCODEGEN_CRC
void CRC_Init()
{
    CRC_Open(NUCODEGEN_CRC_MODE, NUCODEGEN_CRC_ATTRIBUTE, CRC_SEED, NUCODEGEN_CRC_DATALEN);
}
#endif

#if NUCODEGEN_TIMER0
void TIMER0_Init()
{
#if (NUCODEGEN_TIMER0_FUNC == NUCODEGEN_TIMER0_FUNC_TIMER)
        TIMER_Open(TIMER0, TIMER0_MODE, TIMER0_FREQ);

#if (TIMER0_MODE == TIMER_TOGGLE_MODE)
        TIMER_SELECT_TOUT_PIN(TIMER0, NUCODEGEN_TIMER0_TOUT_PIN);
#endif

#if NUCODEGEN_TIMER0_VALUE
        // Set value will change frequency
        TIMER_SET_PRESCALE_VALUE(TIMER0, TIMER0_PRESCALE_VALUE);
        TIMER_SET_CMP_VALUE(TIMER0, TIMER0_CMP_VALUE);
#endif

#if NUCODEGEN_TIMER0_EVENT_CNT
        TIMER_EnableEventCounter(TIMER0, NUCODEGEN_TIMER0_COUNTER_PHASE);
        #if NUCODEGEN_TIMER0_EVENT_CNTDB
        TIMER_EnableEventCounterDebounce(TIMER0);
        #endif
#endif

#if NUCODEGEN_TIMER0_CAP
        #if (TIMER0_CAP_SRC == TIMER_CAPTURE_FROM_EXTERNAL)
        TIMER_CaptureSelect(TIMER0, TIMER0_CAP_SRC);
        #else
        TIMER_CaptureSelect(TIMER0, TIMER_CAPTURE_FROM_INTERNAL);
        // Set capture source from internal
        TIMER0->EXTCTL &= ~TIMER_EXTCTL_INTERCAPSEL_Msk;
        TIMER0->EXTCTL |= TIMER0_CAP_SRC;
        #endif
        // Configure Timer capture mode, capture edge
        TIMER_EnableCapture(TIMER0, NUCODEGEN_TIMER0_CAP_MODE, NUCODEGEN_TIMER0_CAP_EDGE);

        #if NUCODEGEN_TIMER0_CAPDB
        TIMER_EnableCaptureDebounce(TIMER0);
        #endif

        #if NUCODEGEN_TIMER0_CAP_INT
        // Enable timer capture interrupt
        TIMER_EnableCaptureInt(TIMER0);
        #endif
#endif

#if NUCODEGEN_TIMER0_WAKEUP
        TIMER_EnableWakeup(TIMER0);
#endif

#if NUCODEGEN_TIMER0_INT
        // Enable timer time-out interrupt
        TIMER_EnableInt(TIMER0);
#endif

#if NUCODEGEN_TIMER0_TRG
        TIMER_SetTriggerSource(TIMER0, NUCODEGEN_TIMER0_TRG_SRC);
        TIMER_SetTriggerTarget(TIMER0, NUCODEGEN_TIMER0_TRG_TARGET);
#endif

#if (NUCODEGEN_TIMER0_INT || NUCODEGEN_TIMER0_CAP_INT)
        NVIC_EnableIRQ(TMR0_IRQn);
#endif
#endif //(NUCODEGEN_TIMER0_FUNC == TIMER0_FUNC_TIMER)

#if (NUCODEGEN_TIMER0_FUNC == NUCODEGEN_TIMER0_FUNC_PWM)
        /* Change Timer to PWM counter mode */
        TPWM_ENABLE_PWM_MODE(TIMER0);

#if (NUCODEGEN_TPWM0_CONFIG == NUCODEGEN_TPWM0_CONFIG_FREQ_DUTY)
        /* Set Timer PWM output frequency, duty% */
        TPWM_ConfigOutputFreqAndDuty(TIMER0, TPWM0_FREQ, TPWM0_DUTY);
#endif

#if (NUCODEGEN_TPWM0_CONFIG == NUCODEGEN_TPWM0_CONFIG_VALUE)
        // Set value will change frequency and duty
        TPWM_SET_PRESCALER(TIMER0, TPWM0_PRESCALE_VALUE);
        TPWM_SET_PERIOD(TIMER0, TPWM0_PERIOD_VALUE);
        TPWM_SET_CMPDAT(TIMER0, TPWM0_CMP_VALUE);
#endif

#if NUCODEGEN_TPWM0_OUTPUT
        /* Enable output of PWM_CH0 */
        TPWM_ENABLE_OUTPUT(TIMER0, TPWM_CH0);
        TPWM_SELECT_TOUT_PIN(TIMER0, NUCODEGEN_TPWM0_TOUT_PIN);
        #if NUCODEGEN_TPWM0_OUT_INV
        TPWM_SET_OUTPUT_INVERSE(TIMER0, TPWM_CH0);
        #endif
#endif

#if NUCODEGEN_TPWM0_WAKEUP
        TPWM_EnableWakeup(TIMER0);
#endif

#if NUCODEGEN_TPWM0_PERIOD_INT
        /* Enable period interrupt */
        TPWM_ENABLE_PERIOD_INT(TIMER0);
#endif

#if NUCODEGEN_TPWM0_CMP_UP_INT
        /* Enable compare up interrupt */
        TPWM_ENABLE_CMP_UP_INT(TIMER0);
#endif

#if NUCODEGEN_TPWM0_TRG
        TPWM_EnableTrigger(TIMER0, NUCODEGEN_TPWM0_TRG_TARGET, NUCODEGEN_TPWM0_TRG_SRC);
#endif

#if (NUCODEGEN_TPWM0_PERIOD_INT || NUCODEGEN_TPWM0_CMP_UP_INT)
        NVIC_EnableIRQ(TMR0_IRQn);
#endif
#endif //(NUCODEGEN_TIMER0_FUNC == TIMER0_FUNC_PWM)
}
#endif //NUCODEGEN_TIMER0

#if NUCODEGEN_TIMER1
void TIMER1_Init()
{
#if (NUCODEGEN_TIMER1_FUNC == NUCODEGEN_TIMER1_FUNC_TIMER)
        TIMER_Open(TIMER1, TIMER1_MODE, TIMER1_FREQ);

#if (TIMER1_MODE == TIMER_TOGGLE_MODE)
        TIMER_SELECT_TOUT_PIN(TIMER1, NUCODEGEN_TIMER1_TOUT_PIN);
#endif

#if NUCODEGEN_TIMER1_VALUE
        // Set value will change frequency
        TIMER_SET_PRESCALE_VALUE(TIMER1, TIMER1_PRESCALE_VALUE);
        TIMER_SET_CMP_VALUE(TIMER1, TIMER1_CMP_VALUE);
#endif

#if NUCODEGEN_TIMER1_EVENT_CNT
        TIMER_EnableEventCounter(TIMER1, NUCODEGEN_TIMER1_COUNTER_PHASE);
        #if NUCODEGEN_TIMER1_EVENT_CNTDB
        TIMER_EnableEventCounterDebounce(TIMER1);
        #endif
#endif

#if NUCODEGEN_TIMER1_CAP
        #if (TIMER1_CAP_SRC == TIMER_CAPTURE_FROM_EXTERNAL)
        TIMER_CaptureSelect(TIMER1, TIMER1_CAP_SRC);
        #else
        TIMER_CaptureSelect(TIMER1, TIMER_CAPTURE_FROM_INTERNAL);
        // Set capture source from internal
        TIMER1->EXTCTL &= ~TIMER_EXTCTL_INTERCAPSEL_Msk;
        TIMER1->EXTCTL |= TIMER1_CAP_SRC;
        #endif
        // Configure Timer capture mode, capture edge
        TIMER_EnableCapture(TIMER1, NUCODEGEN_TIMER1_CAP_MODE, NUCODEGEN_TIMER1_CAP_EDGE);

        #if NUCODEGEN_TIMER1_CAPDB
        TIMER_EnableCaptureDebounce(TIMER1);
        #endif

        #if NUCODEGEN_TIMER1_CAP_INT
        // Enable timer capture interrupt
        TIMER_EnableCaptureInt(TIMER1);
        #endif
#endif

#if NUCODEGEN_TIMER1_WAKEUP
        TIMER_EnableWakeup(TIMER1);
#endif

#if NUCODEGEN_TIMER1_INT
        // Enable timer time-out interrupt
        TIMER_EnableInt(TIMER1);
#endif

#if NUCODEGEN_TIMER1_TRG
        TIMER_SetTriggerSource(TIMER1, NUCODEGEN_TIMER1_TRG_SRC);
        TIMER_SetTriggerTarget(TIMER1, NUCODEGEN_TIMER1_TRG_TARGET);
#endif

#if (NUCODEGEN_TIMER1_INT || NUCODEGEN_TIMER1_CAP_INT)
        NVIC_EnableIRQ(TMR1_IRQn);
#endif
#endif //(NUCODEGEN_TIMER1_FUNC == TIMER1_FUNC_TIMER)

#if (NUCODEGEN_TIMER1_FUNC == NUCODEGEN_TIMER1_FUNC_PWM)
        /* Change Timer to PWM counter mode */
        TPWM_ENABLE_PWM_MODE(TIMER1);

#if (NUCODEGEN_TPWM1_CONFIG == NUCODEGEN_TPWM1_CONFIG_FREQ_DUTY)
        /* Set Timer PWM output frequency, duty% */
        TPWM_ConfigOutputFreqAndDuty(TIMER1, TPWM1_FREQ, TPWM1_DUTY);
#endif

#if (NUCODEGEN_TPWM1_CONFIG == NUCODEGEN_TPWM1_CONFIG_VALUE)
        // Set value will change frequency and duty
        TPWM_SET_PRESCALER(TIMER1, TPWM1_PRESCALE_VALUE);
        TPWM_SET_PERIOD(TIMER1, TPWM1_PERIOD_VALUE);
        TPWM_SET_CMPDAT(TIMER1, TPWM1_CMP_VALUE);
#endif

#if NUCODEGEN_TPWM1_OUTPUT
        /* Enable output of PWM_CH0 */
        TPWM_ENABLE_OUTPUT(TIMER1, TPWM_CH0);
        TPWM_SELECT_TOUT_PIN(TIMER1, NUCODEGEN_TPWM1_TOUT_PIN);
        #if NUCODEGEN_TPWM1_OUT_INV
        TPWM_SET_OUTPUT_INVERSE(TIMER1, TPWM_CH0);
        #endif
#endif

#if NUCODEGEN_TPWM1_WAKEUP
        TPWM_EnableWakeup(TIMER1);
#endif

#if NUCODEGEN_TPWM1_PERIOD_INT
        /* Enable period interrupt */
        TPWM_ENABLE_PERIOD_INT(TIMER1);
#endif

#if NUCODEGEN_TPWM1_CMP_UP_INT
        /* Enable compare up interrupt */
        TPWM_ENABLE_CMP_UP_INT(TIMER1);
#endif

#if NUCODEGEN_TPWM1_TRG
        TPWM_EnableTrigger(TIMER1, NUCODEGEN_TPWM1_TRG_TARGET, NUCODEGEN_TPWM1_TRG_SRC);
#endif

#if (NUCODEGEN_TPWM1_PERIOD_INT || NUCODEGEN_TPWM1_CMP_UP_INT)
        NVIC_EnableIRQ(TMR1_IRQn);
#endif
#endif //(NUCODEGEN_TIMER1_FUNC == TIMER1_FUNC_PWM)
}
#endif //NUCODEGEN_TIMER1

#if NUCODEGEN_TIMER2
void TIMER2_Init()
{
#if (NUCODEGEN_TIMER2_FUNC == NUCODEGEN_TIMER2_FUNC_TIMER)
        TIMER_Open(TIMER2, TIMER2_MODE, TIMER2_FREQ);

#if (TIMER2_MODE == TIMER_TOGGLE_MODE)
        TIMER_SELECT_TOUT_PIN(TIMER2, NUCODEGEN_TIMER2_TOUT_PIN);
#endif

#if NUCODEGEN_TIMER2_VALUE
        // Set value will change frequency
        TIMER_SET_PRESCALE_VALUE(TIMER2, TIMER2_PRESCALE_VALUE);
        TIMER_SET_CMP_VALUE(TIMER2, TIMER2_CMP_VALUE);
#endif

#if NUCODEGEN_TIMER2_EVENT_CNT
        TIMER_EnableEventCounter(TIMER2, NUCODEGEN_TIMER2_COUNTER_PHASE);
        #if NUCODEGEN_TIMER2_EVENT_CNTDB
        TIMER_EnableEventCounterDebounce(TIMER2);
        #endif
#endif

#if NUCODEGEN_TIMER2_CAP
        #if (TIMER2_CAP_SRC == TIMER_CAPTURE_FROM_EXTERNAL)
        TIMER_CaptureSelect(TIMER2, TIMER2_CAP_SRC);
        #else
        TIMER_CaptureSelect(TIMER2, TIMER_CAPTURE_FROM_INTERNAL);
        // Set capture source from internal
        TIMER2->EXTCTL &= ~TIMER_EXTCTL_INTERCAPSEL_Msk;
        TIMER2->EXTCTL |= TIMER2_CAP_SRC;
        #endif
        // Configure Timer capture mode, capture edge
        TIMER_EnableCapture(TIMER2, NUCODEGEN_TIMER2_CAP_MODE, NUCODEGEN_TIMER2_CAP_EDGE);

        #if NUCODEGEN_TIMER2_CAPDB
        TIMER_EnableCaptureDebounce(TIMER2);
        #endif

        #if NUCODEGEN_TIMER2_CAP_INT
        // Enable timer capture interrupt
        TIMER_EnableCaptureInt(TIMER2);
        #endif
#endif

#if NUCODEGEN_TIMER2_WAKEUP
        TIMER_EnableWakeup(TIMER2);
#endif

#if NUCODEGEN_TIMER2_INT
        // Enable timer time-out interrupt
        TIMER_EnableInt(TIMER2);
#endif

#if NUCODEGEN_TIMER2_TRG
        TIMER_SetTriggerSource(TIMER2, NUCODEGEN_TIMER2_TRG_SRC);
        TIMER_SetTriggerTarget(TIMER2, NUCODEGEN_TIMER2_TRG_TARGET);
#endif

#if (NUCODEGEN_TIMER2_INT || NUCODEGEN_TIMER2_CAP_INT)
        NVIC_EnableIRQ(TMR2_IRQn);
#endif
#endif //(NUCODEGEN_TIMER2_FUNC == TIMER2_FUNC_TIMER)

#if (NUCODEGEN_TIMER2_FUNC == NUCODEGEN_TIMER2_FUNC_PWM)
        /* Change Timer to PWM counter mode */
        TPWM_ENABLE_PWM_MODE(TIMER2);

#if (NUCODEGEN_TPWM2_CONFIG == NUCODEGEN_TPWM2_CONFIG_FREQ_DUTY)
        /* Set Timer PWM output frequency, duty% */
        TPWM_ConfigOutputFreqAndDuty(TIMER2, TPWM2_FREQ, TPWM2_DUTY);
#endif

#if (NUCODEGEN_TPWM2_CONFIG == NUCODEGEN_TPWM2_CONFIG_VALUE)
        // Set value will change frequency and duty
        TPWM_SET_PRESCALER(TIMER2, TPWM2_PRESCALE_VALUE);
        TPWM_SET_PERIOD(TIMER2, TPWM2_PERIOD_VALUE);
        TPWM_SET_CMPDAT(TIMER2, TPWM2_CMP_VALUE);
#endif

#if NUCODEGEN_TPWM2_OUTPUT
        /* Enable output of PWM_CH0 */
        TPWM_ENABLE_OUTPUT(TIMER2, TPWM_CH0);
        TPWM_SELECT_TOUT_PIN(TIMER2, NUCODEGEN_TPWM2_TOUT_PIN);
        #if NUCODEGEN_TPWM2_OUT_INV
        TPWM_SET_OUTPUT_INVERSE(TIMER2, TPWM_CH0);
        #endif
#endif

#if NUCODEGEN_TPWM2_WAKEUP
        TPWM_EnableWakeup(TIMER2);
#endif

#if NUCODEGEN_TPWM2_PERIOD_INT
        /* Enable period interrupt */
        TPWM_ENABLE_PERIOD_INT(TIMER2);
#endif

#if NUCODEGEN_TPWM2_CMP_UP_INT
        /* Enable compare up interrupt */
        TPWM_ENABLE_CMP_UP_INT(TIMER2);
#endif

#if NUCODEGEN_TPWM2_TRG
        TPWM_EnableTrigger(TIMER2, NUCODEGEN_TPWM2_TRG_TARGET, NUCODEGEN_TPWM2_TRG_SRC);
#endif

#if (NUCODEGEN_TPWM2_PERIOD_INT || NUCODEGEN_TPWM2_CMP_UP_INT)
        NVIC_EnableIRQ(TMR2_IRQn);
#endif
#endif //(NUCODEGEN_TIMER2_FUNC == TIMER2_FUNC_PWM)
}
#endif //NUCODEGEN_TIMER2

#if NUCODEGEN_TIMER3
void TIMER3_Init()
{
#if (NUCODEGEN_TIMER3_FUNC == NUCODEGEN_TIMER3_FUNC_TIMER)
        TIMER_Open(TIMER3, TIMER3_MODE, TIMER3_FREQ);

#if (TIMER3_MODE == TIMER_TOGGLE_MODE)
        TIMER_SELECT_TOUT_PIN(TIMER3, NUCODEGEN_TIMER3_TOUT_PIN);
#endif

#if NUCODEGEN_TIMER3_VALUE
        // Set value will change frequency
        TIMER_SET_PRESCALE_VALUE(TIMER3, TIMER3_PRESCALE_VALUE);
        TIMER_SET_CMP_VALUE(TIMER3, TIMER3_CMP_VALUE);
#endif

#if NUCODEGEN_TIMER3_EVENT_CNT
        TIMER_EnableEventCounter(TIMER3, NUCODEGEN_TIMER3_COUNTER_PHASE);
        #if NUCODEGEN_TIMER3_EVENT_CNTDB
        TIMER_EnableEventCounterDebounce(TIMER3);
        #endif
#endif

#if NUCODEGEN_TIMER3_CAP
        #if (TIMER3_CAP_SRC == TIMER_CAPTURE_FROM_EXTERNAL)
        TIMER_CaptureSelect(TIMER3, TIMER3_CAP_SRC);
        #else
        TIMER_CaptureSelect(TIMER3, TIMER_CAPTURE_FROM_INTERNAL);
        // Set capture source from internal
        TIMER3->EXTCTL &= ~TIMER_EXTCTL_INTERCAPSEL_Msk;
        TIMER3->EXTCTL |= TIMER3_CAP_SRC;
        #endif
        // Configure Timer capture mode, capture edge
        TIMER_EnableCapture(TIMER3, NUCODEGEN_TIMER3_CAP_MODE, NUCODEGEN_TIMER3_CAP_EDGE);

        #if NUCODEGEN_TIMER3_CAPDB
        TIMER_EnableCaptureDebounce(TIMER3);
        #endif

        #if NUCODEGEN_TIMER3_CAP_INT
        // Enable timer capture interrupt
        TIMER_EnableCaptureInt(TIMER3);
        #endif
#endif

#if NUCODEGEN_TIMER3_WAKEUP
        TIMER_EnableWakeup(TIMER3);
#endif

#if NUCODEGEN_TIMER3_INT
        // Enable timer time-out interrupt
        TIMER_EnableInt(TIMER3);
#endif

#if NUCODEGEN_TIMER3_TRG
        TIMER_SetTriggerSource(TIMER3, NUCODEGEN_TIMER3_TRG_SRC);
        TIMER_SetTriggerTarget(TIMER3, NUCODEGEN_TIMER3_TRG_TARGET);
#endif

#if (NUCODEGEN_TIMER3_INT || NUCODEGEN_TIMER3_CAP_INT)
        NVIC_EnableIRQ(TMR3_IRQn);
#endif
#endif //(NUCODEGEN_TIMER3_FUNC == TIMER3_FUNC_TIMER)

#if (NUCODEGEN_TIMER3_FUNC == NUCODEGEN_TIMER3_FUNC_PWM)
        /* Change Timer to PWM counter mode */
        TPWM_ENABLE_PWM_MODE(TIMER3);

#if (NUCODEGEN_TPWM3_CONFIG == NUCODEGEN_TPWM3_CONFIG_FREQ_DUTY)
        /* Set Timer PWM output frequency, duty% */
        TPWM_ConfigOutputFreqAndDuty(TIMER3, TPWM3_FREQ, TPWM3_DUTY);
#endif

#if (NUCODEGEN_TPWM3_CONFIG == NUCODEGEN_TPWM3_CONFIG_VALUE)
        // Set value will change frequency and duty
        TPWM_SET_PRESCALER(TIMER3, TPWM3_PRESCALE_VALUE);
        TPWM_SET_PERIOD(TIMER3, TPWM3_PERIOD_VALUE);
        TPWM_SET_CMPDAT(TIMER3, TPWM3_CMP_VALUE);
#endif

#if NUCODEGEN_TPWM3_OUTPUT
        /* Enable output of PWM_CH0 */
        TPWM_ENABLE_OUTPUT(TIMER3, TPWM_CH0);
        TPWM_SELECT_TOUT_PIN(TIMER3, NUCODEGEN_TPWM3_TOUT_PIN);
        #if NUCODEGEN_TPWM3_OUT_INV
        TPWM_SET_OUTPUT_INVERSE(TIMER3, TPWM_CH0);
        #endif
#endif

#if NUCODEGEN_TPWM3_WAKEUP
        TPWM_EnableWakeup(TIMER3);
#endif

#if NUCODEGEN_TPWM3_PERIOD_INT
        /* Enable period interrupt */
        TPWM_ENABLE_PERIOD_INT(TIMER3);
#endif

#if NUCODEGEN_TPWM3_CMP_UP_INT
        /* Enable compare up interrupt */
        TPWM_ENABLE_CMP_UP_INT(TIMER3);
#endif

#if NUCODEGEN_TPWM3_TRG
        TPWM_EnableTrigger(TIMER3, NUCODEGEN_TPWM3_TRG_TARGET, NUCODEGEN_TPWM3_TRG_SRC);
#endif

#if (NUCODEGEN_TPWM3_PERIOD_INT || NUCODEGEN_TPWM3_CMP_UP_INT)
        NVIC_EnableIRQ(TMR3_IRQn);
#endif
#endif //(NUCODEGEN_TIMER3_FUNC == TIMER3_FUNC_PWM)
}
#endif //NUCODEGEN_TIMER3

#if NUCODEGEN_UART0

#if (NUCODEGEN_UART0_FUNCSEL == NUCODEGEN_UART0_FUNCSEL_LIN)

#if ((NUCODEGEN_UART0_LINCTL_HSEL == NUCODEGEN_UART0_LINCTL_HSEL_BREAK_SYNC) || (NUCODEGEN_UART0_LINCTL_HSEL == NUCODEGEN_UART0_LINCTL_HSEL_BREAK))
volatile int32_t g_i32Pointer;
uint8_t g_au8SendData[12] ;
uint8_t g_au8RecvData[12] ;


/*---------------------------------------------------------------------------------------------------------*/
/* Compute Parity Value                                                                                    */
/* u32id = Frame ID                                                                                        */
/*---------------------------------------------------------------------------------------------------------*/
uint8_t GetParityValue(uint32_t u32Id)
{
    uint32_t u32Res = 0, au32ID[6], au32ParityBit[2], u32Mask = 0;

    for (u32Mask = 0; u32Mask < 6; u32Mask++)
        au32ID[u32Mask] = (u32Id & (1 << u32Mask)) >> u32Mask;

    au32ParityBit[0] = (au32ID[0] + au32ID[1] + au32ID[2] + au32ID[4]) % 2;
    au32ParityBit[1] = (!((au32ID[1] + au32ID[3] + au32ID[4] + au32ID[5]) % 2));

    u32Res = u32Id + (au32ParityBit[0] << 6) + (au32ParityBit[1] << 7);
    return u32Res;
}

#endif

#endif


void UART0_Init()
{
#if (NUCODEGEN_UART0_FUNCSEL == NUCODEGEN_UART0_FUNCSEL_UART)
    /* Configure UART0 and set UART0 baud rate */
    UART_Open(UART0, UART0_BAUD);

#if NUCODEGEN_UART0_LINE_CONFIG
    /* Set Data Format*/
    UART_SetLine_Config(UART0, 0, NUCODEGEN_UART0_WORD_LEN, NUCODEGEN_UART0_PARITY, NUCODEGEN_UART0_STOP_BIT);

#endif

#if NUCODEGEN_UART0_AUTOFLOW
    /* Enable RTS and CTS auto flow control */
    UART_EnableFlowCtrl(UART0);
    /* Auto-flow Control Trigger level */
    UART0->FIFO = (UART0->FIFO &~ UART_FIFO_RTSTRGLV_Msk) | NUCODEGEN_UART0_FIFO_RTSTRGLV;

   #if (NUCODEGEN_UART0_RTSACTLV_LOW)
    /* nRTS pin output is low level active */
    UART0->MODEM |= UART_MODEM_RTSACTLV_Msk;
   #else
    /* nRTS pin output is high level active */
    UART0->MODEM &= ~UART_MODEM_RTSACTLV_Msk;
   #endif

   #if (NUCODEGEN_UART0_CTSACTLV_LOW)
    /* nCTS pin input is low level active */
    UART0->MODEMSTS |= UART_MODEMSTS_CTSACTLV_Msk;
   #else
    /* nCTS pin input is high level active */
    UART0->MODEMSTS &= ~UART_MODEMSTS_CTSACTLV_Msk;
   #endif



#endif

#if NUCODEGEN_UART0_INTEN
    /* Enable UART0 Interrupt */
    UART_EnableInt(UART0, (NUCODEGEN_UART0_INT_MASK));

#endif


#elif (NUCODEGEN_UART0_FUNCSEL == NUCODEGEN_UART0_FUNCSEL_LIN)
    /* Configure UART0 and set UART0 baud rate */
    UART_Open(UART0, UART0_LIN_BAUD);
    /* Select LIN function mode */
    UART0->FUNCSEL = UART_FUNCSEL_LIN;

#if(NUCODEGEN_UART0_LIN_MODE == NUCODEGEN_UART0_LIN_MASTER_MODE)

   #if (NUCODEGEN_UART0_LINCTL_HSEL == NUCODEGEN_UART0_LINCTL_HSEL_BREAK_SYNC_ID)
    /* Set LIN 1. PID as UART0_LINCTL_PID [UART_LINCTL_PID(UART0_LINCTL_PID)]
               2. Header select as includes "break field", "sync field" and "frame ID field".[UART_LINCTL_HSEL_BREAK_SYNC_ID]
               3. Break/Sync Delimiter Length as UART0_LINCTL_BSL bit time [UART_LINCTL_BSL(UART0_LINCTL_BSL)]
               4. Break Field Length as UART0_LINCTL_BRKFL bit time [UART_LINCTL_BRKFL(UART0_LINCTL_BRKFL)]
               5. ID Parity Enable. Hardware will calculate and fill P0/P1 automatically  [UART_LINCTL_IDPEN_Msk]
    */
     UART0->LINCTL = UART_LINCTL_PID(UART0_LINCTL_PID) | UART_LINCTL_HSEL_BREAK_SYNC_ID |
                     UART_LINCTL_BSL(UART0_LINCTL_BSL) | UART_LINCTL_BRKFL(UART0_LINCTL_BRKFL) | UART_LINCTL_IDPEN_Msk;

  #if NUCODEGEN_UART0_LINCTL_SENDH
     /* LIN TX Send Header Enable */
     UART0->LINCTL |= UART_LINCTL_SENDH_Msk;
     /* Wait until break field, sync field and ID field transfer completed */
     while ((UART0->LINCTL & UART_LINCTL_SENDH_Msk) == UART_LINCTL_SENDH_Msk);
  #endif


#elif (NUCODEGEN_UART0_LINCTL_HSEL == NUCODEGEN_UART0_LINCTL_HSEL_BREAK_SYNC)
      g_i32Pointer = 0;
     /* Set LIN 1. Header select as includes "break field" and "sync field".[UART_LINCTL_HSEL_BREAK_SYNC]
                2. Break/Sync Delimiter Length as 1 bit time [UART_LINCTL_BSL(1)]
                3. Break Field Length as 12 bit time [UART_LINCTL_BRKFL(12)]
    */
      UART0->LINCTL = UART_LINCTL_HSEL_BREAK_SYNC |UART_LINCTL_BSL(UART0_LINCTL_BSL)
                     | UART_LINCTL_BRKFL(UART0_LINCTL_BRKFL);

  #if NUCODEGEN_UART0_LINCTL_SENDH
     /* LIN TX Send Header Enable */
      UART0->LINCTL |= UART_LINCTL_SENDH_Msk;

     /* Wait until break field and sync field transfer completed */
      while ((UART0->LINCTL & UART_LINCTL_SENDH_Msk) == UART_LINCTL_SENDH_Msk);

     /*Send ID field, g_u8SendData[0] is ID+parity field */
      g_au8SendData[g_i32Pointer++] = GetParityValue(UART0_LINCTL_PID);     // ID+Parity Field
      UART0->DAT = g_au8SendData[0];
      while (!(UART0->FIFOSTS & UART_FIFOSTS_TXEMPTYF_Msk));
  #endif

#else
      g_i32Pointer = 0;
    /* Set LIN 1. Header select as includes "break field".[UART_LINCTL_HSEL_BREAK]
               2. Break/Sync Delimiter Length as 1 bit time [UART_LINCTL_BSL(1)]
               3. Break Field Length as 12 bit time [UART_LINCTL_BRKFL(12)]
    */

        UART0->LINCTL =  UART_LINCTL_HSEL_BREAK | UART_LINCTL_BSL(UART0_LINCTL_BSL) | UART_LINCTL_BRKFL(UART0_LINCTL_BRKFL);

  #if NUCODEGEN_UART0_LINCTL_SENDH
        /* LIN TX Send Header Enable */
        UART0->LINCTL |= UART_LINCTL_SENDH_Msk;

        /* Wait until break field transfer completed */
        while ((UART0->LINCTL & UART_LINCTL_SENDH_Msk) == UART_LINCTL_SENDH_Msk);

        /* Send sync field and ID field */
        g_au8SendData[g_i32Pointer++] = 0x55 ;                   // SYNC Field
        g_au8SendData[g_i32Pointer++] = GetParityValue(UART0_LINCTL_PID);   // ID+Parity Field
        UART0->DAT = g_au8SendData[0];

        while (!(UART0->FIFOSTS & UART_FIFOSTS_TXEMPTYF_Msk));

        UART0->DAT = g_au8SendData[1];

        while (!(UART0->FIFOSTS & UART_FIFOSTS_TXEMPTYF_Msk));
  #endif

#endif
#if NUCODEGEN_UART0_LINCTL_LINRXOFF
     /*Enable the "LIN Receiver Disable" */
     UART0->LINCTL |= UART_LINCTL_LINRXOFF_Msk;

#endif
#if NUCODEGEN_UART0_LINCTL_BITERREN
     /*Enable the LIN Bit Error Detect*/
     UART0->LINCTL |= UART_LINCTL_BITERREN_Msk;
#endif

#if NUCODEGEN_UART0_LINCTL_BRKDETEN
    /*Enable the LIN Break Detection*/
    UART0->LINCTL |= UART_LINCTL_BRKDETEN_Msk;
#endif

#else
      /* Set LIN is Slave mode */
    UART0->LINCTL |= UART_LINCTL_SLVEN_Msk;


    /* Reset Rx FIFO             */
    UART0->FIFO |= UART_FIFO_RXRST_Msk;

    /* Set LIN  1. PID as UART0_LINCTL_PID [UART_LINCTL_PID(UART0_LINCTL_PID)]
               2. Header select as includes "break field".[UART_LINCTL_HSEL_BREAK]
               3. Enabled LIN Slave Header Detection
               4. ID Parity Enable. Hardware will calculate and fill P0/P1 automatically  [UART_LINCTL_IDPEN_Msk]
               5. Enabled Mute mode
    */

    UART0->LINCTL |= (UART_LINCTL_PID(UART0_LINCTL_PID) |  UART_LINCTL_BRKFL(UART0_LINCTL_BRKFL)
                      |UART_LINCTL_IDPEN_Msk | UART_LINCTL_MUTE_Msk);



#if NUCODEGEN_UART0_LINCTL_SLVAREN
    /* Enable the LIN Slave Automatic Resynchronization Mode */
    UART0->LINCTL |= UART_LINCTL_SLVAREN_Msk;
#endif

#if NUCODEGEN_UART0_LINCTL_SLVAREN
    /* Enable the LIN Slave Divider Update Method */
    UART0->LINCTL |= UART_LINCTL_SLVDUEN_Msk;
#endif

#if NUCODEGEN_UART0_LINCTL_BRKDETEN
    /*Enable the LIN Break Detection*/
    UART0->LINCTL |= UART_LINCTL_BRKDETEN_Msk;
#endif

#if NUCODEGEN_UART0_LINCTL_SLVHDEN
    /* Enable the LIN Slave Header Detection */
    UART0->LINCTL |= UART_LINCTL_SLVHDEN_Msk;

    /* Wait to Received the Header     */
    while (!(UART0->LINSTS & UART_LINSTS_SLVHDETF_Msk)) {};
#endif

#endif

#if NUCODEGEN_UART0_LINIEN
    /* Enable UART0 Interrupt */
    UART_EnableInt(UART0, (UART_INTEN_LINIEN_Msk));

#endif


#elif (NUCODEGEN_UART0_FUNCSEL == NUCODEGEN_UART0_FUNCSEL_IrDA)
    /* Select IrDA Tx or Rx mode and set baud rate */
    UART_SelectIrDAMode(UART0, UART0_IRDA_BAUD, NUCODEGEN_UART0_IRDA_MODE);
    /* Set Data Format (only support 8 bits ,None Parity bit,1 Stop bit) */
    UART_SetLine_Config(UART0,0,UART_WORD_LEN_8,UART_PARITY_NONE,UART_STOP_BIT_1);

#if NUCODEGEN_UART0_IRDA_INTEN
    /* Enable UART0 Receive Data Available Interrupt */
    UART_EnableInt(UART0, (NUCODEGEN_UART0_IRDA_INT_MASK));

#endif

#elif (NUCODEGEN_UART0_FUNCSEL == NUCODEGEN_UART0_FUNCSEL_RS485)
    /* Configure UART0 and set UART0 baud rate */
    UART_Open(UART0, UART0_RS485_BAUD);

    /* Set Data Format*/ /* Only need parity enable whenever parity ODD/EVEN */
    UART_SetLine_Config(UART0, 0, UART_WORD_LEN_8, UART_PARITY_EVEN, UART_STOP_BIT_1);

     /* Set RTS pin active level as High level active */
    UART0->MODEM &= ~UART_MODEM_RTSACTLV_Msk;
    UART0->MODEM |= UART_RTS_IS_HIGH_LEV_ACTIVE;

#if (NUCODEGEN_UART0_RS485_MODE == NUCODEGEN_UART0_RS485_ADD_MODE)

    /* Set RS485-AAD Mode and address match is 0xC0 */
    UART_SelectRS485Mode(UART0, UART_ALTCTL_RS485AAD_Msk | UART_ALTCTL_ADDRDEN_Msk | UART_ALTCTL_RS485AUD_Msk, UART0_RS485_ADDRMV);


#else /*NUCODEGEN_UART0_RS485_NMM_MODE*/

  /* Set RX_DIS enable before set RS485-NMM mode */
    UART0->FIFO |= UART_FIFO_RXOFF_Msk;

  /* Set RS485-NMM Mode */
   UART_SelectRS485Mode(UART0, UART_ALTCTL_RS485NMM_Msk | UART_ALTCTL_ADDRDEN_Msk | UART_ALTCTL_RS485AUD_Msk, 0);

#endif

#if NUCODEGEN_UART0_RS485_INTEN
    /* Enable RS485 Interrupr*/
    UART_EnableInt(UART0, (NUCODEGEN_UART0_RS485_INT_MASK));
#endif

#elif (NUCODEGEN_UART0_FUNCSEL == NUCODEGEN_UART0_FUNCSEL_SINGLE_WIRE)
    /* Configure UART0 and set UART0 baud rate */
    UART_Open(UART0, UART0_SW_BAUD);
    /* Set Single Wire Mode */
    UART_SelectSingleWireMode(UART0);

#if NUCODEGEN_UART0_SW_INTEN
    /*Enable the Single Wire Interrupt*/
    UART_EnableInt(UART0, (NUCODEGEN_UART0_SW_INT_MASK));
#endif

#endif

#if NUCODEGEN_UART0_TOCNTEN
    /*Set the UART TimeOut count*/
    UART_SetTimeoutCnt(UART0, UART0_TOCNT);

#endif

#if  NUCODEGEN_UART0_PDMAEN
    /*Enable UART PDMA*/
    UART0->INTEN |= NUCODEGEN_UART0_PDMAEN_Msk;

#endif

#if NUCODEGEN_UART0_ABRDEN
    /* Enable auto baud rate detect function */
    UART0->ALTCTL |= UART_ALTCTL_ABRDEN_Msk;
#endif
    /* RX FIFO Interrupt Trigger Level */
    UART0->FIFO = (UART0->FIFO &~ UART_FIFO_RFITL_Msk) | NUCODEGEN_UART0_RFITL;

#if NUCODEGEN_UART0_WKCTSEN
    /* Enable UART nCTS Wake up */
   UART0->WKCTL |= UART_WKCTL_WKCTSEN_Msk;
#endif

#if NUCODEGEN_UART0_WKDATEN
    /* Enable UART Incoming Data Wake up */
    UART0->WKCTL |= UART_WKCTL_WKDATEN_Msk;
#endif

#if NUCODEGEN_UART0_WKRFRTEN
    /* Enable UART Received Data FIFO Reached Threshold Wake up */
    UART0->WKCTL |= UART_WKCTL_WKRFRTEN_Msk;
#endif

#if NUCODEGEN_UART0_WKTOUTEN
     /* Enable UART Received Data FIFO Threshold Time-out Wake up */
    UART0->WKCTL |= UART_WKCTL_WKTOUTEN_Msk;
#endif

#if NUCODEGEN_UART0_WKRS485EN
    /* Enable RS-485 Address Match (AAD Mode) Wake up */
    UART0->WKCTL |= UART_WKCTL_WKRS485EN_Msk;
#endif

#if (NUCODEGEN_UART0_INTEN || NUCODEGEN_UART0_IRDA_INTEN || NUCODEGEN_UART0_RS485_INTEN || NUCODEGEN_UART0_SW_INTEN || NUCODEGEN_UART0_LINIEN)
    /*Enable UART IRQ Handler */
    NVIC_EnableIRQ(UART0_IRQn);

#endif

}
#endif //NUCODEGEN_UART0

#if NUCODEGEN_UART1
void UART1_Init()
{
#if (NUCODEGEN_UART1_FUNCSEL == NUCODEGEN_UART1_FUNCSEL_UART)
    /* Configure UART0 and set UART0 baud rate */
    UART_Open(UART1, UART1_BAUD);

#if NUCODEGEN_UART1_LINE_CONFIG
    /* Set Data Format*/
    UART_SetLine_Config(UART1, 0, NUCODEGEN_UART1_WORD_LEN, NUCODEGEN_UART1_PARITY, NUCODEGEN_UART1_STOP_BIT);
#endif

#if NUCODEGEN_UART1_AUTOFLOW
    /* Enable RTS and CTS auto flow control */
    UART_EnableFlowCtrl(UART1);
    /* Auto-flow Control Trigger level */
    UART1->FIFO = (UART1->FIFO &~ UART_FIFO_RTSTRGLV_Msk) | NUCODEGEN_UART1_FIFO_RTSTRGLV;

  #if (NUCODEGEN_UART1_RTSACTLV_LOW)
    /* nRTS pin output is low level active */
    UART1->MODEM |= UART_MODEM_RTSACTLV_Msk;
  #else
    /* nRTS pin output is high level active */
    UART1->MODEM &= ~UART_MODEM_RTSACTLV_Msk;
  #endif

  #if (NUCODEGEN_UART1_CTSACTLV_LOW)
    /* nCTS pin input is low level active */
    UART1->MODEMSTS |= UART_MODEMSTS_CTSACTLV_Msk;
  #else
    /* nCTS pin input is high level active */
    UART1->MODEMSTS &= ~UART_MODEMSTS_CTSACTLV_Msk;
  #endif


#endif

#if NUCODEGEN_UART1_INTEN
    /* Enable UART1 Interrupt */
    UART_EnableInt(UART1, (NUCODEGEN_UART1_INT_MASK));
#endif

#elif (NUCODEGEN_UART1_FUNCSEL == NUCODEGEN_UART1_FUNCSEL_IrDA)
     /* Select IrDA Tx or Rx mode and set baud rate */
    UART_SelectIrDAMode(UART1, UART1_IRDA_BAUD, NUCODEGEN_UART1_IRDA_MODE);
    /* Set Data Format (only support 8 bits ,None Parity bit,1 Stop bit) */
    UART_SetLine_Config(UART1,0,UART_WORD_LEN_8,UART_PARITY_NONE,UART_STOP_BIT_1);

#if NUCODEGEN_UART1_IRDA_INTEN
    /* Enable UART1 IrDA Interrupt */
    UART_EnableInt(UART1, (NUCODEGEN_UART1_IRDA_INT_MASK));
#endif
#elif (NUCODEGEN_UART1_FUNCSEL == NUCODEGEN_UART1_FUNCSEL_RS485)
    /* Configure UART1 and set UART1 baud rate */
    UART_Open(UART1, UART1_RS485_BAUD);

    /* Set Data Format*/ /* Only need parity enable whenever parity ODD/EVEN */
    UART_SetLine_Config(UART1,0, UART_WORD_LEN_8, UART_PARITY_EVEN, UART_STOP_BIT_1);

     /* Set RTS pin active level as High level active */
    UART1->MODEM &= ~UART_MODEM_RTSACTLV_Msk;
    UART1->MODEM |= UART_RTS_IS_HIGH_LEV_ACTIVE;

#if (NUCODEGEN_UART0_RS485_MODE == NUCODEGEN_UART0_RS485_ADD_MODE)

    /* Set RS485-AAD Mode and address match is 0xC0 */
    UART_SelectRS485Mode(UART1, UART_ALTCTL_RS485AAD_Msk | UART_ALTCTL_ADDRDEN_Msk | UART_ALTCTL_RS485AUD_Msk, UART1_RS485_ADDRMV);


#else /*NUCODEGEN_UART0_RS485_NMM_MODE*/

  /* Set RX_DIS enable before set RS485-NMM mode */
    UART1->FIFO |= UART_FIFO_RXOFF_Msk;

  /* Set RS485-NMM Mode */

   UART_SelectRS485Mode(UART1, UART_ALTCTL_RS485NMM_Msk | UART_ALTCTL_ADDRDEN_Msk | UART_ALTCTL_RS485AUD_Msk, 0);

#endif
#if NUCODEGEN_UART1_RS485_INTEN
     /* Enable UART1 RS485 Interrupt */
    UART_EnableInt(UART1, (NUCODEGEN_UART1_RS485_INT_MASK));
#endif

#elif (NUCODEGEN_UART1_FUNCSEL == NUCODEGEN_UART1_FUNCSEL_SINGLE_WIRE)
   /* Configure UART1 and set UART1 baud rate */
   UART_Open(UART1, UART1_SW_BAUD);
   /* Set Single Wire Mode */
   UART_SelectSingleWireMode(UART1);

#if NUCODEGEN_UART1_SW_INTEN
    /*Enable the Single Wire Interrupt*/
    UART_EnableInt(UART1, (NUCODEGEN_UART1_SW_INT_MASK));
#endif
#endif

#if NUCODEGEN_UART1_TOCNTEN
      /*Set the UART TimeOut count*/
     UART_SetTimeoutCnt(UART1, UART1_TOCNT);
#endif

#if  NUCODEGEN_UART1_PDMAEN
     /*Enable UART PDMA*/
     UART1->INTEN |= NUCODEGEN_UART1_PDMAEN_Msk;
#endif

#if NUCODEGEN_UART1_ABRDEN
    /* Enable auto baud rate detect function */
    UART1->ALTCTL |= UART_ALTCTL_ABRDEN_Msk;
#endif
    /* RX FIFO Interrupt Trigger Level */
    UART1->FIFO = (UART1->FIFO &~ UART_FIFO_RFITL_Msk) | NUCODEGEN_UART1_RFITL;

#if NUCODEGEN_UART1_WKCTSEN
    /* Enable UART nCTS Wake up */
    UART1->WKCTL |= UART_WKCTL_WKCTSEN_Msk;
#endif

#if NUCODEGEN_UART1_WKDATEN
    /* Enable UART Incoming Data Wake up */
    UART1->WKCTL |= UART_WKCTL_WKDATEN_Msk;
#endif

#if NUCODEGEN_UART1_WKRFRTEN
    /* Enable UART Received Data FIFO Reached Threshold Wake up */
    UART1->WKCTL |= UART_WKCTL_WKRFRTEN_Msk;
#endif

#if NUCODEGEN_UART1_WKTOUTEN
    /* Enable UART Received Data FIFO Threshold Time-out Wake up */
    UART1->WKCTL |= UART_WKCTL_WKTOUTEN_Msk;
#endif

#if NUCODEGEN_UART1_WKRS485EN
    /* Enable RS-485 Address Match (AAD Mode) Wake up */
    UART1->WKCTL |= UART_WKCTL_WKRS485EN_Msk;
#endif

#if (NUCODEGEN_UART1_INTEN || NUCODEGEN_UART1_IRDA_INTEN || NUCODEGEN_UART1_RS485_INTEN || NUCODEGEN_UART1_SW_INTEN )
    /*Enable UART1 IRQ Handler */
    NVIC_EnableIRQ(UART1_IRQn);
#endif

}
#endif //NUCODEGEN_UART1

#if NUCODEGEN_UART2
void UART2_Init()
{
#if (NUCODEGEN_UART2_FUNCSEL == NUCODEGEN_UART2_FUNCSEL_UART)
    /* Configure UART2 and set UART2 baud rate */
    UART_Open(UART2, UART2_BAUD);

#if NUCODEGEN_UART2_LINE_CONFIG
    /* Set Data Format*/
    UART_SetLine_Config(UART2, 0, NUCODEGEN_UART2_WORD_LEN, NUCODEGEN_UART2_PARITY, NUCODEGEN_UART2_STOP_BIT);
#endif


#if NUCODEGEN_UART2_AUTOFLOW
    /* Enable RTS and CTS auto flow control */
    UART_EnableFlowCtrl(UART2);
    /* Auto-flow Control Trigger level */
    UART2->FIFO = (UART2->FIFO &~ UART_FIFO_RTSTRGLV_Msk) | NUCODEGEN_UART2_FIFO_RTSTRGLV;

  #if (NUCODEGEN_UART2_RTSACTLV_LOW)
    /* nRTS pin output is low level active */
    UART2->MODEM |= UART_MODEM_RTSACTLV_Msk;
  #else
    /* nRTS pin output is high level active */
    UART2->MODEM &= ~UART_MODEM_RTSACTLV_Msk;
  #endif

  #if (NUCODEGEN_UART2_CTSACTLV_LOW)
    /* nCTS pin input is low level active */
    UART2->MODEMSTS |= UART_MODEMSTS_CTSACTLV_Msk;
  #else
    /* nCTS pin input is high level active */
    UART2->MODEMSTS &= ~UART_MODEMSTS_CTSACTLV_Msk;
  #endif

#endif

#if NUCODEGEN_UART2_INTEN
    /* Enable UART1 Interrupt */
    UART_EnableInt(UART2, (NUCODEGEN_UART2_INT_MASK));
#endif

#elif (NUCODEGEN_UART2_FUNCSEL == NUCODEGEN_UART2_FUNCSEL_IrDA)
     /* Select IrDA Tx or Rx mode and set baud rate */
    UART_SelectIrDAMode(UART2, UART2_IRDA_BAUD, NUCODEGEN_UART2_IRDA_MODE);
    /* Set Data Format (only support 8 bits ,None Parity bit,1 Stop bit) */
    UART_SetLine_Config(UART2,0,UART_WORD_LEN_8,UART_PARITY_NONE,UART_STOP_BIT_1);

#if NUCODEGEN_UART2_IRDA_INTEN
    /* Enable UART2 IrDA Interrupt */
    UART_EnableInt(UART2, (NUCODEGEN_UART2_IRDA_INT_MASK));
#endif
#elif (NUCODEGEN_UART2_FUNCSEL == NUCODEGEN_UART2_FUNCSEL_RS485)
    /* Configure UART2 and set UART2 baud rate */
    UART_Open(UART2, UART2_RS485_BAUD);

    /* Set Data Format*/ /* Only need parity enable whenever parity ODD/EVEN */
    UART_SetLine_Config(UART2, 0, UART_WORD_LEN_8, UART_PARITY_EVEN, UART_STOP_BIT_1);

     /* Set RTS pin active level as High level active */
    UART2->MODEM &= ~UART_MODEM_RTSACTLV_Msk;
    UART2->MODEM |= UART_RTS_IS_HIGH_LEV_ACTIVE;

#if (NUCODEGEN_UART2_RS485_MODE == NUCODEGEN_UART2_RS485_ADD_MODE)

    /* Set RS485-AAD Mode and address match is UART0_RS485_ADDRMV */
    UART_SelectRS485Mode(UART2, UART_ALTCTL_RS485AAD_Msk | UART_ALTCTL_ADDRDEN_Msk | UART_ALTCTL_RS485AUD_Msk, UART2_RS485_ADDRMV);


#else /*NUCODEGEN_UART2_RS485_NMM_MODE*/

  /* Set RX_DIS enable before set RS485-NMM mode */
    UART2->FIFO |= UART_FIFO_RXOFF_Msk;

  /* Set RS485-NMM Mode */

   UART_SelectRS485Mode(UART2, UART_ALTCTL_RS485NMM_Msk | UART_ALTCTL_ADDRDEN_Msk | UART_ALTCTL_RS485AUD_Msk, 0);

#endif

#if NUCODEGEN_UART2_RS485_INTEN
    /*Enable RS485 Interrupt*/
    UART_EnableInt(UART2, (NUCODEGEN_UART2_RS485_INT_MASK));
#endif
#elif (NUCODEGEN_UART2_FUNCSEL == NUCODEGEN_UART2_FUNCSEL_SINGLE_WIRE)
    /* Configure UART2 and set UART2 baud rate */
    UART_Open(UART2, UART2_SW_BAUD);
    /* Set Single Wire Mode */
    UART_SelectSingleWireMode(UART2);

#if NUCODEGEN_UART2_SW_INTEN
    /*Enable the Single Wire Interrupt*/
    UART_EnableInt(UART2, (NUCODEGEN_UART2_SW_INT_MASK));
#endif
#endif

#if NUCODEGEN_UART2_TOCNTEN
    /*Set the UART TimeOut count*/
     UART_SetTimeoutCnt(UART2, UART2_TOCNT);
#endif

#if  NUCODEGEN_UART2_PDMAEN
    /*Enable UART PDMA*/
     UART2->INTEN |= NUCODEGEN_UART2_PDMAEN_Msk;
#endif


#if NUCODEGEN_UART2_ABRDEN
    /* Enable auto baud rate detect function */
    UART2->ALTCTL |= UART_ALTCTL_ABRDEN_Msk;
#endif
   /* RX FIFO Interrupt TriggeLevel */
    UART2->FIFO = (UART2->FIFO &~ UART_FIFO_RFITL_Msk) | NUCODEGEN_UART2_RFITL;

#if NUCODEGEN_UART2_WKCTSEN
    /* Enable UART nCTS Wake up */
    UART2->WKCTL |= UART_WKCTL_WKCTSEN_Msk;
#endif

#if NUCODEGEN_UART2_WKDATEN
    /* Enable UART Incoming Data Wake up */
    UART2->WKCTL |= UART_WKCTL_WKDATEN_Msk;
#endif

#if NUCODEGEN_UART2_WKRFRTEN
    /* Enable UART Received Data FIFO Reached Threshold Wake up */
    UART2->WKCTL |= UART_WKCTL_WKRFRTEN_Msk;
#endif

#if NUCODEGEN_UART2_WKTOUTEN
    /* Enable UART Received Data FIFO Threshold Time-out Wake up */
    UART2->WKCTL |= UART_WKCTL_WKTOUTEN_Msk;
#endif

#if NUCODEGEN_UART2_WKRS485EN
    /* Enable RS-485 Address Match (AAD Mode) Wake up */
    UART2->WKCTL |= UART_WKCTL_WKRS485EN_Msk;
#endif

#if (NUCODEGEN_UART2_INTEN || NUCODEGEN_UART2_IRDA_INTEN || NUCODEGEN_UART2_RS485_INTEN || NUCODEGEN_UART2_SW_INTEN )
    /*Enable UART IRQ Handler */
    NVIC_EnableIRQ(UART2_IRQn);
#endif

}
#endif //NUCODEGEN_UART2

#if (NUCODEGEN_PDMA)
/*************************************/
/**             PDMA                **/
/*************************************/
#if ((NUCODEGEN_PDMA_CH0_OPMODE_S==NUCODEGEN_PDMA_OP_SCATTER)||(NUCODEGEN_PDMA_CH1_OPMODE_S==NUCODEGEN_PDMA_OP_SCATTER)||(NUCODEGEN_PDMA_CH2_OPMODE_S==NUCODEGEN_PDMA_OP_SCATTER)||(NUCODEGEN_PDMA_CH3_OPMODE_S==NUCODEGEN_PDMA_OP_SCATTER)||(NUCODEGEN_PDMA_CH4_OPMODE_S==NUCODEGEN_PDMA_OP_SCATTER)||(NUCODEGEN_PDMA_CH5_OPMODE_S==NUCODEGEN_PDMA_OP_SCATTER)||(NUCODEGEN_PDMA_CH6_OPMODE_S==NUCODEGEN_PDMA_OP_SCATTER)||(NUCODEGEN_PDMA_CH7_OPMODE_S==NUCODEGEN_PDMA_OP_SCATTER))
typedef struct dma_desc_t
{
    uint32_t u32Ctl;
    uint32_t u32Src;
    uint32_t u32Dest;
    uint32_t u32Offset;
} DMA_DESC_T;
#endif

#if(NUCODEGEN_PDMA_CH0_OPMODE_TB3_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_T DMA_DESC_CH0[5];
#elif(NUCODEGEN_PDMA_CH0_OPMODE_TB2_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_T DMA_DESC_CH0[4];
#elif(NUCODEGEN_PDMA_CH0_OPMODE_TB1_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_T DMA_DESC_CH0[3];
#elif(NUCODEGEN_PDMA_CH0_OPMODE_TB0_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_T DMA_DESC_CH0[2];
#elif(NUCODEGEN_PDMA_CH0_OPMODE_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_T DMA_DESC_CH0[1];
#endif

#if(NUCODEGEN_PDMA_CH1_OPMODE_TB3_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_T DMA_DESC_CH1[5];
#elif(NUCODEGEN_PDMA_CH1_OPMODE_TB2_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_T DMA_DESC_CH1[4];
#elif(NUCODEGEN_PDMA_CH1_OPMODE_TB1_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_T DMA_DESC_CH1[3];
#elif(NUCODEGEN_PDMA_CH1_OPMODE_TB0_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_T DMA_DESC_CH1[2];
#elif(NUCODEGEN_PDMA_CH1_OPMODE_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_T DMA_DESC_CH1[1];
#endif

#if(NUCODEGEN_PDMA_CH2_OPMODE_TB3_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_T DMA_DESC_CH2[5];
#elif(NUCODEGEN_PDMA_CH2_OPMODE_TB2_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_T DMA_DESC_CH2[4];
#elif(NUCODEGEN_PDMA_CH2_OPMODE_TB1_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_T DMA_DESC_CH2[3];
#elif(NUCODEGEN_PDMA_CH2_OPMODE_TB0_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_T DMA_DESC_CH2[2];
#elif(NUCODEGEN_PDMA_CH2_OPMODE_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_T DMA_DESC_CH2[1];
#endif

#if(NUCODEGEN_PDMA_CH3_OPMODE_TB3_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_T DMA_DESC_CH3[5];
#elif(NUCODEGEN_PDMA_CH3_OPMODE_TB2_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_T DMA_DESC_CH3[4];
#elif(NUCODEGEN_PDMA_CH3_OPMODE_TB1_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_T DMA_DESC_CH3[3];
#elif(NUCODEGEN_PDMA_CH3_OPMODE_TB0_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_T DMA_DESC_CH3[2];
#elif(NUCODEGEN_PDMA_CH3_OPMODE_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_T DMA_DESC_CH3[1];
#endif

#if(NUCODEGEN_PDMA_CH4_OPMODE_TB3_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_T DMA_DESC_CH4[5];
#elif(NUCODEGEN_PDMA_CH4_OPMODE_TB2_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_T DMA_DESC_CH4[4];
#elif(NUCODEGEN_PDMA_CH4_OPMODE_TB1_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_T DMA_DESC_CH4[3];
#elif(NUCODEGEN_PDMA_CH4_OPMODE_TB0_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_T DMA_DESC_CH4[2];
#elif(NUCODEGEN_PDMA_CH4_OPMODE_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_T DMA_DESC_CH4[1];
#endif

#if(NUCODEGEN_PDMA_CH5_OPMODE_TB3_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_T DMA_DESC_CH5[5];
#elif(NUCODEGEN_PDMA_CH5_OPMODE_TB2_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_T DMA_DESC_CH5[4];
#elif(NUCODEGEN_PDMA_CH5_OPMODE_TB1_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_T DMA_DESC_CH5[3];
#elif(NUCODEGEN_PDMA_CH5_OPMODE_TB0_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_T DMA_DESC_CH5[2];
#elif(NUCODEGEN_PDMA_CH5_OPMODE_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_T DMA_DESC_CH5[1];
#endif

#if(NUCODEGEN_PDMA_CH6_OPMODE_TB3_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_T DMA_DESC_CH6[5];
#elif(NUCODEGEN_PDMA_CH6_OPMODE_TB2_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_T DMA_DESC_CH6[4];
#elif(NUCODEGEN_PDMA_CH6_OPMODE_TB1_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_T DMA_DESC_CH6[3];
#elif(NUCODEGEN_PDMA_CH6_OPMODE_TB0_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_T DMA_DESC_CH6[2];
#elif(NUCODEGEN_PDMA_CH6_OPMODE_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_T DMA_DESC_CH6[1];
#endif

#if(NUCODEGEN_PDMA_CH7_OPMODE_TB3_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_T DMA_DESC_CH7[5];
#elif(NUCODEGEN_PDMA_CH7_OPMODE_TB2_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_T DMA_DESC_CH7[4];
#elif(NUCODEGEN_PDMA_CH7_OPMODE_TB1_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_T DMA_DESC_CH7[3];
#elif(NUCODEGEN_PDMA_CH7_OPMODE_TB0_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_T DMA_DESC_CH7[2];
#elif(NUCODEGEN_PDMA_CH7_OPMODE_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_T DMA_DESC_CH7[1];
#endif

#if(NUCODEGEN_PDMA_CH0_SRC_ADDR_S)
    uint32_t* g_pu32CH0SrcArray;
    #if(NUCODEGEN_PDMA_CH0_OPMODE_S==NUCODEGEN_PDMA_OP_SCATTER)
    uint32_t* g_pu32CH0SrcArrayTB0;
    #endif
    #if(NUCODEGEN_PDMA_CH0_OPMODE_TB0_S==NUCODEGEN_PDMA_OP_SCATTER)
    uint32_t* g_pu32CH0SrcArrayTB1;
    #endif
    #if(NUCODEGEN_PDMA_CH0_OPMODE_TB1_S==NUCODEGEN_PDMA_OP_SCATTER)
    uint32_t* g_pu32CH0SrcArrayTB2;
    #endif
    #if(NUCODEGEN_PDMA_CH0_OPMODE_TB2_S==NUCODEGEN_PDMA_OP_SCATTER)
    uint32_t* g_pu32CH0SrcArrayTB3;
    #endif
    #if(NUCODEGEN_PDMA_CH0_OPMODE_TB3_S==NUCODEGEN_PDMA_OP_SCATTER)
    uint32_t* g_pu32CH0SrcArrayTB4;
    #endif
#endif
#if(NUCODEGEN_PDMA_CH0_DES_ADDR_S)
    uint32_t* g_pu32CH0DesArray;
    #if(NUCODEGEN_PDMA_CH0_OPMODE_S==NUCODEGEN_PDMA_OP_SCATTER)
    uint32_t* g_pu32CH0DesArrayTB0;
    #endif
    #if(NUCODEGEN_PDMA_CH0_OPMODE_TB0_S==NUCODEGEN_PDMA_OP_SCATTER)
    uint32_t* g_pu32CH0DesArrayTB1;
    #endif
    #if(NUCODEGEN_PDMA_CH0_OPMODE_TB1_S==NUCODEGEN_PDMA_OP_SCATTER)
    uint32_t* g_pu32CH0DesArrayTB2;
    #endif
    #if(NUCODEGEN_PDMA_CH0_OPMODE_TB2_S==NUCODEGEN_PDMA_OP_SCATTER)
    uint32_t* g_pu32CH0DesArrayTB3;
    #endif
    #if(NUCODEGEN_PDMA_CH0_OPMODE_TB3_S==NUCODEGEN_PDMA_OP_SCATTER)
    uint32_t* g_pu32CH0DesArrayTB4;
    #endif
#endif

#if(NUCODEGEN_PDMA_CH1_SRC_ADDR_S)
    uint32_t* g_pu32CH1SrcArray;
    #if(NUCODEGEN_PDMA_CH1_OPMODE_S==NUCODEGEN_PDMA_OP_SCATTER)
    uint32_t* g_pu32CH1SrcArrayTB0;
    #endif
    #if(NUCODEGEN_PDMA_CH1_OPMODE_TB0_S==NUCODEGEN_PDMA_OP_SCATTER)
    uint32_t* g_pu32CH1SrcArrayTB1;
    #endif
    #if(NUCODEGEN_PDMA_CH1_OPMODE_TB1_S==NUCODEGEN_PDMA_OP_SCATTER)
    uint32_t* g_pu32CH1SrcArrayTB2;
    #endif
    #if(NUCODEGEN_PDMA_CH1_OPMODE_TB2_S==NUCODEGEN_PDMA_OP_SCATTER)
    uint32_t* g_pu32CH1SrcArrayTB3;
    #endif
    #if(NUCODEGEN_PDMA_CH1_OPMODE_TB3_S==NUCODEGEN_PDMA_OP_SCATTER)
    uint32_t* g_pu32CH1SrcArrayTB4;
    #endif
#endif
#if(NUCODEGEN_PDMA_CH1_DES_ADDR_S)
    uint32_t* g_pu32CH1DesArray;
    #if(NUCODEGEN_PDMA_CH1_OPMODE_S==NUCODEGEN_PDMA_OP_SCATTER)
    uint32_t* g_pu32CH1DesArrayTB0;
    #endif
    #if(NUCODEGEN_PDMA_CH1_OPMODE_TB0_S==NUCODEGEN_PDMA_OP_SCATTER)
    uint32_t* g_pu32CH1DesArrayTB1;
    #endif
    #if(NUCODEGEN_PDMA_CH1_OPMODE_TB1_S==NUCODEGEN_PDMA_OP_SCATTER)
    uint32_t* g_pu32CH1DesArrayTB2;
    #endif
    #if(NUCODEGEN_PDMA_CH1_OPMODE_TB2_S==NUCODEGEN_PDMA_OP_SCATTER)
    uint32_t* g_pu32CH1DesArrayTB3;
    #endif
    #if(NUCODEGEN_PDMA_CH1_OPMODE_TB3_S==NUCODEGEN_PDMA_OP_SCATTER)
    uint32_t* g_pu32CH1DesArrayTB4;
    #endif
#endif

#if(NUCODEGEN_PDMA_CH2_SRC_ADDR_S)
    uint32_t* g_pu32CH2SrcArray;
    #if(NUCODEGEN_PDMA_CH2_OPMODE_S==NUCODEGEN_PDMA_OP_SCATTER)
    uint32_t* g_pu32CH2SrcArrayTB0;
    #endif
    #if(NUCODEGEN_PDMA_CH2_OPMODE_TB0_S==NUCODEGEN_PDMA_OP_SCATTER)
    uint32_t* g_pu32CH2SrcArrayTB1;
    #endif
    #if(NUCODEGEN_PDMA_CH2_OPMODE_TB1_S==NUCODEGEN_PDMA_OP_SCATTER)
    uint32_t* g_pu32CH2SrcArrayTB2;
    #endif
    #if(NUCODEGEN_PDMA_CH2_OPMODE_TB2_S==NUCODEGEN_PDMA_OP_SCATTER)
    uint32_t* g_pu32CH2SrcArrayTB3;
    #endif
    #if(NUCODEGEN_PDMA_CH2_OPMODE_TB3_S==NUCODEGEN_PDMA_OP_SCATTER)
    uint32_t* g_pu32CH2SrcArrayTB4;
    #endif
#endif
#if(NUCODEGEN_PDMA_CH2_DES_ADDR_S)
    uint32_t* g_pu32CH2DesArray;
    #if(NUCODEGEN_PDMA_CH2_OPMODE_S==NUCODEGEN_PDMA_OP_SCATTER)
    uint32_t* g_pu32CH2DesArrayTB0;
    #endif
    #if(NUCODEGEN_PDMA_CH2_OPMODE_TB0_S==NUCODEGEN_PDMA_OP_SCATTER)
    uint32_t* g_pu32CH2DesArrayTB1;
    #endif
    #if(NUCODEGEN_PDMA_CH2_OPMODE_TB1_S==NUCODEGEN_PDMA_OP_SCATTER)
    uint32_t* g_pu32CH2DesArrayTB2;
    #endif
    #if(NUCODEGEN_PDMA_CH2_OPMODE_TB2_S==NUCODEGEN_PDMA_OP_SCATTER)
    uint32_t* g_pu32CH2DesArrayTB3;
    #endif
    #if(NUCODEGEN_PDMA_CH2_OPMODE_TB3_S==NUCODEGEN_PDMA_OP_SCATTER)
    uint32_t* g_pu32CH2DesArrayTB4;
    #endif
#endif

#if(NUCODEGEN_PDMA_CH3_SRC_ADDR_S)
    uint32_t* g_pu32CH3SrcArray;
    #if(NUCODEGEN_PDMA_CH3_OPMODE_S==NUCODEGEN_PDMA_OP_SCATTER)
    uint32_t* g_pu32CH3SrcArrayTB0;
    #endif
    #if(NUCODEGEN_PDMA_CH3_OPMODE_TB0_S==NUCODEGEN_PDMA_OP_SCATTER)
    uint32_t* g_pu32CH3SrcArrayTB1;
    #endif
    #if(NUCODEGEN_PDMA_CH3_OPMODE_TB1_S==NUCODEGEN_PDMA_OP_SCATTER)
    uint32_t* g_pu32CH3SrcArrayTB2;
    #endif
    #if(NUCODEGEN_PDMA_CH3_OPMODE_TB2_S==NUCODEGEN_PDMA_OP_SCATTER)
    uint32_t* g_pu32CH3SrcArrayTB3;
    #endif
    #if(NUCODEGEN_PDMA_CH3_OPMODE_TB3_S==NUCODEGEN_PDMA_OP_SCATTER)
    uint32_t* g_pu32CH3SrcArrayTB4;
    #endif
#endif
#if(NUCODEGEN_PDMA_CH3_DES_ADDR_S)
    uint32_t* g_pu32CH3DesArray;
    #if(NUCODEGEN_PDMA_CH3_OPMODE_S==NUCODEGEN_PDMA_OP_SCATTER)
    uint32_t* g_pu32CH3DesArrayTB0;
    #endif
    #if(NUCODEGEN_PDMA_CH3_OPMODE_TB0_S==NUCODEGEN_PDMA_OP_SCATTER)
    uint32_t* g_pu32CH3DesArrayTB1;
    #endif
    #if(NUCODEGEN_PDMA_CH3_OPMODE_TB1_S==NUCODEGEN_PDMA_OP_SCATTER)
    uint32_t* g_pu32CH3DesArrayTB2;
    #endif
    #if(NUCODEGEN_PDMA_CH3_OPMODE_TB2_S==NUCODEGEN_PDMA_OP_SCATTER)
    uint32_t* g_pu32CH3DesArrayTB3;
    #endif
    #if(NUCODEGEN_PDMA_CH3_OPMODE_TB3_S==NUCODEGEN_PDMA_OP_SCATTER)
    uint32_t* g_pu32CH3DesArrayTB4;
    #endif
#endif

#if(NUCODEGEN_PDMA_CH4_SRC_ADDR_S)
    uint32_t* g_pu32CH4SrcArray;
    #if(NUCODEGEN_PDMA_CH4_OPMODE_S==NUCODEGEN_PDMA_OP_SCATTER)
    uint32_t* g_pu32CH4SrcArrayTB0;
    #endif
    #if(NUCODEGEN_PDMA_CH4_OPMODE_TB0_S==NUCODEGEN_PDMA_OP_SCATTER)
    uint32_t* g_pu32CH4SrcArrayTB1;
    #endif
    #if(NUCODEGEN_PDMA_CH4_OPMODE_TB1_S==NUCODEGEN_PDMA_OP_SCATTER)
    uint32_t* g_pu32CH4SrcArrayTB2;
    #endif
    #if(NUCODEGEN_PDMA_CH4_OPMODE_TB2_S==NUCODEGEN_PDMA_OP_SCATTER)
    uint32_t* g_pu32CH4SrcArrayTB3;
    #endif
    #if(NUCODEGEN_PDMA_CH4_OPMODE_TB3_S==NUCODEGEN_PDMA_OP_SCATTER)
    uint32_t* g_pu32CH4SrcArrayTB4;
    #endif
#endif
#if(NUCODEGEN_PDMA_CH4_DES_ADDR_S)
    uint32_t* g_pu32CH4DesArray;
    #if(NUCODEGEN_PDMA_CH4_OPMODE_S==NUCODEGEN_PDMA_OP_SCATTER)
    uint32_t* g_pu32CH4DesArrayTB0;
    #endif
    #if(NUCODEGEN_PDMA_CH4_OPMODE_TB0_S==NUCODEGEN_PDMA_OP_SCATTER)
    uint32_t* g_pu32CH4DesArrayTB1;
    #endif
    #if(NUCODEGEN_PDMA_CH4_OPMODE_TB1_S==NUCODEGEN_PDMA_OP_SCATTER)
    uint32_t* g_pu32CH4DesArrayTB2;
    #endif
    #if(NUCODEGEN_PDMA_CH4_OPMODE_TB2_S==NUCODEGEN_PDMA_OP_SCATTER)
    uint32_t* g_pu32CH4DesArrayTB3;
    #endif
    #if(NUCODEGEN_PDMA_CH4_OPMODE_TB3_S==NUCODEGEN_PDMA_OP_SCATTER)
    uint32_t* g_pu32CH4DesArrayTB4;
    #endif
#endif

#if(NUCODEGEN_PDMA_CH5_SRC_ADDR_S)
    uint32_t* g_pu32CH5SrcArray;
    #if(NUCODEGEN_PDMA_CH5_OPMODE_S==NUCODEGEN_PDMA_OP_SCATTER)
    uint32_t* g_pu32CH5SrcArrayTB0;
    #endif
    #if(NUCODEGEN_PDMA_CH5_OPMODE_TB0_S==NUCODEGEN_PDMA_OP_SCATTER)
    uint32_t* g_pu32CH5SrcArrayTB1;
    #endif
    #if(NUCODEGEN_PDMA_CH5_OPMODE_TB1_S==NUCODEGEN_PDMA_OP_SCATTER)
    uint32_t* g_pu32CH5SrcArrayTB2;
    #endif
    #if(NUCODEGEN_PDMA_CH5_OPMODE_TB2_S==NUCODEGEN_PDMA_OP_SCATTER)
    uint32_t* g_pu32CH5SrcArrayTB3;
    #endif
    #if(NUCODEGEN_PDMA_CH5_OPMODE_TB3_S==NUCODEGEN_PDMA_OP_SCATTER)
    uint32_t* g_pu32CH5SrcArrayTB4;
    #endif
#endif
#if(NUCODEGEN_PDMA_CH5_DES_ADDR_S)
    uint32_t* g_pu32CH5DesArray;
    #if(NUCODEGEN_PDMA_CH5_OPMODE_S==NUCODEGEN_PDMA_OP_SCATTER)
    uint32_t* g_pu32CH5DesArrayTB0;
    #endif
    #if(NUCODEGEN_PDMA_CH5_OPMODE_TB0_S==NUCODEGEN_PDMA_OP_SCATTER)
    uint32_t* g_pu32CH5DesArrayTB1;
    #endif
    #if(NUCODEGEN_PDMA_CH5_OPMODE_TB1_S==NUCODEGEN_PDMA_OP_SCATTER)
    uint32_t* g_pu32CH5DesArrayTB2;
    #endif
    #if(NUCODEGEN_PDMA_CH5_OPMODE_TB2_S==NUCODEGEN_PDMA_OP_SCATTER)
    uint32_t* g_pu32CH5DesArrayTB3;
    #endif
    #if(NUCODEGEN_PDMA_CH5_OPMODE_TB3_S==NUCODEGEN_PDMA_OP_SCATTER)
    uint32_t* g_pu32CH5DesArrayTB4;
    #endif
#endif

#if(NUCODEGEN_PDMA_CH6_SRC_ADDR_S)
    uint32_t* g_pu32CH6SrcArray;
    #if(NUCODEGEN_PDMA_CH6_OPMODE_S==NUCODEGEN_PDMA_OP_SCATTER)
    uint32_t* g_pu32CH6SrcArrayTB0;
    #endif
    #if(NUCODEGEN_PDMA_CH6_OPMODE_TB0_S==NUCODEGEN_PDMA_OP_SCATTER)
    uint32_t* g_pu32CH6SrcArrayTB1;
    #endif
    #if(NUCODEGEN_PDMA_CH6_OPMODE_TB1_S==NUCODEGEN_PDMA_OP_SCATTER)
    uint32_t* g_pu32CH6SrcArrayTB2;
    #endif
    #if(NUCODEGEN_PDMA_CH6_OPMODE_TB2_S==NUCODEGEN_PDMA_OP_SCATTER)
    uint32_t* g_pu32CH6SrcArrayTB3;
    #endif
    #if(NUCODEGEN_PDMA_CH6_OPMODE_TB3_S==NUCODEGEN_PDMA_OP_SCATTER)
    uint32_t* g_pu32CH6SrcArrayTB4;
    #endif
#endif
#if(NUCODEGEN_PDMA_CH6_DES_ADDR_S)
    uint32_t* g_pu32CH6DesArray;
    #if(NUCODEGEN_PDMA_CH6_OPMODE_S==NUCODEGEN_PDMA_OP_SCATTER)
    uint32_t* g_pu32CH6DesArrayTB0;
    #endif
    #if(NUCODEGEN_PDMA_CH6_OPMODE_TB0_S==NUCODEGEN_PDMA_OP_SCATTER)
    uint32_t* g_pu32CH6DesArrayTB1;
    #endif
    #if(NUCODEGEN_PDMA_CH6_OPMODE_TB1_S==NUCODEGEN_PDMA_OP_SCATTER)
    uint32_t* g_pu32CH6DesArrayTB2;
    #endif
    #if(NUCODEGEN_PDMA_CH6_OPMODE_TB2_S==NUCODEGEN_PDMA_OP_SCATTER)
    uint32_t* g_pu32CH6DesArrayTB3;
    #endif
    #if(NUCODEGEN_PDMA_CH6_OPMODE_TB3_S==NUCODEGEN_PDMA_OP_SCATTER)
    uint32_t* g_pu32CH6DesArrayTB4;
    #endif
#endif

#if(NUCODEGEN_PDMA_CH7_SRC_ADDR_S)
    uint32_t* g_pu32CH7SrcArray;
    #if(NUCODEGEN_PDMA_CH7_OPMODE_S==NUCODEGEN_PDMA_OP_SCATTER)
    uint32_t* g_pu32CH7SrcArrayTB0;
    #endif
    #if(NUCODEGEN_PDMA_CH7_OPMODE_TB0_S==NUCODEGEN_PDMA_OP_SCATTER)
    uint32_t* g_pu32CH7SrcArrayTB1;
    #endif
    #if(NUCODEGEN_PDMA_CH7_OPMODE_TB1_S==NUCODEGEN_PDMA_OP_SCATTER)
    uint32_t* g_pu32CH7SrcArrayTB2;
    #endif
    #if(NUCODEGEN_PDMA_CH7_OPMODE_TB2_S==NUCODEGEN_PDMA_OP_SCATTER)
    uint32_t* g_pu32CH7SrcArrayTB3;
    #endif
    #if(NUCODEGEN_PDMA_CH7_OPMODE_TB3_S==NUCODEGEN_PDMA_OP_SCATTER)
    uint32_t* g_pu32CH7SrcArrayTB4;
    #endif
#endif
#if(NUCODEGEN_PDMA_CH7_DES_ADDR_S)
    uint32_t* g_pu32CH7DesArray;
    #if(NUCODEGEN_PDMA_CH7_OPMODE_S==NUCODEGEN_PDMA_OP_SCATTER)
    uint32_t* g_pu32CH7DesArrayTB0;
    #endif
    #if(NUCODEGEN_PDMA_CH7_OPMODE_TB0_S==NUCODEGEN_PDMA_OP_SCATTER)
    uint32_t* g_pu32CH7DesArrayTB1;
    #endif
    #if(NUCODEGEN_PDMA_CH7_OPMODE_TB1_S==NUCODEGEN_PDMA_OP_SCATTER)
    uint32_t* g_pu32CH7DesArrayTB2;
    #endif
    #if(NUCODEGEN_PDMA_CH7_OPMODE_TB2_S==NUCODEGEN_PDMA_OP_SCATTER)
    uint32_t* g_pu32CH7DesArrayTB3;
    #endif
    #if(NUCODEGEN_PDMA_CH7_OPMODE_TB3_S==NUCODEGEN_PDMA_OP_SCATTER)
    uint32_t* g_pu32CH7DesArrayTB4;
    #endif
#endif

void PDMA_Init()
{
#if (NUCODEGEN_PDMA_CH0)
#if (NUCODEGEN_PDMA_CH0_OPMODE_S == NUCODEGEN_PDMA_OP_BASIC)
    /* Open CH0 */
    PDMA_Open(PDMA, 1 << 0);

    /* Transfer count is PDMA_CH0_DATA_LENGTH, transfer width is NUCODEGEN_PDMA_CH0_WIDTH */
    PDMA_SetTransferCnt(PDMA, 0, NUCODEGEN_PDMA_CH0_WIDTH, PDMA_CH0_DATA_LENGTH);

    /* Set source address is NUCODEGEN_PDMA_CH0_SRC_ADDR, destination address is NUCODEGEN_PDMA_CH0_DES_ADDR */
    PDMA_SetTransferAddr(PDMA, 0, (uint32_t)NUCODEGEN_PDMA_CH0_SRC_ADDR, NUCODEGEN_PDMA_CH0_SRC_TYPE, (uint32_t)NUCODEGEN_PDMA_CH0_DES_ADDR, NUCODEGEN_PDMA_CH0_DES_TYPE);

    /* Set transfer mode and burst size */
    PDMA_SetBurstType(PDMA, 0, NUCODEGEN_PDMA_CH0_MODE, NUCODEGEN_PDMA_CH0_BURST_SIZE);

    #if(NUCODEGEN_PDMA_CH0_TMOUT)
    /* Enable timeout function and set timeout counter */
    PDMA_SetTimeOut(PDMA, 0, NUCODEGEN_PDMA_CH0_TMOUT, NUCODEGEN_PDMA_CH0_TMOUT_CNT);
    #endif

    #if(NUCODEGEN_PDMA_CH0_STRIDE_EN)
    /* Set stride function */
    PDMA_SetStride(PDMA, 0, NUCODEGEN_PDMA_CH0_STRIDE_DES_LENGTH, NUCODEGEN_PDMA_CH0_STRIDE_SRC_LENGTH, NUCODEGEN_PDMA_CH0_STRIDE_CNT);
    #endif

    /* Request source is NUCODEGEN_PDMA_CH0_SRC_DES_SEL */
    PDMA_SetTransferMode(PDMA, 0, NUCODEGEN_PDMA_CH0_SRC_DES_SEL, 0, 0);
#else   //NUCODEGEN_PDMA_CH0_OPMODE_S == PDMA_OP_SCATTER
    /* Open CH0 */
    PDMA_Open(PDMA, 1 << 0);

    DMA_DESC_CH0[0].u32Ctl =
        (((uint32_t)PDMA_CH0_DATA_LENGTH_TB0 - 1) << PDMA_DSCT_CTL_TXCNT_Pos) | /* Set transfer count */ \
        NUCODEGEN_PDMA_CH0_WIDTH_TB0 |   /*   Set transfer width */ \
        NUCODEGEN_PDMA_CH0_SRC_TYPE_TB0 |    /* Set source increment type */ \
        NUCODEGEN_PDMA_CH0_DES_TYPE_TB0 |    /* Set destination increment type */ \
        NUCODEGEN_PDMA_CH0_MODE_TB0 |  /* Set transfer type */ \
        NUCODEGEN_PDMA_CH0_BURST_SIZE_TB0 |  /* Set burst size */ \
        NUCODEGEN_PDMA_CH0_TB0_INT_EN |   /* Set table empty interrupt */ \
        NUCODEGEN_PDMA_CH0_OPMODE_TB0;  /* Set operation mode */

    /* Configure source address */
    DMA_DESC_CH0[0].u32Src = (uint32_t)NUCODEGEN_PDMA_CH0_SRC_ADDR_TB0;

    /* Configure destination address */
    DMA_DESC_CH0[0].u32Dest = (uint32_t)NUCODEGEN_PDMA_CH0_DES_ADDR_TB0;

	#if(NUCODEGEN_PDMA_CH0_OPMODE_TB0_S==NUCODEGEN_PDMA_OP_BASIC)
    /* Configure next descriptor table address */
    DMA_DESC_CH0[0].u32Offset = 0; /* No next operation table. No effect in basic mode */
	#else
    /* Configure next descriptor table address */
    DMA_DESC_CH0[0].u32Offset = (uint32_t)&DMA_DESC_CH0[1] - (PDMA->SCATBA); /* next descriptor table is table 1 */
    #endif
    #if(NUCODEGEN_PDMA_CH0_OPMODE_TB0_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_CH0[1].u32Ctl =
        (((uint32_t)PDMA_CH0_DATA_LENGTH_TB1 - 1) << PDMA_DSCT_CTL_TXCNT_Pos) | /* Set transfer count */ \
        NUCODEGEN_PDMA_CH0_WIDTH_TB1 |   /* Set transfer width */ \
        NUCODEGEN_PDMA_CH0_SRC_TYPE_TB1 |    /* Set source increment type */ \
        NUCODEGEN_PDMA_CH0_DES_TYPE_TB1 |    /* Set destination increment type */ \
        NUCODEGEN_PDMA_CH0_MODE_TB1 |  /* Set transfer type */ \
        NUCODEGEN_PDMA_CH0_BURST_SIZE_TB1 |  /* Set burst size */ \
        NUCODEGEN_PDMA_CH0_TB1_INT_EN |   /* Set table empty interrupt */ \
        NUCODEGEN_PDMA_CH0_OPMODE_TB1;  /* Set operation mode */

    /* Configure source address */
    DMA_DESC_CH0[1].u32Src = (uint32_t)NUCODEGEN_PDMA_CH0_SRC_ADDR_TB1;

    /* Configure destination address */
    DMA_DESC_CH0[1].u32Dest = (uint32_t)NUCODEGEN_PDMA_CH0_DES_ADDR_TB1;

	#if(NUCODEGEN_PDMA_CH0_OPMODE_TB1_S==NUCODEGEN_PDMA_OP_BASIC)
    /* Configure next descriptor table address */
    DMA_DESC_CH0[1].u32Offset = 0; /* No next operation table. No effect in basic mode */
	#else
    /* Configure next descriptor table address */
    DMA_DESC_CH0[1].u32Offset = (uint32_t)&DMA_DESC_CH0[2] - (PDMA->SCATBA); /* next descriptor table is table 2 */
	#endif
    #endif
    #if(NUCODEGEN_PDMA_CH0_OPMODE_TB1_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_CH0[2].u32Ctl =
        (((uint32_t)PDMA_CH0_DATA_LENGTH_TB2 - 1) << PDMA_DSCT_CTL_TXCNT_Pos) | /* Set transfer count */ \
        NUCODEGEN_PDMA_CH0_WIDTH_TB2 |   /* Set transfer width */ \
        NUCODEGEN_PDMA_CH0_SRC_TYPE_TB2 |    /* Set source increment type */ \
        NUCODEGEN_PDMA_CH0_DES_TYPE_TB2 |    /* Set destination increment type */ \
        NUCODEGEN_PDMA_CH0_MODE_TB2 |  /* Set transfer type */ \
        NUCODEGEN_PDMA_CH0_BURST_SIZE_TB2 |  /* Set burst size */ \
        NUCODEGEN_PDMA_CH0_TB2_INT_EN |   /* Set table empty interrupt */ \
        NUCODEGEN_PDMA_CH0_OPMODE_TB2;  /* Set operation mode */

    /* Configure source address */
    DMA_DESC_CH0[2].u32Src = (uint32_t)NUCODEGEN_PDMA_CH0_SRC_ADDR_TB2;

    /* Configure destination address */
    DMA_DESC_CH0[2].u32Dest = (uint32_t)NUCODEGEN_PDMA_CH0_DES_ADDR_TB2;
	#if(NUCODEGEN_PDMA_CH0_OPMODE_TB2_S==NUCODEGEN_PDMA_OP_BASIC)
    /* Configure next descriptor table address */
    DMA_DESC_CH0[2].u32Offset = 0; /* No next operation table. No effect in basic mode */
    #else
    /* Configure next descriptor table address */
    DMA_DESC_CH0[2].u32Offset = (uint32_t)&DMA_DESC_CH0[3] - (PDMA->SCATBA); /* next descriptor table is table 3 */
	#endif
    #endif
    #if(NUCODEGEN_PDMA_CH0_OPMODE_TB2_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_CH0[3].u32Ctl =
        (((uint32_t)PDMA_CH0_DATA_LENGTH_TB3 - 1) << PDMA_DSCT_CTL_TXCNT_Pos) | /* Set transfer count */ \
        NUCODEGEN_PDMA_CH0_WIDTH_TB3 |   /* Set transfer width */ \
        NUCODEGEN_PDMA_CH0_SRC_TYPE_TB3 |    /* Set source increment type */ \
        NUCODEGEN_PDMA_CH0_DES_TYPE_TB3 |    /* Set destination increment type */ \
        NUCODEGEN_PDMA_CH0_MODE_TB3 |  /* Set transfer type */ \
        NUCODEGEN_PDMA_CH0_BURST_SIZE_TB3 |  /* Set burst size */ \
        NUCODEGEN_PDMA_CH0_TB3_INT_EN |   /* Set table empty interrupt */ \
        NUCODEGEN_PDMA_CH0_OPMODE_TB3;  /* Set operation mode */

    /* Configure source address */
    DMA_DESC_CH0[3].u32Src = (uint32_t)NUCODEGEN_PDMA_CH0_SRC_ADDR_TB3;

    /* Configure destination address */
    DMA_DESC_CH0[3].u32Dest = (uint32_t)NUCODEGEN_PDMA_CH0_DES_ADDR_TB3;

	#if(NUCODEGEN_PDMA_CH0_OPMODE_TB3_S==NUCODEGEN_PDMA_OP_BASIC)
    /* Configure next descriptor table address */
    DMA_DESC_CH0[3].u32Offset = 0; /* No next operation table. No effect in basic mode */
	#else
    /* Configure next descriptor table address */
    DMA_DESC_CH0[3].u32Offset = (uint32_t)&DMA_DESC_CH0[4] - (PDMA->SCATBA); /* next descriptor table is table 4 */
	#endif
    #endif
    #if(NUCODEGEN_PDMA_CH0_OPMODE_TB3_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_CH0[4].u32Ctl =
        (((uint32_t)PDMA_CH0_DATA_LENGTH_TB4 - 1) << PDMA_DSCT_CTL_TXCNT_Pos) | /* Set transfer count */ \
        NUCODEGEN_PDMA_CH0_WIDTH_TB4 |   /* Set transfer width */ \
        NUCODEGEN_PDMA_CH0_SRC_TYPE_TB4 |    /* Set source increment type */ \
        NUCODEGEN_PDMA_CH0_DES_TYPE_TB4 |    /* Set destination increment type */ \
        NUCODEGEN_PDMA_CH0_MODE_TB4 |  /* Set transfer type */ \
        NUCODEGEN_PDMA_CH0_BURST_SIZE_TB4 |  /* Set burst size */ \
        NUCODEGEN_PDMA_CH0_TB4_INT_EN |   /* Set table empty interrupt */ \
        NUCODEGEN_PDMA_CH0_OPMODE_TB4;  /* Set operation mode */

    /* Configure source address */
    DMA_DESC_CH0[4].u32Src = (uint32_t)NUCODEGEN_PDMA_CH0_SRC_ADDR_TB4;

    /* Configure destination address */
    DMA_DESC_CH0[4].u32Dest = (uint32_t)NUCODEGEN_PDMA_CH0_DES_ADDR_TB4;

    /* Configure next descriptor table address */
    DMA_DESC_CH0[4].u32Offset = (uint32_t)&DMA_DESC_CH0[5] - (PDMA->SCATBA); /* next descriptor table is table 5 */
    #endif

    #if(NUCODEGEN_PDMA_CH0_TMOUT)
    /* Enable timeout function and set timeout counter */
    PDMA_SetTimeOut(PDMA, 0, NUCODEGEN_PDMA_CH0_TMOUT, NUCODEGEN_PDMA_CH0_TMOUT_CNT);
    #endif

    #if(NUCODEGEN_PDMA_CH0_STRIDE_EN)
    /* Set stride function */
    PDMA_SetStride(PDMA, 0, NUCODEGEN_PDMA_CH0_STRIDE_DES_LENGTH, NUCODEGEN_PDMA_CH0_STRIDE_SRC_LENGTH, NUCODEGEN_PDMA_CH0_STRIDE_CNT);
    #endif

    /* Request source is NUCODEGEN_PDMA_CH0_SRC_DES_SEL */
    PDMA_SetTransferMode(PDMA, 0, NUCODEGEN_PDMA_CH0_SRC_DES_SEL, 1, (uint32_t)&DMA_DESC_CH0[0]);
#endif  //NUCODEGEN_PDMA_CH0_OPMODE == PDMA_OP_BASIC
#endif  //NUCODEGEN_PDMA_CH0

#if (NUCODEGEN_PDMA_CH1)
#if (NUCODEGEN_PDMA_CH1_OPMODE_S == NUCODEGEN_PDMA_OP_BASIC)
    /* Open CH1 */
    PDMA_Open(PDMA, 1 << 1);

    /* Transfer count is PDMA_CH1_DATA_LENGTH, transfer width is NUCODEGEN_PDMA_CH1_WIDTH */
    PDMA_SetTransferCnt(PDMA, 1, NUCODEGEN_PDMA_CH1_WIDTH, PDMA_CH1_DATA_LENGTH);

    /* Set source address is NUCODEGEN_PDMA_CH1_SRC_ADDR, destination address is NUCODEGEN_PDMA_CH1_DES_ADDR */
    PDMA_SetTransferAddr(PDMA, 1, (uint32_t)NUCODEGEN_PDMA_CH1_SRC_ADDR, NUCODEGEN_PDMA_CH1_SRC_TYPE, (uint32_t)NUCODEGEN_PDMA_CH1_DES_ADDR, NUCODEGEN_PDMA_CH1_DES_TYPE);

    /* Set transfer mode and burst size */
    PDMA_SetBurstType(PDMA, 1, NUCODEGEN_PDMA_CH1_MODE, NUCODEGEN_PDMA_CH1_BURST_SIZE);

    /* Enable timeout function and set timeout counter */
    PDMA_SetTimeOut(PDMA, 1, NUCODEGEN_PDMA_CH1_TMOUT, NUCODEGEN_PDMA_CH1_TMOUT_CNT);
    #if(NUCODEGEN_PDMA_CH1_STRIDE_EN)
    /* Set stride function */
    PDMA_SetStride(PDMA, 1, NUCODEGEN_PDMA_CH1_STRIDE_DES_LENGTH, NUCODEGEN_PDMA_CH1_STRIDE_SRC_LENGTH, NUCODEGEN_PDMA_CH1_STRIDE_CNT);
    #endif

    /* Request source is NUCODEGEN_PDMA_CH1_SRC_DES_SEL */
    PDMA_SetTransferMode(PDMA, 1, NUCODEGEN_PDMA_CH1_SRC_DES_SEL, 0, 0);
#else   //NUCODEGEN_PDMA_CH1_OPMODE_S == PDMA_OP_SCATTER
    /* Open CH1 */
    PDMA_Open(PDMA, 1 << 1);

    DMA_DESC_CH1[0].u32Ctl =
        (((uint32_t)PDMA_CH1_DATA_LENGTH_TB0 - 1) << PDMA_DSCT_CTL_TXCNT_Pos) | /* Set transfer count */ \
        NUCODEGEN_PDMA_CH1_WIDTH_TB0 |   /* Set transfer width */ \
        NUCODEGEN_PDMA_CH1_SRC_TYPE_TB0 |    /* Set source increment type */ \
        NUCODEGEN_PDMA_CH1_DES_TYPE_TB0 |    /* Set destination increment type */ \
        NUCODEGEN_PDMA_CH1_MODE_TB0 |  /* Set transfer type */ \
        NUCODEGEN_PDMA_CH1_BURST_SIZE_TB0 |  /* Set burst size */ \
        NUCODEGEN_PDMA_CH1_TB0_INT_EN |   /* Set table empty interrupt */ \
        NUCODEGEN_PDMA_CH1_OPMODE_TB0;  /* Set operation mode */

    /* Configure source address */
    DMA_DESC_CH1[0].u32Src = (uint32_t)NUCODEGEN_PDMA_CH1_SRC_ADDR_TB0;

    /* Configure destination address */
    DMA_DESC_CH1[0].u32Dest = (uint32_t)NUCODEGEN_PDMA_CH1_DES_ADDR_TB0;

	#if(NUCODEGEN_PDMA_CH1_OPMODE_TB0_S==NUCODEGEN_PDMA_OP_BASIC)
    /* Configure next descriptor table address */
    DMA_DESC_CH1[0].u32Offset = 0; /* No next operation table. No effect in basic mode */
	#else
    /* Configure next descriptor table address */
    DMA_DESC_CH1[0].u32Offset = (uint32_t)&DMA_DESC_CH1[1] - (PDMA->SCATBA); /* next descriptor table is table 1 */
    #endif
    #if(NUCODEGEN_PDMA_CH1_OPMODE_TB0_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_CH1[1].u32Ctl =
        (((uint32_t)PDMA_CH1_DATA_LENGTH_TB1 - 1) << PDMA_DSCT_CTL_TXCNT_Pos) | /* Set transfer count */ \
        NUCODEGEN_PDMA_CH1_WIDTH_TB1 |   /* Set transfer width */ \
        NUCODEGEN_PDMA_CH1_SRC_TYPE_TB1 |    /* Set source increment type */ \
        NUCODEGEN_PDMA_CH1_DES_TYPE_TB1 |    /* Set destination increment type */ \
        NUCODEGEN_PDMA_CH1_MODE_TB1 |  /* Set transfer type */ \
        NUCODEGEN_PDMA_CH1_BURST_SIZE_TB1 |  /* Set burst size */ \
        NUCODEGEN_PDMA_CH1_TB1_INT_EN |   /* Set table empty interrupt */ \
        NUCODEGEN_PDMA_CH1_OPMODE_TB1;  /* Set operation mode */

    /* Configure source address */
    DMA_DESC_CH1[1].u32Src = (uint32_t)NUCODEGEN_PDMA_CH1_SRC_ADDR_TB1;

    /* Configure destination address */
    DMA_DESC_CH1[1].u32Dest = (uint32_t)NUCODEGEN_PDMA_CH1_DES_ADDR_TB1;
	#if(NUCODEGEN_PDMA_CH1_OPMODE_TB1_S==NUCODEGEN_PDMA_OP_BASIC)
    /* Configure next descriptor table address */
    DMA_DESC_CH1[1].u32Offset = 0; /* No next operation table. No effect in basic mode */
	#else
    /* Configure next descriptor table address */
    DMA_DESC_CH1[1].u32Offset = (uint32_t)&DMA_DESC_CH1[2] - (PDMA->SCATBA); /* next descriptor table is table 2 */
	#endif
    #endif
    #if(NUCODEGEN_PDMA_CH1_OPMODE_TB1_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_CH1[2].u32Ctl =
        (((uint32_t)PDMA_CH1_DATA_LENGTH_TB2 - 1) << PDMA_DSCT_CTL_TXCNT_Pos) | /* Set transfer count */ \
        NUCODEGEN_PDMA_CH1_WIDTH_TB2 |   /* Set transfer width */ \
        NUCODEGEN_PDMA_CH1_SRC_TYPE_TB2 |    /* Set source increment type */ \
        NUCODEGEN_PDMA_CH1_DES_TYPE_TB2 |    /* Set destination increment type */ \
        NUCODEGEN_PDMA_CH1_MODE_TB2 |  /* Set transfer type */ \
        NUCODEGEN_PDMA_CH1_BURST_SIZE_TB2 |  /* Set burst size */ \
        NUCODEGEN_PDMA_CH1_TB2_INT_EN |   /* Set table empty interrupt */ \
        NUCODEGEN_PDMA_CH1_OPMODE_TB2;  /* Set operation mode */

    /* Configure source address */
    DMA_DESC_CH1[2].u32Src = (uint32_t)NUCODEGEN_PDMA_CH1_SRC_ADDR_TB2;

    /* Configure destination address */
    DMA_DESC_CH1[2].u32Dest = (uint32_t)NUCODEGEN_PDMA_CH1_DES_ADDR_TB2;
    #if(NUCODEGEN_PDMA_CH1_OPMODE_TB2_S==NUCODEGEN_PDMA_OP_BASIC)
    /* Configure next descriptor table address */
    DMA_DESC_CH1[2].u32Offset = 0; /* No next operation table. No effect in basic mode */
	#else
    /* Configure next descriptor table address */
    DMA_DESC_CH1[2].u32Offset = (uint32_t)&DMA_DESC_CH1[3] - (PDMA->SCATBA); /* next descriptor table is table 3 */
	#endif
    #endif
    #if(NUCODEGEN_PDMA_CH1_OPMODE_TB2_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_CH1[3].u32Ctl =
        (((uint32_t)PDMA_CH1_DATA_LENGTH_TB3 - 1) << PDMA_DSCT_CTL_TXCNT_Pos) | /* Set transfer count */ \
        NUCODEGEN_PDMA_CH1_WIDTH_TB3 |   /* Set transfer width */ \
        NUCODEGEN_PDMA_CH1_SRC_TYPE_TB3 |    /* Set source increment type */ \
        NUCODEGEN_PDMA_CH1_DES_TYPE_TB3 |    /* Set destination increment type */ \
        NUCODEGEN_PDMA_CH1_MODE_TB3 |  /* Set transfer type */ \
        NUCODEGEN_PDMA_CH1_BURST_SIZE_TB3 |  /* Set burst size */ \
        NUCODEGEN_PDMA_CH1_TB3_INT_EN |   /* Set table empty interrupt */ \
        NUCODEGEN_PDMA_CH1_OPMODE_TB3;  /* Set operation mode */

    /* Configure source address */
    DMA_DESC_CH1[3].u32Src = (uint32_t)NUCODEGEN_PDMA_CH1_SRC_ADDR_TB3;

    /* Configure destination address */
    DMA_DESC_CH1[3].u32Dest = (uint32_t)NUCODEGEN_PDMA_CH1_DES_ADDR_TB3;

	#if(NUCODEGEN_PDMA_CH1_OPMODE_TB3_S==NUCODEGEN_PDMA_OP_BASIC)
    /* Configure next descriptor table address */
    DMA_DESC_CH1[3].u32Offset = 0; /* No next operation table. No effect in basic mode */
	#else
    /* Configure next descriptor table address */
    DMA_DESC_CH1[3].u32Offset = (uint32_t)&DMA_DESC_CH1[4] - (PDMA->SCATBA); /* next descriptor table is table 4 */
	#endif
    #endif
    #if(NUCODEGEN_PDMA_CH1_OPMODE_TB3_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_CH1[4].u32Ctl =
        (((uint32_t)PDMA_CH1_DATA_LENGTH_TB4 - 1) << PDMA_DSCT_CTL_TXCNT_Pos) | /* Set transfer count */ \
        NUCODEGEN_PDMA_CH1_WIDTH_TB4 |   /* Set transfer width */ \
        NUCODEGEN_PDMA_CH1_SRC_TYPE_TB4 |    /* Set source increment type */ \
        NUCODEGEN_PDMA_CH1_DES_TYPE_TB4 |    /* Set destination increment type */ \
        NUCODEGEN_PDMA_CH1_MODE_TB4 |  /* Set transfer type */ \
        NUCODEGEN_PDMA_CH1_BURST_SIZE_TB4 |  /* Set burst size */ \
        NUCODEGEN_PDMA_CH1_TB4_INT_EN |   /* Set table empty interrupt */ \
        NUCODEGEN_PDMA_CH1_OPMODE_TB4;  /* Set operation mode */

    /* Configure source address */
    DMA_DESC_CH1[4].u32Src = (uint32_t)NUCODEGEN_PDMA_CH1_SRC_ADDR_TB4;

    /* Configure destination address */
    DMA_DESC_CH1[4].u32Dest = (uint32_t)NUCODEGEN_PDMA_CH1_DES_ADDR_TB4;

    /* Configure next descriptor table address */
    DMA_DESC_CH1[4].u32Offset = (uint32_t)&DMA_DESC_CH1[5] - (PDMA->SCATBA); /* next descriptor table is table 5 */
    #endif

    #if(NUCODEGEN_PDMA_CH1_TMOUT)
    /* Enable timeout function and set timeout counter */
    PDMA_SetTimeOut(PDMA, 1, NUCODEGEN_PDMA_CH1_TMOUT, NUCODEGEN_PDMA_CH1_TMOUT_CNT);
    #endif

    #if(NUCODEGEN_PDMA_CH1_STRIDE_EN)
    /* Set stride function */
    PDMA_SetStride(PDMA, 1, NUCODEGEN_PDMA_CH1_STRIDE_DES_LENGTH, NUCODEGEN_PDMA_CH1_STRIDE_SRC_LENGTH, NUCODEGEN_PDMA_CH1_STRIDE_CNT);
    #endif

    /* Request source is NUCODEGEN_PDMA_CH1_SRC_DES_SEL */
    PDMA_SetTransferMode(PDMA, 1, NUCODEGEN_PDMA_CH1_SRC_DES_SEL, 1, (uint32_t)&DMA_DESC_CH1[0]);
#endif  //NUCODEGEN_PDMA_CH1_OPMODE == PDMA_OP_BASIC
#endif  //NUCODEGEN_PDMA_CH1_FUNC

#if (NUCODEGEN_PDMA_CH2)
#if (NUCODEGEN_PDMA_CH2_OPMODE_S == NUCODEGEN_PDMA_OP_BASIC)
    /* Open CH2 */
    PDMA_Open(PDMA, 1 << 2);

    /* Transfer count is PDMA_CH2_DATA_LENGTH, transfer width is NUCODEGEN_PDMA_CH2_WIDTH */
    PDMA_SetTransferCnt(PDMA, 2, NUCODEGEN_PDMA_CH2_WIDTH, PDMA_CH2_DATA_LENGTH);

    /* Set source address is NUCODEGEN_PDMA_CH2_SRC_ADDR, destination address is NUCODEGEN_PDMA_CH2_DES_ADDR */
    PDMA_SetTransferAddr(PDMA, 2, (uint32_t)NUCODEGEN_PDMA_CH2_SRC_ADDR, NUCODEGEN_PDMA_CH2_SRC_TYPE, (uint32_t)NUCODEGEN_PDMA_CH2_DES_ADDR, NUCODEGEN_PDMA_CH2_DES_TYPE);

    /* Set transfer mode and burst size */
    PDMA_SetBurstType(PDMA, 2, NUCODEGEN_PDMA_CH2_MODE, NUCODEGEN_PDMA_CH2_BURST_SIZE);

    #if(NUCODEGEN_PDMA_CH2_TMOUT)
    /* Enable timeout function and set timeout counter */
    PDMA_SetTimeOut(PDMA, 2, NUCODEGEN_PDMA_CH2_TMOUT, NUCODEGEN_PDMA_CH2_TMOUT_CNT);
    #endif

    #if(NUCODEGEN_PDMA_CH2_STRIDE_EN)
    /* Set stride function */
    PDMA_SetStride(PDMA, 2, NUCODEGEN_PDMA_CH2_STRIDE_DES_LENGTH, NUCODEGEN_PDMA_CH2_STRIDE_SRC_LENGTH, NUCODEGEN_PDMA_CH2_STRIDE_CNT);
    #endif

    /* Request source is NUCODEGEN_PDMA_CH2_SRC_DES_SEL */
    PDMA_SetTransferMode(PDMA, 2, NUCODEGEN_PDMA_CH2_SRC_DES_SEL, 0, 0);
#else   //NUCODEGEN_PDMA_CH2_OPMODE_S == PDMA_OP_SCATTER
    /* Open CH2 */
    PDMA_Open(PDMA, 1 << 2);

    DMA_DESC_CH2[0].u32Ctl =
        (((uint32_t)PDMA_CH2_DATA_LENGTH_TB0 - 1) << PDMA_DSCT_CTL_TXCNT_Pos) | /* Set transfer count */ \
        NUCODEGEN_PDMA_CH2_WIDTH_TB0 |   /* Set transfer width */ \
        NUCODEGEN_PDMA_CH2_SRC_TYPE_TB0 |    /* Set source increment type */ \
        NUCODEGEN_PDMA_CH2_DES_TYPE_TB0 |    /* Set destination increment type */ \
        NUCODEGEN_PDMA_CH2_MODE_TB0 |  /* Set transfer type */ \
        NUCODEGEN_PDMA_CH2_BURST_SIZE_TB0 |  /* Set burst size */ \
        NUCODEGEN_PDMA_CH2_TB0_INT_EN |   /* Set table empty interrupt */ \
        NUCODEGEN_PDMA_CH2_OPMODE_TB0;  /* Set operation mode */

    /* Configure source address */
    DMA_DESC_CH2[0].u32Src = (uint32_t)NUCODEGEN_PDMA_CH2_SRC_ADDR_TB0;

    /* Configure destination address */
    DMA_DESC_CH2[0].u32Dest = (uint32_t)NUCODEGEN_PDMA_CH2_DES_ADDR_TB0;

	#if(NUCODEGEN_PDMA_CH2_OPMODE_TB0_S==NUCODEGEN_PDMA_OP_BASIC)
    /* Configure next descriptor table address */
    DMA_DESC_CH2[0].u32Offset = 0; /* No next operation table. No effect in basic mode */
	#else
    /* Configure next descriptor table address */
    DMA_DESC_CH2[0].u32Offset = (uint32_t)&DMA_DESC_CH2[1] - (PDMA->SCATBA); /* next descriptor table is table 1 */
    #endif
    #if(NUCODEGEN_PDMA_CH2_OPMODE_TB0_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_CH2[1].u32Ctl =
        (((uint32_t)PDMA_CH2_DATA_LENGTH_TB1 - 1) << PDMA_DSCT_CTL_TXCNT_Pos) | /* Set transfer count */ \
        NUCODEGEN_PDMA_CH2_WIDTH_TB1 |   /* Set transfer width */ \
        NUCODEGEN_PDMA_CH2_SRC_TYPE_TB1 |    /* Set source increment type */ \
        NUCODEGEN_PDMA_CH2_DES_TYPE_TB1 |    /* Set destination increment type */ \
        NUCODEGEN_PDMA_CH2_MODE_TB1 |  /* Set transfer type */ \
        NUCODEGEN_PDMA_CH2_BURST_SIZE_TB1 |  /* Set burst size */ \
        NUCODEGEN_PDMA_CH2_TB1_INT_EN |   /* Set table empty interrupt */ \
        NUCODEGEN_PDMA_CH2_OPMODE_TB1;  /* Set operation mode */

    /* Configure source address */
    DMA_DESC_CH2[1].u32Src = (uint32_t)NUCODEGEN_PDMA_CH2_SRC_ADDR_TB1;

    /* Configure destination address */
    DMA_DESC_CH2[1].u32Dest = (uint32_t)NUCODEGEN_PDMA_CH2_DES_ADDR_TB1;

	#if(NUCODEGEN_PDMA_CH2_OPMODE_TB1_S==NUCODEGEN_PDMA_OP_BASIC)
    /* Configure next descriptor table address */
    DMA_DESC_CH2[1].u32Offset = 0; /* No next operation table. No effect in basic mode */
	#else
    /* Configure next descriptor table address */
    DMA_DESC_CH2[1].u32Offset = (uint32_t)&DMA_DESC_CH2[2] - (PDMA->SCATBA); /* next descriptor table is table 2 */
    #endif
    #endif
    #if(NUCODEGEN_PDMA_CH2_OPMODE_TB1_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_CH2[2].u32Ctl =
        (((uint32_t)PDMA_CH2_DATA_LENGTH_TB2 - 1) << PDMA_DSCT_CTL_TXCNT_Pos) | /* Set transfer count */ \
        NUCODEGEN_PDMA_CH2_WIDTH_TB2 |   /* Set transfer width */ \
        NUCODEGEN_PDMA_CH2_SRC_TYPE_TB2 |    /* Set source increment type */ \
        NUCODEGEN_PDMA_CH2_DES_TYPE_TB2 |    /* Set destination increment type */ \
        NUCODEGEN_PDMA_CH2_MODE_TB2 |  /* Set transfer type */ \
        NUCODEGEN_PDMA_CH2_BURST_SIZE_TB2 |  /* Set burst size */ \
        NUCODEGEN_PDMA_CH2_TB2_INT_EN |   /* Set table empty interrupt */ \
        NUCODEGEN_PDMA_CH2_OPMODE_TB2;  /* Set operation mode */

    /* Configure source address */
    DMA_DESC_CH2[2].u32Src = (uint32_t)NUCODEGEN_PDMA_CH2_SRC_ADDR_TB2;

    /* Configure destination address */
    DMA_DESC_CH2[2].u32Dest = (uint32_t)NUCODEGEN_PDMA_CH2_DES_ADDR_TB2;

	#if(NUCODEGEN_PDMA_CH2_OPMODE_TB2_S==NUCODEGEN_PDMA_OP_BASIC)
    /* Configure next descriptor table address */
    DMA_DESC_CH2[2].u32Offset = 0; /* No next operation table. No effect in basic mode */
	#else
    /* Configure next descriptor table address */
    DMA_DESC_CH2[2].u32Offset = (uint32_t)&DMA_DESC_CH2[3] - (PDMA->SCATBA); /* next descriptor table is table 3 */
    #endif
    #endif
    #if(NUCODEGEN_PDMA_CH2_OPMODE_TB2_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_CH2[3].u32Ctl =
        (((uint32_t)PDMA_CH2_DATA_LENGTH_TB3 - 1) << PDMA_DSCT_CTL_TXCNT_Pos) | /* Set transfer count */ \
        NUCODEGEN_PDMA_CH2_WIDTH_TB3 |   /* Set transfer width */ \
        NUCODEGEN_PDMA_CH2_SRC_TYPE_TB3 |    /* Set source increment type */ \
        NUCODEGEN_PDMA_CH2_DES_TYPE_TB3 |    /* Set destination increment type */ \
        NUCODEGEN_PDMA_CH2_MODE_TB3 |  /* Set transfer type */ \
        NUCODEGEN_PDMA_CH2_BURST_SIZE_TB3 |  /* Set burst size */ \
        NUCODEGEN_PDMA_CH2_TB3_INT_EN |   /* Set table empty interrupt */ \
        NUCODEGEN_PDMA_CH2_OPMODE_TB3;  /* Set operation mode */

    /* Configure source address */
    DMA_DESC_CH2[3].u32Src = (uint32_t)NUCODEGEN_PDMA_CH2_SRC_ADDR_TB3;

    /* Configure destination address */
    DMA_DESC_CH2[3].u32Dest = (uint32_t)NUCODEGEN_PDMA_CH2_DES_ADDR_TB3;
	#if(NUCODEGEN_PDMA_CH2_OPMODE_TB3_S==NUCODEGEN_PDMA_OP_BASIC)
    /* Configure next descriptor table address */
    DMA_DESC_CH2[3].u32Offset = 0; /* No next operation table. No effect in basic mode */
	#else
    /* Configure next descriptor table address */
    DMA_DESC_CH2[3].u32Offset = (uint32_t)&DMA_DESC_CH2[4] - (PDMA->SCATBA); /* next descriptor table is table 4 */
    #endif
    #endif
    #if(NUCODEGEN_PDMA_CH2_OPMODE_TB3_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_CH2[4].u32Ctl =
        (((uint32_t)PDMA_CH2_DATA_LENGTH_TB4 - 1) << PDMA_DSCT_CTL_TXCNT_Pos) | /* Set transfer count */ \
        NUCODEGEN_PDMA_CH2_WIDTH_TB4 |   /* Set transfer width */ \
        NUCODEGEN_PDMA_CH2_SRC_TYPE_TB4 |    /* Set source increment type */ \
        NUCODEGEN_PDMA_CH2_DES_TYPE_TB4 |    /* Set destination increment type */ \
        NUCODEGEN_PDMA_CH2_MODE_TB4 |  /* Set transfer type */ \
        NUCODEGEN_PDMA_CH2_BURST_SIZE_TB4 |  /* Set burst size */ \
        NUCODEGEN_PDMA_CH2_TB4_INT_EN |   /* Set table empty interrupt */ \
        NUCODEGEN_PDMA_CH2_OPMODE_TB4;  /* Set operation mode */

    /* Configure source address */
    DMA_DESC_CH2[4].u32Src = (uint32_t)NUCODEGEN_PDMA_CH2_SRC_ADDR_TB4;

    /* Configure destination address */
    DMA_DESC_CH2[4].u32Dest = (uint32_t)NUCODEGEN_PDMA_CH2_DES_ADDR_TB4;

    /* Configure next descriptor table address */
    DMA_DESC_CH2[4].u32Offset = (uint32_t)&DMA_DESC_CH2[5] - (PDMA->SCATBA); /* next descriptor table is table 5 */
    #endif

    #if(NUCODEGEN_PDMA_CH2_TMOUT)
    /* Enable timeout function and set timeout counter */
    PDMA_SetTimeOut(PDMA, 2, NUCODEGEN_PDMA_CH2_TMOUT, NUCODEGEN_PDMA_CH2_TMOUT_CNT);
    #endif

    #if(NUCODEGEN_PDMA_CH2_STRIDE_EN)
    /* Set stride function */
    PDMA_SetStride(PDMA, 2, NUCODEGEN_PDMA_CH2_STRIDE_DES_LENGTH, NUCODEGEN_PDMA_CH2_STRIDE_SRC_LENGTH, NUCODEGEN_PDMA_CH2_STRIDE_CNT);
    #endif

    /* Request source is NUCODEGEN_PDMA_CH2_SRC_DES_SEL */
    PDMA_SetTransferMode(PDMA, 2, NUCODEGEN_PDMA_CH2_SRC_DES_SEL, 1, (uint32_t)&DMA_DESC_CH2[0]);
#endif  //NUCODEGEN_PDMA_CH2_OPMODE == PDMA_OP_BASIC
#endif  //NUCODEGEN_PDMA_CH2_FUNC

#if (NUCODEGEN_PDMA_CH3)
#if (NUCODEGEN_PDMA_CH3_OPMODE_S == NUCODEGEN_PDMA_OP_BASIC)
    /* Open CH3 */
    PDMA_Open(PDMA, 1 << 3);

    /* Transfer count is PDMA_CH3_DATA_LENGTH, transfer width is NUCODEGEN_PDMA_CH3_WIDTH */
    PDMA_SetTransferCnt(PDMA, 3, NUCODEGEN_PDMA_CH3_WIDTH, PDMA_CH3_DATA_LENGTH);

    /* Set source address is NUCODEGEN_PDMA_CH3_SRC_ADDR, destination address is NUCODEGEN_PDMA_CH3_DES_ADDR */
    PDMA_SetTransferAddr(PDMA, 3, (uint32_t)NUCODEGEN_PDMA_CH3_SRC_ADDR, NUCODEGEN_PDMA_CH3_SRC_TYPE, (uint32_t)NUCODEGEN_PDMA_CH3_DES_ADDR, NUCODEGEN_PDMA_CH3_DES_TYPE);

    /* Set transfer mode and burst size */
    PDMA_SetBurstType(PDMA, 3, NUCODEGEN_PDMA_CH3_MODE, NUCODEGEN_PDMA_CH3_BURST_SIZE);

    #if(NUCODEGEN_PDMA_CH3_TMOUT)
    /* Enable timeout function and set timeout counter */
    PDMA_SetTimeOut(PDMA, 3, NUCODEGEN_PDMA_CH3_TMOUT, NUCODEGEN_PDMA_CH3_TMOUT_CNT);
    #endif

    #if(NUCODEGEN_PDMA_CH3_STRIDE_EN)
    /* Set stride function */
    PDMA_SetStride(PDMA, 3, NUCODEGEN_PDMA_CH3_STRIDE_DES_LENGTH, NUCODEGEN_PDMA_CH3_STRIDE_SRC_LENGTH, NUCODEGEN_PDMA_CH3_STRIDE_CNT);
    #endif

    /* Request source is NUCODEGEN_PDMA_CH3_SRC_DES_SEL */
    PDMA_SetTransferMode(PDMA, 3, NUCODEGEN_PDMA_CH3_SRC_DES_SEL, 0, 0);
#else   //NUCODEGEN_PDMA_CH3_OPMODE_S == PDMA_OP_SCATTER
    /* Open CH3 */
    PDMA_Open(PDMA, 1 << 3);

    DMA_DESC_CH3[0].u32Ctl =
        (((uint32_t)PDMA_CH3_DATA_LENGTH_TB0 - 1) << PDMA_DSCT_CTL_TXCNT_Pos) | /* Set transfer count */ \
        NUCODEGEN_PDMA_CH3_WIDTH_TB0 |   /* Set transfer width */ \
        NUCODEGEN_PDMA_CH3_SRC_TYPE_TB0 |    /* Set source increment type */ \
        NUCODEGEN_PDMA_CH3_DES_TYPE_TB0 |    /* Set destination increment type */ \
        NUCODEGEN_PDMA_CH3_MODE_TB0 |  /* Set transfer type */ \
        NUCODEGEN_PDMA_CH3_BURST_SIZE_TB0 |  /* Set burst size */ \
        NUCODEGEN_PDMA_CH3_TB0_INT_EN |   /* Set table empty interrupt */ \
        NUCODEGEN_PDMA_CH3_OPMODE_TB0;  /* Set operation mode */

    /* Configure source address */
    DMA_DESC_CH3[0].u32Src = (uint32_t)NUCODEGEN_PDMA_CH3_SRC_ADDR_TB0;

    /* Configure destination address */
    DMA_DESC_CH3[0].u32Dest = (uint32_t)NUCODEGEN_PDMA_CH3_DES_ADDR_TB0;

    #if(NUCODEGEN_PDMA_CH3_OPMODE_TB0_S==NUCODEGEN_PDMA_OP_BASIC)
    /* Configure next descriptor table address */
    DMA_DESC_CH3[0].u32Offset = 0; /* No next operation table. No effect in basic mode */
	#else
    /* Configure next descriptor table address */
    DMA_DESC_CH3[0].u32Offset = (uint32_t)&DMA_DESC_CH3[1] - (PDMA->SCATBA); /* next descriptor table is table 1 */
    #endif
    #if(NUCODEGEN_PDMA_CH3_OPMODE_TB0_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_CH3[1].u32Ctl =
        (((uint32_t)PDMA_CH3_DATA_LENGTH_TB1 - 1) << PDMA_DSCT_CTL_TXCNT_Pos) | /* Set transfer count */ \
        NUCODEGEN_PDMA_CH3_WIDTH_TB1 |   /* Set transfer width */ \
        NUCODEGEN_PDMA_CH3_SRC_TYPE_TB1 |    /* Set source increment type */ \
        NUCODEGEN_PDMA_CH3_DES_TYPE_TB1 |    /* Set destination increment type */ \
        NUCODEGEN_PDMA_CH3_MODE_TB1 |  /* Set transfer type */ \
        NUCODEGEN_PDMA_CH3_BURST_SIZE_TB1 |  /* Set burst size */ \
        NUCODEGEN_PDMA_CH3_TB1_INT_EN |   /* Set table empty interrupt */ \
        NUCODEGEN_PDMA_CH3_OPMODE_TB1;  /* Set operation mode */

    /* Configure source address */
    DMA_DESC_CH3[1].u32Src = (uint32_t)NUCODEGEN_PDMA_CH3_SRC_ADDR_TB1;

    /* Configure destination address */
    DMA_DESC_CH3[1].u32Dest = (uint32_t)NUCODEGEN_PDMA_CH3_DES_ADDR_TB1;

    #if(NUCODEGEN_PDMA_CH3_OPMODE_TB1_S==NUCODEGEN_PDMA_OP_BASIC)
    /* Configure next descriptor table address */
    DMA_DESC_CH3[1].u32Offset = 0; /* No next operation table. No effect in basic mode */
	#else
    /* Configure next descriptor table address */
    DMA_DESC_CH3[1].u32Offset = (uint32_t)&DMA_DESC_CH3[2] - (PDMA->SCATBA); /* next descriptor table is table 2 */
    #endif
    #endif
    #if(NUCODEGEN_PDMA_CH3_OPMODE_TB1_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_CH3[2].u32Ctl =
        (((uint32_t)PDMA_CH3_DATA_LENGTH_TB2 - 1) << PDMA_DSCT_CTL_TXCNT_Pos) | /* Set transfer count */ \
        NUCODEGEN_PDMA_CH3_WIDTH_TB2 |   /* Set transfer width */ \
        NUCODEGEN_PDMA_CH3_SRC_TYPE_TB2 |    /* Set source increment type */ \
        NUCODEGEN_PDMA_CH3_DES_TYPE_TB2 |    /* Set destination increment type */ \
        NUCODEGEN_PDMA_CH3_MODE_TB2 |  /* Set transfer type */ \
        NUCODEGEN_PDMA_CH3_BURST_SIZE_TB2 |  /* Set burst size */ \
        NUCODEGEN_PDMA_CH3_TB2_INT_EN |   /* Set table empty interrupt */ \
        NUCODEGEN_PDMA_CH3_OPMODE_TB2;  /* Set operation mode */

    /* Configure source address */
    DMA_DESC_CH3[2].u32Src = (uint32_t)NUCODEGEN_PDMA_CH3_SRC_ADDR_TB2;

    /* Configure destination address */
    DMA_DESC_CH3[2].u32Dest = (uint32_t)NUCODEGEN_PDMA_CH3_DES_ADDR_TB2;

    #if(NUCODEGEN_PDMA_CH3_OPMODE_TB2_S==NUCODEGEN_PDMA_OP_BASIC)
    /* Configure next descriptor table address */
    DMA_DESC_CH3[2].u32Offset = 0; /* No next operation table. No effect in basic mode */
	#else
    /* Configure next descriptor table address */
    DMA_DESC_CH3[2].u32Offset = (uint32_t)&DMA_DESC_CH3[3] - (PDMA->SCATBA); /* next descriptor table is table 3 */
    #endif
	#endif
    #if(NUCODEGEN_PDMA_CH3_OPMODE_TB2_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_CH3[3].u32Ctl =
        (((uint32_t)PDMA_CH3_DATA_LENGTH_TB3 - 1) << PDMA_DSCT_CTL_TXCNT_Pos) | /* Set transfer count */ \
        NUCODEGEN_PDMA_CH3_WIDTH_TB3 |   /* Set transfer width */ \
        NUCODEGEN_PDMA_CH3_SRC_TYPE_TB3 |    /* Set source increment type */ \
        NUCODEGEN_PDMA_CH3_DES_TYPE_TB3 |    /* Set destination increment type */ \
        NUCODEGEN_PDMA_CH3_MODE_TB3 |  /* Set transfer type */ \
        NUCODEGEN_PDMA_CH3_BURST_SIZE_TB3 |  /* Set burst size */ \
        NUCODEGEN_PDMA_CH3_TB3_INT_EN |   /* Set table empty interrupt */ \
        NUCODEGEN_PDMA_CH3_OPMODE_TB3;  /* Set operation mode */

    /* Configure source address */
    DMA_DESC_CH3[3].u32Src = (uint32_t)NUCODEGEN_PDMA_CH3_SRC_ADDR_TB3;

    /* Configure destination address */
    DMA_DESC_CH3[3].u32Dest = (uint32_t)NUCODEGEN_PDMA_CH3_DES_ADDR_TB3;

    #if(NUCODEGEN_PDMA_CH3_OPMODE_TB3_S==NUCODEGEN_PDMA_OP_BASIC)
    /* Configure next descriptor table address */
    DMA_DESC_CH3[3].u32Offset = 0; /* No next operation table. No effect in basic mode */
	#else
    /* Configure next descriptor table address */
    DMA_DESC_CH3[3].u32Offset = (uint32_t)&DMA_DESC_CH3[4] - (PDMA->SCATBA); /* next descriptor table is table 4 */
    #endif
	#endif
    #if(NUCODEGEN_PDMA_CH3_OPMODE_TB3_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_CH3[4].u32Ctl =
        (((uint32_t)PDMA_CH3_DATA_LENGTH_TB4 - 1) << PDMA_DSCT_CTL_TXCNT_Pos) | /* Set transfer count */ \
        NUCODEGEN_PDMA_CH3_WIDTH_TB4 |   /* Set transfer width */ \
        NUCODEGEN_PDMA_CH3_SRC_TYPE_TB4 |    /* Set source increment type */ \
        NUCODEGEN_PDMA_CH3_DES_TYPE_TB4 |    /* Set destination increment type */ \
        NUCODEGEN_PDMA_CH3_MODE_TB4 |  /* Set transfer type */ \
        NUCODEGEN_PDMA_CH3_BURST_SIZE_TB4 |  /* Set burst size */ \
        NUCODEGEN_PDMA_CH3_TB4_INT_EN |   /* Set table empty interrupt */ \
        NUCODEGEN_PDMA_CH3_OPMODE_TB4;  /* Set operation mode */

    /* Configure source address */
    DMA_DESC_CH3[4].u32Src = (uint32_t)NUCODEGEN_PDMA_CH3_SRC_ADDR_TB4;

    /* Configure destination address */
    DMA_DESC_CH3[4].u32Dest = (uint32_t)NUCODEGEN_PDMA_CH3_DES_ADDR_TB4;

    /* Configure next descriptor table address */
    DMA_DESC_CH3[4].u32Offset = (uint32_t)&DMA_DESC_CH3[5] - (PDMA->SCATBA); /* next descriptor table is table 5 */
    #endif

    #if(NUCODEGEN_PDMA_CH3_TMOUT)
    /* Enable timeout function and set timeout counter */
    PDMA_SetTimeOut(PDMA, 3, NUCODEGEN_PDMA_CH3_TMOUT, NUCODEGEN_PDMA_CH3_TMOUT_CNT);
    #endif

    #if(NUCODEGEN_PDMA_CH3_STRIDE_EN)
    /* Set stride function */
    PDMA_SetStride(PDMA, 3, NUCODEGEN_PDMA_CH3_STRIDE_DES_LENGTH, NUCODEGEN_PDMA_CH3_STRIDE_SRC_LENGTH, NUCODEGEN_PDMA_CH3_STRIDE_CNT);
    #endif

    /* Request source is NUCODEGEN_PDMA_CH3_SRC_DES_SEL */
    PDMA_SetTransferMode(PDMA, 3, NUCODEGEN_PDMA_CH3_SRC_DES_SEL, 1, (uint32_t)&DMA_DESC_CH3[0]);
#endif  //NUCODEGEN_PDMA_CH3_OPMODE == PDMA_OP_BASIC
#endif  //NUCODEGEN_PDMA_CH3_FUNC

#if (NUCODEGEN_PDMA_CH4)
#if (NUCODEGEN_PDMA_CH4_OPMODE_S == NUCODEGEN_PDMA_OP_BASIC)
    /* Open CH4 */
    PDMA_Open(PDMA, 1 << 4);

    /* Transfer count is PDMA_CH4_DATA_LENGTH, transfer width is NUCODEGEN_PDMA_CH4_WIDTH */
    PDMA_SetTransferCnt(PDMA, 4, NUCODEGEN_PDMA_CH4_WIDTH, PDMA_CH4_DATA_LENGTH);

    /* Set source address is NUCODEGEN_PDMA_CH4_SRC_ADDR, destination address is NUCODEGEN_PDMA_CH4_DES_ADDR */
    PDMA_SetTransferAddr(PDMA, 4, (uint32_t)NUCODEGEN_PDMA_CH4_SRC_ADDR, NUCODEGEN_PDMA_CH4_SRC_TYPE, (uint32_t)NUCODEGEN_PDMA_CH4_DES_ADDR, NUCODEGEN_PDMA_CH4_DES_TYPE);

    /* Set transfer mode and burst size */
    PDMA_SetBurstType(PDMA, 4, NUCODEGEN_PDMA_CH4_MODE, NUCODEGEN_PDMA_CH4_BURST_SIZE);

    #if(NUCODEGEN_PDMA_CH4_TMOUT)
    /* Enable timeout function and set timeout counter */
    PDMA_SetTimeOut(PDMA, 4, NUCODEGEN_PDMA_CH4_TMOUT, NUCODEGEN_PDMA_CH4_TMOUT_CNT);
    #endif

    #if(NUCODEGEN_PDMA_CH4_STRIDE_EN)
    /* Set stride function */
    PDMA_SetStride(PDMA, 4, NUCODEGEN_PDMA_CH4_STRIDE_DES_LENGTH, NUCODEGEN_PDMA_CH4_STRIDE_SRC_LENGTH, NUCODEGEN_PDMA_CH4_STRIDE_CNT);
    #endif

    /* Request source is NUCODEGEN_PDMA_CH4_SRC_DES_SEL */
    PDMA_SetTransferMode(PDMA, 4, NUCODEGEN_PDMA_CH4_SRC_DES_SEL, 0, 0);
#else   //NUCODEGEN_PDMA_CH4_OPMODE_S == PDMA_OP_SCATTER
    /* Open CH4 */
    PDMA_Open(PDMA, 1 << 4);

    DMA_DESC_CH4[0].u32Ctl =
        (((uint32_t)PDMA_CH4_DATA_LENGTH_TB0 - 1) << PDMA_DSCT_CTL_TXCNT_Pos) | /* Set transfer count */ \
        NUCODEGEN_PDMA_CH4_WIDTH_TB0 |   /* Set transfer width */ \
        NUCODEGEN_PDMA_CH4_SRC_TYPE_TB0 |    /* Set source increment type */ \
        NUCODEGEN_PDMA_CH4_DES_TYPE_TB0 |    /* Set destination increment type */ \
        NUCODEGEN_PDMA_CH4_MODE_TB0 |  /* Set transfer type */ \
        NUCODEGEN_PDMA_CH4_BURST_SIZE_TB0 |  /* Set burst size */ \
        NUCODEGEN_PDMA_CH4_TB0_INT_EN |   /* Set table empty interrupt */ \
        NUCODEGEN_PDMA_CH4_OPMODE_TB0;  /* Set operation mode */

    /* Configure source address */
    DMA_DESC_CH4[0].u32Src = (uint32_t)NUCODEGEN_PDMA_CH4_SRC_ADDR_TB0;

    /* Configure destination address */
    DMA_DESC_CH4[0].u32Dest = (uint32_t)NUCODEGEN_PDMA_CH4_DES_ADDR_TB0;

    #if(NUCODEGEN_PDMA_CH4_OPMODE_TB0_S==NUCODEGEN_PDMA_OP_BASIC)
    /* Configure next descriptor table address */
    DMA_DESC_CH4[0].u32Offset = 0; /* No next operation table. No effect in basic mode */
	#else
    /* Configure next descriptor table address */
    DMA_DESC_CH4[0].u32Offset = (uint32_t)&DMA_DESC_CH4[1] - (PDMA->SCATBA); /* next descriptor table is table 1 */
    #endif
    #if(NUCODEGEN_PDMA_CH4_OPMODE_TB0_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_CH4[1].u32Ctl =
        (((uint32_t)PDMA_CH4_DATA_LENGTH_TB1 - 1) << PDMA_DSCT_CTL_TXCNT_Pos) | /* Set transfer count */ \
        NUCODEGEN_PDMA_CH4_WIDTH_TB1 |   /* Set transfer width */ \
        NUCODEGEN_PDMA_CH4_SRC_TYPE_TB1 |    /* Set source increment type */ \
        NUCODEGEN_PDMA_CH4_DES_TYPE_TB1 |    /* Set destination increment type */ \
        NUCODEGEN_PDMA_CH4_MODE_TB1 |  /* Set transfer type */ \
        NUCODEGEN_PDMA_CH4_BURST_SIZE_TB1 |  /* Set burst size */ \
        NUCODEGEN_PDMA_CH4_TB1_INT_EN |   /* Set table empty interrupt */ \
        NUCODEGEN_PDMA_CH4_OPMODE_TB1;  /* Set operation mode */

    /* Configure source address */
    DMA_DESC_CH4[1].u32Src = (uint32_t)NUCODEGEN_PDMA_CH4_SRC_ADDR_TB1;

    /* Configure destination address */
    DMA_DESC_CH4[1].u32Dest = (uint32_t)NUCODEGEN_PDMA_CH4_DES_ADDR_TB1;

    #if(NUCODEGEN_PDMA_CH4_OPMODE_TB1_S==NUCODEGEN_PDMA_OP_BASIC)
    /* Configure next descriptor table address */
    DMA_DESC_CH4[1].u32Offset = 0; /* No next operation table. No effect in basic mode */
	#else
    /* Configure next descriptor table address */
    DMA_DESC_CH4[1].u32Offset = (uint32_t)&DMA_DESC_CH4[2] - (PDMA->SCATBA); /* next descriptor table is table 2 */
    #endif
    #endif
    #if(NUCODEGEN_PDMA_CH4_OPMODE_TB1_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_CH4[2].u32Ctl =
        (((uint32_t)PDMA_CH4_DATA_LENGTH_TB2 - 1) << PDMA_DSCT_CTL_TXCNT_Pos) | /* Set transfer count */ \
        NUCODEGEN_PDMA_CH4_WIDTH_TB2 |   /* Set transfer width */ \
        NUCODEGEN_PDMA_CH4_SRC_TYPE_TB2 |    /* Set source increment type */ \
        NUCODEGEN_PDMA_CH4_DES_TYPE_TB2 |    /* Set destination increment type */ \
        NUCODEGEN_PDMA_CH4_MODE_TB2 |  /* Set transfer type */ \
        NUCODEGEN_PDMA_CH4_BURST_SIZE_TB2 |  /* Set burst size */ \
        NUCODEGEN_PDMA_CH4_TB2_INT_EN |   /* Set table empty interrupt */ \
        NUCODEGEN_PDMA_CH4_OPMODE_TB2;  /* Set operation mode */

    /* Configure source address */
    DMA_DESC_CH4[2].u32Src = (uint32_t)NUCODEGEN_PDMA_CH4_SRC_ADDR_TB2;

    /* Configure destination address */
    DMA_DESC_CH4[2].u32Dest = (uint32_t)NUCODEGEN_PDMA_CH4_DES_ADDR_TB2;

    #if(NUCODEGEN_PDMA_CH4_OPMODE_TB2_S==NUCODEGEN_PDMA_OP_BASIC)
    /* Configure next descriptor table address */
    DMA_DESC_CH4[2].u32Offset = 0; /* No next operation table. No effect in basic mode */
	#else
    /* Configure next descriptor table address */
    DMA_DESC_CH4[2].u32Offset = (uint32_t)&DMA_DESC_CH4[3] - (PDMA->SCATBA); /* next descriptor table is table 3 */
    #endif
    #endif
    #if(NUCODEGEN_PDMA_CH4_OPMODE_TB2_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_CH4[3].u32Ctl =
        (((uint32_t)PDMA_CH4_DATA_LENGTH_TB3 - 1) << PDMA_DSCT_CTL_TXCNT_Pos) | /* Set transfer count */ \
        NUCODEGEN_PDMA_CH4_WIDTH_TB3 |   /* Set transfer width */ \
        NUCODEGEN_PDMA_CH4_SRC_TYPE_TB3 |    /* Set source increment type */ \
        NUCODEGEN_PDMA_CH4_DES_TYPE_TB3 |    /* Set destination increment type */ \
        NUCODEGEN_PDMA_CH4_MODE_TB3 |  /* Set transfer type */ \
        NUCODEGEN_PDMA_CH4_BURST_SIZE_TB3 |  /* Set burst size */ \
        NUCODEGEN_PDMA_CH4_TB3_INT_EN |   /* Set table empty interrupt */ \
        NUCODEGEN_PDMA_CH4_OPMODE_TB3;  /* Set operation mode */

    /* Configure source address */
    DMA_DESC_CH4[3].u32Src = (uint32_t)NUCODEGEN_PDMA_CH4_SRC_ADDR_TB3;

    /* Configure destination address */
    DMA_DESC_CH4[3].u32Dest = (uint32_t)NUCODEGEN_PDMA_CH4_DES_ADDR_TB3;

    #if(NUCODEGEN_PDMA_CH4_OPMODE_TB3_S==NUCODEGEN_PDMA_OP_BASIC)
    /* Configure next descriptor table address */
    DMA_DESC_CH4[3].u32Offset = 0; /* No next operation table. No effect in basic mode */
	#else
    /* Configure next descriptor table address */
    DMA_DESC_CH4[3].u32Offset = (uint32_t)&DMA_DESC_CH4[4] - (PDMA->SCATBA); /* next descriptor table is table 4 */
    #endif
    #endif
    #if(NUCODEGEN_PDMA_CH4_OPMODE_TB3_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_CH4[4].u32Ctl =
        (((uint32_t)PDMA_CH4_DATA_LENGTH_TB4 - 1) << PDMA_DSCT_CTL_TXCNT_Pos) | /* Set transfer count */ \
        NUCODEGEN_PDMA_CH4_WIDTH_TB4 |   /* Set transfer width */ \
        NUCODEGEN_PDMA_CH4_SRC_TYPE_TB4 |    /* Set source increment type */ \
        NUCODEGEN_PDMA_CH4_DES_TYPE_TB4 |    /* Set destination increment type */ \
        NUCODEGEN_PDMA_CH4_MODE_TB4 |  /* Set transfer type */ \
        NUCODEGEN_PDMA_CH4_BURST_SIZE_TB4 |  /* Set burst size */ \
        NUCODEGEN_PDMA_CH4_TB4_INT_EN |   /* Set table empty interrupt */ \
        NUCODEGEN_PDMA_CH4_OPMODE_TB4;  /* Set operation mode */

    /* Configure source address */
    DMA_DESC_CH4[4].u32Src = (uint32_t)NUCODEGEN_PDMA_CH4_SRC_ADDR_TB4;

    /* Configure destination address */
    DMA_DESC_CH4[4].u32Dest = (uint32_t)NUCODEGEN_PDMA_CH4_DES_ADDR_TB4;

    /* Configure next descriptor table address */
    DMA_DESC_CH4[4].u32Offset = (uint32_t)&DMA_DESC_CH4[5] - (PDMA->SCATBA); /* next descriptor table is table 5 */
    #endif

    #if(NUCODEGEN_PDMA_CH4_TMOUT)
    /* Enable timeout function and set timeout counter */
    PDMA_SetTimeOut(PDMA, 4, NUCODEGEN_PDMA_CH4_TMOUT, NUCODEGEN_PDMA_CH4_TMOUT_CNT);
    #endif

    #if(NUCODEGEN_PDMA_CH4_STRIDE_EN)
    /* Set stride function */
    PDMA_SetStride(PDMA, 4, NUCODEGEN_PDMA_CH4_STRIDE_DES_LENGTH, NUCODEGEN_PDMA_CH4_STRIDE_SRC_LENGTH, NUCODEGEN_PDMA_CH4_STRIDE_CNT);
    #endif

    /* Request source is NUCODEGEN_PDMA_CH4_SRC_DES_SEL */
    PDMA_SetTransferMode(PDMA, 4, NUCODEGEN_PDMA_CH4_SRC_DES_SEL, 1, (uint32_t)&DMA_DESC_CH4[0]);
#endif  //NUCODEGEN_PDMA_CH4_OPMODE == PDMA_OP_BASIC
#endif  //NUCODEGEN_PDMA_CH4_FUNC

#if (NUCODEGEN_PDMA_CH5)
#if (NUCODEGEN_PDMA_CH5_OPMODE_S == NUCODEGEN_PDMA_OP_BASIC)
    /* Open CH5 */
    PDMA_Open(PDMA, 1 << 5);

    /* Transfer count is PDMA_CH5_DATA_LENGTH, transfer width is NUCODEGEN_PDMA_CH5_WIDTH */
    PDMA_SetTransferCnt(PDMA, 5, NUCODEGEN_PDMA_CH5_WIDTH, PDMA_CH5_DATA_LENGTH);

    /* Set source address is NUCODEGEN_PDMA_CH5_SRC_ADDR, destination address is NUCODEGEN_PDMA_CH5_DES_ADDR */
    PDMA_SetTransferAddr(PDMA, 5, (uint32_t)NUCODEGEN_PDMA_CH5_SRC_ADDR, NUCODEGEN_PDMA_CH5_SRC_TYPE, (uint32_t)NUCODEGEN_PDMA_CH5_DES_ADDR, NUCODEGEN_PDMA_CH5_DES_TYPE);

    /* Set transfer mode and burst size */
    PDMA_SetBurstType(PDMA, 5, NUCODEGEN_PDMA_CH5_MODE, NUCODEGEN_PDMA_CH5_BURST_SIZE);

    #if(NUCODEGEN_PDMA_CH5_TMOUT)
    /* Enable timeout function and set timeout counter */
    PDMA_SetTimeOut(PDMA, 5, NUCODEGEN_PDMA_CH5_TMOUT, NUCODEGEN_PDMA_CH5_TMOUT_CNT);
    #endif

    #if(NUCODEGEN_PDMA_CH5_STRIDE_EN)
    /* Set stride function */
    PDMA_SetStride(PDMA, 5, NUCODEGEN_PDMA_CH5_STRIDE_DES_LENGTH, NUCODEGEN_PDMA_CH5_STRIDE_SRC_LENGTH, NUCODEGEN_PDMA_CH5_STRIDE_CNT);
    #endif

    /* Request source is NUCODEGEN_PDMA_CH5_SRC_DES_SEL */
    PDMA_SetTransferMode(PDMA, 5, NUCODEGEN_PDMA_CH5_SRC_DES_SEL, 0, 0);
#else   //NUCODEGEN_PDMA_CH5_OPMODE_S == PDMA_OP_SCATTER
    /* Open CH5 */
    PDMA_Open(PDMA, 1 << 5);

    DMA_DESC_CH5[0].u32Ctl =
        (((uint32_t)PDMA_CH5_DATA_LENGTH_TB0 - 1) << PDMA_DSCT_CTL_TXCNT_Pos) | /* Set transfer count */ \
        NUCODEGEN_PDMA_CH5_WIDTH_TB0 |   /* Set transfer width */ \
        NUCODEGEN_PDMA_CH5_SRC_TYPE_TB0 |    /* Set source increment type */ \
        NUCODEGEN_PDMA_CH5_DES_TYPE_TB0 |    /* Set destination increment type */ \
        NUCODEGEN_PDMA_CH5_MODE_TB0 |  /* Set transfer type */ \
        NUCODEGEN_PDMA_CH5_BURST_SIZE_TB0 |  /* Set burst size */ \
        NUCODEGEN_PDMA_CH5_TB0_INT_EN |   /* Set table empty interrupt */ \
        NUCODEGEN_PDMA_CH5_OPMODE_TB0;  /* Set operation mode */

    /* Configure source address */
    DMA_DESC_CH5[0].u32Src = (uint32_t)NUCODEGEN_PDMA_CH5_SRC_ADDR_TB0;

    /* Configure destination address */
    DMA_DESC_CH5[0].u32Dest = (uint32_t)NUCODEGEN_PDMA_CH5_DES_ADDR_TB0;

	#if(NUCODEGEN_PDMA_CH5_OPMODE_TB0_S==NUCODEGEN_PDMA_OP_BASIC)
    /* Configure next descriptor table address */
    DMA_DESC_CH5[0].u32Offset = 0; /* No next operation table. No effect in basic mode */
    #else
    /* Configure next descriptor table address */
    DMA_DESC_CH5[0].u32Offset = (uint32_t)&DMA_DESC_CH5[1] - (PDMA->SCATBA); /* next descriptor table is table 1 */
    #endif
    #if(NUCODEGEN_PDMA_CH5_OPMODE_TB0_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_CH5[1].u32Ctl =
        (((uint32_t)PDMA_CH5_DATA_LENGTH_TB1 - 1) << PDMA_DSCT_CTL_TXCNT_Pos) | /* Set transfer count */ \
        NUCODEGEN_PDMA_CH5_WIDTH_TB1 |   /* Set transfer width */ \
        NUCODEGEN_PDMA_CH5_SRC_TYPE_TB1 |    /* Set source increment type */ \
        NUCODEGEN_PDMA_CH5_DES_TYPE_TB1 |    /* Set destination increment type */ \
        NUCODEGEN_PDMA_CH5_MODE_TB1 |  /* Set transfer type */ \
        NUCODEGEN_PDMA_CH5_BURST_SIZE_TB1 |  /* Set burst size */ \
        NUCODEGEN_PDMA_CH5_TB1_INT_EN |   /* Set table empty interrupt */ \
        NUCODEGEN_PDMA_CH5_OPMODE_TB1;  /* Set operation mode */

    /* Configure source address */
    DMA_DESC_CH5[1].u32Src = (uint32_t)NUCODEGEN_PDMA_CH5_SRC_ADDR_TB1;

    /* Configure destination address */
    DMA_DESC_CH5[1].u32Dest = (uint32_t)NUCODEGEN_PDMA_CH5_DES_ADDR_TB1;
	#if(NUCODEGEN_PDMA_CH5_OPMODE_TB1_S==NUCODEGEN_PDMA_OP_BASIC)
    /* Configure next descriptor table address */
    DMA_DESC_CH5[1].u32Offset = 0; /* No next operation table. No effect in basic mode */
    #else
    /* Configure next descriptor table address */
    DMA_DESC_CH5[1].u32Offset = (uint32_t)&DMA_DESC_CH5[2] - (PDMA->SCATBA); /* next descriptor table is table 2 */
    #endif
    #endif
    #if(NUCODEGEN_PDMA_CH5_OPMODE_TB1_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_CH5[2].u32Ctl =
        (((uint32_t)PDMA_CH5_DATA_LENGTH_TB2 - 1) << PDMA_DSCT_CTL_TXCNT_Pos) | /* Set transfer count */ \
        NUCODEGEN_PDMA_CH5_WIDTH_TB2 |   /* Set transfer width */ \
        NUCODEGEN_PDMA_CH5_SRC_TYPE_TB2 |    /* Set source increment type */ \
        NUCODEGEN_PDMA_CH5_DES_TYPE_TB2 |    /* Set destination increment type */ \
        NUCODEGEN_PDMA_CH5_MODE_TB2 |  /* Set transfer type */ \
        NUCODEGEN_PDMA_CH5_BURST_SIZE_TB2 |  /* Set burst size */ \
        NUCODEGEN_PDMA_CH5_TB2_INT_EN |   /* Set table empty interrupt */ \
        NUCODEGEN_PDMA_CH5_OPMODE_TB2;  /* Set operation mode */

    /* Configure source address */
    DMA_DESC_CH5[2].u32Src = (uint32_t)NUCODEGEN_PDMA_CH5_SRC_ADDR_TB2;

    /* Configure destination address */
    DMA_DESC_CH5[2].u32Dest = (uint32_t)NUCODEGEN_PDMA_CH5_DES_ADDR_TB2;
	#if(NUCODEGEN_PDMA_CH5_OPMODE_TB2_S==NUCODEGEN_PDMA_OP_BASIC)
    /* Configure next descriptor table address */
    DMA_DESC_CH5[2].u32Offset = 0; /* No next operation table. No effect in basic mode */
    #else
    /* Configure next descriptor table address */
    DMA_DESC_CH5[2].u32Offset = (uint32_t)&DMA_DESC_CH5[3] - (PDMA->SCATBA); /* next descriptor table is table 3 */
    #endif
    #endif
    #if(NUCODEGEN_PDMA_CH5_OPMODE_TB2_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_CH5[3].u32Ctl =
        (((uint32_t)PDMA_CH5_DATA_LENGTH_TB3 - 1) << PDMA_DSCT_CTL_TXCNT_Pos) | /* Set transfer count */ \
        NUCODEGEN_PDMA_CH5_WIDTH_TB3 |   /* Set transfer width */ \
        NUCODEGEN_PDMA_CH5_SRC_TYPE_TB3 |    /* Set source increment type */ \
        NUCODEGEN_PDMA_CH5_DES_TYPE_TB3 |    /* Set destination increment type */ \
        NUCODEGEN_PDMA_CH5_MODE_TB3 |  /* Set transfer type */ \
        NUCODEGEN_PDMA_CH5_BURST_SIZE_TB3 |  /* Set burst size */ \
        NUCODEGEN_PDMA_CH5_TB3_INT_EN |   /* Set table empty interrupt */ \
        NUCODEGEN_PDMA_CH5_OPMODE_TB3;  /* Set operation mode */

    /* Configure source address */
    DMA_DESC_CH5[3].u32Src = (uint32_t)NUCODEGEN_PDMA_CH5_SRC_ADDR_TB3;

    /* Configure destination address */
    DMA_DESC_CH5[3].u32Dest = (uint32_t)NUCODEGEN_PDMA_CH5_DES_ADDR_TB3;

	#if(NUCODEGEN_PDMA_CH5_OPMODE_TB3_S==NUCODEGEN_PDMA_OP_BASIC)
    /* Configure next descriptor table address */
    DMA_DESC_CH5[3].u32Offset = 0; /* No next operation table. No effect in basic mode */
    #else
    /* Configure next descriptor table address */
    DMA_DESC_CH5[3].u32Offset = (uint32_t)&DMA_DESC_CH5[4] - (PDMA->SCATBA); /* next descriptor table is table 4 */
    #endif
    #endif
    #if(NUCODEGEN_PDMA_CH5_OPMODE_TB3_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_CH5[4].u32Ctl =
        (((uint32_t)PDMA_CH5_DATA_LENGTH_TB4 - 1) << PDMA_DSCT_CTL_TXCNT_Pos) | /* Set transfer count */ \
        NUCODEGEN_PDMA_CH5_WIDTH_TB4 |   /* Set transfer width */ \
        NUCODEGEN_PDMA_CH5_SRC_TYPE_TB4 |    /* Set source increment type */ \
        NUCODEGEN_PDMA_CH5_DES_TYPE_TB4 |    /* Set destination increment type */ \
        NUCODEGEN_PDMA_CH5_MODE_TB4 |  /* Set transfer type */ \
        NUCODEGEN_PDMA_CH5_BURST_SIZE_TB4 |  /* Set burst size */ \
        NUCODEGEN_PDMA_CH5_TB4_INT_EN |   /* Set table empty interrupt */ \
        NUCODEGEN_PDMA_CH5_OPMODE_TB4;  /* Set operation mode */

    /* Configure source address */
    DMA_DESC_CH5[4].u32Src = (uint32_t)NUCODEGEN_PDMA_CH5_SRC_ADDR_TB4;

    /* Configure destination address */
    DMA_DESC_CH5[4].u32Dest = (uint32_t)NUCODEGEN_PDMA_CH5_DES_ADDR_TB4;

    /* Configure next descriptor table address */
    DMA_DESC_CH5[4].u32Offset = (uint32_t)&DMA_DESC_CH5[5] - (PDMA->SCATBA); /* next descriptor table is table 5 */
    #endif

    #if(NUCODEGEN_PDMA_CH5_TMOUT)
    /* Enable timeout function and set timeout counter */
    PDMA_SetTimeOut(PDMA, 5, NUCODEGEN_PDMA_CH5_TMOUT, NUCODEGEN_PDMA_CH5_TMOUT_CNT);
    #endif

    #if(NUCODEGEN_PDMA_CH5_STRIDE_EN)
    /* Set stride function */
    PDMA_SetStride(PDMA, 5, NUCODEGEN_PDMA_CH5_STRIDE_DES_LENGTH, NUCODEGEN_PDMA_CH5_STRIDE_SRC_LENGTH, NUCODEGEN_PDMA_CH5_STRIDE_CNT);
    #endif

    /* Request source is NUCODEGEN_PDMA_CH5_SRC_DES_SEL */
    PDMA_SetTransferMode(PDMA, 5, NUCODEGEN_PDMA_CH5_SRC_DES_SEL, 1, (uint32_t)&DMA_DESC_CH5[0]);
#endif  //NUCODEGEN_PDMA_CH5_OPMODE == PDMA_OP_BASIC
#endif  //NUCODEGEN_PDMA_CH5_FUNC

#if (NUCODEGEN_PDMA_CH6)
#if (NUCODEGEN_PDMA_CH6_OPMODE_S == NUCODEGEN_PDMA_OP_BASIC)
    /* Open CH6 */
    PDMA_Open(PDMA, 1 << 6);

    /* Transfer count is PDMA_CH6_DATA_LENGTH, transfer width is NUCODEGEN_PDMA_CH6_WIDTH */
    PDMA_SetTransferCnt(PDMA, 6, NUCODEGEN_PDMA_CH6_WIDTH, PDMA_CH6_DATA_LENGTH);

    /* Set source address is NUCODEGEN_PDMA_CH6_SRC_ADDR, destination address is NUCODEGEN_PDMA_CH6_DES_ADDR */
    PDMA_SetTransferAddr(PDMA, 6, (uint32_t)NUCODEGEN_PDMA_CH6_SRC_ADDR, NUCODEGEN_PDMA_CH6_SRC_TYPE, (uint32_t)NUCODEGEN_PDMA_CH6_DES_ADDR, NUCODEGEN_PDMA_CH6_DES_TYPE);

    /* Set transfer mode and burst size */
    PDMA_SetBurstType(PDMA, 6, NUCODEGEN_PDMA_CH6_MODE, NUCODEGEN_PDMA_CH6_BURST_SIZE);

    #if(NUCODEGEN_PDMA_CH6_TMOUT)
    /* Enable timeout function and set timeout counter */
    PDMA_SetTimeOut(PDMA, 6, NUCODEGEN_PDMA_CH6_TMOUT, NUCODEGEN_PDMA_CH6_TMOUT_CNT);
    #endif

    #if(NUCODEGEN_PDMA_CH6_STRIDE_EN)
    /* Set stride function */
    PDMA_SetStride(PDMA, 6, NUCODEGEN_PDMA_CH6_STRIDE_DES_LENGTH, NUCODEGEN_PDMA_CH6_STRIDE_SRC_LENGTH, NUCODEGEN_PDMA_CH6_STRIDE_CNT);
    #endif

    /* Request source is NUCODEGEN_PDMA_CH6_SRC_DES_SEL */
    PDMA_SetTransferMode(PDMA, 6, NUCODEGEN_PDMA_CH6_SRC_DES_SEL, 0, 0);
#else   //NUCODEGEN_PDMA_CH6_OPMODE_S == PDMA_OP_SCATTER
    /* Open CH6 */
    PDMA_Open(PDMA, 1 << 6);

    DMA_DESC_CH6[0].u32Ctl =
        (((uint32_t)PDMA_CH6_DATA_LENGTH_TB0 - 1) << PDMA_DSCT_CTL_TXCNT_Pos) | /* Set transfer count */ \
        NUCODEGEN_PDMA_CH6_WIDTH_TB0 |   /* Set transfer width */ \
        NUCODEGEN_PDMA_CH6_SRC_TYPE_TB0 |    /* Set source increment type */ \
        NUCODEGEN_PDMA_CH6_DES_TYPE_TB0 |    /* Set destination increment type */ \
        NUCODEGEN_PDMA_CH6_MODE_TB0 |  /* Set transfer type */ \
        NUCODEGEN_PDMA_CH6_BURST_SIZE_TB0 |  /* Set burst size */ \
        NUCODEGEN_PDMA_CH6_TB0_INT_EN |   /* Set table empty interrupt */ \
        NUCODEGEN_PDMA_CH6_OPMODE_TB0;  /* Set operation mode */

    /* Configure source address */
    DMA_DESC_CH6[0].u32Src = (uint32_t)NUCODEGEN_PDMA_CH6_SRC_ADDR_TB0;

    /* Configure destination address */
    DMA_DESC_CH6[0].u32Dest = (uint32_t)NUCODEGEN_PDMA_CH6_DES_ADDR_TB0;

	#if(NUCODEGEN_PDMA_CH6_OPMODE_TB0_S==NUCODEGEN_PDMA_OP_BASIC)
    /* Configure next descriptor table address */
    DMA_DESC_CH6[0].u32Offset = 0; /* No next operation table. No effect in basic mode */
	#else
    /* Configure next descriptor table address */
    DMA_DESC_CH6[0].u32Offset = (uint32_t)&DMA_DESC_CH6[1] - (PDMA->SCATBA); /* next descriptor table is table 1 */
	#endif
    #if(NUCODEGEN_PDMA_CH6_OPMODE_TB0_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_CH6[1].u32Ctl =
        (((uint32_t)PDMA_CH6_DATA_LENGTH_TB1 - 1) << PDMA_DSCT_CTL_TXCNT_Pos) | /* Set transfer count */ \
        NUCODEGEN_PDMA_CH6_WIDTH_TB1 |   /* Set transfer width */ \
        NUCODEGEN_PDMA_CH6_SRC_TYPE_TB1 |    /* Set source increment type */ \
        NUCODEGEN_PDMA_CH6_DES_TYPE_TB1 |    /* Set destination increment type */ \
        NUCODEGEN_PDMA_CH6_MODE_TB1 |  /* Set transfer type */ \
        NUCODEGEN_PDMA_CH6_BURST_SIZE_TB1 |  /* Set burst size */ \
        NUCODEGEN_PDMA_CH6_TB1_INT_EN |   /* Set table empty interrupt */ \
        NUCODEGEN_PDMA_CH6_OPMODE_TB1;  /* Set operation mode */

    /* Configure source address */
    DMA_DESC_CH6[1].u32Src = (uint32_t)NUCODEGEN_PDMA_CH6_SRC_ADDR_TB1;

    /* Configure destination address */
    DMA_DESC_CH6[1].u32Dest = (uint32_t)NUCODEGEN_PDMA_CH6_DES_ADDR_TB1;
	#if(NUCODEGEN_PDMA_CH6_OPMODE_TB1_S==NUCODEGEN_PDMA_OP_BASIC)
    /* Configure next descriptor table address */
    DMA_DESC_CH6[1].u32Offset = 0; /* No next operation table. No effect in basic mode */
	#else
    /* Configure next descriptor table address */
    DMA_DESC_CH6[1].u32Offset = (uint32_t)&DMA_DESC_CH6[2] - (PDMA->SCATBA); /* next descriptor table is table 2 */
	#endif
    #endif
    #if(NUCODEGEN_PDMA_CH6_OPMODE_TB1_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_CH6[2].u32Ctl =
        (((uint32_t)PDMA_CH6_DATA_LENGTH_TB2 - 1) << PDMA_DSCT_CTL_TXCNT_Pos) | /* Set transfer count */ \
        NUCODEGEN_PDMA_CH6_WIDTH_TB2 |   /* Set transfer width */ \
        NUCODEGEN_PDMA_CH6_SRC_TYPE_TB2 |    /* Set source increment type */ \
        NUCODEGEN_PDMA_CH6_DES_TYPE_TB2 |    /* Set destination increment type */ \
        NUCODEGEN_PDMA_CH6_MODE_TB2 |  /* Set transfer type */ \
        NUCODEGEN_PDMA_CH6_BURST_SIZE_TB2 |  /* Set burst size */ \
        NUCODEGEN_PDMA_CH6_TB2_INT_EN |   /* Set table empty interrupt */ \
        NUCODEGEN_PDMA_CH6_OPMODE_TB2;  /* Set operation mode */

    /* Configure source address */
    DMA_DESC_CH6[2].u32Src = (uint32_t)NUCODEGEN_PDMA_CH6_SRC_ADDR_TB2;

    /* Configure destination address */
    DMA_DESC_CH6[2].u32Dest = (uint32_t)NUCODEGEN_PDMA_CH6_DES_ADDR_TB2;
	#if(NUCODEGEN_PDMA_CH6_OPMODE_TB2_S==NUCODEGEN_PDMA_OP_BASIC)
    /* Configure next descriptor table address */
    DMA_DESC_CH6[2].u32Offset = 0; /* No next operation table. No effect in basic mode */
	#else
    /* Configure next descriptor table address */
    DMA_DESC_CH6[2].u32Offset = (uint32_t)&DMA_DESC_CH6[3] - (PDMA->SCATBA); /* next descriptor table is table 3 */
	#endif
    #endif
    #if(NUCODEGEN_PDMA_CH6_OPMODE_TB2_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_CH6[3].u32Ctl =
        (((uint32_t)PDMA_CH6_DATA_LENGTH_TB3 - 1) << PDMA_DSCT_CTL_TXCNT_Pos) | /* Set transfer count */ \
        NUCODEGEN_PDMA_CH6_WIDTH_TB3 |   /* Set transfer width */ \
        NUCODEGEN_PDMA_CH6_SRC_TYPE_TB3 |    /* Set source increment type */ \
        NUCODEGEN_PDMA_CH6_DES_TYPE_TB3 |    /* Set destination increment type */ \
        NUCODEGEN_PDMA_CH6_MODE_TB3 |  /* Set transfer type */ \
        NUCODEGEN_PDMA_CH6_BURST_SIZE_TB3 |  /* Set burst size */ \
        NUCODEGEN_PDMA_CH6_TB3_INT_EN |   /* Set table empty interrupt */ \
        NUCODEGEN_PDMA_CH6_OPMODE_TB3;  /* Set operation mode */

    /* Configure source address */
    DMA_DESC_CH6[3].u32Src = (uint32_t)NUCODEGEN_PDMA_CH6_SRC_ADDR_TB3;

    /* Configure destination address */
    DMA_DESC_CH6[3].u32Dest = (uint32_t)NUCODEGEN_PDMA_CH6_DES_ADDR_TB3;
	#if(NUCODEGEN_PDMA_CH6_OPMODE_TB3_S==NUCODEGEN_PDMA_OP_BASIC)
    /* Configure next descriptor table address */
    DMA_DESC_CH6[3].u32Offset = 0; /* No next operation table. No effect in basic mode */
	#else
    /* Configure next descriptor table address */
    DMA_DESC_CH6[3].u32Offset = (uint32_t)&DMA_DESC_CH6[4] - (PDMA->SCATBA); /* next descriptor table is table 4 */
	#endif
    #endif
    #if(NUCODEGEN_PDMA_CH6_OPMODE_TB3_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_CH6[4].u32Ctl =
        (((uint32_t)PDMA_CH6_DATA_LENGTH_TB4 - 1) << PDMA_DSCT_CTL_TXCNT_Pos) | /* Set transfer count */ \
        NUCODEGEN_PDMA_CH6_WIDTH_TB4 |   /* Set transfer width */ \
        NUCODEGEN_PDMA_CH6_SRC_TYPE_TB4 |    /* Set source increment type */ \
        NUCODEGEN_PDMA_CH6_DES_TYPE_TB4 |    /* Set destination increment type */ \
        NUCODEGEN_PDMA_CH6_MODE_TB4 |  /* Set transfer type */ \
        NUCODEGEN_PDMA_CH6_BURST_SIZE_TB4 |  /* Set burst size */ \
        NUCODEGEN_PDMA_CH6_TB4_INT_EN |   /* Set table empty interrupt */ \
        NUCODEGEN_PDMA_CH6_OPMODE_TB4;  /* Set operation mode */

    /* Configure source address */
    DMA_DESC_CH6[4].u32Src = (uint32_t)NUCODEGEN_PDMA_CH6_SRC_ADDR_TB4;

    /* Configure destination address */
    DMA_DESC_CH6[4].u32Dest = (uint32_t)NUCODEGEN_PDMA_CH6_DES_ADDR_TB4;

    /* Configure next descriptor table address */
    DMA_DESC_CH6[4].u32Offset = (uint32_t)&DMA_DESC_CH6[5] - (PDMA->SCATBA); /* next descriptor table is table 5 */
    #endif

    #if(NUCODEGEN_PDMA_CH6_TMOUT)
    /* Enable timeout function and set timeout counter */
    PDMA_SetTimeOut(PDMA, 6, NUCODEGEN_PDMA_CH6_TMOUT, NUCODEGEN_PDMA_CH6_TMOUT_CNT);
    #endif

    #if(NUCODEGEN_PDMA_CH6_STRIDE_EN)
    /* Set stride function */
    PDMA_SetStride(PDMA, 6, NUCODEGEN_PDMA_CH6_STRIDE_DES_LENGTH, NUCODEGEN_PDMA_CH6_STRIDE_SRC_LENGTH, NUCODEGEN_PDMA_CH6_STRIDE_CNT);
    #endif

    /* Request source is NUCODEGEN_PDMA_CH6_SRC_DES_SEL */
    PDMA_SetTransferMode(PDMA, 6, NUCODEGEN_PDMA_CH6_SRC_DES_SEL, 1, (uint32_t)&DMA_DESC_CH6[0]);
#endif  //NUCODEGEN_PDMA_CH6_OPMODE == PDMA_OP_BASIC
#endif  //NUCODEGEN_PDMA_CH6_FUNC

#if (NUCODEGEN_PDMA_CH7)
#if (NUCODEGEN_PDMA_CH7_OPMODE_S == NUCODEGEN_PDMA_OP_BASIC)
    /* Open CH7 */
    PDMA_Open(PDMA, 1 << 7);

    /* Transfer count is PDMA_CH7_DATA_LENGTH, transfer width is NUCODEGEN_PDMA_CH7_WIDTH */
    PDMA_SetTransferCnt(PDMA, 7, NUCODEGEN_PDMA_CH7_WIDTH, PDMA_CH7_DATA_LENGTH);

    /* Set source address is NUCODEGEN_PDMA_CH7_SRC_ADDR, destination address is NUCODEGEN_PDMA_CH7_DES_ADDR */
    PDMA_SetTransferAddr(PDMA, 7, (uint32_t)NUCODEGEN_PDMA_CH7_SRC_ADDR, NUCODEGEN_PDMA_CH7_SRC_TYPE, (uint32_t)NUCODEGEN_PDMA_CH7_DES_ADDR, NUCODEGEN_PDMA_CH7_DES_TYPE);

    /* Set transfer mode and burst size */
    PDMA_SetBurstType(PDMA, 7, NUCODEGEN_PDMA_CH7_MODE, NUCODEGEN_PDMA_CH7_BURST_SIZE);

    #if(NUCODEGEN_PDMA_CH7_TMOUT)
    /* Enable timeout function and set timeout counter */
    PDMA_SetTimeOut(PDMA, 7, NUCODEGEN_PDMA_CH7_TMOUT, NUCODEGEN_PDMA_CH7_TMOUT_CNT);
    #endif

    #if(NUCODEGEN_PDMA_CH7_STRIDE_EN)
    /* Set stride function */
    PDMA_SetStride(PDMA, 7, NUCODEGEN_PDMA_CH7_STRIDE_DES_LENGTH, NUCODEGEN_PDMA_CH7_STRIDE_SRC_LENGTH, NUCODEGEN_PDMA_CH7_STRIDE_CNT);
    #endif

    /* Request source is NUCODEGEN_PDMA_CH7_SRC_DES_SEL */
    PDMA_SetTransferMode(PDMA, 7, NUCODEGEN_PDMA_CH7_SRC_DES_SEL, 0, 0);
#else   //NUCODEGEN_PDMA_CH7_OPMODE_S == PDMA_OP_SCATTER
    /* Open CH7 */
    PDMA_Open(PDMA, 1 << 7);

    DMA_DESC_CH7[0].u32Ctl =
        (((uint32_t)PDMA_CH7_DATA_LENGTH_TB0 - 1) << PDMA_DSCT_CTL_TXCNT_Pos) | /* Set transfer count */ \
        NUCODEGEN_PDMA_CH7_WIDTH_TB0 |   /* Set transfer width */ \
        NUCODEGEN_PDMA_CH7_SRC_TYPE_TB0 |    /* Set source increment type */ \
        NUCODEGEN_PDMA_CH7_DES_TYPE_TB0 |    /* Set destination increment type */ \
        NUCODEGEN_PDMA_CH7_MODE_TB0 |  /* Set transfer type */ \
        NUCODEGEN_PDMA_CH7_BURST_SIZE_TB0 |  /* Set burst size */ \
        NUCODEGEN_PDMA_CH7_TB0_INT_EN |   /* Set table empty interrupt */ \
        NUCODEGEN_PDMA_CH7_OPMODE_TB0;  /* Set operation mode */

    /* Configure source address */
    DMA_DESC_CH7[0].u32Src = (uint32_t)NUCODEGEN_PDMA_CH7_SRC_ADDR_TB0;

    /* Configure destination address */
    DMA_DESC_CH7[0].u32Dest = (uint32_t)NUCODEGEN_PDMA_CH7_DES_ADDR_TB0;

	#if(NUCODEGEN_PDMA_CH7_OPMODE_TB0_S==NUCODEGEN_PDMA_OP_BASIC)
    /* Configure next descriptor table address */
    DMA_DESC_CH7[0].u32Offset = 0; /* No next operation table. No effect in basic mode */
	#else
    /* Configure next descriptor table address */
    DMA_DESC_CH7[0].u32Offset = (uint32_t)&DMA_DESC_CH7[1] - (PDMA->SCATBA); /* next descriptor table is table 1 */
    #endif
    #if(NUCODEGEN_PDMA_CH7_OPMODE_TB0_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_CH7[1].u32Ctl =
        (((uint32_t)PDMA_CH7_DATA_LENGTH_TB1 - 1) << PDMA_DSCT_CTL_TXCNT_Pos) | /* Set transfer count */ \
        NUCODEGEN_PDMA_CH7_WIDTH_TB1 |   /* Set transfer width */ \
        NUCODEGEN_PDMA_CH7_SRC_TYPE_TB1 |    /* Set source increment type */ \
        NUCODEGEN_PDMA_CH7_DES_TYPE_TB1 |    /* Set destination increment type */ \
        NUCODEGEN_PDMA_CH7_MODE_TB1 |  /* Set transfer type */ \
        NUCODEGEN_PDMA_CH7_BURST_SIZE_TB1 |  /* Set burst size */ \
        NUCODEGEN_PDMA_CH7_TB1_INT_EN |   /* Set table empty interrupt */ \
        NUCODEGEN_PDMA_CH7_OPMODE_TB1;  /* Set operation mode */

    /* Configure source address */
    DMA_DESC_CH7[1].u32Src = (uint32_t)NUCODEGEN_PDMA_CH7_SRC_ADDR_TB1;

    /* Configure destination address */
    DMA_DESC_CH7[1].u32Dest = (uint32_t)NUCODEGEN_PDMA_CH7_DES_ADDR_TB1;

	#if(NUCODEGEN_PDMA_CH7_OPMODE_TB1_S==NUCODEGEN_PDMA_OP_BASIC)
    /* Configure next descriptor table address */
    DMA_DESC_CH7[1].u32Offset = 0; /* No next operation table. No effect in basic mode */
	#else
    /* Configure next descriptor table address */
    DMA_DESC_CH7[1].u32Offset = (uint32_t)&DMA_DESC_CH7[2] - (PDMA->SCATBA); /* next descriptor table is table 2 */
    #endif
    #endif
    #if(NUCODEGEN_PDMA_CH7_OPMODE_TB1_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_CH7[2].u32Ctl =
        (((uint32_t)PDMA_CH7_DATA_LENGTH_TB2 - 1) << PDMA_DSCT_CTL_TXCNT_Pos) | /* Set transfer count */ \
        NUCODEGEN_PDMA_CH7_WIDTH_TB2 |   /* Set transfer width */ \
        NUCODEGEN_PDMA_CH7_SRC_TYPE_TB2 |    /* Set source increment type */ \
        NUCODEGEN_PDMA_CH7_DES_TYPE_TB2 |    /* Set destination increment type */ \
        NUCODEGEN_PDMA_CH7_MODE_TB2 |  /* Set transfer type */ \
        NUCODEGEN_PDMA_CH7_BURST_SIZE_TB2 |  /* Set burst size */ \
        NUCODEGEN_PDMA_CH7_TB2_INT_EN |   /* Set table empty interrupt */ \
        NUCODEGEN_PDMA_CH7_OPMODE_TB2;  /* Set operation mode */

    /* Configure source address */
    DMA_DESC_CH7[2].u32Src = (uint32_t)NUCODEGEN_PDMA_CH7_SRC_ADDR_TB2;

    /* Configure destination address */
    DMA_DESC_CH7[2].u32Dest = (uint32_t)NUCODEGEN_PDMA_CH7_DES_ADDR_TB2;
	#if(NUCODEGEN_PDMA_CH7_OPMODE_TB2_S==NUCODEGEN_PDMA_OP_BASIC)
    /* Configure next descriptor table address */
    DMA_DESC_CH7[2].u32Offset = 0; /* No next operation table. No effect in basic mode */
	#else
    /* Configure next descriptor table address */
    DMA_DESC_CH7[2].u32Offset = (uint32_t)&DMA_DESC_CH7[3] - (PDMA->SCATBA); /* next descriptor table is table 3 */
    #endif
    #endif
    #if(NUCODEGEN_PDMA_CH7_OPMODE_TB2_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_CH7[3].u32Ctl =
        (((uint32_t)PDMA_CH7_DATA_LENGTH_TB3 - 1) << PDMA_DSCT_CTL_TXCNT_Pos) | /* Set transfer count */ \
        NUCODEGEN_PDMA_CH7_WIDTH_TB3 |   /* Set transfer width */ \
        NUCODEGEN_PDMA_CH7_SRC_TYPE_TB3 |    /* Set source increment type */ \
        NUCODEGEN_PDMA_CH7_DES_TYPE_TB3 |    /* Set destination increment type */ \
        NUCODEGEN_PDMA_CH7_MODE_TB3 |  /* Set transfer type */ \
        NUCODEGEN_PDMA_CH7_BURST_SIZE_TB3 |  /* Set burst size */ \
        NUCODEGEN_PDMA_CH7_TB3_INT_EN |   /* Set table empty interrupt */ \
        NUCODEGEN_PDMA_CH7_OPMODE_TB3;  /* Set operation mode */

    /* Configure source address */
    DMA_DESC_CH7[3].u32Src = (uint32_t)NUCODEGEN_PDMA_CH7_SRC_ADDR_TB3;

    /* Configure destination address */
    DMA_DESC_CH7[3].u32Dest = (uint32_t)NUCODEGEN_PDMA_CH7_DES_ADDR_TB3;
	#if(NUCODEGEN_PDMA_CH7_OPMODE_TB3_S==NUCODEGEN_PDMA_OP_BASIC)
    /* Configure next descriptor table address */
    DMA_DESC_CH7[3].u32Offset = 0; /* No next operation table. No effect in basic mode */
	#else
    /* Configure next descriptor table address */
    DMA_DESC_CH7[3].u32Offset = (uint32_t)&DMA_DESC_CH7[4] - (PDMA->SCATBA); /* next descriptor table is table 4 */
    #endif
    #endif
    #if(NUCODEGEN_PDMA_CH7_OPMODE_TB3_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_CH7[4].u32Ctl =
        (((uint32_t)PDMA_CH7_DATA_LENGTH_TB4 - 1) << PDMA_DSCT_CTL_TXCNT_Pos) | /* Set transfer count */ \
        NUCODEGEN_PDMA_CH7_WIDTH_TB4 |   /* Set transfer width */ \
        NUCODEGEN_PDMA_CH7_SRC_TYPE_TB4 |    /* Set source increment type */ \
        NUCODEGEN_PDMA_CH7_DES_TYPE_TB4 |    /* Set destination increment type */ \
        NUCODEGEN_PDMA_CH7_MODE_TB4 |  /* Set transfer type */ \
        NUCODEGEN_PDMA_CH7_BURST_SIZE_TB4 |  /* Set burst size */ \
        NUCODEGEN_PDMA_CH7_TB4_INT_EN |   /* Set table empty interrupt */ \
        NUCODEGEN_PDMA_CH7_OPMODE_TB4;  /* Set operation mode */

    /* Configure source address */
    DMA_DESC_CH7[4].u32Src = (uint32_t)NUCODEGEN_PDMA_CH7_SRC_ADDR_TB4;

    /* Configure destination address */
    DMA_DESC_CH7[4].u32Dest = (uint32_t)NUCODEGEN_PDMA_CH7_DES_ADDR_TB4;

    /* Configure next descriptor table address */
    DMA_DESC_CH7[4].u32Offset = (uint32_t)&DMA_DESC_CH7[5] - (PDMA->SCATBA); /* next descriptor table is table 5 */
    #endif

    #if(NUCODEGEN_PDMA_CH7_TMOUT)
    /* Enable timeout function and set timeout counter */
    PDMA_SetTimeOut(PDMA, 7, NUCODEGEN_PDMA_CH7_TMOUT, NUCODEGEN_PDMA_CH7_TMOUT_CNT);
    #endif

    #if(NUCODEGEN_PDMA_CH7_STRIDE_EN)
    /* Set stride function */
    PDMA_SetStride(PDMA, 7, NUCODEGEN_PDMA_CH7_STRIDE_DES_LENGTH, NUCODEGEN_PDMA_CH7_STRIDE_SRC_LENGTH, NUCODEGEN_PDMA_CH7_STRIDE_CNT);
    #endif

    /* Request source is NUCODEGEN_PDMA_CH7_SRC_DES_SEL */
    PDMA_SetTransferMode(PDMA, 7, NUCODEGEN_PDMA_CH7_SRC_DES_SEL, 1, (uint32_t)&DMA_DESC_CH7[0]);
#endif  //NUCODEGEN_PDMA_CH7_OPMODE == PDMA_OP_BASIC
#endif  //NUCODEGEN_PDMA_CH7_FUNC

#if NUCODEGEN_PDMA_CH0_INT
    #if NUCODEGEN_PDMA_CH0_INT_TXDONE
    PDMA_EnableInt(PDMA, 0, PDMA_INT_TRANS_DONE);
    #endif
    #if NUCODEGEN_PDMA_CH0_INT_TBDIS
    PDMA_EnableInt(PDMA, 0, PDMA_INT_TEMPTY);
    #endif
    #if NUCODEGEN_PDMA_CH0_INT_TIMEOUT
    PDMA_EnableInt(PDMA, 0, PDMA_INT_TIMEOUT);
    #endif
#endif
#if NUCODEGEN_PDMA_CH1_INT
    #if NUCODEGEN_PDMA_CH1_INT_TXDONE
    PDMA_EnableInt(PDMA, 1, PDMA_INT_TRANS_DONE);
    #endif
    #if NUCODEGEN_PDMA_CH1_INT_TBDIS
    PDMA_EnableInt(PDMA, 1, PDMA_INT_TEMPTY);
    #endif
    #if NUCODEGEN_PDMA_CH1_INT_TIMEOUT
    PDMA_EnableInt(PDMA, 1, PDMA_INT_TIMEOUT);
    #endif
#endif
#if NUCODEGEN_PDMA_CH2_INT
    #if NUCODEGEN_PDMA_CH2_INT_TXDONE
    PDMA_EnableInt(PDMA, 2, PDMA_INT_TRANS_DONE);
    #endif
    #if NUCODEGEN_PDMA_CH2_INT_TBDIS
    PDMA_EnableInt(PDMA, 2, PDMA_INT_TEMPTY);
    #endif
    #if NUCODEGEN_PDMA_CH2_INT_TIMEOUT
    PDMA_EnableInt(PDMA, 2, PDMA_INT_TIMEOUT);
    #endif
#endif
#if NUCODEGEN_PDMA_CH3_INT
    #if NUCODEGEN_PDMA_CH3_INT_TXDONE
    PDMA_EnableInt(PDMA, 3, PDMA_INT_TRANS_DONE);
    #endif
    #if NUCODEGEN_PDMA_CH3_INT_TBDIS
    PDMA_EnableInt(PDMA, 3, PDMA_INT_TEMPTY);
    #endif
    #if NUCODEGEN_PDMA_CH3_INT_TIMEOUT
    PDMA_EnableInt(PDMA, 3, PDMA_INT_TIMEOUT);
    #endif
#endif
#if NUCODEGEN_PDMA_CH4_INT
    #if NUCODEGEN_PDMA_CH4_INT_TXDONE
    PDMA_EnableInt(PDMA, 4, PDMA_INT_TRANS_DONE);
    #endif
    #if NUCODEGEN_PDMA_CH4_INT_TBDIS
    PDMA_EnableInt(PDMA, 4, PDMA_INT_TEMPTY);
    #endif
    #if NUCODEGEN_PDMA_CH4_INT_TIMEOUT
    PDMA_EnableInt(PDMA, 4, PDMA_INT_TIMEOUT);
    #endif
#endif
#if NUCODEGEN_PDMA_CH5_INT
    #if NUCODEGEN_PDMA_CH5_INT_TXDONE
    PDMA_EnableInt(PDMA, 5, PDMA_INT_TRANS_DONE);
    #endif
    #if NUCODEGEN_PDMA_CH5_INT_TBDIS
    PDMA_EnableInt(PDMA, 5, PDMA_INT_TEMPTY);
    #endif
    #if NUCODEGEN_PDMA_CH5_INT_TIMEOUT
    PDMA_EnableInt(PDMA, 5, PDMA_INT_TIMEOUT);
    #endif
#endif
#if NUCODEGEN_PDMA_CH6_INT
    #if NUCODEGEN_PDMA_CH6_INT_TXDONE
    PDMA_EnableInt(PDMA, 6, PDMA_INT_TRANS_DONE);
    #endif
    #if NUCODEGEN_PDMA_CH6_INT_TBDIS
    PDMA_EnableInt(PDMA, 6, PDMA_INT_TEMPTY);
    #endif
    #if NUCODEGEN_PDMA_CH6_INT_TIMEOUT
    PDMA_EnableInt(PDMA, 6, PDMA_INT_TIMEOUT);
    #endif
#endif
#if NUCODEGEN_PDMA_CH7_INT
    #if NUCODEGEN_PDMA_CH7_INT_TXDONE
    PDMA_EnableInt(PDMA, 7, PDMA_INT_TRANS_DONE);
    #endif
    #if NUCODEGEN_PDMA_CH7_INT_TBDIS
    PDMA_EnableInt(PDMA, 7, PDMA_INT_TEMPTY);
    #endif
    #if NUCODEGEN_PDMA_CH7_INT_TIMEOUT
    PDMA_EnableInt(PDMA, 7, PDMA_INT_TIMEOUT);
    #endif
#endif


#if (NUCODEGEN_PDMA_CH0_INT || NUCODEGEN_PDMA_CH1_INT || NUCODEGEN_PDMA_CH2_INT || NUCODEGEN_PDMA_CH3_INT || NUCODEGEN_PDMA_CH4_INT || NUCODEGEN_PDMA_CH5_INT \
    || NUCODEGEN_PDMA_CH6_INT || NUCODEGEN_PDMA_CH7_INT )
    NVIC_EnableIRQ(PDMA_IRQn);
#endif
}
#endif

#if (NUCODEGEN_EBI)
/*************************************/
/**              EBI                **/
/*************************************/
void EBI_Init(){
#if (NUCODEGEN_EBI_BANK0)
    /* Initialize EBI bank0 */
    EBI_Open(EBI_BANK0, NUCODEGEN_EBI_BANK0_DATAWIDTH, NUCODEGEN_EBI_BANK0_TIMING, NUCODEGEN_EBI_BANK0_BUS_MODE, NUCODEGEN_EBI_BANK0_CS_ACTIVE_LEVEL);
#if (NUCODEGEN_EBI_BANK0_ADVANCE)
    /* Setting EBI data access time */
    EBI->TCTL0 = (EBI->TCTL0 & ~EBI_TCTL_TACC_Msk)|(NUCODEGEN_EBI_BANK0_TACC<<EBI_TCTL_TACC_Pos);

    /* Setting EBI access hold time when write */
    EBI->TCTL0 = (EBI->TCTL0 & ~EBI_TCTL_WAHDOFF_Msk)|(NUCODEGEN_EBI_BANK0_WAHD_EN<<EBI_TCTL_WAHDOFF_Pos);

    /* Setting EBI access hold time when read */
    EBI->TCTL0 = (EBI->TCTL0 & ~EBI_TCTL_RAHDOFF_Msk)|(NUCODEGEN_EBI_BANK0_RAHD_EN<<EBI_TCTL_RAHDOFF_Pos);

    /* Setting EBI access time */
    EBI->TCTL0 = (EBI->TCTL0 & ~EBI_TCTL_TAHD_Msk)|(NUCODEGEN_EBI_BANK0_TAHD<<EBI_TCTL_TAHD_Pos);
#endif
#endif  //NUCODEGEN_EBI_BANK0

#if (NUCODEGEN_EBI_BANK1)
    /* Initialize EBI bank1 */
    EBI_Open(EBI_BANK1, NUCODEGEN_EBI_BANK1_DATAWIDTH, NUCODEGEN_EBI_BANK1_TIMING, NUCODEGEN_EBI_BANK1_BUS_MODE, NUCODEGEN_EBI_BANK1_CS_ACTIVE_LEVEL);
#if (NUCODEGEN_EBI_BANK1_ADVANCE)
    /* Setting EBI data access time */
    EBI->TCTL1 = (EBI->TCTL1 & ~EBI_TCTL_TACC_Msk)|(NUCODEGEN_EBI_BANK1_TACC<<EBI_TCTL_TACC_Pos);

    /* Setting EBI access hold time when write */
    EBI->TCTL1 = (EBI->TCTL1 & ~EBI_TCTL_WAHDOFF_Msk)|(NUCODEGEN_EBI_BANK1_WAHD_EN<<EBI_TCTL_WAHDOFF_Pos);

    /* Setting EBI access hold time when read */
    EBI->TCTL1 = (EBI->TCTL1 & ~EBI_TCTL_RAHDOFF_Msk)|(NUCODEGEN_EBI_BANK1_RAHD_EN<<EBI_TCTL_RAHDOFF_Pos);

    /* Setting EBI access time */
    EBI->TCTL1 = (EBI->TCTL1 & ~EBI_TCTL_TAHD_Msk)|(NUCODEGEN_EBI_BANK1_TAHD<<EBI_TCTL_TAHD_Pos);
#endif
#endif  //NUCODEGEN_EBI_BANK1

#if (NUCODEGEN_EBI_BANK2)
    /* Initialize EBI bank2 */
    EBI_Open(EBI_BANK2, NUCODEGEN_EBI_BANK2_DATAWIDTH, NUCODEGEN_EBI_BANK2_TIMING, NUCODEGEN_EBI_BANK2_BUS_MODE, NUCODEGEN_EBI_BANK2_CS_ACTIVE_LEVEL);
#if (NUCODEGEN_EBI_BANK2_ADVANCE)
    /* Setting EBI data access time */
    EBI->TCTL2 = (EBI->TCTL2 & ~EBI_TCTL_TACC_Msk)|(NUCODEGEN_EBI_BANK2_TACC<<EBI_TCTL_TACC_Pos);

    /* Setting EBI access hold time when write */
    EBI->TCTL2 = (EBI->TCTL2 & ~EBI_TCTL_WAHDOFF_Msk)|(NUCODEGEN_EBI_BANK2_WAHD_EN<<EBI_TCTL_WAHDOFF_Pos);

    /* Setting EBI access hold time when read */
    EBI->TCTL2 = (EBI->TCTL2 & ~EBI_TCTL_RAHDOFF_Msk)|(NUCODEGEN_EBI_BANK2_RAHD_EN<<EBI_TCTL_RAHDOFF_Pos);

    /* Setting EBI access time */
    EBI->TCTL2 = (EBI->TCTL2 & ~EBI_TCTL_TAHD_Msk)|(NUCODEGEN_EBI_BANK2_TAHD<<EBI_TCTL_TAHD_Pos);
#endif
#endif  //NUCODEGEN_EBI_BANK2
}
#endif

#if (NUCODEGEN_PSIO)
/*************************************/
/**              PSIO               **/
/*************************************/
void PSIO_Init(){
#if (NUCODEGEN_PSIO_SLOTCTL0_EN)
    /* Initialize PSIO slot control setting */
    PSIO_SET_SCCTL(PSIO, PSIO_SC0, NUCODEGEN_PSIO_SLOTCTL0_INIT_SLOT, NUCODEGEN_PSIO_SLOTCTL0_END_SLOT, NUCODEGEN_PSIO_SLOTCTL0_LOOP_CNT, NUCODEGEN_PSIO_SLOTCTL0_REPEAT);

    /* Set slot count */
    PSIO_SCSLOT_SET_SLOT(PSIO, PSIO_SC0, PSIO_SLOT0, NUCODEGEN_PSIO_SLOTCTL0_SLOT0_COUNT);
    PSIO_SCSLOT_SET_SLOT(PSIO, PSIO_SC0, PSIO_SLOT1, NUCODEGEN_PSIO_SLOTCTL0_SLOT1_COUNT);
    PSIO_SCSLOT_SET_SLOT(PSIO, PSIO_SC0, PSIO_SLOT2, NUCODEGEN_PSIO_SLOTCTL0_SLOT2_COUNT);
    PSIO_SCSLOT_SET_SLOT(PSIO, PSIO_SC0, PSIO_SLOT3, NUCODEGEN_PSIO_SLOTCTL0_SLOT3_COUNT);
    PSIO_SCSLOT_SET_SLOT(PSIO, PSIO_SC0, PSIO_SLOT4, NUCODEGEN_PSIO_SLOTCTL0_SLOT4_COUNT);
    PSIO_SCSLOT_SET_SLOT(PSIO, PSIO_SC0, PSIO_SLOT5, NUCODEGEN_PSIO_SLOTCTL0_SLOT5_COUNT);
    PSIO_SCSLOT_SET_SLOT(PSIO, PSIO_SC0, PSIO_SLOT6, NUCODEGEN_PSIO_SLOTCTL0_SLOT6_COUNT);
    PSIO_SCSLOT_SET_SLOT(PSIO, PSIO_SC0, PSIO_SLOT7, NUCODEGEN_PSIO_SLOTCTL0_SLOT7_COUNT);

    /* Set slot controller trigger source */
    PSIO_SET_TRIGSRC(PSIO, PSIO_SC0, NUCODEGEN_PSIO_SLOTCTL0_TRIGGER_TYPE);
#endif  //NUCODEGEN_PSIO_SLOTCTL0_EN

#if (NUCODEGEN_PSIO_SLOTCTL1_EN)
    /* Initialize PSIO slot control setting */
    PSIO_SET_SCCTL(PSIO, PSIO_SC1, NUCODEGEN_PSIO_SLOTCTL1_INIT_SLOT, NUCODEGEN_PSIO_SLOTCTL1_END_SLOT, NUCODEGEN_PSIO_SLOTCTL1_LOOP_CNT, NUCODEGEN_PSIO_SLOTCTL1_REPEAT);

    /* Set slot count */
    PSIO_SCSLOT_SET_SLOT(PSIO, PSIO_SC1, PSIO_SLOT0, NUCODEGEN_PSIO_SLOTCTL1_SLOT0_COUNT);
    PSIO_SCSLOT_SET_SLOT(PSIO, PSIO_SC1, PSIO_SLOT1, NUCODEGEN_PSIO_SLOTCTL1_SLOT1_COUNT);
    PSIO_SCSLOT_SET_SLOT(PSIO, PSIO_SC1, PSIO_SLOT2, NUCODEGEN_PSIO_SLOTCTL1_SLOT2_COUNT);
    PSIO_SCSLOT_SET_SLOT(PSIO, PSIO_SC1, PSIO_SLOT3, NUCODEGEN_PSIO_SLOTCTL1_SLOT3_COUNT);
    PSIO_SCSLOT_SET_SLOT(PSIO, PSIO_SC1, PSIO_SLOT4, NUCODEGEN_PSIO_SLOTCTL1_SLOT4_COUNT);
    PSIO_SCSLOT_SET_SLOT(PSIO, PSIO_SC1, PSIO_SLOT5, NUCODEGEN_PSIO_SLOTCTL1_SLOT5_COUNT);
    PSIO_SCSLOT_SET_SLOT(PSIO, PSIO_SC1, PSIO_SLOT6, NUCODEGEN_PSIO_SLOTCTL1_SLOT6_COUNT);
    PSIO_SCSLOT_SET_SLOT(PSIO, PSIO_SC1, PSIO_SLOT7, NUCODEGEN_PSIO_SLOTCTL1_SLOT7_COUNT);

    /* Set slot controller trigger source */
    PSIO_SET_TRIGSRC(PSIO, PSIO_SC1, NUCODEGEN_PSIO_SLOTCTL1_TRIGGER_TYPE);
#endif  //NUCODEGEN_PSIO_SLOTCTL1_EN

#if (NUCODEGEN_PSIO_SLOTCTL2_EN)
    /* Initialize PSIO slot control setting */
    PSIO_SET_SCCTL(PSIO, PSIO_SC2, NUCODEGEN_PSIO_SLOTCTL2_INIT_SLOT, NUCODEGEN_PSIO_SLOTCTL2_END_SLOT, NUCODEGEN_PSIO_SLOTCTL2_LOOP_CNT, NUCODEGEN_PSIO_SLOTCTL2_REPEAT);

    /* Set slot count */
    PSIO_SCSLOT_SET_SLOT(PSIO, PSIO_SC2, PSIO_SLOT0, NUCODEGEN_PSIO_SLOTCTL2_SLOT0_COUNT);
    PSIO_SCSLOT_SET_SLOT(PSIO, PSIO_SC2, PSIO_SLOT1, NUCODEGEN_PSIO_SLOTCTL2_SLOT1_COUNT);
    PSIO_SCSLOT_SET_SLOT(PSIO, PSIO_SC2, PSIO_SLOT2, NUCODEGEN_PSIO_SLOTCTL2_SLOT2_COUNT);
    PSIO_SCSLOT_SET_SLOT(PSIO, PSIO_SC2, PSIO_SLOT3, NUCODEGEN_PSIO_SLOTCTL2_SLOT3_COUNT);
    PSIO_SCSLOT_SET_SLOT(PSIO, PSIO_SC2, PSIO_SLOT4, NUCODEGEN_PSIO_SLOTCTL2_SLOT4_COUNT);
    PSIO_SCSLOT_SET_SLOT(PSIO, PSIO_SC2, PSIO_SLOT5, NUCODEGEN_PSIO_SLOTCTL2_SLOT5_COUNT);
    PSIO_SCSLOT_SET_SLOT(PSIO, PSIO_SC2, PSIO_SLOT6, NUCODEGEN_PSIO_SLOTCTL2_SLOT6_COUNT);
    PSIO_SCSLOT_SET_SLOT(PSIO, PSIO_SC2, PSIO_SLOT7, NUCODEGEN_PSIO_SLOTCTL2_SLOT7_COUNT);

    /* Set slot controller trigger source */
    PSIO_SET_TRIGSRC(PSIO, PSIO_SC2, NUCODEGEN_PSIO_SLOTCTL2_TRIGGER_TYPE);
#endif  //NUCODEGEN_PSIO_SLOTCTL2_EN

#if (NUCODEGEN_PSIO_SLOTCTL3_EN)
    /* Initialize PSIO slot control setting */
    PSIO_SET_SCCTL(PSIO, PSIO_SC3, NUCODEGEN_PSIO_SLOTCTL3_INIT_SLOT, NUCODEGEN_PSIO_SLOTCTL3_END_SLOT, NUCODEGEN_PSIO_SLOTCTL3_LOOP_CNT, NUCODEGEN_PSIO_SLOTCTL3_REPEAT);

    /* Set slot count */
    PSIO_SCSLOT_SET_SLOT(PSIO, PSIO_SC3, PSIO_SLOT0, NUCODEGEN_PSIO_SLOTCTL3_SLOT0_COUNT);
    PSIO_SCSLOT_SET_SLOT(PSIO, PSIO_SC3, PSIO_SLOT1, NUCODEGEN_PSIO_SLOTCTL3_SLOT1_COUNT);
    PSIO_SCSLOT_SET_SLOT(PSIO, PSIO_SC3, PSIO_SLOT2, NUCODEGEN_PSIO_SLOTCTL3_SLOT2_COUNT);
    PSIO_SCSLOT_SET_SLOT(PSIO, PSIO_SC3, PSIO_SLOT3, NUCODEGEN_PSIO_SLOTCTL3_SLOT3_COUNT);
    PSIO_SCSLOT_SET_SLOT(PSIO, PSIO_SC3, PSIO_SLOT4, NUCODEGEN_PSIO_SLOTCTL3_SLOT4_COUNT);
    PSIO_SCSLOT_SET_SLOT(PSIO, PSIO_SC3, PSIO_SLOT5, NUCODEGEN_PSIO_SLOTCTL3_SLOT5_COUNT);
    PSIO_SCSLOT_SET_SLOT(PSIO, PSIO_SC3, PSIO_SLOT6, NUCODEGEN_PSIO_SLOTCTL3_SLOT6_COUNT);
    PSIO_SCSLOT_SET_SLOT(PSIO, PSIO_SC3, PSIO_SLOT7, NUCODEGEN_PSIO_SLOTCTL3_SLOT7_COUNT);

    /* Set slot controller trigger source */
    PSIO_SET_TRIGSRC(PSIO, PSIO_SC3, NUCODEGEN_PSIO_SLOTCTL3_TRIGGER_TYPE);
#endif  //NUCODEGEN_PSIO_SLOTCTL3_EN

#if (NUCODEGEN_PSIO_PIN0_EN)
    /* Link check point to slot */
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN0, PSIO_CP0, NUCODEGEN_PSIO_PIN0_CP0_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN0, PSIO_CP1, NUCODEGEN_PSIO_PIN0_CP1_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN0, PSIO_CP2, NUCODEGEN_PSIO_PIN0_CP2_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN0, PSIO_CP3, NUCODEGEN_PSIO_PIN0_CP3_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN0, PSIO_CP4, NUCODEGEN_PSIO_PIN0_CP4_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN0, PSIO_CP5, NUCODEGEN_PSIO_PIN0_CP5_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN0, PSIO_CP6, NUCODEGEN_PSIO_PIN0_CP6_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN0, PSIO_CP7, NUCODEGEN_PSIO_PIN0_CP7_SLT);

    /* Set check point action */
    PSIO_SET_ACTION(PSIO, PSIO_PIN0, PSIO_CP0, NUCODEGEN_PSIO_PIN0_CP0_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN0, PSIO_CP1, NUCODEGEN_PSIO_PIN0_CP1_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN0, PSIO_CP2, NUCODEGEN_PSIO_PIN0_CP2_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN0, PSIO_CP3, NUCODEGEN_PSIO_PIN0_CP3_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN0, PSIO_CP4, NUCODEGEN_PSIO_PIN0_CP4_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN0, PSIO_CP5, NUCODEGEN_PSIO_PIN0_CP5_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN0, PSIO_CP6, NUCODEGEN_PSIO_PIN0_CP6_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN0, PSIO_CP7, NUCODEGEN_PSIO_PIN0_CP7_ACT);

    /* Set pin general control */
    PSIO_SET_GENCTL(PSIO, PSIO_PIN0, PSIO_PIN_ENABLE, NUCODEGEN_PSIO_PIN0_SLOT_CNT, NUCODEGEN_PSIO_PIN0_IOMODE, NUCODEGEN_PSIO_PIN0_INIT_STATE, NUCODEGEN_PSIO_PIN0_INTERVAL_STATE);

    /* Set pin order */
    PSIO_SET_ORDER(PSIO, PSIO_PIN0, NUCODEGEN_PSIO_PIN0_DATA_ORDER);

    /* Set data width */
    PSIO_SET_WIDTH(PSIO, PSIO_PIN0, NUCODEGEN_PSIO_PIN0_DATA_RX_WIDTH, NUCODEGEN_PSIO_PIN0_DATA_TX_WIDTH);

    /* Set data depth */
    PSIO_SET_OUTPUT_DEPTH(PSIO, PSIO_PIN0, NUCODEGEN_PSIO_PIN0_DATA_TX_DEPTH);
    PSIO_SET_INPUT_DEPTH(PSIO, PSIO_PIN0, NUCODEGEN_PSIO_PIN0_DATA_RX_DEPTH);

    #if(NUCODEGEN_PSIO_PIN0_SWITCH_POINT0_EN)
    /* Set switch point 0 */
    PSIO_SWITCH_MODE(PSIO, PSIO_PIN0, PSIO_SWITCH_P0, NUCODEGEN_PSIO_PIN0_MODE_SWITCH0, NUCODEGEN_PSIO_PIN0_SWITCH_POINT0);
    #endif
    #if(NUCODEGEN_PSIO_PIN0_SWITCH_POINT1_EN)
    /* Set switch point 1 */
    PSIO_SWITCH_MODE(PSIO, PSIO_PIN0, PSIO_SWITCH_P1, NUCODEGEN_PSIO_PIN0_MODE_SWITCH1, NUCODEGEN_PSIO_PIN0_SWITCH_POINT1);
    #endif
#endif  //NUCODEGEN_PSIO_PIN0_EN

#if (NUCODEGEN_PSIO_PIN1_EN)
    /* Link check point to slot */
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN1, PSIO_CP0, NUCODEGEN_PSIO_PIN1_CP0_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN1, PSIO_CP1, NUCODEGEN_PSIO_PIN1_CP1_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN1, PSIO_CP2, NUCODEGEN_PSIO_PIN1_CP2_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN1, PSIO_CP3, NUCODEGEN_PSIO_PIN1_CP3_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN1, PSIO_CP4, NUCODEGEN_PSIO_PIN1_CP4_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN1, PSIO_CP5, NUCODEGEN_PSIO_PIN1_CP5_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN1, PSIO_CP6, NUCODEGEN_PSIO_PIN1_CP6_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN1, PSIO_CP7, NUCODEGEN_PSIO_PIN1_CP7_SLT);

    /* Set check point action */
    PSIO_SET_ACTION(PSIO, PSIO_PIN1, PSIO_CP0, NUCODEGEN_PSIO_PIN1_CP0_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN1, PSIO_CP1, NUCODEGEN_PSIO_PIN1_CP1_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN1, PSIO_CP2, NUCODEGEN_PSIO_PIN1_CP2_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN1, PSIO_CP3, NUCODEGEN_PSIO_PIN1_CP3_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN1, PSIO_CP4, NUCODEGEN_PSIO_PIN1_CP4_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN1, PSIO_CP5, NUCODEGEN_PSIO_PIN1_CP5_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN1, PSIO_CP6, NUCODEGEN_PSIO_PIN1_CP6_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN1, PSIO_CP7, NUCODEGEN_PSIO_PIN1_CP7_ACT);

    /* Set pin general control */
    PSIO_SET_GENCTL(PSIO, PSIO_PIN1, PSIO_PIN_ENABLE, NUCODEGEN_PSIO_PIN1_SLOT_CNT, NUCODEGEN_PSIO_PIN1_IOMODE, NUCODEGEN_PSIO_PIN1_INIT_STATE, NUCODEGEN_PSIO_PIN1_INTERVAL_STATE);

    /* Set pin order */
    PSIO_SET_ORDER(PSIO, PSIO_PIN1, NUCODEGEN_PSIO_PIN1_DATA_ORDER);

    /* Set data width */
    PSIO_SET_WIDTH(PSIO, PSIO_PIN1, NUCODEGEN_PSIO_PIN1_DATA_RX_WIDTH, NUCODEGEN_PSIO_PIN1_DATA_TX_WIDTH);

    /* Set data depth */
    PSIO_SET_OUTPUT_DEPTH(PSIO, PSIO_PIN1, NUCODEGEN_PSIO_PIN1_DATA_TX_DEPTH);
    PSIO_SET_INPUT_DEPTH(PSIO, PSIO_PIN1, NUCODEGEN_PSIO_PIN1_DATA_RX_DEPTH);

    #if(NUCODEGEN_PSIO_PIN1_SWITCH_POINT0_EN)
    /* Set switch point 0 */
    PSIO_SWITCH_MODE(PSIO, PSIO_PIN1, PSIO_SWITCH_P0, NUCODEGEN_PSIO_PIN1_MODE_SWITCH0, NUCODEGEN_PSIO_PIN1_SWITCH_POINT0);
    #endif
    #if(NUCODEGEN_PSIO_PIN1_SWITCH_POINT1_EN)
    /* Set switch point 1 */
    PSIO_SWITCH_MODE(PSIO, PSIO_PIN1, PSIO_SWITCH_P1, NUCODEGEN_PSIO_PIN1_MODE_SWITCH1, NUCODEGEN_PSIO_PIN1_SWITCH_POINT1);
    #endif
#endif  //NUCODEGEN_PSIO_PIN1_EN

#if (NUCODEGEN_PSIO_PIN2_EN)
    /* Link check point to slot */
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN2, PSIO_CP0, NUCODEGEN_PSIO_PIN2_CP0_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN2, PSIO_CP1, NUCODEGEN_PSIO_PIN2_CP1_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN2, PSIO_CP2, NUCODEGEN_PSIO_PIN2_CP2_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN2, PSIO_CP3, NUCODEGEN_PSIO_PIN2_CP3_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN2, PSIO_CP4, NUCODEGEN_PSIO_PIN2_CP4_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN2, PSIO_CP5, NUCODEGEN_PSIO_PIN2_CP5_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN2, PSIO_CP6, NUCODEGEN_PSIO_PIN2_CP6_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN2, PSIO_CP7, NUCODEGEN_PSIO_PIN2_CP7_SLT);

    /* Set check point action */
    PSIO_SET_ACTION(PSIO, PSIO_PIN2, PSIO_CP0, NUCODEGEN_PSIO_PIN2_CP0_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN2, PSIO_CP1, NUCODEGEN_PSIO_PIN2_CP1_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN2, PSIO_CP2, NUCODEGEN_PSIO_PIN2_CP2_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN2, PSIO_CP3, NUCODEGEN_PSIO_PIN2_CP3_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN2, PSIO_CP4, NUCODEGEN_PSIO_PIN2_CP4_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN2, PSIO_CP5, NUCODEGEN_PSIO_PIN2_CP5_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN2, PSIO_CP6, NUCODEGEN_PSIO_PIN2_CP6_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN2, PSIO_CP7, NUCODEGEN_PSIO_PIN2_CP7_ACT);

    /* Set pin general control */
    PSIO_SET_GENCTL(PSIO, PSIO_PIN2, PSIO_PIN_ENABLE, NUCODEGEN_PSIO_PIN2_SLOT_CNT, NUCODEGEN_PSIO_PIN2_IOMODE, NUCODEGEN_PSIO_PIN2_INIT_STATE, NUCODEGEN_PSIO_PIN2_INTERVAL_STATE);

    /* Set pin order */
    PSIO_SET_ORDER(PSIO, PSIO_PIN2, NUCODEGEN_PSIO_PIN2_DATA_ORDER);

    /* Set data width */
    PSIO_SET_WIDTH(PSIO, PSIO_PIN2, NUCODEGEN_PSIO_PIN2_DATA_RX_WIDTH, NUCODEGEN_PSIO_PIN2_DATA_TX_WIDTH);

    /* Set data depth */
    PSIO_SET_OUTPUT_DEPTH(PSIO, PSIO_PIN2, NUCODEGEN_PSIO_PIN2_DATA_TX_DEPTH);
    PSIO_SET_INPUT_DEPTH(PSIO, PSIO_PIN2, NUCODEGEN_PSIO_PIN2_DATA_RX_DEPTH);

    #if(NUCODEGEN_PSIO_PIN2_SWITCH_POINT0_EN)
    /* Set switch point 0 */
    PSIO_SWITCH_MODE(PSIO, PSIO_PIN2, PSIO_SWITCH_P0, NUCODEGEN_PSIO_PIN2_MODE_SWITCH0, NUCODEGEN_PSIO_PIN2_SWITCH_POINT0);
    #endif
    #if(NUCODEGEN_PSIO_PIN2_SWITCH_POINT1_EN)
    /* Set switch point 1 */
    PSIO_SWITCH_MODE(PSIO, PSIO_PIN2, PSIO_SWITCH_P1, NUCODEGEN_PSIO_PIN2_MODE_SWITCH1, NUCODEGEN_PSIO_PIN2_SWITCH_POINT1);
    #endif
#endif  //NUCODEGEN_PSIO_PIN2_EN

#if (NUCODEGEN_PSIO_PIN3_EN)
    /* Link check point to slot */
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN3, PSIO_CP0, NUCODEGEN_PSIO_PIN3_CP0_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN3, PSIO_CP1, NUCODEGEN_PSIO_PIN3_CP1_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN3, PSIO_CP2, NUCODEGEN_PSIO_PIN3_CP2_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN3, PSIO_CP3, NUCODEGEN_PSIO_PIN3_CP3_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN3, PSIO_CP4, NUCODEGEN_PSIO_PIN3_CP4_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN3, PSIO_CP5, NUCODEGEN_PSIO_PIN3_CP5_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN3, PSIO_CP6, NUCODEGEN_PSIO_PIN3_CP6_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN3, PSIO_CP7, NUCODEGEN_PSIO_PIN3_CP7_SLT);

    /* Set check point action */
    PSIO_SET_ACTION(PSIO, PSIO_PIN3, PSIO_CP0, NUCODEGEN_PSIO_PIN3_CP0_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN3, PSIO_CP1, NUCODEGEN_PSIO_PIN3_CP1_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN3, PSIO_CP2, NUCODEGEN_PSIO_PIN3_CP2_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN3, PSIO_CP3, NUCODEGEN_PSIO_PIN3_CP3_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN3, PSIO_CP4, NUCODEGEN_PSIO_PIN3_CP4_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN3, PSIO_CP5, NUCODEGEN_PSIO_PIN3_CP5_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN3, PSIO_CP6, NUCODEGEN_PSIO_PIN3_CP6_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN3, PSIO_CP7, NUCODEGEN_PSIO_PIN3_CP7_ACT);

    /* Set pin general control */
    PSIO_SET_GENCTL(PSIO, PSIO_PIN3, PSIO_PIN_ENABLE, NUCODEGEN_PSIO_PIN3_SLOT_CNT, NUCODEGEN_PSIO_PIN3_IOMODE, NUCODEGEN_PSIO_PIN3_INIT_STATE, NUCODEGEN_PSIO_PIN3_INTERVAL_STATE);

    /* Set pin order */
    PSIO_SET_ORDER(PSIO, PSIO_PIN3, NUCODEGEN_PSIO_PIN3_DATA_ORDER);

    /* Set data width */
    PSIO_SET_WIDTH(PSIO, PSIO_PIN3, NUCODEGEN_PSIO_PIN3_DATA_RX_WIDTH, NUCODEGEN_PSIO_PIN3_DATA_TX_WIDTH);

    /* Set data depth */
    PSIO_SET_OUTPUT_DEPTH(PSIO, PSIO_PIN3, NUCODEGEN_PSIO_PIN3_DATA_TX_DEPTH);
    PSIO_SET_INPUT_DEPTH(PSIO, PSIO_PIN3, NUCODEGEN_PSIO_PIN3_DATA_RX_DEPTH);

    #if(NUCODEGEN_PSIO_PIN3_SWITCH_POINT0_EN)
    /* Set switch point 0 */
    PSIO_SWITCH_MODE(PSIO, PSIO_PIN3, PSIO_SWITCH_P0, NUCODEGEN_PSIO_PIN3_MODE_SWITCH0, NUCODEGEN_PSIO_PIN3_SWITCH_POINT0);
    #endif
    #if(NUCODEGEN_PSIO_PIN3_SWITCH_POINT1_EN)
    /* Set switch point 1 */
    PSIO_SWITCH_MODE(PSIO, PSIO_PIN3, PSIO_SWITCH_P1, NUCODEGEN_PSIO_PIN3_MODE_SWITCH1, NUCODEGEN_PSIO_PIN3_SWITCH_POINT1);
    #endif
#endif  //NUCODEGEN_PSIO_PIN3_EN

#if (NUCODEGEN_PSIO_PIN4_EN)
    /* Link check point to slot */
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN4, PSIO_CP0, NUCODEGEN_PSIO_PIN4_CP0_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN4, PSIO_CP1, NUCODEGEN_PSIO_PIN4_CP1_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN4, PSIO_CP2, NUCODEGEN_PSIO_PIN4_CP2_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN4, PSIO_CP3, NUCODEGEN_PSIO_PIN4_CP3_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN4, PSIO_CP4, NUCODEGEN_PSIO_PIN4_CP4_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN4, PSIO_CP5, NUCODEGEN_PSIO_PIN4_CP5_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN4, PSIO_CP6, NUCODEGEN_PSIO_PIN4_CP6_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN4, PSIO_CP7, NUCODEGEN_PSIO_PIN4_CP7_SLT);

    /* Set check point action */
    PSIO_SET_ACTION(PSIO, PSIO_PIN4, PSIO_CP0, NUCODEGEN_PSIO_PIN4_CP0_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN4, PSIO_CP1, NUCODEGEN_PSIO_PIN4_CP1_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN4, PSIO_CP2, NUCODEGEN_PSIO_PIN4_CP2_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN4, PSIO_CP3, NUCODEGEN_PSIO_PIN4_CP3_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN4, PSIO_CP4, NUCODEGEN_PSIO_PIN4_CP4_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN4, PSIO_CP5, NUCODEGEN_PSIO_PIN4_CP5_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN4, PSIO_CP6, NUCODEGEN_PSIO_PIN4_CP6_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN4, PSIO_CP7, NUCODEGEN_PSIO_PIN4_CP7_ACT);

    /* Set pin general control */
    PSIO_SET_GENCTL(PSIO, PSIO_PIN4, PSIO_PIN_ENABLE, NUCODEGEN_PSIO_PIN4_SLOT_CNT, NUCODEGEN_PSIO_PIN4_IOMODE, NUCODEGEN_PSIO_PIN4_INIT_STATE, NUCODEGEN_PSIO_PIN4_INTERVAL_STATE);

    /* Set pin order */
    PSIO_SET_ORDER(PSIO, PSIO_PIN4, NUCODEGEN_PSIO_PIN4_DATA_ORDER);

    /* Set data width */
    PSIO_SET_WIDTH(PSIO, PSIO_PIN4, NUCODEGEN_PSIO_PIN4_DATA_RX_WIDTH, NUCODEGEN_PSIO_PIN4_DATA_TX_WIDTH);

    /* Set data depth */
    PSIO_SET_OUTPUT_DEPTH(PSIO, PSIO_PIN4, NUCODEGEN_PSIO_PIN4_DATA_TX_DEPTH);
    PSIO_SET_INPUT_DEPTH(PSIO, PSIO_PIN4, NUCODEGEN_PSIO_PIN4_DATA_RX_DEPTH);

    #if(NUCODEGEN_PSIO_PIN4_SWITCH_POINT0_EN)
    /* Set switch point 0 */
    PSIO_SWITCH_MODE(PSIO, PSIO_PIN4, PSIO_SWITCH_P0, NUCODEGEN_PSIO_PIN4_MODE_SWITCH0, NUCODEGEN_PSIO_PIN4_SWITCH_POINT0);
    #endif
    #if(NUCODEGEN_PSIO_PIN4_SWITCH_POINT1_EN)
    /* Set switch point 1 */
    PSIO_SWITCH_MODE(PSIO, PSIO_PIN4, PSIO_SWITCH_P1, NUCODEGEN_PSIO_PIN4_MODE_SWITCH1, NUCODEGEN_PSIO_PIN4_SWITCH_POINT1);
    #endif
#endif  //NUCODEGEN_PSIO_PIN4_EN

#if (NUCODEGEN_PSIO_PIN5_EN)
    /* Link check point to slot */
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN5, PSIO_CP0, NUCODEGEN_PSIO_PIN5_CP0_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN5, PSIO_CP1, NUCODEGEN_PSIO_PIN5_CP1_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN5, PSIO_CP2, NUCODEGEN_PSIO_PIN5_CP2_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN5, PSIO_CP3, NUCODEGEN_PSIO_PIN5_CP3_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN5, PSIO_CP4, NUCODEGEN_PSIO_PIN5_CP4_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN5, PSIO_CP5, NUCODEGEN_PSIO_PIN5_CP5_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN5, PSIO_CP6, NUCODEGEN_PSIO_PIN5_CP6_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN5, PSIO_CP7, NUCODEGEN_PSIO_PIN5_CP7_SLT);

    /* Set check point action */
    PSIO_SET_ACTION(PSIO, PSIO_PIN5, PSIO_CP0, NUCODEGEN_PSIO_PIN5_CP0_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN5, PSIO_CP1, NUCODEGEN_PSIO_PIN5_CP1_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN5, PSIO_CP2, NUCODEGEN_PSIO_PIN5_CP2_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN5, PSIO_CP3, NUCODEGEN_PSIO_PIN5_CP3_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN5, PSIO_CP4, NUCODEGEN_PSIO_PIN5_CP4_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN5, PSIO_CP5, NUCODEGEN_PSIO_PIN5_CP5_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN5, PSIO_CP6, NUCODEGEN_PSIO_PIN5_CP6_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN5, PSIO_CP7, NUCODEGEN_PSIO_PIN5_CP7_ACT);

    /* Set pin general control */
    PSIO_SET_GENCTL(PSIO, PSIO_PIN5, PSIO_PIN_ENABLE, NUCODEGEN_PSIO_PIN5_SLOT_CNT, NUCODEGEN_PSIO_PIN5_IOMODE, NUCODEGEN_PSIO_PIN5_INIT_STATE, NUCODEGEN_PSIO_PIN5_INTERVAL_STATE);

    /* Set pin order */
    PSIO_SET_ORDER(PSIO, PSIO_PIN5, NUCODEGEN_PSIO_PIN5_DATA_ORDER);

    /* Set data width */
    PSIO_SET_WIDTH(PSIO, PSIO_PIN5, NUCODEGEN_PSIO_PIN5_DATA_RX_WIDTH, NUCODEGEN_PSIO_PIN5_DATA_TX_WIDTH);

    /* Set data depth */
    PSIO_SET_OUTPUT_DEPTH(PSIO, PSIO_PIN5, NUCODEGEN_PSIO_PIN5_DATA_TX_DEPTH);
    PSIO_SET_INPUT_DEPTH(PSIO, PSIO_PIN5, NUCODEGEN_PSIO_PIN5_DATA_RX_DEPTH);

    #if(NUCODEGEN_PSIO_PIN5_SWITCH_POINT0_EN)
    /* Set switch point 0 */
    PSIO_SWITCH_MODE(PSIO, PSIO_PIN5, PSIO_SWITCH_P0, NUCODEGEN_PSIO_PIN5_MODE_SWITCH0, NUCODEGEN_PSIO_PIN5_SWITCH_POINT0);
    #endif
    #if(NUCODEGEN_PSIO_PIN5_SWITCH_POINT1_EN)
    /* Set switch point 1 */
    PSIO_SWITCH_MODE(PSIO, PSIO_PIN5, PSIO_SWITCH_P1, NUCODEGEN_PSIO_PIN5_MODE_SWITCH1, NUCODEGEN_PSIO_PIN5_SWITCH_POINT1);
    #endif
#endif  //NUCODEGEN_PSIO_PIN5_EN

#if (NUCODEGEN_PSIO_PIN6_EN)
    /* Link check point to slot */
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN6, PSIO_CP0, NUCODEGEN_PSIO_PIN6_CP0_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN6, PSIO_CP1, NUCODEGEN_PSIO_PIN6_CP1_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN6, PSIO_CP2, NUCODEGEN_PSIO_PIN6_CP2_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN6, PSIO_CP3, NUCODEGEN_PSIO_PIN6_CP3_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN6, PSIO_CP4, NUCODEGEN_PSIO_PIN6_CP4_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN6, PSIO_CP5, NUCODEGEN_PSIO_PIN6_CP5_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN6, PSIO_CP6, NUCODEGEN_PSIO_PIN6_CP6_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN6, PSIO_CP7, NUCODEGEN_PSIO_PIN6_CP7_SLT);

    /* Set check point action */
    PSIO_SET_ACTION(PSIO, PSIO_PIN6, PSIO_CP0, NUCODEGEN_PSIO_PIN6_CP0_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN6, PSIO_CP1, NUCODEGEN_PSIO_PIN6_CP1_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN6, PSIO_CP2, NUCODEGEN_PSIO_PIN6_CP2_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN6, PSIO_CP3, NUCODEGEN_PSIO_PIN6_CP3_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN6, PSIO_CP4, NUCODEGEN_PSIO_PIN6_CP4_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN6, PSIO_CP5, NUCODEGEN_PSIO_PIN6_CP5_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN6, PSIO_CP6, NUCODEGEN_PSIO_PIN6_CP6_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN6, PSIO_CP7, NUCODEGEN_PSIO_PIN6_CP7_ACT);

    /* Set pin general control */
    PSIO_SET_GENCTL(PSIO, PSIO_PIN6, PSIO_PIN_ENABLE, NUCODEGEN_PSIO_PIN6_SLOT_CNT, NUCODEGEN_PSIO_PIN6_IOMODE, NUCODEGEN_PSIO_PIN6_INIT_STATE, NUCODEGEN_PSIO_PIN6_INTERVAL_STATE);

    /* Set pin order */
    PSIO_SET_ORDER(PSIO, PSIO_PIN6, NUCODEGEN_PSIO_PIN6_DATA_ORDER);

    /* Set data width */
    PSIO_SET_WIDTH(PSIO, PSIO_PIN6, NUCODEGEN_PSIO_PIN6_DATA_RX_WIDTH, NUCODEGEN_PSIO_PIN6_DATA_TX_WIDTH);

    /* Set data depth */
    PSIO_SET_OUTPUT_DEPTH(PSIO, PSIO_PIN6, NUCODEGEN_PSIO_PIN6_DATA_TX_DEPTH);
    PSIO_SET_INPUT_DEPTH(PSIO, PSIO_PIN6, NUCODEGEN_PSIO_PIN6_DATA_RX_DEPTH);

    #if(NUCODEGEN_PSIO_PIN6_SWITCH_POINT0_EN)
    /* Set switch point 0 */
    PSIO_SWITCH_MODE(PSIO, PSIO_PIN6, PSIO_SWITCH_P0, NUCODEGEN_PSIO_PIN6_MODE_SWITCH0, NUCODEGEN_PSIO_PIN6_SWITCH_POINT0);
    #endif
    #if(NUCODEGEN_PSIO_PIN6_SWITCH_POINT1_EN)
    /* Set switch point 1 */
    PSIO_SWITCH_MODE(PSIO, PSIO_PIN6, PSIO_SWITCH_P1, NUCODEGEN_PSIO_PIN6_MODE_SWITCH1, NUCODEGEN_PSIO_PIN6_SWITCH_POINT1);
    #endif
#endif  //NUCODEGEN_PSIO_PIN6_EN

#if (NUCODEGEN_PSIO_PIN7_EN)
    /* Link check point to slot */
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN7, PSIO_CP0, NUCODEGEN_PSIO_PIN7_CP0_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN7, PSIO_CP1, NUCODEGEN_PSIO_PIN7_CP1_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN7, PSIO_CP2, NUCODEGEN_PSIO_PIN7_CP2_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN7, PSIO_CP3, NUCODEGEN_PSIO_PIN7_CP3_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN7, PSIO_CP4, NUCODEGEN_PSIO_PIN7_CP4_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN7, PSIO_CP5, NUCODEGEN_PSIO_PIN7_CP5_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN7, PSIO_CP6, NUCODEGEN_PSIO_PIN7_CP6_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN7, PSIO_CP7, NUCODEGEN_PSIO_PIN7_CP7_SLT);

    /* Set check point action */
    PSIO_SET_ACTION(PSIO, PSIO_PIN7, PSIO_CP0, NUCODEGEN_PSIO_PIN7_CP0_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN7, PSIO_CP1, NUCODEGEN_PSIO_PIN7_CP1_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN7, PSIO_CP2, NUCODEGEN_PSIO_PIN7_CP2_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN7, PSIO_CP3, NUCODEGEN_PSIO_PIN7_CP3_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN7, PSIO_CP4, NUCODEGEN_PSIO_PIN7_CP4_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN7, PSIO_CP5, NUCODEGEN_PSIO_PIN7_CP5_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN7, PSIO_CP6, NUCODEGEN_PSIO_PIN7_CP6_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN7, PSIO_CP7, NUCODEGEN_PSIO_PIN7_CP7_ACT);

    /* Set pin general control */
    PSIO_SET_GENCTL(PSIO, PSIO_PIN7, PSIO_PIN_ENABLE, NUCODEGEN_PSIO_PIN7_SLOT_CNT, NUCODEGEN_PSIO_PIN7_IOMODE, NUCODEGEN_PSIO_PIN7_INIT_STATE, NUCODEGEN_PSIO_PIN7_INTERVAL_STATE);

    /* Set pin order */
    PSIO_SET_ORDER(PSIO, PSIO_PIN7, NUCODEGEN_PSIO_PIN7_DATA_ORDER);

    /* Set data width */
    PSIO_SET_WIDTH(PSIO, PSIO_PIN7, NUCODEGEN_PSIO_PIN7_DATA_RX_WIDTH, NUCODEGEN_PSIO_PIN7_DATA_TX_WIDTH);

    /* Set data depth */
    PSIO_SET_OUTPUT_DEPTH(PSIO, PSIO_PIN7, NUCODEGEN_PSIO_PIN7_DATA_TX_DEPTH);
    PSIO_SET_INPUT_DEPTH(PSIO, PSIO_PIN7, NUCODEGEN_PSIO_PIN7_DATA_RX_DEPTH);

    #if(NUCODEGEN_PSIO_PIN7_SWITCH_POINT0_EN)
    /* Set switch point 0 */
    PSIO_SWITCH_MODE(PSIO, PSIO_PIN7, PSIO_SWITCH_P0, NUCODEGEN_PSIO_PIN7_MODE_SWITCH0, NUCODEGEN_PSIO_PIN7_SWITCH_POINT0);
    #endif
    #if(NUCODEGEN_PSIO_PIN7_SWITCH_POINT1_EN)
    /* Set switch point 1 */
    PSIO_SWITCH_MODE(PSIO, PSIO_PIN7, PSIO_SWITCH_P1, NUCODEGEN_PSIO_PIN7_MODE_SWITCH1, NUCODEGEN_PSIO_PIN7_SWITCH_POINT1);
    #endif
#endif  //NUCODEGEN_PSIO_PIN7_EN

#if (NUCODEGEN_PSIO_INT_EN)
    PSIO_ENABLE_INT(PSIO, NUCODEGEN_PSIO_INT_TYPE);
    #if (NUCODEGEN_PSIO_INT0_EN)
        PSIO_SET_INTCTL(PSIO, NUCODEGEN_PSIO_INT0_SC, PSIO_INT0, NUCODEGEN_PSIO_INT0_SLOT);
    #endif  //NUCODEGEN_PSIO_INT0_EN
    #if (NUCODEGEN_PSIO_INT0_EN)
        PSIO_SET_INTCTL(PSIO, NUCODEGEN_PSIO_INT1_SC, PSIO_INT1, NUCODEGEN_PSIO_INT1_SLOT);
    #endif  //NUCODEGEN_PSIO_INT0_EN
    NVIC_EnableIRQ(PSIO_IRQn);
#endif  //NUCODEGEN_PSIO_INT_EN
}
#endif



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


#if (NUCODEGEN_WWDT)
void WWDT_Init(void)
{
    /* Setup WWDT configurations.
       Note that WWDT CTL register can only be written once after the chip resets. */
    WWDT_Open(WWDT_PRESCALER_CONFIG, WWDT_CMPDAT_CONFIG, WWDT_INTEN_CONFIG);

#if (NUCODEGEN_WWDT_INT_ENABLE)
    /* NVIC Enable WWDT Interrupt */
    NVIC_EnableIRQ(WWDT_IRQn);
#endif
}
#endif /* NUCODEGEN_WWDT */


#if (NUCODEGEN_RTC)
void RTC_Init(void)
{
    S_RTC_TIME_DATA_T sDateTimeInit, sDateTimeAlarm;

#if (NUCODEGEN_RTC_DATETIME_INIT)
    /* Configure RTC initial date and time structure. */
    sDateTimeInit.u32Year       = NUCODEGEN_RTC_CURRENT_YEAR_CONFIG;
    sDateTimeInit.u32Month      = NUCODEGEN_RTC_CURRENT_MONTH_CONFIG;
    sDateTimeInit.u32Day        = NUCODEGEN_RTC_CURRENT_DATE_CONFIG;
    sDateTimeInit.u32DayOfWeek  = NUCODEGEN_RTC_CURRENT_DOW_CONFIG;
    sDateTimeInit.u32Hour       = NUCODEGEN_RTC_CURRENT_HOUR_CONFIG;
    sDateTimeInit.u32Minute     = NUCODEGEN_RTC_CURRENT_MINUTE_CONFIG;
    sDateTimeInit.u32Second     = NUCODEGEN_RTC_CURRENT_SECOND_CONFIG;
    sDateTimeInit.u32TimeScale  = NUCODEGEN_RTC_TIMESCALE_CONFIG;
    sDateTimeInit.u32AmPm       = NUCODEGEN_RTC_CURRENT_AMPM_CONFIG;
#else
    /* Configure RTC initial date and time structure. */
    sDateTimeInit.u32Year       = 2015;
    sDateTimeInit.u32Month      = 8;
    sDateTimeInit.u32Day        = 8;
    sDateTimeInit.u32DayOfWeek  = RTC_SATURDAY;
    sDateTimeInit.u32Hour       = 0;
    sDateTimeInit.u32Minute     = 0;
    sDateTimeInit.u32Second     = 0;
    sDateTimeInit.u32TimeScale  = NUCODEGEN_RTC_TIMESCALE_CONFIG;
    sDateTimeInit.u32AmPm       = NUCODEGEN_RTC_CURRENT_AMPM_CONFIG;
#endif
    /* Initial RTC module. Setup RTC current date and time. */
    RTC_Open(&sDateTimeInit);

    /* Setup RTC tick period */
    RTC_SetTickPeriod(RTC_TICK_CONFIG);

#if (NUCODEGEN_RTC_ALARM_ENABLE)
    /* Configure RTC alarm date and time structure. */
    sDateTimeAlarm.u32Year       = NUCODEGEN_RTC_ALARM_YEAR_CONFIG;
    sDateTimeAlarm.u32Month      = NUCODEGEN_RTC_ALARM_MONTH_CONFIG;
    sDateTimeAlarm.u32Day        = NUCODEGEN_RTC_ALARM_DATE_CONFIG;
    sDateTimeAlarm.u32Hour       = NUCODEGEN_RTC_ALARM_HOUR_CONFIG;
    sDateTimeAlarm.u32Minute     = NUCODEGEN_RTC_ALARM_MINUTE_CONFIG;
    sDateTimeAlarm.u32Second     = NUCODEGEN_RTC_ALARM_SECOND_CONFIG;
    sDateTimeAlarm.u32TimeScale  = NUCODEGEN_RTC_TIMESCALE_CONFIG;
    sDateTimeAlarm.u32AmPm       = NUCODEGEN_RTC_ALARM_AMPM_CONFIG;

    /* Setup RTC alarm date and time configurations */
    RTC_SetAlarmDateAndTime(&sDateTimeAlarm);
#else
    /* Configure RTC alarm date and time structure. */
    sDateTimeAlarm.u32Year       = RTC_YEAR2000;
    sDateTimeAlarm.u32Month      = 0;
    sDateTimeAlarm.u32Day        = 0;
    sDateTimeAlarm.u32Hour       = 0;
    sDateTimeAlarm.u32Minute     = 0;
    sDateTimeAlarm.u32Second     = 0;
    sDateTimeAlarm.u32TimeScale  = NUCODEGEN_RTC_TIMESCALE_CONFIG;
    sDateTimeAlarm.u32AmPm       = NUCODEGEN_RTC_ALARM_AMPM_CONFIG;

    /* Setup RTC alarm date and time configurations */
    RTC_SetAlarmDateAndTime(&sDateTimeAlarm);
#endif

    /* Setup RTC alarm date mask. */
    RTC_SetAlarmDateMask(RTC_ALARM_TEN_YEAR_MASK,  RTC_ALARM_ONE_YEAR_MASK,
                         RTC_ALARM_TEN_MONTH_MASK, RTC_ALARM_ONE_MONTH_MASK,
                         RTC_ALARM_TEN_DATE_MASK,  RTC_ALARM_ONE_DATE_MASK);

    /* Setup RTC alarm time mask. */
    RTC_SetAlarmTimeMask(RTC_ALARM_TEN_HOUR_MASK,   RTC_ALARM_ONE_HOUR_MASK,
                         RTC_ALARM_TEN_MINUTE_MASK, RTC_ALARM_ONE_MINUTE_MASK,
                         RTC_ALARM_TEN_SECOND_MASK, RTC_ALARM_ONE_SECOND_MASK);

#if (NUCODEGEN_RTC_TAMP0_ENABLE)
    /* Setup RTC tamper pin detect level */
    RTC_StaticTamperEnable(RTC_TAMPER0_SELECT, NUCODEGEN_RTC_TAMP0_DETECT_LEVEL_CONFIG, RTC_TAMPER_DEBOUNCE_ENABLE);
#else
    /* Disable RTC tamper pin function */
    RTC->TAMPCTL = 0;
#endif

#if (NUCODEGEN_RTC_SPR_ENABLE)
    /* Enable RTC spare registers (SPR0~SPR4). Fill the initial value. */
    RTC_EnableSpareAccess();
    RTC_WRITE_SPARE_REGISTER(0, RTC_SPR0_DATA_CONFIG);
    RTC_WRITE_SPARE_REGISTER(1, RTC_SPR1_DATA_CONFIG);
    RTC_WRITE_SPARE_REGISTER(2, RTC_SPR2_DATA_CONFIG);
    RTC_WRITE_SPARE_REGISTER(3, RTC_SPR3_DATA_CONFIG);
    RTC_WRITE_SPARE_REGISTER(4, RTC_SPR4_DATA_CONFIG);
#else
    /* Disable RTC spare registers (SPR0~SPR4). */
    RTC_DisableSpareRegister();
#endif

#if (NUCODEGEN_RTC_FREQ_ADJ_ENABLE)
    /* Set Frequency Compensation Data */
    RTC_32KCalibration(RTC_LXT_FREQ);
#endif

    /* Clear RTC interrupt source and flag for safe */
    RTC_DisableInt(RTC_INTEN_TICKIEN_Msk|RTC_INTEN_ALMIEN_Msk|RTC_INTEN_TAMP0IEN_Msk);

#if (NUCODEGEN_RTC_INT_ENABLE)

    /* Enable RTC interrupt source */
    RTC_EnableInt(NUCODEGEN_RTC_INT_CONFIG);

    /* Enable RTC NVIC interrupt */
    NVIC_EnableIRQ(RTC_IRQn);
#endif
}
#endif /* NUCODEGEN_RTC */


#if (NUCODEGEN_EADC)
void EADC_Init()
{

/* --------------------------------------------------------------------
 * General configuration
 * ---------------------------------------------------------------------*/

    EADC_Open(NUCODEGEN_EADC_MODULE_SEL, 0);


/* --------------------------------------------------------------------
 * Advanced configuration
 * ---------------------------------------------------------------------*/


#if (NUCODEGEN_EADCATOFFEN)
    /* Auto power off & setup time */
    EADC_ENABLE_AUTOFF(NUCODEGEN_EADC_MODULE_SEL, NUCODEGEN_EADCATOFFTH, NUCODEDEF_EADCATOFFPOT);
#endif /* NUCODEGEN_EADCATOFFEN */


#if (NUCODEGEN_OFFSETCANCELEN)
    /* Offset cancellation */
    EADC_ENABLE_OFFSETCANCEL(NUCODEGEN_EADC_MODULE_SEL, NUCODEDEF_OFFSETCANCEL);
#endif /* NUCODEGEN_OFFSETCANCELEN */

    /* Interrupt setting */
    EADC_ENABLE_INT(NUCODEGEN_EADC_MODULE_SEL, NUCODEGEN_EADCINT);

#if (((NUCODEGEN_EADCINT)&0x1) == 0x1)
    /* Enable EADC INT0 NVIC interrupt */
    NVIC_EnableIRQ(NUCODEGEN_EADC_IRQ0_MODULE_SEL);
#endif /* (((NUCODEGEN_EADCINT)&0x1) == 0x1) */
#if (((NUCODEGEN_EADCINT)&0x2) == 0x2)
    /* Enable EADC INT1 NVIC interrupt */
    NVIC_EnableIRQ(NUCODEGEN_EADC_IRQ1_MODULE_SEL);
#endif /* ((NUCODEGEN_EADCINT)&0x2 == 0x2) */
#if (((NUCODEGEN_EADCINT)&0x4) == 0x4)
    /* Enable EADC INT2 NVIC interrupt */
    NVIC_EnableIRQ(NUCODEGEN_EADC_IRQ2_MODULE_SEL);
#endif /* (((NUCODEGEN_EADCINT)&0x4) == 0x4) */
#if (((NUCODEGEN_EADCINT)&0x8) == 0x8)
    /* Enable EADC INT3 NVIC interrupt */
    NVIC_EnableIRQ(NUCODEGEN_EADC_IRQ3_MODULE_SEL);
#endif /* (((NUCODEGEN_EADCINT)&0x8) == 0x8) */

#if (NUCODEGEN_EADCSM0EN || NUCODEGEN_EADCSM1EN || NUCODEGEN_EADCSM2EN || NUCODEGEN_EADCSM3EN || NUCODEGEN_EADCSM4EN || NUCODEGEN_EADCSM5EN || NUCODEGEN_EADCSM6EN || NUCODEGEN_EADCSM7EN || NUCODEGEN_EADCSM8EN || NUCODEGEN_EADCSM9EN || NUCODEGEN_EADCSM10EN || NUCODEGEN_EADCSM11EN || NUCODEGEN_EADCSM12EN || NUCODEGEN_EADCSM13EN || NUCODEGEN_EADCSM14EN || NUCODEGEN_EADCSM15EN || NUCODEGEN_EADCSM16EN || NUCODEGEN_EADCSM17EN || NUCODEGEN_EADCSM18EN )
/* --------------------------------------------------------------------
 * Sample module configuration 0~15 , Vbat, Temp, Vbg
 * ---------------------------------------------------------------------*/
#endif

#if (NUCODEGEN_EADCSM0EN)
    /* Sample module 0 */
    EADC_ConfigSampleModule(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(0), NUCODEGEN_EADCSM0TS, NUCODEDEF_EADCSM0CH);

    /* Enable interrupt and position */

#if (((NUCODEGEN_EADCSM0INTEN)&0x1) == 0x1)
    EADC_ENABLE_SAMPLE_MODULE_INT(NUCODEGEN_EADC_MODULE_SEL, AINT_SEL(0), BIT0 );
#endif /* (((NUCODEGEN_EADCSM0INTEN)&0x1) == 0x1) */
#if (((NUCODEGEN_EADCSM0INTEN)&0x2) == 0x2)
    EADC_ENABLE_SAMPLE_MODULE_INT(NUCODEGEN_EADC_MODULE_SEL, AINT_SEL(1), BIT0 );
#endif /* (((NUCODEGEN_EADCSM0INTEN)&0x2) == 0x2) */
#if (((NUCODEGEN_EADCSM0INTEN)&0x4) == 0x4)
    EADC_ENABLE_SAMPLE_MODULE_INT(NUCODEGEN_EADC_MODULE_SEL, AINT_SEL(2), BIT0 );
#endif /* (((NUCODEGEN_EADCSM0INTEN)&0x4) == 0x4) */
#if (((NUCODEGEN_EADCSM0INTEN)&0x8) == 0x8)
    EADC_ENABLE_SAMPLE_MODULE_INT(NUCODEGEN_EADC_MODULE_SEL, AINT_SEL(3), BIT0 );
#endif /* (((NUCODEGEN_EADCSM0INTEN)&0x8) == 0x8) */

#if (NUCODEGEN_EADCSM0IP)
    /* Interrupt start of conversion */
    EADC_ENABLE_INT_POSITION(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(0));
#endif /* NUCODEGEN_EADCSM0IP */

#if (NUCODEGEN_EADCSM0ADV)
    /* Advanced configuration */

    /* Trigger delay */
    EADC_SetTriggerDelayTime(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(0), NUCODEDEF_EADCSM0TD, NUCODEGEN_EADCSM0TDDIV);

    /* Extern sample time */
    EADC_SetExtendSampleTime(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(0), NUCODEDEF_EADCSM0ES);

#if (NUCODEGEN_EADCSM0DMA)
    /* Enable DMA support */
    EADC_ENABLE_PDMA(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(0));
#endif /* NUCODEGEN_EADCSM0DMA */

#if (NUCODEGEN_EADCSM0ALIGN)
    /* Enable data left alignment */
    EADC_ENABLE_LEFT_ALIGN(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(0));
#endif /* NUCODEGEN_EADCSM0ALIGN */

#if (NUCODEGEN_EADCSM0MODE == 1)
    /* Enable accumulate */
    EADC_ENABLE_ACU(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(0), NUCODEGEN_EADCSM0ACCU);
#elif (NUCODEGEN_EADCSM0MODE == 2)
    /* Enable average */
    EADC_ENABLE_ACU(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(0), NUCODEGEN_EADCSM0AVG);
    EADC_ENABLE_AVG(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(0));
#endif /* NUCODEGEN_EADCSM0MODE */

#endif /* NUCODEGEN_EADCSM0ADV */

#endif /* NUCODEGEN_EADCSM0EN */




#if (NUCODEGEN_EADCSM1EN)
    /* Sample module 1 */
    EADC_ConfigSampleModule(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(1), NUCODEGEN_EADCSM1TS, NUCODEDEF_EADCSM1CH);

    /* Enable interrupt and position */

#if (((NUCODEGEN_EADCSM1INTEN)&0x1) == 0x1)
    EADC_ENABLE_SAMPLE_MODULE_INT(NUCODEGEN_EADC_MODULE_SEL, AINT_SEL(0), BIT1 );
#endif /* (((NUCODEGEN_EADCSM1INTEN)&0x1) == 0x1) */
#if (((NUCODEGEN_EADCSM1INTEN)&0x2) == 0x2)
    EADC_ENABLE_SAMPLE_MODULE_INT(NUCODEGEN_EADC_MODULE_SEL, AINT_SEL(1), BIT1 );
#endif /* (((NUCODEGEN_EADCSM1INTEN)&0x2) == 0x2) */
#if (((NUCODEGEN_EADCSM1INTEN)&0x4) == 0x4)
    EADC_ENABLE_SAMPLE_MODULE_INT(NUCODEGEN_EADC_MODULE_SEL, AINT_SEL(2), BIT1 );
#endif /* (((NUCODEGEN_EADCSM1INTEN)&0x4) == 0x4) */
#if (((NUCODEGEN_EADCSM1INTEN)&0x8) == 0x8)
    EADC_ENABLE_SAMPLE_MODULE_INT(NUCODEGEN_EADC_MODULE_SEL, AINT_SEL(3), BIT1 );
#endif /* (((NUCODEGEN_EADCSM1INTEN)&0x8) == 0x8) */

#if (NUCODEGEN_EADCSM1IP)
    /* Interrupt start of conversion */
    EADC_ENABLE_INT_POSITION(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(1));
#endif /* NUCODEGEN_EADCSM1IP */

#if (NUCODEGEN_EADCSM1ADV)
    /* Advanced configuration */

    /* Trigger delay */
    EADC_SetTriggerDelayTime(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(1), NUCODEDEF_EADCSM1TD, NUCODEGEN_EADCSM1TDDIV);

    /* Extern sample time */
    EADC_SetExtendSampleTime(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(1), NUCODEDEF_EADCSM1ES);

#if (NUCODEGEN_EADCSM1DMA)
    /* Enable DMA support */
    EADC_ENABLE_PDMA(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(1));
#endif /* NUCODEGEN_EADCSM1DMA */

#if (NUCODEGEN_EADCSM1ALIGN)
    /* Enable data left alignment */
    EADC_ENABLE_LEFT_ALIGN(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(1));
#endif /* NUCODEGEN_EADCSM1ALIGN */

#if (NUCODEGEN_EADCSM1MODE == 1)
    /* Enable accumulate */
    EADC_ENABLE_ACU(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(1), NUCODEGEN_EADCSM1ACCU);
#elif (NUCODEGEN_EADCSM1MODE == 2)
    /* Enable average */
    EADC_ENABLE_ACU(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(1), NUCODEGEN_EADCSM1AVG);
    EADC_ENABLE_AVG(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(1));
#endif /* NUCODEGEN_EADCSM1MODE */

#endif /* NUCODEGEN_EADCSM1ADV */

#endif /* NUCODEGEN_EADCSM1EN */




#if (NUCODEGEN_EADCSM2EN)
    /* Sample module 2 */
    EADC_ConfigSampleModule(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(2), NUCODEGEN_EADCSM2TS, NUCODEDEF_EADCSM2CH);

    /* Enable interrupt and position */

#if (((NUCODEGEN_EADCSM2INTEN)&0x1) == 0x1)
    EADC_ENABLE_SAMPLE_MODULE_INT(NUCODEGEN_EADC_MODULE_SEL, AINT_SEL(0), BIT2 );
#endif /* (((NUCODEGEN_EADCSM2INTEN)&0x1) == 0x1) */
#if (((NUCODEGEN_EADCSM2INTEN)&0x2) == 0x2)
    EADC_ENABLE_SAMPLE_MODULE_INT(NUCODEGEN_EADC_MODULE_SEL, AINT_SEL(1), BIT2 );
#endif /* (((NUCODEGEN_EADCSM2INTEN)&0x2) == 0x2) */
#if (((NUCODEGEN_EADCSM2INTEN)&0x4) == 0x4)
    EADC_ENABLE_SAMPLE_MODULE_INT(NUCODEGEN_EADC_MODULE_SEL, AINT_SEL(2), BIT2 );
#endif /* (((NUCODEGEN_EADCSM2INTEN)&0x4) == 0x4) */
#if (((NUCODEGEN_EADCSM2INTEN)&0x8) == 0x8)
    EADC_ENABLE_SAMPLE_MODULE_INT(NUCODEGEN_EADC_MODULE_SEL, AINT_SEL(3), BIT2 );
#endif /* (((NUCODEGEN_EADCSM2INTEN)&0x8) == 0x8) */

#if (NUCODEGEN_EADCSM2IP)
    /* Interrupt start of conversion */
    EADC_ENABLE_INT_POSITION(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(2));
#endif /* NUCODEGEN_EADCSM2IP */

#if (NUCODEGEN_EADCSM2ADV)
    /* Advanced configuration */

    /* Trigger delay */
    EADC_SetTriggerDelayTime(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(2), NUCODEDEF_EADCSM2TD, NUCODEGEN_EADCSM2TDDIV);

    /* Extern sample time */
    EADC_SetExtendSampleTime(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(2), NUCODEDEF_EADCSM2ES);


#if (NUCODEGEN_EADCSM2DMA)
    /* Enable DMA support */
    EADC_ENABLE_PDMA(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(2));
#endif /* NUCODEGEN_EADCSM2DMA */

#if (NUCODEGEN_EADCSM2ALIGN)
    /* Enable data left alignment */
    EADC_ENABLE_LEFT_ALIGN(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(2));
#endif /* NUCODEGEN_EADCSM2ALIGN */

#if (NUCODEGEN_EADCSM2MODE == 1)
    /* Enable accumulate */
    EADC_ENABLE_ACU(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(2), NUCODEGEN_EADCSM2ACCU);
#elif (NUCODEGEN_EADCSM2MODE == 2)
    /* Enable average */
    EADC_ENABLE_ACU(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(2), NUCODEGEN_EADCSM2AVG);
    EADC_ENABLE_AVG(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(2));
#endif /* NUCODEGEN_EADCSM2MODE */

#endif /* NUCODEGEN_EADCSM2ADV */

#endif /* NUCODEGEN_EADCSM2EN */




#if (NUCODEGEN_EADCSM3EN)
    /* Sample module 3 */
    EADC_ConfigSampleModule(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(3), NUCODEGEN_EADCSM3TS, NUCODEDEF_EADCSM3CH);

    /* Enable interrupt and position */

#if (((NUCODEGEN_EADCSM3INTEN)&0x1) == 0x1)
    EADC_ENABLE_SAMPLE_MODULE_INT(NUCODEGEN_EADC_MODULE_SEL, AINT_SEL(0), BIT3 );
#endif /* (((NUCODEGEN_EADCSM3INTEN)&0x1) == 0x1) */
#if (((NUCODEGEN_EADCSM3INTEN)&0x2) == 0x2)
    EADC_ENABLE_SAMPLE_MODULE_INT(NUCODEGEN_EADC_MODULE_SEL, AINT_SEL(1), BIT3 );
#endif /* (((NUCODEGEN_EADCSM3INTEN)&0x2) == 0x2) */
#if (((NUCODEGEN_EADCSM3INTEN)&0x4) == 0x4)
    EADC_ENABLE_SAMPLE_MODULE_INT(NUCODEGEN_EADC_MODULE_SEL, AINT_SEL(2), BIT3 );
#endif /* (((NUCODEGEN_EADCSM3INTEN)&0x4) == 0x4) */
#if (((NUCODEGEN_EADCSM3INTEN)&0x8) == 0x8)
    EADC_ENABLE_SAMPLE_MODULE_INT(NUCODEGEN_EADC_MODULE_SEL, AINT_SEL(3), BIT3 );
#endif /* (((NUCODEGEN_EADCSM3INTEN)&0x8) == 0x8) */

#if (NUCODEGEN_EADCSM3IP)
    /* Interrupt start of conversion */
    EADC_ENABLE_INT_POSITION(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(3));
#endif /* NUCODEGEN_EADCSM3IP */

#if (NUCODEGEN_EADCSM3ADV)
    /* Advanced configuration */

    /* Trigger delay */
    EADC_SetTriggerDelayTime(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(3), NUCODEDEF_EADCSM3TD, NUCODEGEN_EADCSM3TDDIV);

    /* Extern sample time */
    EADC_SetExtendSampleTime(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(3), NUCODEDEF_EADCSM3ES);

#if (NUCODEGEN_EADCSM3DMA)
    /* Enable DMA support */
    EADC_ENABLE_PDMA(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(3));
#endif /* NUCODEGEN_EADCSM3DMA */

#if (NUCODEGEN_EADCSM3ALIGN)
    /* Enable data left alignment */
    EADC_ENABLE_LEFT_ALIGN(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(3));
#endif /* NUCODEGEN_EADCSM3ALIGN */

#if (NUCODEGEN_EADCSM3MODE == 1)
    /* Enable accumulate */
    EADC_ENABLE_ACU(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(3), NUCODEGEN_EADCSM3ACCU);
#elif (NUCODEGEN_EADCSM3MODE == 2)
    /* Enable average */
    EADC_ENABLE_ACU(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(3), NUCODEGEN_EADCSM3AVG);
    EADC_ENABLE_AVG(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(3));
#endif /* NUCODEGEN_EADCSM3MODE */

#endif /* NUCODEGEN_EADCSM3ADV */

#endif /* NUCODEGEN_EADCSM3EN */




#if (NUCODEGEN_EADCSM4EN)
    /* Sample module 4 */
    EADC_ConfigSampleModule(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(4), NUCODEGEN_EADCSM4TS, NUCODEDEF_EADCSM4CH);

    /* Enable interrupt and position */

#if (((NUCODEGEN_EADCSM4INTEN)&0x1) == 0x1)
    EADC_ENABLE_SAMPLE_MODULE_INT(NUCODEGEN_EADC_MODULE_SEL, AINT_SEL(0), BIT4 );
#endif /* (((NUCODEGEN_EADCSM4INTEN)&0x1) == 0x1) */
#if (((NUCODEGEN_EADCSM4INTEN)&0x2) == 0x2)
    EADC_ENABLE_SAMPLE_MODULE_INT(NUCODEGEN_EADC_MODULE_SEL, AINT_SEL(1), BIT4 );
#endif /* (((NUCODEGEN_EADCSM4INTEN)&0x2) == 0x2) */
#if (((NUCODEGEN_EADCSM4INTEN)&0x4) == 0x4)
    EADC_ENABLE_SAMPLE_MODULE_INT(NUCODEGEN_EADC_MODULE_SEL, AINT_SEL(2), BIT4 );
#endif /* (((NUCODEGEN_EADCSM4INTEN)&0x4) == 0x4) */
#if (((NUCODEGEN_EADCSM4INTEN)&0x8) == 0x8)
    EADC_ENABLE_SAMPLE_MODULE_INT(NUCODEGEN_EADC_MODULE_SEL, AINT_SEL(3), BIT4 );
#endif /* (((NUCODEGEN_EADCSM4INTEN)&0x8) == 0x8) */

#if (NUCODEGEN_EADCSM4IP)
    /* Interrupt start of conversion */
    EADC_ENABLE_INT_POSITION(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(4));
#endif /* NUCODEGEN_EADCSM4IP */

#if (NUCODEGEN_EADCSM4ADV)
    /* Advanced configuration */

    /* Trigger delay */
    EADC_SetTriggerDelayTime(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(4), NUCODEDEF_EADCSM4TD, NUCODEGEN_EADCSM4TDDIV);

    /* Extern sample time */
    EADC_SetExtendSampleTime(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(4), NUCODEDEF_EADCSM4ES);

#if (NUCODEGEN_EADCSM4DMA)
    /* Enable DMA support */
    EADC_ENABLE_PDMA(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(4));
#endif /* NUCODEGEN_EADCSM4DMA */

#if (NUCODEGEN_EADCSM4ALIGN)
    /* Enable data left alignment */
    EADC_ENABLE_LEFT_ALIGN(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(4));
#endif /* NUCODEGEN_EADCSM4ALIGN */

#if (NUCODEGEN_EADCSM4MODE == 1)
    /* Enable accumulate */
    EADC_ENABLE_ACU(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(4), NUCODEGEN_EADCSM4ACCU);
#elif (NUCODEGEN_EADCSM4MODE == 2)
    /* Enable average */
    EADC_ENABLE_ACU(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(4), NUCODEGEN_EADCSM4AVG);
    EADC_ENABLE_AVG(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(4));
#endif /* NUCODEGEN_EADCSM4MODE */

#endif /* NUCODEGEN_EADCSM4ADV */

#endif /* NUCODEGEN_EADCSM4EN */




#if (NUCODEGEN_EADCSM5EN)
    /* Sample module 5 */
    EADC_ConfigSampleModule(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(5), NUCODEGEN_EADCSM5TS, NUCODEDEF_EADCSM5CH);

    /* Enable interrupt and position */

#if (((NUCODEGEN_EADCSM5INTEN)&0x1) == 0x1)
    EADC_ENABLE_SAMPLE_MODULE_INT(NUCODEGEN_EADC_MODULE_SEL, AINT_SEL(0), BIT5 );
#endif /* (((NUCODEGEN_EADCSM5INTEN)&0x1) == 0x1) */
#if (((NUCODEGEN_EADCSM5INTEN)&0x2) == 0x2)
    EADC_ENABLE_SAMPLE_MODULE_INT(NUCODEGEN_EADC_MODULE_SEL, AINT_SEL(1), BIT5 );
#endif /* (((NUCODEGEN_EADCSM5INTEN)&0x2) == 0x2) */
#if (((NUCODEGEN_EADCSM5INTEN)&0x4) == 0x4)
    EADC_ENABLE_SAMPLE_MODULE_INT(NUCODEGEN_EADC_MODULE_SEL, AINT_SEL(2), BIT5 );
#endif /* (((NUCODEGEN_EADCSM5INTEN)&0x4) == 0x4) */
#if (((NUCODEGEN_EADCSM5INTEN)&0x8) == 0x8)
    EADC_ENABLE_SAMPLE_MODULE_INT(NUCODEGEN_EADC_MODULE_SEL, AINT_SEL(3), BIT5 );
#endif /* (((NUCODEGEN_EADCSM5INTEN)&0x8) == 0x8) */

#if (NUCODEGEN_EADCSM5IP)
    /* Interrupt start of conversion */
    EADC_ENABLE_INT_POSITION(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(5));
#endif /* NUCODEGEN_EADCSM5IP */

#if (NUCODEGEN_EADCSM5ADV)
    /* Advanced configuration */

    /* Trigger delay */
    EADC_SetTriggerDelayTime(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(5), NUCODEDEF_EADCSM5TD, NUCODEGEN_EADCSM5TDDIV);

    /* Extern sample time */
    EADC_SetExtendSampleTime(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(5), NUCODEDEF_EADCSM5ES);


#if (NUCODEGEN_EADCSM5DMA)
    /* Enable DMA support */
    EADC_ENABLE_PDMA(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(5));
#endif /* NUCODEGEN_EADCSM5DMA */

#if (NUCODEGEN_EADCSM5ALIGN)
    /* Enable data left alignment */
    EADC_ENABLE_LEFT_ALIGN(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(5));
#endif /* NUCODEGEN_EADCSM5ALIGN */

#if (NUCODEGEN_EADCSM5MODE == 1)
    /* Enable accumulate */
    EADC_ENABLE_ACU(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(5), NUCODEGEN_EADCSM5ACCU);
#elif (NUCODEGEN_EADCSM5MODE == 2)
    /* Enable average */
    EADC_ENABLE_ACU(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(5), NUCODEGEN_EADCSM5AVG);
    EADC_ENABLE_AVG(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(5));
#endif /* NUCODEGEN_EADCSM5MODE */

#endif /* NUCODEGEN_EADCSM5ADV */

#endif /* NUCODEGEN_EADCSM5EN */




#if (NUCODEGEN_EADCSM6EN)
    /* Sample module 6 */
    EADC_ConfigSampleModule(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(6), NUCODEGEN_EADCSM6TS, NUCODEDEF_EADCSM6CH);

    /* Enable interrupt and position */

#if (((NUCODEGEN_EADCSM6INTEN)&0x1) == 0x1)
    EADC_ENABLE_SAMPLE_MODULE_INT(NUCODEGEN_EADC_MODULE_SEL, AINT_SEL(0), BIT6 );
#endif /* (((NUCODEGEN_EADCSM6INTEN)&0x1) == 0x1) */
#if (((NUCODEGEN_EADCSM6INTEN)&0x2) == 0x2)
    EADC_ENABLE_SAMPLE_MODULE_INT(NUCODEGEN_EADC_MODULE_SEL, AINT_SEL(1), BIT6 );
#endif /* (((NUCODEGEN_EADCSM6INTEN)&0x2) == 0x2) */
#if (((NUCODEGEN_EADCSM6INTEN)&0x4) == 0x4)
    EADC_ENABLE_SAMPLE_MODULE_INT(NUCODEGEN_EADC_MODULE_SEL, AINT_SEL(2), BIT6 );
#endif /* (((NUCODEGEN_EADCSM6INTEN)&0x4) == 0x4) */
#if (((NUCODEGEN_EADCSM6INTEN)&0x8) == 0x8)
    EADC_ENABLE_SAMPLE_MODULE_INT(NUCODEGEN_EADC_MODULE_SEL, AINT_SEL(3), BIT6 );
#endif /* (((NUCODEGEN_EADCSM6INTEN)&0x8) == 0x8) */

#if (NUCODEGEN_EADCSM6IP)
    /* Interrupt start of conversion */
    EADC_ENABLE_INT_POSITION(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(6));
#endif /* NUCODEGEN_EADCSM6IP */

#if (NUCODEGEN_EADCSM6ADV)
    /* Advanced configuration */

    /* Trigger delay */
    EADC_SetTriggerDelayTime(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(6), NUCODEDEF_EADCSM6TD, NUCODEGEN_EADCSM6TDDIV);

    /* Extern sample time */
    EADC_SetExtendSampleTime(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(6), NUCODEDEF_EADCSM6ES);


#if (NUCODEGEN_EADCSM6DMA)
    /* Enable DMA support */
    EADC_ENABLE_PDMA(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(6));
#endif /* NUCODEGEN_EADCSM6DMA */

#if (NUCODEGEN_EADCSM6ALIGN)
    /* Enable data left alignment */
    EADC_ENABLE_LEFT_ALIGN(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(6));
#endif /* NUCODEGEN_EADCSM6ALIGN */

#if (NUCODEGEN_EADCSM6MODE == 1)
    /* Enable accumulate */
    EADC_ENABLE_ACU(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(6), NUCODEGEN_EADCSM6ACCU);
#elif (NUCODEGEN_EADCSM6MODE == 2)
    /* Enable average */
    EADC_ENABLE_ACU(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(6), NUCODEGEN_EADCSM6AVG);
    EADC_ENABLE_AVG(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(6));
#endif /* NUCODEGEN_EADCSM6MODE */

#endif /* NUCODEGEN_EADCSM6ADV */

#endif /* NUCODEGEN_EADCSM6EN */




#if (NUCODEGEN_EADCSM7EN)
    /* Sample module 7 */
    EADC_ConfigSampleModule(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(7), NUCODEGEN_EADCSM7TS, NUCODEDEF_EADCSM7CH);

    /* Enable interrupt and position */

#if (((NUCODEGEN_EADCSM7INTEN)&0x1) == 0x1)
    EADC_ENABLE_SAMPLE_MODULE_INT(NUCODEGEN_EADC_MODULE_SEL, AINT_SEL(0), BIT7 );
#endif /* (((NUCODEGEN_EADCSM7INTEN)&0x1) == 0x1) */
#if (((NUCODEGEN_EADCSM7INTEN)&0x2) == 0x2)
    EADC_ENABLE_SAMPLE_MODULE_INT(NUCODEGEN_EADC_MODULE_SEL, AINT_SEL(1), BIT7 );
#endif /* (((NUCODEGEN_EADCSM7INTEN)&0x2) == 0x2) */
#if (((NUCODEGEN_EADCSM7INTEN)&0x4) == 0x4)
    EADC_ENABLE_SAMPLE_MODULE_INT(NUCODEGEN_EADC_MODULE_SEL, AINT_SEL(2), BIT7 );
#endif /* (((NUCODEGEN_EADCSM7INTEN)&0x4) == 0x4) */
#if (((NUCODEGEN_EADCSM7INTEN)&0x8) == 0x8)
    EADC_ENABLE_SAMPLE_MODULE_INT(NUCODEGEN_EADC_MODULE_SEL, AINT_SEL(3), BIT7 );
#endif /* (((NUCODEGEN_EADCSM7INTEN)&0x8) == 0x8) */

#if (NUCODEGEN_EADCSM7IP)
    /* Interrupt start of conversion */
    EADC_ENABLE_INT_POSITION(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(7));
#endif /* NUCODEGEN_EADCSM7IP */

#if (NUCODEGEN_EADCSM7ADV)
    /* Advanced configuration */

    /* Trigger delay */
    EADC_SetTriggerDelayTime(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(7), NUCODEDEF_EADCSM7TD, NUCODEGEN_EADCSM7TDDIV);

    /* Extern sample time */
    EADC_SetExtendSampleTime(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(7), NUCODEDEF_EADCSM7ES);

#if (NUCODEGEN_EADCSM7DMA)
    /* Enable DMA support */
    EADC_ENABLE_PDMA(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(7));
#endif /* NUCODEGEN_EADCSM7DMA */

#if (NUCODEGEN_EADCSM7ALIGN)
    /* Enable data left alignment */
    EADC_ENABLE_LEFT_ALIGN(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(7));
#endif /* NUCODEGEN_EADCSM7ALIGN */

#if (NUCODEGEN_EADCSM7MODE == 1)
    /* Enable accumulate */
    EADC_ENABLE_ACU(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(7), NUCODEGEN_EADCSM7ACCU);
#elif (NUCODEGEN_EADCSM7MODE == 2)
    /* Enable average */
    EADC_ENABLE_ACU(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(7), NUCODEGEN_EADCSM7AVG);
    EADC_ENABLE_AVG(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(7));
#endif /* NUCODEGEN_EADCSM7MODE */

#endif /* NUCODEGEN_EADCSM7ADV */

#endif /* NUCODEGEN_EADCSM7EN */




#if (NUCODEGEN_EADCSM8EN)
    /* Sample module 8 */
    EADC_ConfigSampleModule(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(8), NUCODEGEN_EADCSM8TS, NUCODEDEF_EADCSM8CH);

    /* Enable interrupt and position */

#if (((NUCODEGEN_EADCSM8INTEN)&0x1) == 0x1)
    EADC_ENABLE_SAMPLE_MODULE_INT(NUCODEGEN_EADC_MODULE_SEL, AINT_SEL(0), BIT8 );
#endif /* (((NUCODEGEN_EADCSM8INTEN)&0x1) == 0x1) */
#if (((NUCODEGEN_EADCSM8INTEN)&0x2) == 0x2)
    EADC_ENABLE_SAMPLE_MODULE_INT(NUCODEGEN_EADC_MODULE_SEL, AINT_SEL(1), BIT8 );
#endif /* (((NUCODEGEN_EADCSM8INTEN)&0x2) == 0x2) */
#if (((NUCODEGEN_EADCSM8INTEN)&0x4) == 0x4)
    EADC_ENABLE_SAMPLE_MODULE_INT(NUCODEGEN_EADC_MODULE_SEL, AINT_SEL(2), BIT8 );
#endif /* (((NUCODEGEN_EADCSM8INTEN)&0x4) == 0x4) */
#if (((NUCODEGEN_EADCSM8INTEN)&0x8) == 0x8)
    EADC_ENABLE_SAMPLE_MODULE_INT(NUCODEGEN_EADC_MODULE_SEL, AINT_SEL(3), BIT8 );
#endif /* (((NUCODEGEN_EADCSM8INTEN)&0x8) == 0x8) */

#if (NUCODEGEN_EADCSM8IP)
    /* Interrupt start of conversion */
    EADC_ENABLE_INT_POSITION(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(8));
#endif /* NUCODEGEN_EADCSM8IP */

#if (NUCODEGEN_EADCSM8ADV)
    /* Advanced configuration */

    /* Trigger delay */
    EADC_SetTriggerDelayTime(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(8), NUCODEDEF_EADCSM8TD, NUCODEGEN_EADCSM8TDDIV);

    /* Extern sample time */
    EADC_SetExtendSampleTime(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(8), NUCODEDEF_EADCSM8ES);


#if (NUCODEGEN_EADCSM8DMA)
    /* Enable DMA support */
    EADC_ENABLE_PDMA(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(8));
#endif /* NUCODEGEN_EADCSM8DMA */

#if (NUCODEGEN_EADCSM8ALIGN)
    /* Enable data left alignment */
    EADC_ENABLE_LEFT_ALIGN(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(8));
#endif /* NUCODEGEN_EADCSM8ALIGN */

#if (NUCODEGEN_EADCSM8MODE == 1)
    /* Enable accumulate */
    EADC_ENABLE_ACU(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(8), NUCODEGEN_EADCSM8ACCU);
#elif (NUCODEGEN_EADCSM8MODE == 2)
    /* Enable average */
    EADC_ENABLE_ACU(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(8), NUCODEGEN_EADCSM8AVG);
    EADC_ENABLE_AVG(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(8));
#endif /* NUCODEGEN_EADCSM8MODE */

#endif /* NUCODEGEN_EADCSM8ADV */

#endif /* NUCODEGEN_EADCSM8EN */




#if (NUCODEGEN_EADCSM9EN)
    /* Sample module 9 */
    EADC_ConfigSampleModule(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(9), NUCODEGEN_EADCSM9TS, NUCODEDEF_EADCSM9CH);

    /* Enable interrupt and position */

#if (((NUCODEGEN_EADCSM9INTEN)&0x1) == 0x1)
    EADC_ENABLE_SAMPLE_MODULE_INT(NUCODEGEN_EADC_MODULE_SEL, AINT_SEL(0), BIT9 );
#endif /* (((NUCODEGEN_EADCSM9INTEN)&0x1) == 0x1) */
#if (((NUCODEGEN_EADCSM9INTEN)&0x2) == 0x2)
    EADC_ENABLE_SAMPLE_MODULE_INT(NUCODEGEN_EADC_MODULE_SEL, AINT_SEL(1), BIT9 );
#endif /* (((NUCODEGEN_EADCSM9INTEN)&0x2) == 0x2) */
#if (((NUCODEGEN_EADCSM9INTEN)&0x4) == 0x4)
    EADC_ENABLE_SAMPLE_MODULE_INT(NUCODEGEN_EADC_MODULE_SEL, AINT_SEL(2), BIT9 );
#endif /* (((NUCODEGEN_EADCSM9INTEN)&0x4) == 0x4) */
#if (((NUCODEGEN_EADCSM9INTEN)&0x8) == 0x8)
    EADC_ENABLE_SAMPLE_MODULE_INT(NUCODEGEN_EADC_MODULE_SEL, AINT_SEL(3), BIT9 );
#endif /* (((NUCODEGEN_EADCSM9INTEN)&0x8) == 0x8) */

#if (NUCODEGEN_EADCSM9IP)
    /* Interrupt start of conversion */
    EADC_ENABLE_INT_POSITION(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(9));
#endif /* NUCODEGEN_EADCSM9IP */

#if (NUCODEGEN_EADCSM9ADV)
    /* Advanced configuration */

    /* Trigger delay */
    EADC_SetTriggerDelayTime(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(9), NUCODEDEF_EADCSM9TD, NUCODEGEN_EADCSM9TDDIV);

    /* Extern sample time */
    EADC_SetExtendSampleTime(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(9), NUCODEDEF_EADCSM9ES);

#if (NUCODEGEN_EADCSM9DMA)
    /* Enable DMA support */
    EADC_ENABLE_PDMA(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(9));
#endif /* NUCODEGEN_EADCSM9DMA */

#if (NUCODEGEN_EADCSM9ALIGN)
    /* Enable data left alignment */
    EADC_ENABLE_LEFT_ALIGN(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(9));
#endif /* NUCODEGEN_EADCSM9ALIGN */

#if (NUCODEGEN_EADCSM9MODE == 1)
    /* Enable accumulate */
    EADC_ENABLE_ACU(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(9), NUCODEGEN_EADCSM9ACCU);
#elif (NUCODEGEN_EADCSM9MODE == 2)
    /* Enable average */
    EADC_ENABLE_ACU(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(9), NUCODEGEN_EADCSM9AVG);
    EADC_ENABLE_AVG(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(9));
#endif /* NUCODEGEN_EADCSM9MODE */

#endif /* NUCODEGEN_EADCSM9ADV */

#endif /* NUCODEGEN_EADCSM9EN */




#if (NUCODEGEN_EADCSM10EN)
    /* Sample module 10 */
    EADC_ConfigSampleModule(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(10), NUCODEGEN_EADCSM10TS, NUCODEDEF_EADCSM10CH);

    /* Enable interrupt and position */

#if (((NUCODEGEN_EADCSM10INTEN)&0x1) == 0x1)
    EADC_ENABLE_SAMPLE_MODULE_INT(NUCODEGEN_EADC_MODULE_SEL, AINT_SEL(0), BIT10 );
#endif /* (((NUCODEGEN_EADCSM10INTEN)&0x1) == 0x1) */
#if (((NUCODEGEN_EADCSM10INTEN)&0x2) == 0x2)
    EADC_ENABLE_SAMPLE_MODULE_INT(NUCODEGEN_EADC_MODULE_SEL, AINT_SEL(1), BIT10 );
#endif /* (((NUCODEGEN_EADCSM10INTEN)&0x2) == 0x2) */
#if (((NUCODEGEN_EADCSM10INTEN)&0x4) == 0x4)
    EADC_ENABLE_SAMPLE_MODULE_INT(NUCODEGEN_EADC_MODULE_SEL, AINT_SEL(2), BIT10 );
#endif /* (((NUCODEGEN_EADCSM10INTEN)&0x4) == 0x4) */
#if (((NUCODEGEN_EADCSM10INTEN)&0x8) == 0x8)
    EADC_ENABLE_SAMPLE_MODULE_INT(NUCODEGEN_EADC_MODULE_SEL, AINT_SEL(3), BIT10 );
#endif /* (((NUCODEGEN_EADCSM10INTEN)&0x8) == 0x8) */

#if (NUCODEGEN_EADCSM10IP)
    /* Interrupt start of conversion */
    EADC_ENABLE_INT_POSITION(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(10));
#endif /* NUCODEGEN_EADCSM10IP */

#if (NUCODEGEN_EADCSM10ADV)
    /* Advanced configuration */

    /* Trigger delay */
    EADC_SetTriggerDelayTime(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(10), NUCODEDEF_EADCSM10TD, NUCODEGEN_EADCSM10TDDIV);

    /* Extern sample time */
    EADC_SetExtendSampleTime(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(10), NUCODEDEF_EADCSM10ES);

#if (NUCODEGEN_EADCSM10DMA)
    /* Enable DMA support */
    EADC_ENABLE_PDMA(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(10));
#endif /* NUCODEGEN_EADCSM10DMA */

#if (NUCODEGEN_EADCSM10ALIGN)
    /* Enable data left alignment */
    EADC_ENABLE_LEFT_ALIGN(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(10));
#endif /* NUCODEGEN_EADCSM10ALIGN */

#if (NUCODEGEN_EADCSM10MODE == 1)
    /* Enable accumulate */
    EADC_ENABLE_ACU(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(10), NUCODEGEN_EADCSM10ACCU);
#elif (NUCODEGEN_EADCSM10MODE == 2)
    /* Enable average */
    EADC_ENABLE_ACU(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(10), NUCODEGEN_EADCSM10AVG);
    EADC_ENABLE_AVG(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(10));
#endif /* NUCODEGEN_EADCSM10MODE */

#endif /* NUCODEGEN_EADCSM10ADV */

#endif /* NUCODEGEN_EADCSM10EN */




#if (NUCODEGEN_EADCSM11EN)
    /* Sample module 11 */
    EADC_ConfigSampleModule(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(11), NUCODEGEN_EADCSM11TS, NUCODEDEF_EADCSM11CH);

    /* Enable interrupt and position */

#if (((NUCODEGEN_EADCSM11INTEN)&0x1) == 0x1)
    EADC_ENABLE_SAMPLE_MODULE_INT(NUCODEGEN_EADC_MODULE_SEL, AINT_SEL(0), BIT11 );
#endif /* (((NUCODEGEN_EADCSM11INTEN)&0x1) == 0x1) */
#if (((NUCODEGEN_EADCSM11INTEN)&0x2) == 0x2)
    EADC_ENABLE_SAMPLE_MODULE_INT(NUCODEGEN_EADC_MODULE_SEL, AINT_SEL(1), BIT11 );
#endif /* (((NUCODEGEN_EADCSM11INTEN)&0x2) == 0x2) */
#if (((NUCODEGEN_EADCSM11INTEN)&0x4) == 0x4)
    EADC_ENABLE_SAMPLE_MODULE_INT(NUCODEGEN_EADC_MODULE_SEL, AINT_SEL(2), BIT11 );
#endif /* (((NUCODEGEN_EADCSM11INTEN)&0x4) == 0x4) */
#if (((NUCODEGEN_EADCSM11INTEN)&0x8) == 0x8)
    EADC_ENABLE_SAMPLE_MODULE_INT(NUCODEGEN_EADC_MODULE_SEL, AINT_SEL(3), BIT11 );
#endif /* (((NUCODEGEN_EADCSM11INTEN)&0x8) == 0x8) */

#if (NUCODEGEN_EADCSM11IP)
    /* Interrupt start of conversion */
    EADC_ENABLE_INT_POSITION(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(11));
#endif /* NUCODEGEN_EADCSM11IP */

#if (NUCODEGEN_EADCSM11ADV)
    /* Advanced configuration*/

    /* Trigger delay */
    EADC_SetTriggerDelayTime(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(11), NUCODEDEF_EADCSM11TD, NUCODEGEN_EADCSM11TDDIV);

    /* Extern sample time */
    EADC_SetExtendSampleTime(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(11), NUCODEDEF_EADCSM11ES);

#if (NUCODEGEN_EADCSM11DMA)
    /* Enable DMA support */
    EADC_ENABLE_PDMA(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(11));
#endif /* NUCODEGEN_EADCSM11DMA */

#if (NUCODEGEN_EADCSM11ALIGN)
    /* Enable data left alignment */
    EADC_ENABLE_LEFT_ALIGN(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(11));
#endif /* NUCODEGEN_EADCSM11ALIGN */

#if (NUCODEGEN_EADCSM11MODE == 1)
    /* Enable accumulate */
    EADC_ENABLE_ACU(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(11), NUCODEGEN_EADCSM11ACCU);
#elif (NUCODEGEN_EADCSM11MODE == 2)
    /* Enable average */
    EADC_ENABLE_ACU(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(11), NUCODEGEN_EADCSM11AVG);
    EADC_ENABLE_AVG(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(11));
#endif /* NUCODEGEN_EADCSM11MODE */

#endif /* NUCODEGEN_EADCSM11ADV */

#endif /* NUCODEGEN_EADCSM11EN */




#if (NUCODEGEN_EADCSM12EN)
    /* Sample module 12 */
    EADC_ConfigSampleModule(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(12), NUCODEGEN_EADCSM12TS, NUCODEDEF_EADCSM12CH);

    /* Enable interrupt and position */

#if (((NUCODEGEN_EADCSM12INTEN)&0x1) == 0x1)
    EADC_ENABLE_SAMPLE_MODULE_INT(NUCODEGEN_EADC_MODULE_SEL, AINT_SEL(0), BIT12 );
#endif /* (((NUCODEGEN_EADCSM12INTEN)&0x1) == 0x1) */
#if (((NUCODEGEN_EADCSM12INTEN)&0x2) == 0x2)
    EADC_ENABLE_SAMPLE_MODULE_INT(NUCODEGEN_EADC_MODULE_SEL, AINT_SEL(1), BIT12 );
#endif /* (((NUCODEGEN_EADCSM12INTEN)&0x2) == 0x2) */
#if (((NUCODEGEN_EADCSM12INTEN)&0x4) == 0x4)
    EADC_ENABLE_SAMPLE_MODULE_INT(NUCODEGEN_EADC_MODULE_SEL, AINT_SEL(2), BIT12 );
#endif /* (((NUCODEGEN_EADCSM12INTEN)&0x4) == 0x4) */
#if (((NUCODEGEN_EADCSM12INTEN)&0x8) == 0x8)
    EADC_ENABLE_SAMPLE_MODULE_INT(NUCODEGEN_EADC_MODULE_SEL, AINT_SEL(3), BIT12 );
#endif /* (((NUCODEGEN_EADCSM12INTEN)&0x8) == 0x8) */

#if (NUCODEGEN_EADCSM12IP)
    /* Interrupt start of conversion */
    EADC_ENABLE_INT_POSITION(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(12));
#endif /* NUCODEGEN_EADCSM12IP */

#if (NUCODEGEN_EADCSM12ADV)
    /* Advanced configuration */

    /* Trigger delay */
    EADC_SetTriggerDelayTime(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(12), NUCODEDEF_EADCSM12TD, NUCODEGEN_EADCSM12TDDIV);

    /* Extern sample time */
    EADC_SetExtendSampleTime(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(12), NUCODEDEF_EADCSM12ES);

#if (NUCODEGEN_EADCSM12DMA)
    /* Enable DMA support */
    EADC_ENABLE_PDMA(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(12));
#endif /* NUCODEGEN_EADCSM12DMA */

#if (NUCODEGEN_EADCSM12ALIGN)
    /* Enable data left alignment */
    EADC_ENABLE_LEFT_ALIGN(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(12));
#endif /* NUCODEGEN_EADCSM12ALIGN */

#if (NUCODEGEN_EADCSM12MODE == 1)
    /* Enable accumulate */
    EADC_ENABLE_ACU(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(12), NUCODEGEN_EADCSM12ACCU);
#elif (NUCODEGEN_EADCSM12MODE == 2)
    /* Enable average */
    EADC_ENABLE_ACU(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(12), NUCODEGEN_EADCSM12AVG);
    EADC_ENABLE_AVG(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(12));
#endif /* NUCODEGEN_EADCSM12MODE */

#endif /* NUCODEGEN_EADCSM12ADV */

#endif /* NUCODEGEN_EADCSM12EN */



#if (NUCODEGEN_EADCSM13EN)
    /* Sample module 13 */
    EADC_ConfigSampleModule(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(13), NUCODEGEN_EADCSM13TS, NUCODEDEF_EADCSM13CH);

    /* Enable interrupt and position */

#if (((NUCODEGEN_EADCSM13INTEN)&0x1) == 0x1)
    EADC_ENABLE_SAMPLE_MODULE_INT(NUCODEGEN_EADC_MODULE_SEL, AINT_SEL(0), BIT13 );
#endif /* (((NUCODEGEN_EADCSM13INTEN)&0x1) == 0x1) */
#if (((NUCODEGEN_EADCSM13INTEN)&0x2) == 0x2)
    EADC_ENABLE_SAMPLE_MODULE_INT(NUCODEGEN_EADC_MODULE_SEL, AINT_SEL(1), BIT13 );
#endif /* (((NUCODEGEN_EADCSM13INTEN)&0x2) == 0x2) */
#if (((NUCODEGEN_EADCSM13INTEN)&0x4) == 0x4)
    EADC_ENABLE_SAMPLE_MODULE_INT(NUCODEGEN_EADC_MODULE_SEL, AINT_SEL(2), BIT13 );
#endif /* (((NUCODEGEN_EADCSM13INTEN)&0x4) == 0x4) */
#if (((NUCODEGEN_EADCSM13INTEN)&0x8) == 0x8)
    EADC_ENABLE_SAMPLE_MODULE_INT(NUCODEGEN_EADC_MODULE_SEL, AINT_SEL(3), BIT13 );
#endif /* (((NUCODEGEN_EADCSM13INTEN)&0x8) == 0x8) */

#if (NUCODEGEN_EADCSM13IP)
    /* Interrupt start of conversion */
    EADC_ENABLE_INT_POSITION(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(13));
#endif /* NUCODEGEN_EADCSM13IP */

#if (NUCODEGEN_EADCSM13ADV)
    /* Advanced configuration */

    /* Trigger delay */
    EADC_SetTriggerDelayTime(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(13), NUCODEDEF_EADCSM13TD, NUCODEGEN_EADCSM13TDDIV);

    /* Extern sample time */
    EADC_SetExtendSampleTime(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(13), NUCODEDEF_EADCSM13ES);

#if (NUCODEGEN_EADCSM13DMA)
    /* Enable DMA support */
    EADC_ENABLE_PDMA(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(13));
#endif /* NUCODEGEN_EADCSM13DMA */

#if (NUCODEGEN_EADCSM13ALIGN)
    /* Enable data left alignment */
    EADC_ENABLE_LEFT_ALIGN(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(13));
#endif /* NUCODEGEN_EADCSM13ALIGN */

#if (NUCODEGEN_EADCSM13MODE == 1)
    /* Enable accumulate */
    EADC_ENABLE_ACU(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(13), NUCODEGEN_EADCSM13ACCU);
#elif (NUCODEGEN_EADCSM13MODE == 2)
    /* Enable average */
    EADC_ENABLE_ACU(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(13), NUCODEGEN_EADCSM13AVG);
    EADC_ENABLE_AVG(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(13));
#endif /* NUCODEGEN_EADCSM13MODE */

#endif /* NUCODEGEN_EADCSM13ADV */

#endif /* NUCODEGEN_EADCSM13EN */



#if (NUCODEGEN_EADCSM14EN)
    /* Sample module 14 */
    EADC_ConfigSampleModule(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(14), NUCODEGEN_EADCSM14TS, NUCODEDEF_EADCSM14CH);

    /* Enable interrupt and position */

#if (((NUCODEGEN_EADCSM14INTEN)&0x1) == 0x1)
    EADC_ENABLE_SAMPLE_MODULE_INT(NUCODEGEN_EADC_MODULE_SEL, AINT_SEL(0), BIT14 );
#endif /* (((NUCODEGEN_EADCSM14INTEN)&0x1) == 0x1) */
#if (((NUCODEGEN_EADCSM14INTEN)&0x2) == 0x2)
    EADC_ENABLE_SAMPLE_MODULE_INT(NUCODEGEN_EADC_MODULE_SEL, AINT_SEL(1), BIT14 );
#endif /* (((NUCODEGEN_EADCSM14INTEN)&0x2) == 0x2) */
#if (((NUCODEGEN_EADCSM14INTEN)&0x4) == 0x4)
    EADC_ENABLE_SAMPLE_MODULE_INT(NUCODEGEN_EADC_MODULE_SEL, AINT_SEL(2), BIT14 );
#endif /* (((NUCODEGEN_EADCSM14INTEN)&0x4) == 0x4) */
#if (((NUCODEGEN_EADCSM14INTEN)&0x8) == 0x8)
    EADC_ENABLE_SAMPLE_MODULE_INT(NUCODEGEN_EADC_MODULE_SEL, AINT_SEL(3), BIT14 );
#endif /* (((NUCODEGEN_EADCSM14INTEN)&0x8) == 0x8) */

#if (NUCODEGEN_EADCSM14IP)
    /* Interrupt start of conversion */
    EADC_ENABLE_INT_POSITION(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(14));
#endif /* NUCODEGEN_EADCSM14IP */

#if (NUCODEGEN_EADCSM14ADV)
    /* Advanced configuration */

    /* Trigger delay */
    EADC_SetTriggerDelayTime(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(14), NUCODEDEF_EADCSM14TD, NUCODEGEN_EADCSM14TDDIV);

    /* Extern sample time */
    EADC_SetExtendSampleTime(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(14), NUCODEDEF_EADCSM14ES);

    /* Enable DMA support */
#if (NUCODEGEN_EADCSM14DMA)
    EADC_ENABLE_PDMA(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(14));
#endif /* NUCODEGEN_EADCSM14DMA */

    /* Enable data left alignment */
#if (NUCODEGEN_EADCSM14ALIGN)
    EADC_ENABLE_LEFT_ALIGN(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(14));
#endif /* NUCODEGEN_EADCSM14ALIGN */

#if (NUCODEGEN_EADCSM14MODE == 1)
    /* Enable accumulate */
    EADC_ENABLE_ACU(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(14), NUCODEGEN_EADCSM14ACCU);
#elif (NUCODEGEN_EADCSM14MODE == 2)
    /* Enable average */
    EADC_ENABLE_ACU(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(14), NUCODEGEN_EADCSM14AVG);
    EADC_ENABLE_AVG(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(14));
#endif /* NUCODEGEN_EADCSM14MODE */

#endif /* NUCODEGEN_EADCSM14ADV */

#endif /* NUCODEGEN_EADCSM14EN */




#if (NUCODEGEN_EADCSM15EN)
    /* Sample module 15 */
    EADC_ConfigSampleModule(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(15), NUCODEGEN_EADCSM15TS, NUCODEDEF_EADCSM15CH);

    /* Enable interrupt and position */

#if (((NUCODEGEN_EADCSM15INTEN)&0x1) == 0x1)
    EADC_ENABLE_SAMPLE_MODULE_INT(NUCODEGEN_EADC_MODULE_SEL, AINT_SEL(0), BIT15 );
#endif /* (((NUCODEGEN_EADCSM15INTEN)&0x1) == 0x1) */
#if (((NUCODEGEN_EADCSM15INTEN)&0x2) == 0x2)
    EADC_ENABLE_SAMPLE_MODULE_INT(NUCODEGEN_EADC_MODULE_SEL, AINT_SEL(1), BIT15 );
#endif /* (((NUCODEGEN_EADCSM15INTEN)&0x2) == 0x2) */
#if (((NUCODEGEN_EADCSM15INTEN)&0x4) == 0x4)
    EADC_ENABLE_SAMPLE_MODULE_INT(NUCODEGEN_EADC_MODULE_SEL, AINT_SEL(2), BIT15 );
#endif /* (((NUCODEGEN_EADCSM15INTEN)&0x4) == 0x4) */
#if (((NUCODEGEN_EADCSM15INTEN)&0x8) == 0x8)
    EADC_ENABLE_SAMPLE_MODULE_INT(NUCODEGEN_EADC_MODULE_SEL, AINT_SEL(3), BIT15 );
#endif /* (((NUCODEGEN_EADCSM15INTEN)&0x8) == 0x8) */

#if (NUCODEGEN_EADCSM15IP)
    /* Interrupt start of conversion */
    EADC_ENABLE_INT_POSITION(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(15));
#endif /* NUCODEGEN_EADCSM15IP */

#if (NUCODEGEN_EADCSM15ADV)
    /* Advanced configuration */

    /* Trigger delay */
    EADC_SetTriggerDelayTime(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(15), NUCODEDEF_EADCSM15TD, NUCODEGEN_EADCSM15TDDIV);

    /* Extern sample time */
    EADC_SetExtendSampleTime(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(15), NUCODEDEF_EADCSM15ES);

#if (NUCODEGEN_EADCSM15DMA)
    /* Enable DMA support */
    EADC_ENABLE_PDMA(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(15));
#endif /* NUCODEGEN_EADCSM15DMA */

#if (NUCODEGEN_EADCSM15ALIGN)
    /* Enable data left alignment */
    EADC_ENABLE_LEFT_ALIGN(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(15));
#endif /* NUCODEGEN_EADCSM15ALIGN */

#if (NUCODEGEN_EADCSM15MODE == 1)
    /* Enable accumulate */
    EADC_ENABLE_ACU(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(15), NUCODEGEN_EADCSM15ACCU);
#elif (NUCODEGEN_EADCSM15MODE == 2)
    /* Enable average */
    EADC_ENABLE_ACU(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(15), NUCODEGEN_EADCSM15AVG);
    EADC_ENABLE_AVG(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(15));
#endif /* NUCODEGEN_EADCSM15MODE */

#endif /* NUCODEGEN_EADCSM15ADV */

#endif /* NUCODEGEN_EADCSM15EN */



#if (NUCODEGEN_EADCSM16EN)
    /* Sample module 16 (VBG) */


    /* Enable interrupt */
#if (((NUCODEGEN_EADCSM16INTEN)&0x1) == 0x1)
    EADC_ENABLE_SAMPLE_MODULE_INT(NUCODEGEN_EADC_MODULE_SEL, AINT_SEL(0), BIT16 );
#endif /* (((NUCODEGEN_EADCSM16INTEN)&0x1) == 0x1) */
#if (((NUCODEGEN_EADCSM16INTEN)&0x2) == 0x2)
    EADC_ENABLE_SAMPLE_MODULE_INT(NUCODEGEN_EADC_MODULE_SEL, AINT_SEL(1), BIT16 );
#endif /* (((NUCODEGEN_EADCSM16INTEN)&0x2) == 0x2) */
#if (((NUCODEGEN_EADCSM16INTEN)&0x4) == 0x4)
    EADC_ENABLE_SAMPLE_MODULE_INT(NUCODEGEN_EADC_MODULE_SEL, AINT_SEL(2), BIT16 );
#endif /* (((NUCODEGEN_EADCSM16INTEN)&0x4) == 0x4) */
#if (((NUCODEGEN_EADCSM16INTEN)&0x8) == 0x8)
    EADC_ENABLE_SAMPLE_MODULE_INT(NUCODEGEN_EADC_MODULE_SEL, AINT_SEL(3), BIT16 );
#endif /* (((NUCODEGEN_EADCSM16INTEN)&0x8) == 0x8) */

#if (NUCODEGEN_EADCSM16ADV)
    /* Advanced configuration */

    /* Extern sample time */
    EADC_SetExtendSampleTime(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(16), NUCODEDEF_EADCSM16ES);

#if (NUCODEGEN_EADCSM16DMA)
    /* Enable DMA support */
    EADC_ENABLE_PDMA(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(16));
#endif /* NUCODEGEN_EADCSM16DMA */

#endif /* NUCODEGEN_EADCSM16ADV */

#endif /* NUCODEGEN_EADCSM16EN */



#if (NUCODEGEN_EADCSM17EN)
    /* Sample module 17 (Temp)*/


    /* Enable interrupt */
#if (((NUCODEGEN_EADCSM17INTEN)&0x1) == 0x1)
    EADC_ENABLE_SAMPLE_MODULE_INT(NUCODEGEN_EADC_MODULE_SEL, AINT_SEL(0), BIT17 );
#endif /* (((NUCODEGEN_EADCSM17INTEN)&0x1) == 0x1) */
#if (((NUCODEGEN_EADCSM17INTEN)&0x2) == 0x2)
    EADC_ENABLE_SAMPLE_MODULE_INT(NUCODEGEN_EADC_MODULE_SEL, AINT_SEL(1), BIT17 );
#endif /* (((NUCODEGEN_EADCSM17INTEN)&0x2) == 0x2) */
#if (((NUCODEGEN_EADCSM17INTEN)&0x4) == 0x4)
    EADC_ENABLE_SAMPLE_MODULE_INT(NUCODEGEN_EADC_MODULE_SEL, AINT_SEL(2), BIT17 );
#endif /* (((NUCODEGEN_EADCSM17INTEN)&0x4) == 0x4) */
#if (((NUCODEGEN_EADCSM17INTEN)&0x8) == 0x8)
    EADC_ENABLE_SAMPLE_MODULE_INT(NUCODEGEN_EADC_MODULE_SEL, AINT_SEL(3), BIT17 );
#endif /* (((NUCODEGEN_EADCSM17INTEN)&0x8) == 0x8) */

#if (NUCODEGEN_EADCSM17ADV)
    /* Advanced configuration */

    /* Extern sample time */
    EADC_SetExtendSampleTime(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(17), NUCODEDEF_EADCSM17ES);

#if (NUCODEGEN_EADCSM17DMA)
    /* Enable DMA support */
    EADC_ENABLE_PDMA(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(17));
#endif /* NUCODEGEN_EADCSM17DMA */

#endif /* NUCODEGEN_EADCSM17ADV */

#endif /* NUCODEGEN_EADCSM17EN */



#if (NUCODEGEN_EADCSM18EN)
    /* Sample module 18 (VBAT)*/


    /* Enable interrupt */
#if (((NUCODEGEN_EADCSM18INTEN)&0x1) == 0x1)
    EADC_ENABLE_SAMPLE_MODULE_INT(NUCODEGEN_EADC_MODULE_SEL, AINT_SEL(0), BIT18 );
#endif /* (((NUCODEGEN_EADCSM18INTEN)&0x1) == 0x1) */
#if (((NUCODEGEN_EADCSM18INTEN)&0x2) == 0x2)
    EADC_ENABLE_SAMPLE_MODULE_INT(NUCODEGEN_EADC_MODULE_SEL, AINT_SEL(1), BIT18 );
#endif /* (((NUCODEGEN_EADCSM18INTEN)&0x2) == 0x2) */
#if (((NUCODEGEN_EADCSM18INTEN)&0x4) == 0x4)
    EADC_ENABLE_SAMPLE_MODULE_INT(NUCODEGEN_EADC_MODULE_SEL, AINT_SEL(2), BIT18 );
#endif /* (((NUCODEGEN_EADCSM18INTEN)&0x4) == 0x4) */
#if (((NUCODEGEN_EADCSM18INTEN)&0x8) == 0x8)
    EADC_ENABLE_SAMPLE_MODULE_INT(NUCODEGEN_EADC_MODULE_SEL, AINT_SEL(3), BIT18 );
#endif /* (((NUCODEGEN_EADCSM18INTEN)&0x8) == 0x8) */

#if (NUCODEGEN_EADCSM18ADV)
    /* Advanced configuration */

    /* Extern sample time */
    EADC_SetExtendSampleTime(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(18), NUCODEDEF_EADCSM18ES);

#if (NUCODEGEN_EADCSM18DMA)
    /* Enable DMA support */
    EADC_ENABLE_PDMA(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(18));
#endif /* NUCODEGEN_EADCSM18DMA */

#endif /* NUCODEGEN_EADCSM18ADV */

#endif /* NUCODEGEN_EADCSM18EN */

#if (NUCODEGEN_EADCCMP0CMPEN || NUCODEGEN_EADCCMP1CMPEN || NUCODEGEN_EADCCMP2CMPEN || NUCODEGEN_EADCCMP3CMPEN)
/* --------------------------------------------------------------------
 * Compare configuration 0~3
 * ---------------------------------------------------------------------*/
#endif
#if (NUCODEGEN_EADCCMP0CMPEN)
    /* Compare 0 */
    EADC_ENABLE_CMP0(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(NUCODEGEN_EADCCMP0CMPSM), NUCODEGEN_EADCCMP0CMPCD, NUCODEDEF_EADCCMP0CMPDT, NUCODEDEF_EADCCMP0CMPMC);

#if (NUCODEGEN_EADCCMP0CMPINT)
    /* Comprae 0 interrupt enable */
    EADC_ENABLE_CMP_INT(NUCODEGEN_EADC_MODULE_SEL, COMPARE_SEL(0));
#endif /* NUCODEGEN_EADCCMP0CMPINT */

#if (NUCODEGEN_EADCCMP0CMPW)
    /* Comprae window 0 & 1 enable */
    EADC_ENABLE_CMP_WINDOW_MODE(NUCODEGEN_EADC_MODULE_SEL, COMPARE_SEL(0));
#endif /* NUCODEGEN_EADCCMP0CMPW */
#endif /* NUCODEGEN_EADCCMP0CMPEN */


#if (NUCODEGEN_EADCCMP1CMPEN)
    /* Compare 1 */
    EADC_ENABLE_CMP1(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(NUCODEGEN_EADCCMP1CMPSM), NUCODEGEN_EADCCMP1CMPCD, NUCODEDEF_EADCCMP1CMPDT, NUCODEDEF_EADCCMP1CMPMC);

#if (NUCODEGEN_EADCCMP1CMPINT)
    /* Comprae 1 interrupt enable */
    EADC_ENABLE_CMP_INT(NUCODEGEN_EADC_MODULE_SEL, COMPARE_SEL(1));
#endif /* NUCODEGEN_EADCCMP1CMPINT */
#endif /* NUCODEGEN_EADCCMP1CMPEN */


#if (NUCODEGEN_EADCCMP2CMPEN)
    /* Compare 2 */
    EADC_ENABLE_CMP2(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(NUCODEGEN_EADCCMP2CMPSM), NUCODEGEN_EADCCMP2CMPCD, NUCODEDEF_EADCCMP2CMPDT, NUCODEDEF_EADCCMP2CMPMC);

#if (NUCODEGEN_EADCCMP2CMPINT)
    /* Comprae 2 interrupt enable */
    EADC_ENABLE_CMP_INT(NUCODEGEN_EADC_MODULE_SEL, COMPARE_SEL(2));
#endif /* NUCODEGEN_EADCCMP2CMPINT */

#if (NUCODEGEN_EADCCMP2CMPW)
    /* Comprae window 2 & 3 enable */
    EADC_ENABLE_CMP_WINDOW_MODE(NUCODEGEN_EADC_MODULE_SEL, COMPARE_SEL(2));
#endif /* NUCODEGEN_EADCCMP2CMPW */
#endif /* NUCODEGEN_EADCCMP2CMPEN */


#if (NUCODEGEN_EADCCMP3CMPEN)
    /* Compare 3 */
    EADC_ENABLE_CMP3(NUCODEGEN_EADC_MODULE_SEL, SAMPLE_MODULE_SEL(NUCODEGEN_EADCCMP3CMPSM), NUCODEGEN_EADCCMP3CMPCD, NUCODEDEF_EADCCMP3CMPDT, NUCODEDEF_EADCCMP3CMPMC);

#if (NUCODEGEN_EADCCMP3CMPINT)
    /* Comprae 3 interrupt enable */
    EADC_ENABLE_CMP_INT(NUCODEGEN_EADC_MODULE_SEL, COMPARE_SEL(3));
#endif /* NUCODEGEN_EADCCMP3CMPINT */
#endif /* NUCODEGEN_EADCCMP3CMPEN */



}
#endif /* NUCODEGEN_EADC */


#if (NUCODEGEN_FMC)
void FMC_Init()
{
#if (NUCODEGEN_FMC_ISPEN)
    /* Enable FMC ISP function */
    FMC_Open();
#endif /* NUCODEGEN_FMC_ISPEN */

#if (NUCODEGEN_FMC_APROMEN)
    /* APROM update enable */
    FMC_EnableAPUpdate();
#endif /* NUCODEGEN_FMC_APROMEN */

#if (NUCODEGEN_FMC_LDROMEN)
    /* LDROM update enable */
    FMC_EnableLDUpdate();
#endif /* NUCODEGEN_FMC_LDROMEN */

#if (NUCODEGEN_FMC_SPROMEN)
    /* SPROM update enable */

#endif /* NUCODEGEN_FMC_SPROMEN */

#if (NUCODEGEN_FMC_CONFIGEN)
    /* Config update enable */
    FMC_EnableConfigUpdate();
#endif /* NUCODEGEN_FMC_CONFIGEN */

}
#endif /* NUCODEGEN_FMC */


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


#if (NUCODEGEN_OPA)
void OPA_Init()
{
#if (NUCODEGEN_OPA_SCHMIT_BUF_EN)
    /* Enable OPA0 schmitt trigger buffer */
    OPA_ENABLE_SCH_TRIGGER(NUCODEGEN_OPA_MODULE_SEL, OPA_MODULE_0);
#endif /* NUCODEGEN_OPA_SCHMIT_BUF_EN */

    /* Power on the OPA circuit */
    OPA_POWER_ON(NUCODEGEN_OPA_MODULE_SEL, OPA_MODULE_0);

#if (NUCODEGEN_OPA_INT_EN)
    /* Clear OPA interrupt flag */
    OPA_CLR_INT_FLAG(NUCODEGEN_OPA_MODULE_SEL, OPA_MODULE_0);

    /* Enable OPA interrupt function */
    OPA_ENABLE_INT(NUCODEGEN_OPA_MODULE_SEL, OPA_MODULE_0);

    /* Enable OPA interrupt */
    NVIC_EnableIRQ(NUCODEGEN_OPA_IRQ_MODULE_SEL);
#endif /* NUCODEGEN_OPA_INT_EN */

}
#endif /* NUCODEGEN_OPA */


#if (NUCODEGEN_ACMP)
void ACMP_Init()
{
#if (NUCODEGEN_ACMP0_ENABLE)
    /* Select ACMP0 positive input channel */
    ACMP_SELECT_P(NUCODEGEN_ACMP_MODULE_SEL, ACMP_MODULE_0, NUCODEGEN_ACMP0_P_SEL);

    /* Configure ACMP0. Enable ACMP0 and select output source as the source of ACMP negative input. */
    ACMP_Open(NUCODEGEN_ACMP_MODULE_SEL, ACMP_MODULE_0, NUCODEGEN_ACMP0_N_SEL, NUCODEGEN_ACMP0_HYSTERESIS_SEL);


#if (NUCODEGEN_ACMP0_ADVANCED)

#if (NUCODEGEN_ACMP0_FILTERCNT_EN)

	/* Set ACMP0 output filter */
    ACMP_SET_FILTER(NUCODEGEN_ACMP_MODULE_SEL, ACMP_MODULE_0, NUCODEGEN_ACMP0_FILTERCNT_SEL);

    /* Enable ACMP0 output filter */
    ACMP_ENABLE_FILTER(NUCODEGEN_ACMP_MODULE_SEL,ACMP_MODULE_0);

#endif

#if (NUCODEGEN_ACMP0_OUTPUT_INVERSE_EN)
    /* Enable ACMP0 output inverse */
    ACMP_ENABLE_OUTPUT_INVERSE(NUCODEGEN_ACMP_MODULE_SEL, ACMP_MODULE_0);
#endif /* NUCODEGEN_ACMP0_OUTPUT_INVERSE_EN */

#if (NUCODEGEN_ACMP0_WKP_EN)
    /* Enable ACMP0 ACMP wake-up function */
    ACMP_ENABLE_WAKEUP(NUCODEGEN_ACMP_MODULE_SEL, ACMP_MODULE_0);
#endif /* NUCODEGEN_ACMP0_WKP_EN */

#if (NUCODEGEN_ACMP0_WIN_COMPARE_EN)
    /* Enable ACMP0 window compare function */
    ACMP_ENABLE_WINDOW_COMPARE(NUCODEGEN_ACMP_MODULE_SEL, ACMP_MODULE_0);
#endif /* NUCODEGEN_ACMP0_WIN_COMPARE_EN */

#if (NUCODEGEN_ACMP0_WIN_LATCH_EN)
    /* Enable ACMP0 window latch function */
    ACMP_ENABLE_WINDOW_LATCH(NUCODEGEN_ACMP_MODULE_SEL, ACMP_MODULE_0);
#endif /* NUCODEGEN_ACMP0_WIN_LATCH_EN */

#if (NUCODEGEN_ACMP0_INT_EN)
    /* Clear ACMP 0 interrupt flag */
    ACMP_CLR_INT_FLAG(NUCODEGEN_ACMP_MODULE_SEL, ACMP_MODULE_0);

    /* Set ACMP 0 interrupt condition */
    ACMP_SELECT_INT_COND(NUCODEGEN_ACMP_MODULE_SEL, ACMP_MODULE_0, NUCODEGEN_ACMP0_INT_COND_SEL);

    /* Enable ACMP 0 interrupt */
    ACMP_ENABLE_INT(NUCODEGEN_ACMP_MODULE_SEL, ACMP_MODULE_0);

#endif /* NUCODEGEN_ACMP0_INT_EN */

#endif /* NUCODEGEN_ACMP0_ADVANCED */

#endif /* NUCODEGEN_ACMP0_ENABLE */

#if (NUCODEGEN_ACMP1_ENABLE)
    /* Select ACMP1 positive input channel */
    ACMP_SELECT_P(NUCODEGEN_ACMP_MODULE_SEL, ACMP_MODULE_1, NUCODEGEN_ACMP1_P_SEL);

    /* Configure ACMP1. Enable ACMP1 and select output source as the source of ACMP negative input. */
    ACMP_Open(NUCODEGEN_ACMP_MODULE_SEL, ACMP_MODULE_1, NUCODEGEN_ACMP1_N_SEL, NUCODEGEN_ACMP1_HYSTERESIS_SEL);


#if (NUCODEGEN_ACMP1_ADVANCED)

#if (NUCODEGEN_ACMP1_FILTERCNT_EN)
    /* Set ACMP0 output filter */
    ACMP_SET_FILTER(NUCODEGEN_ACMP_MODULE_SEL, ACMP_MODULE_1, NUCODEGEN_ACMP1_FILTERCNT_SEL);

   /* Enable ACMP1 output filter */
    ACMP_ENABLE_FILTER(NUCODEGEN_ACMP_MODULE_SEL,ACMP_MODULE_1);
#endif

#if (NUCODEGEN_ACMP1_OUTPUT_INVERSE_EN)
    /* Enable ACMP1 output inverse */
    ACMP_ENABLE_OUTPUT_INVERSE(NUCODEGEN_ACMP_MODULE_SEL, ACMP_MODULE_1);

#endif /* NUCODEGEN_ACMP1_OUTPUT_INVERSE_EN */

#if (NUCODEGEN_ACMP1_WKP_EN)
    /* Enable ACMP1 ACMP wake-up function */
    ACMP_ENABLE_WAKEUP(NUCODEGEN_ACMP_MODULE_SEL, ACMP_MODULE_1);
#endif /* NUCODEGEN_ACMP1_WKP_EN */

#if (NUCODEGEN_ACMP1_WIN_COMPARE_EN)
    /* Enable ACMP0 window compare function */
    ACMP_ENABLE_WINDOW_COMPARE(NUCODEGEN_ACMP_MODULE_SEL, ACMP_MODULE_1);
#endif /* NUCODEGEN_ACMP1_WIN_COMPARE_EN */

#if (NUCODEGEN_ACMP1_WIN_LATCH_EN)
    /* Enable ACMP1 window latch function */
    ACMP_ENABLE_WINDOW_LATCH(NUCODEGEN_ACMP_MODULE_SEL, ACMP_MODULE_1);
#endif /* NUCODEGEN_ACMP1_WIN_LATCH_EN */

#if (NUCODEGEN_ACMP1_INT_EN)
    /* Clear ACMP 1 interrupt flag */
    ACMP_CLR_INT_FLAG(NUCODEGEN_ACMP_MODULE_SEL, ACMP_MODULE_1);

    /* Set ACMP 1 interrupt condition */
    ACMP_SELECT_INT_COND(NUCODEGEN_ACMP_MODULE_SEL, ACMP_MODULE_1, NUCODEGEN_ACMP1_INT_COND_SEL);

    /* Enable ACMP 1 interrupt */
    ACMP_ENABLE_INT(NUCODEGEN_ACMP_MODULE_SEL, ACMP_MODULE_1);

#endif /* NUCODEGEN_ACMP1_INT_EN */

#endif /* NUCODEGEN_ACMP1_ADVANCED */

#endif /* NUCODEGEN_ACMP1_ENABLE */

#if (NUCODEGEN_ACMP0_INT_EN) || (NUCODEGEN_ACMP1_INT_EN)
    /* Enable ACMP01 interrupt */
    NVIC_EnableIRQ(NUCODEGEN_ACMP_IRQ_MODULE_SEL);
#endif /* (NUCODEGEN_ACMP0_INT_EN) || (NUCODEGEN_ACMP1_INT_EN) */

    /* select comparator CRV source */
    ACMP_SELECT_CRV_SRC(ACMP01, NUCODEGEN_ACMP_CRV_SEL);

    /* select comparator reference voltage */
    ACMP_CRV_SEL(ACMP01, NUCODEDEF_ACMP_CRV_SET);

}
#endif /* NUCODEGEN_ACMP */

#if (NUCODEGEN_QSPI)
/*--------------------------------------------------------------------------------------------*/
/* QSPI                                                                                       */
/*--------------------------------------------------------------------------------------------*/
void QSPI_Init()
{
    /* This function make QSPI module be ready to transfer */
    QSPI_Open(QSPI0, NUCODEGEN_QSPI_MASTER, NUCODEGEN_QSPI_MODE, NUCODEGEN_QSPI_DATAWIDTH, NUCODEGEN_QSPI_BUSCLOCK);

#if (NUCODEGEN_QSPI_DUAL_QUAD_HALF_EN==NUCODEGEN_QSPI_CTL_DUALIOEN)

#if (NUCODEGEN_QSPI_DATA_DIR)
    /* Enable dual mode and set data direction as output */
    QSPI_ENABLE_DUAL_OUTPUT_MODE(QSPI0) ;
#else
    /* Enable dual mode and set data direction as input */
    QSPI_ENABLE_DUAL_INPUT_MODE(QSPI0) ;
#endif /* NUCODEGEN_QSPI_DATA_DIR */

#elif (NUCODEGEN_QSPI_DUAL_QUAD_HALF_EN==NUCODEGEN_QSPI_CTL_QUADIOEN)

#if (NUCODEGEN_QSPI_DATA_DIR)
    /* Enable quad mode and set data direction as output */
    QSPI_ENABLE_QUAD_OUTPUT_MODE(QSPI0) ;
#else
    /* Enable quad mode and set data direction as input */
    QSPI_ENABLE_QUAD_INPUT_MODE(QSPI0) ;
#endif  /* NUCODEGEN_QSPI_DATA_DIR */

#elif (NUCODEGEN_QSPI_DUAL_QUAD_HALF_EN==NUCODEGEN_QSPI_CTL_HALFIOEN)

#if (NUCODEGEN_QSPI_DATA_DIR)

    /* Enable half- duplex function and set data direction as output */
    QSPI0->CTL = QSPI0->CTL | (QSPI_CTL_DATDIR_Msk | QSPI_CTL_HALFDPX_Msk) ;

#else

    /* Enable half-duplex function and set data direction as input */
    QSPI0->CTL = (QSPI0->CTL & ~QSPI_CTL_DATDIR_Msk) | QSPI_CTL_HALFDPX_Msk ;
#endif  /* NUCODEGEN_QSPI_DATA_DIR */

#endif /* NUCODEGEN_QSPI_DUAL_QUAD_EN */

#if (NUCODEGEN_QSPI_2BIT_EN)

    /* Enable 2-bits mode */
    QSPI_ENABLE_2BIT_MODE(QSPI0);

#endif  /* NUCODEGEN_QSPI_2BIT_EN */

#if (NUCODEGEN_QSPI_BYTE_REORDER_EN)

    /* Enable byte reorder function */
    QSPI_ENABLE_BYTE_REORDER(QSPI0);

#endif  /* NUCODEGEN_QSPI_BYTE_REORDER_EN */

#if (NUCODEGEN_QSPI_RECEIVE_ONLY_EN)

    /* Enable receive-only mode */
    QSPI0->CTL = QSPI0->CTL | QSPI_CTL_RXONLY_Msk;

#endif /* NUCODEGEN_QSPI_RECEIVE_ONLY_EN */


#if (NUCODEGEN_QSPI_SS_EN)

    /* SS function enable */
    QSPI0->SSCTL = (QSPI0->SSCTL & (~QSPI_SSCTL_SS_Msk)) | QSPI_SSCTL_SS_Msk;

#endif  /* NUCODEGEN_QSPI_SS_EN */


#if (NUCODEGEN_QSPI_AUTOSS_EN)

    /* Enable auto SS function */
    QSPI0->SSCTL = (QSPI0->SSCTL & (~QSPI_SSCTL_AUTOSS_Msk)) | QSPI_SSCTL_AUTOSS_Msk | QSPI_SSCTL_SS_Msk;

#endif  /* NUCODEGEN_QSPI_AUTOSS_EN */

#if (NUCODEGEN_QSPI_3WIRE_EN)

    /* Enable 3-wire mode */
    QSPI_ENABLE_3WIRE_MODE(QSPI0);

#endif  /* NUCODEGEN_QSPI_3WIRE_EN */

    /* Select SS level */
    QSPI0->SSCTL = (QSPI0->SSCTL & (~QSPI_SSCTL_SSACTPOL_Msk)) | NUCODEGEN_QSPI_SS_LEVEL;

#if (NUCODEGEN_QSPI_DATA_ORDER)

    /* Set LSB first */
    QSPI_SET_LSB_FIRST(QSPI0);

#else

    /* Set MSB first */
    QSPI_SET_MSB_FIRST(QSPI0);

#endif /* NUCODEGEN_QSPI_DATA_ORDER */

    /* Set FIFO threshold */
    QSPI_SetFIFO(QSPI0, NUCODEGEN_QSPI_TX_THRESHOLD, NUCODEGEN_QSPI_RX_THRESHOLD);

#if (NUCODEGEN_QSPI_INT_EN)

    /* Enable interrupt function */
    NVIC_EnableIRQ(QSPI0_IRQn);

    /* Enable interrupt type */
    QSPI_EnableInt(QSPI0, NUCODEGEN_QSPI_INT_SEL);

#endif /* NUCODEGEN_QSPI_INT_EN */

}
#endif  /* NUCODEGEN_QSPI */

#if (NUCODEGEN_SPII2S)
/*--------------------------------------------------------------------------------------------*/
/* SPII2S                                                                                     */
/*--------------------------------------------------------------------------------------------*/
void SPII2S_Init()
{
#if (NUCODEGEN_SPII2S_MODE==NUCODEGEN_SPI_MODE)

    /* This function make SPI module be ready to transfer */
    SPI_Open(SPI0, NUCODEGEN_SPI_MASTER, NUCODEGEN_SPI_TIME_MODE, NUCODEGEN_SPI_DATAWIDTH, NUCODEGEN_SPI_BUSCLOCK);

#if (NUCODEGEN_SPI_BYTE_REORDER_EN)

    /* Enable byte reorder function */
    SPI_ENABLE_BYTE_REORDER(SPI0);

#endif /* NUCODEGEN_SPI_BYTE_REORDER_EN */

#if (NUCODEGEN_SPI_HALF_DUPLEX_EN)

#if (NUCODEGEN_SPI_DATA_DIR)

    /* Enable half- duplex function and set data direction as output */
    SPI0->CTL = SPI0->CTL | (SPI_CTL_DATDIR_Msk | SPI_CTL_HALFDPX_Msk) ;

#else

    /* Enable half-duplex function and set data direction as input */
    SPI0->CTL = (SPI0->CTL & ~SPI_CTL_DATDIR_Msk) | SPI_CTL_HALFDPX_Msk ;

#endif /* NUCODEGEN_SPI_DATA_DIR */

#endif /* NUCODEGEN_SPI_HALF_DUPLEX_EN */

#if (NUCODEGEN_SPI_RECEIVE_ONLY_EN)

    /* Enable receive-only mode */
    SPI0->CTL = SPI0->CTL | SPI_CTL_RXONLY_Msk;

#endif /* NUCODEGEN_SPI_RECEIVE_ONLY_EN */

#if (NUCODEGEN_SPI_SS_EN)

    /* SS function enable */
    SPI0->SSCTL = (SPI0->SSCTL & (~SPI_SSCTL_SS_Msk)) | SPI_SSCTL_SS_Msk;

#endif /* NUCODEGEN_SPI_SS_EN */

#if (NUCODEGEN_SPI_AUTOSS_EN)

    /* Enable auto SS function */
    SPI0->SSCTL = (SPI0->SSCTL & (~SPI_SSCTL_AUTOSS_Msk)) | SPI_SSCTL_AUTOSS_Msk | SPI_SSCTL_SS_Msk;

#endif /* NUCODEGEN_SPI_AUTOSS_EN */

    /* Select SS level */
    SPI0->SSCTL = (SPI0->SSCTL & (~SPI_SSCTL_SSACTPOL_Msk)) | NUCODEGEN_SPI_SS_LEVEL;

#if (NUCODEGEN_SPI_DATA_ORDER)

    /* Set LSB first */
    SPI_SET_LSB_FIRST(SPI0);

#else

    /* Set MSB first */
    SPI_SET_MSB_FIRST(SPI0);

#endif /* NUCODEGEN_SPI_DATA_ORDER */

#if (NUCODEGEN_SPI_DATAWIDTH>16)

    /* Set FIFO threshold */
    SPI_SetFIFO(SPI0, NUCODEGEN_SPI_TX_THRESHOLD0, NUCODEGEN_SPI_RX_THRESHOLD0);

#else

    /* Set FIFO threshold */
    SPI_SetFIFO(SPI0, NUCODEGEN_SPI_TX_THRESHOLD1, NUCODEGEN_SPI_RX_THRESHOLD1);

#endif

#if (NUCODEGEN_SPI_INT_EN)

    /* Enable interrupt function */
    NVIC_EnableIRQ(SPI0_IRQn);

    /* Enable interrupt type */
    SPI_EnableInt(SPI0, NUCODEGEN_SPI_INT_SEL);

#endif /* NUCODEGEN_SPI_INT_EN */

#elif (NUCODEGEN_SPII2S_MODE==NUCODEGEN_I2S_MODE)

    /* Enable I2S TX and RX functions */
    SPII2S_Open(SPI0, NUCODEGEN_I2S_MASTER, NUCODEGEN_I2S_SAMPLE_RATE, NUCODEGEN_I2S_DATAWIDTH, NUCODEGEN_I2S_AUDIO_FORMAT, NUCODEGEN_I2S_DATA_FORMAT);


#if (NUCODEGEN_I2S_WIDTH_CONFIG>1)

    /* Set FIFO threshold */
    SPII2S_SetFIFO(SPI0, NUCODEGEN_I2S_TX_THRESHOLD0, NUCODEGEN_I2S_RX_THRESHOLD0);

#else

    /* Set FIFO threshold */
    SPII2S_SetFIFO(SPI0, NUCODEGEN_I2S_TX_THRESHOLD1, NUCODEGEN_I2S_RX_THRESHOLD1);

#endif

#if (NUCODEGEN_I2S_MCLK_EN)

    /* Enable MCLK */
    SPII2S_EnableMCLK(SPI0, NUCODEGEN_I2S_MCLK);

#endif /* NUCODEGEN_I2S_MCLK_EN */

#if (NUCODEGEN_I2S_INT_EN)

    /* Enable interrupt function */
    NVIC_EnableIRQ(SPI0_IRQn);

    /* Enable interrupt type */
    SPII2S_EnableInt(SPI0, NUCODEGEN_I2S_INT_SEL);

#endif /* NUCODEGEN_I2S_INT_EN */

#endif  //NUCODEGEN_SPII2S_MODE
}
#endif  /* NUCODEGEN_SPII2S */

void Periph_Init(void)
{
#if NUCODEGEN_UART0
    UART0_Init();
#endif

#if NUCODEGEN_UART1
    UART1_Init();
#endif

#if NUCODEGEN_UART2
    UART2_Init();
#endif

#if NUCODEGEN_CLK
    CLK_Init();
#endif

#if NUCODEGEN_SYS
    SYS_Init();
#endif

#if NUCODEGEN_CRC
    CRC_Init();
#endif

#if NUCODEGEN_CRYPTO
    CRYPTO_Init();
#endif

#if NUCODEGEN_BPWM0
    BPWM0_Init();
#endif

#if NUCODEGEN_BPWM1
    BPWM1_Init();
#endif

#if NUCODEGEN_PWM0
    PWM0_Init();
#endif

#if NUCODEGEN_PWM1
    PWM1_Init();
#endif

#if NUCODEGEN_GPIO
    GPIO_Init();
#endif

#if NUCODEGEN_EADC
    EADC_Init();
#endif

#if NUCODEGEN_EBI
    EBI_Init();
#endif

#if NUCODEGEN_I2C0
    I2C0_Init();
#endif

#if NUCODEGEN_I2C1
    I2C1_Init();
#endif

#if NUCODEGEN_USCI0_I2C
    USCI0_I2C_Init();
#endif

#if NUCODEGEN_USCI1_I2C
    USCI1_I2C_Init();
#endif

#if NUCODEGEN_USCI2_I2C
    USCI2_I2C_Init();
#endif

#if NUCODEGEN_USCI0_UART
    USCI0_UART_Init();
#endif

#if NUCODEGEN_USCI1_UART
    USCI1_UART_Init();
#endif

#if NUCODEGEN_USCI2_UART
    USCI2_UART_Init();
#endif

#if NUCODEGEN_USCI0_SPI
    USCI0_SPI_Init();
#endif

#if NUCODEGEN_USCI1_SPI
    USCI1_SPI_Init();
#endif

#if NUCODEGEN_USCI2_SPI
    USCI2_SPI_Init();
#endif

#if (NUCODEGEN_QSPI)
    QSPI_Init() ;
#endif

#if (NUCODEGEN_SPII2S)
    SPII2S_Init() ;
#endif

#if NUCODEGEN_USBD
    USBD_Init();
#endif

#if NUCODEGEN_SC0
    SC0_Init();
#endif

#if NUCODEGEN_TIMER0
    TIMER0_Init();
#endif

#if NUCODEGEN_TIMER1
    TIMER1_Init();
#endif

#if NUCODEGEN_TIMER2
    TIMER2_Init();
#endif

#if NUCODEGEN_TIMER3
    TIMER3_Init();
#endif

#if NUCODEGEN_PDMA
    PDMA_Init();
#endif

#if NUCODEGEN_PSIO
    PSIO_Init();
#endif

#if NUCODEGEN_WDT
    WDT_Init();
#endif

#if NUCODEGEN_WWDT
    WWDT_Init();
#endif

#if NUCODEGEN_RTC
    RTC_Init();
#endif

#if NUCODEGEN_ACMP
    ACMP_Init();
#endif

#if NUCODEGEN_OPA
    OPA_Init();
#endif

#if NUCODEGEN_DAC
    DAC_Init();
#endif

#if NUCODEGEN_FMC
    FMC_Init();
#endif

}
