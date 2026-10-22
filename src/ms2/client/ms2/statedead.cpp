// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). StateDead / StateDeadNPC / StateRevival: the actor states of
// a player's death (death motion, optional revive-in-place effect, auto-revival), of an npc's death (motion, corpse effect,
// exp reward to the local player) and of the stand-up motion after a revival. See statedead.h.
// MS2-UNIT: ?\statedead.cpp
// MS2-RANGE: 0x1417c24a0-0x1417c3780 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\statedead.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"

#include <float.h>
#include <errno.h>
#include <string.h>
#include <efd/utf8string.h>

#include "statedead.h"

#include "ms2/client/ms2/pcbase.h"
#include "ms2/client/ms2/mypc.h"
#include "ms2/client/ms2/statedata.h"
#include "ms2/client/ms2/effectservice.h"
#include "ms2/placeholder/chomeprivilege.h"
#include "ms2/placeholder/nipoint3.h"
#include "ms2/placeholder/pushcontrol.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local views of the exe objects and unrecovered callees ----

extern Vector3 DAT_143b01a60;                    // the zero point

void FUN_1408a8700(void* pStr);                          // 0x1408a8700 efd::utf8string()
void FUN_1408a8900(void* pStr);                          // 0x1408a8900 ~efd::utf8string
void FUN_1409989e0(void* pStr, const char* psz);         // 0x1409989e0 efd::utf8string(const char*)
void FUN_140ae18f0(void* pStr, const char* psz);         // 0x140ae18f0 efd::utf8string::operator=(const char*)

// The efd::utf8string the exe builds out of line (0x20 bytes).
struct Unk_DeadString
{
    Unk_DeadString() { FUN_1408a8700(m_buf); }
    Unk_DeadString(const char* psz) { FUN_1409989e0(m_buf, psz); }
    ~Unk_DeadString() { FUN_1408a8900(m_buf); }
    Unk_DeadString& operator=(const char* psz) { FUN_140ae18f0(m_buf, psz); return *this; }
    char m_buf[0x20];
};

// The map data of the current field: +0x140375570 tells whether the field revives players on its own.
class Unk_DeadField { public: int FUN_140375570(); };
class Unk_DeadFieldRef
{
public:
    ~Unk_DeadFieldRef() { FUN_1408850f0(); }
    void FUN_1408850f0();                                // release
    bool FUN_140965240(int n) const;                     // == n
    Unk_DeadField* FUN_140885340() const;                // operator->
    void* m_p0;
    void* m_p8;
};

// The player manager singleton.
class Unk_DeadWorld
{
public:
    Unk_DeadFieldRef FUN_141bd30a0();                    // the current field data
    int FUN_141bd1a10(GameObject* pObject);              // object -> effect owner id
    MyPC* FUN_141bd0cc0();                               // the local player
};
Unk_DeadWorld* FUN_1403ed2d0();
CEffectService* FUN_1403ed280();                         // effect manager

// The player's team-info proxy (see statepvpwinlose.cpp): +0x1c holds the revive animation id.
struct Unk_DeadTeam
{
    char m_pad_00[0x1c];
    int m_nValue;                                        // +0x1c
};
class Unk_DeadTeamPtr
{
public:
    ~Unk_DeadTeamPtr() { FUN_140964aa0(); }
    Unk_DeadTeam* FUN_140965970() const;                 // operator->
    void FUN_140964aa0();                                // release
    void* m_pad_00;
    Unk_DeadTeam* m_p;
};
class Unk_DeadPC { public: Unk_DeadTeamPtr FUN_140967420(); };   // the player's team-info proxy

// The constants tables: the revive animation id slot at +0xd248 of the first, two effect names at +0x278 of the second.
struct Unk_DeadConstVal { char m_pad[0x58]; };
struct Unk_DeadConsts
{
    char m_pad_00[0xd248];
    Unk_DeadConstVal m_reviveAnim;                       // +0xd248
};
struct Unk_DeadTexts
{
    char m_pad_00[0x278];
    CString m_strReviveEffect;                           // +0x278
    CString m_strDeathEffect;                            // +0x280
};
Unk_DeadConsts* FUN_1401d3200();
Unk_DeadTexts* FUN_1401d31f0();
int* FUN_1402056b0(Unk_DeadConstVal* pSlot);

// The npc table row: the corpse effect name at +0x448; FUN_1406ccf20 is CNpcData::GetCorpseHitAble.
class Unk_DeadNpcData { public: char m_pad_00[0x448]; CString m_strCorpseEffect; int FUN_1406ccf20(); };
class Unk_DeadNpcRef
{
public:
    ~Unk_DeadNpcRef() { FUN_1406d5390(); }
    void FUN_1406d5390();                                // release
    Unk_DeadNpcData* FUN_140965990() const;              // operator->
    void* m_p0;
    void* m_p8;
};
// The owner seen as an npc.
class Unk_DeadNpc
{
public:
    Unk_DeadNpcRef FUN_141093270();                      // the npc table row
    __int64 FUN_141094e20();                             // the exp reward
};
Unk_DeadNpc* FUN_14096e110(PCBase* pActor);              // as an npc (0 for a player)

