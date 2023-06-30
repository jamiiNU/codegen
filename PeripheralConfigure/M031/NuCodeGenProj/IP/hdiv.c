
#if (NUCODEGEN_HDIV)
void HDIV_Init()
{
    /* Set dividend and divisor */
    HDIV->DIVIDEND = NUCODEGEN_HDIV_DIVIDEND;
    HDIV->DIVISOR = NUCODEGEN_HDIV_DIVISOR;
}
#endif

