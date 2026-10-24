// Recovered Nexon Messenger user information event.
// MS2-UNIT: ?\nmuserinfoevent.cpp
// MS2-RANGE: 0x1415b49d0-0x1415b4d50 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmfunc.h"
#include "ms2/placeholder/nmobjects.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/ms2recover.h"

extern CNMSerializable* FUN_1415f1f10(CNMSerializable*, long long);
extern void FUN_14156bcb0(void*, void*, void*);
extern void FUN_14156be10(void*, void*, void*);
extern void FUN_14156bd50(void*);
extern void FUN_14156bf10(void*);
extern void FUN_1415f9990(void*);
extern int FUN_1415fb6d0(void*);
extern int FUN_1415fb750(void*);

// MS2-FUNCTIONAL: initializes the user information event payload.
// @0x1415b49d0
CNMUserInfoEvent::CNMUserInfoEvent()
    : CNMEvent(0x100c, 1, 0, 0), m_28()
{
}

// MS2-FUNCTIONAL: copies supplied user information into the event payload.
// @0x1415b4a40
CNMUserInfoEvent::CNMUserInfoEvent(const CNMRealUserInfo& data)
    : CNMEvent(0x100c, 1, 0, 0), m_28()
{
    FUN_1415f1f10(reinterpret_cast<CNMSerializable*>(&m_28), reinterpret_cast<long long>(const_cast<CNMRealUserInfo*>(&data)));
}

// MS2-FUNCTIONAL: frames event encoding.
// @0x1415b4ac0
unsigned int CNMUserInfoEvent::EncodeFramed(CNMStream* pStream)
{
    alignas(8) unsigned char encoder[0x18];
    FUN_14156bcb0(encoder, pStream, this);
    const unsigned int result = Encode(reinterpret_cast<CNMEncoder*>(encoder), pStream);
    FUN_14156bd50(encoder);
    return result;
}

// MS2-FUNCTIONAL: chooses direct or framed encoding based on format.
// @0x1415b4b20
unsigned int CNMUserInfoEvent::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        Encode(pEncoder, pStream);
    else
        EncodeFramed(pStream);
    return 0;
}

// MS2-FUNCTIONAL: serializes the embedded real user information payload.
// @0x1415b4b80
unsigned int CNMUserInfoEvent::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMEvent::EncodeDispatch(pEncoder, pStream);
    m_28.EncodeFramed(pStream);
    FUN_1415f9990(pEncoder);
    return 1;
}

// MS2-FUNCTIONAL: validates framed input before decoding user information.
// @0x1415b4bf0
unsigned int CNMUserInfoEvent::DecodeFramed(CNMStream* pStream)
{
    alignas(8) unsigned char decoder[0x38];
    FUN_14156be10(decoder, pStream, this);
    unsigned int result = 0;
    if (FUN_1415fb750(decoder) != 0)
        result = Decode(reinterpret_cast<CNMSerializableDecoder*>(decoder), pStream);
    FUN_14156bf10(decoder);
    return result;
}

// MS2-FUNCTIONAL: routes version two events through framed decoding.
// @0x1415b4c80
unsigned int CNMUserInfoEvent::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        DecodeFramed(pStream);
    else
        Decode(pDecoder, pStream);
    return 0;
}

// MS2-FUNCTIONAL: decodes the event header and embedded user information.
// @0x1415b4ce0
unsigned int CNMUserInfoEvent::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMEvent::DecodeDispatch(pDecoder, pStream);
    m_28.DecodeFramed(pStream);
    FUN_1415fb750(pDecoder);
    return 1;
}

// MS2-PIN: ??0CNMUserInfoEvent@@QEAA@XZ 0x1415b49d0
