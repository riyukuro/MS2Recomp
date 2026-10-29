// Recovered from the Nexon Messenger client library: extended chat-room info request.
// MS2-UNIT: unit_14159d340
// MS2-RANGE: 0x14159d340-0x14159d6d0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmchatroomfunc.h"
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
// @0x14159d340
CNMCRGetRoomInfoExFunc::CNMCRGetRoomInfoExFunc()
    : CNMFunc(0xb00b, 1, 0, 0)
{
}

// MS2-FUNCTIONAL: request ID, serial key, and base initialization match; constructor register width differs.
// @0x14159d3b0
CNMCRGetRoomInfoExFunc::CNMCRGetRoomInfoExFunc(unsigned uSerialKey)
    : CNMFunc(0xb00b, 1, static_cast<int>(uSerialKey), 0)
{
}

// MS2-FUNCTIONAL: framed encoder setup and cleanup match; local encoder storage differs.
// @0x14159d420
unsigned int CNMCRGetRoomInfoExFunc::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMCRGetRoomInfoExFunc::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}

// MS2-FUNCTIONAL: recovered format branch; direct calls replace virtual dispatch.
// @0x14159d480
unsigned int CNMCRGetRoomInfoExFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMCRGetRoomInfoExFunc::Encode(pEncoder, pStream);
    return CNMCRGetRoomInfoExFunc::EncodeFramed(pStream);
}

// MS2-FUNCTIONAL: reply payload gate and finish call match; direct dispatch replaces virtual calls.
// @0x14159d4e0
unsigned int CNMCRGetRoomInfoExFunc::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMFunc::EncodeDispatch(pEncoder, pStream);
    if (FUN_1415fb720(this) != 0)
        m_info.EncodeFramed(pStream);
    FUN_1415f9990(pEncoder);
    return 1;
}

// MS2-FUNCTIONAL: decoder wrapper lifetime and validity branch match; local decoder storage differs.
// @0x14159d560
unsigned int CNMCRGetRoomInfoExFunc::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMCRGetRoomInfoExFunc::Decode(&decoder, pStream);
}

// MS2-FUNCTIONAL: recovered decoder format branch; direct calls replace virtual dispatch.
// @0x14159d5f0
unsigned int CNMCRGetRoomInfoExFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMCRGetRoomInfoExFunc::DecodeFramed(pStream);
    return CNMCRGetRoomInfoExFunc::Decode(pDecoder, pStream);
}

// MS2-FUNCTIONAL: reply payload gate and validity check match; direct dispatch replaces virtual calls.
// @0x14159d650
unsigned int CNMCRGetRoomInfoExFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    if (FUN_1415fb720(this) != 0)
        m_info.DecodeFramed(pStream);
    return FUN_1415fb750(pDecoder);
}

// MS2-PIN: ??0CNMCRGetRoomInfoExFunc@@QEAA@XZ 0x14159d340
