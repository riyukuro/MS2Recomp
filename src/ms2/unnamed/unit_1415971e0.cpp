// Recovered from the Nexon Messenger client library. CNMRequestMultiChatSessionFunc constructors and serializers.
// MS2-UNIT: unit_1415971e0
// MS2-RANGE: 0x1415971e0-0x1415977c0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include <vector>
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

// @0x1415971e0
CNMRequestMultiChatSessionFunc::CNMRequestMultiChatSessionFunc()
    : CNMFunc(0xa002, 1, 0, 0), m_key{0, 0}, m_targets(), m_50(0), m_54(0)
{
}

// @0x141597270
CNMRequestMultiChatSessionFunc::CNMRequestMultiChatSessionFunc(
    NMKey64 key, const std::vector<NMChatSessionTarget>& targets, int mode)
    : CNMFunc(0xa002, 1, 0, 0), m_key(key), m_targets(targets), m_50(static_cast<unsigned int>(mode)), m_54(0)
{
}

// MS2-FUNCTIONAL: framed encoder setup and cleanup match; local encoder storage differs in frame layout.
// @0x141597320
unsigned int CNMRequestMultiChatSessionFunc::EncodeFramed(CNMStream* pStream)
{
    alignas(8) unsigned char encoder[0x18];
    FUN_14156bcb0(encoder, pStream, this);
    const unsigned int result = Encode(reinterpret_cast<CNMEncoder*>(encoder), pStream);
    FUN_14156bd50(encoder);
    return result;
}

// MS2-FUNCTIONAL: recovered format branch; direct calls replace indirect virtual dispatch.
// @0x141597380
unsigned int CNMRequestMultiChatSessionFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        Encode(pEncoder, pStream);
    else
        EncodeFramed(pStream);
    return 0;
}

// MS2-FUNCTIONAL: field order and vector contents match; STL traversal codegen differs from the library.
// @0x1415973e0
unsigned int CNMRequestMultiChatSessionFunc::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMFunc::EncodeDispatch(pEncoder, pStream);
    if (FUN_1415fb700(this) == 0)
    {
        if (FUN_1415fb720(this) != 0)
            FUN_14156ac20(pEncoder, m_54);
    }
    else
    {
        FUN_14156ac20(pEncoder, m_key.nLow);
        FUN_14156ac20(pEncoder, m_key.nHigh);
        FUN_14156ac20(pEncoder, m_50);
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_targets.size()));
        for (const NMChatSessionTarget& target : m_targets)
        {
            FUN_14156acb0(pEncoder, target.uIDCode);
            FUN_14156ac20(pEncoder, target.uVirtualIDCode);
            FUN_14156ac20(pEncoder, target.n0c);
        }
    }
    FUN_1415f9990(pEncoder);
    return 1;
}

// MS2-FUNCTIONAL: framed decoder setup and cleanup match; local decoder storage differs in frame layout.
// @0x141597550
unsigned int CNMRequestMultiChatSessionFunc::DecodeFramed(CNMStream* pStream)
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
// @0x1415975e0
unsigned int CNMRequestMultiChatSessionFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        DecodeFramed(pStream);
    else
        Decode(pDecoder, pStream);
    return 0;
}

// MS2-FUNCTIONAL: field order, vector clear and target reconstruction match; STL growth codegen differs.
// @0x141597640
unsigned int CNMRequestMultiChatSessionFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    if (FUN_1415fb700(this) == 0)
    {
        if (FUN_1415fb720(this) != 0)
        {
            using ReadU32 = unsigned int(__fastcall*)(void*);
            void** vftable = *reinterpret_cast<void***>(pDecoder);
            m_54 = reinterpret_cast<ReadU32>(vftable[3])(pDecoder);
        }
    }
    else
    {
        using ReadU32 = unsigned int(__fastcall*)(void*);
        using ReadU64 = unsigned __int64(__fastcall*)(void*);
        void** vftable = *reinterpret_cast<void***>(pDecoder);
        m_key.nLow = reinterpret_cast<ReadU32>(vftable[3])(pDecoder);
        m_key.nHigh = reinterpret_cast<ReadU32>(vftable[3])(pDecoder);
        m_50 = reinterpret_cast<ReadU32>(vftable[3])(pDecoder);
        const unsigned int count = reinterpret_cast<ReadU32>(vftable[3])(pDecoder);
        m_targets.clear();
        for (unsigned int i = 0; i != count; ++i)
        {
            NMChatSessionTarget target{};
            target.uIDCode = reinterpret_cast<ReadU64>(vftable[4])(pDecoder);
            target.uVirtualIDCode = reinterpret_cast<ReadU32>(vftable[3])(pDecoder);
            target.n0c = reinterpret_cast<ReadU32>(vftable[3])(pDecoder);
            m_targets.push_back(target);
        }
    }
    return FUN_1415fb750(pDecoder);
}

// MS2-PIN: ??0CNMRequestMultiChatSessionFunc@@QEAA@XZ 0x1415971e0
// MS2-PIN: ??0CNMRequestMultiChatSessionFunc@@QEAA@UNMKey64@@AEBV?$vector@UNMChatSessionTarget@@V?$allocator@UNMChatSessionTarget@@@std@@@std@@H@Z 0x141597270
