// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CItemCustomizeController, the abstract base of the item
// customize controllers (1st TU of the fused guess unit ?\itemcustomizecontroller.cpp).
// MS2-UNIT: ?\itemcustomizecontroller.cpp#1
// MS2-RANGE: 0x141410cd0-0x1414131e0 .text$mn
// MS2-RANGE: 0x1400f5c70-0x1400f5e00 .text$di
// MS2-RANGE: 0x142cb1bd0-0x142cb1c80 .text$yd
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?FUN_141412c90@Unk_PickMeshPtr@@QEBAPEAVNiAVObject@@XZ 0x141412c90 ; unique
// MS2-PIN: ?GetCount@?$CAtlArray@PEAVNiAVObject@@V?$CElementTraits@PEAVNiAVObject@@@ATL@@@ATL@@QEBA_KXZ 0x141412e30 ; unique
// MS2-PIN: ?vfunc_28@CItemCustomizeController@@UEAAXXZ 0x141413080 ; unique
// MS2-PIN: ?IsEmpty@?$CAtlArray@PEAVNiAVObject@@V?$CElementTraits@PEAVNiAVObject@@@ATL@@@ATL@@QEBA_NXZ 0x141413090 ; unique
// MS2-PIN: ?vfunc_33@CItemCustomizeController@@UEAAXXZ 0x1414130c0 ; unique
// MS2-PIN: ?vfunc_36@CItemCustomizeController@@UEAAXXZ 0x1414130d0 ; unique
// MS2-PIN: ?vfunc_35@CItemCustomizeController@@UEAAXXZ 0x1414130e0 ; unique
// MS2-PIN: ?vfunc_32@CItemCustomizeController@@UEAAXAEBVNiPoint3@@0AEBVNiPoint2@@M@Z 0x1414130f0 ; unique
// MS2-PIN: ?vfunc_31@CItemCustomizeController@@UEAAXXZ 0x141413110 ; unique
// MS2-PIN: ?vfunc_30@CItemCustomizeController@@UEAAXAEBVNiPoint3@@@Z 0x141413120 ; unique
// MS2-PIN: ?vfunc_34@CItemCustomizeController@@UEAAXAEBVNiPoint3@@@Z 0x141413130 ; unique
// MS2-PIN: ?vfunc_6@CItemCustomizeController@@UEAAXXZ 0x141413140 ; unique
// MS2-PIN: ?RelocateElements@?$CElementTraitsBase@PEAVNiAVObject@@@ATL@@SAXPEAPEAVNiAVObject@@0_K@Z 0x141413150 ; unique
// MS2-PIN: ?vfunc_29@CItemCustomizeController@@UEAAHXZ 0x1414131b0 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ??HPoint2@efd@@QEBA?AV01@AEBV01@@Z 0x141412ca0
// MS2-PIN: ?Add@?$CAtlArray@PEAVNiAVObject@@V?$CElementTraits@PEAVNiAVObject@@@ATL@@@ATL@@QEAA_KAEBQEAVNiAVObject@@@Z 0x141412d00
// MS2-PIN: ?GrowBuffer@?$CAtlArray@PEAVNiAVObject@@V?$CElementTraits@PEAVNiAVObject@@@ATL@@@ATL@@AEAA_N_K@Z 0x141412ee0
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\itemcustomizecontroller.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "itemcustomizecontroller_1.h"
#include "itempickinghelper.h"

struct Unk_PickTargetView : public Unk_PickTarget {};   // layout-identical view of the picker target element
#include <efd/MemHint.h>
#include <efd/MemObject.h>
#include <efd/ServiceManager.h>
#include <ecrInput/InputService.h>
#include <NiInputSystem.h>
#include <NiInputMouse.h>
#include <NiRenderer.h>
#include <NiRenderTargetGroup.h>
#include <NiCamera.h>
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- out-of-unit callees ----

// One customizable part of the equipped item model (MS2Ptr-held; ?\itemugcmesh.cpp).
class Unk_CustomizePart : public CPtred
{
public:
    float FUN_141422340(int nIndex);                            // customize value nIndex of the part
};
// The part's UGC mesh view (MS2Ptr-held, built from the part by the converting copy 0x1411de2a0).
class Unk_CustomizeMesh : public CPtred
{
};
void FUN_1414225d0(MS2Ptr<Unk_CustomizeMesh> spMesh, int nIndex, float fValue);   // stores value nIndex

