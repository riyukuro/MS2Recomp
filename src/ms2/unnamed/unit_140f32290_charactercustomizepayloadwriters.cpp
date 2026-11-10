// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The item-colour / customize payload writers of the
// character shops: they fill the AS object a shop row uses with the colour palette, the size / rotation / position
// pickers of the customize controller and the item row (name, icon, movie). Callers: UIBeautyShopDialog,
// UIBeautyShopStyleDialog and UICharacterCreateDialog. The .text$di part is the string tables of three headers
// (the sort names), "skill", "stun", a marker and the key input controller static.
// MS2-UNIT: unit_140f32290
// MS2-RANGE: 0x1400dea20-0x1400ded40 .text$di
// MS2-RANGE: 0x140f32290-0x140f345b0 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include <atlcoll.h>
#include <vector>
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/cequipitem.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/placeholder/itemcustom.h"
#include "ms2/placeholder/characterdecaldata.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/commonfiles/itemdatatable.h"
#include "ms2/commonfiles/featuremanager.h"
#include "ms2/client/ms2/uibeautyshopstyledialog.h"
#include "ms2/client/ms2/itemcustomizecontroller_1.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/client/ms2/customize.h"

MS2_EMIT_CRT_MEMMOVE_S();

// ---- unit-local views of exe objects ----

// The world service: only the local player accessor is used here.
class Unk_140166410* FUN_140166410();   // C3: was FUN_140166410
int FUN_140f02bc0();                                            // the hair palette id
CStringW FUN_141b71990(unsigned nValue);

// The item an equipped slot shows; the model block of an item row.
// The customize controller reports the item it edits (a CItem handle).
class Unk_CustomizeView : public Customize
{
};

// The part handle (an efd::SmartPointer<CItemCustomizeController>, 8 bytes).

// The worn item / colour helpers of the avatar units.
MS2Ptr<CEquipItem> FUN_1414211a0(int nSlotKind, class AvatarPC* pPc);       // the worn item of the kind (C3: the definer's signature, unit_1414210f0)
int FUN_1414239e0(unsigned int*, int, struct Unk_UgcPlayer*);   // C3: was FUN_1414239e0
int FUN_141424580(MS2Ptr<CEquipItem> spEquip, unsigned int* pnColor, int n);        // the colour of the worn item (spEquip by value; itemugcmesh.cpp's signature)
int FUN_141424760(MS2Ptr<CItem> spItem, unsigned int* pnColor, int n, struct Unk_UgcPlayer* pPlayer);   // the colour of an item (spItem by value; itemugcmesh.cpp's signature)
bool FUN_140f026f0(MS2Ptr<ItemColorEx> spColor, bool* pbLocked);            // the colour is locked

typedef ATL::CAtlArray<MS2Ptr<ItemColorEx> > ColorArray;
typedef Unk_BmBoxPtr<ColorArray> ColorArrayPtr;

// ---- dynamic initializers (.text$di) ----

// @0x1400dea20
static CString s_sort7a[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};

// @0x1400deae0
static CString s_skill("skill");

// @0x1400deb10
static CString s_stun("stun");

#ifndef MS2_HOOK_DLL
// @0x1400deb40
struct Unk_RegMarker {};
#include "ms2/placeholder/unk_1402a9d70.h"
static Unk_1402a9d70 s_marker(17, 0.75f, 0.25f, 2.25f, 10);   // atexit thunk FUN_142ca92e0
#endif

// @0x1400deb90
static CString s_sort7b[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};

// @0x1400dec50
static UICommon::CMyPCKeyInputController s_keyInput;

// @0x1400dec80
static CString s_sort7c[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};

// ---- .text$mn ----

