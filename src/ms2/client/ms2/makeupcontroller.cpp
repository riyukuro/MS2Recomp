// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CMakeupController, the customize controller of the face
// makeup slot (equip slot 3): edits the x / y / angle / scale values of the face mesh's NiFloatsExtraData.
// MS2-UNIT: ?\makeupcontroller.cpp
// MS2-RANGE: 0x1414762e0-0x141478090 .text$mn
// MS2-RANGE: 0x1400f7b70-0x1400f7d10 .text$di
// MS2-RANGE: 0x142cb27c0-0x142cb2850 .text$yd
// MS2-PIN: ?GetRTTI@CMakeupController@@UEBAPEBVNiRTTI@@XZ 0x141477ff0 ; manual
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\makeupcontroller.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "makeupcontroller.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/nipoint3.h"
#include <efd/MemObject.h>
#include <efd/MemHint.h>
#include <NiAVObject.h>
#include <NiFixedString.h>
#include <NiFloatsExtraData.h>
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- exe data ----
extern char DAT_143afafe0;      // NiFloatsExtraData::ms_RTTI
extern char DAT_143afa7d0;      // NiRenderObject::ms_RTTI (the face mesh class)
extern char DAT_143ae50f8;      // the extra data key of the makeup values (a static NiFixedString)

// ---- out-of-unit callees ----

// Item data flags (item -> data struct -> flags).
struct Unk_MakeupItemData
{
    unsigned char FUN_140547130();                              // customizing allowed
    unsigned char FUN_140547150();                              // right button allowed
    unsigned char FUN_140547170();                              // left button allowed
};

// One makeup preset: the x / y values it sets (+0x18 / +0x1c).
struct Unk_MakeupPreset
{
    char m_pad_00[0x18];
    float m_fX;                                                 // +0x18
    float m_fY;                                                 // +0x1c
};
// A 16-byte MS2Ptr-shaped handle to a preset (pointer at +8).
struct Unk_MakeupPresetPtr
{
    Unk_MakeupPreset* FUN_1401e4e80();                          // operator->
};
// The preset list (a vector of 16-byte handles).
struct Unk_MakeupPresetList
{
    int FUN_1401e5720();                                        // number of presets
    Unk_MakeupPresetPtr* FUN_14059ce40(__int64 nIndex);         // preset nIndex
};
struct Unk_MakeupPresetOwner { Unk_MakeupPresetList* FUN_1401e41c0(); };   // its preset list (+0x30)
// The value ranges of the makeup (the same item data section as CItemMorphController).
struct Unk_MakeupRangeList { const Unk_CustomizeRange* FUN_140544f20(size_t nIndex); };
struct Unk_MakeupSection
{
    Unk_MakeupRangeList* FUN_14054b2f0(int nKind);              // value ranges
    Unk_MakeupPresetOwner* FUN_14054b6b0();                     // presets
};
struct Unk_MakeupItem
{
    Unk_MakeupItemData* FUN_14053ec70();                        // item -> item data struct
    Unk_MakeupSection* FUN_14053eba0();                         // item -> data section
};

class CEquipItem : public CPtred
{
public:
    Unk_MakeupItem* FUN_1411dc7f0();                            // the item
    MS2Ptr<CItem> GetItem();                              // the item object holding the proxy data
};

// The proxy data of the item (CItem::FUN_140527870): the four makeup values at +0x58..+0x64 (x, y, scale, angle).
struct Unk_MakeupProxyData
{
    char m_pad_00[0x58];
    float m_fX;                                                 // +0x58
    float m_fY;                                                 // +0x5c
    float m_fScale;                                             // +0x60
    float m_fAngle;                                             // +0x64
};
Unk_MakeupProxyData* FUN_140527870(CItem* pItem);
int FUN_140527a20(CItem* pItem);                                // item model kind (3 = face makeup)
void FUN_14059a1f0(Unk_MakeupProxyData* pData, int nValue);     // stores the preset index
int FUN_14059a210(Unk_MakeupProxyData* pData);                  // reads it

