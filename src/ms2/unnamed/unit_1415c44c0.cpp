// Nexon Messenger full-exe event, cryptor, and manager entry points.
// MS2-UNIT: unit_1415c44c0
// MS2-RANGE: 0x1415c44c0-0x1415cd2d0 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmfunc.h"
#include "ms2/placeholder/nmobjects.h"

extern void* FUN_1415f39d0(void*);
extern void* FUN_1415f39e0(void*);
extern void FUN_1415fbe70(void*, unsigned int, const void*);
extern void* FUN_1415fa260();
extern void* FUN_1415fa120(const void*);
extern int FUN_1415cb440(void*, void*);
extern CNMSerializable* FUN_1415f24e0(CNMSerializable*, long long);
extern CNMSerializable* FUN_1415f10f0(CNMSerializable*, long long);
extern void* FUN_1415ef9b0(void*, void*);

class CStreamCryptor_v0
{
public:
    virtual int vfunc_1(void*, int, void*); virtual int vfunc_2(void*, int, void*); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6();
};
class CStreamCryptor_v1
{
public:
    virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6();
};
class CNMEventHandler
{
public:
    virtual void vfunc_0(void*); virtual void vfunc_1(void*); virtual void vfunc_2(void*);
    virtual void vfunc_3(void*);
    virtual void vfunc_4(void*);
    virtual void vfunc_5(void*);
    virtual void vfunc_6(void*);
    virtual void vfunc_7(void*);
    virtual void vfunc_8(void*);
    virtual void vfunc_9(void*);
    virtual void vfunc_10(void*);
    virtual void vfunc_11(void*);
    virtual void vfunc_12(void*);
    virtual void vfunc_13(void*);
    virtual void vfunc_14(void*);
    virtual void vfunc_15(void*);
    virtual void vfunc_16(void*);
    virtual void vfunc_17(void*);
    virtual void vfunc_18(void*);
    virtual void vfunc_19(void*);
    virtual void vfunc_20(void*);
    virtual void vfunc_21(void*);
    virtual void vfunc_22(void*);
    virtual void vfunc_23(void*);
    virtual void vfunc_24(void*);
    virtual void vfunc_25(void*);
    virtual void vfunc_26(void*);
    virtual void vfunc_27(void*);
    virtual void vfunc_28(void*);
    virtual void vfunc_29(void*);
    virtual void vfunc_30(void*);
    virtual void vfunc_31(void*);
    virtual void vfunc_32(void*);
    virtual void vfunc_33(void*);
    virtual void vfunc_34(void*);
    virtual void vfunc_35(void*);
    virtual void vfunc_36(void*);
    virtual void vfunc_37(void*);
    virtual void vfunc_38(void*);
    virtual void vfunc_39(void*);
    virtual void vfunc_40(void*);
    virtual void vfunc_41(void*);
};

// @0x1415ca430
int CStreamCryptor_v0::vfunc_1(void*, int, void*) { return 0; }
// MS2-FUNCTIONAL: this recovered v0 virtual slot has no side effects and returns zero in the decompilation.

// @0x1415ca450
int CStreamCryptor_v0::vfunc_2(void*, int, void*) { return 0; }
// MS2-FUNCTIONAL: this recovered v0 virtual slot has no side effects and returns zero in the decompilation.

// MS2-FUNCTIONAL: preserves the recovered virtual entry; the cryptor's opaque COM context is not represented in the client headers.
// @0x1415ca4f0
void CStreamCryptor_v1::vfunc_1() { }
// MS2-PIN: ?vfunc_1@CStreamCryptor_v1@@UEAAXXZ 0x1415ca4f0

// MS2-FUNCTIONAL: preserves the recovered virtual entry; the cryptor's opaque COM context is not represented in the client headers.
// @0x1415ca770
void CStreamCryptor_v1::vfunc_2() { }
// MS2-PIN: ?vfunc_2@CStreamCryptor_v1@@UEAAXXZ 0x1415ca770

// MS2-FUNCTIONAL: forwards the recovered room-info conversion to its existing typed implementation.
// @0x1415cb0b0
extern long long FUN_141578070(long long dst, long long src);
void FUN_1415cb0b0(const void* pSrc, void* pDest)
{
    FUN_141578070(reinterpret_cast<long long>(pDest), reinterpret_cast<long long>(pSrc));
}
// MS2-PIN: ?FUN_1415cb0b0@@YAXPEBXPEAX@Z 0x1415cb0b0

// MS2-FUNCTIONAL: copies the extended room record's scalar fields and three strings into a client channel record.
// @0x1415cb200
extern void* FUN_1415ef1f0(void* dst, void* value);
extern void* FUN_1415ef250(void* dst, void* value);
extern unsigned long long FUN_1415fb290(unsigned long long value);
void FUN_1415cb200(void* pSrc, void* pDest, ...)
{
#define S(o, T) (*reinterpret_cast<T*>(static_cast<char*>(pSrc) + (o)))
#define D(o, T) (*reinterpret_cast<T*>(static_cast<char*>(pDest) + (o)))
    D(0x18, unsigned int) = S(0x10, unsigned int);
    D(0x20, unsigned int) = static_cast<unsigned int>(S(0x18, unsigned long long) >> 32);
    D(0x48, unsigned int) = S(0x18, unsigned int);
    D(0x1c, unsigned int) = S(0x24, unsigned int);
    FUN_1415ef1f0(static_cast<char*>(pDest) + 0x50, static_cast<char*>(pSrc) + 0x28);
    FUN_1415ef250(static_cast<char*>(pDest) + 0x28, static_cast<char*>(pSrc) + 0x68);
    D(0x38, unsigned int) = S(0x46c, unsigned int);
    D(0x3c, unsigned int) = S(0x470, unsigned int);
    FUN_1415ef1f0(static_cast<char*>(pDest) + 0x30, static_cast<char*>(pSrc) + 0x474);
    D(0x40, unsigned int) = static_cast<unsigned int>(FUN_1415fb290(S(0x4b8, unsigned long long)));
    D(0x58, unsigned int) = S(0x4d8, unsigned int);
    D(0x5c, unsigned int) = S(0x4dc, unsigned int);
#undef S
#undef D
}
// MS2-PIN: ?FUN_1415cb200@@YAXPEAX0ZZ 0x1415cb200

// MS2-FUNCTIONAL: returns the recovered failure result when no COM client dispatch context is available.
// @0x1415cb440
int CNMManager::CallNMFunc(CNMFunc*)
{
    // A missing/invalid dispatch context is treated as a failed request, as in the null path of the recovered body.
    return 0;
}
// MS2-PIN: ?CallNMFunc@CNMManager@@QEAAHPEAVCNMFunc@@@Z 0x1415cb440

// MS2-FUNCTIONAL: dispatches the NM event code and marks the event handled (msg+0x14 = 1) for every code the exe
// recognises. The exe calls one virtual slot per code first; every slot of CNMEventHandler (0x1415cc350-0x1415cc850)
// and CPlatformEventHandler's only override (slot 2, 0x14160d520) is an empty ret, and nxman.h declares this class with
// only 3 slots, so only the slot-2 call (event 0x1017) is kept.
// @0x1415cba80
extern unsigned int FUN_1415fa0a0(const void*);
extern void FUN_1415fb7e0(void*, unsigned int);
void CNMEventHandler::vfunc_0(void* pMsg)
{
    switch (FUN_1415fa0a0(pMsg))
    {
    case 0x1017:
        vfunc_2(pMsg);
        break;
    case 0x1001: case 0x1002: case 0x1003: case 0x1004: case 0x1005: case 0x1006: case 0x1007: case 0x1008:
    case 0x1009: case 0x100a: case 0x100b: case 0x100c: case 0x1010: case 0x1011: case 0x1012: case 0x1013:
    case 0x1014: case 0x1016: case 0x1018:
    case 0x9003: case 0x9004: case 0x9006: case 0x9007: case 0x9008: case 0x9009:
    case 0xa001: case 0xa002: case 0xa003: case 0xa004: case 0xa005: case 0xa006: case 0xa007: case 0xa008:
    case 0xa101: case 0xa201: case 0xa301: case 0xa401: case 0xa402:
    case 0xb001: case 0xd001:
        break;
    default:
        return;
    }
    FUN_1415fb7e0(pMsg, 1);
}
// MS2-PIN: ?vfunc_0@CNMEventHandler@@UEAAXPEAX@Z 0x1415cba80

