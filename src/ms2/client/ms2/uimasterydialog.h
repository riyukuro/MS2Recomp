// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Header name assumed.
//
// UIMasteryDialog: the "MasteryDialog" (manufacturing / housing / magic scroll mastery windows: category tabs, the
// mastery list, the required-material and reward slots and the craft progress casting bar). RTTI
// .?AVUIMasteryDialog@@, 0x340 bytes, four vftables: the UIDialog primary (0x0), IMessageListener (+0x18),
// ICastingEventListener (+0x178) and UIItemEventListener (+0x180).
// Names: virtuals are Ghidra's vfunc_<slot> where the base does so; FUN_<va> are non-virtual members.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/icastingeventlistener.h"
#include "ms2/placeholder/uiitemeventlistener.h"
#include "ms2/placeholder/itemslotbinder.h"
#include "ms2/placeholder/ascript.h"

class ASData;
class ASArray;
class ASObj;
class Unk_MLevelCtrl;
class Unk_MList;
class Unk_MSubTab;
class Unk_MGroup;
class Unk_MScroll;
class Unk_MRec;
class Unk_MFurn;
class CMsgBoxData;
class NotifyObject;
struct ItemEntity;
template <class T> class MS2Ptr;

// The craft in progress (the casting bar): type 0 = magic scroll, 1 = manufacturing, 2 = none.
struct Unk_MasteryCraft
{
    Unk_MasteryCraft();                 // 0x140eadd70
    void FUN_140eadda0();               // reset: type 2, the rest 0
    BOOL FUN_140eaddf0();               // type == 0
    BOOL FUN_140eade30();               // type == 1
    BOOL HasTotal();               // m_nTotal != 0
    int m_nType;
    int m_nTotal;
    int m_nDone;
    int m_nId;
    int m_nPending;
};
MS2_CHECK_SIZE(Unk_MasteryCraft, 0x14);

class UIMasteryDialog : public UIDialog, public ICastingEventListener, public UIItemEventListener
{
public:
    UIMasteryDialog();                                                                              // 0x140eadeb0
    virtual ~UIMasteryDialog();                                                                     //  0 0x140eae2d0
    virtual CString GetTypeName();                                                                      //  1 0x140eae470
    virtual void OnLoadComplete();                                                                  // 22 0x140eae8a0
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
                                                                                                    // 28 0x140eaf090
    virtual int vfunc_48() { return 0x4f1e; }                                                         // 48 (COMDAT 0x140ebb0f0)
    virtual void vfunc_49(Scaleform::GFx::Value* pRetVal, ASData* pArgs);                           // 49 0x140eaed30 tooltips
    virtual int vfunc_65();                                                                         // 65 0x140eae4c0
    virtual void vfunc_67();                                                                        // 67 0x140eae520
    virtual void vfunc_72();
    virtual void vfunc_2(void* pArg);                                                               // o180 2 0x140eb4f60
    virtual void vfunc_4(void* pArg, int);                                                          // o180 4 0x140eb4fd0                                                                        // 72 0x140eafa50 per-frame
    virtual void OnCastingFinished();                                                               // o178 0 0x140eaf840
    virtual void OnCastingCancelled();                                                              // o178 1 0x140eafa10