struct Unk_ICCItemData { bool FUN_140547170(); };               // item data struct: no per-mesh highlight
struct Unk_ICCItem { Unk_ICCItemData* FUN_14053ec70(); };       // item -> item data struct

class CEquipItem : public CPtred
{
public:
    int FUN_1411dc0d0();                                        // number of customizable parts
    int FUN_1411dc820();                                        // customize value of the item
    Unk_ICCItem* FUN_1411dc7f0();                               // the item
    void FUN_1411dca30(int nSlot, CAtlArray<CString>& aParts);  // attach part names of an equip slot
    MS2Ptr<Unk_CustomizePart> FUN_1411dc950(const CString& strPart);
};

struct Unk_ICCEntityRef { unsigned __int64 m_id; };
struct Unk_ICCPlayer
{
    MS2Ptr<CEquipItem> FUN_141655e10(int nSlot);                // the item equipped in a slot
    Unk_ICCEntityRef FUN_14123c460();                           // the player's entity
};
struct Unk_ICCWorld
{
    Unk_ICCPlayer* FUN_141bd0cc0();                             // the local player
};
Unk_ICCWorld* FUN_1403ed2d0();
struct Unk_ICCEntityLoader
{
    void* FUN_140999440(const Unk_ICCEntityRef& kEntity);       // the entity's loaded scene, NULL while loading
};
Unk_ICCEntityLoader* FUN_141b6f910();

int FUN_14151f6e0();                                            // customizing is allowed now (my PC state)
float FUN_140a17940(float fValue, float fMin, float fMax);      // clamp
NiAVObject* FUN_141167cf0(const CString& strName);              // scene node by name (picking mesh)
void FUN_141414180(NiPointer<CItemCustomizeController> spController);   // unregisters a closed controller (TU 2)

struct Unk_ICCCursor { int FUN_141b90e30(float* pX, float* pY); };      // cursor position in pixels
Unk_ICCCursor* FUN_140aadf80();
void* FUN_1413f9a70();                                          // camera manager
NiCamera* FUN_1409a8a60(void* pCameraManager);                  // active camera

// Picking mesh hits of the customize UV picker (?\meshuvpicker.cpp); only the call used here.
class CMeshUVPicker
{
public:
    bool FUN_14147ea50(NiAVObject* pMesh, NiCamera* pCamera, float x, float y, efd::Point3* pHit, efd::Point3* pNormal,
                       NiPoint2* pUV, float* pT, void* pSkins);
};

const void* FUN_1409a8b90(NiAVObject* pNode);                   // node name
bool FUN_140998dc0(const void* pName, const char* psz);         // name == psz

struct Unk_ICCConfigFloat
{
    float FUN_1402bac70();
    char m_pad[0x58];
};
struct Unk_ICCConfig
{
    char m_pad_0000[0x2ce0];
    Unk_ICCConfigFloat m_2ce0;                                  // highlight scale of the hair mesh "HR1:1"
    Unk_ICCConfigFloat m_2d38;                                  // highlight scale of the other meshes
};
Unk_ICCConfig* FUN_1401d3200();

// The app framework (FUN_14086d260); its service manager handle sits at +8.
struct Unk_ICCApp { char m_pad[8]; char m_manager[1]; };
Unk_ICCApp* FUN_14086d260();
efd::ServiceManager* FUN_140af8310(char* pManager);

// ---- static initializers (.text$di) ----
#ifndef MS2_HOOK_DLL
// @0x1400f5c70
NiImplementRootRTTI(CItemCustomizeController);
#endif
#include "ms2/placeholder/header_statics_a.h"

