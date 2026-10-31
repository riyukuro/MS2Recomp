// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CItemMorphController (3rd TU of the fused guess unit
// ?\itemcustomizecontroller.cpp).
// MS2-UNIT: ?\itemcustomizecontroller.cpp#3
// MS2-RANGE: 0x141416de0-0x141418bf0 .text$mn
// MS2-RANGE: 0x1400f6320-0x1400f6660 .text$di
// MS2-RANGE: 0x142cb1e90-0x142cb1fc0 .text$yd
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
// MS2-PIN: ??__Fs_unk1402a9d70@@YAXXZ 0x142cb1f20 ; hand: atexit of header-statics map
// MS2-PIN: ??__Fs_condition2@@YAXXZ 0x142cb1fb0 ; hand: atexit of s_condition2
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\itemcustomizecontroller.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "itemmorphcontroller.h"
#include "itempickinghelper.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include <efd/MemObject.h>
#include <efd/ServiceManager.h>
#include <ecrInput/InputService.h>
#include <NiInputSystem.h>
#include <NiInputMouse.h>
#include <NiAVObject.h>
#include <NiFixedString.h>
#include <NiTimeController.h>
#include <NiInterpController.h>
#include <NiInterpolator.h>
#include <NiMorphWeightsController.h>
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/placeholder/cmainsystem.h"

// ---- out-of-unit callees ----

// The item the controller edits (CPtred, held in MS2Ptr; ?\equipitem.cpp). Only the members this unit calls.
struct Unk_MorphRangeList
{
    const Unk_CustomizeRange* FUN_140544f20(size_t nIndex);        // range nIndex (static default when absent)
    int FUN_140545090();                                        // number of ranges
};
struct Unk_MorphItemSection { Unk_MorphRangeList* FUN_14054b2f0(int nKind); };
struct Unk_MorphItemData { Unk_MorphItemSection* FUN_14053eba0(); };
struct Unk_MorphItem { Unk_MorphItemData* FUN_14053ec70(); };

class CEquipItem : public CPtred
{
public:
    Unk_MorphItemData* FUN_1411dc7f0();                         // the item's data
    void FUN_1411dca30(int nSlot, CAtlArray<CString>& aParts);  // attach part names of an equip slot
    MS2Ptr<Unk_PickTarget> FUN_1411dc950(const CString& strPart);   // the model of one part
};

               // the local player

struct Unk_MorphConfigFloat { float FUN_1402bac70(); char m_pad[0x58]; };
struct Unk_ClientConfig { char m_pad[0x2d90]; Unk_MorphConfigFloat m_2d90; };
class Unk_SingletonObj1* FUN_1401d3200();   // C3: was FUN_1401d3200

struct Unk_MorphApp { char m_pad[8]; char m_manager[1]; float FUN_141473230(); };   // the app framework
efd::ServiceManager* FUN_140af8310(char* pManager);

float FUN_140a17940(float fValue, float fMin, float fMax);      // clamp
extern const NiRTTI Unk_RenderObjectRTTI;                       // 0x143afa7d0
void FUN_141422660(MS2Ptr<CEquipItem> spItem, int nIndex, float fValue);   // stores value nIndex

// The loaded meshes of a part model: std::set<NiAVObjectPtr> at +0xf8 (equipmodel.h).
std::set<NiAVObjectPtr>* FUN_141201c90(Unk_PickTarget* pPart);

// Listener at +0xa0: slot 2 is called when a value changed (the base class only knows slot 0).
class Unk_MorphListener
{
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(CItemCustomizeController* pController, float fValue, int nIndex);
};

// ---- static initializers (.text$di) ----
#ifndef MS2_HOOK_DLL
static UICommon::CMyPCKeyInputController s_keyInputController;      // header static (origin unknown) @0x1400f6320
// @0x1400f6350
const NiRTTI CItemMorphController::ms_RTTI("CItemMorphController", &CItemCustomizeController::ms_RTTI);
#include "ms2/placeholder/header_statics_a.h"
static CString s_sortNames2[] = {"None","Buy","Like","PriceLow","PriceHigh","Create","EnumEnd"};
static CString s_skill2("skill");
static CString s_stun2("stun");
static Unk_1402a9d70 s_condition2(17, 0.75f, 0.25f, 2.25f, 10);
#else
const NiRTTI CItemMorphController::ms_RTTI("CItemMorphController", &CItemCustomizeController::ms_RTTI);
#endif

