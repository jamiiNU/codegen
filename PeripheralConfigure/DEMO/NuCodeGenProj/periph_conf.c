#include <stdio.h>
#include "NUC472_442.h"

#include "adc.h"
#include "eadc.h"
#include "i2c.h"
#include "pdma.h"
#include "timer.h"
#include "uart.h"
#include "wdt.h"

#include "periph_conf.h"

#if NUCODEGEN_ADC
void ADC_Init()
{
    ADC_Open(ADC, ADC_INPUT_MODE, ADC_OPERATION_MODE, ADC_CHANNEL);
    ADC_POWER_ON(ADC);

#if NUCODEGEN_ADCCMP0
    ADC_ENABLE_CMP0(ADC, ADC_CMP0_CHANNEL, ADC_CMP0_CONDITION, ADC_CMP0_DAT, ADC_CMP0_MATCH_COUNT);
#endif

#if NUCODEGEN_ADCCMP1
    ADC_ENABLE_CMP1(ADC, ADC_CMP1_CHANNEL, ADC_CMP1_CONDITION, ADC_CMP1_DAT, ADC_CMP1_MATCH_COUNT);
#endif

#if NUCODEGEN_ADCPDMA
    ADC_ENABLE_PDMA(ADC);
#endif

#if NUCODEGEN_ADC_INT || NUCODEGEN_ADC_CMP0_INT || NUCODEGEN_ADC_CMP1_INT
    ADC_EnableInt(ADC, NUCODEGEN_ADC_INT | NUCODEGEN_ADC_CMP0_INT | NUCODEGEN_ADC_CMP1_INT);
    NVIC_EnableIRQ(ADC_IRQn);
#endif
}

#if NUCODEGEN_ADC_INT || NUCODEGEN_ADC_CMP0_INT || NUCODEGEN_ADC_CMP1_INT
void ADC_IRQHandler(void)
{
}
#endif
#endif

