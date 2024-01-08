

#if ((NUCODEGEN_PWM0) || (NUCODEGEN_PWM1) )

void PWM_SetMaskOutput(PWM_T *pwm, uint32_t u32ChannelNum, uint32_t u32LevelMask)
{
    (pwm)->MSKEN |= 0x1<<u32ChannelNum;
    (pwm)->MSK |= (u32LevelMask<<u32ChannelNum);
}

void PWM_EnableBrake(PWM_T *pwm, uint32_t u32ChannelMask, uint32_t u32LevelMask, uint32_t u32BrakeSource, uint32_t u32BrakeTrigger)
{
    uint32_t i;

    for (i = 0UL; i < PWM_CHANNEL_NUM; i ++)
    {
        if (u32ChannelMask & (1UL << i))
        {
            if (u32BrakeSource & 0xF00)
            {
                (pwm)->BRKCTL[i >> 1UL] |= ((u32BrakeSource & 0xFF)<<u32BrakeTrigger);
                (pwm)->FAILBRK |= ((u32BrakeSource & 0xF00)>>8);
            }
            else
            {
                (pwm)->BRKCTL[i >> 1UL] |= (u32BrakeSource<<u32BrakeTrigger);
            }

            if ((i & 0x1UL) == 0UL)
            {
                switch ((u32LevelMask & (0x3UL << (i<<1)))>>(i<<1))
                {
                case 0:
                    (pwm)->BRKCTL[i >> 1UL] |= ((0UL) << PWM_BRKCTL_BRKAEVEN_Pos);
                    break;
                case 1:
                    (pwm)->BRKCTL[i >> 1UL] |= ((1UL) << PWM_BRKCTL_BRKAEVEN_Pos);
                    break;
                case 2:
                    (pwm)->BRKCTL[i >> 1UL] |= ((2UL) << PWM_BRKCTL_BRKAEVEN_Pos);
                    break;
                case 3:
                    (pwm)->BRKCTL[i >> 1UL] |= ((3UL) << PWM_BRKCTL_BRKAEVEN_Pos);
                    break;
                default:
                    (pwm)->BRKCTL[i >> 1UL] |= ((0UL) << PWM_BRKCTL_BRKAEVEN_Pos);
                    break;
                }
            }
            else
            {
                switch ((u32LevelMask & (0x3UL << (i<<1)))>>(i<<1))
                {
                case 0:
                    (pwm)->BRKCTL[i >> 1UL] |= ((0UL) << PWM_BRKCTL_BRKAODD_Pos);
                    break;
                case 1:
                    (pwm)->BRKCTL[i >> 1UL] |= ((1UL) << PWM_BRKCTL_BRKAODD_Pos);
                    break;
                case 2:
                    (pwm)->BRKCTL[i >> 1UL] |= ((2UL) << PWM_BRKCTL_BRKAODD_Pos);
                    break;
                case 3:
                    (pwm)->BRKCTL[i >> 1UL] |= ((3UL) << PWM_BRKCTL_BRKAODD_Pos);
                    break;
                default:
                    (pwm)->BRKCTL[i >> 1UL] |= ((0UL) << PWM_BRKCTL_BRKAODD_Pos);
                    break;
                }
            }
        }
    }

}

void PWM_EnableBrakeFilter(PWM_T *pwm, uint32_t u32BrakeSrc, uint32_t u32ClkCnt, uint32_t u32ClkDivSel)
{
    uint32_t u32SetData;

    u32SetData = ((u32ClkCnt << PWM_BNF_BRK0FCNT_Pos) | (u32ClkDivSel << PWM_BNF_BRK0NFSEL_Pos) | PWM_BNF_BRK0NFEN_Msk);

    if (u32BrakeSrc & (PWM_FB_EDGE_BKP0))
        (pwm)->BNF |= (u32SetData << (0 * PWM_BNF_BRK1NFEN_Pos));

    if (u32BrakeSrc & (PWM_FB_EDGE_BKP1))
        (pwm)->BNF |= (u32SetData << (1 * PWM_BNF_BRK1NFEN_Pos));
}

void PWM_EnableBrakePinInv(PWM_T *pwm, uint32_t u32BrakeSrc)
{
    uint32_t u32SetData;

    u32SetData = (1 << PWM_BNF_BRK0PINV_Pos);

    if (u32BrakeSrc & (PWM_FB_EDGE_BKP0))
        (pwm)->BNF |= (u32SetData << (0 * PWM_BNF_BRK1NFEN_Pos));

    if (u32BrakeSrc & (PWM_FB_EDGE_BKP1))
        (pwm)->BNF |= (u32SetData << (1 * PWM_BNF_BRK1NFEN_Pos));
}

#endif

