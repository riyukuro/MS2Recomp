// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). See skillcollisionmanager.h.
// MS2-UNIT: ?\skillcollisionmanager.cpp
// MS2-RANGE: 0x141754490-0x141758d70 .text$mn
// MS2-PIN: ??_G?$TSingleton@VCSkillCollisionManager@@@@UEAAPEAXI@Z 0x1417563f0
// MS2-PIN: ?Clone@CAtlStringMgr@ATL@@UEAAPEAUIAtlStringMgr@2@XZ 0x14103c770
// MS2-PIN: ?ms2_Identity@@YAPEAXPEAX@Z 0x141758c40
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?AssignRaw@?$MS2Ptr@VCBaseCollision@@@@QEAAAEAV1@PEAVCBaseCollision@@@Z 0x141756380 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\skillcollisionmanager.cpp"
#include "ms2/placeholder/ms2stdafx.h"

#include "skillcollisionmanager.h"

#include "ms2/client/ms2/frustumcollision.h"
#include "ms2/placeholder/nipoint3.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/commonfiles/skilloverlapcompare.h"
#include "ms2/client/ms2/worldservice.h"

// ---- unit-local placeholders ----

// The shape description of a skill attribute: kind (1 box, 2 cylinder, 3 frustum, 4 hole cylinder), four extents and
// the offset of the shape's centre.
class Unk_ColInfo
{
public:
    int m_nShape;                       // +0x00
    int m_pad_04[3];
    float m_f10;                        // +0x10
    float m_f14;                        // +0x14
    float m_f18;                        // +0x18
    float m_f1c;                        // +0x1c
    Vector3 m_ptOffset;         // +0x20
};
MS2_CHECK_OFFSET(Unk_ColInfo, m_ptOffset, 0x20);

class Unk_ColCfg { public: char m_pad[0x1a0]; int m_n1a0; };

// A skill source: its shape description by (level, index), its id / level.
class Unk_SkillSrc : public SkillLevelData
{
public:
    Unk_ColInfo* FUN_1408040d0(int nLevel, int nIndex);
    Unk_ColCfg* FUN_140803f60(int nLevel, int nIndex);
};

// The club skill attribute: embeds a shape description at +0x340.
class Unk_ClubSkillAttr : public CPtred
{
public:
    char m_pad_18[0x340 - 0x18];
    Unk_ColInfo m_col;
};
MS2_CHECK_OFFSET(Unk_ClubSkillAttr, m_col, 0x340);

struct Unk_SkPoint { float x, y, z; };
struct Unk_NiPt3 { float x, y, z; Unk_NiPt3(const void* efdPoint); };      // 0x14027dcf0

// Shapes whose classes live in unrecovered units: only the constructor and the touched fields.
class CBoxCollision : public CBaseCollision
{
public:
    CBoxCollision();                                    // 0x140ada4c0
    virtual void vfunc_5();
    virtual float vfunc_6();
    Vector3 m_ptBox;                            // +0x78
    char m_pad_84[0x150 - 0x84];
};
MS2_CHECK_SIZE(CBoxCollision, 0x150);

class CCylinderCollision : public CBaseCollision
{
public:
    CCylinderCollision();                               // 0x141083230
    virtual void vfunc_5();
    virtual float vfunc_6();
    char m_pad_78[0xb0 - 0x78];
    float m_fRadius;                                    // +0xb0
    char m_pad_b4[0xc0 - 0xb4];
    float m_fHeight;                                    // +0xc0
    char m_pad_c4[0xc8 - 0xc4];
};
MS2_CHECK_SIZE(CCylinderCollision, 0xc8);

class CHoleCylinderCollision : public CBaseCollision
{
public:
    CHoleCylinderCollision();                           // 0x140d03650
    virtual void vfunc_5();
    virtual float vfunc_6();
    char m_pad_78[0xd0 - 0x78];
    float m_fInner;                                    // +0xd0
    float m_fOuter;                                    // +0xd4
    char m_pad_d8[0xe4 - 0xd8];
    float m_fHeight;                                    // +0xe4
};
MS2_CHECK_SIZE(CHoleCylinderCollision, 0xe8);

class Unk_EmoPlayer;
class Unk_1403ed2d0;

