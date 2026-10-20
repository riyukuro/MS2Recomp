// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIGuildDialog: see uiguilddialog.h.
// MS2-UNIT: client\ms2\uiguilddialog.cpp
// MS2-RANGE: 0x1401141b0-0x140114300 .text$di
// MS2-RANGE: 0x141960ce0-0x141980ed0 .text$mn
// MS2-RANGE: 0x142cbe5b0-0x142cbe640 .text$yd
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??__Es_strSkill@@YAXXZ 0x1401141b0 ; probe
// MS2-PIN: ??__Es_strStun@@YAXXZ 0x1401142a0 ; probe
// MS2-PIN: ??__Es_strTooltipAlign@@YAXXZ 0x1401142d0 ; probe
// MS2-PIN: ??$?0$$V@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CB_KV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@@2@$00@std@@QEAA@U_Zero_then_variadic_args_t@1@@Z 0x141978d80 ; prop
// MS2-PIN: ??$?0AEBU?$less@_K@std@@U_Zero_then_variadic_args_t@1@@?$_Compressed_pair@U?$less@_K@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CB_KV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@@2@$00@2@$00@std@@QEAA@U_One_then_variadic_args_t@1@AEBU?$less@_K@1@$$QEAU_Zero_then_variadic_args_t@1@@Z 0x141978eb0 ; unique
// MS2-PIN: ?SetManager@CNilStringData@ATL@@QEAAXPEAUIAtlStringMgr@2@@Z 0x14197c010 ; unique
// MS2-PIN: ??$forward@AEAPEAU?$_Tree_node@U?$pair@$$CBII@std@@PEAX@std@@@std@@YAAEAPEAU?$_Tree_node@U?$pair@$$CBII@std@@PEAX@0@AEAPEAU10@@Z 0x14197c350 ; order
// MS2-PIN: ??$forward@AEBU?$less@_K@std@@@std@@YAAEBU?$less@_K@0@AEBU10@@Z 0x14197c7c0 ; prop
// MS2-PIN: ??$forward@AEBVCMsgBoxData@@@std@@YAAEBVCMsgBoxData@@AEBV1@@Z 0x14197c7f0 ; order
// MS2-PIN: ??0?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBII@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@1@@Z 0x14197cef0 ; prop
// MS2-PIN: ??0?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@@std@@@std@@QEAA@XZ 0x14197cf50 ; prop
// MS2-PIN: ??0?$allocator@U?$_Tree_node@U?$pair@$$CB_KV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@std@@PEAX@std@@@std@@QEAA@XZ 0x14197d0e0 ; prop
// MS2-PIN: ??1?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@QEAA@XZ 0x14197d560 ; order
// MS2-PIN: ??8?$MS2Ptr@VASUIComponent@@@@QEBA_NPEAVASUIComponent@@@Z 0x14197d620 ; probe
// MS2-PIN: ??C?$MS2Ptr@VASUIComponent@@@@QEBAPEAVASUIComponent@@XZ 0x14197d870 ; probe
// MS2-PIN: ?GetModuleInstance@CAtlBaseModule@ATL@@QEAAPEAUHINSTANCE__@@XZ 0x14197d880 ; probe
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@std@@QEAAAEAV01@XZ 0x14197da70 ; prop
// MS2-PIN: ?vfunc_48@UIGuildDialog@@UEAAHXZ 0x14197e030 ; unique
// MS2-PIN: ?__empty_global_delete@@YAXPEAX_K@Z 0x14197e460 ; order
// MS2-PIN: ?_Freeheadnode@?$_Tree_comp_alloc@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@HPEAX@2@@Z 0x14197f230 ; prop
// MS2-PIN: ?_Freeheadnode@?$_Tree_comp_alloc@V?$_Tmap_traits@IIU?$less@I@std@@V?$allocator@U?$pair@$$CBII@std@@@2@$00@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBII@std@@PEAX@2@@Z 0x14197f260 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@HPEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@2@$00@std@@QEAAAEAV?$allocator@U?$_Tree_node@HPEAX@std@@@2@XZ 0x14197f350 ; order
// MS2-PIN: ?_Getal@?$_Tree_comp_alloc@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@QEAAAEAV?$allocator@U?$_Tree_node@HPEAX@std@@@2@XZ 0x14197f410 ; order
// MS2-PIN: ?DeletePtred@CPtred@@SAXPEAV1@@Z 0x14197f710 ; order
// MS2-PIN: ?ReleasePtred@CPtred@@SAHPEAV1@@Z 0x14197f730 ; order
// MS2-PIN: ?_Tidy@?$_Tree@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@IEAAXXZ 0x14197f9a0 ; prop
// MS2-PIN: ?end@?$_Tree@V?$_Tmap_traits@IIU?$less@I@std@@V?$allocator@U?$pair@$$CBII@std@@@2@$00@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@@2@XZ 0x1419801e0 ; prop
// MS2-PIN: ?end@?$_Tree@V?$_Tset_traits@HU?$less@H@std@@V?$allocator@H@2@$0A@@std@@@std@@QEAA?AV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@H@std@@@std@@@2@XZ 0x1419802a0 ; prop
// MS2-PIN: ??__Fs_strSkill@@YAXXZ 0x142cbe5b0 ; probe
// MS2-PIN: ??__Fs_strStun@@YAXXZ 0x142cbe600 ; probe
// MS2-PIN: ??__Fs_strTooltipAlign@@YAXXZ 0x142cbe620 ; probe
// MS2-PINS-END tplpin
//
// PARTIAL (w478): the layout, the statics, the small members and the page openers. Not written yet: OnLoadComplete,
// vfunc_26/28/45/53/67/72, OnMessage, the page builders (FUN_14196b620 .. FUN_141976730, up to 4.7KB each), the mark
// web request and the std::map / multimap / set glue (run tools/tplpin.py once the users exist).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiguilddialog.cpp"
#include "ms2/placeholder/ms2stdafx.h"

#include "uiguilddialog.h"
#include "guildmanager.h"
#include "uimessageboxdata.h"

