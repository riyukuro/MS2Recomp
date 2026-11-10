// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIBirdHead: world-anchored bird head tooltip UI.
// MS2-UNIT: ?\uibirdhead.cpp
// MS2-RANGE: 0x1418ce5e0-0x1418cf080 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uibirdhead.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <efd/Point3.h>
#include "uibirdhead.h"
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

// @0x1418ce5e0
UIBirdHead::UIBirdHead()
    : m_68(1), m_6c(DAT_143b01a60), m_78(0), m_7c(0), m_80(0), m_88(L""), m_90(L""), m_98(L""), m_a0(0.0f)
{
    m_28 = FUN_141277f40();
    m_58 = 0;
    LoadSwf(2, 0, 0);
}

// @0x1418ce710
UIBirdHead::~UIBirdHead()
{
}

// @0x1418ce790
CString UIBirdHead::GetTypeName()
{
    return "BirdHead";
}
MS2_REPLACE_METHOD(0x1418CE790, UIBirdHead, GetTypeName, 61, 0xF8542D70);

// @0x1418ce7e0
int UIBirdHead::IsShown()
{
    return m_78;
}
MS2_REPLACE_METHOD(0x1418CE7E0, UIBirdHead, IsShown, 14, 0xB1F80757);

// @0x1418ce800
void UIBirdHead::Show()
{
    m_7c = 1;
    m_78 = 1;
}
MS2_REPLACE_METHOD(0x1418CE800, UIBirdHead, Show, 30, 0x3D58469B);

// @0x1418ce830
void UIBirdHead::FUN_1418ce830()
{
    GetUISwfEntityManager()->RemoveEntity(MS2Ptr<UISwfEntity>(this));
}
MS2_REPLACE_METHOD(0x1418CE830, UIBirdHead, FUN_1418ce830, 82, 0x099CC8F3);

// @0x1418ce890
void UIBirdHead::Hide()
{
    m_7c = 0;
    m_78 = 0;
}
MS2_REPLACE_METHOD(0x1418CE890, UIBirdHead, Hide, 30, 0xA515CB4B);

// @0x1418ce8c0
void UIBirdHead::FUN_1418ce8c0(const Vector3& pt)
{
    m_6c = pt;
}
MS2_REPLACE_METHOD(0x1418CE8C0, UIBirdHead, FUN_1418ce8c0, 41, 0x197B3CE1);

// @0x1418ce8f0
void UIBirdHead::FUN_1418ce8f0(CStringW strMain, CStringW strExtra)
{
    m_7c = 1;
    m_88 = strMain;
    m_98 = strExtra;
}
MS2_REPLACE_METHOD(0x1418CE8F0, UIBirdHead, FUN_1418ce8f0, 119, 0x3596772E);

// @0x1418ce970
void UIBirdHead::SetAdditionalText(CStringW strAdditional)
{
    m_7c = 1;
    m_90 = strAdditional;
}
MS2_REPLACE_METHOD(0x1418CE970, UIBirdHead, SetAdditionalText, 77, 0xB29FF3CF);

// @0x1418ce9d0
void UIBirdHead::ToggleAdditionalText()
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
MS2_REPLACE_METHOD(0x1418CE9D0, UIBirdHead, ToggleAdditionalText, 300, 0x6075389F);

// @0x1418ceb10
void UIBirdHead::vfunc_52()
{
    if (m_30.IsNull())
        return;
    MS2Ptr<ASMovieClip> pClip(dynamic_cast<ASMovieClip*>((AScript*)m_30));
    if (pClip.get())
    {
        vfunc_8(1);
        ((class ASDisplayObject*)(class ASDisplayObject*)(pClip.operator->()))->SetAlpha(100.0f);
        reinterpret_cast<AScript*>(pClip.operator->())->Invoke("setData", m_88, m_98);
        reinterpret_cast<AScript*>(pClip.operator->())->Invoke("setAdditional", m_90, 0);
        pClip->Invoke("setFontSize", 0x12);
        pClip->Invoke("setFontColor", 0x3df0fb);
        m_7c = 0;
    }
}
MS2_REPLACE_METHOD(0x1418CEB10, UIBirdHead, vfunc_52, 627, 0x98249AF1);

// @0x1418ced90
void UIBirdHead::vfunc_15()
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
MS2_REPLACE_METHOD(0x1418CED90, UIBirdHead, vfunc_15, 124, 0x11303266);

// @0x1418cee20
int UIBirdHead::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UISwfEntity::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    return 0;
}
MS2_REPLACE_METHOD(0x1418CEE20, UIBirdHead, vfunc_28, 67, 0xFC04CE34);

// @0x1418cee70
void UIBirdHead::UpdateScreenPosition()
{
    Vector3 screen;
    if (TSingleton<CameraMgr>::GetInstance()->FUN_140af0700(reinterpret_cast<const efd::Point3&>(m_6c), reinterpret_cast<NiPoint3&>(screen)))
    {
        MS2Ptr<ASGameEntity> pEntity(dynamic_cast<ASGameEntity*>((AScript*)m_30));
        if (pEntity.get())
        {
            vfunc_8(1);
            reinterpret_cast<efd::Point3&>(screen) *= ((class GFxManager*)(class Unk_UIScale*)(((class Unk_UIScale*)GetGFxManager())))->GetMovieScale(m_28);
            ((class ASDisplayObject*)(class ASGameEntity*)(pEntity.operator->()))->SetPositionFloat(screen.x, screen.y + m_a0);
        }
    }
    else
        vfunc_8(0);
}
MS2_REPLACE_METHOD(0x1418CEE70, UIBirdHead, UpdateScreenPosition, 330, 0x050CB4DE);

// @0x1418cefc0
void UIBirdHead::vfunc_41(const Scaleform::GFx::Value& root)
{
    m_30 = CreateGameEntity(m_28, root);
}
MS2_REPLACE_METHOD(0x1418CEFC0, UIBirdHead, vfunc_41, 99, 0xFBAD23FE);