// @0x141410cd0
CItemCustomizeController::CItemCustomizeController()
    : m_nSlot(0)
    , m_spEquipItem(0)
    , m_bUseButton1(0)
    , m_bUseButton2(0)
    , m_bEnabled(0)
    , m_nCurIndex(0)
    , m_spPicker(0)
    , m_kCursorStart(0, 0)
    , m_kScreenStart(0, 0)
    , m_n98(0)
    , m_pListener(0)
    , m_bDragging2(0)
    , m_bDragging1(0)
    , m_bDragging(0)
    , m_nPartCount(0)
{
    for (int i = 0; i < 2; i++)
        m_afValue[i] = 0.0f;
}

// @0x141410e60
CItemCustomizeController::~CItemCustomizeController()
{
    vfunc_39(0);
    for (int i = 0; i < 2; i++)
        m_afValue[i] = 0;
    m_nSlot = 0;
    m_spEquipItem = 0;
    m_spPicker = 0;
    m_bEnabled = 0;
    m_bUseButton2 = 0;
    m_bUseButton1 = 0;
    m_bDragging = 0;
    m_kScreenStart = efd::Point2(0, 0);
    m_kCursorStart = efd::Point2(0, 0);
    m_aPartNames.RemoveAll();
    m_aMeshNames.RemoveAll();
}

// @0x141410ff0
int CItemCustomizeController::Initialize(int nSlot)
{
    m_nSlot = nSlot;
    m_spPicker = new (efd::MemHint(efd::MemHint::NONE)) CItemPickingHelper;
    if (m_spPicker->CreatePicker() == 0)
        return 0;
    if (RefreshEquipItem() == 0)
        return 0;
    if (vfunc_29() == 0)
        return 0;
    vfunc_28();
    vfunc_37();
    vfunc_3();
    return 1;
}

// @0x141411110
void CItemCustomizeController::Close()
{
    FUN_141414180(this);
    m_nPartCount = 0;
    ApplyValues();
    vfunc_5();
    vfunc_39(0);
}

// @0x141411190
void CItemCustomizeController::Cancel()
{
    vfunc_6();
    vfunc_39(0);
}

// @0x1414111d0
int CItemCustomizeController::vfunc_3()
{
    return 1;
}

// @0x1414111f0
void CItemCustomizeController::vfunc_4()
{
    if (m_nPartCount == 0 && static_cast<bool>(m_spEquipItem.get()))
        m_nPartCount = m_spEquipItem->FUN_1411dc0d0();
}

// @0x141411270
int CItemCustomizeController::RefreshEquipItem()
{
    Unk_ICCPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer != 0)
    {
        m_spEquipItem = pPlayer->FUN_141655e10(m_nSlot);
        if (m_spEquipItem.get())
            m_nPartCount = m_spEquipItem->FUN_1411dc0d0();
        return 1;
    }
    return 0;
}

// @0x141411340
void CItemCustomizeController::vfunc_7(float fValue)
{
    if (m_bEnabled && fValue >= 0.0f)
    {
        float fMin, fMax;
        vfunc_25(&fMin, &fMax);
        FUN_140a17940(fValue, fMin, fMax);      // result unused in the original
        vfunc_14(fValue);
    }
}

// @0x1414113c0
void CItemCustomizeController::vfunc_8(int nIndex, float fValue)
{
    if (m_bEnabled && fValue >= 0.0f)
    {
        float fMin, fMax;
        vfunc_26(nIndex, &fMin, &fMax);
        FUN_140a17940(fValue, fMin, fMax);      // result unused in the original
        vfunc_15(nIndex, fValue);
    }
}

// @0x141411450
void CItemCustomizeController::vfunc_11()
{
    if (m_bEnabled)
        vfunc_14(vfunc_21() + GetWheelDelta());
}

// @0x1414114c0
int CItemCustomizeController::vfunc_12()
{
    MS2Ptr<CEquipItem> spOld(m_spEquipItem);
    RefreshEquipItem();
    if (m_spEquipItem->FUN_1411dc0d0())
    {
        vfunc_13(spOld);
        return 1;
    }
    return 0;
}

// @0x141411580
void CItemCustomizeController::vfunc_13(MS2Ptr<CEquipItem> spOld)
{
    if (vfunc_29())
    {
        vfunc_37();
        vfunc_3();
    }
}

