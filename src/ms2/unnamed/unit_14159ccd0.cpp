// Recovered from the Nexon Messenger client library: chat-room close request.
// MS2-UNIT: unit_14159ccd0
// MS2-RANGE: 0x14159ccd0-0x14159cfb0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmchatroomfunc.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/placeholder/nmencoder.h"
#include "ms2/ms2recover.h"

extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(CNMSerializableDecoder*);
extern void FUN_1415f9990(void*);
extern void FUN_14156bcb0(void*, void*, void*);
extern void FUN_14156bd50(void*);

// MS2-FUNCTIONAL: request ID and base initialization match; base constructor argument register width differs.
// @0x14159ccd0
CNMCRCloseFunc::CNMCRCloseFunc()
    : CNMFunc(0xb002, 1, 0, 0)
{
}

// @0x14159cd20
CNMCRCloseFunc::CNMCRCloseFunc(unsigned uSerialKey)
    : CNMFunc(0xb002, 1, static_cast<int>(uSerialKey), 0)
{
}

// MS2-FUNCTIONAL: framed encoder setup and cleanup match; local encoder storage differs.
// @0x14159cd70
unsigned int CNMCRCloseFunc::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMCRCloseFunc::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}

// MS2-FUNCTIONAL: recovered format branch; direct calls replace virtual dispatch.
// @0x14159cdd0
unsigned int CNMCRCloseFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMCRCloseFunc::Encode(pEncoder, pStream);
    return CNMCRCloseFunc::EncodeFramed(pStream);
}

// MS2-FUNCTIONAL: empty request body and finish call match; direct dispatch replaces virtual calls.
// @0x14159ce30
unsigned int CNMCRCloseFunc::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMFunc::EncodeDispatch(pEncoder, pStream);
    FUN_1415f9990(pEncoder);
    return 1;
}

// MS2-FUNCTIONAL: decoder wrapper lifetime and validity branch match; local decoder storage differs.
// @0x14159ce80
unsigned int CNMCRCloseFunc::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMCRCloseFunc::Decode(&decoder, pStream);
}

// MS2-FUNCTIONAL: recovered decoder format branch; direct calls replace virtual dispatch.
// @0x14159cf10
unsigned int CNMCRCloseFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMCRCloseFunc::DecodeFramed(pStream);
    return CNMCRCloseFunc::Decode(pDecoder, pStream);
}

// MS2-FUNCTIONAL: empty reply body and validity return match; direct dispatch replaces virtual calls.
// @0x14159cf70
unsigned int CNMCRCloseFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    return FUN_1415fb750(pDecoder);
}

// MS2-PIN: ??0CNMCRCloseFunc@@QEAA@XZ 0x14159ccd0

