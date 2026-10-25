// Recovered Nexon Messenger string, cryptor, and singleton symbols from unit_1415f9410.
// MS2-UNIT: unit_1415f9410
// MS2-RANGE: 0x1415f9410-0x1415fb820 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmfunc.h"
#include <windows.h>
#include <strsafe.h>

unsigned long long FUN_1415fb760(unsigned int high, unsigned int low);

static void nm_free_string_storage(char*& p)
{
    if (p) {
        MEMORY_BASIC_INFORMATION info{};
        if (VirtualQuery(p, &info, sizeof(info)) && info.Type == MEM_PRIVATE)
            ::operator delete(p);
        p = nullptr;
    }
}

static bool nm_ensure_string(void** slot, size_t bytes, size_t emptyRva)
{
    void* empty = static_cast<unsigned char*>(reinterpret_cast<void*>(GetModuleHandleW(nullptr))) + emptyRva;
    if (*slot == nullptr || *slot == empty) {
        *slot = ::operator new(bytes);
        *static_cast<char*>(*slot) = 0;
    }
    return *slot != nullptr && *slot != empty;
}

static void nm_reset_string(void** slot, size_t emptyRva)
{
    void* empty = static_cast<unsigned char*>(reinterpret_cast<void*>(GetModuleHandleW(nullptr))) + emptyRva;
    if (*slot && *slot != empty) {
        MEMORY_BASIC_INFORMATION info{};
        if (VirtualQuery(*slot, &info, sizeof(info)) && info.Type == MEM_PRIVATE)
            ::operator delete(*slot);
    }
    *slot = empty;
}

// MS2-FUNCTIONAL: lazily allocates and clears the session string buffer, preserving its recovered shared-empty sentinel.
// @0x1415f9410
bool FUN_1415f9410(void** slot) { return nm_ensure_string(slot, 9, 0x3ae28ec); }

// MS2-FUNCTIONAL: lazily allocates and clears the session string buffer, preserving its recovered shared-empty sentinel.
// @0x1415f94c0
bool FUN_1415f94c0(void** slot) { return nm_ensure_string(slot, 0x100, 0x3ae28eb); }

// MS2-FUNCTIONAL: lazily allocates and clears the session string buffer, preserving its recovered shared-empty sentinel.
// @0x1415f9570
bool FUN_1415f9570(void** slot) { return nm_ensure_string(slot, 0x1000, 0x3ae28ea); }

// MS2-FUNCTIONAL: lazily allocates and clears the session string buffer, preserving its recovered shared-empty sentinel.
// @0x1415f9620
bool FUN_1415f9620(void** slot) { return nm_ensure_string(slot, 0x15e, 0x3ae28ed); }

// MS2-FUNCTIONAL: lazily allocates and clears the session string buffer, preserving its recovered shared-empty sentinel.
// @0x1415f96d0
bool FUN_1415f96d0(void** slot) { return nm_ensure_string(slot, 0x20, 0x3ae2848); }

// MS2-FUNCTIONAL: lazily allocates and clears the session string buffer, preserving its recovered shared-empty sentinel.
// @0x1415f9780
bool FUN_1415f9780(void** slot) { return nm_ensure_string(slot, 0x40, 0x3ae28e9); }

// MS2-FUNCTIONAL: lazily allocates and clears the session string buffer, preserving its recovered shared-empty sentinel.
// @0x1415f9830
bool FUN_1415f9830(void** slot) { return nm_ensure_string(slot, 0x400, 0x3ae28e8); }

// MS2-FUNCTIONAL: lazily allocates and clears the session string buffer, preserving its recovered shared-empty sentinel.
// @0x1415f98e0
bool FUN_1415f98e0(void** slot) { return nm_ensure_string(slot, 0x800, 0x3ae2849); }

// MS2-FUNCTIONAL: preserves the recovered null-free or allocate-and-copy behavior for this fixed-capacity string.
// @0x1415f99a0
void FUN_1415f99a0(void** slot, const char* value) { if (!value) { nm_reset_string(slot, 0x3ae28ec); return; } if (FUN_1415f9410(slot)) StringCchCopyA(static_cast<char*>(*slot), 9, value); }

// MS2-FUNCTIONAL: preserves the recovered null-free or allocate-and-copy behavior for this fixed-capacity string.
// @0x1415f99f0
void FUN_1415f99f0(void** slot, const char* value) { if (!value) { nm_reset_string(slot, 0x3ae28ea); return; } if (FUN_1415f9570(slot)) StringCchCopyA(static_cast<char*>(*slot), 0x1000, value); }

// MS2-FUNCTIONAL: preserves the recovered null-free or allocate-and-copy behavior for this fixed-capacity string.
// @0x1415f9a40
void FUN_1415f9a40(void** slot, const char* value) { if (!value) { nm_reset_string(slot, 0x3ae28ed); return; } if (FUN_1415f9620(slot)) StringCchCopyA(static_cast<char*>(*slot), 0x15e, value); }

// MS2-FUNCTIONAL: preserves the recovered null-free or allocate-and-copy behavior for this fixed-capacity string.
// @0x1415f9a90
void FUN_1415f9a90(void** slot, const char* value) { if (!value) { nm_reset_string(slot, 0x3ae2848); return; } if (FUN_1415f96d0(slot)) StringCchCopyA(static_cast<char*>(*slot), 0x20, value); }

// MS2-FUNCTIONAL: preserves the recovered null-free or allocate-and-copy behavior for this fixed-capacity string.
// @0x1415f9ae0
void FUN_1415f9ae0(void** slot, const char* value) { if (!value) { nm_reset_string(slot, 0x3ae28e9); return; } if (FUN_1415f9780(slot)) StringCchCopyA(static_cast<char*>(*slot), 0x40, value); }

// MS2-FUNCTIONAL: preserves the recovered null-free or allocate-and-copy behavior for this fixed-capacity string.
// @0x1415f9b30
void FUN_1415f9b30(void** slot, const char* value) { if (!value) { nm_reset_string(slot, 0x3ae28e8); return; } if (FUN_1415f9830(slot)) StringCchCopyA(static_cast<char*>(*slot), 0x400, value); }

// MS2-FUNCTIONAL: preserves the recovered null-free or allocate-and-copy behavior for this fixed-capacity string.
// @0x1415f9b80
void FUN_1415f9b80(void** slot, const char* value) { if (!value) { nm_reset_string(slot, 0x3ae2849); return; } if (FUN_1415f98e0(slot)) StringCchCopyA(static_cast<char*>(*slot), 0x800, value); }

// MS2-FUNCTIONAL: preserves the recovered lazy initialization and returns the slot's resulting buffer.
// @0x1415f9f20
void* FUN_1415f9f20(void** slot) { FUN_1415f9410(slot); return *slot; }

// MS2-FUNCTIONAL: preserves the recovered lazy initialization and returns the slot's resulting buffer.
// @0x1415f9f40
void* FUN_1415f9f40(void** slot) { FUN_1415f94c0(slot); return *slot; }

// MS2-FUNCTIONAL: preserves the recovered lazy initialization and returns the slot's resulting buffer.
// @0x1415f9f60
void* FUN_1415f9f60(void** slot) { FUN_1415f9570(slot); return *slot; }

// MS2-FUNCTIONAL: preserves the recovered lazy initialization and returns the slot's resulting buffer.
// @0x1415f9f80
void* FUN_1415f9f80(void** slot) { FUN_1415f9620(slot); return *slot; }

// MS2-FUNCTIONAL: preserves the recovered lazy initialization and returns the slot's resulting buffer.
// @0x1415f9fa0
void* FUN_1415f9fa0(void** slot) { FUN_1415f96d0(slot); return *slot; }

// MS2-FUNCTIONAL: preserves the recovered lazy initialization and returns the slot's resulting buffer.
// @0x1415f9fc0
void* FUN_1415f9fc0(void** slot) { FUN_1415f9780(slot); return *slot; }

// MS2-FUNCTIONAL: preserves the recovered lazy initialization and returns the slot's resulting buffer.
// @0x1415f9fe0
void* FUN_1415f9fe0(void** slot) { FUN_1415f9830(slot); return *slot; }

// MS2-FUNCTIONAL: preserves the recovered lazy initialization and returns the slot's resulting buffer.
// @0x1415fa000
void* FUN_1415fa000(void** slot) { FUN_1415f98e0(slot); return *slot; }
// @0x1415fa020
size_t FUN_1415fa020() { return 9; }
// MS2-FUNCTIONAL: fixed-capacity accessor ABI variant.
unsigned int FUN_1415fa020(void*) { return 9; }
// MS2-PIN: ?FUN_1415fa020@@YAIPEAX@Z 0x1415fa020

// @0x1415fa030
size_t FUN_1415fa030() { return 0x100; }
// MS2-FUNCTIONAL: fixed-capacity accessor ABI variant.
unsigned int FUN_1415fa030(void*) { return 0x100; }
// MS2-PIN: ?FUN_1415fa030@@YAIPEAX@Z 0x1415fa030

// @0x1415fa040
size_t FUN_1415fa040() { return 0x1000; }
// MS2-FUNCTIONAL: fixed-capacity accessor ABI variant.
unsigned int FUN_1415fa040(void*) { return 0x1000; }
// MS2-PIN: ?FUN_1415fa040@@YAIPEAX@Z 0x1415fa040

// @0x1415fa050
size_t FUN_1415fa050() { return 0x15e; }
// MS2-FUNCTIONAL: fixed-capacity accessor ABI variant.
unsigned int FUN_1415fa050(void*) { return 0x15e; }
// MS2-PIN: ?FUN_1415fa050@@YAIPEAX@Z 0x1415fa050

// @0x1415fa060
size_t FUN_1415fa060() { return 0x20; }
// MS2-FUNCTIONAL: fixed-capacity accessor ABI variant.
unsigned int FUN_1415fa060(void*) { return 0x20; }
// MS2-PIN: ?FUN_1415fa060@@YAIPEAX@Z 0x1415fa060

// @0x1415fa070
size_t FUN_1415fa070() { return 0x40; }
// MS2-FUNCTIONAL: fixed-capacity accessor ABI variant.
unsigned int FUN_1415fa070(void*) { return 0x40; }
// MS2-PIN: ?FUN_1415fa070@@YAIPEAX@Z 0x1415fa070

// @0x1415fa080
size_t FUN_1415fa080() { return 0x400; }
// MS2-FUNCTIONAL: fixed-capacity accessor ABI variant.
unsigned int FUN_1415fa080(void*) { return 0x400; }
// MS2-PIN: ?FUN_1415fa080@@YAIPEAX@Z 0x1415fa080

// @0x1415fa090
size_t FUN_1415fa090() { return 0x800; }
// MS2-FUNCTIONAL: fixed-capacity accessor ABI variant.
unsigned int FUN_1415fa090(void*) { return 0x800; }
// MS2-PIN: ?FUN_1415fa090@@YAIPEAX@Z 0x1415fa090

