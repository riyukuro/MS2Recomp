// Recovered from the Nexon Messenger client library: chat-room member list request.
// MS2-UNIT: unit_14159e1b0
// MS2-RANGE: 0x14159e1b0-0x14159e630 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmchatroomfunc.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/placeholder/nmencoder.h"
#include "ms2/ms2recover.h"

extern int FUN_1415fb720(void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(CNMSerializableDecoder*);
extern void FUN_1415f9990(void*);
extern void FUN_14156ac20(void*, unsigned int);
extern void FUN_14156bcb0(void*, void*, void*);
extern void FUN_14156bd50(void*);

// MS2-FUNCTIONAL: request ID and vector initialization match; helper call and base codegen differ.
// @0x14159e1b0
CNMCRGetMemberListFunc::CNMCRGetMemberListFunc()
    : CNMFunc(0xb006, 1, 0, 0), m_aMembers()
{
}

// MS2-FUNCTIONAL: request ID and serial key match; base constructor register width differs.
// @0x14159e210
CNMCRGetMemberListFunc::CNMCRGetMemberListFunc(unsigned uSerialKey)
    : CNMFunc(0xb006, 1, static_cast<int>(uSerialKey), 0), m_aMembers()
{
}

// MS2-FUNCTIONAL: framed encoder setup and cleanup match; local encoder storage differs.
// @0x14159e270
unsigned int CNMCRGetMemberListFunc::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMCRGetMemberListFunc::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}

// MS2-FUNCTIONAL: recovered format branch; direct calls replace virtual dispatch.
// @0x14159e2d0
unsigned int CNMCRGetMemberListFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMCRGetMemberListFunc::Encode(pEncoder, pStream);
    return CNMCRGetMemberListFunc::EncodeFramed(pStream);
}

// MS2-FUNCTIONAL: reply count and ordered member payloads match; vector iteration codegen differs.
// @0x14159e330
unsigned int CNMCRGetMemberListFunc::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMFunc::EncodeDispatch(pEncoder, pStream);
    if (FUN_1415fb720(this) != 0)
    {
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_aMembers.size()));
        for (CNMChatRoomMemberInfo& member : m_aMembers)
            member.EncodeFramed(pStream);
    }
    FUN_1415f9990(pEncoder);
    return 1;
}

// MS2-FUNCTIONAL: decoder wrapper lifetime and validity branch match; local decoder storage differs.
// @0x14159e420
unsigned int CNMCRGetMemberListFunc::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMCRGetMemberListFunc::Decode(&decoder, pStream);
}

// MS2-FUNCTIONAL: recovered decoder format branch; direct calls replace virtual dispatch.
// @0x14159e4b0
unsigned int CNMCRGetMemberListFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMCRGetMemberListFunc::DecodeFramed(pStream);
    return CNMCRGetMemberListFunc::Decode(pDecoder, pStream);
}

// @0x14159e510
unsigned int CNMCRGetMemberListFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    if (FUN_1415fb720(this) != 0)
    {
        // One record is decoded into the same local each time and a copy is pushed (a failed decode keeps
        // the previous record's data).
        CNMChatRoomMemberInfo member;
        unsigned int count = pDecoder->ReadU32();
        m_aMembers.clear();
        for (unsigned int i = 0; i < count; ++i)
        {
            member.DecodeFramed(pStream);
            m_aMembers.push_back(member);
        }
    }
    return FUN_1415fb750(pDecoder);
}

// MS2-PIN: ??0CNMCRGetMemberListFunc@@QEAA@XZ 0x14159e1b0
