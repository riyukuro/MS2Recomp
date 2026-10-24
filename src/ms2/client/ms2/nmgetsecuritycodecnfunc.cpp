// Recovered Nexon Messenger China security code query.
// MS2-UNIT: ?\nmgetsecuritycodecnfunc.cpp
// MS2-RANGE: 0x1415850a0-0x141585390 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmfunc.h"
#include "ms2/placeholder/nmobjects.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/ms2recover.h"

extern int FUN_1415fb720(void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(void*);
extern void FUN_1415f9990(void*);
extern void FUN_14156ac20(void*, unsigned int);
extern void FUN_14156bcb0(void*, void*, void*);
extern void FUN_14156be10(void*, void*, void*);
extern void FUN_14156bd50(void*);

// MS2-FUNCTIONAL: initializes the China security code query fields.
// @0x1415850a0
CNMGetSecurityCodeCNFunc::CNMGetSecurityCodeCNFunc()
    : CNMFunc(0x2108, 1, 0, 0), m_30(0)
{
}

// MS2-FUNCTIONAL: frames encoding through the common temporary encoder.
// @0x141585100
unsigned int CNMGetSecurityCodeCNFunc::EncodeFramed(CNMStream* pStream)
{
    alignas(8) unsigned char encoder[0x18];
    FUN_14156bcb0(encoder, pStream, this);
    const unsigned int result = Encode(reinterpret_cast<CNMEncoder*>(encoder), pStream);
    FUN_14156bd50(encoder);
    return result;
}

// MS2-FUNCTIONAL: chooses direct or framed encoding by the format byte.
// @0x141585160
unsigned int CNMGetSecurityCodeCNFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        Encode(pEncoder, pStream);
    else
        EncodeFramed(pStream);
    return 0;
}

// MS2-FUNCTIONAL: serializes the response security code when this direction carries one.
// @0x1415851c0
unsigned int CNMGetSecurityCodeCNFunc::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMFunc::EncodeDispatch(pEncoder, pStream);
    if (FUN_1415fb720(this) != 0)
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_30));
    FUN_1415f9990(pEncoder);
    return 1;
}

// MS2-FUNCTIONAL: validates the temporary decoder before reading a framed response.
// @0x141585230
unsigned int CNMGetSecurityCodeCNFunc::DecodeFramed(CNMStream* pStream)
{
    alignas(8) unsigned char decoder[0x38];
    FUN_14156be10(decoder, pStream, this);
    unsigned int result = 0;
    if (FUN_1415fb750(decoder) != 0)
        result = Decode(reinterpret_cast<CNMSerializableDecoder*>(decoder), pStream);
    FUN_14156bd50(decoder);
    return result;
}

// MS2-FUNCTIONAL: routes version two replies through framed decoding.
// @0x1415852c0
unsigned int CNMGetSecurityCodeCNFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        DecodeFramed(pStream);
    else
        Decode(pDecoder, pStream);
    return 0;
}

// MS2-FUNCTIONAL: reads the response security code into the request object.
// @0x141585320
unsigned int CNMGetSecurityCodeCNFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    if (FUN_1415fb720(this) != 0)
        m_30 = static_cast<int>(pDecoder->ReadU32());
    FUN_1415fb750(pDecoder);
    return 1;
}

// MS2-PIN: ??0CNMGetSecurityCodeCNFunc@@QEAA@XZ 0x1415850a0