// @0x1415fa380
unsigned char FUN_1415fa380(const void* p) { return *(static_cast<const unsigned char*>(p) + 0x10); }
// @0x1415fa0a0
unsigned int FUN_1415fa0a0(const void* p) { return *reinterpret_cast<const unsigned int*>(static_cast<const unsigned char*>(p) + 0x10); }
// @0x1415fa0b0
unsigned int FUN_1415fa0b0(const void* p) { return *reinterpret_cast<const unsigned int*>(static_cast<const unsigned char*>(p) + 0x10); }
// @0x1415fa0c0
unsigned int FUN_1415fa0c0(const void* p) { return *reinterpret_cast<const unsigned int*>(static_cast<const unsigned char*>(p) + 0x20); }
// MS2-FUNCTIONAL: mutable-pointer ABI variant of the same field accessor.
unsigned int FUN_1415fa0c0(void* p) { return *reinterpret_cast<unsigned int*>(static_cast<unsigned char*>(p) + 0x20); }
// MS2-PIN: ?FUN_1415fa0c0@@YAIPEAX@Z 0x1415fa0c0
// @0x1415fa120
void FUN_1415fa120(const void* p) { FUN_1415fb760(*reinterpret_cast<const unsigned int*>(static_cast<const unsigned char*>(p) + 4), *reinterpret_cast<const unsigned int*>(static_cast<const unsigned char*>(p) + 8)); }
// @0x1415fa150
unsigned int FUN_1415fa150(const unsigned int* p) { return *p; }
// MS2-FUNCTIONAL: 64-bit element-pointer ABI variant; the routine reads the low word.
unsigned int FUN_1415fa150(const unsigned long long* p) { return static_cast<unsigned int>(*p); }
// MS2-PIN: ?FUN_1415fa150@@YAIPEB_K@Z 0x1415fa150
// @0x1415fa160
unsigned int FUN_1415fa160(const unsigned int* p) { return *p; }
// @0x1415fb760
unsigned long long FUN_1415fb760(unsigned int high, unsigned int low) { return (static_cast<unsigned long long>(high) << 32) | low; }
// @0x1415fb780
unsigned long long FUN_1415fb780(unsigned int high, unsigned int low) { return (static_cast<unsigned long long>(high) << 32) | low; }
// @0x1415fb7a0
void FUN_1415fb7a0(void* p) { *reinterpret_cast<unsigned int*>(static_cast<unsigned char*>(p) + 0x14) = 1; }
// @0x1415fb7c0
void FUN_1415fb7c0(void* p, unsigned int value) { *reinterpret_cast<unsigned int*>(static_cast<unsigned char*>(p) + 0x20) = value; }
// @0x1415fb7e0
void FUN_1415fb7e0(void* p, unsigned int value) { *reinterpret_cast<unsigned int*>(static_cast<unsigned char*>(p) + 0x14) = value; }
// @0x1415fb800
void FUN_1415fb800(unsigned int* p, unsigned int value) { *p = value; }

class __declspec(novtable) CNMAddCategoryFunc { public: virtual char* vfunc_8(); };
// @0x1415fa390
char* CNMAddCategoryFunc::vfunc_8() { return const_cast<char*>("CNMAddCategoryFunc"); }

class __declspec(novtable) CNMAddFriendToCategoryFunc { public: virtual char* vfunc_8(); };
// @0x1415fa3a0
char* CNMAddFriendToCategoryFunc::vfunc_8() { return const_cast<char*>("CNMAddFriendToCategoryFunc"); }

class __declspec(novtable) CNMAppendRejectedUserFunc { public: virtual char* vfunc_8(); };
// @0x1415fa3b0
char* CNMAppendRejectedUserFunc::vfunc_8() { return const_cast<char*>("CNMAppendRejectedUserFunc"); }

class __declspec(novtable) CNMAttachToNMCOServerFunc { public: virtual char* vfunc_8(); };
// @0x1415fa3c0
char* CNMAttachToNMCOServerFunc::vfunc_8() { return const_cast<char*>("CNMAttachToNMCOServerFunc"); }

class __declspec(novtable) CNMAttendanceEventEvent { public: virtual char* vfunc_8(); };
// @0x1415fa3d0
char* CNMAttendanceEventEvent::vfunc_8() { return const_cast<char*>("CNMAttendanceEventEvent"); }

class __declspec(novtable) CNMBlockFriendFunc { public: virtual char* vfunc_8(); };
// @0x1415fa400
char* CNMBlockFriendFunc::vfunc_8() { return const_cast<char*>("CNMBlockFriendFunc"); }

class __declspec(novtable) CNMCHBanUserFunc { public: virtual char* vfunc_8(); };
// @0x1415fa420
char* CNMCHBanUserFunc::vfunc_8() { return const_cast<char*>("CNMCHBanUserFunc"); }

class __declspec(novtable) CNMCHChangeChannelInfoFunc { public: virtual char* vfunc_8(); };
// @0x1415fa430
char* CNMCHChangeChannelInfoFunc::vfunc_8() { return const_cast<char*>("CNMCHChangeChannelInfoFunc"); }

class __declspec(novtable) CNMCHChangeMyInfoFunc { public: virtual char* vfunc_8(); };
// @0x1415fa440
char* CNMCHChangeMyInfoFunc::vfunc_8() { return const_cast<char*>("CNMCHChangeMyInfoFunc"); }

class __declspec(novtable) CNMCHCloseFunc { public: virtual char* vfunc_8(); };
// @0x1415fa450
char* CNMCHCloseFunc::vfunc_8() { return const_cast<char*>("CNMCHCloseFunc"); }

class __declspec(novtable) CNMCHGetChannelInfoFunc { public: virtual char* vfunc_8(); };
// @0x1415fa460
char* CNMCHGetChannelInfoFunc::vfunc_8() { return const_cast<char*>("CNMCHGetChannelInfoFunc"); }

class __declspec(novtable) CNMCHGetMemberInfoListFunc { public: virtual char* vfunc_8(); };
// @0x1415fa470
char* CNMCHGetMemberInfoListFunc::vfunc_8() { return const_cast<char*>("CNMCHGetMemberInfoListFunc"); }

class __declspec(novtable) CNMCHInviteUserFunc { public: virtual char* vfunc_8(); };
// @0x1415fa480
char* CNMCHInviteUserFunc::vfunc_8() { return const_cast<char*>("CNMCHInviteUserFunc"); }

class __declspec(novtable) CNMCHSendChannelMessageFunc { public: virtual char* vfunc_8(); };
// @0x1415fa490
char* CNMCHSendChannelMessageFunc::vfunc_8() { return const_cast<char*>("CNMCHSendChannelMessageFunc"); }

class __declspec(novtable) CNMCRBanUserFunc { public: virtual char* vfunc_8(); };
// @0x1415fa4a0
char* CNMCRBanUserFunc::vfunc_8() { return const_cast<char*>("CNMCRBanUserFunc"); }

class __declspec(novtable) CNMCRChangeMyInfoFunc { public: virtual char* vfunc_8(); };
// @0x1415fa4b0
char* CNMCRChangeMyInfoFunc::vfunc_8() { return const_cast<char*>("CNMCRChangeMyInfoFunc"); }

class __declspec(novtable) CNMCRChangeRoomInfoFunc { public: virtual char* vfunc_8(); };
// @0x1415fa4c0
char* CNMCRChangeRoomInfoFunc::vfunc_8() { return const_cast<char*>("CNMCRChangeRoomInfoFunc"); }

class __declspec(novtable) CNMCRChatRoomCreatedEvent { public: virtual char* vfunc_8(); };
// @0x1415fa4d0
char* CNMCRChatRoomCreatedEvent::vfunc_8() { return const_cast<char*>("CNMCRChatRoomCreatedEvent"); }

class __declspec(novtable) CNMCRChatRoomCreatedExEvent { public: virtual char* vfunc_8(); };
// @0x1415fa4e0
char* CNMCRChatRoomCreatedExEvent::vfunc_8() { return const_cast<char*>("CNMCRChatRoomCreatedExEvent"); }

class __declspec(novtable) CNMCRChatRoomErrorEvent { public: virtual char* vfunc_8(); };
// @0x1415fa4f0
char* CNMCRChatRoomErrorEvent::vfunc_8() { return const_cast<char*>("CNMCRChatRoomErrorEvent"); }

class __declspec(novtable) CNMCRChatRoomEstablishedEvent { public: virtual char* vfunc_8(); };
// @0x1415fa500
char* CNMCRChatRoomEstablishedEvent::vfunc_8() { return const_cast<char*>("CNMCRChatRoomEstablishedEvent"); }

class __declspec(novtable) CNMCRChatRoomEstablishedExEvent { public: virtual char* vfunc_8(); };
// @0x1415fa510
char* CNMCRChatRoomEstablishedExEvent::vfunc_8() { return const_cast<char*>("CNMCRChatRoomEstablishedExEvent"); }

class __declspec(novtable) CNMCRChatRoomInfoEvent { public: virtual char* vfunc_8(); };
// @0x1415fa520
char* CNMCRChatRoomInfoEvent::vfunc_8() { return const_cast<char*>("CNMCRChatRoomInfoEvent"); }

class __declspec(novtable) CNMCRChatRoomInfoExEvent { public: virtual char* vfunc_8(); };
// @0x1415fa530
char* CNMCRChatRoomInfoExEvent::vfunc_8() { return const_cast<char*>("CNMCRChatRoomInfoExEvent"); }

class __declspec(novtable) CNMCRChatRoomMemberEvent { public: virtual char* vfunc_8(); };
// @0x1415fa540
char* CNMCRChatRoomMemberEvent::vfunc_8() { return const_cast<char*>("CNMCRChatRoomMemberEvent"); }

class __declspec(novtable) CNMCRChatRoomMessageReceivedEvent { public: virtual char* vfunc_8(); };
// @0x1415fa550
char* CNMCRChatRoomMessageReceivedEvent::vfunc_8() { return const_cast<char*>("CNMCRChatRoomMessageReceivedEvent"); }

class __declspec(novtable) CNMCRCloseFunc { public: virtual char* vfunc_8(); };
// @0x1415fa560
char* CNMCRCloseFunc::vfunc_8() { return const_cast<char*>("CNMCRCloseFunc"); }

class __declspec(novtable) CNMCRGetMemberInfoFunc { public: virtual char* vfunc_8(); };
// @0x1415fa570
char* CNMCRGetMemberInfoFunc::vfunc_8() { return const_cast<char*>("CNMCRGetMemberInfoFunc"); }

class __declspec(novtable) CNMCRGetMemberListFunc { public: virtual char* vfunc_8(); };
// @0x1415fa580
char* CNMCRGetMemberListFunc::vfunc_8() { return const_cast<char*>("CNMCRGetMemberListFunc"); }

class __declspec(novtable) CNMCRGetRoomInfoExFunc { public: virtual char* vfunc_8(); };
// @0x1415fa590
char* CNMCRGetRoomInfoExFunc::vfunc_8() { return const_cast<char*>("CNMCRGetRoomInfoExFunc"); }

class __declspec(novtable) CNMCRGetRoomInfoFunc { public: virtual char* vfunc_8(); };
// @0x1415fa5a0
char* CNMCRGetRoomInfoFunc::vfunc_8() { return const_cast<char*>("CNMCRGetRoomInfoFunc"); }

class __declspec(novtable) CNMCRInviteUserFunc { public: virtual char* vfunc_8(); };
// @0x1415fa5b0
char* CNMCRInviteUserFunc::vfunc_8() { return const_cast<char*>("CNMCRInviteUserFunc"); }

class __declspec(novtable) CNMCRRegisterCallbackFunc { public: virtual char* vfunc_8(); };
// @0x1415fa5c0
char* CNMCRRegisterCallbackFunc::vfunc_8() { return const_cast<char*>("CNMCRRegisterCallbackFunc"); }

class __declspec(novtable) CNMCRSendChatMessageFunc { public: virtual char* vfunc_8(); };
// @0x1415fa5d0
char* CNMCRSendChatMessageFunc::vfunc_8() { return const_cast<char*>("CNMCRSendChatMessageFunc"); }

class __declspec(novtable) CNMCSChatMessageReceivedEvent { public: virtual char* vfunc_8(); };
// @0x1415fa5e0
char* CNMCSChatMessageReceivedEvent::vfunc_8() { return const_cast<char*>("CNMCSChatMessageReceivedEvent"); }

