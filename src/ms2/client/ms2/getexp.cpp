// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CExpEffectInfo (one exp orb flying from a killed monster
// to the local player) and CGetExp (the list of live orbs). See getexp.h.
// MS2-UNIT: ?\getexp.cpp
// MS2-RANGE: 0x1400eb710-0x1400eba80 .text$di
// MS2-RANGE: 0x141272630-0x141274d10 .text$mn
// MS2-PIN: ??__Es_strSkill@@YAXXZ 0x1400eb860
// MS2-PIN: ??__Es_strStun@@YAXXZ 0x1400eb890
// MS2-PIN: ?get@?$MS2Ptr@VCExpEffectInfo@@@@QEBAPEAVCExpEffectInfo@@XZ 0x141273f30
// MS2-PIN: ??C?$MS2Ptr@VCExpEffectInfo@@@@QEBAPEAVCExpEffectInfo@@XZ 0x141273f40
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??A?$CAtlArray@PEAU__POSITION@@V?$CElementTraits@PEAU__POSITION@@@ATL@@@ATL@@QEAAAEAPEAU__POSITION@@_K@Z 0x1412741f0 ; unique
// MS2-PIN: ?RemoveAt@?$CAtlList@V?$MS2Ptr@VCExpEffectInfo@@@@V?$CElementTraits@V?$MS2Ptr@VCExpEffectInfo@@@@@ATL@@@ATL@@QEAAXPEAU__POSITION@@@Z 0x141274840 ; unique
// MS2-PIN: ?AddRefImpl@?$MS2Ptr@VCExpEffectInfo@@@@AEBAXPEAX@Z 0x141274970 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\getexp.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <efd/Matrix3.h>   // C3: efd::Matrix3::GetCol
#include "ms2/placeholder/commonresource.h"
#include <efd/Point3.h>

#include <NiNode.h>
#include <NiAVObject.h>
#include <string.h>

#include "getexp.h"

#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- the unit's own statics: two offsets of the orb's launch spread, and the dummy node name ----
static Vector3 s_ptSpreadMin(-0.5f, 0.0f, 0.25f);       // @0x1400eb710
static Vector3 s_ptSpreadMax(0.5f, 0.0f, 0.5f);         // @0x1400eb740
CString s_strEffDummy = "Eff_Dummy";                             // @0x1400eb770 (reassigned from the constants);
                                                                 // also the GetExpTargetPCDummyName default (constantsblocks)

// ---- the shared header statics, once more (this unit includes the header twice) ----
#include "ms2/placeholder/header_statics_a.h"       // names @0x1400eb7a0, skill @0x1400eb860, stun @0x1400eb890, condition @0x1400eb8c0
#include "ms2/client/ms2/worldservice.h"
#include "ms2/client/ms2/effectservice.h"
#include "ms2/placeholder/cmainsystem.h"
#include "ms2/placeholder/clientconstants.h"  // C3: Common::Constants::Value<float>::Read
#include "ms2/client/ms2/randomeffectparam.h"
#include <efd/ClassInfo.h>
#include <algorithm>
class NoticeMessage   // C3: unit-local view (ctor 0x140a52ef0, dtor 0x1405a89e0, 0x70 bytes)
{
public:
    NoticeMessage();
    ~NoticeMessage();
    void SetActor(int nActor);                                      // 0x140a53190
    void* m_storage[14];
};
static CString s_strSortTypeNames2[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};   // @0x1400eb910
static CString s_strSkill2 = "skill";                // @0x1400eb9d0
static CString s_strStun2 = "stun";                  // @0x1400eba00
static Unk_1402a9d70 s_unk1402a9d70_2(17, 0.75f, 0.25f, 2.25f, 10);   // @0x1400eba30

