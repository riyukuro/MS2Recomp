// uiinteriorbuilddialog.h - UIInteriorBuildDialog (RTTI .?AVUIInteriorBuildDialog@@, 0x180 bytes, UIDialog, UI id
// 0x4ee8, swf "InteriorBuildDialog"): the confirm box shown when an interior package item is used. It shows the
// package (name, description, install name / description) and, on "OnUseItem", checks that the current map is the own
// home, that it has the indoor size the package needs and sends the item argument "true" / "false" to the inventory.
// Owning unit: ?\uiinteriorbuilddialog.cpp. Header name assumed from the unit path.
#pragma once
#include <afx.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/uidialog.h"

class UIInteriorBuildDialog : public UIDialog
{
public:
    UIInteriorBuildDialog();                                    // 0x140f4b3d0
    virtual ~UIInteriorBuildDialog();                           //  0 0x140f4b430 (??_G 0x140f4cae0)
    virtual CString GetTypeName();                                  //  1 0x140f4b470 "InteriorBuildDialog"
    virtual void OnLoadComplete();                              // 22 0x140f4b550 fill the package texts
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x140f4b580 "OnUseItem"
    virtual int OnMessage(UISwfEntity* pSender, UIMsg* pMsg);   // IMessageListener 0 0x140f4b5f0 confirm answers
    virtual int vfunc_48() { return 0x4ee8; }                   // 48 0x140f4cb20
    virtual void vfunc_67();                                    // 67 0x140f4b520

    void FUN_140f4b4c0(__int64 nItemUid);                       // remember the item and open the dialog
    void FUN_140f4b7d0();                                       // setData: the package texts
    void OnUseItem();                                       // OnUseItem: check the home and send the answer

private:
    __int64 m_178;                                              // +0x178 the used item uid
};
MS2_CHECK_SIZE(UIInteriorBuildDialog, 0x180);
