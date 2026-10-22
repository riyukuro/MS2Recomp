// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CNMGetFindUserResultFunc constructors and its
// reply count plus vector of CNMFindUserInfo records.
// MS2-UNIT: unit_1415964b0
// MS2-RANGE: 0x1415964b0-0x141596980 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include <utility>
#include "ms2/placeholder/nmobjects.h"
#include "ms2/ms2recover.h"

extern int FUN_1415fb700(const void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(void*);
extern void FUN_14156ac20(void*, unsigned int);
extern void FUN_1415f9990(void*);
extern void* FUN_14156bcb0(void*, void*, void*);
extern void FUN_14156bd50(void*);

// @0x1415964b0
CNMGetFindUserResultFunc::CNMGetFindUserResultFunc() : CNMFunc(0x9003, 1, 0, 0), m_30(0), m_38()
{
}

// @0x141596520
CNMGetFindUserResultFunc::CNMGetFindUserResultFunc(int nResult)
    : CNMFunc(0x9003, 1, 0, 0), m_30(nResult), m_38()
{
}

// MS2-FUNCTIONAL: frame setup and cleanup match the executable; local encoder storage differs in frame layout.
// @0x141596590
unsigned int CNMGetFindUserResultFunc::EncodeFramed(CNMStream* pStream)
{
    alignas(8) unsigned char encoder[0x18];
    FUN_14156bcb0(encoder, pStream, this);
    const auto result = Encode(reinterpret_cast<CNMEncoder*>(encoder), pStream);
    FUN_14156bd50(encoder);
    return result;
}

// MS2-FUNCTIONAL: same format selection and serializer slots; direct calls replace indirect dispatch.
// @0x1415965f0
unsigned int CNMGetFindUserResultFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        Encode(pEncoder, pStream);
    else
        EncodeFramed(pStream);
    return 0;
}

// MS2-FUNCTIONAL: reply list count/records, request scalar, and encoder finish behavior are recovered.
// @0x141596650
unsigned int CNMGetFindUserResultFunc::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMFunc::EncodeDispatch(pEncoder, pStream);
    if (FUN_1415fb700(this) == 0)
    {
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_38.size()));
        for (auto& info : m_38)
            info.Encode(pEncoder, pStream);
    }
    else
    {
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_30));
    }
    FUN_1415f9990(pEncoder);
    return 1;
}

// MS2-FUNCTIONAL: framed decoder preflight, payload path, and cleanup are recovered; local frame differs.
// @0x141596750
unsigned int CNMGetFindUserResultFunc::DecodeFramed(CNMStream* pStream)
{
    alignas(8) unsigned char decoder[0x38];
    FUN_14156bcb0(decoder, pStream, this);
    unsigned int result = 0;
    if (FUN_1415fb750(decoder))
        result = Decode(reinterpret_cast<CNMSerializableDecoder*>(decoder), pStream);
    FUN_14156bd50(decoder);
    return result;
}

// MS2-FUNCTIONAL: the decoder format discriminator routes through the same direct/framed slots.
// @0x1415967e0
unsigned int CNMGetFindUserResultFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        DecodeFramed(pStream);
    else
        Decode(pDecoder, pStream);
    return 0;
}

// MS2-FUNCTIONAL: reply count/records, request scalar, and decoder validation behavior are recovered.
// @0x141596840
unsigned int CNMGetFindUserResultFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    if (FUN_1415fb700(this) == 0)
    {
        using ReadU32 = unsigned int(__fastcall*)(void*);
        void** vftable = *reinterpret_cast<void***>(pDecoder);
        const unsigned int count = reinterpret_cast<ReadU32>(vftable[3])(pDecoder);
        m_38.clear();
        for (unsigned int i = 0; i < count; ++i)
        {
            CNMFindUserInfo info;
            info.DecodeFramed(pStream);
            m_38.push_back(std::move(info));
        }
    }
    else
    {
        using ReadU32 = unsigned int(__fastcall*)(void*);
        void** vftable = *reinterpret_cast<void***>(pDecoder);
        m_30 = static_cast<int>(reinterpret_cast<ReadU32>(vftable[3])(pDecoder));
    }
    return FUN_1415fb750(pDecoder);
}

// MS2-PIN: ??0CNMGetFindUserResultFunc@@QEAA@XZ 0x1415964b0
// MS2-PIN: ??0CNMGetFindUserResultFunc@@QEAA@H@Z 0x141596520
