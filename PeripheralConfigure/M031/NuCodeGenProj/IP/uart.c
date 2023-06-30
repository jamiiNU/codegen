
#if NUCODEGEN_UART0
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

    /* Set RS485-AAD Mode and address match is 0xC0 */
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

#if (NUCODEGEN_UART0_INTEN || NUCODEGEN_UART0_IRDA_INTEN || NUCODEGEN_UART0_RS485_INTEN || NUCODEGEN_UART0_SW_INTEN )
    /*Enable UART0 IRQ Handler */
    NVIC_EnableIRQ(UART02_IRQn);
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

    /* Set RS485-AAD Mode and address match is 0xC0 */
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
    NVIC_EnableIRQ(UART13_IRQn);
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
    /* Enable UART2 Interrupt */
    UART_EnableInt(UART2, (NUCODEGEN_UART2_INT_MASK));
#endif

#elif (NUCODEGEN_UART2_FUNCSEL == NUCODEGEN_UART2_FUNCSEL_IrDA)
    /* Select IrDA Tx or Rx mode and set baud rate */
    UART_SelectIrDAMode(UART2, UART2_IRDA_BAUD, NUCODEGEN_UART2_IRDA_MODE);
    /* Set Data Format (only support 8 bits ,None Parity bit,1 Stop bit) */
    UART_SetLine_Config(UART2,0,UART_WORD_LEN_8, UART_PARITY_NONE, UART_STOP_BIT_1);

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

    /* Set RS485-AAD Mode and address match is UART2_RS485_ADDRMV */
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

#if NUCODEGEN_UART2_WKCTSEN
    /* Enable UART nCTS Wake up */
    UART2->WKCTL |= UART_WKCTL_WKCTSEN_Msk;
#endif

#if NUCODEGEN_UART2_WKDATEN
    /* Enable UART Incoming Data Wake up */
    UART2->WKCTL |= UART_WKCTL_WKDATEN_Msk;
#endif

#if (NUCODEGEN_UART2_INTEN || NUCODEGEN_UART2_IRDA_INTEN || NUCODEGEN_UART2_RS485_INTEN || NUCODEGEN_UART2_SW_INTEN )
    /*Enable UART IRQ Handler */
    NVIC_EnableIRQ(UART02_IRQn);
#endif

}
#endif //NUCODEGEN_UART2

