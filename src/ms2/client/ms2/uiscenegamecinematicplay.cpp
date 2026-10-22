// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UISceneGameCinematicPlay: see uiscenegamecinematicplay.h.
// MS2-UNIT: ?\uiscenegamecinematicplay.cpp
// MS2-RANGE: 0x140e84cd0-0x140e84fa0 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"

#include "uiscenegamecinematicplay.h"

#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local placeholders (unrecovered helpers; promote to src/ms2/placeholder/ when shared) ----

class Unk_ScpWorld;                         // the cinematic presentation the scene switches to
class Unk_ScpSceneCtl;                      // the UI scene controller (FUN_1403ed2b0)
class Unk_ScpSceneMgr;                      // the UI scene manager (FUN_1408e57f0)

Unk_ScpWorld* FUN_1403ed2d0();
Unk_ScpSceneCtl* FUN_1403ed2b0();
Unk_ScpSceneMgr* FUN_1408e57f0();
void FUN_141bd3c00(Unk_ScpWorld* pWorld, bool bOn);           // start/stop the cinematic world
void FUN_141ad9e50(Unk_ScpSceneCtl* pCtl, int nScene);       // the scene's presentation, on
void FUN_141ada6f0(Unk_ScpSceneCtl* pCtl, int nScene);
void FUN_141ada610(Unk_ScpSceneCtl* pCtl, int nScene);       // the scene's presentation, off
void FUN_141adad20(Unk_ScpSceneCtl* pCtl, int nScene);
void FUN_1422b9fd0(Unk_ScpSceneMgr* pMgr, int nScene);       // the scene manager's presentation call

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// @0x140e84cd0
UISceneGameCinematicPlay::UISceneGameCinematicPlay()
{
    m_6c = 0x620007f;
}

// @0x140e84d20
UISceneGameCinematicPlay::~UISceneGameCinematicPlay()
{
}

// @0x140e84d60
CString UISceneGameCinematicPlay::GetTypeName()
{
    return "SceneGameCinematicPlay";
}

// @0x140e84db0
bool UISceneGameCinematicPlay::vfunc_47()
{
    return false;
}

// @0x140e84dc0
void UISceneGameCinematicPlay::vfunc_48(int n)
{
    UISceneEntity::vfunc_48(n);
    FUN_141bd3c00(FUN_1403ed2d0(), false);
    FUN_141ad9e50(FUN_1403ed2b0(), m_6c);
    FUN_141ada6f0(FUN_1403ed2b0(), m_6c);
    FUN_1422e7950();
}

// @0x140e84e30
void UISceneGameCinematicPlay::vfunc_49(int n)
{
    UISceneEntity::vfunc_49(n);
    FUN_141bd3c00(FUN_1403ed2d0(), true);
    FUN_141ada610(FUN_1403ed2b0(), m_6c);
    FUN_141adad20(FUN_1403ed2b0(), m_6c);
    FUN_1422e7950();
}

// @0x140e84ea0
void UISceneGameCinematicPlay::vfunc_54()
{
    FUN_1422b9fd0(FUN_1408e57f0(), 0x620001d);
}

// @0x140e84ed0
void UISceneGameCinematicPlay::vfunc_52()
{
    UISceneEntity::vfunc_52();
}

// @0x140e84ef0
int UISceneGameCinematicPlay::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UISceneEntity::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    return 0;
}