// The local player.
namespace egf { class Entity; }
struct Unk_MakeupPlayer { egf::Entity* FUN_14123c410(); };
struct Unk_MakeupWorld { Unk_MakeupPlayer* FUN_141bd0cc0(); };
Unk_MakeupWorld* FUN_1403ed2d0();
void* FUN_1416561a0(Unk_MakeupPlayer* pPlayer);                 // the player's customize state
void FUN_1411ea2e0(void* pState, bool bOn);                     // enables / disables the customize preview
NiAVObject* FUN_141b6efc0(egf::Entity* pEntity);                // the entity's scene root

NiObject* FUN_14098d8d0(const NiRTTI* pRTTI, NiObject* pObject);   // dynamic cast (NULL-safe)
NiExtraData* FUN_141d17b40(NiAVObject* pNode, const void* pName);  // extra data by name
float FUN_141d57ca0(NiFloatsExtraData* pExtra, int nIndex);     // NiFloatsExtraData value
void FUN_141d580c0(NiFloatsExtraData* pExtra, int nIndex, float fValue);   // sets it
float FUN_140768090();                                          // random float in [0, 1]
float FUN_140a17940(float fValue, float fMin, float fMax);      // clamp

struct Unk_MakeupCursor { int FUN_141b90e30(float* pX, float* pY); };   // cursor position in pixels
Unk_MakeupCursor* FUN_140aadf80();

struct Unk_MakeupConfigFloat { float FUN_1402bac70(); char m_pad[0x58]; };
struct Unk_MakeupConfig
{
    char m_pad_0000[0x2de8];
    Unk_MakeupConfigFloat m_2de8;                               // wheel step
    Unk_MakeupConfigFloat m_2e40;                               // drag scale
};
Unk_MakeupConfig* FUN_1401d3200();

// Listener at +0xa0: slots 1 to 4 are called by this controller (the base class only knows slot 0).
class Unk_MakeupListener
{
public:
    virtual void vfunc_0(CItemCustomizeController* pController, int nValue);
    virtual void vfunc_1(CItemCustomizeController* pController);                                // drag begin
    virtual void vfunc_2(CItemCustomizeController* pController, float fValue, int nIndex);      // value changed
    virtual void vfunc_3(CItemCustomizeController* pController, float fDegrees);                // angle changed
    virtual void vfunc_4(CItemCustomizeController* pController, Vector3 kPos);          // x / y changed
};

// This unit's free functions.
void FUN_141477cb0(NiFloatsExtraData* pExtra, Unk_MakeupProxyData* pData);       // proxy data -> face mesh values
void FUN_141477d40(Unk_MakeupProxyData* pData, NiFloatsExtraData* pExtra);       // face mesh values -> proxy data
int FUN_141477dd0(MS2Ptr<CEquipItem> spItem);                                   // number of presets of the item

// The NiFloatsExtraData of the face mesh. Written out in every use in the exe.
#define MAKEUP_FACE_EXTRA() \
    ((NiFloatsExtraData*)FUN_14098d8d0((const NiRTTI*)&DAT_143afafe0, FUN_141d17b40(m_spFaceMesh.operator->(), &DAT_143ae50f8)))

// NiImplementRTTI(CMakeupController, CItemCustomizeController). The hook DLL binds the exe's copy (symbols.tsv row),
// so only the byte-match build defines it.
#ifndef MS2_HOOK_DLL
// @0x1400f7b70
const NiRTTI CMakeupController::ms_RTTI("CMakeupController", &CItemCustomizeController::ms_RTTI);
#endif
// The header statics every TU of this group carries (see mainsystem.cpp); atexit thunks 0x142cb27c0-0x142cb2850.
// @0x1400f7ba0
static CString s_strSortTypeNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
// @0x1400f7c60
static CString s_strSkill = "skill";
// @0x1400f7c90
static CString s_strStun = "stun";
// @0x1400f7cc0
static Unk_1402a9d70 s_unk1402a9d70(17, 0.75f, 0.25f, 2.25f, 10);

