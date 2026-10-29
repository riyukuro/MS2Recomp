// Recovered Nexon Messenger virtual friend info changed event.
// MS2-UNIT: ?\nmvirtualfriendinfochangedevent.cpp
// MS2-RANGE: 0x1415b6dc0-0x1415b7170 .text$mn
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

extern CNMSerializable* FUN_1415f2720(CNMSerializable*, long long);
extern void FUN_14156ac20(void*, unsigned int);
extern void FUN_1415f9990(void*);
extern int FUN_1415fb6d0(CNMSerializableDecoder*);
extern int FUN_1415fb750(void*);

// @0x1415b6dc0
CNMVirtualFriendInfoChangedEvent::CNMVirtualFriendInfoChangedEvent()
    : CNMEvent(0x100f, 1, 0, 0), m_30()
{
    m_28 = 0;
}

// @0x1415b6e30
CNMVirtualFriendInfoChangedEvent::CNMVirtualFriendInfoChangedEvent(int type, const CNMVirtualFriendInfo& info)
    : CNMEvent(0x100f, 1, 0, 0), m_30()
{
    m_28 = type;
    FUN_1415f2720(reinterpret_cast<CNMSerializable*>(&m_30), reinterpret_cast<long long>(const_cast<CNMVirtualFriendInfo*>(&info)));
}

// @0x1415b6ec0
unsigned int CNMVirtualFriendInfoChangedEvent::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMVirtualFriendInfoChangedEvent::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}

// @0x1415b6f20
unsigned int CNMVirtualFriendInfoChangedEvent::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMVirtualFriendInfoChangedEvent::Encode(pEncoder, pStream);
    return CNMVirtualFriendInfoChangedEvent::EncodeFramed(pStream);
}

// @0x1415b6f80
unsigned int CNMVirtualFriendInfoChangedEvent::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMEvent::EncodeDispatch(pEncoder, pStream);
    FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_28));
    m_30.EncodeFramed(pStream);
    FUN_1415f9990(pEncoder);
    return 1;
}

// @0x1415b7000
unsigned int CNMVirtualFriendInfoChangedEvent::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMVirtualFriendInfoChangedEvent::Decode(&decoder, pStream);
}

// @0x1415b7090
unsigned int CNMVirtualFriendInfoChangedEvent::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMVirtualFriendInfoChangedEvent::DecodeFramed(pStream);
    return CNMVirtualFriendInfoChangedEvent::Decode(pDecoder, pStream);
}

// @0x1415b70f0
unsigned int CNMVirtualFriendInfoChangedEvent::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMEvent::DecodeDispatch(pDecoder, pStream);
    m_28 = static_cast<int>(pDecoder->ReadU32());
    m_30.DecodeFramed(pStream);
    return FUN_1415fb750(pDecoder);
}

// MS2-PIN: ??0CNMVirtualFriendInfoChangedEvent@@QEAA@XZ 0x1415b6dc0
