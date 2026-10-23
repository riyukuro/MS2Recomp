// Nexon Messenger join-channel request serialization.
// MS2-UNIT: unit_14159c360
// MS2-RANGE: 0x14159c360-0x14159c950 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/placeholder/nmobjects.h"
#include "ms2/placeholder/nmfunc.h"
#include "ms2/ms2recover.h"

extern void FUN_14156bcb0(void*, void*, void*);
extern void FUN_14156bd50(void*);
extern void FUN_14156be10(void*, void*, void*);
extern void FUN_14156bf10(void*);
extern void FUN_14156ac20(void*, unsigned int);
extern void FUN_14156ab90(void*, unsigned short);
extern void FUN_14156ae30(void*, const void*);
extern void FUN_14156ab00(void*, unsigned char);
extern void FUN_1415f9990(void*);
extern int FUN_1415fb700(void*);
extern int FUN_1415fb720(void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(void*);
extern void* FUN_1415f39e0(void*);
extern void* FUN_1415f3990(void*);
extern unsigned int FUN_1415fa080(void*);
extern void* FUN_1415f9fe0(void*);
extern unsigned int FUN_1415fa030(void*);
extern void* FUN_1415f9f40(void*);

// MS2-FUNCTIONAL 0x14159c360: initializes request metadata and nested channel/member records.
// @0x14159c360
CNMJoinChannelFunc::CNMJoinChannelFunc()
    : CNMFunc(0xa011, 1, 0, 0), m_30(0), m_34(0), m_38(), m_40(), m_48(0), m_50(), m_b0(),
      m_e0(1), m_e4(0), m_e8(0), m_ec(0)
{
}

// MS2-FUNCTIONAL 0x14159c450: frames the join-channel request and calls its encoder slot.
// @0x14159c450
unsigned int CNMJoinChannelFunc::EncodeFramed(CNMStream* pStream)
{
    unsigned char storage[0x18];
    FUN_14156bcb0(storage, pStream, this);
    void** vtable = *reinterpret_cast<void***>(this);
    using Method = unsigned int(__fastcall*)(CNMJoinChannelFunc*, CNMEncoder*, CNMStream*);
    const unsigned int result = reinterpret_cast<Method>(vtable[2])(
        this, reinterpret_cast<CNMEncoder*>(storage), pStream);
    FUN_14156bd50(storage);
    return result;
}

// MS2-FUNCTIONAL 0x14159c4b0: selects direct or framed request encoding by format.
// @0x14159c4b0
unsigned int CNMJoinChannelFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    void** vtable = *reinterpret_cast<void***>(this);
    if (m_bFormat == 1) {
        using Method = unsigned int(__fastcall*)(CNMJoinChannelFunc*, CNMEncoder*, CNMStream*);
        return reinterpret_cast<Method>(vtable[2])(this, pEncoder, pStream);
    }
    using Framed = unsigned int(__fastcall*)(CNMJoinChannelFunc*, CNMStream*);
    return reinterpret_cast<Framed>(vtable[3])(this, pStream);
}

// MS2-FUNCTIONAL 0x14159c510: serializes join parameters, nested records, or reply IDs.
// @0x14159c510
unsigned int CNMJoinChannelFunc::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMFunc::EncodeDispatch(pEncoder, pStream);
    if (FUN_1415fb700(this)) {
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_30));
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_34));
        FUN_14156ae30(pEncoder, FUN_1415f39e0(&m_38));
        FUN_14156ae30(pEncoder, FUN_1415f3990(&m_40));
        FUN_14156ab90(pEncoder, static_cast<unsigned short>(m_48));
        m_50.EncodeFramed(pStream);
        m_b0.EncodeFramed(pStream);
        FUN_14156ab00(pEncoder, static_cast<unsigned char>(m_e0));
    } else if (FUN_1415fb720(this)) {
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_e4));
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_e8));
    }
    FUN_1415f9990(pEncoder);
    return 1;
}

