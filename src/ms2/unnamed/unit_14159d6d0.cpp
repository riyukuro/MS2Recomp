// Recovered from the Nexon Messenger client library: change chat-room info request.
// MS2-UNIT: unit_14159d6d0
// MS2-RANGE: 0x14159d6d0-0x14159de00 .text$mn
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
extern void FUN_14156ae30(void*, const void*);
extern void FUN_14156ac20(void*, unsigned int);
extern void FUN_14156acb0(void*, unsigned __int64);
extern void FUN_14156bcb0(void*, void*, void*);
extern void FUN_14156bd50(void*);
extern void FUN_1415fbe70(void*, unsigned int, const char*);

// MS2-FUNCTIONAL: request code and zero payload initialization match; vftable setup codegen differs.
// @0x14159d6d0
CNMCRChangeRoomInfoFunc::CNMCRChangeRoomInfoFunc()
    : CNMFunc(0xb004, 1, 0, 0), m_uFlags(0), m_434(0), m_438(0), m_43c(0), m_440(0)
{
    m_szTitle[0] = '\0';
    m_448[0] = '\0';
}

// MS2-FUNCTIONAL: optional fields and flag bits follow recovered constructor; helper and initialization codegen differ.
// @0x14159d790
CNMCRChangeRoomInfoFunc::CNMCRChangeRoomInfoFunc(unsigned uSerialKey, const char* szTitle,
    const unsigned* pU434, const unsigned* pU438, const unsigned* pU43c, const char* sz448,
    const unsigned __int64* pU440)
    : CNMFunc(0xb004, 1, static_cast<int>(uSerialKey), 0), m_uFlags(0), m_434(0), m_438(0), m_43c(0), m_440(0)
{
    m_szTitle[0] = '\0';
    m_448[0] = '\0';
    if (szTitle)
    {
        FUN_1415fbe70(m_szTitle, sizeof(m_szTitle), szTitle);
        m_uFlags |= 1;
    }
    if (pU434)
    {
        m_434 = *pU434;
        m_uFlags |= 2;
    }
    if (pU438)
    {
        m_438 = *pU438;
        m_uFlags |= 4;
    }
    if (pU43c)
    {
        m_43c = *pU43c;
        m_uFlags |= 8;
    }
    if (pU440)
    {
        m_440 = *pU440;
        m_uFlags |= 0x10;
    }
    if (sz448)
    {
        FUN_1415fbe70(m_448, sizeof(m_448), sz448);
        m_uFlags |= 0x20;
    }
}

// MS2-FUNCTIONAL: framed encoder setup and cleanup match; local encoder storage differs.
// @0x14159d970
unsigned int CNMCRChangeRoomInfoFunc::EncodeFramed(CNMStream* pStream)
{
    alignas(8) unsigned char encoder[0x18];
    FUN_14156bcb0(encoder, pStream, this);
    const unsigned int result = Encode(reinterpret_cast<CNMEncoder*>(encoder), pStream);
    FUN_14156bd50(encoder);
    return result;
}

// MS2-FUNCTIONAL: recovered format branch; direct calls replace virtual dispatch.
// @0x14159d9d0
unsigned int CNMCRChangeRoomInfoFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        Encode(pEncoder, pStream);
    else
        EncodeFramed(pStream);
    return 0;
}

// MS2-FUNCTIONAL: request flag mask and ordered field writes match; direct calls replace virtual dispatch.
// @0x14159da30
unsigned int CNMCRChangeRoomInfoFunc::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMFunc::EncodeDispatch(pEncoder, pStream);
    if (FUN_1415fb700(this) != 0)
    {
        FUN_14156ac20(pEncoder, m_uFlags);
        if ((m_uFlags & 1) != 0) FUN_14156ae30(pEncoder, m_szTitle);
        if ((m_uFlags & 2) != 0) FUN_14156ac20(pEncoder, m_434);
        if ((m_uFlags & 4) != 0) FUN_14156ac20(pEncoder, m_438);
        if ((m_uFlags & 8) != 0) FUN_14156ac20(pEncoder, m_43c);
        if ((m_uFlags & 0x10) != 0) FUN_14156acb0(pEncoder, m_440);
        if ((m_uFlags & 0x20) != 0) FUN_14156ae30(pEncoder, m_448);
    }
    FUN_1415f9990(pEncoder);
    return 1;
}

// MS2-FUNCTIONAL: decoder wrapper lifetime and validity branch match; local decoder storage differs.
// @0x14159db80
unsigned int CNMCRChangeRoomInfoFunc::DecodeFramed(CNMStream* pStream)
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
// @0x14159dc10
unsigned int CNMCRChangeRoomInfoFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        DecodeFramed(pStream);
    else
        Decode(pDecoder, pStream);
    return 0;
}

// MS2-FUNCTIONAL: flag mask and conditional field reads match; direct calls replace indirect dispatch.
// @0x14159dc70
unsigned int CNMCRChangeRoomInfoFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    if (FUN_1415fb700(this) != 0)
    {
        void** vftable = *reinterpret_cast<void***>(pDecoder);
        using ReadU32 = unsigned int(__fastcall*)(void*);
        using ReadU64 = unsigned __int64(__fastcall*)(void*);
        using ReadString = void(__fastcall*)(void*, void*, unsigned int);
        m_uFlags = reinterpret_cast<ReadU32>(vftable[3])(pDecoder);
        if ((m_uFlags & 1) != 0) reinterpret_cast<ReadString>(vftable[9])(pDecoder, m_szTitle, sizeof(m_szTitle));
        if ((m_uFlags & 2) != 0) m_434 = reinterpret_cast<ReadU32>(vftable[3])(pDecoder);
        if ((m_uFlags & 4) != 0) m_438 = reinterpret_cast<ReadU32>(vftable[3])(pDecoder);
        if ((m_uFlags & 8) != 0) m_43c = reinterpret_cast<ReadU32>(vftable[3])(pDecoder);
        if ((m_uFlags & 0x10) != 0) m_440 = reinterpret_cast<ReadU64>(vftable[4])(pDecoder);
        if ((m_uFlags & 0x20) != 0) reinterpret_cast<ReadString>(vftable[9])(pDecoder, m_448, sizeof(m_448));
    }
    return FUN_1415fb750(pDecoder);
}

// MS2-PIN: ??0CNMCRChangeRoomInfoFunc@@QEAA@XZ 0x14159d6d0
