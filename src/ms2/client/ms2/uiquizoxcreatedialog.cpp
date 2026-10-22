// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIQuizOXCreateDialog: see uiquizoxcreatedialog.h.
// MS2-UNIT: ?\uiquizoxcreatedialog.cpp
// MS2-RANGE: 0x140e7e2f0-0x140e7ead0 .text$mn
// MS2-PIN: ??_GUIQuizOXCreateDialog@@UEAAPEAXI@Z 0x140e7e960
//
// File name assumed (the class name; the exe has no assert path for it).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiquizoxcreatedialog.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"

#include "uiquizoxcreatedialog.h"

#include "ms2/client/ms2/uiservice.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local views of unrecovered callees ------------------------------------------------------------------------

// The SWF dialog object handed around by the UI library (the exe's dynamic_cast targets).
class ASDialog : public ASDisplayObject
{
};

// Handles returned by the dialog's child lookups: a smart reference whose destructor is the exe function REL.
template <void (*REL)(void*)>
struct Unk_QoRef
{
    void* m_0;
    void* m_p;
    Unk_QoRef() : m_0(0), m_p(0) {}
    ~Unk_QoRef() { REL(this); }
};
void FUN_140bbfda0(void*);
void FUN_140bbfdd0(void*);
typedef Unk_QoRef<FUN_140bbfda0> Unk_QoComboRef;
typedef Unk_QoRef<FUN_140bbfdd0> Unk_QoTextRef;

// The drop down control (list of AS items) and the text field control.
class Unk_QoCombo
{
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
    virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11();
    virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15();
    virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19();
    virtual void vfunc_20(); virtual void vfunc_21(); virtual void vfunc_22(); virtual void vfunc_23();
    virtual void vfunc_24(bool b);
    void FUN_1422dfc10();                                       // clear the items
    void FUN_1422dfc70(ASObj& obj);                             // add an item
    void FUN_1422df690(int n);                                  // select an item
};
class Unk_QoText
{
public:
    void FUN_1422e0ab0(const CStringW& str);                    // set the text
};

void FUN_140c28560(void* pDlg, Unk_QoComboRef* pRet, const CString& strName);     // child lookup (this=rcx, hidden return=rdx)
void FUN_140e35bd0(void* pDlg, Unk_QoTextRef* pRet, const CString& strName);      // child lookup (text field)
bool FUN_140bc03e0(Unk_QoComboRef* p, int n);                   // handle is empty
Unk_QoCombo* FUN_140bc0530(Unk_QoComboRef* p);                  // the control
void* FUN_140bc0500(Unk_QoTextRef* p);                          // handle is set
Unk_QoText* FUN_140bc0550(Unk_QoTextRef* p);                    // the control
CStringW FUN_140763e10(int n);                                  // integer to text
void FUN_140dfee10(__int64 n1, int n2, int n3);                 // send the create request (packet 0x90)

// @0x140e7e2f0
UIQuizOXCreateDialog::UIQuizOXCreateDialog()
{
}

// @0x140e7e350
UIQuizOXCreateDialog::~UIQuizOXCreateDialog()
{
}

// @0x140e7e3a0
void UIQuizOXCreateDialog::SetFees(std::vector<int>& fees)
{
    m_fees.clear();
    std::vector<int>& range = fees;
    std::vector<int>::const_iterator itEnd = range.end();
    for (std::vector<int>::const_iterator it = range.begin(); it != itEnd; ++it) {
        int nFee = *it;
        m_fees.push_back(nFee);
    }
    FUN_141924680();
}
MS2_REPLACE_METHOD(0x140E7E3A0, UIQuizOXCreateDialog, SetFees, 180, 0xDA46093D);

// @0x140e7e460
CString UIQuizOXCreateDialog::GetTypeName()
{
    return "QuizOXCreateDialog";
}
MS2_REPLACE_METHOD(0x140E7E460, UIQuizOXCreateDialog, GetTypeName, 61, 0xD38B1E75);

// @0x140e7e4b0
// MS2-FUNCTIONAL: behaviour-equivalent; frame slot order of the control handles / iterators and EH state count differ
void UIQuizOXCreateDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    Unk_QoComboRef spCombo;
    FUN_140c28560(this, &spCombo, "m_dropdownEntryFee");
    if (FUN_140bc03e0(&spCombo, 0) != 0)
        return;
    {
        FUN_140bc0530(&spCombo)->FUN_1422dfc10();
        std::vector<int>& range = m_fees;
        std::vector<int>::const_iterator itEnd = range.end();
        for (std::vector<int>::const_iterator it = range.begin(); it != itEnd; ++it) {
            int nFee = *it;
            ASObj obj(2);
            obj.FUN_1407cbb20("label", FUN_140763e10(nFee));
            obj.FUN_1407cb9c0("data", nFee);
            FUN_140bc0530(&spCombo)->FUN_1422dfc70(obj);
        }
        FUN_140bc0530(&spCombo)->FUN_1422df690(0);
        FUN_140bc0530(&spCombo)->vfunc_24(true);
        Unk_QoTextRef spText;
        FUN_140e35bd0(this, &spText, "m_textHostFee");
        if (FUN_140bc0500(&spText) != 0) {
            FUN_140bc0550(&spText)->FUN_1422e0ab0(FUN_140763e10(m_fees[0]));
        }
    }
}
MS2_REPLACE_METHOD(0x140E7E4B0, UIQuizOXCreateDialog, OnLoadComplete, 679, 0x168B6C82);

// @0x140e7e760
void UIQuizOXCreateDialog::vfunc_43()
{
    UIDialog::vfunc_43();
    ASDialog* pDlg = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDlg != 0)
        pDlg->vfunc_2(0, 0, 0);
}
MS2_REPLACE_METHOD(0x140E7E760, UIQuizOXCreateDialog, vfunc_43, 110, 0x9AEB05D3);

// @0x140e7e7e0
void UIQuizOXCreateDialog::vfunc_72()
{
}

// @0x140e7e7f0
int UIQuizOXCreateDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (_stricmp("OnCreate", szMethod) == 0) {
        ASData args;
        if (args.FUN_1422b9620(pArgs, nArgs) != 0)
            return FUN_140e7e900(this, &args);
    } else if (_stricmp("OnCancel", szMethod) == 0) {
        CUIService::GetInstance()->FUN_141adc5d0((eUIClassID)0x4f47);
    }
    return 0;
}
MS2_REPLACE_METHOD(0x140E7E7F0, UIQuizOXCreateDialog, vfunc_28, 254, 0x832B405C);

// @0x140e7e900
int FUN_140e7e900(UIQuizOXCreateDialog* pDialog, ASData* pArgs)
{
    __int64 n1 = pArgs->FUN_1422b8a10();
    int n2 = pArgs->FUN_1422b8a10();
    int n3 = pArgs->FUN_1422b8a10();
    FUN_140dfee10(n1, n2, n3);
    return 0;
}
MS2_REPLACE(0x140E7E900, FUN_140e7e900, 85, 0x1C8B27D7);

// @0x140e7e9a0
int UIQuizOXCreateDialog::vfunc_48()
{
    return 0x4f47;
}

MS2_EMIT_CRT_MEMMOVE_S();
