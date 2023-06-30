/******************************************************************************//**
 * @file     int_handler.c
 * @version  V1.01
 * @brief    M251 interrupt handler file
 *
 * @copyright (C) 2018 Nuvoton Technology Corp. All rights reserved.
 ******************************************************************************/

/*!<Includes */
#include "NuCodeGenProj.h"

#if (NUCODEGEN_CLK)
#if (NUCODEGEN_CLK_CLKFAIL_INT_ENABLE)
void CLKFAIL_IRQHandler(void)
{
    uint32_t u32Reg;

    /* Unlock protected registers */
    SYS_UnlockReg();

    u32Reg = CLK->CLKDSTS;

#if (NUCODEGEN_CLK_HXT_FAIL_DET_ENABLE)
    if (u32Reg & CLK_CLKDSTS_HXTFIF_Msk)
    {
        /* HCLK is switched to MIRC automatically if HXT clock fail interrupt is happened */
        printf("HXT Clock is stopped! HCLK is switched to MIRC.\n");

        /* Disable HXT clock fail interrupt */
        CLK->CLKDCTL &= ~(CLK_CLKDCTL_HXTFDEN_Msk | CLK_CLKDCTL_HXTFIEN_Msk);

        /* Write 1 to clear HXT Clock fail interrupt flag */
        CLK->CLKDSTS = CLK_CLKDSTS_HXTFIF_Msk;
    }
#endif /* NUCODEGEN_CLK_HXT_FAIL_DET_ENABLE */

#if (NUCODEGEN_CLK_LXT_FAIL_DET_ENABLE)
    if (u32Reg & CLK_CLKDSTS_LXTFIF_Msk)
    {
        /* LXT clock fail interrupt is happened */
        printf("LXT Clock is stopped!\n");

        /* Disable HXT clock fail interrupt */
        CLK->CLKDCTL &= ~(CLK_CLKDCTL_LXTFIEN_Msk | CLK_CLKDCTL_LXTFDEN_Msk);

        /* Write 1 to clear LXT Clock fail interrupt flag */
        CLK->CLKDSTS = CLK_CLKDSTS_LXTFIF_Msk;
    }
#endif /* NUCODEGEN_CLK_LXT_FAIL_DET_ENABLE */

#if (NUCODEGEN_CLK_HXT_FREQ_DET_ENABLE)
    if (u32Reg & CLK_CLKDSTS_HXTFQIF_Msk)
    {
        /* HCLK should be switched to MIRC if HXT clock frequency monitor interrupt is happened */
        CLK_SetHCLK(CLK_CLKSEL0_HCLKSEL_MIRC, CLK_CLKDIV0_HCLK(1));
        printf("HXT Frequency is abnormal! HCLK is switched to MIRC.\n");

        /* Disable HXT clock frequency monitor interrupt */
        CLK->CLKDCTL &= ~(CLK_CLKDCTL_HXTFQDEN_Msk | CLK_CLKDCTL_HXTFQIEN_Msk);

        /* Write 1 to clear HXT Clock frequency monitor interrupt */
        CLK->CLKDSTS = CLK_CLKDSTS_HXTFQIF_Msk;
    }
#endif /* NUCODEGEN_CLK_HXT_FREQ_DET_ENABLE */

    /* Lock protected registers */
    SYS_LockReg();
}
#endif /* NUCODEGEN_CLK_CLKFAIL_INT_ENABLE */
#endif /* NUCODEGEN_CLK */


#if (NUCODEGEN_CLK)
#if (NUCODEGEN_CLK_PDWK_INT_ENABLE)
void PWRWU_IRQHandler(void)
{
    /* Check system power down mode wake-up interrupt status flag */
    if (CLK->PWRCTL & CLK_PWRCTL_PDWKIF_Msk)
    {
        /* Clear system power down wake-up interrupt flag */
        CLK->PWRCTL |= CLK_PWRCTL_PDWKIF_Msk;

        printf("System wake-up from Power-down mode.\n");
    }
}
#endif /* NUCODEGEN_CLK_PDWK_INT_ENABLE */
#endif /* NUCODEGEN_CLK */


#if (NUCODEGEN_SYS)
#if (NUCODEGEN_SYS_BOD_INT_ENABLE)
void BOD_IRQHandler(void)
{
    /* Get BOD interrupt flag */
    if (SYS_GET_BOD_INT_FLAG())
    {
        /* Clear BOD interrupt flag */
        SYS_CLEAR_BOD_INT_FLAG();
    }
}
#endif /* NUCODEGEN_SYS_BOD_INT_ENABLE */
#endif /* NUCODEGEN_SYS */


#if (NUCODEGEN_SYS)
#if (NUCODEGEN_SYS_HIRCTRIM_INT_EN || NUCODEGEN_SYS_MIRCTRIM_INT_EN)
void IRCTRIM_IRQHandler(void)
{
#if (NUCODEGEN_SYS_HIRCTRIM_INT_EN)
    if (SYS->HIRCTRIMSTS & SYS_HIRCTRIMSTS_TFAILIF_Msk)   /* Get Trim Failure Interrupt */
    {
        /* Display HIRC trim status */
        printf("HIRC Trim Failure Interrupt\n");
        /* Clear Trim Failure Interrupt */
        SYS->HIRCTRIMSTS = SYS_HIRCTRIMSTS_TFAILIF_Msk;
    }

    if (SYS->HIRCTRIMSTS & SYS_HIRCTRIMSTS_CLKERIF_Msk)   /* Get LXT Clock Error Interrupt */
    {
        /* Display HIRC trim status */
        printf("LXT Clock Error Interrupt\n");
        /* Clear LXT Clock Error Interrupt */
        SYS->HIRCTRIMSTS = SYS_HIRCTRIMSTS_CLKERIF_Msk;
    }
#endif

#if (NUCODEGEN_SYS_MIRCTRIM_INT_EN)
    if (SYS->MIRCTRIMSTS & SYS_MIRCTRIMSTS_TFAILIF_Msk)   /* Get Trim Failure Interrupt */
    {
        /* Display MIRC trim status */
        printf("MIRC Trim Failure Interrupt\n");
        /* Clear Trim Failure Interrupt */
        SYS->MIRCTRIMSTS = SYS_MIRCTRIMSTS_TFAILIF_Msk;
    }

    if (SYS->MIRCTRIMSTS & SYS_MIRCTRIMSTS_CLKERIF_Msk)   /* Get LXT Clock Error Interrupt */
    {
        /* Display MIRC trim status */
        printf("LXT Clock Error Interrupt\n");
        /* Clear LXT Clock Error Interrupt */
        SYS->MIRCTRIMSTS = SYS_MIRCTRIMSTS_CLKERIF_Msk;
    }
#endif
}
#endif /* NUCODEGEN_SYS_HIRCTRIM_INT_EN || NUCODEGEN_SYS_MIRCTRIM_INT_EN */
#endif /* NUCODEGEN_SYS */

#if (NUCODEGEN_AES_INT || NUCODEGEN_PRNG_INT)
#if NUCODEGEN_PRNG_INT
volatile int8_t  g_PRNG_i8done;
#endif
#if NUCODEGEN_AES_INT
volatile int8_t  g_AES_i8Done;
#endif

void CRPT_IRQHandler()
{
        #if NUCODEGEN_PRNG_INT
    if (PRNG_GET_INT_FLAG(CRPT))
    {
        g_PRNG_i8done = 1;
        PRNG_CLR_INT_FLAG(CRPT);
    }
        #endif

        #if NUCODEGEN_AES_INT
    if (AES_GET_INT_FLAG(CRPT))
    {
        g_AES_i8Done = 1;
        AES_CLR_INT_FLAG(CRPT);
    }
        #endif
}
#endif

#if (NUCODEGEN_TIMER0_INT || NUCODEGEN_TIMER0_CAP_INT || NUCODEGEN_TPWM0_PERIOD_INT || NUCODEGEN_TPWM0_CMP_UP_INT)
void TMR0_IRQHandler(void)
{
#if NUCODEGEN_TIMER0_CAP_INT
        if (TIMER_GetCaptureIntFlag(TIMER0))
        {       /* Clear Timer0 capture trigger interrupt flag */
                TIMER_ClearCaptureIntFlag(TIMER0);
        }
#endif
#if NUCODEGEN_TIMER0_INT
        if (TIMER_GetIntFlag(TIMER0))
        {       /* Clear Timer0 time-out interrupt flag */
                TIMER_ClearIntFlag(TIMER0);
        }
#endif
#if NUCODEGEN_TIMER0_WAKEUP
        if (TIMER_GetWakeupFlag(TIMER0))
        {       /* Clear Timer0 wake-up flag */
                TIMER_ClearWakeupFlag(TIMER0);
        }
#endif
#if NUCODEGEN_TPWM0_PERIOD_INT
        if (TPWM_GET_PERIOD_INT_FLAG(TIMER0))
        {       /* Clear TPWM0 period interrupt flag */
                TPWM_CLEAR_PERIOD_INT_FLAG(TIMER0);
        }
#endif
#if NUCODEGEN_TPWM0_CMP_UP_INT
        if (TPWM_GET_CMP_UP_INT_FLAG(TIMER0))
        {       /* Clear TPWM0 compare up interrupt flag */
                TPWM_CLEAR_CMP_UP_INT_FLAG(TIMER0);
        }
#endif
#if NUCODEGEN_TPWM0_WAKEUP
        if (TPWM_GetWakeupFlag(TIMER0))
        {       /* Clear TPWM0 wake-up flag */
                TPWM_ClearWakeupFlag(TIMER0);
        }
#endif
}
#endif //NUCODEGEN_TIMER0_INT || NUCODEGEN_TIMER0_CAP_INT || NUCODEGEN_TPWM0_PERIOD_INT || NUCODEGEN_TPWM0_CMP_UP_INT

#if (NUCODEGEN_TIMER1_INT || NUCODEGEN_TIMER1_CAP_INT || NUCODEGEN_TPWM1_PERIOD_INT || NUCODEGEN_TPWM1_CMP_UP_INT)
void TMR1_IRQHandler(void)
{
#if NUCODEGEN_TIMER1_CAP_INT
        if (TIMER_GetCaptureIntFlag(TIMER1))
        {       /* Clear TIMER1 capture trigger interrupt flag */
                TIMER_ClearCaptureIntFlag(TIMER1);
        }
#endif
#if NUCODEGEN_TIMER1_INT
        if (TIMER_GetIntFlag(TIMER1))
        {       /* Clear TIMER1 time-out interrupt flag */
                TIMER_ClearIntFlag(TIMER1);
        }
#endif
#if NUCODEGEN_TIMER1_WAKEUP
        if (TIMER_GetWakeupFlag(TIMER1))
        {       /* Clear TIMER1 wake-up flag */
                TIMER_ClearWakeupFlag(TIMER1);
        }
#endif
#if NUCODEGEN_TPWM1_PERIOD_INT
        if (TPWM_GET_PERIOD_INT_FLAG(TIMER1))
        {       /* Clear TPWM1 period interrupt flag */
                TPWM_CLEAR_PERIOD_INT_FLAG(TIMER1);
        }
#endif
#if NUCODEGEN_TPWM1_CMP_UP_INT
        if (TPWM_GET_CMP_UP_INT_FLAG(TIMER1))
        {       /* Clear TPWM1 compare up interrupt flag */
                TPWM_CLEAR_CMP_UP_INT_FLAG(TIMER1);
        }
#endif
#if NUCODEGEN_TPWM1_WAKEUP
        if (TPWM_GetWakeupFlag(TIMER1))
        {       /* Clear TPWM1 wake-up flag */
                TPWM_ClearWakeupFlag(TIMER1);
        }
#endif
}
#endif //NUCODEGEN_TIMER1_INT || NUCODEGEN_TIMER1_CAP_INT || NUCODEGEN_TPWM1_PERIOD_INT || NUCODEGEN_TPWM1_CMP_UP_INT

#if (NUCODEGEN_TIMER2_INT || NUCODEGEN_TIMER2_CAP_INT || NUCODEGEN_TPWM2_PERIOD_INT || NUCODEGEN_TPWM2_CMP_UP_INT)
void TMR2_IRQHandler(void)
{
#if NUCODEGEN_TIMER2_CAP_INT
        if (TIMER_GetCaptureIntFlag(TIMER2))
        {       /* Clear TIMER2 capture trigger interrupt flag */
                TIMER_ClearCaptureIntFlag(TIMER2);
        }
#endif
#if NUCODEGEN_TIMER2_INT
        if (TIMER_GetIntFlag(TIMER2))
        {       /* Clear TIMER2 time-out interrupt flag */
                TIMER_ClearIntFlag(TIMER2);
        }
#endif
#if NUCODEGEN_TIMER2_WAKEUP
        if (TIMER_GetWakeupFlag(TIMER2))
        {       /* Clear TIMER2 wake-up flag */
                TIMER_ClearWakeupFlag(TIMER2);
        }
#endif
#if NUCODEGEN_TPWM2_PERIOD_INT
        if (TPWM_GET_PERIOD_INT_FLAG(TIMER2))
        {       /* Clear TPWM2 period interrupt flag */
                TPWM_CLEAR_PERIOD_INT_FLAG(TIMER2);
        }
#endif
#if NUCODEGEN_TPWM2_CMP_UP_INT
        if (TPWM_GET_CMP_UP_INT_FLAG(TIMER2))
        {       /* Clear TPWM2 compare up interrupt flag */
                TPWM_CLEAR_CMP_UP_INT_FLAG(TIMER2);
        }
#endif
#if NUCODEGEN_TPWM2_WAKEUP
        if (TPWM_GetWakeupFlag(TIMER2))
        {       /* Clear TPWM2 wake-up flag */
                TPWM_ClearWakeupFlag(TIMER2);
        }
#endif
}
#endif //NUCODEGEN_TIMER2_INT || NUCODEGEN_TIMER2_CAP_INT || NUCODEGEN_TPWM2_PERIOD_INT || NUCODEGEN_TPWM2_CMP_UP_INT

#if (NUCODEGEN_TIMER3_INT || NUCODEGEN_TIMER3_CAP_INT || NUCODEGEN_TPWM3_PERIOD_INT || NUCODEGEN_TPWM3_CMP_UP_INT)
void TMR3_IRQHandler(void)
{
#if NUCODEGEN_TIMER3_CAP_INT
        if (TIMER_GetCaptureIntFlag(TIMER3))
        {       /* Clear TIMER3 capture trigger interrupt flag */
                TIMER_ClearCaptureIntFlag(TIMER3);
        }
#endif
#if NUCODEGEN_TIMER3_INT
        if (TIMER_GetIntFlag(TIMER3))
        {       /* Clear TIMER3 time-out interrupt flag */
                TIMER_ClearIntFlag(TIMER3);
        }
#endif
#if NUCODEGEN_TIMER3_WAKEUP
        if (TIMER_GetWakeupFlag(TIMER3))
        {       /* Clear TIMER3 wake-up flag */
                TIMER_ClearWakeupFlag(TIMER3);
        }
#endif
#if NUCODEGEN_TPWM3_PERIOD_INT
        if (TPWM_GET_PERIOD_INT_FLAG(TIMER3))
        {       /* Clear TPWM3 period interrupt flag */
                TPWM_CLEAR_PERIOD_INT_FLAG(TIMER3);
        }
#endif
#if NUCODEGEN_TPWM3_CMP_UP_INT
        if (TPWM_GET_CMP_UP_INT_FLAG(TIMER3))
        {       /* Clear TPWM3 compare up interrupt flag */
                TPWM_CLEAR_CMP_UP_INT_FLAG(TIMER3);
        }
#endif
#if NUCODEGEN_TPWM3_WAKEUP
        if (TPWM_GetWakeupFlag(TIMER3))
        {       /* Clear TPWM3 wake-up flag */
                TPWM_ClearWakeupFlag(TIMER3);
        }
#endif
}
#endif //NUCODEGEN_TIMER3_INT || NUCODEGEN_TIMER3_CAP_INT || NUCODEGEN_TPWM3_PERIOD_INT || NUCODEGEN_TPWM3_CMP_UP_INT

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

#if NUCODEGEN_PWM0

#if NUCODEGEN_PWM0_CH0CH1

