/* MS2: forced include of gb:Lua2/loadlib (units-lib-lua.json flag set 1). The exe's luaopen_package (0x1423a7f20)
   sets package.cpath from a Windows x64 default with _x64 / clibs / 51 entries (exe string at file offset 0x31325f0),
   where stock 5.1.4 luaconf.h has ".\?.dll;!\?.dll;!\loadall.dll". luaconf.h is include-guarded (lconfig_h), so it is
   read here first and LUA_CPATH_DEFAULT is replaced before loadlib.c's own include. LUA_PATH_DEFAULT is the stock one. */
#include "luaconf.h"
#undef LUA_CPATH_DEFAULT
#define LUA_CPATH_DEFAULT \
	".\\?_x64.dll;"  LUA_CDIR"?_x64.dll;" LUA_CDIR"loadall_x64.dll;" \
	LUA_CDIR"clibs\\?_x64.dll;" LUA_CDIR"clibs\\loadall_x64.dll;" \
	".\\?51_x64.dll;"  LUA_CDIR"?51_x64.dll;" LUA_CDIR"clibs\\?51_x64.dll"
