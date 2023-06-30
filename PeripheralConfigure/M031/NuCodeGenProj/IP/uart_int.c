
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


#if NUCODEGEN_UART2

#if (NUCODEGEN_UART2_FUNCSEL == NUCODEGEN_UART2_FUNCSEL_UART ||  NUCODEGEN_UART2_FUNCSEL == NUCODEGEN_UART2_FUNCSEL_SINGLE_WIRE )
void UART2_IRQHandler(void)
{
 
#if (NUCODEGEN_UART2_INTEN || NUCODEGEN_UART2_SW_INTEN )   
    uint32_t u32IntSts = UART2->INTSTS;
    uint32_t u32WKSts  = UART2->WKSTS;
    volatile uint8_t u8InChar = 0xFF;
    uint32_t u32Data;
    
    /* Auto-baud Rate Interrupt */
    if (u32IntSts & UART_INTSTS_ABRINT_Msk)
    {   
        UART2->FIFOSTS = (UART_FIFOSTS_ABRDIF_Msk | UART_FIFOSTS_ABRDTOIF_Msk);
    }
#if (NUCODEGEN_UART2_FUNCSEL == NUCODEGEN_UART2_FUNCSEL_UART)       
     /* MODEM Status Interrupt */
    if(u32IntSts & UART_INTSTS_MODEMIF_Msk)
    { 
     /*Clear nCTS State Change Flag*/     
      UART_ClearIntFlag(UART2, UART_INTSTS_MODEMINT_Msk);
    }
#endif  
    /* Receive Line Status Interrupt */
    if (u32IntSts & UART_INTSTS_RLSIF_Msk)
    {
        if (UART2->FIFOSTS & UART_FIFOSTS_BIF_Msk)
            printf("\n BIF \n");

        if (UART2->FIFOSTS & UART_FIFOSTS_FEF_Msk)
            printf("\n FEF \n");

        if (UART2->FIFOSTS & UART_FIFOSTS_PEF_Msk)
            printf("\n PEF \n");

        u32Data = UART2->DAT; // read out data
        printf("\n Error Data is '0x%x' \n", u32Data);
        UART_ClearIntFlag(UART2, UART_INTSTS_RLSINT_Msk);
    }
  
    if ((u32IntSts & UART_INTSTS_RDAINT_Msk) || (u32IntSts & UART_INTSTS_RXTOINT_Msk))/* Rx Ready or Time-out INT*/
    {
        /* Get all the input characters */
        while (!UART_GET_RX_EMPTY(UART2))
        {
            /* Get the character from UART Buffer */
            u8InChar = UART_READ(UART2);
            /* ToDo : User handle read data here */
            printf("0x%x\n",u8InChar);
        }

    }
 
    /* Buffer Error Interrupt  */
    if (u32IntSts & UART_INTSTS_BUFERRINT_Msk)     /* Buffer Error INT */
    {
        printf("\nBuffer Error...\n");
        UART_ClearIntFlag(UART2, UART_INTSTS_BUFERRINT_Msk);
    }
#if (NUCODEGEN_UART2_FUNCSEL == NUCODEGEN_UART2_FUNCSEL_SINGLE_WIRE)    
    if (u32IntSts & UART_INTSTS_SWBEINT_Msk)
    {
        printf("Single-wire Bit Error Detection \n");
        UART_ClearIntFlag(UART2, UART_INTSTS_SWBEINT_Msk);
    }
#endif  

    /* If you would like to use  "Transmit Holding Register Empty Interrupt  or  Transmitter Empty Interrupt ",you can add this code. */
//    if ((u32IntSts & UART_INTSTS_THREINT_Msk) || (u32IntSts & UART_INTSTS_TXENDIF_Msk) )
//    {
//      while (UART_IS_TX_FULL(UART2)){} /* Wait Tx is not full to transmit data */
//      UART_WRITE(UART2, u8InChar);
//    }

    /* UART Wake-up Interrupt  */
    if (u32IntSts & UART_INTSTS_WKIF_Msk)
    {
        printf("\n UART Wake-Up ");
        UART2->INTSTS = UART_INTSTS_WKIF_Msk;
        UART_ClearIntFlag(UART2,UART_INTSTS_WKINT_Msk);
    }
#endif //(NUCODEGEN_UART2_INTEN || NUCODEGEN_UART2_SW_INTEN)    
}

    
#elif (NUCODEGEN_UART2_FUNCSEL == NUCODEGEN_UART2_FUNCSEL_IrDA)
    
void UART2_IRQHandler(void)
{
#if NUCODEGEN_UART2_IRDA_INTEN   
  uint32_t u32IntSts = UART2->INTSTS;
  uint8_t u8InChar = 0xFF;

  /* Rx Ready or Time-out INT*/
  if ((u32IntSts & UART_INTSTS_RDAINT_Msk) || (u32IntSts & UART_INTSTS_RXTOINT_Msk))
   {


        /* Get all the input characters */
        while (!UART_GET_RX_EMPTY(UART2))
        {
            /* Get the character from UART Buffer */
            u8InChar = UART_READ(UART2);
            /* ToDo : User handle read data here */
            printf("0x%x\n",u8InChar);
        }
   }
   
 /* If you would like to use  "Transmit Holding Register Empty Interrupt  or  Transmitter Empty Interrupt ",you can add this code. */
//   if ((u32IntSts & UART_INTSTS_THREINT_Msk) || (u32IntSts & UART_INTSTS_TXENDIF_Msk) )
//   {
//      while (UART_IS_TX_FULL(UART2)){} /* Wait Tx is not full to transmit data */
//      UART_WRITE(UART2, u8InChar);
//   }

#endif //NUCODEGEN_UART2_IRDA_INTEN   
}


#elif (NUCODEGEN_UART2_FUNCSEL == NUCODEGEN_UART2_FUNCSEL_RS485)


