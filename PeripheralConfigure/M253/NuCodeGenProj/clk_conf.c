/****************************************************************************
 * @file     clk_conf.c
 * @version  V0.37
 * @Date     2019/08/27-15:10:50
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
ACMP01=Bus Clock(PCLK1):48MHz
BPWM0=Bus Clock(PCLK0):48MHz/Engine Clock:48MHz
BPWM1=Bus Clock(PCLK1):48MHz/Engine Clock:48MHz
CLKO=Bus Clock(HCLK):48MHz/Engine Clock:48MHz
CRC=Bus Clock(HCLK):48MHz
DAC=Bus Clock(PCLK1):48MHz
EADC=Bus Clock(PCLK1):48MHz/Engine Clock:48MHz
EBI=Bus Clock(HCLK):48MHz
FMCIDLE=Bus Clock(HCLK):48MHz/Engine Clock:48MHz
I2C0=Bus Clock(PCLK0):48MHz
I2C1=Bus Clock(PCLK1):48MHz
ISP=Bus Clock(HCLK):48MHz/Engine Clock:48MHz
OPA=Bus Clock(PCLK0):48MHz
PDMA=Bus Clock(HCLK):48MHz
PSIO=Bus Clock(PCLK1):48MHz/Engine Clock:48MHz
PWM0=Bus Clock(PCLK0):48MHz/Engine Clock:48MHz
PWM1=Bus Clock(PCLK1):48MHz/Engine Clock:48MHz
QSPI0=Bus Clock(PCLK0):48MHz/Engine Clock:48MHz
RTC=Bus Clock(PCLK0):48MHz/Engine Clock:32.7680kHz
SC0=Bus Clock(PCLK0):48MHz/Engine Clock:48MHz
SPI0=Bus Clock(PCLK1):48MHz/Engine Clock:48MHz
SYSTICK=Bus Clock(HCLK):48MHz/Engine Clock:24MHz
TMR0=Bus Clock(PCLK0):48MHz/Engine Clock:48MHz
TMR1=Bus Clock(PCLK0):48MHz/Engine Clock:48MHz
TMR2=Bus Clock(PCLK1):48MHz/Engine Clock:48MHz
TMR3=Bus Clock(PCLK1):48MHz/Engine Clock:48MHz
UART0=Bus Clock(PCLK0):48MHz/Engine Clock:48MHz
UART1=Bus Clock(PCLK1):48MHz/Engine Clock:48MHz
UART2=Bus Clock(PCLK0):48MHz/Engine Clock:48MHz
USBD=Bus Clock(PCLK0):48MHz/Engine Clock:48MHz
USCI0=Bus Clock(PCLK0):48MHz
USCI1=Bus Clock(PCLK1):48MHz
USCI2=Bus Clock(PCLK0):48MHz
WDT=Bus Clock(PCLK0):48MHz/Engine Clock:38.4000kHz
WWDT=Bus Clock(PCLK0):48MHz/Engine Clock:23.4375kHz
********************/

#include "NuCodeGenProj.h"

/*
 * @brief This function updates clock registers to fulfil the configuration
 * @param None
 * @return None
 */
