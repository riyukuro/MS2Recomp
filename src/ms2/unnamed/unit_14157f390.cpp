// Nexon Messenger virtual-user login request serialization.
// MS2-UNIT: unit_14157f390
// MS2-RANGE: 0x14157f390-0x14157f840 .text$mn
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
extern void FUN_14156ac20(void*, unsigned int);
extern void FUN_14156ae30(void*, const void*);
extern void FUN_1415f9990(void*);
extern int FUN_1415fb700(void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(void*);
extern void FUN_1415fbe70(void*, unsigned int, const void*);

// MS2-FUNCTIONAL: initializes the login request ID and zeroed virtual-user fields.
// @0x14157f390
CNMLoginVirtualFunc::CNMLoginVirtualFunc() : CNMFunc(0x1103, 1, 0, 0), m_30{}, m_70(0), m_74(0), m_78{} {}

// MS2-FUNCTIONAL 0x14157f420: copies optional login and password byte strings and stores the supplied value.
// @0x14157f420
CNMLoginVirtualFunc::CNMLoginVirtualFunc(long long login, int value, long long password)
    : CNMFunc(0x1103, 1, 0, 0), m_30{}, m_70(0), m_74(value), m_78{}
{
    if (login) FUN_1415fbe70(m_30, 0x40, reinterpret_cast<const void*>(login));
    if (password) FUN_1415fbe70(m_78, 0x40, reinterpret_cast<const void*>(password));
}

// MS2-FUNCTIONAL 0x14157f510: frames the request and dispatches its encoder slot.
// @0x14157f510
unsigned int CNMLoginVirtualFunc::EncodeFramed(CNMStream* pStream)
{
    unsigned char storage[0x18];
    FUN_14156bcb0(storage, pStream, this);
    void** vtable = *reinterpret_cast<void***>(this);
    using Method = unsigned int(__fastcall*)(CNMLoginVirtualFunc*, CNMEncoder*, CNMStream*);
    const unsigned int result = reinterpret_cast<Method>(vtable[2])(this, reinterpret_cast<CNMEncoder*>(storage), pStream);
    FUN_14156bd50(storage);
    return result;
}

// MS2-FUNCTIONAL 0x14157f570: selects raw or framed encoding from the format flag.
// @0x14157f570
unsigned int CNMLoginVirtualFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    void** vtable = *reinterpret_cast<void***>(this);
    if (m_bFormat == 1) {
        using Method = unsigned int(__fastcall*)(CNMLoginVirtualFunc*, CNMEncoder*, CNMStream*);
        return reinterpret_cast<Method>(vtable[2])(this, pEncoder, pStream);
    }
    using Framed = unsigned int(__fastcall*)(CNMLoginVirtualFunc*, CNMStream*);
    return reinterpret_cast<Framed>(vtable[3])(this, pStream);
}

// @0x14157f5d0
unsigned int CNMLoginVirtualFunc::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMFunc::EncodeDispatch(pEncoder, pStream);
    if (FUN_1415fb700(this)) {
        FUN_14156ae30(pEncoder, m_30);
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_70));
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_74));
        FUN_14156ae30(pEncoder, m_78);
    }
    FUN_1415f9990(pEncoder);
    return 1;
}

// MS2-FUNCTIONAL 0x14157f670: decodes through a temporary framed decoder and the virtual decode slot.
// @0x14157f670
unsigned int CNMLoginVirtualFunc::DecodeFramed(CNMStream* pStream)
{
    unsigned char storage[0x38];
    FUN_14156be10(storage, pStream, this);
    unsigned int result = 0;
    if (FUN_1415fb750(storage)) {
        void** vtable = *reinterpret_cast<void***>(this);
        using Method = unsigned int(__fastcall*)(CNMLoginVirtualFunc*, CNMSerializableDecoder*, CNMStream*);
        result = reinterpret_cast<Method>(vtable[5])(this, reinterpret_cast<CNMSerializableDecoder*>(storage), pStream);
    }
    FUN_14156bf10(storage);
    return result;
}

// MS2-FUNCTIONAL 0x14157f700: chooses framed decoding for wire format 2.
// @0x14157f700
unsigned int CNMLoginVirtualFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    void** vtable = *reinterpret_cast<void***>(this);
    if (FUN_1415fb6d0(pDecoder) == 2) {
        using Framed = unsigned int(__fastcall*)(CNMLoginVirtualFunc*, CNMStream*);
        return reinterpret_cast<Framed>(vtable[6])(this, pStream);
    }
    using Method = unsigned int(__fastcall*)(CNMLoginVirtualFunc*, CNMSerializableDecoder*, CNMStream*);
    return reinterpret_cast<Method>(vtable[5])(this, pDecoder, pStream);
}

// MS2-FUNCTIONAL 0x14157f760: restores the login fields from the reply decoder.
// @0x14157f760
unsigned int CNMLoginVirtualFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    if (FUN_1415fb700(this)) {
        void** vtable = *reinterpret_cast<void***>(pDecoder);
        using Bytes = unsigned int(__fastcall*)(void*, void*, unsigned int);
        using U32 = unsigned int(__fastcall*)(void*);
        reinterpret_cast<Bytes>(vtable[9])(pDecoder, m_30, 0x40);
        m_70 = static_cast<int>(reinterpret_cast<U32>(vtable[3])(pDecoder));
        m_74 = static_cast<int>(reinterpret_cast<U32>(vtable[3])(pDecoder));
        reinterpret_cast<Bytes>(vtable[9])(pDecoder, m_78, 0x40);
    }
    return static_cast<unsigned int>(FUN_1415fb750(pDecoder));
}

// MS2-PIN: ??0CNMLoginVirtualFunc@@QEAA@XZ 0x14157f390
