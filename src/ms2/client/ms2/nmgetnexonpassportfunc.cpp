// Recovered Nexon Messenger Nexon Passport query.
// MS2-UNIT: ?\nmgetnexonpassportfunc.cpp
// MS2-RANGE: 0x141584d00-0x1415850a0 .text$mn
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

extern int FUN_1415fb700(void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(CNMSerializableDecoder*);
extern void FUN_1415f9990(void*);
extern void FUN_14156ac20(void*, unsigned int);
extern void FUN_14156ae30(void*, const void*);

// @0x141584d00
CNMGetNexonPassportFunc::CNMGetNexonPassportFunc()
    : CNMFunc(0x2105, 1, 0, 0), m_30(0)
{
    m_34[0] = 0;
}

// @0x141584d70
CNMGetNexonPassportFunc::CNMGetNexonPassportFunc(int passport)
    : CNMFunc(0x2105, 1, 0, 0), m_30(passport)
{
    m_34[0] = 0;
}

// @0x141584de0
unsigned int CNMGetNexonPassportFunc::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMGetNexonPassportFunc::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}

// @0x141584e40
unsigned int CNMGetNexonPassportFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMGetNexonPassportFunc::Encode(pEncoder, pStream);
    return CNMGetNexonPassportFunc::EncodeFramed(pStream);
}

// @0x141584ea0
unsigned int CNMGetNexonPassportFunc::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMFunc::EncodeDispatch(pEncoder, pStream);
    if (FUN_1415fb700(this))
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_30));
    else
        FUN_14156ae30(pEncoder, m_34);
    FUN_1415f9990(pEncoder);
    return 1;
}

// @0x141584f20
unsigned int CNMGetNexonPassportFunc::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMGetNexonPassportFunc::Decode(&decoder, pStream);
}

// @0x141584fb0
unsigned int CNMGetNexonPassportFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMGetNexonPassportFunc::DecodeFramed(pStream);
    return CNMGetNexonPassportFunc::Decode(pDecoder, pStream);
}

// @0x141585010
unsigned int CNMGetNexonPassportFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    if (FUN_1415fb700(this))
        m_30 = static_cast<int>(pDecoder->ReadU32());
    else
        pDecoder->ReadStringBufAlias(m_34, 0x1000);
    return FUN_1415fb750(pDecoder);
}

// MS2-PIN: ??0CNMGetNexonPassportFunc@@QEAA@XZ 0x141584d00
