// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Party search register dialog. See uipartysearchregisterdialog.h.
// MS2-UNIT: client\ms2\uipartysearchregisterdialog.cpp
// MS2-RANGE: 0x141320660-0x141322c00 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uipartysearchregisterdialog.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "uipartysearchregisterdialog.h"
#include "blockmanager.h"
#include "partymanager.h"
#include "uimessagebox.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/gfxexception.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local declarations (names describe uses, not original class names) ----

// The child controls bound by name. All four share the display-object base (FUN_1422c1fe0 = set enabled).
class Unk_PsDisplay : public ASDisplayObject
{
public:
    void FUN_1422c1fe0(unsigned int nEnabled);
};
class Unk_PsCombo : public Unk_PsDisplay            // m_maxUserCountCombo
{
public:
    void FUN_1422dfc10();                           // remove all rows
    void FUN_1422df5f0(unsigned int nRows);         // visible rows
    void FUN_1422dfce0(const CStringW& strRow);     // add a row
    void FUN_1422df690(int nRow);                   // select a row
    int FUN_1422df6c0();                            // selected row
};
class Unk_PsInput : public Unk_PsDisplay            // m_inputTitle
{
public:
    void FUN_1422e0ab0(const CStringW& strText);
    CStringW FUN_1422e0b00();
};
class Unk_PsCheck : public Unk_PsDisplay            // m_checkAllowAutoJoin
{
public:
    void FUN_1422ce090(unsigned int nChecked);
    unsigned char FUN_1422ce0e0();
};
class Unk_PsButton : public Unk_PsDisplay           // m_btnRegister / m_btnRemove
{
public:
    void FUN_1422ce240(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& callback, int nFlags);
};

// The party size choices (ints) held by the global config at +0xe770.
class Unk_PsIntList
{
public:
    size_t FUN_1401910d0() const;                   // count
    int* FUN_1404f0a10(size_t nIndex);              // element
};
class Unk_PsConfig
{
public:
    unsigned char m_pad_0[0xe770];
    Unk_PsIntList m_e770;
};
Unk_PsConfig* FUN_1401d3200();

CStringW FUN_14028de60(int nId);                    // string table
CStringW FUN_140719630(int n);                      // "%d"
CStringW FUN_1408116a0(int nId, const int& nArg);
CStringW FUN_140275590(const wchar_t* szFormat, const CStringW& strArg, const int& nArg);
bool FUN_140164830(const CStringW& a, const CStringW& b);
bool FUN_1403b3c40(const CStringW& str, const wchar_t* sz);
void FUN_140d73aa0(CStringW text, int nType, void* p, CStringW tag);
void FUN_140d73bc0(int nStrId, int nType, void* p, CStringW tag);
void FUN_14151f200();
void FUN_140a30ad0(const BlockPtr& rec, int action, unsigned long long cb);
CBlockManager* FUN_140a6a830();
CPartyManager* FUN_1409670d0();
bool FUN_140695080(CMatchPartyRecruit* pRecruit);   // recruitId == 0

// Name filter (bad words) of the title.
class Unk_PsFilter : public CPtred
{
public:
    int FUN_1402262e0(const CStringW& strText, CStringW& strBad);    // nonzero: the text is rejected, strBad = the reason
};
class Unk_PsFilterMgr
{
public:
    MS2Ptr<Unk_PsFilter> FUN_140229a50();
};
Unk_PsFilterMgr* FUN_14025e7d0();

// Keyboard state.
class Unk_PsKeys
{
public:
    bool FUN_14116d9c0(int nKey, int a, int b);
};
Unk_PsKeys* FUN_14025e7c0();

// Dialog manager: the top dialog of a layer.
class Unk_PsDialogMgr
{
public:
    UISwfEntity* FUN_1422d4980(int nLayer);
};
Unk_PsDialogMgr* FUN_140b632f0();

// UI manager lookup by id (reference to a UI object, 0x10 bytes).
class Unk_PsUIRef
{
public:
    ~Unk_PsUIRef();                                 // 0x1403e5630
    UIObject* FUN_1403e8a70() const;                // the object, 0 if none
private:
    void* m_unknown;
    UIObject* m_object;
};
MS2_CHECK_SIZE(Unk_PsUIRef, 0x10);
class Unk_PsUIManager
{
public:
    Unk_PsUIRef FUN_141adcea0(int nUiId);
};
Unk_PsUIManager* FUN_1403ed2b0();
UIObject* FUN_1403ed9e0(Unk_PsUIRef& ref);

