// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// MS2-UNIT: unit_1415a15c0
// MS2-RANGE: 0x1415a15c0-0x1415a1970 .text$mn
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
extern void FUN_1415f9990(void*);
extern void FUN_1415efea0(CNMChatMessage*, const CNMChatMessage*);

// @0x1415a15c0
// MS2-FUNCTIONAL: initializes the recovered 0xc101 request and its embedded chat message.
CNMCSSendChatMessageFunc::CNMCSSendChatMessageFunc()
    : CNMFunc(0xc101, 1, 0, 0), m_30()
{
}

// @0x1415a1630
// MS2-FUNCTIONAL: preserves the serial key and copies the supplied chat message into the request.
CNMCSSendChatMessageFunc::CNMCSSendChatMessageFunc(unsigned int serial, const CNMChatMessage& message)
    : CNMFunc(0xc101, 1, static_cast<int>(serial), 0), m_30()
{
    FUN_1415efea0(&m_30, &message);
}

// @0x1415a16c0
// MS2-FUNCTIONAL: framed encoder setup and cleanup match; local encoder storage differs.
unsigned int CNMCSSendChatMessageFunc::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMCSSendChatMessageFunc::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}

// @0x1415a1720
// MS2-FUNCTIONAL: preserves format dispatch; direct calls replace virtual slot dispatch.
unsigned int CNMCSSendChatMessageFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMCSSendChatMessageFunc::Encode(pEncoder, pStream);
    return CNMCSSendChatMessageFunc::EncodeFramed(pStream);
}

// @0x1415a1780
// MS2-FUNCTIONAL: encodes the embedded message only for request direction and finalizes the stream.
unsigned int CNMCSSendChatMessageFunc::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMFunc::EncodeDispatch(pEncoder, pStream);
    if (FUN_1415fb700(this) != 0)
        m_30.EncodeFramed(pStream);
    FUN_1415f9990(pEncoder);
    return 1;
}

// @0x1415a1800
// MS2-FUNCTIONAL: framed decoder setup, validity check, and cleanup match; local decoder storage differs.
unsigned int CNMCSSendChatMessageFunc::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMCSSendChatMessageFunc::Decode(&decoder, pStream);
}

// @0x1415a1890
// MS2-FUNCTIONAL: selects framed decoding for decoder format 2.
unsigned int CNMCSSendChatMessageFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMCSSendChatMessageFunc::DecodeFramed(pStream);
    return CNMCSSendChatMessageFunc::Decode(pDecoder, pStream);
}

// @0x1415a18f0
// MS2-FUNCTIONAL: decodes the embedded message only for request direction and validates the decoder.
unsigned int CNMCSSendChatMessageFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    if (FUN_1415fb700(this) != 0)
        m_30.DecodeFramed(pStream);
    return static_cast<unsigned int>(FUN_1415fb750(pDecoder));
}

// MS2-PIN: ??0CNMCSSendChatMessageFunc@@QEAA@XZ 0x1415a15c0
