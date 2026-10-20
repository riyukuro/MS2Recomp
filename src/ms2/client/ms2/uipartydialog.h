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
        void* m_00; void* m_08; CStringW m_10; int m_18; void* m_20;
    };
    struct Unk_PmB                                                  // ctor 0x140c303c0, dtor 0x140c30510
    {
        Unk_PmB() : m_00(0), m_08(0), m_10(L""), m_18(0), m_20(L"") {}
        void* m_00; int m_08; CStringW m_10; void* m_18; CStringW m_20;
        void* m_28;                                                 // not set by the ctor
    };
    float m_x, m_y;
    int m_a, m_b, m_c;
    CString m_str;
    void* m_p;
    Unk_PmA m_infoA;
    Unk_PmB m_infoB;
};
MS2_CHECK_SIZE(Unk_PopupMenuInfo, 0x80);

class UIPopUpMenu : public UIHeadUpDisplay, public UIEntityEventListener, public UIUGCEventListener
{
public:
    UIPopUpMenu();                                              // 0x141a7d580
    virtual ~UIPopUpMenu();                                     //  0 0x141a88510 (??_G 0x141a888d0)
    virtual CString vfunc_1();                                  //  1 0x141a7d850 "PopUpMenu"
    virtual void vfunc_2();                                     //  2 0x141a7d8a0
    virtual void vfunc_3();                                     //  3 0x141a7d960
    virtual int vfunc_13();                                     // 13 0x141a7dc90
    virtual void vfunc_15();                                    // 15 0x141a7daf0
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x141a7da20
    virtual int vfunc_48();                                     // 48 0x141a88d40
    virtual int OnMessage(UISwfEntity* pSender, UIMsg* pMsg);   // IMessageListener 0 0x141a7dd30
    virtual void vfunc_o70_2(const void* p);                    // UIEntityEventListener 2 0x141a7dc20
    virtual void vfunc_4(void* p);                              // UIEntityEventListener 4 0x141a7df60
    virtual void vfunc_ugc_1(void* p, CString str);             // UIUGCEventListener 1 0x141a7e1a0
    // ---- non-virtual members (sorted by address) ----
    void FUN_141a7e280(const Unk_PopupMenuInfo& info, PCBase* pTarget, int nType);
    void FUN_141a7f190(const Unk_PopupMenuInfo& info, CPartyMember* pMember);
    void FUN_141a80770();                                       // close
    int FUN_141a80880();                                        // m_80
    CString FUN_141a808c0();                                    // the request key (m_88)

    MS2_LAYOUT_FRIEND;
    int m_80;
    int m_84;
    CString m_88;
    CStringW m_90;
    void* m_98;
    void* m_a0;
    void* m_a8;
    CStringW m_b0;
    void* m_b8;
    CString m_c0;
    int m_c8;
    void* m_d0;
    void* m_d8;
    NiPoint3 m_e0;
    MS2Ptr<ASScrollingList> m_f0;
    int m_100;
    CStringW m_108;
    int m_110;
    ATL::CAtlArray<void*> m_118;                                // element type unrecovered
    void* m_138;
    CStringW m_140;
    CString m_148;
    void* m_150;
    CString m_158;
    ATL::CAtlMap<int, int> m_160;                               // key/value types unrecovered (17 bins)
    Unk_PopupMenuInfo::Unk_PmA m_1a8;
    Unk_PopupMenuInfo::Unk_PmB m_1d0;
};
MS2_CHECK_SIZE(UIPopUpMenu, 0x200);
MS2_CHECK_OFFSET(UIPopUpMenu, m_80, 0x80);
MS2_CHECK_OFFSET(UIPopUpMenu, m_e0, 0xe0);
MS2_CHECK_OFFSET(UIPopUpMenu, m_118, 0x118);
MS2_CHECK_OFFSET(UIPopUpMenu, m_160, 0x160);
MS2_CHECK_OFFSET(UIPopUpMenu, m_1a8, 0x1a8);
