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

// ---- unit-local placeholders ----

// A checkbox-like AS entity of the option dialog (0x88 bytes).
class Unk_GpCheck : public CPtred
{
public:
    Unk_GpCheck(const Scaleform::GFx::Value& v, int nId);       // 0x1422ceac0
    void FUN_1422ce090(int bChecked);
    unsigned char FUN_1422ce0e0();
private:
    char m_pad[0x88 - sizeof(CPtred)];
};

// A slider AS entity of the option dialog (0x88 bytes); the value is a float.
class Unk_GpSlider : public CPtred
{
public:
    Unk_GpSlider(const Scaleform::GFx::Value& v, int nId);      // 0x1422ce570
    void FUN_1422ce5f0(float f);
    float FUN_1422ce630();
private:
    char m_pad[0x88 - sizeof(CPtred)];
};

// The gamepad cursor HUD dialog (UI id 6).
class Unk_GpHud : public CPtred
{
public:
    void FUN_1422cee00();
    void FUN_1422cee50(int n);
};

class Unk_GpHudMgr { public: MS2Ptr<Unk_GpHud> FUN_1422b0370(int nDialogId); };
Unk_GpHudMgr* FUN_14025e7a0();

// The game-option settings object returned by FUN_1409a8b10 (+0x1a0 is the saved gamepad block).
class Unk_GpSettings
{
public:
    char m_pad[0x1a0];
    Unk_GpState m_gamepad;
    char m_pad2[0x230 - 0x1b0];
    char m_defaults;                // +0x230 the default block
};
Unk_GpSettings* FUN_1409a8b10();
Unk_GpState* FUN_140a58500(Unk_GpSettings* p);
void* FUN_1412442a0(Unk_GpSettings* p);

// The state block's methods (0x14125f290...).
void FUN_14125f290(Unk_GpState* p);
void FUN_14125f2c0(Unk_GpState* p);
void FUN_14125f330(Unk_GpState* p, void* pDefaults);
void FUN_14125f640(Unk_GpState* pDst, const Unk_GpState* pSrc);
void FUN_14125f670(Unk_GpState* p, bool bUse, bool bNotify);

CFeatureManager* FUN_140166410();

// View of the option dialog: the option id at +0x28 and the AS root at +0x30.
struct Unk_GpDialog
{
    char m_pad[0x28];
    int m_nId;
    int m_pad2;
    MS2Ptr<AScript> m_root;
    MS2Ptr<class Unk_GpCheck> FUN_140a57f50(CString name, int nIndex);
    MS2Ptr<class Unk_GpSlider> FUN_140a58110(CString name, int nIndex);
};
struct Unk_GpInputView { char m_pad[0x124]; int m_nCursorMode; };
int FUN_140a58520(void* pInput);                                // MS2InputService::m_nCursorMode
MS2InputService* FUN_140a58540();                               // TSingleton<MS2InputService>::GetInstance

MS2Ptr<Unk_GpCheck> FUN_140a57df0(int nId, const Scaleform::GFx::Value& v);
MS2Ptr<Unk_GpSlider> FUN_140a57ea0(int nId, const Scaleform::GFx::Value& v);
bool FUN_1407cce10(const Scaleform::GFx::Value* v);

// ---- CGameOptionGamePad ----
// @0x140a571b0
CGameOptionGamePad::CGameOptionGamePad(int nId, int nType)
    : CBaseOption(nId, nType)
{
    FUN_14125f290(&m_state);
}

// @0x140a57210
CGameOptionGamePad::~CGameOptionGamePad()
{
}