// @0x1414762e0
CMakeupController::CMakeupController()
    : m_fWheelStep(1.0f)
    , m_fDragScale(1.0f)
    , m_fDragStartX(0.0f)
    , m_fDragStartAngle(0.0f)
    , m_spFaceMesh(0)
    , m_spScale(0)
    , m_nPresetIndex(-1)
{
    m_bUseButton1 = 1;
    m_bUseButton2 = 1;
    m_bEnabled = 1;
}

// @0x1414763d0
CMakeupController::~CMakeupController()
{
}

// @0x141476430
int CMakeupController::vfunc_3()
{
    m_bUseButton1 = m_spEquipItem->FUN_1411dc7f0()->FUN_14053ec70()->FUN_140547170();
    m_bUseButton2 = m_spEquipItem->FUN_1411dc7f0()->FUN_14053ec70()->FUN_140547150();
    m_bEnabled = m_spEquipItem->FUN_1411dc7f0()->FUN_14053ec70()->FUN_140547130();
    m_spScale = new (efd::MemHint(efd::MemHint::NONE)) CScaleModifier;
    m_fWheelStep = FUN_1401d3200()->m_2de8.FUN_1402bac70();
    m_fDragScale = FUN_1401d3200()->m_2e40.FUN_1402bac70();
    FindFaceMesh();
    LoadFromProxy();
    m_spPicker->SetPrevMesh(m_spFaceMesh.FUN_141412c90());
    return 1;
}

// @0x1414765f0
void CMakeupController::vfunc_4()
{
    vfunc_13(MS2Ptr<CEquipItem>(0));
    CItemCustomizeController::vfunc_4();
    UpdateScaleAnimation();
}

// @0x141476650
void CMakeupController::vfunc_5()
{
    SaveToProxy();
    SetPreviewApply(true);
}

// @0x141476680
void CMakeupController::vfunc_6()
{
    LoadFromProxy();
    SetPreviewApply(true);
}

// @0x1414766b0
float CMakeupController::vfunc_18()
{
    NiFloatsExtraData* pExtra = MAKEUP_FACE_EXTRA();
    if (pExtra != 0)
    {
        float f = FUN_141d57ca0(pExtra, 2);
        return f * 180.0f / 3.1415927f;
    }
    return 0.0f;
}

// @0x141476740
const Unk_CustomizeRange* CMakeupController::vfunc_23()
{
    return m_spEquipItem->FUN_1411dc7f0()->FUN_14053eba0()->FUN_14054b2f0(0)->FUN_140544f20(0);
}

// @0x141476790
float CMakeupController::vfunc_19()
{
    return vfunc_23()->m_fMin;
}

// @0x1414767c0
float CMakeupController::vfunc_20()
{
    return vfunc_23()->m_fMax;
}

// @0x1414767f0
void CMakeupController::vfunc_25(float* pfMin, float* pfMax)
{
    const Unk_CustomizeRange* pRange = vfunc_23();
    *pfMin = pRange->m_fMin;
    *pfMax = pRange->m_fMax;
}

// @0x141476850
int CMakeupController::vfunc_17()
{
    return m_nPresetIndex;
}

// @0x141476870
void CMakeupController::vfunc_14(float fValue)
{
    if (m_spEquipItem.get() != 0)
    {
        if (IsEnabled() != 0)
            vfunc_42(fValue, 0);
    }
}

