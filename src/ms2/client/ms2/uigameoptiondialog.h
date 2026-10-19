// uigameoptiondialog.h - UIGameOptionDialog (RTTI .?AVUIGameOptionDialog@@, base UIDialog; 0x1d8 bytes): the options window.
// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13); header name assumed, member names invented. Ctor 0x141941b80
// (operator new 0x1d8 in CUIService::RegisterDialogs), dtor 0x141942810 (deleting dtor 0x141944be0). The definitions
// belong to unit `?\uigameoptiondialog.cpp`; only the layout is declared here so other units can use the type.
//
// The ctor builds one CBaseOption page per tab id (1 camera, 2 interface, 3 status, 4 battle, 5 community, 6 graphic,
// 7 sound, 8 gamepad (feature 0xb5), 9..0xd input (0xc: feature 0xb5), 0xe language, 0x10 account, 0xf personal-info
// agreement (feature 0x117)) into m_mapPages (ctor 0x1419447f0 = CAtlMap(17, .75f, .25f, 2.25f, 10)).
#pragma once
#include <atlcoll.h>
#include "ms2/client/ms2/uidialog.h"
#include "ms2/client/ms2/baseoption.h"
#include "ms2/placeholder/imessagelistener.h"
#include "ms2/placeholder/ascript.h"

class ASData;

class UIMsg;
class UISwfEntity;

class UIGameOptionDialog : public UIDialog
{
public:
    UIGameOptionDialog();                                           // 0x141941b80
    virtual ~UIGameOptionDialog();                                  //  0 0x141942810 (??_G 0x141944be0)
    virtual CString vfunc_1();                                      //  1 0x141942880 "GameOptionDialog"
    virtual void OnLoadComplete();                                  // 22 0x1419428d0 send initData, build the tabs
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x141942cc0
    virtual void vfunc_67();                                        // 67 0x141942a10 Close: deactivate every page
    virtual int vfunc_13();                                         // 13 0x141942b10 escape: ask/save, close
    virtual void vfunc_15();                                        // 15 0x141942bf0 every page vfunc_13
    virtual void vfunc_49(Scaleform::GFx::Value* pRetVal, ASData* pArgs);   // 49 0x141943230 getTooltip (hdr, shimmer)
    virtual int vfunc_48() { return 0x4ef3; }                       // 48 0x1419450b0
    virtual int OnMessage(UISwfEntity* pSender, UIMsg* pMsg);       // IMessageListener 0 0x141943010 message box answers

    void FUN_141943480();                                           // pick the simple (reduced) mode, enable the pages, setTabComponent
    void FUN_1419436e0(int nTab);                                   // open a tab: page vfunc_3(1)
    void FUN_141943790(int nTab);                                   // close a tab: page vfunc_4(1)
    void FUN_141943820(int n);                                      // "m_apply" button enabled state
    void FUN_1419438b0();                                           // re-open the current tab
    void FUN_141943900(bool b);                                     // m_bF1d0, update the red circle
    void FUN_141943940();                                           // agreement tab red circle
    void FUN_141943a00();                                           // RemoveAll
    void FUN_141943a30();                                           // the "init to default" confirm box
    void FUN_141943d80();                                           // every page vfunc_9
    void FUN_141943e30();                                           // save (confirm box when not all agreed)
    void FUN_141943ec0();                                           // apply every page, then the option settings
    void FUN_141944030(int n);                                      // m_nF1cc = n; page vfunc_12 (all pages when 0)
    void FUN_141944150();                                           // check and save
    int FUN_141944250();                                            // 1 when nothing is pending
    int FUN_141944330();                                            // 1 when no page differs
    MS2Ptr<class Unk_GoButton> FUN_140bb4b10(const CString& strName);   // 0x140bb4b10 bind a button child
    MS2Ptr<CBaseOption> FUN_141944460(int nIndex);                  // the nIndex-th page (1-based, map order)
    void FUN_141944590(int n);                                      // FUN_1419445c0(0x10, n)
    void FUN_1419445c0(int nKey, int n);                            // n == 0: drop the page nKey
    void FUN_141b15670(int nTab) { m_nTab = nTab; }                 // 0x141b15670 (inline COMDAT, uisystemmenudialog.cpp)
    // appended by ?\gameoptioninputdefault.cpp (w471): inline COMDATs first used there, and the child lookups it calls
    int FUN_141254590() const { return m_nTab; }                    // 0x141254590
    int FUN_141254a00() const { return m_nF1cc; }                   // 0x141254a00
    template <class T> MS2Ptr<T> GetTabChild(CString strName, int nIndex);   // "getTabChild" (instances per T, e.g. 0x1412536b0)
    MS2Ptr<class ASUIComponent> FUN_14124ff50(int nIndex);         // 0x14124ff50 "getTabComponent" (gameoption.cpp)

    int m_nTab;                                                     // +0x178 current tab id (1 on a fresh dialog)
    ATL::CAtlMap<int, MS2Ptr<CBaseOption>> m_mapPages;              // +0x180 tab id -> page
    bool m_bSimple;                                                 // +0x1c8 simplified (reduced-tab) mode
    int m_nF1cc;                                                    // +0x1cc
    bool m_bF1d0;                                                   // +0x1d0
};
MS2_CHECK_SIZE(UIGameOptionDialog, 0x1d8);
MS2_CHECK_OFFSET(UIGameOptionDialog, m_nTab, 0x178);
MS2_CHECK_OFFSET(UIGameOptionDialog, m_mapPages, 0x180);
MS2_CHECK_OFFSET(UIGameOptionDialog, m_bSimple, 0x1c8);
MS2_CHECK_OFFSET(UIGameOptionDialog, m_nF1cc, 0x1cc);
MS2_CHECK_OFFSET(UIGameOptionDialog, m_bF1d0, 0x1d0);