int FUN_140f32290(ASObj& obj, MS2Ptr<CItemData> spItem, MS2Ptr<Customize> spCustomize, unsigned nFlags, int n, bool bColor);
void FUN_140f327a0(MS2Ptr<CItemData> spData, int nPalette, ASObj& obj, int n);
void FUN_140f328a0(MS2Ptr<Customize> spCustomize, ASObj& obj, int n);
void FUN_140f32a70(MS2Ptr<CItemData> spData, MS2Ptr<Customize> spCustomize, ASObj& obj, unsigned* pnFlags);
void FUN_140f33570(MS2Ptr<CItemData> spData, int* pnColor1, int* pnColor2);
void FUN_140f337a0(MS2Ptr<CItem> spItem, int* pnColor1, int* pnColor2);
void FUN_140f33950(ASArray& arr, int* pnIndex, int nColor1, int nColor2, MS2Ptr<CItemData> spData, int nPalette,
                   ColorArrayPtr spColors, bool bBuild);
void FUN_140f33d80(int nColor1, int nColor2, MS2Ptr<CItemData> spData, int nPalette, ASObj& obj, int nFlags);

// The item list row's colour / option payload.
// @0x140f32290
int FUN_140f32290(ASObj& obj, MS2Ptr<CItemData> spItem, MS2Ptr<Customize> spCustomize, unsigned nFlags, int n, bool bColor)
{
    if ((nFlags & 1) != 0)
    {
        if (spItem->IsAvatarColorItem())
        {
            int nPalette = spItem->FUN_14053e260();
            FUN_140f327a0(MS2Ptr<CItemData>(spItem), nPalette, obj, n);
        }
        else
        {
            if (((CItemData*)spItem)->FUN_14053ec70()->FUN_140547190())
                FUN_140f328a0(MS2Ptr<Customize>(spCustomize), obj, n);
        }
    }
    if ((nFlags & 2) != 0)
    {
        ASObj kOption(2);
        unsigned nOption = 0;
        FUN_140f32a70(MS2Ptr<CItemData>(spItem), MS2Ptr<Customize>(spCustomize), kOption, &nOption);
        obj.FUN_1409adbe0("option", Scaleform::GFx::Value(kOption.GetValue()));
        ((class AScript&)(obj)).SetIntMember("optionflag", (int)nOption);
    }
    return 1;
}
MS2_REPLACE(0x140F32290, FUN_140f32290, 592, 0xD7B14785);

// A list row of an item: name, id, icon, movie.
// @0x140f324f0
void FUN_140f324f0(ASObj& obj, MS2Ptr<CItemData> spData, bool bMovie)
{
    if (spData == 0)
        return;
    int nId = spData->GetItemId();
    CStringW strName = TSingleton<CStringTable>::GetInstance()->FUN_141811980(1, nId);
    ((class AScript&)(obj)).SetWStringMember("itemname", CStringW(strName));
    ((class AScript&)(obj)).SetWStringMember("itemid", FUN_141b71990(nId));
    obj.SetStringMember("iconpath", spData->GetIconPath());
    obj.SetBoolMember("editable", ((CItemData*)spData)->FUN_14053ec70()->FUN_1405471d0());
    bool bSkinBg = spData->GetModelOrEmpty()->GetFirstGroupType() == 2 || spData->GetModelOrEmpty()->GetFirstGroupType() == 3;
    obj.SetBoolMember("isSkinBg", bSkinBg);
    obj.SetBoolMember("isHideSlot", spData->IsAvatarColorItem());
    if (bMovie)
        obj.SetStringMember("itemmovie", CString(spData->property.movie));
    else
        obj.FUN_1409c0dc0("itemmovie", "");
}
MS2_REPLACE(0x140F324F0, FUN_140f324f0, 681, 0xAFB2C614);

// @0x140f327a0
void FUN_140f327a0(MS2Ptr<CItemData> spData, int nPalette, ASObj& obj, int n)
{
    if (spData == 0)
        return;
    int nColor1 = 0;
    int nColor2 = 0;
    FUN_140f33570(MS2Ptr<CItemData>(spData), &nColor1, &nColor2);
    FUN_140f33d80(nColor1, nColor2, MS2Ptr<CItemData>(spData), nPalette, obj, n);
}
MS2_REPLACE(0x140F327A0, FUN_140f327a0, 249, 0x0747D19F);