// @0x1414768d0
// MS2-FUNCTIONAL: min/max/rand temp order and slot layout differ from the exe frame
void CMakeupController::vfunc_16()
{
    if (m_spEquipItem.get() != 0)
    {
        Unk_MakeupItem* pItem = m_spEquipItem->FUN_1411dc7f0();
        if (pItem != 0)
        {
            NiFloatsExtraData* pExtra = MAKEUP_FACE_EXTRA();
            if (pExtra != 0)
            {
                if (pItem->FUN_14053ec70()->FUN_140547130() != 0)
                {
                    float fMin = vfunc_19();
                    float fMax = vfunc_20();
                    vfunc_42(FUN_140768090() * (fMax - fMin) + fMin, pExtra);
                }
                if (pItem->FUN_14053ec70()->FUN_140547150() != 0)
                {
                    float fRand = FUN_140768090();
                    vfunc_43(fRand * 2.0f * 3.1415927f - 3.1415927f, pExtra);
                }
                if (pItem->FUN_14053ec70()->FUN_140547170() != 0)
                {
                    float fX = FUN_140768090();
                    float fY = FUN_140768090();
                    fX = fX - 0.5f;
                    fY = (1.0f - fY) - 0.5f;
                    vfunc_44(fX, fY, pExtra);
                    m_nPresetIndex = FUN_141477dd0(m_spEquipItem);
                }
            }
        }
    }
}

// @0x141476b60
void CMakeupController::vfunc_13(MS2Ptr<CEquipItem> spOld)
{
    FindFaceMesh();
    if (m_spFaceMesh.FUN_141412c90() != 0)
        m_spPicker->SetPrevMesh(m_spFaceMesh.FUN_141412c90());
}

// @0x141476bf0
void CMakeupController::vfunc_10(float fDegrees)
{
    vfunc_43(fDegrees * 3.1415927f / 180.0f, 0);
}

// @0x141476c40
void CMakeupController::vfunc_9(int nIndex)
{
    if (nIndex >= 0)
    {
        Unk_MakeupPresetOwner* pOwner = m_spEquipItem->FUN_1411dc7f0()->FUN_14053eba0()->FUN_14054b6b0();
        if (pOwner != 0)
        {
            Unk_MakeupPresetList* pList = pOwner->FUN_1401e41c0();
            if (pList->FUN_1401e5720() > nIndex)
            {
                Unk_MakeupPresetPtr* pPreset = pList->FUN_14059ce40(nIndex);
                vfunc_44(pPreset->FUN_1401e4e80()->m_fX, pPreset->FUN_1401e4e80()->m_fY, 0);
            }
        }
        m_nPresetIndex = nIndex;
    }
}

// @0x141476d30
int CMakeupController::vfunc_29()
{
    return 1;
}

// @0x141476d50
// MS2-FUNCTIONAL: CString temp layout differs (named temps vs the exe frame)
void CMakeupController::vfunc_28()
{
    m_aPartNames.RemoveAll();
    CString strPart("FA_Skin");
    m_aPartNames.Add(strPart);
    m_aMeshNames.RemoveAll();
    CString strMesh("FA_Skin");
    m_aMeshNames.Add(strMesh);
}

// @0x141476e00
float CMakeupController::vfunc_40()
{
    return m_fWheelStep;
}

// @0x141476e20
void CMakeupController::vfunc_30(const NiPoint3& kPos)
{
    CItemCustomizeController::vfunc_30(kPos);
    m_nPresetIndex = FUN_141477dd0(m_spEquipItem);
    if (m_pListener != 0)
        reinterpret_cast<Unk_MakeupListener*>(m_pListener)->vfunc_1(this);
}

// @0x141476ec0
void CMakeupController::vfunc_32(const NiPoint3& kHit, const NiPoint3& kNormal, const NiPoint2& kUV, float fValue)
{
    float fX = kUV.x - 0.5f;
    float fY = kUV.y - 0.5f;
    vfunc_44(fX, fY, 0);
}

// @0x141476f40
// MS2-FUNCTIONAL: exe loads the Start() arg via movaps; source shape not recovered
void CMakeupController::vfunc_33()
{
    NiFloatsExtraData* pExtra = MAKEUP_FACE_EXTRA();
    if (pExtra != 0)
    {
        m_spScale->SetMaxScale(0.8f);
        m_spScale->SetDuration(0.35f);
        if (m_spScale->IsRunning())
        {
            float fBase = m_spScale->GetOriginalScale();
            m_spScale->Start(fBase);
        }
        else
        {
            float fScale = FUN_141d57ca0(pExtra, 3);
            m_spScale->Start(fScale);
        }
    }
}

