// MS2-UNIT: unit_1415b6920
// MS2-RANGE: 0x1415b6920-0x1415b6dc0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/placeholder/nmobjects.h"
#include "ms2/placeholder/nmfunc.h"
#include "ms2/placeholder/nmencoder.h"
#include "ms2/ms2recover.h"

extern long long FUN_1415f1e90(long long, long long);
extern void FUN_14156bcb0(void*, void*, void*);
extern void FUN_14156bd50(void*);
extern void FUN_14156be10(void*, void*, void*);
extern void FUN_14156bf10(void*);
extern void FUN_14156ac20(void*, unsigned int);
extern void FUN_14156ab00(void*, unsigned char);
extern unsigned int FUN_1415f9990(void*);
extern int FUN_1415fb6d0(CNMSerializableDecoder*);
extern int FUN_1415fb750(void*);

// MS2-FUNCTIONAL 0x1415b6920: initializes the friend-info event and optional avatar state.
CNMRealFriendInfoChangedEvent::CNMRealFriendInfoChangedEvent()
    : CNMEvent(0x100e, 1, 0, 0), m_30(), m_110()
{
    m_28 = 0;
    m_108 = 0;
}

// MS2-FUNCTIONAL 0x1415b69b0: copies friend details and clears the optional-avatar flag.
// @0x1415b69b0
CNMRealFriendInfoChangedEvent::CNMRealFriendInfoChangedEvent(int reason, const CNMRealFriendInfo& rInfo)
    : CNMEvent(0x100e, 1, 0, 0), m_30(), m_110()
{
    m_28 = reason;
    FUN_1415f1e90(reinterpret_cast<long long>(&m_30), reinterpret_cast<long long>(&rInfo));
    m_108 = 0;
}

// MS2-FUNCTIONAL 0x1415b6a60: frames event encoding through a temporary stream adapter.
// @0x1415b6a60
unsigned int CNMRealFriendInfoChangedEvent::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMRealFriendInfoChangedEvent::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}

// MS2-FUNCTIONAL 0x1415b6ac0: chooses direct or framed encoding.
// @0x1415b6ac0
unsigned int CNMRealFriendInfoChangedEvent::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMRealFriendInfoChangedEvent::Encode(pEncoder, pStream);
    return CNMRealFriendInfoChangedEvent::EncodeFramed(pStream);
}

// MS2-FUNCTIONAL 0x1415b6b20: serializes friend data and an optional avatar record.
// @0x1415b6b20
unsigned int CNMRealFriendInfoChangedEvent::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMEvent::EncodeDispatch(pEncoder, pStream);
    FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_28));
    m_30.EncodeFramed(pStream);
    FUN_14156ab00(pEncoder, static_cast<unsigned char>(m_108));
    if (m_108 != 0)
        m_110.EncodeFramed(pStream);
    FUN_1415f9990(pEncoder);
    return 1;
}

// MS2-FUNCTIONAL 0x1415b6bf0: validates a temporary framed decoder before dispatch.
// @0x1415b6bf0
unsigned int CNMRealFriendInfoChangedEvent::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMRealFriendInfoChangedEvent::Decode(&decoder, pStream);
}

// MS2-FUNCTIONAL 0x1415b6c80: dispatches framed decoding when the format is 2.
// @0x1415b6c80
unsigned int CNMRealFriendInfoChangedEvent::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMRealFriendInfoChangedEvent::DecodeFramed(pStream);
    return CNMRealFriendInfoChangedEvent::Decode(pDecoder, pStream);
}

// MS2-FUNCTIONAL 0x1415b6ce0: restores friend data and conditionally restores the avatar.
// @0x1415b6ce0
unsigned int CNMRealFriendInfoChangedEvent::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMEvent::DecodeDispatch(pDecoder, pStream);
    m_28 = static_cast<int>(pDecoder->ReadU32());
    m_30.DecodeFramed(pStream);
    m_108 = pDecoder->ReadU8();
    if (m_108 != 0)
        m_110.DecodeFramed(pStream);
    return static_cast<unsigned int>(FUN_1415fb750(pDecoder));
}

// MS2-PIN: ??0CNMRealFriendInfoChangedEvent@@QEAA@XZ 0x1415b6920 ; default constructor
// MS2-PIN: ??0CNMRealFriendInfoChangedEvent@@QEAA@HAEBVCNMRealFriendInfo@@@Z 0x1415b69b0 ; constructor with friend info
