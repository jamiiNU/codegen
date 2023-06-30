#include "NuCodeGenProj.h"
#include "IP\adc.c"
#include "IP\bpwm.c"
#include "IP\clk.c"
#include "IP\crc.c"
#include "IP\fmc.c"
#include "IP\gpio.c"
#include "IP\i2c.c"
#include "IP\llsi.c"
#include "IP\pdma.c"
#include "IP\spii2s.c"
#include "IP\sys.c"
#include "IP\timer.c"
#include "IP\uart.c"
#include "IP\usbd.c"
#include "IP\wdt.c"
#include "IP\wwdt.c"

void Periph_Init(void)
{
#if NUCODEGEN_UART0
    UART0_Init();
#endif

#if NUCODEGEN_UART1
    UART1_Init();
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

#if NUCODEGEN_BPWM2
    BPWM2_Init();
#endif

#if NUCODEGEN_BPWM3
    BPWM3_Init();
#endif

#if NUCODEGEN_GPIO
    GPIO_Init();
#endif

#if NUCODEGEN_I2C0
    I2C0_Init();
#endif

#if NUCODEGEN_I2C1
    I2C1_Init();
#endif

#if NUCODEGEN_SPII2S0
    SPII2S0_Init();
#endif

#if NUCODEGEN_SPII2S1
    SPII2S1_Init();
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

#if NUCODEGEN_PDMA
    PDMA_Init();
#endif

#if NUCODEGEN_WDT
    WDT_Init();
#endif

#if NUCODEGEN_WWDT
    WWDT_Init();
#endif

#if NUCODEGEN_ADC
    ADC_Init();
#endif

#if NUCODEGEN_LLSI0
    LLSI0_Init();
#endif

#if NUCODEGEN_LLSI1
    LLSI1_Init();
#endif

#if NUCODEGEN_LLSI2
    LLSI2_Init();
#endif

#if NUCODEGEN_LLSI3
    LLSI3_Init();
#endif

#if NUCODEGEN_LLSI4
    LLSI4_Init();
#endif

#if NUCODEGEN_LLSI5
    LLSI5_Init();
#endif

#if NUCODEGEN_LLSI6
    LLSI6_Init();
#endif

#if NUCODEGEN_LLSI7
    LLSI7_Init();
#endif

#if NUCODEGEN_LLSI8
    LLSI8_Init();
#endif

#if NUCODEGEN_LLSI9
    LLSI9_Init();
#endif

#if NUCODEGEN_FMC
    FMC_Init();
#endif

}
