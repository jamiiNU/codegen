
#if (NUCODEGEN_PSIO)
/*************************************/
/**              PSIO               **/
/*************************************/
void PSIO_Init(){
#if (NUCODEGEN_PSIO_SLOTCTL0_EN)
    /* Initialize PSIO slot control setting */
    PSIO_SET_SCCTL(PSIO, PSIO_SC0, NUCODEGEN_PSIO_SLOTCTL0_INIT_SLOT, NUCODEGEN_PSIO_SLOTCTL0_END_SLOT, NUCODEGEN_PSIO_SLOTCTL0_LOOP_CNT, NUCODEGEN_PSIO_SLOTCTL0_REPEAT);

    /* Set slot count */
    PSIO_SCSLOT_SET_SLOT(PSIO, PSIO_SC0, PSIO_SLOT0, NUCODEGEN_PSIO_SLOTCTL0_SLOT0_COUNT);
    PSIO_SCSLOT_SET_SLOT(PSIO, PSIO_SC0, PSIO_SLOT1, NUCODEGEN_PSIO_SLOTCTL0_SLOT1_COUNT);
    PSIO_SCSLOT_SET_SLOT(PSIO, PSIO_SC0, PSIO_SLOT2, NUCODEGEN_PSIO_SLOTCTL0_SLOT2_COUNT);
    PSIO_SCSLOT_SET_SLOT(PSIO, PSIO_SC0, PSIO_SLOT3, NUCODEGEN_PSIO_SLOTCTL0_SLOT3_COUNT);
    PSIO_SCSLOT_SET_SLOT(PSIO, PSIO_SC0, PSIO_SLOT4, NUCODEGEN_PSIO_SLOTCTL0_SLOT4_COUNT);
    PSIO_SCSLOT_SET_SLOT(PSIO, PSIO_SC0, PSIO_SLOT5, NUCODEGEN_PSIO_SLOTCTL0_SLOT5_COUNT);
    PSIO_SCSLOT_SET_SLOT(PSIO, PSIO_SC0, PSIO_SLOT6, NUCODEGEN_PSIO_SLOTCTL0_SLOT6_COUNT);
    PSIO_SCSLOT_SET_SLOT(PSIO, PSIO_SC0, PSIO_SLOT7, NUCODEGEN_PSIO_SLOTCTL0_SLOT7_COUNT);

    /* Set slot controller trigger source */
    PSIO_SET_TRIGSRC(PSIO, PSIO_SC0, NUCODEGEN_PSIO_SLOTCTL0_TRIGGER_TYPE);
#endif  //NUCODEGEN_PSIO_SLOTCTL0_EN

#if (NUCODEGEN_PSIO_SLOTCTL1_EN)
    /* Initialize PSIO slot control setting */
    PSIO_SET_SCCTL(PSIO, PSIO_SC1, NUCODEGEN_PSIO_SLOTCTL1_INIT_SLOT, NUCODEGEN_PSIO_SLOTCTL1_END_SLOT, NUCODEGEN_PSIO_SLOTCTL1_LOOP_CNT, NUCODEGEN_PSIO_SLOTCTL1_REPEAT);

    /* Set slot count */
    PSIO_SCSLOT_SET_SLOT(PSIO, PSIO_SC1, PSIO_SLOT0, NUCODEGEN_PSIO_SLOTCTL1_SLOT0_COUNT);
    PSIO_SCSLOT_SET_SLOT(PSIO, PSIO_SC1, PSIO_SLOT1, NUCODEGEN_PSIO_SLOTCTL1_SLOT1_COUNT);
    PSIO_SCSLOT_SET_SLOT(PSIO, PSIO_SC1, PSIO_SLOT2, NUCODEGEN_PSIO_SLOTCTL1_SLOT2_COUNT);
    PSIO_SCSLOT_SET_SLOT(PSIO, PSIO_SC1, PSIO_SLOT3, NUCODEGEN_PSIO_SLOTCTL1_SLOT3_COUNT);
    PSIO_SCSLOT_SET_SLOT(PSIO, PSIO_SC1, PSIO_SLOT4, NUCODEGEN_PSIO_SLOTCTL1_SLOT4_COUNT);
    PSIO_SCSLOT_SET_SLOT(PSIO, PSIO_SC1, PSIO_SLOT5, NUCODEGEN_PSIO_SLOTCTL1_SLOT5_COUNT);
    PSIO_SCSLOT_SET_SLOT(PSIO, PSIO_SC1, PSIO_SLOT6, NUCODEGEN_PSIO_SLOTCTL1_SLOT6_COUNT);
    PSIO_SCSLOT_SET_SLOT(PSIO, PSIO_SC1, PSIO_SLOT7, NUCODEGEN_PSIO_SLOTCTL1_SLOT7_COUNT);

    /* Set slot controller trigger source */
    PSIO_SET_TRIGSRC(PSIO, PSIO_SC1, NUCODEGEN_PSIO_SLOTCTL1_TRIGGER_TYPE);
#endif  //NUCODEGEN_PSIO_SLOTCTL1_EN

#if (NUCODEGEN_PSIO_SLOTCTL2_EN)
    /* Initialize PSIO slot control setting */
    PSIO_SET_SCCTL(PSIO, PSIO_SC2, NUCODEGEN_PSIO_SLOTCTL2_INIT_SLOT, NUCODEGEN_PSIO_SLOTCTL2_END_SLOT, NUCODEGEN_PSIO_SLOTCTL2_LOOP_CNT, NUCODEGEN_PSIO_SLOTCTL2_REPEAT);

    /* Set slot count */
    PSIO_SCSLOT_SET_SLOT(PSIO, PSIO_SC2, PSIO_SLOT0, NUCODEGEN_PSIO_SLOTCTL2_SLOT0_COUNT);
    PSIO_SCSLOT_SET_SLOT(PSIO, PSIO_SC2, PSIO_SLOT1, NUCODEGEN_PSIO_SLOTCTL2_SLOT1_COUNT);
    PSIO_SCSLOT_SET_SLOT(PSIO, PSIO_SC2, PSIO_SLOT2, NUCODEGEN_PSIO_SLOTCTL2_SLOT2_COUNT);
    PSIO_SCSLOT_SET_SLOT(PSIO, PSIO_SC2, PSIO_SLOT3, NUCODEGEN_PSIO_SLOTCTL2_SLOT3_COUNT);
    PSIO_SCSLOT_SET_SLOT(PSIO, PSIO_SC2, PSIO_SLOT4, NUCODEGEN_PSIO_SLOTCTL2_SLOT4_COUNT);
    PSIO_SCSLOT_SET_SLOT(PSIO, PSIO_SC2, PSIO_SLOT5, NUCODEGEN_PSIO_SLOTCTL2_SLOT5_COUNT);
    PSIO_SCSLOT_SET_SLOT(PSIO, PSIO_SC2, PSIO_SLOT6, NUCODEGEN_PSIO_SLOTCTL2_SLOT6_COUNT);
    PSIO_SCSLOT_SET_SLOT(PSIO, PSIO_SC2, PSIO_SLOT7, NUCODEGEN_PSIO_SLOTCTL2_SLOT7_COUNT);

    /* Set slot controller trigger source */
    PSIO_SET_TRIGSRC(PSIO, PSIO_SC2, NUCODEGEN_PSIO_SLOTCTL2_TRIGGER_TYPE);
#endif  //NUCODEGEN_PSIO_SLOTCTL2_EN

#if (NUCODEGEN_PSIO_SLOTCTL3_EN)
    /* Initialize PSIO slot control setting */
    PSIO_SET_SCCTL(PSIO, PSIO_SC3, NUCODEGEN_PSIO_SLOTCTL3_INIT_SLOT, NUCODEGEN_PSIO_SLOTCTL3_END_SLOT, NUCODEGEN_PSIO_SLOTCTL3_LOOP_CNT, NUCODEGEN_PSIO_SLOTCTL3_REPEAT);

    /* Set slot count */
    PSIO_SCSLOT_SET_SLOT(PSIO, PSIO_SC3, PSIO_SLOT0, NUCODEGEN_PSIO_SLOTCTL3_SLOT0_COUNT);
    PSIO_SCSLOT_SET_SLOT(PSIO, PSIO_SC3, PSIO_SLOT1, NUCODEGEN_PSIO_SLOTCTL3_SLOT1_COUNT);
    PSIO_SCSLOT_SET_SLOT(PSIO, PSIO_SC3, PSIO_SLOT2, NUCODEGEN_PSIO_SLOTCTL3_SLOT2_COUNT);
    PSIO_SCSLOT_SET_SLOT(PSIO, PSIO_SC3, PSIO_SLOT3, NUCODEGEN_PSIO_SLOTCTL3_SLOT3_COUNT);
    PSIO_SCSLOT_SET_SLOT(PSIO, PSIO_SC3, PSIO_SLOT4, NUCODEGEN_PSIO_SLOTCTL3_SLOT4_COUNT);
    PSIO_SCSLOT_SET_SLOT(PSIO, PSIO_SC3, PSIO_SLOT5, NUCODEGEN_PSIO_SLOTCTL3_SLOT5_COUNT);
    PSIO_SCSLOT_SET_SLOT(PSIO, PSIO_SC3, PSIO_SLOT6, NUCODEGEN_PSIO_SLOTCTL3_SLOT6_COUNT);
    PSIO_SCSLOT_SET_SLOT(PSIO, PSIO_SC3, PSIO_SLOT7, NUCODEGEN_PSIO_SLOTCTL3_SLOT7_COUNT);

    /* Set slot controller trigger source */
    PSIO_SET_TRIGSRC(PSIO, PSIO_SC3, NUCODEGEN_PSIO_SLOTCTL3_TRIGGER_TYPE);
#endif  //NUCODEGEN_PSIO_SLOTCTL3_EN

#if (NUCODEGEN_PSIO_PIN0_EN)
    /* Link check point to slot */
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN0, PSIO_CP0, NUCODEGEN_PSIO_PIN0_CP0_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN0, PSIO_CP1, NUCODEGEN_PSIO_PIN0_CP1_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN0, PSIO_CP2, NUCODEGEN_PSIO_PIN0_CP2_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN0, PSIO_CP3, NUCODEGEN_PSIO_PIN0_CP3_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN0, PSIO_CP4, NUCODEGEN_PSIO_PIN0_CP4_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN0, PSIO_CP5, NUCODEGEN_PSIO_PIN0_CP5_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN0, PSIO_CP6, NUCODEGEN_PSIO_PIN0_CP6_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN0, PSIO_CP7, NUCODEGEN_PSIO_PIN0_CP7_SLT);

    /* Set check point action */
    PSIO_SET_ACTION(PSIO, PSIO_PIN0, PSIO_CP0, NUCODEGEN_PSIO_PIN0_CP0_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN0, PSIO_CP1, NUCODEGEN_PSIO_PIN0_CP1_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN0, PSIO_CP2, NUCODEGEN_PSIO_PIN0_CP2_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN0, PSIO_CP3, NUCODEGEN_PSIO_PIN0_CP3_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN0, PSIO_CP4, NUCODEGEN_PSIO_PIN0_CP4_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN0, PSIO_CP5, NUCODEGEN_PSIO_PIN0_CP5_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN0, PSIO_CP6, NUCODEGEN_PSIO_PIN0_CP6_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN0, PSIO_CP7, NUCODEGEN_PSIO_PIN0_CP7_ACT);

    /* Set pin general control */
    PSIO_SET_GENCTL(PSIO, PSIO_PIN0, PSIO_PIN_ENABLE, NUCODEGEN_PSIO_PIN0_SLOT_CNT, NUCODEGEN_PSIO_PIN0_IOMODE, NUCODEGEN_PSIO_PIN0_INIT_STATE, NUCODEGEN_PSIO_PIN0_INTERVAL_STATE);

    /* Set pin order */
    PSIO_SET_ORDER(PSIO, PSIO_PIN0, NUCODEGEN_PSIO_PIN0_DATA_ORDER);

    /* Set data width */
    PSIO_SET_WIDTH(PSIO, PSIO_PIN0, NUCODEGEN_PSIO_PIN0_DATA_RX_WIDTH, NUCODEGEN_PSIO_PIN0_DATA_TX_WIDTH);

    /* Set data depth */
    PSIO_SET_OUTPUT_DEPTH(PSIO, PSIO_PIN0, NUCODEGEN_PSIO_PIN0_DATA_TX_DEPTH);
    PSIO_SET_INPUT_DEPTH(PSIO, PSIO_PIN0, NUCODEGEN_PSIO_PIN0_DATA_RX_DEPTH);
    
    #if(NUCODEGEN_PSIO_PIN0_SWITCH_POINT0_EN)
    /* Set switch point 0 */
    PSIO_SWITCH_MODE(PSIO, PSIO_PIN0, PSIO_SWITCH_P0, NUCODEGEN_PSIO_PIN0_MODE_SWITCH0, NUCODEGEN_PSIO_PIN0_SWITCH_POINT0);
    #endif
    #if(NUCODEGEN_PSIO_PIN0_SWITCH_POINT1_EN)
    /* Set switch point 1 */
    PSIO_SWITCH_MODE(PSIO, PSIO_PIN0, PSIO_SWITCH_P1, NUCODEGEN_PSIO_PIN0_MODE_SWITCH1, NUCODEGEN_PSIO_PIN0_SWITCH_POINT1);
    #endif  