void Clock_Init()
{
    /*---------------------------------------------------------------------------------------------------------*/
    /* Init System Clock                                                                                       */
    /*---------------------------------------------------------------------------------------------------------*/
    //CLK->RTC_LXTCTL = (CLK->RTC_LXTCTL & ~(0x00000100ul)) | 0x780F010Eul;
    //CLK->PWRCTL = (CLK->PWRCTL & ~(0x0008000Ful)) | 0x0079001Ful;
    //CLK->PLLCTL = (CLK->PLLCTL & ~(0x001FDE3Ful)) | 0x00084410ul;
    //CLK->CLKDIV0 = (CLK->CLKDIV0 & ~(0x00FFFFFFul)) | 0x00000000ul;
    //CLK->CLKDIV1 = (CLK->CLKDIV1 & ~(0xFF0000FFul)) | 0x00000000ul;
    //CLK->CLKDIV4 = (CLK->CLKDIV4 & ~(0x0000000Ful)) | 0x00000000ul;
    //CLK->PCLKDIV = (CLK->PCLKDIV & ~(0x00000077ul)) | 0x00000000ul;
    //CLK->CLKSEL0 = (CLK->CLKSEL0 & ~(0x0000013Ful)) | 0x0000003Ful;
    //CLK->CLKSEL1 = (CLK->CLKSEL1 & ~(0x7777777Ful)) | 0x4477773Bul;
    //CLK->CLKSEL2 = (CLK->CLKSEL2 & ~(0x7000033Ful)) | 0x2000032Bul;
    //CLK->CLKSEL3 = (CLK->CLKSEL3 & ~(0x07000003ul)) | 0x04000003ul;
    //CLK->AHBCLK = (CLK->AHBCLK & ~(0x0000908Eul)) | 0x0000908Eul;
    //CLK->APBCLK0 = (CLK->APBCLK0 & ~(0x180733FFul)) | 0x180733FFul;
    //CLK->APBCLK1 = (CLK->APBCLK1 & ~(0xC00F1701ul)) | 0xC00F1701ul;
    //CLK->CLKOCTL = (CLK->CLKOCTL & ~(0x0000007Ful)) | 0x00000030ul;
    //SysTick->CTRL = (SysTick->CTRL & ~(0x00000005ul)) | 0x00000001ul;
    //CLK->RTC_LXTCTL = (CLK->RTC_LXTCTL & ~(0x00000100ul)) | 0x780F010Eul;

    /* Enable clock source */
    CLK_EnableXtalRC(CLK_PWRCTL_LIRCEN_Msk|CLK_PWRCTL_HIRCEN_Msk|CLK_PWRCTL_MIRCEN_Msk|CLK_PWRCTL_LXTEN_Msk);

    /* Waiting for clock source ready */
    CLK_WaitClockReady(CLK_STATUS_LIRCSTB_Msk|CLK_STATUS_HIRCSTB_Msk|CLK_STATUS_MIRCSTB_Msk|CLK_STATUS_LXTSTB_Msk);

    /* If the defines do not exist in your project, please refer to the related clk.h in the Header folder appended to the tool package. */
    /* Set HCLK clock */
    CLK_SetHCLK(CLK_CLKSEL0_HCLKSEL_HIRC, CLK_CLKDIV0_HCLK(1));

    /* Set PCLK-related clock */
    CLK->PCLKDIV = (CLK_PCLKDIV_APB0DIV_DIV1 | CLK_PCLKDIV_APB1DIV_DIV1);

    /* Enable IP clock */
    CLK_EnableModuleClock(BPWM0_MODULE);
    CLK_EnableModuleClock(CRC_MODULE);
    CLK_EnableModuleClock(CANFD0_MODULE);
    CLK_EnableModuleClock(EADC_MODULE);
    CLK_EnableModuleClock(FMCIDLE_MODULE);
    CLK_EnableModuleClock(I2C0_MODULE);
    CLK_EnableModuleClock(I2C1_MODULE);
    CLK_EnableModuleClock(ISP_MODULE);
    CLK_EnableModuleClock(PDMA_MODULE);
    CLK_EnableModuleClock(RTC_MODULE);
    CLK_EnableModuleClock(SPI0_MODULE);
    CLK_EnableModuleClock(TMR0_MODULE);
    CLK_EnableModuleClock(TMR1_MODULE);
    CLK_EnableModuleClock(TMR2_MODULE);
    CLK_EnableModuleClock(TMR3_MODULE);
    CLK_EnableModuleClock(UART0_MODULE);
    CLK_EnableModuleClock(UART1_MODULE);
    CLK_EnableModuleClock(UART2_MODULE);
    CLK_EnableModuleClock(UART3_MODULE);
    CLK_EnableModuleClock(UART4_MODULE);
    CLK_EnableModuleClock(USBD_MODULE);
    CLK_EnableModuleClock(USCI0_MODULE);
    CLK_EnableModuleClock(WDT_MODULE);
    CLK_EnableModuleClock(WWDT_MODULE);
    CLK_EnableCKO(CLK_CLKSEL1_CLKOSEL_HIRC, MODULE_NoMsk, 1);
    CLK->CLKOCTL = CLK->CLKOCTL & ~CLK_CLKOCTL_CLK1HZEN_Msk;
    CLK_EnableSysTick(CLK_CLKSEL0_STCLKSEL_HIRC_DIV2, 0);

    /* Set IP clock */
    CLK_SetModuleClock(EADC_MODULE, MODULE_NoMsk, CLK_CLKDIV0_EADC(1));
    RTC->LXTCTL = RTC->LXTCTL & ~RTC_LXTCTL_C32KS_Msk;
    CLK_SetModuleClock(SPI0_MODULE, CLK_CLKSEL2_SPI0SEL_PCLK1, MODULE_NoMsk);
    CLK_SetModuleClock(TMR0_MODULE, CLK_CLKSEL1_TMR0SEL_HIRC, MODULE_NoMsk);
    CLK_SetModuleClock(TMR1_MODULE, CLK_CLKSEL1_TMR1SEL_HIRC, MODULE_NoMsk);
    CLK_SetModuleClock(TMR2_MODULE, CLK_CLKSEL1_TMR2SEL_HIRC, MODULE_NoMsk);
    CLK_SetModuleClock(TMR3_MODULE, CLK_CLKSEL1_TMR3SEL_HIRC, MODULE_NoMsk);
    CLK_SetModuleClock(UART0_MODULE, CLK_CLKSEL1_UART0SEL_PCLK0, CLK_CLKDIV0_UART0(1));
    CLK_SetModuleClock(UART1_MODULE, CLK_CLKSEL1_UART1SEL_PCLK1, CLK_CLKDIV0_UART1(1));
    CLK_SetModuleClock(UART2_MODULE, CLK_CLKSEL3_UART2SEL_PCLK0, CLK_CLKDIV4_UART2(1));
    CLK_SetModuleClock(UART3_MODULE, CLK_CLKSEL3_UART3SEL_PCLK1, CLK_CLKDIV4_UART3(1));
    CLK_SetModuleClock(UART4_MODULE, CLK_CLKSEL3_UART4SEL_PCLK0, CLK_CLKDIV4_UART4(1));
    CLK_SetModuleClock(WDT_MODULE, CLK_CLKSEL1_WDTSEL_LIRC, MODULE_NoMsk);
    CLK_SetModuleClock(WWDT_MODULE, CLK_CLKSEL1_WWDTSEL_HCLK_DIV2048, MODULE_NoMsk);

    /* Update System Core Clock */
    /* User can use SystemCoreClockUpdate() to calculate SystemCoreClock. */
    SystemCoreClockUpdate();

    return;
}

/*** (C) COPYRIGHT 2016-2019 Nuvoton Technology Corp. ***/
