// Recovered from the Nexon Messenger client library: friend categories and category friend lists.
// MS2-UNIT: ?\nmcategoryinfo.cpp
// MS2-RANGE: 0x14156f7e0-0x141570010 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmfunc.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/placeholder/nmencoder.h"
#include "ms2/ms2recover.h"

extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(const void*);
extern int FUN_1415fb6d0(CNMSerializableDecoder*);
extern void FUN_1415f9990(void*);
extern void FUN_14156ac20(void*, unsigned int);
extern void FUN_14156ab00(void*, unsigned char);
extern void FUN_14156ae30(void*, const void*);
extern void FUN_14156bcb0(void*, void*, void*);
extern void FUN_14156be10(void*, void*, void*);
extern void FUN_14156bd50(void*);
extern void FUN_1415e81d0(void*);

// MS2-FUNCTIONAL: reconstructs the zeroed category record with the recovered serializer signature.
// @0x14156f7e0
CNMCategoryInfo::CNMCategoryInfo()
    : CNMSerializable(0x6369, 1, 1), m_10(0), m_14{0, 0}, m_1c{}, m_3c(0), m_3d(0)
{
}

// MS2-FUNCTIONAL: framed encoder setup, virtual record dispatch, and cleanup match the recovered wrapper.
// @0x14156f870
unsigned int CNMCategoryInfo::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMCategoryInfo::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}

// MS2-FUNCTIONAL: routes category encoding according to the record format.
// @0x14156f8d0
unsigned int CNMCategoryInfo::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMCategoryInfo::Encode(pEncoder, pStream);
    return CNMCategoryInfo::EncodeFramed(pStream);
}

// MS2-FUNCTIONAL: writes the three scalar fields, fixed text, and kind-specific state in recovered order.
// @0x14156f930
unsigned int CNMCategoryInfo::Encode(CNMEncoder* pEncoder, CNMStream*)
{
    FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_10));
    FUN_14156ac20(pEncoder, m_14.nLow);
    FUN_14156ac20(pEncoder, m_14.nHigh);
    FUN_14156ae30(pEncoder, m_1c);
    if (m_bKind == 1)
    {
        FUN_14156ab00(pEncoder, m_3c);
        FUN_14156ab00(pEncoder, m_3d);
    }
    FUN_1415f9990(pEncoder);
    return 1;
}

// MS2-FUNCTIONAL: decoder wrapper lifetime and validation match the recovered framed path.
// @0x14156f9e0
unsigned int CNMCategoryInfo::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMCategoryInfo::Decode(&decoder, pStream);
}

// MS2-FUNCTIONAL: routes category decoding according to the decoder version.
// @0x14156fa70
unsigned int CNMCategoryInfo::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMCategoryInfo::DecodeFramed(pStream);
    return CNMCategoryInfo::Decode(pDecoder, pStream);
}

// MS2-FUNCTIONAL: restores the scalar fields, fixed text, and base-category flags from the decoder.
// @0x14156fad0
unsigned int CNMCategoryInfo::Decode(CNMSerializableDecoder* pDecoder, CNMStream*)
{
    m_10 = static_cast<int>(pDecoder->ReadU32());
    m_14.nLow = pDecoder->ReadU32();
    m_14.nHigh = pDecoder->ReadU32();
    pDecoder->ReadStringBufAlias(reinterpret_cast<char*>(m_1c), sizeof m_1c);
    if (m_bKind == 1)
    {
        m_3c = pDecoder->ReadU8();
        m_3d = pDecoder->ReadU8();
    }
    return FUN_1415fb750(pDecoder);
}

// MS2-FUNCTIONAL: initializes the friend category and its vector, then applies the derived record kind.
// @0x14156fbb0
CNMCateFriendInfo::CNMCateFriendInfo()
    : CNMCategoryInfo(), m_aFriends()
{
    ++m_bKind;
}

// MS2-FUNCTIONAL: frames the derived friend-category encoder.
// @0x14156fc10
unsigned int CNMCateFriendInfo::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMCateFriendInfo::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}

// MS2-FUNCTIONAL: selects the derived encoder using the record format.
// @0x14156fc70
unsigned int CNMCateFriendInfo::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMCateFriendInfo::Encode(pEncoder, pStream);
    return CNMCateFriendInfo::EncodeFramed(pStream);
}

// @0x14156fcd0
unsigned int CNMCateFriendInfo::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMCategoryInfo::EncodeDispatch(pEncoder, pStream);
    FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_aFriends.size()));
    for (std::vector<CNMFriendInfo>::iterator it = m_aFriends.begin(), end = m_aFriends.end(); it != end; ++it)
        (*it).EncodeFramed(pStream);
    FUN_14156ab00(pEncoder, m_3c);
    FUN_14156ab00(pEncoder, m_3d);
    FUN_1415f9990(pEncoder);
    return 1;
}

// MS2-FUNCTIONAL: frames derived friend-category decoding and validates the temporary decoder.
// @0x14156fdd0
unsigned int CNMCateFriendInfo::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMCateFriendInfo::Decode(&decoder, pStream);
}

// MS2-FUNCTIONAL: dispatches derived decoding by the decoder record version.
// @0x14156fe60
unsigned int CNMCateFriendInfo::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMCateFriendInfo::DecodeFramed(pStream);
    return CNMCateFriendInfo::Decode(pDecoder, pStream);
}

// @0x14156fec0
unsigned int CNMCateFriendInfo::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMCategoryInfo::DecodeDispatch(pDecoder, pStream);
    {
        CNMFriendInfo friendInfo;
        unsigned int count = pDecoder->ReadU32();
        m_aFriends.clear();
        for (unsigned int i = 0; i < count; ++i)
        {
            friendInfo.DecodeFramed(pStream);
            m_aFriends.push_back(friendInfo);
        }
    }
    m_3c = pDecoder->ReadU8();
    m_3d = pDecoder->ReadU8();
    return FUN_1415fb750(pDecoder);
}

// MS2-PIN: ??0CNMCategoryInfo@@QEAA@XZ 0x14156f7e0
// MS2-PIN: ??0CNMCateFriendInfo@@QEAA@XZ 0x14156fbb0
