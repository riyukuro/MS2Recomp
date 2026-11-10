// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIDebugTooltip: world-anchored debug tooltip UI.
// MS2-UNIT: ?\uidebugtooltip.cpp
// MS2-RANGE: 0x14191a7e0-0x14191b380 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uidebugtooltip.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <efd/Point3.h>
#include "uidebugtooltip.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asgameentity.h"
#include "ms2/placeholder/uiswfentitymanager.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/client/ms2/camera.h"

// ---- out-of-unit callees (bound to the exe by their FUN_<va> names / symbols) ----
#define DAT_143b01a60 (*(Vector3*)&efd::Point3::ZERO)          // C3: was extern Vector3 DAT_143b01a60
extern int g_nDebugUI;                                           // debug switch: UI always shown
int FUN_141277f40();                                                // next UI layer
class Unk_UIScale;
class Unk_AltStringMgr* GetGFxManager();   // C3: was GetGFxManager
class GFxManager   // C3: member view for the former free stand-ins
{
public:
    float GetMovieScale(int);
};
MS2Ptr<ASGameEntity> CreateGameEntity(int n, const Scaleform::GFx::Value& v);   // new ASGameEntity(v, n)

// @0x14191a7e0
UIDebugTooltip::UIDebugTooltip(CString strName)
    : m_68(1), m_6c(DAT_143b01a60), m_78(0), m_7c(0), m_80(0), m_88(L""), m_90(L""), m_98(strName)
{
    m_2c = 2;
    m_58 = 0;
    m_28 = FUN_141277f40();
    LoadSwf(m_2c, 0, 0);
}

// @0x14191a920
UIDebugTooltip::~UIDebugTooltip()
{
}

// @0x14191a9a0
CString UIDebugTooltip::GetTypeName()
{
    return "CubeUGCHead";
}
MS2_REPLACE_METHOD(0x14191A9A0, UIDebugTooltip, GetTypeName, 61, 0xDCE84F5B);

// @0x14191a9f0
int UIDebugTooltip::IsShown()
{
    return m_78;
}
MS2_REPLACE_METHOD(0x14191A9F0, UIDebugTooltip, IsShown, 14, 0xB1F80757);

// @0x14191aa10
void UIDebugTooltip::Show()
{
    m_7c = 1;
    m_78 = 1;
}
MS2_REPLACE_METHOD(0x14191AA10, UIDebugTooltip, Show, 30, 0x3D58469B);

// @0x14191aa40
void UIDebugTooltip::Hide()
{
    m_7c = 0;
    m_78 = 0;
}
MS2_REPLACE_METHOD(0x14191AA40, UIDebugTooltip, Hide, 30, 0xA515CB4B);

// @0x14191aa70
void UIDebugTooltip::FUN_14191aa70()
{
    GetUISwfEntityManager()->RemoveEntity(MS2Ptr<UISwfEntity>(this));
    m_7c = 0;
    m_78 = 0;
}
MS2_REPLACE_METHOD(0x14191AA70, UIDebugTooltip, FUN_14191aa70, 106, 0x4BC32DF7);

// @0x14191aae0
void UIDebugTooltip::FUN_14191aae0(Vector3 pt)
{
    m_6c = pt;
}
MS2_REPLACE_METHOD(0x14191AAE0, UIDebugTooltip, FUN_14191aae0, 41, 0xDEA29562);

// @0x14191ab10
void UIDebugTooltip::SetText(CStringW strText)
{
    m_7c = 1;
    m_88 = strText;
}
MS2_REPLACE_METHOD(0x14191AB10, UIDebugTooltip, SetText, 77, 0x4449CF6B);

// @0x14191ab70
void UIDebugTooltip::SetAdditionalText(CStringW strAdditional)
{
    m_7c = 1;
    m_90 = strAdditional;
}
MS2_REPLACE_METHOD(0x14191AB70, UIDebugTooltip, SetAdditionalText, 77, 0x49FED853);

// @0x14191abd0
void UIDebugTooltip::ToggleAdditionalText()
{
    if (m_30.IsNull())
        return;
    MS2Ptr<ASMovieClip> pClip(dynamic_cast<ASMovieClip*>((AScript*)m_30));
    if (pClip.get())
    {
        if (m_80 != 0)
        {
            pClip->Invoke("showAdditional", 0);
            m_80 = 0;
        }
        else
        {
            pClip->Invoke("showAdditional", 1);
            m_80 = 1;
        }
    }
}
MS2_REPLACE_METHOD(0x14191ABD0, UIDebugTooltip, ToggleAdditionalText, 300, 0xABC3CC9C);

