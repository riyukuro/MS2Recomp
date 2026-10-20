// uipartydialog.h - the party UI unit (client\ms2\uipartydialog.cpp, 0x141a738f0-0x141a8f3a0): ASPartyVotePage (the vote
// panel of the party window), UIPartyDialog (RTTI .?AVUIPartyDialog@@, 0x1e8, UI id 0x4e33?, swf "PartyDialog"),
// UIPartyDPSDialog, UIPerformanceDialog, UIPopupEntity (placeholder/uipopupentity.h) and UIPopUpMenu.
// Header name assumed from the unit path. Member names other than the RTTI class names and the swf child names are
// inferred (w506).
#pragma once
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/intervaltimer.h"
#include <vector>

class ASMovieClip;
class ASTextField;
class ASButton;
class ASObj;
class ASData;
class UIMsg;
class CInPacket;
class CMsgBoxData;
class CPartyMember;

// The vote panel inside the party window ("m_partyVote"). ctor 0x141a738f0, operator new 0x88 (UIPartyDialog::OnLoadComplete).
class ASPartyVotePage : public CPtred
{
public:
    ASPartyVotePage(MS2Ptr<ASMovieClip> spPage);                // 0x141a738f0
    virtual ~ASPartyVotePage();                                 //  0 0x141a739c0 (??_G 0x141a7a9f0)
    void OnInit();                                              // 0x141a73a70 bind the children, hook the buttons
    void FUN_141a74760();                                       // refresh from the current party vote
    void FUN_141a74a60(const Scaleform::GFx::FunctionHandler::Params& params);    // "m_yesButton" click
    void FUN_141a74a90(const Scaleform::GFx::FunctionHandler::Params& params);    // "m_noButton" click
    void FUN_141a74ac0(bool bYes);                              // send the vote

    MS2_LAYOUT_FRIEND;
    MS2Ptr<ASMovieClip> m_page;                                 // +0x18
    MS2Ptr<ASTextField> m_title;                                // +0x28 "m_title"
    MS2Ptr<ASTextField> m_yesCount;                             // +0x38 "m_yesCount"
    MS2Ptr<ASTextField> m_noCount;                              // +0x48 "m_noCount"
    MS2Ptr<ASButton> m_yesButton;                               // +0x58 "m_yesButton"
    MS2Ptr<ASButton> m_noButton;                                // +0x68 "m_noButton"
    MS2Ptr<ASTextField> m_votedText;                            // +0x78 "m_votedText"
};
MS2_CHECK_SIZE(ASPartyVotePage, 0x88);
MS2_CHECK_OFFSET(ASPartyVotePage, m_page, 0x18);
MS2_CHECK_OFFSET(ASPartyVotePage, m_votedText, 0x78);

// The party window. ctor 0x141a74b40, operator new 0x1e8 (sized delete in ??_G 0x141a7aa30).
class UIPartyDialog : public UIDialog
{
public:
    UIPartyDialog();                                            // 0x141a74b40
    virtual ~UIPartyDialog();                                   //  0 0x141a74c50 (??_G 0x141a7aa30)
    virtual CString vfunc_1();                                  //  1 0x141a74d00 "PartyDialog"
    virtual void vfunc_15();                                    // 15 0x141a769d0 once a second: vote refresh, deadline
    virtual void OnLoadComplete();                              // 22 0x141a75a80
    virtual void vfunc_26();                                    // 26 0x141a767d0 unbind
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x141a76a80
    virtual void vfunc_45(Scaleform::GFx::Value* pRetVal, const CString& strMethod, ASData* pArgs);       // 45 0x141a76ff0 "getTooltip"
    virtual int vfunc_48();                                     // 48 0x141a7aa70 UI id
    virtual int OnMessage(UISwfEntity* pSender, UIMsg* pMsg);   // IMessageListener 0 0x141a774d0 "buy_scroll" box answer

