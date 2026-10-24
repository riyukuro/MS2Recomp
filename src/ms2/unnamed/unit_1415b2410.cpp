// MS2-UNIT: unit_1415b2410
// MS2-RANGE: 0x1415b2410-0x1415b2740 .text$mn
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
extern void FUN_14156ac20(void*, unsigned int);
extern unsigned int FUN_1415f9990(void*);
extern int FUN_1415fb6d0(void*);
extern int FUN_1415fb700(void*);
extern int FUN_1415fb750(void*);

// MS2-FUNCTIONAL 0x1415b2410: initializes an empty message-connection event.
// @0x1415b2410
CNMMsgConnectionClosedEvent::CNMMsgConnectionClosedEvent()
    : CNMEvent(0x1002, 1, 0, 0), m_28(0), m_2c(0) {}

// MS2-FUNCTIONAL 0x1415b2470: initializes the event with its reason code.
// @0x1415b2470
CNMMsgConnectionClosedEvent::CNMMsgConnectionClosedEvent(int reason)
    : CNMEvent(0x1002, 1, 0, 0), m_28(reason), m_2c(0) {}

// MS2-FUNCTIONAL 0x1415b24d0: frames event encoding.
// @0x1415b24d0
unsigned int CNMMsgConnectionClosedEvent::EncodeFramed(CNMStream* stream)
{
    unsigned char storage[0x18];
    FUN_14156bcb0(storage, stream, this);
    auto result = Encode(reinterpret_cast<CNMEncoder*>(storage), stream);
    FUN_14156bd50(storage);
    return result;
}

// MS2-FUNCTIONAL 0x1415b2530: dispatches encoding by the event format.
// @0x1415b2530
unsigned int CNMMsgConnectionClosedEvent::EncodeDispatch(CNMEncoder* encoder, CNMStream* stream)
{
    return m_bFormat == 1 ? Encode(encoder, stream) : EncodeFramed(stream);
}

// MS2-FUNCTIONAL 0x1415b2590: serializes the event and reason code.
// @0x1415b2590
unsigned int CNMMsgConnectionClosedEvent::Encode(CNMEncoder* encoder, CNMStream* stream)
{
    CNMEvent::EncodeDispatch(encoder, stream);
    if (FUN_1415fb700(this))
        FUN_14156ac20(encoder, static_cast<unsigned int>(m_28));
    FUN_1415f9990(encoder);
    return 1;
}

// MS2-FUNCTIONAL 0x1415b25f0: decodes a framed event.
// @0x1415b25f0
unsigned int CNMMsgConnectionClosedEvent::DecodeFramed(CNMStream* stream)
{
    unsigned char storage[0x38];
    FUN_14156be10(storage, stream, this);
    unsigned int result = 0;
    if (FUN_1415fb750(storage))
        result = Decode(reinterpret_cast<CNMSerializableDecoder*>(storage), stream);
    FUN_14156bf10(storage);
    return result;
}

// MS2-FUNCTIONAL 0x1415b2680: dispatches decoding by the event format.
// @0x1415b2680
unsigned int CNMMsgConnectionClosedEvent::DecodeDispatch(CNMSerializableDecoder* decoder, CNMStream* stream)
{
    return FUN_1415fb6d0(decoder) == 2 ? DecodeFramed(stream) : Decode(decoder, stream);
}

// MS2-FUNCTIONAL 0x1415b26e0: restores the base event and reason code.
// @0x1415b26e0
unsigned int CNMMsgConnectionClosedEvent::Decode(CNMSerializableDecoder* decoder, CNMStream* stream)
{
    CNMEvent::DecodeDispatch(decoder, stream);
    if (FUN_1415fb700(this)) {
        void** vtable = *reinterpret_cast<void***>(decoder);
        using Read = unsigned int(__fastcall*)(void*);
        m_28 = static_cast<int>(reinterpret_cast<Read>(vtable[3])(decoder));
    }
    return FUN_1415fb750(decoder);
}

// MS2-PIN: ??0CNMMsgConnectionClosedEvent@@QEAA@XZ 0x1415b2410 ; constructor body for the empty event
