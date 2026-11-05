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
#include "equipmodel.h"   // C3: the picking target is a CEquipModel (was Unk_PickTarget)
#include "ms2/placeholder/ms2ptr_impl.h"
#include "hook/ms2hook.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/client/ms2/windowservice.h"
#include <efd/MemHint.h>
#include <efd/MemObject.h>
#include <NiPoint2.h>
#include <NiFixedString.h>
#include <NiRenderObject.h>
#include <NiDX9Renderer.h>     // C3: ms_RTTI
#include <efd/Point2.h>

// ---- out-of-unit callees ----
void FUN_140159b70(long hr);            // AtlThrow

class NiCamera;
struct Unk_PickXY { float x, y; };      // cursor position

class CMeshUVPicker : public efd::MemObject
{
public:
    CMeshUVPicker();                                                    // 0x14147e6e0
    int Init();                                                // init
    bool PickUVAndPosition(NiRenderObject* pMesh, NiCamera* pCamera, float fX, float fY, struct Unk_FcPoint3* pPos0, struct Unk_FcPoint3* pPos1,
                       NiPoint2* pUV, float* pIndex, CAtlArray<NiRenderObject*>* pExtras);   // 0x14147ea50 (meshuvpicker.h)
    char m_pad[0x98];
};
MS2_CHECK_SIZE(CMeshUVPicker, 0x98);

struct Unk_PickApp : public CWindowService { };        // cursor position
void* FUN_140aadf80();   // C3: was FUN_140aadf80
struct Unk_PickRenderer
{
    bool IsFlag() const;
    char m_pad[0x850];
    bool m_bFlag;                                                       // +0x850
};
class CEquipModel;
void* FUN_141200850(CEquipModel* self);   // C3: was the CEquipModel member view (equipmodel.cpp)
class Ni3DRenderView* FUN_1413f9a70();   // C3: was FUN_1413f9a70
class Ni3DRenderView   // C3: member view for the former free stand-ins
{
public:
    class NiCamera* GetCamera() const;
};
class CItemData { public: bool FUN_14053cfd0(); };   // C3: member view (itemdata.h)
class CItem : public CPtred { public: class Unk_ItemEquipData* FUN_140527840(); };          // item -> item data (citem.h's return type)
class GameObject { public: egf::Entity* FUN_14123c410(); };   // C3: unit-local view
namespace egf { class Entity; }   // C3: FUN_141b6efc0 takes the real egf::Entity*
NiAVObject* FUN_141b6efc0(egf::Entity* pEntity);                                     // entity -> scene root
// Depth-first walker over a scene graph (0x30 bytes; unrecovered class, see nifanimationservice.cpp).
class Unk_NodeQueue
{
public:
    Unk_NodeQueue(NiAVObject* pkRoot);              // 0x14098cb80
    ~Unk_NodeQueue();                             // 0x14098cf00
    NiAVObject* Next(bool bDescend);                // 0x14098e0d0
private:
    void* m_pad_00; void* m_pad_08; void* m_pad_10; void* m_pad_18; void* m_pad_20; void* m_pad_28;
};

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
    return m_spPicker.FUN_141286290()->Init();
}

// @0x141418e00
void CItemPickingHelper::ClearTargets()
{
    m_targets.RemoveAll();
}

// @0x141418e30
void CItemPickingHelper::AddTarget(CEquipModel* pTarget)
{
    if (pTarget != 0)
    {
        MS2Ptr<CEquipModel> sp(pTarget);
        m_targets.Add(sp);
    }
}