// ---- unrecovered neighbours ----
extern unsigned DAT_1439f862c;          // display time of a shape (ms)
extern unsigned char DAT_143ae95e0;
extern unsigned char DAT_143ae95e1;
unsigned FUN_140869420();               // tick count
__int64 FUN_14028d0e0();                // next shape handle
Unk_EmoPlayer* FUN_14096e110(PCBase* p);
PCBase* FUN_140974230(PCBase* p);
void* FUN_141468360(PCBase* p);

typedef CSkillCollisionManager::CollisionPtr CollisionPtr;

// ---- CSkillCollisionManager ----

// @0x141754490
CSkillCollisionManager::CSkillCollisionManager() : m_mapCache(10), m_mapActive(17, 0.75f, 0.25f, 2.25f, 10)
{
}

// @0x141754520
CSkillCollisionManager::~CSkillCollisionManager()
{
    m_mapCache.RemoveAll();
}

// @0x141754580
CollisionPtr CSkillCollisionManager::GetCached(Unk_SkillSrc* pSrc, int nLevel, int nIndex, void* pUnused,
    float fZOffset)
{
    if (pSrc == 0)
        return CollisionPtr(0);
    Unk_ColInfo* pInfo = pSrc->FUN_1408040d0(nLevel, nIndex);
    if (pInfo == 0)
        return CollisionPtr(0);
    CollisionPtr spShape(0);
    CStringA strKey;
    strKey.Format("%x,%d,%d,%d,%d", pSrc, pSrc->FUN_140803dc0(), pSrc->GetLevel(), nLevel, nIndex);
    const int& nShape = pInfo->m_nShape;
    if (m_mapCache.Lookup(strKey, spShape))
    {
        if (spShape->m_nShape == 3 && nShape == 3)
        {
            CFrustumCollision* pF = static_cast<CFrustumCollision*>(spShape.get());
            pF->m_fNearHalfWidth = pInfo->m_f18 * 0.5f;
            pF->m_fHeight = pInfo->m_f14 * 0.5f;
            pF->m_fFarHalfWidth = pInfo->m_f1c * 0.5f;
            pF->m_fDepth = pInfo->m_f10 + fZOffset;
            spShape->vfunc_4();
            return spShape;
        }
        else if (spShape->m_nShape == 1 && nShape == 1)
        {
            CBoxCollision* pB = static_cast<CBoxCollision*>(spShape.get());
            pB->m_ptBox = Vector3(pInfo->m_f18, pInfo->m_f10 + fZOffset, pInfo->m_f14);
            spShape->vfunc_4();
            return spShape;
        }
        else if (spShape->m_nShape == 2 && nShape == 2)
        {
            CCylinderCollision* pC = static_cast<CCylinderCollision*>(spShape.get());
            pC->m_fRadius = pInfo->m_f10;
            pC->m_fHeight = pInfo->m_f14;
            spShape->vfunc_4();
            return spShape;
        }
        else if (spShape->m_nShape == 4 && nShape == 4)
        {
            CHoleCylinderCollision* pH = static_cast<CHoleCylinderCollision*>(spShape.get());
            pH->m_fInner = pInfo->m_f18;
            pH->m_fOuter = pInfo->m_f1c;
            pH->m_fHeight = pInfo->m_f14;
            spShape->vfunc_4();
            return spShape;
        }
        else
            m_mapCache.RemoveKey(strKey);
    }
    if (nShape == 3)
    {
        CFrustumCollision* pF = new CFrustumCollision();
        pF->m_fNearHalfWidth = pInfo->m_f18 * 0.5f;
        pF->m_fHeight = pInfo->m_f14 * 0.5f;
        pF->m_fFarHalfWidth = pInfo->m_f1c * 0.5f;
        pF->m_fDepth = pInfo->m_f10 + fZOffset;
        m_mapCache.SetAt(strKey, pF);
        spShape.AssignRaw(pF);
    }
    else if (nShape == 1)
    {
        CBoxCollision* pB = new CBoxCollision();
        pB->m_ptBox = Vector3(pInfo->m_f18, pInfo->m_f10 + fZOffset, pInfo->m_f14);
        m_mapCache.SetAt(strKey, pB);
        spShape.AssignRaw(pB);
    }
    else if (nShape == 2)
    {
        CCylinderCollision* pC = new CCylinderCollision();
        pC->m_fRadius = pInfo->m_f10;
        pC->m_fHeight = pInfo->m_f14;
        m_mapCache.SetAt(strKey, pC);
        spShape.AssignRaw(pC);
    }
    else if (nShape == 4)
    {
        CHoleCylinderCollision* pH = new CHoleCylinderCollision();
        pH->m_fInner = pInfo->m_f18;
        pH->m_fOuter = pInfo->m_f1c;
        pH->m_fHeight = pInfo->m_f14;
        m_mapCache.SetAt(strKey, pH);
        spShape.AssignRaw(pH);
    }
    if (spShape.get() != 0)
    {
        spShape->m_ptSize = pInfo->m_ptOffset;
        spShape->vfunc_4();
        Unk_ColCfg* pCfg = pSrc->FUN_140803f60(nLevel, nIndex);
        spShape->m_n18 = pCfg->m_n1a0;
    }
    return spShape;
}

