// nmfunc.h - Nexon Messenger (NM) client library request objects ("CNM...Func"). NOT an original Nexon header.
// The game links the NM client library statically (0x141569a00-0x14160bd70). A request is a CNMFunc-derived
// object built on the stack, handed to CNMManager::CallNMFunc and read back (the reply members) before its
// destructor runs. Class names are RTTI names; member names are invented unless noted. Layouts are from the
// classes' constructors and from the wrappers in unit_1415c30d0 (frame sizes = sizeof), cross-checked against the
// third-party v2525 snapshot. Constructors/destructors live in the library's other units and are only declared.
#pragma once

#include <vector>
#include "ms2/ms2layout.h"

class CNMEncoder;
class CNMStream;
class CNMSerializableDecoder;
class CNMNoteInfo2;

// The library's serializable base, vftable 0x142f3bd18 (8 slots; slot names per the v2525 snapshot). Every record,
// request and event derives from it.
class CNMSerializable
{
public:
    CNMSerializable(unsigned short wSignature, unsigned char bKind, unsigned char bFormat);
    CNMSerializable(const CNMSerializable& r) noexcept;         // 0x1415eafb0
    virtual ~CNMSerializable();                                 // 0x1415eec70
    virtual unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream);
    virtual unsigned int EncodeFramed(CNMStream* pStream);
    virtual unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream);
    virtual unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream);
    virtual unsigned int DecodeFramed(CNMStream* pStream);
    virtual unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream);
    virtual CNMSerializable* CopyFrom(CNMSerializable* pSrc);   // 0x14156c9d0 (never overridden by the records)

    unsigned short m_wSignature;                                // +0x08
    unsigned char m_bKind;                                      // +0x0a
    unsigned char m_bFormat;                                    // +0x0b
    unsigned char m_bFlag;                                      // +0x0c
};
MS2_CHECK_SIZE(CNMSerializable, 0x10);

class CNMFunc : public CNMSerializable
{
public:
    CNMFunc(int nFuncId, int nDirection, int n18, int n1c);       // 0x14157d4c0
    virtual ~CNMFunc() = default;                                         // 0x1415ed640
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override; // 0x14157d630
    unsigned int EncodeFramed(CNMStream* pStream) override;                // 0x14157d570
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override; // 0x14157d5d0
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override; // 0x14157d790
    unsigned int DecodeFramed(CNMStream* pStream) override;                // 0x14157d6a0
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override; // 0x14157d730

    int m_nFuncId;                                              // +0x10
    int m_nDirection;                                           // +0x14 (0 = reply)
    int m_n18;
    int m_n1c;
    int m_n20;
    int m_n24;
    int m_n28;
    int m_n2c;
};
MS2_CHECK_SIZE(CNMFunc, 0x30);

// Fixed-capacity string holding only a heap pointer (the shared empty string until assigned); bodies in the library
// (Free: unit_1415f9410). The destructor is the inline one-liner the exe instantiates per N in unit_1415eb6c0.
template <int N>
class CNMStr
{
public:
    CNMStr();
    CNMStr(const CNMStr& r);
    ~CNMStr() { Free(); }
    CNMStr& operator=(const CNMStr& r);
    void Free();

    char* m_p;
};

// The library's singleton dispatcher (RTTI CNMManager). Only the two calls the request wrappers make.
class CNMManager
{
public:
    static CNMManager* GetInstance();                           // 0x1415fa260
    int CallNMFunc(CNMFunc* pFunc);                             // 0x1415cb440 (TRUE when the reply arrived)
};

// ---- list elements (std::vector<T> members of the list requests/events) -------------------------------------------
// The records are CNMSerializable-derived (RTTI names and bases). Recovered layouts follow the implicit copy/move
// constructors (unit_1415e5c20, which defines them) and the third-party v2525 snapshot; member names are offsets.
// Each record overrides the six serializer slots (vftable slots 1..6; slot 7 stays CNMSerializable::CopyFrom) and
// declares its destructor and operator= (out of line in the library). Records still marked m_body are not recovered yet.

// 8-byte user key, two dwords (copied as one qword; 4-byte aligned in the records).
struct NMKey64
{
    unsigned int nLow;
    unsigned int nHigh;
};
MS2_CHECK_SIZE(NMKey64, 0x8);

struct NMChatSessionTarget
{
    unsigned __int64 uIDCode;
    unsigned int uVirtualIDCode;
    unsigned int n0c;
};
MS2_CHECK_SIZE(NMChatSessionTarget, 0x10);

// CNMRequestMultiChatSessionExFunc target (0x18, trivially copyable).
struct NMFriendKey
{
    unsigned __int64 uIDCode;
    unsigned int n08;
    unsigned int n0c;
    unsigned int n10;
    unsigned int n14;
};
MS2_CHECK_SIZE(NMFriendKey, 0x18);

// Avatar item record (no data of its own), 0x10 bytes, vftable 0x142f3bd60.
class CNMAvatarItemInfo : public CNMSerializable
{
public:
    CNMAvatarItemInfo();
    CNMAvatarItemInfo(const CNMAvatarItemInfo& r) noexcept;  // 0x1415e8970
    CNMAvatarItemInfo(CNMAvatarItemInfo&& r) noexcept;       // 0x1415e8930
    virtual ~CNMAvatarItemInfo() = default;                               // 0x1415ec300
    CNMAvatarItemInfo& operator=(const CNMAvatarItemInfo& r);
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
};
MS2_CHECK_SIZE(CNMAvatarItemInfo, 0x10);

