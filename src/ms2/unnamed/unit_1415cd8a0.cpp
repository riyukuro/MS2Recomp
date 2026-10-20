// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CNMCRChatRoom, the Nexon Messenger SDK's chat-room handle:
// every method builds the matching CNMCR*Func object for the room's serial key, runs it through
// CNMManager::CallNMFunc and copies the reply out.
// MS2-UNIT: unit_1415cd8a0
// MS2-RANGE: 0x1415cd8a0-0x1415cdf00 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include "ms2/unnamed/unit_1415cd8a0.h"
#include "hook/ms2hook.h"

// @0x1415cd8a0
CNMCRChatRoom::CNMCRChatRoom()
{
    m_uSerialKey = 0;
}

// @0x1415cd8f0
CNMCRChatRoom::~CNMCRChatRoom()
{
}

// @0x1415cd950
unsigned CNMCRChatRoom::GetSerialKey()
{
    return m_uSerialKey;
}
MS2_REPLACE_METHOD(0x1415CD950, CNMCRChatRoom, GetSerialKey, 14, 0x92BE4827);

// @0x1415cd970
int CNMCRChatRoom::RegisterCallback(HWND hWnd, unsigned uMsg)
{
    CNMCRRegisterCallbackFunc func(m_uSerialKey, hWnd, uMsg);
    return CNMManager::GetInstance()->CallNMFunc(&func);
}
MS2_REPLACE_METHOD(0x1415CD970, CNMCRChatRoom, RegisterCallback, 107, 0xBBE241E0);

// @0x1415cd9f0
int CNMCRChatRoom::GetRoomInfo(CNMChatRoomInfoEx* pInfo)
{
    CNMCRGetRoomInfoExFunc func(m_uSerialKey);
    if (CNMManager::GetInstance()->CallNMFunc(&func))
    {
        m_roomInfo = func.m_info;
        *pInfo = func.m_info;
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1415CD9F0, CNMCRChatRoom, GetRoomInfo, 201, 0xDC96A02A);

// @0x1415cdac0
int CNMCRChatRoom::ChangeRoomInfo(const char* szTitle, const unsigned* pU434, const unsigned* pU438,
    const unsigned* pU43c, const char* sz448, const unsigned __int64* pU440)
{
    CNMCRChangeRoomInfoFunc func(m_uSerialKey, szTitle, pU434, pU438, pU43c, sz448, pU440);
    return CNMManager::GetInstance()->CallNMFunc(&func);
}
MS2_REPLACE_METHOD(0x1415CDAC0, CNMCRChatRoom, ChangeRoomInfo, 204, 0xEEA49F09);

// @0x1415cdba0
int CNMCRChatRoom::GetMyInfo(CNMChatRoomMemberInfo* pInfo)
{
    CNMCRGetMemberInfoFunc func(m_uSerialKey, 2);
    if (CNMManager::GetInstance()->CallNMFunc(&func))
    {
        *pInfo = func.m_info;
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1415CDBA0, CNMCRChatRoom, GetMyInfo, 182, 0x285F807B);

// @0x1415cdc60
int CNMCRChatRoom::GetMemberList(std::vector<CNMChatRoomMemberInfo>* pList)
{
    CNMCRGetMemberListFunc func(m_uSerialKey);
    if (CNMManager::GetInstance()->CallNMFunc(&func))
    {
        *pList = func.m_aMembers;
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1415CDC60, CNMCRChatRoom, GetMemberList, 142, 0x3EEB7497);

// @0x1415cdd00
int CNMCRChatRoom::InviteUser(const char* szUser, const char* szMessage)
{
    CNMCRInviteUserFunc func(m_uSerialKey, szUser, szMessage);
    return CNMManager::GetInstance()->CallNMFunc(&func);
}
MS2_REPLACE_METHOD(0x1415CDD00, CNMCRChatRoom, InviteUser, 147, 0x39CFB274);

// @0x1415cdda0
int CNMCRChatRoom::BanUser(unsigned __int64 uUserKey)
{
    CNMCRBanUserFunc func(m_uSerialKey, uUserKey);
    return CNMManager::GetInstance()->CallNMFunc(&func);
}
MS2_REPLACE_METHOD(0x1415CDDA0, CNMCRChatRoom, BanUser, 94, 0xB18C50B0);

// @0x1415cde10
int CNMCRChatRoom::SendChatMessage(const unsigned __int64* pKeys, const CNMChatMessage& msg)
{
    CNMCRSendChatMessageFunc func(m_uSerialKey, pKeys, msg);
    return CNMManager::GetInstance()->CallNMFunc(&func);
}
MS2_REPLACE_METHOD(0x1415CDE10, CNMCRChatRoom, SendChatMessage, 147, 0xF647C2A7);

// @0x1415cdeb0
int CNMCRChatRoom::Close()
{
    CNMCRCloseFunc func(m_uSerialKey);
    return CNMManager::GetInstance()->CallNMFunc(&func);
}
MS2_REPLACE_METHOD(0x1415CDEB0, CNMCRChatRoom, Close, 78, 0x308BE0C1);
