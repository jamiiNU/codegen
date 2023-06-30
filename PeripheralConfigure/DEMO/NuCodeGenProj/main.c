/****************************************************************************
 * @file     main.c
 * @version  V1.00
 * $Revision: 6 $
 * $Date: 14/10/06 9:52a $
 * @brief    Demonstrate UART transmit and receive function with PDMA
 *
 * @note
 * Copyright (C) 2011 Nuvoton Technology Corp. All rights reserved.
 *
 ******************************************************************************/
#include <stdio.h>
#include "NUC472_442.h"

extern void Periph_Init(void);
extern void Clock_Init(void);
extern void Pin_Init(void);

void SYS_Init(void)
{
    Clock_Init();
    Pin_Init();
}

int32_t main(void)
{
    /* Init System, IP clock and multi-function I/O */
    SYS_Init();
    Periph_Init();
}
