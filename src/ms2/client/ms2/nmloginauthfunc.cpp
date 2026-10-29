// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// MS2-UNIT: ?\nmloginauthfunc.cpp
// MS2-RANGE: 0x1415a55b0-0x1415a5e90 .text$mn
// MS2-PIN: ??0CNMSerializableEncoder@@QEAA@PEAVCNMStream@@PEAVCNMSerializable@@@Z 0x14156bcb0
// MS2-PIN: ??1CNMSerializableEncoder@@QEAA@XZ 0x14156bd50
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmobjects.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/placeholder/nmencoder.h"
#include "ms2/ms2recover.h"

extern HRESULT Unk_CopyNullOnFail(char* dest, unsigned cch, const char* src);
extern int FUN_1415fb700(void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(CNMSerializableDecoder*);
extern void FUN_14156ac20(void*, unsigned int);
extern void FUN_14156ae30(void*, const void*);
extern void FUN_1415f9990(void*);

// @0x1415a55b0
CNMLoginAuthFunc::CNMLoginAuthFunc()
    : CNMFunc(0x110f, 1, 0, 0)
{
    m_mode = 0;
    m_password[0] = 0;
    m_user[0] = 0;
    m_1134[0] = 0;
    m_11b4 = 0;
    m_value = 0;
    m_token[0] = 0;
    m_timeout = 20000;
    m_flags = 0;
    m_result = 0;
}

// @0x1415a56b0
CNMLoginAuthFunc::CNMLoginAuthFunc(const char* password, unsigned int value)
    : CNMFunc(0x110f, 1, 0, 0)
{
    m_mode = 1;
    Unk_CopyNullOnFail(m_password, sizeof(m_password), password);
    m_user[0] = 0;
    m_1134[0] = 0;
    m_11b4 = 0;
    m_value = static_cast<int>(value);
    m_token[0] = 0;
    m_timeout = 20000;
    m_flags = 0;
    m_result = 0;
}

// @0x1415a57c0
CNMLoginAuthFunc::CNMLoginAuthFunc(const char* user, const char* password, unsigned int value)
    : CNMFunc(0x110f, 1, 0, 0)
{
    m_mode = 2;
    m_password[0] = 0;
    Unk_CopyNullOnFail(m_user, sizeof(m_user), user);
    Unk_CopyNullOnFail(m_1134, sizeof(m_1134), password);
    m_11b4 = 0;
    m_value = static_cast<int>(value);
    m_token[0] = 0;
    m_timeout = 20000;
    m_flags = 0;
    m_result = 0;
}

// @0x1415a58e0
CNMLoginAuthFunc::CNMLoginAuthFunc(const char* user, const char* password, unsigned int value,
                                   const char* token, unsigned int flags)
    : CNMFunc(0x110f, 1, 0, 0)
{
    m_mode = 2;
    m_password[0] = 0;
    Unk_CopyNullOnFail(m_user, sizeof(m_user), user);
    Unk_CopyNullOnFail(m_1134, sizeof(m_1134), password);
    m_11b4 = 0;
    m_value = static_cast<int>(value);
    Unk_CopyNullOnFail(m_token, sizeof(m_token), token);
    m_timeout = 20000;
    m_flags = static_cast<int>(flags);
    m_result = 0;
}

// @0x1415a5a00
unsigned int CNMLoginAuthFunc::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMLoginAuthFunc::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}

// @0x1415a5a60
unsigned int CNMLoginAuthFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMLoginAuthFunc::Encode(pEncoder, pStream);
    return CNMLoginAuthFunc::EncodeFramed(pStream);
}

// @0x1415a5ac0
unsigned int CNMLoginAuthFunc::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMFunc::EncodeDispatch(pEncoder, pStream);
    if (FUN_1415fb700(this))
    {
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_mode));
        FUN_14156ae30(pEncoder, m_password);
        FUN_14156ae30(pEncoder, m_user);
        FUN_14156ae30(pEncoder, m_1134);
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_11b4));
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_value));
        FUN_14156ae30(pEncoder, m_token);
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_flags));
    }
    else
    {
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_timeout));
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_result));
    }
    FUN_1415f9990(pEncoder);
    return 1;
}

// @0x1415a5bf0
unsigned int CNMLoginAuthFunc::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMLoginAuthFunc::Decode(&decoder, pStream);
}

// @0x1415a5c80
unsigned int CNMLoginAuthFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMLoginAuthFunc::DecodeFramed(pStream);
    return CNMLoginAuthFunc::Decode(pDecoder, pStream);
}

// @0x1415a5ce0
unsigned int CNMLoginAuthFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    if (FUN_1415fb700(this))
    {
        m_mode = static_cast<int>(pDecoder->ReadU32());
        pDecoder->ReadStringBufAlias(m_password, sizeof(m_password));
        pDecoder->ReadStringBufAlias(m_user, sizeof(m_user));
        pDecoder->ReadStringBufAlias(m_1134, sizeof(m_1134));
        m_11b4 = static_cast<int>(pDecoder->ReadU32());
        m_value = static_cast<int>(pDecoder->ReadU32());
        pDecoder->ReadStringBufAlias(m_token, sizeof(m_token));
        m_flags = static_cast<int>(pDecoder->ReadU32());
    }
    else
    {
        m_timeout = static_cast<int>(pDecoder->ReadU32());
        m_result = static_cast<int>(pDecoder->ReadU32());
    }
    return static_cast<unsigned int>(FUN_1415fb750(pDecoder));
}

// MS2-PIN: ??0CNMLoginAuthFunc@@QEAA@XZ 0x1415a55b0
