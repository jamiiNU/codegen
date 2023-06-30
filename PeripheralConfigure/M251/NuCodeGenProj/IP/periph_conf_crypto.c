#if (NUCODEGEN_CRYPTO)
#if (NUCODEGEN_CRYPTO_AES)

static uint32_t au32MyAESKey[8] =
{
    AES_KEY0, AES_KEY1, AES_KEY2, AES_KEY3,
    AES_KEY4, AES_KEY5, AES_KEY6, AES_KEY7
};

static uint32_t au32MyAESIV[4] =
{
    AES_IV0, AES_IV1, AES_IV2, AES_IV3
};

#ifdef __ICCARM__
#pragma data_alignment=4
static uint8_t au8InputData[] =
{
#else
static __attribute__((aligned(4))) uint8_t au8InputData[] =
{
#endif
    0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88,
    0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff
};

#ifdef __ICCARM__
#pragma data_alignment=4
static uint8_t au8OutputData[16];
#else
static __attribute__((aligned(4))) uint8_t au8OutputData[16];
#endif
#endif  /* NUCODEGEN_CRYPTO_AES */

void CRYPTO_Init()
{
#if (NUCODEGEN_CRYPTO_AES)
    AES_Open(CRPT, 0, NUCODEGEN_AES_CRYPT, NUCODEGEN_AES_OP_MODE, NUCODEGEN_AES_KEYSIZE, NUCODEGEN_AES_SWAP_TYPE);
    AES_SetKey(CRPT, 0, au32MyAESKey, NUCODEGEN_AES_KEYSIZE);
    AES_SetInitVect(CRPT, 0, au32MyAESIV);
    AES_SetDMATransfer(CRPT, 0, (uint32_t)au8InputData, (uint32_t)au8OutputData, sizeof(au8InputData));

#if (NUCODEGEN_AES_KEY_PROT)
    AES_ENABLE_KEY_PROTECT(CRPT);
#endif  /* NUCODEGEN_AES_KEY_PROT */

#if (NUCODEGEN_AES_INT)
    AES_ENABLE_INT(CRPT);
    NVIC_EnableIRQ(CRPT_IRQn);
#endif  /* NUCODEGEN_AES_INT */
    AES_Start(CRPT, 0, CRYPTO_DMA_ONE_SHOT);
    while(CRPT->AES_STS & CRPT_AES_STS_BUSY_Msk);
#endif  /* NUCODEGEN_CRYPTO_AES */
}
#endif  /* NUCODEGEN_CRYPTO */
