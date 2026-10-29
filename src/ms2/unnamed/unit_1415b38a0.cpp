// MS2-UNIT: unit_1415b38a0
// MS2-RANGE: 0x1415b38a0-0x1415b3d00 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/placeholder/nmobjects.h"
#include "ms2/placeholder/nmfunc.h"
#include "ms2/placeholder/nmencoder.h"
#include "ms2/ms2recover.h"

extern void FUN_14156bcb0(void*, void*, void*);
extern void FUN_14156bd50(void*);
extern void FUN_14156be10(void*, void*, void*);
extern void FUN_14156bf10(void*);
extern void FUN_1415f1be0(void*, const void*);
extern void FUN_1415f1930(void*, const void*);
extern unsigned int FUN_1415f9990(void*);
extern int FUN_1415fb6d0(CNMSerializableDecoder*);
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
unsigned int CNMNoteInstantMsgEvent::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMNoteInstantMsgEvent::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}

// MS2-FUNCTIONAL 0x1415b3ad0: dispatches encoding by event format.
// @0x1415b3ad0
unsigned int CNMNoteInstantMsgEvent::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMNoteInstantMsgEvent::Encode(pEncoder, pStream);
    return CNMNoteInstantMsgEvent::EncodeFramed(pStream);
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
unsigned int CNMNoteInstantMsgEvent::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMNoteInstantMsgEvent::Decode(&decoder, pStream);
}

// MS2-FUNCTIONAL 0x1415b3c30: dispatches decoding by event format.
// @0x1415b3c30
unsigned int CNMNoteInstantMsgEvent::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMNoteInstantMsgEvent::DecodeFramed(pStream);
    return CNMNoteInstantMsgEvent::Decode(pDecoder, pStream);
}

// MS2-FUNCTIONAL 0x1415b3c90: restores the nested note payload.
// @0x1415b3c90
unsigned int CNMNoteInstantMsgEvent::Decode(CNMSerializableDecoder* decoder, CNMStream* stream)
{
    CNMEvent::DecodeDispatch(decoder, stream);
    m_28.DecodeFramed(stream);
    return FUN_1415fb750(decoder);
}
