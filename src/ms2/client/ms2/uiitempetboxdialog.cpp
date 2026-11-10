// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Pet box dialog (Lullu box).
// MS2-UNIT: client\ms2\uiitempetboxdialog.cpp
// MS2-RANGE: 0x140e4df70-0x140e54b60 .text$mn
// MS2-RANGE: 0x1400d8630-0x1400d8770 .text$di
// MS2-RANGE: 0x142ca6af0-0x142ca6ba6 .text$yd
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$?8PEAVUIItemPetBoxDialog@@P80@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@YA_NAEBU?$pair@PEAVUIItemPetBoxDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@0@0@Z 0x140e52590 ; prop
// MS2-PIN: ??$?8PEAVUIItemPetBoxDialog@@P80@EAA_NHAEBVCMsgBoxData@@@Z@std@@YA_NAEBU?$pair@PEAVUIItemPetBoxDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@0@0@Z 0x140e52600 ; prop
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVUIItemPetBoxDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@QEAA@AEBV01@@Z 0x140e53b40 ; unique
// MS2-PIN: ??_GUIItemPetBoxDialog@@UEAAPEAXI@Z 0x140e540e0 ; unique
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVUIItemPetBoxDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x140e547f0 ; unique
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVUIItemPetBoxDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x140e54850 ; unique
// MS2-PIN: ?vfunc_2@?$DelegateImpl@U?$pair@PEAVUIItemPetBoxDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z 0x140e548e0 ; unique
// MS2-PIN: ?Invoke@?$DelegateImpl@U?$pair@PEAVUIItemPetBoxDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEAA_NHAEBVCMsgBoxData@@@Z 0x140e54910 ; unique
// MS2-PIN: ??$Call@VUIItemPetBoxDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@?$DelegateImpl@U?$pair@PEAVUIItemPetBoxDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@CAXAEAU?$pair@PEAVUIItemPetBoxDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@AEBUParams@FunctionHandler@GFx@Scaleform@@@Z 0x140e54950 ; unique
// MS2-PIN: ??$Call@VUIItemPetBoxDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@?$DelegateImpl@U?$pair@PEAVUIItemPetBoxDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@CA_NAEAU?$pair@PEAVUIItemPetBoxDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@HAEBVCMsgBoxData@@@Z 0x140e54990 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVUIItemPetBoxDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x140e549d0 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVUIItemPetBoxDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x140e54a30 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ?max_size@?$_Default_allocator_traits@V?$allocator@UUnk_PetBoxCard@@@std@@@std@@SA_KAEBV?$allocator@UUnk_PetBoxCard@@@2@@Z 0x140e54a90
// MS2-PIN: ?_Getal@?$_Vector_alloc@U?$_Vec_base_types@UUnk_PetBoxCard@@V?$allocator@UUnk_PetBoxCard@@@std@@@std@@@std@@QEBAAEBV?$allocator@UUnk_PetBoxCard@@@2@XZ 0x140e543b0
// MS2-PIN: ?push_back@?$vector@UUnk_PetBoxCard@@V?$allocator@UUnk_PetBoxCard@@@std@@@std@@QEAAXAEBUUnk_PetBoxCard@@@Z 0x140e54af0
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiitempetboxdialog.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "uiitempetboxdialog.h"
#include "ms2/placeholder/header_statics_a.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/astextfield.h"
#include "ms2/placeholder/asbutton.h"
#include "ms2/placeholder/aslabel.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/citemdata.h"
#include "inventory.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/placeholder/cxmldata.h"
#include "ms2/placeholder/fittingdollpc.h"
#include "ms2/client/ms2/uiservice.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/client/ms2/uirenderview.h"
#include "ms2/client/ms2/uirenderview.h"  // C3: Unk_ModelViewCamera is unit-local below
#include <algorithm>
#include <errno.h>
#include <string.h>
#include "ms2/commonfiles/itemdroptable.h"   // C3: TSingleton<> needs the class
#include "ms2/commonfiles/itemdatatable.h"
// C3: Unk_140acd6e0 (the button view) is ASButton itself.
class UICashAttendDialog { public: template <class T> MS2Ptr<T> FUN_140bc6d10(const CString& strName, MS2Ptr<T>& out); };   // C3: the child binder (0x140bc6d10, uicashattenddialog.cpp)
class UIItemTreasureMapDialog { public: MS2Ptr<ASMovieClip> FUN_140c57ce0(const CString& strName, MS2Ptr<ASMovieClip>& out); };   // bind a child
static CString s_sndOpen = "LulluOpenBox_Open";
static CString s_sndSpecial = "LulluOpenBox_SpecialItem_Get";
static CString s_snd10 = "LulluOpenBox_10Items_Open";

