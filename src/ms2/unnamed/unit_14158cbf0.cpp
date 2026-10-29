// Nexon Messenger get-my-guild-list-ex request serialization.
// MS2-UNIT: unit_14158cbf0
// MS2-RANGE: 0x14158cbf0-0x14158cf10 .text$mn
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
extern void FUN_1415f9990(void*);
extern int FUN_1415fb720(void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(CNMSerializableDecoder*);

// MS2-FUNCTIONAL 0x14158cbf0: initializes the extended guild-list result record.
// @0x14158cbf0
CNMGetMyGuildListExFunc::CNMGetMyGuildListExFunc()
    : CNMFunc(0x7003, 1, 0, 0), m_30() {}

// MS2-FUNCTIONAL 0x14158cc60: frames the get-my-guild-list-ex response.
// @0x14158cc60
unsigned int CNMGetMyGuildListExFunc::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMGetMyGuildListExFunc::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}

// MS2-FUNCTIONAL 0x14158ccc0: selects the encoder by wire format.
// @0x14158ccc0
unsigned int CNMGetMyGuildListExFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMGetMyGuildListExFunc::Encode(pEncoder, pStream);
    return CNMGetMyGuildListExFunc::EncodeFramed(pStream);
}

// MS2-FUNCTIONAL 0x14158cd20: encodes the guild-list result record in replies.
// @0x14158cd20
unsigned int CNMGetMyGuildListExFunc::Encode(CNMEncoder* encoder, CNMStream* stream)
{
    CNMFunc::EncodeDispatch(encoder, stream);
    if (FUN_1415fb720(this)) m_30.Encode(encoder, stream);
    FUN_1415f9990(encoder);
    return 1;
}

// MS2-FUNCTIONAL 0x14158cda0: decodes a framed guild-list response.
// @0x14158cda0
unsigned int CNMGetMyGuildListExFunc::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMGetMyGuildListExFunc::Decode(&decoder, pStream);
}

// MS2-FUNCTIONAL 0x14158ce30: selects the decoder by wire format.
// @0x14158ce30
unsigned int CNMGetMyGuildListExFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMGetMyGuildListExFunc::DecodeFramed(pStream);
    return CNMGetMyGuildListExFunc::Decode(pDecoder, pStream);
}

// MS2-FUNCTIONAL 0x14158ce90: decodes the guild-list result record in replies.
// @0x14158ce90
unsigned int CNMGetMyGuildListExFunc::Decode(CNMSerializableDecoder* decoder, CNMStream* stream)
{
    CNMFunc::DecodeDispatch(decoder, stream);
    if (FUN_1415fb720(this)) m_30.Decode(decoder, stream);
    return static_cast<unsigned int>(FUN_1415fb750(decoder));
}

// MS2-PIN: ??0CNMGetMyGuildListExFunc@@QEAA@XZ 0x14158cbf0
