// uicommunitydialog.h - UICommunityDialog and UICommunityQueryDialog (RTTI .?AVUICommunityDialog@@ / .?AVUICommunityQueryDialog@@,
// UI ids 0x4e4d / 0x4e4e, swf "CommunityDialog" / "CommunityQueryDialog"): the community window (buddy, ban, home-visit and
// rival lists with the tab bar) and the modal name/memo query dialog it opens. Owning unit ?\uibuddyeventlistener.cpp (the obj
// also holds the bodies of UIBuddyEventListener and UIBuddyEventDispatcher). Header name assumed from the class names;
// member names are invented from use.
#pragma once
#include <afx.h>
#include "ms2/ms2layout.h"
#include "ms2/client/ms2/uidialog.h"
#include "ms2/client/ms2/uiservice.h"    // eUIClassID (GetUIClassID)
#include "ms2/client/ms2/uimodaldialog.h"
#include "ms2/client/ms2/buddymanager.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/uiugceventlistener.h"
#include "ms2/placeholder/uibuddyeventlistener.h"
#include "ms2/placeholder/uientityeventlistener.h"

class ASData;
class ASObj;
class CProxyGameObject;
class CMsgBoxData;

// UIDialog 0x178 + UIUGCEventListener +0x178 + UIBuddyEventListener +0x180 + UIEntityEventListener +0x188, members from +0x190.
class UICommunityDialog : public UIDialog, public UIUGCEventListener, public UIBuddyEventListener, public UIEntityEventListener
{
public:
    UICommunityDialog();                                        // 0x1418d3190
    virtual ~UICommunityDialog();                               //  0 0x1418d32c0 (??_G 0x1418d8f10)
    virtual CString vfunc_1();                                  //  1 0x1418d3bf0 "CommunityDialog"
    virtual int vfunc_13();                                     // 13 0x1418d3c40 Esc / Enter ends the memo edit
    virtual void OnLoadComplete();                              // 22 0x1418d3650
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x1418d3d70
    virtual void vfunc_45(Scaleform::GFx::Value* pRetVal, const CString& strMethod, ASData* pArgs);       // 45 0x1418d5150
    virtual int vfunc_48() { return 0x4e4d; }                   // 48 0x1418d8fb0
    virtual int vfunc_65();                                     // 65 0x1418d3370
    virtual void vfunc_67();                                    // 67 0x1418d33a0 close: unregister the listeners
    virtual void vfunc_72();                                    // 72 0x1418d34a0 per frame: refresh the counts
    virtual int OnMessage(UISwfEntity* pSender, UIMsg* pMsg);   // IMessageListener 0 0x1418d3720
    virtual void vfunc_79(void* p);                             // 79 0x1418d3a70 buddy packet
    // UIUGCEventListener (+0x178)
    virtual void vfunc_ugc_1(void* p, CString str);             // 1 0x1418d5340 a profile image changed
    // UIBuddyEventListener (+0x180)
    virtual void vfunc_buddy_1(__int64 nId);                    //  1 0x1418d5650
    virtual void vfunc_buddy_2(__int64 nId);                    //  2 0x1418d55e0
    virtual void vfunc_buddy_3(__int64 nId);                    //  3 0x1418d56d0
    virtual void vfunc_buddy_4(__int64 nId, int n);             //  4 0x1418d5790
    virtual void vfunc_buddy_5(__int64 nId);                    //  5 0x1418d5860
    virtual void vfunc_buddy_6(__int64 nId);                    //  6 0x1418d58e0
    virtual void vfunc_buddy_8(__int64 nId);                    //  8 0x1418d5950
    virtual void vfunc_buddy_9(__int64 nId);                    //  9 0x1418d59c0
    virtual void vfunc_buddy_11(__int64 nId);                   // 11 0x1418d5ae0
    virtual void vfunc_buddy_12(__int64 nId);                   // 12 0x1418d5c60
    virtual void vfunc_buddy_13(__int64 nId);                   // 13 0x1418d5cf0
    virtual void vfunc_buddy_14();                              // 14 0x1418d5e50
    // UIEntityEventListener (+0x188)
    virtual void vfunc_3(void* pActor);                         // 3 0x1418d5e90 an actor entered
    virtual void vfunc_4(void* pActor);                         // 4 0x1418d6060 an actor left
    virtual void vfunc_5(void* pActor, int n);                  // 5 0x1418d61d0 an actor changed

