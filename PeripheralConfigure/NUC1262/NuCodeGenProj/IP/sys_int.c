
#if (NUCODEGEN_SYS)
#if (NUCODEGEN_SYS_BOD_INT_ENABLE||NUCODEGEN_SYS_VDET_INT_ENABLE)
void BOD_IRQHandler(void)
{
#if (NUCODEGEN_SYS_BOD_INT_ENABLE)
    /* Get BOD interrupt flag */
    if (SYS_GET_BOD_INT_FLAG())
    {
        /* Clear BOD interrupt flag */
        SYS_CLEAR_BOD_INT_FLAG();
    }
#endif

#if (NUCODEGEN_SYS_VDET_INT_ENABLE)
    /* Check if voltage detector interrupt happen */
    if( SYS->BODCTL & SYS_BODCTL_VDETIF_Msk )
    {
        /* Clear voltage detector interrupt flag */
        SYS->BODCTL |= SYS_BODCTL_VDETIF_Msk;

		/* Check voltage detector output status */
        if(SYS->BODCTL & SYS_BODCTL_VDETOUT_Msk)
            printf("The input voltage is lower than Bandgap.\n");
        else
            printf("The input voltage is higher than Bandgap.\n");
    }
#endif
}
#endif /* NUCODEGEN_SYS_BOD_INT_ENABLE || NUCODEGEN_SYS_VDET_INT_ENABLE */
#endif /* NUCODEGEN_SYS */
