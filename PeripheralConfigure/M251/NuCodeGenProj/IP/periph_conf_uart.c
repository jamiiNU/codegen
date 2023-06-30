
#if NUCODEGEN_UART0

#if (NUCODEGEN_UART0_FUNCSEL_SEL == NUCODEGEN_UART0_FUNCSEL_LIN)

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
#if (NUCODEGEN_UART0_FUNCSEL_SEL == NUCODEGEN_UART0_FUNCSEL_UART)

#if NUCODEGEN_UART0_WAKEUP_EN

#if (NUCODEGEN_UART0_DATA_WAKEUP_SEL == NUCODEGEN_UART0_INCOMING_DATA_WAKEUP)
    /* Select UART clock source as LXT */
    CLK_SetModuleClock(UART0_MODULE, CLK_CLKSEL1_UART0SEL_HIRC, CLK_CLKDIV0_UART0(1));
    /* Set UART baud rate and baud rate compensation */
    UART_Open(UART0, 9600);
    /* Set UART data wake-up start bit compensation value.
       It indicates how many clock cycle selected by UART_CLK does the UART controller can get the first bit (start bit)
       when the device is wake-up from power-down mode.
       If UART_CLK is selected as HIRC(48MHz) and the HIRC stable time is about 10.67us,
       the data wake-up start bit compensation value can be set as 520. */
    UART0->DWKCOMP = 520;

#elif(NUCODEGEN_UART0_DATA_WAKEUP_SEL == NUCODEGEN_UART0_FIFO_THRESHOLD_WAKEUP)
     /* Select UART clock source as LXT */
    CLK_SetModuleClock(UART0_MODULE, CLK_CLKSEL1_UART0SEL_LXT, CLK_CLKDIV0_UART0(1));
    /* Set UART baud rate and baud rate compensation */
    UART_Open(UART0, 9600);
    /* Compensation LXT cannot produce 9600 bps*/
    UART0->BRCOMP = 0xA5;
#else
    /* Configure UART0 and set UART0 baud rate */
    UART_Open(UART0, NUCODEGEN_UART0_BAUDRATE);
#endif

#else
    /* Configure UART0 and set UART0 baud rate */
    UART_Open(UART0, NUCODEGEN_UART0_BAUDRATE);
#endif

#if NUCODEGEN_UART0_LINE_CONFIG
    /* Set Data Format*/
    UART_SetLine_Config(UART0, 0, NUCODEGEN_UART0_WORD_LEN, NUCODEGEN_UART0_PARITY, NUCODEGEN_UART0_STOP_BIT);

#endif

#if NUCODEGEN_UART0_AUTOFLOW_EN
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

#if NUCODEGEN_UART0_ABRD_EN
    /* Enable auto baud rate detect function */
    UART0->ALTCTL |= UART_ALTCTL_ABRDEN_Msk;
#endif
    /* RX FIFO Interrupt Trigger Level */
    UART0->FIFO = (UART0->FIFO &~ UART_FIFO_RFITL_Msk) | NUCODEGEN_UART0_RFITL;

#if NUCODEGEN_UART0_WKCTS_EN
    /* Enable UART nCTS Wake up */
   UART0->WKCTL |= UART_WKCTL_WKCTSEN_Msk;
#endif

#if(NUCODEGEN_UART0_DATA_WAKEUP_SEL == NUCODEGEN_UART0_INCOMING_DATA_WAKEUP)
    /* Enable UART Incoming Data Wake up */
    UART0->WKCTL |= UART_WKCTL_WKDATEN_Msk;
#endif

#if (NUCODEGEN_UART0_DATA_WAKEUP_SEL == NUCODEGEN_UART0_FIFO_THRESHOLD_WAKEUP)
    /* Enable UART Received Data FIFO Reached Threshold Wake up */
    UART0->WKCTL |= UART_WKCTL_WKRFRTEN_Msk;

#if NUCODEGEN_UART0_WKTOUT_EN
    /* Enable UART Received Data FIFO Threshold Time-out Wake up */
    UART0->WKCTL |= UART_WKCTL_WKTOUTEN_Msk;
#endif

#endif

#if (NUCODEGEN_UART0_TOCNT_EN || NUCODEGEN_UART0_WKTOUT_EN)
    /*Set the UART TimeOut count*/
    UART_SetTimeoutCnt(UART0, NUCODEGEN_UART0_TOCNT);
#endif

#if  NUCODEGEN_UART0_PDMA_EN
    /*Enable UART PDMA*/ 
    UART0->INTEN |=  NUCODEGEN_UART0_PDMAEN_MASK;
#endif

#if (NUCODEGEN_UART0_INT_EN || NUCODEGEN_UART0_MODEMINT_EN || NUCODEGEN_UART0_ABRDINT_EN || NUCODEGEN_UART0_WAKEUP_INT_EN )
    /* Enable UART0 Interrupt */
    UART_EnableInt(UART0, (NUCODEGEN_UART0_INT_CONFIG_MASK ));
    /*Enable UART IRQ Handler */
    NVIC_EnableIRQ(UART0_IRQn);
#endif

#elif (NUCODEGEN_UART0_FUNCSEL_SEL == NUCODEGEN_UART0_FUNCSEL_LIN)
    /* Configure UART0 and set UART0 baud rate */
    UART_Open(UART0, UART0_LIN_BAUDRATE);
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
      g_au8SendData[g_i32Pointer++] = GetParityValue(UART0_LINCTL_PID);// ID+Parity Field
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
        g_au8SendData[g_i32Pointer++] = 0x55 ;// SYNC Field
        g_au8SendData[g_i32Pointer++] = GetParityValue(UART0_LINCTL_PID);// ID+Parity Field
        UART0->DAT = g_au8SendData[0];

        while (!(UART0->FIFOSTS & UART_FIFOSTS_TXEMPTYF_Msk));

        UART0->DAT = g_au8SendData[1];

        while (!(UART0->FIFOSTS & UART_FIFOSTS_TXEMPTYF_Msk));
  #endif

#endif
#if NUCODEGEN_UART0_LINCTL_LINRX_OFF
     /*Enable the "LIN Receiver Disable" */
     UART0->LINCTL |= UART_LINCTL_LINRXOFF_Msk;

#endif
#if NUCODEGEN_UART0_LINCTL_BITERR_EN
     /*Enable the LIN Bit Error Detect*/
     UART0->LINCTL |= UART_LINCTL_BITERREN_Msk;
#endif

#if NUCODEGEN_UART0_LINCTL_BRKDET_EN
    /*Enable the LIN Break Detection*/
    UART0->LINCTL |= UART_LINCTL_BRKDETEN_Msk;
#endif