    void FUN_141a74d50(CPartyMember* pMember, int nFlags);      // "updateMember"
    void FUN_141a74ea0();                                       // update every member (flags 0x180)
    void FUN_141a74f50(CPartyMember* pOld, CPartyMember* pNew); // "changeChief"
    int FUN_141a752a0(CPartyMember* pMember);                   // "addMember"
    int FUN_141a753d0(CPartyMember* pMember);                   // "removeMember"
    int FUN_141a75490(__int64 nCharId, float* pPos);            // "getCameraButtonPos" (adds it to pPos)
    int FUN_141a75680(float* pPos);                             // the first other member's camera button
    bool FUN_141a75840();                                       // "isCanObserveMode"
    void FUN_141a759b0();                                       // refresh the vote panel
    void FUN_141a75a00(unsigned int nDeadline);                 // m_deadline = n
    void FUN_141a75a20();                                       // "arrangeBottomButton"
    bool FUN_141a77600(int nResult, const CMsgBoxData& box);    // create club box answer
    bool FUN_141a776e0(int nResult, const CMsgBoxData& box);    // give up box answer
    void FUN_141a77760(float x, float y, __int64 nCharId);      // the slot popup menu
    void FUN_141a77980(CInPacket& packet);                      // party packet (0x53)
    void FUN_141a77a40(CInPacket& packet);                      // packet 0x100
    void FUN_141a77ab0(const Scaleform::GFx::FunctionHandler::Params& params);    // "m_enterDungeon"
    void FUN_141a77ae0(const Scaleform::GFx::FunctionHandler::Params& params);    // "m_createClub"
    void FUN_141a77dd0(const Scaleform::GFx::FunctionHandler::Params& params);    // "m_giveUpDungeon"
    bool FUN_141a77eb0();                                       // the recall checks
    void FUN_141a783d0(__int64 nItemUid);                       // use the recall scroll
    int FUN_141a784b0(ASObj& obj, CPartyMember* pMember, unsigned int nFlags);    // fill the member object
    void FUN_141a792b0();                                       // refresh everything, "initMembers"
    void FUN_141a794e0();                                       // m_enterDungeon state
    void FUN_141a79570();                                       // dungeon name
    void FUN_141a796b0();                                       // m_recall state
    void FUN_141a79770();                                       // m_createClub state
    void FUN_141a79840();                                       // m_giveUpDungeon state

    MS2_LAYOUT_FRIEND;
    MS2Ptr<ASButton> m_enterDungeon;                            // +0x178 "m_enterDungeon"
    MS2Ptr<ASButton> m_recall;                                  // +0x188 "m_recall"
    MS2Ptr<ASButton> m_createClub;                              // +0x198 "m_createClub"
    MS2Ptr<ASButton> m_giveUpDungeon;                           // +0x1a8 "m_giveUpDungeon"
    MS2Ptr<ASMovieClip> m_dungeonName;                          // +0x1b8 "m_dungeonName"
    MS2Ptr<ASPartyVotePage> m_vote;                             // +0x1c8 "m_partyVote"
    Unk_IntervalTimer m_timer;                                  // +0x1d8
    unsigned int m_deadline;                                    // +0x1e0
};
MS2_CHECK_SIZE(UIPartyDialog, 0x1e8);
MS2_CHECK_OFFSET(UIPartyDialog, m_enterDungeon, 0x178);
MS2_CHECK_OFFSET(UIPartyDialog, m_vote, 0x1c8);
MS2_CHECK_OFFSET(UIPartyDialog, m_deadline, 0x1e0);

// ======== UIPartyDPSDialog ========
// The party damage meter (UI id 0x4e8c, swf "PartyDPSDialog"): the same window as UIChaosDPSDialog
// (uichaosdpsdialog.h) for battle record group 1. ctor 0x141a7b050, operator new 0x1a0.
class UIPartyDPSDialog : public UIDialog
{
public:
    UIPartyDPSDialog();                                         // 0x141a7b050
    virtual ~UIPartyDPSDialog();                                //  0 0x141a7b100 (??_G 0x141a7c470)
    virtual CString vfunc_1();                                  //  1 0x141a7b150 "PartyDPSDialog"
    virtual void OnLoadComplete();                              // 22 0x141a7bc10
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x141a7bc70
    virtual int vfunc_48();                                     // 48 0x141a7c4b0
    virtual void vfunc_67();                                    // 67 0x141a7bbf0
    virtual void vfunc_72();                                    // 72 0x141a7c210

