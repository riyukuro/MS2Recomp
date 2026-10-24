// MS2-UNIT: unit_1415b5f40
// MS2-RANGE: 0x1415b5f40-0x1415b6270 .text$mn
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
extern int FUN_1415fb750(void*);

// MS2-FUNCTIONAL 0x1415b5f40: initializes the auth-connection-closed event with reason 1.
CNMAuthConnectionClosedEvent::CNMAuthConnectionClosedEvent()
    : CNMEvent(0x1017, 1, 0, 0), m_28(1), m_2c(0) {}

// MS2-FUNCTIONAL 0x1415b5fa0: initializes the event with the supplied close reason.
// @0x1415b5fa0
CNMAuthConnectionClosedEvent::CNMAuthConnectionClosedEvent(int reason)
    : CNMEvent(0x1017, 1, 0, 0), m_28(reason), m_2c(0) {}

// MS2-FUNCTIONAL 0x1415b6000: frames serialization through a temporary stream adapter.
// @0x1415b6000
unsigned int CNMAuthConnectionClosedEvent::EncodeFramed(CNMStream* pStream)
{
    unsigned char storage[0x18];
    FUN_14156bcb0(storage, pStream, this);
    const unsigned int result = Encode(reinterpret_cast<CNMEncoder*>(storage), pStream);
    FUN_14156bd50(storage);
    return result;
}

// MS2-FUNCTIONAL 0x1415b6060: selects direct or framed event encoding.
// @0x1415b6060
unsigned int CNMAuthConnectionClosedEvent::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    return m_bFormat == 1 ? Encode(pEncoder, pStream) : EncodeFramed(pStream);
}

// MS2-FUNCTIONAL 0x1415b60c0: serializes the base event and close reason.
// @0x1415b60c0
unsigned int CNMAuthConnectionClosedEvent::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMEvent::EncodeDispatch(pEncoder, pStream);
    FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_28));
    FUN_1415f9990(pEncoder);
    return 1;
}

// MS2-FUNCTIONAL 0x1415b6120: creates and validates a framed decoder before decoding.
// @0x1415b6120
unsigned int CNMAuthConnectionClosedEvent::DecodeFramed(CNMStream* pStream)
{
    unsigned char storage[0x38];
    FUN_14156be10(storage, pStream, this);
    unsigned int result = 0;
    if (FUN_1415fb750(storage))
        result = Decode(reinterpret_cast<CNMSerializableDecoder*>(storage), pStream);
    FUN_14156bf10(storage);
    return result;
}

// MS2-FUNCTIONAL 0x1415b61b0: chooses framed decode when the format value is 2.
// @0x1415b61b0
unsigned int CNMAuthConnectionClosedEvent::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    return FUN_1415fb6d0(pDecoder) == 2 ? DecodeFramed(pStream) : Decode(pDecoder, pStream);
}

// MS2-FUNCTIONAL 0x1415b6210: restores the close reason and validates the decoder.
// @0x1415b6210
unsigned int CNMAuthConnectionClosedEvent::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMEvent::DecodeDispatch(pDecoder, pStream);
    m_28 = static_cast<int>(pDecoder->ReadU32());
    return static_cast<unsigned int>(FUN_1415fb750(pDecoder));
}

// MS2-PIN: ??0CNMAuthConnectionClosedEvent@@QEAA@XZ 0x1415b5f40 ; default constructor
// MS2-PIN: ??0CNMAuthConnectionClosedEvent@@QEAA@H@Z 0x1415b5fa0 ; constructor with close reason
