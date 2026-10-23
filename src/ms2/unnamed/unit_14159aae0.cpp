// Recovered from the Nexon Messenger client library: join-chat-room request.
// MS2-UNIT: unit_14159aae0
// MS2-RANGE: 0x14159aae0-0x14159b0f0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmobjects.h"
#include "ms2/ms2recover.h"

extern int FUN_1415fb700(const void*);
extern int FUN_1415fb720(const void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(void*);
extern void FUN_1415f9990(void*);
extern void FUN_14156ae30(void*, const void*);
extern void FUN_14156ab90(void*, unsigned short);
extern void FUN_14156ac20(void*, unsigned int);
extern void FUN_14156bcb0(void*, void*, void*);
extern void FUN_14156bd50(void*);
extern void FUN_1415fbe70(void*, unsigned int, const char*);

// @0x14159aae0
CNMJoinToChatRoomFunc::CNMJoinToChatRoomFunc()
    : CNMFunc(0xa007, 1, 0, 0), m_room(), m_self()
{
    m_850[0] = '\0';
    m_870 = 0;
    m_874 = 0;
    m_878 = 0;
}

// @0x14159aba0
CNMJoinToChatRoomFunc::CNMJoinToChatRoomFunc(unsigned int n44, unsigned int n48, const char* sz49c,
                                             const char* sz850, unsigned short n870)
    : CNMFunc(0xa007, 1, 0, 0), m_room(), m_self()
{
    m_room.m_14 = static_cast<int>(n44);
    m_room.m_18 = static_cast<int>(n48);
    if (sz49c)
        FUN_1415fbe70(m_room.m_46c, 0x40, sz49c);
    else
        m_room.m_46c[0] = '\0';
    if (sz850)
        FUN_1415fbe70(m_850, 0x20, sz850);
    else
        m_850[0] = '\0';
    m_870 = n870;
    m_874 = 0;
    m_878 = 0;
}

// MS2-FUNCTIONAL: request framed encoding and cleanup match; the local encoder frame layout differs.
// @0x14159acf0
unsigned int CNMJoinToChatRoomFunc::EncodeFramed(CNMStream* pStream)
{
    alignas(8) unsigned char encoder[0x18];
    FUN_14156bcb0(encoder, pStream, this);
    const unsigned int result = Encode(reinterpret_cast<CNMEncoder*>(encoder), pStream);
    FUN_14156bd50(encoder);
    return result;
}

// MS2-FUNCTIONAL: recovered format branch; direct calls replace virtual dispatch.
// @0x14159ad50
unsigned int CNMJoinToChatRoomFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        Encode(pEncoder, pStream);
    else
        EncodeFramed(pStream);
    return 0;
}

// MS2-FUNCTIONAL: request and reply payload branches recovered; direct calls replace indirect dispatch.
// @0x14159adb0
unsigned int CNMJoinToChatRoomFunc::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMFunc::EncodeDispatch(pEncoder, pStream);
    if (FUN_1415fb700(this) == 0)
    {
        if (FUN_1415fb720(this) != 0)
        {
            FUN_14156ac20(pEncoder, m_874);
            FUN_14156ac20(pEncoder, m_878);
        }
    }
    else
    {
        m_room.EncodeFramed(pStream);
        m_self.EncodeFramed(pStream);
        FUN_14156ae30(pEncoder, m_850);
        FUN_14156ab90(pEncoder, m_870);
    }
    FUN_1415f9990(pEncoder);
    return 1;
}

// MS2-FUNCTIONAL: decoder wrapper lifetime and validity branch match; local decoder frame layout differs.
// @0x14159aec0
unsigned int CNMJoinToChatRoomFunc::DecodeFramed(CNMStream* pStream)
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
// @0x14159af50
unsigned int CNMJoinToChatRoomFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        DecodeFramed(pStream);
    else
        Decode(pDecoder, pStream);
    return 0;
}

// MS2-FUNCTIONAL: request and reply payload branches recovered; direct calls replace indirect dispatch.
// @0x14159afb0
unsigned int CNMJoinToChatRoomFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    if (FUN_1415fb700(this) == 0)
    {
        if (FUN_1415fb720(this) != 0)
        {
            using ReadU32 = unsigned int(__fastcall*)(void*);
            void** vftable = *reinterpret_cast<void***>(pDecoder);
            m_874 = ReadU32(vftable[3])(pDecoder);
            m_878 = ReadU32(vftable[3])(pDecoder);
        }
    }
    else
    {
        m_room.DecodeFramed(pStream);
        m_self.DecodeFramed(pStream);
        using ReadBytes = void(__fastcall*)(void*, void*, unsigned int);
        using ReadU16 = unsigned short(__fastcall*)(void*);
        void** vftable = *reinterpret_cast<void***>(pDecoder);
        reinterpret_cast<ReadBytes>(vftable[9])(pDecoder, m_850, 0x20);
        m_870 = reinterpret_cast<ReadU16>(vftable[2])(pDecoder);
    }
    return FUN_1415fb750(pDecoder);
}

