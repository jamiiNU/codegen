
#if (NUCODEGEN_USBD)

#if (NUCODEGEN_CLASS_SEL==NUCODEGEN_CLASS_NONE)
#if (NUCODEGEN_USB_INT_EN)
void USBD_IRQHandler(void)
{
    uint32_t u32IntSts = USBD_GET_INT_FLAG();
    uint32_t u32State = USBD_GET_BUS_STATE();

    //------------------------------------------------------------------
    if(u32IntSts & USBD_INTSTS_VBDETIF_Msk)
    {
        // Floating detect
        USBD_CLR_INT_FLAG(USBD_INTSTS_VBDETIF_Msk);

        if(USBD_IS_ATTACHED())
        {
            /* USB Plug In */
            USBD_ENABLE_USB();
        }
        else
        {
            /* USB Un-plug */
            USBD_DISABLE_USB();
        }
    }

    //------------------------------------------------------------------
    if(u32IntSts & USBD_INTSTS_BUSIF_Msk)
    {
        /* Clear event flag */
        USBD_CLR_INT_FLAG(USBD_INTSTS_BUSIF_Msk);

        if(u32State & USBD_STATE_USBRST)
        {
            /* Bus reset */
            USBD_ENABLE_USB();
            USBD_SwReset();
        }

        if(u32State & USBD_STATE_SUSPEND)
        {
            /* Enable USB but disable PHY */
            USBD_DISABLE_PHY();
        }

        if(u32State & USBD_STATE_RESUME)
        {
            /* Enable USB and enable PHY */
            USBD_ENABLE_USB();
        }

#ifdef SUPPORT_LPM
        if(u32State & USBD_L1SUSPEND)
        {
            /*
               TODO: Implement LPM SUSPEND flag here.
                     Recommend implementing the power-saving function in main loop.
            */
        }

        if(u32State & USBD_L1RESUME)
        {
            /*
               TODO: Implement LPM RESUME flag here.
            */
        }
#endif
    }

    if(u32IntSts & USBD_INTSTS_WKIDLEIF_Msk)
    {
        /*Clear no-event wake up interrupt */
        USBD_CLR_INT_FLAG(USBD_INTSTS_WKIDLEIF_Msk);
        /*
           TODO: Implement the function that will be executed when device is woken by non-USB event.
        */
    }

    //------------------------------------------------------------------
    if(u32IntSts & USBD_INTSTS_USBIF_Msk)
    {
        // USB event
        if(u32IntSts & USBD_INTSTS_SETUP_Msk)
        {
            // Setup packet
            /* Clear event flag */
            USBD_CLR_INT_FLAG(USBD_INTSTS_SETUP_Msk);

            /* Clear the data IN/OUT ready flag of control end-points */
            USBD_STOP_TRANSACTION(EP0);
            USBD_STOP_TRANSACTION(EP1);

            USBD_ProcessSetupPacket();
        }

        // EP events
        if(u32IntSts & USBD_INTSTS_EP0)
        {
            /* Clear event flag */
            USBD_CLR_INT_FLAG(USBD_INTSTS_EP0);
            // control IN
            USBD_CtrlIn();
        }

        if(u32IntSts & USBD_INTSTS_EP1)
        {
            /* Clear event flag */
            USBD_CLR_INT_FLAG(USBD_INTSTS_EP1);

            // control OUT
            USBD_CtrlOut();
        }

        if(u32IntSts & USBD_INTSTS_EP2)
        {
            /* Clear event flag */
            USBD_CLR_INT_FLAG(USBD_INTSTS_EP2);
        }

        if(u32IntSts & USBD_INTSTS_EP3)
        {
            /* Clear event flag */
            USBD_CLR_INT_FLAG(USBD_INTSTS_EP3);
        }

        if(u32IntSts & USBD_INTSTS_EP4)
        {
            /* Clear event flag */
            USBD_CLR_INT_FLAG(USBD_INTSTS_EP4);
        }

        if(u32IntSts & USBD_INTSTS_EP5)
        {
            /* Clear event flag */
            USBD_CLR_INT_FLAG(USBD_INTSTS_EP5);
        }

        if(u32IntSts & USBD_INTSTS_EP6)
        {
            /* Clear event flag */
            USBD_CLR_INT_FLAG(USBD_INTSTS_EP6);
        }

        if(u32IntSts & USBD_INTSTS_EP7)
        {
            /* Clear event flag */
            USBD_CLR_INT_FLAG(USBD_INTSTS_EP7);
        }
    }
}
#endif /*NUCODEGEN_USB_INT_EN*/
#endif /*NUCODEGEN_CLASS_SEL==NUCODEGEN_CLASS_NONE*/