// ---- local stand-ins for classes whose units are not recovered yet ----
// ASMovieClip with the extra setters the dialog uses
class Unk_PetBoxClip : public ASMovieClip { };
class CMsgBoxData : public CPtred
{
public:
    void SetCallback(Delegate<bool(int, const CMsgBoxData&)>);
};
// the obtained items (std::vector<ItemEntity>) and the "binding" strings (std::vector<CString>)
#define PETBOX_ITEMS (m_result)
#define PETBOX_ATTR(p) reinterpret_cast<Unk_PetBoxAttr*>(reinterpret_cast<char*>((p).operator->()) + 0x320)
#define PETBOX_BINDS (m_slotBinds)
// the item record's attribute table (+0x320) and job table (+0x138)
class Unk_PetBoxAttr : public CXmlData
{
};
class Unk_PetBoxData : public CItemData
{
};
class Unk_PetBoxSelf : public PC { };
class Unk_PetBoxWorld { public: Unk_PetBoxSelf* GetLocalPlayer(); };
class Unk_PetBoxUIMgr { public: void FUN_141adc530(int); };
MS2Ptr<CItemData> FUN_14053f870(int);
extern Unk_Inventory g_143ab2a90;
// avatar of a pet (0xc8 bytes, RTTI UIAvatarPet : UIAvatarBase), rendered into an AS clip
class Unk_ModelViewCamera   // uimodelview.h's camera preset (0x30), unit-local field names
{ public:
    Unk_ModelViewCamera(); void ApplyRideeCamera();
    NiPoint3 eye, target;
    float f18, f1c, f20;
    int n24, n28, n2c;
};
typedef Unk_ModelViewCamera Unk_PetBoxCameraData; MS2_CHECK_SIZE(Unk_ModelViewCamera, 0x30);
class Unk_PetBoxActor
{
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4();
    virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9();
    virtual void vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14();
    virtual void vfunc_15(); virtual void vfunc_16(); virtual void vfunc_17();
    virtual NiPoint3 vfunc_18();
};
class Unk_PetBoxCamera
{
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4();
    virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9();
    virtual void vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12();
    virtual void vfunc_13(const Unk_PetBoxCameraData&);
};
class UIAvatarBase
{
public:
    efd::SmartPointer<UIRenderView> GetView();
};
class Unk_PetBoxAvatar : public CPtred
{
public:
    virtual void vfunc_1(IUIAvatarEventListener*);
    virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6();
    virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11();
    virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15(); virtual void vfunc_16();
    virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19(); virtual void vfunc_20(); virtual void vfunc_21();
    virtual void vfunc_22(); virtual void vfunc_23();
    virtual Unk_PetBoxActor* vfunc_24();
    virtual void vfunc_25(); virtual void vfunc_26(); virtual void vfunc_27();
    virtual void vfunc_28(void*, TPtr<Unk_UISwfEntity_25>, void*, void*);
};
class UIAvatarPet : public Unk_PetBoxAvatar
{
public:
    UIAvatarPet(CItemData* pItemData);
private:
    unsigned char m_18[0xb0];
};
MS2_CHECK_SIZE(UIAvatarPet, 0xc8);
int PlaySystemSound(const CString&, const CString&);
void DestroyItemSlotBag(const CString&);
void CreateItemSlotBag(const CString& strBag, int nSlots, void* pItems, MS2Ptr<CItem> (*pfnGetItem)(void*, int), int n1, int n2);   // C3: itemservice.cpp's definition (0x14141f770)
MS2Ptr<CItem> GetItemFromArray(void* pItems, int nIndex);   // C3: itemservice.cpp's definition (0x141420330)
void CreateItemInfoSlot(const CString&, MS2Ptr<CItem>, int, int, int);
CStringW GetStringCommonByKey(const CStringW&);
MS2Ptr<CMsgBoxData> FUN_140d73f20(CStringW, int);
void FUN_140d73c60(MS2Ptr<CMsgBoxData>);
int FUN_140718170(const CString&);
int FUN_140bd09c0(void*);

// @0x140e4df70
UIItemPetBoxDialog::UIItemPetBoxDialog()
{
    m_boxItemId = 0;
    m_multi = false;
    m_sent = false;
    m_80 = 0;
}