void PWM0_P0_IRQHandler(void)
{

#if (((NUCODEGEN_PWM0_CH0_INT_SEL) & 1) || ((NUCODEGEN_PWM0_CH1_INT_SEL) & 1))

    /* Get zero interrupt and clear flag - PWM two channals has one controller */
    if( PWM_GetZeroIntFlag(PWM0, 0) )
    {
        PWM_ClearZeroIntFlag(PWM0, 0) ;
    }

#endif /*NUCODEGEN_PWM0_CH0_INT_SEL*/

#if (((NUCODEGEN_PWM0_CH0_INT_SEL) & 2) || ((NUCODEGEN_PWM0_CH1_INT_SEL) & 2) )

    /* Get period interrupt and clear flag - PWM two channals has one controller */
    if( PWM_GetPeriodIntFlag(PWM0, 0) )
    {
        PWM_ClearPeriodIntFlag(PWM0, 0) ;
    }

#endif /*NUCODEGEN_PWM0_CH0_INT_SEL*/

#if ( ((NUCODEGEN_PWM0_CH0_INT_SEL) & 4) || ((NUCODEGEN_PWM0_CH0_INT_SEL) & 8) )

    /*Get duty interrupt and clear flag*/
    if( PWM_GetDutyIntFlag(PWM0, 0) )
    {
        PWM_ClearDutyIntFlag(PWM0, 0) ;
    }

#endif /*NUCODEGEN_PWM0_CH0_INT_SEL*/

#if (NUCODEGEN_PWM0_CH0_CAP_INT_SEL == 1)

    /*Get rising latch capture interrupt and clear flag*/
    if( PWM_GetCaptureIntFlag(PWM0, 0) & 1)
    {
        PWM_ClearCaptureIntFlag(PWM0, 0, PWM_CAPTURE_INT_RISING_LATCH) ;
    }

#elif (NUCODEGEN_PWM0_CH0_CAP_INT_SEL == 2)

    /*Get falling latch capture interrupt and clear flag*/
    if( PWM_GetCaptureIntFlag(PWM0, 0) & 2)
    {
        PWM_ClearCaptureIntFlag(PWM0, 0, PWM_CAPTURE_INT_FALLING_LATCH) ;
    }

#elif (NUCODEGEN_PWM0_CH0_CAP_INT_SEL == 3)

    /*Get rising and fallinglatch capture interrupt and clear flag*/
    if( PWM_GetCaptureIntFlag(PWM0, 0) & 3)
    {
        PWM_ClearCaptureIntFlag(PWM0, 0, PWM_CAPTURE_INT_RISING_LATCH|PWM_CAPTURE_INT_FALLING_LATCH) ;
    }

#endif /*NUCODEGEN_PWM0_CH0_CAP_INT_SEL*/

#if ( ((NUCODEGEN_PWM0_CH1_INT_SEL) & 4) || ((NUCODEGEN_PWM0_CH1_INT_SEL) & 8) )

    /*Get duty interrupt and clear flag*/
    if( PWM_GetDutyIntFlag(PWM0, 1) )
    {
        PWM_ClearDutyIntFlag(PWM0, 1) ;
    }

#endif /*NUCODEGEN_PWM0_CH1_INT_SEL*/

#if (NUCODEGEN_PWM0_CH1_CAP_INT_SEL == 1)

    /*Get rising latch capture interrupt and clear flag*/
    if( PWM_GetCaptureIntFlag(PWM0, 1) & 1)
    {
        PWM_ClearCaptureIntFlag(PWM0, 1, PWM_CAPTURE_INT_RISING_LATCH) ;
    }

#elif (NUCODEGEN_PWM0_CH1_CAP_INT_SEL == 2)

    /*Get falling latch capture interrupt and clear flag*/
    if( PWM_GetCaptureIntFlag(PWM0, 1) & 2)
    {
        PWM_ClearCaptureIntFlag(PWM0, 1, PWM_CAPTURE_INT_FALLING_LATCH) ;
    }

#elif (NUCODEGEN_PWM0_CH1_CAP_INT_SEL == 3)

    /*Get rising and fallinglatch capture interrupt and clear flag*/
    if( PWM_GetCaptureIntFlag(PWM0, 1) & 3)
    {
        PWM_ClearCaptureIntFlag(PWM0, 1, PWM_CAPTURE_INT_RISING_LATCH|PWM_CAPTURE_INT_FALLING_LATCH) ;
    }

#endif /*NUCODEGEN_PWM0_CH1_CAP_INT_SEL*/

}

#endif /*NUCODEGEN_PWM0_CH0CH1*/

#if NUCODEGEN_PWM0_CH2CH3

void PWM0_P1_IRQHandler(void)
{

#if (((NUCODEGEN_PWM0_CH2_INT_SEL) & 1) || ((NUCODEGEN_PWM0_CH3_INT_SEL) & 1))

    /* Get zero interrupt and clear flag - PWM two channals has one controller */
    if( PWM_GetZeroIntFlag(PWM0, 2) )
    {
        PWM_ClearZeroIntFlag(PWM0, 2) ;
    }

#endif /*NUCODEGEN_PWM0_CH2_INT_SEL*/

#if (((NUCODEGEN_PWM0_CH2_INT_SEL) & 2) || ((NUCODEGEN_PWM0_CH3_INT_SEL) & 2) )

    /* Get period interrupt and clear flag - PWM two channals has one controller */
    if( PWM_GetPeriodIntFlag(PWM0, 2) )
    {
        PWM_ClearPeriodIntFlag(PWM0, 2) ;
    }

#endif /*NUCODEGEN_PWM0_CH2_INT_SEL*/

#if ( ((NUCODEGEN_PWM0_CH2_INT_SEL) & 4) || ((NUCODEGEN_PWM0_CH2_INT_SEL) & 8) )

    /*Get duty interrupt and clear flag*/
    if( PWM_GetDutyIntFlag(PWM0, 2) )
    {
        PWM_ClearDutyIntFlag(PWM0, 2) ;
    }

#endif /*NUCODEGEN_PWM0_CH2_INT_SEL*/

#if (NUCODEGEN_PWM0_CH2_CAP_INT_SEL == 1)

    /*Get rising latch capture interrupt and clear flag*/
    if( PWM_GetCaptureIntFlag(PWM0, 2) & 1)
    {
        PWM_ClearCaptureIntFlag(PWM0, 2, PWM_CAPTURE_INT_RISING_LATCH) ;
    }

#elif (NUCODEGEN_PWM0_CH2_CAP_INT_SEL == 2)

    /*Get falling latch capture interrupt and clear flag*/
    if( PWM_GetCaptureIntFlag(PWM0, 2) & 2)
    {
        PWM_ClearCaptureIntFlag(PWM0, 2, PWM_CAPTURE_INT_FALLING_LATCH) ;
    }

#elif (NUCODEGEN_PWM0_CH2_CAP_INT_SEL == 3)

    /*Get rising and fallinglatch capture interrupt and clear flag*/
    if( PWM_GetCaptureIntFlag(PWM0, 2) & 3)
    {
        PWM_ClearCaptureIntFlag(PWM0, 2, PWM_CAPTURE_INT_RISING_LATCH|PWM_CAPTURE_INT_FALLING_LATCH) ;
    }

#endif /*NUCODEGEN_PWM0_CH2_CAP_INT_SEL*/

#if ( ((NUCODEGEN_PWM0_CH3_INT_SEL) & 4) || ((NUCODEGEN_PWM0_CH3_INT_SEL) & 8) )

    /*Get duty interrupt and clear flag*/
    if( PWM_GetDutyIntFlag(PWM0, 3) )
    {
        PWM_ClearDutyIntFlag(PWM0, 3) ;
    }

#endif /*NUCODEGEN_PWM0_CH3_INT_SEL*/

#if (NUCODEGEN_PWM0_CH3_CAP_INT_SEL == 1)

    /*Get rising latch capture interrupt and clear flag*/
    if( PWM_GetCaptureIntFlag(PWM0, 3) & 1)
    {
        PWM_ClearCaptureIntFlag(PWM0, 3, PWM_CAPTURE_INT_RISING_LATCH) ;
    }

#elif (NUCODEGEN_PWM0_CH3_CAP_INT_SEL == 2)

    /*Get falling latch capture interrupt and clear flag*/
    if( PWM_GetCaptureIntFlag(PWM0, 3) & 2)
    {
        PWM_ClearCaptureIntFlag(PWM0, 3, PWM_CAPTURE_INT_FALLING_LATCH) ;
    }

#elif (NUCODEGEN_PWM0_CH3_CAP_INT_SEL == 3)

    /*Get rising and fallinglatch capture interrupt and clear flag*/
    if( PWM_GetCaptureIntFlag(PWM0, 3) & 3)
    {
        PWM_ClearCaptureIntFlag(PWM0, 3, PWM_CAPTURE_INT_RISING_LATCH|PWM_CAPTURE_INT_FALLING_LATCH) ;
    }

#endif /*NUCODEGEN_PWM0_CH3_CAP_INT_SEL*/

}

#endif /*NUCODEGEN_PWM0_CH0CH1*/

#if NUCODEGEN_PWM0_CH4CH5

void PWM0_P2_IRQHandler(void)
{

#if (((NUCODEGEN_PWM0_CH4_INT_SEL) & 1) || ((NUCODEGEN_PWM0_CH5_INT_SEL) & 1))

    /* Get zero interrupt and clear flag - PWM two channals has one controller */
    if( PWM_GetZeroIntFlag(PWM0, 4) )
    {
        PWM_ClearZeroIntFlag(PWM0, 4) ;
    }

#endif /*NUCODEGEN_PWM0_CH4_INT_SEL*/

#if (((NUCODEGEN_PWM0_CH4_INT_SEL) & 2) || ((NUCODEGEN_PWM0_CH5_INT_SEL) & 2) )

    /* Get period interrupt and clear flag - PWM two channals has one controller */
    if( PWM_GetPeriodIntFlag(PWM0, 4) )
    {
        PWM_ClearPeriodIntFlag(PWM0, 4) ;
    }

#endif /*NUCODEGEN_PWM0_CH4_INT_SEL*/

#if ( ((NUCODEGEN_PWM0_CH4_INT_SEL) & 4) || ((NUCODEGEN_PWM0_CH4_INT_SEL) & 8) )

    /*Get duty interrupt and clear flag*/
    if( PWM_GetDutyIntFlag(PWM0, 4) )
    {
        PWM_ClearDutyIntFlag(PWM0, 4) ;
    }

#endif /*NUCODEGEN_PWM0_CH4_INT_SEL*/

#if (NUCODEGEN_PWM0_CH4_CAP_INT_SEL == 1)

    /*Get rising latch capture interrupt and clear flag*/
    if( PWM_GetCaptureIntFlag(PWM0, 4) & 1)
    {
        PWM_ClearCaptureIntFlag(PWM0, 4, PWM_CAPTURE_INT_RISING_LATCH) ;
    }

#elif (NUCODEGEN_PWM0_CH4_CAP_INT_SEL == 2)

    /*Get falling latch capture interrupt and clear flag*/
    if( PWM_GetCaptureIntFlag(PWM0, 4) & 2)
    {
        PWM_ClearCaptureIntFlag(PWM0, 4, PWM_CAPTURE_INT_FALLING_LATCH) ;
    }

#elif (NUCODEGEN_PWM0_CH4_CAP_INT_SEL == 3)

    /*Get rising and fallinglatch capture interrupt and clear flag*/
    if( PWM_GetCaptureIntFlag(PWM0, 4) & 3)
    {
        PWM_ClearCaptureIntFlag(PWM0, 4, PWM_CAPTURE_INT_RISING_LATCH|PWM_CAPTURE_INT_FALLING_LATCH) ;
    }

#endif /*NUCODEGEN_PWM0_CH4_CAP_INT_SEL*/

#if ( ((NUCODEGEN_PWM0_CH5_INT_SEL) & 4) || ((NUCODEGEN_PWM0_CH5_INT_SEL) & 8) )

    /*Get duty interrupt and clear flag*/
    if( PWM_GetDutyIntFlag(PWM0, 5) )
    {
        PWM_ClearDutyIntFlag(PWM0, 5) ;
    }

#endif /*NUCODEGEN_PWM0_CH5_INT_SEL*/

#if (NUCODEGEN_PWM0_CH5_CAP_INT_SEL == 1)

    /*Get rising latch capture interrupt and clear flag*/
    if( PWM_GetCaptureIntFlag(PWM0, 5) & 1)
    {
        PWM_ClearCaptureIntFlag(PWM0, 5, PWM_CAPTURE_INT_RISING_LATCH) ;
    }

#elif (NUCODEGEN_PWM0_CH5_CAP_INT_SEL == 2)

    /*Get falling latch capture interrupt and clear flag*/
    if( PWM_GetCaptureIntFlag(PWM0, 5) & 2)
    {
        PWM_ClearCaptureIntFlag(PWM0, 5, PWM_CAPTURE_INT_FALLING_LATCH) ;
    }

#elif (NUCODEGEN_PWM0_CH5_CAP_INT_SEL == 3)

    /*Get rising and fallinglatch capture interrupt and clear flag*/
    if( PWM_GetCaptureIntFlag(PWM0, 5) & 3)
    {
        PWM_ClearCaptureIntFlag(PWM0, 5, PWM_CAPTURE_INT_RISING_LATCH|PWM_CAPTURE_INT_FALLING_LATCH) ;
    }

#endif /*NUCODEGEN_PWM0_CH5_CAP_INT_SEL*/

}

#endif /*NUCODEGEN_PWM0_CH4CH5*/

#if (((NUCODEGEN_PWM0_CH0_INT_SEL) & 16)||((NUCODEGEN_PWM0_CH1_INT_SEL) & 16)||((NUCODEGEN_PWM0_CH2_INT_SEL) & 16)||((NUCODEGEN_PWM0_CH3_INT_SEL) & 16)||((NUCODEGEN_PWM0_CH4_INT_SEL) & 16)||((NUCODEGEN_PWM0_CH5_INT_SEL) & 16))

