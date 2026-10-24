// MS2-UNIT: unit_1415b4d50
// MS2-RANGE: 0x1415b4d50-0x1415b5150 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/placeholder/nmobjects.h"
#include "ms2/placeholder/nmfunc.h"
#include "ms2/ms2recover.h"

extern CNMSerializable* FUN_1415f14b0(CNMSerializable*, long long);
extern long long FUN_141575710(long long, long long);
extern void FUN_14156bcb0(void*, void*, void*);
extern void FUN_14156bd50(void*);
extern void FUN_14156be10(void*, void*, void*);
extern void FUN_14156bf10(void*);
extern unsigned int FUN_1415f9990(void*);
extern int FUN_1415fb6d0(void*);
extern unsigned int FUN_1415fb750(void*);

// MS2-FUNCTIONAL 0x1415b4d50: initializes the event and its embedded online-info record.
// @0x1415b4d50
CNMGuildOnlineInfoEvent::CNMGuildOnlineInfoEvent()
    : CNMEvent(0x100d, 1, 0, 0), m_28() {}

// MS2-FUNCTIONAL 0x1415b4dc0: copies a guild-online-info record into the event.
// @0x1415b4dc0
CNMGuildOnlineInfoEvent::CNMGuildOnlineInfoEvent(const CNMGuildOnlineInfo& rInfo)
    : CNMEvent(0x100d, 1, 0, 0), m_28()
{
    FUN_1415f14b0(reinterpret_cast<CNMSerializable*>(&m_28),
                  reinterpret_cast<long long>(&rInfo));
}

// MS2-FUNCTIONAL 0x1415b4e40: converts an extended guild-info record into the event's base record.
// @0x1415b4e40
CNMGuildOnlineInfoEvent::CNMGuildOnlineInfoEvent(const CNMGuildOnlineInfoEx& rInfo)
    : CNMEvent(0x100d, 1, 0, 0), m_28()
{
    FUN_141575710(reinterpret_cast<long long>(&m_28),
                  reinterpret_cast<long long>(&rInfo));
}

// MS2-FUNCTIONAL 0x1415b4ec0: frames serialization through the event stream adapter.
// @0x1415b4ec0
unsigned int CNMGuildOnlineInfoEvent::EncodeFramed(CNMStream* pStream)
{
    unsigned char storage[0x18];
    FUN_14156bcb0(storage, pStream, this);
    const unsigned int result = Encode(reinterpret_cast<CNMEncoder*>(storage), pStream);
    FUN_14156bd50(storage);
    return result;
}

// MS2-FUNCTIONAL 0x1415b4f20: selects direct or framed event encoding from the format byte.
// @0x1415b4f20
unsigned int CNMGuildOnlineInfoEvent::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    return m_bFormat == 1 ? Encode(pEncoder, pStream) : EncodeFramed(pStream);
}

// MS2-FUNCTIONAL 0x1415b4f80: serializes the base event and nested guild-info record.
// @0x1415b4f80
unsigned int CNMGuildOnlineInfoEvent::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMEvent::EncodeDispatch(pEncoder, pStream);
    m_28.EncodeFramed(pStream);
    FUN_1415f9990(pEncoder);
    return 1;
}

// MS2-FUNCTIONAL 0x1415b4ff0: creates a decoder adapter and validates before dispatching.
// @0x1415b4ff0
unsigned int CNMGuildOnlineInfoEvent::DecodeFramed(CNMStream* pStream)
{
    unsigned char storage[0x38];
    FUN_14156be10(storage, pStream, this);
    unsigned int result = 0;
    if (FUN_1415fb750(storage))
        result = Decode(reinterpret_cast<CNMSerializableDecoder*>(storage), pStream);
    FUN_14156bf10(storage);
    return result;
}

// MS2-FUNCTIONAL 0x1415b5080: chooses framed decode for the framed event format.
// @0x1415b5080
unsigned int CNMGuildOnlineInfoEvent::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    return FUN_1415fb6d0(pDecoder) == 2 ? DecodeFramed(pStream) : Decode(pDecoder, pStream);
}

// MS2-FUNCTIONAL 0x1415b50e0: decodes the base event and its embedded guild-info record.
// @0x1415b50e0
unsigned int CNMGuildOnlineInfoEvent::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMEvent::DecodeDispatch(pDecoder, pStream);
    m_28.DecodeFramed(pStream);
    return FUN_1415fb750(pDecoder);
}
