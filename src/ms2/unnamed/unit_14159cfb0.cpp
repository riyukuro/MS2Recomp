// Recovered from the Nexon Messenger client library: chat-room info request.
// MS2-UNIT: unit_14159cfb0
// MS2-RANGE: 0x14159cfb0-0x14159d340 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmobjects.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/placeholder/nmencoder.h"
#include "ms2/ms2recover.h"

extern int FUN_1415fb720(void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(CNMSerializableDecoder*);
extern void FUN_1415f9990(void*);
extern void FUN_14156bcb0(void*, void*, void*);
extern void FUN_14156bd50(void*);

// MS2-FUNCTIONAL: request ID, format, and base initialization match; constructor register width differs.
// @0x14159cfb0
CNMCRGetRoomInfoFunc::CNMCRGetRoomInfoFunc()
    : CNMFunc(0xb003, 1, 0, 0)
{
}

// MS2-FUNCTIONAL: request ID, serial key, and base initialization match; constructor register width differs.
// @0x14159d020
CNMCRGetRoomInfoFunc::CNMCRGetRoomInfoFunc(unsigned uSerialKey)
    : CNMFunc(0xb003, 1, static_cast<int>(uSerialKey), 0)
{
}

// MS2-FUNCTIONAL: framed encoder setup and cleanup match; local encoder storage differs.
// @0x14159d090
unsigned int CNMCRGetRoomInfoFunc::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMCRGetRoomInfoFunc::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}

// MS2-FUNCTIONAL: recovered format branch; direct calls replace virtual dispatch.
// @0x14159d0f0
unsigned int CNMCRGetRoomInfoFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMCRGetRoomInfoFunc::Encode(pEncoder, pStream);
    return CNMCRGetRoomInfoFunc::EncodeFramed(pStream);
}

// MS2-FUNCTIONAL: reply payload gate and finish call match; direct dispatch replaces virtual calls.
// @0x14159d150
unsigned int CNMCRGetRoomInfoFunc::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMFunc::EncodeDispatch(pEncoder, pStream);
    if (FUN_1415fb720(this) != 0)
        m_room.EncodeFramed(pStream);
    FUN_1415f9990(pEncoder);
    return 1;
}

// MS2-FUNCTIONAL: decoder wrapper lifetime and validity branch match; local decoder storage differs.
// @0x14159d1d0
unsigned int CNMCRGetRoomInfoFunc::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMCRGetRoomInfoFunc::Decode(&decoder, pStream);
}

// MS2-FUNCTIONAL: recovered decoder format branch; direct calls replace virtual dispatch.
// @0x14159d260
unsigned int CNMCRGetRoomInfoFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMCRGetRoomInfoFunc::DecodeFramed(pStream);
    return CNMCRGetRoomInfoFunc::Decode(pDecoder, pStream);
}

// MS2-FUNCTIONAL: reply payload gate and validity check match; direct dispatch replaces virtual calls.
// @0x14159d2c0
unsigned int CNMCRGetRoomInfoFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    if (FUN_1415fb720(this) != 0)
        m_room.DecodeFramed(pStream);
    return FUN_1415fb750(pDecoder);
}

// MS2-PIN: ??0CNMCRGetRoomInfoFunc@@QEAA@XZ 0x14159cfb0
