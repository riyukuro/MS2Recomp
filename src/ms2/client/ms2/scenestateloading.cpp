// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// MS2-UNIT: client\ms2\scenestateloading.cpp
// MS2-RANGE: 0x14174bd70-0x14174c000 .text$mn
// MS2-RANGE: 0x140100050-0x140100130 .text$di
// MS2-PIN: ?SetupClassInfo@CSceneStateLoading@@SAXPEAVClassInfo@efd@@_K@Z 0x14174bf00
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\scenestateloading.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "scenestateloading.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

class Unk_140a0afd0 { public: void FUN_141551c10(); };
Unk_140a0afd0* FUN_140a0afd0();
extern int DAT_1439f4a78;

EE_IMPLEMENT_CONCRETE_CLASS_INFO(CSceneStateLoading);

static CString s_sortNames[] = {"None","Buy","Like","PriceLow","PriceHigh","Create","EnumEnd"};

// @0x14174bd70
CSceneStateLoading::CSceneStateLoading()
{
}

// @0x14174bdb0
CSceneStateLoading::~CSceneStateLoading()
{
}

// @0x14174bde0
void CSceneStateLoading::OnEnter(int nPrevState)
{
    DAT_1439f4a78 = -1;
    FUN_140a0afd0()->FUN_141551c10();
    CSceneStateBase::OnEnter(nPrevState);
}

// @0x14174be20
void CSceneStateLoading::OnLeave(int nNextState)
{
    CSceneStateBase::OnLeave(nNextState);
}

// @0x14174be50
void CSceneStateLoading::OnUpdate(double fTime)
{
    CSceneStateBase::OnUpdate(fTime);
}

// @0x14174be80
int CSceneStateLoading::vfunc_15()
{
    return 0;
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cb6450-0x142cb6480 .text$yd
