// nmobjects.h - Nexon Messenger (NM) client library records, events and requests whose only code in the exe is their
// destructor (unit_1415eb6c0). NOT an original Nexon header. Class names are RTTI names; layouts and member names are
// from the third-party v2525 snapshot, with the members its m_body placeholders hid recovered from the destructors
// (the non-trivial member offsets). Every destructor is the implicit one (no vptr store), so they are defaulted
// in-class.
#pragma once

#include <map>
#include <vector>
#include "ms2/placeholder/nmfunc.h"
#include "ms2/placeholder/nmchatroomfunc.h"

// vftable 0x142f416a0, destructor 0x1415ed280.
class CNMEvent : public CNMSerializable
{
public:
    CNMEvent(int nEventId, unsigned char bFormat, int n1c, int n24);
    virtual ~CNMEvent() = default;
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    virtual char* vfunc_8() { return const_cast<char*>("CNMEvent"); }
    virtual unsigned int vfunc_9() { return 0; }
    virtual unsigned int vfunc_10() { return 0; }
    virtual void vfunc_11(unsigned int);

    int m_nEventId;    // +0x10
    int m_n14;         // +0x14
    int m_n18;         // +0x18
    int m_n1c;         // +0x1c
    int m_n20;         // +0x20
    int m_n24;         // +0x24
};
MS2_CHECK_SIZE(CNMEvent, 0x28);

// vftable 0x142f3cbe0, destructor 0x1415ecd30.
class CNMChannelMessage : public CNMSerializable
{
public:
    CNMChannelMessage();
    CNMChannelMessage(const CNMChannelMessage& r);
    CNMChannelMessage(const void* record, int messageType);
    CNMChannelMessage& operator=(const CNMChannelMessage& r);
    virtual ~CNMChannelMessage() = default;
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    unsigned char m_10[0x10];                         // +0x10 (not recovered)
    CNMStr<0x40> m_20;                                // +0x20
    unsigned char m_28[0x8];                          // +0x28 (not recovered)
    CNMStr<0x1000> m_30;                              // +0x30
    CNMStr<0x400> m_38;                               // +0x38
    unsigned char m_40[0x8];                          // +0x40 (not recovered)
};
MS2_CHECK_SIZE(CNMChannelMessage, 0x48);

// vftable 0x142f3c718, destructor 0x1415ecfb0.
class CNMChatRoomMemberList : public CNMSerializable
{
public:
    CNMChatRoomMemberList();
    virtual ~CNMChatRoomMemberList() = default;

    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    std::vector<CNMChatRoomMemberInfo> m_members;
};
MS2_CHECK_SIZE(CNMChatRoomMemberList, 0x28);

// vftable 0x142f3f850, destructor 0x1415ed090.
class CNMCreateChatRoomExFunc : public CNMFunc
{
public:
    CNMCreateChatRoomExFunc(); // 0x14159a480
    CNMCreateChatRoomExFunc(int n10, unsigned __int64 n18, const char* sz20, const char* sz60, int n498, int n49c,
                            int n4a0, const char* sz4a4, const char* sz730, unsigned short n750, int n754);
    virtual ~CNMCreateChatRoomExFunc() = default;

    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    CNMChatRoomInfoEx m_room;                         // +0x30
    CNMChatRoomMemberInfo m_self;                     // +0x510
    char m_730[0x20];                                 // +0x730
    unsigned short m_750;
    unsigned char m_752[2];
    int m_754;
};
MS2_CHECK_SIZE(CNMCreateChatRoomExFunc, 0x758);

// vftable 0x142f3c7f0, destructor 0x1415ecf40.
class CNMChatRoomInfo : public CNMSerializable
{
public:
    CNMChatRoomInfo(); // 0x141577ef0
    virtual ~CNMChatRoomInfo() = default;
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    int m_10; // +0x10
    int m_14; // +0x14
    int m_18; // +0x18
    int m_1c; // +0x1c
    char m_20[0x40]; // +0x20
    char m_60[0x400]; // +0x60
    int m_460; // +0x460
    int m_464; // +0x464
    int m_468; // +0x468
    char m_46c[0x40]; // +0x46c
    int m_4ac; // +0x4ac
    long long m_4b0; // +0x4b0
    char m_4b8[0x40]; // +0x4b8
    char m_4f8[0x40]; // +0x4f8
    char m_538[0x40]; // +0x538
    char m_578[0x40]; // +0x578
    char m_5b8[0x40]; // +0x5b8
    int m_5f8; // +0x5f8
    int m_5fc; // +0x5fc
};
MS2_CHECK_SIZE(CNMChatRoomInfo, 0x600);

// vftable 0x142f3f7e8, destructor 0x1415ed0d0.
class CNMCreateChatRoomFunc : public CNMFunc
{
public:
    CNMCreateChatRoomFunc(); // 0x141599e80
    CNMCreateChatRoomFunc(int n10, int n14, const char* sz20, const char* sz60, int n460, int n464,
                          int n468, const char* sz46c, const char* sz850, unsigned short n870); // 0x141599f20
    virtual ~CNMCreateChatRoomFunc() = default;

    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override; // 0x14159a1c0
    unsigned int EncodeFramed(CNMStream* pStream) override;                 // 0x14159a100
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override; // 0x14159a160
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override; // 0x14159a390
    unsigned int DecodeFramed(CNMStream* pStream) override;                 // 0x14159a2a0
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override; // 0x14159a330

    CNMChatRoomInfo m_room;                           // +0x30
    CNMChatRoomMemberInfo m_self;                     // +0x630
    char m_850[0x20];                                 // +0x850
    unsigned short m_870;                             // +0x870
    unsigned char m_872[0x6];                         // tail padding
};
MS2_CHECK_SIZE(CNMCreateChatRoomFunc, 0x878);

// vftable 0x142f3c9a0, destructor 0x1415ed140.
class CNMCustomNotifyData : public CNMSerializable
{
public:
    CNMCustomNotifyData();
    virtual ~CNMCustomNotifyData() = default;

    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    int m_10; // +0x10
    int m_14; // +0x14
    long long m_18; // +0x18
    int m_20; // +0x20
    int m_24; // +0x24
    long long m_28; // +0x28
    int m_30; // +0x30
    int m_34; // +0x34
    char m_38[0x40]; // +0x38
    char m_78[0x40]; // +0x78
    char m_b8[0x100]; // +0xb8
    unsigned short m_1b8; // +0x1b8
    unsigned short m_1ba; // +0x1ba
    unsigned char m_1bc[0x2]; // +0x1bc
    unsigned short m_1be; // +0x1be
    unsigned char m_1c0[0x8]; // +0x1c0
    int m_1c8; // +0x1c8
};
MS2_CHECK_SIZE(CNMCustomNotifyData, 0x1d0);

// vftable 0x142f40668, destructor 0x1415ed190.
class CNMCustomNotifyFunc : public CNMFunc
{
public:
    CNMCustomNotifyFunc();
    CNMCustomNotifyFunc(int type, const char* message, int flags);
    explicit CNMCustomNotifyFunc(const CNMCustomNotifyData& data);
    virtual ~CNMCustomNotifyFunc() = default;

    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    CNMCustomNotifyData m_data;                       // +0x30
};
MS2_CHECK_SIZE(CNMCustomNotifyFunc, 0x200);

// vftable 0x142f3c958, destructor 0x1415eda00.
class CNMGameListData : public CNMSerializable
{
public:
    CNMGameListData();                                                // 0x141579eb0
    virtual ~CNMGameListData() = default;
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    std::vector<CNMGameInfo> m_games;
};
MS2_CHECK_SIZE(CNMGameListData, 0x28);

// vftable 0x142f3e358, destructor 0x1415ede10.
class CNMGetNoteBox2Func : public CNMFunc
{
public:
    CNMGetNoteBox2Func(); // 0x14158ba00
    CNMGetNoteBox2Func(int type, int index, int status); // 0x14158ba80
    virtual ~CNMGetNoteBox2Func() = default;
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    int m_30, m_34, m_38;
    std::vector<CNMNoteInfo2> m_40;
    unsigned m_58; // inferred: reply flag stored from ReadU8 at +0x58; no ctor store.
};
MS2_CHECK_SIZE(CNMGetNoteBox2Func, 0x60);

// vftable 0x142f3e148, destructor 0x1415ede40.
class CNMGetNoteBoxFunc : public CNMFunc
{
public:
    CNMGetNoteBoxFunc(); // 0x14158a1e0
    CNMGetNoteBoxFunc(int type, int index); // 0x14158a260
    CNMGetNoteBoxFunc(int type, int index, int status); // 0x14158a2f0
    virtual ~CNMGetNoteBoxFunc() = default;
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    int m_30, m_34, m_38;
    std::vector<CNMNoteInfo> m_40;
    unsigned m_58;
};
MS2_CHECK_SIZE(CNMGetNoteBoxFunc, 0x60);

// vftable 0x142f3da90, destructor 0x1415edf40.
class CNMGetServerInfoFunc : public CNMFunc
{
public:
    CNMGetServerInfoFunc(); // 0x1415859f0
    CNMGetServerInfoFunc(int server, int channel); // 0x141585a50
    virtual ~CNMGetServerInfoFunc() = default;
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    int m_30, m_34;
    std::vector<CNMSetServerInfoFunc::RequestInfo> m_requests; // +0x38
};
MS2_CHECK_SIZE(CNMGetServerInfoFunc, 0x50);

// vftable 0x142f3d268, destructor 0x1415ee000.
class CNMGetUserDataListFunc : public CNMFunc
{
public:
    CNMGetUserDataListFunc(); // 0x141580d00
    virtual ~CNMGetUserDataListFunc() = default;

    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    int m_30; // +0x30
    int m_34; // +0x34
    int m_38; // +0x38
    unsigned char m_3c[0x80000]; // +0x3c
};
MS2_CHECK_SIZE(CNMGetUserDataListFunc, 0x80040);

// vftable 0x142f3c5b0, destructor 0x1415ee110.
class CNMGuildOnlineInfo : public CNMSerializable
{
public:
    CNMGuildOnlineInfo();
    virtual ~CNMGuildOnlineInfo() = default;

    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    unsigned m_10, m_14, m_18;
    char m_1c[0x20];
    unsigned short m_3c;
    std::vector<CNMGuildMemberInfo> m_40;
};
MS2_CHECK_SIZE(CNMGuildOnlineInfo, 0x58);

// vftable 0x142f41c18, destructor 0x1415ee1f0.
class CNMInviteVirtualUserEvent : public CNMEvent
{
public:
    CNMInviteVirtualUserEvent();
    CNMInviteVirtualUserEvent(long long n28, int n30, int n34, long long n38, long long n40,
                              const char* text48, const char* text88);
    virtual ~CNMInviteVirtualUserEvent() = default;
    unsigned int vfunc_10() override { return static_cast<unsigned int>(m_1c8); }
    char* vfunc_8() override { return const_cast<char*>("CNMInviteVirtualUserEvent"); }
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    void vfunc_11(unsigned int) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    long long m_28; // +0x28
    int m_30; // +0x30
    int m_34; // +0x34
    int m_38; // +0x38
    int m_3c; // +0x3c
    int m_40; // +0x40
    int m_44; // +0x44
    char m_48[0x40]; // +0x48
    char m_88[0x40]; // +0x88
    char m_c8[0x100]; // +0xc8
    int m_1c8; // +0x1c8
};
MS2_CHECK_SIZE(CNMInviteVirtualUserEvent, 0x1d0);

// vftable 0x142f3f920, destructor 0x1415ee290.
class CNMJoinToChatRoomExFunc : public CNMFunc
{
public:
    CNMJoinToChatRoomExFunc(); // 0x14159b0f0
    CNMJoinToChatRoomExFunc(unsigned __int64 n48, unsigned int n50, const char* sz4a4, const char* sz730,
                            unsigned short n750, unsigned int n4a0, unsigned int n754);
    virtual ~CNMJoinToChatRoomExFunc() = default;

    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    CNMChatRoomInfoEx m_room;                         // +0x30
    CNMChatRoomMemberInfo m_self;                     // +0x510
    char m_730[0x20];                                 // +0x730
    unsigned short m_750;
    unsigned char m_752[2];
    unsigned int m_754;
    unsigned int m_758;
    unsigned int m_75c;
};
MS2_CHECK_SIZE(CNMJoinToChatRoomExFunc, 0x760);

// vftable 0x142f3f8b8, destructor 0x1415ee2d0.
class CNMJoinToChatRoomFunc : public CNMFunc
{
public:
    CNMJoinToChatRoomFunc(); // 0x14159aae0
    CNMJoinToChatRoomFunc(unsigned int n44, unsigned int n48, const char* sz49c, const char* sz850,
                          unsigned short n870);
    virtual ~CNMJoinToChatRoomFunc() = default;

    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    CNMChatRoomInfo m_room;                           // +0x30
    CNMChatRoomMemberInfo m_self;                     // +0x630
    char m_850[0x20];                                 // +0x850
    unsigned short m_870;
    unsigned char m_872[2];
    unsigned int m_874;
    unsigned int m_878;
};
MS2_CHECK_SIZE(CNMJoinToChatRoomFunc, 0x880);

// vftable 0x142f40950, destructor 0x1415ee350.
class CNMLoginAuthFunc : public CNMFunc
{
public:
    CNMLoginAuthFunc();
    CNMLoginAuthFunc(const char* password, unsigned int value);
    CNMLoginAuthFunc(const char* user, const char* password, unsigned int value);
    CNMLoginAuthFunc(const char* user, const char* password, unsigned int value,
                     const char* token, unsigned int flags);
    virtual ~CNMLoginAuthFunc() = default;
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    int m_mode; // +0x30
    char m_password[0x1000]; // +0x34
    char m_user[0x100]; // +0x1034
    char m_1134[0x80];
    int m_11b4;
    int m_value;
    char m_token[0x200]; // +0x11bc
    int m_flags;
    int m_result;
    int m_timeout;
};
MS2_CHECK_SIZE(CNMLoginAuthFunc, 0x13c8);

// vftable 0x142f40810, destructor 0x1415ee3d0.
class CNMLoginNexonPassportFunc : public CNMFunc
{
public:
    CNMLoginNexonPassportFunc();
    CNMLoginNexonPassportFunc(const char* passport, unsigned long long token, unsigned int result);
    virtual ~CNMLoginNexonPassportFunc() = default;

    char m_30[0x1000];
    int m_1030;
    unsigned long long m_1038;
    unsigned int m_1040;

    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
};
MS2_CHECK_SIZE(CNMLoginNexonPassportFunc, 0x1048);

// vftable 0x142f407a8, destructor 0x1415ee3f0.
class CNMLoginPassportFunc : public CNMFunc
{
public:
    CNMLoginPassportFunc();
    CNMLoginPassportFunc(const char* account, const char* passport, unsigned long long token,
                         const unsigned char* payload, int payloadSize, unsigned int flags,
                         unsigned int result);
    CNMLoginPassportFunc(const char* account, const char* passport, const unsigned char* payload,
                         int payloadSize, unsigned int flags, unsigned int result);
    virtual ~CNMLoginPassportFunc() = default;

    char m_30[0x40];
    char m_70[0x40];
    int m_b0;
    unsigned long long m_b8;
    unsigned char m_c0[0x8000];
    int m_80c0;
    int m_80c4;
    int m_80c8;
    int m_80cc;

    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
};
MS2_CHECK_SIZE(CNMLoginPassportFunc, 0x80d0);

// vftable 0x142f422f0, destructor 0x1415ee680.
class CNMNotifyEvent : public CNMEvent
{
public:
    virtual ~CNMNotifyEvent() = default;

    unsigned char m_body[0x820];
};
MS2_CHECK_SIZE(CNMNotifyEvent, 0x848);

