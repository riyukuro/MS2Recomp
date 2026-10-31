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
static CString s_strSortTypeNames2[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};   // @0x1400eb910
static CString s_strSkill2 = "skill";                // @0x1400eb9d0
static CString s_strStun2 = "stun";                  // @0x1400eba00
static Unk_1402a9d70 s_unk1402a9d70_2(17, 0.75f, 0.25f, 2.25f, 10);   // @0x1400eba30

// ---- exe data ----
extern Vector3 DAT_143b01a60;       // the zero point
extern Unk_EfdMatrix3 DAT_143a09600;        // the identity matrix
extern Vector3 DAT_143a08cf8;       // axis a (the up axis)
extern Vector3 DAT_143a08cd8;       // axis b
extern float DAT_1439f733c;                 // minimum travel distance
extern float DAT_1439f7340;                 // travel distance scale
extern float DAT_1439f7344;                 // arrival radius scale
extern float DAT_1439f7348;                 // elapsed decay
extern float DAT_1439f734c;                 // player flash r
extern float DAT_1439f7350;                 // player flash g
extern float DAT_1439f7354;                 // player flash b

// ---- unit-local views of exe objects ----

// 3-float point whose default ctor is the efd::Point3 one (0x1405522f0).
struct Unk_GVec3 : public Vector3
{
    Unk_GVec3();                                                // 0x1405522f0
    Unk_GVec3& operator=(const Unk_NiPoint3& pt);              // 0x14097faa0
};

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
float FUN_14123c260(Unk_ExpActor* p);                               // radius scale
int FUN_14123c580(Unk_ExpActor* p);                                 // object id
int FUN_14123cec0(Unk_ExpActor* p);                                 // player seed
void FUN_141673f70(Unk_ExpActor* p, float fR, float fG, float fB);  // flash the object
NiAVObject* FUN_141675150(Unk_ExpActor* p, const CString& strName); // find a named dummy node
const Vector3& FUN_140947900(NiAVObject* pNode);            // node translate
int FUN_14028d0e0();                                                // seed counter
bool FUN_14087ddc0(void* pClassInfo, int nKind);                    // efd::ClassInfo::IsKindOf

// The world service (0x1403ed2d0) and its object lookups.
class Unk_AttendAvatarMgr : public WorldService
{
public:
    Unk_ExpActor* FUN_141bd1200(int nObjectId);                     // an object by id
    int FUN_141bd1a10(Unk_ExpActor* p);                             // object -> owner id
};

// The effect manager (0x1403ed280).
struct Unk_ExpTarget;
class Unk_1403ed280
{
public:
    void* FUN_1411a6b10();                                          // the effect root NiNode
    int FUN_1411a49c0(Unk_ExpTarget* pRequest);                     // spawn, returns the handle
    void FUN_1411a4a00(Unk_ExpTarget* pRequest);                    // play once
    void FUN_1411a6060(int nHandle);                                // release
};

// Effect request (0x70 bytes; ctor 0x140a52ef0, dtor 0x1405a89e0).
struct Unk_ExpTarget
{
    Unk_ExpTarget();                                                // 0x140a52ef0
    ~Unk_ExpTarget();                                               // 0x1405a89e0
    void FUN_140a53190(int nObjectId);                              // set the object
    CString m_strName;                                              // +0x00
    int m_nOwnerId;                                                 // +0x08
    int m_pad_0c;
    efd::SmartPointer<NiAVObject> m_spNode;                         // +0x10 (0x1409fabf0)
    __int64 m_pad_18, m_pad_20, m_pad_28, m_pad_30, m_pad_38, m_pad_40, m_pad_48, m_pad_50, m_pad_58, m_pad_60, m_pad_68;
};
MS2_CHECK_SIZE(Unk_ExpTarget, 0x70);

// Three-seed random generator (ctor 0x140768290, next float 0x1407680d0, dtor 0x1401cdc30).
class Unk_ExpRandom
{
public:
    Unk_ExpRandom(int nA, int nB, int nC);                          // 0x140768290
    ~Unk_ExpRandom();                                               // 0x1401cdc30
    float FUN_1407680d0();                                          // next value
private:
    void* m_unk0; void* m_unk1; void* m_unk2; void* m_unk3; void* m_unk4; void* m_unk5; void* m_unk6; void* m_unk7;
};

