/******************************************************************************//**
 * @file     descriptors.c
 * @version  V0.10
 * @brief    M031 series USBD descriptor
 *
 * @note
 * SPDX-License-Identifier: Apache-2.0 
 * @copyright (C) 2018 Nuvoton Technology Corp. All rights reserved.
 ******************************************************************************/

/*!<Includes */
#include "NuCodeGenProj.h"

#if (NUCODEGEN_USBD)

#if(NUCODEGEN_CLASS_SEL==NUCODEGEN_CLASS_HID)

/*!<USB HID Report Descriptor */
const uint8_t HID_MouseReportDescriptor[] =
{
    0x05, 0x01,     /* Usage Page(Generic Desktop Controls) */
    0x09, 0x02,     /* Usage(Mouse) */
    0xA1, 0x01,     /* Collection(Application) */
    0x09, 0x01,     /* Usage(Pointer) */
    0xA1, 0x00,     /* Collection(Physical) */
    0x05, 0x09,     /* Usage Page(Button) */
    0x19, 0x01,     /* Usage Minimum(0x1) */
    0x29, 0x03,     /* Usage Maximum(0x3) */
    0x15, 0x00,     /* Logical Minimum(0x0) */
    0x25, 0x01,     /* Logical Maximum(0x1) */
    0x75, 0x01,     /* Report Size(0x1) */
    0x95, 0x03,     /* Report Count(0x3) */
    0x81, 0x02,     /* Input(3 button bit) */
    0x75, 0x05,     /* Report Size(0x5) */
    0x95, 0x01,     /* Report Count(0x1) */
    0x81, 0x01,     /* Input(5 bit padding) */
    0x05, 0x01,     /* Usage Page(Generic Desktop Controls) */
    0x09, 0x30,     /* Usage(X) */
    0x09, 0x31,     /* Usage(Y) */
    0x09, 0x38,     /* Usage(Wheel) */
    0x15, 0x81,     /* Logical Minimum(0x81)(-127) */
    0x25, 0x7F,     /* Logical Maximum(0x7F)(127) */
    0x75, 0x08,     /* Report Size(0x8) */
    0x95, 0x03,     /* Report Count(0x3) */
    0x81, 0x06,     /* Input(1 byte wheel) */
    0xC0,           /* End Collection */
    0xC0            /* End Collection */
};




/*----------------------------------------------------------------------------*/
/*!<USB Device Descriptor */
const uint8_t gu8DeviceDescriptor[] =
{
    LEN_DEVICE,     /* bLength */
    DESC_DEVICE,    /* bDescriptorType */
#ifdef SUPPORT_LPM
    0x01, 0x02,     /* bcdUSB >= 0x0201 to support LPM */
#else
    0x10, 0x01,     /* bcdUSB */
#endif
    0x00,           /* bDeviceClass */
    0x00,           /* bDeviceSubClass */
    0x00,           /* bDeviceProtocol */
    EP0_MAX_PKT_SIZE,   /* bMaxPacketSize0 */
    /* idVendor */
    USBD_VID & 0x00FF,
    (USBD_VID & 0xFF00) >> 8,
    /* idProduct */
    USBD_PID & 0x00FF,
    (USBD_PID & 0xFF00) >> 8,
    0x00, 0x00,     /* bcdDevice */
    0x01,           /* iManufacture */
    0x02,           /* iProduct */
    0x03,           /* iSerialNumber */
    0x01            /* bNumConfigurations */
};

