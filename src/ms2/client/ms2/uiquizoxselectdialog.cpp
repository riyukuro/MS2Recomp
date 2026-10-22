// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIQuizOXSelectDialog: see uiquizoxselectdialog.h.
// MS2-UNIT: ?\uiquizoxselectdialog.cpp
// MS2-RANGE: 0x140e7ead0-0x140e7ef40 .text$mn
//
// File name assumed (the class name; the exe has no assert path for it).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiquizoxselectdialog.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"

#include "uiquizoxselectdialog.h"

#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// The SWF dialog object handed around by the UI library (the exe's dynamic_cast targets).
class ASDialog : public ASDisplayObject
{
};

void FUN_140710590(COutPacket& packet);                         // 0x140710590 send the packet

// @0x140e7ead0
UIQuizOXSelectDialog::UIQuizOXSelectDialog()
{
    FUN_141925e70(1, 1);
}

// @0x140e7eb40
UIQuizOXSelectDialog::~UIQuizOXSelectDialog()
{
}

// @0x140e7eb80
CString UIQuizOXSelectDialog::GetTypeName()
{
    return "QuizOXSelectDialog";
}

// @0x140e7ebd0
void UIQuizOXSelectDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
}

// @0x140e7ebf0
void UIQuizOXSelectDialog::vfunc_43()
{
    UIDialog::vfunc_43();
    ASDialog* pDlg = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDlg != 0)
        pDlg->vfunc_2(0, 0, -300);
}

// @0x140e7ec70
void UIQuizOXSelectDialog::vfunc_72()
{
}

// MS2-FUNCTIONAL: one byte shorter in the exe (answer/result temporaries of the single-exit form)
// @0x140e7ec80
int UIQuizOXSelectDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (_stricmp("OnClickAnswer", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
            FUN_140e7ed60(this, data.FUN_1422b8a10());
        return 1;
    }
    return 0;
}

// MS2-FUNCTIONAL: one byte differs in the answer parameter spill/conversion
// @0x140e7ed60
void FUN_140e7ed60(UIQuizOXSelectDialog* pDialog, char nAnswer)
{
    COutPacket packet(0x90, 0);
    packet.vfunc_o10_1(10);
    packet.vfunc_o10_1(11);
    packet.vfunc_o10_1(nAnswer);
    FUN_140710590(packet);
}

// The UCRT header-inline memmove_s (corecrt_memcpy_s.h), an unreferenced copy kept in this unit.
#pragma function(memmove)
#define MS2_VALIDATE_RETURN_ERRCODE(expr, errorcode) \
    { int _Expr_val = !!(expr); if (!(_Expr_val)) { errno = errorcode; _invalid_parameter_noinfo(); return errorcode; } }
// @0x140e7ee20
errno_t FUN_140e7ee20(void* const dst, rsize_t const dstSize, void const* const src, rsize_t const srcSize)
{
    if (srcSize == 0) return 0;
    MS2_VALIDATE_RETURN_ERRCODE(dst != NULL, EINVAL);
    MS2_VALIDATE_RETURN_ERRCODE(src != NULL, EINVAL);
    MS2_VALIDATE_RETURN_ERRCODE(dstSize >= srcSize, ERANGE);
    memmove(dst, src, srcSize);
    return 0;
}