// The client constants (0x1401d3200) and the singleton holding the effect names (0x1401d31f0).
struct Unk_ClientConfig;
class Unk_ConfigFloat { public: float FUN_1402bac70(); };                           // Value<float>::get
class Unk_ConfigPoint
{
public:
    Vector3 FUN_141273d00() const;                          // copy of the value (0x141273d00)
    const Vector3& FUN_141274420() const;                   // the value, "constants is not set" when unset
    virtual void vfunc_0(); virtual void vfunc_1();
    bool m_bInit; char m_flag9, m_flagA, m_flagB; unsigned m_unkC;
    char m_pad_10[0x40];
    Vector3 m_value;                                        // +0x50
};
class Unk_ConfigString { public: CString* FUN_140298f80(); };      // Value<CString>::get
Unk_ClientConfig* FUN_1401d3200();
struct Unk_NameHolder { };
Unk_NameHolder* FUN_1401d31f0();
void FUN_1402b7560(void* pObj, const char* pszMessage);

// Unit helpers declared elsewhere.
void FUN_140194470(void* pDst, void* pSrc);
const float* FUN_140805fc0(const float* pA, const float* pB);                        // min / max of two floats
Vector3 FUN_141b71390(Vector3 a, Vector3 b, Vector3 c, float t);   // curve point
bool FUN_14147aa60(const Unk_NiPoint3& kOrigin, const Unk_NiPoint3& kDir, const Unk_NiPoint3& kCenter,
                   float fRadius, Unk_GVec3* pHit);                                  // ray / sphere hit
void FUN_140981070(void* pNode, const Unk_NiPoint3& kPoint);                                 // SetTranslate
void FUN_140ddcca0(void* pNode, const void* pMatrix);                                // SetRotate
void FUN_140a0b2a0(NiAVObject* pNode);                                               // detach from the parent
class Unk_Clock;
double FUN_141473280(Unk_Clock* pClock);

// ---- CExpEffectInfo ----

// @0x141272630
CExpEffectInfo::CExpEffectInfo()
    : m_pOwner(0), m_n20(0), m_hEffect(0), m_spNode((void*)0), m_ptPos(DAT_143b01a60), m_fElapsed(0),
      m_rot(DAT_143a09600), m_fProgress(0), m_fTotal(0), m_ptTarget(DAT_143b01a60), m_ptSource(DAT_143b01a60),
      m_nState(0)
{
    InitConstants();
}

// @0x141272760
CExpEffectInfo::~CExpEffectInfo()
{
    StopEffect();
    FUN_140a0b2a0((NiAVObject*)FUN_1409475d0(&m_spNode));
}

// @0x1412727d0
Vector3 CExpEffectInfo::GetAxis0() const
{
    Vector3 pt;
    m_rot.FUN_140a01190(0, pt);
    return pt;
}

// @0x141272830
Vector3 CExpEffectInfo::GetAxis1() const
{
    Vector3 pt;
    m_rot.FUN_140a01190(1, pt);
    return pt;
}

// @0x141272890
Vector3 CExpEffectInfo::GetAxis2() const
{
    Vector3 pt;
    m_rot.FUN_140a01190(2, pt);
    return pt;
}

// @0x1412728f0
void CExpEffectInfo::UpdateOrientation()
{
    Vector3 vDir = m_ptTarget.FUN_140965c40(m_ptSource);
    vDir.FUN_140968990();
    Unk_NiMatrix3 kMat;
    Vector3 vNeg = vDir.FUN_1409f7960();
    Vector3 vUp = DAT_143b01a60;
    if (vNeg.FUN_140552690(DAT_143a08cf8))
    {
        vUp = DAT_143a08cd8;
    }
    else if (vNeg.FUN_140552690(DAT_143a08cf8.FUN_1409f7960()))
    {
        vUp = DAT_143a08cd8.FUN_1409f7960();
    }
    else
    {
        vUp = vNeg.FUN_14109adc0(DAT_143a08cf8);
    }
    Vector3 vSide = vUp.FUN_14109adc0(vNeg);
    kMat.FUN_14109aa30(0, vUp);
    kMat.FUN_14109aa30(1, vNeg);
    kMat.FUN_14109aa30(2, vSide);
    m_rot = kMat;
    FUN_140ddcca0(FUN_1409475f0(&m_spNode), &kMat);
    ((NiAVObject*)FUN_1409475f0(&m_spNode))->Update((float)FUN_141473280(reinterpret_cast<Unk_Clock*>(TSingleton<CMainSystem>::GetInstance())), false);
}

static int s_nConstInit = 0;                                        // @0x143ad6000