/*!<USB Configure Descriptor */
const uint8_t gu8ConfigDescriptor[] =
{
    LEN_CONFIG,     /* bLength */
    DESC_CONFIG,    /* bDescriptorType */
    /* wTotalLength */
    LEN_CONFIG_AND_SUBORDINATE & 0x00FF,
    (LEN_CONFIG_AND_SUBORDINATE & 0xFF00) >> 8,
    0x01,           /* bNumInterfaces */
    0x01,           /* bConfigurationValue */
    0x00,           /* iConfiguration */
    0x80 | (USBD_SELF_POWERED << 6) | (USBD_REMOTE_WAKEUP << 5),/* bmAttributes */
    USBD_MAX_POWER,         /* MaxPower */

    /* I/F descr: HID */
    LEN_INTERFACE,  /* bLength */
    DESC_INTERFACE, /* bDescriptorType */
    0x00,           /* bInterfaceNumber */
    0x00,           /* bAlternateSetting */
    0x01,           /* bNumEndpoints */
    0x03,           /* bInterfaceClass */
    0x01,           /* bInterfaceSubClass */
    HID_MOUSE,      /* bInterfaceProtocol */
    0x00,           /* iInterface */

    /* HID Descriptor */
    LEN_HID,        /* Size of this descriptor in UINT8s. */
    DESC_HID,       /* HID descriptor type. */
    0x10, 0x01,     /* HID Class Spec. release number. */
    0x00,           /* H/W target country. */
    0x01,           /* Number of HID class descriptors to follow. */
    DESC_HID_RPT,   /* Descriptor type. */
    /* Total length of report descriptor. */
    sizeof(HID_MouseReportDescriptor) & 0x00FF,
    (sizeof(HID_MouseReportDescriptor) & 0xFF00) >> 8,

    /* EP Descriptor: interrupt in. */
    LEN_ENDPOINT,   /* bLength */
    DESC_ENDPOINT,  /* bDescriptorType */
    (INT_IN_EP_NUM | EP_INPUT), /* bEndpointAddress */
    EP_INT,         /* bmAttributes */
    /* wMaxPacketSize */
    EP2_MAX_PKT_SIZE & 0x00FF,
    (EP2_MAX_PKT_SIZE & 0xFF00) >> 8,
    HID_DEFAULT_INT_IN_INTERVAL     /* bInterval */
};

/*!<USB Language String Descriptor */
const uint8_t gu8StringLang[4] =
{
    4,              /* bLength */
    DESC_STRING,    /* bDescriptorType */
    0x09, 0x04
};

/*!<USB Vendor String Descriptor */
const uint8_t gu8VendorStringDesc[] =
{
    16,
    DESC_STRING,
    'N', 0, 'u', 0, 'v', 0, 'o', 0, 't', 0, 'o', 0, 'n', 0
};

/*!<USB Product String Descriptor */
const uint8_t gu8ProductStringDesc[] =
{
    20,
    DESC_STRING,
    'H', 0, 'I', 0, 'D', 0, ' ', 0, 'M', 0, 'o', 0, 'u', 0, 's', 0, 'e', 0
};



const uint8_t gu8StringSerial[26] =
{
    26,             // bLength
    DESC_STRING,    // bDescriptorType
    'A', 0, '0', 0, '2', 0, '0', 0, '0', 0, '8', 0, '0', 0, '4', 0, '0', 0, '1', 0, '1', 0, '4', 0
};

const uint8_t *gpu8UsbString[4] =
{
    gu8StringLang,
    gu8VendorStringDesc,
    gu8ProductStringDesc,
    gu8StringSerial
};

const uint8_t *gpu8UsbHidReport[3] =
{
    HID_MouseReportDescriptor,
    NULL,
    NULL
};

const uint32_t gu32UsbHidReportLen[3] =
{
    sizeof(HID_MouseReportDescriptor),
    0,
    0
};

const uint32_t gu32ConfigHidDescIdx[3] =
{
    (LEN_CONFIG + LEN_INTERFACE),
    0,
    0
};

const uint8_t gu8BosDescriptor[] =
{
    LEN_BOS,                         /* bLength         */
    DESC_BOS,                        /* bDescriptorType */
    ((LEN_BOS + LEN_BOSCAP) & 0xFF), /* wTotalLength    */
    ((LEN_BOS + LEN_BOSCAP) >> 8),   /* wTotalLength    */
    0x01,                            /* bNumDevcieCaps  */
    LEN_BOSCAP,                      /* bLength         */
    DESC_CAPABILITY,                 /* bDescriptorType */
    CAP_USB20_EXT,                   /* bDevCapabilityType, 0x02 is USB 2.0 Extension */
    0x06, 0x04, 0x00, 0x00           /* bmAttributs, 32 bits                          */
    /* bit 0     : Reserved. Must be 0.                                         */
    /* bit 1     : Set 1 to support LPM.                                        */
    /* bit 2     : Set 1 to support BSL & Alternative HIRD.                     */
    /* bit 3     : Set 1 to use Baseline BESL.                                  */
    /* bit 4     : Set 1 to use Deep BESL.                                      */
    /* bit 11:8  : Baseline BESL value. Ignore it if bit3 is zero.              */
    /* bit 15:12 : Deep BESL value. Ignore it if bit4 is zero.                  */
    /* bit 31:16 : Reserved. Must be 0.                                         */
};

