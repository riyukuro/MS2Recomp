// MS2-UNIT: unit_1415b55b0
// MS2-RANGE: 0x1415b55b0-0x1415b5930 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/placeholder/nmobjects.h"
#include "ms2/placeholder/nmfunc.h"
#include "ms2/ms2recover.h"

extern CNMSerializable* FUN_1415f06d0(CNMSerializable*, long long);
extern void FUN_14156bcb0(void*, void*, void*);
extern void FUN_14156bd50(void*);
extern void FUN_14156be10(void*, void*, void*);
extern void FUN_14156bf10(void*);
extern unsigned int FUN_1415f9990(void*);
extern int FUN_1415fb6d0(void*);
extern int FUN_1415fb750(void*);

// MS2-FUNCTIONAL 0x1415b55b0: initializes the custom-notify event and its embedded data.
CNMCustomNotifyEvent::CNMCustomNotifyEvent()
    : CNMEvent(0x1014, 1, 0, 0), m_28() {}

// MS2-FUNCTIONAL 0x1415b5620: copies custom-notify data into the event.
// @0x1415b5620
CNMCustomNotifyEvent::CNMCustomNotifyEvent(const CNMCustomNotifyData& rData)
    : CNMEvent(0x1014, 1, 0, 0), m_28()
{
    FUN_1415f06d0(reinterpret_cast<CNMSerializable*>(&m_28),
                  reinterpret_cast<long long>(&rData));
}

// MS2-FUNCTIONAL 0x1415b56a0: encodes the event through a temporary stream adapter.
// @0x1415b56a0
unsigned int CNMCustomNotifyEvent::EncodeFramed(CNMStream* pStream)
{
    unsigned char storage[0x18];
    FUN_14156bcb0(storage, pStream, this);
    const unsigned int result = Encode(reinterpret_cast<CNMEncoder*>(storage), pStream);
    FUN_14156bd50(storage);
    return result;
}

// MS2-FUNCTIONAL 0x1415b5700: chooses direct or framed event encoding.
// @0x1415b5700
unsigned int CNMCustomNotifyEvent::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    return m_bFormat == 1 ? Encode(pEncoder, pStream) : EncodeFramed(pStream);
}

// MS2-FUNCTIONAL 0x1415b5760: serializes the base event and nested custom-notify record.
// @0x1415b5760
unsigned int CNMCustomNotifyEvent::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMEvent::EncodeDispatch(pEncoder, pStream);
    m_28.EncodeFramed(pStream);
    FUN_1415f9990(pEncoder);
    return 1;
}

// MS2-FUNCTIONAL 0x1415b57d0: creates a decoder adapter and validates it before dispatch.
// @0x1415b57d0
unsigned int CNMCustomNotifyEvent::DecodeFramed(CNMStream* pStream)
{
    unsigned char storage[0x38];
    FUN_14156be10(storage, pStream, this);
    unsigned int result = 0;
    if (FUN_1415fb750(storage))
        result = Decode(reinterpret_cast<CNMSerializableDecoder*>(storage), pStream);
    FUN_14156bf10(storage);
    return result;
}

// MS2-FUNCTIONAL 0x1415b5860: dispatches decoding according to the serialized format.
// @0x1415b5860
unsigned int CNMCustomNotifyEvent::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    return FUN_1415fb6d0(pDecoder) == 2 ? DecodeFramed(pStream) : Decode(pDecoder, pStream);
}

// MS2-FUNCTIONAL 0x1415b58c0: decodes the base event and its nested custom-notify record.
// @0x1415b58c0
unsigned int CNMCustomNotifyEvent::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMEvent::DecodeDispatch(pDecoder, pStream);
    m_28.DecodeFramed(pStream);
    return static_cast<unsigned int>(FUN_1415fb750(pDecoder));
}

// MS2-PIN: ??0CNMCustomNotifyEvent@@QEAA@XZ 0x1415b55b0 ; default constructor