// ---- exe data ----
#define DAT_143b01a60 (*(Vector3*)&efd::Point3::ZERO)          // C3: was extern Vector3 DAT_143b01a60
extern Unk_EfdMatrix3 DAT_143a09600;        // the identity matrix
#define DAT_143a08cf8 (*(Vector3*)&efd::Point3::UNIT_Z) // C3: was extern Vector3 DAT_143a08cf8; axis a (the up axis)
#define DAT_143a08cd8 (*(Vector3*)&efd::Point3::UNIT_X) // C3: was extern Vector3 DAT_143a08cd8; axis b
extern float DAT_1439f733c;                 // minimum travel distance
extern float DAT_1439f7340;                 // travel distance scale
extern float DAT_1439f7344;                 // arrival radius scale
extern float DAT_1439f7348;                 // elapsed decay
extern float DAT_1439f734c;                 // player flash r
extern float DAT_1439f7350;                 // player flash g
extern float DAT_1439f7354;                 // player flash b

// ---- unit-local views of exe objects ----

// Uninitialized storage for a position returned through a vfunc.
struct Unk_PosBuf { float x, y, z; };

// A world object (monster, player): slot 6 returns its class info, slot 18 its position.
class Unk_ExpActor
{
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5();
    virtual void* GetClassInfo();                                   // slot 6 (+0x30)
    virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10();
    virtual void vfunc_11(); virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14();
    virtual void vfunc_15(); virtual void vfunc_16(); virtual void vfunc_17();
    virtual Vector3 GetPosition();                  // slot 18 (+0x90)
};
class GameObject   // C3: member view for the former free stand-ins
{
public:
    float FUN_14123c260();
    int FUN_14123c580();
    unsigned __int64 GenerateSerialId();
};
class PCBase   // C3: member view for the former free stand-ins
{
public:
    void AddColorBoost(float, float, float);
    NiAVObject* FUN_141675150(const CString& strNode);
};
__int64 FUN_14028d0e0();                                            // seed counter

// The world service (0x1403ed2d0) and its object lookups.
class Unk_AttendAvatarMgr : public WorldService
{
public:
};

struct Unk_ExpTarget;

// Effect request (0x70 bytes; ctor 0x140a52ef0, dtor 0x1405a89e0).
struct Unk_ExpTarget
{
    Unk_ExpTarget();                                                // 0x140a52ef0
    ~Unk_ExpTarget();                                               // 0x1405a89e0
    CString m_strName;                                              // +0x00
    int m_nOwnerId;                                                 // +0x08
    int m_pad_0c;
    efd::SmartPointer<NiAVObject> m_spNode;                         // +0x10 (0x1409fabf0)
    __int64 m_pad_18, m_pad_20, m_pad_28, m_pad_30, m_pad_38, m_pad_40, m_pad_48, m_pad_50, m_pad_58, m_pad_60, m_pad_68;
};
MS2_CHECK_SIZE(Unk_ExpTarget, 0x70);

float FUN_1407680d0(Unk_Random* p);                                 // next value of the three-seed generator

// The client constants (0x1401d3200) and the singleton holding the effect names (0x1401d31f0).
struct Unk_ClientConfig;
class Unk_ConfigFloat { public: };                           // Value<float>::get
class Unk_ConfigPoint
{
public:
    Vector3 FUN_141273d00() const;                          // copy of the value (0x141273d00)
    // the value getter 0x141274420 is Common::Constants::Value<efd::Point3>::Get() (defined below)
    virtual void vfunc_0(); virtual void vfunc_1();
    bool m_bInit; char m_flag9, m_flagA, m_flagB; unsigned m_unkC;
    char m_pad_10[0x40];
    Vector3 m_value;                                        // +0x50
};
// C3: the string getter 0x140298f80 is Common::Constants::Value<CString>::Get() (clientconstants.h)
// C3: was FUN_1401d3200 (= TSingleton<Client::Constants>::GetInstance, GetClientConstants())

