// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// MS2-UNIT: ?\nmlogoutauthfunc.cpp
// MS2-RANGE: 0x1415a6730-0x1415a6ab0 .text$mn
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
extern void FUN_14156ab00(void*, unsigned char);
extern void FUN_14156ac20(void*, unsigned int);

// @0x1415a6730
// MS2-FUNCTIONAL: initializes logout-auth request 0x1110 and clears both values.
CNMLogoutAuthFunc::CNMLogoutAuthFunc()
    : CNMFunc(0x1110, 1, 0, 0), m_30(0), m_34(0)
{
}

// @0x1415a6790
// MS2-FUNCTIONAL: initializes logout-auth request 0x1110 with flag and value.
CNMLogoutAuthFunc::CNMLogoutAuthFunc(unsigned char flag, unsigned int value)
    : CNMFunc(0x1110, 1, 0, 0), m_30(flag), m_34(static_cast<int>(value))
{
}

// @0x1415a6800
// MS2-FUNCTIONAL: initializes a framed encoder then delegates to Encode.
unsigned int CNMLogoutAuthFunc::EncodeFramed(CNMStream* pStream)
{
    alignas(8) unsigned char encoder[0x18];
    FUN_14156bcb0(encoder, pStream, this);
    const unsigned int result = Encode(reinterpret_cast<CNMEncoder*>(encoder), pStream);
    FUN_14156bd50(encoder);
    return result;
}

// @0x1415a6860
// MS2-FUNCTIONAL: dispatches encoding by the serializable format flag.
unsigned int CNMLogoutAuthFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        Encode(pEncoder, pStream);
    else
        EncodeFramed(pStream);
    return 0;
}

// @0x1415a68c0
// MS2-FUNCTIONAL: encodes the byte flag and trailing value when the request is valid.
unsigned int CNMLogoutAuthFunc::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMFunc::EncodeDispatch(pEncoder, pStream);
    if (FUN_1415fb700(this) != 0)
    {
        FUN_14156ab00(pEncoder, static_cast<unsigned char>(m_30));
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_34));
    }
    return 1;
}

// @0x1415a6940
// MS2-FUNCTIONAL: initializes a framed decoder, validates it, then decodes the response.
unsigned int CNMLogoutAuthFunc::DecodeFramed(CNMStream* pStream)
{
    alignas(8) unsigned char decoder[0x38];
    FUN_14156be10(decoder, pStream, this);
    unsigned int result = 0;
    if (FUN_1415fb750(decoder) != 0)
        result = Decode(reinterpret_cast<CNMSerializableDecoder*>(decoder), pStream);
    FUN_14156bf10(decoder);
    return result;
}

// @0x1415a69d0
// MS2-FUNCTIONAL: dispatches decoding according to decoder format.
unsigned int CNMLogoutAuthFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        DecodeFramed(pStream);
    else
        Decode(pDecoder, pStream);
    return 0;
}

// @0x1415a6a30
// MS2-FUNCTIONAL: restores the byte flag and trailing value when the response is valid.
unsigned int CNMLogoutAuthFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    if (FUN_1415fb700(this) != 0)
    {
        void** vftable = *reinterpret_cast<void***>(pDecoder);
        using ReadU8 = unsigned char(__fastcall*)(void*);
        using ReadU32 = unsigned int(__fastcall*)(void*);
        m_30 = reinterpret_cast<ReadU8>(vftable[1])(pDecoder);
        m_34 = static_cast<int>(reinterpret_cast<ReadU32>(vftable[3])(pDecoder));
    }
    return static_cast<unsigned int>(FUN_1415fb750(pDecoder));
}

// MS2-PIN: ??0CNMLogoutAuthFunc@@QEAA@XZ 0x1415a6730
