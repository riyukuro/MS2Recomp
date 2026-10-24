// Recovered Nexon Messenger count request and reply.
// MS2-UNIT: ?\nmgetcountfunc.cpp
// MS2-RANGE: 0x141582980-0x141582d00 .text$mn
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
extern void FUN_14156bcb0(void*, void*, void*);
extern void FUN_14156be10(void*, void*, void*);
extern void FUN_14156bd50(void*);

// MS2-FUNCTIONAL: initializes a count request and reply with cleared fields.
// @0x141582980
CNMGetCountFunc::CNMGetCountFunc() : CNMFunc(0x2008, 1, 0, 0), m_30(0), m_34(0)
{
}

// MS2-FUNCTIONAL: initializes a count request with its requested value.
// @0x1415829e0
CNMGetCountFunc::CNMGetCountFunc(int count) : CNMFunc(0x2008, 1, 0, 0), m_30(count), m_34(0)
{
}

// MS2-FUNCTIONAL: frames encoding through the common temporary encoder.
// @0x141582a50
unsigned int CNMGetCountFunc::EncodeFramed(CNMStream* pStream)
{
    alignas(8) unsigned char encoder[0x18];
    FUN_14156bcb0(encoder, pStream, this);
    const unsigned int result = Encode(reinterpret_cast<CNMEncoder*>(encoder), pStream);
    FUN_14156bd50(encoder);
    return result;
}

// MS2-FUNCTIONAL: selects direct or framed encoding for the count record.
// @0x141582ab0
unsigned int CNMGetCountFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        Encode(pEncoder, pStream);
    else
        EncodeFramed(pStream);
    return 0;
}

// MS2-FUNCTIONAL: serializes the request or reply count according to direction.
// @0x141582b10
unsigned int CNMGetCountFunc::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMFunc::EncodeDispatch(pEncoder, pStream);
    FUN_14156ac20(pEncoder, static_cast<unsigned int>(
        FUN_1415fb700(this) == 0 ? m_34 : m_30));
    FUN_1415f9990(pEncoder);
    return 1;
}

// MS2-FUNCTIONAL: validates framed decoding before reading a count.
// @0x141582b90
unsigned int CNMGetCountFunc::DecodeFramed(CNMStream* pStream)
{
    alignas(8) unsigned char decoder[0x38];
    FUN_14156be10(decoder, pStream, this);
    unsigned int result = 0;
    if (FUN_1415fb750(decoder) != 0)
        result = Decode(reinterpret_cast<CNMSerializableDecoder*>(decoder), pStream);
    FUN_14156bd50(decoder);
    return result;
}

// MS2-FUNCTIONAL: selects framed decoding for version two count records.
// @0x141582c20
unsigned int CNMGetCountFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        DecodeFramed(pStream);
    else
        Decode(pDecoder, pStream);
    return 0;
}

// MS2-FUNCTIONAL: reads the count into the request or reply field by direction.
// @0x141582c80
unsigned int CNMGetCountFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    const int count = static_cast<int>(pDecoder->ReadU32());
    if (FUN_1415fb700(this) == 0)
        m_34 = count;
    else
        m_30 = count;
    FUN_1415fb750(pDecoder);
    return 1;
}

// MS2-PIN: ??0CNMGetCountFunc@@QEAA@XZ 0x141582980