    // ---- non-virtual members, sorted by address ----
    void SetMainTab(int nMainTab);  // 0x140eafdb0
    void FUN_140eafde0();  // 0x140eafde0
    void FUN_140eb0540();  // 0x140eb0540
    void FUN_140eb05b0(int nType, bool bKeep);  // 0x140eb05b0
    void FUN_140eb0610(int nType, bool bKeep);  // 0x140eb0610
    void FUN_140eb0bf0(int nType, int nIndex);  // 0x140eb0bf0
    void FUN_140eb0da0(int nType, bool bKeep);  // 0x140eb0da0
    void FUN_140eb1770(int nId, bool bKeep);  // 0x140eb1770
    void FUN_140eb2460();  // 0x140eb2460
    void FUN_140eb24a0();  // 0x140eb24a0
    void FUN_140eb2d10();  // 0x140eb2d10
    void FUN_140eb3010(int nId);  // 0x140eb3010
    void FUN_140eb3460();  // 0x140eb3460
    void FUN_140eb4210(int nId);  // 0x140eb4210
    void FUN_140eb4ba0();  // 0x140eb4ba0
    void FUN_140eb4be0();  // 0x140eb4be0
    void FUN_140eb4c10(int nType, int bRefreshTabs);  // 0x140eb4c10
    bool FUN_140eb4c70(int nResult, const CMsgBoxData& box);  // 0x140eb4c70
    bool FUN_140eb4d40(int nResult, const CMsgBoxData& box);  // 0x140eb4d40
    bool FUN_140eb4e30(int nResult, const CMsgBoxData&);  // 0x140eb4e30
    int FUN_140eb5040();  // 0x140eb5040
    int FUN_140eb5150();  // 0x140eb5150
    void FUN_140eb5260(int nType);  // 0x140eb5260
    void FUN_140eb52c0(int nType);  // 0x140eb52c0
    void FUN_140eb5320(NotifyObject* pNotify);  // 0x140eb5320
    void FUN_140eb53a0();  // 0x140eb53a0
    void FUN_140eb5450(int nIndex);  // 0x140eb5450
    void FUN_140eb55e0(int nId);  // 0x140eb55e0
    void FUN_140eb5e30(int nId);  // 0x140eb5e30
    void FUN_140eb5e60(int nId);  // 0x140eb5e60
    void FUN_140eb6660(void* pArg);  // 0x140eb6660
    int FUN_140eb6870();  // 0x140eb6870
    void FUN_140eb6920(int nType, int nIndex, ASObj& obj);  // 0x140eb6920
    void FUN_140eb6c80();  // 0x140eb6c80
    int FUN_140eb6d40(int nKind, int nId);  // 0x140eb6d40
    CStringW FUN_140eb71a0(MS2Ptr<Unk_MRec> spRec);  // 0x140eb71a0
    int FUN_140eb79b0(int nType, unsigned int nNeedMastery, ItemEntity* pEntry);  // 0x140eb79b0
    unsigned __int64 FUN_140eb7b40(int nType, int nNeedMastery, unsigned int nCount);  // 0x140eb7b40
    unsigned __int64 FUN_140eb7bb0(int nType);  // 0x140eb7bb0
    void FUN_140eb7c00(int nType);  // 0x140eb7c00
    CStringW FUN_140eb7c50(int nType);  // 0x140eb7c50
    CStringW FUN_140eb7d40();  // 0x140eb7d40
    void FUN_140eb7e30();  // 0x140eb7e30
    int FUN_140eb8120(MS2Ptr<Unk_MRec> spRec);  // 0x140eb8120
    int FUN_140eb82e0();  // 0x140eb82e0
    int FUN_140eb8410();  // 0x140eb8410
    int FUN_140eb8550(MS2Ptr<Unk_MRec> spRec);  // 0x140eb8550
    int FUN_140eb8630(int nType);  // 0x140eb8630
    void FUN_140eb8670(int nType, int nValue);  // 0x140eb8670
    int FUN_140eb86b0();  // 0x140eb86b0
    int FUN_140eb89e0(int nSlot);  // 0x140eb89e0
    int FUN_140eb8a90();  // 0x140eb8a90
    int FUN_140eb8ac0();  // 0x140eb8ac0
    void FUN_140eb8b20();  // 0x140eb8b20
    static int FUN_140eb8f40(const void* pA, const void* pB);  // 0x140eb8f40
    static int FUN_140eb9160(const void* pA, const void* pB);  // 0x140eb9160

    MS2Ptr<Unk_MLevelCtrl> FUN_140c02990(const CString& strName);   // child lookup
    MS2Ptr<Unk_MList> FUN_140c02900(const CString& strName);
    MS2Ptr<Unk_MSubTab> FUN_140c02870(const CString& strName);
    MS2Ptr<Unk_MGroup> FUN_140eb9db0(const CString& strName);

private:
    MS2_LAYOUT_FRIEND;
    ItemSlotBinder m_mastery;           // +0x188 "MasteryDialog_Mastery"
    ItemSlotBinder m_reward;            // +0x1c8 "MasteryDialog_Reward"
    ItemSlotBinder m_require;           // +0x208 "MasteryDialog_Require"
    MS2Ptr<Unk_MScroll> m_magicScroll;  // +0x248 (16 bytes, pointer at +0x250)
    int m_lastSelected[4];              // +0x258 "m_lastSelectedIndex" per main tab
    int m_268[14];                      // +0x268
    int m_scroll[14];                   // +0x2a0 scroll position per category
    int m_nMainTab;                     // +0x2d8 "m_mainTab" selectedIndex
    int m_2dc;
    int m_nSelected;                    // +0x2e0
    Unk_MasteryCraft m_craft;           // +0x2e4
    int m_2f8;                          // +0x2f8 6, or 10 with feature 0xd1
    int m_nPendingSub;                  // +0x2fc
    int m_nPendingList;                 // +0x300
    int m_304;                          // +0x304
    int m_308;                          // +0x308
    int m_30c;                          // +0x30c
    int m_310[12];                      // +0x310 per-slot values
};
MS2_CHECK_SIZE(UIMasteryDialog, 0x340);
MS2_CHECK_OFFSET(UIMasteryDialog, m_mastery, 0x188);
MS2_CHECK_OFFSET(UIMasteryDialog, m_craft, 0x2e4);
