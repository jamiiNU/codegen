
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