class __declspec(novtable) CNMCSMultiChatCreatedEvent { public: virtual char* vfunc_8(); };
// @0x1415fa5f0
char* CNMCSMultiChatCreatedEvent::vfunc_8() { return const_cast<char*>("CNMCSMultiChatCreatedEvent"); }

class __declspec(novtable) CNMCSSendChatMessageFunc { public: virtual char* vfunc_8(); };
// @0x1415fa600
char* CNMCSSendChatMessageFunc::vfunc_8() { return const_cast<char*>("CNMCSSendChatMessageFunc"); }

class __declspec(novtable) CNMChangeCategoryAllowTypeFunc { public: virtual char* vfunc_8(); };
// @0x1415fa610
char* CNMChangeCategoryAllowTypeFunc::vfunc_8() { return const_cast<char*>("CNMChangeCategoryAllowTypeFunc"); }

class __declspec(novtable) CNMChangeCategoryNameFunc { public: virtual char* vfunc_8(); };
// @0x1415fa620
char* CNMChangeCategoryNameFunc::vfunc_8() { return const_cast<char*>("CNMChangeCategoryNameFunc"); }

class __declspec(novtable) CNMChangeCategoryPropertyFunc { public: virtual char* vfunc_8(); };
// @0x1415fa630
char* CNMChangeCategoryPropertyFunc::vfunc_8() { return const_cast<char*>("CNMChangeCategoryPropertyFunc"); }

class __declspec(novtable) CNMChangeConfigFunc { public: virtual char* vfunc_8(); };
// @0x1415fa640
char* CNMChangeConfigFunc::vfunc_8() { return const_cast<char*>("CNMChangeConfigFunc"); }

class __declspec(novtable) CNMChangeFriendMemoExFunc { public: virtual char* vfunc_8(); };
// @0x1415fa650
char* CNMChangeFriendMemoExFunc::vfunc_8() { return const_cast<char*>("CNMChangeFriendMemoExFunc"); }

class __declspec(novtable) CNMChangeFriendMemoFunc { public: virtual char* vfunc_8(); };
// @0x1415fa660
char* CNMChangeFriendMemoFunc::vfunc_8() { return const_cast<char*>("CNMChangeFriendMemoFunc"); }

class __declspec(novtable) CNMChangeLocalConfigFunc { public: virtual char* vfunc_8(); };
// @0x1415fa670
char* CNMChangeLocalConfigFunc::vfunc_8() { return const_cast<char*>("CNMChangeLocalConfigFunc"); }

class __declspec(novtable) CNMChangeMetaDataFunc { public: virtual char* vfunc_8(); };
// @0x1415fa680
char* CNMChangeMetaDataFunc::vfunc_8() { return const_cast<char*>("CNMChangeMetaDataFunc"); }

class __declspec(novtable) CNMChangeMyInfoFunc { public: virtual char* vfunc_8(); };
// @0x1415fa690
char* CNMChangeMyInfoFunc::vfunc_8() { return const_cast<char*>("CNMChangeMyInfoFunc"); }

class __declspec(novtable) CNMChangeMyLevelFunc { public: virtual char* vfunc_8(); };
// @0x1415fa6a0
char* CNMChangeMyLevelFunc::vfunc_8() { return const_cast<char*>("CNMChangeMyLevelFunc"); }

class __declspec(novtable) CNMChangeMyPositionFunc { public: virtual char* vfunc_8(); };
// @0x1415fa6b0
char* CNMChangeMyPositionFunc::vfunc_8() { return const_cast<char*>("CNMChangeMyPositionFunc"); }

class __declspec(novtable) CNMChangeNicknameFunc { public: virtual char* vfunc_8(); };
// @0x1415fa6c0
char* CNMChangeNicknameFunc::vfunc_8() { return const_cast<char*>("CNMChangeNicknameFunc"); }

class __declspec(novtable) CNMChannelCreatedEvent { public: virtual char* vfunc_8(); };
// @0x1415fa6d0
char* CNMChannelCreatedEvent::vfunc_8() { return const_cast<char*>("CNMChannelCreatedEvent"); }

class __declspec(novtable) CNMChannelErrorEvent { public: virtual char* vfunc_8(); };
// @0x1415fa6e0
char* CNMChannelErrorEvent::vfunc_8() { return const_cast<char*>("CNMChannelErrorEvent"); }

class __declspec(novtable) CNMChannelEstablishedEvent { public: virtual char* vfunc_8(); };
// @0x1415fa6f0
char* CNMChannelEstablishedEvent::vfunc_8() { return const_cast<char*>("CNMChannelEstablishedEvent"); }

class __declspec(novtable) CNMChannelInfoEvent { public: virtual char* vfunc_8(); };
// @0x1415fa700
char* CNMChannelInfoEvent::vfunc_8() { return const_cast<char*>("CNMChannelInfoEvent"); }

class __declspec(novtable) CNMChannelMemberInfoEvent { public: virtual char* vfunc_8(); };
// @0x1415fa710
char* CNMChannelMemberInfoEvent::vfunc_8() { return const_cast<char*>("CNMChannelMemberInfoEvent"); }

class __declspec(novtable) CNMChannelMemberInfoListEvent { public: virtual char* vfunc_8(); };
// @0x1415fa720
char* CNMChannelMemberInfoListEvent::vfunc_8() { return const_cast<char*>("CNMChannelMemberInfoListEvent"); }

class __declspec(novtable) CNMChannelMessageEvent { public: virtual char* vfunc_8(); };
// @0x1415fa730
char* CNMChannelMessageEvent::vfunc_8() { return const_cast<char*>("CNMChannelMessageEvent"); }

class __declspec(novtable) CNMCharacterChangeName64Func { public: virtual char* vfunc_8(); };
// @0x1415fa750
char* CNMCharacterChangeName64Func::vfunc_8() { return const_cast<char*>("CNMCharacterChangeName64Func"); }

class __declspec(novtable) CNMCharacterChangeNameFunc { public: virtual char* vfunc_8(); };
// @0x1415fa760
char* CNMCharacterChangeNameFunc::vfunc_8() { return const_cast<char*>("CNMCharacterChangeNameFunc"); }

class __declspec(novtable) CNMCharacterLogin64Func { public: virtual char* vfunc_8(); };
// @0x1415fa770
char* CNMCharacterLogin64Func::vfunc_8() { return const_cast<char*>("CNMCharacterLogin64Func"); }

class __declspec(novtable) CNMCharacterLoginFunc { public: virtual char* vfunc_8(); };
// @0x1415fa780
char* CNMCharacterLoginFunc::vfunc_8() { return const_cast<char*>("CNMCharacterLoginFunc"); }

class __declspec(novtable) CNMCharacterLogout64Func { public: virtual char* vfunc_8(); };
// @0x1415fa790
char* CNMCharacterLogout64Func::vfunc_8() { return const_cast<char*>("CNMCharacterLogout64Func"); }

class __declspec(novtable) CNMCharacterLogoutFunc { public: virtual char* vfunc_8(); };
// @0x1415fa7a0
char* CNMCharacterLogoutFunc::vfunc_8() { return const_cast<char*>("CNMCharacterLogoutFunc"); }

class __declspec(novtable) CNMCharacterRemove64Func { public: virtual char* vfunc_8(); };
// @0x1415fa7b0
char* CNMCharacterRemove64Func::vfunc_8() { return const_cast<char*>("CNMCharacterRemove64Func"); }

class __declspec(novtable) CNMCharacterRemoveFunc { public: virtual char* vfunc_8(); };
// @0x1415fa7c0
char* CNMCharacterRemoveFunc::vfunc_8() { return const_cast<char*>("CNMCharacterRemoveFunc"); }

class __declspec(novtable) CNMCharacterSync64Func { public: virtual char* vfunc_8(); };
// @0x1415fa7d0
char* CNMCharacterSync64Func::vfunc_8() { return const_cast<char*>("CNMCharacterSync64Func"); }

class __declspec(novtable) CNMCharacterSyncFunc { public: virtual char* vfunc_8(); };
// @0x1415fa7e0
char* CNMCharacterSyncFunc::vfunc_8() { return const_cast<char*>("CNMCharacterSyncFunc"); }

class __declspec(novtable) CNMCheckNewsFunc { public: virtual char* vfunc_8(); };
// @0x1415fa7f0
char* CNMCheckNewsFunc::vfunc_8() { return const_cast<char*>("CNMCheckNewsFunc"); }

class __declspec(novtable) CNMConfirmNewFriendFunc { public: virtual char* vfunc_8(); };
// @0x1415fa800
char* CNMConfirmNewFriendFunc::vfunc_8() { return const_cast<char*>("CNMConfirmNewFriendFunc"); }

class __declspec(novtable) CNMCreateChannelFunc { public: virtual char* vfunc_8(); };
// @0x1415fa810
char* CNMCreateChannelFunc::vfunc_8() { return const_cast<char*>("CNMCreateChannelFunc"); }

class __declspec(novtable) CNMCreateChatRoomExFunc { public: virtual char* vfunc_8(); };
// @0x1415fa820
char* CNMCreateChatRoomExFunc::vfunc_8() { return const_cast<char*>("CNMCreateChatRoomExFunc"); }

class __declspec(novtable) CNMCreateChatRoomFunc { public: virtual char* vfunc_8(); };
// @0x1415fa830
char* CNMCreateChatRoomFunc::vfunc_8() { return const_cast<char*>("CNMCreateChatRoomFunc"); }

class __declspec(novtable) CNMCustomNotifyFunc { public: virtual char* vfunc_8(); };
// @0x1415fa860
char* CNMCustomNotifyFunc::vfunc_8() { return const_cast<char*>("CNMCustomNotifyFunc"); }

class __declspec(novtable) CNMDeleteCategoryFunc { public: virtual char* vfunc_8(); };
// @0x1415fa870
char* CNMDeleteCategoryFunc::vfunc_8() { return const_cast<char*>("CNMDeleteCategoryFunc"); }

class __declspec(novtable) CNMDeleteFriendFromCategoryFunc { public: virtual char* vfunc_8(); };
// @0x1415fa880
char* CNMDeleteFriendFromCategoryFunc::vfunc_8() { return const_cast<char*>("CNMDeleteFriendFromCategoryFunc"); }

class __declspec(novtable) CNMDetachFromNMCOServerFunc { public: virtual char* vfunc_8(); };
// @0x1415fa890
char* CNMDetachFromNMCOServerFunc::vfunc_8() { return const_cast<char*>("CNMDetachFromNMCOServerFunc"); }

class __declspec(novtable) CNMExecuteCommonFunc { public: virtual char* vfunc_8(); };
// @0x1415fa8d0
char* CNMExecuteCommonFunc::vfunc_8() { return const_cast<char*>("CNMExecuteCommonFunc"); }

class __declspec(novtable) CNMFDSControlFunc { public: virtual char* vfunc_8(); };
// @0x1415fa940
char* CNMFDSControlFunc::vfunc_8() { return const_cast<char*>("CNMFDSControlFunc"); }

class __declspec(novtable) CNMFDSFileDownloadEventReceivedEvent { public: virtual char* vfunc_8(); };
// @0x1415fa950
char* CNMFDSFileDownloadEventReceivedEvent::vfunc_8() { return const_cast<char*>("CNMFDSFileDownloadEventReceivedEvent"); }

class __declspec(novtable) CNMFDSGetDownloadDirFunc { public: virtual char* vfunc_8(); };
// @0x1415fa960
char* CNMFDSGetDownloadDirFunc::vfunc_8() { return const_cast<char*>("CNMFDSGetDownloadDirFunc"); }

