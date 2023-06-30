/****************************************************************************
 * @file     clk_conf.c
 * @version  V0.00
 * @Date     2019/02/18-11:10:53
 * @brief    NuMicro generated code file
 *
 * Copyright (C) 2016-2019 Nuvoton Technology Corp. All rights reserved.
*****************************************************************************/

/********************
MCU:NUC472JI8AE(LQFP144)
Base Clocks:
Enabled-Module Frequencies:
ISP=Bus Clock(HCLK):Disabled/Engine Clock:
WDT=Bus Clock(PCLK):Disabled/Engine Clock:
WWDT=Bus Clock(PCLK):Disabled/Engine Clock:
********************/

#include "NUC472_442.h"
/*----------------------------------------------------------------------------
  Define HXT clock.
  Please locate and modify the real one in your project.
  Otherwise, the project may fail to build.
 *----------------------------------------------------------------------------*/
#define __HXT         (0UL)  /*!< High Speed External Crystal Clock Frequency */

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
    //CLK->PWRCTL = (CLK->PWRCTL & ~(0x0000000Ful)) | 0x0000001Ful;
    //CLK->PLLCTL = (CLK->PLLCTL & ~(0x001FFFFFul)) | 0x00058228ul;
    //CLK->CLKDIV0 = (CLK->CLKDIV0 & ~(0xFFFF0FFFul)) | 0x00000000ul;
    //CLK->CLKDIV1 = (CLK->CLKDIV1 & ~(0xFFFFFFFFul)) | 0x00000000ul;
    //CLK->CLKDIV2 = (CLK->CLKDIV2 & ~(0x0000FFFFul)) | 0x00000000ul;
    //CLK->CLKDIV3 = (CLK->CLKDIV3 & ~(0x00FFFFFFul)) | 0x00000000ul;
    //CLK->CLKSEL0 = (CLK->CLKSEL0 & ~(0x0033017Ful)) | 0x0033053Ful;
    //CLK->CLKSEL1 = (CLK->CLKSEL1 & ~(0xF37777FFul)) | 0xB37777FFul;
    //CLK->CLKSEL2 = (CLK->CLKSEL2 & ~(0x00777777ul)) | 0x00333333ul;
    //CLK->CLKSEL3 = (CLK->CLKSEL3 & ~(0x000F0FFFul)) | 0x000F0FFFul;
    //CLK->AHBCLK = (CLK->AHBCLK & ~(0x000017FEul)) | 0x00000005ul;
    //CLK->APBCLK0 = (CLK->APBCLK0 & ~(0xF73FFFFFul)) | 0x00000001ul;
    //CLK->APBCLK1 = (CLK->APBCLK1 & ~(0xFCFF013Ful)) | 0x00000000ul;
    //CLK->CLKOCTL = (CLK->CLKOCTL & ~(0x0000003Ful)) | 0x00000000ul;
    //SysTick->CTRL = (SysTick->CTRL & ~(0x00000005ul)) | 0x00000000ul;

    /* Unlock protected registers */
    SYS_UnlockReg();

    /* Enable clock source */
    CLK_EnableXtalRC(CLK_PWRCTL_LIRCEN_Msk|CLK_PWRCTL_HIRCEN_Msk|CLK_PWRCTL_LXTEN_Msk|CLK_PWRCTL_HXTEN_Msk);

    /* Waiting for clock source ready */
    CLK_WaitClockReady(CLK_STATUS_LIRCSTB_Msk|CLK_STATUS_HIRCSTB_Msk|CLK_STATUS_LXTSTB_Msk|CLK_STATUS_HXTSTB_Msk);

    /* If the defines do not exist in your project, please refer to the related clk.h in the Header folder appended to the tool package. */
    /* Set HCLK clock */
    CLK_SetHCLK(CLK_CLKSEL0_HCLKSEL_HIRC, CLK_CLKDIV0_HCLK(1));

    /* Set PCLK-related clock */
    CLK->CLKSEL0 = CLK->CLKSEL0 & ~CLK_CLKSEL0_PCLKSEL_Msk;

    /* Enable IP clock */
    CLK_EnableModuleClock(ISP_MODULE);
    CLK_EnableModuleClock(WDT_MODULE);
    CLK_EnableModuleClock(WWDT_MODULE);

    /* Set IP clock */
    CLK_SetModuleClock(WDT_MODULE, CLK_CLKSEL1_WDTSEL_LIRC, MODULE_NoMsk);
    CLK_SetModuleClock(WWDT_MODULE, CLK_CLKSEL1_WWDTSEL_HCLK_DIV2048, MODULE_NoMsk);

    /* Update System Core Clock */
    /* User can use SystemCoreClockUpdate() to calculate SystemCoreClock. */
    SystemCoreClockUpdate();

    /* Lock protected registers */
    SYS_LockReg();

    return;
}

/*** (C) COPYRIGHT 2016-2019 Nuvoton Technology Corp. ***/