#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/commonfiles/gamerule.h"
#include "ms2/placeholder/cguildxmldata.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/client/ms2/uimessagebox.h"
#include "ms2/client/ms2/pcbase.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/astooltip.h"
#include "ms2/placeholder/astextinput.h"
#include "ms2/placeholder/astextfield.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/placeholder/asbuttonbar.h"
#include "ms2/placeholder/ascorelist.h"
#include "ms2/placeholder/cfeaturemanager.h"
#include "ms2/placeholder/packethandlermanager.h"
#include "ms2/placeholder/uistatuseventdispatcher.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- statics (.text$di) ----
static CString s_strTooltipAlign = "tooltipAlign";
static CString s_strSortTypeNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill = "skill";
static CString s_strStun = "stun";

// ---- unit-local views of exe objects ----

class Unk_GdBrowser { public: void FUN_14135ec00(const CString& strUrl, bool bOnce); };   // UIWebBrowser: open a url
Unk_GdBrowser* FUN_140c43790(int nUiId);                        // the web browser dialog of an id
class Unk_GdWorld { public: PCBase* FUN_141bd0cc0(); };         // the local player
Unk_GdWorld* FUN_1403ed2d0();
void FUN_1408741a0(void* pCfg, const char* szSection, const char* szKey, int* pValue);   // read an int setting
void FUN_140874440(void* pCfg, const char* szSection, const char* szKey, int nValue, bool bFlush);   // write an int setting
bool FUN_140184310(const CString& str, const char* psz);        // str == psz
CString FUN_1402bb1c0(const char* szFormat, const int& n);      // StringFormat<int>
CStringW FUN_1401e8510(const wchar_t* pszFormat, const CStringW& strArg);   // StringFormat with one argument
CStringW FUN_1408116a0(int nId, const int& nArg);               // formatted system text
CStringW FUN_140811740(int nId, const int& nArg1, const int& nArg2);   // formatted system text
CStringW FUN_140298ea0(CStringW strKey);                        // a string table text
CStringW FUN_140763e10(int nValue);                             // a money amount
CStringW FUN_1405c2690(CStringW strKey, const CStringW& strArg);   // string table format
CStringW FUN_1409e8970(CStringW strKey, const int& nA, const int& nB);   // string table format
CStringW FUN_140d26a00(CStringW strKey, CStringW strArg, const int& nA, const int& nB);   // string table format
CStringW FUN_14028b8e0(const CStringW& strKey);                 // a string table text
void* FUN_1409b4bc0(Scaleform::GFx::Value* pRetVal, Scaleform::GFx::Value& v);    // *pRetVal = v
class Unk_GdEventValue { public: unsigned FUN_140423670(); };   // the guild exp event rate (1/10000)
class Unk_GdEventMgr                                            // CGameEventValueManager
{
public:
    Unk_GdEventValue* FUN_1403eea70();                          // the guild exp event
    int FUN_1413cdf60();                                        // the bonus rate scale (10000)
};
Unk_GdEventMgr* FUN_140302b00();
class ASDialog : public ASDisplayObjectContainer {};            // the movie root (UIDialog::m_90): only addChild is used
bool FUN_1403b3c40(const CStringW& str, const wchar_t* psz);    // str == psz
bool FUN_140841300(const CStringW& str, const char* psz);       // str == psz
CStringW FUN_14016a730(const char* psz, int nCodePage);         // multibyte -> wide
bool FUN_14028d780(char c);                                     // c != 0
void FUN_1422bcce0(Scaleform::GFx::Value* pValue, bool b);      // set a Boolean value
CStringW FUN_14052bd00(int nId, const CStringW& strArg);       // formatted system text
void FUN_140cfee80(const Scaleform::GFx::Value& root, CString strName, CStringW strText);   // set a text clip's text
void FUN_1422bccb0(Scaleform::GFx::Value* pValue, int n);       // set an Int value
void FUN_1422bcd70(Scaleform::GFx::Value* pValue, float f);     // set a Number value
CStringW FUN_1418f5ab0(int nId, const short& nArg1, const CStringW& strArg2, const CStringW& strArg3);   // formatted system text
CString FUN_141028be0(__int64 nCharacterId, const CString& strKey, int nKind, CString strExt);   // a UGC profile path
void FUN_14028cd00(const CStringW& strText, CAtlArray<CStringW>& arrOut, const wchar_t* pszSep, int nMax);   // split
void FUN_14151f200();                                           // close the message box on top
void FUN_140710590(COutPacket& packet);                         // send
void FUN_14141f970(const CString& strName);                     // drop the item slots registered under a name
CString FUN_141029590(unsigned __int64 nGuildId, const CString& strMark, const CString& a3, CString a4);   // the mark image path
CString FUN_140719530(unsigned __int64 n);                      // "%I64u"

// ---- the dialog ----

// @0x141960ce0
UIGuildDialog::UIGuildDialog()
{
    m_7c = 1;
    m_bMarksPending = false;
    m_nTab = 0;
    m_nMemberSort = 0;
    m_bLoading = false;
    m_nSearchPage = 1;
    m_nAcceptPage = 1;
    m_strStorageName = "GuildDialog_storageItems";
    m_strRealtimeRankUrl = "maview:/Rank/Guild?tp=realtime";
    m_strRankUrl = "maview:/Rank/Guild";
    m_strPvpRankUrl = "maview:/Rank/GuildPVP?tp=realtime";
    FUN_141924170(1);
}

// @0x1419610c0
UIGuildDialog::~UIGuildDialog()
{
}

// @0x141961390
int UIGuildDialog::vfunc_65()
{
    if (UIDialog::vfunc_65() == 0)
        return 0;
    return 1;
}
MS2_REPLACE_METHOD(0x141961390, UIGuildDialog, vfunc_65, 37, 0x9F86173A);

// @0x1419613c0
void UIGuildDialog::vfunc_67()
{
    if (m_30.get())
        m_30->Invoke("ClosePopup");
    if (m_storagePage.get())
        m_storagePage->Invoke("ClosePopup");
    UIDialog::vfunc_67();
    m_bMarksPending = false;
    CGuildManager::GetInstance()->FUN_1413c7ed0();
    UIStatusEventDispatcher::GetInstance()->FUN_141b0cd90(this);
}

