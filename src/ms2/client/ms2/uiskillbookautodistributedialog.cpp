// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The skill window ("SkillBookTreeDialog", UI type 0x4f2d): up to
// three saved skill sets (tabs) per character, each with its own CSkillPointSimulator, the job / sub job skill tree filled
// into the movie slot by slot, the point reset / apply / auto-distribute flow, and the "SkillBookAutoDistributeDialog"
// (UI type 0x4f20) that lets the player pick one of the table's presets (Table/skillAutoDistribute.xml). See
// uiskillbookautodistributedialog.h.
// MS2-UNIT: ?\uiskillbookautodistributedialog.cpp
// MS2-RANGE: 0x1400dc6d0-0x1400dc9e0 .text$di
// MS2-RANGE: 0x140ec41e0-0x140ed74c0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
//
// File name assumed (the exe has no assert path for it).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiskillbookautodistributedialog.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"

#include "uiskillbookautodistributedialog.h"

#include <algorithm>
#include <map>
#include <vector>

#include "ms2/ms2format.h"
#include "ms2/client/ms2/uimessagebox.h"
#include "ms2/client/ms2/uimessageboxdata.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/astooltip.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/imessagelistener.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

MS2_EMIT_CRT_MEMMOVE_S();

// ---- header statics (dynamic initializers 0x1400dc6d0..0x1400dc9e0; the same pair as uiarcademaindialog.cpp) ----
#ifndef MS2_HOOK_DLL
static CString s_strSortNames7[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill = "skill";
static CString s_strStun = "stun";
static Unk_1402a9d70 s_unk1402a9d70(17, 0.75f, 0.25f, 2.25f, 10);
static UICommon::CMyPCKeyInputController s_keyInputController;
static CString s_strSortNames7b[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill2 = "skill";
static CString s_strStun2 = "stun";
static Unk_1402a9d70 s_unk1402a9d70b(17, 0.75f, 0.25f, 2.25f, 10);
#endif

// ---- unit-local views of exe objects ----

// The local player and the world (FUN_1403ed2d0 -> FUN_141bd0cc0).
class MyPC;
class Unk_SkillWorld { public: MyPC* FUN_141bd0cc0(); };
Unk_SkillWorld* FUN_1403ed2d0();

// The three "m_distribute{N}" buttons.
class Unk_140acd6e0 : public ASDisplayObject
{
public:
    void FUN_1422cdfb0(const CStringW& strLabel);                           // the button text
    void FUN_1422c7cd0(const Scaleform::GFx::Value& tooltip);               // the tooltip object
};

// The dialog's bound-child lookup (UISwfEntity members; the exe has one COMDAT per child class).
class Unk_SkillDlgView : public UIModalDialog
{
public:
    MS2Ptr<Unk_140acd6e0> FUN_140bb4b10(const CString& strName);            // button child
    MS2Ptr<ASMovieClip> FUN_140ba7930(const CString& strName);              // movie clip child
};

// The movie root of the dialog (RTTI .?AVASDialog@@); slot 24 repaints it. // MS2: slot 24
class ASDialog : public ASDisplayObject {};
class Unk_ASDialogSlots
{
public:
    virtual void V0(); virtual void V1(); virtual void V2(); virtual void V3(); virtual void V4(); virtual void V5();
    virtual void V6(); virtual void V7(); virtual void V8(); virtual void V9(); virtual void V10(); virtual void V11();
    virtual void V12(); virtual void V13(); virtual void V14(); virtual void V15(); virtual void V16(); virtual void V17();
    virtual void V18(); virtual void V19(); virtual void V20(); virtual void V21(); virtual void V22(); virtual void V23();
    virtual void Invalidate(bool bNow);                                     // +0xc0
};
// The dialog background clip (the height follows the number of entries).
class Unk_SkillBgClip : public ASMovieClip
{
public:
    void FUN_1422c0ef0(int nHeight);
};

bool FUN_1403b3c40(const CStringW& str, const wchar_t* sz);                // equals
CStringW FUN_14028b8e0(const CStringW& strKey);                             // string table text
CStringW FUN_1405c2690(CStringW strFormat, const CStringW& strArg);        // format one argument
CString FUN_14052ea30(const char* szFormat, const int* pn);                 // format one int
void FUN_140d73aa0(CStringW text, int type, void* pListener, CStringW tag); // open a message box that reports to pListener
UIDialog* FUN_1409eb120(int nId);                                           // the shown dialog of a UI id
void FUN_14151f200();                                                       // close the message box
class Unk_SkillLogService { public: };
Unk_SkillLogService* FUN_140d8ee90();
void FUN_140a1f970(Unk_SkillLogService* pService, const CString& strEvent, const CString& strParam);   // usage log
CString FUN_1401d4330(const wchar_t* psz, int nCodePage);                   // narrows a string

// @0x140ec41e0
UISkillBookAutoDistributeDialog::UISkillBookAutoDistributeDialog()
{
    m_nSelected = 0;
    FUN_141924170(1);
    FUN_1422dc3b0(1);
}

// @0x140ec4290
UISkillBookAutoDistributeDialog::~UISkillBookAutoDistributeDialog()
{
}

// @0x140ec4300
CString UISkillBookAutoDistributeDialog::vfunc_1()
{
    return "SkillBookAutoDistributeDialog";
}

// @0x140ec4350
void UISkillBookAutoDistributeDialog::vfunc_67()
{
    UIModalDialog::vfunc_67();
    m_names.RemoveAll();
    m_tooltips.RemoveAll();
}

// @0x140ec43a0
int UISkillBookAutoDistributeDialog::vfunc_65()
{
    if (UIDialog::vfunc_65() == 0)
        return 0;
    return 1;
}

// @0x140ec43d0
void UISkillBookAutoDistributeDialog::OnLoadComplete()
{
    UIModalDialog::OnLoadComplete();
    FUN_140ec48e0();
}

// @0x140ec4400
int UISkillBookAutoDistributeDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    ASData data;
    if (_stricmp("onDistribute", szMethod) == 0)
    {
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
        {
            m_nSelected = data.FUN_1422b8a10() - 1;
            if (m_names.GetCount() > m_nSelected)
            {
                CStringW strText = FUN_1405c2690(L"s_msg_skillbook_auto_distribute_msgbox", FUN_14028b8e0(m_names[m_nSelected]));
                FUN_140d73aa0(strText, 1, static_cast<IMessageListener*>(this), L"onDistribute");
            }
        }
        return 1;
    }
    return 0;
}

// @0x140ec4660
int UISkillBookAutoDistributeDialog::OnMessage(UISwfEntity* pSender, UIMsg* pMsg)
{
    if (UIDialog::OnMessage(pSender, pMsg) != 0)
        return 1;
    if (pMsg->FUN_1422e4520() == 0 && dynamic_cast<UIMessageBox*>(pSender) != 0)
    {
        int nResult = pMsg->FUN_1422b8a10();
        if ((m_30.get() ? true : false) && nResult == 0)
        {
            CStringW strTag = pMsg->FUN_1422b8f40();
            if (FUN_1403b3c40(strTag, L"onDistribute") != 0)
            {
                UISkillBookTreeDialog* pTree = static_cast<UISkillBookTreeDialog*>(FUN_1409eb120(0x4f2d));
                if (pTree != 0 && pTree->vfunc_55() == 0)
                {
                    pTree->ApplyDistribute(m_nSelected);
                    CStringW strName = FUN_14028b8e0(m_names[m_nSelected]);
                    FUN_140a1f970(FUN_140d8ee90(), "skll_auto_distribute", FUN_1401d4330(m_names[m_nSelected], 0));
                }
            }
            FUN_14151f200();
            vfunc_67();
        }
        else
        {
            FUN_14151f200();
        }
    }
    return 0;
}

// @0x140ec48e0
void UISkillBookAutoDistributeDialog::FUN_140ec48e0()
{
    if (m_30.IsNull())
        return;
    MyPC* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return;
    int nShown = 0;
    int nNo;
    for (unsigned i = 0; i < 3; i++)
    {
        nNo = i + 1;
        CString strName = FUN_14052ea30("m_distribute{0}", &nNo);
        MS2Ptr<Unk_140acd6e0> spButton = static_cast<Unk_SkillDlgView*>(static_cast<UIModalDialog*>(this))->FUN_140bb4b10(strName);
        if (spButton == 0)
            continue;
        spButton->vfunc_3(1);
        if (m_names.GetCount() <= i)
        {
            spButton->vfunc_3(0);
        }
        else
        {
            spButton->FUN_1422cdfb0(FUN_14028b8e0(m_names[i]));
            CStringW strTooltip = FUN_14028b8e0(m_tooltips[i]);
            if (!strTooltip.IsEmpty())
            {
                ASTooltip tooltip(2);
                tooltip.FUN_1409e26b0(strTooltip);
                tooltip.FUN_1409c6dc0(4);
                spButton->FUN_1422c7cd0(tooltip.FUN_1422bb890());
            }
            nShown++;
        }
    }
    MS2Ptr<ASDialog> spDialog(dynamic_cast<ASDialog*>((AScript*)m_30));
    if (spDialog.get() != 0)
    {
        MS2Ptr<ASMovieClip> spBg = static_cast<Unk_SkillDlgView*>(static_cast<UIModalDialog*>(this))->FUN_140ba7930("m_bg");
        if (spBg.get() != 0)
        {
            int nHeight = nShown * 0x2a + 0x41;
            static_cast<Unk_SkillBgClip*>(spBg.operator->())->FUN_1422c0ef0(nHeight);
        }
        reinterpret_cast<Unk_ASDialogSlots*>(spDialog.operator->())->Invalidate(true);
    }
}
