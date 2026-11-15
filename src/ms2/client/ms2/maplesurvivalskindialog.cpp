// maplesurvivalskindialog.cpp - Mushking Royale restore: UIMapleSurvivalSkinDialog. NOT recovered KMS code and not byte-matched; ported from the GMS 2019
// x86 client (the "GMS 0x..." VAs are that exe's, image base 0x400000). Branch restore/mushking only.
// MS2-UNIT: maplesurvivalskindialog
// MS2-NO-EXE: 0x140db5395 Mushking Royale restore (restore/mushking only)
#define MS2_THIS_FILE ""
#define MS2_ASUICOMPONENT_SLOTS
#include "ms2/placeholder/ms2stdafx.h"
#ifndef MS2_HOOK_DLL

#include "ms2/placeholder/ascorelist.h"
#include "ms2/client/ms2/maplesurvivalskindialog.h"
#include "ms2/client/ms2/maplesurvivalpassdialog.h"
#include "ms2/client/ms2/maplesurvivalui.h"
#include "ms2/client/ms2/uiservice.h"
#include "ms2/placeholder/asbutton.h"
#include "ms2/placeholder/asbuttonbar.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/astextfield.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/pcgemequip.h"
#include "ms2/client/ms2/additionalcli.h"
#include "ms2/client/ms2/avatarpc.h"
#include "ms2/client/ms2/gameobject.h"
#include "ms2/client/ms2/uiavatarbase.h"
#include "ms2/client/ms2/uimodelview.h"
#include "ms2/client/ms2/uirenderview.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/astooltip.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/client/ms2/uiugcbannerdialog.h"   // Unk_DateParts

CStringW GetStringCommonByKey(const CStringW& strKey);
void ShowSystemNotice(const CStringW& strText, int nType, int nFlag);
__int64 GetServerTime();                                                // now

typedef Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)> SkinClickDelegate;
template <> MS2Ptr<ASButtonBar> UISwfEntity::GetChild<ASButtonBar>(const CString& strName);   // 0x140c02870
template <> MS2Ptr<ASMovieClip> UISwfEntity::GetChild<ASMovieClip>(const CString& strName);   // 0x140ba7930
Unk_DateParts* FUN_14088dfa0(Unk_DateParts* pOut, __int64 nTime, int nHourOffset);   // a time broken down
MS2Ptr<CItemData> FUN_14053f870(int nItemId);   // the item data of an id

namespace
{
CStringW Key(const wchar_t* key)
{
    return GetStringCommonByKey(CStringW(key));
}

void Notice(const wchar_t* key)
{
    ShowSystemNotice(Key(key), 1, 1);
}

MS2Ptr<ASScrollingList> BindList(AScript* p, const char* name)
{
    Scaleform::GFx::Value v = p->GetMember(name);
    if (!v.IsObject())
        return MS2Ptr<ASScrollingList>(0);
    return MS2Ptr<ASScrollingList>(new ASScrollingList(v, p->FUN_14198f250()));
}

// the owned skin (id, expire) of a slot, or 0
const std::pair<int, __int64>* FindOwned(const SurvivalSkinSlot& slot, int nId)
{
    for (size_t i = 0; i < slot.skins.size(); ++i)
        if (slot.skins[i].first == nId)
            return &slot.skins[i];
    return 0;
}
}

// The Mushking shrink effect (additionaleffect 71000068, feature SurvivalContents02) that GMS 0x7a64c0 puts on the
// preview avatar, so the preview looks like a match.
static const int kSurvivalScaleEffect = 71000068;
static const int kTailPreviewCount = 3;   // GMS 0x7a5440 passes 3 to the tail preview (0xca4540)

UIMapleSurvivalSkinDialog::UIMapleSurvivalSkinDialog() : m_nSlot(0)
{
}

UIMapleSurvivalSkinDialog::~UIMapleSurvivalSkinDialog()
{
}

// GMS 0x7a4890
CString UIMapleSurvivalSkinDialog::GetTypeName()
{
    return "MapleSurvivalSkinDialog";
}

