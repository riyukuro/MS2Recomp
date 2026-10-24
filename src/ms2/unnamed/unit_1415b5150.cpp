// MS2-UNIT: unit_1415b5150
// MS2-RANGE: 0x1415b5150-0x1415b55b0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/placeholder/nmobjects.h"
#include "ms2/placeholder/nmfunc.h"
#include "ms2/ms2recover.h"

extern void FUN_14156bcb0(void*, void*, void*);
extern void FUN_14156bd50(void*);
extern void FUN_14156be10(void*, void*, void*);
extern void FUN_14156bf10(void*);
extern void FUN_14156acb0(void*, unsigned long long);
extern void FUN_14156ab00(void*, unsigned char);
extern void FUN_1415efea0(CNMChatMessage*, const CNMChatMessage*);
extern unsigned int FUN_1415f9990(void*);
extern int FUN_1415fb6d0(void*);
extern int FUN_1415fb750(void*);

// MS2-FUNCTIONAL 0x1415b5150: initializes a guild chat event and its embedded message.
CNMGuildChatMessageEvent::CNMGuildChatMessageEvent()
    : CNMEvent(0x1013, 1, 0, 0), m_28(0), m_30(0), m_38(0), m_3c(0), m_40()
{
}

// MS2-FUNCTIONAL 0x1415b51e0: transfers the message and guild identifiers into the event.
// @0x1415b51e0
CNMGuildChatMessageEvent::CNMGuildChatMessageEvent(long long n28, long long n30, int n38,
                                                     CNMChatMessage message)
    : CNMEvent(0x1013, 1, 0, 0), m_28(n28), m_30(n30), m_38(n38), m_3c(0), m_40()
{
    FUN_1415efea0(&m_40, &message);
}

// MS2-FUNCTIONAL 0x1415b52a0: frames event encoding through a temporary stream adapter.
// @0x1415b52a0
unsigned int CNMGuildChatMessageEvent::EncodeFramed(CNMStream* pStream)
{
    unsigned char storage[0x18];
    FUN_14156bcb0(storage, pStream, this);
    const unsigned int result = Encode(reinterpret_cast<CNMEncoder*>(storage), pStream);
    FUN_14156bd50(storage);
    return result;
}

// MS2-FUNCTIONAL 0x1415b5300: chooses direct or framed encoding by event format.
// @0x1415b5300
unsigned int CNMGuildChatMessageEvent::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    return m_bFormat == 1 ? Encode(pEncoder, pStream) : EncodeFramed(pStream);
}

// MS2-FUNCTIONAL 0x1415b5360: writes event metadata and its framed chat-message record.
// @0x1415b5360
unsigned int CNMGuildChatMessageEvent::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMEvent::EncodeDispatch(pEncoder, pStream);
    FUN_14156acb0(pEncoder, static_cast<unsigned long long>(m_28));
    FUN_14156acb0(pEncoder, static_cast<unsigned long long>(m_30));
    FUN_14156ab00(pEncoder, static_cast<unsigned char>(m_38));
    m_40.EncodeFramed(pStream);
    FUN_1415f9990(pEncoder);
    return 1;
}

// MS2-FUNCTIONAL 0x1415b5410: builds a decoder adapter and validates the frame.
// @0x1415b5410
unsigned int CNMGuildChatMessageEvent::DecodeFramed(CNMStream* pStream)
{
    unsigned char storage[0x38];
    FUN_14156be10(storage, pStream, this);
    unsigned int result = 0;
    if (FUN_1415fb750(storage))
        result = Decode(reinterpret_cast<CNMSerializableDecoder*>(storage), pStream);
    FUN_14156bf10(storage);
    return result;
}

// MS2-FUNCTIONAL 0x1415b54a0: selects framed decoding when the decoder reports format 2.
// @0x1415b54a0
unsigned int CNMGuildChatMessageEvent::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    return FUN_1415fb6d0(pDecoder) == 2 ? DecodeFramed(pStream) : Decode(pDecoder, pStream);
}

// MS2-FUNCTIONAL 0x1415b5500: restores event metadata and the embedded chat-message record.
// @0x1415b5500
unsigned int CNMGuildChatMessageEvent::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMEvent::DecodeDispatch(pDecoder, pStream);
    m_28 = static_cast<long long>(pDecoder->ReadU64());
    m_30 = static_cast<long long>(pDecoder->ReadU64());
    m_38 = pDecoder->ReadU8();
    m_40.DecodeFramed(pStream);
    return static_cast<unsigned int>(FUN_1415fb750(pDecoder));
}

// MS2-PIN: ??0CNMGuildChatMessageEvent@@QEAA@_J0HVCNMChatMessage@@@Z 0x1415b51e0 ; constructor that transfers a by-value chat message
// MS2-PIN: ??0CNMGuildChatMessageEvent@@QEAA@XZ 0x1415b5150 ; default constructor