#if (NUCODEGEN_PWM0)
void PWM0_Init()
{

#if NUCODEGEN_PWM0_CH0CH1

#if (NUCODEGEN_PWM0_CH0_1_FUNC_SEL==0)

#if (NUCODEGEN_PWM0_CH0_1_OUTPUT_FUNC_SETMODE==0)

#if NUCODEGEN_PWM0_CH0_ENABLE

    /* Set PWM0 channel 0 configuration */
    PWM_ConfigOutputChannel(PWM0, 0, NUCODEGEN_PWM0_CH0_1_FREQ, NUCODEGEN_PWM0_CH0_DUTY);

    /* Enable output of PWM0 channel 0 */
    PWM_EnableOutput(PWM0, PWM_CH_0_MASK);

#endif /*NUCODEGEN_PWM0_CH0_ENABLE*/

#if NUCODEGEN_PWM0_CH1_ENABLE

    /* Set PWM0 channel 1 configuration */
    PWM_ConfigOutputChannel(PWM0, 1, NUCODEGEN_PWM0_CH0_1_FREQ, NUCODEGEN_PWM0_CH1_DUTY);

    /* Enable output of PWM0 channel 1 */
    PWM_EnableOutput(PWM0, PWM_CH_1_MASK);

#endif /*NUCODEGEN_PWM0_CH1_ENABLE*/

#else

#if (NUCODEGEN_PWM0_CH0_ENABLE||NUCODEGEN_PWM0_CH1_ENABLE)

    /* Set PWM0 CH0_1 clock source */
    PWM_SetClockSource(PWM0, 0, NUCODEGEN_PWM0_CH0_1_CLKSRC);

    /* Set PWM0 CH0_1 counter behavior type */
    PWM_SET_ALIGNED_TYPE(PWM0, PWM_CH_0_MASK, NUCODEGEN_PWM0_CH0_1_CNTTYPE);

    /* Set the prescaler of PWM0 CH0_1*/
    PWM_SET_PRESCALER(PWM0, 0,NUCODEGEN_PWM0_CH0_1_PRESCALER);

    /* Set the period of PWM0 CH0_1*/
    PWM_SET_CNR(PWM0, 0, NUCODEGEN_PWM0_CH0_1_PERIOD);

#if NUCODEGEN_PWM0_CH0_1_SYNCSTART_ENABLE

    /* Enable timer synchronous start counting function */
    PWM_ENABLE_TIMER_SYNC(PWM0, BIT0, NUCODEGEN_PWM0_CH0_1_SYNCSTART_SRC);

#endif /*NUCODEGEN_PWM0_CH0_1_SYNCSTART_ENABLE*/

#if NUCODEGEN_PWM0_CH0_1_COMPLEMATARY_ENABLE

    /* Enable complementary mode */
    PWM0->CTL1 = PWM0->CTL1 | PWM_CTL1_OUTMODE0_Msk;

#if NUCODEGEN_PWM0_CH0_1_DEADTIME_ENABLE

    /* Enable Dead zone and set counter */
    PWM_EnableDeadZone(PWM0, 0, NUCODEGEN_PWM0_CH0_1_DEADTIME_CNT);

    /* Set Dead zone clock source */
    PWM_SET_DEADZONE_CLK_SRC(PWM0, 0, NUCODEGEN_PWM0_CH0_1_DEADTIME_CLKSRC);

#endif /*NUCODEGEN_PWM0_CH0_1_DEADTIME_ENABLE*/

#endif /*NUCODEGEN_PWM0_CH0_1_COMPLEMATARY_ENABLE*/

#if NUCODEGEN_PWM0_CH0_1_BRAKE_ENABLE

    /* Enable brake function and set the brake source */
    PWM_EnableBrake(PWM0, PWM_CH_0_MASK|PWM_CH_1_MASK, (NUCODEGEN_PWM0_CH1_BRAKE_ACTION<<(1*2))| NUCODEGEN_PWM0_CH0_BRAKE_ACTION, NUCODEGEN_PWM0_CH0_1_BRAKE_SRC, NUCODEGEN_PWM0_CH0_1_BRAKE_DETECT_TYPE);

#endif /*NUCODEGEN_PWM0_CH0_1_BRAKE_ENABLE*/

#if ((NUCODEGEN_PWM0_CH0_INT_SEL) & 1)

    /* Enable zero interrupt - PWM two channals has one controller  */
    PWM_EnableZeroInt(PWM0, 0);

#endif /*NUCODEGEN_PWM0_CH0_INT_SEL*/

#if ((NUCODEGEN_PWM0_CH0_INT_SEL) & 2)

    /* Enable period interrupt - PWM two channals has one controller  */
    PWM_EnablePeriodInt(PWM0, 0, 0);

#endif /*NUCODEGEN_PWM0_CH0_INT_SEL*/

#if (((NUCODEGEN_PWM0_CH0_INT_SEL) & 16) || ((NUCODEGEN_PWM0_CH1_INT_SEL) & 16))

    /* Enable fault brake interrupt */
    PWM0->INTEN1 |= (1 << NUCODEGEN_PWM0_CH0_1_BRAKE_DETECT_TYPE);

#endif /*NUCODEGEN_PWM0_CH0_INT_SEL*/

#if NUCODEGEN_PWM0_CH0_ENABLE

    /* Set the duty of PWM0 CH0*/
    PWM_SET_CMR(PWM0, 0, NUCODEGEN_PWM0_CH0_CMPDATA);

    /* Set output level of PWM0 CH0*/
    PWM_SET_OUTPUT_LEVEL(PWM0, PWM_CH_0_MASK, NUCODEGEN_PWM0_CH0_WAVEOUT_ZERO, NUCODEGEN_PWM0_CH0_WAVEOUT_CMPUP, NUCODEGEN_PWM0_CH0_WAVEOUT_PERIOD, NUCODEGEN_PWM0_CH0_WAVEOUT_CMPDOWN);

    /* Enable output of PWM0 channel 0 */
    PWM_EnableOutput(PWM0, PWM_CH_0_MASK);

#if NUCODEGEN_PWM0_CH0_ADVANCED

#if (NUCODEGEN_PWM0_CH0_LOAD_MODE == 0)

    /* Period loading mode*/
    PWM_DisableLoadMode(PWM0, 0, PWM_LOAD_MODE_IMMEDIATE|PWM_LOAD_MODE_CENTER);

#elif (NUCODEGEN_PWM0_CH0_LOAD_MODE == 1)

    /*Immediate loading mode*/
    PWM_EnableLoadMode(PWM0, 0, PWM_LOAD_MODE_IMMEDIATE);

#elif (NUCODEGEN_PWM0_CH0_LOAD_MODE == 2)

    /*Center loading mode*/
    PWM_EnableLoadMode(PWM0, 0, PWM_LOAD_MODE_CENTER);

#endif /*NUCODEGEN_PWM0_CH0_LOAD_MODE*/

#if (NUCODEGEN_PWM0_CH0_OTHER_OUTPUT==1)

    /* Enable mask output and output high or low*/
    PWM_SetMaskOutput(PWM0, 0, NUCODEGEN_PWM0_CH0_MASK_DATA);

#elif (NUCODEGEN_PWM0_CH0_OTHER_OUTPUT==2)

    /* Enable inverter output */
    PWM0->POLCTL |= PWM_CH_0_MASK;

#endif /*NUCODEGEN_PWM0_CH0_OTHER_OUTPUT*/

#if NUCODEGEN_PWM0_CH0_TRIGER_ADC_ENABLE

    /* Set trigger ADC and trigger source*/
    PWM_EnableADCTrigger(PWM0, 0, NUCODEGEN_PWM0_CH0_TRIGER_ADCSRC);

#endif /*NUCODEGEN_PWM0_CH0_TRIGER_ADC_ENABLE*/

#if ((NUCODEGEN_PWM0_CH0_INT_SEL) & 4)

    /* Enable duty interrupt - count up interrupt */
    PWM_EnableDutyInt(PWM0, 0, PWM_DUTY_INT_UP_COUNT_MATCH_CMP);

#endif /*NUCODEGEN_PWM0_CH0_INT_SEL*/

#if ((NUCODEGEN_PWM0_CH0_INT_SEL) & 8)

    /* Enable duty interrupt - count down interrupt */
    PWM_EnableDutyInt(PWM0, 0, PWM_DUTY_INT_DOWN_COUNT_MATCH_CMP);

#endif /*NUCODEGEN_PWM0_CH0_INT_SEL*/

#endif /*NUCODEGEN_PWM0_CH0_ADVANCED*/

#endif /*NUCODEGEN_PWM0_CH0_ENABLE*/

#if NUCODEGEN_PWM0_CH1_ENABLE

    /* Set the duty of PWM0 CH1*/
    PWM_SET_CMR(PWM0, 1, NUCODEGEN_PWM0_CH1_CMPDATA);

    /* Set output level of PWM0 CH1*/
    PWM_SET_OUTPUT_LEVEL(PWM0, PWM_CH_1_MASK, NUCODEGEN_PWM0_CH1_WAVEOUT_ZERO, NUCODEGEN_PWM0_CH1_WAVEOUT_CMPUP, NUCODEGEN_PWM0_CH1_WAVEOUT_PERIOD, NUCODEGEN_PWM0_CH1_WAVEOUT_CMPDOWN);

    /* Enable output of PWM0 channel 1 */
    PWM_EnableOutput(PWM0, PWM_CH_1_MASK);

#if NUCODEGEN_PWM0_CH1_ADVANCED

#if (NUCODEGEN_PWM0_CH1_LOAD_MODE == 0)

    /* Period loading mode*/
    PWM_DisableLoadMode(PWM0, 1, PWM_LOAD_MODE_IMMEDIATE|PWM_LOAD_MODE_CENTER);

#elif (NUCODEGEN_PWM0_CH1_LOAD_MODE == 1)

    /*Immediate loading mode*/
    PWM_EnableLoadMode(PWM0, 1, PWM_LOAD_MODE_IMMEDIATE);

#elif (NUCODEGEN_PWM0_CH1_LOAD_MODE == 2)

    /*Center loading mode*/
    PWM_EnableLoadMode(PWM0, 1, PWM_LOAD_MODE_CENTER);

#endif /*NUCODEGEN_PWM0_CH1_LOAD_MODE*/

#if (NUCODEGEN_PWM0_CH1_OTHER_OUTPUT==1)

    /* Enable mask output and output high or low*/
    PWM_SetMaskOutput(PWM0, 1, NUCODEGEN_PWM0_CH1_MASK_DATA);

#elif (NUCODEGEN_PWM0_CH1_OTHER_OUTPUT==2)

    /* Enable inverter output */
    PWM0->POLCTL |= PWM_CH_1_MASK;

#endif /*NUCODEGEN_PWM0_CH1_OTHER_OUTPUT*/

#if NUCODEGEN_PWM0_CH1_TRIGER_ADC_ENABLE

    /* Set trigger ADC and trigger source*/
    PWM_EnableADCTrigger(PWM0, 1, NUCODEGEN_PWM0_CH1_TRIGER_ADCSRC);

#endif /*NUCODEGEN_PWM0_CH1_TRIGER_ADC_ENABLE*/

#if ((NUCODEGEN_PWM0_CH1_INT_SEL) & 4)

    /* Enable duty interrupt - count up interrupt */
    PWM_EnableDutyInt(PWM0, 1, PWM_DUTY_INT_UP_COUNT_MATCH_CMP);

#endif /*NUCODEGEN_PWM0_CH1_INT_SEL*/

#if ((NUCODEGEN_PWM0_CH1_INT_SEL) & 8)

    /* Enable duty interrupt - count down interrupt */
    PWM_EnableDutyInt(PWM0, 1, PWM_DUTY_INT_DOWN_COUNT_MATCH_CMP);

#endif /*NUCODEGEN_PWM0_CH1_INT_SEL*/

#endif /*NUCODEGEN_PWM0_CH1_ADVANCED*/

#endif /*NUCODEGEN_PWM0_CH1_ENABLE*/



#endif /*NUCODEGEN_PWM0_CH0_ENABLE,NUCODEGEN_PWM0_CH1_ENABLE*/

#endif /*NUCODEGEN_PWM0_CH0_1_OUTPUT_FUNC_SETMODE*/

#else

#if (NUCODEGEN_PWM0_CH0_CAP_ENABLE || NUCODEGEN_PWM0_CH1_CAP_ENABLE)

    /* Configure PWM capture and get the nearest unit time */
    PWM_ConfigCaptureChannel(PWM0, 0, NUCODEGEN_PWM0_CH0_1_CAP_UNITTIME, 0);

#if NUCODEGEN_PWM0_CH0_CAP_ENABLE

    /* Set Reload Mode */
    PWM0->CAPCTL |= (NUCODEGEN_PWM0_CH0_CAP_RELOAD)<<PWM_CAPCTL_RCRLDEN0_Pos;

    /* Enable Capture Function for PWM0 channel 0 */
    PWM_EnableCapture(PWM0, PWM_CH_0_MASK);

#if NUCODEGEN_PWM0_CH0_CAP_ADVANCED

#if (NUCODEGEN_PWM0_CH0_CAP_INT_SEL == 1)

    /*Enable rising latch capture interrupt*/
    PWM_EnableCaptureInt(PWM0, 0, PWM_CAPTURE_INT_RISING_LATCH);

#elif (NUCODEGEN_PWM0_CH0_CAP_INT_SEL == 2)

    /*Enable falling latch capture interrupt*/
    PWM_EnableCaptureInt(PWM0, 0, PWM_CAPTURE_INT_FALLING_LATCH);

#elif (NUCODEGEN_PWM0_CH0_CAP_INT_SEL == 3)

    /*Enable rising and falling latch capture interrupt*/
    PWM_EnableCaptureInt(PWM0, 0, PWM_CAPTURE_INT_RISING_LATCH|PWM_CAPTURE_INT_FALLING_LATCH);

#endif /*NUCODEGEN_PWM0_CH0_CAP_INT_SEL*/

#endif /*NUCODEGEN_PWM0_CH0_CAP_ADVANCED*/

#endif /*NUCODEGEN_PWM0_CH0_CAP_ENABLE*/

#if NUCODEGEN_PWM0_CH1_CAP_ENABLE

    /* Set Reload Mode */
    PWM0->CAPCTL |= (NUCODEGEN_PWM0_CH1_CAP_RELOAD)<<PWM_CAPCTL_RCRLDEN1_Pos;

    /* Enable Capture Function for PWM0 channel 1 */
    PWM_EnableCapture(PWM0, PWM_CH_1_MASK);

#if NUCODEGEN_PWM0_CH1_CAP_ADVANCED

#if (NUCODEGEN_PWM0_CH1_CAP_INT_SEL == 1)

    /*Enable rising latch capture interrupt*/
    PWM_EnableCaptureInt(PWM0, 1, PWM_CAPTURE_INT_RISING_LATCH);

#elif (NUCODEGEN_PWM0_CH1_CAP_INT_SEL == 2)

    /*Enable falling latch capture interrupt*/
    PWM_EnableCaptureInt(PWM0, 1, PWM_CAPTURE_INT_FALLING_LATCH);

#elif (NUCODEGEN_PWM0_CH1_CAP_INT_SEL == 3)

    /*Enable rising and falling latch capture interrupt*/
    PWM_EnableCaptureInt(PWM0, 1, PWM_CAPTURE_INT_RISING_LATCH|PWM_CAPTURE_INT_FALLING_LATCH);

#endif /*NUCODEGEN_PWM0_CH1_CAP_INT_SEL*/

#endif /*NUCODEGEN_PWM0_CH1_CAP_ADVANCED*/

#endif /*NUCODEGEN_PWM0_CH1_CAP_ENABLE*/

#endif /*NUCODEGEN_PWM0_CH0_CAP_ENABLE, NUCODEGEN_PWM0_CH1_CAP_ENABLE*/

#endif /*NUCODEGEN_PWM0_FUNC_SEL*/

#endif /*NUCODEGEN_PWM0_CH0CH1*/

#if NUCODEGEN_PWM0_CH2CH3

#if (NUCODEGEN_PWM0_CH2_3_FUNC_SEL==0)

#if (NUCODEGEN_PWM0_CH2_3_OUTPUT_FUNC_SETMODE==0)

#if NUCODEGEN_PWM0_CH2_ENABLE

    /* Set PWM0 channel 2 configuration */
    PWM_ConfigOutputChannel(PWM0, 2, NUCODEGEN_PWM0_CH2_3_FREQ, NUCODEGEN_PWM0_CH2_DUTY);

    /* Enable output of PWM0 channel 2 */
    PWM_EnableOutput(PWM0, PWM_CH_2_MASK);

#endif /*NUCODEGEN_PWM0_CH2_ENABLE*/

#if NUCODEGEN_PWM0_CH3_ENABLE

    /* Set PWM0 channel 3 configuration */
    PWM_ConfigOutputChannel(PWM0, 3, NUCODEGEN_PWM0_CH2_3_FREQ, NUCODEGEN_PWM0_CH3_DUTY);

    /* Enable output of PWM0 channel 3 */
    PWM_EnableOutput(PWM0, PWM_CH_3_MASK);

#endif /*NUCODEGEN_PWM0_CH3_ENABLE*/

#else

#if (NUCODEGEN_PWM0_CH2_ENABLE||NUCODEGEN_PWM0_CH3_ENABLE)

    /* Set PWM0 CH2_3 clock source */
    PWM_SetClockSource(PWM0, 2, NUCODEGEN_PWM0_CH2_3_CLKSRC);

    /* Set PWM0 CH2_3 counter behavior type */
    PWM_SET_ALIGNED_TYPE(PWM0, PWM_CH_2_MASK, NUCODEGEN_PWM0_CH2_3_CNTTYPE);

    /* Set the prescaler of PWM0 CH2_3*/
    PWM_SET_PRESCALER(PWM0, 2, NUCODEGEN_PWM0_CH2_3_PRESCALER);

    /* Set the period of PWM0 CH2_3*/
    PWM_SET_CNR(PWM0, 2, NUCODEGEN_PWM0_CH2_3_PERIOD);

#if NUCODEGEN_PWM0_CH2_3_SYNCSTART_ENABLE

    /* Enable timer synchronous start counting function */
    PWM_ENABLE_TIMER_SYNC(PWM0, BIT2, NUCODEGEN_PWM0_CH2_3_SYNCSTART_SRC);

#endif /*NUCODEGEN_PWM0_CH2_3_SYNCSTART_ENABLE*/

#if NUCODEGEN_PWM0_CH2_3_COMPLEMATARY_ENABLE

    /* Enable complementary mode */
    PWM0->CTL1 = PWM0->CTL1 | PWM_CTL1_OUTMODE2_Msk;

#if NUCODEGEN_PWM0_CH2_3_DEADTIME_ENABLE

    /* Enable Dead zone and set counter */
    PWM_EnableDeadZone(PWM0, 2, NUCODEGEN_PWM0_CH2_3_DEADTIME_CNT);

    /* Set Dead zone clock source */
    PWM_SET_DEADZONE_CLK_SRC(PWM0, 2, NUCODEGEN_PWM0_CH2_3_DEADTIME_CLKSRC);

#endif /*NUCODEGEN_PWM0_CH2_3_DEADTIME_ENABLE*/

#endif /*NUCODEGEN_PWM0_CH2_3_COMPLEMATARY_ENABLE*/


#if NUCODEGEN_PWM0_CH2_3_BRAKE_ENABLE

    /* Enable brake function and set the brake source */
    PWM_EnableBrake(PWM0, PWM_CH_2_MASK|PWM_CH_3_MASK, (NUCODEGEN_PWM0_CH3_BRAKE_ACTION<<(3*2))| (NUCODEGEN_PWM0_CH2_BRAKE_ACTION<<(2*2)), NUCODEGEN_PWM0_CH2_3_BRAKE_SRC, NUCODEGEN_PWM0_CH2_3_BRAKE_DETECT_TYPE);

#endif /*NUCODEGEN_PWM0_CH2_3_BRAKE_ENABLE*/

#if ((NUCODEGEN_PWM0_CH2_INT_SEL) & 1)

    /* Enable zero interrupt - PWM two channals has one controller  */
    PWM_EnableZeroInt(PWM0, 2);

#endif /*NUCODEGEN_PWM0_CH2_INT_SEL*/

#if ((NUCODEGEN_PWM0_CH2_INT_SEL) & 2)

    /* Enable period interrupt - PWM two channals has one controller  */
    PWM_EnablePeriodInt(PWM0, 2, 0);

#endif /*NUCODEGEN_PWM0_CH2_INT_SEL*/

#if (((NUCODEGEN_PWM0_CH2_INT_SEL) & 16) || ((NUCODEGEN_PWM0_CH3_INT_SEL) & 16))

    /* Enable fault brake interrupt */
    PWM0->INTEN1 |= (0x2 << NUCODEGEN_PWM0_CH2_3_BRAKE_DETECT_TYPE);

#endif /*NUCODEGEN_PWM0_CH2_INT_SEL*/

#if NUCODEGEN_PWM0_CH2_ENABLE

    /* Set the duty of PWM0 CH2*/
    PWM_SET_CMR(PWM0, 2, NUCODEGEN_PWM0_CH2_CMPDATA);

    /* Set output level of PWM0 CH2*/
    PWM_SET_OUTPUT_LEVEL(PWM0, PWM_CH_2_MASK, NUCODEGEN_PWM0_CH2_WAVEOUT_ZERO, NUCODEGEN_PWM0_CH2_WAVEOUT_CMPUP, NUCODEGEN_PWM0_CH2_WAVEOUT_PERIOD, NUCODEGEN_PWM0_CH2_WAVEOUT_CMPDOWN);

    /* Enable output of PWM0 channel 2 */
    PWM_EnableOutput(PWM0, PWM_CH_2_MASK);

#if NUCODEGEN_PWM0_CH2_ADVANCED

#if (NUCODEGEN_PWM0_CH2_LOAD_MODE == 0)

    /* Period loading mode*/
    PWM_DisableLoadMode(PWM0, 2, PWM_LOAD_MODE_IMMEDIATE|PWM_LOAD_MODE_CENTER);

#elif (NUCODEGEN_PWM0_CH2_LOAD_MODE == 1)

    /*Immediate loading mode*/
    PWM_EnableLoadMode(PWM0, 2, PWM_LOAD_MODE_IMMEDIATE);

#elif (NUCODEGEN_PWM0_CH2_LOAD_MODE == 2)

    /*Center loading mode*/
    PWM_EnableLoadMode(PWM0, 2, PWM_LOAD_MODE_CENTER);

#endif /*NUCODEGEN_PWM0_CH2_LOAD_MODE*/

#if (NUCODEGEN_PWM0_CH2_OTHER_OUTPUT==1)

    /* Enable mask output and output high or low*/
    PWM_SetMaskOutput(PWM0, 2, NUCODEGEN_PWM0_CH2_MASK_DATA);

#elif (NUCODEGEN_PWM0_CH2_OTHER_OUTPUT==2)

    /* Enable inverter output */
    PWM0->POLCTL |= PWM_CH_2_MASK;

#endif /*NUCODEGEN_PWM0_CH2_OTHER_OUTPUT*/

#if NUCODEGEN_PWM0_CH2_TRIGER_ADC_ENABLE

    /* Set trigger ADC and trigger source*/
    PWM_EnableADCTrigger(PWM0, 2, NUCODEGEN_PWM0_CH2_TRIGER_ADCSRC);

#endif /*NUCODEGEN_PWM0_CH2_TRIGER_ADC_ENABLE*/

#if ((NUCODEGEN_PWM0_CH2_INT_SEL) & 4)

    /* Enable duty interrupt - count up interrupt */
    PWM_EnableDutyInt(PWM0, 2, PWM_DUTY_INT_UP_COUNT_MATCH_CMP);

#endif /*NUCODEGEN_PWM0_CH2_INT_SEL*/

#if ((NUCODEGEN_PWM0_CH2_INT_SEL) & 8)

    /* Enable duty interrupt - count down interrupt */
    PWM_EnableDutyInt(PWM0, 2, PWM_DUTY_INT_DOWN_COUNT_MATCH_CMP);

#endif /*NUCODEGEN_PWM0_CH2_INT_SEL*/

#endif /*NUCODEGEN_PWM0_CH2_ADVANCED*/

#endif /*NUCODEGEN_PWM0_CH2_ENABLE*/

#if NUCODEGEN_PWM0_CH3_ENABLE

    /* Set the duty of PWM0 CH3*/
    PWM_SET_CMR(PWM0, 3, NUCODEGEN_PWM0_CH3_CMPDATA);

    /* Set output level of PWM0 CH3*/
    PWM_SET_OUTPUT_LEVEL(PWM0, PWM_CH_3_MASK, NUCODEGEN_PWM0_CH3_WAVEOUT_ZERO, NUCODEGEN_PWM0_CH3_WAVEOUT_CMPUP, NUCODEGEN_PWM0_CH3_WAVEOUT_PERIOD, NUCODEGEN_PWM0_CH3_WAVEOUT_CMPDOWN);

    /* Enable output of PWM0 channel 3 */
    PWM_EnableOutput(PWM0, PWM_CH_3_MASK);

#if NUCODEGEN_PWM0_CH3_ADVANCED

#if (NUCODEGEN_PWM0_CH3_LOAD_MODE == 0)

    /* Period loading mode*/
    PWM_DisableLoadMode(PWM0, 3, PWM_LOAD_MODE_IMMEDIATE|PWM_LOAD_MODE_CENTER);

#elif (NUCODEGEN_PWM0_CH3_LOAD_MODE == 1)

    /*Immediate loading mode*/
    PWM_EnableLoadMode(PWM0, 3, PWM_LOAD_MODE_IMMEDIATE);

#elif (NUCODEGEN_PWM0_CH3_LOAD_MODE == 2)

    /*Center loading mode*/
    PWM_EnableLoadMode(PWM0, 3, PWM_LOAD_MODE_CENTER);

#endif /*NUCODEGEN_PWM0_CH3_LOAD_MODE*/

#if (NUCODEGEN_PWM0_CH3_OTHER_OUTPUT==1)

    /* Enable mask output and output high or low*/
    PWM_SetMaskOutput(PWM0, 3, NUCODEGEN_PWM0_CH3_MASK_DATA);

#elif (NUCODEGEN_PWM0_CH3_OTHER_OUTPUT==2)

    /* Enable inverter output */
    PWM0->POLCTL |= PWM_CH_3_MASK;

#endif /*NUCODEGEN_PWM0_CH3_OTHER_OUTPUT*/

#if NUCODEGEN_PWM0_CH3_TRIGER_ADC_ENABLE

    /* Set trigger ADC and trigger source*/
    PWM_EnableADCTrigger(PWM0, 3, NUCODEGEN_PWM0_CH3_TRIGER_ADCSRC);

#endif /*NUCODEGEN_PWM0_CH3_TRIGER_ADC_ENABLE*/

#if ((NUCODEGEN_PWM0_CH3_INT_SEL) & 4)

    /* Enable duty interrupt - count up interrupt */
    PWM_EnableDutyInt(PWM0, 3, PWM_DUTY_INT_UP_COUNT_MATCH_CMP);

#endif /*NUCODEGEN_PWM0_CH3_INT_SEL*/

#if ((NUCODEGEN_PWM0_CH3_INT_SEL) & 8)

    /* Enable duty interrupt - count down interrupt */
    PWM_EnableDutyInt(PWM0, 3, PWM_DUTY_INT_DOWN_COUNT_MATCH_CMP);

#endif /*NUCODEGEN_PWM0_CH3_INT_SEL*/

#endif /*NUCODEGEN_PWM0_CH3_ADVANCED*/

#endif /*NUCODEGEN_PWM0_CH3_ENABLE*/

#endif /*NUCODEGEN_PWM0_CH2_ENABLE,NUCODEGEN_PWM0_CH3_ENABLE*/

#endif /*NUCODEGEN_PWM0_CH2_3_OUTPUT_FUNC_SETMODE*/

#else

#if (NUCODEGEN_PWM0_CH2_CAP_ENABLE || NUCODEGEN_PWM0_CH3_CAP_ENABLE)

    /* Configure PWM capture and get the nearest unit time */
    PWM_ConfigCaptureChannel(PWM0, 2, NUCODEGEN_PWM0_CH2_3_CAP_UNITTIME, 0);

#if NUCODEGEN_PWM0_CH2_CAP_ENABLE

    /* Set Reload Mode */
    PWM0->CAPCTL |= (NUCODEGEN_PWM0_CH2_CAP_RELOAD)<<PWM_CAPCTL_RCRLDEN2_Pos;

    /* Enable Capture Function for PWM0 channel 2 */
    PWM_EnableCapture(PWM0, PWM_CH_2_MASK);

#if NUCODEGEN_PWM0_CH2_CAP_ADVANCED

#if (NUCODEGEN_PWM0_CH2_CAP_INT_SEL == 1)

    /*Enable rising latch capture interrupt*/
    PWM_EnableCaptureInt(PWM0, 2, PWM_CAPTURE_INT_RISING_LATCH);

#elif (NUCODEGEN_PWM0_CH2_CAP_INT_SEL == 2)

    /*Enable falling latch capture interrupt*/
    PWM_EnableCaptureInt(PWM0, 2, PWM_CAPTURE_INT_FALLING_LATCH);

#elif (NUCODEGEN_PWM0_CH2_CAP_INT_SEL == 3)

    /*Enable rising and falling latch capture interrupt*/
    PWM_EnableCaptureInt(PWM0, 2, PWM_CAPTURE_INT_RISING_LATCH|PWM_CAPTURE_INT_FALLING_LATCH);

#endif /*NUCODEGEN_PWM0_CH2_CAP_INT_SEL*/

#endif /*NUCODEGEN_PWM0_CH2_CAP_ADVANCED*/

#endif /*NUCODEGEN_PWM0_CH2_CAP_ENABLE*/

#if NUCODEGEN_PWM0_CH3_CAP_ENABLE

    /* Set Reload Mode */
    PWM0->CAPCTL |= (NUCODEGEN_PWM0_CH3_CAP_RELOAD)<<PWM_CAPCTL_RCRLDEN3_Pos;

    /* Enable Capture Function for PWM0 channel 3 */
    PWM_EnableCapture(PWM0, PWM_CH_3_MASK);

#if NUCODEGEN_PWM0_CH3_CAP_ADVANCED

#if (NUCODEGEN_PWM0_CH3_CAP_INT_SEL == 1)

    /*Enable rising latch capture interrupt*/
    PWM_EnableCaptureInt(PWM0, 3, PWM_CAPTURE_INT_RISING_LATCH);

#elif (NUCODEGEN_PWM0_CH3_CAP_INT_SEL == 2)

    /*Enable falling latch capture interrupt*/
    PWM_EnableCaptureInt(PWM0, 3, PWM_CAPTURE_INT_FALLING_LATCH);

#elif (NUCODEGEN_PWM0_CH3_CAP_INT_SEL == 3)

    /*Enable rising and falling latch capture interrupt*/
    PWM_EnableCaptureInt(PWM0, 3, PWM_CAPTURE_INT_RISING_LATCH|PWM_CAPTURE_INT_FALLING_LATCH);

#endif /*NUCODEGEN_PWM0_CH3_CAP_INT_SEL*/

#endif /*NUCODEGEN_PWM0_CH3_CAP_ADVANCED*/

#endif /*NUCODEGEN_PWM0_CH3_CAP_ENABLE*/

#endif /*NUCODEGEN_PWM0_CH2_CAP_ENABLE, NUCODEGEN_PWM0_CH3_CAP_ENABLE*/

#endif /*NUCODEGEN_PWM0_CH2_3_FUNC_SEL*/

#endif /*NUCODEGEN_PWM0_CH2CH3*/

#if NUCODEGEN_PWM0_CH4CH5

#if (NUCODEGEN_PWM0_CH4_5_FUNC_SEL==0)

#if (NUCODEGEN_PWM0_CH4_5_OUTPUT_FUNC_SETMODE==0)

#if NUCODEGEN_PWM0_CH4_ENABLE

    /* Set PWM0 channel 4 configuration */
    PWM_ConfigOutputChannel(PWM0, 4, NUCODEGEN_PWM0_CH4_5_FREQ, NUCODEGEN_PWM0_CH4_DUTY);

    /* Enable output of PWM0 channel 4 */
    PWM_EnableOutput(PWM0, PWM_CH_4_MASK);

#endif /*NUCODEGEN_PWM0_CH4_ENABLE*/

#if NUCODEGEN_PWM0_CH5_ENABLE

    /* Set PWM0 channel 5 configuration */
    PWM_ConfigOutputChannel(PWM0, 5, NUCODEGEN_PWM0_CH4_5_FREQ, NUCODEGEN_PWM0_CH5_DUTY);

    /* Enable output of PWM0 channel 5 */
    PWM_EnableOutput(PWM0, PWM_CH_5_MASK);

#endif /*NUCODEGEN_PWM0_CH5_ENABLE*/

#else

#if (NUCODEGEN_PWM0_CH4_ENABLE||NUCODEGEN_PWM0_CH5_ENABLE)

    /* Set PWM0 CH4_5 clock source */
    PWM_SetClockSource(PWM0, 4, NUCODEGEN_PWM0_CH4_5_CLKSRC);

    /* Set PWM0 CH4_5 counter behavior type */
    PWM_SET_ALIGNED_TYPE(PWM0, PWM_CH_4_MASK, NUCODEGEN_PWM0_CH4_5_CNTTYPE);

    /* Set the prescaler of PWM0 CH4_5*/
    PWM_SET_PRESCALER(PWM0, 4, NUCODEGEN_PWM0_CH4_5_PRESCALER);

    /* Set the period of PWM0 CH4_5*/
    PWM_SET_CNR(PWM0, 4, NUCODEGEN_PWM0_CH4_5_PERIOD);

#if NUCODEGEN_PWM0_CH4_5_SYNCSTART_ENABLE

    /* Enable timer synchronous start counting function */
    PWM_ENABLE_TIMER_SYNC(PWM0, BIT4, NUCODEGEN_PWM0_CH4_5_SYNCSTART_SRC);

#endif /*NUCODEGEN_PWM0_CH4_5_SYNCSTART_ENABLE*/

#if NUCODEGEN_PWM0_CH4_5_COMPLEMATARY_ENABLE

    /* Enable complementary mode */
    PWM0->CTL1 = PWM0->CTL1 | PWM_CTL1_OUTMODE4_Msk;

#if NUCODEGEN_PWM0_CH4_5_DEADTIME_ENABLE

    /* Enable Dead zone and set counter */
    PWM_EnableDeadZone(PWM0, 4, NUCODEGEN_PWM0_CH4_5_DEADTIME_CNT);

    /* Set Dead zone clock source */
    PWM_SET_DEADZONE_CLK_SRC(PWM0, 4, NUCODEGEN_PWM0_CH4_5_DEADTIME_CLKSRC);

#endif /*NUCODEGEN_PWM0_CH4_5_DEADTIME_ENABLE*/

#endif /*NUCODEGEN_PWM0_CH4_5_COMPLEMATARY_ENABLE*/

#if NUCODEGEN_PWM0_CH4_5_BRAKE_ENABLE

    /* Enable brake function and set the brake source */
    PWM_EnableBrake(PWM0, PWM_CH_4_MASK|PWM_CH_5_MASK, (NUCODEGEN_PWM0_CH5_BRAKE_ACTION<<(5*2))| (NUCODEGEN_PWM0_CH4_BRAKE_ACTION<<(4*2)), NUCODEGEN_PWM0_CH4_5_BRAKE_SRC, NUCODEGEN_PWM0_CH4_5_BRAKE_DETECT_TYPE);

#endif /*NUCODEGEN_PWM0_CH0_1_BRAKE_ENABLE*/

#if ((NUCODEGEN_PWM0_CH4_INT_SEL) & 1)

    /* Enable zero interrupt - PWM two channals has one controller  */
    PWM_EnableZeroInt(PWM0, 4);

#endif /*NUCODEGEN_PWM0_CH4_INT_SEL*/

#if ((NUCODEGEN_PWM0_CH4_INT_SEL) & 2)

    /* Enable period interrupt - PWM two channals has one controller  */
    PWM_EnablePeriodInt(PWM0, 4, 0);

#endif /*NUCODEGEN_PWM0_CH4_INT_SEL*/

#if (((NUCODEGEN_PWM0_CH4_INT_SEL) & 16) || ((NUCODEGEN_PWM0_CH5_INT_SEL) & 16))

    /* Enable fault brake interrupt */
    PWM0->INTEN1 |= (0x4 << NUCODEGEN_PWM0_CH4_5_BRAKE_DETECT_TYPE);

#endif /*NUCODEGEN_PWM0_CH0_INT_SEL*/

#if NUCODEGEN_PWM0_CH4_ENABLE

    /* Set the duty of PWM0 CH4*/
    PWM_SET_CMR(PWM0, 4, NUCODEGEN_PWM0_CH4_CMPDATA);

    /* Set output level of PWM0 CH4*/
    PWM_SET_OUTPUT_LEVEL(PWM0, PWM_CH_4_MASK, NUCODEGEN_PWM0_CH4_WAVEOUT_ZERO, NUCODEGEN_PWM0_CH4_WAVEOUT_CMPUP, NUCODEGEN_PWM0_CH4_WAVEOUT_PERIOD, NUCODEGEN_PWM0_CH4_WAVEOUT_CMPDOWN);

    /* Enable output of PWM0 channel 4 */
    PWM_EnableOutput(PWM0, PWM_CH_4_MASK);

#if NUCODEGEN_PWM0_CH4_ADVANCED

#if (NUCODEGEN_PWM0_CH4_LOAD_MODE == 0)

    /* Period loading mode*/
    PWM_DisableLoadMode(PWM0, 4, PWM_LOAD_MODE_IMMEDIATE|PWM_LOAD_MODE_CENTER);

#elif (NUCODEGEN_PWM0_CH4_LOAD_MODE == 1)

    /*Immediate loading mode*/
    PWM_EnableLoadMode(PWM0, 4, PWM_LOAD_MODE_IMMEDIATE);

#elif (NUCODEGEN_PWM0_CH4_LOAD_MODE == 2)

    /*Center loading mode*/
    PWM_EnableLoadMode(PWM0, 4, PWM_LOAD_MODE_CENTER);

#endif /*NUCODEGEN_PWM0_CH4_LOAD_MODE*/

#if (NUCODEGEN_PWM0_CH4_OTHER_OUTPUT==1)

    /* Enable mask output and output high or low*/
    PWM_SetMaskOutput(PWM0, 4, NUCODEGEN_PWM0_CH4_MASK_DATA);

#elif (NUCODEGEN_PWM0_CH4_OTHER_OUTPUT==2)

    /* Enable inverter output */
    PWM0->POLCTL |= PWM_CH_4_MASK;

#endif /*NUCODEGEN_PWM0_CH4_OTHER_OUTPUT*/

#if NUCODEGEN_PWM0_CH4_TRIGER_ADC_ENABLE

    /* Set trigger ADC and trigger source*/
    PWM_EnableADCTrigger(PWM0, 4, NUCODEGEN_PWM0_CH4_TRIGER_ADCSRC);

#endif /*NUCODEGEN_PWM0_CH4_TRIGER_ADC_ENABLE*/

#if ((NUCODEGEN_PWM0_CH4_INT_SEL) & 4)

    /* Enable duty interrupt - count up interrupt */
    PWM_EnableDutyInt(PWM0, 4, PWM_DUTY_INT_UP_COUNT_MATCH_CMP);

#endif /*NUCODEGEN_PWM0_CH4_INT_SEL*/

#if ((NUCODEGEN_PWM0_CH4_INT_SEL) & 8)

    /* Enable duty interrupt - count down interrupt */
    PWM_EnableDutyInt(PWM0, 4, PWM_DUTY_INT_DOWN_COUNT_MATCH_CMP);

#endif /*NUCODEGEN_PWM0_CH4_INT_SEL*/

#endif /*NUCODEGEN_PWM0_CH4_ADVANCED*/

#endif /*NUCODEGEN_PWM0_CH4_ENABLE*/

#if NUCODEGEN_PWM0_CH5_ENABLE

    /* Set the duty of PWM0 CH5*/
    PWM_SET_CMR(PWM0, 5, NUCODEGEN_PWM0_CH5_CMPDATA);

    /* Set output level of PWM0 CH5*/
    PWM_SET_OUTPUT_LEVEL(PWM0, PWM_CH_5_MASK, NUCODEGEN_PWM0_CH5_WAVEOUT_ZERO, NUCODEGEN_PWM0_CH5_WAVEOUT_CMPUP, NUCODEGEN_PWM0_CH5_WAVEOUT_PERIOD, NUCODEGEN_PWM0_CH5_WAVEOUT_CMPDOWN);

    /* Enable output of PWM0 channel 5 */
    PWM_EnableOutput(PWM0, PWM_CH_5_MASK);

#if NUCODEGEN_PWM0_CH5_ADVANCED

#if (NUCODEGEN_PWM0_CH5_LOAD_MODE == 0)

    /* Period loading mode*/
    PWM_DisableLoadMode(PWM0, 5, PWM_LOAD_MODE_IMMEDIATE|PWM_LOAD_MODE_CENTER);

#elif (NUCODEGEN_PWM0_CH5_LOAD_MODE == 1)

    /*Center loading mode*/
    PWM_EnableLoadMode(PWM0, 5, PWM_LOAD_MODE_IMMEDIATE);

#elif (NUCODEGEN_PWM0_CH5_LOAD_MODE == 2)

    /*Center loading mode*/
    PWM_EnableLoadMode(PWM0, 5, PWM_LOAD_MODE_CENTER);

#endif /*NUCODEGEN_PWM0_CH5_LOAD_MODE*/

#if (NUCODEGEN_PWM0_CH5_OTHER_OUTPUT==1)

    /* Enable mask output and output high or low*/
    PWM_SetMaskOutput(PWM0, 5, NUCODEGEN_PWM0_CH5_MASK_DATA);

#elif (NUCODEGEN_PWM0_CH5_OTHER_OUTPUT==2)

    /* Enable inverter output */
    PWM0->POLCTL |= PWM_CH_5_MASK;

#endif /*NUCODEGEN_PWM0_CH5_OTHER_OUTPUT*/

#if NUCODEGEN_PWM0_CH5_TRIGER_ADC_ENABLE

    /* Set trigger ADC and trigger source*/
    PWM_EnableADCTrigger(PWM0, 5, NUCODEGEN_PWM0_CH5_TRIGER_ADCSRC);

#endif /*NUCODEGEN_PWM0_CH5_TRIGER_ADC_ENABLE*/

#if ((NUCODEGEN_PWM0_CH5_INT_SEL) & 4)

    /* Enable duty interrupt - count up interrupt */
    PWM_EnableDutyInt(PWM0, 5, PWM_DUTY_INT_UP_COUNT_MATCH_CMP);

#endif /*NUCODEGEN_PWM0_CH5_INT_SEL*/

#if ((NUCODEGEN_PWM0_CH5_INT_SEL) & 8)

    /* Enable duty interrupt - count down interrupt */
    PWM_EnableDutyInt(PWM0, 5, PWM_DUTY_INT_DOWN_COUNT_MATCH_CMP);

#endif /*NUCODEGEN_PWM0_CH5_INT_SEL*/

#endif /*NUCODEGEN_PWM0_CH5_ADVANCED*/

#endif /*NUCODEGEN_PWM0_CH5_ENABLE*/

#endif

#endif /*NUCODEGEN_PWM0_CH4_5_OUTPUT_FUNC_SETMODE*/

#else

#if (NUCODEGEN_PWM0_CH4_CAP_ENABLE || NUCODEGEN_PWM0_CH5_CAP_ENABLE)

    /* Configure PWM capture and get the nearest unit time */
    PWM_ConfigCaptureChannel(PWM0, 4, NUCODEGEN_PWM0_CH4_5_CAP_UNITTIME, 0);

#if NUCODEGEN_PWM0_CH4_CAP_ENABLE

    /* Set Reload Mode */
    PWM0->CAPCTL |= (NUCODEGEN_PWM0_CH4_CAP_RELOAD)<<PWM_CAPCTL_RCRLDEN4_Pos;

    /* Enable Capture Function for PWM0 channel 4 */
    PWM_EnableCapture(PWM0, PWM_CH_4_MASK);

#if NUCODEGEN_PWM0_CH4_CAP_ADVANCED

#if (NUCODEGEN_PWM0_CH4_CAP_INT_SEL == 1)

    /*Enable rising latch capture interrupt*/
    PWM_EnableCaptureInt(PWM0, 4, PWM_CAPTURE_INT_RISING_LATCH);

#elif (NUCODEGEN_PWM0_CH4_CAP_INT_SEL == 2)

    /*Enable falling latch capture interrupt*/
    PWM_EnableCaptureInt(PWM0, 4, PWM_CAPTURE_INT_FALLING_LATCH);

#elif (NUCODEGEN_PWM0_CH4_CAP_INT_SEL == 3)

    /*Enable rising and falling latch capture interrupt*/
    PWM_EnableCaptureInt(PWM0, 4, PWM_CAPTURE_INT_RISING_LATCH|PWM_CAPTURE_INT_FALLING_LATCH);

#endif /*NUCODEGEN_PWM0_CH4_CAP_INT_SEL*/

#endif /*NUCODEGEN_PWM0_CH4_CAP_ADVANCED*/

#endif /*NUCODEGEN_PWM0_CH4_CAP_ENABLE*/

#if NUCODEGEN_PWM0_CH5_CAP_ENABLE

    /* Set Reload Mode */
    PWM0->CAPCTL |= (NUCODEGEN_PWM0_CH5_CAP_RELOAD)<<PWM_CAPCTL_RCRLDEN5_Pos;

    /* Enable Capture Function for PWM0 channel 5 */
    PWM_EnableCapture(PWM0, PWM_CH_5_MASK);

#if NUCODEGEN_PWM0_CH5_CAP_ADVANCED

#if (NUCODEGEN_PWM0_CH5_CAP_INT_SEL == 1)

    /*Enable rising latch capture interrupt*/
    PWM_EnableCaptureInt(PWM0, 5, PWM_CAPTURE_INT_RISING_LATCH);

#elif (NUCODEGEN_PWM0_CH5_CAP_INT_SEL == 2)

    /*Enable falling latch capture interrupt*/
    PWM_EnableCaptureInt(PWM0, 5, PWM_CAPTURE_INT_FALLING_LATCH);

#elif (NUCODEGEN_PWM0_CH5_CAP_INT_SEL == 3)

    /*Enable rising and falling latch capture interrupt*/
    PWM_EnableCaptureInt(PWM0, 5, PWM_CAPTURE_INT_RISING_LATCH|PWM_CAPTURE_INT_FALLING_LATCH);

#endif /*NUCODEGEN_PWM0_CH5_CAP_INT_SEL*/

#endif /*NUCODEGEN_PWM0_CH5_CAP_ADVANCED*/

#endif /*NUCODEGEN_PWM0_CH5_CAP_ENABLE*/

#endif /*NUCODEGEN_PWM0_CH4_CAP_ENABLE, NUCODEGEN_PWM0_CH5_CAP_ENABLE*/

#endif /*NUCODEGEN_PWM0_CH4_5_FUNC_SEL*/

#endif /*NUCODEGEN_PWM0_CH4CH5*/

#if NUCODEGEN_PWM0_CH0_1_BRAKE_PIN_INV

    /* Enable PWM brake noise filter */
    PWM_EnableBrakePinInv(PWM0, NUCODEGEN_PWM0_CH0_1_BRAKE_SRC);

#elif NUCODEGEN_PWM0_CH2_3_BRAKE_PIN_INV

    /* Enable PWM brake noise filter */
    PWM_EnableBrakePinInv(PWM0, NUCODEGEN_PWM0_CH2_3_BRAKE_SRC);

#elif NUCODEGEN_PWM0_CH4_5_BRAKE_PIN_INV

    /* Enable PWM brake noise filter */
    PWM_EnableBrakePinInv(PWM0, NUCODEGEN_PWM0_CH4_5_BRAKE_SRC);

#endif /*NUCODEGEN_PWM1_CH0_1_BRAKE_PIN_INV*/

#if NUCODEGEN_PWM0_CH0_1_BRAKE_FILTER_ENABLE

    /* Enable PWM brake noise filter */
    PWM_EnableBrakeFilter(PWM0, NUCODEGEN_PWM0_CH0_1_BRAKE_SRC|NUCODEGEN_PWM0_CH2_3_BRAKE_SRC|NUCODEGEN_PWM0_CH4_5_BRAKE_SRC, NUCODEGEN_PWM0_CH0_1_BRAKE_FILTER_CNT, NUCODEGEN_PWM0_CH0_1_BRAKE_FILTER_CLK);

#elif NUCODEGEN_PWM0_CH2_3_BRAKE_FILTER_ENABLE

    /* Enable PWM brake noise filter */
    PWM_EnableBrakeFilter(PWM0, NUCODEGEN_PWM0_CH2_3_BRAKE_SRC|NUCODEGEN_PWM0_CH4_5_BRAKE_SRC, NUCODEGEN_PWM0_CH2_3_BRAKE_FILTER_CNT, NUCODEGEN_PWM0_CH2_3_BRAKE_FILTER_CLK);

#elif NUCODEGEN_PWM0_CH4_5_BRAKE_FILTER_ENABLE

    /* Enable PWM brake noise filter */
    PWM_EnableBrakeFilter(PWM0, NUCODEGEN_PWM0_CH4_5_BRAKE_SRC, NUCODEGEN_PWM0_CH4_5_BRAKE_FILTER_CNT, NUCODEGEN_PWM0_CH4_5_BRAKE_FILTER_CLK);

#endif /*NUCODEGEN_PWM0_CH0_1_BRAKE_FILTER_ENABLE*/

#if (((NUCODEGEN_PWM0_CH0_INT_SEL) & 0x1F) \
  || ((NUCODEGEN_PWM0_CH1_INT_SEL) & 0x1F) \
  || ((NUCODEGEN_PWM0_CH2_INT_SEL) & 0x1F) \
  || ((NUCODEGEN_PWM0_CH3_INT_SEL) & 0x1F) \
  || ((NUCODEGEN_PWM0_CH4_INT_SEL) & 0x1F) \
  || ((NUCODEGEN_PWM0_CH5_INT_SEL) & 0x1F) \
  || ((NUCODEGEN_PWM0_CH0_CAP_INT_SEL) & 0x03) \
  || ((NUCODEGEN_PWM0_CH1_CAP_INT_SEL) & 0x03) \
  || ((NUCODEGEN_PWM0_CH2_CAP_INT_SEL) & 0x03) \
  || ((NUCODEGEN_PWM0_CH3_CAP_INT_SEL) & 0x03) \
  || ((NUCODEGEN_PWM0_CH4_CAP_INT_SEL) & 0x03) \
  || ((NUCODEGEN_PWM0_CH5_CAP_INT_SEL) & 0x03))

    /* Enable interrupt function */
    NVIC_EnableIRQ(PWM0_IRQn);
    
