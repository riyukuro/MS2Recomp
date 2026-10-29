// Nexon Messenger guild record serializer methods.
// MS2-UNIT: unit_141573790
// MS2-RANGE: 0x141573790-0x141574050 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/placeholder/nmfunc.h"
#include "ms2/placeholder/nmencoder.h"
#include "ms2/ms2recover.h"

extern void FUN_14156bcb0(void*, void*, void*);
extern void FUN_14156bd50(void*);
extern void FUN_14156be10(void*, void*, void*);
extern void FUN_14156bf10(void*);
extern void FUN_14156ab00(void*, unsigned char);
extern void FUN_14156ac20(void*, unsigned int);
extern void FUN_14156acb0(void*, unsigned long long);
extern void FUN_14156ae30(void*, const void*);
extern void FUN_1415f9990(void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(CNMSerializableDecoder*);
extern void FUN_1415eb480(void*, unsigned int, long long);

// @0x141573870
void* FUN_141573870(CNMGuildInfoEx* info, void* out)
{
    FUN_1415eb480(out, static_cast<unsigned int>(info->m_78), info->m_10);
    return out;
}

// MS2-FUNCTIONAL 0x141573790: initializes the guild record signature and its fixed-size fields.
// @0x141573790
CNMGuildInfoEx::CNMGuildInfoEx() : CNMSerializable(0x6765,1,1),m_10(0),m_18{},m_58{},m_78(0),m_7c{},m_17c(0),m_180(0),m_184(0),m_188(0) {}

// MS2-FUNCTIONAL 0x141573ca0: initializes the guild-list serializable and vector.
// @0x141573ca0
CNMGuildListExInfo::CNMGuildListExInfo() : CNMSerializable(0x656c,1,1),m_aGuilds{} {}

// MS2-FUNCTIONAL 0x141573cf0: frames the guild list payload.
// @0x141573cf0
unsigned int CNMGuildListExInfo::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMGuildListExInfo::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}

// MS2-FUNCTIONAL 0x141573d50: selects framed or direct guild-list encoding.
// @0x141573d50
unsigned int CNMGuildListExInfo::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMGuildListExInfo::Encode(pEncoder, pStream);
    return CNMGuildListExInfo::EncodeFramed(pStream);
}

// MS2-FUNCTIONAL 0x141573db0: serializes the guild count and each guild in vector order.
// @0x141573db0
unsigned int CNMGuildListExInfo::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_aGuilds.size()));
    for (std::vector<CNMGuildInfoEx>::iterator it = m_aGuilds.begin(), end = m_aGuilds.end(); it != end; ++it)
        (*it).EncodeFramed(pStream);
    FUN_1415f9990(pEncoder);
    return 1;
}

// MS2-FUNCTIONAL 0x141573e70: decodes the framed guild-list payload.
// @0x141573e70
unsigned int CNMGuildListExInfo::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMGuildListExInfo::Decode(&decoder, pStream);
}

// MS2-FUNCTIONAL 0x141573f00: selects direct or framed guild-list decoding.
// @0x141573f00
unsigned int CNMGuildListExInfo::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMGuildListExInfo::DecodeFramed(pStream);
    return CNMGuildListExInfo::Decode(pDecoder, pStream);
}

// @0x141573f60
unsigned int CNMGuildListExInfo::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    // One guild is decoded (framed) into the same local each time and a copy is pushed (a failed decode keeps the
    // previous guild's data).
    {
        CNMGuildInfoEx guild;
        unsigned int count = pDecoder->ReadU32();
        m_aGuilds.clear();
        for (unsigned int i = 0; i < count; ++i) {
            guild.DecodeFramed(pStream);
            m_aGuilds.push_back(guild);
        }
    }
    return static_cast<unsigned int>(FUN_1415fb750(pDecoder));
}

// MS2-PIN: ??0CNMGuildInfoEx@@QEAA@XZ 0x141573790 ; recovered guild info constructor
// MS2-PIN: ??0CNMGuildListExInfo@@QEAA@XZ 0x141573ca0 ; recovered guild list constructor

// MS2-FUNCTIONAL 0x1415738b0: uses opaque stack storage for the temporary encoder; guild encoding behavior is preserved.
// @0x1415738b0
unsigned int CNMGuildInfoEx::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMGuildInfoEx::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}

// MS2-FUNCTIONAL 0x141573910: dispatches through the class vtable; the indirect call shape differs from the recovered image.
// @0x141573910
unsigned int CNMGuildInfoEx::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMGuildInfoEx::Encode(pEncoder, pStream);
    return CNMGuildInfoEx::EncodeFramed(pStream);
}

// @0x141573970
unsigned int CNMGuildInfoEx::Encode(CNMEncoder* pEncoder, CNMStream*)
{
    FUN_14156acb0(pEncoder, static_cast<unsigned long long>(m_10));
    FUN_14156ae30(pEncoder, m_18);
    FUN_14156ae30(pEncoder, m_58);
    FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_78));
    FUN_14156ae30(pEncoder, m_7c);
    FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_17c));
    FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_180));
    FUN_14156ab00(pEncoder, static_cast<unsigned int>(m_184));
    FUN_14156ab00(pEncoder, static_cast<unsigned int>(m_188));
    FUN_1415f9990(pEncoder);
    return 1;
}

// MS2-FUNCTIONAL 0x141573a60: uses opaque stack storage for the temporary decoder; decode behavior is preserved.
// @0x141573a60
unsigned int CNMGuildInfoEx::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMGuildInfoEx::Decode(&decoder, pStream);
}

// MS2-FUNCTIONAL 0x141573af0: dispatches through the class vtable; the indirect call shape differs from the recovered image.
// @0x141573af0
unsigned int CNMGuildInfoEx::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMGuildInfoEx::DecodeFramed(pStream);
    return CNMGuildInfoEx::Decode(pDecoder, pStream);
}

// @0x141573b50
unsigned int CNMGuildInfoEx::Decode(CNMSerializableDecoder* pDecoder, CNMStream*)
{
    m_10 = pDecoder->ReadU64();
    pDecoder->ReadStringBufAlias(m_18, 0x40);
    pDecoder->ReadStringBufAlias(m_58, 0x20);
    m_78 = pDecoder->ReadU32();
    pDecoder->ReadStringBufAlias(m_7c, 0x100);
    m_17c = pDecoder->ReadU32();
    m_180 = pDecoder->ReadU32();
    m_184 = pDecoder->ReadU8();
    m_188 = pDecoder->ReadU8();
    return static_cast<unsigned int>(FUN_1415fb750(pDecoder));
}
