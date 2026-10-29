// Recovered Nexon Messenger new friend request event.
// MS2-UNIT: ?\nmrequestnewfriendevent.cpp
// MS2-RANGE: 0x1415b2e20-0x1415b31a0 .text$mn
// MS2-PIN: ??0CNMSerializableEncoder@@QEAA@PEAVCNMStream@@PEAVCNMSerializable@@@Z 0x14156bcb0
// MS2-PIN: ??1CNMSerializableEncoder@@QEAA@XZ 0x14156bd50
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmfunc.h"
#include "ms2/placeholder/nmobjects.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/placeholder/nmencoder.h"
#include "ms2/ms2recover.h"

extern CNMSerializable* FUN_1415f2310(CNMSerializable*, long long);
extern void FUN_1415f9990(void*);
extern int FUN_1415fb6d0(CNMSerializableDecoder*);
extern int FUN_1415fb750(void*);

// @0x1415b2e20
CNMRequestNewFriendEvent::CNMRequestNewFriendEvent()
    : CNMEvent(0x1005, 1, 0, 0), m_28()
{
}

// @0x1415b2e90
CNMRequestNewFriendEvent::CNMRequestNewFriendEvent(const CNMRequestNewFriendData& data)
    : CNMEvent(0x1005, 1, 0, 0), m_28()
{
    FUN_1415f2310(reinterpret_cast<CNMSerializable*>(&m_28), reinterpret_cast<long long>(const_cast<CNMRequestNewFriendData*>(&data)));
}

// @0x1415b2f10
unsigned int CNMRequestNewFriendEvent::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMRequestNewFriendEvent::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}

// @0x1415b2f70
unsigned int CNMRequestNewFriendEvent::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMRequestNewFriendEvent::Encode(pEncoder, pStream);
    return CNMRequestNewFriendEvent::EncodeFramed(pStream);
}

// @0x1415b2fd0
unsigned int CNMRequestNewFriendEvent::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMEvent::EncodeDispatch(pEncoder, pStream);
    m_28.EncodeFramed(pStream);
    FUN_1415f9990(pEncoder);
    return 1;
}

// @0x1415b3040
unsigned int CNMRequestNewFriendEvent::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMRequestNewFriendEvent::Decode(&decoder, pStream);
}

// @0x1415b30d0
unsigned int CNMRequestNewFriendEvent::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMRequestNewFriendEvent::DecodeFramed(pStream);
    return CNMRequestNewFriendEvent::Decode(pDecoder, pStream);
}

// @0x1415b3130
unsigned int CNMRequestNewFriendEvent::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMEvent::DecodeDispatch(pDecoder, pStream);
    m_28.DecodeFramed(pStream);
    return FUN_1415fb750(pDecoder);
}

// MS2-PIN: ??0CNMRequestNewFriendEvent@@QEAA@XZ 0x1415b2e20
