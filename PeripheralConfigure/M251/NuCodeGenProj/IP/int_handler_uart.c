
#if NUCODEGEN_UART0
#if (NUCODEGEN_UART0_FUNCSEL_SEL == NUCODEGEN_UART0_FUNCSEL_UART || NUCODEGEN_UART0_FUNCSEL_SEL == NUCODEGEN_UART0_FUNCSEL_SINGLE_WIRE )
#if (NUCODEGEN_UART0_INT_EN || NUCODEGEN_UART0_SW_INT_EN )
void UART0_IRQHandler(void)
{
    uint32_t u32IntSts = UART0->INTSTS;
    uint8_t u8InChar = 0xFF;


#if NUCODEGEN_UART0_ABRDINT_EN
    /* Auto-baud Rate Interrupt */
    if (u32IntSts & UART_INTSTS_ABRINT_Msk)
    {
        UART0->FIFOSTS = (UART_FIFOSTS_ABRDIF_Msk | UART_FIFOSTS_ABRDTOIF_Msk);
    }
#endif

#if (NUCODEGEN_UART0_FUNCSEL_SEL == NUCODEGEN_UART0_FUNCSEL_UART)

#if NUCODEGEN_UART0_MODEMINT_EN
    /* MODEM Status Interrupt */
    if(u32IntSts & UART_INTSTS_MODEMIF_Msk)
    {
        /*Clear nCTS State Change Flag*/
        UART_ClearIntFlag(UART0, UART_INTSTS_MODEMINT_Msk);
    }
#endif

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

        u8InChar = UART0->DAT; // read out data
        printf("\n Error Data is '0x%x' \n", u8InChar);
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
    if (u32IntSts & UART_INTSTS_BUFERRINT_Msk) /* Buffer Error INT */
    {
        printf("\nBuffer Error...\n");
        UART_ClearIntFlag(UART0, UART_INTSTS_BUFERRINT_Msk);
    }

#if (NUCODEGEN_UART0_FUNCSEL_SEL == NUCODEGEN_UART0_FUNCSEL_SINGLE_WIRE)
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
#if ((NUCODEGEN_UART0_WKCTS_EN || NUCODEGEN_UART0_DATA_WAKEUP_SEL || NUCODEGEN_UART0_WKTOUT_EN) && NUCODEGEN_UART0_WAKEUP_INT_EN)
    /* UART Wake-up Interrupt  */
    if (u32IntSts & UART_INTSTS_WKIF_Msk)
    {
        printf("\n UART Wake-Up ");
        UART_ClearIntFlag(UART0,UART_INTSTS_WKINT_Msk);
    }
#endif
}
#endif //(NUCODEGEN_UART0_INTEN || NUCODEGEN_UART0_SW_INTEN)


#elif (NUCODEGEN_UART0_FUNCSEL == NUCODEGEN_UART0_FUNCSEL_LIN)

#if NUCODEGEN_UART0_LIN_INT_EN
void UART0_IRQHandler(void)
{

    uint32_t u32IntSts = UART0->INTSTS;
    /* LIN Bus Interrupt */
    if(u32IntSts & UART_INTSTS_LININT_Msk)
    {
        /* Clear LIN Bus Interrupt */
        UART_ClearIntFlag(UART0,UART_INTSTS_LININT_Msk);
    }

}
#endif  // NUCODEGEN_UART0_LIN_INT_EN

#elif (NUCODEGEN_UART0_FUNCSEL_SEL == NUCODEGEN_UART0_FUNCSEL_IrDA)
#if NUCODEGEN_UART0_IRDA_INT_EN
void UART0_IRQHandler(void)
{

    uint32_t u32IntSts = UART0->INTSTS;
    uint8_t u8InChar = 0xFF;

    /* Rx Ready or Time-out INT*/
    if ((u32IntSts & UART_INTSTS_RDAINT_Msk) || (u32IntSts & UART_INTSTS_RXTOINT_Msk))
    {

        /* Get all the input characters */
        while (UART_IS_RX_READY(UART0))
        {
            /* Get the character from UART Buffer */
            u8InChar = UART_READ(UART0);
            /* ToDo : User handle read data here */
            printf("%c\n", u8InChar);

        }
    }

    /* If you would like to use  "Transmit Holding Register Empty Interrupt  or  Transmitter Empty Interrupt ",you can add this code. */
//   if ((u32IntSts & UART_INTSTS_THREINT_Msk) || (u32IntSts & UART_INTSTS_TXENDIF_Msk) )
//   {
//      while (UART_IS_TX_FULL(UART0)){} /* Wait Tx is not full to transmit data */
//      UART_WRITE(UART0, u8InChar);
//   }

}
#endif //NUCODEGEN_UART0_IRDA_INTEN
#elif (NUCODEGEN_UART0_FUNCSEL_SEL == NUCODEGEN_UART0_FUNCSEL_RS485)

