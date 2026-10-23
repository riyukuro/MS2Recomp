// Recovered from low-confidence Ghidra output for the Nexon Messenger chat message record.
// MS2-UNIT: unit_141572e00
// MS2-RANGE: 0x1415727c0-0x141572e00 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmchatroomfunc.h"
#include "ms2/ms2recover.h"

extern void FUN_14156bcb0(void*, void*, void*);
extern void FUN_14156bd50(void*);
extern void FUN_14156be10(void*, void*, void*);
extern void FUN_14156bf10(void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(void*);
extern int FUN_1415fb700(void*);
extern unsigned int FUN_14156ac20(void*, unsigned int);
extern unsigned int FUN_14156ae30(void*, const char*);
extern unsigned int FUN_1415f9990(void*);
extern unsigned long long FUN_1415f39d0(void*);
extern unsigned long long FUN_1415f39a0(void*);
extern int FUN_1415fc140(char*, size_t, const char*);

// @0x1415727c0
// MS2-FUNCTIONAL: initializes the message header, avatar, and four zeroed payload buffers.
CNMChatMessage::CNMChatMessage()
    : CNMSerializable(0x636d, 1, 1), m_10(0), m_14(0), m_avatar(), m_28{}, m_68{}, m_168{}, m_268{}, m_668(0)
{
    m_bFlag = 0xfe;
}

// @0x1415728a0
// MS2-FUNCTIONAL: restores message type, timestamp, avatar, names, body, and flags from the record layout.
CNMChatMessage::CNMChatMessage(const void* record, int messageType)
    : CNMChatMessage()
{
    const auto* source = static_cast<const unsigned char*>(record);
    m_10 = messageType;
    m_14 = *reinterpret_cast<const int*>(source + 0x18);
    if (messageType == 1)
        FUN_1415fc140(m_28, sizeof(m_28), "_NOTICE_");
    else if (messageType == 2)
        FUN_1415fc140(m_28, sizeof(m_28), "_SYSTEM_");
    else
        FUN_1415fc140(m_28, sizeof(m_28), reinterpret_cast<const char*>(FUN_1415f39d0(const_cast<unsigned char*>(source + 0x20))));
    m_68[0] = 0;
    m_168[0] = 0;
    FUN_1415fc140(m_268, sizeof(m_268), reinterpret_cast<const char*>(FUN_1415f39a0(const_cast<unsigned char*>(source + 0x30))));
    m_668 = *reinterpret_cast<const int*>(source + 0x40);
}

// @0x141572a10
// MS2-FUNCTIONAL: framed encoder setup and cleanup match; local encoder storage differs.
unsigned int CNMChatMessage::EncodeFramed(CNMStream* pStream)
{
    alignas(8) unsigned char encoder[0x18];
    FUN_14156bcb0(encoder, pStream, this);
    const unsigned int result = Encode(reinterpret_cast<CNMEncoder*>(encoder), pStream);
    FUN_14156bd50(encoder);
    return result;
}

// @0x141572a70
// MS2-FUNCTIONAL: preserves message format dispatch; direct member calls replace virtual slot dispatch.
unsigned int CNMChatMessage::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        Encode(pEncoder, pStream);
    else
        EncodeFramed(pStream);
    return 0;
}

// @0x141572ad0
// MS2-FUNCTIONAL: serializes scalar header, avatar, and all four fixed-buffer fields in wire order.
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
// MS2-FUNCTIONAL: framed decoder setup, validity check, and cleanup match; local storage differs.
unsigned int CNMChatMessage::DecodeFramed(CNMStream* pStream)
{
    alignas(8) unsigned char decoder[0x38];
    FUN_14156be10(decoder, pStream, this);
    unsigned int result = 0;
    if (FUN_1415fb750(decoder) != 0)
        result = Decode(reinterpret_cast<CNMSerializableDecoder*>(decoder), pStream);
    FUN_14156bf10(decoder);
    return result;
}

// @0x141572c50
// MS2-FUNCTIONAL: selects framed decoding for decoder format 2.
unsigned int CNMChatMessage::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        DecodeFramed(pStream);
    else
        Decode(pDecoder, pStream);
    return 0;
}

// @0x141572cb0
// MS2-FUNCTIONAL: restores scalar header, avatar, fixed-buffer payload, and trailing flags in wire order.
unsigned int CNMChatMessage::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMSerializable::DecodeDispatch(pDecoder, pStream);
    void** vftable = *reinterpret_cast<void***>(pDecoder);
    using ReadU32 = unsigned int(__fastcall*)(void*);
    using ReadBuffer = unsigned int(__fastcall*)(void*, void*, unsigned int);
    m_10 = static_cast<int>(reinterpret_cast<ReadU32>(vftable[3])(pDecoder));
    m_14 = static_cast<int>(reinterpret_cast<ReadU32>(vftable[3])(pDecoder));
    m_avatar.DecodeFramed(pStream);
    reinterpret_cast<ReadBuffer>(vftable[9])(pDecoder, m_28, sizeof(m_28));
    reinterpret_cast<ReadBuffer>(vftable[9])(pDecoder, m_68, sizeof(m_68));
    reinterpret_cast<ReadBuffer>(vftable[9])(pDecoder, m_168, sizeof(m_168));
    reinterpret_cast<ReadBuffer>(vftable[9])(pDecoder, m_268, sizeof(m_268));
    m_668 = static_cast<int>(reinterpret_cast<ReadU32>(vftable[3])(pDecoder));
    return static_cast<unsigned int>(FUN_1415fb750(pDecoder));
}

// MS2-PIN: ??0CNMChatMessage@@QEAA@XZ 0x1415727c0
