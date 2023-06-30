set exe_dir=%1
%exe_dir%\cppcmd.exe "%cd%" -s "periph_conf.h" -t "periph_conf.h"^
 "periph_conf.c"^
 "int_handler.c"^
 "main.c"^
 "USBD\descriptors.c"^
 "USBD\usbd_class.c"^
 "del_nucodegen_keyword"

set err=%errorlevel%
if "%err%" NEQ "0" EXIT %err%