// vftable 0x142f3c298, destructor 0x1415ee8d0.
class CNMReportInfo : public CNMSerializable
{
public:
    CNMReportInfo();
    virtual ~CNMReportInfo() = default;

    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    unsigned int m_10, m_14, m_18, m_1c;
    char m_20[0x40];
    char m_60[4000];
    char m_1000[20000];
    unsigned int m_5e20;
    char m_5e24[0x40];
};
MS2_CHECK_SIZE(CNMReportInfo, 0x5e68);

// vftable 0x142f3f690, destructor 0x1415ee930.
class CNMRequestFileUploadSessionExFunc : public CNMFunc
{
public:
    CNMRequestFileUploadSessionExFunc(); // 0x141598e60
    CNMRequestFileUploadSessionExFunc(const unsigned char* pTarget, unsigned int nTarget,
                                      std::vector<CNMFilePath> files); // 0x141598f10
    virtual ~CNMRequestFileUploadSessionExFunc() = default;

    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override; // 0x1415990a0
    unsigned int EncodeFramed(CNMStream* pStream) override;                 // 0x141598fe0
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override; // 0x141599040
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override; // 0x141599320
    unsigned int DecodeFramed(CNMStream* pStream) override;                 // 0x141599230
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override; // 0x1415992c0

    unsigned __int64 m_30;
    unsigned int m_38, m_3c, m_40, m_44, m_48, m_4c;
    std::vector<CNMFilePath> m_files;                 // +0x50
    unsigned int m_68, m_6c;
};
MS2_CHECK_SIZE(CNMRequestFileUploadSessionExFunc, 0x70);

// vftable 0x142f3f4d0, destructor 0x1415ee960.
class CNMRequestFileUploadSessionFunc : public CNMFunc
{
public:
    CNMRequestFileUploadSessionFunc(); // 0x1415977c0
    CNMRequestFileUploadSessionFunc(const unsigned char* pTarget, unsigned int nTarget,
                                   std::vector<CNMFilePath> files); // 0x141597860
    virtual ~CNMRequestFileUploadSessionFunc() = default;

    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override; // 0x1415979f0
    unsigned int EncodeFramed(CNMStream* pStream) override;                 // 0x141597930
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override; // 0x141597990
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override; // 0x141597c50
    unsigned int DecodeFramed(CNMStream* pStream) override;                 // 0x141597b60
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override; // 0x141597bf0

    unsigned __int64 m_30;
    unsigned m_38, m_3c, m_40;
    std::vector<CNMFilePath> m_48;
    unsigned m_60, m_64;
};
MS2_CHECK_SIZE(CNMRequestFileUploadSessionFunc, 0x68);

// vftable 0x142f3f618, destructor 0x1415ee990.
class CNMRequestMultiChatSessionExFunc : public CNMFunc
{
public:
    CNMRequestMultiChatSessionExFunc(); // 0x141598820
    CNMRequestMultiChatSessionExFunc(NMKey64 key, const std::vector<NMFriendKey>& targets, int mode); // 0x1415988b0
    virtual ~CNMRequestMultiChatSessionExFunc() = default;

    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override; // 0x141598a20
    unsigned int EncodeFramed(CNMStream* pStream) override;                 // 0x141598960
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override; // 0x1415989c0
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override; // 0x141598cb0
    unsigned int DecodeFramed(CNMStream* pStream) override;                 // 0x141598bc0
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override; // 0x141598c50

    NMKey64 m_key;
    std::vector<NMFriendKey> m_targets;
    unsigned int m_50, m_54;
};
MS2_CHECK_SIZE(CNMRequestMultiChatSessionExFunc, 0x58);

// vftable 0x142f3f460, destructor 0x1415ee9c0.
class CNMRequestMultiChatSessionFunc : public CNMFunc
{
public:
    CNMRequestMultiChatSessionFunc(); // 0x1415971e0
    CNMRequestMultiChatSessionFunc(NMKey64 key, const std::vector<NMChatSessionTarget>& targets, int mode); // 0x141597270
    virtual ~CNMRequestMultiChatSessionFunc() = default;

    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override; // 0x1415973e0
    unsigned int EncodeFramed(CNMStream* pStream) override;                 // 0x141597320
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override; // 0x141597380
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override; // 0x141597640
    unsigned int DecodeFramed(CNMStream* pStream) override;                 // 0x141597550
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override; // 0x1415975e0

    NMKey64 m_key;
    std::vector<NMChatSessionTarget> m_targets;
    unsigned int m_50, m_54;
};
MS2_CHECK_SIZE(CNMRequestMultiChatSessionFunc, 0x58);

// vftable 0x142f3f988, destructor 0x1415eeab0.
class CNMRequestSessionToOtherFunc : public CNMFunc
{
public:
    CNMRequestSessionToOtherFunc(); // 0x14159b760
    CNMRequestSessionToOtherFunc(unsigned int n30, unsigned int n34, NMKey64 key, const char* name,
                                 unsigned int n84, const std::vector<CNMFilePath>& files);
    CNMRequestSessionToOtherFunc(unsigned int n30, unsigned int n34, NMKey64 key, const char* name,
                                 unsigned int n84, unsigned int nA0);
    virtual ~CNMRequestSessionToOtherFunc() = default;

    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    unsigned int m_30, m_34, m_38;
    NMKey64 m_3c; // inferred: single qword assignment at 0x14159b8df; 4-byte alignment preserves +0x3c.
    char m_44[0x40];
    unsigned int m_84;
    std::vector<CNMFilePath> m_files;                 // +0x88 (exe serializer decodes CNMFilePath records)
    unsigned int m_a0, m_a4, m_a8;
};
MS2_CHECK_SIZE(CNMRequestSessionToOtherFunc, 0xb0);

// vftable 0x142f3bf58, destructor 0x1415eeb70.
class CNMSelfUserInfo : public CNMRealUserInfo
{
public:
    CNMSelfUserInfo();
    virtual ~CNMSelfUserInfo() = default;
};
MS2_CHECK_SIZE(CNMSelfUserInfo, 0x1a8);

// vftable 0x142f3e218, destructor 0x1415eeb90.
class CNMSendAccuseNoteMsgFunc : public CNMFunc
{
public:
    CNMSendAccuseNoteMsgFunc(); // 0x14158aea0
    CNMSendAccuseNoteMsgFunc(int type, const void* details, int status); // 0x14158af10
    virtual ~CNMSendAccuseNoteMsgFunc() = default;
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    CNMReportInfo m_report;                           // +0x30
};
MS2_CHECK_SIZE(CNMSendAccuseNoteMsgFunc, 0x5e98);

// vftable 0x142f3c208, destructor 0x1415ee630.
class CNMNoteInfoEx : public CNMSerializable
{
public:
    CNMNoteInfoEx();
    virtual ~CNMNoteInfoEx() = default;

    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    int m_10; // +0x10
    char m_14[0x8000]; // +0x14
    int m_8014; // +0x8014
};
MS2_CHECK_SIZE(CNMNoteInfoEx, 0x8018);

// vftable 0x142f3f388, destructor 0x1415eebc0.
class CNMSendNoteExMsgFunc : public CNMFunc
{
public:
    CNMSendNoteExMsgFunc();
    CNMSendNoteExMsgFunc(int nType, const char* szText);
    virtual ~CNMSendNoteExMsgFunc() = default;
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    CNMNoteInfoEx m_note;                             // +0x30
};
MS2_CHECK_SIZE(CNMSendNoteExMsgFunc, 0x8048);

// vftable 0x142f3e2f0, destructor 0x1415eebf0.
class CNMSendNoteInfoFunc : public CNMFunc
{
public:
    CNMSendNoteInfoFunc(); // 0x14158b610
    CNMSendNoteInfoFunc(const CNMNoteInfo& note, int status); // 0x14158b690
    virtual ~CNMSendNoteInfoFunc() = default;
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    unsigned char m_30[0x8];                          // +0x30 (not recovered)
    CNMNoteInfo2 m_note;                              // +0x38
};
MS2_CHECK_SIZE(CNMSendNoteInfoFunc, 0xb20);

// vftable 0x142f3e1b0, destructor 0x1415eec20.
class CNMSendNoteMsgFunc : public CNMFunc
{
public:
    CNMSendNoteMsgFunc(); // 0x14158a810
    CNMSendNoteMsgFunc(int type, int index, const void* subject, const void* message, const void* sender, const void* recipient, int status); // 0x14158a880
    CNMSendNoteMsgFunc(int type, int index, unsigned __int64 timestamp, const void* subject, const void* message, const void* sender, const void* recipient, int status); // 0x14158aa30
    virtual ~CNMSendNoteMsgFunc() = default;
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    unsigned char m_30[0x8];                          // +0x30 (not recovered)
    CNMNoteInfo m_note;                               // +0x38
};
MS2_CHECK_SIZE(CNMSendNoteMsgFunc, 0xf00);

// vftable 0x142f3df28, destructor 0x1415ec1f0.
class CNMAddCategoryFunc : public CNMFunc
{
public:
    CNMAddCategoryFunc(); // 0x141588e20
    CNMAddCategoryFunc(long long key, long long name, int flags, int status); // 0x141588eb0
    virtual ~CNMAddCategoryFunc() = default;
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    NMKey64 m_30; // +0x30
    char m_38[0x20]; // +0x38
    int m_58; // +0x58
    int m_5c; // +0x5c
};
MS2_CHECK_SIZE(CNMAddCategoryFunc, 0x60);

// vftable 0x142f3ddd8, destructor 0x1415ec210.
class CNMAddFriendToCategoryFunc : public CNMFunc
{
public:
    CNMAddFriendToCategoryFunc(); // 0x141587fc0
    CNMAddFriendToCategoryFunc(const unsigned char* key, int category, int flag); // 0x141588050
    virtual ~CNMAddFriendToCategoryFunc() = default;
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    NMFriendKey m_key;
    int m_48; // +0x48
    int m_4c; // +0x4c
};
MS2_CHECK_SIZE(CNMAddFriendToCategoryFunc, 0x50);

// vftable 0x142f3e430, destructor 0x1415ec230.
class CNMAppendRejectedUserFunc : public CNMFunc
{
public:
    CNMAppendRejectedUserFunc(); // 0x14158c3c0
    CNMAppendRejectedUserFunc(const CNMRejectedUser* user); // 0x14158c430
    virtual ~CNMAppendRejectedUserFunc() = default;
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    CNMRejectedUser m_30; // +0x30
};
MS2_CHECK_SIZE(CNMAppendRejectedUserFunc, 0xf8);

// vftable 0x142f3cd50, destructor 0x1415ec260.
class CNMAttachToNMCOServerFunc : public CNMFunc
{
public:
    CNMAttachToNMCOServerFunc();
    CNMAttachToNMCOServerFunc(int a, int b, int c, int d, int e);
    virtual ~CNMAttachToNMCOServerFunc() = default;
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    int m_30; // +0x30
    int m_34; // +0x34
    int m_38; // +0x38
    int m_3c; // +0x3c
    int m_40; // +0x40
    int m_44; // +0x44
};
MS2_CHECK_SIZE(CNMAttachToNMCOServerFunc, 0x48);

// vftable 0x142f43120, destructor 0x1415ec280.
class CNMAttendanceEventEvent : public CNMEvent
{
public:
    virtual ~CNMAttendanceEventEvent() = default;

    int m_28; // +0x28
    int m_2c; // +0x2c
};
MS2_CHECK_SIZE(CNMAttendanceEventEvent, 0x30);

// vftable 0x142f41fb0, destructor 0x1415ec2a0.
class CNMAuthConnectionClosedEvent : public CNMEvent
{
public:
    CNMAuthConnectionClosedEvent();
    explicit CNMAuthConnectionClosedEvent(int reason);
    virtual ~CNMAuthConnectionClosedEvent() = default;
    char* vfunc_8() override { return const_cast<char*>("CNMAuthConnectionClosedEvent"); }

    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    int m_28; // +0x28
    int m_2c; // +0x2c
};
MS2_CHECK_SIZE(CNMAuthConnectionClosedEvent, 0x30);

// vftable 0x142f42038, destructor 0x1415ec2c0.
class CNMAuthSecondaryConnectionClosedEvent : public CNMEvent
{
public:
    CNMAuthSecondaryConnectionClosedEvent();
    explicit CNMAuthSecondaryConnectionClosedEvent(int reason);
    virtual ~CNMAuthSecondaryConnectionClosedEvent() = default;
    char* vfunc_8() override { return const_cast<char*>("CNMAuthSecondaryConnectionClosedEvent"); }

    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    int m_28; // +0x28
    int m_2c; // +0x2c
};
MS2_CHECK_SIZE(CNMAuthSecondaryConnectionClosedEvent, 0x30);

// vftable 0x142f3dc98, destructor 0x1415ec320.
class CNMBlockFriendFunc : public CNMFunc
{
public:
    CNMBlockFriendFunc(); // 0x1415872d0
    CNMBlockFriendFunc(const unsigned char* key, int blockType); // 0x141587360
    virtual ~CNMBlockFriendFunc() = default;
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    NMFriendKey m_key;
    int m_48; // +0x48
    int m_4c; // +0x4c
};
MS2_CHECK_SIZE(CNMBlockFriendFunc, 0x50);

// vftable 0x142f413a0, destructor 0x1415ec360.
class CNMCHBanUserFunc : public CNMFunc
{
public:
    CNMCHBanUserFunc();
    CNMCHBanUserFunc(int n18, int n30);
    virtual ~CNMCHBanUserFunc() = default;
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    int m_30; // +0x30
    int m_34; // +0x34
};
MS2_CHECK_SIZE(CNMCHBanUserFunc, 0x38);

// vftable 0x142f3cac0, destructor 0x1415ecbd0.
class CNMChannelInfo : public CNMSerializable
{
public:
    CNMChannelInfo();
    CNMChannelInfo(const CNMChannelInfo& r);
    CNMChannelInfo& operator=(const CNMChannelInfo& r);
    virtual ~CNMChannelInfo() = default;
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    int m_10; // +0x10
    int m_14; // +0x14
    int m_18; // +0x18
    int m_1c; // +0x1c
    int m_20; // +0x20
    int m_24; // +0x24
    CNMStr<0x400> m_28; // +0x28
    CNMStr<0x40> m_30; // +0x30
    int m_38; // +0x38
    int m_3c; // +0x3c
    int m_40; // +0x40
    int m_44; // +0x44
    int m_48; // +0x48
    int m_4c; // +0x4c
    CNMStr<0x40> m_50; // +0x50
};
MS2_CHECK_SIZE(CNMChannelInfo, 0x58);

// vftable 0x142f3cb08, destructor 0x1415ed000.
class CNMClientChannelInfo : public CNMChannelInfo
{
public:
    CNMClientChannelInfo();
    CNMClientChannelInfo(const CNMClientChannelInfo& r);
    CNMClientChannelInfo(const CNMChannelInfo& r);
    CNMClientChannelInfo(const void* key, int a, int b);
    virtual ~CNMClientChannelInfo() = default;
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    int m_58; // +0x58
    int m_5c; // +0x5c
};
MS2_CHECK_SIZE(CNMClientChannelInfo, 0x60);

// vftable 0x142f411f0, destructor 0x1415ec380.
class CNMCHChangeChannelInfoFunc : public CNMFunc
{
public:
    CNMCHChangeChannelInfoFunc();
    CNMCHChangeChannelInfoFunc(int n18, const CNMClientChannelInfo& rChannelInfo);
    virtual ~CNMCHChangeChannelInfoFunc() = default;
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    CNMClientChannelInfo m_30; // +0x30
};
MS2_CHECK_SIZE(CNMCHChangeChannelInfoFunc, 0x90);