    bool FUN_141a7b1a0(ASObj& obj, CPartyMember* pMember, unsigned int nRank);    // fill one meter row
    void FUN_141a7b3c0();                                       // title bar and sort direction
    void FUN_141a7b540();                                       // rebuild the ranking
    void FUN_141a7bb70();                                       // "RemoveMember"

    MS2_LAYOUT_FRIEND;
    Unk_IntervalTimer m_tick;                                   // +0x178
    std::vector<MS2Ptr<CPartyMember> > m_members;               // +0x180 the ranking
    int m_nGroup;                                               // +0x198 battle record group (1)
    int m_nMode;                                                // +0x19c value kind shown
};
MS2_CHECK_SIZE(UIPartyDPSDialog, 0x1a0);
MS2_CHECK_OFFSET(UIPartyDPSDialog, m_members, 0x180);
MS2_CHECK_OFFSET(UIPartyDPSDialog, m_nMode, 0x19c);

// ======== UIPerformanceDialog ========
// The frame rate overlay (UI id 0x4e7d, swf "PerformanceDialog"). ctor 0x141a7c4c0, operator new 0x188.
class UIPerformanceDialog : public UIDialog
{
public:
    UIPerformanceDialog();                                      // 0x141a7c4c0
    virtual ~UIPerformanceDialog();                             //  0 0x141a7c560 (??_G 0x141a7caa0)
    virtual CString vfunc_1();                                  //  1 0x141a7c5b0 "PerformanceDialog"
    virtual void OnLoadComplete();                              // 22 0x141a7c600
    virtual void vfunc_26();                                    // 26 0x141a7c6a0
    virtual int vfunc_48();                                     // 48 0x141a7cae0
    virtual void vfunc_72();                                    // 72 0x141a7c6e0 "{0:0.1f}({1})" fps / draw count

    MS2_LAYOUT_FRIEND;
    MS2Ptr<ASTextField> m_text;                                 // +0x178 "m_text"
};
MS2_CHECK_SIZE(UIPerformanceDialog, 0x188);

// ======== UIPopUpMenu ========
// The right click menu of players / members (UI id 0x4e39). RTTI .?AVUIPopUpMenu@@, ctor 0x141a7d580, dtor 0x141a88510,
// operator new 0x200 (CUIService::RegisterDialogs). Bases UIHeadUpDisplay +0, UIEntityEventListener +0x70,
// UIUGCEventListener +0x78. Other units reach it as FUN_140c30140(0x4e39) and include ms2/placeholder/uipopupmenu.h.

#include <atlcoll.h>
#include <NiPoint3.h>
#include "ms2/placeholder/uiheadupdisplay.h"
#include "ms2/placeholder/uientityeventlistener.h"
#include "ms2/placeholder/uiugceventlistener.h"
#include "ms2/client/ms2/alphaanimation.h"     // Delegate<void()>

extern NiPoint3 DAT_143b01a60;                              // zero position

class ASScrollingList;
class PCBase;

