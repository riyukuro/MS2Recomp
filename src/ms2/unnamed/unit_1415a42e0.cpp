// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// MS2-UNIT: unit_1415a42e0
// MS2-RANGE: 0x1415a42e0-0x1415a4b30 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmobjects.h"
#include "ms2/ms2recover.h"

extern int FUN_1415fbe70(void*, long long, void*);
extern void FUN_14156bcb0(void*, void*, void*);
extern void FUN_14156bd50(void*);
extern void FUN_14156be10(void*, void*, void*);
extern void FUN_14156bf10(void*);
extern int FUN_1415fb700(void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(void*);
extern void FUN_14156ae30(void*, void*);
extern void FUN_14156ac20(void*, unsigned int);
extern void FUN_14156acb0(void*, unsigned long long);
extern void FUN_14156af60(void*, void*, unsigned int);
extern void FUN_1415f9990(void*);

static void copyPassportText(char* dest, const char* text)
{
    if (text == nullptr)
        *reinterpret_cast<unsigned int*>(dest) = 0;
    else
        FUN_1415fbe70(dest, 0x40, const_cast<char*>(text));
}

static int clampPassportPayload(int size)
{
    return size < 0x1000 ? size : 0x1000;
}

static void copyPassportPayload(unsigned char* dest, const unsigned char* data, int size)
{
    for (int i = 0; i < 0x1000; ++i)
        dest[i] = 0;
    for (int i = 0; i < size; ++i)
        dest[i] = data[i];
}

// @0x1415a42e0
// MS2-FUNCTIONAL: initializes the recovered 0x110a request fields and payload defaults.
CNMLoginPassportFunc::CNMLoginPassportFunc()
    : CNMFunc(0x110a, 1, 0, 1), m_30{}, m_70{}, m_b0(0), m_b8(0), m_c0{},
      m_80c0(0), m_80c4(0x10000), m_80c8(static_cast<int>(0x80000000u)), m_80cc(0)
{
}

// @0x1415a43c0
// MS2-FUNCTIONAL: copies both strings and bounded payload; preserves token and trailing flags.
CNMLoginPassportFunc::CNMLoginPassportFunc(const char* account, const char* passport,
                                           unsigned long long token, const unsigned char* payload,
                                           int payloadSize, unsigned int flags, unsigned int result)
    : CNMFunc(0x110a, 1, 0, 0), m_30{}, m_70{}, m_b0(0), m_b8(token), m_c0{},
      m_80c0(clampPassportPayload(payloadSize)), m_80c4(static_cast<int>(flags)),
      m_80c8(static_cast<int>(0x80000000u)), m_80cc(static_cast<int>(result))
{
    copyPassportText(m_30, account);
    copyPassportText(m_70, passport);
    copyPassportPayload(m_c0, payload, m_80c0);
}

// @0x1415a4560
// MS2-FUNCTIONAL: copies bounded payload and strings; token remains zero as recovered.
CNMLoginPassportFunc::CNMLoginPassportFunc(const char* account, const char* passport,
                                           const unsigned char* payload, int payloadSize,
                                           unsigned int flags, unsigned int result)
    : CNMFunc(0x110a, 1, 0, 0), m_30{}, m_70{}, m_b0(0), m_b8(0), m_c0{},
      m_80c0(clampPassportPayload(payloadSize)), m_80c8(static_cast<int>(flags)),
      m_80cc(static_cast<int>(result))
{
    copyPassportText(m_30, account);
    copyPassportText(m_70, passport);
    copyPassportPayload(m_c0, payload, m_80c0);
}

// @0x1415a4700
// MS2-FUNCTIONAL: framed encoder setup and cleanup match; local encoder storage differs.
unsigned int CNMLoginPassportFunc::EncodeFramed(CNMStream* pStream)
{
    alignas(8) unsigned char encoder[0x18];
    FUN_14156bcb0(encoder, pStream, this);
    const unsigned int result = Encode(reinterpret_cast<CNMEncoder*>(encoder), pStream);
    FUN_14156bd50(encoder);
    return result;
}

// @0x1415a4760
// MS2-FUNCTIONAL: preserves format dispatch; direct calls replace virtual slot dispatch.
unsigned int CNMLoginPassportFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        Encode(pEncoder, pStream);
    else
        EncodeFramed(pStream);
    return 0;
}