// @0x140f328a0
void FUN_140f328a0(MS2Ptr<Customize> spCustomize, ASObj& obj, int n)
{
    if (spCustomize == 0)
        return;
    MS2Ptr<CItem> spItem = static_cast<Unk_CustomizeView*>(spCustomize.get())->GetEditItem();
    if (spItem == 0)
        return;
    MS2Ptr<CItemData> spData(reinterpret_cast<CItemData*>(spItem->FUN_140527840()));
    if (spData == 0)
        return;
    int nPalette = spData->FUN_14053e260();
    int nColor1 = 0;
    int nColor2 = 0;
    FUN_140f337a0(MS2Ptr<CItem>(spItem), &nColor1, &nColor2);
    FUN_140f33d80(nColor1, nColor2, MS2Ptr<CItemData>(spData), nPalette, obj, n);
}
MS2_REPLACE(0x140F328A0, FUN_140f328a0, 455, 0x566F2A2D);

// The size / degree / position pickers of the customize controller.
// @0x140f32a70
void FUN_140f32a70(MS2Ptr<CItemData> spData, MS2Ptr<Customize> spCustomize, ASObj& obj, unsigned* pnFlags)
{
    if (spCustomize == 0)
        return;
    if (spData == 0)
        return;
    NiPointer<CItemCustomizeController> part = spCustomize->FUN_140cd1a30();
    if (part == 0)
        return;
    *pnFlags = ((class Customize*)(class Customize*)(spCustomize.get()))->GetEditFlags();
    if ((int)*pnFlags <= 0)
        return;
    if ((*pnFlags & 1) != 0 || (*pnFlags & 2) != 0)
    {
        int nParts = part->vfunc_27();
        ASArray kSizes(2);
        if (0 < nParts)
        {
            for (int i = nParts - 1; i >= 0; i--)
            {
                const Unk_CustomizeRange* pRange = part->vfunc_24(i);
                float fCur = part->vfunc_22(i);
                float fMin = pRange->m_fMin;
                float fMax = pRange->m_fMax;
                if (pRange->m_n08 != 0)
                {
                    fCur = fMax - fCur;
                    fCur = fCur + fMin;
                }
                ASObj kEntry(2);
                int nIndex = i;
                ((class AScript&)(kEntry)).SetIntMember("id", nIndex);
                kEntry.SetMemberFloat("cur", fCur);
                kEntry.SetMemberFloat("min", fMin);
                kEntry.SetMemberFloat("max", fMax);
                kSizes.PushValue(Scaleform::GFx::Value(kEntry.GetValue()));
            }
            obj.FUN_1409adbe0("sizedata", Scaleform::GFx::Value(kSizes.GetValue()));
        }
    }
    if ((*pnFlags & 4) != 0)
    {
        ASObj kDegree(2);
        float fDegree = part->vfunc_18();
        if (fDegree < 0.0f)
            fDegree = 360.0f + fDegree;
        obj.SetMemberFloat("cur", fDegree);
        obj.FUN_1409adbe0("degreedata", Scaleform::GFx::Value(kDegree.GetValue()));
    }
    if ((*pnFlags & 8) != 0)
    {
        ASArray kPos(2);
        const std::vector<MS2Ptr<ItemCustom> >* pList = 0;
        int nSelected = part->vfunc_17();
        if (spData->FUN_14053d070())
        {
            CharacterDecalData* pDecal = spData->GetModelOrEmpty()->FUN_14054b6b0();
            if (pDecal != 0)
                pList = pDecal->GetCustoms();
        }
        else
        {
            if (spData->GetModelOrEmpty()->GetGroupCount() > 0)
            {
                if (spData->GetModelOrEmpty()->GetGroup(0)->GetPartCount() > 1)
                    pList = &spData->GetModelOrEmpty()->GetGroup(0)->GetPart(1)->customs;
            }
        }
        if (pList != 0)
        {
            for (size_t k = 0; k < pList->size(); k++)
            {
                ASObj kEntry(2);
                kEntry.FUN_140e846b0("id", k);
                const MS2Ptr<ItemCustom>& spCustom = (*pList)[k];
                kEntry.SetStringMember("iconpath", spCustom->name);
                if ((int)k == nSelected)
                    ((class AScript&)(kEntry)).SetIntMember("selected", 1);
                kPos.PushValue(Scaleform::GFx::Value(kEntry.GetValue()));
            }
            obj.FUN_1409adbe0("posdata", Scaleform::GFx::Value(kPos.GetValue()));
        }
    }
}

