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
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVUIGuildHouseUpgradeDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x140e3e950 ; unique
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVUIGuildHouseUpgradeDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x140e3e9b0 ; unique
// MS2-PIN: ?vfunc_2@?$DelegateImpl@U?$pair@PEAVUIGuildHouseUpgradeDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z 0x140e3ed50 ; unique
// MS2-PIN: ?Invoke@?$DelegateImpl@U?$pair@PEAVUIGuildHouseUpgradeDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEAA_NHAEBVCMsgBoxData@@@Z 0x140e3ed80 ; unique
// MS2-PIN: ??$Call@VUIGuildHouseUpgradeDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@?$DelegateImpl@U?$pair@PEAVUIGuildHouseUpgradeDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@CAXAEAU?$pair@PEAVUIGuildHouseUpgradeDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@AEBUParams@FunctionHandler@GFx@Scaleform@@@Z 0x140e3edc0 ; unique
// MS2-PIN: ??$Call@VUIGuildHouseUpgradeDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@?$DelegateImpl@U?$pair@PEAVUIGuildHouseUpgradeDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@CA_NAEAU?$pair@PEAVUIGuildHouseUpgradeDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@HAEBVCMsgBoxData@@@Z 0x140e3ee00 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVUIGuildHouseUpgradeDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x140e3ee40 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVUIGuildHouseUpgradeDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x140e3eea0 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiguildhouseupgradedialog.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"
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

static CString s_strSkill = "skill";
static CString s_strStun = "stun";

// ---- out-of-unit callees (names describe uses) ----
typedef Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)> ParamsDelegate;

// The level strip of the movie: the selected tab is a 0-based index.
class Unk_MentorTab : public AScript
{
public:
    int FUN_1422e3210();                                        // selected index
    void FUN_1422e31e0(int nIndex);                             // select
    void FUN_1422e4190(const ParamsDelegate& cb, void* pUser);  // click callback
};
// The theme list of the movie.
class Unk_LdItemBag : public ASMovieClip
{
public:
    void FUN_1422dce60(const ParamsDelegate& cb, void* pUser);  // click callback
    int FUN_1422dccd0();                                        // selected index
    void FUN_1422dcca0(int nIndex);                             // select
};
// The upgrade button.
class Unk_140acd6e0 : public ASDisplayObject
{
public:
    void FUN_1422cdf20(bool b);
    void FUN_1422cdfb0(const CStringW& str);
    void FUN_1422ce240(const ParamsDelegate& cb, void* pUser);
    void FUN_1422c1fe0(unsigned n);
};
class Unk_GpAS : public AScript
{
public:
    Scaleform::GFx::Value FUN_140c1c8c0(const char* szMethod, unsigned __int64 n);
};
class Unk_GalleryAS : public AScript
{
public:
    Scaleform::GFx::Value FUN_140acd130(const char* szMethod, CStringW str);
};

class Unk_1401a9d70 { public: CStringW FUN_141811980(int nTable, int nIndex); };
Unk_1401a9d70* FUN_1401a9d70();
CGuildManager* FUN_1403ed290();
WorldService* FUN_1403ed2d0();
CGuildXmlData* FUN_1404f4530();
CStringW FUN_140763e10(int n);
CStringW FUN_1405c2690(CStringW key, const CStringW& arg);
CStringW FUN_14062b4f0(CStringW key, const int& arg);
CStringW FUN_1408f71a0(CStringW key, const CStringW& a, const CStringW& b);
CStringW FUN_140d26d90(CStringW key, const CStringW& a, const int* pArg, const CStringW& b);
MS2Ptr<CMsgBoxData> FUN_140d73f20(CStringW text, int type);
void FUN_140d73c60(MS2Ptr<CMsgBoxData> box);
bool FUN_14028d780(char c);
template<> MS2Ptr<ASTextField> UISwfEntity::GetChild<ASTextField>(const CString&);
template<> MS2Ptr<ASMovieClip> UISwfEntity::GetChild<ASMovieClip>(const CString&);
template<> MS2Ptr<Unk_MentorTab> UISwfEntity::GetChild<Unk_MentorTab>(const CString&);
template<> MS2Ptr<Unk_LdItemBag> UISwfEntity::GetChild<Unk_LdItemBag>(const CString&);
template<> MS2Ptr<Unk_140acd6e0> UISwfEntity::GetChild<Unk_140acd6e0>(const CString&);

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
    if (FUN_140e3b650<Unk_MentorTab>("m_tab", m_tab).get())
        m_tab->FUN_1422e4190(ParamsDelegate(this, &UIGuildHouseUpgradeDialog::FUN_140e3a910), 0);
    if (FUN_140e3b6e0<Unk_LdItemBag>("m_themeList", m_themeList).get())
        m_themeList->FUN_1422dce60(ParamsDelegate(this, &UIGuildHouseUpgradeDialog::FUN_140e3abc0), 0);
    if (FUN_140bc6d10<Unk_140acd6e0>("m_upgradeButton", m_upgradeButton).get())
        m_upgradeButton->FUN_1422ce240(ParamsDelegate(this, &UIGuildHouseUpgradeDialog::FUN_140e3abf0), 0);
    FUN_140e3a770();
    FUN_140e39da0();
}

