// Recovered Nexon Messenger new friend request event.
// MS2-UNIT: ?\nmrequestnewfriendevent.cpp
// MS2-RANGE: 0x1415b2e20-0x1415b31a0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmfunc.h"
#include "ms2/placeholder/nmobjects.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/ms2recover.h"

extern CNMSerializable* FUN_1415f2310(CNMSerializable*, long long);
extern void FUN_14156bcb0(void*, void*, void*);
extern void FUN_14156be10(void*, void*, void*);
extern void FUN_14156bd50(void*);
extern void FUN_14156bf10(void*);
extern void FUN_1415f9990(void*);
extern int FUN_1415fb6d0(void*);
extern int FUN_1415fb750(void*);

// MS2-FUNCTIONAL: initializes the new friend request event's embedded data.
// @0x1415b2e20
CNMRequestNewFriendEvent::CNMRequestNewFriendEvent()
    : CNMEvent(0x1005, 1, 0, 0), m_28()
{
}

// MS2-FUNCTIONAL: copies supplied request details into the event payload.
// @0x1415b2e90
CNMRequestNewFriendEvent::CNMRequestNewFriendEvent(const CNMRequestNewFriendData& data)
    : CNMEvent(0x1005, 1, 0, 0), m_28()
{
    FUN_1415f2310(reinterpret_cast<CNMSerializable*>(&m_28), reinterpret_cast<long long>(const_cast<CNMRequestNewFriendData*>(&data)));
}

// MS2-FUNCTIONAL: frames event encoding.
// @0x1415b2f10
unsigned int CNMRequestNewFriendEvent::EncodeFramed(CNMStream* pStream)
{
    alignas(8) unsigned char encoder[0x18];
    FUN_14156bcb0(encoder, pStream, this);
    const unsigned int result = Encode(reinterpret_cast<CNMEncoder*>(encoder), pStream);
    FUN_14156bd50(encoder);
    return result;
}

// MS2-FUNCTIONAL: chooses direct or framed event encoding.
// @0x1415b2f70
unsigned int CNMRequestNewFriendEvent::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        Encode(pEncoder, pStream);
    else
        EncodeFramed(pStream);
    return 0;
}

// MS2-FUNCTIONAL: serializes the embedded request data as a framed record.
// @0x1415b2fd0
unsigned int CNMRequestNewFriendEvent::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMEvent::EncodeDispatch(pEncoder, pStream);
    m_28.EncodeFramed(pStream);
    FUN_1415f9990(pEncoder);
    return 1;
}

// MS2-FUNCTIONAL: validates framed event input before decoding its embedded payload.
// @0x1415b3040
unsigned int CNMRequestNewFriendEvent::DecodeFramed(CNMStream* pStream)
{
    alignas(8) unsigned char decoder[0x38];
    FUN_14156be10(decoder, pStream, this);
    unsigned int result = 0;
    if (FUN_1415fb750(decoder) != 0)
        result = Decode(reinterpret_cast<CNMSerializableDecoder*>(decoder), pStream);
    FUN_14156bf10(decoder);
    return result;
}

// MS2-FUNCTIONAL: selects framed decoding for version two events.
// @0x1415b30d0
unsigned int CNMRequestNewFriendEvent::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        DecodeFramed(pStream);
    else
        Decode(pDecoder, pStream);
    return 0;
}

// MS2-FUNCTIONAL: decodes the event header and embedded new friend request data.
// @0x1415b3130
unsigned int CNMRequestNewFriendEvent::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMEvent::DecodeDispatch(pDecoder, pStream);
    m_28.DecodeFramed(pStream);
    FUN_1415fb750(pDecoder);
    return 1;
}

// MS2-PIN: ??0CNMRequestNewFriendEvent@@QEAA@XZ 0x1415b2e20