// @0x140e4e150
UIItemPetBoxDialog::~UIItemPetBoxDialog()
{
    DestroyItemSlotBag(m_bagId);
}

// @0x140e4e2f0
CString UIItemPetBoxDialog::GetTypeName() { return "ItemPetBoxDialog"; }

// @0x140e4e340
int UIItemPetBoxDialog::vfunc_65()
{
    if (UIDialog::vfunc_65() == 0)
        return 0;
    return 1;
}

// @0x140e4e370
void UIItemPetBoxDialog::vfunc_26()
{
    UIDialog::vfunc_26();
    m_singleOpen = 0;
    m_multiOpen = 0;
    m_itemBox = 0;
    m_resultItem = 0;
    m_skipEffect = 0;
    m_previewSingle = 0;
    m_previewMulti = 0;
    m_closeSingle = 0;
    m_closeMulti = 0;
}

// @0x140e4e450
void UIItemPetBoxDialog::vfunc_67()
{
    UIDialog::vfunc_67();
    ClearCards();
    ReleaseSlotBinds();
}

// @0x140e4e490
void UIItemPetBoxDialog::OnLoadComplete()
{
    m_multi = false;
    m_sent = false;
    UIDialog::OnLoadComplete();
    BindCloseButton("m_closeButton");
    if (reinterpret_cast<UICashAttendDialog*>(this)->FUN_140bc6d10<ASButton>("m_singleOpenButton", reinterpret_cast<MS2Ptr<ASButton>&>(m_singleOpen)).get())
        m_singleOpen->AddClickHandler(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &UIItemPetBoxDialog::FUN_140e4fa60), (void*)0);
    if (reinterpret_cast<UICashAttendDialog*>(this)->FUN_140bc6d10<ASButton>("m_multiOpenButton", reinterpret_cast<MS2Ptr<ASButton>&>(m_multiOpen)).get())
        m_multiOpen->AddClickHandler(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &UIItemPetBoxDialog::FUN_140e4fa60), (void*)1);
    if (reinterpret_cast<UIItemTreasureMapDialog*>(this)->FUN_140c57ce0("m_petPreviewSingle", m_previewSingle).get()) {
        if (m_previewSingle->FUN_140bbe640<ASButton>("m_petPreviewClose", m_closeSingle).get())
            m_closeSingle->AddClickHandler(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &UIItemPetBoxDialog::OnClosePreview), 0);
    }
    if (reinterpret_cast<UIItemTreasureMapDialog*>(this)->FUN_140c57ce0("m_petPreviewMulti", m_previewMulti).get()) {
        if (m_previewMulti->FUN_140bbe640<ASButton>("m_petPreviewClose", m_closeMulti).get())
            m_closeMulti->AddClickHandler(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &UIItemPetBoxDialog::OnClosePreview), 0);
    }
    reinterpret_cast<UIItemTreasureMapDialog*>(this)->FUN_140c57ce0("m_itemBox", m_itemBox);
    reinterpret_cast<UIItemTreasureMapDialog*>(this)->FUN_140c57ce0("m_resultItem", m_resultItem);
    BindCheckBox("m_isSkipEffect", m_skipEffect);
    InitItemData();
}

// @0x140e4ecb0
void UIItemPetBoxDialog::vfunc_79(void* p)
{
#define PETBOX_PKT static_cast<CInPacket*>(p)
    UIDialog::vfunc_79(p);
    if (PETBOX_PKT->GetOpcode() == 0xf5) {
        if (m_30 == 0)
            return;
        m_sent = false;
        unsigned reset = PETBOX_PKT->ReadUInt8();
        if (reset == 1) {
            PETBOX_ITEMS.clear();
            m_special2.clear();
            bool hasSpecial = false;
            int n = PETBOX_PKT->ReadInt32();
            PETBOX_ITEMS.resize(n);
            for (int i = 0; i < n; ++i) {
                PETBOX_ITEMS[i].m_itemId = PETBOX_PKT->ReadInt32();
                PETBOX_ITEMS[i].m_count = PETBOX_PKT->ReadInt32();
                PETBOX_ITEMS[i].SetRank(PETBOX_PKT->ReadInt32());
                bool special = PETBOX_PKT->ReadBool();
                if (special)
                    m_special2.insert(PETBOX_ITEMS[i]);
                if (IsSpecialItem(PETBOX_ITEMS[i]) == true)
                    hasSpecial = true;
            }
            FUN_140e504e0();
            ShowPetCards();
            m_itemBox->vfunc_13("result");
            PlaySystemSound(s_sndOpen, "");
            if (PETBOX_ITEMS.size() > 1)
                PlaySystemSound(s_snd10, "");
            MS2Ptr<ASMovieClip> fw = m_itemBox->FUN_1409b4560("m_fireworkEffect");
            if (fw.get()) {
                fw->vfunc_4(hasSpecial);
                if (hasSpecial) {
                    fw->vfunc_12(1);
                    PlaySystemSound(s_sndSpecial, "");
                }
            }
        }
    }
#undef PETBOX_PKT
}

