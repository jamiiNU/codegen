
#if (NUCODEGEN_QSPI)
/*--------------------------------------------------------------------------------------------*/
/* QSPI                                                                                       */
/*--------------------------------------------------------------------------------------------*/
void QSPI_Init()
{
    /* This function make QSPI module be ready to transfer */
    QSPI_Open(QSPI0, NUCODEGEN_QSPI_MASTER, NUCODEGEN_QSPI_MODE, NUCODEGEN_QSPI_DATAWIDTH, NUCODEGEN_QSPI_BUSCLOCK);

#if (NUCODEGEN_QSPI_DUAL_QUAD_HALF_EN==NUCODEGEN_QSPI_CTL_DUALIOEN)

#if (NUCODEGEN_QSPI_DATA_DIR)
    /* Enable dual mode and set data direction as output */
    QSPI_ENABLE_DUAL_OUTPUT_MODE(QSPI0) ;
#else
    /* Enable dual mode and set data direction as input */
    QSPI_ENABLE_DUAL_INPUT_MODE(QSPI0) ;
#endif /* NUCODEGEN_QSPI_DATA_DIR */

#elif (NUCODEGEN_QSPI_DUAL_QUAD_HALF_EN==NUCODEGEN_QSPI_CTL_QUADIOEN)

#if (NUCODEGEN_QSPI_DATA_DIR)
    /* Enable quad mode and set data direction as output */
    QSPI_ENABLE_QUAD_OUTPUT_MODE(QSPI0) ;
#else
    /* Enable quad mode and set data direction as input */
    QSPI_ENABLE_QUAD_INPUT_MODE(QSPI0) ;
#endif  /* NUCODEGEN_QSPI_DATA_DIR */

#elif (NUCODEGEN_QSPI_DUAL_QUAD_HALF_EN==NUCODEGEN_QSPI_CTL_HALFIOEN)

#if (NUCODEGEN_QSPI_DATA_DIR)

    /* Enable half- duplex function and set data direction as output */
    QSPI0->CTL = QSPI0->CTL | (QSPI_CTL_DATDIR_Msk | QSPI_CTL_HALFDPX_Msk) ;

#else

    /* Enable half-duplex function and set data direction as input */
    QSPI0->CTL = (QSPI0->CTL & ~QSPI_CTL_DATDIR_Msk) | QSPI_CTL_HALFDPX_Msk ;
#endif  /* NUCODEGEN_QSPI_DATA_DIR */

#endif /* NUCODEGEN_QSPI_DUAL_QUAD_EN */

#if (NUCODEGEN_QSPI_2BIT_EN)

    /* Enable 2-bits mode */
    QSPI_ENABLE_2BIT_MODE(QSPI0);

#endif  /* NUCODEGEN_QSPI_2BIT_EN */

#if (NUCODEGEN_QSPI_BYTE_REORDER_EN)

    /* Enable byte reorder function */
    QSPI_ENABLE_BYTE_REORDER(QSPI0);

#endif  /* NUCODEGEN_QSPI_BYTE_REORDER_EN */

#if (NUCODEGEN_QSPI_RECEIVE_ONLY_EN)

    /* Enable receive-only mode */
    QSPI0->CTL = QSPI0->CTL | QSPI_CTL_RXONLY_Msk;

#endif /* NUCODEGEN_QSPI_RECEIVE_ONLY_EN */


#if (NUCODEGEN_QSPI_SS_EN)

    /* SS function enable */
    QSPI0->SSCTL = (QSPI0->SSCTL & (~QSPI_SSCTL_SS_Msk)) | QSPI_SSCTL_SS_Msk;

#endif  /* NUCODEGEN_QSPI_SS_EN */


#if (NUCODEGEN_QSPI_AUTOSS_EN)

    /* Enable auto SS function */
    QSPI0->SSCTL = (QSPI0->SSCTL & (~QSPI_SSCTL_AUTOSS_Msk)) | QSPI_SSCTL_AUTOSS_Msk | QSPI_SSCTL_SS_Msk;

#endif  /* NUCODEGEN_QSPI_AUTOSS_EN */

#if (NUCODEGEN_QSPI_3WIRE_EN)

    /* Enable 3-wire mode */
    QSPI_ENABLE_3WIRE_MODE(QSPI0);

#endif  /* NUCODEGEN_QSPI_3WIRE_EN */

    /* Select SS level */
    QSPI0->SSCTL = (QSPI0->SSCTL & (~QSPI_SSCTL_SSACTPOL_Msk)) | NUCODEGEN_QSPI_SS_LEVEL;

#if (NUCODEGEN_QSPI_DATA_ORDER)

    /* Set LSB first */
    QSPI_SET_LSB_FIRST(QSPI0);

#else

    /* Set MSB first */
    QSPI_SET_MSB_FIRST(QSPI0);

#endif /* NUCODEGEN_QSPI_DATA_ORDER */

    /* Set FIFO threshold */
    QSPI_SetFIFO(QSPI0, NUCODEGEN_QSPI_TX_THRESHOLD, NUCODEGEN_QSPI_RX_THRESHOLD);

#if (NUCODEGEN_QSPI_INT_EN)

    /* Enable interrupt function */
    NVIC_EnableIRQ(QSPI0_IRQn);

    /* Enable interrupt type */
    QSPI_EnableInt(QSPI0, NUCODEGEN_QSPI_INT_SEL);

#endif /* NUCODEGEN_QSPI_INT_EN */

}
#endif  /* NUCODEGEN_QSPI */