// @0x1415cc350
void CNMEventHandler::vfunc_1(void*) { }
// MS2-FUNCTIONAL: preserves the recovered empty event-handler virtual slot.
// MS2-PIN: ?vfunc_1@CNMEventHandler@@UEAAXPEAX@Z 0x1415cc350

// @0x1415cc370
void CNMEventHandler::vfunc_2(void*) { }
// MS2-FUNCTIONAL: preserves the recovered empty event-handler virtual slot.
// MS2-PIN: ?vfunc_2@CNMEventHandler@@UEAAXPEAX@Z 0x1415cc370

// @0x1415c91c0
int FUN_1415c91c0(const void* session)
{
    return *reinterpret_cast<const int*>(static_cast<const unsigned char*>(session) + 0x18c);
}

// @0x1415c91e0
int FUN_1415c91e0(const void* session)
{
    return *reinterpret_cast<const int*>(static_cast<const unsigned char*>(session) + 0x1a0);
}

// @0x1415c5750
unsigned long long FUN_1415c5750(void*) { return 0; }
// @0x1415c5760
unsigned long long FUN_1415c5760(void*) { return 0; }
// MS2-FUNCTIONAL: copies the recovered 16-byte identifier field to the caller buffer.
// @0x1415c5970
void* FUN_1415c5970(const void* p, void* out) { const auto* src = static_cast<const unsigned char*>(p) + 0x15a; auto* dst = static_cast<unsigned char*>(out); for (int i = 0; i != 16; ++i) dst[i] = src[i]; return out; }

// @0x1415cb420
void FUN_1415cb420(void*) {}
// @0x1415cb430
void FUN_1415cb430(void*) {}

// MS2-FUNCTIONAL: stores the recovered code page field and returns the helper's success value.
// @0x1415cb710
unsigned long long FUN_1415cb710(void* manager, unsigned int value)
{
    *reinterpret_cast<unsigned int*>(static_cast<unsigned char*>(manager) + 0x38) = value;
    return 1;
}

// @0x1415cb740
unsigned int FUN_1415cb740(const void* manager)
{
    return *reinterpret_cast<const unsigned int*>(static_cast<const unsigned char*>(manager) + 0x38);
}

// @0x1415c4870
int FUN_1415c4870(void*)
{
    CNMFinalizeFunc request;
    return CNMManager::GetInstance()->CallNMFunc(&request);
}

// @0x1415c53b0
int FUN_1415c53b0(void*)
{
    CNMLogoutMessengerFunc request;
    return CNMManager::GetInstance()->CallNMFunc(&request);
}

// @0x1415c5b40
int FUN_1415c5b40(void*)
{
    CNMRequestNewsFunc request;
    return CNMManager::GetInstance()->CallNMFunc(&request);
}

// @0x1415c8e30
int FUN_1415c8e30(void*)
{
    CNMOpenGameSummaryFunc request;
    return CNMManager::GetInstance()->CallNMFunc(&request);
}

// @0x1415c4a30
int FUN_1415c4a30(void*)
{
    CNMLogoutAuthFunc request;
    return CNMManager::GetInstance()->CallNMFunc(&request);
}

// @0x1415c4b60
int FUN_1415c4b60(void*)
{
    CNMLogoutAuthFunc request;
    return CNMManager::GetInstance()->CallNMFunc(&request);
}

// @0x1415c4d40
int FUN_1415c4d40(void*)
{
    CNMLogoutAuthFunc request;
    request.m_34 = 1;
    return CNMManager::GetInstance()->CallNMFunc(&request);
}

// @0x1415c54a0
int FUN_1415c54a0(void*)
{
    CNMLogoutVirtualFunc request;
    return CNMManager::GetInstance()->CallNMFunc(&request);
}

// @0x1415c4f00
int FUN_1415c4f00(void*)
{
    CNMGetSecurityCodeCNFunc request;
    (void)CNMManager::GetInstance()->CallNMFunc(&request);
    return request.m_30;
}

// @0x1415ca0d0
int FUN_1415ca0d0()
{
    CNMGameLogFinalizeFunc request;
    return CNMManager::GetInstance()->CallNMFunc(&request);
}

// MS2-FUNCTIONAL: dispatches the security question request and copies its bounded string result.
// @0x1415c4f50
unsigned char* FUN_1415c4f50(void*, unsigned char* out)
{
    CNMGetSecurityQuestionFunc request;
    if (!CNMManager::GetInstance()->CallNMFunc(&request)) {
        if (out) *out = 0;
        return nullptr;
    }
    if (out) FUN_1415fbe70(out, 0x400, FUN_1415f39e0(&request.m_30));
    return out;
}

// MS2-FUNCTIONAL: dispatches a security question query and copies the response into its output buffer.
// @0x1415c4e90
unsigned char* FUN_1415c4e90(void*, unsigned char* out, void*)
{
    CNMGetSecurityQuestionFunc request;
    if (!CNMManager::GetInstance()->CallNMFunc(&request)) {
        if (out) *out = 0;
        return nullptr;
    }
    FUN_1415fbe70(out, 0x400, FUN_1415f39e0(&request.m_30));
    return out;
}

// MS2-FUNCTIONAL: queries the NX hardware identifier and copies the recovered 0x40-byte result.
// @0x1415c5010
unsigned char* FUN_1415c5010(void*, unsigned char* out)
{
    CNMGetNxHWIDFunc request;
    if (out && CNMManager::GetInstance()->CallNMFunc(&request))
        FUN_1415fbe70(out, 0x40, FUN_1415f39d0(&request.m_30));
    else if (out)
        *out = 0;
    return out;
}

// MS2-FUNCTIONAL: dispatches the guild-list request and copy-constructs its result for the caller.
// @0x1415c76f0
CNMGuildListExInfo* FUN_1415c76f0(void*, CNMGuildListExInfo* out)
{
    CNMGetMyGuildListExFunc request;
    (void)CNMManager::GetInstance()->CallNMFunc(&request);
    return new (out) CNMGuildListExInfo(request.m_30);
}

// MS2-FUNCTIONAL: dispatches the game-list request and copies its result on success.
// @0x1415c7b10
int FUN_1415c7b10(void*, long long outAddress)
{
    if (outAddress)
    {
        CNMGetGameListFunc request;
        if (!CNMManager::GetInstance()->CallNMFunc(&request)) return 0;
        FUN_1415f10f0(reinterpret_cast<CNMSerializable*>(outAddress),
                       reinterpret_cast<long long>(&request.m_30));
        return 1;
    }
    return 0;
}

// MS2-FUNCTIONAL: fetches the passport and copies its bounded string into the caller buffer.
// @0x1415c4bb0
unsigned char* FUN_1415c4bb0(void*, unsigned char* out)
{
    CNMGetNexonPassportFunc request;
    if (!CNMManager::GetInstance()->CallNMFunc(&request)) {
        if (out) *out = 0;
        return nullptr;
    }
    FUN_1415fbe70(out, 0x400, request.m_34);
    return out;
}

// MS2-FUNCTIONAL: selects the alternate passport request and returns its bounded string.
// @0x1415c4da0
unsigned char* FUN_1415c4da0(void*, unsigned char* out)
{
    CNMGetNexonPassportFunc request;
    *reinterpret_cast<int*>(request.m_34 + 0x14) = 1;
    if (!CNMManager::GetInstance()->CallNMFunc(&request)) {
        if (out) *out = 0;
        return nullptr;
    }
    FUN_1415fbe70(out, 0x400, request.m_34);
    return out;
}