// @0x1419614e0
void UIGuildDialog::vfunc_72()
{
    UIDialog::vfunc_72();
    if (vfunc_55() != 0)
        return;
    FUN_1419758a0();
    FUN_141975c80();
    FUN_1419760c0();
    if (!m_bMarksPending)
        return;
    if (Unk_LockGuard guard = m_lock) {}
    else
    {
        if (m_marks.empty())
            return;
        if (m_pvpHistoryPage.get())
        {
            std::map<unsigned __int64, CString>::iterator it = m_marks.begin();
            std::map<unsigned __int64, CString>::iterator itEnd = m_marks.end();
            for (; it != itEnd; ++it)
            {
                CString strMark = FUN_141029590(it->first, it->second, "", "");
                m_pvpHistoryPage->FUN_1413127f0("setGuildMark", FUN_140719530(it->first), strMark);
            }
        }
        m_marks.clear();
        m_bMarksPending = false;
    }
}

// @0x1419617e0
void UIGuildDialog::vfunc_26()
{
    UIDialog::vfunc_26();
    FUN_14141f970(m_strStorageName);
    PacketHandlerManager::GetInstance()->UnregisterHandler(0x8a, Delegate<void(CInPacket&)>(this, &UIGuildDialog::FUN_141968140));
    m_1b0.clear();
    m_1c0.clear();
    m_requests.clear();
    m_createPage = 0;
    m_joinPage = 0;
    m_infoPage = 0;
    m_memberPage = 0;
    m_managePage = 0;
    m_championshipPage = 0;
    m_pvpHistoryPage = 0;
    m_acceptRequestPage = 0;
    m_skillPage = 0;
    m_skillPage2 = 0;
    m_eventPage = 0;
    m_housePage = 0;
    m_storagePage = 0;
    m_raidPage = 0;
    m_eventVsGame = 0;
    m_eventLoader = 0;
    m_eventImageArea = 0;
    m_button368 = 0;
    m_button378 = 0;
}

// @0x141961ab0
void UIGuildDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    if (m_30.get())
    {
        FUN_141974ce0();
        if (CGuildManager::GetInstance()->FUN_1413b6160())
        {
            if (MS2Ptr<ASButtonBar> spCategory = FUN_140c02870("m_category"))
            {
                spCategory->FUN_1422c7630(1);
                spCategory->FUN_1422e31e0(m_nTab);
                spCategory->vfunc_24(1);
                m_30->Invoke("onCategoryChange");
            }
        }
        else
        {
            CGuildManager::GetInstance()->FUN_1413bc710(1);
        }
        if (CFeatureManager::GetInstance()->FUN_14036d570(0x110) == 1)
        {
            if (MS2Ptr<ASMovieClip> spIcon = m_30->FUN_1409b4560("m_championshipIcon"))
            {
                if (CGameRule::GetInstance()->FUN_14047e880() && CGuildManager::GetInstance()->FUN_1413b6160())
                    spIcon->vfunc_3(1);
                else
                    spIcon->vfunc_3(0);
            }
        }
    }
    FUN_14196da70();
    UIStatusEventDispatcher::GetInstance()->FUN_141b0cd00(this);
    PacketHandlerManager::GetInstance()->RegisterHandler(0x8a, Delegate<void(CInPacket&)>(this, &UIGuildDialog::FUN_141968140));
}

// @0x141961e40
int UIGuildDialog::vfunc_54(void* pCfg)
{
    UIDialog::vfunc_54(pCfg);
    FUN_1408741a0(pCfg, "Histroy", "lastTabIndex", &m_nTab);
    FUN_1408741a0(pCfg, "History", "lastMemberSortindex", &m_nMemberSort);
    return 1;
}
MS2_REPLACE_METHOD(0x141961e40, UIGuildDialog, vfunc_54, 115, 0x59B31712);

// @0x141961ec0
int UIGuildDialog::vfunc_53(void* pCfg)
{
    if (MS2Ptr<ASButtonBar> spCategory = FUN_140c02870("m_category"))
        m_nTab = spCategory->FUN_1422e3210();
    if (m_memberPage.get())
    {
        if (MS2Ptr<ASDropdownMenu> spSort = m_memberPage->FUN_140bbe700("m_sortDropdown"))
            m_nMemberSort = spSort->FUN_1422df6c0();
    }
    UIDialog::vfunc_53(pCfg);
    FUN_140874440(pCfg, "Histroy", "lastTabIndex", m_nTab, 1);
    FUN_140874440(pCfg, "History", "lastMemberSortindex", m_nMemberSort, 1);
    return 1;
}

