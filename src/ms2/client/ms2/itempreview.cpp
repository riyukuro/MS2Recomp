// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The item preview of UIItemPreviewDialog: see itempreview.h.
// MS2-UNIT: ?\itempreview.cpp
// MS2-RANGE: 0x1400d2630-0x1400d2900 .text$di
// MS2-RANGE: 0x140d3b9f0-0x140d418e0 .text$mn
// MS2-RANGE: 0x142ca4cd0-0x142ca4de6 .text$yd
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\itempreview.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"
static CString s_sortNames[] = {"None", "Buy", "PriceLow", "PriceHigh", "Create", "ChartOrder", "BuyTotal", "EnumEnd"};
#include "ms2/placeholder/header_statics_a.h"
static CString s_jobCode = "jobCode";
static CString s_sortValue = "sortValue";
static CString s_tabIndex = "tabIndex";

#include "itempreview.h"
#include "ms2/client/ms2/uiavatarbase.h"
#include "ms2/client/ms2/uiitempreviewdialog.h"
#include "ms2/client/ms2/uiservice.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/client/ms2/avatarpc.h"
#include "ms2/client/ms2/avatarcube.h"
#include "ms2/client/ms2/uimodelview.h"
#include "ms2/client/ms2/gameobject.h"
#include "ms2/commonfiles/itemdata.h"
#include "ms2/commonfiles/itemgem.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/uimeratmarketweapontype.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

using UIMeratMarketCommon::WeaponType;

// ---- unit-local views of unrecovered callees ------------------------------------------------------------------------

// The item list of a package (commonfiles\npcshopdata.cpp): a CPtred holder with the list at +0x18; the pointer to it
// points at the list, so the reference count is reached through the holder.
typedef ATL::CAtlArray<MS2Ptr<CItemData> > Unk_PackageItems;
class Unk_PackageItemsHolder : public CPtred, public Unk_PackageItems
{
};
template <> void MS2Ptr<Unk_PackageItems>::Reference(Unk_PackageItems* p)
{
    CPtred::AddRefPtred(static_cast<Unk_PackageItemsHolder*>(p));
}
template <> void MS2Ptr<Unk_PackageItems>::ReleaseImpl(void*)
{
    if (CPtred::ReleasePtred(static_cast<Unk_PackageItemsHolder*>(m_p)) == 0)
    {
        Reference(m_p);
        CPtred::DeletePtred(static_cast<Unk_PackageItemsHolder*>(m_p));
    }
}
MS2Ptr<Unk_PackageItems> FUN_1406e5af0(int nPackageId);                 // the items of a package id
bool FUN_1405729c0(const Unk_PackageItems* pItems);                     // the list is empty

// The gamepad cursor HUD (UI id 6, see gameoptiongamepad.cpp).
class Unk_GpHud : public CPtred
{
public:
    void FUN_1422cedb0();
    void FUN_1422cee00();
    void FUN_1422cee50(int n);
};
class Unk_GpHudMgr { public: MS2Ptr<Unk_GpHud> FUN_1422b0370(int nDialogId); };
Unk_GpHudMgr* FUN_14025e7a0();

CItemData* FUN_140527840(CItem* pItem);                                 // the item's data row
CItemTransfer* FUN_140527930(CItem* pItem);                             // the item's transfer block
MS2Ptr<CItemData> FUN_14053f870(int nItemId);                           // the item data row of an id
int FUN_14053feb0(int nItemId);                                         // the default rarity of an item id
__int64 FUN_14028d0e0();                                                // the server time
int FUN_141658e60(PC* pPC);                                             // the gender
int FUN_141654700(PC* pPC);                                             // the job
void FUN_141275260(int nStringId, int nA, int nB);                      // system notice
int FUN_1408b5f70(int nItemId);                                         // the cube has a model view
Unk_RideePtr FUN_1407844b0(int nRideeId);                               // the ridee table row of an id
MS2Ptr<CItem> FUN_140ebc2b0(MS2Ptr<CItemData> spData, unsigned __int64 nGrade);   // a new item of a data row

// ?\uiugcitemeditdialog.cpp helpers of the preview
float FUN_141b48480(int nSet, int nIndex);                              // default angle
float FUN_141b48500(int nType);                                         // default angle of a lapenshard / accessory type
bool FUN_141b48710(MS2Ptr<CItemData> spData);
bool FUN_141b488c0(MS2Ptr<CItemData> spData);                           // the item can be previewed
bool FUN_141b48950(MS2Ptr<CItem> spItem);                               // the item goes on the character
bool FUN_141b48f90(PC* pPC, MS2Ptr<CItemData> spData, MS2Ptr<WeaponType> spFilter, Unk_PackageItems* pItems,
    MS2Ptr<CItemData>* pspData, MS2Ptr<CItemData>* pspPackageData, bool* pbDefault);  // resolve a package
MS2Ptr<CItemData> FUN_141b494f0(MS2Ptr<CItem> spItem);                  // the data row the item looks like
bool FUN_141b49b50(MS2Ptr<CItemData> spData);                           // the item is a package

// ---- ItemPreview ------------------------------------------------------------------------------------------------------

// @0x140d3b9f0
ItemPreview::ItemPreview(PC* pPC, IUIAvatarEventListener* pListener, int nMode)
    : m_pPC(pPC), m_spItem(0), m_spPreview(0), m_spAvatar(0), m_pListener(pListener), m_nMode(nMode)
{
}

