// Recovered Nexon Messenger server information query.
// MS2-UNIT: ?\nmgetserverinfofunc.cpp
// MS2-RANGE: 0x1415859f0-0x1415860b0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmfunc.h"
#include "ms2/placeholder/nmobjects.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/ms2recover.h"

extern void FUN_1415e8880(void*);
extern void FUN_14156bcb0(void*, void*, void*);
extern void FUN_14156be10(void*, void*, void*);
extern void FUN_14156bd50(void*);
extern void FUN_14156ac20(void*, unsigned int);
extern void FUN_14156ab90(void*, unsigned short);
extern void FUN_14156ae30(void*, const void*);
extern void FUN_1415f9990(void*);
extern int FUN_1415fb700(void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(void*);
extern size_t FUN_14160bcf0(void*);
extern void* FUN_1415f39c0(void*);
extern void* FUN_1415f39f0(void*);
extern void* FUN_1415f9fa0(void*);
extern unsigned int FUN_1415fa060(void*);
extern void* FUN_1415fa000(void*);
extern unsigned int FUN_1415fa090(void*);
extern void FUN_1415eb5c0(void*);
extern void FUN_1415e5a20(void*);
extern void FUN_1415e5c00(void*);
extern void FUN_1415fb800(void*, unsigned int);
extern void FUN_1415fba10(void*, unsigned int);
extern void FUN_1415fb850(void*, void*);
extern void FUN_1415fb8a0(void*, unsigned short);
extern void FUN_14160b570(void*, void*);

// MS2-FUNCTIONAL: initializes the server query and its result vector.
// @0x1415859f0
CNMGetServerInfoFunc::CNMGetServerInfoFunc()
    : CNMFunc(0x801e, 1, 0, 0), m_30(0), m_34(0), m_requests()
{
    FUN_1415e8880(&m_requests);
}

// MS2-FUNCTIONAL: initializes the query with its server and channel values.
// @0x141585a50
CNMGetServerInfoFunc::CNMGetServerInfoFunc(int server, int channel)
    : CNMFunc(0x801e, 1, 0, 0), m_30(server), m_34(channel), m_requests()
{
    FUN_1415e8880(&m_requests);
}

// MS2-FUNCTIONAL: frames encoding through the shared temporary encoder.
// @0x141585ad0
unsigned int CNMGetServerInfoFunc::EncodeFramed(CNMStream* pStream)
{
    alignas(8) unsigned char encoder[0x18];
    FUN_14156bcb0(encoder, pStream, this);
    const unsigned int result = Encode(reinterpret_cast<CNMEncoder*>(encoder), pStream);
    FUN_14156bd50(encoder);
    return result;
}

// MS2-FUNCTIONAL: selects direct or framed encoding from the format flag.
// @0x141585b30
unsigned int CNMGetServerInfoFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        Encode(pEncoder, pStream);
    else
        EncodeFramed(pStream);
    return 0;
}

// MS2-FUNCTIONAL: writes the result records for replies or the server and channel request values.
// @0x141585b90
unsigned int CNMGetServerInfoFunc::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMFunc::EncodeDispatch(pEncoder, pStream);
    if (FUN_1415fb700(this) == 0)
    {
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(FUN_14160bcf0(&m_requests)));
        for (const auto& item : m_requests)
        {
            FUN_14156ac20(pEncoder, item.m_kind);
            FUN_14156ac20(pEncoder, item.m_flags);
            FUN_14156ae30(pEncoder, FUN_1415f39c0(const_cast<CNMStr<0x20>*>(&item.m_address.m_host)));
            FUN_14156ab90(pEncoder, item.m_address.m_port);
            FUN_14156ae30(pEncoder, FUN_1415f39f0(const_cast<CNMStr<0x800>*>(&item.m_info)));
        }
    }
    else
    {
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_30));
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_34));
    }
    FUN_1415f9990(pEncoder);
    return 1;
}

// MS2-FUNCTIONAL: validates framed input before decoding the reply.
// @0x141585dc0
unsigned int CNMGetServerInfoFunc::DecodeFramed(CNMStream* pStream)
{
    alignas(8) unsigned char decoder[0x38];
    FUN_14156be10(decoder, pStream, this);
    unsigned int result = 0;
    if (FUN_1415fb750(decoder) != 0)
        result = Decode(reinterpret_cast<CNMSerializableDecoder*>(decoder), pStream);
    FUN_14156bd50(decoder);
    return result;
}

// MS2-FUNCTIONAL: selects framed decoding for version two responses.
// @0x141585e50
unsigned int CNMGetServerInfoFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        DecodeFramed(pStream);
    else
        Decode(pDecoder, pStream);
    return 0;
}

// MS2-FUNCTIONAL: fills reply records or reads the server and channel request values.
// @0x141585eb0
unsigned int CNMGetServerInfoFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    void** vftable = *reinterpret_cast<void***>(pDecoder);
    using ReadU32 = unsigned int(__fastcall*)(void*);
    using ReadU16 = unsigned short(__fastcall*)(void*);
    using ReadString = void(__fastcall*)(void*, void*, unsigned int);
    if (FUN_1415fb700(this) == 0)
    {
        const unsigned int count = reinterpret_cast<ReadU32>(vftable[3])(pDecoder);
        for (unsigned int i = 0; i < count; ++i)
        {
            CNMSetServerInfoFunc::RequestInfo item;
            item.m_kind = reinterpret_cast<ReadU32>(vftable[3])(pDecoder);
            item.m_flags = reinterpret_cast<ReadU32>(vftable[3])(pDecoder);
            reinterpret_cast<ReadString>(vftable[9])(pDecoder,
                FUN_1415f9fa0(&item.m_address.m_host), FUN_1415fa060(&item.m_address.m_host));
            item.m_address.m_port = reinterpret_cast<ReadU16>(vftable[2])(pDecoder);
            reinterpret_cast<ReadString>(vftable[9])(pDecoder,
                FUN_1415fa000(&item.m_info), FUN_1415fa090(&item.m_info));
            m_requests.push_back(item);
        }
    }
    else
    {
        m_30 = static_cast<int>(reinterpret_cast<ReadU32>(vftable[3])(pDecoder));
        m_34 = static_cast<int>(reinterpret_cast<ReadU32>(vftable[3])(pDecoder));
    }
    return static_cast<unsigned int>(FUN_1415fb750(pDecoder));
}

// MS2-PIN: ??0CNMGetServerInfoFunc@@QEAA@XZ 0x1415859f0
// MS2-PIN: ??0CNMGetServerInfoFunc@@QEAA@HH@Z 0x141585a50
