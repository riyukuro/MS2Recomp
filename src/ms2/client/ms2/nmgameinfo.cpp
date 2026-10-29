// Recovered Nexon Messenger game information records.
// MS2-UNIT: ?\nmgameinfo.cpp
// MS2-RANGE: 0x141579850-0x14157a260 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmfunc.h"
#include "ms2/placeholder/nmobjects.h"
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

// MS2-FUNCTIONAL: initializes the game record and clears every recovered field.
// @0x141579850
CNMGameInfo::CNMGameInfo()
    : CNMSerializable(0x6766, 1, 1), m_10(0), m_14(0), m_18{}, m_38{}, m_78{},
      m_98{}, m_498{}, m_898{}, m_c98(0), m_c9c(0), m_ca0{}, m_10a0{}, m_14a0(0)
{
}

// MS2-FUNCTIONAL: frames game information encoding through the recovered encoder.
// @0x141579990
unsigned int CNMGameInfo::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMGameInfo::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}

// MS2-FUNCTIONAL: selects raw or framed encoding from the object format byte.
// @0x1415799f0
unsigned int CNMGameInfo::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMGameInfo::Encode(pEncoder, pStream);
    return CNMGameInfo::EncodeFramed(pStream);
}

// MS2-FUNCTIONAL: writes the game record fields in recovered wire order.
// @0x141579a50
unsigned int CNMGameInfo::Encode(CNMEncoder* pEncoder, CNMStream*)
{
    FUN_14156ac20(pEncoder, m_10);
    FUN_14156ac20(pEncoder, m_14);
    FUN_14156ae30(pEncoder, m_18);
    FUN_14156ae30(pEncoder, m_38);
    FUN_14156ae30(pEncoder, m_78);
    FUN_14156ae30(pEncoder, m_98);
    FUN_14156ae30(pEncoder, m_498);
    FUN_14156ae30(pEncoder, m_898);
    FUN_14156ab00(pEncoder, m_c98);
    FUN_14156ac20(pEncoder, m_c9c);
    FUN_14156ae30(pEncoder, m_ca0);
    FUN_14156ae30(pEncoder, m_10a0);
    FUN_14156ac20(pEncoder, m_14a0);
    FUN_1415f9990(pEncoder);
    return 1;
}

// MS2-FUNCTIONAL: validates a framed game record before decoding its payload.
// @0x141579ba0
unsigned int CNMGameInfo::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMGameInfo::Decode(&decoder, pStream);
}

// MS2-FUNCTIONAL: selects framed decoding for version two records.
// @0x141579c30
unsigned int CNMGameInfo::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMGameInfo::DecodeFramed(pStream);
    return CNMGameInfo::Decode(pDecoder, pStream);
}

// MS2-FUNCTIONAL: restores game record fields in serialized order.
// @0x141579c90
unsigned int CNMGameInfo::Decode(CNMSerializableDecoder* pDecoder, CNMStream*)
{
    m_10 = pDecoder->ReadU32();
    m_14 = pDecoder->ReadU32();
    pDecoder->ReadStringBufAlias(reinterpret_cast<char*>(m_18), sizeof m_18);
    pDecoder->ReadStringBufAlias(reinterpret_cast<char*>(m_38), sizeof m_38);
    pDecoder->ReadStringBufAlias(reinterpret_cast<char*>(m_78), sizeof m_78);
    pDecoder->ReadStringBufAlias(reinterpret_cast<char*>(m_98), sizeof m_98);
    pDecoder->ReadStringBufAlias(reinterpret_cast<char*>(m_498), sizeof m_498);
    pDecoder->ReadStringBufAlias(reinterpret_cast<char*>(m_898), sizeof m_898);
    m_c98 = pDecoder->ReadU8();
    m_c9c = pDecoder->ReadU32();
    pDecoder->ReadStringBufAlias(reinterpret_cast<char*>(m_ca0), sizeof m_ca0);
    pDecoder->ReadStringBufAlias(reinterpret_cast<char*>(m_10a0), sizeof m_10a0);
    m_14a0 = pDecoder->ReadU32();
    return FUN_1415fb750(pDecoder);
}

// MS2-FUNCTIONAL: initializes the game list serialization header and vector.
// @0x141579eb0
CNMGameListData::CNMGameListData() : CNMSerializable(0x6764, 1, 1), m_games()
{
}

// MS2-FUNCTIONAL: frames game list encoding through the recovered encoder.
// @0x141579f00
unsigned int CNMGameListData::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMGameListData::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}

// MS2-FUNCTIONAL: selects raw or framed game list encoding.
// @0x141579f60
unsigned int CNMGameListData::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMGameListData::Encode(pEncoder, pStream);
    return CNMGameListData::EncodeFramed(pStream);
}

// MS2-FUNCTIONAL: serializes the vector count and each framed game record.
// @0x141579fc0
unsigned int CNMGameListData::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_games.size()));
    for (CNMGameInfo& game : m_games)
        game.EncodeFramed(pStream);
    FUN_1415f9990(pEncoder);
    return 1;
}

// MS2-FUNCTIONAL: validates a framed game list before decoding its contents.
// @0x14157a080
unsigned int CNMGameListData::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMGameListData::Decode(&decoder, pStream);
}

// MS2-FUNCTIONAL: selects framed game list decoding for version two records.
// @0x14157a110
unsigned int CNMGameListData::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMGameListData::DecodeFramed(pStream);
    return CNMGameListData::Decode(pDecoder, pStream);
}

// MS2-FUNCTIONAL: replaces the list from its count and framed game records.
// @0x14157a170
unsigned int CNMGameListData::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMGameInfo game;
    const unsigned int count = pDecoder->ReadCount();
    m_games.clear();
    for (unsigned int i = 0; i < count; ++i) {
        game.CNMGameInfo::DecodeFramed(pStream);
        m_games.push_back(game);
    }
    return FUN_1415fb750(pDecoder);
}
