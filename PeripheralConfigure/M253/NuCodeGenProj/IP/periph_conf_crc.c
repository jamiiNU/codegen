
#if NUCODEGEN_CRC
void CRC_Init()
{
    CRC_Open(NUCODEGEN_CRC_MODE, NUCODEGEN_CRC_ATTRIBUTE, CRC_SEED, NUCODEGEN_CRC_DATALEN);
}
#endif