// @0x141416de0
CItemMorphController::CItemMorphController()
{
    m_bEnabled = 1;
}

// @0x141416e20
CItemMorphController::~CItemMorphController()
{
}

// @0x141416e50
int CItemMorphController::vfunc_3()
{
    ReadValues();
    ApplyMorph();
    ResetMeshHighlight();
    m_fWheelStep = ((struct Unk_ClientConfig*)FUN_1401d3200())->m_2d90.FUN_1402bac70();
    return 1;
}

// @0x141416eb0
void CItemMorphController::vfunc_4()
{
    CItemCustomizeController::vfunc_4();
}

// @0x141416ed0
void CItemMorphController::vfunc_6()
{
    ReadValues();
    ApplyMorph();
}

// @0x141416f00
void CItemMorphController::vfunc_5()
{
}

// @0x141416f10
float CItemMorphController::vfunc_19()
{
    return vfunc_23()->m_fMin;
}

// @0x141416f40
float CItemMorphController::vfunc_20()
{
    return vfunc_23()->m_fMax;
}

// @0x141416f70
const Unk_CustomizeRange* CItemMorphController::vfunc_23()
{
    return m_spEquipItem->FUN_1411dc7f0()->FUN_14053eba0()->FUN_14054b2f0(0)->FUN_140544f20(m_nCurIndex);
}

// @0x141416fd0
const Unk_CustomizeRange* CItemMorphController::vfunc_24(int nIndex)
{
    return m_spEquipItem->FUN_1411dc7f0()->FUN_14053eba0()->FUN_14054b2f0(0)->FUN_140544f20(nIndex);
}

// @0x141417030
void CItemMorphController::vfunc_25(float* pfMin, float* pfMax)
{
    const Unk_CustomizeRange* pRange = vfunc_23();
    *pfMin = pRange->m_fMin;
    *pfMax = pRange->m_fMax;
}

// @0x141417090
void CItemMorphController::vfunc_26(int nIndex, float* pfMin, float* pfMax)
{
    const Unk_CustomizeRange* pRange = vfunc_24(nIndex);
    *pfMin = pRange->m_fMin;
    *pfMax = pRange->m_fMax;
}

// @0x141417100
void CItemMorphController::vfunc_14(float fValue)
{
    vfunc_15(m_nCurIndex, fValue);
}

// @0x141417140
void CItemMorphController::vfunc_15(int nIndex, float fValue)
{
    if (m_spEquipItem == (CEquipItem*)0)
        return;
    void* pPlayer = WorldService::GetInstance()->FUN_141bd0cc0();
    if (pPlayer != 0)
    {
        NiInterpController* pCtrl = SelectMorphController(nIndex);
        if (pCtrl != 0)
            vfunc_42(nIndex, fValue, pCtrl);
    }
}

// @0x1414171e0
int CItemMorphController::vfunc_27()
{
    return m_spEquipItem->FUN_1411dc7f0()->FUN_14053eba0()->FUN_14054b2f0(0)->FUN_140545090();
}

// @0x141417230
void CItemMorphController::vfunc_11()
{
    if (m_spEquipItem == (CEquipItem*)0)
        return;
    void* pPlayer = WorldService::GetInstance()->FUN_141bd0cc0();
    if (pPlayer != 0)
    {
        NiInterpController* pCtrl = FindMorphController(1);
        if (pCtrl != 0)
        {
            int nWheel = vfunc_41();
            if (nWheel != 0)
            {
                float fDelta = GetWheelDelta();
                float fValue = vfunc_22(m_nCurIndex) + fDelta;
                vfunc_15(m_nCurIndex, fValue);
            }
        }
    }
}

// @0x141417310
int CItemMorphController::vfunc_29()
{
    void* pPlayer = WorldService::GetInstance()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return 0;
    if (m_spEquipItem.IsNull())
        return 0;
    CAtlArray<CString> aParts;
    m_spEquipItem->FUN_1411dca30(m_nSlot, aParts);
    m_spPicker->ClearTargets();
    if (aParts.GetCount() > 0)
    {
        MS2Ptr<Unk_PickTarget> spPart = m_spEquipItem->FUN_1411dc950(aParts.GetAt(0));
        m_spPicker->AddTarget(spPart.get());
    }
    return 1;
}

