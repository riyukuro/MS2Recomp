// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// MS2-UNIT: client\ms2\scenestatemodeselect.cpp
// MS2-RANGE: 0x140aadff0-0x140aae580 .text$mn
// MS2-RANGE: 0x1400c51e0-0x1400c5340 .text$di
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\scenestatemodeselect.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "scenestatemodeselect.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/cinpacket.h"
#include <efd/Helpers.h>

void FUN_140930150(int);
void* FUN_1403ed2d0();
void* FUN_1403ed2b0();
void FUN_141bbae40(void*, IWorldServiceCallback*);
void FUN_141bbae80(void*, IWorldServiceCallback*);
void FUN_141bbbe40(void*, int, int, int);
void FUN_141adc5d0(void*, int);
class Unk_143a09680 { public: void* m_a; void* m_b; };
class Unk_1409879 : public Unk_143a09680 { };
Unk_1409879 FUN_140987930(const void*);
extern char DAT_143a09680[];
void FUN_141489ff0(void*, Unk_143a09680);
extern void* DAT_143ab8f48;
void* FUN_140aae430();
void* FUN_1409478c0();
int FUN_140a18070(void*);
struct Unk_140ae7ce0 { Unk_140ae7ce0(); void *m_p0, *m_p1, *m_p2, *m_p3, *m_p4, *m_p5; };
bool FUN_140aeb590(void*, Unk_140ae7ce0*);
void FUN_140aed720(void*, Unk_140ae7ce0*);
void FUN_140aed750(void*, int, int);

EE_IMPLEMENT_CONCRETE_CLASS_INFO(CSceneStateModeSelect);

class Unk_1401cd100 { public: Unk_1401cd100(void*); private: void* m_p; };
static CString s_sortNames[] = {"None","Buy","Like","PriceLow","PriceHigh","Create","EnumEnd"};
static CString s_skill("skill");
static CString s_stun("stun");
static Unk_1401cd100 s_pointer(NULL);

// @0x140aadff0
CSceneStateModeSelect::CSceneStateModeSelect()
{
}

// @0x140aae050
CSceneStateModeSelect::~CSceneStateModeSelect()
{
}

// @0x140aae090
// MS2-FUNCTIONAL: the exe keeps the 24-byte FUN_140987930 result slot pointer in a stack temp before the call (same as CSceneStateLogin::OnEnter)
void CSceneStateModeSelect::OnEnter(int nPrevState)
{
    CSceneStateBase::OnEnter(nPrevState);
    FUN_140930150(1);
    FUN_141bbae40(FUN_1403ed2d0(), this);
    FUN_141489ff0(FUN_140aae430(), static_cast<const Unk_143a09680&>(FUN_140987930(DAT_143a09680)));
    FUN_141bbbe40(FUN_1403ed2d0(), 0x3e9, 1, 0);
}

// @0x140aae160
void CSceneStateModeSelect::OnLeave(int nNextState)
{
    CSceneStateBase::OnLeave(nNextState);
    FUN_141bbae80(FUN_1403ed2d0(), this);
    FUN_141adc5d0(FUN_1403ed2b0(), 0x4f6e);
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
    if (FUN_140a18070(FUN_1409478c0()) != 0)
    {
        Unk_140ae7ce0 tmp;
        if (FUN_140aeb590(FUN_1409478c0(), &tmp))
        {
            FUN_140aed720(FUN_1409478c0(), &tmp);
            FUN_140aed750(FUN_1409478c0(), 4, 1);
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
    return DAT_143ab8f48;
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142c9fb70-0x142c9fbe0 .text$yd
