// Nexon Messenger character and channel request serialization.
// MS2-UNIT: unit_1415a7c70
// MS2-RANGE: 0x1415a7c70-0x1415b1e30 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/placeholder/nmobjects.h"
#include "ms2/placeholder/nmfunc.h"
#include "ms2/ms2recover.h"

extern void FUN_14156bcb0(void*, void*, void*);
extern void FUN_14156bd50(void*);
extern void FUN_14156be10(void*, void*, void*);
extern void FUN_14156bf10(void*);
extern void FUN_14156ae30(void*, const void*);
extern void FUN_14156ac20(void*, unsigned int);
extern void FUN_14156acb0(void*, unsigned __int64);
extern void FUN_1415f9990(void*);
extern int FUN_1415fb700(void*);
extern int FUN_1415fb720(void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(void*);
extern void FUN_1415fbe70(void*, unsigned int, const char*);

// MS2-FUNCTIONAL 0x1415a7c70: initializes a character-login request.
// @0x1415a7c70
CNMCharacterLoginFunc::CNMCharacterLoginFunc()
    : CNMFunc(0xf000, 1, 0, 0), m_30{}, m_70(0), m_74(0), m_78(1), m_7c(0)
{
}

// MS2-FUNCTIONAL 0x1415a7cf0: copies the character name and request values.
// @0x1415a7cf0
CNMCharacterLoginFunc::CNMCharacterLoginFunc(const char* sz30, int n74, int n78)
    : CNMFunc(0xf000, 1, 0, 0), m_30{}, m_70(0), m_74(n74), m_78(n78), m_7c(0)
{
    if (sz30)
        FUN_1415fbe70(m_30, sizeof(m_30), sz30);
}

// MS2-FUNCTIONAL 0x1415a7db0: wraps login encoding in a stream frame.
// @0x1415a7db0
unsigned int CNMCharacterLoginFunc::EncodeFramed(CNMStream* pStream)
{
    unsigned char storage[0x18];
    FUN_14156bcb0(storage, pStream, this);
    void** vtable = *reinterpret_cast<void***>(this);
    using Method = unsigned int(__fastcall*)(CNMCharacterLoginFunc*, CNMEncoder*, CNMStream*);
    const auto result = reinterpret_cast<Method>(vtable[2])(
        this, reinterpret_cast<CNMEncoder*>(storage), pStream);
    FUN_14156bd50(storage);
    return result;
}

// MS2-FUNCTIONAL 0x1415a7e10: chooses direct or framed request encoding.
// @0x1415a7e10
unsigned int CNMCharacterLoginFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    void** vtable = *reinterpret_cast<void***>(this);
    if (m_bFormat == 1) {
        using Method = unsigned int(__fastcall*)(CNMCharacterLoginFunc*, CNMEncoder*, CNMStream*);
        return reinterpret_cast<Method>(vtable[2])(this, pEncoder, pStream);
    }
    using Framed = unsigned int(__fastcall*)(CNMCharacterLoginFunc*, CNMStream*);
    return reinterpret_cast<Framed>(vtable[3])(this, pStream);
}

// MS2-FUNCTIONAL 0x1415a7e70: serializes the character name and three request values.
// @0x1415a7e70
unsigned int CNMCharacterLoginFunc::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMFunc::EncodeDispatch(pEncoder, pStream);
    if (FUN_1415fb700(this)) {
        FUN_14156ae30(pEncoder, m_30);
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_70));
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_74));
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_78));
    }
    FUN_1415f9990(pEncoder);
    return 1;
}

// MS2-FUNCTIONAL 0x1415a7f10: decodes a framed login response.
// @0x1415a7f10
unsigned int CNMCharacterLoginFunc::DecodeFramed(CNMStream* pStream)
{
    unsigned char storage[0x38];
    FUN_14156be10(storage, pStream, this);
    unsigned int result = 0;
    if (FUN_1415fb750(storage)) {
        void** vtable = *reinterpret_cast<void***>(this);
        using Method = unsigned int(__fastcall*)(CNMCharacterLoginFunc*, CNMSerializableDecoder*, CNMStream*);
        result = reinterpret_cast<Method>(vtable[5])(
            this, reinterpret_cast<CNMSerializableDecoder*>(storage), pStream);
    }
    FUN_14156bf10(storage);
    return result;
}

// MS2-FUNCTIONAL 0x1415a7fa0: chooses direct or framed response decoding.
// @0x1415a7fa0
unsigned int CNMCharacterLoginFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    void** vtable = *reinterpret_cast<void***>(this);
    if (FUN_1415fb6d0(pDecoder) == 2) {
        using Framed = unsigned int(__fastcall*)(CNMCharacterLoginFunc*, CNMStream*);
        return reinterpret_cast<Framed>(vtable[6])(this, pStream);
    }
    using Method = unsigned int(__fastcall*)(CNMCharacterLoginFunc*, CNMSerializableDecoder*, CNMStream*);
    return reinterpret_cast<Method>(vtable[5])(this, pDecoder, pStream);
}

// MS2-FUNCTIONAL 0x1415a8000: restores the character name and request values.
// @0x1415a8000
unsigned int CNMCharacterLoginFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    if (FUN_1415fb700(this)) {
        void** vtable = *reinterpret_cast<void***>(pDecoder);
        using Bytes = void(__fastcall*)(void*, void*, unsigned int);
        using U32 = unsigned int(__fastcall*)(void*);
        reinterpret_cast<Bytes>(vtable[9])(pDecoder, m_30, sizeof(m_30));
        m_70 = static_cast<int>(reinterpret_cast<U32>(vtable[3])(pDecoder));
        m_74 = static_cast<int>(reinterpret_cast<U32>(vtable[3])(pDecoder));
        m_78 = static_cast<int>(reinterpret_cast<U32>(vtable[3])(pDecoder));
    }
    return static_cast<unsigned int>(FUN_1415fb750(pDecoder));
}

// MS2-PIN: ??0CNMCharacterLoginFunc@@QEAA@XZ 0x1415a7c70
// MS2-PIN: ??0CNMCharacterLoginFunc@@QEAA@PEBDHH@Z 0x1415a7cf0
// MS2-PIN: ?EncodeFramed@CNMCharacterLoginFunc@@UEAAIPEAVCNMStream@@@Z 0x1415a7db0
// MS2-PIN: ?EncodeDispatch@CNMCharacterLoginFunc@@UEAAIPEAVCNMEncoder@@PEAVCNMStream@@@Z 0x1415a7e10
// MS2-PIN: ?Encode@CNMCharacterLoginFunc@@UEAAIPEAVCNMEncoder@@PEAVCNMStream@@@Z 0x1415a7e70
// MS2-PIN: ?DecodeFramed@CNMCharacterLoginFunc@@UEAAIPEAVCNMStream@@@Z 0x1415a7f10
// MS2-PIN: ?DecodeDispatch@CNMCharacterLoginFunc@@UEAAIPEAVCNMSerializableDecoder@@PEAVCNMStream@@@Z 0x1415a7fa0
// MS2-PIN: ?Decode@CNMCharacterLoginFunc@@UEAAIPEAVCNMSerializableDecoder@@PEAVCNMStream@@@Z 0x1415a8000

// MS2-FUNCTIONAL 0x1415a80c0: initializes a character-login request.
// @0x1415a80c0
CNMCharacterLogoutFunc::CNMCharacterLogoutFunc()
    : CNMFunc(0xf001, 1, 0, 0), m_30{}, m_70(0), m_74(0), m_78(1), m_7c(0)
{
}

// MS2-FUNCTIONAL 0x1415a8140: copies the character name and request values.
// @0x1415a8140
CNMCharacterLogoutFunc::CNMCharacterLogoutFunc(const char* sz30, int n74, int n78)
    : CNMFunc(0xf001, 1, 0, 0), m_30{}, m_70(0), m_74(n74), m_78(n78), m_7c(0)
{
    if (sz30)
        FUN_1415fbe70(m_30, sizeof(m_30), sz30);
}

// MS2-FUNCTIONAL 0x1415a8200: wraps login encoding in a stream frame.
// @0x1415a8200
unsigned int CNMCharacterLogoutFunc::EncodeFramed(CNMStream* pStream)
{
    unsigned char storage[0x18];
    FUN_14156bcb0(storage, pStream, this);
    void** vtable = *reinterpret_cast<void***>(this);
    using Method = unsigned int(__fastcall*)(CNMCharacterLogoutFunc*, CNMEncoder*, CNMStream*);
    const auto result = reinterpret_cast<Method>(vtable[2])(
        this, reinterpret_cast<CNMEncoder*>(storage), pStream);
    FUN_14156bd50(storage);
    return result;
}

// MS2-FUNCTIONAL 0x1415a8260: chooses direct or framed request encoding.
// @0x1415a8260
unsigned int CNMCharacterLogoutFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    void** vtable = *reinterpret_cast<void***>(this);
    if (m_bFormat == 1) {
        using Method = unsigned int(__fastcall*)(CNMCharacterLogoutFunc*, CNMEncoder*, CNMStream*);
        return reinterpret_cast<Method>(vtable[2])(this, pEncoder, pStream);
    }
    using Framed = unsigned int(__fastcall*)(CNMCharacterLogoutFunc*, CNMStream*);
    return reinterpret_cast<Framed>(vtable[3])(this, pStream);
}

// MS2-FUNCTIONAL 0x1415a82c0: serializes the character name and three request values.
// @0x1415a82c0
unsigned int CNMCharacterLogoutFunc::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMFunc::EncodeDispatch(pEncoder, pStream);
    if (FUN_1415fb700(this)) {
        FUN_14156ae30(pEncoder, m_30);
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_70));
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_74));
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_78));
    }
    FUN_1415f9990(pEncoder);
    return 1;
}

// MS2-FUNCTIONAL 0x1415a8360: decodes a framed login response.
// @0x1415a8360
unsigned int CNMCharacterLogoutFunc::DecodeFramed(CNMStream* pStream)
{
    unsigned char storage[0x38];
    FUN_14156be10(storage, pStream, this);
    unsigned int result = 0;
    if (FUN_1415fb750(storage)) {
        void** vtable = *reinterpret_cast<void***>(this);
        using Method = unsigned int(__fastcall*)(CNMCharacterLogoutFunc*, CNMSerializableDecoder*, CNMStream*);
        result = reinterpret_cast<Method>(vtable[5])(
            this, reinterpret_cast<CNMSerializableDecoder*>(storage), pStream);
    }
    FUN_14156bf10(storage);
    return result;
}

// MS2-FUNCTIONAL 0x1415a83f0: chooses direct or framed response decoding.
// @0x1415a83f0
unsigned int CNMCharacterLogoutFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    void** vtable = *reinterpret_cast<void***>(this);
    if (FUN_1415fb6d0(pDecoder) == 2) {
        using Framed = unsigned int(__fastcall*)(CNMCharacterLogoutFunc*, CNMStream*);
        return reinterpret_cast<Framed>(vtable[6])(this, pStream);
    }
    using Method = unsigned int(__fastcall*)(CNMCharacterLogoutFunc*, CNMSerializableDecoder*, CNMStream*);
    return reinterpret_cast<Method>(vtable[5])(this, pDecoder, pStream);
}

// MS2-FUNCTIONAL 0x1415a8450: restores the character name and request values.
// @0x1415a8450
unsigned int CNMCharacterLogoutFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    if (FUN_1415fb700(this)) {
        void** vtable = *reinterpret_cast<void***>(pDecoder);
        using Bytes = void(__fastcall*)(void*, void*, unsigned int);
        using U32 = unsigned int(__fastcall*)(void*);
        reinterpret_cast<Bytes>(vtable[9])(pDecoder, m_30, sizeof(m_30));
        m_70 = static_cast<int>(reinterpret_cast<U32>(vtable[3])(pDecoder));
        m_74 = static_cast<int>(reinterpret_cast<U32>(vtable[3])(pDecoder));
        m_78 = static_cast<int>(reinterpret_cast<U32>(vtable[3])(pDecoder));
    }
    return static_cast<unsigned int>(FUN_1415fb750(pDecoder));
}

// MS2-PIN: ??0CNMCharacterLogoutFunc@@QEAA@XZ 0x1415a80c0
// MS2-PIN: ??0CNMCharacterLogoutFunc@@QEAA@PEBDHH@Z 0x1415a8140
// MS2-PIN: ?EncodeFramed@CNMCharacterLogoutFunc@@UEAAIPEAVCNMStream@@@Z 0x1415a8200
// MS2-PIN: ?EncodeDispatch@CNMCharacterLogoutFunc@@UEAAIPEAVCNMEncoder@@PEAVCNMStream@@@Z 0x1415a8260
// MS2-PIN: ?Encode@CNMCharacterLogoutFunc@@UEAAIPEAVCNMEncoder@@PEAVCNMStream@@@Z 0x1415a82c0
// MS2-PIN: ?DecodeFramed@CNMCharacterLogoutFunc@@UEAAIPEAVCNMStream@@@Z 0x1415a8360
// MS2-PIN: ?DecodeDispatch@CNMCharacterLogoutFunc@@UEAAIPEAVCNMSerializableDecoder@@PEAVCNMStream@@@Z 0x1415a83f0
// MS2-PIN: ?Decode@CNMCharacterLogoutFunc@@UEAAIPEAVCNMSerializableDecoder@@PEAVCNMStream@@@Z 0x1415a8450

// MS2-FUNCTIONAL 0x1415a9230: initializes a 64-bit character-login request.
// @0x1415a9230
CNMCharacterLogin64Func::CNMCharacterLogin64Func()
    : CNMFunc(0xf004, 1, 0, 0), m_30{}, m_70(0), m_78(1), m_7c(0)
{
}

// MS2-FUNCTIONAL 0x1415a92b0: copies the character name and 64-bit request value.
// @0x1415a92b0
CNMCharacterLogin64Func::CNMCharacterLogin64Func(const char* sz30, long long n70, int n78)
    : CNMFunc(0xf004, 1, 0, 0), m_30{}, m_70(n70), m_78(n78), m_7c(0)
{
    if (sz30)
        FUN_1415fbe70(m_30, sizeof(m_30), sz30);
}

// MS2-FUNCTIONAL 0x1415a9360: frames the 64-bit login request.
// @0x1415a9360
unsigned int CNMCharacterLogin64Func::EncodeFramed(CNMStream* pStream)
{
    unsigned char storage[0x18]; FUN_14156bcb0(storage, pStream, this);
    void** v = *reinterpret_cast<void***>(this);
    using F = unsigned int(__fastcall*)(CNMCharacterLogin64Func*, CNMEncoder*, CNMStream*);
    auto r = reinterpret_cast<F>(v[2])(this, reinterpret_cast<CNMEncoder*>(storage), pStream);
    FUN_14156bd50(storage); return r;
}

// MS2-FUNCTIONAL 0x1415a93c0: selects direct or framed login encoding.
// @0x1415a93c0
unsigned int CNMCharacterLogin64Func::EncodeDispatch(CNMEncoder* e, CNMStream* s)
{
    void** v = *reinterpret_cast<void***>(this);
    if (m_bFormat == 1) { using F = unsigned int(__fastcall*)(CNMCharacterLogin64Func*, CNMEncoder*, CNMStream*); return reinterpret_cast<F>(v[2])(this,e,s); }
    using G = unsigned int(__fastcall*)(CNMCharacterLogin64Func*, CNMStream*); return reinterpret_cast<G>(v[3])(this,s);
}

// MS2-FUNCTIONAL 0x1415a9420: serializes the name and 64-bit login value.
// @0x1415a9420
unsigned int CNMCharacterLogin64Func::Encode(CNMEncoder* e, CNMStream* s)
{
    CNMFunc::EncodeDispatch(e,s);
    if (FUN_1415fb700(this)) { FUN_14156ae30(e,m_30); FUN_14156acb0(e,static_cast<unsigned __int64>(m_70)); FUN_14156ac20(e,static_cast<unsigned int>(m_78)); }
    FUN_1415f9990(e); return 1;
}