#endif  //NUCODEGEN_PSIO_PIN0_EN

#if (NUCODEGEN_PSIO_PIN1_EN)
    /* Link check point to slot */
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN1, PSIO_CP0, NUCODEGEN_PSIO_PIN1_CP0_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN1, PSIO_CP1, NUCODEGEN_PSIO_PIN1_CP1_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN1, PSIO_CP2, NUCODEGEN_PSIO_PIN1_CP2_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN1, PSIO_CP3, NUCODEGEN_PSIO_PIN1_CP3_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN1, PSIO_CP4, NUCODEGEN_PSIO_PIN1_CP4_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN1, PSIO_CP5, NUCODEGEN_PSIO_PIN1_CP5_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN1, PSIO_CP6, NUCODEGEN_PSIO_PIN1_CP6_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN1, PSIO_CP7, NUCODEGEN_PSIO_PIN1_CP7_SLT);

    /* Set check point action */
    PSIO_SET_ACTION(PSIO, PSIO_PIN1, PSIO_CP0, NUCODEGEN_PSIO_PIN1_CP0_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN1, PSIO_CP1, NUCODEGEN_PSIO_PIN1_CP1_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN1, PSIO_CP2, NUCODEGEN_PSIO_PIN1_CP2_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN1, PSIO_CP3, NUCODEGEN_PSIO_PIN1_CP3_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN1, PSIO_CP4, NUCODEGEN_PSIO_PIN1_CP4_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN1, PSIO_CP5, NUCODEGEN_PSIO_PIN1_CP5_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN1, PSIO_CP6, NUCODEGEN_PSIO_PIN1_CP6_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN1, PSIO_CP7, NUCODEGEN_PSIO_PIN1_CP7_ACT);

    /* Set pin general control */
    PSIO_SET_GENCTL(PSIO, PSIO_PIN1, PSIO_PIN_ENABLE, NUCODEGEN_PSIO_PIN1_SLOT_CNT, NUCODEGEN_PSIO_PIN1_IOMODE, NUCODEGEN_PSIO_PIN1_INIT_STATE, NUCODEGEN_PSIO_PIN1_INTERVAL_STATE);

    /* Set pin order */
    PSIO_SET_ORDER(PSIO, PSIO_PIN1, NUCODEGEN_PSIO_PIN1_DATA_ORDER);

    /* Set data width */
    PSIO_SET_WIDTH(PSIO, PSIO_PIN1, NUCODEGEN_PSIO_PIN1_DATA_RX_WIDTH, NUCODEGEN_PSIO_PIN1_DATA_TX_WIDTH);

    /* Set data depth */
    PSIO_SET_OUTPUT_DEPTH(PSIO, PSIO_PIN1, NUCODEGEN_PSIO_PIN1_DATA_TX_DEPTH);
    PSIO_SET_INPUT_DEPTH(PSIO, PSIO_PIN1, NUCODEGEN_PSIO_PIN1_DATA_RX_DEPTH);

    #if(NUCODEGEN_PSIO_PIN1_SWITCH_POINT0_EN)
    /* Set switch point 0 */
    PSIO_SWITCH_MODE(PSIO, PSIO_PIN1, PSIO_SWITCH_P0, NUCODEGEN_PSIO_PIN1_MODE_SWITCH0, NUCODEGEN_PSIO_PIN1_SWITCH_POINT0);
    #endif
    #if(NUCODEGEN_PSIO_PIN1_SWITCH_POINT1_EN)
    /* Set switch point 1 */
    PSIO_SWITCH_MODE(PSIO, PSIO_PIN1, PSIO_SWITCH_P1, NUCODEGEN_PSIO_PIN1_MODE_SWITCH1, NUCODEGEN_PSIO_PIN1_SWITCH_POINT1);
    #endif  
