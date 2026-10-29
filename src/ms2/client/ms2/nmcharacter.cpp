// Recovered from the Nexon Messenger client library: character and rejected-user records.
// MS2-UNIT: ?\nmcharacter.cpp
// MS2-RANGE: 0x141570010-0x141570860 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmfunc.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/placeholder/nmencoder.h"
#include "ms2/ms2recover.h"

extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(CNMSerializableDecoder*);
extern void FUN_1415f9990(void*);
extern void FUN_14156ac20(void*, unsigned int);
extern void FUN_14156ae30(void*, const void*);
extern void FUN_1415fc140(void*, size_t, const char*);

// initializes the category character signature, empty strings, and zero key.
// @0x141570010
CNMCharacter::CNMCharacter()
    : CNMSerializable(0x6372, 1, 1)
{
    m_10[0] = 0;
    m_50.nLow = 0;
    m_50.nHigh = 0;
    m_58[0] = 0;
}

// copies both bounded strings and stores the split 64-bit character key.
// @0x141570090
CNMCharacter::CNMCharacter(int nKeyLow, const char* pszNameAt58, const char* pszNameAt10, int nKeyHigh)
    : CNMSerializable(0x6372, 1, 1)
{
    FUN_1415fc140(m_10, sizeof m_10, pszNameAt10);
    m_50.nLow = static_cast<unsigned int>(nKeyLow);
    m_50.nHigh = static_cast<unsigned int>(nKeyHigh);
    FUN_1415fc140(m_58, sizeof m_58, pszNameAt58);
}

// copies both bounded strings and the supplied character key.
// @0x141570140
CNMCharacter::CNMCharacter(NMKey64 key, const char* pszNameAt58, const char* pszNameAt10)
    : CNMSerializable(0x6372, 1, 1)
{
    FUN_1415fc140(m_10, sizeof m_10, pszNameAt10);
    m_50 = key;
    FUN_1415fc140(m_58, sizeof m_58, pszNameAt58);
}

// frames character encoding through the recovered temporary encoder.
// @0x1415701e0
unsigned int CNMCharacter::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMCharacter::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}

// dispatches character encoding according to the serialized format.
// @0x141570240
unsigned int CNMCharacter::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMCharacter::Encode(pEncoder, pStream);
    return CNMCharacter::EncodeFramed(pStream);
}

// writes the two fixed strings and split key fields in the recovered order.
// @0x1415702a0
unsigned int CNMCharacter::Encode(CNMEncoder* pEncoder, CNMStream*)
{
    FUN_14156ae30(pEncoder, m_10);
    FUN_14156ac20(pEncoder, m_50.nLow);
    FUN_14156ac20(pEncoder, m_50.nHigh);
    FUN_14156ae30(pEncoder, m_58);
    FUN_1415f9990(pEncoder);
    return 1;
}

// frames character decoding and validates the temporary decoder.
// @0x141570320
unsigned int CNMCharacter::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMCharacter::Decode(&decoder, pStream);
}

// dispatches character decoding by decoder version.
// @0x1415703b0
unsigned int CNMCharacter::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMCharacter::DecodeFramed(pStream);
    return CNMCharacter::Decode(pDecoder, pStream);
}

// restores both fixed strings and split key fields.
// @0x141570410
unsigned int CNMCharacter::Decode(CNMSerializableDecoder* pDecoder, CNMStream*)
{
    pDecoder->ReadStringBufAlias(reinterpret_cast<char*>(m_10), sizeof m_10);
    m_50.nLow = pDecoder->ReadU32();
    m_50.nHigh = pDecoder->ReadU32();
    pDecoder->ReadStringBufAlias(reinterpret_cast<char*>(m_58), sizeof m_58);
    return FUN_1415fb750(pDecoder);
}

// initializes the rejected-user record, embedded character, and detail buffer.
// @0x1415704c0
CNMRejectedUser::CNMRejectedUser()
    : CNMSerializable(0x7275, 1, 1), m_character()
{
    m_a8[0] = 0;
}

// copies the source character and bounded detail string into a rejected-user record.
// @0x141570530
CNMRejectedUser::CNMRejectedUser(const CNMCharacter* character, const char* details)
    : CNMSerializable(0x7275, 1, 1), m_character(*character)
{
    FUN_1415fc140(m_a8, sizeof m_a8, details);
}

// frames rejected-user encoding through the recovered temporary encoder.
// @0x1415705c0
unsigned int CNMRejectedUser::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMRejectedUser::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}

// dispatches rejected-user encoding according to the serialized format.
// @0x141570620
unsigned int CNMRejectedUser::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMRejectedUser::Encode(pEncoder, pStream);
    return CNMRejectedUser::EncodeFramed(pStream);
}

// serializes the embedded character and rejected-user detail string.
// @0x141570680
unsigned int CNMRejectedUser::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    m_character.EncodeFramed(pStream);
    FUN_14156ae30(pEncoder, m_a8);
    FUN_1415f9990(pEncoder);
    return 1;
}

// frames rejected-user decoding and validates the temporary decoder.
// @0x1415706f0
unsigned int CNMRejectedUser::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMRejectedUser::Decode(&decoder, pStream);
}

// dispatches rejected-user decoding by decoder version.
// @0x141570780
unsigned int CNMRejectedUser::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMRejectedUser::DecodeFramed(pStream);
    return CNMRejectedUser::Decode(pDecoder, pStream);
}

// restores the embedded character and bounded rejected-user detail string.
// @0x1415707e0
unsigned int CNMRejectedUser::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    m_character.DecodeFramed(pStream);
    pDecoder->ReadStringBufAlias(reinterpret_cast<char*>(m_a8), sizeof m_a8);
    return FUN_1415fb750(pDecoder);
}

// MS2-PIN: ??0CNMCharacter@@QEAA@XZ 0x141570010
// MS2-PIN: ??0CNMRejectedUser@@QEAA@XZ 0x1415704c0