// @0x140e4f1e0
int UIItemPetBoxDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs))
        return 1;
    if (_stricmp(szMethod, "onSendOpenBox") == 0) {
        if (FUN_140e51ca0() == 0)
            SendOpenBox();
        else {
            m_resultItem->vfunc_4(false);
            m_itemBox->vfunc_15("idle");
        }
    }
    return 0;
}

// @0x140e4f2e0
void UIItemPetBoxDialog::vfunc_25(void* a, TPtr<Unk_UISwfEntity_25> tp, void* b, void* c)
{
    if (tp.get() == 0 || b == 0)
        return;
    int idx = FUN_140718170(*static_cast<const CString*>(c));
    if (idx < 0 || idx > (int)m_cards.size())
        return;
    if (m_cards[idx].m_avatar == 0)
        return;
    Unk_PetBoxActor* actor = m_cards[idx].m_avatar->vfunc_24();
    if (!actor)
        return;
    m_cards[idx].m_avatar->vfunc_28(a, tp, b, c);
    Unk_PetBoxCameraData data;
    reinterpret_cast<Unk_ModelViewCamera*>(&data)->ApplyRideeCamera();
    data.f1c = 300.0f;
    data.target += actor->vfunc_18();
    data.eye += data.target;
    reinterpret_cast<Unk_PetBoxCamera*>(reinterpret_cast<UIAvatarBase*>(m_cards[idx].m_avatar.operator->())->GetView().operator->())->vfunc_13(data);
}

// @0x140e4f5a0
void UIItemPetBoxDialog::vfunc_16()
{
    UISwfEntity::vfunc_16();
    UnloadAllRenderTargets();
}

// @0x140e4f5d0
bool UIItemPetBoxDialog::vfunc_17()
{
    if (!UIDialog::vfunc_17())
        return false;
    LoadAllRenderTargets();
    return true;
}

// @0x140e4f610
int UIItemPetBoxDialog::vfunc_o178_1(void* av)
{
    if (!av)
        return 0;
    int found = 0;
    for (size_t i = 0; i < m_cards.size(); ++i) {
        if (m_cards[i].m_avatar.get() == av) {
            found = (int)i;
            break;
        }
    }
    if (found >= 0)
        LoadCardRenderTarget(found);
    return 1;
}

// @0x140e4f6d0
void UIItemPetBoxDialog::LoadCardRenderTarget(int idx)
{
    if (idx > (int)m_cards.size())
        return;
    if (m_cards[idx].m_clip.get())
        m_cards[idx].m_clip->Invoke("loadRenderTarget", StringFormat(L"{0}", idx));
}

// @0x140e4f7d0
void UIItemPetBoxDialog::LoadAllRenderTargets()
{
    for (size_t i = 0; i < m_cards.size(); ++i) {
        if (m_cards[i].m_clip.get())
            m_cards[i].m_clip->Invoke("loadRenderTarget", StringFormat(L"{0}", i));
    }
}

// @0x140e4f8e0
void UIItemPetBoxDialog::UnloadAllRenderTargets()
{
    for (size_t i = 0; i < m_cards.size(); ++i) {
        if (m_cards[i].m_clip.get())
            m_cards[i].m_clip->Invoke("unloadRenderTarget");
    }
}

// @0x140e4f9a0
void UIItemPetBoxDialog::ClearCards()
{
    UnloadAllRenderTargets();
    m_cards.clear();
}

// @0x140e4f9e0
void UIItemPetBoxDialog::ReleaseSlotBinds()
{
    for (size_t i = 0; i < PETBOX_BINDS.size(); ++i)
        DestroyItemSlotBag(m_slotBinds[i]);
    PETBOX_BINDS.clear();
}

