// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). See uikeyboardguidedialog.h.
// MS2-UNIT: ?\uikeyboardguidedialog.cpp
// MS2-RANGE: 0x140f83ff0-0x140f84310 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uikeyboardguidedialog.cpp"
#include "ms2/placeholder/ms2stdafx.h"

#include "uikeyboardguidedialog.h"

#include "ms2/ms2recover.h"
#include "ms2/placeholder/ascript.h"

CString FUN_141900b70();    // uicommon.cpp: name of the active input device ("xbox", "keyboard", ...)

// @0x140f83ff0
UIKeyboardGuideDialog::UIKeyboardGuideDialog()
{
    m_80 = 0;
}

// @0x140f84050
UIKeyboardGuideDialog::~UIKeyboardGuideDialog()
{
}

// @0x140f84090
CString UIKeyboardGuideDialog::GetTypeName()
{
    return "KeyboardGuideDialog";
}

// @0x140f840e0
void UIKeyboardGuideDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    if (m_30.get())
        m_30->Invoke("guideType", FUN_141900b70());
}

// @0x140f84180
void UIKeyboardGuideDialog::vfunc_67()
{
    UIDialog::vfunc_67();
}

// @0x140f841f0
MS2_EMIT_CRT_MEMMOVE_S_COPY(1);