// The party search list dialog (UI id 0x4eda); only its RTTI is needed here.
class UIPartySearchDialog : public UIObject
{
};

// The request sent to the server (Unk_PartyRecruitRequest) with its out-of-line constructor/destructor.
struct Unk_PsRequest
{
    void* m_pszTitle;                   // CStringW
    unsigned int m_kind;
    int m_fieldId;
};
MS2_CHECK_SIZE(Unk_PsRequest, 0x10);
Unk_PsRequest* FUN_140694210(Unk_PsRequest* pRequest);
void FUN_140694250(Unk_PsRequest* pRequest);

// @0x1413226d0
UIPartySearchDialog* FUN_1413226d0(int nUiId)
{
    if (FUN_1403ed2b0())
    {
        Unk_PsUIRef ref = FUN_1403ed2b0()->FUN_141adcea0(nUiId);
        if (ref.FUN_1403e8a70())
            return dynamic_cast<UIPartySearchDialog*>(FUN_1403ed9e0(ref));
    }
    return 0;
}

// ---- Unk_PsRegState ----

// @0x141322880
Unk_PsRegState::Unk_PsRegState()
{
    m_flag = 1;
}

// @0x1413228d0
Unk_PsRegState::~Unk_PsRegState()
{
}

// @0x141322970
void Unk_PsRegState::FUN_141322970()
{
    m_text.Empty();
    m_flag = 1;
}

// ---- UIPartySearchRegisterDialog ----

// @0x141320660
UIPartySearchRegisterDialog::UIPartySearchRegisterDialog()
    : m_220(L"")
{
    FUN_141924170(1);
    FUN_1422dc3b0(1);
    FUN_141321d60();
}

// @0x1413207b0
UIPartySearchRegisterDialog::~UIPartySearchRegisterDialog()
{
}

// @0x1413208b0
CString UIPartySearchRegisterDialog::GetTypeName()
{
    return "PartySearchRegisterDialog";
}

// @0x141320900
void UIPartySearchRegisterDialog::vfunc_67()
{
    UIModalDialog::vfunc_67();
    m_180.FUN_141322970();
}

// @0x141320940
int UIPartySearchRegisterDialog::vfunc_73()
{
    {
        BlockPtr blocked = FUN_140a6a830()->FindBlockedAction(0xe);
        if (blocked.get() != 0)
        {
            FUN_140a30ad0(blocked, 0xe, 0);
            return 0;
        }
    }
    return UIDialog::vfunc_73();
}

// @0x1413209d0
void UIPartySearchRegisterDialog::OnLoadInit()
{
    UIObject::OnLoadInit();
    vfunc_47(0);
}

