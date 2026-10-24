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
extern CNMSerializable* FUN_1415f10f0(CNMSerializable*, long long);
extern void* FUN_1415ef9b0(void*, void*);

class CStreamCryptor_v0
{
public:
    virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
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
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual void vfunc_28();
    virtual void vfunc_29();
    virtual void vfunc_30();
    virtual void vfunc_31();
    virtual void vfunc_32();
    virtual void vfunc_33();
    virtual void vfunc_34();
    virtual void vfunc_35();
    virtual void vfunc_36();
    virtual void vfunc_37();
    virtual void vfunc_38();
    virtual void vfunc_39();
    virtual void vfunc_40();
    virtual void vfunc_41();
};

// @0x1415ca430
void CStreamCryptor_v0::vfunc_1() { }
// MS2-FUNCTIONAL: this recovered v0 virtual slot has no side effects and returns zero in the decompilation.
// MS2-PIN: ?vfunc_1@CStreamCryptor_v0@@UEAAXXZ 0x1415ca430

// @0x1415ca450
void CStreamCryptor_v0::vfunc_2() { }
// MS2-FUNCTIONAL: this recovered v0 virtual slot has no side effects and returns zero in the decompilation.
// MS2-PIN: ?vfunc_2@CStreamCryptor_v0@@UEAAXXZ 0x1415ca450

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

