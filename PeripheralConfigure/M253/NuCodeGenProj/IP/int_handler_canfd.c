
#if NUCODEGEN_CANFD0
#if(NUCODEGEN_CANFD0_INT_EN || NUCODEGEN_CANFD0_RXBUF_INT_EN || NUCODEGEN_CANFD0_FIFO0_INT_EN || NUCODEGEN_CANFD0_FIFO1_INT_EN)

#if NUCODEGEN_CANFD0_RXBUF_INT_EN
CANFD_FD_MSG_T      g_sRxBufMsgFrame;
#endif
#if NUCODEGEN_CANFD0_FIFO0_INT_EN
CANFD_FD_MSG_T      g_sRxFifo0MsgFrame;
#endif
#if NUCODEGEN_CANFD0_FIFO1_INT_EN
CANFD_FD_MSG_T      g_sRxFifo1MsgFrame;
#endif
#if NUCODEGEN_CANFD0_INT_EN
void CANFD0_BusErrHandler(void)
{

    if(CANFD0->IR & (CANFD_IR_PED_Msk | CANFD_IR_PEA_Msk ))
    {
        printf("Bus Error Code = 0x%02lx\n.",(CANFD0->PSR & CANFD_PSR_LEC_Msk));
    }

    if(CANFD0->IR & CANFD_IR_BO_Msk)
    {
        printf("Bus off occurred.\n");
    }

    if(CANFD0->IR & CANFD_IR_MRAF_Msk)
    {
        printf("Message RAM access failure occurred.\n");
        CANFD_ClearStatusFlag(CANFD0, CANFD_IR_TOO_Msk);
    }

}
#endif

void CANFD0_IRQ0_IRQHandler(void)
{

#if NUCODEGEN_CANFD0_INT_EN
    CANFD0_BusErrHandler();
#endif

#if NUCODEGEN_CANFD0_INT_EN
    if(CANFD0->IR & CANFD_IR_TOO_Msk)
    {
        printf("Timeout Occurred.\n");
        CANFD_ClearStatusFlag(CANFD0, CANFD_IR_TOO_Msk);
    }
#endif

#if NUCODEGEN_CANFD0_FIFO0_INT_EN
    if(CANFD0->IR & CANFD_IR_RF0N_Msk)
    {
        /*Clear the Interrupt flag */
        CANFD_ClearStatusFlag(CANFD0, CANFD_IR_TOO_Msk | CANFD_IR_RF0N_Msk);
        /*Recieve the Rx Fifo0 message */
        CANFD_ReadRxFifoMsg(CANFD0, 0, &g_sRxFifo0MsgFrame);
    }
#endif

#if NUCODEGEN_CANFD0_FIFO1_INT_EN
    if(CANFD0->IR & CANFD_IR_RF1N_Msk)
    {
        /*Clear the Interrupt flag */
        CANFD_ClearStatusFlag(CANFD0, CANFD_IR_TOO_Msk | CANFD_IR_RF1N_Msk);
        /*Recieve the Rx Fifo1 message */
        CANFD_ReadRxFifoMsg(CANFD0, 1, &g_sRxFifo1MsgFrame);
    }
#endif

#if NUCODEGEN_CANFD0_RXBUF_INT_EN
    if(CANFD0->IR & CANFD_IR_DRX_Msk)
    {
        /*Clear the Interrupt flag */
        CANFD_ClearStatusFlag(CANFD0, CANFD_IR_TOO_Msk | CANFD_IR_DRX_Msk);
#if(NUCODEGEN_CANFD0_RXBUF_ID_FILTER_ELEMS_SIZE > 0)
        /*Recieve the Rx Buffer message */
        if (CANFD_ReadRxBufMsg(CANFD0, 0, &g_sRxBufMsgFrame) == 1)
        {
        }
#endif
#if(NUCODEGEN_CANFD0_RXBUF_ID_FILTER_ELEMS_SIZE > 1)
        /*Recieve the Rx Buffer message */
        if (CANFD_ReadRxBufMsg(CANFD0, 1, &g_sRxBufMsgFrame) == 1)
        {
        }
#endif
#if(NUCODEGEN_CANFD0_RXBUF_ID_FILTER_ELEMS_SIZE > 2)
        /*Recieve the Rx Buffer message */
        if (CANFD_ReadRxBufMsg(CANFD0, 2, &g_sRxBufMsgFrame) == 1)
        {
        }
#endif
    }
#endif

}
#endif
#endif
