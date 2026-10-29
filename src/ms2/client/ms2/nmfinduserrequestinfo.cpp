// Recovered from the Nexon Messenger client library: find-user request information record.
// MS2-UNIT: ?\nmfinduserrequestinfo.cpp
// MS2-RANGE: 0x141574050-0x141574480 .text$mn
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

extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(CNMSerializableDecoder*);
extern void FUN_1415f9990(void*);
extern void FUN_14156ac20(void*, unsigned int);
extern void FUN_14156ab00(void*, unsigned char);
extern void FUN_14156ae30(void*, const void*);

// @0x141574050
CNMFindUserRequestInfo::CNMFindUserRequestInfo()
    : CNMSerializable(0x6672, 1, 1), m_10(0), m_14{}, m_34(0), m_38(0), m_3c(0), m_40(0), m_44(0), m_48(0)
{
}

// @0x141574100
unsigned int CNMFindUserRequestInfo::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMFindUserRequestInfo::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}

// @0x141574160
unsigned int CNMFindUserRequestInfo::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMFindUserRequestInfo::Encode(pEncoder, pStream);
    return CNMFindUserRequestInfo::EncodeFramed(pStream);
}

// @0x1415741c0
unsigned int CNMFindUserRequestInfo::Encode(CNMEncoder* pEncoder, CNMStream*)
{
    FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_10));
    FUN_14156ae30(pEncoder, m_14);
    FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_34));
    FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_38));
    FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_3c));
    FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_40));
    FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_44));
    FUN_14156ab00(pEncoder, static_cast<unsigned char>(m_48));
    FUN_1415f9990(pEncoder);
    return 1;
}

// @0x141574290
unsigned int CNMFindUserRequestInfo::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMFindUserRequestInfo::Decode(&decoder, pStream);
}

// @0x141574320
unsigned int CNMFindUserRequestInfo::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMFindUserRequestInfo::DecodeFramed(pStream);
    return CNMFindUserRequestInfo::Decode(pDecoder, pStream);
}

// @0x141574380
unsigned int CNMFindUserRequestInfo::Decode(CNMSerializableDecoder* pDecoder, CNMStream*)
{
    m_10 = static_cast<int>(pDecoder->ReadU32());
    pDecoder->ReadStringBufAlias(m_14, sizeof m_14);
    m_34 = static_cast<int>(pDecoder->ReadU32());
    m_38 = static_cast<int>(pDecoder->ReadU32());
    m_3c = static_cast<int>(pDecoder->ReadU32());
    m_40 = static_cast<int>(pDecoder->ReadU32());
    m_44 = static_cast<int>(pDecoder->ReadU32());
    m_48 = pDecoder->ReadU8();
    return FUN_1415fb750(pDecoder);
}

// MS2-PIN: ??0CNMFindUserRequestInfo@@QEAA@XZ 0x141574050
