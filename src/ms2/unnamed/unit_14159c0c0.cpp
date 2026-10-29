// Recovered from the Nexon Messenger client library: create-channel request.
// MS2-UNIT: unit_14159c0c0
// MS2-RANGE: 0x14159c0c0-0x14159c360 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
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
extern void FUN_14156bcb0(void*, void*, void*);
extern void FUN_14156bd50(void*);

// MS2-FUNCTIONAL: request ID and base initialization match; base constructor argument register width differs.
// @0x14159c0c0
CNMCreateChannelFunc::CNMCreateChannelFunc()
    : CNMFunc(0xa010, 1, 0, 0)
{
}

// MS2-FUNCTIONAL: encoder wrapper lifetime and framing flow match; local encoder storage differs.
// @0x14159c110
unsigned int CNMCreateChannelFunc::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMCreateChannelFunc::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}

// MS2-FUNCTIONAL: recovered format branch; direct calls replace virtual dispatch.
// @0x14159c170
unsigned int CNMCreateChannelFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMCreateChannelFunc::Encode(pEncoder, pStream);
    return CNMCreateChannelFunc::EncodeFramed(pStream);
}

// MS2-FUNCTIONAL: empty payload, direction check, and finish match; direct calls replace virtual dispatch.
// @0x14159c1d0
unsigned int CNMCreateChannelFunc::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMFunc::EncodeDispatch(pEncoder, pStream);
    FUN_1415fb700(this);
    FUN_1415f9990(pEncoder);
    return 1;
}

// MS2-FUNCTIONAL: decoder wrapper lifetime and validity branch match; local decoder storage differs.
// @0x14159c220
unsigned int CNMCreateChannelFunc::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMCreateChannelFunc::Decode(&decoder, pStream);
}

// MS2-FUNCTIONAL: recovered decoder format branch; direct calls replace virtual dispatch.
// @0x14159c2b0
unsigned int CNMCreateChannelFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMCreateChannelFunc::DecodeFramed(pStream);
    return CNMCreateChannelFunc::Decode(pDecoder, pStream);
}

// MS2-FUNCTIONAL: empty payload and validity return match; direct calls replace virtual dispatch.
// @0x14159c310
unsigned int CNMCreateChannelFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    FUN_1415fb700(this);
    return FUN_1415fb750(pDecoder);
}

// MS2-PIN: ??0CNMCreateChannelFunc@@QEAA@XZ 0x14159c0c0
