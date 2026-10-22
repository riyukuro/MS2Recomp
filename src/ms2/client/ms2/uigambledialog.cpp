// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIGambleDialog: the gamble / loot box result dialog.
// MS2-UNIT: ?\uigambledialog.cpp
// MS2-RANGE: 0x141935200-0x141935f20 .text$mn
// MS2-PIN: ??1UIGambleDialog@@UEAA@XZ 0x141935d40
// MS2-PIN: ??_GUIGambleDialog@@UEAAPEAXI@Z 0x141935db0
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uigambledialog.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "uigambledialog.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

MS2_EMIT_CRT_MEMMOVE_S();

// ---- unit-local views of exe types ----

// The root AS object of the gamble movie.
class ASDialog : public ASDisplayObject
{
public:
    void FUN_1407cb9c0(const char* szName, int n);
    Scaleform::GFx::Value FUN_141935bc0(const char* szMethod, CString strBind, unsigned int nSlot, CStringW strName, CString strIcon, int nFlag);   // "bind"
};

// The result items of the open box: a growable array of item handles inside the talk manager's reward block.
class Unk_GbItems
{
public:
    unsigned FUN_140720ca0() const;                              // GetCount
    MS2Ptr<CItem>& FUN_140a69ee0(unsigned i);                    // checked GetAt
private:
    void* m_data; size_t m_count; size_t m_max; size_t m_grow;
};
class Unk_GbReward
{
public:
    void FUN_141b1dbd0();                                        // clear
    void* m_0; void* m_8; void* m_10;
    Unk_GbItems m_items;                                         // +0x18
};
MS2_CHECK_OFFSET(Unk_GbReward, m_items, 0x18);
class Unk_GbTalk
{
public:
    Unk_GbReward* FUN_141082d60();
    void FUN_141b20db0(int nSelect);                             // next page / select
};
Unk_GbTalk* FUN_140967100();

class Unk_GbRewardUI { public: int FUN_141b1d3d0(); };
Unk_GbRewardUI* FUN_140a7b2b0(int nId);

void FUN_141415600(const CString& strBindID);                    // release the item bound to the name
void FUN_141415450(const CString& strName, MS2Ptr<CItem> spItem, int nIndex, int nIconType, int nFlags);
CStringW FUN_1402758a0(const wchar_t* szFormat, const CStringW& a, const unsigned& b);
CStringW FUN_1418fec00(int nType, __int64 nValue, int);          // money text by pay type
int FUN_1403bafd0(int id);
void FUN_1422bce70(Scaleform::GFx::Value* pValue, const char* sz);
void FUN_1422bcd10(Scaleform::GFx::Value* pValue, unsigned int n);
void FUN_1422bcea0(Scaleform::GFx::Value* pValue, const wchar_t* psz);
void FUN_1422bccb0(Scaleform::GFx::Value* pValue, int n);

// @0x141935200
UIGambleDialog::UIGambleDialog()
{
    m_2c = 0xc;
    m_1d8 = 0;
}

// @0x1419352b0
CString UIGambleDialog::GetTypeName()
{
    return CString("GambleDialog");
}

// @0x141935300
int UIGambleDialog::vfunc_65()
{
    if (UIDialog::vfunc_65() == 0)
        return 0;
    return 1;
}

// @0x141935330
void UIGambleDialog::vfunc_67()
{
    for (size_t i = 0; i < m_binds.GetCount(); i++)
        FUN_141415600(m_binds[i]);
    m_binds.RemoveAll();
    UIDialog::vfunc_67();
}

// @0x1419353c0
// MS2-FUNCTIONAL: the exe frame is 0x10 larger (extra temporaries) with no source form found
void UIGambleDialog::vfunc_43()
{
    ASDialog* pDlg = dynamic_cast<ASDialog*>((AScript*)m_30);
    Unk_GbRewardUI* pUI;
    int n;
    if (pDlg != 0 && (pUI = FUN_140a7b2b0(0x4e40)) != 0 && (n = pUI->FUN_141b1d3d0()) != -1) {
        pDlg->vfunc_2(1, 0, n - pDlg->FUN_1422c13b0());
        return;
    }
    pDlg = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDlg != 0)
        pDlg->vfunc_2(1, 0, 0);
}

