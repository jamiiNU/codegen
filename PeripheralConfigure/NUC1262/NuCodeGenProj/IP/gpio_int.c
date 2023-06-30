
#if NUCODEGEN_GPIO
#if (NUCODEGEN_GPIO_PA_INT||NUCODEGEN_GPIO_PB_INT)
void GPAB_IRQHandler(void)
{
#if NUCODEGEN_GPIO_PA_INT
    /* To check if PA.1 interrupt occurred */
    if (GPIO_GET_INT_FLAG(PA, BIT1))
    {
        GPIO_CLR_INT_FLAG(PA, BIT1);
        printf("PA.1 INT occurred.\n");
    }
#endif

#if NUCODEGEN_GPIO_PB_INT
    /* To check if PB.2 interrupt occurred */
    if (GPIO_GET_INT_FLAG(PB, BIT2))
    {
        GPIO_CLR_INT_FLAG(PB, BIT2);
        printf("PB.2 INT occurred.\n");
    }
#endif
}
#endif

#if (NUCODEGEN_GPIO_PC_INT||NUCODEGEN_GPIO_PD_INT||NUCODEGEN_GPIO_PF_INT)
void GPCDF_IRQHandler(void)
{
#if NUCODEGEN_GPIO_PC_INT
    /* To check if PC.0 interrupt occurred */
    if (GPIO_GET_INT_FLAG(PC, BIT0))
    {
        GPIO_CLR_INT_FLAG(PC, BIT0);
        printf("PC.0 INT occurred.\n");
    }
#endif

#if NUCODEGEN_GPIO_PD_INT
    /* To check if PD.0 interrupt occurred */
    if (GPIO_GET_INT_FLAG(PD, BIT0))
    {
        GPIO_CLR_INT_FLAG(PD, BIT0);
        printf("PD.0 INT occurred.\n");
    }
#endif

#if NUCODEGEN_GPIO_PF_INT
    /* To check if PF.0 interrupt occurred */
    if (GPIO_GET_INT_FLAG(PF, BIT0))
    {
        GPIO_CLR_INT_FLAG(PF, BIT0);
        printf("PF.0 INT occurred.\n");
    }
#endif
}
#endif

#if (NUCODEGEN_GPIO_PA_EINT0 || NUCODEGEN_GPIO_PB_EINT0)||(NUCODEGEN_GPIO_PC_EINT2 || NUCODEGEN_GPIO_PB_EINT2)||(NUCODEGEN_GPIO_PA_EINT4 || NUCODEGEN_GPIO_PB_EINT4|| NUCODEGEN_GPIO_PF_EINT4)
void EINT024_IRQHandler(void)
{
#if NUCODEGEN_GPIO_PA_EINT0
    /* To check if PA.6 external interrupt occurred */
    if (GPIO_GET_INT_FLAG(PA, BIT6))
    {
        GPIO_CLR_INT_FLAG(PA, BIT6);
        printf("PA.6 EINT0 occurred.\n");
    }
#endif

#if NUCODEGEN_GPIO_PB_EINT0
    /* To check if PB.5 external interrupt occurred */
    if (GPIO_GET_INT_FLAG(PB, BIT5))
    {
        GPIO_CLR_INT_FLAG(PB, BIT5);
        printf("PB.5 EINT0 occurred.\n");
    }
#endif

#if NUCODEGEN_GPIO_PC_EINT2
    /* To check if PB.3 external interrupt occurred */
    if (GPIO_GET_INT_FLAG(PB, BIT3))
    {
        GPIO_CLR_INT_FLAG(PB, BIT3);
        printf("PB.3 EINT2 occurred.\n");
    }
#endif

#if NUCODEGEN_GPIO_PB_EINT2
    /* To check if PC.6 external interrupt occurred */
    if (GPIO_GET_INT_FLAG(PC, BIT6))
    {
        GPIO_CLR_INT_FLAG(PC, BIT6);
        printf("PC.6 EINT2 occurred.\n");
    }
#endif

#if NUCODEGEN_GPIO_PB_EINT4
    /* To check if PB.6 external interrupt occurred */
    if (GPIO_GET_INT_FLAG(PB, BIT6))
    {
        GPIO_CLR_INT_FLAG(PB, BIT6);
        printf("PB.6 EINT4 occurred.\n");
    }
#endif

#if (NUCODEGEN_GPIO_PA_EINT4)
    /* To check if PA.8 external interrupt occurred */
    if (GPIO_GET_INT_FLAG(PA, BIT8))
    {
        GPIO_CLR_INT_FLAG(PA, BIT8);
        printf("PA.8 EINT4 occurred.\n");
    }
#endif

#if (NUCODEGEN_GPIO_PF_EINT4)
    /* To check if PF.15 external interrupt occurred */
    if (GPIO_GET_INT_FLAG(PF, BIT15))
    {
        GPIO_CLR_INT_FLAG(PF, BIT15);
        printf("PF.15 EINT4 occurred.\n");
    }
#endif
}
#endif