// @0x140e4fa60
void UIItemPetBoxDialog::FUN_140e4fa60(const Scaleform::GFx::FunctionHandler::Params& params)
{
    if (m_30 == 0)
        return;
    if (m_previewSingle.get())
        m_previewSingle->vfunc_3(0);
    if (m_previewMulti.get())
        m_previewMulti->vfunc_3(0);
    int v = FUN_140bd09c0(params.pUserData);
    if (v != 0 && v != 1)
        return;
    if (v == 0)
        m_multi = false;
    else
        m_multi = true;
    FUN_140e51e40();
}

// @0x140e4fb70
void UIItemPetBoxDialog::OnClosePreview(const Scaleform::GFx::FunctionHandler::Params&)
{
    if (m_30 == 0)
        return;
    if (m_previewSingle.get())
        m_previewSingle->vfunc_3(0);
    if (m_previewMulti.get())
        m_previewMulti->vfunc_3(0);
}

// @0x140e4fc30
void UIItemPetBoxDialog::SetBoxItemId(int id) { m_boxItemId = id; }

// @0x140e4fc50
bool UIItemPetBoxDialog::FUN_140e4fc50(int result, const CMsgBoxData&)
{
    if (result == 0)
        (((CUIService*)(TSingleton<CUIService>::GetInstance()))->OpenDialog((eUIClassID)(0x4ec1)));
    return true;
}

// @0x140e4fc90
bool UIItemPetBoxDialog::IsSpecialItem(const ItemEntity& e)
{
    if (m_special1.find(e) != m_special1.end())
        return true;
    if (m_special2.find(e) != m_special2.end())
        return true;
    return false;
}

// @0x140e4fd60
bool UIItemPetBoxDialog::InitItemData()
{
    if (m_30 == 0)
        return false;
    Unk_PetBoxSelf* self = ((Unk_PetBoxSelf*)((WorldService*)(WorldService::GetInstance()))->GetLocalPlayer());
    if (self == 0)
        return false;
    MS2Ptr<CItemData> data = FUN_14053f870(m_boxItemId);
    if (data == 0)
        return false;
    if (data->function.name != L"OpenPetBox")
        return false;
    std::vector<int> ids = PETBOX_ATTR(data)->GetIntArray(L"unCommonBoxId", std::vector<int>());
    std::vector<ItemDropResult> drops;
    for (size_t i = 0; i < ids.size(); ++i)
        TSingleton<ItemDropTable>::GetInstance()->GetBoxItems(ids[i], drops);
    std::vector<ItemDropResult> filtered;
    for (size_t i = 0; i < drops.size(); ++i) {
        ItemDropResult* d = &drops[i];
        MS2Ptr<CItemData> idata = FUN_14053f870(d->vfunc_o18_0());
        if (idata == 0)
            continue;
        if (!reinterpret_cast<ItemLimit*>(reinterpret_cast<char*>(idata.operator->()) + 0x138)->IsJobRecommended(self->GetJobGroupId()))
            continue;
        if (static_cast<Unk_PetBoxData*>(idata.operator->())->IsGenderAllowed(self->GetGender()) == 0)
            continue;
        filtered.push_back(*d);
    }
    ATL::CAtlArray<MS2Ptr<CItem> > items;
    m_special1.clear();
    for (size_t i = 0; i < filtered.size(); ++i) {
        ItemDropResult* d = &filtered[i];
        MS2Ptr<CItem> item(new CItem);
        if (item->FUN_14052b130(d->vfunc_o18_0(), d->vfunc_o18_1(), 0) != 0) {
            item->SetCountClamped(d->vfunc_o18_2());
            items.Add(item);
        }
        m_special1.insert(ItemEntity(d->vfunc_o18_0(), d->vfunc_o18_1(), d->vfunc_o18_2(), false, false, false, false));
    }
    DestroyItemSlotBag(m_bagId);
    MS2Ptr<CItem> (*getter)(void*, int) = GetItemFromArray;
    CreateItemSlotBag(m_bagId, (unsigned)items.GetCount(), (void*)&items, getter, 0x415, 0x800);
    ASObj obj(2);
    obj.SetStringMember("bagId", m_bagId);
    m_30->Invoke("initItemData", obj.GetValue());
    return true;
}

