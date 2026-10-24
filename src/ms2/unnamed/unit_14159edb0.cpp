// Recovered from the Nexon Messenger client library: send chat message request.
// MS2-UNIT: unit_14159edb0
// MS2-RANGE: 0x14159edb0-0x14159f220 .text$mn
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
extern void FUN_14156acb0(void*, unsigned __int64);
extern void FUN_14156bcb0(void*, void*, void*);
extern void FUN_14156be10(void*, void*, void*);
extern void FUN_14156bd50(void*);
extern void FUN_1415efea0(void*, const void*);

// MS2-FUNCTIONAL: initializes the chat-message request and its embedded message.
// @0x14159edb0
CNMCRSendChatMessageFunc::CNMCRSendChatMessageFunc()
    : CNMFunc(0xb009, 1, 0, 0), m_aKeys{}, m_msg()
{
}

// MS2-FUNCTIONAL: initializes request fields, copies ten recipient keys, and assigns the message payload.
// @0x14159ee30
CNMCRSendChatMessageFunc::CNMCRSendChatMessageFunc(
    unsigned uSerialKey, const unsigned __int64* pKeys, const CNMChatMessage& msg)
    : CNMFunc(0xb009, 1, static_cast<int>(uSerialKey), 0), m_aKeys{}, m_msg()
{
    if (pKeys)
        memcpy(m_aKeys, pKeys, sizeof m_aKeys);
    FUN_1415efea0(&m_msg, &msg);
}

// MS2-FUNCTIONAL: framed encoder setup, payload dispatch, and cleanup match; local encoder storage differs.
// @0x14159ef00
unsigned int CNMCRSendChatMessageFunc::EncodeFramed(CNMStream* pStream)
{
    alignas(8) unsigned char encoder[0x18];
    FUN_14156bcb0(encoder, pStream, this);
    const unsigned int result = Encode(reinterpret_cast<CNMEncoder*>(encoder), pStream);
    FUN_14156bd50(encoder);
    return result;
}

// MS2-FUNCTIONAL: follows the request format branch and delegates to the matching encoder.
// @0x14159ef60
unsigned int CNMCRSendChatMessageFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        Encode(pEncoder, pStream);
    else
        EncodeFramed(pStream);
    return 0;
}

// MS2-FUNCTIONAL: writes ten recipient keys and the framed chat message when the request direction is active.
// @0x14159efc0
unsigned int CNMCRSendChatMessageFunc::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMFunc::EncodeDispatch(pEncoder, pStream);
    if (FUN_1415fb700(this) != 0)
    {
        for (const auto key : m_aKeys)
            FUN_14156acb0(pEncoder, key);
        m_msg.EncodeFramed(pStream);
    }
    FUN_1415f9990(pEncoder);
    return 1;
}

// MS2-FUNCTIONAL: decoder wrapper lifetime and validity branch match; local decoder storage differs.
// @0x14159f070
unsigned int CNMCRSendChatMessageFunc::DecodeFramed(CNMStream* pStream)
{
    alignas(8) unsigned char decoder[0x38];
    FUN_14156be10(decoder, pStream, this);
    unsigned int result = 0;
    if (FUN_1415fb750(decoder) != 0)
        result = Decode(reinterpret_cast<CNMSerializableDecoder*>(decoder), pStream);
    FUN_14156bd50(decoder);
    return result;
}

// MS2-FUNCTIONAL: follows decoder format 2 into the framed wrapper, otherwise decodes directly.
// @0x14159f100
unsigned int CNMCRSendChatMessageFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        DecodeFramed(pStream);
    else
        Decode(pDecoder, pStream);
    return 0;
}

// MS2-FUNCTIONAL: reads ten recipient keys and the framed chat message when request direction is active.
// @0x14159f160
unsigned int CNMCRSendChatMessageFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    if (FUN_1415fb700(this) != 0)
    {
        void** vftable = *reinterpret_cast<void***>(pDecoder);
        using ReadU64 = unsigned __int64(__fastcall*)(void*);
        for (auto& key : m_aKeys)
            key = reinterpret_cast<ReadU64>(vftable[4])(pDecoder);
        m_msg.DecodeFramed(pStream);
    }
    return FUN_1415fb750(pDecoder);
}

// MS2-PIN: ??0CNMCRSendChatMessageFunc@@QEAA@XZ 0x14159edb0