#else

    /* Set LIN is Slave mode */
    /* Set LIN 1. PID as UART0_LINCTL_PID [UART_LINCTL_PID(UART0_LINCTL_PID)]
               2. Header select as includes "break field".[UART_LINCTL_HSEL_BREAK]
               3. Enabled LIN Slave Header Detection
               4. ID Parity Enable. Hardware will calculate and fill P0/P1 automatically  [UART_LINCTL_IDPEN_Msk]
               5. Enabled Mute mode
    */

  #if (NUCODEGEN_UART0_LINCTL_HSEL == NUCODEGEN_UART0_LINCTL_HSEL_BREAK_SYNC_ID)
    UART0->LINCTL = (UART_LINCTL_HSEL_BREAK_SYNC_ID|UART_LINCTL_PID(UART0_LINCTL_PID)|UART_LINCTL_BRKFL(UART0_LINCTL_BRKFL)|UART_LINCTL_BSL(UART0_LINCTL_BSL)
                     |UART_LINCTL_IDPEN_Msk | UART_LINCTL_MUTE_Msk |UART_LINCTL_SLVEN_Msk);
   #elif (NUCODEGEN_UART0_LINCTL_HSEL == NUCODEGEN_UART0_LINCTL_HSEL_BREAK_SYNC)
     UART0->LINCTL = (UART_LINCTL_HSEL_BREAK_SYNC|UART_LINCTL_PID(UART0_LINCTL_PID)|UART_LINCTL_BRKFL(UART0_LINCTL_BRKFL)|UART_LINCTL_BSL(UART0_LINCTL_BSL)
                      |UART_LINCTL_IDPEN_Msk|UART_LINCTL_MUTE_Msk |UART_LINCTL_SLVEN_Msk);
   #else
     UART0->LINCTL = (UART_LINCTL_HSEL_BREAK|UART_LINCTL_PID(UART0_LINCTL_PID)|UART_LINCTL_BRKFL(UART0_LINCTL_BRKFL)|UART_LINCTL_BSL(UART0_LINCTL_BSL)
                      |UART_LINCTL_IDPEN_Msk|UART_LINCTL_MUTE_Msk|UART_LINCTL_SLVEN_Msk);
   #endif

    /* Reset Rx FIFO             */
    UART0->FIFO |= UART_FIFO_RXRST_Msk;

#if NUCODEGEN_UART0_LINCTL_SLVAR_EN
    /* Enable the LIN Slave Automatic Resynchronization Mode */
    UART0->LINCTL |= UART_LINCTL_SLVAREN_Msk;
#endif

#if NUCODEGEN_UART0_LINCTL_SLVDU_EN
    /* Enable the LIN Slave Divider Update Method */
    UART0->LINCTL |= UART_LINCTL_SLVDUEN_Msk;
#endif

#if NUCODEGEN_UART0_LINCTL_BRKDET_EN
    /*Enable the LIN Break Detection*/
    UART0->LINCTL |= UART_LINCTL_BRKDETEN_Msk;
#endif

#if NUCODEGEN_UART0_LINCTL_SLVHD_EN
    /* Enable the LIN Slave Header Detection */
    UART0->LINCTL |= UART_LINCTL_SLVHDEN_Msk;

    /* Wait to Received the Header     */
//   while (!(UART0->LINSTS & UART_LINSTS_SLVHDETF_Msk)) {};
#endif

#endif

#if NUCODEGEN_UART0_LIN_INT_EN
    /* Enable UART0 Interrupt */
    UART_EnableInt(UART0, (UART_INTEN_LINIEN_Msk));

#endif


#elif (NUCODEGEN_UART0_FUNCSEL_SEL == NUCODEGEN_UART0_FUNCSEL_IrDA)
    /* Select IrDA Tx or Rx mode and set baud rate */
    UART_SelectIrDAMode(UART0, NUCODEGEN_UART0_IRDA_BAUDRATE, NUCODEGEN_UART0_IRDA_MODE);
    /* Set Data Format (only support 8 bits ,None Parity bit,1 Stop bit) */	
    UART_SetLine_Config(UART0,0,UART_WORD_LEN_8,UART_PARITY_NONE,UART_STOP_BIT_1);

#if NUCODEGEN_UART0_IRDA_INT_EN
    /* Enable UART0 Receive Data Available Interrupt */
    UART_EnableInt(UART0, (NUCODEGEN_UART0_IRDA_INT_MASK));
    /*Enable UART IRQ Handler */
    NVIC_EnableIRQ(UART0_IRQn);
#endif

#elif (NUCODEGEN_UART0_FUNCSEL_SEL == NUCODEGEN_UART0_FUNCSEL_RS485)

#if NUCODEGEN_UART0_WAKEUP_EN
#if(NUCODEGEN_UART0_WKRS485_EN || NUCODEGEN_UART0_WKRFRT_EN )
     /* Select UART clock source as LXT */
    CLK_SetModuleClock(UART0_MODULE, CLK_CLKSEL1_UART0SEL_LXT, CLK_CLKDIV0_UART0(1));
    /* Set UART baud rate and baud rate compensation */
    UART_Open(UART0, 9600);
    /* Compensation LXT cannot produce 9600 bps*/
    UART0->BRCOMP = 0xA5;
#else
    /* Configure UART0 and set UART0 baud rate */
    UART_Open(UART0, NUCODEGEN_UART0_RS485_BAUDRATE);
#endif
#else
    /* Configure UART0 and set UART0 baud rate */
    UART_Open(UART0, NUCODEGEN_UART0_RS485_BAUDRATE);
#endif

    /* Set Data Format*/ /* Only need parity enable whenever parity ODD/EVEN */
    UART_SetLine_Config(UART0, 0, UART_WORD_LEN_8, UART_PARITY_EVEN, UART_STOP_BIT_1);

     /* Set RTS pin active level as High level active */
    UART0->MODEM &= ~UART_MODEM_RTSACTLV_Msk;
    UART0->MODEM |= UART_RTS_IS_HIGH_LEV_ACTIVE;

#if (NUCODEGEN_UART0_RS485_MODE == NUCODEGEN_UART0_RS485_ADD_MODE)

    /* Set RS485-AAD Mode and address match is 0xC0 */
    UART_SelectRS485Mode(UART0,(UART_ALTCTL_RS485AAD_Msk | UART_ALTCTL_ADDRDEN_Msk | UART_ALTCTL_RS485AUD_Msk), NUCODEGEN_UART0_RS485_ADDRMV);

#if NUCODEGEN_UART0_WKRS485_EN
    /* Enable RS-485 Address Match (AAD Mode) Wake up */
    UART0->WKCTL |= UART_WKCTL_WKRS485EN_Msk;
#endif

#else /*NUCODEGEN_UART0_RS485_NMM_MODE*/

  /* Set RX_DIS enable before set RS485-NMM mode */
    UART0->FIFO |= UART_FIFO_RXOFF_Msk;

  /* Set RS485-NMM Mode */
   UART_SelectRS485Mode(UART0, UART_ALTCTL_RS485NMM_Msk | UART_ALTCTL_ADDRDEN_Msk | UART_ALTCTL_RS485AUD_Msk, 0);
   
#endif

    /* RX FIFO Interrupt Trigger Level */
    UART0->FIFO = (UART0->FIFO &~ UART_FIFO_RFITL_Msk) | NUCODEGEN_UART0_RFITL;

#if NUCODEGEN_UART0_WKRFRT_EN
    /* Enable UART Received Data FIFO Reached Threshold Wake up */
    UART0->WKCTL |= UART_WKCTL_WKRFRTEN_Msk;
#endif

#if NUCODEGEN_UART0_WKTOUT_EN
    /* Enable UART Received Data FIFO Threshold Time-out Wake up */
    UART0->WKCTL |= UART_WKCTL_WKTOUTEN_Msk;
#endif

#if (NUCODEGEN_UART0_TOCNT_EN || NUCODEGEN_UART0_WKTOUT_EN)
    /*Set the UART TimeOut count*/
    UART_SetTimeoutCnt(UART0, NUCODEGEN_UART0_TOCNT);
#endif

#if (NUCODEGEN_UART0_RS485_INT_EN || NUCODEGEN_UART0_WAKEUP_INT_EN )
    /* Enable RS485 Interrupr*/
    UART_EnableInt(UART0, (NUCODEGEN_UART0_RS485_INT_CONFIG_MASK));
    /*Enable UART IRQ Handler */
    NVIC_EnableIRQ(UART0_IRQn);
#endif

#elif (NUCODEGEN_UART0_FUNCSEL_SEL == NUCODEGEN_UART0_FUNCSEL_SINGLE_WIRE)

#if NUCODEGEN_UART0_WAKEUP_EN

