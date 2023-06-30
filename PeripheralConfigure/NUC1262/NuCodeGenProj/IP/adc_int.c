
#if (NUCODEGEN_ADC)

#if (NUCODEGEN_ADC_COMPAER0_INTERRUPT)
volatile uint32_t g_u32AdcCmp0IntFlag=0;
#endif

#if (NUCODEGEN_ADC_COMPAER1_INTERRUPT)
volatile uint32_t g_u32AdcCmp1IntFlag=0;
#endif

#if (NUCODEGEN_ADC_INTERRUPT)
volatile uint32_t g_u32AdcIntFlag=0;
#endif

void ADC_IRQHandler(void)
{
#if (NUCODEGEN_ADC_COMPAER0_INTERRUPT)
    if(ADC_GET_INT_FLAG(ADC, ADC_CMP0_INT))
    {
        g_u32AdcCmp0IntFlag = 1;
        ADC_CLR_INT_FLAG(ADC, ADC_CMP0_INT);    /* Clear the A/D compare flag 0 */
    }
#endif

#if (NUCODEGEN_ADC_COMPAER1_INTERRUPT)
    if(ADC_GET_INT_FLAG(ADC, ADC_CMP1_INT))
    {
        g_u32AdcCmp1IntFlag = 1;
        ADC_CLR_INT_FLAG(ADC, ADC_CMP1_INT);    /* Clear the A/D compare flag 1 */
    }
#endif

#if (NUCODEGEN_ADC_INTERRUPT)
    g_u32AdcIntFlag = 1;
    ADC_CLR_INT_FLAG(ADC, ADC_ADF_INT);
#endif
}

#endif  /* NUCODEGEN_ADC */
