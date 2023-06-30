
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
    USPI0->LINECTL = (USPI0->LINECTL & ~USPI_LINECTL_CTLOINV_Msk) | (NUCODEGEN_USPI0_MASTER_SS_LEVEL<<USPI_LINECTL_CTLOINV_Pos);

    /* Slave SS active level */
    USPI0->CTLIN0 = ( USPI0->CTLIN0 & ~USPI_CTLIN0_ININV_Msk) | (NUCODEGEN_USPI0_SLAVE_SS_LEVEL<<USPI_CTLIN0_ININV_Pos);
       
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
    USPI1->LINECTL = (USPI1->LINECTL & ~USPI_LINECTL_CTLOINV_Msk) | (NUCODEGEN_USPI1_MASTER_SS_LEVEL<<USPI_LINECTL_CTLOINV_Pos);

    /* Slave SS active level */
    USPI1->CTLIN0 = (USPI1->CTLIN0 & ~USPI_CTLIN0_ININV_Msk) | (NUCODEGEN_USPI1_SLAVE_SS_LEVEL<<USPI_CTLIN0_ININV_Pos);
       
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
    USPI2->LINECTL = (USPI2->LINECTL & ~USPI_LINECTL_CTLOINV_Msk) | (NUCODEGEN_USPI2_MASTER_SS_LEVEL<<USPI_LINECTL_CTLOINV_Pos);

    /* Slave SS active level */
    USPI2->CTLIN0 = (USPI2->CTLIN0 & ~USPI_CTLIN0_ININV_Msk) | (NUCODEGEN_USPI2_SLAVE_SS_LEVEL<<USPI_CTLIN0_ININV_Pos);
       
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