void UART2_IRQHandler(void)
{
#if NUCODEGEN_UART2_RS485_INTEN 
    volatile uint32_t u32Addr = 0;
    uint32_t u32IntSts = UART2->INTSTS;
    uint32_t u32WKSts  = UART2->WKSTS;
    volatile uint8_t u8InChar = 0xFF;

  
  /* RLS INT & RDA INT */ 
    if ((u32IntSts & UART_INTSTS_RLSINT_Msk) && (u32IntSts & UART_INTSTS_RDAINT_Msk))//For RS485 Detect Address
    {
        if (UART2->FIFOSTS & UART_FIFOSTS_ADDRDETF_Msk)   /* ADD_IF, RS485 mode */
        {
            u32Addr = UART2->DAT;
            UART_RS485_CLEAR_ADDR_FLAG(UART2);        /* clear ADD_IF flag */
            printf("\nAddr=0x%x,Get:", u32Addr);

#if (NUCODEGEN_UART2_RS485_MODE == NUCODEGEN_UART2_RS485_NMM_MODE) //RS485_NMM
            /* if address match, enable RX to receive data, otherwise to disable RX. */
            /* In NMM mode,user can decide multi-address filter. In AAD mode,only one address can set */
            if ((u32Addr == UART2_MATCH_ADDRSS1) || (u32Addr == UART2_MATCH_ADDRSS2))
            {
                UART2->FIFO &= ~ UART_FIFO_RXOFF_Msk;  /* Enable RS485 RX */
            }
            else
            {
                UART2->FIFO |= UART_FIFO_RXOFF_Msk;      /* Disable RS485 RX */
                UART2->FIFO |= UART_FIFO_RXRST_Msk;      /* Clear data from RX FIFO */
                printf("\n");
            }
#endif
        }
    }
    else if ((u32IntSts & UART_INTSTS_RDAINT_Msk) || (u32IntSts & UART_INTSTS_RXTOINT_Msk))/* Rx Ready or Time-out INT*/
    {
         /* Handle received data */
        while (!UART_GET_RX_EMPTY(UART2))
        {
            /* Get the character from UART Buffer */
            u8InChar = UART_READ(UART2);
            /* ToDo : User handle read data here */
            printf("0x%x\n",u8InChar);
        }
        
    }
    else if (u32IntSts & UART_INTSTS_BUFERRINT_Msk)     /* Buffer Error INT */
    {
        printf("\nBuffer Error...\n");
        UART_ClearIntFlag(UART2, UART_INTSTS_BUFERRINT_Msk);
    }
 
     /* If you would like to use  "Transmit Holding Register Empty Interrupt  or  Transmitter Empty Interrupt ",you can add this code. */
//   if ((u32IntSts & UART_INTSTS_THREINT_Msk) || (u32IntSts & UART_INTSTS_TXENDIF_Msk) )
//   {
//      while (UART_IS_TX_FULL(UART2)){} /* Wait Tx is not full to transmit data */
//      UART_WRITE(UART2, u8InChar);
//   }

 #endif //NUCODEGEN_UART2_RS485_INTEN
}

#endif //(NUCODEGEN_UART2_FUNCSEL_UART || NUCODEGEN_UART2_FUNCSEL_SINGLE_WIRE)

#endif //NUCODEGEN_UART2

#if (NUCODEGEN_UART0 || NUCODEGEN_UART2)
    
void UART02_IRQHandler(void)
{
#if NUCODEGEN_UART0
    UART0_IRQHandler();
#endif //NUCODEGEN_UART0
#if NUCODEGEN_UART2
    UART2_IRQHandler();
#endif //NUCODEGEN_UART2
}

#endif //(NUCODEGEN_UART0 || NUCODEGEN_UART2)




#if NUCODEGEN_UART3

#if (NUCODEGEN_UART3_FUNCSEL == NUCODEGEN_UART3_FUNCSEL_UART ||  NUCODEGEN_UART3_FUNCSEL == NUCODEGEN_UART3_FUNCSEL_SINGLE_WIRE )
void UART3_IRQHandler(void)
{
 
#if (NUCODEGEN_UART3_INTEN || NUCODEGEN_UART3_SW_INTEN )   
    uint32_t u32IntSts = UART3->INTSTS;
    uint32_t u32WKSts  = UART3->WKSTS;
    volatile uint8_t u8InChar = 0xFF;
    uint32_t u32Data;
    
    /* Auto-baud Rate Interrupt */
    if (u32IntSts & UART_INTSTS_ABRINT_Msk)
    {   
        UART3->FIFOSTS = (UART_FIFOSTS_ABRDIF_Msk | UART_FIFOSTS_ABRDTOIF_Msk);
    }
#if (NUCODEGEN_UART3_FUNCSEL == NUCODEGEN_UART3_FUNCSEL_UART)       
     /* MODEM Status Interrupt */
    if(u32IntSts & UART_INTSTS_MODEMIF_Msk)
    { 
     /*Clear nCTS State Change Flag*/     
      UART_ClearIntFlag(UART3, UART_INTSTS_MODEMINT_Msk);
    }
#endif  
    /* Receive Line Status Interrupt */
    if (u32IntSts & UART_INTSTS_RLSIF_Msk)
    {
        if (UART3->FIFOSTS & UART_FIFOSTS_BIF_Msk)
            printf("\n BIF \n");

        if (UART3->FIFOSTS & UART_FIFOSTS_FEF_Msk)
            printf("\n FEF \n");

        if (UART3->FIFOSTS & UART_FIFOSTS_PEF_Msk)
            printf("\n PEF \n");

        u32Data = UART3->DAT; // read out data
        printf("\n Error Data is '0x%x' \n", u32Data);
        UART_ClearIntFlag(UART3, UART_INTSTS_RLSINT_Msk);
    }
  
    if ((u32IntSts & UART_INTSTS_RDAINT_Msk) || (u32IntSts & UART_INTSTS_RXTOINT_Msk))/* Rx Ready or Time-out INT*/
    {
        /* Get all the input characters */
        while (!UART_GET_RX_EMPTY(UART3))
        {
            /* Get the character from UART Buffer */
            u8InChar = UART_READ(UART3);
            /* ToDo : User handle read data here */
            printf("0x%x\n",u8InChar);
        }

    }
 
    /* Buffer Error Interrupt  */
    if (u32IntSts & UART_INTSTS_BUFERRINT_Msk)     /* Buffer Error INT */
    {
        printf("\nBuffer Error...\n");
        UART_ClearIntFlag(UART3, UART_INTSTS_BUFERRINT_Msk);
    }
#if (NUCODEGEN_UART3_FUNCSEL == NUCODEGEN_UART3_FUNCSEL_SINGLE_WIRE)    
    if (u32IntSts & UART_INTSTS_SWBEINT_Msk)
    {
        printf("Single-wire Bit Error Detection \n");
        UART_ClearIntFlag(UART3, UART_INTSTS_SWBEINT_Msk);
    }
#endif  

    /* If you would like to use  "Transmit Holding Register Empty Interrupt  or  Transmitter Empty Interrupt ",you can add this code. */
//    if ((u32IntSts & UART_INTSTS_THREINT_Msk) || (u32IntSts & UART_INTSTS_TXENDIF_Msk) )
//    {
//      while (UART_IS_TX_FULL(UART3)){} /* Wait Tx is not full to transmit data */
//      UART_WRITE(UART3, u8InChar);
//    }

    /* UART Wake-up Interrupt  */
    if (u32IntSts & UART_INTSTS_WKIF_Msk)
    {
        printf("\n UART Wake-Up ");
        UART3->INTSTS = UART_INTSTS_WKIF_Msk;
        UART_ClearIntFlag(UART3,UART_INTSTS_WKINT_Msk);
    }
#endif //(NUCODEGEN_UART3_INTEN || NUCODEGEN_UART3_SW_INTEN)    
}

    
#elif (NUCODEGEN_UART3_FUNCSEL == NUCODEGEN_UART3_FUNCSEL_IrDA)
    