// @0x141417470
void CItemMorphController::vfunc_28()
{
    m_aPartNames.RemoveAll();
    if (m_nSlot == 1)
    {
        m_aPartNames.Add("HR:0");
        m_aPartNames.Add("HR0:0");
        m_aPartNames.Add("HR1:1");
    }
    else
    {
        m_aPartNames.Add("Editable Mesh");
        m_aPartNames.Add("Editable Poly");
    }
}

// @0x1414175c0
float CItemMorphController::vfunc_40()
{
    return m_fWheelStep;
}

// @0x1414175e0
int CItemMorphController::vfunc_41()
{
    efd::ServiceManager* pServiceManager = FUN_140af8310(reinterpret_cast<Unk_MorphApp*>(TSingleton<CMainSystem>::GetInstance())->m_manager);
    ecrInput::InputService* pInputService = pServiceManager->GetSystemServiceAs<ecrInput::InputService>();
    NiInputMouse* pMouse = pInputService->GetInputSystem()->OpenMouse();
    int nWheel = 0;
    pMouse->GetPositionDelta(NiInputMouse::NIM_AXIS_Z, nWheel);
    return -nWheel;
}

// @0x141417660
void CItemMorphController::vfunc_42(int nIndex, float fValue, NiInterpController* pCtrl)
{
    if (pCtrl != 0)
    {
        m_n98 = 1;
        if (vfunc_22(nIndex) == fValue)
            return;
        const Unk_CustomizeRange* pRange = vfunc_24(nIndex);
        m_afValue[nIndex] = FUN_140a17940(fValue, pRange->m_fMin, pRange->m_fMax);
        float fNow = vfunc_22(nIndex);
        for (unsigned short us = 0; us < pCtrl->GetInterpolatorCount(); us++)
            pCtrl->UpdateValue(reinterpret_cast<Unk_MorphApp*>(TSingleton<CMainSystem>::GetInstance())->FUN_141473230(), fNow, us);
        FUN_141422660(m_spEquipItem, nIndex, fNow);
        if (m_pListener != 0)
            reinterpret_cast<Unk_MorphListener*>(m_pListener)->vfunc_2(this, fNow, nIndex);
    }
}

// @0x141417830
int CItemMorphController::HasMorphController()
{
    return FindMorphController(0) != 0;
}

// @0x141417870
int CItemMorphController::vfunc_38(int bActive, const efd::Point3& kPos)
{
    if (m_n98 != 0)
    {
        m_spPicker->m_spMesh.FUN_141418a00((NiAVObject*)NiObject::DynamicCast(&Unk_RenderObjectRTTI, (class NiObject const*)((NiAVObject*)FindMorphNode(m_nCurIndex))));
    }
    return CItemCustomizeController::vfunc_38(bActive, kPos);
}

// @0x141417930
void CItemMorphController::ResetMeshHighlight()
{
    CAtlArray<CString> aParts;
    m_spEquipItem->FUN_1411dca30(m_nSlot, aParts);
    if (aParts.GetCount() > 0)
    {
        MS2Ptr<Unk_PickTarget> spPart = m_spEquipItem->FUN_1411dc950(aParts.GetAt(0));
        std::set<NiAVObjectPtr>* pSet = FUN_141201c90(spPart.operator->());
        std::set<NiAVObjectPtr>& kSet = *pSet;
        std::set<NiAVObjectPtr>::iterator itEnd = kSet.end();
        for (std::set<NiAVObjectPtr>::iterator it = kSet.begin(); it != itEnd; ++it)
        {
            efd::SmartPointer<NiAVObject> spMesh = *it;
            NiAVObject* pFound = 0;
            for (unsigned int i = 0; i < m_aPartNames.GetCount(); i++)
            {
                pFound = spMesh->GetObjectByName((const char*)m_aPartNames[i]);
                if (pFound != 0)
                    break;
            }
            if (pFound != 0)
            {
                NiTimeController* pTime = pFound->GetControllers();
                while (pTime != 0)
                {
                    NiObject* pCtrl = NiObject::DynamicCast(&NiMorphWeightsController::ms_RTTI, (class NiObject const*)(pTime));
                    if (pCtrl != 0)
                    {
                        NiObject* pRender = NiObject::DynamicCast(&Unk_RenderObjectRTTI, (class NiObject const*)(pFound));
                        if (pRender != 0)
                            spPart.get()->FUN_1411679d0(0, 0, 0);
                        return;
                    }
                    pTime = pTime->GetNext();
                }
            }
        }
    }
}

