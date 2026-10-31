// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). StateHold, the actor state of a player holding another
// actor's hand / a mount's seat: the owner is pinned to the holder's seat node, plays the seat animation of the
// holder's mount model, and leaves the state when the holder is gone. Also the StateHoldData payload's members.
// See stateholddata.h.
// MS2-UNIT: ?\stateholddata.cpp
// MS2-RANGE: 0x1417cb9c0-0x1417cd420 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\stateholddata.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"

#include <new>
#include <NiAVObject.h>
#include <egf/Entity.h>

#include "ms2/client/ms2/stateholddata.h"
#include "ms2/client/ms2/pcbase.h"
#include "ms2/client/ms2/mypc.h"
#include "ms2/client/ms2/ridee.h"
#include "ms2/commonfiles/skilloverlapcompare.h"   // SkillData
#include "ms2/placeholder/chomeprivilege.h"
#include "ms2/placeholder/nipoint3.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "ms2/commonfiles/featuremanager.h"
#include "ms2/client/ms2/skilldatatablecli.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/client/ms2/camera.h"
#include "ms2/placeholder/cnpc.h"
#include "ms2/placeholder/cinputkeyhandler.h"

// MS2Ptr members instantiated by other objs.
template <> MS2Ptr<Unk_RideeData>::~MS2Ptr();                                           // 0x140788ed0
template <> bool MS2Ptr<Unk_RideeData>::operator==(Unk_RideeData* p) const;             // 0x1407893c0
template <> Unk_RideeData* MS2Ptr<Unk_RideeData>::operator->() const;                   // 0x1407895d0
template <> MS2Ptr<Unk_RideeModel>::~MS2Ptr();                                          // 0x140788ea0
template <> Unk_RideeModel* MS2Ptr<Unk_RideeModel>::operator->() const;                 // 0x1407895c0
template <> bool MS2Ptr<Unk_RideeModel>::operator==(Unk_RideeModel* p) const;           // 0x140789380
template <> MS2Ptr<SkillData>::~MS2Ptr();                                               // 0x14063e5c0
template <> void MS2Ptr<Unk_RideeModel>::Reference(Unk_RideeModel* p) { CPtred::AddRefPtred((CPtred*)p); }

// ---- unit-local views of the exe objects and unrecovered callees ----

class Unk_StateDataArg
{
public:
    char m_pad_00[0x28];
    float m_f28;                            // +0x28 (the held mount's height)
    char m_pad_2c[0x90 - 0x2c];
    int m_n90;                              // +0x90
    char m_pad_94[4];
    CString m_str98;                        // +0x98
    char m_pad_a0[0xb8 - 0xa0];
};
MS2_CHECK_OFFSET(Unk_StateDataArg, m_f28, 0x28);
MS2_CHECK_OFFSET(Unk_StateDataArg, m_n90, 0x90);
MS2_CHECK_OFFSET(Unk_StateDataArg, m_str98, 0x98);

class GameObjectControllerHitReport { public: void FUN_140cfaf30(); };
class Unk_HoldBody                                                       // the actor's physics body
{
public:
    void FUN_141240730();                                                // drop the stood-on entity
    GameObjectControllerHitReport* FUN_141240f20();
    void FUN_141241070();                                                // start falling
};
class Unk_HoldWorld                                                      // the field's actors by id
{
public:
    PCBase* FUN_141bd1200(int nId);
    PCBase* FUN_141bd1290(int nId);
};
class Unk_HoldBuffs                                                      // the actor's buff list
{
public:
    NiPoint3 FUN_141683290();                                            // knock-back velocity
    bool FUN_141683100(int nBuff);
};
CFeatureManager* FUN_140166410();
class Unk_HoldConsts                                                     // the game's constants table
{
public:
    char m_pad_00[0x9a94];
    int m_nHoldSkill;                                                    // +0x9a94
};
Unk_HoldConsts* FUN_1401d3200();
class Unk_HoldCamera { public: char m_pad[8]; };                         // the camera manager
class Unk_HoldSkillTable { public: MS2Ptr<SkillData> FUN_1407ee1d0(int nSkillId); };
void FUN_140ad0c10(efd::Point3* pAngles, float fScale);                    // 0x140ad0c10 scale the angles (radians -> degrees)
PCBase* FUN_140974230(GameObject* pObject);                              // 0x140974230 the actor as a player
void FUN_1409989e0(void* pOut, const char* psz);                         // 0x1409989e0 efd::utf8string(const char*)
void FUN_1408a8900(void* pStr);                                          // 0x1408a8900 ~efd::utf8string
void* FUN_14096e110(GameObject* pObject);                                // 0x14096e110 the actor as an npc
void* FUN_14025e7c0();                                                   // 0x14025e7c0 the key-binding table