// @0x140d3baf0
ItemPreview::~ItemPreview()
{
    m_pPC = 0;
    m_spPreview = 0;
    m_spItem = 0;
    m_spAvatar = 0;
    m_pListener = 0;
    m_nMode = 0;
    m_items.clear();
    FUN_140d3f3b0();
}

// @0x140d3bc30
int ItemPreview::FUN_140d3bc30()
{
    if (m_spAvatar.get())
        return m_spAvatar->vfunc_25();
    return 0;
}
MS2_REPLACE_METHOD(0x140D3BC30, ItemPreview, FUN_140d3bc30, 81, 0xC9B845CA);

// @0x140d3bc90
// MS2-FUNCTIONAL: behaviour from the decompile; temporaries / branch layout not byte-matched yet
int ItemPreview::FUN_140d3bc90(MS2Ptr<CItem> spItem)
{
    if (spItem == 0)
        return 0;
    MS2Ptr<CItemData> spItemData = FUN_14053f870(spItem->FUN_1405276c0());
    if (spItemData == 0)
        return 0;
    m_items.clear();
    FUN_140d3f3b0();
    bool bDefault = false;
    if (FUN_141b49b50(spItemData))
    {
        if (!FUN_141b48f90(m_pPC, spItemData, MS2Ptr<WeaponType>(0), &m_packageItems, &m_spData, &m_spPackageData,
                &bDefault))
            FUN_140d3f3b0();
    }
    else if (spItem->FUN_140525a30())
    {
        m_spData = FUN_141b494f0(spItem);
    }
    if (m_spData == 0)
        m_spData = spItemData;
    MS2Ptr<CItemData> spData = m_spData;
    if (FUN_140d3de80(spData))
        m_spAvatar = FUN_140d3e450(spData, 0, bDefault);
    else if (spData->FUN_14053cb80())
        m_spAvatar = FUN_140d3e7d0(spData, 0);
    else if (spData->FUN_14053cc40())
        m_spAvatar = FUN_140d3ea20(spData, 0);
    m_spItem = spItem;
    if ((m_spPreview = FUN_140d3c760(spItem)).get() == 0)
        return 0;
    m_spPreview->FUN_140526a70(FUN_14028d0e0());
    m_spPreview->FUN_140526b30(FUN_140d3bc30());
    FUN_140d3fea0(m_spPreview);
    return 1;
}
MS2_REPLACE_METHOD(0x140D3BC90, ItemPreview, FUN_140d3bc90, 1830, 0xAF0C7E00);

// @0x140d3c3c0
// MS2-FUNCTIONAL: behaviour from the decompile; temporaries / branch layout not byte-matched yet
int ItemPreview::FUN_140d3c3c0(std::vector<MS2Ptr<CItem> > items)
{
    if (m_pPC == 0)
        return 0;
    m_spAvatar = FUN_140d3e2f0();
    m_items.clear();
    int nGender = FUN_141658e60(m_pPC);
    for (size_t i = 0; i < items.size(); ++i)
    {
        if (!FUN_141b48950(items[i]))
            continue;
        MS2Ptr<CItem> spShown = FUN_140d3c760(items[i]);
        if (spShown.get())
        {
            if (!FUN_140527840(spShown)->FUN_14053c940(nGender))
                continue;
            spShown->FUN_140526a70(FUN_14028d0e0());
            spShown->FUN_140526b30(FUN_140d3bc30());
            m_items.push_back(spShown);
            m_spPreview = spShown;
        }
    }
    return 1;
}
MS2_REPLACE_METHOD(0x140D3C3C0, ItemPreview, FUN_140d3c3c0, 623, 0xB44AB87E);

// @0x140d3c640
MS2Ptr<CItem> ItemPreview::GetPreview()
{
    return m_spPreview;
}
MS2_REPLACE_METHOD(0x140D3C640, ItemPreview, GetPreview, 65, 0x1F75C5E3);

// @0x140d3c690
void ItemPreview::FUN_140d3c690(std::vector<MS2Ptr<CItem> >& items)
{
    items.clear();
    for (size_t i = 0; i < m_items.size(); ++i)
        items.push_back(m_items[i]);
}
MS2_REPLACE_METHOD(0x140D3C690, ItemPreview, FUN_140d3c690, 114, 0x76EC6C11);

// @0x140d3c710
MS2Ptr<CItem> ItemPreview::GetItem()
{
    return m_spItem;
}
MS2_REPLACE_METHOD(0x140D3C710, ItemPreview, GetItem, 65, 0xB93845D0);

