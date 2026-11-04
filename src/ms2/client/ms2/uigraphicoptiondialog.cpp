// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIGraphicOptionDialog (UI type 0x4e34, "GraphicOptionDialog"): the
// HDR / shimmer / mirror check boxes, the shadow quality combo and the UI scale slider of the graphics options.
// MS2-UNIT: ?\uigraphicoptiondialog.cpp
// MS2-RANGE: 0x141946c10-0x141947920 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?vfunc_48@UIGraphicOptionDialog@@UEAAHXZ 0x1419477f0 ; unique
// MS2-PINS-END tplpin
#define NOMINMAX
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uigraphicoptiondialog.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"
#include <errno.h>
#include <string.h>
#include "ms2/client/ms2/uidialog.h"
#include "ms2/client/ms2/uiservice.h"
#include "ms2/client/ms2/postprocessing/postprocessingservice.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/uiswfentitymanager.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/cgameoption.h"
#include "ms2/placeholder/asbutton.h"  // C3: ASButton::FUN_1422ce090
#include "ms2/placeholder/ascorelist.h"
#include <NiRenderStep.h>

// ---- unit-local stand-ins for classes whose units are not recovered yet ----

// A check box AS entity of the option dialog.
class Unk_GoCheck : public ASButton
{
public:
};

// The shadow quality combo box AS entity.
class Unk_GoCombo : public ASDisplayObject
{
public:
};

// The graphics option block (Unk_AeGameOption::FUN_1409a8ac0): HDR, shimmer, mirror flags and the shadow quality.
class Unk_GoGraphics
{
public:
    char m_pad_00[0x19];
    bool m_bHdr;                // +0x19
    char m_pad_1a[2];
    bool m_bShimmer;            // +0x1c
    char m_pad_1d[2];
    bool m_bMirror;             // +0x1f
    int m_nShadow;              // +0x20
};
MS2_CHECK_OFFSET(Unk_GoGraphics, m_bHdr, 0x19);
MS2_CHECK_OFFSET(Unk_GoGraphics, m_nShadow, 0x20);

class Unk_AeGameOption { public: class Unk_AeGraphicOption* FUN_1409a8ac0(); };   // C3: unit-local view (def in applyeffect)

// The swf entity manager's slot 6 (vtable 0x143112518): refreshes the loaded movies after a UI scale change.
class Unk_GoMovieMgr
{
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6();
};

class Unk_AeFeatureMgr   // C3: member view for the former free stand-ins
{
public:
    static class Unk_AeFeatureMgr* FUN_1409a8b20();
};
bool FUN_1409a5850(class NiFixedString&, bool const*, unsigned int);   // C3: was FUN_1409a5850
extern NiFixedString DAT_143ae53c0;                  // "gfEnableShimmerRender"
CStringW GetStringCommon(int nStringId);

class UIGraphicOptionDialog : public UIDialog
{
public:
    UIGraphicOptionDialog();                                                        // 0x141946c10
    virtual ~UIGraphicOptionDialog();                                               //  0 0x141946c60 (??_G 0x1419477b0)
    virtual CString GetTypeName();                                                      //  1 0x141946ca0
    virtual int vfunc_5();                                                          //  5 0x141946d20
    virtual void OnLoadInit();                                                      // 20 0x141947000
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
                                                                                    // 28 0x141947290
    virtual int vfunc_48() { return 0x4e34; }                                       // 48 (COMDAT 0x1419477f0)
    virtual int vfunc_65();                                                         // 65 0x141946cf0

    MS2Ptr<Unk_GoCheck> FUN_140e52670(const CString& strName);                      // child lookup (ICF'd GetChild instance)
    MS2Ptr<Unk_GoCombo> FUN_140c28560(const CString& strName);                      // child lookup (ICF'd GetChild instance)
    void FUN_1419475a0(int bHdr);                                                  // HDR on/off
    void FUN_141947600(int bShimmer);                                              // shimmer on/off
    void FUN_141947710(int bMirror);                                               // mirror on/off
    void FUN_141947770(int nShadow);                                                // shadow quality
};

// @0x141946c10
UIGraphicOptionDialog::UIGraphicOptionDialog()
{
    m_40 = 1;
}

// @0x141946c60
UIGraphicOptionDialog::~UIGraphicOptionDialog()
{
}

// @0x141946ca0
CString UIGraphicOptionDialog::GetTypeName()
{
    return "GraphicOptionDialog";
}
MS2_REPLACE_METHOD(0x141946ca0, UIGraphicOptionDialog, GetTypeName, 61, 0x49ADDABE);

