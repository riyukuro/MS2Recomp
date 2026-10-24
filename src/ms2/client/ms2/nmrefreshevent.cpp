// Recovered Nexon Messenger refresh event.
// MS2-UNIT: ?\nmrefreshevent.cpp
// MS2-RANGE: 0x1415b2740-0x1415b2a70 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmfunc.h"
#include "ms2/placeholder/nmobjects.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/ms2recover.h"

extern void FUN_14156bcb0(void*, void*, void*);
extern void FUN_14156be10(void*, void*, void*);
extern void FUN_14156bd50(void*);
extern void FUN_14156bf10(void*);
extern void FUN_14156ac20(void*, unsigned int);
extern void FUN_1415f9990(void*);
extern int FUN_1415fb6d0(void*);
extern int FUN_1415fb750(void*);

// MS2-FUNCTIONAL: initializes the default refresh event value.
// @0x1415b2740
CNMRefreshEvent::CNMRefreshEvent()
    : CNMEvent(0x1003, 1, 0, 0), m_28(0)
{
}

// MS2-FUNCTIONAL: initializes the refresh event with its supplied value.
// @0x1415b27a0
CNMRefreshEvent::CNMRefreshEvent(int value)
    : CNMEvent(0x1003, 1, 0, 0), m_28(value)
{
}

// MS2-FUNCTIONAL: frames refresh event encoding.
// @0x1415b2800
unsigned int CNMRefreshEvent::EncodeFramed(CNMStream* pStream)
{
    alignas(8) unsigned char encoder[0x18];
    FUN_14156bcb0(encoder, pStream, this);
    const unsigned int result = Encode(reinterpret_cast<CNMEncoder*>(encoder), pStream);
    FUN_14156bd50(encoder);
    return result;
}

// MS2-FUNCTIONAL: selects direct or framed event encoding.
// @0x1415b2860
unsigned int CNMRefreshEvent::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    return m_bFormat == 1 ? Encode(pEncoder, pStream) : EncodeFramed(pStream);
}

// MS2-FUNCTIONAL: serializes the refresh event value.
// @0x1415b28c0
unsigned int CNMRefreshEvent::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMEvent::EncodeDispatch(pEncoder, pStream);
    FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_28));
    FUN_1415f9990(pEncoder);
    return 1;
}

// MS2-FUNCTIONAL: validates a framed refresh event before decoding it.
// @0x1415b2920
unsigned int CNMRefreshEvent::DecodeFramed(CNMStream* pStream)
{
    alignas(8) unsigned char decoder[0x38];
    FUN_14156be10(decoder, pStream, this);
    unsigned int result = 0;
    if (FUN_1415fb750(decoder) != 0)
        result = Decode(reinterpret_cast<CNMSerializableDecoder*>(decoder), pStream);
    FUN_14156bf10(decoder);
    return result;
}

// MS2-FUNCTIONAL: dispatches version two refresh events through framed decoding.
// @0x1415b29b0
unsigned int CNMRefreshEvent::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    return FUN_1415fb6d0(pDecoder) == 2 ? DecodeFramed(pStream) : Decode(pDecoder, pStream);
}

// MS2-FUNCTIONAL: restores the refresh event value from the decoder.
// @0x1415b2a10
unsigned int CNMRefreshEvent::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMEvent::DecodeDispatch(pDecoder, pStream);
    void** vftable = *reinterpret_cast<void***>(pDecoder);
    using ReadU32 = unsigned int(__fastcall*)(void*);
    m_28 = static_cast<int>(reinterpret_cast<ReadU32>(vftable[3])(pDecoder));
    return static_cast<unsigned int>(FUN_1415fb750(pDecoder));
}

// MS2-PIN: ??0CNMRefreshEvent@@QEAA@XZ 0x1415b2740
// MS2-PIN: ??0CNMRefreshEvent@@QEAA@H@Z 0x1415b27a0