// Unit helpers declared elsewhere.
// (0x140194470 is efd::Point3::operator=(const Point3&))
efd::Point3 FUN_141b71390(Vector3 a, Vector3 b, Vector3 c, float t);   // curve point
bool FUN_14147aa60(const NiPoint3& kOrigin, const NiPoint3& kDir, const NiPoint3& kCenter,
                   float fRadius, NiPoint3* pHit);                                   // ray / sphere hit
void FUN_140a0b2a0(NiAVObject* pNode);                                               // detach from the parent
class Unk_Clock;

// ---- CExpEffectInfo ----

// @0x141272630
CExpEffectInfo::CExpEffectInfo()
    : m_pOwner(0), m_n20(0), m_hEffect(0), m_spNode((NiNode*)0), m_ptPos(DAT_143b01a60), m_fElapsed(0),
      m_rot(DAT_143a09600), m_fProgress(0), m_fTotal(0), m_ptTarget(DAT_143b01a60), m_ptSource(DAT_143b01a60),
      m_nState(0)
{
    InitConstants();
}

// @0x141272760
CExpEffectInfo::~CExpEffectInfo()
{
    StopEffect();
    FUN_140a0b2a0((NiAVObject*)m_spNode.operator NiNode*());
}

// @0x1412727d0
Vector3 CExpEffectInfo::GetAxis0() const
{
    Vector3 pt;
    reinterpret_cast<const efd::Matrix3&>(m_rot).GetCol(0, reinterpret_cast<efd::Point3&>(pt));
    return pt;
}

// @0x141272830
Vector3 CExpEffectInfo::GetAxis1() const
{
    Vector3 pt;
    reinterpret_cast<const efd::Matrix3&>(m_rot).GetCol(1, reinterpret_cast<efd::Point3&>(pt));
    return pt;
}

// @0x141272890
Vector3 CExpEffectInfo::GetAxis2() const
{
    Vector3 pt;
    reinterpret_cast<const efd::Matrix3&>(m_rot).GetCol(2, reinterpret_cast<efd::Point3&>(pt));
    return pt;
}

// @0x1412728f0
void CExpEffectInfo::UpdateOrientation()
{
    Vector3 vDir = m_ptTarget.FUN_140965c40(m_ptSource);
    vDir.FUN_140968990();
    Unk_NiMatrix3 kMat;
    efd::Point3 vNeg = -reinterpret_cast<const efd::Point3&>(vDir);
    Vector3 vUp = DAT_143b01a60;
    if (reinterpret_cast<const efd::Point3&>(vNeg) == reinterpret_cast<const efd::Point3&>(DAT_143a08cf8))
    {
        vUp = DAT_143a08cd8;
    }
    else if (reinterpret_cast<const efd::Point3&>(vNeg) == static_cast<const efd::Point3&>(-reinterpret_cast<const efd::Point3&>(DAT_143a08cf8)))
    {
        reinterpret_cast<efd::Point3&>(vUp) = -reinterpret_cast<const efd::Point3&>(DAT_143a08cd8);
    }
    else
    {
        reinterpret_cast<efd::Point3&>(vUp) = reinterpret_cast<const efd::Point3&>(vNeg).UnitCross(reinterpret_cast<const efd::Point3&>(DAT_143a08cf8));
    }
    efd::Point3 vSide = reinterpret_cast<const efd::Point3&>(vUp).UnitCross(reinterpret_cast<const efd::Point3&>(vNeg));
    reinterpret_cast<efd::Matrix3&>(kMat).SetCol(0, reinterpret_cast<const efd::Point3&>(vUp));
    reinterpret_cast<efd::Matrix3&>(kMat).SetCol(1, reinterpret_cast<const efd::Point3&>(vNeg));
    reinterpret_cast<efd::Matrix3&>(kMat).SetCol(2, reinterpret_cast<const efd::Point3&>(vSide));
    m_rot = kMat;
    ((class NiAVObject*)(void*)(m_spNode.operator->()))->SetRotate(*(class NiMatrix3 const*)(&kMat));
    ((NiAVObject*)m_spNode.operator->())->Update((float)((class CMainSystem*)(class Unk_Clock*)(reinterpret_cast<Unk_Clock*>(TSingleton<CMainSystem>::GetInstance())))->FUN_141473280(), false);
}

