// Nexon Messenger session request data serializer methods.
// MS2-UNIT: unit_1415794f0
// MS2-RANGE: 0x1415794f0-0x141579850 .text$mn
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
extern void FUN_14156ac20(void*, unsigned int);
extern void FUN_14156ae30(void*, const void*);
extern void FUN_1415f9990(void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(CNMSerializableDecoder*);

// MS2-FUNCTIONAL 0x1415794f0: initializes session request metadata and its two fixed-size strings.
// @0x1415794f0
CNMRequestSessionData::CNMRequestSessionData() : CNMSerializable(0x7273,1,1),m_10(0),m_14(0),m_18{},m_58{} {}

// MS2-FUNCTIONAL 0x141579570: uses opaque stack storage for the temporary encoder; session request encoding behavior is preserved.
// @0x141579570
unsigned int CNMRequestSessionData::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMRequestSessionData::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}

// MS2-FUNCTIONAL 0x1415795d0: dispatches through the class vtable; the indirect call shape differs from the recovered image.
// @0x1415795d0
unsigned int CNMRequestSessionData::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMRequestSessionData::Encode(pEncoder, pStream);
    return CNMRequestSessionData::EncodeFramed(pStream);
}

// @0x141579630
unsigned int CNMRequestSessionData::Encode(CNMEncoder* pEncoder, CNMStream*)
{
    FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_10));
    FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_14));
    FUN_14156ae30(pEncoder, m_18);
    FUN_14156ae30(pEncoder, m_58);
    FUN_1415f9990(pEncoder);
    return 1;
}

// MS2-FUNCTIONAL 0x1415796b0: uses opaque stack storage for the temporary decoder; session request decode behavior is preserved.
// @0x1415796b0
unsigned int CNMRequestSessionData::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMRequestSessionData::Decode(&decoder, pStream);
}

// MS2-FUNCTIONAL 0x141579740: dispatches through the class vtable; the indirect call shape differs from the recovered image.
// @0x141579740
unsigned int CNMRequestSessionData::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMRequestSessionData::DecodeFramed(pStream);
    return CNMRequestSessionData::Decode(pDecoder, pStream);
}

// @0x1415797a0
unsigned int CNMRequestSessionData::Decode(CNMSerializableDecoder* pDecoder, CNMStream*)
{
    void** vtable = *reinterpret_cast<void***>(pDecoder);
    using ReadU32 = unsigned int(__fastcall*)(void*);
    using ReadBytes = unsigned int(__fastcall*)(void*, void*, unsigned int);
    m_10 = static_cast<int>(reinterpret_cast<ReadU32>(vtable[3])(pDecoder));
    m_14 = static_cast<int>(reinterpret_cast<ReadU32>(vtable[3])(pDecoder));
    reinterpret_cast<ReadBytes>(vtable[9])(pDecoder, m_18, 0x40);
    reinterpret_cast<ReadBytes>(vtable[9])(pDecoder, m_58, 0x40);
    return static_cast<unsigned int>(FUN_1415fb750(pDecoder));
}

// MS2-PIN: ??0CNMRequestSessionData@@QEAA@XZ 0x1415794f0 ; recovered session request data constructor
