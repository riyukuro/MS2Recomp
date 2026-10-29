// MS2-UNIT: unit_1415b4030
// MS2-RANGE: 0x1415b4030-0x1415b4360 .text$mn
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

// MS2-FUNCTIONAL 0x1415b4030: initializes an empty find-user reply event.
// @0x1415b4030
CNMFindUserReplyEvent::CNMFindUserReplyEvent()
    : CNMEvent(0x100a, 1, 0, 0), m_28(0), m_2c(0) {}

// MS2-FUNCTIONAL 0x1415b4090: initializes the find-user result code.
// @0x1415b4090
CNMFindUserReplyEvent::CNMFindUserReplyEvent(int result)
    : CNMEvent(0x100a, 1, 0, 0), m_28(result), m_2c(0) {}

// MS2-FUNCTIONAL 0x1415b40f0: frames event encoding.
// @0x1415b40f0
unsigned int CNMFindUserReplyEvent::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMFindUserReplyEvent::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}

// MS2-FUNCTIONAL 0x1415b4150: dispatches encoding by event format.
// @0x1415b4150
unsigned int CNMFindUserReplyEvent::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMFindUserReplyEvent::Encode(pEncoder, pStream);
    return CNMFindUserReplyEvent::EncodeFramed(pStream);
}

// MS2-FUNCTIONAL 0x1415b41b0: serializes the find-user result code.
// @0x1415b41b0
unsigned int CNMFindUserReplyEvent::Encode(CNMEncoder* encoder, CNMStream* stream)
{
    CNMEvent::EncodeDispatch(encoder, stream);
    FUN_14156ac20(encoder, static_cast<unsigned int>(m_28));
    FUN_1415f9990(encoder);
    return 1;
}

// MS2-FUNCTIONAL 0x1415b4210: decodes a framed event.
// @0x1415b4210
unsigned int CNMFindUserReplyEvent::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMFindUserReplyEvent::Decode(&decoder, pStream);
}

// MS2-FUNCTIONAL 0x1415b42a0: dispatches decoding by event format.
// @0x1415b42a0
unsigned int CNMFindUserReplyEvent::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMFindUserReplyEvent::DecodeFramed(pStream);
    return CNMFindUserReplyEvent::Decode(pDecoder, pStream);
}

// MS2-FUNCTIONAL 0x1415b4300: restores the find-user result code.
// @0x1415b4300
unsigned int CNMFindUserReplyEvent::Decode(CNMSerializableDecoder* decoder, CNMStream* stream)
{
    CNMEvent::DecodeDispatch(decoder, stream);
    void** vtable = *reinterpret_cast<void***>(decoder);
    using Read = unsigned int(__fastcall*)(void*);
    m_28 = static_cast<int>(reinterpret_cast<Read>(vtable[3])(decoder));
    return FUN_1415fb750(decoder);
}

// MS2-PIN: ??0CNMFindUserReplyEvent@@QEAA@XZ 0x1415b4030 ; constructor body for an empty reply