// The efd::utf8string the exe builds out of line (ctor 0x1409989e0, dtor 0x1408a8900; 0x20 bytes).
struct Unk_HoldString
{
    Unk_HoldString(const char* psz) { FUN_1409989e0(m_buf, psz); }
    ~Unk_HoldString() { FUN_1408a8900(m_buf); }
    __int64 m_buf[4];
};

// The cast request of a skill (ctor 0x141763fa0).
struct Unk_InventorySkillRequest
{
    Unk_InventorySkillRequest(int nSkillId, unsigned short nLevel);   // 0x141763fa0
    int skill;
    unsigned short level;
    unsigned __int64 tick;
    unsigned serial, unknown14;
    Vector3 origin;
    Vector3 direction;
    float fValue;
    unsigned unknown34;
    bool remap, suppressDispatch, itemUse;
    __int64 item;
};

class CSkillRecord : public CPtred                                       // RTTI, 0x1c0 (?\skillrecord.cpp)
{
public:
    char m_pad_18[0xb0 - 0x18];
    int m_nTargetId;                                                     // +0xb0 the held actor
    char m_pad_b4[4];
    CString m_strNode;                                                   // +0xb8 its seat node
    char m_pad_c0[0x1c0 - 0xc0];
};
MS2_CHECK_OFFSET(CSkillRecord, m_nTargetId, 0xb0);
MS2_CHECK_OFFSET(CSkillRecord, m_strNode, 0xb8);
MS2_CHECK_SIZE(CSkillRecord, 0x1c0);

// The ridee cast of an object (0x1417cd1c0).
Ridee* FUN_1417cd1c0(GameObject* pObject);

// ---- StateHoldData ----

// @0x1417cb9c0
StateHoldData::StateHoldData() : m_nTargetId(0)
{
    m_nSkill = 0x1312d1f;
    m_nLevel = 1;
}

// @0x1417cba30
void StateHoldData::vfunc_1(Unk_StateDataArg* p)
{
    StateSkillData::vfunc_1(p);
    p->m_n90 = m_nTargetId;
    p->m_str98 = m_strTargetName;
    PCBase* pTarget = reinterpret_cast<Unk_HoldWorld*>(WorldService::GetInstance())->FUN_141bd1290(m_nTargetId);
    if (pTarget != 0)
    {
        if (pTarget->FUN_1416764a0() != 0)
        {
            Ridee* pRidee = pTarget->FUN_1416764a0();
            p->m_f28 = pRidee->vfunc_18().z;
        }
    }
}

// @0x1417cbaf0
void StateHoldData::vfunc_2(Unk_StateDataArg* p)
{
    StateSkillData::vfunc_2(p);
    m_nTargetId = p->m_n90;
    m_strTargetName = p->m_str98;
}

// @0x1417cbb50
MS2Ptr<SkillData> StateHoldData::FUN_1417cbb50()
{
    return reinterpret_cast<Unk_HoldSkillTable*>(TSingleton<SkillDataTableCli>::GetInstance())->FUN_1407ee1d0(m_nSkill);
}

// ---- StateHold ----

// @0x1417cbba0
StateHold::StateHold(PCBase* pOwner) : StateMoveSkill(pOwner), m_bRiding(false)
{
    m_n14 = 1;
    m_n44 = 0x20;
    m_nFallbackState = 6;
    m_nFallbackSub = 0x22;
    m_nMode = 1;
}

// @0x1417cbc70
StateHold::~StateHold()
{
}

// @0x1417cbcb0
void StateHold::vfunc_4(StateData* pData)
{
    StateMoveSkill::vfunc_4(pData);
    ((Unk_HoldBody*)(reinterpret_cast<PCBase*>(m_pOwner)->FUN_14166d220()))->FUN_141240730();
    m_spHold.AssignRaw(dynamic_cast<StateHoldData*>(pData));
    if (m_spHold == 0)
    {
        m_pOwner->vfunc_59(1, 0, 0, 0);
    }
    else
    {
        FUN_1417ccd50();
        m_pOwner->vfunc_31(false);
        MyPC* pPC = FUN_1417b84b0();
        if (pPC != 0)
        {
            if (((void*)(reinterpret_cast<PC*>(pPC)->FUN_14165f100())) != 0)
                reinterpret_cast<PC*>(pPC)->SendRequestCube();
        }
        m_kPos = m_pOwner->vfunc_18();
        m_kDir = m_pOwner->vfunc_20();
        ((Unk_HoldBody*)(reinterpret_cast<PCBase*>(m_pOwner)->FUN_14166d220()))->FUN_141240f20()->FUN_140cfaf30();
        ((Unk_HoldBody*)(reinterpret_cast<PCBase*>(m_pOwner)->FUN_14166d220()))->FUN_141241070();
    }
}

