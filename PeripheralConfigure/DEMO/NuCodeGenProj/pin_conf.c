/****************************************************************************
 * @file     pin_conf.c
 * @version  V0.00
 * @Date     2019/02/18-11:10:53 
 * @brief    NuMicro generated code file
 *
 * Copyright (C) 2016-2019 Nuvoton Technology Corp. All rights reserved.
*****************************************************************************/

/********************
MCU:NUC472JI8AE(LQFP144)
Pin Configuration:
Pin1:ACMP1_P3
Pin25:ACMP1_O
Pin35:ICE_CLK
Pin36:ICE_DAT
Pin141:ADC1_0
Pin142:ACMP1_P0
Pin143:ACMP1_P1
Pin144:ACMP1_P2
Module Configuration:
ACMP1_O(Pin:25)
ACMP1_P0(Pin:142)
ACMP1_P1(Pin:143)
ACMP1_P2(Pin:144)
ACMP1_P3(Pin:1)
ICE_CLK(Pin:35)
ICE_DAT(Pin:36)
ADC1_0(Pin:141)
GPIO Configuration:
PD.4:ACMP1_O(Pin:25)
PE.8:ADC1_0(Pin:141)
PE.9:ACMP1_P0(Pin:142)
PE.10:ACMP1_P1(Pin:143)
PE.11:ACMP1_P2(Pin:144)
PE.12:ACMP1_P3(Pin:1)
PG.10:ICE_CLK(Pin:35)
PG.11:ICE_DAT(Pin:36)
********************/

#include "NUC472_442.h"
/*
 * @brief This function provides the configued MFP registers
 * @param None
 * @return None
 */
void Pin_Init(void)
{
    //SYS->GPA_MFPH = 0x00000000;
    //SYS->GPA_MFPL = 0x00000000;
    //SYS->GPB_MFPH = 0x00000000;
    //SYS->GPB_MFPL = 0x00000000;
    //SYS->GPC_MFPH = 0x00000000;
    //SYS->GPC_MFPL = 0x00000000;
    //SYS->GPD_MFPH = 0x00000000;
    //SYS->GPD_MFPL = 0x00030000;
    //SYS->GPE_MFPH = 0x00022221;
    //SYS->GPE_MFPL = 0x00000000;
    //SYS->GPF_MFPH = 0x00000000;
    //SYS->GPF_MFPL = 0x00000000;
    //SYS->GPG_MFPH = 0x00001100;
    //SYS->GPG_MFPL = 0x00000000;
    //SYS->GPH_MFPL = 0x00000000;

    //If the defines do not exist in your project, please refer to the corresponding sys.h in the Header folder appended to the tool package.
    SYS->GPA_MFPH = 0x00000000;
    SYS->GPA_MFPL = 0x00000000;
    SYS->GPB_MFPH = 0x00000000;
    SYS->GPB_MFPL = 0x00000000;
    SYS->GPC_MFPH = 0x00000000;
    SYS->GPC_MFPL = 0x00000000;
    SYS->GPD_MFPH = 0x00000000;
    SYS->GPD_MFPL = SYS_GPD_MFPL_PD4MFP_ACMP1_O;
    SYS->GPE_MFPH = SYS_GPE_MFPH_PE12MFP_ACMP1_P3 | SYS_GPE_MFPH_PE11MFP_ACMP1_P2 | SYS_GPE_MFPH_PE10MFP_ACMP1_P1 | SYS_GPE_MFPH_PE9MFP_ACMP1_P0 | SYS_GPE_MFPH_PE8MFP_ADC1_0;
    SYS->GPE_MFPL = 0x00000000;
    SYS->GPF_MFPH = 0x00000000;
    SYS->GPF_MFPL = 0x00000000;
    SYS->GPG_MFPH = SYS_GPG_MFPH_PG11MFP_ICE_DAT | SYS_GPG_MFPH_PG10MFP_ICE_CLK;
    SYS->GPG_MFPL = 0x00000000;
    SYS->GPH_MFPL = 0x00000000;

    return;
}

/*** (C) COPYRIGHT 2016-2019 Nuvoton Technology Corp. ***/