#endif

}

#endif //NUCODEGEN_PWM0

#if (NUCODEGEN_PWM1)
void PWM1_Init()
{

#if NUCODEGEN_PWM1_CH0CH1

#if (NUCODEGEN_PWM1_CH0_1_FUNC_SEL==0)

#if (NUCODEGEN_PWM1_CH0_1_OUTPUT_FUNC_SETMODE==0)

#if NUCODEGEN_PWM1_CH0_ENABLE

    /* Set PWM1 channel 0 configuration */
    PWM_ConfigOutputChannel(PWM1, 0, NUCODEGEN_PWM1_CH0_1_FREQ, NUCODEGEN_PWM1_CH0_DUTY);

    /* Enable output of PWM1 channel 0 */
    PWM_EnableOutput(PWM1, PWM_CH_0_MASK);

#endif /*NUCODEGEN_PWM1_CH0_ENABLE*/

#if NUCODEGEN_PWM1_CH1_ENABLE

    /* Set PWM1 channel 1 configuration */
    PWM_ConfigOutputChannel(PWM1, 1, NUCODEGEN_PWM1_CH0_1_FREQ, NUCODEGEN_PWM1_CH1_DUTY);

    /* Enable output of PWM1 channel 1 */
    PWM_EnableOutput(PWM1, PWM_CH_1_MASK);

#endif /*NUCODEGEN_PWM1_CH1_ENABLE*/

#else

#if (NUCODEGEN_PWM1_CH0_ENABLE||NUCODEGEN_PWM1_CH1_ENABLE)

    /* Set PWM1 CH0_1 clock source */
    PWM_SetClockSource(PWM1, 0, NUCODEGEN_PWM1_CH0_1_CLKSRC);

    /* Set PWM1 CH0_1 counter behavior type */
    PWM_SET_ALIGNED_TYPE(PWM1, PWM_CH_0_MASK, NUCODEGEN_PWM1_CH0_1_CNTTYPE);

    /* Set the prescaler of PWM1 CH0_1*/
    PWM_SET_PRESCALER(PWM1, 0,NUCODEGEN_PWM1_CH0_1_PRESCALER);

    /* Set the period of PWM1 CH0_1*/
    PWM_SET_CNR(PWM1, 0, NUCODEGEN_PWM1_CH0_1_PERIOD);

#if NUCODEGEN_PWM1_CH0_1_SYNCSTART_ENABLE

    /* Enable timer synchronous start counting function */
    PWM_ENABLE_TIMER_SYNC(PWM1, BIT0, NUCODEGEN_PWM1_CH0_1_SYNCSTART_SRC);

#endif /*NUCODEGEN_PWM1_CH0_1_SYNCSTART_ENABLE*/

#if NUCODEGEN_PWM1_CH0_1_COMPLEMATARY_ENABLE

    /* Enable complementary mode */
    PWM1->CTL1 = PWM1->CTL1 | PWM_CTL1_OUTMODE0_Msk;

#if NUCODEGEN_PWM1_CH0_1_DEADTIME_ENABLE

    /* Enable Dead zone and set counter */
    PWM_EnableDeadZone(PWM1, 0, NUCODEGEN_PWM1_CH0_1_DEADTIME_CNT);

    /* Set Dead zone clock source */
    PWM_SET_DEADZONE_CLK_SRC(PWM1, 0, NUCODEGEN_PWM1_CH0_1_DEADTIME_CLKSRC);

#endif /*NUCODEGEN_PWM1_CH0_1_DEADTIME_ENABLE*/

#endif /*NUCODEGEN_PWM1_CH0_1_COMPLEMATARY_ENABLE*/

#if NUCODEGEN_PWM1_CH0_1_BRAKE_ENABLE

    /* Enable brake function and set the brake source */
    PWM_EnableBrake(PWM1, PWM_CH_0_MASK|PWM_CH_1_MASK, (NUCODEGEN_PWM1_CH1_BRAKE_ACTION<<(1*2))| (NUCODEGEN_PWM1_CH0_BRAKE_ACTION<<(0*2)), NUCODEGEN_PWM1_CH0_1_BRAKE_SRC, NUCODEGEN_PWM1_CH0_1_BRAKE_DETECT_TYPE);

#endif /*NUCODEGEN_PWM1_CH0_1_BRAKE_ENABLE*/

#if ((NUCODEGEN_PWM1_CH0_INT_SEL) & 1)

    /* Enable zero interrupt - PWM two channals has one controller  */
    PWM_EnableZeroInt(PWM1, 0);

#endif /*NUCODEGEN_PWM1_CH0_INT_SEL*/

#if ((NUCODEGEN_PWM1_CH0_INT_SEL) & 2)

    /* Enable period interrupt - PWM two channals has one controller  */
    PWM_EnablePeriodInt(PWM1, 0, 0);

#endif /*NUCODEGEN_PWM1_CH0_INT_SEL*/

#if (((NUCODEGEN_PWM1_CH0_INT_SEL) & 16) || ((NUCODEGEN_PWM1_CH1_INT_SEL) & 16))

    /* Enable fault brake interrupt */
    PWM1->INTEN1 |= (1 << NUCODEGEN_PWM1_CH0_1_BRAKE_DETECT_TYPE);

#endif /*NUCODEGEN_PWM1_CH0_INT_SEL*/

#if NUCODEGEN_PWM1_CH0_ENABLE

    /* Set the duty of PWM1 CH0*/
    PWM_SET_CMR(PWM1, 0, NUCODEGEN_PWM1_CH0_CMPDATA);

    /* Set output level of PWM1 CH0*/
    PWM_SET_OUTPUT_LEVEL(PWM1, PWM_CH_0_MASK, NUCODEGEN_PWM1_CH0_WAVEOUT_ZERO, NUCODEGEN_PWM1_CH0_WAVEOUT_CMPUP, NUCODEGEN_PWM1_CH0_WAVEOUT_PERIOD, NUCODEGEN_PWM1_CH0_WAVEOUT_CMPDOWN);

    /* Enable output of PWM1 channel 0 */
    PWM_EnableOutput(PWM1, PWM_CH_0_MASK);

#if NUCODEGEN_PWM1_CH0_ADVANCED

#if (NUCODEGEN_PWM1_CH0_LOAD_MODE == 0)

    /* Period loading mode*/
    PWM_DisableLoadMode(PWM1, 0, PWM_LOAD_MODE_IMMEDIATE|PWM_LOAD_MODE_CENTER);

#elif (NUCODEGEN_PWM1_CH0_LOAD_MODE == 1)

    /*Immediate loading mode*/
    PWM_EnableLoadMode(PWM1, 0, PWM_LOAD_MODE_IMMEDIATE);

#elif (NUCODEGEN_PWM1_CH0_LOAD_MODE == 2)

    /*Center loading mode*/
    PWM_EnableLoadMode(PWM1, 0, PWM_LOAD_MODE_CENTER);

#endif /*NUCODEGEN_PWM1_CH0_LOAD_MODE*/

#if (NUCODEGEN_PWM1_CH0_OTHER_OUTPUT==1)

    /* Enable mask output and output high or low*/
    PWM_SetMaskOutput(PWM1, 0, NUCODEGEN_PWM1_CH0_MASK_DATA);

#elif (NUCODEGEN_PWM1_CH0_OTHER_OUTPUT==2)

    /* Enable inverter output */
    PWM1->POLCTL |= PWM_CH_0_MASK;

#endif /*NUCODEGEN_PWM1_CH0_OTHER_OUTPUT*/

#if NUCODEGEN_PWM1_CH0_TRIGER_ADC_ENABLE

    /* Set trigger ADC and trigger source*/
    PWM_EnableADCTrigger(PWM1, 0, NUCODEGEN_PWM1_CH0_TRIGER_ADCSRC);

#endif /*NUCODEGEN_PWM1_CH0_TRIGER_ADC_ENABLE*/

#if ((NUCODEGEN_PWM1_CH0_INT_SEL) & 4)

    /* Enable duty interrupt - count up interrupt */
    PWM_EnableDutyInt(PWM1, 0, PWM_DUTY_INT_UP_COUNT_MATCH_CMP);

#endif /*NUCODEGEN_PWM1_CH0_INT_SEL*/

#if ((NUCODEGEN_PWM1_CH0_INT_SEL) & 8)

    /* Enable duty interrupt - count down interrupt */
    PWM_EnableDutyInt(PWM1, 0, PWM_DUTY_INT_DOWN_COUNT_MATCH_CMP);

#endif /*NUCODEGEN_PWM1_CH0_INT_SEL*/

#endif /*NUCODEGEN_PWM1_CH0_ADVANCED*/

#endif /*NUCODEGEN_PWM1_CH0_ENABLE*/

#if NUCODEGEN_PWM1_CH1_ENABLE

    /* Set the duty of PWM1 CH1*/
    PWM_SET_CMR(PWM1, 1, NUCODEGEN_PWM1_CH1_CMPDATA);

    /* Set output level of PWM1 CH1*/
    PWM_SET_OUTPUT_LEVEL(PWM1, PWM_CH_1_MASK, NUCODEGEN_PWM1_CH1_WAVEOUT_ZERO, NUCODEGEN_PWM1_CH1_WAVEOUT_CMPUP, NUCODEGEN_PWM1_CH1_WAVEOUT_PERIOD, NUCODEGEN_PWM1_CH1_WAVEOUT_CMPDOWN);

    /* Enable output of PWM1 channel 1 */
    PWM_EnableOutput(PWM1, PWM_CH_1_MASK);

#if NUCODEGEN_PWM1_CH1_ADVANCED

#if (NUCODEGEN_PWM1_CH1_LOAD_MODE == 0)

    /* Period loading mode*/
    PWM_DisableLoadMode(PWM1, 1, PWM_LOAD_MODE_IMMEDIATE|PWM_LOAD_MODE_CENTER);

#elif (NUCODEGEN_PWM1_CH1_LOAD_MODE == 1)

    /*Immediate loading mode*/
    PWM_EnableLoadMode(PWM1, 1, PWM_LOAD_MODE_IMMEDIATE);

#elif (NUCODEGEN_PWM1_CH1_LOAD_MODE == 2)

    /*Center loading mode*/
    PWM_EnableLoadMode(PWM1, 1, PWM_LOAD_MODE_CENTER);

#endif /*NUCODEGEN_PWM1_CH1_LOAD_MODE*/

#if (NUCODEGEN_PWM1_CH1_OTHER_OUTPUT==1)

    /* Enable mask output and output high or low*/
    PWM_SetMaskOutput(PWM1, 1, NUCODEGEN_PWM1_CH1_MASK_DATA);

#elif (NUCODEGEN_PWM1_CH1_OTHER_OUTPUT==2)

    /* Enable inverter output */
    PWM1->POLCTL |= PWM_CH_1_MASK;

#endif /*NUCODEGEN_PWM1_CH1_OTHER_OUTPUT*/

#if NUCODEGEN_PWM1_CH1_TRIGER_ADC_ENABLE

    /* Set trigger ADC and trigger source*/
    PWM_EnableADCTrigger(PWM1, 1, NUCODEGEN_PWM1_CH1_TRIGER_ADCSRC);

#endif /*NUCODEGEN_PWM1_CH1_TRIGER_ADC_ENABLE*/

#if ((NUCODEGEN_PWM1_CH1_INT_SEL) & 4)

    /* Enable duty interrupt - count up interrupt */
    PWM_EnableDutyInt(PWM1, 1, PWM_DUTY_INT_UP_COUNT_MATCH_CMP);

#endif /*NUCODEGEN_PWM1_CH1_INT_SEL*/

#if ((NUCODEGEN_PWM1_CH1_INT_SEL) & 8)

    /* Enable duty interrupt - count down interrupt */
    PWM_EnableDutyInt(PWM1, 1, PWM_DUTY_INT_DOWN_COUNT_MATCH_CMP);

#endif /*NUCODEGEN_PWM1_CH1_INT_SEL*/

#endif /*NUCODEGEN_PWM1_CH1_ADVANCED*/

#endif /*NUCODEGEN_PWM1_CH1_ENABLE*/

#endif

#endif /*NUCODEGEN_PWM1_CH0_1_OUTPUT_FUNC_SETMODE*/

#else

#if (NUCODEGEN_PWM1_CH0_CAP_ENABLE || NUCODEGEN_PWM1_CH1_CAP_ENABLE)

    /* Configure PWM capture and get the nearest unit time */
    PWM_ConfigCaptureChannel(PWM1, 0, NUCODEGEN_PWM1_CH0_1_CAP_UNITTIME, 0);

#if NUCODEGEN_PWM1_CH0_CAP_ENABLE

    /* Set Reload Mode */
    PWM1->CAPCTL |= (NUCODEGEN_PWM1_CH0_CAP_RELOAD)<<PWM_CAPCTL_RCRLDEN0_Pos;

    /* Enable Capture Function for PWM1 channel 0 */
    PWM_EnableCapture(PWM1, PWM_CH_0_MASK);

#if NUCODEGEN_PWM1_CH0_CAP_ADVANCED

#if (NUCODEGEN_PWM1_CH0_CAP_INT_SEL == 1)

    /*Enable rising latch capture interrupt*/
    PWM_EnableCaptureInt(PWM1, 0, PWM_CAPTURE_INT_RISING_LATCH);

#elif (NUCODEGEN_PWM1_CH0_CAP_INT_SEL == 2)

    /*Enable falling latch capture interrupt*/
    PWM_EnableCaptureInt(PWM1, 0, PWM_CAPTURE_INT_FALLING_LATCH);

#elif (NUCODEGEN_PWM1_CH0_CAP_INT_SEL == 3)

    /*Enable rising and falling latch capture interrupt*/
    PWM_EnableCaptureInt(PWM1, 0, PWM_CAPTURE_INT_RISING_LATCH|PWM_CAPTURE_INT_FALLING_LATCH);

#endif /*NUCODEGEN_PWM1_CH0_CAP_INT_SEL*/

#endif /*NUCODEGEN_PWM1_CH0_CAP_ADVANCED*/

#endif /*NUCODEGEN_PWM1_CH0_CAP_ENABLE*/

#if NUCODEGEN_PWM1_CH1_CAP_ENABLE

    /* Set Reload Mode */
    PWM1->CAPCTL |= (NUCODEGEN_PWM1_CH1_CAP_RELOAD)<<PWM_CAPCTL_RCRLDEN1_Pos;

    /* Enable Capture Function for PWM1 channel 1 */
    PWM_EnableCapture(PWM1, PWM_CH_1_MASK);

#if NUCODEGEN_PWM1_CH1_CAP_ADVANCED

#if (NUCODEGEN_PWM1_CH1_CAP_INT_SEL == 1)

    /*Enable rising latch capture interrupt*/
    PWM_EnableCaptureInt(PWM1, 1, PWM_CAPTURE_INT_RISING_LATCH);

#elif (NUCODEGEN_PWM1_CH1_CAP_INT_SEL == 2)

    /*Enable falling latch capture interrupt*/
    PWM_EnableCaptureInt(PWM1, 1, PWM_CAPTURE_INT_FALLING_LATCH);

#elif (NUCODEGEN_PWM1_CH1_CAP_INT_SEL == 3)

    /*Enable rising and falling latch capture interrupt*/
    PWM_EnableCaptureInt(PWM1, 1, PWM_CAPTURE_INT_RISING_LATCH|PWM_CAPTURE_INT_FALLING_LATCH);

#endif /*NUCODEGEN_PWM1_CH1_CAP_INT_SEL*/

#endif /*NUCODEGEN_PWM1_CH1_CAP_ADVANCED*/

#endif /*NUCODEGEN_PWM1_CH1_CAP_ENABLE*/

#endif /*NUCODEGEN_PWM1_CH0_CAP_ENABLE, NUCODEGEN_PWM1_CH1_CAP_ENABLE*/

#endif /*NUCODEGEN_PWM1_FUNC_SEL*/

#endif /*NUCODEGEN_PWM1_CH0CH1*/

#if NUCODEGEN_PWM1_CH2CH3

#if (NUCODEGEN_PWM1_CH2_3_FUNC_SEL==0)

#if (NUCODEGEN_PWM1_CH2_3_OUTPUT_FUNC_SETMODE==0)

#if NUCODEGEN_PWM1_CH2_ENABLE

    /* Set PWM1 channel 2 configuration */
    PWM_ConfigOutputChannel(PWM1, 2, NUCODEGEN_PWM1_CH2_3_FREQ, NUCODEGEN_PWM1_CH2_DUTY);

    /* Enable output of PWM1 channel 2 */
    PWM_EnableOutput(PWM1, PWM_CH_2_MASK);

#endif /*NUCODEGEN_PWM1_CH2_ENABLE*/

#if NUCODEGEN_PWM1_CH3_ENABLE

    /* Set PWM1 channel 3 configuration */
    PWM_ConfigOutputChannel(PWM1, 3, NUCODEGEN_PWM1_CH2_3_FREQ, NUCODEGEN_PWM1_CH3_DUTY);

    /* Enable output of PWM1 channel 3 */
    PWM_EnableOutput(PWM1, PWM_CH_3_MASK);

#endif /*NUCODEGEN_PWM1_CH3_ENABLE*/

#else

#if (NUCODEGEN_PWM1_CH2_ENABLE||NUCODEGEN_PWM1_CH3_ENABLE)

    /* Set PWM1 CH2_3 clock source */
    PWM_SetClockSource(PWM1, 2, NUCODEGEN_PWM1_CH2_3_CLKSRC);

    /* Set PWM1 CH2_3 counter behavior type */
    PWM_SET_ALIGNED_TYPE(PWM1, PWM_CH_2_MASK, NUCODEGEN_PWM1_CH2_3_CNTTYPE);

    /* Set the prescaler of PWM1 CH2_3*/
    PWM_SET_PRESCALER(PWM1, 2, NUCODEGEN_PWM1_CH2_3_PRESCALER);

    /* Set the period of PWM1 CH2_3*/
    PWM_SET_CNR(PWM1, 2, NUCODEGEN_PWM1_CH2_3_PERIOD);

#if NUCODEGEN_PWM1_CH2_3_SYNCSTART_ENABLE

    /* Enable timer synchronous start counting function */
    PWM_ENABLE_TIMER_SYNC(PWM1, BIT2, NUCODEGEN_PWM1_CH2_3_SYNCSTART_SRC);

#endif /*NUCODEGEN_PWM1_CH2_3_SYNCSTART_ENABLE*/

#if NUCODEGEN_PWM1_CH2_3_COMPLEMATARY_ENABLE

    /* Enable complementary mode */
    PWM1->CTL1 = PWM1->CTL1 | PWM_CTL1_OUTMODE2_Msk;

#if NUCODEGEN_PWM1_CH2_3_DEADTIME_ENABLE

    /* Enable Dead zone and set counter */
    PWM_EnableDeadZone(PWM1, 2, NUCODEGEN_PWM1_CH2_3_DEADTIME_CNT);

    /* Set Dead zone clock source */
    PWM_SET_DEADZONE_CLK_SRC(PWM1, 2, NUCODEGEN_PWM1_CH2_3_DEADTIME_CLKSRC);

#endif /*NUCODEGEN_PWM1_CH2_3_DEADTIME_ENABLE*/

#endif /*NUCODEGEN_PWM1_CH2_3_COMPLEMATARY_ENABLE*/

#if NUCODEGEN_PWM1_CH2_3_BRAKE_ENABLE

    /* Enable brake function and set the brake source */
    PWM_EnableBrake(PWM1, PWM_CH_2_MASK|PWM_CH_3_MASK, (NUCODEGEN_PWM1_CH2_BRAKE_ACTION<<(2*2))| (NUCODEGEN_PWM1_CH3_BRAKE_ACTION<<(3*2)), NUCODEGEN_PWM1_CH2_3_BRAKE_SRC, NUCODEGEN_PWM1_CH2_3_BRAKE_DETECT_TYPE);

#endif /*NUCODEGEN_PWM1_CH2_3_BRAKE_ENABLE*/

#if ((NUCODEGEN_PWM1_CH2_INT_SEL) & 1)

    /* Enable zero interrupt - PWM two channals has one controller  */
    PWM_EnableZeroInt(PWM1, 2);

#endif /*NUCODEGEN_PWM1_CH2_INT_SEL*/

#if ((NUCODEGEN_PWM1_CH2_INT_SEL) & 2)

    /* Enable period interrupt - PWM two channals has one controller  */
    PWM_EnablePeriodInt(PWM1, 2, 0);

#endif /*NUCODEGEN_PWM1_CH2_INT_SEL*/

#if (((NUCODEGEN_PWM1_CH2_INT_SEL) & 16) || ((NUCODEGEN_PWM1_CH3_INT_SEL) & 16))

    /* Enable fault brake interrupt */
    PWM1->INTEN1 |= (0x2 << NUCODEGEN_PWM1_CH2_3_BRAKE_DETECT_TYPE);

#endif /*NUCODEGEN_PWM1_CH2_INT_SEL*/

#if NUCODEGEN_PWM1_CH2_ENABLE

    /* Set the duty of PWM1 CH2*/
    PWM_SET_CMR(PWM1, 2, NUCODEGEN_PWM1_CH2_CMPDATA);

    /* Set output level of PWM1 CH2*/
    PWM_SET_OUTPUT_LEVEL(PWM1, PWM_CH_2_MASK, NUCODEGEN_PWM1_CH2_WAVEOUT_ZERO, NUCODEGEN_PWM1_CH2_WAVEOUT_CMPUP, NUCODEGEN_PWM1_CH2_WAVEOUT_PERIOD, NUCODEGEN_PWM1_CH2_WAVEOUT_CMPDOWN);

    /* Enable output of PWM1 channel 2 */
    PWM_EnableOutput(PWM1, PWM_CH_2_MASK);

#if NUCODEGEN_PWM1_CH2_ADVANCED

#if (NUCODEGEN_PWM1_CH2_LOAD_MODE == 0)

    /* Period loading mode*/
    PWM_DisableLoadMode(PWM1, 2, PWM_LOAD_MODE_IMMEDIATE|PWM_LOAD_MODE_CENTER);

#elif (NUCODEGEN_PWM1_CH2_LOAD_MODE == 1)

    /*Immediate loading mode*/
    PWM_EnableLoadMode(PWM1, 2, PWM_LOAD_MODE_IMMEDIATE);

#elif (NUCODEGEN_PWM1_CH2_LOAD_MODE == 2)

    /*Center loading mode*/
    PWM_EnableLoadMode(PWM1, 2, PWM_LOAD_MODE_CENTER);

#endif /*NUCODEGEN_PWM1_CH2_LOAD_MODE*/

#if (NUCODEGEN_PWM1_CH2_OTHER_OUTPUT==1)

    /* Enable mask output and output high or low*/
    PWM_SetMaskOutput(PWM1, 2, NUCODEGEN_PWM1_CH2_MASK_DATA);

#elif (NUCODEGEN_PWM1_CH2_OTHER_OUTPUT==2)

    /* Enable inverter output */
    PWM1->POLCTL |= PWM_CH_2_MASK;

#endif /*NUCODEGEN_PWM1_CH2_OTHER_OUTPUT*/

#if NUCODEGEN_PWM1_CH2_TRIGER_ADC_ENABLE

    /* Set trigger ADC and trigger source*/
    PWM_EnableADCTrigger(PWM1, 2, NUCODEGEN_PWM1_CH2_TRIGER_ADCSRC);

#endif /*NUCODEGEN_PWM1_CH2_TRIGER_ADC_ENABLE*/

#if ((NUCODEGEN_PWM1_CH2_INT_SEL) & 4)

    /* Enable duty interrupt - count up interrupt */
    PWM_EnableDutyInt(PWM1, 2, PWM_DUTY_INT_UP_COUNT_MATCH_CMP);

#endif /*NUCODEGEN_PWM1_CH2_INT_SEL*/

#if ((NUCODEGEN_PWM1_CH2_INT_SEL) & 8)

    /* Enable duty interrupt - count down interrupt */
    PWM_EnableDutyInt(PWM1, 2, PWM_DUTY_INT_DOWN_COUNT_MATCH_CMP);

#endif /*NUCODEGEN_PWM1_CH2_INT_SEL*/

#endif /*NUCODEGEN_PWM1_CH2_ADVANCED*/

#endif /*NUCODEGEN_PWM1_CH2_ENABLE*/

#if NUCODEGEN_PWM1_CH3_ENABLE

    /* Set the duty of PWM1 CH3*/
    PWM_SET_CMR(PWM1, 3, NUCODEGEN_PWM1_CH3_CMPDATA);

    /* Set output level of PWM1 CH3*/
    PWM_SET_OUTPUT_LEVEL(PWM1, PWM_CH_3_MASK, NUCODEGEN_PWM1_CH3_WAVEOUT_ZERO, NUCODEGEN_PWM1_CH3_WAVEOUT_CMPUP, NUCODEGEN_PWM1_CH3_WAVEOUT_PERIOD, NUCODEGEN_PWM1_CH3_WAVEOUT_CMPDOWN);

    /* Enable output of PWM1 channel 3 */
    PWM_EnableOutput(PWM1, PWM_CH_3_MASK);

#if NUCODEGEN_PWM1_CH3_ADVANCED

#if (NUCODEGEN_PWM1_CH3_LOAD_MODE == 0)

    /* Period loading mode*/
    PWM_DisableLoadMode(PWM1, 3, PWM_LOAD_MODE_IMMEDIATE|PWM_LOAD_MODE_CENTER);

#elif (NUCODEGEN_PWM1_CH3_LOAD_MODE == 1)

    /*Immediate loading mode*/
    PWM_EnableLoadMode(PWM1, 3, PWM_LOAD_MODE_IMMEDIATE);

#elif (NUCODEGEN_PWM1_CH3_LOAD_MODE == 2)

    /*Center loading mode*/
    PWM_EnableLoadMode(PWM1, 3, PWM_LOAD_MODE_CENTER);

#endif /*NUCODEGEN_PWM1_CH3_LOAD_MODE*/

#if (NUCODEGEN_PWM1_CH3_OTHER_OUTPUT==1)

    /* Enable mask output and output high or low*/
    PWM_SetMaskOutput(PWM1, 3, NUCODEGEN_PWM1_CH3_MASK_DATA);

#elif (NUCODEGEN_PWM1_CH3_OTHER_OUTPUT==2)

    /* Enable inverter output */
    PWM1->POLCTL |= PWM_CH_3_MASK;

#endif /*NUCODEGEN_PWM1_CH3_OTHER_OUTPUT*/

#if NUCODEGEN_PWM1_CH3_TRIGER_ADC_ENABLE

    /* Set trigger ADC and trigger source*/
    PWM_EnableADCTrigger(PWM1, 3, NUCODEGEN_PWM1_CH3_TRIGER_ADCSRC);

#endif /*NUCODEGEN_PWM1_CH3_TRIGER_ADC_ENABLE*/

#if ((NUCODEGEN_PWM1_CH3_INT_SEL) & 4)

    /* Enable duty interrupt - count up interrupt */
    PWM_EnableDutyInt(PWM1, 3, PWM_DUTY_INT_UP_COUNT_MATCH_CMP);

#endif /*NUCODEGEN_PWM1_CH3_INT_SEL*/

#if ((NUCODEGEN_PWM1_CH3_INT_SEL) & 8)

    /* Enable duty interrupt - count down interrupt */
    PWM_EnableDutyInt(PWM1, 3, PWM_DUTY_INT_DOWN_COUNT_MATCH_CMP);

#endif /*NUCODEGEN_PWM1_CH3_INT_SEL*/

#endif /*NUCODEGEN_PWM1_CH3_ADVANCED*/

#endif /*NUCODEGEN_PWM1_CH3_ENABLE*/

#endif

#endif /*NUCODEGEN_PWM1_CH2_3_OUTPUT_FUNC_SETMODE*/

#else

#if (NUCODEGEN_PWM1_CH2_CAP_ENABLE || NUCODEGEN_PWM1_CH3_CAP_ENABLE)

    /* Configure PWM capture and get the nearest unit time */
    PWM_ConfigCaptureChannel(PWM1, 2, NUCODEGEN_PWM1_CH2_3_CAP_UNITTIME, 0);

#if NUCODEGEN_PWM1_CH2_CAP_ENABLE

    /* Set Reload Mode */
    PWM1->CAPCTL |= (NUCODEGEN_PWM1_CH2_CAP_RELOAD)<<PWM_CAPCTL_RCRLDEN2_Pos;

    /* Enable Capture Function for PWM1 channel 2 */
    PWM_EnableCapture(PWM1, PWM_CH_2_MASK);

#if NUCODEGEN_PWM1_CH2_CAP_ADVANCED

#if (NUCODEGEN_PWM1_CH2_CAP_INT_SEL == 1)

    /*Enable rising latch capture interrupt*/
    PWM_EnableCaptureInt(PWM1, 2, PWM_CAPTURE_INT_RISING_LATCH);

#elif (NUCODEGEN_PWM1_CH2_CAP_INT_SEL == 2)

    /*Enable falling latch capture interrupt*/
    PWM_EnableCaptureInt(PWM1, 2, PWM_CAPTURE_INT_FALLING_LATCH);

#elif (NUCODEGEN_PWM1_CH2_CAP_INT_SEL == 3)

    /*Enable rising and falling latch capture interrupt*/
    PWM_EnableCaptureInt(PWM1, 2, PWM_CAPTURE_INT_RISING_LATCH|PWM_CAPTURE_INT_FALLING_LATCH);

#endif /*NUCODEGEN_PWM1_CH2_CAP_INT_SEL*/

#endif /*NUCODEGEN_PWM1_CH2_CAP_ADVANCED*/

#endif /*NUCODEGEN_PWM1_CH2_CAP_ENABLE*/

#if NUCODEGEN_PWM1_CH3_CAP_ENABLE

    /* Set Reload Mode */
    PWM1->CAPCTL |= (NUCODEGEN_PWM1_CH3_CAP_RELOAD)<<PWM_CAPCTL_RCRLDEN3_Pos;

    /* Enable Capture Function for PWM1 channel 3 */
    PWM_EnableCapture(PWM1, PWM_CH_3_MASK);

#if NUCODEGEN_PWM1_CH3_CAP_ADVANCED

#if (NUCODEGEN_PWM1_CH3_CAP_INT_SEL == 1)

    /*Enable rising latch capture interrupt*/
    PWM_EnableCaptureInt(PWM1, 3, PWM_CAPTURE_INT_RISING_LATCH);

#elif (NUCODEGEN_PWM1_CH3_CAP_INT_SEL == 2)

    /*Enable falling latch capture interrupt*/
    PWM_EnableCaptureInt(PWM1, 3, PWM_CAPTURE_INT_FALLING_LATCH);

#elif (NUCODEGEN_PWM1_CH3_CAP_INT_SEL == 3)

    /*Enable rising and falling latch capture interrupt*/
    PWM_EnableCaptureInt(PWM1, 3, PWM_CAPTURE_INT_RISING_LATCH|PWM_CAPTURE_INT_FALLING_LATCH);

#endif /*NUCODEGEN_PWM1_CH3_CAP_INT_SEL*/

#endif /*NUCODEGEN_PWM1_CH3_CAP_ADVANCED*/

#endif /*NUCODEGEN_PWM1_CH3_CAP_ENABLE*/

#endif /*NUCODEGEN_PWM1_CH2_CAP_ENABLE, NUCODEGEN_PWM1_CH3_CAP_ENABLE*/

#endif /*NUCODEGEN_PWM1_CH2_3_FUNC_SEL*/


#endif /*NUCODEGEN_PWM1_CH2CH3*/

#if NUCODEGEN_PWM1_CH4CH5

#if (NUCODEGEN_PWM1_CH4_5_FUNC_SEL==0)

#if (NUCODEGEN_PWM1_CH4_5_OUTPUT_FUNC_SETMODE==0)

#if NUCODEGEN_PWM1_CH4_ENABLE

    /* Set PWM1 channel 4 configuration */
    PWM_ConfigOutputChannel(PWM1, 4, NUCODEGEN_PWM1_CH4_5_FREQ, NUCODEGEN_PWM1_CH4_DUTY);

    /* Enable output of PWM1 channel 4 */
    PWM_EnableOutput(PWM1, PWM_CH_4_MASK);

#endif /*NUCODEGEN_PWM1_CH4_ENABLE*/

#if NUCODEGEN_PWM1_CH5_ENABLE

    /* Set PWM1 channel 5 configuration */
    PWM_ConfigOutputChannel(PWM1, 5, NUCODEGEN_PWM1_CH4_5_FREQ, NUCODEGEN_PWM1_CH5_DUTY);

    /* Enable output of PWM1 channel 5 */
    PWM_EnableOutput(PWM1, PWM_CH_5_MASK);

#endif /*NUCODEGEN_PWM1_CH5_ENABLE*/

#else

#if (NUCODEGEN_PWM1_CH4_ENABLE||NUCODEGEN_PWM1_CH5_ENABLE)

    /* Set PWM1 CH4_5 clock source */
    PWM_SetClockSource(PWM1, 4, NUCODEGEN_PWM1_CH4_5_CLKSRC);

    /* Set PWM1 CH4_5 counter behavior type */
    PWM_SET_ALIGNED_TYPE(PWM1, PWM_CH_4_MASK, NUCODEGEN_PWM1_CH4_5_CNTTYPE);

    /* Set the prescaler of PWM1 CH4_5*/
    PWM_SET_PRESCALER(PWM1, 4, NUCODEGEN_PWM1_CH4_5_PRESCALER);

    /* Set the period of PWM1 CH4_5*/
    PWM_SET_CNR(PWM1, 4, NUCODEGEN_PWM1_CH4_5_PERIOD);

#if NUCODEGEN_PWM1_CH4_5_SYNCSTART_ENABLE

    /* Enable timer synchronous start counting function */
    PWM_ENABLE_TIMER_SYNC(PWM1, BIT4, NUCODEGEN_PWM1_CH4_5_SYNCSTART_SRC);

#endif /*NUCODEGEN_PWM1_CH4_5_SYNCSTART_ENABLE*/

#if NUCODEGEN_PWM1_CH4_5_COMPLEMATARY_ENABLE

    /* Enable complementary mode */
    PWM1->CTL1 = PWM1->CTL1 | PWM_CTL1_OUTMODE4_Msk;

#if NUCODEGEN_PWM1_CH4_5_DEADTIME_ENABLE

    /* Enable Dead zone and set counter */
    PWM_EnableDeadZone(PWM1, 4, NUCODEGEN_PWM1_CH4_5_DEADTIME_CNT);

    /* Set Dead zone clock source */
    PWM_SET_DEADZONE_CLK_SRC(PWM1, 4, NUCODEGEN_PWM1_CH4_5_DEADTIME_CLKSRC);

#endif /*NUCODEGEN_PWM1_CH4_5_DEADTIME_ENABLE*/

#endif /*NUCODEGEN_PWM1_CH4_5_COMPLEMATARY_ENABLE*/

#if NUCODEGEN_PWM1_CH4_5_BRAKE_ENABLE

    /* Enable brake function and set the brake source */
    PWM_EnableBrake(PWM1, PWM_CH_4_MASK|PWM_CH_5_MASK, (NUCODEGEN_PWM1_CH4_BRAKE_ACTION<<(4*2))| (NUCODEGEN_PWM1_CH5_BRAKE_ACTION<<(5*2)), NUCODEGEN_PWM1_CH4_5_BRAKE_SRC, NUCODEGEN_PWM1_CH4_5_BRAKE_DETECT_TYPE);

#endif /*NUCODEGEN_PWM1_CH4_5_BRAKE_ENABLE*/

#if ((NUCODEGEN_PWM1_CH4_INT_SEL) & 1)

    /* Enable zero interrupt - PWM two channals has one controller  */
    PWM_EnableZeroInt(PWM1, 4);

#endif /*NUCODEGEN_PWM1_CH4_INT_SEL*/

#if ((NUCODEGEN_PWM1_CH4_INT_SEL) & 2)

    /* Enable period interrupt - PWM two channals has one controller  */
    PWM_EnablePeriodInt(PWM1, 4, 0);

#endif /*NUCODEGEN_PWM1_CH4_INT_SEL*/

#if (((NUCODEGEN_PWM1_CH4_INT_SEL) & 16) || ((NUCODEGEN_PWM1_CH5_INT_SEL) & 16))

    /* Enable fault brake interrupt */
    PWM1->INTEN1 |= (0x4 << NUCODEGEN_PWM1_CH4_5_BRAKE_DETECT_TYPE);

#endif /*NUCODEGEN_PWM1_CH4_INT_SEL*/

#if NUCODEGEN_PWM1_CH4_ENABLE

    /* Set the duty of PWM1 CH4*/
    PWM_SET_CMR(PWM1, 4, NUCODEGEN_PWM1_CH4_CMPDATA);

    /* Set output level of PWM1 CH4*/
    PWM_SET_OUTPUT_LEVEL(PWM1, PWM_CH_4_MASK, NUCODEGEN_PWM1_CH4_WAVEOUT_ZERO, NUCODEGEN_PWM1_CH4_WAVEOUT_CMPUP, NUCODEGEN_PWM1_CH4_WAVEOUT_PERIOD, NUCODEGEN_PWM1_CH4_WAVEOUT_CMPDOWN);

    /* Enable output of PWM1 channel 4 */
    PWM_EnableOutput(PWM1, PWM_CH_4_MASK);

#if NUCODEGEN_PWM1_CH4_ADVANCED

#if (NUCODEGEN_PWM1_CH4_LOAD_MODE == 0)

    /* Period loading mode*/
    PWM_DisableLoadMode(PWM1, 4, PWM_LOAD_MODE_IMMEDIATE|PWM_LOAD_MODE_CENTER);

#elif (NUCODEGEN_PWM1_CH4_LOAD_MODE == 1)

    /*Immediate loading mode*/
    PWM_EnableLoadMode(PWM1, 4, PWM_LOAD_MODE_IMMEDIATE);

#elif (NUCODEGEN_PWM1_CH4_LOAD_MODE == 2)

    /*Center loading mode*/
    PWM_EnableLoadMode(PWM1, 4, PWM_LOAD_MODE_CENTER);

#endif /*NUCODEGEN_PWM1_CH4_LOAD_MODE*/

#if (NUCODEGEN_PWM1_CH4_OTHER_OUTPUT==1)

    /* Enable mask output and output high or low*/
    PWM_SetMaskOutput(PWM1, 4, NUCODEGEN_PWM1_CH4_MASK_DATA);

#elif (NUCODEGEN_PWM1_CH4_OTHER_OUTPUT==2)

    /* Enable inverter output */
    PWM1->POLCTL |= PWM_CH_4_MASK;

#endif /*NUCODEGEN_PWM1_CH4_OTHER_OUTPUT*/

#if NUCODEGEN_PWM1_CH4_TRIGER_ADC_ENABLE

    /* Set trigger ADC and trigger source*/
    PWM_EnableADCTrigger(PWM1, 4, NUCODEGEN_PWM1_CH4_TRIGER_ADCSRC);

#endif /*NUCODEGEN_PWM1_CH4_TRIGER_ADC_ENABLE*/

#if ((NUCODEGEN_PWM1_CH4_INT_SEL) & 4)

    /* Enable duty interrupt - count up interrupt */
    PWM_EnableDutyInt(PWM1, 4, PWM_DUTY_INT_UP_COUNT_MATCH_CMP);

#endif /*NUCODEGEN_PWM1_CH4_INT_SEL*/

#if ((NUCODEGEN_PWM1_CH4_INT_SEL) & 8)

    /* Enable duty interrupt - count down interrupt */
    PWM_EnableDutyInt(PWM1, 4, PWM_DUTY_INT_DOWN_COUNT_MATCH_CMP);

#endif /*NUCODEGEN_PWM1_CH4_INT_SEL*/

#endif /*NUCODEGEN_PWM1_CH4_ADVANCED*/

#endif /*NUCODEGEN_PWM1_CH4_ENABLE*/

#if NUCODEGEN_PWM1_CH5_ENABLE

    /* Set the duty of PWM1 CH5*/
    PWM_SET_CMR(PWM1, 5, NUCODEGEN_PWM1_CH5_CMPDATA);

    /* Set output level of PWM1 CH5*/
    PWM_SET_OUTPUT_LEVEL(PWM1, PWM_CH_5_MASK, NUCODEGEN_PWM1_CH5_WAVEOUT_ZERO, NUCODEGEN_PWM1_CH5_WAVEOUT_CMPUP, NUCODEGEN_PWM1_CH5_WAVEOUT_PERIOD, NUCODEGEN_PWM1_CH5_WAVEOUT_CMPDOWN);

    /* Enable output of PWM1 channel 5 */
    PWM_EnableOutput(PWM1, PWM_CH_5_MASK);

#if NUCODEGEN_PWM1_CH5_ADVANCED

#if (NUCODEGEN_PWM1_CH5_LOAD_MODE == 0)

    /* Period loading mode*/
    PWM_DisableLoadMode(PWM1, 5, PWM_LOAD_MODE_IMMEDIATE|PWM_LOAD_MODE_CENTER);

#elif (NUCODEGEN_PWM1_CH5_LOAD_MODE == 1)

    /*Immediate loading mode*/
    PWM_EnableLoadMode(PWM1, 5, PWM_LOAD_MODE_IMMEDIATE);

#elif (NUCODEGEN_PWM1_CH5_LOAD_MODE == 2)

    /*Center loading mode*/
    PWM_EnableLoadMode(PWM1, 5, PWM_LOAD_MODE_CENTER);

#endif /*NUCODEGEN_PWM1_CH5_LOAD_MODE*/

#if (NUCODEGEN_PWM1_CH5_OTHER_OUTPUT==1)

    /* Enable mask output and output high or low*/
    PWM_SetMaskOutput(PWM1, 5, NUCODEGEN_PWM1_CH5_MASK_DATA);

#elif (NUCODEGEN_PWM1_CH5_OTHER_OUTPUT==2)

    /* Enable inverter output */
    PWM1->POLCTL |= PWM_CH_5_MASK;

#endif /*NUCODEGEN_PWM1_CH5_OTHER_OUTPUT*/

#if NUCODEGEN_PWM1_CH5_TRIGER_ADC_ENABLE

    /* Set trigger ADC and trigger source*/
    PWM_EnableADCTrigger(PWM1, 5, NUCODEGEN_PWM1_CH5_TRIGER_ADCSRC);

#endif /*NUCODEGEN_PWM1_CH5_TRIGER_ADC_ENABLE*/

#if ((NUCODEGEN_PWM1_CH5_INT_SEL) & 4)

    /* Enable duty interrupt - count up interrupt */
    PWM_EnableDutyInt(PWM1, 5, PWM_DUTY_INT_UP_COUNT_MATCH_CMP);

#endif /*NUCODEGEN_PWM1_CH5_INT_SEL*/

#if ((NUCODEGEN_PWM1_CH5_INT_SEL) & 8)

    /* Enable duty interrupt - count down interrupt */
    PWM_EnableDutyInt(PWM1, 5, PWM_DUTY_INT_DOWN_COUNT_MATCH_CMP);

#endif /*NUCODEGEN_PWM1_CH5_INT_SEL*/

#endif /*NUCODEGEN_PWM1_CH5_ADVANCED*/

#endif /*NUCODEGEN_PWM1_CH5_ENABLE*/

#endif

#endif /*NUCODEGEN_PWM1_CH4_5_OUTPUT_FUNC_SETMODE*/

#else

#if (NUCODEGEN_PWM1_CH4_CAP_ENABLE || NUCODEGEN_PWM1_CH5_CAP_ENABLE)

    /* Configure PWM capture and get the nearest unit time */
    PWM_ConfigCaptureChannel(PWM1, 4, NUCODEGEN_PWM1_CH4_5_CAP_UNITTIME, 0);

#if NUCODEGEN_PWM1_CH4_CAP_ENABLE

    /* Set Reload Mode */
    PWM1->CAPCTL |= (NUCODEGEN_PWM1_CH4_CAP_RELOAD)<<PWM_CAPCTL_RCRLDEN4_Pos;

    /* Enable Capture Function for PWM1 channel 4 */
    PWM_EnableCapture(PWM1, PWM_CH_4_MASK);

#if NUCODEGEN_PWM1_CH4_CAP_ADVANCED

#if (NUCODEGEN_PWM1_CH4_CAP_INT_SEL == 1)

    /*Enable rising latch capture interrupt*/
    PWM_EnableCaptureInt(PWM1, 4, PWM_CAPTURE_INT_RISING_LATCH);

#elif (NUCODEGEN_PWM1_CH4_CAP_INT_SEL == 2)

    /*Enable falling latch capture interrupt*/
    PWM_EnableCaptureInt(PWM1, 4, PWM_CAPTURE_INT_FALLING_LATCH);

#elif (NUCODEGEN_PWM1_CH4_CAP_INT_SEL == 3)

    /*Enable rising and falling latch capture interrupt*/
    PWM_EnableCaptureInt(PWM1, 4, PWM_CAPTURE_INT_RISING_LATCH|PWM_CAPTURE_INT_FALLING_LATCH);

#endif /*NUCODEGEN_PWM1_CH4_CAP_INT_SEL*/

#endif /*NUCODEGEN_PWM1_CH4_CAP_ADVANCED*/

#endif /*NUCODEGEN_PWM1_CH4_CAP_ENABLE*/

#if NUCODEGEN_PWM1_CH5_CAP_ENABLE

    /* Set Reload Mode */
    PWM1->CAPCTL |= (NUCODEGEN_PWM1_CH5_CAP_RELOAD)<<PWM_CAPCTL_RCRLDEN5_Pos;

    /* Enable Capture Function for PWM1 channel 5 */
    PWM_EnableCapture(PWM1, PWM_CH_5_MASK);

#if NUCODEGEN_PWM1_CH5_CAP_ADVANCED

#if (NUCODEGEN_PWM1_CH5_CAP_INT_SEL == 1)

    /*Enable rising latch capture interrupt*/
    PWM_EnableCaptureInt(PWM1, 5, PWM_CAPTURE_INT_RISING_LATCH);

#elif (NUCODEGEN_PWM1_CH5_CAP_INT_SEL == 2)

    /*Enable falling latch capture interrupt*/
    PWM_EnableCaptureInt(PWM1, 5, PWM_CAPTURE_INT_FALLING_LATCH);

#elif (NUCODEGEN_PWM1_CH5_CAP_INT_SEL == 3)

    /*Enable rising and falling latch capture interrupt*/
    PWM_EnableCaptureInt(PWM1, 5, PWM_CAPTURE_INT_RISING_LATCH|PWM_CAPTURE_INT_FALLING_LATCH);

#endif /*NUCODEGEN_PWM1_CH5_CAP_INT_SEL*/

#endif /*NUCODEGEN_PWM1_CH5_CAP_ADVANCED*/

#endif /*NUCODEGEN_PWM1_CH5_CAP_ENABLE*/

#endif /*NUCODEGEN_PWM1_CH4_CAP_ENABLE, NUCODEGEN_PWM1_CH5_CAP_ENABLE*/

#endif /*NUCODEGEN_PWM1_CH4_5_FUNC_SEL*/

#endif /*NUCODEGEN_PWM1_CH4CH5*/

#if NUCODEGEN_PWM1_CH0_1_BRAKE_PIN_INV

    /* Enable PWM brake noise filter */
    PWM_EnableBrakePinInv(PWM1, NUCODEGEN_PWM1_CH0_1_BRAKE_SRC);

#elif NUCODEGEN_PWM1_CH2_3_BRAKE_PIN_INV

    /* Enable PWM brake noise filter */
    PWM_EnableBrakePinInv(PWM1, NUCODEGEN_PWM1_CH2_3_BRAKE_SRC);

#elif NUCODEGEN_PWM1_CH4_5_BRAKE_PIN_INV

    /* Enable PWM brake noise filter */
    PWM_EnableBrakePinInv(PWM1, NUCODEGEN_PWM1_CH4_5_BRAKE_SRC);

#endif /*NUCODEGEN_PWM1_CH0_1_BRAKE_PIN_INV*/


#if NUCODEGEN_PWM1_CH0_1_BRAKE_FILTER_ENABLE

    /* Enable PWM brake noise filter */
    PWM_EnableBrakeFilter(PWM1, NUCODEGEN_PWM1_CH0_1_BRAKE_SRC|NUCODEGEN_PWM1_CH2_3_BRAKE_SRC|NUCODEGEN_PWM1_CH4_5_BRAKE_SRC, NUCODEGEN_PWM1_CH0_1_BRAKE_FILTER_CNT, NUCODEGEN_PWM1_CH0_1_BRAKE_FILTER_CLK);

#elif NUCODEGEN_PWM1_CH2_3_BRAKE_FILTER_ENABLE

    /* Enable PWM brake noise filter */
    PWM_EnableBrakeFilter(PWM1, NUCODEGEN_PWM1_CH2_3_BRAKE_SRC|NUCODEGEN_PWM1_CH4_5_BRAKE_SRC, NUCODEGEN_PWM1_CH2_3_BRAKE_FILTER_CNT, NUCODEGEN_PWM1_CH2_3_BRAKE_FILTER_CLK);

#elif NUCODEGEN_PWM1_CH4_5_BRAKE_FILTER_ENABLE

    /* Enable PWM brake noise filter */
    PWM_EnableBrakeFilter(PWM1, NUCODEGEN_PWM1_CH4_5_BRAKE_SRC, NUCODEGEN_PWM1_CH4_5_BRAKE_FILTER_CNT, NUCODEGEN_PWM1_CH4_5_BRAKE_FILTER_CLK);

#endif /*NUCODEGEN_PWM1_CH0_1_BRAKE_FILTER_ENABLE*/

#if (((NUCODEGEN_PWM1_CH0_INT_SEL) & 0x1F) \
  || ((NUCODEGEN_PWM1_CH1_INT_SEL) & 0x1F) \
  || ((NUCODEGEN_PWM1_CH2_INT_SEL) & 0x1F) \
  || ((NUCODEGEN_PWM1_CH3_INT_SEL) & 0x1F) \
  || ((NUCODEGEN_PWM1_CH4_INT_SEL) & 0x1F) \
  || ((NUCODEGEN_PWM1_CH5_INT_SEL) & 0x1F) \
  || ((NUCODEGEN_PWM1_CH0_CAP_INT_SEL) & 0x03) \
  || ((NUCODEGEN_PWM1_CH1_CAP_INT_SEL) & 0x03) \
  || ((NUCODEGEN_PWM1_CH2_CAP_INT_SEL) & 0x03) \
  || ((NUCODEGEN_PWM1_CH3_CAP_INT_SEL) & 0x03) \
  || ((NUCODEGEN_PWM1_CH4_CAP_INT_SEL) & 0x03) \
  || ((NUCODEGEN_PWM1_CH5_CAP_INT_SEL) & 0x03))
  
    /* Enable interrupt function */
    NVIC_EnableIRQ(PWM1_IRQn);
    
#endif
}

#endif /*NUCODEGEN_PWM1*/
