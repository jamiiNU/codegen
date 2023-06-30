

#if ((NUCODEGEN_BPWM0) || (NUCODEGEN_BPWM1) || (NUCODEGEN_BPWM2) || (NUCODEGEN_BPWM3))

void BPWM_SetMaskOutput(BPWM_T *bpwm, uint32_t u32ChannelNum, uint32_t u32LevelMask)
{
    (bpwm)->MSKEN |= 0x1<<u32ChannelNum;
    (bpwm)->MSK |= (u32LevelMask<<u32ChannelNum);
}

#endif

#if (NUCODEGEN_BPWM0)
void BPWM0_Init()
{

#if (NUCODEGEN_BPWM0_FUNC_SEL==0)

#if (NUCODEGEN_BPWM0_OUTPUT_FUNC_SETMODE==0)

#if NUCODEGEN_BPWM0_CH0_ENABLE

    /* Set BPWM0 channel 0 configuration */
    BPWM_ConfigOutputChannel(BPWM0, 0, NUCODEGEN_BPWM0_FREQ, NUCODEGEN_BPWM0_CH0_DUTY);

    /* Enable output of BPWM0 channel 0 */
    BPWM_EnableOutput(BPWM0, BPWM_CH_0_MASK);

#endif /*NUCODEGEN_BPWM0_CH0_ENABLE*/

#if NUCODEGEN_BPWM0_CH1_ENABLE

    /* Set BPWM0 channel 1 configuration */
    BPWM_ConfigOutputChannel(BPWM0, 1, NUCODEGEN_BPWM0_FREQ, NUCODEGEN_BPWM0_CH1_DUTY);

    /* Enable output of BPWM0 channel 1 */
    BPWM_EnableOutput(BPWM0, BPWM_CH_1_MASK);

#endif /*NUCODEGEN_BPWM0_CH1_ENABLE*/

#if NUCODEGEN_BPWM0_CH2_ENABLE
    /* Set BPWM0 channel 2 configuration */
    BPWM_ConfigOutputChannel(BPWM0, 2, NUCODEGEN_BPWM0_FREQ, NUCODEGEN_BPWM0_CH2_DUTY);
    /* Enable output of BPWM0 channel 2 */
    BPWM_EnableOutput(BPWM0, BPWM_CH_2_MASK);

#endif /*NUCODEGEN_BPWM0_CH2_ENABLE*/

#if NUCODEGEN_BPWM0_CH3_ENABLE
    /* Set BPWM0 channel 3 configuration */
    BPWM_ConfigOutputChannel(BPWM0, 3, NUCODEGEN_BPWM0_FREQ, NUCODEGEN_BPWM0_CH3_DUTY);
    /* Enable output of BPWM0 channel 3 */
    BPWM_EnableOutput(BPWM0, BPWM_CH_3_MASK);

#endif /*NUCODEGEN_BPWM0_CH3_ENABLE*/

#if NUCODEGEN_BPWM0_CH4_ENABLE
    /* Set BPWM0 channel 4 configuration */
    BPWM_ConfigOutputChannel(BPWM0, 4, NUCODEGEN_BPWM0_FREQ, NUCODEGEN_BPWM0_CH4_DUTY);
    /* Enable output of BPWM0 channel 4 */
    BPWM_EnableOutput(BPWM0, BPWM_CH_4_MASK);


#endif /*NUCODEGEN_BPWM0_CH4_ENABLE*/

#if NUCODEGEN_BPWM0_CH5_ENABLE

    /* Set BPWM0 channel 5 configuration */
    BPWM_ConfigOutputChannel(BPWM0, 5, NUCODEGEN_BPWM0_FREQ, NUCODEGEN_BPWM0_CH5_DUTY);

    /* Enable output of BPWM0 channel 5 */
    BPWM_EnableOutput(BPWM0, BPWM_CH_5_MASK);

#endif /*NUCODEGEN_BPWM0_CH5_ENABLE*/

#else

    /* Set BPWM0 clock source */
    BPWM_SetClockSource(BPWM0, 0, NUCODEGEN_BPWM0_CLKSRC);

    /* Set BPWM0 counter behavior type */
    BPWM_SET_ALIGNED_TYPE(BPWM0, BPWM_CH_0_MASK, NUCODEGEN_BPWM0_CNTTYPE);

    /* Set the prescaler of BPWM0  */
    BPWM_SET_PRESCALER(BPWM0, 0,NUCODEGEN_BPWM0_PRESCALER);

    /* Set the period of BPWM0 */
    BPWM_SET_CNR(BPWM0, 0, NUCODEGEN_BPWM0_PERIOD);

#if NUCODEGEN_BPWM0_SYNCSTART_ENABLE

    /* Enable timer synchronous start counting function */
    BPWM_ENABLE_TIMER_SYNC(BPWM0, BIT0, NUCODEGEN_BPWM0_SYNCSTART_SRC) ;

#endif /*NUCODEGEN_BPWM0_SYNCSTART_ENABLE*/

#if (((NUCODEGEN_BPWM0_CH0_INT_SEL) & 1)||((NUCODEGEN_BPWM0_CH1_INT_SEL) & 1)||((NUCODEGEN_BPWM0_CH2_INT_SEL) & 1)||((NUCODEGEN_BPWM0_CH3_INT_SEL) & 1)||((NUCODEGEN_BPWM0_CH4_INT_SEL) & 1)||((NUCODEGEN_BPWM0_CH5_INT_SEL) & 1))

    /* Enable zero interrupt - BPWM0 has only one controller  */
    BPWM_EnableZeroInt(BPWM0, 0) ;

#endif

#if (((NUCODEGEN_BPWM0_CH0_INT_SEL) & 2)||((NUCODEGEN_BPWM0_CH1_INT_SEL) & 2)||((NUCODEGEN_BPWM0_CH2_INT_SEL) & 2)||((NUCODEGEN_BPWM0_CH3_INT_SEL) & 2)||((NUCODEGEN_BPWM0_CH4_INT_SEL) & 2)||((NUCODEGEN_BPWM0_CH5_INT_SEL) & 2))

    /* Enable period interrupt - BPWM0 has only one controller  */
    BPWM_EnablePeriodInt(BPWM0, 0, 0) ;

#endif

#if NUCODEGEN_BPWM0_CH0_ENABLE

    /* Set the duty of BPWM0 CH0*/
    BPWM_SET_CMR(BPWM0, 0, NUCODEGEN_BPWM0_CH0_CMPDATA);

    /* Set output level of BPWM0 CH0*/
    BPWM_SET_OUTPUT_LEVEL(BPWM0, BIT0, NUCODEGEN_BPWM0_CH0_WAVEOUT_ZERO, NUCODEGEN_BPWM0_CH0_WAVEOUT_CMPUP, NUCODEGEN_BPWM0_CH0_WAVEOUT_PERIOD, NUCODEGEN_BPWM0_CH0_WAVEOUT_CMPDOWN);

    /* Enable output of BPWM0 channel 0 */
    BPWM_EnableOutput(BPWM0, BPWM_CH_0_MASK);

#if NUCODEGEN_BPWM0_CH0_ADVANCED

#if (NUCODEGEN_BPWM0_CH0_LOAD_MODE == 0)

    /* Period loading mode*/
    BPWM_DisableLoadMode(BPWM0, 0, BPWM_LOAD_MODE_IMMEDIATE|BPWM_LOAD_MODE_CENTER) ;

#elif (NUCODEGEN_BPWM0_CH0_LOAD_MODE == 1)

    /*Immediate loading mode*/
    BPWM_EnableLoadMode(BPWM0, 0, BPWM_LOAD_MODE_IMMEDIATE) ;

#elif (NUCODEGEN_BPWM0_CH0_LOAD_MODE == 2)

    /*Center loading mode*/
    BPWM_EnableLoadMode(BPWM0, 0, BPWM_LOAD_MODE_CENTER) ;

#endif /*NUCODEGEN_BPWM0_CH0_LOAD_MODE*/

#if (NUCODEGEN_BPWM0_CH0_OTHER_OUTPUT==1)

    /* Enable mask output and output high or low*/
    BPWM_SetMaskOutput(BPWM0, 0, NUCODEGEN_BPWM0_CH0_MASK_DATA);

#elif (NUCODEGEN_BPWM0_CH0_OTHER_OUTPUT==2)

    /* Enable inverter output */
    BPWM0->POLCTL |= BPWM_CH_0_MASK ;

#endif /*NUCODEGEN_BPWM0_CH0_OTHER_OUTPUT*/

#if NUCODEGEN_BPWM0_CH0_TRIGER_ADC_ENABLE

    /* Set trigger ADC and trigger source*/
    BPWM_EnableADCTrigger(BPWM0, 0, NUCODEGEN_BPWM0_CH0_TRIGER_ADCSRC) ;

#endif /*NUCODEGEN_BPWM0_CH0_TRIGER_ADC_ENABLE*/

#if ((NUCODEGEN_BPWM0_CH0_INT_SEL) & 4)

    /* Enable duty interrupt - count up interrupt */
    BPWM_EnableDutyInt(BPWM0, 0, BPWM_DUTY_INT_UP_COUNT_MATCH_CMP) ;

#endif /*(NUCODEGEN_BPWM0_CH0_INT_SEL)*/

#if ((NUCODEGEN_BPWM0_CH0_INT_SEL) & 8)

    /* Enable duty interrupt - count down interrupt */
    BPWM_EnableDutyInt(BPWM0, 0, BPWM_DUTY_INT_DOWN_COUNT_MATCH_CMP) ;

#endif /*NUCODEGEN_BPWM0_CH0_INT_SEL*/

#endif /*NUCODEGEN_BPWM0_CH0_ADVANCED*/

#endif /*NUCODEGEN_BPWM0_CH0_ENABLE*/

#if NUCODEGEN_BPWM0_CH1_ENABLE

    /* Set the duty of BPWM0 CH1*/
    BPWM_SET_CMR(BPWM0, 1, NUCODEGEN_BPWM0_CH1_CMPDATA);

    /* Set output level of BPWM0 CH1*/
    BPWM_SET_OUTPUT_LEVEL(BPWM0, BIT1, NUCODEGEN_BPWM0_CH1_WAVEOUT_ZERO, NUCODEGEN_BPWM0_CH1_WAVEOUT_CMPUP, NUCODEGEN_BPWM0_CH1_WAVEOUT_PERIOD, NUCODEGEN_BPWM0_CH1_WAVEOUT_CMPDOWN);

    /* Enable output of BPWM0 channel 1 */
    BPWM_EnableOutput(BPWM0, BPWM_CH_1_MASK);

#if NUCODEGEN_BPWM0_CH1_ADVANCED

#if (NUCODEGEN_BPWM0_CH1_LOAD_MODE == 0)

    /* Period loading mode*/
    BPWM_DisableLoadMode(BPWM0, 1, BPWM_LOAD_MODE_IMMEDIATE|BPWM_LOAD_MODE_CENTER) ;

#elif (NUCODEGEN_BPWM0_CH1_LOAD_MODE == 1)

    /*Immediate loading mode*/
    BPWM_EnableLoadMode(BPWM0, 1, BPWM_LOAD_MODE_IMMEDIATE) ;

#elif (NUCODEGEN_BPWM0_CH1_LOAD_MODE == 2)

    /*Center loading mode*/
    BPWM_EnableLoadMode(BPWM0, 1, BPWM_LOAD_MODE_CENTER) ;

#endif /*NUCODEGEN_BPWM0_CH1_LOAD_MODE*/

#if (NUCODEGEN_BPWM0_CH1_OTHER_OUTPUT==1)

    /* Enable mask output and output high or low*/
    BPWM_SetMaskOutput(BPWM0, 1, NUCODEGEN_BPWM0_CH1_MASK_DATA);

#elif (NUCODEGEN_BPWM0_CH1_OTHER_OUTPUT==2)

    /* Enable inverter output */
    BPWM0->POLCTL |= BPWM_CH_1_MASK ;

#endif /*NUCODEGEN_BPWM0_CH1_OTHER_OUTPUT*/

#if NUCODEGEN_BPWM0_CH1_TRIGER_ADC_ENABLE

    /* Set trigger ADC and trigger source*/
    BPWM_EnableADCTrigger(BPWM0, 1, NUCODEGEN_BPWM0_CH1_TRIGER_ADCSRC) ;

#endif /*NUCODEGEN_BPWM0_CH1_TRIGER_ADC_ENABLE*/

#if ((NUCODEGEN_BPWM0_CH1_INT_SEL) & 4)

    /* Enable duty interrupt - count up interrupt */
    BPWM_EnableDutyInt(BPWM0, 1, BPWM_DUTY_INT_UP_COUNT_MATCH_CMP) ;

#endif /*NUCODEGEN_BPWM0_CH1_INT_SEL*/

#if ((NUCODEGEN_BPWM0_CH1_INT_SEL) & 8)

    /* Enable duty interrupt - count down interrupt */
    BPWM_EnableDutyInt(BPWM0, 1, BPWM_DUTY_INT_DOWN_COUNT_MATCH_CMP) ;

#endif /*NUCODEGEN_BPWM0_CH1_INT_SEL*/

#endif /*NUCODEGEN_BPWM0_CH1_ADVANCED*/

#endif /*NUCODEGEN_BPWM0_CH1_ENABLE*/

#if NUCODEGEN_BPWM0_CH2_ENABLE

    /* Set the duty of BPWM0 CH2*/
    BPWM_SET_CMR(BPWM0, 2, NUCODEGEN_BPWM0_CH2_CMPDATA);

    /* Set output level of BPWM0 CH2*/
    BPWM_SET_OUTPUT_LEVEL(BPWM0, BIT2, NUCODEGEN_BPWM0_CH2_WAVEOUT_ZERO, NUCODEGEN_BPWM0_CH2_WAVEOUT_CMPUP, NUCODEGEN_BPWM0_CH2_WAVEOUT_PERIOD, NUCODEGEN_BPWM0_CH2_WAVEOUT_CMPDOWN);

    /* Enable output of BPWM0 channel 2 */
    BPWM_EnableOutput(BPWM0, BPWM_CH_2_MASK);

#if NUCODEGEN_BPWM0_CH2_ADVANCED

#if (NUCODEGEN_BPWM0_CH2_LOAD_MODE == 0)

    /* Period loading mode*/
    BPWM_DisableLoadMode(BPWM0, 2, BPWM_LOAD_MODE_IMMEDIATE|BPWM_LOAD_MODE_CENTER) ;

#elif (NUCODEGEN_BPWM0_CH2_LOAD_MODE == 1)

    /*Immediate loading mode*/
    BPWM_EnableLoadMode(BPWM0, 2, BPWM_LOAD_MODE_IMMEDIATE) ;

#elif (NUCODEGEN_BPWM0_CH2_LOAD_MODE == 2)

    /*Center loading mode*/
    BPWM_EnableLoadMode(BPWM0, 2, BPWM_LOAD_MODE_CENTER) ;

#endif /*NUCODEGEN_BPWM0_CH2_LOAD_MODE*/

#if (NUCODEGEN_BPWM0_CH2_OTHER_OUTPUT==1)

    /* Enable mask output and output high or low*/
    BPWM_SetMaskOutput(BPWM0, 2, NUCODEGEN_BPWM0_CH2_MASK_DATA);

#elif (NUCODEGEN_BPWM0_CH2_OTHER_OUTPUT==2)

    /* Enable inverter output */
    BPWM0->POLCTL |= BPWM_CH_2_MASK ;

#endif /*NUCODEGEN_BPWM0_CH2_OTHER_OUTPUT*/

#if NUCODEGEN_BPWM0_CH2_TRIGER_ADC_ENABLE

    /* Set trigger ADC and trigger source*/
    BPWM_EnableADCTrigger(BPWM0, 2, NUCODEGEN_BPWM0_CH2_TRIGER_ADCSRC) ;

#endif /*NUCODEGEN_BPWM0_CH2_TRIGER_ADC_ENABLE*/

#if ((NUCODEGEN_BPWM0_CH2_INT_SEL) & 4)

    /* Enable duty interrupt - count up interrupt */
    BPWM_EnableDutyInt(BPWM0, 2, BPWM_DUTY_INT_UP_COUNT_MATCH_CMP) ;

#endif /*NUCODEGEN_BPWM0_CH2_INT_SEL*/

#if ((NUCODEGEN_BPWM0_CH2_INT_SEL) & 8)

    /* Enable duty interrupt - count down interrupt */
    BPWM_EnableDutyInt(BPWM0, 2, BPWM_DUTY_INT_DOWN_COUNT_MATCH_CMP) ;

#endif /*NUCODEGEN_BPWM0_CH2_INT_SEL*/

#endif /*NUCODEGEN_BPWM0_CH2_ADVANCED*/

#endif /*NUCODEGEN_BPWM0_CH2_ENABLE*/

#if NUCODEGEN_BPWM0_CH3_ENABLE

    /* Set the duty of BPWM0 CH3*/
    BPWM_SET_CMR(BPWM0, 3, NUCODEGEN_BPWM0_CH3_CMPDATA);

    /* Set output level of BPWM0 CH3*/
    BPWM_SET_OUTPUT_LEVEL(BPWM0, BIT3, NUCODEGEN_BPWM0_CH3_WAVEOUT_ZERO, NUCODEGEN_BPWM0_CH3_WAVEOUT_CMPUP, NUCODEGEN_BPWM0_CH3_WAVEOUT_PERIOD, NUCODEGEN_BPWM0_CH3_WAVEOUT_CMPDOWN);

    /* Enable output of BPWM0 channel 3 */
    BPWM_EnableOutput(BPWM0, BPWM_CH_3_MASK);

#if NUCODEGEN_BPWM0_CH3_ADVANCED

#if (NUCODEGEN_BPWM0_CH3_LOAD_MODE == 0)

    /* Period loading mode*/
    BPWM_DisableLoadMode(BPWM0, 3, BPWM_LOAD_MODE_IMMEDIATE|BPWM_LOAD_MODE_CENTER) ;

#elif (NUCODEGEN_BPWM0_CH3_LOAD_MODE == 1)

    /*Immediate loading mode*/
    BPWM_EnableLoadMode(BPWM0, 3, BPWM_LOAD_MODE_IMMEDIATE) ;

#elif (NUCODEGEN_BPWM0_CH3_LOAD_MODE == 2)

    /*Center loading mode*/
    BPWM_EnableLoadMode(BPWM0, 3, BPWM_LOAD_MODE_CENTER) ;

#endif /*NUCODEGEN_BPWM0_CH3_LOAD_MODE*/

#if (NUCODEGEN_BPWM0_CH3_OTHER_OUTPUT==1)

    /* Enable mask output and output high or low*/
    BPWM_SetMaskOutput(BPWM0, 3, NUCODEGEN_BPWM0_CH3_MASK_DATA);

#elif (NUCODEGEN_BPWM0_CH3_OTHER_OUTPUT==2)

    /* Enable inverter output */
    BPWM0->POLCTL |= BPWM_CH_3_MASK;

#endif /*NUCODEGEN_BPWM0_CH3_OTHER_OUTPUT*/

#if NUCODEGEN_BPWM0_CH3_TRIGER_ADC_ENABLE

    /* Set trigger ADC and trigger source*/
    BPWM_EnableADCTrigger(BPWM0, 3, NUCODEGEN_BPWM0_CH3_TRIGER_ADCSRC) ;

#endif /*NUCODEGEN_BPWM0_CH3_TRIGER_ADC_ENABLE*/

#if ((NUCODEGEN_BPWM0_CH3_INT_SEL) & 4)

    /* Enable duty interrupt - count up interrupt */
    BPWM_EnableDutyInt(BPWM0, 3, BPWM_DUTY_INT_UP_COUNT_MATCH_CMP) ;

#endif /*NUCODEGEN_BPWM0_CH3_INT_SEL*/

#if ((NUCODEGEN_BPWM0_CH3_INT_SEL) & 8)

    /* Enable duty interrupt - count down interrupt */
    BPWM_EnableDutyInt(BPWM0, 3, BPWM_DUTY_INT_DOWN_COUNT_MATCH_CMP) ;

#endif /*NUCODEGEN_BPWM0_CH3_INT_SEL*/

#endif /*NUCODEGEN_BPWM0_CH3_ADVANCED*/

#endif /*NUCODEGEN_BPWM0_CH3_ENABLE*/

#if NUCODEGEN_BPWM0_CH4_ENABLE

    /* Set the duty of BPWM0 CH4*/
    BPWM_SET_CMR(BPWM0, 4, NUCODEGEN_BPWM0_CH4_CMPDATA);

    /* Set output level of BPWM0 CH4*/
    BPWM_SET_OUTPUT_LEVEL(BPWM0, BIT4, NUCODEGEN_BPWM0_CH4_WAVEOUT_ZERO, NUCODEGEN_BPWM0_CH4_WAVEOUT_CMPUP, NUCODEGEN_BPWM0_CH4_WAVEOUT_PERIOD, NUCODEGEN_BPWM0_CH4_WAVEOUT_CMPDOWN);

    /* Enable output of BPWM0 channel 4 */
    BPWM_EnableOutput(BPWM0, BPWM_CH_4_MASK);

#if NUCODEGEN_BPWM0_CH4_ADVANCED

#if (NUCODEGEN_BPWM0_CH4_LOAD_MODE == 0)

    /* Period loading mode*/
    BPWM_DisableLoadMode(BPWM0, 4, BPWM_LOAD_MODE_IMMEDIATE|BPWM_LOAD_MODE_CENTER) ;

#elif (NUCODEGEN_BPWM0_CH4_LOAD_MODE == 1)

    /*Immediate loading mode*/
    BPWM_EnableLoadMode(BPWM0, 4, BPWM_LOAD_MODE_IMMEDIATE) ;

#elif (NUCODEGEN_BPWM0_CH4_LOAD_MODE == 2)

    /*Center loading mode*/
    BPWM_EnableLoadMode(BPWM0, 4, BPWM_LOAD_MODE_CENTER) ;

#endif /*NUCODEGEN_BPWM0_CH4_LOAD_MODE*/

#if (NUCODEGEN_BPWM0_CH4_OTHER_OUTPUT==1)

    /* Enable mask output and output high or low*/
    BPWM_SetMaskOutput(BPWM0, 4, NUCODEGEN_BPWM0_CH4_MASK_DATA);

#elif (NUCODEGEN_BPWM0_CH4_OTHER_OUTPUT==2)

    /* Enable inverter output */
    BPWM0->POLCTL |= BPWM_CH_4_MASK;

#endif /*NUCODEGEN_BPWM0_CH4_OTHER_OUTPUT*/

#if NUCODEGEN_BPWM0_CH4_TRIGER_ADC_ENABLE

    /* Set trigger ADC and trigger source*/
    BPWM_EnableADCTrigger(BPWM0, 4, NUCODEGEN_BPWM0_CH4_TRIGER_ADCSRC) ;

#endif /*NUCODEGEN_BPWM0_CH4_TRIGER_ADC_ENABLE*/

#if ((NUCODEGEN_BPWM0_CH4_INT_SEL) & 4)

    /* Enable duty interrupt - count up interrupt */
    BPWM_EnableDutyInt(BPWM0, 4, BPWM_DUTY_INT_UP_COUNT_MATCH_CMP) ;

#endif /*NUCODEGEN_BPWM0_CH4_INT_SEL*/

#if ((NUCODEGEN_BPWM0_CH4_INT_SEL) & 8)

    /* Enable duty interrupt - count down interrupt */
    BPWM_EnableDutyInt(BPWM0, 4, BPWM_DUTY_INT_DOWN_COUNT_MATCH_CMP) ;

#endif /*NUCODEGEN_BPWM0_CH4_INT_SEL*/

#endif /*NUCODEGEN_BPWM0_CH4_ADVANCED*/

#endif /*NUCODEGEN_BPWM0_CH4_ENABLE*/

#if NUCODEGEN_BPWM0_CH5_ENABLE

    /* Set the duty of BPWM0 CH5*/
    BPWM_SET_CMR(BPWM0, 5, NUCODEGEN_BPWM0_CH5_CMPDATA);

    /* Set output level of BPWM0 CH5*/
    BPWM_SET_OUTPUT_LEVEL(BPWM0, BIT5, NUCODEGEN_BPWM0_CH5_WAVEOUT_ZERO, NUCODEGEN_BPWM0_CH5_WAVEOUT_CMPUP, NUCODEGEN_BPWM0_CH5_WAVEOUT_PERIOD, NUCODEGEN_BPWM0_CH5_WAVEOUT_CMPDOWN);

    /* Enable output of BPWM0 channel 5 */
    BPWM_EnableOutput(BPWM0, BPWM_CH_5_MASK);

#if NUCODEGEN_BPWM0_CH5_ADVANCED

#if (NUCODEGEN_BPWM0_CH5_LOAD_MODE == 0)

    /* Period loading mode*/
    BPWM_DisableLoadMode(BPWM0, 5, BPWM_LOAD_MODE_IMMEDIATE|BPWM_LOAD_MODE_CENTER) ;

#elif (NUCODEGEN_BPWM0_CH5_LOAD_MODE == 1)

    /*Immediate loading mode*/
    BPWM_EnableLoadMode(BPWM0, 5, BPWM_LOAD_MODE_IMMEDIATE) ;

#elif (NUCODEGEN_BPWM0_CH5_LOAD_MODE == 2)

    /*Center loading mode*/
    BPWM_EnableLoadMode(BPWM0, 5, BPWM_LOAD_MODE_CENTER) ;

#endif /*NUCODEGEN_BPWM0_CH5_LOAD_MODE*/

#if (NUCODEGEN_BPWM0_CH5_OTHER_OUTPUT==1)

    /* Enable mask output and output high or low*/
    BPWM_SetMaskOutput(BPWM0, 5, NUCODEGEN_BPWM0_CH5_MASK_DATA);

#elif (NUCODEGEN_BPWM0_CH5_OTHER_OUTPUT==2)

    /* Enable inverter output */
    BPWM0->POLCTL |= BPWM_CH_5_MASK;

#endif /*NUCODEGEN_BPWM0_CH5_OTHER_OUTPUT*/

#if NUCODEGEN_BPWM0_CH5_TRIGER_ADC_ENABLE

    /* Set trigger ADC and trigger source*/
    BPWM_EnableADCTrigger(BPWM0, 5, NUCODEGEN_BPWM0_CH5_TRIGER_ADCSRC) ;

#endif /*NUCODEGEN_BPWM0_CH5_TRIGER_ADC_ENABLE*/

#if (((NUCODEGEN_BPWM0_CH5_INT_SEL) & 4))

    /* Enable duty interrupt - count up interrupt */
    BPWM_EnableDutyInt(BPWM0, 5, BPWM_DUTY_INT_UP_COUNT_MATCH_CMP) ;

#endif /*NUCODEGEN_BPWM0_CH5_INT_SEL*/

#if (((NUCODEGEN_BPWM0_CH5_INT_SEL) & 8))

    /* Enable duty interrupt - count down interrupt */
    BPWM_EnableDutyInt(BPWM0, 5, BPWM_DUTY_INT_DOWN_COUNT_MATCH_CMP) ;

#endif /*NUCODEGEN_BPWM0_CH5_INT_SEL*/

#endif /*NUCODEGEN_BPWM0_CH5_ADVANCED*/

#endif /*NUCODEGEN_BPWM0_CH5_ENABLE*/


#endif /*NUCODEGEN_BPWM0_OUTPUT_FUNC_SETMODE*/

#else

    /* Configure BPWM capture and get the nearest unit time */
    BPWM_ConfigCaptureChannel(BPWM0, 0, NUCODEGEN_BPWM0_CAP_UNITTIME, 0);

#if NUCODEGEN_BPWM0_CH0_CAP_ENABLE

    /* Set Reload Mode */
    BPWM0->CAPCTL |= (NUCODEGEN_BPWM0_CH0_CAP_RELOAD)<<BPWM_CAPCTL_RCRLDEN0_Pos;

    /* Enable Capture Function for BPWM0 channel 0 */
    BPWM_EnableCapture(BPWM0, BPWM_CH_0_MASK);

#if NUCODEGEN_BPWM0_CH0_CAP_ADVANCED

#if (NUCODEGEN_BPWM0_CH0_CAP_INT_SEL == 1)

    /*Enable rising latch capture interrupt*/
    BPWM_EnableCaptureInt(BPWM0, 0, BPWM_CAPTURE_INT_RISING_LATCH) ;

#elif (NUCODEGEN_BPWM0_CH0_CAP_INT_SEL == 2)

    /*Enable falling latch capture interrupt*/
    BPWM_EnableCaptureInt(BPWM0, 0, BPWM_CAPTURE_INT_FALLING_LATCH) ;

#elif (NUCODEGEN_BPWM0_CH0_CAP_INT_SEL == 3)

    /*Enable rising and falling latch capture interrupt*/
    BPWM_EnableCaptureInt(BPWM0, 0, BPWM_CAPTURE_INT_RISING_LATCH|BPWM_CAPTURE_INT_FALLING_LATCH) ;

#endif /*NUCODEGEN_BPWM0_CH0_CAP_INT_SEL*/

#endif /*NUCODEGEN_BPWM0_CH0_CAP_ADVANCED*/

#endif /*NUCODEGEN_BPWM0_CH0_CAP_ENABLE*/

#if NUCODEGEN_BPWM0_CH1_CAP_ENABLE

    /* Set Reload Mode */
    BPWM0->CAPCTL |= (NUCODEGEN_BPWM0_CH1_CAP_RELOAD)<<BPWM_CAPCTL_RCRLDEN1_Pos;

    /* Enable Timer for BPWM0 channel 1 */
    BPWM_Start(BPWM0, BPWM_CH_1_MASK);

    /* Enable Capture Function for BPWM0 channel 1 */
    BPWM_EnableCapture(BPWM0, BPWM_CH_1_MASK);

#if NUCODEGEN_BPWM0_CH1_CAP_ADVANCED

#if (NUCODEGEN_BPWM0_CH1_CAP_INT_SEL == 1)

    /*Enable rising latch capture interrupt*/
    BPWM_EnableCaptureInt(BPWM0, 1, BPWM_CAPTURE_INT_RISING_LATCH) ;

#elif (NUCODEGEN_BPWM0_CH1_CAP_INT_SEL == 2)

    /*Enable falling latch capture interrupt*/
    BPWM_EnableCaptureInt(BPWM0, 1, BPWM_CAPTURE_INT_FALLING_LATCH) ;

#elif (NUCODEGEN_BPWM0_CH1_CAP_INT_SEL == 3)

    /*Enable rising and falling latch capture interrupt*/
    BPWM_EnableCaptureInt(BPWM0, 1, BPWM_CAPTURE_INT_RISING_LATCH|BPWM_CAPTURE_INT_FALLING_LATCH) ;

#endif /*NUCODEGEN_BPWM0_CH1_CAP_INT_SEL*/

#endif /*NUCODEGEN_BPWM0_CH1_CAP_ADVANCED*/

#endif /*NUCODEGEN_BPWM0_CH1_CAP_ENABLE*/

#if NUCODEGEN_BPWM0_CH2_CAP_ENABLE

    /* Set Reload Mode */
    BPWM0->CAPCTL |= (NUCODEGEN_BPWM0_CH2_CAP_RELOAD)<<BPWM_CAPCTL_RCRLDEN2_Pos;

    /* Enable Capture Function for BPWM0 channel 2 */
    BPWM_EnableCapture(BPWM0, BPWM_CH_2_MASK);

#if NUCODEGEN_BPWM0_CH2_CAP_ADVANCED

#if (NUCODEGEN_BPWM0_CH2_CAP_INT_SEL == 1)

    /*Enable rising latch capture interrupt*/
    BPWM_EnableCaptureInt(BPWM0, 2, BPWM_CAPTURE_INT_RISING_LATCH) ;

#elif (NUCODEGEN_BPWM0_CH2_CAP_INT_SEL == 2)

    /*Enable falling latch capture interrupt*/
    BPWM_EnableCaptureInt(BPWM0, 2, BPWM_CAPTURE_INT_FALLING_LATCH) ;

#elif (NUCODEGEN_BPWM0_CH2_CAP_INT_SEL == 3)

    /*Enable rising and falling latch capture interrupt*/
    BPWM_EnableCaptureInt(BPWM0, 2, BPWM_CAPTURE_INT_RISING_LATCH|BPWM_CAPTURE_INT_FALLING_LATCH) ;

#endif /*NUCODEGEN_BPWM0_CH2_CAP_INT_SEL*/

#endif /*NUCODEGEN_BPWM0_CH2_CAP_ADVANCED*/

#endif /*NUCODEGEN_BPWM0_CH2_CAP_ENABLE*/

#if NUCODEGEN_BPWM0_CH3_CAP_ENABLE

    /* Set Reload Mode */
    BPWM0->CAPCTL |= (NUCODEGEN_BPWM0_CH3_CAP_RELOAD)<<BPWM_CAPCTL_RCRLDEN3_Pos;

    /* Enable Capture Function for BPWM0 channel 3 */
    BPWM_EnableCapture(BPWM0, BPWM_CH_3_MASK);

#if NUCODEGEN_BPWM0_CH3_CAP_ADVANCED

#if (NUCODEGEN_BPWM0_CH3_CAP_INT_SEL == 1)

    /*Enable rising latch capture interrupt*/
    BPWM_EnableCaptureInt(BPWM0, 3, BPWM_CAPTURE_INT_RISING_LATCH) ;

#elif (NUCODEGEN_BPWM0_CH3_CAP_INT_SEL == 2)

    /*Enable falling latch capture interrupt*/
    BPWM_EnableCaptureInt(BPWM0, 3, BPWM_CAPTURE_INT_FALLING_LATCH) ;

#elif (NUCODEGEN_BPWM0_CH3_CAP_INT_SEL == 3)

    /*Enable rising and falling latch capture interrupt*/
    BPWM_EnableCaptureInt(BPWM0, 3, BPWM_CAPTURE_INT_RISING_LATCH|BPWM_CAPTURE_INT_FALLING_LATCH) ;

#endif /*NUCODEGEN_BPWM0_CH3_CAP_INT_SEL*/

#endif /*NUCODEGEN_BPWM0_CH3_CAP_ADVANCED*/

#endif /*NUCODEGEN_BPWM0_CH3_CAP_ENABLE*/

#if NUCODEGEN_BPWM0_CH4_CAP_ENABLE

    /* Set Reload Mode */
    BPWM0->CAPCTL |= (NUCODEGEN_BPWM0_CH4_CAP_RELOAD)<<BPWM_CAPCTL_RCRLDEN4_Pos;

    /* Enable Capture Function for BPWM0 channel 4 */
    BPWM_EnableCapture(BPWM0, BPWM_CH_4_MASK);

#if NUCODEGEN_BPWM0_CH4_CAP_ADVANCED

#if (NUCODEGEN_BPWM0_CH4_CAP_INT_SEL == 1)

    /*Enable rising latch capture interrupt*/
    BPWM_EnableCaptureInt(BPWM0, 4, BPWM_CAPTURE_INT_RISING_LATCH) ;

#elif (NUCODEGEN_BPWM0_CH4_CAP_INT_SEL == 2)

    /*Enable falling latch capture interrupt*/
    BPWM_EnableCaptureInt(BPWM0, 4, BPWM_CAPTURE_INT_FALLING_LATCH) ;

#elif (NUCODEGEN_BPWM0_CH4_CAP_INT_SEL == 3)

    /*Enable rising and falling latch capture interrupt*/
    BPWM_EnableCaptureInt(BPWM0, 4, BPWM_CAPTURE_INT_RISING_LATCH|BPWM_CAPTURE_INT_FALLING_LATCH) ;

#endif /*NUCODEGEN_BPWM0_CH4_CAP_INT_SEL*/

#endif /*NUCODEGEN_BPWM0_CH4_CAP_ADVANCED*/

#endif /*NUCODEGEN_BPWM0_CH4_CAP_ENABLE*/

#if NUCODEGEN_BPWM0_CH5_CAP_ENABLE

    /* Set Reload Mode */
    BPWM0->CAPCTL |= (NUCODEGEN_BPWM0_CH5_CAP_RELOAD)<<BPWM_CAPCTL_RCRLDEN5_Pos;

    /* Enable Capture Function for BPWM0 channel 5 */
    BPWM_EnableCapture(BPWM0, BPWM_CH_5_MASK);

#if NUCODEGEN_BPWM0_CH5_CAP_ADVANCED

#if (NUCODEGEN_BPWM0_CH5_CAP_INT_SEL == 1)

    /*Enable rising latch capture interrupt*/
    BPWM_EnableCaptureInt(BPWM0, 5, BPWM_CAPTURE_INT_RISING_LATCH) ;

#elif (NUCODEGEN_BPWM0_CH5_CAP_INT_SEL == 2)

    /*Enable falling latch capture interrupt*/
    BPWM_EnableCaptureInt(BPWM0, 5, BPWM_CAPTURE_INT_FALLING_LATCH) ;

#elif (NUCODEGEN_BPWM0_CH5_CAP_INT_SEL == 3)

    /*Enable rising and falling latch capture interrupt*/
    BPWM_EnableCaptureInt(BPWM0, 5, BPWM_CAPTURE_INT_RISING_LATCH|BPWM_CAPTURE_INT_FALLING_LATCH) ;

#endif /*NUCODEGEN_BPWM0_CH5_CAP_INT_SEL*/

#endif /*NUCODEGEN_BPWM0_CH5_CAP_ADVANCED*/

#endif /*NUCODEGEN_BPWM0_CH5_CAP_ENABLE*/

#endif /*NUCODEGEN_BPWM0_FUNC_SEL*/

}