// @0x1419354d0
// MS2-FUNCTIONAL: the exe returns this (the base slot is void in the shared header)
void UIGambleDialog::vfunc_15() {}

// @0x1419354f0
void UIGambleDialog::vfunc_79(void* pPacket)
{
    UIDialog::vfunc_79(pPacket);
    int cResult;
    if (((CInPacket*)pPacket)->FUN_14070fe80() == 0x9c && (cResult = ((CInPacket*)pPacket)->vfunc_o8_1()) == 1) {
        for (size_t i = 0; i < m_binds.GetCount(); i++)
            FUN_141415600(m_binds[i]);
        m_binds.RemoveAll();
        if (FUN_141935710() == 0)
            return;
        ASDialog* pDlg = dynamic_cast<ASDialog*>((AScript*)m_30);
        if (pDlg != 0)
            pDlg->Invoke("OpenBox");
    }
}

// @0x141935660
int UIGambleDialog::vfunc_13() { return 0; }

// @0x141935670
int UIGambleDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (_stricmp(szMethod, "OnResult") == 0) {
        FUN_140967100()->FUN_141b20db0(0);
        return 1;
    }
    else if (_stricmp(szMethod, "OnHideComplete") == 0) {
        UIDialog::vfunc_67();
        return 1;
    }
    return 0;
}

// @0x141935710
// MS2-FUNCTIONAL: behaviour-equivalent; temporaries of the by-value bind arguments are not byte-identical
int UIGambleDialog::FUN_141935710()
{
    ASDialog* pDlg = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDlg == 0)
        return 0;
    Unk_GbReward* pReward = FUN_140967100()->FUN_141082d60();
    if (pReward->m_items.FUN_140720ca0() == 0)
        return 0;
    pDlg->FUN_1407cb9c0("m_resultItemCount", pReward->m_items.FUN_140720ca0());
    for (unsigned i = 0; i < pReward->m_items.FUN_140720ca0(); i++) {
        MS2Ptr<CItem> spItem = pReward->m_items.FUN_140a69ee0(i);
        if (spItem.IsNull())
            continue;
        CString strBind;
        strBind.Format("%s_%d", (const char*)GetTypeName(), i + 1);
        unsigned nCount = spItem->FUN_140526c50();
        CStringW strName = FUN_1402758a0(L"{0} X {1}", spItem->FUN_140527b10(), nCount);
        FUN_141415450(strBind, spItem, i, 0x415, 0);
        int nFlag = 1;
        int nPayType = FUN_1403bafd0(spItem->FUN_1405276c0());
        if (nPayType != 0x11) {
            strName = FUN_1418fec00(nPayType, nCount, 0);
            if (!strName.IsEmpty())
                nFlag = 0;
        }
        pDlg->FUN_141935bc0("bind", strBind, i + 1, strName, spItem->FUN_140528590(), nFlag);
        m_binds.Add(strBind);
    }
    pReward->FUN_141b1dbd0();
    return 1;
}

// @0x141935bc0
inline Scaleform::GFx::Value ASDialog::FUN_141935bc0(const char* szMethod, CString strBind, unsigned int nSlot, CStringW strName, CString strIcon, int nFlag)
{
    ASArgList args;
    args.FUN_1409b2800(5);
    FUN_1422bce70(args.FUN_1409b1f70(0), strBind);
    FUN_1422bcd10(args.FUN_1409b1f70(1), nSlot);
    FUN_1422bcea0(args.FUN_1409b1f70(2), strName);
    FUN_1422bce70(args.FUN_1409b1f70(3), strIcon);
    FUN_1422bccb0(args.FUN_1409b1f70(4), nFlag);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x141935d40 ~UIGambleDialog (implicit: the exe copy stores no vptr)

// @0x141935df0
int UIGambleDialog::vfunc_48()
{
    return 0x4e98;
}
