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
#include "ms2/placeholder/effectquery.h"
#include "ms2/placeholder/fittingdollpc.h"
#include "ms2/client/ms2/effectservice.h"
#include "ms2/client/ms2/worldservice.h"

// ---- unrecovered helpers (declared with their exe signatures) ----

// The effect manager and its play request (NoticeMessage, effectquery.h).
class Unk_LtFxMgr
{
public:
    int FUN_1411a49c0(NoticeMessage* pRequest);                     // play, returns the handle
    void FUN_1411a6060(int nHandle);                                // stop
};

// The target's transform (NiTransform: rotation, translation, scale). The ctor 0x140a332d0 is out of line, and the
// position converts through NiPoint3(const efd::Point3&) (0x14027dcf0) and is move-assigned (0x14097faa0).
struct Unk_LtPoint3 { float x, y, z; Unk_LtPoint3& operator=(const Unk_LtPoint3&); };
struct Unk_LtMatrix3
{
    void FUN_142083d40(float fX, float fY, float fZ);               // efd::Matrix3::FromEulerAnglesXYZ (radians)
    float m_f[9];
};
struct Unk_LtXform
{
    Unk_LtMatrix3 m_rot;                                            // +0x00
    Unk_LtPoint3 m_pos;                                             // +0x24
    float m_fScale;                                                 // +0x30
};
void FUN_140a332d0(Unk_LtXform* p);
void FUN_14027dcf0(Unk_LtPoint3* p, const Vector3& pt);
void FUN_14097faa0(Unk_LtPoint3* p, Unk_LtPoint3* pSrc);

// Entity properties read by hash.
class Unk_Entity
{
public:
    int FUN_1409618c0(unsigned nHash, Vector3* pValue);     // point property
    int FUN_1408a2020(unsigned nHash, int* pValue);                 // int property
    int FUN_1408a2060(unsigned nHash, efd::utf8string* pValue);     // string property
};