// MS2-FUNCTIONAL 0x1415a94b0: decodes a framed 64-bit login response.
// @0x1415a94b0
unsigned int CNMCharacterLogin64Func::DecodeFramed(CNMStream* s)
{
    unsigned char storage[0x38]; FUN_14156be10(storage,s,this); unsigned int r=0;
    if (FUN_1415fb750(storage)) { void** v=*reinterpret_cast<void***>(this); using F=unsigned int(__fastcall*)(CNMCharacterLogin64Func*,CNMSerializableDecoder*,CNMStream*); r=reinterpret_cast<F>(v[5])(this,reinterpret_cast<CNMSerializableDecoder*>(storage),s); }
    FUN_14156bf10(storage); return r;
}

// MS2-FUNCTIONAL 0x1415a9540: selects direct or framed response decoding.
// @0x1415a9540
unsigned int CNMCharacterLogin64Func::DecodeDispatch(CNMSerializableDecoder* d, CNMStream* s)
{
    void** v=*reinterpret_cast<void***>(this); if (FUN_1415fb6d0(d)==2) { using F=unsigned int(__fastcall*)(CNMCharacterLogin64Func*,CNMStream*); return reinterpret_cast<F>(v[6])(this,s); }
    using G=unsigned int(__fastcall*)(CNMCharacterLogin64Func*,CNMSerializableDecoder*,CNMStream*); return reinterpret_cast<G>(v[5])(this,d,s);
}

// MS2-FUNCTIONAL 0x1415a95a0: restores the name and 64-bit login value.
// @0x1415a95a0
unsigned int CNMCharacterLogin64Func::Decode(CNMSerializableDecoder* d, CNMStream* s)
{
    CNMFunc::DecodeDispatch(d,s); if (FUN_1415fb700(this)) { void** v=*reinterpret_cast<void***>(d); using B=void(__fastcall*)(void*,void*,unsigned int); using Q=unsigned __int64(__fastcall*)(void*); using U=unsigned int(__fastcall*)(void*); reinterpret_cast<B>(v[9])(d,m_30,sizeof(m_30)); m_70=static_cast<long long>(reinterpret_cast<Q>(v[4])(d)); m_78=static_cast<int>(reinterpret_cast<U>(v[3])(d)); }
    return static_cast<unsigned int>(FUN_1415fb750(d));
}

// MS2-PIN: ??0CNMCharacterLogin64Func@@QEAA@XZ 0x1415a9230
// MS2-PIN: ??0CNMCharacterLogin64Func@@QEAA@PEBD_JH@Z 0x1415a92b0
// MS2-PIN: ?EncodeFramed@CNMCharacterLogin64Func@@UEAAIPEAVCNMStream@@@Z 0x1415a9360
// MS2-PIN: ?EncodeDispatch@CNMCharacterLogin64Func@@UEAAIPEAVCNMEncoder@@PEAVCNMStream@@@Z 0x1415a93c0
// MS2-PIN: ?Encode@CNMCharacterLogin64Func@@UEAAIPEAVCNMEncoder@@PEAVCNMStream@@@Z 0x1415a9420
// MS2-PIN: ?DecodeFramed@CNMCharacterLogin64Func@@UEAAIPEAVCNMStream@@@Z 0x1415a94b0
// MS2-PIN: ?DecodeDispatch@CNMCharacterLogin64Func@@UEAAIPEAVCNMSerializableDecoder@@PEAVCNMStream@@@Z 0x1415a9540
// MS2-PIN: ?Decode@CNMCharacterLogin64Func@@UEAAIPEAVCNMSerializableDecoder@@PEAVCNMStream@@@Z 0x1415a95a0

// MS2-FUNCTIONAL 0x1415a9650: initializes a 64-bit character-login request.
// @0x1415a9650
CNMCharacterLogout64Func::CNMCharacterLogout64Func()
    : CNMFunc(0xf005, 1, 0, 0), m_30{}, m_70(0), m_78(1), m_7c(0)
{
}

// MS2-FUNCTIONAL 0x1415a96d0: copies the character name and 64-bit request value.
// @0x1415a96d0
CNMCharacterLogout64Func::CNMCharacterLogout64Func(const char* sz30, long long n70, int n78)
    : CNMFunc(0xf005, 1, 0, 0), m_30{}, m_70(n70), m_78(n78), m_7c(0)
{
    if (sz30)
        FUN_1415fbe70(m_30, sizeof(m_30), sz30);
}

// MS2-FUNCTIONAL 0x1415a9780: frames the 64-bit login request.
// @0x1415a9780
unsigned int CNMCharacterLogout64Func::EncodeFramed(CNMStream* pStream)
{
    unsigned char storage[0x18]; FUN_14156bcb0(storage, pStream, this);
    void** v = *reinterpret_cast<void***>(this);
    using F = unsigned int(__fastcall*)(CNMCharacterLogout64Func*, CNMEncoder*, CNMStream*);
    auto r = reinterpret_cast<F>(v[2])(this, reinterpret_cast<CNMEncoder*>(storage), pStream);
    FUN_14156bd50(storage); return r;
}

// MS2-FUNCTIONAL 0x1415a97e0: selects direct or framed login encoding.
// @0x1415a97e0
unsigned int CNMCharacterLogout64Func::EncodeDispatch(CNMEncoder* e, CNMStream* s)
{
    void** v = *reinterpret_cast<void***>(this);
    if (m_bFormat == 1) { using F = unsigned int(__fastcall*)(CNMCharacterLogout64Func*, CNMEncoder*, CNMStream*); return reinterpret_cast<F>(v[2])(this,e,s); }
    using G = unsigned int(__fastcall*)(CNMCharacterLogout64Func*, CNMStream*); return reinterpret_cast<G>(v[3])(this,s);
}

// MS2-FUNCTIONAL 0x1415a9840: serializes the name and 64-bit login value.
// @0x1415a9840
unsigned int CNMCharacterLogout64Func::Encode(CNMEncoder* e, CNMStream* s)
{
    CNMFunc::EncodeDispatch(e,s);
    if (FUN_1415fb700(this)) { FUN_14156ae30(e,m_30); FUN_14156acb0(e,static_cast<unsigned __int64>(m_70)); FUN_14156ac20(e,static_cast<unsigned int>(m_78)); }
    FUN_1415f9990(e); return 1;
}

// MS2-FUNCTIONAL 0x1415a98d0: decodes a framed 64-bit login response.
// @0x1415a98d0
unsigned int CNMCharacterLogout64Func::DecodeFramed(CNMStream* s)
{
    unsigned char storage[0x38]; FUN_14156be10(storage,s,this); unsigned int r=0;
    if (FUN_1415fb750(storage)) { void** v=*reinterpret_cast<void***>(this); using F=unsigned int(__fastcall*)(CNMCharacterLogout64Func*,CNMSerializableDecoder*,CNMStream*); r=reinterpret_cast<F>(v[5])(this,reinterpret_cast<CNMSerializableDecoder*>(storage),s); }
    FUN_14156bf10(storage); return r;
}

// MS2-FUNCTIONAL 0x1415a9960: selects direct or framed response decoding.
// @0x1415a9960
unsigned int CNMCharacterLogout64Func::DecodeDispatch(CNMSerializableDecoder* d, CNMStream* s)
{
    void** v=*reinterpret_cast<void***>(this); if (FUN_1415fb6d0(d)==2) { using F=unsigned int(__fastcall*)(CNMCharacterLogout64Func*,CNMStream*); return reinterpret_cast<F>(v[6])(this,s); }
    using G=unsigned int(__fastcall*)(CNMCharacterLogout64Func*,CNMSerializableDecoder*,CNMStream*); return reinterpret_cast<G>(v[5])(this,d,s);
}

// MS2-FUNCTIONAL 0x1415a99c0: restores the name and 64-bit login value.
// @0x1415a99c0
unsigned int CNMCharacterLogout64Func::Decode(CNMSerializableDecoder* d, CNMStream* s)
{
    CNMFunc::DecodeDispatch(d,s); if (FUN_1415fb700(this)) { void** v=*reinterpret_cast<void***>(d); using B=void(__fastcall*)(void*,void*,unsigned int); using Q=unsigned __int64(__fastcall*)(void*); using U=unsigned int(__fastcall*)(void*); reinterpret_cast<B>(v[9])(d,m_30,sizeof(m_30)); m_70=static_cast<long long>(reinterpret_cast<Q>(v[4])(d)); m_78=static_cast<int>(reinterpret_cast<U>(v[3])(d)); }
    return static_cast<unsigned int>(FUN_1415fb750(d));
}

// MS2-PIN: ??0CNMCharacterLogout64Func@@QEAA@XZ 0x1415a9650
// MS2-PIN: ??0CNMCharacterLogout64Func@@QEAA@PEBD_JH@Z 0x1415a96d0
// MS2-PIN: ?EncodeFramed@CNMCharacterLogout64Func@@UEAAIPEAVCNMStream@@@Z 0x1415a9780
// MS2-PIN: ?EncodeDispatch@CNMCharacterLogout64Func@@UEAAIPEAVCNMEncoder@@PEAVCNMStream@@@Z 0x1415a97e0
// MS2-PIN: ?Encode@CNMCharacterLogout64Func@@UEAAIPEAVCNMEncoder@@PEAVCNMStream@@@Z 0x1415a9840
// MS2-PIN: ?DecodeFramed@CNMCharacterLogout64Func@@UEAAIPEAVCNMStream@@@Z 0x1415a98d0
// MS2-PIN: ?DecodeDispatch@CNMCharacterLogout64Func@@UEAAIPEAVCNMSerializableDecoder@@PEAVCNMStream@@@Z 0x1415a9960
// MS2-PIN: ?Decode@CNMCharacterLogout64Func@@UEAAIPEAVCNMSerializableDecoder@@PEAVCNMStream@@@Z 0x1415a99c0


// MS2-FUNCTIONAL 0x1415a9a70: initializes a 64-bit character-login request.
// @0x1415a9a70
CNMCharacterRemove64Func::CNMCharacterRemove64Func()
    : CNMFunc(0xf006, 1, 0, 0), m_30{}, m_70(0), m_78(1), m_7c(0)
{
}

// MS2-FUNCTIONAL 0x1415a9af0: copies the character name and 64-bit request value.
// @0x1415a9af0
CNMCharacterRemove64Func::CNMCharacterRemove64Func(const char* sz30, long long n70, int n78)
    : CNMFunc(0xf006, 1, 0, 0), m_30{}, m_70(n70), m_78(n78), m_7c(0)
{
    if (sz30)
        FUN_1415fbe70(m_30, sizeof(m_30), sz30);
}

// MS2-FUNCTIONAL 0x1415a9ba0: frames the 64-bit login request.
// @0x1415a9ba0
unsigned int CNMCharacterRemove64Func::EncodeFramed(CNMStream* pStream)
{
    unsigned char storage[0x18]; FUN_14156bcb0(storage, pStream, this);
    void** v = *reinterpret_cast<void***>(this);
    using F = unsigned int(__fastcall*)(CNMCharacterRemove64Func*, CNMEncoder*, CNMStream*);
    auto r = reinterpret_cast<F>(v[2])(this, reinterpret_cast<CNMEncoder*>(storage), pStream);
    FUN_14156bd50(storage); return r;
}

// MS2-FUNCTIONAL 0x1415a9c00: selects direct or framed login encoding.
// @0x1415a9c00
unsigned int CNMCharacterRemove64Func::EncodeDispatch(CNMEncoder* e, CNMStream* s)
{
    void** v = *reinterpret_cast<void***>(this);
    if (m_bFormat == 1) { using F = unsigned int(__fastcall*)(CNMCharacterRemove64Func*, CNMEncoder*, CNMStream*); return reinterpret_cast<F>(v[2])(this,e,s); }
    using G = unsigned int(__fastcall*)(CNMCharacterRemove64Func*, CNMStream*); return reinterpret_cast<G>(v[3])(this,s);
}

// MS2-FUNCTIONAL 0x1415a9c60: serializes the name and 64-bit login value.
// @0x1415a9c60
unsigned int CNMCharacterRemove64Func::Encode(CNMEncoder* e, CNMStream* s)
{
    CNMFunc::EncodeDispatch(e,s);
    if (FUN_1415fb700(this)) { FUN_14156ae30(e,m_30); FUN_14156acb0(e,static_cast<unsigned __int64>(m_70)); FUN_14156ac20(e,static_cast<unsigned int>(m_78)); }
    FUN_1415f9990(e); return 1;
}

// MS2-FUNCTIONAL 0x1415a9cf0: decodes a framed 64-bit login response.
// @0x1415a9cf0
unsigned int CNMCharacterRemove64Func::DecodeFramed(CNMStream* s)
{
    unsigned char storage[0x38]; FUN_14156be10(storage,s,this); unsigned int r=0;
    if (FUN_1415fb750(storage)) { void** v=*reinterpret_cast<void***>(this); using F=unsigned int(__fastcall*)(CNMCharacterRemove64Func*,CNMSerializableDecoder*,CNMStream*); r=reinterpret_cast<F>(v[5])(this,reinterpret_cast<CNMSerializableDecoder*>(storage),s); }
    FUN_14156bf10(storage); return r;
}

// MS2-FUNCTIONAL 0x1415a9d80: selects direct or framed response decoding.
// @0x1415a9d80
unsigned int CNMCharacterRemove64Func::DecodeDispatch(CNMSerializableDecoder* d, CNMStream* s)
{
    void** v=*reinterpret_cast<void***>(this); if (FUN_1415fb6d0(d)==2) { using F=unsigned int(__fastcall*)(CNMCharacterRemove64Func*,CNMStream*); return reinterpret_cast<F>(v[6])(this,s); }
    using G=unsigned int(__fastcall*)(CNMCharacterRemove64Func*,CNMSerializableDecoder*,CNMStream*); return reinterpret_cast<G>(v[5])(this,d,s);
}

// MS2-FUNCTIONAL 0x1415a9de0: restores the name and 64-bit login value.
// @0x1415a9de0
unsigned int CNMCharacterRemove64Func::Decode(CNMSerializableDecoder* d, CNMStream* s)
{
    CNMFunc::DecodeDispatch(d,s); if (FUN_1415fb700(this)) { void** v=*reinterpret_cast<void***>(d); using B=void(__fastcall*)(void*,void*,unsigned int); using Q=unsigned __int64(__fastcall*)(void*); using U=unsigned int(__fastcall*)(void*); reinterpret_cast<B>(v[9])(d,m_30,sizeof(m_30)); m_70=static_cast<long long>(reinterpret_cast<Q>(v[4])(d)); m_78=static_cast<int>(reinterpret_cast<U>(v[3])(d)); }
    return static_cast<unsigned int>(FUN_1415fb750(d));
}

// MS2-PIN: ??0CNMCharacterRemove64Func@@QEAA@XZ 0x1415a9a70
// MS2-PIN: ??0CNMCharacterRemove64Func@@QEAA@PEBD_JH@Z 0x1415a9af0
// MS2-PIN: ?EncodeFramed@CNMCharacterRemove64Func@@UEAAIPEAVCNMStream@@@Z 0x1415a9ba0
// MS2-PIN: ?EncodeDispatch@CNMCharacterRemove64Func@@UEAAIPEAVCNMEncoder@@PEAVCNMStream@@@Z 0x1415a9c00
// MS2-PIN: ?Encode@CNMCharacterRemove64Func@@UEAAIPEAVCNMEncoder@@PEAVCNMStream@@@Z 0x1415a9c60
// MS2-PIN: ?DecodeFramed@CNMCharacterRemove64Func@@UEAAIPEAVCNMStream@@@Z 0x1415a9cf0
// MS2-PIN: ?DecodeDispatch@CNMCharacterRemove64Func@@UEAAIPEAVCNMSerializableDecoder@@PEAVCNMStream@@@Z 0x1415a9d80
// MS2-PIN: ?Decode@CNMCharacterRemove64Func@@UEAAIPEAVCNMSerializableDecoder@@PEAVCNMStream@@@Z 0x1415a9de0


