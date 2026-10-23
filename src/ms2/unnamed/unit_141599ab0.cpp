// Recovered from the Nexon Messenger client library. CNMReplySessionRequestFunc constructors and serializers.
// MS2-UNIT: unit_141599ab0
// MS2-RANGE: 0x141599ab0-0x141599e80 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmobjects.h"
#include "ms2/ms2recover.h"

extern int FUN_1415fb700(const void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(void*);
extern void FUN_1415f9990(void*);
extern void FUN_14156ac20(void*, unsigned int);
extern void FUN_14156acb0(void*, unsigned __int64);
extern void FUN_14156ab00(void*, unsigned char);
extern void* FUN_14156bcb0(void*, void*, void*);
extern void FUN_14156bd50(void*);

// @0x141599ab0
CNMReplySessionRequestFunc::CNMReplySessionRequestFunc()
    : CNMFunc(0xa005, 1, 0, 0), m_30(0), m_38(0), m_3c(0)
{
}

// @0x141599b20
CNMReplySessionRequestFunc::CNMReplySessionRequestFunc(unsigned __int64 nSession, int bReply)
    : CNMFunc(0xa005, 1, 0, 0), m_30(static_cast<long long>(nSession)), m_38(0), m_3c(bReply)
{
}

// MS2-FUNCTIONAL: framed encoder setup and cleanup match; local encoder storage differs in frame layout.
// @0x141599ba0
unsigned int CNMReplySessionRequestFunc::EncodeFramed(CNMStream* pStream)
{
    alignas(8) unsigned char encoder[0x18];
    FUN_14156bcb0(encoder, pStream, this);
    const unsigned int result = Encode(reinterpret_cast<CNMEncoder*>(encoder), pStream);
    FUN_14156bd50(encoder);
    return result;
}

// MS2-FUNCTIONAL: recovered format branch; direct calls replace indirect virtual dispatch.
// @0x141599c00
unsigned int CNMReplySessionRequestFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        Encode(pEncoder, pStream);
    else
        EncodeFramed(pStream);
    return 0;
}

// MS2-FUNCTIONAL: recovered request data and boolean field order match; direct calls differ in codegen.
// @0x141599c60
unsigned int CNMReplySessionRequestFunc::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMFunc::EncodeDispatch(pEncoder, pStream);
    if (FUN_1415fb700(this) != 0)
    {
        FUN_14156acb0(pEncoder, static_cast<unsigned __int64>(m_30));
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_38));
        FUN_14156ab00(pEncoder, static_cast<unsigned char>(m_3c));
    }
    FUN_1415f9990(pEncoder);
    return 1;
}

// MS2-FUNCTIONAL: framed decoder setup and cleanup match; local decoder storage differs in frame layout.
// @0x141599cf0
unsigned int CNMReplySessionRequestFunc::DecodeFramed(CNMStream* pStream)
{
    alignas(8) unsigned char decoder[0x38];
    FUN_14156bcb0(decoder, pStream, this);
    unsigned int result = 0;
    if (FUN_1415fb750(decoder) != 0)
        result = Decode(reinterpret_cast<CNMSerializableDecoder*>(decoder), pStream);
    FUN_14156bd50(decoder);
    return result;
}

// MS2-FUNCTIONAL: framed decoder selection matches; direct dispatch replaces the indirect virtual call.
// @0x141599d80
unsigned int CNMReplySessionRequestFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        DecodeFramed(pStream);
    else
        Decode(pDecoder, pStream);
    return 0;
}

// MS2-FUNCTIONAL: recovered request data and boolean reader calls match; indirect reader dispatch is preserved.
// @0x141599de0
unsigned int CNMReplySessionRequestFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    if (FUN_1415fb700(this) != 0)
    {
        using ReadU32 = unsigned int(__fastcall*)(void*);
        using ReadU64 = unsigned __int64(__fastcall*)(void*);
        using ReadBool = unsigned char(__fastcall*)(void*);
        void** vftable = *reinterpret_cast<void***>(pDecoder);
        m_30 = static_cast<long long>(reinterpret_cast<ReadU64>(vftable[4])(pDecoder));
        m_38 = static_cast<int>(reinterpret_cast<ReadU32>(vftable[3])(pDecoder));
        m_3c = reinterpret_cast<ReadBool>(vftable[1])(pDecoder);
    }
    return FUN_1415fb750(pDecoder);
}

// MS2-PIN: ??0CNMReplySessionRequestFunc@@QEAA@XZ 0x141599ab0
// MS2-PIN: ??0CNMReplySessionRequestFunc@@QEAA@_KH@Z 0x141599b20