// @0x1417cbe70
void StateHold::vfunc_5(int n)
{
    StateMoveSkill::vfunc_5(n);
    ((Unk_HoldBody*)(reinterpret_cast<PCBase*>(m_pOwner)->FUN_14166d220()))->FUN_141240730();
    m_pOwner->vfunc_31(true);
    m_pOwner->vfunc_21(m_kDir);
    MyPC* pPC = FUN_1417b84b0();
    if (pPC != 0)
    {
        pPC->FUN_141676060(pPC->vfunc_18());
        if (((void*)(reinterpret_cast<Unk_CameraManager*>(reinterpret_cast<Unk_HoldCamera*>(TSingleton<CameraMgr>::GetInstance()))->FUN_140a38d60())) != pPC)
            pPC->SendRequestRideMode4();
    }
}

// @0x1417cbfa0
void StateHold::vfunc_3(double fTime)
{
    efd::SmartPointer<NiAVObject> spNode(0);
    int nAttached = 0;
    StateHoldData* pData = m_spHold.get();
    PCBase* pTarget = reinterpret_cast<Unk_HoldWorld*>(WorldService::GetInstance())->FUN_141bd1200(pData->m_nTargetId);
    if (pTarget != 0)
        spNode = pTarget->FUN_1416757c0(m_spHold.get()->m_strTargetName);
    if (((NiAVObject*)spNode ? true : false) && pTarget != 0 && pTarget->FUN_14166ce30() == 0)
    {
        if (pTarget->GetClassID() == 0x6200003 || pTarget->GetClassID() == 0x6200004)
        {
            Ridee* pRidee = FUN_1417cd1c0(pTarget->FUN_1416764a0());
            if (pRidee == 0)
                return;
            MS2Ptr<Unk_RideeData> spData = pRidee->GetData();
            if (spData == 0)
                return;
            int nSeat = pTarget->FUN_141676790(m_pOwner->FUN_14123c580());
            MS2Ptr<Unk_RideeModel> spModel = spData->FUN_1407849c0(nSeat);
            if (spModel == 0)
                return;
            nAttached = 1;
            Ridee::FUN_1417083a0(m_pOwner, spNode, spModel);
            if (FUN_1417b8560() != 0)
                m_pOwner->FUN_14166ebf0(pRidee);
        }
        else if (pTarget->GetClassID() != 0x6200045)
        {
            efd::Point3 kAngles;
            if (spNode->GetWorldRotate().ToEulerAnglesXYZ(kAngles.x, kAngles.y, kAngles.z))
            {
                FUN_140ad0c10(&kAngles, -57.2957764f);
                m_pOwner->vfunc_21(kAngles);
            }
            efd::Point3 kPos = spNode->GetWorldTranslate();
            m_pOwner->vfunc_19(kPos);
        }
    }
    else
    {
        FUN_1417ccca0(m_nFallbackState, m_nFallbackSub);
    }
    State::vfunc_3(fTime);
}

// @0x1417cc440
void StateHold::vfunc_8(double fTime)
{
    StateMoveSkill::vfunc_8(fTime);
    Unk_HoldBuffs* pBuff = ((Unk_HoldBuffs*)(reinterpret_cast<PCBase*>(m_pOwner)->FUN_14166d240()));
    efd::Point3 kZero = efd::Point3::ZERO;
    m_pOwner->vfunc_22(efd::Point3(kZero));
    if (pBuff->FUN_141683100(0x493e1))
    {
        MyPC* pPC = FUN_1417b84b0();
        if (pPC == 0)
            return;
        if (pPC->FUN_141527960() != 0)
            return;
        else
        {
            efd::Point3 kVel = pBuff->FUN_141683290();
            m_pOwner->vfunc_22(kVel);
            FUN_1417ccca0(m_nFallbackState, 0);
        }
    }
    else
    {
        FUN_1417cce10();
    }
}

