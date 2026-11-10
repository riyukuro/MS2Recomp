// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UITalkPanelSettingDialog: the chat tab settings window, see
// uitalkpanelsettingdialog.h.
// MS2-UNIT: ?\uitalkpanelsettingdialog.cpp
// MS2-RANGE: 0x141b224f0-0x141b265f0 .text$mn
// MS2-RANGE: 0x14011e260-0x14011e350 .text$di
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uitalkpanelsettingdialog.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"

#include "uitalkpanelsettingdialog.h"

#include "ms2/client/ms2/messengerdata.h"
#include "ms2/commonfiles/commonstringtable.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asuicomponent.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/placeholder/iclientplatform.h"
#include "ms2/placeholder/ms2ptr_impl.h"

#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/commonfiles/featuremanager.h"
#include "ms2/client/ms2/uimessenger.h"
#include "ms2/placeholder/cinputkeyhandler.h"  // C3: CInputKeyHandler::FUN_14116d9c0
#include "ms2/placeholder/astextinput.h"   // C3: ASTextInput::FUN_1422e0b00
#include "ms2/placeholder/asbutton.h"  // C3: ASButton::FUN_1422ce090
#include "ms2/placeholder/asslider.h"
#include "ms2/placeholder/unk_blocklist.h"

// ---- statics (init order: the shared header's sort type names, then the file's key input controller) ----

static CString s_strSortTypeNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static UICommon::CMyPCKeyInputController s_keyInput;

// ---- unit-local placeholders (unrecovered helpers) ----

// "m_sliderTransparent" / "m_sliderFontsize": the look sliders; the radios; "m_apply".
#include "ms2/placeholder/asradiobutton.h"   // C3: the radios are ASRadioButton (was the Unk_SdRadio view)
// C3: Unk_140acd6e0 (the button view) is ASButton itself.

// The chat state of the messenger: the tab manager (+0x40) and the chat window (+0x48).
struct Unk_MdState
{
    char m_pad_00[0x38];
    int m_n38;                                                              // +0x38 2 = the tab view
    UIMessenger* m_p40;                                                     // +0x40
    UIMessengerBrowser* m_p48;                                              // +0x48
    void* m_p50;                                                            // +0x50
    void FUN_141482e50();
};
MS2_CHECK_OFFSET(Unk_MdState, m_n38, 0x38);
MS2_CHECK_OFFSET(Unk_MdState, m_p48, 0x48);
struct Unk_MdState* GetState();   // C3: was GetState

class Unk_140166410* FUN_140166410();
class Unk_TpsKeys : public CInputKeyHandler {};
void* FUN_14025e7c0();   // C3: was FUN_14025e7c0
CStringW BlockFormat(int nStringId);
void FUN_140d73aa0(CStringW strText, int nA, void* pListener, CStringW strTag);
void FUN_140d73bc0(int nStringId, int nA, void* pListener, CStringW strTag);
int FUN_1418fc760(char const*, void*, int, void*);   // C3: was FUN_1418fc760
void FUN_140cff840(const Scaleform::GFx::Value& root, CString strName, int n);
void FUN_140d00860(const Scaleform::GFx::Value& root, CString strName, int n);
void FUN_140d00960(const Scaleform::GFx::Value& root, CString strName, unsigned int* pOut);

// The "global" switch (all tabs share one screen look) and the shared look (messengerdata.cpp's statics).
extern int s_nGlobal;
extern MessengerData::ScreenSetting DAT_143adda48;

// ---- UITalkPanelSettingDialog ----

// @0x141b224f0
UITalkPanelSettingDialog::UITalkPanelSettingDialog()
{
    FUN_1422dc3b0(1);
    FUN_141924170(1);
    m_bApplied = 0;
}

// @0x141b22580
UITalkPanelSettingDialog::~UITalkPanelSettingDialog()
{
}

// @0x141b225d0
CString UITalkPanelSettingDialog::GetTypeName()
{
    return "TalkPanelSettingDialog";
}

// @0x141b22620
void UITalkPanelSettingDialog::vfunc_69()
{
    if (m_bApplied == 0)
    {
        if (GetState()->m_n38 == 2)
        {
            if (GetState()->m_p40 != 0)
            {
                MessengerData::TalkTab* pTab = GetState()->m_p40->GetCurrentTab();
                if (pTab != 0)
                {
                    GetState()->m_p40->RemoveTabByName(pTab->m_strName);
                    GetState()->m_p40->vfunc_4();
                }
            }
        }
    }
    vfunc_67();
}

