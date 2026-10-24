// MS2-UNIT: unit_1415b38a0
// MS2-RANGE: 0x1415b38a0-0x1415b3d00 .text$mn
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
extern void FUN_1415f1be0(void*, const void*);
extern void FUN_1415f1930(void*, const void*);
extern unsigned int FUN_1415f9990(void*);
extern int FUN_1415fb6d0(void*);
extern int FUN_1415fb750(void*);

// MS2-FUNCTIONAL 0x1415b38a0: constructs the event and its note payload.
// @0x1415b38a0
CNMNoteInstantMsgEvent::CNMNoteInstantMsgEvent()
    : CNMEvent(0x1008, 1, 0, 0), m_28() {}

// MS2-FUNCTIONAL 0x1415b3910: copies the supplied note into the event payload.
// @0x1415b3910
CNMNoteInstantMsgEvent::CNMNoteInstantMsgEvent(const CNMNoteInfo& note)
    : CNMEvent(0x1008, 1, 0, 0), m_28()
{
    FUN_1415f1be0(&m_28, &note);
}

// MS2-FUNCTIONAL 0x1415b3990: copies a by-value note payload into the event.
// @0x1415b3990
CNMNoteInstantMsgEvent::CNMNoteInstantMsgEvent(CNMNoteInfo note)
    : CNMEvent(0x1008, 1, 0, 0), m_28()
{
    FUN_1415f1930(&m_28, &note);
}

// MS2-FUNCTIONAL 0x1415b3a70: frames event encoding.
// @0x1415b3a70
unsigned int CNMNoteInstantMsgEvent::EncodeFramed(CNMStream* stream)
{
    unsigned char storage[0x18];
    FUN_14156bcb0(storage, stream, this);
    auto result = Encode(reinterpret_cast<CNMEncoder*>(storage), stream);
    FUN_14156bd50(storage);
    return result;
}

// MS2-FUNCTIONAL 0x1415b3ad0: dispatches encoding by event format.
// @0x1415b3ad0
unsigned int CNMNoteInstantMsgEvent::EncodeDispatch(CNMEncoder* encoder, CNMStream* stream)
{
    return m_bFormat == 1 ? Encode(encoder, stream) : EncodeFramed(stream);
}

// MS2-FUNCTIONAL 0x1415b3b30: serializes the nested note payload.
// @0x1415b3b30
unsigned int CNMNoteInstantMsgEvent::Encode(CNMEncoder* encoder, CNMStream* stream)
{
    CNMEvent::EncodeDispatch(encoder, stream);
    m_28.EncodeFramed(stream);
    FUN_1415f9990(encoder);
    return 1;
}

// MS2-FUNCTIONAL 0x1415b3ba0: decodes a framed event.
// @0x1415b3ba0
unsigned int CNMNoteInstantMsgEvent::DecodeFramed(CNMStream* stream)
{
    unsigned char storage[0x38];
    FUN_14156be10(storage, stream, this);
    unsigned int result = 0;
    if (FUN_1415fb750(storage))
        result = Decode(reinterpret_cast<CNMSerializableDecoder*>(storage), stream);
    FUN_14156bf10(storage);
    return result;
}

// MS2-FUNCTIONAL 0x1415b3c30: dispatches decoding by event format.
// @0x1415b3c30
unsigned int CNMNoteInstantMsgEvent::DecodeDispatch(CNMSerializableDecoder* decoder, CNMStream* stream)
{
    return FUN_1415fb6d0(decoder) == 2 ? DecodeFramed(stream) : Decode(decoder, stream);
}

// MS2-FUNCTIONAL 0x1415b3c90: restores the nested note payload.
// @0x1415b3c90
unsigned int CNMNoteInstantMsgEvent::Decode(CNMSerializableDecoder* decoder, CNMStream* stream)
{
    CNMEvent::DecodeDispatch(decoder, stream);
    m_28.DecodeFramed(stream);
    return FUN_1415fb750(decoder);
}
