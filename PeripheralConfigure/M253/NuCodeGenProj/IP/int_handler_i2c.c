
#if (NUCODEGEN_I2C0)
#if NUCODEGEN_I2C0_INT_EN

void I2C0_IRQHandler(void)
{
    uint32_t u32Status;

#if NUCODEGEN_I2C0_WAKEUP_EN
    /* Check I2C Wake-up interrupt flag set or not */
    if (I2C_GET_WAKEUP_FLAG(I2C0))
    {
        /* Clear I2C Wake-up interrupt flag */
        I2C_CLEAR_WAKEUP_FLAG(I2C0);
        return;
    }
#endif /*NUCODEGEN_I2C0_WAKEUP_EN*/

    u32Status = I2C_GET_STATUS(I2C0);

    (void)u32Status; /*To remove complier warning. The code is unnecessary if u32Status is used.*/

    if (I2C_GET_TIMEOUT_FLAG(I2C0))
    {
        /* Clear I2C0 Timeout Flag */
        I2C_ClearTimeoutFlag(I2C0);
    }
    else
    {
        /*TODO: implement user function here*/
//                if (s_pfnI2C0Handler != NULL)
//                    s_pfnI2C0Handler(u32Status);
    }
}

#endif /* NUCODEGEN_I2C0_INT */
#endif /*NUCODEGEN_I2C0*/

#if (NUCODEGEN_I2C1)
#if NUCODEGEN_I2C1_INT_EN

void I2C1_IRQHandler(void)
{
    uint32_t u32Status;

    (void)u32Status; /*To remove complier warning. The code is unnecessary if u32Status is used.*/
    
#if NUCODEGEN_I2C1_WAKEUP_EN
    /* Check I2C Wake-up interrupt flag set or not */
    if (I2C_GET_WAKEUP_FLAG(I2C1))
    {
        /* Clear I2C Wake-up interrupt flag */
        I2C_CLEAR_WAKEUP_FLAG(I2C1);
        return;
    }
#endif /*NUCODEGEN_I2C1_WAKEUP_EN*/

    u32Status = I2C_GET_STATUS(I2C1);

    if (I2C_GET_TIMEOUT_FLAG(I2C1))
    {
        /* Clear I2C1 Timeout Flag */
        I2C_ClearTimeoutFlag(I2C1);
    }
    else
    {
        /*TODO: implement user function here*/
//                if (s_pfnI2C1Handler != NULL)
//                    s_pfnI2C1Handler(u32Status);
    }
}

#endif /* NUCODEGEN_I2C1_INT */
#endif /*NUCODEGEN_I2C1*/
