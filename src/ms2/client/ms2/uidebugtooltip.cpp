// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIDebugTooltip: world-anchored debug tooltip UI.
// MS2-UNIT: ?\uidebugtooltip.cpp
// MS2-RANGE: 0x14191a7e0-0x14191b380 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uidebugtooltip.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "uidebugtooltip.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asgameentity.h"
#include "ms2/placeholder/uiswfentitymanager.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- out-of-unit callees (bound to the exe by their FUN_<va> names / symbols) ----
extern Vector3 DAT_143b01a60;                               // the zero point
extern int DAT_143ae0fc0;                                           // debug switch: UI always shown
int FUN_141277f40();                                                // next UI layer
class Unk_WorldToScreen { public: bool FUN_140af0700(const Vector3& world, Vector3& out); };
Unk_WorldToScreen* FUN_1409478c0();                                 // camera service
class Unk_UIScale;
Unk_UIScale* FUN_14025e7a0();                                       // ui scale service
float FUN_1422afec0(Unk_UIScale* pScale, int nLayer);               // scale of a layer
Vector3* FUN_140ad0c10(Vector3* pt, float f);       // efd::Point3::operator*=
void FUN_1422bfe00(ASDisplayObject* pObj, float fAlpha);            // set the alpha
void FUN_1422c00f0(ASGameEntity* pEntity, float x, float y);        // set the position
MS2Ptr<ASGameEntity> FUN_140ba77e0(int n, const Scaleform::GFx::Value& v);   // new ASGameEntity(v, n)
// AS invokers on the tooltip's movie clip (instances of the AScript::Invoke templates).
class Unk_TooltipMovie
{
public:
    Scaleform::GFx::Value FUN_140e0a8c0(const char* szMethod, CStringW a1, int a2);
    Scaleform::GFx::Value FUN_1412cc450(const char* szMethod, CStringW a1, CString a2);
};

// @0x14191a7e0
UIDebugTooltip::UIDebugTooltip(CString strName)
    : m_68(1), m_6c(DAT_143b01a60), m_78(0), m_7c(0), m_80(0), m_88(L""), m_90(L""), m_98(strName)
{
    m_2c = 2;
    m_58 = 0;
    m_28 = FUN_141277f40();
    FUN_1422dbf00(m_2c, 0, 0);
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
int UIDebugTooltip::FUN_14191a9f0()
{
    return m_78;
}
MS2_REPLACE_METHOD(0x14191A9F0, UIDebugTooltip, FUN_14191a9f0, 14, 0xB1F80757);

// @0x14191aa10
void UIDebugTooltip::FUN_14191aa10()
{
    m_7c = 1;
    m_78 = 1;
}
MS2_REPLACE_METHOD(0x14191AA10, UIDebugTooltip, FUN_14191aa10, 30, 0x3D58469B);

// @0x14191aa40
void UIDebugTooltip::FUN_14191aa40()
{
    m_7c = 0;
    m_78 = 0;
}
MS2_REPLACE_METHOD(0x14191AA40, UIDebugTooltip, FUN_14191aa40, 30, 0xA515CB4B);

// @0x14191aa70
void UIDebugTooltip::FUN_14191aa70()
{
    FUN_140b632f0()->FUN_1422d0dc0(MS2Ptr<UISwfEntity>(this));
    m_7c = 0;
    m_78 = 0;
}
MS2_REPLACE_METHOD(0x14191AA70, UIDebugTooltip, FUN_14191aa70, 106, 0x4BC32DF7);

// @0x14191aae0
void UIDebugTooltip::FUN_14191aae0(const Vector3& pt)
{
    m_6c = pt;
}
MS2_REPLACE_METHOD(0x14191AAE0, UIDebugTooltip, FUN_14191aae0, 41, 0xDEA29562);

// @0x14191ab10
void UIDebugTooltip::FUN_14191ab10(CStringW strText)
{
    m_7c = 1;
    m_88 = strText;
}
MS2_REPLACE_METHOD(0x14191AB10, UIDebugTooltip, FUN_14191ab10, 77, 0x4449CF6B);

// @0x14191ab70
void UIDebugTooltip::FUN_14191ab70(CStringW strAdditional)
{
    m_7c = 1;
    m_90 = strAdditional;
}
MS2_REPLACE_METHOD(0x14191AB70, UIDebugTooltip, FUN_14191ab70, 77, 0x49FED853);

// @0x14191abd0
void UIDebugTooltip::FUN_14191abd0()
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
MS2_REPLACE_METHOD(0x14191ABD0, UIDebugTooltip, FUN_14191abd0, 300, 0xABC3CC9C);

// @0x14191ad10
void UIDebugTooltip::vfunc_2()
{
    UISwfEntity::vfunc_2();
    FUN_1422dbf00(m_2c, m_44, 0);
    FUN_14191aa10();
}
MS2_REPLACE_METHOD(0x14191AD10, UIDebugTooltip, vfunc_2, 64, 0xD42C3A42);

// @0x14191ad60
void UIDebugTooltip::vfunc_3()
{
    UISwfEntity::vfunc_3();
    FUN_1422dc080();
    FUN_14191aa40();
}
MS2_REPLACE_METHOD(0x14191AD60, UIDebugTooltip, vfunc_3, 44, 0xCD6070CD);

// @0x14191ada0
void UIDebugTooltip::vfunc_52()
{
    if (m_30.IsNull())
        return;
    int nDebug = 0;
    nDebug = DAT_143ae0fc0;
    MS2Ptr<ASMovieClip> pClip(dynamic_cast<ASMovieClip*>((AScript*)m_30));
    if (pClip.get())
    {
        if (m_68 != 0 && nDebug == 0)
            vfunc_8(0);
        else
            vfunc_8(1);
        FUN_1422bfe00(pClip.operator->(), 100.0f);
        reinterpret_cast<Unk_TooltipMovie*>(pClip.operator->())->FUN_1412cc450("setData", m_88, m_98);
        reinterpret_cast<Unk_TooltipMovie*>(pClip.operator->())->FUN_140e0a8c0("setAdditional", m_90, 0);
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
    if (FUN_14191a9f0())
        FUN_14191b140();
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
void UIDebugTooltip::FUN_14191b140()
{
    Vector3 screen;
    int nDebug = 0;
    nDebug = DAT_143ae0fc0;
    if (FUN_1409478c0()->FUN_140af0700(m_6c, screen))
    {
        MS2Ptr<ASGameEntity> pEntity(dynamic_cast<ASGameEntity*>((AScript*)m_30));
        if (pEntity.get())
        {
            if (m_68 != 0 && nDebug == 0)
                vfunc_8(0);
            else
                vfunc_8(1);
            FUN_140ad0c10(&screen, FUN_1422afec0(FUN_14025e7a0(), m_28));
            FUN_1422c00f0(pEntity.operator->(), screen.x, screen.y);
        }
    }
    else
        vfunc_8(0);
}
MS2_REPLACE_METHOD(0x14191B140, UIDebugTooltip, FUN_14191b140, 368, 0x8BB371DA);

// @0x14191b2c0
void UIDebugTooltip::vfunc_41(const Scaleform::GFx::Value& root)
{
    m_30 = FUN_140ba77e0(m_28, root);
}
MS2_REPLACE_METHOD(0x14191B2C0, UIDebugTooltip, vfunc_41, 99, 0x4082510E);
