// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// MS2-UNIT: unit_1415a6e90
// MS2-RANGE: 0x1415a6e90-0x1415a7300 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmobjects.h"
#include "ms2/ms2recover.h"

extern void FUN_1415e5980(void*);
extern void FUN_1415e5940(void*, const void*);
extern void FUN_1415e5a80(void*, const void*);
extern void* FUN_1415f39b0(void*);
extern void* FUN_1415f39d0(void*);
extern unsigned int FUN_1415fa050(void*);
extern void* FUN_1415f9f80(void*);
extern unsigned int FUN_1415fa070(void*);
extern void* FUN_1415f9fc0(void*);
extern void FUN_14156bcb0(void*, void*, void*);
extern void FUN_14156bd50(void*);
extern void FUN_14156be10(void*, void*, void*);
extern void FUN_14156bf10(void*);
extern int FUN_1415fb700(void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(void*);
extern void FUN_14156ac20(void*, unsigned int);
extern void FUN_14156ae30(void*, const void*);
extern void FUN_1415f9990(void*);

// @0x1415a6e90
// MS2-FUNCTIONAL: initializes request 0x1119 and constructs both token strings.
CNMTPATokenLoginFunc::CNMTPATokenLoginFunc()
    : CNMFunc(0x1119, 1, 0, 0), m_38(), m_40(20000)
{
    FUN_1415e5980(m_30);
}

// @0x1415a6f10
// MS2-FUNCTIONAL: initializes request 0x1119 and copies both supplied strings.
CNMTPATokenLoginFunc::CNMTPATokenLoginFunc(const char* account, const char* password)
    : CNMFunc(0x1119, 1, 0, 0), m_38(), m_40(20000)
{
    FUN_1415e5940(m_30, account);
    FUN_1415e5a80(&m_38, password);
}

// @0x1415a6fb0
// MS2-FUNCTIONAL: initializes a framed encoder then delegates to Encode.
unsigned int CNMTPATokenLoginFunc::EncodeFramed(CNMStream* pStream)
{
    alignas(8) unsigned char encoder[0x18];
    FUN_14156bcb0(encoder, pStream, this);
    const unsigned int result = Encode(reinterpret_cast<CNMEncoder*>(encoder), pStream);
    FUN_14156bd50(encoder);
    return result;
}

// @0x1415a7010
// MS2-FUNCTIONAL: dispatches encoding by the serializable format flag.
unsigned int CNMTPATokenLoginFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        Encode(pEncoder, pStream);
    else
        EncodeFramed(pStream);
    return 0;
}

// @0x1415a7070
// MS2-FUNCTIONAL: encodes timeout for replies or account and password for requests.
unsigned int CNMTPATokenLoginFunc::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMFunc::EncodeDispatch(pEncoder, pStream);
    if (FUN_1415fb700(this) == 0)
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_40));
    else
    {
        FUN_14156ae30(pEncoder, FUN_1415f39b0(m_30));
        FUN_14156ae30(pEncoder, FUN_1415f39d0(&m_38));
    }
    FUN_1415f9990(pEncoder);
    return 1;
}

// @0x1415a7110
// MS2-FUNCTIONAL: initializes a framed decoder, validates it, then decodes the response.
unsigned int CNMTPATokenLoginFunc::DecodeFramed(CNMStream* pStream)
{
    alignas(8) unsigned char decoder[0x38];
    FUN_14156be10(decoder, pStream, this);
    unsigned int result = 0;
    if (FUN_1415fb750(decoder) != 0)
        result = Decode(reinterpret_cast<CNMSerializableDecoder*>(decoder), pStream);
    FUN_14156bf10(decoder);
    return result;
}

// @0x1415a71a0
// MS2-FUNCTIONAL: dispatches decoding according to decoder format.
unsigned int CNMTPATokenLoginFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        DecodeFramed(pStream);
    else
        Decode(pDecoder, pStream);
    return 0;
}

// @0x1415a7200
// MS2-FUNCTIONAL: decodes timeout for replies or fills both account strings.
unsigned int CNMTPATokenLoginFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    if (FUN_1415fb700(this) == 0)
        m_40 = static_cast<int>(reinterpret_cast<unsigned int(__fastcall*)(void*)>(
            (*reinterpret_cast<void***>(pDecoder))[3])(pDecoder));
    else
    {
        void** vftable = *reinterpret_cast<void***>(pDecoder);
        using ReadString = void(__fastcall*)(void*, void*, unsigned int);
        reinterpret_cast<ReadString>(vftable[9])(pDecoder, FUN_1415f9f80(m_30), FUN_1415fa050(m_30));
        reinterpret_cast<ReadString>(vftable[9])(pDecoder, FUN_1415f9fc0(&m_38), FUN_1415fa070(&m_38));
    }
    return static_cast<unsigned int>(FUN_1415fb750(pDecoder));
}

// MS2-PIN: ??0CNMTPATokenLoginFunc@@QEAA@XZ 0x1415a6e90
