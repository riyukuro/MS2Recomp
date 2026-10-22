// uipcbangdialog.h - UIPcBangDialog (RTTI .?AVUIPcBangDialog@@, 0x2b8 bytes; UI type 0x4ecf "PcBangDialog"): the PC
// bang (internet cafe) play-time bonus dialog, and the NotifyPcBang notice it posts. Recovered with ?\uipcbangdialog.cpp;
// header name and directory assumed (the exe has no __FILE__ for it). Vftable 0x142eebaa0 (overrides 0, 1, 20, 26, 28,
// 48, 49, 72), IMessageListener-in-UIDialog at +0x18. Ctor 0x141322c00, dtor 0x1413230d0 (??_G 0x141329500); the size
// is the operator new of CUIService::RegisterDialogs (0x141adf580).
// Member and non-virtual method names are invented from their use (the packet sub-codes, the AS method names).
#pragma once

#include <afx.h>
#include <atlcoll.h>
#include <vector>

#include "ms2/ms2layout.h"
#include "ms2/client/ms2/uidialog.h"
#include "ms2/commonfiles/itemgift.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/asuicomponent.h"
#include "ms2/placeholder/cbannerurlgetter.h"
#include "ms2/placeholder/notifyobject.h"
#include "ms2/placeholder/partybits.h"

class ASButton;
class ASData;
class ASObj;
class ASTextField;
class CInPacket;

// The notice posted when the PC bang state or the claimable bonus count changes (the name virtual GetTypeName 0x140db41f0
// lives with the other Notify* names in unnamed\unit_140da50e0.cpp). Ctor/dtor are inline COMDATs of this unit.
class NotifyPcBang : public NotifyObject
{
public:
    NotifyPcBang() {}                                       // 0x141328cf0
    virtual CStringW GetTypeName();                             // 1 0x140db41f0 "NotifyPcBang"
};
MS2_CHECK_SIZE(NotifyPcBang, 0x18);

// An interval check: FUN_140268870 is true once m_nInterval ms have passed since the last true (ctor inline here).
struct Unk_PcBangTimer
{
    Unk_PcBangTimer(int nInterval) : m_nInterval(nInterval), m_nLast(0) {}   // 0x141328d20
    int FUN_140268870(unsigned nMs);
    int m_nInterval;                                        // +0x00
    unsigned m_nLast;                                       // +0x04
};
MS2_CHECK_SIZE(Unk_PcBangTimer, 8);

// The "m_giftList" tile list (ASTileList: ASCoreList -> ASUIComponent); slots 16-24 are ASUIComponent's.
class Unk_PcBangGiftList : public ASUIComponent
{
public:
    virtual void vfunc_16();                                // 16 0x1422c7ec0
    virtual void vfunc_17();                                // 17 0x1422c7f00
    virtual void vfunc_18();                                // 18 0x1422c7f40
    virtual void vfunc_19();                                // 19 0x1422c7f80
    virtual void vfunc_20();                                // 20 0x1422c7fc0
    virtual void vfunc_21();                                // 21 0x1422c8000
    virtual void vfunc_22();                                // 22 0x1422c8040
    virtual void vfunc_23();                                // 23 0x1422dd090
    virtual void vfunc_24(bool bRefresh);                   // 24 0x1422c80c0 validateNow
    void FUN_1422dd230(const ASObj& row);                   // ASCoreList: append a row
};

class UIPcBangDialog : public UIDialog
{
public:
    UIPcBangDialog();                                                       // 0x141322c00
    virtual ~UIPcBangDialog();                                              //  0 0x1413230d0 (??_G 0x141329500)
    virtual CString GetTypeName();                                              //  1 0x141323490 "PcBangDialog"
    virtual void OnLoadInit();                                              // 20 0x1413234e0
    virtual void vfunc_26();                                                // 26 0x141323910
    virtual void vfunc_49(Scaleform::GFx::Value* pRetVal, ASData* pArgs);   // 49 0x1413239a0 "getTooltip"
    virtual void vfunc_72();                                                // 72 0x141323d60 per-frame update
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x141323e20
    virtual int vfunc_48() { return 0x4ecf; }                               // 48 (COMDAT 0x1413298e0)