#if (NUCODEGEN_UART0_DATA_WAKEUP_SEL == NUCODEGEN_UART0_INCOMING_DATA_WAKEUP)
    /* Select UART clock source as LXT */
    CLK_SetModuleClock(UART0_MODULE, CLK_CLKSEL1_UART0SEL_HIRC, CLK_CLKDIV0_UART0(1));
    /* Set UART baud rate and baud rate compensation */
    UART_Open(UART0, 9600);
    /* Set UART data wake-up start bit compensation value.
       It indicates how many clock cycle selected by UART_CLK does the UART controller can get the first bit (start bit)
       when the device is wake-up from power-down mode.
       If UART_CLK is selected as HIRC(48MHz) and the HIRC stable time is about 10.67us,
       the data wake-up start bit compensation value can be set as 520. */
    UART0->DWKCOMP = 520;

#elif(NUCODEGEN_UART0_DATA_WAKEUP_SEL == NUCODEGEN_UART0_FIFO_THRESHOLD_WAKEUP)
     /* Select UART clock source as LXT */
    CLK_SetModuleClock(UART0_MODULE, CLK_CLKSEL1_UART0SEL_LXT, CLK_CLKDIV0_UART0(1));
    /* Set UART baud rate and baud rate compensation */
    UART_Open(UART0, 9600);
    /* Compensation LXT cannot produce 9600 bps*/
    UART0->BRCOMP = 0xA5;
#else
    /* Configure UART0 and set UART0 baud rate */
    UART_Open(UART0, NUCODEGEN_UART0_SW_BAUD);
#endif

#else
    /* Configure UART0 and set UART0 baud rate */
    UART_Open(UART0, NUCODEGEN_UART0_SW_BAUD);
#endif


    /* Set Single Wire Mode */
    UART_SelectSingleWireMode(UART0);

#if NUCODEGEN_UART0_ABRD_EN
    /* Enable auto baud rate detect function */
    UART0->ALTCTL |= UART_ALTCTL_ABRDEN_Msk;
#endif
    /* RX FIFO Interrupt Trigger Level */
    UART0->FIFO = (UART0->FIFO &~ UART_FIFO_RFITL_Msk) | NUCODEGEN_UART0_RFITL;

#if(NUCODEGEN_UART0_DATA_WAKEUP_SEL == NUCODEGEN_UART0_INCOMING_DATA_WAKEUP)
    /* Enable UART Incoming Data Wake up */
    UART0->WKCTL |= UART_WKCTL_WKDATEN_Msk;
#endif

#if (NUCODEGEN_UART0_DATA_WAKEUP_SEL == NUCODEGEN_UART0_FIFO_THRESHOLD_WAKEUP)
    /* Enable UART Received Data FIFO Reached Threshold Wake up */
    UART0->WKCTL |= UART_WKCTL_WKRFRTEN_Msk;

#if NUCODEGEN_UART0_WKTOUT_EN
    /* Enable UART Received Data FIFO Threshold Time-out Wake up */
    UART0->WKCTL |= UART_WKCTL_WKTOUTEN_Msk;
#endif

#endif

#if (NUCODEGEN_UART0_TOCNT_EN || NUCODEGEN_UART0_WKTOUT_EN)
    /*Set the UART TimeOut count*/
    UART_SetTimeoutCnt(UART0, NUCODEGEN_UART0_TOCNT);
#endif

#if  NUCODEGEN_UART0_PDMA_EN
    /*Enable UART PDMA*/ 
    UART0->INTEN |=  NUCODEGEN_UART0_PDMAEN_MASK;
#endif

#if (NUCODEGEN_UART0_SW_INT_EN | NUCODEGEN_UART0_ABRDINT_EN || NUCODEGEN_UART0_WAKEUP_INT_EN)
    /*Enable the Single Wire Interrupt*/
    UART_EnableInt(UART0, (NUCODEGEN_UART0_SW_INT_CONFIG_MASK));
    /*Enable UART IRQ Handler */
    NVIC_EnableIRQ(UART0_IRQn);
#endif

#endif

}
#endif //NUCODEGEN_UART0

#if NUCODEGEN_UART1

