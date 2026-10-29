// Recovered Nexon Messenger user information query.
// MS2-UNIT: ?\nmgetuserinfofunc.cpp
// MS2-RANGE: 0x141595d10-0x1415960e0 .text$mn
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

extern void FUN_1415fbe70(void*, unsigned int, const char*);
extern void FUN_14156ae30(void*, const void*);
extern void FUN_14156ac20(void*, unsigned int);
extern void FUN_1415f9990(void*);
extern int FUN_1415fb700(void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(CNMSerializableDecoder*);

// @0x141595d10
CNMGetUserInfoFunc::CNMGetUserInfoFunc()
    : CNMFunc(0x9001, 1, 0, 0)
{
    m_30[0] = 0;
    m_70 = 0;
}

// @0x141595d80
CNMGetUserInfoFunc::CNMGetUserInfoFunc(const char* userId, int type)
    : CNMFunc(0x9001, 1, 0, 0)
{
    if (userId != nullptr)
        FUN_1415fbe70(m_30, sizeof m_30, userId);
    else
        m_30[0] = 0;
    m_70 = type;
}

// @0x141595e20
unsigned int CNMGetUserInfoFunc::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMGetUserInfoFunc::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}

// @0x141595e80
unsigned int CNMGetUserInfoFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMGetUserInfoFunc::Encode(pEncoder, pStream);
    return CNMGetUserInfoFunc::EncodeFramed(pStream);
}

// @0x141595ee0
unsigned int CNMGetUserInfoFunc::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMFunc::EncodeDispatch(pEncoder, pStream);
    if (FUN_1415fb700(this) != 0)
    {
        FUN_14156ae30(pEncoder, m_30);
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_70));
    }
    FUN_1415f9990(pEncoder);
    return 1;
}

// @0x141595f60
unsigned int CNMGetUserInfoFunc::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMGetUserInfoFunc::Decode(&decoder, pStream);
}

// @0x141595ff0
unsigned int CNMGetUserInfoFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMGetUserInfoFunc::DecodeFramed(pStream);
    return CNMGetUserInfoFunc::Decode(pDecoder, pStream);
}

// @0x141596050
unsigned int CNMGetUserInfoFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    if (FUN_1415fb700(this) != 0)
    {
        pDecoder->ReadStringBufAlias(m_30, sizeof m_30);
        m_70 = static_cast<int>(pDecoder->ReadU32());
    }
    return FUN_1415fb750(pDecoder);
}

// MS2-PIN: ??0CNMGetUserInfoFunc@@QEAA@XZ 0x141595d10
// MS2-PIN: ??0CNMGetUserInfoFunc@@QEAA@PEBDH@Z 0x141595d80