#endif  //NUCODEGEN_PSIO_PIN1_EN

#if (NUCODEGEN_PSIO_PIN2_EN)
    /* Link check point to slot */
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN2, PSIO_CP0, NUCODEGEN_PSIO_PIN2_CP0_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN2, PSIO_CP1, NUCODEGEN_PSIO_PIN2_CP1_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN2, PSIO_CP2, NUCODEGEN_PSIO_PIN2_CP2_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN2, PSIO_CP3, NUCODEGEN_PSIO_PIN2_CP3_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN2, PSIO_CP4, NUCODEGEN_PSIO_PIN2_CP4_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN2, PSIO_CP5, NUCODEGEN_PSIO_PIN2_CP5_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN2, PSIO_CP6, NUCODEGEN_PSIO_PIN2_CP6_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN2, PSIO_CP7, NUCODEGEN_PSIO_PIN2_CP7_SLT);

    /* Set check point action */
    PSIO_SET_ACTION(PSIO, PSIO_PIN2, PSIO_CP0, NUCODEGEN_PSIO_PIN2_CP0_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN2, PSIO_CP1, NUCODEGEN_PSIO_PIN2_CP1_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN2, PSIO_CP2, NUCODEGEN_PSIO_PIN2_CP2_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN2, PSIO_CP3, NUCODEGEN_PSIO_PIN2_CP3_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN2, PSIO_CP4, NUCODEGEN_PSIO_PIN2_CP4_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN2, PSIO_CP5, NUCODEGEN_PSIO_PIN2_CP5_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN2, PSIO_CP6, NUCODEGEN_PSIO_PIN2_CP6_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN2, PSIO_CP7, NUCODEGEN_PSIO_PIN2_CP7_ACT);

    /* Set pin general control */
    PSIO_SET_GENCTL(PSIO, PSIO_PIN2, PSIO_PIN_ENABLE, NUCODEGEN_PSIO_PIN2_SLOT_CNT, NUCODEGEN_PSIO_PIN2_IOMODE, NUCODEGEN_PSIO_PIN2_INIT_STATE, NUCODEGEN_PSIO_PIN2_INTERVAL_STATE);

    /* Set pin order */
    PSIO_SET_ORDER(PSIO, PSIO_PIN2, NUCODEGEN_PSIO_PIN2_DATA_ORDER);

    /* Set data width */
    PSIO_SET_WIDTH(PSIO, PSIO_PIN2, NUCODEGEN_PSIO_PIN2_DATA_RX_WIDTH, NUCODEGEN_PSIO_PIN2_DATA_TX_WIDTH);

    /* Set data depth */
    PSIO_SET_OUTPUT_DEPTH(PSIO, PSIO_PIN2, NUCODEGEN_PSIO_PIN2_DATA_TX_DEPTH);
    PSIO_SET_INPUT_DEPTH(PSIO, PSIO_PIN2, NUCODEGEN_PSIO_PIN2_DATA_RX_DEPTH);

    #if(NUCODEGEN_PSIO_PIN2_SWITCH_POINT0_EN)
    /* Set switch point 0 */
    PSIO_SWITCH_MODE(PSIO, PSIO_PIN2, PSIO_SWITCH_P0, NUCODEGEN_PSIO_PIN2_MODE_SWITCH0, NUCODEGEN_PSIO_PIN2_SWITCH_POINT0);
    #endif
    #if(NUCODEGEN_PSIO_PIN2_SWITCH_POINT1_EN)
    /* Set switch point 1 */
    PSIO_SWITCH_MODE(PSIO, PSIO_PIN2, PSIO_SWITCH_P1, NUCODEGEN_PSIO_PIN2_MODE_SWITCH1, NUCODEGEN_PSIO_PIN2_SWITCH_POINT1);
    #endif  