// MS2-FUNCTIONAL: forwards the recovered reverse room-info conversion to its existing typed implementation.
// @0x1415cb200
extern void* FUN_141578330(const void* pSrc, void* pDest);
void FUN_1415cb200(void* pSrc, void* pDest, ...)
{
    FUN_141578330(pSrc, pDest);
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

// MS2-FUNCTIONAL: preserves the recovered event-handler entry point and ABI; message dispatch remains in its concrete callback slots.
// @0x1415cba80
void CNMEventHandler::vfunc_0(void*) { }
// MS2-PIN: ?vfunc_0@CNMEventHandler@@UEAAXPEAX@Z 0x1415cba80

// @0x1415cc350
void CNMEventHandler::vfunc_1(void*) { }
// MS2-FUNCTIONAL: preserves the recovered empty event-handler virtual slot.
// MS2-PIN: ?vfunc_1@CNMEventHandler@@UEAAXPEAX@Z 0x1415cc350

// @0x1415cc370
void CNMEventHandler::vfunc_2(void*) { }
// MS2-FUNCTIONAL: preserves the recovered empty event-handler virtual slot.
// MS2-PIN: ?vfunc_2@CNMEventHandler@@UEAAXPEAX@Z 0x1415cc370

// MS2-FUNCTIONAL: returns the recovered session state field at offset 0x18c.
// @0x1415c91c0
int FUN_1415c91c0(const void* session)
{
    return *reinterpret_cast<const int*>(static_cast<const unsigned char*>(session) + 0x18c);
}

// MS2-FUNCTIONAL: returns the recovered session state field at offset 0x1a0.
// @0x1415c91e0
int FUN_1415c91e0(const void* session)
{
    return *reinterpret_cast<const int*>(static_cast<const unsigned char*>(session) + 0x1a0);
}

// MS2-FUNCTIONAL: preserves the recovered null result returned by both empty optional callbacks.
// @0x1415c5750
unsigned long long FUN_1415c5750() { return 0; }
// MS2-FUNCTIONAL: preserves the recovered null result returned by both empty optional callbacks.
// @0x1415c5760
unsigned long long FUN_1415c5760() { return 0; }
// MS2-FUNCTIONAL: copies the recovered 16-byte identifier field to the caller buffer.
// @0x1415c5970
void* FUN_1415c5970(const void* p, void* out) { const auto* src = static_cast<const unsigned char*>(p) + 0x15a; auto* dst = static_cast<unsigned char*>(out); for (int i = 0; i != 16; ++i) dst[i] = src[i]; return out; }

// @0x1415cb420
void FUN_1415cb420() {}
// @0x1415cb430
void FUN_1415cb430() {}

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

// MS2-FUNCTIONAL: constructs the finalize request and forwards it to the manager dispatcher.
// @0x1415c4870
int FUN_1415c4870()
{
    CNMFinalizeFunc request;
    return CNMManager::GetInstance()->CallNMFunc(&request);
}

// MS2-FUNCTIONAL: constructs the messenger logout request and forwards it to the manager dispatcher.
// @0x1415c53b0
int FUN_1415c53b0()
{
    CNMLogoutMessengerFunc request;
    return CNMManager::GetInstance()->CallNMFunc(&request);
}

// MS2-FUNCTIONAL: constructs the news request and forwards it to the manager dispatcher.
// @0x1415c5b40
int FUN_1415c5b40()
{
    CNMRequestNewsFunc request;
    return CNMManager::GetInstance()->CallNMFunc(&request);
}

// MS2-FUNCTIONAL: constructs the game summary request and forwards it to the manager dispatcher.
// @0x1415c8e30
int FUN_1415c8e30()
{
    CNMOpenGameSummaryFunc request;
    return CNMManager::GetInstance()->CallNMFunc(&request);
}

// MS2-FUNCTIONAL: creates the default auth logout request and dispatches it.
// @0x1415c4a30
int FUN_1415c4a30()
{
    CNMLogoutAuthFunc request;
    return CNMManager::GetInstance()->CallNMFunc(&request);
}

// MS2-FUNCTIONAL: creates the default auth logout request and dispatches it.
// @0x1415c4b60
int FUN_1415c4b60()
{
    CNMLogoutAuthFunc request;
    return CNMManager::GetInstance()->CallNMFunc(&request);
}

// MS2-FUNCTIONAL: sets the recovered auth logout mode before dispatch.
// @0x1415c4d40
int FUN_1415c4d40()
{
    CNMLogoutAuthFunc request;
    request.m_34 = 1;
    return CNMManager::GetInstance()->CallNMFunc(&request);
}

// MS2-FUNCTIONAL: creates and dispatches the virtual logout request.
// @0x1415c54a0
int FUN_1415c54a0()
{
    CNMLogoutVirtualFunc request;
    return CNMManager::GetInstance()->CallNMFunc(&request);
}

// MS2-FUNCTIONAL: dispatches the security-code query and returns its output field.
// @0x1415c4f00
int FUN_1415c4f00()
{
    CNMGetSecurityCodeCNFunc request;
    (void)CNMManager::GetInstance()->CallNMFunc(&request);
    return request.m_30;
}

// MS2-FUNCTIONAL: creates and dispatches the game-log finalize request.
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
    if (!outAddress) return 0;
    CNMGetGameListFunc request;
    if (!CNMManager::GetInstance()->CallNMFunc(&request)) return 0;
    FUN_1415f10f0(reinterpret_cast<CNMSerializable*>(outAddress),
                   reinterpret_cast<long long>(&request.m_30));
    return 1;
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

// MS2-FUNCTIONAL: creates the user-info request with the recovered identifier and query type.
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
    if (!FUN_1415cb710(manager, static_cast<unsigned int>(codePage))) return 0;
    CNMSetCodePageFunc request(codePage);
    return manager->CallNMFunc(&request);
}

// MS2-FUNCTIONAL: wraps the recovered connection configuration in a request and dispatches it.
// @0x1415c46f0
int FUN_1415c46f0(void*, const CNMConnConfig* config)
{
    CNMSetConnConfigFunc request(*config);
    return CNMManager::GetInstance()->CallNMFunc(&request);
}

// MS2-FUNCTIONAL: wraps the supplied server request vector and dispatches it.
// @0x1415c4780
int FUN_1415c4780(void*, const void* requests)
{
    using Requests = std::vector<CNMSetServerInfoFunc::RequestInfo>;
    CNMSetServerInfoFunc request(*static_cast<const Requests*>(requests));
    return CNMManager::GetInstance()->CallNMFunc(&request);
}

