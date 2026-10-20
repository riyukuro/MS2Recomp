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
class Unk_GdWorld { public: void* FUN_141bd0cc0(); };           // the local player
Unk_GdWorld* FUN_1403ed2d0();
void FUN_1408741a0(void* pCfg, const char* szSection, const char* szKey, int* pValue);   // read an int setting
void FUN_140874440(void* pCfg, const char* szSection, const char* szKey, int nValue, bool bFlush);   // write an int setting
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

// @0x141969870
void UIGuildDialog::FUN_141969870(MS2Ptr<ASUIComponent> spPage, bool b)
{
    if (spPage == 0)
        return;
    spPage->vfunc_4(b);
}
MS2_REPLACE_METHOD(0x141969870, UIGuildDialog, FUN_141969870, 111, 0x402FDDF8);

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
void UIGuildDialog::FUN_141974e70(const CStringW& strName)
{
    CGuildManager::GetInstance()->FUN_1413b80d0(strName);
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
