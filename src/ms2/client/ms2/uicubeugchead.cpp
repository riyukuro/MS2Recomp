// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UICubeUGCHead: the label above a UGC cube.
// MS2-UNIT: ?\uicubeugchead.cpp
// MS2-RANGE: 0x141906490-0x141906f30 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uicubeugchead.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <efd/Point3.h>
#include <NiPoint3.h>
#include "uicubeugchead.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asgameentity.h"
#include "ms2/placeholder/uiswfentitymanager.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/client/ms2/uiservice.h"
#include "ms2/client/ms2/camera.h"
#include "ms2/commonfiles/ugcmappackageinfo.h"   // C3: Unk_Int3, the cell type of FUN_1408a15b0

// ---- out-of-unit callees (bound to the exe by their FUN_<va> names / symbols) ----
extern int g_nDebugUI;                                           // debug switch: UI always shown
int FUN_141277f40();                                                // next UI layer
int FUN_140707660(int nKind);
int IsTriggerControlEnabled(int nKind);
efd::Point3 FUN_1408a15b0(Unk_Int3 cell, efd::Point3& ptOrigin);   // the world point of a cell (Unk_UgcCell is the same 3 ints)
class Unk_UIScale;
class Unk_AltStringMgr* GetGFxManager();   // C3: was GetGFxManager
class GFxManager   // C3: member view for the former free stand-ins
{
public:
    float GetMovieScale(int);
};
MS2Ptr<ASGameEntity> CreateGameEntity(int n, const Scaleform::GFx::Value& v);   // new ASGameEntity(v, n)

// @0x141906490
UICubeUGCHead::UICubeUGCHead(Unk_UgcCell cell, CStringW strName, int nType)
    : m_68(cell), m_78(strName), m_80(0), m_84(0), m_8c(nType)
{
    m_2c = 2;
    m_58 = 0;
    m_28 = FUN_141277f40();
    LoadSwf(m_2c, 1, 0);
}

// @0x1419065a0
CString UICubeUGCHead::GetTypeName()
{
    return "CubeUGCHead";
}

// @0x1419065f0
int UICubeUGCHead::IsShown()
{
    return m_80;
}

// @0x141906610
void UICubeUGCHead::Show(int nId)
{
    m_88 = nId;
    m_84 = 1;
    m_80 = 1;
}

// @0x141906650
void UICubeUGCHead::FUN_141906650()
{
    m_84 = 0;
    m_80 = 0;
}

// @0x141906680
void UICubeUGCHead::FUN_141906680()
{
    vfunc_8(0);
    FUN_141906650();
    FUN_1422dc080();
}

// @0x1419066c0
int UICubeUGCHead::CanShowLabel()
{
    if (FUN_140707660(m_8c) != 0 || IsTriggerControlEnabled(m_8c) != 0)
    {
        if ((((CUIService*)(TSingleton<CUIService>::GetInstance()))->IsDialogOpen((eUIClassID)(0x4e6b))) != 0)
            return 1;
    }
    if (g_nDebugUI != 0)
        return 1;
    return 0;
}

// @0x141906730
void UICubeUGCHead::vfunc_2()
{
    UISwfEntity::vfunc_2();
    LoadSwf(m_2c, m_44, 0);
    Show(m_88);
}

// @0x141906790
void UICubeUGCHead::vfunc_3()
{
    UISwfEntity::vfunc_3();
    FUN_1422dc080();
    FUN_141906650();
}

// @0x1419067d0
void UICubeUGCHead::vfunc_52()
{
    if (m_30.IsNull())
        return;
    MS2Ptr<ASMovieClip> pClip(dynamic_cast<ASMovieClip*>((AScript*)m_30));
    if (pClip.get())
    {
        if (CanShowLabel() != 0)
            vfunc_8(1);
        else
            vfunc_8(0);
        ((class ASDisplayObject*)(class ASDisplayObject*)(pClip.operator->()))->SetAlpha(100.0f);
        CStringW strId;
        strId.Format(L"ID:%d", m_88);
        pClip->Invoke("setData", m_78, strId);
        pClip->Invoke("setFontSize", 0x12);
        if (FUN_140707660(m_8c) != 0)
            pClip->Invoke("setFontColor", 0x45ff98);
        else
            pClip->Invoke("setFontColor", 0x3df0fb);
        m_84 = 0;
    }
}

// @0x141906a80
void UICubeUGCHead::vfunc_15()
{
    UISwfEntity::vfunc_15();
    if (m_30.IsNull())
        return;
    if (m_84 != 0)
        vfunc_52();
    if (IsShown())
        UpdateScreenPosition();
    else
        vfunc_8(0);
}

// @0x141906b10
int UICubeUGCHead::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UISwfEntity::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    return 0;
}

// @0x141906b60
void UICubeUGCHead::UpdateScreenPosition()
{
    efd::Point3 ptOrigin = efd::Point3::ZERO;
    NiPoint3 world = FUN_1408a15b0(reinterpret_cast<const Unk_Int3&>(m_68), ptOrigin);
    Vector3 screen;
    if (TSingleton<CameraMgr>::GetInstance()->FUN_140af0700(world, reinterpret_cast<NiPoint3&>(screen)) != 0)
    {
        MS2Ptr<ASGameEntity> pEntity(dynamic_cast<ASGameEntity*>((AScript*)m_30));
        if (pEntity.get())
        {
            if (CanShowLabel() != 0)
                vfunc_8(1);
            else
                vfunc_8(0);
            reinterpret_cast<efd::Point3&>(screen) *= ((class GFxManager*)(class Unk_UIScale*)(((class Unk_UIScale*)GetGFxManager())))->GetMovieScale(m_28);
            ((class ASDisplayObject*)(class ASGameEntity*)(pEntity.operator->()))->SetPositionFloat(screen.x, screen.y);
        }
    }
    else
        vfunc_8(0);
}

// @0x141906d20
void UICubeUGCHead::vfunc_41(const Scaleform::GFx::Value& root)
{
    m_30 = CreateGameEntity(m_28, root);
}

// ~UICubeUGCHead (0x141906d90) is implicit.

MS2_EMIT_CRT_MEMMOVE_S();
