// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CNMOpenGameSummaryFunc request and serializer slots.
// MS2-UNIT: unit_141595a70
// MS2-RANGE: 0x141595a70-0x141595d10 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmobjects.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/placeholder/nmencoder.h"
#include "ms2/ms2recover.h"

extern int FUN_1415fb700(const void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(CNMSerializableDecoder*);
extern void FUN_1415f9990(void*);
extern void* FUN_14156bcb0(void*, void*, void*);
extern void FUN_14156bd50(void*);

// @0x141595a70
CNMOpenGameSummaryFunc::CNMOpenGameSummaryFunc() : CNMFunc(0x8021, 1, 0, 0)
{
}

// MS2-FUNCTIONAL: framed encoder setup and cleanup are recovered; local storage changes the frame layout.
// @0x141595ac0
unsigned int CNMOpenGameSummaryFunc::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMOpenGameSummaryFunc::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}

// MS2-FUNCTIONAL: same format branch and serializer slots; direct calls replace the original indirect dispatch.
// @0x141595b20
unsigned int CNMOpenGameSummaryFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMOpenGameSummaryFunc::Encode(pEncoder, pStream);
    return CNMOpenGameSummaryFunc::EncodeFramed(pStream);
}

// MS2-FUNCTIONAL: base fields and final encoder marker match; direct helper calls differ in callee sequence.
// @0x141595b80
unsigned int CNMOpenGameSummaryFunc::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMFunc::EncodeDispatch(pEncoder, pStream);
    (void)FUN_1415fb700(this);
    FUN_1415f9990(pEncoder);
    return 1;
}

// MS2-FUNCTIONAL: decoder preflight, base decoding and cleanup are recovered; temporary storage changes the frame.
// @0x141595bd0
unsigned int CNMOpenGameSummaryFunc::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMOpenGameSummaryFunc::Decode(&decoder, pStream);
}

// MS2-FUNCTIONAL: the format check chooses the same direct or framed decode path.
// @0x141595c60
unsigned int CNMOpenGameSummaryFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMOpenGameSummaryFunc::DecodeFramed(pStream);
    return CNMOpenGameSummaryFunc::Decode(pDecoder, pStream);
}

// MS2-FUNCTIONAL: base decode, status read and helper side effects are recovered; the original method returns void.
// @0x141595cc0
unsigned int CNMOpenGameSummaryFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    (void)FUN_1415fb700(this);
    (void)FUN_1415fb750(pDecoder);
    return FUN_1415fb750(pDecoder);
}

// MS2-PIN: ??0CNMOpenGameSummaryFunc@@QEAA@XZ 0x141595a70