static int s_nConstInit = 0;                                        // @0x143ad6000

#ifndef MS2_HOOK_DLL
// @0x141272b10
void CExpEffectInfo::InitConstants()
{
    if (s_nConstInit != 0)
        return;
    DAT_1439f733c = reinterpret_cast<Common::Constants::Value<float>*>(reinterpret_cast<Unk_ConfigFloat*>((char*)((struct Unk_ClientConfig*)GetClientConstants()) + 0x21b8))->Read();
    DAT_1439f7340 = reinterpret_cast<Common::Constants::Value<float>*>(reinterpret_cast<Unk_ConfigFloat*>((char*)((struct Unk_ClientConfig*)GetClientConstants()) + 0x2210))->Read();
    DAT_1439f7348 = reinterpret_cast<Common::Constants::Value<float>*>(reinterpret_cast<Unk_ConfigFloat*>((char*)((struct Unk_ClientConfig*)GetClientConstants()) + 0x2268))->Read();
    DAT_1439f7344 = reinterpret_cast<Common::Constants::Value<float>*>(reinterpret_cast<Unk_ConfigFloat*>((char*)((struct Unk_ClientConfig*)GetClientConstants()) + 0x22c0))->Read();
    Vector3 kMin = reinterpret_cast<Unk_ConfigPoint*>((char*)((struct Unk_ClientConfig*)GetClientConstants()) + 0x2318)->FUN_141273d00();
    s_ptSpreadMin = kMin;
    Vector3 kMax = reinterpret_cast<Unk_ConfigPoint*>((char*)((struct Unk_ClientConfig*)GetClientConstants()) + 0x2380)->FUN_141273d00();
    s_ptSpreadMax = kMax;
    s_strEffDummy = *reinterpret_cast<Common::Constants::Value<CString>*>((char*)((struct Unk_ClientConfig*)GetClientConstants()) + 0x23e8)->Get();
    s_nConstInit = 1;
}
#endif

// @0x141272c20
void CExpEffectInfo::StopEffect()
{
    if (m_hEffect > 0)
    {
        TSingleton<CEffectService>::GetInstance()->FUN_1411a6060(m_hEffect);
        m_hEffect = 0;
    }
}

// @0x141272c60
void CExpEffectInfo::Update(float fElapsed)
{
    if (m_nState != 0 || m_spNode.operator NiNode*() == 0)
        return;
    UpdateMove(fElapsed);
}

// @0x141272cb0
void CExpEffectInfo::UpdateMove(float fElapsed)
{
    Unk_ExpActor* pPlayer = (Unk_ExpActor*)reinterpret_cast<Unk_AttendAvatarMgr*>(WorldService::GetInstance())->FUN_141bd0cc0();
    if (pPlayer == 0)
        return;
    GetTargetPos(pPlayer, &m_ptTarget);
    float fDist = m_ptSource.FUN_140965c40(m_ptTarget).FUN_140967ac0();
    m_fProgress = fDist / m_fTotal;
    UpdateOrientation();
    bool bDone = m_fElapsed >= m_fProgress;
    if (bDone)
    {
        Finish();
    }
    else
    {
        m_fElapsed = m_fElapsed + fElapsed;
        m_fElapsed = m_fElapsed * DAT_1439f7348;
        bDone = m_fElapsed >= m_fProgress;
        if (bDone)
            Finish();
        else
        {
            float fT = m_fElapsed / m_fProgress;
            efd::Point3 ptNew = FUN_141b71390(m_ptSource, m_ptPos, m_ptTarget, fT);
            SetPosition(reinterpret_cast<Vector3&>(ptNew));
        }
    }
}