// @0x140a57240
void CGameOptionGamePad::vfunc_3(int n)
{
    if (n == 0)
        FUN_14125f640(&m_state, FUN_140a58500(FUN_1409a8b10()));
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
        MS2Ptr<Unk_GpCheck> spUse = ((Unk_GpDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_bGamePadUse"), -1);
        if (static_cast<Unk_GpCheck*>(spUse) != 0)
            spUse->FUN_1422ce090(m_state.m_bUse);
    }
    {
        MS2Ptr<Unk_GpCheck> spSkill = ((Unk_GpDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_bShowSkillName"), -1);
        if (static_cast<Unk_GpCheck*>(spSkill) != 0)
            spSkill->FUN_1422ce090(m_state.m_bShowSkillName);
    }
    {
        MS2Ptr<Unk_GpSlider> spStick = ((Unk_GpDialog*)GetOptionDialog())->FUN_140a58110(CString("m_gamePadLStickMoveSensitivity"), -1);
        if (static_cast<Unk_GpSlider*>(spStick) != 0)
            spStick->FUN_1422ce5f0((float)m_state.m_nLStickSensitivity);
    }
    {
        MS2Ptr<Unk_GpCheck> spVibration = ((Unk_GpDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_bVibration"), -1);
        if (static_cast<Unk_GpCheck*>(spVibration) != 0)
            spVibration->FUN_1422ce090(m_state.m_bVibration);
    }
    {
        MS2Ptr<Unk_GpSlider> spH = ((Unk_GpDialog*)GetOptionDialog())->FUN_140a58110(CString("m_sensitivityH"), -1);
        if (static_cast<Unk_GpSlider*>(spH) != 0)
            spH->FUN_1422ce5f0(m_state.m_fSensitivityH * 100.0f);
    }
    {
        MS2Ptr<Unk_GpSlider> spV = ((Unk_GpDialog*)GetOptionDialog())->FUN_140a58110(CString("m_sensitivityV"), -1);
        if (static_cast<Unk_GpSlider*>(spV) != 0)
            spV->FUN_1422ce5f0(m_state.m_fSensitivityV * 100.0f);
    }
}
MS2_REPLACE_METHOD(0x140A572E0, CGameOptionGamePad, vfunc_6, 1098, 0x80A5AEFD);

// @0x140a57730
void CGameOptionGamePad::vfunc_7()
{
    {
        MS2Ptr<Unk_GpCheck> spUse = ((Unk_GpDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_bGamePadUse"), -1);
        if (static_cast<Unk_GpCheck*>(spUse) != 0)
            m_state.m_bUse = spUse->FUN_1422ce0e0() ? true : false;
    }
    {
        MS2Ptr<Unk_GpCheck> spSkill = ((Unk_GpDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_bShowSkillName"), -1);
        if (static_cast<Unk_GpCheck*>(spSkill) != 0)
            m_state.m_bShowSkillName = spSkill->FUN_1422ce0e0() ? true : false;
    }
    {
        MS2Ptr<Unk_GpSlider> spStick = ((Unk_GpDialog*)GetOptionDialog())->FUN_140a58110(CString("m_gamePadLStickMoveSensitivity"), -1);
        if (static_cast<Unk_GpSlider*>(spStick) != 0)
        {
            if (FUN_140166410()->FUN_14036d570(0xd6))
                m_state.m_nLStickSensitivity = (int)spStick->FUN_1422ce630();
            else
                m_state.m_nLStickSensitivity = 0;
        }
    }
    {
        MS2Ptr<Unk_GpCheck> spVibration = ((Unk_GpDialog*)GetOptionDialog())->FUN_140a57f50(CString("m_bVibration"), -1);
        if (static_cast<Unk_GpCheck*>(spVibration) != 0)
        {
            if (FUN_140166410()->FUN_14036d570(0xc3))
                m_state.m_bVibration = spVibration->FUN_1422ce0e0() ? true : false;
            else
                m_state.m_bVibration = false;
        }
    }
    {
        MS2Ptr<Unk_GpSlider> spH = ((Unk_GpDialog*)GetOptionDialog())->FUN_140a58110(CString("m_sensitivityH"), -1);
        if (static_cast<Unk_GpSlider*>(spH) != 0)
        {
            float fMin = 0.01f;
            float fValue = spH->FUN_1422ce630() / 100.0f;
            m_state.m_fSensitivityH = (std::max)(fValue, fMin);
        }
    }
    {
        MS2Ptr<Unk_GpSlider> spV = ((Unk_GpDialog*)GetOptionDialog())->FUN_140a58110(CString("m_sensitivityV"), -1);
        if (static_cast<Unk_GpSlider*>(spV) != 0)
        {
            float fMin = 0.01f;
            float fValue = spV->FUN_1422ce630() / 100.0f;
            m_state.m_fSensitivityV = (std::max)(fValue, fMin);
        }
    }
}
MS2_REPLACE_METHOD(0x140A57730, CGameOptionGamePad, vfunc_7, 1247, 0xF0F4D26E);

// @0x140a57c20
void CGameOptionGamePad::vfunc_10()
{
    CBaseOption::vfunc_10();
    FUN_14125f640(FUN_140a58500(FUN_1409a8b10()), &m_state);
    FUN_14125f670(&m_state, m_state.m_bUse, true);
    if (FUN_140a58520(FUN_140a58540()) != 0)
    {
        MS2Ptr<Unk_GpHud> spHud = FUN_14025e7a0()->FUN_1422b0370(6);
        if (static_cast<Unk_GpHud*>(spHud) != 0)
        {
            spHud->FUN_1422cee00();
            spHud->FUN_1422cee50(0);
        }
    }
}
MS2_REPLACE_METHOD(0x140A57C20, CGameOptionGamePad, vfunc_10, 211, 0xC0B451FA);

// @0x140a57d00
void CGameOptionGamePad::vfunc_12()
{
    CBaseOption::vfunc_12();
    FUN_14125f2c0(&m_state);
    FUN_14125f330(&m_state, FUN_1412442a0(FUN_1409a8b10()));
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
    return memcmp(&m_state, FUN_140a58500(FUN_1409a8b10()), 0x10);
}

// @0x140a57df0
MS2Ptr<Unk_GpCheck> FUN_140a57df0(int nId, const Scaleform::GFx::Value& v)
{
    MS2Ptr<Unk_GpCheck> tmp(new Unk_GpCheck(v, nId));
    return tmp;
}

// @0x140a57ea0
MS2Ptr<Unk_GpSlider> FUN_140a57ea0(int nId, const Scaleform::GFx::Value& v)
{
    MS2Ptr<Unk_GpSlider> tmp(new Unk_GpSlider(v, nId));
    return tmp;
}

// @0x140a57f50
MS2Ptr<Unk_GpCheck> Unk_GpDialog::FUN_140a57f50(CString name, int nIndex)
{
    if (m_root.IsNull())
        return MS2Ptr<Unk_GpCheck>(0);
    Scaleform::GFx::Value child = m_root->Invoke("getTabChild", name, nIndex);
    if (FUN_1407cce10(&child))
    {
        MS2Ptr<Unk_GpCheck> check = FUN_140a57df0(m_nId, child);
        if (static_cast<Unk_GpCheck*>(check) != 0)
            return check;
    }
    return MS2Ptr<Unk_GpCheck>(0);
}

// @0x140a58110
MS2Ptr<Unk_GpSlider> Unk_GpDialog::FUN_140a58110(CString name, int nIndex)
{
    if (m_root.IsNull())
        return MS2Ptr<Unk_GpSlider>(0);
    Scaleform::GFx::Value child = m_root->Invoke("getTabChild", name, nIndex);
    if (FUN_1407cce10(&child))
    {
        MS2Ptr<Unk_GpSlider> slider = FUN_140a57ea0(m_nId, child);
        if (static_cast<Unk_GpSlider*>(slider) != 0)
            return slider;
    }
    return MS2Ptr<Unk_GpSlider>(0);
}

// @0x140a58500
Unk_GpState* FUN_140a58500(Unk_GpSettings* p)
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
