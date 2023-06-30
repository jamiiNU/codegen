
#if (NUCODEGEN_PDMA)
/*************************************/
/**             PDMA                **/
/*************************************/
#if ((NUCODEGEN_PDMA_CH0_OPMODE_S==NUCODEGEN_PDMA_OP_SCATTER)||(NUCODEGEN_PDMA_CH1_OPMODE_S==NUCODEGEN_PDMA_OP_SCATTER)||(NUCODEGEN_PDMA_CH2_OPMODE_S==NUCODEGEN_PDMA_OP_SCATTER)||(NUCODEGEN_PDMA_CH3_OPMODE_S==NUCODEGEN_PDMA_OP_SCATTER)||(NUCODEGEN_PDMA_CH4_OPMODE_S==NUCODEGEN_PDMA_OP_SCATTER)||(NUCODEGEN_PDMA_CH5_OPMODE_S==NUCODEGEN_PDMA_OP_SCATTER)||(NUCODEGEN_PDMA_CH6_OPMODE_S==NUCODEGEN_PDMA_OP_SCATTER)||(NUCODEGEN_PDMA_CH7_OPMODE_S==NUCODEGEN_PDMA_OP_SCATTER))
typedef struct dma_desc_t
{
    uint32_t u32Ctl;
    uint32_t u32Src;
    uint32_t u32Dest;
    uint32_t u32Offset;
} DMA_DESC_T;   
#endif  

#if(NUCODEGEN_PDMA_CH0_OPMODE_S==NUCODEGEN_PDMA_OP_SCATTER)
#if(NUCODEGEN_PDMA_CH0_OPMODE_TB3_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_T DMA_DESC_CH0[5];
#elif(NUCODEGEN_PDMA_CH0_OPMODE_TB2_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_T DMA_DESC_CH0[4];
#elif(NUCODEGEN_PDMA_CH0_OPMODE_TB1_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_T DMA_DESC_CH0[3];
#elif(NUCODEGEN_PDMA_CH0_OPMODE_TB0_S==NUCODEGEN_PDMA_OP_SCATTER)   
    DMA_DESC_T DMA_DESC_CH0[2];
#else
    DMA_DESC_T DMA_DESC_CH0[1];
#endif  
#endif

#if(NUCODEGEN_PDMA_CH1_OPMODE_S==NUCODEGEN_PDMA_OP_SCATTER)
#if(NUCODEGEN_PDMA_CH1_OPMODE_TB3_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_T DMA_DESC_CH1[5];
#elif(NUCODEGEN_PDMA_CH1_OPMODE_TB2_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_T DMA_DESC_CH1[4];
#elif(NUCODEGEN_PDMA_CH1_OPMODE_TB1_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_T DMA_DESC_CH1[3];
#elif(NUCODEGEN_PDMA_CH1_OPMODE_TB0_S==NUCODEGEN_PDMA_OP_SCATTER)   
    DMA_DESC_T DMA_DESC_CH1[2];
#else
    DMA_DESC_T DMA_DESC_CH1[1];
#endif 
#endif

#if(NUCODEGEN_PDMA_CH2_OPMODE_S==NUCODEGEN_PDMA_OP_SCATTER)
#if(NUCODEGEN_PDMA_CH2_OPMODE_TB3_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_T DMA_DESC_CH2[5];
#elif(NUCODEGEN_PDMA_CH2_OPMODE_TB2_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_T DMA_DESC_CH2[4];
#elif(NUCODEGEN_PDMA_CH2_OPMODE_TB1_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_T DMA_DESC_CH2[3];
#elif(NUCODEGEN_PDMA_CH2_OPMODE_TB0_S==NUCODEGEN_PDMA_OP_SCATTER)   
    DMA_DESC_T DMA_DESC_CH2[2];
#else
    DMA_DESC_T DMA_DESC_CH2[1];
#endif 
#endif
 
#if(NUCODEGEN_PDMA_CH3_OPMODE_S==NUCODEGEN_PDMA_OP_SCATTER) 
#if(NUCODEGEN_PDMA_CH3_OPMODE_TB3_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_T DMA_DESC_CH3[5];
#elif(NUCODEGEN_PDMA_CH3_OPMODE_TB2_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_T DMA_DESC_CH3[4];
#elif(NUCODEGEN_PDMA_CH3_OPMODE_TB1_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_T DMA_DESC_CH3[3];
#elif(NUCODEGEN_PDMA_CH3_OPMODE_TB0_S==NUCODEGEN_PDMA_OP_SCATTER)   
    DMA_DESC_T DMA_DESC_CH3[2];
#else
    DMA_DESC_T DMA_DESC_CH3[1];
#endif 
#endif

#if(NUCODEGEN_PDMA_CH4_OPMODE_S==NUCODEGEN_PDMA_OP_SCATTER)
#if(NUCODEGEN_PDMA_CH4_OPMODE_TB3_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_T DMA_DESC_CH4[5];
#elif(NUCODEGEN_PDMA_CH4_OPMODE_TB2_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_T DMA_DESC_CH4[4];
#elif(NUCODEGEN_PDMA_CH4_OPMODE_TB1_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_T DMA_DESC_CH4[3];
#elif(NUCODEGEN_PDMA_CH4_OPMODE_TB0_S==NUCODEGEN_PDMA_OP_SCATTER)   
    DMA_DESC_T DMA_DESC_CH4[2];
#else
    DMA_DESC_T DMA_DESC_CH4[1];
#endif  
#endif

#if(NUCODEGEN_PDMA_CH5_OPMODE_S==NUCODEGEN_PDMA_OP_SCATTER)
#if(NUCODEGEN_PDMA_CH5_OPMODE_TB3_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_T DMA_DESC_CH5[5];
#elif(NUCODEGEN_PDMA_CH5_OPMODE_TB2_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_T DMA_DESC_CH5[4];
#elif(NUCODEGEN_PDMA_CH5_OPMODE_TB1_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_T DMA_DESC_CH5[3];
#elif(NUCODEGEN_PDMA_CH5_OPMODE_TB0_S==NUCODEGEN_PDMA_OP_SCATTER)   
    DMA_DESC_T DMA_DESC_CH5[2];
#else
    DMA_DESC_T DMA_DESC_CH5[1];
#endif 
#endif

#if(NUCODEGEN_PDMA_CH6_OPMODE_S==NUCODEGEN_PDMA_OP_SCATTER)
#if(NUCODEGEN_PDMA_CH6_OPMODE_TB3_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_T DMA_DESC_CH6[5];
#elif(NUCODEGEN_PDMA_CH6_OPMODE_TB2_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_T DMA_DESC_CH6[4];
#elif(NUCODEGEN_PDMA_CH6_OPMODE_TB1_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_T DMA_DESC_CH6[3];
#elif(NUCODEGEN_PDMA_CH6_OPMODE_TB0_S==NUCODEGEN_PDMA_OP_SCATTER)   
    DMA_DESC_T DMA_DESC_CH6[2];
#else
    DMA_DESC_T DMA_DESC_CH6[1];
#endif 
#endif
	
#if(NUCODEGEN_PDMA_CH7_OPMODE_S==NUCODEGEN_PDMA_OP_SCATTER)	
#if(NUCODEGEN_PDMA_CH7_OPMODE_TB3_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_T DMA_DESC_CH7[5];
#elif(NUCODEGEN_PDMA_CH7_OPMODE_TB2_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_T DMA_DESC_CH7[4];
#elif(NUCODEGEN_PDMA_CH7_OPMODE_TB1_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_T DMA_DESC_CH7[3];
#elif(NUCODEGEN_PDMA_CH7_OPMODE_TB0_S==NUCODEGEN_PDMA_OP_SCATTER)   
    DMA_DESC_T DMA_DESC_CH7[2];
#else
    DMA_DESC_T DMA_DESC_CH7[1];
#endif
#endif

#if(NUCODEGEN_PDMA_CH0_SRC_ADDR_S)
	#if(NUCODEGEN_PDMA_CH0_OPMODE_S==NUCODEGEN_PDMA_OP_BASIC)
    uint32_t* g_pu32CH0SrcArray;
    #else
    uint32_t* g_pu32CH0SrcArrayTB0;    
		#if(NUCODEGEN_PDMA_CH0_OPMODE_TB0_S==NUCODEGEN_PDMA_OP_SCATTER)
		uint32_t* g_pu32CH0SrcArrayTB1;
		#endif  
		#if(NUCODEGEN_PDMA_CH0_OPMODE_TB1_S==NUCODEGEN_PDMA_OP_SCATTER)
		uint32_t* g_pu32CH0SrcArrayTB2;
		#endif  
		#if(NUCODEGEN_PDMA_CH0_OPMODE_TB2_S==NUCODEGEN_PDMA_OP_SCATTER)
		uint32_t* g_pu32CH0SrcArrayTB3;
		#endif  
		#if(NUCODEGEN_PDMA_CH0_OPMODE_TB3_S==NUCODEGEN_PDMA_OP_SCATTER)
		uint32_t* g_pu32CH0SrcArrayTB4;
		#endif
	#endif
#endif
#if(NUCODEGEN_PDMA_CH0_DES_ADDR_S)
	#if(NUCODEGEN_PDMA_CH0_OPMODE_S==NUCODEGEN_PDMA_OP_BASIC)
    uint32_t* g_pu32CH0DesArray;
    #else
    uint32_t* g_pu32CH0DesArrayTB0;
		#if(NUCODEGEN_PDMA_CH0_OPMODE_TB0_S==NUCODEGEN_PDMA_OP_SCATTER)
		uint32_t* g_pu32CH0DesArrayTB1;
		#endif  
		#if(NUCODEGEN_PDMA_CH0_OPMODE_TB1_S==NUCODEGEN_PDMA_OP_SCATTER)
		uint32_t* g_pu32CH0DesArrayTB2;
		#endif  
		#if(NUCODEGEN_PDMA_CH0_OPMODE_TB2_S==NUCODEGEN_PDMA_OP_SCATTER)
		uint32_t* g_pu32CH0DesArrayTB3;
		#endif  
		#if(NUCODEGEN_PDMA_CH0_OPMODE_TB3_S==NUCODEGEN_PDMA_OP_SCATTER)
		uint32_t* g_pu32CH0DesArrayTB4;
		#endif 
    #endif	
#endif      

#if(NUCODEGEN_PDMA_CH1_SRC_ADDR_S)
	#if(NUCODEGEN_PDMA_CH1_OPMODE_S==NUCODEGEN_PDMA_OP_BASIC)
    uint32_t* g_pu32CH1SrcArray;
    #else
    uint32_t* g_pu32CH1SrcArrayTB0;
		#if(NUCODEGEN_PDMA_CH1_OPMODE_TB0_S==NUCODEGEN_PDMA_OP_SCATTER)
		uint32_t* g_pu32CH1SrcArrayTB1;
		#endif  
		#if(NUCODEGEN_PDMA_CH1_OPMODE_TB1_S==NUCODEGEN_PDMA_OP_SCATTER)
		uint32_t* g_pu32CH1SrcArrayTB2;
		#endif  
		#if(NUCODEGEN_PDMA_CH1_OPMODE_TB2_S==NUCODEGEN_PDMA_OP_SCATTER)
		uint32_t* g_pu32CH1SrcArrayTB3;
		#endif  
		#if(NUCODEGEN_PDMA_CH1_OPMODE_TB3_S==NUCODEGEN_PDMA_OP_SCATTER)
		uint32_t* g_pu32CH1SrcArrayTB4;
		#endif     
    #endif	
#endif
#if(NUCODEGEN_PDMA_CH1_DES_ADDR_S)
	#if(NUCODEGEN_PDMA_CH1_OPMODE_S==NUCODEGEN_PDMA_OP_BASIC)
    uint32_t* g_pu32CH1DesArray;
    #else
    uint32_t* g_pu32CH1DesArrayTB0;
		#if(NUCODEGEN_PDMA_CH1_OPMODE_TB0_S==NUCODEGEN_PDMA_OP_SCATTER)
		uint32_t* g_pu32CH1DesArrayTB1;
		#endif  
		#if(NUCODEGEN_PDMA_CH1_OPMODE_TB1_S==NUCODEGEN_PDMA_OP_SCATTER)
		uint32_t* g_pu32CH1DesArrayTB2;
		#endif  
		#if(NUCODEGEN_PDMA_CH1_OPMODE_TB2_S==NUCODEGEN_PDMA_OP_SCATTER)
		uint32_t* g_pu32CH1DesArrayTB3;
		#endif  
		#if(NUCODEGEN_PDMA_CH1_OPMODE_TB3_S==NUCODEGEN_PDMA_OP_SCATTER)
		uint32_t* g_pu32CH1DesArrayTB4;
		#endif  
    #endif	
#endif     

#if(NUCODEGEN_PDMA_CH2_SRC_ADDR_S)
	#if(NUCODEGEN_PDMA_CH2_OPMODE_S==NUCODEGEN_PDMA_OP_BASIC)
    uint32_t* g_pu32CH2SrcArray;
    #else
    uint32_t* g_pu32CH2SrcArrayTB0;
		#if(NUCODEGEN_PDMA_CH2_OPMODE_TB0_S==NUCODEGEN_PDMA_OP_SCATTER)
		uint32_t* g_pu32CH2SrcArrayTB1;
		#endif  
		#if(NUCODEGEN_PDMA_CH2_OPMODE_TB1_S==NUCODEGEN_PDMA_OP_SCATTER)
		uint32_t* g_pu32CH2SrcArrayTB2;
		#endif  
		#if(NUCODEGEN_PDMA_CH2_OPMODE_TB2_S==NUCODEGEN_PDMA_OP_SCATTER)
		uint32_t* g_pu32CH2SrcArrayTB3;
		#endif  
		#if(NUCODEGEN_PDMA_CH2_OPMODE_TB3_S==NUCODEGEN_PDMA_OP_SCATTER)
		uint32_t* g_pu32CH2SrcArrayTB4;
		#endif 
    #endif	
#endif
#if(NUCODEGEN_PDMA_CH2_DES_ADDR_S)
	#if(NUCODEGEN_PDMA_CH2_OPMODE_S==NUCODEGEN_PDMA_OP_BASIC)
    uint32_t* g_pu32CH2DesArray;
    #else
    uint32_t* g_pu32CH2DesArrayTB0;
		#if(NUCODEGEN_PDMA_CH2_OPMODE_TB0_S==NUCODEGEN_PDMA_OP_SCATTER)
		uint32_t* g_pu32CH2DesArrayTB1;
		#endif  
		#if(NUCODEGEN_PDMA_CH2_OPMODE_TB1_S==NUCODEGEN_PDMA_OP_SCATTER)
		uint32_t* g_pu32CH2DesArrayTB2;
		#endif  
		#if(NUCODEGEN_PDMA_CH2_OPMODE_TB2_S==NUCODEGEN_PDMA_OP_SCATTER)
		uint32_t* g_pu32CH2DesArrayTB3;
		#endif  
		#if(NUCODEGEN_PDMA_CH2_OPMODE_TB3_S==NUCODEGEN_PDMA_OP_SCATTER)
		uint32_t* g_pu32CH2DesArrayTB4;
		#endif  
	#endif	
#endif      

#if(NUCODEGEN_PDMA_CH3_SRC_ADDR_S)
	#if(NUCODEGEN_PDMA_CH3_OPMODE_S==NUCODEGEN_PDMA_OP_BASIC)
    uint32_t* g_pu32CH3SrcArray;
    #else
    uint32_t* g_pu32CH3SrcArrayTB0;
		#if(NUCODEGEN_PDMA_CH3_OPMODE_TB0_S==NUCODEGEN_PDMA_OP_SCATTER)
		uint32_t* g_pu32CH3SrcArrayTB1;
		#endif  
		#if(NUCODEGEN_PDMA_CH3_OPMODE_TB1_S==NUCODEGEN_PDMA_OP_SCATTER)
		uint32_t* g_pu32CH3SrcArrayTB2;
		#endif  
		#if(NUCODEGEN_PDMA_CH3_OPMODE_TB2_S==NUCODEGEN_PDMA_OP_SCATTER)
		uint32_t* g_pu32CH3SrcArrayTB3;
		#endif  
		#if(NUCODEGEN_PDMA_CH3_OPMODE_TB3_S==NUCODEGEN_PDMA_OP_SCATTER)
		uint32_t* g_pu32CH3SrcArrayTB4;
		#endif 
    #endif	