// @0x141320a10
// MS2-FUNCTIONAL: OnLoadComplete: stack frame/temp ordering differs from the exe (large GFx bind sequence)
void UIPartySearchRegisterDialog::OnLoadComplete()
{
    UIModalDialog::OnLoadComplete();
    FUN_141925ec0("m_closeButton");
    if (!(m_30 == 0))
    {
        if (FUN_1413226d0(0x4eda) == 0)
        {
            vfunc_67();
        }
        else
        {
            do { m_30->FUN_140bbe7c0("m_maxUserCountCombo", m_1b0); if (m_1b0 == 0) throw new GfxExceptionSwfLoad(StringFormat("GfxError:{0} {1}({2}) function:{3}", "SwfLoadError", MS2_THIS_FILE, MS2_LINE(72), __FUNCTION__)); } while (0);
            do { m_30->FUN_140bbe940("m_inputTitle", m_1c0); if (m_1c0 == 0) throw new GfxExceptionSwfLoad(StringFormat("GfxError:{0} {1}({2}) function:{3}", "SwfLoadError", MS2_THIS_FILE, MS2_LINE(73), __FUNCTION__)); } while (0);
            do { m_30->FUN_140c12010("m_checkAllowAutoJoin", m_1d0); if (m_1d0 == 0) throw new GfxExceptionSwfLoad(StringFormat("GfxError:{0} {1}({2}) function:{3}", "SwfLoadError", MS2_THIS_FILE, MS2_LINE(74), __FUNCTION__)); } while (0);
            do { m_30->FUN_140bbe640("m_btnRegister", m_1e0); if (m_1e0 == 0) throw new GfxExceptionSwfLoad(StringFormat("GfxError:{0} {1}({2}) function:{3}", "SwfLoadError", MS2_THIS_FILE, MS2_LINE(75), __FUNCTION__)); } while (0);
            do { m_30->FUN_140bbe640("m_btnRemove", m_1f0); if (m_1f0 == 0) throw new GfxExceptionSwfLoad(StringFormat("GfxError:{0} {1}({2}) function:{3}", "SwfLoadError", MS2_THIS_FILE, MS2_LINE(76), __FUNCTION__)); } while (0);

            m_1b0->FUN_1422dfc10();
            unsigned long long nCount = FUN_1401d3200()->m_e770.FUN_1401910d0();
            m_1b0->FUN_1422df5f0((unsigned int)nCount);
            m_1e0->FUN_1422ce240(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &UIPartySearchRegisterDialog::FUN_141322400), 0);
            m_1f0->FUN_1422ce240(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &UIPartySearchRegisterDialog::FUN_141322520), 0);
            for (unsigned int i = 0; i < (unsigned int)FUN_1401d3200()->m_e770.FUN_1401910d0(); ++i)
            {
                m_1b0->FUN_1422dfce0(FUN_140719630(*FUN_1401d3200()->m_e770.FUN_1404f0a10(i)));
            }
            CMatchPartyRecruit* pRecruit = &FUN_1409670d0()->FUN_141631ce0();
            if (!FUN_140695080(pRecruit))
            {
                m_1c0->FUN_1422c1fe0(0);
                m_1d0->FUN_1422c1fe0(0);
                m_1b0->FUN_1422c1fe0(0);
                m_1c0->FUN_1422e0ab0(pRecruit->title);
                m_1d0->FUN_1422ce090(pRecruit->minimumLevel);
                m_1b0->FUN_1422df690(FUN_141322380(pRecruit->members));
                m_1e0->vfunc_4(0);
                m_1f0->vfunc_4(1);
            }
            else
            {
                m_1c0->FUN_1422e0ab0(m_190.m_text);
                m_1d0->FUN_1422ce090((unsigned int)m_190.m_flag);
                m_1b0->FUN_1422df690((int)(FUN_1401d3200()->m_e770.FUN_1401910d0() - 1));
                m_1e0->vfunc_4(1);
                m_1f0->vfunc_4(0);
            }
        }
    }
}

// @0x1413218d0
void UIPartySearchRegisterDialog::vfunc_26()
{
    UIDialog::vfunc_26();
    m_1b0 = 0;
    m_1c0 = 0;
    m_1d0 = 0;
    m_1e0 = 0;
    m_1f0 = 0;
}

// @0x141321960
int UIPartySearchRegisterDialog::vfunc_13()
{
    if (UIDialog::vfunc_13())
        return 1;
    if (vfunc_55() == 0 && (m_30.get() ? true : false))
    {
        if (FUN_140b632f0()->FUN_1422d4980(m_e0) == this)
        {
            CString strKey("");
            if (FUN_14025e7c0()->FUN_14116d9c0(0x1c, 0, 0))
                strKey = "onEnterKey";
            else if (FUN_14025e7c0()->FUN_14116d9c0(0xf, 0, 0))
                strKey = "onTabKey";
            if (!strKey.IsEmpty())
            {
                m_30->Invoke("onProcessKey", strKey);
                return 1;
            }
        }
    }
    return 0;
}

// @0x141321b30
int UIPartySearchRegisterDialog::OnMessage(UISwfEntity* pSender, UIMsg* pMsg)
{
    if (UIDialog::OnMessage(pSender, pMsg))
        return 1;
    if (pMsg->FUN_1422e4520() == 0 && dynamic_cast<UIMessageBox*>(pSender))
    {
        int nAnswer = pMsg->FUN_1422b8a10();
        CStringW strTag = pMsg->FUN_1422b8f40();
        FUN_14151f200();
        if (nAnswer == 0)
        {
            if (FUN_1403b3c40(strTag, L"remove"))
            {
                FUN_1409670d0()->SendMatchPartyMode1();
                vfunc_67();
            }
            else if (FUN_1403b3c40(strTag, L"modify") && FUN_1413220d0(&m_180, 1) != 0)
            {
                vfunc_67();
            }
        }
        return 1;
    }
    return 0;
}

