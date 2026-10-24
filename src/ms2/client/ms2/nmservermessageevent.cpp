// Recovered Nexon Messenger server message event.
// MS2-UNIT: ?\nmservermessageevent.cpp
// MS2-RANGE: 0x1415b31a0-0x1415b3520 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmfunc.h"
#include "ms2/placeholder/nmobjects.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/ms2recover.h"

extern CNMSerializable* FUN_1415f1660(CNMSerializable*, long long);
extern void FUN_14156bcb0(void*, void*, void*);
extern void FUN_14156be10(void*, void*, void*);
extern void FUN_14156bd50(void*);
extern void FUN_14156bf10(void*);
extern void FUN_1415f9990(void*);
extern int FUN_1415fb6d0(void*);
extern int FUN_1415fb750(void*);

// MS2-FUNCTIONAL: initializes an empty server message payload.
// @0x1415b31a0
CNMServerMessageEvent::CNMServerMessageEvent()
    : CNMEvent(0x1006, 1, 0, 0), m_28()
{
}

// MS2-FUNCTIONAL: copies the supplied message payload into the event.
// @0x1415b3210
CNMServerMessageEvent::CNMServerMessageEvent(const CNMMessageData& data)
    : CNMEvent(0x1006, 1, 0, 0), m_28()
{
    FUN_1415f1660(reinterpret_cast<CNMSerializable*>(&m_28), reinterpret_cast<long long>(const_cast<CNMMessageData*>(&data)));
}

// MS2-FUNCTIONAL: frames server message event encoding.
// @0x1415b3290
unsigned int CNMServerMessageEvent::EncodeFramed(CNMStream* pStream)
{
    alignas(8) unsigned char encoder[0x18];
    FUN_14156bcb0(encoder, pStream, this);
    const unsigned int result = Encode(reinterpret_cast<CNMEncoder*>(encoder), pStream);
    FUN_14156bd50(encoder);
    return result;
}

// MS2-FUNCTIONAL: selects direct or framed event encoding.
// @0x1415b32f0
unsigned int CNMServerMessageEvent::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        Encode(pEncoder, pStream);
    else
        EncodeFramed(pStream);
    return 0;
}

// MS2-FUNCTIONAL: serializes the embedded message data as a framed record.
// @0x1415b3350
unsigned int CNMServerMessageEvent::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMEvent::EncodeDispatch(pEncoder, pStream);
    m_28.EncodeFramed(pStream);
    FUN_1415f9990(pEncoder);
    return 1;
}

// MS2-FUNCTIONAL: validates framed event input before decoding the embedded message.
// @0x1415b33c0
unsigned int CNMServerMessageEvent::DecodeFramed(CNMStream* pStream)
{
    alignas(8) unsigned char decoder[0x38];
    FUN_14156be10(decoder, pStream, this);
    unsigned int result = 0;
    if (FUN_1415fb750(decoder) != 0)
        result = Decode(reinterpret_cast<CNMSerializableDecoder*>(decoder), pStream);
    FUN_14156bf10(decoder);
    return result;
}

// MS2-FUNCTIONAL: routes version two events through framed decoding.
// @0x1415b3450
unsigned int CNMServerMessageEvent::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        DecodeFramed(pStream);
    else
        Decode(pDecoder, pStream);
    return 0;
}

// MS2-FUNCTIONAL: decodes the event header and embedded server message.
// @0x1415b34b0
unsigned int CNMServerMessageEvent::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMEvent::DecodeDispatch(pDecoder, pStream);
    m_28.DecodeFramed(pStream);
    FUN_1415fb750(pDecoder);
    return 1;
}

// MS2-PIN: ??0CNMServerMessageEvent@@QEAA@XZ 0x1415b31a0