void UART1_Init()
{
#if (NUCODEGEN_UART1_FUNCSEL_SEL == NUCODEGEN_UART1_FUNCSEL_UART)

#if NUCODEGEN_UART1_WAKEUP_EN

#if (NUCODEGEN_UART1_DATA_WAKEUP_SEL == NUCODEGEN_UART1_INCOMING_DATA_WAKEUP)
    /* Select UART clock source as LXT */
    CLK_SetModuleClock(UART1_MODULE, CLK_CLKSEL1_UART1SEL_HIRC, CLK_CLKDIV0_UART1(1));
    /* Set UART baud rate and baud rate compensation */
    UART_Open(UART1, 9600);
    /* Set UART data wake-up start bit compensation value.
       It indicates how many clock cycle selected by UART_CLK does the UART controller can get the first bit (start bit)
       when the device is wake-up from power-down mode.
       If UART_CLK is selected as HIRC(48MHz) and the HIRC stable time is about 10.67us,
       the data wake-up start bit compensation value can be set as 520. */
    UART1->DWKCOMP = 520;

#elif(NUCODEGEN_UART1_DATA_WAKEUP_SEL == NUCODEGEN_UART1_FIFO_THRESHOLD_WAKEUP)
     /* Select UART clock source as LXT */
    CLK_SetModuleClock(UART1_MODULE, CLK_CLKSEL1_UART1SEL_LXT, CLK_CLKDIV0_UART1(1));
    /* Set UART baud rate and baud rate compensation */
    UART_Open(UART1, 9600);
    /* Compensation LXT cannot produce 9600 bps*/
    UART1->BRCOMP = 0xA5;
#else
    /* Configure UART1 and set UART1 baud rate */
    UART_Open(UART1, NUCODEGEN_UART1_BAUDRATE);
#endif

#else
    /* Configure UART1 and set UART1 baud rate */
    UART_Open(UART1, NUCODEGEN_UART1_BAUDRATE);
#endif

#if NUCODEGEN_UART1_LINE_CONFIG
    /* Set Data Format*/
    UART_SetLine_Config(UART1, 0, NUCODEGEN_UART1_WORD_LEN, NUCODEGEN_UART1_PARITY, NUCODEGEN_UART1_STOP_BIT);

#endif

#if NUCODEGEN_UART1_AUTOFLOW_EN
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

#if NUCODEGEN_UART1_ABRD_EN
    /* Enable auto baud rate detect function */
    UART1->ALTCTL |= UART_ALTCTL_ABRDEN_Msk;
#endif
    /* RX FIFO Interrupt Trigger Level */
    UART1->FIFO = (UART1->FIFO &~ UART_FIFO_RFITL_Msk) | NUCODEGEN_UART1_RFITL;

#if NUCODEGEN_UART1_WKCTS_EN
    /* Enable UART nCTS Wake up */
   UART1->WKCTL |= UART_WKCTL_WKCTSEN_Msk;
#endif

#if(NUCODEGEN_UART1_DATA_WAKEUP_SEL == NUCODEGEN_UART1_INCOMING_DATA_WAKEUP)
    /* Enable UART Incoming Data Wake up */
    UART1->WKCTL |= UART_WKCTL_WKDATEN_Msk;
#endif

#if (NUCODEGEN_UART1_DATA_WAKEUP_SEL == NUCODEGEN_UART1_FIFO_THRESHOLD_WAKEUP)
    /* Enable UART Received Data FIFO Reached Threshold Wake up */
    UART1->WKCTL |= UART_WKCTL_WKRFRTEN_Msk;

#if NUCODEGEN_UART1_WKTOUT_EN
    /* Enable UART Received Data FIFO Threshold Time-out Wake up */
    UART1->WKCTL |= UART_WKCTL_WKTOUTEN_Msk;
#endif

#endif

#if (NUCODEGEN_UART1_TOCNT_EN || NUCODEGEN_UART1_WKTOUT_EN)
    /*Set the UART TimeOut count*/
    UART_SetTimeoutCnt(UART1, NUCODEGEN_UART1_TOCNT);
#endif

#if  NUCODEGEN_UART1_PDMA_EN
    /*Enable UART PDMA*/ 
    UART1->INTEN |=  NUCODEGEN_UART1_PDMAEN_MASK;
#endif

#if (NUCODEGEN_UART1_INT_EN || NUCODEGEN_UART1_MODEMINT_EN || NUCODEGEN_UART1_ABRDINT_EN || NUCODEGEN_UART1_WAKEUP_INT_EN )
    /* Enable UART1 Interrupt */
    UART_EnableInt(UART1, (NUCODEGEN_UART1_INT_CONFIG_MASK ));
    /*Enable UART IRQ Handler */
    NVIC_EnableIRQ(UART1_IRQn);
#endif

#elif (NUCODEGEN_UART1_FUNCSEL_SEL == NUCODEGEN_UART1_FUNCSEL_IrDA)
    /* Select IrDA Tx or Rx mode and set baud rate */
    UART_SelectIrDAMode(UART1, NUCODEGEN_UART1_IRDA_BAUDRATE, NUCODEGEN_UART1_IRDA_MODE);
    /* Set Data Format (only support 8 bits ,None Parity bit,1 Stop bit) */	
    UART_SetLine_Config(UART1,0,UART_WORD_LEN_8,UART_PARITY_NONE,UART_STOP_BIT_1);

#if NUCODEGEN_UART1_IRDA_INT_EN
    /* Enable UART1 Receive Data Available Interrupt */
    UART_EnableInt(UART1, (NUCODEGEN_UART1_IRDA_INT_MASK));
    /*Enable UART IRQ Handler */
    NVIC_EnableIRQ(UART1_IRQn);
#endif

#elif (NUCODEGEN_UART1_FUNCSEL_SEL == NUCODEGEN_UART1_FUNCSEL_RS485)

#if NUCODEGEN_UART1_WAKEUP_EN
#if(NUCODEGEN_UART1_WKRS485_EN || NUCODEGEN_UART1_WKRFRT_EN )
     /* Select UART clock source as LXT */
    CLK_SetModuleClock(UART1_MODULE, CLK_CLKSEL1_UART1SEL_LXT, CLK_CLKDIV0_UART1(1));
    /* Set UART baud rate and baud rate compensation */
    UART_Open(UART1, 9600);
    /* Compensation LXT cannot produce 9600 bps*/
    UART1->BRCOMP = 0xA5;
#else
    /* Configure UART1 and set UART1 baud rate */
    UART_Open(UART1, NUCODEGEN_UART1_RS485_BAUDRATE);
#endif
#else
    /* Configure UART1 and set UART1 baud rate */
    UART_Open(UART1, NUCODEGEN_UART1_RS485_BAUDRATE);
#endif

    /* Set Data Format*/ /* Only need parity enable whenever parity ODD/EVEN */
    UART_SetLine_Config(UART1, 0, UART_WORD_LEN_8, UART_PARITY_EVEN, UART_STOP_BIT_1);

     /* Set RTS pin active level as High level active */
    UART1->MODEM &= ~UART_MODEM_RTSACTLV_Msk;
    UART1->MODEM |= UART_RTS_IS_HIGH_LEV_ACTIVE;

#if (NUCODEGEN_UART1_RS485_MODE == NUCODEGEN_UART1_RS485_ADD_MODE)

    /* Set RS485-AAD Mode and address match is 0xC0 */
    UART_SelectRS485Mode(UART1,(UART_ALTCTL_RS485AAD_Msk | UART_ALTCTL_ADDRDEN_Msk | UART_ALTCTL_RS485AUD_Msk), NUCODEGEN_UART1_RS485_ADDRMV);

#if NUCODEGEN_UART1_WKRS485_EN
    /* Enable RS-485 Address Match (AAD Mode) Wake up */
    UART1->WKCTL |= UART_WKCTL_WKRS485EN_Msk;
#endif

#else /*NUCODEGEN_UART1_RS485_NMM_MODE*/

  /* Set RX_DIS enable before set RS485-NMM mode */
    UART1->FIFO |= UART_FIFO_RXOFF_Msk;

  /* Set RS485-NMM Mode */
   UART_SelectRS485Mode(UART1, UART_ALTCTL_RS485NMM_Msk | UART_ALTCTL_ADDRDEN_Msk | UART_ALTCTL_RS485AUD_Msk, 0);
   
#endif

    /* RX FIFO Interrupt Trigger Level */
    UART1->FIFO = (UART1->FIFO &~ UART_FIFO_RFITL_Msk) | NUCODEGEN_UART1_RFITL;

#if NUCODEGEN_UART1_WKRFRT_EN
    /* Enable UART Received Data FIFO Reached Threshold Wake up */
    UART1->WKCTL |= UART_WKCTL_WKRFRTEN_Msk;
#endif

#if NUCODEGEN_UART1_WKTOUT_EN
    /* Enable UART Received Data FIFO Threshold Time-out Wake up */
    UART1->WKCTL |= UART_WKCTL_WKTOUTEN_Msk;
#endif

#if (NUCODEGEN_UART1_TOCNT_EN || NUCODEGEN_UART1_WKTOUT_EN)
    /*Set the UART TimeOut count*/
    UART_SetTimeoutCnt(UART1, NUCODEGEN_UART1_TOCNT);
#endif

#if (NUCODEGEN_UART1_RS485_INT_EN || NUCODEGEN_UART1_WAKEUP_INT_EN )
    /* Enable RS485 Interrupr*/
    UART_EnableInt(UART1, (NUCODEGEN_UART1_RS485_INT_CONFIG_MASK));
    /*Enable UART IRQ Handler */
    NVIC_EnableIRQ(UART1_IRQn);
#endif

#elif (NUCODEGEN_UART1_FUNCSEL_SEL == NUCODEGEN_UART1_FUNCSEL_SINGLE_WIRE)

#if NUCODEGEN_UART1_WAKEUP_EN

#if (NUCODEGEN_UART1_DATA_WAKEUP_SEL == NUCODEGEN_UART1_INCOMING_DATA_WAKEUP)
    /* Select UART clock source as LXT */
    CLK_SetModuleClock(UART1_MODULE, CLK_CLKSEL1_UART1SEL_HIRC, CLK_CLKDIV0_UART1(1));
    /* Set UART baud rate and baud rate compensation */
    UART_Open(UART1, 9600);
    /* Set UART data wake-up start bit compensation value.
       It indicates how many clock cycle selected by UART_CLK does the UART controller can get the first bit (start bit)
       when the device is wake-up from power-down mode.
       If UART_CLK is selected as HIRC(48MHz) and the HIRC stable time is about 10.67us,
       the data wake-up start bit compensation value can be set as 520. */
    UART1->DWKCOMP = 520;

#elif(NUCODEGEN_UART1_DATA_WAKEUP_SEL == NUCODEGEN_UART1_FIFO_THRESHOLD_WAKEUP)
     /* Select UART clock source as LXT */
    CLK_SetModuleClock(UART1_MODULE, CLK_CLKSEL1_UART1SEL_LXT, CLK_CLKDIV0_UART1(1));
    /* Set UART baud rate and baud rate compensation */
    UART_Open(UART1, 9600);
    /* Compensation LXT cannot produce 9600 bps*/
    UART1->BRCOMP = 0xA5;
#else
    /* Configure UART1 and set UART1 baud rate */
    UART_Open(UART1, NUCODEGEN_UART1_SW_BAUD);
#endif

#else
    /* Configure UART1 and set UART1 baud rate */
    UART_Open(UART1, NUCODEGEN_UART1_SW_BAUD);
#endif

    /* Set Single Wire Mode */
    UART_SelectSingleWireMode(UART1);

#if NUCODEGEN_UART1_ABRD_EN
    /* Enable auto baud rate detect function */
    UART1->ALTCTL |= UART_ALTCTL_ABRDEN_Msk;
#endif
    /* RX FIFO Interrupt Trigger Level */
    UART1->FIFO = (UART1->FIFO &~ UART_FIFO_RFITL_Msk) | NUCODEGEN_UART1_RFITL;

#if(NUCODEGEN_UART1_DATA_WAKEUP_SEL == NUCODEGEN_UART1_INCOMING_DATA_WAKEUP)
    /* Enable UART Incoming Data Wake up */
    UART1->WKCTL |= UART_WKCTL_WKDATEN_Msk;
#endif

#if (NUCODEGEN_UART1_DATA_WAKEUP_SEL == NUCODEGEN_UART1_FIFO_THRESHOLD_WAKEUP)
    /* Enable UART Received Data FIFO Reached Threshold Wake up */
    UART1->WKCTL |= UART_WKCTL_WKRFRTEN_Msk;

#if NUCODEGEN_UART1_WKTOUT_EN
    /* Enable UART Received Data FIFO Threshold Time-out Wake up */
    UART1->WKCTL |= UART_WKCTL_WKTOUTEN_Msk;
#endif

#endif

#if (NUCODEGEN_UART1_TOCNT_EN || NUCODEGEN_UART1_WKTOUT_EN)
    /*Set the UART TimeOut count*/
    UART_SetTimeoutCnt(UART1, NUCODEGEN_UART1_TOCNT);
#endif

#if  NUCODEGEN_UART1_PDMA_EN
    /*Enable UART PDMA*/ 
    UART1->INTEN |=  NUCODEGEN_UART1_PDMAEN_MASK;
#endif

#if (NUCODEGEN_UART1_SW_INT_EN | NUCODEGEN_UART1_ABRDINT_EN || NUCODEGEN_UART1_WAKEUP_INT_EN)
    /*Enable the Single Wire Interrupt*/
    UART_EnableInt(UART1, (NUCODEGEN_UART1_SW_INT_CONFIG_MASK));
    /*Enable UART IRQ Handler */
    NVIC_EnableIRQ(UART1_IRQn);
#endif

#endif

}
#endif //NUCODEGEN_UART1

