// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIGuildHouseUpgradeDialog: see uiguildhouseupgradedialog.h.
// MS2-UNIT: ?\uiguildhouseupgradedialog.cpp
// MS2-RANGE: 0x1400d7e20-0x1400d7e80 .text$di
// MS2-RANGE: 0x140e39790-0x140e3efd0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??__Es_strSkill@@YAXXZ 0x1400d7e20 ; probe
// MS2-PIN: ??__Es_strStun@@YAXXZ 0x1400d7e50 ; probe
// MS2-PIN: ??$?8PEAVUIGuildHouseUpgradeDialog@@P80@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@YA_NAEBU?$pair@PEAVUIGuildHouseUpgradeDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@0@0@Z 0x140e3b570 ; prop
// MS2-PIN: ??$?8PEAVUIGuildHouseUpgradeDialog@@P80@EAA_NHAEBVCMsgBoxData@@@Z@std@@YA_NAEBU?$pair@PEAVUIGuildHouseUpgradeDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@0@0@Z 0x140e3b5e0 ; prop
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVUIGuildHouseUpgradeDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@QEAA@AEBV01@@Z 0x140e3d1f0 ; prop
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVUIGuildHouseUpgradeDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@QEAA@AEBV01@@Z 0x140e3d290 ; prop
// MS2-PIN: ??A?$vector@U?$pair@HH@std@@V?$allocator@U?$pair@HH@std@@@2@@std@@QEAAAEAU?$pair@HH@1@_K@Z 0x140e3d6b0 ; unique
// MS2-PIN: ?GetTypeName@?$DelegateImpl@U?$pair@PEAVUIGuildHouseUpgradeDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x140e3e950 ; unique
// MS2-PIN: ?GetTypeName@?$DelegateImpl@U?$pair@PEAVUIGuildHouseUpgradeDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x140e3e9b0 ; unique
// MS2-PIN: ?vfunc_2@?$DelegateImpl@U?$pair@PEAVUIGuildHouseUpgradeDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z 0x140e3ed50 ; unique
// MS2-PIN: ?Invoke@?$DelegateImpl@U?$pair@PEAVUIGuildHouseUpgradeDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEAA_NHAEBVCMsgBoxData@@@Z 0x140e3ed80 ; unique
// MS2-PIN: ??$Call@VUIGuildHouseUpgradeDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@?$DelegateImpl@U?$pair@PEAVUIGuildHouseUpgradeDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@CAXAEAU?$pair@PEAVUIGuildHouseUpgradeDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@AEBUParams@FunctionHandler@GFx@Scaleform@@@Z 0x140e3edc0 ; unique
// MS2-PIN: ??$Call@VUIGuildHouseUpgradeDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@?$DelegateImpl@U?$pair@PEAVUIGuildHouseUpgradeDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@CA_NAEAU?$pair@PEAVUIGuildHouseUpgradeDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@HAEBVCMsgBoxData@@@Z 0x140e3ee00 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVUIGuildHouseUpgradeDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x140e3ee40 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVUIGuildHouseUpgradeDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x140e3eea0 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiguildhouseupgradedialog.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/astilelist.h"
#include "uiguildhouseupgradedialog.h"
#include "guildmanager.h"
#include "worldservice.h"
#include "ms2/client/ms2/uimessageboxdata.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/astextfield.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/cguildxmldata.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/client/ms2/guildmanager.h"
#include "ms2/placeholder/wcformat.h"  // C3: FUN_14028dfa0 wrappers
#include "ms2/placeholder/asbutton.h"  // C3: ASButton::FUN_1422cdfb0
#include "ms2/placeholder/ascorelist.h"   // C3: ASCoreList::SetSelectedIndex
#include "ms2/placeholder/asbuttonbar.h"

static CString s_strSkill = "skill";
static CString s_strStun = "stun";

// ---- out-of-unit callees (names describe uses) ----
typedef Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)> ParamsDelegate;

// C3: Unk_140acd6e0 (the upgrade button) is ASButton itself.






class Unk_GpAS : public AScript
{
public:
};
class Unk_GalleryAS : public AScript
{
};

