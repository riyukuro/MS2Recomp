// uiitembreakdialog.h - the item break windows (header name assumed; the classes are defined in
// client\ms2\uiinventorydialog.cpp). UIItemBreakBase (RTTI .?AVUIItemBreakBase@@, 0x1c0 bytes, UIDialog +
// UIStatusEventListener + UIItemEventListener) is the shared part: the "m_itemBag" slot bag registered under the movie
// name, the reward item bindings, the "startBreak" / "endBreak" calls and the docking next to the inventory window.
// UIItemBreakDialog (0x210, UI id 0x4e8d, "ItemBreakDialog") breaks items into materials, with the bundle register
// dropdowns and the preview list; UIItemBreakDonationDialog (0x1c8, UI id 0x4e8e, "ItemBreakDonationDialog") donates
// them. Both read the CItemBreakManager mode from vfunc_88 (1 break, 2 donation).
// Owning unit: client\ms2\uiinventorydialog.cpp.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include <map>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/uistatuseventlistener.h"
#include "ms2/placeholder/uiitemeventlistener.h"

class CInPacket;
class CMsgBoxData;

class UIItemBreakBase : public UIDialog, public UIStatusEventListener, public UIItemEventListener
{
public:
    UIItemBreakBase();                                          // 0x1419a1280
    virtual ~UIItemBreakBase();                                 //  0 0x1419a1360 (??_G 0x1419a9400)
    virtual void vfunc_15();                                    // 15 0x1419a1a40 per-frame: the manager's pending work
    virtual void OnLoadInit();                                  // 20 0x1419a1740
    virtual void OnLoadComplete();                              // 22 0x1419a1770
    virtual void vfunc_26();                                    // 26 0x1419a1830
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x1419a19f0
    virtual void vfunc_43();                                    // 43 0x1419a1bb0 dock left of the inventory
    virtual void vfunc_45(Scaleform::GFx::Value* pRetVal, const CString& strMethod, ASData* pArgs);    // 45 0x1419a19d0 empty
    virtual int vfunc_46();                                     // 46 0x1419a1400
    virtual void vfunc_66();                                    // 66 0x1419a1a80 tell the inventory where it is
    virtual void vfunc_67();                                    // 67 0x1419a18c0 close
    virtual int vfunc_73();                                     // 73 0x1419a1970 not while the item lock window is open
    virtual void vfunc_84(CInPacket* pPacket) {}                // 84 0x1419a94c0 the break result
    virtual void vfunc_85(bool bReset, int nIndex) {}           // 85 0x1419a9520 scroll the bag
    virtual int vfunc_86() { return 0; }                        // 86 0x1419a94d0 can break
    virtual bool vfunc_87(int nResult, const CMsgBoxData& box) { return true; }   // 87 0x1419a9500 the confirm box
    virtual int vfunc_88() = 0;                                 // 88 the CItemBreakManager mode

    // ---- non-virtual members, sorted by address ----
    void FUN_1419a1430();                                       // (re)register the slot bag under the movie name
    int FUN_1419a1660();                                        // "m_itemBag" is visible
    void FUN_1419a1d20(int nIndex);                             // a bag slot changed
    CString FUN_1419a1dc0(int nItemId, int nRarity, int nCount);   // bind a reward item; the binding name
    void FUN_1419a1fb0();                                       // release the reward bindings
    void FUN_1419a2060();                                       // "startBreak"
    void FUN_1419a2110();                                       // "endBreak"

protected:
    MS2_LAYOUT_FRIEND;
    int m_188;                                                  // +0x188 breaking (startBreak .. endBreak)
    ATL::CAtlList<CString> m_190;                               // +0x190 the reward item bindings
};
MS2_CHECK_SIZE(UIItemBreakBase, 0x1c0);
MS2_CHECK_OFFSET(UIItemBreakBase, m_188, 0x188);
MS2_CHECK_OFFSET(UIItemBreakBase, m_190, 0x190);

