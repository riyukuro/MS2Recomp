// unit_1415cd8a0.h - CNMCRChatRoom (RTTI .?AVCNMCRChatRoom@@), the Nexon Messenger SDK's client-side handle of one chat
// room, from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original file probably nmcrchatroom.cpp (header name
// assumed). Method names are invented from the function object each one runs (the SDK's CNMCR*Func).
#pragma once
#include "ms2/ms2layout.h"
#include "ms2/placeholder/nmchatroomfunc.h"

// 0x4f0 bytes (scalar deleting dtor 0x1415f4e10), vftable 0x142f43708 with the destructor as its only slot.
class CNMCRChatRoom
{
public:
    CNMCRChatRoom();                                            // 0x1415cd8a0
    virtual ~CNMCRChatRoom();                                   // 0x1415cd8f0

    unsigned GetSerialKey();                                    // 0x1415cd950
    int RegisterCallback(HWND hWnd, unsigned uMsg);             // 0x1415cd970
    int GetRoomInfo(CNMChatRoomInfoEx* pInfo);                  // 0x1415cd9f0 (also refreshes the cached copy)
    int ChangeRoomInfo(const char* szTitle, const unsigned* pU434, const unsigned* pU438, const unsigned* pU43c,
        const char* sz448, const unsigned __int64* pU440);      // 0x1415cdac0
    int GetMyInfo(CNMChatRoomMemberInfo* pInfo);                // 0x1415cdba0 (member query kind 2)
    int GetMemberList(std::vector<CNMChatRoomMemberInfo>* pList); // 0x1415cdc60
    int InviteUser(const char* szUser, const char* szMessage);  // 0x1415cdd00
    int BanUser(unsigned __int64 uUserKey);                     // 0x1415cdda0
    int SendChatMessage(const unsigned __int64* pKeys, const CNMChatMessage& msg); // 0x1415cde10
    int Close();                                                // 0x1415cdeb0

    unsigned m_uSerialKey;                                      // +0x08
    CNMChatRoomInfoEx m_roomInfo;                               // +0x10
};
MS2_CHECK_SIZE(CNMCRChatRoom, 0x4f0);