class __declspec(novtable) CNMFDSSetDownloadDirFunc { public: virtual char* vfunc_8(); };
// @0x1415fa970
char* CNMFDSSetDownloadDirFunc::vfunc_8() { return const_cast<char*>("CNMFDSSetDownloadDirFunc"); }

class __declspec(novtable) CNMFUDSGetFileEventFunc { public: virtual char* vfunc_8(); };
// @0x1415fa980
char* CNMFUDSGetFileEventFunc::vfunc_8() { return const_cast<char*>("CNMFUDSGetFileEventFunc"); }

class __declspec(novtable) CNMFUSControlFunc { public: virtual char* vfunc_8(); };
// @0x1415fa990
char* CNMFUSControlFunc::vfunc_8() { return const_cast<char*>("CNMFUSControlFunc"); }

class __declspec(novtable) CNMFUSFileUploadEventReceivedEvent { public: virtual char* vfunc_8(); };
// @0x1415fa9a0
char* CNMFUSFileUploadEventReceivedEvent::vfunc_8() { return const_cast<char*>("CNMFUSFileUploadEventReceivedEvent"); }

class __declspec(novtable) CNMFUSSendFileFunc { public: virtual char* vfunc_8(); };
// @0x1415fa9b0
char* CNMFUSSendFileFunc::vfunc_8() { return const_cast<char*>("CNMFUSSendFileFunc"); }

class __declspec(novtable) CNMFinalizeFunc { public: virtual char* vfunc_8(); };
// @0x1415fa9c0
char* CNMFinalizeFunc::vfunc_8() { return const_cast<char*>("CNMFinalizeFunc"); }

class __declspec(novtable) CNMFindUserFunc { public: virtual char* vfunc_8(); };
// @0x1415fa9d0
char* CNMFindUserFunc::vfunc_8() { return const_cast<char*>("CNMFindUserFunc"); }

class __declspec(novtable) CNMFriendInfoChangedEvent { public: virtual char* vfunc_8(); };
// @0x1415fa9f0
char* CNMFriendInfoChangedEvent::vfunc_8() { return const_cast<char*>("CNMFriendInfoChangedEvent"); }

class __declspec(novtable) CNMGSGetInviteCandidateListFunc { public: virtual char* vfunc_8(); };
// @0x1415faa10
char* CNMGSGetInviteCandidateListFunc::vfunc_8() { return const_cast<char*>("CNMGSGetInviteCandidateListFunc"); }

class __declspec(novtable) CNMGSGetMemberListFunc { public: virtual char* vfunc_8(); };
// @0x1415faa20
char* CNMGSGetMemberListFunc::vfunc_8() { return const_cast<char*>("CNMGSGetMemberListFunc"); }

class __declspec(novtable) CNMGSGetSessionInfoFunc { public: virtual char* vfunc_8(); };
// @0x1415faa30
char* CNMGSGetSessionInfoFunc::vfunc_8() { return const_cast<char*>("CNMGSGetSessionInfoFunc"); }

class __declspec(novtable) CNMGSInviteRejectedEvent { public: virtual char* vfunc_8(); };
// @0x1415faa40
char* CNMGSInviteRejectedEvent::vfunc_8() { return const_cast<char*>("CNMGSInviteRejectedEvent"); }

class __declspec(novtable) CNMGSInviteUserExFunc { public: virtual char* vfunc_8(); };
// @0x1415faa50
char* CNMGSInviteUserExFunc::vfunc_8() { return const_cast<char*>("CNMGSInviteUserExFunc"); }

class __declspec(novtable) CNMGSInviteUserFunc { public: virtual char* vfunc_8(); };
// @0x1415faa60
char* CNMGSInviteUserFunc::vfunc_8() { return const_cast<char*>("CNMGSInviteUserFunc"); }

class __declspec(novtable) CNMGSMemberInfoChangedEvent { public: virtual char* vfunc_8(); };
// @0x1415faa70
char* CNMGSMemberInfoChangedEvent::vfunc_8() { return const_cast<char*>("CNMGSMemberInfoChangedEvent"); }

class __declspec(novtable) CNMGSMemberLeavedEvent { public: virtual char* vfunc_8(); };
// @0x1415faa80
char* CNMGSMemberLeavedEvent::vfunc_8() { return const_cast<char*>("CNMGSMemberLeavedEvent"); }

class __declspec(novtable) CNMGSNewMemberJoinedEvent { public: virtual char* vfunc_8(); };
// @0x1415faa90
char* CNMGSNewMemberJoinedEvent::vfunc_8() { return const_cast<char*>("CNMGSNewMemberJoinedEvent"); }

class __declspec(novtable) CNMGSRegisterCallbackFunc { public: virtual char* vfunc_8(); };
// @0x1415faaa0
char* CNMGSRegisterCallbackFunc::vfunc_8() { return const_cast<char*>("CNMGSRegisterCallbackFunc"); }

class __declspec(novtable) CNMGSSessionClosedEvent { public: virtual char* vfunc_8(); };
// @0x1415faab0
char* CNMGSSessionClosedEvent::vfunc_8() { return const_cast<char*>("CNMGSSessionClosedEvent"); }

class __declspec(novtable) CNMGSSessionCreatedEvent { public: virtual char* vfunc_8(); };
// @0x1415faac0
char* CNMGSSessionCreatedEvent::vfunc_8() { return const_cast<char*>("CNMGSSessionCreatedEvent"); }

class __declspec(novtable) CNMGSSessionEstablishedEvent { public: virtual char* vfunc_8(); };
// @0x1415faad0
char* CNMGSSessionEstablishedEvent::vfunc_8() { return const_cast<char*>("CNMGSSessionEstablishedEvent"); }

class __declspec(novtable) CNMGSSessionFailedEvent { public: virtual char* vfunc_8(); };
// @0x1415faae0
char* CNMGSSessionFailedEvent::vfunc_8() { return const_cast<char*>("CNMGSSessionFailedEvent"); }

class __declspec(novtable) CNMGSSessionInfoChangedEvent { public: virtual char* vfunc_8(); };
// @0x1415faaf0
char* CNMGSSessionInfoChangedEvent::vfunc_8() { return const_cast<char*>("CNMGSSessionInfoChangedEvent"); }

class __declspec(novtable) CNMGSSessionInfoEvent { public: virtual char* vfunc_8(); };
// @0x1415fab00
char* CNMGSSessionInfoEvent::vfunc_8() { return const_cast<char*>("CNMGSSessionInfoEvent"); }

class __declspec(novtable) CNMGSSetServingProcessIDFunc { public: virtual char* vfunc_8(); };
// @0x1415fab10
char* CNMGSSetServingProcessIDFunc::vfunc_8() { return const_cast<char*>("CNMGSSetServingProcessIDFunc"); }

class __declspec(novtable) CNMGSWantCloseFunc { public: virtual char* vfunc_8(); };
// @0x1415fab20
char* CNMGSWantCloseFunc::vfunc_8() { return const_cast<char*>("CNMGSWantCloseFunc"); }

class __declspec(novtable) CNMGameLogFinalizeFunc { public: virtual char* vfunc_8(); };
// @0x1415fab30
char* CNMGameLogFinalizeFunc::vfunc_8() { return const_cast<char*>("CNMGameLogFinalizeFunc"); }

class __declspec(novtable) CNMGameLogGetSessionIDFunc { public: virtual char* vfunc_8(); };
// @0x1415fab40
char* CNMGameLogGetSessionIDFunc::vfunc_8() { return const_cast<char*>("CNMGameLogGetSessionIDFunc"); }

class __declspec(novtable) CNMGameLogInitializeFunc { public: virtual char* vfunc_8(); };
// @0x1415fab50
char* CNMGameLogInitializeFunc::vfunc_8() { return const_cast<char*>("CNMGameLogInitializeFunc"); }

class __declspec(novtable) CNMGameLogWriteErrorLogFunc { public: virtual char* vfunc_8(); };
// @0x1415fab60
char* CNMGameLogWriteErrorLogFunc::vfunc_8() { return const_cast<char*>("CNMGameLogWriteErrorLogFunc"); }

class __declspec(novtable) CNMGameLogWriteStageLogFunc { public: virtual char* vfunc_8(); };
// @0x1415fab70
char* CNMGameLogWriteStageLogFunc::vfunc_8() { return const_cast<char*>("CNMGameLogWriteStageLogFunc"); }

class __declspec(novtable) CNMGetConfigFunc { public: virtual char* vfunc_8(); };
// @0x1415fab80
char* CNMGetConfigFunc::vfunc_8() { return const_cast<char*>("CNMGetConfigFunc"); }

class __declspec(novtable) CNMGetConnConfigFunc { public: virtual char* vfunc_8(); };
// @0x1415fab90
char* CNMGetConnConfigFunc::vfunc_8() { return const_cast<char*>("CNMGetConnConfigFunc"); }

class __declspec(novtable) CNMGetCountFunc { public: virtual char* vfunc_8(); };
// @0x1415faba0
char* CNMGetCountFunc::vfunc_8() { return const_cast<char*>("CNMGetCountFunc"); }

class __declspec(novtable) CNMGetDomainFunc { public: virtual char* vfunc_8(); };
// @0x1415fabb0
char* CNMGetDomainFunc::vfunc_8() { return const_cast<char*>("CNMGetDomainFunc"); }

class __declspec(novtable) CNMGetFindUserResultFunc { public: virtual char* vfunc_8(); };
// @0x1415fabc0
char* CNMGetFindUserResultFunc::vfunc_8() { return const_cast<char*>("CNMGetFindUserResultFunc"); }

class __declspec(novtable) CNMGetFriendInfoFunc { public: virtual char* vfunc_8(); };
// @0x1415fabd0
char* CNMGetFriendInfoFunc::vfunc_8() { return const_cast<char*>("CNMGetFriendInfoFunc"); }

class __declspec(novtable) CNMGetFriendListFunc { public: virtual char* vfunc_8(); };
// @0x1415fabe0
char* CNMGetFriendListFunc::vfunc_8() { return const_cast<char*>("CNMGetFriendListFunc"); }

class __declspec(novtable) CNMGetGameListFunc { public: virtual char* vfunc_8(); };
// @0x1415fac10
char* CNMGetGameListFunc::vfunc_8() { return const_cast<char*>("CNMGetGameListFunc"); }

class __declspec(novtable) CNMGetGameTokenFunc { public: virtual char* vfunc_8(); };
// @0x1415fac50
char* CNMGetGameTokenFunc::vfunc_8() { return const_cast<char*>("CNMGetGameTokenFunc"); }

class __declspec(novtable) CNMGetLocalConfigFunc { public: virtual char* vfunc_8(); };
// @0x1415fac60
char* CNMGetLocalConfigFunc::vfunc_8() { return const_cast<char*>("CNMGetLocalConfigFunc"); }

class __declspec(novtable) CNMGetMyGuildListExFunc { public: virtual char* vfunc_8(); };
// @0x1415fac70
char* CNMGetMyGuildListExFunc::vfunc_8() { return const_cast<char*>("CNMGetMyGuildListExFunc"); }

class __declspec(novtable) CNMGetMyInfoFunc { public: virtual char* vfunc_8(); };
// @0x1415fac80
char* CNMGetMyInfoFunc::vfunc_8() { return const_cast<char*>("CNMGetMyInfoFunc"); }

class __declspec(novtable) CNMGetMyVirtualUserListFunc { public: virtual char* vfunc_8(); };
// @0x1415fac90
char* CNMGetMyVirtualUserListFunc::vfunc_8() { return const_cast<char*>("CNMGetMyVirtualUserListFunc"); }

