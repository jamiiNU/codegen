/****************************************************************************
 * @file     clk_conf.c
 * @version  V0.41
 * @Date     2021/05/06-09:00:40
 * @brief    NuMicro generated code file
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Copyright (C) 2016-2021 Nuvoton Technology Corp. All rights reserved.
*****************************************************************************/

/********************
MCU:NUC1262SE4AE(LQFP64)
Base Clocks:
LIRC:10kHz
HIRC:48MHz
LXT:32.7680kHz
HXT:12MHz
PLL:24MHz
HCLK:48MHz
PCLK0:48MHz
PCLK1:48MHz
Enabled-Module Frequencies:
ADC=Bus Clock(PCLK0):48MHz/Engine Clock:24MHz
BPWM0=Bus Clock(PCLK0):48MHz
BPWM1=Bus Clock(PCLK0):48MHz
BPWM2=Bus Clock(PCLK0):48MHz
BPWM3=Bus Clock(PCLK0):48MHz
CLKO=Bus Clock(HCLK):48MHz/Engine Clock:48MHz
CRC=Bus Clock(HCLK):48MHz
GPIOA=Bus Clock(HCLK):48MHz
GPIOB=Bus Clock(HCLK):48MHz
GPIOC=Bus Clock(HCLK):48MHz
GPIOD=Bus Clock(HCLK):48MHz
GPIOF=Bus Clock(HCLK):48MHz
I2C0=Bus Clock(PCLK0):48MHz
I2C1=Bus Clock(PCLK0):48MHz
ISP=Bus Clock(HCLK):48MHz/Engine Clock:48MHz
LLSI0=Bus Clock(PCLK0):48MHz
LLSI1=Bus Clock(PCLK1):48MHz
LLSI2=Bus Clock(PCLK0):48MHz
LLSI3=Bus Clock(PCLK1):48MHz
LLSI4=Bus Clock(PCLK0):48MHz
LLSI5=Bus Clock(PCLK1):48MHz
LLSI6=Bus Clock(PCLK0):48MHz
LLSI7=Bus Clock(PCLK1):48MHz
LLSI8=Bus Clock(PCLK0):48MHz
LLSI9=Bus Clock(PCLK1):48MHz
PDMA=Bus Clock(HCLK):48MHz
SPI0=Bus Clock(PCLK0):48MHz/Engine Clock:12MHz
SPI1=Bus Clock(PCLK0):48MHz/Engine Clock:12MHz
SYSTICK=Bus Clock(HCLK):48MHz/Engine Clock:12MHz
TMR0=Bus Clock(PCLK0):48MHz/Engine Clock:24MHz
TMR1=Bus Clock(PCLK0):48MHz/Engine Clock:24MHz
TMR2=Bus Clock(PCLK0):48MHz/Engine Clock:24MHz
TMR3=Bus Clock(PCLK0):48MHz/Engine Clock:24MHz
UART0=Bus Clock(PCLK0):48MHz/Engine Clock:24MHz
UART1=Bus Clock(PCLK0):48MHz/Engine Clock:24MHz
USBD=Bus Clock(PCLK0):48MHz/Engine Clock:48MHz
WDT=Bus Clock(PCLK0):48MHz/Engine Clock:10kHz
WWDT=Bus Clock(PCLK0):48MHz/Engine Clock:23.4375kHz
********************/

#include "NuCodeGenProj.h"

/*
 * @brief This function updates clock registers to fulfill the configuration
 * @param None
 * @return None
 */