// @0x140d3c760
// MS2-FUNCTIONAL: behaviour from the decompile; temporaries / branch layout not byte-matched yet
// A beauty coupon (function ItemChangeBeauty) shows the first item of its package; a lapenshard-like item gets a copy
// with its gem created; anything else shows a copy of itself.
MS2Ptr<CItem> ItemPreview::FUN_140d3c760(MS2Ptr<CItem> spItem)
{
    if (spItem == 0)
        return 0;
    MS2Ptr<CItemData> spData(FUN_140527840(spItem));
    if (spData == 0)
        return 0;
    ItemFunction* pFunction = &spData->function;
    if (pFunction->name == L"ItemChangeBeauty")
    {
        int nCount = pFunction->parameter.FUN_1408d2380();
        if (nCount == 0)
            return 0;
        int nPackageId = pFunction->parameter.FUN_1408d1fd0(0, 0);
        if (nPackageId == 0)
            return 0;
        MS2Ptr<Unk_PackageItems> spPackage = FUN_1406e5af0(nPackageId);
        if (!(spPackage == 0) && !FUN_1405729c0(spPackage.operator->()))
        {
            size_t nSize = spPackage->GetCount();
            for (size_t i = 0; i < nSize; ++i)
            {
                MS2Ptr<CItemData> spEntry = (*spPackage.operator->())[i];
                if (spEntry == 0)
                    continue;
                int nItemId = spEntry->FUN_14053c510();
                int nRarity = FUN_14053feb0(nItemId);
                MS2Ptr<CItem> spNew(new CItem());
                if (spNew->FUN_14052b130(nItemId, nRarity, 0))
                    return spNew;
            }
        }
        return 0;
    }
    if (!spData->FUN_14053cc00())
        return spItem->FUN_140524250();
    MS2Ptr<CItem> spCopy = spItem->FUN_140524250();
    if (!spCopy)
        return 0;
    CItemGem* pGem = spCopy->FUN_140527900();
    if (pGem && pGem->GetGem().IsNull())
        pGem->FUN_1405a7020(spData->FUN_14053e900(), spData->FUN_14053c650());
    return spCopy;
}
MS2_REPLACE_METHOD(0x140D3C760, ItemPreview, FUN_140d3c760, 1689, 0xFD61A5FE);

// @0x140d3ce10
// MS2-FUNCTIONAL: behaviour from the decompile; temporaries / branch layout not byte-matched yet
MS2Ptr<CItemData> ItemPreview::FUN_140d3ce10()
{
    if (m_spData.get())
        return m_spData;
    MS2Ptr<CItem> spShown = GetPreview();
    if (spShown.get() == 0)
        return 0;
    return MS2Ptr<CItemData>(FUN_140527840(spShown));
}
MS2_REPLACE_METHOD(0x140D3CE10, ItemPreview, FUN_140d3ce10, 229, 0x38F6D89B);

// @0x140d3cf00
MS2Ptr<UIAvatarBase> ItemPreview::GetAvatar()
{
    return m_spAvatar;
}
MS2_REPLACE_METHOD(0x140D3CF00, ItemPreview, GetAvatar, 65, 0x7D78CB50);

// @0x140d3cf50
void ItemPreview::FUN_140d3cf50()
{
    if (m_spPreview == 0)
        return;
    UIAvatarCube* pCube = dynamic_cast<UIAvatarCube*>((UIAvatarBase*)m_spAvatar);
    if (pCube)
    {
        AvatarCube* pObj = pCube->FUN_1418bde80();
        if (pObj)
            pObj->FUN_141085530(m_spPreview);
    }
}
MS2_REPLACE_METHOD(0x140D3CF50, ItemPreview, FUN_140d3cf50, 182, 0x72033574);

// @0x140d3d010
void ItemPreview::FUN_140d3d010()
{
    if (m_spAvatar == 0)
        return;
    m_spAvatar->vfunc_5();
}
MS2_REPLACE_METHOD(0x140D3D010, ItemPreview, FUN_140d3d010, 80, 0x9DA10FC9);

// @0x140d3d070
void ItemPreview::FUN_140d3d070()
{
    if (m_spAvatar == 0)
        return;
    m_spAvatar->vfunc_6();
}
MS2_REPLACE_METHOD(0x140D3D070, ItemPreview, FUN_140d3d070, 80, 0xFE7EB861);

// @0x140d3d0d0
// MS2-FUNCTIONAL: the exe passes pUnused as a 4th (stack) argument of slot 28, which uiavatarbase.h declares with three
// parameters (no implementation reads it).
void ItemPreview::FUN_140d3d0d0(void* p1, TPtr<Unk_UISwfEntity_25> spTarget, void* pArg, void* pUnused)
{
    if (m_spAvatar == 0)
        return;
    m_spAvatar->vfunc_28(p1, spTarget, pArg);
    if (m_nMode == 0)
    {
        if (m_spPreview == 0)
            return;
        MS2Ptr<CItemData> spData = FUN_14053f870(m_spPreview->FUN_1405276c0());
        if (spData == 0)
            return;
        FUN_140d3eb30(m_spPreview);
    }
    else if (m_nMode == 1)
    {
        if (m_items.size() == 0)
        {
            FUN_140d3fa30();
            FUN_140d3e130();
        }
        else
        {
            for (size_t i = 0; i < m_items.size(); ++i)
            {
                if (m_items[i] == 0)
                    continue;
                MS2Ptr<CItemData> spData = FUN_14053f870(m_items[i]->FUN_1405276c0());
                if (spData == 0)
                    return;
                bool bDefault = false;
                if (FUN_141b49b50(spData))
                {
                    if (!FUN_141b48f90(m_pPC, spData, MS2Ptr<WeaponType>(0), &m_packageItems, &m_spData,
                            &m_spPackageData, &bDefault))
                        FUN_140d3f3b0();
                }
                FUN_140d3eb30(m_items[i]);
            }
        }
    }
}
MS2_REPLACE_METHOD(0x140D3D0D0, ItemPreview, FUN_140d3d0d0, 1180, 0x54958EE2);

// @0x140d3d580
int ItemPreview::FUN_140d3d580(const char* szEvent, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (m_spAvatar.get())
        return m_spAvatar->vfunc_27(szEvent, pArgs, nArgs);
    return 0;
}
MS2_REPLACE_METHOD(0x140D3D580, ItemPreview, FUN_140d3d580, 111, 0xFC58E31F);