class UIItemBreakDialog : public UIItemBreakBase
{
public:
    UIItemBreakDialog();                                        // 0x1419a21c0
    virtual ~UIItemBreakDialog();                               //  0 0x1419a22a0 (??_G 0x1419a9440)
    virtual CString GetTypeName();                                  //  1 0x1419a2330 "ItemBreakDialog"
    virtual void OnLoadInit();                                  // 20 0x1419a2380
    virtual void OnLoadComplete();                              // 22 0x1419a2400 the bundle dropdowns
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x1419a3a80
    virtual int vfunc_46();                                     // 46 0x1419a3110 the description and tooltip
    virtual int vfunc_48() { return 0x4e8d; }                   // 48 0x1419a94e0
    virtual void vfunc_67();                                    // 67 0x1419a2ce0
    virtual int vfunc_73();                                     // 73 0x1419a2d70
    virtual void vfunc_84(CInPacket* pPacket);                  // 84 0x1419a36b0
    virtual void vfunc_85(bool bReset, int nIndex);             // 85 0x1419a2e30
    virtual int vfunc_86();                                     // 86 0x1419a2dd0
    virtual bool vfunc_87(int nResult, const CMsgBoxData& box); // 87 0x1419a4420
    virtual int vfunc_88();                                     // 88 0x1419a2e10

    void FUN_1419a4460();                                       // "resetBreak"
    void FUN_1419a44d0(CInPacket* pPacket);                     // the preview list
    CString FUN_1419a4aa0(int nItemId);                         // bind a preview item; the binding name
    void FUN_1419a4c80();                                       // release the preview bindings

protected:
    MS2_LAYOUT_FRIEND;
    int m_1c0;                                                  // +0x1c0 the manager mode (1)
    ATL::CAtlList<CString> m_1c8;                               // +0x1c8 the preview item bindings
    int m_1f8;                                                  // +0x1f8 the bundle type (an inventory tab)
    int m_1fc;                                                  // +0x1fc the bundle rank (and below)
    std::map<int, int> m_200;                                   // +0x200 bundle type -> dropdown index
};
MS2_CHECK_SIZE(UIItemBreakDialog, 0x210);
MS2_CHECK_OFFSET(UIItemBreakDialog, m_1c0, 0x1c0);
MS2_CHECK_OFFSET(UIItemBreakDialog, m_1c8, 0x1c8);
MS2_CHECK_OFFSET(UIItemBreakDialog, m_1f8, 0x1f8);
MS2_CHECK_OFFSET(UIItemBreakDialog, m_200, 0x200);

class UIItemBreakDonationDialog : public UIItemBreakBase
{
public:
    UIItemBreakDonationDialog();                                // 0x1419a4d30
    virtual ~UIItemBreakDonationDialog();                       //  0 0x1419a4db0 (??_G 0x1419a9480)
    virtual CString GetTypeName();                                  //  1 0x1419a4e20 "ItemBreakDonationDialog"
    virtual void OnLoadInit();                                  // 20 0x1419a4e70
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x1419a51b0
    virtual int vfunc_46();                                     // 46 0x1419a5050
    virtual int vfunc_48() { return 0x4e8e; }                   // 48 0x1419a94f0
    virtual void vfunc_67();                                    // 67 0x1419a4ef0
    virtual int vfunc_73();                                     // 73 0x1419a4f70
    virtual void vfunc_84(CInPacket* pPacket);                  // 84 0x1419a5160
    virtual void vfunc_85(bool bReset, int nIndex);             // 85 0x1419a5030 empty
    virtual int vfunc_86();                                     // 86 0x1419a4fd0
    virtual bool vfunc_87(int nResult, const CMsgBoxData& box); // 87 0x1419a5980
    virtual int vfunc_88();                                     // 88 0x1419a5010

protected:
    MS2_LAYOUT_FRIEND;
    int m_1c0;                                                  // +0x1c0 the manager mode (2)
};
MS2_CHECK_SIZE(UIItemBreakDonationDialog, 0x1c8);
MS2_CHECK_OFFSET(UIItemBreakDonationDialog, m_1c0, 0x1c0);