// @0x141272f20
int CExpEffectInfo::Create(int nObjectId, void* pOwner)
{
    Unk_ExpActor* pPlayer = (Unk_ExpActor*)reinterpret_cast<Unk_AttendAvatarMgr*>(WorldService::GetInstance())->FUN_141bd0cc0();
    if (pPlayer == 0)
        return 0;
    Unk_ExpActor* pObj = reinterpret_cast<Unk_ExpActor*>(WorldService::GetInstance()->FUN_141bd1200(nObjectId));
    if (pObj == 0)
        return 0;
    m_spNode = new (efd::MemHint(efd::MemHint::NONE)) NiNode(0);
    if (m_spNode.operator NiNode*() == 0)
        return 0;
    m_pOwner = pOwner;
    m_fElapsed = 0;
    m_ptSource = pObj->GetPosition();
    GetTargetPos(pPlayer, &m_ptTarget);
    Vector3 vDir = m_ptTarget.FUN_140965c40(m_ptSource);
    float fLen = vDir.FUN_140968990();
    float fScaled = fLen * DAT_1439f7340;
    m_fTotal = std::max<float>(DAT_1439f733c, fScaled);
    m_fProgress = fLen / m_fTotal;
    UpdateOrientation();
    int nSeedA = (int)FUN_14028d0e0() + nObjectId;
    int nSeedB = (int)reinterpret_cast<GameObject*>(pPlayer)->GenerateSerialId() + nObjectId;
    int nSeedC = nSeedA * nSeedB * nObjectId;
    Unk_Random kRandom(nSeedA, nSeedB, nSeedC);
    float fRandX = FUN_1407680d0(&kRandom);
    float fRandY = FUN_1407680d0(&kRandom);
    float fRandZ = FUN_1407680d0(&kRandom);
    // [0] = spread min, [1] = spread max, both scaled by the distance
    efd::Point3 aSpread[2] = { reinterpret_cast<const efd::Point3&>(s_ptSpreadMin) * fLen, reinterpret_cast<const efd::Point3&>(s_ptSpreadMax) * fLen };
    aSpread[0].y = aSpread[0].y / m_fTotal;
    aSpread[1].y = aSpread[1].y / m_fTotal;
    Vector3 ptRange = reinterpret_cast<Vector3&>(aSpread[1]).FUN_140965c40(reinterpret_cast<Vector3&>(aSpread[0]));
    Vector3 ptOffset(aSpread[0].x + ptRange.x * fRandX, aSpread[0].y + ptRange.y * fRandY, aSpread[0].z + ptRange.z * fRandZ);
    reinterpret_cast<efd::Point3&>(m_ptPos) =
                                reinterpret_cast<const efd::Point3&>(m_ptSource) + reinterpret_cast<const efd::Point3&>(vDir) * ptOffset.y * fLen
                                    + reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(GetAxis2())) * ptOffset.z
                                    + reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(GetAxis0())) * ptOffset.x;
    SetPosition(m_ptSource);
    NiNode* pRoot = TSingleton<CEffectService>::GetInstance()->GetLeastLoadedRoot();
    pRoot->AttachChild((NiAVObject*)m_spNode.operator NiNode*(), true);
    NoticeMessage kRequest;   // C3: was Unk_ExpTarget
    ((Unk_ExpTarget&)(kRequest)).m_spNode = (NiAVObject*)m_spNode.operator NiNode*();
    ((Unk_ExpTarget&)(kRequest)).m_strName = TSingleton<CommonResource>::GetInstance()->m_strEffectGetExp;
    ((Unk_ExpTarget&)(kRequest)).m_nOwnerId = WorldService::GetInstance()->FUN_141bd1a10(reinterpret_cast<class Unk_WsC_GameObj*>(pObj));
    kRequest.SetActor(((class GameObject*)(class Unk_ExpActor*)(pObj))->FUN_14123c580());
    m_hEffect = TSingleton<CEffectService>::GetInstance()->FUN_1411a49c0(*reinterpret_cast<Unk_EffectTarget*>(&((Unk_ExpTarget&)(kRequest))));
    return 1;
}