// @0x141962650
void UIGuildDialog::vfunc_45(Scaleform::GFx::Value* pRetVal, const CString& strMethod, ASData* pArgs)
{
    UIObject::vfunc_45(pRetVal, strMethod, pArgs);
    if (!FUN_140184310(strMethod, "getTooltip"))
        return;
    CString strName = pArgs->FUN_1422b8d30();
    if (FUN_140184310(strName, "campionship_grade"))
    {
        ASObj obj(2);
        obj.FUN_1409c0dc0("tooltip", "guild_champion_ship_tooltip");
        obj.FUN_1409eb310(s_strTooltipAlign, 7);
        for (int nGrade = 1; nGrade < 8; nGrade++)
        {
            int nScore = 0;
            Unk_GuildSeason* pSeason = CGuildManager::GetInstance()->FUN_1404d3180();
            if (pSeason->id == 0)
                return;
            nScore = pSeason->FUN_1404c60e0(nGrade);
            CString strRankKey = FUN_1402bb1c0("rankName{0}", nGrade);
            CString strScoreKey = FUN_1402bb1c0("score{0}", nGrade);
            CStringW strRank = FUN_1401e8510(L"{0}", CStringTable::GetInstance()->FUN_141811980(0x2d, nGrade));
            CStringW strScore = FUN_1408116a0(0x3f7, nScore);
            obj.FUN_1407cbb20(strRankKey, strRank);
            obj.FUN_1407cbb20(strScoreKey, strScore);
        }
        FUN_1409b4bc0(pRetVal, obj.FUN_1422bb870());
    }
    else if (FUN_140184310(strName, "member_memo"))
    {
        CStringW strMember = pArgs->FUN_1422b8f40();
        MS2Ptr<CGuildMember> spMember = CGuildManager::GetInstance()->FUN_1404cf9f0(strMember);
        if (spMember.get())
        {
            CStringW strMemo = spMember->fb8;
            if (strMemo.GetLength() < 1)
                return;
            ASTooltip tip(1, 2);
            tip.FUN_1409c6dc0(5);
            if (tip.FUN_1409e26b0(strMemo))
                FUN_1409b4bc0(pRetVal, tip.FUN_1422bb870());
        }
    }
    else if (FUN_140184310(strName, "m_expInfo"))
    {
        CStringW strText = FUN_140298ea0(L"s_guild_ui_info_guild_exp_tooltip");
        if (CFeatureManager::GetInstance()->FUN_14036d570(0x79))
            strText += FUN_140298ea0(L"s_guild_ui_info_guild_raid_tooltip");
        ASTooltip tip(1, 2);
        tip.FUN_1409c6dc0(1);
        if (tip.FUN_1409e26b0(strText))
            FUN_1409b4bc0(pRetVal, tip.FUN_1422bb870());
    }
    else if (FUN_140184310(strName, "m_goldInfo"))
    {
        int nHouseLevel = CGuildManager::GetInstance()->FUN_1404d1ad0();
        Unk_PayloadPtr<CGuildXmlData::GuildProperty> spProperty = CGuildXmlData::GetInstance()->FUN_1404d7410(nHouseLevel);
        if (spProperty == 0)
            return;
        int nFund = (int)spProperty->f28;
        CStringW strText = FUN_1405c2690(L"s_guild_ui_info_guild_fund_tooltip", FUN_140763e10(nFund));
        if (CFeatureManager::GetInstance()->FUN_14036d570(0x79))
            strText += FUN_140298ea0(L"s_guild_ui_info_guild_raid_tooltip");
        ASTooltip tip(1, 2);
        tip.FUN_1409c6dc0(1);
        if (tip.FUN_1409e26b0(strText))
            FUN_1409b4bc0(pRetVal, tip.FUN_1422bb870());
    }
    else if (FUN_140184310(strName, "m_guildLevelGauge"))
    {
        int nExp = CGuildManager::GetInstance()->FUN_1404d1a80();
        int nLevel = CGuildXmlData::GetInstance()->FUN_1404d7130(nExp);
        if (nLevel < 1)
            return;
        int nPrevLevel = nLevel - 1;
        int nPrevExp = CGuildXmlData::GetInstance()->FUN_1404d7200(nPrevLevel);
        int nNextExp = CGuildXmlData::GetInstance()->FUN_1404d7200(nLevel);
        int nNeed = nNextExp - nPrevExp;
        int nHave = nExp - nPrevExp;
        CStringW strText;
        float fRate = (float)FUN_140302b00()->FUN_1403eea70()->FUN_140423670();
        float fBonus = fRate / (float)FUN_140302b00()->FUN_1413cdf60() + 1.0f;
        if (fBonus <= 1.0f)
        {
            strText = FUN_1409e8970(L"s_guild_ui_info_guild_exp", nHave, nNeed);
        }
        else
        {
            CStringW strBonus;
            int nTenth = (int)(fBonus * 10.0f);
            if (nTenth % 10 < 1)
                strBonus.Format(L"%.0f", fBonus);
            else
                strBonus.Format(L"%.1f", fBonus);
            strText = FUN_140d26a00(L"s_guild_ui_info_guild_exp_event", strBonus, nHave, nNeed);
        }
        if (CGuildXmlData::GetInstance()->FUN_1404d72f0() == nLevel)
        {
            CStringW strKey(L"s_guild_ui_info_guild_exp_max");
            strText = FUN_14028b8e0(strKey);
        }
        ASTooltip tip(1, 2);
        tip.FUN_1409c6dc0(1);
        if (tip.FUN_1409e26b0(strText))
            FUN_1409b4bc0(pRetVal, tip.FUN_1422bb870());
    }
    else if (FUN_140184310(strName, "m_participate"))
    {
        PCBase* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pPlayer == 0)
            return;
        CStringW strPlayer = pPlayer->vfunc_77();
        MS2Ptr<CGuildMember> spMember = CGuildManager::GetInstance()->FUN_1404cf9f0(strPlayer);
        if (spMember.get())
        {
            CStringW strText = FUN_140811740(0x3f6, spMember->fe0, spMember->fe4);
            ASTooltip tip(1, 2);
            if (tip.FUN_1409e26b0(strText))
                FUN_1409b4bc0(pRetVal, tip.FUN_1422bb870());
        }
    }
}

// @0x1419620b0
int UIGuildDialog::OnMessage(UISwfEntity* pSender, UIMsg* pMsg)
{
    if (UIDialog::OnMessage(pSender, pMsg) != 0)
        return 1;
    if (pMsg->FUN_1422e4520() == 0 && dynamic_cast<UIMessageBox*>(pSender) != 0)
    {
        bool bClose = true;
        int nResult = pMsg->FUN_1422b8a10();
        CStringW strTag = pMsg->FUN_1422b8f40();
        if (nResult == 0)
        {
            CAtlArray<CStringW> arrTag;
            FUN_14028cd00(strTag, arrTag, L",", 2);
            if (arrTag.GetCount() == 1)
            {
                FUN_14151f200();
                bClose = false;
                if (strTag.Find(L"breakGuild") == 0)
                {
                    FUN_141974ea0();
                }
                else if (strTag.Find(L"leaveGuild") == 0)
                {
                    CGuildManager::GetInstance()->FUN_1413b75a0();
                }
                else if (strTag.Find(L"expelMember") == 0)
                {
                    CGuildManager::GetInstance()->FUN_1413b76c0(m_strDesc);
                    m_strDesc = "";
                }
                else if (strTag.Find(L"changeMaster") == 0)
                {
                    CGuildManager::GetInstance()->FUN_1413b7ad0(m_strName);
                    m_strName = "";
                }
                else if (strTag.Find(L"sendMail") == 0)
                {
                    FUN_1419751e0();
                }
                else if (strTag.Find(L"unregistPvP") == 0)
                {
                    COutPacket packet(0x61, 0);
                    packet.vfunc_o10_1(2);
                    FUN_140710590(packet);
                }
            }
            else if (arrTag.GetCount() == 2)
            {
                CStringW strArg = arrTag[1];
                if (strTag.Find(L"addMember") == 0)
                    bClose = FUN_1419755a0(strArg);
                else if (strTag.Find(L"createGuild") == 0)
                    bClose = FUN_141974d90(strArg);
                else if (strTag.Find(L"changeNotify") == 0)
                    bClose = FUN_141974df0(strArg);
                else if (strTag.Find(L"changeMemo") == 0)
                    bClose = FUN_141974e70(strArg);
                else if (strTag.Find(L"checkChampionGuild") == 0)
                {
                    CGuildManager::GetInstance()->FUN_1413bc190();
                    bClose = true;
                }
                else if (strTag.Find(L"serachGuildName") == 0)
                {
                    bClose = CGuildManager::GetInstance()->FUN_1413bc860(strArg);
                }
            }
        }
        if (bClose)
            FUN_14151f200();
        return 1;
    }
    return 0;
}