    void OnPacket(CInPacket& packet);                       // 0x141323f40 packet 0xa5: the sub-code dispatch
    void OnPacketInfo(CInPacket& packet);                   // 0x141324010 0: the full state and the gift tables
    void OnPacketPlayed(CInPacket& packet);                 // 0x1413244d0 1: a play-time bonus was received
    void OnPacketReward(CInPacket& packet);                 // 0x1413246b0 2: a gift item was received
    void OnPacketStatus(CInPacket& packet);                 // 0x141324a50 3: the state without the tables
    void OnPacketNotice(CInPacket& packet);                 // 0x141324b40 5: a system notice
    void OnResetBonus(CInPacket& packet);                   // 0x141324c10 packet 0x10b
    void OnGameStart(NotifyObject* pNotify);                // 0x141324cf0 "NotifyGameStart"
    void OnChangeMyLevel(NotifyObject* pNotify);            // 0x141324d20 "NotifyChangeMyLevel"
    int GetState();                                         // 0x141324d60 m_nState
    int GetPcBangGrade();                                   // 0x141324d80 -1 until the info packet arrived
    int GetReceivableCount();                               // 0x141324db0 m_nReceivable
    void RefreshAll();                                      // 0x141324dd0
    void UpdatePcBangFlag();                                // 0x141324e30 "setPlayPcBang"
    void UpdatePlayTime();                                  // 0x141324ea0 "setPlayTime"
    void UpdateBuff();                                      // 0x141324f40 "setIcon" + "buffText"
    void UpdateBanner();                                    // 0x1413251c0 "setBanner"
    void UpdateRows();                                      // 0x1413252e0 the "m_timeBonus{0}" rows
    void UpdateProgress();                                  // 0x141325670 row colour / get buttons
    void RefreshGiftList();                                 // 0x141325950 "m_giftList"
    void FUN_141325d60();                                   // 0x141325d60 empty
    void OnClickItemGet(const Scaleform::GFx::FunctionHandler::Params& params);   // 0x141325d70 (user value = row)
    void OnClickBanner(const Scaleform::GFx::FunctionHandler::Params& params);    // 0x141325de0
    void ResetInfo();                                       // 0x141325e10
    unsigned GetPlayTime();                                 // 0x141325ee0 milliseconds
    CStringW GetPlayTimeText();                             // 0x141325f70
    void RebuildGiftOrder();                                // 0x141326040 m_gifts -> m_giftOrder by item level
    void RequestInfo();                                     // 0x141326540 packet 0x67, 3
    void UpdateReceivable();                                // 0x1413265a0
    int CountReachedBonus();                                // 0x1413266e0 play-time tiers already reached
    int IsPcBang();                                         // 0x1413267b0 m_nGrade > 0

    // Child lookups (UISwfEntity::GetChild<T> COMDATs, one per wrapper class).
    MS2Ptr<Unk_PcBangGiftList> FUN_140ba4b70(const CString& strName);

    int m_nState;                                           // +0x178 1 once the info packet arrived
    unsigned char m_nGrade;                                 // +0x17c PC bang grade (0: not a PC bang)
    int m_bGiftOrderDirty;                                  // +0x180 m_giftOrder must be rebuilt
    unsigned m_nStartTime;                                  // +0x184 server time the session started
    int m_nPlayTime;                                        // +0x188 play time before the session (ms)
    Unk_PartyBits m_received;                               // +0x18c received play-time bonuses (bit per tier)
    CString m_strBanner;                                    // +0x190 the banner file shown
    int m_nBuffId;                                          // +0x198 the PC bang buff (additional effect id)
    ATL::CAtlArray<MS2Ptr<PlayBonusItemGift> > m_playBonus; // +0x1a0 play-time bonus tiers
    ATL::CRBMap<unsigned, MS2Ptr<ItemGiftPcBang> > m_gifts; // +0x1c0 PC bang gift items by gift id
    std::vector<MS2Ptr<ItemGiftPcBang> > m_giftOrder;       // +0x1f0 m_gifts in display order
    int m_nReceivable;                                      // +0x208 reached but not received tiers
    Unk_PcBangTimer m_playTimeTimer;                        // +0x20c 30 s
    Unk_PcBangTimer m_receivableTimer;                      // +0x214 10 s
    CBannerUrlGetter m_banner;                              // +0x220
    MS2Ptr<Unk_PcBangGiftList> m_spGiftList;                // +0x258 "m_giftList"
    MS2Ptr<ASMovieClip> m_spBanner;                         // +0x268 "m_banner"
    ATL::CAtlArray<MS2Ptr<ASMovieClip> > m_rows;            // +0x278 "m_timeBonus{0}"
    ATL::CAtlArray<MS2Ptr<ASButton> > m_getButtons;         // +0x298 "itemGetButton" of each row
};
MS2_CHECK_OFFSET(UIPcBangDialog, m_nState, 0x178);
MS2_CHECK_OFFSET(UIPcBangDialog, m_received, 0x18c);
MS2_CHECK_OFFSET(UIPcBangDialog, m_playBonus, 0x1a0);
MS2_CHECK_OFFSET(UIPcBangDialog, m_gifts, 0x1c0);
MS2_CHECK_OFFSET(UIPcBangDialog, m_giftOrder, 0x1f0);
MS2_CHECK_OFFSET(UIPcBangDialog, m_playTimeTimer, 0x20c);
MS2_CHECK_OFFSET(UIPcBangDialog, m_banner, 0x220);
MS2_CHECK_OFFSET(UIPcBangDialog, m_rows, 0x278);
MS2_CHECK_SIZE(UIPcBangDialog, 0x2b8);
