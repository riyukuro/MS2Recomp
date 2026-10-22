// uiitemeditdialog.h - the "edit item" page (RTTI UIItemEditDialog, UI id 0x4e24; "m_save" / "m_reset" buttons): edits the
// worn costume through the item customize controller (Customize), asks before leaving with unsaved changes and
// reports the server result (opcode 0x31). NOT an original header (the unit is ?\uiitemeditdialog.cpp). Member and
// helper names are invented from use. Sibling of UIBeautyShopDialog (uibeautyshopdialog.h), same bases.
#pragma once
#include <afx.h>
#include "ms2/placeholder/asobj.h"
#include "ms2/client/ms2/uibeautyshopstyledialog.h"     // IItemCustomizeEventListener, Customize

class CMsgBoxData;
class NotifyObject;
class Unk_BSCamera;
class Unk_140acd6e0;                                    // a button child

class UIItemEditDialog : public UIDialog, public UIItemEventListener, public IItemCustomizeEventListener
{
public:
    UIItemEditDialog();                                 // 0x1419bc730
    virtual ~UIItemEditDialog() = default;              // 0x1419be250 (??_G 0x1419be320)
    virtual CString vfunc_1();
    virtual int vfunc_13();
    virtual void vfunc_15();
    virtual void OnLoadComplete();
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
    // @0x1419be360
    virtual int vfunc_48() { return 0x4e24; }
    virtual void vfunc_67();
    virtual int OnMessage(UISwfEntity* pSender, UIMsg* pMsg);
    virtual void vfunc_79(void* p);

    // UIItemEventListener override
    virtual void vfunc_24(void* p);
    // IItemCustomizeEventListener overrides
    virtual int vfunc_1(void* p);
    virtual int vfunc_2(void* p, float fValue, int nIndex);
    virtual int vfunc_3(void* p, float fValue);

    bool FUN_1419bd500(int nResult, const CMsgBoxData& data);     // answer of the leave box: restore
    void FUN_1419bd530(NotifyObject* pNotify);                    // the active my-codi tab changed
    bool FUN_1419bd6d0(int nResult, const CMsgBoxData& data);
    bool FUN_1419bd710();
    bool FUN_1419bd7a0();                                         // the worn costume is editable
    bool FUN_1419bd860();                                         // leave the page (restore the worn item)
    void OnSave();                                         // save
    void OnReset();                                         // reset
    void FUN_1419bd9f0();                                         // close: ask first when changed
    void FUN_1419bdb50(int bEnable);                              // enable both buttons
    int FUN_1419bdb90();                                          // the save button is enabled
    void FUN_1419bdc40(int bEnable);                              // save button
    void FUN_1419bdce0(int bEnable);                              // reset button
    MS2Ptr<Unk_140acd6e0> FUN_140bb4b10(const CString& strName);  // bind a button child (a UIDialog member)

private:
    MS2_LAYOUT_FRIEND;
    MS2Ptr<Customize> m_198;                            // +0x198 the customize controller
    Unk_BSCamera* m_1a8;                                // +0x1a8 the camera (UI 0x4ef2's object)
    char m_1b0;                                         // +0x1b0 a save is pending
};
MS2_CHECK_SIZE(UIItemEditDialog, 0x1b8);
MS2_CHECK_OFFSET(UIItemEditDialog, m_198, 0x198);
MS2_CHECK_OFFSET(UIItemEditDialog, m_1a8, 0x1a8);
MS2_CHECK_OFFSET(UIItemEditDialog, m_1b0, 0x1b0);
