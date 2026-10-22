// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIVisualTrackerListDialog: the "VisualTrackerListDialog"
// dialog (UI type 0x4eb2), the list of entities tracked by the visual tracker. The base flag m_40 is set so the SWF
// loads from the Debug_UI table; OnLoadComplete pushes the initial data ("initData") and the two list buttons
// ("onClickAddToList" / "onClickRemoveFromList") forward the current selection. File name unknown (the unit classifier
// rejected the class-name guess): the class is declared here.
// MS2-UNIT: unit_141b72f60
// MS2-RANGE: 0x141b72f60-0x141b732c0 .text$mn
#define MS2_THIS_FILE ""    // no original source path recovered (the unit is unnamed); no assert paths here
#include "ms2/placeholder/ms2stdafx.h"

#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asobj.h"

#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

class UIVisualTrackerListDialog : public UIDialog
{
public:
    UIVisualTrackerListDialog();                                                // 0x141b72f60
    virtual ~UIVisualTrackerListDialog();                                       //  0 0x141b72fb0 (??_G 0x141b73270)
    virtual CString GetTypeName();                                                  //  1 0x141b72ff0
    virtual void OnLoadComplete();                                              // 22 0x141b73040
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
                                                                                // 28 0x141b73100
    virtual int vfunc_48();                                                     // 48 0x141b732b0 returns 0x4eb2
};
MS2_CHECK_SIZE(UIVisualTrackerListDialog, 0x178);

// The tracker list helper the two button handlers forward to (0x141b73260): a no-op in this build.
void FUN_141b73260(UIVisualTrackerListDialog* pDialog, ASData& data, bool bAdd);

// @0x141b72f60
UIVisualTrackerListDialog::UIVisualTrackerListDialog()
{
    m_40 = 1;
}

// @0x141b72fb0
UIVisualTrackerListDialog::~UIVisualTrackerListDialog()
{
}

// @0x141b72ff0
CString UIVisualTrackerListDialog::GetTypeName()
{
    return "VisualTrackerListDialog";
}
MS2_REPLACE_METHOD(0x141B72FF0, UIVisualTrackerListDialog, GetTypeName, 61, 0x989F1624);

// @0x141b73040
void UIVisualTrackerListDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    ASObj obj(2);
    m_30->Invoke("initData", obj.FUN_1422bb870());
}
MS2_REPLACE_METHOD(0x141B73040, UIVisualTrackerListDialog, OnLoadComplete, 176, 0x0B503C25);

// @0x141b73100
int UIVisualTrackerListDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (_stricmp("onClickAddToList", szMethod) == 0) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
            FUN_141b73260(this, data, true);
        return 1;
    }
    else if (_stricmp("onClickRemoveFromList", szMethod) == 0) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
            FUN_141b73260(this, data, false);
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x141B73100, UIVisualTrackerListDialog, vfunc_28, 329, 0x3FD4CA7B);

// @0x141b73260
void FUN_141b73260(UIVisualTrackerListDialog* pDialog, ASData& data, bool bAdd)
{
    (void)pDialog;
    (void)data;
    (void)bAdd;
}
MS2_REPLACE(0x141B73260, FUN_141b73260, 16, 0x497674E6);

// @0x141b732b0
int UIVisualTrackerListDialog::vfunc_48()
{
    return 0x4eb2;
}
MS2_REPLACE_METHOD(0x141B732B0, UIVisualTrackerListDialog, vfunc_48, 11, 0x5E8784EB);