#if (NUCODEGEN_CLASS_SEL==NUCODEGEN_CLASS_HID)
#if (NUCODEGEN_USB_INT_EN)
void USBD_IRQHandler(void)
{
    uint32_t u32IntSts = USBD_GET_INT_FLAG();
    uint32_t u32State = USBD_GET_BUS_STATE();

    //------------------------------------------------------------------
    if(u32IntSts & USBD_INTSTS_VBDETIF_Msk)
    {
        // Floating detect
        USBD_CLR_INT_FLAG(USBD_INTSTS_VBDETIF_Msk);

        if(USBD_IS_ATTACHED())
        {
            /* USB Plug In */
            USBD_ENABLE_USB();
        }
        else
        {
            /* USB Un-plug */
            USBD_DISABLE_USB();
        }
    }

    //------------------------------------------------------------------
    if(u32IntSts & USBD_INTSTS_BUSIF_Msk)
    {
        /* Clear event flag */
        USBD_CLR_INT_FLAG(USBD_INTSTS_BUSIF_Msk);

        if(u32State & USBD_STATE_USBRST)
        {
            /* Bus reset */
            USBD_ENABLE_USB();
            USBD_SwReset();
        }

        if(u32State & USBD_STATE_SUSPEND)
        {
            /* Enable USB but disable PHY */
            USBD_DISABLE_PHY();
        }

        if(u32State & USBD_STATE_RESUME)
        {
            /* Enable USB and enable PHY */
            USBD_ENABLE_USB();
        }

#ifdef SUPPORT_LPM
        if(u32State & USBD_L1SUSPEND)
        {
            /*
               TODO: Implement LPM SUSPEND flag here.
                     Recommend implementing the power-saving function in main loop.
            */
        }

        if(u32State & USBD_L1RESUME)
        {
            /*
               TODO: Implement LPM RESUME flag here.
            */
        }
#endif
    }

    if(u32IntSts & USBD_INTSTS_WKIDLEIF_Msk)
    {
        /*Clear no-event wake up interrupt */
        USBD_CLR_INT_FLAG(USBD_INTSTS_WKIDLEIF_Msk);
        /*
           TODO: Implement the function that will be executed when device is woken by non-USB event.
        */
    }

    //------------------------------------------------------------------
    if(u32IntSts & USBD_INTSTS_USBIF_Msk)
    {
        // USB event
        if(u32IntSts & USBD_INTSTS_SETUP_Msk)
        {
            // Setup packet
            /* Clear event flag */
            USBD_CLR_INT_FLAG(USBD_INTSTS_SETUP_Msk);

            /* Clear the data IN/OUT ready flag of control end-points */
            USBD_STOP_TRANSACTION(EP0);
            USBD_STOP_TRANSACTION(EP1);

            USBD_ProcessSetupPacket();
        }

        // EP events
        if(u32IntSts & USBD_INTSTS_EP0)
        {
            /* Clear event flag */
            USBD_CLR_INT_FLAG(USBD_INTSTS_EP0);
            // control IN
            USBD_CtrlIn();
        }

        if(u32IntSts & USBD_INTSTS_EP1)
        {
            /* Clear event flag */
            USBD_CLR_INT_FLAG(USBD_INTSTS_EP1);

            // control OUT
            USBD_CtrlOut();
        }

        if(u32IntSts & USBD_INTSTS_EP2)
        {
            /* Clear event flag */
            USBD_CLR_INT_FLAG(USBD_INTSTS_EP2);
            // Interrupt IN
            EP2_Handler();
        }

        if(u32IntSts & USBD_INTSTS_EP3)
        {
            /* Clear event flag */
            USBD_CLR_INT_FLAG(USBD_INTSTS_EP3);
        }

        if(u32IntSts & USBD_INTSTS_EP4)
        {
            /* Clear event flag */
            USBD_CLR_INT_FLAG(USBD_INTSTS_EP4);
        }

        if(u32IntSts & USBD_INTSTS_EP5)
        {
            /* Clear event flag */
            USBD_CLR_INT_FLAG(USBD_INTSTS_EP5);
        }

        if(u32IntSts & USBD_INTSTS_EP6)
        {
            /* Clear event flag */
            USBD_CLR_INT_FLAG(USBD_INTSTS_EP6);
        }

        if(u32IntSts & USBD_INTSTS_EP7)
        {
            /* Clear event flag */
            USBD_CLR_INT_FLAG(USBD_INTSTS_EP7);
        }
    }
}

void EP2_Handler(void)  /* Interrupt IN handler */
{
    g_u8EP2Ready = 1;
}
#endif /*NUCODEGEN_USB_INT_EN*/
#endif /*NUCODEGEN_CLASS_SEL==NUCODEGEN_CLASS_HID*/

#if (NUCODEGEN_CLASS_SEL==NUCODEGEN_CLASS_MSC)
#if 0
    #define DBG_PRINTF      printf
#else
    #define DBG_PRINTF(...)