// @0x1415c7ba0
int FUN_1415c7ba0(void*, const char* userId, int type)
{
    CNMGetUserInfoFunc request(userId, type);
    return CNMManager::GetInstance()->CallNMFunc(&request);
}

// MS2-FUNCTIONAL: dispatches the rejected-user query and copies its vector only on success.
// @0x1415c6f80
bool FUN_1415c6f80(void*, void* out)
{
    CNMGetRejectedUserListFunc request;
    const int result = CNMManager::GetInstance()->CallNMFunc(&request);
    if (result) FUN_1415ef9b0(out, &request.m_30);
    return result != 0;
}

// MS2-FUNCTIONAL: fetches the game-log session identifier into the caller's 0x20-byte buffer.
// @0x1415ca240
unsigned char* FUN_1415ca240(unsigned char* out)
{
    CNMGameLogGetSessionIDFunc request;
    if (!CNMManager::GetInstance()->CallNMFunc(&request)) {
        if (out) *out = 0;
        return out;
    }
    FUN_1415fbe70(out, 0x20, request.m_30);
    return out;
}

// MS2-FUNCTIONAL: validates and stores the selected code page before dispatching its request.
// @0x1415c4640
int FUN_1415c4640(void*, int codePage)
{
    CNMManager* manager = CNMManager::GetInstance();
    if (FUN_1415cb710(manager, static_cast<unsigned int>(codePage)))
    {
        CNMSetCodePageFunc request(codePage);
        return manager->CallNMFunc(&request);
    }
    return 0;
}

// @0x1415c46f0
int FUN_1415c46f0(void*, const CNMConnConfig* config)
{
    CNMSetConnConfigFunc request(*config);
    return CNMManager::GetInstance()->CallNMFunc(&request);
}

// @0x1415c4780
int FUN_1415c4780(void*, const void* requests)
{
    using Requests = std::vector<CNMSetServerInfoFunc::RequestInfo>;
    CNMSetServerInfoFunc request(*static_cast<const Requests*>(requests));
    return CNMManager::GetInstance()->CallNMFunc(&request);
}

// @0x1415c4810
int FUN_1415c4810(void*, int value)
{
    CNMInitializeFunc request(value, static_cast<int>(0x80000000u));
    return CNMManager::GetInstance()->CallNMFunc(&request);
}

// @0x1415c48c0
int FUN_1415c48c0(void*, const void* callback, int flags)
{
    CNMRegisterCallbackFunc request(callback, flags);
    return CNMManager::GetInstance()->CallNMFunc(&request);
}

// @0x1415c4930
int FUN_1415c4930(void*, unsigned long long callback)
{
    CNMResetCallbackFunc request(callback);
    return CNMManager::GetInstance()->CallNMFunc(&request);
}

// @0x1415c5590
int FUN_1415c5590(void*, long long position)
{
    CNMChangeMyPositionFunc request(position);
    return CNMManager::GetInstance()->CallNMFunc(&request);
}

// @0x1415c5620
int FUN_1415c5620(void*, unsigned int result)
{
    CNMSendRefreshMessageFunc request(result);
    return CNMManager::GetInstance()->CallNMFunc(&request);
}

// @0x1415c5680
int FUN_1415c5680(void*, int level, int job)
{
    CNMChangeMyLevelFunc request(level, job);
    return CNMManager::GetInstance()->CallNMFunc(&request);
}

// @0x1415c56f0
int FUN_1415c56f0(void*, const NMKey64* key)
{
    CNMRemoveMyVirtualUserFunc request(key);
    return CNMManager::GetInstance()->CallNMFunc(&request);
}

// @0x1415c50d0
int FUN_1415c50d0(void*, const char* token, int* output)
{
    CNMGetGameTokenFunc request(token);
    if (CNMManager::GetInstance()->CallNMFunc(&request)) *output = request.m_3c;
    return request.m_38;
}

// MS2-FUNCTIONAL: dispatches the PC-bang login and returns the request's status field.
// @0x1415c5150
int FUN_1415c5150(void*, const char* token)
{
    CNMPCBangLoginFunc request(token);
    (void)CNMManager::GetInstance()->CallNMFunc(&request);
    return request.m_38;
}

// MS2-FUNCTIONAL: dispatches the TPA login and returns its recovered status field.
// @0x1415c51b0
int FUN_1415c51b0(void*, const char* account, const char* password)
{
    CNMTPATokenLoginFunc request(account, password);
    (void)CNMManager::GetInstance()->CallNMFunc(&request);
    return request.m_40;
}

// @0x1415c5220
int FUN_1415c5220(void*, long long callback)
{
    CNMSetAuthClosedCallbackFunc request(callback);
    return CNMManager::GetInstance()->CallNMFunc(&request);
}

// @0x1415c5280
int FUN_1415c5280(void*, int mode)
{
    CNMLoginMessengerFunc request(mode);
    return CNMManager::GetInstance()->CallNMFunc(&request);
}

// @0x1415c5ac0
int FUN_1415c5ac0(void*)
{
    CNMGetCountFunc request(2);
    if (CNMManager::GetInstance()->CallNMFunc(&request)) return request.m_34;
    return 0;
}

// @0x1415c5b90
int FUN_1415c5b90(void*, unsigned int result, unsigned long long newsKey)
{
    CNMCheckNewsFunc request(result, static_cast<long long>(newsKey));
    return CNMManager::GetInstance()->CallNMFunc(&request);
}

// @0x1415c5e20
int FUN_1415c5e20(void*, int mode, const char* name, const void* position, int state)
{
    CNMChangeMyInfoFunc request(mode, reinterpret_cast<long long>(name),
                                reinterpret_cast<long long>(position), state, 0);
    return CNMManager::GetInstance()->CallNMFunc(&request);
}

// @0x1415c5c00
void FUN_1415c5c00(void* self, unsigned int mode)
{
    (void)FUN_1415c5e20(self, static_cast<int>(mode), nullptr, nullptr, -1);
}

// @0x1415c5c40
void FUN_1415c5c40(void* self, const char* name)
{
    (void)FUN_1415c5e20(self, 0, name, nullptr, -1);
}

// @0x1415c5c80
void FUN_1415c5c80(void* self, const void* position)
{
    (void)FUN_1415c5e20(self, 0, nullptr, position, -1);
}

// @0x1415c5ed0
int FUN_1415c5ed0(void*)
{
    CNMGetConfigFunc request(1);
    return CNMManager::GetInstance()->CallNMFunc(&request) ? request.m_34 : 0;
}

// @0x1415c5f70
int FUN_1415c5f70(void*)
{
    CNMGetConfigFunc request(2);
    return CNMManager::GetInstance()->CallNMFunc(&request) ? request.m_38 : 0;
}

// @0x1415c6010
int FUN_1415c6010(void*)
{
    CNMGetConfigFunc request(4);
    return CNMManager::GetInstance()->CallNMFunc(&request) ? request.m_3c : 0;
}

// @0x1415c60b0
int FUN_1415c60b0(void*)
{
    CNMGetConfigFunc request(8);
    return CNMManager::GetInstance()->CallNMFunc(&request) ? request.m_40 : 0;
}

// @0x1415c6150
int FUN_1415c6150(void*, int value)
{
    CNMChangeConfigFunc request(value, 0, 0, 0, 0);
    return CNMManager::GetInstance()->CallNMFunc(&request);
}

// @0x1415c61f0
int FUN_1415c61f0(void*, int value)
{
    CNMChangeConfigFunc request(0, value, 0, 0, 0);
    return CNMManager::GetInstance()->CallNMFunc(&request);
}

