/****************************************************************************
 * @file     pin_conf.c
 * @version  V0.00
 * @Date     2019/03/28-12:06:28
 * @brief    NuMicro generated code file
 *
 * Copyright (C) 2016-2019 Nuvoton Technology Corp. All rights reserved.
*****************************************************************************/

/********************
MCU:M252KG6AE(LQFP128)
Pin Configuration:
Pin1:TM0
Pin2:TM1
Pin3:TM2
Pin4:TM3
Pin48:UART0_nCTS
Pin49:UART0_nRTS
Pin65:ICE_DAT
Pin66:ICE_CLK
Pin118:UART0_TXD
Pin119:UART0_RXD
Module Configuration:
TM0(Pin:1)
TM1(Pin:2)
TM2(Pin:3)
TM3(Pin:4)
UART0_nCTS(Pin:48)
UART0_nRTS(Pin:49)
UART0_RXD(Pin:119)
UART0_TXD(Pin:118)
ICE_CLK(Pin:66)
ICE_DAT(Pin:65)
GPIO Configuration:
PB.2:TM3(Pin:4)
PB.3:TM2(Pin:3)
PB.4:TM1(Pin:2)
PB.5:TM0(Pin:1)
PB.12:UART0_RXD(Pin:119)
PB.13:UART0_TXD(Pin:118)
PC.6:UART0_nRTS(Pin:49)
PC.7:UART0_nCTS(Pin:48)
PF.0:ICE_DAT(Pin:65)
PF.1:ICE_CLK(Pin:66)
********************/

#include "NuCodeGenProj.h"
/*
 * @brief This function provides the configured MFP registers
 * @param None
 * @return None
 */
void Pin_Init(void)
{
    //SYS->GPA_MFPH = 0x00000000;
    //SYS->GPA_MFPL = 0x00000000;
    //SYS->GPB_MFPH = 0x00660000;
    //SYS->GPB_MFPL = 0x00EEEE00;
    //SYS->GPC_MFPH = 0x00000000;
    //SYS->GPC_MFPL = 0x77000000;
    //SYS->GPD_MFPH = 0x00000000;
    //SYS->GPD_MFPL = 0x00000000;
    //SYS->GPE_MFPH = 0x00000000;
    //SYS->GPE_MFPL = 0x00000000;
    //SYS->GPF_MFPL = 0x000000EE;

    //If the defines do not exist in your project, please refer to the corresponding sys.h in the Header folder appended to the tool package.
    SYS->GPA_MFPH = 0x00000000;
    SYS->GPA_MFPL = 0x00000000;
    SYS->GPB_MFPH = SYS_GPB_MFPH_PB13MFP_UART0_TXD | SYS_GPB_MFPH_PB12MFP_UART0_RXD;
    SYS->GPB_MFPL = SYS_GPB_MFPL_PB5MFP_TM0 | SYS_GPB_MFPL_PB4MFP_TM1 | SYS_GPB_MFPL_PB3MFP_TM2 | SYS_GPB_MFPL_PB2MFP_TM3;
    SYS->GPC_MFPH = 0x00000000;
    SYS->GPC_MFPL = SYS_GPC_MFPL_PC7MFP_UART0_nCTS | SYS_GPC_MFPL_PC6MFP_UART0_nRTS;
    SYS->GPD_MFPH = 0x00000000;
    SYS->GPD_MFPL = 0x00000000;
    SYS->GPE_MFPH = 0x00000000;
    SYS->GPE_MFPL = 0x00000000;
    SYS->GPF_MFPL = SYS_GPF_MFPL_PF1MFP_ICE_CLK | SYS_GPF_MFPL_PF0MFP_ICE_DAT;

    return;
}

/*** (C) COPYRIGHT 2016-2019 Nuvoton Technology Corp. ***/