// Full avatar record (no data of its own), 0x10 bytes, vftable 0x142f3bda8.
class CNMAvatarFullInfo : public CNMAvatarItemInfo
{
public:
    CNMAvatarFullInfo();
    CNMAvatarFullInfo(const CNMAvatarFullInfo& r) noexcept;  // 0x1415e88f0
    CNMAvatarFullInfo(CNMAvatarFullInfo&& r) noexcept;       // 0x1415e88b0
    virtual ~CNMAvatarFullInfo() = default;                               // 0x1415ec2e0
    CNMAvatarFullInfo& operator=(const CNMAvatarFullInfo& r);
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
};
MS2_CHECK_SIZE(CNMAvatarFullInfo, 0x10);

// Game character, 0x98 bytes, vftable 0x142f3c130.
class CNMCharacter : public CNMSerializable
{
public:
    CNMCharacter();
    CNMCharacter(const CNMCharacter& r) noexcept;               // 0x1415e8c60
    CNMCharacter(CNMCharacter&& r) noexcept;                    // 0x1415e8be0
    virtual ~CNMCharacter() = default;                                    // 0x1415ecdb0
    CNMCharacter& operator=(const CNMCharacter& r);
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    char m_10[0x40];                                            // +0x10
    NMKey64 m_50;                                               // +0x50
    char m_58[0x40];                                            // +0x58
};
MS2_CHECK_SIZE(CNMCharacter, 0x98);

// User record base, 0xb0 bytes, vftable 0x142f3bdf0.
class CNMDefaultUserInfo : public CNMSerializable
{
public:
    CNMDefaultUserInfo();
    CNMDefaultUserInfo(const CNMDefaultUserInfo& r) noexcept;   // 0x1415e9110
    CNMDefaultUserInfo(CNMDefaultUserInfo&& r) noexcept;        // 0x1415e9020
    virtual ~CNMDefaultUserInfo() = default;                              // 0x1415ed1c0
    CNMDefaultUserInfo& operator=(const CNMDefaultUserInfo& r);
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    char m_10[0x40];                                            // +0x10
    __int64 m_50;                                                // +0x50
    int m_58;                                                   // +0x58
    char m_5c[0x40];                                            // +0x5c
    int m_9c;                                                   // +0x9c
    int m_a0;                                                   // +0xa0
    int m_a4;                                                   // +0xa4
    short m_a8;                                                 // +0xa8
};
MS2_CHECK_SIZE(CNMDefaultUserInfo, 0xb0);

// Real (logged-in) user record, 0x1a8 bytes, vftable 0x142f3bf10.
class CNMRealUserInfo : public CNMDefaultUserInfo
{
public:
    CNMRealUserInfo();
    CNMRealUserInfo(const CNMRealUserInfo& r) noexcept;         // 0x1415eacc0
    CNMRealUserInfo(CNMRealUserInfo&& r) noexcept;              // 0x1415eaad0
    virtual ~CNMRealUserInfo() = default;                                 // 0x1415ee780
    CNMRealUserInfo& operator=(const CNMRealUserInfo& r);
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    char m_b0[0x20];                                            // +0xb0
    char m_d0[0x40];                                            // +0xd0
    int m_110;                                                  // +0x110
    int m_114;                                                  // +0x114
    int m_118;                                                  // +0x118
    int m_11c;                                                  // +0x11c
    short m_120;                                                // +0x120
    int m_124;                                                  // +0x124
    short m_128;                                                // +0x128
    SYSTEMTIME m_12a;                                           // +0x12a
    CNMAvatarFullInfo m_140;                                    // +0x140
    int m_150;                                                  // +0x150
    int m_154;                                                  // +0x154
    int m_158;                                                  // +0x158
    int m_15c;                                                  // +0x15c
    unsigned char m_160;                                        // +0x160
    char m_161[0x40];                                           // +0x161
};
MS2_CHECK_SIZE(CNMRealUserInfo, 0x1a8);

// Friend user record, 0xd8 bytes, vftable 0x142f3be38.
class CNMRealFriendInfo : public CNMDefaultUserInfo
{
public:
    CNMRealFriendInfo();
    CNMRealFriendInfo(const CNMRealFriendInfo& r) noexcept;     // 0x1415eaa40
    CNMRealFriendInfo(CNMRealFriendInfo&& r) noexcept;          // 0x1415ea9b0
    virtual ~CNMRealFriendInfo() = default;                               // 0x1415ee710
    CNMRealFriendInfo& operator=(const CNMRealFriendInfo& r);
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    CNMAvatarItemInfo m_b0;                                     // +0xb0
    SYSTEMTIME m_c0;                                            // +0xc0
    unsigned char m_d0;                                         // +0xd0
};
MS2_CHECK_SIZE(CNMRealFriendInfo, 0xd8);

