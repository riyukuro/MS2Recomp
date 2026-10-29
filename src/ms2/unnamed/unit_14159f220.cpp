// Recovered from the Nexon Messenger client library: chat-room member info request.
// MS2-UNIT: unit_14159f220
// MS2-RANGE: 0x14159f220-0x14159f5e0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmchatroomfunc.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/placeholder/nmencoder.h"
#include "ms2/ms2recover.h"

extern int FUN_1415fb700(const void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(CNMSerializableDecoder*);
extern void FUN_1415f9990(void*);
extern void FUN_14156ac20(void*, unsigned int);
extern void FUN_14156bcb0(void*, void*, void*);
extern void FUN_14156bd50(void*);

// MS2-FUNCTIONAL: request code and member-info initialization match; vftable setup codegen differs.
// @0x14159f220
CNMCRGetMemberInfoFunc::CNMCRGetMemberInfoFunc()
    : CNMFunc(0xb00a, 1, 0, 0), m_uWhich(0), m_34(0), m_info()
{
}

// MS2-FUNCTIONAL: request code, selector, and member-info initialization match; base codegen differs.
// @0x14159f290
CNMCRGetMemberInfoFunc::CNMCRGetMemberInfoFunc(unsigned uSerialKey, unsigned uWhich)
    : CNMFunc(0xb00a, 1, static_cast<int>(uSerialKey), 0), m_uWhich(uWhich), m_34(0), m_info()
{
}

// MS2-FUNCTIONAL: framed encoder setup and cleanup match; local encoder storage differs.
// @0x14159f310
unsigned int CNMCRGetMemberInfoFunc::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMCRGetMemberInfoFunc::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}

// MS2-FUNCTIONAL: recovered format branch; direct calls replace virtual dispatch.
// @0x14159f370
unsigned int CNMCRGetMemberInfoFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMCRGetMemberInfoFunc::Encode(pEncoder, pStream);
    return CNMCRGetMemberInfoFunc::EncodeFramed(pStream);
}

// MS2-FUNCTIONAL: request selector/reply member branches and finish call match; direct dispatch replaces virtual calls.
// @0x14159f3d0
unsigned int CNMCRGetMemberInfoFunc::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMFunc::EncodeDispatch(pEncoder, pStream);
    if (FUN_1415fb700(this) == 0)
        m_info.EncodeFramed(pStream);
    else
        FUN_14156ac20(pEncoder, m_uWhich);
    FUN_1415f9990(pEncoder);
    return 1;
}

// MS2-FUNCTIONAL: decoder wrapper lifetime and validity branch match; local decoder storage differs.
// @0x14159f460
unsigned int CNMCRGetMemberInfoFunc::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMCRGetMemberInfoFunc::Decode(&decoder, pStream);
}

// MS2-FUNCTIONAL: recovered decoder format branch; direct calls replace virtual dispatch.
// @0x14159f4f0
unsigned int CNMCRGetMemberInfoFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMCRGetMemberInfoFunc::DecodeFramed(pStream);
    return CNMCRGetMemberInfoFunc::Decode(pDecoder, pStream);
}

// MS2-FUNCTIONAL: request selector/reply member branches and validity check match; direct dispatch replaces virtual calls.
// @0x14159f550
unsigned int CNMCRGetMemberInfoFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    if (FUN_1415fb700(this) == 0)
        m_info.DecodeFramed(pStream);
    else
    {
        void** vftable = *reinterpret_cast<void***>(pDecoder);
        using ReadU32 = unsigned int(__fastcall*)(void*);
        m_uWhich = reinterpret_cast<ReadU32>(vftable[3])(pDecoder);
    }
    return FUN_1415fb750(pDecoder);
}

// MS2-PIN: ??0CNMCRGetMemberInfoFunc@@QEAA@XZ 0x14159f220