// @0x140d3d600
// MS2-FUNCTIONAL: behaviour from the decompile; temporaries / branch layout not byte-matched yet
void ItemPreview::FUN_140d3d600(MS2Ptr<CItem> spItem)
{
    if (spItem == 0)
        return;
    int nItemId = spItem->FUN_1405276c0();
    UIRenderView* pView = m_spAvatar->FUN_1418b9bc0();
    if (pView == 0)
        return;
    GameObject* pObj = m_spAvatar->vfunc_23();
    if (pObj == 0)
        return;
    MS2Ptr<CItemData> spItemData(FUN_140527840(spItem));
    if (spItemData == 0)
        return;
    MS2Ptr<CItemData> spData = spItemData;
    if (FUN_141b49b50(spItemData))
        spData = m_spData;
    if (spData == 0)
        return;

    int nModelType = spData->FUN_14053eba0()->FUN_14054b400();
    if (nModelType != 0 && spData->FUN_14053cbc0())
        m_spAvatar->vfunc_19(FUN_141b48480(1, nModelType), 0);
    else if (spData->FUN_14053cb80())
    {
        if (FUN_1408b5f70(nItemId) == 0)
            m_spAvatar->vfunc_19(FUN_141b48480(6, 0), 0);
        else
            m_spAvatar->vfunc_19(FUN_141b48480(0xb, 0), 0);
    }
    else if (spData->FUN_14053cc40())
        m_spAvatar->vfunc_19(FUN_141b48480(0xb, 0), 0);
    else if (spData->FUN_14053cc00())
        m_spAvatar->vfunc_19(FUN_141b48500(spData->FUN_14053e900()), 0);

    Unk_ModelViewCamera kCamera;
    if (dynamic_cast<UIAvatarPC*>((UIAvatarBase*)m_spAvatar))
    {
        kCamera.FUN_141b48530();
        kCamera.m_fMinDistance = 1000.0f;
        kCamera.m_nSteps = 5;
        kCamera.m_kTarget += pObj->vfunc_18();
        kCamera.m_kPosition += kCamera.m_kTarget;
        if (spData.get())
        {
            if (FUN_141b48710(spData))
                kCamera.m_nStepsDone = 2;
            else if (spData->FUN_14053cc00())
            {
                int nType = spData->FUN_14053e900();
                if (nType == 5 || nType == 6)
                    kCamera.m_nStepsDone = 1;
                else if (nType == 8)
                    kCamera.m_nStepsDone = 2;
            }
        }
    }
    else if (dynamic_cast<UIAvatarCube*>((UIAvatarBase*)m_spAvatar))
    {
        kCamera.FUN_141b485d0();
        kCamera.m_fMinDistance = 300.0f;
        kCamera.m_kTarget += pObj->vfunc_18();
        kCamera.m_kPosition += kCamera.m_kTarget;
    }
    else if (dynamic_cast<UIAvatarRidee*>((UIAvatarBase*)m_spAvatar))
    {
        kCamera.FUN_141b48670();
        float fScale = 1.0f;
        Unk_RideePtr spRow = FUN_1407844b0(spData->FUN_14053dd80());
        if (spRow.get())
            fScale = spRow->m_fViewScale * 0.015f;
        kCamera.m_fMinDistance = 300.0f;
        kCamera.m_kTarget += pObj->vfunc_18();
        kCamera.m_kPosition = kCamera.m_kPosition * fScale;
    }
    else if (dynamic_cast<UIAvatarPet*>((UIAvatarBase*)m_spAvatar))
    {
        kCamera.FUN_141b48670();
        kCamera.m_fMinDistance = 300.0f;
        kCamera.m_kTarget += pObj->vfunc_18();
        kCamera.m_kPosition = kCamera.m_kPosition;
    }
    pView->vfunc_13(kCamera);
}
MS2_REPLACE_METHOD(0x140D3D600, ItemPreview, FUN_140d3d600, 2170, 0x7C5FBDA4);

// @0x140d3de80
// MS2-FUNCTIONAL: behaviour from the decompile; temporaries / branch layout not byte-matched yet
bool ItemPreview::FUN_140d3de80(MS2Ptr<CItemData> spData)
{
    if (spData->FUN_14053cbc0() || spData->FUN_14053ce40() || spData->FUN_14053cb40() || spData->FUN_14053cd50()
        || spData->FUN_14053cc80())
        return true;
    if (spData->FUN_14053cc00())
    {
        int nType = spData->FUN_14053e900();
        if (nType == 5 || nType == 8 || nType == 6)
            return true;
    }
    CItemData* pData = spData.operator->();
    if (!(pData->function.name == L"ItemChangeBeauty"))
        return false;
    if (pData->function.parameter.FUN_1408d2380() == 0)
        return false;
    int nPackageId = pData->function.parameter.FUN_1408d1fd0(0, 0);
    if (nPackageId == 0)
        return false;
    MS2Ptr<Unk_PackageItems> spPackage = FUN_1406e5af0(nPackageId);
    if (!(spPackage == 0) && !FUN_1405729c0(spPackage.operator->()))
        return true;
    return false;
}
MS2_REPLACE_METHOD(0x140D3DE80, ItemPreview, FUN_140d3de80, 679, 0xB525CDB5);