// MS2-FUNCTIONAL 0x1415a9e90: initializes a 64-bit character-login request.
// @0x1415a9e90
CNMCharacterChangeName64Func::CNMCharacterChangeName64Func()
    : CNMFunc(0xf007, 1, 0, 0), m_30{}, m_70(0), m_78(1), m_7c(0)
{
}

// MS2-FUNCTIONAL 0x1415a9f10: copies the character name and 64-bit request value.
// @0x1415a9f10
CNMCharacterChangeName64Func::CNMCharacterChangeName64Func(const char* sz30, long long n70, int n78)
    : CNMFunc(0xf007, 1, 0, 0), m_30{}, m_70(n70), m_78(n78), m_7c(0)
{
    if (sz30)
        FUN_1415fbe70(m_30, sizeof(m_30), sz30);
}

// MS2-FUNCTIONAL 0x1415a9fc0: frames the 64-bit login request.
// @0x1415a9fc0
unsigned int CNMCharacterChangeName64Func::EncodeFramed(CNMStream* pStream)
{
    unsigned char storage[0x18]; FUN_14156bcb0(storage, pStream, this);
    void** v = *reinterpret_cast<void***>(this);
    using F = unsigned int(__fastcall*)(CNMCharacterChangeName64Func*, CNMEncoder*, CNMStream*);
    auto r = reinterpret_cast<F>(v[2])(this, reinterpret_cast<CNMEncoder*>(storage), pStream);
    FUN_14156bd50(storage); return r;
}

// MS2-FUNCTIONAL 0x1415aa020: selects direct or framed login encoding.
// @0x1415aa020
unsigned int CNMCharacterChangeName64Func::EncodeDispatch(CNMEncoder* e, CNMStream* s)
{
    void** v = *reinterpret_cast<void***>(this);
    if (m_bFormat == 1) { using F = unsigned int(__fastcall*)(CNMCharacterChangeName64Func*, CNMEncoder*, CNMStream*); return reinterpret_cast<F>(v[2])(this,e,s); }
    using G = unsigned int(__fastcall*)(CNMCharacterChangeName64Func*, CNMStream*); return reinterpret_cast<G>(v[3])(this,s);
}

// MS2-FUNCTIONAL 0x1415aa080: serializes the name and 64-bit login value.
// @0x1415aa080
unsigned int CNMCharacterChangeName64Func::Encode(CNMEncoder* e, CNMStream* s)
{
    CNMFunc::EncodeDispatch(e,s);
    if (FUN_1415fb700(this)) { FUN_14156ae30(e,m_30); FUN_14156acb0(e,static_cast<unsigned __int64>(m_70)); FUN_14156ac20(e,static_cast<unsigned int>(m_78)); }
    FUN_1415f9990(e); return 1;
}

// MS2-FUNCTIONAL 0x1415aa110: decodes a framed 64-bit login response.
// @0x1415aa110
unsigned int CNMCharacterChangeName64Func::DecodeFramed(CNMStream* s)
{
    unsigned char storage[0x38]; FUN_14156be10(storage,s,this); unsigned int r=0;
    if (FUN_1415fb750(storage)) { void** v=*reinterpret_cast<void***>(this); using F=unsigned int(__fastcall*)(CNMCharacterChangeName64Func*,CNMSerializableDecoder*,CNMStream*); r=reinterpret_cast<F>(v[5])(this,reinterpret_cast<CNMSerializableDecoder*>(storage),s); }
    FUN_14156bf10(storage); return r;
}

// MS2-FUNCTIONAL 0x1415aa1a0: selects direct or framed response decoding.
// @0x1415aa1a0
unsigned int CNMCharacterChangeName64Func::DecodeDispatch(CNMSerializableDecoder* d, CNMStream* s)
{
    void** v=*reinterpret_cast<void***>(this); if (FUN_1415fb6d0(d)==2) { using F=unsigned int(__fastcall*)(CNMCharacterChangeName64Func*,CNMStream*); return reinterpret_cast<F>(v[6])(this,s); }
    using G=unsigned int(__fastcall*)(CNMCharacterChangeName64Func*,CNMSerializableDecoder*,CNMStream*); return reinterpret_cast<G>(v[5])(this,d,s);
}

// MS2-FUNCTIONAL 0x1415aa200: restores the name and 64-bit login value.
// @0x1415aa200
unsigned int CNMCharacterChangeName64Func::Decode(CNMSerializableDecoder* d, CNMStream* s)
{
    CNMFunc::DecodeDispatch(d,s); if (FUN_1415fb700(this)) { void** v=*reinterpret_cast<void***>(d); using B=void(__fastcall*)(void*,void*,unsigned int); using Q=unsigned __int64(__fastcall*)(void*); using U=unsigned int(__fastcall*)(void*); reinterpret_cast<B>(v[9])(d,m_30,sizeof(m_30)); m_70=static_cast<long long>(reinterpret_cast<Q>(v[4])(d)); m_78=static_cast<int>(reinterpret_cast<U>(v[3])(d)); }
    return static_cast<unsigned int>(FUN_1415fb750(d));
}

// MS2-PIN: ??0CNMCharacterChangeName64Func@@QEAA@XZ 0x1415a9e90
// MS2-PIN: ??0CNMCharacterChangeName64Func@@QEAA@PEBD_JH@Z 0x1415a9f10
// MS2-PIN: ?EncodeFramed@CNMCharacterChangeName64Func@@UEAAIPEAVCNMStream@@@Z 0x1415a9fc0
// MS2-PIN: ?EncodeDispatch@CNMCharacterChangeName64Func@@UEAAIPEAVCNMEncoder@@PEAVCNMStream@@@Z 0x1415aa020
// MS2-PIN: ?Encode@CNMCharacterChangeName64Func@@UEAAIPEAVCNMEncoder@@PEAVCNMStream@@@Z 0x1415aa080
// MS2-PIN: ?DecodeFramed@CNMCharacterChangeName64Func@@UEAAIPEAVCNMStream@@@Z 0x1415aa110
// MS2-PIN: ?DecodeDispatch@CNMCharacterChangeName64Func@@UEAAIPEAVCNMSerializableDecoder@@PEAVCNMStream@@@Z 0x1415aa1a0
// MS2-PIN: ?Decode@CNMCharacterChangeName64Func@@UEAAIPEAVCNMSerializableDecoder@@PEAVCNMStream@@@Z 0x1415aa200


// MS2-FUNCTIONAL 0x1415a8d90: initializes a character synchronization request.
// @0x1415a8d90
CNMCharacterSyncFunc::CNMCharacterSyncFunc() : CNMFunc(0xf008,1,0,0), m_30{}, m_70(0), m_74(0), m_78(1), m_7c(0) {}
// MS2-FUNCTIONAL 0x1415a8e20: initializes synchronization values and name.
// @0x1415a8e20
CNMCharacterSyncFunc::CNMCharacterSyncFunc(const char* n, int a, int b, int c) : CNMFunc(0xf008,1,0,0), m_30{}, m_70(0), m_74(a), m_78(b), m_7c(c) { if(n) FUN_1415fbe70(m_30,sizeof(m_30),n); }
// MS2-FUNCTIONAL 0x1415a8ef0: frames the request encoder.
// @0x1415a8ef0
unsigned int CNMCharacterSyncFunc::EncodeFramed(CNMStream* s) { unsigned char b[0x18]; FUN_14156bcb0(b,s,this); void** v=*reinterpret_cast<void***>(this); using F=unsigned int(__fastcall*)(CNMCharacterSyncFunc*,CNMEncoder*,CNMStream*); auto r=reinterpret_cast<F>(v[2])(this,reinterpret_cast<CNMEncoder*>(b),s); FUN_14156bd50(b); return r; }

// MS2-FUNCTIONAL 0x1415a8f50: selects direct or framed request encoding.
// @0x1415a8f50
unsigned int CNMCharacterSyncFunc::EncodeDispatch(CNMEncoder* e,CNMStream* s) { void** v=*reinterpret_cast<void***>(this); if(m_bFormat==1) { using F=unsigned int(__fastcall*)(CNMCharacterSyncFunc*,CNMEncoder*,CNMStream*); return reinterpret_cast<F>(v[2])(this,e,s); } using G=unsigned int(__fastcall*)(CNMCharacterSyncFunc*,CNMStream*); return reinterpret_cast<G>(v[3])(this,s); }

// MS2-FUNCTIONAL 0x1415a9060: decodes a framed response.
// @0x1415a9060
unsigned int CNMCharacterSyncFunc::DecodeFramed(CNMStream* s) { unsigned char b[0x38]; FUN_14156be10(b,s,this); unsigned int r=0; if(FUN_1415fb750(b)) { void** v=*reinterpret_cast<void***>(this); using F=unsigned int(__fastcall*)(CNMCharacterSyncFunc*,CNMSerializableDecoder*,CNMStream*); r=reinterpret_cast<F>(v[5])(this,reinterpret_cast<CNMSerializableDecoder*>(b),s); } FUN_14156bf10(b); return r; }

// MS2-FUNCTIONAL 0x1415a90f0: selects direct or framed response decoding.
// @0x1415a90f0
unsigned int CNMCharacterSyncFunc::DecodeDispatch(CNMSerializableDecoder* d,CNMStream* s) { void** v=*reinterpret_cast<void***>(this); if(FUN_1415fb6d0(d)==2) { using F=unsigned int(__fastcall*)(CNMCharacterSyncFunc*,CNMStream*); return reinterpret_cast<F>(v[6])(this,s); } using G=unsigned int(__fastcall*)(CNMCharacterSyncFunc*,CNMSerializableDecoder*,CNMStream*); return reinterpret_cast<G>(v[5])(this,d,s); }

// MS2-FUNCTIONAL 0x1415a8fb0: serializes the name and three synchronization values.
// @0x1415a8fb0
unsigned int CNMCharacterSyncFunc::Encode(CNMEncoder* e,CNMStream* s) { CNMFunc::EncodeDispatch(e,s); if(FUN_1415fb700(this)) { FUN_14156ae30(e,m_30); FUN_14156ac20(e,m_70); FUN_14156ac20(e,m_74); FUN_14156ac20(e,m_78); FUN_14156ac20(e,m_7c); } FUN_1415f9990(e); return 1; }
// MS2-FUNCTIONAL 0x1415a9150: restores the name and synchronization values.
// @0x1415a9150
unsigned int CNMCharacterSyncFunc::Decode(CNMSerializableDecoder* d,CNMStream* s) { CNMFunc::DecodeDispatch(d,s); if(FUN_1415fb700(this)) { void** v=*reinterpret_cast<void***>(d); using B=void(__fastcall*)(void*,void*,unsigned int); using U=unsigned int(__fastcall*)(void*); reinterpret_cast<B>(v[9])(d,m_30,sizeof(m_30)); m_70=reinterpret_cast<U>(v[3])(d); m_74=reinterpret_cast<U>(v[3])(d); m_78=reinterpret_cast<U>(v[3])(d); m_7c=reinterpret_cast<U>(v[3])(d); } return FUN_1415fb750(d); }

// MS2-FUNCTIONAL 0x1415aa2b0: initializes a 64-bit character synchronization request.
// @0x1415aa2b0
CNMCharacterSync64Func::CNMCharacterSync64Func() : CNMFunc(0xf009,1,0,0), m_30{}, m_70(0), m_78(1), m_7c(0) {}
// MS2-FUNCTIONAL 0x1415aa330: initializes the 64-bit synchronization values and name.
// @0x1415aa330
CNMCharacterSync64Func::CNMCharacterSync64Func(const char* n, long long a, int b, int c) : CNMFunc(0xf009,1,0,0), m_30{}, m_70(a), m_78(b), m_7c(c) { if(n) FUN_1415fbe70(m_30,sizeof(m_30),n); }
// MS2-FUNCTIONAL 0x1415aa3f0: frames the request encoder.
// @0x1415aa3f0
unsigned int CNMCharacterSync64Func::EncodeFramed(CNMStream* s) { unsigned char b[0x18]; FUN_14156bcb0(b,s,this); void** v=*reinterpret_cast<void***>(this); using F=unsigned int(__fastcall*)(CNMCharacterSync64Func*,CNMEncoder*,CNMStream*); auto r=reinterpret_cast<F>(v[2])(this,reinterpret_cast<CNMEncoder*>(b),s); FUN_14156bd50(b); return r; }

// MS2-FUNCTIONAL 0x1415aa450: selects direct or framed request encoding.
// @0x1415aa450
unsigned int CNMCharacterSync64Func::EncodeDispatch(CNMEncoder* e,CNMStream* s) { void** v=*reinterpret_cast<void***>(this); if(m_bFormat==1) { using F=unsigned int(__fastcall*)(CNMCharacterSync64Func*,CNMEncoder*,CNMStream*); return reinterpret_cast<F>(v[2])(this,e,s); } using G=unsigned int(__fastcall*)(CNMCharacterSync64Func*,CNMStream*); return reinterpret_cast<G>(v[3])(this,s); }

// MS2-FUNCTIONAL 0x1415aa550: decodes a framed response.
// @0x1415aa550
unsigned int CNMCharacterSync64Func::DecodeFramed(CNMStream* s) { unsigned char b[0x38]; FUN_14156be10(b,s,this); unsigned int r=0; if(FUN_1415fb750(b)) { void** v=*reinterpret_cast<void***>(this); using F=unsigned int(__fastcall*)(CNMCharacterSync64Func*,CNMSerializableDecoder*,CNMStream*); r=reinterpret_cast<F>(v[5])(this,reinterpret_cast<CNMSerializableDecoder*>(b),s); } FUN_14156bf10(b); return r; }

// MS2-FUNCTIONAL 0x1415aa5e0: selects direct or framed response decoding.
// @0x1415aa5e0
unsigned int CNMCharacterSync64Func::DecodeDispatch(CNMSerializableDecoder* d,CNMStream* s) { void** v=*reinterpret_cast<void***>(this); if(FUN_1415fb6d0(d)==2) { using F=unsigned int(__fastcall*)(CNMCharacterSync64Func*,CNMStream*); return reinterpret_cast<F>(v[6])(this,s); } using G=unsigned int(__fastcall*)(CNMCharacterSync64Func*,CNMSerializableDecoder*,CNMStream*); return reinterpret_cast<G>(v[5])(this,d,s); }

// MS2-FUNCTIONAL 0x1415aa4b0: serializes the name, 64-bit ID and synchronization values.
// @0x1415aa4b0
unsigned int CNMCharacterSync64Func::Encode(CNMEncoder* e,CNMStream* s) { CNMFunc::EncodeDispatch(e,s); if(FUN_1415fb700(this)) { FUN_14156ae30(e,m_30); FUN_14156acb0(e,static_cast<unsigned __int64>(m_70)); FUN_14156ac20(e,m_78); FUN_14156ac20(e,m_7c); } FUN_1415f9990(e); return 1; }
// MS2-FUNCTIONAL 0x1415aa640: restores the name, 64-bit ID and synchronization values.
// @0x1415aa640
unsigned int CNMCharacterSync64Func::Decode(CNMSerializableDecoder* d,CNMStream* s) { CNMFunc::DecodeDispatch(d,s); if(FUN_1415fb700(this)) { void** v=*reinterpret_cast<void***>(d); using B=void(__fastcall*)(void*,void*,unsigned int); using Q=unsigned __int64(__fastcall*)(void*); using U=unsigned int(__fastcall*)(void*); reinterpret_cast<B>(v[9])(d,m_30,sizeof(m_30)); m_70=static_cast<long long>(reinterpret_cast<Q>(v[4])(d)); m_78=reinterpret_cast<U>(v[3])(d); m_7c=reinterpret_cast<U>(v[3])(d); } return FUN_1415fb750(d); }

