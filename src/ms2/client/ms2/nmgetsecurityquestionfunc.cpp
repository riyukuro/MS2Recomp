// Recovered Nexon Messenger security question query.
// MS2-UNIT: ?\nmgetsecurityquestionfunc.cpp
// MS2-RANGE: 0x141585390-0x1415856c0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmfunc.h"
#include "ms2/placeholder/nmobjects.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/ms2recover.h"

extern void* FUN_1415f39e0(void*);
extern unsigned int FUN_1415fa080(void*);
extern void* FUN_1415f9fe0(void*);
extern int FUN_1415fb720(void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(void*);
extern void FUN_1415f9990(void*);
extern void FUN_14156ae30(void*, const void*);
extern void FUN_14156bcb0(void*, void*, void*);
extern void FUN_14156be10(void*, void*, void*);
extern void FUN_14156bd50(void*);

// MS2-FUNCTIONAL: initializes the security question request and its empty string.
// @0x141585390
CNMGetSecurityQuestionFunc::CNMGetSecurityQuestionFunc()
    : CNMFunc(0x2106, 1, 0, 0), m_30()
{
}

// MS2-FUNCTIONAL: frames encoding through the shared temporary encoder.
// @0x141585400
unsigned int CNMGetSecurityQuestionFunc::EncodeFramed(CNMStream* pStream)
{
    alignas(8) unsigned char encoder[0x18];
    FUN_14156bcb0(encoder, pStream, this);
    const unsigned int result = Encode(reinterpret_cast<CNMEncoder*>(encoder), pStream);
    FUN_14156bd50(encoder);
    return result;
}

// MS2-FUNCTIONAL: selects direct or framed encoding by format.
// @0x141585460
unsigned int CNMGetSecurityQuestionFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        Encode(pEncoder, pStream);
    else
        EncodeFramed(pStream);
    return 0;
}

// MS2-FUNCTIONAL: encodes the question text for response direction and terminates the record.
// @0x1415854c0
unsigned int CNMGetSecurityQuestionFunc::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMFunc::EncodeDispatch(pEncoder, pStream);
    if (FUN_1415fb720(this) != 0)
        FUN_14156ae30(pEncoder, FUN_1415f39e0(&m_30));
    FUN_1415f9990(pEncoder);
    return 1;
}

// MS2-FUNCTIONAL: validates the temporary decoder before decoding a framed reply.
// @0x141585530
unsigned int CNMGetSecurityQuestionFunc::DecodeFramed(CNMStream* pStream)
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
// @0x1415855c0
unsigned int CNMGetSecurityQuestionFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        DecodeFramed(pStream);
    else
        Decode(pDecoder, pStream);
    return 0;
}

// MS2-FUNCTIONAL: reads the returned question text when this direction carries a response.
// @0x141585620
unsigned int CNMGetSecurityQuestionFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    if (FUN_1415fb720(this) != 0)
    {
        void** vftable = *reinterpret_cast<void***>(pDecoder);
        using ReadString = void(__fastcall*)(void*, void*, unsigned int);
        reinterpret_cast<ReadString>(vftable[9])(pDecoder, FUN_1415f9fe0(&m_30), FUN_1415fa080(&m_30));
    }
    FUN_1415fb750(pDecoder);
    return 1;
}

// MS2-PIN: ??0CNMGetSecurityQuestionFunc@@QEAA@XZ 0x141585390