#if NUCODEGEN_UART3
void UART3_Init()
{
#if (NUCODEGEN_UART3_FUNCSEL == NUCODEGEN_UART3_FUNCSEL_UART)
    /* Configure UART3 and set UART3 baud rate */
    UART_Open(UART3, UART3_BAUD);

#if NUCODEGEN_UART3_LINE_CONFIG
    /* Set Data Format*/
    UART_SetLine_Config(UART3, 0, NUCODEGEN_UART3_WORD_LEN, NUCODEGEN_UART3_PARITY, NUCODEGEN_UART3_STOP_BIT);
#endif


#if NUCODEGEN_UART3_AUTOFLOW
    /* Enable RTS and CTS auto flow control */
    UART_EnableFlowCtrl(UART3);
    /* Auto-flow Control Trigger level */
    UART3->FIFO = (UART3->FIFO &~ UART_FIFO_RTSTRGLV_Msk) | NUCODEGEN_UART3_FIFO_RTSTRGLV;

#if (NUCODEGEN_UART3_RTSACTLV_LOW)
    /* nRTS pin output is low level active */
    UART3->MODEM |= UART_MODEM_RTSACTLV_Msk;
#else
    /* nRTS pin output is high level active */
    UART3->MODEM &= ~UART_MODEM_RTSACTLV_Msk;
#endif

#if (NUCODEGEN_UART3_CTSACTLV_LOW)
    /* nCTS pin input is low level active */
    UART3->MODEMSTS |= UART_MODEMSTS_CTSACTLV_Msk;
#else
    /* nCTS pin input is high level active */
    UART3->MODEMSTS &= ~UART_MODEMSTS_CTSACTLV_Msk;
#endif

#endif

#if NUCODEGEN_UART3_INTEN
    /* Enable UART3 Interrupt */
    UART_EnableInt(UART3, (NUCODEGEN_UART3_INT_MASK));
#endif

#elif (NUCODEGEN_UART3_FUNCSEL == NUCODEGEN_UART3_FUNCSEL_IrDA)
    /* Select IrDA Tx or Rx mode and set baud rate */
    UART_SelectIrDAMode(UART3, UART3_IRDA_BAUD, NUCODEGEN_UART3_IRDA_MODE);
    /* Set Data Format (only support 8 bits ,None Parity bit,1 Stop bit) */
    UART_SetLine_Config(UART3,0,UART_WORD_LEN_8, UART_PARITY_NONE, UART_STOP_BIT_1);

#if NUCODEGEN_UART3_IRDA_INTEN
    /* Enable UART3 IrDA Interrupt */
    UART_EnableInt(UART3, (NUCODEGEN_UART3_IRDA_INT_MASK));
#endif
#elif (NUCODEGEN_UART3_FUNCSEL == NUCODEGEN_UART3_FUNCSEL_RS485)
    /* Configure UART3 and set UART3 baud rate */
    UART_Open(UART3, UART3_RS485_BAUD);

    /* Set Data Format*/ /* Only need parity enable whenever parity ODD/EVEN */
    UART_SetLine_Config(UART3, 0, UART_WORD_LEN_8, UART_PARITY_EVEN, UART_STOP_BIT_1);

    /* Set RTS pin active level as High level active */
    UART3->MODEM &= ~UART_MODEM_RTSACTLV_Msk;
    UART3->MODEM |= UART_RTS_IS_HIGH_LEV_ACTIVE;

#if (NUCODEGEN_UART3_RS485_MODE == NUCODEGEN_UART3_RS485_ADD_MODE)

    /* Set RS485-AAD Mode and address match is UART3_RS485_ADDRMV */
    UART_SelectRS485Mode(UART3, UART_ALTCTL_RS485AAD_Msk | UART_ALTCTL_ADDRDEN_Msk | UART_ALTCTL_RS485AUD_Msk, UART3_RS485_ADDRMV);


#else /*NUCODEGEN_UART3_RS485_NMM_MODE*/

    /* Set RX_DIS enable before set RS485-NMM mode */
    UART3->FIFO |= UART_FIFO_RXOFF_Msk;

    /* Set RS485-NMM Mode */

    UART_SelectRS485Mode(UART3, UART_ALTCTL_RS485NMM_Msk | UART_ALTCTL_ADDRDEN_Msk | UART_ALTCTL_RS485AUD_Msk, 0);

#endif

#if NUCODEGEN_UART3_RS485_INTEN
    /*Enable RS485 Interrupt*/
    UART_EnableInt(UART3, (NUCODEGEN_UART3_RS485_INT_MASK));
#endif
#elif (NUCODEGEN_UART3_FUNCSEL == NUCODEGEN_UART3_FUNCSEL_SINGLE_WIRE)
    /* Configure UART3 and set UART3 baud rate */
    UART_Open(UART3, UART3_SW_BAUD);
    /* Set Single Wire Mode */
    UART_SelectSingleWireMode(UART3);

#if NUCODEGEN_UART3_SW_INTEN
    /*Enable the Single Wire Interrupt*/
    UART_EnableInt(UART3, (NUCODEGEN_UART3_SW_INT_MASK));
#endif
#endif

#if NUCODEGEN_UART3_TOCNTEN
    /*Set the UART TimeOut count*/
    UART_SetTimeoutCnt(UART3, UART3_TOCNT);
#endif

#if  NUCODEGEN_UART3_PDMAEN
    /*Enable UART PDMA*/
    UART3->INTEN |= NUCODEGEN_UART3_PDMAEN_Msk;
#endif


#if NUCODEGEN_UART3_ABRDEN
    /* Enable auto baud rate detect function */
    UART3->ALTCTL |= UART_ALTCTL_ABRDEN_Msk;
#endif

#if NUCODEGEN_UART3_WKCTSEN
    /* Enable UART nCTS Wake up */
    UART3->WKCTL |= UART_WKCTL_WKCTSEN_Msk;
#endif

#if NUCODEGEN_UART3_WKDATEN
    /* Enable UART Incoming Data Wake up */
    UART3->WKCTL |= UART_WKCTL_WKDATEN_Msk;
#endif

#if (NUCODEGEN_UART3_INTEN || NUCODEGEN_UART3_IRDA_INTEN || NUCODEGEN_UART3_RS485_INTEN || NUCODEGEN_UART3_SW_INTEN )
    /*Enable UART IRQ Handler */
    NVIC_EnableIRQ(UART13_IRQn);
#endif

}
#endif //NUCODEGEN_UART3

