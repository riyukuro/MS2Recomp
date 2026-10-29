// Recovered from the Nexon Messenger client library: file path record.
// MS2-UNIT: ?\nmfilepath.cpp
// MS2-RANGE: 0x1415731e0-0x1415734a0 .text$mn
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
extern void FUN_14156ae30(void*, const void*);

// @0x1415731e0
CNMFilePath::CNMFilePath()
    : CNMSerializable(0x6670, 1, 1), m_10{}
{
}

// @0x141573240
unsigned int CNMFilePath::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMFilePath::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}

// @0x1415732a0
unsigned int CNMFilePath::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMFilePath::Encode(pEncoder, pStream);
    return CNMFilePath::EncodeFramed(pStream);
}

// @0x141573300
unsigned int CNMFilePath::Encode(CNMEncoder* pEncoder, CNMStream*)
{
    FUN_14156ae30(pEncoder, m_10);
    FUN_1415f9990(pEncoder);
    return 1;
}

// @0x141573350
unsigned int CNMFilePath::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMFilePath::Decode(&decoder, pStream);
}

// @0x1415733e0
unsigned int CNMFilePath::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMFilePath::DecodeFramed(pStream);
    return CNMFilePath::Decode(pDecoder, pStream);
}

// @0x141573440
unsigned int CNMFilePath::Decode(CNMSerializableDecoder* pDecoder, CNMStream*)
{
    pDecoder->ReadStringBufAlias(reinterpret_cast<char*>(m_10), sizeof m_10);
    return FUN_1415fb750(pDecoder);
}

// MS2-PIN: ??0CNMFilePath@@QEAA@XZ 0x1415731e0
