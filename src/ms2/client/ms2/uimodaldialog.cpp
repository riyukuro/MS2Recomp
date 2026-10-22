// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIModalDialog.
// MS2-UNIT: ?\uimodaldialog.cpp
// MS2-RANGE: 0x141a55270-0x141a55740 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uimodaldialog.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "uimodaldialog.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

extern int DAT_143af4400;               // the id of the modal dialog that is shown
void FUN_141901470(int, int);
class ASDialog : public ASDisplayObject {
public:
    void FUN_1407cbbe0(const char*, bool);
};

// @0x141a55270
UIModalDialog::UIModalDialog() {
    m_178 = 0;
    m_e0 = 0;
    m_84 = 1;
}
// @0x141a552e0
UIModalDialog::~UIModalDialog() {
    DAT_143af4400 = 0;
}
// @0x141a55330
CString UIModalDialog::GetTypeName() { return "ModalDialog"; }
MS2_REPLACE_METHOD(0x141a55330, UIModalDialog, GetTypeName, 61, 0xCF736B5E);
// @0x141a55380
void UIModalDialog::vfunc_8(int nVisible) {
    ASDialog* dialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (dialog) {
        vfunc_47(nVisible == 0);
        dialog->vfunc_3(nVisible);
        dialog->FUN_1407cbbe0("visible", nVisible == 1);
        if (m_178 && m_c4 != 0) {
            const char* name;
            if (nVisible != 0) name = "startOpen";
            else name = "startClose";
            CString method(name);
            if (m_30.get()) {
                m_30->Invoke(method);
            }
        }
    }
    if (nVisible != 0) FUN_141a55650(vfunc_48());
    else FUN_141a55670(vfunc_48());
}
MS2_REPLACE_METHOD(0x141a55380, UIModalDialog, vfunc_8, 501, 0x1D8C5C66);
// @0x141a55580
void UIModalDialog::vfunc_67() {
    vfunc_47(1);
    FUN_141a55670(vfunc_48());
    UIDialog::vfunc_67();
    m_178 = 0;
}
MS2_REPLACE_METHOD(0x141a55580, UIModalDialog, vfunc_67, 86, 0x755CF89E);
// @0x141a555e0
void UIModalDialog::vfunc_68() {
    vfunc_8(0);
    UIDialog::vfunc_68();
}
MS2_REPLACE_METHOD(0x141a555e0, UIModalDialog, vfunc_68, 42, 0xABBA7414);
// @0x141a55620
int FUN_141a55620() { return DAT_143af4400 != 0; }
MS2_REPLACE(0x141a55620, FUN_141a55620, 37, 0xB34B823E);
// @0x141a55650
void FUN_141a55650(int nId) { DAT_143af4400 = nId; }
MS2_REPLACE(0x141a55650, FUN_141a55650, 15, 0x883EE3E0);
// @0x141a55670
void FUN_141a55670(int nId) {
    if (nId == DAT_143af4400) DAT_143af4400 = 0;
}
MS2_REPLACE(0x141a55670, FUN_141a55670, 27, 0x3785A5EB);
// @0x141a556a0
void UIModalDialog::OnLoadComplete() {
    UIDialog::OnLoadComplete();
    m_178 = 1;
}
MS2_REPLACE_METHOD(0x141a556a0, UIModalDialog, OnLoadComplete, 36, 0x547E66E9);
// @0x141a556d0
void UIModalDialog::vfunc_47(int n) { FUN_141901470(n, vfunc_48()); }
MS2_REPLACE_METHOD(0x141a556d0, UIModalDialog, vfunc_47, 48, 0xA0005278);
