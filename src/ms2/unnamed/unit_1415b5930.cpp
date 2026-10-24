// MS2-UNIT: unit_1415b5930
// MS2-RANGE: 0x1415b5930-0x1415b5bc0 .text$mn
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
extern unsigned int FUN_1415f9990(void*);
extern int FUN_1415fb6d0(void*);
extern int FUN_1415fb750(void*);

// MS2-FUNCTIONAL 0x1415b5930: constructs an event that signals a rejected-user-list update.
CNMRejectedUserListChangedEvent::CNMRejectedUserListChangedEvent()
    : CNMEvent(0x1015, 1, 0, 0)
{
}

// MS2-FUNCTIONAL 0x1415b5980: frames the empty event encoding.
// @0x1415b5980
unsigned int CNMRejectedUserListChangedEvent::EncodeFramed(CNMStream* pStream)
{
    unsigned char storage[0x18];
    FUN_14156bcb0(storage, pStream, this);
    const unsigned int result = Encode(reinterpret_cast<CNMEncoder*>(storage), pStream);
    FUN_14156bd50(storage);
    return result;
}

// MS2-FUNCTIONAL 0x1415b59e0: selects direct or framed encoding by event format.
// @0x1415b59e0
unsigned int CNMRejectedUserListChangedEvent::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    return m_bFormat == 1 ? Encode(pEncoder, pStream) : EncodeFramed(pStream);
}

// MS2-FUNCTIONAL 0x1415b5a40: serializes the base event and finishes the empty payload.
// @0x1415b5a40
unsigned int CNMRejectedUserListChangedEvent::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMEvent::EncodeDispatch(pEncoder, pStream);
    FUN_1415f9990(pEncoder);
    return 1;
}

// MS2-FUNCTIONAL 0x1415b5a90: constructs and validates the framed decoder.
// @0x1415b5a90
unsigned int CNMRejectedUserListChangedEvent::DecodeFramed(CNMStream* pStream)
{
    unsigned char storage[0x38];
    FUN_14156be10(storage, pStream, this);
    unsigned int result = 0;
    if (FUN_1415fb750(storage))
        result = Decode(reinterpret_cast<CNMSerializableDecoder*>(storage), pStream);
    FUN_14156bf10(storage);
    return result;
}

// MS2-FUNCTIONAL 0x1415b5b20: routes format-2 input through framed decoding.
// @0x1415b5b20
unsigned int CNMRejectedUserListChangedEvent::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    return FUN_1415fb6d0(pDecoder) == 2 ? DecodeFramed(pStream) : Decode(pDecoder, pStream);
}

// MS2-FUNCTIONAL 0x1415b5b80: decodes base event fields and validates the empty payload.
// @0x1415b5b80
unsigned int CNMRejectedUserListChangedEvent::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMEvent::DecodeDispatch(pDecoder, pStream);
    return static_cast<unsigned int>(FUN_1415fb750(pDecoder));
}

// MS2-PIN: ??0CNMRejectedUserListChangedEvent@@QEAA@XZ 0x1415b5930 ; default constructor