// The colour of a palette entry: real / visible colours of both channels.
// @0x140f33250
bool FUN_140f33250(ASObj& obj, MS2Ptr<ItemColorEx> spColor, MS2Ptr<CItemData> spData, bool bAlt);
bool FUN_140f33400(ASObj& obj, MS2Ptr<ItemColorEx> spColor, int* pnColor1, int* pnColor2, bool bAlt);

bool FUN_140f33250(ASObj& obj, MS2Ptr<ItemColorEx> spColor, MS2Ptr<CItemData> spData, bool bAlt)
{
    if (spColor == 0 || spData == 0)
        return false;
    int nColor1 = 0;
    int nColor2 = 0;
    if (bAlt)
    {
        nColor1 = spColor->m_n30;
        nColor2 = spColor->m_n34;
    }
    else
    {
        unsigned nIndex0 = 0;
        unsigned nWorn;
        if (spData->IsAvatarColorItem())
            nWorn = 1;
        else
            nWorn = 2;
        unsigned nIndex1 = nWorn;
        nColor1 = spColor->m_aValues[nIndex0];
        nColor2 = spColor->m_aValues[nIndex1];
    }
    FUN_140f33400(obj, MS2Ptr<ItemColorEx>(spColor), &nColor1, &nColor2, bAlt);
    return true;
}
MS2_REPLACE(0x140F33250, FUN_140f33250, 416, 0x1E0629C2);

// @0x140f33400
bool FUN_140f33400(ASObj& obj, MS2Ptr<ItemColorEx> spColor, int* pnColor1, int* pnColor2, bool)
{
    if (spColor == 0)
        return false;
    bool bDual = spColor->m_bFlag;
    obj.FUN_1409c4990("realColor", *pnColor1);
    if (!bDual)
        obj.FUN_1409c4990("visibleColor", spColor->m_n38);
    else
    {
        obj.FUN_1409c4990("visibleColor", *pnColor1);
        obj.FUN_1409c4990("realColor2", *pnColor2);
        obj.FUN_1409c4990("visibleColor2", *pnColor2);
    }
    obj.FUN_1409c4990("ch2Color", *pnColor2);
    ((class AScript&)(obj)).SetIntMember("colorSN", spColor->m_nColor);
    obj.SetMemberUInt("paletteID", spColor->m_nId);
    return true;
}
MS2_REPLACE(0x140F33400, FUN_140f33400, 349, 0x8BD542F8);

// The colours of the item's worn counterpart (or the default colours).
// @0x140f33570
void FUN_140f33570(MS2Ptr<CItemData> spData, int* pnColor1, int* pnColor2)
{
    void* pPc = WorldService::GetInstance()->FUN_141bd0cc0();
    if (pPc == 0)
        return;
    if (spData == 0)
        return;
    if (spData->IsAvatarColorItem())
    {
        FUN_1414239e0((unsigned int*)(pnColor1), 0, (struct Unk_UgcPlayer*)(pPc));
        FUN_1414239e0((unsigned int*)(pnColor2), 1, (struct Unk_UgcPlayer*)(pPc));
    }
    else
    {
        MS2Ptr<CEquipItem> spEquip = FUN_1414211a0(spData->GetModelOrEmpty()->GetFirstGroupType(), (class AvatarPC*)pPc);
        if (spEquip.get() != 0)
        {
            if (spEquip->GetItem()->GetItemId() == spData->GetItemId())
            {
                FUN_141424580(MS2Ptr<CEquipItem>(spEquip), (unsigned int*)(pnColor1), 0);
                FUN_141424580(MS2Ptr<CEquipItem>(spEquip), (unsigned int*)(pnColor2), 2);
            }
        }
    }
}
MS2_REPLACE(0x140F33570, FUN_140f33570, 542, 0xAC452C00);

