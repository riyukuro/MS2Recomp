// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// MS2-UNIT: unit_1415a5310
// MS2-RANGE: 0x1415a5310-0x1415a55b0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmobjects.h"
#include "ms2/ms2recover.h"

extern void FUN_14156bcb0(void*, void*, void*);
extern void FUN_14156bd50(void*);
extern void FUN_14156be10(void*, void*, void*);
extern void FUN_14156bf10(void*);
extern int FUN_1415fb700(void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(void*);
extern void FUN_1415f9990(void*);

// @0x1415a5310
// MS2-FUNCTIONAL: initializes the empty 0x110e logout request.
CNMLogoutMessengerFunc::CNMLogoutMessengerFunc()
    : CNMFunc(0x110e, 1, 0, 0)
{
}

// @0x1415a5360
// MS2-FUNCTIONAL: sets up a framed encoder then delegates to the empty request encoder.
unsigned int CNMLogoutMessengerFunc::EncodeFramed(CNMStream* pStream)
{
    alignas(8) unsigned char encoder[0x18];
    FUN_14156bcb0(encoder, pStream, this);
    const unsigned int result = Encode(reinterpret_cast<CNMEncoder*>(encoder), pStream);
    FUN_14156bd50(encoder);
    return result;
}

// @0x1415a53c0
// MS2-FUNCTIONAL: dispatches between direct and framed encoding by request format.
unsigned int CNMLogoutMessengerFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        Encode(pEncoder, pStream);
    else
        EncodeFramed(pStream);
    return 0;
}

// @0x1415a5420
// MS2-FUNCTIONAL: runs base framing setup and finalizes without payload fields.
unsigned int CNMLogoutMessengerFunc::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMFunc::EncodeDispatch(pEncoder, pStream);
    FUN_1415fb700(this);
    FUN_1415f9990(pEncoder);
    return 1;
}

// @0x1415a5470
// MS2-FUNCTIONAL: initializes the framed decoder and checks its validity before decoding.
unsigned int CNMLogoutMessengerFunc::DecodeFramed(CNMStream* pStream)
{
    alignas(8) unsigned char decoder[0x38];
    FUN_14156be10(decoder, pStream, this);
    unsigned int result = 0;
    if (FUN_1415fb750(decoder) != 0)
        result = Decode(reinterpret_cast<CNMSerializableDecoder*>(decoder), pStream);
    FUN_14156bf10(decoder);
    return result;
}

// @0x1415a5500
// MS2-FUNCTIONAL: dispatches decoding according to decoder format.
unsigned int CNMLogoutMessengerFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        DecodeFramed(pStream);
    else
        Decode(pDecoder, pStream);
    return 0;
}

// @0x1415a5560
// MS2-FUNCTIONAL: runs base decoder setup and completes without payload fields.
unsigned int CNMLogoutMessengerFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    FUN_1415fb700(this);
    return static_cast<unsigned int>(FUN_1415fb750(pDecoder));
}

// MS2-PIN: ??0CNMLogoutMessengerFunc@@QEAA@XZ 0x1415a5310
