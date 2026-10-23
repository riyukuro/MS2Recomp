// Nexon Messenger get-my-info request serialization.
// MS2-UNIT: unit_141580880
// MS2-RANGE: 0x141580880-0x141580d00 .text$mn
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
extern void FUN_14156acb0(void*, unsigned long long);
extern void FUN_14156ae30(void*, const void*);
extern void FUN_1415f9990(void*);
extern int FUN_1415fb720(void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(void*);

// MS2-FUNCTIONAL 0x141580880: initializes the function ID and its real-user info payload.
// @0x141580880
CNMGetMyInfoFunc::CNMGetMyInfoFunc()
    : CNMFunc(0x2001, 1, 0, 0), m_30(), m_1d8(0), m_1e0(0), m_1e8(0), m_1ec(0), m_1f0{}
{
}

// MS2-FUNCTIONAL 0x141580940: frames the request and dispatches its encoder slot.
// @0x141580940
unsigned int CNMGetMyInfoFunc::EncodeFramed(CNMStream* pStream)
{
    unsigned char storage[0x18];
    FUN_14156bcb0(storage, pStream, this);
    void** vtable = *reinterpret_cast<void***>(this);
    using Method = unsigned int(__fastcall*)(CNMGetMyInfoFunc*, CNMEncoder*, CNMStream*);
    const unsigned int result = reinterpret_cast<Method>(vtable[2])(this, reinterpret_cast<CNMEncoder*>(storage), pStream);
    FUN_14156bd50(storage);
    return result;
}

// MS2-FUNCTIONAL 0x1415809a0: selects raw or framed encoding from the format flag.
// @0x1415809a0
unsigned int CNMGetMyInfoFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    void** vtable = *reinterpret_cast<void***>(this);
    if (m_bFormat == 1) {
        using Method = unsigned int(__fastcall*)(CNMGetMyInfoFunc*, CNMEncoder*, CNMStream*);
        return reinterpret_cast<Method>(vtable[2])(this, pEncoder, pStream);
    }
    using Framed = unsigned int(__fastcall*)(CNMGetMyInfoFunc*, CNMStream*);
    return reinterpret_cast<Framed>(vtable[3])(this, pStream);
}

// MS2-FUNCTIONAL 0x141580a00: serializes the real-user info and profile fields.
// @0x141580a00
unsigned int CNMGetMyInfoFunc::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMFunc::EncodeDispatch(pEncoder, pStream);
    if (FUN_1415fb720(this)) {
        m_30.EncodeFramed(pStream);
        FUN_14156acb0(pEncoder, static_cast<unsigned long long>(m_1d8));
        FUN_14156acb0(pEncoder, static_cast<unsigned long long>(m_1e0));
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_1e8));
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_1ec));
        FUN_14156ae30(pEncoder, m_1f0);
    }
    FUN_1415f9990(pEncoder);
    return 1;
}

// MS2-FUNCTIONAL 0x141580af0: decodes through a temporary framed decoder and the virtual decode slot.
// @0x141580af0
unsigned int CNMGetMyInfoFunc::DecodeFramed(CNMStream* pStream)
{
    unsigned char storage[0x38];
    FUN_14156be10(storage, pStream, this);
    unsigned int result = 0;
    if (FUN_1415fb750(storage)) {
        void** vtable = *reinterpret_cast<void***>(this);
        using Method = unsigned int(__fastcall*)(CNMGetMyInfoFunc*, CNMSerializableDecoder*, CNMStream*);
        result = reinterpret_cast<Method>(vtable[5])(this, reinterpret_cast<CNMSerializableDecoder*>(storage), pStream);
    }
    FUN_14156bf10(storage);
    return result;
}

// MS2-FUNCTIONAL 0x141580b80: chooses framed decoding for wire format 2.
// @0x141580b80
unsigned int CNMGetMyInfoFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    void** vtable = *reinterpret_cast<void***>(this);
    if (FUN_1415fb6d0(pDecoder) == 2) {
        using Framed = unsigned int(__fastcall*)(CNMGetMyInfoFunc*, CNMStream*);
        return reinterpret_cast<Framed>(vtable[6])(this, pStream);
    }
    using Method = unsigned int(__fastcall*)(CNMGetMyInfoFunc*, CNMSerializableDecoder*, CNMStream*);
    return reinterpret_cast<Method>(vtable[5])(this, pDecoder, pStream);
}

// MS2-FUNCTIONAL 0x141580be0: restores real-user data and scalar profile fields from the reply.
// @0x141580be0
unsigned int CNMGetMyInfoFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    if (FUN_1415fb720(this)) {
        m_30.DecodeFramed(pStream);
        void** vtable = *reinterpret_cast<void***>(pDecoder);
        using U32 = unsigned int(__fastcall*)(void*);
        using U64 = unsigned long long(__fastcall*)(void*);
        using Bytes = unsigned int(__fastcall*)(void*, void*, unsigned int);
        m_1d8 = static_cast<long long>(reinterpret_cast<U64>(vtable[4])(pDecoder));
        m_1e0 = static_cast<long long>(reinterpret_cast<U64>(vtable[4])(pDecoder));
        m_1e8 = static_cast<int>(reinterpret_cast<U32>(vtable[3])(pDecoder));
        m_1ec = static_cast<int>(reinterpret_cast<U32>(vtable[3])(pDecoder));
        reinterpret_cast<Bytes>(vtable[9])(pDecoder, m_1f0, 0x1000);
    }
    return static_cast<unsigned int>(FUN_1415fb750(pDecoder));
}

// MS2-PIN: ??0CNMGetMyInfoFunc@@QEAA@XZ 0x141580880
