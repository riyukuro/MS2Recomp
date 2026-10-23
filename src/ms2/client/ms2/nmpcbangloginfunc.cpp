// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// MS2-UNIT: ?\nmpcbangloginfunc.cpp
// MS2-RANGE: 0x1415a6ab0-0x1415a6e90 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmobjects.h"
#include "ms2/ms2recover.h"

extern void FUN_1415e5860(void*);
extern void FUN_1415e5820(void*, const void*);
extern void* FUN_1415f3980(void*);
extern unsigned int FUN_1415fa020(void*);
extern void* FUN_1415f9f20(void*);
extern void FUN_14156bcb0(void*, void*, void*);
extern void FUN_14156bd50(void*);
extern void FUN_14156be10(void*, void*, void*);
extern void FUN_14156bf10(void*);
extern int FUN_1415fb700(void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(void*);
extern void FUN_14156ac20(void*, unsigned int);
extern void FUN_14156ae30(void*, const void*);

// @0x1415a6ab0
// MS2-FUNCTIONAL: initializes request 0x1115 with the empty PC-bang token and default timeout.
CNMPCBangLoginFunc::CNMPCBangLoginFunc()
    : CNMFunc(0x1115, 1, 0, 0), m_38(20000)
{
    FUN_1415e5860(&m_30);
}

// @0x1415a6b20
// MS2-FUNCTIONAL: initializes request 0x1115 with the supplied token and default timeout.
CNMPCBangLoginFunc::CNMPCBangLoginFunc(const char* token)
    : CNMFunc(0x1115, 1, 0, 0), m_38(20000)
{
    FUN_1415e5820(&m_30, token);
}

// @0x1415a6ba0
// MS2-FUNCTIONAL: initializes a framed encoder then delegates to Encode.
unsigned int CNMPCBangLoginFunc::EncodeFramed(CNMStream* pStream)
{
    alignas(8) unsigned char encoder[0x18];
    FUN_14156bcb0(encoder, pStream, this);
    const unsigned int result = Encode(reinterpret_cast<CNMEncoder*>(encoder), pStream);
    FUN_14156bd50(encoder);
    return result;
}

// @0x1415a6c00
// MS2-FUNCTIONAL: dispatches encoding by the serializable format flag.
unsigned int CNMPCBangLoginFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        Encode(pEncoder, pStream);
    else
        EncodeFramed(pStream);
    return 0;
}

// @0x1415a6c60
// MS2-FUNCTIONAL: encodes timeout for replies or the token for requests.
unsigned int CNMPCBangLoginFunc::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMFunc::EncodeDispatch(pEncoder, pStream);
    if (FUN_1415fb700(this) == 0)
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_38));
    else
        FUN_14156ae30(pEncoder, FUN_1415f3980(&m_30));
    return 1;
}

// @0x1415a6cf0
// MS2-FUNCTIONAL: initializes a framed decoder, validates it, then decodes the response.
unsigned int CNMPCBangLoginFunc::DecodeFramed(CNMStream* pStream)
{
    alignas(8) unsigned char decoder[0x38];
    FUN_14156be10(decoder, pStream, this);
    unsigned int result = 0;
    if (FUN_1415fb750(decoder) != 0)
        result = Decode(reinterpret_cast<CNMSerializableDecoder*>(decoder), pStream);
    FUN_14156bf10(decoder);
    return result;
}

// @0x1415a6d80
// MS2-FUNCTIONAL: dispatches decoding according to decoder format.
unsigned int CNMPCBangLoginFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        DecodeFramed(pStream);
    else
        Decode(pDecoder, pStream);
    return 0;
}

// @0x1415a6de0
// MS2-FUNCTIONAL: decodes timeout for replies or fills the token buffer.
unsigned int CNMPCBangLoginFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    if (FUN_1415fb700(this) == 0)
    {
        void** vftable = *reinterpret_cast<void***>(pDecoder);
        using ReadU32 = unsigned int(__fastcall*)(void*);
        m_38 = static_cast<int>(reinterpret_cast<ReadU32>(vftable[3])(pDecoder));
    }
    else
    {
        void** vftable = *reinterpret_cast<void***>(pDecoder);
        using ReadString = void(__fastcall*)(void*, void*, unsigned int);
        reinterpret_cast<ReadString>(vftable[9])(pDecoder, FUN_1415f9f20(&m_30), FUN_1415fa020(&m_30));
    }
    return static_cast<unsigned int>(FUN_1415fb750(pDecoder));
}

// MS2-PIN: ??0CNMPCBangLoginFunc@@QEAA@XZ 0x1415a6ab0
