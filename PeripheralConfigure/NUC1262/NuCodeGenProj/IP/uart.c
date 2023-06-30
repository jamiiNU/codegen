
#if NUCODEGEN_UART0
void UART0_Init()
{
#if (NUCODEGEN_UART0_FUNCSEL == NUCODEGEN_UART0_FUNCSEL_UART)
    /* Configure UART0 and set UART0 baud rate */
    UART_Open(UART0, UART0_BAUD);

#if NUCODEGEN_UART0_LINE_CONFIG
    /* Set Data Format */
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

#elif (NUCODEGEN_UART0_FUNCSEL == NUCODEGEN_UART0_FUNCSEL_IrDA)
    /* Select IrDA Tx or Rx mode and set baud rate */
    UART_SelectIrDAMode(UART0, UART0_IRDA_BAUD, NUCODEGEN_UART0_IRDA_MODE);
    /* Set Data Format (only support 8 bits ,None Parity bit,1 Stop bit) */
    UART_SetLine_Config(UART0,0,UART_WORD_LEN_8, UART_PARITY_NONE, UART_STOP_BIT_1);

#if NUCODEGEN_UART0_IRDA_INTEN
    /* Enable UART0 IrDA Interrupt */
    UART_EnableInt(UART0, (NUCODEGEN_UART0_IRDA_INT_MASK));
#endif
#elif (NUCODEGEN_UART0_FUNCSEL == NUCODEGEN_UART0_FUNCSEL_RS485)
    /* Configure UART0 and set UART0 baud rate */
    UART_Open(UART0, UART0_RS485_BAUD);

    /* Set Data Format*/ /* Only need parity enable whenever parity ODD/EVEN */
    UART_SetLine_Config(UART0,0, UART_WORD_LEN_8, UART_PARITY_EVEN, UART_STOP_BIT_1);

    /* Set RTS pin active level as High level active */
    UART0->MODEM &= ~UART_MODEM_RTSACTLV_Msk;
    UART0->MODEM |= UART_RTS_IS_HIGH_LEV_ACTIVE;

#if (NUCODEGEN_UART0_RS485_MODE == NUCODEGEN_UART0_RS485_ADD_MODE)
    /* Set RS485-AAD Mode and address match value */
    UART_SelectRS485Mode(UART0, UART_ALTCTL_RS485AAD_Msk | UART_ALTCTL_ADDRDEN_Msk | UART_ALTCTL_RS485AUD_Msk, UART0_RS485_ADDRMV);


#else /*NUCODEGEN_UART0_RS485_NMM_MODE*/

    /* Set RX_DIS enable before set RS485-NMM mode */
    UART0->FIFO |= UART_FIFO_RXOFF_Msk;

    /* Set RS485-NMM Mode */

    UART_SelectRS485Mode(UART0, UART_ALTCTL_RS485NMM_Msk | UART_ALTCTL_ADDRDEN_Msk | UART_ALTCTL_RS485AUD_Msk, 0);

#endif
#if NUCODEGEN_UART0_RS485_INTEN
    /* Enable UART0 RS485 Interrupt */
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
    /* Set the UART Time-out count */
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

#if (NUCODEGEN_UART0_INTEN || NUCODEGEN_UART0_IRDA_INTEN || NUCODEGEN_UART0_RS485_INTEN || NUCODEGEN_UART0_SW_INTEN )
    /* Enable UART0 IRQ Handler */
    NVIC_EnableIRQ(UART0_IRQn);
#endif

}
#endif //NUCODEGEN_UART0

#if NUCODEGEN_UART1
void UART1_Init()
{
#if (NUCODEGEN_UART1_FUNCSEL == NUCODEGEN_UART1_FUNCSEL_UART)
    /* Configure UART1 and set UART1 baud rate */
    UART_Open(UART1, UART1_BAUD);

#if NUCODEGEN_UART1_LINE_CONFIG
    /* Set Data Format */
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
    UART_SetLine_Config(UART1,0,UART_WORD_LEN_8, UART_PARITY_NONE, UART_STOP_BIT_1);

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

#if (NUCODEGEN_UART1_RS485_MODE == NUCODEGEN_UART1_RS485_ADD_MODE)

    /* Set RS485-AAD Mode and address match value */
    UART_SelectRS485Mode(UART1, UART_ALTCTL_RS485AAD_Msk | UART_ALTCTL_ADDRDEN_Msk | UART_ALTCTL_RS485AUD_Msk, UART1_RS485_ADDRMV);


#else /*NUCODEGEN_UART1_RS485_NMM_MODE*/

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
    /* Set the UART Time-out count */
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
    /* Enable UART1 IRQ Handler */
    NVIC_EnableIRQ(UART1_IRQn);
#endif

}
#endif //NUCODEGEN_UART1