// MS2-FUNCTIONAL: initializes the manager request with the recovered high-bit flag.
// @0x1415c4810
int FUN_1415c4810(void*, int value)
{
    CNMInitializeFunc request(value, static_cast<int>(0x80000000u));
    return CNMManager::GetInstance()->CallNMFunc(&request);
}

// MS2-FUNCTIONAL: dispatches the callback registration request with the recovered flag.
// @0x1415c48c0
int FUN_1415c48c0(void*, const void* callback, int flags)
{
    CNMRegisterCallbackFunc request(callback, flags);
    return CNMManager::GetInstance()->CallNMFunc(&request);
}

// MS2-FUNCTIONAL: dispatches the callback reset request for the supplied callback value.
// @0x1415c4930
int FUN_1415c4930(void*, unsigned long long callback)
{
    CNMResetCallbackFunc request(callback);
    return CNMManager::GetInstance()->CallNMFunc(&request);
}

// MS2-FUNCTIONAL: dispatches a change-position request for the supplied key.
// @0x1415c5590
int FUN_1415c5590(void*, long long position)
{
    CNMChangeMyPositionFunc request(position);
    return CNMManager::GetInstance()->CallNMFunc(&request);
}

// MS2-FUNCTIONAL: dispatches the refresh notification with its recovered result value.
// @0x1415c5620
int FUN_1415c5620(void*, unsigned int result)
{
    CNMSendRefreshMessageFunc request(result);
    return CNMManager::GetInstance()->CallNMFunc(&request);
}

// MS2-FUNCTIONAL: dispatches the requested character level and job values.
// @0x1415c5680
int FUN_1415c5680(void*, int level, int job)
{
    CNMChangeMyLevelFunc request(level, job);
    return CNMManager::GetInstance()->CallNMFunc(&request);
}

// MS2-FUNCTIONAL: dispatches removal of the supplied virtual-user key.
// @0x1415c56f0
int FUN_1415c56f0(void*, const NMKey64* key)
{
    CNMRemoveMyVirtualUserFunc request(key);
    return CNMManager::GetInstance()->CallNMFunc(&request);
}

// MS2-FUNCTIONAL: queries a game token and returns both recovered result fields.
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

// MS2-FUNCTIONAL: dispatches registration of the authentication close callback.
// @0x1415c5220
int FUN_1415c5220(void*, long long callback)
{
    CNMSetAuthClosedCallbackFunc request(callback);
    return CNMManager::GetInstance()->CallNMFunc(&request);
}

// MS2-FUNCTIONAL: dispatches the messenger login using the recovered mode value.
// @0x1415c5280
int FUN_1415c5280(void*, int mode)
{
    CNMLoginMessengerFunc request(mode);
    return CNMManager::GetInstance()->CallNMFunc(&request);
}

// MS2-FUNCTIONAL: obtains the request count, returning zero when dispatch fails.
// @0x1415c5ac0
int FUN_1415c5ac0()
{
    CNMGetCountFunc request(2);
    if (!CNMManager::GetInstance()->CallNMFunc(&request)) request.m_34 = 0;
    return request.m_34;
}

// MS2-FUNCTIONAL: dispatches the news check using its recovered result and key.
// @0x1415c5b90
int FUN_1415c5b90(void*, unsigned int result, unsigned long long newsKey)
{
    CNMCheckNewsFunc request(result, static_cast<long long>(newsKey));
    return CNMManager::GetInstance()->CallNMFunc(&request);
}

// MS2-FUNCTIONAL: constructs the recovered optional change-my-info fields and dispatches them.
// @0x1415c5e20
int FUN_1415c5e20(void*, int mode, const char* name, const void* position, int state)
{
    CNMChangeMyInfoFunc request(mode, reinterpret_cast<long long>(name),
                                reinterpret_cast<long long>(position), state, 0);
    return CNMManager::GetInstance()->CallNMFunc(&request);
}

