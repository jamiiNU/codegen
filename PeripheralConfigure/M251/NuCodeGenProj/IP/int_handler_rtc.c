
#if (NUCODEGEN_RTC)
#if (NUCODEGEN_RTC_INT_ENABLE)
void RTC_IRQHandler(void)
{
    /* Get RTC Tick Interrupt Flag */
    if (RTC_GET_TICK_INT_FLAG())
    {
        /* Clear RTC Tick Interrupt Flag */
        RTC_CLEAR_TICK_INT_FLAG();
    }

    /* Get RTC Alarm Interrupt Flag */
    if (RTC_GET_ALARM_INT_FLAG())
    {
        /* Clear RTC Alarm Interrupt Flag */
        RTC_CLEAR_ALARM_INT_FLAG();
    }

#if (NUCODEGEN_RTC_TAMPER_PIN_SUPPORT)
    /* Get RTC Tamper Interrupt Flag */
    if (RTC_GET_TAMPER_INT_FLAG())
    {
        /* Clear RTC Tamper Interrupt Flag */
        RTC_CLEAR_TAMPER_INT_FLAG(RTC_INTSTS_TAMP0IF_Msk);
    }
#endif
}
#endif /* NUCODEGEN_RTC_INT_ENABLE */
#endif /* NUCODEGEN_RTC */
