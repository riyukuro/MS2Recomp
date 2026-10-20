// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// MS2-UNIT: client\ms2\scenestaterelocateworld.cpp
// MS2-RANGE: 0x141750f00-0x141751290 .text$mn
// MS2-RANGE: 0x140100720-0x140100860 .text$di
// MS2-PIN: ?SetupClassInfo@CSceneStateRelocateWorld@@SAXPEAVClassInfo@efd@@_K@Z 0x141751190
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\scenestaterelocateworld.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "scenestaterelocateworld.h"
#include "networkservice.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

CNetworkService* FUN_140714f90();
void* FUN_140aae430();
class Unk_143a09680 { public: void* m_a; void* m_b; };
class Unk_1409879 : public Unk_143a09680 { };
Unk_1409879 FUN_140987930(const void*);
extern char DAT_143a09680[];
void FUN_141489ff0(void*, Unk_143a09680);
extern CString DAT_143ab2a48;
extern unsigned short DAT_143ab2848;
extern __int64 DAT_143ab2868;

EE_IMPLEMENT_CONCRETE_CLASS_INFO(CSceneStateRelocateWorld);

static CString s_sortNames[] = {"None","Buy","Like","PriceLow","PriceHigh","Create","EnumEnd"};
static CString s_skill("skill");
static CString s_stun("stun");

// @0x141750f00
CSceneStateRelocateWorld::CSceneStateRelocateWorld()
{
    m_nState = 0;
}

// @0x141750f60
CSceneStateRelocateWorld::~CSceneStateRelocateWorld()
{
}

// @0x141750fa0
// MS2-FUNCTIONAL: the exe keeps the 24-byte FUN_140987930 result slot pointer in a stack temp before the call (same as CSceneStateLogin::OnEnter)
void CSceneStateRelocateWorld::OnEnter(int nPrevState)
{
    FUN_141489ff0(FUN_140aae430(), static_cast<const Unk_143a09680&>(FUN_140987930(DAT_143a09680)));
    m_nState = 0;
    CSceneStateBase::OnEnter(nPrevState);
}

// @0x141751020
void CSceneStateRelocateWorld::OnLeave(int nNextState)
{
    CSceneStateBase::OnLeave(nNextState);
    DAT_143ab2868 = 0;
}

// @0x141751060
void CSceneStateRelocateWorld::OnUpdate(double fTime)
{
    if (m_nState == 1)
    {
        m_nState = 2;
        FUN_140714f90()->FUN_1415383a0(DAT_143ab2a48, DAT_143ab2848, 1, 1, 0);
    }
}

// @0x141751100
void CSceneStateRelocateWorld::SetState(int nState)
{
    m_nState = nState;
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cb66a0-0x142cb6710 .text$yd
