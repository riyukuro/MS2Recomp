// Recovered from the Nexon Messenger client library: file transfer event record.
// MS2-UNIT: ?\nmfileevent.cpp
// MS2-RANGE: 0x141572e00-0x1415731e0 .text$mn
// MS2-PIN: ??0CNMSerializableEncoder@@QEAA@PEAVCNMStream@@PEAVCNMSerializable@@@Z 0x14156bcb0
// MS2-PIN: ??1CNMSerializableEncoder@@QEAA@XZ 0x14156bd50
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmfunc.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/placeholder/nmencoder.h"
#include "ms2/ms2recover.h"

extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(CNMSerializableDecoder*);
extern void FUN_1415f9990(void*);
extern void FUN_14156ac20(void*, unsigned int);
extern void FUN_14156ab00(void*, unsigned char);
extern void FUN_14156ae30(void*, const void*);

// @0x141572e00
CNMFileEvent::CNMFileEvent()
    : CNMSerializable(0x6665, 1, 1), m_10(0), m_14{}, m_114(0), m_118(0), m_11c(0), m_120(0)
{
}

// @0x141572ea0
unsigned int CNMFileEvent::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMFileEvent::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}

// @0x141572f00
unsigned int CNMFileEvent::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMFileEvent::Encode(pEncoder, pStream);
    return CNMFileEvent::EncodeFramed(pStream);
}

// @0x141572f60
unsigned int CNMFileEvent::Encode(CNMEncoder* pEncoder, CNMStream*)
{
    FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_10));
    FUN_14156ae30(pEncoder, m_14);
    FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_114));
    FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_118));
    FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_11c));
    FUN_14156ab00(pEncoder, static_cast<unsigned char>(m_120));
    FUN_1415f9990(pEncoder);
    return 1;
}

// @0x141573010
unsigned int CNMFileEvent::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMFileEvent::Decode(&decoder, pStream);
}

// @0x1415730a0
unsigned int CNMFileEvent::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMFileEvent::DecodeFramed(pStream);
    return CNMFileEvent::Decode(pDecoder, pStream);
}

// @0x141573100
unsigned int CNMFileEvent::Decode(CNMSerializableDecoder* pDecoder, CNMStream*)
{
    m_10 = static_cast<int>(pDecoder->ReadU32());
    pDecoder->ReadStringBufAlias(reinterpret_cast<char*>(m_14), sizeof m_14);
    m_114 = static_cast<int>(pDecoder->ReadU32());
    m_118 = static_cast<int>(pDecoder->ReadU32());
    m_11c = static_cast<int>(pDecoder->ReadU32());
    m_120 = pDecoder->ReadU8();
    return FUN_1415fb750(pDecoder);
}

// MS2-PIN: ??0CNMFileEvent@@QEAA@XZ 0x141572e00