// @0x141321cc0
void UIPartySearchRegisterDialog::FUN_141321cc0(CStringW* pText, unsigned char nAutoJoin, Unk_PsRegState* pState)
{
    if (FUN_140164830(m_220, *pText))
        pState->m_text = *pText;
    pState->m_flag = nAutoJoin;
}

// @0x141321d30
void UIPartySearchRegisterDialog::FUN_141321d30()
{
    m_190.m_text.Empty();
}

// @0x141321d60
void UIPartySearchRegisterDialog::FUN_141321d60()
{
    m_200.RemoveAll();
    m_200.Add(FUN_14028de60(0xc48));
    m_200.Add(FUN_14028de60(0xc49));
    m_200.Add(FUN_14028de60(0xc4a));
    m_200.Add(FUN_14028de60(0xc4b));
    m_200.Add(FUN_14028de60(0xc4c));
}

// @0x141321f10
CStringW UIPartySearchRegisterDialog::FUN_141321f10(CStringW strArg, int nArg)
{
    if (m_200.GetCount() == 0)
        return CStringW(L"");
    return FUN_140275590((const wchar_t*)m_200[(unsigned long long)(long long)rand() % m_200.GetCount()], strArg, nArg);
}

// @0x141322020
int UIPartySearchRegisterDialog::FUN_141322020()
{
    if (m_1b0 == 0)
        return 10;
    int nRow = m_1b0->FUN_1422df6c0();
    if (nRow < 0 || nRow >= (int)FUN_1401d3200()->m_e770.FUN_1401910d0())
        return 10;
    return *FUN_1401d3200()->m_e770.FUN_1404f0a10(nRow);
}

// @0x1413220d0
// MS2-FUNCTIONAL: FUN_1413220d0: one extra unwind state and +8 frame offsets (Unk_PsRequest temp placement)
int UIPartySearchRegisterDialog::FUN_1413220d0(Unk_PsRegState* pState, int bSilent)
{
    if (pState->m_text.GetLength() < 2)
    {
        FUN_140d73aa0(FUN_1408116a0(0xb53, 2), 0, 0, CStringW(L""));
        return 0;
    }
    if (Unk_PsFilter* pFilter = FUN_14025e7d0()->FUN_140229a50().get())
    {
        CStringW strBad;
        if (pFilter->FUN_1402262e0(pState->m_text, strBad) != 0)
        {
            FUN_140d73aa0(CStringW(strBad), 0, 0, CStringW(L""));
            return 0;
        }
    }
    unsigned char nAutoJoin = pState->m_flag;
    CStringW* pTitle = &pState->m_text;
    Unk_PsRequest request;
    FUN_140694210(&request);
    *(CStringW*)&request.m_pszTitle = *pTitle;
    request.m_kind = nAutoJoin;
    request.m_fieldId = FUN_141322020();
    if (bSilent == 0)
        FUN_1409670d0()->SendMatchPartyMode0(*(const Unk_PartyRecruitRequest*)&request);
    FUN_141321cc0(pTitle, nAutoJoin, &m_190);
    FUN_140694250(&request);
    return 1;
}

// @0x141322380
int UIPartySearchRegisterDialog::FUN_141322380(int nValue)
{
    for (int i = 0; i < (int)FUN_1401d3200()->m_e770.FUN_1401910d0(); ++i)
    {
        if (*FUN_1401d3200()->m_e770.FUN_1404f0a10(i) == nValue)
            return i;
    }
    return -1;
}

// @0x141322400
void UIPartySearchRegisterDialog::FUN_141322400(const Scaleform::GFx::FunctionHandler::Params&)
{
    if (m_1c0 == 0 || m_1d0 == 0)
        return;
    m_180.m_text = m_1c0->FUN_1422e0b00();
    m_180.m_text.Trim();
    m_180.m_flag = m_1d0->FUN_1422ce0e0();
    if (FUN_1413220d0(&m_180, 0) != 0)
        vfunc_67();
}

// @0x141322520
void UIPartySearchRegisterDialog::FUN_141322520(const Scaleform::GFx::FunctionHandler::Params&)
{
    FUN_140d73bc0(0xb56, 1, static_cast<IMessageListener*>(this), CStringW(L"remove"));
}
