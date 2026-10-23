// Recovered from the Nexon Messenger client library. CNMRequestWBSessionExFunc constructors and serializers.
// MS2-UNIT: unit_141599560
// MS2-RANGE: 0x141599560-0x141599ab0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmobjects.h"
#include "ms2/ms2recover.h"

extern int FUN_1415fb700(const void*);
extern int FUN_1415fb720(const void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(void*);
extern void FUN_1415f9990(void*);
extern void FUN_14156ac20(void*, unsigned int);
extern void FUN_14156acb0(void*, unsigned __int64);
extern void* FUN_14156bcb0(void*, void*, void*);
extern void FUN_14156bd50(void*);

// @0x141599560
CNMRequestWBSessionExFunc::CNMRequestWBSessionExFunc()
    : CNMFunc(0xa00e, 1, 0, 0), m_30(0), m_38(0), m_3c(0), m_40(0), m_44(0), m_48(0), m_4c(0), m_50(0), m_54(0)
{
}

// @0x141599610
CNMRequestWBSessionExFunc::CNMRequestWBSessionExFunc(const unsigned char* pTarget, int n48, int n4c)
    : CNMFunc(0xa00e, 1, 0, 0), m_30(0), m_38(0), m_3c(0), m_40(0), m_44(0), m_48(n48), m_4c(n4c), m_50(0), m_54(0)
{
    *reinterpret_cast<unsigned __int64*>(&m_30) = *reinterpret_cast<const unsigned __int64*>(pTarget);
    *reinterpret_cast<unsigned __int64*>(&m_38) = *reinterpret_cast<const unsigned __int64*>(pTarget + 8);
    *reinterpret_cast<unsigned __int64*>(&m_40) = *reinterpret_cast<const unsigned __int64*>(pTarget + 16);
}

// MS2-FUNCTIONAL: framed encoder setup and cleanup match; local encoder storage differs in frame layout.
// @0x1415996b0
unsigned int CNMRequestWBSessionExFunc::EncodeFramed(CNMStream* pStream)
{
    alignas(8) unsigned char encoder[0x18];
    FUN_14156bcb0(encoder, pStream, this);
    const unsigned int result = Encode(reinterpret_cast<CNMEncoder*>(encoder), pStream);
    FUN_14156bd50(encoder);
    return result;
}

// MS2-FUNCTIONAL: recovered format branch; direct calls replace indirect virtual dispatch.
// @0x141599710
unsigned int CNMRequestWBSessionExFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        Encode(pEncoder, pStream);
    else
        EncodeFramed(pStream);
    return 0;
}

// MS2-FUNCTIONAL: request and reply fields are serialized in recovered order; direct calls differ in codegen.
// @0x141599770
unsigned int CNMRequestWBSessionExFunc::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMFunc::EncodeDispatch(pEncoder, pStream);
    if (FUN_1415fb700(this) == 0)
    {
        if (FUN_1415fb720(this) != 0)
        {
            FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_50));
            FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_54));
        }
    }
    else
    {
        FUN_14156acb0(pEncoder, static_cast<unsigned __int64>(m_30));
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_38));
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_3c));
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_40));
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_44));
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_48));
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_4c));
    }
    FUN_1415f9990(pEncoder);
    return 1;
}

// MS2-FUNCTIONAL: framed decoder setup and cleanup match; local decoder storage differs in frame layout.
// @0x141599880
unsigned int CNMRequestWBSessionExFunc::DecodeFramed(CNMStream* pStream)
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
// @0x141599910
unsigned int CNMRequestWBSessionExFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        DecodeFramed(pStream);
    else
        Decode(pDecoder, pStream);
    return 0;
}

// MS2-FUNCTIONAL: request and reply field reads match; indirect reader dispatch is preserved.
// @0x141599970
unsigned int CNMRequestWBSessionExFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    using ReadU32 = unsigned int(__fastcall*)(void*);
    using ReadU64 = unsigned __int64(__fastcall*)(void*);
    void** vftable = *reinterpret_cast<void***>(pDecoder);
    if (FUN_1415fb700(this) == 0)
    {
        if (FUN_1415fb720(this) != 0)
        {
            m_50 = static_cast<int>(reinterpret_cast<ReadU32>(vftable[3])(pDecoder));
            m_54 = static_cast<int>(reinterpret_cast<ReadU32>(vftable[3])(pDecoder));
        }
    }
    else
    {
        m_30 = static_cast<long long>(reinterpret_cast<ReadU64>(vftable[4])(pDecoder));
        m_38 = static_cast<int>(reinterpret_cast<ReadU32>(vftable[3])(pDecoder));
        m_3c = static_cast<int>(reinterpret_cast<ReadU32>(vftable[3])(pDecoder));
        m_40 = static_cast<int>(reinterpret_cast<ReadU32>(vftable[3])(pDecoder));
        m_44 = static_cast<int>(reinterpret_cast<ReadU32>(vftable[3])(pDecoder));
        m_48 = static_cast<int>(reinterpret_cast<ReadU32>(vftable[3])(pDecoder));
        m_4c = static_cast<int>(reinterpret_cast<ReadU32>(vftable[3])(pDecoder));
    }
    return FUN_1415fb750(pDecoder);
}

// MS2-PIN: ??0CNMRequestWBSessionExFunc@@QEAA@XZ 0x141599560
// MS2-PIN: ??0CNMRequestWBSessionExFunc@@QEAA@PEBEHH@Z 0x141599610