void UART3_IRQHandler(void)
{
#if NUCODEGEN_UART3_IRDA_INTEN   
  uint32_t u32IntSts = UART3->INTSTS;
  uint8_t u8InChar = 0xFF;

  /* Rx Ready or Time-out INT*/
  if ((u32IntSts & UART_INTSTS_RDAINT_Msk) || (u32IntSts & UART_INTSTS_RXTOINT_Msk))
   {


        /* Get all the input characters */
        while (!UART_GET_RX_EMPTY(UART3))
        {
            /* Get the character from UART Buffer */
            u8InChar = UART_READ(UART3);
            /* ToDo : User handle read data here */
            printf("0x%x\n",u8InChar);
        }
   }
   
 /* If you would like to use  "Transmit Holding Register Empty Interrupt  or  Transmitter Empty Interrupt ",you can add this code. */
//   if ((u32IntSts & UART_INTSTS_THREINT_Msk) || (u32IntSts & UART_INTSTS_TXENDIF_Msk) )
//   {
//      while (UART_IS_TX_FULL(UART3)){} /* Wait Tx is not full to transmit data */
//      UART_WRITE(UART3, u8InChar);
//   }

#endif //NUCODEGEN_UART3_IRDA_INTEN   
}


#elif (NUCODEGEN_UART3_FUNCSEL == NUCODEGEN_UART3_FUNCSEL_RS485)


void UART3_IRQHandler(void)
{
#if NUCODEGEN_UART3_RS485_INTEN 
    volatile uint32_t u32Addr = 0;
    uint32_t u32IntSts = UART3->INTSTS;
    uint32_t u32WKSts  = UART3->WKSTS;
    volatile uint8_t u8InChar = 0xFF;

  
  /* RLS INT & RDA INT */ 
    if ((u32IntSts & UART_INTSTS_RLSINT_Msk) && (u32IntSts & UART_INTSTS_RDAINT_Msk))//For RS485 Detect Address
    {
        if (UART3->FIFOSTS & UART_FIFOSTS_ADDRDETF_Msk)   /* ADD_IF, RS485 mode */
        {
            u32Addr = UART3->DAT;
            UART_RS485_CLEAR_ADDR_FLAG(UART3);        /* clear ADD_IF flag */
            printf("\nAddr=0x%x,Get:", u32Addr);

#if (NUCODEGEN_UART3_RS485_MODE == NUCODEGEN_UART3_RS485_NMM_MODE) //RS485_NMM
            /* if address match, enable RX to receive data, otherwise to disable RX. */
            /* In NMM mode,user can decide multi-address filter. In AAD mode,only one address can set */
            if ((u32Addr == UART3_MATCH_ADDRSS1) || (u32Addr == UART3_MATCH_ADDRSS2))
            {
                UART3->FIFO &= ~ UART_FIFO_RXOFF_Msk;  /* Enable RS485 RX */
            }
            else
            {
                UART3->FIFO |= UART_FIFO_RXOFF_Msk;      /* Disable RS485 RX */
                UART3->FIFO |= UART_FIFO_RXRST_Msk;      /* Clear data from RX FIFO */
                printf("\n");
            }
#endif
        }
    }
    else if ((u32IntSts & UART_INTSTS_RDAINT_Msk) || (u32IntSts & UART_INTSTS_RXTOINT_Msk))/* Rx Ready or Time-out INT*/
    {
         /* Handle received data */
        while (!UART_GET_RX_EMPTY(UART3))
        {
            /* Get the character from UART Buffer */
            u8InChar = UART_READ(UART3);
            /* ToDo : User handle read data here */
            printf("0x%x\n",u8InChar);
        }
        
    }
    else if (u32IntSts & UART_INTSTS_BUFERRINT_Msk)     /* Buffer Error INT */
    {
        printf("\nBuffer Error...\n");
        UART_ClearIntFlag(UART3, UART_INTSTS_BUFERRINT_Msk);
    }
 
     /* If you would like to use  "Transmit Holding Register Empty Interrupt  or  Transmitter Empty Interrupt ",you can add this code. */
//   if ((u32IntSts & UART_INTSTS_THREINT_Msk) || (u32IntSts & UART_INTSTS_TXENDIF_Msk) )
//   {
//      while (UART_IS_TX_FULL(UART3)){} /* Wait Tx is not full to transmit data */
//      UART_WRITE(UART3, u8InChar);
//   }

 #endif //NUCODEGEN_UART3_RS485_INTEN
}

#endif //(NUCODEGEN_UART3_FUNCSEL_UART || NUCODEGEN_UART3_FUNCSEL_SINGLE_WIRE)

#endif //NUCODEGEN_UART3

#if (NUCODEGEN_UART1 || NUCODEGEN_UART3)
    
void UART13_IRQHandler(void)
{
#if NUCODEGEN_UART1
    UART1_IRQHandler();
#endif //NUCODEGEN_UART1
#if NUCODEGEN_UART3
    UART3_IRQHandler();
#endif //NUCODEGEN_UART3
}

#endif //(NUCODEGEN_UART1 || NUCODEGEN_UART3)


#if NUCODEGEN_UART4

