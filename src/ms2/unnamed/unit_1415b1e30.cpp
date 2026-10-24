// MS2-UNIT: unit_1415b1e30
// MS2-RANGE: 0x1415b1e30-0x1415b2410 .text$mn
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
extern void FUN_14156ac20(void*, unsigned int);
extern unsigned int FUN_1415f9990(void*);
extern int FUN_1415fb6d0(void*);
extern int FUN_1415fb700(void*);
extern int FUN_1415fb750(void*);

// MS2-FUNCTIONAL 0x1415b1e30: initializes the event envelope fields.
// @0x1415b1e30
CNMEvent::CNMEvent(int eventId, unsigned char format, int n1c, int n24)
    : CNMSerializable(0x656f, 1, format), m_nEventId(eventId), m_n14(0), m_n18(1),
      m_n1c(n1c), m_n20(0), m_n24(n24) {}

// MS2-FUNCTIONAL 0x1415b1ed0: frames event encoding.
// @0x1415b1ed0
unsigned int CNMEvent::EncodeFramed(CNMStream* stream)
{
    unsigned char storage[0x18];
    FUN_14156bcb0(storage, stream, this);
    auto result = Encode(reinterpret_cast<CNMEncoder*>(storage), stream);
    FUN_14156bd50(storage);
    return result;
}

// MS2-FUNCTIONAL 0x1415b1f30: dispatches event encoding by format.
// @0x1415b1f30
unsigned int CNMEvent::EncodeDispatch(CNMEncoder* encoder, CNMStream* stream)
{
    return m_bFormat == 1 ? Encode(encoder, stream) : EncodeFramed(stream);
}

// MS2-FUNCTIONAL 0x1415b1f90: writes the base event terminator.
// @0x1415b1f90
unsigned int CNMEvent::Encode(CNMEncoder* encoder, CNMStream*)
{
    FUN_1415f9990(encoder);
    return 1;
}

// MS2-FUNCTIONAL 0x1415b1fc0: decodes a framed event.
// @0x1415b1fc0
unsigned int CNMEvent::DecodeFramed(CNMStream* stream)
{
    unsigned char storage[0x38];
    FUN_14156be10(storage, stream, this);
    unsigned int result = 0;
    if (FUN_1415fb750(storage))
        result = Decode(reinterpret_cast<CNMSerializableDecoder*>(storage), stream);
    FUN_14156bf10(storage);
    return result;
}

// MS2-FUNCTIONAL 0x1415b2050: dispatches event decoding by format.
// @0x1415b2050
unsigned int CNMEvent::DecodeDispatch(CNMSerializableDecoder* decoder, CNMStream* stream)
{
    return FUN_1415fb6d0(decoder) == 2 ? DecodeFramed(stream) : Decode(decoder, stream);
}

// MS2-FUNCTIONAL 0x1415b20b0: consumes the base event payload.
// @0x1415b20b0
unsigned int CNMEvent::Decode(CNMSerializableDecoder* decoder, CNMStream*)
{
    return FUN_1415fb750(decoder);
}

// MS2-FUNCTIONAL 0x1415b20e0: initializes an empty messenger reply event.
// @0x1415b20e0
CNMMessengerReplyEvent::CNMMessengerReplyEvent() : CNMEvent(0x1001, 1, 0, 0), m_28(0), m_2c(0) {}

// MS2-FUNCTIONAL 0x1415b2140: initializes a messenger reply event with its result.
// @0x1415b2140
CNMMessengerReplyEvent::CNMMessengerReplyEvent(int reply) : CNMEvent(0x1001, 1, 0, 0), m_28(reply), m_2c(0) {}

// MS2-FUNCTIONAL 0x1415b21a0: frames messenger reply encoding.
// @0x1415b21a0
unsigned int CNMMessengerReplyEvent::EncodeFramed(CNMStream* stream)
{
    unsigned char storage[0x18];
    FUN_14156bcb0(storage, stream, this);
    auto result = Encode(reinterpret_cast<CNMEncoder*>(storage), stream);
    FUN_14156bd50(storage);
    return result;
}

// MS2-FUNCTIONAL 0x1415b2200: dispatches messenger reply encoding by format.
// @0x1415b2200
unsigned int CNMMessengerReplyEvent::EncodeDispatch(CNMEncoder* encoder, CNMStream* stream)
{
    return m_bFormat == 1 ? Encode(encoder, stream) : EncodeFramed(stream);
}

// MS2-FUNCTIONAL 0x1415b2260: serializes the base event and reply code.
// @0x1415b2260
unsigned int CNMMessengerReplyEvent::Encode(CNMEncoder* encoder, CNMStream* stream)
{
    CNMEvent::EncodeDispatch(encoder, stream);
    if (FUN_1415fb700(this))
        FUN_14156ac20(encoder, static_cast<unsigned int>(m_28));
    FUN_1415f9990(encoder);
    return 1;
}

// MS2-FUNCTIONAL 0x1415b22c0: decodes a framed messenger reply event.
// @0x1415b22c0
unsigned int CNMMessengerReplyEvent::DecodeFramed(CNMStream* stream)
{
    unsigned char storage[0x38];
    FUN_14156be10(storage, stream, this);
    unsigned int result = 0;
    if (FUN_1415fb750(storage))
        result = Decode(reinterpret_cast<CNMSerializableDecoder*>(storage), stream);
    FUN_14156bf10(storage);
    return result;
}

// MS2-FUNCTIONAL 0x1415b2350: dispatches messenger reply decoding by format.
// @0x1415b2350
unsigned int CNMMessengerReplyEvent::DecodeDispatch(CNMSerializableDecoder* decoder, CNMStream* stream)
{
    return FUN_1415fb6d0(decoder) == 2 ? DecodeFramed(stream) : Decode(decoder, stream);
}

// MS2-FUNCTIONAL 0x1415b23b0: restores the reply code after the base event.
// @0x1415b23b0
unsigned int CNMMessengerReplyEvent::Decode(CNMSerializableDecoder* decoder, CNMStream* stream)
{
    CNMEvent::DecodeDispatch(decoder, stream);
    if (FUN_1415fb700(this)) {
        void** vtable = *reinterpret_cast<void***>(decoder);
        using Read = unsigned int(__fastcall*)(void*);
        m_28 = static_cast<int>(reinterpret_cast<Read>(vtable[3])(decoder));
    }
    return FUN_1415fb750(decoder);
}

// MS2-PIN: ??0CNMMessengerReplyEvent@@QEAA@XZ 0x1415b20e0 ; constructor body for the default reply event