// @0x141477080
// MS2-FUNCTIONAL: exe frame/temp layout (MS2Ptr by-value temp for the item) differs
void CMakeupController::vfunc_42(float fValue, NiFloatsExtraData* pExtra)
{
    if (pExtra == 0)
        pExtra = MAKEUP_FACE_EXTRA();
    if (pExtra != 0)
    {
        const Unk_CustomizeRange* pRange = vfunc_23();
        m_afValue[m_nCurIndex] = FUN_140a17940(fValue, pRange->m_fMin, pRange->m_fMax);
        float fNow = vfunc_21();
        FUN_141d580c0(pExtra, 3, fNow);
        Unk_MakeupProxyData* pData = FUN_140527870((CItem*)m_spEquipItem->GetItem());
        if (pData != 0)
            pData->m_fScale = fNow;
        if (m_pListener != 0)
            reinterpret_cast<Unk_MakeupListener*>(m_pListener)->vfunc_2(this, fNow, 0);
    }
}

// @0x141477260
// MS2-FUNCTIONAL: exe frame/temp layout (MS2Ptr by-value temp for the item) differs
void CMakeupController::vfunc_43(float fRadians, NiFloatsExtraData* pExtra)
{
    if (pExtra == 0)
        pExtra = MAKEUP_FACE_EXTRA();
    if (pExtra != 0)
    {
        if (FUN_141d57ca0(pExtra, 2) != fRadians)
        {
            FUN_141d580c0(pExtra, 2, fRadians);
            Unk_MakeupProxyData* pData = FUN_140527870((CItem*)m_spEquipItem->GetItem());
            if (pData != 0)
                pData->m_fAngle = fRadians;
            if (m_pListener != 0)
                reinterpret_cast<Unk_MakeupListener*>(m_pListener)->vfunc_3(this, fRadians * 180.0f / 3.1415927f);
        }
    }
}

// @0x1414773d0
// MS2-FUNCTIONAL: exe frame/temp layout (MS2Ptr by-value temp for the item) differs
void CMakeupController::vfunc_44(float fX, float fY, NiFloatsExtraData* pExtra)
{
    if (pExtra == 0)
        pExtra = MAKEUP_FACE_EXTRA();
    if (pExtra != 0)
    {
        FUN_141d580c0(pExtra, 0, fX);
        FUN_141d580c0(pExtra, 1, fY);
        Unk_MakeupProxyData* pData = FUN_140527870((CItem*)m_spEquipItem->GetItem());
        if (pData != 0)
        {
            pData->m_fX = fX;
            pData->m_fY = fY;
        }
        if (m_pListener != 0)
            reinterpret_cast<Unk_MakeupListener*>(m_pListener)->vfunc_4(this, Vector3(fX, fY, 0.0f));
    }
}

// @0x141477590
void CMakeupController::vfunc_34(const NiPoint3& kPos)
{
    float fY;
    FUN_140aadf80()->FUN_141b90e30(&m_fDragStartX, &fY);
    NiFloatsExtraData* pExtra = MAKEUP_FACE_EXTRA();
    if (pExtra != 0)
    {
        m_fDragStartAngle = FUN_141d57ca0(pExtra, 2) * 180.0f / 3.1415927f;
    }
}

// @0x141477640
void CMakeupController::vfunc_35()
{
    float fX;
    float fDelta;
    float fScaled;
    float fAngle;
    float fY;
    FUN_140aadf80()->FUN_141b90e30(&fX, &fY);
    fDelta = fX - m_fDragStartX;
    fScaled = fDelta * m_fDragScale;
    NiFloatsExtraData* pExtra = MAKEUP_FACE_EXTRA();
    fAngle = (m_fDragStartAngle + fScaled) * 3.1415927f / 180.0f;
    vfunc_43(fAngle, pExtra);
}

// @0x141477720
void CMakeupController::vfunc_36()
{
}

