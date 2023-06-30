/****************************************************************************
 * @file     clk_conf.c
 * @version  V0.00
 * @Date     2019/03/28-12:06:28
 * @brief    NuMicro generated code file
 *
 * Copyright (C) 2016-2019 Nuvoton Technology Corp. All rights reserved.
*****************************************************************************/

/********************
MCU:M252KG6AE(LQFP128)
Base Clocks:
LIRC:38.4000kHz
HIRC:48MHz
MIRC:4MHz
LXT:32.7680kHz
HXT:12MHz
PLL:48MHz
HCLK:48MHz
PCLK0:48MHz
PCLK1:48MHz
Enabled-Module Frequencies:
FMCIDLE=Bus Clock(HCLK):48MHz
ISP=Bus Clock(HCLK):48MHz/Engine Clock:48MHz
TMR0=Bus Clock(PCLK0):48MHz/Engine Clock:48MHz
TMR1=Bus Clock(PCLK0):48MHz/Engine Clock:48MHz
TMR2=Bus Clock(PCLK1):48MHz/Engine Clock:48MHz
TMR3=Bus Clock(PCLK1):48MHz/Engine Clock:48MHz
UART0=Bus Clock(PCLK0):48MHz/Engine Clock:48MHz
********************/

#include "NuCodeGenProj.h"

/*----------------------------------------------------------------------------
  Define HXT clock.
  Please locate and modify the real one in your project.
  Otherwise, the project may fail to build.
 *----------------------------------------------------------------------------*/
#define __HXT         (12000000UL)  /*!< High Speed External Crystal Clock Frequency */

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
    //CLK->PWRCTL = (CLK->PWRCTL & ~(0x0008000Ful)) | 0x0079001Ful;
    //CLK->PLLCTL = (CLK->PLLCTL & ~(0x019FDE3Ful)) | 0x00084410ul;
    //CLK->CLKDIV0 = (CLK->CLKDIV0 & ~(0x00FFFFFFul)) | 0x00000000ul;
    //CLK->CLKDIV1 = (CLK->CLKDIV1 & ~(0xFF0000FFul)) | 0x00000000ul;
    //CLK->CLKDIV4 = (CLK->CLKDIV4 & ~(0x0000000Ful)) | 0x00000000ul;
    //CLK->PCLKDIV = (CLK->PCLKDIV & ~(0x00000077ul)) | 0x00000000ul;
    //CLK->CLKSEL0 = (CLK->CLKSEL0 & ~(0x0000013Ful)) | 0x0000003Aul;
    //CLK->CLKSEL1 = (CLK->CLKSEL1 & ~(0x7777777Ful)) | 0x4422223Bul;
    //CLK->CLKSEL2 = (CLK->CLKSEL2 & ~(0x7000033Ful)) | 0x2000032Bul;
    //CLK->CLKSEL3 = (CLK->CLKSEL3 & ~(0x07000003ul)) | 0x04000003ul;
    //CLK->AHBCLK = (CLK->AHBCLK & ~(0x0000908Eul)) | 0x00008004ul;
    //CLK->APBCLK0 = (CLK->APBCLK0 & ~(0x180733FFul)) | 0x0001003Cul;
    //CLK->APBCLK1 = (CLK->APBCLK1 & ~(0xC00F1701ul)) | 0x00000000ul;
    //CLK->CLKOCTL = (CLK->CLKOCTL & ~(0x0000007Ful)) | 0x00000000ul;
    //SysTick->CTRL = (SysTick->CTRL & ~(0x00000005ul)) | 0x00000000ul;
    //CLK->RTC_LXTCTL = (CLK->RTC_LXTCTL & ~(0x00000100ul)) | 0x780F010Eul;

    /* Unlock protected registers */
    //SYS_UnlockReg();

    /* Enable clock source */
    CLK_EnableXtalRC(CLK_PWRCTL_LIRCEN_Msk|CLK_PWRCTL_HIRCEN_Msk|CLK_PWRCTL_MIRCEN_Msk|CLK_PWRCTL_LXTEN_Msk|CLK_PWRCTL_HXTEN_Msk);

    /* Waiting for clock source ready */
    CLK_WaitClockReady(CLK_STATUS_LIRCSTB_Msk|CLK_STATUS_HIRCSTB_Msk|CLK_STATUS_MIRCSTB_Msk|CLK_STATUS_LXTSTB_Msk|CLK_STATUS_HXTSTB_Msk);

    /* Disable PLL first to avoid unstable when setting PLL */
    CLK_DisablePLL();

    /* Set PLL frequency */
    CLK->PLLCTL = (CLK->PLLCTL & ~(0x019FDE3Ful)) | 0x00084410ul;

    /* Waiting for PLL ready */
    CLK_WaitClockReady(CLK_STATUS_PLLSTB_Msk);

    /* If the defines do not exist in your project, please refer to the related clk.h in the Header folder appended to the tool package. */
    /* Set HCLK clock */
    CLK_SetHCLK(CLK_CLKSEL0_HCLKSEL_PLL, CLK_CLKDIV0_HCLK(1));

    /* Set PCLK-related clock */
    CLK->PCLKDIV = (CLK_PCLKDIV_APB0DIV_DIV1 | CLK_PCLKDIV_APB1DIV_DIV1);

    /* Enable IP clock */
    CLK_EnableModuleClock(FMCIDLE_MODULE);
    CLK_EnableModuleClock(ISP_MODULE);
    CLK_EnableModuleClock(TMR0_MODULE);
    CLK_EnableModuleClock(TMR1_MODULE);
    CLK_EnableModuleClock(TMR2_MODULE);
    CLK_EnableModuleClock(TMR3_MODULE);
    CLK_EnableModuleClock(UART0_MODULE);

    /* Set IP clock */
    CLK_SetModuleClock(TMR0_MODULE, CLK_CLKSEL1_TMR0SEL_PCLK0, MODULE_NoMsk);
    CLK_SetModuleClock(TMR1_MODULE, CLK_CLKSEL1_TMR1SEL_PCLK0, MODULE_NoMsk);
    CLK_SetModuleClock(TMR2_MODULE, CLK_CLKSEL1_TMR2SEL_PCLK1, MODULE_NoMsk);
    CLK_SetModuleClock(TMR3_MODULE, CLK_CLKSEL1_TMR3SEL_PCLK1, MODULE_NoMsk);
    CLK_SetModuleClock(UART0_MODULE, CLK_CLKSEL1_UART0SEL_PCLK0, CLK_CLKDIV0_UART0(1));

    /* Update System Core Clock */
    /* User can use SystemCoreClockUpdate() to calculate SystemCoreClock. */
    SystemCoreClockUpdate();

    /* Lock protected registers */
    //SYS_LockReg();

    return;
}

/*** (C) COPYRIGHT 2016-2019 Nuvoton Technology Corp. ***/
