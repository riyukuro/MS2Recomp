// Recovered Nexon Messenger configuration request and reply.
// MS2-UNIT: ?\nmgetconfigfunc.cpp
// MS2-RANGE: 0x141581690-0x141581c00 .text$mn
// MS2-PIN: ??0CNMSerializableEncoder@@QEAA@PEAVCNMStream@@PEAVCNMSerializable@@@Z 0x14156bcb0
// MS2-PIN: ??1CNMSerializableEncoder@@QEAA@XZ 0x14156bd50
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmfunc.h"
#include "ms2/placeholder/nmobjects.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/placeholder/nmencoder.h"
#include "ms2/ms2recover.h"

extern int FUN_1415fb720(void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(CNMSerializableDecoder*);
extern void FUN_1415f9990(void*);
extern void FUN_14156ac20(void*, unsigned int);
extern void FUN_14156ab00(void*, unsigned char);

// @0x141581690
CNMGetConfigFunc::CNMGetConfigFunc()
    : CNMFunc(0x2004, 1, 0, 0), m_48()
{
    m_30 = 0;
    m_34 = 0;
    m_38 = 0;
    m_3c = 0;
    m_40 = 0;
}

// @0x141581730
CNMGetConfigFunc::CNMGetConfigFunc(int configMask)
    : CNMFunc(0x2004, 1, 0, 0), m_48()
{
    m_30 = configMask;
    m_34 = 0;
    m_38 = 0;
    m_3c = 0;
    m_40 = 0;
}

// @0x1415817d0
unsigned int CNMGetConfigFunc::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMGetConfigFunc::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}

// @0x141581830
unsigned int CNMGetConfigFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMGetConfigFunc::Encode(pEncoder, pStream);
    return CNMGetConfigFunc::EncodeFramed(pStream);
}

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

// @0x1415819c0
unsigned int CNMGetConfigFunc::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMGetConfigFunc::Decode(&decoder, pStream);
}

// @0x141581a50
unsigned int CNMGetConfigFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMGetConfigFunc::DecodeFramed(pStream);
    return CNMGetConfigFunc::Decode(pDecoder, pStream);
}

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
    return FUN_1415fb750(pDecoder);
}

// MS2-PIN: ??0CNMGetConfigFunc@@QEAA@XZ 0x141581690
