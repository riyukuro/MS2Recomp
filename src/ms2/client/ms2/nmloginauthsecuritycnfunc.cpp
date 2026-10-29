// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// MS2-UNIT: ?\nmloginauthsecuritycnfunc.cpp
// MS2-RANGE: 0x1415a5e90-0x1415a6300 .text$mn
// MS2-PIN: ??0CNMSerializableEncoder@@QEAA@PEAVCNMStream@@PEAVCNMSerializable@@@Z 0x14156bcb0
// MS2-PIN: ??1CNMSerializableEncoder@@QEAA@XZ 0x14156bd50
// MS2-PIN: ??0?$CNMStr@$0BAAA@@@QEAA@PEBD@Z 0x1415e58e0
// MS2-PIN: ??0?$CNMStr@$0EAA@@@QEAA@PEBD@Z 0x1415e5b20
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmobjects.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/placeholder/nmencoder.h"
#include "ms2/ms2recover.h"

extern void* FUN_1415f39a0(void*);
extern void* FUN_1415f39e0(void*);
extern unsigned int FUN_1415fa040(void*);
extern void* FUN_1415f9f60(void*);
extern unsigned int FUN_1415fa080(void*);
extern void* FUN_1415f9fe0(void*);
extern int FUN_1415fb700(void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(CNMSerializableDecoder*);
extern void FUN_14156ac20(void*, unsigned int);
extern void FUN_14156ae30(void*, const void*);
extern void FUN_1415f9990(void*);

// @0x1415a5e90
CNMLoginAuthSecurityCNFunc::CNMLoginAuthSecurityCNFunc()
    : CNMFunc(0x1112, 1, 0, 0), m_30(), m_38(), m_40(20000)
{
}

// @0x1415a5f10
CNMLoginAuthSecurityCNFunc::CNMLoginAuthSecurityCNFunc(const char* account, const char* password)
    : CNMFunc(0x1112, 1, 0, 0), m_30(account), m_38(password), m_40(20000)
{
}

// @0x1415a5fb0
unsigned int CNMLoginAuthSecurityCNFunc::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMLoginAuthSecurityCNFunc::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}

// @0x1415a6010
unsigned int CNMLoginAuthSecurityCNFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMLoginAuthSecurityCNFunc::Encode(pEncoder, pStream);
    return CNMLoginAuthSecurityCNFunc::EncodeFramed(pStream);
}

// @0x1415a6070
unsigned int CNMLoginAuthSecurityCNFunc::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMFunc::EncodeDispatch(pEncoder, pStream);
    if (FUN_1415fb700(this))
    {
        FUN_14156ae30(pEncoder, FUN_1415f39a0(&m_30));
        FUN_14156ae30(pEncoder, FUN_1415f39e0(&m_38));
    }
    else
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_40));
    FUN_1415f9990(pEncoder);
    return 1;
}

// @0x1415a6110
unsigned int CNMLoginAuthSecurityCNFunc::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMLoginAuthSecurityCNFunc::Decode(&decoder, pStream);
}

// @0x1415a61a0
unsigned int CNMLoginAuthSecurityCNFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMLoginAuthSecurityCNFunc::DecodeFramed(pStream);
    return CNMLoginAuthSecurityCNFunc::Decode(pDecoder, pStream);
}

// @0x1415a6200
unsigned int CNMLoginAuthSecurityCNFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    if (FUN_1415fb700(this))
    {
        pDecoder->ReadStringBufAlias(static_cast<char*>(FUN_1415f9f60(&m_30)), FUN_1415fa040(&m_30));
        pDecoder->ReadStringBufAlias(static_cast<char*>(FUN_1415f9fe0(&m_38)), FUN_1415fa080(&m_38));
    }
    else
    {
        m_40 = static_cast<int>(pDecoder->ReadU32());
    }
    return static_cast<unsigned int>(FUN_1415fb750(pDecoder));
}

// MS2-PIN: ??0CNMLoginAuthSecurityCNFunc@@QEAA@XZ 0x1415a5e90
