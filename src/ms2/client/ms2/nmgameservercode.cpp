// Recovered Nexon Messenger game server code record.
// MS2-UNIT: ?\nmgameservercode.cpp
// MS2-RANGE: 0x14157aaf0-0x14157adc0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmfunc.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/ms2recover.h"

extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(void*);
extern void FUN_1415f9990(void*);
extern void FUN_14156ac20(void*, unsigned int);
extern void FUN_14156bcb0(void*, void*, void*);
extern void FUN_14156be10(void*, void*, void*);
extern void FUN_14156bd50(void*);

// MS2-FUNCTIONAL: initializes a zero-valued game server code record.
// @0x14157aaf0
CNMGameServerCode::CNMGameServerCode()
    : CNMSerializable(0x6773, 1, 1), m_nServerCode(0)
{
}

// MS2-FUNCTIONAL: initializes a game server code record with its code.
// @0x14157ab40
CNMGameServerCode::CNMGameServerCode(int serverCode)
    : CNMSerializable(0x6773, 1, 1), m_nServerCode(serverCode)
{
}

// MS2-FUNCTIONAL: frames the record through the recovered temporary encoder.
// @0x14157ab90
unsigned int CNMGameServerCode::EncodeFramed(CNMStream* pStream)
{
    alignas(8) unsigned char encoder[0x18];
    FUN_14156bcb0(encoder, pStream, this);
    const unsigned int result = Encode(reinterpret_cast<CNMEncoder*>(encoder), pStream);
    FUN_14156bd50(encoder);
    return result;
}

// MS2-FUNCTIONAL: dispatches encoding according to the serialized format byte.
// @0x14157abf0
unsigned int CNMGameServerCode::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        Encode(pEncoder, pStream);
    else
        EncodeFramed(pStream);
    return 0;
}

// MS2-FUNCTIONAL: writes the server code and finishes the encoder record.
// @0x14157ac50
unsigned int CNMGameServerCode::Encode(CNMEncoder* pEncoder, CNMStream*)
{
    FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_nServerCode));
    FUN_1415f9990(pEncoder);
    return 1;
}

// MS2-FUNCTIONAL: frames decoding and validates the temporary decoder.
// @0x14157ac90
unsigned int CNMGameServerCode::DecodeFramed(CNMStream* pStream)
{
    alignas(8) unsigned char decoder[0x38];
    FUN_14156be10(decoder, pStream, this);
    unsigned int result = 0;
    if (FUN_1415fb750(decoder) != 0)
        result = Decode(reinterpret_cast<CNMSerializableDecoder*>(decoder), pStream);
    FUN_14156bd50(decoder);
    return result;
}

// MS2-FUNCTIONAL: selects framed decoding for version two records.
// @0x14157ad20
unsigned int CNMGameServerCode::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        DecodeFramed(pStream);
    else
        Decode(pDecoder, pStream);
    return 0;
}

// MS2-FUNCTIONAL: restores the server code and validates the decoder.
// @0x14157ad80
unsigned int CNMGameServerCode::Decode(CNMSerializableDecoder* pDecoder, CNMStream*)
{
    m_nServerCode = static_cast<int>(pDecoder->ReadU32());
    FUN_1415fb750(pDecoder);
    return 1;
}
