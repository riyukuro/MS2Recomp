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

// ---- statics (init order: the shared header's sort type names, then the file's key input controller) ----

static CString s_strSortTypeNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static UICommon::CMyPCKeyInputController s_keyInput;

// ---- unit-local placeholders (unrecovered helpers) ----

// The AS controls of the movie (slot 24 of the input is the one the dialog calls).
class Unk_TpsControl : public AScript
{
public:
    virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4();
    virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8();
    virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12();
    virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15(); virtual void vfunc_16();
    virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19(); virtual void vfunc_20();
    virtual void vfunc_21(); virtual void vfunc_22(); virtual void vfunc_23();
    virtual void vfunc_24(int n);
};
// "m_tab": the tab name input.
class Unk_TpsInput : public Unk_TpsControl
{
public:
    void FUN_1422e0a60(const CString& strText);             // set the text (narrow)
    void FUN_1422e0ab0(const CStringW& strText);            // set the text
    void FUN_1422e1500(int nBegin, int nEnd);               // select a range
    CStringW FUN_1422e0b00();                               // the text
    int FUN_1422c76c0();                                    // has focus
};
// "m_entire": the "all tabs share one look" check.
class Unk_TpsCheck : public AScript
{
public:
    bool FUN_1422ce0e0();
};
// "m_sliderTransparent" / "m_sliderFontsize": the look sliders (float values).
class Unk_TpsSlider : public AScript
{
public:
    void FUN_1422ce5f0(float f);
    float FUN_1422ce630();
};
// "m_damageShow" / "m_damageHide": the damage line radios.
class Unk_TpsRadio : public AScript
{
public:
    void FUN_1422ce090(int bChecked);
    bool FUN_1422ce0e0();
};
// "m_apply": the apply button.
class Unk_TpsButton : public ASDisplayObject
{
public:
    void FUN_1422c1fe0(unsigned int bEnabled);
    void FUN_1422c7730(int bEnabled);
};
// The root clip's child lookups by name (one COMDAT per wrapper class).
class Unk_TpsRoot : public ASUIComponent
{
public:
    template <class T> MS2Ptr<T> FUN_140bbe880(const CString& strName);
    template <class T> MS2Ptr<T> FUN_140c11f50(const CString& strName);
    template <class T> MS2Ptr<T> FUN_140fafed0(const CString& strName);
    template <class T> MS2Ptr<T> FUN_140e28bc0(const CString& strName);
};

// The chat tab manager (Unk_MdState +0x40) and the chat window (+0x48).
class Unk_TpsTabMgr
{
public:
    virtual ~Unk_TpsTabMgr();
    virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4();                                                 // refresh the tabs
    MessengerData::TalkTab* FUN_141a0e050();                                // the current tab
    void FUN_141a0e350(const CStringW& strName);                            // make a tab current
    void FUN_141a0e9f0(CStringW strOldName, CStringW strNewName);           // rename a tab
    void FUN_141a0e990();                                                   // save the tabs
};
class Unk_TpsChat
{
public:
    void FUN_141a25130(int nFontSize);
    void FUN_141a25160(int nAlpha);
    void FUN_141a25210(int bEnabled);
    int FUN_141a25410(MessengerData::TalkTab* pTab, const CStringW& strName);
};
struct Unk_TpsState
{
    char m_pad_00[0x38];
    int m_n38;                                                              // +0x38 2 = the tab view
    Unk_TpsTabMgr* m_p40;                                                    // +0x40
    Unk_TpsChat* m_p48;                                                      // +0x48
    void* m_p50;                                                            // +0x50
    void FUN_141482e50();
};
MS2_CHECK_OFFSET(Unk_TpsState, m_n38, 0x38);
MS2_CHECK_OFFSET(Unk_TpsState, m_p48, 0x48);
Unk_TpsState* FUN_141482e80();