// Virtual friend record, 0x4c0 bytes, vftable 0x142f3be80.
class CNMVirtualFriendInfo : public CNMSerializable
{
public:
    CNMVirtualFriendInfo();
    virtual ~CNMVirtualFriendInfo() = default;
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    unsigned long long m_10;
    int m_18, m_1c, m_20, m_24;
    char m_28[0x40];
    char m_68[0x40];
    char m_a8[0x3e8];
    char m_490[0x20];
    int m_4b0, m_4b4, m_4b8, m_4bc;
};
MS2_CHECK_SIZE(CNMVirtualFriendInfo, 0x4c0);

// Friend list entry, 0x580 bytes, vftable 0x142f3bec8.
class CNMFriendInfo : public CNMRealFriendInfo
{
public:
    CNMFriendInfo();
    CNMFriendInfo(const CNMFriendInfo& r) noexcept;             // 0x1415e97b0
    CNMFriendInfo(CNMFriendInfo&& r) noexcept;                  // 0x1415e96a0
    virtual ~CNMFriendInfo() = default;                                   // 0x1415ed5b0
    CNMFriendInfo& operator=(const CNMFriendInfo& r);
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    NMFriendKey m_key;                                          // +0xd8
    char m_f0[0x40];                                            // +0xf0
    char m_130[0x40];                                           // +0x130
    char m_170[0x3e8];                                          // +0x170
    char m_558[0x20];                                           // +0x558
    unsigned int m_578;                                         // +0x578
    unsigned int m_57c;                                         // +0x57c
};
MS2_CHECK_SIZE(CNMFriendInfo, 0x580);

// Friend category, 0x40 bytes, vftable 0x142f3c0a0.
class CNMCategoryInfo : public CNMSerializable
{
public:
    CNMCategoryInfo(const CNMCategoryInfo& r) noexcept;         // 0x1415e8b40
    CNMCategoryInfo(CNMCategoryInfo&& r) noexcept;              // 0x1415e8aa0
    virtual ~CNMCategoryInfo() = default;                                 // 0x1415ec980
    CNMCategoryInfo& operator=(const CNMCategoryInfo& r);
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    int m_10;                                                   // +0x10
    NMKey64 m_14;                                               // +0x14
    char m_1c[0x20];                                            // +0x1c
    unsigned char m_3c;                                         // +0x3c
    unsigned char m_3d;                                         // +0x3d
};
MS2_CHECK_SIZE(CNMCategoryInfo, 0x40);

// Category with its friends, 0x58 bytes, vftable 0x142f3c0e8.
class CNMCateFriendInfo : public CNMCategoryInfo
{
public:
    CNMCateFriendInfo(const CNMCateFriendInfo& r);              // 0x1415e8a40
    CNMCateFriendInfo(CNMCateFriendInfo&& r) noexcept;          // 0x1415e89f0
    virtual ~CNMCateFriendInfo() = default;                               // 0x1415ec950
    CNMCateFriendInfo& operator=(const CNMCateFriendInfo& r);
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    std::vector<CNMFriendInfo> m_aFriends;                      // +0x40
};
MS2_CHECK_SIZE(CNMCateFriendInfo, 0x58);

class CNMChannelMemberInfo : public CNMSerializable
{
public:
    CNMChannelMemberInfo(const CNMChannelMemberInfo& r);
    virtual ~CNMChannelMemberInfo() = default;
    CNMChannelMemberInfo& operator=(const CNMChannelMemberInfo& r);

    unsigned char m_10[0x8];                          // +0x10 (not recovered)
    CNMStr<0x40> m_18;                                // +0x18
    CNMStr<0x400> m_20;                               // +0x20
    unsigned char m_28[0x8];                          // +0x28 (not recovered)
};
MS2_CHECK_SIZE(CNMChannelMemberInfo, 0x30);

// Chat-room member, 0x220 bytes, vftable 0x142f3c6d0.
class CNMChatRoomMemberInfo : public CNMRealUserInfo
{
public:
    CNMChatRoomMemberInfo(); // 0x141576ae0
    CNMChatRoomMemberInfo(const CNMChatRoomMemberInfo& r) noexcept; // 0x1415e8f40
    CNMChatRoomMemberInfo(CNMChatRoomMemberInfo&& r) noexcept;  // 0x1415e8e60
    virtual ~CNMChatRoomMemberInfo() = default;                           // 0x1415ecf90
    CNMChatRoomMemberInfo& operator=(const CNMChatRoomMemberInfo& r);
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    char m_1a8[0x20];                                           // +0x1a8
    NMKey64 m_1c8;                                              // +0x1c8
    unsigned int m_1d0;                                         // +0x1d0
    char m_1d4[0x40];                                           // +0x1d4
    unsigned int m_214;                                         // +0x214
    unsigned int m_218;                                         // +0x218
};
MS2_CHECK_SIZE(CNMChatRoomMemberInfo, 0x220);

// Guild member level, 0x58 bytes, vftable 0x142f3c760.
class CNMGuildMemberLevelInfo : public CNMSerializable
{
public:
    CNMGuildMemberLevelInfo(const CNMGuildMemberLevelInfo& r) noexcept; // 0x1415ea1f0
    CNMGuildMemberLevelInfo(CNMGuildMemberLevelInfo&& r) noexcept; // 0x1415ea180
    virtual ~CNMGuildMemberLevelInfo() = default;                         // 0x1415ee0f0
    CNMGuildMemberLevelInfo& operator=(const CNMGuildMemberLevelInfo& r);
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    unsigned char m_10;                                         // +0x10
    char m_11[0x40];                                            // +0x11
};
MS2_CHECK_SIZE(CNMGuildMemberLevelInfo, 0x58);