// MS2-FUNCTIONAL 0x1415aa700: initializes an empty chat-channel close request.
// @0x1415aa700
CNMCHCloseFunc::CNMCHCloseFunc() : CNMFunc(0xd001,1,0,0) {}
// MS2-FUNCTIONAL 0x1415aa750: initializes a close request with the caller's option.
// @0x1415aa750
CNMCHCloseFunc::CNMCHCloseFunc(int n30) : CNMFunc(0xd001,1,n30,0) {}
// MS2-FUNCTIONAL 0x1415aa7a0: frames the request encoder.
// @0x1415aa7a0
unsigned int CNMCHCloseFunc::EncodeFramed(CNMStream* s) { unsigned char b[0x18]; FUN_14156bcb0(b,s,this); void** v=*reinterpret_cast<void***>(this); using F=unsigned int(__fastcall*)(CNMCHCloseFunc*,CNMEncoder*,CNMStream*); auto r=reinterpret_cast<F>(v[2])(this,reinterpret_cast<CNMEncoder*>(b),s); FUN_14156bd50(b); return r; }

// MS2-FUNCTIONAL 0x1415aa800: selects direct or framed request encoding.
// @0x1415aa800
unsigned int CNMCHCloseFunc::EncodeDispatch(CNMEncoder* e,CNMStream* s) { void** v=*reinterpret_cast<void***>(this); if(m_bFormat==1) { using F=unsigned int(__fastcall*)(CNMCHCloseFunc*,CNMEncoder*,CNMStream*); return reinterpret_cast<F>(v[2])(this,e,s); } using G=unsigned int(__fastcall*)(CNMCHCloseFunc*,CNMStream*); return reinterpret_cast<G>(v[3])(this,s); }

// MS2-FUNCTIONAL 0x1415aa8b0: decodes a framed response.
// @0x1415aa8b0
unsigned int CNMCHCloseFunc::DecodeFramed(CNMStream* s) { unsigned char b[0x38]; FUN_14156be10(b,s,this); unsigned int r=0; if(FUN_1415fb750(b)) { void** v=*reinterpret_cast<void***>(this); using F=unsigned int(__fastcall*)(CNMCHCloseFunc*,CNMSerializableDecoder*,CNMStream*); r=reinterpret_cast<F>(v[5])(this,reinterpret_cast<CNMSerializableDecoder*>(b),s); } FUN_14156bf10(b); return r; }

// MS2-FUNCTIONAL 0x1415aa940: selects direct or framed response decoding.
// @0x1415aa940
unsigned int CNMCHCloseFunc::DecodeDispatch(CNMSerializableDecoder* d,CNMStream* s) { void** v=*reinterpret_cast<void***>(this); if(FUN_1415fb6d0(d)==2) { using F=unsigned int(__fastcall*)(CNMCHCloseFunc*,CNMStream*); return reinterpret_cast<F>(v[6])(this,s); } using G=unsigned int(__fastcall*)(CNMCHCloseFunc*,CNMSerializableDecoder*,CNMStream*); return reinterpret_cast<G>(v[5])(this,d,s); }

// MS2-FUNCTIONAL 0x1415aa860: finalizes the empty close request payload.
// @0x1415aa860
unsigned int CNMCHCloseFunc::Encode(CNMEncoder* e,CNMStream* s) { CNMFunc::EncodeDispatch(e,s); FUN_1415f9990(e); return 1; }
// MS2-FUNCTIONAL 0x1415aa9a0: validates an empty close response.
// @0x1415aa9a0
unsigned int CNMCHCloseFunc::Decode(CNMSerializableDecoder* d,CNMStream* s) { CNMFunc::DecodeDispatch(d,s); return FUN_1415fb750(d); }

// MS2-FUNCTIONAL 0x1415aa9e0: initializes a channel-info query.
// @0x1415aa9e0
CNMCHGetChannelInfoFunc::CNMCHGetChannelInfoFunc() : CNMFunc(0xd002,1,0,0), m_30() {}
// MS2-FUNCTIONAL 0x1415aaa50: initializes a channel-info query with its option.
// @0x1415aaa50
CNMCHGetChannelInfoFunc::CNMCHGetChannelInfoFunc(int n18) : CNMFunc(0xd002,1,n18,0), m_30() {}
// MS2-FUNCTIONAL 0x1415aaac0: frames the request encoder.
// @0x1415aaac0
unsigned int CNMCHGetChannelInfoFunc::EncodeFramed(CNMStream* s) { unsigned char b[0x18]; FUN_14156bcb0(b,s,this); void** v=*reinterpret_cast<void***>(this); using F=unsigned int(__fastcall*)(CNMCHGetChannelInfoFunc*,CNMEncoder*,CNMStream*); auto r=reinterpret_cast<F>(v[2])(this,reinterpret_cast<CNMEncoder*>(b),s); FUN_14156bd50(b); return r; }

// MS2-FUNCTIONAL 0x1415aab20: selects direct or framed request encoding.
// @0x1415aab20
unsigned int CNMCHGetChannelInfoFunc::EncodeDispatch(CNMEncoder* e,CNMStream* s) { void** v=*reinterpret_cast<void***>(this); if(m_bFormat==1) { using F=unsigned int(__fastcall*)(CNMCHGetChannelInfoFunc*,CNMEncoder*,CNMStream*); return reinterpret_cast<F>(v[2])(this,e,s); } using G=unsigned int(__fastcall*)(CNMCHGetChannelInfoFunc*,CNMStream*); return reinterpret_cast<G>(v[3])(this,s); }

// MS2-FUNCTIONAL 0x1415aac00: decodes a framed response.
// @0x1415aac00
unsigned int CNMCHGetChannelInfoFunc::DecodeFramed(CNMStream* s) { unsigned char b[0x38]; FUN_14156be10(b,s,this); unsigned int r=0; if(FUN_1415fb750(b)) { void** v=*reinterpret_cast<void***>(this); using F=unsigned int(__fastcall*)(CNMCHGetChannelInfoFunc*,CNMSerializableDecoder*,CNMStream*); r=reinterpret_cast<F>(v[5])(this,reinterpret_cast<CNMSerializableDecoder*>(b),s); } FUN_14156bf10(b); return r; }

// MS2-FUNCTIONAL 0x1415aac90: selects direct or framed response decoding.
// @0x1415aac90
unsigned int CNMCHGetChannelInfoFunc::DecodeDispatch(CNMSerializableDecoder* d,CNMStream* s) { void** v=*reinterpret_cast<void***>(this); if(FUN_1415fb6d0(d)==2) { using F=unsigned int(__fastcall*)(CNMCHGetChannelInfoFunc*,CNMStream*); return reinterpret_cast<F>(v[6])(this,s); } using G=unsigned int(__fastcall*)(CNMCHGetChannelInfoFunc*,CNMSerializableDecoder*,CNMStream*); return reinterpret_cast<G>(v[5])(this,d,s); }

// MS2-FUNCTIONAL 0x1415aab80: writes a channel record for reply messages.
// @0x1415aab80
unsigned int CNMCHGetChannelInfoFunc::Encode(CNMEncoder* e,CNMStream* s) { CNMFunc::EncodeDispatch(e,s); if(FUN_1415fb720(this)) m_30.EncodeFramed(s); FUN_1415f9990(e); return 1; }
// MS2-FUNCTIONAL 0x1415aacf0: reads the channel record for reply messages.
// @0x1415aacf0
unsigned int CNMCHGetChannelInfoFunc::Decode(CNMSerializableDecoder* d,CNMStream* s) { CNMFunc::DecodeDispatch(d,s); if(FUN_1415fb720(this)) m_30.DecodeFramed(s); return FUN_1415fb750(d); }

// MS2-FUNCTIONAL 0x1415aad70: initializes a channel-info update request.
// @0x1415aad70
CNMCHChangeChannelInfoFunc::CNMCHChangeChannelInfoFunc() : CNMFunc(0xd003,1,0,0), m_30() {}
// MS2-FUNCTIONAL 0x1415aade0: initializes the request from a channel record.
// @0x1415aade0
CNMCHChangeChannelInfoFunc::CNMCHChangeChannelInfoFunc(int n18,const CNMClientChannelInfo& r) : CNMFunc(0xd003,1,n18,0), m_30(r) {}
// MS2-FUNCTIONAL 0x1415aae60: frames the request encoder.
// @0x1415aae60
unsigned int CNMCHChangeChannelInfoFunc::EncodeFramed(CNMStream* s) { unsigned char b[0x18]; FUN_14156bcb0(b,s,this); void** v=*reinterpret_cast<void***>(this); using F=unsigned int(__fastcall*)(CNMCHChangeChannelInfoFunc*,CNMEncoder*,CNMStream*); auto r=reinterpret_cast<F>(v[2])(this,reinterpret_cast<CNMEncoder*>(b),s); FUN_14156bd50(b); return r; }

// MS2-FUNCTIONAL 0x1415aaec0: selects direct or framed request encoding.
// @0x1415aaec0
unsigned int CNMCHChangeChannelInfoFunc::EncodeDispatch(CNMEncoder* e,CNMStream* s) { void** v=*reinterpret_cast<void***>(this); if(m_bFormat==1) { using F=unsigned int(__fastcall*)(CNMCHChangeChannelInfoFunc*,CNMEncoder*,CNMStream*); return reinterpret_cast<F>(v[2])(this,e,s); } using G=unsigned int(__fastcall*)(CNMCHChangeChannelInfoFunc*,CNMStream*); return reinterpret_cast<G>(v[3])(this,s); }

// MS2-FUNCTIONAL 0x1415aafa0: decodes a framed response.
// @0x1415aafa0
unsigned int CNMCHChangeChannelInfoFunc::DecodeFramed(CNMStream* s) { unsigned char b[0x38]; FUN_14156be10(b,s,this); unsigned int r=0; if(FUN_1415fb750(b)) { void** v=*reinterpret_cast<void***>(this); using F=unsigned int(__fastcall*)(CNMCHChangeChannelInfoFunc*,CNMSerializableDecoder*,CNMStream*); r=reinterpret_cast<F>(v[5])(this,reinterpret_cast<CNMSerializableDecoder*>(b),s); } FUN_14156bf10(b); return r; }

// MS2-FUNCTIONAL 0x1415ab030: selects direct or framed response decoding.
// @0x1415ab030
unsigned int CNMCHChangeChannelInfoFunc::DecodeDispatch(CNMSerializableDecoder* d,CNMStream* s) { void** v=*reinterpret_cast<void***>(this); if(FUN_1415fb6d0(d)==2) { using F=unsigned int(__fastcall*)(CNMCHChangeChannelInfoFunc*,CNMStream*); return reinterpret_cast<F>(v[6])(this,s); } using G=unsigned int(__fastcall*)(CNMCHChangeChannelInfoFunc*,CNMSerializableDecoder*,CNMStream*); return reinterpret_cast<G>(v[5])(this,d,s); }

// MS2-FUNCTIONAL 0x1415aaf20: serializes the updated channel record.
// @0x1415aaf20
unsigned int CNMCHChangeChannelInfoFunc::Encode(CNMEncoder* e,CNMStream* s) { CNMFunc::EncodeDispatch(e,s); if(FUN_1415fb700(this)) m_30.EncodeFramed(s); FUN_1415f9990(e); return 1; }
// MS2-FUNCTIONAL 0x1415ab090: decodes the channel record response.
// @0x1415ab090
unsigned int CNMCHChangeChannelInfoFunc::Decode(CNMSerializableDecoder* d,CNMStream* s) { CNMFunc::DecodeDispatch(d,s); if(FUN_1415fb700(this)) m_30.DecodeFramed(s); return FUN_1415fb750(d); }

// MS2-FUNCTIONAL 0x1415ab550: initializes a member-info update request.
// @0x1415ab550
CNMCHChangeMyInfoFunc::CNMCHChangeMyInfoFunc() : CNMFunc(0xd005,1,0,0), m_30() {}
// MS2-FUNCTIONAL 0x1415ab5c0: initializes a member-info update request with an option.
// @0x1415ab5c0
CNMCHChangeMyInfoFunc::CNMCHChangeMyInfoFunc(int n18) : CNMFunc(0xd005,1,n18,0), m_30() {}
// MS2-FUNCTIONAL 0x1415ab630: initializes the request from a member record.
// @0x1415ab630
CNMCHChangeMyInfoFunc::CNMCHChangeMyInfoFunc(int n18,const CNMChannelMemberInfo& r) : CNMFunc(0xd005,1,n18,0), m_30(r) {}
// MS2-FUNCTIONAL 0x1415ab6b0: frames the request encoder.
// @0x1415ab6b0
unsigned int CNMCHChangeMyInfoFunc::EncodeFramed(CNMStream* s) { unsigned char b[0x18]; FUN_14156bcb0(b,s,this); void** v=*reinterpret_cast<void***>(this); using F=unsigned int(__fastcall*)(CNMCHChangeMyInfoFunc*,CNMEncoder*,CNMStream*); auto r=reinterpret_cast<F>(v[2])(this,reinterpret_cast<CNMEncoder*>(b),s); FUN_14156bd50(b); return r; }

// MS2-FUNCTIONAL 0x1415ab710: selects direct or framed request encoding.
// @0x1415ab710
unsigned int CNMCHChangeMyInfoFunc::EncodeDispatch(CNMEncoder* e,CNMStream* s) { void** v=*reinterpret_cast<void***>(this); if(m_bFormat==1) { using F=unsigned int(__fastcall*)(CNMCHChangeMyInfoFunc*,CNMEncoder*,CNMStream*); return reinterpret_cast<F>(v[2])(this,e,s); } using G=unsigned int(__fastcall*)(CNMCHChangeMyInfoFunc*,CNMStream*); return reinterpret_cast<G>(v[3])(this,s); }

// MS2-FUNCTIONAL 0x1415ab7f0: decodes a framed response.
// @0x1415ab7f0
unsigned int CNMCHChangeMyInfoFunc::DecodeFramed(CNMStream* s) { unsigned char b[0x38]; FUN_14156be10(b,s,this); unsigned int r=0; if(FUN_1415fb750(b)) { void** v=*reinterpret_cast<void***>(this); using F=unsigned int(__fastcall*)(CNMCHChangeMyInfoFunc*,CNMSerializableDecoder*,CNMStream*); r=reinterpret_cast<F>(v[5])(this,reinterpret_cast<CNMSerializableDecoder*>(b),s); } FUN_14156bf10(b); return r; }

// MS2-FUNCTIONAL 0x1415ab880: selects direct or framed response decoding.
// @0x1415ab880
unsigned int CNMCHChangeMyInfoFunc::DecodeDispatch(CNMSerializableDecoder* d,CNMStream* s) { void** v=*reinterpret_cast<void***>(this); if(FUN_1415fb6d0(d)==2) { using F=unsigned int(__fastcall*)(CNMCHChangeMyInfoFunc*,CNMStream*); return reinterpret_cast<F>(v[6])(this,s); } using G=unsigned int(__fastcall*)(CNMCHChangeMyInfoFunc*,CNMSerializableDecoder*,CNMStream*); return reinterpret_cast<G>(v[5])(this,d,s); }

