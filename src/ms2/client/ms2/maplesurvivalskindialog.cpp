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
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/astextfield.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/ms2ptr_impl.h"

CStringW GetStringCommonByKey(const CStringW& strKey);
void ShowSystemNotice(const CStringW& strText, int nType, int nFlag);
__int64 GetServerTime();                                                // now

typedef Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)> SkinClickDelegate;

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
    m_category = BindList(m_30.operator->(), "m_category");
    m_okButton = m_30->FUN_140acce30<ASButton>("m_okButton");
    m_cancelButton = m_30->FUN_140acce30<ASButton>("m_cancelButton");
    // Not restored: the m_skinPreview render target (loadRenderTarget / unloadRenderTarget, the 3D preview of the
    // selected row, GMS 0x7a5440) and the row tooltip (0x7a4bb0).
    if (m_okButton.get() != 0)
        m_okButton.operator->()->AddClickHandler(SkinClickDelegate(this, &UIMapleSurvivalSkinDialog::OnOk), 0);
    if (m_cancelButton.get() != 0)
        m_cancelButton.operator->()->AddClickHandler(SkinClickDelegate(this, &UIMapleSurvivalSkinDialog::OnCancel), 0);
    if (m_category.get() != 0)
    {
        static const wchar_t* const kCategory[3] =
            { L"s_maple_survival_ui_skin_category1", L"s_maple_survival_ui_skin_category2", L"s_maple_survival_ui_skin_category3" };
        m_category.operator->()->FUN_1422dd1d0();
        for (int i = 0; i < 3; ++i)
        {
            ASObj obj(2);
            obj.SetWStringMember("label", Key(kCategory[i]));
            m_category.operator->()->AddItem(obj);
        }
        m_category.operator->()->SetSelectedIndex(m_nSlot);
        m_category.operator->()->AddListIndexChangeListener(SkinClickDelegate(this, &UIMapleSurvivalSkinDialog::OnCategoryChange));
    }
    RefreshSkins();
}

void UIMapleSurvivalSkinDialog::vfunc_26()
{
    UIDialog::vfunc_26();
    m_items = 0;
    m_category = 0;
    m_okButton = 0;
    m_cancelButton = 0;
    m_ids.clear();
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
