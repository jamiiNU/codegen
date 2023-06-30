
#if (NUCODEGEN_LCD)

#if ((NUCODEGEN_LCDFEINTEN != 0) || (NUCODEGEN_LCDFCINTEN != 0) || (NUCODEGEN_LCDCPINTEN != 0) )
/**
 * @brief       IRQ Handler for LCD Interrupt
 *
 * @param       None
 *
 * @return      None
 *
 * @details     The LCD_IRQHandler is default IRQ of LCD, declared in startup_M251.s.
 */
void LCD_IRQHandler(void)
{
#if (NUCODEGEN_LCDFEINTEN != 0)
    if (LCD_GET_FRAME_END_FLAG() == 1)
    {
        LCD_CLEAR_FRAME_END_FLAG();
    }
#endif /* (NUCODEGEN_LCDFEINTEN != 0) */

#if (NUCODEGEN_LCDFCINTEN != 0)
    if (LCD_GET_FRAME_COUNTING_END_FLAG() == 1)
    {
        LCD_CLEAR_FRAME_COUNTING_END_FLAG();
    }
#endif /* (NUCODEGEN_LCDFCINTEN != 0) */

#if (NUCODEGEN_LCDCPINTEN != 0)
    if (LCD_GET_CHARGE_TIMEOUT_FLAG() == 1)
    {
        LCD_CLEAR_CHARGE_TIMEOUT_FLAG();
    }
#endif /* (NUCODEGEN_LCDCPINTEN != 0) */
}
#endif /* ((NUCODEGEN_LCDFEINTEN != 0) || (NUCODEGEN_LCDFCINTEN != 0) || (NUCODEGEN_LCDCPINTEN != 0) ) */

#endif /* NUCODEGEN_LCD */
