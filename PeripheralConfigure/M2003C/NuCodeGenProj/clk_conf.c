/****************************************************************************
 * @file     clk_conf.c
 * @version  V0.41
 * @Date     2021/05/04-16:18:32
 * @brief    NuMicro generated code file
 *
 * SPDX-License-Identifier: Apache-2.0 
 * Copyright (C) 2023 Nuvoton Technology Corp. All rights reserved.
*****************************************************************************/

/********************
MCU:M2003FC1AE(LQFP128)
Base Clocks:
LIRC:10.0kHz
HIRC:24MHz
HCLK:24MHz
PCLK0:24MHz
PCLK1:24MHz
Enabled-Module Frequencies:
ISP=Bus Clock(HCLK):24MHz/Engine Clock:24MHz
TMR0=Bus Clock(PCLK0):24MHz/Engine Clock:24MHz
TMR1=Bus Clock(PCLK0):24MHz/Engine Clock:24MHz
TMR2=Bus Clock(PCLK1):24MHz/Engine Clock:24MHz
TMR3=Bus Clock(PCLK1):24MHz/Engine Clock:24MHz
UART0=Bus Clock(PCLK0):24MHz/Engine Clock:24MHz
********************/

#include "NuCodeGenProj.h"

/*----------------------------------------------------------------------------
  Define HXT clock.
  Please locate and modify the real one in your project.
  Otherwise, the project may fail to build.
 *----------------------------------------------------------------------------*/
#define __HXT         (32000000UL)  /*!< High Speed External Crystal Clock Frequency */

/*
 * @brief This function updates clock registers to fulfill the configuration
 * @param None
 * @return None
 */
void Clock_Init()
{
    /*---------------------------------------------------------------------------------------------------------*/
    /* Init System Clock                                                                                       */
    /*---------------------------------------------------------------------------------------------------------*/
    //CLK->PWRCTL = (CLK->PWRCTL & ~(0x0000000FUL)) | 0x0231001FUL;
    //CLK->PLLCTL = (CLK->PLLCTL & ~(0x000FFFFFUL)) | 0x0005C25EUL;
    //CLK->CLKDIV0 = (CLK->CLKDIV0 & ~(0x00FFFFFFUL)) | 0x00000000UL;
    //CLK->CLKDIV4 = (CLK->CLKDIV4 & ~(0x00FFFFFFUL)) | 0x00000000UL;
    //CLK->PCLKDIV = (CLK->PCLKDIV & ~(0x00000077UL)) | 0x00000000UL;
    //CLK->CLKSEL0 = (CLK->CLKSEL0 & ~(0x0000013FUL)) | 0x0000003FUL;
    //CLK->CLKSEL1 = (CLK->CLKSEL1 & ~(0x7777777FUL)) | 0x4477773BUL;
    //CLK->CLKSEL2 = (CLK->CLKSEL2 & ~(0x0030033FUL)) | 0x0020032BUL;
    //CLK->CLKSEL3 = (CLK->CLKSEL3 & ~(0x77777700UL)) | 0x44444400UL;
    //CLK->AHBCLK = (CLK->AHBCLK & ~(0x0000009EUL)) | 0x00000004UL;
    //CLK->APBCLK0 = (CLK->APBCLK0 & ~(0x18FF33FFUL)) | 0x00010001UL;
    //CLK->APBCLK1 = (CLK->APBCLK1 & ~(0x000F0300UL)) | 0x00000000UL;
    //CLK->CLKOCTL = (CLK->CLKOCTL & ~(0x0000007FUL)) | 0x00000000UL;
    //SysTick->CTRL = (SysTick->CTRL & ~(0x00000005UL)) | 0x00000000UL;
    //RTC->LXTCTL = (RTC->LXTCTL & ~(0x00000080UL)) | 0x00000000UL;

    /* Unlock protected registers */
    SYS_UnlockReg();

    /* Enable clock source */
    CLK_EnableXtalRC(CLK_PWRCTL_LIRCEN_Msk|CLK_PWRCTL_HIRCEN_Msk);

    /* Waiting for clock source ready */
    CLK_WaitClockReady(CLK_STATUS_LIRCSTB_Msk|CLK_STATUS_HIRCSTB_Msk);

    /* Disable PLL first to avoid unstable when setting PLL */
    CLK_DisablePLL();

    /* If the defines do not exist in your project, please refer to the related clk.h in the Header folder appended to the tool package. */
    /* Set HCLK clock */
    CLK_SetHCLK(CLK_CLKSEL0_HCLKSEL_HIRC, CLK_CLKDIV0_HCLK(1));

    /* Set PCLK-related clock */
    CLK->PCLKDIV = (CLK_PCLKDIV_APB0DIV_DIV1 | CLK_PCLKDIV_APB1DIV_DIV1);

    /* Enable IP clock */
    CLK_EnableModuleClock(ADC_MODULE);
    CLK_EnableModuleClock(ECAP0_MODULE);
    CLK_EnableModuleClock(I2C0_MODULE);
    CLK_EnableModuleClock(ISP_MODULE);
    CLK_EnableModuleClock(PWM0_MODULE);
//    CLK_EnableModuleClock(RTC_MODULE);
    CLK_EnableModuleClock(TMR0_MODULE);
    CLK_EnableModuleClock(TMR1_MODULE);
    CLK_EnableModuleClock(TMR2_MODULE);
    CLK_EnableModuleClock(TMR3_MODULE);
    CLK_EnableModuleClock(UART0_MODULE);
    CLK_EnableModuleClock(UART1_MODULE);
    CLK_EnableModuleClock(USCI0_MODULE);
    CLK_EnableModuleClock(WDT_MODULE);
    CLK_EnableModuleClock(WWDT_MODULE);

    /* Set IP clock */
    CLK_SetModuleClock(ADC_MODULE, MODULE_NoMsk, CLK_CLKDIV0_ADC(1));    
    CLK_SetModuleClock(PWM0_MODULE, CLK_CLKSEL2_PWM0SEL_PCLK0, MODULE_NoMsk);
    CLK_SetModuleClock(TMR0_MODULE, CLK_CLKSEL1_TMR0SEL_PCLK0, MODULE_NoMsk);
    CLK_SetModuleClock(TMR1_MODULE, CLK_CLKSEL1_TMR1SEL_PCLK0, MODULE_NoMsk);
    CLK_SetModuleClock(TMR2_MODULE, CLK_CLKSEL1_TMR2SEL_PCLK1, MODULE_NoMsk);
    CLK_SetModuleClock(TMR3_MODULE, CLK_CLKSEL1_TMR3SEL_PCLK1, MODULE_NoMsk);
    CLK_SetModuleClock(UART0_MODULE, CLK_CLKSEL2_UART0SEL_HIRC, CLK_CLKDIV0_UART0(1));
    CLK_SetModuleClock(UART1_MODULE, CLK_CLKSEL2_UART1SEL_HIRC, CLK_CLKDIV0_UART1(1));
    CLK_SetModuleClock(WDT_MODULE, CLK_CLKSEL1_WDTSEL_LIRC, MODULE_NoMsk);
    CLK_SetModuleClock(WWDT_MODULE, CLK_CLKSEL1_WWDTSEL_HCLK_DIV2048, MODULE_NoMsk);

    /* Update System Core Clock */
    /* User can use SystemCoreClockUpdate() to calculate SystemCoreClock. */
    SystemCoreClockUpdate();

    return;
}

/*** (C) COPYRIGHT 2016-2019 Nuvoton Technology Corp. ***/
