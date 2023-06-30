set exe_dir=%1
%exe_dir%\cppcmd.exe "%cd%" -s "periph_conf.h" -t "periph_conf.h"^
 "IP\adc.c"^
 "IP\adc_int.c"^
 "IP\bpwm.c"^
 "IP\bpwm_int.c"^
 "IP\clk.c"^
 "IP\clk_int.c"^
 "IP\crc.c"^
 "IP\fmc.c"^
 "IP\gpio.c"^
 "IP\gpio_int.c"^
 "IP\i2c.c"^
 "IP\i2c_int.c"^
 "IP\llsi.c"^
 "IP\llsi_int.c"^
 "IP\pdma.c"^
 "IP\pdma_int.c"^
 "IP\spii2s.c"^
 "IP\spii2s_int.c"^
 "IP\sys.c"^
 "IP\sys_int.c"^
 "IP\timer.c"^
 "IP\timer_int.c"^
 "IP\uart.c"^
 "IP\uart_int.c"^
 "IP\usbd.c"^
 "IP\usbd_int.c"^
 "IP\wdt.c"^
 "IP\wdt_int.c"^
 "IP\wwdt.c"^
 "IP\wwdt_int.c"^
 "periph_conf.c"^
 "int_handler.c"^
 "main.c"^
 "USBD\descriptors.c"^
 "USBD\usbd_class.c"^
 "del_nucodegen_keyword"

set err=%errorlevel%
if "%err%" NEQ "0" EXIT %err%
