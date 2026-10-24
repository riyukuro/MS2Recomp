// MS2-UNIT: unit_1415b3520
// MS2-RANGE: 0x1415b3520-0x1415b38a0 .text$mn
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
extern void FUN_1415f1660(void*, const void*);
extern unsigned int FUN_1415f9990(void*);
extern int FUN_1415fb6d0(void*);
extern int FUN_1415fb750(void*);

// MS2-FUNCTIONAL 0x1415b3520: constructs the event and its message payload.
// @0x1415b3520
CNMCustomMessageEvent::CNMCustomMessageEvent() : CNMEvent(0x1007, 1, 0, 0), m_28() {}

// MS2-FUNCTIONAL 0x1415b3590: copies the supplied serializable message payload.
// @0x1415b3590
CNMCustomMessageEvent::CNMCustomMessageEvent(const CNMMessageData& message)
    : CNMEvent(0x1007, 1, 0, 0), m_28()
{
    FUN_1415f1660(&m_28, &message);
}

// MS2-FUNCTIONAL 0x1415b3610: frames event encoding.
// @0x1415b3610
unsigned int CNMCustomMessageEvent::EncodeFramed(CNMStream* stream)
{
    unsigned char storage[0x18];
    FUN_14156bcb0(storage, stream, this);
    auto result = Encode(reinterpret_cast<CNMEncoder*>(storage), stream);
    FUN_14156bd50(storage);
    return result;
}

// MS2-FUNCTIONAL 0x1415b3670: dispatches encoding by event format.
// @0x1415b3670
unsigned int CNMCustomMessageEvent::EncodeDispatch(CNMEncoder* encoder, CNMStream* stream)
{
    return m_bFormat == 1 ? Encode(encoder, stream) : EncodeFramed(stream);
}

// MS2-FUNCTIONAL 0x1415b36d0: serializes the embedded message payload.
// @0x1415b36d0
unsigned int CNMCustomMessageEvent::Encode(CNMEncoder* encoder, CNMStream* stream)
{
    CNMEvent::EncodeDispatch(encoder, stream);
    m_28.EncodeFramed(stream);
    FUN_1415f9990(encoder);
    return 1;
}

// MS2-FUNCTIONAL 0x1415b3740: decodes a framed event.
// @0x1415b3740
unsigned int CNMCustomMessageEvent::DecodeFramed(CNMStream* stream)
{
    unsigned char storage[0x38];
    FUN_14156be10(storage, stream, this);
    unsigned int result = 0;
    if (FUN_1415fb750(storage))
        result = Decode(reinterpret_cast<CNMSerializableDecoder*>(storage), stream);
    FUN_14156bf10(storage);
    return result;
}

// MS2-FUNCTIONAL 0x1415b37d0: dispatches decoding by event format.
// @0x1415b37d0
unsigned int CNMCustomMessageEvent::DecodeDispatch(CNMSerializableDecoder* decoder, CNMStream* stream)
{
    return FUN_1415fb6d0(decoder) == 2 ? DecodeFramed(stream) : Decode(decoder, stream);
}

// MS2-FUNCTIONAL 0x1415b3830: restores the embedded message payload.
// @0x1415b3830
unsigned int CNMCustomMessageEvent::Decode(CNMSerializableDecoder* decoder, CNMStream* stream)
{
    CNMEvent::DecodeDispatch(decoder, stream);
    m_28.DecodeFramed(stream);
    return FUN_1415fb750(decoder);
}