#endif  //NUCODEGEN_PSIO_PIN2_EN

#if (NUCODEGEN_PSIO_PIN3_EN)
    /* Link check point to slot */
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN3, PSIO_CP0, NUCODEGEN_PSIO_PIN3_CP0_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN3, PSIO_CP1, NUCODEGEN_PSIO_PIN3_CP1_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN3, PSIO_CP2, NUCODEGEN_PSIO_PIN3_CP2_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN3, PSIO_CP3, NUCODEGEN_PSIO_PIN3_CP3_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN3, PSIO_CP4, NUCODEGEN_PSIO_PIN3_CP4_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN3, PSIO_CP5, NUCODEGEN_PSIO_PIN3_CP5_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN3, PSIO_CP6, NUCODEGEN_PSIO_PIN3_CP6_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN3, PSIO_CP7, NUCODEGEN_PSIO_PIN3_CP7_SLT);

    /* Set check point action */
    PSIO_SET_ACTION(PSIO, PSIO_PIN3, PSIO_CP0, NUCODEGEN_PSIO_PIN3_CP0_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN3, PSIO_CP1, NUCODEGEN_PSIO_PIN3_CP1_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN3, PSIO_CP2, NUCODEGEN_PSIO_PIN3_CP2_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN3, PSIO_CP3, NUCODEGEN_PSIO_PIN3_CP3_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN3, PSIO_CP4, NUCODEGEN_PSIO_PIN3_CP4_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN3, PSIO_CP5, NUCODEGEN_PSIO_PIN3_CP5_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN3, PSIO_CP6, NUCODEGEN_PSIO_PIN3_CP6_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN3, PSIO_CP7, NUCODEGEN_PSIO_PIN3_CP7_ACT);

    /* Set pin general control */
    PSIO_SET_GENCTL(PSIO, PSIO_PIN3, PSIO_PIN_ENABLE, NUCODEGEN_PSIO_PIN3_SLOT_CNT, NUCODEGEN_PSIO_PIN3_IOMODE, NUCODEGEN_PSIO_PIN3_INIT_STATE, NUCODEGEN_PSIO_PIN3_INTERVAL_STATE);

    /* Set pin order */
    PSIO_SET_ORDER(PSIO, PSIO_PIN3, NUCODEGEN_PSIO_PIN3_DATA_ORDER);

    /* Set data width */
    PSIO_SET_WIDTH(PSIO, PSIO_PIN3, NUCODEGEN_PSIO_PIN3_DATA_RX_WIDTH, NUCODEGEN_PSIO_PIN3_DATA_TX_WIDTH);

    /* Set data depth */
    PSIO_SET_OUTPUT_DEPTH(PSIO, PSIO_PIN3, NUCODEGEN_PSIO_PIN3_DATA_TX_DEPTH);
    PSIO_SET_INPUT_DEPTH(PSIO, PSIO_PIN3, NUCODEGEN_PSIO_PIN3_DATA_RX_DEPTH);
    
    #if(NUCODEGEN_PSIO_PIN3_SWITCH_POINT0_EN)
    /* Set switch point 0 */
    PSIO_SWITCH_MODE(PSIO, PSIO_PIN3, PSIO_SWITCH_P0, NUCODEGEN_PSIO_PIN3_MODE_SWITCH0, NUCODEGEN_PSIO_PIN3_SWITCH_POINT0);
    #endif
    #if(NUCODEGEN_PSIO_PIN3_SWITCH_POINT1_EN)
    /* Set switch point 1 */
    PSIO_SWITCH_MODE(PSIO, PSIO_PIN3, PSIO_SWITCH_P1, NUCODEGEN_PSIO_PIN3_MODE_SWITCH1, NUCODEGEN_PSIO_PIN3_SWITCH_POINT1);
    #endif  
