// maplesurvivalbuybundledialog.cpp - Mushking Royale restore: UIMapleSurvivalBuyBundleDialog. NOT recovered KMS code and not byte-matched; ported from the GMS 2019
// x86 client (the "GMS 0x..." VAs are that exe's, image base 0x400000). Branch restore/mushking only.
// MS2-UNIT: maplesurvivalbuybundledialog
// MS2-NO-EXE: 0x140db5393 Mushking Royale restore (restore/mushking only)
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#ifndef MS2_HOOK_DLL

#include "ms2/client/ms2/maplesurvivalbuybundledialog.h"
#include "ms2/client/ms2/maplesurvivaldialog.h"
#include "ms2/client/ms2/maplesurvivalui.h"
#include "ms2/client/ms2/uiservice.h"
#include "ms2/placeholder/asbutton.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asitemslot.h"
#include "ms2/placeholder/astextfield.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/ms2ptr_impl.h"

typedef Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)> BundleClickDelegate;

namespace
{
// The item slot child `name` of the movie (GMS 0x79f6f0): wraps the AS member in an ASItemSlot.
MS2Ptr<ASItemSlot> BindItemSlot(AScript* pMovie, const char* name)
{
    Scaleform::GFx::Value v = pMovie->GetMember(name);
    if (!v.IsObject())
        return MS2Ptr<ASItemSlot>(0);
    return MS2Ptr<ASItemSlot>(new ASItemSlot(v, pMovie->FUN_14198f250()));
}

CStringW PriceText(__int64 n)
{
    CStringW s;
    s.Format(L"%I64d", n);
    return s;
}
}

UIMapleSurvivalBuyBundleDialog::UIMapleSurvivalBuyBundleDialog()
    : m_defaultPrice(0), m_bundlePrice(0), m_bonusItemId(0)
{
}

UIMapleSurvivalBuyBundleDialog::~UIMapleSurvivalBuyBundleDialog()
{
}

// GMS 0x79ea20
CString UIMapleSurvivalBuyBundleDialog::GetTypeName()
{
    return "MapleSurvivalBuyBundleDialog";
}

// GMS 0x79f200: only opens while the pass-bundle GameEvent runs (prices and the bonus item come from it).
void UIMapleSurvivalBuyBundleDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    if (m_30 == 0)
    {
        vfunc_67();
        return;
    }
    int nItem = 0;
    if (!GetMapleSurvivalPassBundle(m_defaultPrice, m_bundlePrice, nItem) || m_defaultPrice == 0 || m_bundlePrice == 0 || nItem == 0)
    {
        vfunc_67();
        return;
    }
    m_bonusItemId = nItem;

    m_buyDefault = m_30->FUN_140acce30<ASButton>("m_buyDefault");
    m_buyBundle = m_30->FUN_140acce30<ASButton>("m_buyBundle");
    if (m_buyDefault.get() != 0)
        m_buyDefault.operator->()->AddClickHandler(BundleClickDelegate(this, &UIMapleSurvivalBuyBundleDialog::OnBuyDefault), 0);
    if (m_buyBundle.get() != 0)
        m_buyBundle.operator->()->AddClickHandler(BundleClickDelegate(this, &UIMapleSurvivalBuyBundleDialog::OnBuyBundle), 0);
    m_bonusItem = BindItemSlot(m_30.operator->(), "m_bonusItemSlot");
    Refresh();
}

// GMS 0x79ec70 (close hook): release the children and forget the bundle.
void UIMapleSurvivalBuyBundleDialog::vfunc_26()
{
    UIDialog::vfunc_26();
    m_buyDefault = 0;
    m_buyBundle = 0;
    m_bonusItem = 0;
    m_defaultPrice = 0;
    m_bundlePrice = 0;
    m_bonusItemId = 0;
}

// Fills the prices and the bonus item (GMS 0x79f200 body). Does nothing while the movie is not loaded.
void UIMapleSurvivalBuyBundleDialog::Refresh()
{
    if (m_30 == 0)
        return;
    int nItem = 0;
    __int64 a = 0, b = 0;
    if (!GetMapleSurvivalPassBundle(a, b, nItem))
    {
        vfunc_67();     // the event ended
        return;
    }
    m_defaultPrice = a;
    m_bundlePrice = b;
    m_bonusItemId = nItem;
    if (m_buyDefault.get() != 0)
        m_buyDefault.operator->()->FUN_1422cdfb0(PriceText(m_defaultPrice));
    if (m_buyBundle.get() != 0)
        m_buyBundle.operator->()->FUN_1422cdfb0(PriceText(m_bundlePrice));
    if (m_bonusItem.get() != 0)
        m_bonusItem.operator->()->SetItem(m_bonusItemId, 1, 1);
    // m_originPrice shows the struck-through price only when the bundle is the cheaper one (GMS 0x79f200).
    // In uimaplesurvivalbuybundledialog.gfx m_originPrice is a clip (m_textField + m_strike) inside each buy button,
    // not a root text field; the bundle button's copy carries the struck-through price.
    MS2Ptr<ASTextField> spOrigin;
    if (m_buyBundle.get() != 0)
    {
        Scaleform::GFx::Value v = m_buyBundle.operator->()->GetMember("m_originPrice");
        if (v.IsObject())
        {
            MS2Ptr<AScript> spClip(new AScript(v, m_30->FUN_14198f250()));
            spOrigin = spClip.operator->()->FUN_1409b4620("m_textField");
        }
    }
    if (spOrigin.get() != 0)
        spOrigin.operator->()->SetTextW(m_defaultPrice < m_bundlePrice ? PriceText(m_defaultPrice) : CStringW(L""));
}

// GMS 0x79ed70 / 0x79efe0: buy send (mode 0x22; the manager throttles it), then close the window. GMS checks the
// wallet before sending; the server validates the price here, so the check is left out.
void UIMapleSurvivalBuyBundleDialog::OnBuyDefault(const Scaleform::GFx::FunctionHandler::Params&)
{
    if (m_30 == 0 || m_defaultPrice == 0)
        return;
    CMapleSurvivalManager::GetInstance()->BuyPass(false, m_defaultPrice);
    vfunc_67();
}

void UIMapleSurvivalBuyBundleDialog::OnBuyBundle(const Scaleform::GFx::FunctionHandler::Params&)
{
    if (m_30 == 0 || m_bundlePrice == 0)
        return;
    CMapleSurvivalManager::GetInstance()->BuyPass(true, m_bundlePrice);
    vfunc_67();
}

// The pass-bundle GameEvent started or ended: refresh an open window, which closes itself when the bundle is gone.
void MushkingUI::BuyBundle_OnBundle()
{
    MS2Ptr<UIDialog> sp = CUIService::GetInstance()->FindDialog((eUIClassID)MS2_UI_MAPLESURVIVAL_BUYBUNDLE);
    if (sp.get() == 0)
        return;
    static_cast<UIMapleSurvivalBuyBundleDialog*>(sp.operator->())->Refresh();
}

// Registers both lobby windows (the lobby's class is in maplesurvivaldialog.cpp).
void MushkingUI::RegisterLobbyDialogs()
{
    CUIService::GetInstance()->RegisterDialog(MS2Ptr<UIDialog>(new UIMapleSurvivalDialog));
    CUIService::GetInstance()->RegisterDialog(MS2Ptr<UIDialog>(new UIMapleSurvivalBuyBundleDialog));
}

#endif   // MS2_HOOK_DLL
