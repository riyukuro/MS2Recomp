// Recovered Nexon Messenger game-server want-close request.
// MS2-UNIT: ?\nmgswantclosefunc.cpp
// MS2-RANGE: 0x14159f960-0x14159fc90 .text$mn
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

extern void FUN_14156ab00(void*, unsigned char);
extern void FUN_1415f9990(void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(CNMSerializableDecoder*);

// @0x14159f960
CNMGSWantCloseFunc::CNMGSWantCloseFunc()
    : CNMFunc(0xc002, 1, 0, 0), m_30(0)
{
}

// @0x14159f9c0
CNMGSWantCloseFunc::CNMGSWantCloseFunc(int n18, int wantClose)
    : CNMFunc(0xc002, 1, n18, 0), m_30(wantClose)
{
}

// @0x14159fa20
unsigned int CNMGSWantCloseFunc::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMGSWantCloseFunc::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}

// @0x14159fa80
unsigned int CNMGSWantCloseFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMGSWantCloseFunc::Encode(pEncoder, pStream);
    return CNMGSWantCloseFunc::EncodeFramed(pStream);
}

// @0x14159fae0
unsigned int CNMGSWantCloseFunc::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMFunc::EncodeDispatch(pEncoder, pStream);
    FUN_14156ab00(pEncoder, static_cast<unsigned char>(m_30));
    FUN_1415f9990(pEncoder);
    return 1;
}

// @0x14159fb40
unsigned int CNMGSWantCloseFunc::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMGSWantCloseFunc::Decode(&decoder, pStream);
}

// @0x14159fbd0
unsigned int CNMGSWantCloseFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMGSWantCloseFunc::DecodeFramed(pStream);
    return CNMGSWantCloseFunc::Decode(pDecoder, pStream);
}

// @0x14159fc30
unsigned int CNMGSWantCloseFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    m_30 = pDecoder->ReadU8();
    return FUN_1415fb750(pDecoder);
}

// MS2-PIN: ??0CNMGSWantCloseFunc@@QEAA@XZ 0x14159f960
