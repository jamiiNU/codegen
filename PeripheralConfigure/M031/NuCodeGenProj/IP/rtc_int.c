
#if (NUCODEGEN_RTC)
#if (NUCODEGEN_RTC_INT_ENABLE)
void RTC_IRQHandler(void)
{
    /* Get RTC Tick Interrupt Flag */
    if (RTC_GET_TICK_INT_FLAG() && (RTC->INTEN & RTC_INTEN_TICKIEN_Msk))
    {
        /* Clear RTC Tick Interrupt Flag */
        RTC_CLEAR_TICK_INT_FLAG();
    }

    /* Get RTC Alarm Interrupt Flag */
    if (RTC_GET_ALARM_INT_FLAG() && (RTC->INTEN & RTC_INTEN_ALMIEN_Msk))
    {
        /* Clear RTC Alarm Interrupt Flag */
        RTC_CLEAR_ALARM_INT_FLAG();
    }
}
#endif /* NUCODEGEN_RTC_INT_ENABLE */
#endif /* NUCODEGEN_RTC */