#if (NUCODEGEN_UART4_FUNCSEL == NUCODEGEN_UART4_FUNCSEL_UART ||  NUCODEGEN_UART4_FUNCSEL == NUCODEGEN_UART4_FUNCSEL_SINGLE_WIRE )
void UART4_IRQHandler(void)
{
 
#if (NUCODEGEN_UART4_INTEN || NUCODEGEN_UART4_SW_INTEN )   
    uint32_t u32IntSts = UART4->INTSTS;
    uint32_t u32WKSts  = UART4->WKSTS;
    volatile uint8_t u8InChar = 0xFF;
    uint32_t u32Data;
    
    /* Auto-baud Rate Interrupt */
    if (u32IntSts & UART_INTSTS_ABRINT_Msk)
    {   
        UART4->FIFOSTS = (UART_FIFOSTS_ABRDIF_Msk | UART_FIFOSTS_ABRDTOIF_Msk);
    }
#if (NUCODEGEN_UART4_FUNCSEL == NUCODEGEN_UART4_FUNCSEL_UART)       
     /* MODEM Status Interrupt */
    if(u32IntSts & UART_INTSTS_MODEMIF_Msk)
    { 
     /*Clear nCTS State Change Flag*/     
      UART_ClearIntFlag(UART4, UART_INTSTS_MODEMINT_Msk);
    }
#endif  
    /* Receive Line Status Interrupt */
    if (u32IntSts & UART_INTSTS_RLSIF_Msk)
    {
        if (UART4->FIFOSTS & UART_FIFOSTS_BIF_Msk)
            printf("\n BIF \n");

        if (UART4->FIFOSTS & UART_FIFOSTS_FEF_Msk)
            printf("\n FEF \n");

        if (UART4->FIFOSTS & UART_FIFOSTS_PEF_Msk)
            printf("\n PEF \n");

        u32Data = UART4->DAT; // read out data
        printf("\n Error Data is '0x%x' \n", u32Data);
        UART_ClearIntFlag(UART4, UART_INTSTS_RLSINT_Msk);
    }
  
    if ((u32IntSts & UART_INTSTS_RDAINT_Msk) || (u32IntSts & UART_INTSTS_RXTOINT_Msk))/* Rx Ready or Time-out INT*/
    {
        /* Get all the input characters */
        while (!UART_GET_RX_EMPTY(UART4))
        {
            /* Get the character from UART Buffer */
            u8InChar = UART_READ(UART4);
            /* ToDo : User handle read data here */
            printf("0x%x\n",u8InChar);
        }

    }
 
    /* Buffer Error Interrupt  */
    if (u32IntSts & UART_INTSTS_BUFERRINT_Msk)     /* Buffer Error INT */
    {
        printf("\nBuffer Error...\n");
        UART_ClearIntFlag(UART4, UART_INTSTS_BUFERRINT_Msk);
    }
#if (NUCODEGEN_UART4_FUNCSEL == NUCODEGEN_UART4_FUNCSEL_SINGLE_WIRE)    
    if (u32IntSts & UART_INTSTS_SWBEINT_Msk)
    {
        printf("Single-wire Bit Error Detection \n");
        UART_ClearIntFlag(UART4, UART_INTSTS_SWBEINT_Msk);
    }
#endif  

    /* If you would like to use  "Transmit Holding Register Empty Interrupt  or  Transmitter Empty Interrupt ",you can add this code. */
//    if ((u32IntSts & UART_INTSTS_THREINT_Msk) || (u32IntSts & UART_INTSTS_TXENDIF_Msk) )
//    {
//      while (UART_IS_TX_FULL(UART4)){} /* Wait Tx is not full to transmit data */
//      UART_WRITE(UART4, u8InChar);
//    }

    /* UART Wake-up Interrupt  */
    if (u32IntSts & UART_INTSTS_WKIF_Msk)
    {
        printf("\n UART Wake-Up ");
        UART4->INTSTS = UART_INTSTS_WKIF_Msk;
        UART_ClearIntFlag(UART4,UART_INTSTS_WKINT_Msk);
    }
#endif //(NUCODEGEN_UART4_INTEN || NUCODEGEN_UART4_SW_INTEN)    
}

    
#elif (NUCODEGEN_UART4_FUNCSEL == NUCODEGEN_UART4_FUNCSEL_IrDA)
    
void UART4_IRQHandler(void)
{
#if NUCODEGEN_UART4_IRDA_INTEN   
  uint32_t u32IntSts = UART4->INTSTS;
  uint8_t u8InChar = 0xFF;

  /* Rx Ready or Time-out INT*/
  if ((u32IntSts & UART_INTSTS_RDAINT_Msk) || (u32IntSts & UART_INTSTS_RXTOINT_Msk))
   {


        /* Get all the input characters */
        while (!UART_GET_RX_EMPTY(UART4))
        {
            /* Get the character from UART Buffer */
            u8InChar = UART_READ(UART4);
            /* ToDo : User handle read data here */
            printf("0x%x\n",u8InChar);
        }
   }
   
 /* If you would like to use  "Transmit Holding Register Empty Interrupt  or  Transmitter Empty Interrupt ",you can add this code. */
//   if ((u32IntSts & UART_INTSTS_THREINT_Msk) || (u32IntSts & UART_INTSTS_TXENDIF_Msk) )
//   {
//      while (UART_IS_TX_FULL(UART4)){} /* Wait Tx is not full to transmit data */
//      UART_WRITE(UART4, u8InChar);
//   }

#endif //NUCODEGEN_UART4_IRDA_INTEN   
}


#elif (NUCODEGEN_UART4_FUNCSEL == NUCODEGEN_UART4_FUNCSEL_RS485)


void UART4_IRQHandler(void)
{
#if NUCODEGEN_UART4_RS485_INTEN 
    volatile uint32_t u32Addr = 0;
    uint32_t u32IntSts = UART4->INTSTS;
    uint32_t u32WKSts  = UART4->WKSTS;
    volatile uint8_t u8InChar = 0xFF;

  
  /* RLS INT & RDA INT */ 
    if ((u32IntSts & UART_INTSTS_RLSINT_Msk) && (u32IntSts & UART_INTSTS_RDAINT_Msk))//For RS485 Detect Address
    {
        if (UART4->FIFOSTS & UART_FIFOSTS_ADDRDETF_Msk)   /* ADD_IF, RS485 mode */
        {
            u32Addr = UART4->DAT;
            UART_RS485_CLEAR_ADDR_FLAG(UART4);        /* clear ADD_IF flag */
            printf("\nAddr=0x%x,Get:", u32Addr);

#if (NUCODEGEN_UART4_RS485_MODE == NUCODEGEN_UART4_RS485_NMM_MODE) //RS485_NMM
            /* if address match, enable RX to receive data, otherwise to disable RX. */
            /* In NMM mode,user can decide multi-address filter. In AAD mode,only one address can set */
            if ((u32Addr == UART4_MATCH_ADDRSS1) || (u32Addr == UART4_MATCH_ADDRSS2))
            {
                UART4->FIFO &= ~ UART_FIFO_RXOFF_Msk;  /* Enable RS485 RX */
            }
            else
            {
                UART4->FIFO |= UART_FIFO_RXOFF_Msk;      /* Disable RS485 RX */
                UART4->FIFO |= UART_FIFO_RXRST_Msk;      /* Clear data from RX FIFO */
                printf("\n");
            }
#endif
        }
    }
    else if ((u32IntSts & UART_INTSTS_RDAINT_Msk) || (u32IntSts & UART_INTSTS_RXTOINT_Msk))/* Rx Ready or Time-out INT*/
    {
         /* Handle received data */
        while (!UART_GET_RX_EMPTY(UART4))
        {
            /* Get the character from UART Buffer */
            u8InChar = UART_READ(UART4);
            /* ToDo : User handle read data here */
            printf("0x%x\n",u8InChar);
        }
        
    }
    else if (u32IntSts & UART_INTSTS_BUFERRINT_Msk)     /* Buffer Error INT */
    {
        printf("\nBuffer Error...\n");
        UART_ClearIntFlag(UART4, UART_INTSTS_BUFERRINT_Msk);
    }
 
     /* If you would like to use  "Transmit Holding Register Empty Interrupt  or  Transmitter Empty Interrupt ",you can add this code. */
//   if ((u32IntSts & UART_INTSTS_THREINT_Msk) || (u32IntSts & UART_INTSTS_TXENDIF_Msk) )
//   {
//      while (UART_IS_TX_FULL(UART4)){} /* Wait Tx is not full to transmit data */
//      UART_WRITE(UART4, u8InChar);
//   }

 #endif //NUCODEGEN_UART4_RS485_INTEN
}

#endif //(NUCODEGEN_UART4_FUNCSEL_UART || NUCODEGEN_UART4_FUNCSEL_SINGLE_WIRE)