#if NUCODEGEN_EADC
void EADC_Init()
{
    EADC_Open(EADC, 0);

#if NUCODEGEN_EADC0_MODULE0
    EADC_ConfigSampleModule(EADC, EADC0_SAMPLE_MODULE0, EADC0_TRIGGER_MODULE0, EADC0_CHANNEL_MODULE0);
    EADC_SetTriggerDelayTime(EADC, EADC0_SAMPLE_MODULE0, EADC0_TRGDLY_MODULE0, EADC0_TRGDLYDIV_MODULE0);
#endif
#if NUCODEGEN_EADC0_MODULE1
    EADC_ConfigSampleModule(EADC, EADC0_SAMPLE_MODULE1, EADC0_TRIGGER_MODULE1, EADC0_CHANNEL_MODULE1);
    EADC_SetTriggerDelayTime(EADC, EADC0_SAMPLE_MODULE1, EADC0_TRGDLY_MODULE1, EADC0_TRGDLYDIV_MODULE1);
#endif
#if NUCODEGEN_EADC0_MODULE2
    EADC_ConfigSampleModule(EADC, EADC0_SAMPLE_MODULE2, EADC0_TRIGGER_MODULE2, EADC0_CHANNEL_MODULE2);
    EADC_SetTriggerDelayTime(EADC, EADC0_SAMPLE_MODULE2, EADC0_TRGDLY_MODULE2, EADC0_TRGDLYDIV_MODULE2);
#endif
#if NUCODEGEN_EADC0_MODULE3
    EADC_ConfigSampleModule(EADC, EADC0_SAMPLE_MODULE3, EADC0_TRIGGER_MODULE3, EADC0_CHANNEL_MODULE3);
    EADC_SetTriggerDelayTime(EADC, EADC0_SAMPLE_MODULE3, EADC0_TRGDLY_MODULE3, EADC0_TRGDLYDIV_MODULE3);
#endif
#if NUCODEGEN_EADC0_MODULE4
    EADC_ConfigSampleModule(EADC, EADC0_SAMPLE_MODULE4, EADC0_TRIGGER_MODULE4, EADC0_CHANNEL_MODULE4);
    EADC_SetTriggerDelayTime(EADC, EADC0_SAMPLE_MODULE4, EADC0_TRGDLY_MODULE4, EADC0_TRGDLYDIV_MODULE4);
#endif
#if NUCODEGEN_EADC0_MODULE5
    EADC_ConfigSampleModule(EADC, EADC0_SAMPLE_MODULE5, EADC0_TRIGGER_MODULE5, EADC0_CHANNEL_MODULE5);
    EADC_SetTriggerDelayTime(EADC, EADC0_SAMPLE_MODULE5, EADC0_TRGDLY_MODULE5, EADC0_TRGDLYDIV_MODULE5);
#endif
#if NUCODEGEN_EADC0_MODULE6
    EADC_ConfigSampleModule(EADC, EADC0_SAMPLE_MODULE6, EADC0_TRIGGER_MODULE6, EADC0_CHANNEL_MODULE6);
    EADC_SetTriggerDelayTime(EADC, EADC0_SAMPLE_MODULE6, EADC0_TRGDLY_MODULE6, EADC0_TRGDLYDIV_MODULE6);
#endif
#if NUCODEGEN_EADC0_MODULE7
    EADC_ConfigSampleModule(EADC, EADC0_SAMPLE_MODULE7, EADC0_TRIGGER_MODULE7, EADC0_CHANNEL_MODULE7);
    EADC_SetTriggerDelayTime(EADC, EADC0_SAMPLE_MODULE6, EADC0_TRGDLY_MODULE7, EADC0_TRGDLYDIV_MODULE7);
#endif
#if NUCODEGEN_EADC1_MODULE0
    EADC_ConfigSampleModule(EADC, EADC1_SAMPLE_MODULE0, EADC1_TRIGGER_MODULE0, EADC1_CHANNEL_MODULE0);
    EADC_SetTriggerDelayTime(EADC, EADC1_SAMPLE_MODULE0, EADC1_TRGDLY_MODULE0, EADC1_TRGDLYDIV_MODULE0);
#endif
#if NUCODEGEN_EADC1_MODULE1
    EADC_ConfigSampleModule(EADC, EADC1_SAMPLE_MODULE1, EADC1_TRIGGER_MODULE1, EADC1_CHANNEL_MODULE1);
    EADC_SetTriggerDelayTime(EADC, EADC1_SAMPLE_MODULE1, EADC1_TRGDLY_MODULE1, EADC1_TRGDLYDIV_MODULE1);
#endif
#if NUCODEGEN_EADC1_MODULE2
    EADC_ConfigSampleModule(EADC, EADC1_SAMPLE_MODULE2, EADC1_TRIGGER_MODULE2, EADC1_CHANNEL_MODULE2);
    EADC_SetTriggerDelayTime(EADC, EADC1_SAMPLE_MODULE2, EADC1_TRGDLY_MODULE2, EADC1_TRGDLYDIV_MODULE2);
#endif
#if NUCODEGEN_EADC1_MODULE3
    EADC_ConfigSampleModule(EADC, EADC1_SAMPLE_MODULE3, EADC1_TRIGGER_MODULE3, EADC1_CHANNEL_MODULE3);
    EADC_SetTriggerDelayTime(EADC, EADC1_SAMPLE_MODULE3, EADC1_TRGDLY_MODULE3, EADC1_TRGDLYDIV_MODULE3);
#endif
#if NUCODEGEN_EADC1_MODULE4
    EADC_ConfigSampleModule(EADC, EADC1_SAMPLE_MODULE4, EADC1_TRIGGER_MODULE4, EADC1_CHANNEL_MODULE4);
    EADC_SetTriggerDelayTime(EADC, EADC1_SAMPLE_MODULE4, EADC1_TRGDLY_MODULE4, EADC1_TRGDLYDIV_MODULE4);
#endif
#if NUCODEGEN_EADC1_MODULE5
    EADC_ConfigSampleModule(EADC, EADC1_SAMPLE_MODULE5, EADC1_TRIGGER_MODULE5, EADC1_CHANNEL_MODULE5);
    EADC_SetTriggerDelayTime(EADC, EADC1_SAMPLE_MODULE5, EADC1_TRGDLY_MODULE5, EADC1_TRGDLYDIV_MODULE5);
#endif
#if NUCODEGEN_EADC1_MODULE6
    EADC_ConfigSampleModule(EADC, EADC1_SAMPLE_MODULE6, EADC1_TRIGGER_MODULE6, EADC1_CHANNEL_MODULE6);
    EADC_SetTriggerDelayTime(EADC, EADC1_SAMPLE_MODULE6, EADC1_TRGDLY_MODULE6, EADC1_TRGDLYDIV_MODULE6);
#endif
#if NUCODEGEN_EADC1_MODULE7
    EADC_ConfigSampleModule(EADC, EADC1_SAMPLE_MODULE7, EADC1_TRIGGER_MODULE7, EADC1_CHANNEL_MODULE7);
    EADC_SetTriggerDelayTime(EADC, EADC1_SAMPLE_MODULE7, EADC1_TRGDLY_MODULE7, EADC1_TRGDLYDIV_MODULE7);
#endif

    EADC_CLR_INT_FLAG(EADC, EADC_CLR_INT);

#if NUCODEGEN_EADC_SIMUL_MODE
    EADC_ENABLE_SIMULTANEOUS(EADC, EADC_SIMULTANEOUS_MODULE);
#endif

#if NUCODEGEN_EADC0_TRGCOND_MODULE0
    EADC_EnablePWMTriggerCondition(EADC, EADC0_TRIGGEREN0, EADC0_TRGCOND_MODULE0);
#endif
#if NUCODEGEN_EADC0_TRGCOND_MODULE1
    EADC_EnablePWMTriggerCondition(EADC, EADC0_TRIGGEREN1, EADC0_TRGCOND_MODULE1);
#endif
#if NUCODEGEN_EADC0_TRGCOND_MODULE2
    EADC_EnablePWMTriggerCondition(EADC, EADC0_TRIGGEREN2, EADC0_TRGCOND_MODULE2);
#endif
#if NUCODEGEN_EADC0_TRGCOND_MODULE3
    EADC_EnablePWMTriggerCondition(EADC, EADC0_TRIGGEREN3, EADC0_TRGCOND_MODULE3);
#endif
#if NUCODEGEN_EADC1_TRGCOND_MODULE0
    EADC_EnablePWMTriggerCondition(EADC, EADC1_TRIGGEREN0, EADC1_TRGCOND_MODULE0);
#endif
#if NUCODEGEN_EADC1_TRGCOND_MODULE1
    EADC_EnablePWMTriggerCondition(EADC, EADC1_TRIGGEREN1, EADC1_TRGCOND_MODULE1);
#endif
#if NUCODEGEN_EADC1_TRGCOND_MODULE2
    EADC_EnablePWMTriggerCondition(EADC, EADC1_TRIGGEREN2, EADC1_TRGCOND_MODULE2);
#endif
#if NUCODEGEN_EADC1_TRGCOND_MODULE3
    EADC_EnablePWMTriggerCondition(EADC, EADC1_TRIGGEREN3, EADC1_TRGCOND_MODULE3);
#endif


#if NUCODEGEN_EADC_INT0 || NUCODEGEN_EADC_INT1 || NUCODEGEN_EADC_INT2 || NUCODEGEN_EADC_INT3
    EADC_ENABLE_INT(EADC, (NUCODEGEN_EADC_INT0 << 0) | (NUCODEGEN_EADC_INT1 << 1) | (NUCODEGEN_EADC_INT2 << 2) | (NUCODEGEN_EADC_INT3 << 3));

#if NUCODEGEN_EADC_INT0
    EADC_ENABLE_SAMPLE_MODULE_INT(EADC, 0, EADC_SAMPLE_MODULE_INT0);
#endif
#if NUCODEGEN_EADC_INT1
    EADC_ENABLE_SAMPLE_MODULE_INT(EADC, 1, EADC_SAMPLE_MODULE_INT1);
#endif
#if NUCODEGEN_EADC_INT2
    EADC_ENABLE_SAMPLE_MODULE_INT(EADC, 2, EADC_SAMPLE_MODULE_INT2);
#endif
#if NUCODEGEN_EADC_INT3
    EADC_ENABLE_SAMPLE_MODULE_INT(EADC, 3, EADC_SAMPLE_MODULE_INT3);
#endif
    NVIC_EnableIRQ(EADC0_IRQn);
#endif

#if NUCODEGEN_EADC_CMP0
    EADC_ENABLE_CMP0(EADC, EADC_CMP0_SAMPLE_MODULE, EADC_CMP0_CONDITION, EADC_CMP0_DAT, EADC_CMP0_MATCH_COUNT);
#endif
#if NUCODEGEN_EADC_CMP1
    EADC_ENABLE_CMP1(EADC, EADC_CMP1_SAMPLE_MODULE, EADC_CMP1_CONDITION, EADC_CMP1_DAT, EADC_CMP1_MATCH_COUNT);
#endif
#if NUCODEGEN_EADC_CMP0_INT
    EADC_ENABLE_CMP_INT(EADC, 0);
#endif
#if NUCODEGEN_EADC_CMP1_INT
    EADC_ENABLE_CMP_INT(EADC, 1);
#endif
    EADC_START_CONV(EADC, (NUCODEGEN_EADC0_MODULE0 << 0) || (NUCODEGEN_EADC0_MODULE1 << 1) || (NUCODEGEN_EADC0_MODULE2 << 2) || (NUCODEGEN_EADC0_MODULE3 << 3) \
                             || (NUCODEGEN_EADC0_MODULE4 << 4) || (NUCODEGEN_EADC0_MODULE5 << 5) || (NUCODEGEN_EADC0_MODULE6 << 6) || (NUCODEGEN_EADC0_MODULE7 << 7) \
                              || (NUCODEGEN_EADC1_MODULE0 << 8) || (NUCODEGEN_EADC1_MODULE1 << 9) || (NUCODEGEN_EADC1_MODULE2 << 10) || (NUCODEGEN_EADC1_MODULE3 << 11) \
                               || (NUCODEGEN_EADC1_MODULE4 << 12) || (NUCODEGEN_EADC1_MODULE5 << 13) || (NUCODEGEN_EADC1_MODULE6 << 14) || (NUCODEGEN_EADC1_MODULE7 << 15));
}

