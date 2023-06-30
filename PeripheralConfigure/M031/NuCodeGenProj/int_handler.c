/******************************************************************************//**
 * @file     int_handler.c
 * @version  V1.01
 * @brief    M031 interrupt handler file
 *
 * SPDX-License-Identifier: Apache-2.0 
 * @copyright (C) 2021 Nuvoton Technology Corp. All rights reserved.
 ******************************************************************************/

/*!<Includes */
#include "NuCodeGenProj.h"
#include "IP\acmp_int.c"
#include "IP\bpwm_int.c"
#include "IP\clk_int.c"
#include "IP\adc_int.c"
#include "IP\gpio_int.c"
#include "IP\I2C_int.c"
#include "IP\pdma_int.c"
#include "IP\pwm_int.c"
#include "IP\qspi_int.c"
#include "IP\rtc_int.c"
#include "IP\spii2s_int.c"
#include "IP\sys_int.c"
#include "IP\timer_int.c"
#include "IP\uart_int.c"
#include "IP\usci_int.c"
#include "IP\wdt_int.c"
#if NUCODEGEN_USBD
#include "USBD\usbd_int.c"
#endif







