// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// MS2-UNIT: ?\nmlogoutauthfunc.cpp
// MS2-RANGE: 0x1415a6730-0x1415a6ab0 .text$mn
// MS2-PIN: ??0CNMSerializableEncoder@@QEAA@PEAVCNMStream@@PEAVCNMSerializable@@@Z 0x14156bcb0
// MS2-PIN: ??1CNMSerializableEncoder@@QEAA@XZ 0x14156bd50
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmobjects.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/placeholder/nmencoder.h"
#include "ms2/ms2recover.h"

extern int FUN_1415fb700(void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(CNMSerializableDecoder*);
extern void FUN_14156ab00(void*, unsigned char);
extern void FUN_14156ac20(void*, unsigned int);
extern void FUN_1415f9990(void*);

// @0x1415a6730
CNMLogoutAuthFunc::CNMLogoutAuthFunc()
    : CNMFunc(0x1110, 1, 0, 0), m_30(0), m_34(0)
{
}

// @0x1415a6790
CNMLogoutAuthFunc::CNMLogoutAuthFunc(int flag, unsigned int value)
    : CNMFunc(0x1110, 1, 0, 0), m_30(flag), m_34(static_cast<int>(value))
{
}

// @0x1415a6800
unsigned int CNMLogoutAuthFunc::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMLogoutAuthFunc::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}

// @0x1415a6860
unsigned int CNMLogoutAuthFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMLogoutAuthFunc::Encode(pEncoder, pStream);
    return CNMLogoutAuthFunc::EncodeFramed(pStream);
}

// @0x1415a68c0
unsigned int CNMLogoutAuthFunc::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMFunc::EncodeDispatch(pEncoder, pStream);
    if (FUN_1415fb700(this) != 0)
    {
        FUN_14156ab00(pEncoder, static_cast<unsigned char>(m_30));
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_34));
    }
    FUN_1415f9990(pEncoder);
    return 1;
}

// @0x1415a6940
unsigned int CNMLogoutAuthFunc::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMLogoutAuthFunc::Decode(&decoder, pStream);
}

// @0x1415a69d0
unsigned int CNMLogoutAuthFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMLogoutAuthFunc::DecodeFramed(pStream);
    return CNMLogoutAuthFunc::Decode(pDecoder, pStream);
}

// @0x1415a6a30
unsigned int CNMLogoutAuthFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    if (FUN_1415fb700(this) != 0)
    {
        m_30 = pDecoder->ReadU8();
        m_34 = static_cast<int>(pDecoder->ReadU32());
    }
    return static_cast<unsigned int>(FUN_1415fb750(pDecoder));
}

// MS2-PIN: ??0CNMLogoutAuthFunc@@QEAA@XZ 0x1415a6730