class __declspec(novtable) CNMGetNexonPassportFunc { public: virtual char* vfunc_8(); };
// @0x1415faca0
char* CNMGetNexonPassportFunc::vfunc_8() { return const_cast<char*>("CNMGetNexonPassportFunc"); }

class __declspec(novtable) CNMGetNoteBox2Func { public: virtual char* vfunc_8(); };
// @0x1415facb0
char* CNMGetNoteBox2Func::vfunc_8() { return const_cast<char*>("CNMGetNoteBox2Func"); }

class __declspec(novtable) CNMGetNoteBoxFunc { public: virtual char* vfunc_8(); };
// @0x1415facc0
char* CNMGetNoteBoxFunc::vfunc_8() { return const_cast<char*>("CNMGetNoteBoxFunc"); }

class __declspec(novtable) CNMGetNxHWIDFunc { public: virtual char* vfunc_8(); };
// @0x1415facd0
char* CNMGetNxHWIDFunc::vfunc_8() { return const_cast<char*>("CNMGetNxHWIDFunc"); }

class __declspec(novtable) CNMGetPathFunc { public: virtual char* vfunc_8(); };
// @0x1415face0
char* CNMGetPathFunc::vfunc_8() { return const_cast<char*>("CNMGetPathFunc"); }

class __declspec(novtable) CNMGetRejectedUserListFunc { public: virtual char* vfunc_8(); };
// @0x1415facf0
char* CNMGetRejectedUserListFunc::vfunc_8() { return const_cast<char*>("CNMGetRejectedUserListFunc"); }

class __declspec(novtable) CNMGetSecurityCodeCNFunc { public: virtual char* vfunc_8(); };
// @0x1415fad00
char* CNMGetSecurityCodeCNFunc::vfunc_8() { return const_cast<char*>("CNMGetSecurityCodeCNFunc"); }

class __declspec(novtable) CNMGetSecurityQuestionFunc { public: virtual char* vfunc_8(); };
// @0x1415fad10
char* CNMGetSecurityQuestionFunc::vfunc_8() { return const_cast<char*>("CNMGetSecurityQuestionFunc"); }

class __declspec(novtable) CNMGetServerInfoFunc { public: virtual char* vfunc_8(); };
// @0x1415fad20
char* CNMGetServerInfoFunc::vfunc_8() { return const_cast<char*>("CNMGetServerInfoFunc"); }

class __declspec(novtable) CNMGetUrlFunc { public: virtual char* vfunc_8(); };
// @0x1415fad60
char* CNMGetUrlFunc::vfunc_8() { return const_cast<char*>("CNMGetUrlFunc"); }

class __declspec(novtable) CNMGetUserDataListFunc { public: virtual char* vfunc_8(); };
// @0x1415fad70
char* CNMGetUserDataListFunc::vfunc_8() { return const_cast<char*>("CNMGetUserDataListFunc"); }

class __declspec(novtable) CNMGetUserInfoFunc { public: virtual char* vfunc_8(); };
// @0x1415fad80
char* CNMGetUserInfoFunc::vfunc_8() { return const_cast<char*>("CNMGetUserInfoFunc"); }

class __declspec(novtable) CNMInitializeFunc { public: virtual char* vfunc_8(); };
// @0x1415fadc0
char* CNMInitializeFunc::vfunc_8() { return const_cast<char*>("CNMInitializeFunc"); }

class __declspec(novtable) CNMJoinChannelFunc { public: virtual char* vfunc_8(); };
// @0x1415fadf0
char* CNMJoinChannelFunc::vfunc_8() { return const_cast<char*>("CNMJoinChannelFunc"); }

class __declspec(novtable) CNMJoinToChatRoomExFunc { public: virtual char* vfunc_8(); };
// @0x1415fae00
char* CNMJoinToChatRoomExFunc::vfunc_8() { return const_cast<char*>("CNMJoinToChatRoomExFunc"); }

class __declspec(novtable) CNMJoinToChatRoomFunc { public: virtual char* vfunc_8(); };
// @0x1415fae10
char* CNMJoinToChatRoomFunc::vfunc_8() { return const_cast<char*>("CNMJoinToChatRoomFunc"); }

class __declspec(novtable) CNMLogReportSyncEvent { public: virtual char* vfunc_8(); };
// @0x1415fae20
char* CNMLogReportSyncEvent::vfunc_8() { return const_cast<char*>("CNMLogReportSyncEvent"); }

class __declspec(novtable) CNMLogReportSyncFunc { public: virtual char* vfunc_8(); };
// @0x1415fae30
char* CNMLogReportSyncFunc::vfunc_8() { return const_cast<char*>("CNMLogReportSyncFunc"); }

class __declspec(novtable) CNMLoginAuthFunc { public: virtual char* vfunc_8(); };
// @0x1415fae40
char* CNMLoginAuthFunc::vfunc_8() { return const_cast<char*>("CNMLoginAuthFunc"); }

class __declspec(novtable) CNMLoginAuthSecurityCNFunc { public: virtual char* vfunc_8(); };
// @0x1415fae50
char* CNMLoginAuthSecurityCNFunc::vfunc_8() { return const_cast<char*>("CNMSecurityAuthFunc"); }

class __declspec(novtable) CNMLoginMessengerFunc { public: virtual char* vfunc_8(); };
// @0x1415fae60
char* CNMLoginMessengerFunc::vfunc_8() { return const_cast<char*>("CNMLoginMessengerFunc"); }

class __declspec(novtable) CNMLoginNexonPassportFunc { public: virtual char* vfunc_8(); };
// @0x1415fae70
char* CNMLoginNexonPassportFunc::vfunc_8() { return const_cast<char*>("CNMLoginNexonPassportFunc"); }

class __declspec(novtable) CNMLoginPassportFunc { public: virtual char* vfunc_8(); };
// @0x1415fae80
char* CNMLoginPassportFunc::vfunc_8() { return const_cast<char*>("CNMLoginPassportFunc"); }

class __declspec(novtable) CNMLoginVirtualFunc { public: virtual char* vfunc_8(); };
// @0x1415fae90
char* CNMLoginVirtualFunc::vfunc_8() { return const_cast<char*>("CNMLoginVirtualFunc"); }

class __declspec(novtable) CNMLogoutAuthFunc { public: virtual char* vfunc_8(); };
// @0x1415faea0
char* CNMLogoutAuthFunc::vfunc_8() { return const_cast<char*>("CNMLogoutAuthFunc"); }

class __declspec(novtable) CNMLogoutMessengerFunc { public: virtual char* vfunc_8(); };
// @0x1415faeb0
char* CNMLogoutMessengerFunc::vfunc_8() { return const_cast<char*>("CNMLogoutMessengerFunc"); }

class __declspec(novtable) CNMLogoutVirtualFunc { public: virtual char* vfunc_8(); };
// @0x1415faec0
char* CNMLogoutVirtualFunc::vfunc_8() { return const_cast<char*>("CNMLogoutVirtualFunc"); }

class __declspec(novtable) CNMMinimizeAllFunc { public: virtual char* vfunc_8(); };
// @0x1415faee0
char* CNMMinimizeAllFunc::vfunc_8() { return const_cast<char*>("CNMMinimizeAllFunc"); }

class __declspec(novtable) CNMMonitorGuildOnlineInfoExFunc { public: virtual char* vfunc_8(); };
// @0x1415faef0
char* CNMMonitorGuildOnlineInfoExFunc::vfunc_8() { return const_cast<char*>("CNMMonitorGuildOnlineInfoExFunc"); }

class __declspec(novtable) CNMMonitorGuildOnlineInfoFunc { public: virtual char* vfunc_8(); };
// @0x1415faf00
char* CNMMonitorGuildOnlineInfoFunc::vfunc_8() { return const_cast<char*>("CNMMonitorGuildOnlineInfoFunc"); }

class __declspec(novtable) CNMMoveFriendCategoryFunc { public: virtual char* vfunc_8(); };
// @0x1415faf10
char* CNMMoveFriendCategoryFunc::vfunc_8() { return const_cast<char*>("CNMMoveFriendCategoryFunc"); }

class __declspec(novtable) CNMNotifyEvent { public: virtual char* vfunc_8(); };
// @0x1415faf50
char* CNMNotifyEvent::vfunc_8() { return const_cast<char*>("CNMNotifyEvent"); }

class __declspec(novtable) CNMOpenGameSummaryFunc { public: virtual char* vfunc_8(); };
// @0x1415faf60
char* CNMOpenGameSummaryFunc::vfunc_8() { return const_cast<char*>("CNMOpenGameSummaryFunc"); }

class __declspec(novtable) CNMPCBangLoginFunc { public: virtual char* vfunc_8(); };
// @0x1415faf70
char* CNMPCBangLoginFunc::vfunc_8() { return const_cast<char*>("CNMPCBangLoginFunc"); }

class __declspec(novtable) CNMProcessNoteFunc { public: virtual char* vfunc_8(); };
// @0x1415faf80
char* CNMProcessNoteFunc::vfunc_8() { return const_cast<char*>("CNMProcessNoteFunc"); }

class __declspec(novtable) CNMRegisterCallbackFunc { public: virtual char* vfunc_8(); };
// @0x1415fafc0
char* CNMRegisterCallbackFunc::vfunc_8() { return const_cast<char*>("CNMRegisterCallbackFunc"); }

class __declspec(novtable) CNMRemoveMyVirtualUserFunc { public: virtual char* vfunc_8(); };
// @0x1415fafe0
char* CNMRemoveMyVirtualUserFunc::vfunc_8() { return const_cast<char*>("CNMRemoveMyVirtualUserFunc"); }

class __declspec(novtable) CNMRemoveRejectedUserFunc { public: virtual char* vfunc_8(); };
// @0x1415faff0
char* CNMRemoveRejectedUserFunc::vfunc_8() { return const_cast<char*>("CNMRemoveRejectedUserFunc"); }

class __declspec(novtable) CNMReplySessionRequestFunc { public: virtual char* vfunc_8(); };
// @0x1415fb000
char* CNMReplySessionRequestFunc::vfunc_8() { return const_cast<char*>("CNMReplySessionRequestFunc"); }

class __declspec(novtable) CNMRequestChatSessionExFunc { public: virtual char* vfunc_8(); };
// @0x1415fb010
char* CNMRequestChatSessionExFunc::vfunc_8() { return const_cast<char*>("CNMRequestChatSessionExFunc"); }

class __declspec(novtable) CNMRequestChatSessionFunc { public: virtual char* vfunc_8(); };
// @0x1415fb020
char* CNMRequestChatSessionFunc::vfunc_8() { return const_cast<char*>("CNMRequestChatSessionFunc"); }

class __declspec(novtable) CNMRequestFileUploadSessionExFunc { public: virtual char* vfunc_8(); };
// @0x1415fb030
char* CNMRequestFileUploadSessionExFunc::vfunc_8() { return const_cast<char*>("CNMRequestFileUploadSessionExFunc"); }

class __declspec(novtable) CNMRequestFileUploadSessionFunc { public: virtual char* vfunc_8(); };
// @0x1415fb040
char* CNMRequestFileUploadSessionFunc::vfunc_8() { return const_cast<char*>("CNMRequestFileUploadSessionFunc"); }

class __declspec(novtable) CNMRequestMultiChatSessionExFunc { public: virtual char* vfunc_8(); };
// @0x1415fb050
char* CNMRequestMultiChatSessionExFunc::vfunc_8() { return const_cast<char*>("CNMRequestMultiChatSessionExFunc"); }