#endif
#if(NUCODEGEN_PDMA_CH3_DES_ADDR_S)
	#if(NUCODEGEN_PDMA_CH3_OPMODE_S==NUCODEGEN_PDMA_OP_BASIC)
    uint32_t* g_pu32CH3DesArray;
    #else
    uint32_t* g_pu32CH3DesArrayTB0;
		#if(NUCODEGEN_PDMA_CH3_OPMODE_TB0_S==NUCODEGEN_PDMA_OP_SCATTER)
		uint32_t* g_pu32CH3DesArrayTB1;
		#endif  
		#if(NUCODEGEN_PDMA_CH3_OPMODE_TB1_S==NUCODEGEN_PDMA_OP_SCATTER)
		uint32_t* g_pu32CH3DesArrayTB2;
		#endif  
		#if(NUCODEGEN_PDMA_CH3_OPMODE_TB2_S==NUCODEGEN_PDMA_OP_SCATTER)
		uint32_t* g_pu32CH3DesArrayTB3;
		#endif  
		#if(NUCODEGEN_PDMA_CH3_OPMODE_TB3_S==NUCODEGEN_PDMA_OP_SCATTER)
		uint32_t* g_pu32CH3DesArrayTB4;
		#endif 
    #endif	
#endif  

#if(NUCODEGEN_PDMA_CH4_SRC_ADDR_S)
	#if(NUCODEGEN_PDMA_CH4_OPMODE_S==NUCODEGEN_PDMA_OP_BASIC)
    uint32_t* g_pu32CH4SrcArray;
    #else
    uint32_t* g_pu32CH4SrcArrayTB0;
		#if(NUCODEGEN_PDMA_CH4_OPMODE_TB0_S==NUCODEGEN_PDMA_OP_SCATTER)
		uint32_t* g_pu32CH4SrcArrayTB1;
		#endif  
		#if(NUCODEGEN_PDMA_CH4_OPMODE_TB1_S==NUCODEGEN_PDMA_OP_SCATTER)
		uint32_t* g_pu32CH4SrcArrayTB2;
		#endif  
		#if(NUCODEGEN_PDMA_CH4_OPMODE_TB2_S==NUCODEGEN_PDMA_OP_SCATTER)
		uint32_t* g_pu32CH4SrcArrayTB3;
		#endif  
		#if(NUCODEGEN_PDMA_CH4_OPMODE_TB3_S==NUCODEGEN_PDMA_OP_SCATTER)
		uint32_t* g_pu32CH4SrcArrayTB4;
		#endif  
    #endif	
#endif
#if(NUCODEGEN_PDMA_CH4_DES_ADDR_S)
	#if(NUCODEGEN_PDMA_CH4_OPMODE_S==NUCODEGEN_PDMA_OP_BASIC)
    uint32_t* g_pu32CH4DesArray;
    #else
    uint32_t* g_pu32CH4DesArrayTB0;
		#if(NUCODEGEN_PDMA_CH4_OPMODE_TB0_S==NUCODEGEN_PDMA_OP_SCATTER)
		uint32_t* g_pu32CH4DesArrayTB1;
		#endif  
		#if(NUCODEGEN_PDMA_CH4_OPMODE_TB1_S==NUCODEGEN_PDMA_OP_SCATTER)
		uint32_t* g_pu32CH4DesArrayTB2;
		#endif  
		#if(NUCODEGEN_PDMA_CH4_OPMODE_TB2_S==NUCODEGEN_PDMA_OP_SCATTER)
		uint32_t* g_pu32CH4DesArrayTB3;
		#endif  
		#if(NUCODEGEN_PDMA_CH4_OPMODE_TB3_S==NUCODEGEN_PDMA_OP_SCATTER)
		uint32_t* g_pu32CH4DesArrayTB4;
		#endif 
    #endif	
#endif      

#if(NUCODEGEN_PDMA_CH5_SRC_ADDR_S)
	#if(NUCODEGEN_PDMA_CH5_OPMODE_S==NUCODEGEN_PDMA_OP_BASIC)
    uint32_t* g_pu32CH5SrcArray;
    #else
    uint32_t* g_pu32CH5SrcArrayTB0;
		#if(NUCODEGEN_PDMA_CH5_OPMODE_TB0_S==NUCODEGEN_PDMA_OP_SCATTER)
		uint32_t* g_pu32CH5SrcArrayTB1;
		#endif  
		#if(NUCODEGEN_PDMA_CH5_OPMODE_TB1_S==NUCODEGEN_PDMA_OP_SCATTER)
		uint32_t* g_pu32CH5SrcArrayTB2;
		#endif  
		#if(NUCODEGEN_PDMA_CH5_OPMODE_TB2_S==NUCODEGEN_PDMA_OP_SCATTER)
		uint32_t* g_pu32CH5SrcArrayTB3;
		#endif  
		#if(NUCODEGEN_PDMA_CH5_OPMODE_TB3_S==NUCODEGEN_PDMA_OP_SCATTER)
		uint32_t* g_pu32CH5SrcArrayTB4;
		#endif  
    #endif	
#endif
#if(NUCODEGEN_PDMA_CH5_DES_ADDR_S)
	#if(NUCODEGEN_PDMA_CH5_OPMODE_S==NUCODEGEN_PDMA_OP_BASIC)
    uint32_t* g_pu32CH5DesArray;
    #else
    uint32_t* g_pu32CH5DesArrayTB0;
		#if(NUCODEGEN_PDMA_CH5_OPMODE_TB0_S==NUCODEGEN_PDMA_OP_SCATTER)
		uint32_t* g_pu32CH5DesArrayTB1;
		#endif  
		#if(NUCODEGEN_PDMA_CH5_OPMODE_TB1_S==NUCODEGEN_PDMA_OP_SCATTER)
		uint32_t* g_pu32CH5DesArrayTB2;
		#endif  
		#if(NUCODEGEN_PDMA_CH5_OPMODE_TB2_S==NUCODEGEN_PDMA_OP_SCATTER)
		uint32_t* g_pu32CH5DesArrayTB3;
		#endif  
		#if(NUCODEGEN_PDMA_CH5_OPMODE_TB3_S==NUCODEGEN_PDMA_OP_SCATTER)
		uint32_t* g_pu32CH5DesArrayTB4;
		#endif 
    #endif	
#endif     

#if(NUCODEGEN_PDMA_CH6_SRC_ADDR_S)
	#if(NUCODEGEN_PDMA_CH6_OPMODE_S==NUCODEGEN_PDMA_OP_BASIC)
    uint32_t* g_pu32CH6SrcArray;
    #else
    uint32_t* g_pu32CH6SrcArrayTB0;
		#if(NUCODEGEN_PDMA_CH6_OPMODE_TB0_S==NUCODEGEN_PDMA_OP_SCATTER)
		uint32_t* g_pu32CH6SrcArrayTB1;
		#endif  
		#if(NUCODEGEN_PDMA_CH6_OPMODE_TB1_S==NUCODEGEN_PDMA_OP_SCATTER)
		uint32_t* g_pu32CH6SrcArrayTB2;
		#endif  
		#if(NUCODEGEN_PDMA_CH6_OPMODE_TB2_S==NUCODEGEN_PDMA_OP_SCATTER)
		uint32_t* g_pu32CH6SrcArrayTB3;
		#endif  
		#if(NUCODEGEN_PDMA_CH6_OPMODE_TB3_S==NUCODEGEN_PDMA_OP_SCATTER)
		uint32_t* g_pu32CH6SrcArrayTB4;
		#endif    
    #endif	
#endif
#if(NUCODEGEN_PDMA_CH6_DES_ADDR_S)
	#if(NUCODEGEN_PDMA_CH6_OPMODE_S==NUCODEGEN_PDMA_OP_BASIC)
    uint32_t* g_pu32CH6DesArray;
    #else
    uint32_t* g_pu32CH6DesArrayTB0;
		#if(NUCODEGEN_PDMA_CH6_OPMODE_TB0_S==NUCODEGEN_PDMA_OP_SCATTER)
		uint32_t* g_pu32CH6DesArrayTB1;
		#endif  
		#if(NUCODEGEN_PDMA_CH6_OPMODE_TB1_S==NUCODEGEN_PDMA_OP_SCATTER)
		uint32_t* g_pu32CH6DesArrayTB2;
		#endif  
		#if(NUCODEGEN_PDMA_CH6_OPMODE_TB2_S==NUCODEGEN_PDMA_OP_SCATTER)
		uint32_t* g_pu32CH6DesArrayTB3;
		#endif  
		#if(NUCODEGEN_PDMA_CH6_OPMODE_TB3_S==NUCODEGEN_PDMA_OP_SCATTER)
		uint32_t* g_pu32CH6DesArrayTB4;
		#endif 
	#endif
#endif      

#if(NUCODEGEN_PDMA_CH7_SRC_ADDR_S)
	#if(NUCODEGEN_PDMA_CH7_OPMODE_S==NUCODEGEN_PDMA_OP_BASIC)
    uint32_t* g_pu32CH7SrcArray;
    #else
    uint32_t* g_pu32CH7SrcArrayTB0;
		#if(NUCODEGEN_PDMA_CH7_OPMODE_TB0_S==NUCODEGEN_PDMA_OP_SCATTER)
		uint32_t* g_pu32CH7SrcArrayTB1;
		#endif  
		#if(NUCODEGEN_PDMA_CH7_OPMODE_TB1_S==NUCODEGEN_PDMA_OP_SCATTER)
		uint32_t* g_pu32CH7SrcArrayTB2;
		#endif  
		#if(NUCODEGEN_PDMA_CH7_OPMODE_TB2_S==NUCODEGEN_PDMA_OP_SCATTER)
		uint32_t* g_pu32CH7SrcArrayTB3;
		#endif  
		#if(NUCODEGEN_PDMA_CH7_OPMODE_TB3_S==NUCODEGEN_PDMA_OP_SCATTER)
		uint32_t* g_pu32CH7SrcArrayTB4;
		#endif  
    #endif	
#endif
#if(NUCODEGEN_PDMA_CH7_DES_ADDR_S)
	#if(NUCODEGEN_PDMA_CH7_OPMODE_S==NUCODEGEN_PDMA_OP_BASIC)
    uint32_t* g_pu32CH7DesArray;
    #else
    uint32_t* g_pu32CH7DesArrayTB0;
		#if(NUCODEGEN_PDMA_CH7_OPMODE_TB0_S==NUCODEGEN_PDMA_OP_SCATTER)
		uint32_t* g_pu32CH7DesArrayTB1;
		#endif  
		#if(NUCODEGEN_PDMA_CH7_OPMODE_TB1_S==NUCODEGEN_PDMA_OP_SCATTER)
		uint32_t* g_pu32CH7DesArrayTB2;
		#endif  
		#if(NUCODEGEN_PDMA_CH7_OPMODE_TB2_S==NUCODEGEN_PDMA_OP_SCATTER)
		uint32_t* g_pu32CH7DesArrayTB3;
		#endif  
		#if(NUCODEGEN_PDMA_CH7_OPMODE_TB3_S==NUCODEGEN_PDMA_OP_SCATTER)
		uint32_t* g_pu32CH7DesArrayTB4;
		#endif  
    #endif	
#endif  

