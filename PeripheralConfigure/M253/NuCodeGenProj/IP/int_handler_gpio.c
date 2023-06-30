
#if NUCODEGEN_GPIO
#if NUCODEGEN_GPIO_PA_INT
void GPA_IRQHandler(void)
{
    /* To check if PA.1 interrupt occurred */
    if (GPIO_GET_INT_FLAG(PA, BIT1))
    {
        GPIO_CLR_INT_FLAG(PA, BIT1);
        printf("PA.1 INT occurred.\n");
    }
    else
    {
        /* Un-expected interrupt. Just clear all PA interrupts */
        PA->INTSRC = PA->INTSRC;
        printf("Un-expected interrupts.\n");
    }
}
#endif

#if NUCODEGEN_GPIO_PB_INT
void GPB_IRQHandler(void)
{
    /* To check if PB.2 interrupt occurred */
    if (GPIO_GET_INT_FLAG(PB, BIT2))
    {
        GPIO_CLR_INT_FLAG(PB, BIT2);
        printf("PB.2 INT occurred.\n");
    }
    else
    {
        /* Un-expected interrupt. Just clear all PB interrupts */
        PB->INTSRC = PB->INTSRC;
        printf("Un-expected interrupts.\n");
    }
}
#endif

#if NUCODEGEN_GPIO_PC_INT
void GPC_IRQHandler(void)
{
    /* To check if PC.0 interrupt occurred */
    if (GPIO_GET_INT_FLAG(PC, BIT0))
    {
        GPIO_CLR_INT_FLAG(PC, BIT0);
        printf("PC.0 INT occurred.\n");
    }
    else
    {
        /* Un-expected interrupt. Just clear all PC interrupts */
        PC->INTSRC = PC->INTSRC;
        printf("Un-expected interrupts.\n");
    }
}
#endif

#if NUCODEGEN_GPIO_PF_INT
void GPF_IRQHandler(void)
{
    /* To check if PF.0 interrupt occurred */
    if (GPIO_GET_INT_FLAG(PF, BIT0))
    {
        GPIO_CLR_INT_FLAG(PF, BIT0);
        printf("PF.0 INT occurred.\n");
    }
    else
    {
        /* Un-expected interrupt. Just clear all PF interrupts */
        PF->INTSRC = PF->INTSRC;
        printf("Un-expected interrupts.\n");
    }
}
#endif

#if (NUCODEGEN_GPIO_PA_EINT0 || NUCODEGEN_GPIO_PB_EINT0)
void EINT0_IRQHandler(void)
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
}
#endif

#if (NUCODEGEN_GPIO_PA_EINT1 || NUCODEGEN_GPIO_PB_EINT1)
void EINT1_IRQHandler(void)
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
}
#endif

#if (NUCODEGEN_GPIO_PB_EINT2)
void EINT2_IRQHandler(void)
{
#if NUCODEGEN_GPIO_PB_EINT2
    /* To check if PB.3 external interrupt occurred */
    if (GPIO_GET_INT_FLAG(PB, BIT3))
    {
        GPIO_CLR_INT_FLAG(PB, BIT3);
        printf("PB.3 EINT2 occurred.\n");
    }
#endif
}
#endif

#if (NUCODEGEN_GPIO_PB_EINT3)
void EINT3_IRQHandler(void)
{
#if NUCODEGEN_GPIO_PB_EINT3
    /* To check if PB.2 external interrupt occurred */
    if (GPIO_GET_INT_FLAG(PB, BIT2))
    {
        GPIO_CLR_INT_FLAG(PB, BIT2);
        printf("PB.2 EINT3 occurred.\n");
    }
#endif
}
#endif

#if (NUCODEGEN_GPIO_PA_EINT4 || NUCODEGEN_GPIO_PB_EINT4 || NUCODEGEN_GPIO_PF_EINT4)
void EINT4_IRQHandler(void)
{
#if NUCODEGEN_GPIO_PB_EINT4
    /* To check if PB.6 external interrupt occurred */
    if (GPIO_GET_INT_FLAG(PB, BIT6))
    {
        GPIO_CLR_INT_FLAG(PB, BIT6);
        printf("PB.6 EINT4 occurred.\n");
    }
#endif

#if NUCODEGEN_GPIO_PA_EINT4
    /* To check if PA.8 external interrupt occurred */
    if (GPIO_GET_INT_FLAG(PA, BIT8))
    {
        GPIO_CLR_INT_FLAG(PA, BIT8);
        printf("PA.8 EINT4 occurred.\n");
    }
#endif

#if NUCODEGEN_GPIO_PF_EINT4
    /* To check if PF.15 external interrupt occurred */
    if (GPIO_GET_INT_FLAG(PF, BIT15))
    {
        GPIO_CLR_INT_FLAG(PF, BIT15);
        printf("PF.15 EINT4 occurred.\n");
    }
#endif
}
#endif

#if (NUCODEGEN_GPIO_PB_EINT5)
void EINT5_IRQHandler(void)
{
#if NUCODEGEN_GPIO_PB_EINT5
    /* To check if PB.7 external interrupt occurred */
    if (GPIO_GET_INT_FLAG(PB, BIT7))
    {
        GPIO_CLR_INT_FLAG(PB, BIT7);
        printf("PB.7 EINT5 occurred.\n");
    }
#endif
}
#endif
#endif //NUCODEGEN_GPIO
