// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// MS2-UNIT: unit_1415a0de0
// MS2-RANGE: 0x1415a0de0-0x1415a11a0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmobjects.h"
#include "ms2/ms2recover.h"

extern void FUN_14156bcb0(void*, void*, void*);
extern void FUN_14156bd50(void*);
extern void FUN_14156be10(void*, void*, void*);
extern void FUN_14156bf10(void*);
extern int FUN_1415fb700(void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(void*);
extern void FUN_14156ac20(void*, unsigned int);
extern void FUN_14156acb0(void*, unsigned long long);
extern void FUN_1415f9990(void*);

// @0x1415a0de0
// MS2-FUNCTIONAL: initializes the recovered 0xc006 request and zeroes its 16-byte target.
CNMGSInviteUserFunc::CNMGSInviteUserFunc()
    : CNMFunc(0xc006, 1, 0, 0), m_30(0), m_38(0), m_3c(0)
{
}

// @0x1415a0e50
// MS2-FUNCTIONAL: preserves request metadata and copies the recovered 16-byte target payload.
CNMGSInviteUserFunc::CNMGSInviteUserFunc(unsigned int n18, const unsigned char* target)
    : CNMFunc(0xc006, 1, static_cast<int>(n18), 0), m_30(0), m_38(0), m_3c(0)
{
    if (target) std::memcpy(&m_30, target, 0x10);
}

// @0x1415a0ec0
// MS2-FUNCTIONAL: framed encoder setup and cleanup match; local encoder storage differs.
unsigned int CNMGSInviteUserFunc::EncodeFramed(CNMStream* pStream)
{
    alignas(8) unsigned char encoder[0x18];
    FUN_14156bcb0(encoder, pStream, this);
    const unsigned int result = Encode(reinterpret_cast<CNMEncoder*>(encoder), pStream);
    FUN_14156bd50(encoder);
    return result;
}

// @0x1415a0f20
// MS2-FUNCTIONAL: preserves format dispatch; direct calls replace virtual slot dispatch.
unsigned int CNMGSInviteUserFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        Encode(pEncoder, pStream);
    else
        EncodeFramed(pStream);
    return 0;
}

// @0x1415a0f80
// MS2-FUNCTIONAL: writes the target's 64-bit value and two trailing words in wire order.
unsigned int CNMGSInviteUserFunc::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMFunc::EncodeDispatch(pEncoder, pStream);
    if (FUN_1415fb700(this) != 0)
    {
        FUN_14156acb0(pEncoder, static_cast<unsigned long long>(m_30));
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_38));
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_3c));
    }
    FUN_1415f9990(pEncoder);
    return 1;
}

// @0x1415a1010
// MS2-FUNCTIONAL: framed decoder setup and cleanup match; local decoder storage differs.
unsigned int CNMGSInviteUserFunc::DecodeFramed(CNMStream* pStream)
{
    alignas(8) unsigned char decoder[0x38];
    FUN_14156be10(decoder, pStream, this);
    unsigned int result = 0;
    if (FUN_1415fb750(decoder) != 0)
        result = Decode(reinterpret_cast<CNMSerializableDecoder*>(decoder), pStream);
    FUN_14156bf10(decoder);
    return result;
}

// @0x1415a10a0
// MS2-FUNCTIONAL: selects framed decoding when the decoder format is 2.
unsigned int CNMGSInviteUserFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        DecodeFramed(pStream);
    else
        Decode(pDecoder, pStream);
    return 0;
}

// @0x1415a1100
// MS2-FUNCTIONAL: restores target fields in wire order when this is a request.
unsigned int CNMGSInviteUserFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    if (FUN_1415fb700(this) != 0)
    {
        void** vftable = *reinterpret_cast<void***>(pDecoder);
        using ReadU64 = unsigned long long(__fastcall*)(void*);
        using ReadU32 = unsigned int(__fastcall*)(void*);
        m_30 = static_cast<long long>(reinterpret_cast<ReadU64>(vftable[4])(pDecoder));
        m_38 = static_cast<int>(reinterpret_cast<ReadU32>(vftable[3])(pDecoder));
        m_3c = static_cast<int>(reinterpret_cast<ReadU32>(vftable[3])(pDecoder));
    }
    return static_cast<unsigned int>(FUN_1415fb750(pDecoder));
}

// MS2-PIN: ??0CNMGSInviteUserFunc@@QEAA@XZ 0x1415a0de0
