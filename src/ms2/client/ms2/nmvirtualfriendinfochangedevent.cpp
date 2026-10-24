// Recovered Nexon Messenger virtual friend info changed event.
// MS2-UNIT: ?\nmvirtualfriendinfochangedevent.cpp
// MS2-RANGE: 0x1415b6dc0-0x1415b7170 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmfunc.h"
#include "ms2/placeholder/nmobjects.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/ms2recover.h"

extern CNMSerializable* FUN_1415f2720(CNMSerializable*, long long);
extern void FUN_14156bcb0(void*, void*, void*);
extern void FUN_14156be10(void*, void*, void*);
extern void FUN_14156bd50(void*);
extern void FUN_14156bf10(void*);
extern void FUN_14156ac20(void*, unsigned int);
extern void FUN_1415f9990(void*);
extern int FUN_1415fb6d0(void*);
extern int FUN_1415fb750(void*);

// MS2-FUNCTIONAL: initializes virtual friend info change event fields.
// @0x1415b6dc0
CNMVirtualFriendInfoChangedEvent::CNMVirtualFriendInfoChangedEvent()
    : CNMEvent(0x100f, 1, 0, 0), m_28(0), m_30()
{
}

// MS2-FUNCTIONAL: copies virtual friend info into the event payload.
// @0x1415b6e30
CNMVirtualFriendInfoChangedEvent::CNMVirtualFriendInfoChangedEvent(int type, const CNMVirtualFriendInfo& info)
    : CNMEvent(0x100f, 1, 0, 0), m_28(type), m_30()
{
    FUN_1415f2720(reinterpret_cast<CNMSerializable*>(&m_30), reinterpret_cast<long long>(const_cast<CNMVirtualFriendInfo*>(&info)));
}

// MS2-FUNCTIONAL: frames event encoding.
// @0x1415b6ec0
unsigned int CNMVirtualFriendInfoChangedEvent::EncodeFramed(CNMStream* pStream)
{
    alignas(8) unsigned char encoder[0x18];
    FUN_14156bcb0(encoder, pStream, this);
    const unsigned int result = Encode(reinterpret_cast<CNMEncoder*>(encoder), pStream);
    FUN_14156bd50(encoder);
    return result;
}

// MS2-FUNCTIONAL: selects direct or framed event encoding.
// @0x1415b6f20
unsigned int CNMVirtualFriendInfoChangedEvent::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        Encode(pEncoder, pStream);
    else
        EncodeFramed(pStream);
    return 0;
}

// MS2-FUNCTIONAL: writes the event type and virtual friend record.
// @0x1415b6f80
unsigned int CNMVirtualFriendInfoChangedEvent::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMEvent::EncodeDispatch(pEncoder, pStream);
    FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_28));
    m_30.EncodeFramed(pStream);
    FUN_1415f9990(pEncoder);
    return 1;
}

// MS2-FUNCTIONAL: validates framed input before decoding virtual friend info.
// @0x1415b7000
unsigned int CNMVirtualFriendInfoChangedEvent::DecodeFramed(CNMStream* pStream)
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
// @0x1415b7090
unsigned int CNMVirtualFriendInfoChangedEvent::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        DecodeFramed(pStream);
    else
        Decode(pDecoder, pStream);
    return 0;
}

// MS2-FUNCTIONAL: decodes the event type and virtual friend payload.
// @0x1415b70f0
unsigned int CNMVirtualFriendInfoChangedEvent::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMEvent::DecodeDispatch(pDecoder, pStream);
    void** vftable = *reinterpret_cast<void***>(pDecoder);
    using ReadU32 = unsigned int(__fastcall*)(void*);
    m_28 = static_cast<int>(reinterpret_cast<ReadU32>(vftable[3])(pDecoder));
    m_30.DecodeFramed(pStream);
    FUN_1415fb750(pDecoder);
    return 1;
}

// MS2-PIN: ??0CNMVirtualFriendInfoChangedEvent@@QEAA@XZ 0x1415b6dc0