#endif //NUCODEGEN_UART4


#if NUCODEGEN_UART5

#if (NUCODEGEN_UART5_FUNCSEL == NUCODEGEN_UART5_FUNCSEL_UART ||  NUCODEGEN_UART5_FUNCSEL == NUCODEGEN_UART5_FUNCSEL_SINGLE_WIRE )
void UART5_IRQHandler(void)
{
 
#if (NUCODEGEN_UART5_INTEN || NUCODEGEN_UART5_SW_INTEN )   
    uint32_t u32IntSts = UART5->INTSTS;
    uint32_t u32WKSts  = UART5->WKSTS;
    volatile uint8_t u8InChar = 0xFF;
    uint32_t u32Data;
    
    /* Auto-baud Rate Interrupt */
    if (u32IntSts & UART_INTSTS_ABRINT_Msk)
    {   
        UART5->FIFOSTS = (UART_FIFOSTS_ABRDIF_Msk | UART_FIFOSTS_ABRDTOIF_Msk);
    }
#if (NUCODEGEN_UART5_FUNCSEL == NUCODEGEN_UART5_FUNCSEL_UART)       
     /* MODEM Status Interrupt */
    if(u32IntSts & UART_INTSTS_MODEMIF_Msk)
    { 
     /*Clear nCTS State Change Flag*/     
      UART_ClearIntFlag(UART5, UART_INTSTS_MODEMINT_Msk);
    }
#endif  
    /* Receive Line Status Interrupt */
    if (u32IntSts & UART_INTSTS_RLSIF_Msk)
    {
        if (UART5->FIFOSTS & UART_FIFOSTS_BIF_Msk)
            printf("\n BIF \n");

        if (UART5->FIFOSTS & UART_FIFOSTS_FEF_Msk)
            printf("\n FEF \n");

        if (UART5->FIFOSTS & UART_FIFOSTS_PEF_Msk)
            printf("\n PEF \n");

        u32Data = UART5->DAT; // read out data
        printf("\n Error Data is '0x%x' \n", u32Data);
        UART_ClearIntFlag(UART5, UART_INTSTS_RLSINT_Msk);
    }
  
    if ((u32IntSts & UART_INTSTS_RDAINT_Msk) || (u32IntSts & UART_INTSTS_RXTOINT_Msk))/* Rx Ready or Time-out INT*/
    {
        /* Get all the input characters */
        while (!UART_GET_RX_EMPTY(UART5))
        {
            /* Get the character from UART Buffer */
            u8InChar = UART_READ(UART5);
            /* ToDo : User handle read data here */
            printf("0x%x\n",u8InChar);
        }
    }
 
    /* Buffer Error Interrupt  */
    if (u32IntSts & UART_INTSTS_BUFERRINT_Msk)     /* Buffer Error INT */
    {
        printf("\nBuffer Error...\n");
        UART_ClearIntFlag(UART5, UART_INTSTS_BUFERRINT_Msk);
    }
#if (NUCODEGEN_UART5_FUNCSEL == NUCODEGEN_UART5_FUNCSEL_SINGLE_WIRE)    
    if (u32IntSts & UART_INTSTS_SWBEINT_Msk)
    {
        printf("Single-wire Bit Error Detection \n");
        UART_ClearIntFlag(UART5, UART_INTSTS_SWBEINT_Msk);
    }
#endif  

    /* If you would like to use  "Transmit Holding Register Empty Interrupt  or  Transmitter Empty Interrupt ",you can add this code. */
//    if ((u32IntSts & UART_INTSTS_THREINT_Msk) || (u32IntSts & UART_INTSTS_TXENDIF_Msk) )
//    {
//      while (UART_IS_TX_FULL(UART5)){} /* Wait Tx is not full to transmit data */
//      UART_WRITE(UART5, u8InChar);
//    }

    /* UART Wake-up Interrupt  */
    if (u32IntSts & UART_INTSTS_WKIF_Msk)
    {
        printf("\n UART Wake-Up ");
        UART5->INTSTS = UART_INTSTS_WKIF_Msk;
        UART_ClearIntFlag(UART5,UART_INTSTS_WKINT_Msk);
    }
#endif //(NUCODEGEN_UART5_INTEN || NUCODEGEN_UART5_SW_INTEN)    
}

    
#elif (NUCODEGEN_UART5_FUNCSEL == NUCODEGEN_UART5_FUNCSEL_IrDA)
    
void UART5_IRQHandler(void)
{
#if NUCODEGEN_UART5_IRDA_INTEN   
  uint32_t u32IntSts = UART5->INTSTS;
  uint8_t u8InChar = 0xFF;

  /* Rx Ready or Time-out INT*/
  if ((u32IntSts & UART_INTSTS_RDAINT_Msk) || (u32IntSts & UART_INTSTS_RXTOINT_Msk))
   {
        /* Get all the input characters */
        while (!UART_GET_RX_EMPTY(UART5))
        {
            /* Get the character from UART Buffer */
            u8InChar = UART_READ(UART5);
            /* ToDo : User handle read data here */
            printf("0x%x\n",u8InChar);
        }
   }
   
 /* If you would like to use  "Transmit Holding Register Empty Interrupt  or  Transmitter Empty Interrupt ",you can add this code. */
//   if ((u32IntSts & UART_INTSTS_THREINT_Msk) || (u32IntSts & UART_INTSTS_TXENDIF_Msk) )
//   {
//      while (UART_IS_TX_FULL(UART5)){} /* Wait Tx is not full to transmit data */
//      UART_WRITE(UART5, u8InChar);
//   }

#endif //NUCODEGEN_UART5_IRDA_INTEN   
}


#elif (NUCODEGEN_UART5_FUNCSEL == NUCODEGEN_UART5_FUNCSEL_RS485)


