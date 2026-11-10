// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). See liftabletarget.h.
// MS2-UNIT: ?\liftabletarget.cpp
// MS2-RANGE: 0x141448190-0x141448b90 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\liftabletarget.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "liftabletarget.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include <atlcoll.h>
#include <efd/utf8string.h>
#include <NiPoint3.h>
#include "ms2/placeholder/effectquery.h"
#include "ms2/placeholder/cconditioncommon.h"
#include "ms2/placeholder/mypc.h"
#include "ms2/client/ms2/questmanager_2.h"
#include "ms2/client/ms2/cubecraft_2.h"
#include "ms2/placeholder/fittingdollpc.h"
#include "ms2/client/ms2/effectservice.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/placeholder/questdata.h"   // C3: CQuestData, the quest's data

// ---- unrecovered helpers (declared with their exe signatures) ----

// The quest manager: its condition interface sits at +0x10, a quest's own interface at +0x18.
MS2_CHECK_OFFSET(CQuestData, m_conditions, 0x388);   // C3: was the unit-local view Unk_LtQuestData
class Unk_LtQuestIf
{
public:
    virtual MS2Ptr<CQuestData> vfunc_0();                      // 0 the quest's data
    virtual int vfunc_1();                                          // 1 finished
};
class Unk_LtQuest : public CPtred
{
public:
    Unk_LtQuestIf m_if;                                             // +0x18
};
class Unk_LtQuestMgrIf
{
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual MS2Ptr<Unk_LtQuest> vfunc_3(int nQuestId);              // 3 the quest of an id
};
class Unk_LtQuestMgr
{
public:
    void* m_pad_00;
    void* m_pad_08;
    Unk_LtQuestMgrIf m_if;                                          // +0x10
};
void* FUN_140764020();   // C3: was FUN_140764020

// The string table global (+0x348: the box marker effect name).
class Unk_LtStrTable
{
public:
    void* m_pad[0x69];
    CString m_strBox;                                               // +0x348
};
class Unk_SingletonObj* GetCommonResource();   // C3: was GetCommonResource

// The local player and its actor.
class Unk_LtActor : public PC
{
};
class Unk_LtPlayer;

// @0x141448190
CLiftableTarget::CLiftableTarget() : m_ent(0)
{
    m_ent = 0;
    m_nId = 0;
    m_nFx = 0;
}

// @0x141448230
CLiftableTarget::~CLiftableTarget()
{
    DestroyEffect();
    m_ent = 0;
}

// @0x1414482a0
int CLiftableTarget::vfunc_1(egf::EntityPtr ent)
{
    m_ent = ent;
    if (m_ent->GetPropertyValue<efd::Point3>(0xfd95ca52, (efd::Point3&)(m_vPos)) != 0)
        return 0;
    if (m_ent->GetPropertyValue<efd::Point3>(0x68c7c29d, (efd::Point3&)(m_vRot)) != 0)
        return 0;
    if (m_ent->GetPropertyValue<int>(0x79ec600a, m_nId) != 0)
        return 0;
    return 1;
}

// @0x1414483e0
void CLiftableTarget::FUN_1414483e0()
{
    Unk_LtActor* pActor = ((class Unk_LtActor*)((class WorldService*)(class Unk_LtPlayer*)(reinterpret_cast<Unk_LtPlayer*>(WorldService::GetInstance())))->GetLocalPlayer());
    if (pActor == 0)
        return;
    if (pActor->IsInCubeMode() == 0)
    {
        DestroyEffect();
        return;
    }
    ATL::CAtlArray<int> ids;
    reinterpret_cast<CQuestManager*>(((class Unk_LtQuestMgr*)FUN_140764020()))->GetQuestIdsFiltered(reinterpret_cast<ATL::CAtlArray<unsigned>&>(ids), 1, 0xb, 0xffffffff);
    for (unsigned __int64 i = 0; i < ids.GetCount(); i++)
    {
        MS2Ptr<Unk_LtQuest> spQuest = (&((class Unk_LtQuestMgr*)FUN_140764020())->m_if)->vfunc_3(ids[i]);
        if (spQuest.IsNull())
            continue;
        if ((&spQuest->m_if)->vfunc_1() != 0)
            continue;
        MS2Ptr<CQuestData> spData = (&spQuest->m_if)->vfunc_0();
        for (unsigned __int64 j = 0; j < spData->m_conditions.GetCount(); j++)
        {
            if (spData->m_conditions[j]->m_nType != 0x9c)
                continue;
            if (spData->m_conditions[j]->m_target.GetIdCount() != 1)
                continue;
            if (spData->m_conditions[j]->m_target.Matches((__int64)m_nId) == 0)
                continue;
            if (spData->m_conditions[j]->m_code.Matches((unsigned __int64)(unsigned)reinterpret_cast<MyPC*>(pActor)->GetActiveCubeCraft()->GetItemId()) == 0)
                continue;
            CreateEffect();
            return;
        }
    }
    DestroyEffect();
}

// @0x141448750
void CLiftableTarget::CreateEffect()
{
    if (m_nFx != 0)
        return;
    NiTransform xform;
    xform.m_Translate = reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(reinterpret_cast<const efd::Point3&>(m_vPos) + reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(Vector3(0.0f, 0.0f, 1.0f)))))));
    xform.m_Rotate.FromEulerAnglesXYZ(m_vRot.x * 3.1415927f / 180.0f, m_vRot.y * 3.1415927f / 180.0f, m_vRot.z * 3.1415927f / 180.0f);
    xform.m_fScale = 1.0f;
    NoticeMessage req;
    req.m_strName = vfunc_2();
    req.m_nObject = 0;
    req.m_p18 = &xform;
    m_nFx = TSingleton<CEffectService>::GetInstance()->FUN_1411a49c0(*reinterpret_cast<Unk_EffectTarget*>(&req));
}

// @0x141448920
void CLiftableTarget::DestroyEffect()
{
    if (m_nFx == 0)
        return;
    TSingleton<CEffectService>::GetInstance()->FUN_1411a6060(m_nFx);
    m_nFx = 0;
}

// @0x141448970
CString CLiftableTargetBox::vfunc_2()
{
    return ((class Unk_LtStrTable*)GetCommonResource())->m_strBox;
}

// @0x1414489c0
int CLiftableTargetGuide::vfunc_1(egf::EntityPtr ent)
{
    if (CLiftableTarget::vfunc_1(ent) == 0)
        return 0;
    efd::utf8string name;
    if (m_ent->GetPropertyValue<efd::utf8string>(0x86adffcf, name) != 0)
        return 0;
    m_strGuide = name.c_str();
    return 1;
}

// @0x141448b00
CString CLiftableTargetGuide::vfunc_2()
{
    return m_strGuide;
}

// ---- hooks ----
// (vfunc_1 takes egf::EntityPtr by value and FUN_1414483e0 / CreateEffect go through unrecovered quest/effect views: not hooked)
MS2_REPLACE_METHOD(0x141448920, CLiftableTarget, DestroyEffect, 60, 0x767CACA6);
MS2_REPLACE_METHOD(0x141448970, CLiftableTargetBox, vfunc_2, 68, 0x6C0F74DD);
MS2_REPLACE_METHOD(0x141448B00, CLiftableTargetGuide, vfunc_2, 66, 0x7D865BC0);
