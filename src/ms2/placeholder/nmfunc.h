// nmfunc.h - Nexon Messenger (NM) client library request objects ("CNM...Func"). NOT an original Nexon header.
// The game links the NM client library statically (0x141569a00-0x14160bd70). A request is a CNMFunc-derived
// object built on the stack, handed to CNMManager::CallNMFunc and read back (the reply members) before its
// destructor runs. Class names are RTTI names; member names are invented unless noted. Layouts are from the
// classes' constructors and from the wrappers in unit_1415c30d0 (frame sizes = sizeof), cross-checked against the
// third-party v2525 snapshot. Constructors/destructors live in the library's other units and are only declared.
#pragma once

#include <vector>
#include "ms2/ms2layout.h"

class CNMSerializable
{
public:
    virtual ~CNMSerializable();                                 // 0x1415eec70

    unsigned short m_wSignature;                                // +0x08
    unsigned char m_bKind;                                      // +0x0a
    unsigned char m_bFormat;                                    // +0x0b
    unsigned char m_bFlag;                                      // +0x0c
};
MS2_CHECK_SIZE(CNMSerializable, 0x10);

class CNMFunc : public CNMSerializable
{
public:
    virtual ~CNMFunc();                                         // 0x1415ed640

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

// The library's singleton dispatcher (RTTI CNMManager). Only the two calls the request wrappers make.
class CNMManager
{
public:
    static CNMManager* GetInstance();                           // 0x1415fa260
    int CallNMFunc(CNMFunc* pFunc);                             // 0x1415cb440 (TRUE when the reply arrived)
};

// ---- list elements (std::vector<T> members of the list requests/events) -------------------------------------------
// The records are CNMSerializable-derived (RTTI names, sizes from their copy constructors and the vector code in
// unit_1415cf3e0). Only what the vector templates use is declared: the copy constructor, operator= and the virtual
// destructor; bodies not recovered yet are an opaque m_body. Some derive through intermediate bases in the exe
// (noted per class); those add no data the templates touch.

// CNMRequestMultiChatSessionFunc target (0x10, trivially copyable; name invented).
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

class CNMAvatarItemInfo : public CNMSerializable
{
public:
    virtual ~CNMAvatarItemInfo();
};
MS2_CHECK_SIZE(CNMAvatarItemInfo, 0x10);

class CNMCateFriendInfo : public CNMSerializable
{
public:
    CNMCateFriendInfo(const CNMCateFriendInfo& r);
    virtual ~CNMCateFriendInfo();
    CNMCateFriendInfo& operator=(const CNMCateFriendInfo& r);

    unsigned char m_body[0x48];                       // +0x10 (not recovered) (CNMCategoryInfo-derived)
};
MS2_CHECK_SIZE(CNMCateFriendInfo, 0x58);

class CNMChannelMemberInfo : public CNMSerializable
{
public:
    CNMChannelMemberInfo(const CNMChannelMemberInfo& r);
    virtual ~CNMChannelMemberInfo();
    CNMChannelMemberInfo& operator=(const CNMChannelMemberInfo& r);

    unsigned char m_body[0x20];                       // +0x10 (not recovered)
};
MS2_CHECK_SIZE(CNMChannelMemberInfo, 0x30);

class CNMCharacter : public CNMSerializable
{
public:
    CNMCharacter(const CNMCharacter& r);
    virtual ~CNMCharacter();
    CNMCharacter& operator=(const CNMCharacter& r);

    unsigned char m_body[0x88];                       // +0x10 (not recovered)
};
MS2_CHECK_SIZE(CNMCharacter, 0x98);

class CNMChatRoomMemberInfo : public CNMSerializable
{
public:
    CNMChatRoomMemberInfo(const CNMChatRoomMemberInfo& r);
    virtual ~CNMChatRoomMemberInfo();
    CNMChatRoomMemberInfo& operator=(const CNMChatRoomMemberInfo& r);

