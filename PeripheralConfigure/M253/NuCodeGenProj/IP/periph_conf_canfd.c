
#if NUCODEGEN_CANFD0
void CANFD0_Init()
{
    CANFD_FD_T sCANFD_Config;
#if(NUCODEGEN_CANFD0_FUNCSEL_SEL == NUCODEGEN_CANFD_FUNCSEL_CANFD)
    /*Get the CANFD configuration value*/
    CANFD_GetDefaultConfig(&sCANFD_Config, CANFD_OP_CAN_FD_MODE);
    sCANFD_Config.sBtConfig.sNormBitRate.u32BitRate = NUCODEGEN_CANFD0_NOMINAL_BITRATE;
    sCANFD_Config.sBtConfig.sDataBitRate.u32BitRate = NUCODEGEN_CANFD0_DATA_BITRATE;
    /*Open the CAN FD feature*/
#else
    /*Get the CAN FD configuration value*/
    CANFD_GetDefaultConfig(&sCANFD_Config, CANFD_OP_CAN_MODE);
    sCANFD_Config.sBtConfig.sNormBitRate.u32BitRate = NUCODEGEN_CANFD0_NOMINAL_BITRATE;
    sCANFD_Config.sBtConfig.sDataBitRate.u32BitRate = 0;
    /*Open the CAN feature*/
#endif

    CANFD_Open(CANFD0, &sCANFD_Config);
#if NUCODEGEN_CANFD0_RXBUF_ID_FILTER_ELEMS_EN
#if(NUCODEGEN_CANFD0_RXBUF_ID_FILTER_ELEMS_SIZE > 0)
#if (NUCODEGEN_CANFD0_RXBUF_ID1_FILTER_TYPE_SEL == NUCODEGEN_ID_FILTER_STD)
    /* receive NUCODEGEN_CANFD0_RXBUF_ID1_STD_FILTER_NUM (Standard ID) in CAN FD0 rx message buffer 0 */
    CANFD_SetSIDFltr(CANFD0, 0, CANFD_RX_BUFFER_STD(NUCODEGEN_CANFD0_RXBUF_ID1_STD_FILTER_NUM, 0));
#else
    /* receive NUCODEGEN_CANFD0_RXBUF_ID1_EXT_FILTER_NUM(Extended ID) in CAN FD0 rx message buffer 0 */
    CANFD_SetXIDFltr(CANFD0, 0, CANFD_RX_BUFFER_EXT_LOW(NUCODEGEN_CANFD0_RXBUF_ID1_EXT_FILTER_NUM, 0),CANFD_RX_BUFFER_EXT_HIGH(NUCODEGEN_CANFD0_RXBUF_ID1_EXT_FILTER_NUM,0));
#endif//NUCODEGEN_CANFD0_RXBUF_ID1_FILTER_TYPE_SEL
#endif//NUCODEGEN_CANFD0_RXBUF_ID_FILTER_ELEMS_SIZE

#if (NUCODEGEN_CANFD0_RXBUF_ID_FILTER_ELEMS_SIZE > 1)
#if (NUCODEGEN_CANFD0_RXBUF_ID2_FILTER_TYPE_SEL == NUCODEGEN_ID_FILTER_STD)
    /* receive NUCODEGEN_CANFD0_RXBUF_ID2_STD_FILTER_NUM (Standard ID) in CAN FD0 rx message buffer 1*/
    CANFD_SetSIDFltr(CANFD0, 1, CANFD_RX_BUFFER_STD(NUCODEGEN_CANFD0_RXBUF_ID2_STD_FILTER_NUM, 1));
#else
    /* receive NUCODEGEN_CANFD0_RXBUF_ID2_EXT_FILTER_NUM(Extended ID) in CAN FD0 rx message buffer 1*/
    CANFD_SetXIDFltr(CANFD0, 1, CANFD_RX_BUFFER_EXT_LOW(NUCODEGEN_CANFD0_RXBUF_ID2_EXT_FILTER_NUM, 1),CANFD_RX_BUFFER_EXT_HIGH(NUCODEGEN_CANFD0_RXBUF_ID2_EXT_FILTER_NUM,1));
#endif//NUCODEGEN_CANFD0_RXBUF_ID2_FILTER_TYPE_SEL
#endif//NUCODEGEN_CANFD0_RXBUF_ID_FILTER_ELEMS_SIZE

#if (NUCODEGEN_CANFD0_RXBUF_ID_FILTER_ELEMS_SIZE > 2)
#if (NUCODEGEN_CANFD0_RXBUF_ID3_FILTER_TYPE_SEL == NUCODEGEN_ID_FILTER_STD)
    /* receive NUCODEGEN_CANFD0_RXBUF_ID3_STD_FILTER_NUM(Standard ID) in CAN FD0 rx message buffer 2*/
    CANFD_SetSIDFltr(CANFD0, 2, CANFD_RX_BUFFER_STD(NUCODEGEN_CANFD0_RXBUF_ID3_STD_FILTER_NUM, 2));
#else
    /* receive NUCODEGEN_CANFD0_RXBUF_ID3_EXT_FILTER_NUM(Extended ID) in CAN FD0 rx message buffer 2*/
    CANFD_SetXIDFltr(CANFD0, 2, CANFD_RX_BUFFER_EXT_LOW(NUCODEGEN_CANFD0_RXBUF_ID3_EXT_FILTER_NUM, 2),CANFD_RX_BUFFER_EXT_HIGH(NUCODEGEN_CANFD0_RXBUF_ID3_EXT_FILTER_NUM,2));
#endif//NUCODEGEN_CANFD0_RXBUF_ID3_FILTER_TYPE_SEL
#endif//NUCODEGEN_CANFD0_RXBUF_ID_FILTER_ELEMS_SIZE
#endif//NUCODEGEN_CANFD0_RXBUF_ID_FILTER_ELEMS_EN

#if NUCODEGEN_CANFD0_FIFO0_ID_FILTER_ELEMS_EN
#if(NUCODEGEN_CANFD0_FIFO0_ID_FILTER_ELEMS_SIZE > 0)
#if (NUCODEGEN_CANFD0_FIFO0_ID1_FILTER_TYPE_SEL == NUCODEGEN_ID_FILTER_STD)
    /* receive NUCODEGEN_CANFD0_FIFO0_ID1_STD_FILTER_NUM(Standard ID) in CAN FD0 rx fifo0 buffer by setting mask 0 */
    CANFD_SetSIDFltr(CANFD0, 3, CANFD_RX_FIFO0_STD_MASK(NUCODEGEN_CANFD0_FIFO0_ID1_STD_FILTER_NUM, NUCODEGEN_CANFD0_FIFO0_ID1_STD_FILTER_MSAK));
#else
    /* receive NUCODEGEN_CANFD0_FIFO0_ID1_EXT_FILTER_NUM (Extended ID)in CAN FD0 rx fifo0 buffer by setting mask 0 */
    CANFD_SetXIDFltr(CANFD0, 3, CANFD_RX_FIFO0_EXT_MASK_LOW(NUCODEGEN_CANFD0_FIFO0_ID1_EXT_FILTER_NUM),CANFD_RX_FIFO0_EXT_MASK_HIGH(NUCODEGEN_CANFD0_FIFO0_ID1_EXT_FILTER_MSAK));
#endif//NUCODEGEN_CANFD0_FIFO0_ID1_FILTER_TYPE_SEL
#endif//NUCODEGEN_CANFD0_FIFO0_ID_FILTER_ELEMS_SIZE

#if (NUCODEGEN_CANFD0_FIFO0_ID_FILTER_ELEMS_SIZE > 1)
#if (NUCODEGEN_CANFD0_FIFO0_ID2_FILTER_TYPE_SEL == NUCODEGEN_ID_FILTER_STD)
    /* receive NUCODEGEN_CANFD0_FIFO0_ID2_STD_FILTER_NUM(Standard ID) in CAN FD0 rx fifo0 buffer by setting mask 1 */
    CANFD_SetSIDFltr(CANFD0, 4, CANFD_RX_FIFO0_STD_MASK(NUCODEGEN_CANFD0_FIFO0_ID2_STD_FILTER_NUM, NUCODEGEN_CANFD0_FIFO0_ID2_STD_FILTER_MSAK));
#else
    /* receive NUCODEGEN_CANFD0_FIFO0_ID2_EXT_FILTER_NUM (Extended ID)in CAN FD0 rx fifo0 buffer by setting mask 1 */
    CANFD_SetXIDFltr(CANFD0, 4, CANFD_RX_FIFO0_EXT_MASK_LOW(NUCODEGEN_CANFD0_FIFO0_ID2_EXT_FILTER_NUM),CANFD_RX_FIFO0_EXT_MASK_HIGH(NUCODEGEN_CANFD0_FIFO0_ID2_EXT_FILTER_MSAK));
#endif//NUCODEGEN_CANFD0_FIFO0_ID2_FILTER_TYPE_SEL
#endif//NUCODEGEN_CANFD0_FIFO0_ID_FILTER_ELEMS_SIZE

#if (NUCODEGEN_CANFD0_FIFO0_ID_FILTER_ELEMS_SIZE > 2)
#if (NUCODEGEN_CANFD0_FIFO0_ID3_FILTER_TYPE_SEL == NUCODEGEN_ID_FILTER_STD)
    /* receive NUCODEGEN_CANFD0_FIFO0_ID3_STD_FILTER_NUM(Standard ID) in CAN FD0 rx fifo0 buffer by setting mask 1 */
    CANFD_SetSIDFltr(CANFD0, 5, CANFD_RX_FIFO0_STD_MASK(NUCODEGEN_CANFD0_FIFO0_ID3_STD_FILTER_NUM, NUCODEGEN_CANFD0_FIFO0_ID3_STD_FILTER_MSAK));
#else
    /* receive NUCODEGEN_CANFD0_FIFO0_ID3_EXT_FILTER_NUM (Extended ID)in CAN FD0 rx fifo0 buffer by setting mask 1 */
    CANFD_SetXIDFltr(CANFD0, 5, CANFD_RX_FIFO0_EXT_MASK_LOW(NUCODEGEN_CANFD0_FIFO0_ID3_EXT_FILTER_NUM),CANFD_RX_FIFO0_EXT_MASK_HIGH(NUCODEGEN_CANFD0_FIFO0_ID3_EXT_FILTER_MSAK));
#endif//NUCODEGEN_CANFD0_FIFO0_ID3_FILTER_TYPE_SEL
#endif//NUCODEGEN_CANFD0_FIFO0_ID_FILTER_ELEMS_SIZE
#endif//NUCODEGEN_CANFD0_FIFO0_ID_FILTER_ELEMS_EN


#if NUCODEGEN_CANFD0_FIFO1_ID_FILTER_ELEMS_EN
#if(NUCODEGEN_CANFD0_FIFO1_ID_FILTER_ELEMS_SIZE > 0)
#if (NUCODEGEN_CANFD0_FIFO1_ID1_FILTER_TYPE_SEL == NUCODEGEN_ID_FILTER_STD)
    /* receive NUCODEGEN_CANFD0_FIFO1_ID1_STD_FILTER_NUM(Standard ID) in CAN FD0 rx fifo0 buffer by setting mask 0 */
    CANFD_SetSIDFltr(CANFD0, 6, CANFD_RX_FIFO1_STD_MASK(NUCODEGEN_CANFD0_FIFO1_ID1_STD_FILTER_NUM, NUCODEGEN_CANFD0_FIFO1_ID1_STD_FILTER_MSAK));
#else
    /* receive NUCODEGEN_CANFD0_FIFO1_ID1_EXT_FILTER_NUM (Extended ID)in CAN FD0 rx fifo0 buffer by setting mask 0 */
    CANFD_SetXIDFltr(CANFD0, 6, CANFD_RX_FIFO1_EXT_MASK_LOW(NUCODEGEN_CANFD0_FIFO1_ID1_EXT_FILTER_NUM),CANFD_RX_FIFO1_EXT_MASK_HIGH(NUCODEGEN_CANFD0_FIFO1_ID1_EXT_FILTER_MSAK));
#endif//NUCODEGEN_CANFD0_FIFO1_ID1_FILTER_TYPE_SEL
#endif//NUCODEGEN_CANFD0_FIFO1_ID_FILTER_ELEMS_SIZE

#if (NUCODEGEN_CANFD0_FIFO1_ID_FILTER_ELEMS_SIZE > 1)
#if (NUCODEGEN_CANFD0_FIFO1_ID2_FILTER_TYPE_SEL == NUCODEGEN_ID_FILTER_STD)
    /* receive NUCODEGEN_CANFD0_FIFO1_ID2_STD_FILTER_NUM(Standard ID) in CAN FD0 rx fifo0 buffer by setting mask 1 */
    CANFD_SetSIDFltr(CANFD0, 7, CANFD_RX_FIFO1_STD_MASK(NUCODEGEN_CANFD0_FIFO1_ID2_STD_FILTER_NUM, NUCODEGEN_CANFD0_FIFO1_ID2_STD_FILTER_MSAK));
#else
    /* receive NUCODEGEN_CANFD0_FIFO1_ID2_EXT_FILTER_NUM (Extended ID)in CAN FD0 rx fifo0 buffer by setting mask 1 */
    CANFD_SetXIDFltr(CANFD0, 7, CANFD_RX_FIFO1_EXT_MASK_LOW(NUCODEGEN_CANFD0_FIFO1_ID2_EXT_FILTER_NUM),CANFD_RX_FIFO1_EXT_MASK_HIGH(NUCODEGEN_CANFD0_FIFO1_ID2_EXT_FILTER_MSAK));
#endif//NUCODEGEN_CANFD0_FIFO1_ID2_FILTER_TYPE_SEL
#endif//NUCODEGEN_CANFD0_FIFO1_ID_FILTER_ELEMS_SIZE

#if (NUCODEGEN_CANFD0_FIFO1_ID_FILTER_ELEMS_SIZE > 2)
#if (NUCODEGEN_CANFD0_FIFO1_ID3_FILTER_TYPE_SEL == NUCODEGEN_ID_FILTER_STD)
    /* receive NUCODEGEN_CANFD0_FIFO1_ID3_STD_FILTER_NUM(Standard ID) in CAN FD0 rx fifo0 buffer by setting mask 1 */
    CANFD_SetSIDFltr(CANFD0, 8, CANFD_RX_FIFO1_STD_MASK(NUCODEGEN_CANFD0_FIFO1_ID3_STD_FILTER_NUM, NUCODEGEN_CANFD0_FIFO1_ID3_STD_FILTER_MSAK));
#else
    /* receive NUCODEGEN_CANFD0_FIFO1_ID3_EXT_FILTER_NUM (Extended ID)in CAN FD0 rx fifo0 buffer by setting mask 1 */
    CANFD_SetXIDFltr(CANFD0, 8, CANFD_RX_FIFO1_EXT_MASK_LOW(NUCODEGEN_CANFD0_FIFO1_ID3_EXT_FILTER_NUM),CANFD_RX_FIFO1_EXT_MASK_HIGH(NUCODEGEN_CANFD0_FIFO1_ID3_EXT_FILTER_MSAK));
#endif//NUCODEGEN_CANFD0_FIFO1_ID3_FILTER_TYPE_SEL
#endif//NUCODEGEN_CANFD0_FIFO1_ID_FILTER_ELEMS_SIZE
#endif//NUCODEGEN_CANFD0_FIFO1_ID_FILTER_ELEMS_EN

#if NUCODEGEN_CANFD0_GLOBAL_FILTER_EN
    /* CANFD0 Global Filter Configuration*/
    CANFD_SetGFC(CANFD0, NUCODEGEN_CANFD0_GLOBAL_FILTER_ANFS_SEL, NUCODEGEN_CANFD0_GLOBAL_FILTER_ANFE_SEL, NUCODEGEN_CANFD0_GLOBAL_FILTER_RRFS_SEL, NUCODEGEN_CANFD0_GLOBAL_FILTER_RRFE_SEL);
#endif
#if(NUCODEGEN_CANFD0_INT_EN || NUCODEGEN_CANFD0_RXBUF_INT_EN || NUCODEGEN_CANFD0_FIFO0_INT_EN || NUCODEGEN_CANFD0_FIFO1_INT_EN)
    /* Enable RX fifo0 new message interrupt using interrupt line 0. */
    CANFD_EnableInt(CANFD0, (NUCODEGEN_CANFD0_INT_CONFIG_MASK), 0, 0, 0);
#endif
    /* CAN FD0 Run to Normal mode  */
    CANFD_RunToNormal(CANFD0, TRUE);
}

#endif//NUCODEGEN_CANFD0