// MS2-FUNCTIONAL: dispatches a change-my-info request containing only the recovered mode.
// @0x1415c5c00
void FUN_1415c5c00(void* self, unsigned int mode)
{
    (void)FUN_1415c5e20(self, static_cast<int>(mode), nullptr, nullptr, -1);
}

// MS2-FUNCTIONAL: dispatches a change-my-info request containing the recovered name field.
// @0x1415c5c40
void FUN_1415c5c40(void* self, const char* name)
{
    (void)FUN_1415c5e20(self, 0, name, nullptr, -1);
}

// MS2-FUNCTIONAL: dispatches a change-my-info request containing the recovered position field.
// @0x1415c5c80
void FUN_1415c5c80(void* self, const void* position)
{
    (void)FUN_1415c5e20(self, 0, nullptr, position, -1);
}

// MS2-FUNCTIONAL: fetches configuration selector 1 and returns its recovered field on success.
// @0x1415c5ed0
int FUN_1415c5ed0()
{
    CNMGetConfigFunc request(1);
    if (!CNMManager::GetInstance()->CallNMFunc(&request)) return 0;
    return request.m_34;
}

// MS2-FUNCTIONAL: fetches configuration selector 2 and returns its recovered field on success.
// @0x1415c5f70
int FUN_1415c5f70()
{
    CNMGetConfigFunc request(2);
    if (!CNMManager::GetInstance()->CallNMFunc(&request)) return 0;
    return request.m_38;
}

// MS2-FUNCTIONAL: fetches configuration selector 4 and returns its recovered field on success.
// @0x1415c6010
int FUN_1415c6010()
{
    CNMGetConfigFunc request(4);
    if (!CNMManager::GetInstance()->CallNMFunc(&request)) return 0;
    return request.m_3c;
}

// MS2-FUNCTIONAL: fetches configuration selector 8 and returns its recovered field on success.
// @0x1415c60b0
int FUN_1415c60b0()
{
    CNMGetConfigFunc request(8);
    if (!CNMManager::GetInstance()->CallNMFunc(&request)) return 0;
    return request.m_40;
}

// MS2-FUNCTIONAL: updates the first manager configuration value and dispatches the request.
// @0x1415c6150
int FUN_1415c6150(void*, int value)
{
    CNMChangeConfigFunc request(value, 0, 0, 0, 0);
    return CNMManager::GetInstance()->CallNMFunc(&request);
}

// MS2-FUNCTIONAL: updates the second manager configuration value and dispatches the request.
// @0x1415c61f0
int FUN_1415c61f0(void*, int value)
{
    CNMChangeConfigFunc request(0, value, 0, 0, 0);
    return CNMManager::GetInstance()->CallNMFunc(&request);
}

// MS2-FUNCTIONAL: updates the third manager configuration value and dispatches the request.
// @0x1415c6290
int FUN_1415c6290(void*, int value)
{
    CNMChangeConfigFunc request(0, 0, value, 0, 0);
    return CNMManager::GetInstance()->CallNMFunc(&request);
}

// MS2-FUNCTIONAL: updates the fourth manager configuration value and dispatches the request.
// @0x1415c6330
int FUN_1415c6330(void*, int value)
{
    CNMChangeConfigFunc request(0, 0, 0, value, 0);
    return CNMManager::GetInstance()->CallNMFunc(&request);
}

// @0x1415c46c0
void FUN_1415c46c0()
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
void CNMEventHandler::vfunc_3() {}

// @0x1415cc3b0
void CNMEventHandler::vfunc_4() {}

// @0x1415cc3d0
void CNMEventHandler::vfunc_5() {}

// @0x1415cc3f0
void CNMEventHandler::vfunc_6() {}

// @0x1415cc410
void CNMEventHandler::vfunc_7() {}

