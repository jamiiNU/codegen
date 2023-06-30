

#if (NUCODEGEN_FMC)
void FMC_Init()
{
#if (NUCODEGEN_FMC_ISPEN)
    /* Enable FMC ISP function */
    FMC_Open();
#endif /* NUCODEGEN_FMC_ISPEN */

#if (NUCODEGEN_FMC_APROMEN)
    /* APROM update enable */
    FMC_ENABLE_AP_UPDATE();
#endif /* NUCODEGEN_FMC_APROMEN */

#if (NUCODEGEN_FMC_LDROMEN)
    /* LDROM update enable */
    FMC_ENABLE_LD_UPDATE();
#endif /* NUCODEGEN_FMC_LDROMEN */

#if (NUCODEGEN_FMC_SPROMEN)
    /* SPROM update enable */

#endif /* NUCODEGEN_FMC_SPROMEN */

#if (NUCODEGEN_FMC_CONFIGEN)
    /* Config update enable */
    FMC_ENABLE_CFG_UPDATE();
#endif /* NUCODEGEN_FMC_CONFIGEN */

}
#endif /* NUCODEGEN_FMC */
