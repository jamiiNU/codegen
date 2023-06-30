/****************************************************************************
 * @file     pin_conf.c
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
Pin Configuration:
Pin33:ICE_DAT
Pin34:ICE_CLK
Pin60:UART0_nCTS
Pin61:UART0_nRTS
Pin62:UART0_TXD
Pin63:UART0_RXD
Module Configuration:
ICE_CLK(Pin:34)
ICE_DAT(Pin:33)
UART0_nCTS(Pin:60)
UART0_nRTS(Pin:61)
UART0_RXD(Pin:63)
UART0_TXD(Pin:62)
GPIO Configuration:
PB.8:UART0_RXD(Pin:63)
PB.9:UART0_TXD(Pin:62)
PB.10:UART0_nRTS(Pin:61)
PB.11:UART0_nCTS(Pin:60)
PF.0:ICE_DAT(Pin:33)
PF.1:ICE_CLK(Pin:34)
********************/

#include "NuCodeGenProj.h"

/*
 * @brief This function provides the configured MFP registers
 * @param None
 * @return None
 */
void Pin_Init(void)
{
    //SYS->GPA_MFPH = 0x00000000UL;
    //SYS->GPA_MFPL = 0x00000000UL;
    //SYS->GPB_MFPH = 0x00005555UL;
    //SYS->GPB_MFPL = 0x00000000UL;
    //SYS->GPC_MFPH = 0x00000000UL;
    //SYS->GPC_MFPL = 0x00000000UL;
    //SYS->GPD_MFPH = 0x00000000UL;
    //SYS->GPD_MFPL = 0x00000000UL;
    //SYS->GPF_MFPH = 0x00000000UL;
    //SYS->GPF_MFPL = 0x000000EEUL;

    SYS->GPA_MFPH = 0x00000000;
    SYS->GPA_MFPL = 0x00000000;
    SYS->GPB_MFPH = SYS_GPB_MFPH_PB11MFP_UART0_nCTS | SYS_GPB_MFPH_PB10MFP_UART0_nRTS | SYS_GPB_MFPH_PB9MFP_UART0_TXD | SYS_GPB_MFPH_PB8MFP_UART0_RXD;
    SYS->GPB_MFPL = 0x00000000;
    SYS->GPC_MFPH = 0x00000000;
    SYS->GPC_MFPL = 0x00000000;
    SYS->GPD_MFPH = 0x00000000;
    SYS->GPD_MFPL = 0x00000000;
    SYS->GPF_MFPH = 0x00000000;
    SYS->GPF_MFPL = SYS_GPF_MFPL_PF1MFP_ICE_CLK | SYS_GPF_MFPL_PF0MFP_ICE_DAT;

    return;
}

/*** (C) COPYRIGHT 2016-2021 Nuvoton Technology Corp. ***/
