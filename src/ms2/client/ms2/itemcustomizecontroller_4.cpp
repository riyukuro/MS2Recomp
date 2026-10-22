// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CItemPickingHelper (4th TU of the fused guess unit).
// MS2-UNIT: ?\itemcustomizecontroller.cpp#4
// MS2-RANGE: 0x141418c00-0x141419df0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
// MS2-PIN: ??_GCItemPickingHelper@@UEAAPEAXI@Z 0x141419870
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\itemcustomizecontroller.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "itemcustomizecontroller_1.h"
#include "itempickinghelper.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "hook/ms2hook.h"
#include <efd/MemHint.h>
#include <efd/MemObject.h>
#include <NiPoint2.h>

// ---- out-of-unit callees ----
void FUN_140980460(void* p);            // NiRefObject::IncRefCount
void FUN_1405a93d0(void* p);            // NiRefObject::DecRefCount
void FUN_140159b70(long hr);            // AtlThrow

class NiCamera;
struct Unk_PickXY { float x, y; };      // cursor position
extern Unk_PickXY DAT_143b02320;        // initial value of the cursor position
extern char DAT_143d6eb58;              // NiRTTI of the renderer class
extern char DAT_143afa7d0;              // NiRTTI of the model-part node class

class CMeshUVPicker : public efd::MemObject
{
public:
    CMeshUVPicker();                                                    // 0x14147e6e0
    int FUN_14147e900();                                                // init
    bool FUN_14147ea50(NiAVObject* pMesh, NiCamera* pCam, float x, float y, efd::Point3* pHit, efd::Point3* pNormal,
                       NiPoint2* pUV, unsigned __int64* pTri, CAtlArray<NiRenderObject*>* pSkins);   // pick
    char m_pad[0x98];
};
MS2_CHECK_SIZE(CMeshUVPicker, 0x98);

struct Unk_PickApp { int FUN_141b90e30(float* pX, float* pY); };        // cursor position
Unk_PickApp* FUN_140aadf80();
struct Unk_PickRenderer
{
    bool IsFlag() const;
    char m_pad[0x850];
    bool m_bFlag;                                                       // +0x850
};
void* FUN_140994450();                                                  // NiRenderer::GetRenderer()
void* FUN_1413f9a70();                                                  // camera manager
NiCamera* FUN_1409a8a60(void* pMgr);                                    // active camera
const NiPoint3* FUN_1411b1f60(NiCamera* pCam);                          // camera world position
Unk_PickRenderer* FUN_14098d8d0(char* pRtti, void* pObj);               // checked cast
NiRenderObject* FUN_14098d8d0(char* pRtti, NiAVObject* pObj);
struct Unk_PickGame { void* FUN_141bd0cc0(); };
Unk_PickGame* FUN_1403ed2d0();
struct Unk_PickItemData { bool FUN_14053cfd0() const; };
class CItem : public CPtred { public: Unk_PickItemData* FUN_140527840(); };                         // item -> item data
void* FUN_14123c410(void* pObj);                                        // the game object's entity
void* FUN_141b6efc0(void* pEntity);                                     // entity -> scene root
// Scene-graph walker (56 bytes): ctor 0x14098cb80, dtor 0x14098cf00.
struct Unk_PickSceneIter
{
    Unk_PickSceneIter(void* pRoot);
    ~Unk_PickSceneIter();
    NiAVObject* FUN_14098e0d0(bool bDescend);
    void* m_a[7];
};
const void* FUN_1409a8b90(NiAVObject* pObj);                            // node name
bool FUN_140998dc0(const void* pName, const char* psz);                 // name == psz

void FUN_141419670(void* pObject, CAtlArray<NiRenderObject*>* pOut);

struct Unk_PickPartName : public CString {};   // layout-identical view of a part-name element

// @0x141418c00
CItemPickingHelper::CItemPickingHelper()
    : m_spMesh(0)
    , m_nMode(0)
    , m_spPicker(0)
    , m_nPicked(-1)
    , m_spLast(0)
{
}

// @0x141418cd0
CItemPickingHelper::~CItemPickingHelper()
{
    Reset();
}

// @0x141418d60
int CItemPickingHelper::CreatePicker()
{
    m_spPicker.FUN_1412861e0(new (efd::MemHint(efd::MemHint::NONE)) CMeshUVPicker);
    return m_spPicker.FUN_141286290()->FUN_14147e900();
}

// @0x141418e00
void CItemPickingHelper::ClearTargets()
{
    m_targets.RemoveAll();
}

// @0x141418e30
void CItemPickingHelper::AddTarget(Unk_PickTarget* pTarget)
{
    if (pTarget != 0)
    {
        MS2Ptr<Unk_PickTarget> sp(pTarget);
        m_targets.Add(sp);
    }
}

// @0x141418e90
Unk_PickTarget* CItemPickingHelper::GetPickedTarget()
{
    if (m_nPicked < 0 || m_nPicked >= (int)m_targets.GetCount())
        return 0;
    return m_targets[m_nPicked].get();
}

// @0x141418ef0
int CItemPickingHelper::GetPickedIndex() const
{
    return m_nPicked;
}