// @0x1419625d0
CString UIGuildDialog::vfunc_1()
{
    return "GuildDialog";
}
MS2_REPLACE_METHOD(0x1419625d0, UIGuildDialog, vfunc_1, 61, 0x471B1AD8);

// @0x141962620
int UIGuildDialog::vfunc_13()
{
    if (UIDialog::vfunc_13() != 0)
        return 1;
    return 0;
}
MS2_REPLACE_METHOD(0x141962620, UIGuildDialog, vfunc_13, 37, 0x68944FB7);

// @0x141968140
void UIGuildDialog::FUN_141968140(CInPacket& packet)
{
    int nMode = packet.vfunc_o8_1();
    switch (nMode)
    {
    case 0x76:
    case 0x77:
        FUN_1419761f0();
        break;
    }
}
MS2_REPLACE_METHOD(0x141968140, UIGuildDialog, FUN_141968140, 94, 0x7485E7B2);

// @0x141969040
void UIGuildDialog::FUN_141969040(const CStringW& strCategory)
{
    FUN_1419698f0();
    if (FUN_1403b3c40(strCategory, L"Join"))
        FUN_141969ee0();
    else if (FUN_1403b3c40(strCategory, L"Create"))
        FUN_141969e80();
    else if (FUN_1403b3c40(strCategory, L"Info"))
        FUN_141969f60();
    else if (FUN_1403b3c40(strCategory, L"Member"))
        FUN_14196a090();
    else if (FUN_1403b3c40(strCategory, L"Skill"))
        FUN_14196a590();
    else if (FUN_140841300(strCategory, "MemberSkill"))
        FUN_14196a640();
    else if (FUN_1403b3c40(strCategory, L"Event"))
        FUN_14196a6f0();
    else if (FUN_1403b3c40(strCategory, L"AcceptMember"))
        FUN_14196a440();
    else if (FUN_1403b3c40(strCategory, L"Manager"))
        FUN_14196a1b0();
    else if (FUN_1403b3c40(strCategory, L"House"))
        FUN_14196b0e0();
    else if (FUN_1403b3c40(strCategory, L"Storage"))
        FUN_14196b160();
    else if (FUN_1403b3c40(strCategory, L"Raid"))
        FUN_14196b1d0();
    else if (FUN_1403b3c40(strCategory, L"ChampionShip"))
        FUN_14196a320();
    else if (FUN_1403b3c40(strCategory, L"ChampionShipHistroy"))
        FUN_14196a3b0();
    FUN_141969290(strCategory);
}

// @0x141969290
void UIGuildDialog::FUN_141969290(const CStringW& strCategory)
{
    if (FUN_1403b3c40(strCategory, L"Join"))
        FUN_141969870(m_joinPage, true);
    else if (FUN_1403b3c40(strCategory, L"Create"))
        FUN_141969870(m_createPage, true);
    else if (FUN_1403b3c40(strCategory, L"Info"))
        FUN_141969870(m_infoPage, true);
    else if (FUN_1403b3c40(strCategory, L"Member"))
        FUN_141969870(m_memberPage, true);
    else if (FUN_1403b3c40(strCategory, L"Skill"))
        FUN_141969870(m_skillPage, true);
    else if (FUN_1403b3c40(strCategory, L"MemberSkill"))
        FUN_141969870(m_skillPage2, true);
    else if (FUN_1403b3c40(strCategory, L"Event"))
        FUN_141969870(m_eventPage, true);
    else if (FUN_1403b3c40(strCategory, L"AcceptMember"))
        FUN_141969870(m_acceptRequestPage, true);
    else if (FUN_1403b3c40(strCategory, L"Manager"))
        FUN_141969870(m_managePage, true);
    else if (FUN_1403b3c40(strCategory, L"House"))
        FUN_141969870(m_housePage, true);
    else if (FUN_1403b3c40(strCategory, L"Storage"))
        FUN_141969870(m_storagePage, true);
    else if (FUN_1403b3c40(strCategory, L"Raid"))
        FUN_141969870(m_raidPage, true);
    else if (FUN_1403b3c40(strCategory, L"ChampionShip"))
        FUN_141969870(m_championshipPage, true);
    else if (FUN_1403b3c40(strCategory, L"ChampionShipHistroy"))
        FUN_141969870(m_pvpHistoryPage, true);
}

// @0x141969870
void UIGuildDialog::FUN_141969870(MS2Ptr<ASUIComponent> spPage, bool b)
{
    if (spPage == 0)
        return;
    spPage->vfunc_4(b);
}
MS2_REPLACE_METHOD(0x141969870, UIGuildDialog, FUN_141969870, 111, 0x402FDDF8);

// @0x1419698f0
void UIGuildDialog::FUN_1419698f0()
{
    FUN_141969870(m_joinPage, false);
    FUN_141969870(m_createPage, false);
    FUN_141969870(m_infoPage, false);
    FUN_141969870(m_memberPage, false);
    FUN_141969870(m_skillPage, false);
    FUN_141969870(m_skillPage2, false);
    FUN_141969870(m_eventPage, false);
    FUN_141969870(m_housePage, false);
    FUN_141969870(m_storagePage, false);
    FUN_141969870(m_raidPage, false);
    FUN_141969870(m_acceptRequestPage, false);
    FUN_141969870(m_managePage, false);
    FUN_141969870(m_championshipPage, false);
    FUN_141969870(m_pvpHistoryPage, false);
}