// MS2-FUNCTIONAL 0x14159c680: decodes a framed join-channel reply.
// @0x14159c680
unsigned int CNMJoinChannelFunc::DecodeFramed(CNMStream* pStream)
{
    unsigned char storage[0x38];
    FUN_14156be10(storage, pStream, this);
    unsigned int result = 0;
    if (FUN_1415fb750(storage)) {
        void** vtable = *reinterpret_cast<void***>(this);
        using Method = unsigned int(__fastcall*)(CNMJoinChannelFunc*, CNMSerializableDecoder*, CNMStream*);
        result = reinterpret_cast<Method>(vtable[5])(
            this, reinterpret_cast<CNMSerializableDecoder*>(storage), pStream);
    }
    FUN_14156bf10(storage);
    return result;
}

// MS2-FUNCTIONAL 0x14159c710: selects raw or framed reply decoding by wire format.
// @0x14159c710
unsigned int CNMJoinChannelFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    void** vtable = *reinterpret_cast<void***>(this);
    if (FUN_1415fb6d0(pDecoder) == 2) {
        using Framed = unsigned int(__fastcall*)(CNMJoinChannelFunc*, CNMStream*);
        return reinterpret_cast<Framed>(vtable[6])(this, pStream);
    }
    using Method = unsigned int(__fastcall*)(CNMJoinChannelFunc*, CNMSerializableDecoder*, CNMStream*);
    return reinterpret_cast<Method>(vtable[5])(this, pDecoder, pStream);
}

// MS2-FUNCTIONAL 0x14159c770: restores the request fields, nested records, or reply IDs.
// @0x14159c770
unsigned int CNMJoinChannelFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    if (!FUN_1415fb700(this)) {
        if (FUN_1415fb720(this)) {
            void** vtable = *reinterpret_cast<void***>(pDecoder);
            using U32 = unsigned int(__fastcall*)(void*);
            m_e4 = static_cast<int>(reinterpret_cast<U32>(vtable[3])(pDecoder));
            m_e8 = static_cast<int>(reinterpret_cast<U32>(vtable[3])(pDecoder));
        }
    } else {
        void** vtable = *reinterpret_cast<void***>(pDecoder);
        using U32 = unsigned int(__fastcall*)(void*);
        using U16 = unsigned short(__fastcall*)(void*);
        using U8 = unsigned char(__fastcall*)(void*);
        using Bytes = void(__fastcall*)(void*, void*, unsigned int);
        m_30 = static_cast<int>(reinterpret_cast<U32>(vtable[3])(pDecoder));
        m_34 = static_cast<int>(reinterpret_cast<U32>(vtable[3])(pDecoder));
        reinterpret_cast<Bytes>(vtable[9])(pDecoder, FUN_1415f9fe0(&m_38), FUN_1415fa080(&m_38));
        reinterpret_cast<Bytes>(vtable[9])(pDecoder, FUN_1415f9f40(&m_40), FUN_1415fa030(&m_40));
        m_48 = static_cast<short>(reinterpret_cast<U16>(vtable[2])(pDecoder));
        m_50.DecodeFramed(pStream);
        m_b0.DecodeFramed(pStream);
        m_e0 = reinterpret_cast<U8>(vtable[1])(pDecoder);
    }
    return static_cast<unsigned int>(FUN_1415fb750(pDecoder));
}

// MS2-PIN: ??0CNMJoinChannelFunc@@QEAA@XZ 0x14159c360
// MS2-PIN: ?EncodeFramed@CNMJoinChannelFunc@@UEAAIPEAVCNMStream@@@Z 0x14159c450
// MS2-PIN: ?EncodeDispatch@CNMJoinChannelFunc@@UEAAIPEAVCNMEncoder@@PEAVCNMStream@@@Z 0x14159c4b0
// MS2-PIN: ?Encode@CNMJoinChannelFunc@@UEAAIPEAVCNMEncoder@@PEAVCNMStream@@@Z 0x14159c510
// MS2-PIN: ?DecodeFramed@CNMJoinChannelFunc@@UEAAIPEAVCNMStream@@@Z 0x14159c680
// MS2-PIN: ?DecodeDispatch@CNMJoinChannelFunc@@UEAAIPEAVCNMSerializableDecoder@@PEAVCNMStream@@@Z 0x14159c710
// MS2-PIN: ?Decode@CNMJoinChannelFunc@@UEAAIPEAVCNMSerializableDecoder@@PEAVCNMStream@@@Z 0x14159c770