// GMS 0x7a5eb0: close / drag bar, the skin list, the three categories, ok (equip) and cancel (take off).
void UIMapleSurvivalSkinDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    if (m_30 == 0)
    {
        vfunc_67();
        return;
    }
    BindCloseButton(CString("m_closeButton"));
    BindDragBar(CString("m_dragBar"));
    m_items = BindList(m_30.operator->(), "m_items");
    m_category = GetChild<ASButtonBar>("m_category");
    m_okButton = m_30->FUN_140acce30<ASButton>("m_okButton");
    m_cancelButton = m_30->FUN_140acce30<ASButton>("m_cancelButton");
    m_skinPreview = GetChild<ASMovieClip>("m_skinPreview");   // GMS 0x759cc0
    if (m_items.get() != 0)
        m_items.operator->()->AddListIndexChangeHandler(
            SkinClickDelegate(this, &UIMapleSurvivalSkinDialog::OnItemSelect), 0);
    if (m_okButton.get() != 0)
        m_okButton.operator->()->AddClickHandler(SkinClickDelegate(this, &UIMapleSurvivalSkinDialog::OnOk), 0);
    if (m_cancelButton.get() != 0)
        m_cancelButton.operator->()->AddClickHandler(SkinClickDelegate(this, &UIMapleSurvivalSkinDialog::OnCancel), 0);
    if (m_category.get() != 0)
    {
        static const wchar_t* const kCategory[3] =
            { L"s_maple_survival_ui_skin_category1", L"s_maple_survival_ui_skin_category2", L"s_maple_survival_ui_skin_category3" };
        // GMS 0x7a5eb0: the category bar's clikIndexChange (0x1177cf0), the three labels (0x11762f0), validateNow
        // (vtable slot 24) and selectedIndex (0x1177df0).
        m_category.operator->()->AddIndexChangeHandler(
            SkinClickDelegate(this, &UIMapleSurvivalSkinDialog::OnCategoryChange), 0);
        for (int i = 0; i < 3; ++i)
        {
            ASObj obj(2);
            obj.SetWStringMember("label", Key(kCategory[i]));
            m_category.operator->()->AddItem(obj);
        }
        m_category.operator->()->vfunc_24(true);
        m_category.operator->()->SetSelectedIndex(m_nSlot);
    }
    RefreshSkins();
    CreateAvatar();
}

// GMS 0x7a5270
void UIMapleSurvivalSkinDialog::vfunc_26()
{
    UIDialog::vfunc_26();
    m_items = 0;
    m_category = 0;
    m_okButton = 0;
    m_cancelButton = 0;
    m_ids.clear();
    UnloadRenderTarget();
    m_skinPreview = 0;
    m_avatar = 0;
}

// GMS 0x7a4b60
void UIMapleSurvivalSkinDialog::vfunc_16()
{
    UISwfEntity::vfunc_16();
    UnloadRenderTarget();
}

// GMS 0x7a64a0
bool UIMapleSurvivalSkinDialog::vfunc_17()
{
    if (!UIDialog::vfunc_17())
        return false;
    LoadRenderTarget();
    return true;
}

// GMS 0x7a48f0: the preview's mouse areas (rotate, zoom) go to the avatar.
int UIMapleSurvivalSkinDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs))
        return 1;
    if (m_avatar.get() != 0 && m_avatar->vfunc_27(szMethod, pArgs, nArgs))
        return 1;
    return 0;
}

// GMS 0x7a4950: the render target is ready; frame the character camera on the avatar.
void UIMapleSurvivalSkinDialog::vfunc_25(void* p1, TPtr<Unk_UISwfEntity_25> p2, void* p3, void* p4)
{
    if (m_avatar.get() == 0)
        return;
    GameObject* pActor = m_avatar->vfunc_24();
    if (pActor == 0)
        return;
    m_avatar->vfunc_28(p1, p2, p3, p4);
    Unk_ModelViewCamera kCamera;
    kCamera.ApplyCharCamera();
    kCamera.m_kTarget.z -= 30.0f;
    kCamera.m_fMinDistance = 300.0f;
    kCamera.m_kTarget += pActor->vfunc_18();
    kCamera.m_kPosition += kCamera.m_kTarget;
    m_avatar->GetView()->vfunc_13(kCamera);
}

