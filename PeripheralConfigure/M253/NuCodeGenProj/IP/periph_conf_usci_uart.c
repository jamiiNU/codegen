
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

