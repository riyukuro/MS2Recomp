// Nexon Messenger (NM) SDK stand-ins for the full-exe rebuild - NOT recovered code. The rebuild does not use NM
// (user decision 2026-10-24): tools/fullexe/plan.py leaves the NM zone's units (0x14156a020-0x14160a7f0) out of the
// link and places this unit at the zone's start instead. These are the only NM symbols the rest of the game references
// (work/sfr36/nm/xref.py over the TAG=11 plan), with "messenger unavailable" bodies: init/login report failure, requests
// do nothing, getters return null.
// None of them runs: FUN_1406c34b0 (the Nexon platform predicate, byte-patched to return 0 in the shipped exe) keeps
// WinMain out of the platform's NX block (vslot 14 init, vslot 4 auth, vslot 16 connect), so CNXMan is never created
// and its NM calls are unreachable. The cash shop's certify URL lookup returning 0 just skips the unlock dialog.
// The hook DLL keeps the exe's NM (and the recovered NM units): this TU is empty there.
// MS2-UNIT: nm_stubs
// MS2-NO-EXE: 0x14156a020 Nexon Messenger stand-ins for the full exe (user 2026-10-24)
#define MS2_THIS_FILE ""
#define _WINSOCKAPI_
#include <afx.h>
#include <winsock2.h>
#include "ms2/placeholder/ms2stdafx.h"

#include "ms2/client/ms2/nxman.h"

#ifndef MS2_HOOK_DLL

// MS2-FUNCTIONAL: NM stub. The global Nexon Messenger character record unit_1400fa560 constructs at startup (exe ctor
// 0x141570010, dtor 0x1415ecdb0, both NM). Nothing reads it; its 0x18 bytes there are less than the real record.
class CNMCharacter
{
public:
    CNMCharacter();
    ~CNMCharacter();
};
CNMCharacter::CNMCharacter() {}
CNMCharacter::~CNMCharacter() {}

// MS2-FUNCTIONAL: NM stubs. CNMEventHandler's slots (exe 0x1415cba80, 0x1415cc350, 0x1415cc370): no NM, no events.
void CNMEventHandler::vfunc_0(void*) {}
void CNMEventHandler::vfunc_1(void*) {}
void CNMEventHandler::vfunc_2(void*) {}

// MS2-FUNCTIONAL: NM stubs, by their address under the declarations their callers use (nxman.cpp, uicashshopdialog.cpp).
// The NM client object / manager singletons (0x1415fa1b0, 0x1415fa260): none.
void* FUN_1415fa1b0(void) { return 0; }
void* FUN_1415fa260(void) { return 0; }
// Client object initialize (0x1415c4540) and login (0x1415c4810): fail (CNXMan::FUN_14160d820 reports the error).
int FUN_1415c4540(void*, int, int, int, int) { return 0; }
int FUN_1415c4810(void*, int) { return 0; }
// Messenger connect (0x1415c4990): CNXMan::FUN_14160db80 treats 0 as success, so the error is non-zero.
int FUN_1415c4990(void*, const char*, unsigned int) { return 1; }
// Patcher available (0x1415c3780): no.
int FUN_1415c3780(void) { return 0; }
// Certify / auth URL (0x1415c3b50, UICashShopDialog): none, so the caller returns before its dialog.
int FUN_1415c3b50(const char*, char* szOut, int, int, int nLen)
{
    if (szOut != 0 && nLen > 0)
        szOut[0] = 0;
    return 0;
}
// Passport and user name (0x1415c4bb0, 0x1415c5010): empty strings into the caller's buffers.
void FUN_1415c4bb0(void*, char* psz) { if (psz != 0) psz[0] = 0; }
void FUN_1415c5010(void*, char* psz) { if (psz != 0) psz[0] = 0; }
// Requests with nothing to do without NM: run the patcher (0x1415c3430), logout (0x1415c4930), disconnect
// (0x1415c4a30), set the service names (0x1415ca030), the log context (0x1415ca240), register / unregister the
// manager (0x1415cb420, 0x1415cb430), and the window-message forward (0x1415cb760).
int FUN_1415c3430(int, const char*, const char*, const char*, int, int, int, const char*, int, const char*, int) { return 0; }
void FUN_1415c4930(void*, int) {}
void FUN_1415c4a30(void*) {}
void FUN_1415ca030(const char*, const char*, const char*) {}
void FUN_1415ca240(void*) {}
void FUN_1415cb420(void*) {}
void FUN_1415cb430(void*) {}
void FUN_1415cb760(void*, void*, void*) {}

#endif
