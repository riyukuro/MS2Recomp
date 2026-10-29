// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// MS2-UNIT: unit_1415a42e0
// MS2-RANGE: 0x1415a42e0-0x1415a4b30 .text$mn
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
extern void FUN_14156af60(void*, void*, unsigned int);
extern void FUN_1415f9990(void*);

// @0x1415a42e0
// MS2-FUNCTIONAL: initializes the recovered 0x110a request fields and payload defaults.
CNMLoginPassportFunc::CNMLoginPassportFunc()
    : CNMFunc(0x110a, 1, 0, 1), m_30{}, m_70{}, m_b0(0), m_b8(0), m_c0{},
      m_80c0(0), m_80c4(0x10000), m_80c8(static_cast<int>(0x80000000u)), m_80cc(0)
{
}

// @0x1415a43c0
CNMLoginPassportFunc::CNMLoginPassportFunc(const char* account, const char* passport,
                                           unsigned long long token, const unsigned char* payload,
                                           int payloadSize, unsigned int flags, unsigned int result)
    : CNMFunc(0x110a, 1, 0, 0)
{
    if (account) FUN_1415fbe70(m_30, 0x40, const_cast<char*>(account));
    else m_30[0] = 0;
    if (passport) FUN_1415fbe70(m_70, 0x40, const_cast<char*>(passport));
    else m_70[0] = 0;
    m_b0 = 0;
    m_b8 = token;
    m_80c0 = payloadSize < 0x1000 ? payloadSize : 0x1000;
    memset(m_c0, 0, 0x1000);
    memcpy(m_c0, payload, m_80c0);
    m_80c4 = flags;
    m_80c8 = 0x80000000;
    m_80cc = result;
}

// @0x1415a4560
CNMLoginPassportFunc::CNMLoginPassportFunc(const char* account, const char* passport,
                                           const unsigned char* payload, int payloadSize,
                                           unsigned int flags, unsigned int result)
    : CNMFunc(0x110a, 1, 0, 0)
{
    if (account) FUN_1415fbe70(m_30, 0x40, const_cast<char*>(account));
    else m_30[0] = 0;
    if (passport) FUN_1415fbe70(m_70, 0x40, const_cast<char*>(passport));
    else m_70[0] = 0;
    m_b0 = 0;
    m_b8 = 0;
    m_80c0 = payloadSize < 0x1000 ? payloadSize : 0x1000;
    memset(m_c0, 0, 0x1000);
    memcpy(m_c0, payload, m_80c0);
    m_80c4 = m_80c4;
    m_80c8 = flags;
    m_80cc = result;
}

// @0x1415a4700
// MS2-FUNCTIONAL: framed encoder setup and cleanup match; local encoder storage differs.
unsigned int CNMLoginPassportFunc::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMLoginPassportFunc::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}

// @0x1415a4760
// MS2-FUNCTIONAL: preserves format dispatch; direct calls replace virtual slot dispatch.
unsigned int CNMLoginPassportFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMLoginPassportFunc::Encode(pEncoder, pStream);
    return CNMLoginPassportFunc::EncodeFramed(pStream);
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
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMLoginPassportFunc::Decode(&decoder, pStream);
}

// @0x1415a4960
// MS2-FUNCTIONAL: selects framed decoding for decoder format 2.
unsigned int CNMLoginPassportFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMLoginPassportFunc::DecodeFramed(pStream);
    return CNMLoginPassportFunc::Decode(pDecoder, pStream);
}

// @0x1415a49c0
unsigned int CNMLoginPassportFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    if (FUN_1415fb700(this) != 0)
    {
        pDecoder->ReadStringBufAlias(m_30, 0x40);
        pDecoder->ReadStringBufAlias(m_70, 0x40);
        m_b0 = pDecoder->ReadU32();
        m_b8 = pDecoder->ReadU64();
        m_80c0 = pDecoder->ReadBytes(m_c0, 0x1000);
        m_80c4 = pDecoder->ReadU32();
        m_80c8 = pDecoder->ReadU32();
        m_80cc = pDecoder->ReadU32();
    }
    return static_cast<unsigned int>(FUN_1415fb750(pDecoder));
}

// MS2-PIN: ??0CNMLoginPassportFunc@@QEAA@XZ 0x1415a42e0
// MS2-PIN: ??0CNMLoginPassportFunc@@QEAA@PEBD0_KPEBEHII@Z 0x1415a43c0
// MS2-PIN: ??0CNMLoginPassportFunc@@QEAA@PEBD0PEBEHII@Z 0x1415a4560
