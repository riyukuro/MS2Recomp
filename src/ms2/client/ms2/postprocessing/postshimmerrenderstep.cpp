// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// MS2-UNIT: ?\postshimmerrenderstep.cpp
// MS2-RANGE: 0x1400cf2b0-0x1400cf480 .text$di
// MS2-RANGE: 0x140c8efe0-0x140c90340 .text$mn
// MS2-PIN: ??0NiPoint2@@QEAA@XZ 0x140c90180
// MS2-PIN: ??1CPostEffectParam@@UEAA@XZ 0x140c901a0
// MS2-PIN: ??1PostShimmerEffect@@UEAA@XZ 0x140c901c0
// MS2-PIN: ??1PostShimmerEffectParam@@UEAA@XZ 0x140c901f0
// MS2-PIN: ??Defd@@YA?AVPoint2@0@MAEBV10@@Z 0x140c90220
// MS2-PIN: ??_GPostShimmerEffect@@UEAAPEAXI@Z 0x140c90260
// MS2-PIN: ??_GPostShimmerEffectParam@@UEAAPEAXI@Z 0x140c902a0
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\postshimmerrenderstep.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "postshimmerrenderstep.h"
#include <NiTexturingProperty.h>
#include <NiViewRenderClick.h>
#include <NiScreenFillingRenderView.h>
#include <NiShaderFactory.h>
#include <NiRenderObject.h>
#include <atlcoll.h>
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// Main system (commonfiles singleton 0x14086d260): resource root path and the current time in seconds.
class Unk_MainSystem
{
public:
    CString FUN_1414736e0();
    double FUN_141473280();
};
Unk_MainSystem* FUN_14086d260();

// Resource manager (singleton 0x140a0afd0): texture load by path.
class Unk_ResourceMgr
{
public:
    Unk_PPSmartC FUN_141552f90(CString strPath, int nFlags);
};
Unk_ResourceMgr* FUN_140a0afd0();
CString FUN_14016a5c0(const char* psz, int n);          // path normalise

// Post-processing service (singleton 0x1409a8b20): find step by id, enable step by id.
class Unk_PostProcessSvc
{
public:
    void* FUN_1416a3a90(int nId);
    void FUN_1416a3920(int nId, bool bOn);
};
Unk_PostProcessSvc* FUN_1409a8b20();

// TinyXML attribute helpers (commonfiles\tinyxmlhelper.cpp).
int FUN_140873360(Unk_140165cf0* pNode, const char* pszName, float& fOut);
int FUN_1408733e0(Unk_140165cf0* pNode, const char* pszName, CString& strOut);

// Global shader constant setters (validate, then NiShaderFactory::UpdateGlobalShaderConstant). The float one lives in
// another unit; the NiPoint2 one is emitted here.
void FUN_1409a5770(const NiFixedString& kName, const float* pf, int n);
bool FUN_140c900e0(const NiFixedString& kName, const efd::Point2* pk, int n);
int FUN_140c902f0(const efd::Point2& k);               // both components finite
void FUN_140c8f490(Unk_PPSmartC spTexture);             // swap the shimmer texture of the live step
void* FUN_14097fbe0(void* smartPtr);                    // PostProcessEffect m_88 getter

extern NiFixedString DAT_143ae5438;                     // shimmer blend constant name
extern NiFixedString DAT_143ae5448;                     // shimmer uv-move constant name

// @0x143abf728 (no initializer; zero-initialised)
static NiTexturingProperty* s_pkShimmerProp;

// @0x1400cf2b0
static Unk_PPSmartC s_shimmerTexture(0);

// @0x1400cf2e0
const NiRTTI PostShimmerRenderStep::ms_RTTI("PostShimmerRenderStep", &NiDefaultClickRenderStep::ms_RTTI);

// Header-defined statics (same strings as client\ms2\scenestatemove.cpp's initializers).
// @0x1400cf310
static CString s_sortNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
// @0x1400cf3d0
static CString s_skill("skill");
// @0x1400cf400
static CString s_stun("stun");
// @0x1400cf430
static ATL::CAtlMap<unsigned int, CString> s_conditions(17, .75f, .25f, 2.25f, 10);

// ---------------------------------------------------------------------------------------------------------------
// PostShimmerRenderStep

// @0x140c8efe0
PostShimmerRenderStep::PostShimmerRenderStep(unsigned __int64 a, unsigned int b) : PostProcessEffect(a, b)
{
    NiFixedString kName("PostShimmerRenderStep");
    SetName(kName);
}

// @0x140c8f060
PostShimmerRenderStep::~PostShimmerRenderStep()
{
}

