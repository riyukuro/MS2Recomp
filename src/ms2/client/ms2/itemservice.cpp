// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// MS2-UNIT: ?\itemservice.cpp
// MS2-RANGE: 0x1400f6660-0x1400f6bf0 .text$di
// MS2-RANGE: 0x141419df0-0x141420a70 .text$mn
// MS2-RANGE: 0x142cb1fd0-0x142cb21e0 .text$yd
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$addressof@$$CBV?$_List_val@U?$_List_simple_types@V?$SmartPointer@VNiAVObject@@@efd@@@std@@@std@@@std@@YAPEBV?$_List_val@U?$_List_simple_types@V?$SmartPointer@VNiAVObject@@@efd@@@std@@@0@AEBV10@@Z 0x14141bf00 ; prop
// MS2-PIN: ??0?$_List_const_iterator@V?$_List_val@U?$_List_simple_types@V?$SmartPointer@VNiAVObject@@@efd@@@std@@@std@@@std@@QEAA@PEAU?$_List_node@V?$SmartPointer@VNiAVObject@@@efd@@PEAX@1@PEBV?$_List_val@U?$_List_simple_types@V?$SmartPointer@VNiAVObject@@@efd@@@std@@@1@@Z 0x14141c290 ; prop
// MS2-PIN: ?RegisterMessageFactory@?$MessageHandlerImpl@VCItemService@@VPhysXPropMessage@ecrPhysX@@@efd@@UEAAXPEAV?$GenericFactory@V?$SmartPointer@VIMessage@efd@@@efd@@I@2@@Z 0x14141eae0 ; unique
// MS2-PIN: ?RegisterMessageFactory@?$MessageSubclassHandler@VCItemService@@VPhysXPropMessage@ecrPhysX@@V23@@efd@@UEAAXPEAV?$GenericFactory@V?$SmartPointer@VIMessage@efd@@@efd@@I@2@@Z 0x14141eb20 ; unique
// MS2-PIN: ?TypeCast@PhysXPropMessage@ecrPhysX@@UEBA_NIPEAPEAX@Z 0x14141f340 ; unique
// MS2-PIN: ?TypeCast@PhysXPropMessage@ecrPhysX@@UEBA_NIPEAPEBX@Z 0x14141f390 ; unique
// MS2-PIN: ?_Make_iter@?$list@V?$SmartPointer@VNiAVObject@@@efd@@V?$allocator@V?$SmartPointer@VNiAVObject@@@efd@@@std@@@std@@QEBA?AV?$_List_iterator@V?$_List_val@U?$_List_simple_types@V?$SmartPointer@VNiAVObject@@@efd@@@std@@@std@@@2@V?$_List_const_iterator@V?$_List_val@U?$_List_simple_types@V?$SmartPointer@VNiAVObject@@@efd@@@std@@@std@@@2@@Z 0x14141f410 ; unique
// MS2-PIN: ?_Unlinknode@?$list@V?$SmartPointer@VNiAVObject@@@efd@@V?$allocator@V?$SmartPointer@VNiAVObject@@@efd@@@std@@@std@@QEAAPEAU?$_List_node@V?$SmartPointer@VNiAVObject@@@efd@@PEAX@2@V?$_List_const_iterator@V?$_List_val@U?$_List_simple_types@V?$SmartPointer@VNiAVObject@@@efd@@@std@@@std@@@2@@Z 0x14141f480 ; unique
// MS2-PIN: ?begin@?$list@V?$SmartPointer@VNiAVObject@@@efd@@V?$allocator@V?$SmartPointer@VNiAVObject@@@efd@@@std@@@std@@QEAA?AV?$_List_iterator@V?$_List_val@U?$_List_simple_types@V?$SmartPointer@VNiAVObject@@@efd@@@std@@@std@@@2@XZ 0x14141f4f0 ; unique
// MS2-PIN: ?empty@?$list@V?$SmartPointer@VNiAVObject@@@efd@@V?$allocator@V?$SmartPointer@VNiAVObject@@@efd@@@std@@@std@@QEBA_NXZ 0x14141f550 ; unique
// MS2-PIN: ?erase@?$list@V?$SmartPointer@VNiAVObject@@@efd@@V?$allocator@V?$SmartPointer@VNiAVObject@@@efd@@@std@@@std@@QEAA?AV?$_List_iterator@V?$_List_val@U?$_List_simple_types@V?$SmartPointer@VNiAVObject@@@efd@@@std@@@std@@@2@V?$_List_const_iterator@V?$_List_val@U?$_List_simple_types@V?$SmartPointer@VNiAVObject@@@efd@@@std@@@std@@@2@@Z 0x14141f590 ; unique
// MS2-PIN: ??_GCreateParam@ItemSlotBag@@UEAAPEAXI@Z 0x141420530 ; unique
// MS2-PIN: ??_GItemSlotBag@@UEAAPEAXI@Z 0x141420570 ; unique
// MS2-PINS-END tplpin
// CItemService (see citemservice.h) and ItemSlotBag (iteminfoslot.h): the bag of ItemInfoSlots the gacha / reward
// dialogs show, whose items come from a caller-owned array through CreateParam::m_pfnGetItem. The .text$di statics
// show two objs fused in this range (the ItemSlotBag ClassInfo starts the second one); both are written here.
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\itemservice.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <atlcoll.h>
#include <list>
#include <map>
#include <string>
#include <efd/MessageService.h>
#include <efd/ServiceManager.h>
#include <efd/AssetLoadResponse.h>
#include <efd/MemHint.h>
#include <egf/Entity.h>
#include <egf/FlatModelManager.h>
#include <ecr/ShaderService.h>
#include <egmAnimation/ActorMessages.h>
#include <NiAVObject.h>
#include "ms2/placeholder/physxpropmessage.h"
#include "ms2/placeholder/citemservice.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/fittingdollpc.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/commonfiles/itemdata.h"
#include "equipitem.h"
#include "equipment.h"
#include "equipmodel.h"
#include "kfmmodel.h"
#include "nifmodel.h"
#include "nifeffectparam.h"
#include "iteminfoslot.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- out-of-unit callees ----
class CLogString;
CLogString* GetLogString();
template <class T> void Unk_FileLog(CLogString* pLog, int nLevel, int nCategory, const wchar_t* pszFormat,
                                    const T& first);                // 0x1403a1280 for T = const char*

