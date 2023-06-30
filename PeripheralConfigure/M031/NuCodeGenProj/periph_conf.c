#include "NuCodeGenProj.h"
#include "IP\acmp.c"
#include "IP\bpwm.c"
#include "IP\clk.c"
#include "IP\crc.c"
#include "IP\adc.c"
#include "IP\ebi.c"
#include "IP\fmc.c"
#include "IP\gpio.c"
#include "IP\i2c.c"
#include "IP\pdma.c"
#include "IP\pwm.c"
#include "IP\qspi.c"
#include "IP\rtc.c"
#include "IP\spii2s.c"
#include "IP\sys.c"
#include "IP\timer.c"
#include "IP\usbd.c"
#include "IP\uart.c"
#include "IP\usci.c"
#include "IP\wdt.c"
#include "IP\wwdt.c"
#include "IP\hdiv.c"

void Periph_Init(void)
{
#if NUCODEGEN_CLK
    CLK_Init();
#endif

#if NUCODEGEN_SYS
    SYS_Init();
#endif    

#if NUCODEGEN_PDMA
    PDMA_Init();
#endif

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

#if NUCODEGEN_UART4
    UART4_Init();
#endif

#if NUCODEGEN_UART5
    UART5_Init();
#endif

#if NUCODEGEN_UART6
    UART6_Init();
#endif

#if NUCODEGEN_UART7
    UART7_Init();
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

#if NUCODEGEN_ADC
    ADC_Init();
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

#if NUCODEGEN_USCI0_UART
    USCI0_UART_Init();
#endif

#if NUCODEGEN_USCI1_UART
    USCI1_UART_Init();
#endif

#if NUCODEGEN_USCI0_SPI
    USCI0_SPI_Init();
#endif

#if NUCODEGEN_USCI1_SPI
    USCI1_SPI_Init();
#endif

#if (NUCODEGEN_QSPI)
    QSPI_Init() ;
#endif

#if (NUCODEGEN_SPII2S)
    SPII2S_Init() ;
#endif

#if NUCODEGEN_USBD
    USBD_Init();
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

#if NUCODEGEN_FMC
    FMC_Init();
#endif

#if NUCODEGEN_HDIV
    HDIV_Init();
#endif
}
