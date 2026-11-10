// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UITokenPocketDialog: see uitokenpocketdialog.h.
// MS2-UNIT: ?\uitokenpocketdialog.cpp
// MS2-RANGE: 0x1413518a0-0x141353540 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uitokenpocketdialog.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"
#include "uitokenpocketdialog.h"
#include "ms2/placeholder/astooltip.h"
#include "ms2/placeholder/asuicomponent.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/commonfiles/featuremanager.h"
#include "ms2/placeholder/notifysystem.h"
#include <stdlib.h>
#include "ms2/ms2format.h"

MS2_EMIT_CRT_MEMMOVE_S();

// ---- unit-local views of exe types (unrecovered helpers) ----

class ASDialog : public ASDisplayObjectContainer { public: virtual void vfunc_2(int, int, int); };   // vfunc_2: place the movie
class Unk_TpClip : public ASMovieClip { };
class Unk_TpComp : public ASUIComponent { };   // set the tooltip

class Unk_140166410* FUN_140166410();   // the CFeatureManager instance (0x140166410, the definer's signature)
bool IsStarPointEventActive();                                               // star point is enabled
class Unk_SingletonObj* FUN_140939a10();   // the NotifySystem instance (0x140939a10, the definer's signature)
CStringW FUN_141900120(int nCurrency, bool bIcon, bool bNewline);   // the amount text of a token kind
CStringW FUN_1418fe870(int nCurrency, int* pnVSpace, unsigned nItemId);   // the "<img>" source of a token kind
void SetChildHtmlText(const Scaleform::GFx::Value& root, CString strName, CStringW strText);   // set a text clip's text
void SetChildText(const Scaleform::GFx::Value& root, CString strName, CStringW strText);   // set a text field's text

// @0x1413518a0
UITokenPocketDialog::UITokenPocketDialog()
{
    SetTweenEnabled(1);
}

// @0x1413519b0
UITokenPocketDialog::~UITokenPocketDialog()
{
}

// @0x141351aa0
CString UITokenPocketDialog::GetTypeName()
{
    return "TokenPocketDialog";
}

// @0x141351af0
void UITokenPocketDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    BindDragBar("m_dragBar");
    BindCloseButton("m_closeButton");
    m_178 = 0x32;
    if (reinterpret_cast<CFeatureManager*>(FUN_140166410())->IsFeatureEnabled(0x11))
        m_180 = AddTokenSlot(4, L"$s_token_pocket_honor_tooltip");
    if (reinterpret_cast<CFeatureManager*>(FUN_140166410())->IsFeatureEnabled(0x2e))
        m_190 = AddTokenSlot(5, L"$s_token_pocket_karma_tooltip");
    m_1a0 = AddTokenSlot(6, L"$s_token_pocket_lu_tooltip");
    if (reinterpret_cast<CFeatureManager*>(FUN_140166410())->IsFeatureEnabled(0xc))
        m_1b0 = AddTokenSlot(7, L"$s_token_pocket_habi_tooltip");
    if (reinterpret_cast<CFeatureManager*>(FUN_140166410())->IsFeatureEnabled(0x76))
        m_1c0 = AddTokenSlot(0xc, L"$s_token_pocket_reverse_coin_tooltip");
    if (reinterpret_cast<CFeatureManager*>(FUN_140166410())->IsFeatureEnabled(0x91))
    {
        m_1d0 = AddTokenSlot(0xd, L"$s_token_pocket_mentor_token_tooltip");
        m_1e0 = AddTokenSlot(0xe, L"$s_token_pocket_mentee_token_tooltip");
    }
    if (IsStarPointEventActive())
        m_1f0 = AddTokenSlot(0xf, L"$s_token_pocket_star_point_tooltip");
    if (reinterpret_cast<CFeatureManager*>(FUN_140166410())->IsFeatureEnabled(0xf3))
        m_200 = AddTokenSlot(0x10, L"$s_token_pocket_meso_market_token_tooltip");
    MS2Ptr<ASMovieClip> spBgWhite = GetChild<ASMovieClip>("m_bgWhite");
    MS2Ptr<ASMovieClip> spBgBlack = GetChild<ASMovieClip>("m_bgBlack");
    int nBlackY = m_178 - 0x2c;
    int nWhiteY = nBlackY + 0x37;
    static_cast<Unk_TpClip*>(spBgWhite.get())->SetHeightInt(nWhiteY);
    static_cast<Unk_TpClip*>(spBgBlack.get())->SetHeightInt(nBlackY);
    reinterpret_cast<NotifySystem*>(FUN_140939a10())->RegisterNotify(L"NotifyChangedTokenMoney", Delegate<void(NotifyObject*)>(this, &UITokenPocketDialog::OnChangedTokenMoney));
    FUN_141352560();
}

