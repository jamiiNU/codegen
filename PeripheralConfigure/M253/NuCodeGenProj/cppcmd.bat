set exe_dir=%1
%exe_dir%\cppcmd.exe "%cd%" -s "periph_conf.h" -t "periph_conf.h"^
 "IP\int_handler_bpwm.c"^
 "IP\int_handler_canfd.c"^
 "IP\int_handler_clk.c"^
 "IP\int_handler_eadc.c"^
 "IP\int_handler_gpio.c"^
 "IP\int_handler_i2c.c"^
 "IP\int_handler_pdma.c"^
 "IP\int_handler_rtc.c"^
 "IP\int_handler_spii2s.c"^
 "IP\int_handler_sys.c"^
 "IP\int_handler_timer.c"^
 "IP\int_handler_uart.c"^
 "IP\int_handler_usbd.c"^
 "IP\int_handler_usci_i2c.c"^
 "IP\int_handler_usci_spi.c"^
 "IP\int_handler_usci_uart.c"^
 "IP\int_handler_wdt.c"^
 "IP\int_handler_wwdt.c"^
 "IP\periph_conf_bpwm.c"^
 "IP\periph_conf_canfd.c"^
 "IP\periph_conf_clk.c"^
 "IP\periph_conf_crc.c"^
 "IP\periph_conf_eadc.c"^
 "IP\periph_conf_fmc.c"^
 "IP\periph_conf_gpio.c"^
 "IP\periph_conf_i2c.c"^
 "IP\periph_conf_pdma.c"^
 "IP\periph_conf_rtc.c"^
 "IP\periph_conf_spii2s.c"^
 "IP\periph_conf_sys.c"^
 "IP\periph_conf_timer.c"^
 "IP\periph_conf_uart.c"^
 "IP\periph_conf_usbd.c"^
 "IP\periph_conf_usci_i2c.c"^
 "IP\periph_conf_usci_spi.c"^
 "IP\periph_conf_usci_uart.c"^
 "IP\periph_conf_wdt.c"^
 "IP\periph_conf_wwdt.c"^
 "periph_conf.c"^
 "int_handler.c"^
 "main.c"^
 "USBD\descriptors.c"^
 "USBD\usbd_class.c"^
 "del_nucodegen_keyword"

set err=%errorlevel%
if "%err%" NEQ "0" EXIT %err%