// @0x141b226d0
void UITalkPanelSettingDialog::vfunc_67()
{
    UIDialog::vfunc_67();
    GetState()->FUN_141482e50();
    if (GetState()->m_p48 != 0)
        GetState()->m_p48->FUN_141a25210(1);
    m_spRoot = 0;
}

// @0x141b22730
void UITalkPanelSettingDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    m_spRoot = GetChild<ASUIComponent>("m_settingMenu");
    if (m_spRoot == 0)
        return;
    m_bApplied = 0;
    if (GetState()->m_p40 != 0)
    {
        MessengerData::TalkTab* pTab = GetState()->m_p40->GetCurrentTab();
        if (pTab != 0)
        {
            if (MS2Ptr<ASTextInput> spTab = m_spRoot->FUN_140bbe880<ASTextInput>("m_tab"))
            {
                spTab->SetTextW(pTab->m_strName);
                spTab->FocusAndSetSelection(0, pTab->m_strName.GetLength());
                spTab->vfunc_24(true);
            }
            FUN_141b24ee0(&pTab->m_panel);
        }
    }
    if (GetState()->m_p48 != 0)
        GetState()->m_p48->FUN_141a25210(0);
}

// @0x141b22970
int UITalkPanelSettingDialog::vfunc_13()
{
    if (UIDialog::vfunc_13() != 0)
        return 1;
    if (((class Unk_TpsKeys*)FUN_14025e7c0())->FUN_14116d9c0(0x1c, 0, 0))
    {
        if (MS2Ptr<ASTextInput> spTab = m_spRoot->FUN_140bbe880<ASTextInput>("m_tab"))
        {
            if (spTab->GetFocused() != 0)
            {
                Unk_BlockList request(0x4e62);
                request.Add("OnKeyHandler", FUN_141b23550(), false);
                request.SetEnabled(true);
                if (GetClientPlatform()->vfunc_37(&request) == 1)
                {
                    if (FUN_141b236c0(FUN_141b23550()) == 1)
                    {
                        if (MS2Ptr<ASButton> spApply = GetChild<ASButton>("m_apply"))
                            spApply->SetDisplayFocus(1);
                    }
                }
            }
        }
        return 1;
    }
    return 0;
}

// @0x141b22c60
int UITalkPanelSettingDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (FUN_1418fc760(szMethod, (void*)(pArgs), nArgs, (void*)(this)) != 0)
        return 1;
    if (_stricmp("OnOk", szMethod) == 0)
    {
        Unk_BlockList request(0x4e62);
        request.Add("OnOk", FUN_141b23550(), false);
        request.SetEnabled(true);
        if (GetClientPlatform()->vfunc_37(&request) == 1)
        {
            if (FUN_141b236c0(FUN_141b23550()) == 1)
                vfunc_67();
        }
        return 1;
    }
    else if (_stricmp("eventInitialize", szMethod) == 0)
    {
        EventInitialize();
        return 1;
    }
    else if (_stricmp("eventApply", szMethod) == 0)
    {
        Unk_BlockList request(0x4e62);
        request.Add("eventApply", FUN_141b23550(), false);
        request.SetEnabled(true);
        if (GetClientPlatform()->vfunc_37(&request) == 1)
        {
            FUN_141b236c0(FUN_141b23550());
            m_bApplied = 1;
        }
        return 1;
    }
    else if (_stricmp("OnCloseDialog", szMethod) == 0)
    {
        if (m_bApplied == 0 && GetState()->m_n38 == 2 && GetState()->m_p40 != 0)
        {
            MessengerData::TalkTab* pTab = GetState()->m_p40->GetCurrentTab();
            if (pTab != 0)
            {
                GetState()->m_p40->RemoveTabByName(pTab->m_strName);
                GetState()->m_p40->vfunc_4();
            }
        }
        vfunc_67();
        return 1;
    }
    return UIDialog::vfunc_28(szMethod, pArgs, nArgs);
}

