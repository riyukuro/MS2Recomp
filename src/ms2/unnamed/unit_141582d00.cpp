// Nexon Messenger set-count request serialization.
// MS2-UNIT: unit_141582d00
// MS2-RANGE: 0x141582d00-0x141583080 .text$mn
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
extern void FUN_1415f9990(void*);
extern int FUN_1415fb700(void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(void*);

// MS2-FUNCTIONAL 0x141582d00: initializes both count fields to zero.
// @0x141582d00
CNMSetCountFunc::CNMSetCountFunc() : CNMFunc(0x2009, 1, 0, 0), m_30(0), m_34(0) {}

// MS2-FUNCTIONAL 0x141582d60: stores the two supplied count fields.
// @0x141582d60
CNMSetCountFunc::CNMSetCountFunc(unsigned first, unsigned second)
    : CNMFunc(0x2009, 1, 0, 0), m_30(static_cast<int>(second)), m_34(static_cast<int>(first))
{
}

// MS2-FUNCTIONAL 0x141582dd0: frames the request and dispatches its encoder slot.
// @0x141582dd0
unsigned int CNMSetCountFunc::EncodeFramed(CNMStream* pStream)
{
    unsigned char storage[0x18];
    FUN_14156bcb0(storage, pStream, this);
    void** vtable = *reinterpret_cast<void***>(this);
    using Method = unsigned int(__fastcall*)(CNMSetCountFunc*, CNMEncoder*, CNMStream*);
    const unsigned int encoded = reinterpret_cast<Method>(vtable[2])(this, reinterpret_cast<CNMEncoder*>(storage), pStream);
    FUN_14156bd50(storage);
    return encoded;
}

// MS2-FUNCTIONAL 0x141582e30: selects raw or framed encoding from the format flag.
// @0x141582e30
unsigned int CNMSetCountFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    void** vtable = *reinterpret_cast<void***>(this);
    if (m_bFormat == 1) {
        using Method = unsigned int(__fastcall*)(CNMSetCountFunc*, CNMEncoder*, CNMStream*);
        return reinterpret_cast<Method>(vtable[2])(this, pEncoder, pStream);
    }
    using Framed = unsigned int(__fastcall*)(CNMSetCountFunc*, CNMStream*);
    return reinterpret_cast<Framed>(vtable[3])(this, pStream);
}

// MS2-FUNCTIONAL 0x141582e90: serializes the ordered pair of count fields.
// @0x141582e90
unsigned int CNMSetCountFunc::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMFunc::EncodeDispatch(pEncoder, pStream);
    if (FUN_1415fb700(this)) {
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_34));
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_30));
    }
    FUN_1415f9990(pEncoder);
    return 1;
}

// MS2-FUNCTIONAL 0x141582f10: decodes through a temporary framed decoder and the virtual decode slot.
// @0x141582f10
unsigned int CNMSetCountFunc::DecodeFramed(CNMStream* pStream)
{
    unsigned char storage[0x38];
    FUN_14156be10(storage, pStream, this);
    unsigned int result = 0;
    if (FUN_1415fb750(storage)) {
        void** vtable = *reinterpret_cast<void***>(this);
        using Method = unsigned int(__fastcall*)(CNMSetCountFunc*, CNMSerializableDecoder*, CNMStream*);
        result = reinterpret_cast<Method>(vtable[5])(this, reinterpret_cast<CNMSerializableDecoder*>(storage), pStream);
    }
    FUN_14156bf10(storage);
    return result;
}

// MS2-FUNCTIONAL 0x141582fa0: chooses framed decoding for wire format 2.
// @0x141582fa0
unsigned int CNMSetCountFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    void** vtable = *reinterpret_cast<void***>(this);
    if (FUN_1415fb6d0(pDecoder) == 2) {
        using Framed = unsigned int(__fastcall*)(CNMSetCountFunc*, CNMStream*);
        return reinterpret_cast<Framed>(vtable[6])(this, pStream);
    }
    using Method = unsigned int(__fastcall*)(CNMSetCountFunc*, CNMSerializableDecoder*, CNMStream*);
    return reinterpret_cast<Method>(vtable[5])(this, pDecoder, pStream);
}

// MS2-FUNCTIONAL 0x141583000: restores the pair of count fields from the reply.
// @0x141583000
unsigned int CNMSetCountFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    if (FUN_1415fb700(this)) {
        void** vtable = *reinterpret_cast<void***>(pDecoder);
        using U32 = unsigned int(__fastcall*)(void*);
        m_34 = static_cast<int>(reinterpret_cast<U32>(vtable[3])(pDecoder));
        m_30 = static_cast<int>(reinterpret_cast<U32>(vtable[3])(pDecoder));
    }
    return static_cast<unsigned int>(FUN_1415fb750(pDecoder));
}

// MS2-PIN: ??0CNMSetCountFunc@@QEAA@XZ 0x141582d00