#if NUCODEGEN_UART4
void UART4_Init()
{
#if (NUCODEGEN_UART4_FUNCSEL == NUCODEGEN_UART4_FUNCSEL_UART)
    /* Configure UART4 and set UART4 baud rate */
    UART_Open(UART4, UART4_BAUD);

#if NUCODEGEN_UART4_LINE_CONFIG
    /* Set Data Format*/
    UART_SetLine_Config(UART4, 0, NUCODEGEN_UART4_WORD_LEN, NUCODEGEN_UART4_PARITY, NUCODEGEN_UART4_STOP_BIT);
#endif


#if NUCODEGEN_UART4_AUTOFLOW
    /* Enable RTS and CTS auto flow control */
    UART_EnableFlowCtrl(UART4);
    /* Auto-flow Control Trigger level */
    UART4->FIFO = (UART4->FIFO &~ UART_FIFO_RTSTRGLV_Msk) | NUCODEGEN_UART4_FIFO_RTSTRGLV;

#if (NUCODEGEN_UART4_RTSACTLV_LOW)
    /* nRTS pin output is low level active */
    UART4->MODEM |= UART_MODEM_RTSACTLV_Msk;
#else
    /* nRTS pin output is high level active */
    UART4->MODEM &= ~UART_MODEM_RTSACTLV_Msk;
#endif

#if (NUCODEGEN_UART4_CTSACTLV_LOW)
    /* nCTS pin input is low level active */
    UART4->MODEMSTS |= UART_MODEMSTS_CTSACTLV_Msk;
#else
    /* nCTS pin input is high level active */
    UART4->MODEMSTS &= ~UART_MODEMSTS_CTSACTLV_Msk;
#endif

#endif

#if NUCODEGEN_UART4_INTEN
    /* Enable UART4 Interrupt */
    UART_EnableInt(UART4, (NUCODEGEN_UART4_INT_MASK));
#endif

#elif (NUCODEGEN_UART4_FUNCSEL == NUCODEGEN_UART4_FUNCSEL_IrDA)
    /* Select IrDA Tx or Rx mode and set baud rate */
    UART_SelectIrDAMode(UART4, UART4_IRDA_BAUD, NUCODEGEN_UART4_IRDA_MODE);
    /* Set Data Format (only support 8 bits ,None Parity bit,1 Stop bit) */
    UART_SetLine_Config(UART4,0,UART_WORD_LEN_8, UART_PARITY_NONE, UART_STOP_BIT_1);

#if NUCODEGEN_UART4_IRDA_INTEN
    /* Enable UART4 IrDA Interrupt */
    UART_EnableInt(UART4, (NUCODEGEN_UART4_IRDA_INT_MASK));
#endif
#elif (NUCODEGEN_UART4_FUNCSEL == NUCODEGEN_UART4_FUNCSEL_RS485)
    /* Configure UART4 and set UART4 baud rate */
    UART_Open(UART4, UART4_RS485_BAUD);

    /* Set Data Format*/ /* Only need parity enable whenever parity ODD/EVEN */
    UART_SetLine_Config(UART4, 0, UART_WORD_LEN_8, UART_PARITY_EVEN, UART_STOP_BIT_1);

    /* Set RTS pin active level as High level active */
    UART4->MODEM &= ~UART_MODEM_RTSACTLV_Msk;
    UART4->MODEM |= UART_RTS_IS_HIGH_LEV_ACTIVE;

#if (NUCODEGEN_UART4_RS485_MODE == NUCODEGEN_UART4_RS485_ADD_MODE)

    /* Set RS485-AAD Mode and address match is UART4_RS485_ADDRMV */
    UART_SelectRS485Mode(UART4, UART_ALTCTL_RS485AAD_Msk | UART_ALTCTL_ADDRDEN_Msk | UART_ALTCTL_RS485AUD_Msk, UART4_RS485_ADDRMV);


#else /*NUCODEGEN_UART4_RS485_NMM_MODE*/

    /* Set RX_DIS enable before set RS485-NMM mode */
    UART4->FIFO |= UART_FIFO_RXOFF_Msk;

    /* Set RS485-NMM Mode */

    UART_SelectRS485Mode(UART4, UART_ALTCTL_RS485NMM_Msk | UART_ALTCTL_ADDRDEN_Msk | UART_ALTCTL_RS485AUD_Msk, 0);

#endif

#if NUCODEGEN_UART4_RS485_INTEN
    /*Enable RS485 Interrupt*/
    UART_EnableInt(UART4, (NUCODEGEN_UART4_RS485_INT_MASK));
#endif
#elif (NUCODEGEN_UART4_FUNCSEL == NUCODEGEN_UART4_FUNCSEL_SINGLE_WIRE)
    /* Configure UART4 and set UART4 baud rate */
    UART_Open(UART4, UART4_SW_BAUD);
    /* Set Single Wire Mode */
    UART_SelectSingleWireMode(UART4);

#if NUCODEGEN_UART4_SW_INTEN
    /*Enable the Single Wire Interrupt*/
    UART_EnableInt(UART4, (NUCODEGEN_UART4_SW_INT_MASK));
#endif
#endif

#if NUCODEGEN_UART4_TOCNTEN
    /*Set the UART TimeOut count*/
    UART_SetTimeoutCnt(UART4, UART4_TOCNT);
#endif

#if  NUCODEGEN_UART4_PDMAEN
    /*Enable UART PDMA*/
    UART4->INTEN |= NUCODEGEN_UART4_PDMAEN_Msk;
#endif


#if NUCODEGEN_UART4_ABRDEN
    /* Enable auto baud rate detect function */
    UART4->ALTCTL |= UART_ALTCTL_ABRDEN_Msk;
#endif
   /* RX FIFO Interrupt TriggeLevel */
    UART4->FIFO = (UART4->FIFO &~ UART_FIFO_RFITL_Msk) | NUCODEGEN_UART4_RFITL;

#if NUCODEGEN_UART4_WKCTSEN
    /* Enable UART nCTS Wake up */
    UART4->WKCTL |= UART_WKCTL_WKCTSEN_Msk;
#endif

#if NUCODEGEN_UART4_WKDATEN
    /* Enable UART Incoming Data Wake up */
    UART4->WKCTL |= UART_WKCTL_WKDATEN_Msk;
#endif

#if NUCODEGEN_UART4_WKRFRTEN
    /* Enable UART Received Data FIFO Reached Threshold Wake up */
    UART4->WKCTL |= UART_WKCTL_WKRFRTEN_Msk;
#endif

#if NUCODEGEN_UART4_WKTOUTEN
    /* Enable UART Received Data FIFO Threshold Time-out Wake up */
    UART4->WKCTL |= UART_WKCTL_WKTOUTEN_Msk;
#endif

#if NUCODEGEN_UART4_WKRS485EN
    /* Enable RS-485 Address Match (AAD Mode) Wake up */
    UART4->WKCTL |= UART_WKCTL_WKRS485EN_Msk;
#endif

#if (NUCODEGEN_UART4_INTEN || NUCODEGEN_UART4_IRDA_INTEN || NUCODEGEN_UART4_RS485_INTEN || NUCODEGEN_UART4_SW_INTEN )
    /*Enable UART IRQ Handler */
    NVIC_EnableIRQ(UART46_IRQn);
#endif

}
#endif //NUCODEGEN_UART4