// Extended chat-room record, 0x4e0 bytes, vftable 0x142f3c7a8.
class CNMChatRoomInfoEx : public CNMSerializable
{
public:
    CNMChatRoomInfoEx(CNMChatRoomInfoEx&& r) noexcept;          // 0x1415e8ce0
    CNMChatRoomInfoEx();                                        // 0x1415776c0
    virtual ~CNMChatRoomInfoEx() = default;                               // 0x1415ecf60
    CNMChatRoomInfoEx& operator=(const CNMChatRoomInfoEx& r);
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    unsigned int m_10;                                          // +0x10
    unsigned __int64 m_18;                                      // +0x18
    unsigned int m_20;                                          // +0x20
    unsigned int m_24;                                          // +0x24
    char m_28[0x40];                                            // +0x28
    char m_68[0x400];                                           // +0x68 room title
    unsigned int m_468;                                         // +0x468
    unsigned int m_46c;                                         // +0x46c
    unsigned int m_470;                                         // +0x470
    char m_474[0x40];                                           // +0x474
    unsigned __int64 m_4b8;                                     // +0x4b8
    std::vector<CNMGuildMemberLevelInfo> m_4c0;                 // +0x4c0
    unsigned int m_4d8;                                         // +0x4d8
    unsigned int m_4dc;                                         // +0x4dc
};
MS2_CHECK_SIZE(CNMChatRoomInfoEx, 0x4e0);

// File transfer event, 0x128 bytes, vftable 0x142f3c328.
class CNMFileEvent : public CNMSerializable
{
public:
    CNMFileEvent(const CNMFileEvent& r) noexcept;               // 0x1415e92c0
    CNMFileEvent(CNMFileEvent&& r) noexcept;                    // 0x1415e9200
    virtual ~CNMFileEvent() = default;                                    // 0x1415ed4b0
    CNMFileEvent& operator=(const CNMFileEvent& r);
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    int m_10;                                                   // +0x10
    char m_14[0x100];                                           // +0x14
    int m_114;                                                  // +0x114
    int m_118;                                                  // +0x118
    int m_11c;                                                  // +0x11c
    int m_120;                                                  // +0x120
};
MS2_CHECK_SIZE(CNMFileEvent, 0x128);

// File path, 0x118 bytes, vftable 0x142f3c370.
class CNMFilePath : public CNMSerializable
{
public:
    CNMFilePath();                                            // 0x1415731e0
    CNMFilePath(const CNMFilePath& r) noexcept;                 // 0x1415e93e0
    CNMFilePath(CNMFilePath&& r) noexcept;                      // 0x1415e9380
    virtual ~CNMFilePath() = default;                                     // 0x1415ed4d0
    CNMFilePath& operator=(const CNMFilePath& r);
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    char m_10[0x104];                                           // +0x10
};
MS2_CHECK_SIZE(CNMFilePath, 0x118);

// User search result, 0xe0 bytes, vftable 0x142f3c4d8.
class CNMFindUserInfo : public CNMSerializable
{
public:
    CNMFindUserInfo();                                          // 0x141574480
    CNMFindUserInfo(const CNMFindUserInfo& r) noexcept;         // 0x1415e9570
    CNMFindUserInfo(CNMFindUserInfo&& r) noexcept;              // 0x1415e9440
    virtual ~CNMFindUserInfo() = default;                                 // 0x1415ed540
    CNMFindUserInfo& operator=(const CNMFindUserInfo& r);
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    __int64 m_10;                                                // +0x10
    char m_18[0x40];                                            // +0x18
    char m_58[0x20];                                            // +0x58
    char m_78[0x40];                                            // +0x78
    int m_b8;                                                   // +0xb8
    int m_bc;                                                   // +0xbc
    int m_c0;                                                   // +0xc0
    int m_c4;                                                   // +0xc4
    CNMAvatarItemInfo m_c8;                                     // +0xc8
    int m_d8;                                                   // +0xd8
};
MS2_CHECK_SIZE(CNMFindUserInfo, 0xe0);

class CNMGameCode : public CNMSerializable
{
public:
    CNMGameCode();
    explicit CNMGameCode(int nGameCode);
    CNMGameCode(const CNMGameCode& r) noexcept;                 // 0x1415e9910
    CNMGameCode(CNMGameCode&& r) noexcept;                      // 0x1415e98c0
    virtual ~CNMGameCode() = default;                                     // 0x1415ed9c0
    CNMGameCode& operator=(const CNMGameCode& r);
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    int m_nGameCode;                                            // +0x10
};
MS2_CHECK_SIZE(CNMGameCode, 0x18);