#if NUCODEGEN_EADC_INT0 || NUCODEGEN_EADC_INT1 || NUCODEGEN_EADC_INT2 || NUCODEGEN_EADC_INT3 || NUCODEGEN_EADC_CMP0_INT || NUCODEGEN_EADC_CMP1_INT
void EADC0_IRQHandler(void)
{
}
#endif
#endif

#if NUCODEGEN_I2C0
void I2C0_Init()
{
    I2C_Open(I2C0, I2C0_BUSCLK);
    I2C_SetSlaveAddr(I2C0, 0, I2C0_ADDR0, I2C0_GCMODE);
    I2C_SetSlaveAddr(I2C0, 1, I2C0_ADDR1, I2C0_GCMODE);
    I2C_SetSlaveAddr(I2C0, 2, I2C0_ADDR2, I2C0_GCMODE);
    I2C_SetSlaveAddr(I2C0, 3, I2C0_ADDR3, I2C0_GCMODE);
    I2C_SetSlaveAddrMask(I2C0, 0, I2C0_ADDRMSK0);
    I2C_SetSlaveAddrMask(I2C0, 1, I2C0_ADDRMSK1);
    I2C_SetSlaveAddrMask(I2C0, 2, I2C0_ADDRMSK2);
    I2C_SetSlaveAddrMask(I2C0, 3, I2C0_ADDRMSK3);
#if NUCODEGEN_I2C0_INT
    I2C_EnableInt(I2C0);
    NVIC_EnableIRQ(I2C0_IRQn);
#endif
}

#if NUCODEGEN_I2C0_INT
void I2C0_IRQHandler(void)
{
}
#endif
#endif

