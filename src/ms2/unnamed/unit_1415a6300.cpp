// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// MS2-UNIT: unit_1415a6300
// MS2-RANGE: 0x1415a6300-0x1415a6730 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmobjects.h"
#include "ms2/ms2recover.h"

extern void FUN_1415e5a20(void*);
extern void FUN_1415e59e0(void*, const void*);
extern void* FUN_1415f39c0(void*);
extern unsigned int FUN_1415fa060(void*);
extern void* FUN_1415f9fa0(void*);
extern void FUN_14156bcb0(void*, void*, void*);
extern void FUN_14156bd50(void*);
extern void FUN_14156be10(void*, void*, void*);
extern void FUN_14156bf10(void*);
extern int FUN_1415fb700(void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(void*);
extern void FUN_14156ac20(void*, unsigned int);
extern void FUN_14156ae30(void*, const void*);

// @0x1415a6300
// MS2-FUNCTIONAL: initializes request 0x1113, token string, timeout, and result.
CNMGetGameTokenFunc::CNMGetGameTokenFunc()
    : CNMFunc(0x1113, 1, 0, 0), m_30(), m_38(20000), m_3c(0)
{
    FUN_1415e5a20(&m_30);
}

// @0x1415a6380
// MS2-FUNCTIONAL: initializes request 0x1113 with the supplied token string.
CNMGetGameTokenFunc::CNMGetGameTokenFunc(const char* token)
    : CNMFunc(0x1113, 1, 0, 0), m_30(), m_38(0), m_3c(0)
{
    FUN_1415e59e0(&m_30, token);
}

// @0x1415a6410
// MS2-FUNCTIONAL: initializes a framed encoder then delegates to Encode.
unsigned int CNMGetGameTokenFunc::EncodeFramed(CNMStream* pStream)
{
    alignas(8) unsigned char encoder[0x18];
    FUN_14156bcb0(encoder, pStream, this);
    const unsigned int result = Encode(reinterpret_cast<CNMEncoder*>(encoder), pStream);
    FUN_14156bd50(encoder);
    return result;
}

// @0x1415a6470
// MS2-FUNCTIONAL: dispatches encoding by the serializable format flag.
unsigned int CNMGetGameTokenFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        Encode(pEncoder, pStream);
    else
        EncodeFramed(pStream);
    return 0;
}

// @0x1415a64d0
// MS2-FUNCTIONAL: encodes timeout and result for replies, or token for requests.
unsigned int CNMGetGameTokenFunc::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMFunc::EncodeDispatch(pEncoder, pStream);
    if (FUN_1415fb700(this) == 0)
    {
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_38));
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_3c));
    }
    else
        FUN_14156ae30(pEncoder, FUN_1415f39c0(&m_30));
    return 1;
}

// @0x1415a6570
// MS2-FUNCTIONAL: initializes a framed decoder, validates it, then decodes the reply.
unsigned int CNMGetGameTokenFunc::DecodeFramed(CNMStream* pStream)
{
    alignas(8) unsigned char decoder[0x38];
    FUN_14156be10(decoder, pStream, this);
    unsigned int result = 0;
    if (FUN_1415fb750(decoder) != 0)
        result = Decode(reinterpret_cast<CNMSerializableDecoder*>(decoder), pStream);
    FUN_14156bf10(decoder);
    return result;
}

// @0x1415a6600
// MS2-FUNCTIONAL: dispatches decoding according to decoder format.
unsigned int CNMGetGameTokenFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        DecodeFramed(pStream);
    else
        Decode(pDecoder, pStream);
    return 0;
}

// @0x1415a6660
// MS2-FUNCTIONAL: decodes timeout/result replies or the returned token string.
unsigned int CNMGetGameTokenFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    void** vftable = *reinterpret_cast<void***>(pDecoder);
    using ReadU32 = unsigned int(__fastcall*)(void*);
    using ReadString = void(__fastcall*)(void*, void*, unsigned int);
    if (FUN_1415fb700(this) == 0)
    {
        m_38 = static_cast<int>(reinterpret_cast<ReadU32>(vftable[3])(pDecoder));
        m_3c = static_cast<int>(reinterpret_cast<ReadU32>(vftable[3])(pDecoder));
    }
    else
        reinterpret_cast<ReadString>(vftable[9])(pDecoder, FUN_1415f9fa0(&m_30), FUN_1415fa060(&m_30));
    return static_cast<unsigned int>(FUN_1415fb750(pDecoder));
}

// MS2-PIN: ??0CNMGetGameTokenFunc@@QEAA@XZ 0x1415a6300