// @0x140e504e0
void UIItemPetBoxDialog::FUN_140e504e0()
{
    if (m_30 == 0)
        return;
    if (PETBOX_ITEMS.empty())
        return;
    ReleaseSlotBinds();
    if (PETBOX_ITEMS.size() == 1) {
        MS2Ptr<ASMovieClip> single = m_resultItem->FUN_1409b4560("m_singleItem");
        if (single == 0)
            return;
        MS2Ptr<ASMovieClip> slot = single->FUN_1409b4560("m_itemSlot");
        if (slot == 0)
            return;
        MS2Ptr<ASLabel> name = single->FUN_140c436d0<ASLabel>("m_itemName");
        if (name == 0)
            return;
        ItemEntity& e = PETBOX_ITEMS[0];
        MS2Ptr<CItem> item(new CItem);
        if (item->FUN_14052b130(e.vfunc_o18_0(), e.vfunc_o18_1(), 0) == 0)
            return;
        MS2Ptr<ASMovieClip> unc = single->FUN_1409b4560("m_uncommonEffect");
        if (unc.get()) {
            if (IsSpecialItem(e) == true)
                unc->vfunc_4(true);
            else
                unc->vfunc_4(false);
        }
        item->SetCountClamped(e.vfunc_o18_2());
        CString bagKey;
        bagKey.Format("ItemLullu_%s_%d", (const char*)GetTypeName(), 1);
        unsigned count = item->GetCount();
        CStringW txt = StringFormat(L"{0} X {1}", item->FUN_140527b10(), count);
        CreateItemInfoSlot(bagKey, MS2Ptr<CItem>(item), 0, 0x415, 0x800);
        static_cast<Unk_PetBoxClip*>(slot.operator->())->SetStringMember("binding", bagKey);
        name->FUN_1422e4b80(txt);
        PETBOX_BINDS.push_back(bagKey);
        m_30->Invoke("SetMultiType", false);
        return;
    } else {
        size_t n = PETBOX_ITEMS.size();
        size_t cap = 10;
        size_t count = (std::min)(cap, n);
        for (size_t i = 0; i < count; ++i) {
            size_t k = i + 1;
            CString nm = StringFormat("m_multi{0}", k);
            MS2Ptr<ASMovieClip> multi = m_resultItem->FUN_1409b4560(nm);
            if (multi == 0)
                continue;
            MS2Ptr<ASMovieClip> slot = multi->FUN_1409b4560("m_itemSlot");
            if (slot == 0)
                continue;
            CString bagKey;
            if (i < PETBOX_ITEMS.size()) {
                ItemEntity& e = PETBOX_ITEMS[i];
                MS2Ptr<CItem> item(new CItem);
                if (item->FUN_14052b130(e.vfunc_o18_0(), e.vfunc_o18_1(), 0) == 0)
                    continue;
                item->SetCountClamped(e.vfunc_o18_2());
                bagKey.Format("ItemLullu_%s_%d", (const char*)GetTypeName(), i + 1);
                CreateItemInfoSlot(bagKey, MS2Ptr<CItem>(item), (int)i, 0x415, 0x800);
                PETBOX_BINDS.push_back(bagKey);
                MS2Ptr<ASMovieClip> unc = multi->FUN_1409b4560("m_uncommonEffect");
                if (unc.get()) {
                    if (IsSpecialItem(e) == true) {
                        unc->vfunc_4(true);
                        unc->vfunc_12(1);
                    } else
                        unc->vfunc_4(false);
                }
                static_cast<Unk_PetBoxClip*>(slot.operator->())->SetStringMember("binding", bagKey);
            }
        }
        m_30->Invoke("SetMultiType", true);
    }
}

