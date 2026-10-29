// MS2-UNIT: unit_1415b65a0
// MS2-RANGE: 0x1415b65a0-0x1415b6920 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/placeholder/nmobjects.h"
#include "ms2/placeholder/nmfunc.h"
#include "ms2/placeholder/nmencoder.h"
#include "ms2/ms2recover.h"

extern CNMSerializable* FUN_1415f1580(CNMSerializable*, long long);
extern void FUN_14156bcb0(void*, void*, void*);
extern void FUN_14156bd50(void*);
extern void FUN_14156be10(void*, void*, void*);
extern void FUN_14156bf10(void*);
extern unsigned int FUN_1415f9990(void*);
extern int FUN_1415fb6d0(CNMSerializableDecoder*);
extern int FUN_1415fb750(void*);

// MS2-FUNCTIONAL 0x1415b65a0: initializes the event and embedded extended guild-info record.
CNMGuildOnlineInfoExEvent::CNMGuildOnlineInfoExEvent()
    : CNMEvent(0x1012, 1, 0, 0), m_28() {}

// MS2-FUNCTIONAL 0x1415b6610: copies the extended guild-info record into the event.
// @0x1415b6610
CNMGuildOnlineInfoExEvent::CNMGuildOnlineInfoExEvent(const CNMGuildOnlineInfoEx& rInfo)
    : CNMEvent(0x1012, 1, 0, 0), m_28()
{
    FUN_1415f1580(reinterpret_cast<CNMSerializable*>(&m_28),
                  reinterpret_cast<long long>(&rInfo));
}

// MS2-FUNCTIONAL 0x1415b6690: frames event encoding through the stream adapter.
// @0x1415b6690
unsigned int CNMGuildOnlineInfoExEvent::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMGuildOnlineInfoExEvent::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}

// MS2-FUNCTIONAL 0x1415b66f0: chooses direct or framed event encoding.
// @0x1415b66f0
unsigned int CNMGuildOnlineInfoExEvent::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMGuildOnlineInfoExEvent::Encode(pEncoder, pStream);
    return CNMGuildOnlineInfoExEvent::EncodeFramed(pStream);
}

// MS2-FUNCTIONAL 0x1415b6750: serializes base event and nested extended guild info.
// @0x1415b6750
unsigned int CNMGuildOnlineInfoExEvent::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMEvent::EncodeDispatch(pEncoder, pStream);
    m_28.EncodeFramed(pStream);
    FUN_1415f9990(pEncoder);
    return 1;
}

// MS2-FUNCTIONAL 0x1415b67c0: builds and validates the framed decoder.
// @0x1415b67c0
unsigned int CNMGuildOnlineInfoExEvent::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMGuildOnlineInfoExEvent::Decode(&decoder, pStream);
}

// MS2-FUNCTIONAL 0x1415b6850: dispatches according to the serialized format byte.
// @0x1415b6850
unsigned int CNMGuildOnlineInfoExEvent::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMGuildOnlineInfoExEvent::DecodeFramed(pStream);
    return CNMGuildOnlineInfoExEvent::Decode(pDecoder, pStream);
}

// MS2-FUNCTIONAL 0x1415b68b0: decodes the event and nested extended guild-info record.
// @0x1415b68b0
unsigned int CNMGuildOnlineInfoExEvent::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMEvent::DecodeDispatch(pDecoder, pStream);
    m_28.DecodeFramed(pStream);
    return static_cast<unsigned int>(FUN_1415fb750(pDecoder));
}

// MS2-PIN: ??0CNMGuildOnlineInfoExEvent@@QEAA@XZ 0x1415b65a0 ; default constructor