const S_USBD_INFO_T gsInfo =
{
    (uint8_t *) gu8DeviceDescriptor,
    (uint8_t *) gu8ConfigDescriptor,
    (uint8_t **)gpu8UsbString,
    (uint8_t **)gpu8UsbHidReport,
    (uint8_t *) gu8BosDescriptor,
    (uint32_t *)gu32UsbHidReportLen,
    (uint32_t *)gu32ConfigHidDescIdx,
};

#endif /*NUCODEGEN_CLASS_SEL==NUCODEGEN_CLASS_HID*/


#if(NUCODEGEN_CLASS_SEL==NUCODEGEN_CLASS_MSC)
/*----------------------------------------------------------------------------*/
/*!<USB Device Descriptor */
#ifdef __ICCARM__
#pragma data_alignment=4
uint8_t gu8DeviceDescriptor[] =
{
#else
uint8_t gu8DeviceDescriptor[] __attribute__((aligned(4))) =
{
#endif
    LEN_DEVICE,         /* bLength */
    DESC_DEVICE,        /* bDescriptorType */
    0x10, 0x01,         /* bcdUSB */
    0x00,               /* bDeviceClass */
    0x00,               /* bDeviceSubClass */
    0x00,               /* bDeviceProtocol */
    EP0_MAX_PKT_SIZE,   /* bMaxPacketSize0 */
    /* idVendor */
    USBD_VID & 0x00FF,
    (USBD_VID & 0xFF00) >> 8,
    /* idProduct */
    USBD_PID & 0x00FF,
    (USBD_PID & 0xFF00) >> 8,
    0x00, 0x00,        /* bcdDevice */
    0x01,              /* iManufacture */
    0x02,              /* iProduct */
    0x03,              /* iSerialNumber -  is required for BOT device */
    0x01               /* bNumConfigurations */
};

/*!<USB Configure Descriptor */
#ifdef __ICCARM__
#pragma data_alignment=4
uint8_t gu8ConfigDescriptor[] =
{
#else
uint8_t gu8ConfigDescriptor[] __attribute__((aligned(4))) =
{
#endif
    LEN_CONFIG,                                         // bLength
    DESC_CONFIG,                                        // bDescriptorType
    (LEN_CONFIG + LEN_INTERFACE + LEN_ENDPOINT * 2), 0x00, // wTotalLength
    0x01,                                               // bNumInterfaces
    0x01,                                               // bConfigurationValue
    0x00,                                               // iConfiguration
    0xC0,                                               // bmAttributes
    0x32,                                               // MaxPower

    /* const BYTE cbyInterfaceDescriptor[LEN_INTERFACE] = */
    LEN_INTERFACE,  // bLength
    DESC_INTERFACE, // bDescriptorType
    0x00,           // bInterfaceNumber
    0x00,           // bAlternateSetting
    0x02,           // bNumEndpoints
    0x08,           // bInterfaceClass
    0x05,           // bInterfaceSubClass
    0x50,           // bInterfaceProtocol
    0x00,           // iInterface

    /* const BYTE cbyEndpointDescriptor1[LEN_ENDPOINT] = */
    LEN_ENDPOINT,           // bLength
    DESC_ENDPOINT,          // bDescriptorType
    (BULK_IN_EP_NUM | EP_INPUT), // bEndpointAddress
    EP_BULK,                // bmAttributes
    EP2_MAX_PKT_SIZE, 0x00,  // wMaxPacketSize
    0x00,                   // bInterval

    /* const BYTE cbyEndpointDescriptor2[LEN_ENDPOINT] = */
    LEN_ENDPOINT,           // bLength
    DESC_ENDPOINT,          // bDescriptorType
    BULK_OUT_EP_NUM,                   // bEndpointAddress
    EP_BULK,                // bmAttributes
    EP3_MAX_PKT_SIZE, 0x00,  // wMaxPacketSize
    0x00                    // bInterval
};

/*!<USB BOS Descriptor */
const uint8_t gu8BosDescriptor[] =
{
    LEN_BOS,                         /* bLength         */
    DESC_BOS,                        /* bDescriptorType */
    ((LEN_BOS + LEN_BOSCAP) & 0xFF), /* wTotalLength    */
    ((LEN_BOS + LEN_BOSCAP) >> 8),   /* wTotalLength    */
    0x01,                            /* bNumDevcieCaps  */
    LEN_BOSCAP,                      /* bLength         */
    DESC_CAPABILITY,                 /* bDescriptorType */
    CAP_USB20_EXT,                   /* bDevCapabilityType, 0x02 is USB 2.0 Extension */
    0x06, 0x04, 0x00, 0x00  /* bmAttributs, 32 bits     */
    /* bit 0 : Reserved. Must 0.                                         */
    /* bit 1 : 1 to support LPM.                                         */
    /* bit 2 : 1 to support BSL & Alternat HIRD                          */
    /* bit 3 : 1 to recommend Baseline BESL                              */
    /* bit 4 : 1 to recommand Deep BESL                                  */
    /* bit 11:8 : Recommend Baseline BESL value. Ignore by bit3 is zero. */
    /* bit 15:12 : Recommend Deep BESL value. Ignore by bit4 is zero.    */
    /* bit 31:16 : Reserved. Must 0.                                     */
};

/*!<USB Language String Descriptor */
#ifdef __ICCARM__
#pragma data_alignment=4
uint8_t gu8StringLang[4] =
{
#else
uint8_t gu8StringLang[4] __attribute__((aligned(4))) =
{
#endif
    4,              /* bLength */
    DESC_STRING,    /* bDescriptorType */
    0x09, 0x04
};

/*!<USB Vendor String Descriptor */
#ifdef __ICCARM__
#pragma data_alignment=4
uint8_t gu8VendorStringDesc[] =
{
#else
uint8_t gu8VendorStringDesc[] __attribute__((aligned(4))) =
{
#endif
    16,
    DESC_STRING,
    'N', 0, 'u', 0, 'v', 0, 'o', 0, 't', 0, 'o', 0, 'n', 0
};

/*!<USB Product String Descriptor */
#ifdef __ICCARM__
#pragma data_alignment=4
uint8_t gu8ProductStringDesc[] =
{
#else
uint8_t gu8ProductStringDesc[] __attribute__((aligned(4))) =
{
#endif
    22,             /* bLength          */
    DESC_STRING,    /* bDescriptorType  */
    'U', 0, 'S', 0, 'B', 0, ' ', 0, 'D', 0, 'e', 0, 'v', 0, 'i', 0, 'c', 0, 'e', 0
};

#ifdef __ICCARM__
    #pragma data_alignment=4
    uint8_t gu8StringSerial[] =
#else
    uint8_t gu8StringSerial[] __attribute__((aligned(4))) =
#endif
{
    26,             // bLength
    DESC_STRING,    // bDescriptorType
    'A', 0, '0', 0, '0', 0, '0', 0, '0', 0, '8', 0, '0', 0, '4', 0, '0', 0, '1', 0, '1', 0, '5', 0

};


const uint8_t *gpu8UsbString[4] =
{
    gu8StringLang,
    gu8VendorStringDesc,
    gu8ProductStringDesc,
    gu8StringSerial
};

const S_USBD_INFO_T gsInfo =
{
    (uint8_t *)gu8DeviceDescriptor,
    (uint8_t *)gu8ConfigDescriptor,
    (uint8_t **)gpu8UsbString,
    NULL,
    NULL,
    NULL,
    NULL
};
#endif /*NUCODEGEN_CLASS_SEL==NUCODEGEN_CLASS_MSC*/

#endif /*NUCODEGEN_USBD*/
