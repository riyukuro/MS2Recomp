// uiobjectstoredialog.h - UIObjectStoreDialog (RTTI .?AVUIObjectStoreDialog@@, 0x1a0 bytes, UIDialog + UIStatusEventListener,
// UI id 0x4e78, swf "ObjectStoreDialog"): the item bag window of an object store (a function cube that keeps items).
// It shows the bag of the item type m_198 (name, slot count, description), binds the "m_itemBag" control to the bag
// id in m_180, follows the inventory dialog (it is placed next to it) and asks the server (packet 0x2e, op 7) to close
// the store session with the store key m_190. vfunc_84 (a new virtual) sets the store key and the item type.
// Owning unit: ?\uiobjectstoredialog.cpp. Header name assumed from the unit path.
#pragma once
#include <afx.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/uistatuseventlistener.h"

class UIObjectStoreDialog : public UIDialog, public UIStatusEventListener
{
public:
    UIObjectStoreDialog();                                      // 0x141a72480
    virtual ~UIObjectStoreDialog();                             //  0 0x141a72550 (??_G 0x141a73290)
    virtual CString GetTypeName();                                  //  1 0x141a725e0 "ObjectStoreDialog"
    virtual void OnLoadInit();                                  // 20 0x141a729d0 register the status listener
    virtual void OnLoadComplete();                              // 22 0x141a72a60 initData: bag id, name, count, description
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x141a72dd0 "OnSort"
    virtual int vfunc_48() { return 0x4e78; }                   // 48 0x141a732d0
    virtual int vfunc_54(void* pCfg);                           // 54 0x141a729a0
    virtual int vfunc_65();                                     // 65 0x141a72690
    virtual void vfunc_66();                                    // 66 0x141a726e0 place next to the inventory
    virtual void vfunc_67();                                    // 67 0x141a72860 close: tell the server
    virtual void vfunc_84(const CString& strKey, int nItemType);   // 84 0x141a72630
    virtual int OnMessage(UISwfEntity* pSender, UIMsg* pMsg);   // IMessageListener 0 0x141a72d80

    // UIStatusEventListener (+0x178) overrides
    virtual int vfunc_oa0_1();                                  // o178 1 0x141a72e50
    virtual void vfunc_oa0_7(int a1, CStringW s);               // o178 7 0x141a72f00
    virtual void vfunc_oa0_9(unsigned short a1);                // o178 9 0x141a72ea0

    void FUN_141a72f80(int bBind);                              // (re)create the bag of the item type

private:
    MS2_LAYOUT_FRIEND;
    CString m_180;                                              // +0x180 the bag id (starts as the dialog name)
    int m_188;                                                  // +0x188 the inventory was open when this opened
    CString m_190;                                              // +0x190 the store key
    int m_198;                                                  // +0x198 the item type
};
MS2_CHECK_SIZE(UIObjectStoreDialog, 0x1a0);
MS2_CHECK_OFFSET(UIObjectStoreDialog, m_180, 0x180);
MS2_CHECK_OFFSET(UIObjectStoreDialog, m_198, 0x198);