class __declspec(novtable) CNMRequestMultiChatSessionFunc { public: virtual char* vfunc_8(); };
// @0x1415fb060
char* CNMRequestMultiChatSessionFunc::vfunc_8() { return const_cast<char*>("CNMRequestMultiChatSessionFunc"); }

class __declspec(novtable) CNMRequestNewFriendFunc { public: virtual char* vfunc_8(); };
// @0x1415fb080
char* CNMRequestNewFriendFunc::vfunc_8() { return const_cast<char*>("CNMRequestNewFriendFunc"); }

class __declspec(novtable) CNMRequestNewsFunc { public: virtual char* vfunc_8(); };
// @0x1415fb090
char* CNMRequestNewsFunc::vfunc_8() { return const_cast<char*>("CNMRequestNewsFunc"); }

class __declspec(novtable) CNMRequestSessionToOtherFunc { public: virtual char* vfunc_8(); };
// @0x1415fb0a0
char* CNMRequestSessionToOtherFunc::vfunc_8() { return const_cast<char*>("CNMRequestSessionToOtherFunc"); }

class __declspec(novtable) CNMRequestWBSessionExFunc { public: virtual char* vfunc_8(); };
// @0x1415fb0b0
char* CNMRequestWBSessionExFunc::vfunc_8() { return const_cast<char*>("CNMRequestWBSessionExFunc"); }

class __declspec(novtable) CNMRequestWBSessionFunc { public: virtual char* vfunc_8(); };
// @0x1415fb0c0
char* CNMRequestWBSessionFunc::vfunc_8() { return const_cast<char*>("CNMRequestWBSessionFunc"); }

class __declspec(novtable) CNMResetCallbackFunc { public: virtual char* vfunc_8(); };
// @0x1415fb0d0
char* CNMResetCallbackFunc::vfunc_8() { return const_cast<char*>("CNMResetCallbackFunc"); }

class __declspec(novtable) CNMRestrictedWordsFunc { public: virtual char* vfunc_8(); };
// @0x1415fb0e0
char* CNMRestrictedWordsFunc::vfunc_8() { return const_cast<char*>("CNMRestrictedWordsFunc"); }

class __declspec(novtable) CNMSendAccuseNoteMsgFunc { public: virtual char* vfunc_8(); };
// @0x1415fb0f0
char* CNMSendAccuseNoteMsgFunc::vfunc_8() { return const_cast<char*>("CNMSendAccuseNoteMsgFunc"); }

class __declspec(novtable) CNMSendNoteExMsgFunc { public: virtual char* vfunc_8(); };
// @0x1415fb100
char* CNMSendNoteExMsgFunc::vfunc_8() { return const_cast<char*>("CNMSendNoteExMsgFunc"); }

class __declspec(novtable) CNMSendNoteInfoFunc { public: virtual char* vfunc_8(); };
// @0x1415fb110
char* CNMSendNoteInfoFunc::vfunc_8() { return const_cast<char*>("CNMSendNoteInfoFunc"); }

class __declspec(novtable) CNMSendNoteMsgFunc { public: virtual char* vfunc_8(); };
// @0x1415fb120
char* CNMSendNoteMsgFunc::vfunc_8() { return const_cast<char*>("CNMSendNoteMsgFunc"); }

class __declspec(novtable) CNMSendRefreshMessageFunc { public: virtual char* vfunc_8(); };
// @0x1415fb130
char* CNMSendRefreshMessageFunc::vfunc_8() { return const_cast<char*>("CNMSendRefreshMessageFunc"); }

class __declspec(novtable) CNMSetAuthClosedCallbackFunc { public: virtual char* vfunc_8(); };
// @0x1415fb150
char* CNMSetAuthClosedCallbackFunc::vfunc_8() { return const_cast<char*>("CNMSetAuthClosedCallbackFunc"); }

class __declspec(novtable) CNMSetCodePageFunc { public: virtual char* vfunc_8(); };
// @0x1415fb160
char* CNMSetCodePageFunc::vfunc_8() { return const_cast<char*>("CNMSetCodePageFunc"); }

class __declspec(novtable) CNMSetConnConfigFunc { public: virtual char* vfunc_8(); };
// @0x1415fb170
char* CNMSetConnConfigFunc::vfunc_8() { return const_cast<char*>("CNMSetConnConfigFunc"); }

class __declspec(novtable) CNMSetCountFunc { public: virtual char* vfunc_8(); };
// @0x1415fb180
char* CNMSetCountFunc::vfunc_8() { return const_cast<char*>("CNMSetCountFunc"); }

class __declspec(novtable) CNMSetLocaleFunc { public: virtual char* vfunc_8(); };
// @0x1415fb190
char* CNMSetLocaleFunc::vfunc_8() { return const_cast<char*>("CNMSetLocaleFunc"); }

class __declspec(novtable) CNMSetStatInfoFunc { public: virtual char* vfunc_8(); };
// @0x1415fb1c0
char* CNMSetStatInfoFunc::vfunc_8() { return const_cast<char*>("CNMSetStatInfoFunc"); }

class __declspec(novtable) CNMStartStandAloneMsgFunc { public: virtual char* vfunc_8(); };
// @0x1415fb1e0
char* CNMStartStandAloneMsgFunc::vfunc_8() { return const_cast<char*>("CNMStartStandAloneMsgFunc"); }

class __declspec(novtable) CNMTPATokenLoginFunc { public: virtual char* vfunc_8(); };
// @0x1415fb1f0
char* CNMTPATokenLoginFunc::vfunc_8() { return const_cast<char*>("CNMTPATokenLoginFunc"); }

class __declspec(novtable) CNMWSAssocSerialKeyEvent { public: virtual char* vfunc_8(); };
// @0x1415fb230
char* CNMWSAssocSerialKeyEvent::vfunc_8() { return const_cast<char*>("CNMWSAssocSerialKeyEvent"); }

class __declspec(novtable) CNMWSGetAssocSerialKeyFunc { public: virtual char* vfunc_8(); };
// @0x1415fb240
char* CNMWSGetAssocSerialKeyFunc::vfunc_8() { return const_cast<char*>("CNMWSGetAssocSerialKeyFunc"); }

class __declspec(novtable) CNMWSSendWBMessageFunc { public: virtual char* vfunc_8(); };
// @0x1415fb250
char* CNMWSSendWBMessageFunc::vfunc_8() { return const_cast<char*>("CNMWSSendWBMessageFunc"); }

class __declspec(novtable) CNMWSWhiteBoardAckReceivedEvent { public: virtual char* vfunc_8(); };
// @0x1415fb260
char* CNMWSWhiteBoardAckReceivedEvent::vfunc_8() { return const_cast<char*>("CNMWSWhiteBoardAckReceivedEvent"); }

class __declspec(novtable) CNMWSWhiteBoardMsgReceivedEvent { public: virtual char* vfunc_8(); };
// @0x1415fb270
char* CNMWSWhiteBoardMsgReceivedEvent::vfunc_8() { return const_cast<char*>("CNMWSWhiteBoardMsgReceivedEvent"); }
class __declspec(novtable) CNMAuthConnectionClosedEvent { public: virtual char* vfunc_8(); };
// @0x1415fa3e0
char* CNMAuthConnectionClosedEvent::vfunc_8() { return const_cast<char*>("CNMAuthConnectionClosedEvent"); }

class __declspec(novtable) CNMAuthSecondaryConnectionClosedEvent { public: virtual char* vfunc_8(); };
// @0x1415fa3f0
char* CNMAuthSecondaryConnectionClosedEvent::vfunc_8() { return const_cast<char*>("CNMAuthSecondaryConnectionClosedEvent"); }

class __declspec(novtable) CNMCustomMessageEvent { public: virtual char* vfunc_8(); };
// @0x1415fa840
char* CNMCustomMessageEvent::vfunc_8() { return const_cast<char*>("CNMCustomMessageEvent"); }

class __declspec(novtable) CNMCustomNotifyEvent { public: virtual char* vfunc_8(); };
// @0x1415fa850
char* CNMCustomNotifyEvent::vfunc_8() { return const_cast<char*>("CNMCustomNotifyEvent"); }

class __declspec(novtable) CNMEvent { public: virtual char* vfunc_8(); };
// @0x1415fa8c0
char* CNMEvent::vfunc_8() { return const_cast<char*>("CNMEvent"); }

class __declspec(novtable) CNMFindUserReplyEvent { public: virtual char* vfunc_8(); };
// @0x1415fa9e0
char* CNMFindUserReplyEvent::vfunc_8() { return const_cast<char*>("CNMFindUserReplyEvent"); }

class __declspec(novtable) CNMGuildChatMessageEvent { public: virtual char* vfunc_8(); };
// @0x1415fad90
char* CNMGuildChatMessageEvent::vfunc_8() { return const_cast<char*>("CNMGuildChatMessageEvent"); }

class __declspec(novtable) CNMGuildOnlineInfoEvent { public: virtual char* vfunc_8(); };
// @0x1415fada0
char* CNMGuildOnlineInfoEvent::vfunc_8() { return const_cast<char*>("CNMGuildOnlineInfoEvent"); }

class __declspec(novtable) CNMGuildOnlineInfoExEvent { public: virtual char* vfunc_8(); };
// @0x1415fadb0
char* CNMGuildOnlineInfoExEvent::vfunc_8() { return const_cast<char*>("CNMGuildOnlineInfoExEvent"); }

class __declspec(novtable) CNMInviteVirtualUserEvent { public: virtual char* vfunc_8(); };
// @0x1415fadd0
char* CNMInviteVirtualUserEvent::vfunc_8() { return const_cast<char*>("CNMInviteVirtualUserEvent"); }

class __declspec(novtable) CNMMessengerReplyEvent { public: virtual char* vfunc_8(); };
// @0x1415faed0
char* CNMMessengerReplyEvent::vfunc_8() { return const_cast<char*>("CNMMessengerReplyEvent"); }

class __declspec(novtable) CNMMsgConnectionClosedEvent { public: virtual char* vfunc_8(); };
// @0x1415faf20
char* CNMMsgConnectionClosedEvent::vfunc_8() { return const_cast<char*>("CNMMsgConnectionClosedEvent"); }

class __declspec(novtable) CNMNoteInfoEvent { public: virtual char* vfunc_8(); };
// @0x1415faf30
char* CNMNoteInfoEvent::vfunc_8() { return const_cast<char*>("CNMNoteInfoEvent"); }

class __declspec(novtable) CNMNoteInstantMsgEvent { public: virtual char* vfunc_8(); };
// @0x1415faf40
char* CNMNoteInstantMsgEvent::vfunc_8() { return const_cast<char*>("CNMNoteInstantMsgEvent"); }

class __declspec(novtable) CNMRealFriendInfoChangedEvent { public: virtual char* vfunc_8(); };
// @0x1415faf90
char* CNMRealFriendInfoChangedEvent::vfunc_8() { return const_cast<char*>("CNMRealFriendInfoChangedEvent"); }

class __declspec(novtable) CNMRefreshEvent { public: virtual char* vfunc_8(); };
// @0x1415fafa0
char* CNMRefreshEvent::vfunc_8() { return const_cast<char*>("CNMRefreshEvent"); }

class __declspec(novtable) CNMRefreshMessageEvent { public: virtual char* vfunc_8(); };
// @0x1415fafb0
char* CNMRefreshMessageEvent::vfunc_8() { return const_cast<char*>("CNMRefreshMessageEvent"); }

class __declspec(novtable) CNMRejectedUserListChangedEvent { public: virtual char* vfunc_8(); };
// @0x1415fafd0
char* CNMRejectedUserListChangedEvent::vfunc_8() { return const_cast<char*>("CNMRejectedUserListChangedEvent"); }