#endif //NUCODEGEN_BPWM0

#if (NUCODEGEN_BPWM1)
void BPWM1_Init()
{

#if (NUCODEGEN_BPWM1_FUNC_SEL==0)

#if (NUCODEGEN_BPWM1_OUTPUT_FUNC_SETMODE==0)

#if NUCODEGEN_BPWM1_CH0_ENABLE

    /* Set BPWM1 channel 0 configuration */
    BPWM_ConfigOutputChannel(BPWM1, 0, NUCODEGEN_BPWM1_FREQ, NUCODEGEN_BPWM1_CH0_DUTY);

    /* Enable output of BPWM1 channel 0 */
    BPWM_EnableOutput(BPWM1, BPWM_CH_0_MASK);

#endif /*NUCODEGEN_BPWM1_CH0_ENABLE*/

#if NUCODEGEN_BPWM1_CH1_ENABLE

    /* Set BPWM1 channel 1 configuration */
    BPWM_ConfigOutputChannel(BPWM1, 1, NUCODEGEN_BPWM1_FREQ, NUCODEGEN_BPWM1_CH1_DUTY);

    /* Enable output of BPWM1 channel 1 */
    BPWM_EnableOutput(BPWM1, BPWM_CH_1_MASK);

#endif /*NUCODEGEN_BPWM1_CH1_ENABLE*/

#if NUCODEGEN_BPWM1_CH2_ENABLE
    /* Set BPWM1 channel 2 configuration */
    BPWM_ConfigOutputChannel(BPWM1, 2, NUCODEGEN_BPWM1_FREQ, NUCODEGEN_BPWM1_CH2_DUTY);
    /* Enable output of BPWM1 channel 2 */
    BPWM_EnableOutput(BPWM1, BPWM_CH_2_MASK);

#endif /*NUCODEGEN_BPWM1_CH2_ENABLE*/

#if NUCODEGEN_BPWM1_CH3_ENABLE
    /* Set BPWM1 channel 3 configuration */
    BPWM_ConfigOutputChannel(BPWM1, 3, NUCODEGEN_BPWM1_FREQ, NUCODEGEN_BPWM1_CH3_DUTY);
    /* Enable output of BPWM1 channel 3 */
    BPWM_EnableOutput(BPWM1, BPWM_CH_3_MASK);

#endif /*NUCODEGEN_BPWM1_CH3_ENABLE*/

#if NUCODEGEN_BPWM1_CH4_ENABLE
    /* Set BPWM1 channel 4 configuration */
    BPWM_ConfigOutputChannel(BPWM1, 4, NUCODEGEN_BPWM1_FREQ, NUCODEGEN_BPWM1_CH4_DUTY);
    /* Enable output of BPWM1 channel 4 */
    BPWM_EnableOutput(BPWM1, BPWM_CH_4_MASK);


#endif /*NUCODEGEN_BPWM1_CH4_ENABLE*/

#if NUCODEGEN_BPWM1_CH5_ENABLE

    /* Set BPWM1 channel 5 configuration */
    BPWM_ConfigOutputChannel(BPWM1, 5, NUCODEGEN_BPWM1_FREQ, NUCODEGEN_BPWM1_CH5_DUTY);

    /* Enable output of BPWM1 channel 5 */
    BPWM_EnableOutput(BPWM1, BPWM_CH_5_MASK);

#endif /*NUCODEGEN_BPWM1_CH5_ENABLE*/

#else

    /* Set BPWM1 clock source */
    BPWM_SetClockSource(BPWM1, 0, NUCODEGEN_BPWM1_CLKSRC);

    /* Set BPWM1 counter behavior type */
    BPWM_SET_ALIGNED_TYPE(BPWM1, BPWM_CH_0_MASK, NUCODEGEN_BPWM1_CNTTYPE);

    /* Set the prescaler of BPWM1  */
    BPWM_SET_PRESCALER(BPWM1, 0,NUCODEGEN_BPWM1_PRESCALER);

    /* Set the period of BPWM1 */
    BPWM_SET_CNR(BPWM1, 0, NUCODEGEN_BPWM1_PERIOD);

#if NUCODEGEN_BPWM1_SYNCSTART_ENABLE

    /* Enable timer synchronous start counting function */
    BPWM_ENABLE_TIMER_SYNC(BPWM1, BIT0, NUCODEGEN_BPWM1_SYNCSTART_SRC) ;

#endif /*NUCODEGEN_BPWM1_SYNCSTART_ENABLE*/


#if (((NUCODEGEN_BPWM1_CH0_INT_SEL) & 1)||((NUCODEGEN_BPWM1_CH1_INT_SEL) & 1)||((NUCODEGEN_BPWM1_CH2_INT_SEL) & 1)||((NUCODEGEN_BPWM1_CH3_INT_SEL) & 1)||((NUCODEGEN_BPWM1_CH4_INT_SEL) & 1)||((NUCODEGEN_BPWM1_CH5_INT_SEL) & 1))

    /* Enable zero interrupt */
    BPWM_EnableZeroInt(BPWM1, 0) ;

#endif

#if (((NUCODEGEN_BPWM1_CH0_INT_SEL) & 2)||((NUCODEGEN_BPWM1_CH1_INT_SEL) & 2)||((NUCODEGEN_BPWM1_CH2_INT_SEL) & 2)||((NUCODEGEN_BPWM1_CH3_INT_SEL) & 2)||((NUCODEGEN_BPWM1_CH4_INT_SEL) & 2)||((NUCODEGEN_BPWM1_CH5_INT_SEL) & 2))

    /* Enable period interrupt */
    BPWM_EnablePeriodInt(BPWM1, 0, 0) ;

#endif

#if NUCODEGEN_BPWM1_CH0_ENABLE

    /* Set the duty of BPWM1 CH0*/
    BPWM_SET_CMR(BPWM1, 0, NUCODEGEN_BPWM1_CH0_CMPDATA);

    /* Set output level of BPWM1 CH0*/
    BPWM_SET_OUTPUT_LEVEL(BPWM1, BIT0, NUCODEGEN_BPWM1_CH0_WAVEOUT_ZERO, NUCODEGEN_BPWM1_CH0_WAVEOUT_CMPUP, NUCODEGEN_BPWM1_CH0_WAVEOUT_PERIOD, NUCODEGEN_BPWM1_CH0_WAVEOUT_CMPDOWN);

    /* Enable output of BPWM1 channel 0 */
    BPWM_EnableOutput(BPWM1, BPWM_CH_0_MASK);

#if NUCODEGEN_BPWM1_CH0_ADVANCED

#if (NUCODEGEN_BPWM1_CH0_LOAD_MODE == 0)

    /* Period loading mode*/
    BPWM_DisableLoadMode(BPWM1, 0, BPWM_LOAD_MODE_IMMEDIATE|BPWM_LOAD_MODE_CENTER) ;

#elif (NUCODEGEN_BPWM1_CH0_LOAD_MODE == 1)

    /*Immediate loading mode*/
    BPWM_EnableLoadMode(BPWM1, 0, BPWM_LOAD_MODE_IMMEDIATE) ;

#elif (NUCODEGEN_BPWM1_CH0_LOAD_MODE == 2)

    /*Center loading mode*/
    BPWM_EnableLoadMode(BPWM1, 0, BPWM_LOAD_MODE_CENTER) ;

#endif /*NUCODEGEN_BPWM1_CH0_LOAD_MODE*/

#if (NUCODEGEN_BPWM1_CH0_OTHER_OUTPUT==1)

    /* Enable mask output and output high or low*/
    BPWM_SetMaskOutput(BPWM1, 0, NUCODEGEN_BPWM1_CH0_MASK_DATA);

#elif (NUCODEGEN_BPWM1_CH0_OTHER_OUTPUT==2)

    /* Enable inverter output */
    BPWM1->POLCTL |= BPWM_CH_0_MASK;

#endif /*NUCODEGEN_BPWM1_CH0_OTHER_OUTPUT*/

#if NUCODEGEN_BPWM1_CH0_TRIGER_ADC_ENABLE

    /* Set trigger ADC and trigger source*/
    BPWM_EnableADCTrigger(BPWM1, 0, NUCODEGEN_BPWM1_CH0_TRIGER_ADCSRC) ;

#endif /*NUCODEGEN_BPWM1_CH0_TRIGER_ADC_ENABLE*/

#if ((NUCODEGEN_BPWM1_CH0_INT_SEL) & 4)

    /* Enable duty interrupt - count up interrupt */
    BPWM_EnableDutyInt(BPWM1, 0, BPWM_DUTY_INT_UP_COUNT_MATCH_CMP) ;

#endif /*NUCODEGEN_BPWM1_CH0_INT_SEL*/

#if ((NUCODEGEN_BPWM1_CH0_INT_SEL) & 8)

    /* Enable duty interrupt - count down interrupt */
    BPWM_EnableDutyInt(BPWM1, 0, BPWM_DUTY_INT_DOWN_COUNT_MATCH_CMP) ;

#endif /*NUCODEGEN_BPWM1_CH0_INT_SEL*/

#endif /*NUCODEGEN_BPWM1_CH0_ADVANCED*/

#endif /*NUCODEGEN_BPWM1_CH0_ENABLE*/

#if NUCODEGEN_BPWM1_CH1_ENABLE

    /* Set the duty of BPWM1 CH1*/
    BPWM_SET_CMR(BPWM1, 1, NUCODEGEN_BPWM1_CH1_CMPDATA);

    /* Set output level of BPWM1 CH1*/
    BPWM_SET_OUTPUT_LEVEL(BPWM1, BIT1, NUCODEGEN_BPWM1_CH1_WAVEOUT_ZERO, NUCODEGEN_BPWM1_CH1_WAVEOUT_CMPUP, NUCODEGEN_BPWM1_CH1_WAVEOUT_PERIOD, NUCODEGEN_BPWM1_CH1_WAVEOUT_CMPDOWN);

    /* Enable output of BPWM1 channel 1 */
    BPWM_EnableOutput(BPWM1, BPWM_CH_1_MASK);

#if NUCODEGEN_BPWM1_CH1_ADVANCED

#if (NUCODEGEN_BPWM1_CH1_LOAD_MODE == 0)

    /* Period loading mode*/
    BPWM_DisableLoadMode(BPWM1, 1, BPWM_LOAD_MODE_IMMEDIATE|BPWM_LOAD_MODE_CENTER) ;

#elif (NUCODEGEN_BPWM1_CH1_LOAD_MODE == 1)

    /*Immediate loading mode*/
    BPWM_EnableLoadMode(BPWM1, 1, BPWM_LOAD_MODE_IMMEDIATE) ;

#elif (NUCODEGEN_BPWM1_CH1_LOAD_MODE == 2)

    /*Center loading mode*/
    BPWM_EnableLoadMode(BPWM1, 1, BPWM_LOAD_MODE_CENTER) ;

#endif /*NUCODEGEN_BPWM1_CH1_LOAD_MODE*/

#if (NUCODEGEN_BPWM1_CH1_OTHER_OUTPUT==1)

    /* Enable mask output and output high or low*/
    BPWM_SetMaskOutput(BPWM1, 1, NUCODEGEN_BPWM1_CH1_MASK_DATA);

#elif (NUCODEGEN_BPWM1_CH1_OTHER_OUTPUT==2)

    /* Enable inverter output */
    BPWM1->POLCTL |= BPWM_CH_1_MASK;

#endif /*NUCODEGEN_BPWM1_CH1_OTHER_OUTPUT*/

#if NUCODEGEN_BPWM1_CH1_TRIGER_ADC_ENABLE

    /* Set trigger ADC and trigger source*/
    BPWM_EnableADCTrigger(BPWM1, 1, NUCODEGEN_BPWM1_CH1_TRIGER_ADCSRC) ;

#endif /*NUCODEGEN_BPWM1_CH1_TRIGER_ADC_ENABLE*/

#if (((NUCODEGEN_BPWM1_CH1_INT_SEL) & 4))

    /* Enable duty interrupt - count up interrupt */
    BPWM_EnableDutyInt(BPWM1, 1, BPWM_DUTY_INT_UP_COUNT_MATCH_CMP) ;

#endif /*NUCODEGEN_BPWM1_CH1_INT_SEL*/

#if (((NUCODEGEN_BPWM1_CH1_INT_SEL) & 8))

    /* Enable duty interrupt - count down interrupt */
    BPWM_EnableDutyInt(BPWM1, 1, BPWM_DUTY_INT_DOWN_COUNT_MATCH_CMP) ;

#endif /*NUCODEGEN_BPWM1_CH1_INT_SEL*/

#endif /*NUCODEGEN_BPWM1_CH1_ADVANCED*/

#endif /*NUCODEGEN_BPWM1_CH1_ENABLE*/

#if NUCODEGEN_BPWM1_CH2_ENABLE

    /* Set the duty of BPWM1 CH2*/
    BPWM_SET_CMR(BPWM1, 2, NUCODEGEN_BPWM1_CH2_CMPDATA);

    /* Set output level of BPWM1 CH2*/
    BPWM_SET_OUTPUT_LEVEL(BPWM1, BIT2, NUCODEGEN_BPWM1_CH2_WAVEOUT_ZERO, NUCODEGEN_BPWM1_CH2_WAVEOUT_CMPUP, NUCODEGEN_BPWM1_CH2_WAVEOUT_PERIOD, NUCODEGEN_BPWM1_CH2_WAVEOUT_CMPDOWN);

    /* Enable output of BPWM1 channel 2 */
    BPWM_EnableOutput(BPWM1, BPWM_CH_2_MASK);

#if NUCODEGEN_BPWM1_CH2_ADVANCED

#if (NUCODEGEN_BPWM1_CH2_LOAD_MODE == 0)

    /* Period loading mode*/
    BPWM_DisableLoadMode(BPWM1, 2, BPWM_LOAD_MODE_IMMEDIATE|BPWM_LOAD_MODE_CENTER) ;

#elif (NUCODEGEN_BPWM1_CH2_LOAD_MODE == 1)

    /*Immediate loading mode*/
    BPWM_EnableLoadMode(BPWM1, 2, BPWM_LOAD_MODE_IMMEDIATE) ;

#elif (NUCODEGEN_BPWM1_CH2_LOAD_MODE == 2)

    /*Center loading mode*/
    BPWM_EnableLoadMode(BPWM1, 2, BPWM_LOAD_MODE_CENTER) ;

#endif /*NUCODEGEN_BPWM1_CH2_LOAD_MODE*/

#if (NUCODEGEN_BPWM1_CH2_OTHER_OUTPUT==1)

    /* Enable mask output and output high or low*/
    BPWM_SetMaskOutput(BPWM1, 2, NUCODEGEN_BPWM1_CH2_MASK_DATA);

#elif (NUCODEGEN_BPWM1_CH2_OTHER_OUTPUT==2)

    /* Enable inverter output */
    BPWM1->POLCTL |= BPWM_CH_2_MASK;

#endif /*NUCODEGEN_BPWM1_CH2_OTHER_OUTPUT*/

#if NUCODEGEN_BPWM1_CH2_TRIGER_ADC_ENABLE

    /* Set trigger ADC and trigger source*/
    BPWM_EnableADCTrigger(BPWM1, 2, NUCODEGEN_BPWM1_CH2_TRIGER_ADCSRC) ;

#endif /*NUCODEGEN_BPWM1_CH2_TRIGER_ADC_ENABLE*/

#if (((NUCODEGEN_BPWM1_CH2_INT_SEL) & 4))

    /* Enable duty interrupt - count up interrupt */
    BPWM_EnableDutyInt(BPWM1, 2, BPWM_DUTY_INT_UP_COUNT_MATCH_CMP) ;

#endif /*NUCODEGEN_BPWM1_CH2_INT_SEL*/

#if (((NUCODEGEN_BPWM1_CH2_INT_SEL) & 8))

    /* Enable duty interrupt - count down interrupt */
    BPWM_EnableDutyInt(BPWM1, 2, BPWM_DUTY_INT_DOWN_COUNT_MATCH_CMP) ;

#endif /*NUCODEGEN_BPWM1_CH2_INT_SEL*/

#endif /*NUCODEGEN_BPWM1_CH2_ADVANCED*/

#endif /*NUCODEGEN_BPWM1_CH2_ENABLE*/

#if NUCODEGEN_BPWM1_CH3_ENABLE

    /* Set the duty of BPWM1 CH3*/
    BPWM_SET_CMR(BPWM1, 3, NUCODEGEN_BPWM1_CH3_CMPDATA);

    /* Set output level of BPWM1 CH3*/
    BPWM_SET_OUTPUT_LEVEL(BPWM1, BIT3, NUCODEGEN_BPWM1_CH3_WAVEOUT_ZERO, NUCODEGEN_BPWM1_CH3_WAVEOUT_CMPUP, NUCODEGEN_BPWM1_CH3_WAVEOUT_PERIOD, NUCODEGEN_BPWM1_CH3_WAVEOUT_CMPDOWN);

    /* Enable output of BPWM1 channel 3 */
    BPWM_EnableOutput(BPWM1, BPWM_CH_3_MASK);

#if NUCODEGEN_BPWM1_CH3_ADVANCED

#if (NUCODEGEN_BPWM1_CH3_LOAD_MODE == 0)

    /* Period loading mode*/
    BPWM_DisableLoadMode(BPWM1, 3, BPWM_LOAD_MODE_IMMEDIATE|BPWM_LOAD_MODE_CENTER) ;

#elif (NUCODEGEN_BPWM1_CH3_LOAD_MODE == 1)

    /*Immediate loading mode*/
    BPWM_EnableLoadMode(BPWM1, 3, BPWM_LOAD_MODE_IMMEDIATE) ;

#elif (NUCODEGEN_BPWM1_CH3_LOAD_MODE == 2)

    /*Center loading mode*/
    BPWM_EnableLoadMode(BPWM1, 3, BPWM_LOAD_MODE_CENTER) ;

#endif /*NUCODEGEN_BPWM1_CH3_LOAD_MODE*/

#if (NUCODEGEN_BPWM1_CH3_OTHER_OUTPUT==1)

    /* Enable mask output and output high or low*/
    BPWM_SetMaskOutput(BPWM1, 3, NUCODEGEN_BPWM1_CH3_MASK_DATA);

#elif (NUCODEGEN_BPWM1_CH3_OTHER_OUTPUT==2)

    /* Enable inverter output */
    BPWM1->POLCTL |= BPWM_CH_3_MASK;

#endif /*NUCODEGEN_BPWM1_CH3_OTHER_OUTPUT*/

#if NUCODEGEN_BPWM1_CH3_TRIGER_ADC_ENABLE

    /* Set trigger ADC and trigger source*/
    BPWM_EnableADCTrigger(BPWM1, 3, NUCODEGEN_BPWM1_CH3_TRIGER_ADCSRC) ;

#endif /*NUCODEGEN_BPWM1_CH3_TRIGER_ADC_ENABLE*/

#if (((NUCODEGEN_BPWM1_CH3_INT_SEL) & 4))

    /* Enable duty interrupt - count up interrupt */
    BPWM_EnableDutyInt(BPWM1, 3, BPWM_DUTY_INT_UP_COUNT_MATCH_CMP) ;

#endif /*NUCODEGEN_BPWM1_CH3_INT_SEL*/

#if (((NUCODEGEN_BPWM1_CH3_INT_SEL) & 8))

    /* Enable duty interrupt - count down interrupt */
    BPWM_EnableDutyInt(BPWM1, 3, BPWM_DUTY_INT_DOWN_COUNT_MATCH_CMP) ;

#endif /*NUCODEGEN_BPWM1_CH3_INT_SEL*/

#endif /*NUCODEGEN_BPWM1_CH3_ADVANCED*/

#endif /*NUCODEGEN_BPWM1_CH3_ENABLE*/

#if NUCODEGEN_BPWM1_CH4_ENABLE

    /* Set the duty of BPWM1 CH4*/
    BPWM_SET_CMR(BPWM1, 4, NUCODEGEN_BPWM1_CH4_CMPDATA);

    /* Set output level of BPWM1 CH4*/
    BPWM_SET_OUTPUT_LEVEL(BPWM1, BIT4, NUCODEGEN_BPWM1_CH4_WAVEOUT_ZERO, NUCODEGEN_BPWM1_CH4_WAVEOUT_CMPUP, NUCODEGEN_BPWM1_CH4_WAVEOUT_PERIOD, NUCODEGEN_BPWM1_CH4_WAVEOUT_CMPDOWN);

    /* Enable output of BPWM1 channel 4 */
    BPWM_EnableOutput(BPWM1, BPWM_CH_4_MASK);

#if NUCODEGEN_BPWM1_CH4_ADVANCED

#if (NUCODEGEN_BPWM1_CH4_LOAD_MODE == 0)

    /* Period loading mode*/
    BPWM_DisableLoadMode(BPWM1, 4, BPWM_LOAD_MODE_IMMEDIATE|BPWM_LOAD_MODE_CENTER) ;

#elif (NUCODEGEN_BPWM1_CH4_LOAD_MODE == 1)

    /*Immediate loading mode*/
    BPWM_EnableLoadMode(BPWM1, 4, BPWM_LOAD_MODE_IMMEDIATE) ;

#elif (NUCODEGEN_BPWM1_CH4_LOAD_MODE == 2)

    /*Center loading mode*/
    BPWM_EnableLoadMode(BPWM1, 4, BPWM_LOAD_MODE_CENTER) ;

#endif /*NUCODEGEN_BPWM1_CH4_LOAD_MODE*/

#if (NUCODEGEN_BPWM1_CH4_OTHER_OUTPUT==1)

    /* Enable mask output and output high or low*/
    BPWM_SetMaskOutput(BPWM1, 4, NUCODEGEN_BPWM1_CH4_MASK_DATA);

#elif (NUCODEGEN_BPWM1_CH4_OTHER_OUTPUT==2)

    /* Enable inverter output */
    BPWM1->POLCTL |= BPWM_CH_4_MASK;

#endif /*NUCODEGEN_BPWM1_CH4_OTHER_OUTPUT*/

#if NUCODEGEN_BPWM1_CH4_TRIGER_ADC_ENABLE

    /* Set trigger ADC and trigger source*/
    BPWM_EnableADCTrigger(BPWM1, 4, NUCODEGEN_BPWM1_CH4_TRIGER_ADCSRC) ;

#endif /*NUCODEGEN_BPWM1_CH4_TRIGER_ADC_ENABLE*/

#if (((NUCODEGEN_BPWM1_CH4_INT_SEL) & 4))

    /* Enable duty interrupt - count up interrupt */
    BPWM_EnableDutyInt(BPWM1, 4, BPWM_DUTY_INT_UP_COUNT_MATCH_CMP) ;

#endif /*NUCODEGEN_BPWM1_CH4_INT_SEL*/

#if (((NUCODEGEN_BPWM1_CH4_INT_SEL) & 8))

    /* Enable duty interrupt - count down interrupt */
    BPWM_EnableDutyInt(BPWM1, 4, BPWM_DUTY_INT_DOWN_COUNT_MATCH_CMP) ;

#endif /*NUCODEGEN_BPWM1_CH4_INT_SEL*/

#endif /*NUCODEGEN_BPWM1_CH4_ADVANCED*/

#endif /*NUCODEGEN_BPWM1_CH4_ENABLE*/

#if NUCODEGEN_BPWM1_CH5_ENABLE

    /* Set the duty of BPWM1 CH5*/
    BPWM_SET_CMR(BPWM1, 5, NUCODEGEN_BPWM1_CH5_CMPDATA);

    /* Set output level of BPWM1 CH5*/
    BPWM_SET_OUTPUT_LEVEL(BPWM1, BIT5, NUCODEGEN_BPWM1_CH5_WAVEOUT_ZERO, NUCODEGEN_BPWM1_CH5_WAVEOUT_CMPUP, NUCODEGEN_BPWM1_CH5_WAVEOUT_PERIOD, NUCODEGEN_BPWM1_CH5_WAVEOUT_CMPDOWN);

    /* Enable output of BPWM1 channel 5 */
    BPWM_EnableOutput(BPWM1, BPWM_CH_5_MASK);

#if NUCODEGEN_BPWM1_CH5_ADVANCED

#if (NUCODEGEN_BPWM1_CH5_LOAD_MODE == 0)

    /* Period loading mode*/
    BPWM_DisableLoadMode(BPWM1, 5, BPWM_LOAD_MODE_IMMEDIATE|BPWM_LOAD_MODE_CENTER) ;

#elif (NUCODEGEN_BPWM1_CH5_LOAD_MODE == 1)

    /*Immediate loading mode*/
    BPWM_EnableLoadMode(BPWM1, 5, BPWM_LOAD_MODE_IMMEDIATE) ;

#elif (NUCODEGEN_BPWM1_CH5_LOAD_MODE == 2)

    /*Center loading mode*/
    BPWM_EnableLoadMode(BPWM1, 5, BPWM_LOAD_MODE_CENTER) ;

#endif /*NUCODEGEN_BPWM1_CH5_LOAD_MODE*/

#if (NUCODEGEN_BPWM1_CH5_OTHER_OUTPUT==1)

    /* Enable mask output and output high or low*/
    BPWM_SetMaskOutput(BPWM1, 5, NUCODEGEN_BPWM1_CH5_MASK_DATA);

#elif (NUCODEGEN_BPWM1_CH5_OTHER_OUTPUT==2)

    /* Enable inverter output */
    BPWM1->POLCTL |= BPWM_CH_5_MASK;

#endif /*NUCODEGEN_BPWM1_CH5_OTHER_OUTPUT*/

#if NUCODEGEN_BPWM1_CH5_TRIGER_ADC_ENABLE

    /* Set trigger ADC and trigger source*/
    BPWM_EnableADCTrigger(BPWM1, 5, NUCODEGEN_BPWM1_CH5_TRIGER_ADCSRC) ;

#endif /*NUCODEGEN_BPWM1_CH5_TRIGER_ADC_ENABLE*/

#if (((NUCODEGEN_BPWM1_CH5_INT_SEL) & 4))

    /* Enable duty interrupt - count up interrupt */
    BPWM_EnableDutyInt(BPWM1, 5, BPWM_DUTY_INT_UP_COUNT_MATCH_CMP) ;

#endif /*NUCODEGEN_BPWM1_CH5_INT_SEL*/

#if (((NUCODEGEN_BPWM1_CH5_INT_SEL) & 8))

    /* Enable duty interrupt - count down interrupt */
    BPWM_EnableDutyInt(BPWM1, 5, BPWM_DUTY_INT_DOWN_COUNT_MATCH_CMP) ;

#endif /*NUCODEGEN_BPWM1_CH5_INT_SEL*/

#endif /*NUCODEGEN_BPWM1_CH5_ADVANCED*/

#endif /*NUCODEGEN_BPWM1_CH5_ENABLE*/

#endif /*NUCODEGEN_BPWM1_OUTPUT_FUNC_SETMODE*/

#else

    /* Configure BPWM capture and get the nearest unit time */
    BPWM_ConfigCaptureChannel(BPWM1, 0, NUCODEGEN_BPWM1_CAP_UNITTIME, 0);

#if NUCODEGEN_BPWM1_CH0_CAP_ENABLE

    /* Set Reload Mode */
    BPWM1->CAPCTL |= (NUCODEGEN_BPWM1_CH0_CAP_RELOAD)<<BPWM_CAPCTL_RCRLDEN0_Pos;

    /* Enable Capture Function for BPWM1 channel 0 */
    BPWM_EnableCapture(BPWM1, BPWM_CH_0_MASK);

#if NUCODEGEN_BPWM1_CH0_CAP_ADVANCED

#if (NUCODEGEN_BPWM1_CH0_CAP_INT_SEL == 1)

    /*Enable rising latch capture interrupt*/
    BPWM_EnableCaptureInt(BPWM1, 0, BPWM_CAPTURE_INT_RISING_LATCH) ;

#elif (NUCODEGEN_BPWM1_CH0_CAP_INT_SEL == 2)

    /*Enable falling latch capture interrupt*/
    BPWM_EnableCaptureInt(BPWM1, 0, BPWM_CAPTURE_INT_FALLING_LATCH) ;

#elif (NUCODEGEN_BPWM1_CH0_CAP_INT_SEL == 3)

    /*Enable rising and falling latch capture interrupt*/
    BPWM_EnableCaptureInt(BPWM1, 0, BPWM_CAPTURE_INT_RISING_LATCH|BPWM_CAPTURE_INT_FALLING_LATCH) ;

#endif /*NUCODEGEN_BPWM1_CH0_CAP_INT_SEL*/

#endif /*NUCODEGEN_BPWM1_CH0_CAP_ADVANCED*/

#endif /*NUCODEGEN_BPWM1_CH0_CAP_ENABLE*/

#if NUCODEGEN_BPWM1_CH1_CAP_ENABLE

    /* Set Reload Mode */
    BPWM1->CAPCTL |= (NUCODEGEN_BPWM1_CH1_CAP_RELOAD)<<BPWM_CAPCTL_RCRLDEN1_Pos;

    /* Enable Capture Function for BPWM1 channel 1 */
    BPWM_EnableCapture(BPWM1, BPWM_CH_1_MASK);

#if NUCODEGEN_BPWM1_CH1_CAP_ADVANCED

#if (NUCODEGEN_BPWM1_CH1_CAP_INT_SEL == 1)

    /*Enable rising latch capture interrupt*/
    BPWM_EnableCaptureInt(BPWM1, 1, BPWM_CAPTURE_INT_RISING_LATCH) ;

#elif (NUCODEGEN_BPWM1_CH1_CAP_INT_SEL == 2)

    /*Enable falling latch capture interrupt*/
    BPWM_EnableCaptureInt(BPWM1, 1, BPWM_CAPTURE_INT_FALLING_LATCH) ;

#elif (NUCODEGEN_BPWM1_CH1_CAP_INT_SEL == 3)

    /*Enable rising and falling latch capture interrupt*/
    BPWM_EnableCaptureInt(BPWM1, 1, BPWM_CAPTURE_INT_RISING_LATCH|BPWM_CAPTURE_INT_FALLING_LATCH) ;

#endif /*NUCODEGEN_BPWM1_CH1_CAP_INT_SEL*/

#endif /*NUCODEGEN_BPWM1_CH1_CAP_ADVANCED*/

#endif /*NUCODEGEN_BPWM1_CH1_CAP_ENABLE*/

#if NUCODEGEN_BPWM1_CH2_CAP_ENABLE

    /* Set Reload Mode */
    BPWM1->CAPCTL |= (NUCODEGEN_BPWM1_CH2_CAP_RELOAD)<<BPWM_CAPCTL_RCRLDEN2_Pos;

    /* Enable Capture Function for BPWM1 channel 2 */
    BPWM_EnableCapture(BPWM1, BPWM_CH_2_MASK);

#if NUCODEGEN_BPWM1_CH2_CAP_ADVANCED

#if (NUCODEGEN_BPWM1_CH2_CAP_INT_SEL == 1)

    /*Enable rising latch capture interrupt*/
    BPWM_EnableCaptureInt(BPWM1, 2, BPWM_CAPTURE_INT_RISING_LATCH) ;

#elif (NUCODEGEN_BPWM1_CH2_CAP_INT_SEL == 2)

    /*Enable falling latch capture interrupt*/
    BPWM_EnableCaptureInt(BPWM1, 2, BPWM_CAPTURE_INT_FALLING_LATCH) ;

#elif (NUCODEGEN_BPWM1_CH2_CAP_INT_SEL == 3)

    /*Enable rising and falling latch capture interrupt*/
    BPWM_EnableCaptureInt(BPWM1, 2, BPWM_CAPTURE_INT_RISING_LATCH|BPWM_CAPTURE_INT_FALLING_LATCH) ;

#endif /*NUCODEGEN_BPWM1_CH2_CAP_INT_SEL*/

#endif /*NUCODEGEN_BPWM1_CH2_CAP_ADVANCED*/

#endif /*NUCODEGEN_BPWM1_CH2_CAP_ENABLE*/

#if NUCODEGEN_BPWM1_CH3_CAP_ENABLE

    /* Set Reload Mode */
    BPWM1->CAPCTL |= (NUCODEGEN_BPWM1_CH3_CAP_RELOAD)<<BPWM_CAPCTL_RCRLDEN3_Pos;

    /* Enable Capture Function for BPWM1 channel 3 */
    BPWM_EnableCapture(BPWM1, BPWM_CH_3_MASK);

#if NUCODEGEN_BPWM1_CH3_CAP_ADVANCED

#if (NUCODEGEN_BPWM1_CH3_CAP_INT_SEL == 1)

    /*Enable rising latch capture interrupt*/
    BPWM_EnableCaptureInt(BPWM1, 3, BPWM_CAPTURE_INT_RISING_LATCH) ;

#elif (NUCODEGEN_BPWM1_CH3_CAP_INT_SEL == 2)

    /*Enable falling latch capture interrupt*/
    BPWM_EnableCaptureInt(BPWM1, 3, BPWM_CAPTURE_INT_FALLING_LATCH) ;

#elif (NUCODEGEN_BPWM1_CH3_CAP_INT_SEL == 3)

    /*Enable rising and falling latch capture interrupt*/
    BPWM_EnableCaptureInt(BPWM1, 3, BPWM_CAPTURE_INT_RISING_LATCH|BPWM_CAPTURE_INT_FALLING_LATCH) ;

#endif /*NUCODEGEN_BPWM1_CH3_CAP_INT_SEL*/

#endif /*NUCODEGEN_BPWM1_CH3_CAP_ADVANCED*/

#endif /*NUCODEGEN_BPWM1_CH3_CAP_ENABLE*/

#if NUCODEGEN_BPWM1_CH4_CAP_ENABLE

    /* Set Reload Mode */
    BPWM1->CAPCTL |= (NUCODEGEN_BPWM1_CH4_CAP_RELOAD)<<BPWM_CAPCTL_RCRLDEN4_Pos;

    /* Enable Capture Function for BPWM1 channel 4 */
    BPWM_EnableCapture(BPWM1, BPWM_CH_4_MASK);

#if NUCODEGEN_BPWM1_CH4_CAP_ADVANCED

#if (NUCODEGEN_BPWM1_CH4_CAP_INT_SEL == 1)

    /*Enable rising latch capture interrupt*/
    BPWM_EnableCaptureInt(BPWM1, 4, BPWM_CAPTURE_INT_RISING_LATCH) ;

#elif (NUCODEGEN_BPWM1_CH4_CAP_INT_SEL == 2)

    /*Enable falling latch capture interrupt*/
    BPWM_EnableCaptureInt(BPWM1, 4, BPWM_CAPTURE_INT_FALLING_LATCH) ;

#elif (NUCODEGEN_BPWM1_CH4_CAP_INT_SEL == 3)

    /*Enable rising and falling latch capture interrupt*/
    BPWM_EnableCaptureInt(BPWM1, 4, BPWM_CAPTURE_INT_RISING_LATCH|BPWM_CAPTURE_INT_FALLING_LATCH) ;

#endif /*NUCODEGEN_BPWM1_CH4_CAP_INT_SEL*/

#endif /*NUCODEGEN_BPWM1_CH4_CAP_ADVANCED*/

#endif /*NUCODEGEN_BPWM1_CH4_CAP_ENABLE*/

#if NUCODEGEN_BPWM1_CH5_CAP_ENABLE

    /* Set Reload Mode */
    BPWM1->CAPCTL |= (NUCODEGEN_BPWM1_CH5_CAP_RELOAD)<<BPWM_CAPCTL_RCRLDEN5_Pos;

    /* Enable Capture Function for BPWM1 channel 5 */
    BPWM_EnableCapture(BPWM1, BPWM_CH_5_MASK);

#if NUCODEGEN_BPWM1_CH5_CAP_ADVANCED

#if (NUCODEGEN_BPWM1_CH5_CAP_INT_SEL == 1)

    /*Enable rising latch capture interrupt*/
    BPWM_EnableCaptureInt(BPWM1, 5, BPWM_CAPTURE_INT_RISING_LATCH) ;

#elif (NUCODEGEN_BPWM1_CH5_CAP_INT_SEL == 2)

    /*Enable falling latch capture interrupt*/
    BPWM_EnableCaptureInt(BPWM1, 5, BPWM_CAPTURE_INT_FALLING_LATCH) ;

#elif (NUCODEGEN_BPWM1_CH5_CAP_INT_SEL == 3)

    /*Enable rising and falling latch capture interrupt*/
    BPWM_EnableCaptureInt(BPWM1, 5, BPWM_CAPTURE_INT_RISING_LATCH|BPWM_CAPTURE_INT_FALLING_LATCH) ;

#endif /*NUCODEGEN_BPWM1_CH5_CAP_INT_SEL*/

#endif /*NUCODEGEN_BPWM1_CH5_CAP_ADVANCED*/

#endif /*NUCODEGEN_BPWM1_CH5_CAP_ENABLE*/

#endif /*NUCODEGEN_BPWM1_FUNC_SEL*/

}

