// MS2-UNIT: unit_1415b5bc0
// MS2-RANGE: 0x1415b5bc0-0x1415b5f40 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/placeholder/nmobjects.h"
#include "ms2/placeholder/nmfunc.h"
#include "ms2/placeholder/nmencoder.h"
#include "ms2/ms2recover.h"

extern CNMSerializable* FUN_1415f1760(CNMSerializable*, long long);
extern void FUN_14156bcb0(void*, void*, void*);
extern void FUN_14156bd50(void*);
extern void FUN_14156be10(void*, void*, void*);
extern void FUN_14156bf10(void*);
extern unsigned int FUN_1415f9990(void*);
extern int FUN_1415fb6d0(CNMSerializableDecoder*);
extern int FUN_1415fb750(void*);

// MS2-FUNCTIONAL 0x1415b5bc0: initializes the note-info event and its embedded note record.
CNMNoteInfoEvent::CNMNoteInfoEvent()
    : CNMEvent(0x1016, 1, 0, 0), m_28() {}

// MS2-FUNCTIONAL 0x1415b5c30: copies the note-info record into the event.
// @0x1415b5c30
CNMNoteInfoEvent::CNMNoteInfoEvent(const CNMNoteInfo2& rNoteInfo)
    : CNMEvent(0x1016, 1, 0, 0), m_28()
{
    FUN_1415f1760(reinterpret_cast<CNMSerializable*>(&m_28),
                  reinterpret_cast<long long>(&rNoteInfo));
}

// MS2-FUNCTIONAL 0x1415b5cb0: frames event encoding through a stream adapter.
// @0x1415b5cb0
unsigned int CNMNoteInfoEvent::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMNoteInfoEvent::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}

// MS2-FUNCTIONAL 0x1415b5d10: selects direct or framed encoding by format.
// @0x1415b5d10
unsigned int CNMNoteInfoEvent::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMNoteInfoEvent::Encode(pEncoder, pStream);
    return CNMNoteInfoEvent::EncodeFramed(pStream);
}

// MS2-FUNCTIONAL 0x1415b5d70: serializes the event and its embedded note-info record.
// @0x1415b5d70
unsigned int CNMNoteInfoEvent::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMEvent::EncodeDispatch(pEncoder, pStream);
    m_28.EncodeFramed(pStream);
    FUN_1415f9990(pEncoder);
    return 1;
}

// MS2-FUNCTIONAL 0x1415b5de0: builds and validates a framed decoder before decoding.
// @0x1415b5de0
unsigned int CNMNoteInfoEvent::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMNoteInfoEvent::Decode(&decoder, pStream);
}

// MS2-FUNCTIONAL 0x1415b5e70: dispatches framed or direct decoding.
// @0x1415b5e70
unsigned int CNMNoteInfoEvent::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMNoteInfoEvent::DecodeFramed(pStream);
    return CNMNoteInfoEvent::Decode(pDecoder, pStream);
}

// MS2-FUNCTIONAL 0x1415b5ed0: decodes the base event and its embedded note record.
// @0x1415b5ed0
unsigned int CNMNoteInfoEvent::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMEvent::DecodeDispatch(pDecoder, pStream);
    m_28.DecodeFramed(pStream);
    return static_cast<unsigned int>(FUN_1415fb750(pDecoder));
}

// MS2-PIN: ??0CNMNoteInfoEvent@@QEAA@XZ 0x1415b5bc0 ; default constructor
