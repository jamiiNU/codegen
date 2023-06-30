
#if NUCODEGEN_LLSI0
#if (NUCODEGEN_LLSI0_INT_EN)
void LLSI0_IRQHandler(void)
{
    uint32_t u32IntFlag;

    u32IntFlag = LLSI_GetIntFlag(LLSI0, NUCODEGEN_LLSI0_INT_SEL);
	if(u32IntFlag)
    {
        printf("LLSI0 INT Flag:0x%x\n", u32IntFlag);
    }
    else
    {
        printf("Unknown INT occurred!\n");
    }
}
#endif //NUCODEGEN_LLSI0_INT_EN
#endif /* NUCODEGEN_LLSI0 */

#if NUCODEGEN_LLSI1
#if (NUCODEGEN_LLSI1_INT_EN)
void LLSI1_IRQHandler(void)
{
    uint32_t u32IntFlag;

    u32IntFlag = LLSI_GetIntFlag(LLSI1, NUCODEGEN_LLSI1_INT_SEL);
	if(u32IntFlag)
    {
        printf("LLSI1 INT Flag:0x%x\n", u32IntFlag);
    }
    else
    {
        printf("Unknown INT occurred!\n");
    }
}
#endif //NUCODEGEN_LLSI1_INT_EN
#endif /* NUCODEGEN_LLSI1 */

#if NUCODEGEN_LLSI2
#if (NUCODEGEN_LLSI2_INT_EN)
void LLSI2_IRQHandler(void)
{
    uint32_t u32IntFlag;

    u32IntFlag = LLSI_GetIntFlag(LLSI2, NUCODEGEN_LLSI2_INT_SEL);
	if(u32IntFlag)
    {
        printf("LLSI2 INT Flag:0x%x\n", u32IntFlag);
    }
    else
    {
        printf("Unknown INT occurred!\n");
    }
}
#endif //NUCODEGEN_LLSI2_INT_EN
#endif /* NUCODEGEN_LLSI2 */

#if NUCODEGEN_LLSI3
#if (NUCODEGEN_LLSI3_INT_EN)
void LLSI3_IRQHandler(void)
{
    uint32_t u32IntFlag;

    u32IntFlag = LLSI_GetIntFlag(LLSI3, NUCODEGEN_LLSI3_INT_SEL);
	if(u32IntFlag)
    {
        printf("LLSI3 INT Flag:0x%x\n", u32IntFlag);
    }
    else
    {
        printf("Unknown INT occurred!\n");
    }
}
#endif //NUCODEGEN_LLSI3_INT_EN
#endif /* NUCODEGEN_LLSI3 */

#if NUCODEGEN_LLSI4
#if (NUCODEGEN_LLSI4_INT_EN)
void LLSI4_IRQHandler(void)
{
    uint32_t u32IntFlag;

    u32IntFlag = LLSI_GetIntFlag(LLSI4, NUCODEGEN_LLSI4_INT_SEL);
	if(u32IntFlag)
    {
        printf("LLSI4 INT Flag:0x%x\n", u32IntFlag);
    }
    else
    {
        printf("Unknown INT occurred!\n");
    }
}
#endif //NUCODEGEN_LLSI4_INT_EN
#endif /* NUCODEGEN_LLSI4 */

#if NUCODEGEN_LLSI5
#if (NUCODEGEN_LLSI5_INT_EN)
void LLSI5_IRQHandler(void)
{
    uint32_t u32IntFlag;

    u32IntFlag = LLSI_GetIntFlag(LLSI5, NUCODEGEN_LLSI5_INT_SEL);
	if(u32IntFlag)
    {
        printf("LLSI5 INT Flag:0x%x\n", u32IntFlag);
    }
    else
    {
        printf("Unknown INT occurred!\n");
    }
}
#endif //NUCODEGEN_LLSI5_INT_EN
#endif /* NUCODEGEN_LLSI5 */

#if NUCODEGEN_LLSI6
#if (NUCODEGEN_LLSI6_INT_EN)
void LLSI6_IRQHandler(void)
{
    uint32_t u32IntFlag;

    u32IntFlag = LLSI_GetIntFlag(LLSI6, NUCODEGEN_LLSI6_INT_SEL);
	if(u32IntFlag)
    {
        printf("LLSI6 INT Flag:0x%x\n", u32IntFlag);
    }
    else
    {
        printf("Unknown INT occurred!\n");
    }
}
#endif //NUCODEGEN_LLSI6_INT_EN
#endif /* NUCODEGEN_LLSI6 */

#if NUCODEGEN_LLSI7
#if (NUCODEGEN_LLSI7_INT_EN)
void LLSI7_IRQHandler(void)
{
    uint32_t u32IntFlag;

    u32IntFlag = LLSI_GetIntFlag(LLSI7, NUCODEGEN_LLSI7_INT_SEL);
	if(u32IntFlag)
    {
        printf("LLSI7 INT Flag:0x%x\n", u32IntFlag);
    }
    else
    {
        printf("Unknown INT occurred!\n");
    }
}
#endif //NUCODEGEN_LLSI7_INT_EN
#endif /* NUCODEGEN_LLSI7 */

#if NUCODEGEN_LLSI8
#if (NUCODEGEN_LLSI8_INT_EN)
void LLSI8_IRQHandler(void)
{
    uint32_t u32IntFlag;

    u32IntFlag = LLSI_GetIntFlag(LLSI8, NUCODEGEN_LLSI8_INT_SEL);
	if(u32IntFlag)
    {
        printf("LLSI8 INT Flag:0x%x\n", u32IntFlag);
    }
    else
    {
        printf("Unknown INT occurred!\n");
    }
}
#endif //NUCODEGEN_LLSI8_INT_EN
#endif /* NUCODEGEN_LLSI8 */

#if NUCODEGEN_LLSI9
#if (NUCODEGEN_LLSI9_INT_EN)
void LLSI9_IRQHandler(void)
{
    uint32_t u32IntFlag;

    u32IntFlag = LLSI_GetIntFlag(LLSI9, NUCODEGEN_LLSI9_INT_SEL);
	if(u32IntFlag)
    {
        printf("LLSI9 INT Flag:0x%x\n", u32IntFlag);
    }
    else
    {
        printf("Unknown INT occurred!\n");
    }
}
#endif //NUCODEGEN_LLSI9_INT_EN
#endif /* NUCODEGEN_LLSI9 */
