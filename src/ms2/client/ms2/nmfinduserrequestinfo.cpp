// Recovered from the Nexon Messenger client library: find-user request information record.
// MS2-UNIT: ?\nmfinduserrequestinfo.cpp
// MS2-RANGE: 0x141574050-0x141574480 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmobjects.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/ms2recover.h"

extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(void*);
extern void FUN_1415f9990(void*);
extern void FUN_14156ac20(void*, unsigned int);
extern void FUN_14156ab00(void*, unsigned char);
extern void FUN_14156ae30(void*, const void*);
extern void FUN_14156bcb0(void*, void*, void*);
extern void FUN_14156be10(void*, void*, void*);
extern void FUN_14156bd50(void*);

// MS2-FUNCTIONAL: initializes the find-user query and zeroes its fixed query fields.
// @0x141574050
CNMFindUserRequestInfo::CNMFindUserRequestInfo()
    : CNMSerializable(0x6672, 1, 1), m_10(0), m_14{}, m_34(0), m_38(0), m_3c(0), m_40(0), m_44(0), m_48(0), m_4c(0)
{
}

// MS2-FUNCTIONAL: frames query encoding through the recovered temporary encoder.
// @0x141574100
unsigned int CNMFindUserRequestInfo::EncodeFramed(CNMStream* pStream)
{
    alignas(8) unsigned char encoder[0x18];
    FUN_14156bcb0(encoder, pStream, this);
    const unsigned int result = Encode(reinterpret_cast<CNMEncoder*>(encoder), pStream);
    FUN_14156bd50(encoder);
    return result;
}

// MS2-FUNCTIONAL: dispatches query encoding according to the serialized format.
// @0x141574160
unsigned int CNMFindUserRequestInfo::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        Encode(pEncoder, pStream);
    else
        EncodeFramed(pStream);
    return 0;
}

// MS2-FUNCTIONAL: writes the query ID, fixed search text, filters, and final byte in wire order.
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

// MS2-FUNCTIONAL: frames query decoding and validates the temporary decoder.
// @0x141574290
unsigned int CNMFindUserRequestInfo::DecodeFramed(CNMStream* pStream)
{
    alignas(8) unsigned char decoder[0x38];
    FUN_14156be10(decoder, pStream, this);
    unsigned int result = 0;
    if (FUN_1415fb750(decoder) != 0)
        result = Decode(reinterpret_cast<CNMSerializableDecoder*>(decoder), pStream);
    FUN_14156bd50(decoder);
    return result;
}

// MS2-FUNCTIONAL: dispatches query decoding by decoder version.
// @0x141574320
unsigned int CNMFindUserRequestInfo::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        DecodeFramed(pStream);
    else
        Decode(pDecoder, pStream);
    return 0;
}

// MS2-FUNCTIONAL: restores query text, filter fields, and the trailing byte in serialized order.
// @0x141574380
unsigned int CNMFindUserRequestInfo::Decode(CNMSerializableDecoder* pDecoder, CNMStream*)
{
    m_10 = static_cast<int>(pDecoder->ReadU32());
    pDecoder->ReadBytes(reinterpret_cast<unsigned char*>(m_14), sizeof m_14);
    m_34 = static_cast<int>(pDecoder->ReadU32());
    m_38 = static_cast<int>(pDecoder->ReadU32());
    m_3c = static_cast<int>(pDecoder->ReadU32());
    m_40 = static_cast<int>(pDecoder->ReadU32());
    m_44 = static_cast<int>(pDecoder->ReadU32());
    m_48 = pDecoder->ReadU8();
    FUN_1415fb750(pDecoder);
    return 1;
}

// MS2-PIN: ??0CNMFindUserRequestInfo@@QEAA@XZ 0x141574050