// @0x141969d10
bool UIGuildDialog::FUN_141969d10(const CString& strName, MS2Ptr<ASUIComponent>& spPage)
{
    if (spPage.get() != 0)
        return false;
    spPage.AssignRaw(new ASUIComponent(strName, 2));
    if (spPage == 0)
        return false;
    m_90->FUN_1422c6900((*spPage).FUN_1422bb890());
    spPage->FUN_1422bffe0(0xa8, 0x50);
    return true;
}

// @0x141969e80
void UIGuildDialog::FUN_141969e80()
{
    FUN_141969d10("guild_create_page", m_createPage);
}
MS2_REPLACE_METHOD(0x141969e80, UIGuildDialog, FUN_141969e80, 83, 0x800329ED);

// @0x141969ee0
void UIGuildDialog::FUN_141969ee0()
{
    if (FUN_141969d10("guild_join_page", m_joinPage))
    {
        CGuildManager::GetInstance()->FUN_1413bc6a0();
        FUN_14196d660();
    }
}
MS2_REPLACE_METHOD(0x141969ee0, UIGuildDialog, FUN_141969ee0, 118, 0x6206FAB2);

// @0x141969f60
void UIGuildDialog::FUN_141969f60()
{
    if (FUN_141969d10("guild_info_page", m_infoPage))
    {
        FUN_14196b620();
        FUN_141976730(FUN_14016a730(CGuildManager::GetInstance()->FUN_1404ccdb0(), 0), 1);
        FUN_14196c860();
        FUN_14196e0a0();
        FUN_14196e2c0();
        FUN_14196b3a0();
    }
}

// @0x14196a090
void UIGuildDialog::FUN_14196a090()
{
    if (FUN_141969d10("guild_member_page", m_memberPage))
    {
        FUN_141975620();
        MS2Ptr<ASDropdownMenu> spSort = m_memberPage->FUN_140bbe700("m_sortDropdown");
        if (spSort.get() != 0)
            spSort->FUN_1422df690(m_nMemberSort);
    }
}

// @0x14196a1b0
void UIGuildDialog::FUN_14196a1b0()
{
    if (FUN_141969d10("guild_manage_page", m_managePage))
    {
        FUN_14196cd30();
        FUN_141975620();
        if (CFeatureManager::GetInstance()->FUN_14036e560())
        {
            MS2Ptr<ASUIComponent> spPopup = m_managePage->FUN_140accfb0<ASUIComponent>("m_editGradePopup");
            if (spPopup.get() != 0)
            {
                MS2Ptr<ASTextInput> spGradeName = spPopup->FUN_140bbe880<ASTextInput>("m_gradeName");
                if (spGradeName.get() != 0)
                    spGradeName->FUN_1422e0d60(0xf);
            }
        }
    }
}

// @0x14196a320
void UIGuildDialog::FUN_14196a320()
{
    if (!CGameRule::GetInstance()->FUN_14047e880())
        return;
    if (FUN_141969d10("guild_champion_ship_page", m_championshipPage))
    {
        FUN_141973610();
        FUN_14196c1d0();
    }
}
MS2_REPLACE_METHOD(0x14196a320, UIGuildDialog, FUN_14196a320, 137, 0xB229D7A4);

// @0x14196a3b0
void UIGuildDialog::FUN_14196a3b0()
{
    if (!CGameRule::GetInstance()->FUN_14047e880())
        return;
    if (FUN_141969d10("guild_pvp_history_page", m_pvpHistoryPage))
        CGuildManager::GetInstance()->FUN_1413bbe80();
}
MS2_REPLACE_METHOD(0x14196a3b0, UIGuildDialog, FUN_14196a3b0, 130, 0x61127482);

// @0x14196a440
void UIGuildDialog::FUN_14196a440()
{
    if (FUN_141969d10("guild_accept_request_page", m_acceptRequestPage))
    {
        FUN_14196b620();
        FUN_14196da70();
        CStringW strCount = FUN_140811740(1000, CGuildManager::GetInstance()->FUN_1404d0020(), CGuildManager::GetInstance()->FUN_1404cd1c0());
        m_acceptRequestPage->Invoke("setMemberCountText", strCount);
    }
}

// @0x14196a590
void UIGuildDialog::FUN_14196a590()
{
    if (FUN_141969d10("guild_skill_page", m_skillPage))
    {
        m_skillPage->Invoke("setType", 0);
        FUN_14196e590();
        FUN_14196e2c0();
    }
}
MS2_REPLACE_METHOD(0x14196a590, UIGuildDialog, FUN_14196a590, 167, 0x7501C1E7);

// @0x14196a640
void UIGuildDialog::FUN_14196a640()
{
    if (FUN_141969d10("guild_skill_page", m_skillPage2))
    {
        m_skillPage2->Invoke("setType", 1);
        FUN_14196f830();
    }
}
MS2_REPLACE_METHOD(0x14196a640, UIGuildDialog, FUN_14196a640, 160, 0x6B802DB1);

// @0x14196b0e0
void UIGuildDialog::FUN_14196b0e0()
{
    if (FUN_141969d10("guild_house_page", m_housePage))
    {
        FUN_141971490();
        FUN_141971ac0();
    }
}
MS2_REPLACE_METHOD(0x14196b0e0, UIGuildDialog, FUN_14196b0e0, 115, 0x335B3DF9);

// @0x14196b160
void UIGuildDialog::FUN_14196b160()
{
    if (FUN_141969d10("guild_storage_page", m_storagePage))
        FUN_141972520();
}
MS2_REPLACE_METHOD(0x14196b160, UIGuildDialog, FUN_14196b160, 105, 0xFFC915DD);

// @0x14196b1d0
void UIGuildDialog::FUN_14196b1d0()
{
    if (FUN_141969d10("guild_raid_page", m_raidPage))
    {
        FUN_141972fc0();
        FUN_141973220();
    }
}
MS2_REPLACE_METHOD(0x14196b1d0, UIGuildDialog, FUN_14196b1d0, 115, 0xF5EDBD8F);

// @0x14196b250
void UIGuildDialog::FUN_14196b250()
{
    if (m_30.IsNull())
        return;
    bool bHasGuild = false;
    if (CGameRule::GetInstance()->FUN_14047e880())
    {
        if (CGuildManager::GetInstance()->FUN_1413b6160() != 0)
            bHasGuild = true;
    }
    m_30->Invoke("setupCategory", bHasGuild);
}

