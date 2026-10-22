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
#include <efd/Matrix3.h>

// ---- unrecovered helpers (declared with their exe signatures) ----

// The effect / sound manager and its 0x78-byte play request.
struct Unk_LtFxReq
{
    CString m_strName;                                              // +0x00
    int m_nType;                                                    // +0x08
    int m_nPad0c;                                                   // +0x0c
    void* m_pad_10;                                                 // +0x10
    void* m_pXform;                                                 // +0x18 the transform the effect follows
    void* m_unk[11];                                                // +0x20 (constructed by FUN_140a52ef0)
};
class Unk_LtFxMgr
{
public:
    int FUN_1411a49c0(Unk_LtFxReq* pRequest);                       // play, returns the handle
    void FUN_1411a6060(int nHandle);                                // stop
};
Unk_LtFxMgr* FUN_1403ed280();
void FUN_140a52ef0(Unk_LtFxReq* p);                                 // construct
void FUN_1405a89e0(Unk_LtFxReq* p);                                 // destroy

// The target's transform: rotation, translation, scale.
struct Unk_LtXform
{
    efd::Matrix3 m_rot;                                             // +0x00
    Vector3 m_pos;                                          // +0x24
    float m_fScale;                                                 // +0x30
};

// Entity properties read by hash.
class Unk_Entity
{
public:
    int FUN_1409618c0(unsigned nHash, Vector3* pValue);     // point property
    int FUN_1408a2020(unsigned nHash, int* pValue);                 // int property
    int FUN_1408a2060(unsigned nHash, struct Unk_LtName* pValue);   // string property
};
struct Unk_LtName
{
    char m_buf[32];
};
void FUN_1408a8700(Unk_LtName* p);                                  // construct
void FUN_1408a8900(Unk_LtName* p);                                  // destroy
const char* FUN_1408ac310(Unk_LtName* p);                           // c_str

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
Unk_LtQuestMgr* FUN_140764020();
void FUN_1416cb260(Unk_LtQuestMgr* pMgr, ATL::CAtlArray<int>* pOut, int a1, int a2, int a3);   // the open quest ids

// The string table global (+0x348: the box marker effect name).
class Unk_LtStrTable
{
public:
    void* m_pad[0x69];
    CString m_strBox;                                               // +0x348
};
Unk_LtStrTable* FUN_1401d31f0();

// The local player and its actor.
class Unk_LtActorB
{
public:
    unsigned FUN_1410ad610();
};
class Unk_LtActor
{
public:
    int FUN_1416595d0();                                            // lift mode on
    Unk_LtActorB* FUN_141530290();
};
class Unk_LtPlayer;
Unk_LtPlayer* FUN_1403ed2d0();
Unk_LtActor* FUN_141bd0cc0(Unk_LtPlayer* pPlayer);

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
// MS2-FUNCTIONAL: written from the decompile; the quest chain's temporaries/EH states are not matched
void CLiftableTarget::FUN_1414483e0()
{
    Unk_LtActor* pActor = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pActor == 0)
        return;
    if (pActor->FUN_1416595d0() == 0)
    {
        FUN_141448920();
        return;
    }
    ATL::CAtlArray<int> ids;
    FUN_1416cb260(FUN_140764020(), &ids, 1, 0xb, 0xffffffff);
    for (unsigned __int64 i = 0; i < ids.GetCount(); i++)
    {
        Unk_LtQuestMgrIf* pIf = &FUN_140764020()->m_if;
        MS2Ptr<Unk_LtQuest> spQuest = pIf->vfunc_3(ids[i]);
        if (spQuest.IsNull())
            continue;
        Unk_LtQuestIf* pQuestIf = &spQuest->m_if;
        if (pQuestIf->vfunc_1() != 0)
            continue;
        MS2Ptr<Unk_LtQuestData> spData = pQuestIf->vfunc_0();
        for (unsigned __int64 j = 0; j < spData->m_conds.FUN_14075ae80(); j++)
        {
            MS2Ptr<Unk_LtCond>& spCond = spData->m_conds.FUN_140759290(j);
            if (spCond->m_nType == 0x9c)
            {
                if (spCond->m_setA.FUN_14029e720() == 1)
                {
                    if (spCond->m_setA.FUN_14029e600((__int64)m_nId) != 0)
                    {
                        unsigned nMap = pActor->FUN_141530290()->FUN_1410ad610();
                        if (spCond->m_setB.FUN_14029e600((unsigned __int64)nMap) != 0)
                        {
                            FUN_141448750();
                            return;
                        }
                    }
                }
            }
        }
    }
    FUN_141448920();
}

// @0x141448750
// MS2-FUNCTIONAL: the exe copies the sum through efd::Point3's copy ctor / operator= (0x14027dcf0 / 0x14097faa0)
void CLiftableTarget::FUN_141448750()
{
    if (m_nFx != 0)
        return;
    {
        Unk_LtXform xform;
        xform.m_pos = m_vPos.FUN_14097fd50(Vector3(0.0f, 0.0f, 1.0f));
        xform.m_rot.FromEulerAnglesXYZ(m_vRot.x * 3.1415927f / 180.0f, m_vRot.y * 3.1415927f / 180.0f, m_vRot.z * 3.1415927f / 180.0f);
        xform.m_fScale = 1.0f;
        Unk_LtFxReq req;
        FUN_140a52ef0(&req);
        req.m_strName = vfunc_2();
        req.m_nType = 0;
        req.m_pXform = &xform;
        m_nFx = FUN_1403ed280()->FUN_1411a49c0(&req);
        FUN_1405a89e0(&req);
    }
}

// @0x141448920
void CLiftableTarget::FUN_141448920()
{
    if (m_nFx == 0)
        return;
    FUN_1403ed280()->FUN_1411a6060(m_nFx);
    m_nFx = 0;
}

// @0x141448970
CString CLiftableTargetBox::vfunc_2()
{
    return FUN_1401d31f0()->m_strBox;
}

// @0x1414489c0
// MS2-FUNCTIONAL: the exe has a second EH state around the name object (nop after the destroy call)
int CLiftableTargetGuide::vfunc_1(Unk_EntRef ent)
{
    if (CLiftableTarget::vfunc_1(ent) == 0)
        return 0;
    Unk_LtName name;
    FUN_1408a8700(&name);
    if (m_ent.FUN_1408a9280()->FUN_1408a2060(0x86adffcf, &name) != 0)
    {
        FUN_1408a8900(&name);
        return 0;
    }
    m_strGuide = FUN_1408ac310(&name);
    FUN_1408a8900(&name);
    return 1;
}

// @0x141448b00
CString CLiftableTargetGuide::vfunc_2()
{
    return m_strGuide;
}

// ---- hooks ----
// (vfunc_1 takes Unk_EntRef by value and FUN_1414483e0 / FUN_141448750 are functional over unrecovered quest/effect types: not hooked)
MS2_REPLACE_METHOD(0x141448920, CLiftableTarget, FUN_141448920, 60, 0x767CACA6);
MS2_REPLACE_METHOD(0x141448970, CLiftableTargetBox, vfunc_2, 68, 0x6C0F74DD);
MS2_REPLACE_METHOD(0x141448B00, CLiftableTargetGuide, vfunc_2, 66, 0x7D865BC0);
