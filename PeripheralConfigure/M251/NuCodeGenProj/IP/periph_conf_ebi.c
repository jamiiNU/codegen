
#if (NUCODEGEN_EBI)
/*************************************/
/**              EBI                **/
/*************************************/
void EBI_Init(){
#if (NUCODEGEN_EBI_BANK0)   
    /* Initialize EBI bank0 */
    EBI_Open(EBI_BANK0, NUCODEGEN_EBI_BANK0_DATAWIDTH, NUCODEGEN_EBI_BANK0_TIMING, NUCODEGEN_EBI_BANK0_BUS_MODE, NUCODEGEN_EBI_BANK0_CS_ACTIVE_LEVEL);
#if (NUCODEGEN_EBI_BANK0_ADVANCE)
    /* Setting EBI data access time */
    EBI->TCTL0 = (EBI->TCTL0 & ~EBI_TCTL_TACC_Msk)|(NUCODEGEN_EBI_BANK0_TACC<<EBI_TCTL_TACC_Pos);
    
    /* Setting EBI access hold time when write */
    EBI->TCTL0 = (EBI->TCTL0 & ~EBI_TCTL_WAHDOFF_Msk)|(NUCODEGEN_EBI_BANK0_WAHD_EN<<EBI_TCTL_WAHDOFF_Pos);
    
    /* Setting EBI access hold time when read */
    EBI->TCTL0 = (EBI->TCTL0 & ~EBI_TCTL_RAHDOFF_Msk)|(NUCODEGEN_EBI_BANK0_RAHD_EN<<EBI_TCTL_RAHDOFF_Pos);
    
    /* Setting EBI access time */
    EBI->TCTL0 = (EBI->TCTL0 & ~EBI_TCTL_TAHD_Msk)|(NUCODEGEN_EBI_BANK0_TAHD<<EBI_TCTL_TAHD_Pos);
#endif  
#endif  //NUCODEGEN_EBI_BANK0

#if (NUCODEGEN_EBI_BANK1)   
    /* Initialize EBI bank1 */
    EBI_Open(EBI_BANK1, NUCODEGEN_EBI_BANK1_DATAWIDTH, NUCODEGEN_EBI_BANK1_TIMING, NUCODEGEN_EBI_BANK1_BUS_MODE, NUCODEGEN_EBI_BANK1_CS_ACTIVE_LEVEL);
#if (NUCODEGEN_EBI_BANK1_ADVANCE)
    /* Setting EBI data access time */
    EBI->TCTL1 = (EBI->TCTL1 & ~EBI_TCTL_TACC_Msk)|(NUCODEGEN_EBI_BANK1_TACC<<EBI_TCTL_TACC_Pos);
    
    /* Setting EBI access hold time when write */
    EBI->TCTL1 = (EBI->TCTL1 & ~EBI_TCTL_WAHDOFF_Msk)|(NUCODEGEN_EBI_BANK1_WAHD_EN<<EBI_TCTL_WAHDOFF_Pos);
    
    /* Setting EBI access hold time when read */
    EBI->TCTL1 = (EBI->TCTL1 & ~EBI_TCTL_RAHDOFF_Msk)|(NUCODEGEN_EBI_BANK1_RAHD_EN<<EBI_TCTL_RAHDOFF_Pos);
    
    /* Setting EBI access time */
    EBI->TCTL1 = (EBI->TCTL1 & ~EBI_TCTL_TAHD_Msk)|(NUCODEGEN_EBI_BANK1_TAHD<<EBI_TCTL_TAHD_Pos);
#endif  
#endif  //NUCODEGEN_EBI_BANK1

#if (NUCODEGEN_EBI_BANK2)   
    /* Initialize EBI bank2 */
    EBI_Open(EBI_BANK2, NUCODEGEN_EBI_BANK2_DATAWIDTH, NUCODEGEN_EBI_BANK2_TIMING, NUCODEGEN_EBI_BANK2_BUS_MODE, NUCODEGEN_EBI_BANK2_CS_ACTIVE_LEVEL);
#if (NUCODEGEN_EBI_BANK2_ADVANCE)
    /* Setting EBI data access time */
    EBI->TCTL2 = (EBI->TCTL2 & ~EBI_TCTL_TACC_Msk)|(NUCODEGEN_EBI_BANK2_TACC<<EBI_TCTL_TACC_Pos);
    
    /* Setting EBI access hold time when write */
    EBI->TCTL2 = (EBI->TCTL2 & ~EBI_TCTL_WAHDOFF_Msk)|(NUCODEGEN_EBI_BANK2_WAHD_EN<<EBI_TCTL_WAHDOFF_Pos);
    
    /* Setting EBI access hold time when read */
    EBI->TCTL2 = (EBI->TCTL2 & ~EBI_TCTL_RAHDOFF_Msk)|(NUCODEGEN_EBI_BANK2_RAHD_EN<<EBI_TCTL_RAHDOFF_Pos);
    
    /* Setting EBI access time */
    EBI->TCTL2 = (EBI->TCTL2 & ~EBI_TCTL_TAHD_Msk)|(NUCODEGEN_EBI_BANK2_TAHD<<EBI_TCTL_TAHD_Pos);
#endif  
#endif  //NUCODEGEN_EBI_BANK2
}
#endif
