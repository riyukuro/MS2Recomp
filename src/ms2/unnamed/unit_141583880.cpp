// Nexon Messenger request-news request serialization.
// MS2-UNIT: unit_141583880
// MS2-RANGE: 0x141583880-0x141583b20 .text$mn
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
extern int FUN_1415fb700(void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(CNMSerializableDecoder*);

// MS2-FUNCTIONAL 0x141583880: initializes request-news opcode and direction.
// @0x141583880
CNMRequestNewsFunc::CNMRequestNewsFunc() : CNMFunc(0x200c, 1, 0, 0) {}

// MS2-FUNCTIONAL 0x1415838d0: frames the request and dispatches its encoder slot.
// @0x1415838d0
unsigned int CNMRequestNewsFunc::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMRequestNewsFunc::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}

// MS2-FUNCTIONAL 0x141583930: selects raw or framed encoding by the format flag.
// @0x141583930
unsigned int CNMRequestNewsFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMRequestNewsFunc::Encode(pEncoder, pStream);
    return CNMRequestNewsFunc::EncodeFramed(pStream);
}

// MS2-FUNCTIONAL 0x141583990: emits the empty news request payload.
// @0x141583990
unsigned int CNMRequestNewsFunc::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMFunc::EncodeDispatch(pEncoder, pStream);
    FUN_1415fb700(this);
    FUN_1415f9990(pEncoder);
    return 1;
}

// MS2-FUNCTIONAL 0x1415839e0: decodes through a temporary framed decoder.
// @0x1415839e0
unsigned int CNMRequestNewsFunc::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMRequestNewsFunc::Decode(&decoder, pStream);
}

// MS2-FUNCTIONAL 0x141583a70: selects framed decoding for wire format 2.
// @0x141583a70
unsigned int CNMRequestNewsFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMRequestNewsFunc::DecodeFramed(pStream);
    return CNMRequestNewsFunc::Decode(pDecoder, pStream);
}

// MS2-FUNCTIONAL 0x141583ad0: validates the empty reply payload.
// @0x141583ad0
unsigned int CNMRequestNewsFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    FUN_1415fb700(this);
    return static_cast<unsigned int>(FUN_1415fb750(pDecoder));
}

// MS2-PIN: ??0CNMRequestNewsFunc@@QEAA@XZ 0x141583880
