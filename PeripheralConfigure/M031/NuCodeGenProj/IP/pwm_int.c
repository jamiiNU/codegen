
#if NUCODEGEN_PWM0

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

void PWM0_IRQHandler(void)
{

#if ((NUCODEGEN_PWM0_CH0_INT_SEL) & 1)

    /* Get zero interrupt and clear flag - PWM two channals has one controller */
    if( PWM_GetZeroIntFlag(PWM0, 0) )
    {
        PWM_ClearZeroIntFlag(PWM0, 0);
    }

#endif /*NUCODEGEN_PWM0_CH0_INT_SEL*/

#if ((NUCODEGEN_PWM0_CH0_INT_SEL) & 2)

    /* Get period interrupt and clear flag - PWM two channals has one controller */
    if( PWM_GetPeriodIntFlag(PWM0, 0) )
    {
        PWM_ClearPeriodIntFlag(PWM0, 0);
    }

#endif /*NUCODEGEN_PWM0_CH0_INT_SEL*/

#if ( ((NUCODEGEN_PWM0_CH0_INT_SEL) & 4) || ((NUCODEGEN_PWM0_CH0_INT_SEL) & 8) )

    /*Get duty interrupt and clear flag*/
    if( PWM_GetDutyIntFlag(PWM0, 0) )
    {
        PWM_ClearDutyIntFlag(PWM0, 0);
    }

#endif /*NUCODEGEN_PWM0_CH0_INT_SEL*/

#if (NUCODEGEN_PWM0_CH0_CAP_INT_SEL == 1)

    /*Get rising latch capture interrupt and clear flag*/
    if( PWM_GetCaptureIntFlag(PWM0, 0) & 1)
    {
        PWM_ClearCaptureIntFlag(PWM0, 0, PWM_CAPTURE_INT_RISING_LATCH);
    }

#elif (NUCODEGEN_PWM0_CH0_CAP_INT_SEL == 2)

    /*Get falling latch capture interrupt and clear flag*/
    if( PWM_GetCaptureIntFlag(PWM0, 0) & 2)
    {
        PWM_ClearCaptureIntFlag(PWM0, 0, PWM_CAPTURE_INT_FALLING_LATCH);
    }

#elif (NUCODEGEN_PWM0_CH0_CAP_INT_SEL == 3)

    /*Get rising and fallinglatch capture interrupt and clear flag*/
    if( PWM_GetCaptureIntFlag(PWM0, 0) & 3)
    {
        PWM_ClearCaptureIntFlag(PWM0, 0, PWM_CAPTURE_INT_RISING_LATCH|PWM_CAPTURE_INT_FALLING_LATCH);
    }

#endif /*NUCODEGEN_PWM0_CH0_CAP_INT_SEL*/

#if ( ((NUCODEGEN_PWM0_CH1_INT_SEL) & 4) || ((NUCODEGEN_PWM0_CH1_INT_SEL) & 8) )

    /*Get duty interrupt and clear flag*/
    if( PWM_GetDutyIntFlag(PWM0, 1) )
    {
        PWM_ClearDutyIntFlag(PWM0, 1);
    }

#endif /*NUCODEGEN_PWM0_CH1_INT_SEL*/

#if (NUCODEGEN_PWM0_CH1_CAP_INT_SEL == 1)

    /*Get rising latch capture interrupt and clear flag*/
    if( PWM_GetCaptureIntFlag(PWM0, 1) & 1)
    {
        PWM_ClearCaptureIntFlag(PWM0, 1, PWM_CAPTURE_INT_RISING_LATCH);
    }

#elif (NUCODEGEN_PWM0_CH1_CAP_INT_SEL == 2)

    /*Get falling latch capture interrupt and clear flag*/
    if( PWM_GetCaptureIntFlag(PWM0, 1) & 2)
    {
        PWM_ClearCaptureIntFlag(PWM0, 1, PWM_CAPTURE_INT_FALLING_LATCH);
    }

#elif (NUCODEGEN_PWM0_CH1_CAP_INT_SEL == 3)

    /*Get rising and fallinglatch capture interrupt and clear flag*/
    if( PWM_GetCaptureIntFlag(PWM0, 1) & 3)
    {
        PWM_ClearCaptureIntFlag(PWM0, 1, PWM_CAPTURE_INT_RISING_LATCH|PWM_CAPTURE_INT_FALLING_LATCH);
    }

#endif /*NUCODEGEN_PWM0_CH1_CAP_INT_SEL*/

#if ((NUCODEGEN_PWM0_CH2_INT_SEL) & 1)

    /* Get zero interrupt and clear flag - PWM two channals has one controller */
    if( PWM_GetZeroIntFlag(PWM0, 2) )
    {
        PWM_ClearZeroIntFlag(PWM0, 2);
    }

#endif /*NUCODEGEN_PWM0_CH2_INT_SEL*/

#if ((NUCODEGEN_PWM0_CH2_INT_SEL) & 2)

    /* Get period interrupt and clear flag - PWM two channals has one controller */
    if( PWM_GetPeriodIntFlag(PWM0, 2) )
    {
        PWM_ClearPeriodIntFlag(PWM0, 2);
    }

#endif /*NUCODEGEN_PWM0_CH2_INT_SEL*/

#if ( ((NUCODEGEN_PWM0_CH2_INT_SEL) & 4) || ((NUCODEGEN_PWM0_CH2_INT_SEL) & 8) )

    /*Get duty interrupt and clear flag*/
    if( PWM_GetDutyIntFlag(PWM0, 2) )
    {
        PWM_ClearDutyIntFlag(PWM0, 2);
    }

#endif /*NUCODEGEN_PWM0_CH2_INT_SEL*/

#if (NUCODEGEN_PWM0_CH2_CAP_INT_SEL == 1)

    /*Get rising latch capture interrupt and clear flag*/
    if( PWM_GetCaptureIntFlag(PWM0, 2) & 1)
    {
        PWM_ClearCaptureIntFlag(PWM0, 2, PWM_CAPTURE_INT_RISING_LATCH);
    }

#elif (NUCODEGEN_PWM0_CH2_CAP_INT_SEL == 2)

    /*Get falling latch capture interrupt and clear flag*/
    if( PWM_GetCaptureIntFlag(PWM0, 2) & 2)
    {
        PWM_ClearCaptureIntFlag(PWM0, 2, PWM_CAPTURE_INT_FALLING_LATCH);
    }

#elif (NUCODEGEN_PWM0_CH2_CAP_INT_SEL == 3)

    /*Get rising and fallinglatch capture interrupt and clear flag*/
    if( PWM_GetCaptureIntFlag(PWM0, 2) & 3)
    {
        PWM_ClearCaptureIntFlag(PWM0, 2, PWM_CAPTURE_INT_RISING_LATCH|PWM_CAPTURE_INT_FALLING_LATCH);
    }

#endif /*NUCODEGEN_PWM0_CH2_CAP_INT_SEL*/

#if ( ((NUCODEGEN_PWM0_CH3_INT_SEL) & 4) || ((NUCODEGEN_PWM0_CH3_INT_SEL) & 8) )

    /*Get duty interrupt and clear flag*/
    if( PWM_GetDutyIntFlag(PWM0, 3) )
    {
        PWM_ClearDutyIntFlag(PWM0, 3);
    }

#endif /*NUCODEGEN_PWM0_CH3_INT_SEL*/

#if (NUCODEGEN_PWM0_CH3_CAP_INT_SEL == 1)

    /*Get rising latch capture interrupt and clear flag*/
    if( PWM_GetCaptureIntFlag(PWM0, 3) & 1)
    {
        PWM_ClearCaptureIntFlag(PWM0, 3, PWM_CAPTURE_INT_RISING_LATCH);
    }

#elif (NUCODEGEN_PWM0_CH3_CAP_INT_SEL == 2)

    /*Get falling latch capture interrupt and clear flag*/
    if( PWM_GetCaptureIntFlag(PWM0, 3) & 2)
    {
        PWM_ClearCaptureIntFlag(PWM0, 3, PWM_CAPTURE_INT_FALLING_LATCH);
    }

#elif (NUCODEGEN_PWM0_CH3_CAP_INT_SEL == 3)

    /*Get rising and fallinglatch capture interrupt and clear flag*/
    if( PWM_GetCaptureIntFlag(PWM0, 3) & 3)
    {
        PWM_ClearCaptureIntFlag(PWM0, 3, PWM_CAPTURE_INT_RISING_LATCH|PWM_CAPTURE_INT_FALLING_LATCH);
    }

#endif /*NUCODEGEN_PWM0_CH3_CAP_INT_SEL*/

#if ((NUCODEGEN_PWM0_CH4_INT_SEL) & 1)

    /* Get zero interrupt and clear flag - PWM two channals has one controller */
    if( PWM_GetZeroIntFlag(PWM0, 4) )
    {
        PWM_ClearZeroIntFlag(PWM0, 4);
    }

#endif /*NUCODEGEN_PWM0_CH4_INT_SEL*/

#if ((NUCODEGEN_PWM0_CH4_INT_SEL) & 2)

    /* Get period interrupt and clear flag - PWM two channals has one controller */
    if( PWM_GetPeriodIntFlag(PWM0, 4) )
    {
        PWM_ClearPeriodIntFlag(PWM0, 4);
    }

#endif /*NUCODEGEN_PWM0_CH4_INT_SEL*/

#if ( ((NUCODEGEN_PWM0_CH4_INT_SEL) & 4) || ((NUCODEGEN_PWM0_CH4_INT_SEL) & 8) )

    /*Get duty interrupt and clear flag*/
    if( PWM_GetDutyIntFlag(PWM0, 4) )
    {
        PWM_ClearDutyIntFlag(PWM0, 4);
    }

#endif /*NUCODEGEN_PWM0_CH4_INT_SEL*/

#if (NUCODEGEN_PWM0_CH4_CAP_INT_SEL == 1)

    /*Get rising latch capture interrupt and clear flag*/
    if( PWM_GetCaptureIntFlag(PWM0, 4) & 1)
    {
        PWM_ClearCaptureIntFlag(PWM0, 4, PWM_CAPTURE_INT_RISING_LATCH);
    }

#elif (NUCODEGEN_PWM0_CH4_CAP_INT_SEL == 2)

    /*Get falling latch capture interrupt and clear flag*/
    if( PWM_GetCaptureIntFlag(PWM0, 4) & 2)
    {
        PWM_ClearCaptureIntFlag(PWM0, 4, PWM_CAPTURE_INT_FALLING_LATCH);
    }

#elif (NUCODEGEN_PWM0_CH4_CAP_INT_SEL == 3)

    /*Get rising and fallinglatch capture interrupt and clear flag*/
    if( PWM_GetCaptureIntFlag(PWM0, 4) & 3)
    {
        PWM_ClearCaptureIntFlag(PWM0, 4, PWM_CAPTURE_INT_RISING_LATCH|PWM_CAPTURE_INT_FALLING_LATCH);
    }

#endif /*NUCODEGEN_PWM0_CH4_CAP_INT_SEL*/

#if ( ((NUCODEGEN_PWM0_CH5_INT_SEL) & 4) || ((NUCODEGEN_PWM0_CH5_INT_SEL) & 8) )

    /*Get duty interrupt and clear flag*/
    if( PWM_GetDutyIntFlag(PWM0, 5) )
    {
        PWM_ClearDutyIntFlag(PWM0, 5);
    }

#endif /*NUCODEGEN_PWM0_CH5_INT_SEL*/

#if (NUCODEGEN_PWM0_CH5_CAP_INT_SEL == 1)

    /*Get rising latch capture interrupt and clear flag*/
    if( PWM_GetCaptureIntFlag(PWM0, 5) & 1)
    {
        PWM_ClearCaptureIntFlag(PWM0, 5, PWM_CAPTURE_INT_RISING_LATCH);
    }

#elif (NUCODEGEN_PWM0_CH5_CAP_INT_SEL == 2)

    /*Get falling latch capture interrupt and clear flag*/
    if( PWM_GetCaptureIntFlag(PWM0, 5) & 2)
    {
        PWM_ClearCaptureIntFlag(PWM0, 5, PWM_CAPTURE_INT_FALLING_LATCH);
    }

#elif (NUCODEGEN_PWM0_CH5_CAP_INT_SEL == 3)

    /*Get rising and fallinglatch capture interrupt and clear flag*/
    if( PWM_GetCaptureIntFlag(PWM0, 5) & 3)
    {
        PWM_ClearCaptureIntFlag(PWM0, 5, PWM_CAPTURE_INT_RISING_LATCH|PWM_CAPTURE_INT_FALLING_LATCH);
    }

#endif /*NUCODEGEN_PWM0_CH5_CAP_INT_SEL*/

#if ((NUCODEGEN_PWM0_CH0_INT_SEL) & 16)

    /* Get fault brake interrupt and clear flag */
    if( ((PWM0->INTSTS1) & (PWM_CH_0_MASK << NUCODEGEN_PWM0_CH0_1_BRAKE_DETECT_TYPE)) )
    {
        PWM0->INTSTS1 = (PWM_CH_0_MASK << NUCODEGEN_PWM0_CH0_1_BRAKE_DETECT_TYPE);
    }

#endif /*NUCODEGEN_PWM0_CH0_INT_SEL*/

#if ((NUCODEGEN_PWM0_CH1_INT_SEL) & 16)

    /* Get fault brake interrupt and clear flag */
    if( ((PWM0->INTSTS1) & (PWM_CH_1_MASK << NUCODEGEN_PWM0_CH0_1_BRAKE_DETECT_TYPE)) )
    {
        PWM0->INTSTS1 = (PWM_CH_1_MASK << NUCODEGEN_PWM0_CH0_1_BRAKE_DETECT_TYPE);
    }

#endif /*NUCODEGEN_PWM0_CH1_INT_SEL*/

#if ((NUCODEGEN_PWM0_CH2_INT_SEL) & 16)

    /*Get fault brake interrupt and clear flag*/
    if( ((PWM0->INTSTS1) & (PWM_CH_2_MASK << NUCODEGEN_PWM0_CH2_3_BRAKE_DETECT_TYPE)) )
    {
        PWM0->INTSTS1 = (PWM_CH_2_MASK << NUCODEGEN_PWM0_CH2_3_BRAKE_DETECT_TYPE);
    }

#endif /*NUCODEGEN_PWM0_CH2_INT_SEL*/

#if ((NUCODEGEN_PWM0_CH3_INT_SEL) & 16)

    /*Get fault brake interrupt and clear flag*/
    if( ((PWM0->INTSTS1) & (PWM_CH_3_MASK << NUCODEGEN_PWM0_CH2_3_BRAKE_DETECT_TYPE)) )
    {
        PWM0->INTSTS1 = (PWM_CH_3_MASK << NUCODEGEN_PWM0_CH2_3_BRAKE_DETECT_TYPE);
    }

#endif /*NUCODEGEN_PWM0_CH3_INT_SEL*/

#if ((NUCODEGEN_PWM0_CH4_INT_SEL) & 16)

    /*Get fault brake interrupt and clear flag*/
    if( ((PWM0->INTSTS1) & (PWM_CH_4_MASK << NUCODEGEN_PWM0_CH4_5_BRAKE_DETECT_TYPE)) )
    {
        PWM0->INTSTS1 = (PWM_CH_4_MASK << NUCODEGEN_PWM0_CH4_5_BRAKE_DETECT_TYPE);
    }

#endif /*NUCODEGEN_PWM0_CH4_5_INT_SEL*/

#if ((NUCODEGEN_PWM0_CH5_INT_SEL) & 16)

    /*Get fault brake interrupt and clear flag*/
    if( ((PWM0->INTSTS1) & (PWM_CH_5_MASK << NUCODEGEN_PWM0_CH4_5_BRAKE_DETECT_TYPE)) )
    {
        PWM0->INTSTS1 = (PWM_CH_5_MASK << NUCODEGEN_PWM0_CH4_5_BRAKE_DETECT_TYPE);
    }

#endif /*NUCODEGEN_PWM0_CH4_5_INT_SEL*/

}