// @0x141755010
void CSkillCollisionManager::Tick()
{
    ATL::CAtlList<__int64> aExpired(10);
    for (POSITION pos = m_mapActive.GetStartPosition(); pos != 0; m_mapActive.GetNext(pos))
    {
        CollisionPtr spShape = m_mapActive.GetValueAt(pos);
        spShape->vfunc_1();
        if (spShape->m_n58 != 0)
        {
            if (spShape->m_n58 + DAT_1439f862c < FUN_140869420())
                aExpired.AddTail(m_mapActive.GetKeyAt(pos));
        }
    }
    for (POSITION posExpired = aExpired.GetHeadPosition(); posExpired != 0; aExpired.GetNext(posExpired))
    {
        Remove(aExpired.GetAt(posExpired));
    }
    if (DAT_143ae95e0 != 0 || DAT_143ae95e1 != 0)
        reinterpret_cast<WorldService*>(reinterpret_cast<Unk_1403ed2d0*>(WorldService::GetInstance()))->FUN_141bc49c0();
}

// @0x1417551b0
CollisionPtr CSkillCollisionManager::Create(Unk_SkillSrc* pSrc, int nLevel, int nIndex, void* pUnused,
    float fZOffset)
{
    if (pSrc == 0)
        return CollisionPtr(0);
    Unk_ColInfo* pInfo = pSrc->FUN_1408040d0(nLevel, nIndex);
    if (pInfo == 0)
        return CollisionPtr(0);
    CollisionPtr spShape(0);
    const int& nShape = pInfo->m_nShape;
    if (nShape == 3)
    {
        CFrustumCollision* pF = new CFrustumCollision();
        pF->m_fNearHalfWidth = pInfo->m_f18 * 0.5f;
        pF->m_fHeight = pInfo->m_f14 * 0.5f;
        pF->m_fFarHalfWidth = pInfo->m_f1c * 0.5f;
        pF->m_fDepth = pInfo->m_f10 + fZOffset;
        spShape.AssignRaw(pF);
    }
    else if (nShape == 1)
    {
        CBoxCollision* pB = new CBoxCollision();
        pB->m_ptBox = Vector3(pInfo->m_f18, pInfo->m_f10 + fZOffset, pInfo->m_f14);
        spShape.AssignRaw(pB);
    }
    else if (nShape == 2)
    {
        CCylinderCollision* pC = new CCylinderCollision();
        pC->m_fRadius = pInfo->m_f10;
        pC->m_fHeight = pInfo->m_f14;
        spShape.AssignRaw(pC);
    }
    else if (nShape == 4)
    {
        CHoleCylinderCollision* pH = new CHoleCylinderCollision();
        pH->m_fInner = pInfo->m_f18;
        pH->m_fOuter = pInfo->m_f1c;
        pH->m_fHeight = pInfo->m_f14;
        spShape.AssignRaw(pH);
    }
    if (spShape.get() != 0)
    {
        spShape->m_ptSize = pInfo->m_ptOffset;
        spShape->vfunc_4();
        Unk_ColCfg* pCfg = pSrc->FUN_140803f60(nLevel, nIndex);
        spShape->m_n18 = pCfg->m_n1a0;
    }
    return spShape;
}