// vftable 0x142f412d0, destructor 0x1415ec3b0.
class CNMCHChangeMyInfoFunc : public CNMFunc
{
public:
    CNMCHChangeMyInfoFunc();
    CNMCHChangeMyInfoFunc(int n18);
    CNMCHChangeMyInfoFunc(int n18, const CNMChannelMemberInfo& rMember);
    virtual ~CNMCHChangeMyInfoFunc() = default;
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    CNMChannelMemberInfo m_30; // +0x30
};
MS2_CHECK_SIZE(CNMCHChangeMyInfoFunc, 0x60);

// vftable 0x142f41128, destructor 0x1415ec3e0.
class CNMCHCloseFunc : public CNMFunc
{
public:
    CNMCHCloseFunc();
    CNMCHCloseFunc(int n30);
    virtual ~CNMCHCloseFunc() = default;
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
};
MS2_CHECK_SIZE(CNMCHCloseFunc, 0x30);

// vftable 0x142f41188, destructor 0x1415ec400.
class CNMCHGetChannelInfoFunc : public CNMFunc
{
public:
    CNMCHGetChannelInfoFunc();
    CNMCHGetChannelInfoFunc(int n18);
    virtual ~CNMCHGetChannelInfoFunc() = default;
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    CNMClientChannelInfo m_30; // +0x30
};
MS2_CHECK_SIZE(CNMCHGetChannelInfoFunc, 0x90);

// vftable 0x142f41260, destructor 0x1415ec430.
class CNMCHGetMemberInfoListFunc : public CNMFunc
{
public:
    CNMCHGetMemberInfoListFunc();
    CNMCHGetMemberInfoListFunc(int n18);
    virtual ~CNMCHGetMemberInfoListFunc() = default;
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    std::vector<CNMChannelMemberInfo> m_30; // +0x30
};
MS2_CHECK_SIZE(CNMCHGetMemberInfoListFunc, 0x48);

// vftable 0x142f41338, destructor 0x1415ec460.
class CNMCHInviteUserFunc : public CNMFunc
{
public:
    CNMCHInviteUserFunc();
    CNMCHInviteUserFunc(int n18, const char* psz30, const char* psz38);
    virtual ~CNMCHInviteUserFunc() = default;
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    CNMStr<0x400> m_30; // +0x30
    CNMStr<0x800> m_38; // +0x38
};
MS2_CHECK_SIZE(CNMCHInviteUserFunc, 0x40);

// vftable 0x142f41408, destructor 0x1415ec4a0.
class CNMCHSendChannelMessageFunc : public CNMFunc
{
public:
    CNMCHSendChannelMessageFunc();
    CNMCHSendChannelMessageFunc(int n18);
    CNMCHSendChannelMessageFunc(int n18, const CNMChannelMessage& rMessage);
    virtual ~CNMCHSendChannelMessageFunc() = default;
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    CNMChannelMessage m_30; // +0x30
};
MS2_CHECK_SIZE(CNMCHSendChannelMessageFunc, 0x78);

// vftable 0x142f3fcd0, destructor 0x1415ec4f0.
class CNMCRChangeMyInfoFunc : public CNMFunc
{
public:
    CNMCRChangeMyInfoFunc();
    CNMCRChangeMyInfoFunc(int nFlags, const char* pszInfo);
    virtual ~CNMCRChangeMyInfoFunc() = default;
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    CNMChatRoomMemberInfo m_30; // +0x30
};
MS2_CHECK_SIZE(CNMCRChangeMyInfoFunc, 0x250);

// vftable 0x142f42368, destructor 0x1415ec540.
class CNMCRChatRoomCreatedEvent : public CNMEvent
{
public:
    virtual ~CNMCRChatRoomCreatedEvent() = default;

    int m_28; // +0x28
    int m_2c; // +0x2c
    CNMChatRoomInfo m_30; // +0x30
    CNMChatRoomMemberInfo m_630; // +0x630
};
MS2_CHECK_SIZE(CNMCRChatRoomCreatedEvent, 0x850);

// vftable 0x142f423f0, destructor 0x1415ec580.
class CNMCRChatRoomCreatedExEvent : public CNMEvent
{
public:
    virtual ~CNMCRChatRoomCreatedExEvent() = default;

    int m_28; // +0x28
    int m_2c; // +0x2c
    CNMChatRoomInfoEx m_30; // +0x30
    CNMChatRoomMemberInfo m_510; // +0x510
};
MS2_CHECK_SIZE(CNMCRChatRoomCreatedExEvent, 0x730);

// vftable 0x142f42588, destructor 0x1415ec5c0.
class CNMCRChatRoomErrorEvent : public CNMEvent
{
public:
    virtual ~CNMCRChatRoomErrorEvent() = default;

    int m_28; // +0x28
    int m_2c; // +0x2c
};
MS2_CHECK_SIZE(CNMCRChatRoomErrorEvent, 0x30);

// vftable 0x142f42478, destructor 0x1415ec5e0.
class CNMCRChatRoomEstablishedEvent : public CNMEvent
{
public:
    virtual ~CNMCRChatRoomEstablishedEvent() = default;

    int m_28; // +0x28
    int m_2c; // +0x2c
    CNMChatRoomInfo m_30; // +0x30
    CNMChatRoomMemberInfo m_630; // +0x630
};
MS2_CHECK_SIZE(CNMCRChatRoomEstablishedEvent, 0x850);

// vftable 0x142f42500, destructor 0x1415ec620.
class CNMCRChatRoomEstablishedExEvent : public CNMEvent
{
public:
    virtual ~CNMCRChatRoomEstablishedExEvent() = default;

    int m_28; // +0x28
    int m_2c; // +0x2c
    CNMChatRoomInfoEx m_30; // +0x30
    CNMChatRoomMemberInfo m_510; // +0x510
};
MS2_CHECK_SIZE(CNMCRChatRoomEstablishedExEvent, 0x730);

// vftable 0x142f42690, destructor 0x1415ec660.
class CNMCRChatRoomInfoEvent : public CNMEvent
{
public:
    virtual ~CNMCRChatRoomInfoEvent() = default;

    int m_28; // +0x28
    int m_2c; // +0x2c
    CNMChatRoomInfo m_30; // +0x30
    CNMChatRoomMemberInfo m_630; // +0x630
};
MS2_CHECK_SIZE(CNMCRChatRoomInfoEvent, 0x850);

// vftable 0x142f42710, destructor 0x1415ec6a0.
class CNMCRChatRoomInfoExEvent : public CNMEvent
{
public:
    virtual ~CNMCRChatRoomInfoExEvent() = default;

    int m_28; // +0x28
    int m_2c; // +0x2c
    CNMChatRoomInfoEx m_30; // +0x30
    CNMChatRoomMemberInfo m_510; // +0x510
};
MS2_CHECK_SIZE(CNMCRChatRoomInfoExEvent, 0x730);

// vftable 0x142f42608, destructor 0x1415ec6e0.
class CNMCRChatRoomMemberEvent : public CNMEvent
{
public:
    virtual ~CNMCRChatRoomMemberEvent() = default;

    int m_28; // +0x28
    int m_2c; // +0x2c
    std::vector<CNMChatRoomMemberInfo> m_30; // +0x30
    CNMChatRoomMemberInfo m_48; // +0x48
    CNMChatRoomMemberInfo m_268; // +0x268
};
MS2_CHECK_SIZE(CNMCRChatRoomMemberEvent, 0x488);

// vftable 0x142f42798, destructor 0x1415ec730.
class CNMCRChatRoomMessageReceivedEvent : public CNMEvent
{
public:
    virtual ~CNMCRChatRoomMessageReceivedEvent() = default;
    void vfunc_11(unsigned int) override;

    int m_28; // +0x28
    int m_2c; // +0x2c
    CNMChatMessage m_30; // +0x30
    int m_6a0; // +0x6a0
    int m_6a4; // +0x6a4
};
MS2_CHECK_SIZE(CNMCRChatRoomMessageReceivedEvent, 0x6a8);

// vftable 0x142f3fb98, destructor 0x1415ec810.
class CNMCRGetRoomInfoFunc : public CNMFunc
{
public:
    CNMCRGetRoomInfoFunc(); // 0x14159cfb0
    explicit CNMCRGetRoomInfoFunc(unsigned uSerialKey); // 0x14159d020
    virtual ~CNMCRGetRoomInfoFunc() = default;

    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    CNMChatRoomInfo m_room; // +0x30 (reply)
};
MS2_CHECK_SIZE(CNMCRGetRoomInfoFunc, 0x630);

// vftable 0x142f42d58, destructor 0x1415ec8b0.
class CNMCSChatMessageReceivedEvent : public CNMEvent
{
public:
    virtual ~CNMCSChatMessageReceivedEvent() = default;
    void vfunc_11(unsigned int) override;

    int m_28; // +0x28
    int m_2c; // +0x2c
    CNMChatMessage m_30; // +0x30
    int m_6a0; // +0x6a0
    int m_6a4; // +0x6a4
};
MS2_CHECK_SIZE(CNMCSChatMessageReceivedEvent, 0x6a8);

// vftable 0x142f42de0, destructor 0x1415ec900.
class CNMCSMultiChatCreatedEvent : public CNMEvent
{
public:
    virtual ~CNMCSMultiChatCreatedEvent() = default;

    int m_28; // +0x28
    int m_2c; // +0x2c
};
MS2_CHECK_SIZE(CNMCSMultiChatCreatedEvent, 0x30);

// vftable 0x142f402a0, destructor 0x1415ec920.
class CNMCSSendChatMessageFunc : public CNMFunc
{
public:
    CNMCSSendChatMessageFunc();
    CNMCSSendChatMessageFunc(unsigned int serial, const CNMChatMessage& message);
    virtual ~CNMCSSendChatMessageFunc() = default;

    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    CNMChatMessage m_30; // +0x30
};
MS2_CHECK_SIZE(CNMCSSendChatMessageFunc, 0x6a0);

// vftable 0x142f3e0d8, destructor 0x1415ec9a0.
class CNMChangeCategoryAllowTypeFunc : public CNMFunc
{
public:
    CNMChangeCategoryAllowTypeFunc(); // 0x141589e10
    CNMChangeCategoryAllowTypeFunc(int category, int allowType, int value); // 0x141589e80
    virtual ~CNMChangeCategoryAllowTypeFunc() = default;
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    int m_30; // +0x30
    int m_34; // +0x34
    int m_38; // +0x38
    int m_3c; // +0x3c
};
MS2_CHECK_SIZE(CNMChangeCategoryAllowTypeFunc, 0x40);

// vftable 0x142f3dff8, destructor 0x1415ec9c0.
class CNMChangeCategoryNameFunc : public CNMFunc
{
public:
    CNMChangeCategoryNameFunc(); // 0x141589630
    CNMChangeCategoryNameFunc(int category, long long name, int flag); // 0x1415896a0
    virtual ~CNMChangeCategoryNameFunc() = default;
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    int m_30; // +0x30
    char m_34[0x20]; // +0x34
    int m_54; // +0x54
};
MS2_CHECK_SIZE(CNMChangeCategoryNameFunc, 0x58);

// vftable 0x142f3e068, destructor 0x1415ec9e0.
class CNMChangeCategoryPropertyFunc : public CNMFunc
{
public:
    CNMChangeCategoryPropertyFunc(); // 0x141589a40
    CNMChangeCategoryPropertyFunc(int category, int property, int value); // 0x141589ab0
    virtual ~CNMChangeCategoryPropertyFunc() = default;
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    int m_30; // +0x30
    int m_34; // +0x34
    int m_38; // +0x38
    int m_3c; // +0x3c
};
MS2_CHECK_SIZE(CNMChangeCategoryPropertyFunc, 0x40);

// vftable 0x142f3c3b8, destructor 0x1415ee570.
class CNMMyGameInfo : public CNMSerializable
{
public:
    CNMMyGameInfo();
    virtual ~CNMMyGameInfo() = default;

    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    int m_10[0xa]; // +0x10
};
MS2_CHECK_SIZE(CNMMyGameInfo, 0x38);

// vftable 0x142f3d3a0, destructor 0x1415eca00.
class CNMChangeConfigFunc : public CNMFunc
{
public:
    CNMChangeConfigFunc(); // 0x141581c00
    CNMChangeConfigFunc(int setting1, int setting2, int setting3, int setting4, long long gameInfo); // 0x141581ca0
    virtual ~CNMChangeConfigFunc() = default;

    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    int m_30; // +0x30
    int m_34; // +0x34
    int m_38; // +0x38
    int m_3c; // +0x3c
    int m_40; // +0x40
    int m_44; // +0x44
    CNMMyGameInfo m_48; // +0x48
};
MS2_CHECK_SIZE(CNMChangeConfigFunc, 0x80);

// vftable 0x142f3dd68, destructor 0x1415eca30.
class CNMChangeFriendMemoExFunc : public CNMFunc
{
public:
    CNMChangeFriendMemoExFunc(); // 0x141587b10
    CNMChangeFriendMemoExFunc(const unsigned char* key, long long memo); // 0x141587ba0
    virtual ~CNMChangeFriendMemoExFunc() = default;
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    unsigned long long m_30; // +0x30
    int m_38; // +0x38
    int m_3c; // +0x3c
    int m_40; // +0x40
    int m_44; // +0x44
    char m_48[0x20]; // +0x48
};
MS2_CHECK_SIZE(CNMChangeFriendMemoExFunc, 0x68);

// vftable 0x142f3dd00, destructor 0x1415eca50.
class CNMChangeFriendMemoFunc : public CNMFunc
{
public:
    CNMChangeFriendMemoFunc(); // 0x141587740
    CNMChangeFriendMemoFunc(long long key, long long memo); // 0x1415877b0
    virtual ~CNMChangeFriendMemoFunc() = default;
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    long long m_30; // +0x30
    char m_38[0x20]; // +0x38
};
MS2_CHECK_SIZE(CNMChangeFriendMemoFunc, 0x58);

// vftable 0x142f3d470, destructor 0x1415eca70.
class CNMChangeLocalConfigFunc : public CNMFunc
{
public:
    CNMChangeLocalConfigFunc(); // 0x1415825b0
    CNMChangeLocalConfigFunc(unsigned result, long long config); // 0x141582620
    virtual ~CNMChangeLocalConfigFunc() = default;

    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    int m_30; // +0x30
    char m_34[0x404]; // +0x34
};
MS2_CHECK_SIZE(CNMChangeLocalConfigFunc, 0x438);

// vftable 0x142f3d608, destructor 0x1415eca90.
class CNMChangeMetaDataFunc : public CNMFunc
{
public:
    CNMChangeMetaDataFunc(); // 0x141583480
    CNMChangeMetaDataFunc(long long key, long long metadata); // 0x1415834f0
    virtual ~CNMChangeMetaDataFunc() = default;
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    NMKey64 m_30; // +0x30
    char m_38[0x3e8]; // +0x38
};
MS2_CHECK_SIZE(CNMChangeMetaDataFunc, 0x420);

// vftable 0x142f3d2d0, destructor 0x1415ecab0.
class CNMChangeMyInfoFunc : public CNMFunc
{
public:
    CNMChangeMyInfoFunc(); // 0x141581070
    CNMChangeMyInfoFunc(int mode, long long name, long long position, int state, unsigned extra); // 0x141581110
    virtual ~CNMChangeMyInfoFunc() = default;

    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    int m_30; // +0x30
    int m_34; // +0x34
    char m_38[0x40]; // +0x38
    char m_78[0x40]; // +0x78
    int m_b8; // +0xb8
    int m_bc; // +0xbc
};
MS2_CHECK_SIZE(CNMChangeMyInfoFunc, 0xc0);

