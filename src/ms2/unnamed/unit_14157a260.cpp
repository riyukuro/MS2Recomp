// Nexon Messenger custom notification payload serializer methods.
// MS2-UNIT: unit_14157a260
// MS2-RANGE: 0x14157a260-0x14157a830 .text$mn
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
extern void FUN_14156acb0(void*, unsigned long long);
extern void FUN_14156ab00(void*, unsigned char);
extern void FUN_14156ae30(void*, const void*);
extern void FUN_1415f9990(void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(CNMSerializableDecoder*);

// MS2-FUNCTIONAL 0x14157a260: initializes the fixed fields and byte arrays of custom notification data.
// @0x14157a260
CNMCustomNotifyData::CNMCustomNotifyData() : CNMSerializable(0x636e,1,1),m_10(0),m_18(0),m_20(0),m_24(0),m_28(0),m_30(0),m_34(0),m_38{},m_78{},m_b8{}
{
    memset(&m_1b8, 0, 0x10);
    m_1c8 = 0;
}

// MS2-FUNCTIONAL 0x14157a360: uses opaque storage for the temporary encoder; payload behavior is preserved.
// @0x14157a360
unsigned int CNMCustomNotifyData::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMCustomNotifyData::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}

// MS2-FUNCTIONAL 0x14157a3c0: dispatches through the recovered virtual slots.
// @0x14157a3c0
unsigned int CNMCustomNotifyData::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMCustomNotifyData::Encode(pEncoder, pStream);
    return CNMCustomNotifyData::EncodeFramed(pStream);
}

// @0x14157a420
unsigned int CNMCustomNotifyData::Encode(CNMEncoder* pEncoder, CNMStream*)
{
    FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_10));
    FUN_14156acb0(pEncoder, static_cast<unsigned long long>(m_18));
    FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_20));
    FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_24));
    FUN_14156acb0(pEncoder, static_cast<unsigned long long>(m_28));
    FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_30));
    FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_34));
    FUN_14156ae30(pEncoder, m_38);
    FUN_14156ae30(pEncoder, m_78);
    FUN_14156ae30(pEncoder, m_b8);
    FUN_14156ac20(pEncoder, m_1b8);
    FUN_14156ab00(pEncoder, static_cast<unsigned char>(m_1ba));
    FUN_14156ab00(pEncoder, static_cast<unsigned char>(m_1be));
    FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_1c8));
    FUN_1415f9990(pEncoder);
    return 1;
}

// MS2-FUNCTIONAL 0x14157a570: uses opaque storage for the temporary decoder; payload behavior is preserved.
// @0x14157a570
unsigned int CNMCustomNotifyData::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMCustomNotifyData::Decode(&decoder, pStream);
}

// MS2-FUNCTIONAL 0x14157a600: dispatches through the recovered virtual slots.
// @0x14157a600
unsigned int CNMCustomNotifyData::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMCustomNotifyData::DecodeFramed(pStream);
    return CNMCustomNotifyData::Decode(pDecoder, pStream);
}

// @0x14157a660
unsigned int CNMCustomNotifyData::Decode(CNMSerializableDecoder* pDecoder, CNMStream*)
{
    m_10 = pDecoder->ReadU32();
    m_18 = pDecoder->ReadU64();
    m_20 = pDecoder->ReadU32();
    m_24 = pDecoder->ReadU32();
    m_28 = pDecoder->ReadU64();
    m_30 = pDecoder->ReadU32();
    m_34 = pDecoder->ReadU32();
    pDecoder->ReadStringBufAlias(m_38, 0x40);
    pDecoder->ReadStringBufAlias(m_78, 0x40);
    pDecoder->ReadStringBufAlias(m_b8, 0x100);
    m_1b8 = pDecoder->ReadU32();
    m_1ba = pDecoder->ReadU8();
    m_1be = pDecoder->ReadU8();
    m_1c8 = pDecoder->ReadU32();
    return static_cast<unsigned int>(FUN_1415fb750(pDecoder));
}

// MS2-PIN: ??0CNMCustomNotifyData@@QEAA@XZ 0x14157a260 ; recovered custom notification data constructor