#endif  //NUCODEGEN_PSIO_PIN3_EN

#if (NUCODEGEN_PSIO_PIN4_EN)
    /* Link check point to slot */
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN4, PSIO_CP0, NUCODEGEN_PSIO_PIN4_CP0_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN4, PSIO_CP1, NUCODEGEN_PSIO_PIN4_CP1_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN4, PSIO_CP2, NUCODEGEN_PSIO_PIN4_CP2_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN4, PSIO_CP3, NUCODEGEN_PSIO_PIN4_CP3_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN4, PSIO_CP4, NUCODEGEN_PSIO_PIN4_CP4_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN4, PSIO_CP5, NUCODEGEN_PSIO_PIN4_CP5_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN4, PSIO_CP6, NUCODEGEN_PSIO_PIN4_CP6_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN4, PSIO_CP7, NUCODEGEN_PSIO_PIN4_CP7_SLT);

    /* Set check point action */
    PSIO_SET_ACTION(PSIO, PSIO_PIN4, PSIO_CP0, NUCODEGEN_PSIO_PIN4_CP0_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN4, PSIO_CP1, NUCODEGEN_PSIO_PIN4_CP1_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN4, PSIO_CP2, NUCODEGEN_PSIO_PIN4_CP2_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN4, PSIO_CP3, NUCODEGEN_PSIO_PIN4_CP3_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN4, PSIO_CP4, NUCODEGEN_PSIO_PIN4_CP4_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN4, PSIO_CP5, NUCODEGEN_PSIO_PIN4_CP5_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN4, PSIO_CP6, NUCODEGEN_PSIO_PIN4_CP6_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN4, PSIO_CP7, NUCODEGEN_PSIO_PIN4_CP7_ACT);

    /* Set pin general control */
    PSIO_SET_GENCTL(PSIO, PSIO_PIN4, PSIO_PIN_ENABLE, NUCODEGEN_PSIO_PIN4_SLOT_CNT, NUCODEGEN_PSIO_PIN4_IOMODE, NUCODEGEN_PSIO_PIN4_INIT_STATE, NUCODEGEN_PSIO_PIN4_INTERVAL_STATE);

    /* Set pin order */
    PSIO_SET_ORDER(PSIO, PSIO_PIN4, NUCODEGEN_PSIO_PIN4_DATA_ORDER);

    /* Set data width */
    PSIO_SET_WIDTH(PSIO, PSIO_PIN4, NUCODEGEN_PSIO_PIN4_DATA_RX_WIDTH, NUCODEGEN_PSIO_PIN4_DATA_TX_WIDTH);

    /* Set data depth */
    PSIO_SET_OUTPUT_DEPTH(PSIO, PSIO_PIN4, NUCODEGEN_PSIO_PIN4_DATA_TX_DEPTH);
    PSIO_SET_INPUT_DEPTH(PSIO, PSIO_PIN4, NUCODEGEN_PSIO_PIN4_DATA_RX_DEPTH);
    
    #if(NUCODEGEN_PSIO_PIN4_SWITCH_POINT0_EN)
    /* Set switch point 0 */
    PSIO_SWITCH_MODE(PSIO, PSIO_PIN4, PSIO_SWITCH_P0, NUCODEGEN_PSIO_PIN4_MODE_SWITCH0, NUCODEGEN_PSIO_PIN4_SWITCH_POINT0);
    #endif
    #if(NUCODEGEN_PSIO_PIN4_SWITCH_POINT1_EN)
    /* Set switch point 1 */
    PSIO_SWITCH_MODE(PSIO, PSIO_PIN4, PSIO_SWITCH_P1, NUCODEGEN_PSIO_PIN4_MODE_SWITCH1, NUCODEGEN_PSIO_PIN4_SWITCH_POINT1);
    #endif  