    bool FUN_1418d6390(int nButton, const CMsgBoxData& data);   // 0x1418d6390 the home-visit box answer
    void FUN_1418d6430(int nTab);                               // build the buddy list of a tab
    void FUN_1418d6930(int nTab);                               // m_190 = nTab (0..4)
    static eUIClassID GetUIClassID() { return (eUIClassID)0x4e4d; }   // COMDAT (0x141a4b220, uiminimapentity.cpp)
    int FUN_1418d6960();                                        // m_190
    void FUN_1418d6980();                                       // "initData"
    void FUN_1418d69f0(int nTab);                               // change the tab
    void FUN_1418d6a90();                                       // build the tab 0 (nearby players) list
    void FUN_1418d6d00();                                       // build the tab 4 (home blocks) list
    void FUN_1418d6ed0(int nA, int nB);                         // post UIMsg(a, b) to the query dialog 0x4e4e
    void FUN_1418d6f80(int nTab, int nNew, int nCount);         // "setNew"
    void FUN_1418d7000(int nTab, CBuddyManager::Ptr spBuddy);   // add a buddy row
    void FUN_1418d71d0(int nTab, __int64 nId);
    void FUN_1418d7240(__int64 nId);                            // remove a buddy row
    void FUN_1418d73b0(int nTab, CBuddyManager::Ptr spBuddy);   // update a buddy row
    void FUN_1418d74f0(__int64 nId);                            // update a buddy's profile image
    int FUN_1418d76c0();                                        // count the online buddies
    void FUN_1418d77f0(int nOnline, int nTotal);                // "setOnline"
friend void FUN_1418d6410(UICommunityDialog* pDialog);      // inlined tab reset
private:
    MS2_LAYOUT_FRIEND;
    int m_190;                                                  // +0x190 tab (0 nearby, 1 buddy, 2 request, 3 ban, 4 home blocks)
    int m_194;                                                  // +0x194 online buddies
    int m_198;                                                  // +0x198 online count changed
    int m_19c;                                                  // +0x19c list changed
    __int64 m_1a0;                                              // +0x1a0 the ban memo being edited
};
MS2_CHECK_SIZE(UICommunityDialog, 0x1a8);
MS2_CHECK_OFFSET(UICommunityDialog, m_190, 0x190);
MS2_CHECK_OFFSET(UICommunityDialog, m_1a0, 0x1a0);

void FUN_1418d6410(UICommunityDialog* pDialog);                 // 0x1418d6410 m_190 = 0

// Modal dialog that asks for a name / memo (add buddy, add ban, edit memo, home-block name). Base UIModalDialog 0x180.
class UICommunityQueryDialog : public UIModalDialog
{
public:
    UICommunityQueryDialog();                                   // 0x1418da510
    virtual ~UICommunityQueryDialog();                          //  0 0x1418da5e0 (??_G 0x1418dcb30)
    virtual CString vfunc_1();                                  //  1 0x1418da870 "CommunityQueryDialog"
    virtual int vfunc_13();                                     // 13 0x1418db5b0 Enter / Tab keys
    virtual void OnLoadComplete();                              // 22 0x1418da6b0
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x1418da8c0
    virtual int vfunc_48() { return 0x4e4e; }                   // 48 0x1418dcb90
    virtual int vfunc_65();                                     // 65 0x1418da650
    virtual void vfunc_67();                                    // 67 0x1418da680
    virtual int OnMessage(UISwfEntity* pSender, UIMsg* pMsg);   // IMessageListener 0 0x1418daa70
    virtual void vfunc_79(void* p);                             // 79 0x1418da6e0 buddy packet

    void FUN_1418db6d0();                                       // reset the query
    void FUN_1418db750();                                       // "initData"
    void FUN_1418dba00(Unk_BuddyResponse& response);            // the server answered
    void FUN_1418dbcb0(int nMode);                              // OK: validate and send
    int FUN_1418dc410(const CStringW& str);                     // empty / bad word check (true = rejected)
    int FUN_1418dc540(const CStringW& str);                     // add-buddy name check (true = rejected)
    int FUN_1418dc7f0(const CStringW& str);                     // add-ban name check (true = rejected)
private:
    MS2_LAYOUT_FRIEND;
    int m_180;                                                  // +0x180 mode (1 add buddy, 2 add ban, 3 ..., 4 edit memo, 5 home block name)
    CStringW m_188;                                             // +0x188 the entered name
    __int64 m_190;                                              // +0x190 the buddy id
    __int64 m_198;                                              // +0x198
    CStringW m_1a0;                                             // +0x1a0 the entered memo
};
MS2_CHECK_SIZE(UICommunityQueryDialog, 0x1a8);
MS2_CHECK_OFFSET(UICommunityQueryDialog, m_180, 0x180);
MS2_CHECK_OFFSET(UICommunityQueryDialog, m_188, 0x188);
MS2_CHECK_OFFSET(UICommunityQueryDialog, m_1a0, 0x1a0);