// @0x140c8f090
bool PostShimmerRenderStep::vfunc_15(unsigned int a, void* b)
{
    if (!PostProcessEffect::vfunc_15(a, 0) || m_70 == 0)
        return false;
    CString strPath;
    strPath.Format("%s/Image/ScreenMask/shimmer.tga", (const char*)FUN_14086d260()->FUN_1414736e0());
    s_shimmerTexture = FUN_140a0afd0()->FUN_141552f90(CString((const char*)FUN_14016a5c0((const char*)strPath, 0)), 5);
    NiViewRenderClick* pkClick = (NiViewRenderClick*)FUN_140c8f690(FUN_1416b4990(this, "PostShimmer", 0, this,
        FUN_140c8f680(&m_80), 0, 0, 0, "PostShimmer", s_shimmerTexture.Get(), 0, 0));
    if (pkClick == 0)
    {
        vfunc_16();
        return false;
    }
    NiScreenFillingRenderView* pkView = NiDynamicCast(NiScreenFillingRenderView, pkClick->GetRenderViews().GetHead());
    s_pkShimmerProp = (NiTexturingProperty*)pkView->GetScreenFillingQuad().GetProperty(NiProperty::TEXTURING);
    NiTexturingProperty::ShaderMap* pkMap = new (efd::MemHint(efd::MemHint::NONE)) NiTexturingProperty::ShaderMap(
        (NiTexture*)s_shimmerTexture.Get(), 0, (NiTexturingProperty::ClampMode)0, (NiTexturingProperty::FilterMode)0, 0);
    s_pkShimmerProp->SetShaderMap(0, pkMap);
    return true;
}
MS2_REPLACE_METHOD(0x140c8f090, PostShimmerRenderStep, vfunc_15, 1014, 0xBACEC7B6);

#ifndef MS2_HOOK_DLL
// @0x140c8f490
void FUN_140c8f490(Unk_PPSmartC spTexture)
{
    if (s_pkShimmerProp != 0)
    {
        void* pStep = FUN_1409a8b20()->FUN_1416a3a90(0x12);
        if (pStep != 0)
        {
            s_shimmerTexture = spTexture;
            NiTexturingProperty::ShaderMap* pkMap = new (efd::MemHint(efd::MemHint::NONE)) NiTexturingProperty::ShaderMap(
                (NiTexture*)s_shimmerTexture.Get(), 0, (NiTexturingProperty::ClampMode)0,
                (NiTexturingProperty::FilterMode)0, 0);
            s_pkShimmerProp->SetShaderMap(0, pkMap);
        }
    }
}
#endif

// @0x140c8f5a0
void PostShimmerRenderStep::vfunc_16()
{
    PostProcessEffect::vfunc_16();
    s_shimmerTexture.Assign(0);
}
MS2_REPLACE_METHOD(0x140c8f5a0, PostShimmerRenderStep, vfunc_16, 38, 0xD507FABE);

// @0x140c8f680
void* FUN_140c8f680(void* smartPtr)
{
    return *(void**)smartPtr;
}

// @0x140c8f690
void* FUN_140c8f690(const Unk_PPRes& res)
{
    return res.m_p;
}

// @0x140c8f810
void* PostProcessEffect::vfunc_18()
{
    return FUN_14097fbe0(&m_88);
}

// @0x140c8f840
void* PostProcessEffect::vfunc_17()
{
    return FUN_140c8f680(&m_80);
}

// @0x140c8f870
const NiRTTI* PostShimmerRenderStep::GetRTTI() const
{
    return &ms_RTTI;
}

// @0x140c8f890
bool PostShimmerRenderStep::vfunc_14()
{
    return false;
}

// @0x140c8f900
bool PostShimmerRenderStep::vfunc_13()
{
    return false;
}

// @0x140c8f910
void PostProcessEffect::vfunc_21()
{
}

// @0x140c8f920
void PostProcessEffect::vfunc_19()
{
}

// @0x140c8f930
void PostProcessEffect::vfunc_20()
{
}

// @0x140c8f940
void PostProcessEffect::vfunc_22()
{
}

// ---------------------------------------------------------------------------------------------------------------
// PostShimmerEffectParam

// @0x140c8f980
PostShimmerEffectParam::PostShimmerEffectParam()
    : CPostEffectParam(0x14), m_fBlendingMin(0.0f), m_fBlendingMax(1.0f), m_fMoveX(0.0f), m_fMoveY(0.0f),
      m_strTexture("shimmer.tga")
{
}

// @0x140c8fa20
void PostShimmerEffectParam::vfunc_1(Unk_140165cf0* pNode)
{
    CPostEffectParam::vfunc_1(pNode);
    FUN_140873360(pNode, "blendingMin", m_fBlendingMin);
    FUN_140873360(pNode, "blendingMax", m_fBlendingMax);
    FUN_140873360(pNode, "moveX", m_fMoveX);
    FUN_140873360(pNode, "moveY", m_fMoveY);
    FUN_1408733e0(pNode, "texture", m_strTexture);
}
MS2_REPLACE_METHOD(0x140c8fa20, PostShimmerEffectParam, vfunc_1, 179, 0xCCA48F6B);

// ---------------------------------------------------------------------------------------------------------------
// PostShimmerEffect

