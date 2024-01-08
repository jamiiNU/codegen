#include "NuCodeGenProj.h"
#include "IP\adc.c"
#include "IP\clk.c"
#include "IP\ecap.c"
#include "IP\fmc.c"
#include "IP\gpio.c"
#include "IP\i2c.c"
#include "IP\pwm.c"
#include "IP\sys.c"
#include "IP\timer.c"
#include "IP\uart.c"
#include "IP\usci_i2c.c"
#include "IP\usci_spi.c"
#include "IP\usci_uart.c"
#include "IP\wdt.c"
#include "IP\wwdt.c"

void Periph_Init(void)
{
#if NUCODEGEN_ADC
    ADC_Init();
#endif

#if NUCODEGEN_CLK
    CLK_Init();
#endif

#if NUCODEGEN_ECAP
    ECAP_Init();
#endif

#if NUCODEGEN_FMC
    FMC_Init();
#endif

#if NUCODEGEN_GPIO
    GPIO_Init();
#endif

#if NUCODEGEN_I2C0
    I2C0_Init();
#endif

#if NUCODEGEN_PWM0
    PWM0_Init();
#endif

#if NUCODEGEN_SYS
    SYS_Init();
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

#if NUCODEGEN_UART0
    UART0_Init();
#endif

#if NUCODEGEN_UART1
    UART1_Init();
#endif

#if NUCODEGEN_USCI0_I2C
    USCI0_I2C_Init();
#endif

#if NUCODEGEN_USCI0_SPI
    USCI0_SPI_Init();
#endif

#if NUCODEGEN_USCI0_UART
    USCI0_UART_Init();
#endif

#if NUCODEGEN_WDT
    WDT_Init();
#endif

#if NUCODEGEN_WWDT
    WWDT_Init();
#endif
}