    unsigned char m_body[0x210];                       // +0x10 (not recovered) (CNMRealUserInfo/CNMDefaultUserInfo-derived)
};
MS2_CHECK_SIZE(CNMChatRoomMemberInfo, 0x220);

class CNMFileEvent : public CNMSerializable
{
public:
    CNMFileEvent(const CNMFileEvent& r);
    virtual ~CNMFileEvent();
    CNMFileEvent& operator=(const CNMFileEvent& r);

    unsigned char m_body[0x118];                       // +0x10 (not recovered)
};
MS2_CHECK_SIZE(CNMFileEvent, 0x128);

class CNMFilePath : public CNMSerializable
{
public:
    CNMFilePath(const CNMFilePath& r);
    virtual ~CNMFilePath();
    CNMFilePath& operator=(const CNMFilePath& r);

    unsigned char m_body[0x108];                       // +0x10 (not recovered)
};
MS2_CHECK_SIZE(CNMFilePath, 0x118);

class CNMFriendInfo : public CNMSerializable
{
public:
    CNMFriendInfo(const CNMFriendInfo& r);
    virtual ~CNMFriendInfo();
    CNMFriendInfo& operator=(const CNMFriendInfo& r);

    unsigned char m_body[0x570];                       // +0x10 (not recovered) (CNMRealFriendInfo/CNMDefaultUserInfo-derived)
};
MS2_CHECK_SIZE(CNMFriendInfo, 0x580);

class CNMGameCode : public CNMSerializable
{
public:
    CNMGameCode(const CNMGameCode& r);
    virtual ~CNMGameCode();
    CNMGameCode& operator=(const CNMGameCode& r);

    int m_nGameCode;                                            // +0x10
    int m_n14;                                                  // +0x14
};
MS2_CHECK_SIZE(CNMGameCode, 0x18);

class CNMGameInfo : public CNMSerializable
{
public:
    CNMGameInfo(const CNMGameInfo& r);
    virtual ~CNMGameInfo();
    CNMGameInfo& operator=(const CNMGameInfo& r);

    unsigned char m_body[0x1498];                       // +0x10 (not recovered)
};
MS2_CHECK_SIZE(CNMGameInfo, 0x14a8);

class CNMGameServerCode : public CNMSerializable
{
public:
    CNMGameServerCode(const CNMGameServerCode& r);
    virtual ~CNMGameServerCode();
    CNMGameServerCode& operator=(const CNMGameServerCode& r);

    int m_nServerCode;                                          // +0x10
    int m_n14;                                                  // +0x14
};
MS2_CHECK_SIZE(CNMGameServerCode, 0x18);

class CNMGuildMemberInfo : public CNMSerializable
{
public:
    CNMGuildMemberInfo(const CNMGuildMemberInfo& r);
    CNMGuildMemberInfo(const CNMChannelMemberInfo& r);          // 0x141574aa0
    virtual ~CNMGuildMemberInfo();
    CNMGuildMemberInfo& operator=(const CNMGuildMemberInfo& r);
    CNMGuildMemberInfo& operator=(CNMGuildMemberInfo&& r);      // 0x1415f1180

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

class CNMGuildMemberLevelInfo : public CNMSerializable
{
public:
    CNMGuildMemberLevelInfo(const CNMGuildMemberLevelInfo& r);
    virtual ~CNMGuildMemberLevelInfo();
    CNMGuildMemberLevelInfo& operator=(const CNMGuildMemberLevelInfo& r);

    unsigned char m_body[0x48];                       // +0x10 (not recovered)
};
MS2_CHECK_SIZE(CNMGuildMemberLevelInfo, 0x58);

class CNMNoteInfo2 : public CNMSerializable
{
public:
    CNMNoteInfo2(const CNMNoteInfo2& r);
    virtual ~CNMNoteInfo2();
    CNMNoteInfo2& operator=(const CNMNoteInfo2& r);

