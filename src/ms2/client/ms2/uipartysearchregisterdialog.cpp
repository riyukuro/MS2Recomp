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
#include "ms2/placeholder/asdropdownmenu.h"   // C3: ASDropdownMenu::SetSelectedIndex
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/gfxexception.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/client/ms2/partymanager.h"
#include "ms2/client/ms2/uiservice.h"
#include "ms2/placeholder/cinputkeyhandler.h"  // C3: CInputKeyHandler::FUN_14116d9c0
#include "ms2/placeholder/astextinput.h"   // C3: ASTextInput::FUN_1422e0b00
#include "ms2/placeholder/asbutton.h"  // C3: ASButton::FUN_1422ce090
#include "ms2/placeholder/blockformat.h"
#include "ms2/placeholder/uiswfentitymanager.h"
#include "ms2/commonfiles/commonstringtable.h"

// ---- unit-local declarations (names describe uses, not original class names) ----

class Unk_PsConfig
{
public:
    unsigned char m_pad_0[0xe770];
    std::vector<int> m_e770;
};
namespace Client { class Constants; } template<class T> class TSingleton; template<> class TSingleton<Client::Constants> { public: static Client::Constants* GetInstance(); }; class Unk_SingletonObj1;   // C3: was FUN_1401d3200 (= TSingleton<Client::Constants>::GetInstance)

CStringW GetStringCommon(int nId);                    // string table
CStringW FUN_140719630(int n);                      // "%d"
void ShowMessageBox(CStringW text, int nType, void* p, CStringW tag);
void FUN_140d73bc0(int nStrId, int nType, void* p, CStringW tag);
void FUN_14151f200();
void FUN_140a30ad0(const BlockPtr& rec, int action, unsigned long long cb);
class Unk_InventoryStateManager* GetBlockManager();   // C3: was GetBlockManager
int FUN_140695080(class CMatchPartyRecruit const*);   // C3: was FUN_140695080


// Keyboard state.
class Unk_PsKeys : public CInputKeyHandler {};
void* FUN_14025e7c0();   // C3: was FUN_14025e7c0

// The party search list dialog (UI id 0x4eda); only its RTTI is needed here.
class UIPartySearchDialog : public UIObject
{
};

// The request sent to the server (Unk_PartyRecruitRequest) with its out-of-line constructor/destructor (same
// layout as manufacture.cpp's Unk_140694210).
struct Unk_140694210
{
    Unk_140694210();                    // 0x140694210
    ~Unk_140694210();                   // 0x140694250
    CStringW m_00;                      // title
    unsigned m_08;                      // kind
    int m_0c;                           // field id
};
MS2_CHECK_SIZE(Unk_140694210, 0x10);