// Game record, 0x14a8 bytes, vftable 0x142f3c910.
class CNMGameInfo : public CNMSerializable
{
public:
    CNMGameInfo(const CNMGameInfo& r) noexcept;                 // 0x1415e9af0
    CNMGameInfo(CNMGameInfo&& r) noexcept;                      // 0x1415e9960
    virtual ~CNMGameInfo() = default;                                     // 0x1415ed9e0
    CNMGameInfo& operator=(const CNMGameInfo& r);
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    unsigned int m_10;                                          // +0x10
    unsigned int m_14;                                          // +0x14
    char m_18[0x20];                                            // +0x18
    char m_38[0x40];                                            // +0x38
    char m_78[0x20];                                            // +0x78
    char m_98[0x400];                                           // +0x98
    char m_498[0x400];                                          // +0x498
    char m_898[0x400];                                          // +0x898
    unsigned char m_c98;                                        // +0xc98
    unsigned int m_c9c;                                         // +0xc9c
    char m_ca0[0x400];                                          // +0xca0
    char m_10a0[0x400];                                         // +0x10a0
    unsigned int m_14a0;                                        // +0x14a0
};
MS2_CHECK_SIZE(CNMGameInfo, 0x14a8);

class CNMGameServerCode : public CNMSerializable
{
public:
    CNMGameServerCode(const CNMGameServerCode& r) noexcept;     // 0x1415e9cd0
    CNMGameServerCode(CNMGameServerCode&& r) noexcept;          // 0x1415e9c80
    virtual ~CNMGameServerCode() = default;                               // 0x1415edad0
    CNMGameServerCode& operator=(const CNMGameServerCode& r);
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    int m_nServerCode;                                          // +0x10
};
MS2_CHECK_SIZE(CNMGameServerCode, 0x18);

// Guild record, 0x190 bytes, vftable 0x142f3c400.
class CNMGuildInfoEx : public CNMSerializable
{
public:
    CNMGuildInfoEx();
    CNMGuildInfoEx(const CNMGuildInfoEx& r) noexcept;           // 0x1415e9e20
    CNMGuildInfoEx(CNMGuildInfoEx&& r) noexcept;                // 0x1415e9d20
    virtual ~CNMGuildInfoEx() = default;                                  // 0x1415ee070
    CNMGuildInfoEx& operator=(const CNMGuildInfoEx& r);
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    __int64 m_10;                                                // +0x10
    char m_18[0x40];                                            // +0x18
    char m_58[0x20];                                            // +0x58
    int m_78;                                                   // +0x78
    char m_7c[0x100];                                           // +0x7c
    int m_17c;                                                  // +0x17c
    int m_180;                                                  // +0x180
    int m_184;                                                  // +0x184
    int m_188;                                                  // +0x188
};
MS2_CHECK_SIZE(CNMGuildInfoEx, 0x190);

// Guild list, 0x28 bytes, vftable 0x142f3c448.
class CNMGuildListExInfo : public CNMSerializable
{
public:
    CNMGuildListExInfo();
    CNMGuildListExInfo(const CNMGuildListExInfo& r);            // 0x1415e9f20
    virtual ~CNMGuildListExInfo() = default;                              // 0x1415ee090
    CNMGuildListExInfo& operator=(const CNMGuildListExInfo& r);
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    std::vector<CNMGuildInfoEx> m_aGuilds;                      // +0x10
};
MS2_CHECK_SIZE(CNMGuildListExInfo, 0x28);

class CNMGuildMemberInfo : public CNMSerializable
{
public:
    CNMGuildMemberInfo(const CNMGuildMemberInfo& r) noexcept;   // 0x1415ea080
    CNMGuildMemberInfo(CNMGuildMemberInfo&& r) noexcept;        // 0x1415e9f80
    CNMGuildMemberInfo(const CNMChannelMemberInfo& r);          // 0x141574aa0
    virtual ~CNMGuildMemberInfo() = default;                              // 0x1415ee0c0
    CNMGuildMemberInfo& operator=(const CNMGuildMemberInfo& r);
    CNMGuildMemberInfo& operator=(CNMGuildMemberInfo&& r);      // 0x1415f1180
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    unsigned __int64 m_nIDCode;                                 // +0x10
    char m_szLoginID[0x40];                                     // +0x18
    char m_szNickName[0x40];                                    // +0x58
    CNMAvatarItemInfo m_avatar;                                 // +0x98
    int m_na8;
    unsigned char m_bac;
    int m_nb0;
    int m_nb4;
};
MS2_CHECK_SIZE(CNMGuildMemberInfo, 0xb8);

// Guild online state, 0x68 bytes, vftable 0x142f3c568.
class CNMGuildOnlineInfoEx : public CNMSerializable
{
public:
    CNMGuildOnlineInfoEx(const CNMGuildOnlineInfoEx& r);        // 0x1415ea330
    CNMGuildOnlineInfoEx(CNMGuildOnlineInfoEx&& r) noexcept;    // 0x1415ea260
    virtual ~CNMGuildOnlineInfoEx() = default;                            // 0x1415ee170
    CNMGuildOnlineInfoEx& operator=(const CNMGuildOnlineInfoEx& r);
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    unsigned __int64 m_10;                                      // +0x10
    unsigned int m_18;                                          // +0x18
    unsigned int m_1c;                                          // +0x1c
    char m_20[0x20];                                            // +0x20
    unsigned short m_40;                                        // +0x40
    std::vector<CNMGuildMemberInfo> m_aMembers;                 // +0x48
    unsigned int m_60;                                          // +0x60
};
MS2_CHECK_SIZE(CNMGuildOnlineInfoEx, 0x68);

