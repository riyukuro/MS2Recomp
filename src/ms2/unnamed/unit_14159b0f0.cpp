// Recovered from the Nexon Messenger client library: extended join-chat-room request.
// MS2-UNIT: unit_14159b0f0
// MS2-RANGE: 0x14159b0f0-0x14159b760 .text$mn
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
    alignas(8) unsigned char encoder[0x18];
    FUN_14156bcb0(encoder, pStream, this);
    const unsigned int result = Encode(reinterpret_cast<CNMEncoder*>(encoder), pStream);
    FUN_14156bd50(encoder);
    return result;
}

// MS2-FUNCTIONAL: recovered format branch; direct calls replace virtual dispatch.
// @0x14159b390
unsigned int CNMJoinToChatRoomExFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        Encode(pEncoder, pStream);
    else
        EncodeFramed(pStream);
    return 0;
}

// MS2-FUNCTIONAL: request/reply branches and payload order recovered; direct calls replace indirect dispatch.
// @0x14159b3f0
unsigned int CNMJoinToChatRoomExFunc::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMFunc::EncodeDispatch(pEncoder, pStream);
    if (FUN_1415fb700(this) == 0)
    {
        if (FUN_1415fb720(this) != 0)
        {
            FUN_14156ac20(pEncoder, m_758);
            FUN_14156ac20(pEncoder, m_75c);
        }
    }
    else
    {
        m_room.EncodeFramed(pStream);
        m_self.EncodeFramed(pStream);
        FUN_14156ae30(pEncoder, m_730);
        FUN_14156ab90(pEncoder, m_750);
        FUN_14156ac20(pEncoder, m_754);
    }
    FUN_1415f9990(pEncoder);
    return 1;
}

// MS2-FUNCTIONAL: decoder wrapper lifetime and validity branch match; local decoder frame layout differs.
// @0x14159b520
unsigned int CNMJoinToChatRoomExFunc::DecodeFramed(CNMStream* pStream)
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
// @0x14159b5b0
unsigned int CNMJoinToChatRoomExFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        DecodeFramed(pStream);
    else
        Decode(pDecoder, pStream);
    return 0;
}

// MS2-FUNCTIONAL: request/reply branches and payload order recovered; direct calls replace indirect dispatch.
// @0x14159b610
unsigned int CNMJoinToChatRoomExFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    if (FUN_1415fb700(this) == 0)
    {
        if (FUN_1415fb720(this) != 0)
        {
            using ReadU32 = unsigned int(__fastcall*)(void*);
            void** vftable = *reinterpret_cast<void***>(pDecoder);
            m_758 = ReadU32(vftable[3])(pDecoder);
            m_75c = ReadU32(vftable[3])(pDecoder);
        }
    }
    else
    {
        m_room.DecodeFramed(pStream);
        m_self.DecodeFramed(pStream);
        using ReadBytes = void(__fastcall*)(void*, void*, unsigned int);
        using ReadU16 = unsigned short(__fastcall*)(void*);
        using ReadU32 = unsigned int(__fastcall*)(void*);
        void** vftable = *reinterpret_cast<void***>(pDecoder);
        reinterpret_cast<ReadBytes>(vftable[9])(pDecoder, m_730, 0x20);
        m_750 = reinterpret_cast<ReadU16>(vftable[2])(pDecoder);
        m_754 = reinterpret_cast<ReadU32>(vftable[3])(pDecoder);
    }
    return FUN_1415fb750(pDecoder);
}