#if NUCODEGEN_UART5
void UART5_Init()
{
#if (NUCODEGEN_UART5_FUNCSEL == NUCODEGEN_UART5_FUNCSEL_UART)
    /* Configure UART5 and set UART5 baud rate */
    UART_Open(UART5, UART5_BAUD);

#if NUCODEGEN_UART5_LINE_CONFIG
    /* Set Data Format*/
    UART_SetLine_Config(UART5, 0, NUCODEGEN_UART5_WORD_LEN, NUCODEGEN_UART5_PARITY, NUCODEGEN_UART5_STOP_BIT);
#endif


#if NUCODEGEN_UART5_AUTOFLOW
    /* Enable RTS and CTS auto flow control */
    UART_EnableFlowCtrl(UART5);
    /* Auto-flow Control Trigger level */
    UART5->FIFO = (UART5->FIFO &~ UART_FIFO_RTSTRGLV_Msk) | NUCODEGEN_UART5_FIFO_RTSTRGLV;

#if (NUCODEGEN_UART5_RTSACTLV_LOW)
    /* nRTS pin output is low level active */
    UART5->MODEM |= UART_MODEM_RTSACTLV_Msk;
#else
    /* nRTS pin output is high level active */
    UART5->MODEM &= ~UART_MODEM_RTSACTLV_Msk;
#endif

#if (NUCODEGEN_UART5_CTSACTLV_LOW)
    /* nCTS pin input is low level active */
    UART5->MODEMSTS |= UART_MODEMSTS_CTSACTLV_Msk;
#else
    /* nCTS pin input is high level active */
    UART5->MODEMSTS &= ~UART_MODEMSTS_CTSACTLV_Msk;
#endif

#endif

#if NUCODEGEN_UART5_INTEN
    /* Enable UART5 Interrupt */
    UART_EnableInt(UART5, (NUCODEGEN_UART5_INT_MASK));
#endif

#elif (NUCODEGEN_UART5_FUNCSEL == NUCODEGEN_UART5_FUNCSEL_IrDA)
    /* Select IrDA Tx or Rx mode and set baud rate */
    UART_SelectIrDAMode(UART5, UART5_IRDA_BAUD, NUCODEGEN_UART5_IRDA_MODE);
    /* Set Data Format (only support 8 bits ,None Parity bit,1 Stop bit) */
    UART_SetLine_Config(UART5,0,UART_WORD_LEN_8, UART_PARITY_NONE, UART_STOP_BIT_1);

#if NUCODEGEN_UART5_IRDA_INTEN
    /* Enable UART5 IrDA Interrupt */
    UART_EnableInt(UART5, (NUCODEGEN_UART5_IRDA_INT_MASK));
#endif
#elif (NUCODEGEN_UART5_FUNCSEL == NUCODEGEN_UART5_FUNCSEL_RS485)
    /* Configure UART5 and set UART5 baud rate */
    UART_Open(UART5, UART5_RS485_BAUD);

    /* Set Data Format*/ /* Only need parity enable whenever parity ODD/EVEN */
    UART_SetLine_Config(UART5, 0, UART_WORD_LEN_8, UART_PARITY_EVEN, UART_STOP_BIT_1);

    /* Set RTS pin active level as High level active */
    UART5->MODEM &= ~UART_MODEM_RTSACTLV_Msk;
    UART5->MODEM |= UART_RTS_IS_HIGH_LEV_ACTIVE;

#if (NUCODEGEN_UART5_RS485_MODE == NUCODEGEN_UART5_RS485_ADD_MODE)

    /* Set RS485-AAD Mode and address match is UART5_RS485_ADDRMV */
    UART_SelectRS485Mode(UART5, UART_ALTCTL_RS485AAD_Msk | UART_ALTCTL_ADDRDEN_Msk | UART_ALTCTL_RS485AUD_Msk, UART5_RS485_ADDRMV);


#else /*NUCODEGEN_UART5_RS485_NMM_MODE*/

    /* Set RX_DIS enable before set RS485-NMM mode */
    UART5->FIFO |= UART_FIFO_RXOFF_Msk;

    /* Set RS485-NMM Mode */

    UART_SelectRS485Mode(UART5, UART_ALTCTL_RS485NMM_Msk | UART_ALTCTL_ADDRDEN_Msk | UART_ALTCTL_RS485AUD_Msk, 0);

#endif

#if NUCODEGEN_UART5_RS485_INTEN
    /*Enable RS485 Interrupt*/
    UART_EnableInt(UART5, (NUCODEGEN_UART5_RS485_INT_MASK));
#endif
#elif (NUCODEGEN_UART5_FUNCSEL == NUCODEGEN_UART5_FUNCSEL_SINGLE_WIRE)
    /* Configure UART5 and set UART5 baud rate */
    UART_Open(UART5, UART5_SW_BAUD);
    /* Set Single Wire Mode */
    UART_SelectSingleWireMode(UART5);

#if NUCODEGEN_UART5_SW_INTEN
    /*Enable the Single Wire Interrupt*/
    UART_EnableInt(UART5, (NUCODEGEN_UART5_SW_INT_MASK));
#endif
#endif

#if NUCODEGEN_UART5_TOCNTEN
    /*Set the UART TimeOut count*/
    UART_SetTimeoutCnt(UART5, UART5_TOCNT);
#endif

#if  NUCODEGEN_UART5_PDMAEN
    /*Enable UART PDMA*/
    UART5->INTEN |= NUCODEGEN_UART5_PDMAEN_Msk;
#endif


#if NUCODEGEN_UART5_ABRDEN
    /* Enable auto baud rate detect function */
    UART5->ALTCTL |= UART_ALTCTL_ABRDEN_Msk;
#endif
   /* RX FIFO Interrupt TriggeLevel */
    UART5->FIFO = (UART5->FIFO &~ UART_FIFO_RFITL_Msk) | NUCODEGEN_UART5_RFITL;

#if NUCODEGEN_UART5_WKCTSEN
    /* Enable UART nCTS Wake up */
    UART5->WKCTL |= UART_WKCTL_WKCTSEN_Msk;
#endif

#if NUCODEGEN_UART5_WKDATEN
    /* Enable UART Incoming Data Wake up */
    UART5->WKCTL |= UART_WKCTL_WKDATEN_Msk;
#endif

#if NUCODEGEN_UART5_WKRFRTEN
    /* Enable UART Received Data FIFO Reached Threshold Wake up */
    UART5->WKCTL |= UART_WKCTL_WKRFRTEN_Msk;
#endif

#if NUCODEGEN_UART5_WKTOUTEN
    /* Enable UART Received Data FIFO Threshold Time-out Wake up */
    UART5->WKCTL |= UART_WKCTL_WKTOUTEN_Msk;
#endif

#if NUCODEGEN_UART5_WKRS485EN
    /* Enable RS-485 Address Match (AAD Mode) Wake up */
    UART5->WKCTL |= UART_WKCTL_WKRS485EN_Msk;
#endif

#if (NUCODEGEN_UART5_INTEN || NUCODEGEN_UART5_IRDA_INTEN || NUCODEGEN_UART5_RS485_INTEN || NUCODEGEN_UART5_SW_INTEN )
    /*Enable UART IRQ Handler */
    NVIC_EnableIRQ(UART57_IRQn);
#endif

}
#endif //NUCODEGEN_UART5

