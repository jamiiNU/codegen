

#if NUCODEGEN_SYS
void SYS_Init(void)
{
#if (NUCODEGEN_SYS_BODEN_CONFIG)
    /* Brown-Out Detector initialization */
    SYS_EnableBOD(NUCODEGEN_SYS_BODRSTEN_CONFIG, NUCODEGEN_SYS_BODVL_CONFIG);

    /* Setup BOD de-glitch time */
    SYS->BODCTL = (SYS->BODCTL & ~SYS_BODCTL_BODDGSEL_Msk) | NUCODEGEN_SYS_BODDG_CONFIG;

#if (NUCODEGEN_SYS_BODLPM_CONFIG)
    /* Setup BOD mode as Low-Power Mode */
    SYS_SET_BOD_LPM();
#else
    /* Setup BOD mode as Normal-Power Mode */
    SYS_CLEAR_BOD_LPM();
#endif /* NUCODEGEN_SYS_BODLPM_CONFIG */

#if (NUCODEGEN_SYS_BOD_INT_ENABLE)
    /* Enable BOD NVIC interrupt */
    NVIC_EnableIRQ(BOD_IRQn);
#else
    /* Disable BOD NVIC interrupt */
    NVIC_DisableIRQ(BOD_IRQn);
#endif

#else
    /* Disable Brown-Out Detector function */
    SYS_DisableBOD();
#endif /* NUCODEGEN_SYS_BODEN_CONFIG */

#if (NUCODEGEN_SYS_LVREN_CONFIG)
    /* Low-Voltage Detector initialization */
    SYS_ENABLE_LVR();

    /* Setup LVR detector threshold voltage */
    SYS->BODCTL = (SYS->BODCTL & ~SYS_BODCTL_LVRVL_Msk) | ( NUCODEGEN_SYS_LVRVL_CONFIG << SYS_BODCTL_LVRVL_Pos);

    /* Setup LVR de-glitch time */
    SYS->BODCTL = (SYS->BODCTL & ~SYS_BODCTL_LVRDGSEL_Msk) | NUCODEGEN_SYS_LVRDG_CONFIG;
#else
    /* Dsiable Low-Voltage Detector function */
    SYS_DISABLE_LVR();
#endif /* NUCODEGEN_SYS_LVREN_CONFIG */

#if (NUCODEGEN_SYS_HIRCTRIM_EN)

    SYS->HIRCTRIMCTL = ((SYS->HIRCTRIMCTL & ~(SYS_HIRCTRIMCTL_FREQSEL_Msk | SYS_HIRCTRIMCTL_LOOPSEL_Msk | SYS_HIRCTRIMCTL_RETRYCNT_Msk |
                         SYS_HIRCTRIMCTL_REFCKSEL_Msk | SYS_HIRCTRIMCTL_BOUNDEN_Msk | SYS_HIRCTRIMCTL_BOUNDARY_Msk | SYS_HIRCTRIMCTL_CESTOPEN_Msk))
                        | (NUCODEGEN_SYS_HIRCTRIM_RETRYCNT << SYS_HIRCTRIMCTL_RETRYCNT_Pos)
                        | (NUCODEGEN_SYS_HIRCTRIM_LOOPSEL << SYS_HIRCTRIMCTL_LOOPSEL_Pos)
                        | (NUCODEGEN_SYS_HIRCTRIM_REFCLOCK << SYS_HIRCTRIMCTL_REFCKSEL_Pos)
                        | (NUCODEGEN_SYS_HIRCTRIM_BOUND_EN << SYS_HIRCTRIMCTL_BOUNDEN_Pos)
                        | (NUCODEGEN_SYS_HIRCTRIM_BOUND_RANGE << SYS_HIRCTRIMCTL_BOUNDARY_Pos)
                        | (NUCODEGEN_SYS_HIRCTRIM_ERRSTOP_EN << SYS_HIRCTRIMCTL_CESTOPEN_Pos)
                        | (0x1 << SYS_HIRCTRIMCTL_FREQSEL_Pos));

#if (NUCODEGEN_SYS_HIRCTRIM_INT_EN)
    /* Enable HIRC Trim Interrupt */
    SYS->HIRCTRIMIEN = (NUCODEGEN_SYS_HIRCTRIM_INT_SEL);
#endif  /* NUCODEGEN_SYS_HIRCTRIM_INT_EN */
#endif  /* NUCODEGEN_SYS_HIRCTRIM_EN  */

#if (NUCODEGEN_SYS_HIRCTRIM_INT_EN)
    /* NVIC Enable RC Trim Interrupt */
    NVIC_EnableIRQ(CKFAIL_IRQn);
#endif
}
#endif /* NUCODEGEN_SYS */