#if NUCODEGEN_UART2

void UART2_Init()
{
#if (NUCODEGEN_UART2_FUNCSEL_SEL == NUCODEGEN_UART2_FUNCSEL_UART)

#if NUCODEGEN_UART2_WAKEUP_EN

#if (NUCODEGEN_UART2_DATA_WAKEUP_SEL == NUCODEGEN_UART2_INCOMING_DATA_WAKEUP)
    /* Select UART clock source as LXT */
    CLK_SetModuleClock(UART2_MODULE, CLK_CLKSEL3_UART2SEL_HIRC, CLK_CLKDIV4_UART2(1));
    /* Set UART baud rate and baud rate compensation */
    UART_Open(UART2, 9600);
    /* Set UART data wake-up start bit compensation value.
       It indicates how many clock cycle selected by UART_CLK does the UART controller can get the first bit (start bit)
       when the device is wake-up from power-down mode.
       If UART_CLK is selected as HIRC(48MHz) and the HIRC stable time is about 10.67us,
       the data wake-up start bit compensation value can be set as 520. */
    UART2->DWKCOMP = 520;

#elif(NUCODEGEN_UART2_DATA_WAKEUP_SEL == NUCODEGEN_UART2_FIFO_THRESHOLD_WAKEUP)
     /* Select UART clock source as LXT */
    CLK_SetModuleClock(UART2_MODULE, CLK_CLKSEL3_UART2SEL_LXT, CLK_CLKDIV4_UART2(1));
    /* Set UART baud rate and baud rate compensation */
    UART_Open(UART2, 9600);
    /* Compensation LXT cannot produce 9600 bps*/
    UART2->BRCOMP = 0xA5;
#else
    /* Configure UART2 and set UART2 baud rate */
    UART_Open(UART2, NUCODEGEN_UART2_BAUDRATE);
#endif

#else
    /* Configure UART2 and set UART2 baud rate */
    UART_Open(UART2, NUCODEGEN_UART2_BAUDRATE);
#endif

#if NUCODEGEN_UART2_LINE_CONFIG
    /* Set Data Format*/
    UART_SetLine_Config(UART2, 0, NUCODEGEN_UART2_WORD_LEN, NUCODEGEN_UART2_PARITY, NUCODEGEN_UART2_STOP_BIT);

#endif

#if NUCODEGEN_UART2_AUTOFLOW_EN
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

#if NUCODEGEN_UART2_ABRD_EN
    /* Enable auto baud rate detect function */
    UART2->ALTCTL |= UART_ALTCTL_ABRDEN_Msk;
#endif
    /* RX FIFO Interrupt Trigger Level */
    UART2->FIFO = (UART2->FIFO &~ UART_FIFO_RFITL_Msk) | NUCODEGEN_UART2_RFITL;

#if NUCODEGEN_UART2_WKCTS_EN
    /* Enable UART nCTS Wake up */
   UART2->WKCTL |= UART_WKCTL_WKCTSEN_Msk;
#endif

#if(NUCODEGEN_UART2_DATA_WAKEUP_SEL == NUCODEGEN_UART2_INCOMING_DATA_WAKEUP)
    /* Enable UART Incoming Data Wake up */
    UART2->WKCTL |= UART_WKCTL_WKDATEN_Msk;
#endif

#if (NUCODEGEN_UART2_DATA_WAKEUP_SEL == NUCODEGEN_UART2_FIFO_THRESHOLD_WAKEUP)
    /* Enable UART Received Data FIFO Reached Threshold Wake up */
    UART2->WKCTL |= UART_WKCTL_WKRFRTEN_Msk;

#if NUCODEGEN_UART2_WKTOUT_EN
    /* Enable UART Received Data FIFO Threshold Time-out Wake up */
    UART2->WKCTL |= UART_WKCTL_WKTOUTEN_Msk;
#endif

#endif

#if (NUCODEGEN_UART2_TOCNT_EN || NUCODEGEN_UART2_WKTOUT_EN)
    /*Set the UART TimeOut count*/
    UART_SetTimeoutCnt(UART2, NUCODEGEN_UART2_TOCNT);
#endif

#if  NUCODEGEN_UART2_PDMA_EN
    /*Enable UART PDMA*/ 
    UART2->INTEN |=  NUCODEGEN_UART2_PDMAEN_MASK;
#endif

#if (NUCODEGEN_UART2_INT_EN || NUCODEGEN_UART2_MODEMINT_EN || NUCODEGEN_UART2_ABRDINT_EN || NUCODEGEN_UART2_WAKEUP_INT_EN )
    /* Enable UART2 Interrupt */
    UART_EnableInt(UART2, (NUCODEGEN_UART2_INT_CONFIG_MASK ));
    /*Enable UART IRQ Handler */
    NVIC_EnableIRQ(UART2_IRQn);
#endif

#elif (NUCODEGEN_UART2_FUNCSEL_SEL == NUCODEGEN_UART2_FUNCSEL_IrDA)
    /* Select IrDA Tx or Rx mode and set baud rate */
    UART_SelectIrDAMode(UART2, NUCODEGEN_UART2_IRDA_BAUDRATE, NUCODEGEN_UART2_IRDA_MODE);
    /* Set Data Format (only support 8 bits ,None Parity bit,1 Stop bit) */	
    UART_SetLine_Config(UART2,0,UART_WORD_LEN_8,UART_PARITY_NONE,UART_STOP_BIT_1);

#if NUCODEGEN_UART2_IRDA_INT_EN
    /* Enable UART2 Receive Data Available Interrupt */
    UART_EnableInt(UART2, (NUCODEGEN_UART2_IRDA_INT_MASK));
    /*Enable UART IRQ Handler */
    NVIC_EnableIRQ(UART2_IRQn);
#endif

#elif (NUCODEGEN_UART2_FUNCSEL_SEL == NUCODEGEN_UART2_FUNCSEL_RS485)

#if NUCODEGEN_UART2_WAKEUP_EN
#if(NUCODEGEN_UART2_WKRS485_EN || NUCODEGEN_UART2_WKRFRT_EN )
     /* Select UART clock source as LXT */
    CLK_SetModuleClock(UART2_MODULE, CLK_CLKSEL3_UART2SEL_LXT, CLK_CLKDIV4_UART2(1));
    /* Set UART baud rate and baud rate compensation */
    UART_Open(UART2, 9600);
    /* Compensation LXT cannot produce 9600 bps*/
    UART2->BRCOMP = 0xA5;
#else
    /* Configure UART2 and set UART2 baud rate */
    UART_Open(UART2, NUCODEGEN_UART2_RS485_BAUDRATE);
#endif
#else
    /* Configure UART2 and set UART2 baud rate */
    UART_Open(UART2, NUCODEGEN_UART2_RS485_BAUDRATE);
#endif

    /* Set Data Format*/ /* Only need parity enable whenever parity ODD/EVEN */
    UART_SetLine_Config(UART2, 0, UART_WORD_LEN_8, UART_PARITY_EVEN, UART_STOP_BIT_1);

     /* Set RTS pin active level as High level active */
    UART2->MODEM &= ~UART_MODEM_RTSACTLV_Msk;
    UART2->MODEM |= UART_RTS_IS_HIGH_LEV_ACTIVE;

#if (NUCODEGEN_UART2_RS485_MODE == NUCODEGEN_UART2_RS485_ADD_MODE)

    /* Set RS485-AAD Mode and address match is 0xC0 */
    UART_SelectRS485Mode(UART2,(UART_ALTCTL_RS485AAD_Msk | UART_ALTCTL_ADDRDEN_Msk | UART_ALTCTL_RS485AUD_Msk), NUCODEGEN_UART2_RS485_ADDRMV);

#if NUCODEGEN_UART2_WKRS485_EN
    /* Enable RS-485 Address Match (AAD Mode) Wake up */
    UART2->WKCTL |= UART_WKCTL_WKRS485EN_Msk;
#endif

#else /*NUCODEGEN_UART2_RS485_NMM_MODE*/

  /* Set RX_DIS enable before set RS485-NMM mode */
    UART2->FIFO |= UART_FIFO_RXOFF_Msk;

  /* Set RS485-NMM Mode */
   UART_SelectRS485Mode(UART2, UART_ALTCTL_RS485NMM_Msk | UART_ALTCTL_ADDRDEN_Msk | UART_ALTCTL_RS485AUD_Msk, 0);
   
#endif

    /* RX FIFO Interrupt Trigger Level */
    UART2->FIFO = (UART2->FIFO &~ UART_FIFO_RFITL_Msk) | NUCODEGEN_UART2_RFITL;

#if NUCODEGEN_UART2_WKRFRT_EN
    /* Enable UART Received Data FIFO Reached Threshold Wake up */
    UART2->WKCTL |= UART_WKCTL_WKRFRTEN_Msk;
#endif

#if NUCODEGEN_UART2_WKTOUT_EN
    /* Enable UART Received Data FIFO Threshold Time-out Wake up */
    UART2->WKCTL |= UART_WKCTL_WKTOUTEN_Msk;
#endif

#if (NUCODEGEN_UART2_TOCNT_EN || NUCODEGEN_UART2_WKTOUT_EN)
    /*Set the UART TimeOut count*/
    UART_SetTimeoutCnt(UART2, NUCODEGEN_UART2_TOCNT);
#endif

#if (NUCODEGEN_UART2_RS485_INT_EN || NUCODEGEN_UART2_WAKEUP_INT_EN )
    /* Enable RS485 Interrupr*/
    UART_EnableInt(UART2, (NUCODEGEN_UART2_RS485_INT_CONFIG_MASK));
    /*Enable UART IRQ Handler */
    NVIC_EnableIRQ(UART2_IRQn);
#endif

#elif (NUCODEGEN_UART2_FUNCSEL_SEL == NUCODEGEN_UART2_FUNCSEL_SINGLE_WIRE)

#if NUCODEGEN_UART2_WAKEUP_EN

#if (NUCODEGEN_UART2_DATA_WAKEUP_SEL == NUCODEGEN_UART2_INCOMING_DATA_WAKEUP)
    /* Select UART clock source as LXT */
    CLK_SetModuleClock(UART2_MODULE, CLK_CLKSEL3_UART2SEL_HIRC, CLK_CLKDIV4_UART2(1));
    /* Set UART baud rate and baud rate compensation */
    UART_Open(UART2, 9600);
    /* Set UART data wake-up start bit compensation value.
       It indicates how many clock cycle selected by UART_CLK does the UART controller can get the first bit (start bit)
       when the device is wake-up from power-down mode.
       If UART_CLK is selected as HIRC(48MHz) and the HIRC stable time is about 10.67us,
       the data wake-up start bit compensation value can be set as 520. */
    UART2->DWKCOMP = 520;

#elif(NUCODEGEN_UART2_DATA_WAKEUP_SEL == NUCODEGEN_UART2_FIFO_THRESHOLD_WAKEUP)
     /* Select UART clock source as LXT */
    CLK_SetModuleClock(UART2_MODULE, CLK_CLKSEL3_UART2SEL_LXT, CLK_CLKDIV4_UART2(1));
    /* Set UART baud rate and baud rate compensation */
    UART_Open(UART2, 9600);
    /* Compensation LXT cannot produce 9600 bps*/
    UART2->BRCOMP = 0xA5;
#else
    /* Configure UART2 and set UART2 baud rate */
    UART_Open(UART2, NUCODEGEN_UART2_SW_BAUD);
#endif

#else
    /* Configure UART2 and set UART2 baud rate */
    UART_Open(UART2, NUCODEGEN_UART2_SW_BAUD);
#endif

    /* Set Single Wire Mode */
    UART_SelectSingleWireMode(UART2);

#if NUCODEGEN_UART2_ABRD_EN
    /* Enable auto baud rate detect function */
    UART2->ALTCTL |= UART_ALTCTL_ABRDEN_Msk;
#endif
    /* RX FIFO Interrupt Trigger Level */
    UART2->FIFO = (UART2->FIFO &~ UART_FIFO_RFITL_Msk) | NUCODEGEN_UART2_RFITL;

#if(NUCODEGEN_UART2_DATA_WAKEUP_SEL == NUCODEGEN_UART2_INCOMING_DATA_WAKEUP)
    /* Enable UART Incoming Data Wake up */
    UART2->WKCTL |= UART_WKCTL_WKDATEN_Msk;
#endif

#if (NUCODEGEN_UART2_DATA_WAKEUP_SEL == NUCODEGEN_UART2_FIFO_THRESHOLD_WAKEUP)
    /* Enable UART Received Data FIFO Reached Threshold Wake up */
    UART2->WKCTL |= UART_WKCTL_WKRFRTEN_Msk;

#if NUCODEGEN_UART2_WKTOUT_EN
    /* Enable UART Received Data FIFO Threshold Time-out Wake up */
    UART2->WKCTL |= UART_WKCTL_WKTOUTEN_Msk;
#endif

#endif

#if (NUCODEGEN_UART2_TOCNT_EN || NUCODEGEN_UART2_WKTOUT_EN)
    /*Set the UART TimeOut count*/
    UART_SetTimeoutCnt(UART2, NUCODEGEN_UART2_TOCNT);
#endif

#if  NUCODEGEN_UART2_PDMA_EN
    /*Enable UART PDMA*/ 
    UART2->INTEN |=  NUCODEGEN_UART2_PDMAEN_MASK;
#endif

#if (NUCODEGEN_UART2_SW_INT_EN | NUCODEGEN_UART2_ABRDINT_EN || NUCODEGEN_UART2_WAKEUP_INT_EN)
    /*Enable the Single Wire Interrupt*/
    UART_EnableInt(UART2, (NUCODEGEN_UART2_SW_INT_CONFIG_MASK));
    /*Enable UART IRQ Handler */
    NVIC_EnableIRQ(UART2_IRQn);
#endif

#endif

}
#endif //NUCODEGEN_UART2

