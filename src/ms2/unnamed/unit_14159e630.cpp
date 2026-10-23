// Recovered from the Nexon Messenger client library: chat-room invite user request.
// MS2-UNIT: unit_14159e630
// MS2-RANGE: 0x14159e630-0x14159ea60 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmchatroomfunc.h"
#include "ms2/ms2recover.h"

extern int FUN_1415fb700(const void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(void*);
extern void FUN_1415f9990(void*);
extern void FUN_14156ae30(void*, const void*);
extern void FUN_14156bcb0(void*, void*, void*);
extern void FUN_14156bd50(void*);
extern void FUN_1415fbe70(void*, unsigned int, const char*);

// MS2-FUNCTIONAL: request code and empty string initialization match; vftable setup codegen differs.
// @0x14159e630
CNMCRInviteUserFunc::CNMCRInviteUserFunc()
    : CNMFunc(0xb007, 1, 0, 0)
{
    m_szUser[0] = '\0';
    m_szMessage[0] = '\0';
}

// MS2-FUNCTIONAL: request code and string payload initialization match; helper and base codegen differ.
// @0x14159e6a0
CNMCRInviteUserFunc::CNMCRInviteUserFunc(unsigned uSerialKey, const char* szUser, const char* szMessage)
    : CNMFunc(0xb007, 1, static_cast<int>(uSerialKey), 0)
{
    if (szUser)
        FUN_1415fbe70(m_szUser, sizeof(m_szUser), szUser);
    else
        m_szUser[0] = '\0';
    if (szMessage)
        FUN_1415fbe70(m_szMessage, sizeof(m_szMessage), szMessage);
    else
        m_szMessage[0] = '\0';
}

// MS2-FUNCTIONAL: framed encoder setup and cleanup match; local encoder storage differs.
// @0x14159e780
unsigned int CNMCRInviteUserFunc::EncodeFramed(CNMStream* pStream)
{
    alignas(8) unsigned char encoder[0x18];
    FUN_14156bcb0(encoder, pStream, this);
    const unsigned int result = Encode(reinterpret_cast<CNMEncoder*>(encoder), pStream);
    FUN_14156bd50(encoder);
    return result;
}

// MS2-FUNCTIONAL: recovered format branch; direct calls replace virtual dispatch.
// @0x14159e7e0
unsigned int CNMCRInviteUserFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        Encode(pEncoder, pStream);
    else
        EncodeFramed(pStream);
    return 0;
}

// MS2-FUNCTIONAL: request/reply string ordering and finish call match; direct dispatch replaces virtual calls.
// @0x14159e840
unsigned int CNMCRInviteUserFunc::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMFunc::EncodeDispatch(pEncoder, pStream);
    if (FUN_1415fb700(this) != 0)
    {
        FUN_14156ae30(pEncoder, m_szUser);
        FUN_14156ae30(pEncoder, m_szMessage);
    }
    FUN_1415f9990(pEncoder);
    return 1;
}

// MS2-FUNCTIONAL: decoder wrapper lifetime and validity branch match; local decoder storage differs.
// @0x14159e8c0
unsigned int CNMCRInviteUserFunc::DecodeFramed(CNMStream* pStream)
{
    alignas(8) unsigned char decoder[0x38];
    FUN_14156bcb0(decoder, pStream, this);
    unsigned int result = 0;
    if (FUN_1415fb750(decoder) != 0)
        result = Decode(reinterpret_cast<CNMSerializableDecoder*>(decoder), pStream);
    FUN_14156bd50(decoder);
    return result;
}

// MS2-FUNCTIONAL: recovered decoder format branch; direct calls replace virtual dispatch.
// @0x14159e950
unsigned int CNMCRInviteUserFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        DecodeFramed(pStream);
    else
        Decode(pDecoder, pStream);
    return 0;
}

// MS2-FUNCTIONAL: request/reply string fields and validity check match; direct dispatch replaces virtual calls.
// @0x14159e9b0
unsigned int CNMCRInviteUserFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    if (FUN_1415fb700(this) != 0)
    {
        void** vftable = *reinterpret_cast<void***>(pDecoder);
        using ReadString = void(__fastcall*)(void*, void*, unsigned int);
        reinterpret_cast<ReadString>(vftable[9])(pDecoder, m_szUser, sizeof(m_szUser));
        reinterpret_cast<ReadString>(vftable[9])(pDecoder, m_szMessage, sizeof(m_szMessage));
    }
    return FUN_1415fb750(pDecoder);
}

// MS2-PIN: ??0CNMCRInviteUserFunc@@QEAA@XZ 0x14159e630