int FUN_14165ef30(PCBase* pPC);                          // the player is revived through the team-info path
void FUN_14165cac0(PCBase* pPC);
void FUN_14165f170(MyPC* pPC);
void FUN_140ef4330();
void* FUN_1409331e0();
void FUN_14138bf00(void* p, int a, int b, int c);
int FUN_141661970(MyPC* p);
void FUN_14123fbf0(Unk_PCBaseBody* pBody, unsigned short n);
void FUN_1410943b0(PCBase* pActor, int n);
bool FUN_140184310(const CString& str, const char* psz);   // str == psz
CString FUN_1409a2360(const char* psz, int n);             // text conversion

// ---- StateDead ----

// @0x1417c24a0
StateDead::StateDead(PCBase* pOwner) : State(pOwner)
{
    m_n14 = 0;
    m_nEffect = 0;
}

// @0x1417c2500
StateDead::~StateDead()
{
}

// @0x1417c2530
void StateDead::vfunc_4(StateData* pData)
{
    State::vfunc_4(pData);
    bool bRevive = false;
    int nAnimId = 0;
    PCBase* pPC = FUN_1417b8370();
    if (pPC != 0)
    {
        Unk_DeadFieldRef kField = FUN_1403ed2d0()->FUN_141bd30a0();
        if (kField.FUN_140965240(0))
            return;
        if (FUN_14165ef30(pPC) != 0)
        {
            bRevive = true;
            nAnimId = ((Unk_DeadPC*)pPC)->FUN_140967420().FUN_140965970()->m_nValue;
        }
        else
        {
            if (kField.FUN_140885340()->FUN_140375570() != 0)
            {
                bRevive = true;
                nAnimId = *FUN_1402056b0(&FUN_1401d3200()->m_reviveAnim);
            }
        }
    }
    if (bRevive == true)
    {
        m_pOwner->vfunc_23(0);
        m_pOwner->FUN_14166dd20(m_pOwner->FUN_141679170(0x40, nAnimId), 1.0f, false, false);
        m_pOwner->vfunc_31(false);
    }
    else
    {
        m_pOwner->vfunc_23(1);
        {
            Unk_DeadString kAnim(m_pOwner->vfunc_123(0x34));
            m_pOwner->FUN_14166dd20(reinterpret_cast<const efd::utf8string&>(kAnim), 1.0f, false, false);
        }
        m_pOwner->vfunc_31(false);
        PCBase* pPCAgain = FUN_1417b8370();
        if (pPCAgain != 0)
            FUN_14165cac0(pPCAgain);
    }
    if (FUN_1417b84b0() != 0)
    {
        MyPC* pMyPC = FUN_1417b84b0();
        if (pMyPC != 0)
        {
            FUN_14165f170(pMyPC);
            ((CPushControl*)pMyPC->FUN_141675eb0())->FUN_1413fcf90();
        }
        if (bRevive == true)
        {
            Unk_EffectTarget kTarget;
            kTarget.m_strName = FUN_1401d31f0()->m_strReviveEffect;
            kTarget.m_nKind = 1;
            kTarget.FUN_140a53190(m_pOwner->FUN_14123c580());
            m_nEffect = FUN_1403ed280()->FUN_1411a49c0(kTarget);
        }
        else
        {
            Unk_EffectTarget kTarget;
            kTarget.m_strName = FUN_1401d31f0()->m_strDeathEffect;
            kTarget.m_nKind = 1;
            kTarget.FUN_140a53190(m_pOwner->FUN_14123c580());
            FUN_1403ed280()->FUN_1411a4a00(kTarget);
        }
        if (FUN_141661970(FUN_1417b84b0()) != 0)
            FUN_14138bf00(FUN_1409331e0(), 8, 0, 0);
    }
}

// @0x1417c29b0
void StateDead::vfunc_5(int n)
{
    if (m_nEffect != 0)
        FUN_1403ed280()->FUN_1411a6060(m_nEffect);
    m_pOwner->vfunc_23(0);
    m_pOwner->vfunc_31(true);
    FUN_140ef4330();
    State::vfunc_5(n);
}

// @0x1417c2a40
void StateDead::vfunc_3(double fTime)
{
    State::vfunc_3(fTime);
    Vector3 kZero = DAT_143b01a60;
    m_pOwner->vfunc_68(&kZero, fTime, 0, 0, 0);
}

// @0x1417c2ac0
void StateDead::vfunc_23()
{
    m_pOwner->vfunc_23(1);
    m_pOwner->vfunc_31(false);
    m_pOwner->vfunc_32(true);
}

// ---- StateDeadNPC ----

// @0x1417c2b30
StateDeadNPC::StateDeadNPC(PCBase* pOwner) : State(pOwner)
{
    m_n14 = 0;
    m_nEffect = 0;
    m_bFinished = 0;
}

// @0x1417c2bb0
StateDeadNPC::~StateDeadNPC()
{
    if (m_nEffect != 0)
    {
        FUN_1403ed280()->FUN_1411a6060(m_nEffect);
        m_nEffect = 0;
    }
}

