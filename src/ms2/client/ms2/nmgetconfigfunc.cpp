// Recovered Nexon Messenger configuration request and reply.
// MS2-UNIT: ?\nmgetconfigfunc.cpp
// MS2-RANGE: 0x141581690-0x141581c00 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmfunc.h"
#include "ms2/placeholder/nmobjects.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/ms2recover.h"

extern int FUN_1415fb720(void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(void*);
extern void FUN_1415f9990(void*);
extern void FUN_14156ac20(void*, unsigned int);
extern void FUN_14156ab00(void*, unsigned char);
extern void FUN_14156bcb0(void*, void*, void*);
extern void FUN_14156be10(void*, void*, void*);
extern void FUN_14156bd50(void*);

// MS2-FUNCTIONAL: initializes a configuration request with every mask and value cleared.
// @0x141581690
CNMGetConfigFunc::CNMGetConfigFunc()
    : CNMFunc(0x2004, 1, 0, 0), m_48()
{
    m_30 = m_34 = m_38 = m_3c = m_40 = 0;
}

// MS2-FUNCTIONAL: initializes a configuration request with its requested setting mask.
// @0x141581730
CNMGetConfigFunc::CNMGetConfigFunc(int configMask)
    : CNMFunc(0x2004, 1, 0, 0), m_48()
{
    m_30 = configMask;
    m_34 = m_38 = m_3c = m_40 = 0;
}

// MS2-FUNCTIONAL: frames the request using the common temporary encoder.
// @0x1415817d0
unsigned int CNMGetConfigFunc::EncodeFramed(CNMStream* pStream)
{
    alignas(8) unsigned char encoder[0x18];
    FUN_14156bcb0(encoder, pStream, this);
    const unsigned int result = Encode(reinterpret_cast<CNMEncoder*>(encoder), pStream);
    FUN_14156bd50(encoder);
    return result;
}

// MS2-FUNCTIONAL: selects direct or framed request encoding.
// @0x141581830
unsigned int CNMGetConfigFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        Encode(pEncoder, pStream);
    else
        EncodeFramed(pStream);
    return 0;
}

// MS2-FUNCTIONAL: writes requested configuration values selected by the mask.
// @0x141581890
unsigned int CNMGetConfigFunc::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMFunc::EncodeDispatch(pEncoder, pStream);
    FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_30));
    if (FUN_1415fb720(this)) {
        if (m_30 & 1) FUN_14156ab00(pEncoder, static_cast<unsigned char>(m_34));
        if (m_30 & 2) FUN_14156ab00(pEncoder, static_cast<unsigned char>(m_38));
        if (m_30 & 4) FUN_14156ab00(pEncoder, static_cast<unsigned char>(m_3c));
        if (m_30 & 8) FUN_14156ab00(pEncoder, static_cast<unsigned char>(m_40));
        if (m_30 & 0x10) m_48.EncodeFramed(pStream);
    }
    FUN_1415f9990(pEncoder);
    return 1;
}

// MS2-FUNCTIONAL: validates a framed reply before decoding it.
// @0x1415819c0
unsigned int CNMGetConfigFunc::DecodeFramed(CNMStream* pStream)
{
    alignas(8) unsigned char decoder[0x38];
    FUN_14156be10(decoder, pStream, this);
    unsigned int result = 0;
    if (FUN_1415fb750(decoder) != 0)
        result = Decode(reinterpret_cast<CNMSerializableDecoder*>(decoder), pStream);
    FUN_14156bd50(decoder);
    return result;
}

// MS2-FUNCTIONAL: selects framed decoding for version two replies.
// @0x141581a50
unsigned int CNMGetConfigFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        DecodeFramed(pStream);
    else
        Decode(pDecoder, pStream);
    return 0;
}

// MS2-FUNCTIONAL: restores values selected by the reply's configuration mask.
// @0x141581ab0
unsigned int CNMGetConfigFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    m_30 = static_cast<int>(pDecoder->ReadU32());
    if (FUN_1415fb720(this)) {
        if (m_30 & 1) m_34 = pDecoder->ReadU8();
        if (m_30 & 2) m_38 = pDecoder->ReadU8();
        if (m_30 & 4) m_3c = pDecoder->ReadU8();
        if (m_30 & 8) m_40 = pDecoder->ReadU8();
        if (m_30 & 0x10) m_48.DecodeFramed(pStream);
    }
    FUN_1415fb750(pDecoder);
    return 1;
}

// MS2-PIN: ??0CNMGetConfigFunc@@QEAA@XZ 0x141581690
