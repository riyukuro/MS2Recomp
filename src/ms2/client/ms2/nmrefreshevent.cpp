// Recovered Nexon Messenger refresh event.
// MS2-UNIT: ?\nmrefreshevent.cpp
// MS2-RANGE: 0x1415b2740-0x1415b2a70 .text$mn
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

extern void FUN_14156ac20(void*, unsigned int);
extern void FUN_1415f9990(void*);
extern int FUN_1415fb6d0(CNMSerializableDecoder*);
extern int FUN_1415fb750(void*);

// @0x1415b2740
CNMRefreshEvent::CNMRefreshEvent()
    : CNMEvent(0x1003, 1, 0, 0), m_28(0)
{
}

// @0x1415b27a0
CNMRefreshEvent::CNMRefreshEvent(int value)
    : CNMEvent(0x1003, 1, 0, 0), m_28(value)
{
}

// @0x1415b2800
unsigned int CNMRefreshEvent::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMRefreshEvent::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}

// @0x1415b2860
unsigned int CNMRefreshEvent::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMRefreshEvent::Encode(pEncoder, pStream);
    return CNMRefreshEvent::EncodeFramed(pStream);
}

// @0x1415b28c0
unsigned int CNMRefreshEvent::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMEvent::EncodeDispatch(pEncoder, pStream);
    FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_28));
    FUN_1415f9990(pEncoder);
    return 1;
}

// @0x1415b2920
unsigned int CNMRefreshEvent::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMRefreshEvent::Decode(&decoder, pStream);
}

// @0x1415b29b0
unsigned int CNMRefreshEvent::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMRefreshEvent::DecodeFramed(pStream);
    return CNMRefreshEvent::Decode(pDecoder, pStream);
}

// @0x1415b2a10
unsigned int CNMRefreshEvent::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMEvent::DecodeDispatch(pDecoder, pStream);
    m_28 = static_cast<int>(pDecoder->ReadU32());
    return static_cast<unsigned int>(FUN_1415fb750(pDecoder));
}

// MS2-PIN: ??0CNMRefreshEvent@@QEAA@XZ 0x1415b2740
// MS2-PIN: ??0CNMRefreshEvent@@QEAA@H@Z 0x1415b27a0