// GMS 0x7a64c0: the avatar model is loaded; give it the Mushking shrink effect and show the render target.
int UIMapleSurvivalSkinDialog::vfunc_o178_1(void* pAvatar)
{
    if (pAvatar == 0)
        return 0;
    AvatarPC* pPC = m_avatar.get() != 0 ? m_avatar->GetAvatarPC() : 0;
    if (pPC != 0)
    {
        MS2Ptr<AdditionalCli> spEffect;
        spEffect.AssignRaw(new AdditionalCli());
        spEffect->InitLocal(pPC, kSurvivalScaleEffect, 1, 0);   // GMS 0x682030
        pPC->AddAdditionalCli(spEffect);                         // GMS 0x9744a0
    }
    LoadRenderTarget();
    return 1;
}

// GMS 0x7a5ac0: the preview avatar mirrors the local player.
void UIMapleSurvivalSkinDialog::CreateAvatar()
{
    if (m_avatar.get() != 0)
        return;
    WorldService* pWorld = WorldService::GetInstance();
    PC* pPlayer = pWorld != 0 ? reinterpret_cast<PC*>(pWorld->GetLocalPlayer()) : 0;
    if (pPlayer == 0)
        return;
    UIAvatarPC* pAvatar = new UIAvatarPC(pPlayer, false);
    m_avatar.AssignRaw(pAvatar);
    AvatarPC* pPC = pAvatar->GetAvatarPC();
    if (pPC != 0)
    {
        pPC->FUN_1410885b0(true);                                           // GMS 0x973620
        reinterpret_cast<PCGemEquip*>(pPC->GetGemEquip())->FUN_141270610();   // GMS 0xb86a50, 0xa1ae50
    }
    m_avatar->vfunc_1(this);
}

// GMS 0x7a6450
void UIMapleSurvivalSkinDialog::LoadRenderTarget()
{
    if (m_skinPreview.get() != 0)
        m_skinPreview->Invoke("loadRenderTarget", CString(""));
}

// GMS 0x7a4b60, 0x7a5270
void UIMapleSurvivalSkinDialog::UnloadRenderTarget()
{
    if (m_skinPreview.get() != 0)
        m_skinPreview->Invoke("unloadRenderTarget");
}

// GMS 0x7a5440: show the selected row on the avatar: a tail effect, a mount or a glider.
void UIMapleSurvivalSkinDialog::OnItemSelect(const Scaleform::GFx::FunctionHandler::Params&)
{
    if (m_30 == 0 || m_avatar.get() == 0 || m_items.get() == 0)
        return;
    int nCat = SelectedCategory();
    int nRow = m_items.operator->()->GetSelectedIndex();
    if (nCat < 0 || nRow < 0 || nRow >= (int)m_ids.size())
        return;
    int nId = m_ids[nRow];
    if (nId == 0)
        return;
    AvatarPC* pPC = m_avatar->GetAvatarPC();
    if (pPC != 0)
        pPC->FUN_141663ea0();   // GMS 0xb87da0: stop the tail effect
    CMapleSurvivalTable* pTab = &CMapleSurvivalTable::Get();
    std::map<int, SurvivalSkinInfo>::const_iterator it = pTab->m_skins.find(nId);
    if (it == pTab->m_skins.end())
        return;
    int nValue = it->second.value1;   // the tail id, the mount item or the glider item
    if (nCat == 0)
    {
        m_avatar->FUN_1418bd150(kTailPreviewCount, nValue);   // GMS 0xca4540
        return;
    }
    MS2Ptr<CItemData> spData = FUN_14053f870(nValue);   // GMS 0x52c3f0
    if (spData.get() == 0)
        return;
    if (nCat == 1)
        m_avatar->FUN_1418bd050(spData, MS2Ptr<CItem>(0));   // GMS 0xca4e50
    else
    {
        // Not GMS: GMS plays the glider item's skill (0xca44f0). KMS has no glide skills: a glider item names its
        // table/glidedata.xml row in param1, and the avatar glides through the item (the item preview's path,
        // UIAvatarPC::FUN_1418bced0 -> AvatarPC::FUN_1409f42a0).
        m_avatar->FUN_1418bced0(spData);
    }
}