// @0x1417cc5a0
void StateHold::vfunc_9(double fTime)
{
    State::vfunc_9(fTime);
    StateHoldData* pData = m_spHold.get();
    PCBase* pTarget = reinterpret_cast<Unk_HoldWorld*>(WorldService::GetInstance())->FUN_141bd1200(pData->m_nTargetId);
    if (pTarget != 0)
    {
    if (pTarget->GetClassID() == 0x6200028)
    {
        void* pNpc = FUN_14096e110(pTarget);
        if (pNpc != 0)
        {
            const int& nNpcId = reinterpret_cast<CNpc*>(pNpc)->FUN_141092fa0();
            if (nNpcId == 0xa7e02a)
            {
                Unk_HoldString kAnim("Ride_Idle_U");
                m_pOwner->FUN_14166dd20(reinterpret_cast<const efd::utf8string&>(kAnim), m_pOwner->FUN_1416713c0(), false, false);
                return;
            }
            else if (nNpcId == 0xadf341 || nNpcId == 0xadf342)
            {
                Unk_HoldString kAnim("Idle_A");
                m_pOwner->FUN_14166dd20(reinterpret_cast<const efd::utf8string&>(kAnim), m_pOwner->FUN_1416713c0(), false, false);
                return;
            }
        }
    }
    else if (pTarget->GetClassID() == 0x6200003 || pTarget->GetClassID() == 0x6200004)
    {
        PCBase* pPlayer = FUN_140974230(pTarget);
        Ridee* pRidee = pPlayer->FUN_1416764a0();
        if (pRidee == 0)
            return;
        MS2Ptr<Unk_RideeData> spData = pRidee->GetData();
        if (spData == 0)
            return;
        {
            int nSeat = pPlayer->FUN_141676790(m_pOwner->FUN_14123c580());
            MS2Ptr<Unk_RideeModel> spModel = spData->FUN_1407849c0(nSeat);
            if (spModel == 0)
                return;
            {
                if (pRidee->FUN_14166c930() == 2 || pRidee->FUN_14166c930() == 0x1b)
                {
                    if (pRidee->FUN_14166cc80() == 0x17 || pRidee->FUN_14166cc80() == 0x85)
                    {
                        Unk_HoldString kAnim(spModel->m_str50);
                        m_pOwner->FUN_14166dd20(reinterpret_cast<const efd::utf8string&>(kAnim), pRidee->FUN_1416713c0(), false, false);
                    }
                    else
                    {
                        Unk_HoldString kAnim(spModel->m_str38);
                        m_pOwner->FUN_14166dd20(reinterpret_cast<const efd::utf8string&>(kAnim), pRidee->FUN_1416713c0(), false, false);
                    }
                }
                else if (pRidee->FUN_14166c930() == 6)
                {
                    if (pRidee->FUN_14166cc80() == 0x27)
                    {
                        Unk_HoldString kAnim(spModel->m_str58);
                        m_pOwner->FUN_14166dd20(reinterpret_cast<const efd::utf8string&>(kAnim), pRidee->FUN_1416713c0(), false, false);
                    }
                    else
                    {
                        Unk_HoldString kAnim(spModel->m_str40);
                        m_pOwner->FUN_14166dd20(reinterpret_cast<const efd::utf8string&>(kAnim), pRidee->FUN_1416713c0(), false, false);
                    }
                }
                else if (pRidee->FUN_14166c930() == 1 || pRidee->FUN_14166c930() == 4)
                {
                    if (pRidee->FUN_14166cc80() == 0xc || pRidee->FUN_14166cc80() == 0x87)
                    {
                        Unk_HoldString kAnim(spModel->m_str48);
                        m_pOwner->FUN_14166dd20(reinterpret_cast<const efd::utf8string&>(kAnim), pRidee->FUN_1416713c0(), false, false);
                    }
                    else
                    {
                        Unk_HoldString kAnim(spModel->m_str30);
                        m_pOwner->FUN_14166dd20(reinterpret_cast<const efd::utf8string&>(kAnim), pRidee->FUN_1416713c0(), false, false);
                    }
                }
                else if (pRidee->FUN_141676b70() != 0)
                {
                    Unk_HoldString kAnim(spModel->m_str48);
                    m_pOwner->FUN_14166dd20(reinterpret_cast<const efd::utf8string&>(kAnim), pRidee->FUN_1416713c0(), false, false);
                }
                else
                {
                    Unk_HoldString kAnim(spModel->m_str28);
                    m_pOwner->FUN_14166dd20(reinterpret_cast<const efd::utf8string&>(kAnim), pRidee->FUN_1416713c0(), false, false);
                }
            }
        }
        return;
    }
    m_pOwner->FUN_14166dda0(0x3e);
    }
}