class Unk_TrigNetSvc2 { public: efd::Category FUN_142156c20(); };
Unk_TrigNetSvc2* FUN_140ae1200(efd::ServiceManager* pManager);
class Unk_TrigAnimSvc2 { public: efd::Category FUN_141235eb0(); };
Unk_TrigAnimSvc2* FUN_141b6f910();

// The model owner of CEquipModel is the CEquipItem (its MS2Ptr copy is the CPtred-generic 0x140884f30).
class Unk_EquipModelOwner : public CPtred {};

// CEquipModel members the unit uses (equipmodel.cpp).
class Unk_IsModel : public CEquipModel
{
public:
    PC* FUN_141200820();                                            // the owner PC (0 when none)
    MS2Ptr<CEquipItem> FUN_141200a40() const;                       // the equip item of the model
    efd::utf8string FUN_141201780();                                // the model's name (for the log)
};
class Unk_IsEquipItem
{
public:
    int FUN_1411dc500(CKfmModel* pModel);
    void FUN_1411dc530(CKfmModel* pModel);
};
#define IsModel(p) static_cast<Unk_IsModel*>(static_cast<CEquipModel*>(p))
int FUN_141565a20(CNifModel* pModel, CString strPath, NiAVObjectPtr spRoot);   // attach an already loaded root

typedef std::map<std::string, std::list<NiAVObjectPtr> > Unk_NifRootCache;

// The registry of named bags (GFx bind data).
void FUN_1422c8f10(const CString& strName, NotifyContext::BindData* pBag);
NotifyContext::BindData* FUN_1422c8e90(const CString& strName);
void FUN_1422c8f70(const CString& strName);
ItemSlotBag* FUN_140c54520(NotifyContext::BindData* p);             // BindData -> ItemSlotBag (TypeCast)
ItemInfoSlot* FUN_140cfe6c0(DragSlot* p);                           // DragSlot -> ItemInfoSlot (TypeCast)
class AvatarPC;
CItemData* FUN_140527840(CItem* pItem);                             // the item's template data
int FUN_141420b30(CItemData* pData, AvatarPC* pAvatar);             // unit_141420a70.cpp
unsigned FUN_141420a30(unsigned nType, CItem* pItem, AvatarPC* pAvatar);