// @0x1417c2c30
void StateDeadNPC::vfunc_4(StateData* pData)
{
    State::vfunc_4(pData);
    m_bFinished = 0;
    MS2Ptr<StateDeadNPCData> spData(dynamic_cast<StateDeadNPCData*>(pData));
    if (spData.get() != 0 && spData->m_b18 != 0)
    {
        m_strAnim = "Dead_Idle_A";
    }
    else
    {
        m_strAnim = m_pOwner->vfunc_123(0x34);
        if (FUN_1417b8480() != 0)
            FUN_1410943b0(FUN_1417b8480(), 4);
    }
    CString strEffect(((Unk_DeadNpc*)FUN_1417b8480())->FUN_141093270().FUN_140965990()->m_strCorpseEffect);
    if (strEffect.GetLength() != 0)
    {
        Unk_EffectTarget kTarget;
        kTarget.m_strName = strEffect;
        kTarget.m_nKind = FUN_1403ed2d0()->FUN_141bd1a10(m_pOwner);
        kTarget.FUN_140a53190(m_pOwner->FUN_14123c580());
        m_nEffect = FUN_1403ed280()->FUN_1411a49c0(kTarget);
    }
    FUN_14123fbf0(m_pOwner->FUN_14166d220(), 5);
    m_pOwner->FUN_14166dd20(efd::utf8string((const char*)FUN_1409a2360(m_strAnim, 0)), 1.0f, false, false);
}

// @0x1417c2f50
void StateDeadNPC::vfunc_5(int n)
{
    State::vfunc_5(n);
    FUN_1403ed280()->FUN_1411a6060(m_nEffect);
    m_nEffect = 0;
}

// @0x1417c2fa0
void StateDeadNPC::vfunc_6()
{
    if (m_bFinished == 0)
        return;
    Unk_DeadNpc* pNpc = FUN_14096e110(m_pOwner);
    if (pNpc != 0)
    {
        {
            int nHit = pNpc->FUN_141093270().FUN_140965990()->FUN_1406ccf20();
            if (nHit != 0)
            {
                Unk_DeadString kAnim;
                if (FUN_140184310(m_strAnim, "Dead_A") || FUN_140184310(m_strAnim, "Dead_Idle_A"))
                {
                    kAnim = "Dead_Damg_A";
                }
                else
                {
                    if (FUN_140184310(m_strAnim, "Dead_B"))
                        kAnim = "Dead_Damg_B";
                    else
                        return;
                }
                m_pOwner->FUN_14166dd20(reinterpret_cast<const efd::utf8string&>(kAnim), 1.0f, true, false);
            }
        }
    }
}

// @0x1417c3140
void StateDeadNPC::EndOfSequence(NiActorManager* pkManager, unsigned int eSequenceID,
    NiControllerSequence* pkSeq, float fEventTime)
{
    if (m_bFinished != 0)
        return;
    if (m_pOwner->FUN_14166de90(0x34, eSequenceID))
    {
        m_bFinished = 1;
        Unk_DeadNpc* pNpc = FUN_14096e110(m_pOwner);
        if (pNpc != 0)
        {
            if (pNpc->FUN_141094e20() <= 0)
                return;
            MyPC* pMyPC = FUN_1403ed2d0()->FUN_141bd0cc0();
            if (pMyPC != 0)
                pMyPC->FUN_1415294f0(m_pOwner->FUN_14123c580(), pNpc->FUN_141094e20());
        }
    }
}

// ---- StateRevival ----

// @0x1417c3220
StateRevival::StateRevival(PCBase* pOwner) : State(pOwner)
{
    m_n14 = 0;
}

// @0x1417c3270
StateRevival::~StateRevival()
{
}

// @0x1417c32a0
void StateRevival::vfunc_4(StateData* pData)
{
    State::vfunc_4(pData);
    Unk_DeadString kAnim(m_pOwner->vfunc_123(0x33));
    m_pOwner->FUN_14166dd20(reinterpret_cast<const efd::utf8string&>(kAnim), 1.0f, false, false);
}

// @0x1417c3350
void StateRevival::EndOfSequence(NiActorManager* pkManager, unsigned int eSequenceID,
    NiControllerSequence* pkSeq, float fEventTime)
{
    if (m_pOwner->FUN_14166de90(0x33, eSequenceID))
        m_pOwner->vfunc_59(1, 0, 0, 0);
}

// @0x1417c3500
int StateDeadNPC::vfunc_15()
{
    return 1;
}

// @0x1417c3510
int StateRevival::vfunc_15()
{
    return 1;
}

// @0x1417c3520
int StateDead::vfunc_1()
{
    return 0xc;
}

// @0x1417c3530
int StateDeadNPC::vfunc_1()
{
    return 0xc;
}

// @0x1417c3540
int StateRevival::vfunc_1()
{
    return 0x18;
}

// ---- the unreferenced CRT copy of this TU ----

// The UCRT's `static __inline memmove_s` of this TU (unreferenced copy, kept alive by the pointer below).
#pragma function(memcpy, memset)
// @0x1417c3660
MS2_EMIT_CRT_MEMMOVE_S_COPY(1);
