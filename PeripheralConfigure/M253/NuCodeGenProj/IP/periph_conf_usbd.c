
#if (NUCODEGEN_USBD)

void USBD_Init(void)
{

#if ( NUCODEGEN_CLASS_SEL==NUCODEGEN_CLASS_NONE )
    USBD_Open(NULL, NULL, NULL);
#endif /*NUCODEGEN_CLASS_SEL==NUCODEGEN_CLASS_NONE*/

#if (NUCODEGEN_CLASS_SEL==NUCODEGEN_CLASS_HID)
    USBD_Open(&gsInfo, HID_ClassRequest, NULL);

    /* Endpoint configuration */
    HID_Init();
#endif /*NUCODEGEN_CLASS_SEL==NUCODEGEN_CLASS_HID*/

#if ( NUCODEGEN_CLASS_SEL==NUCODEGEN_CLASS_MSC )
    USBD_Open(&gsInfo, MSC_ClassRequest, NULL);

    /* Endpoint configuration */
    MSC_Init();

    USBD_SetConfigCallback(MSC_SetConfig);
#endif /*NUCODEGEN_CLASS_SEL==NUCODEGEN_CLASS_MSC*/


#if NUCODEGEN_USB_INT_EN
    NVIC_EnableIRQ(USBD_IRQn);
#endif
}
#endif