void UART5_IRQHandler(void)
{
#if NUCODEGEN_UART5_RS485_INTEN 
    volatile uint32_t u32Addr = 0;
    uint32_t u32IntSts = UART5->INTSTS;
    uint32_t u32WKSts  = UART5->WKSTS;
    volatile uint8_t u8InChar = 0xFF;

  
  /* RLS INT & RDA INT */ 
    if ((u32IntSts & UART_INTSTS_RLSINT_Msk) && (u32IntSts & UART_INTSTS_RDAINT_Msk))//For RS485 Detect Address
    {
        if (UART5->FIFOSTS & UART_FIFOSTS_ADDRDETF_Msk)   /* ADD_IF, RS485 mode */
        {
            u32Addr = UART5->DAT;
            UART_RS485_CLEAR_ADDR_FLAG(UART5);        /* clear ADD_IF flag */
            printf("\nAddr=0x%x,Get:", u32Addr);

#if (NUCODEGEN_UART5_RS485_MODE == NUCODEGEN_UART5_RS485_NMM_MODE) //RS485_NMM
            /* if address match, enable RX to receive data, otherwise to disable RX. */
            /* In NMM mode,user can decide multi-address filter. In AAD mode,only one address can set */
            if ((u32Addr == UART5_MATCH_ADDRSS1) || (u32Addr == UART5_MATCH_ADDRSS2))
            {
                UART5->FIFO &= ~ UART_FIFO_RXOFF_Msk;  /* Enable RS485 RX */
            }
            else
            {
                UART5->FIFO |= UART_FIFO_RXOFF_Msk;      /* Disable RS485 RX */
                UART5->FIFO |= UART_FIFO_RXRST_Msk;      /* Clear data from RX FIFO */
                printf("\n");
            }
#endif
        }
    }
    else if ((u32IntSts & UART_INTSTS_RDAINT_Msk) || (u32IntSts & UART_INTSTS_RXTOINT_Msk))/* Rx Ready or Time-out INT*/
    {
        /* Get all the input characters */
        while (!UART_GET_RX_EMPTY(UART5))
        {
            /* Get the character from UART Buffer */
            u8InChar = UART_READ(UART5);
            /* ToDo : User handle read data here */
            printf("0x%x\n",u8InChar);
        }
        
    }
    else if (u32IntSts & UART_INTSTS_BUFERRINT_Msk)     /* Buffer Error INT */
    {
        printf("\nBuffer Error...\n");
        UART_ClearIntFlag(UART5, UART_INTSTS_BUFERRINT_Msk);
    }
 
     /* If you would like to use  "Transmit Holding Register Empty Interrupt  or  Transmitter Empty Interrupt ",you can add this code. */
//   if ((u32IntSts & UART_INTSTS_THREINT_Msk) || (u32IntSts & UART_INTSTS_TXENDIF_Msk) )
//   {
//      while (UART_IS_TX_FULL(UART5)){} /* Wait Tx is not full to transmit data */
//      UART_WRITE(UART5, u8InChar);
//   }

 #endif //NUCODEGEN_UART5_RS485_INTEN
}

#endif //(NUCODEGEN_UART5_FUNCSEL_UART || NUCODEGEN_UART5_FUNCSEL_SINGLE_WIRE)

#endif //NUCODEGEN_UART5


#if NUCODEGEN_UART6

#if (NUCODEGEN_UART6_FUNCSEL == NUCODEGEN_UART6_FUNCSEL_UART ||  NUCODEGEN_UART6_FUNCSEL == NUCODEGEN_UART6_FUNCSEL_SINGLE_WIRE )
void UART6_IRQHandler(void)
{
 
#if (NUCODEGEN_UART6_INTEN || NUCODEGEN_UART6_SW_INTEN )   
    uint32_t u32IntSts = UART6->INTSTS;
    uint32_t u32WKSts  = UART6->WKSTS;
    volatile uint8_t u8InChar = 0xFF;
    uint32_t u32Data;
    
    /* Auto-baud Rate Interrupt */
    if (u32IntSts & UART_INTSTS_ABRINT_Msk)
    {   
        UART6->FIFOSTS = (UART_FIFOSTS_ABRDIF_Msk | UART_FIFOSTS_ABRDTOIF_Msk);
    }
#if (NUCODEGEN_UART6_FUNCSEL == NUCODEGEN_UART6_FUNCSEL_UART)       
     /* MODEM Status Interrupt */
    if(u32IntSts & UART_INTSTS_MODEMIF_Msk)
    { 
     /*Clear nCTS State Change Flag*/     
      UART_ClearIntFlag(UART6, UART_INTSTS_MODEMINT_Msk);
    }
#endif  
    /* Receive Line Status Interrupt */
    if (u32IntSts & UART_INTSTS_RLSIF_Msk)
    {
        if (UART6->FIFOSTS & UART_FIFOSTS_BIF_Msk)
            printf("\n BIF \n");

        if (UART6->FIFOSTS & UART_FIFOSTS_FEF_Msk)
            printf("\n FEF \n");

        if (UART6->FIFOSTS & UART_FIFOSTS_PEF_Msk)
            printf("\n PEF \n");

        u32Data = UART6->DAT; // read out data
        printf("\n Error Data is '0x%x' \n", u32Data);
        UART_ClearIntFlag(UART6, UART_INTSTS_RLSINT_Msk);
    }
  
    if ((u32IntSts & UART_INTSTS_RDAINT_Msk) || (u32IntSts & UART_INTSTS_RXTOINT_Msk))/* Rx Ready or Time-out INT*/
    {
        /* Get all the input characters */
        while (!UART_GET_RX_EMPTY(UART6))
        {
            /* Get the character from UART Buffer */
            u8InChar = UART_READ(UART6);
            /* ToDo : User handle read data here */
            printf("0x%x\n",u8InChar);
        }
    }
 
    /* Buffer Error Interrupt  */
    if (u32IntSts & UART_INTSTS_BUFERRINT_Msk)     /* Buffer Error INT */
    {
        printf("\nBuffer Error...\n");
        UART_ClearIntFlag(UART6, UART_INTSTS_BUFERRINT_Msk);
    }
#if (NUCODEGEN_UART6_FUNCSEL == NUCODEGEN_UART6_FUNCSEL_SINGLE_WIRE)    
    if (u32IntSts & UART_INTSTS_SWBEINT_Msk)
    {
        printf("Single-wire Bit Error Detection \n");
        UART_ClearIntFlag(UART6, UART_INTSTS_SWBEINT_Msk);
    }
#endif  

    /* If you would like to use  "Transmit Holding Register Empty Interrupt  or  Transmitter Empty Interrupt ",you can add this code. */
//    if ((u32IntSts & UART_INTSTS_THREINT_Msk) || (u32IntSts & UART_INTSTS_TXENDIF_Msk) )
//    {
//      while (UART_IS_TX_FULL(UART6)){} /* Wait Tx is not full to transmit data */
//      UART_WRITE(UART6, u8InChar);
//    }

    /* UART Wake-up Interrupt  */
    if (u32IntSts & UART_INTSTS_WKIF_Msk)
    {
        printf("\n UART Wake-Up ");
        UART6->INTSTS = UART_INTSTS_WKIF_Msk;
        UART_ClearIntFlag(UART6,UART_INTSTS_WKINT_Msk);
    }
#endif //(NUCODEGEN_UART6_INTEN || NUCODEGEN_UART6_SW_INTEN)    
}

    
#elif (NUCODEGEN_UART6_FUNCSEL == NUCODEGEN_UART6_FUNCSEL_IrDA)
    
