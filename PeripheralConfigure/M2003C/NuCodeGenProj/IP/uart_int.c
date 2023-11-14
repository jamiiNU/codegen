
#if NUCODEGEN_UART0

#if (NUCODEGEN_UART0_FUNCSEL == NUCODEGEN_UART0_FUNCSEL_UART ||  NUCODEGEN_UART0_FUNCSEL == NUCODEGEN_UART0_FUNCSEL_SINGLE_WIRE )
void UART0_IRQHandler(void)
{
 
#if (NUCODEGEN_UART0_INTEN || NUCODEGEN_UART0_SW_INTEN )   
    uint32_t u32IntSts = UART0->INTSTS;
    uint32_t u32WKSts  = UART0->WKSTS;
    volatile uint8_t u8InChar = 0xFF;
    uint32_t u32Data;
    
    /* Auto-baud Rate Interrupt */
    if (u32IntSts & UART_INTSTS_ABRINT_Msk)
    {   
        UART0->FIFOSTS = (UART_FIFOSTS_ABRDIF_Msk | UART_FIFOSTS_ABRDTOIF_Msk);
    }
#if (NUCODEGEN_UART0_FUNCSEL == NUCODEGEN_UART0_FUNCSEL_UART)       
     /* MODEM Status Interrupt */
    if(u32IntSts & UART_INTSTS_MODEMIF_Msk)
    { 
     /*Clear nCTS State Change Flag*/     
      UART_ClearIntFlag(UART0, UART_INTSTS_MODEMINT_Msk);
    }
#endif  
    /* Receive Line Status Interrupt */
    if (u32IntSts & UART_INTSTS_RLSIF_Msk)
    {
        if (UART0->FIFOSTS & UART_FIFOSTS_BIF_Msk)
            printf("\n BIF \n");

        if (UART0->FIFOSTS & UART_FIFOSTS_FEF_Msk)
            printf("\n FEF \n");

        if (UART0->FIFOSTS & UART_FIFOSTS_PEF_Msk)
            printf("\n PEF \n");

        u32Data = UART0->DAT; // read out data
        printf("\n Error Data is '0x%x' \n", u32Data);
        UART_ClearIntFlag(UART0, UART_INTSTS_RLSINT_Msk);
    }
  
    if ((u32IntSts & UART_INTSTS_RDAINT_Msk) || (u32IntSts & UART_INTSTS_RXTOINT_Msk))/* Rx Ready or Time-out INT*/
    {
        /* Get all the input characters */
        while (!UART_GET_RX_EMPTY(UART0))
        {
            /* Get the character from UART Buffer */
            u8InChar = UART_READ(UART0);
            /* ToDo : User handle read data here */
            printf("0x%x\n",u8InChar);
        }
    }
 
    /* Buffer Error Interrupt  */
    if (u32IntSts & UART_INTSTS_BUFERRINT_Msk)     /* Buffer Error INT */
    {
        printf("\nBuffer Error...\n");
        UART_ClearIntFlag(UART0, UART_INTSTS_BUFERRINT_Msk);
    }
#if (NUCODEGEN_UART0_FUNCSEL == NUCODEGEN_UART0_FUNCSEL_SINGLE_WIRE)    
    if (u32IntSts & UART_INTSTS_SWBEINT_Msk)
    {
        printf("Single-wire Bit Error Detection \n");
        UART_ClearIntFlag(UART0, UART_INTSTS_SWBEINT_Msk);
    }
#endif  

    /* If you would like to use  "Transmit Holding Register Empty Interrupt  or  Transmitter Empty Interrupt ",you can add this code. */
//    if ((u32IntSts & UART_INTSTS_THREINT_Msk) || (u32IntSts & UART_INTSTS_TXENDIF_Msk) )
//    {
//      while (UART_IS_TX_FULL(UART0)){} /* Wait Tx is not full to transmit data */
//      UART_WRITE(UART0, u8InChar);
//    }

    /* UART Wake-up Interrupt  */
    if (u32IntSts & UART_INTSTS_WKIF_Msk)
    {
        printf("\n UART Wake-Up ");
        UART0->INTSTS = UART_INTSTS_WKIF_Msk;
        UART_ClearIntFlag(UART0,UART_INTSTS_WKINT_Msk);
    }
#endif //(NUCODEGEN_UART0_INTEN || NUCODEGEN_UART0_SW_INTEN)    
}

    
#elif (NUCODEGEN_UART0_FUNCSEL == NUCODEGEN_UART0_FUNCSEL_IrDA)
    
