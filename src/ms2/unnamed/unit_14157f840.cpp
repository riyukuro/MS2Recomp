// Nexon Messenger virtual-user logout request serialization.
// MS2-UNIT: unit_14157f840
// MS2-RANGE: 0x14157f840-0x14157fbb0 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/placeholder/nmobjects.h"
#include "ms2/placeholder/nmfunc.h"
#include "ms2/placeholder/nmencoder.h"
#include "ms2/ms2recover.h"

extern void FUN_14156bcb0(void*, void*, void*);
extern void FUN_14156bd50(void*);
extern void FUN_14156be10(void*, void*, void*);
extern void FUN_14156bf10(void*);
extern void FUN_14156ac20(void*, unsigned int);
extern void FUN_1415f9990(void*);
extern int FUN_1415fb700(void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(CNMSerializableDecoder*);

// MS2-FUNCTIONAL 0x14157f840: initializes the logout request ID and zero fields.
// @0x14157f840
CNMLogoutVirtualFunc::CNMLogoutVirtualFunc() : CNMFunc(0x1104, 1, 0, 0), m_30(0), m_34(0) {}

// MS2-FUNCTIONAL 0x14157f8a0: stores the supplied logout value.
// @0x14157f8a0
CNMLogoutVirtualFunc::CNMLogoutVirtualFunc(long long value)
    : CNMFunc(0x1104, 1, 0, 0), m_30(static_cast<int>(value)), m_34(static_cast<int>(value >> 32)) {}

// MS2-FUNCTIONAL 0x14157f900: frames the request and dispatches its encoder slot.
// @0x14157f900
unsigned int CNMLogoutVirtualFunc::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMLogoutVirtualFunc::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}

// MS2-FUNCTIONAL 0x14157f960: selects raw or framed encoding from the format flag.
// @0x14157f960
unsigned int CNMLogoutVirtualFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMLogoutVirtualFunc::Encode(pEncoder, pStream);
    return CNMLogoutVirtualFunc::EncodeFramed(pStream);
}

// MS2-FUNCTIONAL 0x14157f9c0: writes both 32-bit logout fields.
// @0x14157f9c0
unsigned int CNMLogoutVirtualFunc::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMFunc::EncodeDispatch(pEncoder, pStream);
    if (FUN_1415fb700(this)) {
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_30));
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_34));
    }
    FUN_1415f9990(pEncoder);
    return 1;
}

// MS2-FUNCTIONAL 0x14157fa40: decodes through a temporary framed decoder.
// @0x14157fa40
unsigned int CNMLogoutVirtualFunc::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMLogoutVirtualFunc::Decode(&decoder, pStream);
}

// MS2-FUNCTIONAL 0x14157fad0: chooses framed decoding for wire format 2.
// @0x14157fad0
unsigned int CNMLogoutVirtualFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMLogoutVirtualFunc::DecodeFramed(pStream);
    return CNMLogoutVirtualFunc::Decode(pDecoder, pStream);
}

// MS2-FUNCTIONAL 0x14157fb30: restores the two logout fields.
// @0x14157fb30
unsigned int CNMLogoutVirtualFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    if (FUN_1415fb700(this)) {
        void** vtable = *reinterpret_cast<void***>(pDecoder);
        using U32 = unsigned int(__fastcall*)(void*);
        m_30 = static_cast<int>(reinterpret_cast<U32>(vtable[3])(pDecoder));
        m_34 = static_cast<int>(reinterpret_cast<U32>(vtable[3])(pDecoder));
    }
    return static_cast<unsigned int>(FUN_1415fb750(pDecoder));
}

// MS2-PIN: ??0CNMLogoutVirtualFunc@@QEAA@XZ 0x14157f840