CStringW FUN_140763e10(int n);
MS2Ptr<CMsgBoxData> FUN_140d73f20(CStringW text, int type);
void FUN_140d73c60(MS2Ptr<CMsgBoxData> box);
bool FUN_14028d780(unsigned char c);
template<> MS2Ptr<ASTextField> UISwfEntity::GetChild<ASTextField>(const CString&);
template<> MS2Ptr<ASMovieClip> UISwfEntity::GetChild<ASMovieClip>(const CString&);
template<> MS2Ptr<ASButtonBar> UISwfEntity::GetChild<ASButtonBar>(const CString&);
template<> MS2Ptr<ASTileList> UISwfEntity::GetChild<ASTileList>(const CString&);
template<> MS2Ptr<ASButton> UISwfEntity::GetChild<ASButton>(const CString&);

typedef CGuildXmlData::GuildHouse GuildHouse;

// @0x140e39790
UIGuildHouseUpgradeDialog::UIGuildHouseUpgradeDialog()
{
}

// @0x140e39830
UIGuildHouseUpgradeDialog::~UIGuildHouseUpgradeDialog()
{
}

// @0x140e398c0
void UIGuildHouseUpgradeDialog::vfunc_26()
{
    UIDialog::vfunc_26();
    m_themes.clear();
}

// @0x140e39900
void UIGuildHouseUpgradeDialog::vfunc_67()
{
    UIDialog::vfunc_67();
    m_tab = 0;
    m_themeList = 0;
    m_upgradeButton = 0;
}

// @0x140e39960
void UIGuildHouseUpgradeDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    if (FUN_140e3b650<ASButtonBar>("m_tab", m_tab).get())
        m_tab->AddIndexChangeHandler(ParamsDelegate(this, &UIGuildHouseUpgradeDialog::FUN_140e3a910), 0);
    if (FUN_140e3b6e0<ASTileList>("m_themeList", m_themeList).get())
        reinterpret_cast<ASCoreList*>(m_themeList.operator->())->AddListIndexChangeHandler(ParamsDelegate(this, &UIGuildHouseUpgradeDialog::FUN_140e3abc0), 0);
    if (FUN_140bc6d10<ASButton>("m_upgradeButton", m_upgradeButton).get())
        ((class ASButton*)(m_upgradeButton))->FUN_1422ce240(ParamsDelegate(this, &UIGuildHouseUpgradeDialog::OnUpgradeButtonClicked), 0);
    FUN_140e3a770();
    FUN_140e39da0();
}

// @0x140e39d50
CString UIGuildHouseUpgradeDialog::GetTypeName()
{
    return "GuildHouseUpgradeDialog";
}