// The skin name / description string tables (string.xml ids 81 mapleSurvivalSkinName, 82 ..Description).
static const int kSkinNameTable = 0x51;
static const int kSkinDescTable = 0x52;

// "{0}"... in a string pack text filled in order ("{3:02d}" style widths are two-digit, zero-padded).
static CStringW FillArgs(CStringW strText, const int* pArgs, int nArgs)
{
    strText.Replace(L"\\n", L"\n");
    for (int i = 0; i < nArgs; ++i)
    {
        CStringW strKey, strWide, strValue, strWideValue;
        strKey.Format(L"{%d}", i);
        strWide.Format(L"{%d:02d}", i);
        strValue.Format(L"%d", pArgs[i]);
        strWideValue.Format(L"%02d", pArgs[i]);
        strText.Replace(strKey, strValue);
        strText.Replace(strWide, strWideValue);
    }
    return strText;
}

// GMS 0x7a4bb0: the row's tooltip. The row object carries "id" and "expireDate" (RefreshSkins); the text is
// s_maple_survival_ui_skin_tooltip with the skin's name and description, then a line with s_item_end_time (or
// s_item_end_time_expired once past) unless the skin never expires (INT64_MAX, GMS numeric_limits<__int64>::max).
void UIMapleSurvivalSkinDialog::vfunc_49(Scaleform::GFx::Value* pRetVal, ASData* pArgs)
{
    Scaleform::GFx::Value arg = pArgs->PopValue();
    AScript row((const Scaleform::GFx::Value&)arg, 2);
    if (row.IsUndefinedOrNull())
        return;
    int nId = 0;
    if (!row.TryGetInt("id", &nId))
        return;
    CString strExpire;
    row.TryGetString("expireDate", strExpire);
    __int64 nExpire = _atoi64(strExpire);
    CStringTable* pStrings = TSingleton<CStringTable>::GetInstance();
    CStringW strName = pStrings->FUN_141811980(kSkinNameTable, nId);
    CStringW strDesc = pStrings->FUN_141811980(kSkinDescTable, nId);
    CStringW strText = GetStringCommonByKey(L"s_maple_survival_ui_skin_tooltip");
    strText.Replace(L"\\n", L"\n");
    strText.Replace(L"{0}", strName);
    strText.Replace(L"{1}", strDesc);
    if (nExpire != _I64_MAX)
    {
        Unk_DateParts kDate;
        FUN_14088dfa0(&kDate, nExpire, 0);
        int args[5] = { kDate.m_year, kDate.m_month, kDate.m_day, kDate.m_hour2, kDate.m_minute };
        strText += L"\n";
        if (nExpire > GetServerTime())
            strText += FillArgs(GetStringCommonByKey(L"s_item_end_time"), args, 5);
        else
            strText += FillArgs(GetStringCommonByKey(L"s_item_end_time_expired"), args, 5);
    }
    ASTooltip tip(1, 2);   // GMS 0x6a1e30(1, 2)
    if (tip.ApplyTextTooltip(strText) != 0)
    {
        tip.SetTooltipAlign(5);   // GMS 0x6a5400(5): "tooltipAlign"
        *pRetVal = tip.GetValue();
    }
}

// The pass window's "+" buttons (GMS 0x7a1420) pick the category before opening / refreshing the window.
void UIMapleSurvivalSkinDialog::SetSlot(int nSlot)
{
    if (nSlot < 0 || nSlot > 2)
        return;
    m_nSlot = nSlot;
    if (m_30 != 0 && m_category.get() != 0)
        m_category.operator->()->SetSelectedIndex(nSlot);
}

int UIMapleSurvivalSkinDialog::SelectedCategory()
{
    int n = m_nSlot;
    if (m_category.get() != 0)
        n = m_category.operator->()->GetSelectedIndex();
    return n >= 0 && n <= 2 ? n : -1;
}

// GMS 0x7a5ea0
void UIMapleSurvivalSkinDialog::OnCategoryChange(const Scaleform::GFx::FunctionHandler::Params&)
{
    int n = SelectedCategory();
    if (n >= 0)
        m_nSlot = n;
    RefreshSkins();
}

