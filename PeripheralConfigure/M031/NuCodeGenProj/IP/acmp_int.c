
#if (NUCODEGEN_ACMP)
#if (NUCODEGEN_ACMP0_INT_EN || NUCODEGEN_ACMP1_INT_EN)
void ACMP01_IRQHandler(void)
{
#if (NUCODEGEN_ACMP0_INT_EN)
    /* Check ACMP0 interrupt flag is rising */
    if (ACMP_GET_INT_FLAG(NUCODEGEN_ACMP_MODULE_SEL, ACMP_MODULE_0))
    {
        /* Clear ACMP 0 interrupt flag */
        ACMP_CLR_INT_FLAG(NUCODEGEN_ACMP_MODULE_SEL, ACMP_MODULE_0);

       /* insert get output data of ACMP0. Ex: ACMP_GET_OUTPUT(ACMP01, 0); */

    }
#endif /* NUCODEGEN_ACMP0_INT_EN */

#if (NUCODEGEN_ACMP0_WKP_EN)

      /* Clear ACMP 0 wake up interrupt flag */
      ACMP_CLR_WAKEUP_INT_FLAG(NUCODEGEN_ACMP_MODULE_SEL,ACMP_MODULE_0);

#endif /* NUCODEGEN_ACMP0_WKP_EN */

#if (NUCODEGEN_ACMP1_INT_EN)
    /* Check ACMP1 interrupt flag is rising */
    if (ACMP_GET_INT_FLAG(NUCODEGEN_ACMP_MODULE_SEL, ACMP_MODULE_1))
    {
       /* Clear ACMP 1 interrupt flag */
       ACMP_CLR_INT_FLAG(NUCODEGEN_ACMP_MODULE_SEL, ACMP_MODULE_1);

       /* insert get output data of ACMP1. Ex: ACMP_GET_OUTPUT(ACMP01, 1); */

    }
#endif /* NUCODEGEN_ACMP1_INT_EN */

#if (NUCODEGEN_ACMP1_WKP_EN)
     /* Clear ACMP 1 wake up interrupt flag */
     ACMP_CLR_WAKEUP_INT_FLAG(NUCODEGEN_ACMP_MODULE_SEL,ACMP_MODULE_1);

#endif /* NUCODEGEN_ACMP1_WKP_EN */

}
#endif /* (NUCODEGEN_ACMP0_INT_EN || NUCODEGEN_ACMP1_INT_EN) */
#endif /* NUCODEGEN_ACMP */