#endif  //NUCODEGEN_PSIO_PIN4_EN

#if (NUCODEGEN_PSIO_PIN5_EN)
    /* Link check point to slot */
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN5, PSIO_CP0, NUCODEGEN_PSIO_PIN5_CP0_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN5, PSIO_CP1, NUCODEGEN_PSIO_PIN5_CP1_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN5, PSIO_CP2, NUCODEGEN_PSIO_PIN5_CP2_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN5, PSIO_CP3, NUCODEGEN_PSIO_PIN5_CP3_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN5, PSIO_CP4, NUCODEGEN_PSIO_PIN5_CP4_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN5, PSIO_CP5, NUCODEGEN_PSIO_PIN5_CP5_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN5, PSIO_CP6, NUCODEGEN_PSIO_PIN5_CP6_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN5, PSIO_CP7, NUCODEGEN_PSIO_PIN5_CP7_SLT);

    /* Set check point action */
    PSIO_SET_ACTION(PSIO, PSIO_PIN5, PSIO_CP0, NUCODEGEN_PSIO_PIN5_CP0_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN5, PSIO_CP1, NUCODEGEN_PSIO_PIN5_CP1_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN5, PSIO_CP2, NUCODEGEN_PSIO_PIN5_CP2_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN5, PSIO_CP3, NUCODEGEN_PSIO_PIN5_CP3_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN5, PSIO_CP4, NUCODEGEN_PSIO_PIN5_CP4_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN5, PSIO_CP5, NUCODEGEN_PSIO_PIN5_CP5_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN5, PSIO_CP6, NUCODEGEN_PSIO_PIN5_CP6_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN5, PSIO_CP7, NUCODEGEN_PSIO_PIN5_CP7_ACT);

    /* Set pin general control */
    PSIO_SET_GENCTL(PSIO, PSIO_PIN5, PSIO_PIN_ENABLE, NUCODEGEN_PSIO_PIN5_SLOT_CNT, NUCODEGEN_PSIO_PIN5_IOMODE, NUCODEGEN_PSIO_PIN5_INIT_STATE, NUCODEGEN_PSIO_PIN5_INTERVAL_STATE);

    /* Set pin order */
    PSIO_SET_ORDER(PSIO, PSIO_PIN5, NUCODEGEN_PSIO_PIN5_DATA_ORDER);

    /* Set data width */
    PSIO_SET_WIDTH(PSIO, PSIO_PIN5, NUCODEGEN_PSIO_PIN5_DATA_RX_WIDTH, NUCODEGEN_PSIO_PIN5_DATA_TX_WIDTH);

    /* Set data depth */
    PSIO_SET_OUTPUT_DEPTH(PSIO, PSIO_PIN5, NUCODEGEN_PSIO_PIN5_DATA_TX_DEPTH);
    PSIO_SET_INPUT_DEPTH(PSIO, PSIO_PIN5, NUCODEGEN_PSIO_PIN5_DATA_RX_DEPTH);
    
    #if(NUCODEGEN_PSIO_PIN5_SWITCH_POINT0_EN)
    /* Set switch point 0 */
    PSIO_SWITCH_MODE(PSIO, PSIO_PIN5, PSIO_SWITCH_P0, NUCODEGEN_PSIO_PIN5_MODE_SWITCH0, NUCODEGEN_PSIO_PIN5_SWITCH_POINT0);
    #endif
    #if(NUCODEGEN_PSIO_PIN5_SWITCH_POINT1_EN)
    /* Set switch point 1 */
    PSIO_SWITCH_MODE(PSIO, PSIO_PIN5, PSIO_SWITCH_P1, NUCODEGEN_PSIO_PIN5_MODE_SWITCH1, NUCODEGEN_PSIO_PIN5_SWITCH_POINT1);
    #endif  
