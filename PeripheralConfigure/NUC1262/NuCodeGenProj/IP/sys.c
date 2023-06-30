
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

#else
    /* Disable Brown-Out Detector function */
    SYS_DisableBOD();
#endif /* NUCODEGEN_SYS_BODEN_CONFIG */

#if (NUCODEGEN_SYS_BODEN_CONFIG||NUCODEGEN_SYS_VDETEN_CONFIG)
#if (NUCODEGEN_SYS_BOD_INT_ENABLE||NUCODEGEN_SYS_VDET_INT_ENABLE)
    /* Enable BOD NVIC interrupt */
    NVIC_EnableIRQ(BOD_IRQn);
#endif
#endif

#if (NUCODEGEN_SYS_LVREN_CONFIG)
    /* Low-Voltage Detector initialization */
    SYS_ENABLE_LVR();

    /* Setup LVR de-glitch time */
    SYS->BODCTL = (SYS->BODCTL & ~SYS_BODCTL_LVRDGSEL_Msk) | NUCODEGEN_SYS_LVRDG_CONFIG;
#else
    /* Dsiable Low-Voltage Detector function */
    SYS_DISABLE_LVR();
#endif /* NUCODEGEN_SYS_LVREN_CONFIG */

#if (NUCODEGEN_SYS_VDETEN_CONFIG)
    /* Enable voltage detector function */
    SYS->BODCTL = (SYS->BODCTL &  ~(SYS_BODCTL_VDETIEN_Msk|SYS_BODCTL_VDETDGSEL_Msk|SYS_BODCTL_VDETPINSEL_Msk)) | 
	              (0x1 << SYS_BODCTL_VDETIEN_Pos) | NUCODEGEN_SYS_VDETDG_CONFIG | NUCODEGEN_SYS_VDETPINSEL_CONFIG | SYS_BODCTL_VDETEN_Msk;	
#else
    /* Disable voltage detector function */
    SYS->BODCTL &= ~SYS_BODCTL_VDETEN_Msk;
#endif

#if (NUCODEGEN_SYS_IRCTCTL_EN)
	/* Enable HIRC Trim Function */
    SYS->IRCTCTL = ((SYS->IRCTCTL & ~(SYS_IRCTCTL_FREQSEL_Msk | SYS_IRCTCTL_LOOPSEL_Msk | SYS_IRCTCTL_RETRYCNT_Msk |
                   SYS_IRCTCTL_REFCKSEL_Msk | SYS_IRCTCTL_BOUNDEN_Msk | SYS_IRCTCTL_BOUNDARY_Msk | SYS_IRCTCTL_CESTOPEN_Msk))
                 | (NUCODEGEN_SYS_IRCTCTL_RETRYCNT << SYS_IRCTCTL_RETRYCNT_Pos)
                 | (NUCODEGEN_SYS_IRCTCTL_LOOPSEL << SYS_IRCTCTL_LOOPSEL_Pos)
                 | (NUCODEGEN_SYS_IRCTCTL_REFCLOCK << SYS_IRCTCTL_REFCKSEL_Pos)
                 | (NUCODEGEN_SYS_IRCTCTL_BOUND_EN << SYS_IRCTCTL_BOUNDEN_Pos)
                 | (NUCODEGEN_SYS_IRCTCTL_BOUND_RANGE << SYS_IRCTCTL_BOUNDARY_Pos)
                 | (NUCODEGEN_SYS_IRCTCTL_ERRSTOP_EN << SYS_IRCTCTL_CESTOPEN_Pos)
                 | (0x1 << SYS_IRCTCTL_FREQSEL_Pos));

#if (NUCODEGEN_SYS_IRCTIEN_INT_EN)
    /* Enable HIRC Trim Interrupt */
    SYS->IRCTIEN = (NUCODEGEN_SYS_IRCTIEN_INT_SEL);
#endif  /* NUCODEGEN_SYS_IRCTIEN_INT_EN */
#endif  /* NUCODEGEN_SYS_IRCTCTL_EN  */

#if (NUCODEGEN_SYS_IRCTIEN_INT_EN)
    /* NVIC Enable HIRC Trim Interrupt */
    NVIC_EnableIRQ(CLKDIRC_IRQn);
#endif
}
#endif /* NUCODEGEN_SYS */
