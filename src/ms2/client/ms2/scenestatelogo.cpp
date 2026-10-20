// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// MS2-UNIT: client\ms2\scenestatelogo.cpp
// MS2-RANGE: 0x14174c710-0x14174c9c0 .text$mn
// MS2-RANGE: 0x1401002c0-0x140100400 .text$di
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\scenestatelogo.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "scenestatelogo.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include <efd/Helpers.h>

extern int DAT_1439f4a78;

EE_IMPLEMENT_CONCRETE_CLASS_INFO(CSceneStateLogo);

static CString s_sortNames[] = {"None","Buy","Like","PriceLow","PriceHigh","Create","EnumEnd"};
static CString s_skill("skill");
static CString s_stun("stun");

// @0x14174c710
CSceneStateLogo::CSceneStateLogo()
{
}

// @0x14174c770
CSceneStateLogo::~CSceneStateLogo()
{
}

// @0x14174c7b0
void CSceneStateLogo::OnEnter(int nPrevState)
{
    DAT_1439f4a78 = -1;
    CSceneStateBase::OnEnter(nPrevState);
}

// @0x14174c7e0
void CSceneStateLogo::OnLeave(int nNextState)
{
    CSceneStateBase::OnLeave(nNextState);
}

// @0x14174c810
void CSceneStateLogo::OnUpdate(double fTime)
{
    CSceneStateBase::OnUpdate(fTime);
}

// @0x14174c840
int CSceneStateLogo::vfunc_15()
{
    return 0;
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cb6510-0x142cb6580 .text$yd