// MS2-FUNCTIONAL 0x1415ab770: writes the member record for update requests.
// @0x1415ab770
unsigned int CNMCHChangeMyInfoFunc::Encode(CNMEncoder* e,CNMStream* s) { CNMFunc::EncodeDispatch(e,s); if(FUN_1415fb700(this)) m_30.EncodeFramed(s); FUN_1415f9990(e); return 1; }
// MS2-FUNCTIONAL 0x1415ab8e0: reads the member record in update responses.
// @0x1415ab8e0
unsigned int CNMCHChangeMyInfoFunc::Decode(CNMSerializableDecoder* d,CNMStream* s) { CNMFunc::DecodeDispatch(d,s); if(FUN_1415fb720(this)) m_30.DecodeFramed(s); return FUN_1415fb750(d); }

extern void FUN_1415e5c00(void*);
extern void FUN_1415e5b20(void*, const char*);
extern void FUN_1415e5bc0(void*, const char*);
extern void* FUN_1415f39e0(void*);
extern void* FUN_1415f39f0(void*);
extern unsigned int FUN_1415fa080(void*);
extern void* FUN_1415f9fe0(void*);
extern unsigned int FUN_1415fa090(void*);
extern void* FUN_1415fa000(void*);

// MS2-FUNCTIONAL 0x1415ab960: initializes the invite strings.
// @0x1415ab960
CNMCHInviteUserFunc::CNMCHInviteUserFunc() : CNMFunc(0xd006,1,0,0)
{
    FUN_1415e5b60(&m_30); FUN_1415e5c00(&m_38);
}
// MS2-FUNCTIONAL 0x1415ab9e0: initializes the invite request and both strings.
// @0x1415ab9e0
CNMCHInviteUserFunc::CNMCHInviteUserFunc(int n18,const char* a,const char* b) : CNMFunc(0xd006,1,n18,0)
{
    FUN_1415e5b20(&m_30,a); FUN_1415e5bc0(&m_38,b);
}
// MS2-FUNCTIONAL 0x1415aba70: frames the request encoder.
// @0x1415aba70
unsigned int CNMCHInviteUserFunc::EncodeFramed(CNMStream* s) { unsigned char b[0x18]; FUN_14156bcb0(b,s,this); void** v=*reinterpret_cast<void***>(this); using F=unsigned int(__fastcall*)(CNMCHInviteUserFunc*,CNMEncoder*,CNMStream*); auto r=reinterpret_cast<F>(v[2])(this,reinterpret_cast<CNMEncoder*>(b),s); FUN_14156bd50(b); return r; }

// MS2-FUNCTIONAL 0x1415abad0: selects direct or framed request encoding.
// @0x1415abad0
unsigned int CNMCHInviteUserFunc::EncodeDispatch(CNMEncoder* e,CNMStream* s) { void** v=*reinterpret_cast<void***>(this); if(m_bFormat==1) { using F=unsigned int(__fastcall*)(CNMCHInviteUserFunc*,CNMEncoder*,CNMStream*); return reinterpret_cast<F>(v[2])(this,e,s); } using G=unsigned int(__fastcall*)(CNMCHInviteUserFunc*,CNMStream*); return reinterpret_cast<G>(v[3])(this,s); }

// MS2-FUNCTIONAL 0x1415abbc0: decodes a framed response.
// @0x1415abbc0
unsigned int CNMCHInviteUserFunc::DecodeFramed(CNMStream* s) { unsigned char b[0x38]; FUN_14156be10(b,s,this); unsigned int r=0; if(FUN_1415fb750(b)) { void** v=*reinterpret_cast<void***>(this); using F=unsigned int(__fastcall*)(CNMCHInviteUserFunc*,CNMSerializableDecoder*,CNMStream*); r=reinterpret_cast<F>(v[5])(this,reinterpret_cast<CNMSerializableDecoder*>(b),s); } FUN_14156bf10(b); return r; }

// MS2-FUNCTIONAL 0x1415abc50: selects direct or framed response decoding.
// @0x1415abc50
unsigned int CNMCHInviteUserFunc::DecodeDispatch(CNMSerializableDecoder* d,CNMStream* s) { void** v=*reinterpret_cast<void***>(this); if(FUN_1415fb6d0(d)==2) { using F=unsigned int(__fastcall*)(CNMCHInviteUserFunc*,CNMStream*); return reinterpret_cast<F>(v[6])(this,s); } using G=unsigned int(__fastcall*)(CNMCHInviteUserFunc*,CNMSerializableDecoder*,CNMStream*); return reinterpret_cast<G>(v[5])(this,d,s); }

// MS2-FUNCTIONAL 0x1415abb30: serializes both invite strings.
// @0x1415abb30
unsigned int CNMCHInviteUserFunc::Encode(CNMEncoder* e,CNMStream* s) { CNMFunc::EncodeDispatch(e,s); if(FUN_1415fb700(this)) { FUN_14156ae30(e,FUN_1415f39e0(&m_30)); FUN_14156ae30(e,FUN_1415f39f0(&m_38)); } FUN_1415f9990(e); return 1; }
// MS2-FUNCTIONAL 0x1415abcb0: restores both invite strings.
// @0x1415abcb0
unsigned int CNMCHInviteUserFunc::Decode(CNMSerializableDecoder* d,CNMStream* s) { CNMFunc::DecodeDispatch(d,s); if(FUN_1415fb700(this)) { void** v=*reinterpret_cast<void***>(d); using B=void(__fastcall*)(void*,void*,unsigned int); reinterpret_cast<B>(v[9])(d,FUN_1415f9fe0(&m_30),FUN_1415fa080(&m_30)); reinterpret_cast<B>(v[9])(d,FUN_1415fa000(&m_38),FUN_1415fa090(&m_38)); } return FUN_1415fb750(d); }

// MS2-FUNCTIONAL 0x1415ac0d0: initializes a channel-message request.
// @0x1415ac0d0
CNMCHSendChannelMessageFunc::CNMCHSendChannelMessageFunc() : CNMFunc(0xd008,1,0,0), m_30() {}
// MS2-FUNCTIONAL 0x1415ac140: initializes the request with its option.
// @0x1415ac140
CNMCHSendChannelMessageFunc::CNMCHSendChannelMessageFunc(int n18) : CNMFunc(0xd008,1,n18,0), m_30() {}
// MS2-FUNCTIONAL 0x1415ac1b0: initializes the request from message data.
// @0x1415ac1b0
CNMCHSendChannelMessageFunc::CNMCHSendChannelMessageFunc(int n18,const CNMChannelMessage& rMessage) : CNMFunc(0xd008,1,n18,0), m_30(rMessage) {}
// MS2-FUNCTIONAL 0x1415ac230: frames the request encoder.
// @0x1415ac230
unsigned int CNMCHSendChannelMessageFunc::EncodeFramed(CNMStream* s) { unsigned char b[0x18]; FUN_14156bcb0(b,s,this); void** v=*reinterpret_cast<void***>(this); using F=unsigned int(__fastcall*)(CNMCHSendChannelMessageFunc*,CNMEncoder*,CNMStream*); auto r=reinterpret_cast<F>(v[2])(this,reinterpret_cast<CNMEncoder*>(b),s); FUN_14156bd50(b); return r; }

// MS2-FUNCTIONAL 0x1415ac290: selects direct or framed request encoding.
// @0x1415ac290
unsigned int CNMCHSendChannelMessageFunc::EncodeDispatch(CNMEncoder* e,CNMStream* s) { void** v=*reinterpret_cast<void***>(this); if(m_bFormat==1) { using F=unsigned int(__fastcall*)(CNMCHSendChannelMessageFunc*,CNMEncoder*,CNMStream*); return reinterpret_cast<F>(v[2])(this,e,s); } using G=unsigned int(__fastcall*)(CNMCHSendChannelMessageFunc*,CNMStream*); return reinterpret_cast<G>(v[3])(this,s); }

// MS2-FUNCTIONAL 0x1415ac370: decodes a framed response.
// @0x1415ac370
unsigned int CNMCHSendChannelMessageFunc::DecodeFramed(CNMStream* s) { unsigned char b[0x38]; FUN_14156be10(b,s,this); unsigned int r=0; if(FUN_1415fb750(b)) { void** v=*reinterpret_cast<void***>(this); using F=unsigned int(__fastcall*)(CNMCHSendChannelMessageFunc*,CNMSerializableDecoder*,CNMStream*); r=reinterpret_cast<F>(v[5])(this,reinterpret_cast<CNMSerializableDecoder*>(b),s); } FUN_14156bf10(b); return r; }

// MS2-FUNCTIONAL 0x1415ac400: selects direct or framed response decoding.
// @0x1415ac400
unsigned int CNMCHSendChannelMessageFunc::DecodeDispatch(CNMSerializableDecoder* d,CNMStream* s) { void** v=*reinterpret_cast<void***>(this); if(FUN_1415fb6d0(d)==2) { using F=unsigned int(__fastcall*)(CNMCHSendChannelMessageFunc*,CNMStream*); return reinterpret_cast<F>(v[6])(this,s); } using G=unsigned int(__fastcall*)(CNMCHSendChannelMessageFunc*,CNMSerializableDecoder*,CNMStream*); return reinterpret_cast<G>(v[5])(this,d,s); }

// MS2-FUNCTIONAL 0x1415ac2f0: serializes the nested channel message.
// @0x1415ac2f0
unsigned int CNMCHSendChannelMessageFunc::Encode(CNMEncoder* e,CNMStream* s) { CNMFunc::EncodeDispatch(e,s); if(FUN_1415fb700(this)) m_30.EncodeFramed(s); FUN_1415f9990(e); return 1; }
// MS2-FUNCTIONAL 0x1415ac460: decodes the nested channel message.
// @0x1415ac460
unsigned int CNMCHSendChannelMessageFunc::Decode(CNMSerializableDecoder* d,CNMStream* s) { CNMFunc::DecodeDispatch(d,s); if(FUN_1415fb700(this)) m_30.DecodeFramed(s); return FUN_1415fb750(d); }

// MS2-FUNCTIONAL 0x1415ac4e0: initializes the game-log endpoint strings.
// @0x1415ac4e0
CNMGameLogInitializeFunc::CNMGameLogInitializeFunc() : CNMFunc(0xf010,1,0,0), m_30{}, m_50{}, m_150{} {}
// MS2-FUNCTIONAL 0x1415ac570: copies the three game-log endpoint strings.
// @0x1415ac570
CNMGameLogInitializeFunc::CNMGameLogInitializeFunc(const char* a,const char* b,const char* c) : CNMFunc(0xf010,1,0,0), m_30{}, m_50{}, m_150{} { if(a) FUN_1415fbe70(m_30,sizeof(m_30),a); if(b) FUN_1415fbe70(m_50,sizeof(m_50),b); if(c) FUN_1415fbe70(m_150,sizeof(m_150),c); }
// MS2-FUNCTIONAL 0x1415ac680: frames the request encoder.
// @0x1415ac680
unsigned int CNMGameLogInitializeFunc::EncodeFramed(CNMStream* s) { unsigned char b[0x18]; FUN_14156bcb0(b,s,this); void** v=*reinterpret_cast<void***>(this); using F=unsigned int(__fastcall*)(CNMGameLogInitializeFunc*,CNMEncoder*,CNMStream*); auto r=reinterpret_cast<F>(v[2])(this,reinterpret_cast<CNMEncoder*>(b),s); FUN_14156bd50(b); return r; }

// MS2-FUNCTIONAL 0x1415ac6e0: selects direct or framed request encoding.
// @0x1415ac6e0
unsigned int CNMGameLogInitializeFunc::EncodeDispatch(CNMEncoder* e,CNMStream* s) { void** v=*reinterpret_cast<void***>(this); if(m_bFormat==1) { using F=unsigned int(__fastcall*)(CNMGameLogInitializeFunc*,CNMEncoder*,CNMStream*); return reinterpret_cast<F>(v[2])(this,e,s); } using G=unsigned int(__fastcall*)(CNMGameLogInitializeFunc*,CNMStream*); return reinterpret_cast<G>(v[3])(this,s); }

// MS2-FUNCTIONAL 0x1415ac7e0: decodes a framed response.
// @0x1415ac7e0
unsigned int CNMGameLogInitializeFunc::DecodeFramed(CNMStream* s) { unsigned char b[0x38]; FUN_14156be10(b,s,this); unsigned int r=0; if(FUN_1415fb750(b)) { void** v=*reinterpret_cast<void***>(this); using F=unsigned int(__fastcall*)(CNMGameLogInitializeFunc*,CNMSerializableDecoder*,CNMStream*); r=reinterpret_cast<F>(v[5])(this,reinterpret_cast<CNMSerializableDecoder*>(b),s); } FUN_14156bf10(b); return r; }

// MS2-FUNCTIONAL 0x1415ac870: selects direct or framed response decoding.
// @0x1415ac870
unsigned int CNMGameLogInitializeFunc::DecodeDispatch(CNMSerializableDecoder* d,CNMStream* s) { void** v=*reinterpret_cast<void***>(this); if(FUN_1415fb6d0(d)==2) { using F=unsigned int(__fastcall*)(CNMGameLogInitializeFunc*,CNMStream*); return reinterpret_cast<F>(v[6])(this,s); } using G=unsigned int(__fastcall*)(CNMGameLogInitializeFunc*,CNMSerializableDecoder*,CNMStream*); return reinterpret_cast<G>(v[5])(this,d,s); }

// MS2-FUNCTIONAL 0x1415ac740: serializes the three game-log strings.
// @0x1415ac740
unsigned int CNMGameLogInitializeFunc::Encode(CNMEncoder* e,CNMStream* s) { CNMFunc::EncodeDispatch(e,s); if(FUN_1415fb700(this)) { FUN_14156ae30(e,m_30); FUN_14156ae30(e,m_50); FUN_14156ae30(e,m_150); } FUN_1415f9990(e); return 1; }
// MS2-FUNCTIONAL 0x1415ac8d0: restores the three game-log strings.
// @0x1415ac8d0
unsigned int CNMGameLogInitializeFunc::Decode(CNMSerializableDecoder* d,CNMStream* s) { CNMFunc::DecodeDispatch(d,s); if(FUN_1415fb700(this)) { void** v=*reinterpret_cast<void***>(d); using B=void(__fastcall*)(void*,void*,unsigned int); reinterpret_cast<B>(v[9])(d,m_30,sizeof(m_30)); reinterpret_cast<B>(v[9])(d,m_50,sizeof(m_50)); reinterpret_cast<B>(v[9])(d,m_150,sizeof(m_150)); } return FUN_1415fb750(d); }

// MS2-FUNCTIONAL 0x1415ac9b0: initializes the empty game-log finalize request.
// @0x1415ac9b0
CNMGameLogFinalizeFunc::CNMGameLogFinalizeFunc() : CNMFunc(0xf011,1,0,0) {}
// MS2-FUNCTIONAL 0x1415aca00: frames the request encoder.
// @0x1415aca00
unsigned int CNMGameLogFinalizeFunc::EncodeFramed(CNMStream* s) { unsigned char b[0x18]; FUN_14156bcb0(b,s,this); void** v=*reinterpret_cast<void***>(this); using F=unsigned int(__fastcall*)(CNMGameLogFinalizeFunc*,CNMEncoder*,CNMStream*); auto r=reinterpret_cast<F>(v[2])(this,reinterpret_cast<CNMEncoder*>(b),s); FUN_14156bd50(b); return r; }

// MS2-FUNCTIONAL 0x1415aca60: selects direct or framed request encoding.
// @0x1415aca60
unsigned int CNMGameLogFinalizeFunc::EncodeDispatch(CNMEncoder* e,CNMStream* s) { void** v=*reinterpret_cast<void***>(this); if(m_bFormat==1) { using F=unsigned int(__fastcall*)(CNMGameLogFinalizeFunc*,CNMEncoder*,CNMStream*); return reinterpret_cast<F>(v[2])(this,e,s); } using G=unsigned int(__fastcall*)(CNMGameLogFinalizeFunc*,CNMStream*); return reinterpret_cast<G>(v[3])(this,s); }

