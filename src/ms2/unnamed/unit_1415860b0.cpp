// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// MS2-UNIT: unit_1415860b0
// MS2-RANGE: 0x1415860b0-0x1415866f0 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmobjects.h"
#include "ms2/ms2recover.h"

extern void FUN_14156bcb0(void*, void*, void*);
extern void FUN_14156bd50(void*);
extern void FUN_14156be10(void*, void*, void*);
extern void FUN_14156bf10(void*);
extern bool FUN_1415fb700(void*);
extern bool FUN_1415fb750(void*);
extern int FUN_1415fb6d0(void*);
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
unsigned int CNMGetFriendListFunc::EncodeFramed(CNMStream* stream)
{
    unsigned char framed[0x18];
    FUN_14156bcb0(framed, stream, this);
    unsigned int result = Encode(reinterpret_cast<CNMEncoder*>(framed), stream);
    FUN_14156bd50(framed);
    return result;
}

// @0x141586200
// MS2-FUNCTIONAL: preserves the format selector and target body; direct member calls differ from the binary's indirect slot calls.
unsigned int CNMGetFriendListFunc::EncodeDispatch(CNMEncoder* encoder, CNMStream* stream)
{
    if (m_bFormat == 1) return Encode(encoder, stream);
    return EncodeFramed(stream);
}

// @0x141586260
// MS2-FUNCTIONAL: serializes both vectors and scalar reply keys in order; C++ iteration replaces the binary's STL iterator helpers.
unsigned int CNMGetFriendListFunc::Encode(CNMEncoder* encoder, CNMStream* stream)
{
    CNMFunc::EncodeDispatch(encoder, stream);
    if (!FUN_1415fb700(this)) {
        FUN_14156ac20(encoder, FUN_14160b6b0(&m_38));
        for (auto& category : m_38) category.EncodeFramed(stream);
        FUN_14156ac20(encoder, FUN_14160b8e0(&m_50));
        for (auto& friendInfo : m_50) friendInfo.EncodeFramed(stream);
    } else {
        FUN_14156ac20(encoder, m_30.nLow);
        FUN_14156ac20(encoder, m_30.nHigh);
    }
    FUN_1415f9990(encoder);
    return 1;
}

// @0x141586400
// MS2-FUNCTIONAL: builds the framed decoder and forwards to Decode; wrapper frame differs while preserving setup, call and cleanup.
unsigned int CNMGetFriendListFunc::DecodeFramed(CNMStream* stream)
{
    unsigned char framed[0x38];
    FUN_14156be10(framed, stream, this);
    unsigned int result = 0;
    if (FUN_1415fb750(framed)) result = Decode(reinterpret_cast<CNMSerializableDecoder*>(framed), stream);
    FUN_14156bf10(framed);
    return result;
}

// @0x141586490
// MS2-FUNCTIONAL: preserves decoder-format dispatch; direct member calls differ from the binary's indirect slot calls.
unsigned int CNMGetFriendListFunc::DecodeDispatch(CNMSerializableDecoder* decoder, CNMStream* stream)
{
    if (FUN_1415fb6d0(decoder) == 2) return DecodeFramed(stream);
    return Decode(decoder, stream);
}

// @0x1415864f0
// MS2-FUNCTIONAL: decodes list elements and key words in wire order; C++ vector operations replace the binary's STL iterator helpers.
unsigned int CNMGetFriendListFunc::Decode(CNMSerializableDecoder* decoder, CNMStream* stream)
{
    CNMFunc::DecodeDispatch(decoder, stream);
    void** decoderVtable = *reinterpret_cast<void***>(decoder);
    using ReadU32 = unsigned int(__fastcall*)(CNMSerializableDecoder*);
    auto readU32 = reinterpret_cast<ReadU32>(decoderVtable[3]);
    if (!FUN_1415fb700(this)) {
        const unsigned int categoryCount = readU32(decoder);
        m_38.clear();
        for (unsigned int i = 0; i < categoryCount; ++i) {
            CNMCateFriendInfo category;
            category.DecodeFramed(stream);
            m_38.push_back(std::move(category));
        }
        const unsigned int friendCount = readU32(decoder);
        m_50.clear();
        for (unsigned int i = 0; i < friendCount; ++i) {
            CNMFriendInfo friendInfo;
            friendInfo.DecodeFramed(stream);
            m_50.push_back(std::move(friendInfo));
        }
    } else {
        m_30.nLow = readU32(decoder);
        m_30.nHigh = readU32(decoder);
    }
    return static_cast<unsigned int>(FUN_1415fb750(decoder));
}

// MS2-PIN: ??0CNMGetFriendListFunc@@QEAA@XZ 0x1415860b0
