// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CChatEmoticonCli: the client state of the owned chat emoticon
// packs (id list, pack list, pack-by-id map), its packet handlers and the expiry report, plus the inline
// ChatEmoticonGroupInfo (see chatemoticoncli.h).
// MS2-UNIT: client\ms2\chatemoticoncli.cpp
// MS2-RANGE: 0x1400c34f0-0x1400c3670 .text$di
// MS2-RANGE: 0x142c9f0d0-0x142c9f130 .text$yd
// MS2-RANGE: 0x140a38fa0-0x140a40060 .text$mn
// MS2-PIN: ?deallocate@?$allocator@U?$_List_node@V?$MS2Ptr@VChatEmoticonGroupInfo@@@@PEAX@std@@@std@@QEAAXQEAU?$_List_node@V?$MS2Ptr@VChatEmoticonGroupInfo@@@@PEAX@2@_K@Z 0x140a3f640
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$forward@AEAPEAU?$_List_node@V?$MS2Ptr@VChatEmoticonGroupInfo@@@@PEAX@std@@@std@@YAAEAPEAU?$_List_node@V?$MS2Ptr@VChatEmoticonGroupInfo@@@@PEAX@0@AEAPEAU10@@Z 0x140a3cdd0 ; unique
// MS2-PIN: ??$forward@AEAPEAU?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VChatEmoticonGroupInfo@@@@@std@@PEAX@std@@@std@@YAAEAPEAU?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VChatEmoticonGroupInfo@@@@@std@@PEAX@0@AEAPEAU10@@Z 0x140a3cde0 ; unique
// MS2-PIN: ??$forward@AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VChatEmoticonGroupInfo@@@@@std@@@std@@@std@@@std@@@std@@YAAEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VChatEmoticonGroupInfo@@@@@std@@@std@@@std@@@0@AEAV10@@Z 0x140a3ce10 ; unique
// MS2-PIN: ??$forward@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VChatEmoticonGroupInfo@@@@@std@@@std@@@std@@@std@@@std@@YA$$QEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VChatEmoticonGroupInfo@@@@@std@@@std@@@std@@@0@AEAV10@@Z 0x140a3ce30 ; unique
// MS2-PIN: ?IsNull@?$MS2Ptr@VChatEmoticonGroupInfo@@@@QEBA_NXZ 0x140a3d480 ; unique
// MS2-PIN: ?AddRefImpl@?$MS2Ptr@VChatEmoticonGroupInfo@@@@AEBAXPEAX@Z 0x140a3dcc0 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@I@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VChatEmoticonGroupInfo@@@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VChatEmoticonGroupInfo@@@@@std@@@std@@@2@$00@2@$00@std@@QEAAAEAU?$less@I@2@XZ 0x140a3e830 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@I@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VChatEmoticonGroupInfo@@@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VChatEmoticonGroupInfo@@@@@std@@@std@@@2@$00@2@$00@std@@QEBAAEBU?$less@I@2@XZ 0x140a3e840 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_List_node@IPEAX@std@@@std@@V?$_List_val@U?$_List_simple_types@I@std@@@2@$00@std@@QEAAAEAV?$allocator@U?$_List_node@IPEAX@std@@@2@XZ 0x140a3e850 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VChatEmoticonGroupInfo@@@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VChatEmoticonGroupInfo@@@@@std@@@std@@@2@$00@std@@QEAAAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VChatEmoticonGroupInfo@@@@@std@@PEAX@std@@@2@XZ 0x140a3e890 ; unique
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VChatEmoticonGroupInfo@@@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VChatEmoticonGroupInfo@@@@@std@@@std@@@2@$00@std@@QEAAAEAV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VChatEmoticonGroupInfo@@@@@std@@@std@@@2@XZ 0x140a3e910 ; unique
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VChatEmoticonGroupInfo@@@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VChatEmoticonGroupInfo@@@@@std@@@std@@@2@$00@std@@QEBAAEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VChatEmoticonGroupInfo@@@@@std@@@std@@@2@XZ 0x140a3e920 ; unique
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VChatEmoticonGroupInfo@@@@AEAAXPEAX@Z 0x140a3ee70 ; unique
// MS2-PIN: ?max_size@?$list@IV?$allocator@I@std@@@std@@QEBA_KXZ 0x140a3fc80 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ??1ChatEmoticonGroupInfo@@UEAA@XZ 0x140a3d420
// MS2-PIN: ??_GChatEmoticonGroupInfo@@UEAAPEAXI@Z 0x140a3dc20
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\chatemoticoncli.cpp"
#include "ms2/placeholder/ms2stdafx.h"