#if (NUCODEGEN_PDMA_CH0 || NUCODEGEN_PDMA_CH1 || NUCODEGEN_PDMA_CH2 || NUCODEGEN_PDMA_CH3 || NUCODEGEN_PDMA_CH4 || NUCODEGEN_PDMA_CH5 || NUCODEGEN_PDMA_CH6 || NUCODEGEN_PDMA_CH7 \
    || NUCODEGEN_PDMA_CH8 || NUCODEGEN_PDMA_CH9 || NUCODEGEN_PDMA_CH10 || NUCODEGEN_PDMA_CH11 || NUCODEGEN_PDMA_CH12 || NUCODEGEN_PDMA_CH13 || NUCODEGEN_PDMA_CH14 || NUCODEGEN_PDMA_CH15)
#if NUCODEGEN_PDMA_CH0
    uint8_t SrcArray0[PDMA_CH0_DATA_LENGTH * 4];
    uint8_t DestArray0[PDMA_CH0_DATA_LENGTH * 4];
#endif
#if NUCODEGEN_PDMA_CH1
    uint8_t SrcArray1[PDMA_CH1_DATA_LENGTH * 4];
    uint8_t DestArray1[PDMA_CH1_DATA_LENGTH * 4];
#endif
#if NUCODEGEN_PDMA_CH2
    uint8_t SrcArray2[PDMA_CH2_DATA_LENGTH * 4];
    uint8_t DestArray2[PDMA_CH2_DATA_LENGTH * 4];
#endif
#if NUCODEGEN_PDMA_CH3
    uint8_t SrcArray3[PDMA_CH3_DATA_LENGTH * 4];
    uint8_t DestArray3[PDMA_CH3_DATA_LENGTH * 4];
#endif
#if NUCODEGEN_PDMA_CH4
    uint8_t SrcArray4[PDMA_CH4_DATA_LENGTH * 4];
    uint8_t DestArray4[PDMA_CH4_DATA_LENGTH * 4];
#endif
#if NUCODEGEN_PDMA_CH5
    uint8_t SrcArray5[PDMA_CH5_DATA_LENGTH * 4];
    uint8_t DestArray5[PDMA_CH5_DATA_LENGTH * 4];
#endif
#if NUCODEGEN_PDMA_CH6
    uint8_t SrcArray6[PDMA_CH6_DATA_LENGTH * 4];
    uint8_t DestArray6[PDMA_CH6_DATA_LENGTH * 4];
#endif
#if NUCODEGEN_PDMA_CH7
    uint8_t SrcArray7[PDMA_CH7_DATA_LENGTH * 4];
    uint8_t DestArray7[PDMA_CH7_DATA_LENGTH * 4];
#endif
#if NUCODEGEN_PDMA_CH8
    uint8_t SrcArray8[PDMA_CH8_DATA_LENGTH * 4];
    uint8_t DestArray8[PDMA_CH8_DATA_LENGTH * 4];
#endif
#if NUCODEGEN_PDMA_CH9
    uint8_t SrcArray9[PDMA_CH9_DATA_LENGTH * 4];
    uint8_t DestArray9[PDMA_CH9_DATA_LENGTH * 4];
#endif
#if NUCODEGEN_PDMA_CH10
    uint8_t SrcArray10[PDMA_CH10_DATA_LENGTH * 4];
    uint8_t DestArray10[PDMA_CH10_DATA_LENGTH * 4];
#endif
#if NUCODEGEN_PDMA_CH11
    uint8_t SrcArray11[PDMA_CH11_DATA_LENGTH * 4];
    uint8_t DestArray11[PDMA_CH11_DATA_LENGTH * 4];
#endif
#if NUCODEGEN_PDMA_CH12
    uint8_t SrcArray12[PDMA_CH12_DATA_LENGTH * 4];
    uint8_t DestArray12[PDMA_CH12_DATA_LENGTH * 4];
#endif
#if NUCODEGEN_PDMA_CH13
    uint8_t SrcArray13[PDMA_CH13_DATA_LENGTH * 4];
    uint8_t DestArray13[PDMA_CH13_DATA_LENGTH * 4];
#endif
#if NUCODEGEN_PDMA_CH14
    uint8_t SrcArray14[PDMA_CH14_DATA_LENGTH * 4];
    uint8_t DestArray14[PDMA_CH14_DATA_LENGTH * 4];
#endif
#if NUCODEGEN_PDMA_CH15
    uint8_t SrcArray15[PDMA_CH15_DATA_LENGTH * 4];
    uint8_t DestArray15[PDMA_CH15_DATA_LENGTH * 4];
