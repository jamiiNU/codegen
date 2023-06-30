

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
    NVIC_EnableIRQ(USCI_IRQn);
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
    /* Enable UI2C1 10-bit address mode */
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
    NVIC_EnableIRQ(USCI_IRQn);
#endif /* NUCODEGEN_UI2C1_INT_EN */

}
#endif /*NUCODEGEN_USCI1_I2C*/


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
    NVIC_EnableIRQ(USCI_IRQn);
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
    /* NVIC Enable USCI1 Interrupt */
    NVIC_EnableIRQ(USCI_IRQn);
#endif /* NUCODEGEN_UUART1_NVIC_ENALBE */

#if NUCODEGEN_UUART1_PDMA_ENABLE
    /* Configure UUART1 PDMA Function */
    UUART1->PDMACTL = NUCODEGEN_UUART1_PDMA_CONFIG;
#endif
}
#endif /* NUCODEGEN_USCI1_UART*/


#if (NUCODEGEN_USCI0_SPI)
void USCI0_SPI_Init(void)
{
#if (NUCODEGEN_USPI0_MASTER_SLAVE == NUCODEGEN_USPI0_MASTER_MODE)
	
    /* Init USCI_SPI0 */
    USPI_Open(USPI0, USPI_MASTER, NUCODEGEN_USPI0_TIME_MODE,  NUCODEGEN_USPI0_DATAWIDTH, NUCODEGEN_USPI0_BUSCLOCK);
    
#else

    /* Init USCI_SPI0 */
    USPI_Open(USPI0, USPI_SLAVE, NUCODEGEN_USPI0_TIME_MODE,  NUCODEGEN_USPI0_DATAWIDTH, NUCODEGEN_USPI0_BUSCLOCK);

#endif /* NUCODEGEN_USPI0_MASTER_SLAVE */    


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

#if (NUCODEGEN_USPI0_MASTER_SS_LEVEL == 0)

    /* Enable auto SS function */
    USPI_EnableAutoSS(USPI0, 0, USPI_SS_ACTIVE_HIGH);
    
#else

    /* Enable auto SS function */
    USPI_EnableAutoSS(USPI0, 0, USPI_SS_ACTIVE_LOW);

#endif /* NUCODEGEN_USPI0_MASTER_SS_LEVEL */
    
#endif /* NUCODEGEN_USPI_AUTOSS_EN */

#if (NUCODEGEN_USPI0_SS_EN)

    /* Enable SS function */
    USPI0->PROTCTL |= USPI_PROTCTL_SS_Msk;

#endif /* NUCODEGEN_USPI_SS_EN */

#if (NUCODEGEN_USPI0_MASTER_SLAVE == NUCODEGEN_USPI0_MASTER_MODE)

    /* Master SS active level */
    USPI0->LINECTL = (USPI0->LINECTL & ~USPI_LINECTL_CTLOINV_Msk) | (NUCODEGEN_USPI0_MASTER_SS_LEVEL<<USPI_LINECTL_CTLOINV_Pos);

#else
#if (NUCODEGEN_USPI0_3WIRE_EN)

    /* Enable 3 wire mode */
    USPI_ENABLE_3WIRE_MODE(USPI0);
    
#else

    /* Slave SS active level */
    USPI0->CTLIN0 = ( USPI0->CTLIN0 & ~USPI_CTLIN0_ININV_Msk) | (NUCODEGEN_USPI0_SLAVE_SS_LEVEL<<USPI_CTLIN0_ININV_Pos);
        
#endif /* NUCODEGEN_USPI_3WIRE_EN */   
#endif /* NUCODEGEN_USPI0_MASTER_SLAVE */    
       
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
    NVIC_EnableIRQ(USCI_IRQn);
#endif /* NUCODEGEN_USPI0_INT_EN */
}
#endif /* NUCODEGEN_USCI0_SPI*/

#if (NUCODEGEN_USCI1_SPI)
void USCI1_SPI_Init(void)
{

#if (NUCODEGEN_USPI1_MASTER_SLAVE == NUCODEGEN_USPI1_MASTER_MODE)
	
    /* Init USCI_SPI1 */
    USPI_Open(USPI1, USPI_MASTER, NUCODEGEN_USPI1_TIME_MODE,  NUCODEGEN_USPI1_DATAWIDTH, NUCODEGEN_USPI1_BUSCLOCK);
    
#else

    /* Init USCI_SPI1 */
    USPI_Open(USPI1, USPI_SLAVE, NUCODEGEN_USPI1_TIME_MODE,  NUCODEGEN_USPI1_DATAWIDTH, NUCODEGEN_USPI1_BUSCLOCK);

#endif /* NUCODEGEN_USPI1_MASTER_SLAVE */


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

#if (NUCODEGEN_USPI1_MASTER_SS_LEVEL == 0)

    /* Enable auto SS function */
    USPI_EnableAutoSS(USPI1, 0, USPI_SS_ACTIVE_HIGH);
    
#else

    /* Enable auto SS function */
    USPI_EnableAutoSS(USPI1, 0, USPI_SS_ACTIVE_LOW);

#endif /* NUCODEGEN_USPI1_MASTER_SS_LEVEL */

#endif /* NUCODEGEN_USPI_AUTOSS_EN */

#if (NUCODEGEN_USPI1_SS_EN)

    /* Enable SS function */
    USPI1->PROTCTL |= USPI_PROTCTL_SS_Msk;

#endif /* NUCODEGEN_USPI_SS_EN */

#if (NUCODEGEN_USPI1_MASTER_SLAVE == NUCODEGEN_USPI1_MASTER_MODE)

    /* Master SS active level */
    USPI1->LINECTL = (USPI1->LINECTL & ~USPI_LINECTL_CTLOINV_Msk) | (NUCODEGEN_USPI1_MASTER_SS_LEVEL<<USPI_LINECTL_CTLOINV_Pos);

#else
#if (NUCODEGEN_USPI1_3WIRE_EN)

    /* Enable 3 wire mode */
    USPI_ENABLE_3WIRE_MODE(USPI1);
    
#else    

    /* Slave SS active level */
    USPI1->CTLIN0 = ( USPI1->CTLIN0 & ~USPI_CTLIN0_ININV_Msk) | (NUCODEGEN_USPI1_SLAVE_SS_LEVEL<<USPI_CTLIN0_ININV_Pos);
    
#endif /* NUCODEGEN_USPI_3WIRE_EN */    
#endif /* NUCODEGEN_USPI1_MASTER_SLAVE */

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
    NVIC_EnableIRQ(USCI_IRQn);

#endif /* NUCODEGEN_USPI1_INT_EN */
}
#endif /* NUCODEGEN_USCI1_SPI*/

