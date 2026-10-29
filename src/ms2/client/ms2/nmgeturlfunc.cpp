// Recovered Nexon Messenger URL query.
// MS2-UNIT: ?\nmgeturlfunc.cpp
// MS2-RANGE: 0x141591960-0x141591f50 .text$mn
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

extern void FUN_14156ac20(void*, unsigned int);
extern void FUN_14156ab00(void*, unsigned char);
extern void FUN_14156ae30(void*, const void*);
extern void FUN_1415f9990(void*);
extern int FUN_1415fb700(void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(CNMSerializableDecoder*);

// @0x141591960
CNMGetUrlFunc::CNMGetUrlFunc()
    : CNMFunc(0x8004, 1, 0, 0), m_30(1), m_34(0), m_38(0), m_3c(0)
{
    m_40[0] = 0;
    m_140 = 0;
    m_144[0] = 0;
    m_244 = 0;
    m_248 = 0;
    m_24c = 0;
    m_250[0] = 0;
}

// @0x141591a50
unsigned int CNMGetUrlFunc::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMGetUrlFunc::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}

// @0x141591ab0
unsigned int CNMGetUrlFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMGetUrlFunc::Encode(pEncoder, pStream);
    return CNMGetUrlFunc::EncodeFramed(pStream);
}

// @0x141591b10
unsigned int CNMGetUrlFunc::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMFunc::EncodeDispatch(pEncoder, pStream);
    if (FUN_1415fb700(this))
    {
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_30));
        if (m_30 == 1)
            FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_34));
        if (m_30 == 2)
            FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_38));
        if (m_30 == 3)
            FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_3c));
        if (m_30 == 4)
            FUN_14156ae30(pEncoder, m_40);
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_140));
        FUN_14156ae30(pEncoder, m_144);
        FUN_14156ab00(pEncoder, static_cast<unsigned char>(m_244));
        FUN_14156ab00(pEncoder, static_cast<unsigned char>(m_248));
        FUN_14156ab00(pEncoder, static_cast<unsigned char>(m_24c));
    }
    else
        FUN_14156ae30(pEncoder, m_250);
    FUN_1415f9990(pEncoder);
    return 1;
}

// @0x141591c80
unsigned int CNMGetUrlFunc::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMGetUrlFunc::Decode(&decoder, pStream);
}

// @0x141591d10
unsigned int CNMGetUrlFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMGetUrlFunc::DecodeFramed(pStream);
    return CNMGetUrlFunc::Decode(pDecoder, pStream);
}

// @0x141591d70
unsigned int CNMGetUrlFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    if (FUN_1415fb700(this))
    {
        m_30 = static_cast<int>(pDecoder->ReadU32());
        if (m_30 == 1)
            m_34 = static_cast<int>(pDecoder->ReadU32());
        if (m_30 == 2)
            m_38 = static_cast<int>(pDecoder->ReadU32());
        if (m_30 == 3)
            m_3c = static_cast<int>(pDecoder->ReadU32());
        if (m_30 == 4)
            pDecoder->ReadStringBufAlias(m_40, sizeof m_40);
        m_140 = static_cast<int>(pDecoder->ReadU32());
        pDecoder->ReadStringBufAlias(m_144, sizeof m_144);
        m_244 = pDecoder->ReadU8();
        m_248 = pDecoder->ReadU8();
        m_24c = pDecoder->ReadU8();
    }
    else
        pDecoder->ReadStringBufAlias(m_250, sizeof m_250);
    return FUN_1415fb750(pDecoder);
}

// MS2-PIN: ??0CNMGetUrlFunc@@QEAA@XZ 0x141591960