void PDMA_Init()
{
#if (NUCODEGEN_PDMA_CH0)
#if (NUCODEGEN_PDMA_CH0_OPMODE_S == NUCODEGEN_PDMA_OP_BASIC)
    /* Open CH0 */
    PDMA_Open(PDMA, 1 << 0);
    
    /* Transfer count is PDMA_CH0_DATA_LENGTH, transfer width is NUCODEGEN_PDMA_CH0_WIDTH */
    PDMA_SetTransferCnt(PDMA, 0, NUCODEGEN_PDMA_CH0_WIDTH, PDMA_CH0_DATA_LENGTH);
    
    /* Set source address is NUCODEGEN_PDMA_CH0_SRC_ADDR, destination address is NUCODEGEN_PDMA_CH0_DES_ADDR */
    PDMA_SetTransferAddr(PDMA, 0, (uint32_t)NUCODEGEN_PDMA_CH0_SRC_ADDR, NUCODEGEN_PDMA_CH0_SRC_TYPE, (uint32_t)NUCODEGEN_PDMA_CH0_DES_ADDR, NUCODEGEN_PDMA_CH0_DES_TYPE);
    
    /* Set transfer mode and burst size */
    PDMA_SetBurstType(PDMA, 0, NUCODEGEN_PDMA_CH0_MODE, NUCODEGEN_PDMA_CH0_BURST_SIZE);
    
    #if(NUCODEGEN_PDMA_CH0_TMOUT)
    /* Enable timeout function and set timeout counter */
    PDMA_SetTimeOut(PDMA, 0, NUCODEGEN_PDMA_CH0_TMOUT, NUCODEGEN_PDMA_CH0_TMOUT_CNT);  
    #endif
    
    #if(NUCODEGEN_PDMA_CH0_STRIDE_EN)
    /* Set stride function */
    PDMA_SetStride(PDMA, 0, NUCODEGEN_PDMA_CH0_STRIDE_DES_LENGTH, NUCODEGEN_PDMA_CH0_STRIDE_SRC_LENGTH, NUCODEGEN_PDMA_CH0_STRIDE_CNT);
    #endif
    
    /* Request source is NUCODEGEN_PDMA_CH0_SRC_DES_SEL */
    PDMA_SetTransferMode(PDMA, 0, NUCODEGEN_PDMA_CH0_SRC_DES_SEL, 0, 0);
#else   //NUCODEGEN_PDMA_CH0_OPMODE_S == PDMA_OP_SCATTER
    /* Open CH0 */
    PDMA_Open(PDMA, 1 << 0);    
    
    DMA_DESC_CH0[0].u32Ctl =
        (((uint32_t)PDMA_CH0_DATA_LENGTH_TB0 - 1) << PDMA_DSCT_CTL_TXCNT_Pos) | /* Set transfer count */ \
        NUCODEGEN_PDMA_CH0_WIDTH_TB0 |   /*   Set transfer width */ \
        NUCODEGEN_PDMA_CH0_SRC_TYPE_TB0 |    /* Set source increment type */ \
        NUCODEGEN_PDMA_CH0_DES_TYPE_TB0 |    /* Set destination increment type */ \
        NUCODEGEN_PDMA_CH0_MODE_TB0 |  /* Set transfer type */ \
        NUCODEGEN_PDMA_CH0_BURST_SIZE_TB0 |  /* Set burst size */ \
        NUCODEGEN_PDMA_CH0_TB0_INT_EN |   /* Set table empty interrupt */ \
        NUCODEGEN_PDMA_CH0_OPMODE_TB0;  /* Set operation mode */
        
    /* Configure source address */  
    DMA_DESC_CH0[0].u32Src = (uint32_t)NUCODEGEN_PDMA_CH0_SRC_ADDR_TB0;
    
    /* Configure destination address */
    DMA_DESC_CH0[0].u32Dest = (uint32_t)NUCODEGEN_PDMA_CH0_DES_ADDR_TB0;
    
	#if(NUCODEGEN_PDMA_CH0_OPMODE_TB0_S==NUCODEGEN_PDMA_OP_BASIC)
    /* Configure next descriptor table address */
    DMA_DESC_CH0[0].u32Offset = 0; /* No next operation table. No effect in basic mode */ 		
	#else
    /* Configure next descriptor table address */
    DMA_DESC_CH0[0].u32Offset = (uint32_t)&DMA_DESC_CH0[1] - (PDMA->SCATBA); /* next descriptor table is table 1 */ 
    #endif
    #if(NUCODEGEN_PDMA_CH0_OPMODE_TB0_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_CH0[1].u32Ctl =
        (((uint32_t)PDMA_CH0_DATA_LENGTH_TB1 - 1) << PDMA_DSCT_CTL_TXCNT_Pos) | /* Set transfer count */ \
        NUCODEGEN_PDMA_CH0_WIDTH_TB1 |   /* Set transfer width */ \
        NUCODEGEN_PDMA_CH0_SRC_TYPE_TB1 |    /* Set source increment type */ \
        NUCODEGEN_PDMA_CH0_DES_TYPE_TB1 |    /* Set destination increment type */ \
        NUCODEGEN_PDMA_CH0_MODE_TB1 |  /* Set transfer type */ \
        NUCODEGEN_PDMA_CH0_BURST_SIZE_TB1 |  /* Set burst size */ \
        NUCODEGEN_PDMA_CH0_TB1_INT_EN |   /* Set table empty interrupt */ \
        NUCODEGEN_PDMA_CH0_OPMODE_TB1;  /* Set operation mode */
        
    /* Configure source address */  
    DMA_DESC_CH0[1].u32Src = (uint32_t)NUCODEGEN_PDMA_CH0_SRC_ADDR_TB1;
    
    /* Configure destination address */
    DMA_DESC_CH0[1].u32Dest = (uint32_t)NUCODEGEN_PDMA_CH0_DES_ADDR_TB1;
    
	#if(NUCODEGEN_PDMA_CH0_OPMODE_TB1_S==NUCODEGEN_PDMA_OP_BASIC)
    /* Configure next descriptor table address */
    DMA_DESC_CH0[1].u32Offset = 0; /* No next operation table. No effect in basic mode */ 		
	#else
    /* Configure next descriptor table address */
    DMA_DESC_CH0[1].u32Offset = (uint32_t)&DMA_DESC_CH0[2] - (PDMA->SCATBA); /* next descriptor table is table 2 */     
	#endif
    #endif  
    #if(NUCODEGEN_PDMA_CH0_OPMODE_TB1_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_CH0[2].u32Ctl =
        (((uint32_t)PDMA_CH0_DATA_LENGTH_TB2 - 1) << PDMA_DSCT_CTL_TXCNT_Pos) | /* Set transfer count */ \
        NUCODEGEN_PDMA_CH0_WIDTH_TB2 |   /* Set transfer width */ \
        NUCODEGEN_PDMA_CH0_SRC_TYPE_TB2 |    /* Set source increment type */ \
        NUCODEGEN_PDMA_CH0_DES_TYPE_TB2 |    /* Set destination increment type */ \
        NUCODEGEN_PDMA_CH0_MODE_TB2 |  /* Set transfer type */ \
        NUCODEGEN_PDMA_CH0_BURST_SIZE_TB2 |  /* Set burst size */ \
        NUCODEGEN_PDMA_CH0_TB2_INT_EN |   /* Set table empty interrupt */ \
        NUCODEGEN_PDMA_CH0_OPMODE_TB2;  /* Set operation mode */
        
    /* Configure source address */  
    DMA_DESC_CH0[2].u32Src = (uint32_t)NUCODEGEN_PDMA_CH0_SRC_ADDR_TB2;
    
    /* Configure destination address */
    DMA_DESC_CH0[2].u32Dest = (uint32_t)NUCODEGEN_PDMA_CH0_DES_ADDR_TB2;
	#if(NUCODEGEN_PDMA_CH0_OPMODE_TB2_S==NUCODEGEN_PDMA_OP_BASIC)    
    /* Configure next descriptor table address */
    DMA_DESC_CH0[2].u32Offset = 0; /* No next operation table. No effect in basic mode */ 		
    #else		
    /* Configure next descriptor table address */
    DMA_DESC_CH0[2].u32Offset = (uint32_t)&DMA_DESC_CH0[3] - (PDMA->SCATBA); /* next descriptor table is table 3 */     
	#endif
    #endif
    #if(NUCODEGEN_PDMA_CH0_OPMODE_TB2_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_CH0[3].u32Ctl =
        (((uint32_t)PDMA_CH0_DATA_LENGTH_TB3 - 1) << PDMA_DSCT_CTL_TXCNT_Pos) | /* Set transfer count */ \
        NUCODEGEN_PDMA_CH0_WIDTH_TB3 |   /* Set transfer width */ \
        NUCODEGEN_PDMA_CH0_SRC_TYPE_TB3 |    /* Set source increment type */ \
        NUCODEGEN_PDMA_CH0_DES_TYPE_TB3 |    /* Set destination increment type */ \
        NUCODEGEN_PDMA_CH0_MODE_TB3 |  /* Set transfer type */ \
        NUCODEGEN_PDMA_CH0_BURST_SIZE_TB3 |  /* Set burst size */ \
        NUCODEGEN_PDMA_CH0_TB3_INT_EN |   /* Set table empty interrupt */ \
        NUCODEGEN_PDMA_CH0_OPMODE_TB3;  /* Set operation mode */
        
    /* Configure source address */  
    DMA_DESC_CH0[3].u32Src = (uint32_t)NUCODEGEN_PDMA_CH0_SRC_ADDR_TB3;
    
    /* Configure destination address */
    DMA_DESC_CH0[3].u32Dest = (uint32_t)NUCODEGEN_PDMA_CH0_DES_ADDR_TB3;
    
	#if(NUCODEGEN_PDMA_CH0_OPMODE_TB3_S==NUCODEGEN_PDMA_OP_BASIC)
    /* Configure next descriptor table address */
    DMA_DESC_CH0[3].u32Offset = 0; /* No next operation table. No effect in basic mode */  		
	#else
    /* Configure next descriptor table address */
    DMA_DESC_CH0[3].u32Offset = (uint32_t)&DMA_DESC_CH0[4] - (PDMA->SCATBA); /* next descriptor table is table 4 */     
	#endif
    #endif  
    #if(NUCODEGEN_PDMA_CH0_OPMODE_TB3_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_CH0[4].u32Ctl =
        (((uint32_t)PDMA_CH0_DATA_LENGTH_TB4 - 1) << PDMA_DSCT_CTL_TXCNT_Pos) | /* Set transfer count */ \
        NUCODEGEN_PDMA_CH0_WIDTH_TB4 |   /* Set transfer width */ \
        NUCODEGEN_PDMA_CH0_SRC_TYPE_TB4 |    /* Set source increment type */ \
        NUCODEGEN_PDMA_CH0_DES_TYPE_TB4 |    /* Set destination increment type */ \
        NUCODEGEN_PDMA_CH0_MODE_TB4 |  /* Set transfer type */ \
        NUCODEGEN_PDMA_CH0_BURST_SIZE_TB4 |  /* Set burst size */ \
        NUCODEGEN_PDMA_CH0_TB4_INT_EN |   /* Set table empty interrupt */ \
        NUCODEGEN_PDMA_CH0_OPMODE_TB4;  /* Set operation mode */
        
    /* Configure source address */  
    DMA_DESC_CH0[4].u32Src = (uint32_t)NUCODEGEN_PDMA_CH0_SRC_ADDR_TB4;
    
    /* Configure destination address */
    DMA_DESC_CH0[4].u32Dest = (uint32_t)NUCODEGEN_PDMA_CH0_DES_ADDR_TB4;
    
    /* Configure next descriptor table address */
    DMA_DESC_CH0[4].u32Offset = (uint32_t)&DMA_DESC_CH0[5] - (PDMA->SCATBA); /* next descriptor table is table 5 */     
    #endif  
    
    #if(NUCODEGEN_PDMA_CH0_TMOUT)
    /* Enable timeout function and set timeout counter */
    PDMA_SetTimeOut(PDMA, 0, NUCODEGEN_PDMA_CH0_TMOUT, NUCODEGEN_PDMA_CH0_TMOUT_CNT);  
    #endif
    
    #if(NUCODEGEN_PDMA_CH0_STRIDE_EN)
    /* Set stride function */
    PDMA_SetStride(PDMA, 0, NUCODEGEN_PDMA_CH0_STRIDE_DES_LENGTH, NUCODEGEN_PDMA_CH0_STRIDE_SRC_LENGTH, NUCODEGEN_PDMA_CH0_STRIDE_CNT);
    #endif
    
    /* Request source is NUCODEGEN_PDMA_CH0_SRC_DES_SEL */
    PDMA_SetTransferMode(PDMA, 0, NUCODEGEN_PDMA_CH0_SRC_DES_SEL, 1, (uint32_t)&DMA_DESC_CH0[0]);
#endif  //NUCODEGEN_PDMA_CH0_OPMODE == PDMA_OP_BASIC
#endif  //NUCODEGEN_PDMA_CH0

#if (NUCODEGEN_PDMA_CH1)
#if (NUCODEGEN_PDMA_CH1_OPMODE_S == NUCODEGEN_PDMA_OP_BASIC)
    /* Open CH1 */
    PDMA_Open(PDMA, 1 << 1);
    
    /* Transfer count is PDMA_CH1_DATA_LENGTH, transfer width is NUCODEGEN_PDMA_CH1_WIDTH */
    PDMA_SetTransferCnt(PDMA, 1, NUCODEGEN_PDMA_CH1_WIDTH, PDMA_CH1_DATA_LENGTH);
    
    /* Set source address is NUCODEGEN_PDMA_CH1_SRC_ADDR, destination address is NUCODEGEN_PDMA_CH1_DES_ADDR */
    PDMA_SetTransferAddr(PDMA, 1, (uint32_t)NUCODEGEN_PDMA_CH1_SRC_ADDR, NUCODEGEN_PDMA_CH1_SRC_TYPE, (uint32_t)NUCODEGEN_PDMA_CH1_DES_ADDR, NUCODEGEN_PDMA_CH1_DES_TYPE);
    
    /* Set transfer mode and burst size */
    PDMA_SetBurstType(PDMA, 1, NUCODEGEN_PDMA_CH1_MODE, NUCODEGEN_PDMA_CH1_BURST_SIZE);
    
    /* Enable timeout function and set timeout counter */
    PDMA_SetTimeOut(PDMA, 1, NUCODEGEN_PDMA_CH1_TMOUT, NUCODEGEN_PDMA_CH1_TMOUT_CNT);      
    #if(NUCODEGEN_PDMA_CH1_STRIDE_EN)
    /* Set stride function */
    PDMA_SetStride(PDMA, 1, NUCODEGEN_PDMA_CH1_STRIDE_DES_LENGTH, NUCODEGEN_PDMA_CH1_STRIDE_SRC_LENGTH, NUCODEGEN_PDMA_CH1_STRIDE_CNT);
    #endif
    
    /* Request source is NUCODEGEN_PDMA_CH1_SRC_DES_SEL */
    PDMA_SetTransferMode(PDMA, 1, NUCODEGEN_PDMA_CH1_SRC_DES_SEL, 0, 0);
#else   //NUCODEGEN_PDMA_CH1_OPMODE_S == PDMA_OP_SCATTER
    /* Open CH1 */
    PDMA_Open(PDMA, 1 << 1);    
    
    DMA_DESC_CH1[0].u32Ctl =
        (((uint32_t)PDMA_CH1_DATA_LENGTH_TB0 - 1) << PDMA_DSCT_CTL_TXCNT_Pos) | /* Set transfer count */ \
        NUCODEGEN_PDMA_CH1_WIDTH_TB0 |   /* Set transfer width */ \
        NUCODEGEN_PDMA_CH1_SRC_TYPE_TB0 |    /* Set source increment type */ \
        NUCODEGEN_PDMA_CH1_DES_TYPE_TB0 |    /* Set destination increment type */ \
        NUCODEGEN_PDMA_CH1_MODE_TB0 |  /* Set transfer type */ \
        NUCODEGEN_PDMA_CH1_BURST_SIZE_TB0 |  /* Set burst size */ \
        NUCODEGEN_PDMA_CH1_TB0_INT_EN |   /* Set table empty interrupt */ \
        NUCODEGEN_PDMA_CH1_OPMODE_TB0;  /* Set operation mode */
        
    /* Configure source address */  
    DMA_DESC_CH1[0].u32Src = (uint32_t)NUCODEGEN_PDMA_CH1_SRC_ADDR_TB0;
    
    /* Configure destination address */
    DMA_DESC_CH1[0].u32Dest = (uint32_t)NUCODEGEN_PDMA_CH1_DES_ADDR_TB0;
    
	#if(NUCODEGEN_PDMA_CH1_OPMODE_TB0_S==NUCODEGEN_PDMA_OP_BASIC)
    /* Configure next descriptor table address */
    DMA_DESC_CH1[0].u32Offset = 0; /* No next operation table. No effect in basic mode */
	#else
    /* Configure next descriptor table address */
    DMA_DESC_CH1[0].u32Offset = (uint32_t)&DMA_DESC_CH1[1] - (PDMA->SCATBA); /* next descriptor table is table 1 */ 
    #endif
    #if(NUCODEGEN_PDMA_CH1_OPMODE_TB0_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_CH1[1].u32Ctl =
        (((uint32_t)PDMA_CH1_DATA_LENGTH_TB1 - 1) << PDMA_DSCT_CTL_TXCNT_Pos) | /* Set transfer count */ \
        NUCODEGEN_PDMA_CH1_WIDTH_TB1 |   /* Set transfer width */ \
        NUCODEGEN_PDMA_CH1_SRC_TYPE_TB1 |    /* Set source increment type */ \
        NUCODEGEN_PDMA_CH1_DES_TYPE_TB1 |    /* Set destination increment type */ \
        NUCODEGEN_PDMA_CH1_MODE_TB1 |  /* Set transfer type */ \
        NUCODEGEN_PDMA_CH1_BURST_SIZE_TB1 |  /* Set burst size */ \
        NUCODEGEN_PDMA_CH1_TB1_INT_EN |   /* Set table empty interrupt */ \
        NUCODEGEN_PDMA_CH1_OPMODE_TB1;  /* Set operation mode */
        
    /* Configure source address */  
    DMA_DESC_CH1[1].u32Src = (uint32_t)NUCODEGEN_PDMA_CH1_SRC_ADDR_TB1;
    
    /* Configure destination address */
    DMA_DESC_CH1[1].u32Dest = (uint32_t)NUCODEGEN_PDMA_CH1_DES_ADDR_TB1;
	#if(NUCODEGEN_PDMA_CH1_OPMODE_TB1_S==NUCODEGEN_PDMA_OP_BASIC)  
    /* Configure next descriptor table address */
    DMA_DESC_CH1[1].u32Offset = 0; /* No next operation table. No effect in basic mode */ 		
	#else
    /* Configure next descriptor table address */
    DMA_DESC_CH1[1].u32Offset = (uint32_t)&DMA_DESC_CH1[2] - (PDMA->SCATBA); /* next descriptor table is table 2 */     
	#endif
    #endif  
    #if(NUCODEGEN_PDMA_CH1_OPMODE_TB1_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_CH1[2].u32Ctl =
        (((uint32_t)PDMA_CH1_DATA_LENGTH_TB2 - 1) << PDMA_DSCT_CTL_TXCNT_Pos) | /* Set transfer count */ \
        NUCODEGEN_PDMA_CH1_WIDTH_TB2 |   /* Set transfer width */ \
        NUCODEGEN_PDMA_CH1_SRC_TYPE_TB2 |    /* Set source increment type */ \
        NUCODEGEN_PDMA_CH1_DES_TYPE_TB2 |    /* Set destination increment type */ \
        NUCODEGEN_PDMA_CH1_MODE_TB2 |  /* Set transfer type */ \
        NUCODEGEN_PDMA_CH1_BURST_SIZE_TB2 |  /* Set burst size */ \
        NUCODEGEN_PDMA_CH1_TB2_INT_EN |   /* Set table empty interrupt */ \
        NUCODEGEN_PDMA_CH1_OPMODE_TB2;  /* Set operation mode */
        
    /* Configure source address */  
    DMA_DESC_CH1[2].u32Src = (uint32_t)NUCODEGEN_PDMA_CH1_SRC_ADDR_TB2;
    
    /* Configure destination address */
    DMA_DESC_CH1[2].u32Dest = (uint32_t)NUCODEGEN_PDMA_CH1_DES_ADDR_TB2;
    #if(NUCODEGEN_PDMA_CH1_OPMODE_TB2_S==NUCODEGEN_PDMA_OP_BASIC)
    /* Configure next descriptor table address */
    DMA_DESC_CH1[2].u32Offset = 0; /* No next operation table. No effect in basic mode */		
	#else
    /* Configure next descriptor table address */
    DMA_DESC_CH1[2].u32Offset = (uint32_t)&DMA_DESC_CH1[3] - (PDMA->SCATBA); /* next descriptor table is table 3 */     
	#endif
    #endif
    #if(NUCODEGEN_PDMA_CH1_OPMODE_TB2_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_CH1[3].u32Ctl =
        (((uint32_t)PDMA_CH1_DATA_LENGTH_TB3 - 1) << PDMA_DSCT_CTL_TXCNT_Pos) | /* Set transfer count */ \
        NUCODEGEN_PDMA_CH1_WIDTH_TB3 |   /* Set transfer width */ \
        NUCODEGEN_PDMA_CH1_SRC_TYPE_TB3 |    /* Set source increment type */ \
        NUCODEGEN_PDMA_CH1_DES_TYPE_TB3 |    /* Set destination increment type */ \
        NUCODEGEN_PDMA_CH1_MODE_TB3 |  /* Set transfer type */ \
        NUCODEGEN_PDMA_CH1_BURST_SIZE_TB3 |  /* Set burst size */ \
        NUCODEGEN_PDMA_CH1_TB3_INT_EN |   /* Set table empty interrupt */ \
        NUCODEGEN_PDMA_CH1_OPMODE_TB3;  /* Set operation mode */
        
    /* Configure source address */  
    DMA_DESC_CH1[3].u32Src = (uint32_t)NUCODEGEN_PDMA_CH1_SRC_ADDR_TB3;
    
    /* Configure destination address */
    DMA_DESC_CH1[3].u32Dest = (uint32_t)NUCODEGEN_PDMA_CH1_DES_ADDR_TB3;
    
	#if(NUCODEGEN_PDMA_CH1_OPMODE_TB3_S==NUCODEGEN_PDMA_OP_BASIC)	
    /* Configure next descriptor table address */
    DMA_DESC_CH1[3].u32Offset = 0; /* No next operation table. No effect in basic mode */	 		
	#else
    /* Configure next descriptor table address */
    DMA_DESC_CH1[3].u32Offset = (uint32_t)&DMA_DESC_CH1[4] - (PDMA->SCATBA); /* next descriptor table is table 4 */     
	#endif
    #endif  
    #if(NUCODEGEN_PDMA_CH1_OPMODE_TB3_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_CH1[4].u32Ctl =
        (((uint32_t)PDMA_CH1_DATA_LENGTH_TB4 - 1) << PDMA_DSCT_CTL_TXCNT_Pos) | /* Set transfer count */ \
        NUCODEGEN_PDMA_CH1_WIDTH_TB4 |   /* Set transfer width */ \
        NUCODEGEN_PDMA_CH1_SRC_TYPE_TB4 |    /* Set source increment type */ \
        NUCODEGEN_PDMA_CH1_DES_TYPE_TB4 |    /* Set destination increment type */ \
        NUCODEGEN_PDMA_CH1_MODE_TB4 |  /* Set transfer type */ \
        NUCODEGEN_PDMA_CH1_BURST_SIZE_TB4 |  /* Set burst size */ \
        NUCODEGEN_PDMA_CH1_TB4_INT_EN |   /* Set table empty interrupt */ \
        NUCODEGEN_PDMA_CH1_OPMODE_TB4;  /* Set operation mode */
        
    /* Configure source address */  
    DMA_DESC_CH1[4].u32Src = (uint32_t)NUCODEGEN_PDMA_CH1_SRC_ADDR_TB4;
    
    /* Configure destination address */
    DMA_DESC_CH1[4].u32Dest = (uint32_t)NUCODEGEN_PDMA_CH1_DES_ADDR_TB4;
    
    /* Configure next descriptor table address */
    DMA_DESC_CH1[4].u32Offset = (uint32_t)&DMA_DESC_CH1[5] - (PDMA->SCATBA); /* next descriptor table is table 5 */     
    #endif  

    #if(NUCODEGEN_PDMA_CH1_TMOUT)
    /* Enable timeout function and set timeout counter */
    PDMA_SetTimeOut(PDMA, 1, NUCODEGEN_PDMA_CH1_TMOUT, NUCODEGEN_PDMA_CH1_TMOUT_CNT);  
    #endif
    
    #if(NUCODEGEN_PDMA_CH1_STRIDE_EN)
    /* Set stride function */
    PDMA_SetStride(PDMA, 1, NUCODEGEN_PDMA_CH1_STRIDE_DES_LENGTH, NUCODEGEN_PDMA_CH1_STRIDE_SRC_LENGTH, NUCODEGEN_PDMA_CH1_STRIDE_CNT);
    #endif
    
    /* Request source is NUCODEGEN_PDMA_CH1_SRC_DES_SEL */
    PDMA_SetTransferMode(PDMA, 1, NUCODEGEN_PDMA_CH1_SRC_DES_SEL, 1, (uint32_t)&DMA_DESC_CH1[0]);   
#endif  //NUCODEGEN_PDMA_CH1_OPMODE == PDMA_OP_BASIC
#endif  //NUCODEGEN_PDMA_CH1_FUNC

#if (NUCODEGEN_PDMA_CH2)
#if (NUCODEGEN_PDMA_CH2_OPMODE_S == NUCODEGEN_PDMA_OP_BASIC)
    /* Open CH2 */
    PDMA_Open(PDMA, 1 << 2);
    
    /* Transfer count is PDMA_CH2_DATA_LENGTH, transfer width is NUCODEGEN_PDMA_CH2_WIDTH */
    PDMA_SetTransferCnt(PDMA, 2, NUCODEGEN_PDMA_CH2_WIDTH, PDMA_CH2_DATA_LENGTH);
    
    /* Set source address is NUCODEGEN_PDMA_CH2_SRC_ADDR, destination address is NUCODEGEN_PDMA_CH2_DES_ADDR */
    PDMA_SetTransferAddr(PDMA, 2, (uint32_t)NUCODEGEN_PDMA_CH2_SRC_ADDR, NUCODEGEN_PDMA_CH2_SRC_TYPE, (uint32_t)NUCODEGEN_PDMA_CH2_DES_ADDR, NUCODEGEN_PDMA_CH2_DES_TYPE);
    
    /* Set transfer mode and burst size */
    PDMA_SetBurstType(PDMA, 2, NUCODEGEN_PDMA_CH2_MODE, NUCODEGEN_PDMA_CH2_BURST_SIZE);
    
    #if(NUCODEGEN_PDMA_CH2_TMOUT)
    /* Enable timeout function and set timeout counter */
    PDMA_SetTimeOut(PDMA, 2, NUCODEGEN_PDMA_CH2_TMOUT, NUCODEGEN_PDMA_CH2_TMOUT_CNT);    
    #endif
    
    #if(NUCODEGEN_PDMA_CH2_STRIDE_EN)
    /* Set stride function */
    PDMA_SetStride(PDMA, 2, NUCODEGEN_PDMA_CH2_STRIDE_DES_LENGTH, NUCODEGEN_PDMA_CH2_STRIDE_SRC_LENGTH, NUCODEGEN_PDMA_CH2_STRIDE_CNT);
    #endif
    
    /* Request source is NUCODEGEN_PDMA_CH2_SRC_DES_SEL */
    PDMA_SetTransferMode(PDMA, 2, NUCODEGEN_PDMA_CH2_SRC_DES_SEL, 0, 0);
#else   //NUCODEGEN_PDMA_CH2_OPMODE_S == PDMA_OP_SCATTER
    /* Open CH2 */
    PDMA_Open(PDMA, 1 << 2);    
    
    DMA_DESC_CH2[0].u32Ctl =
        (((uint32_t)PDMA_CH2_DATA_LENGTH_TB0 - 1) << PDMA_DSCT_CTL_TXCNT_Pos) | /* Set transfer count */ \
        NUCODEGEN_PDMA_CH2_WIDTH_TB0 |   /* Set transfer width */ \
        NUCODEGEN_PDMA_CH2_SRC_TYPE_TB0 |    /* Set source increment type */ \
        NUCODEGEN_PDMA_CH2_DES_TYPE_TB0 |    /* Set destination increment type */ \
        NUCODEGEN_PDMA_CH2_MODE_TB0 |  /* Set transfer type */ \
        NUCODEGEN_PDMA_CH2_BURST_SIZE_TB0 |  /* Set burst size */ \
        NUCODEGEN_PDMA_CH2_TB0_INT_EN |   /* Set table empty interrupt */ \
        NUCODEGEN_PDMA_CH2_OPMODE_TB0;  /* Set operation mode */
        
    /* Configure source address */  
    DMA_DESC_CH2[0].u32Src = (uint32_t)NUCODEGEN_PDMA_CH2_SRC_ADDR_TB0;
    
    /* Configure destination address */
    DMA_DESC_CH2[0].u32Dest = (uint32_t)NUCODEGEN_PDMA_CH2_DES_ADDR_TB0;
    
	#if(NUCODEGEN_PDMA_CH2_OPMODE_TB0_S==NUCODEGEN_PDMA_OP_BASIC)
    /* Configure next descriptor table address */
    DMA_DESC_CH2[0].u32Offset = 0; /* No next operation table. No effect in basic mode */		
	#else		
    /* Configure next descriptor table address */
    DMA_DESC_CH2[0].u32Offset = (uint32_t)&DMA_DESC_CH2[1] - (PDMA->SCATBA); /* next descriptor table is table 1 */ 
    #endif
    #if(NUCODEGEN_PDMA_CH2_OPMODE_TB0_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_CH2[1].u32Ctl =
        (((uint32_t)PDMA_CH2_DATA_LENGTH_TB1 - 1) << PDMA_DSCT_CTL_TXCNT_Pos) | /* Set transfer count */ \
        NUCODEGEN_PDMA_CH2_WIDTH_TB1 |   /* Set transfer width */ \
        NUCODEGEN_PDMA_CH2_SRC_TYPE_TB1 |    /* Set source increment type */ \
        NUCODEGEN_PDMA_CH2_DES_TYPE_TB1 |    /* Set destination increment type */ \
        NUCODEGEN_PDMA_CH2_MODE_TB1 |  /* Set transfer type */ \
        NUCODEGEN_PDMA_CH2_BURST_SIZE_TB1 |  /* Set burst size */ \
        NUCODEGEN_PDMA_CH2_TB1_INT_EN |   /* Set table empty interrupt */ \
        NUCODEGEN_PDMA_CH2_OPMODE_TB1;  /* Set operation mode */
        
    /* Configure source address */  
    DMA_DESC_CH2[1].u32Src = (uint32_t)NUCODEGEN_PDMA_CH2_SRC_ADDR_TB1;
    
    /* Configure destination address */
    DMA_DESC_CH2[1].u32Dest = (uint32_t)NUCODEGEN_PDMA_CH2_DES_ADDR_TB1;
	
	#if(NUCODEGEN_PDMA_CH2_OPMODE_TB1_S==NUCODEGEN_PDMA_OP_BASIC)
    /* Configure next descriptor table address */
    DMA_DESC_CH2[1].u32Offset = 0; /* No next operation table. No effect in basic mode */		
	#else		
    /* Configure next descriptor table address */
    DMA_DESC_CH2[1].u32Offset = (uint32_t)&DMA_DESC_CH2[2] - (PDMA->SCATBA); /* next descriptor table is table 2 */ 
    #endif       
    #endif  
    #if(NUCODEGEN_PDMA_CH2_OPMODE_TB1_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_CH2[2].u32Ctl =
        (((uint32_t)PDMA_CH2_DATA_LENGTH_TB2 - 1) << PDMA_DSCT_CTL_TXCNT_Pos) | /* Set transfer count */ \
        NUCODEGEN_PDMA_CH2_WIDTH_TB2 |   /* Set transfer width */ \
        NUCODEGEN_PDMA_CH2_SRC_TYPE_TB2 |    /* Set source increment type */ \
        NUCODEGEN_PDMA_CH2_DES_TYPE_TB2 |    /* Set destination increment type */ \
        NUCODEGEN_PDMA_CH2_MODE_TB2 |  /* Set transfer type */ \
        NUCODEGEN_PDMA_CH2_BURST_SIZE_TB2 |  /* Set burst size */ \
        NUCODEGEN_PDMA_CH2_TB2_INT_EN |   /* Set table empty interrupt */ \
        NUCODEGEN_PDMA_CH2_OPMODE_TB2;  /* Set operation mode */
        
    /* Configure source address */  
    DMA_DESC_CH2[2].u32Src = (uint32_t)NUCODEGEN_PDMA_CH2_SRC_ADDR_TB2;
    
    /* Configure destination address */
    DMA_DESC_CH2[2].u32Dest = (uint32_t)NUCODEGEN_PDMA_CH2_DES_ADDR_TB2;

	#if(NUCODEGEN_PDMA_CH2_OPMODE_TB2_S==NUCODEGEN_PDMA_OP_BASIC)
    /* Configure next descriptor table address */
    DMA_DESC_CH2[2].u32Offset = 0; /* No next operation table. No effect in basic mode */		
	#else		
    /* Configure next descriptor table address */
    DMA_DESC_CH2[2].u32Offset = (uint32_t)&DMA_DESC_CH2[3] - (PDMA->SCATBA); /* next descriptor table is table 3 */ 
    #endif        
    #endif
    #if(NUCODEGEN_PDMA_CH2_OPMODE_TB2_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_CH2[3].u32Ctl =
        (((uint32_t)PDMA_CH2_DATA_LENGTH_TB3 - 1) << PDMA_DSCT_CTL_TXCNT_Pos) | /* Set transfer count */ \
        NUCODEGEN_PDMA_CH2_WIDTH_TB3 |   /* Set transfer width */ \
        NUCODEGEN_PDMA_CH2_SRC_TYPE_TB3 |    /* Set source increment type */ \
        NUCODEGEN_PDMA_CH2_DES_TYPE_TB3 |    /* Set destination increment type */ \
        NUCODEGEN_PDMA_CH2_MODE_TB3 |  /* Set transfer type */ \
        NUCODEGEN_PDMA_CH2_BURST_SIZE_TB3 |  /* Set burst size */ \
        NUCODEGEN_PDMA_CH2_TB3_INT_EN |   /* Set table empty interrupt */ \
        NUCODEGEN_PDMA_CH2_OPMODE_TB3;  /* Set operation mode */
        
    /* Configure source address */  
    DMA_DESC_CH2[3].u32Src = (uint32_t)NUCODEGEN_PDMA_CH2_SRC_ADDR_TB3;
    
    /* Configure destination address */
    DMA_DESC_CH2[3].u32Dest = (uint32_t)NUCODEGEN_PDMA_CH2_DES_ADDR_TB3;	
	#if(NUCODEGEN_PDMA_CH2_OPMODE_TB3_S==NUCODEGEN_PDMA_OP_BASIC)
    /* Configure next descriptor table address */
    DMA_DESC_CH2[3].u32Offset = 0; /* No next operation table. No effect in basic mode */		
	#else		
    /* Configure next descriptor table address */
    DMA_DESC_CH2[3].u32Offset = (uint32_t)&DMA_DESC_CH2[4] - (PDMA->SCATBA); /* next descriptor table is table 4 */ 
    #endif       
    #endif  
    #if(NUCODEGEN_PDMA_CH2_OPMODE_TB3_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_CH2[4].u32Ctl =
        (((uint32_t)PDMA_CH2_DATA_LENGTH_TB4 - 1) << PDMA_DSCT_CTL_TXCNT_Pos) | /* Set transfer count */ \
        NUCODEGEN_PDMA_CH2_WIDTH_TB4 |   /* Set transfer width */ \
        NUCODEGEN_PDMA_CH2_SRC_TYPE_TB4 |    /* Set source increment type */ \
        NUCODEGEN_PDMA_CH2_DES_TYPE_TB4 |    /* Set destination increment type */ \
        NUCODEGEN_PDMA_CH2_MODE_TB4 |  /* Set transfer type */ \
        NUCODEGEN_PDMA_CH2_BURST_SIZE_TB4 |  /* Set burst size */ \
        NUCODEGEN_PDMA_CH2_TB4_INT_EN |   /* Set table empty interrupt */ \
        NUCODEGEN_PDMA_CH2_OPMODE_TB4;  /* Set operation mode */
        
    /* Configure source address */  
    DMA_DESC_CH2[4].u32Src = (uint32_t)NUCODEGEN_PDMA_CH2_SRC_ADDR_TB4;
    
    /* Configure destination address */
    DMA_DESC_CH2[4].u32Dest = (uint32_t)NUCODEGEN_PDMA_CH2_DES_ADDR_TB4;
    
    /* Configure next descriptor table address */
    DMA_DESC_CH2[4].u32Offset = (uint32_t)&DMA_DESC_CH2[5] - (PDMA->SCATBA); /* next descriptor table is table 5 */     
    #endif  

    #if(NUCODEGEN_PDMA_CH2_TMOUT)
    /* Enable timeout function and set timeout counter */
    PDMA_SetTimeOut(PDMA, 2, NUCODEGEN_PDMA_CH2_TMOUT, NUCODEGEN_PDMA_CH2_TMOUT_CNT);  
    #endif
    
    #if(NUCODEGEN_PDMA_CH2_STRIDE_EN)
    /* Set stride function */
    PDMA_SetStride(PDMA, 2, NUCODEGEN_PDMA_CH2_STRIDE_DES_LENGTH, NUCODEGEN_PDMA_CH2_STRIDE_SRC_LENGTH, NUCODEGEN_PDMA_CH2_STRIDE_CNT);
    #endif
    
    /* Request source is NUCODEGEN_PDMA_CH2_SRC_DES_SEL */
    PDMA_SetTransferMode(PDMA, 2, NUCODEGEN_PDMA_CH2_SRC_DES_SEL, 1, (uint32_t)&DMA_DESC_CH2[0]);   
#endif  //NUCODEGEN_PDMA_CH2_OPMODE == PDMA_OP_BASIC
#endif  //NUCODEGEN_PDMA_CH2_FUNC

#if (NUCODEGEN_PDMA_CH3)
#if (NUCODEGEN_PDMA_CH3_OPMODE_S == NUCODEGEN_PDMA_OP_BASIC)
    /* Open CH3 */
    PDMA_Open(PDMA, 1 << 3);
    
    /* Transfer count is PDMA_CH3_DATA_LENGTH, transfer width is NUCODEGEN_PDMA_CH3_WIDTH */
    PDMA_SetTransferCnt(PDMA, 3, NUCODEGEN_PDMA_CH3_WIDTH, PDMA_CH3_DATA_LENGTH);
    
    /* Set source address is NUCODEGEN_PDMA_CH3_SRC_ADDR, destination address is NUCODEGEN_PDMA_CH3_DES_ADDR */
    PDMA_SetTransferAddr(PDMA, 3, (uint32_t)NUCODEGEN_PDMA_CH3_SRC_ADDR, NUCODEGEN_PDMA_CH3_SRC_TYPE, (uint32_t)NUCODEGEN_PDMA_CH3_DES_ADDR, NUCODEGEN_PDMA_CH3_DES_TYPE);
    
    /* Set transfer mode and burst size */
    PDMA_SetBurstType(PDMA, 3, NUCODEGEN_PDMA_CH3_MODE, NUCODEGEN_PDMA_CH3_BURST_SIZE);
    
    #if(NUCODEGEN_PDMA_CH3_TMOUT)
    /* Enable timeout function and set timeout counter */
    PDMA_SetTimeOut(PDMA, 3, NUCODEGEN_PDMA_CH3_TMOUT, NUCODEGEN_PDMA_CH3_TMOUT_CNT);      
    #endif
    
    #if(NUCODEGEN_PDMA_CH3_STRIDE_EN)
    /* Set stride function */
    PDMA_SetStride(PDMA, 3, NUCODEGEN_PDMA_CH3_STRIDE_DES_LENGTH, NUCODEGEN_PDMA_CH3_STRIDE_SRC_LENGTH, NUCODEGEN_PDMA_CH3_STRIDE_CNT);
    #endif
    
    /* Request source is NUCODEGEN_PDMA_CH3_SRC_DES_SEL */
    PDMA_SetTransferMode(PDMA, 3, NUCODEGEN_PDMA_CH3_SRC_DES_SEL, 0, 0);
#else   //NUCODEGEN_PDMA_CH3_OPMODE_S == PDMA_OP_SCATTER
    /* Open CH3 */
    PDMA_Open(PDMA, 1 << 3);    
    
    DMA_DESC_CH3[0].u32Ctl =
        (((uint32_t)PDMA_CH3_DATA_LENGTH_TB0 - 1) << PDMA_DSCT_CTL_TXCNT_Pos) | /* Set transfer count */ \
        NUCODEGEN_PDMA_CH3_WIDTH_TB0 |   /* Set transfer width */ \
        NUCODEGEN_PDMA_CH3_SRC_TYPE_TB0 |    /* Set source increment type */ \
        NUCODEGEN_PDMA_CH3_DES_TYPE_TB0 |    /* Set destination increment type */ \
        NUCODEGEN_PDMA_CH3_MODE_TB0 |  /* Set transfer type */ \
        NUCODEGEN_PDMA_CH3_BURST_SIZE_TB0 |  /* Set burst size */ \
        NUCODEGEN_PDMA_CH3_TB0_INT_EN |   /* Set table empty interrupt */ \
        NUCODEGEN_PDMA_CH3_OPMODE_TB0;  /* Set operation mode */
        
    /* Configure source address */  
    DMA_DESC_CH3[0].u32Src = (uint32_t)NUCODEGEN_PDMA_CH3_SRC_ADDR_TB0;
    
    /* Configure destination address */
    DMA_DESC_CH3[0].u32Dest = (uint32_t)NUCODEGEN_PDMA_CH3_DES_ADDR_TB0;
	
    #if(NUCODEGEN_PDMA_CH3_OPMODE_TB0_S==NUCODEGEN_PDMA_OP_BASIC)
    /* Configure next descriptor table address */
    DMA_DESC_CH3[0].u32Offset = 0; /* No next operation table. No effect in basic mode */		
	#else		
    /* Configure next descriptor table address */
    DMA_DESC_CH3[0].u32Offset = (uint32_t)&DMA_DESC_CH3[1] - (PDMA->SCATBA); /* next descriptor table is table 1 */ 
    #endif    
    #if(NUCODEGEN_PDMA_CH3_OPMODE_TB0_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_CH3[1].u32Ctl =
        (((uint32_t)PDMA_CH3_DATA_LENGTH_TB1 - 1) << PDMA_DSCT_CTL_TXCNT_Pos) | /* Set transfer count */ \
        NUCODEGEN_PDMA_CH3_WIDTH_TB1 |   /* Set transfer width */ \
        NUCODEGEN_PDMA_CH3_SRC_TYPE_TB1 |    /* Set source increment type */ \
        NUCODEGEN_PDMA_CH3_DES_TYPE_TB1 |    /* Set destination increment type */ \
        NUCODEGEN_PDMA_CH3_MODE_TB1 |  /* Set transfer type */ \
        NUCODEGEN_PDMA_CH3_BURST_SIZE_TB1 |  /* Set burst size */ \
        NUCODEGEN_PDMA_CH3_TB1_INT_EN |   /* Set table empty interrupt */ \
        NUCODEGEN_PDMA_CH3_OPMODE_TB1;  /* Set operation mode */
        
    /* Configure source address */  
    DMA_DESC_CH3[1].u32Src = (uint32_t)NUCODEGEN_PDMA_CH3_SRC_ADDR_TB1;
    
    /* Configure destination address */
    DMA_DESC_CH3[1].u32Dest = (uint32_t)NUCODEGEN_PDMA_CH3_DES_ADDR_TB1;
	
    #if(NUCODEGEN_PDMA_CH3_OPMODE_TB1_S==NUCODEGEN_PDMA_OP_BASIC)
    /* Configure next descriptor table address */
    DMA_DESC_CH3[1].u32Offset = 0; /* No next operation table. No effect in basic mode */		
	#else		
    /* Configure next descriptor table address */
    DMA_DESC_CH3[1].u32Offset = (uint32_t)&DMA_DESC_CH3[2] - (PDMA->SCATBA); /* next descriptor table is table 2 */ 
    #endif      
    #endif  
    #if(NUCODEGEN_PDMA_CH3_OPMODE_TB1_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_CH3[2].u32Ctl =
        (((uint32_t)PDMA_CH3_DATA_LENGTH_TB2 - 1) << PDMA_DSCT_CTL_TXCNT_Pos) | /* Set transfer count */ \
        NUCODEGEN_PDMA_CH3_WIDTH_TB2 |   /* Set transfer width */ \
        NUCODEGEN_PDMA_CH3_SRC_TYPE_TB2 |    /* Set source increment type */ \
        NUCODEGEN_PDMA_CH3_DES_TYPE_TB2 |    /* Set destination increment type */ \
        NUCODEGEN_PDMA_CH3_MODE_TB2 |  /* Set transfer type */ \
        NUCODEGEN_PDMA_CH3_BURST_SIZE_TB2 |  /* Set burst size */ \
        NUCODEGEN_PDMA_CH3_TB2_INT_EN |   /* Set table empty interrupt */ \
        NUCODEGEN_PDMA_CH3_OPMODE_TB2;  /* Set operation mode */
        
    /* Configure source address */  
    DMA_DESC_CH3[2].u32Src = (uint32_t)NUCODEGEN_PDMA_CH3_SRC_ADDR_TB2;
    
    /* Configure destination address */
    DMA_DESC_CH3[2].u32Dest = (uint32_t)NUCODEGEN_PDMA_CH3_DES_ADDR_TB2;
    
    #if(NUCODEGEN_PDMA_CH3_OPMODE_TB2_S==NUCODEGEN_PDMA_OP_BASIC)
    /* Configure next descriptor table address */
    DMA_DESC_CH3[2].u32Offset = 0; /* No next operation table. No effect in basic mode */		
	#else		
    /* Configure next descriptor table address */
    DMA_DESC_CH3[2].u32Offset = (uint32_t)&DMA_DESC_CH3[3] - (PDMA->SCATBA); /* next descriptor table is table 3 */    
    #endif
	#endif
    #if(NUCODEGEN_PDMA_CH3_OPMODE_TB2_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_CH3[3].u32Ctl =
        (((uint32_t)PDMA_CH3_DATA_LENGTH_TB3 - 1) << PDMA_DSCT_CTL_TXCNT_Pos) | /* Set transfer count */ \
        NUCODEGEN_PDMA_CH3_WIDTH_TB3 |   /* Set transfer width */ \
        NUCODEGEN_PDMA_CH3_SRC_TYPE_TB3 |    /* Set source increment type */ \
        NUCODEGEN_PDMA_CH3_DES_TYPE_TB3 |    /* Set destination increment type */ \
        NUCODEGEN_PDMA_CH3_MODE_TB3 |  /* Set transfer type */ \
        NUCODEGEN_PDMA_CH3_BURST_SIZE_TB3 |  /* Set burst size */ \
        NUCODEGEN_PDMA_CH3_TB3_INT_EN |   /* Set table empty interrupt */ \
        NUCODEGEN_PDMA_CH3_OPMODE_TB3;  /* Set operation mode */
        
    /* Configure source address */  
    DMA_DESC_CH3[3].u32Src = (uint32_t)NUCODEGEN_PDMA_CH3_SRC_ADDR_TB3;
    
    /* Configure destination address */
    DMA_DESC_CH3[3].u32Dest = (uint32_t)NUCODEGEN_PDMA_CH3_DES_ADDR_TB3;

    #if(NUCODEGEN_PDMA_CH3_OPMODE_TB3_S==NUCODEGEN_PDMA_OP_BASIC)
    /* Configure next descriptor table address */
    DMA_DESC_CH3[3].u32Offset = 0; /* No next operation table. No effect in basic mode */		
	#else		
    /* Configure next descriptor table address */
    DMA_DESC_CH3[3].u32Offset = (uint32_t)&DMA_DESC_CH3[4] - (PDMA->SCATBA); /* next descriptor table is table 4 */      
    #endif  
	#endif
    #if(NUCODEGEN_PDMA_CH3_OPMODE_TB3_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_CH3[4].u32Ctl =
        (((uint32_t)PDMA_CH3_DATA_LENGTH_TB4 - 1) << PDMA_DSCT_CTL_TXCNT_Pos) | /* Set transfer count */ \
        NUCODEGEN_PDMA_CH3_WIDTH_TB4 |   /* Set transfer width */ \
        NUCODEGEN_PDMA_CH3_SRC_TYPE_TB4 |    /* Set source increment type */ \
        NUCODEGEN_PDMA_CH3_DES_TYPE_TB4 |    /* Set destination increment type */ \
        NUCODEGEN_PDMA_CH3_MODE_TB4 |  /* Set transfer type */ \
        NUCODEGEN_PDMA_CH3_BURST_SIZE_TB4 |  /* Set burst size */ \
        NUCODEGEN_PDMA_CH3_TB4_INT_EN |   /* Set table empty interrupt */ \
        NUCODEGEN_PDMA_CH3_OPMODE_TB4;  /* Set operation mode */
        
    /* Configure source address */  
    DMA_DESC_CH3[4].u32Src = (uint32_t)NUCODEGEN_PDMA_CH3_SRC_ADDR_TB4;
    
    /* Configure destination address */
    DMA_DESC_CH3[4].u32Dest = (uint32_t)NUCODEGEN_PDMA_CH3_DES_ADDR_TB4;
    
    /* Configure next descriptor table address */
    DMA_DESC_CH3[4].u32Offset = (uint32_t)&DMA_DESC_CH3[5] - (PDMA->SCATBA); /* next descriptor table is table 5 */     
    #endif  

    #if(NUCODEGEN_PDMA_CH3_TMOUT)
    /* Enable timeout function and set timeout counter */
    PDMA_SetTimeOut(PDMA, 3, NUCODEGEN_PDMA_CH3_TMOUT, NUCODEGEN_PDMA_CH3_TMOUT_CNT);  
    #endif
    
    #if(NUCODEGEN_PDMA_CH3_STRIDE_EN)
    /* Set stride function */
    PDMA_SetStride(PDMA, 3, NUCODEGEN_PDMA_CH3_STRIDE_DES_LENGTH, NUCODEGEN_PDMA_CH3_STRIDE_SRC_LENGTH, NUCODEGEN_PDMA_CH3_STRIDE_CNT);
    #endif
    
    /* Request source is NUCODEGEN_PDMA_CH3_SRC_DES_SEL */
    PDMA_SetTransferMode(PDMA, 3, NUCODEGEN_PDMA_CH3_SRC_DES_SEL, 1, (uint32_t)&DMA_DESC_CH3[0]);   
#endif  //NUCODEGEN_PDMA_CH3_OPMODE == PDMA_OP_BASIC
#endif  //NUCODEGEN_PDMA_CH3_FUNC

#if (NUCODEGEN_PDMA_CH4)
#if (NUCODEGEN_PDMA_CH4_OPMODE_S == NUCODEGEN_PDMA_OP_BASIC)
    /* Open CH4 */
    PDMA_Open(PDMA, 1 << 4);
    
    /* Transfer count is PDMA_CH4_DATA_LENGTH, transfer width is NUCODEGEN_PDMA_CH4_WIDTH */
    PDMA_SetTransferCnt(PDMA, 4, NUCODEGEN_PDMA_CH4_WIDTH, PDMA_CH4_DATA_LENGTH);
    
    /* Set source address is NUCODEGEN_PDMA_CH4_SRC_ADDR, destination address is NUCODEGEN_PDMA_CH4_DES_ADDR */
    PDMA_SetTransferAddr(PDMA, 4, (uint32_t)NUCODEGEN_PDMA_CH4_SRC_ADDR, NUCODEGEN_PDMA_CH4_SRC_TYPE, (uint32_t)NUCODEGEN_PDMA_CH4_DES_ADDR, NUCODEGEN_PDMA_CH4_DES_TYPE);
    
    /* Set transfer mode and burst size */
    PDMA_SetBurstType(PDMA, 4, NUCODEGEN_PDMA_CH4_MODE, NUCODEGEN_PDMA_CH4_BURST_SIZE);
    
    #if(NUCODEGEN_PDMA_CH4_TMOUT)
    /* Enable timeout function and set timeout counter */
    PDMA_SetTimeOut(PDMA, 4, NUCODEGEN_PDMA_CH4_TMOUT, NUCODEGEN_PDMA_CH4_TMOUT_CNT);      
    #endif
    
    #if(NUCODEGEN_PDMA_CH4_STRIDE_EN)
    /* Set stride function */
    PDMA_SetStride(PDMA, 4, NUCODEGEN_PDMA_CH4_STRIDE_DES_LENGTH, NUCODEGEN_PDMA_CH4_STRIDE_SRC_LENGTH, NUCODEGEN_PDMA_CH4_STRIDE_CNT);
    #endif
    
    /* Request source is NUCODEGEN_PDMA_CH4_SRC_DES_SEL */
    PDMA_SetTransferMode(PDMA, 4, NUCODEGEN_PDMA_CH4_SRC_DES_SEL, 0, 0);
#else   //NUCODEGEN_PDMA_CH4_OPMODE_S == PDMA_OP_SCATTER
    /* Open CH4 */
    PDMA_Open(PDMA, 1 << 4);    
    
    DMA_DESC_CH4[0].u32Ctl =
        (((uint32_t)PDMA_CH4_DATA_LENGTH_TB0 - 1) << PDMA_DSCT_CTL_TXCNT_Pos) | /* Set transfer count */ \
        NUCODEGEN_PDMA_CH4_WIDTH_TB0 |   /* Set transfer width */ \
        NUCODEGEN_PDMA_CH4_SRC_TYPE_TB0 |    /* Set source increment type */ \
        NUCODEGEN_PDMA_CH4_DES_TYPE_TB0 |    /* Set destination increment type */ \
        NUCODEGEN_PDMA_CH4_MODE_TB0 |  /* Set transfer type */ \
        NUCODEGEN_PDMA_CH4_BURST_SIZE_TB0 |  /* Set burst size */ \
        NUCODEGEN_PDMA_CH4_TB0_INT_EN |   /* Set table empty interrupt */ \
        NUCODEGEN_PDMA_CH4_OPMODE_TB0;  /* Set operation mode */
        
    /* Configure source address */  
    DMA_DESC_CH4[0].u32Src = (uint32_t)NUCODEGEN_PDMA_CH4_SRC_ADDR_TB0;
    
    /* Configure destination address */
    DMA_DESC_CH4[0].u32Dest = (uint32_t)NUCODEGEN_PDMA_CH4_DES_ADDR_TB0;
	
    #if(NUCODEGEN_PDMA_CH4_OPMODE_TB0_S==NUCODEGEN_PDMA_OP_BASIC)
    /* Configure next descriptor table address */
    DMA_DESC_CH4[0].u32Offset = 0; /* No next operation table. No effect in basic mode */		
	#else
    /* Configure next descriptor table address */
    DMA_DESC_CH4[0].u32Offset = (uint32_t)&DMA_DESC_CH4[1] - (PDMA->SCATBA); /* next descriptor table is table 1 */ 
    #endif
    #if(NUCODEGEN_PDMA_CH4_OPMODE_TB0_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_CH4[1].u32Ctl =
        (((uint32_t)PDMA_CH4_DATA_LENGTH_TB1 - 1) << PDMA_DSCT_CTL_TXCNT_Pos) | /* Set transfer count */ \
        NUCODEGEN_PDMA_CH4_WIDTH_TB1 |   /* Set transfer width */ \
        NUCODEGEN_PDMA_CH4_SRC_TYPE_TB1 |    /* Set source increment type */ \
        NUCODEGEN_PDMA_CH4_DES_TYPE_TB1 |    /* Set destination increment type */ \
        NUCODEGEN_PDMA_CH4_MODE_TB1 |  /* Set transfer type */ \
        NUCODEGEN_PDMA_CH4_BURST_SIZE_TB1 |  /* Set burst size */ \
        NUCODEGEN_PDMA_CH4_TB1_INT_EN |   /* Set table empty interrupt */ \
        NUCODEGEN_PDMA_CH4_OPMODE_TB1;  /* Set operation mode */
        
    /* Configure source address */  
    DMA_DESC_CH4[1].u32Src = (uint32_t)NUCODEGEN_PDMA_CH4_SRC_ADDR_TB1;
    
    /* Configure destination address */
    DMA_DESC_CH4[1].u32Dest = (uint32_t)NUCODEGEN_PDMA_CH4_DES_ADDR_TB1;
	
    #if(NUCODEGEN_PDMA_CH4_OPMODE_TB1_S==NUCODEGEN_PDMA_OP_BASIC)
    /* Configure next descriptor table address */
    DMA_DESC_CH4[1].u32Offset = 0; /* No next operation table. No effect in basic mode */		
	#else
    /* Configure next descriptor table address */
    DMA_DESC_CH4[1].u32Offset = (uint32_t)&DMA_DESC_CH4[2] - (PDMA->SCATBA); /* next descriptor table is table 2 */ 
    #endif        
    #endif  
    #if(NUCODEGEN_PDMA_CH4_OPMODE_TB1_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_CH4[2].u32Ctl =
        (((uint32_t)PDMA_CH4_DATA_LENGTH_TB2 - 1) << PDMA_DSCT_CTL_TXCNT_Pos) | /* Set transfer count */ \
        NUCODEGEN_PDMA_CH4_WIDTH_TB2 |   /* Set transfer width */ \
        NUCODEGEN_PDMA_CH4_SRC_TYPE_TB2 |    /* Set source increment type */ \
        NUCODEGEN_PDMA_CH4_DES_TYPE_TB2 |    /* Set destination increment type */ \
        NUCODEGEN_PDMA_CH4_MODE_TB2 |  /* Set transfer type */ \
        NUCODEGEN_PDMA_CH4_BURST_SIZE_TB2 |  /* Set burst size */ \
        NUCODEGEN_PDMA_CH4_TB2_INT_EN |   /* Set table empty interrupt */ \
        NUCODEGEN_PDMA_CH4_OPMODE_TB2;  /* Set operation mode */
        
    /* Configure source address */  
    DMA_DESC_CH4[2].u32Src = (uint32_t)NUCODEGEN_PDMA_CH4_SRC_ADDR_TB2;
    
    /* Configure destination address */
    DMA_DESC_CH4[2].u32Dest = (uint32_t)NUCODEGEN_PDMA_CH4_DES_ADDR_TB2;

    #if(NUCODEGEN_PDMA_CH4_OPMODE_TB2_S==NUCODEGEN_PDMA_OP_BASIC)
    /* Configure next descriptor table address */
    DMA_DESC_CH4[2].u32Offset = 0; /* No next operation table. No effect in basic mode */		
	#else
    /* Configure next descriptor table address */
    DMA_DESC_CH4[2].u32Offset = (uint32_t)&DMA_DESC_CH4[3] - (PDMA->SCATBA); /* next descriptor table is table 3 */ 
    #endif    
    #endif
    #if(NUCODEGEN_PDMA_CH4_OPMODE_TB2_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_CH4[3].u32Ctl =
        (((uint32_t)PDMA_CH4_DATA_LENGTH_TB3 - 1) << PDMA_DSCT_CTL_TXCNT_Pos) | /* Set transfer count */ \
        NUCODEGEN_PDMA_CH4_WIDTH_TB3 |   /* Set transfer width */ \
        NUCODEGEN_PDMA_CH4_SRC_TYPE_TB3 |    /* Set source increment type */ \
        NUCODEGEN_PDMA_CH4_DES_TYPE_TB3 |    /* Set destination increment type */ \
        NUCODEGEN_PDMA_CH4_MODE_TB3 |  /* Set transfer type */ \
        NUCODEGEN_PDMA_CH4_BURST_SIZE_TB3 |  /* Set burst size */ \
        NUCODEGEN_PDMA_CH4_TB3_INT_EN |   /* Set table empty interrupt */ \
        NUCODEGEN_PDMA_CH4_OPMODE_TB3;  /* Set operation mode */
        
    /* Configure source address */  
    DMA_DESC_CH4[3].u32Src = (uint32_t)NUCODEGEN_PDMA_CH4_SRC_ADDR_TB3;
    
    /* Configure destination address */
    DMA_DESC_CH4[3].u32Dest = (uint32_t)NUCODEGEN_PDMA_CH4_DES_ADDR_TB3;
	
    #if(NUCODEGEN_PDMA_CH4_OPMODE_TB3_S==NUCODEGEN_PDMA_OP_BASIC)
    /* Configure next descriptor table address */
    DMA_DESC_CH4[3].u32Offset = 0; /* No next operation table. No effect in basic mode */		
	#else
    /* Configure next descriptor table address */
    DMA_DESC_CH4[3].u32Offset = (uint32_t)&DMA_DESC_CH4[4] - (PDMA->SCATBA); /* next descriptor table is table 4 */ 
    #endif    
    #endif  
    #if(NUCODEGEN_PDMA_CH4_OPMODE_TB3_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_CH4[4].u32Ctl =
        (((uint32_t)PDMA_CH4_DATA_LENGTH_TB4 - 1) << PDMA_DSCT_CTL_TXCNT_Pos) | /* Set transfer count */ \
        NUCODEGEN_PDMA_CH4_WIDTH_TB4 |   /* Set transfer width */ \
        NUCODEGEN_PDMA_CH4_SRC_TYPE_TB4 |    /* Set source increment type */ \
        NUCODEGEN_PDMA_CH4_DES_TYPE_TB4 |    /* Set destination increment type */ \
        NUCODEGEN_PDMA_CH4_MODE_TB4 |  /* Set transfer type */ \
        NUCODEGEN_PDMA_CH4_BURST_SIZE_TB4 |  /* Set burst size */ \
        NUCODEGEN_PDMA_CH4_TB4_INT_EN |   /* Set table empty interrupt */ \
        NUCODEGEN_PDMA_CH4_OPMODE_TB4;  /* Set operation mode */
        
    /* Configure source address */  
    DMA_DESC_CH4[4].u32Src = (uint32_t)NUCODEGEN_PDMA_CH4_SRC_ADDR_TB4;
    
    /* Configure destination address */
    DMA_DESC_CH4[4].u32Dest = (uint32_t)NUCODEGEN_PDMA_CH4_DES_ADDR_TB4;
    
    /* Configure next descriptor table address */
    DMA_DESC_CH4[4].u32Offset = (uint32_t)&DMA_DESC_CH4[5] - (PDMA->SCATBA); /* next descriptor table is table 5 */     
    #endif  

    #if(NUCODEGEN_PDMA_CH4_TMOUT)
    /* Enable timeout function and set timeout counter */
    PDMA_SetTimeOut(PDMA, 4, NUCODEGEN_PDMA_CH4_TMOUT, NUCODEGEN_PDMA_CH4_TMOUT_CNT);  
    #endif
    
    #if(NUCODEGEN_PDMA_CH4_STRIDE_EN)
    /* Set stride function */
    PDMA_SetStride(PDMA, 4, NUCODEGEN_PDMA_CH4_STRIDE_DES_LENGTH, NUCODEGEN_PDMA_CH4_STRIDE_SRC_LENGTH, NUCODEGEN_PDMA_CH4_STRIDE_CNT);
    #endif
    
    /* Request source is NUCODEGEN_PDMA_CH4_SRC_DES_SEL */
    PDMA_SetTransferMode(PDMA, 4, NUCODEGEN_PDMA_CH4_SRC_DES_SEL, 1, (uint32_t)&DMA_DESC_CH4[0]);   
#endif  //NUCODEGEN_PDMA_CH4_OPMODE == PDMA_OP_BASIC
#endif  //NUCODEGEN_PDMA_CH4_FUNC

#if (NUCODEGEN_PDMA_CH5)
#if (NUCODEGEN_PDMA_CH5_OPMODE_S == NUCODEGEN_PDMA_OP_BASIC)
    /* Open CH5 */
    PDMA_Open(PDMA, 1 << 5);
    
    /* Transfer count is PDMA_CH5_DATA_LENGTH, transfer width is NUCODEGEN_PDMA_CH5_WIDTH */
    PDMA_SetTransferCnt(PDMA, 5, NUCODEGEN_PDMA_CH5_WIDTH, PDMA_CH5_DATA_LENGTH);
    
    /* Set source address is NUCODEGEN_PDMA_CH5_SRC_ADDR, destination address is NUCODEGEN_PDMA_CH5_DES_ADDR */
    PDMA_SetTransferAddr(PDMA, 5, (uint32_t)NUCODEGEN_PDMA_CH5_SRC_ADDR, NUCODEGEN_PDMA_CH5_SRC_TYPE, (uint32_t)NUCODEGEN_PDMA_CH5_DES_ADDR, NUCODEGEN_PDMA_CH5_DES_TYPE);
    
    /* Set transfer mode and burst size */
    PDMA_SetBurstType(PDMA, 5, NUCODEGEN_PDMA_CH5_MODE, NUCODEGEN_PDMA_CH5_BURST_SIZE);
    
    #if(NUCODEGEN_PDMA_CH5_TMOUT)
    /* Enable timeout function and set timeout counter */
    PDMA_SetTimeOut(PDMA, 5, NUCODEGEN_PDMA_CH5_TMOUT, NUCODEGEN_PDMA_CH5_TMOUT_CNT);      
    #endif
    
    #if(NUCODEGEN_PDMA_CH5_STRIDE_EN)
    /* Set stride function */
    PDMA_SetStride(PDMA, 5, NUCODEGEN_PDMA_CH5_STRIDE_DES_LENGTH, NUCODEGEN_PDMA_CH5_STRIDE_SRC_LENGTH, NUCODEGEN_PDMA_CH5_STRIDE_CNT);
    #endif
    
    /* Request source is NUCODEGEN_PDMA_CH5_SRC_DES_SEL */
    PDMA_SetTransferMode(PDMA, 5, NUCODEGEN_PDMA_CH5_SRC_DES_SEL, 0, 0);
#else   //NUCODEGEN_PDMA_CH5_OPMODE_S == PDMA_OP_SCATTER
    /* Open CH5 */
    PDMA_Open(PDMA, 1 << 5);    
    
    DMA_DESC_CH5[0].u32Ctl =
        (((uint32_t)PDMA_CH5_DATA_LENGTH_TB0 - 1) << PDMA_DSCT_CTL_TXCNT_Pos) | /* Set transfer count */ \
        NUCODEGEN_PDMA_CH5_WIDTH_TB0 |   /* Set transfer width */ \
        NUCODEGEN_PDMA_CH5_SRC_TYPE_TB0 |    /* Set source increment type */ \
        NUCODEGEN_PDMA_CH5_DES_TYPE_TB0 |    /* Set destination increment type */ \
        NUCODEGEN_PDMA_CH5_MODE_TB0 |  /* Set transfer type */ \
        NUCODEGEN_PDMA_CH5_BURST_SIZE_TB0 |  /* Set burst size */ \
        NUCODEGEN_PDMA_CH5_TB0_INT_EN |   /* Set table empty interrupt */ \
        NUCODEGEN_PDMA_CH5_OPMODE_TB0;  /* Set operation mode */
        
    /* Configure source address */  
    DMA_DESC_CH5[0].u32Src = (uint32_t)NUCODEGEN_PDMA_CH5_SRC_ADDR_TB0;
    
    /* Configure destination address */
    DMA_DESC_CH5[0].u32Dest = (uint32_t)NUCODEGEN_PDMA_CH5_DES_ADDR_TB0;
    
	#if(NUCODEGEN_PDMA_CH5_OPMODE_TB0_S==NUCODEGEN_PDMA_OP_BASIC)
    /* Configure next descriptor table address */
    DMA_DESC_CH5[0].u32Offset = 0; /* No next operation table. No effect in basic mode */		
    #else		
    /* Configure next descriptor table address */
    DMA_DESC_CH5[0].u32Offset = (uint32_t)&DMA_DESC_CH5[1] - (PDMA->SCATBA); /* next descriptor table is table 1 */ 
    #endif
    #if(NUCODEGEN_PDMA_CH5_OPMODE_TB0_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_CH5[1].u32Ctl =
        (((uint32_t)PDMA_CH5_DATA_LENGTH_TB1 - 1) << PDMA_DSCT_CTL_TXCNT_Pos) | /* Set transfer count */ \
        NUCODEGEN_PDMA_CH5_WIDTH_TB1 |   /* Set transfer width */ \
        NUCODEGEN_PDMA_CH5_SRC_TYPE_TB1 |    /* Set source increment type */ \
        NUCODEGEN_PDMA_CH5_DES_TYPE_TB1 |    /* Set destination increment type */ \
        NUCODEGEN_PDMA_CH5_MODE_TB1 |  /* Set transfer type */ \
        NUCODEGEN_PDMA_CH5_BURST_SIZE_TB1 |  /* Set burst size */ \
        NUCODEGEN_PDMA_CH5_TB1_INT_EN |   /* Set table empty interrupt */ \
        NUCODEGEN_PDMA_CH5_OPMODE_TB1;  /* Set operation mode */
        
    /* Configure source address */  
    DMA_DESC_CH5[1].u32Src = (uint32_t)NUCODEGEN_PDMA_CH5_SRC_ADDR_TB1;
    
    /* Configure destination address */
    DMA_DESC_CH5[1].u32Dest = (uint32_t)NUCODEGEN_PDMA_CH5_DES_ADDR_TB1;
	#if(NUCODEGEN_PDMA_CH5_OPMODE_TB1_S==NUCODEGEN_PDMA_OP_BASIC)
    /* Configure next descriptor table address */
    DMA_DESC_CH5[1].u32Offset = 0; /* No next operation table. No effect in basic mode */		
    #else		
    /* Configure next descriptor table address */
    DMA_DESC_CH5[1].u32Offset = (uint32_t)&DMA_DESC_CH5[2] - (PDMA->SCATBA); /* next descriptor table is table 2 */ 
    #endif     
    #endif  
    #if(NUCODEGEN_PDMA_CH5_OPMODE_TB1_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_CH5[2].u32Ctl =
        (((uint32_t)PDMA_CH5_DATA_LENGTH_TB2 - 1) << PDMA_DSCT_CTL_TXCNT_Pos) | /* Set transfer count */ \
        NUCODEGEN_PDMA_CH5_WIDTH_TB2 |   /* Set transfer width */ \
        NUCODEGEN_PDMA_CH5_SRC_TYPE_TB2 |    /* Set source increment type */ \
        NUCODEGEN_PDMA_CH5_DES_TYPE_TB2 |    /* Set destination increment type */ \
        NUCODEGEN_PDMA_CH5_MODE_TB2 |  /* Set transfer type */ \
        NUCODEGEN_PDMA_CH5_BURST_SIZE_TB2 |  /* Set burst size */ \
        NUCODEGEN_PDMA_CH5_TB2_INT_EN |   /* Set table empty interrupt */ \
        NUCODEGEN_PDMA_CH5_OPMODE_TB2;  /* Set operation mode */
        
    /* Configure source address */  
    DMA_DESC_CH5[2].u32Src = (uint32_t)NUCODEGEN_PDMA_CH5_SRC_ADDR_TB2;
    
    /* Configure destination address */
    DMA_DESC_CH5[2].u32Dest = (uint32_t)NUCODEGEN_PDMA_CH5_DES_ADDR_TB2;
	#if(NUCODEGEN_PDMA_CH5_OPMODE_TB2_S==NUCODEGEN_PDMA_OP_BASIC)
    /* Configure next descriptor table address */
    DMA_DESC_CH5[2].u32Offset = 0; /* No next operation table. No effect in basic mode */		
    #else		
    /* Configure next descriptor table address */
    DMA_DESC_CH5[2].u32Offset = (uint32_t)&DMA_DESC_CH5[3] - (PDMA->SCATBA); /* next descriptor table is table 3 */ 
    #endif         
    #endif
    #if(NUCODEGEN_PDMA_CH5_OPMODE_TB2_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_CH5[3].u32Ctl =
        (((uint32_t)PDMA_CH5_DATA_LENGTH_TB3 - 1) << PDMA_DSCT_CTL_TXCNT_Pos) | /* Set transfer count */ \
        NUCODEGEN_PDMA_CH5_WIDTH_TB3 |   /* Set transfer width */ \
        NUCODEGEN_PDMA_CH5_SRC_TYPE_TB3 |    /* Set source increment type */ \
        NUCODEGEN_PDMA_CH5_DES_TYPE_TB3 |    /* Set destination increment type */ \
        NUCODEGEN_PDMA_CH5_MODE_TB3 |  /* Set transfer type */ \
        NUCODEGEN_PDMA_CH5_BURST_SIZE_TB3 |  /* Set burst size */ \
        NUCODEGEN_PDMA_CH5_TB3_INT_EN |   /* Set table empty interrupt */ \
        NUCODEGEN_PDMA_CH5_OPMODE_TB3;  /* Set operation mode */
        
    /* Configure source address */  
    DMA_DESC_CH5[3].u32Src = (uint32_t)NUCODEGEN_PDMA_CH5_SRC_ADDR_TB3;
    
    /* Configure destination address */
    DMA_DESC_CH5[3].u32Dest = (uint32_t)NUCODEGEN_PDMA_CH5_DES_ADDR_TB3;
	
	#if(NUCODEGEN_PDMA_CH5_OPMODE_TB3_S==NUCODEGEN_PDMA_OP_BASIC)
    /* Configure next descriptor table address */
    DMA_DESC_CH5[3].u32Offset = 0; /* No next operation table. No effect in basic mode */		
    #else		
    /* Configure next descriptor table address */
    DMA_DESC_CH5[3].u32Offset = (uint32_t)&DMA_DESC_CH5[4] - (PDMA->SCATBA); /* next descriptor table is table 4 */ 
    #endif        
    #endif  
    #if(NUCODEGEN_PDMA_CH5_OPMODE_TB3_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_CH5[4].u32Ctl =
        (((uint32_t)PDMA_CH5_DATA_LENGTH_TB4 - 1) << PDMA_DSCT_CTL_TXCNT_Pos) | /* Set transfer count */ \
        NUCODEGEN_PDMA_CH5_WIDTH_TB4 |   /* Set transfer width */ \
        NUCODEGEN_PDMA_CH5_SRC_TYPE_TB4 |    /* Set source increment type */ \
        NUCODEGEN_PDMA_CH5_DES_TYPE_TB4 |    /* Set destination increment type */ \
        NUCODEGEN_PDMA_CH5_MODE_TB4 |  /* Set transfer type */ \
        NUCODEGEN_PDMA_CH5_BURST_SIZE_TB4 |  /* Set burst size */ \
        NUCODEGEN_PDMA_CH5_TB4_INT_EN |   /* Set table empty interrupt */ \
        NUCODEGEN_PDMA_CH5_OPMODE_TB4;  /* Set operation mode */
        
    /* Configure source address */  
    DMA_DESC_CH5[4].u32Src = (uint32_t)NUCODEGEN_PDMA_CH5_SRC_ADDR_TB4;
    
    /* Configure destination address */
    DMA_DESC_CH5[4].u32Dest = (uint32_t)NUCODEGEN_PDMA_CH5_DES_ADDR_TB4;
    
    /* Configure next descriptor table address */
    DMA_DESC_CH5[4].u32Offset = (uint32_t)&DMA_DESC_CH5[5] - (PDMA->SCATBA); /* next descriptor table is table 5 */     
    #endif  

    #if(NUCODEGEN_PDMA_CH5_TMOUT)
    /* Enable timeout function and set timeout counter */
    PDMA_SetTimeOut(PDMA, 5, NUCODEGEN_PDMA_CH5_TMOUT, NUCODEGEN_PDMA_CH5_TMOUT_CNT);  
    #endif
    
    #if(NUCODEGEN_PDMA_CH5_STRIDE_EN)
    /* Set stride function */
    PDMA_SetStride(PDMA, 5, NUCODEGEN_PDMA_CH5_STRIDE_DES_LENGTH, NUCODEGEN_PDMA_CH5_STRIDE_SRC_LENGTH, NUCODEGEN_PDMA_CH5_STRIDE_CNT);
    #endif
    
    /* Request source is NUCODEGEN_PDMA_CH5_SRC_DES_SEL */
    PDMA_SetTransferMode(PDMA, 5, NUCODEGEN_PDMA_CH5_SRC_DES_SEL, 1, (uint32_t)&DMA_DESC_CH5[0]);   
#endif  //NUCODEGEN_PDMA_CH5_OPMODE == PDMA_OP_BASIC
#endif  //NUCODEGEN_PDMA_CH5_FUNC

#if (NUCODEGEN_PDMA_CH6)
#if (NUCODEGEN_PDMA_CH6_OPMODE_S == NUCODEGEN_PDMA_OP_BASIC)
    /* Open CH6 */
    PDMA_Open(PDMA, 1 << 6);
    
    /* Transfer count is PDMA_CH6_DATA_LENGTH, transfer width is NUCODEGEN_PDMA_CH6_WIDTH */
    PDMA_SetTransferCnt(PDMA, 6, NUCODEGEN_PDMA_CH6_WIDTH, PDMA_CH6_DATA_LENGTH);
    
    /* Set source address is NUCODEGEN_PDMA_CH6_SRC_ADDR, destination address is NUCODEGEN_PDMA_CH6_DES_ADDR */
    PDMA_SetTransferAddr(PDMA, 6, (uint32_t)NUCODEGEN_PDMA_CH6_SRC_ADDR, NUCODEGEN_PDMA_CH6_SRC_TYPE, (uint32_t)NUCODEGEN_PDMA_CH6_DES_ADDR, NUCODEGEN_PDMA_CH6_DES_TYPE);
    
    /* Set transfer mode and burst size */
    PDMA_SetBurstType(PDMA, 6, NUCODEGEN_PDMA_CH6_MODE, NUCODEGEN_PDMA_CH6_BURST_SIZE);
    
    #if(NUCODEGEN_PDMA_CH6_TMOUT)
    /* Enable timeout function and set timeout counter */
    PDMA_SetTimeOut(PDMA, 6, NUCODEGEN_PDMA_CH6_TMOUT, NUCODEGEN_PDMA_CH6_TMOUT_CNT);      
    #endif
    
    #if(NUCODEGEN_PDMA_CH6_STRIDE_EN)
    /* Set stride function */
    PDMA_SetStride(PDMA, 6, NUCODEGEN_PDMA_CH6_STRIDE_DES_LENGTH, NUCODEGEN_PDMA_CH6_STRIDE_SRC_LENGTH, NUCODEGEN_PDMA_CH6_STRIDE_CNT);
    #endif
    
    /* Request source is NUCODEGEN_PDMA_CH6_SRC_DES_SEL */
    PDMA_SetTransferMode(PDMA, 6, NUCODEGEN_PDMA_CH6_SRC_DES_SEL, 0, 0);
#else   //NUCODEGEN_PDMA_CH6_OPMODE_S == PDMA_OP_SCATTER
    /* Open CH6 */
    PDMA_Open(PDMA, 1 << 6);    
    
    DMA_DESC_CH6[0].u32Ctl =
        (((uint32_t)PDMA_CH6_DATA_LENGTH_TB0 - 1) << PDMA_DSCT_CTL_TXCNT_Pos) | /* Set transfer count */ \
        NUCODEGEN_PDMA_CH6_WIDTH_TB0 |   /* Set transfer width */ \
        NUCODEGEN_PDMA_CH6_SRC_TYPE_TB0 |    /* Set source increment type */ \
        NUCODEGEN_PDMA_CH6_DES_TYPE_TB0 |    /* Set destination increment type */ \
        NUCODEGEN_PDMA_CH6_MODE_TB0 |  /* Set transfer type */ \
        NUCODEGEN_PDMA_CH6_BURST_SIZE_TB0 |  /* Set burst size */ \
        NUCODEGEN_PDMA_CH6_TB0_INT_EN |   /* Set table empty interrupt */ \
        NUCODEGEN_PDMA_CH6_OPMODE_TB0;  /* Set operation mode */
        
    /* Configure source address */  
    DMA_DESC_CH6[0].u32Src = (uint32_t)NUCODEGEN_PDMA_CH6_SRC_ADDR_TB0;
    
    /* Configure destination address */
    DMA_DESC_CH6[0].u32Dest = (uint32_t)NUCODEGEN_PDMA_CH6_DES_ADDR_TB0;
    
	#if(NUCODEGEN_PDMA_CH6_OPMODE_TB0_S==NUCODEGEN_PDMA_OP_BASIC)
    /* Configure next descriptor table address */
    DMA_DESC_CH6[0].u32Offset = 0; /* No next operation table. No effect in basic mode */		
	#else
    /* Configure next descriptor table address */
    DMA_DESC_CH6[0].u32Offset = (uint32_t)&DMA_DESC_CH6[1] - (PDMA->SCATBA); /* next descriptor table is table 1 */		
	#endif
    #if(NUCODEGEN_PDMA_CH6_OPMODE_TB0_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_CH6[1].u32Ctl =
        (((uint32_t)PDMA_CH6_DATA_LENGTH_TB1 - 1) << PDMA_DSCT_CTL_TXCNT_Pos) | /* Set transfer count */ \
        NUCODEGEN_PDMA_CH6_WIDTH_TB1 |   /* Set transfer width */ \
        NUCODEGEN_PDMA_CH6_SRC_TYPE_TB1 |    /* Set source increment type */ \
        NUCODEGEN_PDMA_CH6_DES_TYPE_TB1 |    /* Set destination increment type */ \
        NUCODEGEN_PDMA_CH6_MODE_TB1 |  /* Set transfer type */ \
        NUCODEGEN_PDMA_CH6_BURST_SIZE_TB1 |  /* Set burst size */ \
        NUCODEGEN_PDMA_CH6_TB1_INT_EN |   /* Set table empty interrupt */ \
        NUCODEGEN_PDMA_CH6_OPMODE_TB1;  /* Set operation mode */
        
    /* Configure source address */  
    DMA_DESC_CH6[1].u32Src = (uint32_t)NUCODEGEN_PDMA_CH6_SRC_ADDR_TB1;
    
    /* Configure destination address */
    DMA_DESC_CH6[1].u32Dest = (uint32_t)NUCODEGEN_PDMA_CH6_DES_ADDR_TB1;
	#if(NUCODEGEN_PDMA_CH6_OPMODE_TB1_S==NUCODEGEN_PDMA_OP_BASIC)
    /* Configure next descriptor table address */
    DMA_DESC_CH6[1].u32Offset = 0; /* No next operation table. No effect in basic mode */		
	#else
    /* Configure next descriptor table address */
    DMA_DESC_CH6[1].u32Offset = (uint32_t)&DMA_DESC_CH6[2] - (PDMA->SCATBA); /* next descriptor table is table 2 */		
	#endif     
    #endif  
    #if(NUCODEGEN_PDMA_CH6_OPMODE_TB1_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_CH6[2].u32Ctl =
        (((uint32_t)PDMA_CH6_DATA_LENGTH_TB2 - 1) << PDMA_DSCT_CTL_TXCNT_Pos) | /* Set transfer count */ \
        NUCODEGEN_PDMA_CH6_WIDTH_TB2 |   /* Set transfer width */ \
        NUCODEGEN_PDMA_CH6_SRC_TYPE_TB2 |    /* Set source increment type */ \
        NUCODEGEN_PDMA_CH6_DES_TYPE_TB2 |    /* Set destination increment type */ \
        NUCODEGEN_PDMA_CH6_MODE_TB2 |  /* Set transfer type */ \
        NUCODEGEN_PDMA_CH6_BURST_SIZE_TB2 |  /* Set burst size */ \
        NUCODEGEN_PDMA_CH6_TB2_INT_EN |   /* Set table empty interrupt */ \
        NUCODEGEN_PDMA_CH6_OPMODE_TB2;  /* Set operation mode */
        
    /* Configure source address */  
    DMA_DESC_CH6[2].u32Src = (uint32_t)NUCODEGEN_PDMA_CH6_SRC_ADDR_TB2;
    
    /* Configure destination address */
    DMA_DESC_CH6[2].u32Dest = (uint32_t)NUCODEGEN_PDMA_CH6_DES_ADDR_TB2;
	#if(NUCODEGEN_PDMA_CH6_OPMODE_TB2_S==NUCODEGEN_PDMA_OP_BASIC)
    /* Configure next descriptor table address */
    DMA_DESC_CH6[2].u32Offset = 0; /* No next operation table. No effect in basic mode */		
	#else
    /* Configure next descriptor table address */
    DMA_DESC_CH6[2].u32Offset = (uint32_t)&DMA_DESC_CH6[3] - (PDMA->SCATBA); /* next descriptor table is table 3 */		
	#endif    
    #endif
    #if(NUCODEGEN_PDMA_CH6_OPMODE_TB2_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_CH6[3].u32Ctl =
        (((uint32_t)PDMA_CH6_DATA_LENGTH_TB3 - 1) << PDMA_DSCT_CTL_TXCNT_Pos) | /* Set transfer count */ \
        NUCODEGEN_PDMA_CH6_WIDTH_TB3 |   /* Set transfer width */ \
        NUCODEGEN_PDMA_CH6_SRC_TYPE_TB3 |    /* Set source increment type */ \
        NUCODEGEN_PDMA_CH6_DES_TYPE_TB3 |    /* Set destination increment type */ \
        NUCODEGEN_PDMA_CH6_MODE_TB3 |  /* Set transfer type */ \
        NUCODEGEN_PDMA_CH6_BURST_SIZE_TB3 |  /* Set burst size */ \
        NUCODEGEN_PDMA_CH6_TB3_INT_EN |   /* Set table empty interrupt */ \
        NUCODEGEN_PDMA_CH6_OPMODE_TB3;  /* Set operation mode */
        
    /* Configure source address */  
    DMA_DESC_CH6[3].u32Src = (uint32_t)NUCODEGEN_PDMA_CH6_SRC_ADDR_TB3;
    
    /* Configure destination address */
    DMA_DESC_CH6[3].u32Dest = (uint32_t)NUCODEGEN_PDMA_CH6_DES_ADDR_TB3;
	#if(NUCODEGEN_PDMA_CH6_OPMODE_TB3_S==NUCODEGEN_PDMA_OP_BASIC)
    /* Configure next descriptor table address */
    DMA_DESC_CH6[3].u32Offset = 0; /* No next operation table. No effect in basic mode */		
	#else
    /* Configure next descriptor table address */
    DMA_DESC_CH6[3].u32Offset = (uint32_t)&DMA_DESC_CH6[4] - (PDMA->SCATBA); /* next descriptor table is table 4 */		
	#endif    
    #endif  
    #if(NUCODEGEN_PDMA_CH6_OPMODE_TB3_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_CH6[4].u32Ctl =
        (((uint32_t)PDMA_CH6_DATA_LENGTH_TB4 - 1) << PDMA_DSCT_CTL_TXCNT_Pos) | /* Set transfer count */ \
        NUCODEGEN_PDMA_CH6_WIDTH_TB4 |   /* Set transfer width */ \
        NUCODEGEN_PDMA_CH6_SRC_TYPE_TB4 |    /* Set source increment type */ \
        NUCODEGEN_PDMA_CH6_DES_TYPE_TB4 |    /* Set destination increment type */ \
        NUCODEGEN_PDMA_CH6_MODE_TB4 |  /* Set transfer type */ \
        NUCODEGEN_PDMA_CH6_BURST_SIZE_TB4 |  /* Set burst size */ \
        NUCODEGEN_PDMA_CH6_TB4_INT_EN |   /* Set table empty interrupt */ \
        NUCODEGEN_PDMA_CH6_OPMODE_TB4;  /* Set operation mode */
        
    /* Configure source address */  
    DMA_DESC_CH6[4].u32Src = (uint32_t)NUCODEGEN_PDMA_CH6_SRC_ADDR_TB4;
    
    /* Configure destination address */
    DMA_DESC_CH6[4].u32Dest = (uint32_t)NUCODEGEN_PDMA_CH6_DES_ADDR_TB4;
    
    /* Configure next descriptor table address */
    DMA_DESC_CH6[4].u32Offset = (uint32_t)&DMA_DESC_CH6[5] - (PDMA->SCATBA); /* next descriptor table is table 5 */     
    #endif  

    #if(NUCODEGEN_PDMA_CH6_TMOUT)
    /* Enable timeout function and set timeout counter */
    PDMA_SetTimeOut(PDMA, 6, NUCODEGEN_PDMA_CH6_TMOUT, NUCODEGEN_PDMA_CH6_TMOUT_CNT);  
    #endif
    
    #if(NUCODEGEN_PDMA_CH6_STRIDE_EN)
    /* Set stride function */
    PDMA_SetStride(PDMA, 6, NUCODEGEN_PDMA_CH6_STRIDE_DES_LENGTH, NUCODEGEN_PDMA_CH6_STRIDE_SRC_LENGTH, NUCODEGEN_PDMA_CH6_STRIDE_CNT);
    #endif
    
    /* Request source is NUCODEGEN_PDMA_CH6_SRC_DES_SEL */
    PDMA_SetTransferMode(PDMA, 6, NUCODEGEN_PDMA_CH6_SRC_DES_SEL, 1, (uint32_t)&DMA_DESC_CH6[0]);   
#endif  //NUCODEGEN_PDMA_CH6_OPMODE == PDMA_OP_BASIC
#endif  //NUCODEGEN_PDMA_CH6_FUNC

#if (NUCODEGEN_PDMA_CH7)
#if (NUCODEGEN_PDMA_CH7_OPMODE_S == NUCODEGEN_PDMA_OP_BASIC)
    /* Open CH7 */
    PDMA_Open(PDMA, 1 << 7);
    
    /* Transfer count is PDMA_CH7_DATA_LENGTH, transfer width is NUCODEGEN_PDMA_CH7_WIDTH */
    PDMA_SetTransferCnt(PDMA, 7, NUCODEGEN_PDMA_CH7_WIDTH, PDMA_CH7_DATA_LENGTH);
    
    /* Set source address is NUCODEGEN_PDMA_CH7_SRC_ADDR, destination address is NUCODEGEN_PDMA_CH7_DES_ADDR */
    PDMA_SetTransferAddr(PDMA, 7, (uint32_t)NUCODEGEN_PDMA_CH7_SRC_ADDR, NUCODEGEN_PDMA_CH7_SRC_TYPE, (uint32_t)NUCODEGEN_PDMA_CH7_DES_ADDR, NUCODEGEN_PDMA_CH7_DES_TYPE);
    
    /* Set transfer mode and burst size */
    PDMA_SetBurstType(PDMA, 7, NUCODEGEN_PDMA_CH7_MODE, NUCODEGEN_PDMA_CH7_BURST_SIZE);
    
    #if(NUCODEGEN_PDMA_CH7_TMOUT)
    /* Enable timeout function and set timeout counter */
    PDMA_SetTimeOut(PDMA, 7, NUCODEGEN_PDMA_CH7_TMOUT, NUCODEGEN_PDMA_CH7_TMOUT_CNT);      
    #endif
    
    #if(NUCODEGEN_PDMA_CH7_STRIDE_EN)
    /* Set stride function */
    PDMA_SetStride(PDMA, 7, NUCODEGEN_PDMA_CH7_STRIDE_DES_LENGTH, NUCODEGEN_PDMA_CH7_STRIDE_SRC_LENGTH, NUCODEGEN_PDMA_CH7_STRIDE_CNT);
    #endif
    
    /* Request source is NUCODEGEN_PDMA_CH7_SRC_DES_SEL */
    PDMA_SetTransferMode(PDMA, 7, NUCODEGEN_PDMA_CH7_SRC_DES_SEL, 0, 0);
#else   //NUCODEGEN_PDMA_CH7_OPMODE_S == PDMA_OP_SCATTER
    /* Open CH7 */
    PDMA_Open(PDMA, 1 << 7);    
    
    DMA_DESC_CH7[0].u32Ctl =
        (((uint32_t)PDMA_CH7_DATA_LENGTH_TB0 - 1) << PDMA_DSCT_CTL_TXCNT_Pos) | /* Set transfer count */ \
        NUCODEGEN_PDMA_CH7_WIDTH_TB0 |   /* Set transfer width */ \
        NUCODEGEN_PDMA_CH7_SRC_TYPE_TB0 |    /* Set source increment type */ \
        NUCODEGEN_PDMA_CH7_DES_TYPE_TB0 |    /* Set destination increment type */ \
        NUCODEGEN_PDMA_CH7_MODE_TB0 |  /* Set transfer type */ \
        NUCODEGEN_PDMA_CH7_BURST_SIZE_TB0 |  /* Set burst size */ \
        NUCODEGEN_PDMA_CH7_TB0_INT_EN |   /* Set table empty interrupt */ \
        NUCODEGEN_PDMA_CH7_OPMODE_TB0;  /* Set operation mode */
        
    /* Configure source address */  
    DMA_DESC_CH7[0].u32Src = (uint32_t)NUCODEGEN_PDMA_CH7_SRC_ADDR_TB0;
    
    /* Configure destination address */
    DMA_DESC_CH7[0].u32Dest = (uint32_t)NUCODEGEN_PDMA_CH7_DES_ADDR_TB0;
	
	#if(NUCODEGEN_PDMA_CH7_OPMODE_TB0_S==NUCODEGEN_PDMA_OP_BASIC)   
    /* Configure next descriptor table address */
    DMA_DESC_CH7[0].u32Offset = 0; /* No next operation table. No effect in basic mode */		
	#else		
    /* Configure next descriptor table address */
    DMA_DESC_CH7[0].u32Offset = (uint32_t)&DMA_DESC_CH7[1] - (PDMA->SCATBA); /* next descriptor table is table 1 */ 
    #endif
    #if(NUCODEGEN_PDMA_CH7_OPMODE_TB0_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_CH7[1].u32Ctl =
        (((uint32_t)PDMA_CH7_DATA_LENGTH_TB1 - 1) << PDMA_DSCT_CTL_TXCNT_Pos) | /* Set transfer count */ \
        NUCODEGEN_PDMA_CH7_WIDTH_TB1 |   /* Set transfer width */ \
        NUCODEGEN_PDMA_CH7_SRC_TYPE_TB1 |    /* Set source increment type */ \
        NUCODEGEN_PDMA_CH7_DES_TYPE_TB1 |    /* Set destination increment type */ \
        NUCODEGEN_PDMA_CH7_MODE_TB1 |  /* Set transfer type */ \
        NUCODEGEN_PDMA_CH7_BURST_SIZE_TB1 |  /* Set burst size */ \
        NUCODEGEN_PDMA_CH7_TB1_INT_EN |   /* Set table empty interrupt */ \
        NUCODEGEN_PDMA_CH7_OPMODE_TB1;  /* Set operation mode */
        
    /* Configure source address */  
    DMA_DESC_CH7[1].u32Src = (uint32_t)NUCODEGEN_PDMA_CH7_SRC_ADDR_TB1;
    
    /* Configure destination address */
    DMA_DESC_CH7[1].u32Dest = (uint32_t)NUCODEGEN_PDMA_CH7_DES_ADDR_TB1;

	#if(NUCODEGEN_PDMA_CH7_OPMODE_TB1_S==NUCODEGEN_PDMA_OP_BASIC)   
    /* Configure next descriptor table address */
    DMA_DESC_CH7[1].u32Offset = 0; /* No next operation table. No effect in basic mode */		
	#else		
    /* Configure next descriptor table address */
    DMA_DESC_CH7[1].u32Offset = (uint32_t)&DMA_DESC_CH7[2] - (PDMA->SCATBA); /* next descriptor table is table 2 */ 
    #endif   
    #endif  
    #if(NUCODEGEN_PDMA_CH7_OPMODE_TB1_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_CH7[2].u32Ctl =
        (((uint32_t)PDMA_CH7_DATA_LENGTH_TB2 - 1) << PDMA_DSCT_CTL_TXCNT_Pos) | /* Set transfer count */ \
        NUCODEGEN_PDMA_CH7_WIDTH_TB2 |   /* Set transfer width */ \
        NUCODEGEN_PDMA_CH7_SRC_TYPE_TB2 |    /* Set source increment type */ \
        NUCODEGEN_PDMA_CH7_DES_TYPE_TB2 |    /* Set destination increment type */ \
        NUCODEGEN_PDMA_CH7_MODE_TB2 |  /* Set transfer type */ \
        NUCODEGEN_PDMA_CH7_BURST_SIZE_TB2 |  /* Set burst size */ \
        NUCODEGEN_PDMA_CH7_TB2_INT_EN |   /* Set table empty interrupt */ \
        NUCODEGEN_PDMA_CH7_OPMODE_TB2;  /* Set operation mode */
        
    /* Configure source address */  
    DMA_DESC_CH7[2].u32Src = (uint32_t)NUCODEGEN_PDMA_CH7_SRC_ADDR_TB2;
    
    /* Configure destination address */
    DMA_DESC_CH7[2].u32Dest = (uint32_t)NUCODEGEN_PDMA_CH7_DES_ADDR_TB2;
	#if(NUCODEGEN_PDMA_CH7_OPMODE_TB2_S==NUCODEGEN_PDMA_OP_BASIC)   
    /* Configure next descriptor table address */
    DMA_DESC_CH7[2].u32Offset = 0; /* No next operation table. No effect in basic mode */		
	#else		
    /* Configure next descriptor table address */
    DMA_DESC_CH7[2].u32Offset = (uint32_t)&DMA_DESC_CH7[3] - (PDMA->SCATBA); /* next descriptor table is table 3 */ 
    #endif        
    #endif
    #if(NUCODEGEN_PDMA_CH7_OPMODE_TB2_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_CH7[3].u32Ctl =
        (((uint32_t)PDMA_CH7_DATA_LENGTH_TB3 - 1) << PDMA_DSCT_CTL_TXCNT_Pos) | /* Set transfer count */ \
        NUCODEGEN_PDMA_CH7_WIDTH_TB3 |   /* Set transfer width */ \
        NUCODEGEN_PDMA_CH7_SRC_TYPE_TB3 |    /* Set source increment type */ \
        NUCODEGEN_PDMA_CH7_DES_TYPE_TB3 |    /* Set destination increment type */ \
        NUCODEGEN_PDMA_CH7_MODE_TB3 |  /* Set transfer type */ \
        NUCODEGEN_PDMA_CH7_BURST_SIZE_TB3 |  /* Set burst size */ \
        NUCODEGEN_PDMA_CH7_TB3_INT_EN |   /* Set table empty interrupt */ \
        NUCODEGEN_PDMA_CH7_OPMODE_TB3;  /* Set operation mode */
        
    /* Configure source address */  
    DMA_DESC_CH7[3].u32Src = (uint32_t)NUCODEGEN_PDMA_CH7_SRC_ADDR_TB3;
    
    /* Configure destination address */
    DMA_DESC_CH7[3].u32Dest = (uint32_t)NUCODEGEN_PDMA_CH7_DES_ADDR_TB3;
	#if(NUCODEGEN_PDMA_CH7_OPMODE_TB3_S==NUCODEGEN_PDMA_OP_BASIC)   
    /* Configure next descriptor table address */
    DMA_DESC_CH7[3].u32Offset = 0; /* No next operation table. No effect in basic mode */		
	#else		
    /* Configure next descriptor table address */
    DMA_DESC_CH7[3].u32Offset = (uint32_t)&DMA_DESC_CH7[4] - (PDMA->SCATBA); /* next descriptor table is table 4 */ 
    #endif	    
    #endif  
    #if(NUCODEGEN_PDMA_CH7_OPMODE_TB3_S==NUCODEGEN_PDMA_OP_SCATTER)
    DMA_DESC_CH7[4].u32Ctl =
        (((uint32_t)PDMA_CH7_DATA_LENGTH_TB4 - 1) << PDMA_DSCT_CTL_TXCNT_Pos) | /* Set transfer count */ \
        NUCODEGEN_PDMA_CH7_WIDTH_TB4 |   /* Set transfer width */ \
        NUCODEGEN_PDMA_CH7_SRC_TYPE_TB4 |    /* Set source increment type */ \
        NUCODEGEN_PDMA_CH7_DES_TYPE_TB4 |    /* Set destination increment type */ \
        NUCODEGEN_PDMA_CH7_MODE_TB4 |  /* Set transfer type */ \
        NUCODEGEN_PDMA_CH7_BURST_SIZE_TB4 |  /* Set burst size */ \
        NUCODEGEN_PDMA_CH7_TB4_INT_EN |   /* Set table empty interrupt */ \
        NUCODEGEN_PDMA_CH7_OPMODE_TB4;  /* Set operation mode */
        
    /* Configure source address */  
    DMA_DESC_CH7[4].u32Src = (uint32_t)NUCODEGEN_PDMA_CH7_SRC_ADDR_TB4;
    
    /* Configure destination address */
    DMA_DESC_CH7[4].u32Dest = (uint32_t)NUCODEGEN_PDMA_CH7_DES_ADDR_TB4;
    
    /* Configure next descriptor table address */
    DMA_DESC_CH7[4].u32Offset = (uint32_t)&DMA_DESC_CH7[5] - (PDMA->SCATBA); /* next descriptor table is table 5 */     
    #endif  

    #if(NUCODEGEN_PDMA_CH7_TMOUT)
    /* Enable timeout function and set timeout counter */
    PDMA_SetTimeOut(PDMA, 7, NUCODEGEN_PDMA_CH7_TMOUT, NUCODEGEN_PDMA_CH7_TMOUT_CNT);  
    #endif
    
    #if(NUCODEGEN_PDMA_CH7_STRIDE_EN)
    /* Set stride function */
    PDMA_SetStride(PDMA, 7, NUCODEGEN_PDMA_CH7_STRIDE_DES_LENGTH, NUCODEGEN_PDMA_CH7_STRIDE_SRC_LENGTH, NUCODEGEN_PDMA_CH7_STRIDE_CNT);
    #endif
    
    /* Request source is NUCODEGEN_PDMA_CH7_SRC_DES_SEL */
    PDMA_SetTransferMode(PDMA, 7, NUCODEGEN_PDMA_CH7_SRC_DES_SEL, 1, (uint32_t)&DMA_DESC_CH7[0]);   
#endif  //NUCODEGEN_PDMA_CH7_OPMODE == PDMA_OP_BASIC
#endif  //NUCODEGEN_PDMA_CH7_FUNC

#if NUCODEGEN_PDMA_CH0_INT
    #if NUCODEGEN_PDMA_CH0_INT_TXDONE
    PDMA_EnableInt(PDMA, 0, PDMA_INT_TRANS_DONE);
    #endif
    #if NUCODEGEN_PDMA_CH0_INT_TIMEOUT
    PDMA_EnableInt(PDMA, 0, PDMA_INT_TIMEOUT);
    #endif  
#endif
#if NUCODEGEN_PDMA_CH1_INT
    #if NUCODEGEN_PDMA_CH1_INT_TXDONE
    PDMA_EnableInt(PDMA, 1, PDMA_INT_TRANS_DONE);
    #endif 
    #if NUCODEGEN_PDMA_CH1_INT_TIMEOUT
    PDMA_EnableInt(PDMA, 1, PDMA_INT_TIMEOUT);
    #endif
#endif
#if NUCODEGEN_PDMA_CH2_INT
    #if NUCODEGEN_PDMA_CH2_INT_TXDONE
    PDMA_EnableInt(PDMA, 2, PDMA_INT_TRANS_DONE);
    #endif 
    #if NUCODEGEN_PDMA_CH2_INT_TIMEOUT
    PDMA_EnableInt(PDMA, 2, PDMA_INT_TIMEOUT);
    #endif
#endif
#if NUCODEGEN_PDMA_CH3_INT
    #if NUCODEGEN_PDMA_CH3_INT_TXDONE
    PDMA_EnableInt(PDMA, 3, PDMA_INT_TRANS_DONE);
    #endif 
    #if NUCODEGEN_PDMA_CH3_INT_TIMEOUT
    PDMA_EnableInt(PDMA, 3, PDMA_INT_TIMEOUT);
    #endif
#endif
#if NUCODEGEN_PDMA_CH4_INT
    #if NUCODEGEN_PDMA_CH4_INT_TXDONE
    PDMA_EnableInt(PDMA, 4, PDMA_INT_TRANS_DONE);
    #endif
    #if NUCODEGEN_PDMA_CH4_INT_TIMEOUT
    PDMA_EnableInt(PDMA, 4, PDMA_INT_TIMEOUT);
    #endif
#endif
#if NUCODEGEN_PDMA_CH5_INT
    #if NUCODEGEN_PDMA_CH5_INT_TXDONE
    PDMA_EnableInt(PDMA, 5, PDMA_INT_TRANS_DONE);
    #endif
    #if NUCODEGEN_PDMA_CH5_INT_TIMEOUT
    PDMA_EnableInt(PDMA, 5, PDMA_INT_TIMEOUT);
    #endif
#endif
#if NUCODEGEN_PDMA_CH6_INT
    #if NUCODEGEN_PDMA_CH6_INT_TXDONE
    PDMA_EnableInt(PDMA, 6, PDMA_INT_TRANS_DONE);
    #endif  
    #if NUCODEGEN_PDMA_CH6_INT_TIMEOUT
    PDMA_EnableInt(PDMA, 6, PDMA_INT_TIMEOUT);
    #endif
#endif
#if NUCODEGEN_PDMA_CH7_INT
    #if NUCODEGEN_PDMA_CH7_INT_TXDONE
    PDMA_EnableInt(PDMA, 7, PDMA_INT_TRANS_DONE);
    #endif 
    #if NUCODEGEN_PDMA_CH7_INT_TIMEOUT
    PDMA_EnableInt(PDMA, 7, PDMA_INT_TIMEOUT);
    #endif
#endif


#if (NUCODEGEN_PDMA_CH0_INT || NUCODEGEN_PDMA_CH1_INT || NUCODEGEN_PDMA_CH2_INT || NUCODEGEN_PDMA_CH3_INT || NUCODEGEN_PDMA_CH4_INT || NUCODEGEN_PDMA_CH5_INT \
    || NUCODEGEN_PDMA_CH6_INT || NUCODEGEN_PDMA_CH7_INT )
    NVIC_EnableIRQ(PDMA_IRQn);
#endif
}
#endif