// @0x140e39d50
CString UIGuildHouseUpgradeDialog::vfunc_1()
{
    return "GuildHouseUpgradeDialog";
}

// @0x140e39da0
void UIGuildHouseUpgradeDialog::FUN_140e39da0()
{
    if (m_30 == 0)
        return;
    int nLevel = m_tab->FUN_1422e3210() + 1;
    int nTheme = m_themeList->FUN_1422dccd0() + 1;
    Unk_PayloadPtr<GuildHouse> house = FUN_1404f4530()->FUN_1404d79b0(nLevel, nTheme);
    if (house == 0)
        return;
    MS2Ptr<ASTextField> spTitle = GetChild<ASTextField>("m_themeTitle");
    if (spTitle.get())
        spTitle->FUN_1422c4cd0(FUN_1401a9d70()->FUN_141811980(0x36, house->f20));
    if (m_upgradeButton.get())
    {
        bool bEnable = true;
        CStringW strLabel(L"");
        if (nLevel < FUN_1403ed290()->FUN_1404d1f90())
            bEnable = false;
        if (nLevel == FUN_1403ed290()->FUN_1404d1f90() && nTheme == FUN_1403ed290()->FUN_1404d2030())
            bEnable = false;
        if (nLevel == FUN_1403ed290()->FUN_1404d1f90())
            strLabel = FUN_1405c2690(CStringW(L"s_guild_ui_house_change_theme"), FUN_140763e10(house->f30));
        else if (nLevel > FUN_1403ed290()->FUN_1404d1f90())
            strLabel = FUN_1405c2690(CStringW(L"s_guild_ui_house_upgrade_upgrade"), FUN_140763e10(house->f28));
        m_upgradeButton->vfunc_4(bEnable);
        m_upgradeButton->FUN_1422cdf20(true);
        m_upgradeButton->FUN_1422cdfb0(strLabel);
        bool bOk = FUN_14028d780((char)FUN_1403ed290()->FUN_1404d01b0(FUN_1403ed2d0()->FUN_141bd0d30()));
        if (!bOk)
            m_upgradeButton->FUN_1422c1fe0(0);
    }
    MS2Ptr<ASMovieClip> spInfo = GetChild<ASMovieClip>("m_houseInfo");
    if (spInfo.get())
    {
        MS2Ptr<ASTextField> spArea = spInfo->FUN_1409b4620("m_areaText");
        if (spArea.get())
            spArea->FUN_1422c4cd0(FUN_14062b4f0(CStringW(L"s_home_info_area"), house->f24));
        ASArray arr(2);
        std::vector<int>& facilities = house->f38;
        size_t i = 0;
        while (i < facilities.size())
        {
            ASObj obj(2);
            obj.FUN_1407cbb20("facility1", FUN_1401a9d70()->FUN_141811980(0x37, facilities[i]));
            if (i + 1 < facilities.size())
                obj.FUN_1407cbb20("facility2", FUN_1401a9d70()->FUN_141811980(0x37, facilities[i + 1]));
            arr.FUN_1422bc050(Scaleform::GFx::Value(obj.FUN_1422bb870()));
            i += 2;
        }
        m_30.operator->()->FUN_140bd2cb0("setHouseFacility", arr);
    }
    static_cast<Unk_GalleryAS*>(m_30.operator->())->FUN_140acd130("setPreviewImage", CStringW(house->f60));
}

// @0x140e3a6b0
bool UIGuildHouseUpgradeDialog::FUN_140e3a6b0(int nButton, const CMsgBoxData& data)
{
    if (nButton == 0)
    {
        int nLevel = data.FUN_141a02e50(0, 0);
        int nTheme = data.FUN_141a02e50(1, 0);
        FUN_1403ed290()->FUN_1413ba820(nLevel, nTheme);
    }
    return true;
}