#endif
void PDMA_Init()
{
#if NUCODEGEN_PDMA_CH0
    PDMA_Open(1 << 0);
    PDMA_SetTransferCnt(1 << 0, PDMA_CH0_WIDTH, PDMA_CH0_DATA_LENGTH);
    PDMA_SetTransferAddr(1 << 0, (uint32_t)PDMA_CH0_SRC_ADDR, PDMA_CH0_SAR_TYPE, (uint32_t)PDMA_CH0_DST_ADDR, PDMA_CH0_DAR_TYPE);
    PDMA_SetBurstType(1 << 0, PDMA_CH0_BURST_TYPE, PDMA_CH0_BURST_SIZE);
    PDMA_SetTransferMode(1 << 0, PDMA_CH0_SOURCE_SELECT, PDMA_CH0_OPERATION_MODE, 0);
    PDMA_Trigger(1 << 0);
#endif
#if NUCODEGEN_PDMA_CH1
    PDMA_Open(1 << 1);
    PDMA_SetTransferCnt(1 << 1, PDMA_CH1_WIDTH, PDMA_CH1_DATA_LENGTH);
    PDMA_SetTransferAddr(1 << 1, (uint32_t)PDMA_CH1_SRC_ADDR, PDMA_CH1_SAR_TYPE, (uint32_t)PDMA_CH1_DST_ADDR, PDMA_CH1_DAR_TYPE);
    PDMA_SetBurstType(1 << 1, PDMA_CH1_BURST_TYPE, PDMA_CH1_BURST_SIZE);
    PDMA_SetTransferMode(1 << 1, PDMA_CH1_SOURCE_SELECT, PDMA_CH1_OPERATION_MODE, 0);
    PDMA_Trigger(1 << 1);
#endif
#if NUCODEGEN_PDMA_CH2
    PDMA_Open(1 << 2);
    PDMA_SetTransferCnt(1 << 2, PDMA_CH2_WIDTH, PDMA_CH2_DATA_LENGTH);
    PDMA_SetTransferAddr(1 << 2, (uint32_t)PDMA_CH2_SRC_ADDR, PDMA_CH2_SAR_TYPE, (uint32_t)PDMA_CH2_DST_ADDR, PDMA_CH2_DAR_TYPE);
    PDMA_SetBurstType(1 << 2, PDMA_CH2_BURST_TYPE, PDMA_CH2_BURST_SIZE);
    PDMA_SetTransferMode(1 << 2, PDMA_CH2_SOURCE_SELECT, PDMA_CH2_OPERATION_MODE, 0);
    PDMA_Trigger(1 << 2);
#endif
#if NUCODEGEN_PDMA_CH3
    PDMA_Open(1 << 3);
    PDMA_SetTransferCnt(1 << 3, PDMA_CH3_WIDTH, PDMA_CH3_DATA_LENGTH);
    PDMA_SetTransferAddr(1 << 3, (uint32_t)PDMA_CH3_SRC_ADDR, PDMA_CH3_SAR_TYPE, (uint32_t)PDMA_CH3_DST_ADDR, PDMA_CH3_DAR_TYPE);
    PDMA_SetBurstType(1 << 3, PDMA_CH3_BURST_TYPE, PDMA_CH3_BURST_SIZE);
    PDMA_SetTransferMode(1 << 3, PDMA_CH3_SOURCE_SELECT, PDMA_CH3_OPERATION_MODE, 0);
    PDMA_Trigger(1 << 3);
#endif
#if NUCODEGEN_PDMA_CH4
    PDMA_Open(1 << 4);
    PDMA_SetTransferCnt(1 << 4, PDMA_CH4_WIDTH, PDMA_CH4_DATA_LENGTH);
    PDMA_SetTransferAddr(1 << 4, (uint32_t)PDMA_CH4_SRC_ADDR, PDMA_CH4_SAR_TYPE, (uint32_t)PDMA_CH4_DST_ADDR, PDMA_CH4_DAR_TYPE);
    PDMA_SetBurstType(1 << 4, PDMA_CH4_BURST_TYPE, PDMA_CH4_BURST_SIZE);
    PDMA_SetTransferMode(1 << 4, PDMA_CH4_SOURCE_SELECT, PDMA_CH4_OPERATION_MODE, 0);
    PDMA_Trigger(1 << 4);
#endif
#if NUCODEGEN_PDMA_CH5
    PDMA_Open(1 << 5);
    PDMA_SetTransferCnt(1 << 5, PDMA_CH5_WIDTH, PDMA_CH5_DATA_LENGTH);
    PDMA_SetTransferAddr(1 << 5, (uint32_t)PDMA_CH5_SRC_ADDR, PDMA_CH5_SAR_TYPE, (uint32_t)PDMA_CH5_DST_ADDR, PDMA_CH5_DAR_TYPE);
    PDMA_SetBurstType(1 << 5, PDMA_CH5_BURST_TYPE, PDMA_CH5_BURST_SIZE);
    PDMA_SetTransferMode(1 << 5, PDMA_CH5_SOURCE_SELECT, PDMA_CH5_OPERATION_MODE, 0);
    PDMA_Trigger(1 << 5);
#endif
#if NUCODEGEN_PDMA_CH6
    PDMA_Open(1 << 6);
    PDMA_SetTransferCnt(1 << 6, PDMA_CH6_WIDTH, PDMA_CH6_DATA_LENGTH);
    PDMA_SetTransferAddr(1 << 6, (uint32_t)PDMA_CH6_SRC_ADDR, PDMA_CH6_SAR_TYPE, (uint32_t)PDMA_CH6_DST_ADDR, PDMA_CH6_DAR_TYPE);
    PDMA_SetBurstType(1 << 6, PDMA_CH6_BURST_TYPE, PDMA_CH6_BURST_SIZE);
    PDMA_SetTransferMode(1 << 6, PDMA_CH6_SOURCE_SELECT, PDMA_CH6_OPERATION_MODE, 0);
    PDMA_Trigger(1 << 6);
#endif
#if NUCODEGEN_PDMA_CH7
    PDMA_Open(1 << 7);
    PDMA_SetTransferCnt(1 << 7, PDMA_CH7_WIDTH, PDMA_CH7_DATA_LENGTH);

    PDMA_SetTransferAddr(1 << 7, (uint32_t)PDMA_CH7_SRC_ADDR, PDMA_CH7_SAR_TYPE, (uint32_t)PDMA_CH7_DST_ADDR, PDMA_CH7_DAR_TYPE);
    PDMA_SetBurstType(1 << 7, PDMA_CH7_BURST_TYPE, PDMA_CH7_BURST_SIZE);
    PDMA_SetTransferMode(1 << 7, PDMA_CH7_SOURCE_SELECT, PDMA_CH7_OPERATION_MODE, 0);
    PDMA_Trigger(1 << 7);
#endif
#if NUCODEGEN_PDMA_CH8
    PDMA_Open(1 << 8);
    PDMA_SetTransferCnt(1 << 8, PDMA_CH8_WIDTH, PDMA_CH8_DATA_LENGTH);
    PDMA_SetTransferAddr(1 << 8, (uint32_t)PDMA_CH8_SRC_ADDR, PDMA_CH8_SAR_TYPE, (uint32_t)PDMA_CH8_DST_ADDR, PDMA_CH8_DAR_TYPE);
    PDMA_SetBurstType(1 << 8, PDMA_CH8_BURST_TYPE, PDMA_CH8_BURST_SIZE);
    PDMA_SetTransferMode(1 << 8, PDMA_CH8_SOURCE_SELECT, PDMA_CH8_OPERATION_MODE, 0);
    PDMA_Trigger(1 << 8);
#endif
#if NUCODEGEN_PDMA_CH9
    PDMA_Open(1 << 9);
    PDMA_SetTransferCnt(1 << 9, PDMA_CH9_WIDTH, PDMA_CH9_DATA_LENGTH);
    PDMA_SetTransferAddr(1 << 9, (uint32_t)PDMA_CH9_SRC_ADDR, PDMA_CH9_SAR_TYPE, (uint32_t)PDMA_CH9_DST_ADDR, PDMA_CH9_DAR_TYPE);
    PDMA_SetBurstType(1 << 9, PDMA_CH9_BURST_TYPE, PDMA_CH9_BURST_SIZE);
    PDMA_SetTransferMode(1 << 9, PDMA_CH9_SOURCE_SELECT, PDMA_CH9_OPERATION_MODE, 0);
    PDMA_Trigger(1 << 9);
#endif
#if NUCODEGEN_PDMA_CH10
    PDMA_Open(1 << 10);
    PDMA_SetTransferCnt(1 << 10, PDMA_CH10_WIDTH, PDMA_CH10_DATA_LENGTH);
    PDMA_SetTransferAddr(1 << 10, (uint32_t)PDMA_CH10_SRC_ADDR, PDMA_CH10_SAR_TYPE, (uint32_t)PDMA_CH10_DST_ADDR, PDMA_CH10_DAR_TYPE);
    PDMA_SetBurstType(1 << 10, PDMA_CH10_BURST_TYPE, PDMA_CH10_BURST_SIZE);
    PDMA_SetTransferMode(1 << 10, PDMA_CH10_SOURCE_SELECT, PDMA_CH10_OPERATION_MODE, 0);
    PDMA_Trigger(1 << 10);
#endif
#if NUCODEGEN_PDMA_CH11
    PDMA_Open(1 << 11);
    PDMA_SetTransferCnt(1 << 11, PDMA_CH11_WIDTH, PDMA_CH11_DATA_LENGTH);
    PDMA_SetTransferAddr(1 << 11, (uint32_t)PDMA_CH11_SRC_ADDR, PDMA_CH11_SAR_TYPE, (uint32_t)PDMA_CH11_DST_ADDR, PDMA_CH11_DAR_TYPE);
    PDMA_SetBurstType(1 << 11, PDMA_CH11_BURST_TYPE, PDMA_CH11_BURST_SIZE);
    PDMA_SetTransferMode(1 << 11, PDMA_CH11_SOURCE_SELECT, PDMA_CH11_OPERATION_MODE, 0);
    PDMA_Trigger(1 << 11);
#endif
#if NUCODEGEN_PDMA_CH12
    PDMA_Open(1 << 12);
    PDMA_SetTransferCnt(1 << 12, PDMA_CH12_WIDTH, PDMA_CH12_DATA_LENGTH);
    PDMA_SetTransferAddr(1 << 12, (uint32_t)PDMA_CH12_SRC_ADDR, PDMA_CH12_SAR_TYPE, (uint32_t)PDMA_CH12_DST_ADDR, PDMA_CH12_DAR_TYPE);
    PDMA_SetBurstType(1 << 12, PDMA_CH12_BURST_TYPE, PDMA_CH12_BURST_SIZE);
    PDMA_SetTransferMode(1 << 12, PDMA_CH12_SOURCE_SELECT, PDMA_CH12_OPERATION_MODE, 0);
    PDMA_Trigger(1 << 12);
#endif
#if NUCODEGEN_PDMA_CH13
    PDMA_Open(1 << 13);
    PDMA_SetTransferCnt(1 << 13, PDMA_CH13_WIDTH, PDMA_CH13_DATA_LENGTH);
    PDMA_SetTransferAddr(1 << 13, (uint32_t)PDMA_CH13_SRC_ADDR, PDMA_CH13_SAR_TYPE, (uint32_t)PDMA_CH13_DST_ADDR, PDMA_CH13_DAR_TYPE);
    PDMA_SetBurstType(1 << 13, PDMA_CH13_BURST_TYPE, PDMA_CH13_BURST_SIZE);
    PDMA_SetTransferMode(1 << 13, PDMA_CH13_SOURCE_SELECT, PDMA_CH13_OPERATION_MODE, 0);
    PDMA_Trigger(1 << 13);
#endif
#if NUCODEGEN_PDMA_CH14
    PDMA_Open(1 << 14);
    PDMA_SetTransferCnt(1 << 14, PDMA_CH14_WIDTH, PDMA_CH14_DATA_LENGTH);
    PDMA_SetTransferAddr(1 << 14, (uint32_t)PDMA_CH14_SRC_ADDR, PDMA_CH14_SAR_TYPE, (uint32_t)PDMA_CH14_DST_ADDR, PDMA_CH14_DAR_TYPE);
    PDMA_SetBurstType(1 << 14, PDMA_CH14_BURST_TYPE, PDMA_CH14_BURST_SIZE);
    PDMA_SetTransferMode(1 << 14, PDMA_CH14_SOURCE_SELECT, PDMA_CH14_OPERATION_MODE, 0);
    PDMA_Trigger(1 << 14);
#endif
#if NUCODEGEN_PDMA_CH15
    PDMA_Open(1 << 15);
    PDMA_SetTransferCnt(1 << 15, PDMA_CH15_WIDTH, PDMA_CH15_DATA_LENGTH);
    PDMA_SetTransferAddr(1 << 15, (uint32_t)PDMA_CH15_SRC_ADDR, PDMA_CH15_SAR_TYPE, (uint32_t)PDMA_CH15_DST_ADDR, PDMA_CH15_DAR_TYPE);
    PDMA_SetBurstType(1 << 15, PDMA_CH15_BURST_TYPE, PDMA_CH15_BURST_SIZE);
    PDMA_SetTransferMode(1 << 15, PDMA_CH15_SOURCE_SELECT, PDMA_CH15_OPERATION_MODE, 0);
    PDMA_Trigger(1 << 15);
#endif


#if NUCODEGEN_PDMA_CH0_INT
    PDMA_EnableInt(1 << 0, 0);
#endif
#if NUCODEGEN_PDMA_CH1_INT
    PDMA_EnableInt(1 << 1, 0);
#endif
#if NUCODEGEN_PDMA_CH2_INT
    PDMA_EnableInt(1 << 2, 0);
#endif
#if NUCODEGEN_PDMA_CH3_INT
    PDMA_EnableInt(1 << 3, 0);
#endif
#if NUCODEGEN_PDMA_CH4_INT
    PDMA_EnableInt(1 << 4, 0);
#endif
#if NUCODEGEN_PDMA_CH5_INT
    PDMA_EnableInt(1 << 5, 0);
#endif
#if NUCODEGEN_PDMA_CH6_INT
    PDMA_EnableInt(1 << 6, 0);
#endif
#if NUCODEGEN_PDMA_CH7_INT
    PDMA_EnableInt(1 << 7, 0);
#endif
#if NUCODEGEN_PDMA_CH8_INT
    PDMA_EnableInt(1 << 8, 0);
#endif
#if NUCODEGEN_PDMA_CH9_INT
    PDMA_EnableInt(1 << 9, 0);
#endif
#if NUCODEGEN_PDMA_CH10_INT
    PDMA_EnableInt(1 << 10, 0);
#endif
#if NUCODEGEN_PDMA_CH11_INT
    PDMA_EnableInt(1 << 11, 0);
#endif
#if NUCODEGEN_PDMA_CH12_INT
    PDMA_EnableInt(1 << 12, 0);
#endif
#if NUCODEGEN_PDMA_CH13_INT
    PDMA_EnableInt(1 << 13, 0);
#endif
#if NUCODEGEN_PDMA_CH14_INT
    PDMA_EnableInt(1 << 14, 0);
#endif
#if NUCODEGEN_PDMA_CH15_INT
    PDMA_EnableInt(1 << 15, 0);
#endif

#if (NUCODEGEN_PDMA_CH0_INT || NUCODEGEN_PDMA_CH1_INT || NUCODEGEN_PDMA_CH2_INT || NUCODEGEN_PDMA_CH3_INT || NUCODEGEN_PDMA_CH4_INT || NUCODEGEN_PDMA_CH5_INT \
    || NUCODEGEN_PDMA_CH6_INT || NUCODEGEN_PDMA_CH7_INT || NUCODEGEN_PDMA_CH8_INT || NUCODEGEN_PDMA_CH9_INT || NUCODEGEN_PDMA_CH10_INT || NUCODEGEN_PDMA_CH11_INT \
    || NUCODEGEN_PDMA_CH12_INT || NUCODEGEN_PDMA_CH13_INT || NUCODEGEN_PDMA_CH14_INT || NUCODEGEN_PDMA_CH15_INT)
    NVIC_EnableIRQ(PDMA_IRQn);
