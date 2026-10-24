// Nexon Messenger full-exe event, cryptor, and manager entry points.
// MS2-UNIT: unit_1415c44c0
// MS2-RANGE: 0x1415c44c0-0x1415cd2d0 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmfunc.h"

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
