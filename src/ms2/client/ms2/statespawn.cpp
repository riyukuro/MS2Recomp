// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). StateSpawn, the actor state that plays an actor's spawn
// animation (named by its StateSpawnData) after a short random delay. See statespawn.h. The MS2Ptr<StateSpawnData>
// members the exe keeps in this unit come out of ms2ptr_impl.h.
// MS2-UNIT: ?\statespawn.cpp
// MS2-RANGE: 0x1417f6050-0x1417f67b0 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\statespawn.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"

#include <new>
#include <egf/Entity.h>
#include <efd/utf8string.h>

#include "statespawn.h"

#include "ms2/client/ms2/pcbase.h"
#include "ms2/client/ms2/randomeffectparam.h"       // Unk_Random
#include "ms2/placeholder/nipoint3.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local views of unrecovered callees ------------------------------------------------------------------------

float FUN_14099eb30(const egf::EntityID& kKey, CString strAnim);           // 0x14099eb30 the animation length (the callee destroys the name)
bool FUN_14028d470(float a, float b);                                      // approx equal
int FUN_140b10150(PCBase* pMount);                                         // 0x140b10150 the mount's id

// The mount's proxy handle (PCBase +0xd50) and the entry it resolves to (the spawn effect path at +0x550).
struct Unk_SpawnProxy { char m_pad[0x10]; };
struct Unk_SpawnEntry
{
    char m_pad_00[0x550];
    CString m_strEffect;                                                   // +0x550
};
void FUN_141093270(PCBase* pMount, Unk_SpawnProxy* pOut);                  // 0x141093270 the mount's proxy handle
Unk_SpawnEntry* FUN_140965990(Unk_SpawnProxy* pProxy);                     // 0x140965990 operator->
void FUN_1406d5390(Unk_SpawnProxy* pProxy);                                // 0x1406d5390 dtor

// The effect manager and the request it takes (constructed / destroyed out of line).
struct Unk_SpawnRot { float m_af[9]; };
struct Unk_SpawnXform
{
    Unk_SpawnRot m_rotate;
    Vector3 m_translate;
    float m_fScale;
};
MS2_CHECK_SIZE(Unk_SpawnXform, 0x34);
struct Unk_SpawnRequest
{
    CString m_strName;                                                     // +0
    int m_nOwnerId;                                                        // +8
    int m_pad_0c;
    void* m_pSlot10;
    Unk_SpawnXform* m_pXform;                                              // +0x18
    char m_pad_20[0x58];
};
MS2_CHECK_SIZE(Unk_SpawnRequest, 0x78);
class Unk_SpawnEffectMgr { public: void FUN_1411a4a00(Unk_SpawnRequest* pRequest); };
Unk_SpawnEffectMgr* FUN_1403ed280();
void FUN_140a52ef0(Unk_SpawnRequest* p);                                   // construct
void FUN_1405a89e0(Unk_SpawnRequest* p);                                   // destroy
void* FUN_140a332d0(Unk_SpawnXform* p);                                    // NiTransform default ctor
void FUN_1420849a0(Unk_SpawnRot* p);                                       // efd::Matrix3::MakeIdentity
struct Unk_SpawnNiPoint3 : public Vector3
{
    Unk_SpawnNiPoint3(const NiPoint3& pt);                          // 0x14027dcf0
};
void FUN_14097faa0(Vector3* pDst, const Unk_SpawnNiPoint3* pSrc);  // NiPoint3::operator=

// @0x1417f6050
StateSpawn::StateSpawn(PCBase* pOwner) : State(pOwner)
{
    m_fElapsed = 0;
    m_fDuration = 0;
}

// @0x1417f60e0
StateSpawn::~StateSpawn()
{
}

// @0x1417f6140
void StateSpawn::vfunc_4(StateData* pData)
{
    State::vfunc_4(pData);
    m_fElapsed = 0;
    m_fDuration = 0;
    m_spSpawn.AssignRaw(dynamic_cast<StateSpawnData*>(pData));
    m_pOwner->FUN_14123cb20(false);
    m_pOwner->FUN_14166ca20(10);
    Unk_Random kRandom(m_pOwner->FUN_14123c580());
    int nDelay = (int)(kRandom.FUN_1407684c0() % 300) + 100;
    m_timer.FUN_140868750(nDelay);
}
MS2_REPLACE_METHOD(0x1417F6140, StateSpawn, vfunc_4, 281, 0x4A452965);

// @0x1417f6260
void StateSpawn::vfunc_5(int n)
{
    State::vfunc_5(n);
    int nMountId = 0;
    PCBase* pMount = FUN_1417b83a0();
    if (pMount != 0)
        nMountId = FUN_140b10150(pMount);
    m_pOwner->FUN_14166ca80(10);
    m_pOwner->FUN_14123cb20(true);
    m_fElapsed = 0;
    m_fDuration = 0;
}
MS2_REPLACE_METHOD(0x1417F6260, StateSpawn, vfunc_5, 138, 0xE3F2D2EC);

// @0x1417f62f0
// MS2-FUNCTIONAL: the mount effect request is written against unit-local stand-ins
void StateSpawn::vfunc_3(double fTime)
{
    State::vfunc_3(fTime);
    if (m_timer.FUN_140868ba0() != 0)
        return;

    if (FUN_14028d470(m_fElapsed, 0))
    {
        m_pOwner->FUN_14166ca80(10);
        if (m_spSpawn.get() != 0)
        {
            if (!m_spSpawn->m_str.IsEmpty())
            {
                m_pOwner->FUN_14166dd20(efd::utf8string((const char*)m_spSpawn->m_str), 1.0f, true, false);
                egf::EntityID kKey;
                m_fDuration = FUN_14099eb30(m_pOwner->FUN_14123c460(kKey), CString(m_spSpawn->m_str));
            }
        }
        PCBase* pMount = FUN_1417b8480();
        if (pMount != 0)
        {
            Unk_SpawnXform xf;
            FUN_140a332d0(&xf);
            FUN_1420849a0(&xf.m_rotate);
            xf.m_fScale = 1.0f;
            Unk_SpawnNiPoint3 niPt(m_pOwner->vfunc_18());
            FUN_14097faa0(&xf.m_translate, &niPt);
            Unk_SpawnRequest request;
            FUN_140a52ef0(&request);
            Unk_SpawnProxy kProxy;
            FUN_141093270(pMount, &kProxy);
            request.m_strName = FUN_140965990(&kProxy)->m_strEffect;
            FUN_1406d5390(&kProxy);
            request.m_nOwnerId = 0;
            request.m_pXform = &xf;
            FUN_1403ed280()->FUN_1411a4a00(&request);
            FUN_1405a89e0(&request);
        }
    }
    m_fElapsed += (float)fTime;
    if (m_fDuration <= m_fElapsed)
        m_pOwner->vfunc_59(1, 0, 0, 0);
}
MS2_REPLACE_METHOD(0x1417F62F0, StateSpawn, vfunc_3, 897, 0xEC49E718);

// @0x1417f6680
void StateSpawn::vfunc_9(double fTime)
{
    State::vfunc_9(fTime);
}
MS2_REPLACE_METHOD(0x1417F6680, StateSpawn, vfunc_9, 36, 0x3072E362);

// @0x1417f6790
int StateSpawn::vfunc_15() { return 1; }
MS2_REPLACE_METHOD(0x1417F6790, StateSpawn, vfunc_15, 11, 0x30025ED0);

// @0x1417f67a0
int StateSpawn::vfunc_1() { return 0x11; }
MS2_REPLACE_METHOD(0x1417F67A0, StateSpawn, vfunc_1, 11, 0x1A761180);
