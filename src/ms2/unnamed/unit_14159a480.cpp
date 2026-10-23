// Recovered from the Nexon Messenger client library: extended create-chat-room request.
// MS2-UNIT: unit_14159a480
// MS2-RANGE: 0x14159a480-0x14159aae0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmobjects.h"
#include "ms2/ms2recover.h"

extern int FUN_1415fb700(const void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(void*);
extern void FUN_1415f9990(void*);
extern void FUN_14156ae30(void*, const void*);
extern void FUN_14156ab90(void*, unsigned short);
extern void FUN_14156ac20(void*, unsigned int);
extern void FUN_14156bcb0(void*, void*, void*);
extern void FUN_14156bd50(void*);
extern void FUN_1415fbe70(void*, unsigned int, const char*);

// MS2-FUNCTIONAL: recovered member initialization; base constructor lowering differs in the argument register width.
// @0x14159a480
CNMCreateChatRoomExFunc::CNMCreateChatRoomExFunc()
    : CNMFunc(0xa009, 1, 0, 0), m_room(), m_self()
{
    m_730[0] = '\0';
    m_750 = 0;
    m_754 = 1;
}

// @0x14159a530
CNMCreateChatRoomExFunc::CNMCreateChatRoomExFunc(int n10, unsigned __int64 n18, const char* sz20, const char* sz60,
                                                 int n498, int n49c, int n4a0, const char* sz4a4,
                                                 const char* sz730, unsigned short n750, int n754)
    : CNMFunc(0xa009, 1, 0, 0), m_room(), m_self()
{
    m_room.m_10 = static_cast<unsigned int>(n10);
    m_room.m_18 = n18;
    if (sz20)
        FUN_1415fbe70(m_room.m_28, 0x40, sz20);
    else
        m_room.m_28[0] = '\0';
    if (sz60)
        FUN_1415fbe70(m_room.m_68, 0x400, sz60);
    else
        m_room.m_68[0] = '\0';
    m_room.m_468 = static_cast<unsigned int>(n498);
    m_room.m_46c = static_cast<unsigned int>(n49c);
    m_room.m_470 = static_cast<unsigned int>(n4a0);
    if (sz4a4)
        FUN_1415fbe70(m_room.m_474, 0x40, sz4a4);
    else
        m_room.m_474[0] = '\0';
    if (sz730)
        FUN_1415fbe70(m_730, 0x20, sz730);
    else
        m_730[0] = '\0';
    m_750 = n750;
    m_754 = n754;
}

// MS2-FUNCTIONAL: stack encoder lifetime and framing flow match; local encoder frame layout differs.
// @0x14159a730
unsigned int CNMCreateChatRoomExFunc::EncodeFramed(CNMStream* pStream)
{
    alignas(8) unsigned char encoder[0x18];
    FUN_14156bcb0(encoder, pStream, this);
    const unsigned int result = Encode(reinterpret_cast<CNMEncoder*>(encoder), pStream);
    FUN_14156bd50(encoder);
    return result;
}

// MS2-FUNCTIONAL: recovered format branch; direct calls stand in for virtual dispatch.
// @0x14159a790
unsigned int CNMCreateChatRoomExFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        Encode(pEncoder, pStream);
    else
        EncodeFramed(pStream);
    return 0;
}

// MS2-FUNCTIONAL: nested records and trailing fields match; direct calls replace indirect dispatch.
// @0x14159a7f0
unsigned int CNMCreateChatRoomExFunc::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMFunc::EncodeDispatch(pEncoder, pStream);
    if (FUN_1415fb700(this) != 0)
    {
        m_room.EncodeFramed(pStream);
        m_self.EncodeFramed(pStream);
        FUN_14156ae30(pEncoder, m_730);
        FUN_14156ab90(pEncoder, m_750);
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_754));
    }
    FUN_1415f9990(pEncoder);
    return 1;
}

// MS2-FUNCTIONAL: stack decoder lifetime and validity branch match; local decoder frame layout differs.
// @0x14159a8e0
unsigned int CNMCreateChatRoomExFunc::DecodeFramed(CNMStream* pStream)
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
// @0x14159a970
unsigned int CNMCreateChatRoomExFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        DecodeFramed(pStream);
    else
        Decode(pDecoder, pStream);
    return 0;
}

// MS2-FUNCTIONAL: nested records and trailing fields match; direct calls replace indirect dispatch.
// @0x14159a9d0
unsigned int CNMCreateChatRoomExFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    if (FUN_1415fb700(this) != 0)
    {
        m_room.DecodeFramed(pStream);
        m_self.DecodeFramed(pStream);
        using ReadBytes = void(__fastcall*)(void*, void*, unsigned int);
        using ReadU16 = unsigned short(__fastcall*)(void*);
        using ReadU32 = unsigned int(__fastcall*)(void*);
        void** vftable = *reinterpret_cast<void***>(pDecoder);
        reinterpret_cast<ReadBytes>(vftable[9])(pDecoder, m_730, 0x20);
        m_750 = reinterpret_cast<ReadU16>(vftable[2])(pDecoder);
        m_754 = static_cast<int>(reinterpret_cast<ReadU32>(vftable[3])(pDecoder));
    }
    return 1;
}

// MS2-PIN: ??0CNMCreateChatRoomExFunc@@QEAA@XZ 0x14159a480
