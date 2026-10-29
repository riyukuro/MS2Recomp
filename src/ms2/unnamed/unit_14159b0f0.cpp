// Recovered from the Nexon Messenger client library: extended join-chat-room request.
// MS2-UNIT: unit_14159b0f0
// MS2-RANGE: 0x14159b0f0-0x14159b760 .text$mn
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

// @0x14159b0f0
CNMJoinToChatRoomExFunc::CNMJoinToChatRoomExFunc()
    : CNMFunc(0xa00a, 1, 0, 0), m_room(), m_self()
{
    m_730[0] = '\0';
    m_750 = 0;
    m_754 = 1;
    m_758 = 0;
    m_75c = 0;
}

// @0x14159b1c0
CNMJoinToChatRoomExFunc::CNMJoinToChatRoomExFunc(unsigned __int64 n48, unsigned int n50, const char* sz4a4,
                                                 const char* sz730, unsigned short n750,
                                                 unsigned int n4a0, unsigned int n754)
    : CNMFunc(0xa00a, 1, 0, 0), m_room(), m_self()
{
    m_room.m_18 = n48;
    m_room.m_20 = n50;
    if (sz4a4)
        FUN_1415fbe70(m_room.m_474, 0x40, sz4a4);
    else
        m_room.m_474[0] = '\0';
    m_room.m_470 = n4a0;
    if (sz730)
        FUN_1415fbe70(m_730, 0x20, sz730);
    else
        m_730[0] = '\0';
    m_750 = n750;
    m_754 = n754;
    m_758 = 0;
    m_75c = 0;
}

// MS2-FUNCTIONAL: wrapper lifetime and framed encoding flow match; local encoder frame layout differs.
// @0x14159b330
unsigned int CNMJoinToChatRoomExFunc::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMJoinToChatRoomExFunc::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}

// MS2-FUNCTIONAL: recovered format branch; direct calls replace virtual dispatch.
// @0x14159b390
unsigned int CNMJoinToChatRoomExFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMJoinToChatRoomExFunc::Encode(pEncoder, pStream);
    return CNMJoinToChatRoomExFunc::EncodeFramed(pStream);
}

// @0x14159b3f0
unsigned int CNMJoinToChatRoomExFunc::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMFunc::EncodeDispatch(pEncoder, pStream);
    if (FUN_1415fb700(this) != 0)
    {
        m_room.EncodeFramed(pStream);
        m_self.EncodeFramed(pStream);
        FUN_14156ae30(pEncoder, m_730);
        FUN_14156ab90(pEncoder, m_750);
        FUN_14156ac20(pEncoder, m_754);
    }
    else if (FUN_1415fb720(this) != 0)
    {
        FUN_14156ac20(pEncoder, m_758);
        FUN_14156ac20(pEncoder, m_75c);
    }
    FUN_1415f9990(pEncoder);
    return 1;
}

// MS2-FUNCTIONAL: decoder wrapper lifetime and validity branch match; local decoder frame layout differs.
// @0x14159b520
unsigned int CNMJoinToChatRoomExFunc::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMJoinToChatRoomExFunc::Decode(&decoder, pStream);
}

// MS2-FUNCTIONAL: recovered decoder format branch; direct calls replace virtual dispatch.
// @0x14159b5b0
unsigned int CNMJoinToChatRoomExFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMJoinToChatRoomExFunc::DecodeFramed(pStream);
    return CNMJoinToChatRoomExFunc::Decode(pDecoder, pStream);
}

// @0x14159b610
unsigned int CNMJoinToChatRoomExFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    if (FUN_1415fb700(this) != 0)
    {
        m_room.DecodeFramed(pStream);
        m_self.DecodeFramed(pStream);
        pDecoder->ReadStringBufAlias(reinterpret_cast<char*>(m_730), 0x20);
        m_750 = pDecoder->ReadU16();
        m_754 = pDecoder->ReadU32();
    }
    else if (FUN_1415fb720(this) != 0)
    {
        m_758 = pDecoder->ReadU32();
        m_75c = pDecoder->ReadU32();
    }
    return FUN_1415fb750(pDecoder);
}

