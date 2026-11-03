// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UITextPreviewDialog: see uitextpreviewdialog.h.
// MS2-UNIT: ?\uitextpreviewdialog.cpp
// MS2-RANGE: 0x141350cf0-0x1413518a0 .text$mn
//
// File name assumed (the class name; the exe has no assert path for it).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uitextpreviewdialog.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"

#include "uitextpreviewdialog.h"

#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/creservedwordtable.h"
#include "ms2/placeholder/astextinput.h"
#include "ms2/placeholder/asbuttonbar.h"
#include "ms2/commonfiles/itemdatatable.h"

// ---- unit-local views of unrecovered callees ------------------------------------------------------------------------

class ASDialog : public ASDisplayObject { };

// The text input.
class Unk_TpInput : public ASTextInput
{
};

extern template class MS2Ptr<ASButtonBar>;                      // instances owned by other objs

// The button bar child lookup, shared with this dialog.
class UIDailyMissionDialog
{
public:
    MS2Ptr<ASButtonBar> FUN_140c02870(const CString& strName);
};

class CItemDataTable;

Scaleform::GFx::Movie* FUN_1422bb8b0(int nMovieId);             // the movie of a UI layer
// A GFx::Value that the string-value builder constructs itself (no ctor call); the dtor is Value's (0x140614800).
void FUN_1422bccb0(Scaleform::GFx::Value* pValue, int n);
void FUN_1422bcd10(Scaleform::GFx::Value* pValue, unsigned int n);
void FUN_1422bcea0(Scaleform::GFx::Value* pValue, const wchar_t* psz);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// @0x141350cf0
UITextPreviewDialog::UITextPreviewDialog()
{
    m_40 = 1;
}

// @0x141350d90
CString UITextPreviewDialog::GetTypeName()
{
    return "TextPreviewDialog";
}

// @0x141350de0
void UITextPreviewDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    {
        CString strName("m_input1");
        m_178 = FUN_140c26f60(strName);
    }
    {
        CString strName("m_input2");
        m_188 = FUN_140c26f60(strName);
    }
    {
        CString strName("m_buttonBar");
        m_198 = reinterpret_cast<UIDailyMissionDialog*>(this)->FUN_140c02870(strName);
    }
}

// @0x141350f60
void UITextPreviewDialog::vfunc_26()
{
    UIDialog::vfunc_26();
    m_178 = 0;
    m_188 = 0;
    m_198 = 0;
}

// @0x141350fc0
void UITextPreviewDialog::FUN_141350fc0(unsigned int nIndex)
{
    if (FUN_1422dc2d0() == 0)
        return;
    if (m_198 == 0)
        return;
    if (nIndex >= m_198.operator->()->GetItemCount())
        return;
    m_198.operator->()->SetSelectedIndex((int)nIndex);
}

// @0x141351050
void UITextPreviewDialog::FUN_141351050(CStringW strText)
{
    if (FUN_1422dc2d0() == 0)
        return;
    if (m_178 == 0)
        return;
    m_178.operator->()->SetTextW(strText);
}

// @0x1413510f0
void UITextPreviewDialog::FUN_1413510f0(CStringW strText)
{
    if (FUN_1422dc2d0() == 0)
        return;
    if (m_188 == 0)
        return;
    m_188.operator->()->SetTextW(strText);
}

// @0x141351190
void UITextPreviewDialog::vfunc_67()
{
    UIDialog::vfunc_67();
}

// @0x1413511b0
int UITextPreviewDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (_stricmp("ReplaceReserveWord", szMethod) == 0) {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs)) {
            CStringW strText = data.FUN_1422b8f40();
            TSingleton<CReservedWordTable>::GetInstance()->ReplaceColorWords(strText);
            TSingleton<CReservedWordTable>::GetInstance()->ReplaceObjectWords(strText);
            TSingleton<CReservedWordTable>::GetInstance()->ReplaceValueWords(strText);
            FUN_1422bb8b0(m_28)->SetExternalInterfaceRetVal(Scaleform::GFx::Value((const wchar_t*)strText));
        }
    }
    else if (_stricmp("OnDescriptionCheck", szMethod) == 0) {
        OnDescriptionCheck();
    }
    return 0;
}

// @0x141351340
void UITextPreviewDialog::OnDescriptionCheck()
{
    ASDialog* pDlg = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDlg != 0) {
        std::vector<unsigned int> ids;
        reinterpret_cast<CItemDataTable*>(reinterpret_cast<void*>(TSingleton<CItemDataTable>::GetInstance()))->LoadItemNameIds(ids);
        for (size_t i = 0; i < ids.size(); i++) {
            unsigned int nId = ids[i];
            CStringW strMain = TSingleton<CStringTable>::GetInstance()->GetItemDescription(nId, CString("mainDescription"));
            CStringW strTooltip = TSingleton<CStringTable>::GetInstance()->GetItemDescription(nId, CString("tooltipDescription"));
            if (strMain.IsEmpty() && strTooltip.IsEmpty())
                continue;
            pDlg->Invoke("descriptionCheck", 0, nId, strMain, strTooltip);
        }
    }
}

// The Invoke back end for the description check.
// @0x1413515e0
Scaleform::GFx::Value AScript::Invoke(const char* szMethod, int a1, unsigned int a2, CStringW a3, CStringW a4)
{
    ASArgList args;
    args.FUN_1409b2800(4);
    FUN_1422bccb0(args.FUN_1409b1f70(0), a1);
    FUN_1422bcd10(args.FUN_1409b1f70(1), a2);
    FUN_1422bcea0(args.FUN_1409b1f70(2), (const wchar_t*)a3);
    FUN_1422bcea0(args.FUN_1409b1f70(3), (const wchar_t*)a4);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x141351740 ~UITextPreviewDialog: implicit (no vftable stores in the exe)

// @0x141351890
int UITextPreviewDialog::vfunc_48()
{
    return 0x4eb7;
}

MS2_REPLACE_METHOD(0x141350D90, UITextPreviewDialog, GetTypeName, 61, 0x808E73E2);
MS2_REPLACE_METHOD(0x141350DE0, UITextPreviewDialog, OnLoadComplete, 375, 0xB00AB583);
MS2_REPLACE_METHOD(0x141350F60, UITextPreviewDialog, vfunc_26, 87, 0x892F17C9);
MS2_REPLACE_METHOD(0x141350FC0, UITextPreviewDialog, FUN_141350fc0, 130, 0xB8523302);
MS2_REPLACE_METHOD(0x141351050, UITextPreviewDialog, FUN_141351050, 140, 0xC648E1D4);
MS2_REPLACE_METHOD(0x1413510F0, UITextPreviewDialog, FUN_1413510f0, 140, 0xC7B7B9BD);
MS2_REPLACE_METHOD(0x141351190, UITextPreviewDialog, vfunc_67, 24, 0x76B18167);
MS2_REPLACE_METHOD(0x1413511B0, UITextPreviewDialog, vfunc_28, 381, 0xE82608D9);
MS2_REPLACE_METHOD(0x141351340, UITextPreviewDialog, OnDescriptionCheck, 661, 0xDDEA0E88);
MS2_REPLACE_METHOD(0x141351890, UITextPreviewDialog, vfunc_48, 11, 0xE2D70D38);