// The quest manager: its condition interface sits at +0x10, a quest's own interface at +0x18.
struct Unk_LtIdSet
{
    __int64 FUN_14029e720();                                        // number of ids
    int FUN_14029e600(__int64 nId);                                 // contains
    void* m_pad[16];
};
class Unk_LtCond : public CPtred
{
public:
    int m_nType;                                                    // +0x18
    int m_pad_1c;
    void* m_pad_20;
    Unk_LtIdSet m_setB;                                             // +0x28
    Unk_LtIdSet m_setA;                                             // +0xa8
};
struct Unk_LtCondArr
{
    unsigned __int64 FUN_14075ae80();                               // count
    MS2Ptr<Unk_LtCond>& FUN_140759290(unsigned __int64 nIndex);     // element
};
class Unk_LtQuestData : public CPtred
{
public:
    void* m_pad[0x6e];
    Unk_LtCondArr m_conds;                                          // +0x388
};
class Unk_LtQuestIf
{
public:
    virtual MS2Ptr<Unk_LtQuestData> vfunc_0();                      // 0 the quest's data
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
void FUN_1416cb260(Unk_LtQuestMgr* pMgr, ATL::CAtlArray<int>* pOut, int a1, int a2, int a3);   // the open quest ids

// The string table global (+0x348: the box marker effect name).
class Unk_LtStrTable
{
public:
    void* m_pad[0x69];
    CString m_strBox;                                               // +0x348
};
class Unk_SingletonObj* FUN_1401d31f0();   // C3: was FUN_1401d31f0

// The local player and its actor.
class Unk_LtActorB
{
public:
    unsigned FUN_1410ad610();
};
class Unk_LtActor : public PC
{
public:
    Unk_LtActorB* FUN_141530290();
};
class Unk_LtPlayer;

// @0x141448190
CLiftableTarget::CLiftableTarget() : m_ent(0)
{
    m_ent.FUN_1408b6ec0(0);
    m_nId = 0;
    m_nFx = 0;
}

// @0x141448230
CLiftableTarget::~CLiftableTarget()
{
    FUN_141448920();
    m_ent = 0;
}

// @0x1414482a0
int CLiftableTarget::vfunc_1(Unk_EntRef ent)
{
    m_ent = ent;
    if (m_ent.FUN_1408a9280()->FUN_1409618c0(0xfd95ca52, &m_vPos) != 0)
        return 0;
    if (m_ent.FUN_1408a9280()->FUN_1409618c0(0x68c7c29d, &m_vRot) != 0)
        return 0;
    if (m_ent.FUN_1408a9280()->FUN_1408a2020(0x79ec600a, &m_nId) != 0)
        return 0;
    return 1;
}

// @0x1414483e0
void CLiftableTarget::FUN_1414483e0()
{
    Unk_LtActor* pActor = ((class Unk_LtActor*)((class WorldService*)(class Unk_LtPlayer*)(reinterpret_cast<Unk_LtPlayer*>(WorldService::GetInstance())))->FUN_141bd0cc0());
    if (pActor == 0)
        return;
    if (pActor->FUN_1416595d0() == 0)
    {
        FUN_141448920();
        return;
    }
    ATL::CAtlArray<int> ids;
    FUN_1416cb260(((class Unk_LtQuestMgr*)FUN_140764020()), &ids, 1, 0xb, 0xffffffff);
    for (unsigned __int64 i = 0; i < ids.GetCount(); i++)
    {
        MS2Ptr<Unk_LtQuest> spQuest = (&((class Unk_LtQuestMgr*)FUN_140764020())->m_if)->vfunc_3(ids[i]);
        if (spQuest.IsNull())
            continue;
        if ((&spQuest->m_if)->vfunc_1() != 0)
            continue;
        MS2Ptr<Unk_LtQuestData> spData = (&spQuest->m_if)->vfunc_0();
        for (unsigned __int64 j = 0; j < spData->m_conds.FUN_14075ae80(); j++)
        {
            if (spData->m_conds.FUN_140759290(j)->m_nType != 0x9c)
                continue;
            if (spData->m_conds.FUN_140759290(j)->m_setA.FUN_14029e720() != 1)
                continue;
            if (spData->m_conds.FUN_140759290(j)->m_setA.FUN_14029e600((__int64)m_nId) == 0)
                continue;
            if (spData->m_conds.FUN_140759290(j)->m_setB.FUN_14029e600((unsigned __int64)pActor->FUN_141530290()->FUN_1410ad610()) == 0)
                continue;
            FUN_141448750();
            return;
        }
    }
    FUN_141448920();
}

// @0x141448750
void CLiftableTarget::FUN_141448750()
{
    if (m_nFx != 0)
        return;
    Unk_LtXform xform;
    FUN_140a332d0(&xform);
    Unk_LtPoint3 kPos;
    FUN_14027dcf0(&kPos, m_vPos.FUN_14097fd50(Vector3(0.0f, 0.0f, 1.0f)));
    FUN_14097faa0(&xform.m_pos, &kPos);
    xform.m_rot.FUN_142083d40(m_vRot.x * 3.1415927f / 180.0f, m_vRot.y * 3.1415927f / 180.0f, m_vRot.z * 3.1415927f / 180.0f);
    xform.m_fScale = 1.0f;
    NoticeMessage req;
    req.m_strName = vfunc_2();
    req.m_nObject = 0;
    req.m_p18 = &xform;
    m_nFx = reinterpret_cast<Unk_LtFxMgr*>(TSingleton<CEffectService>::GetInstance())->FUN_1411a49c0(&req);
}

// @0x141448920
void CLiftableTarget::FUN_141448920()
{
    if (m_nFx == 0)
        return;
    reinterpret_cast<Unk_LtFxMgr*>(TSingleton<CEffectService>::GetInstance())->FUN_1411a6060(m_nFx);
    m_nFx = 0;
}

// @0x141448970
CString CLiftableTargetBox::vfunc_2()
{
    return ((class Unk_LtStrTable*)FUN_1401d31f0())->m_strBox;
}

// @0x1414489c0
int CLiftableTargetGuide::vfunc_1(Unk_EntRef ent)
{
    if (CLiftableTarget::vfunc_1(ent) == 0)
        return 0;
    efd::utf8string name;
    if (m_ent.FUN_1408a9280()->FUN_1408a2060(0x86adffcf, &name) != 0)
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
// (vfunc_1 takes Unk_EntRef by value and FUN_1414483e0 / FUN_141448750 go through unrecovered quest/effect views: not hooked)
MS2_REPLACE_METHOD(0x141448920, CLiftableTarget, FUN_141448920, 60, 0x767CACA6);
MS2_REPLACE_METHOD(0x141448970, CLiftableTargetBox, vfunc_2, 68, 0x6C0F74DD);
MS2_REPLACE_METHOD(0x141448B00, CLiftableTargetGuide, vfunc_2, 66, 0x7D865BC0);