// @0x140e511f0
void UIItemPetBoxDialog::ShowPetCards()
{
    if (m_30 == 0)
        return;
    ClearCards();
    if (PETBOX_ITEMS.empty())
        return;
    if (PETBOX_ITEMS.size() == 1) {
        if (m_previewSingle == 0)
            return;
        MS2Ptr<ASMovieClip> card = m_previewSingle->FUN_1409b4560("m_petCard1");
        if (card == 0)
            return;
        SetPetCardInfo(card, PETBOX_ITEMS[0]);
        MS2Ptr<CItemData> idata = FUN_14053f870(PETBOX_ITEMS[0].m_itemId);
        if (idata.get() != 0) {
            if (static_cast<Unk_PetBoxData*>(idata.operator->())->IsPetItem()) {
                UIAvatarPet* av = new UIAvatarPet(idata.get());
                av->vfunc_1(this);
                Unk_PetBoxCard c;
                c.m_avatar.AssignRaw(av);
                c.m_clip = card;
                c.m_clip->vfunc_3(1);
                m_cards.push_back(c);
            }
        }
        m_previewSingle->vfunc_3(1);
        m_previewSingle->vfunc_12(1);
        return;
    } else {
        if (m_previewMulti == 0)
            return;
        MS2Ptr<ASMovieClip> movie = m_previewMulti->FUN_1409b4560("m_petCardMovie");
        if (movie == 0)
            return;
        size_t n = PETBOX_ITEMS.size();
        size_t cap = 10;
        size_t count = (std::min)(cap, n);
        for (size_t i = 0; i < count; ++i) {
            size_t k = i + 1;
            CString nm = Unk_SocketFormat("m_petCard{0}", k);
            MS2Ptr<ASMovieClip> card = movie->FUN_1409b4560(nm);
            if (card == 0)
                continue;
            SetPetCardInfo(card, PETBOX_ITEMS[i]);
            MS2Ptr<CItemData> idata = FUN_14053f870(PETBOX_ITEMS[i].m_itemId);
            if (idata.get() != 0) {
                if (static_cast<Unk_PetBoxData*>(idata.operator->())->IsPetItem()) {
                    UIAvatarPet* av = new UIAvatarPet(idata.get());
                    av->vfunc_1(this);
                    Unk_PetBoxCard c;
                    c.m_avatar.AssignRaw(av);
                    c.m_clip = card;
                    m_cards.push_back(c);
                }
            }
        }
        m_previewMulti->vfunc_3(1);
        m_previewMulti->vfunc_12(1);
    }
}

// @0x140e519b0
void UIItemPetBoxDialog::SetPetCardInfo(MS2Ptr<ASMovieClip> clip, const ItemEntity& item)
{
    if (clip == 0)
        return;
    MS2Ptr<ASTextField> txt = clip->FUN_1409b4620("m_petNameText");
    if (txt == 0)
        return;
    CStringW name = TSingleton<CStringTable>::GetInstance()->FUN_141811980(1, item.m_itemId);
    txt->SetTextW(name);
    if (const_cast<ItemEntity&>(item).vfunc_o18_1() == 2)
        clip->vfunc_15("rare");
    else if (const_cast<ItemEntity&>(item).vfunc_o18_1() == 3)
        clip->vfunc_15("elite");
    else if (const_cast<ItemEntity&>(item).vfunc_o18_1() == 4)
        clip->vfunc_15("excellent");
    else
        clip->vfunc_15("normal");
}

// @0x140e51ca0
int UIItemPetBoxDialog::FUN_140e51ca0()
{
    MS2Ptr<CItemData> data = FUN_14053f870(m_boxItemId);
    if (data == 0)
        return -1;
    CString tag = PETBOX_ATTR(data)->GetString(L"itemTag", "");
    int tagId = (int)TSingleton<CItemDataTable>::GetInstance()->GetTagByName(tag);
    if (tagId == 0)
        return -1;
    int have = g_143ab2a90.FUN_140a5f7b0(tagId, 0);
    int need = 1;
    if (m_multi)
        need = 10;
    if (have < need)
        return 1;
    return 0;
}

// @0x140e51e40
void UIItemPetBoxDialog::FUN_140e51e40()
{
    if (m_30 == 0)
        return;
    int r = FUN_140e51ca0();
    if (r == -1) {
        return;
    } else if (r == 1) {
        if (MS2Ptr<CMsgBoxData> box = FUN_140d73f20(GetStringCommonByKey(L"s_lullu_key_not_enough_key"), 1)) {
            box->SetCallback(Delegate<bool(int, const CMsgBoxData&)>(this, &UIItemPetBoxDialog::FUN_140e4fc50));
            FUN_140d73c60(box);
        }
        return;
    }
    m_30->Invoke("enableComponent", false);
    if (m_skipEffect->IsSelected()) {
        SendOpenBox();
        return;
    }
    m_resultItem->vfunc_4(false);
    m_itemBox->vfunc_13("open");
}

// @0x140e52110
void UIItemPetBoxDialog::SendOpenBox()
{
    if (m_sent == true)
        return;
    CStringW mode = L"single";
    if (m_multi)
        mode = L"multi";
    int r = FUN_140e51ca0();
    if (r != 0) {
        m_resultItem->vfunc_4(false);
        m_itemBox->vfunc_15("idle");
        return;
    }
    MS2Ptr<CItemData> data = FUN_14053f870(m_boxItemId);
    if (data == 0)
        return;
    CString tag = PETBOX_ATTR(data)->GetString(L"itemTag", "");
    int tagId = (int)TSingleton<CItemDataTable>::GetInstance()->GetTagByName(tag);
    MS2Ptr<CItem> inv = g_143ab2a90.FindItemByTag(tagId);
    if (inv == 0)
        return;
    if (g_143ab2a90.FUN_140a63880(inv.operator->(), mode) == 0)
        vfunc_67();
    else
        m_sent = true;
}