void BRAKE0_IRQHandler(void)
{

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

#endif

#endif //NUCODEGEN_PWM0

#if NUCODEGEN_PWM1

#if NUCODEGEN_PWM1_CH0CH1

void PWM1_P0_IRQHandler(void)
{

#if (((NUCODEGEN_PWM1_CH0_INT_SEL) & 1) || ((NUCODEGEN_PWM1_CH1_INT_SEL) & 1))

    /* Get zero interrupt and clear flag - PWM two channals has one controller */
    if( PWM_GetZeroIntFlag(PWM1, 0) )
    {
        PWM_ClearZeroIntFlag(PWM1, 0) ;
    }

#endif /*NUCODEGEN_PWM1_CH0_INT_SEL*/

#if (((NUCODEGEN_PWM1_CH0_INT_SEL) & 2) || ((NUCODEGEN_PWM1_CH1_INT_SEL) & 2) )

    /* Get period interrupt and clear flag - PWM two channals has one controller */
    if( PWM_GetPeriodIntFlag(PWM1, 0) )
    {
        PWM_ClearPeriodIntFlag(PWM1, 0) ;
    }

#endif /*NUCODEGEN_PWM1_CH0_INT_SEL*/

#if ( ((NUCODEGEN_PWM1_CH0_INT_SEL) & 4) || ((NUCODEGEN_PWM1_CH0_INT_SEL) & 8) )

    /*Get duty interrupt and clear flag*/
    if( PWM_GetDutyIntFlag(PWM1, 0) )
    {
        PWM_ClearDutyIntFlag(PWM1, 0) ;
    }

#endif /*NUCODEGEN_PWM1_CH0_INT_SEL*/

#if (NUCODEGEN_PWM1_CH0_CAP_INT_SEL == 1)

    /*Get rising latch capture interrupt and clear flag*/
    if( PWM_GetCaptureIntFlag(PWM1, 0) & 1)
    {
        PWM_ClearCaptureIntFlag(PWM1, 0, PWM_CAPTURE_INT_RISING_LATCH) ;
    }

#elif (NUCODEGEN_PWM1_CH0_CAP_INT_SEL == 2)

    /*Get falling latch capture interrupt and clear flag*/
    if( PWM_GetCaptureIntFlag(PWM1, 0) & 2)
    {
        PWM_ClearCaptureIntFlag(PWM1, 0, PWM_CAPTURE_INT_FALLING_LATCH) ;
    }

#elif (NUCODEGEN_PWM1_CH0_CAP_INT_SEL == 3)

    /*Get rising and fallinglatch capture interrupt and clear flag*/
    if( PWM_GetCaptureIntFlag(PWM1, 0) & 3)
    {
        PWM_ClearCaptureIntFlag(PWM1, 0, PWM_CAPTURE_INT_RISING_LATCH|PWM_CAPTURE_INT_FALLING_LATCH) ;
    }

#endif /*NUCODEGEN_PWM1_CH0_CAP_INT_SEL*/

#if ( ((NUCODEGEN_PWM1_CH1_INT_SEL) & 4) || ((NUCODEGEN_PWM1_CH1_INT_SEL) & 8) )

    /*Get duty interrupt and clear flag*/
    if( PWM_GetDutyIntFlag(PWM1, 1) )
    {
        PWM_ClearDutyIntFlag(PWM1, 1) ;
    }

#endif /*NUCODEGEN_PWM1_CH1_INT_SEL*/

#if (NUCODEGEN_PWM1_CH1_CAP_INT_SEL == 1)

    /*Get rising latch capture interrupt and clear flag*/
    if( PWM_GetCaptureIntFlag(PWM1, 1) & 1)
    {
        PWM_ClearCaptureIntFlag(PWM1, 1, PWM_CAPTURE_INT_RISING_LATCH) ;
    }

#elif (NUCODEGEN_PWM1_CH1_CAP_INT_SEL == 2)

    /*Get falling latch capture interrupt and clear flag*/
    if( PWM_GetCaptureIntFlag(PWM1, 1) & 2)
    {
        PWM_ClearCaptureIntFlag(PWM1, 1, PWM_CAPTURE_INT_FALLING_LATCH) ;
    }

#elif (NUCODEGEN_PWM1_CH1_CAP_INT_SEL == 3)

    /*Get rising and fallinglatch capture interrupt and clear flag*/
    if( PWM_GetCaptureIntFlag(PWM1, 1) & 3)
    {
        PWM_ClearCaptureIntFlag(PWM1, 1, PWM_CAPTURE_INT_RISING_LATCH|PWM_CAPTURE_INT_FALLING_LATCH) ;
    }

#endif /*NUCODEGEN_PWM1_CH1_CAP_INT_SEL*/

}

#endif /*NUCODEGEN_PWM1_CH0CH1*/

#if NUCODEGEN_PWM1_CH2CH3

void PWM1_P1_IRQHandler(void)
{

#if (((NUCODEGEN_PWM1_CH2_INT_SEL) & 1) || ((NUCODEGEN_PWM1_CH3_INT_SEL) & 1))

    /* Get zero interrupt and clear flag - PWM two channals has one controller */
    if( PWM_GetZeroIntFlag(PWM1, 2) )
    {
        PWM_ClearZeroIntFlag(PWM1, 2) ;
    }

#endif /*NUCODEGEN_PWM1_CH2_INT_SEL*/

#if (((NUCODEGEN_PWM1_CH2_INT_SEL) & 2) || ((NUCODEGEN_PWM1_CH3_INT_SEL) & 2) )

    /* Get period interrupt and clear flag - PWM two channals has one controller */
    if( PWM_GetPeriodIntFlag(PWM1, 2) )
    {
        PWM_ClearPeriodIntFlag(PWM1, 2) ;
    }

#endif /*NUCODEGEN_PWM1_CH2_INT_SEL*/

#if ( ((NUCODEGEN_PWM1_CH2_INT_SEL) & 4) || ((NUCODEGEN_PWM1_CH2_INT_SEL) & 8) )

    /*Get duty interrupt and clear flag*/
    if( PWM_GetDutyIntFlag(PWM1, 2) )
    {
        PWM_ClearDutyIntFlag(PWM1, 2) ;
    }

#endif /*NUCODEGEN_PWM1_CH2_INT_SEL*/

#if (NUCODEGEN_PWM1_CH2_CAP_INT_SEL == 1)

    /*Get rising latch capture interrupt and clear flag*/
    if( PWM_GetCaptureIntFlag(PWM1, 2) & 1)
    {
        PWM_ClearCaptureIntFlag(PWM1, 2, PWM_CAPTURE_INT_RISING_LATCH) ;
    }

#elif (NUCODEGEN_PWM1_CH2_CAP_INT_SEL == 2)

    /*Get falling latch capture interrupt and clear flag*/
    if( PWM_GetCaptureIntFlag(PWM1, 2) & 2)
    {
        PWM_ClearCaptureIntFlag(PWM1, 2, PWM_CAPTURE_INT_FALLING_LATCH) ;
    }

#elif (NUCODEGEN_PWM1_CH2_CAP_INT_SEL == 3)

    /*Get rising and fallinglatch capture interrupt and clear flag*/
    if( PWM_GetCaptureIntFlag(PWM1, 2) & 3)
    {
        PWM_ClearCaptureIntFlag(PWM1, 2, PWM_CAPTURE_INT_RISING_LATCH|PWM_CAPTURE_INT_FALLING_LATCH) ;
    }

#endif /*NUCODEGEN_PWM1_CH2_CAP_INT_SEL*/

#if ( ((NUCODEGEN_PWM1_CH3_INT_SEL) & 4) || ((NUCODEGEN_PWM1_CH3_INT_SEL) & 8) )

    /*Get duty interrupt and clear flag*/
    if( PWM_GetDutyIntFlag(PWM1, 3) )
    {
        PWM_ClearDutyIntFlag(PWM1, 3) ;
    }

#endif /*NUCODEGEN_PWM1_CH3_INT_SEL*/

#if (NUCODEGEN_PWM1_CH3_CAP_INT_SEL == 1)

    /*Get rising latch capture interrupt and clear flag*/
    if( PWM_GetCaptureIntFlag(PWM1, 3) & 1)
    {
        PWM_ClearCaptureIntFlag(PWM1, 3, PWM_CAPTURE_INT_RISING_LATCH) ;
    }

#elif (NUCODEGEN_PWM1_CH3_CAP_INT_SEL == 2)

    /*Get falling latch capture interrupt and clear flag*/
    if( PWM_GetCaptureIntFlag(PWM1, 3) & 2)
    {
        PWM_ClearCaptureIntFlag(PWM1, 3, PWM_CAPTURE_INT_FALLING_LATCH) ;
    }

#elif (NUCODEGEN_PWM1_CH3_CAP_INT_SEL == 3)

    /*Get rising and fallinglatch capture interrupt and clear flag*/
    if( PWM_GetCaptureIntFlag(PWM1, 3) & 3)
    {
        PWM_ClearCaptureIntFlag(PWM1, 3, PWM_CAPTURE_INT_RISING_LATCH|PWM_CAPTURE_INT_FALLING_LATCH) ;
    }

#endif /*NUCODEGEN_PWM1_CH3_CAP_INT_SEL*/

}

#endif /*NUCODEGEN_PWM1_CH2CH3*/

#if NUCODEGEN_PWM1_CH4CH5

void PWM1_P2_IRQHandler(void)
{

#if (((NUCODEGEN_PWM1_CH4_INT_SEL) & 1) || ((NUCODEGEN_PWM1_CH5_INT_SEL) & 1))

    /* Get zero interrupt and clear flag - PWM two channals has one controller */
    if( PWM_GetZeroIntFlag(PWM1, 4) )
    {
        PWM_ClearZeroIntFlag(PWM1, 4) ;
    }

#endif /*NUCODEGEN_PWM1_CH4_INT_SEL*/

#if (((NUCODEGEN_PWM1_CH4_INT_SEL) & 2) || ((NUCODEGEN_PWM1_CH5_INT_SEL) & 2) )

    /* Get period interrupt and clear flag - PWM two channals has one controller */
    if( PWM_GetPeriodIntFlag(PWM1, 4) )
    {
        PWM_ClearPeriodIntFlag(PWM1, 4) ;
    }

#endif /*NUCODEGEN_PWM1_CH4_INT_SEL*/

#if ( ((NUCODEGEN_PWM1_CH4_INT_SEL) & 4) || ((NUCODEGEN_PWM1_CH4_INT_SEL) & 8) )

    /*Get duty interrupt and clear flag*/
    if( PWM_GetDutyIntFlag(PWM1, 4) )
    {
        PWM_ClearDutyIntFlag(PWM1, 4) ;
    }

#endif /*NUCODEGEN_PWM1_CH4_INT_SEL*/

#if (NUCODEGEN_PWM1_CH4_CAP_INT_SEL == 1)

    /*Get rising latch capture interrupt and clear flag*/
    if( PWM_GetCaptureIntFlag(PWM1, 4) & 1)
    {
        PWM_ClearCaptureIntFlag(PWM1, 4, PWM_CAPTURE_INT_RISING_LATCH) ;
    }

#elif (NUCODEGEN_PWM1_CH4_CAP_INT_SEL == 2)

    /*Get falling latch capture interrupt and clear flag*/
    if( PWM_GetCaptureIntFlag(PWM1, 4) & 2)
    {
        PWM_ClearCaptureIntFlag(PWM1, 4, PWM_CAPTURE_INT_FALLING_LATCH) ;
    }

#elif (NUCODEGEN_PWM1_CH4_CAP_INT_SEL == 3)

    /*Get rising and fallinglatch capture interrupt and clear flag*/
    if( PWM_GetCaptureIntFlag(PWM1, 4) & 3)
    {
        PWM_ClearCaptureIntFlag(PWM1, 4, PWM_CAPTURE_INT_RISING_LATCH|PWM_CAPTURE_INT_FALLING_LATCH) ;
    }

#endif /*NUCODEGEN_PWM1_CH4_CAP_INT_SEL*/

#if ( ((NUCODEGEN_PWM1_CH5_INT_SEL) & 4) || ((NUCODEGEN_PWM1_CH5_INT_SEL) & 8) )

    /*Get duty interrupt and clear flag*/
    if( PWM_GetDutyIntFlag(PWM1, 5) )
    {
        PWM_ClearDutyIntFlag(PWM1, 5) ;
    }

#endif /*NUCODEGEN_PWM1_CH5_INT_SEL*/

#if (NUCODEGEN_PWM1_CH5_CAP_INT_SEL == 1)

    /*Get rising latch capture interrupt and clear flag*/
    if( PWM_GetCaptureIntFlag(PWM1, 5) & 1)
    {
        PWM_ClearCaptureIntFlag(PWM1, 5, PWM_CAPTURE_INT_RISING_LATCH) ;
    }

#elif (NUCODEGEN_PWM1_CH5_CAP_INT_SEL == 2)

    /*Get falling latch capture interrupt and clear flag*/
    if( PWM_GetCaptureIntFlag(PWM1, 5) & 2)
    {
        PWM_ClearCaptureIntFlag(PWM1, 5, PWM_CAPTURE_INT_FALLING_LATCH) ;
    }

#elif (NUCODEGEN_PWM1_CH5_CAP_INT_SEL == 3)

    /*Get rising and fallinglatch capture interrupt and clear flag*/
    if( PWM_GetCaptureIntFlag(PWM1, 5) & 3)
    {
        PWM_ClearCaptureIntFlag(PWM1, 5, PWM_CAPTURE_INT_RISING_LATCH|PWM_CAPTURE_INT_FALLING_LATCH) ;
    }

#endif /*NUCODEGEN_PWM1_CH5_CAP_INT_SEL*/

}

#endif /*NUCODEGEN_PWM1_CH4CH5*/

#if (((NUCODEGEN_PWM1_CH0_INT_SEL) & 16)||((NUCODEGEN_PWM1_CH1_INT_SEL) & 16)||((NUCODEGEN_PWM1_CH2_INT_SEL) & 16)||((NUCODEGEN_PWM1_CH3_INT_SEL) & 16)||((NUCODEGEN_PWM1_CH4_INT_SEL) & 16)||((NUCODEGEN_PWM1_CH5_INT_SEL) & 16))

void BRAKE1_IRQHandler(void)
{

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

#endif

#endif //NUCODEGEN_PWM1

#if NUCODEGEN_GPIO
#if NUCODEGEN_GPIO_PA_INT
void GPA_IRQHandler(void)
{
    /* To check if PA.1 interrupt occurred */
    if (GPIO_GET_INT_FLAG(PA, BIT1))
    {
        GPIO_CLR_INT_FLAG(PA, BIT1);
        printf("PA.1 INT occurred.\n");
    }
    else
    {
        /* Un-expected interrupt. Just clear all PA interrupts */
        PA->INTSRC = PA->INTSRC;
        printf("Un-expected interrupts.\n");
    }
}
#endif

#if NUCODEGEN_GPIO_PB_INT
void GPB_IRQHandler(void)
{
    /* To check if PB.2 interrupt occurred */
    if (GPIO_GET_INT_FLAG(PB, BIT2))
    {
        GPIO_CLR_INT_FLAG(PB, BIT2);
        printf("PB.2 INT occurred.\n");
    }
    else
    {
        /* Un-expected interrupt. Just clear all PB interrupts */
        PB->INTSRC = PB->INTSRC;
        printf("Un-expected interrupts.\n");
    }
}
#endif

#if NUCODEGEN_GPIO_PC_INT
void GPC_IRQHandler(void)
{
    /* To check if PC.0 interrupt occurred */
    if (GPIO_GET_INT_FLAG(PC, BIT0))
    {
        GPIO_CLR_INT_FLAG(PC, BIT0);
        printf("PC.0 INT occurred.\n");
    }
    else
    {
        /* Un-expected interrupt. Just clear all PC interrupts */
        PC->INTSRC = PC->INTSRC;
        printf("Un-expected interrupts.\n");
    }
}
#endif

#if NUCODEGEN_GPIO_PD_INT
void GPD_IRQHandler(void)
{
    /* To check if PD.0 interrupt occurred */
    if (GPIO_GET_INT_FLAG(PD, BIT0))
    {
        GPIO_CLR_INT_FLAG(PD, BIT0);
        printf("PD.0 INT occurred.\n");
    }
    else
    {
        /* Un-expected interrupt. Just clear all PD interrupts */
        PD->INTSRC = PD->INTSRC;
        printf("Un-expected interrupts.\n");
    }
}
#endif

#if NUCODEGEN_GPIO_PE_INT
void GPE_IRQHandler(void)
{
    /* To check if PE.0 interrupt occurred */
    if (GPIO_GET_INT_FLAG(PE, BIT0))
    {
        GPIO_CLR_INT_FLAG(PE, BIT0);
        printf("PE.0 INT occurred.\n");
    }
    else
    {
        /* Un-expected interrupt. Just clear all PE interrupts */
        PE->INTSRC = PE->INTSRC;
        printf("Un-expected interrupts.\n");
    }
}
#endif

#if NUCODEGEN_GPIO_PF_INT
void GPF_IRQHandler(void)
{
    /* To check if PF.0 interrupt occurred */
    if (GPIO_GET_INT_FLAG(PF, BIT0))
    {
        GPIO_CLR_INT_FLAG(PF, BIT0);
        printf("PF.0 INT occurred.\n");
    }
    else
    {
        /* Un-expected interrupt. Just clear all PF interrupts */
        PF->INTSRC = PF->INTSRC;
        printf("Un-expected interrupts.\n");
    }
}
#endif

#if (NUCODEGEN_GPIO_PA_EINT0 || NUCODEGEN_GPIO_PB_EINT0)
void EINT0_IRQHandler(void)
{
#if NUCODEGEN_GPIO_PA_EINT0
    /* To check if PA.6 external interrupt occurred */
    if (GPIO_GET_INT_FLAG(PA, BIT6))
    {
        GPIO_CLR_INT_FLAG(PA, BIT6);
        printf("PA.6 EINT0 occurred.\n");
    }
#endif

#if NUCODEGEN_GPIO_PB_EINT0
    /* To check if PB.5 external interrupt occurred */
    if (GPIO_GET_INT_FLAG(PB, BIT5))
    {
        GPIO_CLR_INT_FLAG(PB, BIT5);
        printf("PB.5 EINT0 occurred.\n");
    }
#endif
}
#endif

#if (NUCODEGEN_GPIO_PA_EINT1 || NUCODEGEN_GPIO_PB_EINT1 || NUCODEGEN_GPIO_PD_EINT1)
void EINT1_IRQHandler(void)
{
#if NUCODEGEN_GPIO_PA_EINT1
    /* To check if PA.7 external interrupt occurred */
    if (GPIO_GET_INT_FLAG(PA, BIT7))
    {
        GPIO_CLR_INT_FLAG(PA, BIT7);
        printf("PA.7 EINT1 occurred.\n");
    }
#endif

#if NUCODEGEN_GPIO_PB_EINT1
    /* To check if PB.4 external interrupt occurred */
    if (GPIO_GET_INT_FLAG(PB, BIT4))
    {
        GPIO_CLR_INT_FLAG(PB, BIT4);
        printf("PB.4 EINT1 occurred.\n");
    }
#endif

#if NUCODEGEN_GPIO_PD_EINT1
    /* To check if PD.15 external interrupt occurred */
    if (GPIO_GET_INT_FLAG(PD, BIT15))
    {
        GPIO_CLR_INT_FLAG(PD, BIT15);
        printf("PD.15 EINT1 occurred.\n");
    }
#endif
}
#endif

#if (NUCODEGEN_GPIO_PC_EINT2 || NUCODEGEN_GPIO_PB_EINT2)
void EINT2_IRQHandler(void)
{
#if NUCODEGEN_GPIO_PC_EINT2
    /* To check if PB.3 external interrupt occurred */
    if (GPIO_GET_INT_FLAG(PB, BIT3))
    {
        GPIO_CLR_INT_FLAG(PB, BIT3);
        printf("PB.3 EINT2 occurred.\n");
    }
#endif

#if NUCODEGEN_GPIO_PB_EINT2
    /* To check if PC.6 external interrupt occurred */
    if (GPIO_GET_INT_FLAG(PC, BIT6))
    {
        GPIO_CLR_INT_FLAG(PC, BIT6);
        printf("PC.6 EINT2 occurred.\n");
    }
#endif
}
#endif

#if (NUCODEGEN_GPIO_PC_EINT3 || NUCODEGEN_GPIO_PB_EINT3)
void EINT3_IRQHandler(void)
{
#if NUCODEGEN_GPIO_PB_EINT3
    /* To check if PB.2 external interrupt occurred */
    if (GPIO_GET_INT_FLAG(PB, BIT2))
    {
        GPIO_CLR_INT_FLAG(PB, BIT2);
        printf("PB.2 EINT3 occurred.\n");
    }
#endif

#if NUCODEGEN_GPIO_PC_EINT3
    /* To check if PC.7 external interrupt occurred */
    if (GPIO_GET_INT_FLAG(PC, BIT7))
    {
        GPIO_CLR_INT_FLAG(PC, BIT7);
        printf("PC.7 EINT3 occurred.\n");
    }
#endif
}
#endif

#if (NUCODEGEN_GPIO_PA_EINT4 || NUCODEGEN_GPIO_PB_EINT4)
void EINT4_IRQHandler(void)
{
#if NUCODEGEN_GPIO_PB_EINT4
    /* To check if PB.6 external interrupt occurred */
    if (GPIO_GET_INT_FLAG(PB, BIT6))
    {
        GPIO_CLR_INT_FLAG(PB, BIT6);
        printf("PB.6 EINT4 occurred.\n");
    }
#endif

#if (NUCODEGEN_GPIO_PA_EINT4
    /* To check if PA.8 external interrupt occurred */
    if (GPIO_GET_INT_FLAG(PA, BIT8))
    {
        GPIO_CLR_INT_FLAG(PA, BIT8);
        printf("PA.8 EINT4 occurred.\n");
    }
#endif
}
#endif

#if (NUCODEGEN_GPIO_PD_EINT5 || NUCODEGEN_GPIO_PB_EINT5)
void EINT5_IRQHandler(void)
{
#if NUCODEGEN_GPIO_PB_EINT5
    /* To check if PB.7 external interrupt occurred */
    if (GPIO_GET_INT_FLAG(PB, BIT7))
    {
        GPIO_CLR_INT_FLAG(PB, BIT7);
        printf("PB.7 EINT5 occurred.\n");
    }
#endif

#if NUCODEGEN_GPIO_PD_EINT5
    /* To check if PD.12 external interrupt occurred */
    if (GPIO_GET_INT_FLAG(PD, BIT12))
    {
        GPIO_CLR_INT_FLAG(PD, BIT12);
        printf("PD.12 EINT5 occurred.\n");
    }
#endif
}
#endif
#endif //NUCODEGEN_GPIO

#if NUCODEGEN_UART0

#if (NUCODEGEN_UART0_FUNCSEL == NUCODEGEN_UART0_FUNCSEL_UART ||  NUCODEGEN_UART0_FUNCSEL == NUCODEGEN_UART0_FUNCSEL_SINGLE_WIRE )
void UART0_IRQHandler(void)
{

#if (NUCODEGEN_UART0_INTEN || NUCODEGEN_UART0_SW_INTEN )
    uint32_t u32IntSts = UART0->INTSTS;
    uint32_t u32WKSts  = UART0->WKSTS;
    uint8_t u8InChar = 0xFF;
    uint32_t u32Data;

    /* Auto-baud Rate Interrupt */
    if (u32IntSts & UART_INTSTS_ABRINT_Msk)
    {
        UART0->FIFOSTS = (UART_FIFOSTS_ABRDIF_Msk | UART_FIFOSTS_ABRDTOIF_Msk);
    }
#if (NUCODEGEN_UART0_FUNCSEL == NUCODEGEN_UART0_FUNCSEL_UART)
     /* MODEM Status Interrupt */
    if(u32IntSts & UART_INTSTS_MODEMIF_Msk)
    {
     /*Clear nCTS State Change Flag*/
      UART_ClearIntFlag(UART0, UART_INTSTS_MODEMINT_Msk);
    }
#endif
    /* Receive Line Status Interrupt */
    if (u32IntSts & UART_INTSTS_RLSIF_Msk)
    {
        if (UART0->FIFOSTS & UART_FIFOSTS_BIF_Msk)
            printf("\n BIF \n");

        if (UART0->FIFOSTS & UART_FIFOSTS_FEF_Msk)
            printf("\n FEF \n");

        if (UART0->FIFOSTS & UART_FIFOSTS_PEF_Msk)
            printf("\n PEF \n");

        u32Data = UART0->DAT; // read out data
        printf("\n Error Data is '0x%x' \n", u32Data);
        UART_ClearIntFlag(UART0, UART_INTSTS_RLSINT_Msk);
    }

    if ((u32IntSts & UART_INTSTS_RDAINT_Msk) || (u32IntSts & UART_INTSTS_RXTOINT_Msk))/* Rx Ready or Time-out INT*/
    {
        /* Handle received data */
        while (!UART_GET_RX_EMPTY(UART0))

        /* Get all the input characters */
        while (UART_IS_RX_READY(UART0))
        {
            /* Get the character from UART Buffer */
            u8InChar = UART_READ(UART0);

        }

    }

    /* Buffer Error Interrupt  */
    if (u32IntSts & UART_INTSTS_BUFERRINT_Msk)     /* Buffer Error INT */
    {
        printf("\nBuffer Error...\n");
        UART_ClearIntFlag(UART0, UART_INTSTS_BUFERRINT_Msk);
    }
#if (NUCODEGEN_UART0_FUNCSEL == NUCODEGEN_UART0_FUNCSEL_SINGLE_WIRE)
    if (u32IntSts & UART_INTSTS_SWBEINT_Msk)
    {
        printf("Single-wire Bit Error Detection \n");
        UART_ClearIntFlag(UART0, UART_INTSTS_SWBEINT_Msk);
    }
#endif
    /*  Transmit Holding Register Empty Interrupt  or  Transmitter Empty Interrupt*/
    if ((u32IntSts & UART_INTSTS_THREINT_Msk) || (u32IntSts & UART_INTSTS_TXENDIF_Msk) )
    {
      while (UART_IS_TX_FULL(UART0)); /* Wait Tx is not full to transmit data */
      UART_WRITE(UART0, u8InChar);
    }
    /* UART Wake-up Interrupt  */
    if (u32IntSts & UART_INTSTS_WKIF_Msk)
    {
        printf("\n UART Wake-Up ");
        UART0->INTSTS = UART_INTSTS_WKIF_Msk;
        UART_ClearIntFlag(UART0,UART_INTSTS_WKINT_Msk);
    }

#endif //(NUCODEGEN_UART1_INTEN || NUCODEGEN_UART1_SW_INTEN)
}


#elif (NUCODEGEN_UART0_FUNCSEL == NUCODEGEN_UART0_FUNCSEL_LIN)


void UART0_IRQHandler(void)
{
#if NUCODEGEN_UART0_LINIEN
      uint32_t u32IntSts = UART0->INTSTS;
  /* LIN Bus Interrupt */
  if(u32IntSts & UART_INTSTS_LININT_Msk)
  {
    /* Clear LIN Bus Interrupt */
    UART_ClearIntFlag(UART0,UART_INTSTS_LININT_Msk);
  }
#endif  // NUCODEGEN_UART0_LINIEN
}

#elif (NUCODEGEN_UART0_FUNCSEL == NUCODEGEN_UART0_FUNCSEL_IrDA)

void UART0_IRQHandler(void)
{
#if NUCODEGEN_UART0_IRDA_INTEN
  uint32_t u32IntSts = UART0->INTSTS;
  uint8_t u8InChar = 0xFF;

  /* Rx Ready or Time-out INT*/
  if ((u32IntSts & UART_INTSTS_RDAINT_Msk) || (u32IntSts & UART_INTSTS_RXTOINT_Msk))
   {
        /* received data */
        while (!UART_GET_RX_EMPTY(UART0))
        printf("\nInput:");

        /* Get all the input characters */
        while (UART_IS_RX_READY(UART0))
        {
            /* Get the character from UART Buffer */
            u8InChar = UART_READ(UART0);
            printf("%c\n", u8InChar);

        }
   }
   /*  Transmit Holding Register Empty Interrupt  or  Transmitter Empty Interrupt*/
   if ((u32IntSts & UART_INTSTS_THREINT_Msk) || (u32IntSts & UART_INTSTS_TXENDIF_Msk) )
   {
      while (UART_IS_TX_FULL(UART0)); /* Wait Tx is not full to transmit data */
      UART_WRITE(UART0, u8InChar);
   }
#endif //NUCODEGEN_UART0_IRDA_INTEN
}


#elif (NUCODEGEN_UART0_FUNCSEL == NUCODEGEN_UART0_FUNCSEL_RS485)


void UART0_IRQHandler(void)
{
#if NUCODEGEN_UART0_RS485_INTEN
    volatile uint32_t u32Addr = 0;
    uint32_t u32IntSts = UART0->INTSTS;
    uint32_t u32WKSts  = UART0->WKSTS;
    uint8_t u8InChar = 0xFF;
    uint32_t u32Data;

  /* RLS INT & RDA INT */
    if ((u32IntSts & UART_INTSTS_RLSINT_Msk) && (u32IntSts & UART_INTSTS_RDAINT_Msk))//For RS485 Detect Address
    {
        if (UART0->FIFOSTS & UART_FIFOSTS_ADDRDETF_Msk)   /* ADD_IF, RS485 mode */
        {
            u32Addr = UART0->DAT;
            UART_RS485_CLEAR_ADDR_FLAG(UART0);        /* clear ADD_IF flag */
            printf("\nAddr=0x%x,Get:", u32Addr);

#if (NUCODEGEN_UART0_RS485_MODE == NUCODEGEN_UART0_RS485_NMM_MODE) //RS485_NMM
            /* if address match, enable RX to receive data, otherwise to disable RX. */
            /* In NMM mode,user can decide multi-address filter. In AAD mode,only one address can set */
            if ((u32Addr == UART0_MATCH_ADDRSS1) || (u32Addr == UART0_MATCH_ADDRSS2))
            {
                UART0->FIFO &= ~ UART_FIFO_RXOFF_Msk;  /* Enable RS485 RX */
            }
            else
            {
                UART0->FIFO |= UART_FIFO_RXOFF_Msk;      /* Disable RS485 RX */
                UART0->FIFO |= UART_FIFO_RXRST_Msk;      /* Clear data from RX FIFO */
                printf("\n");
            }
#endif
        }
    }
    else if ((u32IntSts & UART_INTSTS_RDAINT_Msk) || (u32IntSts & UART_INTSTS_RXTOINT_Msk))/* Rx Ready or Time-out INT*/
    {
         /* Handle received data */
        while (!UART_GET_RX_EMPTY(UART0)){};
        printf("%2d,", UART0->DAT);

    }
    else if (u32IntSts & UART_INTSTS_BUFERRINT_Msk)     /* Buffer Error INT */
    {
        printf("\nBuffer Error...\n");
        UART_ClearIntFlag(UART0, UART_INTSTS_BUFERRINT_Msk);
    }
   /*  Transmit Holding Register Empty Interrupt  or  Transmitter Empty Interrupt*/
   if ((u32IntSts & UART_INTSTS_THREINT_Msk) || (u32IntSts & UART_INTSTS_TXENDIF_Msk) )
   {
      while (UART_IS_TX_FULL(UART0)); /* Wait Tx is not full to transmit data */
      UART_WRITE(UART0, u8InChar);
   }
 #endif //NUCODEGEN_UART0_RS485_INTEN
}

#endif //(NUCODEGEN_UART0_FUNCSEL_UART || NUCODEGEN_UART0_FUNCSEL_SINGLE_WIRE)

#endif

#if NUCODEGEN_UART1
#if (NUCODEGEN_UART1_FUNCSEL == NUCODEGEN_UART1_FUNCSEL_UART ||  NUCODEGEN_UART1_FUNCSEL == NUCODEGEN_UART1_FUNCSEL_SINGLE_WIRE )
void UART1_IRQHandler(void)
{
 #if(NUCODEGEN_UART1_INTEN || NUCODEGEN_UART1_SW_INTEN )
    uint32_t u32IntSts = UART1->INTSTS;
    uint32_t u32WKSts  = UART1->WKSTS;
    uint8_t u8InChar = 0xFF;
    uint32_t u32Data;

    /* Auto-baud Rate Interrupt */
    if (u32IntSts & UART_INTSTS_ABRINT_Msk)
    {
        UART1->FIFOSTS = (UART_FIFOSTS_ABRDIF_Msk | UART_FIFOSTS_ABRDTOIF_Msk);
    }
#if (NUCODEGEN_UART1_FUNCSEL == NUCODEGEN_UART1_FUNCSEL_UART)
     /* MODEM Status Interrupt */
    if(u32IntSts & UART_INTSTS_MODEMIF_Msk)
    {
     /*Clear nCTS State Change Flag*/
      UART_ClearIntFlag(UART1, UART_INTSTS_MODEMINT_Msk);
    }
#endif
    /* Receive Line Status Interrupt */
    if (u32IntSts & UART_INTSTS_RLSIF_Msk)
    {
        if (UART1->FIFOSTS & UART_FIFOSTS_BIF_Msk)
            printf("\n BIF \n");

        if (UART1->FIFOSTS & UART_FIFOSTS_FEF_Msk)
            printf("\n FEF \n");

        if (UART1->FIFOSTS & UART_FIFOSTS_PEF_Msk)
            printf("\n PEF \n");

        u32Data = UART1->DAT; // read out data
        printf("\n Error Data is '0x%x' \n", u32Data);
        UART_ClearIntFlag(UART1, UART_INTSTS_RLSINT_Msk);
    }

    if ((u32IntSts & UART_INTSTS_RDAINT_Msk) || (u32IntSts & UART_INTSTS_RXTOINT_Msk))/* Rx Ready or Time-out INT*/
    {
        /* Handle received data */
        while (!UART_GET_RX_EMPTY(UART1))

        /* Get all the input characters */
        while (UART_IS_RX_READY(UART1))
        {
            /* Get the character from UART Buffer */
            u8InChar = UART_READ(UART1);

        }

    }

    /* Buffer Error Interrupt  */
    if (u32IntSts & UART_INTSTS_BUFERRINT_Msk)     /* Buffer Error INT */
    {
        printf("\nBuffer Error...\n");
        UART_ClearIntFlag(UART1, UART_INTSTS_BUFERRINT_Msk);
    }
#if (NUCODEGEN_UART1_FUNCSEL == NUCODEGEN_UART1_FUNCSEL_SINGLE_WIRE)
    if (u32IntSts & UART_INTSTS_SWBEINT_Msk)
    {
        printf("Single-wire Bit Error Detection \n");
        UART_ClearIntFlag(UART1, UART_INTSTS_SWBEINT_Msk);
    }
#endif
    /*  Transmit Holding Register Empty Interrupt  or  Transmitter Empty Interrupt*/
    if ((u32IntSts & UART_INTSTS_THREINT_Msk) || (u32IntSts & UART_INTSTS_TXENDIF_Msk) )
    {
      while (UART_IS_TX_FULL(UART1)); /* Wait Tx is not full to transmit data */
      UART_WRITE(UART1, u8InChar);
    }
    /* UART Wake-up Interrupt  */
    if (u32IntSts & UART_INTSTS_WKIF_Msk)
    {
        printf("\n UART Wake-Up ");
        UART1->INTSTS = UART_INTSTS_WKIF_Msk;
        UART_ClearIntFlag(UART1,UART_INTSTS_WKINT_Msk);
    }
#endif//(NUCODEGEN_UART1_INTEN || NUCODEGEN_UART1_SW_INTEN )

}
#elif (NUCODEGEN_UART1_FUNCSEL == NUCODEGEN_UART1_FUNCSEL_IrDA)
void UART1_IRQHandler(void)
{
#if NUCODEGEN_UART1_IRDA_INTEN
  uint32_t u32IntSts = UART1->INTSTS;
  uint8_t u8InChar = 0xFF;

  /* Rx Ready or Time-out INT*/
  if ((u32IntSts & UART_INTSTS_RDAINT_Msk) || (u32IntSts & UART_INTSTS_RXTOINT_Msk))
   {
        /* received data */
        while (!UART_GET_RX_EMPTY(UART1))
        printf("\nInput:");

        /* Get all the input characters */
        while (UART_IS_RX_READY(UART1))
        {
            /* Get the character from UART Buffer */
            u8InChar = UART_READ(UART1);
            printf("%c\n", u8InChar);

        }
   }
   /*  Transmit Holding Register Empty Interrupt  or  Transmitter Empty Interrupt*/
   if ((u32IntSts & UART_INTSTS_THREINT_Msk) || (u32IntSts & UART_INTSTS_TXENDIF_Msk) )
   {
      while (UART_IS_TX_FULL(UART1)); /* Wait Tx is not full to transmit data */
      UART_WRITE(UART1, u8InChar);
   }
 #endif  //NUCODEGEN_UART1_IRDA_INTEN
}
#elif (NUCODEGEN_UART1_FUNCSEL == NUCODEGEN_UART1_FUNCSEL_RS485)
void UART1_IRQHandler(void)
{

 #if NUCODEGEN_UART1_RS485_INTEN

    volatile uint32_t u32Addr = 0;
    uint32_t u32IntSts = UART1->INTSTS;
    uint32_t u32WKSts  = UART1->WKSTS;
    uint8_t u8InChar = 0xFF;
    uint32_t u32Data;

  /* RLS INT & RDA INT */
    if ((u32IntSts & UART_INTSTS_RLSINT_Msk) && (u32IntSts & UART_INTSTS_RDAINT_Msk))//For RS485 Detect Address
    {
        if (UART1->FIFOSTS & UART_FIFOSTS_ADDRDETF_Msk)   /* ADD_IF, RS485 mode */
        {
            u32Addr = UART1->DAT;
            UART_RS485_CLEAR_ADDR_FLAG(UART1);        /* clear ADD_IF flag */
            printf("\nAddr=0x%x,Get:", u32Addr);

#if (NUCODEGEN_UART1_RS485_MODE == NUCODEGEN_UART1_RS485_NMM_MODE) //RS485_NMM
            /* if address match, enable RX to receive data, otherwise to disable RX. */
            /* In NMM mode,user can decide multi-address filter. In AAD mode,only one address can set */
            if ((u32Addr == UART1_MATCH_ADDRSS1) || (u32Addr == UART1_MATCH_ADDRSS2))
            {
                UART1->FIFO &= ~ UART_FIFO_RXOFF_Msk;  /* Enable RS485 RX */
            }
            else
            {
                UART1->FIFO |= UART_FIFO_RXOFF_Msk;      /* Disable RS485 RX */
                UART1->FIFO |= UART_FIFO_RXRST_Msk;      /* Clear data from RX FIFO */
                printf("\n");
            }
#endif
        }
    }
    else if ((u32IntSts & UART_INTSTS_RDAINT_Msk) || (u32IntSts & UART_INTSTS_RXTOINT_Msk))/* Rx Ready or Time-out INT*/
    {
         /* Handle received data */
        while (!UART_GET_RX_EMPTY(UART1)){};
        printf("%2d,", UART1->DAT);

    }
    else if (u32IntSts & UART_INTSTS_BUFERRINT_Msk)     /* Buffer Error INT */
    {
        printf("\nBuffer Error...\n");
        UART_ClearIntFlag(UART1, UART_INTSTS_BUFERRINT_Msk);
    }
   /*  Transmit Holding Register Empty Interrupt  or  Transmitter Empty Interrupt*/
   if ((u32IntSts & UART_INTSTS_THREINT_Msk) || (u32IntSts & UART_INTSTS_TXENDIF_Msk) )
   {
      while (UART_IS_TX_FULL(UART1)); /* Wait Tx is not full to transmit data */
      UART_WRITE(UART1, u8InChar);
   }

 #endif //NUCODEGEN_UART1_RS485_INTEN
}
#endif //(NUCODEGEN_UART1_FUNCSEL_UART || NUCODEGEN_UART1_FUNCSEL_SINGLE_WIRE)

#endif

#if NUCODEGEN_UART2
#if (NUCODEGEN_UART2_FUNCSEL == NUCODEGEN_UART2_FUNCSEL_UART ||  NUCODEGEN_UART2_FUNCSEL == NUCODEGEN_UART2_FUNCSEL_SINGLE_WIRE )
void UART2_IRQHandler(void)
{
 #if(NUCODEGEN_UART2_INTEN || NUCODEGEN_UART2_SW_INTEN )
    uint32_t u32IntSts = UART2->INTSTS;
    uint32_t u32WKSts  = UART2->WKSTS;
    uint8_t u8InChar = 0xFF;
    uint32_t u32Data;

    /* Auto-baud Rate Interrupt */
    if (u32IntSts & UART_INTSTS_ABRINT_Msk)
    {
        UART2->FIFOSTS = (UART_FIFOSTS_ABRDIF_Msk | UART_FIFOSTS_ABRDTOIF_Msk);
    }
#if (NUCODEGEN_UART2_FUNCSEL == NUCODEGEN_UART2_FUNCSEL_UART)
     /* MODEM Status Interrupt */
    if(u32IntSts & UART_INTSTS_MODEMIF_Msk)
    {
     /*Clear nCTS State Change Flag*/
      UART_ClearIntFlag(UART2, UART_INTSTS_MODEMINT_Msk);
    }
#endif
    /* Receive Line Status Interrupt */
    if (u32IntSts & UART_INTSTS_RLSIF_Msk)
    {
        if (UART2->FIFOSTS & UART_FIFOSTS_BIF_Msk)
            printf("\n BIF \n");

        if (UART2->FIFOSTS & UART_FIFOSTS_FEF_Msk)
            printf("\n FEF \n");

        if (UART2->FIFOSTS & UART_FIFOSTS_PEF_Msk)
            printf("\n PEF \n");

        u32Data = UART2->DAT; // read out data
        printf("\n Error Data is '0x%x' \n", u32Data);
        UART_ClearIntFlag(UART2, UART_INTSTS_RLSINT_Msk);
    }

    if ((u32IntSts & UART_INTSTS_RDAINT_Msk) || (u32IntSts & UART_INTSTS_RXTOINT_Msk))/* Rx Ready or Time-out INT*/
    {
        /* Handle received data */
        while (!UART_GET_RX_EMPTY(UART2))

        /* Get all the input characters */
        while (UART_IS_RX_READY(UART2))
        {
            /* Get the character from UART Buffer */
            u8InChar = UART_READ(UART2);

        }

    }

    /* Buffer Error Interrupt  */
    if (u32IntSts & UART_INTSTS_BUFERRINT_Msk)     /* Buffer Error INT */
    {
        printf("\nBuffer Error...\n");
        UART_ClearIntFlag(UART2, UART_INTSTS_BUFERRINT_Msk);
    }
#if (NUCODEGEN_UART2_FUNCSEL == NUCODEGEN_UART2_FUNCSEL_SINGLE_WIRE)
    if (u32IntSts & UART_INTSTS_SWBEINT_Msk)
    {
        printf("Single-wire Bit Error Detection \n");
        UART_ClearIntFlag(UART2, UART_INTSTS_SWBEINT_Msk);
    }
#endif
    /*  Transmit Holding Register Empty Interrupt  or  Transmitter Empty Interrupt*/
    if ((u32IntSts & UART_INTSTS_THREINT_Msk) || (u32IntSts & UART_INTSTS_TXENDIF_Msk) )
    {
      while (UART_IS_TX_FULL(UART2)); /* Wait Tx is not full to transmit data */
      UART_WRITE(UART2, u8InChar);
    }
    /* UART Wake-up Interrupt  */
    if (u32IntSts & UART_INTSTS_WKIF_Msk)
    {
        printf("\n UART Wake-Up ");
        UART2->INTSTS = UART_INTSTS_WKIF_Msk;
        UART_ClearIntFlag(UART2,UART_INTSTS_WKINT_Msk);
    }

#endif //(NUCODEGEN_UART2_INTEN || NUCODEGEN_UART2_SW_INTEN )

}
#elif (NUCODEGEN_UART2_FUNCSEL == NUCODEGEN_UART2_FUNCSEL_IrDA)
void UART2_IRQHandler(void)
{

#if NUCODEGEN_UART2_IRDA_INTEN
  uint32_t u32IntSts = UART2->INTSTS;
  uint8_t u8InChar = 0xFF;

  /* Rx Ready or Time-out INT*/
  if ((u32IntSts & UART_INTSTS_RDAINT_Msk) || (u32IntSts & UART_INTSTS_RXTOINT_Msk))
   {
        /* received data */
        while (!UART_GET_RX_EMPTY(UART2))
        printf("\nInput:");

        /* Get all the input characters */
        while (UART_IS_RX_READY(UART2))
        {
            /* Get the character from UART Buffer */
            u8InChar = UART_READ(UART2);
            printf("%c\n", u8InChar);

        }
   }
   /*  Transmit Holding Register Empty Interrupt  or  Transmitter Empty Interrupt*/
   if ((u32IntSts & UART_INTSTS_THREINT_Msk) || (u32IntSts & UART_INTSTS_TXENDIF_Msk) )
   {
      while (UART_IS_TX_FULL(UART2)); /* Wait Tx is not full to transmit data */
      UART_WRITE(UART2, u8InChar);
   }

#endif //NUCODEGEN_UART2_IRDA_INTEN
}
#elif (NUCODEGEN_UART2_FUNCSEL == NUCODEGEN_UART2_FUNCSEL_RS485)
void UART2_IRQHandler(void)
{

 #if NUCODEGEN_UART2_RS485_INTEN

    volatile uint32_t u32Addr = 0;
    uint32_t u32IntSts = UART2->INTSTS;
    uint32_t u32WKSts  = UART2->WKSTS;
    uint8_t u8InChar = 0xFF;
    uint32_t u32Data;

  /* RLS INT & RDA INT */
    if ((u32IntSts & UART_INTSTS_RLSINT_Msk) && (u32IntSts & UART_INTSTS_RDAINT_Msk))//For RS485 Detect Address
    {
        if (UART2->FIFOSTS & UART_FIFOSTS_ADDRDETF_Msk)   /* ADD_IF, RS485 mode */
        {
            u32Addr = UART2->DAT;
            UART_RS485_CLEAR_ADDR_FLAG(UART2);        /* clear ADD_IF flag */
            printf("\nAddr=0x%x,Get:", u32Addr);

#if (NUCODEGEN_UART2_RS485_MODE == NUCODEGEN_UART2_RS485_NMM_MODE) //RS485_NMM
            /* if address match, enable RX to receive data, otherwise to disable RX. */
            /* In NMM mode,user can decide multi-address filter. In AAD mode,only one address can set */
            if ((u32Addr == UART2_MATCH_ADDRSS1) || (u32Addr == UART2_MATCH_ADDRSS2))
            {
                UART2->FIFO &= ~ UART_FIFO_RXOFF_Msk;  /* Enable RS485 RX */
            }
            else
            {
                UART2->FIFO |= UART_FIFO_RXOFF_Msk;      /* Disable RS485 RX */
                UART2->FIFO |= UART_FIFO_RXRST_Msk;      /* Clear data from RX FIFO */
                printf("\n");
            }
#endif
        }
    }
    else if ((u32IntSts & UART_INTSTS_RDAINT_Msk) || (u32IntSts & UART_INTSTS_RXTOINT_Msk))/* Rx Ready or Time-out INT*/
    {
         /* Handle received data */
        while (!UART_GET_RX_EMPTY(UART2)){};
        printf("%2d,", UART2->DAT);

    }
    else if (u32IntSts & UART_INTSTS_BUFERRINT_Msk)     /* Buffer Error INT */
    {
        printf("\nBuffer Error...\n");
        UART_ClearIntFlag(UART2, UART_INTSTS_BUFERRINT_Msk);
    }
   /*  Transmit Holding Register Empty Interrupt  or  Transmitter Empty Interrupt*/
   if ((u32IntSts & UART_INTSTS_THREINT_Msk) || (u32IntSts & UART_INTSTS_TXENDIF_Msk) )
   {
      while (UART_IS_TX_FULL(UART2)); /* Wait Tx is not full to transmit data */
      UART_WRITE(UART2, u8InChar);
   }

 #endif //NUCODEGEN_UART2_RS485_INTEN
}
#endif //(NUCODEGEN_UART2_FUNCSEL_UART || NUCODEGEN_UART2_FUNCSEL_SINGLE_WIRE)
#endif

#if (NUCODEGEN_I2C0)
#if NUCODEGEN_I2C0_INT_EN


#if (NUCODEGEN_I2C0_SUBMODE_SEL==NUCODEGEN_I2C0_SUBMODE_NORMAL)
void I2C0_IRQHandler(void)
{
    uint32_t u32Status;

#if NUCODEGEN_I2C0_WAKEUP_EN
    /* Check I2C Wake-up interrupt flag set or not */
    if (I2C_GET_WAKEUP_FLAG(I2C0))
    {
        /* Clear I2C Wake-up interrupt flag */
        I2C_CLEAR_WAKEUP_FLAG(I2C0);
        return;
    }
#endif /*NUCODEGEN_I2C0_WAKEUP_EN*/

    u32Status = I2C_GET_STATUS(I2C0);

    (void)u32Status; /*To remove complier warning. The code is unnecessary if u32Status is used.*/

    if (I2C_GET_TIMEOUT_FLAG(I2C0))
    {
        /* Clear I2C0 Timeout Flag */
        I2C_ClearTimeoutFlag(I2C0);
    }
    else
    {
        /*TODO: implement user function here*/
//                if (s_pfnI2C0Handler != NULL)
//                    s_pfnI2C0Handler(u32Status);
    }
}
#endif /*NUCODEGEN_I2C0_SUBMODE_SEL==NUCODEGEN_I2C0_SUBMODE_NORMAL*/

#if (NUCODEGEN_I2C0_SUBMODE_SEL==NUCODEGEN_I2C0_SUBMODE_SMBUS)
void I2C0_IRQHandler(void)
{
    uint32_t u32Status;

#if NUCODEGEN_I2C0_WAKEUP_EN
    /* Check I2C Wake-up interrupt flag set or not */
    if (I2C_GET_WAKEUP_FLAG(I2C0))
    {
        /* Clear I2C Wake-up interrupt flag */
        I2C_CLEAR_WAKEUP_FLAG(I2C0);
        return;
    }
#endif /*NUCODEGEN_I2C0_WAKEUP_EN*/


    /* Check Transmit byte done interrupt flag */
    if((I2C_SMBusGetStatus(I2C0) & I2C_BUSSTS_BCDONE_Msk) == I2C_BUSSTS_BCDONE_Msk)
    {
        I2C_SMBusClearInterruptFlag(I2C0, I2C_BUSSTS_BCDONE_Msk);
        //printf("I2C0 Byte Transmit Byte Done Interrupt !\n");
        return;
    }

    /* Occur receive PEC packet error */
    if((I2C_SMBusGetStatus(I2C0) & I2C_BUSSTS_PECERR_Msk) == I2C_BUSSTS_PECERR_Msk)
    {
        I2C_SMBusClearInterruptFlag(I2C0, I2C_BUSSTS_PECERR_Msk);
        //printf("I2C0 PEC Error Interrupt !\n");
        return;
    }

    /* Check Alert Interrupt when I2C0 is Host */
    if(((I2C_SMBusGetStatus(I2C0) & I2C_BUSSTS_ALERT_Msk) == I2C_BUSSTS_ALERT_Msk) &
            ((I2C0->BUSCTL & I2C_BUSCTL_BMHEN_Msk) == I2C_BUSCTL_BMHEN_Msk))
    {
        I2C_SMBusClearInterruptFlag(I2C0, I2C_BUSSTS_ALERT_Msk);
        //printf("I2C0 Alert Interrupt !\n");
        return ;
    }

    if(I2C_GET_TIMEOUT_FLAG(I2C0))
    {
        /* Clear I2C0 Timeout Flag */
        I2C_ClearTimeoutFlag(I2C0);
    }
    else
    {
        u32Status = I2C_GET_STATUS(I2C0);

        (void)u32Status; /*To remove complier warning. The code is unnecessary if u32Status is used.*/

        /*TODO:: implement user function here.*/
    }
}
#endif /*NUCODEGEN_I2C0_SUBMODE_SEL==NUCODEGEN_I2C0_SUBMODE_SMBUS*/

#endif /* NUCODEGEN_I2C0_INT */
#endif /*NUCODEGEN_I2C0*/

#if (NUCODEGEN_I2C1)
#if NUCODEGEN_I2C1_INT_EN


#if (NUCODEGEN_I2C1_SUBMODE_SEL==NUCODEGEN_I2C1_SUBMODE_NORMAL)
void I2C1_IRQHandler(void)
{
    uint32_t u32Status;

    (void)u32Status; /*To remove complier warning. The code is unnecessary if u32Status is used.*/

#if NUCODEGEN_I2C1_WAKEUP_EN
    /* Check I2C Wake-up interrupt flag set or not */
    if (I2C_GET_WAKEUP_FLAG(I2C1))
    {
        /* Clear I2C Wake-up interrupt flag */
        I2C_CLEAR_WAKEUP_FLAG(I2C1);
        return;
    }
#endif /*NUCODEGEN_I2C1_WAKEUP_EN*/

    u32Status = I2C_GET_STATUS(I2C1);

    if (I2C_GET_TIMEOUT_FLAG(I2C1))
    {
        /* Clear I2C1 Timeout Flag */
        I2C_ClearTimeoutFlag(I2C1);
    }
    else
    {
        /*TODO: implement user function here*/
//                if (s_pfnI2C1Handler != NULL)
//                    s_pfnI2C1Handler(u32Status);
    }
}
#endif /*NUCODEGEN_I2C1_SUBMODE_SEL==NUCODEGEN_I2C1_SUBMODE_NORMAL*/

#if (NUCODEGEN_I2C1_SUBMODE_SEL==NUCODEGEN_I2C1_SUBMODE_SMBUS)
void I2C1_IRQHandler(void)
{
    uint32_t u32Status;

#if NUCODEGEN_I2C1_WAKEUP_EN
    /* Check I2C Wake-up interrupt flag set or not */
    if (I2C_GET_WAKEUP_FLAG(I2C1))
    {
        /* Clear I2C Wake-up interrupt flag */
        I2C_CLEAR_WAKEUP_FLAG(I2C1);
        return;
    }
#endif /*NUCODEGEN_I2C1_WAKEUP_EN*/


    /* Check Transmit byte done interrupt flag */
    if((I2C_SMBusGetStatus(I2C1) & I2C_BUSSTS_BCDONE_Msk) == I2C_BUSSTS_BCDONE_Msk)
    {
        I2C_SMBusClearInterruptFlag(I2C1, I2C_BUSSTS_BCDONE_Msk);
        //printf("I2C1 Byte Transmit Byte Done Interrupt !\n");
        return;
    }

    /* Occur receive PEC packet error */
    if((I2C_SMBusGetStatus(I2C1) & I2C_BUSSTS_PECERR_Msk) == I2C_BUSSTS_PECERR_Msk)
    {
        I2C_SMBusClearInterruptFlag(I2C1, I2C_BUSSTS_PECERR_Msk);
        //printf("I2C1 PEC Error Interrupt !\n");
        return;
    }

    /* Check Alert Interrupt when I2C1 is Host */
    if(((I2C_SMBusGetStatus(I2C1) & I2C_BUSSTS_ALERT_Msk) == I2C_BUSSTS_ALERT_Msk) &
            ((I2C1->BUSCTL & I2C_BUSCTL_BMHEN_Msk) == I2C_BUSCTL_BMHEN_Msk))
    {
        I2C_SMBusClearInterruptFlag(I2C1, I2C_BUSSTS_ALERT_Msk);
        //printf("I2C1 Alert Interrupt !\n");
        return ;
    }

    if(I2C_GET_TIMEOUT_FLAG(I2C1))
    {
        /* Clear I2C1 Timeout Flag */
        I2C_ClearTimeoutFlag(I2C1);
    }
    else
    {
        u32Status = I2C_GET_STATUS(I2C1);

        (void)u32Status; /*To remove complier warning. The code is unnecessary if u32Status is used.*/

        /*TODO:: implement user function here.*/
    }
}
#endif /*NUCODEGEN_I2C1_SUBMODE_SEL==NUCODEGEN_I2C1_SUBMODE_SMBUS*/

#endif /* NUCODEGEN_I2C1_INT */
#endif /*NUCODEGEN_I2C1*/

#if (NUCODEGEN_USCI0_I2C)
#if NUCODEGEN_UI2C0_INT_EN
/*---------------------------------------------------------------------------------------------------------*/
/*  USCI_I2C IRQ Handler                                                                                   */
/*---------------------------------------------------------------------------------------------------------*/
void USCI0_IRQHandler(void)
{
    uint32_t u32Status;

    u32Status = (UI2C0->PROTSTS);

    (void)u32Status; /*To remove complier warning. The code is unnecessary if u32Status is used.*/

    #if NUCODEGEN_UI2C0_WAKEUP_EN
    if((UI2C0->WKSTS & UI2C_WKSTS_WKF_Msk) == UI2C_WKSTS_WKF_Msk)
    {

        while((UI2C0->PROTSTS & UI2C_PROTSTS_WKAKDONE_Msk) == 0) {};

        /* Clear WK flag */
        UI2C_CLR_WAKEUP_FLAG(UI2C0);
        UI2C0->PROTSTS = UI2C_PROTSTS_WKAKDONE_Msk;

        return;
    }
    #endif /*NUCODEGEN_UI2C0_WAKEUP_EN*/

    if (UI2C_GET_TIMEOUT_FLAG(UI2C0))
    {
        /* Clear USCI_I2C0 Timeout Flag */
        UI2C_ClearTimeoutFlag(UI2C0);

        /*TODO: put user code here*/
    }
    else
    {
        /*TODO: put user code here*/
    }
}

#endif /*NUCODEGEN_UI2C0_INT_EN*/
#endif /*NUCODEGEN_USCI0*/


#if (NUCODEGEN_USCI1_I2C)
#if NUCODEGEN_UI2C1_INT_EN
/*---------------------------------------------------------------------------------------------------------*/
/*  USCI_I2C IRQ Handler                                                                                   */
/*---------------------------------------------------------------------------------------------------------*/
void USCI1_IRQHandler(void)
{
    uint32_t u32Status;

    u32Status = (UI2C1->PROTSTS);

    (void)u32Status; /*To remove complier warning. The code is unnecessary if u32Status is used.*/

    #if NUCODEGEN_UI2C1_WAKEUP_EN
    if((UI2C1->WKSTS & UI2C_WKSTS_WKF_Msk) == UI2C_WKSTS_WKF_Msk)
    {

        while((UI2C1->PROTSTS & UI2C_PROTSTS_WKAKDONE_Msk) == 0) {};

        /* Clear WK flag */
        UI2C_CLR_WAKEUP_FLAG(UI2C1);
        UI2C1->PROTSTS = UI2C_PROTSTS_WKAKDONE_Msk;

        return;
    }
    #endif /*NUCODEGEN_UI2C1_WAKEUP_EN*/

    if (UI2C_GET_TIMEOUT_FLAG(UI2C1))
    {
        /* Clear USCI_I2C1 Timeout Flag */
        UI2C_ClearTimeoutFlag(UI2C1);

        /*TODO: put user code here*/
    }
    else
    {
        /*TODO: put user code here*/
    }
}

#endif /*NUCODEGEN_UI2C1_INT_EN*/
#endif /*NUCODEGEN_USCI1*/

#if (NUCODEGEN_USCI2_I2C)
#if NUCODEGEN_UI2C2_INT_EN
/*---------------------------------------------------------------------------------------------------------*/
/*  USCI_I2C IRQ Handler                                                                                   */
/*---------------------------------------------------------------------------------------------------------*/
void USCI2_IRQHandler(void)
{
    uint32_t u32Status;

    u32Status = (UI2C2->PROTSTS);

    (void)u32Status; /*To remove complier warning. The code is unnecessary if u32Status is used.*/

    #if NUCODEGEN_UI2C2_WAKEUP_EN
    if((UI2C2->WKSTS & UI2C_WKSTS_WKF_Msk) == UI2C_WKSTS_WKF_Msk)
    {

        while((UI2C2->PROTSTS & UI2C_PROTSTS_WKAKDONE_Msk) == 0) {};

        /* Clear WK flag */
        UI2C_CLR_WAKEUP_FLAG(UI2C2);
        UI2C2->PROTSTS = UI2C_PROTSTS_WKAKDONE_Msk;

        return;
    }
    #endif /*NUCODEGEN_UI2C2_WAKEUP_EN*/

    if (UI2C_GET_TIMEOUT_FLAG(UI2C2))
    {
        /* Clear USCI_I2C2 Timeout Flag */
        UI2C_ClearTimeoutFlag(UI2C2);

        /*TODO: put user code here*/
    }
    else
    {
        /*TODO: put user code here*/
    }
}

#endif /*NUCODEGEN_UI2C2_INT_EN*/
#endif /*NUCODEGEN_USCI2*/


#if (NUCODEGEN_USCI0_UART)
#if (NUCODEGEN_UUART0_INT_ENABLE)
void USCI0_IRQHandler(void)
{
    uint32_t u32IntFlag;
    /* USCI0 is configured as UUART function */
    /* Get UUART interrupt flag */
    u32IntFlag = UUART_GetIntFlag(UUART0, UUART0_INT_CONFIG);

    /* Clear UUART interrupt flag */
    UUART_ClearIntFlag(UUART0, u32IntFlag);

    /* Get UUART wakeup flag */
    if (UUART_GET_WAKEUP_FLAG(UUART0))
    {
        /* Clear UUART wakeup flag */
        UUART_CLR_WAKEUP_FLAG(UUART0);
    }
}
#endif /* NUCODEGEN_UUART0_INT_ENABLE */
#endif /* NUCODEGEN_USCI0_UART*/



#if (NUCODEGEN_USCI1_UART)
#if (NUCODEGEN_UUART1_INT_ENABLE)
void USCI1_IRQHandler(void)
{
    uint32_t u32IntFlag;
    /* USCI1 is configured as UUART function */
    /* Get UUART interrupt flag */
    u32IntFlag = UUART_GetIntFlag(UUART1, UUART1_INT_CONFIG);

    /* Clear UUART interrupt flag */
    UUART_ClearIntFlag(UUART1, u32IntFlag);

    /* Get UUART wakeup flag */
    if (UUART_GET_WAKEUP_FLAG(UUART1))
    {
        /* Clear UUART wakeup flag */
        UUART_CLR_WAKEUP_FLAG(UUART1);
    }
}
#endif /* NUCODEGEN_UUART1_INT_ENABLE */
#endif /* NUCODEGEN_USCI1_UART*/



#if (NUCODEGEN_USCI2_UART)
#if (NUCODEGEN_UUART2_INT_ENABLE)
void USCI2_IRQHandler(void)
{
    uint32_t u32IntFlag;
    /* USCI2 is configured as UUART function */
    /* Get UUART interrupt flag */
    u32IntFlag = UUART_GetIntFlag(UUART2, UUART2_INT_CONFIG);

    /* Clear UUART interrupt flag */
    UUART_ClearIntFlag(UUART2, u32IntFlag);

    /* Get UUART wakeup flag */
    if (UUART_GET_WAKEUP_FLAG(UUART2))
    {
        /* Clear UUART wakeup flag */
        UUART_CLR_WAKEUP_FLAG(UUART2);
    }
}
#endif /* NUCODEGEN_UUART2_INT_ENABLE */
#endif /* NUCODEGEN_USCI2_UART*/

#if (NUCODEGEN_USCI0_SPI)
#if (NUCODEGEN_USPI0_INT_EN)
void USCI0_IRQHandler(void)
{
    uint32_t u32IntFlag;
    /* USCI0 is configured as USPI function */
    /* Get SPI interrupt flag */
    u32IntFlag = USPI_GetIntFlag(USPI0, NUCODEGEN_USPI0_INT_SEL);

    /* Clear USPI interrupt flag */
    USPI_ClearIntFlag(USPI0, u32IntFlag);
}
#endif /* NUCODEGEN_USPI0_INT_EN */
#endif /* NUCODEGEN_USCI0_SPI*/

#if (NUCODEGEN_USCI1_SPI)
#if (NUCODEGEN_USPI1_INT_EN)
void USCI1_IRQHandler(void)
{
    uint32_t u32IntFlag;
    /* USCI0 is configured as USPI function */
    /* Get SPI interrupt flag */
    u32IntFlag = USPI_GetIntFlag(USPI1, NUCODEGEN_USPI1_INT_SEL);

    /* Clear USPI interrupt flag */
    USPI_ClearIntFlag(USPI1, u32IntFlag);
}
#endif /* NUCODEGEN_USPI1_INT_EN */
#endif /* NUCODEGEN_USCI1_SPI */

#if (NUCODEGEN_USCI2_SPI)
#if (NUCODEGEN_USPI2_INT_EN)
void USCI2_IRQHandler(void)
{
    uint32_t u32IntFlag;
    /* USCI0 is configured as USPI function */
    /* Get SPI interrupt flag */
    u32IntFlag = USPI_GetIntFlag(USPI2, NUCODEGEN_USPI2_INT_SEL);

    /* Clear USPI interrupt flag */
    USPI_ClearIntFlag(USPI2, u32IntFlag);
}
#endif /* NUCODEGEN_USPI2_INT_EN */
#endif /* NUCODEGEN_USCI2_SPI*/

#if (NUCODEGEN_USBD)

#if (NUCODEGEN_CLASS_SEL==NUCODEGEN_CLASS_NONE)
#if (NUCODEGEN_USB_INT_EN)
void USBD_IRQHandler(void)
{
    uint32_t u32IntSts = USBD_GET_INT_FLAG();
    uint32_t u32State = USBD_GET_BUS_STATE();

    //------------------------------------------------------------------
    if (u32IntSts & USBD_INTSTS_VBDETIF_Msk)
    {
        // Floating detect
        USBD_CLR_INT_FLAG(USBD_INTSTS_VBDETIF_Msk);

        if (USBD_IS_ATTACHED())
        {
            /* USB Plug In */
            USBD_ENABLE_USB();
        }
        else
        {
            /* USB Un-plug */
            USBD_DISABLE_USB();
        }
    }

    //------------------------------------------------------------------
    if (u32IntSts & USBD_INTSTS_BUSIF_Msk)
    {
        /* Clear event flag */
        USBD_CLR_INT_FLAG(USBD_INTSTS_BUSIF_Msk);

        if (u32State & USBD_STATE_USBRST)
        {
            /* Bus reset */
            USBD_ENABLE_USB();
            USBD_SwReset();
        }

        if (u32State & USBD_STATE_SUSPEND)
        {
            /* Enable USB but disable PHY */
            USBD_DISABLE_PHY();
        }

        if (u32State & USBD_STATE_RESUME)
        {
            /* Enable USB and enable PHY */
            USBD_ENABLE_USB();
        }

#ifdef SUPPORT_LPM

        if (u32State & USBD_STATE_L1SUSPEND)
        {
            /*
               TODO: Implement LPM SUSPEND flag here.
                     Recommend implementing the power-saving function in main loop.
            */
        }

        if (u32State & USBD_STATE_L1RESUME)
        {
            /*
               TODO: Implement LPM RESUME flag here.
            */
        }

#endif
    }

    if (u32IntSts & USBD_INTSTS_NEVWKIF_Msk)
    {
        /*Clear no-event wake up interrupt */
        USBD_CLR_INT_FLAG(USBD_INTSTS_NEVWKIF_Msk);
        /*
           TODO: Implement the function that will be executed when device is woken by non-USB event.
        */
    }

    //------------------------------------------------------------------
    if (u32IntSts & USBD_INTSTS_USBIF_Msk)
    {
        // USB event
        if (u32IntSts & USBD_INTSTS_SETUP_Msk)
        {
            // Setup packet
            /* Clear event flag */
            USBD_CLR_INT_FLAG(USBD_INTSTS_SETUP_Msk);

            /* Clear the data IN/OUT ready flag of control end-points */
            USBD_STOP_TRANSACTION(EP0);
            USBD_STOP_TRANSACTION(EP1);

            USBD_ProcessSetupPacket();
        }

        // EP events
        if (u32IntSts & USBD_INTSTS_EP0)
        {
            /* Clear event flag */
            USBD_CLR_INT_FLAG(USBD_INTSTS_EP0);
            // control IN
            USBD_CtrlIn();
        }

        if (u32IntSts & USBD_INTSTS_EP1)
        {
            /* Clear event flag */
            USBD_CLR_INT_FLAG(USBD_INTSTS_EP1);

            // control OUT
            USBD_CtrlOut();
        }

        if (u32IntSts & USBD_INTSTS_EP2)
        {
            /* Clear event flag */
            USBD_CLR_INT_FLAG(USBD_INTSTS_EP2);
        }

        if (u32IntSts & USBD_INTSTS_EP3)
        {
            /* Clear event flag */
            USBD_CLR_INT_FLAG(USBD_INTSTS_EP3);
        }

        if (u32IntSts & USBD_INTSTS_EP4)
        {
            /* Clear event flag */
            USBD_CLR_INT_FLAG(USBD_INTSTS_EP4);
        }

        if (u32IntSts & USBD_INTSTS_EP5)
        {
            /* Clear event flag */
            USBD_CLR_INT_FLAG(USBD_INTSTS_EP5);
        }

        if (u32IntSts & USBD_INTSTS_EP6)
        {
            /* Clear event flag */
            USBD_CLR_INT_FLAG(USBD_INTSTS_EP6);
        }

        if (u32IntSts & USBD_INTSTS_EP7)
        {
            /* Clear event flag */
            USBD_CLR_INT_FLAG(USBD_INTSTS_EP7);
        }

        if (u32IntSts & USBD_INTSTS_EP8)
        {
            /* Clear event flag */
            USBD_CLR_INT_FLAG(USBD_INTSTS_EP8);
        }

        if (u32IntSts & USBD_INTSTS_EP9)
        {
            /* Clear event flag */
            USBD_CLR_INT_FLAG(USBD_INTSTS_EP9);
        }

        if (u32IntSts & USBD_INTSTS_EP10)
        {
            /* Clear event flag */
            USBD_CLR_INT_FLAG(USBD_INTSTS_EP10);
        }

        if (u32IntSts & USBD_INTSTS_EP11)
        {
            /* Clear event flag */
            USBD_CLR_INT_FLAG(USBD_INTSTS_EP11);
        }
    }
}
#endif /*NUCODEGEN_USB_INT_EN*/
#endif /*NUCODEGEN_CLASS_SEL==NUCODEGEN_CLASS_NONE*/


#if (NUCODEGEN_CLASS_SEL==NUCODEGEN_CLASS_HID)

#if (NUCODEGEN_USB_INT_EN)

void USBD_IRQHandler(void)
{
    uint32_t u32IntSts = USBD_GET_INT_FLAG();
    uint32_t u32State = USBD_GET_BUS_STATE();

    //------------------------------------------------------------------
    if (u32IntSts & USBD_INTSTS_VBDETIF_Msk)
    {
        // Floating detect
        USBD_CLR_INT_FLAG(USBD_INTSTS_VBDETIF_Msk);

        if (USBD_IS_ATTACHED())
        {
            /* USB Plug In */
            USBD_ENABLE_USB();
        }
        else
        {
            /* USB Un-plug */
            USBD_DISABLE_USB();
        }
    }

    //------------------------------------------------------------------
    if (u32IntSts & USBD_INTSTS_BUSIF_Msk)
    {
        /* Clear event flag */
        USBD_CLR_INT_FLAG(USBD_INTSTS_BUSIF_Msk);

        if (u32State & USBD_STATE_USBRST)
        {
            /* Bus reset */
            USBD_ENABLE_USB();
            USBD_SwReset();
        }

        if (u32State & USBD_STATE_SUSPEND)
        {
            /* Enable USB but disable PHY */
            USBD_DISABLE_PHY();
        }

        if (u32State & USBD_STATE_RESUME)
        {
            /* Enable USB and enable PHY */
            USBD_ENABLE_USB();
        }

#ifdef SUPPORT_LPM

        if (u32State & USBD_STATE_L1SUSPEND)
        {
            /*
               TODO: Implement LPM SUSPEND flag here.
                     Recommend implementing the power-saving function in main loop.
            */
        }

        if (u32State & USBD_STATE_L1RESUME)
        {
            /*
               TODO: Implement LPM RESUME flag here.
            */
        }

#endif
    }

    if (u32IntSts & USBD_INTSTS_NEVWKIF_Msk)
    {
        /*Clear no-event wake up interrupt */
        USBD_CLR_INT_FLAG(USBD_INTSTS_NEVWKIF_Msk);
        /*
           TODO: Implement the function that will be executed when device is woken by non-USB event.
        */
    }

    //------------------------------------------------------------------
    if (u32IntSts & USBD_INTSTS_USBIF_Msk)
    {
        // USB event
        if (u32IntSts & USBD_INTSTS_SETUP_Msk)
        {
            // Setup packet
            /* Clear event flag */
            USBD_CLR_INT_FLAG(USBD_INTSTS_SETUP_Msk);

            /* Clear the data IN/OUT ready flag of control end-points */
            USBD_STOP_TRANSACTION(EP0);
            USBD_STOP_TRANSACTION(EP1);

            USBD_ProcessSetupPacket();
        }

        // EP events
        if (u32IntSts & USBD_INTSTS_EP0)
        {
            /* Clear event flag */
            USBD_CLR_INT_FLAG(USBD_INTSTS_EP0);
            // control IN
            USBD_CtrlIn();
        }

        if (u32IntSts & USBD_INTSTS_EP1)
        {
            /* Clear event flag */
            USBD_CLR_INT_FLAG(USBD_INTSTS_EP1);

            // control OUT
            USBD_CtrlOut();
        }

        if (u32IntSts & USBD_INTSTS_EP2)
        {
            /* Clear event flag */
            USBD_CLR_INT_FLAG(USBD_INTSTS_EP2);
            // Interrupt IN
            EP2_Handler();
        }

        if (u32IntSts & USBD_INTSTS_EP3)
        {
            /* Clear event flag */
            USBD_CLR_INT_FLAG(USBD_INTSTS_EP3);
        }

        if (u32IntSts & USBD_INTSTS_EP4)
        {
            /* Clear event flag */
            USBD_CLR_INT_FLAG(USBD_INTSTS_EP4);
        }

        if (u32IntSts & USBD_INTSTS_EP5)
        {
            /* Clear event flag */
            USBD_CLR_INT_FLAG(USBD_INTSTS_EP5);
        }

        if (u32IntSts & USBD_INTSTS_EP6)
        {
            /* Clear event flag */
            USBD_CLR_INT_FLAG(USBD_INTSTS_EP6);
        }

        if (u32IntSts & USBD_INTSTS_EP7)
        {
            /* Clear event flag */
            USBD_CLR_INT_FLAG(USBD_INTSTS_EP7);
        }

        if (u32IntSts & USBD_INTSTS_EP8)
        {
            /* Clear event flag */
            USBD_CLR_INT_FLAG(USBD_INTSTS_EP8);
        }

        if (u32IntSts & USBD_INTSTS_EP9)
        {
            /* Clear event flag */
            USBD_CLR_INT_FLAG(USBD_INTSTS_EP9);
        }

        if (u32IntSts & USBD_INTSTS_EP10)
        {
            /* Clear event flag */
            USBD_CLR_INT_FLAG(USBD_INTSTS_EP10);
        }

        if (u32IntSts & USBD_INTSTS_EP11)
        {
            /* Clear event flag */
            USBD_CLR_INT_FLAG(USBD_INTSTS_EP11);
        }
    }
}

void EP2_Handler(void)  /* Interrupt IN handler */
{
    g_u8EP2Ready = 1;
}

#endif /* NUCODEGEN_USB_INT_EN */

#endif /*NUCODEGEN_CLASS_SEL==NUCODEGEN_CLASS_HID*/

#if (NUCODEGEN_CLASS_SEL==NUCODEGEN_CLASS_MSC)
#if 0
    #define DBG_PRINTF      printf
#else
    #define DBG_PRINTF(...)
#endif

#if (NUCODEGEN_USB_INT_EN)
void USBD_IRQHandler(void)
{
    uint32_t u32IntSts = USBD_GET_INT_FLAG();
    uint32_t u32State = USBD_GET_BUS_STATE();


    //------------------------------------------------------------------
    if (u32IntSts & USBD_INTSTS_FLDET)
    {
        // Floating detect
        USBD_CLR_INT_FLAG(USBD_INTSTS_FLDET);

        if (USBD_IS_ATTACHED())
        {
            /* USB Plug In */
            USBD_ENABLE_USB();
        }
        else
        {
            /* USB Un-plug */
            USBD_DISABLE_USB();
        }
    }

    //------------------------------------------------------------------
    if (u32IntSts & USBD_INTSTS_BUS)
    {
        /* Clear event flag */
        USBD_CLR_INT_FLAG(USBD_INTSTS_BUS);

        if (u32State & USBD_STATE_USBRST)
        {
            /* Bus reset */
            USBD_ENABLE_USB();
            USBD_SwReset();
            DBG_PRINTF("Bus reset\n");
        }

        if (u32State & USBD_STATE_SUSPEND)
        {
            /* Enable USB but disable PHY */
            USBD_DISABLE_PHY();
            DBG_PRINTF("Suspend\n");
        }

        if (u32State & USBD_STATE_RESUME)
        {
            /* Enable USB and enable PHY */
            USBD_ENABLE_USB();
            DBG_PRINTF("Resume\n");
        }

#ifdef SUPPORT_LPM

        if (u32State & USBD_STATE_L1SUSPEND)
        {
            /*
               TODO: Implement LPM SUSPEND flag here.
                     Recommend implementing the power-saving function in main loop.
            */
        }

        if (u32State & USBD_STATE_L1RESUME)
        {
            /*
               TODO: Implement LPM RESUME flag here.
            */
        }

#endif
    }

    if (u32IntSts & USBD_INTSTS_NEVWKIF_Msk)
    {
        /*Clear no-event wake up interrupt */
        USBD_CLR_INT_FLAG(USBD_INTSTS_NEVWKIF_Msk);
        /*
           TODO: Implement the function that will be executed when device is woken by non-USB event.
        */
    }

    //------------------------------------------------------------------
    if (u32IntSts & USBD_INTSTS_USB)
    {
        // USB event
        if (u32IntSts & USBD_INTSTS_SETUP)
        {
            // Setup packet
            /* Clear event flag */
            USBD_CLR_INT_FLAG(USBD_INTSTS_SETUP);

            /* Clear the data IN/OUT ready flag of control end-points */
            USBD_STOP_TRANSACTION(EP0);
            USBD_STOP_TRANSACTION(EP1);

            USBD_ProcessSetupPacket();
        }

        // EP events
        if (u32IntSts & USBD_INTSTS_EP0)
        {
            /* Clear event flag */
            USBD_CLR_INT_FLAG(USBD_INTSTS_EP0);
            // control IN
            USBD_CtrlIn();
        }

        if (u32IntSts & USBD_INTSTS_EP1)
        {
            /* Clear event flag */
            USBD_CLR_INT_FLAG(USBD_INTSTS_EP1);

            // control OUT
            USBD_CtrlOut();
        }

        if (u32IntSts & USBD_INTSTS_EP2)
        {
            /* Clear event flag */
            USBD_CLR_INT_FLAG(USBD_INTSTS_EP2);
            // Bulk IN
            EP2_Handler();
        }

        if (u32IntSts & USBD_INTSTS_EP3)
        {
            /* Clear event flag */
            USBD_CLR_INT_FLAG(USBD_INTSTS_EP3);
            // Bulk OUT
            EP3_Handler();
        }

        if (u32IntSts & USBD_INTSTS_EP4)
        {
            /* Clear event flag */
            USBD_CLR_INT_FLAG(USBD_INTSTS_EP4);
        }

        if (u32IntSts & USBD_INTSTS_EP5)
        {
            /* Clear event flag */
            USBD_CLR_INT_FLAG(USBD_INTSTS_EP5);
        }

        if (u32IntSts & USBD_INTSTS_EP6)
        {
            /* Clear event flag */
            USBD_CLR_INT_FLAG(USBD_INTSTS_EP6);
        }

        if (u32IntSts & USBD_INTSTS_EP7)
        {
            /* Clear event flag */
            USBD_CLR_INT_FLAG(USBD_INTSTS_EP7);
        }

        if (u32IntSts & USBD_INTSTS_EP8)
        {
            /* Clear event flag */
            USBD_CLR_INT_FLAG(USBD_INTSTS_EP8);
        }

        if (u32IntSts & USBD_INTSTS_EP9)
        {
            /* Clear event flag */
            USBD_CLR_INT_FLAG(USBD_INTSTS_EP9);
        }

        if (u32IntSts & USBD_INTSTS_EP10)
        {
            /* Clear event flag */
            USBD_CLR_INT_FLAG(USBD_INTSTS_EP10);
        }

        if (u32IntSts & USBD_INTSTS_EP11)
        {
            /* Clear event flag */
            USBD_CLR_INT_FLAG(USBD_INTSTS_EP11);
        }

    }
}


void EP2_Handler(void)
{
    g_u8EP2Ready = 1;
    MSC_AckCmd();
}


void EP3_Handler(void)
{
    /* Bulk OUT */
    g_u8EP3Ready = 1;
}
#endif /*NUCODEGEN_USB_INT_EN*/

#endif /*NUCODEGEN_CLASS_SEL==NUCODEGEN_CLASS_MSC*/
#endif /*NUCODEGEN_USBD*/

#if (NUCODEGEN_SC0)
#if (NUCODEGEN_SC0_SUBMODE_SEL==NUCODEGEN_SC0_SUBMODE_SC)
void SC0_IRQHandler(void)
{
    /* Please don't remove any of the function calls below               */
    /* Card insert/remove event occurred, no need to check other event...*/
    if (SCLIB_CheckCDEvent(SC_INTF))
        return;

    /* Check if there's any timeout event occurs. If so, it usually indicates an error */
    SCLIB_CheckTimeOutEvent(SC_INTF);

    /* Check transmit and receive interrupt, all data transmission take place in this function*/
    SCLIB_CheckTxRxEvent(SC_INTF);

    /*
        Check if there's any transmission error occurred (e.g. parity error, frame error...)
        These errors will induce SCLIB to deactivation smartcard eventually.
    */
    SCLIB_CheckErrorEvent(SC_INTF);

    return;
}
#endif /*NUCODEGEN_SC0_SUBMODE_SEL==NUCODEGEN_SC0_SUBMODE_SC*/

#if (NUCODEGEN_SC0_SUBMODE_SEL==NUCODEGEN_SC0_SUBMODE_SCUART)
#if (NUCODEGEN_SC0_INT_EN)
void SC0_IRQHandler(void)
{
    uint32_t u32intsts;
    u32intsts = SC0->INTSTS;

    if(u32intsts & SC_INTSTS_TERRIF_Msk) {
        /*TODO: add user code here here*/
    }

    if(u32intsts & SC_INTSTS_TBEIF_Msk) {
        /*TODO: add user code here here*/
    }

    if(u32intsts & SC_INTSTS_RDAIF_Msk) {
        /*TODO: add user code here here*/
    }

    if(u32intsts & SC_INTSTS_RXTOIF_Msk){
        /*TODO: add user code here here*/
    }

    return;
}
#endif /*NUCODEGEN_SC0_INT_EN*/

#endif /*NUCODEGEN_SC0_SUBMODE_SEL==NUCODEGEN_SC0_SUBMODE_SCUART*/
#endif /*NUCODEGEN_SC0*/

#if (NUCODEGEN_PDMA_CH0 || NUCODEGEN_PDMA_CH1 || NUCODEGEN_PDMA_CH2 || NUCODEGEN_PDMA_CH3 || NUCODEGEN_PDMA_CH4 || NUCODEGEN_PDMA_CH5 || NUCODEGEN_PDMA_CH6 || NUCODEGEN_PDMA_CH7 )
#if (NUCODEGEN_PDMA_CH0_INT || NUCODEGEN_PDMA_CH1_INT || NUCODEGEN_PDMA_CH2_INT || NUCODEGEN_PDMA_CH3_INT || NUCODEGEN_PDMA_CH4_INT || NUCODEGEN_PDMA_CH5_INT \
    || NUCODEGEN_PDMA_CH6_INT || NUCODEGEN_PDMA_CH7_INT )
void PDMA_IRQHandler(void)
{
    uint32_t u32Status = PDMA_GET_INT_STATUS(PDMA);

    if (u32Status & PDMA_INTSTS_TDIF_Msk)     /* done */
    {
        /* Transfer done */
    }
    else
        printf("Unexpected interrupt !!\n");
}
#endif  //NUCODEGEN_PDMA_CH0_INT || NUCODEGEN_PDMA_CH1_INT || NUCODEGEN_PDMA_CH2_INT || NUCODEGEN_PDMA_CH3_INT || NUCODEGEN_PDMA_CH4_INT || NUCODEGEN_PDMA_CH5_INT || NUCODEGEN_PDMA_CH6_INT || NUCODEGEN_PDMA_CH7_INT
#endif  //NUCODEGEN_PDMA_CH0 || NUCODEGEN_PDMA_CH1 || NUCODEGEN_PDMA_CH2 || NUCODEGEN_PDMA_CH3 || NUCODEGEN_PDMA_CH4 || NUCODEGEN_PDMA_CH5 || NUCODEGEN_PDMA_CH6 || NUCODEGEN_PDMA_CH7

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


#if (NUCODEGEN_RTC)
#if (NUCODEGEN_RTC_INT_ENABLE)
void RTC_IRQHandler(void)
{
    /* Get RTC Tick Interrupt Flag */
    if (RTC_GET_TICK_INT_FLAG())
    {
        /* Clear RTC Tick Interrupt Flag */
        RTC_CLEAR_TICK_INT_FLAG();
    }

    /* Get RTC Alarm Interrupt Flag */
    if (RTC_GET_ALARM_INT_FLAG())
    {
        /* Clear RTC Alarm Interrupt Flag */
        RTC_CLEAR_ALARM_INT_FLAG();
    }

    /* Get RTC Tamper Interrupt Flag */
    if (RTC_GET_TAMPER_INT_FLAG())
    {
        /* Clear RTC Tamper Interrupt Flag */
        RTC_CLEAR_TAMPER_INT_FLAG(RTC_INTSTS_TAMP0IF_Msk);
    }
}
#endif /* NUCODEGEN_RTC_INT_ENABLE */
#endif /* NUCODEGEN_RTC */

#if (NUCODEGEN_WDT)
#if (NUCODEGEN_WDT_INT_ENABLE)
void WDT_IRQHandler(void)
{
    /* Get WDT Time-out interrupt flag */
    if (WDT_GET_TIMEOUT_INT_FLAG())
    {
        /* Clear WDT time-out interrupt flag */
        WDT_CLEAR_TIMEOUT_INT_FLAG();
    }

    /* Get WDT time-out wakeup  flag */
    if (WDT_GET_TIMEOUT_WAKEUP_FLAG())
    {
        /* Clear WDT time-out wakeup  flag */
        WDT_CLEAR_TIMEOUT_WAKEUP_FLAG();
    }

    /* To prevent system from reset by WDT, it is necessary to clear WDT counter
       by software before WDT counter reaches the reset delay time after time-out occurs. */
    WDT_RESET_COUNTER();
}
#endif /* NUCODEGEN_WDT_INT_ENABLE*/
#endif /* NUCODEGEN_WDT */


#if (NUCODEGEN_WWDT)
#if (NUCODEGEN_WWDT_INT_ENABLE)
void WWDT_IRQHandler(void)
{
    /* Get WWDT interrupt flag */
    if (WWDT_GET_INT_FLAG())
    {
        /* Clear WWDT interrupt flag */
        WWDT_CLEAR_INT_FLAG();
    }

    /* To prevent system from reset by WWDT, it is necessary to reload WWDT counter
       by software before WWDT counter reaches zero. */
    WWDT_RELOAD_COUNTER();
}
#endif /* NUCODEGEN_WWDT_INT_ENABLE */
#endif /* NUCODEGEN_WWDT */



#if (NUCODEGEN_DAC)
#if (NUCODEGEN_DAC_INT_EN)
void DAC_IRQHandler(void)
{
    /* Check DAC interrupt flag is rising */
    if (DAC_GET_INT_FLAG(NUCODEGEN_DAC_MODULE_SEL, DAC_MODULE_0))
    {
       /* Clear DAC interrupt flag */
       DAC_CLR_INT_FLAG(NUCODEGEN_DAC_MODULE_SEL, DAC_MODULE_0);

       /* insert next convert data of DAC. Ex: DAC_WRITE_DATA(DAC, 0, 0xFF); */

    }
}
#endif /* NUCODEGEN_DAC_INT_EN */
#endif /* NUCODEGEN_DAC */


#if (NUCODEGEN_EADC)

#if (((NUCODEGEN_EADCINT)&0x1) == 0x1)
void EADC_INT0_IRQHandler(void)
{
    if(EADC_GET_INT_FLAG(NUCODEGEN_EADC_MODULE_SEL, EADC_STATUS2_ADIF0_Msk))
    {
       /* Clear the A/D ADINT0 interrupt flag */
       EADC_CLR_INT_FLAG(NUCODEGEN_EADC_MODULE_SEL, EADC_STATUS2_ADIF0_Msk);
       printf("ADINT0 interrupt occurred !\n");

       /* get convert result, trigger next sample module, ..etc*/
    }
}
#endif /* (((NUCODEGEN_EADCINT)&0x1) == 0x1) */


#if (((NUCODEGEN_EADCINT)&0x2) == 0x2)
void EADC_INT1_IRQHandler(void)
{
    if(EADC_GET_INT_FLAG(NUCODEGEN_EADC_MODULE_SEL, EADC_STATUS2_ADIF1_Msk))
    {
       /* Clear the A/D ADINT1 interrupt flag */
       EADC_CLR_INT_FLAG(NUCODEGEN_EADC_MODULE_SEL, EADC_STATUS2_ADIF1_Msk);
       printf("ADINT1 interrupt occurred !\n");

       /* get convert result, trigger next sample module, ..etc*/
    }
}
#endif /* (((NUCODEGEN_EADCINT)&0x2) == 0x2) */


#if (((NUCODEGEN_EADCINT)&0x4) == 0x4)
void EADC_INT2_IRQHandler(void)
{
    if(EADC_GET_INT_FLAG(NUCODEGEN_EADC_MODULE_SEL, EADC_STATUS2_ADIF2_Msk))
    {
       /* Clear the A/D ADINT2 interrupt flag */
       EADC_CLR_INT_FLAG(NUCODEGEN_EADC_MODULE_SEL, EADC_STATUS2_ADIF2_Msk);
       printf("ADINT2 interrupt occurred !\n");

       /* get convert result, trigger next sample module, ..etc*/
    }
}
#endif /* (((NUCODEGEN_EADCINT)&0x4) == 0x4) */

#if (((NUCODEGEN_EADCINT)&0x8) == 0x8)
void EADC_INT3_IRQHandler(void)
{
    if(EADC_GET_INT_FLAG(NUCODEGEN_EADC_MODULE_SEL, EADC_STATUS2_ADIF3_Msk))
    {
       /* Clear the A/D ADINT3 interrupt flag */
       EADC_CLR_INT_FLAG(NUCODEGEN_EADC_MODULE_SEL, EADC_STATUS2_ADIF3_Msk);
       printf("ADINT3 interrupt occurred !\n");

       /* get convert result, trigger next sample module, ..etc*/
    }
#if (NUCODEGEN_EADCCMP0CMPINT)
    else if(EADC_GET_INT_FLAG(NUCODEGEN_EADC_MODULE_SEL, EADC_STATUS2_ADCMPF0_Msk))
    {
       /* Clear the A/D Compare0 interrupt flag */
       EADC_CLR_INT_FLAG(NUCODEGEN_EADC_MODULE_SEL, EADC_STATUS2_ADCMPF0_Msk);
       printf("ADCMPF0 interrupt occurred !\n");
    }
#endif /* NUCODEGEN_EADCCMP0CMPINT */
#if (NUCODEGEN_EADCCMP1CMPINT)
    else if(EADC_GET_INT_FLAG(NUCODEGEN_EADC_MODULE_SEL, EADC_STATUS2_ADCMPF1_Msk))
    {
       /* Clear the A/D Compare1 interrupt flag */
       EADC_CLR_INT_FLAG(NUCODEGEN_EADC_MODULE_SEL, EADC_STATUS2_ADCMPF1_Msk);
       printf("ADCMPF1 interrupt occurred !\n");
    }
#endif /* NUCODEGEN_EADCCMP1CMPINT */
#if (NUCODEGEN_EADCCMP2CMPINT)
    else if(EADC_GET_INT_FLAG(NUCODEGEN_EADC_MODULE_SEL, EADC_STATUS2_ADCMPF2_Msk))
    {
       /* Clear the A/D Compare2 interrupt flag */
       EADC_CLR_INT_FLAG(NUCODEGEN_EADC_MODULE_SEL, EADC_STATUS2_ADCMPF2_Msk);
       printf("ADCMPF2 interrupt occurred !\n");
    }
#endif /* NUCODEGEN_EADCCMP2CMPINT */
#if (NUCODEGEN_EADCCMP3CMPINT)
    else if(EADC_GET_INT_FLAG(NUCODEGEN_EADC_MODULE_SEL, EADC_STATUS2_ADCMPF3_Msk))
    {
       /* Clear the A/D Compare3 interrupt flag */
       EADC_CLR_INT_FLAG(NUCODEGEN_EADC_MODULE_SEL, EADC_STATUS2_ADCMPF3_Msk);
       printf("ADCMPF3 interrupt occurred !\n");
    }
#endif /* NUCODEGEN_EADCCMP3CMPINT */
}
#endif /* (((NUCODEGEN_EADCINT)&0x8) == 0x8) */

#endif /* NUCODEGEN_EADC */


#if (NUCODEGEN_OPA)
#if (NUCODEGEN_OPA_INT_EN)
void OPA_IRQHandler(void)
{
    /* Check OPA interrupt flag is rising */
    if (OPA_GET_INT_FLAG(NUCODEGEN_OPA_MODULE_SEL, OPA_MODULE_0))
    {
       /* Clear OPA interrupt flag */
       OPA_CLR_INT_FLAG(NUCODEGEN_OPA_MODULE_SEL, OPA_MODULE_0);

       /* insert digital output of OPA. Ex: OPA_GET_DIGITAL_OUTPUT(OPA, 0); */

    }
}
#endif /* NUCODEGEN_OPA_INT_EN */
#endif /* NUCODEGEN_OPA */

#if (NUCODEGEN_ACMP)
#if (NUCODEGEN_ACMP0_INT_EN || NUCODEGEN_ACMP1_INT_EN)
void ACMP01_IRQHandler(void)
{
#if (NUCODEGEN_ACMP0_INT_EN)
    /* Check ACMP0 interrupt flag is rising */
    if (ACMP_GET_INT_FLAG(NUCODEGEN_ACMP_MODULE_SEL, ACMP_MODULE_0))
    {
        /* Clear ACMP 0 interrupt flag */
        ACMP_CLR_INT_FLAG(NUCODEGEN_ACMP_MODULE_SEL, ACMP_MODULE_0);

       /* insert get output data of ACMP0. Ex: ACMP_GET_OUTPUT(ACMP01, 0); */

    }
#endif /* NUCODEGEN_ACMP0_INT_EN */

#if (NUCODEGEN_ACMP0_WKP_EN)

      /* Clear ACMP 0 wake up interrupt flag */
      ACMP_CLR_WAKEUP_INT_FLAG(NUCODEGEN_ACMP_MODULE_SEL,ACMP_MODULE_0);

#endif /* NUCODEGEN_ACMP0_WKP_EN */

#if (NUCODEGEN_ACMP1_INT_EN)
    /* Check ACMP1 interrupt flag is rising */
    if (ACMP_GET_INT_FLAG(NUCODEGEN_ACMP_MODULE_SEL, ACMP_MODULE_1))
    {
       /* Clear ACMP 1 interrupt flag */
       ACMP_CLR_INT_FLAG(NUCODEGEN_ACMP_MODULE_SEL, ACMP_MODULE_1);

       /* insert get output data of ACMP1. Ex: ACMP_GET_OUTPUT(ACMP01, 1); */

    }
#endif /* NUCODEGEN_ACMP1_INT_EN */

#if (NUCODEGEN_ACMP1_WKP_EN)
     /* Clear ACMP 1 wake up interrupt flag */
     ACMP_CLR_WAKEUP_INT_FLAG(NUCODEGEN_ACMP_MODULE_SEL,ACMP_MODULE_1);

#endif /* NUCODEGEN_ACMP1_WKP_EN */

}
#endif /* (NUCODEGEN_ACMP0_INT_EN || NUCODEGEN_ACMP1_INT_EN) */
#endif /* NUCODEGEN_OPA */

#if (NUCODEGEN_QSPI)
#if (NUCODEGEN_QSPI_INT_EN)
void QSPI0_IRQHandler(void)
{
    uint32_t u32IntFlag;

    u32IntFlag = QSPI_GetIntFlag(QSPI0, NUCODEGEN_QSPI_INT_SEL);
    if(u32IntFlag){
        printf("0x%x\n", u32IntFlag);
    }

}
#endif //NUCODEGEN_QSPI_INT_EN
#endif //NUCODEGEN_QSPI

#if (NUCODEGEN_SPII2S)
#if ((NUCODEGEN_SPI_INT_EN) || (NUCODEGEN_I2S_INT_EN))
void SPI0_IRQHandler(void)
{
    uint32_t u32IntFlag;
#if(NUCODEGEN_SPII2S_MODE==NUCODEGEN_SPI_MODE)
#if (NUCODEGEN_SPI_INT_EN)
    u32IntFlag = SPI_GetIntFlag(SPI0, NUCODEGEN_SPI_INT_SEL);
    if(u32IntFlag){
        printf("SPI INT Flag:0x%x\n", u32IntFlag);
    }else{
        printf("Unknown INT occurred!\n");
    }
#endif //NUCODEGEN_SPI_INT_EN
#else
#if (NUCODEGEN_I2S_INT_EN)
    u32IntFlag = SPI0->I2SSTS;
    SPI0->I2SSTS = u32IntFlag;
    if(u32IntFlag){
        printf("I2S INT Flag:0x%x\n", u32IntFlag);
    }else{
        printf("Unknown INT occurred!\n");
    }
#endif //NUCODEGEN_I2S_INT_EN
#endif  //NUCODEGEN_SPII2S_MODE
}
#endif //NUCODEGEN_SPII2S_INT_EN
#endif //NUCODEGEN_SPII2S

