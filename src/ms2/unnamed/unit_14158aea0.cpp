// Nexon Messenger send-accuse-note request serialization.
// MS2-UNIT: unit_14158aea0
// MS2-RANGE: 0x14158aea0-0x14158b290 .text$mn
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
extern void FUN_1415fbe70(void*, unsigned int, const void*);
extern void FUN_1415f9990(void*);
extern int FUN_1415fb700(void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(CNMSerializableDecoder*);

// MS2-FUNCTIONAL 0x14158aea0: initializes the embedded report request.
// @0x14158aea0
CNMSendAccuseNoteMsgFunc::CNMSendAccuseNoteMsgFunc() : CNMFunc(0x6006, 1, 0, 0), m_report() {}

// MS2-FUNCTIONAL 0x14158af10: stores report type, optional fixed-size detail text, and status.
// @0x14158af10
CNMSendAccuseNoteMsgFunc::CNMSendAccuseNoteMsgFunc(int type, const void* details, int status)
    : CNMFunc(0x6006, 1, 0, 0), m_report()
{
    m_report.m_14 = static_cast<unsigned int>(type);
    if (details) FUN_1415fbe70(m_report.m_60, 4000, details);
    m_report.m_5e20 = static_cast<unsigned int>(status);
}

// MS2-FUNCTIONAL 0x14158afe0: frames the report request.
// @0x14158afe0
unsigned int CNMSendAccuseNoteMsgFunc::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMSendAccuseNoteMsgFunc::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}

// MS2-FUNCTIONAL 0x14158b040: selects the encoder by wire format.
// @0x14158b040
unsigned int CNMSendAccuseNoteMsgFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMSendAccuseNoteMsgFunc::Encode(pEncoder, pStream);
    return CNMSendAccuseNoteMsgFunc::EncodeFramed(pStream);
}

// MS2-FUNCTIONAL 0x14158b0a0: serializes the embedded report for a response.
// @0x14158b0a0
unsigned int CNMSendAccuseNoteMsgFunc::Encode(CNMEncoder* encoder, CNMStream* stream)
{
    CNMFunc::EncodeDispatch(encoder, stream);
    if (FUN_1415fb700(this)) m_report.Encode(encoder, stream);
    FUN_1415f9990(encoder);
    return 1;
}

// MS2-FUNCTIONAL 0x14158b120: decodes a framed report response.
// @0x14158b120
unsigned int CNMSendAccuseNoteMsgFunc::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMSendAccuseNoteMsgFunc::Decode(&decoder, pStream);
}

// MS2-FUNCTIONAL 0x14158b1b0: selects the decoder by wire format.
// @0x14158b1b0
unsigned int CNMSendAccuseNoteMsgFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMSendAccuseNoteMsgFunc::DecodeFramed(pStream);
    return CNMSendAccuseNoteMsgFunc::Decode(pDecoder, pStream);
}

// MS2-FUNCTIONAL 0x14158b210: delegates response payload decoding to CNMReportInfo.
// @0x14158b210
unsigned int CNMSendAccuseNoteMsgFunc::Decode(CNMSerializableDecoder* decoder, CNMStream* stream)
{
    CNMFunc::DecodeDispatch(decoder, stream);
    if (FUN_1415fb700(this)) m_report.Decode(decoder, stream);
    return static_cast<unsigned int>(FUN_1415fb750(decoder));
}

// MS2-PIN: ??0CNMSendAccuseNoteMsgFunc@@QEAA@XZ 0x14158aea0