// @0x14196b2f0
void UIGuildDialog::FUN_14196b2f0()
{
    if (m_30.IsNull())
        return;
    if (CGuildManager::GetInstance()->FUN_1413b6160() != 0)
        m_30->Invoke("showGuildDialog", 1);
    else
        m_30->Invoke("showGuildDialog", 0);
}

// @0x14196b3a0
void UIGuildDialog::FUN_14196b3a0()
{
    if (m_30.IsNull())
        return;
    PCBase* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return;
    CStringW strName = pPlayer->vfunc_77();
    m_30->Invoke("setPlayer", strName);
    if (m_infoPage.get() != 0)
    {
        bool bMaster = FUN_14028d780(CGuildManager::GetInstance()->FUN_1404d01b0(strName));
        bool bRight8 = FUN_14028d780(CGuildManager::GetInstance()->FUN_1404d0600(strName, 8));
        bool bRight40 = FUN_14028d780(CGuildManager::GetInstance()->FUN_1404d0600(strName, 0x40));
        m_infoPage->FUN_14197a3e0("setPlayer", bMaster, bRight8, bRight40);
    }
}

// @0x14196c860
void UIGuildDialog::FUN_14196c860()
{
    if (m_30.IsNull())
        return;
    CStringW strGrade;
    CStringW strMark;
    Unk_PayloadPtr<CGuildMember> spMaster = CGuildManager::GetInstance()->FUN_1404d00a0();
    if (spMaster.get() != 0)
    {
        Unk_PayloadPtr<CGuildGrade> spGrade = CGuildManager::GetInstance()->FUN_1404d0860(spMaster->fb4);
        if (spGrade.get() != 0)
            strGrade = FUN_1418f5ab0(0x3d9, spMaster->data.f1c, CStringTable::GetInstance()->FUN_141811980(6, spMaster->data.f18), spGrade->name);
        strMark = FUN_14016a730(FUN_141028be0(spMaster->data.f08, spMaster->data.FUN_1404ca980(), 1, CString("")), 0);
        m_30->Invoke("setMasterInfo", spMaster->data.FUN_1404ca890());
        if (m_infoPage.get() != 0)
            m_infoPage->FUN_1412e80d0("setMasterInfo", spMaster->data.FUN_1404ca890(), strGrade, strMark);
    }
}

// @0x14196cd30
void UIGuildDialog::FUN_14196cd30()
{
    if (m_30.IsNull())
        return;
    ASArray arrGrades(2);
    for (int nGrade = 0; nGrade < 6; nGrade++)
    {
        ASObj objGrade(2);
        Unk_PayloadPtr<CGuildGrade> spGrade = CGuildManager::GetInstance()->FUN_1404d0860(nGrade);
        if (spGrade == 0)
            continue;
        objGrade.FUN_1407cb9c0("gradeRank", nGrade);
        objGrade.FUN_1407cbb20("gradeName", spGrade->name);
        objGrade.FUN_1407cb9c0("gradeAuth", spGrade->permissions);
        arrGrades.FUN_1422bc050(objGrade.FUN_1422bb870());
    }
    m_30->FUN_140bd2cb0("setGradeInfo", arrGrades);
    if (m_managePage.get() != 0)
        m_managePage->FUN_140bd2cb0("setGradeInfo", arrGrades);
}

// @0x14196cf80
void UIGuildDialog::FUN_14196cf80()
{
    if (!m_championshipPage)
        return;
    MS2Ptr<ASTextField> spText = m_championshipPage->FUN_1409b4620("m_belongGuildText");
    if (spText.get() != 0)
    {
        CStringW strGuild = CGuildManager::GetInstance()->FUN_14197df60();
        if (strGuild.GetLength() < 1)
            spText->FUN_1422c4cd0(CStringW(L""));
        else
            spText->FUN_1422c4cd0(FUN_14052bd00(0x3fb, strGuild));
    }
}

// @0x14196e0a0
void UIGuildDialog::FUN_14196e0a0()
{
    if (m_infoPage == 0)
        return;
    int nExp = CGuildManager::GetInstance()->FUN_1404d1a80();
    int nLevel = CGuildXmlData::GetInstance()->FUN_1404d7130(nExp);
    if (nLevel <= 0)
        return;
    int nPrevLevel = nLevel - 1;
    int nPrevExp = CGuildXmlData::GetInstance()->FUN_1404d7200(nPrevLevel);
    int nNextExp = CGuildXmlData::GetInstance()->FUN_1404d7200(nLevel);
    int nRange = nNextExp - nPrevExp;
    int nCur = nExp - nPrevExp;
    float fRate = (float)nCur / (float)nRange;
    if (fRate < 0.0f)
        fRate = 0.0f;
    if (fRate > 1.0f)
        fRate = 1.0f;
    bool bMax = false;
    if (CGuildXmlData::GetInstance()->FUN_1404d72f0() == nLevel)
    {
        bMax = true;
        fRate = 1.0f;
    }
    m_infoPage->FUN_14197a240("setGuildExp", nLevel, bMax, fRate);
}

// @0x14196e230
void UIGuildDialog::FUN_14196e230(bool bEvent)
{
    if (m_30.IsNull() || m_infoPage == 0)
        return;
    m_infoPage->Invoke("setGuildExpEvent", bEvent);
}

// @0x14196e2c0
void UIGuildDialog::FUN_14196e2c0()
{
    if (m_30.IsNull())
        return;
    int nFund = CGuildManager::GetInstance()->FUN_1404d1df0();
    CStringW strFund = FUN_140763e10(nFund);
    int nEventFund = CGuildManager::GetInstance()->FUN_1404d1e40();
    CStringW strEventFund = FUN_140763e10(nEventFund);
    if (m_infoPage.get() != 0)
        m_infoPage->Invoke("setGuildFund", strFund);
    if (m_skillPage.get() != 0)
    {
        FUN_140cfee80((*m_skillPage).FUN_1422bb890(), "m_guildFund", FUN_140763e10(nFund));
        FUN_140cfee80((*m_skillPage).FUN_1422bb890(), "m_guildEventFund", FUN_140763e10(nEventFund));
        m_skillPage->Invoke("onChangedFund", nFund);
    }
}

