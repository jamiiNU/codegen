
#if (NUCODEGEN_EADC)

#if (((NUCODEGEN_EADCINT)&0x1) == 0x1)
void EADC_INT0_IRQHandler(void)
{
    if(EADC_GET_INT_FLAG(NUCODEGEN_EADC_MODULE_SEL, EADC_STATUS2_ADIF0_Msk))
    {
       /* Clear the A/D ADINT0 interrupt flag */
       EADC_CLR_INT_FLAG(NUCODEGEN_EADC_MODULE_SEL, EADC_STATUS2_ADIF0_Msk);
       printf("ADINT0 interrupt occurred !\n");
       
       /* get convert result, trigger next sample module, ..etc*/
    }
}
#endif /* (((NUCODEGEN_EADCINT)&0x1) == 0x1) */


#if (((NUCODEGEN_EADCINT)&0x2) == 0x2)
void EADC_INT1_IRQHandler(void)
{
    if(EADC_GET_INT_FLAG(NUCODEGEN_EADC_MODULE_SEL, EADC_STATUS2_ADIF1_Msk))
    {
       /* Clear the A/D ADINT1 interrupt flag */
       EADC_CLR_INT_FLAG(NUCODEGEN_EADC_MODULE_SEL, EADC_STATUS2_ADIF1_Msk);
       printf("ADINT1 interrupt occurred !\n");
       
       /* get convert result, trigger next sample module, ..etc*/
    }
}
#endif /* (((NUCODEGEN_EADCINT)&0x2) == 0x2) */


#if (((NUCODEGEN_EADCINT)&0x4) == 0x4)
void EADC_INT2_IRQHandler(void)
{
    if(EADC_GET_INT_FLAG(NUCODEGEN_EADC_MODULE_SEL, EADC_STATUS2_ADIF2_Msk))
    {
       /* Clear the A/D ADINT2 interrupt flag */
       EADC_CLR_INT_FLAG(NUCODEGEN_EADC_MODULE_SEL, EADC_STATUS2_ADIF2_Msk);
       printf("ADINT2 interrupt occurred !\n");
       
       /* get convert result, trigger next sample module, ..etc*/
    }
}
#endif /* (((NUCODEGEN_EADCINT)&0x4) == 0x4) */

#if (((NUCODEGEN_EADCINT)&0x8) == 0x8)
void EADC_INT3_IRQHandler(void)
{
    if(EADC_GET_INT_FLAG(NUCODEGEN_EADC_MODULE_SEL, EADC_STATUS2_ADIF3_Msk))
    {
       /* Clear the A/D ADINT3 interrupt flag */
       EADC_CLR_INT_FLAG(NUCODEGEN_EADC_MODULE_SEL, EADC_STATUS2_ADIF3_Msk);
       printf("ADINT3 interrupt occurred !\n");
       
       /* get convert result, trigger next sample module, ..etc*/
    }   
#if (NUCODEGEN_EADCCMP0CMPINT)
    else if(EADC_GET_INT_FLAG(NUCODEGEN_EADC_MODULE_SEL, EADC_STATUS2_ADCMPF0_Msk))
    {
       /* Clear the A/D Compare0 interrupt flag */
       EADC_CLR_INT_FLAG(NUCODEGEN_EADC_MODULE_SEL, EADC_STATUS2_ADCMPF0_Msk);
       printf("ADCMPF0 interrupt occurred !\n");
    }
#endif /* NUCODEGEN_EADCCMP0CMPINT */
#if (NUCODEGEN_EADCCMP1CMPINT)
    else if(EADC_GET_INT_FLAG(NUCODEGEN_EADC_MODULE_SEL, EADC_STATUS2_ADCMPF1_Msk))
    {
       /* Clear the A/D Compare1 interrupt flag */
       EADC_CLR_INT_FLAG(NUCODEGEN_EADC_MODULE_SEL, EADC_STATUS2_ADCMPF1_Msk);
       printf("ADCMPF1 interrupt occurred !\n");
    }
#endif /* NUCODEGEN_EADCCMP1CMPINT */
#if (NUCODEGEN_EADCCMP2CMPINT)
    else if(EADC_GET_INT_FLAG(NUCODEGEN_EADC_MODULE_SEL, EADC_STATUS2_ADCMPF2_Msk))
    {
       /* Clear the A/D Compare2 interrupt flag */
       EADC_CLR_INT_FLAG(NUCODEGEN_EADC_MODULE_SEL, EADC_STATUS2_ADCMPF2_Msk);
       printf("ADCMPF2 interrupt occurred !\n");
    }
#endif /* NUCODEGEN_EADCCMP2CMPINT */
#if (NUCODEGEN_EADCCMP3CMPINT)
    else if(EADC_GET_INT_FLAG(NUCODEGEN_EADC_MODULE_SEL, EADC_STATUS2_ADCMPF3_Msk))
    {
       /* Clear the A/D Compare3 interrupt flag */
       EADC_CLR_INT_FLAG(NUCODEGEN_EADC_MODULE_SEL, EADC_STATUS2_ADCMPF3_Msk);
       printf("ADCMPF3 interrupt occurred !\n");
    }
#endif /* NUCODEGEN_EADCCMP3CMPINT */
}
#endif /* (((NUCODEGEN_EADCINT)&0x8) == 0x8) */

#endif /* NUCODEGEN_EADC */