// @0x141417c10
void CItemMorphController::ApplyMorph()
{
    if (vfunc_27() > 1)
    {
        NiInterpController* pCtrl0 = SelectMorphController(0);
        if (pCtrl0 != 0)
        {
            for (unsigned short us = 0; us < pCtrl0->GetInterpolatorCount(); us++)
                pCtrl0->UpdateValue(reinterpret_cast<Unk_MorphApp*>(TSingleton<CMainSystem>::GetInstance())->FUN_141473230(), vfunc_22(0), us);
        }
        NiInterpController* pCtrl1 = SelectMorphController(1);
        if (pCtrl1 != 0)
        {
            for (unsigned short us = 0; us < pCtrl1->GetInterpolatorCount(); us++)
                pCtrl1->UpdateValue(reinterpret_cast<Unk_MorphApp*>(TSingleton<CMainSystem>::GetInstance())->FUN_141473230(), vfunc_22(1), us);
        }
    }
    else
    {
        NiInterpController* pCtrl = FindMorphController(0);
        if (pCtrl != 0)
        {
            for (unsigned short us = 0; us < pCtrl->GetInterpolatorCount(); us++)
                pCtrl->UpdateValue(reinterpret_cast<Unk_MorphApp*>(TSingleton<CMainSystem>::GetInstance())->FUN_141473230(), vfunc_21(), us);
        }
    }
}

// @0x141417ea0
NiInterpController* CItemMorphController::FindMorphController(int bTrack)
{
    void* pPlayer = WorldService::GetInstance()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return 0;
    if (bTrack != 0)
        m_nCurIndex = 0;
    CAtlArray<CString> aParts;
    m_spEquipItem->FUN_1411dca30(m_nSlot, aParts);
    if (m_nSlot == 1)
    {
        if (aParts.GetCount() > 0)
        {
            MS2Ptr<Unk_PickTarget> spPart = m_spEquipItem->FUN_1411dc950(aParts.GetAt(0));
            std::set<NiAVObjectPtr>* pSet = FUN_141201c90(spPart.operator->());
            std::set<NiAVObjectPtr>& kSet = *pSet;
            std::set<NiAVObjectPtr>::iterator itEnd = kSet.end();
            for (std::set<NiAVObjectPtr>::iterator it = kSet.begin(); it != itEnd; ++it)
            {
                efd::SmartPointer<NiAVObject> spMesh = *it;
                NiAVObject* pFound = spMesh->GetObjectByName("HR:0");
                if (pFound == 0)
                {
                    pFound = spMesh->GetObjectByName("HR0:0");
                    if (bTrack != 0)
                    {
                        if (m_spPicker->m_spMesh.FUN_141412c90() != pFound)
                            pFound = 0;
                    }
                }
                if (pFound == 0)
                {
                    pFound = spMesh->GetObjectByName("HR1:1");
                    if (bTrack != 0)
                    {
                        if (m_spPicker->m_spMesh.FUN_141412c90() != pFound)
                            pFound = 0;
                        else
                            m_nCurIndex = 1;
                    }
                }
                if (pFound != 0)
                {
                    if (bTrack != 0 && m_spPicker->m_spMesh.FUN_141412c90() != pFound)
                        continue;
                    NiTimeController* pTime = pFound->GetControllers();
                    while (pTime != 0)
                    {
                        NiObject* pCtrl = NiObject::DynamicCast(&NiMorphWeightsController::ms_RTTI, (class NiObject const*)(pTime));
                        if (pCtrl != 0)
                            return (NiInterpController*)pCtrl;
                        pTime = pTime->GetNext();
                    }
                }
            }
        }
    }
    else
    {
        if (aParts.GetCount() > 0)
        {
            MS2Ptr<Unk_PickTarget> spPart = m_spEquipItem->FUN_1411dc950(aParts.GetAt(0));
            std::set<NiAVObjectPtr>* pSet = FUN_141201c90(spPart.operator->());
            std::set<NiAVObjectPtr>& kSet = *pSet;
            std::set<NiAVObjectPtr>::iterator itEnd = kSet.end();
            for (std::set<NiAVObjectPtr>::iterator it = kSet.begin(); it != itEnd; ++it)
            {
                efd::SmartPointer<NiAVObject> spMesh = *it;
                NiAVObject* pFound = spMesh->GetObjectByName("Editable Mesh");
                if (pFound == 0)
                    pFound = spMesh->GetObjectByName("Editable Poly");
                if (pFound != 0)
                {
                    NiTimeController* pTime = pFound->GetControllers();
                    while (pTime != 0)
                    {
                        NiObject* pCtrl = NiObject::DynamicCast(&NiMorphWeightsController::ms_RTTI, (class NiObject const*)(pTime));
                        if (pCtrl != 0)
                            return (NiInterpController*)pCtrl;
                        pTime = pTime->GetNext();
                    }
                }
            }
        }
    }
    return 0;
}

