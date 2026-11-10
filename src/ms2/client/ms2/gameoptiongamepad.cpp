// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The client's gameoptiongamepad.cpp: the gamepad row of the
// game options.
// MS2-UNIT: ?\gameoptiongamepad.cpp
// MS2-RANGE: 0x140a571b0-0x140a58820 .text$mn
// MS2-PIN: ??_GCGameOptionGamePad@@UEAAPEAXI@Z 0x140a584c0
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\gameoptiongamepad.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"
#include "gameoptiongamepad.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/client/ms2/ms2inputservice.h"
#include "ms2/commonfiles/featuremanager.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include <string.h>
#include <algorithm>
#include "ms2/placeholder/asbutton.h"  // C3: ASButton::FUN_1422ce090
#include "ms2/placeholder/asmousecursor.h"
#include "ms2/placeholder/gfxmanager.h"
#include "ms2/placeholder/asslider.h"
#include "ms2/placeholder/cgameoption.h"

// ---- unit-local placeholders ----


// The game-option settings object (TSingleton<CGameOption>; +0x1a0 is the saved gamepad block).
class Unk_GpSettings
{
public:
    char m_pad[0x1a0];
    Unk_GpState m_gamepad;
    char m_pad2[0x230 - 0x1b0];
    char m_defaults;                // +0x230 the default block
};
Unk_GpState* GetGamepadState(Unk_GpSettings* p);

// The state block's methods (0x14125f290...).
struct Unk_GpState* FUN_14125f290(struct Unk_GpState*);   // C3: was FUN_14125f290
void FUN_14125f2c0(Unk_GpState* p);
int LoadGameOptionGamepad(struct Unk_GpState*, class TiXmlDocument*);   // C3: was FUN_14125f330
void FUN_14125f640(Unk_GpState* pDst, const Unk_GpState* pSrc);
void SetGamepadEnabled(Unk_GpState* p, bool bUse, bool bNotify);


// View of the option dialog: the option id at +0x28 and the AS root at +0x30.
struct Unk_GpDialog
{
    char m_pad[0x28];
    int m_nId;
    int m_pad2;
    MS2Ptr<AScript> m_root;
    MS2Ptr<class ASCheckBox> GetTabCheckBox(CString name, int nIndex);
    MS2Ptr<class ASSlider> GetTabSlider(CString name, int nIndex);
};
struct Unk_GpInputView { char m_pad[0x124]; int m_nCursorMode; };
int FUN_140a58520(void* pInput);                                // MS2InputService::m_nCursorMode
MS2InputService* FUN_140a58540();                               // TSingleton<MS2InputService>::GetInstance

MS2Ptr<ASCheckBox> CreateCheckBox(int nId, const Scaleform::GFx::Value& v);
MS2Ptr<ASSlider> CreateSlider(int nId, const Scaleform::GFx::Value& v);

// ---- CGameOptionGamePad ----
// @0x140a571b0
CGameOptionGamePad::CGameOptionGamePad(int nId, int nType)
    : CBaseOption(nId, nType)
{
    // m_state: its ctor (0x14125f290) runs as a member ctor
}

// @0x140a57210
CGameOptionGamePad::~CGameOptionGamePad()
{
}

// @0x140a57240
void CGameOptionGamePad::vfunc_3(int n)
{
    if (n == 0)
        FUN_14125f640(&m_state, GetGamepadState(reinterpret_cast<Unk_GpSettings*>(TSingleton<CGameOption>::GetInstance())));
    CBaseOption::vfunc_3(n);
}
MS2_REPLACE_METHOD(0x140A57240, CGameOptionGamePad, vfunc_3, 69, 0xABC5CF6E);

// @0x140a57290
void CGameOptionGamePad::vfunc_4(int n)
{
    CBaseOption::vfunc_4(n);
}
MS2_REPLACE_METHOD(0x140A57290, CGameOptionGamePad, vfunc_4, 32, 0xFDCCB9F3);

// @0x140a572c0
int CGameOptionGamePad::vfunc_5(const char* pszName, void* pArg, int nArg)
{
    return 0;
}
MS2_REPLACE_METHOD(0x140A572C0, CGameOptionGamePad, vfunc_5, 23, 0x192A1B0B);