#if NUCODEGEN_UART6
void UART6_Init()
{
#if (NUCODEGEN_UART6_FUNCSEL == NUCODEGEN_UART6_FUNCSEL_UART)
    /* Configure UART6 and set UART6 baud rate */
    UART_Open(UART6, UART6_BAUD);

#if NUCODEGEN_UART6_LINE_CONFIG
    /* Set Data Format*/
    UART_SetLine_Config(UART6, 0, NUCODEGEN_UART6_WORD_LEN, NUCODEGEN_UART6_PARITY, NUCODEGEN_UART6_STOP_BIT);
#endif


#if NUCODEGEN_UART6_AUTOFLOW
    /* Enable RTS and CTS auto flow control */
    UART_EnableFlowCtrl(UART6);
    /* Auto-flow Control Trigger level */
    UART6->FIFO = (UART6->FIFO &~ UART_FIFO_RTSTRGLV_Msk) | NUCODEGEN_UART6_FIFO_RTSTRGLV;

#if (NUCODEGEN_UART6_RTSACTLV_LOW)
    /* nRTS pin output is low level active */
    UART6->MODEM |= UART_MODEM_RTSACTLV_Msk;
#else
    /* nRTS pin output is high level active */
    UART6->MODEM &= ~UART_MODEM_RTSACTLV_Msk;
#endif

#if (NUCODEGEN_UART6_CTSACTLV_LOW)
    /* nCTS pin input is low level active */
    UART6->MODEMSTS |= UART_MODEMSTS_CTSACTLV_Msk;
#else
    /* nCTS pin input is high level active */
    UART6->MODEMSTS &= ~UART_MODEMSTS_CTSACTLV_Msk;
#endif

#endif

#if NUCODEGEN_UART6_INTEN
    /* Enable UART6 Interrupt */
    UART_EnableInt(UART6, (NUCODEGEN_UART6_INT_MASK));
#endif

#elif (NUCODEGEN_UART6_FUNCSEL == NUCODEGEN_UART6_FUNCSEL_IrDA)
    /* Select IrDA Tx or Rx mode and set baud rate */
    UART_SelectIrDAMode(UART6, UART6_IRDA_BAUD, NUCODEGEN_UART6_IRDA_MODE);
    /* Set Data Format (only support 8 bits ,None Parity bit,1 Stop bit) */
    UART_SetLine_Config(UART6,0,UART_WORD_LEN_8, UART_PARITY_NONE, UART_STOP_BIT_1);

#if NUCODEGEN_UART6_IRDA_INTEN
    /* Enable UART6 IrDA Interrupt */
    UART_EnableInt(UART6, (NUCODEGEN_UART6_IRDA_INT_MASK));
#endif
#elif (NUCODEGEN_UART6_FUNCSEL == NUCODEGEN_UART6_FUNCSEL_RS485)
    /* Configure UART6 and set UART6 baud rate */
    UART_Open(UART6, UART6_RS485_BAUD);

    /* Set Data Format*/ /* Only need parity enable whenever parity ODD/EVEN */
    UART_SetLine_Config(UART6, 0, UART_WORD_LEN_8, UART_PARITY_EVEN, UART_STOP_BIT_1);

    /* Set RTS pin active level as High level active */
    UART6->MODEM &= ~UART_MODEM_RTSACTLV_Msk;
    UART6->MODEM |= UART_RTS_IS_HIGH_LEV_ACTIVE;

#if (NUCODEGEN_UART6_RS485_MODE == NUCODEGEN_UART6_RS485_ADD_MODE)

    /* Set RS485-AAD Mode and address match is UART6_RS485_ADDRMV */
    UART_SelectRS485Mode(UART6, UART_ALTCTL_RS485AAD_Msk | UART_ALTCTL_ADDRDEN_Msk | UART_ALTCTL_RS485AUD_Msk, UART6_RS485_ADDRMV);


#else /*NUCODEGEN_UART6_RS485_NMM_MODE*/

    /* Set RX_DIS enable before set RS485-NMM mode */
    UART6->FIFO |= UART_FIFO_RXOFF_Msk;

    /* Set RS485-NMM Mode */

    UART_SelectRS485Mode(UART6, UART_ALTCTL_RS485NMM_Msk | UART_ALTCTL_ADDRDEN_Msk | UART_ALTCTL_RS485AUD_Msk, 0);

#endif

#if NUCODEGEN_UART6_RS485_INTEN
    /*Enable RS485 Interrupt*/
    UART_EnableInt(UART6, (NUCODEGEN_UART6_RS485_INT_MASK));
#endif
#elif (NUCODEGEN_UART6_FUNCSEL == NUCODEGEN_UART6_FUNCSEL_SINGLE_WIRE)
    /* Configure UART6 and set UART6 baud rate */
    UART_Open(UART6, UART6_SW_BAUD);
    /* Set Single Wire Mode */
    UART_SelectSingleWireMode(UART6);

#if NUCODEGEN_UART6_SW_INTEN
    /*Enable the Single Wire Interrupt*/
    UART_EnableInt(UART6, (NUCODEGEN_UART6_SW_INT_MASK));
#endif
#endif

#if NUCODEGEN_UART6_TOCNTEN
    /*Set the UART TimeOut count*/
    UART_SetTimeoutCnt(UART6, UART6_TOCNT);
#endif

#if  NUCODEGEN_UART6_PDMAEN
    /*Enable UART PDMA*/
    UART6->INTEN |= NUCODEGEN_UART6_PDMAEN_Msk;
#endif


#if NUCODEGEN_UART6_ABRDEN
    /* Enable auto baud rate detect function */
    UART6->ALTCTL |= UART_ALTCTL_ABRDEN_Msk;
#endif

#if NUCODEGEN_UART6_WKCTSEN
    /* Enable UART nCTS Wake up */
    UART6->WKCTL |= UART_WKCTL_WKCTSEN_Msk;
#endif

#if NUCODEGEN_UART6_WKDATEN
    /* Enable UART Incoming Data Wake up */
    UART6->WKCTL |= UART_WKCTL_WKDATEN_Msk;
#endif

#if (NUCODEGEN_UART6_INTEN || NUCODEGEN_UART6_IRDA_INTEN || NUCODEGEN_UART6_RS485_INTEN || NUCODEGEN_UART6_SW_INTEN )
    /*Enable UART IRQ Handler */
    NVIC_EnableIRQ(UART46_IRQn);
#endif

}
#endif //NUCODEGEN_UART6