#ifndef MS2_HOOK_DLL
// @0x141272b10
void CExpEffectInfo::InitConstants()
{
    if (s_nConstInit != 0)
        return;
    DAT_1439f733c = reinterpret_cast<Unk_ConfigFloat*>((char*)FUN_1401d3200() + 0x21b8)->FUN_1402bac70();
    DAT_1439f7340 = reinterpret_cast<Unk_ConfigFloat*>((char*)FUN_1401d3200() + 0x2210)->FUN_1402bac70();
    DAT_1439f7348 = reinterpret_cast<Unk_ConfigFloat*>((char*)FUN_1401d3200() + 0x2268)->FUN_1402bac70();
    DAT_1439f7344 = reinterpret_cast<Unk_ConfigFloat*>((char*)FUN_1401d3200() + 0x22c0)->FUN_1402bac70();
    Vector3 kMin = reinterpret_cast<Unk_ConfigPoint*>((char*)FUN_1401d3200() + 0x2318)->FUN_141273d00();
    s_ptSpreadMin = kMin;
    Vector3 kMax = reinterpret_cast<Unk_ConfigPoint*>((char*)FUN_1401d3200() + 0x2380)->FUN_141273d00();
    s_ptSpreadMax = kMax;
    s_strEffDummy = *reinterpret_cast<Unk_ConfigString*>((char*)FUN_1401d3200() + 0x23e8)->FUN_140298f80();
    s_nConstInit = 1;
}
#endif

// @0x141272c20
void CExpEffectInfo::StopEffect()
{
    if (m_hEffect > 0)
    {
        reinterpret_cast<Unk_1403ed280*>(TSingleton<CEffectService>::GetInstance())->FUN_1411a6060(m_hEffect);
        m_hEffect = 0;
    }
}

// @0x141272c60
void CExpEffectInfo::Update(float fElapsed)
{
    if (m_nState != 0 || FUN_1409475d0(&m_spNode) == 0)
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
            Vector3 ptNew = FUN_141b71390(m_ptSource, m_ptPos, m_ptTarget, fT);
            SetPosition(ptNew);
        }
    }
}

// @0x141272f20
int CExpEffectInfo::Create(int nObjectId, void* pOwner)
{
    Unk_ExpActor* pPlayer = (Unk_ExpActor*)reinterpret_cast<Unk_AttendAvatarMgr*>(WorldService::GetInstance())->FUN_141bd0cc0();
    if (pPlayer == 0)
        return 0;
    Unk_ExpActor* pObj = reinterpret_cast<Unk_AttendAvatarMgr*>(WorldService::GetInstance())->FUN_141bd1200(nObjectId);
    if (pObj == 0)
        return 0;
    FUN_1409f76f0(&m_spNode, new (efd::MemHint(efd::MemHint::NONE)) NiNode(0));
    if (FUN_1409475d0(&m_spNode) == 0)
        return 0;
    m_pOwner = pOwner;
    m_fElapsed = 0;
    m_ptSource = pObj->GetPosition();
    GetTargetPos(pPlayer, &m_ptTarget);
    Vector3 vDir = m_ptTarget.FUN_140965c40(m_ptSource);
    float fLen = vDir.FUN_140968990();
    float fScaled = fLen * DAT_1439f7340;
    m_fTotal = *FUN_140805fc0(&DAT_1439f733c, &fScaled);
    m_fProgress = fLen / m_fTotal;
    UpdateOrientation();
    int nSeedA = FUN_14028d0e0() + nObjectId;
    int nSeedB = FUN_14123cec0(pPlayer) + nObjectId;
    int nSeedC = nSeedA * nSeedB * nObjectId;
    Unk_ExpRandom kRandom(nSeedA, nSeedB, nSeedC);
    float fRandX = kRandom.FUN_1407680d0();
    float fRandY = kRandom.FUN_1407680d0();
    float fRandZ = kRandom.FUN_1407680d0();
    // [0] = spread min, [1] = spread max, both scaled by the distance
    Vector3 aSpread[2] = { s_ptSpreadMin.FUN_14097fc90(fLen), s_ptSpreadMax.FUN_14097fc90(fLen) };
    aSpread[0].y = aSpread[0].y / m_fTotal;
    aSpread[1].y = aSpread[1].y / m_fTotal;
    Vector3 ptRange = aSpread[1].FUN_140965c40(aSpread[0]);
    Vector3 ptOffset(aSpread[0].x + ptRange.x * fRandX, aSpread[0].y + ptRange.y * fRandY, aSpread[0].z + ptRange.z * fRandZ);
    FUN_140194470(&m_ptPos, (void*)&static_cast<const Vector3&>(
                                m_ptSource.FUN_14097fd50(vDir.FUN_14097fc90(ptOffset.y).FUN_14097fc90(fLen))
                                    .FUN_14097fd50(GetAxis2().FUN_14097fc90(ptOffset.z))
                                    .FUN_14097fd50(GetAxis0().FUN_14097fc90(ptOffset.x))));
    SetPosition(m_ptSource);
    NiNode* pRoot = (NiNode*)reinterpret_cast<Unk_1403ed280*>(TSingleton<CEffectService>::GetInstance())->FUN_1411a6b10();
    pRoot->AttachChild((NiAVObject*)FUN_1409475d0(&m_spNode), true);
    Unk_ExpTarget kRequest;
    kRequest.m_spNode = (NiAVObject*)FUN_1409475d0(&m_spNode);
    kRequest.m_strName = *reinterpret_cast<CString*>((char*)FUN_1401d31f0() + 0x338);
    kRequest.m_nOwnerId = reinterpret_cast<Unk_AttendAvatarMgr*>(WorldService::GetInstance())->FUN_141bd1a10(pObj);
    kRequest.FUN_140a53190(FUN_14123c580(pObj));
    m_hEffect = reinterpret_cast<Unk_1403ed280*>(TSingleton<CEffectService>::GetInstance())->FUN_1411a49c0(&kRequest);
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
    if (FUN_1409475d0(&m_spNode) != 0)
    {
        FUN_140981070(FUN_1409475f0(&m_spNode), pt);
        ((NiAVObject*)FUN_1409475f0(&m_spNode))->Update((float)FUN_141473280(reinterpret_cast<Unk_Clock*>(TSingleton<CMainSystem>::GetInstance())), false);
    }
}