// @0x14191ad10
void UIDebugTooltip::vfunc_2()
{
    UISwfEntity::vfunc_2();
    LoadSwf(m_2c, m_44, 0);
    Show();
}
MS2_REPLACE_METHOD(0x14191AD10, UIDebugTooltip, vfunc_2, 64, 0xD42C3A42);

// @0x14191ad60
void UIDebugTooltip::vfunc_3()
{
    UISwfEntity::vfunc_3();
    FUN_1422dc080();
    Hide();
}
MS2_REPLACE_METHOD(0x14191AD60, UIDebugTooltip, vfunc_3, 44, 0xCD6070CD);

// @0x14191ada0
void UIDebugTooltip::vfunc_52()
{
    if (m_30.IsNull())
        return;
    int nDebug = 0;
    nDebug = g_nDebugUI;
    MS2Ptr<ASMovieClip> pClip(dynamic_cast<ASMovieClip*>((AScript*)m_30));
    if (pClip.get())
    {
        if (m_68 != 0 && nDebug == 0)
            vfunc_8(0);
        else
            vfunc_8(1);
        ((class ASDisplayObject*)(class ASDisplayObject*)(pClip.operator->()))->SetAlpha(100.0f);
        reinterpret_cast<AScript*>(pClip.operator->())->Invoke("setData", m_88, m_98);
        reinterpret_cast<AScript*>(pClip.operator->())->Invoke("setAdditional", m_90, 0);
        pClip->Invoke("setFontSize", 0x12);
        pClip->Invoke("setFontColor", 0x3df0fb);
        m_7c = 0;
    }
}

MS2_REPLACE_METHOD(0x14191ADA0, UIDebugTooltip, vfunc_52, 698, 0x32A63BE5);

// @0x14191b060
void UIDebugTooltip::vfunc_15()
{
    UISwfEntity::vfunc_15();
    if (m_30.IsNull())
        return;
    if (m_7c != 0)
        vfunc_52();
    if (IsShown())
        UpdateScreenPosition();
    else
        vfunc_8(0);
}
MS2_REPLACE_METHOD(0x14191B060, UIDebugTooltip, vfunc_15, 124, 0xD6382227);

// @0x14191b0f0
int UIDebugTooltip::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UISwfEntity::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    return 0;
}
MS2_REPLACE_METHOD(0x14191B0F0, UIDebugTooltip, vfunc_28, 67, 0xE589D637);

// @0x14191b140
void UIDebugTooltip::UpdateScreenPosition()
{
    Vector3 screen;
    int nDebug = 0;
    nDebug = g_nDebugUI;
    if (TSingleton<CameraMgr>::GetInstance()->FUN_140af0700(reinterpret_cast<const efd::Point3&>(m_6c), reinterpret_cast<NiPoint3&>(screen)))
    {
        MS2Ptr<ASGameEntity> pEntity(dynamic_cast<ASGameEntity*>((AScript*)m_30));
        if (pEntity.get())
        {
            if (m_68 != 0 && nDebug == 0)
                vfunc_8(0);
            else
                vfunc_8(1);
            reinterpret_cast<efd::Point3&>(screen) *= ((class GFxManager*)(class Unk_UIScale*)(((class Unk_UIScale*)GetGFxManager())))->GetMovieScale(m_28);
            ((class ASDisplayObject*)(class ASGameEntity*)(pEntity.operator->()))->SetPositionFloat(screen.x, screen.y);
        }
    }
    else
        vfunc_8(0);
}
MS2_REPLACE_METHOD(0x14191B140, UIDebugTooltip, UpdateScreenPosition, 368, 0x8BB371DA);

// @0x14191b2c0
void UIDebugTooltip::vfunc_41(const Scaleform::GFx::Value& root)
{
    m_30 = CreateGameEntity(m_28, root);
}
MS2_REPLACE_METHOD(0x14191B2C0, UIDebugTooltip, vfunc_41, 99, 0x4082510E);
