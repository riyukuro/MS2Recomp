// Nexon Messenger report information serializer methods.
// MS2-UNIT: unit_1415722e0
// MS2-RANGE: 0x1415722e0-0x1415727c0 .text$mn
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
extern void FUN_14156ae30(void*, const void*);
extern void FUN_1415f9990(void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(CNMSerializableDecoder*);

// MS2-FUNCTIONAL 0x1415723c0: uses opaque stack storage for the temporary encoder; report encoding behavior is preserved.
// @0x1415723c0
unsigned int CNMReportInfo::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMReportInfo::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}

// MS2-FUNCTIONAL 0x141572420: dispatches through the class vtable; the indirect call shape differs from the recovered image.
// @0x141572420
unsigned int CNMReportInfo::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMReportInfo::Encode(pEncoder, pStream);
    return CNMReportInfo::EncodeFramed(pStream);
}

// @0x141572480
unsigned int CNMReportInfo::Encode(CNMEncoder* pEncoder, CNMStream*)
{
    FUN_14156ab00(pEncoder, m_10);
    FUN_14156ab00(pEncoder, m_14);
    FUN_14156ac20(pEncoder, m_18);
    FUN_14156ac20(pEncoder, m_1c);
    FUN_14156ae30(pEncoder, m_20);
    FUN_14156ae30(pEncoder, m_60);
    FUN_14156ae30(pEncoder, m_1000);
    FUN_14156ac20(pEncoder, m_5e20);
    FUN_14156ae30(pEncoder, m_5e24);
    FUN_1415f9990(pEncoder);
    return 1;
}

// MS2-FUNCTIONAL 0x141572570: uses opaque stack storage for the temporary decoder; decode behavior is preserved.
// @0x141572570
unsigned int CNMReportInfo::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMReportInfo::Decode(&decoder, pStream);
}

// MS2-FUNCTIONAL 0x141572600: dispatches through the class vtable; the indirect call shape differs from the recovered image.
// @0x141572600
unsigned int CNMReportInfo::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMReportInfo::DecodeFramed(pStream);
    return CNMReportInfo::Decode(pDecoder, pStream);
}

// @0x141572660
unsigned int CNMReportInfo::Decode(CNMSerializableDecoder* pDecoder, CNMStream*)
{
    m_10 = pDecoder->ReadU8();
    m_14 = pDecoder->ReadU8();
    m_18 = pDecoder->ReadU32();
    m_1c = pDecoder->ReadU32();
    pDecoder->ReadStringBufAlias(m_20, 0x40);
    pDecoder->ReadStringBufAlias(m_60, 4000);
    pDecoder->ReadStringBufAlias(m_1000, 20000);
    m_5e20 = pDecoder->ReadU32();
    pDecoder->ReadStringBufAlias(m_5e24, 0x40);
    return static_cast<unsigned int>(FUN_1415fb750(pDecoder));
}

// MS2-FUNCTIONAL 0x1415722e0: initializes the report signature and zeroes its fixed-size payload fields.
// @0x1415722e0
CNMReportInfo::CNMReportInfo() : CNMSerializable(0x7269,1,1),m_10(0),m_14(0),m_18(0),m_1c(0),m_20{},m_60{},m_1000{},m_5e20(0),m_5e24{} {}

// MS2-PIN: ??0CNMReportInfo@@QEAA@XZ 0x1415722e0 ; recovered report info constructor