// MS2-FUNCTIONAL 0x1415acb10: decodes a framed response.
// @0x1415acb10
unsigned int CNMGameLogFinalizeFunc::DecodeFramed(CNMStream* s) { unsigned char b[0x38]; FUN_14156be10(b,s,this); unsigned int r=0; if(FUN_1415fb750(b)) { void** v=*reinterpret_cast<void***>(this); using F=unsigned int(__fastcall*)(CNMGameLogFinalizeFunc*,CNMSerializableDecoder*,CNMStream*); r=reinterpret_cast<F>(v[5])(this,reinterpret_cast<CNMSerializableDecoder*>(b),s); } FUN_14156bf10(b); return r; }

// MS2-FUNCTIONAL 0x1415acba0: selects direct or framed response decoding.
// @0x1415acba0
unsigned int CNMGameLogFinalizeFunc::DecodeDispatch(CNMSerializableDecoder* d,CNMStream* s) { void** v=*reinterpret_cast<void***>(this); if(FUN_1415fb6d0(d)==2) { using F=unsigned int(__fastcall*)(CNMGameLogFinalizeFunc*,CNMStream*); return reinterpret_cast<F>(v[6])(this,s); } using G=unsigned int(__fastcall*)(CNMGameLogFinalizeFunc*,CNMSerializableDecoder*,CNMStream*); return reinterpret_cast<G>(v[5])(this,d,s); }

// MS2-FUNCTIONAL 0x1415acac0: finalizes the empty game-log request payload.
// @0x1415acac0
unsigned int CNMGameLogFinalizeFunc::Encode(CNMEncoder* e,CNMStream* s) { CNMFunc::EncodeDispatch(e,s); (void)FUN_1415fb700(this); FUN_1415f9990(e); return 1; }
// MS2-FUNCTIONAL 0x1415acc00: validates the empty game-log response.
// @0x1415acc00
unsigned int CNMGameLogFinalizeFunc::Decode(CNMSerializableDecoder* d,CNMStream* s) { CNMFunc::DecodeDispatch(d,s); (void)FUN_1415fb700(this); return FUN_1415fb750(d); }

// MS2-FUNCTIONAL 0x1415a8510: initializes a character-remove request.
// @0x1415a8510
CNMCharacterRemoveFunc::CNMCharacterRemoveFunc() : CNMFunc(0xf002,1,0,0), m_30{}, m_38{}, m_78(1), m_7c(0) {}
// MS2-FUNCTIONAL 0x1415a8590: initializes the user key, name and remove option.
// @0x1415a8590
CNMCharacterRemoveFunc::CNMCharacterRemoveFunc(NMKey64 key,const char* name,int option) : CNMFunc(0xf002,1,0,0), m_30(key), m_38{}, m_78(option), m_7c(0) { if(name) FUN_1415fbe70(m_38,sizeof(m_38),name); }
// MS2-FUNCTIONAL 0x1415a8640: frames the request encoder.
// @0x1415a8640
unsigned int CNMCharacterRemoveFunc::EncodeFramed(CNMStream* s) { unsigned char b[0x18]; FUN_14156bcb0(b,s,this); void** v=*reinterpret_cast<void***>(this); using F=unsigned int(__fastcall*)(CNMCharacterRemoveFunc*,CNMEncoder*,CNMStream*); auto r=reinterpret_cast<F>(v[2])(this,reinterpret_cast<CNMEncoder*>(b),s); FUN_14156bd50(b); return r; }

// MS2-FUNCTIONAL 0x1415a86a0: selects direct or framed request encoding.
// @0x1415a86a0
unsigned int CNMCharacterRemoveFunc::EncodeDispatch(CNMEncoder* e,CNMStream* s) { void** v=*reinterpret_cast<void***>(this); if(m_bFormat==1) { using F=unsigned int(__fastcall*)(CNMCharacterRemoveFunc*,CNMEncoder*,CNMStream*); return reinterpret_cast<F>(v[2])(this,e,s); } using G=unsigned int(__fastcall*)(CNMCharacterRemoveFunc*,CNMStream*); return reinterpret_cast<G>(v[3])(this,s); }

// MS2-FUNCTIONAL 0x1415a87a0: decodes a framed response.
// @0x1415a87a0
unsigned int CNMCharacterRemoveFunc::DecodeFramed(CNMStream* s) { unsigned char b[0x38]; FUN_14156be10(b,s,this); unsigned int r=0; if(FUN_1415fb750(b)) { void** v=*reinterpret_cast<void***>(this); using F=unsigned int(__fastcall*)(CNMCharacterRemoveFunc*,CNMSerializableDecoder*,CNMStream*); r=reinterpret_cast<F>(v[5])(this,reinterpret_cast<CNMSerializableDecoder*>(b),s); } FUN_14156bf10(b); return r; }

// MS2-FUNCTIONAL 0x1415a8830: selects direct or framed response decoding.
// @0x1415a8830
unsigned int CNMCharacterRemoveFunc::DecodeDispatch(CNMSerializableDecoder* d,CNMStream* s) { void** v=*reinterpret_cast<void***>(this); if(FUN_1415fb6d0(d)==2) { using F=unsigned int(__fastcall*)(CNMCharacterRemoveFunc*,CNMStream*); return reinterpret_cast<F>(v[6])(this,s); } using G=unsigned int(__fastcall*)(CNMCharacterRemoveFunc*,CNMSerializableDecoder*,CNMStream*); return reinterpret_cast<G>(v[5])(this,d,s); }

// MS2-FUNCTIONAL 0x1415a8700: serializes the key, character name and option.
// @0x1415a8700
unsigned int CNMCharacterRemoveFunc::Encode(CNMEncoder* e,CNMStream* s) { CNMFunc::EncodeDispatch(e,s); if(FUN_1415fb700(this)) { FUN_14156ac20(e,m_30.nLow); FUN_14156ac20(e,m_30.nHigh); FUN_14156ae30(e,m_38); FUN_14156ac20(e,m_78); } FUN_1415f9990(e); return 1; }
// MS2-FUNCTIONAL 0x1415a8890: restores the key, name and option.
// @0x1415a8890
unsigned int CNMCharacterRemoveFunc::Decode(CNMSerializableDecoder* d,CNMStream* s) { CNMFunc::DecodeDispatch(d,s); if(FUN_1415fb700(this)) { void** v=*reinterpret_cast<void***>(d); using U=unsigned int(__fastcall*)(void*); using B=void(__fastcall*)(void*,void*,unsigned int); m_30.nLow=reinterpret_cast<U>(v[3])(d); m_30.nHigh=reinterpret_cast<U>(v[3])(d); reinterpret_cast<B>(v[9])(d,m_38,sizeof(m_38)); m_78=reinterpret_cast<U>(v[3])(d); } return FUN_1415fb750(d); }

// MS2-FUNCTIONAL 0x1415a8950: initializes a character-name update request.
// @0x1415a8950
CNMCharacterChangeNameFunc::CNMCharacterChangeNameFunc() : CNMFunc(0xf003,1,0,0), m_30{}, m_38{}, m_78(1), m_7c(0) {}
// MS2-FUNCTIONAL 0x1415a89d0: initializes the user key, name and update option.
// @0x1415a89d0
CNMCharacterChangeNameFunc::CNMCharacterChangeNameFunc(NMKey64 key,const char* name,int option) : CNMFunc(0xf003,1,0,0), m_30(key), m_38{}, m_78(option), m_7c(0) { if(name) FUN_1415fbe70(m_38,sizeof(m_38),name); }
// MS2-FUNCTIONAL 0x1415a8a80: frames the request encoder.
// @0x1415a8a80
unsigned int CNMCharacterChangeNameFunc::EncodeFramed(CNMStream* s) { unsigned char b[0x18]; FUN_14156bcb0(b,s,this); void** v=*reinterpret_cast<void***>(this); using F=unsigned int(__fastcall*)(CNMCharacterChangeNameFunc*,CNMEncoder*,CNMStream*); auto r=reinterpret_cast<F>(v[2])(this,reinterpret_cast<CNMEncoder*>(b),s); FUN_14156bd50(b); return r; }

// MS2-FUNCTIONAL 0x1415a8ae0: selects direct or framed request encoding.
// @0x1415a8ae0
unsigned int CNMCharacterChangeNameFunc::EncodeDispatch(CNMEncoder* e,CNMStream* s) { void** v=*reinterpret_cast<void***>(this); if(m_bFormat==1) { using F=unsigned int(__fastcall*)(CNMCharacterChangeNameFunc*,CNMEncoder*,CNMStream*); return reinterpret_cast<F>(v[2])(this,e,s); } using G=unsigned int(__fastcall*)(CNMCharacterChangeNameFunc*,CNMStream*); return reinterpret_cast<G>(v[3])(this,s); }

// MS2-FUNCTIONAL 0x1415a8be0: decodes a framed response.
// @0x1415a8be0
unsigned int CNMCharacterChangeNameFunc::DecodeFramed(CNMStream* s) { unsigned char b[0x38]; FUN_14156be10(b,s,this); unsigned int r=0; if(FUN_1415fb750(b)) { void** v=*reinterpret_cast<void***>(this); using F=unsigned int(__fastcall*)(CNMCharacterChangeNameFunc*,CNMSerializableDecoder*,CNMStream*); r=reinterpret_cast<F>(v[5])(this,reinterpret_cast<CNMSerializableDecoder*>(b),s); } FUN_14156bf10(b); return r; }

// MS2-FUNCTIONAL 0x1415a8c70: selects direct or framed response decoding.
// @0x1415a8c70
unsigned int CNMCharacterChangeNameFunc::DecodeDispatch(CNMSerializableDecoder* d,CNMStream* s) { void** v=*reinterpret_cast<void***>(this); if(FUN_1415fb6d0(d)==2) { using F=unsigned int(__fastcall*)(CNMCharacterChangeNameFunc*,CNMStream*); return reinterpret_cast<F>(v[6])(this,s); } using G=unsigned int(__fastcall*)(CNMCharacterChangeNameFunc*,CNMSerializableDecoder*,CNMStream*); return reinterpret_cast<G>(v[5])(this,d,s); }

// MS2-FUNCTIONAL 0x1415a8b40: serializes the key, new character name and option.
// @0x1415a8b40
unsigned int CNMCharacterChangeNameFunc::Encode(CNMEncoder* e,CNMStream* s) { CNMFunc::EncodeDispatch(e,s); if(FUN_1415fb700(this)) { FUN_14156ac20(e,m_30.nLow); FUN_14156ac20(e,m_30.nHigh); FUN_14156ae30(e,m_38); FUN_14156ac20(e,m_78); } FUN_1415f9990(e); return 1; }
// MS2-FUNCTIONAL 0x1415a8cd0: restores the user key, name and option.
// @0x1415a8cd0
unsigned int CNMCharacterChangeNameFunc::Decode(CNMSerializableDecoder* d,CNMStream* s) { CNMFunc::DecodeDispatch(d,s); if(FUN_1415fb700(this)) { void** v=*reinterpret_cast<void***>(d); using U=unsigned int(__fastcall*)(void*); using B=void(__fastcall*)(void*,void*,unsigned int); m_30.nLow=reinterpret_cast<U>(v[3])(d); m_30.nHigh=reinterpret_cast<U>(v[3])(d); reinterpret_cast<B>(v[9])(d,m_38,sizeof(m_38)); m_78=reinterpret_cast<U>(v[3])(d); } return FUN_1415fb750(d); }

// MS2-FUNCTIONAL 0x1415abd90: initializes an empty channel ban request.
// @0x1415abd90
CNMCHBanUserFunc::CNMCHBanUserFunc() : CNMFunc(0xd007,1,0,0), m_30(0), m_34(0) {}
// MS2-FUNCTIONAL 0x1415abde0: initializes the ban request value.
// @0x1415abde0
CNMCHBanUserFunc::CNMCHBanUserFunc(int n18,int n30) : CNMFunc(0xd007,1,n18,0), m_30(n30), m_34(0) {}
// MS2-FUNCTIONAL 0x1415abe40: frames the request encoder.
// @0x1415abe40
unsigned int CNMCHBanUserFunc::EncodeFramed(CNMStream* s) { unsigned char b[0x18]; FUN_14156bcb0(b,s,this); void** v=*reinterpret_cast<void***>(this); using F=unsigned int(__fastcall*)(CNMCHBanUserFunc*,CNMEncoder*,CNMStream*); auto r=reinterpret_cast<F>(v[2])(this,reinterpret_cast<CNMEncoder*>(b),s); FUN_14156bd50(b); return r; }

// MS2-FUNCTIONAL 0x1415abea0: selects direct or framed request encoding.
// @0x1415abea0
unsigned int CNMCHBanUserFunc::EncodeDispatch(CNMEncoder* e,CNMStream* s) { void** v=*reinterpret_cast<void***>(this); if(m_bFormat==1) { using F=unsigned int(__fastcall*)(CNMCHBanUserFunc*,CNMEncoder*,CNMStream*); return reinterpret_cast<F>(v[2])(this,e,s); } using G=unsigned int(__fastcall*)(CNMCHBanUserFunc*,CNMStream*); return reinterpret_cast<G>(v[3])(this,s); }

// MS2-FUNCTIONAL 0x1415abf70: decodes a framed response.
// @0x1415abf70
unsigned int CNMCHBanUserFunc::DecodeFramed(CNMStream* s) { unsigned char b[0x38]; FUN_14156be10(b,s,this); unsigned int r=0; if(FUN_1415fb750(b)) { void** v=*reinterpret_cast<void***>(this); using F=unsigned int(__fastcall*)(CNMCHBanUserFunc*,CNMSerializableDecoder*,CNMStream*); r=reinterpret_cast<F>(v[5])(this,reinterpret_cast<CNMSerializableDecoder*>(b),s); } FUN_14156bf10(b); return r; }

// MS2-FUNCTIONAL 0x1415ac000: selects direct or framed response decoding.
// @0x1415ac000
unsigned int CNMCHBanUserFunc::DecodeDispatch(CNMSerializableDecoder* d,CNMStream* s) { void** v=*reinterpret_cast<void***>(this); if(FUN_1415fb6d0(d)==2) { using F=unsigned int(__fastcall*)(CNMCHBanUserFunc*,CNMStream*); return reinterpret_cast<F>(v[6])(this,s); } using G=unsigned int(__fastcall*)(CNMCHBanUserFunc*,CNMSerializableDecoder*,CNMStream*); return reinterpret_cast<G>(v[5])(this,d,s); }

// MS2-FUNCTIONAL 0x1415abf00: serializes the ban request value.
// @0x1415abf00
unsigned int CNMCHBanUserFunc::Encode(CNMEncoder* e,CNMStream* s) { CNMFunc::EncodeDispatch(e,s); if(FUN_1415fb700(this)) FUN_14156ac20(e,static_cast<unsigned int>(m_30)); FUN_1415f9990(e); return 1; }
// MS2-FUNCTIONAL 0x1415ac060: restores the ban request value.
// @0x1415ac060
unsigned int CNMCHBanUserFunc::Decode(CNMSerializableDecoder* d,CNMStream* s) { CNMFunc::DecodeDispatch(d,s); if(FUN_1415fb700(this)) { void** v=*reinterpret_cast<void***>(d); using U=unsigned int(__fastcall*)(void*); m_30=static_cast<int>(reinterpret_cast<U>(v[3])(d)); } return FUN_1415fb750(d); }

