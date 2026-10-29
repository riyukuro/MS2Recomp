// Recovered from the Nexon Messenger client library. CNMRequestWBSessionFunc constructors and serializers.
// MS2-UNIT: unit_141597e50
// MS2-RANGE: 0x141597e50-0x141598330 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmobjects.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/placeholder/nmencoder.h"
#include "ms2/ms2recover.h"

extern int FUN_1415fb700(const void*);
extern int FUN_1415fb720(const void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(CNMSerializableDecoder*);
extern void FUN_1415f9990(void*);
extern void FUN_14156ac20(void*, unsigned int);
extern void FUN_14156acb0(void*, unsigned __int64);
extern void* FUN_14156bcb0(void*, void*, void*);
extern void FUN_14156bd50(void*);

// @0x141597e50
CNMRequestWBSessionFunc::CNMRequestWBSessionFunc()
    : CNMFunc(0xa004, 1, 0, 0), m_30(0), m_38(0), m_3c(0), m_40(0), m_44(0), m_48(0), m_4c(0)
{
}

// @0x141597ef0
CNMRequestWBSessionFunc::CNMRequestWBSessionFunc(const unsigned char* pTarget, int n40, int n44)
    : CNMFunc(0xa004, 1, 0, 0)
{
    memcpy(&m_30, pTarget, 0x10);
    m_40 = n40;
    m_44 = n44;
    m_48 = 0;
    m_4c = 0;
}

// @0x141597f90
unsigned int CNMRequestWBSessionFunc::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMRequestWBSessionFunc::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}

// @0x141597ff0
unsigned int CNMRequestWBSessionFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMRequestWBSessionFunc::Encode(pEncoder, pStream);
    return CNMRequestWBSessionFunc::EncodeFramed(pStream);
}

// @0x141598050
unsigned int CNMRequestWBSessionFunc::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMFunc::EncodeDispatch(pEncoder, pStream);
    if (FUN_1415fb700(this) != 0)
    {
        FUN_14156acb0(pEncoder, static_cast<unsigned __int64>(m_30));
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_38));
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_3c));
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_40));
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_44));
    }
    else if (FUN_1415fb720(this) != 0)
    {
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_48));
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_4c));
    }
    FUN_1415f9990(pEncoder);
    return 1;
}

// @0x141598130
unsigned int CNMRequestWBSessionFunc::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMRequestWBSessionFunc::Decode(&decoder, pStream);
}

// @0x1415981c0
unsigned int CNMRequestWBSessionFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMRequestWBSessionFunc::DecodeFramed(pStream);
    return CNMRequestWBSessionFunc::Decode(pDecoder, pStream);
}

// @0x141598220
unsigned int CNMRequestWBSessionFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    if (FUN_1415fb700(this) != 0)
    {
        m_30 = pDecoder->ReadU64();
        m_38 = pDecoder->ReadU32();
        m_3c = pDecoder->ReadU32();
        m_40 = pDecoder->ReadU32();
        m_44 = pDecoder->ReadU32();
    }
    else if (FUN_1415fb720(this) != 0)
    {
        m_48 = pDecoder->ReadU32();
        m_4c = pDecoder->ReadU32();
    }
    return FUN_1415fb750(pDecoder);
}

// MS2-PIN: ??0CNMRequestWBSessionFunc@@QEAA@XZ 0x141597e50
// MS2-PIN: ??0CNMRequestWBSessionFunc@@QEAA@PEBEHH@Z 0x141597ef0
