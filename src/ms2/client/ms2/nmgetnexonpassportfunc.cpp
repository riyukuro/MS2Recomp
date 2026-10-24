// Recovered Nexon Messenger Nexon Passport query.
// MS2-UNIT: ?\nmgetnexonpassportfunc.cpp
// MS2-RANGE: 0x141584d00-0x1415850a0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmfunc.h"
#include "ms2/placeholder/nmobjects.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/ms2recover.h"

extern int FUN_1415fb700(void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(void*);
extern void FUN_1415f9990(void*);
extern void FUN_14156ac20(void*, unsigned int);
extern void FUN_14156ae30(void*, const void*);
extern void FUN_14156bcb0(void*, void*, void*);
extern void FUN_14156be10(void*, void*, void*);
extern void FUN_14156bd50(void*);

// MS2-FUNCTIONAL: initializes the query code and clears the first passport byte.
// @0x141584d00
CNMGetNexonPassportFunc::CNMGetNexonPassportFunc()
    : CNMFunc(0x2105, 1, 0, 0), m_30(0)
{
    m_34[0] = 0;
}

// MS2-FUNCTIONAL: initializes the query with its passport value.
// @0x141584d70
CNMGetNexonPassportFunc::CNMGetNexonPassportFunc(int passport)
    : CNMFunc(0x2105, 1, 0, 0), m_30(passport)
{
    m_34[0] = 0;
}

// MS2-FUNCTIONAL: frames passport query encoding through the shared encoder.
// @0x141584de0
unsigned int CNMGetNexonPassportFunc::EncodeFramed(CNMStream* pStream)
{
    alignas(8) unsigned char encoder[0x18];
    FUN_14156bcb0(encoder, pStream, this);
    const unsigned int result = Encode(reinterpret_cast<CNMEncoder*>(encoder), pStream);
    FUN_14156bd50(encoder);
    return result;
}

// MS2-FUNCTIONAL: selects direct or framed encoding.
// @0x141584e40
unsigned int CNMGetNexonPassportFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        Encode(pEncoder, pStream);
    else
        EncodeFramed(pStream);
    return 0;
}

// MS2-FUNCTIONAL: writes the request code or reply passport string by direction.
// @0x141584ea0
unsigned int CNMGetNexonPassportFunc::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMFunc::EncodeDispatch(pEncoder, pStream);
    if (FUN_1415fb700(this) == 0)
        FUN_14156ae30(pEncoder, m_34);
    else
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_30));
    FUN_1415f9990(pEncoder);
    return 1;
}

// MS2-FUNCTIONAL: validates framed passport decoding.
// @0x141584f20
unsigned int CNMGetNexonPassportFunc::DecodeFramed(CNMStream* pStream)
{
    alignas(8) unsigned char decoder[0x38];
    FUN_14156be10(decoder, pStream, this);
    unsigned int result = 0;
    if (FUN_1415fb750(decoder) != 0)
        result = Decode(reinterpret_cast<CNMSerializableDecoder*>(decoder), pStream);
    FUN_14156bd50(decoder);
    return result;
}

// MS2-FUNCTIONAL: selects framed decoding for version two replies.
// @0x141584fb0
unsigned int CNMGetNexonPassportFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        DecodeFramed(pStream);
    else
        Decode(pDecoder, pStream);
    return 0;
}

// MS2-FUNCTIONAL: reads either the 0x1000-byte passport or numeric request value.
// @0x141585010
unsigned int CNMGetNexonPassportFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    if (FUN_1415fb700(this) == 0)
        pDecoder->ReadBytes(reinterpret_cast<unsigned char*>(m_34), 0x1000);
    else
        m_30 = static_cast<int>(pDecoder->ReadU32());
    FUN_1415fb750(pDecoder);
    return 1;
}

// MS2-PIN: ??0CNMGetNexonPassportFunc@@QEAA@XZ 0x141584d00