#endif
}

#if (NUCODEGEN_PDMA_CH0_INT || NUCODEGEN_PDMA_CH1_INT || NUCODEGEN_PDMA_CH2_INT || NUCODEGEN_PDMA_CH3_INT || NUCODEGEN_PDMA_CH4_INT || NUCODEGEN_PDMA_CH5_INT \
    || NUCODEGEN_PDMA_CH6_INT || NUCODEGEN_PDMA_CH7_INT || NUCODEGEN_PDMA_CH8_INT || NUCODEGEN_PDMA_CH9_INT || NUCODEGEN_PDMA_CH10_INT || NUCODEGEN_PDMA_CH11_INT \
    || NUCODEGEN_PDMA_CH12_INT || NUCODEGEN_PDMA_CH13_INT || NUCODEGEN_PDMA_CH14_INT || NUCODEGEN_PDMA_CH15_INT)
void PDMA_IRQHandler(void)
{
}
#endif
#endif

#if NUCODEGEN_TIMER0
void TIMER0_Init()
{
    TIMER_Open(TIMER0, TIMER0_MODE, TIMER0_FREQ);

#if NUCODEGEN_TIMER0_CNT || NUCODEGEN_TIMER0_EXT_CAP
    TIMER_SET_PRESCALE_VALUE(TIMER0, TIMER0_PRESCALE_VALUE);
    TIMER_SET_CMP_VALUE(TIMER0, TIMER0_CMP_VALUE);
#endif

#if NUCODEGEN_TIMER0_CNT
    // Counter increase on falling edge
    TIMER_EnableEventCounter(TIMER0, TIMER0_COUNTER_PHASE);
#endif

#if NUCODEGEN_TIMER0_EXT_CAP
    // Configure Timer 0 free counting mode, capture TDR value on rising edge
    TIMER_EnableCapture(TIMER0, TIMER0_EXT_FUNS, TIMER0_EXT_EDGE); 
#endif

#if NUCODEGEN_TIMER0_WAKEUP
    TIMER_EnableWakeup(TIMER0);
#endif
#if NUCODEGEN_TIMER0_INT
    // Enable timer interrupt
    TIMER_EnableInt(TIMER0);
#endif

#if NUCODEGEN_TIMER0_CAP_INT
    TIMER_EnableCaptureInt(TIMER0);
#endif

#if NUCODEGEN_TIMER0_INT || NUCODEGEN_TIMER0_CAP_INT
    NVIC_EnableIRQ(TMR0_IRQn);
#endif

    // Start Timer 0
    TIMER_Start(TIMER0);

}

