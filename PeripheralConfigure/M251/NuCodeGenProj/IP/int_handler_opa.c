
#if (NUCODEGEN_OPA)
#if (NUCODEGEN_OPA_INT_EN)
void OPA_IRQHandler(void)
{
    /* Check OPA interrupt flag is rising */
    if (OPA_GET_INT_FLAG(NUCODEGEN_OPA_MODULE_SEL, OPA_MODULE_0))
    {
       /* Clear OPA interrupt flag */
       OPA_CLR_INT_FLAG(NUCODEGEN_OPA_MODULE_SEL, OPA_MODULE_0);

       /* insert digital output of OPA. Ex: OPA_GET_DIGITAL_OUTPUT(OPA, 0); */

    }
}
#endif /* NUCODEGEN_OPA_INT_EN */
#endif /* NUCODEGEN_OPA */