// The menu request (callers build it on the stack). ctor 0x140c302f0, dtor 0x140c304c0; the two tails are also members
// of UIPopUpMenu (+0x1a8 / +0x1d0).
class Unk_PopupMenuInfo
{
public:
    Unk_PopupMenuInfo(float x, float y, int a, int b, int c, CString str, void* p);   // 0x140c302f0
    ~Unk_PopupMenuInfo() {}                                         // 0x140c304c0
    struct Unk_PmA                                                  // ctor 0x140c30440, dtor 0x140c30550
    {
        Unk_PmA() : m_00(0), m_08(0), m_10(L""), m_18(0), m_20(0) {}
        __int64 m_00; __int64 m_08; CStringW m_10; int m_18; __int64 m_20;
    };
    struct Unk_PmB                                                  // ctor 0x140c303c0, dtor 0x140c30510
    {
        Unk_PmB() : m_00(0), m_08(0), m_10(L""), m_18(0), m_20(L"") {}
        __int64 m_00; int m_08; CStringW m_10; __int64 m_18; CStringW m_20;
        __int64 m_28;                                                 // not set by the ctor
    };
    float m_x, m_y;
    int m_a, m_b, m_c;
    CString m_str;
    void* m_p;
    Unk_PmA m_infoA;
    Unk_PmB m_infoB;
};
MS2_CHECK_SIZE(Unk_PopupMenuInfo, 0x80);

// The target of a menu (a stack value built by the PopUpMenu* entry points, passed to FUN_141a82140). Ctor/dtor are inline
// COMDATs (0x141a882d0 / 0x141a884d0).
struct Unk_PmTarget
{
    Unk_PmTarget() : m_pos(DAT_143b01a60), m_nLevel(0), m_nCharId(0), m_bOnline(1), m_nTrophy(0), m_n20(0), m_nJobCode(0), m_b38(false) {}
    NiPoint3 m_pos;                     // +0x00 world (or screen) position
    unsigned m_nLevel;                  // +0x0c "level"
    __int64 m_nCharId;                  // +0x10
    int m_bOnline;                      // +0x18
    int m_nTrophy;                      // +0x1c "trophy"
    int m_n20;                          // +0x20
    int m_nJobCode;                     // +0x24 "jobcode"
    CString m_strImage;                 // +0x28 "imgpath"
    CStringW m_strName;                 // +0x30 "name"
    bool m_b38;                         // +0x38
};
MS2_CHECK_SIZE(Unk_PmTarget, 0x40);

class CProxyGameObject;
class CUgcRegistBanner;
class CClubMember;
class CGuildMember;
class CBuddy;
class MyPC;
class GameObject;
class ASArray;
class CMsgBoxData;
class CInPacket;
template <class T> class Unk_PayloadPtr;
struct HomeBlockInfo;
class Unk_PmUserEntry;