    unsigned char m_body[0xad8];                       // +0x10 (not recovered)
};
MS2_CHECK_SIZE(CNMNoteInfo2, 0xae8);

class CNMRejectedUser : public CNMSerializable
{
public:
    CNMRejectedUser(const CNMRejectedUser& r);
    virtual ~CNMRejectedUser();
    CNMRejectedUser& operator=(const CNMRejectedUser& r);

    unsigned char m_body[0xb8];                       // +0x10 (not recovered)
};
MS2_CHECK_SIZE(CNMRejectedUser, 0xc8);

class CNMSessionMemberInfo : public CNMSerializable
{
public:
    CNMSessionMemberInfo(const CNMSessionMemberInfo& r);
    virtual ~CNMSessionMemberInfo();
    CNMSessionMemberInfo& operator=(const CNMSessionMemberInfo& r);

    unsigned char m_body[0xe8];                       // +0x10 (not recovered)
};
MS2_CHECK_SIZE(CNMSessionMemberInfo, 0xf8);

class CNMVirtualUserInfo : public CNMSerializable
{
public:
    CNMVirtualUserInfo(const CNMVirtualUserInfo& r);
    virtual ~CNMVirtualUserInfo();
    CNMVirtualUserInfo& operator=(const CNMVirtualUserInfo& r);

    unsigned char m_body[0x480];                       // +0x10 (not recovered)
};
MS2_CHECK_SIZE(CNMVirtualUserInfo, 0x490);

class CNMExecutePatcherFunc : public CNMFunc
{
public:
    CNMExecutePatcherFunc(const char* szUrl, const char* szPatchDir, const char* szExecPath, int n4, int n5, int n6);
    virtual ~CNMExecutePatcherFunc();                           // 0x1415ed360

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
    virtual ~CNMExecuteLauncherFunc();

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
    virtual ~CNMExecuteNGMPatcherFunc();

    char m_body[0x85c0];                                        // +0x30 (not recovered)
};
MS2_CHECK_SIZE(CNMExecuteNGMPatcherFunc, 0x85f0);

class CNMExecuteNGMPatcher2Func : public CNMFunc
{
public:
    CNMExecuteNGMPatcher2Func(const char* szArgument, int n2);
    virtual ~CNMExecuteNGMPatcher2Func();

    char m_body[0x8008];                                        // +0x30 (not recovered)
};
MS2_CHECK_SIZE(CNMExecuteNGMPatcher2Func, 0x8038);

class CNMExecuteNGMLauncherFunc : public CNMFunc
{
public:
    CNMExecuteNGMLauncherFunc(int nGameCode, int n2, const char* sz3, int n4, const char* sz5, int n6, const char* sz7,
                              const char* sz8, int n9);
    virtual ~CNMExecuteNGMLauncherFunc();

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
    virtual ~CNMExecuteNGMInstallerFunc();

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
    virtual ~CNMIsNGMInstalledFunc();                           // 0x1415ee210

    int m_bInstalled;                                           // +0x30 (reply)
    int m_n34;
};
MS2_CHECK_SIZE(CNMIsNGMInstalledFunc, 0x38);

// One request, four URL kinds (m_nUrlType 1..4), each filling its own input members.
class CNMGetUrlExFunc : public CNMFunc
{
public:
    CNMGetUrlExFunc();
    virtual ~CNMGetUrlExFunc();                                 // 0x1415edfc0

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
    CNMGetSessionValueFunc(const char* szName);
    virtual ~CNMGetSessionValueFunc();                          // 0x1415edf70

    char m_szName[0x20];                                        // +0x30
    char m_szValue[0x100];                                      // +0x50 (reply)
};
MS2_CHECK_SIZE(CNMGetSessionValueFunc, 0x150);

class CNMSetSessionValueFunc : public CNMFunc
{
public:
    CNMSetSessionValueFunc(const char* szName, const char* szValue, int n3);
    virtual ~CNMSetSessionValueFunc();

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
    virtual ~CNMBringForwardStandAloneMsgFunc();

