set exe_dir=%1
%exe_dir%\cppcmd.exe "%cd%" -s "periph_conf.h" -t "periph_conf.h"^
 "IP\uart.c"^
 "IP\uart_int.c"^
 "IP\clk.c"^
 "IP\clk_int.c"^
 "IP\sys.c"^
 "IP\sys_int.c"^
 "IP\pwm.c"^
 "IP\pwm_int.c"^
 "IP\gpio.c"^
 "IP\gpio_int.c"^
 "IP\adc.c"^
 "IP\adc_int.c"^
 "IP\ecap.c"^
 "IP\ecap_int.c"^
 "IP\usci_spi.c"^
 "IP\usci_spi_int.c"^
 "IP\usci_uart.c"^
 "IP\usci_uart_int.c"^
 "IP\usci_i2c.c"^
 "IP\usci_i2c_int.c"^
 "IP\i2c.c"^
 "IP\i2c_int.c"^
 "IP\timer.c"^
 "IP\timer_int.c"^
 "IP\wdt.c"^
 "IP\wdt_int.c"^
 "IP\wwdt.c"^
 "IP\wwdt_int.c"^
 "IP\fmc.c"^
 "periph_conf.c"^
 "int_handler.c"^
 "main.c"^
 "del_nucodegen_keyword"

set err=%errorlevel%
if "%err%" NEQ "0" EXIT %err%