#ifndef MS2_HOOK_DLL
// @0x1414115f0
const Unk_CustomizeRange* CItemCustomizeController::vfunc_23()
{
    static Unk_CustomizeRange s_kRange;
    return &s_kRange;
}
#endif

// @0x141411680
const Unk_CustomizeRange* CItemCustomizeController::vfunc_24(int nIndex)
{
    return vfunc_23();
}

// Mouse wheel step: one notch (120) moves vfunc_40() of the value range.
// @0x1414116b0
float CItemCustomizeController::GetWheelDelta()
{
    if (m_bEnabled)
    {
        int nWheel = vfunc_41();
        if (nWheel)
        {
            float fMin, fMax;
            vfunc_25(&fMin, &fMax);
            float fRange = fMax - fMin;
            float fDelta = fRange > 0.0f ? (float)nWheel * vfunc_40() / 120.0f * fRange : 0.0f;
            return fDelta;
        }
    }
    return 0.0f;
}

// MS2-FUNCTIONAL: the exe builds the per-call MS2Ptr<Unk_CustomizeMesh> with a converting copy constructor
// (0x1411de2a0, MS2Ptr<U> -> MS2Ptr<T>) that the shared placeholder/ascript.h MS2Ptr does not declare; this
// version converts through the raw pointer (same AddRef/Release effect).
// @0x1414117a0
void CItemCustomizeController::ApplyValues()
{
    Unk_ICCPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return;
    if (m_spEquipItem.IsNull())
        return;
    CAtlArray<CString> aParts;
    m_spEquipItem->FUN_1411dca30(m_nSlot, aParts);
    if (m_bEnabled && aParts.GetCount() > 0)
    {
        MS2Ptr<Unk_CustomizePart> spPart = m_spEquipItem->FUN_1411dc950(aParts[0]);
        for (int i = 0; i < 2; i++)
            FUN_1414225d0(MS2Ptr<Unk_CustomizeMesh>((Unk_CustomizeMesh*)spPart.get()), i, m_afValue[i]);
    }
}

// @0x141411920
void CItemCustomizeController::ReadValues()
{
    Unk_ICCPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return;
    {
        CAtlArray<CString> aParts;
        m_spEquipItem->FUN_1411dca30(m_nSlot, aParts);
        if (aParts.GetCount() > 0)
        {
            MS2Ptr<Unk_CustomizePart> spPart = m_spEquipItem->FUN_1411dc950(aParts.GetAt(0));
            for (int i = 0; i < 2; i++)
            {
                float fValue = spPart.get()->FUN_141422340(i);
                float fMin, fMax;
                vfunc_26(i, &fMin, &fMax);
                m_afValue[i] = FUN_140a17940(fValue, fMin, fMax);
            }
        }
    }
}

// @0x141411a90
int CItemCustomizeController::IsPickable(efd::Point3* pHit)
{
    return (m_nPartCount && (m_spPicker->GetMode() == 1 || m_spPicker->Pick(pHit, m_aPartNames))) ? 1 : 0;
}

// @0x141411b20
int CItemCustomizeController::vfunc_38(int bActive, const efd::Point3& kPos)
{
    if (FUN_14151f6e0() == 0)
    {
        if (m_spPicker->GetMode() == 1)
            EndDrag();
        return 0;
    }
    int bOn = bActive;
    SetDragging(bOn);
    vfunc_39(bOn);
    if (bActive)
    {
        int nWheel = vfunc_41();
        if (nWheel && m_pListener)
            m_pListener->vfunc_0(this, nWheel);
        vfunc_11();
    }
    if (bActive || m_spPicker->GetMode() == 1)
        OnMouseButton1(kPos);
    OnMouseButton2(bActive, kPos);
    m_n98 = 0;
    return 1;
}

