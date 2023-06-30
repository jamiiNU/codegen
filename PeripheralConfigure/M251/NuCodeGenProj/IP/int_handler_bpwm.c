
#if NUCODEGEN_BPWM0
void BPWM0_IRQHandler(void)
{
#if (((NUCODEGEN_BPWM0_CH0_INT_SEL) & 1)||((NUCODEGEN_BPWM0_CH1_INT_SEL) & 1)||((NUCODEGEN_BPWM0_CH2_INT_SEL) & 1)||((NUCODEGEN_BPWM0_CH3_INT_SEL) & 1)||((NUCODEGEN_BPWM0_CH4_INT_SEL) & 1)||((NUCODEGEN_BPWM0_CH5_INT_SEL) & 1))

    /* Get zero interrupt and clear flag - BPWM0 has only one controller */
    if( BPWM_GetZeroIntFlag(BPWM0, 0) )
    {
        BPWM_ClearZeroIntFlag(BPWM0, 0) ;
    }

#endif

#if (((NUCODEGEN_BPWM0_CH0_INT_SEL) & 2)||((NUCODEGEN_BPWM0_CH1_INT_SEL) & 2)||((NUCODEGEN_BPWM0_CH2_INT_SEL) & 2)||((NUCODEGEN_BPWM0_CH3_INT_SEL) & 2)||((NUCODEGEN_BPWM0_CH4_INT_SEL) & 2)||((NUCODEGEN_BPWM0_CH5_INT_SEL) & 2))

    /* Get period interrupt and clear flag - BPWM0 has only one controller */
    if( BPWM_GetPeriodIntFlag(BPWM0, 0) )
    {
        BPWM_ClearPeriodIntFlag(BPWM0, 0) ;
    }

#endif

#if ( ((NUCODEGEN_BPWM0_CH0_INT_SEL) & 4) || ((NUCODEGEN_BPWM0_CH0_INT_SEL) & 8) )

    /*Get duty interrupt and clear flag*/
    if( BPWM_GetDutyIntFlag(BPWM0, 0) )
    {
        BPWM_ClearDutyIntFlag(BPWM0, 0) ;
    }

#endif /*NUCODEGEN_BPWM0_CH0_INT_SEL*/

#if (NUCODEGEN_BPWM0_CH0_CAP_INT_SEL == 1)

    /*Get rising latch capture interrupt and clear flag*/
    if( BPWM_GetCaptureIntFlag(BPWM0, 0) & 1)
    {
        BPWM_ClearCaptureIntFlag(BPWM0, 0, BPWM_CAPTURE_INT_RISING_LATCH) ;
    }

#elif (NUCODEGEN_BPWM0_CH0_CAP_INT_SEL == 2)

    /*Get falling latch capture interrupt and clear flag*/
    if( BPWM_GetCaptureIntFlag(BPWM0, 0) & 2)
    {
        BPWM_ClearCaptureIntFlag(BPWM0, 0, BPWM_CAPTURE_INT_FALLING_LATCH) ;
    }

#elif (NUCODEGEN_BPWM0_CH0_CAP_INT_SEL == 3)

    /*Get rising and fallinglatch capture interrupt and clear flag*/
    if( BPWM_GetCaptureIntFlag(BPWM0, 0) & 3)
    {
        BPWM_ClearCaptureIntFlag(BPWM0, 0, BPWM_CAPTURE_INT_RISING_LATCH|BPWM_CAPTURE_INT_FALLING_LATCH) ;
    }

#endif /*NUCODEGEN_BPWM0_CH0_CAP_INT_SEL*/

#if ( ((NUCODEGEN_BPWM0_CH1_INT_SEL) & 4) || ((NUCODEGEN_BPWM0_CH1_INT_SEL) & 8) )

    /*Get duty interrupt and clear flag*/
    if( BPWM_GetDutyIntFlag(BPWM0, 1) )
    {
        BPWM_ClearDutyIntFlag(BPWM0, 1) ;
    }

#endif /*NUCODEGEN_BPWM0_CH1_INT_SEL*/

#if (NUCODEGEN_BPWM0_CH1_CAP_INT_SEL == 1)

    /*Get rising latch capture interrupt and clear flag*/
    if( BPWM_GetCaptureIntFlag(BPWM0, 1) & 1)
    {
        BPWM_ClearCaptureIntFlag(BPWM0, 1, BPWM_CAPTURE_INT_RISING_LATCH) ;
    }

#elif (NUCODEGEN_BPWM0_CH1_CAP_INT_SEL == 2)

    /*Get falling latch capture interrupt and clear flag*/
    if( BPWM_GetCaptureIntFlag(BPWM0, 1) & 2)
    {
        BPWM_ClearCaptureIntFlag(BPWM0, 1, BPWM_CAPTURE_INT_FALLING_LATCH) ;
    }

#elif (NUCODEGEN_BPWM0_CH1_CAP_INT_SEL == 3)

    /*Get rising and fallinglatch capture interrupt and clear flag*/
    if( BPWM_GetCaptureIntFlag(BPWM0, 1) & 3)
    {
        BPWM_ClearCaptureIntFlag(BPWM0, 1, BPWM_CAPTURE_INT_RISING_LATCH|BPWM_CAPTURE_INT_FALLING_LATCH) ;
    }

#endif /*NUCODEGEN_BPWM0_CH1_CAP_INT_SEL*/

#if ( ((NUCODEGEN_BPWM0_CH2_INT_SEL) & 4) || ((NUCODEGEN_BPWM0_CH2_INT_SEL) & 8) )

    /*Get duty interrupt and clear flag*/
    if( BPWM_GetDutyIntFlag(BPWM0, 2) )
    {
        BPWM_ClearDutyIntFlag(BPWM0, 2) ;
    }

#endif /*NUCODEGEN_BPWM0_CH2_INT_SEL*/

#if (NUCODEGEN_BPWM0_CH2_CAP_INT_SEL == 1)

    /*Get rising latch capture interrupt and clear flag*/
    if( BPWM_GetCaptureIntFlag(BPWM0, 2) & 1)
    {
        BPWM_ClearCaptureIntFlag(BPWM0, 2, BPWM_CAPTURE_INT_RISING_LATCH) ;
    }

#elif (NUCODEGEN_BPWM0_CH2_CAP_INT_SEL == 2)

    /*Get falling latch capture interrupt and clear flag*/
    if( BPWM_GetCaptureIntFlag(BPWM0, 2) & 2)
    {
        BPWM_ClearCaptureIntFlag(BPWM0, 2, BPWM_CAPTURE_INT_FALLING_LATCH) ;
    }

#elif (NUCODEGEN_BPWM0_CH2_CAP_INT_SEL == 3)

    /*Get rising and fallinglatch capture interrupt and clear flag*/
    if( BPWM_GetCaptureIntFlag(BPWM0, 2) & 3)
    {
        BPWM_ClearCaptureIntFlag(BPWM0, 2, BPWM_CAPTURE_INT_RISING_LATCH|BPWM_CAPTURE_INT_FALLING_LATCH) ;
    }

#endif /*NUCODEGEN_BPWM0_CH2_CAP_INT_SEL*/

#if ( ((NUCODEGEN_BPWM0_CH3_INT_SEL) & 4) || ((NUCODEGEN_BPWM0_CH3_INT_SEL) & 8) )

    /*Get duty interrupt and clear flag*/
    if( BPWM_GetDutyIntFlag(BPWM0, 3) )
    {
        BPWM_ClearDutyIntFlag(BPWM0, 3) ;
    }

#endif /*NUCODEGEN_BPWM0_CH3_INT_SEL*/

#if (NUCODEGEN_BPWM0_CH3_CAP_INT_SEL == 1)

    /*Get rising latch capture interrupt and clear flag*/
    if( BPWM_GetCaptureIntFlag(BPWM0, 3) & 1)
    {
        BPWM_ClearCaptureIntFlag(BPWM0, 3, BPWM_CAPTURE_INT_RISING_LATCH) ;
    }

#elif (NUCODEGEN_BPWM0_CH3_CAP_INT_SEL == 2)

    /*Get falling latch capture interrupt and clear flag*/
    if( BPWM_GetCaptureIntFlag(BPWM0, 3) & 2)
    {
        BPWM_ClearCaptureIntFlag(BPWM0, 3, BPWM_CAPTURE_INT_FALLING_LATCH) ;
    }

#elif (NUCODEGEN_BPWM0_CH3_CAP_INT_SEL == 3)

    /*Get rising and fallinglatch capture interrupt and clear flag*/
    if( BPWM_GetCaptureIntFlag(BPWM0, 3) & 3)
    {
        BPWM_ClearCaptureIntFlag(BPWM0, 3, BPWM_CAPTURE_INT_RISING_LATCH|BPWM_CAPTURE_INT_FALLING_LATCH) ;
    }

#endif /*NUCODEGEN_BPWM0_CH3_CAP_INT_SEL*/

#if ( ((NUCODEGEN_BPWM0_CH4_INT_SEL) & 4) || ((NUCODEGEN_BPWM0_CH4_INT_SEL) & 8) )

    /*Get duty interrupt and clear flag*/
    if( BPWM_GetDutyIntFlag(BPWM0, 4) )
    {
        BPWM_ClearDutyIntFlag(BPWM0, 4) ;
    }

#endif /*NUCODEGEN_BPWM0_CH4_INT_SEL*/

#if (NUCODEGEN_BPWM0_CH4_CAP_INT_SEL == 1)

    /*Get rising latch capture interrupt and clear flag*/
    if( BPWM_GetCaptureIntFlag(BPWM0, 4) & 1)
    {
        BPWM_ClearCaptureIntFlag(BPWM0, 4, BPWM_CAPTURE_INT_RISING_LATCH) ;
    }

#elif (NUCODEGEN_BPWM0_CH4_CAP_INT_SEL == 2)

    /*Get falling latch capture interrupt and clear flag*/
    if( BPWM_GetCaptureIntFlag(BPWM0, 4) & 2)
    {
        BPWM_ClearCaptureIntFlag(BPWM0, 4, BPWM_CAPTURE_INT_FALLING_LATCH) ;
    }

#elif (NUCODEGEN_BPWM0_CH4_CAP_INT_SEL == 3)

    /*Get rising and fallinglatch capture interrupt and clear flag*/
    if( BPWM_GetCaptureIntFlag(BPWM0, 4) & 3)
    {
        BPWM_ClearCaptureIntFlag(BPWM0, 4, BPWM_CAPTURE_INT_RISING_LATCH|BPWM_CAPTURE_INT_FALLING_LATCH) ;
    }

#endif /*NUCODEGEN_BPWM0_CH4_CAP_INT_SEL*/

#if ( ((NUCODEGEN_BPWM0_CH5_INT_SEL) & 4) || ((NUCODEGEN_BPWM0_CH5_INT_SEL) & 8) )

    /*Get duty interrupt and clear flag*/
    if( BPWM_GetDutyIntFlag(BPWM0, 5) )
    {
        BPWM_ClearDutyIntFlag(BPWM0, 5) ;
    }

#endif /*NUCODEGEN_BPWM0_CH5_INT_SEL*/

#if (NUCODEGEN_BPWM0_CH5_CAP_INT_SEL == 1)

    /*Get rising latch capture interrupt and clear flag*/
    if( BPWM_GetCaptureIntFlag(BPWM0, 5) & 1)
    {
        BPWM_ClearCaptureIntFlag(BPWM0, 5, BPWM_CAPTURE_INT_RISING_LATCH) ;
    }

#elif (NUCODEGEN_BPWM0_CH5_CAP_INT_SEL == 2)

    /*Get falling latch capture interrupt and clear flag*/
    if( BPWM_GetCaptureIntFlag(BPWM0, 5) & 2)
    {
        BPWM_ClearCaptureIntFlag(BPWM0, 5, BPWM_CAPTURE_INT_FALLING_LATCH) ;
    }

#elif (NUCODEGEN_BPWM0_CH5_CAP_INT_SEL == 3)

    /*Get rising and fallinglatch capture interrupt and clear flag*/
    if( BPWM_GetCaptureIntFlag(BPWM0, 5) & 3)
    {
        BPWM_ClearCaptureIntFlag(BPWM0, 5, BPWM_CAPTURE_INT_RISING_LATCH|BPWM_CAPTURE_INT_FALLING_LATCH) ;
    }

#endif /*NUCODEGEN_BPWM0_CH5_CAP_INT_SEL*/
}

