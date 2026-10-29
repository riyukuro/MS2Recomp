// Recovered Nexon Messenger server information query.
// MS2-UNIT: ?\nmgetserverinfofunc.cpp
// MS2-RANGE: 0x1415859f0-0x1415860b0 .text$mn
// MS2-PIN: ??0CNMSerializableEncoder@@QEAA@PEAVCNMStream@@PEAVCNMSerializable@@@Z 0x14156bcb0
// MS2-PIN: ??1CNMSerializableEncoder@@QEAA@XZ 0x14156bd50
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmfunc.h"
#include "ms2/placeholder/nmobjects.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/placeholder/nmencoder.h"
#include "ms2/ms2recover.h"

extern void FUN_14156ac20(void*, unsigned int);
extern void FUN_14156ab90(void*, unsigned short);
extern void FUN_14156ae30(void*, const void*);
extern void FUN_1415f9990(void*);
extern int FUN_1415fb700(void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(CNMSerializableDecoder*);
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

// @0x1415859f0
CNMGetServerInfoFunc::CNMGetServerInfoFunc()
    : CNMFunc(0x801e, 1, 0, 0), m_requests()
{
}

// @0x141585a50
CNMGetServerInfoFunc::CNMGetServerInfoFunc(int server, int channel)
    : CNMFunc(0x801e, 1, 0, 0), m_30(server), m_34(channel), m_requests()
{
}

// @0x141585ad0
unsigned int CNMGetServerInfoFunc::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMGetServerInfoFunc::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}

// @0x141585b30
unsigned int CNMGetServerInfoFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMGetServerInfoFunc::Encode(pEncoder, pStream);
    return CNMGetServerInfoFunc::EncodeFramed(pStream);
}

// MS2-FUNCTIONAL: writes the result records for replies or the server and channel request values. The request
// loop sends kind, flags, host and port only (no info string). The exe reads them through folded accessor COMDATs.
// @0x141585b90
unsigned int CNMGetServerInfoFunc::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMFunc::EncodeDispatch(pEncoder, pStream);
    if (FUN_1415fb700(this))
    {
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_30));
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_34));
    }
    else
    {
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(FUN_14160bcf0(&m_requests)));
        for (const auto& item : m_requests)
        {
            FUN_14156ac20(pEncoder, item.m_kind);
            FUN_14156ac20(pEncoder, item.m_flags);
            FUN_14156ae30(pEncoder, FUN_1415f39c0(const_cast<CNMStr<0x20>*>(&item.m_address.m_host)));
            FUN_14156ab90(pEncoder, item.m_address.m_port);
        }
    }
    FUN_1415f9990(pEncoder);
    return 1;
}

// @0x141585dc0
unsigned int CNMGetServerInfoFunc::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMGetServerInfoFunc::Decode(&decoder, pStream);
}

// @0x141585e50
unsigned int CNMGetServerInfoFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMGetServerInfoFunc::DecodeFramed(pStream);
    return CNMGetServerInfoFunc::Decode(pDecoder, pStream);
}

// MS2-FUNCTIONAL: fills reply records or reads the server and channel request values. Each request carries kind,
// flags, host and port (no info string). The exe reads the host into a temp CNMStr and sets it through accessors.
// @0x141585eb0
unsigned int CNMGetServerInfoFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    if (FUN_1415fb700(this))
    {
        m_30 = static_cast<int>(pDecoder->ReadU32());
        m_34 = static_cast<int>(pDecoder->ReadU32());
    }
    else
    {
        const unsigned int count = pDecoder->ReadU32();
        for (unsigned int i = 0; i < count; ++i)
        {
            CNMSetServerInfoFunc::RequestInfo item;
            item.m_kind = pDecoder->ReadU32();
            item.m_flags = pDecoder->ReadU32();
            pDecoder->ReadStringBufAlias(static_cast<char*>(FUN_1415f9fa0(&item.m_address.m_host)), FUN_1415fa060(&item.m_address.m_host));
            item.m_address.m_port = pDecoder->ReadU16();
            m_requests.push_back(item);
        }
    }
    return static_cast<unsigned int>(FUN_1415fb750(pDecoder));
}

// MS2-PIN: ??0CNMGetServerInfoFunc@@QEAA@XZ 0x1415859f0
// MS2-PIN: ??0CNMGetServerInfoFunc@@QEAA@HH@Z 0x141585a50
