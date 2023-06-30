#if (NUCODEGEN_CRYPTO)
#if (NUCODEGEN_AES_INT)
void CRPT_IRQHandler()
{
    if (AES_GET_INT_FLAG(CRPT))
    {
        AES_CLR_INT_FLAG(CRPT);
    }
}
#endif  /* NUCODEGEN_AES_INT */
#endif  /* NUCODEGEN_CRYPTO */