// @0x140f337a0
void FUN_140f337a0(MS2Ptr<CItem> spItem, int* pnColor1, int* pnColor2)
{
    void* pPc = WorldService::GetInstance()->FUN_141bd0cc0();
    if (pPc == 0)
        return;
    if (spItem == 0)
        return;
    MS2Ptr<CItemData> spData(reinterpret_cast<CItemData*>(spItem->FUN_140527840()));
    if (spData == 0)
        return;
    if (spData->IsAvatarColorItem())
    {
        FUN_1414239e0((unsigned int*)(pnColor1), 0, (struct Unk_UgcPlayer*)(pPc));
        FUN_1414239e0((unsigned int*)(pnColor2), 1, (struct Unk_UgcPlayer*)(pPc));
    }
    else
    {
        FUN_141424760(MS2Ptr<CItem>(spItem), (unsigned int*)(pnColor1), 0, (struct Unk_UgcPlayer*)(pPc));
        FUN_141424760(MS2Ptr<CItem>(spItem), (unsigned int*)(pnColor2), 2, (struct Unk_UgcPlayer*)(pPc));
    }
}
MS2_REPLACE(0x140F337A0, FUN_140f337a0, 422, 0x0424A80D);

// The colour page of one palette: a row per colour (when building) and the index of the selected one.
// @0x140f33950
void FUN_140f33950(ASArray& arr, int* pnIndex, int nColor1, int nColor2, MS2Ptr<CItemData> spData, int nPalette,
                   ColorArrayPtr spColors, bool bBuild)
{
    if (spData == 0 || spColors == 0 || spColors->IsEmpty())
        return;
    bool bFactory = spData->IsAvatarColorItem();
    bool bFlag = spData->FUN_14053d020();
    bool bAlt = nPalette == FUN_140f02bc0() && bFlag == true;
    unsigned nIndex0 = 0;
    unsigned nWorn;
    if (bFactory)
        nWorn = 1;
    else
        nWorn = 2;
    unsigned nIndex1 = nWorn;
    bool bLockFeature = ((class CFeatureManager*)FUN_140166410())->IsFeatureEnabled(0xb7);
    size_t nCount = spColors->GetCount();
    int nMatch = 0;
    for (size_t i = 0; i < nCount; i++)
    {
        MS2Ptr<ItemColorEx> spColor((*spColors)[i]);
        if (spColor == 0)
            continue;
        ASObj kRow(2);
        int nA = 0;
        int nB = 0;
        if (bAlt)
        {
            nA = spColor->m_n30;
            nB = spColor->m_n34;
        }
        else
        {
            nA = spColor->m_aValues[nIndex0];
            nB = spColor->m_aValues[nIndex1];
        }
        bool bAdd = true;
        if (bBuild)
        {
            FUN_140f33400(kRow, MS2Ptr<ItemColorEx>(spColor), &nA, &nB, bAlt);
            if (bLockFeature && (unsigned)spColor->m_n24 > 0)
            {
                bAdd = false;
                bool bLocked = false;
                if (FUN_140f026f0(MS2Ptr<ItemColorEx>(spColor), &bLocked) == true)
                {
                    bAdd = true;
                    kRow.SetBoolMember("colorLock", bLocked);
                }
            }
            if (bAdd)
                arr.PushValue(Scaleform::GFx::Value(kRow.GetValue()));
        }
        if (bAdd)
        {
            if (nA == nColor1 && nB == nColor2)
            {
                *pnIndex = nMatch;
                if (!bBuild)
                    break;
            }
            nMatch = nMatch + 1;
        }
    }
}
MS2_REPLACE(0x140F33950, FUN_140f33950, 1053, 0x81E7461B);