// @0x141418e90
CEquipModel* CItemPickingHelper::GetPickedTarget()
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
    void* pCamMgr = ((void*)FUN_1413f9a70());
    NiPoint3 camPos = *((class NiPoint3 const*)&((class NiCamera*)(class NiCamera*)(((class Ni3DRenderView*)(void*)(pCamMgr))->GetCamera()))->GetWorldLocation());
    float fBest = FLT_MAX;
    m_nPicked = -1;
    for (unsigned i = 0; i < m_targets.GetCount(); i++)
    {
        MS2Ptr<CEquipModel> spTarget(m_targets[i]);
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
int CItemPickingHelper::PickTarget(CEquipModel* pTarget, const CString* pPart, NiPoint3* pHit)
{
    m_spMesh.FUN_141418a00(0);
    if (pTarget == 0)
        return 0;
    bool bBad = pTarget->FUN_141200940() == 0 || pTarget->FUN_141200940()->FUN_140527840() == 0;
    if (bBad)
        return 0;
    void* pGame = WorldService::GetInstance()->FUN_141bd0cc0();
    if (pGame == 0)
        return 0;
    NiAVObject* pMesh = pTarget->FUN_1411676d0(pPart);
    if (pMesh == 0)
        return 0;
    CAtlArray<NiRenderObject*> skins;
    bool bSkin = reinterpret_cast<CItemData*>(pTarget->FUN_141200940()->FUN_140527840())->FUN_14053cfd0();
    if (bSkin)
    {
        void* pObject = FUN_141200850(pTarget);
        FUN_141419670(pObject, &skins);
    }
    return PickMesh(pMesh, skins, pHit);
}

// @0x1414194b0
int CItemPickingHelper::PickMesh(NiAVObject* pMesh, CAtlArray<NiRenderObject*>& skins, NiPoint3* pHit)
{
    float tri;                                  // CMeshUVPicker::PickUVAndPosition writes a float (float* pIndex)
    m_spMesh.FUN_141418a00(0);
    if (pMesh == 0)
        return 0;
    Unk_PickXY xy = reinterpret_cast<const Unk_PickXY&>(efd::Point2::ZERO);
    if (((struct Unk_PickApp*)FUN_140aadf80())->GetCursorClientPos(&xy.x, &xy.y) == 0)
        return 0;
    Unk_PickRenderer* pRenderer = (Unk_PickRenderer*)NiObject::DynamicCast(&NiDX9Renderer::ms_RTTI, (class NiObject const*)(((void*)NiRenderer::GetRenderer())));
    if (pRenderer == 0)
        return 0;
    if (pRenderer->IsFlag())
        return 0;
    void* pCamMgr = ((void*)FUN_1413f9a70());
    efd::Point3 hit;
    efd::Point3 normal;
    NiPoint2 uv;
    if (m_spPicker.FUN_141286290()->PickUVAndPosition((NiRenderObject*)pMesh, ((class Ni3DRenderView*)(void*)(pCamMgr))->GetCamera(), xy.x, xy.y, (struct Unk_FcPoint3*)&hit, (struct Unk_FcPoint3*)&normal, &uv, &tri, &skins))
    {
        if (pHit != 0)
            *pHit = *(NiPoint3*)&hit;
        m_spMesh.FUN_141418a00(pMesh);
        return 1;
    }
    return 0;
}

// @0x141419670
void FUN_141419670(void* pObject, CAtlArray<NiRenderObject*>* pOut)
{
    if (pObject == 0)
        return;
    Unk_NodeQueue it(FUN_141b6efc0(reinterpret_cast<GameObject*>(pObject)->FUN_14123c410()));
    NiAVObject* pNode;
    while ((pNode = it.Next(true)) != 0)
    {
        const NiFixedString& kName = ((class NiObjectNET*)(class NiAVObject*)(pNode))->GetName();
        if (kName == "FA_Skin" || kName == "FA_EA")
        {
            NiRenderObject* pPart = (NiRenderObject*)NiObject::DynamicCast(&NiRenderObject::ms_RTTI, (class NiObject const*)(pNode));
            if (pPart != 0)
                pOut->Add(pPart);
        }
    }
}

// @0x141419840
Unk_PickMeshPtr::~Unk_PickMeshPtr()
{
    if (m_p != 0)
        ((class NiRefObject*)(void*)(m_p))->DecRefCount();
}

// @0x1414197a0
Unk_PickMeshPtr::Unk_PickMeshPtr(NiAVObject* p)
{
    m_p = p;
    if (m_p != 0)
        ((class NiRefObject*)(void*)(m_p))->IncRefCount();
}

// @0x141419be0
bool Unk_PickRenderer::IsFlag() const
{
    return m_bFlag;
}