class __declspec(novtable) CNMRequestNewFriendEvent { public: virtual char* vfunc_8(); };
// @0x1415fb070
char* CNMRequestNewFriendEvent::vfunc_8() { return const_cast<char*>("CNMRequestNewFriendEvent"); }

class __declspec(novtable) CNMServerMessageEvent { public: virtual char* vfunc_8(); };
// @0x1415fb140
char* CNMServerMessageEvent::vfunc_8() { return const_cast<char*>("CNMServerMessageEvent"); }

class __declspec(novtable) CNMSpecialEvent { public: virtual char* vfunc_8(); };
// @0x1415fb1d0
char* CNMSpecialEvent::vfunc_8() { return const_cast<char*>("CNMSpecialEvent"); }

class __declspec(novtable) CNMUserInfoEvent { public: virtual char* vfunc_8(); };
// @0x1415fb210
char* CNMUserInfoEvent::vfunc_8() { return const_cast<char*>("CNMUserInfoEvent"); }

class __declspec(novtable) CNMVirtualFriendInfoChangedEvent { public: virtual char* vfunc_8(); };
// @0x1415fb220
char* CNMVirtualFriendInfoChangedEvent::vfunc_8() { return const_cast<char*>("CNMVirtualFriendInfoChangedEvent"); }

// @0x1415f9990
void FUN_1415f9990(void*) { }
// MS2-FUNCTIONAL: the recovered helper is an empty body; pin the alternate unsigned return analysis too.
// MS2-PIN: ?FUN_1415f9990@@YAXPEAX@Z 0x1415f9990
// MS2-PIN: ?FUN_1415f9990@@YAIPEAX@Z 0x1415f9990
#pragma comment(linker, "/alternatename:?FUN_1415f9990@@YAIPEAX@Z=?FUN_1415f9990@@YAXPEAX@Z")

// @0x1415f9c30
template<> void CNMStr<0x100>::Free() { nm_free_string_storage(m_p); }
// MS2-FUNCTIONAL: frees heap storage while preserving the image-backed shared empty string.
// MS2-PIN: ?Free@?$CNMStr@$0BAA@@@QEAAXXZ 0x1415f9c30

// @0x1415f9c90
template<> void CNMStr<0x1000>::Free() { nm_free_string_storage(m_p); }
// MS2-FUNCTIONAL: frees heap storage while preserving the image-backed shared empty string.
extern void FUN_1415eb4d0(void*, void*, void*, void*, int);
extern void FUN_1415e5b80(void*, void*, void*, void*, int);
extern void* FUN_1415e59a0(void*, void*);

// @0x1415fa170
void* FUN_1415fa170(void* result, void* first, void* value, void* end)
{
    FUN_1415e59a0(result, first);
    return result;
}

// @0x1415f9ed0
unsigned long long FUN_1415f9ed0(void* first, void* result, void* value, void* end)
{
    FUN_1415eb4d0(result, static_cast<char*>(first) + 8, value, end, 0);
    return reinterpret_cast<unsigned long long>(result);
}

// @0x1415fa740
void* FUN_1415fa740(void* p) { return static_cast<char*>(p) + 0x58; }

// @0x1415fb2b0
void FUN_1415fb2b0(void* p)
{
    auto** vtable = *reinterpret_cast<void***>(p);
    reinterpret_cast<void (*)(void*)>(vtable[10])(p);
}

// @0x1415fb650
unsigned long long FUN_1415fb650(void* first, void* result, void* value, void* end)
{
    FUN_1415e5b80(result, static_cast<char*>(first) + 0x18, value, end, 0);
    return reinterpret_cast<unsigned long long>(result);
}

// @0x1415fb6a0
unsigned long long* FUN_1415fb6a0(const void* first, unsigned long long* result)
{
    *result = *reinterpret_cast<const unsigned long long*>(static_cast<const char*>(first) + 0x50);
    return result;
}

// MS2-PIN: ?Free@?$CNMStr@$0BAAA@@@QEAAXXZ 0x1415f9c90

// @0x1415f9cf0
template<> void CNMStr<350>::Free() { nm_free_string_storage(m_p); }
// MS2-FUNCTIONAL: frees heap storage while preserving the image-backed shared empty string.
// MS2-PIN: ?Free@?$CNMStr@$0BFO@@@QEAAXXZ 0x1415f9cf0

// @0x1415f9d50
template<> void CNMStr<32>::Free() { nm_free_string_storage(m_p); }
// MS2-FUNCTIONAL: frees heap storage while preserving the image-backed shared empty string.
// MS2-PIN: ?Free@?$CNMStr@$0CA@@@QEAAXXZ 0x1415f9d50

// @0x1415f9db0
template<> void CNMStr<64>::Free() { nm_free_string_storage(m_p); }
// MS2-FUNCTIONAL: frees heap storage while preserving the image-backed shared empty string.
// MS2-PIN: ?Free@?$CNMStr@$0EA@@@QEAAXXZ 0x1415f9db0

// @0x1415f9e10
template<> void CNMStr<1024>::Free() { nm_free_string_storage(m_p); }
// MS2-FUNCTIONAL: frees heap storage while preserving the image-backed shared empty string.
// MS2-PIN: ?Free@?$CNMStr@$0EAA@@@QEAAXXZ 0x1415f9e10

// @0x1415f9e70
template<> void CNMStr<2048>::Free() { nm_free_string_storage(m_p); }
// MS2-FUNCTIONAL: frees heap storage while preserving the image-backed shared empty string.
// MS2-PIN: ?Free@?$CNMStr@$0IAA@@@QEAAXXZ 0x1415f9e70

class CStreamCryptor_v0
{
public:
    virtual void vfunc_1(); virtual void vfunc_2(); virtual bool vfunc_3();
    virtual unsigned long long vfunc_4(); virtual unsigned int vfunc_5(); virtual unsigned int vfunc_6(unsigned int);
};
class CStreamCryptor_v1
{
public:
    virtual void vfunc_1(); virtual void vfunc_2(); virtual bool vfunc_3();
    virtual unsigned long long vfunc_4(); virtual unsigned int vfunc_5(); virtual int vfunc_6(int);
};
// @0x1415fa0d0
unsigned int CStreamCryptor_v0::vfunc_6(unsigned int value) { return value; }
// MS2-PIN: ?vfunc_6@CStreamCryptor_v0@@UEAAII@Z 0x1415fa0d0
// @0x1415fa0e0
int CStreamCryptor_v1::vfunc_6(int value) { return value + 10; }
// MS2-PIN: ?vfunc_6@CStreamCryptor_v1@@UEAAHH@Z 0x1415fa0e0
// @0x1415fa100
unsigned int CStreamCryptor_v0::vfunc_5() { return 0x8a119e; }
// MS2-PIN: ?vfunc_5@CStreamCryptor_v0@@UEAAIXZ 0x1415fa100
// @0x1415fa110
unsigned int CStreamCryptor_v1::vfunc_5() { return 0x820a9e12; }
// MS2-PIN: ?vfunc_5@CStreamCryptor_v1@@UEAAIXZ 0x1415fa110

// MS2-FUNCTIONAL: provides the process-stable singleton instance recovered from this function.
// @0x1415fa260
CNMManager* CNMManager::GetInstance()
{
    static CNMManager manager;
    return &manager;
}
// MS2-PIN: ?GetInstance@CNMManager@@SAPEAV1@XZ 0x1415fa260

// @0x1415fb610
unsigned long long CStreamCryptor_v0::vfunc_4() { return 0x1fca34; }
// MS2-PIN: ?vfunc_4@CStreamCryptor_v0@@UEAA_KXZ 0x1415fb610
// @0x1415fb620
unsigned long long CStreamCryptor_v1::vfunc_4() { return 0xa98c32a; }
// MS2-PIN: ?vfunc_4@CStreamCryptor_v1@@UEAA_KXZ 0x1415fb620
// @0x1415fb6e0
bool CStreamCryptor_v0::vfunc_3() { return false; }
// MS2-PIN: ?vfunc_3@CStreamCryptor_v0@@UEAA_NXZ 0x1415fb6e0
// @0x1415fb6f0
bool CStreamCryptor_v1::vfunc_3() { return true; }
// MS2-PIN: ?vfunc_3@CStreamCryptor_v1@@UEAA_NXZ 0x1415fb6f0

// The executable's vftable refers to these slots with the recovered void() ABI.
// The source-level return-value variants above share the same code and calling
// convention for slots 3-5, so preserve those bodies under the vftable names.
#pragma comment(linker, "/alternatename:?vfunc_3@CStreamCryptor_v0@@UEAAXXZ=?vfunc_3@CStreamCryptor_v0@@UEAA_NXZ")
#pragma comment(linker, "/alternatename:?vfunc_3@CStreamCryptor_v1@@UEAAXXZ=?vfunc_3@CStreamCryptor_v1@@UEAA_NXZ")
#pragma comment(linker, "/alternatename:?vfunc_4@CStreamCryptor_v0@@UEAAXXZ=?vfunc_4@CStreamCryptor_v0@@UEAA_KXZ")
#pragma comment(linker, "/alternatename:?vfunc_4@CStreamCryptor_v1@@UEAAXXZ=?vfunc_4@CStreamCryptor_v1@@UEAA_KXZ")
#pragma comment(linker, "/alternatename:?vfunc_5@CStreamCryptor_v0@@UEAAXXZ=?vfunc_5@CStreamCryptor_v0@@UEAAIXZ")
#pragma comment(linker, "/alternatename:?vfunc_5@CStreamCryptor_v1@@UEAAXXZ=?vfunc_5@CStreamCryptor_v1@@UEAAIXZ")

extern "C" void __fastcall nm_streamcryptor_v0_v6(void* self)
{
    static_cast<CStreamCryptor_v0*>(self)->CStreamCryptor_v0::vfunc_6(0);
}

extern "C" void __fastcall nm_streamcryptor_v1_v6(void* self)
{
    static_cast<CStreamCryptor_v1*>(self)->CStreamCryptor_v1::vfunc_6(0);
}

#pragma comment(linker, "/alternatename:?vfunc_6@CStreamCryptor_v0@@UEAAXXZ=nm_streamcryptor_v0_v6")
#pragma comment(linker, "/alternatename:?vfunc_6@CStreamCryptor_v1@@UEAAXXZ=nm_streamcryptor_v1_v6")

// @0x1415fb700
int FUN_1415fb700(void* p) { return *reinterpret_cast<int*>(static_cast<char*>(p) + 0x14); }
// MS2-PIN: ?FUN_1415fb700@@YAHPEAX@Z 0x1415fb700
// @0x1415fb700
int FUN_1415fb700(const void* p) { return *reinterpret_cast<const int*>(static_cast<const char*>(p) + 0x14); }
// MS2-PIN: ?FUN_1415fb700@@YAHPEBX@Z 0x1415fb700

// @0x1415fb720
int FUN_1415fb720(void* p) { return *reinterpret_cast<int*>(static_cast<char*>(p) + 0x14) == 0; }
// MS2-PIN: ?FUN_1415fb720@@YAHPEAX@Z 0x1415fb720

// @0x1415fb750
unsigned int FUN_1415fb750(void* p) { return *reinterpret_cast<unsigned int*>(static_cast<char*>(p) + 0x24); }
// MS2-PIN: ?FUN_1415fb750@@YAIPEAX@Z 0x1415fb750
// MS2-PIN: ?FUN_1415fb750@@YAHPEAX@Z 0x1415fb750