// Note (memo), 0xec8 bytes, vftable 0x142f3c1c0.
class CNMNoteInfo : public CNMSerializable
{
public:
    CNMNoteInfo();
    CNMNoteInfo(const CNMNoteInfo2& r);
    CNMNoteInfo(const CNMNoteInfo& r) noexcept;                 // 0x1415ea820
    CNMNoteInfo(CNMNoteInfo&& r) noexcept;                      // 0x1415ea690
    virtual ~CNMNoteInfo() = default;                                     // 0x1415ee5d0
    CNMNoteInfo& operator=(const CNMNoteInfo& r);
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    int m_10;                                                   // +0x10
    int m_14;                                                   // +0x14
    int m_18;                                                   // +0x18
    NMKey64 m_1c;                                               // +0x1c
    union                                                       // +0x24 (the implicit copy copies both members)
    {
        int m_24;
        int m_24b;
    };
    SYSTEMTIME m_28;                                            // +0x28
    char m_38[0x400];                                           // +0x38
    char m_438[0x40];                                           // +0x438
    char m_478[0x40];                                           // +0x478
    char m_4b8[0x800];                                          // +0x4b8
    char m_cb8[0x100];                                          // +0xcb8
    char m_db8[0x100];                                          // +0xdb8
    CNMAvatarFullInfo m_eb8;                                    // +0xeb8
};
MS2_CHECK_SIZE(CNMNoteInfo, 0xec8);

// Note box entry, 0xae8 bytes, vftable 0x142f3c250.
class CNMNoteInfo2 : public CNMSerializable
{
public:
    CNMNoteInfo2();
    CNMNoteInfo2(const CNMNoteInfo& r);
    CNMNoteInfo2(const CNMNoteInfo2& r);                        // 0x1415ea540
    CNMNoteInfo2(CNMNoteInfo2&& r) noexcept;                    // 0x1415ea400
    virtual ~CNMNoteInfo2() = default;                                    // 0x1415ee590
    CNMNoteInfo2& operator=(const CNMNoteInfo2& r);
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    unsigned int m_10;                                          // +0x10
    unsigned int m_14;                                          // +0x14
    unsigned int m_18;                                          // +0x18
    SYSTEMTIME m_1c;                                            // +0x1c
    unsigned int m_2c;                                          // +0x2c
    unsigned int m_30;                                          // +0x30
    char m_34[0x800];                                           // +0x34
    char m_834[0x100];                                          // +0x834
    char m_934[0x100];                                          // +0x934
    CNMCharacter m_a38;                                         // +0xa38
    std::vector<CNMCharacter> m_aCharacters;                    // +0xad0
};
MS2_CHECK_SIZE(CNMNoteInfo2, 0xae8);

class CNMRejectedUser : public CNMSerializable
{
public:
    CNMRejectedUser(const CNMRejectedUser& r);
    virtual ~CNMRejectedUser() = default;
    CNMRejectedUser& operator=(const CNMRejectedUser& r);

    CNMCharacter m_character;                         // +0x10
    unsigned char m_a8[0x20];                         // +0xa8 (not recovered)
};
MS2_CHECK_SIZE(CNMRejectedUser, 0xc8);

class CNMSessionMemberInfo : public CNMSerializable
{
public:
    CNMSessionMemberInfo(const CNMSessionMemberInfo& r);
    virtual ~CNMSessionMemberInfo() = default;
    CNMSessionMemberInfo& operator=(const CNMSessionMemberInfo& r);

    unsigned char m_10[0xd8];                         // +0x10 (not recovered)
    CNMAvatarFullInfo m_avatar;                       // +0xe8
};
MS2_CHECK_SIZE(CNMSessionMemberInfo, 0xf8);

class CNMVirtualUserInfo : public CNMSerializable
{
public:
    CNMVirtualUserInfo();
    CNMVirtualUserInfo(const CNMVirtualUserInfo& r);
    virtual ~CNMVirtualUserInfo() = default;
    CNMVirtualUserInfo& operator=(const CNMVirtualUserInfo& r);
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    int m_10, m_14;
    char m_18[0x40];
    char m_58[0x40];
    char m_98[0x3e8];
    unsigned int m_480, m_484, m_488, m_48c;
};
MS2_CHECK_SIZE(CNMVirtualUserInfo, 0x490);

class CNMExecutePatcherFunc : public CNMFunc
{
public:
    CNMExecutePatcherFunc(const char* szUrl, const char* szPatchDir, const char* szExecPath, int n4, int n5, int n6);
    virtual ~CNMExecutePatcherFunc() = default;                           // 0x1415ed360

    char m_szUrl[0x100];                                        // +0x30
    char m_szPatchDir[0x100];                                   // +0x130
    char m_szExecPath[0x7d0];                                   // +0x230
    int m_na00;
    int m_na04;
    int m_na08;
    int m_na0c;
};
MS2_CHECK_SIZE(CNMExecutePatcherFunc, 0xa10);

class CNMExecuteLauncherFunc : public CNMFunc
{
public:
    CNMExecuteLauncherFunc(int nGameCode, int n2, const char* szArgument, int n4, int n5);
    virtual ~CNMExecuteLauncherFunc() = default;

    int m_nGameCode;                                            // +0x30
    int m_n34;
    char m_szArgument[0x7d0];                                   // +0x38
    int m_n808;
    int m_n80c;
};
MS2_CHECK_SIZE(CNMExecuteLauncherFunc, 0x810);

