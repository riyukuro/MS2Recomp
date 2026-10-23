// Recovered from the Nexon Messenger client library: chat-room ban user request.
// MS2-UNIT: unit_14159ea60
// MS2-RANGE: 0x14159ea60-0x14159edb0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmchatroomfunc.h"
#include "ms2/ms2recover.h"

extern int FUN_1415fb700(const void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(void*);
extern void FUN_1415f9990(void*);
extern void FUN_14156acb0(void*, unsigned __int64);
extern void FUN_14156bcb0(void*, void*, void*);
extern void FUN_14156bd50(void*);

// MS2-FUNCTIONAL: request code and zero key initialization match; vftable setup codegen differs.
// @0x14159ea60
CNMCRBanUserFunc::CNMCRBanUserFunc()
    : CNMFunc(0xb008, 1, 0, 0), m_uUserKey(0)
{
}

// MS2-FUNCTIONAL: request code, serial key, and user key match; base constructor register width differs.
// @0x14159eac0
CNMCRBanUserFunc::CNMCRBanUserFunc(unsigned uSerialKey, unsigned __int64 uUserKey)
    : CNMFunc(0xb008, 1, static_cast<int>(uSerialKey), 0), m_uUserKey(uUserKey)
{
}

// MS2-FUNCTIONAL: framed encoder setup and cleanup match; local encoder storage differs.
// @0x14159eb20
unsigned int CNMCRBanUserFunc::EncodeFramed(CNMStream* pStream)
{
    alignas(8) unsigned char encoder[0x18];
    FUN_14156bcb0(encoder, pStream, this);
    const unsigned int result = Encode(reinterpret_cast<CNMEncoder*>(encoder), pStream);
    FUN_14156bd50(encoder);
    return result;
}

// MS2-FUNCTIONAL: recovered format branch; direct calls replace virtual dispatch.
// @0x14159eb80
unsigned int CNMCRBanUserFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        Encode(pEncoder, pStream);
    else
        EncodeFramed(pStream);
    return 0;
}

// MS2-FUNCTIONAL: key gate and 64-bit payload write match; direct dispatch replaces virtual calls.
// @0x14159ebe0
unsigned int CNMCRBanUserFunc::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMFunc::EncodeDispatch(pEncoder, pStream);
    if (FUN_1415fb700(this) != 0)
        FUN_14156acb0(pEncoder, m_uUserKey);
    FUN_1415f9990(pEncoder);
    return 1;
}

// MS2-FUNCTIONAL: decoder wrapper lifetime and validity branch match; local decoder storage differs.
// @0x14159ec50
unsigned int CNMCRBanUserFunc::DecodeFramed(CNMStream* pStream)
{
    alignas(8) unsigned char decoder[0x38];
    FUN_14156bcb0(decoder, pStream, this);
    unsigned int result = 0;
    if (FUN_1415fb750(decoder) != 0)
        result = Decode(reinterpret_cast<CNMSerializableDecoder*>(decoder), pStream);
    FUN_14156bd50(decoder);
    return result;
}

// MS2-FUNCTIONAL: recovered decoder format branch; direct calls replace virtual dispatch.
// @0x14159ece0
unsigned int CNMCRBanUserFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        DecodeFramed(pStream);
    else
        Decode(pDecoder, pStream);
    return 0;
}

// MS2-FUNCTIONAL: key gate, 64-bit read, and validity check match; direct dispatch replaces virtual calls.
// @0x14159ed40
unsigned int CNMCRBanUserFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    if (FUN_1415fb700(this) != 0)
    {
        void** vftable = *reinterpret_cast<void***>(pDecoder);
        using ReadU64 = unsigned __int64(__fastcall*)(void*);
        m_uUserKey = reinterpret_cast<ReadU64>(vftable[4])(pDecoder);
    }
    return FUN_1415fb750(pDecoder);
}

// MS2-PIN: ??0CNMCRBanUserFunc@@QEAA@XZ 0x14159ea60