// vftable 0x142f406d0, destructor 0x1415ecad0.
class CNMChangeMyLevelFunc : public CNMFunc
{
public:
    CNMChangeMyLevelFunc();
    CNMChangeMyLevelFunc(int level, int job);
    virtual ~CNMChangeMyLevelFunc() = default;

    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    int m_30; // +0x30
    int m_34; // +0x34
    int m_38; // +0x38
    int m_3c; // +0x3c
};
MS2_CHECK_SIZE(CNMChangeMyLevelFunc, 0x40);

// vftable 0x142f3d128, destructor 0x1415ecaf0.
class CNMChangeMyPositionFunc : public CNMFunc
{
public:
    CNMChangeMyPositionFunc(); // 0x141580080
    explicit CNMChangeMyPositionFunc(long long position); // 0x1415800f0
    CNMChangeMyPositionFunc(long long key, long long position); // 0x1415801a0
    virtual ~CNMChangeMyPositionFunc() = default;
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    NMKey64 m_30; // +0x30
    char m_38[0x40]; // +0x38
};
MS2_CHECK_SIZE(CNMChangeMyPositionFunc, 0x78);

// vftable 0x142f3d5a0, destructor 0x1415ecb10.
class CNMChangeNicknameFunc : public CNMFunc
{
public:
    CNMChangeNicknameFunc(); // 0x141583080
    CNMChangeNicknameFunc(long long key, long long nickname); // 0x1415830f0
    virtual ~CNMChangeNicknameFunc() = default;
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    NMKey64 m_30; // +0x30
    char m_38[0x40]; // +0x38
};
MS2_CHECK_SIZE(CNMChangeNicknameFunc, 0x78);

// vftable 0x142f43220, destructor 0x1415ecb30.
class CNMChannelCreatedEvent : public CNMEvent
{
public:
    virtual ~CNMChannelCreatedEvent() = default;

    int m_28; // +0x28
    int m_2c; // +0x2c
    CNMClientChannelInfo m_30; // +0x30
    CNMChannelMemberInfo m_90; // +0x90
};
MS2_CHECK_SIZE(CNMChannelCreatedEvent, 0xc0);

// vftable 0x142f431a0, destructor 0x1415ecb70.
class CNMChannelErrorEvent : public CNMEvent
{
public:
    virtual ~CNMChannelErrorEvent() = default;

    int m_28; // +0x28
    int m_2c; // +0x2c
};
MS2_CHECK_SIZE(CNMChannelErrorEvent, 0x30);

// vftable 0x142f432a0, destructor 0x1415ecb90.
class CNMChannelEstablishedEvent : public CNMEvent
{
public:
    virtual ~CNMChannelEstablishedEvent() = default;

    int m_28; // +0x28
    int m_2c; // +0x2c
    CNMClientChannelInfo m_30; // +0x30
    CNMChannelMemberInfo m_90; // +0x90
};
MS2_CHECK_SIZE(CNMChannelEstablishedEvent, 0xc0);

// vftable 0x142f43328, destructor 0x1415ecc20.
class CNMChannelInfoEvent : public CNMEvent
{
public:
    virtual ~CNMChannelInfoEvent() = default;

    int m_28; // +0x28
    int m_2c; // +0x2c
    CNMClientChannelInfo m_30; // +0x30
    CNMChannelMemberInfo m_90; // +0x90
};
MS2_CHECK_SIZE(CNMChannelInfoEvent, 0xc0);

// vftable 0x142f433a8, destructor 0x1415ecca0.
class CNMChannelMemberInfoEvent : public CNMEvent
{
public:
    virtual ~CNMChannelMemberInfoEvent() = default;

    int m_28; // +0x28
    int m_2c; // +0x2c
    CNMChannelMemberInfo m_30; // +0x30
};
MS2_CHECK_SIZE(CNMChannelMemberInfoEvent, 0x60);

// vftable 0x142f3cb98, destructor 0x1415eccd0.
class CNMChannelMemberInfoList : public CNMSerializable
{
public:
    CNMChannelMemberInfoList();
    CNMChannelMemberInfoList(const CNMChannelMemberInfoList& r);
    virtual ~CNMChannelMemberInfoList() = default;
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    std::vector<CNMChannelMemberInfo> m_10; // +0x10
};
MS2_CHECK_SIZE(CNMChannelMemberInfoList, 0x28);

// vftable 0x142f43430, destructor 0x1415ecd00.
class CNMChannelMemberInfoListEvent : public CNMEvent
{
public:
    virtual ~CNMChannelMemberInfoListEvent() = default;

    int m_28; // +0x28
    int m_2c; // +0x2c
    std::vector<CNMChannelMemberInfo> m_30; // +0x30
};
MS2_CHECK_SIZE(CNMChannelMemberInfoListEvent, 0x48);

// vftable 0x142f434b8, destructor 0x1415ecd80.
class CNMChannelMessageEvent : public CNMEvent
{
public:
    virtual ~CNMChannelMessageEvent() = default;

    int m_28; // +0x28
    int m_2c; // +0x2c
    CNMChannelMessage m_30; // +0x30
};
MS2_CHECK_SIZE(CNMChannelMessageEvent, 0x78);

// vftable 0x142f41050, destructor 0x1415ecdd0.
class CNMCharacterChangeName64Func : public CNMFunc
{
public:
    CNMCharacterChangeName64Func();
    CNMCharacterChangeName64Func(const char* sz30, long long n70, int n78);
    virtual ~CNMCharacterChangeName64Func() = default;
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    char m_30[0x40]; // +0x30
    long long m_70; // +0x70
    int m_78; // +0x78
    int m_7c; // +0x7c
};
MS2_CHECK_SIZE(CNMCharacterChangeName64Func, 0x80);

// vftable 0x142f40e30, destructor 0x1415ecdf0.
class CNMCharacterChangeNameFunc : public CNMFunc
{
public:
    CNMCharacterChangeNameFunc();
    CNMCharacterChangeNameFunc(NMKey64 key, const char* pszName, int n78);
    virtual ~CNMCharacterChangeNameFunc() = default;
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    NMKey64 m_30; // +0x30
    char m_38[0x40]; // +0x38
    int m_78; // +0x78
    int m_7c; // +0x7c
};
MS2_CHECK_SIZE(CNMCharacterChangeNameFunc, 0x80);

// vftable 0x142f40f08, destructor 0x1415ece10.
class CNMCharacterLogin64Func : public CNMFunc
{
public:
    CNMCharacterLogin64Func();
    CNMCharacterLogin64Func(const char* sz30, long long n70, int n78);
    virtual ~CNMCharacterLogin64Func() = default;
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    char m_30[0x40]; // +0x30
    long long m_70; // +0x70
    int m_78; // +0x78
    int m_7c; // +0x7c
};
MS2_CHECK_SIZE(CNMCharacterLogin64Func, 0x80);

// vftable 0x142f40cf8, destructor 0x1415ece30.
class CNMCharacterLoginFunc : public CNMFunc
{
public:
    CNMCharacterLoginFunc();
    CNMCharacterLoginFunc(const char* sz30, int n74, int n78);
    virtual ~CNMCharacterLoginFunc() = default;
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    char m_30[0x40]; // +0x30
    int m_70; // +0x70
    int m_74; // +0x74
    int m_78; // +0x78
    int m_7c; // +0x7c
};
MS2_CHECK_SIZE(CNMCharacterLoginFunc, 0x80);

// vftable 0x142f40f70, destructor 0x1415ece50.
class CNMCharacterLogout64Func : public CNMFunc
{
public:
    CNMCharacterLogout64Func();
    CNMCharacterLogout64Func(const char* sz30, long long n70, int n78);
    virtual ~CNMCharacterLogout64Func() = default;
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    char m_30[0x40]; // +0x30
    long long m_70; // +0x70
    int m_78; // +0x78
    int m_7c; // +0x7c
};
MS2_CHECK_SIZE(CNMCharacterLogout64Func, 0x80);

// vftable 0x142f40d60, destructor 0x1415ece70.
class CNMCharacterLogoutFunc : public CNMFunc
{
public:
    CNMCharacterLogoutFunc();
    CNMCharacterLogoutFunc(const char* sz30, int n74, int n78);
    virtual ~CNMCharacterLogoutFunc() = default;
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    char m_30[0x40]; // +0x30
    int m_70; // +0x70
    int m_74; // +0x74
    int m_78; // +0x78
    int m_7c; // +0x7c
};
MS2_CHECK_SIZE(CNMCharacterLogoutFunc, 0x80);

// vftable 0x142f40fe0, destructor 0x1415ece90.
class CNMCharacterRemove64Func : public CNMFunc
{
public:
    CNMCharacterRemove64Func();
    CNMCharacterRemove64Func(const char* sz30, long long n70, int n78);
    virtual ~CNMCharacterRemove64Func() = default;
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    char m_30[0x40]; // +0x30
    long long m_70; // +0x70
    int m_78; // +0x78
    int m_7c; // +0x7c
};
MS2_CHECK_SIZE(CNMCharacterRemove64Func, 0x80);

// vftable 0x142f40dc8, destructor 0x1415eceb0.
class CNMCharacterRemoveFunc : public CNMFunc
{
public:
    CNMCharacterRemoveFunc();
    CNMCharacterRemoveFunc(NMKey64 key, const char* pszName, int n78);
    virtual ~CNMCharacterRemoveFunc() = default;
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    NMKey64 m_30; // +0x30
    char m_38[0x40]; // +0x38
    int m_78; // +0x78
    int m_7c; // +0x7c
};
MS2_CHECK_SIZE(CNMCharacterRemoveFunc, 0x80);

// vftable 0x142f410c0, destructor 0x1415eced0.
class CNMCharacterSync64Func : public CNMFunc
{
public:
    CNMCharacterSync64Func();
    CNMCharacterSync64Func(const char* sz30, long long n70, int n78, int n7c);
    virtual ~CNMCharacterSync64Func() = default;
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    char m_30[0x40]; // +0x30
    long long m_70; // +0x70
    int m_78; // +0x78
    int m_7c; // +0x7c
};
MS2_CHECK_SIZE(CNMCharacterSync64Func, 0x80);

// vftable 0x142f40ea0, destructor 0x1415ecef0.
class CNMCharacterSyncFunc : public CNMFunc
{
public:
    CNMCharacterSyncFunc();
    CNMCharacterSyncFunc(const char* sz30, int n74, int n78, int n7c);
    virtual ~CNMCharacterSyncFunc() = default;
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    char m_30[0x40]; // +0x30
    int m_70; // +0x70
    int m_74; // +0x74
    int m_78; // +0x78
    int m_7c; // +0x7c
};
MS2_CHECK_SIZE(CNMCharacterSyncFunc, 0x80);

// vftable 0x142f3d6d8, destructor 0x1415ecfe0.
class CNMCheckNewsFunc : public CNMFunc
{
public:
    CNMCheckNewsFunc(); // 0x141583b20
    CNMCheckNewsFunc(unsigned result, long long newsKey); // 0x141583b90
    virtual ~CNMCheckNewsFunc() = default;
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    int m_30; // +0x30
    NMKey64 m_34; // +0x34
    int m_3c; // +0x3c
};
MS2_CHECK_SIZE(CNMCheckNewsFunc, 0x40);

// vftable 0x142f3dc30, destructor 0x1415ed020.
class CNMConfirmNewFriendFunc : public CNMFunc
{
public:
    CNMConfirmNewFriendFunc(); // 0x141586f00
    CNMConfirmNewFriendFunc(int result, int flags, int userId); // 0x141586f70
    virtual ~CNMConfirmNewFriendFunc() = default;
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    int m_30; // +0x30
    int m_34; // +0x34
    int m_38; // +0x38
    int m_3c; // +0x3c
};
MS2_CHECK_SIZE(CNMConfirmNewFriendFunc, 0x40);

// vftable 0x142f3ca78, destructor 0x1415ed040.
class CNMConnConfig : public CNMSerializable
{
public:
    CNMConnConfig();
    CNMConnConfig(const char* host, unsigned short port, const char* user, unsigned short mode, unsigned char flags, const char* token, unsigned short channel);
    CNMConnConfig(const CNMConnConfig& r);
    CNMConnConfig& operator=(const CNMConnConfig& r);
    virtual ~CNMConnConfig() = default;
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    char m_10[0x20]; // +0x10
    short m_30; // +0x30
    char m_32[0x20]; // +0x32
    short m_52; // +0x52
    int m_54; // +0x54
    CNMStr<0x20> m_58; // +0x58
    short m_60; // +0x60
};
MS2_CHECK_SIZE(CNMConnConfig, 0x68);

// vftable 0x142f3f9f8, destructor 0x1415ed070.
class CNMCreateChannelFunc : public CNMFunc
{
public:
    CNMCreateChannelFunc(); // 0x14159c0c0
    virtual ~CNMCreateChannelFunc() = default;

    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
};
MS2_CHECK_SIZE(CNMCreateChannelFunc, 0x30);

// vftable 0x142f3c838, destructor 0x1415ee490.
class CNMMessageData : public CNMSerializable
{
public:
    CNMMessageData();
    CNMMessageData(int type, const char* text);
    virtual ~CNMMessageData() = default;

    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    int m_10; // +0x10
    char m_14[0x1004]; // +0x14
};
MS2_CHECK_SIZE(CNMMessageData, 0x1018);

// vftable 0x142f41a18, destructor 0x1415ed110.
class CNMCustomMessageEvent : public CNMEvent
{
public:
    CNMCustomMessageEvent();
    explicit CNMCustomMessageEvent(const CNMMessageData& rMessage);
    virtual ~CNMCustomMessageEvent() = default;
    char* vfunc_8() override { return const_cast<char*>("CNMCustomMessageEvent"); }
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    CNMMessageData m_28; // +0x28
};
MS2_CHECK_SIZE(CNMCustomMessageEvent, 0x1040);

// vftable 0x142f41e28, destructor 0x1415ed160.
class CNMCustomNotifyEvent : public CNMEvent
{
public:
    CNMCustomNotifyEvent();
    CNMCustomNotifyEvent(const CNMCustomNotifyData& rData);
    virtual ~CNMCustomNotifyEvent() = default;
    char* vfunc_8() override { return const_cast<char*>("CNMCustomNotifyEvent"); }

    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    CNMCustomNotifyData m_28; // +0x28
};
MS2_CHECK_SIZE(CNMCustomNotifyEvent, 0x1f8);

// vftable 0x142f3df90, destructor 0x1415ed1e0.
class CNMDeleteCategoryFunc : public CNMFunc
{
public:
    CNMDeleteCategoryFunc(); // 0x1415892b0
    CNMDeleteCategoryFunc(int category, int flag); // 0x141589310
    virtual ~CNMDeleteCategoryFunc() = default;
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    int m_30; // +0x30
    int m_34; // +0x34
};
MS2_CHECK_SIZE(CNMDeleteCategoryFunc, 0x38);

// vftable 0x142f3de48, destructor 0x1415ed200.
class CNMDeleteFriendFromCategoryFunc : public CNMFunc
{
public:
    CNMDeleteFriendFromCategoryFunc(); // 0x141588470
    CNMDeleteFriendFromCategoryFunc(const unsigned char* key, int category, int flag); // 0x141588500
    virtual ~CNMDeleteFriendFromCategoryFunc() = default;
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    NMFriendKey m_key;
    int m_48; // +0x48
    int m_4c; // +0x4c
};
MS2_CHECK_SIZE(CNMDeleteFriendFromCategoryFunc, 0x50);

// vftable 0x142f3cdc0, destructor 0x1415ed220.
class CNMDetachFromNMCOServerFunc : public CNMFunc
{
public:
    CNMDetachFromNMCOServerFunc();
    CNMDetachFromNMCOServerFunc(int id);
    virtual ~CNMDetachFromNMCOServerFunc() = default;
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    int m_30; // +0x30
    int m_34; // +0x34
};
MS2_CHECK_SIZE(CNMDetachFromNMCOServerFunc, 0x38);