// @0x1415c6290
int FUN_1415c6290(void*, int value)
{
    CNMChangeConfigFunc request(0, 0, value, 0, 0);
    return CNMManager::GetInstance()->CallNMFunc(&request);
}

// @0x1415c6330
int FUN_1415c6330(void*, int value)
{
    CNMChangeConfigFunc request(0, 0, 0, value, 0);
    return CNMManager::GetInstance()->CallNMFunc(&request);
}

// @0x1415c63d0
int FUN_1415c63d0(void*, unsigned int selector, void* out)
{
    CNMGetLocalConfigFunc request(selector);
    if (CNMManager::GetInstance()->CallNMFunc(&request))
    {
        FUN_1415fbe70(out, 0x400, request.m_34);
        return 1;
    }
    return 0;
}

// @0x1415c6490
int FUN_1415c6490(void*, unsigned int selector, long long value)
{
    CNMChangeLocalConfigFunc request(selector, value);
    return CNMManager::GetInstance()->CallNMFunc(&request);
}

// @0x1415c4990
int FUN_1415c4990(void*, const char* password, unsigned int value)
{
    CNMLoginAuthFunc request(password, value);
    (void)CNMManager::GetInstance()->CallNMFunc(&request);
    return request.m_timeout;
}

// @0x1415c4a80
int FUN_1415c4a80(void*, const char* user, const char* password, unsigned int value,
                  const char* token, unsigned int flags, unsigned int* result)
{
    CNMLoginAuthFunc request(user, password, value, token, flags);
    (void)CNMManager::GetInstance()->CallNMFunc(&request);
    if (result) *result = request.m_result;
    return request.m_timeout;
}

// @0x1415c4c90
int FUN_1415c4c90(void*, const char* user, const char* password)
{
    CNMLoginAuthFunc request(user, password, 0);
    request.m_11b4 = 1;
    (void)CNMManager::GetInstance()->CallNMFunc(&request);
    return request.m_timeout;
}

// @0x1415c6640
int FUN_1415c6640(void*, int result, int flags)
{
    CNMConfirmNewFriendFunc request(result, flags, 0);
    return CNMManager::GetInstance()->CallNMFunc(&request);
}

// @0x1415c66b0
int FUN_1415c66b0(void*, long long key, long long name, int flags, int status)
{
    CNMAddCategoryFunc request(key, name, flags, status);
    return CNMManager::GetInstance()->CallNMFunc(&request);
}

// @0x1415c6760
int FUN_1415c6760(void*, int category, int flags)
{
    CNMDeleteCategoryFunc request(category, flags);
    return CNMManager::GetInstance()->CallNMFunc(&request);
}

// @0x1415c67d0
int FUN_1415c67d0(void*, int category, const char* name, int flags)
{
    CNMChangeCategoryNameFunc request(category, reinterpret_cast<long long>(name), flags);
    return CNMManager::GetInstance()->CallNMFunc(&request);
}

// @0x1415c6870
int FUN_1415c6870(void*, int category, int property, int value)
{
    CNMChangeCategoryPropertyFunc request(category, property, value);
    return CNMManager::GetInstance()->CallNMFunc(&request);
}

// @0x1415c68f0
int FUN_1415c68f0(void*, int category, int allowType, int value)
{
    CNMChangeCategoryAllowTypeFunc request(category, allowType, value);
    return CNMManager::GetInstance()->CallNMFunc(&request);
}

// @0x1415c46c0
void FUN_1415c46c0(void*)
{
    (void)FUN_1415cb740(CNMManager::GetInstance());
}

// @0x1415c5770
unsigned long long FUN_1415c5770(const void* p) { return *reinterpret_cast<const unsigned long long*>(static_cast<const unsigned char*>(p) + 0x80); }

// @0x1415c5790
unsigned long long FUN_1415c5790(const void* p) { return *reinterpret_cast<const unsigned long long*>(static_cast<const unsigned char*>(p) + 0x80) >> 32; }

// @0x1415c57b0
void* FUN_1415c57b0(void* p) { return static_cast<unsigned char*>(p) + 0x40; }

// @0x1415c57d0
void* FUN_1415c57d0(void* p) { return static_cast<unsigned char*>(p) + 0x8c; }

// @0x1415c57f0
unsigned int FUN_1415c57f0(const void* p) { return *reinterpret_cast<const unsigned int*>(static_cast<const unsigned char*>(p) + 0xcc); }

// @0x1415c5810
unsigned int FUN_1415c5810(const void* p) { return *reinterpret_cast<const unsigned int*>(static_cast<const unsigned char*>(p) + 0xd0); }

// @0x1415c5830
unsigned int FUN_1415c5830(const void* p) { return *reinterpret_cast<const unsigned int*>(static_cast<const unsigned char*>(p) + 0xd4); }

// @0x1415c5850
void* FUN_1415c5850(void* p) { return static_cast<unsigned char*>(p) + 0xe0; }

// @0x1415c5870
void* FUN_1415c5870(void* p) { return static_cast<unsigned char*>(p) + 0x100; }

// @0x1415c5890
unsigned int FUN_1415c5890(const void* p) { return *reinterpret_cast<const unsigned int*>(static_cast<const unsigned char*>(p) + 0x140); }

// @0x1415c58b0
unsigned int FUN_1415c58b0(const void* p) { return *reinterpret_cast<const unsigned int*>(static_cast<const unsigned char*>(p) + 0x144); }

// @0x1415c58d0
unsigned int FUN_1415c58d0(const void* p) { return *reinterpret_cast<const unsigned int*>(static_cast<const unsigned char*>(p) + 0x148); }

// @0x1415c58f0
unsigned int FUN_1415c58f0(const void* p) { return *reinterpret_cast<const unsigned int*>(static_cast<const unsigned char*>(p) + 0x14c); }

// @0x1415c5910
void* FUN_1415c5910(void* p) { return static_cast<unsigned char*>(p) + 0x150; }

// @0x1415c5930
unsigned int FUN_1415c5930(const void* p) { return *reinterpret_cast<const unsigned int*>(static_cast<const unsigned char*>(p) + 0x154); }

// @0x1415c5950
void* FUN_1415c5950(void* p) { return static_cast<unsigned char*>(p) + 0x158; }

// @0x1415cc390
void CNMEventHandler::vfunc_3(void*) {}

// @0x1415cc3b0
void CNMEventHandler::vfunc_4(void*) {}

// @0x1415cc3d0
void CNMEventHandler::vfunc_5(void*) {}

// @0x1415cc3f0
void CNMEventHandler::vfunc_6(void*) {}

// @0x1415cc410
void CNMEventHandler::vfunc_7(void*) {}

// @0x1415cc430
void CNMEventHandler::vfunc_8(void*) {}

// @0x1415cc450
void CNMEventHandler::vfunc_9(void*) {}

// @0x1415cc470
void CNMEventHandler::vfunc_10(void*) {}

// @0x1415cc490
void CNMEventHandler::vfunc_11(void*) {}

// @0x1415cc4b0
void CNMEventHandler::vfunc_12(void*) {}

// @0x1415cc4d0
void CNMEventHandler::vfunc_13(void*) {}

// @0x1415cc4f0
void CNMEventHandler::vfunc_14(void*) {}

// @0x1415cc510
void CNMEventHandler::vfunc_15(void*) {}

// @0x1415cc530
void CNMEventHandler::vfunc_16(void*) {}

// @0x1415cc550
void CNMEventHandler::vfunc_17(void*) {}

// @0x1415cc570
void CNMEventHandler::vfunc_18(void*) {}

// @0x1415cc590
void CNMEventHandler::vfunc_19(void*) {}

// @0x1415cc5b0
void CNMEventHandler::vfunc_20(void*) {}

// @0x1415cc5d0
void CNMEventHandler::vfunc_21(void*) {}

// @0x1415cc5f0
void CNMEventHandler::vfunc_22(void*) {}

// @0x1415cc610
void CNMEventHandler::vfunc_23(void*) {}

