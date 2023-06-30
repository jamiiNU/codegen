
#if (NUCODEGEN_SC0)
#if (NUCODEGEN_SC0_SUBMODE_SEL==NUCODEGEN_SC0_SUBMODE_SC)
void SC0_IRQHandler(void)
{
    /* Please don't remove any of the function calls below               */
    /* Card insert/remove event occurred, no need to check other event...*/
    if (SCLIB_CheckCDEvent(SC_INTF))
        return;

    /* Check if there's any timeout event occurs. If so, it usually indicates an error */
    SCLIB_CheckTimeOutEvent(SC_INTF);
    
    /* Check transmit and receive interrupt, all data transmission take place in this function*/
    SCLIB_CheckTxRxEvent(SC_INTF);

    /*
        Check if there's any transmission error occurred (e.g. parity error, frame error...)
        These errors will induce SCLIB to deactivation smartcard eventually.
    */
    SCLIB_CheckErrorEvent(SC_INTF);

    return;
}
#endif /*NUCODEGEN_SC0_SUBMODE_SEL==NUCODEGEN_SC0_SUBMODE_SC*/

#if (NUCODEGEN_SC0_SUBMODE_SEL==NUCODEGEN_SC0_SUBMODE_SCUART)
#if (NUCODEGEN_SC0_INT_EN)
void SC0_IRQHandler(void)
{
    uint32_t u32intsts;
    u32intsts = SC0->INTSTS;
    
    if(u32intsts & SC_INTSTS_TERRIF_Msk) {
        /*TODO: add user code here here*/
    } 
  
//    /* User can add following commented code here if the function, TBEIEN(SC_INTEN[1]), is enabled. */    
//    if(u32intsts & SC_INTSTS_TBEIF_Msk) {
//       /*TODO: add user code here here*/
//    }
    
    if(u32intsts & SC_INTSTS_RDAIF_Msk) {
        /*TODO: add user code here here*/
    }
    
    if(u32intsts & SC_INTSTS_RXTOIF_Msk){
        /*TODO: add user code here here*/
    }

    return;
}
#endif /*NUCODEGEN_SC0_INT_EN*/

#endif /*NUCODEGEN_SC0_SUBMODE_SEL==NUCODEGEN_SC0_SUBMODE_SCUART*/
#endif /*NUCODEGEN_SC0*/
