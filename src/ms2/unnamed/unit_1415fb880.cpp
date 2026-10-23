// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// MS2-UNIT: unit_1415fb880
// MS2-RANGE: 0x1415fb880-0x1415fbae0 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmobjects.h"
#include "ms2/ms2recover.h"

extern void FUN_1415fb880(void*, unsigned short);
extern void FUN_1415fb8d0(void*, unsigned int);
extern void FUN_1415ef280(void*, unsigned long long);
extern int FUN_141569b40(char*, const char*, unsigned int);
extern int FUN_141569c80(char*, const char*, int, unsigned long long, unsigned int);

// @0x1415fb880
void FUN_1415fb880(void* p, unsigned short v) { *reinterpret_cast<unsigned short*>(static_cast<char*>(p) + 8) = v; }

// @0x1415fb8a0
void FUN_1415fb8a0(void* p, unsigned short v) { FUN_1415fb880(static_cast<char*>(p) + 8, v); }

// @0x1415fb8d0
void FUN_1415fb8d0(void* p, unsigned int v) { *reinterpret_cast<unsigned int*>(static_cast<char*>(p) + 0x20) = v; }

// @0x1415fb8f0
void FUN_1415fb8f0(void** p, unsigned int v) { reinterpret_cast<void(__fastcall**)(void*, unsigned int)>(*p)[11](p, v); }

// @0x1415fb920
void CNMCRChatRoomMessageReceivedEvent::vfunc_11(unsigned int v) { *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x6a4) = v; }

// @0x1415fb940
void CNMCSChatMessageReceivedEvent::vfunc_11(unsigned int v) { *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x6a0) = v; }

// @0x1415fb960
void CNMEvent::vfunc_11(unsigned int) {}

// @0x1415fb970
void CNMGSSessionCreatedEvent::vfunc_11(unsigned int v) { *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x90) = v; }

// @0x1415fb990
void CNMGSSessionEstablishedEvent::vfunc_11(unsigned int v) { *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x90) = v; }

// @0x1415fb9b0
void CNMGSSessionInfoEvent::vfunc_11(unsigned int v) { *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x90) = v; }

// @0x1415fb9d0
void CNMInviteVirtualUserEvent::vfunc_11(unsigned int v) { *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x1c8) = v; }

// @0x1415fb9f0
void FUN_1415fb9f0(void* p) { *reinterpret_cast<unsigned int*>(static_cast<char*>(p) + 0x14) = 0; }

// @0x1415fba10
void FUN_1415fba10(void* p, unsigned int v) { *reinterpret_cast<unsigned int*>(static_cast<char*>(p) + 4) = v; }

// @0x1415fba30
void FUN_1415fba30(void* p, unsigned long long v) { FUN_1415ef280(static_cast<char*>(p) + 0x18, v); }

// @0x1415fba60
int FUN_1415fba60(char* dst, const char* src, unsigned long long n)
{
    int r = FUN_141569b40(dst, src, 0x7fffffff);
    if (r < 0) {
        if (n != 0) *dst = 0;
    } else {
        r = FUN_141569c80(dst, src, 0, n, 0x7ffffffe);
    }
    return r;
}
