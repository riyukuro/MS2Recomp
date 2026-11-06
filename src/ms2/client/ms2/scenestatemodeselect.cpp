// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// MS2-UNIT: client\ms2\scenestatemodeselect.cpp
// MS2-RANGE: 0x140aadff0-0x140aae580 .text$mn
// MS2-RANGE: 0x1400c51e0-0x1400c5340 .text$di
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\scenestatemodeselect.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/client/ms2/ms2.h"   // C3: MS2::SetBackgroundColor
#include "scenestatemodeselect.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include <NiColor.h>
#include "ms2/placeholder/cinpacket.h"
#include <efd/Helpers.h>
#include "ms2/client/ms2/uiservice.h"  // C3: CUIService::FUN_141adc5d0

void FUN_140930150(int);
class WorldService   // C3: unit-local view of the callback set
{
public:
    static WorldService* GetInstance();   // C3: was free FUN_1403ed2d0
    void FUN_141bbae40(void* p);
    void FUN_141bbae80(void* p);
    int FUN_141bbbe40(int mapId, int arg2, int arg3);
};
void* FUN_140aae430();
class CameraMgr;
template<> CameraMgr* TSingleton<CameraMgr>::GetInstance();   // actioncameramode.cpp defines it
class CameraMgr   // C3: member view for the former free stand-ins
{
public:
    int FUN_140a18070();
    bool GetSavedSetting(struct Unk_CameraSetting&);
    void FUN_140aed720(struct Unk_CameraSetting const&);
    void FUN_140aed750(int, int);
};
#include "ms2/client/ms2/cameramode.h"   // Unk_CameraSetting (ctor 0x140ae7ce0; was the Unk_140ae7ce0 view)

EE_IMPLEMENT_CONCRETE_CLASS_INFO(CSceneStateModeSelect);

#include <egf/EntityID.h>   // B22: was class Unk_BuddyHandle (ctor 0x1401cd100 = egf::EntityID(efd::UInt64))
static CString s_sortNames[] = {"None","Buy","Like","PriceLow","PriceHigh","Create","EnumEnd"};
static CString s_skill("skill");
static CString s_stun("stun");
static egf::EntityID s_pointer(0);                                       // @0x1400c5320

// @0x140aadff0
CSceneStateModeSelect::CSceneStateModeSelect()
{
}

// @0x140aae050
CSceneStateModeSelect::~CSceneStateModeSelect()
{
}

// @0x140aae090
void CSceneStateModeSelect::OnEnter(int nPrevState)
{
    CSceneStateBase::OnEnter(nPrevState);
    FUN_140930150(1);
    WorldService::GetInstance()->FUN_141bbae40((IWorldServiceCallback*)this);
    static_cast<MS2*>(FUN_140aae430())->SetBackgroundColor(efd::ColorA::BLACK);
    WorldService::GetInstance()->FUN_141bbbe40(0x3e9, 1, 0);
}

// @0x140aae160
void CSceneStateModeSelect::OnLeave(int nNextState)
{
    CSceneStateBase::OnLeave(nNextState);
    WorldService::GetInstance()->FUN_141bbae80((IWorldServiceCallback*)this);
    TSingleton<CUIService>::GetInstance()->CloseDialog((eUIClassID)0x4f6e);
}

// @0x140aae1d0
void CSceneStateModeSelect::OnUpdate(double fTime)
{
    CSceneStateBase::OnUpdate(fTime);
}

// @0x140aae200
void CSceneStateModeSelect::OnPacket(CInPacket& packet)
{
    CSceneStateBase::OnPacket(packet);
}

// @0x140aae230
void CSceneStateModeSelect::vfunc_1(int)
{
    if (((class CameraMgr*)(void*)(TSingleton<CameraMgr>::GetInstance()))->FUN_140a18070() != 0)
    {
        Unk_CameraSetting tmp;
        if (((class CameraMgr*)(void*)(TSingleton<CameraMgr>::GetInstance()))->GetSavedSetting(tmp))
        {
            ((class CameraMgr*)(void*)(TSingleton<CameraMgr>::GetInstance()))->FUN_140aed720(tmp);
            ((class CameraMgr*)(void*)(TSingleton<CameraMgr>::GetInstance()))->FUN_140aed750(4, 1);
        }
    }
}

class Unk_140aae2b0Obj { public: virtual void vfunc_0(); virtual bool vfunc_1(); };
struct Unk_140aae2b0Arg { void* m_0; Unk_140aae2b0Obj m_8; };

// @0x140aae2b0
void FUN_140aae2b0(void*, Unk_140aae2b0Arg* arg)
{
    int t = (&arg->m_8)->vfunc_1();
    int ok = t;
    if (ok != 0)
        return;
    bool v = (&arg->m_8)->vfunc_1();
    FUN_140930150(v);
}

// @0x140aae430
void* FUN_140aae430()
{
    return TSingleton<MS2>::s_instance;   // C3: was extern void* DAT_143ab8f48
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142c9fb70-0x142c9fbe0 .text$yd
