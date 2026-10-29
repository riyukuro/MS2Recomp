// Recovered Nexon Messenger user information event.
// MS2-UNIT: ?\nmuserinfoevent.cpp
// MS2-RANGE: 0x1415b49d0-0x1415b4d50 .text$mn
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

extern CNMSerializable* FUN_1415f1f10(CNMSerializable*, long long);
extern void FUN_14156bcb0(void*, void*, void*);
extern void FUN_14156be10(void*, void*, void*);
extern void FUN_14156bd50(void*);
extern void FUN_14156bf10(void*);
extern void FUN_1415f9990(void*);
extern int FUN_1415fb6d0(CNMSerializableDecoder*);
extern int FUN_1415fb750(void*);

// @0x1415b49d0
CNMUserInfoEvent::CNMUserInfoEvent()
    : CNMEvent(0x100c, 1, 0, 0), m_28()
{
}

// @0x1415b4a40
CNMUserInfoEvent::CNMUserInfoEvent(const CNMRealUserInfo& data)
    : CNMEvent(0x100c, 1, 0, 0), m_28()
{
    FUN_1415f1f10(reinterpret_cast<CNMSerializable*>(&m_28), reinterpret_cast<long long>(const_cast<CNMRealUserInfo*>(&data)));
}

// @0x1415b4ac0
unsigned int CNMUserInfoEvent::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMUserInfoEvent::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}

// @0x1415b4b20
unsigned int CNMUserInfoEvent::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMUserInfoEvent::Encode(pEncoder, pStream);
    return CNMUserInfoEvent::EncodeFramed(pStream);
}

// @0x1415b4b80
unsigned int CNMUserInfoEvent::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMEvent::EncodeDispatch(pEncoder, pStream);
    m_28.EncodeFramed(pStream);
    FUN_1415f9990(pEncoder);
    return 1;
}

// @0x1415b4bf0
unsigned int CNMUserInfoEvent::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMUserInfoEvent::Decode(&decoder, pStream);
}

// @0x1415b4c80
unsigned int CNMUserInfoEvent::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMUserInfoEvent::DecodeFramed(pStream);
    return CNMUserInfoEvent::Decode(pDecoder, pStream);
}

// @0x1415b4ce0
unsigned int CNMUserInfoEvent::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMEvent::DecodeDispatch(pDecoder, pStream);
    m_28.DecodeFramed(pStream);
    return FUN_1415fb750(pDecoder);
}

// MS2-PIN: ??0CNMUserInfoEvent@@QEAA@XZ 0x1415b49d0
