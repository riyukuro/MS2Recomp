// Recovered Nexon Messenger security question query.
// MS2-UNIT: ?\nmgetsecurityquestionfunc.cpp
// MS2-RANGE: 0x141585390-0x1415856c0 .text$mn
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

extern void* FUN_1415f39e0(void*);
extern unsigned int FUN_1415fa080(void*);
extern void* FUN_1415f9fe0(void*);
extern int FUN_1415fb720(void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(CNMSerializableDecoder*);
extern void FUN_1415f9990(void*);
extern void FUN_14156ae30(void*, const void*);

// @0x141585390
CNMGetSecurityQuestionFunc::CNMGetSecurityQuestionFunc()
    : CNMFunc(0x2106, 1, 0, 0), m_30()
{
}

// @0x141585400
unsigned int CNMGetSecurityQuestionFunc::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMGetSecurityQuestionFunc::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}

// @0x141585460
unsigned int CNMGetSecurityQuestionFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMGetSecurityQuestionFunc::Encode(pEncoder, pStream);
    return CNMGetSecurityQuestionFunc::EncodeFramed(pStream);
}

// @0x1415854c0
unsigned int CNMGetSecurityQuestionFunc::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMFunc::EncodeDispatch(pEncoder, pStream);
    if (FUN_1415fb720(this) != 0)
        FUN_14156ae30(pEncoder, FUN_1415f39e0(&m_30));
    FUN_1415f9990(pEncoder);
    return 1;
}

// @0x141585530
unsigned int CNMGetSecurityQuestionFunc::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMGetSecurityQuestionFunc::Decode(&decoder, pStream);
}

// @0x1415855c0
unsigned int CNMGetSecurityQuestionFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMGetSecurityQuestionFunc::DecodeFramed(pStream);
    return CNMGetSecurityQuestionFunc::Decode(pDecoder, pStream);
}

// @0x141585620
unsigned int CNMGetSecurityQuestionFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    if (FUN_1415fb720(this) != 0)
    {
        pDecoder->ReadStringBufAlias(static_cast<char*>(FUN_1415f9fe0(&m_30)), FUN_1415fa080(&m_30));
    }
    return FUN_1415fb750(pDecoder);
}

// MS2-PIN: ??0CNMGetSecurityQuestionFunc@@QEAA@XZ 0x141585390