// @0x1417ccca0
void StateHold::FUN_1417ccca0(int nState, int nSub)
{
    m_pOwner->vfunc_59(nState, 0, nSub, 0);
}

// @0x1417cccf0
int StateHold::vfunc_15()
{
    if (m_bRiding)
        return 0;
    return 1;
}

// @0x1417ccd20
int StateHold::vfunc_16()
{
    if (m_bRiding)
        return 0;
    return 1;
}

// @0x1417ccd50
void StateHold::FUN_1417ccd50()
{
    m_bRiding = false;
    StateHoldData* pData = m_spHold.get();
    PCBase* pTarget = reinterpret_cast<Unk_HoldWorld*>(WorldService::GetInstance())->FUN_141bd1290(pData->m_nTargetId);
    if (pTarget != 0)
    {
        if (pTarget->FUN_1416764a0() != 0)
        {
            m_bRiding = true;
            MyPC* pPC = FUN_1417b84b0();
            if (pPC != 0)
                reinterpret_cast<CameraMgr*>(reinterpret_cast<Unk_HoldCamera*>(TSingleton<CameraMgr>::GetInstance()))->FUN_140aeaf40(reinterpret_cast<Unk_CameraTargetEntity*>(static_cast<Ridee*>(pTarget->FUN_1416764a0())), 1);
        }
    }
}

// @0x1417cce10
void StateHold::FUN_1417cce10()
{
    if (!FUN_140166410()->FUN_14036d570(0xae))
        return;
    Unk_HoldBuffs* pBuff = ((Unk_HoldBuffs*)(reinterpret_cast<PCBase*>(m_pOwner)->FUN_14166d240()));
    if (!pBuff->FUN_141683100(0x49401))
        return;
    MyPC* pPC = FUN_1417b84b0();
    if (pPC == 0)
        return;
    if (reinterpret_cast<PC*>(pPC)->FUN_141654700() != 0x46)
        return;
    StateHoldData* pData = m_spHold.get();
    PCBase* pTarget = reinterpret_cast<Unk_HoldWorld*>(WorldService::GetInstance())->FUN_141bd1200(pData->m_nTargetId);
    if (pTarget == 0)
        return;
    if (pPC->vfunc_122(pTarget) == 0)
        return;
    if (pTarget->vfunc_116() == 2)
        return;
    if (pTarget->GetClassID() != 0x6200028)
        return;
    Unk_InventorySkillRequest kReq(FUN_1401d3200()->m_nHoldSkill, 1);
    MS2Ptr<CSkillRecord> spRecord = pPC->FUN_141523bc0()->FUN_141765570(kReq);
    if (spRecord == 0)
        return;
    spRecord->m_nTargetId = m_spHold.get()->m_nTargetId;
    spRecord->m_strNode = m_spHold.get()->m_strTargetName;
    pPC->vfunc_102(spRecord);
}

// @0x1417cd060
bool StateHold::FUN_1417cd060()
{
    PCBase* pTarget = reinterpret_cast<Unk_HoldWorld*>(WorldService::GetInstance())->FUN_141bd1290(m_spHold.get()->m_nTargetId);
    if (pTarget != 0 && pTarget->FUN_1416764a0() != 0)
        return true;
    return false;
}

// @0x1417cd0d0
int StateHold::FUN_1417cd0d0()
{
    if ((StateHoldData*)m_spHold != 0)
        return m_spHold.get()->m_nTargetId;
    return 0;
}

// @0x1417cd120
int StateHold::vfunc_36()
{
    PCBase* pTarget = reinterpret_cast<Unk_HoldWorld*>(WorldService::GetInstance())->FUN_141bd1200(m_spHold.get()->m_nTargetId);
    if (pTarget != 0 && pTarget->GetClassID() != 0x6200045)
        return reinterpret_cast<CInputKeyHandler*>(FUN_14025e7c0())->FUN_14116dcb0(0x493e2, 0, 0);
    else
        return 1;
}

// @0x1417cd1b0
int StateHold::vfunc_37()
{
    return 1;
}

// @0x1417cd1c0
Ridee* FUN_1417cd1c0(GameObject* pObject)
{
    Ridee* pRidee = 0;
    if (pObject != 0 && pObject->TypeCast(0x6200045, (void**)&pRidee))
        return pRidee;
    else
        return 0;
}

// @0x1417cd390
MS2Ptr<StateData> StateHold::vfunc_27()
{
    return MS2Ptr<StateData>(new StateHoldData());
}

// @0x1417cd410
int StateHold::vfunc_1()
{
    return 0x20;
}
