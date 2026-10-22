// uiinteriorpreviewdialog.h - UIInteriorPreviewDialog (RTTI .?AVUIInteriorPreviewDialog@@, 0x1a8 bytes, UIDialog, UI id
// 0x4ee3, swf "InteriorPreviewDialog"): the preview box of an interior package item. For the package named by the item's
// function parameter it lists every distinct cube item (name, bound item tooltip) and the package's indoor size.
// Owning unit: ?\uiinteriorpreviewdialog.cpp. Header name assumed from the unit path.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/uidialog.h"

class ASTextField;
class ASData;

class UIInteriorPreviewDialog : public UIDialog
{
public:
    UIInteriorPreviewDialog();                                  // 0x140f4cc50
    virtual ~UIInteriorPreviewDialog();                         //  0 0x140f4ccf0
    virtual CString GetTypeName();                                  //  1 0x140f4cd40 "InteriorPreviewDialog"
    virtual void OnLoadComplete();                              // 22 0x140f4cf60 apply the pending position and fill the lists
    virtual void vfunc_45(Scaleform::GFx::Value* pRetVal, const CString& strMethod, ASData* pArgs);   // 45 0x140f4d010 "getTooltipFromItemID"
    virtual int vfunc_48() { return 0x4ee3; }                   // 48 0x140f4dea0
    virtual void vfunc_67();                                    // 67 0x140f4cef0 close: forget the item and release the bound items

    void FUN_140f4cd90(int nItemId);                            // show the preview of that package item
    void FUN_140f4ce70(int nItemId, float fX, float fY);            // same, remembering the position for OnLoadComplete
    void FUN_140f4d110();                                       // fill the lists (setData)
    void FUN_140f4dac0();                                       // release the bound items
    MS2Ptr<ASTextField> FUN_140bb4cf0(const CString& strName);  // 0x140bb4cf0 text field child lookup (a UIDialog member)

private:
    MS2_LAYOUT_FRIEND;
    int m_178;                                                  // +0x178 the package item id
    int m_17c;                                                  // +0x17c a position is pending
    float m_180;                                                  // +0x180 the pending x
    float m_184;                                                  // +0x184 the pending y
    ATL::CAtlArray<CString> m_188;                              // +0x188 the names the items are bound under
};
MS2_CHECK_SIZE(UIInteriorPreviewDialog, 0x1a8);