class CNMExecuteNGMPatcherFunc : public CNMFunc
{
public:
    CNMExecuteNGMPatcherFunc(int nGameCode, const char* sz2, const char* sz3, const char* sz4, int n5, int n6, int n7,
                             const char* sz8, int n9, const char* sz10, int n11);
    virtual ~CNMExecuteNGMPatcherFunc() = default;

    char m_body[0x85c0];                                        // +0x30 (not recovered)
};
MS2_CHECK_SIZE(CNMExecuteNGMPatcherFunc, 0x85f0);

class CNMExecuteNGMPatcher2Func : public CNMFunc
{
public:
    CNMExecuteNGMPatcher2Func(const char* szArgument, int n2);
    virtual ~CNMExecuteNGMPatcher2Func() = default;

    char m_body[0x8008];                                        // +0x30 (not recovered)
};
MS2_CHECK_SIZE(CNMExecuteNGMPatcher2Func, 0x8038);

class CNMExecuteNGMLauncherFunc : public CNMFunc
{
public:
    CNMExecuteNGMLauncherFunc(int nGameCode, int n2, const char* sz3, int n4, const char* sz5, int n6, const char* sz7,
                              const char* sz8, int n9);
    virtual ~CNMExecuteNGMLauncherFunc() = default;

    int m_nGameCode;                                            // +0x30
    int m_n34;
    char m_sz38[0x400];
    int m_n438;
    char m_sz43c[0x400];
    int m_n83c;
    char m_sz840[0x8];
    char m_sz848[0x80];
    int m_n8c8;
    int m_n8cc;
};
MS2_CHECK_SIZE(CNMExecuteNGMLauncherFunc, 0x8d0);

class CNMExecuteNGMInstallerFunc : public CNMFunc
{
public:
    CNMExecuteNGMInstallerFunc(int nGameCode, int n2, int n3, const char* sz4, const char* sz5, const char* sz6,
                               const char* sz7, int n8);
    virtual ~CNMExecuteNGMInstallerFunc() = default;

    int m_nGameCode;                                            // +0x30
    int m_n34;
    int m_n38;
    char m_sz3c[0x400];
    char m_sz43c[0x400];
    char m_sz83c[0x20];
    char m_sz85c[0x80];
    int m_n8dc;
};
MS2_CHECK_SIZE(CNMExecuteNGMInstallerFunc, 0x8e0);

class CNMIsNGMInstalledFunc : public CNMFunc
{
public:
    CNMIsNGMInstalledFunc();
    virtual ~CNMIsNGMInstalledFunc() = default;                           // 0x1415ee210

    int m_bInstalled;                                           // +0x30 (reply)
    int m_n34;
};
MS2_CHECK_SIZE(CNMIsNGMInstalledFunc, 0x38);

// One request, four URL kinds (m_nUrlType 1..4), each filling its own input members.
class CNMGetUrlExFunc : public CNMFunc
{
public:
    CNMGetUrlExFunc();
    virtual ~CNMGetUrlExFunc() = default;                                 // 0x1415edfc0

    int m_nUrlType;                                             // +0x30
    int m_nGameCode;                                            // +0x34 (type 1)
    int m_n38;                                                  // +0x38 (type 2)
    int m_n3c;
    unsigned __int64 m_n40;                                     // +0x40 (type 3)
    char m_sz48[0x200];                                         // +0x48 (type 4)
    int m_n248;                                                 // +0x248 (type 1)
    char m_sz24c[0x100];                                        // +0x24c (type 1)
    int m_n34c;
    int m_n350;
    int m_n354;
    int m_n358;
    char m_szUrl[0x404];                                        // +0x35c (reply)
};
MS2_CHECK_SIZE(CNMGetUrlExFunc, 0x760);
MS2_CHECK_OFFSET(CNMGetUrlExFunc, m_szUrl, 0x35c);

class CNMGetSessionValueFunc : public CNMFunc
{
public:
    CNMGetSessionValueFunc();
    CNMGetSessionValueFunc(const char* szName);
    virtual ~CNMGetSessionValueFunc() = default;                          // 0x1415edf70
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    char m_szName[0x20];                                        // +0x30
    char m_szValue[0x100];                                      // +0x50 (reply)
};
MS2_CHECK_SIZE(CNMGetSessionValueFunc, 0x150);

class CNMSetSessionValueFunc : public CNMFunc
{
public:
    CNMSetSessionValueFunc(const char* szName, const char* szValue, int n3);
    virtual ~CNMSetSessionValueFunc() = default;

    char m_szName[0x20];                                        // +0x30
    char m_szValue[0x100];                                      // +0x50
    int m_n150;
    int m_n154;
};
MS2_CHECK_SIZE(CNMSetSessionValueFunc, 0x158);

class CNMBringForwardStandAloneMsgFunc : public CNMFunc
{
public:
    CNMBringForwardStandAloneMsgFunc(const char* szName);
    virtual ~CNMBringForwardStandAloneMsgFunc() = default;

    char m_szName[0x400];                                       // +0x30
};
MS2_CHECK_SIZE(CNMBringForwardStandAloneMsgFunc, 0x430);

class CNMDownloadFileFunc : public CNMFunc
{
public:
    CNMDownloadFileFunc(const char* szUrl, const char* szPath);
    virtual ~CNMDownloadFileFunc() = default;