// @0x141974ba0
bool UIGuildDialog::FUN_141974ba0(int nResult, const CMsgBoxData& box)
{
    if (nResult == 0)
    {
        int nValue = box.FUN_141a02e50(0, 0);
        CGuildManager::GetInstance()->FUN_1413b8fe0(nValue);
    }
    return 1;
}
MS2_REPLACE_METHOD(0x141974ba0, UIGuildDialog, FUN_141974ba0, 68, 0x9294CBCD);

// @0x141974bf0
bool UIGuildDialog::FUN_141974bf0(int nResult, const CMsgBoxData& box)
{
    if (nResult == 0)
    {
        int nValue = box.FUN_141a02e50(0, 0);
        CGuildManager::GetInstance()->FUN_1413b96e0(nValue);
    }
    return 1;
}
MS2_REPLACE_METHOD(0x141974bf0, UIGuildDialog, FUN_141974bf0, 68, 0xA043AA8F);

// @0x141974c40
bool UIGuildDialog::FUN_141974c40(int nResult, const CMsgBoxData& box)
{
    if (nResult == 0)
    {
        int nValue = box.FUN_141a02e50(0, 0);
        CGuildManager::GetInstance()->FUN_1413b9ac0(nValue);
    }
    return 1;
}
MS2_REPLACE_METHOD(0x141974c40, UIGuildDialog, FUN_141974c40, 68, 0xD3A581DE);

// @0x141974c90
bool UIGuildDialog::FUN_141974c90(int nResult, const CMsgBoxData& box)
{
    if (nResult == 0)
    {
        Unk_GuildNpcKind nKind = (Unk_GuildNpcKind)box.FUN_141a02e50(0, 0);
        CGuildManager::GetInstance()->FUN_1413bb000(nKind);
    }
    return 1;
}
MS2_REPLACE_METHOD(0x141974c90, UIGuildDialog, FUN_141974c90, 68, 0x04837610);

// @0x141974ce0
void UIGuildDialog::FUN_141974ce0()
{
    if (m_30.IsNull())
        return;
    FUN_1419260d0("m_webGuideButton", 0);
    FUN_14196b250();
    FUN_14196b2f0();
    FUN_14196c860();
    FUN_14196cd30();
    FUN_141975620();
    FUN_14196b3a0();
    FUN_141973a70();
}

// @0x141974e70
bool UIGuildDialog::FUN_141974e70(const CStringW& strName)
{
    return CGuildManager::GetInstance()->FUN_1413b80d0(strName);
}
MS2_REPLACE_METHOD(0x141974e70, UIGuildDialog, FUN_141974e70, 37, 0xADB6BC2F);

// @0x141974ea0
bool UIGuildDialog::FUN_141974ea0()
{
    CGuildManager::GetInstance()->FUN_1413b7020();
    return 1;
}
MS2_REPLACE_METHOD(0x141974ea0, UIGuildDialog, FUN_141974ea0, 29, 0x50AB2629);

// @0x1419754b0
bool UIGuildDialog::FUN_1419754b0()
{
    Unk_GdBrowser* pBrowser = FUN_140c43790(0x4e6a);
    if (pBrowser == 0)
        return 0;
    pBrowser->FUN_14135ec00(m_strRealtimeRankUrl, 1);
    return 1;
}
MS2_REPLACE_METHOD(0x1419754b0, UIGuildDialog, FUN_1419754b0, 70, 0xDE9AFD4A);

// @0x141975500
bool UIGuildDialog::FUN_141975500()
{
    Unk_GdBrowser* pBrowser = FUN_140c43790(0x4e6a);
    if (pBrowser == 0)
        return 0;
    pBrowser->FUN_14135ec00(m_strRankUrl, 1);
    return 1;
}
MS2_REPLACE_METHOD(0x141975500, UIGuildDialog, FUN_141975500, 70, 0x9F60DC9F);

// @0x141975550
bool UIGuildDialog::FUN_141975550()
{
    Unk_GdBrowser* pBrowser = FUN_140c43790(0x4e6a);
    if (pBrowser == 0)
        return 0;
    pBrowser->FUN_14135ec00(m_strPvpRankUrl, 1);
    return 1;
}
MS2_REPLACE_METHOD(0x141975550, UIGuildDialog, FUN_141975550, 70, 0xE0CE95EF);

// @0x141976380
void UIGuildDialog::FUN_141976380(const Scaleform::GFx::FunctionHandler::Params& params)
{
    void* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return;
    CGuildManager::GetInstance()->FUN_1413bd2e0();
}
MS2_REPLACE_METHOD(0x141976380, UIGuildDialog, FUN_141976380, 60, 0x93A4B944);

// @0x1419763d0
void UIGuildDialog::FUN_1419763d0(const Scaleform::GFx::FunctionHandler::Params& params)
{
    void* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return;
    CGuildManager::GetInstance()->FUN_1413bd3f0();
}
MS2_REPLACE_METHOD(0x1419763d0, UIGuildDialog, FUN_1419763d0, 60, 0xAED62FC8);

// @0x141976980
void UIGuildDialog::FUN_141976980(const CStringW& strMark)
{
    if (vfunc_55() != 0)
        return;
    FUN_141976730(strMark, 0);
}
MS2_REPLACE_METHOD(0x141976980, UIGuildDialog, FUN_141976980, 62, 0xE2E64811);

// @0x14197a3e0 (inline COMDAT: Invoke with three Booleans)
Scaleform::GFx::Value AScript::FUN_14197a3e0(const char* szMethod, bool a1, bool a2, bool a3)
{
    ASArgList args;
    args.FUN_1409b2800(3);
    FUN_1422bcce0(args.FUN_1409b1f70(0), a1);
    FUN_1422bcce0(args.FUN_1409b1f70(1), a2);
    FUN_1422bcce0(args.FUN_1409b1f70(2), a3);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x14197a240 (inline COMDAT: Invoke with an Int, a Boolean and a Number)
Scaleform::GFx::Value AScript::FUN_14197a240(const char* szMethod, int a1, bool a2, float a3)
{
    ASArgList args;
    args.FUN_1409b2800(3);
    FUN_1422bccb0(args.FUN_1409b1f70(0), a1);
    FUN_1422bcce0(args.FUN_1409b1f70(1), a2);
    FUN_1422bcd70(args.FUN_1409b1f70(2), a3);
    return FUN_1422bb8f0(szMethod, args);
}