// vftable 0x142f3eb58, destructor 0x1415ed2a0.
class CNMExecuteCommonFunc : public CNMFunc
{
public:
    CNMExecuteCommonFunc();
    CNMExecuteCommonFunc(int nCode, const char* argument);
    virtual ~CNMExecuteCommonFunc() = default;
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    int m_30; // +0x30
    char m_34[0x404]; // +0x34
};
MS2_CHECK_SIZE(CNMExecuteCommonFunc, 0x438);

// vftable 0x142f40448, destructor 0x1415ed380.
class CNMFDSControlFunc : public CNMFunc
{
public:
    CNMFDSControlFunc();
    CNMFDSControlFunc(unsigned int serial, int controlType, int controlValue);
    virtual ~CNMFDSControlFunc() = default;

    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    int m_30; // +0x30
    int m_34; // +0x34
};
MS2_CHECK_SIZE(CNMFDSControlFunc, 0x38);

// vftable 0x142f42ef8, destructor 0x1415ed3a0.
class CNMFDSFileDownloadEventReceivedEvent : public CNMEvent
{
public:
    virtual ~CNMFDSFileDownloadEventReceivedEvent() = default;

    int m_28; // +0x28
    int m_2c; // +0x2c
    std::vector<CNMFileEvent> m_30; // +0x30
};
MS2_CHECK_SIZE(CNMFDSFileDownloadEventReceivedEvent, 0x48);

// vftable 0x142f404b0, destructor 0x1415ed3d0.
class CNMFDSGetDownloadDirFunc : public CNMFunc
{
public:
    CNMFDSGetDownloadDirFunc();
    explicit CNMFDSGetDownloadDirFunc(unsigned int serial);
    virtual ~CNMFDSGetDownloadDirFunc() = default;

    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    char m_30[0x108]; // +0x30
};
MS2_CHECK_SIZE(CNMFDSGetDownloadDirFunc, 0x138);

// vftable 0x142f40520, destructor 0x1415ed3f0.
class CNMFDSSetDownloadDirFunc : public CNMFunc
{
public:
    CNMFDSSetDownloadDirFunc();
    CNMFDSSetDownloadDirFunc(unsigned int serial, const char* directory);
    virtual ~CNMFDSSetDownloadDirFunc() = default;

    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    char m_30[0x108]; // +0x30
};
MS2_CHECK_SIZE(CNMFDSSetDownloadDirFunc, 0x138);

// vftable 0x142f40310, destructor 0x1415ed410.
class CNMFUDSGetFileEventFunc : public CNMFunc
{
public:
    CNMFUDSGetFileEventFunc();
    explicit CNMFUDSGetFileEventFunc(unsigned int serial);
    virtual ~CNMFUDSGetFileEventFunc() = default;

    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    std::vector<CNMFileEvent> m_30; // +0x30
};
MS2_CHECK_SIZE(CNMFUDSGetFileEventFunc, 0x48);

// vftable 0x142f403e0, destructor 0x1415ed440.
class CNMFUSControlFunc : public CNMFunc
{
public:
    CNMFUSControlFunc();
    CNMFUSControlFunc(unsigned int serial, int controlType, int controlValue);
    virtual ~CNMFUSControlFunc() = default;

    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    int m_30; // +0x30
    int m_34; // +0x34
};
MS2_CHECK_SIZE(CNMFUSControlFunc, 0x38);

class CNMWSSendWBMessageFunc : public CNMFunc
{
public:
    CNMWSSendWBMessageFunc();
    CNMWSSendWBMessageFunc(unsigned int serial, unsigned int messageType, const unsigned char* data, unsigned int size);
    virtual ~CNMWSSendWBMessageFunc() = default;

    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    unsigned int m_30;
    unsigned int m_34;
    unsigned char m_38[0x8000];
};
MS2_CHECK_SIZE(CNMWSSendWBMessageFunc, 0x8038);

class CNMWSGetAssocSerialKeyFunc : public CNMFunc
{
public:
    CNMWSGetAssocSerialKeyFunc();
    explicit CNMWSGetAssocSerialKeyFunc(unsigned int serial);
    virtual ~CNMWSGetAssocSerialKeyFunc() = default;

    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    unsigned int m_30;
};
MS2_CHECK_SIZE(CNMWSGetAssocSerialKeyFunc, 0x38);

// vftable 0x142f42e68, destructor 0x1415ed460.
class CNMFUSFileUploadEventReceivedEvent : public CNMEvent
{
public:
    virtual ~CNMFUSFileUploadEventReceivedEvent() = default;

    int m_28; // +0x28
    int m_2c; // +0x2c
    std::vector<CNMFileEvent> m_30; // +0x30
};
MS2_CHECK_SIZE(CNMFUSFileUploadEventReceivedEvent, 0x48);

// vftable 0x142f40378, destructor 0x1415ed490.
class CNMFUSSendFileFunc : public CNMFunc
{
public:
    CNMFUSSendFileFunc();
    CNMFUSSendFileFunc(unsigned int serial, const char* path);
    virtual ~CNMFUSSendFileFunc() = default;

    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    char m_30[0x108]; // +0x30
};
MS2_CHECK_SIZE(CNMFUSSendFileFunc, 0x138);

// vftable 0x142f40c98, destructor 0x1415ed4f0.
class CNMFinalizeFunc : public CNMFunc
{
public:
    CNMFinalizeFunc();
    virtual ~CNMFinalizeFunc() = default;
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
};
MS2_CHECK_SIZE(CNMFinalizeFunc, 0x30);

// vftable 0x142f3c490, destructor 0x1415ed590.
class CNMFindUserRequestInfo : public CNMSerializable
{
public:
    CNMFindUserRequestInfo();
    virtual ~CNMFindUserRequestInfo() = default;
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    int m_10; // +0x10
    char m_14[0x20]; // +0x14
    int m_34; // +0x34
    int m_38; // +0x38
    int m_3c; // +0x3c
    int m_40; // +0x40
    int m_44; // +0x44
    int m_48; // +0x48
    int m_4c; // +0x4c
};
MS2_CHECK_SIZE(CNMFindUserRequestInfo, 0x50);

// vftable 0x142f3f2b8, destructor 0x1415ed510.
class CNMFindUserFunc : public CNMFunc
{
public:
    CNMFindUserFunc();
    CNMFindUserFunc(const CNMFindUserRequestInfo& info);
    virtual ~CNMFindUserFunc() = default;
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    CNMFindUserRequestInfo m_30; // +0x30
    int m_80; // +0x80
    int m_84; // +0x84
};
MS2_CHECK_SIZE(CNMFindUserFunc, 0x88);

// vftable 0x142f41b98, destructor 0x1415ed570.
class CNMFindUserReplyEvent : public CNMEvent
{
public:
    CNMFindUserReplyEvent();
    explicit CNMFindUserReplyEvent(int nResult);
    virtual ~CNMFindUserReplyEvent() = default;
    char* vfunc_8() override { return const_cast<char*>("CNMFindUserReplyEvent"); }
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    int m_28; // +0x28
    int m_2c; // +0x2c
};
MS2_CHECK_SIZE(CNMFindUserReplyEvent, 0x30);

// vftable 0x142f42268, destructor 0x1415ed5d0.
class CNMFriendInfoChangedEvent : public CNMEvent
{
public:
    virtual ~CNMFriendInfoChangedEvent() = default;

    CNMFriendInfo m_28; // +0x28
    int m_5a8; // +0x5a8
    int m_5ac; // +0x5ac
    CNMAvatarFullInfo m_5b0; // +0x5b0
};
MS2_CHECK_SIZE(CNMFriendInfoChangedEvent, 0x5c0);

// vftable 0x142f3c058, destructor 0x1415ed610.
class CNMFriendList : public CNMSerializable
{
public:
    CNMFriendList();
    virtual ~CNMFriendList() = default;
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    std::vector<CNMFriendInfo> m_10; // +0x10
};
MS2_CHECK_SIZE(CNMFriendList, 0x28);

// vftable 0x142f40160, destructor 0x1415ed660.
class CNMGSGetInviteCandidateListFunc : public CNMFunc
{
public:
    CNMGSGetInviteCandidateListFunc(); // 0x1415a0960
    explicit CNMGSGetInviteCandidateListFunc(unsigned uSerialKey); // 0x1415a09c0
    virtual ~CNMGSGetInviteCandidateListFunc() = default;

    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    std::vector<CNMFriendInfo> m_30; // +0x30
};
MS2_CHECK_SIZE(CNMGSGetInviteCandidateListFunc, 0x48);

// vftable 0x142f400f8, destructor 0x1415ed690.
class CNMGSGetMemberListFunc : public CNMFunc
{
public:
    CNMGSGetMemberListFunc(); // 0x1415a04e0
    explicit CNMGSGetMemberListFunc(unsigned uSerialKey); // 0x1415a0540
    virtual ~CNMGSGetMemberListFunc() = default;

    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    std::vector<CNMSessionMemberInfo> m_30; // +0x30
};
MS2_CHECK_SIZE(CNMGSGetMemberListFunc, 0x48);

// vftable 0x142f3c5f8, destructor 0x1415eecc0.
class CNMSessionInfo : public CNMSerializable
{
public:
    CNMSessionInfo();
    virtual ~CNMSessionInfo() = default;

    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    int m_10; // +0x10
    NMKey64 m_14; // +0x14
    int m_1c; // +0x1c
    int m_20; // +0x20
    int m_24; // +0x24
    long long m_28; // +0x28
    long long m_30; // +0x30
    int m_38; // +0x38
    int m_3c; // +0x3c
    int m_40; // +0x40
    int m_44; // +0x44
};
MS2_CHECK_SIZE(CNMSessionInfo, 0x48);

// vftable 0x142f40020, destructor 0x1415ed6c0.
class CNMGSGetSessionInfoFunc : public CNMFunc
{
public:
    CNMGSGetSessionInfoFunc();
    explicit CNMGSGetSessionInfoFunc(int nFlags);
    virtual ~CNMGSGetSessionInfoFunc() = default;
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    CNMSessionInfo m_30; // +0x30
    std::vector<CNMSessionMemberInfo> m_78; // +0x78
};
MS2_CHECK_SIZE(CNMGSGetSessionInfoFunc, 0x90);

// vftable 0x142f42cd0, destructor 0x1415ed700.
class CNMGSInviteRejectedEvent : public CNMEvent
{
public:
    virtual ~CNMGSInviteRejectedEvent() = default;

    int m_28; // +0x28
    int m_2c; // +0x2c
    CNMSessionInfo m_30; // +0x30
    char m_78[0x40]; // +0x78
    char m_b8[0x40]; // +0xb8
    int m_f8; // +0xf8
    int m_fc; // +0xfc
};
MS2_CHECK_SIZE(CNMGSInviteRejectedEvent, 0x100);

// vftable 0x142f40238, destructor 0x1415ed730.
class CNMGSInviteUserExFunc : public CNMFunc
{
public:
    CNMGSInviteUserExFunc();
    CNMGSInviteUserExFunc(unsigned int n18, const unsigned char* target);
    virtual ~CNMGSInviteUserExFunc() = default;

    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    unsigned long long m_30; // +0x30
    int m_38; // +0x38
    int m_3c; // +0x3c
    int m_40; // +0x40
    int m_44; // +0x44
};
MS2_CHECK_SIZE(CNMGSInviteUserExFunc, 0x48);

// vftable 0x142f401d0, destructor 0x1415ed750.
class CNMGSInviteUserFunc : public CNMFunc
{
public:
    CNMGSInviteUserFunc();
    CNMGSInviteUserFunc(unsigned int n18, const unsigned char* target);
    virtual ~CNMGSInviteUserFunc() = default;

    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    long long m_30; // +0x30
    int m_38; // +0x38
    int m_3c; // +0x3c
};
MS2_CHECK_SIZE(CNMGSInviteUserFunc, 0x40);

// vftable 0x142f42bc8, destructor 0x1415ed770.
class CNMGSMemberInfoChangedEvent : public CNMEvent
{
public:
    virtual ~CNMGSMemberInfoChangedEvent() = default;

    int m_28; // +0x28
    int m_2c; // +0x2c
    CNMSessionMemberInfo m_30; // +0x30
    CNMSessionMemberInfo m_128; // +0x128
};
MS2_CHECK_SIZE(CNMGSMemberInfoChangedEvent, 0x220);

// vftable 0x142f42b48, destructor 0x1415ed7b0.
class CNMGSMemberLeavedEvent : public CNMEvent
{
public:
    virtual ~CNMGSMemberLeavedEvent() = default;

    int m_28; // +0x28
    int m_2c; // +0x2c
    CNMSessionMemberInfo m_30; // +0x30
};
MS2_CHECK_SIZE(CNMGSMemberLeavedEvent, 0x128);

// vftable 0x142f42ac0, destructor 0x1415ed7e0.
class CNMGSNewMemberJoinedEvent : public CNMEvent
{
public:
    virtual ~CNMGSNewMemberJoinedEvent() = default;

    int m_28; // +0x28
    int m_2c; // +0x2c
    CNMSessionMemberInfo m_30; // +0x30
};
MS2_CHECK_SIZE(CNMGSNewMemberJoinedEvent, 0x128);

// vftable 0x142f3ff48, destructor 0x1415ed810.
class CNMGSRegisterCallbackFunc : public CNMFunc
{
public:
    CNMGSRegisterCallbackFunc(); // 0x14159f5e0
    CNMGSRegisterCallbackFunc(int n18, long long callback, int code); // 0x14159f640
    virtual ~CNMGSRegisterCallbackFunc() = default;
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    long long m_30; // +0x30
    int m_38; // +0x38
};
MS2_CHECK_SIZE(CNMGSRegisterCallbackFunc, 0x40);

// vftable 0x142f429b8, destructor 0x1415ed830.
class CNMGSSessionClosedEvent : public CNMEvent
{
public:
    virtual ~CNMGSSessionClosedEvent() = default;

    int m_28; // +0x28
    int m_2c; // +0x2c
    CNMSessionInfo m_30; // +0x30
};
MS2_CHECK_SIZE(CNMGSSessionClosedEvent, 0x78);

// vftable 0x142f42828, destructor 0x1415ed860.
class CNMGSSessionCreatedEvent : public CNMEvent
{
public:
    virtual ~CNMGSSessionCreatedEvent() = default;
    void vfunc_11(unsigned int) override;

    int m_28; // +0x28
    int m_2c; // +0x2c
    CNMSessionInfo m_30; // +0x30
    std::vector<CNMSessionMemberInfo> m_78; // +0x78
    int m_90; // +0x90
    int m_94; // +0x94
};
MS2_CHECK_SIZE(CNMGSSessionCreatedEvent, 0x98);

// vftable 0x142f428b0, destructor 0x1415ed8a0.
class CNMGSSessionEstablishedEvent : public CNMEvent
{
public:
    virtual ~CNMGSSessionEstablishedEvent() = default;
    void vfunc_11(unsigned int) override;

    int m_28; // +0x28
    int m_2c; // +0x2c
    CNMSessionInfo m_30; // +0x30
    std::vector<CNMSessionMemberInfo> m_78; // +0x78
    int m_90; // +0x90
    int m_94; // +0x94
};
MS2_CHECK_SIZE(CNMGSSessionEstablishedEvent, 0x98);

// vftable 0x142f42938, destructor 0x1415ed8e0.
class CNMGSSessionFailedEvent : public CNMEvent
{
public:
    virtual ~CNMGSSessionFailedEvent() = default;

    int m_28; // +0x28
    int m_2c; // +0x2c
    CNMSessionInfo m_30; // +0x30
};
MS2_CHECK_SIZE(CNMGSSessionFailedEvent, 0x78);

