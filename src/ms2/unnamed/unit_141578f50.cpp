// Nexon Messenger new friend request data serializer methods.
// MS2-UNIT: unit_141578f50
// MS2-RANGE: 0x141578f50-0x1415794f0 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmobjects.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/placeholder/nmencoder.h"
#include "ms2/ms2recover.h"

extern void FUN_14156bcb0(void*, void*, void*);
extern void FUN_14156bd50(void*);
extern void FUN_14156be10(void*, void*, void*);
extern void FUN_14156bf10(void*);
extern void FUN_14156ab00(void*, unsigned int);
extern void FUN_14156ac20(void*, unsigned int);
extern void FUN_14156ae30(void*, const void*);
extern void FUN_1415f9990(void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(CNMSerializableDecoder*);

// MS2-FUNCTIONAL 0x141578f50: initializes the new-friend request fields and fixed-size strings.
// @0x141578f50
CNMRequestNewFriendData::CNMRequestNewFriendData() : CNMSerializable(0x7266,1,1),m_10(0),m_14{},m_54(0),m_58(0),m_5c(0),m_a0(0),m_a4(0)
{
    memset(m_60,0,sizeof(m_60));
    memset(m_a8,0,sizeof(m_a8));
    m_e8 = 0;
    memset(m_ec,0,sizeof(m_ec));
    m_1ec = 0;
}

// MS2-FUNCTIONAL 0x141579060: uses opaque stack storage for the temporary encoder; request data encoding behavior is preserved.
// @0x141579060
unsigned int CNMRequestNewFriendData::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMRequestNewFriendData::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}

// MS2-FUNCTIONAL 0x1415790c0: dispatches through the class vtable; the indirect call shape differs from the recovered image.
// @0x1415790c0
unsigned int CNMRequestNewFriendData::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMRequestNewFriendData::Encode(pEncoder, pStream);
    return CNMRequestNewFriendData::EncodeFramed(pStream);
}

// @0x141579120
unsigned int CNMRequestNewFriendData::Encode(CNMEncoder* pEncoder, CNMStream*)
{
    FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_10));
    FUN_14156ae30(pEncoder, m_14);
    FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_54));
    FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_58));
    FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_5c));
    FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_a0));
    FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_a4));
    FUN_14156ae30(pEncoder, m_60);
    FUN_14156ae30(pEncoder, m_a8);
    FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_e8));
    FUN_14156ae30(pEncoder, m_ec);
    FUN_14156ab00(pEncoder, static_cast<unsigned int>(m_1ec));
    FUN_1415f9990(pEncoder);
    return 1;
}

// MS2-FUNCTIONAL 0x141579250: uses opaque stack storage for the temporary decoder; request data decode behavior is preserved.
// @0x141579250
unsigned int CNMRequestNewFriendData::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMRequestNewFriendData::Decode(&decoder, pStream);
}

// MS2-FUNCTIONAL 0x1415792e0: dispatches through the class vtable; the indirect call shape differs from the recovered image.
// @0x1415792e0
unsigned int CNMRequestNewFriendData::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMRequestNewFriendData::DecodeFramed(pStream);
    return CNMRequestNewFriendData::Decode(pDecoder, pStream);
}

// @0x141579340
unsigned int CNMRequestNewFriendData::Decode(CNMSerializableDecoder* pDecoder, CNMStream*)
{
    m_10 = pDecoder->ReadU32();
    pDecoder->ReadStringBufAlias(m_14, 0x40);
    m_54 = pDecoder->ReadU32();
    m_58 = pDecoder->ReadU32();
    m_5c = pDecoder->ReadU32();
    m_a0 = pDecoder->ReadU32();
    m_a4 = pDecoder->ReadU32();
    pDecoder->ReadStringBufAlias(m_60, 0x40);
    pDecoder->ReadStringBufAlias(m_a8, 0x40);
    m_e8 = pDecoder->ReadU32();
    pDecoder->ReadStringBufAlias(m_ec, 0x100);
    m_1ec = pDecoder->ReadU8();
    return static_cast<unsigned int>(FUN_1415fb750(pDecoder));
}

// MS2-PIN: ??0CNMRequestNewFriendData@@QEAA@XZ 0x141578f50 ; recovered new-friend request data constructor