void Clock_Init(void)
{
    /*---------------------------------------------------------------------------------------------------------*/
    /* Init System Clock                                                                                       */
    /*---------------------------------------------------------------------------------------------------------*/
    //CLK->PWRCTL = (CLK->PWRCTL & ~(0x0000000FUL)) | 0x0000001FUL;
    //CLK->PLLCTL = (CLK->PLLCTL & ~(0x000FFFFFUL)) | 0x008A0012UL;
    //CLK->CLKDIV0 = (CLK->CLKDIV0 & ~(0x00FFFFFFUL)) | 0x00000000UL;
    //CLK->CLKSEL0 = (CLK->CLKSEL0 & ~(0x000000FFUL)) | 0x0000003CUL;
    //CLK->CLKSEL1 = (CLK->CLKSEL1 & ~(0x0F77770FUL)) | 0x0F77770FUL;
    //CLK->CLKSEL2 = (CLK->CLKSEL2 & ~(0x0F03001CUL)) | 0x00020008UL;
    //CLK->CLKSEL3 = (CLK->CLKSEL3 & ~(0x00000100UL)) | 0x00000000UL;
    //CLK->AHBCLK = (CLK->AHBCLK & ~(0x002F8086UL)) | 0x003F8086UL;
    //CLK->APBCLK0 = (CLK->APBCLK0 & ~(0x18F3337DUL)) | 0x18F3337DUL;
    //CLK->APBCLK1 = (CLK->APBCLK1 & ~(0x03FF0000UL)) | 0x03FF0000UL;
    //CLK->CLKOCTL = (CLK->CLKOCTL & ~(0x0000003FUL)) | 0x00000030UL;
    //SysTick->CTRL = (SysTick->CTRL & ~(0x00000005UL)) | 0x00000001UL;

    /* Enable clock source */
    CLK_EnableXtalRC(CLK_PWRCTL_LIRCEN_Msk | CLK_PWRCTL_HIRCEN_Msk | CLK_PWRCTL_LXTEN_Msk | CLK_PWRCTL_HXTEN_Msk);

    /* Waiting for clock source ready */
    CLK_WaitClockReady(CLK_STATUS_LIRCSTB_Msk | CLK_STATUS_HIRCSTB_Msk | CLK_STATUS_LXTSTB_Msk | CLK_STATUS_HXTSTB_Msk);

    /* Disable PLL first to avoid unstable when setting PLL */
    CLK_DisablePLL();

    /* Set PLL frequency */
    CLK->PLLCTL = (CLK->PLLCTL & ~(0x000FFFFFUL)) | 0x008A0012UL;

    /* Waiting for PLL ready */
    CLK_WaitClockReady(CLK_STATUS_PLLSTB_Msk);

    /* Set HCLK clock */
    CLK_SetHCLK(CLK_CLKSEL0_HCLKSEL_HIRC, CLK_CLKDIV0_HCLK(1));

    /* Set PCLK-related clock */
    CLK->CLKSEL0 = CLK->CLKSEL0 & ~CLK_CLKSEL0_PCLK0SEL_Msk;
    CLK->CLKSEL0 = CLK->CLKSEL0 & ~CLK_CLKSEL0_PCLK1SEL_Msk;

    /* Enable IP clock */
    CLK_EnableModuleClock(ADC_MODULE);
    CLK_EnableModuleClock(BPWM0_MODULE);
    CLK_EnableModuleClock(BPWM1_MODULE);
    CLK_EnableModuleClock(BPWM2_MODULE);
    CLK_EnableModuleClock(BPWM3_MODULE);
    CLK_EnableModuleClock(CRC_MODULE);
    CLK_EnableModuleClock(GPIOA_MODULE);
    CLK_EnableModuleClock(GPIOB_MODULE);
    CLK_EnableModuleClock(GPIOC_MODULE);
    CLK_EnableModuleClock(GPIOD_MODULE);
    CLK_EnableModuleClock(GPIOF_MODULE);
    CLK_EnableModuleClock(I2C0_MODULE);
    CLK_EnableModuleClock(I2C1_MODULE);
    CLK_EnableModuleClock(ISP_MODULE);
    CLK_EnableModuleClock(LLSI0_MODULE);
    CLK_EnableModuleClock(LLSI1_MODULE);
    CLK_EnableModuleClock(LLSI2_MODULE);
    CLK_EnableModuleClock(LLSI3_MODULE);
    CLK_EnableModuleClock(LLSI4_MODULE);
    CLK_EnableModuleClock(LLSI5_MODULE);
    CLK_EnableModuleClock(LLSI6_MODULE);
    CLK_EnableModuleClock(LLSI7_MODULE);
    CLK_EnableModuleClock(LLSI8_MODULE);
    CLK_EnableModuleClock(LLSI9_MODULE);
    CLK_EnableModuleClock(PDMA_MODULE);
    CLK_EnableModuleClock(SPI0_MODULE);
    CLK_EnableModuleClock(SPI1_MODULE);
    CLK_EnableModuleClock(TMR0_MODULE);
    CLK_EnableModuleClock(TMR1_MODULE);
    CLK_EnableModuleClock(TMR2_MODULE);
    CLK_EnableModuleClock(TMR3_MODULE);
    CLK_EnableModuleClock(UART0_MODULE);
    CLK_EnableModuleClock(UART1_MODULE);
    CLK_EnableModuleClock(USBD_MODULE);
    CLK_EnableModuleClock(WDT_MODULE);
    CLK_EnableModuleClock(WWDT_MODULE);
    CLK_EnableCKO(CLK_CLKSEL2_CLKOSEL_HCLK, MODULE_NoMsk, 1);
    CLK_EnableSysTick(CLK_CLKSEL0_STCLKSEL_HIRC_DIV4, 0);

    /* Set IP clock */
    CLK_SetModuleClock(ADC_MODULE, CLK_CLKSEL1_ADCSEL_HIRC_DIV2, CLK_CLKDIV0_ADC(1));
    CLK_SetModuleClock(SPI0_MODULE, CLK_CLKSEL2_SPI0SEL_HXT, MODULE_NoMsk);
    CLK_SetModuleClock(SPI1_MODULE, CLK_CLKSEL2_SPI1SEL_HXT, MODULE_NoMsk);
    CLK_SetModuleClock(TMR0_MODULE, CLK_CLKSEL1_TMR0SEL_HIRC_DIV2, MODULE_NoMsk);
    CLK_SetModuleClock(TMR1_MODULE, CLK_CLKSEL1_TMR1SEL_HIRC_DIV2, MODULE_NoMsk);
    CLK_SetModuleClock(TMR2_MODULE, CLK_CLKSEL1_TMR2SEL_HIRC_DIV2, MODULE_NoMsk);
    CLK_SetModuleClock(TMR3_MODULE, CLK_CLKSEL1_TMR3SEL_HIRC_DIV2, MODULE_NoMsk);
    CLK_SetModuleClock(UART0_MODULE, CLK_CLKSEL1_UART0SEL_HIRC_DIV2, CLK_CLKDIV0_UART0(1));
    CLK_SetModuleClock(UART1_MODULE, CLK_CLKSEL1_UART1SEL_HIRC_DIV2, CLK_CLKDIV0_UART1(1));
    CLK_SetModuleClock(USBD_MODULE, CLK_CLKSEL3_USBDSEL_HIRC, MODULE_NoMsk);
    CLK_SetModuleClock(WDT_MODULE, CLK_CLKSEL1_WDTSEL_LIRC, MODULE_NoMsk);
    CLK_SetModuleClock(WWDT_MODULE, CLK_CLKSEL2_WWDTSEL_HCLK_DIV2048, MODULE_NoMsk);

    /* Update System Core Clock */
    /* User can use SystemCoreClockUpdate() to calculate SystemCoreClock. */
    SystemCoreClockUpdate();

    return;
}

/*** (C) COPYRIGHT 2016-2021 Nuvoton Technology Corp. ***/