// @0x1415f9bd0
// MS2-FUNCTIONAL: resets the fixed string slot to the shared image-backed empty sentinel.
void FUN_1415f9bd0(void** p) { nm_reset_string(p, 0x3ae28ec); }
// MS2-PIN: ?FUN_1415f9bd0@@YAXPEAPEAX@Z 0x1415f9bd0
// MS2-FUNCTIONAL: adapter for the capacity-specific free routine at this entry point.
void FUN_1415f9c30(void* p) { reinterpret_cast<CNMStr<0x100>*>(p)->Free(); }
// MS2-PIN: ?FUN_1415f9c30@@YAXPEAX@Z 0x1415f9c30
// @0x1415fb290
unsigned long long FUN_1415fb290(unsigned long long value) { return value >> 32; }
// @0x1415fb2a0
unsigned short FUN_1415fb2a0(const void* p) { return *reinterpret_cast<const unsigned short*>(static_cast<const char*>(p) + 8); }
// @0x1415fb3a0
const char* FUN_1415fb3a0(const char* p) { return p + 0xa38; }
// @0x1415fb5f0
unsigned long long FUN_1415fb5f0(const unsigned long long* p) { return *p >> 32; }
// @0x1415fb630
unsigned char FUN_1415fb630(const void* p) { return *(static_cast<const unsigned char*>(p) + 0x1c); }
// @0x1415fb640
unsigned int FUN_1415fb640(const void* p) { return *reinterpret_cast<const unsigned int*>(static_cast<const char*>(p) + 4); }
// @0x1415fb6d0
unsigned char FUN_1415fb6d0(const void* p) { return *(static_cast<const unsigned char*>(p) + 0x28); }
// @0x1415fb710
unsigned int FUN_1415fb710(const void* p) { return *reinterpret_cast<const unsigned int*>(static_cast<const char*>(p) + 0x18); }

// Full-exe ABI entry points whose first parameter is an opaque object pointer, rather than a void** in C++.
// MS2-FUNCTIONAL: forwards each entry point to the recovered fixed-string lazy allocator.
void* FUN_1415f9f20(void* slot) { return FUN_1415f9f20(reinterpret_cast<void**>(slot)); }
// MS2-PIN: ?FUN_1415f9f20@@YAPEAXPEAX@Z 0x1415f9f20
// MS2-FUNCTIONAL: forwards each entry point to the recovered fixed-string lazy allocator.
void* FUN_1415f9f40(void* slot) { return FUN_1415f9f40(reinterpret_cast<void**>(slot)); }
// MS2-PIN: ?FUN_1415f9f40@@YAPEAXPEAX@Z 0x1415f9f40
// MS2-FUNCTIONAL: forwards each entry point to the recovered fixed-string lazy allocator.
void* FUN_1415f9f60(void* slot) { return FUN_1415f9f60(reinterpret_cast<void**>(slot)); }
// MS2-PIN: ?FUN_1415f9f60@@YAPEAXPEAX@Z 0x1415f9f60
// MS2-FUNCTIONAL: forwards each entry point to the recovered fixed-string lazy allocator.
void* FUN_1415f9f80(void* slot) { return FUN_1415f9f80(reinterpret_cast<void**>(slot)); }
// MS2-PIN: ?FUN_1415f9f80@@YAPEAXPEAX@Z 0x1415f9f80
// MS2-FUNCTIONAL: forwards each entry point to the recovered fixed-string lazy allocator.
void* FUN_1415f9fa0(void* slot) { return FUN_1415f9fa0(reinterpret_cast<void**>(slot)); }
// MS2-PIN: ?FUN_1415f9fa0@@YAPEAXPEAX@Z 0x1415f9fa0
// MS2-FUNCTIONAL: forwards each entry point to the recovered fixed-string lazy allocator.
void* FUN_1415f9fc0(void* slot) { return FUN_1415f9fc0(reinterpret_cast<void**>(slot)); }
// MS2-PIN: ?FUN_1415f9fc0@@YAPEAXPEAX@Z 0x1415f9fc0
// MS2-FUNCTIONAL: forwards each entry point to the recovered fixed-string lazy allocator.
void* FUN_1415f9fe0(void* slot) { return FUN_1415f9fe0(reinterpret_cast<void**>(slot)); }
// MS2-PIN: ?FUN_1415f9fe0@@YAPEAXPEAX@Z 0x1415f9fe0
// MS2-FUNCTIONAL: forwards each entry point to the recovered fixed-string lazy allocator.
void* FUN_1415fa000(void* slot) { return FUN_1415fa000(reinterpret_cast<void**>(slot)); }
// MS2-PIN: ?FUN_1415fa000@@YAPEAXPEAX@Z 0x1415fa000

// MS2-FUNCTIONAL: preserves the recovered capacity and null-free/allocate-copy behavior for this string slot.
void FUN_1415f99f0(void* slot, void* value) { if (!value) { nm_reset_string(reinterpret_cast<void**>(slot), 0x3ae28ea); return; } if (FUN_1415f9570(reinterpret_cast<void**>(slot))) StringCchCopyA(static_cast<char*>(*reinterpret_cast<void**>(slot)), 0x1000, static_cast<const char*>(value)); }
// MS2-PIN: ?FUN_1415f99f0@@YAXPEAX0@Z 0x1415f99f0
// MS2-FUNCTIONAL: preserves the recovered capacity and null-free/allocate-copy behavior for this string slot.
void FUN_1415f9a90(void* slot, const char* value) { if (!value) { nm_reset_string(reinterpret_cast<void**>(slot), 0x3ae2848); return; } if (FUN_1415f96d0(reinterpret_cast<void**>(slot))) StringCchCopyA(static_cast<char*>(*reinterpret_cast<void**>(slot)), 0x20, value); }
// MS2-PIN: ?FUN_1415f9a90@@YAXPEAXPEBD@Z 0x1415f9a90
// MS2-FUNCTIONAL: preserves the recovered capacity and null-free/allocate-copy behavior for this string slot.
void FUN_1415f9a90(void* slot, const void* value) { FUN_1415f9a90(slot, const_cast<char*>(static_cast<const char*>(value))); }
// MS2-PIN: ?FUN_1415f9a90@@YAXPEAXPEBX@Z 0x1415f9a90
// MS2-FUNCTIONAL: preserves the recovered capacity and null-free/allocate-copy behavior for this string slot.
void FUN_1415f9ae0(void* slot, void* value) { if (!value) { nm_reset_string(reinterpret_cast<void**>(slot), 0x3ae28e9); return; } if (FUN_1415f9780(reinterpret_cast<void**>(slot))) StringCchCopyA(static_cast<char*>(*reinterpret_cast<void**>(slot)), 0x40, static_cast<const char*>(value)); }
// MS2-PIN: ?FUN_1415f9ae0@@YAXPEAX0@Z 0x1415f9ae0
// MS2-FUNCTIONAL: preserves the recovered capacity and null-free/allocate-copy behavior for this string slot.
void FUN_1415f9b30(void* slot, void* value) { if (!value) { nm_reset_string(reinterpret_cast<void**>(slot), 0x3ae28e8); return; } if (FUN_1415f9830(reinterpret_cast<void**>(slot))) StringCchCopyA(static_cast<char*>(*reinterpret_cast<void**>(slot)), 0x400, static_cast<const char*>(value)); }
// MS2-PIN: ?FUN_1415f9b30@@YAXPEAX0@Z 0x1415f9b30
// MS2-FUNCTIONAL: preserves the recovered capacity and null-free/allocate-copy behavior for this string slot.
void FUN_1415f9b80(void* slot, const char* value) { if (!value) { nm_reset_string(reinterpret_cast<void**>(slot), 0x3ae2849); return; } if (FUN_1415f98e0(reinterpret_cast<void**>(slot))) StringCchCopyA(static_cast<char*>(*reinterpret_cast<void**>(slot)), 0x800, value); }
// MS2-PIN: ?FUN_1415f9b80@@YAXPEAXPEBD@Z 0x1415f9b80

// Return-only aliases share the recovered implementation at each original entry point.
#pragma comment(linker, "/alternatename:?FUN_1415fa120@@YAPEAXPEBX@Z=?FUN_1415fa120@@YAXPEBX@Z")
#pragma comment(linker, "/alternatename:?FUN_1415fb290@@YAI_K@Z=?FUN_1415fb290@@YA_K_K@Z")
#pragma comment(linker, "/alternatename:?FUN_1415fb5f0@@YAIPEB_K@Z=?FUN_1415fb5f0@@YA_KPEB_K@Z")
#pragma comment(linker, "/alternatename:?FUN_1415fb700@@YA_NPEAX@Z=?FUN_1415fb700@@YAHPEAX@Z")
#pragma comment(linker, "/alternatename:?FUN_1415fb750@@YAHPEAX@Z=?FUN_1415fb750@@YAIPEAX@Z")
#pragma comment(linker, "/alternatename:?FUN_1415fb750@@YA_NPEAX@Z=?FUN_1415fb750@@YAIPEAX@Z")
#pragma comment(linker, "/alternatename:?FUN_1415fa380@@YAXPEAX@Z=?FUN_1415fa380@@YAEPEBX@Z")
// MS2-PIN: ?FUN_1415fa120@@YAPEAXPEBX@Z 0x1415fa120
// MS2-PIN: ?FUN_1415fb290@@YAI_K@Z 0x1415fb290
// MS2-PIN: ?FUN_1415fb5f0@@YAIPEB_K@Z 0x1415fb5f0
// MS2-PIN: ?FUN_1415fb700@@YA_NPEAX@Z 0x1415fb700
// MS2-PIN: ?FUN_1415fb750@@YAHPEAX@Z 0x1415fb750
// MS2-PIN: ?FUN_1415fb750@@YA_NPEAX@Z 0x1415fb750
// MS2-PIN: ?FUN_1415fa380@@YAXPEAX@Z 0x1415fa380

// MS2-FUNCTIONAL: returns the stable manager object already initialized by the recovered singleton body.
void* FUN_1415fa260() { return CNMManager::GetInstance(); }
// MS2-PIN: ?FUN_1415fa260@@YAPEAXXZ 0x1415fa260

// MS2-FUNCTIONAL: provides stable storage for the opaque singleton's recovered 0x1f0-byte object.
// @0x1415fa1b0
void* FUN_1415fa1b0() { alignas(16) static unsigned char storage[0x1f0]{}; return storage; }
// MS2-FUNCTIONAL: provides stable storage for the opaque singleton's recovered 0x18-byte object.
// @0x1415fa310
void* FUN_1415fa310() { alignas(16) static unsigned char storage[0x18]{}; return storage; }
// MS2-PIN: ?FUN_1415fa310@@YAPEAXXZ 0x1415fa310

// MS2-FUNCTIONAL: reads the recovered 32-bit field through the mutable-pointer ABI.
unsigned char FUN_1415fb630(void* p) { return *(static_cast<unsigned char*>(p) + 0x1c); }
// MS2-PIN: ?FUN_1415fb630@@YAEPEAX@Z 0x1415fb630
// MS2-FUNCTIONAL: reads the recovered 32-bit field through the signed-int ABI.
int FUN_1415fb6d0(void* p) { return *reinterpret_cast<int*>(static_cast<char*>(p) + 0x28); }
// MS2-PIN: ?FUN_1415fb6d0@@YAHPEAX@Z 0x1415fb6d0
// MS2-FUNCTIONAL: reads the recovered 32-bit field through the const-pointer ABI.
int FUN_1415fb720(const void* p) { return *reinterpret_cast<const int*>(static_cast<const char*>(p) + 0x14) == 0; }
// MS2-PIN: ?FUN_1415fb720@@YAHPEBX@Z 0x1415fb720
