// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIIGuideMovieDialog: the modal tutorial-movie dialog.
// MS2-UNIT: unit_1412c3ac0
// MS2-RANGE: 0x1412c3ac0-0x1412c3e60 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "unit_1412c3ac0.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- out-of-unit callees (names describe uses) ----
class Unk_GmGuideCfg
{
public:
    CString FUN_1409f6f30();                                    // the guide movie path
};
class Unk_GmConfig                                              // the game constants singleton
{
public:
    char m_pad_00[0xcd70];
    Unk_GmGuideCfg m_guide;                                     // +0xcd70
};
Unk_GmConfig* FUN_1401d3200();
class Unk_GmKeys
{
public:
    bool FUN_14116d9c0(int nKey, int a, int b);
};
Unk_GmKeys* FUN_14025e7c0();

// @0x1412c3ac0
UIIGuideMovieDialog::UIIGuideMovieDialog()
{
    m_58 = 0;
    m_7c = 1;
    m_80 = 0;
    FUN_141924170(1);
}

// @0x1412c3b50
UIIGuideMovieDialog::~UIIGuideMovieDialog()
{
}

// @0x1412c3b90
CString UIIGuideMovieDialog::GetTypeName()
{
    return "GuideMovieDialog";
}
MS2_REPLACE_METHOD(0x1412C3B90, UIIGuideMovieDialog, GetTypeName, 61, 0xAE290DE9);

// @0x1412c3be0
int UIIGuideMovieDialog::vfunc_65()
{
    return UIDialog::vfunc_65();
}
MS2_REPLACE_METHOD(0x1412C3BE0, UIIGuideMovieDialog, vfunc_65, 24, 0x2E748187);

// @0x1412c3c00
void UIIGuideMovieDialog::vfunc_67()
{
    UIModalDialog::vfunc_67();
}
MS2_REPLACE_METHOD(0x1412C3C00, UIIGuideMovieDialog, vfunc_67, 24, 0x7FB6FA99);

// @0x1412c3c20
void UIIGuideMovieDialog::vfunc_69()
{
    if (m_30.get())
        m_30->Invoke("onEscapeKey");
}
MS2_REPLACE_METHOD(0x1412C3C20, UIIGuideMovieDialog, vfunc_69, 83, 0x2124D088);

// @0x1412c3c80
// MS2-FUNCTIONAL: the exe copies the returned path through an extra CString temp that the source form elides
void UIIGuideMovieDialog::OnLoadComplete()
{
    UIModalDialog::OnLoadComplete();
    CString strMovie = FUN_1401d3200()->m_guide.FUN_1409f6f30();
    m_30->Invoke("initData", strMovie);
}
MS2_REPLACE_METHOD(0x1412C3C80, UIIGuideMovieDialog, OnLoadComplete, 204, 0x1460A601);

// @0x1412c3d60
int UIIGuideMovieDialog::vfunc_13()
{
    if (UIDialog::vfunc_13())
        return 1;
    if (FUN_14025e7c0()->FUN_14116d9c0(0x1c, 0, 0))
        return 1;
    return 0;
}
MS2_REPLACE_METHOD(0x1412C3D60, UIIGuideMovieDialog, vfunc_13, 75, 0x6A0C7CB5);

// @0x1412c3dc0
int UIIGuideMovieDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs))
        return 1;
    return 0;
}
MS2_REPLACE_METHOD(0x1412C3DC0, UIIGuideMovieDialog, vfunc_28, 67, 0x980377F2);