class UIPopUpMenu : public UIHeadUpDisplay, public UIEntityEventListener, public UIUGCEventListener
{
public:
    UIPopUpMenu();                                              // 0x141a7d580 (the dtor is implicit: 0x141a88510, ??_G 0x141a888d0)
    virtual CString vfunc_1();                                  //  1 0x141a7d850 "PopUpMenu"
    virtual void vfunc_2();                                     //  2 0x141a7d8a0
    virtual void vfunc_3();                                     //  3 0x141a7d960
    virtual int vfunc_13();                                     // 13 0x141a7dc90
    virtual void vfunc_15();                                    // 15 0x141a7daf0
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x141a7da20
    virtual int vfunc_48() { return 0x4e39; }                   // 48 0x141a88d40 (inline)
    virtual int OnMessage(UISwfEntity* pSender, UIMsg* pMsg);   // IMessageListener 0 0x141a7dd30
    virtual void vfunc_o70_2(const void* pId);                  // UIEntityEventListener 2 0x141a7dc20 (an efd::UniversalID)
    virtual void vfunc_4(void* pProxy);                         // UIEntityEventListener 4 0x141a7df60 (a by-value MS2Ptr<CProxyGameObject>)
    virtual void vfunc_ugc_1(void* pId, CString strImage);      // UIUGCEventListener 1 0x141a7e1a0
    // ---- non-virtual members (sorted by address) ----
    bool FUN_141a7e020(int nButton, const CMsgBoxData& data);   // report confirm
    bool FUN_141a7e0a0(int nButton, const CMsgBoxData& data);   // party vote kick confirm
    bool FUN_141a7e100(int nButton, const CMsgBoxData& data);   // wedding propose confirm
    void FUN_141a7e280(const Unk_PopupMenuInfo& info, PCBase* pTarget, int nType);     // PopUpMenu
    void FUN_141a7e870(const Unk_PopupMenuInfo& info, PCBase* pTarget, int nType);     // PopUpMenu (fitting / npc)
    void FUN_141a7eb60(const Unk_PopupMenuInfo& info, MS2Ptr<CProxyGameObject> spProxy, int nType);
    void FUN_141a7f090(const Unk_PopupMenuInfo& info, const CStringW& strName, unsigned __int64 nCharId, void* pAccount, int nType, int nDir);
    void FUN_141a7f190(const Unk_PopupMenuInfo& info, CPartyMember* pMember);         // PopUpMenuFromPartyMember
    void FUN_141a7f510(const Unk_PopupMenuInfo& info, CGuildMember* pMember);         // PopUpMenuFromGuildMember
    void FUN_141a7f890(const Unk_PopupMenuInfo& info, Unk_PmUserEntry* pEntry, const CStringW& strText, int nType);
    void FUN_141a7f950(const Unk_PopupMenuInfo& info, __int64 nBuddyId);
    void FUN_141a7fc50(const Unk_PopupMenuInfo& info, __int64 nHomeId);
    void FUN_141a7ff60(const Unk_PopupMenuInfo& info, int nIndex, MS2Ptr<CUgcRegistBanner> spBanner);
    void FUN_141a80210(const Unk_PopupMenuInfo& info, CClubMember* pMember);          // PopUpMenuFromClubMember
    void FUN_141a805f0(const Unk_PopupMenuInfo& info, void* pAccount, unsigned __int64 nCharId, const CStringW& strName, const CStringW& strText, int nType);
    void FUN_141a80670(const Unk_PopupMenuInfo& info);
    void FUN_141a80770();                                       // close
    int FUN_141a80880();                                        // m_100 (closed)
    __int64 FUN_141a808a0();                                    // m_a8
    CString FUN_141a808c0();                                    // the request key (m_88)
    void FUN_141a80910();                                       // copy the own guild
    void FUN_141a809e0(__int64 nGuildId, const CStringW& strGuild, const CString& strMark);
    void FUN_141a80a50(CInPacket& packet);                      // packet 0x53
    void FUN_141a80af0(const Unk_PopupMenuInfo& info);          // take the request
    void FUN_141a80c40();                                       // register the menu handlers
    int FUN_141a82140(const Unk_PmTarget& target, int nFlags, int nType);   // Open
    int FUN_141a828a0(CStringW strName, const Unk_PopupMenuInfo& info, int nMode, int nDir);   // OpenFromCharName
    void FUN_141a82dd0();                                       // reset
    int FUN_141a82ed0(GameObject* pObject, NiPoint3& out, float fDir);
    int FUN_141a82f30(const NiPoint3& pos, NiPoint3& out, float fDir);
    void FUN_141a82fb0(const CString& strImage);
    int FUN_141a83080(GameObject* pObject);                     // target kind
    void FUN_141a832e0(GameObject* pObject, CStringW& strName);
    int FUN_141a834e0(unsigned nFlags, int nType, const CStringW& strName, int nDir);
    int FUN_141a83810(unsigned nFlags, int nType, const Unk_PmTarget& target);
    float FUN_141a83db0();                                      // camera height offset
    void FUN_141a83ed0(int nQuery, int nKind);
    void FUN_141a84130(int nQuery, int nKind);
    void FUN_141a842f0();
    void FUN_141a84320(ASArray& menu);
    void FUN_141a844a0(unsigned nMenuId);                       // AddPopupMenu
    void FUN_141a84520(int nType, int bOnline, __int64 nCharId);
    void FUN_141a84590(int nType, MyPC* pMe, const CStringW& strName, int bOnline);
    void FUN_141a847c0(int nType, MyPC* pMe, CBuddy* pBuddy);
    void FUN_141a84860(int nType, MyPC* pMe, CBuddy* pBuddy);
    void FUN_141a848d0(int nType, int bOnline, __int64 nCharId);
    void FUN_141a84940(int nType, int bOnline);
    void FUN_141a84980(int nType, int bOnline);
    void FUN_141a849c0(int nType, __int64 nCharId);
    void FUN_141a84a10(int nType, __int64 nCharId);
    void FUN_141a84a60(int nType);
    void FUN_141a84a90(int nType);
    void FUN_141a84ac0(int nType, __int64 nCharId);
    void FUN_141a84b10(int nType);
    void FUN_141a84b40(int nType, MyPC* pMe, const CStringW& strName);
    void FUN_141a84c60(int nType, MyPC* pMe, __int64 nCharId);
    void FUN_141a84cb0(int nType, MyPC* pMe, Unk_PayloadPtr<HomeBlockInfo> spHome);
    // menu handlers (m_160)
    void FUN_141a84d40();
    void FUN_141a84da0();
    void FUN_141a84df0();
    void FUN_141a84f60();
    void FUN_141a84f90();
    void FUN_141a85010();
    void FUN_141a85120();
    void FUN_141a85230();
    void FUN_141a853a0();
    void FUN_141a853c0();
    void FUN_141a85410();
    void FUN_141a85460();
    void FUN_141a854b0();
    void FUN_141a85500();
    void FUN_141a85680();
    void FUN_141a85760();
    void FUN_141a86920();
    void FUN_141a86970();
    void FUN_141a86a50();
    void FUN_141a86ad0();
    void FUN_141a86b80();
    void FUN_141a86bd0();
    void FUN_141a86ca0();
    void FUN_141a86d20();
    void FUN_141a86db0();
    void FUN_141a86e40();
    void FUN_141a86ed0();
    void FUN_141a86f50();
    void FUN_141a87100();
    void FUN_141a87150();
    void FUN_141a871a0();

