// Recovered Nexon Messenger China security code query.
// MS2-UNIT: ?\nmgetsecuritycodecnfunc.cpp
// MS2-RANGE: 0x1415850a0-0x141585390 .text$mn
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

// @0x1415850a0
CNMGetSecurityCodeCNFunc::CNMGetSecurityCodeCNFunc()
    : CNMFunc(0x2108, 1, 0, 0), m_30(0)
{
}

// @0x141585100
unsigned int CNMGetSecurityCodeCNFunc::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMGetSecurityCodeCNFunc::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}

// @0x141585160
unsigned int CNMGetSecurityCodeCNFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMGetSecurityCodeCNFunc::Encode(pEncoder, pStream);
    return CNMGetSecurityCodeCNFunc::EncodeFramed(pStream);
}

// @0x1415851c0
unsigned int CNMGetSecurityCodeCNFunc::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMFunc::EncodeDispatch(pEncoder, pStream);
    if (FUN_1415fb720(this) != 0)
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_30));
    FUN_1415f9990(pEncoder);
    return 1;
}

// @0x141585230
unsigned int CNMGetSecurityCodeCNFunc::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMGetSecurityCodeCNFunc::Decode(&decoder, pStream);
}

// @0x1415852c0
unsigned int CNMGetSecurityCodeCNFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMGetSecurityCodeCNFunc::DecodeFramed(pStream);
    return CNMGetSecurityCodeCNFunc::Decode(pDecoder, pStream);
}

// @0x141585320
unsigned int CNMGetSecurityCodeCNFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    if (FUN_1415fb720(this) != 0)
        m_30 = static_cast<int>(pDecoder->ReadU32());
    return FUN_1415fb750(pDecoder);
}

// MS2-PIN: ??0CNMGetSecurityCodeCNFunc@@QEAA@XZ 0x1415850a0
