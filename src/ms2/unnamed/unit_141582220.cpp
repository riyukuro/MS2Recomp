// Nexon Messenger get-local-config request serialization.
// MS2-UNIT: unit_141582220
// MS2-RANGE: 0x141582220-0x1415825b0 .text$mn
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

// MS2-FUNCTIONAL 0x141582220: initializes the local-config request with an empty string.
// @0x141582220
CNMGetLocalConfigFunc::CNMGetLocalConfigFunc()
    : CNMFunc(0x2006, 1, 0, 0), m_30(0), m_34{}
{
}

// MS2-FUNCTIONAL 0x141582290: stores the supplied request result code.
// @0x141582290
CNMGetLocalConfigFunc::CNMGetLocalConfigFunc(unsigned result)
    : CNMFunc(0x2006, 1, 0, 0), m_30(static_cast<int>(result)), m_34{}
{
}

// MS2-FUNCTIONAL 0x1415822f0: frames the request and dispatches its encoder slot.
// @0x1415822f0
unsigned int CNMGetLocalConfigFunc::EncodeFramed(CNMStream* pStream)
{
    unsigned char storage[0x18];
    FUN_14156bcb0(storage, pStream, this);
    void** vtable = *reinterpret_cast<void***>(this);
    using Method = unsigned int(__fastcall*)(CNMGetLocalConfigFunc*, CNMEncoder*, CNMStream*);
    const unsigned int encoded = reinterpret_cast<Method>(vtable[2])(this, reinterpret_cast<CNMEncoder*>(storage), pStream);
    FUN_14156bd50(storage);
    return encoded;
}

// MS2-FUNCTIONAL 0x141582350: selects raw or framed encoding from the format flag.
// @0x141582350
unsigned int CNMGetLocalConfigFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    void** vtable = *reinterpret_cast<void***>(this);
    if (m_bFormat == 1) {
        using Method = unsigned int(__fastcall*)(CNMGetLocalConfigFunc*, CNMEncoder*, CNMStream*);
        return reinterpret_cast<Method>(vtable[2])(this, pEncoder, pStream);
    }
    using Framed = unsigned int(__fastcall*)(CNMGetLocalConfigFunc*, CNMStream*);
    return reinterpret_cast<Framed>(vtable[3])(this, pStream);
}

// MS2-FUNCTIONAL 0x1415823b0: serializes either the request result or local configuration text.
// @0x1415823b0
unsigned int CNMGetLocalConfigFunc::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMFunc::EncodeDispatch(pEncoder, pStream);
    if (FUN_1415fb700(this) == 0) FUN_14156ae30(pEncoder, m_34);
    else FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_30));
    FUN_1415f9990(pEncoder);
    return 1;
}

// MS2-FUNCTIONAL 0x141582430: decodes through a temporary framed decoder and the virtual decode slot.
// @0x141582430
unsigned int CNMGetLocalConfigFunc::DecodeFramed(CNMStream* pStream)
{
    unsigned char storage[0x38];
    FUN_14156be10(storage, pStream, this);
    unsigned int result = 0;
    if (FUN_1415fb750(storage)) {
        void** vtable = *reinterpret_cast<void***>(this);
        using Method = unsigned int(__fastcall*)(CNMGetLocalConfigFunc*, CNMSerializableDecoder*, CNMStream*);
        result = reinterpret_cast<Method>(vtable[5])(this, reinterpret_cast<CNMSerializableDecoder*>(storage), pStream);
    }
    FUN_14156bf10(storage);
    return result;
}

// MS2-FUNCTIONAL 0x1415824c0: chooses framed decoding for wire format 2.
// @0x1415824c0
unsigned int CNMGetLocalConfigFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    void** vtable = *reinterpret_cast<void***>(this);
    if (FUN_1415fb6d0(pDecoder) == 2) {
        using Framed = unsigned int(__fastcall*)(CNMGetLocalConfigFunc*, CNMStream*);
        return reinterpret_cast<Framed>(vtable[6])(this, pStream);
    }
    using Method = unsigned int(__fastcall*)(CNMGetLocalConfigFunc*, CNMSerializableDecoder*, CNMStream*);
    return reinterpret_cast<Method>(vtable[5])(this, pDecoder, pStream);
}

// MS2-FUNCTIONAL 0x141582520: restores the reply result or local configuration buffer.
// @0x141582520
unsigned int CNMGetLocalConfigFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    if (FUN_1415fb700(this) == 0) {
        void** vtable = *reinterpret_cast<void***>(pDecoder);
        using Bytes = unsigned int(__fastcall*)(void*, void*, unsigned int);
        reinterpret_cast<Bytes>(vtable[9])(pDecoder, m_34, 0x400);
    } else {
        void** vtable = *reinterpret_cast<void***>(pDecoder);
        using U32 = unsigned int(__fastcall*)(void*);
        m_30 = static_cast<int>(reinterpret_cast<U32>(vtable[3])(pDecoder));
    }
    return static_cast<unsigned int>(FUN_1415fb750(pDecoder));
}

// MS2-PIN: ??0CNMGetLocalConfigFunc@@QEAA@XZ 0x141582220
