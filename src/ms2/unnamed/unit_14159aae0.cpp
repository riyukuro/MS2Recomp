// Recovered from the Nexon Messenger client library: join-chat-room request.
// MS2-UNIT: unit_14159aae0
// MS2-RANGE: 0x14159aae0-0x14159b0f0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmobjects.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/placeholder/nmencoder.h"
#include "ms2/ms2recover.h"

extern int FUN_1415fb700(const void*);
extern int FUN_1415fb720(const void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(CNMSerializableDecoder*);
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

// @0x14159acf0
unsigned int CNMJoinToChatRoomFunc::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMJoinToChatRoomFunc::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}

// @0x14159ad50
unsigned int CNMJoinToChatRoomFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMJoinToChatRoomFunc::Encode(pEncoder, pStream);
    return CNMJoinToChatRoomFunc::EncodeFramed(pStream);
}

// @0x14159adb0
unsigned int CNMJoinToChatRoomFunc::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMFunc::EncodeDispatch(pEncoder, pStream);
    if (FUN_1415fb700(this) != 0)
    {
        m_room.EncodeFramed(pStream);
        m_self.EncodeFramed(pStream);
        FUN_14156ae30(pEncoder, m_850);
        FUN_14156ab90(pEncoder, m_870);
    }
    else if (FUN_1415fb720(this) != 0)
    {
        FUN_14156ac20(pEncoder, m_874);
        FUN_14156ac20(pEncoder, m_878);
    }
    FUN_1415f9990(pEncoder);
    return 1;
}

// @0x14159aec0
unsigned int CNMJoinToChatRoomFunc::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMJoinToChatRoomFunc::Decode(&decoder, pStream);
}

// @0x14159af50
unsigned int CNMJoinToChatRoomFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMJoinToChatRoomFunc::DecodeFramed(pStream);
    return CNMJoinToChatRoomFunc::Decode(pDecoder, pStream);
}

// @0x14159afb0
unsigned int CNMJoinToChatRoomFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    if (FUN_1415fb700(this) != 0)
    {
        m_room.DecodeFramed(pStream);
        m_self.DecodeFramed(pStream);
        pDecoder->ReadStringBufAlias(reinterpret_cast<char*>(m_850), 0x20);
        m_870 = pDecoder->ReadU16();
    }
    else if (FUN_1415fb720(this) != 0)
    {
        m_874 = pDecoder->ReadU32();
        m_878 = pDecoder->ReadU32();
    }
    return FUN_1415fb750(pDecoder);
}