// @0x1413522f0
void UITokenPocketDialog::vfunc_26()
{
    UIDialog::vfunc_26();
    m_180 = 0;
    m_190 = 0;
    m_1a0 = 0;
    m_1b0 = 0;
    m_1c0 = 0;
    m_1d0 = 0;
    m_1e0 = 0;
    m_1f0 = 0;
    m_200 = 0;
    reinterpret_cast<NotifySystem*>(FUN_140939a10())->UnregisterNotify(L"NotifyChangedTokenMoney", Delegate<void(NotifyObject*)>(this, &UITokenPocketDialog::OnChangedTokenMoney));
}

// @0x1413524b0
void UITokenPocketDialog::vfunc_43()
{
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDialog != 0)
        pDialog->vfunc_2(5, 0x118, 0x28);
}

// @0x141352530
void UITokenPocketDialog::OnChangedTokenMoney(NotifyObject* pNotify)
{
    FUN_141352560();
}

// @0x141352560
void UITokenPocketDialog::FUN_141352560()
{
    if (m_30.IsNull() != 0)
        return;
    const CString& strField = "textField";
    if (m_180.get() != 0)
        SetChildText(m_180->FUN_1422bb890(), strField, FUN_141900120(4, 0, 0));
    if (m_190.get() != 0)
        SetChildText(m_190->FUN_1422bb890(), strField, FUN_141900120(5, 0, 0));
    if (m_1a0.get() != 0)
        SetChildText(m_1a0->FUN_1422bb890(), strField, FUN_141900120(6, 0, 0));
    if (m_1b0.get() != 0)
        SetChildText(m_1b0->FUN_1422bb890(), strField, FUN_141900120(7, 0, 0));
    if (m_1c0.get() != 0)
        SetChildText(m_1c0->FUN_1422bb890(), strField, FUN_141900120(0xc, 0, 0));
    if (m_1d0.get() != 0)
        SetChildText(m_1d0->FUN_1422bb890(), strField, FUN_141900120(0xd, 0, 0));
    if (m_1e0.get() != 0)
        SetChildText(m_1e0->FUN_1422bb890(), strField, FUN_141900120(0xe, 0, 0));
    if (m_1f0.get() != 0)
        SetChildText(m_1f0->FUN_1422bb890(), strField, FUN_141900120(0xf, 0, 0));
    if (m_200.get() != 0)
        SetChildText(m_200->FUN_1422bb890(), strField, FUN_141900120(0x10, 0, 0));
}

// @0x141352cf0
MS2Ptr<ASUIComponent> UITokenPocketDialog::AddTokenSlot(int nTokenKind, const CStringW& strTooltip)
{
    MS2Ptr<ASUIComponent> spSlot(new ASUIComponent(CString("UITokenPocketDialog_slot"), 2));
    int nVSpace = -4;
    const CStringW& strSrc = FUN_1418fe870(nTokenKind, &nVSpace, 0);
    SetChildHtmlText(spSlot->FUN_1422bb890(), "icon", StringFormat<CStringW, int>(L"<img src='{0}' vspace='{1}'/>", strSrc, nVSpace));
    spSlot.get()->SetPositionInt(0xe, m_178);
    m_178 += 0x17;
    m_90->AddChild(spSlot->FUN_1422bb890());
    ASTooltip tooltip(2);
    tooltip.ApplyTextTooltip(strTooltip);
    tooltip.SetTooltipAlign(5);
    static_cast<Unk_TpComp*>(spSlot.get())->SetTooltipData(tooltip.GetValue());
    return spSlot;
}
