// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// MS2-UNIT: unit_1415a4b30
// MS2-RANGE: 0x1415a4b30-0x1415a4fc0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmobjects.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/placeholder/nmencoder.h"
#include "ms2/ms2recover.h"

extern int FUN_1415fbe70(void*, long long, void*);
extern void FUN_14156bcb0(void*, void*, void*);
extern void FUN_14156bd50(void*);
extern void FUN_14156be10(void*, void*, void*);
extern void FUN_14156bf10(void*);
extern int FUN_1415fb700(void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(CNMSerializableDecoder*);
extern void FUN_14156ae30(void*, void*);
extern void FUN_14156ac20(void*, unsigned int);
extern void FUN_14156acb0(void*, unsigned long long);
extern void FUN_1415f9990(void*);

// @0x1415a4b30
// MS2-FUNCTIONAL: initializes the 0x110c request and clears its passport string.
CNMLoginNexonPassportFunc::CNMLoginNexonPassportFunc()
    : CNMFunc(0x110c, 1, 0, 0), m_30{}, m_1030(0)
{
}

// @0x1415a4bc0
// MS2-FUNCTIONAL: copies the optional passport string and preserves token and result fields.
CNMLoginNexonPassportFunc::CNMLoginNexonPassportFunc(const char* passport,
                                                     unsigned long long token,
                                                     unsigned int result)
    : CNMFunc(0x110c, 1, 0, 0), m_30{}, m_1030(0), m_1038(token), m_1040(result)
{
    if (passport == nullptr)
        *reinterpret_cast<unsigned int*>(m_30) = 0;
    else
        FUN_1415fbe70(m_30, 0x1000, const_cast<char*>(passport));
}

// @0x1415a4c90
// MS2-FUNCTIONAL: framed encoder setup and cleanup match; local encoder storage differs.
unsigned int CNMLoginNexonPassportFunc::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMLoginNexonPassportFunc::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}

// @0x1415a4cf0
// MS2-FUNCTIONAL: preserves format dispatch; direct calls replace virtual slot dispatch.
unsigned int CNMLoginNexonPassportFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMLoginNexonPassportFunc::Encode(pEncoder, pStream);
    return CNMLoginNexonPassportFunc::EncodeFramed(pStream);
}

// @0x1415a4d50
// MS2-FUNCTIONAL: encodes passport, status, token, and result fields in wire order.
unsigned int CNMLoginNexonPassportFunc::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMFunc::EncodeDispatch(pEncoder, pStream);
    if (FUN_1415fb700(this) != 0)
    {
        FUN_14156ae30(pEncoder, m_30);
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_1030));
        FUN_14156acb0(pEncoder, m_1038);
        FUN_14156ac20(pEncoder, m_1040);
    }
    FUN_1415f9990(pEncoder);
    return 1;
}

// @0x1415a4e00
// MS2-FUNCTIONAL: framed decoder setup, validity check, and cleanup match; local decoder storage differs.
unsigned int CNMLoginNexonPassportFunc::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMLoginNexonPassportFunc::Decode(&decoder, pStream);
}

// @0x1415a4e90
// MS2-FUNCTIONAL: selects framed decoding for decoder format 2.
unsigned int CNMLoginNexonPassportFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMLoginNexonPassportFunc::DecodeFramed(pStream);
    return CNMLoginNexonPassportFunc::Decode(pDecoder, pStream);
}

// @0x1415a4ef0
// MS2-FUNCTIONAL: restores the passport string and trailing scalar fields.
unsigned int CNMLoginNexonPassportFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    if (FUN_1415fb700(this) != 0)
    {
        void** vftable = *reinterpret_cast<void***>(pDecoder);
        using ReadU32 = unsigned int(__fastcall*)(void*);
        using ReadU64 = unsigned long long(__fastcall*)(void*);
        using ReadString = void(__fastcall*)(void*, void*, unsigned int);
        reinterpret_cast<ReadString>(vftable[9])(pDecoder, m_30, 0x1000);
        m_1030 = static_cast<int>(reinterpret_cast<ReadU32>(vftable[3])(pDecoder));
        m_1038 = reinterpret_cast<ReadU64>(vftable[4])(pDecoder);
        m_1040 = reinterpret_cast<ReadU32>(vftable[3])(pDecoder);
    }
    return static_cast<unsigned int>(FUN_1415fb750(pDecoder));
}

// MS2-PIN: ??0CNMLoginNexonPassportFunc@@QEAA@XZ 0x1415a4b30
