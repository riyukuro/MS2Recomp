// Nexon Messenger change-metadata request serialization.
// MS2-UNIT: unit_141583480
// MS2-RANGE: 0x141583480-0x141583880 .text$mn
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
extern void FUN_1415fbe70(void*, unsigned int, const void*);
extern void FUN_1415f9990(void*);
extern int FUN_1415fb700(void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(void*);

// MS2-FUNCTIONAL 0x141583480: initializes the request key and metadata buffer.
// @0x141583480
CNMChangeMetaDataFunc::CNMChangeMetaDataFunc()
    : CNMFunc(0x200b, 1, 0, 0), m_30{}, m_38{}
{
}

// MS2-FUNCTIONAL 0x1415834f0: stores the user key and copies an optional metadata.
// @0x1415834f0
CNMChangeMetaDataFunc::CNMChangeMetaDataFunc(long long key, long long metadata)
    : CNMFunc(0x200b, 1, 0, 0),
      m_30{static_cast<unsigned int>(key), static_cast<unsigned int>(static_cast<unsigned long long>(key) >> 32)},
      m_38{}
{
    if (metadata) FUN_1415fbe70(m_38, 0x3e8, reinterpret_cast<const void*>(metadata));
}

// MS2-FUNCTIONAL 0x141583590: frames the request and dispatches its encoder slot.
// @0x141583590
unsigned int CNMChangeMetaDataFunc::EncodeFramed(CNMStream* pStream)
{
    unsigned char storage[0x18];
    FUN_14156bcb0(storage, pStream, this);
    void** vtable = *reinterpret_cast<void***>(this);
    using Method = unsigned int(__fastcall*)(CNMChangeMetaDataFunc*, CNMEncoder*, CNMStream*);
    const unsigned int result = reinterpret_cast<Method>(vtable[2])(this, reinterpret_cast<CNMEncoder*>(storage), pStream);
    FUN_14156bd50(storage);
    return result;
}

// MS2-FUNCTIONAL 0x1415835f0: selects raw or framed encoding by the format flag.
// @0x1415835f0
unsigned int CNMChangeMetaDataFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    void** vtable = *reinterpret_cast<void***>(this);
    if (m_bFormat == 1) {
        using Method = unsigned int(__fastcall*)(CNMChangeMetaDataFunc*, CNMEncoder*, CNMStream*);
        return reinterpret_cast<Method>(vtable[2])(this, pEncoder, pStream);
    }
    using Framed = unsigned int(__fastcall*)(CNMChangeMetaDataFunc*, CNMStream*);
    return reinterpret_cast<Framed>(vtable[3])(this, pStream);
}

// MS2-FUNCTIONAL 0x141583650: encodes the key and metadata when the direction carries a reply.
// @0x141583650
unsigned int CNMChangeMetaDataFunc::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMFunc::EncodeDispatch(pEncoder, pStream);
    if (FUN_1415fb700(this)) {
        FUN_14156ac20(pEncoder, m_30.nLow);
        FUN_14156ac20(pEncoder, m_30.nHigh);
        FUN_14156ae30(pEncoder, m_38);
    }
    FUN_1415f9990(pEncoder);
    return 1;
}

// MS2-FUNCTIONAL 0x1415836e0: decodes through a temporary framed decoder.
// @0x1415836e0
unsigned int CNMChangeMetaDataFunc::DecodeFramed(CNMStream* pStream)
{
    unsigned char storage[0x38];
    FUN_14156be10(storage, pStream, this);
    unsigned int result = 0;
    if (FUN_1415fb750(storage)) {
        void** vtable = *reinterpret_cast<void***>(this);
        using Method = unsigned int(__fastcall*)(CNMChangeMetaDataFunc*, CNMSerializableDecoder*, CNMStream*);
        result = reinterpret_cast<Method>(vtable[5])(this, reinterpret_cast<CNMSerializableDecoder*>(storage), pStream);
    }
    FUN_14156bf10(storage);
    return result;
}

// MS2-FUNCTIONAL 0x141583770: selects framed decoding for wire format 2.
// @0x141583770
unsigned int CNMChangeMetaDataFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    void** vtable = *reinterpret_cast<void***>(this);
    if (FUN_1415fb6d0(pDecoder) == 2) {
        using Framed = unsigned int(__fastcall*)(CNMChangeMetaDataFunc*, CNMStream*);
        return reinterpret_cast<Framed>(vtable[6])(this, pStream);
    }
    using Method = unsigned int(__fastcall*)(CNMChangeMetaDataFunc*, CNMSerializableDecoder*, CNMStream*);
    return reinterpret_cast<Method>(vtable[5])(this, pDecoder, pStream);
}

// MS2-FUNCTIONAL 0x1415837d0: restores key and metadata from the reply decoder.
// @0x1415837d0
unsigned int CNMChangeMetaDataFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    if (FUN_1415fb700(this)) {
        void** vtable = *reinterpret_cast<void***>(pDecoder);
        using U32 = unsigned int(__fastcall*)(void*);
        using Bytes = unsigned int(__fastcall*)(void*, void*, unsigned int);
        m_30.nLow = reinterpret_cast<U32>(vtable[3])(pDecoder);
        m_30.nHigh = reinterpret_cast<U32>(vtable[3])(pDecoder);
        reinterpret_cast<Bytes>(vtable[9])(pDecoder, m_38, 0x3e8);
    }
    return static_cast<unsigned int>(FUN_1415fb750(pDecoder));
}

// MS2-PIN: ??0CNMChangeMetaDataFunc@@QEAA@XZ 0x141583480