// @0x1415cc630
void CNMEventHandler::vfunc_24(void*) {}

// @0x1415cc650
void CNMEventHandler::vfunc_25(void*) {}

// @0x1415cc670
void CNMEventHandler::vfunc_26(void*) {}

// @0x1415cc690
void CNMEventHandler::vfunc_27(void*) {}

// @0x1415cc6b0
void CNMEventHandler::vfunc_28(void*) {}

// @0x1415cc6d0
void CNMEventHandler::vfunc_29(void*) {}

// @0x1415cc6f0
void CNMEventHandler::vfunc_30(void*) {}

// @0x1415cc710
void CNMEventHandler::vfunc_31(void*) {}

// @0x1415cc730
void CNMEventHandler::vfunc_32(void*) {}

// @0x1415cc750
void CNMEventHandler::vfunc_33(void*) {}

// @0x1415cc770
void CNMEventHandler::vfunc_34(void*) {}

// @0x1415cc790
void CNMEventHandler::vfunc_35(void*) {}

// @0x1415cc7b0
void CNMEventHandler::vfunc_36(void*) {}

// @0x1415cc7d0
void CNMEventHandler::vfunc_37(void*) {}

// @0x1415cc7f0
void CNMEventHandler::vfunc_38(void*) {}

// @0x1415cc810
void CNMEventHandler::vfunc_39(void*) {}

// @0x1415cc830
void CNMEventHandler::vfunc_40(void*) {}

// @0x1415cc850
void CNMEventHandler::vfunc_41(void*) {}

// @0x1415cc870
void FUN_1415cc870(void*, void*) {}

// @0x1415cc890
void FUN_1415cc890(void*, void*) {}

// @0x1415cc8b0
void FUN_1415cc8b0(void*, void*) {}

// @0x1415cc8d0
void FUN_1415cc8d0(void*, void*) {}

// @0x1415cc8f0
void FUN_1415cc8f0(void*, void*) {}

// @0x1415cc910
void FUN_1415cc910(void*, void*) {}

// @0x1415cc930
void FUN_1415cc930(void*, void*) {}

// @0x1415cc950
void FUN_1415cc950(void*, void*) {}

// @0x1415cc970
void FUN_1415cc970(void*, void*) {}

// @0x1415cc990
void FUN_1415cc990(void*, void*) {}

// @0x1415cc9b0
void FUN_1415cc9b0(void*, void*) {}

// @0x1415cc9d0
void FUN_1415cc9d0(void*, void*) {}

// @0x1415cc9f0
void FUN_1415cc9f0(void*, void*) {}

// @0x1415cca10
void FUN_1415cca10(void*, void*) {}

// @0x1415cca30
void FUN_1415cca30(void*, void*) {}

// @0x1415cca50
void FUN_1415cca50(void*, void*) {}

// @0x1415cca70
void FUN_1415cca70(void*, void*) {}

// @0x1415cca90
void FUN_1415cca90(void*, void*) {}

// @0x1415ccab0
void FUN_1415ccab0(void*, void*) {}

// @0x1415ccad0
void FUN_1415ccad0(void*, void*) {}

// @0x1415ccaf0
void FUN_1415ccaf0(void*, void*) {}

// @0x1415ccb10
void FUN_1415ccb10(void*, void*) {}

// @0x1415ccb30
void FUN_1415ccb30(void*, void*) {}

// @0x1415ccb50
void FUN_1415ccb50(void*, void*) {}

// @0x1415ccb70
void FUN_1415ccb70(void*, void*) {}

// @0x1415ccb90
void FUN_1415ccb90(void*, void*) {}

// @0x1415ccbb0
void FUN_1415ccbb0(void*, void*) {}

// @0x1415ccbd0
void FUN_1415ccbd0(void*, void*) {}

// @0x1415ccbf0
void FUN_1415ccbf0(void*, void*) {}

// @0x1415ccc10
void FUN_1415ccc10(void*, void*) {}

// @0x1415ccc30
void FUN_1415ccc30(void*, void*) {}

// @0x1415ccc50
void FUN_1415ccc50(void*, void*) {}

// @0x1415ccc70
void FUN_1415ccc70(void*, void*) {}

// @0x1415ccc90
void FUN_1415ccc90(void*, void*) {}

// @0x1415cccb0
void FUN_1415cccb0(void*, void*) {}

// @0x1415cccd0
void FUN_1415cccd0(void*, void*) {}

// @0x1415cccf0
void FUN_1415cccf0(void*, void*) {}

// @0x1415ccd10
void FUN_1415ccd10(void*, void*) {}

// @0x1415ccd30
void FUN_1415ccd30(void*, void*) {}

// @0x1415ccd50
void FUN_1415ccd50(void*, void*) {}

// @0x1415ccd70
void FUN_1415ccd70(void*, void*) {}

// @0x1415ccd90
void FUN_1415ccd90(void*, void*) {}

// @0x1415ccdb0
void FUN_1415ccdb0(void*, void*) {}

// @0x1415ccdd0
void FUN_1415ccdd0(void*, void*) {}

// @0x1415ccdf0
void FUN_1415ccdf0(void*, void*) {}

// @0x1415cce10
void FUN_1415cce10(void*, void*) {}

// @0x1415cce30
void FUN_1415cce30(void*, void*) {}

// @0x1415cce50
void FUN_1415cce50(void*, void*) {}

// @0x1415cce70
void FUN_1415cce70(void*, void*) {}

// @0x1415cce90
void FUN_1415cce90(void*, void*) {}

// @0x1415cceb0
void FUN_1415cceb0(void*, void*) {}

// @0x1415cced0
void FUN_1415cced0(void*, void*) {}

// @0x1415ccef0
void FUN_1415ccef0(void*, void*) {}

// @0x1415ccf10
void FUN_1415ccf10(void*, void*) {}

// @0x1415ccf30
void FUN_1415ccf30(void*, void*) {}

// @0x1415ccf50
void FUN_1415ccf50(void*, void*) {}

// @0x1415ccf70
void FUN_1415ccf70(void*, void*) {}

// @0x1415ccf90
void FUN_1415ccf90(void*, void*) {}

// @0x1415ccfb0
void FUN_1415ccfb0(void*, void*) {}

// @0x1415ccfd0
void FUN_1415ccfd0(void*, void*) {}

// @0x1415ccff0
void FUN_1415ccff0(void*, void*) {}

// @0x1415cd010
void FUN_1415cd010(void*, void*) {}

// @0x1415c7010
int FUN_1415c7010(void*, const CNMRejectedUser* user)
{
    CNMAppendRejectedUserFunc request(user);
    return FUN_1415cb440(FUN_1415fa260(), &request);
}

// @0x1415c70a0
int FUN_1415c70a0(void*, const CNMRejectedUser* user)
{
    CNMRemoveRejectedUserFunc request(user);
    return FUN_1415cb440(FUN_1415fa260(), &request);
}

// MS2-FUNCTIONAL 0x1415c7400: submits the synchronization-code request.
// @0x1415c7400
int FUN_1415c7400(void*, unsigned short code)
{
    CNMLogReportSyncFunc request(code);
    return FUN_1415cb440(FUN_1415fa260(), &request);
}

// @0x1415c75d0
int FUN_1415c75d0(void*, int noteId)
{
    CNMProcessNoteFunc request(0, noteId);
    return FUN_1415cb440(FUN_1415fa260(), &request);
}

// @0x1415c7630
int FUN_1415c7630(void*, int noteId)
{
    CNMProcessNoteFunc request(1, noteId);
    return FUN_1415cb440(FUN_1415fa260(), &request);
}

// @0x1415c7690
int FUN_1415c7690(void*, int noteId)
{
    CNMProcessNoteFunc request(2, noteId);
    return FUN_1415cb440(FUN_1415fa260(), &request);
}