// @0x1413226d0
UIPartySearchDialog* GetPartySearchDialog(int nUiId)
{
    if (TSingleton<CUIService>::GetInstance())
    {
        MS2Ptr<UIObject> ref = TSingleton<CUIService>::GetInstance()->FindObject((eUIClassID)nUiId);
        if (ref.get())
            return dynamic_cast<UIPartySearchDialog*>(ref.operator UIObject*());
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
void Unk_PsRegState::Reset()
{
    m_text.Empty();
    m_flag = 1;
}

// ---- UIPartySearchRegisterDialog ----

// @0x141320660
UIPartySearchRegisterDialog::UIPartySearchRegisterDialog()
    : m_220(L"")
{
    SetTweenEnabled(1);
    FUN_1422dc3b0(1);
    BuildRandomTitleList();
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
    m_180.Reset();
}

// @0x141320940
int UIPartySearchRegisterDialog::vfunc_73()
{
    {
        BlockPtr blocked = ((class CBlockManager*)GetBlockManager())->FindBlockedAction(0xe);
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
void UIPartySearchRegisterDialog::OnLoadComplete()
{
    UIModalDialog::OnLoadComplete();
    BindCloseButton("m_closeButton");
    if (m_30 == 0)
        return;
    UIPartySearchDialog* pSearch = GetPartySearchDialog(0x4eda);
    if (pSearch == 0)
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

        m_1b0->ClearItems();
        m_1b0->SetMenuRowCount((unsigned int)((class Unk_PsConfig*)reinterpret_cast<Unk_SingletonObj1*>(TSingleton<Client::Constants>::GetInstance()))->m_e770.size());
        m_1e0->FUN_1422ce240(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &UIPartySearchRegisterDialog::OnRegisterClicked), 0);
        m_1f0->FUN_1422ce240(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &UIPartySearchRegisterDialog::OnRemoveClicked), 0);
        for (unsigned int i = 0; i < (unsigned int)((class Unk_PsConfig*)reinterpret_cast<Unk_SingletonObj1*>(TSingleton<Client::Constants>::GetInstance()))->m_e770.size(); ++i)
        {
            m_1b0->AddItemLabel(FUN_140719630(((class Unk_PsConfig*)reinterpret_cast<Unk_SingletonObj1*>(TSingleton<Client::Constants>::GetInstance()))->m_e770[i]));
        }
        CMatchPartyRecruit* pRecruit = &TSingleton<CPartyManager>::GetInstance()->GetRecruitment();
        if (FUN_140695080((class CMatchPartyRecruit const*)(pRecruit)))
        {
            m_1c0->SetTextW(m_190.m_text);
            m_1d0->SetSelected((unsigned int)m_190.m_flag);
            m_1b0->SetSelectedIndex((int)(((class Unk_PsConfig*)reinterpret_cast<Unk_SingletonObj1*>(TSingleton<Client::Constants>::GetInstance()))->m_e770.size() - 1));
            m_1e0->vfunc_4(1);
            m_1f0->vfunc_4(0);
        }
        else
        {
            m_1c0->SetEnabled(0);
            m_1d0->SetEnabled(0);
            m_1b0->SetEnabled(0);
            m_1c0->SetTextW(pRecruit->title);
            m_1d0->SetSelected(pRecruit->minimumLevel);
            m_1b0->SetSelectedIndex(FindMaxUserCountIndex(pRecruit->members));
            m_1e0->vfunc_4(0);
            m_1f0->vfunc_4(1);
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
        if (GetUISwfEntityManager()->GetTopEntity(m_e0) == this)
        {
            CString strKey("");
            if (((class Unk_PsKeys*)FUN_14025e7c0())->WasKeyPressed(0x1c, 0, 0))
                strKey = "onEnterKey";
            else if (((class Unk_PsKeys*)FUN_14025e7c0())->WasKeyPressed(0xf, 0, 0))
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
        int nAnswer = pMsg->PopInt();
        CStringW strTag = pMsg->FUN_1422b8f40();
        FUN_14151f200();
        if (nAnswer == 0)
        {
            if (operator==(strTag, L"remove"))
            {
                TSingleton<CPartyManager>::GetInstance()->SendMatchPartyMode1();
                vfunc_67();
            }
            else if (operator==(strTag, L"modify") && ValidateAndSendRegistration(&m_180, 1) != 0)
            {
                vfunc_67();
            }
        }
        return 1;
    }
    return 0;
}

// @0x141321cc0
void UIPartySearchRegisterDialog::ApplyTitleAndAutoJoin(CStringW* pText, unsigned char nAutoJoin, Unk_PsRegState* pState)
{
    if (m_220 != *pText)
        pState->m_text = *pText;
    pState->m_flag = nAutoJoin;
}

// @0x141321d30
void UIPartySearchRegisterDialog::ClearRegisteredTitle()
{
    m_190.m_text.Empty();
}

// @0x141321d60
void UIPartySearchRegisterDialog::BuildRandomTitleList()
{
    m_200.RemoveAll();
    m_200.Add(GetStringCommon(0xc48));
    m_200.Add(GetStringCommon(0xc49));
    m_200.Add(GetStringCommon(0xc4a));
    m_200.Add(GetStringCommon(0xc4b));
    m_200.Add(GetStringCommon(0xc4c));
}

// @0x141321f10
CStringW UIPartySearchRegisterDialog::GetRandomTitle(CStringW strArg, int nArg)
{
    if (m_200.GetCount() == 0)
        return CStringW(L"");
    return StringFormat<CStringW, int>((const wchar_t*)m_200[(unsigned long long)(long long)rand() % m_200.GetCount()], strArg, nArg);
}

// @0x141322020
int UIPartySearchRegisterDialog::GetSelectedMaxUserCount()
{
    if (m_1b0 == 0)
        return 10;
    int nRow = m_1b0->GetSelectedIndex();
    if (nRow < 0 || nRow >= (int)((class Unk_PsConfig*)reinterpret_cast<Unk_SingletonObj1*>(TSingleton<Client::Constants>::GetInstance()))->m_e770.size())
        return 10;
    return ((class Unk_PsConfig*)reinterpret_cast<Unk_SingletonObj1*>(TSingleton<Client::Constants>::GetInstance()))->m_e770[nRow];
}

// @0x1413220d0
int UIPartySearchRegisterDialog::ValidateAndSendRegistration(Unk_PsRegState* pState, int bSilent)
{
    if (pState->m_text.GetLength() < 2)
    {
        ShowMessageBox(BlockFormat<int>(0xb53, 2), 0, 0, CStringW(L""));
        return 0;
    }
    if (CBanTextChecker* pFilter = TSingleton<CommonString>::GetInstance()->GetChecker().get())
    {
        CStringW strBad;
        if (pFilter->FUN_1402262e0(pState->m_text, strBad) != 0)
        {
            ShowMessageBox(CStringW(strBad), 0, 0, CStringW(L""));
            return 0;
        }
    }
    unsigned char nAutoJoin = pState->m_flag;
    CStringW* pTitle = &pState->m_text;
    Unk_140694210 request;
    request.m_00 = *pTitle;
    request.m_08 = nAutoJoin;
    request.m_0c = GetSelectedMaxUserCount();
    if (bSilent == 0)
        TSingleton<CPartyManager>::GetInstance()->SendMatchPartyMode0(*(const Unk_PartyRecruitRequest*)&request);
    ApplyTitleAndAutoJoin(pTitle, nAutoJoin, &m_190);
    return 1;
}

// @0x141322380
int UIPartySearchRegisterDialog::FindMaxUserCountIndex(int nValue)
{
    for (int i = 0; i < (int)((class Unk_PsConfig*)reinterpret_cast<Unk_SingletonObj1*>(TSingleton<Client::Constants>::GetInstance()))->m_e770.size(); ++i)
    {
        if (((class Unk_PsConfig*)reinterpret_cast<Unk_SingletonObj1*>(TSingleton<Client::Constants>::GetInstance()))->m_e770[i] == nValue)
            return i;
    }
    return -1;
}

// @0x141322400
void UIPartySearchRegisterDialog::OnRegisterClicked(const Scaleform::GFx::FunctionHandler::Params&)
{
    if (m_1c0 == 0 || m_1d0 == 0)
        return;
    m_180.m_text = m_1c0->GetText();
    m_180.m_text.Trim();
    m_180.m_flag = m_1d0->IsSelected();
    if (ValidateAndSendRegistration(&m_180, 0) != 0)
        vfunc_67();
}

// @0x141322520
void UIPartySearchRegisterDialog::OnRemoveClicked(const Scaleform::GFx::FunctionHandler::Params&)
{
    FUN_140d73bc0(0xb56, 1, static_cast<IMessageListener*>(this), CStringW(L"remove"));
}