// @0x141477730
void CMakeupController::SetPreviewApply(bool bOn)
{
    Unk_MakeupPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer != 0)
        FUN_1411ea2e0(FUN_1416561a0(pPlayer), bOn);
}

// @0x141477780
// MS2-FUNCTIONAL: exe frame/temp layout (MS2Ptr by-value temp for the item) differs
// Writes the face mesh values and the preset index back to the item's proxy data.
void CMakeupController::SaveToProxy()
{
    if (m_spEquipItem.get() == 0)
        return;
    bool bFace = m_spEquipItem.get() != 0 && FUN_140527a20((CItem*)m_spEquipItem->GetItem()) == 3;
    if (bFace && m_spFaceMesh.FUN_141412c90() != 0)
    {
        NiFloatsExtraData* pExtra = MAKEUP_FACE_EXTRA();
        Unk_MakeupProxyData* pData = FUN_140527870((CItem*)m_spEquipItem->GetItem());
        FUN_141477d40(pData, pExtra);
        FUN_14059a1f0(pData, m_nPresetIndex);
    }
}

// @0x141477960
// MS2-FUNCTIONAL: exe frame/temp layout (MS2Ptr by-value temp for the item) differs
// Reads the proxy data of the item into the face mesh values.
void CMakeupController::LoadFromProxy()
{
    if (m_spEquipItem.get() != 0)
    {
        int nKind = FUN_140527a20((CItem*)m_spEquipItem->GetItem());
        if (nKind == 3 && m_spFaceMesh.FUN_141412c90() != 0)
        {
            Unk_MakeupProxyData* pData = FUN_140527870((CItem*)m_spEquipItem->GetItem());
            FUN_141477cb0(MAKEUP_FACE_EXTRA(), pData);
            if (pData != 0)
            {
                m_nPresetIndex = FUN_14059a210(pData);
                m_afValue[m_nCurIndex] = pData->m_fScale;
            }
        }
    }
}

// @0x141477b20
void CMakeupController::UpdateScaleAnimation()
{
    if (m_spScale->Update() != false)
    {
        float fScale = m_spScale->GetCurrentScale();
        NiFloatsExtraData* pExtra = MAKEUP_FACE_EXTRA();
        if (pExtra != 0)
            FUN_141d580c0(pExtra, 3, fScale);
    }
}

// @0x141477bd0
void CMakeupController::FindFaceMesh()
{
    m_spFaceMesh.FUN_141418a00(0);
    Unk_MakeupPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer != 0)
    {
        SetPreviewApply(false);
        NiAVObject* pRoot = FUN_141b6efc0(pPlayer->FUN_14123c410());
        if (pRoot != 0)
        {
            NiFixedString kName("FA_Skin");
            m_spFaceMesh.FUN_141418a00((NiAVObject*)FUN_14098d8d0((const NiRTTI*)&DAT_143afa7d0, pRoot->GetObjectByName(kName)));
        }
    }
}

// @0x141477cb0
void FUN_141477cb0(NiFloatsExtraData* pExtra, Unk_MakeupProxyData* pData)
{
    if (pData != 0 && pExtra != 0)
    {
        FUN_141d580c0(pExtra, 0, pData->m_fX);
        FUN_141d580c0(pExtra, 1, pData->m_fY);
        FUN_141d580c0(pExtra, 2, pData->m_fAngle);
        FUN_141d580c0(pExtra, 3, pData->m_fScale);
    }
}

// @0x141477d40
void FUN_141477d40(Unk_MakeupProxyData* pData, NiFloatsExtraData* pExtra)
{
    if (pData != 0 && pExtra != 0)
    {
        pData->m_fX = FUN_141d57ca0(pExtra, 0);
        pData->m_fY = FUN_141d57ca0(pExtra, 1);
        pData->m_fAngle = FUN_141d57ca0(pExtra, 2);
        pData->m_fScale = FUN_141d57ca0(pExtra, 3);
    }
}