    MS2_LAYOUT_FRIEND;
    int m_80;                                                   // menu kind (1: on a world object, 2/3: at the cursor)
    int m_84;                                                   // AS "type"
    CString m_88;                                               // request key
    CStringW m_90;                                              // target name
    unsigned __int64 m_98;                                      // target object id
    __int64 m_a0;                                               // target account id
    __int64 m_a8;                                               // target character id
    CStringW m_b0;                                              // target name (report)
    __int64 m_b8;                                               // ugc banner id
    CString m_c0;                                               // ugc banner text
    int m_c8;                                                   // ugc banner index
    __int64 m_d0;                                               // buddy id
    __int64 m_d8;                                               // home block id
    NiPoint3 m_e0;
    MS2Ptr<ASScrollingList> m_f0;                               // the open menu list
    int m_100;                                                  // closed
    CStringW m_108;                                             // report text
    int m_110;                                                  // report kind
    ATL::CAtlArray<unsigned int> m_118;                         // menu ids of the open menu
    __int64 m_138;                                              // guild id
    CStringW m_140;                                             // guild name
    CString m_148;                                              // guild mark
    void* m_150;
    CString m_158;                                              // profile image
    ATL::CAtlMap<int, Delegate<void()> > m_160;                 // menu id -> handler
    Unk_PopupMenuInfo::Unk_PmA m_1a8;
    Unk_PopupMenuInfo::Unk_PmB m_1d0;
};
MS2_CHECK_SIZE(UIPopUpMenu, 0x200);
MS2_CHECK_OFFSET(UIPopUpMenu, m_80, 0x80);
MS2_CHECK_OFFSET(UIPopUpMenu, m_e0, 0xe0);
MS2_CHECK_OFFSET(UIPopUpMenu, m_118, 0x118);
MS2_CHECK_OFFSET(UIPopUpMenu, m_160, 0x160);
MS2_CHECK_OFFSET(UIPopUpMenu, m_1a8, 0x1a8);