    char m_szUrl[0x100];                                        // +0x30
    char m_szPath[0x100];                                       // +0x130
};
MS2_CHECK_SIZE(CNMDownloadFileFunc, 0x230);

class CNMUploadFileFunc : public CNMFunc
{
public:
    CNMUploadFileFunc(const char* szUrl, const char* sz2, const char* sz3, int n4);
    virtual ~CNMUploadFileFunc() = default;

    char m_szUrl[0x400];                                        // +0x30
    char m_sz430[0x100];
    char m_sz530[0x100];
    int m_n630;
    char m_szResult[0x404];                                     // +0x634 (reply)
};
MS2_CHECK_SIZE(CNMUploadFileFunc, 0xa38);

class CNMGetSupportGameListFunc : public CNMFunc
{
public:
    CNMGetSupportGameListFunc(int n);
    virtual ~CNMGetSupportGameListFunc() = default;                       // 0x1415edf90

    int m_n30;
    int m_n34;
    std::vector<CNMGameCode> m_aGameCode;                       // +0x38 (reply)
};
MS2_CHECK_SIZE(CNMGetSupportGameListFunc, 0x50);

class CNMGetGameServerListFunc : public CNMFunc
{
public:
    CNMGetGameServerListFunc(int nGameCode);
    virtual ~CNMGetGameServerListFunc() = default;

    int m_nGameCode;                                            // +0x30
    int m_n34;
    std::vector<CNMGameServerCode> m_aServerCode;               // +0x38 (reply)
};
MS2_CHECK_SIZE(CNMGetGameServerListFunc, 0x50);

class CNMGetGameFullNameFunc : public CNMFunc
{
public:
    CNMGetGameFullNameFunc(int nGameCode);
    virtual ~CNMGetGameFullNameFunc() = default;

    int m_nGameCode;                                            // +0x30
    char m_szName[0x84];                                        // +0x34 (reply)
};
MS2_CHECK_SIZE(CNMGetGameFullNameFunc, 0xb8);

class CNMGetGameShortNameFunc : public CNMFunc
{
public:
    CNMGetGameShortNameFunc(int nGameCode);
    virtual ~CNMGetGameShortNameFunc() = default;

    int m_nGameCode;                                            // +0x30
    char m_szName[0x84];                                        // +0x34 (reply)
};
MS2_CHECK_SIZE(CNMGetGameShortNameFunc, 0xb8);

class CNMGetGameFriendTitleFunc : public CNMFunc
{
public:
    CNMGetGameFriendTitleFunc(int nGameCode);
    virtual ~CNMGetGameFriendTitleFunc() = default;

    int m_nGameCode;                                            // +0x30
    char m_szTitle[0x84];                                       // +0x34 (reply)
};
MS2_CHECK_SIZE(CNMGetGameFriendTitleFunc, 0xb8);

class CNMGetGameServerNameFunc : public CNMFunc
{
public:
    CNMGetGameServerNameFunc(int nGameCode, int nServerCode);
    virtual ~CNMGetGameServerNameFunc() = default;

    int m_nGameCode;                                            // +0x30
    int m_nServerCode;                                          // +0x34
    char m_szName[0x80];                                        // +0x38 (reply)
};
MS2_CHECK_SIZE(CNMGetGameServerNameFunc, 0xb8);

class CNMDownloadGuildMarkFileFunc : public CNMFunc
{
public:
    CNMDownloadGuildMarkFileFunc(int nGameCode, unsigned __int64 nGuildKey, const char* szPath);
    virtual ~CNMDownloadGuildMarkFileFunc() = default;

    int m_nGameCode;                                            // +0x30
    int m_n34;
    unsigned __int64 m_nGuildKey;                               // +0x38
    char m_szPath[0x100];                                       // +0x40
};
MS2_CHECK_SIZE(CNMDownloadGuildMarkFileFunc, 0x140);


// Server list request (0x48). Only the nested records the list code needs are declared.
class CNMSetServerInfoFunc : public CNMFunc
{
public:
    class ServerAddress
    {
    public:
        ServerAddress();
        ServerAddress(const ServerAddress& r);
        CNMStr<0x20> m_host;                                    // +0x00
        unsigned short m_port;                                  // +0x08
    };

    class RequestInfo
    {
    public:
        RequestInfo();
        RequestInfo(const RequestInfo& r);
        unsigned int m_kind;                                    // +0x00
        unsigned int m_flags;                                   // +0x04
        ServerAddress m_address;                                // +0x08
        CNMStr<0x800> m_info;                                   // +0x18
    };

    CNMSetServerInfoFunc();                                     // 0x141590b00
    virtual ~CNMSetServerInfoFunc() = default;

    std::vector<RequestInfo> m_requests;                        // +0x30
};
MS2_CHECK_SIZE(CNMSetServerInfoFunc::ServerAddress, 0x10);
MS2_CHECK_SIZE(CNMSetServerInfoFunc::RequestInfo, 0x20);
MS2_CHECK_SIZE(CNMSetServerInfoFunc, 0x48);

// Scoped critical-section lock (name invented): enters on construction, leaves on destruction.
class CNMCSLock
{
public:
    CNMCSLock(CRITICAL_SECTION* pcs);                           // 0x1415e89b0
    ~CNMCSLock() { LeaveCriticalSection(m_pcs); }

    CRITICAL_SECTION* m_pcs;                                    // +0x00
};