// MS2-FUNCTIONAL 0x1415acc50: initializes a stage-log record.
// @0x1415acc50
CNMGameLogWriteStageLogFunc::CNMGameLogWriteStageLogFunc() : CNMFunc(0xf012,1,0,0), m_30(0), m_34{} {}
// MS2-FUNCTIONAL 0x1415accc0: initializes a stage-log record and copies its text.
// @0x1415accc0
CNMGameLogWriteStageLogFunc::CNMGameLogWriteStageLogFunc(int n30,const char* text) : CNMFunc(0xf012,1,0,0), m_30(n30), m_34{} { if(text) FUN_1415fbe70(m_34,sizeof(m_34),text); }
// MS2-FUNCTIONAL 0x1415acd60: frames the request encoder.
// @0x1415acd60
unsigned int CNMGameLogWriteStageLogFunc::EncodeFramed(CNMStream* s) { unsigned char b[0x18]; FUN_14156bcb0(b,s,this); void** v=*reinterpret_cast<void***>(this); using F=unsigned int(__fastcall*)(CNMGameLogWriteStageLogFunc*,CNMEncoder*,CNMStream*); auto r=reinterpret_cast<F>(v[2])(this,reinterpret_cast<CNMEncoder*>(b),s); FUN_14156bd50(b); return r; }

// MS2-FUNCTIONAL 0x1415acdc0: selects direct or framed request encoding.
// @0x1415acdc0
unsigned int CNMGameLogWriteStageLogFunc::EncodeDispatch(CNMEncoder* e,CNMStream* s) { void** v=*reinterpret_cast<void***>(this); if(m_bFormat==1) { using F=unsigned int(__fastcall*)(CNMGameLogWriteStageLogFunc*,CNMEncoder*,CNMStream*); return reinterpret_cast<F>(v[2])(this,e,s); } using G=unsigned int(__fastcall*)(CNMGameLogWriteStageLogFunc*,CNMStream*); return reinterpret_cast<G>(v[3])(this,s); }

// MS2-FUNCTIONAL 0x1415acea0: decodes a framed response.
// @0x1415acea0
unsigned int CNMGameLogWriteStageLogFunc::DecodeFramed(CNMStream* s) { unsigned char b[0x38]; FUN_14156be10(b,s,this); unsigned int r=0; if(FUN_1415fb750(b)) { void** v=*reinterpret_cast<void***>(this); using F=unsigned int(__fastcall*)(CNMGameLogWriteStageLogFunc*,CNMSerializableDecoder*,CNMStream*); r=reinterpret_cast<F>(v[5])(this,reinterpret_cast<CNMSerializableDecoder*>(b),s); } FUN_14156bf10(b); return r; }

// MS2-FUNCTIONAL 0x1415acf30: selects direct or framed response decoding.
// @0x1415acf30
unsigned int CNMGameLogWriteStageLogFunc::DecodeDispatch(CNMSerializableDecoder* d,CNMStream* s) { void** v=*reinterpret_cast<void***>(this); if(FUN_1415fb6d0(d)==2) { using F=unsigned int(__fastcall*)(CNMGameLogWriteStageLogFunc*,CNMStream*); return reinterpret_cast<F>(v[6])(this,s); } using G=unsigned int(__fastcall*)(CNMGameLogWriteStageLogFunc*,CNMSerializableDecoder*,CNMStream*); return reinterpret_cast<G>(v[5])(this,d,s); }

// MS2-FUNCTIONAL 0x1415ace20: serializes the stage-log code and text.
// @0x1415ace20
unsigned int CNMGameLogWriteStageLogFunc::Encode(CNMEncoder* e,CNMStream* s) { CNMFunc::EncodeDispatch(e,s); if(FUN_1415fb700(this)) { FUN_14156ac20(e,m_30); FUN_14156ae30(e,m_34); } FUN_1415f9990(e); return 1; }
// MS2-FUNCTIONAL 0x1415acf90: restores the stage-log code and text.
// @0x1415acf90
unsigned int CNMGameLogWriteStageLogFunc::Decode(CNMSerializableDecoder* d,CNMStream* s) { CNMFunc::DecodeDispatch(d,s); if(FUN_1415fb700(this)) { void** v=*reinterpret_cast<void***>(d); using U=unsigned int(__fastcall*)(void*); using B=void(__fastcall*)(void*,void*,unsigned int); m_30=reinterpret_cast<U>(v[3])(d); reinterpret_cast<B>(v[9])(d,m_34,sizeof(m_34)); } return FUN_1415fb750(d); }

// MS2-FUNCTIONAL 0x1415ad020: initializes an error-log record.
// @0x1415ad020
CNMGameLogWriteErrorLogFunc::CNMGameLogWriteErrorLogFunc() : CNMFunc(0xf013,1,0,0), m_30(0), m_34{} {}
// MS2-FUNCTIONAL 0x1415ad090: initializes an error-log record and copies its text.
// @0x1415ad090
CNMGameLogWriteErrorLogFunc::CNMGameLogWriteErrorLogFunc(int n30,const char* text) : CNMFunc(0xf013,1,0,0), m_30(n30), m_34{} { if(text) FUN_1415fbe70(m_34,sizeof(m_34),text); }
// MS2-FUNCTIONAL 0x1415ad130: frames the request encoder.
// @0x1415ad130
unsigned int CNMGameLogWriteErrorLogFunc::EncodeFramed(CNMStream* s) { unsigned char b[0x18]; FUN_14156bcb0(b,s,this); void** v=*reinterpret_cast<void***>(this); using F=unsigned int(__fastcall*)(CNMGameLogWriteErrorLogFunc*,CNMEncoder*,CNMStream*); auto r=reinterpret_cast<F>(v[2])(this,reinterpret_cast<CNMEncoder*>(b),s); FUN_14156bd50(b); return r; }

// MS2-FUNCTIONAL 0x1415ad190: selects direct or framed request encoding.
// @0x1415ad190
unsigned int CNMGameLogWriteErrorLogFunc::EncodeDispatch(CNMEncoder* e,CNMStream* s) { void** v=*reinterpret_cast<void***>(this); if(m_bFormat==1) { using F=unsigned int(__fastcall*)(CNMGameLogWriteErrorLogFunc*,CNMEncoder*,CNMStream*); return reinterpret_cast<F>(v[2])(this,e,s); } using G=unsigned int(__fastcall*)(CNMGameLogWriteErrorLogFunc*,CNMStream*); return reinterpret_cast<G>(v[3])(this,s); }

// MS2-FUNCTIONAL 0x1415ad270: decodes a framed response.
// @0x1415ad270
unsigned int CNMGameLogWriteErrorLogFunc::DecodeFramed(CNMStream* s) { unsigned char b[0x38]; FUN_14156be10(b,s,this); unsigned int r=0; if(FUN_1415fb750(b)) { void** v=*reinterpret_cast<void***>(this); using F=unsigned int(__fastcall*)(CNMGameLogWriteErrorLogFunc*,CNMSerializableDecoder*,CNMStream*); r=reinterpret_cast<F>(v[5])(this,reinterpret_cast<CNMSerializableDecoder*>(b),s); } FUN_14156bf10(b); return r; }

// MS2-FUNCTIONAL 0x1415ad300: selects direct or framed response decoding.
// @0x1415ad300
unsigned int CNMGameLogWriteErrorLogFunc::DecodeDispatch(CNMSerializableDecoder* d,CNMStream* s) { void** v=*reinterpret_cast<void***>(this); if(FUN_1415fb6d0(d)==2) { using F=unsigned int(__fastcall*)(CNMGameLogWriteErrorLogFunc*,CNMStream*); return reinterpret_cast<F>(v[6])(this,s); } using G=unsigned int(__fastcall*)(CNMGameLogWriteErrorLogFunc*,CNMSerializableDecoder*,CNMStream*); return reinterpret_cast<G>(v[5])(this,d,s); }

// MS2-FUNCTIONAL 0x1415ad1f0: serializes the error-log code and text.
// @0x1415ad1f0
unsigned int CNMGameLogWriteErrorLogFunc::Encode(CNMEncoder* e,CNMStream* s) { CNMFunc::EncodeDispatch(e,s); if(FUN_1415fb700(this)) { FUN_14156ac20(e,m_30); FUN_14156ae30(e,m_34); } FUN_1415f9990(e); return 1; }
// MS2-FUNCTIONAL 0x1415ad360: restores the error-log code and text.
// @0x1415ad360
unsigned int CNMGameLogWriteErrorLogFunc::Decode(CNMSerializableDecoder* d,CNMStream* s) { CNMFunc::DecodeDispatch(d,s); if(FUN_1415fb700(this)) { void** v=*reinterpret_cast<void***>(d); using U=unsigned int(__fastcall*)(void*); using B=void(__fastcall*)(void*,void*,unsigned int); m_30=reinterpret_cast<U>(v[3])(d); reinterpret_cast<B>(v[9])(d,m_34,sizeof(m_34)); } return FUN_1415fb750(d); }

// MS2-FUNCTIONAL 0x1415ad3f0: initializes the game-log session identifier result.
// @0x1415ad3f0
CNMGameLogGetSessionIDFunc::CNMGameLogGetSessionIDFunc() : CNMFunc(0xf014,1,0,0), m_30{} {}
// MS2-FUNCTIONAL 0x1415ad450: frames the request encoder.
// @0x1415ad450
unsigned int CNMGameLogGetSessionIDFunc::EncodeFramed(CNMStream* s) { unsigned char b[0x18]; FUN_14156bcb0(b,s,this); void** v=*reinterpret_cast<void***>(this); using F=unsigned int(__fastcall*)(CNMGameLogGetSessionIDFunc*,CNMEncoder*,CNMStream*); auto r=reinterpret_cast<F>(v[2])(this,reinterpret_cast<CNMEncoder*>(b),s); FUN_14156bd50(b); return r; }

// MS2-FUNCTIONAL 0x1415ad4b0: selects direct or framed request encoding.
// @0x1415ad4b0
unsigned int CNMGameLogGetSessionIDFunc::EncodeDispatch(CNMEncoder* e,CNMStream* s) { void** v=*reinterpret_cast<void***>(this); if(m_bFormat==1) { using F=unsigned int(__fastcall*)(CNMGameLogGetSessionIDFunc*,CNMEncoder*,CNMStream*); return reinterpret_cast<F>(v[2])(this,e,s); } using G=unsigned int(__fastcall*)(CNMGameLogGetSessionIDFunc*,CNMStream*); return reinterpret_cast<G>(v[3])(this,s); }

// MS2-FUNCTIONAL 0x1415ad580: decodes a framed response.
// @0x1415ad580
unsigned int CNMGameLogGetSessionIDFunc::DecodeFramed(CNMStream* s) { unsigned char b[0x38]; FUN_14156be10(b,s,this); unsigned int r=0; if(FUN_1415fb750(b)) { void** v=*reinterpret_cast<void***>(this); using F=unsigned int(__fastcall*)(CNMGameLogGetSessionIDFunc*,CNMSerializableDecoder*,CNMStream*); r=reinterpret_cast<F>(v[5])(this,reinterpret_cast<CNMSerializableDecoder*>(b),s); } FUN_14156bf10(b); return r; }

// MS2-FUNCTIONAL 0x1415ad610: selects direct or framed response decoding.
// @0x1415ad610
unsigned int CNMGameLogGetSessionIDFunc::DecodeDispatch(CNMSerializableDecoder* d,CNMStream* s) { void** v=*reinterpret_cast<void***>(this); if(FUN_1415fb6d0(d)==2) { using F=unsigned int(__fastcall*)(CNMGameLogGetSessionIDFunc*,CNMStream*); return reinterpret_cast<F>(v[6])(this,s); } using G=unsigned int(__fastcall*)(CNMGameLogGetSessionIDFunc*,CNMSerializableDecoder*,CNMStream*); return reinterpret_cast<G>(v[5])(this,d,s); }

// MS2-FUNCTIONAL 0x1415ad510: serializes the session identifier reply string.
// @0x1415ad510
unsigned int CNMGameLogGetSessionIDFunc::Encode(CNMEncoder* e,CNMStream* s) { CNMFunc::EncodeDispatch(e,s); if(FUN_1415fb720(this)) FUN_14156ae30(e,m_30); FUN_1415f9990(e); return 1; }
// MS2-FUNCTIONAL 0x1415ad670: restores the session identifier reply string.
// @0x1415ad670
unsigned int CNMGameLogGetSessionIDFunc::Decode(CNMSerializableDecoder* d,CNMStream* s) { CNMFunc::DecodeDispatch(d,s); if(FUN_1415fb720(this)) { void** v=*reinterpret_cast<void***>(d); using B=void(__fastcall*)(void*,void*,unsigned int); reinterpret_cast<B>(v[9])(d,m_30,sizeof(m_30)); } return FUN_1415fb750(d); }

// MS2-FUNCTIONAL 0x1415ab110: initializes an empty member-info result list.
// @0x1415ab110
CNMCHGetMemberInfoListFunc::CNMCHGetMemberInfoListFunc() : CNMFunc(0xd004,1,0,0), m_30() {}
// MS2-FUNCTIONAL 0x1415ab170: initializes a member-info query with its option.
// @0x1415ab170
CNMCHGetMemberInfoListFunc::CNMCHGetMemberInfoListFunc(int n18) : CNMFunc(0xd004,1,n18,0), m_30() {}
// MS2-FUNCTIONAL 0x1415ab1d0: frames the request encoder.
// @0x1415ab1d0
unsigned int CNMCHGetMemberInfoListFunc::EncodeFramed(CNMStream* s) { unsigned char b[0x18]; FUN_14156bcb0(b,s,this); void** v=*reinterpret_cast<void***>(this); using F=unsigned int(__fastcall*)(CNMCHGetMemberInfoListFunc*,CNMEncoder*,CNMStream*); auto r=reinterpret_cast<F>(v[2])(this,reinterpret_cast<CNMEncoder*>(b),s); FUN_14156bd50(b); return r; }

// MS2-FUNCTIONAL 0x1415ab230: selects direct or framed request encoding.
// @0x1415ab230
unsigned int CNMCHGetMemberInfoListFunc::EncodeDispatch(CNMEncoder* e,CNMStream* s) { void** v=*reinterpret_cast<void***>(this); if(m_bFormat==1) { using F=unsigned int(__fastcall*)(CNMCHGetMemberInfoListFunc*,CNMEncoder*,CNMStream*); return reinterpret_cast<F>(v[2])(this,e,s); } using G=unsigned int(__fastcall*)(CNMCHGetMemberInfoListFunc*,CNMStream*); return reinterpret_cast<G>(v[3])(this,s); }

// MS2-FUNCTIONAL 0x1415ab380: decodes a framed response.
// @0x1415ab380
unsigned int CNMCHGetMemberInfoListFunc::DecodeFramed(CNMStream* s) { unsigned char b[0x38]; FUN_14156be10(b,s,this); unsigned int r=0; if(FUN_1415fb750(b)) { void** v=*reinterpret_cast<void***>(this); using F=unsigned int(__fastcall*)(CNMCHGetMemberInfoListFunc*,CNMSerializableDecoder*,CNMStream*); r=reinterpret_cast<F>(v[5])(this,reinterpret_cast<CNMSerializableDecoder*>(b),s); } FUN_14156bf10(b); return r; }

// MS2-FUNCTIONAL 0x1415ab410: selects direct or framed response decoding.
// @0x1415ab410
unsigned int CNMCHGetMemberInfoListFunc::DecodeDispatch(CNMSerializableDecoder* d,CNMStream* s) { void** v=*reinterpret_cast<void***>(this); if(FUN_1415fb6d0(d)==2) { using F=unsigned int(__fastcall*)(CNMCHGetMemberInfoListFunc*,CNMStream*); return reinterpret_cast<F>(v[6])(this,s); } using G=unsigned int(__fastcall*)(CNMCHGetMemberInfoListFunc*,CNMSerializableDecoder*,CNMStream*); return reinterpret_cast<G>(v[5])(this,d,s); }

