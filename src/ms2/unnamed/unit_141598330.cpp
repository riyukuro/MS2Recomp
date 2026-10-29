// Recovered from the Nexon Messenger client library. CNMRequestChatSessionExFunc constructors and serializers.
// MS2-UNIT: unit_141598330
// MS2-RANGE: 0x141598330-0x141598820 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmobjects.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/placeholder/nmencoder.h"
#include "ms2/ms2recover.h"

extern int FUN_1415fb700(const void*);
extern int FUN_1415fb720(const void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(CNMSerializableDecoder*);
extern void FUN_1415f9990(void*);
extern void FUN_14156ac20(void*, unsigned int);
extern void FUN_14156acb0(void*, unsigned __int64);
extern void* FUN_14156bcb0(void*, void*, void*);
extern void FUN_14156bd50(void*);

// MS2-FUNCTIONAL: base and request field initialization match; vftable setup differs in codegen.
// @0x141598330
CNMRequestChatSessionExFunc::CNMRequestChatSessionExFunc()
    : CNMFunc(0xa00b, 1, 0, 0), m_30(0), m_38(0), m_3c(0), m_40(0), m_44(0), m_48(0), m_4c(0), m_50(0), m_54(0)
{
}

// @0x1415983d0
CNMRequestChatSessionExFunc::CNMRequestChatSessionExFunc(const unsigned char* pTarget, int nTarget)
    : CNMFunc(0xa00b, 1, 0, 0), m_30(0), m_38(0), m_3c(0), m_40(0), m_44(0), m_48(nTarget), m_4c(0), m_50(0), m_54(0)
{
    *reinterpret_cast<unsigned __int64*>(&m_30) = *reinterpret_cast<const unsigned __int64*>(pTarget);
    *reinterpret_cast<unsigned __int64*>(reinterpret_cast<unsigned char*>(&m_30) + 8) =
        *reinterpret_cast<const unsigned __int64*>(pTarget + 8);
    *reinterpret_cast<unsigned __int64*>(reinterpret_cast<unsigned char*>(&m_30) + 16) =
        *reinterpret_cast<const unsigned __int64*>(pTarget + 16);
}

// MS2-FUNCTIONAL: framed encoder setup and cleanup match; local encoder storage differs in frame layout.
// @0x141598460
unsigned int CNMRequestChatSessionExFunc::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMRequestChatSessionExFunc::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}

// MS2-FUNCTIONAL: recovered format branch; direct calls replace indirect virtual dispatch.
// @0x1415984c0
unsigned int CNMRequestChatSessionExFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMRequestChatSessionExFunc::Encode(pEncoder, pStream);
    return CNMRequestChatSessionExFunc::EncodeFramed(pStream);
}

// @0x141598520
unsigned int CNMRequestChatSessionExFunc::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMFunc::EncodeDispatch(pEncoder, pStream);
    if (FUN_1415fb700(this) != 0)
    {
        FUN_14156acb0(pEncoder, m_30);
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_38));
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_3c));
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_40));
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_44));
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_48));
    }
    else if (FUN_1415fb720(this) != 0)
    {
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_4c));
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_50));
    }
    FUN_1415f9990(pEncoder);
    return 1;
}

// MS2-FUNCTIONAL: framed decoder setup and cleanup match; local decoder storage differs in frame layout.
// @0x141598610
unsigned int CNMRequestChatSessionExFunc::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMRequestChatSessionExFunc::Decode(&decoder, pStream);
}

// MS2-FUNCTIONAL: framed decoder selection matches; direct dispatch replaces the indirect virtual call.
// @0x1415986a0
unsigned int CNMRequestChatSessionExFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMRequestChatSessionExFunc::DecodeFramed(pStream);
    return CNMRequestChatSessionExFunc::Decode(pDecoder, pStream);
}

// @0x141598700
unsigned int CNMRequestChatSessionExFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    if (FUN_1415fb700(this) != 0)
    {
        m_30 = pDecoder->ReadU64();
        m_38 = pDecoder->ReadU32();
        m_3c = pDecoder->ReadU32();
        m_40 = pDecoder->ReadU32();
        m_44 = pDecoder->ReadU32();
        m_48 = pDecoder->ReadU32();
    }
    else if (FUN_1415fb720(this) != 0)
    {
        m_4c = pDecoder->ReadU32();
        m_50 = pDecoder->ReadU32();
    }
    return FUN_1415fb750(pDecoder);
}

// MS2-PIN: ??0CNMRequestChatSessionExFunc@@QEAA@XZ 0x141598330
// MS2-PIN: ??0CNMRequestChatSessionExFunc@@QEAA@PEBEH@Z 0x1415983d0
