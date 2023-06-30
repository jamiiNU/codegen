/******************************************************************************//**
 * @file     periph_conf.c
 * @version  V1.01
 * @brief    M251 peripheral configuration file
 *
 * SPDX-License-Identifier: Apache-2.0
 * @copyright (C) 2021 Nuvoton Technology Corp. All rights reserved.
 ******************************************************************************/
#include "NuCodeGenProj.h"

#include "IP\periph_conf_acmp.c"
#include "IP\periph_conf_bpwm.c"
#include "IP\periph_conf_clk.c"
#include "IP\periph_conf_crc.c"
#include "IP\periph_conf_crypto.c"
#include "IP\periph_conf_dac.c"
#include "IP\periph_conf_eadc.c"
#include "IP\periph_conf_ebi.c"
#include "IP\periph_conf_fmc.c"
#include "IP\periph_conf_gpio.c"
#include "IP\periph_conf_i2c.c"
#include "IP\periph_conf_lcd.c"
#include "IP\periph_conf_opa.c"
#include "IP\periph_conf_pdma.c"
#include "IP\periph_conf_psio.c"
#include "IP\periph_conf_pwm.c"
#include "IP\periph_conf_qspi.c"
#include "IP\periph_conf_rtc.c"
#include "IP\periph_conf_sc.c"
#include "IP\periph_conf_spii2s.c"
#include "IP\periph_conf_sys.c"
#include "IP\periph_conf_timer.c"
#include "IP\periph_conf_uart.c"
#include "IP\periph_conf_usbd.c"
#include "IP\periph_conf_usci_i2c.c"
#include "IP\periph_conf_usci_spi.c"
#include "IP\periph_conf_usci_uart.c"
#include "IP\periph_conf_wdt.c"
#include "IP\periph_conf_wwdt.c"

void Periph_Init(void)
{
#if NUCODEGEN_UART0
    UART0_Init();
#endif

#if NUCODEGEN_UART1
    UART1_Init();
#endif

#if NUCODEGEN_UART2
    UART2_Init();
#endif

#if NUCODEGEN_UART3
    UART3_Init();
#endif

#if NUCODEGEN_CLK
    CLK_Init();
#endif

#if NUCODEGEN_SYS
    SYS_Init();
#endif

#if NUCODEGEN_CRC
    CRC_Init();
#endif

#if NUCODEGEN_BPWM0
    BPWM0_Init();
#endif

#if NUCODEGEN_BPWM1
    BPWM1_Init();
#endif

#if NUCODEGEN_PWM0
    PWM0_Init();
#endif

#if NUCODEGEN_PWM1
    PWM1_Init();
#endif

#if NUCODEGEN_GPIO
    GPIO_Init();
#endif

#if NUCODEGEN_EADC
    EADC_Init();
#endif

#if NUCODEGEN_EBI
    EBI_Init();
#endif

#if NUCODEGEN_I2C0
    I2C0_Init();
#endif

#if NUCODEGEN_I2C1
    I2C1_Init();
#endif

#if NUCODEGEN_USCI0_I2C
    USCI0_I2C_Init();
#endif

#if NUCODEGEN_USCI1_I2C
    USCI1_I2C_Init();
#endif

#if NUCODEGEN_USCI2_I2C
    USCI2_I2C_Init();
#endif

#if NUCODEGEN_USCI0_UART
    USCI0_UART_Init();
#endif

#if NUCODEGEN_USCI1_UART
    USCI1_UART_Init();
#endif

#if NUCODEGEN_USCI2_UART
    USCI2_UART_Init();
#endif

#if NUCODEGEN_USCI0_SPI
    USCI0_SPI_Init();
#endif

#if NUCODEGEN_USCI1_SPI
    USCI1_SPI_Init();
#endif

#if NUCODEGEN_USCI2_SPI
    USCI2_SPI_Init();
#endif

#if (NUCODEGEN_QSPI0)
    QSPI0_Init();
#endif

#if (NUCODEGEN_SPII2S0)
    SPII2S0_Init();
#endif

#if NUCODEGEN_USBD
    USBD_Init();
#endif

#if NUCODEGEN_SC0
    SC0_Init();
#endif

#if NUCODEGEN_TIMER0
    TIMER0_Init();
#endif

#if NUCODEGEN_TIMER1
    TIMER1_Init();
#endif

#if NUCODEGEN_TIMER2
    TIMER2_Init();
#endif

#if NUCODEGEN_TIMER3
    TIMER3_Init();
#endif

#if NUCODEGEN_PDMA
    PDMA_Init();
#endif

#if NUCODEGEN_PSIO
    PSIO_Init();
#endif

#if NUCODEGEN_WDT
    WDT_Init();
#endif

#if NUCODEGEN_WWDT
    WWDT_Init();
#endif

#if NUCODEGEN_RTC
    RTC_Init();
#endif

#if NUCODEGEN_ACMP
    ACMP_Init();
#endif

#if NUCODEGEN_OPA
    OPA_Init();
#endif

#if NUCODEGEN_DAC0
    DAC0_Init();
#endif
#if NUCODEGEN_DAC1
    DAC1_Init();
#endif

#if NUCODEGEN_FMC
    FMC_Init();
#endif

#if NUCODEGEN_LCD
    LCD_Init();
#endif

#if NUCODEGEN_CRYPTO
    CRYPTO_Init();
#endif
}
