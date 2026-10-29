// Recovered Nexon Messenger count request and reply.
// MS2-UNIT: ?\nmgetcountfunc.cpp
// MS2-RANGE: 0x141582980-0x141582d00 .text$mn
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

// @0x141582980
CNMGetCountFunc::CNMGetCountFunc() : CNMFunc(0x2008, 1, 0, 0), m_30(0), m_34(0)
{
}

// @0x1415829e0
CNMGetCountFunc::CNMGetCountFunc(int count) : CNMFunc(0x2008, 1, 0, 0), m_30(count), m_34(0)
{
}

// @0x141582a50
unsigned int CNMGetCountFunc::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMGetCountFunc::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}

// @0x141582ab0
unsigned int CNMGetCountFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMGetCountFunc::Encode(pEncoder, pStream);
    return CNMGetCountFunc::EncodeFramed(pStream);
}

// @0x141582b10
unsigned int CNMGetCountFunc::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMFunc::EncodeDispatch(pEncoder, pStream);
    if (FUN_1415fb700(this))
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_30));
    else
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_34));
    FUN_1415f9990(pEncoder);
    return 1;
}

// @0x141582b90
unsigned int CNMGetCountFunc::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMGetCountFunc::Decode(&decoder, pStream);
}

// @0x141582c20
unsigned int CNMGetCountFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMGetCountFunc::DecodeFramed(pStream);
    return CNMGetCountFunc::Decode(pDecoder, pStream);
}

// @0x141582c80
unsigned int CNMGetCountFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    if (FUN_1415fb700(this))
        m_30 = static_cast<int>(pDecoder->ReadU32());
    else
        m_34 = static_cast<int>(pDecoder->ReadU32());
    return FUN_1415fb750(pDecoder);
}

// MS2-PIN: ??0CNMGetCountFunc@@QEAA@XZ 0x141582980