// @0x141755670
CollisionPtr CSkillCollisionManager::CreateFromInfo(Unk_ColInfo* pInfo, float fZOffset)
{
    if (pInfo == 0)
        return CollisionPtr(0);
    CollisionPtr spShape(0);
    const int& nShape = pInfo->m_nShape;
    if (nShape == 3)
    {
        CFrustumCollision* pF = new CFrustumCollision();
        pF->m_fNearHalfWidth = pInfo->m_f18 * 0.5f;
        pF->m_fHeight = pInfo->m_f14 * 0.5f;
        pF->m_fFarHalfWidth = pInfo->m_f1c * 0.5f;
        pF->m_fDepth = pInfo->m_f10 + fZOffset;
        spShape.AssignRaw(pF);
    }
    else if (nShape == 1)
    {
        CBoxCollision* pB = new CBoxCollision();
        pB->m_ptBox = Vector3(pInfo->m_f18, pInfo->m_f10 + fZOffset, pInfo->m_f14);
        spShape.AssignRaw(pB);
    }
    else if (nShape == 2)
    {
        CCylinderCollision* pC = new CCylinderCollision();
        pC->m_fRadius = pInfo->m_f10;
        pC->m_fHeight = pInfo->m_f14;
        spShape.AssignRaw(pC);
    }
    else if (nShape == 4)
    {
        CHoleCylinderCollision* pH = new CHoleCylinderCollision();
        pH->m_fInner = pInfo->m_f18;
        pH->m_fOuter = pInfo->m_f1c;
        pH->m_fHeight = pInfo->m_f14;
        spShape.AssignRaw(pH);
    }
    if (spShape.get() != 0)
    {
        spShape->m_ptSize = pInfo->m_ptOffset;
        spShape->vfunc_4();
    }
    return spShape;
}

// @0x141755ac0
__int64 CSkillCollisionManager::Add(CollisionPtr spShape)
{
    if (spShape == 0)
        return 0;
    __int64 nHandle = FUN_14028d0e0();
    m_mapActive.SetAt(nHandle, spShape);
    return nHandle;
}

// @0x141755b50
void CSkillCollisionManager::Remove(__int64 nHandle)
{
    CollisionPtr spShape(0);
    if (m_mapActive.Lookup(nHandle, spShape))
        m_mapActive.RemoveKey(nHandle);
}

// @0x141755bd0
void CSkillCollisionManager::Touch(__int64 nHandle)
{
    CollisionPtr spShape(0);
    if (m_mapActive.Lookup(nHandle, spShape))
        spShape->m_n58 = FUN_140869420();
}

// @0x141755c50
CollisionPtr CSkillCollisionManager::Get(__int64 nHandle)
{
    CollisionPtr spShape(0);
    m_mapActive.Lookup(nHandle, spShape);
    return spShape;
}

// @0x141755cd0
// MS2-FUNCTIONAL: temporary Unk_NiPt3 copies are laid out differently
void CSkillCollisionManager::Show(PCBase* pActor, MS2Ptr<Unk_ClubSkillAttr> spSkill, const Unk_SkPoint* pPos,
    const Unk_SkPoint* pDir)
{
    if (FUN_14096e110(pActor) == 0)
    {
        if ((FUN_140974230(pActor) != 0 || FUN_141468360(pActor) != 0) && DAT_143ae95e0 == 0)
            return;
    }
    else if (DAT_143ae95e1 == 0)
    {
        return;
    }
    Unk_ColInfo* pInfo = &spSkill->m_col;
    if (pInfo == 0)
        return;
    CollisionPtr spShape = TSingleton<CSkillCollisionManager>::GetInstance()->CreateFromInfo(pInfo, 0.0f);
    if (!(spShape == 0))
    {
        CBaseCollision* pShape = spShape.get();
        Unk_NiPt3 kDir(pDir);
        Vector3 ptDir = *(Vector3*)&kDir;
        Unk_NiPt3 kPos(pPos);
        Vector3 ptPos = *(Vector3*)&kPos;
        pShape->vfunc_3(ptPos, ptDir, 1.0f);
        spShape->m_n58 = FUN_140869420();
        TSingleton<CSkillCollisionManager>::GetInstance()->Add(spShape);
    }
}

// An unreferenced identity function (11 bytes, `mov [rsp+8], rcx; mov rax, [rsp+8]; ret`) sits in front of the CRT
// memmove_s copy (probably an ATL / std `this`-returning helper); kept alive through a constant pointer like memmove_s.
static void* ms2_Identity(void* p) { return p; }
__declspec(selectany) extern void* (* const ms2_pfnIdentity)(void*) = &ms2_Identity;

MS2_EMIT_CRT_MEMMOVE_S();