#include "chatemoticoncli.h"

#include <set>

#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/mstime.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/uiobject.h"

#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- statics (.text$di) ----
// Two copies of the sort-type name table (two headers of the unit define it).
static CString s_strSortTypeNames0[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSortTypeNames1[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};

// ---- unit-local placeholders ----

// The chat emoticon dialog (ui id 0x4f80) and the two messenger browsers; only used for the RTTI lookup and their
// member calls (real classes: uichatemoticondialog.cpp, uimessenger.cpp, uigroupmessenger.cpp).
class UIChatEmoticonDialog : public UIDialog
{
public:
    void FUN_140bd2620();                                           // refresh
    void FUN_140bd2660();                                           // rebuild
    void FUN_140bd26c0(int nEmoticonId);                            // select
    unsigned char unrecovered[0x50];
};
class Unk_MessengerChat { public: void FUN_141a10010(unsigned nFlag, int nId); };
class UIMessengerBrowser : public UIDialog
{
public:
    Unk_MessengerChat* FUN_141a259c0(const CStringW& strName);
    unsigned char unrecovered[0x10];
};
class Unk_GroupChat { public: void FUN_14194afc0(int nId); };
class UIGroupMessengerBrowser : public UIDialog
{
public:
    Unk_GroupChat* FUN_141952fc0(const CStringW& strName);
    unsigned char unrecovered[0x10];
};
class UIChatDialog;
extern template class MS2Ptr<UIObject>;
UIChatEmoticonDialog* FUN_140a3aa20();
UIGroupMessengerBrowser* FUN_140a3aad0(int nUiId);
UIMessengerBrowser* FUN_140a3ab70(int nUiId);

// UI manager: the lookup of a dialog by its ui id.
class Unk_EmoUIManager
{
public:
    MS2Ptr<UIObject> FUN_141adcea0(int nUiId);
};
Unk_EmoUIManager* FUN_1403ed2b0();
UIChatDialog* FUN_140938cd0(int nUiId);
void FUN_141ac1580(UIChatDialog* pChat, const CStringW& strName, const CStringW& strMsg, int nFlag);

// The emoticon table row and its handle.
struct Unk_EmoData { char m_pad[0x1c]; unsigned m_nGroupId; };
class Unk_EmoDataPtr
{
public:
    ~Unk_EmoDataPtr();                                              // 0x1401f0530
    bool FUN_1401f0b70() const;
    Unk_EmoData* FUN_1401f1080() const;
private:
    void* m_pad;
    void* m_p;
};
MS2_CHECK_SIZE(Unk_EmoDataPtr, 0x10);
class Unk_EmoTable { public: Unk_EmoDataPtr FUN_1401e7120(int nEmoticonId); };
Unk_EmoTable* FUN_1409eecd0();

// The item row (the pack item) and its handle.
class Unk_EmoItemData { public: CString FUN_14053fdd0(); };
class Unk_EmoItemPtr
{
public:
    ~Unk_EmoItemPtr();                                              // 0x1401b50d0
    bool FUN_1402ffd90() const;
    Unk_EmoItemData* FUN_1401b52a0() const;
private:
    void* m_pad;
    void* m_p;
};
MS2_CHECK_SIZE(Unk_EmoItemPtr, 0x10);
Unk_EmoItemPtr FUN_14053f870(int nItemId);

class Unk_EmoStrings { public: CStringW FUN_141811980(int nTable, int nIndex); };
Unk_EmoStrings* FUN_1401a9d70();
class Unk_EmoChatFormat { public: void FUN_1416fb340(CStringW& strMsg); };
Unk_EmoChatFormat* FUN_1403b4750();

__int64 FUN_140869440();                                            // server time
CStringW FUN_14028b8e0(const CStringW& strKey);
CStringW FUN_1405c2690(CStringW strKey, const CStringW& strArg);
CStringW FUN_14016a730(const char* sz, int nCodePage);
void FUN_140d73aa0(CStringW strMsg, int nType, void* pTarget, CStringW strTag);
void FUN_1412751f0(const CStringW& strMsg, int a, int b);
void FUN_140710590(COutPacket& packet);

// ---- dialog lookups ----

// The ui id of the chat emoticon dialog.
// @0x140a3dc60
inline int FUN_140a3dc60() { return 0x4f80; }

// @0x140a3aa20
UIChatEmoticonDialog* FUN_140a3aa20()
{
    Unk_EmoUIManager* pManager = FUN_1403ed2b0();
    if (pManager == 0)
        return 0;
    MS2Ptr<UIObject> spUI = pManager->FUN_141adcea0(FUN_140a3dc60());
    if (spUI.IsNull())
        return 0;
    return dynamic_cast<UIChatEmoticonDialog*>((UIObject*)spUI);
}

// @0x140a3aad0
UIGroupMessengerBrowser* FUN_140a3aad0(int nUiId)
{
    if (FUN_1403ed2b0() != 0)
    {
        MS2Ptr<UIObject> spUI = FUN_1403ed2b0()->FUN_141adcea0(nUiId);
        if (spUI.get() != 0)
            return dynamic_cast<UIGroupMessengerBrowser*>((UIObject*)spUI);
    }
    return 0;
}

// @0x140a3ab70
UIMessengerBrowser* FUN_140a3ab70(int nUiId)
{
    if (FUN_1403ed2b0() != 0)
    {
        MS2Ptr<UIObject> spUI = FUN_1403ed2b0()->FUN_141adcea0(nUiId);
        if (spUI.get() != 0)
            return dynamic_cast<UIMessengerBrowser*>((UIObject*)spUI);
    }
    return 0;
}

// ---- CChatEmoticonCli ----

// 0: the full state (owned ids, then the packs with expiry).
// @0x140a38fa0
void CChatEmoticonCli::FUN_140a38fa0(CInPacket& packet)
{
    m_ids.clear();
    unsigned nIds = (unsigned short)packet.vfunc_o8_2();
    for (int i = 0; i < (int)nIds; i++)
    {
        unsigned nId = packet.vfunc_o8_3();
        m_ids.push_back(nId);
    }
    m_groups.clear();
    m_groupById.clear();
    unsigned nGroups = (unsigned short)packet.vfunc_o8_2();
    for (int i = 0; i < (int)nGroups; i++)
    {
        unsigned nId = packet.vfunc_o8_3();
        __int64 nExpire = packet.vfunc_o8_4();
        FUN_140a3a290(nId, nExpire);
    }
    UIChatEmoticonDialog* pDlg = FUN_140a3aa20();
    if (pDlg != 0)
    {
        pDlg->FUN_140bd2660();
        pDlg->FUN_140bd2620();
    }
}
MS2_REPLACE_METHOD(0x140A38FA0, CChatEmoticonCli, FUN_140a38fa0, 458, 0xDF3657B8);

// 1: expired packs removed.
// @0x140a39170
void CChatEmoticonCli::FUN_140a39170(CInPacket& packet)
{
    int nGroups = packet.vfunc_o8_3();
    for (int i = 0; i < nGroups; i++)
    {
        unsigned nId = packet.vfunc_o8_3();
        FUN_140a3a380(nId);
    }
    int nIds = packet.vfunc_o8_3();
    for (int i = 0; i < nIds; i++)
    {
        unsigned nId = packet.vfunc_o8_3();
        m_ids.remove(nId);
    }
    UIChatEmoticonDialog* pDlg = FUN_140a3aa20();
    if (pDlg != 0)
        pDlg->FUN_140bd2620();
    FUN_140d73aa0(FUN_14028b8e0(L"s_msg_chat_emoticon_expired"), 0, 0, L"");
}
MS2_REPLACE_METHOD(0x140A39170, CChatEmoticonCli, FUN_140a39170, 489, 0xFCB43972);

// 2: packs added (with a chat notice).
// @0x140a39360
void CChatEmoticonCli::FUN_140a39360(CInPacket& packet)
{
    int nItemId = packet.vfunc_o8_3();
    int nCount = packet.vfunc_o8_3();
    std::set<unsigned> setAdded;
    for (int i = 0; i < nCount; i++)
    {
        unsigned nId = packet.vfunc_o8_3();
        __int64 nExpire = packet.vfunc_o8_4();
        FUN_140a3a290(nId, nExpire);
        setAdded.insert(nId);
    }
    UIChatEmoticonDialog* pDlg = FUN_140a3aa20();
    if (pDlg != 0)
    {
        MS2_FOR_EACH(unsigned nId, setAdded)
            pDlg->FUN_140bd26c0(nId);
        pDlg->FUN_140bd2620();
    }
    Unk_EmoItemPtr item = FUN_14053f870(nItemId);
    if (item.FUN_1402ffd90())
    {
        MS2_ASSERT_AT(0x91, 0);
        return;
    }
    UIChatDialog* pChat = FUN_140938cd0(0x4e5d);
    if (pChat != 0)
    {
        CStringW strName = FUN_14016a730((const char*)item.FUN_1401b52a0()->FUN_14053fdd0(), 0);
        CStringW strMsg = FUN_1405c2690(L"s_msg_chat_emoticon_add_notify_message",
                                        FUN_1401a9d70()->FUN_141811980(1, nItemId));
        FUN_1403b4750()->FUN_1416fb340(strMsg);
        FUN_141ac1580(pChat, strName, strMsg, 1);
        FUN_1412751f0(strMsg, 0, 1);
    }
}
MS2_REPLACE_METHOD(0x140A39360, CChatEmoticonCli, FUN_140a39360, 943, 0xC5A9D741);

// 5: one id moved to the end of the owned list.
// @0x140a39720
void CChatEmoticonCli::FUN_140a39720(CInPacket& packet)
{
    unsigned nId = packet.vfunc_o8_3();
    m_ids.remove(nId);
    m_ids.push_back(nId);
    UIChatEmoticonDialog* pDlg = FUN_140a3aa20();
    if (pDlg != 0)
        pDlg->FUN_140bd2620();
}
MS2_REPLACE_METHOD(0x140A39720, CChatEmoticonCli, FUN_140a39720, 129, 0x890960FB);

// 6: one id removed from the owned list.
// @0x140a397b0
void CChatEmoticonCli::FUN_140a397b0(CInPacket& packet)
{
    unsigned nId = packet.vfunc_o8_3();
    m_ids.remove(nId);
    UIChatEmoticonDialog* pDlg = FUN_140a3aa20();
    if (pDlg != 0)
        pDlg->FUN_140bd2620();
}
MS2_REPLACE_METHOD(0x140A397B0, CChatEmoticonCli, FUN_140a397b0, 107, 0x3D9C8144);

// 3: a pack opened in the messenger browser.
// @0x140a39830
void CChatEmoticonCli::FUN_140a39830(CInPacket& packet)
{
    unsigned nId = packet.vfunc_o8_3();
    CStringW strName = packet.vfunc_o8_8();
    unsigned nFlag = packet.vfunc_o8_1();
    UIMessengerBrowser* pBrowser = FUN_140a3ab70(0x4e61);
    if (pBrowser == 0)
        return;
    Unk_MessengerChat* pChat = pBrowser->FUN_141a259c0(strName);
    if (pChat == 0)
        return;
    pChat->FUN_141a10010(nFlag, nId);
}
MS2_REPLACE_METHOD(0x140A39830, CChatEmoticonCli, FUN_140a39830, 255, 0xCDB8952F);

// 4: a pack opened in the group messenger browser.
// @0x140a39940
void CChatEmoticonCli::FUN_140a39940(CInPacket& packet)
{
    unsigned nId = packet.vfunc_o8_3();
    CStringW strName = packet.vfunc_o8_8();
    UIGroupMessengerBrowser* pBrowser = FUN_140a3aad0(0x4e93);
    if (pBrowser == 0)
        return;
    Unk_GroupChat* pChat = pBrowser->FUN_141952fc0(strName);
    if (pChat == 0)
        return;
    pChat->FUN_14194afc0(nId);
}
MS2_REPLACE_METHOD(0x140A39940, CChatEmoticonCli, FUN_140a39940, 209, 0x3A7FAB09);

// 7: result notice of a pack operation.
// @0x140a39a20
void CChatEmoticonCli::FUN_140a39a20(CInPacket& packet)
{
    int nResult = packet.vfunc_o8_1();
    switch (nResult)
    {
    case 0:
        FUN_140d73aa0(FUN_14028b8e0(L"s_msg_chat_emoticon_print_failed"), 0, 0, L"");
        break;
    case 1:
        FUN_140d73aa0(FUN_14028b8e0(L"s_msg_chat_emoticon_add_failed"), 0, 0, L"");
        break;
    case 2:
        FUN_140d73aa0(FUN_14028b8e0(L"s_msg_chat_emoticon_add_failed_already_exist"), 0, 0, L"");
        break;
    case 3:
        FUN_140d73aa0(FUN_14028b8e0(L"s_msg_chat_emoticon_add_failed"), 0, 0, L"");
        break;
    case 4:
        FUN_140d73aa0(FUN_14028b8e0(L"s_msg_chat_emoticon_add_failed"), 0, 0, L"");
        break;
    }
}
MS2_REPLACE_METHOD(0x140A39A20, CChatEmoticonCli, FUN_140a39a20, 938, 0x5E574199);

// @0x140a39dd0
bool CChatEmoticonCli::FUN_140a39dd0(int nEmoticonId)
{
    Unk_EmoDataPtr data = FUN_1409eecd0()->FUN_1401e7120(nEmoticonId);
    if (data.FUN_1401f0b70())
        return false;
    std::map<unsigned, MS2Ptr<ChatEmoticonGroupInfo> >::iterator it = m_groupById.find(data.FUN_1401f1080()->m_nGroupId);
    if (it == m_groupById.end())
        return false;
    MS2Ptr<ChatEmoticonGroupInfo> spGroup = it->second;
    if (spGroup.IsNull())
    {
        MS2_ASSERT_AT(0x10a, 0);
        return false;
    }
    CMsTime now(FUN_140869440());
    CMsTime expire(spGroup->m_nExpire);
    if (now > expire)
        return false;
    return true;
}
MS2_REPLACE_METHOD(0x140A39DD0, CChatEmoticonCli, FUN_140a39dd0, 454, 0xE5D9DB06);

// @0x140a39fa0
bool CChatEmoticonCli::FUN_140a39fa0(int nEmoticonId)
{
    Unk_EmoDataPtr data = FUN_1409eecd0()->FUN_1401e7120(nEmoticonId);
    if (data.FUN_1401f0b70())
        return false;
    MS2_FOR_EACH(unsigned nId, m_ids)
    {
        if (nId == nEmoticonId)
            return true;
    }
    return false;
}
MS2_REPLACE_METHOD(0x140A39FA0, CChatEmoticonCli, FUN_140a39fa0, 266, 0xE11749A0);

// @0x140a3a0b0
bool CChatEmoticonCli::FUN_140a3a0b0(int nEmoticonId)
{
    Unk_EmoDataPtr data = FUN_1409eecd0()->FUN_1401e7120(nEmoticonId);
    if (data.FUN_1401f0b70())
        return false;
    return FUN_140a3a140(data.FUN_1401f1080()->m_nGroupId);
}
MS2_REPLACE_METHOD(0x140A3A0B0, CChatEmoticonCli, FUN_140a3a0b0, 132, 0x16C12BAD);

// @0x140a3a140
bool CChatEmoticonCli::FUN_140a3a140(unsigned nGroupId)
{
    std::map<unsigned, MS2Ptr<ChatEmoticonGroupInfo> >::iterator it = m_groupById.find(nGroupId);
    if (it == m_groupById.end())
        return true;
    MS2Ptr<ChatEmoticonGroupInfo> spGroup = it->second;
    if (spGroup.IsNull())
    {
        MS2_ASSERT_AT(0x137, 0);
        return true;
    }
    CMsTime now(FUN_140869440());
    CMsTime expire(spGroup->m_nExpire);
    if (expire >= now)
        return false;
    return true;
}
MS2_REPLACE_METHOD(0x140A3A140, CChatEmoticonCli, FUN_140a3a140, 319, 0xCB912C57);

// @0x140a3a290
void CChatEmoticonCli::FUN_140a3a290(unsigned nGroupId, __int64 nExpire)
{
    FUN_140a3a380(nGroupId);
    MS2Ptr<ChatEmoticonGroupInfo> spGroup(new ChatEmoticonGroupInfo);
    spGroup->m_nId = nGroupId;
    spGroup->m_nExpire = nExpire;
    m_groupById[nGroupId] = spGroup;
    m_groups.push_back(spGroup);
}
MS2_REPLACE_METHOD(0x140A3A290, CChatEmoticonCli, FUN_140a3a290, 225, 0xED9F37B5);

// @0x140a3a380
void CChatEmoticonCli::FUN_140a3a380(unsigned nGroupId)
{
    MS2Ptr<ChatEmoticonGroupInfo> spGroup = FUN_140a3a640(nGroupId);
    if (spGroup.IsNull())
        return;
    m_groupById.erase(nGroupId);
    m_groups.remove(spGroup);
}
MS2_REPLACE_METHOD(0x140A3A380, CChatEmoticonCli, FUN_140a3a380, 132, 0x5133450B);

// @0x140a3a410
void CChatEmoticonCli::SendMessenger()
{
    CMsTime now(FUN_140869440());
    std::list<unsigned> expired;
    MS2_FOR_EACH(MS2Ptr<ChatEmoticonGroupInfo> spGroup, m_groups)
    {
        if (spGroup.IsNull())
            continue;
        CMsTime expire(spGroup->m_nExpire);
        if (now > expire)
            expired.push_back(spGroup->m_nId);
    }
    COutPacket packet(0xb7, 0);
    packet.vfunc_o10_1(1);
    packet.vfunc_o10_3((int)expired.size());
    MS2_FOR_EACH(unsigned nId, expired)
        packet.vfunc_o10_3(nId);
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x140A3A410, CChatEmoticonCli, SendMessenger, 550, 0x755D789E);

// @0x140a3a640
MS2Ptr<ChatEmoticonGroupInfo> CChatEmoticonCli::FUN_140a3a640(unsigned nGroupId)
{
    std::map<unsigned, MS2Ptr<ChatEmoticonGroupInfo> >::iterator it = m_groupById.find(nGroupId);
    if (it == m_groupById.end())
        return MS2Ptr<ChatEmoticonGroupInfo>(0);
    return it->second;
}
MS2_REPLACE_METHOD(0x140A3A640, CChatEmoticonCli, FUN_140a3a640, 174, 0x91849124);

// @0x140a3a700
void CChatEmoticonCli::FUN_140a3a700(CInPacket& packet)
{
    int nType = packet.vfunc_o8_1();
    switch (nType)
    {
    case 0: FUN_140a38fa0(packet); break;
    case 1: FUN_140a39170(packet); break;
    case 2: FUN_140a39360(packet); break;
    case 3: FUN_140a39830(packet); break;
    case 4: FUN_140a39940(packet); break;
    case 5: FUN_140a39720(packet); break;
    case 6: FUN_140a397b0(packet); break;
    case 7: FUN_140a39a20(packet); break;
    }
}
MS2_REPLACE_METHOD(0x140A3A700, CChatEmoticonCli, FUN_140a3a700, 237, 0x18A57F3A);