// @0x140e52670
template <> MS2Ptr<ASCheckBox> UISwfEntity::GetChild<ASCheckBox>(const CString& name)
{
    if (m_30 == 0)
        return MS2Ptr<ASCheckBox>(0);
    return m_30->FUN_140c11f50<ASCheckBox>(name);
}

// @0x140e52700
MS2Ptr<ASCheckBox> UIItemPetBoxDialog::BindCheckBox(const CString& name, MS2Ptr<ASCheckBox>& member)
{
    member = GetChild<ASCheckBox>(name);
    return member;
}

// ---- hooks ----
MS2_REPLACE_METHOD(0x140E4E2F0, UIItemPetBoxDialog, GetTypeName, 61, 0xA2EBBBF1);
MS2_REPLACE_METHOD(0x140E4E340, UIItemPetBoxDialog, vfunc_65, 37, 0x4561E126);
MS2_REPLACE_METHOD(0x140E4E370, UIItemPetBoxDialog, vfunc_26, 213, 0x44B68A87);
MS2_REPLACE_METHOD(0x140E4E450, UIItemPetBoxDialog, vfunc_67, 44, 0x3C78319B);
MS2_REPLACE_METHOD(0x140E4E490, UIItemPetBoxDialog, OnLoadComplete, 2064, 0x2E8A2E45);
MS2_REPLACE_METHOD(0x140E4F1E0, UIItemPetBoxDialog, vfunc_28, 248, 0x7ABDB895);
MS2_REPLACE_METHOD(0x140E4F2E0, UIItemPetBoxDialog, vfunc_25, 683, 0x523E66EC);
MS2_REPLACE_METHOD(0x140E4F5A0, UIItemPetBoxDialog, vfunc_16, 34, 0x867535AC);
MS2_REPLACE_METHOD(0x140E4F5D0, UIItemPetBoxDialog, vfunc_17, 47, 0xA0F8AF34);
MS2_REPLACE_METHOD(0x140E4F6D0, UIItemPetBoxDialog, LoadCardRenderTarget, 244, 0x58DDE214);
MS2_REPLACE_METHOD(0x140E4F7D0, UIItemPetBoxDialog, LoadAllRenderTargets, 251, 0xFE9B33A1);
MS2_REPLACE_METHOD(0x140E4F8E0, UIItemPetBoxDialog, UnloadAllRenderTargets, 176, 0x6354CE48);
MS2_REPLACE_METHOD(0x140E4F9A0, UIItemPetBoxDialog, ClearCards, 43, 0x34618B18);
MS2_REPLACE_METHOD(0x140E4F9E0, UIItemPetBoxDialog, ReleaseSlotBinds, 117, 0x33366119);
MS2_REPLACE_METHOD(0x140E4FA60, UIItemPetBoxDialog, FUN_140e4fa60, 259, 0x6554B4A2);
MS2_REPLACE_METHOD(0x140E4FB70, UIItemPetBoxDialog, OnClosePreview, 182, 0x99CD677A);
MS2_REPLACE_METHOD(0x140E4FC30, UIItemPetBoxDialog, SetBoxItemId, 25, 0x9BF64FA6);
MS2_REPLACE_METHOD(0x140E4FC50, UIItemPetBoxDialog, FUN_140e4fc50, 50, 0x3FD9DD97);
MS2_REPLACE_METHOD(0x140E4FC90, UIItemPetBoxDialog, IsSpecialItem, 187, 0x768844F2);
MS2_REPLACE_METHOD(0x140E519B0, UIItemPetBoxDialog, SetPetCardInfo, 734, 0x3387E636);
MS2_REPLACE_METHOD(0x140E51CA0, UIItemPetBoxDialog, FUN_140e51ca0, 401, 0x3F87147F);
MS2_REPLACE_METHOD(0x140E52670, UISwfEntity, GetChild<ASCheckBox>, 139, 0x2C5278D7);
MS2_REPLACE_METHOD(0x140E52700, UIItemPetBoxDialog, BindCheckBox, 138, 0x48954D03);
MS2_REPLACE_METHOD_VIA(0x140E4F610, UIItemPetBoxDialog, IUIAvatarEventListener, vfunc_o178_1, 178, 0xCEE1D1D9);
