// Recovered from the Nexon Messenger client library. CNMCreateChatRoomFunc constructors and serializers.
// MS2-UNIT: unit_141599e80
// MS2-RANGE: 0x141599e80-0x14159a480 .text$mn
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
extern void* FUN_14156bcb0(void*, void*, void*);
extern void FUN_14156bd50(void*);
extern void FUN_1415fbe70(void*, unsigned int, const char*);

// @0x141599e80
CNMCreateChatRoomFunc::CNMCreateChatRoomFunc()
    : CNMFunc(0xa006, 1, 0, 0), m_room(), m_self(), m_850{}, m_870(0), m_872{}
{
}

// @0x141599f20
CNMCreateChatRoomFunc::CNMCreateChatRoomFunc(int n10, int n14, const char* sz20, const char* sz60,
                                             int n460, int n464, int n468, const char* sz46c,
                                             const char* sz850, unsigned short n870)
    : CNMFunc(0xa006, 1, 0, 0), m_room(), m_self(), m_850{}, m_870(n870), m_872{}
{
    m_room.m_10 = n10;
    m_room.m_14 = n14;
    if (sz20)
        FUN_1415fbe70(m_room.m_20, 0x40, sz20);
    else
        m_room.m_20[0] = '\0';
    if (sz60)
        FUN_1415fbe70(m_room.m_60, 0x400, sz60);
    else
        m_room.m_60[0] = '\0';
    m_room.m_460 = n460;
    m_room.m_464 = n464;
    m_room.m_468 = n468;
    if (sz46c)
        FUN_1415fbe70(m_room.m_46c, 0x40, sz46c);
    else
        m_room.m_46c[0] = '\0';
    if (sz850)
        FUN_1415fbe70(m_850, 0x20, sz850);
    else
        m_850[0] = '\0';
}

// MS2-FUNCTIONAL: framed encoder setup and cleanup match; local encoder storage differs in frame layout.
// @0x14159a100
unsigned int CNMCreateChatRoomFunc::EncodeFramed(CNMStream* pStream)
{
    alignas(8) unsigned char encoder[0x18];
    FUN_14156bcb0(encoder, pStream, this);
    const unsigned int result = Encode(reinterpret_cast<CNMEncoder*>(encoder), pStream);
    FUN_14156bd50(encoder);
    return result;
}

// MS2-FUNCTIONAL: recovered format branch; direct calls replace indirect virtual dispatch.
// @0x14159a160
unsigned int CNMCreateChatRoomFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        Encode(pEncoder, pStream);
    else
        EncodeFramed(pStream);
    return 0;
}

// MS2-FUNCTIONAL: nested records and trailing fields match; direct virtual calls replace indirect dispatch.
// @0x14159a1c0
unsigned int CNMCreateChatRoomFunc::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMFunc::EncodeDispatch(pEncoder, pStream);
    if (FUN_1415fb700(this) != 0)
    {
        m_room.EncodeFramed(pStream);
        m_self.EncodeFramed(pStream);
        FUN_14156ae30(pEncoder, m_850);
        FUN_14156ab90(pEncoder, m_870);
    }
    FUN_1415f9990(pEncoder);
    return 1;
}

// MS2-FUNCTIONAL: framed decoder setup and cleanup match; local decoder storage differs in frame layout.
// @0x14159a2a0
unsigned int CNMCreateChatRoomFunc::DecodeFramed(CNMStream* pStream)
{
    alignas(8) unsigned char decoder[0x38];
    FUN_14156bcb0(decoder, pStream, this);
    unsigned int result = 0;
    if (FUN_1415fb750(decoder) != 0)
        result = Decode(reinterpret_cast<CNMSerializableDecoder*>(decoder), pStream);
    FUN_14156bd50(decoder);
    return result;
}

// MS2-FUNCTIONAL: framed decoder selection matches; direct dispatch replaces the indirect virtual call.
// @0x14159a330
unsigned int CNMCreateChatRoomFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        DecodeFramed(pStream);
    else
        Decode(pDecoder, pStream);
    return 0;
}

// MS2-FUNCTIONAL: nested record decodes and trailing fields match; direct virtual calls replace indirect dispatch.
// @0x14159a390
unsigned int CNMCreateChatRoomFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    if (FUN_1415fb700(this) != 0)
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

// MS2-PIN: ??0CNMCreateChatRoomFunc@@QEAA@XZ 0x141599e80
// MS2-PIN: ??0CNMCreateChatRoomFunc@@QEAA@HHPEBD0HHH00G@Z 0x141599f20