void UART6_IRQHandler(void)
{
#if NUCODEGEN_UART6_IRDA_INTEN   
  uint32_t u32IntSts = UART6->INTSTS;
  uint8_t u8InChar = 0xFF;

  /* Rx Ready or Time-out INT*/
  if ((u32IntSts & UART_INTSTS_RDAINT_Msk) || (u32IntSts & UART_INTSTS_RXTOINT_Msk))
   {
        /* Get all the input characters */
        while (!UART_GET_RX_EMPTY(UART6))
        {
            /* Get the character from UART Buffer */
            u8InChar = UART_READ(UART6);
            /* ToDo : User handle read data here */
            printf("0x%x\n",u8InChar);
        }
   }
   
 /* If you would like to use  "Transmit Holding Register Empty Interrupt  or  Transmitter Empty Interrupt ",you can add this code. */
//   if ((u32IntSts & UART_INTSTS_THREINT_Msk) || (u32IntSts & UART_INTSTS_TXENDIF_Msk) )
//   {
//      while (UART_IS_TX_FULL(UART6)){} /* Wait Tx is not full to transmit data */
//      UART_WRITE(UART6, u8InChar);
//   }

#endif //NUCODEGEN_UART6_IRDA_INTEN   
}


#elif (NUCODEGEN_UART6_FUNCSEL == NUCODEGEN_UART6_FUNCSEL_RS485)


void UART6_IRQHandler(void)
{
#if NUCODEGEN_UART6_RS485_INTEN 
    volatile uint32_t u32Addr = 0;
    uint32_t u32IntSts = UART6->INTSTS;
    uint32_t u32WKSts  = UART6->WKSTS;
    volatile uint8_t u8InChar = 0xFF;

  
  /* RLS INT & RDA INT */ 
    if ((u32IntSts & UART_INTSTS_RLSINT_Msk) && (u32IntSts & UART_INTSTS_RDAINT_Msk))//For RS485 Detect Address
    {
        if (UART6->FIFOSTS & UART_FIFOSTS_ADDRDETF_Msk)   /* ADD_IF, RS485 mode */
        {
            u32Addr = UART6->DAT;
            UART_RS485_CLEAR_ADDR_FLAG(UART6);        /* clear ADD_IF flag */
            printf("\nAddr=0x%x,Get:", u32Addr);

#if (NUCODEGEN_UART6_RS485_MODE == NUCODEGEN_UART6_RS485_NMM_MODE) //RS485_NMM
            /* if address match, enable RX to receive data, otherwise to disable RX. */
            /* In NMM mode,user can decide multi-address filter. In AAD mode,only one address can set */
            if ((u32Addr == UART6_MATCH_ADDRSS1) || (u32Addr == UART6_MATCH_ADDRSS2))
            {
                UART6->FIFO &= ~ UART_FIFO_RXOFF_Msk;  /* Enable RS485 RX */
            }
            else
            {
                UART6->FIFO |= UART_FIFO_RXOFF_Msk;      /* Disable RS485 RX */
                UART6->FIFO |= UART_FIFO_RXRST_Msk;      /* Clear data from RX FIFO */
                printf("\n");
            }
#endif
        }
    }
    else if ((u32IntSts & UART_INTSTS_RDAINT_Msk) || (u32IntSts & UART_INTSTS_RXTOINT_Msk))/* Rx Ready or Time-out INT*/
    {
        /* Get all the input characters */
        while (!UART_GET_RX_EMPTY(UART6))
        {
            /* Get the character from UART Buffer */
            u8InChar = UART_READ(UART6);
            /* ToDo : User handle read data here */
            printf("0x%x\n",u8InChar);
        }
        
    }
    else if (u32IntSts & UART_INTSTS_BUFERRINT_Msk)     /* Buffer Error INT */
    {
        printf("\nBuffer Error...\n");
        UART_ClearIntFlag(UART6, UART_INTSTS_BUFERRINT_Msk);
    }
 
     /* If you would like to use  "Transmit Holding Register Empty Interrupt  or  Transmitter Empty Interrupt ",you can add this code. */
//   if ((u32IntSts & UART_INTSTS_THREINT_Msk) || (u32IntSts & UART_INTSTS_TXENDIF_Msk) )
//   {
//      while (UART_IS_TX_FULL(UART6)){} /* Wait Tx is not full to transmit data */
//      UART_WRITE(UART6, u8InChar);
//   }

 #endif //NUCODEGEN_UART6_RS485_INTEN
}

#endif //(NUCODEGEN_UART6_FUNCSEL_UART || NUCODEGEN_UART6_FUNCSEL_SINGLE_WIRE)

#endif //NUCODEGEN_UART6

#if (NUCODEGEN_UART4 || NUCODEGEN_UART6)
    
void UART46_IRQHandler(void)
{
#if NUCODEGEN_UART4
    UART4_IRQHandler();
#endif //NUCODEGEN_UART4
#if NUCODEGEN_UART6
    UART6_IRQHandler();
#endif //NUCODEGEN_UART6
}

#endif //(NUCODEGEN_UART4 || NUCODEGEN_UART6)


#if NUCODEGEN_UART7

#if (NUCODEGEN_UART7_FUNCSEL == NUCODEGEN_UART7_FUNCSEL_UART ||  NUCODEGEN_UART7_FUNCSEL == NUCODEGEN_UART7_FUNCSEL_SINGLE_WIRE )
void UART7_IRQHandler(void)
{
 
#if (NUCODEGEN_UART7_INTEN || NUCODEGEN_UART7_SW_INTEN )   
    uint32_t u32IntSts = UART7->INTSTS;
    uint32_t u32WKSts  = UART7->WKSTS;
    volatile uint8_t u8InChar = 0xFF;
    uint32_t u32Data;
    
    /* Auto-baud Rate Interrupt */
    if (u32IntSts & UART_INTSTS_ABRINT_Msk)
    {   
        UART7->FIFOSTS = (UART_FIFOSTS_ABRDIF_Msk | UART_FIFOSTS_ABRDTOIF_Msk);
    }
#if (NUCODEGEN_UART7_FUNCSEL == NUCODEGEN_UART7_FUNCSEL_UART)       
     /* MODEM Status Interrupt */
    if(u32IntSts & UART_INTSTS_MODEMIF_Msk)
    { 
     /*Clear nCTS State Change Flag*/     
      UART_ClearIntFlag(UART7, UART_INTSTS_MODEMINT_Msk);
    }
#endif  
    /* Receive Line Status Interrupt */
    if (u32IntSts & UART_INTSTS_RLSIF_Msk)
    {
        if (UART7->FIFOSTS & UART_FIFOSTS_BIF_Msk)
            printf("\n BIF \n");

        if (UART7->FIFOSTS & UART_FIFOSTS_FEF_Msk)
            printf("\n FEF \n");

        if (UART7->FIFOSTS & UART_FIFOSTS_PEF_Msk)
            printf("\n PEF \n");

        u32Data = UART7->DAT; // read out data
        printf("\n Error Data is '0x%x' \n", u32Data);
        UART_ClearIntFlag(UART7, UART_INTSTS_RLSINT_Msk);
    }
  
    if ((u32IntSts & UART_INTSTS_RDAINT_Msk) || (u32IntSts & UART_INTSTS_RXTOINT_Msk))/* Rx Ready or Time-out INT*/
    {
        /* Get all the input characters */
        while (!UART_GET_RX_EMPTY(UART7))
        {
            /* Get the character from UART Buffer */
            u8InChar = UART_READ(UART7);
            /* ToDo : User handle read data here */
            printf("0x%x\n",u8InChar);
        }

    }
 
    /* Buffer Error Interrupt  */
    if (u32IntSts & UART_INTSTS_BUFERRINT_Msk)     /* Buffer Error INT */
    {
        printf("\nBuffer Error...\n");
        UART_ClearIntFlag(UART7, UART_INTSTS_BUFERRINT_Msk);
    }
#if (NUCODEGEN_UART7_FUNCSEL == NUCODEGEN_UART7_FUNCSEL_SINGLE_WIRE)    
    if (u32IntSts & UART_INTSTS_SWBEINT_Msk)
    {
        printf("Single-wire Bit Error Detection \n");
        UART_ClearIntFlag(UART7, UART_INTSTS_SWBEINT_Msk);
    }
#endif  

    /* If you would like to use  "Transmit Holding Register Empty Interrupt  or  Transmitter Empty Interrupt ",you can add this code. */
//    if ((u32IntSts & UART_INTSTS_THREINT_Msk) || (u32IntSts & UART_INTSTS_TXENDIF_Msk) )
//    {
//      while (UART_IS_TX_FULL(UART7)){} /* Wait Tx is not full to transmit data */
//      UART_WRITE(UART7, u8InChar);
//    }

    /* UART Wake-up Interrupt  */
    if (u32IntSts & UART_INTSTS_WKIF_Msk)
    {
        printf("\n UART Wake-Up ");
        UART7->INTSTS = UART_INTSTS_WKIF_Msk;
        UART_ClearIntFlag(UART7,UART_INTSTS_WKINT_Msk);
    }
#endif //(NUCODEGEN_UART7_INTEN || NUCODEGEN_UART7_SW_INTEN)    
}

    
#elif (NUCODEGEN_UART7_FUNCSEL == NUCODEGEN_UART7_FUNCSEL_IrDA)
    