// @0x141273630
void CExpEffectInfo::SetVisible(int nHide)
{
    ((NiAVObject*)FUN_1409475f0(&m_spNode))->SetAppCulled(nHide == 0);
}

// @0x141273680
void CExpEffectInfo::Finish()
{
    Unk_ExpActor* pPlayer = (Unk_ExpActor*)reinterpret_cast<Unk_AttendAvatarMgr*>(WorldService::GetInstance())->FUN_141bd0cc0();
    if (pPlayer == 0)
        return;
    float fRadius = DAT_1439f7344 * FUN_14123c260(pPlayer);
    Vector3 ptCur = *(const Vector3*)&((NiAVObject*)FUN_1409475f0(&m_spNode))->GetTranslate();
    Unk_GVec3 ptHit;
    if (!FUN_14147aa60(ptCur, ptCur.FUN_140965c40(m_ptTarget), m_ptTarget, fRadius, &ptHit))
        ptHit = ptCur;
    FUN_141673f70(pPlayer, DAT_1439f734c, DAT_1439f7350, DAT_1439f7354);
    SetPosition(ptHit);
    StopEffect();
    Unk_ExpTarget kRequest;
    kRequest.m_strName = *reinterpret_cast<CString*>((char*)FUN_1401d31f0() + 0x340);
    kRequest.m_nOwnerId = 1;
    kRequest.FUN_140a53190(FUN_14123c580(pPlayer));
    reinterpret_cast<Unk_1403ed280*>(TSingleton<CEffectService>::GetInstance())->FUN_1411a4a00(&kRequest);
    m_nState = 1;
}

// @0x141273890
void CExpEffectInfo::GetTargetPos(Unk_ExpActor* pActor, Vector3* pOut)
{
    if (pActor == 0)
        return;
    NiAVObject* pDummy = FUN_141675150(pActor, s_strEffDummy);
    if (pDummy != 0)
    {
        FUN_140194470(pOut, (void*)&FUN_140947900(pDummy));
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
    return p != 0 && FUN_14087ddc0(p ? p->GetClassInfo() : 0, 0x6200013);
}

// @0x141274aa0
int FUN_141274aa0(Unk_ExpActor* p)
{
    return p != 0 && FUN_14087ddc0(p ? p->GetClassInfo() : 0, 0x6200028);
}

// @0x141274b10
int FUN_141274b10(Unk_ExpActor* p)
{
    return p != 0 && FUN_14087ddc0(p ? p->GetClassInfo() : 0, 0x6200003);
}

// @0x141274b80
int FUN_141274b80(Unk_ExpActor* p)
{
    return p != 0 && FUN_14087ddc0(p ? p->GetClassInfo() : 0, 0x6200011);
}

// @0x141273d00
Vector3 Unk_ConfigPoint::FUN_141273d00() const
{
    return FUN_141274420();
}

// @0x141274420
const Vector3& Unk_ConfigPoint::FUN_141274420() const
{
    if (!m_bInit)
        FUN_1402b7560((void*)this, "constants is not set");
    return m_value;
}

MS2_EMIT_CRT_MEMMOVE_S();
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cae6c0-0x142cae800 .text$yd

// Full-executable aliases for existing experience effect methods.
// MS2-PIN: ?Update@CGetExp@@QEAAXM@Z 0x1412739d0
// MS2-PIN: ?FUN_1412739d0@CGetExp@@QEAAXM@Z 0x1412739d0
// MS2-PIN: ?AddEffect@CGetExp@@QEAAXHPEAX@Z 0x141273b60
// MS2-PIN: ?FUN_141273b60@CGetExp@@QEAAXH_J@Z 0x141273b60
