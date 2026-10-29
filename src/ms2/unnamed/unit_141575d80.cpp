// Nexon Messenger session record serializer methods.
// MS2-UNIT: unit_141575d80
// MS2-RANGE: 0x141575d80-0x141576260 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmobjects.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/placeholder/nmencoder.h"
#include "ms2/ms2recover.h"

extern void FUN_14156bcb0(void*, void*, void*);
extern void FUN_14156bd50(void*);
extern void FUN_14156be10(void*, void*, void*);
extern void FUN_14156bf10(void*);
extern void FUN_14156ab00(void*, unsigned char);
extern void FUN_14156ac20(void*, unsigned int);
extern void FUN_14156acb0(void*, unsigned long long);
extern void FUN_1415f9990(void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(CNMSerializableDecoder*);

// MS2-FUNCTIONAL 0x141575d80: initializes the session record fields after the serializable base.
// @0x141575d80
CNMSessionInfo::CNMSessionInfo() : CNMSerializable(0x7369,1,1),m_10(0),m_14{},m_1c(0),m_20(0),m_24(0),m_28(0),m_30(0),m_38(0),m_3c(0),m_40(0),m_44(0) {}

// MS2-FUNCTIONAL 0x141575e50: uses opaque stack storage for the temporary encoder; session record encoding behavior is preserved.
// @0x141575e50
unsigned int CNMSessionInfo::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMSessionInfo::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}

// MS2-FUNCTIONAL 0x141575eb0: dispatches through the class vtable; the indirect call shape differs from the recovered image.
// @0x141575eb0
unsigned int CNMSessionInfo::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMSessionInfo::Encode(pEncoder, pStream);
    return CNMSessionInfo::EncodeFramed(pStream);
}

// @0x141575f10
unsigned int CNMSessionInfo::Encode(CNMEncoder* pEncoder, CNMStream*)
{
    FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_10));
    FUN_14156ac20(pEncoder, m_14.nLow);
    FUN_14156ac20(pEncoder, m_14.nHigh);
    FUN_14156ab00(pEncoder, static_cast<unsigned int>(m_1c));
    FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_20));
    FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_24));
    FUN_14156acb0(pEncoder, static_cast<unsigned long long>(m_28));
    FUN_14156acb0(pEncoder, static_cast<unsigned long long>(m_30));
    FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_38));
    FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_3c));
    FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_40));
    FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_44));
    FUN_1415f9990(pEncoder);
    return 1;
}

// MS2-FUNCTIONAL 0x141576020: uses opaque stack storage for the temporary decoder; session record decode behavior is preserved.
// @0x141576020
unsigned int CNMSessionInfo::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMSessionInfo::Decode(&decoder, pStream);
}

// MS2-FUNCTIONAL 0x1415760b0: dispatches through the class vtable; the indirect call shape differs from the recovered image.
// @0x1415760b0
unsigned int CNMSessionInfo::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMSessionInfo::DecodeFramed(pStream);
    return CNMSessionInfo::Decode(pDecoder, pStream);
}

// @0x141576110
unsigned int CNMSessionInfo::Decode(CNMSerializableDecoder* pDecoder, CNMStream*)
{
    m_10 = pDecoder->ReadU32();
    m_14.nLow = pDecoder->ReadU32();
    m_14.nHigh = pDecoder->ReadU32();
    m_1c = pDecoder->ReadU8();
    m_20 = pDecoder->ReadU32();
    m_24 = pDecoder->ReadU32();
    m_28 = pDecoder->ReadU64();
    m_30 = pDecoder->ReadU64();
    m_38 = pDecoder->ReadU32();
    m_3c = pDecoder->ReadU32();
    m_40 = pDecoder->ReadU32();
    m_44 = pDecoder->ReadU32();
    return static_cast<unsigned int>(FUN_1415fb750(pDecoder));
}

// MS2-PIN: ??0CNMSessionInfo@@QEAA@XZ 0x141575d80 ; recovered session constructor