// Drag mode 1 (left button): remembers the cursor and the picked part's screen position.
// @0x141411c70
void CItemCustomizeController::BeginDrag(const NiPoint3& kPos)
{
    m_spPicker->SetMode(1);
    m_bDragging1 = 1;
    SetDragging(1);
    Unk_PickTarget* pTarget = m_spPicker->GetPickedTarget();
    if (pTarget)
    {
        if (!FUN_140aadf80()->FUN_141b90e30(&m_kCursorStart.x, &m_kCursorStart.y))
            return;
        void* pCameraManager = FUN_1413f9a70();
        Unk_ICCPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pPlayer == 0)
            return;
        NiRenderer* pRenderer = NiRenderer::GetRenderer();
        NiRenderTargetGroup* pTarget2;
        if (pRenderer && (pTarget2 = pRenderer->GetDefaultRenderTargetGroup()) != 0)
        {
            efd::Point3 kAnchor, kP1, kP2, kP3;
            pTarget->FUN_141202480(&kAnchor, &kP1, &kP2, &kP3, 0);
            NiPoint3 kWorld(kAnchor);
            FUN_1409a8a60(pCameraManager)->WorldPtToScreenPt(kWorld, m_kScreenStart.x, m_kScreenStart.y);
            m_kScreenStart.x *= (float)pTarget2->GetWidth(0);
            m_kScreenStart.y = (1.0f - m_kScreenStart.y) * (float)pTarget2->GetHeight(0);
        }
    }
    vfunc_30(kPos);
}

// @0x141411f50
void CItemCustomizeController::UpdateDrag()
{
    NiPoint2 kCursor;
    if (!FUN_140aadf80()->FUN_141b90e30(&kCursor.x, &kCursor.y))
        return;
    CAtlArray<NiAVObject*> aMeshes;
    for (unsigned i = 0; i < m_aMeshNames.GetCount(); i++)
    {
        NiAVObject* pMesh = FUN_141167cf0(m_aMeshNames[i]);
        if (pMesh)
            aMeshes.Add(pMesh);
    }
    if (aMeshes.IsEmpty())
    {
        vfunc_31();
        return;
    }
    Unk_ICCPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return;
    Unk_ICCEntityLoader* pLoader = FUN_141b6f910();
    if (pLoader == 0)
        return;
    void* pScene = pLoader->FUN_140999440(pPlayer->FUN_14123c460());
    if (pScene == 0)
        return;
    void* pCameraManager = FUN_1413f9a70();
    if (pCameraManager == 0)
        return;
    for (unsigned j = 0; j < aMeshes.GetCount(); j++)
    {
        NiAVObject* pMesh = aMeshes.GetAt(j);
        efd::Point3 kHit;
        efd::Point3 kNormal;
        NiPoint2 kUV;
        float fT;
        NiPoint2 kDelta = kCursor - m_kCursorStart;
        NiPoint2 kScreen = m_kScreenStart + kDelta;
        if (m_spPicker->GetUVPicker()->FUN_14147ea50(pMesh, FUN_1409a8a60(pCameraManager), kScreen.x, kScreen.y, &kHit,
                                                     &kNormal, &kUV, &fT, 0))
        {
            vfunc_32(*(NiPoint3*)&kHit, *(NiPoint3*)&kNormal, kUV, fT);
            break;
        }
    }
}

// @0x141412320
void CItemCustomizeController::EndDrag()
{
    m_bDragging1 = 0;
    vfunc_33();
    m_spPicker->SetMode(0);
    SetDragging(0);
}

// Drag mode 2 (right button).
// @0x141412380
void CItemCustomizeController::BeginDrag2(const NiPoint3& kPos)
{
    m_bDragging2 = 1;
    SetDragging(1);
    vfunc_34(kPos);
}

// @0x1414123d0
void CItemCustomizeController::UpdateDrag2()
{
    vfunc_35();
}

// @0x141412400
void CItemCustomizeController::EndDrag2()
{
    vfunc_36();
    SetDragging(0);
    m_bDragging2 = 0;
}

// @0x141412450
MS2Ptr<CEquipItem> CItemCustomizeController::GetEquipItem()
{
    return m_spEquipItem;
}

// @0x1414124a0
int CItemCustomizeController::GetEquipItemValue()
{
    return m_spEquipItem.get() ? m_spEquipItem->FUN_1411dc820() : 0;
}