// @0x140e3a720
bool UIGuildHouseUpgradeDialog::FUN_140e3a720(int nButton, const CMsgBoxData& data)
{
    if (nButton == 0)
    {
        int nTheme = data.FUN_141a02e50(0, 0);
        FUN_1403ed290()->FUN_1413babf0(nTheme);
    }
    return true;
}

// @0x140e3a770
void UIGuildHouseUpgradeDialog::FUN_140e3a770()
{
    m_themes.clear();
    std::vector<std::pair<int, int> > list;
    FUN_1404f4530()->FUN_1404d7a90(list);
    for (size_t i = 0; i < list.size(); i++)
        m_themes[list[i].first].push_back(static_cast<int&&>(list[i].second));
    static_cast<Unk_GpAS*>(m_30.operator->())->FUN_140c1c8c0("setTab", m_themes.size());
    m_tab->FUN_1422e31e0(FUN_1403ed290()->FUN_1404d1f90() - 1);
    m_themeList->FUN_1422dcca0(FUN_1403ed290()->FUN_1404d2030() - 1);
}

// @0x140e3a910
void UIGuildHouseUpgradeDialog::FUN_140e3a910(const Scaleform::GFx::FunctionHandler::Params& params)
{
    if (m_tab == 0)
        return;
    int nLevel = m_tab->FUN_1422e3210() + 1;
    ASArray arr(2);
    std::map<int, std::vector<int> >::iterator it = m_themes.find(nLevel);
    if (it == m_themes.end())
        return;
    std::vector<int>& ids = it->second;
    for (size_t i = 0; i < ids.size(); i++)
    {
        ASObj obj(2);
        Unk_PayloadPtr<GuildHouse> house = FUN_1404f4530()->FUN_1404d79b0(nLevel, ids[i]);
        if (house == 0)
            return;
        obj.FUN_1407cbb20("imgpath", CStringW(house->f58));
        arr.FUN_1422bc050(Scaleform::GFx::Value(obj.FUN_1422bb870()));
    }
    m_30.operator->()->FUN_140bd2cb0("setThemeTab", arr);
    FUN_140e39da0();
}

// @0x140e3abc0
void UIGuildHouseUpgradeDialog::FUN_140e3abc0(const Scaleform::GFx::FunctionHandler::Params& params)
{
    FUN_140e39da0();
}

// @0x140e3abf0
void UIGuildHouseUpgradeDialog::FUN_140e3abf0(const Scaleform::GFx::FunctionHandler::Params& params)
{
    if (m_30 == 0)
        return;
    int nLevel = m_tab->FUN_1422e3210() + 1;
    int nTheme = m_themeList->FUN_1422dccd0() + 1;
    int nGuildLevel = FUN_1403ed290()->FUN_1404d1f90();
    if (nLevel < nGuildLevel)
        return;
    {
        if (nLevel == nGuildLevel)
        {
            Unk_PayloadPtr<GuildHouse> house = FUN_1404f4530()->FUN_1404d79b0(nLevel, nTheme);
            if (house == 0)
                return;
            CStringW strText = FUN_1408f71a0(CStringW(L"s_guild_ui_skill_use_change_theme"), FUN_140763e10(house->f30),
                                             FUN_1401a9d70()->FUN_141811980(0x36, house->f20));
            MS2Ptr<CMsgBoxData> box = FUN_140d73f20(CStringW(strText), 1);
            box->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &UIGuildHouseUpgradeDialog::FUN_140e3a720));
            box->FUN_140533ff0(nTheme);
            FUN_140d73c60(MS2Ptr<CMsgBoxData>(box));
        }
        else if (nLevel > nGuildLevel)
        {
            Unk_PayloadPtr<GuildHouse> house = FUN_1404f4530()->FUN_1404d79b0(nLevel, nTheme);
            if (house == 0)
                return;
            CStringW strText = FUN_140d26d90(CStringW(L"s_guild_ui_house_use_upgrade"), FUN_140763e10(house->f28), &nLevel,
                                             FUN_1401a9d70()->FUN_141811980(0x36, house->f20));
            MS2Ptr<CMsgBoxData> box = FUN_140d73f20(CStringW(strText), 1);
            box->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &UIGuildHouseUpgradeDialog::FUN_140e3a6b0));
            box->FUN_140533ff0(nLevel);
            box->FUN_140533ff0(nTheme);
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
