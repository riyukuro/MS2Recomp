// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Nexon Messenger chat message record (CNMChatMessage).
// MS2-UNIT: ?\nmchatmessage.cpp
// MS2-RANGE: 0x1415727c0-0x141572e00 .text$mn
// MS2-PIN: ??0CNMSerializableEncoder@@QEAA@PEAVCNMStream@@PEAVCNMSerializable@@@Z 0x14156bcb0
// MS2-PIN: ??1CNMSerializableEncoder@@QEAA@XZ 0x14156bd50
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmchatroomfunc.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/placeholder/nmencoder.h"
#include "ms2/ms2recover.h"

extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(CNMSerializableDecoder*);
extern unsigned int FUN_14156ac20(void*, unsigned int);
extern unsigned int FUN_14156ae30(void*, const char*);
extern unsigned int FUN_1415f9990(void*);
extern void* FUN_1415f39d0(void*);
extern void* FUN_1415f39a0(void*);
extern HRESULT Unk_CopyNullOnFail(char* dest, unsigned cch, const char* src);

// The chat record the second constructor copies from (only the fields it reads).
struct Unk_NmcRecord {
    char m_pad_00[0x10];
    int m_type;                 // +0x10 1 = notice, 2 = system
    int m_pad_14;
    int m_time;                 // +0x18
    int m_pad_1c;
    char m_name[0x10];          // +0x20
    char m_body[0x10];          // +0x30
    int m_flags;                // +0x40
};

// @0x1415727c0
CNMChatMessage::CNMChatMessage()
    : CNMSerializable(0x636d, 1, 1)
{
    m_10 = 0;
    m_14 = 0;
    memset(m_28, 0, sizeof(m_28));
    memset(m_68, 0, sizeof(m_68));
    memset(m_168, 0, sizeof(m_168));
    memset(m_268, 0, sizeof(m_268));
    m_668 = 0;
}

// @0x1415728a0
CNMChatMessage::CNMChatMessage(const void* record, int messageType)
    : CNMSerializable(0x636d, 1, 1)
{
    m_10 = messageType;
    m_14 = static_cast<const Unk_NmcRecord*>(record)->m_time;
    switch (static_cast<const Unk_NmcRecord*>(record)->m_type) {
    case 1:
        Unk_CopyNullOnFail(m_28, sizeof(m_28), "_NOTICE_");
        break;
    case 2:
        Unk_CopyNullOnFail(m_28, sizeof(m_28), "_SYSTEM_");
        break;
    default:
        Unk_CopyNullOnFail(m_28, sizeof(m_28), static_cast<const char*>(FUN_1415f39d0(const_cast<char*>(static_cast<const Unk_NmcRecord*>(record)->m_name))));
        break;
    }
    m_68[0] = 0;
    m_168[0] = 0;
    Unk_CopyNullOnFail(m_268, sizeof(m_268), static_cast<const char*>(FUN_1415f39a0(const_cast<char*>(static_cast<const Unk_NmcRecord*>(record)->m_body))));
    m_668 = static_cast<const Unk_NmcRecord*>(record)->m_flags;
}

// @0x141572a10
unsigned int CNMChatMessage::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMChatMessage::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}

// @0x141572a70
unsigned int CNMChatMessage::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMChatMessage::Encode(pEncoder, pStream);
    return CNMChatMessage::EncodeFramed(pStream);
}

// @0x141572ad0
unsigned int CNMChatMessage::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    (void)pStream;
    FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_10));
    FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_14));
    m_avatar.EncodeFramed(pStream);
    FUN_14156ae30(pEncoder, m_28);
    FUN_14156ae30(pEncoder, m_68);
    FUN_14156ae30(pEncoder, m_168);
    FUN_14156ae30(pEncoder, m_268);
    FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_668));
    FUN_1415f9990(pEncoder);
    return 1;
}

// @0x141572bc0
unsigned int CNMChatMessage::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMChatMessage::Decode(&decoder, pStream);
}

// @0x141572c50
unsigned int CNMChatMessage::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMChatMessage::DecodeFramed(pStream);
    return CNMChatMessage::Decode(pDecoder, pStream);
}

// @0x141572cb0
unsigned int CNMChatMessage::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    m_10 = static_cast<int>(pDecoder->ReadU32());
    m_14 = static_cast<int>(pDecoder->ReadU32());
    m_avatar.DecodeFramed(pStream);
    pDecoder->ReadStringBufAlias(m_28, sizeof(m_28));
    pDecoder->ReadStringBufAlias(m_68, sizeof(m_68));
    pDecoder->ReadStringBufAlias(m_168, sizeof(m_168));
    pDecoder->ReadStringBufAlias(m_268, sizeof(m_268));
    m_668 = static_cast<int>(pDecoder->ReadU32());
    return FUN_1415fb750(pDecoder);
}

// MS2-PIN: ??0CNMChatMessage@@QEAA@XZ 0x1415727c0
