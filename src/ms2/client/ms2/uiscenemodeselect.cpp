// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UISceneModeSelect: see uiscenemodeselect.h.
// MS2-UNIT: ?\uiscenemodeselect.cpp
// MS2-RANGE: 0x140e84fa0-0x140e855f0 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"

#include "uiscenemodeselect.h"
#include "ms2/client/ms2/gfxmoviebackground.h"
#include "ms2/placeholder/uivideocontents.h"
#include "ms2/placeholder/ms2ptr_impl.h"

#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local views of exe types (unrecovered helpers) ----

// The intro movie dialog (0xa8 bytes, base UIVideoContents; slot 53 stops the video).
class UIIntroMovie : public UIVideoContents
{
};

class Unk_SmUIMgr                                       // the UI service (FUN_1403ed2b0)
{
public:
    MS2Ptr<UIObject> FUN_141adcea0(int nUiId);          // looks a UI up by id
    void FUN_141adbe00(float f, int n);
    void FUN_141adc530(int nUiId);
    void FUN_141adc5d0(int nUiId);
};
class Unk_SmWorld;                                      // FUN_1403ed2d0
class Unk_SmHost;                                       // FUN_14025e7a0
class Unk_SmPlayerState { public: int m_pad0; int m_pad4; int m_8; };   // FUN_1409331f0 (m_8 +8)
class Unk_SmLogin;                                      // FUN_14025e7c0

Unk_SmUIMgr* FUN_1403ed2b0();
Unk_SmWorld* FUN_1403ed2d0();
Unk_SmHost* FUN_14025e7a0();
Unk_SmLogin* FUN_14025e7c0();
Unk_SmPlayerState* FUN_1409331f0();
int FUN_141bcfbd0(Unk_SmWorld* pWorld);
GFxMovie* FUN_1422b01a0(Unk_SmHost* pHost, int nType);
const NiRTTI* FUN_14098db90(const NiRTTI* pRtti);       // NiRTTI::GetBaseRTTI
CStringW FUN_141850100(int a, int b);
bool FUN_14116d9c0(Unk_SmLogin* p, int a, int b, int c);
bool FUN_14116dd30(Unk_SmLogin* p, int a, int b, int c);
int FUN_1418fc760(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs, UISceneModeSelect* pScene);

static int FUN_140e85580(Unk_SmPlayerState* p);
static int FUN_140e853c0();
static UIIntroMovie* FUN_140e85420(int nUiId);
static GFxMovieBackground* FUN_140e85550(const NiRTTI* pRtti, GFxMovie* pObj);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// @0x140e84fa0
UISceneModeSelect::UISceneModeSelect()
{
    m_6c = 0x6200085;
}

// @0x140e84ff0
UISceneModeSelect::~UISceneModeSelect()
{
}

// @0x140e85030
CString UISceneModeSelect::GetTypeName()
{
    return "SceneModeSelect";
}

// @0x140e85080
CString UISceneModeSelect::vfunc_7()
{
    return "SceneEmpty";
}

// @0x140e850d0
void UISceneModeSelect::vfunc_48(int n)
{
    UISceneEntity::vfunc_48(n);
    UIIntroMovie* pIntro = FUN_140e85420(0x4e33);
    if (pIntro != 0)
        pIntro->vfunc_53();
    FUN_1403ed2b0()->FUN_141adbe00(1.0f, 0);
    FUN_1422e7950();
}

// @0x140e85150
void UISceneModeSelect::vfunc_49(int n)
{
    FUN_1403ed2b0()->FUN_141adc5d0(0x4e22);
    UISceneEntity::vfunc_49(n);
}

// @0x140e85190
void UISceneModeSelect::vfunc_55()
{
    UISceneEntity::vfunc_55();
    FUN_1403ed2b0()->FUN_141adc530(0x4f6e);
}

// @0x140e851c0
void UISceneModeSelect::vfunc_15()
{
    UISwfEntity::vfunc_15();
}

// @0x140e851e0
int UISceneModeSelect::vfunc_13()
{
    if (UISwfEntity::vfunc_13() != 0)
        return 1;
    if (FUN_140e853c0() != 0)
    {
        FUN_141850100(1, 0);
        return 1;
    }
    return 0;
}

// @0x140e85240
void UISceneModeSelect::OnLoadComplete()
{
    UISwfEntity::OnLoadComplete();
    if (FUN_141bcfbd0(FUN_1403ed2d0()) != 0)
        vfunc_55();
    GFxMovieBackground* pBg = FUN_140e85550(&GFxMovieBackground::ms_RTTI, FUN_1422b01a0(FUN_14025e7a0(), 4));
    if (pBg != 0)
    {
        if (pBg->IsLoaded() != 0)
            vfunc_60(pBg->GetScript());
    }
}

// @0x140e85300
int UISceneModeSelect::OnMessage(UISwfEntity* pSender, UIMsg* pMsg)
{
    if (UISwfEntity::OnMessage(pSender, pMsg))
        return 1;
    return 0;
}

// @0x140e85350
int UISceneModeSelect::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UISceneEntity::vfunc_28(szMethod, pArgs, nArgs))
        return 1;
    if (FUN_1418fc760(szMethod, pArgs, nArgs, this))
        return 1;
    return 0;
}

// @0x140e853c0
static int FUN_140e853c0()
{
    if (FUN_140e85580(FUN_1409331f0()) == 0)
        return FUN_14116d9c0(FUN_14025e7c0(), 0x75, 0, 0);
    return FUN_14116dd30(FUN_14025e7c0(), 0x493ef, 0, 0);
}

// @0x140e85420
static UIIntroMovie* FUN_140e85420(int nUiId)
{
    if (FUN_1403ed2b0() != 0)
    {
        MS2Ptr<UIObject> spUI = FUN_1403ed2b0()->FUN_141adcea0(nUiId);
        if (spUI.get() != 0)
            return dynamic_cast<UIIntroMovie*>((UIObject*)spUI);
    }
    return 0;
}

// @0x140e85590
static bool FUN_140e85590(GFxMovie* pObj, const NiRTTI* pRtti)
{
    const NiRTTI* pCur = (const NiRTTI*)pObj->vfunc_2();
    while (pCur != 0)
    {
        if (pCur == pRtti)
            return true;
        pCur = FUN_14098db90(pCur);
    }
    return false;
}

// @0x140e85580
static int FUN_140e85580(Unk_SmPlayerState* p)
{
    return p->m_8;
}

// @0x140e85500
static GFxMovie* FUN_140e85500(GFxMovie* pObj, const NiRTTI* pRtti)
{
    return FUN_140e85590(pObj, pRtti) ? pObj : 0;
}

// @0x140e85550
static GFxMovieBackground* FUN_140e85550(const NiRTTI* pRtti, GFxMovie* pObj)
{
    if (pObj == 0)
        return 0;
    return (GFxMovieBackground*)FUN_140e85500(pObj, pRtti);
}