#endif
#if (NUCODEGEN_USB_INT_EN)
void USBD_IRQHandler(void)
{
    uint32_t u32IntSts = USBD_GET_INT_FLAG();
    uint32_t u32State = USBD_GET_BUS_STATE();


    //------------------------------------------------------------------
    if(u32IntSts & USBD_INTSTS_FLDET)
    {
        // Floating detect
        USBD_CLR_INT_FLAG(USBD_INTSTS_FLDET);

        if(USBD_IS_ATTACHED())
        {
            /* USB Plug In */
            USBD_ENABLE_USB();
        }
        else
        {
            /* USB Un-plug */
            USBD_DISABLE_USB();
        }
    }

    //------------------------------------------------------------------
    if(u32IntSts & USBD_INTSTS_BUS)
    {
        /* Clear event flag */
        USBD_CLR_INT_FLAG(USBD_INTSTS_BUS);

        if(u32State & USBD_STATE_USBRST)
        {
            /* Bus reset */
            USBD_ENABLE_USB();
            USBD_SwReset();
            DBG_PRINTF("Bus reset\n");
        }

        if(u32State & USBD_STATE_SUSPEND)
        {
            /* Enable USB but disable PHY */
            USBD_DISABLE_PHY();
            DBG_PRINTF("Suspend\n");
        }

        if(u32State & USBD_STATE_RESUME)
        {
            /* Enable USB and enable PHY */
            USBD_ENABLE_USB();
            DBG_PRINTF("Resume\n");
        }

#ifdef SUPPORT_LPM
        if(u32State & USBD_L1SUSPEND)
        {
            /*
               TODO: Implement LPM SUSPEND flag here.
                     Recommend implementing the power-saving function in main loop.
            */
        }

        if(u32State & USBD_L1RESUME)
        {
            /*
               TODO: Implement LPM RESUME flag here.
            */
        }
#endif
    }

    if(u32IntSts & USBD_INTSTS_WKIDLEIF_Msk)
    {
        /*Clear no-event wake up interrupt */
        USBD_CLR_INT_FLAG(USBD_INTSTS_WKIDLEIF_Msk);
        /*
           TODO: Implement the function that will be executed when device is woken by non-USB event.
        */
    }

    //------------------------------------------------------------------
    if(u32IntSts & USBD_INTSTS_USB)
    {
        // USB event
        if(u32IntSts & USBD_INTSTS_SETUP)
        {
            // Setup packet
            /* Clear event flag */
            USBD_CLR_INT_FLAG(USBD_INTSTS_SETUP);

            /* Clear the data IN/OUT ready flag of control end-points */
            USBD_STOP_TRANSACTION(EP0);
            USBD_STOP_TRANSACTION(EP1);

            USBD_ProcessSetupPacket();
        }

        // EP events
        if(u32IntSts & USBD_INTSTS_EP0)
        {
            /* Clear event flag */
            USBD_CLR_INT_FLAG(USBD_INTSTS_EP0);
            // control IN
            USBD_CtrlIn();
        }

        if(u32IntSts & USBD_INTSTS_EP1)
        {
            /* Clear event flag */
            USBD_CLR_INT_FLAG(USBD_INTSTS_EP1);

            // control OUT
            USBD_CtrlOut();
        }

        if(u32IntSts & USBD_INTSTS_EP2)
        {
            /* Clear event flag */
            USBD_CLR_INT_FLAG(USBD_INTSTS_EP2);
            // Bulk IN
            EP2_Handler();
        }

        if(u32IntSts & USBD_INTSTS_EP3)
        {
            /* Clear event flag */
            USBD_CLR_INT_FLAG(USBD_INTSTS_EP3);
            // Bulk OUT
            EP3_Handler();
        }

        if(u32IntSts & USBD_INTSTS_EP4)
        {
            /* Clear event flag */
            USBD_CLR_INT_FLAG(USBD_INTSTS_EP4);
        }

        if(u32IntSts & USBD_INTSTS_EP5)
        {
            /* Clear event flag */
            USBD_CLR_INT_FLAG(USBD_INTSTS_EP5);
        }

        if(u32IntSts & USBD_INTSTS_EP6)
        {
            /* Clear event flag */
            USBD_CLR_INT_FLAG(USBD_INTSTS_EP6);
        }

        if(u32IntSts & USBD_INTSTS_EP7)
        {
            /* Clear event flag */
            USBD_CLR_INT_FLAG(USBD_INTSTS_EP7);
        }
    }
}

void EP2_Handler(void)
{
    g_u8EP2Ready = 1;
    MSC_AckCmd();
}


void EP3_Handler(void)
{
    /* Bulk OUT */
    g_u8EP3Ready = 1;
}
#endif /*NUCODEGEN_USB_INT_EN*/
#endif /*NUCODEGEN_CLASS_SEL==NUCODEGEN_CLASS_MSC*/

#endif /*NUCODEGEN_USBD*/