#endif  //NUCODEGEN_PSIO_PIN5_EN

#if (NUCODEGEN_PSIO_PIN6_EN)
    /* Link check point to slot */
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN6, PSIO_CP0, NUCODEGEN_PSIO_PIN6_CP0_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN6, PSIO_CP1, NUCODEGEN_PSIO_PIN6_CP1_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN6, PSIO_CP2, NUCODEGEN_PSIO_PIN6_CP2_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN6, PSIO_CP3, NUCODEGEN_PSIO_PIN6_CP3_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN6, PSIO_CP4, NUCODEGEN_PSIO_PIN6_CP4_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN6, PSIO_CP5, NUCODEGEN_PSIO_PIN6_CP5_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN6, PSIO_CP6, NUCODEGEN_PSIO_PIN6_CP6_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN6, PSIO_CP7, NUCODEGEN_PSIO_PIN6_CP7_SLT);

    /* Set check point action */
    PSIO_SET_ACTION(PSIO, PSIO_PIN6, PSIO_CP0, NUCODEGEN_PSIO_PIN6_CP0_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN6, PSIO_CP1, NUCODEGEN_PSIO_PIN6_CP1_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN6, PSIO_CP2, NUCODEGEN_PSIO_PIN6_CP2_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN6, PSIO_CP3, NUCODEGEN_PSIO_PIN6_CP3_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN6, PSIO_CP4, NUCODEGEN_PSIO_PIN6_CP4_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN6, PSIO_CP5, NUCODEGEN_PSIO_PIN6_CP5_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN6, PSIO_CP6, NUCODEGEN_PSIO_PIN6_CP6_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN6, PSIO_CP7, NUCODEGEN_PSIO_PIN6_CP7_ACT);

    /* Set pin general control */
    PSIO_SET_GENCTL(PSIO, PSIO_PIN6, PSIO_PIN_ENABLE, NUCODEGEN_PSIO_PIN6_SLOT_CNT, NUCODEGEN_PSIO_PIN6_IOMODE, NUCODEGEN_PSIO_PIN6_INIT_STATE, NUCODEGEN_PSIO_PIN6_INTERVAL_STATE);

    /* Set pin order */
    PSIO_SET_ORDER(PSIO, PSIO_PIN6, NUCODEGEN_PSIO_PIN6_DATA_ORDER);

    /* Set data width */
    PSIO_SET_WIDTH(PSIO, PSIO_PIN6, NUCODEGEN_PSIO_PIN6_DATA_RX_WIDTH, NUCODEGEN_PSIO_PIN6_DATA_TX_WIDTH);

    /* Set data depth */
    PSIO_SET_OUTPUT_DEPTH(PSIO, PSIO_PIN6, NUCODEGEN_PSIO_PIN6_DATA_TX_DEPTH);
    PSIO_SET_INPUT_DEPTH(PSIO, PSIO_PIN6, NUCODEGEN_PSIO_PIN6_DATA_RX_DEPTH);
    
    #if(NUCODEGEN_PSIO_PIN6_SWITCH_POINT0_EN)
    /* Set switch point 0 */
    PSIO_SWITCH_MODE(PSIO, PSIO_PIN6, PSIO_SWITCH_P0, NUCODEGEN_PSIO_PIN6_MODE_SWITCH0, NUCODEGEN_PSIO_PIN6_SWITCH_POINT0);
    #endif
    #if(NUCODEGEN_PSIO_PIN6_SWITCH_POINT1_EN)
    /* Set switch point 1 */
    PSIO_SWITCH_MODE(PSIO, PSIO_PIN6, PSIO_SWITCH_P1, NUCODEGEN_PSIO_PIN6_MODE_SWITCH1, NUCODEGEN_PSIO_PIN6_SWITCH_POINT1);
    #endif  