// vftable 0x142f42a38, destructor 0x1415ed910.
class CNMGSSessionInfoChangedEvent : public CNMEvent
{
public:
    virtual ~CNMGSSessionInfoChangedEvent() = default;

    int m_28; // +0x28
    int m_2c; // +0x2c
    CNMSessionInfo m_30; // +0x30
};
MS2_CHECK_SIZE(CNMGSSessionInfoChangedEvent, 0x78);

// vftable 0x142f42c50, destructor 0x1415ed940.
class CNMGSSessionInfoEvent : public CNMEvent
{
public:
    virtual ~CNMGSSessionInfoEvent() = default;
    void vfunc_11(unsigned int) override;

    int m_28; // +0x28
    int m_2c; // +0x2c
    CNMSessionInfo m_30; // +0x30
    std::vector<CNMSessionMemberInfo> m_78; // +0x78
    int m_90; // +0x90
    int m_94; // +0x94
};
MS2_CHECK_SIZE(CNMGSSessionInfoEvent, 0x98);

// vftable 0x142f40088, destructor 0x1415ed980.
class CNMGSSetServingProcessIDFunc : public CNMFunc
{
public:
    CNMGSSetServingProcessIDFunc(); // 0x1415a01a0
    CNMGSSetServingProcessIDFunc(unsigned uSerialKey, unsigned uProcessId); // 0x1415a01f0
    virtual ~CNMGSSetServingProcessIDFunc() = default;

    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    int m_30; // +0x30
    int m_34; // +0x34
};
MS2_CHECK_SIZE(CNMGSSetServingProcessIDFunc, 0x38);

// vftable 0x142f3ffb8, destructor 0x1415ed9a0.
class CNMGSWantCloseFunc : public CNMFunc
{
public:
    CNMGSWantCloseFunc(); // 0x14159f960
    CNMGSWantCloseFunc(int n18, int wantClose); // 0x14159f9c0
    virtual ~CNMGSWantCloseFunc() = default;
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    int m_30; // +0x30
};
MS2_CHECK_SIZE(CNMGSWantCloseFunc, 0x38);

// vftable 0x142f414e8, destructor 0x1415eda30.
class CNMGameLogFinalizeFunc : public CNMFunc
{
public:
    CNMGameLogFinalizeFunc();
    virtual ~CNMGameLogFinalizeFunc() = default;
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
};
MS2_CHECK_SIZE(CNMGameLogFinalizeFunc, 0x30);

// vftable 0x142f41630, destructor 0x1415eda50.
class CNMGameLogGetSessionIDFunc : public CNMFunc
{
public:
    CNMGameLogGetSessionIDFunc();
    virtual ~CNMGameLogGetSessionIDFunc() = default;
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    char m_30[0x20]; // +0x30
};
MS2_CHECK_SIZE(CNMGameLogGetSessionIDFunc, 0x50);

// vftable 0x142f41478, destructor 0x1415eda70.
class CNMGameLogInitializeFunc : public CNMFunc
{
public:
    CNMGameLogInitializeFunc();
    CNMGameLogInitializeFunc(const char* psz30, const char* psz50, const char* psz150);
    virtual ~CNMGameLogInitializeFunc() = default;
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    char m_30[0x20]; // +0x30
    char m_50[0x100]; // +0x50
    char m_150[0x20]; // +0x150
};
MS2_CHECK_SIZE(CNMGameLogInitializeFunc, 0x170);

// vftable 0x142f415c0, destructor 0x1415eda90.
class CNMGameLogWriteErrorLogFunc : public CNMFunc
{
public:
    CNMGameLogWriteErrorLogFunc();
    CNMGameLogWriteErrorLogFunc(int n30, const char* psz34);
    virtual ~CNMGameLogWriteErrorLogFunc() = default;
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    int m_30; // +0x30
    char m_34[0x104]; // +0x34
};
MS2_CHECK_SIZE(CNMGameLogWriteErrorLogFunc, 0x138);

// vftable 0x142f41550, destructor 0x1415edab0.
class CNMGameLogWriteStageLogFunc : public CNMFunc
{
public:
    CNMGameLogWriteStageLogFunc();
    CNMGameLogWriteStageLogFunc(int n30, const char* psz34);
    virtual ~CNMGameLogWriteStageLogFunc() = default;
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    int m_30; // +0x30
    char m_34[0x104]; // +0x34
};
MS2_CHECK_SIZE(CNMGameLogWriteStageLogFunc, 0x138);

// vftable 0x142f3d338, destructor 0x1415edaf0.
class CNMGetConfigFunc : public CNMFunc
{
public:
    CNMGetConfigFunc(); // 0x141581690
    explicit CNMGetConfigFunc(int configMask); // 0x141581730
    virtual ~CNMGetConfigFunc() = default;
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    int m_30; // +0x30
    int m_34; // +0x34
    int m_38; // +0x38
    int m_3c; // +0x3c
    int m_40; // +0x40
    int m_44; // +0x44
    CNMMyGameInfo m_48; // +0x48
};
MS2_CHECK_SIZE(CNMGetConfigFunc, 0x80);

// vftable 0x142f3cf18, destructor 0x1415edb20.
class CNMGetConnConfigFunc : public CNMFunc
{
public:
    CNMGetConnConfigFunc();
    virtual ~CNMGetConnConfigFunc() = default;
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    CNMConnConfig m_30; // +0x30
};
MS2_CHECK_SIZE(CNMGetConnConfigFunc, 0x98);

// vftable 0x142f3d4e0, destructor 0x1415edb50.
class CNMGetCountFunc : public CNMFunc
{
public:
    CNMGetCountFunc(); // 0x141582980
    explicit CNMGetCountFunc(int count); // 0x1415829e0
    virtual ~CNMGetCountFunc() = default;
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    int m_30; // +0x30
    int m_34; // +0x34
};
MS2_CHECK_SIZE(CNMGetCountFunc, 0x38);

// vftable 0x142f3d740, destructor 0x1415edb70.
class CNMGetDomainFunc : public CNMFunc
{
public:
    CNMGetDomainFunc(); // 0x141583ee0
    virtual ~CNMGetDomainFunc() = default;
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    char m_30[0x400]; // +0x30
};
MS2_CHECK_SIZE(CNMGetDomainFunc, 0x430);

// vftable 0x142f3f318, destructor 0x1415edb90.
class CNMGetFindUserResultFunc : public CNMFunc
{
public:
    CNMGetFindUserResultFunc();
    CNMGetFindUserResultFunc(int nResult);
    virtual ~CNMGetFindUserResultFunc() = default;
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    int m_30; // +0x30
    int m_34; // +0x34
    std::vector<CNMFindUserInfo> m_38; // +0x38
};
MS2_CHECK_SIZE(CNMGetFindUserResultFunc, 0x50);

// vftable 0x142f3db60, destructor 0x1415edbc0.
class CNMGetFriendInfoFunc : public CNMFunc
{
public:
    CNMGetFriendInfoFunc(); // 0x1415866f0
    explicit CNMGetFriendInfoFunc(const unsigned char* key); // 0x141586760
    virtual ~CNMGetFriendInfoFunc() = default;
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    unsigned long long m_30; // +0x30
    int m_38; // +0x38
    int m_3c; // +0x3c
    int m_40; // +0x40
    int m_44; // +0x44
    CNMFriendInfo m_48; // +0x48
};
MS2_CHECK_SIZE(CNMGetFriendInfoFunc, 0x5c8);

// vftable 0x142f3daf8, destructor 0x1415edbf0.
class CNMGetFriendListFunc : public CNMFunc
{
public:
    CNMGetFriendListFunc();
    explicit CNMGetFriendListFunc(unsigned long long key);
    virtual ~CNMGetFriendListFunc() = default;

    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    NMKey64 m_30; // +0x30
    std::vector<CNMCateFriendInfo> m_38; // +0x38
    std::vector<CNMFriendInfo> m_50; // +0x50
};
MS2_CHECK_SIZE(CNMGetFriendListFunc, 0x68);

// vftable 0x142f3f180, destructor 0x1415edc70.
class CNMGetGameListFunc : public CNMFunc
{
public:
    CNMGetGameListFunc();
    virtual ~CNMGetGameListFunc() = default;

    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    CNMGameListData m_30; // +0x30
};
MS2_CHECK_SIZE(CNMGetGameListFunc, 0x58);

// vftable 0x142f40a20, destructor 0x1415edd10.
class CNMGetGameTokenFunc : public CNMFunc
{
public:
    CNMGetGameTokenFunc();
    explicit CNMGetGameTokenFunc(const char* token);
    virtual ~CNMGetGameTokenFunc() = default;
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    CNMStr<0x20> m_30; // +0x30
    int m_38; // +0x38
    int m_3c; // +0x3c
};
MS2_CHECK_SIZE(CNMGetGameTokenFunc, 0x40);

// vftable 0x142f3d408, destructor 0x1415edd40.
class CNMGetLocalConfigFunc : public CNMFunc
{
public:
    CNMGetLocalConfigFunc(); // 0x141582220
    explicit CNMGetLocalConfigFunc(unsigned result); // 0x141582290
    virtual ~CNMGetLocalConfigFunc() = default;

    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    int m_30; // +0x30
    char m_34[0x404]; // +0x34
};
MS2_CHECK_SIZE(CNMGetLocalConfigFunc, 0x438);

// vftable 0x142f3e510, destructor 0x1415edd60.
class CNMGetMyGuildListExFunc : public CNMFunc
{
public:
    CNMGetMyGuildListExFunc(); // 0x14158cbf0
    virtual ~CNMGetMyGuildListExFunc() = default;
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    CNMGuildListExInfo m_30; // +0x30
};
MS2_CHECK_SIZE(CNMGetMyGuildListExFunc, 0x58);

// vftable 0x142f3d200, destructor 0x1415edd90.
class CNMGetMyInfoFunc : public CNMFunc
{
public:
    CNMGetMyInfoFunc(); // 0x141580880
    virtual ~CNMGetMyInfoFunc() = default;

    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    CNMRealUserInfo m_30; // +0x30
    long long m_1d8; // +0x1d8
    long long m_1e0; // +0x1e0
    int m_1e8; // +0x1e8
    int m_1ec; // +0x1ec
    char m_1f0[0x1000]; // +0x1f0
};
MS2_CHECK_SIZE(CNMGetMyInfoFunc, 0x11f0);

// vftable 0x142f3d0b8, destructor 0x1415eddc0.
class CNMGetMyVirtualUserListFunc : public CNMFunc
{
public:
    CNMGetMyVirtualUserListFunc(); // 0x14157fbb0
    explicit CNMGetMyVirtualUserListFunc(unsigned result); // 0x14157fc20
    virtual ~CNMGetMyVirtualUserListFunc() = default;

    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    int m_30; // +0x30
    int m_34; // +0x34
    std::vector<CNMVirtualUserInfo> m_38; // +0x38
};
MS2_CHECK_SIZE(CNMGetMyVirtualUserListFunc, 0x50);

// vftable 0x142f3d8e0, destructor 0x1415eddf0.
class CNMGetNexonPassportFunc : public CNMFunc
{
public:
    CNMGetNexonPassportFunc(); // 0x141584d00
    explicit CNMGetNexonPassportFunc(int passport); // 0x141584d70
    virtual ~CNMGetNexonPassportFunc() = default;
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    int m_30; // +0x30
    char m_34[0x1004]; // +0x34
};
MS2_CHECK_SIZE(CNMGetNexonPassportFunc, 0x1038);

// vftable 0x142f3da28, destructor 0x1415ede70.
class CNMGetNxHWIDFunc : public CNMFunc
{
public:
    CNMGetNxHWIDFunc(); // 0x1415856c0
    virtual ~CNMGetNxHWIDFunc() = default;
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    CNMStr<0x40> m_30; // +0x30
};
MS2_CHECK_SIZE(CNMGetNxHWIDFunc, 0x38);

// vftable 0x142f3f050, destructor 0x1415edea0.
class CNMGetPathFunc : public CNMFunc
{
public:
    CNMGetPathFunc();
    CNMGetPathFunc(int nRequest);
    virtual ~CNMGetPathFunc() = default;
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    int m_30; // +0x30
    char m_34[0x104]; // +0x34
};
MS2_CHECK_SIZE(CNMGetPathFunc, 0x138);

// vftable 0x142f3e3c0, destructor 0x1415edec0.
class CNMGetRejectedUserListFunc : public CNMFunc
{
public:
    CNMGetRejectedUserListFunc(); // 0x14158bfa0
    virtual ~CNMGetRejectedUserListFunc() = default;
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    std::vector<CNMRejectedUser> m_30; // +0x30
};
MS2_CHECK_SIZE(CNMGetRejectedUserListFunc, 0x48);

// vftable 0x142f3d948, destructor 0x1415edef0.
class CNMGetSecurityCodeCNFunc : public CNMFunc
{
public:
    CNMGetSecurityCodeCNFunc(); // 0x1415850a0
    virtual ~CNMGetSecurityCodeCNFunc() = default;
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    int m_30; // +0x30
};
MS2_CHECK_SIZE(CNMGetSecurityCodeCNFunc, 0x38);

// vftable 0x142f3d9b8, destructor 0x1415edf10.
class CNMGetSecurityQuestionFunc : public CNMFunc
{
public:
    CNMGetSecurityQuestionFunc(); // 0x141585390
    virtual ~CNMGetSecurityQuestionFunc() = default;
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    CNMStr<0x400> m_30; // +0x30
};
MS2_CHECK_SIZE(CNMGetSecurityQuestionFunc, 0x38);

// vftable 0x142f3ebc0, destructor 0x1415edfe0.
class CNMGetUrlFunc : public CNMFunc
{
public:
    CNMGetUrlFunc(); // 0x141591960
    virtual ~CNMGetUrlFunc() = default;
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    int m_30; // +0x30
    int m_34; // +0x34
    int m_38; // +0x38
    int m_3c; // +0x3c
    char m_40[0x100]; // +0x40
    int m_140; // +0x140
    char m_144[0x100]; // +0x144
    int m_244; // +0x244
    int m_248; // +0x248
    int m_24c; // +0x24c
    char m_250[0x400]; // +0x250
};
MS2_CHECK_SIZE(CNMGetUrlFunc, 0x650);

// vftable 0x142f3f250, destructor 0x1415ee020.
class CNMGetUserInfoFunc : public CNMFunc
{
public:
    CNMGetUserInfoFunc(); // 0x141595d10
    CNMGetUserInfoFunc(const char* userId, int type); // 0x141595d80
    virtual ~CNMGetUserInfoFunc() = default;
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    char m_30[0x40]; // +0x30
    int m_70; // +0x70
};
MS2_CHECK_SIZE(CNMGetUserInfoFunc, 0x78);

// vftable 0x142f41da0, destructor 0x1415ee040.
class CNMGuildChatMessageEvent : public CNMEvent
{
public:
    CNMGuildChatMessageEvent();
    CNMGuildChatMessageEvent(long long n28, long long n30, int n38, CNMChatMessage message);
    virtual ~CNMGuildChatMessageEvent() = default;
    char* vfunc_8() override { return const_cast<char*>("CNMGuildChatMessageEvent"); }

    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    long long m_28; // +0x28
    long long m_30; // +0x30
    int m_38; // +0x38
    int m_3c; // +0x3c
    CNMChatMessage m_40; // +0x40
};
MS2_CHECK_SIZE(CNMGuildChatMessageEvent, 0x6b0);