#if NUCODEGEN_UART3

void UART3_Init()
{
#if (NUCODEGEN_UART3_FUNCSEL_SEL == NUCODEGEN_UART3_FUNCSEL_UART)

#if NUCODEGEN_UART3_WAKEUP_EN

#if (NUCODEGEN_UART3_DATA_WAKEUP_SEL == NUCODEGEN_UART3_INCOMING_DATA_WAKEUP)
    /* Select UART clock source as LXT */
    CLK_SetModuleClock(UART3_MODULE, CLK_CLKSEL3_UART3SEL_HIRC, CLK_CLKDIV4_UART3(1));
    /* Set UART baud rate and baud rate compensation */
    UART_Open(UART3, 9600);
    /* Set UART data wake-up start bit compensation value.
       It indicates how many clock cycle selected by UART_CLK does the UART controller can get the first bit (start bit)
       when the device is wake-up from power-down mode.
       If UART_CLK is selected as HIRC(48MHz) and the HIRC stable time is about 10.67us,
       the data wake-up start bit compensation value can be set as 520. */
    UART3->DWKCOMP = 520;

#elif(NUCODEGEN_UART3_DATA_WAKEUP_SEL == NUCODEGEN_UART3_FIFO_THRESHOLD_WAKEUP)
     /* Select UART clock source as LXT */
    CLK_SetModuleClock(UART3_MODULE, CLK_CLKSEL3_UART3SEL_LXT, CLK_CLKDIV4_UART3(1));
    /* Set UART baud rate and baud rate compensation */
    UART_Open(UART3, 9600);
    /* Compensation LXT cannot produce 9600 bps*/
    UART3->BRCOMP = 0xA5;
#else
    /* Configure UART3 and set UART3 baud rate */
    UART_Open(UART3, NUCODEGEN_UART3_BAUDRATE);
#endif

#else
    /* Configure UART3 and set UART3 baud rate */
    UART_Open(UART3, NUCODEGEN_UART3_BAUDRATE);
#endif

#if NUCODEGEN_UART3_LINE_CONFIG
    /* Set Data Format*/
    UART_SetLine_Config(UART3, 0, NUCODEGEN_UART3_WORD_LEN, NUCODEGEN_UART3_PARITY, NUCODEGEN_UART3_STOP_BIT);

#endif

#if NUCODEGEN_UART3_AUTOFLOW_EN
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

#if NUCODEGEN_UART3_ABRD_EN
    /* Enable auto baud rate detect function */
    UART3->ALTCTL |= UART_ALTCTL_ABRDEN_Msk;
#endif
    /* RX FIFO Interrupt Trigger Level */
    UART3->FIFO = (UART3->FIFO &~ UART_FIFO_RFITL_Msk) | NUCODEGEN_UART3_RFITL;

#if NUCODEGEN_UART3_WKCTS_EN
    /* Enable UART nCTS Wake up */
   UART3->WKCTL |= UART_WKCTL_WKCTSEN_Msk;
#endif

#if(NUCODEGEN_UART3_DATA_WAKEUP_SEL == NUCODEGEN_UART3_INCOMING_DATA_WAKEUP)
    /* Enable UART Incoming Data Wake up */
    UART3->WKCTL |= UART_WKCTL_WKDATEN_Msk;
#endif

#if (NUCODEGEN_UART3_DATA_WAKEUP_SEL == NUCODEGEN_UART3_FIFO_THRESHOLD_WAKEUP)
    /* Enable UART Received Data FIFO Reached Threshold Wake up */
    UART3->WKCTL |= UART_WKCTL_WKRFRTEN_Msk;

#if NUCODEGEN_UART3_WKTOUT_EN
    /* Enable UART Received Data FIFO Threshold Time-out Wake up */
    UART3->WKCTL |= UART_WKCTL_WKTOUTEN_Msk;
#endif

#endif

#if (NUCODEGEN_UART3_TOCNT_EN || NUCODEGEN_UART3_WKTOUT_EN)
    /*Set the UART TimeOut count*/
    UART_SetTimeoutCnt(UART3, NUCODEGEN_UART3_TOCNT);
#endif

#if  NUCODEGEN_UART3_PDMA_EN
    /*Enable UART PDMA*/ 
    UART3->INTEN |=  NUCODEGEN_UART3_PDMAEN_MASK;
#endif

#if (NUCODEGEN_UART3_INT_EN || NUCODEGEN_UART3_MODEMINT_EN || NUCODEGEN_UART3_ABRDINT_EN || NUCODEGEN_UART3_WAKEUP_INT_EN )
    /* Enable UART3 Interrupt */
    UART_EnableInt(UART3, (NUCODEGEN_UART3_INT_CONFIG_MASK ));
    /*Enable UART IRQ Handler */
    NVIC_EnableIRQ(UART3_IRQn);
#endif

#elif (NUCODEGEN_UART3_FUNCSEL_SEL == NUCODEGEN_UART3_FUNCSEL_IrDA)
    /* Select IrDA Tx or Rx mode and set baud rate */
    UART_SelectIrDAMode(UART3, NUCODEGEN_UART3_IRDA_BAUDRATE, NUCODEGEN_UART3_IRDA_MODE);
    /* Set Data Format (only support 8 bits ,None Parity bit,1 Stop bit) */	
    UART_SetLine_Config(UART3,0,UART_WORD_LEN_8,UART_PARITY_NONE,UART_STOP_BIT_1);

#if NUCODEGEN_UART3_IRDA_INT_EN
    /* Enable UART3 Receive Data Available Interrupt */
    UART_EnableInt(UART3, (NUCODEGEN_UART3_IRDA_INT_MASK));
    /*Enable UART IRQ Handler */
    NVIC_EnableIRQ(UART3_IRQn);
#endif

#elif (NUCODEGEN_UART3_FUNCSEL_SEL == NUCODEGEN_UART3_FUNCSEL_RS485)

#if NUCODEGEN_UART3_WAKEUP_EN
#if(NUCODEGEN_UART3_WKRS485_EN || NUCODEGEN_UART3_WKRFRT_EN )
     /* Select UART clock source as LXT */
    CLK_SetModuleClock(UART3_MODULE, CLK_CLKSEL3_UART3SEL_LXT, CLK_CLKDIV4_UART3(1));
    /* Set UART baud rate and baud rate compensation */
    UART_Open(UART3, 9600);
    /* Compensation LXT cannot produce 9600 bps*/
    UART3->BRCOMP = 0xA5;
#else
    /* Configure UART3 and set UART3 baud rate */
    UART_Open(UART3, NUCODEGEN_UART3_RS485_BAUDRATE);
#endif
#else
    /* Configure UART3 and set UART3 baud rate */
    UART_Open(UART3, NUCODEGEN_UART3_RS485_BAUDRATE);
#endif

    /* Set Data Format*/ /* Only need parity enable whenever parity ODD/EVEN */
    UART_SetLine_Config(UART3, 0, UART_WORD_LEN_8, UART_PARITY_EVEN, UART_STOP_BIT_1);

     /* Set RTS pin active level as High level active */
    UART3->MODEM &= ~UART_MODEM_RTSACTLV_Msk;
    UART3->MODEM |= UART_RTS_IS_HIGH_LEV_ACTIVE;

#if (NUCODEGEN_UART3_RS485_MODE == NUCODEGEN_UART3_RS485_ADD_MODE)

    /* Set RS485-AAD Mode and address match is 0xC0 */
    UART_SelectRS485Mode(UART3,(UART_ALTCTL_RS485AAD_Msk | UART_ALTCTL_ADDRDEN_Msk | UART_ALTCTL_RS485AUD_Msk), NUCODEGEN_UART3_RS485_ADDRMV);

#if NUCODEGEN_UART3_WKRS485_EN
    /* Enable RS-485 Address Match (AAD Mode) Wake up */
    UART3->WKCTL |= UART_WKCTL_WKRS485EN_Msk;
#endif

#else /*NUCODEGEN_UART3_RS485_NMM_MODE*/

  /* Set RX_DIS enable before set RS485-NMM mode */
    UART3->FIFO |= UART_FIFO_RXOFF_Msk;

  /* Set RS485-NMM Mode */
   UART_SelectRS485Mode(UART3, UART_ALTCTL_RS485NMM_Msk | UART_ALTCTL_ADDRDEN_Msk | UART_ALTCTL_RS485AUD_Msk, 0);
   
#endif

    /* RX FIFO Interrupt Trigger Level */
    UART3->FIFO = (UART3->FIFO &~ UART_FIFO_RFITL_Msk) | NUCODEGEN_UART3_RFITL;

#if NUCODEGEN_UART3_WKRFRT_EN
    /* Enable UART Received Data FIFO Reached Threshold Wake up */
    UART3->WKCTL |= UART_WKCTL_WKRFRTEN_Msk;
#endif

#if NUCODEGEN_UART3_WKTOUT_EN
    /* Enable UART Received Data FIFO Threshold Time-out Wake up */
    UART3->WKCTL |= UART_WKCTL_WKTOUTEN_Msk;
#endif

#if (NUCODEGEN_UART3_TOCNT_EN || NUCODEGEN_UART3_WKTOUT_EN)
    /*Set the UART TimeOut count*/
    UART_SetTimeoutCnt(UART3, NUCODEGEN_UART3_TOCNT);
#endif

#if (NUCODEGEN_UART3_RS485_INT_EN || NUCODEGEN_UART3_WAKEUP_INT_EN )
    /* Enable RS485 Interrupr*/
    UART_EnableInt(UART3, (NUCODEGEN_UART3_RS485_INT_CONFIG_MASK));
    /*Enable UART IRQ Handler */
    NVIC_EnableIRQ(UART3_IRQn);
#endif

#elif (NUCODEGEN_UART3_FUNCSEL_SEL == NUCODEGEN_UART3_FUNCSEL_SINGLE_WIRE)

#if NUCODEGEN_UART3_WAKEUP_EN

#if (NUCODEGEN_UART3_DATA_WAKEUP_SEL == NUCODEGEN_UART3_INCOMING_DATA_WAKEUP)
    /* Select UART clock source as LXT */
    CLK_SetModuleClock(UART3_MODULE, CLK_CLKSEL3_UART3SEL_HIRC, CLK_CLKDIV4_UART3(1));
    /* Set UART baud rate and baud rate compensation */
    UART_Open(UART3, 9600);
    /* Set UART data wake-up start bit compensation value.
       It indicates how many clock cycle selected by UART_CLK does the UART controller can get the first bit (start bit)
       when the device is wake-up from power-down mode.
       If UART_CLK is selected as HIRC(48MHz) and the HIRC stable time is about 10.67us,
       the data wake-up start bit compensation value can be set as 520. */
    UART3->DWKCOMP = 520;

#elif(NUCODEGEN_UART3_DATA_WAKEUP_SEL == NUCODEGEN_UART3_FIFO_THRESHOLD_WAKEUP)
     /* Select UART clock source as LXT */
    CLK_SetModuleClock(UART3_MODULE, CLK_CLKSEL3_UART3SEL_LXT, CLK_CLKDIV4_UART3(1));
    /* Set UART baud rate and baud rate compensation */
    UART_Open(UART3, 9600);
    /* Compensation LXT cannot produce 9600 bps*/
    UART3->BRCOMP = 0xA5;
#else
    /* Configure UART3 and set UART3 baud rate */
    UART_Open(UART3, NUCODEGEN_UART3_SW_BAUD);
#endif

#else
    /* Configure UART3 and set UART3 baud rate */
    UART_Open(UART3, NUCODEGEN_UART3_SW_BAUD);
#endif

    /* Set Single Wire Mode */
    UART_SelectSingleWireMode(UART3);

#if NUCODEGEN_UART3_ABRD_EN
    /* Enable auto baud rate detect function */
    UART3->ALTCTL |= UART_ALTCTL_ABRDEN_Msk;
#endif
    /* RX FIFO Interrupt Trigger Level */
    UART3->FIFO = (UART3->FIFO &~ UART_FIFO_RFITL_Msk) | NUCODEGEN_UART3_RFITL;

#if(NUCODEGEN_UART3_DATA_WAKEUP_SEL == NUCODEGEN_UART3_INCOMING_DATA_WAKEUP)
    /* Enable UART Incoming Data Wake up */
    UART3->WKCTL |= UART_WKCTL_WKDATEN_Msk;
#endif

#if (NUCODEGEN_UART3_DATA_WAKEUP_SEL == NUCODEGEN_UART3_FIFO_THRESHOLD_WAKEUP)
    /* Enable UART Received Data FIFO Reached Threshold Wake up */
    UART3->WKCTL |= UART_WKCTL_WKRFRTEN_Msk;

#if NUCODEGEN_UART3_WKTOUT_EN
    /* Enable UART Received Data FIFO Threshold Time-out Wake up */
    UART3->WKCTL |= UART_WKCTL_WKTOUTEN_Msk;
#endif

#endif

#if (NUCODEGEN_UART3_TOCNT_EN || NUCODEGEN_UART3_WKTOUT_EN)
    /*Set the UART TimeOut count*/
    UART_SetTimeoutCnt(UART3, NUCODEGEN_UART3_TOCNT);
#endif

#if  NUCODEGEN_UART3_PDMA_EN
    /*Enable UART PDMA*/ 
    UART3->INTEN |=  NUCODEGEN_UART3_PDMAEN_MASK;
#endif

#if (NUCODEGEN_UART3_SW_INT_EN | NUCODEGEN_UART3_ABRDINT_EN || NUCODEGEN_UART3_WAKEUP_INT_EN)
    /*Enable the Single Wire Interrupt*/
    UART_EnableInt(UART3, (NUCODEGEN_UART3_SW_INT_CONFIG_MASK));
    /*Enable UART IRQ Handler */
    NVIC_EnableIRQ(UART3_IRQn);
#endif

#endif

}
#endif //NUCODEGEN_UART3