// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// MS2-UNIT: ?\nmloginauthfunc.cpp
// MS2-RANGE: 0x1415a55b0-0x1415a5e90 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmobjects.h"
#include "ms2/ms2recover.h"

extern HRESULT Unk_CopyNullOnFail(char* dest, unsigned cch, const char* src);
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

// @0x1415a55b0
// MS2-FUNCTIONAL: initializes auth request 0x110f and clears the leading words of its buffers.
CNMLoginAuthFunc::CNMLoginAuthFunc()
    : CNMFunc(0x110f, 1, 0, 0)
{
    m_mode = 0;
    *reinterpret_cast<int*>(m_password) = 0;
    *reinterpret_cast<int*>(m_user) = 0;
    *reinterpret_cast<int*>(m_1134) = 0;
    m_11b4 = 0;
    m_value = 0;
    *reinterpret_cast<int*>(m_token) = 0;
    m_flags = 0;
    m_result = 0;
    m_timeout = 20000;
}

// @0x1415a56b0
// MS2-FUNCTIONAL: initializes mode 1 with password and value arguments.
CNMLoginAuthFunc::CNMLoginAuthFunc(const char* password, unsigned int value)
    : CNMFunc(0x110f, 1, 0, 0)
{
    m_mode = 1;
    Unk_CopyNullOnFail(m_password, sizeof(m_password), password);
    *reinterpret_cast<int*>(m_user) = 0;
    *reinterpret_cast<int*>(m_1134) = 0;
    m_11b4 = 0;
    m_value = static_cast<int>(value);
    *reinterpret_cast<int*>(m_token) = 0;
    m_flags = 0;
    m_result = 0;
    m_timeout = 20000;
}

// @0x1415a57c0
// MS2-FUNCTIONAL: initializes mode 2 with user, password, and value arguments.
CNMLoginAuthFunc::CNMLoginAuthFunc(const char* user, const char* password, unsigned int value)
    : CNMFunc(0x110f, 1, 0, 0)
{
    m_mode = 2;
    *reinterpret_cast<int*>(m_password) = 0;
    Unk_CopyNullOnFail(m_user, sizeof(m_user), user);
    Unk_CopyNullOnFail(m_1134, sizeof(m_1134), password);
    m_11b4 = 0;
    m_value = static_cast<int>(value);
    *reinterpret_cast<int*>(m_token) = 0;
    m_flags = 0;
    m_result = 0;
    m_timeout = 20000;
}

// @0x1415a58e0
// MS2-FUNCTIONAL: initializes mode 2 and copies the optional token and flags.
CNMLoginAuthFunc::CNMLoginAuthFunc(const char* user, const char* password, unsigned int value,
                                   const char* token, unsigned int flags)
    : CNMFunc(0x110f, 1, 0, 0)
{
    m_mode = 2;
    *reinterpret_cast<int*>(m_password) = 0;
    Unk_CopyNullOnFail(m_user, sizeof(m_user), user);
    Unk_CopyNullOnFail(m_1134, sizeof(m_1134), password);
    m_11b4 = 0;
    m_value = static_cast<int>(value);
    Unk_CopyNullOnFail(m_token, sizeof(m_token), token);
    m_flags = static_cast<int>(flags);
    m_result = 0;
    m_timeout = 20000;
}

// @0x1415a5a00
// MS2-FUNCTIONAL: initializes a framed encoder then delegates to Encode.
unsigned int CNMLoginAuthFunc::EncodeFramed(CNMStream* pStream)
{
    alignas(8) unsigned char encoder[0x18];
    FUN_14156bcb0(encoder, pStream, this);
    const unsigned int result = Encode(reinterpret_cast<CNMEncoder*>(encoder), pStream);
    FUN_14156bd50(encoder);
    return result;
}

// @0x1415a5a60
// MS2-FUNCTIONAL: dispatches encoding by the serializable format flag.
unsigned int CNMLoginAuthFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        Encode(pEncoder, pStream);
    else
        EncodeFramed(pStream);
    return 0;
}

// @0x1415a5ac0
// MS2-FUNCTIONAL: encodes credentials for requests and timeout/result for replies.
unsigned int CNMLoginAuthFunc::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMFunc::EncodeDispatch(pEncoder, pStream);
    if (FUN_1415fb700(this) == 0)
    {
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_timeout));
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_result));
    }
    else
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
    FUN_1415f9990(pEncoder);
    return 1;
}

// @0x1415a5bf0
// MS2-FUNCTIONAL: initializes a framed decoder, validates it, then decodes the reply.
unsigned int CNMLoginAuthFunc::DecodeFramed(CNMStream* pStream)
{
    alignas(8) unsigned char decoder[0x38];
    FUN_14156be10(decoder, pStream, this);
    unsigned int result = 0;
    if (FUN_1415fb750(decoder) != 0)
        result = Decode(reinterpret_cast<CNMSerializableDecoder*>(decoder), pStream);
    FUN_14156bf10(decoder);
    return result;
}

// @0x1415a5c80
// MS2-FUNCTIONAL: dispatches decoding according to decoder format.
unsigned int CNMLoginAuthFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        DecodeFramed(pStream);
    else
        Decode(pDecoder, pStream);
    return 0;
}

// @0x1415a5ce0
// MS2-FUNCTIONAL: decodes the credential payload or timeout/result reply fields.
unsigned int CNMLoginAuthFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    void** vftable = *reinterpret_cast<void***>(pDecoder);
    using ReadU32 = unsigned int(__fastcall*)(void*);
    using ReadString = void(__fastcall*)(void*, void*, unsigned int);
    if (FUN_1415fb700(this) == 0)
    {
        m_timeout = static_cast<int>(reinterpret_cast<ReadU32>(vftable[3])(pDecoder));
        m_result = static_cast<int>(reinterpret_cast<ReadU32>(vftable[3])(pDecoder));
    }
    else
    {
        m_mode = static_cast<int>(reinterpret_cast<ReadU32>(vftable[3])(pDecoder));
        reinterpret_cast<ReadString>(vftable[9])(pDecoder, m_password, sizeof(m_password));
        reinterpret_cast<ReadString>(vftable[9])(pDecoder, m_user, sizeof(m_user));
        reinterpret_cast<ReadString>(vftable[9])(pDecoder, m_1134, sizeof(m_1134));
        m_11b4 = static_cast<int>(reinterpret_cast<ReadU32>(vftable[3])(pDecoder));
        m_value = static_cast<int>(reinterpret_cast<ReadU32>(vftable[3])(pDecoder));
        reinterpret_cast<ReadString>(vftable[9])(pDecoder, m_token, sizeof(m_token));
        m_flags = static_cast<int>(reinterpret_cast<ReadU32>(vftable[3])(pDecoder));
    }
    return static_cast<unsigned int>(FUN_1415fb750(pDecoder));
}

// MS2-PIN: ??0CNMLoginAuthFunc@@QEAA@XZ 0x1415a55b0
