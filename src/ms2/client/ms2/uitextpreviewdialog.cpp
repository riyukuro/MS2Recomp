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

// ---- unit-local views of unrecovered callees ------------------------------------------------------------------------

class ASDialog : public ASDisplayObject { };

// The text input.
class Unk_TpInput : public ASDisplayObject
{
public:
    void FUN_1422e0ab0(const CStringW& strText);                // set the text
};

// The button bar.
class Unk_TpBar : public ASDisplayObject
{
public:
    unsigned int FUN_1422e3380();                               // button count
    void FUN_1422e31e0(unsigned int nIndex);                    // select a button
};
extern template class MS2Ptr<Unk_TpBar>;                        // instances owned by other objs

// The reserved-word filters of the text singleton.
class Unk_TpFilter
{
public:
    void FUN_1416fb3c0(CStringW& str);
    void FUN_1416fb380(CStringW& str);
    void FUN_1416fb340(CStringW& str);
};
Unk_TpFilter* FUN_1403b4750();

// A vector of unsigned ids (24 bytes; ctor 0x140182ed0, dtor 0x140183b90).
struct Unk_TpIds { void* m_begin; void* m_end; void* m_cap; };
void FUN_140182ed0(Unk_TpIds* p);
void FUN_140183b90(Unk_TpIds* p);
size_t FUN_140191110(Unk_TpIds* p);                             // size
unsigned int* FUN_140297cb0(Unk_TpIds* p, size_t n);            // operator[]
void* FUN_140281980();                                          // the table singleton
void FUN_1405594b0(void* pTable, Unk_TpIds* pOut);              // collect the ids

CStringTable* FUN_1401a9d70();
void* FUN_1422bb8b0(int nMovieId);                              // the movie of a UI layer
// A GFx::Value that the string-value builder constructs itself (no ctor call); the dtor is Value's (0x140614800).
struct Unk_TpValue { ~Unk_TpValue(); long long m_a, m_b, m_c, m_d; };
void FUN_142575b00(void* pMovie, const Unk_TpValue& v);   // hand a value to the movie
Unk_TpValue* FUN_1412dd680(Unk_TpValue* pOut, const wchar_t* sz);   // string value
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
        m_198 = FUN_140c02870(strName);
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
    if (nIndex >= m_198.operator->()->FUN_1422e3380())
        return;
    m_198.operator->()->FUN_1422e31e0(nIndex);
}

// @0x141351050
void UITextPreviewDialog::FUN_141351050(CStringW strText)
{
    if (FUN_1422dc2d0() == 0)
        return;
    if (m_178 == 0)
        return;
    m_178.operator->()->FUN_1422e0ab0(strText);
}

// @0x1413510f0
void UITextPreviewDialog::FUN_1413510f0(CStringW strText)
{
    if (FUN_1422dc2d0() == 0)
        return;
    if (m_188 == 0)
        return;
    m_188.operator->()->FUN_1422e0ab0(strText);
}

// @0x141351190
void UITextPreviewDialog::vfunc_67()
{
    UIDialog::vfunc_67();
}

// MS2-FUNCTIONAL: the exe spills the string Value's address through an extra stack temp (+9 bytes); not reproducible
// @0x1413511b0
int UITextPreviewDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (_stricmp("ReplaceReserveWord", szMethod) == 0) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs)) {
            CStringW strText = data.FUN_1422b8f40();
            FUN_1403b4750()->FUN_1416fb3c0(strText);
            FUN_1403b4750()->FUN_1416fb380(strText);
            FUN_1403b4750()->FUN_1416fb340(strText);
            Unk_TpValue v;
            const Unk_TpValue& rv = *FUN_1412dd680(&v, (const wchar_t*)strText);
            FUN_142575b00(FUN_1422bb8b0(m_28), rv);
        }
    }
    else if (_stricmp("OnDescriptionCheck", szMethod) == 0) {
        OnDescriptionCheck();
    }
    return 0;
}

// MS2-FUNCTIONAL: the exe has an extra EH state/nop around the id vector setup (6 states vs 5)
// @0x141351340
void UITextPreviewDialog::OnDescriptionCheck()
{
    ASDialog* pDlg = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDlg != 0) {
        Unk_TpIds ids;
        FUN_140182ed0(&ids);
        FUN_1405594b0(FUN_140281980(), &ids);
        for (size_t i = 0; i < FUN_140191110(&ids); i++) {
            unsigned int nId = *FUN_140297cb0(&ids, i);
            CStringW strMain = FUN_1401a9d70()->GetItemDescription(nId, CString("mainDescription"));
            CStringW strTooltip = FUN_1401a9d70()->GetItemDescription(nId, CString("tooltipDescription"));
            if (strMain.IsEmpty() && strTooltip.IsEmpty())
                continue;
            pDlg->Invoke("descriptionCheck", 0, nId, strMain, strTooltip);
        }
        FUN_140183b90(&ids);
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

// MS2-FUNCTIONAL: the exe has no vtable stores and an out-of-line MS2Ptr<Input> dtor (other obj)
// @0x141351740
UITextPreviewDialog::~UITextPreviewDialog()
{
}

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
