// Nexon Messenger user data list request and reply serialization.
// MS2-UNIT: unit_141580d00
// MS2-RANGE: 0x141580d00-0x141581070 .text$mn
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
extern void FUN_14156ac20(void*, unsigned int);
extern void FUN_14156af60(void*, const void*, unsigned int);
extern void FUN_1415f9990(void*);
extern int FUN_1415fb700(void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(void*);

// MS2-FUNCTIONAL 0x141580d00: initializes request and data-size fields.
// @0x141580d00
CNMGetUserDataListFunc::CNMGetUserDataListFunc()
    : CNMFunc(0x2002, 1, 0, 0), m_30(0), m_34(0), m_38(0)
{
}

// MS2-FUNCTIONAL 0x141580d70: frames the request and dispatches encoder slot.
// @0x141580d70
unsigned int CNMGetUserDataListFunc::EncodeFramed(CNMStream* pStream)
{
    unsigned char storage[0x18];
    FUN_14156bcb0(storage, pStream, this);
    void** vtable = *reinterpret_cast<void***>(this);
    using Method = unsigned int(__fastcall*)(CNMGetUserDataListFunc*, CNMEncoder*, CNMStream*);
    const unsigned int result = reinterpret_cast<Method>(vtable[2])(this, reinterpret_cast<CNMEncoder*>(storage), pStream);
    FUN_14156bd50(storage);
    return result;
}

// MS2-FUNCTIONAL 0x141580dd0: selects raw or framed encoding by format.
// @0x141580dd0
unsigned int CNMGetUserDataListFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    void** vtable = *reinterpret_cast<void***>(this);
    if (m_bFormat == 1) {
        using Method = unsigned int(__fastcall*)(CNMGetUserDataListFunc*, CNMEncoder*, CNMStream*);
        return reinterpret_cast<Method>(vtable[2])(this, pEncoder, pStream);
    }
    using Framed = unsigned int(__fastcall*)(CNMGetUserDataListFunc*, CNMStream*);
    return reinterpret_cast<Framed>(vtable[3])(this, pStream);
}

// MS2-FUNCTIONAL 0x141580e30: encodes request count/data or the reply result.
// @0x141580e30
unsigned int CNMGetUserDataListFunc::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMFunc::EncodeDispatch(pEncoder, pStream);
    if (FUN_1415fb700(this) == 0) {
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_34));
        FUN_14156af60(pEncoder, m_3c, static_cast<unsigned int>(m_38));
    } else {
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_30));
    }
    FUN_1415f9990(pEncoder);
    return 1;
}

// MS2-FUNCTIONAL 0x141580ed0: decodes through a temporary framed decoder.
// @0x141580ed0
unsigned int CNMGetUserDataListFunc::DecodeFramed(CNMStream* pStream)
{
    unsigned char storage[0x38];
    FUN_14156be10(storage, pStream, this);
    unsigned int result = 0;
    if (FUN_1415fb750(storage)) {
        void** vtable = *reinterpret_cast<void***>(this);
        using Method = unsigned int(__fastcall*)(CNMGetUserDataListFunc*, CNMSerializableDecoder*, CNMStream*);
        result = reinterpret_cast<Method>(vtable[5])(this, reinterpret_cast<CNMSerializableDecoder*>(storage), pStream);
    }
    FUN_14156bf10(storage);
    return result;
}

// MS2-FUNCTIONAL 0x141580f60: chooses framed decoding for wire format 2.
// @0x141580f60
unsigned int CNMGetUserDataListFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    void** vtable = *reinterpret_cast<void***>(this);
    if (FUN_1415fb6d0(pDecoder) == 2) {
        using Framed = unsigned int(__fastcall*)(CNMGetUserDataListFunc*, CNMStream*);
        return reinterpret_cast<Framed>(vtable[6])(this, pStream);
    }
    using Method = unsigned int(__fastcall*)(CNMGetUserDataListFunc*, CNMSerializableDecoder*, CNMStream*);
    return reinterpret_cast<Method>(vtable[5])(this, pDecoder, pStream);
}

// MS2-FUNCTIONAL 0x141580fc0: restores request data or the reply result.
// @0x141580fc0
unsigned int CNMGetUserDataListFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    void** vtable = *reinterpret_cast<void***>(pDecoder);
    using ReadU32 = unsigned int(__fastcall*)(void*);
    if (FUN_1415fb700(this) == 0) {
        m_34 = static_cast<int>(reinterpret_cast<ReadU32>(vtable[3])(pDecoder));
        using ReadBuffer = unsigned int(__fastcall*)(void*, void*, unsigned int);
        m_38 = static_cast<int>(reinterpret_cast<ReadBuffer>(vtable[11])(pDecoder, m_3c, 0));
    } else {
        m_30 = static_cast<int>(reinterpret_cast<ReadU32>(vtable[3])(pDecoder));
    }
    return static_cast<unsigned int>(FUN_1415fb750(pDecoder));
}

// MS2-PIN: ??0CNMGetUserDataListFunc@@QEAA@XZ 0x141580d00
