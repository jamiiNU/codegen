

#if (NUCODEGEN_SPII2S0)
/*--------------------------------------------------------------------------------------------*/
/* SPII2S0                                                                                    */
/*--------------------------------------------------------------------------------------------*/
void SPII2S0_Init()
{
#if (NUCODEGEN_SPII2S0_MODE==NUCODEGEN_SPI0_MODE)

    /* This function make SPI0 module be ready to transfer */
    SPI_Open(SPI0, NUCODEGEN_SPI0_MASTER, NUCODEGEN_SPI0_TIME_MODE, NUCODEGEN_SPI0_DATAWIDTH, NUCODEGEN_SPI0_BUSCLOCK);

#if (NUCODEGEN_SPI0_BYTE_REORDER_EN)

    /* Enable byte reorder function */
    SPI_ENABLE_BYTE_REORDER(SPI0);

#endif /* NUCODEGEN_SPI0_BYTE_REORDER_EN */

#if (NUCODEGEN_SPI0_HALF_DUPLEX_EN)

#if (NUCODEGEN_SPI0_DATA_DIR)

    /* Enable half-duplex function and set data direction as output */
    SPI0->CTL = SPI0->CTL | (SPI_CTL_DATDIR_Msk | SPI_CTL_HALFDPX_Msk);

#else

    /* Enable half-duplex function and set data direction as input */
    SPI0->CTL = (SPI0->CTL & ~SPI_CTL_DATDIR_Msk) | SPI_CTL_HALFDPX_Msk;

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

    /* Set FIFO threshold */
    SPI_SetFIFO(SPI0, NUCODEGEN_SPI0_TX_THRESHOLD, NUCODEGEN_SPI0_RX_THRESHOLD);

#if (NUCODEGEN_SPI0_INT_EN)

    /* Enable interrupt type */
    SPI_EnableInt(SPI0, NUCODEGEN_SPI0_INT_SEL);

    /* Enable interrupt function */
    NVIC_EnableIRQ(SPI0_IRQn);

#endif /* NUCODEGEN_SPI0_INT_EN */

#elif (NUCODEGEN_SPII2S0_MODE==NUCODEGEN_I2S0_MODE)

    /* Enable I2S0 TX and RX functions */
    SPII2S_Open(SPI0, NUCODEGEN_I2S0_MASTER, NUCODEGEN_I2S0_SAMPLE_RATE, NUCODEGEN_I2S0_DATAWIDTH, NUCODEGEN_I2S0_AUDIO_FORMAT, NUCODEGEN_I2S0_DATA_FORMAT);


#if (NUCODEGEN_I2S0_AUDIO_FORMAT==SPII2S_STEREO)

#if (NUCODEGEN_I2S0_DATA_ORDER)

    /* Left channel data at low byte */
    SPI0->I2SCTL = SPI0->I2SCTL | SPI_I2SCTL_ORDER_Msk;

#else

    /* Left channel data at high byte */
    SPI0->I2SCTL &= ~SPI_I2SCTL_ORDER_Msk;

#endif /* NUCODEGEN_I2S0_DATA_ORDER */

#endif

#if (NUCODEGEN_I2S0_AUDIO_FORMAT==SPII2S_MONO)

    /* Set receive channel */
    SPII2S_SET_MONO_RX_CHANNEL(SPI0, NUCODEGEN_I2S0_RECEIVE_CHANNEL);

#endif

    /* Set FIFO threshold */
    SPII2S_SetFIFO(SPI0, NUCODEGEN_I2S0_TX_THRESHOLD, NUCODEGEN_I2S0_RX_THRESHOLD);

#if (NUCODEGEN_I2S0_ZC_EN)

    /* Enable zero cross detection */
    SPI0->I2SCTL |= NUCODEGEN_I2S0_ZC_SEL;

#endif

#if (NUCODEGEN_I2S0_MCLK_EN)

    /* Enable MCLK */
    SPII2S_EnableMCLK(SPI0, NUCODEGEN_I2S0_MCLK);

#endif /* NUCODEGEN_I2S0_MCLK_EN */

#if (NUCODEGEN_I2S0_INT_EN)

    /* Enable interrupt type */
    SPII2S_EnableInt(SPI0, NUCODEGEN_I2S0_INT_SEL);

    /* Enable interrupt function */
    NVIC_EnableIRQ(SPI0_IRQn);

#endif /* NUCODEGEN_I2S0_INT_EN */

#endif  //NUCODEGEN_SPII2S0_MODE
}
#endif  /* NUCODEGEN_SPII2S0 */