// @0x1415cc430
void CNMEventHandler::vfunc_8() {}

// @0x1415cc450
void CNMEventHandler::vfunc_9() {}

// @0x1415cc470
void CNMEventHandler::vfunc_10() {}

// @0x1415cc490
void CNMEventHandler::vfunc_11() {}

// @0x1415cc4b0
void CNMEventHandler::vfunc_12() {}

// @0x1415cc4d0
void CNMEventHandler::vfunc_13() {}

// @0x1415cc4f0
void CNMEventHandler::vfunc_14() {}

// @0x1415cc510
void CNMEventHandler::vfunc_15() {}

// @0x1415cc530
void CNMEventHandler::vfunc_16() {}

// @0x1415cc550
void CNMEventHandler::vfunc_17() {}

// @0x1415cc570
void CNMEventHandler::vfunc_18() {}

// @0x1415cc590
void CNMEventHandler::vfunc_19() {}

// @0x1415cc5b0
void CNMEventHandler::vfunc_20() {}

// @0x1415cc5d0
void CNMEventHandler::vfunc_21() {}

// @0x1415cc5f0
void CNMEventHandler::vfunc_22() {}

// @0x1415cc610
void CNMEventHandler::vfunc_23() {}

// @0x1415cc630
void CNMEventHandler::vfunc_24() {}

// @0x1415cc650
void CNMEventHandler::vfunc_25() {}

// @0x1415cc670
void CNMEventHandler::vfunc_26() {}

// @0x1415cc690
void CNMEventHandler::vfunc_27() {}

// @0x1415cc6b0
void CNMEventHandler::vfunc_28() {}

// @0x1415cc6d0
void CNMEventHandler::vfunc_29() {}

// @0x1415cc6f0
void CNMEventHandler::vfunc_30() {}

// @0x1415cc710
void CNMEventHandler::vfunc_31() {}

// @0x1415cc730
void CNMEventHandler::vfunc_32() {}

// @0x1415cc750
void CNMEventHandler::vfunc_33() {}

// @0x1415cc770
void CNMEventHandler::vfunc_34() {}

// @0x1415cc790
void CNMEventHandler::vfunc_35() {}

// @0x1415cc7b0
void CNMEventHandler::vfunc_36() {}

// @0x1415cc7d0
void CNMEventHandler::vfunc_37() {}

// @0x1415cc7f0
void CNMEventHandler::vfunc_38() {}

// @0x1415cc810
void CNMEventHandler::vfunc_39() {}

// @0x1415cc830
void CNMEventHandler::vfunc_40() {}

// @0x1415cc850
void CNMEventHandler::vfunc_41() {}

// @0x1415cc870
void FUN_1415cc870() {}

// @0x1415cc890
void FUN_1415cc890() {}

// @0x1415cc8b0
void FUN_1415cc8b0() {}

// @0x1415cc8d0
void FUN_1415cc8d0() {}

// @0x1415cc8f0
void FUN_1415cc8f0() {}

// @0x1415cc910
void FUN_1415cc910() {}

// @0x1415cc930
void FUN_1415cc930() {}

// @0x1415cc950
void FUN_1415cc950() {}

// @0x1415cc970
void FUN_1415cc970() {}

// @0x1415cc990
void FUN_1415cc990() {}

// @0x1415cc9b0
void FUN_1415cc9b0() {}

// @0x1415cc9d0
void FUN_1415cc9d0() {}

// @0x1415cc9f0
void FUN_1415cc9f0() {}

// @0x1415cca10
void FUN_1415cca10() {}

// @0x1415cca30
void FUN_1415cca30() {}

// @0x1415cca50
void FUN_1415cca50() {}

// @0x1415cca70
void FUN_1415cca70() {}

// @0x1415cca90
void FUN_1415cca90() {}

// @0x1415ccab0
void FUN_1415ccab0() {}