// @0x1415a47c0
// MS2-FUNCTIONAL: encodes strings, token, bounded payload, and option fields in wire order.
unsigned int CNMLoginPassportFunc::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMFunc::EncodeDispatch(pEncoder, pStream);
    if (FUN_1415fb700(this) != 0)
    {
        FUN_14156ae30(pEncoder, m_30);
        FUN_14156ae30(pEncoder, m_70);
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_b0));
        FUN_14156acb0(pEncoder, m_b8);
        FUN_14156af60(pEncoder, m_c0, static_cast<unsigned int>(m_80c0));
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_80c4));
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_80c8));
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_80cc));
    }
    FUN_1415f9990(pEncoder);
    return 1;
}

// @0x1415a48d0
// MS2-FUNCTIONAL: framed decoder setup, validity check, and cleanup match; local decoder storage differs.
unsigned int CNMLoginPassportFunc::DecodeFramed(CNMStream* pStream)
{
    alignas(8) unsigned char decoder[0x38];
    FUN_14156be10(decoder, pStream, this);
    unsigned int result = 0;
    if (FUN_1415fb750(decoder) != 0)
        result = Decode(reinterpret_cast<CNMSerializableDecoder*>(decoder), pStream);
    FUN_14156bf10(decoder);
    return result;
}

// @0x1415a4960
// MS2-FUNCTIONAL: selects framed decoding for decoder format 2.
unsigned int CNMLoginPassportFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        DecodeFramed(pStream);
    else
        Decode(pDecoder, pStream);
    return 0;
}

// @0x1415a49c0
// MS2-FUNCTIONAL: restores all fields and the payload bounded at 0x1000 bytes.
unsigned int CNMLoginPassportFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    if (FUN_1415fb700(this) != 0)
    {
        void** vftable = *reinterpret_cast<void***>(pDecoder);
        using ReadU32 = unsigned int(__fastcall*)(void*);
        using ReadU64 = unsigned long long(__fastcall*)(void*);
        using ReadString = void(__fastcall*)(void*, void*, unsigned int);
        using ReadBytes = unsigned int(__fastcall*)(void*, void*, unsigned int);
        reinterpret_cast<ReadString>(vftable[9])(pDecoder, m_30, 0x40);
        reinterpret_cast<ReadString>(vftable[9])(pDecoder, m_70, 0x40);
        m_b0 = static_cast<int>(reinterpret_cast<ReadU32>(vftable[3])(pDecoder));
        m_b8 = reinterpret_cast<ReadU64>(vftable[4])(pDecoder);
        m_80c0 = static_cast<int>(reinterpret_cast<ReadBytes>(vftable[11])(pDecoder, m_c0, 0x1000));
        m_80c4 = static_cast<int>(reinterpret_cast<ReadU32>(vftable[3])(pDecoder));
        m_80c8 = static_cast<int>(reinterpret_cast<ReadU32>(vftable[3])(pDecoder));
        m_80cc = static_cast<int>(reinterpret_cast<ReadU32>(vftable[3])(pDecoder));
    }
    return static_cast<unsigned int>(FUN_1415fb750(pDecoder));
}

// MS2-PIN: ??0CNMLoginPassportFunc@@QEAA@XZ 0x1415a42e0
// MS2-PIN: ??0CNMLoginPassportFunc@@QEAA@PEBD0_KPEBEHII@Z 0x1415a43c0
// MS2-PIN: ??0CNMLoginPassportFunc@@QEAA@PEBD0PEBEHII@Z 0x1415a4560
