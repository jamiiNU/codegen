
#if (NUCODEGEN_OPA)
void OPA_Init()
{
#if (NUCODEGEN_OPA_SCHMIT_BUF_EN)
    /* Enable OPA0 schmitt trigger buffer */
    OPA_ENABLE_SCH_TRIGGER(NUCODEGEN_OPA_MODULE_SEL, OPA_MODULE_0);
#endif /* NUCODEGEN_OPA_SCHMIT_BUF_EN */

    /* Power on the OPA circuit */
    OPA_POWER_ON(NUCODEGEN_OPA_MODULE_SEL, OPA_MODULE_0);
    
#if (NUCODEGEN_OPA_INT_EN)
    /* Clear OPA interrupt flag */
    OPA_CLR_INT_FLAG(NUCODEGEN_OPA_MODULE_SEL, OPA_MODULE_0);

    /* Enable OPA interrupt function */
    OPA_ENABLE_INT(NUCODEGEN_OPA_MODULE_SEL, OPA_MODULE_0);
        
    /* Enable OPA interrupt */
    NVIC_EnableIRQ(NUCODEGEN_OPA_IRQ_MODULE_SEL);
#endif /* NUCODEGEN_OPA_INT_EN */

}
#endif /* NUCODEGEN_OPA */