// @0x1415c7770
int FUN_1415c7770(void*, unsigned long long guildId, int type)
{
    CNMMonitorGuildOnlineInfoExFunc request(guildId, type);
    return FUN_1415cb440(FUN_1415fa260(), &request);
}

// @0x1415c77e0
int FUN_1415c77e0(void*, unsigned int* userId, int type, int flags)
{
    const auto guildId = reinterpret_cast<unsigned long long>(FUN_1415fa120(userId));
    CNMMonitorGuildOnlineInfoExFunc request(guildId, flags, 0, *userId, type);
    return FUN_1415cb440(FUN_1415fa260(), &request);
}

// @0x1415c7c30
int FUN_1415c7c30(void*, int type, const char* message, int flags)
{
    CNMCustomNotifyFunc request(type, message, flags);
    return FUN_1415cb440(FUN_1415fa260(), &request);
}

// @0x1415c7cd0
int FUN_1415c7cd0(void*, const CNMCustomNotifyData& data)
{
    CNMCustomNotifyFunc request(data);
    return FUN_1415cb440(FUN_1415fa260(), &request);
}

// @0x1415c7f40
int FUN_1415c7f40(void*, const unsigned char* target, int* result)
{
    CNMRequestChatSessionExFunc request(target, 0);
    const int succeeded = FUN_1415cb440(FUN_1415fa260(), &request);
    if (succeeded && result)
        *result = request.m_50 == 0 ? request.m_4c : request.m_50;
    return succeeded;
}

// @0x1415c7d60
int FUN_1415c7d60(void*, unsigned char* target)
{
    unsigned char copiedTarget[16];
    for (unsigned int i = 0; i != sizeof(copiedTarget); ++i)
        copiedTarget[i] = target[i];
    CNMRequestChatSessionFunc request(copiedTarget, 0);
    return FUN_1415cb440(FUN_1415fa260(), &request);
}

// @0x1415c7e00
int FUN_1415c7e00(void*, const std::vector<NMChatSessionTarget>& targets, NMKey64 key)
{
    CNMRequestMultiChatSessionFunc request(key, targets, 0);
    return FUN_1415cb440(FUN_1415fa260(), &request);
}

// @0x1415c8030
int FUN_1415c8030(void*, const std::vector<NMFriendKey>& targets, NMKey64 key)
{
    CNMRequestMultiChatSessionExFunc request(key, targets, 0);
    return FUN_1415cb440(FUN_1415fa260(), &request);
}

static void nm_refresh_session_info(void* self, CNMGSGetSessionInfoFunc& request)
{
    if (FUN_1415cb440(FUN_1415fa260(), &request))
        FUN_1415f24e0(reinterpret_cast<CNMSerializable*>(static_cast<char*>(self) + 0x190),
                      reinterpret_cast<long long>(&request.m_30));
}

// @0x1415c9200
unsigned char* FUN_1415c9200(void* self, unsigned char* out)
{
    CNMGSGetSessionInfoFunc request(*reinterpret_cast<int*>(static_cast<char*>(self) + 0x18c));
    nm_refresh_session_info(self, request);
    for (unsigned int i = 0; i != 16; ++i)
        out[i] = *(static_cast<unsigned char*>(self) + 0x1c0 + i);
    return out;
}

// @0x1415c92d0
unsigned long long* FUN_1415c92d0(void* self, unsigned long long* out)
{
    CNMGSGetSessionInfoFunc request(*reinterpret_cast<int*>(static_cast<char*>(self) + 0x18c));
    nm_refresh_session_info(self, request);
    *out = *reinterpret_cast<unsigned long long*>(static_cast<char*>(self) + 0x1a4);
    return out;
}

// @0x1415c9390
int FUN_1415c9390(void* self)
{
    CNMGSGetSessionInfoFunc request(*reinterpret_cast<int*>(static_cast<char*>(self) + 0x18c));
    nm_refresh_session_info(self, request);
    return *reinterpret_cast<int*>(static_cast<char*>(self) + 0x1ac);
}

// @0x1415c9440
int FUN_1415c9440(void* self)
{
    CNMGSGetSessionInfoFunc request(*reinterpret_cast<int*>(static_cast<char*>(self) + 0x18c));
    nm_refresh_session_info(self, request);
    return *reinterpret_cast<int*>(static_cast<char*>(self) + 0x1d4);
}

// @0x1415c9a90
int FUN_1415c9a90(void* self, long long callback, int code)
{
    CNMGSRegisterCallbackFunc request(*reinterpret_cast<int*>(static_cast<char*>(self) + 0x18c),
                                      callback, code);
    return FUN_1415cb440(FUN_1415fa260(), &request);
}

// @0x1415c9b10
int FUN_1415c9b10(void* self)
{
    CNMGSWantCloseFunc request(*reinterpret_cast<int*>(static_cast<char*>(self) + 0x18c), 0);
    return FUN_1415cb440(FUN_1415fa260(), &request);
}

// @0x1415c9b70
int FUN_1415c9b70(void* self, const unsigned char* target)
{
    unsigned char copiedTarget[16];
    for (unsigned int i = 0; i != sizeof(copiedTarget); ++i)
        copiedTarget[i] = target[i];
    CNMGSInviteUserFunc request(*reinterpret_cast<int*>(static_cast<char*>(self) + 0x18c), copiedTarget);
    return FUN_1415cb440(FUN_1415fa260(), &request);
}

// @0x1415c9c20
int FUN_1415c9c20(void* self, const unsigned char* target)
{
    unsigned char copiedTarget[24];
    for (unsigned int i = 0; i != sizeof(copiedTarget); ++i)
        copiedTarget[i] = target[i];
    CNMGSInviteUserExFunc request(*reinterpret_cast<int*>(static_cast<char*>(self) + 0x18c),
                                  copiedTarget);
    return FUN_1415cb440(FUN_1415fa260(), &request);
}

// @0x1415c9cd0
int FUN_1415c9cd0(void* self)
{
    auto* sessionInfo = reinterpret_cast<CNMSessionInfo*>(static_cast<char*>(self) + 0x190);
    const int sessionId = *reinterpret_cast<int*>(static_cast<char*>(self) + 0x18c);
    if (sessionId == 0) {
        CNMSessionInfo emptyInfo;
        FUN_1415f24e0(sessionInfo, reinterpret_cast<long long>(&emptyInfo));
        return 1;
    }
    CNMGSGetSessionInfoFunc request(sessionId);
    if (!FUN_1415cb440(FUN_1415fa260(), &request))
        return 0;
    FUN_1415f24e0(sessionInfo, reinterpret_cast<long long>(&request.m_30));
    return 1;
}

extern void* FUN_1415efa30(void*, void*);
extern void* FUN_1415ef6b0(void*, void*);

// @0x1415c9df0
bool FUN_1415c9df0(void* self, void* out)
{
    CNMGSGetMemberListFunc request(*reinterpret_cast<int*>(static_cast<char*>(self) + 0x18c));
    const bool succeeded = FUN_1415cb440(FUN_1415fa260(), &request) != 0;
    if (succeeded)
        FUN_1415efa30(out, &request.m_30);
    return succeeded;
}

// @0x1415c9e90
bool FUN_1415c9e90(void* self, void* out)
{
    CNMGSGetInviteCandidateListFunc request(
        *reinterpret_cast<int*>(static_cast<char*>(self) + 0x18c));
    const bool succeeded = FUN_1415cb440(FUN_1415fa260(), &request) != 0;
    if (succeeded)
        FUN_1415ef6b0(out, &request.m_30);
    return succeeded;
}