#if NUCODEGEN_TIMER0_INT
void TIMER0_IRQHandler(void)
{
}
#endif
#endif

#if NUCODEGEN_UART0
void UART0_Init()
{
    UART_Open(UART0, UART0_BAUD);
    UART0->FUNCSEL = NUCODEGEN_UART0_FUNCSEL;
    UART0->FIFO = (UART0->FIFO &~ UART_FIFO_RFITL_Msk) | UART0_TRGLEVEL;
    UART0->FIFO = (UART0->FIFO &~ UART_FIFO_RTSTRGLV_Msk) | UART0_RTSTRGLEVEL;
#if (NUCODEGEN_UART0_FUNCSEL == UART_FUNCSEL_RS485)
    UART_SelectRS485Mode(UART0, UART0_RS485_ALTCTL, UART0_RS485_ADDRV);
#elif (NUCODEGEN_UART0_FUNCSEL == UART_FUNCSEL_IrDA)
    UART_SelectIrDAMode(UART0, UART0_BAUD, UART0_IRDA_TX_ENABLE);
#endif
    UART_SetTimeoutCnt(UART0, UART0_TOCNT);
    UART_SetLine_Config(UART0, 0, UART0_WORD_LEN, UART0_PARITY, UART0_STOP_BIT);
#if NUCODEGEN_UART0_INT
    UART_ENABLE_INT(UART0, NUCODEGEN_UART0_INT);
    NVIC_EnableIRQ(UART0_IRQn);
#endif
}

