// Recovered from the Nexon Messenger client library: game session member list request.
// MS2-UNIT: unit_1415a04e0
// MS2-RANGE: 0x1415a04e0-0x1415a0960 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmobjects.h"
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

// MS2-FUNCTIONAL: request ID and empty vector initialization match; helper/vector codegen differs.
// @0x1415a04e0
CNMGSGetMemberListFunc::CNMGSGetMemberListFunc()
    : CNMFunc(0xc005, 1, 0, 0), m_30()
{
}

// MS2-FUNCTIONAL: request ID, serial key, and vector initialization match; base codegen differs.
// @0x1415a0540
CNMGSGetMemberListFunc::CNMGSGetMemberListFunc(unsigned uSerialKey)
    : CNMFunc(0xc005, 1, static_cast<int>(uSerialKey), 0), m_30()
{
}

// MS2-FUNCTIONAL: framed encoder setup and cleanup match; local encoder storage differs.
// @0x1415a05a0
unsigned int CNMGSGetMemberListFunc::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMGSGetMemberListFunc::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}

// MS2-FUNCTIONAL: recovered format branch; direct calls replace virtual dispatch.
// @0x1415a0600
unsigned int CNMGSGetMemberListFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMGSGetMemberListFunc::Encode(pEncoder, pStream);
    return CNMGSGetMemberListFunc::EncodeFramed(pStream);
}

// MS2-FUNCTIONAL: reply count and ordered member payloads match; vector iteration codegen differs.
// @0x1415a0660
unsigned int CNMGSGetMemberListFunc::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMFunc::EncodeDispatch(pEncoder, pStream);
    if (FUN_1415fb720(this) != 0)
    {
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_30.size()));
        for (CNMSessionMemberInfo& member : m_30)
            member.EncodeFramed(pStream);
    }
    FUN_1415f9990(pEncoder);
    return 1;
}

// MS2-FUNCTIONAL: decoder wrapper lifetime and validity branch match; local decoder storage differs.
// @0x1415a0750
unsigned int CNMGSGetMemberListFunc::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMGSGetMemberListFunc::Decode(&decoder, pStream);
}

// MS2-FUNCTIONAL: recovered decoder format branch; direct calls replace virtual dispatch.
// @0x1415a07e0
unsigned int CNMGSGetMemberListFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMGSGetMemberListFunc::DecodeFramed(pStream);
    return CNMGSGetMemberListFunc::Decode(pDecoder, pStream);
}

// @0x1415a0840
unsigned int CNMGSGetMemberListFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    if (FUN_1415fb720(this) != 0)
    {
        // One record is decoded into the same local each time and a copy is pushed (a failed decode keeps
        // the previous record's data).
        CNMSessionMemberInfo member;
        unsigned int count = pDecoder->ReadU32();
        m_30.clear();
        for (unsigned int i = 0; i < count; ++i)
        {
            member.DecodeFramed(pStream);
            m_30.push_back(member);
        }
    }
    return FUN_1415fb750(pDecoder);
}

// MS2-PIN: ??0CNMGSGetMemberListFunc@@QEAA@XZ 0x1415a04e0
