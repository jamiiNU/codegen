
#if (NUCODEGEN_SYS)
#if (NUCODEGEN_SYS_BOD_INT_ENABLE)
void BOD_IRQHandler(void)
{
    /* Get BOD interrupt flag */
    if (SYS_GET_BOD_INT_FLAG())
    {
        /* Clear BOD interrupt flag */
        SYS_CLEAR_BOD_INT_FLAG();
    }
}
#endif /* NUCODEGEN_SYS_BOD_INT_ENABLE */
#endif /* NUCODEGEN_SYS */

#if (NUCODEGEN_SYS)
#if (NUCODEGEN_SYS_HIRCTRIM_INT_EN || NUCODEGEN_SYS_MIRCTRIM_INT_EN)
void IRCTRIM_IRQHandler(void)
{
#if (NUCODEGEN_SYS_HIRCTRIM_INT_EN)  
    if (SYS->HIRCTRIMSTS & SYS_HIRCTRIMSTS_TFAILIF_Msk)   /* Get Trim Failure Interrupt */
    {
        /* Display HIRC trim status */
        printf("HIRC Trim Failure Interrupt\n");
        /* Clear Trim Failure Interrupt */
        SYS->HIRCTRIMSTS = SYS_HIRCTRIMSTS_TFAILIF_Msk;
    }

    if (SYS->HIRCTRIMSTS & SYS_HIRCTRIMSTS_CLKERIF_Msk)   /* Get LXT Clock Error Interrupt */
    {
        /* Display HIRC trim status */
        printf("LXT Clock Error Interrupt\n");
        /* Clear LXT Clock Error Interrupt */
        SYS->HIRCTRIMSTS = SYS_HIRCTRIMSTS_CLKERIF_Msk;
    }
#endif

#if (NUCODEGEN_SYS_MIRCTRIM_INT_EN)  
    if (SYS->MIRCTRIMSTS & SYS_MIRCTRIMSTS_TFAILIF_Msk)   /* Get Trim Failure Interrupt */
    {
        /* Display MIRC trim status */
        printf("MIRC Trim Failure Interrupt\n");
        /* Clear Trim Failure Interrupt */
        SYS->MIRCTRIMSTS = SYS_MIRCTRIMSTS_TFAILIF_Msk;
    }

    if (SYS->MIRCTRIMSTS & SYS_MIRCTRIMSTS_CLKERIF_Msk)   /* Get LXT Clock Error Interrupt */
    {
        /* Display MIRC trim status */
        printf("LXT Clock Error Interrupt\n");
        /* Clear LXT Clock Error Interrupt */
        SYS->MIRCTRIMSTS = SYS_MIRCTRIMSTS_CLKERIF_Msk;
    }
#endif
}
#endif /* NUCODEGEN_SYS_HIRCTRIM_INT_EN || NUCODEGEN_SYS_MIRCTRIM_INT_EN */
#endif /* NUCODEGEN_SYS */