// GMS 0x7a5b90: the owned, unexpired skins of the selected category; "active" marks the equipped one.
void UIMapleSurvivalSkinDialog::RefreshSkins()
{
    if (m_30 == 0 || m_items.get() == 0)
        return;
    m_items.operator->()->FUN_1422dd1d0();
    m_ids.clear();
    int nCat = SelectedCategory();
    if (nCat < 0)
        return;
    CMapleSurvivalManager* pMgr = CMapleSurvivalManager::GetInstance();
    CMapleSurvivalTable* pTab = &CMapleSurvivalTable::Get();
    const SurvivalSkinSlot& slot = pMgr->m_skinSlots[nCat];
    __int64 nNow = GetServerTime();
    for (size_t i = 0; i < slot.skins.size(); ++i)
    {
        int nId = slot.skins[i].first;
        __int64 nExpire = slot.skins[i].second;
        std::map<int, SurvivalSkinInfo>::const_iterator it = pTab->m_skins.find(nId);
        if (it == pTab->m_skins.end() || nExpire < nNow)
            continue;
        CString strExpire;
        strExpire.Format("%I64d", nExpire);
        ASObj obj(2);
        obj.SetIntMember("id", nId);
        obj.SetStringMember("expireDate", strExpire);
        obj.SetStringMember("imagePath", it->second.imagePath);
        obj.SetBoolMember("active", nId == slot.equipped);
        m_items.operator->()->AddItem(obj);
        m_ids.push_back(nId);
    }
}

// GMS 0x7a5680: equip the selected skin.
void UIMapleSurvivalSkinDialog::OnOk(const Scaleform::GFx::FunctionHandler::Params&)
{
    if (m_items.get() == 0)
        return;
    int nRow = m_items.operator->()->GetSelectedIndex();
    if (nRow < 0 || nRow >= (int)m_ids.size())
    {
        Notice(L"s_maple_survival_ui_skin_err_no_select_item");
        return;
    }
    int nId = m_ids[nRow];
    int nCat = SelectedCategory();
    if (nId == 0 || nCat < 0)
        return;
    CMapleSurvivalManager* pMgr = CMapleSurvivalManager::GetInstance();
    const SurvivalSkinSlot& slot = pMgr->m_skinSlots[nCat];
    if (slot.equipped == nId)
    {
        Notice(L"s_maple_survival_ui_skin_err_already_puton");
        return;
    }
    const std::pair<int, __int64>* pOwned = FindOwned(slot, nId);
    if (pOwned == 0 || pOwned->second < GetServerTime())
    {
        Notice(L"s_item_err_puton_expired");
        return;
    }
    // GMS also refuses with s_maple_survival_ui_skin_err_not_here when a place check (0x4ab510) fails; that check is
    // not identified, so the server decides.
    pMgr->EquipSkin((unsigned char)nCat, nId);
}

// GMS 0x7a5910: take the category's skin off.
void UIMapleSurvivalSkinDialog::OnCancel(const Scaleform::GFx::FunctionHandler::Params&)
{
    int nCat = SelectedCategory();
    if (m_30 == 0 || nCat < 0)
        return;
    CMapleSurvivalManager* pMgr = CMapleSurvivalManager::GetInstance();
    if (pMgr->m_skinSlots[nCat].equipped == 0)
    {
        Notice(L"s_maple_survival_ui_skin_err_not_puton");
        return;
    }
    pMgr->EquipSkin((unsigned char)nCat, 0);
}

void MushkingUI::Skin_OnSkins()
{
    MS2Ptr<UIDialog> sp = CUIService::GetInstance()->FindDialog((eUIClassID)MS2_UI_MAPLESURVIVAL_SKIN);
    if (sp.get() == 0)
        return;
    static_cast<UIMapleSurvivalSkinDialog*>(sp.operator->())->RefreshSkins();
}

void MushkingUI::RegisterPassDialogs()
{
    CUIService::GetInstance()->RegisterDialog(MS2Ptr<UIDialog>(new UIMapleSurvivalPassDialog));
    CUIService::GetInstance()->RegisterDialog(MS2Ptr<UIDialog>(new UIMapleSurvivalSkinDialog));
}

#endif   // MS2_HOOK_DLL