// @0x140e39da0
void UIGuildHouseUpgradeDialog::FUN_140e39da0()
{
    if (m_30 == 0)
        return;
    int nLevel = m_tab->GetSelectedIndex() + 1;
    int nTheme = reinterpret_cast<ASCoreList*>(m_themeList.operator->())->GetSelectedIndex() + 1;
    MS2Ptr<GuildHouse> house = TSingleton<CGuildXmlData>::GetInstance()->GetHouse(nLevel, nTheme);
    if (house == 0)
        return;
    MS2Ptr<ASTextField> spTitle = GetChild<ASTextField>("m_themeTitle");
    if (spTitle.get())
        spTitle->SetTextW(TSingleton<CStringTable>::GetInstance()->FUN_141811980(0x36, house->f20));
    if (m_upgradeButton.get())
    {
        bool bEnable = true;
        CStringW strLabel(L"");
        if (nLevel < TSingleton<CGuildManager>::GetInstance()->GetHouseLevel())
            bEnable = false;
        if (nLevel == TSingleton<CGuildManager>::GetInstance()->GetHouseLevel() && nTheme == TSingleton<CGuildManager>::GetInstance()->GetHouseTheme())
            bEnable = false;
        if (nLevel == TSingleton<CGuildManager>::GetInstance()->GetHouseLevel())
            strLabel = FUN_14028dfa0<CStringW>(CStringW(L"s_guild_ui_house_change_theme"), FUN_140763e10(house->f30));
        else if (nLevel > TSingleton<CGuildManager>::GetInstance()->GetHouseLevel())
            strLabel = FUN_14028dfa0<CStringW>(CStringW(L"s_guild_ui_house_upgrade_upgrade"), FUN_140763e10(house->f28));
        m_upgradeButton->vfunc_4(bEnable);
        ((class ASButton*)(m_upgradeButton))->SetHtml(true);
        ((class ASButton*)(m_upgradeButton))->FUN_1422cdfb0(strLabel);
        bool bOk = FUN_14028d780((unsigned char)TSingleton<CGuildManager>::GetInstance()->IsMaster(WorldService::GetInstance()->FUN_141bd0d30()));
        if (!bOk)
            ((class ASMovieClip*)(m_upgradeButton))->SetEnabled((int)(0));
    }
    MS2Ptr<ASMovieClip> spInfo = GetChild<ASMovieClip>("m_houseInfo");
    if (spInfo.get())
    {
        MS2Ptr<ASTextField> spArea = spInfo->FUN_1409b4620("m_areaText");
        if (spArea.get())
            spArea->SetTextW(FUN_14028dfa0<int>(CStringW(L"s_home_info_area"), house->f24));
        ASArray arr(2);
        std::vector<int>& facilities = house->f38;
        size_t i = 0;
        while (i < facilities.size())
        {
            ASObj obj(2);
            ((class AScript&)(obj)).SetWStringMember("facility1", TSingleton<CStringTable>::GetInstance()->FUN_141811980(0x37, facilities[i]));
            if (i + 1 < facilities.size())
                ((class AScript&)(obj)).SetWStringMember("facility2", TSingleton<CStringTable>::GetInstance()->FUN_141811980(0x37, facilities[i + 1]));
            arr.PushValue(Scaleform::GFx::Value(obj.GetValue()));
            i += 2;
        }
        m_30.operator->()->InvokeWithArray("setHouseFacility", arr);
    }
    static_cast<Unk_GalleryAS*>(m_30.operator->())->Invoke("setPreviewImage", CStringW(house->f60));
}

// @0x140e3a6b0
bool UIGuildHouseUpgradeDialog::OnUpgradeConfirmed(int nButton, const CMsgBoxData& data)
{
    if (nButton == 0)
    {
        int nLevel = data.FUN_141a02e50(0, 0);
        int nTheme = data.FUN_141a02e50(1, 0);
        TSingleton<CGuildManager>::GetInstance()->FUN_1413ba820(nLevel, nTheme);
    }
    return true;
}

// @0x140e3a720
bool UIGuildHouseUpgradeDialog::OnChangeThemeConfirmed(int nButton, const CMsgBoxData& data)
{
    if (nButton == 0)
    {
        int nTheme = data.FUN_141a02e50(0, 0);
        TSingleton<CGuildManager>::GetInstance()->FUN_1413babf0(nTheme);
    }
    return true;
}

// @0x140e3a770
void UIGuildHouseUpgradeDialog::FUN_140e3a770()
{
    m_themes.clear();
    std::vector<std::pair<int, int> > list;
    TSingleton<CGuildXmlData>::GetInstance()->GetHouseKeys(list);
    for (size_t i = 0; i < list.size(); i++)
        m_themes[list[i].first].push_back(list[i].second);
    static_cast<AScript*>(m_30.operator->())->FUN_140c1c8c0("setTab", m_themes.size());
    m_tab->SetSelectedIndex(TSingleton<CGuildManager>::GetInstance()->GetHouseLevel() - 1);
    reinterpret_cast<ASCoreList*>(m_themeList.operator->())->SetSelectedIndex(TSingleton<CGuildManager>::GetInstance()->GetHouseTheme() - 1);
}