// vftable 0x142f41d20, destructor 0x1415ee140.
class CNMGuildOnlineInfoEvent : public CNMEvent
{
public:
    CNMGuildOnlineInfoEvent();
    CNMGuildOnlineInfoEvent(const CNMGuildOnlineInfo& rInfo);
    CNMGuildOnlineInfoEvent(const CNMGuildOnlineInfoEx& rInfo);
    virtual ~CNMGuildOnlineInfoEvent() = default;
    char* vfunc_8() override { return const_cast<char*>("CNMGuildOnlineInfoEvent"); }

    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    CNMGuildOnlineInfo m_28; // +0x28
};
MS2_CHECK_SIZE(CNMGuildOnlineInfoEvent, 0x80);

// vftable 0x142f420c8, destructor 0x1415ee1a0.
class CNMGuildOnlineInfoExEvent : public CNMEvent
{
public:
    CNMGuildOnlineInfoExEvent();
    explicit CNMGuildOnlineInfoExEvent(const CNMGuildOnlineInfoEx& rInfo);
    virtual ~CNMGuildOnlineInfoExEvent() = default;
    char* vfunc_8() override { return const_cast<char*>("CNMGuildOnlineInfoExEvent"); }

    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    CNMGuildOnlineInfoEx m_28; // +0x28
};
MS2_CHECK_SIZE(CNMGuildOnlineInfoExEvent, 0x90);

// vftable 0x142f40c30, destructor 0x1415ee1d0.
class CNMInitializeFunc : public CNMFunc
{
public:
    CNMInitializeFunc();
    CNMInitializeFunc(int n30, int n34);
    virtual ~CNMInitializeFunc() = default;
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    int m_30; // +0x30
    int m_34; // +0x34
};
MS2_CHECK_SIZE(CNMInitializeFunc, 0x38);

// vftable 0x142f3fa60, destructor 0x1415ee230.
class CNMJoinChannelFunc : public CNMFunc
{
public:
    CNMJoinChannelFunc();
    virtual ~CNMJoinChannelFunc() = default;
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    int m_30; // +0x30
    int m_34; // +0x34
    CNMStr<0x400> m_38; // +0x38
    CNMStr<0x100> m_40; // +0x40
    short m_48; // +0x48
    unsigned char m_4a[0x6]; // +0x4a
    CNMClientChannelInfo m_50; // +0x50
    CNMChannelMemberInfo m_b0; // +0xb0
    int m_e0; // +0xe0
    int m_e4; // +0xe4
    int m_e8; // +0xe8
    int m_ec; // +0xec
};
MS2_CHECK_SIZE(CNMJoinChannelFunc, 0xf0);

// vftable 0x142f43538, destructor 0x1415ee310.
class CNMLogReportSyncEvent : public CNMEvent
{
public:
    virtual ~CNMLogReportSyncEvent() = default;

    short m_28; // +0x28
    unsigned char m_2a[0x6]; // +0x2a
};
MS2_CHECK_SIZE(CNMLogReportSyncEvent, 0x30);

// vftable 0x142f3ea20, destructor 0x1415ee330.
class CNMLogReportSyncFunc : public CNMFunc
{
public:
    CNMLogReportSyncFunc();
    explicit CNMLogReportSyncFunc(short nCode);
    virtual ~CNMLogReportSyncFunc() = default;
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    short m_30; // +0x30
    unsigned char m_32[0x6]; // +0x32
};
MS2_CHECK_SIZE(CNMLogReportSyncFunc, 0x38);

// vftable 0x142f409b8, destructor 0x1415ee370.
class CNMLoginAuthSecurityCNFunc : public CNMFunc
{
public:
    CNMLoginAuthSecurityCNFunc();
    CNMLoginAuthSecurityCNFunc(const char* account, const char* password);
    virtual ~CNMLoginAuthSecurityCNFunc() = default;
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    CNMStr<0x1000> m_30; // +0x30
    CNMStr<0x400> m_38; // +0x38
    int m_40; // +0x40
    int m_44; // +0x44
};
MS2_CHECK_SIZE(CNMLoginAuthSecurityCNFunc, 0x48);

// vftable 0x142f40880, destructor 0x1415ee3b0.
class CNMLoginMessengerFunc : public CNMFunc
{
public:
    CNMLoginMessengerFunc();
    explicit CNMLoginMessengerFunc(int value);
    virtual ~CNMLoginMessengerFunc() = default;
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    int m_30; // +0x30
    int m_34; // +0x34
};
MS2_CHECK_SIZE(CNMLoginMessengerFunc, 0x38);

// vftable 0x142f3cfe8, destructor 0x1415ee410.
class CNMLoginVirtualFunc : public CNMFunc
{
public:
    CNMLoginVirtualFunc(); // 0x14157f390
    CNMLoginVirtualFunc(long long login, int value, long long password); // 0x14157f420
    virtual ~CNMLoginVirtualFunc() = default;
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    char m_30[0x40]; // +0x30
    int m_70; // +0x70
    int m_74; // +0x74
    char m_78[0x40]; // +0x78
};
MS2_CHECK_SIZE(CNMLoginVirtualFunc, 0xb8);

// vftable 0x142f40a88, destructor 0x1415ee430.
class CNMLogoutAuthFunc : public CNMFunc
{
public:
    CNMLogoutAuthFunc();
    CNMLogoutAuthFunc(unsigned char flag, unsigned int value);
    virtual ~CNMLogoutAuthFunc() = default;
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    int m_30; // +0x30
    int m_34; // +0x34
};
MS2_CHECK_SIZE(CNMLogoutAuthFunc, 0x38);

// vftable 0x142f408e8, destructor 0x1415ee450.
class CNMLogoutMessengerFunc : public CNMFunc
{
public:
    CNMLogoutMessengerFunc();
    virtual ~CNMLogoutMessengerFunc() = default;
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
};
MS2_CHECK_SIZE(CNMLogoutMessengerFunc, 0x30);

// vftable 0x142f3d050, destructor 0x1415ee470.
class CNMLogoutVirtualFunc : public CNMFunc
{
public:
    CNMLogoutVirtualFunc(); // 0x14157f840
    explicit CNMLogoutVirtualFunc(long long value); // 0x14157f8a0
    virtual ~CNMLogoutVirtualFunc() = default;
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    int m_30; // +0x30
    int m_34; // +0x34
};
MS2_CHECK_SIZE(CNMLogoutVirtualFunc, 0x38);

// vftable 0x142f41718, destructor 0x1415ee4b0.
class CNMMessengerReplyEvent : public CNMEvent
{
public:
    CNMMessengerReplyEvent();
    explicit CNMMessengerReplyEvent(int nReply);
    virtual ~CNMMessengerReplyEvent() = default;
    unsigned int vfunc_9() override { return static_cast<unsigned int>(m_28); }
    char* vfunc_8() override { return const_cast<char*>("CNMMessengerReplyEvent"); }
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    int m_28; // +0x28
    int m_2c; // +0x2c
};
MS2_CHECK_SIZE(CNMMessengerReplyEvent, 0x30);

// vftable 0x142f3e9b8, destructor 0x1415ee4d0.
class CNMMinimizeAllFunc : public CNMFunc
{
public:
    CNMMinimizeAllFunc();
    explicit CNMMinimizeAllFunc(int bMinimize);
    virtual ~CNMMinimizeAllFunc() = default;
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    int m_30; // +0x30
    int m_34; // +0x34
};
MS2_CHECK_SIZE(CNMMinimizeAllFunc, 0x38);

// vftable 0x142f3e5e8, destructor 0x1415ee4f0.
class CNMMonitorGuildOnlineInfoExFunc : public CNMFunc
{
public:
    CNMMonitorGuildOnlineInfoExFunc(); // 0x14158d360
    CNMMonitorGuildOnlineInfoExFunc(unsigned __int64 guildId, int type); // 0x14158d3f0
    CNMMonitorGuildOnlineInfoExFunc(unsigned __int64 guildId, int type, int status); // 0x14158d480
    CNMMonitorGuildOnlineInfoExFunc(unsigned __int64 guildId, int type, int status, int flags, int result); // 0x14158d520
    virtual ~CNMMonitorGuildOnlineInfoExFunc() = default;
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    long long m_30; // +0x30
    int m_38; // +0x38
    int m_3c; // +0x3c
    int m_40; // +0x40
    int m_44; // +0x44
};
MS2_CHECK_SIZE(CNMMonitorGuildOnlineInfoExFunc, 0x48);

// vftable 0x142f3e578, destructor 0x1415ee510.
class CNMMonitorGuildOnlineInfoFunc : public CNMFunc
{
public:
    CNMMonitorGuildOnlineInfoFunc(); // 0x14158cf10
    CNMMonitorGuildOnlineInfoFunc(int type, int enabled); // 0x14158cf80
    CNMMonitorGuildOnlineInfoFunc(int type, int enabled, int status); // 0x14158d000
    virtual ~CNMMonitorGuildOnlineInfoFunc() = default;
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    int m_30; // +0x30
    int m_34; // +0x34
    int m_38; // +0x38
    int m_3c; // +0x3c
};
MS2_CHECK_SIZE(CNMMonitorGuildOnlineInfoFunc, 0x40);

// vftable 0x142f3deb8, destructor 0x1415ee530.
class CNMMoveFriendCategoryFunc : public CNMFunc
{
public:
    CNMMoveFriendCategoryFunc(); // 0x141588920
    CNMMoveFriendCategoryFunc(const unsigned char* key, int source, int destination, int flag); // 0x1415889c0
    virtual ~CNMMoveFriendCategoryFunc() = default;
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    NMFriendKey m_key;
    int m_48; // +0x48
    int m_4c; // +0x4c
    int m_50; // +0x50
    int m_54; // +0x54
};
MS2_CHECK_SIZE(CNMMoveFriendCategoryFunc, 0x58);

// vftable 0x142f41798, destructor 0x1415ee550.
class CNMMsgConnectionClosedEvent : public CNMEvent
{
public:
    CNMMsgConnectionClosedEvent();
    explicit CNMMsgConnectionClosedEvent(int nReason);
    virtual ~CNMMsgConnectionClosedEvent() = default;
    char* vfunc_8() override { return const_cast<char*>("CNMMsgConnectionClosedEvent"); }
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    int m_28; // +0x28
    int m_2c; // +0x2c
};
MS2_CHECK_SIZE(CNMMsgConnectionClosedEvent, 0x30);

// vftable 0x142f41f30, destructor 0x1415ee600.
class CNMNoteInfoEvent : public CNMEvent
{
public:
    CNMNoteInfoEvent();
    CNMNoteInfoEvent(const CNMNoteInfo2& rNoteInfo);
    virtual ~CNMNoteInfoEvent() = default;
    char* vfunc_8() override { return const_cast<char*>("CNMNoteInfoEvent"); }

    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    CNMNoteInfo2 m_28; // +0x28
};
MS2_CHECK_SIZE(CNMNoteInfoEvent, 0xb10);

// vftable 0x142f41a98, destructor 0x1415ee650.
class CNMNoteInstantMsgEvent : public CNMEvent
{
public:
    CNMNoteInstantMsgEvent();
    explicit CNMNoteInstantMsgEvent(const CNMNoteInfo& rNote);
    explicit CNMNoteInstantMsgEvent(CNMNoteInfo note);
    virtual ~CNMNoteInstantMsgEvent() = default;
    char* vfunc_8() override { return const_cast<char*>("CNMNoteInstantMsgEvent"); }
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    CNMNoteInfo m_28; // +0x28
};
MS2_CHECK_SIZE(CNMNoteInstantMsgEvent, 0xef0);

// vftable 0x142f3f1e8, destructor 0x1415ee6a0.
class CNMOpenGameSummaryFunc : public CNMFunc
{
public:
    CNMOpenGameSummaryFunc();
    virtual ~CNMOpenGameSummaryFunc() = default;
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
};
MS2_CHECK_SIZE(CNMOpenGameSummaryFunc, 0x30);

// vftable 0x142f40af0, destructor 0x1415ee6c0.
class CNMPCBangLoginFunc : public CNMFunc
{
public:
    CNMPCBangLoginFunc();
    explicit CNMPCBangLoginFunc(const char* token);
    virtual ~CNMPCBangLoginFunc();
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    unsigned char m_30[0x8]; // +0x30
    int m_38; // +0x38
    int m_3c; // +0x3c
};
MS2_CHECK_SIZE(CNMPCBangLoginFunc, 0x40);

// vftable 0x142f3e288, destructor 0x1415ee6f0.
class CNMProcessNoteFunc : public CNMFunc
{
public:
    CNMProcessNoteFunc(); // 0x14158b290
    CNMProcessNoteFunc(int noteType, int noteId); // 0x14158b2f0
    virtual ~CNMProcessNoteFunc() = default;
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    int m_30; // +0x30
    int m_34; // +0x34
};
MS2_CHECK_SIZE(CNMProcessNoteFunc, 0x38);

// vftable 0x142f42150, destructor 0x1415ee740.
class CNMRealFriendInfoChangedEvent : public CNMEvent
{
public:
    CNMRealFriendInfoChangedEvent();
    CNMRealFriendInfoChangedEvent(int reason, const CNMRealFriendInfo& rInfo);
    virtual ~CNMRealFriendInfoChangedEvent() = default;
    char* vfunc_8() override { return const_cast<char*>("CNMRealFriendInfoChangedEvent"); }

    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    int m_28; // +0x28
    int m_2c; // +0x2c
    CNMRealFriendInfo m_30; // +0x30
    int m_108; // +0x108
    int m_10c; // +0x10c
    CNMAvatarFullInfo m_110; // +0x110
};
MS2_CHECK_SIZE(CNMRealFriendInfoChangedEvent, 0x120);

// vftable 0x142f41820, destructor 0x1415ee7b0.
class CNMRefreshEvent : public CNMEvent
{
public:
    CNMRefreshEvent(); // 0x1415b2740
    explicit CNMRefreshEvent(int value); // 0x1415b27a0
    virtual ~CNMRefreshEvent() = default;
    char* vfunc_8() override { return const_cast<char*>("CNMRefreshEvent"); }
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    int m_28; // +0x28
};
MS2_CHECK_SIZE(CNMRefreshEvent, 0x30);

// vftable 0x142f41b18, destructor 0x1415ee7d0.
class CNMRefreshMessageEvent : public CNMEvent
{
public:
    CNMRefreshMessageEvent();
    explicit CNMRefreshMessageEvent(int nMessage);
    virtual ~CNMRefreshMessageEvent() = default;
    char* vfunc_8() override { return const_cast<char*>("CNMRefreshMessageEvent"); }
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    int m_28; // +0x28
    int m_2c; // +0x2c
};
MS2_CHECK_SIZE(CNMRefreshMessageEvent, 0x30);

// vftable 0x142f3cc80, destructor 0x1415ee7f0.
class CNMRegisterCallbackFunc : public CNMFunc
{
public:
    CNMRegisterCallbackFunc();
    CNMRegisterCallbackFunc(const void* pCallback, int nFlags);
    virtual ~CNMRegisterCallbackFunc() = default;
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    long long m_30; // +0x30
    int m_38; // +0x38
    int m_3c; // +0x3c
};
MS2_CHECK_SIZE(CNMRegisterCallbackFunc, 0x40);

// vftable 0x142f41ea8, destructor 0x1415ee840.
class CNMRejectedUserListChangedEvent : public CNMEvent
{
public:
    CNMRejectedUserListChangedEvent();
    virtual ~CNMRejectedUserListChangedEvent() = default;
    char* vfunc_8() override { return const_cast<char*>("CNMRejectedUserListChangedEvent"); }

    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
};
MS2_CHECK_SIZE(CNMRejectedUserListChangedEvent, 0x28);

// vftable 0x142f40738, destructor 0x1415ee860.
class CNMRemoveMyVirtualUserFunc : public CNMFunc
{
public:
    CNMRemoveMyVirtualUserFunc();
    explicit CNMRemoveMyVirtualUserFunc(const NMKey64* key);
    virtual ~CNMRemoveMyVirtualUserFunc() = default;

    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    NMKey64 m_30; // +0x30
};
MS2_CHECK_SIZE(CNMRemoveMyVirtualUserFunc, 0x38);