void UART0_IRQHandler(void)
{
#if NUCODEGEN_UART0_IRDA_INTEN   
  uint32_t u32IntSts = UART0->INTSTS;
  uint8_t u8InChar = 0xFF;

  /* Rx Ready or Time-out INT*/
  if ((u32IntSts & UART_INTSTS_RDAINT_Msk) || (u32IntSts & UART_INTSTS_RXTOINT_Msk))
   {


        /* Get all the input characters */
        while (!UART_GET_RX_EMPTY(UART0))
        {
            /* Get the character from UART Buffer */
            u8InChar = UART_READ(UART0);
            /* ToDo : User handle read data here */
            printf("0x%x\n",u8InChar);
        }
   }
   
 /* If you would like to use  "Transmit Holding Register Empty Interrupt  or  Transmitter Empty Interrupt ",you can add this code. */
//   if ((u32IntSts & UART_INTSTS_THREINT_Msk) || (u32IntSts & UART_INTSTS_TXENDIF_Msk) )
//   {
//      while (UART_IS_TX_FULL(UART0)){} /* Wait Tx is not full to transmit data */
//      UART_WRITE(UART0, u8InChar);
//   }

#endif //NUCODEGEN_UART0_IRDA_INTEN   
}


#elif (NUCODEGEN_UART0_FUNCSEL == NUCODEGEN_UART0_FUNCSEL_RS485)


void UART0_IRQHandler(void)
{
#if NUCODEGEN_UART0_RS485_INTEN 
    volatile uint32_t u32Addr = 0;
    uint32_t u32IntSts = UART0->INTSTS;
    uint32_t u32WKSts  = UART0->WKSTS;
    volatile uint8_t u8InChar = 0xFF;

  
  /* RLS INT & RDA INT */ 
    if ((u32IntSts & UART_INTSTS_RLSINT_Msk) && (u32IntSts & UART_INTSTS_RDAINT_Msk))//For RS485 Detect Address
    {
        if (UART0->FIFOSTS & UART_FIFOSTS_ADDRDETF_Msk)   /* ADD_IF, RS485 mode */
        {
            u32Addr = UART0->DAT;
            UART_RS485_CLEAR_ADDR_FLAG(UART0);        /* clear ADD_IF flag */
            printf("\nAddr=0x%x,Get:", u32Addr);

#if (NUCODEGEN_UART0_RS485_MODE == NUCODEGEN_UART0_RS485_NMM_MODE) //RS485_NMM
            /* if address match, enable RX to receive data, otherwise to disable RX. */
            /* In NMM mode,user can decide multi-address filter. In AAD mode,only one address can set */
            if ((u32Addr == UART0_MATCH_ADDRSS1) || (u32Addr == UART0_MATCH_ADDRSS2))
            {
                UART0->FIFO &= ~ UART_FIFO_RXOFF_Msk;  /* Enable RS485 RX */
            }
            else
            {
                UART0->FIFO |= UART_FIFO_RXOFF_Msk;      /* Disable RS485 RX */
                UART0->FIFO |= UART_FIFO_RXRST_Msk;      /* Clear data from RX FIFO */
                printf("\n");
            }
#endif
        }
    }
    else if ((u32IntSts & UART_INTSTS_RDAINT_Msk) || (u32IntSts & UART_INTSTS_RXTOINT_Msk))/* Rx Ready or Time-out INT*/
    {
         /* Handle received data */
        while (!UART_GET_RX_EMPTY(UART0))
        {
            /* Get the character from UART Buffer */
            u8InChar = UART_READ(UART0);
            /* ToDo : User handle read data here */
            printf("0x%x\n",u8InChar);
        }
        
    }
    else if (u32IntSts & UART_INTSTS_BUFERRINT_Msk)     /* Buffer Error INT */
    {
        printf("\nBuffer Error...\n");
        UART_ClearIntFlag(UART0, UART_INTSTS_BUFERRINT_Msk);
    }
 
     /* If you would like to use  "Transmit Holding Register Empty Interrupt  or  Transmitter Empty Interrupt ",you can add this code. */
//   if ((u32IntSts & UART_INTSTS_THREINT_Msk) || (u32IntSts & UART_INTSTS_TXENDIF_Msk) )
//   {
//      while (UART_IS_TX_FULL(UART0)){} /* Wait Tx is not full to transmit data */
//      UART_WRITE(UART0, u8InChar);
//   }

 #endif //NUCODEGEN_UART0_RS485_INTEN
}

#endif //(NUCODEGEN_UART0_FUNCSEL_UART || NUCODEGEN_UART0_FUNCSEL_SINGLE_WIRE)