// Highlights the item's parts: hover (mode 0) half strength, dragging (mode 1) full strength.
// @0x141412500
void CItemCustomizeController::vfunc_39(int bActive)
{
    float fScale = 0.0f;
    float fMode = 0.0f;
    if (bActive)
    {
        float fHighlight = GetHighlightScale(m_spPicker->m_spMesh.FUN_141412c90());
        if (m_spPicker->GetMode() == 0)
        {
            fScale = fHighlight * 0.5f;
            fMode = 2.0f;
        }
        else if (m_spPicker->GetMode() == 1)
        {
            fScale = fHighlight;
            fMode = 3.0f;
        }
    }
    // the exe instantiates CAtlArray::operator[] separately here (0x141412c40, not the 0x141168040 copy #4 calls)
    CAtlArray<MS2Ptr<Unk_PickTargetView> >& aTargets = (CAtlArray<MS2Ptr<Unk_PickTargetView> >&)m_spPicker->GetTargets();
    for (size_t i = 0; i < aTargets.GetCount(); i++)
    {
        Unk_PickTarget* pTarget = aTargets[i].get();
        if (pTarget == 0)
            continue;
        if (!m_spEquipItem->FUN_1411dc7f0()->FUN_14053ec70()->FUN_140547170())
            pTarget->FUN_1411679d0(fScale, fMode, m_spPicker->m_spMesh.FUN_141412c90());
        else
            pTarget->FUN_1411679d0(fScale, fMode, 0);
    }
}

// Mouse wheel delta of this frame.
// @0x1414126d0
int CItemCustomizeController::vfunc_41()
{
    efd::ServiceManager* pServiceManager = FUN_140af8310(FUN_14086d260()->m_manager);
    ecrInput::InputService* pInputService = pServiceManager->GetSystemServiceAs<ecrInput::InputService>();
    NiInputMouse* pMouse = pInputService->GetInputSystem()->OpenMouse();
    int nWheel = 0;
    pMouse->GetPositionDelta(NiInputMouse::NIM_AXIS_Z, nWheel);
    return nWheel;
}

// @0x141412750
void CItemCustomizeController::OnMouseButton1(const efd::Point3& kPos)
{
    if (m_bUseButton1)
    {
        efd::ServiceManager* pServiceManager = FUN_140af8310(FUN_14086d260()->m_manager);
        ecrInput::InputService* pInputService = pServiceManager->GetSystemServiceAs<ecrInput::InputService>();
        NiInputMouse* pMouse = pInputService->GetInputSystem()->OpenMouse();
        int nMode = m_spPicker->GetMode();
        if (pMouse->ButtonWasPressed(NiInputMouse::NIM_LEFT) && nMode == 0)
        {
            BeginDrag(kPos);
            UpdateDrag();
        }
        else if (pMouse->ButtonIsDown(NiInputMouse::NIM_LEFT) && nMode == 1)
            UpdateDrag();
        else if (pMouse->ButtonWasReleased(NiInputMouse::NIM_LEFT) && nMode == 1)
            EndDrag();
    }
}

// @0x141412870
void CItemCustomizeController::OnMouseButton2(int bActive, const efd::Point3& kPos)
{
    if (m_bUseButton2)
    {
        efd::ServiceManager* pServiceManager = FUN_140af8310(FUN_14086d260()->m_manager);
        ecrInput::InputService* pInputService = pServiceManager->GetSystemServiceAs<ecrInput::InputService>();
        NiInputMouse* pMouse = pInputService->GetInputSystem()->OpenMouse();
        int nMode = m_spPicker->GetMode();
        if (m_bDragging2)
        {
            if (pMouse->ButtonWasReleased(NiInputMouse::NIM_RIGHT))
                EndDrag2();
            else
                UpdateDrag2();
        }
        else if (bActive && pMouse->ButtonWasPressed(NiInputMouse::NIM_RIGHT) && nMode == 0)
            BeginDrag2(kPos);
    }
}

// @0x141412990
float CItemCustomizeController::GetHighlightScale(NiAVObject* pNode)
{
    CString strUnused;
    if (pNode && FUN_140998dc0(FUN_1409a8b90(pNode), "HR1:1"))
        return FUN_1401d3200()->m_2ce0.FUN_1402bac70();
    else
        return FUN_1401d3200()->m_2d38.FUN_1402bac70();
}