#if (NUCODEGEN_SPII2S1)
/*--------------------------------------------------------------------------------------------*/
/* SPII2S1                                                                                    */
/*--------------------------------------------------------------------------------------------*/
void SPII2S1_Init()
{
#if (NUCODEGEN_SPII2S1_MODE==NUCODEGEN_SPI1_MODE)

    /* This function make SPI1 module be ready to transfer */
    SPI_Open(SPI1, NUCODEGEN_SPI1_MASTER, NUCODEGEN_SPI1_TIME_MODE, NUCODEGEN_SPI1_DATAWIDTH, NUCODEGEN_SPI1_BUSCLOCK);

#if (NUCODEGEN_SPI1_BYTE_REORDER_EN)

    /* Enable byte reorder function */
    SPI_ENABLE_BYTE_REORDER(SPI1);

#endif /* NUCODEGEN_SPI1_BYTE_REORDER_EN */

#if (NUCODEGEN_SPI1_HALF_DUPLEX_EN)

#if (NUCODEGEN_SPI1_DATA_DIR)

    /* Enable half-duplex function and set data direction as output */
    SPI1->CTL = SPI1->CTL | (SPI_CTL_DATDIR_Msk | SPI_CTL_HALFDPX_Msk);

#else

    /* Enable half-duplex function and set data direction as input */
    SPI1->CTL = (SPI1->CTL & ~SPI_CTL_DATDIR_Msk) | SPI_CTL_HALFDPX_Msk;

#endif /* NUCODEGEN_SPI1_DATA_DIR */

#endif /* NUCODEGEN_SPI1_HALF_DUPLEX_EN */

#if (NUCODEGEN_SPI1_RECEIVE_ONLY_EN)

    /* Enable receive-only mode */
    SPI1->CTL = SPI1->CTL | SPI_CTL_RXONLY_Msk;

#endif /* NUCODEGEN_SPI1_RECEIVE_ONLY_EN */

#if (NUCODEGEN_SPI1_SS_EN)

    /* SS function enable */
    SPI1->SSCTL = (SPI1->SSCTL & (~SPI_SSCTL_SS_Msk)) | SPI_SSCTL_SS_Msk;

#endif /* NUCODEGEN_SPI1_SS_EN */

#if (NUCODEGEN_SPI1_AUTOSS_EN)

    /* Enable auto SS function */
    SPI1->SSCTL = (SPI1->SSCTL & (~SPI_SSCTL_AUTOSS_Msk)) | SPI_SSCTL_AUTOSS_Msk | SPI_SSCTL_SS_Msk;

#endif /* NUCODEGEN_SPI1_AUTOSS_EN */

    /* Select SS level */
    SPI1->SSCTL = (SPI1->SSCTL & (~SPI_SSCTL_SSACTPOL_Msk)) | NUCODEGEN_SPI1_SS_LEVEL;

#if (NUCODEGEN_SPI1_DATA_ORDER)

    /* Set LSB first */
    SPI_SET_LSB_FIRST(SPI1);

#else

    /* Set MSB first */
    SPI_SET_MSB_FIRST(SPI1);

#endif /* NUCODEGEN_SPI1_DATA_ORDER */

    /* Set FIFO threshold */
    SPI_SetFIFO(SPI1, NUCODEGEN_SPI1_TX_THRESHOLD, NUCODEGEN_SPI1_RX_THRESHOLD);

#if (NUCODEGEN_SPI1_INT_EN)

    /* Enable interrupt type */
    SPI_EnableInt(SPI1, NUCODEGEN_SPI1_INT_SEL);

    /* Enable interrupt function */
    NVIC_EnableIRQ(SPI1_IRQn);

#endif /* NUCODEGEN_SPI1_INT_EN */

#elif (NUCODEGEN_SPII2S1_MODE==NUCODEGEN_I2S1_MODE)

    /* Enable I2S1 TX and RX functions */
    SPII2S_Open(SPI1, NUCODEGEN_I2S1_MASTER, NUCODEGEN_I2S1_SAMPLE_RATE, NUCODEGEN_I2S1_DATAWIDTH, NUCODEGEN_I2S1_AUDIO_FORMAT, NUCODEGEN_I2S1_DATA_FORMAT);


#if (NUCODEGEN_I2S1_AUDIO_FORMAT==SPII2S_STEREO)

#if (NUCODEGEN_I2S1_DATA_ORDER)

    /* Left channel data at low byte */
    SPI1->I2SCTL = SPI1->I2SCTL | SPI_I2SCTL_ORDER_Msk;

#else

    /* Left channel data at high byte */
    SPI1->I2SCTL &= ~SPI_I2SCTL_ORDER_Msk;

#endif /* NUCODEGEN_I2S1_DATA_ORDER */

#endif

#if (NUCODEGEN_I2S1_AUDIO_FORMAT==SPII2S_MONO)

    /* Set receive channel */
    SPII2S_SET_MONO_RX_CHANNEL(SPI1, NUCODEGEN_I2S1_RECEIVE_CHANNEL);

#endif

    /* Set FIFO threshold */
    SPII2S_SetFIFO(SPI1, NUCODEGEN_I2S1_TX_THRESHOLD, NUCODEGEN_I2S1_RX_THRESHOLD);

#if (NUCODEGEN_I2S1_ZC_EN)

    /* Enable zero cross detection */
    SPI1->I2SCTL |= NUCODEGEN_I2S1_ZC_SEL;

#endif

#if (NUCODEGEN_I2S1_MCLK_EN)

    /* Enable MCLK */
    SPII2S_EnableMCLK(SPI1, NUCODEGEN_I2S1_MCLK);

#endif /* NUCODEGEN_I2S1_MCLK_EN */

#if (NUCODEGEN_I2S1_INT_EN)

    /* Enable interrupt type */
    SPII2S_EnableInt(SPI1, NUCODEGEN_I2S1_INT_SEL);

    /* Enable interrupt function */
    NVIC_EnableIRQ(SPI1_IRQn);

#endif /* NUCODEGEN_I2S1_INT_EN */

#endif  //NUCODEGEN_SPII2S1_MODE
}
#endif  /* NUCODEGEN_SPII2S1 */