// @0x140c8fae0
PostShimmerEffect::PostShimmerEffect(int nId, const CPostEffectParam* pParam)
    : CScreenEffectBase(nId, pParam), m_fBlendMin(0.0f), m_fBlendMax(1.0f), m_dStart(0.0)
{
    if (pParam)
    {
        if (static_cast<const PostShimmerEffectParam*>(pParam)->m_fBlendingMin > 0.0f)
            m_fBlendMin = static_cast<const PostShimmerEffectParam*>(pParam)->m_fBlendingMin;
        if (static_cast<const PostShimmerEffectParam*>(pParam)->m_fBlendingMax < 1.0f)
            m_fBlendMax = static_cast<const PostShimmerEffectParam*>(pParam)->m_fBlendingMax;
        m_kMove.x = static_cast<const PostShimmerEffectParam*>(pParam)->m_fMoveX;
        m_kMove.y = static_cast<const PostShimmerEffectParam*>(pParam)->m_fMoveY;
        m_strTexture = static_cast<const PostShimmerEffectParam*>(pParam)->m_strTexture;
    }
    else
    {
        m_kMove.x = 0.0f;
        m_kMove.y = 0.0f;
    }
}

// @0x140c8fc40
void PostShimmerEffect::vfunc_1()
{
    CScreenEffectBase::vfunc_1();
    m_dStart = m_dStartTime;
    FUN_1409a8b20()->FUN_1416a3920(0x12, true);
    float fBlend = 0.0f;
    CString strPath;
    strPath.Format("%s/Image/ScreenMask/%s", (const char*)FUN_14086d260()->FUN_1414736e0(), (const char*)m_strTexture);
    FUN_140c8f490(FUN_140a0afd0()->FUN_141552f90(CString((const char*)strPath), 5));
    FUN_1409a5770(DAT_143ae5438, &fBlend, 1);
    efd::Point2 kMove(0.0f, 0.0f);
    FUN_140c900e0(DAT_143ae5448, &kMove, 1);
}
MS2_REPLACE_METHOD(0x140c8fc40, PostShimmerEffect, vfunc_1, 425, 0xB2DD6343);

// @0x140c8fdf0
bool PostShimmerEffect::vfunc_2()
{
    bool bRet = CScreenEffectBase::vfunc_2();
    if (bRet && m_bStarted)
    {
        float fElapsed = (float)(FUN_14086d260()->FUN_141473280() - m_dStart);
        efd::Point2 kMove = fElapsed * m_kMove;
        FUN_140c900e0(DAT_143ae5448, &kMove, 1);
    }
    return bRet;
}
MS2_REPLACE_METHOD(0x140c8fdf0, PostShimmerEffect, vfunc_2, 139, 0x7171511D);

// @0x140c8fe90
void PostShimmerEffect::vfunc_4()
{
    CScreenEffectBase::vfunc_4();
    FUN_1409a8b20()->FUN_1416a3920(0x12, false);
}
MS2_REPLACE_METHOD(0x140c8fe90, PostShimmerEffect, vfunc_4, 45, 0xB9116348);

// @0x140c8fed0
bool PostShimmerEffect::vfunc_6(bool b)
{
    if (!b)
    {
        CString strPath;
        strPath.Format("%s/Image/ScreenMask/%s", (const char*)FUN_14086d260()->FUN_1414736e0(), (const char*)m_strTexture);
        FUN_140c8f490(FUN_140a0afd0()->FUN_141552f90(CString((const char*)strPath), 5));
        vfunc_7(m_nState, m_fAlpha);
    }
    return true;
}
MS2_REPLACE_METHOD(0x140c8fed0, PostShimmerEffect, vfunc_6, 353, 0x59B176E8);

// @0x140c90040
void PostShimmerEffect::vfunc_7(int nState, float fAlpha)
{
    float fBlend;
    float fT = fAlpha;
    switch (nState)
    {
    default:
        break;
    case 1:
        fT = 1.0f - fAlpha;
        break;
    }
    fBlend = (m_fBlendMax - m_fBlendMin) * fT + m_fBlendMin;
    fBlend *= 0.01f;
    FUN_1409a5770(DAT_143ae5438, &fBlend, 1);
}
MS2_REPLACE_METHOD(0x140c90040, PostShimmerEffect, vfunc_7, 158, 0xAC33291B);

// @0x140c900e0
bool FUN_140c900e0(const NiFixedString& kName, const efd::Point2* pk, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (!FUN_140c902f0(pk[i]))
            throw 13;
    }
    if (NiShaderFactory::UpdateGlobalShaderConstant(kName, n * sizeof(efd::Point2), pk))
        return true;
    return false;
}

// @0x140c902e0
int PostShimmerEffect::vfunc_5()
{
    return 0x14;
}

// @0x140c902f0
int FUN_140c902f0(const efd::Point2& k)
{
    if ((_fpclass(k.x) & 0x207) || (_fpclass(k.y) & 0x207))
        return 0;
    else
        return 1;
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca3930-0x142ca39e0 .text$yd
