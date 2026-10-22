// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CNMFindUserFunc constructors and request/reply
// serialization, plus its CNMFindUserRequestInfo payload supplied by the NM library.
// MS2-UNIT: unit_1415960e0
// MS2-RANGE: 0x1415960e0-0x1415964b0 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmobjects.h"
#include "ms2/ms2recover.h"

extern int FUN_1415fb700(const void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(void*);
extern void FUN_14156ac20(void*, unsigned int);
extern void FUN_1415f9990(void*);
extern void* FUN_14156bcb0(void*, void*, void*);
extern void FUN_14156bd50(void*);
extern void* FUN_1415f0b10(void*, const void*);

// @0x1415960e0
CNMFindUserFunc::CNMFindUserFunc() : CNMFunc(0x9002, 1, 0, 0), m_30()
{
    m_80 = 0;
}

// @0x141596150
CNMFindUserFunc::CNMFindUserFunc(const CNMFindUserRequestInfo& info) : CNMFunc(0x9002, 1, 0, 0), m_30()
{
    m_80 = 0;
    FUN_1415f0b10(&m_30, &info);
}

// MS2-FUNCTIONAL: framed encoder setup and cleanup follow the executable; local storage differs in stack frame.
// @0x1415961e0
unsigned int CNMFindUserFunc::EncodeFramed(CNMStream* pStream)
{
    alignas(8) unsigned char encoder[0x18];
    FUN_14156bcb0(encoder, pStream, this);
    const auto result = Encode(reinterpret_cast<CNMEncoder*>(encoder), pStream);
    FUN_14156bd50(encoder);
    return result;
}

// MS2-FUNCTIONAL: format branch and selected encoder slot match; direct calls replace indirect dispatch.
// @0x141596240
unsigned int CNMFindUserFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        Encode(pEncoder, pStream);
    else
        EncodeFramed(pStream);
    return 0;
}

// MS2-FUNCTIONAL: base fields, direction branch, payload serialization and finish marker are recovered.
// @0x1415962a0
unsigned int CNMFindUserFunc::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMFunc::EncodeDispatch(pEncoder, pStream);
    if (FUN_1415fb700(this) == 0)
        FUN_14156ac20(pEncoder, m_80);
    else
        m_30.Encode(pEncoder, pStream);
    FUN_1415f9990(pEncoder);
    return 1;
}

// MS2-FUNCTIONAL: decoder preflight, payload decode and cleanup follow the executable; local frame differs.
// @0x141596330
unsigned int CNMFindUserFunc::DecodeFramed(CNMStream* pStream)
{
    alignas(8) unsigned char decoder[0x38];
    FUN_14156bcb0(decoder, pStream, this);
    unsigned int result = 0;
    if (FUN_1415fb750(decoder))
        result = Decode(reinterpret_cast<CNMSerializableDecoder*>(decoder), pStream);
    FUN_14156bd50(decoder);
    return result;
}

// MS2-FUNCTIONAL: same format selection and decode slot; direct calls replace indirect dispatch.
// @0x1415963c0
unsigned int CNMFindUserFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        DecodeFramed(pStream);
    else
        Decode(pDecoder, pStream);
    return 0;
}

// MS2-FUNCTIONAL: reply scalar read, request payload decode and decoder status are recovered.
// @0x141596420
unsigned int CNMFindUserFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    if (FUN_1415fb700(this) == 0)
    {
        using ReadU32 = unsigned int(__fastcall*)(void*);
        void** vftable = *reinterpret_cast<void***>(pDecoder);
        m_80 = reinterpret_cast<ReadU32>(vftable[3])(pDecoder);
    }
    else
    {
        m_30.Decode(pDecoder, pStream);
    }
    return FUN_1415fb750(pDecoder);
}

// MS2-PIN: ??0CNMFindUserFunc@@QEAA@XZ 0x1415960e0
// MS2-PIN: ??0CNMFindUserFunc@@QEAA@AEBVCNMFindUserRequestInfo@@@Z 0x141596150
