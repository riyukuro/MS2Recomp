// MS2-UNIT: unit_1415b3d00
// MS2-RANGE: 0x1415b3d00-0x1415b4030 .text$mn
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
extern void FUN_14156ac20(void*, unsigned int);
extern unsigned int FUN_1415f9990(void*);
extern int FUN_1415fb6d0(CNMSerializableDecoder*);
extern int FUN_1415fb750(void*);

// MS2-FUNCTIONAL 0x1415b3d00: initializes the default refresh-message event.
// @0x1415b3d00
CNMRefreshMessageEvent::CNMRefreshMessageEvent()
    : CNMEvent(0x1009, 1, 0, 0), m_28(1), m_2c(0) {}

// MS2-FUNCTIONAL 0x1415b3d60: initializes the refresh-message event value.
// @0x1415b3d60
CNMRefreshMessageEvent::CNMRefreshMessageEvent(int message)
    : CNMEvent(0x1009, 1, 0, 0), m_28(message), m_2c(0) {}

// MS2-FUNCTIONAL 0x1415b3dc0: frames event encoding.
// @0x1415b3dc0
unsigned int CNMRefreshMessageEvent::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMRefreshMessageEvent::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}

// MS2-FUNCTIONAL 0x1415b3e20: dispatches encoding by event format.
// @0x1415b3e20
unsigned int CNMRefreshMessageEvent::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMRefreshMessageEvent::Encode(pEncoder, pStream);
    return CNMRefreshMessageEvent::EncodeFramed(pStream);
}

// MS2-FUNCTIONAL 0x1415b3e80: serializes the refresh-message value.
// @0x1415b3e80
unsigned int CNMRefreshMessageEvent::Encode(CNMEncoder* encoder, CNMStream* stream)
{
    CNMEvent::EncodeDispatch(encoder, stream);
    FUN_14156ac20(encoder, static_cast<unsigned int>(m_28));
    FUN_1415f9990(encoder);
    return 1;
}

// MS2-FUNCTIONAL 0x1415b3ee0: decodes a framed event.
// @0x1415b3ee0
unsigned int CNMRefreshMessageEvent::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMRefreshMessageEvent::Decode(&decoder, pStream);
}

// MS2-FUNCTIONAL 0x1415b3f70: dispatches decoding by event format.
// @0x1415b3f70
unsigned int CNMRefreshMessageEvent::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMRefreshMessageEvent::DecodeFramed(pStream);
    return CNMRefreshMessageEvent::Decode(pDecoder, pStream);
}

// MS2-FUNCTIONAL 0x1415b3fd0: restores the refresh-message value.
// @0x1415b3fd0
unsigned int CNMRefreshMessageEvent::Decode(CNMSerializableDecoder* decoder, CNMStream* stream)
{
    CNMEvent::DecodeDispatch(decoder, stream);
    void** vtable = *reinterpret_cast<void***>(decoder);
    using Read = unsigned int(__fastcall*)(void*);
    m_28 = static_cast<int>(reinterpret_cast<Read>(vtable[3])(decoder));
    return FUN_1415fb750(decoder);
}

// MS2-PIN: ??0CNMRefreshMessageEvent@@QEAA@XZ 0x1415b3d00 ; constructor body for the default refresh message
