// Recovered UIItemPreviewDialog (UI type 0x4ec2 "ItemPreviewDialog"): previews an item on the player's avatar with a
// tooltip. RTTI vftables: dialog at +0, IMessageListener at +0x18, IUIAvatarEventListener at +0x178. File name assumed
// (the class name). Unnamed helpers and members use invented names.
#pragma once
#include "ms2/client/ms2/uiskillpreviewdialog.h"        // IUIAvatarEventListener
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/citem.h"

class ASTextField;
class UIEquipIconContainer;
class UIItemPreviewDialog : public UIDialog, public IUIAvatarEventListener
{
public:
    UIItemPreviewDialog();                                          // 0x1412d5890
    virtual ~UIItemPreviewDialog();                                 //  0 0x1412d5920 (??_G 0x1412d6c00)
    virtual CString GetTypeName();                                      //  1 0x1412d5990
    virtual void vfunc_26();                                        // 26 0x1412d59e0
    virtual void vfunc_67();                                        // 67 0x1412d5a20
    virtual int vfunc_65();                                         // 65 0x1412d5a50
    virtual void OnLoadComplete();                                  // 22 0x1412d5a90
    virtual void vfunc_15();                                        // 15 0x1412d5c10
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x1412d5c40
    virtual void vfunc_25(void* p1, TPtr<Unk_UISwfEntity_25> p2, void* p3, void* p4);   // 25 0x1412d5cb0
    virtual void vfunc_16();                                        // 16 0x1412d5ff0
    virtual bool vfunc_17();                                        // 17 0x1412d6020
    virtual int vfunc_o178_1(void* pAvatar);                        // 0x1412d6060
    virtual int vfunc_o178_0(void* pAvatar);                        // 0x1412d6220
    virtual int vfunc_o178_2(void* pAvatar);                        // 0x1412d6250
    virtual int vfunc_48() { return 0x4ec2; }                       // 48 (COMDAT 0x1412d6c70)

    void FUN_1412d6270();                                           // "loadRenderTarget"
    void FUN_1412d62d0();                                           // "unloadRenderTarget"
    void FUN_1412d6330(MS2Ptr<CItem> spItem);                       // show the item on the avatar
    void FUN_1412d66e0(const Scaleform::GFx::FunctionHandler::Params& params);   // tooltip callback
    MS2Ptr<ASTextField> FUN_140bb4cf0(const CString& strName);      // text field child lookup

private:
    MS2_LAYOUT_FRIEND;
    MS2Ptr<UIEquipIconContainer> m_equip;                           // +0x180
};
MS2_CHECK_SIZE(UIItemPreviewDialog, 0x190);
MS2_CHECK_OFFSET(UIItemPreviewDialog, m_equip, 0x180);