#endif  //NUCODEGEN_UART0


#if NUCODEGEN_UART1

#if (NUCODEGEN_UART1_FUNCSEL == NUCODEGEN_UART1_FUNCSEL_UART ||  NUCODEGEN_UART1_FUNCSEL == NUCODEGEN_UART1_FUNCSEL_SINGLE_WIRE )
void UART1_IRQHandler(void)
{
 
#if (NUCODEGEN_UART1_INTEN || NUCODEGEN_UART1_SW_INTEN )   
    uint32_t u32IntSts = UART1->INTSTS;
    uint32_t u32WKSts  = UART1->WKSTS;
    volatile uint8_t u8InChar = 0xFF;
    uint32_t u32Data;
    
    /* Auto-baud Rate Interrupt */
    if (u32IntSts & UART_INTSTS_ABRINT_Msk)
    {   
        UART1->FIFOSTS = (UART_FIFOSTS_ABRDIF_Msk | UART_FIFOSTS_ABRDTOIF_Msk);
    }
#if (NUCODEGEN_UART1_FUNCSEL == NUCODEGEN_UART1_FUNCSEL_UART)       
     /* MODEM Status Interrupt */
    if(u32IntSts & UART_INTSTS_MODEMIF_Msk)
    { 
     /*Clear nCTS State Change Flag*/     
      UART_ClearIntFlag(UART1, UART_INTSTS_MODEMINT_Msk);
    }
#endif  
    /* Receive Line Status Interrupt */
    if (u32IntSts & UART_INTSTS_RLSIF_Msk)
    {
        if (UART1->FIFOSTS & UART_FIFOSTS_BIF_Msk)
            printf("\n BIF \n");

        if (UART1->FIFOSTS & UART_FIFOSTS_FEF_Msk)
            printf("\n FEF \n");

        if (UART1->FIFOSTS & UART_FIFOSTS_PEF_Msk)
            printf("\n PEF \n");

        u32Data = UART1->DAT; // read out data
        printf("\n Error Data is '0x%x' \n", u32Data);
        UART_ClearIntFlag(UART1, UART_INTSTS_RLSINT_Msk);
    }
  
    if ((u32IntSts & UART_INTSTS_RDAINT_Msk) || (u32IntSts & UART_INTSTS_RXTOINT_Msk))/* Rx Ready or Time-out INT*/
    {
        /* Get all the input characters */
        while (!UART_GET_RX_EMPTY(UART1))
        {
            /* Get the character from UART Buffer */
            u8InChar = UART_READ(UART1);
            /* ToDo : User handle read data here */
            printf("0x%x\n",u8InChar);
        }
    }
 
    /* Buffer Error Interrupt  */
    if (u32IntSts & UART_INTSTS_BUFERRINT_Msk)     /* Buffer Error INT */
    {
        printf("\nBuffer Error...\n");
        UART_ClearIntFlag(UART1, UART_INTSTS_BUFERRINT_Msk);
    }
#if (NUCODEGEN_UART1_FUNCSEL == NUCODEGEN_UART1_FUNCSEL_SINGLE_WIRE)    
    if (u32IntSts & UART_INTSTS_SWBEINT_Msk)
    {
        printf("Single-wire Bit Error Detection \n");
        UART_ClearIntFlag(UART1, UART_INTSTS_SWBEINT_Msk);
    }
#endif  

    /* If you would like to use  "Transmit Holding Register Empty Interrupt  or  Transmitter Empty Interrupt ",you can add this code. */
//    if ((u32IntSts & UART_INTSTS_THREINT_Msk) || (u32IntSts & UART_INTSTS_TXENDIF_Msk) )
//    {
//      while (UART_IS_TX_FULL(UART1)){} /* Wait Tx is not full to transmit data */
//      UART_WRITE(UART1, u8InChar);
//    }

    /* UART Wake-up Interrupt  */
    if (u32IntSts & UART_INTSTS_WKIF_Msk)
    {
        printf("\n UART Wake-Up ");
        UART1->INTSTS = UART_INTSTS_WKIF_Msk;
        UART_ClearIntFlag(UART1,UART_INTSTS_WKINT_Msk);
    }
#endif //(NUCODEGEN_UART1_INTEN || NUCODEGEN_UART1_SW_INTEN)    
}

    
#elif (NUCODEGEN_UART1_FUNCSEL == NUCODEGEN_UART1_FUNCSEL_IrDA)
    
