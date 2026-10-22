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
#include <stdlib.h>

MS2_EMIT_CRT_MEMMOVE_S();

// ---- unit-local views of exe types (unrecovered helpers) ----

class ASDialog : public ASDisplayObjectContainer { public: virtual void vfunc_2(int, int, int); };   // vfunc_2: place the movie
class Unk_TpClip : public ASMovieClip { public: void FUN_1422c0ec0(int nY); };
class Unk_TpComp : public ASUIComponent { public: void FUN_1422c7cd0(const Scaleform::GFx::Value& v); };   // set the tooltip
class Unk_TpFeatures { public: bool FUN_14036d570(int nFeature); };
class Unk_TpNotices
{
public:
    void FUN_140da4e40(CStringW strName, Delegate<void(NotifyObject*)> handler);
    void FUN_140da4eb0(CStringW strName, Delegate<void(NotifyObject*)> handler);
};

Unk_TpFeatures* FUN_140166410();
bool FUN_1406a5930();                                               // star point is enabled
Unk_TpNotices* FUN_140939a10();
CStringW FUN_141900120(int nCurrency, bool bIcon, bool bNewline);   // the amount text of a token kind
CStringW FUN_1418fe870(int nCurrency, int* pnVSpace, unsigned nItemId);   // the "<img>" source of a token kind
CStringW FUN_140275590(const wchar_t* szFormat, const CStringW& a1, const int& a2);
void FUN_140cff1b0(const Scaleform::GFx::Value& root, CString strName, CStringW strText);   // set a text clip's text
void FUN_140cfee80(const Scaleform::GFx::Value& root, CString strName, CStringW strText);   // set a text field's text

// @0x1413518a0
UITokenPocketDialog::UITokenPocketDialog()
{
    FUN_141924170(1);
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
// MS2-FUNCTIONAL: nine inline MS2Ptr temporaries; temp / frame layout differs
void UITokenPocketDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    FUN_141925fa0("m_dragBar");
    FUN_141925ec0("m_closeButton");
    m_178 = 0x32;
    if (FUN_140166410()->FUN_14036d570(0x11))
        m_180 = FUN_141352cf0(4, L"$s_token_pocket_honor_tooltip");
    if (FUN_140166410()->FUN_14036d570(0x2e))
        m_190 = FUN_141352cf0(5, L"$s_token_pocket_karma_tooltip");
    m_1a0 = FUN_141352cf0(6, L"$s_token_pocket_lu_tooltip");
    if (FUN_140166410()->FUN_14036d570(0xc))
        m_1b0 = FUN_141352cf0(7, L"$s_token_pocket_habi_tooltip");
    if (FUN_140166410()->FUN_14036d570(0x76))
        m_1c0 = FUN_141352cf0(0xc, L"$s_token_pocket_reverse_coin_tooltip");
    if (FUN_140166410()->FUN_14036d570(0x91))
    {
        m_1d0 = FUN_141352cf0(0xd, L"$s_token_pocket_mentor_token_tooltip");
        m_1e0 = FUN_141352cf0(0xe, L"$s_token_pocket_mentee_token_tooltip");
    }
    if (FUN_1406a5930())
        m_1f0 = FUN_141352cf0(0xf, L"$s_token_pocket_star_point_tooltip");
    if (FUN_140166410()->FUN_14036d570(0xf3))
        m_200 = FUN_141352cf0(0x10, L"$s_token_pocket_meso_market_token_tooltip");
    MS2Ptr<ASMovieClip> spBgWhite = FUN_140ba7930("m_bgWhite");
    MS2Ptr<ASMovieClip> spBgBlack = FUN_140ba7930("m_bgBlack");
    int nY = m_178;
    static_cast<Unk_TpClip*>(spBgWhite.get())->FUN_1422c0ec0(nY + 0xb);
    static_cast<Unk_TpClip*>(spBgBlack.get())->FUN_1422c0ec0(nY - 0x2c);
    FUN_140939a10()->FUN_140da4e40(L"NotifyChangedTokenMoney", Delegate<void(NotifyObject*)>(this, &UITokenPocketDialog::FUN_141352530));
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
    FUN_140939a10()->FUN_140da4eb0(L"NotifyChangedTokenMoney", Delegate<void(NotifyObject*)>(this, &UITokenPocketDialog::FUN_141352530));
}

// @0x1413524b0
void UITokenPocketDialog::vfunc_43()
{
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDialog != 0)
        pDialog->vfunc_2(5, 0x118, 0x28);
}

// @0x141352530
void UITokenPocketDialog::FUN_141352530(NotifyObject* pNotify)
{
    FUN_141352560();
}

// @0x141352560
// MS2-FUNCTIONAL: nine unrolled refresh blocks; temp / frame layout differs
void UITokenPocketDialog::FUN_141352560()
{
    if (m_30.IsNull() != 0)
        return;
    CString strField = "textField";
    if (m_180.get() != 0)
        FUN_140cfee80(m_180->FUN_1422bb890(), strField, FUN_141900120(4, 0, 0));
    if (m_190.get() != 0)
        FUN_140cfee80(m_190->FUN_1422bb890(), strField, FUN_141900120(5, 0, 0));
    if (m_1a0.get() != 0)
        FUN_140cfee80(m_1a0->FUN_1422bb890(), strField, FUN_141900120(6, 0, 0));
    if (m_1b0.get() != 0)
        FUN_140cfee80(m_1b0->FUN_1422bb890(), strField, FUN_141900120(7, 0, 0));
    if (m_1c0.get() != 0)
        FUN_140cfee80(m_1c0->FUN_1422bb890(), strField, FUN_141900120(0xc, 0, 0));
    if (m_1d0.get() != 0)
        FUN_140cfee80(m_1d0->FUN_1422bb890(), strField, FUN_141900120(0xd, 0, 0));
    if (m_1e0.get() != 0)
        FUN_140cfee80(m_1e0->FUN_1422bb890(), strField, FUN_141900120(0xe, 0, 0));
    if (m_1f0.get() != 0)
        FUN_140cfee80(m_1f0->FUN_1422bb890(), strField, FUN_141900120(0xf, 0, 0));
    if (m_200.get() != 0)
        FUN_140cfee80(m_200->FUN_1422bb890(), strField, FUN_141900120(0x10, 0, 0));
}

// @0x141352cf0
// MS2-FUNCTIONAL: MS2Ptr return temp / frame layout differs
MS2Ptr<ASUIComponent> UITokenPocketDialog::FUN_141352cf0(int nTokenKind, CStringW strTooltip)
{
    MS2Ptr<ASUIComponent> spSlot(new ASUIComponent(CString("UITokenPocketDialog_slot"), 2));
    int nVSpace = -4;
    CStringW strImg = FUN_140275590(L"<img src='{0}' vspace='{1}'/>", FUN_1418fe870(nTokenKind, &nVSpace, 0), nVSpace);
    FUN_140cff1b0(spSlot->FUN_1422bb890(), "icon", strImg);
    spSlot.get()->FUN_1422bffe0(0xe, m_178);
    m_178 += 0x17;
    m_90->FUN_1422c6900(spSlot->FUN_1422bb890());
    ASTooltip tooltip(2);
    tooltip.FUN_1409e26b0(strTooltip);
    tooltip.FUN_1409c6dc0(5);
    static_cast<Unk_TpComp*>(spSlot.get())->FUN_1422c7cd0(tooltip.FUN_1422bb870());
    return spSlot;
}