// @0x140e3a910
void UIGuildHouseUpgradeDialog::FUN_140e3a910(const Scaleform::GFx::FunctionHandler::Params& params)
{
    if (m_tab == 0)
        return;
    int nLevel = m_tab->GetSelectedIndex() + 1;
    ASArray arr(2);
    std::map<int, std::vector<int> >::iterator it = m_themes.find(nLevel);
    if (it == m_themes.end())
        return;
    std::vector<int>& ids = it->second;
    for (size_t i = 0; i < ids.size(); i++)
    {
        ASObj obj(2);
        MS2Ptr<GuildHouse> house = TSingleton<CGuildXmlData>::GetInstance()->GetHouse(nLevel, ids[i]);
        if (house == 0)
            return;
        ((class AScript&)(obj)).SetWStringMember("imgpath", CStringW(house->f58));
        arr.PushValue(Scaleform::GFx::Value(obj.GetValue()));
    }
    m_30.operator->()->InvokeWithArray("setThemeTab", arr);
    FUN_140e39da0();
}

// @0x140e3abc0
void UIGuildHouseUpgradeDialog::FUN_140e3abc0(const Scaleform::GFx::FunctionHandler::Params& params)
{
    FUN_140e39da0();
}

// @0x140e3abf0
void UIGuildHouseUpgradeDialog::OnUpgradeButtonClicked(const Scaleform::GFx::FunctionHandler::Params& params)
{
    if (m_30 == 0)
        return;
    int nLevel = m_tab->GetSelectedIndex() + 1;
    int nTheme = reinterpret_cast<ASCoreList*>(m_themeList.operator->())->GetSelectedIndex() + 1;
    int nGuildLevel = TSingleton<CGuildManager>::GetInstance()->GetHouseLevel();
    if (nLevel < nGuildLevel)
        return;
    {
        if (nLevel == nGuildLevel)
        {
            MS2Ptr<GuildHouse> house = TSingleton<CGuildXmlData>::GetInstance()->GetHouse(nLevel, nTheme);
            if (house == 0)
                return;
            CStringW strText = FUN_14028dfa0<CStringW, CStringW>(CStringW(L"s_guild_ui_skill_use_change_theme"), FUN_140763e10(house->f30),
                                             TSingleton<CStringTable>::GetInstance()->FUN_141811980(0x36, house->f20));
            MS2Ptr<CMsgBoxData> box = FUN_140d73f20(CStringW(strText), 1);
            box->SetCallback(Delegate<bool(int, const CMsgBoxData&)>(this, &UIGuildHouseUpgradeDialog::OnChangeThemeConfirmed));
            box->Append<int>(nTheme);
            FUN_140d73c60(MS2Ptr<CMsgBoxData>(box));
        }
        else if (nLevel > nGuildLevel)
        {
            MS2Ptr<GuildHouse> house = TSingleton<CGuildXmlData>::GetInstance()->GetHouse(nLevel, nTheme);
            if (house == 0)
                return;
            CStringW strText = FUN_14028dfa0<CStringW, int, CStringW>(CStringW(L"s_guild_ui_house_use_upgrade"), FUN_140763e10(house->f28), nLevel,
                                             TSingleton<CStringTable>::GetInstance()->FUN_141811980(0x36, house->f20));
            MS2Ptr<CMsgBoxData> box = FUN_140d73f20(CStringW(strText), 1);
            box->SetCallback(Delegate<bool(int, const CMsgBoxData&)>(this, &UIGuildHouseUpgradeDialog::OnUpgradeConfirmed));
            box->Append<int>(nLevel);
            box->Append<int>(nTheme);
            FUN_140d73c60(MS2Ptr<CMsgBoxData>(box));
        }
    }
}

// @0x140e3b650
template<class T> MS2Ptr<T> UIGuildHouseUpgradeDialog::FUN_140e3b650(const CString& strName, MS2Ptr<T>& out)
{
    out = GetChild<T>(strName);
    return out;
}

// @0x140e3b6e0
template<class T> MS2Ptr<T> UIGuildHouseUpgradeDialog::FUN_140e3b6e0(const CString& strName, MS2Ptr<T>& out)
{
    out = GetChild<T>(strName);
    return out;
}

// @0x140bc6d10 (button bind; out of unit, instantiated for the dialog's button type)
template<class T> MS2Ptr<T> UIGuildHouseUpgradeDialog::FUN_140bc6d10(const CString& strName, MS2Ptr<T>& out)
{
    out = GetChild<T>(strName);
    return out;
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca67d0-0x142ca6810 .text$yd
