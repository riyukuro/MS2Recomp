// Recovered pair initialization wrappers from the Nexon Messenger library.
// MS2-UNIT: unit_1415cdf00
// MS2-RANGE: 0x1415cdf00-0x1415ce510 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmobjects.h"

extern void* FUN_1415e79b0(void*);
extern void* FUN_1415e5db0(void*);

extern void* FUN_1415e5db0(void*);
extern void* FUN_1415e7a00(void*);
extern void* FUN_1415e7a10(void*);
extern void* FUN_1415e7a20(void*);
extern void* FUN_1415e7a30(void*);
extern void* FUN_1415e7a40(void*);
extern void* FUN_1415e7a50(void*);
extern void* FUN_1415e7a60(void*);
extern void* FUN_1415e7a70(void*);
extern void* FUN_1415e7a80(void*);
extern void* FUN_1415e7a90(void*);
extern void* FUN_1415e7aa0(void*);
extern void* FUN_1415e7ab0(void*);
extern void* FUN_1415e7ac0(void*);
extern void* FUN_1415e7ad0(void*);
extern void* FUN_1415e7ae0(void*);
extern void* FUN_1415e7af0(void*);
extern void* FUN_1415e7b00(void*);
extern void* FUN_1415e7b10(void*);
extern void* FUN_1415e7b20(void*);
extern void* FUN_140162f70(void*);
extern void* FUN_140162f10(void*);
extern void* FUN_1406c42c0(void*);
extern void* FUN_1415e4be0(void*);
extern void* FUN_1415e4bc0(void*);
extern void* FUN_1415e4e90(void*);
extern void* FUN_1415e4eb0(void*);
extern void FUN_141064390(void*);

// MS2-FUNCTIONAL: the recovered helper sequence initializes the object storage; Ghidra loses the second argument type.
// @0x1415cdf00
void* FUN_1415cdf00(void* p, unsigned char)
{
    FUN_1415e79b0(p);
    FUN_1415e5db0(p);
    return p;
}

// MS2-FUNCTIONAL: copies the recovered 8-byte iterator and one-byte insertion result into the pair layout.
// @0x1415ce380
void* FUN_1415ce380(void* result, void* first, void* second)
{
    *static_cast<void**>(result) = *static_cast<void**>(FUN_1415e4be0(first));
    *reinterpret_cast<unsigned char*>(static_cast<char*>(result) + 8) =
        *static_cast<unsigned char*>(FUN_140162f70(second));
    return result;
}

// MS2-FUNCTIONAL: forwards the recovered boolean to the local tree-pair initializer after the allocator helper.
// @0x1415ce3d0
void* FUN_1415ce3d0(void* result, void*, void* third, void* fourth)
{
    FUN_141064390(third);
    FUN_1415cdf00(result, *static_cast<unsigned char*>(FUN_140162f10(fourth)));
    return result;
}

// @0x1415ce420
void* FUN_1415ce420(void* result, void* second, void* third)
{
    *static_cast<unsigned char*>(result) = *static_cast<unsigned char*>(FUN_1406c42c0(second));
    *reinterpret_cast<void**>(static_cast<char*>(result) + 8) = *static_cast<void**>(FUN_1415e4bc0(third));
    return result;
}

// MS2-FUNCTIONAL: copies the byte key and 8-byte mapped value from the recovered pair wrapper offsets.
// @0x1415ce470
void* FUN_1415ce470(void* result, long long second)
{
    *static_cast<unsigned char*>(result) = *static_cast<unsigned char*>(FUN_1406c42c0(reinterpret_cast<void*>(second)));
    *reinterpret_cast<void**>(static_cast<char*>(result) + 8) =
        *static_cast<void**>(FUN_1415e4e90(reinterpret_cast<void*>(second + 8)));
    return result;
}

// MS2-FUNCTIONAL: copies the recovered 8-byte iterator and one-byte insertion result into the pair layout.
// @0x1415ce4c0
void* FUN_1415ce4c0(void* result, void* second, void* third)
{
    *static_cast<void**>(result) = *static_cast<void**>(FUN_1415e4eb0(second));
    *reinterpret_cast<unsigned char*>(static_cast<char*>(result) + 8) =
        *static_cast<unsigned char*>(FUN_140162f70(third));
    return result;
}


// This unreachable helper forces MSVC to emit the vendor container constructor COMDATs used by this owner.
class CNMCodec;
__declspec(noinline) void force_nm_vector_ctor_symbols()
{
    std::vector<NMChatSessionTarget> v0;
    std::vector<NMFriendKey> v1;
    std::vector<CNMCateFriendInfo> v2;
    std::vector<CNMChannelMemberInfo> v3;
    std::vector<CNMCharacter> v4;
    std::vector<CNMChatRoomMemberInfo> v5;
    std::vector<CNMFileEvent> v6;
    std::vector<CNMFilePath> v7;
    std::vector<CNMFindUserInfo> v8;
    std::vector<CNMFriendInfo> v9;
    std::vector<CNMGameCode> v10;
    std::vector<CNMGameInfo> v11;
    std::vector<CNMGameServerCode> v12;
    std::vector<CNMGuildInfoEx> v13;
    std::vector<CNMGuildMemberInfo> v14;
    std::vector<CNMGuildMemberLevelInfo> v15;
    std::vector<CNMGuildOnlineInfoEx> v16;
    std::vector<CNMNoteInfo2> v17;
    std::vector<CNMNoteInfo> v18;
    std::vector<CNMRejectedUser> v19;
    std::vector<CNMSessionMemberInfo> v20;
    std::vector<CNMVirtualUserInfo> v21;
    std::vector<CNMSetServerInfoFunc::RequestInfo> v22;
    std::map<unsigned char, CNMCodec*> codecMap;
    (void)v0; (void)v1; (void)v2; (void)v3; (void)v4; (void)v5; (void)v6; (void)v7;
    (void)v8; (void)v9; (void)v10; (void)v11; (void)v12; (void)v13; (void)v14; (void)v15;
    (void)v16; (void)v17; (void)v18; (void)v19; (void)v20; (void)v21; (void)v22; (void)codecMap;
}

using ForceNmCtorSymbols = void (*)();
static ForceNmCtorSymbols volatile s_force_nm_ctor_symbols = &force_nm_vector_ctor_symbols;