// @0x141418550
NiInterpController* CItemMorphController::SelectMorphController(int nIndex)
{
    m_nCurIndex = nIndex;
    {
        efd::SmartPointer<NiAVObject> spNode = FindMorphNode(nIndex);
        if ((NiAVObject*)spNode != 0)
        {
            NiTimeController* pTime = spNode->GetControllers();
            while (pTime != 0)
            {
                NiInterpController* pCtrl = (NiInterpController*)NiObject::DynamicCast(&NiMorphWeightsController::ms_RTTI, (class NiObject const*)(pTime));
                if (pCtrl != 0)
                    return pCtrl;
                pTime = pTime->GetNext();
            }
        }
    }
    return 0;
}

// @0x141418620
efd::SmartPointer<NiAVObject> CItemMorphController::FindMorphNode(int nIndex)
{
    void* pPlayer = WorldService::GetInstance()->FUN_141bd0cc0();
    if (pPlayer != 0)
    {
        CAtlArray<CString> aParts;
        m_spEquipItem->FUN_1411dca30(m_nSlot, aParts);
        if (aParts.GetCount() > 0)
        {
            MS2Ptr<Unk_PickTarget> spPart = m_spEquipItem->FUN_1411dc950(aParts.GetAt(0));
            NiAVObject* pFound = 0;
            std::set<NiAVObjectPtr>* pSet = FUN_141201c90(spPart.operator->());
            std::set<NiAVObjectPtr>& kSet = *pSet;
            std::set<NiAVObjectPtr>::iterator itEnd = kSet.end();
            for (std::set<NiAVObjectPtr>::iterator it = kSet.begin(); it != itEnd; ++it)
            {
                efd::SmartPointer<NiAVObject> spMesh = *it;
                if (m_nSlot == 1)
                {
                    pFound = spMesh->GetObjectByName("HR:0");
                    if (pFound == 0)
                    {
                        if (nIndex == 0)
                            pFound = spMesh->GetObjectByName("HR0:0");
                        else
                            pFound = spMesh->GetObjectByName("HR1:1");
                    }
                }
                else
                {
                    pFound = spMesh->GetObjectByName("Editable Mesh");
                    if (pFound == 0)
                        pFound = spMesh->GetObjectByName("Editable Poly");
                }
                if (pFound != 0)
                    return efd::SmartPointer<NiAVObject>(pFound);
            }
        }
    }
    return efd::SmartPointer<NiAVObject>(0);
}

// @0x141418a00
Unk_PickMeshPtr& Unk_PickMeshPtr::FUN_141418a00(NiAVObject* p)
{
    if (m_p != p)
    {
        if (m_p != 0)
            m_p->DecRefCount();
        m_p = p;
        if (m_p != 0)
            ((class NiRefObject*)(void*)(m_p))->IncRefCount();
    }
    return *this;
}

MS2_EMIT_CRT_MEMMOVE_S();