// @0x141946cf0
int UIGraphicOptionDialog::vfunc_65()
{
    if (UIDialog::vfunc_65() == 0)
        return 0;
    return 1;
}
MS2_REPLACE_METHOD(0x141946cf0, UIGraphicOptionDialog, vfunc_65, 37, 0xE40486DA);

// @0x141946d20
int UIGraphicOptionDialog::vfunc_5()
{
    if (MS2Ptr<Unk_GoCheck> spHdr = FUN_140e52670("m_hdr"))
        spHdr->FUN_1422ce090(reinterpret_cast<Unk_GoGraphics*>(reinterpret_cast<Unk_AeGameOption*>(TSingleton<CGameOption>::GetInstance())->FUN_1409a8ac0())->m_bHdr);
    if (MS2Ptr<Unk_GoCheck> spShimmer = FUN_140e52670("m_shimmer"))
        spShimmer->FUN_1422ce090(reinterpret_cast<Unk_GoGraphics*>(reinterpret_cast<Unk_AeGameOption*>(TSingleton<CGameOption>::GetInstance())->FUN_1409a8ac0())->m_bShimmer);
    if (MS2Ptr<Unk_GoCheck> spMirror = FUN_140e52670("m_mirror"))
        spMirror->FUN_1422ce090(reinterpret_cast<Unk_GoGraphics*>(reinterpret_cast<Unk_AeGameOption*>(TSingleton<CGameOption>::GetInstance())->FUN_1409a8ac0())->m_bMirror);
    if (MS2Ptr<Unk_GoCombo> spShadow = FUN_140c28560("m_shadow"))
        reinterpret_cast<MS2Ptr<ASDropdownMenu>&>(spShadow)->SetSelectedIndex(reinterpret_cast<Unk_GoGraphics*>(reinterpret_cast<Unk_AeGameOption*>(TSingleton<CGameOption>::GetInstance())->FUN_1409a8ac0())->m_nShadow);
    return UIDialog::vfunc_5();
}
MS2_REPLACE_METHOD(0x141946d20, UIGraphicOptionDialog, vfunc_5, 718, 0x445E1ECF);

// @0x141947000
void UIGraphicOptionDialog::OnLoadInit()
{
    UIDialog::OnLoadInit();
    {
        if (MS2Ptr<Unk_GoCombo> spShadow = FUN_140c28560("m_shadow")) {
            reinterpret_cast<MS2Ptr<ASDropdownMenu>&>(spShadow)->AddItemLabel(GetStringCommon(0x311));
            reinterpret_cast<MS2Ptr<ASDropdownMenu>&>(spShadow)->AddItemLabel(GetStringCommon(0x312));
            reinterpret_cast<MS2Ptr<ASDropdownMenu>&>(spShadow)->AddItemLabel(GetStringCommon(0x313));
            reinterpret_cast<MS2Ptr<ASDropdownMenu>&>(spShadow)->AddItemLabel(GetStringCommon(0x314));
            reinterpret_cast<MS2Ptr<ASDropdownMenu>&>(spShadow)->AddItemLabel(GetStringCommon(0x315));
        }
    }
    if (m_30.get() != 0) {
        m_30->Invoke("initData", TSingleton<CGameOption>::GetInstance()->FUN_140e09150()->m_f08);
    }
}
MS2_REPLACE_METHOD(0x141947000, UIGraphicOptionDialog, OnLoadInit, 641, 0x9F3488BD);

// @0x141947290
int UIGraphicOptionDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    ASData data;
    if (_stricmp("OnDisplayHdr", szMethod) == 0) {
        if (data.SetArgsIfAny(pArgs, nArgs)) {
            FUN_1419475a0(data.PopBool());
            return 1;
        }
    }
    else if (_stricmp("OnDisplayShimmer", szMethod) == 0) {
        if (data.SetArgsIfAny(pArgs, nArgs)) {
            FUN_141947600(data.PopBool());
            return 1;
        }
    }
    else if (_stricmp("OnDisplayMirror", szMethod) == 0) {
        if (data.SetArgsIfAny(pArgs, nArgs)) {
            FUN_141947710(data.PopBool());
            return 1;
        }
    }
    else if (_stricmp("OnDisplayShadow", szMethod) == 0) {
        if (data.SetArgsIfAny(pArgs, nArgs)) {
            FUN_141947770(data.PopInt());
            return 1;
        }
    }
    else if (_stricmp("OnUIScale", szMethod) == 0 && data.SetArgsIfAny(pArgs, nArgs)) {
        int nValue = data.PopInt();
        float fScale = (200 - nValue) * 0.01;
        if (TSingleton<CUIService>::GetInstance()->FUN_141adbe00(fScale, 1) != 0)
            reinterpret_cast<Unk_GoMovieMgr*>(FUN_140b632f0())->vfunc_6();      // MS2: slot 6
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x141947290, UIGraphicOptionDialog, vfunc_28, 766, 0x22DD0AE9);