// vftable 0x142f3e4a0, destructor 0x1415ee880.
class CNMRemoveRejectedUserFunc : public CNMFunc
{
public:
    CNMRemoveRejectedUserFunc(); // 0x14158c760
    CNMRemoveRejectedUserFunc(const CNMRejectedUser* user); // 0x14158c7d0
    virtual ~CNMRemoveRejectedUserFunc() = default;
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    CNMRejectedUser m_30; // +0x30
};
MS2_CHECK_SIZE(CNMRemoveRejectedUserFunc, 0xf8);

// vftable 0x142f3f778, destructor 0x1415ee8b0.
class CNMReplySessionRequestFunc : public CNMFunc
{
public:
    CNMReplySessionRequestFunc(); // 0x141599ab0
    CNMReplySessionRequestFunc(unsigned __int64 nSession, int bReply); // 0x141599b20
    virtual ~CNMReplySessionRequestFunc() = default;

    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override; // 0x141599c60
    unsigned int EncodeFramed(CNMStream* pStream) override;                 // 0x141599ba0
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override; // 0x141599c00
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override; // 0x141599de0
    unsigned int DecodeFramed(CNMStream* pStream) override;                 // 0x141599cf0
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override; // 0x141599d80

    long long m_30; // +0x30
    int m_38; // +0x38
    int m_3c; // +0x3c
};
MS2_CHECK_SIZE(CNMReplySessionRequestFunc, 0x40);

// vftable 0x142f3f5a8, destructor 0x1415ee8f0.
class CNMRequestChatSessionExFunc : public CNMFunc
{
public:
    CNMRequestChatSessionExFunc(); // 0x141598330
    CNMRequestChatSessionExFunc(const unsigned char* pTarget, int nTarget); // 0x1415983d0
    virtual ~CNMRequestChatSessionExFunc() = default;

    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override; // 0x141598520
    unsigned int EncodeFramed(CNMStream* pStream) override;                 // 0x141598460
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override; // 0x1415984c0
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override; // 0x141598700
    unsigned int DecodeFramed(CNMStream* pStream) override;                 // 0x141598610
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override; // 0x1415986a0

    unsigned long long m_30; // +0x30
    int m_38; // +0x38
    int m_3c; // +0x3c
    int m_40; // +0x40
    int m_44; // +0x44
    int m_48; // +0x48
    int m_4c; // +0x4c
    int m_50; // +0x50
    int m_54; // +0x54
};
MS2_CHECK_SIZE(CNMRequestChatSessionExFunc, 0x58);

// vftable 0x142f3f3f0, destructor 0x1415ee910.
class CNMRequestChatSessionFunc : public CNMFunc
{
public:
    CNMRequestChatSessionFunc();                         // 0x141596d50
    CNMRequestChatSessionFunc(const unsigned char* pTarget, int nTarget); // 0x141596de0
    virtual ~CNMRequestChatSessionFunc() = default;

    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override; // 0x141596f30
    unsigned int EncodeFramed(CNMStream* pStream) override;                 // 0x141596e70
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override; // 0x141596ed0
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override; // 0x1415970f0
    unsigned int DecodeFramed(CNMStream* pStream) override;                 // 0x141597000
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override; // 0x141597090

    long long m_30; // +0x30
    int m_38; // +0x38
    int m_3c; // +0x3c
    int m_40; // +0x40
    int m_44; // +0x44
    int m_48; // +0x48
    int m_4c; // +0x4c
};
MS2_CHECK_SIZE(CNMRequestChatSessionFunc, 0x50);

// vftable 0x142f3c880, destructor 0x1415ee9f0.
class CNMRequestNewFriendData : public CNMSerializable
{
public:
    CNMRequestNewFriendData();
    virtual ~CNMRequestNewFriendData() = default;

    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    int m_10; // +0x10
    char m_14[0x40]; // +0x14
    int m_54; // +0x54
    int m_58; // +0x58
    int m_5c; // +0x5c
    char m_60[0x40]; // +0x60
    int m_a0; // +0xa0
    int m_a4; // +0xa4
    char m_a8[0x40]; // +0xa8
    int m_e8; // +0xe8
    char m_ec[0x100]; // +0xec
    int m_1ec; // +0x1ec
};
MS2_CHECK_SIZE(CNMRequestNewFriendData, 0x1f0);

// vftable 0x142f41910, destructor 0x1415eea10.
class CNMRequestNewFriendEvent : public CNMEvent
{
public:
    CNMRequestNewFriendEvent(); // 0x1415b2e20
    explicit CNMRequestNewFriendEvent(const CNMRequestNewFriendData& data); // 0x1415b2e90
    virtual ~CNMRequestNewFriendEvent() = default;
    char* vfunc_8() override { return const_cast<char*>("CNMRequestNewFriendEvent"); }
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    CNMRequestNewFriendData m_28; // +0x28
};
MS2_CHECK_SIZE(CNMRequestNewFriendEvent, 0x218);

// vftable 0x142f3dbc8, destructor 0x1415eea40.
class CNMRequestNewFriendFunc : public CNMFunc
{
public:
    CNMRequestNewFriendFunc(); // 0x141586b60
    explicit CNMRequestNewFriendFunc(const CNMRequestNewFriendData& data); // 0x141586bd0
    virtual ~CNMRequestNewFriendFunc() = default;
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    CNMRequestNewFriendData m_30; // +0x30
};
MS2_CHECK_SIZE(CNMRequestNewFriendFunc, 0x220);

// vftable 0x142f3d670, destructor 0x1415eea70.
class CNMRequestNewsFunc : public CNMFunc
{
public:
    CNMRequestNewsFunc(); // 0x141583880
    virtual ~CNMRequestNewsFunc() = default;
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
};
MS2_CHECK_SIZE(CNMRequestNewsFunc, 0x30);

// vftable 0x142f3c8c8, destructor 0x1415eea90.
class CNMRequestSessionData : public CNMSerializable
{
public:
    CNMRequestSessionData();
    virtual ~CNMRequestSessionData() = default;

    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    int m_10; // +0x10
    int m_14; // +0x14
    char m_18[0x40]; // +0x18
    char m_58[0x40]; // +0x58
};
MS2_CHECK_SIZE(CNMRequestSessionData, 0x98);

// vftable 0x142f3f708, destructor 0x1415eeae0.
class CNMRequestWBSessionExFunc : public CNMFunc
{
public:
    CNMRequestWBSessionExFunc(); // 0x141599560
    CNMRequestWBSessionExFunc(const unsigned char* pTarget, int n48, int n4c); // 0x141599610
    virtual ~CNMRequestWBSessionExFunc() = default;

    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override; // 0x141599770
    unsigned int EncodeFramed(CNMStream* pStream) override;                 // 0x1415996b0
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override; // 0x141599710
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override; // 0x141599970
    unsigned int DecodeFramed(CNMStream* pStream) override;                 // 0x141599880
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override; // 0x141599910

    unsigned long long m_30; // +0x30
    int m_38; // +0x38
    int m_3c; // +0x3c
    int m_40; // +0x40
    int m_44; // +0x44
    int m_48; // +0x48
    int m_4c; // +0x4c
    int m_50; // +0x50
    int m_54; // +0x54
};
MS2_CHECK_SIZE(CNMRequestWBSessionExFunc, 0x58);

// vftable 0x142f3f540, destructor 0x1415eeb00.
class CNMRequestWBSessionFunc : public CNMFunc
{
public:
    CNMRequestWBSessionFunc(); // 0x141597e50
    CNMRequestWBSessionFunc(const unsigned char* pTarget, int n40, int n44); // 0x141597ef0
    virtual ~CNMRequestWBSessionFunc() = default;

    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override; // 0x141598050
    unsigned int EncodeFramed(CNMStream* pStream) override;                 // 0x141597f90
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override; // 0x141597ff0
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override; // 0x141598220
    unsigned int DecodeFramed(CNMStream* pStream) override;                 // 0x141598130
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override; // 0x1415981c0

    long long m_30; // +0x30
    int m_38; // +0x38
    int m_3c; // +0x3c
    int m_40; // +0x40
    int m_44; // +0x44
    int m_48; // +0x48
    int m_4c; // +0x4c
};
MS2_CHECK_SIZE(CNMRequestWBSessionFunc, 0x50);

// vftable 0x142f3cce8, destructor 0x1415eeb20.
class CNMResetCallbackFunc : public CNMFunc
{
public:
    CNMResetCallbackFunc();
    explicit CNMResetCallbackFunc(unsigned long long callback);
    virtual ~CNMResetCallbackFunc() = default;
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    long long m_30; // +0x30
};
MS2_CHECK_SIZE(CNMResetCallbackFunc, 0x38);

// vftable 0x142f3e950, destructor 0x1415eeb40.
class CNMRestrictedWordsFunc : public CNMFunc
{
public:
    CNMRestrictedWordsFunc();
    CNMRestrictedWordsFunc(int nMode, int nCategory, const char* szWords);
    virtual ~CNMRestrictedWordsFunc() = default;
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    int m_30; // +0x30
    int m_34; // +0x34
    CNMStr<0x400> m_38; // +0x38
    int m_40; // +0x40
    int m_44; // +0x44
};
MS2_CHECK_SIZE(CNMRestrictedWordsFunc, 0x48);

// vftable 0x142f3d190, destructor 0x1415eec50.
class CNMSendRefreshMessageFunc : public CNMFunc
{
public:
    CNMSendRefreshMessageFunc(); // 0x141580530
    explicit CNMSendRefreshMessageFunc(unsigned result); // 0x141580590
    virtual ~CNMSendRefreshMessageFunc() = default;

    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    int m_30; // +0x30
    int m_34; // +0x34
};
MS2_CHECK_SIZE(CNMSendRefreshMessageFunc, 0x38);

// vftable 0x142f41998, destructor 0x1415eec90.
class CNMServerMessageEvent : public CNMEvent
{
public:
    CNMServerMessageEvent(); // 0x1415b31a0
    explicit CNMServerMessageEvent(const CNMMessageData& data); // 0x1415b3210
    virtual ~CNMServerMessageEvent() = default;
    char* vfunc_8() override { return const_cast<char*>("CNMServerMessageEvent"); }
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    CNMMessageData m_28; // +0x28
};
MS2_CHECK_SIZE(CNMServerMessageEvent, 0x1040);

// vftable 0x142f3c688, destructor 0x1415eed10.
class CNMSessionMemberList : public CNMSerializable
{
public:
    CNMSessionMemberList();
    virtual ~CNMSessionMemberList() = default;

    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    std::vector<CNMSessionMemberInfo> m_10; // +0x10
};
MS2_CHECK_SIZE(CNMSessionMemberList, 0x28);

// vftable 0x142f40bc0, destructor 0x1415eed40.
class CNMSetAuthClosedCallbackFunc : public CNMFunc
{
public:
    CNMSetAuthClosedCallbackFunc();
    explicit CNMSetAuthClosedCallbackFunc(long long callback);
    virtual ~CNMSetAuthClosedCallbackFunc() = default;
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    long long m_30; // +0x30
};
MS2_CHECK_SIZE(CNMSetAuthClosedCallbackFunc, 0x38);

// vftable 0x142f3d878, destructor 0x1415eed60.
class CNMSetCodePageFunc : public CNMFunc
{
public:
    CNMSetCodePageFunc(); // 0x1415849b0
    explicit CNMSetCodePageFunc(int codePage); // 0x141584a10
    virtual ~CNMSetCodePageFunc() = default;
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    int m_30; // +0x30
    int m_34; // +0x34
};
MS2_CHECK_SIZE(CNMSetCodePageFunc, 0x38);

// vftable 0x142f3cf80, destructor 0x1415eed80.
class CNMSetConnConfigFunc : public CNMFunc
{
public:
    CNMSetConnConfigFunc();
    explicit CNMSetConnConfigFunc(const CNMConnConfig& config);
    virtual ~CNMSetConnConfigFunc() = default;
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    CNMConnConfig m_30; // +0x30
};
MS2_CHECK_SIZE(CNMSetConnConfigFunc, 0x98);

// vftable 0x142f3d540, destructor 0x1415eedb0.
class CNMSetCountFunc : public CNMFunc
{
public:
    CNMSetCountFunc(); // 0x141582d00
    CNMSetCountFunc(unsigned first, unsigned second); // 0x141582d60
    virtual ~CNMSetCountFunc() = default;

    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    int m_30; // +0x30
    int m_34; // +0x34
};
MS2_CHECK_SIZE(CNMSetCountFunc, 0x38);

// vftable 0x142f3d810, destructor 0x1415eedd0.
class CNMSetLocaleFunc : public CNMFunc
{
public:
    CNMSetLocaleFunc(); // 0x141584630
    CNMSetLocaleFunc(int locale, int sublocale); // 0x141584690
    virtual ~CNMSetLocaleFunc() = default;
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    int m_30; // +0x30
    int m_34; // +0x34
};
MS2_CHECK_SIZE(CNMSetLocaleFunc, 0x38);

// vftable 0x142f3d7a8, destructor 0x1415eee40.
class CNMSetStatInfoFunc : public CNMFunc
{
public:
    CNMSetStatInfoFunc(); // 0x1415841e0
    CNMSetStatInfoFunc(int a, int b, int c, int d, int e); // 0x141584270
    virtual ~CNMSetStatInfoFunc() = default;
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    int m_30; // +0x30
    int m_34; // +0x34
    int m_38; // +0x38
    int m_3c; // +0x3c
    int m_40; // +0x40
    int m_44; // +0x44
};
MS2_CHECK_SIZE(CNMSetStatInfoFunc, 0x48);

// vftable 0x142f41898, destructor 0x1415eee60.
class CNMSpecialEvent : public CNMEvent
{
public:
    CNMSpecialEvent();
    CNMSpecialEvent(int nType, const char* text);
    virtual ~CNMSpecialEvent() = default;
    char* vfunc_8() override { return const_cast<char*>("CNMSpecialEvent"); }
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    int m_28; // +0x28
    char m_2c[0x104]; // +0x2c
};
MS2_CHECK_SIZE(CNMSpecialEvent, 0x130);

// vftable 0x142f3cea8, destructor 0x1415eee80.
class CNMStartStandAloneMsgFunc : public CNMFunc
{
public:
    CNMStartStandAloneMsgFunc();
    explicit CNMStartStandAloneMsgFunc(const char* message);
    virtual ~CNMStartStandAloneMsgFunc() = default;
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    char m_30[0x400]; // +0x30
};
MS2_CHECK_SIZE(CNMStartStandAloneMsgFunc, 0x430);

// vftable 0x142f40b58, destructor 0x1415eeea0.
class CNMTPATokenLoginFunc : public CNMFunc
{
public:
    CNMTPATokenLoginFunc();
    CNMTPATokenLoginFunc(const char* account, const char* password);
    virtual ~CNMTPATokenLoginFunc();
    unsigned int Encode(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int EncodeFramed(CNMStream* pStream) override;
    unsigned int EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream) override;
    unsigned int Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;
    unsigned int DecodeFramed(CNMStream* pStream) override;
    unsigned int DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream) override;

    unsigned char m_30[0x8]; // +0x30
    CNMStr<0x40> m_38; // +0x38
    int m_40; // +0x40
    int m_44; // +0x44
};
MS2_CHECK_SIZE(CNMTPATokenLoginFunc, 0x48);

// vftable 0x142f41ca0, destructor 0x1415eef00.
class CNMUserInfoEvent : public CNMEvent
{
public:
    virtual ~CNMUserInfoEvent() = default;

    CNMRealUserInfo m_28; // +0x28
};
MS2_CHECK_SIZE(CNMUserInfoEvent, 0x1d0);