// MS2-FUNCTIONAL 0x1415ab290: writes the member count and each member record.
// @0x1415ab290
unsigned int CNMCHGetMemberInfoListFunc::Encode(CNMEncoder* e,CNMStream* s) { CNMFunc::EncodeDispatch(e,s); if(FUN_1415fb720(this)) { FUN_14156ac20(e,static_cast<unsigned int>(m_30.size())); for(auto& member:m_30) member.EncodeFramed(s); } FUN_1415f9990(e); return 1; }
// MS2-FUNCTIONAL 0x1415ab470: reads the member count and repopulates the result list.
// @0x1415ab470
unsigned int CNMCHGetMemberInfoListFunc::Decode(CNMSerializableDecoder* d,CNMStream* s) { CNMFunc::DecodeDispatch(d,s); if(FUN_1415fb720(this)) { void** v=*reinterpret_cast<void***>(d); using U=unsigned int(__fastcall*)(void*); const unsigned int count=reinterpret_cast<U>(v[3])(d); m_30.clear(); for(unsigned int i=0;i<count;++i) { m_30.emplace_back(); m_30.back().DecodeFramed(s); } } return FUN_1415fb750(d); }


// MS2-PIN: ??0CNMCharacterRemoveFunc@@QEAA@XZ 0x1415a8510
// MS2-PIN: ??0CNMCharacterChangeNameFunc@@QEAA@XZ 0x1415a8950
// MS2-PIN: ??0CNMCharacterSyncFunc@@QEAA@XZ 0x1415a8d90
// MS2-PIN: ??0CNMCharacterSync64Func@@QEAA@XZ 0x1415aa2b0
// MS2-PIN: ??0CNMCHCloseFunc@@QEAA@XZ 0x1415aa700
// MS2-PIN: ??0CNMCHGetChannelInfoFunc@@QEAA@XZ 0x1415aa9e0
// MS2-PIN: ??0CNMCHChangeChannelInfoFunc@@QEAA@XZ 0x1415aad70
// MS2-PIN: ??0CNMCHGetMemberInfoListFunc@@QEAA@XZ 0x1415ab110
// MS2-PIN: ??0CNMCHChangeMyInfoFunc@@QEAA@XZ 0x1415ab550
// MS2-PIN: ??0CNMCHInviteUserFunc@@QEAA@XZ 0x1415ab960
// MS2-PIN: ??0CNMCHBanUserFunc@@QEAA@XZ 0x1415abd90
// MS2-PIN: ??0CNMCHSendChannelMessageFunc@@QEAA@XZ 0x1415ac0d0
// MS2-PIN: ??0CNMGameLogInitializeFunc@@QEAA@XZ 0x1415ac4e0
// MS2-PIN: ??0CNMGameLogFinalizeFunc@@QEAA@XZ 0x1415ac9b0
// MS2-PIN: ??0CNMGameLogWriteStageLogFunc@@QEAA@XZ 0x1415acc50
// MS2-PIN: ??0CNMGameLogWriteErrorLogFunc@@QEAA@XZ 0x1415ad020
// MS2-PIN: ??0CNMGameLogGetSessionIDFunc@@QEAA@XZ 0x1415ad3f0


// Request factory: constructs the CNM*Func registered for each function ID.
// @0x1415ad6f0
CNMFunc* FUN_1415ad6f0(unsigned int functionId)
{
    switch (functionId)
    {
    case 0x1002:
        return new CNMRegisterCallbackFunc;
    case 0x1003:
        return new CNMResetCallbackFunc;
    case 0x1004:
        return new CNMAttachToNMCOServerFunc;
    case 0x1005:
        return new CNMDetachFromNMCOServerFunc;
    case 0x1006:
        return new CNMBringForwardStandAloneMsgFunc;
    case 0x1007:
        return new CNMStartStandAloneMsgFunc;
    case 0x1103:
        return new CNMLoginVirtualFunc;
    case 0x1104:
        return new CNMLogoutVirtualFunc;
    case 0x1105:
        return new CNMGetMyVirtualUserListFunc;
    case 0x1106:
        return new CNMChangeMyPositionFunc;
    case 0x1107:
        return new CNMSendRefreshMessageFunc;
    case 0x1108:
        return new CNMChangeMyLevelFunc;
    case 0x1109:
        return new CNMRemoveMyVirtualUserFunc;
    case 0x110a:
        return new CNMLoginPassportFunc;
    case 0x110c:
        return new CNMLoginNexonPassportFunc;
    case 0x110d:
        return new CNMLoginMessengerFunc;
    case 0x110e:
        return new CNMLogoutMessengerFunc;
    case 0x110f:
        return new CNMLoginAuthFunc;
    case 0x1112:
        return new CNMLoginAuthSecurityCNFunc;
    case 0x1110:
        return new CNMLogoutAuthFunc;
    case 0x1111:
        return new CNMInitializeFunc;
    case 0x1113:
        return new CNMGetGameTokenFunc;
    case 0x1114:
        return new CNMFinalizeFunc;
    case 0x1115:
        return new CNMPCBangLoginFunc;
    case 0x1119:
        return new CNMTPATokenLoginFunc;
    case 0x1118:
        return new CNMSetAuthClosedCallbackFunc;
    case 0x2001:
        return new CNMGetMyInfoFunc;
    case 0x2002:
        return new CNMGetUserDataListFunc;
    case 0x2003:
        return new CNMChangeMyInfoFunc;
    case 0x2004:
        return new CNMGetConfigFunc;
    case 0x2005:
        return new CNMChangeConfigFunc;
    case 0x2006:
        return new CNMGetLocalConfigFunc;
    case 0x2007:
        return new CNMChangeLocalConfigFunc;
    case 0x2008:
        return new CNMGetCountFunc;
    case 0x2009:
        return new CNMSetCountFunc;
    case 0x200a:
        return new CNMChangeNicknameFunc;
    case 0x200c:
        return new CNMRequestNewsFunc;
    case 0x200d:
        return new CNMCheckNewsFunc;
    case 0x200b:
        return new CNMChangeMetaDataFunc;
    case 0x2101:
        return new CNMGetDomainFunc;
    case 0x2103:
        return new CNMSetStatInfoFunc;
    case 0x2104:
        return new CNMSetLocaleFunc;
    case 0x2105:
        return new CNMGetNexonPassportFunc;
    case 0x2108:
        return new CNMGetSecurityCodeCNFunc;
    case 0x2106:
        return new CNMGetSecurityQuestionFunc;
    case 0x2107:
        return new CNMGetNxHWIDFunc;
    case 0x2109:
        return new CNMSetCodePageFunc;
    case 0x4001:
        return new CNMGetFriendListFunc;
    case 0x4002:
        return new CNMGetFriendInfoFunc;
    case 0x4003:
        return new CNMRequestNewFriendFunc;
    case 0x4004:
        return new CNMConfirmNewFriendFunc;
    case 0x4005:
        return new CNMBlockFriendFunc;
    case 0x4006:
        return new CNMChangeFriendMemoFunc;
    case 0x4007:
        return new CNMAddFriendToCategoryFunc;
    case 0x4008:
        return new CNMDeleteFriendFromCategoryFunc;
    case 0x4009:
        return new CNMMoveFriendCategoryFunc;
    case 0x400a:
        return new CNMChangeFriendMemoExFunc;
    case 0x4101:
        return new CNMAddCategoryFunc;
    case 0x4102:
        return new CNMDeleteCategoryFunc;
    case 0x4103:
        return new CNMChangeCategoryNameFunc;
    case 0x4104:
        return new CNMChangeCategoryPropertyFunc;
    case 0x4105:
        return new CNMChangeCategoryAllowTypeFunc;
    case 0x6001:
        return new CNMGetNoteBoxFunc;
    case 0x6002:
        return new CNMSendNoteMsgFunc;
    case 0x6006:
        return new CNMSendAccuseNoteMsgFunc;
    case 0x6003:
        return new CNMProcessNoteFunc;
    case 0x6004:
        return new CNMSendNoteInfoFunc;
    case 0x6005:
        return new CNMGetNoteBox2Func;
    case 0x5201:
        return new CNMGetRejectedUserListFunc;
    case 0x5202:
        return new CNMAppendRejectedUserFunc;
    case 0x5203:
        return new CNMRemoveRejectedUserFunc;
    case 0x7003:
        return new CNMGetMyGuildListExFunc;
    case 0x7002:
        return new CNMMonitorGuildOnlineInfoFunc;
    case 0x7004:
        return new CNMMonitorGuildOnlineInfoExFunc;
    case 0x8001:
        return new CNMExecutePatcherFunc;
    case 0x8002:
        return new CNMExecuteLauncherFunc;
    case 0x8003:
        return new CNMExecuteCommonFunc;
    case 0x8004:
        return new CNMGetUrlFunc;
    case 0x8005:
        return new CNMGetPathFunc;
    case 0x8006:
        return new CNMSetSessionValueFunc;
    case 0x8007:
        return new CNMGetSessionValueFunc;
    case 0x8008:
        return new CNMGetGameListFunc;
    case 0x8009:
        return new CNMGetUrlExFunc;
    case 0x801d:
        return new CNMDownloadGuildMarkFileFunc;
    case 0x800a:
        return new CNMDownloadFileFunc;
    case 0x800b:
        return new CNMUploadFileFunc;
    case 0x800c:
        return new CNMGetSupportGameListFunc;
    case 0x800d:
        return new CNMGetGameServerListFunc;
    case 0x800e:
        return new CNMGetGameFullNameFunc;
    case 0x800f:
        return new CNMGetGameShortNameFunc;
    case 0x8010:
        return new CNMGetGameFriendTitleFunc;
    case 0x8011:
        return new CNMGetGameServerNameFunc;
    case 0x8012:
        return new CNMGetConnConfigFunc;
    case 0x8013:
        return new CNMSetConnConfigFunc;
    case 0x8015:
        return new CNMExecuteNGMPatcherFunc;
    case 0x8022:
        return new CNMExecuteNGMPatcher2Func;
    case 0x8016:
        return new CNMExecuteNGMLauncherFunc;
    case 0x8020:
        return new CNMExecuteNGMInstallerFunc;
    case 0x8017:
        return new CNMIsNGMInstalledFunc;
    case 0x8018:
        return new CNMRestrictedWordsFunc;
    case 0x8019:
        return new CNMMinimizeAllFunc;
    case 0x801a:
        return new CNMLogReportSyncFunc;
    case 0x801c:
        return new CNMSetServerInfoFunc;
    case 0x801e:
        return new CNMGetServerInfoFunc;
    case 0x801f:
        return new CNMWriteToWiselogFunc;
    case 0x8021:
        return new CNMOpenGameSummaryFunc;
    case 0x9001:
        return new CNMGetUserInfoFunc;
    case 0x9002:
        return new CNMFindUserFunc;
    case 0x9003:
        return new CNMGetFindUserResultFunc;
    case 0x9004:
        return new CNMSendNoteExMsgFunc;
    case 0x9006:
        return new CNMCustomNotifyFunc;
    case 0xa001:
        return new CNMRequestChatSessionFunc;
    case 0xa00b:
        return new CNMRequestChatSessionExFunc;
    case 0xa002:
        return new CNMRequestMultiChatSessionFunc;
    case 0xa003:
        return new CNMRequestFileUploadSessionFunc;
    case 0xa00d:
        return new CNMRequestFileUploadSessionExFunc;
    case 0xa004:
        return new CNMRequestWBSessionFunc;
    case 0xa005:
        return new CNMReplySessionRequestFunc;
    case 0xa006:
        return new CNMCreateChatRoomFunc;
    case 0xa007:
        return new CNMJoinToChatRoomFunc;
    case 0xa008:
        return new CNMRequestSessionToOtherFunc;
    case 0xa009:
        return new CNMCreateChatRoomExFunc;
    case 0xa00a:
        return new CNMJoinToChatRoomExFunc;
    case 0xa010:
        return new CNMCreateChannelFunc;
    case 0xa011:
        return new CNMJoinChannelFunc;
    case 0xb001:
        return new CNMCRRegisterCallbackFunc;
    case 0xb002:
        return new CNMCRCloseFunc;
    case 0xb003:
        return new CNMCRGetRoomInfoFunc;
    case 0xb004:
        return new CNMCRChangeRoomInfoFunc;
    case 0xb005:
        return new CNMCRChangeMyInfoFunc;
    case 0xb006:
        return new CNMCRGetMemberListFunc;
    case 0xb007:
        return new CNMCRInviteUserFunc;
    case 0xb008:
        return new CNMCRBanUserFunc;
    case 0xb009:
        return new CNMCRSendChatMessageFunc;
    case 0xb00a:
        return new CNMCRGetMemberInfoFunc;
    case 0xb00b:
        return new CNMCRGetRoomInfoExFunc;
    case 0xc001:
        return new CNMGSRegisterCallbackFunc;
    case 0xc002:
        return new CNMGSWantCloseFunc;
    case 0xc003:
        return new CNMGSGetSessionInfoFunc;
    case 0xc004:
        return new CNMGSSetServingProcessIDFunc;
    case 0xc005:
        return new CNMGSGetMemberListFunc;
    case 0xc006:
        return new CNMGSInviteUserFunc;
    case 0xc008:
        return new CNMGSInviteUserExFunc;
    case 0xc007:
        return new CNMGSGetInviteCandidateListFunc;
    case 0xc101:
        return new CNMCSSendChatMessageFunc;
    case 0xc201:
        return new CNMFUDSGetFileEventFunc;
    case 0xc202:
        return new CNMFUSSendFileFunc;
    case 0xc203:
        return new CNMFUSControlFunc;
    case 0xc301:
        return new CNMFDSControlFunc;
    case 0xc302:
        return new CNMFDSGetDownloadDirFunc;
    case 0xc303:
        return new CNMFDSSetDownloadDirFunc;
    case 0xc401:
        return new CNMWSSendWBMessageFunc;
    case 0xc402:
        return new CNMWSGetAssocSerialKeyFunc;
    case 0xf000:
        return new CNMCharacterLoginFunc;
    case 0xf001:
        return new CNMCharacterLogoutFunc;
    case 0xf002:
        return new CNMCharacterRemoveFunc;
    case 0xf003:
        return new CNMCharacterChangeNameFunc;
    case 0xf008:
        return new CNMCharacterSyncFunc;
    case 0xf004:
        return new CNMCharacterLogin64Func;
    case 0xf005:
        return new CNMCharacterLogout64Func;
    case 0xf006:
        return new CNMCharacterRemove64Func;
    case 0xf007:
        return new CNMCharacterChangeName64Func;
    case 0xf009:
        return new CNMCharacterSync64Func;
    case 0xf010:
        return new CNMGameLogInitializeFunc;
    case 0xf011:
        return new CNMGameLogFinalizeFunc;
    case 0xf012:
        return new CNMGameLogWriteStageLogFunc;
    case 0xf013:
        return new CNMGameLogWriteErrorLogFunc;
    case 0xf014:
        return new CNMGameLogGetSessionIDFunc;
    case 0xd001:
        return new CNMCHCloseFunc;
    case 0xd002:
        return new CNMCHGetChannelInfoFunc;
    case 0xd003:
        return new CNMCHChangeChannelInfoFunc;
    case 0xd004:
        return new CNMCHGetMemberInfoListFunc;
    case 0xd005:
        return new CNMCHChangeMyInfoFunc;
    case 0xd006:
        return new CNMCHInviteUserFunc;
    case 0xd007:
        return new CNMCHBanUserFunc;
    case 0xd008:
        return new CNMCHSendChannelMessageFunc;
    }
    return nullptr;
}