#endif  //NUCODEGEN_PSIO_PIN6_EN

#if (NUCODEGEN_PSIO_PIN7_EN)
    /* Link check point to slot */
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN7, PSIO_CP0, NUCODEGEN_PSIO_PIN7_CP0_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN7, PSIO_CP1, NUCODEGEN_PSIO_PIN7_CP1_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN7, PSIO_CP2, NUCODEGEN_PSIO_PIN7_CP2_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN7, PSIO_CP3, NUCODEGEN_PSIO_PIN7_CP3_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN7, PSIO_CP4, NUCODEGEN_PSIO_PIN7_CP4_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN7, PSIO_CP5, NUCODEGEN_PSIO_PIN7_CP5_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN7, PSIO_CP6, NUCODEGEN_PSIO_PIN7_CP6_SLT);
    PSIO_SET_CHECKPOINT(PSIO, PSIO_PIN7, PSIO_CP7, NUCODEGEN_PSIO_PIN7_CP7_SLT);

    /* Set check point action */
    PSIO_SET_ACTION(PSIO, PSIO_PIN7, PSIO_CP0, NUCODEGEN_PSIO_PIN7_CP0_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN7, PSIO_CP1, NUCODEGEN_PSIO_PIN7_CP1_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN7, PSIO_CP2, NUCODEGEN_PSIO_PIN7_CP2_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN7, PSIO_CP3, NUCODEGEN_PSIO_PIN7_CP3_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN7, PSIO_CP4, NUCODEGEN_PSIO_PIN7_CP4_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN7, PSIO_CP5, NUCODEGEN_PSIO_PIN7_CP5_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN7, PSIO_CP6, NUCODEGEN_PSIO_PIN7_CP6_ACT);
    PSIO_SET_ACTION(PSIO, PSIO_PIN7, PSIO_CP7, NUCODEGEN_PSIO_PIN7_CP7_ACT);

    /* Set pin general control */
    PSIO_SET_GENCTL(PSIO, PSIO_PIN7, PSIO_PIN_ENABLE, NUCODEGEN_PSIO_PIN7_SLOT_CNT, NUCODEGEN_PSIO_PIN7_IOMODE, NUCODEGEN_PSIO_PIN7_INIT_STATE, NUCODEGEN_PSIO_PIN7_INTERVAL_STATE);

    /* Set pin order */
    PSIO_SET_ORDER(PSIO, PSIO_PIN7, NUCODEGEN_PSIO_PIN7_DATA_ORDER);

    /* Set data width */
    PSIO_SET_WIDTH(PSIO, PSIO_PIN7, NUCODEGEN_PSIO_PIN7_DATA_RX_WIDTH, NUCODEGEN_PSIO_PIN7_DATA_TX_WIDTH);

    /* Set data depth */
    PSIO_SET_OUTPUT_DEPTH(PSIO, PSIO_PIN7, NUCODEGEN_PSIO_PIN7_DATA_TX_DEPTH);
    PSIO_SET_INPUT_DEPTH(PSIO, PSIO_PIN7, NUCODEGEN_PSIO_PIN7_DATA_RX_DEPTH);
    
    #if(NUCODEGEN_PSIO_PIN7_SWITCH_POINT0_EN)
    /* Set switch point 0 */
    PSIO_SWITCH_MODE(PSIO, PSIO_PIN7, PSIO_SWITCH_P0, NUCODEGEN_PSIO_PIN7_MODE_SWITCH0, NUCODEGEN_PSIO_PIN7_SWITCH_POINT0);
    #endif
    #if(NUCODEGEN_PSIO_PIN7_SWITCH_POINT1_EN)
    /* Set switch point 1 */
    PSIO_SWITCH_MODE(PSIO, PSIO_PIN7, PSIO_SWITCH_P1, NUCODEGEN_PSIO_PIN7_MODE_SWITCH1, NUCODEGEN_PSIO_PIN7_SWITCH_POINT1);
    #endif  
#endif  //NUCODEGEN_PSIO_PIN7_EN

#if (NUCODEGEN_PSIO_INT_EN)
    PSIO_ENABLE_INT(PSIO, NUCODEGEN_PSIO_INT_TYPE);
    #if (NUCODEGEN_PSIO_INT0_EN)
        PSIO_SET_INTCTL(PSIO, NUCODEGEN_PSIO_INT0_SC, PSIO_INT0, NUCODEGEN_PSIO_INT0_SLOT);
    #endif  //NUCODEGEN_PSIO_INT0_EN
    #if (NUCODEGEN_PSIO_INT0_EN)
        PSIO_SET_INTCTL(PSIO, NUCODEGEN_PSIO_INT1_SC, PSIO_INT1, NUCODEGEN_PSIO_INT1_SLOT);
    #endif  //NUCODEGEN_PSIO_INT0_EN
    NVIC_EnableIRQ(PSIO_IRQn);
#endif  //NUCODEGEN_PSIO_INT_EN
}
#endif
