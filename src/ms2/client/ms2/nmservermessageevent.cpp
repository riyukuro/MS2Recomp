// Recovered Nexon Messenger server message event.
// MS2-UNIT: ?\nmservermessageevent.cpp
// MS2-RANGE: 0x1415b31a0-0x1415b3520 .text$mn
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

extern CNMSerializable* FUN_1415f1660(CNMSerializable*, long long);
extern void FUN_1415f9990(void*);
extern int FUN_1415fb6d0(CNMSerializableDecoder*);
extern int FUN_1415fb750(void*);

// @0x1415b31a0
CNMServerMessageEvent::CNMServerMessageEvent()
    : CNMEvent(0x1006, 1, 0, 0), m_28()
{
}

// @0x1415b3210
CNMServerMessageEvent::CNMServerMessageEvent(const CNMMessageData& data)
    : CNMEvent(0x1006, 1, 0, 0), m_28()
{
    FUN_1415f1660(reinterpret_cast<CNMSerializable*>(&m_28), reinterpret_cast<long long>(const_cast<CNMMessageData*>(&data)));
}

// @0x1415b3290
unsigned int CNMServerMessageEvent::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMServerMessageEvent::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}

// @0x1415b32f0
unsigned int CNMServerMessageEvent::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMServerMessageEvent::Encode(pEncoder, pStream);
    return CNMServerMessageEvent::EncodeFramed(pStream);
}

// @0x1415b3350
unsigned int CNMServerMessageEvent::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMEvent::EncodeDispatch(pEncoder, pStream);
    m_28.EncodeFramed(pStream);
    FUN_1415f9990(pEncoder);
    return 1;
}

// @0x1415b33c0
unsigned int CNMServerMessageEvent::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMServerMessageEvent::Decode(&decoder, pStream);
}

// @0x1415b3450
unsigned int CNMServerMessageEvent::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMServerMessageEvent::DecodeFramed(pStream);
    return CNMServerMessageEvent::Decode(pDecoder, pStream);
}

// @0x1415b34b0
unsigned int CNMServerMessageEvent::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMEvent::DecodeDispatch(pDecoder, pStream);
    m_28.DecodeFramed(pStream);
    return FUN_1415fb750(pDecoder);
}

// MS2-PIN: ??0CNMServerMessageEvent@@QEAA@XZ 0x1415b31a0