// @0x140a572e0
void CGameOptionGamePad::vfunc_6()
{
    {
        MS2Ptr<ASCheckBox> spUse = ((Unk_GpDialog*)GetOptionDialog())->GetTabCheckBox(CString("m_bGamePadUse"), -1);
        if (static_cast<ASCheckBox*>(spUse) != 0)
            reinterpret_cast<ASButton*>(spUse.operator->())->FUN_1422ce090(m_state.m_bUse);
    }
    {
        MS2Ptr<ASCheckBox> spSkill = ((Unk_GpDialog*)GetOptionDialog())->GetTabCheckBox(CString("m_bShowSkillName"), -1);
        if (static_cast<ASCheckBox*>(spSkill) != 0)
            reinterpret_cast<ASButton*>(spSkill.operator->())->FUN_1422ce090(m_state.m_bShowSkillName);
    }
    {
        MS2Ptr<ASSlider> spStick = ((Unk_GpDialog*)GetOptionDialog())->GetTabSlider(CString("m_gamePadLStickMoveSensitivity"), -1);
        if (static_cast<ASSlider*>(spStick) != 0)
            reinterpret_cast<MS2Ptr<ASSlider>&>(spStick)->FUN_1422ce5f0((float)m_state.m_nLStickSensitivity);
    }
    {
        MS2Ptr<ASCheckBox> spVibration = ((Unk_GpDialog*)GetOptionDialog())->GetTabCheckBox(CString("m_bVibration"), -1);
        if (static_cast<ASCheckBox*>(spVibration) != 0)
            reinterpret_cast<ASButton*>(spVibration.operator->())->FUN_1422ce090(m_state.m_bVibration);
    }
    {
        MS2Ptr<ASSlider> spH = ((Unk_GpDialog*)GetOptionDialog())->GetTabSlider(CString("m_sensitivityH"), -1);
        if (static_cast<ASSlider*>(spH) != 0)
            reinterpret_cast<MS2Ptr<ASSlider>&>(spH)->FUN_1422ce5f0(m_state.m_fSensitivityH * 100.0f);
    }
    {
        MS2Ptr<ASSlider> spV = ((Unk_GpDialog*)GetOptionDialog())->GetTabSlider(CString("m_sensitivityV"), -1);
        if (static_cast<ASSlider*>(spV) != 0)
            reinterpret_cast<MS2Ptr<ASSlider>&>(spV)->FUN_1422ce5f0(m_state.m_fSensitivityV * 100.0f);
    }
}
MS2_REPLACE_METHOD(0x140A572E0, CGameOptionGamePad, vfunc_6, 1098, 0x80A5AEFD);

// @0x140a57730
void CGameOptionGamePad::vfunc_7()
{
    {
        MS2Ptr<ASCheckBox> spUse = ((Unk_GpDialog*)GetOptionDialog())->GetTabCheckBox(CString("m_bGamePadUse"), -1);
        if (static_cast<ASCheckBox*>(spUse) != 0)
            m_state.m_bUse = reinterpret_cast<ASButton*>(spUse.operator->())->FUN_1422ce0e0() ? true : false;
    }
    {
        MS2Ptr<ASCheckBox> spSkill = ((Unk_GpDialog*)GetOptionDialog())->GetTabCheckBox(CString("m_bShowSkillName"), -1);
        if (static_cast<ASCheckBox*>(spSkill) != 0)
            m_state.m_bShowSkillName = reinterpret_cast<ASButton*>(spSkill.operator->())->FUN_1422ce0e0() ? true : false;
    }
    {
        MS2Ptr<ASSlider> spStick = ((Unk_GpDialog*)GetOptionDialog())->GetTabSlider(CString("m_gamePadLStickMoveSensitivity"), -1);
        if (static_cast<ASSlider*>(spStick) != 0)
        {
            if (CFeatureManager::GetInstance()->FUN_14036d570(0xd6))
                m_state.m_nLStickSensitivity = (int)reinterpret_cast<MS2Ptr<ASSlider>&>(spStick)->FUN_1422ce630();
            else
                m_state.m_nLStickSensitivity = 0;
        }
    }
    {
        MS2Ptr<ASCheckBox> spVibration = ((Unk_GpDialog*)GetOptionDialog())->GetTabCheckBox(CString("m_bVibration"), -1);
        if (static_cast<ASCheckBox*>(spVibration) != 0)
        {
            if (CFeatureManager::GetInstance()->FUN_14036d570(0xc3))
                m_state.m_bVibration = reinterpret_cast<ASButton*>(spVibration.operator->())->FUN_1422ce0e0() ? true : false;
            else
                m_state.m_bVibration = false;
        }
    }
    {
        MS2Ptr<ASSlider> spH = ((Unk_GpDialog*)GetOptionDialog())->GetTabSlider(CString("m_sensitivityH"), -1);
        if (static_cast<ASSlider*>(spH) != 0)
        {
            float fMin = 0.01f;
            float fValue = reinterpret_cast<MS2Ptr<ASSlider>&>(spH)->FUN_1422ce630() / 100.0f;
            m_state.m_fSensitivityH = (std::max)(fValue, fMin);
        }
    }
    {
        MS2Ptr<ASSlider> spV = ((Unk_GpDialog*)GetOptionDialog())->GetTabSlider(CString("m_sensitivityV"), -1);
        if (static_cast<ASSlider*>(spV) != 0)
        {
            float fMin = 0.01f;
            float fValue = reinterpret_cast<MS2Ptr<ASSlider>&>(spV)->FUN_1422ce630() / 100.0f;
            m_state.m_fSensitivityV = (std::max)(fValue, fMin);
        }
    }
}
MS2_REPLACE_METHOD(0x140A57730, CGameOptionGamePad, vfunc_7, 1247, 0xF0F4D26E);

