// uipetsystemdialog.h - UIPetSystemDialog (RTTI .?AVUIPetSystemDialog@@, 0x1e0 bytes, bases UIDialog and
// UIItemEventListener at +0x178; UI id 0x4f38, swf "PetSystemDialog"): the pet window with the info / compose / evolution /
// remake option / collect tabs. Ctor 0x140e73440, dtor 0x140e6d9b0 (inline, emitted by uiotherpetsystemdialog.cpp;
// ??_G 0x140e75470). UIOtherPetSystemDialog (another player's pet) derives from it. Recovered with the queue unit
// ?\uiotherpetsystemdialog.cpp (TU 0x140e733a0-0x140e75ea0); header name assumed.
//
// The tabs live in a map (tab index -> TabInfo); each TabInfo owns its page (a PetSystemTabContents created by a factory
// that checks the feature switches). m_188 is the shown page; the dialog forwards its events to it.
#pragma once

#include <afx.h>
#include <atlcoll.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/uiitemeventlistener.h"
#include "ms2/placeholder/petsystemtabcontents.h"

class CItem;

class UIPetSystemDialog : public UIDialog, public UIItemEventListener
{
public:
    // A tab: its label string id, the swf frame name and the page (RTTI .?AUTabInfo@UIPetSystemDialog@@, 0x38 bytes).
    struct TabInfo : public CPtred
    {
        TabInfo(int nStrId, MS2Ptr<PetSystemTabContents> spPage, CString strName);    // 0x140e733a0
                                                                                        // (dtor 0x140e75270 implicit, ??_G 0x140e75430)
        int m_18;                                               // +0x18 the label (common string id)
        CString m_20;                                           // +0x20 the frame name ("petInfo", ...)
        MS2Ptr<PetSystemTabContents> m_28;                      // +0x28 the page (null when its feature is off)
    };

    UIPetSystemDialog();                                        // 0x140e73440
    virtual CString GetTypeName();                                  //  1 0x140e73540 "PetSystemDialog"
    virtual void OnLoadComplete();                              // 22 0x140e73db0 fill "m_buttonBar"
    virtual void vfunc_25(void* p1, TPtr<Unk_UISwfEntity_25> p2, void* p3, void* p4);     // 25 0x140e74360
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x140e74120
    virtual void vfunc_45(Scaleform::GFx::Value* pRetVal, const CString& strMethod, ASData* pArgs);     // 45 0x140e74090
    virtual int vfunc_48() { return 0x4f38; }                   // 48 0x140e75800
    virtual int vfunc_65();                                     // 65 0x140e735e0 Open: create the tabs; returns 0
    virtual void vfunc_67();                                    // 67 0x140e73c20 Close: drop the tabs
    virtual void vfunc_79(void* p);                             // 79 0x140e74480
    virtual int vfunc_82();                                     // 82 0x140e74420 the page's vfunc_8, -1 without a page
    virtual int vfunc_84();                                     // 84 0x140e74710 the pages to create (1: own pets)
    virtual MS2Ptr<CItem> vfunc_85();                           // 85 0x140e74730 the pet item (the summoned pet)
    virtual void vfunc_3(void* pItem, bool b);                  // UIItemEventListener 3 0x140e744e0

    void FUN_140e73590(int n);                                  // FUN_1412761e0 on the movie
    void FUN_140e74550(int nGroup);                             // open the collect tab at a group
    void FUN_140e74640(int nEvent);                             // forward an event to the page (while open)
    MS2Ptr<PetSystemTabContents> FUN_140e746c0();               // the shown page
    int FUN_140e74790();                                        // the index of the collect tab (forwarding m_180)
    void OnRemoveTab();                                       // leave the shown page
    void FUN_140e74970(CString strName, const Scaleform::GFx::Value& root);    // show a tab by frame name

protected:
    MS2_LAYOUT_FRIEND;
    int m_180;                                                  // +0x180 the collect group to show (FUN_140e74550)
    MS2Ptr<PetSystemTabContents> m_188;                         // +0x188 the shown page
    ATL::CAtlMap<int, MS2Ptr<TabInfo>, ATL::CDefaultElementTraits<int> > m_198;   // +0x198 tab index -> tab (key by reference)
};
MS2_CHECK_SIZE(UIPetSystemDialog::TabInfo, 0x38);
MS2_CHECK_SIZE(UIPetSystemDialog, 0x1e0);
MS2_CHECK_OFFSET(UIPetSystemDialog, m_180, 0x180);
MS2_CHECK_OFFSET(UIPetSystemDialog, m_188, 0x188);
MS2_CHECK_OFFSET(UIPetSystemDialog, m_198, 0x198);
