
#if (NUCODEGEN_SPII2S0)
/*--------------------------------------------------------------------------------------------*/
/* SPII2S                                                                                     */
/*--------------------------------------------------------------------------------------------*/
void SPII2S0_Init()
{
#if (NUCODEGEN_SPII2S0_MODE==NUCODEGEN_SPI0_MODE)

    /* This function make SPI module be ready to transfer */
    SPI_Open(SPI0, NUCODEGEN_SPI0_MASTER, NUCODEGEN_SPI0_TIME_MODE, NUCODEGEN_SPI0_DATAWIDTH, NUCODEGEN_SPI0_BUSCLOCK);

#if (NUCODEGEN_SPI0_BYTE_REORDER_EN)

    /* Enable byte reorder function */
    SPI_ENABLE_BYTE_REORDER(SPI0);

#endif /* NUCODEGEN_SPI0_BYTE_REORDER_EN */

#if (NUCODEGEN_SPI0_HALF_DUPLEX_EN)

#if (NUCODEGEN_SPI0_DATA_DIR)

    /* Enable half- duplex function and set data direction as output */
    SPI0->CTL = SPI0->CTL | (SPI_CTL_DATDIR_Msk | SPI_CTL_HALFDPX_Msk) ;

#else

    /* Enable half-duplex function and set data direction as input */
    SPI0->CTL = (SPI0->CTL & ~SPI_CTL_DATDIR_Msk) | SPI_CTL_HALFDPX_Msk ;

#endif /* NUCODEGEN_SPI0_DATA_DIR */

#endif /* NUCODEGEN_SPI0_HALF_DUPLEX_EN */

#if (NUCODEGEN_SPI0_RECEIVE_ONLY_EN)

    /* Enable receive-only mode */
    SPI0->CTL = SPI0->CTL | SPI_CTL_RXONLY_Msk;

#endif /* NUCODEGEN_SPI0_RECEIVE_ONLY_EN */

#if (NUCODEGEN_SPI0_SS_EN)

    /* SS function enable */
    SPI0->SSCTL = (SPI0->SSCTL & (~SPI_SSCTL_SS_Msk)) | SPI_SSCTL_SS_Msk;

#endif /* NUCODEGEN_SPI0_SS_EN */

#if (NUCODEGEN_SPI0_AUTOSS_EN)

    /* Enable auto SS function */
    SPI0->SSCTL = (SPI0->SSCTL & (~SPI_SSCTL_AUTOSS_Msk)) | SPI_SSCTL_AUTOSS_Msk | SPI_SSCTL_SS_Msk;

#endif /* NUCODEGEN_SPI0_AUTOSS_EN */

    /* Select SS level */
    SPI0->SSCTL = (SPI0->SSCTL & (~SPI_SSCTL_SSACTPOL_Msk)) | NUCODEGEN_SPI0_SS_LEVEL;

#if (NUCODEGEN_SPI0_DATA_ORDER)

    /* Set LSB first */
    SPI_SET_LSB_FIRST(SPI0);

#else

    /* Set MSB first */
    SPI_SET_MSB_FIRST(SPI0);

#endif /* NUCODEGEN_SPI0_DATA_ORDER */

#if (NUCODEGEN_SPI0_DATAWIDTH>16)

    /* Set FIFO threshold */
    SPI_SetFIFO(SPI0, NUCODEGEN_SPI0_TX_THRESHOLD0, NUCODEGEN_SPI0_RX_THRESHOLD0);

#else

    /* Set FIFO threshold */
    SPI_SetFIFO(SPI0, NUCODEGEN_SPI0_TX_THRESHOLD1, NUCODEGEN_SPI0_RX_THRESHOLD1);

#endif /* NUCODEGEN_SPI0_DATAWIDTH */

#if (NUCODEGEN_SPI0_INT_EN)

    /* Enable interrupt function */
    NVIC_EnableIRQ(SPI0_IRQn);

    /* Enable interrupt type */
    SPI_EnableInt(SPI0, NUCODEGEN_SPI0_INT_SEL);

#endif /* NUCODEGEN_SPI0_INT_EN */

#elif (NUCODEGEN_SPII2S0_MODE==NUCODEGEN_I2S0_MODE)

    /* Enable I2S TX and RX functions */
    SPII2S_Open(SPI0, NUCODEGEN_I2S0_MASTER, NUCODEGEN_I2S0_SAMPLE_RATE, NUCODEGEN_I2S0_DATAWIDTH, NUCODEGEN_I2S0_AUDIO_FORMAT, NUCODEGEN_I2S0_DATA_FORMAT);


#if (NUCODEGEN_I2S0_WIDTH_CONFIG>1)

    /* Set FIFO threshold */
    SPII2S_SetFIFO(SPI0, NUCODEGEN_I2S0_TX_THRESHOLD0, NUCODEGEN_I2S0_RX_THRESHOLD0);

#else

    /* Set FIFO threshold */
    SPII2S_SetFIFO(SPI0, NUCODEGEN_I2S0_TX_THRESHOLD1, NUCODEGEN_I2S0_RX_THRESHOLD1);

#endif /* NUCODEGEN_I2S0_WIDTH_CONFIG */

#if (NUCODEGEN_I2S0_MCLK_EN)

    /* Enable MCLK */
    SPII2S_EnableMCLK(SPI0, NUCODEGEN_I2S0_MCLK);

#endif /* NUCODEGEN_I2S0_MCLK_EN */

#if (NUCODEGEN_I2S0_INT_EN)

    /* Enable interrupt function */
    NVIC_EnableIRQ(SPI0_IRQn);

    /* Enable interrupt type */
    SPII2S_EnableInt(SPI0, NUCODEGEN_I2S0_INT_SEL);

#endif /* NUCODEGEN_I2S0_INT_EN */

#endif //NUCODEGEN_SPII2S0_MODE
}
#endif /* NUCODEGEN_SPII2S0 */