#if NUCODEGEN_UART0_INT
void UART0_IRQHandler(void)
{
}
#endif
#endif

#if NUCODEGEN_UART1
void UART1_Init()
{
    UART_Open(UART1, UART1_BAUD);
    UART1->FUNCSEL = NUCODEGEN_UART1_FUNCSEL;
    UART1->FIFO = (UART1->FIFO &~ UART_FIFO_RFITL_Msk) | UART1_TRGLEVEL;
    UART1->FIFO = (UART1->FIFO &~ UART_FIFO_RTSTRGLV_Msk) | UART1_RTSTRGLEVEL;
#if (NUCODEGEN_UART1_FUNCSEL == UART_FUNCSEL_RS485)
    UART_SelectRS485Mode(UART1, UART1_RS485_ALTCTL, UART1_RS485_ADDRV);
#elif (NUCODEGEN_UART1_FUNCSEL == UART_FUNCSEL_IrDA)
    UART_SelectIrDAMode(UART1, UART1_BAUD, UART1_IRDA_TX_ENABLE);
#endif
    UART_SetTimeoutCnt(UART1, UART1_TOCNT);
    UART_SetLine_Config(UART1, 0, UART1_WORD_LEN, UART1_PARITY, UART1_STOP_BIT);
#if NUCODEGEN_UART1_INT
    UART_ENABLE_INT(UART1, NUCODEGEN_UART1_INT);
    NVIC_EnableIRQ(UART1_IRQn);
#endif
}

#if NUCODEGEN_UART1_INT
void UART1_IRQHandler(void)
{
}
#endif
#endif

#if NUCODEGEN_WDT
void WDT_Init()
{
    WDT_Open(WDT_TIMEOUT, 0, WDT_RESET, WDT_WAKEUP);
#if NUCODEGEN_WDT_INT
    WDT_EnableInt();
    NVIC_EnableIRQ(WDT_IRQn);
#endif
}

#if NUCODEGEN_WDT_INT
void WDT_IRQHandler(void)
{
}
#endif
#endif

void Periph_Init(void)
{
#if NUCODEGEN_ADC
    ADC_Init();
#endif

#if NUCODEGEN_EADC
    EADC_Init();
#endif

#if NUCODEGEN_I2C0
    I2C0_Init();
#endif

#if NUCODEGEN_TIMER0
    TIMER0_Init();
#endif

#if NUCODEGEN_UART0
    UART0_Init();
#endif

#if NUCODEGEN_UART1
    UART1_Init();
#endif

#if NUCODEGEN_WDT
    WDT_Init();
#endif

#if NUCODEGEN_PDMA
    PDMA_Init();
#endif
}