// @0x140d3e130
// MS2-FUNCTIONAL: behaviour from the decompile; temporaries / branch layout not byte-matched yet
void ItemPreview::FUN_140d3e130()
{
    UIRenderView* pView = m_spAvatar->FUN_1418b9bc0();
    if (pView == 0)
        return;
    GameObject* pObj = m_spAvatar->vfunc_23();
    if (pObj == 0)
        return;
    m_spAvatar->vfunc_19(FUN_141b48480(1, 0), 0);
    Unk_ModelViewCamera kCamera;
    if (dynamic_cast<UIAvatarPC*>((UIAvatarBase*)m_spAvatar))
    {
        kCamera.FUN_141b48530();
        kCamera.m_fMinDistance = 1000.0f;
        kCamera.m_nSteps = 5;
        kCamera.m_kTarget += pObj->vfunc_18();
        kCamera.m_kPosition += kCamera.m_kTarget;
    }
    pView->vfunc_13(kCamera);
}
MS2_REPLACE_METHOD(0x140D3E130, ItemPreview, FUN_140d3e130, 431, 0xC0358E39);

// @0x140d3e2f0
MS2Ptr<UIAvatarBase> ItemPreview::FUN_140d3e2f0()
{
    MS2Ptr<WeaponType> spFilter(new WeaponType(m_pPC));
    UIAvatarPC* pAvatar = new UIAvatarPC(m_pPC, true);
    if (pAvatar)
    {
        pAvatar->vfunc_1(m_pListener);
        AvatarPC* pObj = pAvatar->FUN_1418bd1d0();
        if (pObj)
            pObj->SetEnabled(true);
    }
    return MS2Ptr<UIAvatarBase>(pAvatar);
}
MS2_REPLACE_METHOD(0x140D3E2F0, ItemPreview, FUN_140d3e2f0, 331, 0xA089AB81);

// @0x140d3e450
// MS2-FUNCTIONAL: behaviour from the decompile; temporaries / branch layout not byte-matched yet
MS2Ptr<UIAvatarBase> ItemPreview::FUN_140d3e450(MS2Ptr<CItemData> spData, int nUnused, bool bDefault)
{
    if (spData == 0)
        return 0;
    int nGender = FUN_141658e60(m_pPC);
    bool bShowEquip = true;
    if (spData->FUN_14053cc00() && spData->FUN_14053e900() == 5)
        bShowEquip = false;
    MS2Ptr<WeaponType> spFilter(new WeaponType(m_pPC));
    UIAvatarPC* pAvatar;
    if (spFilter.get() && spFilter->FUN_140ebb780(nGender, FUN_141654700(m_pPC), spData) && !bDefault)
    {
        pAvatar = new UIAvatarPC(m_pPC, true);
    }
    else
    {
        if (!spData->FUN_14053c940(nGender))
            nGender = nGender != 1;
        pAvatar = new UIAvatarPC(nGender, true);
    }
    if (pAvatar)
    {
        pAvatar->vfunc_1(m_pListener);
        AvatarPC* pObj = pAvatar->FUN_1418bd1d0();
        if (pObj)
            pObj->SetEnabled(bShowEquip);
    }
    return MS2Ptr<UIAvatarBase>(pAvatar);
}
MS2_REPLACE_METHOD(0x140D3E450, ItemPreview, FUN_140d3e450, 889, 0xC41CAF82);

// @0x140d3e7d0
MS2Ptr<UIAvatarBase> ItemPreview::FUN_140d3e7d0(MS2Ptr<CItemData> spData, int nUnused)
{
    if (spData == 0)
        return 0;
    UIAvatarCube* pAvatar = new UIAvatarCube(spData);
    pAvatar->vfunc_1(m_pListener);
    return MS2Ptr<UIAvatarBase>(pAvatar);
}
MS2_REPLACE_METHOD(0x140D3E7D0, ItemPreview, FUN_140d3e7d0, 256, 0x12448A9A);

// @0x140d3e8e0
MS2Ptr<UIAvatarBase> ItemPreview::FUN_140d3e8e0(MS2Ptr<CItemData> spData, int nUnused)
{
    if (spData == 0)
        return 0;
    UIAvatarRidee* pAvatar = new UIAvatarRidee(spData);
    pAvatar->vfunc_1(m_pListener);
    return MS2Ptr<UIAvatarBase>(pAvatar);
}
MS2_REPLACE_METHOD(0x140D3E8E0, ItemPreview, FUN_140d3e8e0, 305, 0x92CE75FB);

// @0x140d3ea20
MS2Ptr<UIAvatarBase> ItemPreview::FUN_140d3ea20(MS2Ptr<CItemData> spData, int nUnused)
{
    if (spData == 0)
        return 0;
    UIAvatarPet* pAvatar = new UIAvatarPet(spData);
    pAvatar->vfunc_1(m_pListener);
    return MS2Ptr<UIAvatarBase>(pAvatar);
}
MS2_REPLACE_METHOD(0x140D3EA20, ItemPreview, FUN_140d3ea20, 256, 0x806EC0D7);