#endif //NUCODEGEN_BPWM1

#if (NUCODEGEN_BPWM2)
void BPWM2_Init()
{

#if (NUCODEGEN_BPWM2_FUNC_SEL==0)

#if (NUCODEGEN_BPWM2_OUTPUT_FUNC_SETMODE==0)

#if NUCODEGEN_BPWM2_CH0_ENABLE

    /* Set BPWM2 channel 0 configuration */
    BPWM_ConfigOutputChannel(BPWM2, 0, NUCODEGEN_BPWM2_FREQ, NUCODEGEN_BPWM2_CH0_DUTY);

    /* Enable output of BPWM2 channel 0 */
    BPWM_EnableOutput(BPWM2, BPWM_CH_0_MASK);

#endif /*NUCODEGEN_BPWM2_CH0_ENABLE*/

#if NUCODEGEN_BPWM2_CH1_ENABLE

    /* Set BPWM2 channel 1 configuration */
    BPWM_ConfigOutputChannel(BPWM2, 1, NUCODEGEN_BPWM2_FREQ, NUCODEGEN_BPWM2_CH1_DUTY);

    /* Enable output of BPWM2 channel 1 */
    BPWM_EnableOutput(BPWM2, BPWM_CH_1_MASK);

#endif /*NUCODEGEN_BPWM2_CH1_ENABLE*/

#if NUCODEGEN_BPWM2_CH2_ENABLE
    /* Set BPWM2 channel 2 configuration */
    BPWM_ConfigOutputChannel(BPWM2, 2, NUCODEGEN_BPWM2_FREQ, NUCODEGEN_BPWM2_CH2_DUTY);
    /* Enable output of BPWM2 channel 2 */
    BPWM_EnableOutput(BPWM2, BPWM_CH_2_MASK);

#endif /*NUCODEGEN_BPWM2_CH2_ENABLE*/

#if NUCODEGEN_BPWM2_CH3_ENABLE
    /* Set BPWM2 channel 3 configuration */
    BPWM_ConfigOutputChannel(BPWM2, 3, NUCODEGEN_BPWM2_FREQ, NUCODEGEN_BPWM2_CH3_DUTY);
    /* Enable output of BPWM2 channel 3 */
    BPWM_EnableOutput(BPWM2, BPWM_CH_3_MASK);

#endif /*NUCODEGEN_BPWM2_CH3_ENABLE*/

#if NUCODEGEN_BPWM2_CH4_ENABLE
    /* Set BPWM2 channel 4 configuration */
    BPWM_ConfigOutputChannel(BPWM2, 4, NUCODEGEN_BPWM2_FREQ, NUCODEGEN_BPWM2_CH4_DUTY);
    /* Enable output of BPWM2 channel 4 */
    BPWM_EnableOutput(BPWM2, BPWM_CH_4_MASK);


#endif /*NUCODEGEN_BPWM2_CH4_ENABLE*/

#if NUCODEGEN_BPWM2_CH5_ENABLE

    /* Set BPWM2 channel 5 configuration */
    BPWM_ConfigOutputChannel(BPWM2, 5, NUCODEGEN_BPWM2_FREQ, NUCODEGEN_BPWM2_CH5_DUTY);

    /* Enable output of BPWM2 channel 5 */
    BPWM_EnableOutput(BPWM2, BPWM_CH_5_MASK);

#endif /*NUCODEGEN_BPWM2_CH5_ENABLE*/

#else

    /* Set BPWM2 clock source */
    BPWM_SetClockSource(BPWM2, 0, NUCODEGEN_BPWM2_CLKSRC);

    /* Set BPWM2 counter behavior type */
    BPWM_SET_ALIGNED_TYPE(BPWM2, BPWM_CH_0_MASK, NUCODEGEN_BPWM2_CNTTYPE);

    /* Set the prescaler of BPWM2  */
    BPWM_SET_PRESCALER(BPWM2, 0,NUCODEGEN_BPWM2_PRESCALER);

    /* Set the period of BPWM2 */
    BPWM_SET_CNR(BPWM2, 0, NUCODEGEN_BPWM2_PERIOD);

#if NUCODEGEN_BPWM2_SYNCSTART_ENABLE

    /* Enable timer synchronous start counting function */
    BPWM_ENABLE_TIMER_SYNC(BPWM2, BIT0, NUCODEGEN_BPWM2_SYNCSTART_SRC) ;

#endif /*NUCODEGEN_BPWM2_SYNCSTART_ENABLE*/


#if (((NUCODEGEN_BPWM2_CH0_INT_SEL) & 1)||((NUCODEGEN_BPWM2_CH1_INT_SEL) & 1)||((NUCODEGEN_BPWM2_CH2_INT_SEL) & 1)||((NUCODEGEN_BPWM2_CH3_INT_SEL) & 1)||((NUCODEGEN_BPWM2_CH4_INT_SEL) & 1)||((NUCODEGEN_BPWM2_CH5_INT_SEL) & 1))

    /* Enable zero interrupt */
    BPWM_EnableZeroInt(BPWM2, 0) ;

#endif

#if (((NUCODEGEN_BPWM2_CH0_INT_SEL) & 2)||((NUCODEGEN_BPWM2_CH1_INT_SEL) & 2)||((NUCODEGEN_BPWM2_CH2_INT_SEL) & 2)||((NUCODEGEN_BPWM2_CH3_INT_SEL) & 2)||((NUCODEGEN_BPWM2_CH4_INT_SEL) & 2)||((NUCODEGEN_BPWM2_CH5_INT_SEL) & 2))

    /* Enable period interrupt */
    BPWM_EnablePeriodInt(BPWM2, 0, 0) ;

#endif

#if NUCODEGEN_BPWM2_CH0_ENABLE

    /* Set the duty of BPWM2 CH0*/
    BPWM_SET_CMR(BPWM2, 0, NUCODEGEN_BPWM2_CH0_CMPDATA);

    /* Set output level of BPWM2 CH0*/
    BPWM_SET_OUTPUT_LEVEL(BPWM2, BIT0, NUCODEGEN_BPWM2_CH0_WAVEOUT_ZERO, NUCODEGEN_BPWM2_CH0_WAVEOUT_CMPUP, NUCODEGEN_BPWM2_CH0_WAVEOUT_PERIOD, NUCODEGEN_BPWM2_CH0_WAVEOUT_CMPDOWN);

    /* Enable output of BPWM2 channel 0 */
    BPWM_EnableOutput(BPWM2, BPWM_CH_0_MASK);

#if NUCODEGEN_BPWM2_CH0_ADVANCED

#if (NUCODEGEN_BPWM2_CH0_LOAD_MODE == 0)

    /* Period loading mode*/
    BPWM_DisableLoadMode(BPWM2, 0, BPWM_LOAD_MODE_IMMEDIATE|BPWM_LOAD_MODE_CENTER) ;

#elif (NUCODEGEN_BPWM2_CH0_LOAD_MODE == 1)

    /*Immediate loading mode*/
    BPWM_EnableLoadMode(BPWM2, 0, BPWM_LOAD_MODE_IMMEDIATE) ;

#elif (NUCODEGEN_BPWM2_CH0_LOAD_MODE == 2)

    /*Center loading mode*/
    BPWM_EnableLoadMode(BPWM2, 0, BPWM_LOAD_MODE_CENTER) ;

#endif /*NUCODEGEN_BPWM2_CH0_LOAD_MODE*/

#if (NUCODEGEN_BPWM2_CH0_OTHER_OUTPUT==1)

    /* Enable mask output and output high or low*/
    BPWM_SetMaskOutput(BPWM2, 0, NUCODEGEN_BPWM2_CH0_MASK_DATA);

#elif (NUCODEGEN_BPWM2_CH0_OTHER_OUTPUT==2)

    /* Enable inverter output */
    BPWM2->POLCTL |= BPWM_CH_0_MASK;

#endif /*NUCODEGEN_BPWM2_CH0_OTHER_OUTPUT*/

#if NUCODEGEN_BPWM2_CH0_TRIGER_ADC_ENABLE

    /* Set trigger ADC and trigger source*/
    BPWM_EnableADCTrigger(BPWM2, 0, NUCODEGEN_BPWM2_CH0_TRIGER_ADCSRC) ;

#endif /*NUCODEGEN_BPWM2_CH0_TRIGER_ADC_ENABLE*/

#if ((NUCODEGEN_BPWM2_CH0_INT_SEL) & 4)

    /* Enable duty interrupt - count up interrupt */
    BPWM_EnableDutyInt(BPWM2, 0, BPWM_DUTY_INT_UP_COUNT_MATCH_CMP) ;

#endif /*NUCODEGEN_BPWM2_CH0_INT_SEL*/

#if ((NUCODEGEN_BPWM2_CH0_INT_SEL) & 8)

    /* Enable duty interrupt - count down interrupt */
    BPWM_EnableDutyInt(BPWM2, 0, BPWM_DUTY_INT_DOWN_COUNT_MATCH_CMP) ;

#endif /*NUCODEGEN_BPWM2_CH0_INT_SEL*/

#endif /*NUCODEGEN_BPWM2_CH0_ADVANCED*/

#endif /*NUCODEGEN_BPWM2_CH0_ENABLE*/

#if NUCODEGEN_BPWM2_CH1_ENABLE

    /* Set the duty of BPWM2 CH1*/
    BPWM_SET_CMR(BPWM2, 1, NUCODEGEN_BPWM2_CH1_CMPDATA);

    /* Set output level of BPWM2 CH1*/
    BPWM_SET_OUTPUT_LEVEL(BPWM2, BIT1, NUCODEGEN_BPWM2_CH1_WAVEOUT_ZERO, NUCODEGEN_BPWM2_CH1_WAVEOUT_CMPUP, NUCODEGEN_BPWM2_CH1_WAVEOUT_PERIOD, NUCODEGEN_BPWM2_CH1_WAVEOUT_CMPDOWN);

    /* Enable output of BPWM2 channel 1 */
    BPWM_EnableOutput(BPWM2, BPWM_CH_1_MASK);

#if NUCODEGEN_BPWM2_CH1_ADVANCED

#if (NUCODEGEN_BPWM2_CH1_LOAD_MODE == 0)

    /* Period loading mode*/
    BPWM_DisableLoadMode(BPWM2, 1, BPWM_LOAD_MODE_IMMEDIATE|BPWM_LOAD_MODE_CENTER) ;

#elif (NUCODEGEN_BPWM2_CH1_LOAD_MODE == 1)

    /*Immediate loading mode*/
    BPWM_EnableLoadMode(BPWM2, 1, BPWM_LOAD_MODE_IMMEDIATE) ;

#elif (NUCODEGEN_BPWM2_CH1_LOAD_MODE == 2)

    /*Center loading mode*/
    BPWM_EnableLoadMode(BPWM2, 1, BPWM_LOAD_MODE_CENTER) ;

#endif /*NUCODEGEN_BPWM2_CH1_LOAD_MODE*/

#if (NUCODEGEN_BPWM2_CH1_OTHER_OUTPUT==1)

    /* Enable mask output and output high or low*/
    BPWM_SetMaskOutput(BPWM2, 1, NUCODEGEN_BPWM2_CH1_MASK_DATA);

#elif (NUCODEGEN_BPWM2_CH1_OTHER_OUTPUT==2)

    /* Enable inverter output */
    BPWM2->POLCTL |= BPWM_CH_1_MASK;

#endif /*NUCODEGEN_BPWM2_CH1_OTHER_OUTPUT*/

#if NUCODEGEN_BPWM2_CH1_TRIGER_ADC_ENABLE

    /* Set trigger ADC and trigger source*/
    BPWM_EnableADCTrigger(BPWM2, 1, NUCODEGEN_BPWM2_CH1_TRIGER_ADCSRC) ;

#endif /*NUCODEGEN_BPWM2_CH1_TRIGER_ADC_ENABLE*/

#if (((NUCODEGEN_BPWM2_CH1_INT_SEL) & 4))

    /* Enable duty interrupt - count up interrupt */
    BPWM_EnableDutyInt(BPWM2, 1, BPWM_DUTY_INT_UP_COUNT_MATCH_CMP) ;

#endif /*NUCODEGEN_BPWM2_CH1_INT_SEL*/

#if (((NUCODEGEN_BPWM2_CH1_INT_SEL) & 8))

    /* Enable duty interrupt - count down interrupt */
    BPWM_EnableDutyInt(BPWM2, 1, BPWM_DUTY_INT_DOWN_COUNT_MATCH_CMP) ;

#endif /*NUCODEGEN_BPWM2_CH1_INT_SEL*/

#endif /*NUCODEGEN_BPWM2_CH1_ADVANCED*/

#endif /*NUCODEGEN_BPWM2_CH1_ENABLE*/

#if NUCODEGEN_BPWM2_CH2_ENABLE

    /* Set the duty of BPWM2 CH2*/
    BPWM_SET_CMR(BPWM2, 2, NUCODEGEN_BPWM2_CH2_CMPDATA);

    /* Set output level of BPWM2 CH2*/
    BPWM_SET_OUTPUT_LEVEL(BPWM2, BIT2, NUCODEGEN_BPWM2_CH2_WAVEOUT_ZERO, NUCODEGEN_BPWM2_CH2_WAVEOUT_CMPUP, NUCODEGEN_BPWM2_CH2_WAVEOUT_PERIOD, NUCODEGEN_BPWM2_CH2_WAVEOUT_CMPDOWN);

    /* Enable output of BPWM2 channel 2 */
    BPWM_EnableOutput(BPWM2, BPWM_CH_2_MASK);

#if NUCODEGEN_BPWM2_CH2_ADVANCED

#if (NUCODEGEN_BPWM2_CH2_LOAD_MODE == 0)

    /* Period loading mode*/
    BPWM_DisableLoadMode(BPWM2, 2, BPWM_LOAD_MODE_IMMEDIATE|BPWM_LOAD_MODE_CENTER) ;

#elif (NUCODEGEN_BPWM2_CH2_LOAD_MODE == 1)

    /*Immediate loading mode*/
    BPWM_EnableLoadMode(BPWM2, 2, BPWM_LOAD_MODE_IMMEDIATE) ;

#elif (NUCODEGEN_BPWM2_CH2_LOAD_MODE == 2)

    /*Center loading mode*/
    BPWM_EnableLoadMode(BPWM2, 2, BPWM_LOAD_MODE_CENTER) ;

#endif /*NUCODEGEN_BPWM2_CH2_LOAD_MODE*/

#if (NUCODEGEN_BPWM2_CH2_OTHER_OUTPUT==1)

    /* Enable mask output and output high or low*/
    BPWM_SetMaskOutput(BPWM2, 2, NUCODEGEN_BPWM2_CH2_MASK_DATA);

#elif (NUCODEGEN_BPWM2_CH2_OTHER_OUTPUT==2)

    /* Enable inverter output */
    BPWM2->POLCTL |= BPWM_CH_2_MASK;

#endif /*NUCODEGEN_BPWM2_CH2_OTHER_OUTPUT*/

#if NUCODEGEN_BPWM2_CH2_TRIGER_ADC_ENABLE

    /* Set trigger ADC and trigger source*/
    BPWM_EnableADCTrigger(BPWM2, 2, NUCODEGEN_BPWM2_CH2_TRIGER_ADCSRC) ;

#endif /*NUCODEGEN_BPWM2_CH2_TRIGER_ADC_ENABLE*/

#if (((NUCODEGEN_BPWM2_CH2_INT_SEL) & 4))

    /* Enable duty interrupt - count up interrupt */
    BPWM_EnableDutyInt(BPWM2, 2, BPWM_DUTY_INT_UP_COUNT_MATCH_CMP) ;

#endif /*NUCODEGEN_BPWM2_CH2_INT_SEL*/

#if (((NUCODEGEN_BPWM2_CH2_INT_SEL) & 8))

    /* Enable duty interrupt - count down interrupt */
    BPWM_EnableDutyInt(BPWM2, 2, BPWM_DUTY_INT_DOWN_COUNT_MATCH_CMP) ;

#endif /*NUCODEGEN_BPWM2_CH2_INT_SEL*/

#endif /*NUCODEGEN_BPWM2_CH2_ADVANCED*/

#endif /*NUCODEGEN_BPWM2_CH2_ENABLE*/

#if NUCODEGEN_BPWM2_CH3_ENABLE

    /* Set the duty of BPWM2 CH3*/
    BPWM_SET_CMR(BPWM2, 3, NUCODEGEN_BPWM2_CH3_CMPDATA);

    /* Set output level of BPWM2 CH3*/
    BPWM_SET_OUTPUT_LEVEL(BPWM2, BIT3, NUCODEGEN_BPWM2_CH3_WAVEOUT_ZERO, NUCODEGEN_BPWM2_CH3_WAVEOUT_CMPUP, NUCODEGEN_BPWM2_CH3_WAVEOUT_PERIOD, NUCODEGEN_BPWM2_CH3_WAVEOUT_CMPDOWN);

    /* Enable output of BPWM2 channel 3 */
    BPWM_EnableOutput(BPWM2, BPWM_CH_3_MASK);

#if NUCODEGEN_BPWM2_CH3_ADVANCED

#if (NUCODEGEN_BPWM2_CH3_LOAD_MODE == 0)

    /* Period loading mode*/
    BPWM_DisableLoadMode(BPWM2, 3, BPWM_LOAD_MODE_IMMEDIATE|BPWM_LOAD_MODE_CENTER) ;

#elif (NUCODEGEN_BPWM2_CH3_LOAD_MODE == 1)

    /*Immediate loading mode*/
    BPWM_EnableLoadMode(BPWM2, 3, BPWM_LOAD_MODE_IMMEDIATE) ;

#elif (NUCODEGEN_BPWM2_CH3_LOAD_MODE == 2)

    /*Center loading mode*/
    BPWM_EnableLoadMode(BPWM2, 3, BPWM_LOAD_MODE_CENTER) ;

#endif /*NUCODEGEN_BPWM2_CH3_LOAD_MODE*/

#if (NUCODEGEN_BPWM2_CH3_OTHER_OUTPUT==1)

    /* Enable mask output and output high or low*/
    BPWM_SetMaskOutput(BPWM2, 3, NUCODEGEN_BPWM2_CH3_MASK_DATA);

#elif (NUCODEGEN_BPWM2_CH3_OTHER_OUTPUT==2)

    /* Enable inverter output */
    BPWM2->POLCTL |= BPWM_CH_3_MASK;

#endif /*NUCODEGEN_BPWM2_CH3_OTHER_OUTPUT*/

#if NUCODEGEN_BPWM2_CH3_TRIGER_ADC_ENABLE

    /* Set trigger ADC and trigger source*/
    BPWM_EnableADCTrigger(BPWM2, 3, NUCODEGEN_BPWM2_CH3_TRIGER_ADCSRC) ;

#endif /*NUCODEGEN_BPWM2_CH3_TRIGER_ADC_ENABLE*/

#if (((NUCODEGEN_BPWM2_CH3_INT_SEL) & 4))

    /* Enable duty interrupt - count up interrupt */
    BPWM_EnableDutyInt(BPWM2, 3, BPWM_DUTY_INT_UP_COUNT_MATCH_CMP) ;

#endif /*NUCODEGEN_BPWM2_CH3_INT_SEL*/

#if (((NUCODEGEN_BPWM2_CH3_INT_SEL) & 8))

    /* Enable duty interrupt - count down interrupt */
    BPWM_EnableDutyInt(BPWM2, 3, BPWM_DUTY_INT_DOWN_COUNT_MATCH_CMP) ;

#endif /*NUCODEGEN_BPWM2_CH3_INT_SEL*/

#endif /*NUCODEGEN_BPWM2_CH3_ADVANCED*/

#endif /*NUCODEGEN_BPWM2_CH3_ENABLE*/

#if NUCODEGEN_BPWM2_CH4_ENABLE

    /* Set the duty of BPWM2 CH4*/
    BPWM_SET_CMR(BPWM2, 4, NUCODEGEN_BPWM2_CH4_CMPDATA);

    /* Set output level of BPWM2 CH4*/
    BPWM_SET_OUTPUT_LEVEL(BPWM2, BIT4, NUCODEGEN_BPWM2_CH4_WAVEOUT_ZERO, NUCODEGEN_BPWM2_CH4_WAVEOUT_CMPUP, NUCODEGEN_BPWM2_CH4_WAVEOUT_PERIOD, NUCODEGEN_BPWM2_CH4_WAVEOUT_CMPDOWN);

    /* Enable output of BPWM2 channel 4 */
    BPWM_EnableOutput(BPWM2, BPWM_CH_4_MASK);

#if NUCODEGEN_BPWM2_CH4_ADVANCED

#if (NUCODEGEN_BPWM2_CH4_LOAD_MODE == 0)

    /* Period loading mode*/
    BPWM_DisableLoadMode(BPWM2, 4, BPWM_LOAD_MODE_IMMEDIATE|BPWM_LOAD_MODE_CENTER) ;

#elif (NUCODEGEN_BPWM2_CH4_LOAD_MODE == 1)

    /*Immediate loading mode*/
    BPWM_EnableLoadMode(BPWM2, 4, BPWM_LOAD_MODE_IMMEDIATE) ;

#elif (NUCODEGEN_BPWM2_CH4_LOAD_MODE == 2)

    /*Center loading mode*/
    BPWM_EnableLoadMode(BPWM2, 4, BPWM_LOAD_MODE_CENTER) ;

#endif /*NUCODEGEN_BPWM2_CH4_LOAD_MODE*/

#if (NUCODEGEN_BPWM2_CH4_OTHER_OUTPUT==1)

    /* Enable mask output and output high or low*/
    BPWM_SetMaskOutput(BPWM2, 4, NUCODEGEN_BPWM2_CH4_MASK_DATA);

#elif (NUCODEGEN_BPWM2_CH4_OTHER_OUTPUT==2)

    /* Enable inverter output */
    BPWM2->POLCTL |= BPWM_CH_4_MASK;

#endif /*NUCODEGEN_BPWM2_CH4_OTHER_OUTPUT*/

#if NUCODEGEN_BPWM2_CH4_TRIGER_ADC_ENABLE

    /* Set trigger ADC and trigger source*/
    BPWM_EnableADCTrigger(BPWM2, 4, NUCODEGEN_BPWM2_CH4_TRIGER_ADCSRC) ;

#endif /*NUCODEGEN_BPWM2_CH4_TRIGER_ADC_ENABLE*/

#if (((NUCODEGEN_BPWM2_CH4_INT_SEL) & 4))

    /* Enable duty interrupt - count up interrupt */
    BPWM_EnableDutyInt(BPWM2, 4, BPWM_DUTY_INT_UP_COUNT_MATCH_CMP) ;

#endif /*NUCODEGEN_BPWM2_CH4_INT_SEL*/

#if (((NUCODEGEN_BPWM2_CH4_INT_SEL) & 8))

    /* Enable duty interrupt - count down interrupt */
    BPWM_EnableDutyInt(BPWM2, 4, BPWM_DUTY_INT_DOWN_COUNT_MATCH_CMP) ;

#endif /*NUCODEGEN_BPWM2_CH4_INT_SEL*/

#endif /*NUCODEGEN_BPWM2_CH4_ADVANCED*/

#endif /*NUCODEGEN_BPWM2_CH4_ENABLE*/

#if NUCODEGEN_BPWM2_CH5_ENABLE

    /* Set the duty of BPWM2 CH5*/
    BPWM_SET_CMR(BPWM2, 5, NUCODEGEN_BPWM2_CH5_CMPDATA);

    /* Set output level of BPWM2 CH5*/
    BPWM_SET_OUTPUT_LEVEL(BPWM2, BIT5, NUCODEGEN_BPWM2_CH5_WAVEOUT_ZERO, NUCODEGEN_BPWM2_CH5_WAVEOUT_CMPUP, NUCODEGEN_BPWM2_CH5_WAVEOUT_PERIOD, NUCODEGEN_BPWM2_CH5_WAVEOUT_CMPDOWN);

    /* Enable output of BPWM2 channel 5 */
    BPWM_EnableOutput(BPWM2, BPWM_CH_5_MASK);

#if NUCODEGEN_BPWM2_CH5_ADVANCED

#if (NUCODEGEN_BPWM2_CH5_LOAD_MODE == 0)

    /* Period loading mode*/
    BPWM_DisableLoadMode(BPWM2, 5, BPWM_LOAD_MODE_IMMEDIATE|BPWM_LOAD_MODE_CENTER) ;

#elif (NUCODEGEN_BPWM2_CH5_LOAD_MODE == 1)

    /*Immediate loading mode*/
    BPWM_EnableLoadMode(BPWM2, 5, BPWM_LOAD_MODE_IMMEDIATE) ;

#elif (NUCODEGEN_BPWM2_CH5_LOAD_MODE == 2)

    /*Center loading mode*/
    BPWM_EnableLoadMode(BPWM2, 5, BPWM_LOAD_MODE_CENTER) ;

#endif /*NUCODEGEN_BPWM2_CH5_LOAD_MODE*/

#if (NUCODEGEN_BPWM2_CH5_OTHER_OUTPUT==1)

    /* Enable mask output and output high or low*/
    BPWM_SetMaskOutput(BPWM2, 5, NUCODEGEN_BPWM2_CH5_MASK_DATA);

#elif (NUCODEGEN_BPWM2_CH5_OTHER_OUTPUT==2)

    /* Enable inverter output */
    BPWM2->POLCTL |= BPWM_CH_5_MASK;

#endif /*NUCODEGEN_BPWM2_CH5_OTHER_OUTPUT*/

#if NUCODEGEN_BPWM2_CH5_TRIGER_ADC_ENABLE

    /* Set trigger ADC and trigger source*/
    BPWM_EnableADCTrigger(BPWM2, 5, NUCODEGEN_BPWM2_CH5_TRIGER_ADCSRC) ;

#endif /*NUCODEGEN_BPWM2_CH5_TRIGER_ADC_ENABLE*/

#if (((NUCODEGEN_BPWM2_CH5_INT_SEL) & 4))

    /* Enable duty interrupt - count up interrupt */
    BPWM_EnableDutyInt(BPWM2, 5, BPWM_DUTY_INT_UP_COUNT_MATCH_CMP) ;

#endif /*NUCODEGEN_BPWM2_CH5_INT_SEL*/

#if (((NUCODEGEN_BPWM2_CH5_INT_SEL) & 8))

    /* Enable duty interrupt - count down interrupt */
    BPWM_EnableDutyInt(BPWM2, 5, BPWM_DUTY_INT_DOWN_COUNT_MATCH_CMP) ;

#endif /*NUCODEGEN_BPWM2_CH5_INT_SEL*/

#endif /*NUCODEGEN_BPWM2_CH5_ADVANCED*/

#endif /*NUCODEGEN_BPWM2_CH5_ENABLE*/

#endif /*NUCODEGEN_BPWM2_OUTPUT_FUNC_SETMODE*/

#else

    /* Configure BPWM capture and get the nearest unit time */
    BPWM_ConfigCaptureChannel(BPWM2, 0, NUCODEGEN_BPWM2_CAP_UNITTIME, 0);

#if NUCODEGEN_BPWM2_CH0_CAP_ENABLE

    /* Set Reload Mode */
    BPWM2->CAPCTL |= (NUCODEGEN_BPWM2_CH0_CAP_RELOAD)<<BPWM_CAPCTL_RCRLDEN0_Pos;

    /* Enable Capture Function for BPWM2 channel 0 */
    BPWM_EnableCapture(BPWM2, BPWM_CH_0_MASK);

#if NUCODEGEN_BPWM2_CH0_CAP_ADVANCED

#if (NUCODEGEN_BPWM2_CH0_CAP_INT_SEL == 1)

    /*Enable rising latch capture interrupt*/
    BPWM_EnableCaptureInt(BPWM2, 0, BPWM_CAPTURE_INT_RISING_LATCH) ;

#elif (NUCODEGEN_BPWM2_CH0_CAP_INT_SEL == 2)

    /*Enable falling latch capture interrupt*/
    BPWM_EnableCaptureInt(BPWM2, 0, BPWM_CAPTURE_INT_FALLING_LATCH) ;

#elif (NUCODEGEN_BPWM2_CH0_CAP_INT_SEL == 3)

    /*Enable rising and falling latch capture interrupt*/
    BPWM_EnableCaptureInt(BPWM2, 0, BPWM_CAPTURE_INT_RISING_LATCH|BPWM_CAPTURE_INT_FALLING_LATCH) ;

#endif /*NUCODEGEN_BPWM2_CH0_CAP_INT_SEL*/

#endif /*NUCODEGEN_BPWM2_CH0_CAP_ADVANCED*/

#endif /*NUCODEGEN_BPWM2_CH0_CAP_ENABLE*/

#if NUCODEGEN_BPWM2_CH1_CAP_ENABLE

    /* Set Reload Mode */
    BPWM2->CAPCTL |= (NUCODEGEN_BPWM2_CH1_CAP_RELOAD)<<BPWM_CAPCTL_RCRLDEN1_Pos;

    /* Enable Capture Function for BPWM2 channel 1 */
    BPWM_EnableCapture(BPWM2, BPWM_CH_1_MASK);

#if NUCODEGEN_BPWM2_CH1_CAP_ADVANCED

#if (NUCODEGEN_BPWM2_CH1_CAP_INT_SEL == 1)

    /*Enable rising latch capture interrupt*/
    BPWM_EnableCaptureInt(BPWM2, 1, BPWM_CAPTURE_INT_RISING_LATCH) ;

#elif (NUCODEGEN_BPWM2_CH1_CAP_INT_SEL == 2)

    /*Enable falling latch capture interrupt*/
    BPWM_EnableCaptureInt(BPWM2, 1, BPWM_CAPTURE_INT_FALLING_LATCH) ;

#elif (NUCODEGEN_BPWM2_CH1_CAP_INT_SEL == 3)

    /*Enable rising and falling latch capture interrupt*/
    BPWM_EnableCaptureInt(BPWM2, 1, BPWM_CAPTURE_INT_RISING_LATCH|BPWM_CAPTURE_INT_FALLING_LATCH) ;

#endif /*NUCODEGEN_BPWM2_CH1_CAP_INT_SEL*/

#endif /*NUCODEGEN_BPWM2_CH1_CAP_ADVANCED*/

#endif /*NUCODEGEN_BPWM2_CH1_CAP_ENABLE*/

#if NUCODEGEN_BPWM2_CH2_CAP_ENABLE

    /* Set Reload Mode */
    BPWM2->CAPCTL |= (NUCODEGEN_BPWM2_CH2_CAP_RELOAD)<<BPWM_CAPCTL_RCRLDEN2_Pos;

    /* Enable Capture Function for BPWM2 channel 2 */
    BPWM_EnableCapture(BPWM2, BPWM_CH_2_MASK);

#if NUCODEGEN_BPWM2_CH2_CAP_ADVANCED

#if (NUCODEGEN_BPWM2_CH2_CAP_INT_SEL == 1)

    /*Enable rising latch capture interrupt*/
    BPWM_EnableCaptureInt(BPWM2, 2, BPWM_CAPTURE_INT_RISING_LATCH) ;

#elif (NUCODEGEN_BPWM2_CH2_CAP_INT_SEL == 2)

    /*Enable falling latch capture interrupt*/
    BPWM_EnableCaptureInt(BPWM2, 2, BPWM_CAPTURE_INT_FALLING_LATCH) ;

#elif (NUCODEGEN_BPWM2_CH2_CAP_INT_SEL == 3)

    /*Enable rising and falling latch capture interrupt*/
    BPWM_EnableCaptureInt(BPWM2, 2, BPWM_CAPTURE_INT_RISING_LATCH|BPWM_CAPTURE_INT_FALLING_LATCH) ;

#endif /*NUCODEGEN_BPWM2_CH2_CAP_INT_SEL*/

#endif /*NUCODEGEN_BPWM2_CH2_CAP_ADVANCED*/

#endif /*NUCODEGEN_BPWM2_CH2_CAP_ENABLE*/

#if NUCODEGEN_BPWM2_CH3_CAP_ENABLE

    /* Set Reload Mode */
    BPWM2->CAPCTL |= (NUCODEGEN_BPWM2_CH3_CAP_RELOAD)<<BPWM_CAPCTL_RCRLDEN3_Pos;

    /* Enable Capture Function for BPWM2 channel 3 */
    BPWM_EnableCapture(BPWM2, BPWM_CH_3_MASK);

#if NUCODEGEN_BPWM2_CH3_CAP_ADVANCED

#if (NUCODEGEN_BPWM2_CH3_CAP_INT_SEL == 1)

    /*Enable rising latch capture interrupt*/
    BPWM_EnableCaptureInt(BPWM2, 3, BPWM_CAPTURE_INT_RISING_LATCH) ;

#elif (NUCODEGEN_BPWM2_CH3_CAP_INT_SEL == 2)

    /*Enable falling latch capture interrupt*/
    BPWM_EnableCaptureInt(BPWM2, 3, BPWM_CAPTURE_INT_FALLING_LATCH) ;

#elif (NUCODEGEN_BPWM2_CH3_CAP_INT_SEL == 3)

    /*Enable rising and falling latch capture interrupt*/
    BPWM_EnableCaptureInt(BPWM2, 3, BPWM_CAPTURE_INT_RISING_LATCH|BPWM_CAPTURE_INT_FALLING_LATCH) ;

#endif /*NUCODEGEN_BPWM2_CH3_CAP_INT_SEL*/

#endif /*NUCODEGEN_BPWM2_CH3_CAP_ADVANCED*/

#endif /*NUCODEGEN_BPWM2_CH3_CAP_ENABLE*/

#if NUCODEGEN_BPWM2_CH4_CAP_ENABLE

    /* Set Reload Mode */
    BPWM2->CAPCTL |= (NUCODEGEN_BPWM2_CH4_CAP_RELOAD)<<BPWM_CAPCTL_RCRLDEN4_Pos;

    /* Enable Capture Function for BPWM2 channel 4 */
    BPWM_EnableCapture(BPWM2, BPWM_CH_4_MASK);

#if NUCODEGEN_BPWM2_CH4_CAP_ADVANCED

#if (NUCODEGEN_BPWM2_CH4_CAP_INT_SEL == 1)

    /*Enable rising latch capture interrupt*/
    BPWM_EnableCaptureInt(BPWM2, 4, BPWM_CAPTURE_INT_RISING_LATCH) ;

#elif (NUCODEGEN_BPWM2_CH4_CAP_INT_SEL == 2)

    /*Enable falling latch capture interrupt*/
    BPWM_EnableCaptureInt(BPWM2, 4, BPWM_CAPTURE_INT_FALLING_LATCH) ;

#elif (NUCODEGEN_BPWM2_CH4_CAP_INT_SEL == 3)

    /*Enable rising and falling latch capture interrupt*/
    BPWM_EnableCaptureInt(BPWM2, 4, BPWM_CAPTURE_INT_RISING_LATCH|BPWM_CAPTURE_INT_FALLING_LATCH) ;

#endif /*NUCODEGEN_BPWM2_CH4_CAP_INT_SEL*/

#endif /*NUCODEGEN_BPWM2_CH4_CAP_ADVANCED*/

#endif /*NUCODEGEN_BPWM2_CH4_CAP_ENABLE*/

#if NUCODEGEN_BPWM2_CH5_CAP_ENABLE

    /* Set Reload Mode */
    BPWM2->CAPCTL |= (NUCODEGEN_BPWM2_CH5_CAP_RELOAD)<<BPWM_CAPCTL_RCRLDEN5_Pos;

    /* Enable Capture Function for BPWM2 channel 5 */
    BPWM_EnableCapture(BPWM2, BPWM_CH_5_MASK);

#if NUCODEGEN_BPWM2_CH5_CAP_ADVANCED

#if (NUCODEGEN_BPWM2_CH5_CAP_INT_SEL == 1)

    /*Enable rising latch capture interrupt*/
    BPWM_EnableCaptureInt(BPWM2, 5, BPWM_CAPTURE_INT_RISING_LATCH) ;

#elif (NUCODEGEN_BPWM2_CH5_CAP_INT_SEL == 2)

    /*Enable falling latch capture interrupt*/
    BPWM_EnableCaptureInt(BPWM2, 5, BPWM_CAPTURE_INT_FALLING_LATCH) ;

#elif (NUCODEGEN_BPWM2_CH5_CAP_INT_SEL == 3)

    /*Enable rising and falling latch capture interrupt*/
    BPWM_EnableCaptureInt(BPWM2, 5, BPWM_CAPTURE_INT_RISING_LATCH|BPWM_CAPTURE_INT_FALLING_LATCH) ;

#endif /*NUCODEGEN_BPWM2_CH5_CAP_INT_SEL*/

#endif /*NUCODEGEN_BPWM2_CH5_CAP_ADVANCED*/

#endif /*NUCODEGEN_BPWM2_CH5_CAP_ENABLE*/

#endif /*NUCODEGEN_BPWM2_FUNC_SEL*/

}

