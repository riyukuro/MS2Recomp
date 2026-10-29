// Recovered Nexon Messenger domain query.
// MS2-UNIT: ?\nmgetdomainfunc.cpp
// MS2-RANGE: 0x141583ee0-0x1415841e0 .text$mn
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
extern void FUN_14156ae30(void*, const void*);

// @0x141583ee0
CNMGetDomainFunc::CNMGetDomainFunc() : CNMFunc(0x2101, 1, 0, 0)
{
    m_30[0] = 0;
}

// @0x141583f40
unsigned int CNMGetDomainFunc::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMGetDomainFunc::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}

// @0x141583fa0
unsigned int CNMGetDomainFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMGetDomainFunc::Encode(pEncoder, pStream);
    return CNMGetDomainFunc::EncodeFramed(pStream);
}

// @0x141584000
unsigned int CNMGetDomainFunc::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMFunc::EncodeDispatch(pEncoder, pStream);
    if (FUN_1415fb720(this) != 0)
        FUN_14156ae30(pEncoder, m_30);
    FUN_1415f9990(pEncoder);
    return 1;
}

// @0x141584070
unsigned int CNMGetDomainFunc::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMGetDomainFunc::Decode(&decoder, pStream);
}

// @0x141584100
unsigned int CNMGetDomainFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMGetDomainFunc::DecodeFramed(pStream);
    return CNMGetDomainFunc::Decode(pDecoder, pStream);
}

// @0x141584160
unsigned int CNMGetDomainFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    if (FUN_1415fb720(this) != 0)
        pDecoder->ReadStringBufAlias(m_30, sizeof m_30);
    return FUN_1415fb750(pDecoder);
}

// MS2-PIN: ??0CNMGetDomainFunc@@QEAA@XZ 0x141583ee0