// @0x141b230f0
void UITalkPanelSettingDialog::vfunc_80(void* pRequest)
{
    Unk_BlockList request(*reinterpret_cast<CInPacket*>(pRequest));
    Unk_BlockEntry value;
    if (request.Find("OnKeyHandler", value) == 1 && value.m_nFlags == 0)
    {
        // The key handler applies the text typed in the tab, not the request's text.
        if (FUN_141b236c0(FUN_141b23550()) == 1)
        {
            if (MS2Ptr<ASButton> spApply = GetChild<ASButton>("m_apply"))
                spApply->SetDisplayFocus(1);
        }
        return;
    }
    if (request.Find("OnOk", value) == 1 && value.m_nFlags == 0)
    {
        if (FUN_141b236c0(value.m_strName) == 1)
            vfunc_67();
        return;
    }
    if (request.Find("eventApply", value) == 1 && value.m_nFlags == 0)
    {
        FUN_141b236c0(value.m_strName);
        return;
    }
    if (MS2Ptr<ASTextInput> spTab = m_spRoot->FUN_140bbe880<ASTextInput>("m_tab"))
        spTab->SetTextA("");
    FUN_140d73aa0(BlockFormat(0x8b7), 0, 0, CStringW(L""));
}

// @0x141b23550
CStringW UITalkPanelSettingDialog::FUN_141b23550()
{
    if (MS2Ptr<ASTextInput> spTab = m_spRoot->FUN_140bbe880<ASTextInput>("m_tab"))
        return reinterpret_cast<ASTextInput*>(spTab.operator->())->GetText();
    return L"";
}

// @0x141b23650
int UITalkPanelSettingDialog::EventInitialize()
{
    MessengerData::PanelSetting panel;
    s_nGlobal = 1;
    DAT_143adda48 = panel.m_screen;
    FUN_141b24ee0(&panel);
    return 1;
}

// @0x141b236c0
int UITalkPanelSettingDialog::FUN_141b236c0(const CStringW& strName)
{
    if (GetState()->m_p40 == 0)
        return 0;
    MessengerData::TalkTab* pTab = GetState()->m_p40->GetCurrentTab();
    if (pTab == 0)
        return 0;
    if (strName.IsEmpty())
    {
        FUN_140d73bc0(0x85, 0, 0, CStringW(L""));
        return 0;
    }
    else
    {
        CStringW strMessage;
        if (CBanTextChecker* pChecker = TSingleton<CommonString>::GetInstance()->GetChecker())
        {
            if (pChecker->FUN_140225f70(strName, strMessage) != 0)
            {
                FUN_140d73aa0(CStringW(strMessage), 0, 0, CStringW(L""));
                return 0;
            }
        }
        if (FUN_141b23a40(strName) != 0)
        {
            CStringW strOldName(pTab->m_strName);
            CStringW strNewName(strName);
            FUN_141b23ab0(&pTab->m_panel);
            GetState()->m_p40->RenameTab(strOldName, strNewName);
            GetState()->m_p40->ReselectCurrentTab();
            if (pTab->m_panel.FUN_141482150() != 0)
            {
                GetState()->m_p48->FUN_141a25130(pTab->m_panel.FUN_1414821b0()->m_nFontSize);
                GetState()->m_p48->FUN_141a25160(pTab->m_panel.FUN_1414821b0()->m_nBackgroundAlpha);
            }
            return 1;
        }
        else
        {
            FUN_140d73bc0(0x86, 0, 0, CStringW(L""));
            return 0;
        }
    }
}

// @0x141b23a40
int UITalkPanelSettingDialog::FUN_141b23a40(const CStringW& strName)
{
    if (GetState()->m_p40 != 0 && GetState()->m_p48 != 0)
    {
        return GetState()->m_p48->FUN_141a25410(GetState()->m_p40->GetCurrentTab(), strName);
    }
    return 1;
}