// @0x141418f10
int CItemPickingHelper::Pick(efd::Point3* pHit, CAtlArray<CString>& parts)
{
    // the exe calls its own CAtlArray<CString>::operator[] copy here (0x14134b380), not the 0x1401c0cc0 one
    void* pCamMgr = FUN_1413f9a70();
    NiPoint3 camPos = *FUN_1411b1f60(FUN_1409a8a60(pCamMgr));
    float fBest = FLT_MAX;
    m_nPicked = -1;
    for (unsigned i = 0; i < m_targets.GetCount(); i++)
    {
        MS2Ptr<Unk_PickTarget> spTarget(m_targets[i]);
        if (spTarget == 0)
            continue;
        for (unsigned j = 0; j < parts.GetCount(); j++)
        {
            efd::Point3 hit;
            if (PickTarget(spTarget.get(), &((CAtlArray<Unk_PickPartName>&)parts)[j], (NiPoint3*)&hit) != 0)
            {
                float fDist = (*(NiPoint3*)&hit - camPos).Length();
                if (fDist < fBest)
                {
                    fBest = fDist;
                    m_nPicked = i;
                    *pHit = hit;
                    break;
                }
            }
        }
        if (m_nPicked != -1)
            break;
    }
    if (m_nPicked == -1 && (m_spLast.FUN_141412c90() != 0 ? true : false))
    {
        efd::Point3 hit;
        CAtlArray<NiRenderObject*> skins;
        int r = PickMesh(m_spLast.FUN_141412c90(), skins, (NiPoint3*)&hit);
        *pHit = hit;
        return r;
    }
    if (m_nPicked != -1)
        return 1;
    return 0;
}

// @0x141419210
void CItemPickingHelper::Reset()
{
    m_spPicker.FUN_1412861e0(0);
    m_spMesh.FUN_141418a00(0);
}

// @0x141419250
int CItemPickingHelper::PickTarget(Unk_PickTarget* pTarget, const CString* pPart, NiPoint3* pHit)
{
    m_spMesh.FUN_141418a00(0);
    if (pTarget == 0)
        return 0;
    bool bBad = pTarget->FUN_141200940() == 0 || pTarget->FUN_141200940()->FUN_140527840() == 0;
    if (bBad)
        return 0;
    void* pGame = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pGame == 0)
        return 0;
    NiAVObject* pMesh = pTarget->FUN_1411676d0(pPart);
    if (pMesh == 0)
        return 0;
    CAtlArray<NiRenderObject*> skins;
    bool bSkin = pTarget->FUN_141200940()->FUN_140527840()->FUN_14053cfd0();
    if (bSkin)
    {
        void* pObject = pTarget->FUN_141200850();
        FUN_141419670(pObject, &skins);
    }
    return PickMesh(pMesh, skins, pHit);
}

// @0x1414194b0
// MS2-FUNCTIONAL: byte-exact except the stack slot of the uninitialised `tri` out-param (exe: lowest slot)
int CItemPickingHelper::PickMesh(NiAVObject* pMesh, CAtlArray<NiRenderObject*>& skins, NiPoint3* pHit)
{
    unsigned __int64 tri;
    m_spMesh.FUN_141418a00(0);
    if (pMesh == 0)
        return 0;
    Unk_PickXY xy = DAT_143b02320;
    if (FUN_140aadf80()->FUN_141b90e30(&xy.x, &xy.y) == 0)
        return 0;
    Unk_PickRenderer* pRenderer = FUN_14098d8d0(&DAT_143d6eb58, FUN_140994450());
    if (pRenderer == 0)
        return 0;
    if (pRenderer->IsFlag())
        return 0;
    void* pCamMgr = FUN_1413f9a70();
    efd::Point3 hit;
    efd::Point3 normal;
    NiPoint2 uv;
    if (m_spPicker.FUN_141286290()->FUN_14147ea50(pMesh, FUN_1409a8a60(pCamMgr), xy.x, xy.y, &hit, &normal, &uv, &tri, &skins))
    {
        if (pHit != 0)
            *pHit = *(NiPoint3*)&hit;
        m_spMesh.FUN_141418a00(pMesh);
        return 1;
    }
    return 0;
}

// @0x141419670
// MS2-FUNCTIONAL: frame 0x10 larger than the exe (iterator object with an out-of-line dtor); same behaviour
void FUN_141419670(void* pObject, CAtlArray<NiRenderObject*>* pOut)
{
    if (pObject == 0)
        return;
    Unk_PickSceneIter it(FUN_141b6efc0(FUN_14123c410(pObject)));
    NiAVObject* pNode;
    while ((pNode = it.FUN_14098e0d0(true)) != 0)
    {
        const void* pName = FUN_1409a8b90(pNode);
        if (FUN_140998dc0(pName, "FA_Skin") || FUN_140998dc0(pName, "FA_EA"))
        {
            NiRenderObject* pPart = FUN_14098d8d0(&DAT_143afa7d0, pNode);
            if (pPart != 0)
                pOut->Add(pPart);
        }
    }
}

// @0x141419840
Unk_PickMeshPtr::~Unk_PickMeshPtr()
{
    if (m_p != 0)
        FUN_1405a93d0(m_p);
}

// @0x1414197a0
Unk_PickMeshPtr::Unk_PickMeshPtr(NiAVObject* p)
{
    m_p = p;
    if (m_p != 0)
        FUN_140980460(m_p);
}

// @0x141419be0
bool Unk_PickRenderer::IsFlag() const
{
    return m_bFlag;
}
