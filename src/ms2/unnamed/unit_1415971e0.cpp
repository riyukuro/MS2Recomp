// Recovered from the Nexon Messenger client library. CNMRequestMultiChatSessionFunc constructors and serializers.
// MS2-UNIT: unit_1415971e0
// MS2-RANGE: 0x1415971e0-0x1415977c0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include <vector>
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

// @0x1415971e0
CNMRequestMultiChatSessionFunc::CNMRequestMultiChatSessionFunc()
    : CNMFunc(0xa002, 1, 0, 0)
{
    m_key.nLow = 0;
    m_key.nHigh = 0;
    m_50 = 0;
    m_54 = 0;
}

// @0x141597270
CNMRequestMultiChatSessionFunc::CNMRequestMultiChatSessionFunc(
    NMKey64 key, const std::vector<NMChatSessionTarget>& targets, int mode)
    : CNMFunc(0xa002, 1, 0, 0)
{
    m_key = key;
    m_targets = targets;
    m_50 = static_cast<unsigned int>(mode);
    m_54 = 0;
}

// MS2-FUNCTIONAL: framed encoder setup and cleanup match; local encoder storage differs in frame layout.
// @0x141597320
unsigned int CNMRequestMultiChatSessionFunc::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMRequestMultiChatSessionFunc::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}

// MS2-FUNCTIONAL: recovered format branch; direct calls replace indirect virtual dispatch.
// @0x141597380
unsigned int CNMRequestMultiChatSessionFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMRequestMultiChatSessionFunc::Encode(pEncoder, pStream);
    return CNMRequestMultiChatSessionFunc::EncodeFramed(pStream);
}

// MS2-FUNCTIONAL: field order and vector contents match; STL traversal codegen differs from the library.
// @0x1415973e0
unsigned int CNMRequestMultiChatSessionFunc::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMFunc::EncodeDispatch(pEncoder, pStream);
    if (FUN_1415fb700(this))
    {
        FUN_14156ac20(pEncoder, m_key.nLow);
        FUN_14156ac20(pEncoder, m_key.nHigh);
        FUN_14156ac20(pEncoder, m_50);
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_targets.size()));
        for (std::vector<NMChatSessionTarget>::const_iterator it = m_targets.begin(), itEnd = m_targets.end(); it != itEnd; ++it)
        {
            FUN_14156acb0(pEncoder, it->uIDCode);
            FUN_14156ac20(pEncoder, it->uVirtualIDCode);
            FUN_14156ac20(pEncoder, it->n0c);
        }
    }
    else if (FUN_1415fb720(this))
    {
        FUN_14156ac20(pEncoder, m_54);
    }
    FUN_1415f9990(pEncoder);
    return 1;
}

// MS2-FUNCTIONAL: framed decoder setup and cleanup match; local decoder storage differs in frame layout.
// @0x141597550
unsigned int CNMRequestMultiChatSessionFunc::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMRequestMultiChatSessionFunc::Decode(&decoder, pStream);
}

// MS2-FUNCTIONAL: framed decoder selection matches; direct dispatch replaces the indirect virtual call.
// @0x1415975e0
unsigned int CNMRequestMultiChatSessionFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMRequestMultiChatSessionFunc::DecodeFramed(pStream);
    return CNMRequestMultiChatSessionFunc::Decode(pDecoder, pStream);
}

// MS2-FUNCTIONAL: field order, vector clear and target reconstruction match; STL growth codegen differs.
// @0x141597640
unsigned int CNMRequestMultiChatSessionFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    if (FUN_1415fb700(this))
    {
        m_key.nLow = pDecoder->ReadU32();
        m_key.nHigh = pDecoder->ReadU32();
        m_50 = pDecoder->ReadU32();
        unsigned int count = pDecoder->ReadU32();
        m_targets.clear();
        for (unsigned int i = 0; i < count; ++i)
        {
            NMChatSessionTarget target;
            target.uIDCode = pDecoder->ReadU64();
            target.uVirtualIDCode = pDecoder->ReadU32();
            target.n0c = pDecoder->ReadU32();
            m_targets.push_back(target);
        }
    }
    else if (FUN_1415fb720(this))
    {
        m_54 = pDecoder->ReadU32();
    }
    return FUN_1415fb750(pDecoder);
}

// MS2-PIN: ??0CNMRequestMultiChatSessionFunc@@QEAA@XZ 0x1415971e0
// MS2-PIN: ??0CNMRequestMultiChatSessionFunc@@QEAA@UNMKey64@@AEBV?$vector@UNMChatSessionTarget@@V?$allocator@UNMChatSessionTarget@@@std@@@std@@H@Z 0x141597270