// @0x141b23ab0
void UITalkPanelSettingDialog::FUN_141b23ab0(MessengerData::PanelSetting* pSetting)
{
    if (MS2Ptr<ASCheckBox> sp = m_spRoot->FUN_140c11f50<ASCheckBox>("m_entire"))
        s_nGlobal = sp->FUN_1422ce0e0();
    if (MS2Ptr<ASSlider> sp = m_spRoot->FUN_140fafed0<ASSlider>("m_sliderTransparent"))
    {
        pSetting->m_screen.m_nBackgroundAlpha = (int)(__int64)sp->FUN_1422ce630();
        DAT_143adda48.m_nBackgroundAlpha = (int)(__int64)sp->FUN_1422ce630();
    }
    if (MS2Ptr<ASSlider> sp = m_spRoot->FUN_140fafed0<ASSlider>("m_sliderFontsize"))
    {
        pSetting->m_screen.m_nFontSize = (int)(__int64)sp->FUN_1422ce630();
        DAT_143adda48.m_nFontSize = (int)(__int64)sp->FUN_1422ce630();
    }
    if (MS2Ptr<ASRadioButton> sp = m_spRoot->FUN_140e159f0<ASRadioButton>("m_damageShow"))
    {
        pSetting->m_screen.m_nShowDamage = sp->FUN_1422ce0e0();
        DAT_143adda48.m_nShowDamage = sp->FUN_1422ce0e0();
    }
    FUN_140d00960((*m_spRoot).FUN_1422bb890(), "m_subjectAll", (unsigned int*)&pSetting->m_subject.m_nAll);
    FUN_140d00960((*m_spRoot).FUN_1422bb890(), "m_super", (unsigned int*)&pSetting->m_subject.m_nSuper);
    FUN_140d00960((*m_spRoot).FUN_1422bb890(), "m_world", (unsigned int*)&pSetting->m_subject.m_nWorld);
    FUN_140d00960((*m_spRoot).FUN_1422bb890(), "m_channel", (unsigned int*)&pSetting->m_subject.m_nChannel);
    FUN_140d00960((*m_spRoot).FUN_1422bb890(), "m_social", (unsigned int*)&pSetting->m_subject.m_nSocial);
    FUN_140d00960((*m_spRoot).FUN_1422bb890(), "m_party", (unsigned int*)&pSetting->m_subject.m_nParty);
    FUN_140d00960((*m_spRoot).FUN_1422bb890(), "m_guild", (unsigned int*)&pSetting->m_subject.m_nGuild);
    FUN_140d00960((*m_spRoot).FUN_1422bb890(), "m_whisper", (unsigned int*)&pSetting->m_subject.m_nWhisper);
    if (reinterpret_cast<CFeatureManager*>(FUN_140166410())->FUN_14036d570(0x56) == 1)
        FUN_140d00960((*m_spRoot).FUN_1422bb890(), "m_club", (unsigned int*)&pSetting->m_subject.m_nClub);
    FUN_140d00960((*m_spRoot).FUN_1422bb890(), "m_partyInvite", (unsigned int*)&pSetting->m_subject.m_nPartyInvite);
    if (reinterpret_cast<CFeatureManager*>(FUN_140166410())->FUN_14036d570(0x93) == 1)
        FUN_140d00960((*m_spRoot).FUN_1422bb890(), "m_dungeonHelp", (unsigned int*)&pSetting->m_subject.m_nDungeonHelp);
    FUN_140d00960((*m_spRoot).FUN_1422bb890(), "m_requireAll", (unsigned int*)&pSetting->m_require.m_nAll);
    FUN_140d00960((*m_spRoot).FUN_1422bb890(), "m_meso", (unsigned int*)&pSetting->m_require.m_nMeso);
    FUN_140d00960((*m_spRoot).FUN_1422bb890(), "m_merat", (unsigned int*)&pSetting->m_require.m_nMerat);
    FUN_140d00960((*m_spRoot).FUN_1422bb890(), "m_token", (unsigned int*)&pSetting->m_require.m_nToken);
    FUN_140d00960((*m_spRoot).FUN_1422bb890(), "m_exp", (unsigned int*)&pSetting->m_require.m_nExperience);
    FUN_140d00960((*m_spRoot).FUN_1422bb890(), "m_item", (unsigned int*)&pSetting->m_require.m_nItem);
    FUN_140d00960((*m_spRoot).FUN_1422bb890(), "m_auth", (unsigned int*)&pSetting->m_require.m_nAuth);
    FUN_140d00960((*m_spRoot).FUN_1422bb890(), "m_noticeAll", (unsigned int*)&pSetting->m_notice.m_nAll);
    FUN_140d00960((*m_spRoot).FUN_1422bb890(), "m_user", (unsigned int*)&pSetting->m_notice.m_nUser);
    FUN_140d00960((*m_spRoot).FUN_1422bb890(), "m_trade", (unsigned int*)&pSetting->m_notice.m_nTrade);
    FUN_140d00960((*m_spRoot).FUN_1422bb890(), "m_community", (unsigned int*)&pSetting->m_notice.m_nCommunity);
    FUN_140d00960((*m_spRoot).FUN_1422bb890(), "m_noticeFriend", (unsigned int*)&pSetting->m_notice.m_nFriend);
    FUN_140d00960((*m_spRoot).FUN_1422bb890(), "m_noticeGuild", (unsigned int*)&pSetting->m_notice.m_nGuild);
    FUN_140d00960((*m_spRoot).FUN_1422bb890(), "m_noticeParty", (unsigned int*)&pSetting->m_notice.m_nParty);
    FUN_140d00960((*m_spRoot).FUN_1422bb890(), "m_noticeClub", (unsigned int*)&pSetting->m_notice.m_nClub);
    FUN_140d00960((*m_spRoot).FUN_1422bb890(), "m_noticeMentoring", (unsigned int*)&pSetting->m_notice.m_nMentoring);
    FUN_140d00960((*m_spRoot).FUN_1422bb890(), "m_noticeEtc", (unsigned int*)&pSetting->m_notice.m_nEtc);
    FUN_140d00960((*m_spRoot).FUN_1422bb890(), "m_systemAll", (unsigned int*)&pSetting->m_system.m_nAll);
    FUN_140d00960((*m_spRoot).FUN_1422bb890(), "m_event", (unsigned int*)&pSetting->m_system.m_nEvent);
    FUN_140d00960((*m_spRoot).FUN_1422bb890(), "m_notice", (unsigned int*)&pSetting->m_system.m_nNotice);
}

