
#if (NUCODEGEN_PSIO)
#if (NUCODEGEN_PSIO_INT_EN)
void PSIO_IRQHandler(void)
{
    if(PSIO_GET_INT_FLAG(PSIO, PSIO_INTSTS_CON0IF_Msk)){
        printf("INT0 Interrupt!\n");
    }
    if(PSIO_GET_INT_FLAG(PSIO, PSIO_INTSTS_CON1IF_Msk)){
        printf("INT1 Interrupt!\n");
    }
    if(PSIO_GET_INT_FLAG(PSIO, PSIO_INTSTS_MISMATIF_Msk)){
        printf("Mismatch Interrupt!\n");
    }
    if(PSIO_GET_INT_FLAG(PSIO, PSIO_INTSTS_TERRIF_Msk)){
        printf("Transfer Error Interrupt!\n");
    }
    if(PSIO_GET_INT_FLAG(PSIO, PSIO_INTSTS_SC0IF_Msk)){
        printf("Slot Controller 0 Finish Interrupt!\n");
    }
    if(PSIO_GET_INT_FLAG(PSIO, PSIO_INTSTS_SC1IF_Msk)){
        printf("Slot Controller 1 Finish Interrupt!\n");
    }
    if(PSIO_GET_INT_FLAG(PSIO, PSIO_INTSTS_SC2IF_Msk)){
        printf("Slot Controller 2 Finish Interrupt!\n");
    }
    if(PSIO_GET_INT_FLAG(PSIO, PSIO_INTSTS_SC3IF_Msk)){
        printf("Slot Controller 3 Finish Interrupt!\n");
    }
}
#endif  //NUCODEGEN_PSIO_INT_EN
#endif  //NUCODEGEN_PSIO