#endif //NUCODEGEN_BPWM0

#if NUCODEGEN_BPWM1

void BPWM1_IRQHandler(void)
{

#if ((NUCODEGEN_BPWM1_CH0_INT_SEL & 1)||(NUCODEGEN_BPWM1_CH1_INT_SEL & 1)||(NUCODEGEN_BPWM1_CH2_INT_SEL & 1)||(NUCODEGEN_BPWM1_CH3_INT_SEL & 1)||(NUCODEGEN_BPWM1_CH4_INT_SEL & 1)||(NUCODEGEN_BPWM1_CH5_INT_SEL & 1))

    /* Get zero interrupt and clear flag - BPWM1 has only one controller */
    if( BPWM_GetZeroIntFlag(BPWM1, 0) )
    {
        BPWM_ClearZeroIntFlag(BPWM1, 0) ;
    }

#endif

#if ((NUCODEGEN_BPWM1_CH0_INT_SEL & 2)||(NUCODEGEN_BPWM1_CH1_INT_SEL & 2)||(NUCODEGEN_BPWM1_CH2_INT_SEL & 2)||(NUCODEGEN_BPWM1_CH3_INT_SEL & 2)||(NUCODEGEN_BPWM1_CH4_INT_SEL & 2)||(NUCODEGEN_BPWM1_CH5_INT_SEL & 2))

    /* Get period interrupt and clear flag - BPWM1 has only one controller */
    if( BPWM_GetPeriodIntFlag(BPWM1, 0) )
    {
        BPWM_ClearPeriodIntFlag(BPWM1, 0) ;
    }

#endif

#if ( ((NUCODEGEN_BPWM1_CH0_INT_SEL) & 4) || ((NUCODEGEN_BPWM1_CH0_INT_SEL) & 8) )

    /*Get duty interrupt and clear flag*/
    if( BPWM_GetDutyIntFlag(BPWM1, 0) )
    {
        BPWM_ClearDutyIntFlag(BPWM1, 0) ;
    }

#endif /*NUCODEGEN_BPWM1_CH0_INT_SEL*/

#if (NUCODEGEN_BPWM1_CH0_CAP_INT_SEL == 1)

    /*Get rising latch capture interrupt and clear flag*/
    if( BPWM_GetCaptureIntFlag(BPWM1, 0) & 1)
    {
        BPWM_ClearCaptureIntFlag(BPWM1, 0, BPWM_CAPTURE_INT_RISING_LATCH) ;
    }

#elif (NUCODEGEN_BPWM1_CH0_CAP_INT_SEL == 2)

    /*Get falling latch capture interrupt and clear flag*/
    if( BPWM_GetCaptureIntFlag(BPWM1, 0) & 2)
    {
        BPWM_ClearCaptureIntFlag(BPWM1, 0, BPWM_CAPTURE_INT_FALLING_LATCH) ;
    }

#elif (NUCODEGEN_BPWM1_CH0_CAP_INT_SEL == 3)

    /*Get rising and fallinglatch capture interrupt and clear flag*/
    if( BPWM_GetCaptureIntFlag(BPWM1, 0) & 3)
    {
        BPWM_ClearCaptureIntFlag(BPWM1, 0, BPWM_CAPTURE_INT_RISING_LATCH|BPWM_CAPTURE_INT_FALLING_LATCH) ;
    }

#endif /*NUCODEGEN_BPWM1_CH0_CAP_INT_SEL*/

#if ( ((NUCODEGEN_BPWM1_CH1_INT_SEL) & 4) || ((NUCODEGEN_BPWM1_CH1_INT_SEL) & 8) )

    /*Get duty interrupt and clear flag*/
    if( BPWM_GetDutyIntFlag(BPWM1, 1) )
    {
        BPWM_ClearDutyIntFlag(BPWM1, 1) ;
    }

#endif /*NUCODEGEN_BPWM1_CH1_INT_SEL*/

#if (NUCODEGEN_BPWM1_CH1_CAP_INT_SEL == 1)

    /*Get rising latch capture interrupt and clear flag*/
    if( BPWM_GetCaptureIntFlag(BPWM1, 1) & 1)
    {
        BPWM_ClearCaptureIntFlag(BPWM1, 1, BPWM_CAPTURE_INT_RISING_LATCH) ;
    }

#elif (NUCODEGEN_BPWM1_CH1_CAP_INT_SEL == 2)

    /*Get falling latch capture interrupt and clear flag*/
    if( BPWM_GetCaptureIntFlag(BPWM1, 1) & 2)
    {
        BPWM_ClearCaptureIntFlag(BPWM1, 1, BPWM_CAPTURE_INT_FALLING_LATCH) ;
    }

#elif (NUCODEGEN_BPWM1_CH1_CAP_INT_SEL == 3)

    /*Get rising and fallinglatch capture interrupt and clear flag*/
    if( BPWM_GetCaptureIntFlag(BPWM1, 1) & 3)
    {
        BPWM_ClearCaptureIntFlag(BPWM1, 1, BPWM_CAPTURE_INT_RISING_LATCH|BPWM_CAPTURE_INT_FALLING_LATCH) ;
    }

#endif /*NUCODEGEN_BPWM1_CH1_CAP_INT_SEL*/

#if ( ((NUCODEGEN_BPWM1_CH2_INT_SEL) & 4) || ((NUCODEGEN_BPWM1_CH2_INT_SEL) & 8) )

    /*Get duty interrupt and clear flag*/
    if( BPWM_GetDutyIntFlag(BPWM1, 2) )
    {
        BPWM_ClearDutyIntFlag(BPWM1, 2) ;
    }

#endif /*NUCODEGEN_BPWM1_CH2_INT_SEL*/

#if (NUCODEGEN_BPWM1_CH2_CAP_INT_SEL == 1)

    /*Get rising latch capture interrupt and clear flag*/
    if( BPWM_GetCaptureIntFlag(BPWM1, 2) & 1)
    {
        BPWM_ClearCaptureIntFlag(BPWM1, 2, BPWM_CAPTURE_INT_RISING_LATCH) ;
    }

#elif (NUCODEGEN_BPWM1_CH2_CAP_INT_SEL == 2)

    /*Get falling latch capture interrupt and clear flag*/
    if( BPWM_GetCaptureIntFlag(BPWM1, 2) & 2)
    {
        BPWM_ClearCaptureIntFlag(BPWM1, 2, BPWM_CAPTURE_INT_FALLING_LATCH) ;
    }

#elif (NUCODEGEN_BPWM1_CH2_CAP_INT_SEL == 3)

    /*Get rising and fallinglatch capture interrupt and clear flag*/
    if( BPWM_GetCaptureIntFlag(BPWM1, 2) & 3)
    {
        BPWM_ClearCaptureIntFlag(BPWM1, 2, BPWM_CAPTURE_INT_RISING_LATCH|BPWM_CAPTURE_INT_FALLING_LATCH) ;
    }

#endif /*NUCODEGEN_BPWM1_CH2_CAP_INT_SEL*/

#if ( ((NUCODEGEN_BPWM1_CH3_INT_SEL) & 4) || ((NUCODEGEN_BPWM1_CH3_INT_SEL) & 8) )

    /*Get duty interrupt and clear flag*/
    if( BPWM_GetDutyIntFlag(BPWM1, 3) )
    {
        BPWM_ClearDutyIntFlag(BPWM1, 3) ;
    }

#endif /*NUCODEGEN_BPWM1_CH3_INT_SEL*/

#if (NUCODEGEN_BPWM1_CH3_CAP_INT_SEL == 1)

    /*Get rising latch capture interrupt and clear flag*/
    if( BPWM_GetCaptureIntFlag(BPWM1, 3) & 1)
    {
        BPWM_ClearCaptureIntFlag(BPWM1, 3, BPWM_CAPTURE_INT_RISING_LATCH) ;
    }

#elif (NUCODEGEN_BPWM1_CH3_CAP_INT_SEL == 2)

    /*Get falling latch capture interrupt and clear flag*/
    if( BPWM_GetCaptureIntFlag(BPWM1, 3) & 2)
    {
        BPWM_ClearCaptureIntFlag(BPWM1, 3, BPWM_CAPTURE_INT_FALLING_LATCH) ;
    }

#elif (NUCODEGEN_BPWM1_CH3_CAP_INT_SEL == 3)

    /*Get rising and fallinglatch capture interrupt and clear flag*/
    if( BPWM_GetCaptureIntFlag(BPWM1, 3) & 3)
    {
        BPWM_ClearCaptureIntFlag(BPWM1, 3, BPWM_CAPTURE_INT_RISING_LATCH|BPWM_CAPTURE_INT_FALLING_LATCH) ;
    }

#endif /*NUCODEGEN_BPWM1_CH3_CAP_INT_SEL*/

#if ( ((NUCODEGEN_BPWM1_CH4_INT_SEL) & 4) || ((NUCODEGEN_BPWM1_CH4_INT_SEL) & 8) )

    /*Get duty interrupt and clear flag*/
    if( BPWM_GetDutyIntFlag(BPWM1, 4) )
    {
        BPWM_ClearDutyIntFlag(BPWM1, 4) ;
    }

#endif /*NUCODEGEN_BPWM1_CH4_INT_SEL*/

#if (NUCODEGEN_BPWM1_CH4_CAP_INT_SEL == 1)

    /*Get rising latch capture interrupt and clear flag*/
    if( BPWM_GetCaptureIntFlag(BPWM1, 4) & 1)
    {
        BPWM_ClearCaptureIntFlag(BPWM1, 4, BPWM_CAPTURE_INT_RISING_LATCH) ;
    }

#elif (NUCODEGEN_BPWM1_CH4_CAP_INT_SEL == 2)

    /*Get falling latch capture interrupt and clear flag*/
    if( BPWM_GetCaptureIntFlag(BPWM1, 4) & 2)
    {
        BPWM_ClearCaptureIntFlag(BPWM1, 4, BPWM_CAPTURE_INT_FALLING_LATCH) ;
    }

#elif (NUCODEGEN_BPWM1_CH4_CAP_INT_SEL == 3)

    /*Get rising and fallinglatch capture interrupt and clear flag*/
    if( BPWM_GetCaptureIntFlag(BPWM1, 4) & 3)
    {
        BPWM_ClearCaptureIntFlag(BPWM1, 4, BPWM_CAPTURE_INT_RISING_LATCH|BPWM_CAPTURE_INT_FALLING_LATCH) ;
    }

#endif /*NUCODEGEN_BPWM1_CH4_CAP_INT_SEL*/

#if ( ((NUCODEGEN_BPWM1_CH5_INT_SEL) & 4) || ((NUCODEGEN_BPWM1_CH5_INT_SEL) & 8) )

    /*Get duty interrupt and clear flag*/
    if( BPWM_GetDutyIntFlag(BPWM1, 5) )
    {
        BPWM_ClearDutyIntFlag(BPWM1, 5) ;
    }

#endif /*NUCODEGEN_BPWM1_CH5_INT_SEL*/

#if (NUCODEGEN_BPWM1_CH5_CAP_INT_SEL == 1)

    /*Get rising latch capture interrupt and clear flag*/
    if( BPWM_GetCaptureIntFlag(BPWM1, 5) & 1)
    {
        BPWM_ClearCaptureIntFlag(BPWM1, 5, BPWM_CAPTURE_INT_RISING_LATCH) ;
    }

#elif (NUCODEGEN_BPWM1_CH5_CAP_INT_SEL == 2)

    /*Get falling latch capture interrupt and clear flag*/
    if( BPWM_GetCaptureIntFlag(BPWM1, 5) & 2)
    {
        BPWM_ClearCaptureIntFlag(BPWM1, 5, BPWM_CAPTURE_INT_FALLING_LATCH) ;
    }

#elif (NUCODEGEN_BPWM1_CH5_CAP_INT_SEL == 3)

    /*Get rising and fallinglatch capture interrupt and clear flag*/
    if( BPWM_GetCaptureIntFlag(BPWM1, 5) & 3)
    {
        BPWM_ClearCaptureIntFlag(BPWM1, 5, BPWM_CAPTURE_INT_RISING_LATCH|BPWM_CAPTURE_INT_FALLING_LATCH) ;
    }

#endif /*NUCODEGEN_BPWM1_CH5_CAP_INT_SEL*/
}

#endif //NUCODEGEN_BPWM1
