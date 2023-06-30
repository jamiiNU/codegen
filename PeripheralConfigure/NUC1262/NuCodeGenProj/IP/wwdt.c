

#if (NUCODEGEN_WWDT)
void WWDT_Init(void)
{
    /* Setup WWDT configurations.
       Note that WWDT CTL register can only be written once after the chip resets. */
    WWDT_Open(WWDT_PRESCALER_CONFIG, WWDT_CMPDAT_CONFIG, WWDT_INTEN_CONFIG);

#if (NUCODEGEN_WWDT_INT_ENABLE)
    /* NVIC Enable WWDT Interrupt */
    NVIC_EnableIRQ(WDT_IRQn);
#endif
}
#endif /* NUCODEGEN_WWDT */