#if NUCODEGEN_UART0_RS485_INT_EN
void UART0_IRQHandler(void)
{

    volatile uint32_t u32Addr = 0;
    uint32_t u32IntSts = UART0->INTSTS;
    uint8_t u8InChar = 0xFF;

    /* RLS INT & RDA INT */
    if ((u32IntSts & UART_INTSTS_RLSINT_Msk) && (u32IntSts & UART_INTSTS_RDAINT_Msk))//For RS485 Detect Address
    {
        if (UART0->FIFOSTS & UART_FIFOSTS_ADDRDETF_Msk)   /* ADD_IF, RS485 mode */
        {
            u32Addr = UART0->DAT;
            UART_RS485_CLEAR_ADDR_FLAG(UART0);/* clear ADD_IF flag */
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

#if NUCODEGEN_UART0_WAKEUP_INT_EN
    /* UART Wake-up Interrupt  */
    if (u32IntSts & UART_INTSTS_WKIF_Msk)
    {
        printf("\n UART Wake-Up ");
        UART_ClearIntFlag(UART0,UART_INTSTS_WKINT_Msk);
    }
#endif

}
#endif //NUCODEGEN_UART0_RS485_INT_EN
#endif //(NUCODEGEN_UART0_FUNCSEL_UART || NUCODEGEN_UART0_FUNCSEL_SINGLE_WIRE)

#endif

#if NUCODEGEN_UART1

#if (NUCODEGEN_UART1_FUNCSEL_SEL == NUCODEGEN_UART1_FUNCSEL_UART || NUCODEGEN_UART1_FUNCSEL_SEL == NUCODEGEN_UART1_FUNCSEL_SINGLE_WIRE )
#if (NUCODEGEN_UART1_INT_EN || NUCODEGEN_UART1_SW_INT_EN )
void UART1_IRQHandler(void)
{
    uint32_t u32IntSts = UART1->INTSTS;
    uint8_t u8InChar = 0xFF;


#if NUCODEGEN_UART1_ABRDINT_EN
    /* Auto-baud Rate Interrupt */
    if (u32IntSts & UART_INTSTS_ABRINT_Msk)
    {
        UART1->FIFOSTS = (UART_FIFOSTS_ABRDIF_Msk | UART_FIFOSTS_ABRDTOIF_Msk);
    }
#endif

#if (NUCODEGEN_UART1_FUNCSEL_SEL == NUCODEGEN_UART1_FUNCSEL_UART)

#if NUCODEGEN_UART1_MODEMINT_EN
    /* MODEM Status Interrupt */
    if(u32IntSts & UART_INTSTS_MODEMIF_Msk)
    {
        /*Clear nCTS State Change Flag*/
        UART_ClearIntFlag(UART1, UART_INTSTS_MODEMINT_Msk);
    }
#endif

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

        u8InChar = UART1->DAT; // read out data
        printf("\n Error Data is '0x%x' \n", u8InChar);
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
    if (u32IntSts & UART_INTSTS_BUFERRINT_Msk) /* Buffer Error INT */
    {
        printf("\nBuffer Error...\n");
        UART_ClearIntFlag(UART1, UART_INTSTS_BUFERRINT_Msk);
    }

#if (NUCODEGEN_UART1_FUNCSEL_SEL == NUCODEGEN_UART1_FUNCSEL_SINGLE_WIRE)
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
#if ((NUCODEGEN_UART1_WKCTS_EN || NUCODEGEN_UART1_DATA_WAKEUP_SEL || NUCODEGEN_UART1_WKTOUT_EN) && NUCODEGEN_UART1_WAKEUP_INT_EN)
    /* UART Wake-up Interrupt  */
    if (u32IntSts & UART_INTSTS_WKIF_Msk)
    {
        printf("\n UART Wake-Up ");
        UART_ClearIntFlag(UART1,UART_INTSTS_WKINT_Msk);
    }
#endif
}
#endif //(NUCODEGEN_UART1_INTEN || NUCODEGEN_UART1_SW_INTEN)

#elif (NUCODEGEN_UART1_FUNCSEL_SEL == NUCODEGEN_UART1_FUNCSEL_IrDA)
#if NUCODEGEN_UART1_IRDA_INT_EN
void UART1_IRQHandler(void)
{

    uint32_t u32IntSts = UART1->INTSTS;
    uint8_t u8InChar = 0xFF;

    /* Rx Ready or Time-out INT*/
    if ((u32IntSts & UART_INTSTS_RDAINT_Msk) || (u32IntSts & UART_INTSTS_RXTOINT_Msk))
    {

        /* Get all the input characters */
        while (UART_IS_RX_READY(UART1))
        {
            /* Get the character from UART Buffer */
            u8InChar = UART_READ(UART1);
            /* ToDo : User handle read data here */
            printf("%c\n", u8InChar);

        }
    }

    /* If you would like to use  "Transmit Holding Register Empty Interrupt  or  Transmitter Empty Interrupt ",you can add this code. */
//   if ((u32IntSts & UART_INTSTS_THREINT_Msk) || (u32IntSts & UART_INTSTS_TXENDIF_Msk) )
//   {
//      while (UART_IS_TX_FULL(UART1)){} /* Wait Tx is not full to transmit data */
//      UART_WRITE(UART1, u8InChar);
//   }

}
#endif //NUCODEGEN_UART1_IRDA_INTEN
#elif (NUCODEGEN_UART1_FUNCSEL_SEL == NUCODEGEN_UART1_FUNCSEL_RS485)

#if NUCODEGEN_UART1_RS485_INT_EN
void UART1_IRQHandler(void)
{

    volatile uint32_t u32Addr = 0;
    uint32_t u32IntSts = UART1->INTSTS;
    uint8_t u8InChar = 0xFF;

    /* RLS INT & RDA INT */
    if ((u32IntSts & UART_INTSTS_RLSINT_Msk) && (u32IntSts & UART_INTSTS_RDAINT_Msk))//For RS485 Detect Address
    {
        if (UART1->FIFOSTS & UART_FIFOSTS_ADDRDETF_Msk)   /* ADD_IF, RS485 mode */
        {
            u32Addr = UART1->DAT;
            UART_RS485_CLEAR_ADDR_FLAG(UART1);/* clear ADD_IF flag */
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

#if NUCODEGEN_UART1_WAKEUP_INT_EN
    /* UART Wake-up Interrupt  */
    if (u32IntSts & UART_INTSTS_WKIF_Msk)
    {
        printf("\n UART Wake-Up ");
        UART_ClearIntFlag(UART1,UART_INTSTS_WKINT_Msk);
    }
#endif

}
#endif //NUCODEGEN_UART1_RS485_INT_EN
#endif //(NUCODEGEN_UART1_FUNCSEL_UART || NUCODEGEN_UART1_FUNCSEL_SINGLE_WIRE)

#endif

#if NUCODEGEN_UART2

#if (NUCODEGEN_UART2_FUNCSEL_SEL == NUCODEGEN_UART2_FUNCSEL_UART || NUCODEGEN_UART2_FUNCSEL_SEL == NUCODEGEN_UART2_FUNCSEL_SINGLE_WIRE )
#if (NUCODEGEN_UART2_INT_EN || NUCODEGEN_UART2_SW_INT_EN )
void UART2_IRQHandler(void)
{
    uint32_t u32IntSts = UART2->INTSTS;
    uint8_t u8InChar = 0xFF;


#if NUCODEGEN_UART2_ABRDINT_EN
    /* Auto-baud Rate Interrupt */
    if (u32IntSts & UART_INTSTS_ABRINT_Msk)
    {
        UART2->FIFOSTS = (UART_FIFOSTS_ABRDIF_Msk | UART_FIFOSTS_ABRDTOIF_Msk);
    }
#endif

#if (NUCODEGEN_UART2_FUNCSEL_SEL == NUCODEGEN_UART2_FUNCSEL_UART)

#if NUCODEGEN_UART2_MODEMINT_EN
    /* MODEM Status Interrupt */
    if(u32IntSts & UART_INTSTS_MODEMIF_Msk)
    {
        /*Clear nCTS State Change Flag*/
        UART_ClearIntFlag(UART2, UART_INTSTS_MODEMINT_Msk);
    }
#endif

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

        u8InChar = UART2->DAT; // read out data
        printf("\n Error Data is '0x%x' \n", u8InChar);
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
    if (u32IntSts & UART_INTSTS_BUFERRINT_Msk) /* Buffer Error INT */
    {
        printf("\nBuffer Error...\n");
        UART_ClearIntFlag(UART2, UART_INTSTS_BUFERRINT_Msk);
    }

#if (NUCODEGEN_UART2_FUNCSEL_SEL == NUCODEGEN_UART2_FUNCSEL_SINGLE_WIRE)
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
#if ((NUCODEGEN_UART2_WKCTS_EN || NUCODEGEN_UART2_DATA_WAKEUP_SEL || NUCODEGEN_UART2_WKTOUT_EN) && NUCODEGEN_UART2_WAKEUP_INT_EN)
    /* UART Wake-up Interrupt  */
    if (u32IntSts & UART_INTSTS_WKIF_Msk)
    {
        printf("\n UART Wake-Up ");
        UART_ClearIntFlag(UART2,UART_INTSTS_WKINT_Msk);
    }
#endif
}
#endif //(NUCODEGEN_UART2_INTEN || NUCODEGEN_UART2_SW_INTEN)

#elif (NUCODEGEN_UART2_FUNCSEL_SEL == NUCODEGEN_UART2_FUNCSEL_IrDA)
#if NUCODEGEN_UART2_IRDA_INT_EN
void UART2_IRQHandler(void)
{

    uint32_t u32IntSts = UART2->INTSTS;
    uint8_t u8InChar = 0xFF;

    /* Rx Ready or Time-out INT*/
    if ((u32IntSts & UART_INTSTS_RDAINT_Msk) || (u32IntSts & UART_INTSTS_RXTOINT_Msk))
    {

        /* Get all the input characters */
        while (UART_IS_RX_READY(UART2))
        {
            /* Get the character from UART Buffer */
            u8InChar = UART_READ(UART2);
            /* ToDo : User handle read data here */
            printf("%c\n", u8InChar);

        }
    }

    /* If you would like to use  "Transmit Holding Register Empty Interrupt  or  Transmitter Empty Interrupt ",you can add this code. */
//   if ((u32IntSts & UART_INTSTS_THREINT_Msk) || (u32IntSts & UART_INTSTS_TXENDIF_Msk) )
//   {
//      while (UART_IS_TX_FULL(UART2)){} /* Wait Tx is not full to transmit data */
//      UART_WRITE(UART2, u8InChar);
//   }

}
#endif //NUCODEGEN_UART2_IRDA_INTEN
#elif (NUCODEGEN_UART2_FUNCSEL_SEL == NUCODEGEN_UART2_FUNCSEL_RS485)

#if NUCODEGEN_UART2_RS485_INT_EN
void UART2_IRQHandler(void)
{

    volatile uint32_t u32Addr = 0;
    uint32_t u32IntSts = UART2->INTSTS;
    uint8_t u8InChar = 0xFF;

    /* RLS INT & RDA INT */
    if ((u32IntSts & UART_INTSTS_RLSINT_Msk) && (u32IntSts & UART_INTSTS_RDAINT_Msk))//For RS485 Detect Address
    {
        if (UART2->FIFOSTS & UART_FIFOSTS_ADDRDETF_Msk)   /* ADD_IF, RS485 mode */
        {
            u32Addr = UART2->DAT;
            UART_RS485_CLEAR_ADDR_FLAG(UART2);/* clear ADD_IF flag */
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

#if NUCODEGEN_UART2_WAKEUP_INT_EN
    /* UART Wake-up Interrupt  */
    if (u32IntSts & UART_INTSTS_WKIF_Msk)
    {
        printf("\n UART Wake-Up ");
        UART_ClearIntFlag(UART2,UART_INTSTS_WKINT_Msk);
    }
#endif

}
#endif //NUCODEGEN_UART2_RS485_INT_EN
#endif //(NUCODEGEN_UART2_FUNCSEL_UART || NUCODEGEN_UART2_FUNCSEL_SINGLE_WIRE)

#endif

#if NUCODEGEN_UART3

#if (NUCODEGEN_UART3_FUNCSEL_SEL == NUCODEGEN_UART3_FUNCSEL_UART || NUCODEGEN_UART3_FUNCSEL_SEL == NUCODEGEN_UART3_FUNCSEL_SINGLE_WIRE )
#if (NUCODEGEN_UART3_INT_EN || NUCODEGEN_UART3_SW_INT_EN )
void UART3_IRQHandler(void)
{
    uint32_t u32IntSts = UART3->INTSTS;
    uint8_t u8InChar = 0xFF;


#if NUCODEGEN_UART3_ABRDINT_EN
    /* Auto-baud Rate Interrupt */
    if (u32IntSts & UART_INTSTS_ABRINT_Msk)
    {
        UART3->FIFOSTS = (UART_FIFOSTS_ABRDIF_Msk | UART_FIFOSTS_ABRDTOIF_Msk);
    }
#endif

#if (NUCODEGEN_UART3_FUNCSEL_SEL == NUCODEGEN_UART3_FUNCSEL_UART)

#if NUCODEGEN_UART3_MODEMINT_EN
    /* MODEM Status Interrupt */
    if(u32IntSts & UART_INTSTS_MODEMIF_Msk)
    {
        /*Clear nCTS State Change Flag*/
        UART_ClearIntFlag(UART3, UART_INTSTS_MODEMINT_Msk);
    }
#endif

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

        u8InChar = UART3->DAT; // read out data
        printf("\n Error Data is '0x%x' \n", u8InChar);
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
    if (u32IntSts & UART_INTSTS_BUFERRINT_Msk) /* Buffer Error INT */
    {
        printf("\nBuffer Error...\n");
        UART_ClearIntFlag(UART3, UART_INTSTS_BUFERRINT_Msk);
    }

#if (NUCODEGEN_UART3_FUNCSEL_SEL == NUCODEGEN_UART3_FUNCSEL_SINGLE_WIRE)
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
#if ((NUCODEGEN_UART3_WKCTS_EN || NUCODEGEN_UART3_DATA_WAKEUP_SEL || NUCODEGEN_UART3_WKTOUT_EN) && NUCODEGEN_UART3_WAKEUP_INT_EN)
    /* UART Wake-up Interrupt  */
    if (u32IntSts & UART_INTSTS_WKIF_Msk)
    {
        printf("\n UART Wake-Up ");
        UART_ClearIntFlag(UART3,UART_INTSTS_WKINT_Msk);
    }
#endif
}
#endif //(NUCODEGEN_UART3_INTEN || NUCODEGEN_UART3_SW_INTEN)

#elif (NUCODEGEN_UART3_FUNCSEL_SEL == NUCODEGEN_UART3_FUNCSEL_IrDA)
#if NUCODEGEN_UART3_IRDA_INT_EN
void UART3_IRQHandler(void)
{

    uint32_t u32IntSts = UART3->INTSTS;
    uint8_t u8InChar = 0xFF;

    /* Rx Ready or Time-out INT*/
    if ((u32IntSts & UART_INTSTS_RDAINT_Msk) || (u32IntSts & UART_INTSTS_RXTOINT_Msk))
    {

        /* Get all the input characters */
        while (UART_IS_RX_READY(UART3))
        {
            /* Get the character from UART Buffer */
            u8InChar = UART_READ(UART3);
            /* ToDo : User handle read data here */
            printf("%c\n", u8InChar);

        }
    }

    /* If you would like to use  "Transmit Holding Register Empty Interrupt  or  Transmitter Empty Interrupt ",you can add this code. */
//   if ((u32IntSts & UART_INTSTS_THREINT_Msk) || (u32IntSts & UART_INTSTS_TXENDIF_Msk) )
//   {
//      while (UART_IS_TX_FULL(UART3)){} /* Wait Tx is not full to transmit data */
//      UART_WRITE(UART3, u8InChar);
//   }

}
#endif //NUCODEGEN_UART3_IRDA_INTEN
#elif (NUCODEGEN_UART3_FUNCSEL_SEL == NUCODEGEN_UART3_FUNCSEL_RS485)

#if NUCODEGEN_UART3_RS485_INT_EN
void UART3_IRQHandler(void)
{

    volatile uint32_t u32Addr = 0;
    uint32_t u32IntSts = UART3->INTSTS;
    uint8_t u8InChar = 0xFF;

    /* RLS INT & RDA INT */
    if ((u32IntSts & UART_INTSTS_RLSINT_Msk) && (u32IntSts & UART_INTSTS_RDAINT_Msk))//For RS485 Detect Address
    {
        if (UART3->FIFOSTS & UART_FIFOSTS_ADDRDETF_Msk)   /* ADD_IF, RS485 mode */
        {
            u32Addr = UART3->DAT;
            UART_RS485_CLEAR_ADDR_FLAG(UART3);/* clear ADD_IF flag */
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

#if NUCODEGEN_UART3_WAKEUP_INT_EN
    /* UART Wake-up Interrupt  */
    if (u32IntSts & UART_INTSTS_WKIF_Msk)
    {
        printf("\n UART Wake-Up ");
        UART_ClearIntFlag(UART3,UART_INTSTS_WKINT_Msk);
    }
#endif

}
#endif //NUCODEGEN_UART3_RS485_INT_EN
#endif //(NUCODEGEN_UART3_FUNCSEL_UART || NUCODEGEN_UART3_FUNCSEL_SINGLE_WIRE)

#endif