// @0x140d3eb30
// MS2-FUNCTIONAL: behaviour from the decompile; temporaries / branch layout not byte-matched yet
void ItemPreview::FUN_140d3eb30(MS2Ptr<CItem> spItem)
{
    if (spItem == 0 || m_spAvatar == 0)
        return;
    MS2Ptr<CItemData> spData(FUN_140527840(spItem));
    if (spData == 0)
        return;
    UIAvatarPC* pAvatar = dynamic_cast<UIAvatarPC*>((UIAvatarBase*)m_spAvatar);
    if (pAvatar)
    {
        if (spData->FUN_14053cb40())
            pAvatar->FUN_1418bced0(spData);
        else if (spData->FUN_14053ce40())
            pAvatar->FUN_1418bce80(spData->FUN_14053dc20());
        else if (spData->FUN_14053cd50())
            pAvatar->FUN_1418bcfc0(spData);
        else if (spData->FUN_14053cc80())
            pAvatar->FUN_1418bd050(spData, spItem);
        else if (spData->FUN_14053cc00())
        {
            int nType = spData->FUN_14053e900();
            if (nType == 5 || nType == 8 || nType == 6)
            {
                FUN_140527930(spItem)->FUN_1406352b0();
                pAvatar->FUN_1418bc110(spItem);
            }
        }
        else if (!FUN_141b49b50(spData))
        {
            for (size_t i = 0; i < spData->FUN_14053eba0()->FUN_14054b3d0(); ++i)
            {
                int nType = spData->FUN_14053eba0()->FUN_14054b2f0(i)->FUN_1405451a0();
                if (nType == 0x13)
                {
                    spItem->FUN_140526c10(5);
                    pAvatar->FUN_1418bbd30(5);
                }
                else
                {
                    pAvatar->FUN_1418bbd30(nType);
                }
            }
            pAvatar->FUN_1418baf40(spItem.get());
        }
        else
        {
            if (!FUN_1405729c0(&m_packageItems))
                pAvatar->FUN_1418bb2a0(spData, 0, &m_packageItems);
            if (m_spPackageData.get())
            {
                MS2Ptr<CItem> spPackageItem = FUN_140ebc2b0(m_spPackageData, 1);
                FUN_140d3f160(m_spPackageData, spPackageItem);
            }
        }
    }
    FUN_140d3d600(spItem);
}
MS2_REPLACE_METHOD(0x140D3EB30, ItemPreview, FUN_140d3eb30, 1569, 0x6E2231A6);

// @0x140d3f160
void ItemPreview::FUN_140d3f160(MS2Ptr<CItemData> spData, MS2Ptr<CItem> spItem)
{
    if (spData == 0 || m_spAvatar == 0)
        return;
    UIAvatarPC* pAvatar = dynamic_cast<UIAvatarPC*>((UIAvatarBase*)m_spAvatar);
    if (pAvatar)
    {
        if (spData->FUN_14053cb40())
            pAvatar->FUN_1418bced0(spData);
        else if (spData->FUN_14053ce40())
            pAvatar->FUN_1418bce80(spData->FUN_14053dc20());
        else if (spData->FUN_14053cd50())
            pAvatar->FUN_1418bcfc0(spData);
        else if (spData->FUN_14053cc80())
            pAvatar->FUN_1418bd050(spData, spItem);
    }
}
MS2_REPLACE_METHOD(0x140D3F160, ItemPreview, FUN_140d3f160, 586, 0x1EDE7B85);

// @0x140d3f3b0
void ItemPreview::FUN_140d3f3b0()
{
    m_spPackageData = 0;
    m_spData = 0;
    m_packageItems.RemoveAll();
}
MS2_REPLACE_METHOD(0x140D3F3B0, ItemPreview, FUN_140d3f3b0, 73, 0xD3320356);

// @0x140d3f400
bool ItemPreview::FUN_140d3f400(MS2Ptr<CItem> spItem)
{
    if (spItem == 0)
        return false;
    MS2Ptr<CItemData> spItemData = FUN_14053f870(spItem->FUN_1405276c0());
    if (spItemData == 0)
        return false;
    if (FUN_140d3fda0(spItem) == true)
        return false;
    FUN_140d3f3b0();
    bool bDefault = false;
    if (FUN_141b49b50(spItemData))
    {
        if (!FUN_141b48f90(m_pPC, spItemData, MS2Ptr<WeaponType>(0), &m_packageItems, &m_spData, &m_spPackageData,
                &bDefault))
            FUN_140d3f3b0();
    }
    else if (spItem->FUN_140525a30())
    {
        m_spData = FUN_141b494f0(spItem);
    }
    if (m_spData == 0)
        m_spData = spItemData;
    m_spItem = spItem;
    if ((m_spPreview = FUN_140d3c760(spItem)).get())
    {
        m_spPreview->FUN_140526a70(FUN_14028d0e0());
        m_spPreview->FUN_140526b30(FUN_140d3bc30());
        FUN_140d3eb30(m_spPreview);
        FUN_140d3fea0(m_spPreview);
        spItem->FUN_140526a70(m_spPreview->FUN_140526a50());
        spItem->FUN_140526b30(FUN_140d3bc30());
    }
    return true;
}
MS2_REPLACE_METHOD(0x140D3F400, ItemPreview, FUN_140d3f400, 1421, 0x740DDA1A);

// @0x140d3f9a0
void ItemPreview::FUN_140d3f9a0()
{
    UIAvatarPC* pAvatar = dynamic_cast<UIAvatarPC*>((UIAvatarBase*)m_spAvatar);
    if (pAvatar)
    {
        pAvatar->FUN_1418bbe40();
        pAvatar->FUN_1418bd830();
        FUN_140d3e130();
    }
    m_items.clear();
}
MS2_REPLACE_METHOD(0x140D3F9A0, ItemPreview, FUN_140d3f9a0, 123, 0x35E48EEF);