void UART1_IRQHandler(void)
{
#if NUCODEGEN_UART1_IRDA_INTEN   
  uint32_t u32IntSts = UART1->INTSTS;
  uint8_t u8InChar = 0xFF;

  /* Rx Ready or Time-out INT*/
  if ((u32IntSts & UART_INTSTS_RDAINT_Msk) || (u32IntSts & UART_INTSTS_RXTOINT_Msk))
   {
        /* Get all the input characters */
        while (!UART_GET_RX_EMPTY(UART1))
        {
            /* Get the character from UART Buffer */
            u8InChar = UART_READ(UART1);
            /* ToDo : User handle read data here */
            printf("0x%x\n",u8InChar);
        }
   }
   
 /* If you would like to use  "Transmit Holding Register Empty Interrupt  or  Transmitter Empty Interrupt ",you can add this code. */
//   if ((u32IntSts & UART_INTSTS_THREINT_Msk) || (u32IntSts & UART_INTSTS_TXENDIF_Msk) )
//   {
//      while (UART_IS_TX_FULL(UART1)){} /* Wait Tx is not full to transmit data */
//      UART_WRITE(UART1, u8InChar);
//   }

#endif //NUCODEGEN_UART1_IRDA_INTEN   
}


#elif (NUCODEGEN_UART1_FUNCSEL == NUCODEGEN_UART1_FUNCSEL_RS485)


void UART1_IRQHandler(void)
{
#if NUCODEGEN_UART1_RS485_INTEN 
    volatile uint32_t u32Addr = 0;
    uint32_t u32IntSts = UART1->INTSTS;
    uint32_t u32WKSts  = UART1->WKSTS;
    volatile uint8_t u8InChar = 0xFF;

  
  /* RLS INT & RDA INT */ 
    if ((u32IntSts & UART_INTSTS_RLSINT_Msk) && (u32IntSts & UART_INTSTS_RDAINT_Msk))//For RS485 Detect Address
    {
        if (UART1->FIFOSTS & UART_FIFOSTS_ADDRDETF_Msk)   /* ADD_IF, RS485 mode */
        {
            u32Addr = UART1->DAT;
            UART_RS485_CLEAR_ADDR_FLAG(UART1);        /* clear ADD_IF flag */
            printf("\nAddr=0x%x,Get:", u32Addr);

#if (NUCODEGEN_UART1_RS485_MODE == NUCODEGEN_UART1_RS485_NMM_MODE) //RS485_NMM
            /* if address match, enable RX to receive data, otherwise to disable RX. */
            /* In NMM mode,user can decide multi-address filter. In AAD mode,only one address can set */
            if ((u32Addr == UART1_MATCH_ADDRSS1) || (u32Addr == UART1_MATCH_ADDRSS2))
            {
                UART1->FIFO &= ~ UART_FIFO_RXOFF_Msk;  /* Enable RS485 RX */
            }
            else
            {
                UART1->FIFO |= UART_FIFO_RXOFF_Msk;      /* Disable RS485 RX */
                UART1->FIFO |= UART_FIFO_RXRST_Msk;      /* Clear data from RX FIFO */
                printf("\n");
            }
#endif
        }
    }
    else if ((u32IntSts & UART_INTSTS_RDAINT_Msk) || (u32IntSts & UART_INTSTS_RXTOINT_Msk))/* Rx Ready or Time-out INT*/
    {
         /* Handle received data */
        while (!UART_GET_RX_EMPTY(UART1))
        {
            /* Get the character from UART Buffer */
            u8InChar = UART_READ(UART1);
            /* ToDo : User handle read data here */
            printf("0x%x\n",u8InChar);
        }
        
    }
    else if (u32IntSts & UART_INTSTS_BUFERRINT_Msk)     /* Buffer Error INT */
    {
        printf("\nBuffer Error...\n");
        UART_ClearIntFlag(UART1, UART_INTSTS_BUFERRINT_Msk);
    }
 
     /* If you would like to use  "Transmit Holding Register Empty Interrupt  or  Transmitter Empty Interrupt ",you can add this code. */
//   if ((u32IntSts & UART_INTSTS_THREINT_Msk) || (u32IntSts & UART_INTSTS_TXENDIF_Msk) )
//   {
//      while (UART_IS_TX_FULL(UART1)){} /* Wait Tx is not full to transmit data */
//      UART_WRITE(UART1, u8InChar);
//   }

 #endif //NUCODEGEN_UART1_RS485_INTEN
}

#endif //(NUCODEGEN_UART1_FUNCSEL_UART || NUCODEGEN_UART1_FUNCSEL_SINGLE_WIRE)



#endif //NUCODEGEN_UART1