// The colour page and the pickers of an item's AS object.
// @0x140f33d80
void FUN_140f33d80(int nColor1, int nColor2, MS2Ptr<CItemData> spData, int nPalette, ASObj& obj, int nFlags)
{
    if (spData == 0)
        return;
    bool bBuild;
    bool bLockFeature;
    bool bF8;
    int bDetail = ((CItemData*)spData)->FUN_14053ec70()->FUN_140547190();
    int bColor2 = spData->GetModelOrEmpty()->GetFirstGroupType() != 3;
    ASArray kColors(2);
    int nSelected = -1;
    bBuild = (nFlags & 1) > 0 ? true : false;
    ColorArrayPtr spPalette = TSingleton<CItemDataTable>::GetInstance()->GetPaletteColors(nPalette);
    if (spPalette.get() != 0)
        FUN_140f33950(kColors, &nSelected, nColor1, nColor2, MS2Ptr<CItemData>(spData), nPalette, ColorArrayPtr(spPalette),
                      bBuild);
    bF8 = (nFlags & 8) > 0;
    bLockFeature = ((class CFeatureManager*)FUN_140166410())->IsFeatureEnabled(0xb7);
    if (bLockFeature)
    {
        int nSelected2 = -1;
        int nHair = FUN_140f02bc0();
        ColorArrayPtr spHair = TSingleton<CItemDataTable>::GetInstance()->GetPaletteColors(nHair);
        if (spHair.get() != 0)
            FUN_140f33950(kColors, &nSelected2, nColor1, nColor2, MS2Ptr<CItemData>(spData), nHair, ColorArrayPtr(spHair),
                          bF8);
        if (nSelected == -1 && nSelected2 >= 0)
            nSelected = (int)(nSelected2 + spPalette->GetCount());
    }
    if ((nFlags & 2) != 0)
    {
        int nDetail = 0;
        if (bDetail && nSelected == -1)
            nDetail = 1;
        obj.SetMemberUInt("color0", nColor1);
        obj.SetMemberUInt("color2", nColor2);
        ((class AScript&)(obj)).SetIntMember("colorDetail", nDetail);
        ((class AScript&)(obj)).SetIntMember("colorSelectedIndex", nSelected);
    }
    if ((nFlags & 4) != 0)
    {
        ((class AScript&)(obj)).SetIntMember("colorDetailEnable", bDetail);
        ((class AScript&)(obj)).SetIntMember("color2enable", bColor2);
    }
    if ((nFlags & 1) != 0)
    {
        ((class AScript&)(obj)).SetIntMember("colorSelectedIndex", nSelected);
        obj.FUN_1409adbe0("color", Scaleform::GFx::Value(kColors.GetValue()));
        if (spData->FUN_14053e370())
        {
            ASArray kMulti(2);
            int nMulti = spData->GetMultiColorCount();
            for (int i = 0; i < nMulti; i++)
            {
                ASObj kEntry(2);
                ((class AScript&)(kEntry)).SetIntMember("label", i);
                ((class AScript&)(kEntry)).SetIntMember("idx", spData->FUN_14053e2b0(i));
                kMulti.PushValue(Scaleform::GFx::Value(kEntry.GetValue()));
            }
            ((class AScript&)(obj)).SetIntMember("multiColorCount", nMulti);
            obj.FUN_1409adbe0("multiColorList", Scaleform::GFx::Value(kMulti.GetValue()));
        }
    }
}
MS2_REPLACE(0x140F33D80, FUN_140f33d80, 1669, 0x3EB47E2D);
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca9270-0x142ca92e0 .text$yd
// MS2-RANGE: 0x142ca9300-0x142ca9380 .text$yd
// Atexit thunks of this unit's statics (gap2 yd sweep, yd2).
// MS2-RANGE: 0x142ca92e0-0x142ca9300 .text$yd
