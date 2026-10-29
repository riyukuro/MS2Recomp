// Recovered Nexon Messenger game-server callback registration.
// MS2-UNIT: ?\nmgsregistercallbackfunc.cpp
// MS2-RANGE: 0x14159f5e0-0x14159f960 .text$mn
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
extern void FUN_1415f9990(void*);
extern int FUN_1415fb700(void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(CNMSerializableDecoder*);

// @0x14159f5e0
CNMGSRegisterCallbackFunc::CNMGSRegisterCallbackFunc()
    : CNMFunc(0xc001, 1, 0, 0), m_30(0), m_38(0)
{
}

// @0x14159f640
CNMGSRegisterCallbackFunc::CNMGSRegisterCallbackFunc(int n18, long long callback, int code)
    : CNMFunc(0xc001, 1, n18, 0), m_30(callback), m_38(code)
{
}

// @0x14159f6b0
unsigned int CNMGSRegisterCallbackFunc::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMGSRegisterCallbackFunc::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}

// @0x14159f710
unsigned int CNMGSRegisterCallbackFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMGSRegisterCallbackFunc::Encode(pEncoder, pStream);
    return CNMGSRegisterCallbackFunc::EncodeFramed(pStream);
}

// @0x14159f770
unsigned int CNMGSRegisterCallbackFunc::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMFunc::EncodeDispatch(pEncoder, pStream);
    if (FUN_1415fb700(this) != 0)
    {
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_30));
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_38));
    }
    FUN_1415f9990(pEncoder);
    return 1;
}

// @0x14159f7f0
unsigned int CNMGSRegisterCallbackFunc::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMGSRegisterCallbackFunc::Decode(&decoder, pStream);
}

// @0x14159f880
unsigned int CNMGSRegisterCallbackFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMGSRegisterCallbackFunc::DecodeFramed(pStream);
    return CNMGSRegisterCallbackFunc::Decode(pDecoder, pStream);
}

// @0x14159f8e0
unsigned int CNMGSRegisterCallbackFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    if (FUN_1415fb700(this) != 0)
    {
        m_30 = pDecoder->ReadU32();
        m_38 = static_cast<int>(pDecoder->ReadU32());
    }
    return FUN_1415fb750(pDecoder);
}

// MS2-PIN: ??0CNMGSRegisterCallbackFunc@@QEAA@XZ 0x14159f5e0
