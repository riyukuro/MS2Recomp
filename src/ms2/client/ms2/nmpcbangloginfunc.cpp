// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// MS2-UNIT: ?\nmpcbangloginfunc.cpp
// MS2-RANGE: 0x1415a6ab0-0x1415a6e90 .text$mn
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

extern void FUN_1415e5860(void*);
extern void FUN_1415e5820(void*, const void*);
extern void* FUN_1415f3980(void*);
extern unsigned int FUN_1415fa020(void*);
extern void* FUN_1415f9f20(void*);
extern int FUN_1415fb700(void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(CNMSerializableDecoder*);
extern void FUN_14156ac20(void*, unsigned int);
extern void FUN_1415f9990(void*);
extern void FUN_14156ae30(void*, const void*);

// @0x1415a6ab0
CNMPCBangLoginFunc::CNMPCBangLoginFunc()
    : CNMFunc(0x1115, 1, 0, 0)
{
    FUN_1415e5860(&m_30);
    m_38 = 20000;
}

// @0x1415a6b20
CNMPCBangLoginFunc::CNMPCBangLoginFunc(const char* token)
    : CNMFunc(0x1115, 1, 0, 0)
{
    FUN_1415e5820(&m_30, token);
    m_38 = 20000;
}

// @0x1415a6ba0
unsigned int CNMPCBangLoginFunc::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMPCBangLoginFunc::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}

// @0x1415a6c00
unsigned int CNMPCBangLoginFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMPCBangLoginFunc::Encode(pEncoder, pStream);
    return CNMPCBangLoginFunc::EncodeFramed(pStream);
}

// @0x1415a6c60
unsigned int CNMPCBangLoginFunc::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMFunc::EncodeDispatch(pEncoder, pStream);
    if (FUN_1415fb700(this))
        FUN_14156ae30(pEncoder, FUN_1415f3980(&m_30));
    else
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_38));
    FUN_1415f9990(pEncoder);
    return 1;
}

// @0x1415a6cf0
unsigned int CNMPCBangLoginFunc::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMPCBangLoginFunc::Decode(&decoder, pStream);
}

// @0x1415a6d80
unsigned int CNMPCBangLoginFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMPCBangLoginFunc::DecodeFramed(pStream);
    return CNMPCBangLoginFunc::Decode(pDecoder, pStream);
}

// @0x1415a6de0
unsigned int CNMPCBangLoginFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    if (FUN_1415fb700(this))
    {
        pDecoder->ReadStringBufAlias(static_cast<char*>(FUN_1415f9f20(&m_30)), FUN_1415fa020(&m_30));
    }
    else
    {
        m_38 = static_cast<int>(pDecoder->ReadU32());
    }
    return static_cast<unsigned int>(FUN_1415fb750(pDecoder));
}

// MS2-PIN: ??0CNMPCBangLoginFunc@@QEAA@XZ 0x1415a6ab0
