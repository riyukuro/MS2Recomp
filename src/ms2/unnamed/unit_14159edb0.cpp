// Recovered from the Nexon Messenger client library: send chat message request.
// MS2-UNIT: unit_14159edb0
// MS2-RANGE: 0x14159edb0-0x14159f220 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmchatroomfunc.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/placeholder/nmencoder.h"
#include "ms2/ms2recover.h"

extern int FUN_1415fb700(const void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(CNMSerializableDecoder*);
extern void FUN_1415f9990(void*);
extern void FUN_14156acb0(void*, unsigned __int64);
extern void FUN_14156bcb0(void*, void*, void*);
extern void FUN_14156be10(void*, void*, void*);
extern void FUN_14156bd50(void*);
extern void FUN_1415efea0(void*, const void*);

// @0x14159edb0
CNMCRSendChatMessageFunc::CNMCRSendChatMessageFunc()
    : CNMFunc(0xb009, 1, 0, 0), m_msg()
{
    memset(m_aKeys, 0, sizeof m_aKeys);
}

// @0x14159ee30
CNMCRSendChatMessageFunc::CNMCRSendChatMessageFunc(
    unsigned uSerialKey, const unsigned __int64* pKeys, const CNMChatMessage& msg)
    : CNMFunc(0xb009, 1, static_cast<int>(uSerialKey), 0), m_msg()
{
    if (pKeys)
        memcpy(m_aKeys, pKeys, sizeof m_aKeys);
    else
        memset(m_aKeys, 0, sizeof m_aKeys);
    FUN_1415efea0(&m_msg, &msg);
}

// @0x14159ef00
unsigned int CNMCRSendChatMessageFunc::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMCRSendChatMessageFunc::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}

// @0x14159ef60
unsigned int CNMCRSendChatMessageFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMCRSendChatMessageFunc::Encode(pEncoder, pStream);
    return CNMCRSendChatMessageFunc::EncodeFramed(pStream);
}

// @0x14159efc0
unsigned int CNMCRSendChatMessageFunc::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMFunc::EncodeDispatch(pEncoder, pStream);
    if (FUN_1415fb700(this) != 0)
    {
        for (unsigned int i = 0; i < 10; ++i)
            FUN_14156acb0(pEncoder, m_aKeys[i]);
        m_msg.EncodeFramed(pStream);
    }
    FUN_1415f9990(pEncoder);
    return 1;
}

// @0x14159f070
unsigned int CNMCRSendChatMessageFunc::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMCRSendChatMessageFunc::Decode(&decoder, pStream);
}

// @0x14159f100
unsigned int CNMCRSendChatMessageFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMCRSendChatMessageFunc::DecodeFramed(pStream);
    return CNMCRSendChatMessageFunc::Decode(pDecoder, pStream);
}

// @0x14159f160
unsigned int CNMCRSendChatMessageFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    if (FUN_1415fb700(this) != 0)
    {
        for (unsigned int i = 0; i < 10; ++i)
            m_aKeys[i] = pDecoder->ReadU64();
        m_msg.DecodeFramed(pStream);
    }
    return FUN_1415fb750(pDecoder);
}

// MS2-PIN: ??0CNMCRSendChatMessageFunc@@QEAA@XZ 0x14159edb0
