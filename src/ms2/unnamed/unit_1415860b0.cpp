// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// MS2-UNIT: unit_1415860b0
// MS2-RANGE: 0x1415860b0-0x1415866f0 .text$mn
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
extern int FUN_1415fb700(void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(CNMSerializableDecoder*);
extern unsigned int FUN_1415f9990(void*);
extern unsigned int FUN_14156ac20(void*, unsigned int);
extern unsigned int FUN_14160b6b0(const std::vector<CNMCateFriendInfo>*);
extern unsigned int FUN_14160b8e0(const std::vector<CNMFriendInfo>*);

// @0x1415860b0
// MS2-FUNCTIONAL: initializes the recovered 0x4001 request and both list members; compiler frame and member-init order differ from the binary.
CNMGetFriendListFunc::CNMGetFriendListFunc()
    : CNMFunc(0x4001, 1, 0, 0), m_30{}, m_38{}, m_50{}
{
}

// @0x141586120
CNMGetFriendListFunc::CNMGetFriendListFunc(unsigned long long key)
    : CNMGetFriendListFunc()
{
    *reinterpret_cast<unsigned long long*>(&m_30) = key;
}

// @0x1415861a0
// MS2-FUNCTIONAL: builds the framed encoder and forwards to Encode; wrapper frame differs while preserving setup, call and cleanup.
unsigned int CNMGetFriendListFunc::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMGetFriendListFunc::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}

// @0x141586200
// MS2-FUNCTIONAL: preserves the format selector and target body; direct member calls differ from the binary's indirect slot calls.
unsigned int CNMGetFriendListFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMGetFriendListFunc::Encode(pEncoder, pStream);
    return CNMGetFriendListFunc::EncodeFramed(pStream);
}

// @0x141586260
unsigned int CNMGetFriendListFunc::Encode(CNMEncoder* encoder, CNMStream* stream)
{
    CNMFunc::EncodeDispatch(encoder, stream);
    if (FUN_1415fb700(this) != 0) {
        FUN_14156ac20(encoder, m_30.nLow);
        FUN_14156ac20(encoder, m_30.nHigh);
    } else {
        FUN_14156ac20(encoder, FUN_14160b6b0(&m_38));
        for (std::vector<CNMCateFriendInfo>::iterator it = m_38.begin(), itEnd = m_38.end(); it != itEnd; ++it)
            (*it).EncodeFramed(stream);
        FUN_14156ac20(encoder, FUN_14160b8e0(&m_50));
        for (std::vector<CNMFriendInfo>::iterator it = m_50.begin(), itEnd = m_50.end(); it != itEnd; ++it)
            (*it).EncodeFramed(stream);
    }
    FUN_1415f9990(encoder);
    return 1;
}

// @0x141586400
// MS2-FUNCTIONAL: builds the framed decoder and forwards to Decode; wrapper frame differs while preserving setup, call and cleanup.
unsigned int CNMGetFriendListFunc::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMGetFriendListFunc::Decode(&decoder, pStream);
}

// @0x141586490
// MS2-FUNCTIONAL: preserves decoder-format dispatch; direct member calls differ from the binary's indirect slot calls.
unsigned int CNMGetFriendListFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMGetFriendListFunc::DecodeFramed(pStream);
    return CNMGetFriendListFunc::Decode(pDecoder, pStream);
}

// @0x1415864f0
unsigned int CNMGetFriendListFunc::Decode(CNMSerializableDecoder* decoder, CNMStream* stream)
{
    CNMFunc::DecodeDispatch(decoder, stream);
    if (FUN_1415fb700(this) != 0) {
        m_30.nLow = decoder->ReadU32();
        m_30.nHigh = decoder->ReadU32();
    } else {
        {
            CNMCateFriendInfo category;
            const unsigned int categoryCount = decoder->ReadU32();
            m_38.clear();
            for (unsigned int i = 0; i < categoryCount; ++i) {
                category.DecodeFramed(stream);
                m_38.push_back(category);
            }
        }
        {
            CNMFriendInfo friendInfo;
            const unsigned int friendCount = decoder->ReadU32();
            m_50.clear();
            for (unsigned int i = 0; i < friendCount; ++i) {
                friendInfo.DecodeFramed(stream);
                m_50.push_back(friendInfo);
            }
        }
    }
    return static_cast<unsigned int>(FUN_1415fb750(decoder));
}

// MS2-PIN: ??0CNMGetFriendListFunc@@QEAA@XZ 0x1415860b0
