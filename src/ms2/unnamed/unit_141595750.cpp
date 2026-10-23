// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CNMGetGameListFunc construction and serializer slots.
// The payload is a CNMGameListData object containing the vector of game records.
// MS2-UNIT: unit_141595750
// MS2-RANGE: 0x141595750-0x141595a70 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmobjects.h"
#include "ms2/ms2recover.h"

extern int FUN_1415fb720(const void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(void*);
extern void FUN_1415f9990(void*);
extern void* FUN_14156bcb0(void*, void*, void*);
extern void FUN_14156bd50(void*);

// @0x141595750
CNMGetGameListFunc::CNMGetGameListFunc() : CNMFunc(0x8008, 1, 0, 0), m_30()
{
}

// MS2-FUNCTIONAL: encoder frame helper and payload call are recovered; frame allocation differs from the executable.
// @0x1415957c0
unsigned int CNMGetGameListFunc::EncodeFramed(CNMStream* pStream)
{
    alignas(8) unsigned char encoder[0x18];
    FUN_14156bcb0(encoder, pStream, this);
    const auto result = Encode(reinterpret_cast<CNMEncoder*>(encoder), pStream);
    FUN_14156bd50(encoder);
    return result;
}

// MS2-FUNCTIONAL: format condition and selected encoder slot match; direct calls replace indirect dispatch.
// @0x141595820
unsigned int CNMGetGameListFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    return m_bFormat == 1 ? Encode(pEncoder, pStream) : EncodeFramed(pStream);
}

// MS2-FUNCTIONAL: payload presence check and record encoding are recovered; compiler devirtualizes the data call.
// @0x141595880
unsigned int CNMGetGameListFunc::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMFunc::EncodeDispatch(pEncoder, pStream);
    if (FUN_1415fb720(this))
        m_30.Encode(pEncoder, pStream);
    FUN_1415f9990(pEncoder);
    return 1;
}

// MS2-FUNCTIONAL: decoder framing check and payload decode are recovered; temporary decoder storage differs in frame.
// @0x141595900
unsigned int CNMGetGameListFunc::DecodeFramed(CNMStream* pStream)
{
    alignas(8) unsigned char decoder[0x38];
    FUN_14156bcb0(decoder, pStream, this);
    const auto result = Decode(reinterpret_cast<CNMSerializableDecoder*>(decoder), pStream);
    FUN_14156bd50(decoder);
    return result;
}

// MS2-FUNCTIONAL: the format discriminator chooses the same decoder path; direct calls replace indirect dispatch.
// @0x141595990
unsigned int CNMGetGameListFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    return FUN_1415fb6d0(pDecoder) == 2 ? DecodeFramed(pStream) : Decode(pDecoder, pStream);
}

// MS2-FUNCTIONAL: base decode, payload guard, and final status read are recovered; payload call is devirtualized.
// @0x1415959f0
unsigned int CNMGetGameListFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    if (FUN_1415fb720(this))
        m_30.Decode(pDecoder, pStream);
    return FUN_1415fb750(pDecoder);
}

// MS2-PIN: ??0CNMGetGameListFunc@@QEAA@XZ 0x141595750