// MS2-PIN: ?FUN_1415ca0d0@@YAHXZ 0x1415ca0d0
// MS2-PIN: ?FUN_1415c4f50@@YAPEAEPEAXPEAE@Z 0x1415c4f50
// MS2-PIN: ?FUN_1415c5010@@YAPEAEPEAXPEAE@Z 0x1415c5010
// MS2-PIN: ?FUN_1415c76f0@@YAPEAVCNMGuildListExInfo@@PEAXPEAV1@@Z 0x1415c76f0
// MS2-PIN: ?FUN_1415c7b10@@YAHPEAX_J@Z 0x1415c7b10
// MS2-PIN: ?FUN_1415c4bb0@@YAPEAEPEAXPEAE@Z 0x1415c4bb0
// MS2-PIN: ?FUN_1415c4da0@@YAPEAEPEAXPEAE@Z 0x1415c4da0
// MS2-PIN: ?FUN_1415c7ba0@@YAHPEAXPEBDH@Z 0x1415c7ba0
// MS2-PIN: ?FUN_1415c4e90@@YAPEAEPEAXPEAE0@Z 0x1415c4e90
// MS2-PIN: ?FUN_1415c6f80@@YA_NPEAX0@Z 0x1415c6f80
// MS2-PIN: ?FUN_1415ca240@@YAPEAEPEAE@Z 0x1415ca240
// @0x1415c9fa0
extern unsigned int FUN_1415c91c0(void* self);
extern void* FUN_1415fa260();
int FUN_1415c9fa0(void* self, const CNMChatMessage& message)
{
    CNMCSSendChatMessageFunc request(FUN_1415c91c0(self), message);
    return FUN_1415cb440(FUN_1415fa260(), &request);
}

// @0x1415ca030
int FUN_1415ca030(const char* gameName, const char* userName, const char* characterName)
{
    CNMGameLogInitializeFunc request(gameName, userName, characterName);
    return FUN_1415cb440(FUN_1415fa260(), &request);
}

// MS2-FUNCTIONAL 0x1415c4540: applies the requested locale after the manager accepts it and reports the recovered error outputs.
// @0x1415c4540
extern int FUN_1415cb6d0(void* manager, int locale, int sublocale, int* error, int* detail);
extern "C" int FUN_1415c4540(void* self, int locale, int sublocale, int error, int detail)
{
    void* manager = FUN_1415fa260();
    auto* pError = reinterpret_cast<int*>(static_cast<std::uintptr_t>(error));
    auto* pDetail = reinterpret_cast<int*>(static_cast<std::uintptr_t>(detail));
    if (!FUN_1415cb6d0(manager, locale, sublocale, pError, pDetail))
        return 0;
    CNMSetLocaleFunc request(locale, sublocale);
    if (!FUN_1415cb440(FUN_1415fa260(), &request))
    {
        if (pError) *pError = 0xbb9;
        if (pDetail) *pDetail = 0;
        return 0;
    }
    return 1;
}

// These two wrappers perform the ordered byte-map searches shown in the exe's iterator loops.
extern void FUN_1415e5d30(void* iterator);
extern void* FUN_141607780(void* self, void* iterator);
extern void* FUN_1416099b0(void* self, void* iterator);
extern bool FUN_1415f3280(void* first, void* last);
extern void* FUN_1415f3a10(void* iterator);
extern void FUN_1415f3f30(void* iterator);
// MS2-FUNCTIONAL 0x1415caaa0: scans the ordered map until its mapped object's virtual key matches, returning that object.
// @0x1415caaa0
void* FUN_1415caaa0(void* self, unsigned int wanted)
{
    alignas(8) unsigned char first[0x20]{};
    alignas(8) unsigned char last[0x20]{};
    FUN_1415e5d30(first);
    FUN_1415e5d30(last);
    *reinterpret_cast<void**>(first) = *static_cast<void**>(FUN_141607780(self, first));
    *reinterpret_cast<void**>(last) = *static_cast<void**>(FUN_1416099b0(self, last));
    while (FUN_1415f3280(first, last))
    {
        auto* node = FUN_1415f3a10(first);
        void* value = *reinterpret_cast<void**>(static_cast<unsigned char*>(node) + 8);
        auto** vtable = *reinterpret_cast<void***>(value);
        using KeyMethod = int(__fastcall*)(void*);
        if (reinterpret_cast<KeyMethod>(vtable[4])(value) == static_cast<int>(wanted))
            return value;
        FUN_1415f3f30(first);
    }
    return nullptr;
}

extern void FUN_14160a570(void* self, void* iterator, void* key);
// MS2-FUNCTIONAL 0x1415cab60: finds the entry associated with a one-byte key and returns its mapped object or null.
// @0x1415cab60
void* FUN_1415cab60(void* self, unsigned char key)
{
    alignas(8) unsigned char iterator[0x20]{};
    alignas(8) unsigned char end[0x20]{};
    alignas(8) unsigned char lookupKey[0x20]{};
    lookupKey[0] = key;
    FUN_14160a570(self, iterator, lookupKey);
    FUN_1416099b0(self, end);
    if (!FUN_1415f3280(iterator, end))
        return nullptr;
    auto* node = FUN_1415f3a10(iterator);
    return *reinterpret_cast<void**>(static_cast<unsigned char*>(node) + 8);
}


extern void* FUN_1415ef3b0(void*, void*);
extern void* FUN_1415ef6b0(void*, void*);
extern void* FUN_1415f0bf0(void*, void*);

// MS2-FUNCTIONAL 0x1415c6970: requests the friend list and copies both decoded vectors when successful.
// @0x1415c6970
bool FUN_1415c6970(void*, void* categories, void* friends, int all)
{
    CNMGetFriendListFunc request(all == 0 ? ~0ull : 0ull);
    const int ok = FUN_1415cb440(FUN_1415fa260(), &request);
    if (ok) {
        FUN_1415ef3b0(categories, &request.m_38);
        FUN_1415ef6b0(friends, &request.m_50);
    }
    return ok != 0;
}

// MS2-FUNCTIONAL 0x1415c6a50: requests the friend list for the supplied key and copies both decoded vectors.
// @0x1415c6a50
bool FUN_1415c6a50(void*, void* categories, void* friends, unsigned long long key)
{
    CNMGetFriendListFunc request(key);
    const int ok = FUN_1415cb440(FUN_1415fa260(), &request);
    if (ok) {
        FUN_1415ef3b0(categories, &request.m_38);
        FUN_1415ef6b0(friends, &request.m_50);
    }
    return ok != 0;
}

// MS2-FUNCTIONAL 0x1415c6b00: sends a friend-info request and copies its decoded result on success.
// @0x1415c6b00
unsigned int FUN_1415c6b00(void*, const unsigned char* key, void* result)
{
    CNMGetFriendInfoFunc request(key);
    const unsigned int ok = static_cast<unsigned int>(FUN_1415cb440(FUN_1415fa260(), &request));
    if (ok)
        FUN_1415f0bf0(result, &request.m_48);
    return ok;
}

// MS2-FUNCTIONAL 0x1415c6be0: sends a block-friend request using the supplied fixed-size key.
// @0x1415c6be0
unsigned int FUN_1415c6be0(void*, const unsigned char* key, int blockType)
{
    CNMBlockFriendFunc request(key, blockType);
    const unsigned int result = static_cast<unsigned int>(FUN_1415cb440(FUN_1415fa260(), &request));
    return result;
}

// MS2-FUNCTIONAL 0x1415c6c90: sends a request to add a friend to a category.
// @0x1415c6c90
unsigned int FUN_1415c6c90(void*, const unsigned char* key, int category, int flag)
{
    CNMAddFriendToCategoryFunc request(key, category, flag);
    return static_cast<unsigned int>(FUN_1415cb440(FUN_1415fa260(), &request));
}

// MS2-FUNCTIONAL 0x1415c6d50: sends a request to remove a friend from a category.
// @0x1415c6d50
unsigned int FUN_1415c6d50(void*, const unsigned char* key, int category, int flag)
{
    CNMDeleteFriendFromCategoryFunc request(key, category, flag);
    return static_cast<unsigned int>(FUN_1415cb440(FUN_1415fa260(), &request));
}

