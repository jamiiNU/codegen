
#if (NUCODEGEN_I2C0)
#if NUCODEGEN_I2C0_INT_EN

void I2C0_IRQHandler(void)
{
    uint32_t u32Status;

#if NUCODEGEN_I2C0_WAKEUP_EN
    /* Check I2C Wake-up interrupt flag set or not */
    if (I2C_GET_WAKEUP_FLAG(I2C0))
    {
        /* Make sure that the ACK bit is done */
        while (!(I2C0->WKSTS & I2C_WKSTS_WKAKDONE_Msk)) {};

        /* Clear I2C Wake-up interrupt flag */
        I2C_CLEAR_WAKEUP_FLAG(I2C0);

        /* Clear Wakeup done flag, I2C will release bus */
        I2C0->WKSTS = I2C_WKSTS_WKAKDONE_Msk;
        return;
    }
#endif /*NUCODEGEN_I2C0_WAKEUP_EN*/

#if NUCODEGEN_I2C0_TWO_BUFFER_EN
    if((I2C0->CTL0 & I2C_CTL0_SARCIF_Msk))
        I2C_SET_DATA(I2C0, 0);    /* Prepare first data */

    /* Wait SI flag is set */
    I2C_WAIT_READY(I2C0);

    u32Status = I2C_GET_STATUS(I2C0);

    I2C_SET_CONTROL_REG(I2C0, I2C_CTL_SI_AA | I2C_CTL0_DPCIF_Msk | I2C_CTL0_SARCIF_Msk);

    (void)u32Status; /*To remove complier warning. The code is unnecessary if u32Status is used.*/
#else
    u32Status = I2C_GET_STATUS(I2C0);

    (void)u32Status; /*To remove complier warning. The code is unnecessary if u32Status is used.*/
#endif

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