void UART7_IRQHandler(void)
{
#if NUCODEGEN_UART7_IRDA_INTEN   
  uint32_t u32IntSts = UART7->INTSTS;
  uint8_t u8InChar = 0xFF;

  /* Rx Ready or Time-out INT*/
  if ((u32IntSts & UART_INTSTS_RDAINT_Msk) || (u32IntSts & UART_INTSTS_RXTOINT_Msk))
   {
        /* Get all the input characters */
        while (!UART_GET_RX_EMPTY(UART7))
        {
            /* Get the character from UART Buffer */
            u8InChar = UART_READ(UART7);
            /* ToDo : User handle read data here */
            printf("0x%x\n",u8InChar);
        }
   }
   
 /* If you would like to use  "Transmit Holding Register Empty Interrupt  or  Transmitter Empty Interrupt ",you can add this code. */
//   if ((u32IntSts & UART_INTSTS_THREINT_Msk) || (u32IntSts & UART_INTSTS_TXENDIF_Msk) )
//   {
//      while (UART_IS_TX_FULL(UART7)){} /* Wait Tx is not full to transmit data */
//      UART_WRITE(UART7, u8InChar);
//   }

#endif //NUCODEGEN_UART7_IRDA_INTEN   
}


#elif (NUCODEGEN_UART7_FUNCSEL == NUCODEGEN_UART7_FUNCSEL_RS485)


void UART7_IRQHandler(void)
{
#if NUCODEGEN_UART7_RS485_INTEN 
    volatile uint32_t u32Addr = 0;
    uint32_t u32IntSts = UART7->INTSTS;
    uint32_t u32WKSts  = UART7->WKSTS;
    volatile uint8_t u8InChar = 0xFF;

  
  /* RLS INT & RDA INT */ 
    if ((u32IntSts & UART_INTSTS_RLSINT_Msk) && (u32IntSts & UART_INTSTS_RDAINT_Msk))//For RS485 Detect Address
    {
        if (UART7->FIFOSTS & UART_FIFOSTS_ADDRDETF_Msk)   /* ADD_IF, RS485 mode */
        {
            u32Addr = UART7->DAT;
            UART_RS485_CLEAR_ADDR_FLAG(UART7);        /* clear ADD_IF flag */
            printf("\nAddr=0x%x,Get:", u32Addr);

#if (NUCODEGEN_UART7_RS485_MODE == NUCODEGEN_UART7_RS485_NMM_MODE) //RS485_NMM
            /* if address match, enable RX to receive data, otherwise to disable RX. */
            /* In NMM mode,user can decide multi-address filter. In AAD mode,only one address can set */
            if ((u32Addr == UART7_MATCH_ADDRSS1) || (u32Addr == UART7_MATCH_ADDRSS2))
            {
                UART7->FIFO &= ~ UART_FIFO_RXOFF_Msk;  /* Enable RS485 RX */
            }
            else
            {
                UART7->FIFO |= UART_FIFO_RXOFF_Msk;      /* Disable RS485 RX */
                UART7->FIFO |= UART_FIFO_RXRST_Msk;      /* Clear data from RX FIFO */
                printf("\n");
            }
#endif
        }
    }
    else if ((u32IntSts & UART_INTSTS_RDAINT_Msk) || (u32IntSts & UART_INTSTS_RXTOINT_Msk))/* Rx Ready or Time-out INT*/
    {
        /* Get all the input characters */
        while (!UART_GET_RX_EMPTY(UART7))
        {
            /* Get the character from UART Buffer */
            u8InChar = UART_READ(UART7);
            /* ToDo : User handle read data here */
            printf("0x%x\n",u8InChar);
        }
        
    }
    else if (u32IntSts & UART_INTSTS_BUFERRINT_Msk)     /* Buffer Error INT */
    {
        printf("\nBuffer Error...\n");
        UART_ClearIntFlag(UART7, UART_INTSTS_BUFERRINT_Msk);
    }
 
     /* If you would like to use  "Transmit Holding Register Empty Interrupt  or  Transmitter Empty Interrupt ",you can add this code. */
//   if ((u32IntSts & UART_INTSTS_THREINT_Msk) || (u32IntSts & UART_INTSTS_TXENDIF_Msk) )
//   {
//      while (UART_IS_TX_FULL(UART7)){} /* Wait Tx is not full to transmit data */
//      UART_WRITE(UART7, u8InChar);
//   }

 #endif //NUCODEGEN_UART7_RS485_INTEN
}

#endif //(NUCODEGEN_UART7_FUNCSEL_UART || NUCODEGEN_UART7_FUNCSEL_SINGLE_WIRE)

#endif //NUCODEGEN_UART7

#if (NUCODEGEN_UART5 || NUCODEGEN_UART7)
    
void UART57_IRQHandler(void)
{
#if NUCODEGEN_UART5
    UART5_IRQHandler();
#endif //NUCODEGEN_UART5
#if NUCODEGEN_UART7
    UART7_IRQHandler();
#endif //NUCODEGEN_UART7
}

#endif //(NUCODEGEN_UART5 || NUCODEGEN_UART7)