#endif //NUCODEGEN_BPWM2

#if (NUCODEGEN_BPWM3)
void BPWM3_Init()
{

#if (NUCODEGEN_BPWM3_FUNC_SEL==0)

#if (NUCODEGEN_BPWM3_OUTPUT_FUNC_SETMODE==0)

#if NUCODEGEN_BPWM3_CH0_ENABLE

    /* Set BPWM3 channel 0 configuration */
    BPWM_ConfigOutputChannel(BPWM3, 0, NUCODEGEN_BPWM3_FREQ, NUCODEGEN_BPWM3_CH0_DUTY);

    /* Enable output of BPWM3 channel 0 */
    BPWM_EnableOutput(BPWM3, BPWM_CH_0_MASK);

#endif /*NUCODEGEN_BPWM3_CH0_ENABLE*/

#if NUCODEGEN_BPWM3_CH1_ENABLE

    /* Set BPWM3 channel 1 configuration */
    BPWM_ConfigOutputChannel(BPWM3, 1, NUCODEGEN_BPWM3_FREQ, NUCODEGEN_BPWM3_CH1_DUTY);

    /* Enable output of BPWM3 channel 1 */
    BPWM_EnableOutput(BPWM3, BPWM_CH_1_MASK);

#endif /*NUCODEGEN_BPWM3_CH1_ENABLE*/

#if NUCODEGEN_BPWM3_CH2_ENABLE
    /* Set BPWM3 channel 2 configuration */
    BPWM_ConfigOutputChannel(BPWM3, 2, NUCODEGEN_BPWM3_FREQ, NUCODEGEN_BPWM3_CH2_DUTY);
    /* Enable output of BPWM3 channel 2 */
    BPWM_EnableOutput(BPWM3, BPWM_CH_2_MASK);

#endif /*NUCODEGEN_BPWM3_CH2_ENABLE*/

#if NUCODEGEN_BPWM3_CH3_ENABLE
    /* Set BPWM3 channel 3 configuration */
    BPWM_ConfigOutputChannel(BPWM3, 3, NUCODEGEN_BPWM3_FREQ, NUCODEGEN_BPWM3_CH3_DUTY);
    /* Enable output of BPWM3 channel 3 */
    BPWM_EnableOutput(BPWM3, BPWM_CH_3_MASK);

#endif /*NUCODEGEN_BPWM3_CH3_ENABLE*/

#if NUCODEGEN_BPWM3_CH4_ENABLE
    /* Set BPWM3 channel 4 configuration */
    BPWM_ConfigOutputChannel(BPWM3, 4, NUCODEGEN_BPWM3_FREQ, NUCODEGEN_BPWM3_CH4_DUTY);
    /* Enable output of BPWM3 channel 4 */
    BPWM_EnableOutput(BPWM3, BPWM_CH_4_MASK);


#endif /*NUCODEGEN_BPWM3_CH4_ENABLE*/

#if NUCODEGEN_BPWM3_CH5_ENABLE

    /* Set BPWM3 channel 5 configuration */
    BPWM_ConfigOutputChannel(BPWM3, 5, NUCODEGEN_BPWM3_FREQ, NUCODEGEN_BPWM3_CH5_DUTY);

    /* Enable output of BPWM3 channel 5 */
    BPWM_EnableOutput(BPWM3, BPWM_CH_5_MASK);

#endif /*NUCODEGEN_BPWM3_CH5_ENABLE*/

#else

    /* Set BPWM3 clock source */
    BPWM_SetClockSource(BPWM3, 0, NUCODEGEN_BPWM3_CLKSRC);

    /* Set BPWM3 counter behavior type */
    BPWM_SET_ALIGNED_TYPE(BPWM3, BPWM_CH_0_MASK, NUCODEGEN_BPWM3_CNTTYPE);

    /* Set the prescaler of BPWM3  */
    BPWM_SET_PRESCALER(BPWM3, 0,NUCODEGEN_BPWM3_PRESCALER);

    /* Set the period of BPWM3 */
    BPWM_SET_CNR(BPWM3, 0, NUCODEGEN_BPWM3_PERIOD);

#if NUCODEGEN_BPWM3_SYNCSTART_ENABLE

    /* Enable timer synchronous start counting function */
    BPWM_ENABLE_TIMER_SYNC(BPWM3, BIT0, NUCODEGEN_BPWM3_SYNCSTART_SRC) ;

#endif /*NUCODEGEN_BPWM3_SYNCSTART_ENABLE*/


#if (((NUCODEGEN_BPWM3_CH0_INT_SEL) & 1)||((NUCODEGEN_BPWM3_CH1_INT_SEL) & 1)||((NUCODEGEN_BPWM3_CH2_INT_SEL) & 1)||((NUCODEGEN_BPWM3_CH3_INT_SEL) & 1)||((NUCODEGEN_BPWM3_CH4_INT_SEL) & 1)||((NUCODEGEN_BPWM3_CH5_INT_SEL) & 1))

    /* Enable zero interrupt */
    BPWM_EnableZeroInt(BPWM3, 0) ;

#endif

#if (((NUCODEGEN_BPWM3_CH0_INT_SEL) & 2)||((NUCODEGEN_BPWM3_CH1_INT_SEL) & 2)||((NUCODEGEN_BPWM3_CH2_INT_SEL) & 2)||((NUCODEGEN_BPWM3_CH3_INT_SEL) & 2)||((NUCODEGEN_BPWM3_CH4_INT_SEL) & 2)||((NUCODEGEN_BPWM3_CH5_INT_SEL) & 2))

    /* Enable period interrupt */
    BPWM_EnablePeriodInt(BPWM3, 0, 0) ;

#endif

#if NUCODEGEN_BPWM3_CH0_ENABLE

    /* Set the duty of BPWM3 CH0*/
    BPWM_SET_CMR(BPWM3, 0, NUCODEGEN_BPWM3_CH0_CMPDATA);

    /* Set output level of BPWM3 CH0*/
    BPWM_SET_OUTPUT_LEVEL(BPWM3, BIT0, NUCODEGEN_BPWM3_CH0_WAVEOUT_ZERO, NUCODEGEN_BPWM3_CH0_WAVEOUT_CMPUP, NUCODEGEN_BPWM3_CH0_WAVEOUT_PERIOD, NUCODEGEN_BPWM3_CH0_WAVEOUT_CMPDOWN);

    /* Enable output of BPWM3 channel 0 */
    BPWM_EnableOutput(BPWM3, BPWM_CH_0_MASK);

#if NUCODEGEN_BPWM3_CH0_ADVANCED

#if (NUCODEGEN_BPWM3_CH0_LOAD_MODE == 0)

    /* Period loading mode*/
    BPWM_DisableLoadMode(BPWM3, 0, BPWM_LOAD_MODE_IMMEDIATE|BPWM_LOAD_MODE_CENTER) ;

#elif (NUCODEGEN_BPWM3_CH0_LOAD_MODE == 1)

    /*Immediate loading mode*/
    BPWM_EnableLoadMode(BPWM3, 0, BPWM_LOAD_MODE_IMMEDIATE) ;

#elif (NUCODEGEN_BPWM3_CH0_LOAD_MODE == 2)

    /*Center loading mode*/
    BPWM_EnableLoadMode(BPWM3, 0, BPWM_LOAD_MODE_CENTER) ;

#endif /*NUCODEGEN_BPWM3_CH0_LOAD_MODE*/

#if (NUCODEGEN_BPWM3_CH0_OTHER_OUTPUT==1)

    /* Enable mask output and output high or low*/
    BPWM_SetMaskOutput(BPWM3, 0, NUCODEGEN_BPWM3_CH0_MASK_DATA);

#elif (NUCODEGEN_BPWM3_CH0_OTHER_OUTPUT==2)

    /* Enable inverter output */
    BPWM3->POLCTL |= BPWM_CH_0_MASK;

#endif /*NUCODEGEN_BPWM3_CH0_OTHER_OUTPUT*/

#if NUCODEGEN_BPWM3_CH0_TRIGER_ADC_ENABLE

    /* Set trigger ADC and trigger source*/
    BPWM_EnableADCTrigger(BPWM3, 0, NUCODEGEN_BPWM3_CH0_TRIGER_ADCSRC) ;

#endif /*NUCODEGEN_BPWM3_CH0_TRIGER_ADC_ENABLE*/

#if ((NUCODEGEN_BPWM3_CH0_INT_SEL) & 4)

    /* Enable duty interrupt - count up interrupt */
    BPWM_EnableDutyInt(BPWM3, 0, BPWM_DUTY_INT_UP_COUNT_MATCH_CMP) ;

#endif /*NUCODEGEN_BPWM3_CH0_INT_SEL*/

#if ((NUCODEGEN_BPWM3_CH0_INT_SEL) & 8)

    /* Enable duty interrupt - count down interrupt */
    BPWM_EnableDutyInt(BPWM3, 0, BPWM_DUTY_INT_DOWN_COUNT_MATCH_CMP) ;

#endif /*NUCODEGEN_BPWM3_CH0_INT_SEL*/

#endif /*NUCODEGEN_BPWM3_CH0_ADVANCED*/

#endif /*NUCODEGEN_BPWM3_CH0_ENABLE*/

#if NUCODEGEN_BPWM3_CH1_ENABLE

    /* Set the duty of BPWM3 CH1*/
    BPWM_SET_CMR(BPWM3, 1, NUCODEGEN_BPWM3_CH1_CMPDATA);

    /* Set output level of BPWM3 CH1*/
    BPWM_SET_OUTPUT_LEVEL(BPWM3, BIT1, NUCODEGEN_BPWM3_CH1_WAVEOUT_ZERO, NUCODEGEN_BPWM3_CH1_WAVEOUT_CMPUP, NUCODEGEN_BPWM3_CH1_WAVEOUT_PERIOD, NUCODEGEN_BPWM3_CH1_WAVEOUT_CMPDOWN);

    /* Enable output of BPWM3 channel 1 */
    BPWM_EnableOutput(BPWM3, BPWM_CH_1_MASK);

#if NUCODEGEN_BPWM3_CH1_ADVANCED

#if (NUCODEGEN_BPWM3_CH1_LOAD_MODE == 0)

    /* Period loading mode*/
    BPWM_DisableLoadMode(BPWM3, 1, BPWM_LOAD_MODE_IMMEDIATE|BPWM_LOAD_MODE_CENTER) ;

#elif (NUCODEGEN_BPWM3_CH1_LOAD_MODE == 1)

    /*Immediate loading mode*/
    BPWM_EnableLoadMode(BPWM3, 1, BPWM_LOAD_MODE_IMMEDIATE) ;

#elif (NUCODEGEN_BPWM3_CH1_LOAD_MODE == 2)

    /*Center loading mode*/
    BPWM_EnableLoadMode(BPWM3, 1, BPWM_LOAD_MODE_CENTER) ;

#endif /*NUCODEGEN_BPWM3_CH1_LOAD_MODE*/

#if (NUCODEGEN_BPWM3_CH1_OTHER_OUTPUT==1)

    /* Enable mask output and output high or low*/
    BPWM_SetMaskOutput(BPWM3, 1, NUCODEGEN_BPWM3_CH1_MASK_DATA);

#elif (NUCODEGEN_BPWM3_CH1_OTHER_OUTPUT==2)

    /* Enable inverter output */
    BPWM3->POLCTL |= BPWM_CH_1_MASK;

#endif /*NUCODEGEN_BPWM3_CH1_OTHER_OUTPUT*/

#if NUCODEGEN_BPWM3_CH1_TRIGER_ADC_ENABLE

    /* Set trigger ADC and trigger source*/
    BPWM_EnableADCTrigger(BPWM3, 1, NUCODEGEN_BPWM3_CH1_TRIGER_ADCSRC) ;

#endif /*NUCODEGEN_BPWM3_CH1_TRIGER_ADC_ENABLE*/

#if (((NUCODEGEN_BPWM3_CH1_INT_SEL) & 4))

    /* Enable duty interrupt - count up interrupt */
    BPWM_EnableDutyInt(BPWM3, 1, BPWM_DUTY_INT_UP_COUNT_MATCH_CMP) ;

#endif /*NUCODEGEN_BPWM3_CH1_INT_SEL*/

#if (((NUCODEGEN_BPWM3_CH1_INT_SEL) & 8))

    /* Enable duty interrupt - count down interrupt */
    BPWM_EnableDutyInt(BPWM3, 1, BPWM_DUTY_INT_DOWN_COUNT_MATCH_CMP) ;

#endif /*NUCODEGEN_BPWM3_CH1_INT_SEL*/

#endif /*NUCODEGEN_BPWM3_CH1_ADVANCED*/

#endif /*NUCODEGEN_BPWM3_CH1_ENABLE*/

#if NUCODEGEN_BPWM3_CH2_ENABLE

    /* Set the duty of BPWM3 CH2*/
    BPWM_SET_CMR(BPWM3, 2, NUCODEGEN_BPWM3_CH2_CMPDATA);

    /* Set output level of BPWM3 CH2*/
    BPWM_SET_OUTPUT_LEVEL(BPWM3, BIT2, NUCODEGEN_BPWM3_CH2_WAVEOUT_ZERO, NUCODEGEN_BPWM3_CH2_WAVEOUT_CMPUP, NUCODEGEN_BPWM3_CH2_WAVEOUT_PERIOD, NUCODEGEN_BPWM3_CH2_WAVEOUT_CMPDOWN);

    /* Enable output of BPWM3 channel 2 */
    BPWM_EnableOutput(BPWM3, BPWM_CH_2_MASK);

#if NUCODEGEN_BPWM3_CH2_ADVANCED

#if (NUCODEGEN_BPWM3_CH2_LOAD_MODE == 0)

    /* Period loading mode*/
    BPWM_DisableLoadMode(BPWM3, 2, BPWM_LOAD_MODE_IMMEDIATE|BPWM_LOAD_MODE_CENTER) ;

#elif (NUCODEGEN_BPWM3_CH2_LOAD_MODE == 1)

    /*Immediate loading mode*/
    BPWM_EnableLoadMode(BPWM3, 2, BPWM_LOAD_MODE_IMMEDIATE) ;

#elif (NUCODEGEN_BPWM3_CH2_LOAD_MODE == 2)

    /*Center loading mode*/
    BPWM_EnableLoadMode(BPWM3, 2, BPWM_LOAD_MODE_CENTER) ;

#endif /*NUCODEGEN_BPWM3_CH2_LOAD_MODE*/

#if (NUCODEGEN_BPWM3_CH2_OTHER_OUTPUT==1)

    /* Enable mask output and output high or low*/
    BPWM_SetMaskOutput(BPWM3, 2, NUCODEGEN_BPWM3_CH2_MASK_DATA);

#elif (NUCODEGEN_BPWM3_CH2_OTHER_OUTPUT==2)

    /* Enable inverter output */
    BPWM3->POLCTL |= BPWM_CH_2_MASK;

#endif /*NUCODEGEN_BPWM3_CH2_OTHER_OUTPUT*/

#if NUCODEGEN_BPWM3_CH2_TRIGER_ADC_ENABLE

    /* Set trigger ADC and trigger source*/
    BPWM_EnableADCTrigger(BPWM3, 2, NUCODEGEN_BPWM3_CH2_TRIGER_ADCSRC) ;

#endif /*NUCODEGEN_BPWM3_CH2_TRIGER_ADC_ENABLE*/

#if (((NUCODEGEN_BPWM3_CH2_INT_SEL) & 4))

    /* Enable duty interrupt - count up interrupt */
    BPWM_EnableDutyInt(BPWM3, 2, BPWM_DUTY_INT_UP_COUNT_MATCH_CMP) ;

#endif /*NUCODEGEN_BPWM3_CH2_INT_SEL*/

#if (((NUCODEGEN_BPWM3_CH2_INT_SEL) & 8))

    /* Enable duty interrupt - count down interrupt */
    BPWM_EnableDutyInt(BPWM3, 2, BPWM_DUTY_INT_DOWN_COUNT_MATCH_CMP) ;

#endif /*NUCODEGEN_BPWM3_CH2_INT_SEL*/

#endif /*NUCODEGEN_BPWM3_CH2_ADVANCED*/

#endif /*NUCODEGEN_BPWM3_CH2_ENABLE*/

#if NUCODEGEN_BPWM3_CH3_ENABLE

    /* Set the duty of BPWM3 CH3*/
    BPWM_SET_CMR(BPWM3, 3, NUCODEGEN_BPWM3_CH3_CMPDATA);

    /* Set output level of BPWM3 CH3*/
    BPWM_SET_OUTPUT_LEVEL(BPWM3, BIT3, NUCODEGEN_BPWM3_CH3_WAVEOUT_ZERO, NUCODEGEN_BPWM3_CH3_WAVEOUT_CMPUP, NUCODEGEN_BPWM3_CH3_WAVEOUT_PERIOD, NUCODEGEN_BPWM3_CH3_WAVEOUT_CMPDOWN);

    /* Enable output of BPWM3 channel 3 */
    BPWM_EnableOutput(BPWM3, BPWM_CH_3_MASK);

#if NUCODEGEN_BPWM3_CH3_ADVANCED

#if (NUCODEGEN_BPWM3_CH3_LOAD_MODE == 0)

    /* Period loading mode*/
    BPWM_DisableLoadMode(BPWM3, 3, BPWM_LOAD_MODE_IMMEDIATE|BPWM_LOAD_MODE_CENTER) ;

#elif (NUCODEGEN_BPWM3_CH3_LOAD_MODE == 1)

    /*Immediate loading mode*/
    BPWM_EnableLoadMode(BPWM3, 3, BPWM_LOAD_MODE_IMMEDIATE) ;

#elif (NUCODEGEN_BPWM3_CH3_LOAD_MODE == 2)

    /*Center loading mode*/
    BPWM_EnableLoadMode(BPWM3, 3, BPWM_LOAD_MODE_CENTER) ;

#endif /*NUCODEGEN_BPWM3_CH3_LOAD_MODE*/

#if (NUCODEGEN_BPWM3_CH3_OTHER_OUTPUT==1)

    /* Enable mask output and output high or low*/
    BPWM_SetMaskOutput(BPWM3, 3, NUCODEGEN_BPWM3_CH3_MASK_DATA);

#elif (NUCODEGEN_BPWM3_CH3_OTHER_OUTPUT==2)

    /* Enable inverter output */
    BPWM3->POLCTL |= BPWM_CH_3_MASK;

#endif /*NUCODEGEN_BPWM3_CH3_OTHER_OUTPUT*/

#if NUCODEGEN_BPWM3_CH3_TRIGER_ADC_ENABLE

    /* Set trigger ADC and trigger source*/
    BPWM_EnableADCTrigger(BPWM3, 3, NUCODEGEN_BPWM3_CH3_TRIGER_ADCSRC) ;

#endif /*NUCODEGEN_BPWM3_CH3_TRIGER_ADC_ENABLE*/

#if (((NUCODEGEN_BPWM3_CH3_INT_SEL) & 4))

    /* Enable duty interrupt - count up interrupt */
    BPWM_EnableDutyInt(BPWM3, 3, BPWM_DUTY_INT_UP_COUNT_MATCH_CMP) ;

#endif /*NUCODEGEN_BPWM3_CH3_INT_SEL*/

#if (((NUCODEGEN_BPWM3_CH3_INT_SEL) & 8))

    /* Enable duty interrupt - count down interrupt */
    BPWM_EnableDutyInt(BPWM3, 3, BPWM_DUTY_INT_DOWN_COUNT_MATCH_CMP) ;

#endif /*NUCODEGEN_BPWM3_CH3_INT_SEL*/

#endif /*NUCODEGEN_BPWM3_CH3_ADVANCED*/

#endif /*NUCODEGEN_BPWM3_CH3_ENABLE*/

#if NUCODEGEN_BPWM3_CH4_ENABLE

    /* Set the duty of BPWM3 CH4*/
    BPWM_SET_CMR(BPWM3, 4, NUCODEGEN_BPWM3_CH4_CMPDATA);

    /* Set output level of BPWM3 CH4*/
    BPWM_SET_OUTPUT_LEVEL(BPWM3, BIT4, NUCODEGEN_BPWM3_CH4_WAVEOUT_ZERO, NUCODEGEN_BPWM3_CH4_WAVEOUT_CMPUP, NUCODEGEN_BPWM3_CH4_WAVEOUT_PERIOD, NUCODEGEN_BPWM3_CH4_WAVEOUT_CMPDOWN);

    /* Enable output of BPWM3 channel 4 */
    BPWM_EnableOutput(BPWM3, BPWM_CH_4_MASK);

#if NUCODEGEN_BPWM3_CH4_ADVANCED

#if (NUCODEGEN_BPWM3_CH4_LOAD_MODE == 0)

    /* Period loading mode*/
    BPWM_DisableLoadMode(BPWM3, 4, BPWM_LOAD_MODE_IMMEDIATE|BPWM_LOAD_MODE_CENTER) ;

#elif (NUCODEGEN_BPWM3_CH4_LOAD_MODE == 1)

    /*Immediate loading mode*/
    BPWM_EnableLoadMode(BPWM3, 4, BPWM_LOAD_MODE_IMMEDIATE) ;

#elif (NUCODEGEN_BPWM3_CH4_LOAD_MODE == 2)

    /*Center loading mode*/
    BPWM_EnableLoadMode(BPWM3, 4, BPWM_LOAD_MODE_CENTER) ;

#endif /*NUCODEGEN_BPWM3_CH4_LOAD_MODE*/

#if (NUCODEGEN_BPWM3_CH4_OTHER_OUTPUT==1)

    /* Enable mask output and output high or low*/
    BPWM_SetMaskOutput(BPWM3, 4, NUCODEGEN_BPWM3_CH4_MASK_DATA);

#elif (NUCODEGEN_BPWM3_CH4_OTHER_OUTPUT==2)

    /* Enable inverter output */
    BPWM3->POLCTL |= BPWM_CH_4_MASK;

#endif /*NUCODEGEN_BPWM3_CH4_OTHER_OUTPUT*/

#if NUCODEGEN_BPWM3_CH4_TRIGER_ADC_ENABLE

    /* Set trigger ADC and trigger source*/
    BPWM_EnableADCTrigger(BPWM3, 4, NUCODEGEN_BPWM3_CH4_TRIGER_ADCSRC) ;

#endif /*NUCODEGEN_BPWM3_CH4_TRIGER_ADC_ENABLE*/

#if (((NUCODEGEN_BPWM3_CH4_INT_SEL) & 4))

    /* Enable duty interrupt - count up interrupt */
    BPWM_EnableDutyInt(BPWM3, 4, BPWM_DUTY_INT_UP_COUNT_MATCH_CMP) ;

#endif /*NUCODEGEN_BPWM3_CH4_INT_SEL*/

#if (((NUCODEGEN_BPWM3_CH4_INT_SEL) & 8))

    /* Enable duty interrupt - count down interrupt */
    BPWM_EnableDutyInt(BPWM3, 4, BPWM_DUTY_INT_DOWN_COUNT_MATCH_CMP) ;

#endif /*NUCODEGEN_BPWM3_CH4_INT_SEL*/

#endif /*NUCODEGEN_BPWM3_CH4_ADVANCED*/

#endif /*NUCODEGEN_BPWM3_CH4_ENABLE*/

#if NUCODEGEN_BPWM3_CH5_ENABLE

    /* Set the duty of BPWM3 CH5*/
    BPWM_SET_CMR(BPWM3, 5, NUCODEGEN_BPWM3_CH5_CMPDATA);

    /* Set output level of BPWM3 CH5*/
    BPWM_SET_OUTPUT_LEVEL(BPWM3, BIT5, NUCODEGEN_BPWM3_CH5_WAVEOUT_ZERO, NUCODEGEN_BPWM3_CH5_WAVEOUT_CMPUP, NUCODEGEN_BPWM3_CH5_WAVEOUT_PERIOD, NUCODEGEN_BPWM3_CH5_WAVEOUT_CMPDOWN);

    /* Enable output of BPWM3 channel 5 */
    BPWM_EnableOutput(BPWM3, BPWM_CH_5_MASK);

#if NUCODEGEN_BPWM3_CH5_ADVANCED

#if (NUCODEGEN_BPWM3_CH5_LOAD_MODE == 0)

    /* Period loading mode*/
    BPWM_DisableLoadMode(BPWM3, 5, BPWM_LOAD_MODE_IMMEDIATE|BPWM_LOAD_MODE_CENTER) ;

#elif (NUCODEGEN_BPWM3_CH5_LOAD_MODE == 1)

    /*Immediate loading mode*/
    BPWM_EnableLoadMode(BPWM3, 5, BPWM_LOAD_MODE_IMMEDIATE) ;

#elif (NUCODEGEN_BPWM3_CH5_LOAD_MODE == 2)

    /*Center loading mode*/
    BPWM_EnableLoadMode(BPWM3, 5, BPWM_LOAD_MODE_CENTER) ;

#endif /*NUCODEGEN_BPWM3_CH5_LOAD_MODE*/

#if (NUCODEGEN_BPWM3_CH5_OTHER_OUTPUT==1)

    /* Enable mask output and output high or low*/
    BPWM_SetMaskOutput(BPWM3, 5, NUCODEGEN_BPWM3_CH5_MASK_DATA);

#elif (NUCODEGEN_BPWM3_CH5_OTHER_OUTPUT==2)

    /* Enable inverter output */
    BPWM3->POLCTL |= BPWM_CH_5_MASK;

#endif /*NUCODEGEN_BPWM3_CH5_OTHER_OUTPUT*/

#if NUCODEGEN_BPWM3_CH5_TRIGER_ADC_ENABLE

    /* Set trigger ADC and trigger source*/
    BPWM_EnableADCTrigger(BPWM3, 5, NUCODEGEN_BPWM3_CH5_TRIGER_ADCSRC) ;

#endif /*NUCODEGEN_BPWM3_CH5_TRIGER_ADC_ENABLE*/

#if (((NUCODEGEN_BPWM3_CH5_INT_SEL) & 4))

    /* Enable duty interrupt - count up interrupt */
    BPWM_EnableDutyInt(BPWM3, 5, BPWM_DUTY_INT_UP_COUNT_MATCH_CMP) ;

#endif /*NUCODEGEN_BPWM3_CH5_INT_SEL*/

#if (((NUCODEGEN_BPWM3_CH5_INT_SEL) & 8))

    /* Enable duty interrupt - count down interrupt */
    BPWM_EnableDutyInt(BPWM3, 5, BPWM_DUTY_INT_DOWN_COUNT_MATCH_CMP) ;

#endif /*NUCODEGEN_BPWM3_CH5_INT_SEL*/

#endif /*NUCODEGEN_BPWM3_CH5_ADVANCED*/

#endif /*NUCODEGEN_BPWM3_CH5_ENABLE*/

#endif /*NUCODEGEN_BPWM3_OUTPUT_FUNC_SETMODE*/

#else

    /* Configure BPWM capture and get the nearest unit time */
    BPWM_ConfigCaptureChannel(BPWM3, 0, NUCODEGEN_BPWM3_CAP_UNITTIME, 0);

#if NUCODEGEN_BPWM3_CH0_CAP_ENABLE

    /* Set Reload Mode */
    BPWM3->CAPCTL |= (NUCODEGEN_BPWM3_CH0_CAP_RELOAD)<<BPWM_CAPCTL_RCRLDEN0_Pos;

    /* Enable Capture Function for BPWM3 channel 0 */
    BPWM_EnableCapture(BPWM3, BPWM_CH_0_MASK);

#if NUCODEGEN_BPWM3_CH0_CAP_ADVANCED

#if (NUCODEGEN_BPWM3_CH0_CAP_INT_SEL == 1)

    /*Enable rising latch capture interrupt*/
    BPWM_EnableCaptureInt(BPWM3, 0, BPWM_CAPTURE_INT_RISING_LATCH) ;

#elif (NUCODEGEN_BPWM3_CH0_CAP_INT_SEL == 2)

    /*Enable falling latch capture interrupt*/
    BPWM_EnableCaptureInt(BPWM3, 0, BPWM_CAPTURE_INT_FALLING_LATCH) ;

#elif (NUCODEGEN_BPWM3_CH0_CAP_INT_SEL == 3)

    /*Enable rising and falling latch capture interrupt*/
    BPWM_EnableCaptureInt(BPWM3, 0, BPWM_CAPTURE_INT_RISING_LATCH|BPWM_CAPTURE_INT_FALLING_LATCH) ;

#endif /*NUCODEGEN_BPWM3_CH0_CAP_INT_SEL*/

#endif /*NUCODEGEN_BPWM3_CH0_CAP_ADVANCED*/

#endif /*NUCODEGEN_BPWM3_CH0_CAP_ENABLE*/

#if NUCODEGEN_BPWM3_CH1_CAP_ENABLE

    /* Set Reload Mode */
    BPWM3->CAPCTL |= (NUCODEGEN_BPWM3_CH1_CAP_RELOAD)<<BPWM_CAPCTL_RCRLDEN1_Pos;

    /* Enable Capture Function for BPWM3 channel 1 */
    BPWM_EnableCapture(BPWM3, BPWM_CH_1_MASK);

#if NUCODEGEN_BPWM3_CH1_CAP_ADVANCED

#if (NUCODEGEN_BPWM3_CH1_CAP_INT_SEL == 1)

    /*Enable rising latch capture interrupt*/
    BPWM_EnableCaptureInt(BPWM3, 1, BPWM_CAPTURE_INT_RISING_LATCH) ;

#elif (NUCODEGEN_BPWM3_CH1_CAP_INT_SEL == 2)

    /*Enable falling latch capture interrupt*/
    BPWM_EnableCaptureInt(BPWM3, 1, BPWM_CAPTURE_INT_FALLING_LATCH) ;

#elif (NUCODEGEN_BPWM3_CH1_CAP_INT_SEL == 3)

    /*Enable rising and falling latch capture interrupt*/
    BPWM_EnableCaptureInt(BPWM3, 1, BPWM_CAPTURE_INT_RISING_LATCH|BPWM_CAPTURE_INT_FALLING_LATCH) ;

#endif /*NUCODEGEN_BPWM3_CH1_CAP_INT_SEL*/

#endif /*NUCODEGEN_BPWM3_CH1_CAP_ADVANCED*/

#endif /*NUCODEGEN_BPWM3_CH1_CAP_ENABLE*/

#if NUCODEGEN_BPWM3_CH2_CAP_ENABLE

    /* Set Reload Mode */
    BPWM3->CAPCTL |= (NUCODEGEN_BPWM3_CH2_CAP_RELOAD)<<BPWM_CAPCTL_RCRLDEN2_Pos;

    /* Enable Capture Function for BPWM3 channel 2 */
    BPWM_EnableCapture(BPWM3, BPWM_CH_2_MASK);

#if NUCODEGEN_BPWM3_CH2_CAP_ADVANCED

#if (NUCODEGEN_BPWM3_CH2_CAP_INT_SEL == 1)

    /*Enable rising latch capture interrupt*/
    BPWM_EnableCaptureInt(BPWM3, 2, BPWM_CAPTURE_INT_RISING_LATCH) ;

#elif (NUCODEGEN_BPWM3_CH2_CAP_INT_SEL == 2)

    /*Enable falling latch capture interrupt*/
    BPWM_EnableCaptureInt(BPWM3, 2, BPWM_CAPTURE_INT_FALLING_LATCH) ;

#elif (NUCODEGEN_BPWM3_CH2_CAP_INT_SEL == 3)

    /*Enable rising and falling latch capture interrupt*/
    BPWM_EnableCaptureInt(BPWM3, 2, BPWM_CAPTURE_INT_RISING_LATCH|BPWM_CAPTURE_INT_FALLING_LATCH) ;

#endif /*NUCODEGEN_BPWM3_CH2_CAP_INT_SEL*/

#endif /*NUCODEGEN_BPWM3_CH2_CAP_ADVANCED*/

#endif /*NUCODEGEN_BPWM3_CH2_CAP_ENABLE*/

#if NUCODEGEN_BPWM3_CH3_CAP_ENABLE

    /* Set Reload Mode */
    BPWM3->CAPCTL |= (NUCODEGEN_BPWM3_CH3_CAP_RELOAD)<<BPWM_CAPCTL_RCRLDEN3_Pos;

    /* Enable Capture Function for BPWM3 channel 3 */
    BPWM_EnableCapture(BPWM3, BPWM_CH_3_MASK);

#if NUCODEGEN_BPWM3_CH3_CAP_ADVANCED

#if (NUCODEGEN_BPWM3_CH3_CAP_INT_SEL == 1)

    /*Enable rising latch capture interrupt*/
    BPWM_EnableCaptureInt(BPWM3, 3, BPWM_CAPTURE_INT_RISING_LATCH) ;

#elif (NUCODEGEN_BPWM3_CH3_CAP_INT_SEL == 2)

    /*Enable falling latch capture interrupt*/
    BPWM_EnableCaptureInt(BPWM3, 3, BPWM_CAPTURE_INT_FALLING_LATCH) ;

#elif (NUCODEGEN_BPWM3_CH3_CAP_INT_SEL == 3)

    /*Enable rising and falling latch capture interrupt*/
    BPWM_EnableCaptureInt(BPWM3, 3, BPWM_CAPTURE_INT_RISING_LATCH|BPWM_CAPTURE_INT_FALLING_LATCH) ;

#endif /*NUCODEGEN_BPWM3_CH3_CAP_INT_SEL*/

#endif /*NUCODEGEN_BPWM3_CH3_CAP_ADVANCED*/

#endif /*NUCODEGEN_BPWM3_CH3_CAP_ENABLE*/

#if NUCODEGEN_BPWM3_CH4_CAP_ENABLE

    /* Set Reload Mode */
    BPWM3->CAPCTL |= (NUCODEGEN_BPWM3_CH4_CAP_RELOAD)<<BPWM_CAPCTL_RCRLDEN4_Pos;

    /* Enable Capture Function for BPWM3 channel 4 */
    BPWM_EnableCapture(BPWM3, BPWM_CH_4_MASK);

#if NUCODEGEN_BPWM3_CH4_CAP_ADVANCED

#if (NUCODEGEN_BPWM3_CH4_CAP_INT_SEL == 1)

    /*Enable rising latch capture interrupt*/
    BPWM_EnableCaptureInt(BPWM3, 4, BPWM_CAPTURE_INT_RISING_LATCH) ;

#elif (NUCODEGEN_BPWM3_CH4_CAP_INT_SEL == 2)

    /*Enable falling latch capture interrupt*/
    BPWM_EnableCaptureInt(BPWM3, 4, BPWM_CAPTURE_INT_FALLING_LATCH) ;

#elif (NUCODEGEN_BPWM3_CH4_CAP_INT_SEL == 3)

    /*Enable rising and falling latch capture interrupt*/
    BPWM_EnableCaptureInt(BPWM3, 4, BPWM_CAPTURE_INT_RISING_LATCH|BPWM_CAPTURE_INT_FALLING_LATCH) ;

#endif /*NUCODEGEN_BPWM3_CH4_CAP_INT_SEL*/

#endif /*NUCODEGEN_BPWM3_CH4_CAP_ADVANCED*/

#endif /*NUCODEGEN_BPWM3_CH4_CAP_ENABLE*/

#if NUCODEGEN_BPWM3_CH5_CAP_ENABLE

    /* Set Reload Mode */
    BPWM3->CAPCTL |= (NUCODEGEN_BPWM3_CH5_CAP_RELOAD)<<BPWM_CAPCTL_RCRLDEN5_Pos;

    /* Enable Capture Function for BPWM3 channel 5 */
    BPWM_EnableCapture(BPWM3, BPWM_CH_5_MASK);

#if NUCODEGEN_BPWM3_CH5_CAP_ADVANCED

#if (NUCODEGEN_BPWM3_CH5_CAP_INT_SEL == 1)

    /*Enable rising latch capture interrupt*/
    BPWM_EnableCaptureInt(BPWM3, 5, BPWM_CAPTURE_INT_RISING_LATCH) ;

#elif (NUCODEGEN_BPWM3_CH5_CAP_INT_SEL == 2)

    /*Enable falling latch capture interrupt*/
    BPWM_EnableCaptureInt(BPWM3, 5, BPWM_CAPTURE_INT_FALLING_LATCH) ;

#elif (NUCODEGEN_BPWM3_CH5_CAP_INT_SEL == 3)

    /*Enable rising and falling latch capture interrupt*/
    BPWM_EnableCaptureInt(BPWM3, 5, BPWM_CAPTURE_INT_RISING_LATCH|BPWM_CAPTURE_INT_FALLING_LATCH) ;

#endif /*NUCODEGEN_BPWM3_CH5_CAP_INT_SEL*/

#endif /*NUCODEGEN_BPWM3_CH5_CAP_ADVANCED*/

#endif /*NUCODEGEN_BPWM3_CH5_CAP_ENABLE*/

#endif /*NUCODEGEN_BPWM3_FUNC_SEL*/

}

#endif //NUCODEGEN_BPWM3