// @0x141477dd0
int FUN_141477dd0(MS2Ptr<CEquipItem> spItem)
{
    if (spItem.get() != 0)
    {
        Unk_MakeupPresetOwner* pOwner = spItem->FUN_1411dc7f0()->FUN_14053eba0()->FUN_14054b6b0();
        if (pOwner != 0)
        {
            return pOwner->FUN_1401e41c0()->FUN_1401e5720();
        }
    }
    return 0;
}

MS2_REPLACE_METHOD(0x141476430, CMakeupController, vfunc_3, 429, 0x73B2E760);
MS2_REPLACE_METHOD(0x1414765F0, CMakeupController, vfunc_4, 82, 0x38A24B26);
MS2_REPLACE_METHOD(0x141476650, CMakeupController, vfunc_5, 36, 0xC859747D);
MS2_REPLACE_METHOD(0x141476680, CMakeupController, vfunc_6, 36, 0xC6BDD9C6);
MS2_REPLACE_METHOD(0x1414766B0, CMakeupController, vfunc_18, 124, 0x3CAB6A8D);
MS2_REPLACE_METHOD(0x141476740, CMakeupController, vfunc_23, 67, 0x33D60620);
MS2_REPLACE_METHOD(0x141476790, CMakeupController, vfunc_19, 38, 0xDFEA221F);
MS2_REPLACE_METHOD(0x1414767C0, CMakeupController, vfunc_20, 37, 0x12943AED);
MS2_REPLACE_METHOD(0x1414767F0, CMakeupController, vfunc_25, 85, 0x443EF96E);
MS2_REPLACE_METHOD(0x141476850, CMakeupController, vfunc_17, 17, 0xD382A09B);
MS2_REPLACE_METHOD(0x141476870, CMakeupController, vfunc_14, 84, 0x281EDFEA);
MS2_REPLACE_METHOD(0x1414768D0, CMakeupController, vfunc_16, 648, 0x58B89652);
MS2_REPLACE_METHOD(0x141476BF0, CMakeupController, vfunc_10, 67, 0xCA36C133);
MS2_REPLACE_METHOD(0x141476C40, CMakeupController, vfunc_9, 224, 0x35AFCA44);
MS2_REPLACE_METHOD(0x141476D50, CMakeupController, vfunc_28, 163, 0x36C80BAE);
MS2_REPLACE_METHOD(0x141476E00, CMakeupController, vfunc_40, 19, 0x50C39DE0);
MS2_REPLACE_METHOD(0x141476E20, CMakeupController, vfunc_30, 142, 0x77E541A2);
MS2_REPLACE_METHOD(0x141476EC0, CMakeupController, vfunc_32, 110, 0x33A6C730);
MS2_REPLACE_METHOD(0x141476F40, CMakeupController, vfunc_33, 309, 0xEAA1F384);
MS2_REPLACE_METHOD(0x141477080, CMakeupController, vfunc_42, 462, 0x1C504909);
MS2_REPLACE_METHOD(0x141477260, CMakeupController, vfunc_43, 357, 0x493906A1);
MS2_REPLACE_METHOD(0x1414773D0, CMakeupController, vfunc_44, 439, 0x20BDA905);
MS2_REPLACE_METHOD(0x141477590, CMakeupController, vfunc_34, 167, 0x4219F4EF);
MS2_REPLACE_METHOD(0x141477640, CMakeupController, vfunc_35, 212, 0x600A29AC);
MS2_REPLACE_METHOD(0x141477730, CMakeupController, SetPreviewApply, 67, 0x2403F66D);
MS2_REPLACE_METHOD(0x141477780, CMakeupController, SaveToProxy, 468, 0x8FCFCD58);
MS2_REPLACE_METHOD(0x141477960, CMakeupController, LoadFromProxy, 431, 0x4F149344);
MS2_REPLACE_METHOD(0x141477B20, CMakeupController, UpdateScaleAnimation, 164, 0x5C05F753);
MS2_REPLACE_METHOD(0x141477BD0, CMakeupController, FindFaceMesh, 205, 0x6070503A);