// @0x140d3fa30
void ItemPreview::FUN_140d3fa30()
{
    UIAvatarPC* pAvatar = dynamic_cast<UIAvatarPC*>((UIAvatarBase*)m_spAvatar);
    if (pAvatar)
    {
        pAvatar->vfunc_3();
        pAvatar->FUN_1418bd830();
        FUN_140d3e130();
    }
    m_items.clear();
}
MS2_REPLACE_METHOD(0x140D3FA30, ItemPreview, FUN_140d3fa30, 129, 0x948C0DCA);

// @0x140d3fac0
// MS2-FUNCTIONAL: behaviour from the decompile; temporaries / branch layout not byte-matched yet
// A character item is taken off the avatar; anything else rebuilds the preview without it.
void ItemPreview::FUN_140d3fac0(__int64 nItemUid)
{
    bool bRebuild = false;
    MS2Ptr<CItem> spRemoved(0);
    for (size_t i = 0; i < m_items.size(); ++i)
    {
        MS2Ptr<CItem> spCur = m_items[i];
        if (spCur->FUN_140526a50() == nItemUid)
        {
            UIAvatarPC* pAvatar = dynamic_cast<UIAvatarPC*>((UIAvatarBase*)m_spAvatar);
            if (pAvatar)
            {
                bRebuild = !FUN_140527840(spCur)->FUN_14053cbc0();
                if (bRebuild)
                {
                    spRemoved = spCur;
                }
                else
                {
                    pAvatar->FUN_1418bc380(spCur.get());
                    m_items.erase(m_items.begin() + i);
                }
                break;
            }
        }
    }
    if (bRebuild)
    {
        std::vector<MS2Ptr<CItem> > items;
        for (size_t i = 0; i < m_items.size(); ++i)
        {
            if (!(m_items[i] == spRemoved.get()))
                items.push_back(m_items[i]);
        }
        FUN_140d3c3c0(items);
    }
}
MS2_REPLACE_METHOD(0x140D3FAC0, ItemPreview, FUN_140d3fac0, 722, 0x91DD141A);

// @0x140d3fda0
// MS2-FUNCTIONAL: behaviour from the decompile; temporaries / branch layout not byte-matched yet
bool ItemPreview::FUN_140d3fda0(MS2Ptr<CItem> spItem)
{
    for (size_t i = 0; i < m_items.size(); ++i)
    {
        if (!(m_items[i] == 0) && m_items[i]->FUN_1405276c0() == spItem->FUN_1405276c0())
            return true;
    }
    return false;
}
MS2_REPLACE_METHOD(0x140D3FDA0, ItemPreview, FUN_140d3fda0, 236, 0x41E8037B);

// @0x140d3fea0
void ItemPreview::FUN_140d3fea0(MS2Ptr<CItem> spItem)
{
    if (spItem == 0)
        return;
    int nSlot = spItem->FUN_140526c30();
    for (std::vector<MS2Ptr<CItem> >::iterator it = m_items.begin(); it != m_items.end(); ++it)
    {
        MS2Ptr<CItem> spCur = *it;
        if (spCur.get() && spCur->FUN_140526c30() == nSlot)
        {
            m_items.erase(it);
            break;
        }
    }
    m_items.push_back(spItem);
}
MS2_REPLACE_METHOD(0x140D3FEA0, ItemPreview, FUN_140d3fea0, 325, 0xF500E04F);

// ---- ItemPreviewMgr ---------------------------------------------------------------------------------------------------

// @0x140d3fff0
ItemPreviewMgr::ItemPreviewMgr()
    : m_nArg(0), m_nUnk0c(0), m_bHudOn(0), m_spPreview(0)
{
}

// @0x140d40070
ItemPreviewMgr::~ItemPreviewMgr()
{
    m_spPreview = 0;
}

// @0x140d400d0
int ItemPreviewMgr::FUN_140d400d0()
{
    if (m_spPreview == 0)
        return 0;
    return m_spPreview->FUN_140d3bc30();
}
MS2_REPLACE_METHOD(0x140D400D0, ItemPreviewMgr, FUN_140d400d0, 69, 0x3872E652);

// @0x140d40120
int ItemPreviewMgr::FUN_140d40120(MS2Ptr<CItem> spItem, int nArg)
{
    if (spItem == 0)
        return 0;
    PC* pPC = static_cast<PC*>(WorldService::GetInstance()->FUN_141bd0cc0());
    if (pPC == 0)
        return 0;
    UIItemPreviewDialog* pDialog = FUN_140d40ab0(0x4ec2);
    if (pDialog == 0)
        return 0;
    MS2Ptr<CItemData> spData = FUN_14053f870(spItem->FUN_1405276c0());
    if (spData == 0)
        return 0;
    if (!FUN_141b488c0(spData))
    {
        FUN_141275260(0xf9, 1, 1);
        return 0;
    }
    if (spItem->FUN_140528930())
    {
        FUN_141275260(0xfa, 1, 1);
        return 0;
    }
    m_nArg = nArg;
    CUIService::GetInstance()->OpenDialog((eUIClassID)0x4ec2);
    if (m_spPreview == 0)
        m_spPreview.AssignRaw(new ItemPreview(pPC, pDialog, 0));
    return m_spPreview->FUN_140d3bc90(spItem);
}
MS2_REPLACE_METHOD(0x140D40120, ItemPreviewMgr, FUN_140d40120, 842, 0x26150E8E);

// @0x140d40470
MS2Ptr<CItem> ItemPreviewMgr::FUN_140d40470()
{
    if (m_spPreview.get())
        return m_spPreview->GetPreview();
    return 0;
}
MS2_REPLACE_METHOD(0x140D40470, ItemPreviewMgr, FUN_140d40470, 125, 0x8A1C73D5);