// @0x1419475a0
void UIGraphicOptionDialog::FUN_1419475a0(int bHdr)
{
    if (reinterpret_cast<Unk_GoGraphics*>(reinterpret_cast<Unk_AeGameOption*>(TSingleton<CGameOption>::GetInstance())->FUN_1409a8ac0())->m_bHdr != bHdr)
        reinterpret_cast<Unk_GoGraphics*>(reinterpret_cast<Unk_AeGameOption*>(TSingleton<CGameOption>::GetInstance())->FUN_1409a8ac0())->m_bHdr = bHdr ? true : false;
}
MS2_REPLACE_METHOD(0x1419475a0, UIGraphicOptionDialog, FUN_1419475a0, 81, 0x89AE58C7);

// @0x141947600
void UIGraphicOptionDialog::FUN_141947600(int bShimmer)
{
    if (reinterpret_cast<Unk_GoGraphics*>(reinterpret_cast<Unk_AeGameOption*>(TSingleton<CGameOption>::GetInstance())->FUN_1409a8ac0())->m_bShimmer != bShimmer) {
        reinterpret_cast<Unk_GoGraphics*>(reinterpret_cast<Unk_AeGameOption*>(TSingleton<CGameOption>::GetInstance())->FUN_1409a8ac0())->m_bShimmer = bShimmer ? true : false;
        if (((class PostProcessingService*)Unk_AeFeatureMgr::FUN_1409a8b20())->IsClickActive(6) != bShimmer)
            ((class PostProcessingService*)Unk_AeFeatureMgr::FUN_1409a8b20())->FUN_1416aa450(6, bShimmer != 0);
        if (bShimmer == 0) {
            PostProcessEffect* pStep = ((class PostProcessingService*)Unk_AeFeatureMgr::FUN_1409a8b20())->GetStep(0xc);
            if (reinterpret_cast<NiRenderStep*>(pStep)->GetActive() != 0)
                ((class PostProcessingService*)Unk_AeFeatureMgr::FUN_1409a8b20())->FUN_1416a37a0(0xc, true);
            bool bFlag = false;
            FUN_1409a5850(DAT_143ae53c0, (bool const*)(&bFlag), 1);
        }
    }
}
MS2_REPLACE_METHOD(0x141947600, UIGraphicOptionDialog, FUN_141947600, 251, 0x88436EBF);

// @0x141947710
void UIGraphicOptionDialog::FUN_141947710(int bMirror)
{
    if (reinterpret_cast<Unk_GoGraphics*>(reinterpret_cast<Unk_AeGameOption*>(TSingleton<CGameOption>::GetInstance())->FUN_1409a8ac0())->m_bMirror != bMirror)
        reinterpret_cast<Unk_GoGraphics*>(reinterpret_cast<Unk_AeGameOption*>(TSingleton<CGameOption>::GetInstance())->FUN_1409a8ac0())->m_bMirror = bMirror ? true : false;
}
MS2_REPLACE_METHOD(0x141947710, UIGraphicOptionDialog, FUN_141947710, 81, 0xA404FEDE);

// @0x141947770
void UIGraphicOptionDialog::FUN_141947770(int nShadow)
{
    if (reinterpret_cast<Unk_GoGraphics*>(reinterpret_cast<Unk_AeGameOption*>(TSingleton<CGameOption>::GetInstance())->FUN_1409a8ac0())->m_nShadow != nShadow)
        reinterpret_cast<Unk_GoGraphics*>(reinterpret_cast<Unk_AeGameOption*>(TSingleton<CGameOption>::GetInstance())->FUN_1409a8ac0())->m_nShadow = nShadow;
}
MS2_REPLACE_METHOD(0x141947770, UIGraphicOptionDialog, FUN_141947770, 60, 0x8A6148B2);

// @0x141947800
MS2_EMIT_CRT_MEMMOVE_S_COPY(1);