// @0x141b24ee0
void UITalkPanelSettingDialog::FUN_141b24ee0(MessengerData::PanelSetting* pSetting)
{
    FUN_140d00860((*m_spRoot).FUN_1422bb890(), "m_entire", s_nGlobal);
    if (MS2Ptr<ASSlider> sp = m_spRoot->FUN_140fafed0<ASSlider>("m_sliderTransparent"))
        sp->FUN_1422ce5f0((float)(unsigned int)pSetting->FUN_1414821b0()->m_nBackgroundAlpha);
    if (MS2Ptr<ASSlider> sp = m_spRoot->FUN_140fafed0<ASSlider>("m_sliderFontsize"))
        sp->FUN_1422ce5f0((float)(unsigned int)pSetting->FUN_1414821b0()->m_nFontSize);
    if (MS2Ptr<ASRadioButton> sp = m_spRoot->FUN_140e159f0<ASRadioButton>("m_damageShow"))
        reinterpret_cast<ASButton*>(sp.operator->())->FUN_1422ce090(pSetting->FUN_1414821b0()->m_nShowDamage);
    if (MS2Ptr<ASRadioButton> sp = m_spRoot->FUN_140e159f0<ASRadioButton>("m_damageHide"))
        reinterpret_cast<ASButton*>(sp.operator->())->FUN_1422ce090(pSetting->FUN_1414821b0()->m_nShowDamage == 0);
    FUN_140d00860((*m_spRoot).FUN_1422bb890(), "m_subjectAll", pSetting->FUN_141482200()->m_nAll);
    FUN_140d00860((*m_spRoot).FUN_1422bb890(), "m_social", pSetting->FUN_141482200()->m_nSocial);
    FUN_140d00860((*m_spRoot).FUN_1422bb890(), "m_party", pSetting->FUN_141482200()->m_nParty);
    FUN_140d00860((*m_spRoot).FUN_1422bb890(), "m_guild", pSetting->FUN_141482200()->m_nGuild);
    FUN_140d00860((*m_spRoot).FUN_1422bb890(), "m_whisper", pSetting->FUN_141482200()->m_nWhisper);
    FUN_140d00860((*m_spRoot).FUN_1422bb890(), "m_super", pSetting->FUN_141482200()->m_nSuper);
    FUN_140d00860((*m_spRoot).FUN_1422bb890(), "m_world", pSetting->FUN_141482200()->m_nWorld);
    FUN_140d00860((*m_spRoot).FUN_1422bb890(), "m_channel", pSetting->FUN_141482200()->m_nChannel);
    if (reinterpret_cast<CFeatureManager*>(FUN_140166410())->FUN_14036d570(0x56) == 1)
        FUN_140d00860((*m_spRoot).FUN_1422bb890(), "m_club", pSetting->FUN_141482200()->m_nClub);
    else
        FUN_140cff840((*m_spRoot).FUN_1422bb890(), "m_club", 0);
    FUN_140d00860((*m_spRoot).FUN_1422bb890(), "m_partyInvite", pSetting->FUN_141482200()->m_nPartyInvite);
    if (reinterpret_cast<CFeatureManager*>(FUN_140166410())->FUN_14036d570(0x93) == 1)
        FUN_140d00860((*m_spRoot).FUN_1422bb890(), "m_dungeonHelp", pSetting->FUN_141482200()->m_nDungeonHelp);
    else
        FUN_140cff840((*m_spRoot).FUN_1422bb890(), "m_dungeonHelp", 0);
    FUN_140d00860((*m_spRoot).FUN_1422bb890(), "m_requireAll", pSetting->FUN_1414821e0()->m_nAll);
    FUN_140d00860((*m_spRoot).FUN_1422bb890(), "m_meso", pSetting->FUN_1414821e0()->m_nMeso);
    FUN_140d00860((*m_spRoot).FUN_1422bb890(), "m_merat", pSetting->FUN_1414821e0()->m_nMerat);
    FUN_140d00860((*m_spRoot).FUN_1422bb890(), "m_token", pSetting->FUN_1414821e0()->m_nToken);
    FUN_140d00860((*m_spRoot).FUN_1422bb890(), "m_exp", pSetting->FUN_1414821e0()->m_nExperience);
    FUN_140d00860((*m_spRoot).FUN_1422bb890(), "m_item", pSetting->FUN_1414821e0()->m_nItem);
    FUN_140d00860((*m_spRoot).FUN_1422bb890(), "m_auth", pSetting->FUN_1414821e0()->m_nAuth);
    FUN_140d00860((*m_spRoot).FUN_1422bb890(), "m_noticeAll", pSetting->FUN_141482170()->m_nAll);
    FUN_140d00860((*m_spRoot).FUN_1422bb890(), "m_user", pSetting->FUN_141482170()->m_nUser);
    FUN_140d00860((*m_spRoot).FUN_1422bb890(), "m_trade", pSetting->FUN_141482170()->m_nTrade);
    FUN_140d00860((*m_spRoot).FUN_1422bb890(), "m_community", pSetting->FUN_141482170()->m_nCommunity);
    FUN_140d00860((*m_spRoot).FUN_1422bb890(), "m_noticeFriend", pSetting->FUN_141482170()->m_nFriend);
    FUN_140d00860((*m_spRoot).FUN_1422bb890(), "m_noticeGuild", pSetting->FUN_141482170()->m_nGuild);
    FUN_140d00860((*m_spRoot).FUN_1422bb890(), "m_noticeParty", pSetting->FUN_141482170()->m_nParty);
    FUN_140d00860((*m_spRoot).FUN_1422bb890(), "m_noticeClub", pSetting->FUN_141482170()->m_nClub);
    FUN_140d00860((*m_spRoot).FUN_1422bb890(), "m_noticeMentoring", pSetting->FUN_141482170()->m_nMentoring);
    FUN_140d00860((*m_spRoot).FUN_1422bb890(), "m_noticeEtc", pSetting->FUN_141482170()->m_nEtc);
    FUN_140d00860((*m_spRoot).FUN_1422bb890(), "m_systemAll", pSetting->FUN_141482190()->m_nAll);
    FUN_140d00860((*m_spRoot).FUN_1422bb890(), "m_event", pSetting->FUN_141482190()->m_nEvent);
    FUN_140d00860((*m_spRoot).FUN_1422bb890(), "m_notice", pSetting->FUN_141482190()->m_nNotice);
    if (MS2Ptr<ASButton> sp = GetChild<ASButton>("m_apply"))
        sp->FUN_1422c1fe0(0);
    if (m_spRoot.get() != 0)
        m_spRoot->Invoke("alignCheckBox");
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cc2d30-0x142cc2d80 .text$yd