// The platform request (the "OnKeyHandler" / "OnOk" / "eventApply" answers) and its value.
class Unk_TpsRequest
{
public:
    Unk_TpsRequest(int nId);                                                 // 0x1401baa00
    Unk_TpsRequest(const void* pSource);                                     // 0x1401baaa0
    ~Unk_TpsRequest();                                                       // 0x1401baaf0
    void FUN_1401bac80(CString strName, CStringW strValue, int n);
    void FUN_1401badc0(int bEnabled);
    char FUN_1401bab90(CString strName, void* pOut);
private:
    char m_pad[0x38];
};
struct Unk_TpsReqValue
{
    Unk_TpsReqValue();                                                          // 0x1401ba840
    ~Unk_TpsReqValue();                                                         // 0x1401ba940
    char m_pad_00[8];
    CStringW m_strText;                                                     // +0x08
    char m_pad_10[8];
    int m_code;                                                             // +0x18
    char m_pad_1c[0x1c];
};
MS2_CHECK_SIZE(Unk_TpsReqValue, 0x38);

class Unk_TpsFeatures { public: bool FUN_14036d570(int nFeature); };
Unk_TpsFeatures* FUN_140166410();
class Unk_TpsKeys { public: bool FUN_14116d9c0(int nKey, int a, int b); };
Unk_TpsKeys* FUN_14025e7c0();
CommonString* FUN_14025e7d0();
CStringW FUN_1409eec40(int nStringId);
void FUN_140d73aa0(CStringW strText, int nA, int nB, CStringW strTag);
void FUN_140d73bc0(int nStringId, int nA, void* p, CStringW strTag);
int FUN_1418fc760(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs, UIDialog* pDialog);
void FUN_140cff840(const Scaleform::GFx::Value& root, CString strName, int n);
void FUN_140d00860(const Scaleform::GFx::Value& root, CString strName, int n);
void FUN_140d00960(const Scaleform::GFx::Value& root, CString strName, int* pOut);

// The "global" switch (all tabs share one screen look) and the shared look (messengerdata.cpp's statics).
extern int DAT_1439f7cbc;
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
CString UITalkPanelSettingDialog::vfunc_1()
{
    return "TalkPanelSettingDialog";
}