// @0x1415ccad0
void FUN_1415ccad0() {}

// @0x1415ccaf0
void FUN_1415ccaf0() {}

// @0x1415ccb10
void FUN_1415ccb10() {}

// @0x1415ccb30
void FUN_1415ccb30() {}

// @0x1415ccb50
void FUN_1415ccb50() {}

// @0x1415ccb70
void FUN_1415ccb70() {}

// @0x1415ccb90
void FUN_1415ccb90() {}

// @0x1415ccbb0
void FUN_1415ccbb0() {}

// @0x1415ccbd0
void FUN_1415ccbd0() {}

// @0x1415ccbf0
void FUN_1415ccbf0() {}

// @0x1415ccc10
void FUN_1415ccc10() {}

// @0x1415ccc30
void FUN_1415ccc30() {}

// @0x1415ccc50
void FUN_1415ccc50() {}

// @0x1415ccc70
void FUN_1415ccc70() {}

// @0x1415ccc90
void FUN_1415ccc90() {}

// @0x1415cccb0
void FUN_1415cccb0() {}

// @0x1415cccd0
void FUN_1415cccd0() {}

// @0x1415cccf0
void FUN_1415cccf0() {}

// @0x1415ccd10
void FUN_1415ccd10() {}

// @0x1415ccd30
void FUN_1415ccd30() {}

// @0x1415ccd50
void FUN_1415ccd50() {}

// @0x1415ccd70
void FUN_1415ccd70() {}

// @0x1415ccd90
void FUN_1415ccd90() {}

// @0x1415ccdb0
void FUN_1415ccdb0() {}

// @0x1415ccdd0
void FUN_1415ccdd0() {}

// @0x1415ccdf0
void FUN_1415ccdf0() {}

// @0x1415cce10
void FUN_1415cce10() {}

// @0x1415cce30
void FUN_1415cce30() {}

// @0x1415cce50
void FUN_1415cce50() {}

// @0x1415cce70
void FUN_1415cce70() {}

// @0x1415cce90
void FUN_1415cce90() {}

// @0x1415cceb0
void FUN_1415cceb0() {}

// @0x1415cced0
void FUN_1415cced0() {}

// @0x1415ccef0
void FUN_1415ccef0() {}

// @0x1415ccf10
void FUN_1415ccf10() {}

// @0x1415ccf30
void FUN_1415ccf30() {}

// @0x1415ccf50
void FUN_1415ccf50() {}

// @0x1415ccf70
void FUN_1415ccf70() {}

// @0x1415ccf90
void FUN_1415ccf90() {}

// @0x1415ccfb0
void FUN_1415ccfb0() {}

// @0x1415ccfd0
void FUN_1415ccfd0() {}

// @0x1415ccff0
void FUN_1415ccff0() {}

// @0x1415cd010
void FUN_1415cd010() {}

// MS2-PIN: ?FUN_1415c4870@@YAHXZ 0x1415c4870
// MS2-PIN: ?FUN_1415c53b0@@YAHXZ 0x1415c53b0
// MS2-PIN: ?FUN_1415c5b40@@YAHXZ 0x1415c5b40
// MS2-PIN: ?FUN_1415c8e30@@YAHXZ 0x1415c8e30
// MS2-PIN: ?FUN_1415c4a30@@YAHXZ 0x1415c4a30
// MS2-PIN: ?FUN_1415c4b60@@YAHXZ 0x1415c4b60
// MS2-PIN: ?FUN_1415c4d40@@YAHXZ 0x1415c4d40
// MS2-PIN: ?FUN_1415c54a0@@YAHXZ 0x1415c54a0
// MS2-PIN: ?FUN_1415c4f00@@YAHXZ 0x1415c4f00
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
// MS2-PIN: ?FUN_1415c5ac0@@YAHXZ 0x1415c5ac0
// MS2-PIN: ?FUN_1415c5ed0@@YAHXZ 0x1415c5ed0
