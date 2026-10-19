// uistatuseventlistener.h - UIStoreDialog (RTTI .?AVUIStoreDialog@@, 0x1b8 bytes, UIDialog + UIStatusEventListener +
// UIItemEventListener, UI id 0x4e47, swf "StoreDialog"): the bank / storage window (deposit and withdraw mesos, expand
// the slots, search the items by name). The unit ?\uistatuseventlistener.cpp also holds the status event hub
// (UIStatusEventDispatcher, src/ms2/placeholder/uistatuseventdispatcher.h) and the 8-byte listener base
// (src/ms2/placeholder/uistatuseventlistener.h). Header name assumed from the unit path.
#pragma once
#include <afx.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/uistatuseventlistener.h"
#include "ms2/placeholder/uiitemeventlistener.h"
#include "ms2/placeholder/delegate.h"

class CMsgBoxData;
class Unk_StInput;
class Unk_StExpandClip;
class Unk_StItemHub;
class Unk_StBagBind;
class Unk_StSlotBag;
class Unk_StCandSet;

// The 16-byte handle of the search input ("m_inputSearch"): an MS2Ptr whose operations live in the exe (0x140bbf710 /
// 0x140bbfdd0 / 0x140bc0500 / 0x140bc0550).
struct Unk_StInputRef { void* m_0; void* m_8; };

class UIStoreDialog : public UIDialog, public UIStatusEventListener, public UIItemEventListener
{
public:
    typedef Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)> StoreDelegate;

    UIStoreDialog();                                            // 0x141b0ebd0
    virtual ~UIStoreDialog();                                   //  0 0x141b0ed50 (??_G 0x141b12530)
    virtual CString vfunc_1();                                  //  1 0x141b0ee20 "StoreDialog"
    virtual int vfunc_13();                                     // 13 0x141b10290 Enter key: apply the search text
    virtual void vfunc_15();                                    // 15 0x141b10210 per-frame: refresh the bag / the expand text
    virtual void OnLoadInit();                                  // 20 0x141b0f430 register the listeners
    virtual void OnLoadComplete();                              // 22 0x141b0f4f0 bind the search input, initData
    virtual void vfunc_26();                                    // 26 0x141b0f780 drop the search input
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x141b0fa40
    virtual int vfunc_48() { return 0x4e47; }                   // 48 0x141b12570
    virtual int vfunc_54(void* pCfg);                           // 54 0x141b0f1e0
    virtual int vfunc_65();                                     // 65 0x141b0eec0
    virtual void vfunc_66();                                    // 66 0x141b0ef40 place next to the inventory
    virtual void vfunc_67();                                    // 67 0x141b0f0c0 close
    virtual int vfunc_71();                                     // 71 0x141b0f2b0 ask before closing
    virtual int vfunc_73();                                     // 73 0x141b0f210 can open
    virtual void vfunc_80(void* pRequest);                      // 80 0x141b10480 platform request: the search text
    virtual int OnMessage(UISwfEntity* pSender, UIMsg* pMsg);   // IMessageListener 0 0x141b0f7c0

    // UIStatusEventListener (+0x178)
    virtual int vfunc_oa0_1();                                  // o178 1 0x141b0ee70
    virtual void vfunc_oa0_7(int a1, CStringW s);               // o178 7 0x141b107e0
    virtual void vfunc_oa0_9(unsigned short a1);                // o178 9 0x141b10780
    virtual void vfunc_oa0_13(void* a1);                        // o178 13 0x141b106b0 changeMoney
    virtual void vfunc_oa0_25(void* a1);                        // o178 25 0x141b10860
    virtual void vfunc_oa0_26(void* a1);                        // o178 26 0x141b108c0

    // UIItemEventListener (+0x180)
    virtual void vfunc_9(void* p);                              // o180 9 0x141b10920 bag changed
    virtual void vfunc_10(void* p);                             // o180 10 0x141b10950 bag changed
    virtual void vfunc_il13();                                  // o180 13 0x141b10980 everything changed

    // ---- non-virtual members, sorted by address ----
    MS2Ptr<ASMovieClip> FUN_140ba7930(const CString& strName);  // movie clip child lookup (GetChild<ASMovieClip>)
    MS2Ptr<Unk_StExpandClip> FUN_140e6d820(const CString& strName);   // the "m_expand" clip (GetChild)
    void FUN_141b109a0();                                       // the slots were expanded: play "m_expandEff"
    int FUN_141b10af0();                                        // may be used (no talk running, not closed)
    CStringW FUN_141b10b50();                                   // the search text
    void FUN_141b10ba0(int n);                                  // m_190 = n
    void FUN_141b10bc0(const Scaleform::GFx::FunctionHandler::Params& params);   // "search" button: candidates of the typed text
    void FUN_141b10eb0();                                       // m_198 = 4
    void FUN_141b10ed0(CStringW strText);                       // ask the platform to accept the text, then FUN_141b116d0
    void FUN_141b110e0();                                       // rebuild the bag
    int FUN_141b11190(const __int64& nAmount);                  // deposit mesos
    int FUN_141b11350(const __int64& nAmount);                  // withdraw mesos
    int FUN_141b11490();                                        // can deposit / withdraw
    bool FUN_141b114f0();                                       // can expand the slots
    void FUN_141b11520();                                       // expand the slots (or tell why not)
    void FUN_141b11590();                                       // refresh the "m_expand" text
    void FUN_141b116d0(CStringW strText);                       // scroll to / mark the item matching the text
    void FUN_141b11a10(CStringW strText, Unk_StCandSet* pOut);  // collect the item names containing the text
    bool FUN_141b11ba0(int nButton, const CMsgBoxData& box);    // result callback: focus the search input
    bool FUN_141b11c90(int nButton, const CMsgBoxData& box);    // result callback: expand

private:
    MS2_LAYOUT_FRIEND;
    CString m_188;                                              // +0x188 the bag id (the dialog name)
    int m_190;                                                  // +0x190 close question variant
    int m_194;                                                  // +0x194 the inventory was open when this opened
    int m_198;                                                  // +0x198 pending refresh bits (2 = expand text, 4 = bag)
    CStringW m_1a0;                                             // +0x1a0 the search text
    Unk_StInputRef m_1a8;                                       // +0x1a8 the search input
};
MS2_CHECK_SIZE(UIStoreDialog, 0x1b8);
MS2_CHECK_OFFSET(UIStoreDialog, m_188, 0x188);
MS2_CHECK_OFFSET(UIStoreDialog, m_198, 0x198);
MS2_CHECK_OFFSET(UIStoreDialog, m_1a0, 0x1a0);
MS2_CHECK_OFFSET(UIStoreDialog, m_1a8, 0x1a8);
