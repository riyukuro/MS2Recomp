// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIObserveDialog (class name "ObserveDialog", UI type
// 0x4e8a, 0x188 bytes) is the observer-mode HUD: it shows the name of the player being watched ("ChangePlayerName") and
// toggles the centred camera ("SetCenterCamera"). While the observer feature is on, vfunc_13 (the close/back request)
// leaves the observed actor instead.
// MS2-UNIT: ?\uiobservedialog.cpp
// MS2-RANGE: 0x141a732e0-0x141a738f0 .text$mn
// MS2-PIN: ??_GUIObserveDialog@@UEAAPEAXI@Z 0x141a73780
// MS2-PIN: ??1UIObserveDialog@@UEAA@XZ 0x141a73750
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiobservedialog.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"

#include "uiobservedialog.h"

#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local views of unrecovered callees ------------------------------------------------------------------------

void* FUN_14025e7c0();                                          // the option service
bool FUN_14116d840(void* pOptions);                             // is the observer mode on
void* FUN_1403ed2d0();                                          // the UI service
void* FUN_141bd0cc0(void* pPlayer);                             // the player's actor
void FUN_14152a960(void* pActor);                               // leave the observed actor

// @0x141a732e0
UIObserveDialog::UIObserveDialog()
{
    m_bCenterCamera = false;
    FUN_1422dc3b0(1);
}

// @0x141a73360
CString UIObserveDialog::GetTypeName()
{
    return "ObserveDialog";
}
MS2_REPLACE_METHOD(0x141A73360, UIObserveDialog, GetTypeName, 61, 0x20B5146C);

// @0x141a733b0
void UIObserveDialog::OnLoadInit()
{
    UIObject::OnLoadInit();
    FUN_141a735c0();
}
MS2_REPLACE_METHOD(0x141A733B0, UIObserveDialog, OnLoadInit, 34, 0x2B2E9752);

// @0x141a733e0
void UIObserveDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    if (m_30.get() != 0)
        m_30.operator->()->FUN_140f5ff80("initData", m_strName, m_bCenterCamera);
    vfunc_47(0);
}
MS2_REPLACE_METHOD(0x141A733E0, UIObserveDialog, OnLoadComplete, 226, 0xFD29FD68);

// @0x141a734d0
int UIObserveDialog::vfunc_13()
{
    if (FUN_14116d840(FUN_14025e7c0()) != false)
    {
        void* pActor = FUN_141bd0cc0(FUN_1403ed2d0());
        if (pActor != 0)
            FUN_14152a960(pActor);
        return 1;
    }
    if (UIDialog::vfunc_13() != 0)
        return 1;
    return 0;
}
MS2_REPLACE_METHOD(0x141A734D0, UIObserveDialog, vfunc_13, 100, 0x4BBA8AE1);

// @0x141a73540
int UIObserveDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    return UIDialog::vfunc_28(szMethod, pArgs, nArgs);
}
MS2_REPLACE_METHOD(0x141A73540, UIObserveDialog, vfunc_28, 54, 0xF1B8C899);

// @0x141a73580
void UIObserveDialog::vfunc_67()
{
    UIDialog::vfunc_67();
    vfunc_47(1);
}
MS2_REPLACE_METHOD(0x141A73580, UIObserveDialog, vfunc_67, 48, 0x63D94166);

// @0x141a735c0
void UIObserveDialog::FUN_141a735c0()
{
}

// @0x141a735d0
void UIObserveDialog::FUN_141a735d0(CStringW strName)
{
    m_strName = strName;
    m_bCenterCamera = false;
    if (m_30.get() != 0)
        m_30.operator->()->Invoke("ChangePlayerName", m_strName);
}

// @0x141a736c0
void UIObserveDialog::FUN_141a736c0(bool bCenterCamera)
{
    m_strName = L"";
    m_bCenterCamera = bCenterCamera;
    if (m_30.get() != 0)
        m_30.operator->()->Invoke("SetCenterCamera", bCenterCamera);
}
MS2_REPLACE_METHOD(0x141A736C0, UIObserveDialog, FUN_141a736c0, 136, 0xB2A9C07A);

// @0x141a737c0
int UIObserveDialog::vfunc_48()
{
    return 0x4e8a;
}

// @0x141a737d0
MS2_EMIT_CRT_MEMMOVE_S_COPY(1);