#endif // NUCODEGEN_PWM0_CHx_INT_SEL || NUCODEGEN_PWM0_CHx_CAP_INT_SEL

#endif //NUCODEGEN_PWM0

#if NUCODEGEN_PWM1

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

void PWM1_IRQHandler(void)
{

#if ((NUCODEGEN_PWM1_CH0_INT_SEL) & 1)

    /* Get zero interrupt and clear flag - PWM two channals has one controller */
    if( PWM_GetZeroIntFlag(PWM1, 0) )
    {
        PWM_ClearZeroIntFlag(PWM1, 0);
    }

#endif /*NUCODEGEN_PWM1_CH0_INT_SEL*/

#if ((NUCODEGEN_PWM1_CH0_INT_SEL) & 2)

    /* Get period interrupt and clear flag - PWM two channals has one controller */
    if( PWM_GetPeriodIntFlag(PWM1, 0) )
    {
        PWM_ClearPeriodIntFlag(PWM1, 0);
    }

#endif /*NUCODEGEN_PWM1_CH0_INT_SEL*/

#if ( ((NUCODEGEN_PWM1_CH0_INT_SEL) & 4) || ((NUCODEGEN_PWM1_CH0_INT_SEL) & 8) )

    /*Get duty interrupt and clear flag*/
    if( PWM_GetDutyIntFlag(PWM1, 0) )
    {
        PWM_ClearDutyIntFlag(PWM1, 0);
    }

#endif /*NUCODEGEN_PWM1_CH0_INT_SEL*/

#if (NUCODEGEN_PWM1_CH0_CAP_INT_SEL == 1)

    /*Get rising latch capture interrupt and clear flag*/
    if( PWM_GetCaptureIntFlag(PWM1, 0) & 1)
    {
        PWM_ClearCaptureIntFlag(PWM1, 0, PWM_CAPTURE_INT_RISING_LATCH);
    }

#elif (NUCODEGEN_PWM1_CH0_CAP_INT_SEL == 2)

    /*Get falling latch capture interrupt and clear flag*/
    if( PWM_GetCaptureIntFlag(PWM1, 0) & 2)
    {
        PWM_ClearCaptureIntFlag(PWM1, 0, PWM_CAPTURE_INT_FALLING_LATCH);
    }

#elif (NUCODEGEN_PWM1_CH0_CAP_INT_SEL == 3)

    /*Get rising and fallinglatch capture interrupt and clear flag*/
    if( PWM_GetCaptureIntFlag(PWM1, 0) & 3)
    {
        PWM_ClearCaptureIntFlag(PWM1, 0, PWM_CAPTURE_INT_RISING_LATCH|PWM_CAPTURE_INT_FALLING_LATCH);
    }

#endif /*NUCODEGEN_PWM1_CH0_CAP_INT_SEL*/

#if ( ((NUCODEGEN_PWM1_CH1_INT_SEL) & 4) || ((NUCODEGEN_PWM1_CH1_INT_SEL) & 8) )

    /*Get duty interrupt and clear flag*/
    if( PWM_GetDutyIntFlag(PWM1, 1) )
    {
        PWM_ClearDutyIntFlag(PWM1, 1);
    }

#endif /*NUCODEGEN_PWM1_CH1_INT_SEL*/

#if (NUCODEGEN_PWM1_CH1_CAP_INT_SEL == 1)

    /*Get rising latch capture interrupt and clear flag*/
    if( PWM_GetCaptureIntFlag(PWM1, 1) & 1)
    {
        PWM_ClearCaptureIntFlag(PWM1, 1, PWM_CAPTURE_INT_RISING_LATCH);
    }

#elif (NUCODEGEN_PWM1_CH1_CAP_INT_SEL == 2)

    /*Get falling latch capture interrupt and clear flag*/
    if( PWM_GetCaptureIntFlag(PWM1, 1) & 2)
    {
        PWM_ClearCaptureIntFlag(PWM1, 1, PWM_CAPTURE_INT_FALLING_LATCH);
    }

#elif (NUCODEGEN_PWM1_CH1_CAP_INT_SEL == 3)

    /*Get rising and fallinglatch capture interrupt and clear flag*/
    if( PWM_GetCaptureIntFlag(PWM1, 1) & 3)
    {
        PWM_ClearCaptureIntFlag(PWM1, 1, PWM_CAPTURE_INT_RISING_LATCH|PWM_CAPTURE_INT_FALLING_LATCH);
    }

#endif /*NUCODEGEN_PWM1_CH1_CAP_INT_SEL*/

#if ((NUCODEGEN_PWM1_CH2_INT_SEL) & 1)

    /* Get zero interrupt and clear flag - PWM two channals has one controller */
    if( PWM_GetZeroIntFlag(PWM1, 2) )
    {
        PWM_ClearZeroIntFlag(PWM1, 2);
    }

#endif /*NUCODEGEN_PWM1_CH2_INT_SEL*/

#if ((NUCODEGEN_PWM1_CH2_INT_SEL) & 2)

    /* Get period interrupt and clear flag - PWM two channals has one controller */
    if( PWM_GetPeriodIntFlag(PWM1, 2) )
    {
        PWM_ClearPeriodIntFlag(PWM1, 2);
    }

#endif /*NUCODEGEN_PWM1_CH2_INT_SEL*/

#if ( ((NUCODEGEN_PWM1_CH2_INT_SEL) & 4) || ((NUCODEGEN_PWM1_CH2_INT_SEL) & 8) )

    /*Get duty interrupt and clear flag*/
    if( PWM_GetDutyIntFlag(PWM1, 2) )
    {
        PWM_ClearDutyIntFlag(PWM1, 2);
    }

#endif /*NUCODEGEN_PWM1_CH2_INT_SEL*/

#if (NUCODEGEN_PWM1_CH2_CAP_INT_SEL == 1)

    /*Get rising latch capture interrupt and clear flag*/
    if( PWM_GetCaptureIntFlag(PWM1, 2) & 1)
    {
        PWM_ClearCaptureIntFlag(PWM1, 2, PWM_CAPTURE_INT_RISING_LATCH);
    }

#elif (NUCODEGEN_PWM1_CH2_CAP_INT_SEL == 2)

    /*Get falling latch capture interrupt and clear flag*/
    if( PWM_GetCaptureIntFlag(PWM1, 2) & 2)
    {
        PWM_ClearCaptureIntFlag(PWM1, 2, PWM_CAPTURE_INT_FALLING_LATCH);
    }

#elif (NUCODEGEN_PWM1_CH2_CAP_INT_SEL == 3)

    /*Get rising and fallinglatch capture interrupt and clear flag*/
    if( PWM_GetCaptureIntFlag(PWM1, 2) & 3)
    {
        PWM_ClearCaptureIntFlag(PWM1, 2, PWM_CAPTURE_INT_RISING_LATCH|PWM_CAPTURE_INT_FALLING_LATCH);
    }

#endif /*NUCODEGEN_PWM1_CH2_CAP_INT_SEL*/

#if ( ((NUCODEGEN_PWM1_CH3_INT_SEL) & 4) || ((NUCODEGEN_PWM1_CH3_INT_SEL) & 8) )

    /*Get duty interrupt and clear flag*/
    if( PWM_GetDutyIntFlag(PWM1, 3) )
    {
        PWM_ClearDutyIntFlag(PWM1, 3);
    }

#endif /*NUCODEGEN_PWM1_CH3_INT_SEL*/

#if (NUCODEGEN_PWM1_CH3_CAP_INT_SEL == 1)

    /*Get rising latch capture interrupt and clear flag*/
    if( PWM_GetCaptureIntFlag(PWM1, 3) & 1)
    {
        PWM_ClearCaptureIntFlag(PWM1, 3, PWM_CAPTURE_INT_RISING_LATCH);
    }

#elif (NUCODEGEN_PWM1_CH3_CAP_INT_SEL == 2)

    /*Get falling latch capture interrupt and clear flag*/
    if( PWM_GetCaptureIntFlag(PWM1, 3) & 2)
    {
        PWM_ClearCaptureIntFlag(PWM1, 3, PWM_CAPTURE_INT_FALLING_LATCH);
    }

#elif (NUCODEGEN_PWM1_CH3_CAP_INT_SEL == 3)

    /*Get rising and fallinglatch capture interrupt and clear flag*/
    if( PWM_GetCaptureIntFlag(PWM1, 3) & 3)
    {
        PWM_ClearCaptureIntFlag(PWM1, 3, PWM_CAPTURE_INT_RISING_LATCH|PWM_CAPTURE_INT_FALLING_LATCH);
    }

#endif /*NUCODEGEN_PWM1_CH3_CAP_INT_SEL*/

#if ((NUCODEGEN_PWM1_CH4_INT_SEL) & 1)

    /* Get zero interrupt and clear flag - PWM two channals has one controller */
    if( PWM_GetZeroIntFlag(PWM1, 4) )
    {
        PWM_ClearZeroIntFlag(PWM1, 4);
    }

#endif /*NUCODEGEN_PWM1_CH4_INT_SEL*/

#if ((NUCODEGEN_PWM1_CH4_INT_SEL) & 2)

    /* Get period interrupt and clear flag - PWM two channals has one controller */
    if( PWM_GetPeriodIntFlag(PWM1, 4) )
    {
        PWM_ClearPeriodIntFlag(PWM1, 4);
    }

#endif /*NUCODEGEN_PWM1_CH4_INT_SEL*/

#if ( ((NUCODEGEN_PWM1_CH4_INT_SEL) & 4) || ((NUCODEGEN_PWM1_CH4_INT_SEL) & 8) )

    /*Get duty interrupt and clear flag*/
    if( PWM_GetDutyIntFlag(PWM1, 4) )
    {
        PWM_ClearDutyIntFlag(PWM1, 4);
    }

#endif /*NUCODEGEN_PWM1_CH4_INT_SEL*/

#if (NUCODEGEN_PWM1_CH4_CAP_INT_SEL == 1)

    /*Get rising latch capture interrupt and clear flag*/
    if( PWM_GetCaptureIntFlag(PWM1, 4) & 1)
    {
        PWM_ClearCaptureIntFlag(PWM1, 4, PWM_CAPTURE_INT_RISING_LATCH);
    }

#elif (NUCODEGEN_PWM1_CH4_CAP_INT_SEL == 2)

    /*Get falling latch capture interrupt and clear flag*/
    if( PWM_GetCaptureIntFlag(PWM1, 4) & 2)
    {
        PWM_ClearCaptureIntFlag(PWM1, 4, PWM_CAPTURE_INT_FALLING_LATCH);
    }

#elif (NUCODEGEN_PWM1_CH4_CAP_INT_SEL == 3)

    /*Get rising and fallinglatch capture interrupt and clear flag*/
    if( PWM_GetCaptureIntFlag(PWM1, 4) & 3)
    {
        PWM_ClearCaptureIntFlag(PWM1, 4, PWM_CAPTURE_INT_RISING_LATCH|PWM_CAPTURE_INT_FALLING_LATCH);
    }

#endif /*NUCODEGEN_PWM1_CH4_CAP_INT_SEL*/

#if ( ((NUCODEGEN_PWM1_CH5_INT_SEL) & 4) || ((NUCODEGEN_PWM1_CH5_INT_SEL) & 8) )

    /*Get duty interrupt and clear flag*/
    if( PWM_GetDutyIntFlag(PWM1, 5) )
    {
        PWM_ClearDutyIntFlag(PWM1, 5);
    }

#endif /*NUCODEGEN_PWM1_CH5_INT_SEL*/

#if (NUCODEGEN_PWM1_CH5_CAP_INT_SEL == 1)

    /*Get rising latch capture interrupt and clear flag*/
    if( PWM_GetCaptureIntFlag(PWM1, 5) & 1)
    {
        PWM_ClearCaptureIntFlag(PWM1, 5, PWM_CAPTURE_INT_RISING_LATCH);
    }

#elif (NUCODEGEN_PWM1_CH5_CAP_INT_SEL == 2)

    /*Get falling latch capture interrupt and clear flag*/
    if( PWM_GetCaptureIntFlag(PWM1, 5) & 2)
    {
        PWM_ClearCaptureIntFlag(PWM1, 5, PWM_CAPTURE_INT_FALLING_LATCH);
    }

#elif (NUCODEGEN_PWM1_CH5_CAP_INT_SEL == 3)

    /*Get rising and fallinglatch capture interrupt and clear flag*/
    if( PWM_GetCaptureIntFlag(PWM1, 5) & 3)
    {
        PWM_ClearCaptureIntFlag(PWM1, 5, PWM_CAPTURE_INT_RISING_LATCH|PWM_CAPTURE_INT_FALLING_LATCH);
    }

#endif /*NUCODEGEN_PWM1_CH5_CAP_INT_SEL*/

#if ((NUCODEGEN_PWM1_CH0_INT_SEL) & 16)

    /* Get fault brake interrupt and clear flag */
    if( ((PWM1->INTSTS1) & (PWM_CH_0_MASK << NUCODEGEN_PWM1_CH0_1_BRAKE_DETECT_TYPE)) )
    {
        PWM1->INTSTS1 = (PWM_CH_0_MASK << NUCODEGEN_PWM1_CH0_1_BRAKE_DETECT_TYPE);
    }

#endif /*NUCODEGEN_PWM1_CH0_INT_SEL*/

#if ((NUCODEGEN_PWM1_CH1_INT_SEL) & 16)

    /* Get fault brake interrupt and clear flag */
    if( ((PWM1->INTSTS1) & (PWM_CH_1_MASK << NUCODEGEN_PWM1_CH0_1_BRAKE_DETECT_TYPE)) )
    {
        PWM1->INTSTS1 = (PWM_CH_1_MASK << NUCODEGEN_PWM1_CH0_1_BRAKE_DETECT_TYPE);
    }

#endif /*NUCODEGEN_PWM1_CH0_INT_SEL*/

#if ((NUCODEGEN_PWM1_CH2_INT_SEL) & 16)

    /*Get fault brake interrupt and clear flag*/
    if( ((PWM1->INTSTS1) & (PWM_CH_2_MASK << NUCODEGEN_PWM1_CH2_3_BRAKE_DETECT_TYPE)) )
    {
        PWM1->INTSTS1 = (PWM_CH_2_MASK << NUCODEGEN_PWM1_CH2_3_BRAKE_DETECT_TYPE);
    }

#endif /*NUCODEGEN_PWM1_CH2_INT_SEL*/

#if ((NUCODEGEN_PWM1_CH3_INT_SEL) & 16)

    /*Get fault brake interrupt and clear flag*/
    if( ((PWM1->INTSTS1) & (PWM_CH_3_MASK << NUCODEGEN_PWM1_CH2_3_BRAKE_DETECT_TYPE)) )
    {
        PWM1->INTSTS1 = (PWM_CH_3_MASK << NUCODEGEN_PWM1_CH2_3_BRAKE_DETECT_TYPE);
    }

#endif /*NUCODEGEN_PWM1_CH2_INT_SEL*/

#if ((NUCODEGEN_PWM1_CH4_INT_SEL) & 16)

    /*Get fault brake interrupt and clear flag*/
    if( ((PWM1->INTSTS1) & (PWM_CH_4_MASK << NUCODEGEN_PWM1_CH4_5_BRAKE_DETECT_TYPE)) )
    {
        PWM1->INTSTS1 = (PWM_CH_4_MASK << NUCODEGEN_PWM1_CH4_5_BRAKE_DETECT_TYPE);
    }

#endif /*NUCODEGEN_PWM1_CH4_5_INT_SEL*/

#if ((NUCODEGEN_PWM1_CH5_INT_SEL) & 16)

    /*Get fault brake interrupt and clear flag*/
    if( ((PWM1->INTSTS1) & (PWM_CH_5_MASK << NUCODEGEN_PWM1_CH4_5_BRAKE_DETECT_TYPE)) )
    {
        PWM1->INTSTS1 = (PWM_CH_5_MASK << NUCODEGEN_PWM1_CH4_5_BRAKE_DETECT_TYPE);
    }

#endif /*NUCODEGEN_PWM1_CH4_5_INT_SEL*/

}

#endif // NUCODEGEN_PWM1_CHx_INT_SEL || NUCODEGEN_PWM1_CHx_CAP_INT_SEL

#endif //NUCODEGEN_PWM1
