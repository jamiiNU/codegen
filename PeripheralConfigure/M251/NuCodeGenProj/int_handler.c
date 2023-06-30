/******************************************************************************//**
 * @file     int_handler.c
 * @version  V1.01
 * @brief    M251 interrupt handler file
 *
 * SPDX-License-Identifier: Apache-2.0
 * @copyright (C) 2021 Nuvoton Technology Corp. All rights reserved.
 ******************************************************************************/

/*!<Includes */
#include "NuCodeGenProj.h"
#include "IP\int_handler_acmp.c"
#include "IP\int_handler_bpwm.c"
#include "IP\int_handler_clk.c"
#include "IP\int_handler_crypto.c"
#include "IP\int_handler_dac.c"
#include "IP\int_handler_eadc.c"
#include "IP\int_handler_gpio.c"
#include "IP\int_handler_i2c.c"
#include "IP\int_handler_lcd.c"
#include "IP\int_handler_opa.c"
#include "IP\int_handler_pdma.c"
#include "IP\int_handler_psio.c"
#include "IP\int_handler_pwm.c"
#include "IP\int_handler_qspi.c"
#include "IP\int_handler_rtc.c"
#include "IP\int_handler_sc.c"
#include "IP\int_handler_spii2s.c"
#include "IP\int_handler_sys.c"
#include "IP\int_handler_timer.c"
#include "IP\int_handler_uart.c"
#include "IP\int_handler_usbd.c"
#include "IP\int_handler_usci_i2c.c"
#include "IP\int_handler_usci_spi.c"
#include "IP\int_handler_usci_uart.c"
#include "IP\int_handler_wdt.c"
#include "IP\int_handler_wwdt.c"