// @0x140a57c20
void CGameOptionGamePad::vfunc_10()
{
    CBaseOption::vfunc_10();
    FUN_14125f640(GetGamepadState(reinterpret_cast<Unk_GpSettings*>(TSingleton<CGameOption>::GetInstance())), &m_state);
    SetGamepadEnabled(&m_state, m_state.m_bUse, true);
    if (FUN_140a58520(FUN_140a58540()) != 0)
    {
        MS2Ptr<ASMouseCursor> spHud = FUN_14025e7a0()->GetMouseCursor(6);
        if (static_cast<ASMouseCursor*>(spHud) != 0)
        {
            spHud->FUN_1422cee00();
            spHud->FUN_1422cee50((Unk_MouseCursorType)0);
        }
    }
}
MS2_REPLACE_METHOD(0x140A57C20, CGameOptionGamePad, vfunc_10, 211, 0xC0B451FA);

// @0x140a57d00
void CGameOptionGamePad::vfunc_12()
{
    CBaseOption::vfunc_12();
    FUN_14125f2c0(&m_state);
    LoadGameOptionGamepad(&m_state, (class TiXmlDocument*)(((void*)TSingleton<CGameOption>::GetInstance()->FUN_1412442a0())));
    vfunc_6();
}
MS2_REPLACE_METHOD(0x140A57D00, CGameOptionGamePad, vfunc_12, 87, 0x743F787E);

// @0x140a57d60
CString CGameOptionGamePad::GetTypeName()
{
    return CString("GameOptionLanguage");
}
MS2_REPLACE_METHOD(0x140A57D60, CGameOptionGamePad, GetTypeName, 61, 0xECB38628);

// MS2-FUNCTIONAL: the exe returns the raw memcmp int from a bool-declared slot (no setne)
// @0x140a57db0
int CGameOptionGamePad::vfunc_14()
{
    return memcmp(&m_state, GetGamepadState(reinterpret_cast<Unk_GpSettings*>(TSingleton<CGameOption>::GetInstance())), 0x10);
}

// @0x140a57df0
MS2Ptr<ASCheckBox> CreateCheckBox(int nId, const Scaleform::GFx::Value& v)
{
    MS2Ptr<ASCheckBox> tmp(new ASCheckBox(v, nId));
    return tmp;
}

// @0x140a57ea0
MS2Ptr<ASSlider> CreateSlider(int nId, const Scaleform::GFx::Value& v)
{
    MS2Ptr<ASSlider> tmp(new ASSlider(v, nId));
    return tmp;
}

// @0x140a57f50
MS2Ptr<ASCheckBox> Unk_GpDialog::GetTabCheckBox(CString name, int nIndex)
{
    if (m_root.IsNull())
        return MS2Ptr<ASCheckBox>(0);
    Scaleform::GFx::Value child = m_root->Invoke("getTabChild", name, nIndex);
    if (((Scaleform::GFx::Value*)(void*)(&child))->IsDisplayObject())
    {
        MS2Ptr<ASCheckBox> check = CreateCheckBox(m_nId, child);
        if (static_cast<ASCheckBox*>(check) != 0)
            return check;
    }
    return MS2Ptr<ASCheckBox>(0);
}

// @0x140a58110
MS2Ptr<ASSlider> Unk_GpDialog::GetTabSlider(CString name, int nIndex)
{
    if (m_root.IsNull())
        return MS2Ptr<ASSlider>(0);
    Scaleform::GFx::Value child = m_root->Invoke("getTabChild", name, nIndex);
    if (((Scaleform::GFx::Value*)(void*)(&child))->IsDisplayObject())
    {
        MS2Ptr<ASSlider> slider = CreateSlider(m_nId, child);
        if (static_cast<ASSlider*>(slider) != 0)
            return slider;
    }
    return MS2Ptr<ASSlider>(0);
}

// @0x140a58500
Unk_GpState* GetGamepadState(Unk_GpSettings* p)
{
    return &p->m_gamepad;
}

// @0x140a58520
int FUN_140a58520(void* pInput)
{
    return ((Unk_GpInputView*)pInput)->m_nCursorMode;
}

// @0x140a58540
MS2InputService* FUN_140a58540()
{
    return TSingleton<MS2InputService>::s_instance;
}