    char m_szName[0x400];                                       // +0x30
};
MS2_CHECK_SIZE(CNMBringForwardStandAloneMsgFunc, 0x430);

class CNMDownloadFileFunc : public CNMFunc
{
public:
    CNMDownloadFileFunc(const char* szUrl, const char* szPath);
    virtual ~CNMDownloadFileFunc();

    char m_szUrl[0x100];                                        // +0x30
    char m_szPath[0x100];                                       // +0x130
};
MS2_CHECK_SIZE(CNMDownloadFileFunc, 0x230);

class CNMUploadFileFunc : public CNMFunc
{
public:
    CNMUploadFileFunc(const char* szUrl, const char* sz2, const char* sz3, int n4);
    virtual ~CNMUploadFileFunc();

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
    virtual ~CNMGetSupportGameListFunc();                       // 0x1415edf90

    int m_n30;
    int m_n34;
    std::vector<CNMGameCode> m_aGameCode;                       // +0x38 (reply)
};
MS2_CHECK_SIZE(CNMGetSupportGameListFunc, 0x50);

class CNMGetGameServerListFunc : public CNMFunc
{
public:
    CNMGetGameServerListFunc(int nGameCode);
    virtual ~CNMGetGameServerListFunc();

    int m_nGameCode;                                            // +0x30
    int m_n34;
    std::vector<CNMGameServerCode> m_aServerCode;               // +0x38 (reply)
};
MS2_CHECK_SIZE(CNMGetGameServerListFunc, 0x50);

class CNMGetGameFullNameFunc : public CNMFunc
{
public:
    CNMGetGameFullNameFunc(int nGameCode);
    virtual ~CNMGetGameFullNameFunc();

    int m_nGameCode;                                            // +0x30
    char m_szName[0x84];                                        // +0x34 (reply)
};
MS2_CHECK_SIZE(CNMGetGameFullNameFunc, 0xb8);

class CNMGetGameShortNameFunc : public CNMFunc
{
public:
    CNMGetGameShortNameFunc(int nGameCode);
    virtual ~CNMGetGameShortNameFunc();

    int m_nGameCode;                                            // +0x30
    char m_szName[0x84];                                        // +0x34 (reply)
};
MS2_CHECK_SIZE(CNMGetGameShortNameFunc, 0xb8);

class CNMGetGameFriendTitleFunc : public CNMFunc
{
public:
    CNMGetGameFriendTitleFunc(int nGameCode);
    virtual ~CNMGetGameFriendTitleFunc();

    int m_nGameCode;                                            // +0x30
    char m_szTitle[0x84];                                       // +0x34 (reply)
};
MS2_CHECK_SIZE(CNMGetGameFriendTitleFunc, 0xb8);

class CNMGetGameServerNameFunc : public CNMFunc
{
public:
    CNMGetGameServerNameFunc(int nGameCode, int nServerCode);
    virtual ~CNMGetGameServerNameFunc();

    int m_nGameCode;                                            // +0x30
    int m_nServerCode;                                          // +0x34
    char m_szName[0x80];                                        // +0x38 (reply)
};
MS2_CHECK_SIZE(CNMGetGameServerNameFunc, 0xb8);

class CNMDownloadGuildMarkFileFunc : public CNMFunc
{
public:
    CNMDownloadGuildMarkFileFunc(int nGameCode, unsigned __int64 nGuildKey, const char* szPath);
    virtual ~CNMDownloadGuildMarkFileFunc();

    int m_nGameCode;                                            // +0x30
    int m_n34;
    unsigned __int64 m_nGuildKey;                               // +0x38
    char m_szPath[0x100];                                       // +0x40
};
MS2_CHECK_SIZE(CNMDownloadGuildMarkFileFunc, 0x140);