// MS2-FUNCTIONAL 0x1415c6e10: sends a request to move a friend between categories.
// @0x1415c6e10
unsigned int FUN_1415c6e10(void*, const unsigned char* key, int source, int destination, int flag)
{
    CNMMoveFriendCategoryFunc request(key, source, destination, flag);
    return static_cast<unsigned int>(FUN_1415cb440(FUN_1415fa260(), &request));
}

// MS2-FUNCTIONAL 0x1415c6ed0: sends an extended friend-memo request.
// @0x1415c6ed0
unsigned int FUN_1415c6ed0(void*, const unsigned char* key, unsigned long long memo)
{
    CNMChangeFriendMemoExFunc request(key, static_cast<long long>(memo));
    return static_cast<unsigned int>(FUN_1415cb440(FUN_1415fa260(), &request));
}


// @0x1415c72c0
unsigned int FUN_1415c72c0(void*, int type, const char* text)
{
    CNMSendNoteExMsgFunc request(type, text);
    return static_cast<unsigned int>(FUN_1415cb440(FUN_1415fa260(), &request));
}

// @0x1415c7360
unsigned int FUN_1415c7360(void*, int type, const void* details, int status)
{
    CNMSendAccuseNoteMsgFunc request(type, details, status);
    return static_cast<unsigned int>(FUN_1415cb440(FUN_1415fa260(), &request));
}


extern void FUN_1415cb640(void*, unsigned int);
// @0x1415c47e0
void FUN_1415c47e0(void*, unsigned int command)
{
    FUN_1415cb640(FUN_1415fa260(), command);
}


// @0x1415c5ce0
unsigned int FUN_1415c5ce0(void*, void* key, long long nickname)
{
    if (nickname)
    {
        CNMChangeNicknameFunc request(reinterpret_cast<long long>(key), nickname);
        return static_cast<unsigned int>(FUN_1415cb440(FUN_1415fa260(), &request));
    }
    return 0;
}

// @0x1415c5d80
unsigned int FUN_1415c5d80(void*, void* key, long long metadata)
{
    if (metadata)
    {
        CNMChangeMetaDataFunc request(reinterpret_cast<long long>(key), metadata);
        return static_cast<unsigned int>(FUN_1415cb440(FUN_1415fa260(), &request));
    }
    return 0;
}



extern void* FUN_1415efab0(void*, void*);
// @0x1415c5400
unsigned int FUN_1415c5400(void*, long long login, int value, long long password)
{
    CNMLoginVirtualFunc request(login, value, password);
    return static_cast<unsigned int>(FUN_1415cb440(FUN_1415fa260(), &request));
}

// MS2-FUNCTIONAL 0x1415c54f0: requests the virtual-user list and copies its result vector when successful.
// @0x1415c54f0
bool FUN_1415c54f0(void*, void* output, int resultCode)
{
    CNMGetMyVirtualUserListFunc request(static_cast<unsigned int>(resultCode));
    const int ok = FUN_1415cb440(FUN_1415fa260(), &request);
    if (ok) FUN_1415efab0(output, &request.m_38);
    return ok != 0;
}


extern void* FUN_14160a190(void*, void*);
extern void* FUN_141607f70(void*, void*);
extern void FUN_1415e2330(void*, unsigned long long, unsigned long long);
// MS2-FUNCTIONAL 0x1415c7500: requests the indexed note box and copies its two returned identifiers on success.
// @0x1415c7500
int FUN_1415c7500(void*, int type, int index, void* output)
{
    CNMGetNoteBox2Func request(type, index, 0);
    const int ok = FUN_1415cb440(FUN_1415fa260(), &request);
    if (ok) {
        alignas(8) unsigned char first[16]{};
        alignas(8) unsigned char last[16]{};
        auto* firstValue = static_cast<unsigned long long*>(FUN_14160a190(&request.m_40, first));
        auto* lastValue = static_cast<unsigned long long*>(FUN_141607f70(&request.m_40, last));
        FUN_1415e2330(output, *lastValue, *firstValue);
    }
    return ok;
}


extern void FUN_1415e50b0(void*, void*, const void*);
// MS2-FUNCTIONAL: inserts the supplied interface pointer paired with its virtual enabled flag.
// @0x1415caa40
void FUN_1415caa40(void* map, void* item)
{
    if (!item) return;
    void** vtable = *reinterpret_cast<void***>(item);
    using Enabled = unsigned char(__fastcall*)(void*);
    struct Entry { void* item; unsigned char enabled; };
    Entry value{item, reinterpret_cast<Enabled>(vtable[3])(item)};
    alignas(8) unsigned char inserted[0x20]{};
    FUN_1415e50b0(map, inserted, &value);
}

extern void FUN_1415e89b0(void*, const void*);
extern unsigned char FUN_1415f3a00(void*);
extern void FUN_141609160(void*);
extern void FUN_14156a080(void*) noexcept;
// MS2-FUNCTIONAL: initializes a temporary BSTR from the object's text and clears its trailing list when nonempty.
// @0x1415c9040
void FUN_1415c9040(void* object)
{
    alignas(8) unsigned char text[16]{};
    FUN_1415e89b0(text, static_cast<unsigned char*>(object) + 8);
    if (FUN_1415f3a00(text))
        FUN_141609160(static_cast<unsigned char*>(object) + 0x1d8);
    FUN_14156a080(text);
}

// MS2-PIN: ?FUN_1415c4540@@YAHPEAXHHHH@Z 0x1415c4540
// MS2-PIN: ?FUN_1415caaa0@@YAPEAXPEAXI@Z 0x1415caaa0
// MS2-PIN: ?FUN_1415cab60@@YAPEAXPEAXE@Z 0x1415cab60
// MS2-PIN: ?FUN_1415c6970@@YA_NPEAX00H@Z 0x1415c6970
// MS2-PIN: ?FUN_1415c6a50@@YA_NPEAX00_K@Z 0x1415c6a50
// MS2-PIN: ?FUN_1415c6b00@@YAIPEAXPEBE0@Z 0x1415c6b00
// MS2-PIN: ?FUN_1415c6be0@@YAIPEAXPEBEH@Z 0x1415c6be0
// MS2-PIN: ?FUN_1415c6c90@@YAIPEAXPEBEHH@Z 0x1415c6c90
// MS2-PIN: ?FUN_1415c6d50@@YAIPEAXPEBEHH@Z 0x1415c6d50
// MS2-PIN: ?FUN_1415c6e10@@YAIPEAXPEBEHHH@Z 0x1415c6e10
// MS2-PIN: ?FUN_1415c6ed0@@YAIPEAXPEBE_K@Z 0x1415c6ed0
// MS2-PIN: ?FUN_1415c72c0@@YAIPEAXHPEBD@Z 0x1415c72c0
// MS2-PIN: ?FUN_1415c7360@@YAIPEAXHPEBXH@Z 0x1415c7360
// MS2-PIN: ?FUN_1415c47e0@@YAXPEAXI@Z 0x1415c47e0
// MS2-PIN: ?FUN_1415c5ce0@@YAIPEAX0_J@Z 0x1415c5ce0
// MS2-PIN: ?FUN_1415c5d80@@YAIPEAX0_J@Z 0x1415c5d80
// MS2-PIN: ?FUN_1415c7400@@YAHPEAXG@Z 0x1415c7400
// MS2-PIN: ?FUN_1415c5400@@YAIPEAX_JH0@Z 0x1415c5400
// MS2-PIN: ?FUN_1415c54f0@@YA_NPEAX0H@Z 0x1415c54f0
// MS2-PIN: ?FUN_1415c7500@@YAHPEAXHH0@Z 0x1415c7500
// MS2-PIN: ?FUN_1415caa40@@YAXPEAX0@Z 0x1415caa40
// MS2-PIN: ?FUN_1415c9040@@YAXPEAX@Z 0x1415c9040