// @0x141273570
int CExpEffectInfo::GetState() const
{
    return m_nState;
}

// @0x141273590
void CExpEffectInfo::SetPosition(const Vector3& pt)
{
    if (m_spNode.operator NiNode*() != 0)
    {
        ((class NiAVObject*)(void*)(m_spNode.operator->()))->SetTranslate(*(class NiPoint3 const*)&static_cast<struct Unk_NiPoint3 const&>(pt));
        ((NiAVObject*)m_spNode.operator->())->Update((float)((class CMainSystem*)(class Unk_Clock*)(reinterpret_cast<Unk_Clock*>(TSingleton<CMainSystem>::GetInstance())))->FUN_141473280(), false);
    }
}

// @0x141273630
void CExpEffectInfo::SetVisible(int nHide)
{
    ((NiAVObject*)m_spNode.operator->())->SetAppCulled(nHide == 0);
}

// @0x141273680
void CExpEffectInfo::Finish()
{
    Unk_ExpActor* pPlayer = (Unk_ExpActor*)reinterpret_cast<Unk_AttendAvatarMgr*>(WorldService::GetInstance())->FUN_141bd0cc0();
    if (pPlayer == 0)
        return;
    float fRadius = DAT_1439f7344 * ((class GameObject*)(class Unk_ExpActor*)(pPlayer))->FUN_14123c260();
    Vector3 ptCur = *(const Vector3*)&((NiAVObject*)m_spNode.operator->())->GetTranslate();
    NiPoint3 ptHit;
    if (!FUN_14147aa60(reinterpret_cast<const efd::Point3&>(ptCur),
                       reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(ptCur.FUN_140965c40(m_ptTarget))),
                       reinterpret_cast<const efd::Point3&>(m_ptTarget), fRadius, &ptHit))
        ptHit = reinterpret_cast<const efd::Point3&>(ptCur);
    ((class PCBase*)(class Unk_ExpActor*)(pPlayer))->AddColorBoost(DAT_1439f734c, DAT_1439f7350, DAT_1439f7354);
    SetPosition(reinterpret_cast<const Vector3&>(ptHit));
    StopEffect();
    NoticeMessage kRequest;   // C3: was Unk_ExpTarget
    ((Unk_ExpTarget&)(kRequest)).m_strName = TSingleton<CommonResource>::GetInstance()->m_strEffectGetExpEnd;
    ((Unk_ExpTarget&)(kRequest)).m_nOwnerId = 1;
    kRequest.SetActor(((class GameObject*)(class Unk_ExpActor*)(pPlayer))->FUN_14123c580());
    TSingleton<CEffectService>::GetInstance()->FUN_1411a4a00(*reinterpret_cast<Unk_EffectTarget*>(&((Unk_ExpTarget&)(kRequest))));
    m_nState = 1;
}

// @0x141273890
void CExpEffectInfo::GetTargetPos(Unk_ExpActor* pActor, Vector3* pOut)
{
    if (pActor == 0)
        return;
    NiAVObject* pDummy = reinterpret_cast<PCBase*>(pActor)->FUN_141675150(s_strEffDummy);
    if (pDummy != 0)
    {
        *reinterpret_cast<efd::Point3*>(pOut) = static_cast<const efd::Point3&>(pDummy->GetWorldTranslate());
    }
    else
    {
        *pOut = pActor->GetPosition();
    }
}

// ---- CGetExp ----

// @0x141273920
CGetExp::CGetExp()
    : m_list(10), m_bEnabled(1)
{
}

// @0x141273980
CGetExp::~CGetExp()
{
    m_list.RemoveAll();
}