#if (NUCODEGEN_GPIO_PA_EINT1 || NUCODEGEN_GPIO_PB_EINT1 || NUCODEGEN_GPIO_PD_EINT1)||(NUCODEGEN_GPIO_PC_EINT3 || NUCODEGEN_GPIO_PB_EINT3)||(NUCODEGEN_GPIO_PD_EINT5 || NUCODEGEN_GPIO_PB_EINT5 || NUCODEGEN_GPIO_PF_EINT5)
void EINT135_IRQHandler(void)
{
#if NUCODEGEN_GPIO_PA_EINT1
    /* To check if PA.7 external interrupt occurred */
    if (GPIO_GET_INT_FLAG(PA, BIT7))
    {
        GPIO_CLR_INT_FLAG(PA, BIT7);
        printf("PA.7 EINT1 occurred.\n");
    }
#endif

#if NUCODEGEN_GPIO_PB_EINT1
    /* To check if PB.4 external interrupt occurred */
    if (GPIO_GET_INT_FLAG(PB, BIT4))
    {
        GPIO_CLR_INT_FLAG(PB, BIT4);
        printf("PB.4 EINT1 occurred.\n");
    }
#endif

#if NUCODEGEN_GPIO_PD_EINT1
    /* To check if PD.15 external interrupt occurred */
    if (GPIO_GET_INT_FLAG(PD, BIT15))
    {
        GPIO_CLR_INT_FLAG(PD, BIT15);
        printf("PD.15 EINT1 occurred.\n");
    }
#endif

#if NUCODEGEN_GPIO_PB_EINT3
    /* To check if PB.2 external interrupt occurred */
    if (GPIO_GET_INT_FLAG(PB, BIT2))
    {
        GPIO_CLR_INT_FLAG(PB, BIT2);
        printf("PB.2 EINT3 occurred.\n");
    }
#endif

#if NUCODEGEN_GPIO_PC_EINT3
    /* To check if PC.7 external interrupt occurred */
    if (GPIO_GET_INT_FLAG(PC, BIT7))
    {
        GPIO_CLR_INT_FLAG(PC, BIT7);
        printf("PC.7 EINT3 occurred.\n");
    }
#endif

#if NUCODEGEN_GPIO_PB_EINT5
    /* To check if PB.7 external interrupt occurred */
    if (GPIO_GET_INT_FLAG(PB, BIT7))
    {
        GPIO_CLR_INT_FLAG(PB, BIT7);
        printf("PB.7 EINT5 occurred.\n");
    }
#endif

#if NUCODEGEN_GPIO_PD_EINT5
    /* To check if PD.12 external interrupt occurred */
    if (GPIO_GET_INT_FLAG(PD, BIT12))
    {
        GPIO_CLR_INT_FLAG(PD, BIT12);
        printf("PD.12 EINT5 occurred.\n");
    }
#endif

#if NUCODEGEN_GPIO_PF_EINT5
    /* To check if PF.14 external interrupt occurred */
    if (GPIO_GET_INT_FLAG(PF, BIT14))
    {
        GPIO_CLR_INT_FLAG(PF, BIT14);
        printf("PF.14 EINT5 occurred.\n");
    }
#endif
}
#endif
#endif //NUCODEGEN_GPIO