// @0x140d40500
MS2Ptr<CItem> ItemPreviewMgr::FUN_140d40500()
{
    if (m_spPreview.get())
        return m_spPreview->GetItem();
    return 0;
}
MS2_REPLACE_METHOD(0x140D40500, ItemPreviewMgr, FUN_140d40500, 125, 0xB42171E2);

// @0x140d40590
MS2Ptr<CItemData> ItemPreviewMgr::FUN_140d40590()
{
    if (m_spPreview.get())
        return m_spPreview->FUN_140d3ce10();
    return 0;
}
MS2_REPLACE_METHOD(0x140D40590, ItemPreviewMgr, FUN_140d40590, 125, 0xEDD763B6);

// @0x140d40620
MS2Ptr<ItemPreview> ItemPreviewMgr::GetPreview()
{
    return m_spPreview;
}
MS2_REPLACE_METHOD(0x140D40620, ItemPreviewMgr, GetPreview, 65, 0x3FDA6E98);

// @0x140d40670
int ItemPreviewMgr::IsHudOn()
{
    return m_bHudOn;
}
MS2_REPLACE_METHOD(0x140D40670, ItemPreviewMgr, IsHudOn, 14, 0xC2D0886F);

// @0x140d40690
void ItemPreviewMgr::FUN_140d40690()
{
    FUN_140d406d0(m_bHudOn == 0);
}
MS2_REPLACE_METHOD(0x140D40690, ItemPreviewMgr, FUN_140d40690, 57, 0x628BB16C);

// @0x140d406d0
// MS2-FUNCTIONAL: behaviour from the decompile; temporaries / branch layout not byte-matched yet
void ItemPreviewMgr::FUN_140d406d0(int bOn)
{
    if (m_bHudOn == bOn)
        return;
    MS2Ptr<Unk_GpHud> spHud = FUN_14025e7a0()->FUN_1422b0370(6);
    if (spHud == 0)
        return;
    m_bHudOn = bOn;
    if (bOn == 0)
    {
        spHud->FUN_1422cee00();
        spHud->FUN_1422cee50(0);
    }
    else
    {
        spHud->FUN_1422cee50(4);
        spHud->FUN_1422cedb0();
    }
}
MS2_REPLACE_METHOD(0x140D406D0, ItemPreviewMgr, FUN_140d406d0, 213, 0xDBA85ECF);

// @0x140d407d0
void ItemPreviewMgr::FUN_140d407d0()
{
    m_spPreview = 0;
}
MS2_REPLACE_METHOD(0x140D407D0, ItemPreviewMgr, FUN_140d407d0, 33, 0xFE99409C);

// @0x140d40800
void ItemPreviewMgr::FUN_140d40800()
{
    if (m_spPreview == 0)
        return;
    m_spPreview->FUN_140d3cf50();
}
MS2_REPLACE_METHOD(0x140D40800, ItemPreviewMgr, FUN_140d40800, 67, 0xD5F34919);

// @0x140d40850
int ItemPreviewMgr::GetArg()
{
    return m_nArg;
}
MS2_REPLACE_METHOD(0x140D40850, ItemPreviewMgr, GetArg, 14, 0x92BE4827);

// @0x140d40870
void ItemPreviewMgr::FUN_140d40870()
{
    if (m_spPreview == 0)
        return;
    m_spPreview->FUN_140d3d010();
}
MS2_REPLACE_METHOD(0x140D40870, ItemPreviewMgr, FUN_140d40870, 67, 0x18A91909);

// @0x140d408c0
void ItemPreviewMgr::FUN_140d408c0()
{
    if (m_spPreview == 0)
        return;
    m_spPreview->FUN_140d3d070();
}
MS2_REPLACE_METHOD(0x140D408C0, ItemPreviewMgr, FUN_140d408c0, 67, 0x7544A367);

// @0x140d40910
void ItemPreviewMgr::FUN_140d40910(void* p1, TPtr<Unk_UISwfEntity_25> spTarget, void* pArg, void* pUnused)
{
    if (m_spPreview == 0)
        return;
    m_spPreview->FUN_140d3d0d0(p1, spTarget, pArg, pUnused);
}
MS2_REPLACE_METHOD(0x140D40910, ItemPreviewMgr, FUN_140d40910, 193, 0x208C52FF);

// @0x140d409e0
int ItemPreviewMgr::FUN_140d409e0(const char* szEvent, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    return m_spPreview->FUN_140d3d580(szEvent, pArgs, nArgs);
}
MS2_REPLACE_METHOD(0x140D409E0, ItemPreviewMgr, FUN_140d409e0, 69, 0xD3764FA6);

// @0x140d40ab0
UIItemPreviewDialog* ItemPreviewMgr::FUN_140d40ab0(int nClass)
{
    if (CUIService::GetInstance())
    {
        MS2Ptr<UIObject> spObj = CUIService::GetInstance()->FUN_141adcea0((eUIClassID)nClass);
        if (spObj.get())
            return dynamic_cast<UIItemPreviewDialog*>((UIObject*)spObj);
    }
    return 0;
}
MS2_REPLACE(0x140D40AB0, ItemPreviewMgr::FUN_140d40ab0, 147, 0x8B528740);

// ---- COMDAT emitted here --------------------------------------------------------------------------------------------

// @0x140d41400
MS2Ptr<CGemBase> CItemGem::GetGem()
{
    return m_spGem;
}
