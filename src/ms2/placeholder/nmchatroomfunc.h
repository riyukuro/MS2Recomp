// nmchatroomfunc.h - shared placeholder for the Nexon Messenger (nm) SDK chat-room types embedded in MapleStory2.exe
// KMS2_DEV x64 (2022-04-13): the chat-room record types and the CNMCR* chat-room function objects (func codes
// 0xb001..0xb00b). NOT an original header (name assumed). Bases (CNMSerializable, CNMFunc, CNMManager) and the
// list element records (CNMChatRoomMemberInfo, CNMGuildMemberLevelInfo) are in nmfunc.h. Include after ms2stdafx.h (HWND).
//
// Sizes are proven from the exe: each class's scalar deleting destructor (vftable slot 0, work/map/vtables.tsv) passes
// its size to operator delete. Function-object layouts follow their constructors (0x14159c9b0 .. 0x14159ee30); the
// record payloads follow the third-party v2525 snapshot (work/ext/v2525, same VAs). Ctors/dtors/assignments live in
// the library's other units and are only declared (bound through progress/symbols-manual.tsv). Virtual slots beyond
// the destructor are not declared.
#pragma once
#include <vector>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/nmfunc.h"

// CNMChatRoomInfoEx (0x4e0, vftable 0x142f3c7a8) is in nmfunc.h with the other records (w500: moved there for
// unit_1415e5c20, which defines its move constructor; same layout).

// CNMChatMessage: chat message record, 0x670 bytes, vftable 0x142f3c2e0 (payload mostly not recovered).
class CNMChatMessage : public CNMSerializable
{
public:
    char m_10[0x8];                                             // +0x10
    CNMAvatarItemInfo m_avatar;                                 // +0x18
    char m_28[0x648];                                           // +0x28
};
MS2_CHECK_SIZE(CNMChatMessage, 0x670);

// 0xb001, 0x40 bytes, vftable 0x142f3fac8.
class CNMCRRegisterCallbackFunc : public CNMFunc
{
public:
    CNMCRRegisterCallbackFunc(); // 0x14159c950
    CNMCRRegisterCallbackFunc(unsigned uSerialKey, HWND hWnd, unsigned uMsg); // 0x14159c9b0
    virtual ~CNMCRRegisterCallbackFunc() = default;                       // 0x1415ec860

    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    HWND m_hWnd;                                                // +0x30
    unsigned m_uMsg;                                            // +0x38
    unsigned m_3c;                                              // +0x3c
};
MS2_CHECK_SIZE(CNMCRRegisterCallbackFunc, 0x40);

// 0xb002, 0x30 bytes, vftable 0x142f3fb38.
class CNMCRCloseFunc : public CNMFunc
{
public:
    CNMCRCloseFunc(); // 0x14159ccd0
    explicit CNMCRCloseFunc(unsigned uSerialKey);               // 0x14159cd20
    virtual ~CNMCRCloseFunc() = default;                                  // 0x1415ec760

    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
};
MS2_CHECK_SIZE(CNMCRCloseFunc, 0x30);

// 0xb004, 0x488 bytes, vftable 0x142f3fc68. Each non-null argument is copied and sets its bit in m_uFlags (title 1,
// the three uints 2/4/8, the 64-bit value 0x10, the 0x40-char string 0x20).
class CNMCRChangeRoomInfoFunc : public CNMFunc
{
public:
    CNMCRChangeRoomInfoFunc(unsigned uSerialKey, const char* szTitle, const unsigned* pU434, const unsigned* pU438,
        const unsigned* pU43c, const char* sz448, const unsigned __int64* pU440);   // 0x14159d790
    virtual ~CNMCRChangeRoomInfoFunc() = default;                         // 0x1415ec520

    unsigned m_uFlags;                                          // +0x30
    char m_szTitle[0x400];                                      // +0x34
    unsigned m_434;                                             // +0x434
    unsigned m_438;                                             // +0x438
    unsigned m_43c;                                             // +0x43c
    unsigned __int64 m_440;                                     // +0x440
    char m_448[0x40];                                           // +0x448
};
MS2_CHECK_SIZE(CNMCRChangeRoomInfoFunc, 0x488);

// 0xb006, 0x48 bytes, vftable 0x142f3fd38.
class CNMCRGetMemberListFunc : public CNMFunc
{
public:
    explicit CNMCRGetMemberListFunc(unsigned uSerialKey);       // 0x14159e210
    virtual ~CNMCRGetMemberListFunc() = default;                          // 0x1415ec7b0

    std::vector<CNMChatRoomMemberInfo> m_aMembers;              // +0x30 (reply)
};
MS2_CHECK_SIZE(CNMCRGetMemberListFunc, 0x48);

// 0xb007, 0x830 bytes, vftable 0x142f3fda0.
class CNMCRInviteUserFunc : public CNMFunc
{
public:
    CNMCRInviteUserFunc(unsigned uSerialKey, const char* szUser, const char* szMessage); // 0x14159e6a0
    virtual ~CNMCRInviteUserFunc() = default;                             // 0x1415ec840

    char m_szUser[0x400];                                       // +0x30
    char m_szMessage[0x400];                                    // +0x430
};
MS2_CHECK_SIZE(CNMCRInviteUserFunc, 0x830);

// 0xb008, 0x38 bytes, vftable 0x142f3fe08.
class CNMCRBanUserFunc : public CNMFunc
{
public:
    CNMCRBanUserFunc(unsigned uSerialKey, unsigned __int64 uUserKey); // 0x14159eac0
    virtual ~CNMCRBanUserFunc() = default;                                // 0x1415ec4d0

    unsigned __int64 m_uUserKey;                                // +0x30
};
MS2_CHECK_SIZE(CNMCRBanUserFunc, 0x38);

// 0xb009, 0x6f0 bytes, vftable 0x142f3fe70. The ctor copies 0x50 bytes of recipient keys (zeroes them when null)
// and assigns the message.
class CNMCRSendChatMessageFunc : public CNMFunc
{
public:
    CNMCRSendChatMessageFunc(unsigned uSerialKey, const unsigned __int64* pKeys, const CNMChatMessage& msg); // 0x14159ee30
    virtual ~CNMCRSendChatMessageFunc() = default;                        // 0x1415ec880

    unsigned __int64 m_aKeys[10];                               // +0x30
    CNMChatMessage m_msg;                                       // +0x80
};
MS2_CHECK_SIZE(CNMCRSendChatMessageFunc, 0x6f0);

// 0xb00a, 0x258 bytes, vftable 0x142f3fee0.
class CNMCRGetMemberInfoFunc : public CNMFunc
{
public:
    CNMCRGetMemberInfoFunc(unsigned uSerialKey, unsigned uWhich); // 0x14159f290
    virtual ~CNMCRGetMemberInfoFunc() = default;                          // 0x1415ec780

    unsigned m_uWhich;                                          // +0x30
    unsigned m_34;                                              // +0x34
    CNMChatRoomMemberInfo m_info;                               // +0x38 (reply)
};
MS2_CHECK_SIZE(CNMCRGetMemberInfoFunc, 0x258);

// 0xb00b, 0x510 bytes, vftable 0x142f3fc00.
class CNMCRGetRoomInfoExFunc : public CNMFunc
{
public:
    explicit CNMCRGetRoomInfoExFunc(unsigned uSerialKey);       // 0x14159d3b0
    virtual ~CNMCRGetRoomInfoExFunc() = default;                          // 0x1415ec7e0

    CNMChatRoomInfoEx m_info;                                   // +0x30 (reply)
};
MS2_CHECK_SIZE(CNMCRGetRoomInfoExFunc, 0x510);