#if NUCODEGEN_UART7
void UART7_Init()
{
#if (NUCODEGEN_UART7_FUNCSEL == NUCODEGEN_UART7_FUNCSEL_UART)
    /* Configure UART7 and set UART7 baud rate */
    UART_Open(UART7, UART7_BAUD);

#if NUCODEGEN_UART7_LINE_CONFIG
    /* Set Data Format*/
    UART_SetLine_Config(UART7, 0, NUCODEGEN_UART7_WORD_LEN, NUCODEGEN_UART7_PARITY, NUCODEGEN_UART7_STOP_BIT);
#endif


#if NUCODEGEN_UART7_AUTOFLOW
    /* Enable RTS and CTS auto flow control */
    UART_EnableFlowCtrl(UART7);
    /* Auto-flow Control Trigger level */
    UART7->FIFO = (UART7->FIFO &~ UART_FIFO_RTSTRGLV_Msk) | NUCODEGEN_UART7_FIFO_RTSTRGLV;

#if (NUCODEGEN_UART7_RTSACTLV_LOW)
    /* nRTS pin output is low level active */
    UART7->MODEM |= UART_MODEM_RTSACTLV_Msk;
#else
    /* nRTS pin output is high level active */
    UART7->MODEM &= ~UART_MODEM_RTSACTLV_Msk;
#endif

#if (NUCODEGEN_UART7_CTSACTLV_LOW)
    /* nCTS pin input is low level active */
    UART7->MODEMSTS |= UART_MODEMSTS_CTSACTLV_Msk;
#else
    /* nCTS pin input is high level active */
    UART7->MODEMSTS &= ~UART_MODEMSTS_CTSACTLV_Msk;
#endif

#endif

#if NUCODEGEN_UART7_INTEN
    /* Enable UART7 Interrupt */
    UART_EnableInt(UART7, (NUCODEGEN_UART7_INT_MASK));
#endif

#elif (NUCODEGEN_UART7_FUNCSEL == NUCODEGEN_UART7_FUNCSEL_IrDA)
    /* Select IrDA Tx or Rx mode and set baud rate */
    UART_SelectIrDAMode(UART7, UART7_IRDA_BAUD, NUCODEGEN_UART7_IRDA_MODE);
    /* Set Data Format (only support 8 bits ,None Parity bit,1 Stop bit) */
    UART_SetLine_Config(UART7,0,UART_WORD_LEN_8, UART_PARITY_NONE, UART_STOP_BIT_1);

#if NUCODEGEN_UART7_IRDA_INTEN
    /* Enable UART7 IrDA Interrupt */
    UART_EnableInt(UART7, (NUCODEGEN_UART7_IRDA_INT_MASK));
#endif
#elif (NUCODEGEN_UART7_FUNCSEL == NUCODEGEN_UART7_FUNCSEL_RS485)
    /* Configure UART7 and set UART7 baud rate */
    UART_Open(UART7, UART7_RS485_BAUD);

    /* Set Data Format*/ /* Only need parity enable whenever parity ODD/EVEN */
    UART_SetLine_Config(UART7, 0, UART_WORD_LEN_8, UART_PARITY_EVEN, UART_STOP_BIT_1);

    /* Set RTS pin active level as High level active */
    UART7->MODEM &= ~UART_MODEM_RTSACTLV_Msk;
    UART7->MODEM |= UART_RTS_IS_HIGH_LEV_ACTIVE;

#if (NUCODEGEN_UART7_RS485_MODE == NUCODEGEN_UART7_RS485_ADD_MODE)

    /* Set RS485-AAD Mode and address match is UART7_RS485_ADDRMV */
    UART_SelectRS485Mode(UART7, UART_ALTCTL_RS485AAD_Msk | UART_ALTCTL_ADDRDEN_Msk | UART_ALTCTL_RS485AUD_Msk, UART7_RS485_ADDRMV);


#else /*NUCODEGEN_UART7_RS485_NMM_MODE*/

    /* Set RX_DIS enable before set RS485-NMM mode */
    UART7->FIFO |= UART_FIFO_RXOFF_Msk;

    /* Set RS485-NMM Mode */

    UART_SelectRS485Mode(UART7, UART_ALTCTL_RS485NMM_Msk | UART_ALTCTL_ADDRDEN_Msk | UART_ALTCTL_RS485AUD_Msk, 0);

#endif

#if NUCODEGEN_UART7_RS485_INTEN
    /*Enable RS485 Interrupt*/
    UART_EnableInt(UART7, (NUCODEGEN_UART7_RS485_INT_MASK));
#endif
#elif (NUCODEGEN_UART7_FUNCSEL == NUCODEGEN_UART7_FUNCSEL_SINGLE_WIRE)
    /* Configure UART7 and set UART7 baud rate */
    UART_Open(UART7, UART7_SW_BAUD);
    /* Set Single Wire Mode */
    UART_SelectSingleWireMode(UART7);

#if NUCODEGEN_UART7_SW_INTEN
    /*Enable the Single Wire Interrupt*/
    UART_EnableInt(UART7, (NUCODEGEN_UART7_SW_INT_MASK));
#endif
#endif

#if NUCODEGEN_UART7_TOCNTEN
    /*Set the UART TimeOut count*/
    UART_SetTimeoutCnt(UART7, UART7_TOCNT);
#endif

#if  NUCODEGEN_UART7_PDMAEN
    /*Enable UART PDMA*/
    UART7->INTEN |= NUCODEGEN_UART7_PDMAEN_Msk;
#endif


#if NUCODEGEN_UART7_ABRDEN
    /* Enable auto baud rate detect function */
    UART7->ALTCTL |= UART_ALTCTL_ABRDEN_Msk;
#endif

#if NUCODEGEN_UART7_WKCTSEN
    /* Enable UART nCTS Wake up */
    UART7->WKCTL |= UART_WKCTL_WKCTSEN_Msk;
#endif

#if NUCODEGEN_UART7_WKDATEN
    /* Enable UART Incoming Data Wake up */
    UART7->WKCTL |= UART_WKCTL_WKDATEN_Msk;
#endif

#if (NUCODEGEN_UART7_INTEN || NUCODEGEN_UART7_IRDA_INTEN || NUCODEGEN_UART7_RS485_INTEN || NUCODEGEN_UART7_SW_INTEN )
    /*Enable UART IRQ Handler */
    NVIC_EnableIRQ(UART57_IRQn);
#endif

}
#endif //NUCODEGEN_UART7