// @0x141b22620
void UITalkPanelSettingDialog::vfunc_69()
{
    if (m_bApplied == 0)
    {
        if (FUN_141482e80()->m_n38 == 2)
        {
            if (FUN_141482e80()->m_p40 != 0)
            {
                MessengerData::TalkTab* pTab = FUN_141482e80()->m_p40->FUN_141a0e050();
                if (pTab != 0)
                {
                    FUN_141482e80()->m_p40->FUN_141a0e350(pTab->m_strName);
                    FUN_141482e80()->m_p40->vfunc_4();
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
    FUN_141482e80()->FUN_141482e50();
    if (FUN_141482e80()->m_p48 != 0)
        FUN_141482e80()->m_p48->FUN_141a25210(1);
    m_spRoot = 0;
}

// @0x141b22730
void UITalkPanelSettingDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    m_spRoot = GetChild<ASUIComponent>("m_settingMenu");
    if (!(m_spRoot == 0))
    {
        m_bApplied = 0;
        if (FUN_141482e80()->m_p40 != 0)
        {
            MessengerData::TalkTab* pTab = FUN_141482e80()->m_p40->FUN_141a0e050();
            if (pTab != 0)
            {
                MS2Ptr<Unk_TpsInput> spTab = static_cast<Unk_TpsRoot*>(m_spRoot.operator->())->FUN_140bbe880<Unk_TpsInput>("m_tab");
                if (static_cast<Unk_TpsInput*>(spTab) != 0)
                {
                    spTab->FUN_1422e0ab0(pTab->m_strName);
                    spTab->FUN_1422e1500(0, pTab->m_strName.GetLength());
                    spTab->vfunc_24(1);
                }
                FUN_141b24ee0(&pTab->m_panel);
            }
        }
        if (FUN_141482e80()->m_p48 != 0)
            FUN_141482e80()->m_p48->FUN_141a25210(0);
    }
}

// @0x141b22970
int UITalkPanelSettingDialog::vfunc_13()
{
    if (UIDialog::vfunc_13() != 0)
        return 1;
    if (!FUN_14025e7c0()->FUN_14116d9c0(0x1c, 0, 0))
        return 0;
    MS2Ptr<Unk_TpsInput> spTab = static_cast<Unk_TpsRoot*>(m_spRoot.operator->())->FUN_140bbe880<Unk_TpsInput>("m_tab");
    if (static_cast<Unk_TpsInput*>(spTab) != 0)
    {
        if (spTab->FUN_1422c76c0() != 0)
        {
            Unk_TpsRequest request(0x4e62);
            request.FUN_1401bac80("OnKeyHandler", FUN_141b23550(), 0);
            request.FUN_1401badc0(1);
            if (GetClientPlatform()->vfunc_37(&request) == 1)
            {
                if (FUN_141b236c0(FUN_141b23550()) == 1)
                {
                    MS2Ptr<Unk_TpsButton> spApply = FUN_140bb4b10("m_apply");
                    if (static_cast<Unk_TpsButton*>(spApply) != 0)
                        spApply->FUN_1422c7730(1);
                }
            }
        }
    }
    return 1;
}

// @0x141b22c60
int UITalkPanelSettingDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (FUN_1418fc760(szMethod, pArgs, nArgs, this) != 0)
        return 1;
    if (_stricmp("OnOk", szMethod) == 0)
    {
        Unk_TpsRequest request(0x4e62);
        request.FUN_1401bac80("OnOk", FUN_141b23550(), 0);
        request.FUN_1401badc0(1);
        if (GetClientPlatform()->vfunc_37(&request) == 1)
        {
            if (FUN_141b236c0(FUN_141b23550()) == 1)
                vfunc_67();
        }
        return 1;
    }
    if (_stricmp("eventInitialize", szMethod) == 0)
    {
        FUN_141b23650();
        return 1;
    }
    if (_stricmp("eventApply", szMethod) == 0)
    {
        Unk_TpsRequest request(0x4e62);
        request.FUN_1401bac80("eventApply", FUN_141b23550(), 0);
        request.FUN_1401badc0(1);
        if (GetClientPlatform()->vfunc_37(&request) == 1)
        {
            FUN_141b236c0(FUN_141b23550());
            m_bApplied = 1;
        }
        return 1;
    }
    if (_stricmp("OnCloseDialog", szMethod) == 0)
    {
        if (m_bApplied == 0 && FUN_141482e80()->m_n38 == 2 && FUN_141482e80()->m_p40 != 0)
        {
            MessengerData::TalkTab* pTab = FUN_141482e80()->m_p40->FUN_141a0e050();
            if (pTab != 0)
            {
                FUN_141482e80()->m_p40->FUN_141a0e350(pTab->m_strName);
                FUN_141482e80()->m_p40->vfunc_4();
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
    Unk_TpsRequest request(pRequest);
    Unk_TpsReqValue value;
    if (request.FUN_1401bab90("OnKeyHandler", &value) == 1 && value.m_code == 0)
    {
        if (FUN_141b236c0(value.m_strText) == 1)
        {
            MS2Ptr<Unk_TpsButton> spApply = FUN_140bb4b10("m_apply");
            if (static_cast<Unk_TpsButton*>(spApply) != 0)
                spApply->FUN_1422c7730(1);
        }
    }
    else if (request.FUN_1401bab90("OnOk", &value) == 1 && value.m_code == 0)
    {
        if (FUN_141b236c0(value.m_strText) == 1)
            vfunc_67();
    }
    else if (request.FUN_1401bab90("eventApply", &value) == 1 && value.m_code == 0)
    {
        FUN_141b236c0(value.m_strText);
    }
    else
    {
        MS2Ptr<Unk_TpsInput> spTab = static_cast<Unk_TpsRoot*>(m_spRoot.operator->())->FUN_140bbe880<Unk_TpsInput>("m_tab");
        if (static_cast<Unk_TpsInput*>(spTab) != 0)
            spTab->FUN_1422e0a60("");
        FUN_140d73aa0(FUN_1409eec40(0x8b7), 0, 0, CStringW(L""));
    }
}

// @0x141b23550
CStringW UITalkPanelSettingDialog::FUN_141b23550()
{
    MS2Ptr<Unk_TpsInput> spTab = static_cast<Unk_TpsRoot*>(m_spRoot.operator->())->FUN_140bbe880<Unk_TpsInput>("m_tab");
    if (static_cast<Unk_TpsInput*>(spTab) == 0)
        return L"";
    return spTab->FUN_1422e0b00();
}   // MS2-FUNCTIONAL: not byte-matched (temp destruction order)

// @0x141b23650
int UITalkPanelSettingDialog::FUN_141b23650()
{
    MessengerData::PanelSetting panel;
    DAT_1439f7cbc = 1;
    DAT_143adda48 = panel.m_screen;
    FUN_141b24ee0(&panel);
    return 1;
}

// @0x141b236c0
int UITalkPanelSettingDialog::FUN_141b236c0(const CStringW& strName)
{
    if (FUN_141482e80()->m_p40 == 0)
        return 0;
    MessengerData::TalkTab* pTab = FUN_141482e80()->m_p40->FUN_141a0e050();
    if (pTab == 0)
        return 0;
    if (strName.IsEmpty())
    {
        FUN_140d73bc0(0x85, 0, 0, CStringW(L""));
        return 0;
    }
    CStringW strMessage;
    CBanTextChecker* pChecker = FUN_14025e7d0()->GetChecker();
    if (pChecker != 0 && pChecker->FUN_140225f70(strName, strMessage) != 0)
    {
        FUN_140d73aa0(CStringW(strMessage), 0, 0, CStringW(L""));
        return 0;
    }
    if (FUN_141b23a40(strName) == 0)
    {
        FUN_140d73bc0(0x86, 0, 0, CStringW(L""));
        return 0;
    }
    CStringW strOldName(pTab->m_strName);
    CStringW strNewName(strName);
    FUN_141b23ab0(&pTab->m_panel);
    FUN_141482e80()->m_p40->FUN_141a0e9f0(strOldName, strNewName);
    FUN_141482e80()->m_p40->FUN_141a0e990();
    if (pTab->m_panel.FUN_141482150() != 0)
    {
        FUN_141482e80()->m_p48->FUN_141a25130(pTab->m_panel.FUN_1414821b0()->m_nFontSize);
        FUN_141482e80()->m_p48->FUN_141a25160(pTab->m_panel.FUN_1414821b0()->m_nBackgroundAlpha);
    }
    return 1;
}   // MS2-FUNCTIONAL: not byte-matched (temp destruction order)

// @0x141b23a40
int UITalkPanelSettingDialog::FUN_141b23a40(const CStringW& strName)
{
    if (FUN_141482e80()->m_p40 != 0 && FUN_141482e80()->m_p48 != 0)
    {
        MessengerData::TalkTab* pTab = FUN_141482e80()->m_p40->FUN_141a0e050();
        return FUN_141482e80()->m_p48->FUN_141a25410(pTab, strName);
    }
    return 1;
}

// @0x141b23ab0
void UITalkPanelSettingDialog::FUN_141b23ab0(MessengerData::PanelSetting* pSetting)
{
    {
        MS2Ptr<Unk_TpsCheck> sp = static_cast<Unk_TpsRoot*>(m_spRoot.operator->())->FUN_140c11f50<Unk_TpsCheck>("m_entire");
        if (static_cast<Unk_TpsCheck*>(sp) != 0)
            DAT_1439f7cbc = sp->FUN_1422ce0e0();
    }
    {
        MS2Ptr<Unk_TpsSlider> sp = static_cast<Unk_TpsRoot*>(m_spRoot.operator->())->FUN_140fafed0<Unk_TpsSlider>("m_sliderTransparent");
        if (static_cast<Unk_TpsSlider*>(sp) != 0)
        {
            pSetting->m_screen.m_nBackgroundAlpha = (int)(__int64)sp->FUN_1422ce630();
            DAT_143adda48.m_nBackgroundAlpha = (int)(__int64)sp->FUN_1422ce630();
        }
    }
    {
        MS2Ptr<Unk_TpsSlider> sp = static_cast<Unk_TpsRoot*>(m_spRoot.operator->())->FUN_140fafed0<Unk_TpsSlider>("m_sliderFontsize");
        if (static_cast<Unk_TpsSlider*>(sp) != 0)
        {
            pSetting->m_screen.m_nFontSize = (int)(__int64)sp->FUN_1422ce630();
            DAT_143adda48.m_nFontSize = (int)(__int64)sp->FUN_1422ce630();
        }
    }
    {
        MS2Ptr<Unk_TpsRadio> sp = static_cast<Unk_TpsRoot*>(m_spRoot.operator->())->FUN_140e28bc0<Unk_TpsRadio>("m_damageShow");
        if (static_cast<Unk_TpsRadio*>(sp) != 0)
        {
            pSetting->m_screen.m_nShowDamage = sp->FUN_1422ce0e0();
            DAT_143adda48.m_nShowDamage = sp->FUN_1422ce0e0();
        }
    }
    FUN_140d00960((*m_spRoot).FUN_1422bb890(), "m_subjectAll", &pSetting->m_subject.m_nAll);
    FUN_140d00960((*m_spRoot).FUN_1422bb890(), "m_super", &pSetting->m_subject.m_nSuper);
    FUN_140d00960((*m_spRoot).FUN_1422bb890(), "m_world", &pSetting->m_subject.m_nWorld);
    FUN_140d00960((*m_spRoot).FUN_1422bb890(), "m_channel", &pSetting->m_subject.m_nChannel);
    FUN_140d00960((*m_spRoot).FUN_1422bb890(), "m_social", &pSetting->m_subject.m_nSocial);
    FUN_140d00960((*m_spRoot).FUN_1422bb890(), "m_party", &pSetting->m_subject.m_nParty);
    FUN_140d00960((*m_spRoot).FUN_1422bb890(), "m_guild", &pSetting->m_subject.m_nGuild);
    FUN_140d00960((*m_spRoot).FUN_1422bb890(), "m_whisper", &pSetting->m_subject.m_nWhisper);
    if (FUN_140166410()->FUN_14036d570(0x56) == 1)
        FUN_140d00960((*m_spRoot).FUN_1422bb890(), "m_club", &pSetting->m_subject.m_nClub);
    FUN_140d00960((*m_spRoot).FUN_1422bb890(), "m_partyInvite", &pSetting->m_subject.m_nPartyInvite);
    if (FUN_140166410()->FUN_14036d570(0x93) == 1)
        FUN_140d00960((*m_spRoot).FUN_1422bb890(), "m_dungeonHelp", &pSetting->m_subject.m_nDungeonHelp);
    FUN_140d00960((*m_spRoot).FUN_1422bb890(), "m_requireAll", &pSetting->m_require.m_nAll);
    FUN_140d00960((*m_spRoot).FUN_1422bb890(), "m_meso", &pSetting->m_require.m_nMeso);
    FUN_140d00960((*m_spRoot).FUN_1422bb890(), "m_merat", &pSetting->m_require.m_nMerat);
    FUN_140d00960((*m_spRoot).FUN_1422bb890(), "m_token", &pSetting->m_require.m_nToken);
    FUN_140d00960((*m_spRoot).FUN_1422bb890(), "m_exp", &pSetting->m_require.m_nExperience);
    FUN_140d00960((*m_spRoot).FUN_1422bb890(), "m_item", &pSetting->m_require.m_nItem);
    FUN_140d00960((*m_spRoot).FUN_1422bb890(), "m_auth", &pSetting->m_require.m_nAuth);
    FUN_140d00960((*m_spRoot).FUN_1422bb890(), "m_noticeAll", &pSetting->m_notice.m_nAll);
    FUN_140d00960((*m_spRoot).FUN_1422bb890(), "m_user", &pSetting->m_notice.m_nUser);
    FUN_140d00960((*m_spRoot).FUN_1422bb890(), "m_trade", &pSetting->m_notice.m_nTrade);
    FUN_140d00960((*m_spRoot).FUN_1422bb890(), "m_community", &pSetting->m_notice.m_nCommunity);
    FUN_140d00960((*m_spRoot).FUN_1422bb890(), "m_noticeFriend", &pSetting->m_notice.m_nFriend);
    FUN_140d00960((*m_spRoot).FUN_1422bb890(), "m_noticeGuild", &pSetting->m_notice.m_nGuild);
    FUN_140d00960((*m_spRoot).FUN_1422bb890(), "m_noticeParty", &pSetting->m_notice.m_nParty);
    FUN_140d00960((*m_spRoot).FUN_1422bb890(), "m_noticeClub", &pSetting->m_notice.m_nClub);
    FUN_140d00960((*m_spRoot).FUN_1422bb890(), "m_noticeMentoring", &pSetting->m_notice.m_nMentoring);
    FUN_140d00960((*m_spRoot).FUN_1422bb890(), "m_noticeEtc", &pSetting->m_notice.m_nEtc);
    FUN_140d00960((*m_spRoot).FUN_1422bb890(), "m_systemAll", &pSetting->m_system.m_nAll);
    FUN_140d00960((*m_spRoot).FUN_1422bb890(), "m_event", &pSetting->m_system.m_nEvent);
    FUN_140d00960((*m_spRoot).FUN_1422bb890(), "m_notice", &pSetting->m_system.m_nNotice);
}   // MS2-FUNCTIONAL: not byte-matched (temp string locals)

// @0x141b24ee0
void UITalkPanelSettingDialog::FUN_141b24ee0(MessengerData::PanelSetting* pSetting)
{
    FUN_140d00860((*m_spRoot).FUN_1422bb890(), "m_entire", DAT_1439f7cbc);
    {
        MS2Ptr<Unk_TpsSlider> sp = static_cast<Unk_TpsRoot*>(m_spRoot.operator->())->FUN_140fafed0<Unk_TpsSlider>("m_sliderTransparent");
        if (static_cast<Unk_TpsSlider*>(sp) != 0)
            sp->FUN_1422ce5f0((float)(unsigned int)pSetting->FUN_1414821b0()->m_nBackgroundAlpha);
    }
    {
        MS2Ptr<Unk_TpsSlider> sp = static_cast<Unk_TpsRoot*>(m_spRoot.operator->())->FUN_140fafed0<Unk_TpsSlider>("m_sliderFontsize");
        if (static_cast<Unk_TpsSlider*>(sp) != 0)
            sp->FUN_1422ce5f0((float)(unsigned int)pSetting->FUN_1414821b0()->m_nFontSize);
    }
    {
        MS2Ptr<Unk_TpsRadio> sp = static_cast<Unk_TpsRoot*>(m_spRoot.operator->())->FUN_140e28bc0<Unk_TpsRadio>("m_damageShow");
        if (static_cast<Unk_TpsRadio*>(sp) != 0)
            sp->FUN_1422ce090(pSetting->FUN_1414821b0()->m_nShowDamage);
    }
    {
        MS2Ptr<Unk_TpsRadio> sp = static_cast<Unk_TpsRoot*>(m_spRoot.operator->())->FUN_140e28bc0<Unk_TpsRadio>("m_damageHide");
        if (static_cast<Unk_TpsRadio*>(sp) != 0)
            sp->FUN_1422ce090(pSetting->FUN_1414821b0()->m_nShowDamage == 0);
    }
    FUN_140d00860((*m_spRoot).FUN_1422bb890(), "m_subjectAll", pSetting->FUN_141482200()->m_nAll);
    FUN_140d00860((*m_spRoot).FUN_1422bb890(), "m_social", pSetting->FUN_141482200()->m_nSocial);
    FUN_140d00860((*m_spRoot).FUN_1422bb890(), "m_party", pSetting->FUN_141482200()->m_nParty);
    FUN_140d00860((*m_spRoot).FUN_1422bb890(), "m_guild", pSetting->FUN_141482200()->m_nGuild);
    FUN_140d00860((*m_spRoot).FUN_1422bb890(), "m_whisper", pSetting->FUN_141482200()->m_nWhisper);
    FUN_140d00860((*m_spRoot).FUN_1422bb890(), "m_super", pSetting->FUN_141482200()->m_nSuper);
    FUN_140d00860((*m_spRoot).FUN_1422bb890(), "m_world", pSetting->FUN_141482200()->m_nWorld);
    FUN_140d00860((*m_spRoot).FUN_1422bb890(), "m_channel", pSetting->FUN_141482200()->m_nChannel);
    if (FUN_140166410()->FUN_14036d570(0x56) == 1)
        FUN_140d00860((*m_spRoot).FUN_1422bb890(), "m_club", pSetting->FUN_141482200()->m_nClub);
    else
        FUN_140cff840((*m_spRoot).FUN_1422bb890(), "m_club", 0);
    FUN_140d00860((*m_spRoot).FUN_1422bb890(), "m_partyInvite", pSetting->FUN_141482200()->m_nPartyInvite);
    if (FUN_140166410()->FUN_14036d570(0x93) == 1)
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
    {
        MS2Ptr<Unk_TpsButton> sp = FUN_140bb4b10("m_apply");
        if (static_cast<Unk_TpsButton*>(sp) != 0)
            sp->FUN_1422c1fe0(0);
    }
    if (m_spRoot.get() != 0)
        m_spRoot->Invoke("alignCheckBox");
}   // MS2-FUNCTIONAL: not byte-matched (temp string locals)