// ---- static initializers (.text$di, in this order) ----
// @0x1400f6660
EE_IMPLEMENT_CONCRETE_CLASS_INFO(CItemService);
#ifndef MS2_HOOK_DLL
// @0x1400f6680
EE_HANDLER(CItemService, FUN_14141ac60, efd::AssetLoadResponse);
// @0x1400f66e0
EE_HANDLER_WRAP(CItemService, FUN_14141acc0, ecrPhysX::PhysXPropMessage, 12299);
// @0x1400f6740
EE_HANDLER(CItemService, FUN_14141ae10, egmAnimation::ActorAddedMessage);
#endif
// @0x1400f67a0
static CString s_aSortNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
// @0x1400f6860
static CString s_strSkill = "skill";
// @0x1400f6890
static CString s_strStun = "stun";
// @0x1400f68c0
static const efd::Category s_catInvalid(0ull);
// @0x1400f68f0
static const efd::Category s_catEntityChannel(efd::UniversalID::ECU_Any, 0xfff, 0x07f00004);
// @0x1400f6920
static const efd::Category s_catAnimationChannel(efd::UniversalID::ECU_Any, 0xfff, 0x07001008);
// @0x1400f6950
static Unk_1402a9d70 s_unk1402a9d70(17, 0.75f, 0.25f, 2.25f, 10);
// second obj (ItemSlotBag)
// @0x1400f69a0
EE_IMPLEMENT_CONCRETE_CLASS_INFO(ItemSlotBag);
// @0x1400f69c0
static CString s_aSortNames2[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
// @0x1400f6a80
static CString s_aSortNames3[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
// @0x1400f6b40
static CString s_strSkill2 = "skill";
// @0x1400f6b70
static CString s_strStun2 = "stun";
// @0x1400f6ba0
static Unk_1402a9d70 s_unk1402a9d70_2(17, 0.75f, 0.25f, 2.25f, 10);

// Not in the hook DLL: MS2::RegisterServices (hooked) must build the exe object (exe vtable; unhooked virtuals stay exe).
#ifndef MS2_HOOK_DLL
// @0x141419df0
CItemService::CItemService() : m_spMessages(0), m_mapModels(10)
{
}
#endif

// @0x141419ea0
CItemService::~CItemService()
{
}

// @0x141419f30
const char* CItemService::GetDisplayName() const
{
    return "ItemService";
}

// @0x141419f50
int CItemService::FUN_141419f50(CKfmModel* pModel)
{
    if (pModel == 0)
        return 0;
    if (m_mapModels.Lookup(pModel->FUN_14143ff70().GetValue()) != 0)
        return 0;
    {
        MS2Ptr<CKfmModel> spModel(pModel);
        m_mapModels.SetAt(pModel->FUN_14143ff70().GetValue(), spModel);
    }
    return 1;
}

// @0x14141a000
int CItemService::FUN_14141a000(CKfmModel* pModel)
{
    if (pModel == 0)
        return 0;
    m_mapModels.RemoveKey(pModel->FUN_14143ff70().GetValue());
    return 1;
}

// MS2-FUNCTIONAL: the flow of the 0xbec-byte original (equip item, KFM / NIF parts, root cache, three failure logs) is
// kept; the temporaries and the cleanup order on the early returns are not byte-checked
// @0x14141a060
MS2Ptr<CEquipItem> CItemService::FUN_14141a060(CItem* pItem, PC* pPC, __int64 nCache)
{
    Unk_NifRootCache* pCache = reinterpret_cast<Unk_NifRootCache*>(nCache);
    int nType;
    if (pPC == 0 || pPC->GetClassID() != 0x6200016 || pItem == 0 || (nType = pItem->FUN_140526c30(), nType < 4)
        || (nType > 5 && nType != 0x13))
    {
        MS2Ptr<CEquipItem> spEquip(new CEquipItem(pPC, pItem));
        CEquipment* pEquipment = reinterpret_cast<CEquipment*>(pPC->FUN_1416561a0());
        if (!FUN_14141b000(pItem, pPC))
        {
            FUN_14141b250(pItem, pPC, &spEquip->m_linkedItems);
            reinterpret_cast<CEquipment*>(pPC->FUN_1416561a0())->FUN_1411e3d20(spEquip->m_linkedItems, 0);
            spEquip->m_linkedItems.RemoveAll();
        }
        else
        {
            FUN_14141b250(pItem, pPC, &spEquip->m_linkedItems);
            reinterpret_cast<CEquipment*>(pPC->FUN_1416561a0())->FUN_1411e3d20(spEquip->m_linkedItems, 1);
        }
        (void)pEquipment;
        bool bSecond = pItem->FUN_14052a170() == 2;
        int nWeapon = pPC->vfunc_133(pItem, bSecond);
        bool bHair = FUN_140527840(pItem)->FUN_14053eba0()->FUN_14054b400() == 0xe;
        int nGender = pPC->FUN_141658e60();
        if (!FUN_140527840(pItem)->FUN_14053cae0(nGender, nWeapon))
            return spEquip;
        MS2Ptr<CItemData> spData(FUN_140527840(pItem));
        for (size_t i = 0; i < spData->FUN_14053eba0()->FUN_14054b3d0(); i++)
        {
            const ModelGroup* pGroup = spData->FUN_14053eba0()->FUN_14054b2f0(i);
            for (size_t j = 0; j < pGroup->FUN_1405450c0(); j++)
            {
                const ModelPart* pPart = pGroup->FUN_140544fe0(j);
                if (!pPart->FUN_140544aa0(nGender, nWeapon))
                    continue;
                CString strPath(pPart->name0);
                if (bHair)
                    strPath = reinterpret_cast<CEquipment*>(pPC->FUN_1416561a0())->FUN_1411ea5d0(strPath);
                if (pPart->isNif == 0)
                {
                    MS2Ptr<CKfmModel> spModel(new CKfmModel(reinterpret_cast<const MS2Ptr<Unk_EquipModelOwner>&>(spEquip),
                                                            const_cast<ModelGroup*>(pGroup), const_cast<ModelPart*>(pPart)));
                    if (!spModel->vfunc_4(strPath))
                    {
                        efd::utf8string strName = IsModel(spModel.get())->FUN_141201780();
                        Unk_FileLog(GetLogString(), 1, 0x13, L"nif \xd30c\xc77c\xc744 \xc77d\xc744 \xc218 \xc5c6\xc2b5\xb2c8\xb2e4" L"EquipItem1 [{0}]", strName.c_str());
                        return MS2Ptr<CEquipItem>(0);
                    }
                }
                else
                {
                    MS2Ptr<CNifModel> spModel(new CNifModel(reinterpret_cast<const MS2Ptr<Unk_EquipModelOwner>&>(spEquip),
                                                            const_cast<ModelGroup*>(pGroup), const_cast<ModelPart*>(pPart)));
                    NiAVObjectPtr spRoot(0);
                    if (pCache != 0)
                    {
                        Unk_NifRootCache::iterator it = pCache->find(std::string((const char*)strPath));
                        if (it != pCache->end())
                        {
                            std::list<NiAVObjectPtr>& rList = it->second;
                            if (!rList.empty())
                            {
                                spRoot = *rList.begin();
                                rList.erase(rList.begin());
                            }
                        }
                    }
                    if (spRoot == 0)
                    {
                        if (!spModel->vfunc_4(strPath))
                        {
                            efd::utf8string strName = IsModel(spModel.get())->FUN_141201780();
                            Unk_FileLog(GetLogString(), 1, 0x13, L"nif \xd30c\xc77c\xc744 \xc77d\xc744 \xc218 \xc5c6\xc2b5\xb2c8\xb2e4" L"EquipItem3 [{0}]", strName.c_str());
                            return MS2Ptr<CEquipItem>(0);
                        }
                    }
                    else if (!FUN_141565a20(spModel.get(), strPath, spRoot))
                    {
                        efd::utf8string strName = IsModel(spModel.get())->FUN_141201780();
                        Unk_FileLog(GetLogString(), 1, 0x13, L"nif \xd30c\xc77c\xc744 \xc77d\xc744 \xc218 \xc5c6\xc2b5\xb2c8\xb2e4" L"EquipItem2 [{0}]", strName.c_str());
                        return MS2Ptr<CEquipItem>(0);
                    }
                }
            }
        }
        return spEquip;
    }
    return MS2Ptr<CEquipItem>(0);
}

// @0x14141ac60
void CItemService::FUN_14141ac60(const efd::AssetLoadResponse* pMsg, efd::Category)
{
    efd::AssetLoadResponse::AssetLoadResult eResult = pMsg->GetResult();
    if (eResult != 9)
    {
        return;
    }
}

// The PhysX prop of a loading KFM model was created.
// MS2-FUNCTIONAL: the argument register shuffle of the two Unk_IsEquipItem calls (mov rcx,[x]; mov rdx,rcx) is not reproduced
// @0x14141acc0
void CItemService::FUN_14141acc0(const ecrPhysX::PhysXPropMessage* pMsg, efd::Category)
{
    egf::EntityID id = pMsg->GetEntityID();
    MS2Ptr<CKfmModel> spModel(0);
    if (m_mapModels.Lookup(id.GetValue(), spModel))
    {
        spModel->vfunc_33();
        CKfmModel* pModel = spModel;
        reinterpret_cast<Unk_IsEquipItem*>(IsModel(spModel.get())->FUN_141200a40().operator->())->FUN_1411dc500(pModel);
        PC* pPC = IsModel(spModel.get())->FUN_141200820();
        if (pPC != 0)
            reinterpret_cast<CEquipment*>(pPC->FUN_1416561a0())->FUN_1411e0c00();
    }
}

// The actor of a loading KFM model was added.
// MS2-FUNCTIONAL: the argument register shuffle of the two Unk_IsEquipItem calls (mov rcx,[x]; mov rdx,rcx) is not reproduced
// @0x14141ae10
void CItemService::FUN_14141ae10(const egmAnimation::ActorAddedMessage* pMsg, efd::Category)
{
    egf::EntityID id = pMsg->m_pEntity->GetEntityID();
    MS2Ptr<CKfmModel> spModel(0);
    if (m_mapModels.Lookup(id.GetValue(), spModel))
    {
        IsModel(spModel.get())->FUN_141200a40()->FUN_1411dbfd0();
        spModel->vfunc_34();
        CKfmModel* pModel = spModel;
        reinterpret_cast<Unk_IsEquipItem*>(IsModel(spModel.get())->FUN_141200a40().operator->())->FUN_1411dc530(pModel);
        PC* pPC = IsModel(spModel.get())->FUN_141200820();
        if (pPC != 0)
            reinterpret_cast<CEquipment*>(pPC->FUN_1416561a0())->FUN_1411e0c10();
        if (spModel->vfunc_9() != 0)
            FUN_14141a000(spModel);
    }
}

// MS2-FUNCTIONAL: the original's frame is 0x10 bigger (an int-typed temporary for the ternary argument, an int-returning
// FUN_14053cae0, a spData temporary); same flow
// @0x14141b000
int CItemService::FUN_14141b000(CItem* pItem, PC* pPC)
{
    if (pItem == 0 || pPC == 0)
        return 0;
    int nCount = 0;
    int nWeapon = pPC->vfunc_133(pItem, pItem->FUN_14052a170() == 2 ? true : false);
    int nGender = pPC->FUN_141658e60();
    if (!FUN_140527840(pItem)->FUN_14053cae0(nGender, nWeapon))
        return 0;
    MS2Ptr<CItemData> spData(FUN_140527840(pItem));
    for (size_t i = 0; i < spData->FUN_14053eba0()->FUN_14054b3d0(); i++)
    {
        const ModelGroup* pGroup = spData->FUN_14053eba0()->FUN_14054b2f0(i);
        for (int j = 0; j < (int)pGroup->FUN_1405450c0(); j++)
        {
            const ModelPart* pPart = pGroup->FUN_140544fe0(j);
            if (pPart->FUN_140544aa0(nGender, nWeapon))
            {
                MS2Ptr<CEquipModel> spModel(0);
                if (pPart->isNif != 0)
                    return 0;
                nCount++;
            }
        }
    }
    return nCount > 0;
}

// @0x14141b250
void CItemService::FUN_14141b250(CItem* pItem, PC* pPC, ATL::CAtlList<MS2Ptr<CEquipItem> >* pList)
{
    int nLayer = pItem->FUN_14052a170();
    for (size_t i = 0; i < FUN_140527840(pItem)->FUN_14053eba0()->FUN_14054b3d0(); i++)
    {
        int nSlot = FUN_141420a30(FUN_140527840(pItem)->FUN_14053eba0()->FUN_14054b2f0(i)->FUN_1405451a0(), pItem,
            reinterpret_cast<AvatarPC*>(pPC));
        MS2Ptr<CEquipItem> spItem = reinterpret_cast<CEquipment*>(pPC->FUN_1416561a0())->FUN_1411e1780(nSlot, nLayer);
        if (spItem.get() != 0)
            pList->AddTail(spItem);
    }
}

// @0x14141b360
efd::SyncResult CItemService::OnPreInit(efd::IDependencyRegistrar* pRegistrar)
{
    pRegistrar->AddDependency<egf::FlatModelManager>(1);
    pRegistrar->AddDependency<efd::MessageService>(1);
    pRegistrar->AddDependency<ecr::ShaderService>(1);
    pRegistrar->AddDependency<CNifLoadingService>(1);
    m_spMessages = m_pServiceManager->GetSystemServiceAs<efd::MessageService>();
    return efd::SyncResult_Success;
}

// @0x14141b3e0
efd::AsyncResult CItemService::OnInit()
{
    m_catGlobal = m_spMessages->GetGloballyUniqueCategory();
    m_spMessages->Subscribe(this, s_catEntityChannel, 0, false);
    m_spMessages->Subscribe(this, m_catGlobal, 0, false);
    m_spMessages->Subscribe(this, FUN_140ae1200(m_pServiceManager)->FUN_142156c20(), 0, false);
    m_spMessages->Subscribe(this, s_catAnimationChannel, 0, false);
    m_spMessages->Subscribe(this, FUN_141b6f910()->FUN_141235eb0(), 0, false);
    return efd::AsyncResult_Complete;
}

// @0x14141b660
efd::AsyncResult CItemService::OnTick()
{
    return efd::AsyncResult_Pending;
}

// @0x14141b680
efd::AsyncResult CItemService::OnShutdown()
{
    for (POSITION pos = m_mapModels.GetHeadPosition(); pos != 0; m_mapModels.GetNext(pos))
    {
        MS2Ptr<CKfmModel> spModel = m_mapModels.GetValueAt(pos);
        if ((CKfmModel*)spModel != 0)
            spModel->vfunc_18();
    }
    m_mapModels.RemoveAll();
    if ((efd::MessageService*)m_spMessages != 0)
    {
        m_spMessages->Unsubscribe(this, s_catEntityChannel, 0);
        m_spMessages->Unsubscribe(this, m_catGlobal, 0);
        m_spMessages->Unsubscribe(this, FUN_140ae1200(m_pServiceManager)->FUN_142156c20(), 0);
        m_spMessages->Unsubscribe(this, s_catAnimationChannel, 0);
        m_spMessages->Unsubscribe(this, FUN_141b6f910()->FUN_141235eb0(), 0);
    }
    return efd::AsyncResult_Complete;
}

// ======== ItemSlotBag (second obj) ========

// The slot callbacks are copied with the Delegate copy constructor (its COMDATs are in this obj).
template <> inline ItemInfoSlotSlotFn::Delegate(const Delegate& o)
{
    if (o.m_pImpl == 0)
        m_pImpl = 0;
    else
        m_pImpl = o.m_pImpl->vfunc_1();
}
template <> inline ItemInfoSlotTipFn::Delegate(const Delegate& o)
{
    if (o.m_pImpl == 0)
        m_pImpl = 0;
    else
        m_pImpl = o.m_pImpl->vfunc_1();
}

// @0x14141f6e0
ItemSlotBag::CreateParam::CreateParam()
    : m_pfnGetItem(0), m_nIconType(0), m_nFlags(0), m_bEnabled(false)
{
}

// @0x14141f770
void FUN_14141f770(const CString& strName, int nSlots, void* pItems, ItemSlotBag::CreateParam::GetItemFn pfnGetItem,
                   int nIconType, int nFlags)
{
    ItemSlotBag* pBag = new (efd::MemHint(efd::MemHint::NONE)) ItemSlotBag(strName, pItems, pfnGetItem, nIconType, nFlags);
    if (pBag != 0)
    {
        static_cast<DragSlotBag*>(pBag)->vfunc_10(nSlots);
        FUN_1422c8f10(strName, pBag);
    }
}

// @0x14141f860
void FUN_14141f860(const CString& strName, int nSlots, void* pItems, MS2Ptr<ItemSlotBag::CreateParam> spParam)
{
    ItemSlotBag* pBag = new (efd::MemHint(efd::MemHint::NONE)) ItemSlotBag(strName, pItems, spParam);
    if (pBag != 0)
    {
        static_cast<DragSlotBag*>(pBag)->vfunc_10(nSlots);
        FUN_1422c8f10(strName, pBag);
    }
}

// @0x14141f970
void FUN_14141f970(const CString& strName)
{
    ItemSlotBag* pBag = FUN_140c54520(FUN_1422c8e90(strName));
    if (pBag != 0)
    {
        pBag->FUN_1422cc9e0();
        FUN_1422c8f70(strName);
    }
}

// @0x14141f9c0
ItemSlotBag::ItemSlotBag(const CString& strName, void* pItems, CreateParam::GetItemFn pfnGetItem, int nIconType, int nFlags)
    : DragSlotBag(strName), m_pItems(pItems)
{
    m_spParam.AssignRaw(new CreateParam);
    if (m_spParam.get() != 0)
    {
        m_spParam->m_pfnGetItem = pfnGetItem;
        m_spParam->m_nIconType = nIconType;
        m_spParam->m_nFlags = nFlags;
    }
}

// @0x14141faf0
ItemSlotBag::ItemSlotBag(const CString& strName, void* pItems, MS2Ptr<CreateParam> spParam)
    : DragSlotBag(strName), m_pItems(pItems), m_spParam(spParam)
{
}

// @0x14141fb80
ItemSlotBag::~ItemSlotBag()
{
}

// @0x14141fbc0
void ItemSlotBag::vfunc_13(int nIndex)
{
    ItemInfoSlot* pSlot = FUN_140cfe6c0(FUN_1422cd070(nIndex));
    if (pSlot != 0)
        pSlot->vfunc_11();
}

// @0x14141fc10
void ItemSlotBag::vfunc_14(int nIndex)
{
    ItemInfoSlot* pSlot = FUN_140cfe6c0(FUN_1422cd070(nIndex));
    if (pSlot != 0)
        pSlot->vfunc_10();
}

// MS2-FUNCTIONAL: the original's frame is 0x10 bigger (one more int local and a copied GetItemFn result temporary)
// @0x14141fc60
DragSlot* ItemSlotBag::vfunc_16(int nIndex)
{
    CString strName = vfunc_15(nIndex);
    int nIconType = 0;
    int nFlags = 0;
    MS2Ptr<CItem> spItem(0);
    if (m_spParam.get() != 0)
    {
        nIconType = m_spParam->m_nIconType;
        nFlags = m_spParam->m_nFlags;
        spItem = m_spParam->m_pfnGetItem(m_pItems, nIndex);
    }
    ItemInfoSlot* pSlot = new (efd::MemHint(efd::MemHint::NONE)) ItemInfoSlot(strName, spItem, nIndex, nIconType, nFlags);
    if (pSlot != 0 && m_spParam.get() != 0)
    {
        pSlot->SetSlotFn(m_spParam->m_pfnSlot);
        pSlot->SetTipFn(m_spParam->m_pfnTip);
        pSlot->SetEnabled(m_spParam->m_bEnabled);
    }
    return pSlot;
}

// Resize the bag to nCount slots and refill the items.
// MS2-FUNCTIONAL: the original keeps the old slot count in two more int locals; the grow / shrink loops are the same
// @0x14141ff80
void FUN_14141ff80(ItemSlotBag* pBag, int nCount)
{
    if (nCount == 0)
    {
        pBag->FUN_1422cc9e0();
        return;
    }
    int nOld = (int)pBag->m_slots.size();
    if (nOld < nCount)
    {
        for (; nOld < nCount; nOld++)
            pBag->FUN_1422ccb50(nOld);
    }
    else if (nCount < nOld)
    {
        int i = nOld - 1;
        if (i < 0)
            return;
        for (; nCount <= i; i--)
            pBag->FUN_1422ccc60(i);
    }
    if (!pBag->m_slots.empty())
    {
        for (auto kv : pBag->m_slots)
        {
            ItemInfoSlot* pSlot = FUN_140cfe6c0(pBag->FUN_1422cd0f0(kv.second));
            if (pSlot == 0)
                continue;
            int nIndex = pSlot->GetIndex();
            MS2Ptr<CItem> spItem = pBag->m_spParam.get() == 0 ? MS2Ptr<CItem>(0)
                                                               : pBag->m_spParam->m_pfnGetItem(pBag->m_pItems, nIndex);
            pSlot->SetItem(spItem);
        }
    }
}

// The default GetItemFn: the nIndex-th item of a CAtlArray<MS2Ptr<CItem> >.
// @0x141420330
MS2Ptr<CItem> FUN_141420330(void* pItems, int nIndex)
{
    typedef ATL::CAtlArray<MS2Ptr<CItem> > ItemArray;
    if (!static_cast<ItemArray*>(pItems)->IsEmpty() && nIndex < (int)static_cast<ItemArray*>(pItems)->GetCount())
        return static_cast<ItemArray*>(pItems)->GetAt(nIndex);
    return MS2Ptr<CItem>(0);
}

// The slot of an equip item of the given model-group type (0x13 = the item's own slot).
// @0x141420990
int FUN_141420990(int nType, CItem* pItem, AvatarPC* pAvatar)
{
    if (pItem == 0 || FUN_140527840(pItem) == 0 || pAvatar == 0)
        return 0;
    if (nType == 0)
        return 0;
    int nResult = nType;
    if (nResult == 0x13)
    {
        if (pItem->FUN_140526c30() == 0)
        {
            int nSlot = FUN_141420b30(FUN_140527840(pItem), pAvatar);
            return nSlot;
        }
        else
        {
            nResult = pItem->FUN_140526c30();
        }
    }
    return nResult;
}

// @0x141420a30
unsigned FUN_141420a30(unsigned nType, CItem* pItem, AvatarPC* pAvatar)
{
    if (pAvatar == 0)
        return 0;
    if (nType == 0x13)
        return pItem->FUN_140526c30();
    return nType;
}

// memcpy_s (the CRT's _VALIDATE_RETURN_ERRCODE form, per-TU static __inline copy).
// @0x141420720
#pragma function(memset, memcpy)
static __inline errno_t ms2_memcpy_s_copy(void* const d, size_t const dsz, void const* const s, size_t const ssz)
{
    if (ssz == 0) { return 0; }
    { int e = !!(d != NULL); if (!e) { errno = EINVAL; _invalid_parameter_noinfo(); return EINVAL; } }
    if (s == NULL || dsz < ssz)
    {
        memset(d, 0, dsz);
        { int e = !!(s != NULL); if (!e) { errno = EINVAL; _invalid_parameter_noinfo(); return EINVAL; } }
        { int e = !!(dsz >= ssz); if (!e) { errno = ERANGE; _invalid_parameter_noinfo(); return ERANGE; } }
        return EINVAL;
    }
    memcpy(d, s, ssz);
    return 0;
}
__declspec(selectany) extern errno_t(__cdecl* const ms2_pfnMemcpySCopy)(void*, size_t, const void*, size_t) = &ms2_memcpy_s_copy;
#pragma intrinsic(memset, memcpy)
MS2_EMIT_CRT_MEMMOVE_S();

MS2_REPLACE_METHOD(0x141419F30, CItemService, GetDisplayName, 13, 0xFE406CA6);
MS2_REPLACE_METHOD(0x141419F50, CItemService, FUN_141419f50, 166, 0x32862F2B);
MS2_REPLACE_METHOD(0x14141A000, CItemService, FUN_14141a000, 76, 0x1DFADF0C);
MS2_REPLACE_METHOD(0x14141A060, CItemService, FUN_14141a060, 3052, 0x097F71D7);
MS2_REPLACE_METHOD(0x14141AC60, CItemService, FUN_14141ac60, 76, 0xF9400BDF);
MS2_REPLACE_METHOD(0x14141ACC0, CItemService, FUN_14141acc0, 322, 0x5E111DEB);
MS2_REPLACE_METHOD(0x14141AE10, CItemService, FUN_14141ae10, 477, 0x3F4220C9);
MS2_REPLACE_METHOD(0x14141B000, CItemService, FUN_14141b000, 574, 0x26956EB2);
MS2_REPLACE_METHOD(0x14141B250, CItemService, FUN_14141b250, 253, 0x9E0E8D7C);
MS2_REPLACE_METHOD(0x14141B360, CItemService, OnPreInit, 115, 0x1B8C8A6F);
MS2_REPLACE_METHOD(0x14141B3E0, CItemService, OnInit, 621, 0x2187FFE3);
MS2_REPLACE_METHOD(0x14141B660, CItemService, OnTick, 11, 0x30025ED0);
MS2_REPLACE_METHOD(0x14141B680, CItemService, OnShutdown, 698, 0x8FB44546);
MS2_REPLACE(0x14141F770, FUN_14141f770, 225, 0x511582BC);
MS2_REPLACE(0x14141F860, FUN_14141f860, 253, 0xEEFE7307);
MS2_REPLACE(0x14141F970, FUN_14141f970, 65, 0x553D0D40);
MS2_REPLACE_METHOD(0x14141FBC0, ItemSlotBag, vfunc_13, 69, 0x040F174F);
MS2_REPLACE_METHOD(0x14141FC10, ItemSlotBag, vfunc_14, 69, 0xEBA994A7);
MS2_REPLACE_METHOD(0x14141FC60, ItemSlotBag, vfunc_16, 791, 0xEF0344BF);
MS2_REPLACE(0x14141FF80, FUN_14141ff80, 928, 0xAEBFD3E5);
MS2_REPLACE(0x141420330, FUN_141420330, 142, 0xD685F342);
MS2_REPLACE(0x141420990, FUN_141420990, 149, 0x82E4FA4C);
MS2_REPLACE(0x141420A30, FUN_141420a30, 58, 0x30F01A85);
// MS2-PIN: ??1CreateParam@ItemSlotBag@@UEAA@XZ 0x141420480
// MS2-PIN: ??_7CItemService@@6BISystemService@efd@@@ 0x142f10b58
// MS2-PIN: ??_7CItemService@@6B?$TSingleton@VCItemService@@@@@ 0x142f10be0
// MS2-PIN: ?GetClassDesc@CItemService@@UEBAPEBVClassInfo@efd@@XZ 0x14141ce20
// MS2-PIN: ?TypeCast@CItemService@@UEBA_NIPEAPEAX@Z 0x14141f2a0
// MS2-PIN: ?TypeCast@CItemService@@UEBA_NIPEAPEBX@Z 0x14141f2f0
// MS2-PIN: ?GetClassDesc@ItemSlotBag@@UEBAPEBVClassInfo@efd@@XZ 0x1414205d0
// MS2-PIN: ?TypeCast@ItemSlotBag@@UEBA_NIPEAPEAX@Z 0x141420640
// MS2-PIN: ?TypeCast@ItemSlotBag@@UEBA_NIPEAPEBX@Z 0x141420690