// @0x1412739d0
void CGetExp::Update(float fElapsed)
{
    if (m_list.IsEmpty())
        return;
    ATL::CAtlArray<POSITION> aDone;
    POSITION pos;
    for (pos = m_list.GetHeadPosition(); pos != 0; m_list.GetNext(pos))
    {
        CExpEffectInfo* pInfo = m_list.GetAt(pos).get();
        if (pInfo != 0)
        {
            if (pInfo->GetState() != 0)
                aDone.Add(pos);
            else
                pInfo->Update(fElapsed);
        }
    }
    if (aDone.IsEmpty())
        return;
    size_t nCount = aDone.GetCount();
    for (size_t i = 0; i < nCount; i++)
        m_list.RemoveAt(aDone[i]);
}

// @0x141273b40
int CGetExp::FUN_141273b40()
{
    return 1;
}

// @0x141273b60
void CGetExp::AddEffect(int nObjectId, void* pOwner)
{
    if (nObjectId == 0 || pOwner == 0)
        return;
    if (m_bEnabled == 0)
        return;
    MS2Ptr<CExpEffectInfo> spInfo(new CExpEffectInfo);
    if (spInfo.get() != 0)
    {
        spInfo->Create(nObjectId, pOwner);
        m_list.AddTail(spInfo);
    }
}

// @0x141273c40
void CGetExp::SetVisible(int nHide)
{
    if (m_list.IsEmpty())
        return;
    ATL::CAtlArray<POSITION> aUnused;
    POSITION pos;
    for (pos = m_list.GetHeadPosition(); pos != 0; m_list.GetNext(pos))
    {
        CExpEffectInfo* pInfo = m_list.GetAt(pos).get();
        if (pInfo != 0)
            pInfo->SetVisible(nHide);
    }
}

// ---- class-kind tests on a world object (instantiations of one inline helper) ----

// @0x141274a30
int FUN_141274a30(Unk_ExpActor* p)
{
    return p != 0 && efd::ClassInfo::IsKindOf((const efd::ClassInfo*)(p ? p->GetClassInfo() : 0), 0x6200013);
}

// @0x141274aa0
int FUN_141274aa0(Unk_ExpActor* p)
{
    return p != 0 && efd::ClassInfo::IsKindOf((const efd::ClassInfo*)(p ? p->GetClassInfo() : 0), 0x6200028);
}

// @0x141274b10
int FUN_141274b10(Unk_ExpActor* p)
{
    return p != 0 && efd::ClassInfo::IsKindOf((const efd::ClassInfo*)(p ? p->GetClassInfo() : 0), 0x6200003);
}

// @0x141274b80
int FUN_141274b80(Unk_ExpActor* p)
{
    return p != 0 && efd::ClassInfo::IsKindOf((const efd::ClassInfo*)(p ? p->GetClassInfo() : 0), 0x6200011);
}

// @0x141274420
template<> efd::Point3* Common::Constants::Value<efd::Point3>::Get()
{
    if (!m_defined)
        Error("constants is not set");
    return &m_value;
}

// @0x141273d00
Vector3 Unk_ConfigPoint::FUN_141273d00() const
{
    return reinterpret_cast<const Vector3&>(*reinterpret_cast<Common::Constants::Value<efd::Point3>*>(const_cast<Unk_ConfigPoint*>(this))->Get());
}

MS2_EMIT_CRT_MEMMOVE_S();
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cae6c0-0x142cae800 .text$yd

// Full-executable aliases for existing experience effect methods.
// MS2-PIN: ?Update@CGetExp@@QEAAXM@Z 0x1412739d0
// MS2-PIN: ?FUN_1412739d0@CGetExp@@QEAAXM@Z 0x1412739d0
// MS2-PIN: ?AddEffect@CGetExp@@QEAAXHPEAX@Z 0x141273b60
// MS2-PIN: ?FUN_141273b60@CGetExp@@QEAAXH_J@Z 0x141273b60
