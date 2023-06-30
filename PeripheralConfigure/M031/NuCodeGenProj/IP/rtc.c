
#if (NUCODEGEN_RTC)
void RTC_Init(void)
{
    S_RTC_TIME_DATA_T sDateTimeInit, sDateTimeAlarm;

#if (NUCODEGEN_RTC_DATETIME_INIT)
    /* Configure RTC initial date and time structure. */
    sDateTimeInit.u32Year       = NUCODEGEN_RTC_CURRENT_YEAR_CONFIG;
    sDateTimeInit.u32Month      = NUCODEGEN_RTC_CURRENT_MONTH_CONFIG;
    sDateTimeInit.u32Day        = NUCODEGEN_RTC_CURRENT_DATE_CONFIG;
    sDateTimeInit.u32DayOfWeek  = NUCODEGEN_RTC_CURRENT_DOW_CONFIG;
    sDateTimeInit.u32Hour       = NUCODEGEN_RTC_CURRENT_HOUR_CONFIG;
    sDateTimeInit.u32Minute     = NUCODEGEN_RTC_CURRENT_MINUTE_CONFIG;
    sDateTimeInit.u32Second     = NUCODEGEN_RTC_CURRENT_SECOND_CONFIG;
    sDateTimeInit.u32TimeScale  = NUCODEGEN_RTC_TIMESCALE_CONFIG;
    sDateTimeInit.u32AmPm       = NUCODEGEN_RTC_CURRENT_AMPM_CONFIG;
#else
    /* Configure RTC initial date and time structure. */
    sDateTimeInit.u32Year       = 2015;
    sDateTimeInit.u32Month      = 8;
    sDateTimeInit.u32Day        = 8;
    sDateTimeInit.u32DayOfWeek  = RTC_SATURDAY;
    sDateTimeInit.u32Hour       = 0;
    sDateTimeInit.u32Minute     = 0;
    sDateTimeInit.u32Second     = 0;
    sDateTimeInit.u32TimeScale  = NUCODEGEN_RTC_TIMESCALE_CONFIG;
    sDateTimeInit.u32AmPm       = NUCODEGEN_RTC_CURRENT_AMPM_CONFIG;
#endif
    /* Initial RTC module. Setup RTC current date and time. */
    RTC_Open(&sDateTimeInit);

    /* Setup RTC tick period */
    RTC_SetTickPeriod(NUCODEGEN_RTC_TICK_CONFIG);

#if (NUCODEGEN_RTC_ALARM_ENABLE)
    /* Configure RTC alarm date and time structure. */
    sDateTimeAlarm.u32Year       = NUCODEGEN_RTC_ALARM_YEAR_CONFIG;
    sDateTimeAlarm.u32Month      = NUCODEGEN_RTC_ALARM_MONTH_CONFIG;
    sDateTimeAlarm.u32Day        = NUCODEGEN_RTC_ALARM_DATE_CONFIG;
    sDateTimeAlarm.u32Hour       = NUCODEGEN_RTC_ALARM_HOUR_CONFIG;
    sDateTimeAlarm.u32Minute     = NUCODEGEN_RTC_ALARM_MINUTE_CONFIG;
    sDateTimeAlarm.u32Second     = NUCODEGEN_RTC_ALARM_SECOND_CONFIG;
    sDateTimeAlarm.u32TimeScale  = NUCODEGEN_RTC_TIMESCALE_CONFIG;
    sDateTimeAlarm.u32AmPm       = NUCODEGEN_RTC_ALARM_AMPM_CONFIG;

    /* Setup RTC alarm date and time configurations */
    RTC_SetAlarmDateAndTime(&sDateTimeAlarm);
#else
    /* Configure RTC alarm date and time structure. */
    sDateTimeAlarm.u32Year       = RTC_YEAR2000;
    sDateTimeAlarm.u32Month      = 0;
    sDateTimeAlarm.u32Day        = 0;
    sDateTimeAlarm.u32Hour       = 0;
    sDateTimeAlarm.u32Minute     = 0;
    sDateTimeAlarm.u32Second     = 0;
    sDateTimeAlarm.u32TimeScale  = NUCODEGEN_RTC_TIMESCALE_CONFIG;
    sDateTimeAlarm.u32AmPm       = NUCODEGEN_RTC_ALARM_AMPM_CONFIG;

    /* Setup RTC alarm date and time configurations */
    RTC_SetAlarmDateAndTime(&sDateTimeAlarm);
#endif

    /* Setup RTC alarm date mask. */
    RTC_SetAlarmDateMask(RTC_ALARM_TEN_YEAR_MASK,  RTC_ALARM_ONE_YEAR_MASK,
                         RTC_ALARM_TEN_MONTH_MASK, RTC_ALARM_ONE_MONTH_MASK,
                         RTC_ALARM_TEN_DATE_MASK,  RTC_ALARM_ONE_DATE_MASK);

    /* Setup RTC alarm time mask. */
    RTC_SetAlarmTimeMask(RTC_ALARM_TEN_HOUR_MASK,   RTC_ALARM_ONE_HOUR_MASK,
                         RTC_ALARM_TEN_MINUTE_MASK, RTC_ALARM_ONE_MINUTE_MASK,
                         RTC_ALARM_TEN_SECOND_MASK, RTC_ALARM_ONE_SECOND_MASK);

#if (NUCODEGEN_RTC_FREQ_ADJ_ENABLE)
    /* Set Frequency Compensation Data */
    RTC_32KCalibration(RTC_LXT_FREQ);
#endif

    /* Clear RTC interrupt source and flag for safe */
    RTC_DisableInt(RTC_INTEN_TICKIEN_Msk|RTC_INTEN_ALMIEN_Msk);

#if (NUCODEGEN_RTC_INT_ENABLE)

    /* Enable RTC interrupt source */
    RTC_EnableInt(NUCODEGEN_RTC_INT_CONFIG);

    /* Enable RTC NVIC interrupt */
    NVIC_EnableIRQ(RTC_IRQn);
#endif
}
#endif /* NUCODEGEN_RTC */
