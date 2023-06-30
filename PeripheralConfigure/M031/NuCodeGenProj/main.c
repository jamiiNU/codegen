/****************************************************************************
 * @file     main.c
 * @version  V1.01
 * $Revision: 1 $
 * $Date: 2019/05/02 8:05p $
 * @brief    NuCodeGenProj Sample
 * @note
 * SPDX-License-Identifier: Apache-2.0
 * Copyright (C) 2011 Nuvoton Technology Corp. All rights reserved.
 *
 ******************************************************************************/
#include "NuCodeGenProj.h"

#if defined (__GNUC__) && !defined(__ARMCC_VERSION) && defined(OS_USE_SEMIHOSTING)
    extern void initialise_monitor_handles(void);
#endif

extern void Periph_Init(void);
extern void Clock_Init(void);
extern void Pin_Init(void);

void System_Init(void)
{
    /* Unlock protected registers */
    SYS_UnlockReg();

    Clock_Init();
    Pin_Init();
    Periph_Init();

    /* Lock protected registers */
    SYS_LockReg();
}

int32_t main(void)
{
    /* Init System, IP clock, multi-function I/O and Peripheral*/
    System_Init();
#if (NUCODEGEN_UTEST)
    __asm("bkpt #0");
#endif /*NUCODEGEN_UTEST*/
    printf("*** Init Done, User add operation code***\n");

#if (NUCODEGEN_USBD)
#if (NUCODEGEN_CLASS_SEL==NUCODEGEN_CLASS_HID)
#if (NUCODEGEN_HID_DEMO_EN)
    USBD_Start();
    while (1) {
        HID_UpdateMouseData();
    }
#endif /*NUCODEGEN_HID_DEMO_EN*/
#endif /*NUCODEGEN_CLASS_SEL==NUCODEGEN_CLASS_HID*/

#if (NUCODEGEN_CLASS_SEL==NUCODEGEN_CLASS_MSC)
#if (NUCODEGEN_MSC_DEMO_EN)
    USBD_Start();
    while (1) {
        MSC_ProcessCmd();
    }
#endif /*NUCODEGEN_MSC_DEMO_EN*/
#endif /*NUCODEGEN_CLASS_SEL==NUCODEGEN_CLASS_MSC*/

#endif /*NUCODEGEN_USBD*/

#if (!NUCODEGEN_HID_DEMO_EN) && (!NUCODEGEN_MSC_DEMO_EN)
    while (1);
#endif
}
