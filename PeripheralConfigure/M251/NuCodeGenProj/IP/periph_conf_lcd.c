
#if (NUCODEGEN_LCD)
void LCD_Init()
{
    static S_LCD_CFG_T g_LCDCfg =
    {
        /*!< LCD clock source frequency */
        __LIRC,
        /*!< COM duty                   */
        NUCODEGEN_LCDDUTY,
        /*!< BIAS level                 */
        NUCODEGEN_LCDBIAS,
        /*!< Operation frame rate       */
        NUCODEGEN_LCDFRATE,
        /*!< Waveform type              */
        NUCODEGEN_LCDWAVTYPE,
        /*!< Interrupt source           */
        NUCODEGEN_LCDINTEN,
        /*!< Driving mode               */
        NUCODEGEN_LCDDRIVEMODE,
        /*!< Voltage source             */
        NUCODEGEN_LCDPOR,
    };

    /* Output Select */
    LCD_OUTPUT_SET(NUCODEGEN_LCD8OPSEL  | \
NUCODEGEN_LCD9OPSEL  | \
NUCODEGEN_LCD10OPSEL | \
NUCODEGEN_LCD11OPSEL | \
NUCODEGEN_LCD12OPSEL | \
NUCODEGEN_LCD13OPSEL | \
NUCODEGEN_LCD14OPSEL | \
NUCODEGEN_LCD15OPSEL | \
NUCODEGEN_LCD24OPSEL | \
NUCODEGEN_LCD25OPSEL | \
NUCODEGEN_LCD26OPSEL | \
NUCODEGEN_LCD27OPSEL | \
NUCODEGEN_LCD28OPSEL | \
NUCODEGEN_LCD29OPSEL | \
NUCODEGEN_LCD35OPSEL | \
NUCODEGEN_LCD36OPSEL | \
NUCODEGEN_LCD37OPSEL | \
NUCODEGEN_LCD38OPSEL | \
NUCODEGEN_LCD41OPSEL | \
NUCODEGEN_LCD42OPSEL | \
NUCODEGEN_LCD47OPSEL | \
NUCODEGEN_LCD48OPSEL | \
NUCODEGEN_LCD49OPSEL) ;

    /* LCD Initialize and calculate real frame rate */
    LCD_Open(&g_LCDCfg);

    /* Set output voltage */
    LCD_SET_CP_VOLTAGE(NUCODEGEN_LCDCPV);

#if (NUCODEGEN_POWERSAVING)
    /* Set LCD power saving mode */
    LCD_SetSavingMode(NUCODEGEN_POWERSAVINGMODE,NUCODEGEN_POWERSAVINGLEVEL);
#endif /* (NUCODEGEN_POWERSAVING) */

#if ((NUCODEGEN_LCDFEINTEN != 0) || (NUCODEGEN_LCDFCINTEN != 0) || (NUCODEGEN_LCDCPINTEN != 0) )
    /* Enable LCD Interrupt */
    NVIC_EnableIRQ(NUCODEGEN_LCD_IRQ0_MODULE_SEL);
#endif /* ((NUCODEGEN_LCDFEINTEN != 0) || (NUCODEGEN_LCDFCINTEN != 0) || (NUCODEGEN_LCDCPINTEN != 0) ) */

    /* Set frame counting value */
    LCD_SET_FRAME_COUNTING_VALUE(NUCODEGEN_LCDFCV);

#if (NUCODEGEN_LCDBLINK)
    /* Enable blinking function */
    LCD_BLINKING_ON();
#endif /* (NUCODEGEN_LCDBLINK) */

}

#endif /* NUCODEGEN_LCD */
