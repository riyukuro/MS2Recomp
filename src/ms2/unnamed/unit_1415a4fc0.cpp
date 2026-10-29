// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// MS2-UNIT: unit_1415a4fc0
// MS2-RANGE: 0x1415a4fc0-0x1415a5310 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmobjects.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/placeholder/nmencoder.h"
#include "ms2/ms2recover.h"

extern void FUN_14156bcb0(void*, void*, void*);
extern void FUN_14156bd50(void*);
extern void FUN_14156be10(void*, void*, void*);
extern void FUN_14156bf10(void*);
extern int FUN_1415fb700(void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(CNMSerializableDecoder*);
extern void FUN_14156ac20(void*, unsigned int);
extern void FUN_1415f9990(void*);

// @0x1415a4fc0
// MS2-FUNCTIONAL: initializes request 0x110d and assigns its recovered default sentinel.
CNMLoginMessengerFunc::CNMLoginMessengerFunc()
    : CNMFunc(0x110d, 1, 0, 0), m_30(static_cast<int>(0x80000000u)), m_34(0)
{
}

// @0x1415a5020
// MS2-FUNCTIONAL: initializes request 0x110d with the supplied status value.
CNMLoginMessengerFunc::CNMLoginMessengerFunc(int value)
    : CNMFunc(0x110d, 1, 0, 0), m_30(value), m_34(0)
{
}

// @0x1415a5080
// MS2-FUNCTIONAL: sets up a framed encoder then delegates to the request encoder.
unsigned int CNMLoginMessengerFunc::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMLoginMessengerFunc::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}

// @0x1415a50e0
// MS2-FUNCTIONAL: dispatches between direct and framed encoding by request format.
unsigned int CNMLoginMessengerFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMLoginMessengerFunc::Encode(pEncoder, pStream);
    return CNMLoginMessengerFunc::EncodeFramed(pStream);
}

// @0x1415a5140
// MS2-FUNCTIONAL: writes the single status value when the request is valid.
unsigned int CNMLoginMessengerFunc::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMFunc::EncodeDispatch(pEncoder, pStream);
    if (FUN_1415fb700(this) != 0)
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_30));
    FUN_1415f9990(pEncoder);
    return 1;
}

// @0x1415a51b0
// MS2-FUNCTIONAL: initializes the framed decoder and checks its validity before decoding.
unsigned int CNMLoginMessengerFunc::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMLoginMessengerFunc::Decode(&decoder, pStream);
}

// @0x1415a5240
// MS2-FUNCTIONAL: dispatches decoding according to decoder format.
unsigned int CNMLoginMessengerFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMLoginMessengerFunc::DecodeFramed(pStream);
    return CNMLoginMessengerFunc::Decode(pDecoder, pStream);
}

// @0x1415a52a0
// MS2-FUNCTIONAL: restores the status value when the response is valid.
unsigned int CNMLoginMessengerFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    if (FUN_1415fb700(this) != 0)
    {
        void** vftable = *reinterpret_cast<void***>(pDecoder);
        using ReadU32 = unsigned int(__fastcall*)(void*);
        m_30 = static_cast<int>(reinterpret_cast<ReadU32>(vftable[3])(pDecoder));
    }
    return static_cast<unsigned int>(FUN_1415fb750(pDecoder));
}

// MS2-PIN: ??0CNMLoginMessengerFunc@@QEAA@XZ 0x1415a4fc0
