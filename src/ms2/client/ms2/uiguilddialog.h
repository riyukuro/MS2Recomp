// uiguilddialog.h - UIGuildDialog (RTTI .?AVUIGuildDialog@@, 0x388 bytes (??_G 0x14197de60 frees 0x388), bases UIDialog
// and UIStatusEventListener at +0x178, UI id 0x4e4f, swf "GuildDialog"): the guild window. A category list opens pages
// (create / join / info / members / manage / championship / pvp history / requests / skills / events / house / storage /
// raid), each an ASUIComponent child created on first use by FUN_141969d10. Owning unit: client\ms2\uiguilddialog.cpp.
// Layout from the ctor 0x141960ce0 / dtor 0x1419610c0 (member ctor / dtor COMDATs named in progress/symbols.tsv) and the
// v2525 reference draft (work/ext/v2525/x/ms2decomp/include/ms2/client/UIGuildDialog.h); member and method names are
// invented from use.
#pragma once
#include <afx.h>
#include <map>
#include <set>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/asbutton.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asuicomponent.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/placeholder/uistatuseventlistener.h"

class CInPacket;
class CMsgBoxData;
class ASButtonBar;
class ItemInfoSlot;
class ASSlot;

class UIGuildDialog : public UIDialog, public UIStatusEventListener
{
public:
    UIGuildDialog();                                            // 0x141960ce0
    virtual ~UIGuildDialog();                                   //  0 0x1419610c0 (??_G 0x14197de60)
    virtual CString vfunc_1();                                  //  1 0x1419625d0 "GuildDialog"
    virtual int vfunc_13();                                     // 13 0x141962620
    virtual void OnLoadComplete();                              // 22 0x141961ab0
    virtual void vfunc_26();                                    // 26 0x1419617e0
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
                                                                // 28 0x1419634e0 (19KB)
    virtual void vfunc_45(Scaleform::GFx::Value* pRetVal, const CString& strMethod, ASData* pArgs);   // 45 0x141962650
    virtual int vfunc_48() { return 0x4e4f; }                   // 48 0x14197e030
    virtual int vfunc_53(void* pCfg);                           // 53 0x141961ec0 load the tab / member sort
    virtual int vfunc_54(void* pCfg);                           // 54 0x141961e40 save the tab / member sort
    virtual int vfunc_65();                                     // 65 0x141961390
    virtual void vfunc_67();                                    // 67 0x1419613c0
    virtual void vfunc_72();                                    // 72 0x1419614e0 request expiry, mark push
    virtual int OnMessage(UISwfEntity* pSender, UIMsg* pMsg);   // IMessageListener 0 0x1419620b0
    virtual void vfunc_oa0_11(void* a1);                        // UIStatusEventListener 11 0x141976a60 (the guild fund)


    MS2Ptr<ASButtonBar> FUN_140c02870(const CString& strName);  // 0x140c02870 bind a button bar child ("m_category")
    void FUN_141968140(CInPacket& packet);                      // guild packet 0x8a: refresh the buttons on 0x76 / 0x77
    int FUN_1419681b0(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // the join / request pages' AS callbacks (vfunc_28)
    void FUN_141969040(const CStringW& strCategory);            // open a category's page and show it
    void FUN_141969290(const CStringW& strCategory);            // show a category's page
    void FUN_141969870(MS2Ptr<ASUIComponent> spPage, bool b);
    void FUN_1419698f0();                                       // hide every page   // a page's slot 4
    bool FUN_141969d10(const CString& strName, MS2Ptr<ASUIComponent>& spPage);   // bind (create) a page
    void FUN_141969e80();                                       // open "guild_create_page"
    void FUN_141969ee0();                                       // open "guild_join_page"
    void FUN_141969f60();                                       // open "guild_info_page"
    void FUN_14196a090();                                       // open "guild_member_page"
    void FUN_14196a1b0();                                       // open "guild_manage_page"
    void FUN_14196a320();                                       // open "guild_champion_ship_page"
    void FUN_14196a3b0();                                       // open "guild_pvp_history_page"
    void FUN_14196a440();                                       // open "guild_accept_request_page"
    void FUN_14196a590();                                       // open "guild_skill_page" (type 0)
    void FUN_14196a640();                                       // open "guild_skill_page" (type 1)
    void CreateEventPage();                                     // 0x14196a6f0 open "UIGuildDialog_EventPage" (name: its GfxError string)
    void FUN_14196b0e0();                                       // open "guild_house_page"
    void FUN_14196b160();                                       // open "guild_storage_page"
    void FUN_14196b1d0();                                       // open "guild_raid_page"
    void FUN_14196b250();
    void FUN_14196b2f0();
    void FUN_14196b3a0();
    void FUN_14196b620();
    void FUN_14196c1d0();
    void FUN_14196c860();
    void FUN_14196cd30();                                       // "setGradeInfo"
    void FUN_14196cf80();                                       // the championship page's guild text
    void FUN_14196d0c0(int nPage);                              // "buildSearchGuild" (9 per page)
    void FUN_14196d660();                                       // "buildSearchMy": my join requests
    void FUN_14196da70();                                       // the request member page
    void FUN_14196e0a0();                                       // "setGuildExp"
    void FUN_14196e230(bool bEvent);                            // "setGuildExpEvent"
    void FUN_14196e2c0();                                       // "setGuildFund"
    void FUN_14196e590();
    void FUN_14196f830();
    void FUN_141970f00();                                       // the guild vs-game event panel
    void FUN_141971490();                                       // the house page
    void FUN_141971ac0();
    void FUN_141972520();                                       // the storage page
    void FUN_1419729d0();                                       // the storage history (last 7 days)
    void FUN_141972fc0();                                       // the raid score
    void FUN_141973220();                                       // the raid history
    void FUN_141973610();                                       // the championship info
    void FUN_141973a70();                                       // show the attendance mark
    void FUN_141973b20(const CStringW& strName);                // refresh a member's row
    void FUN_141973df0(const CStringW& strName);                // "removeMember"
    void FUN_141973fd0(int nGrade);                             // grade renamed: refresh its members
    void FUN_141974120(const CString& strCode);                 // set the mark from a code
    void FUN_141974190(const CStringW& strName);                // "setGuildName"
    void FUN_141974240();                                       // the pvp history page
    MS2Ptr<ASMovieClip> FUN_140ba7930(const CString& strName);
    void FUN_141974640();                                       // the pvp season history
    void FUN_141974930();                                       // confirm the championship guild
    bool FUN_141974ba0(int nResult, const CMsgBoxData& box);    // confirm boxes: forward the box's number to the manager
    bool FUN_141974bf0(int nResult, const CMsgBoxData& box);
    bool FUN_141974c40(int nResult, const CMsgBoxData& box);
    bool FUN_141974c90(int nResult, const CMsgBoxData& box);
    void FUN_141974ce0();                                       // bind the web guide button and build the static pages
    bool FUN_141974d90(const CStringW& strName);                // "createGuild"
    bool FUN_141974df0(const CStringW& strText);                // "changeNotify"
    bool FUN_141974e70(const CStringW& strName);                // request by name ("changeMemo")
    bool FUN_141974ea0();                                       // request a refresh
    bool FUN_1419754b0();                                       // open the realtime rank page
    bool FUN_141975500();                                       // open the rank page
    bool FUN_141975550();                                       // open the pvp rank page
    bool FUN_141974ed0();                                       // is the guild mail filled in
    bool FUN_1419751e0();                                       // "sendMail"
    bool FUN_1419755a0(const CStringW& strName);                // "addMember"
    void FUN_141975620();
    void FUN_1419758a0();
    void FUN_141975c80();
    void FUN_1419760c0();
    void FUN_1419761f0();                                       // update the buttons
    void FUN_141976380(const Scaleform::GFx::FunctionHandler::Params& params);
    void FUN_1419763d0(const Scaleform::GFx::FunctionHandler::Params& params);
    void FUN_141976420(ItemInfoSlot& slot, ASSlot& asSlot);     // a storage slot's count
    bool FUN_1419764a0();                                       // is a guild exp event running
    void FUN_1419764f0(unsigned __int64 nGuildId, const CString& strCode);   // a guild's mark arrived
    void FUN_141976730(const CStringW& strMark, int n);         // "setGuildMark"
    void FUN_1419769d0();                                       // set the own guild's mark
    void FUN_141970900();
    void FUN_141976980(const CStringW& strMark);                // set the mark unless the dialog is closed
    static UINT RequestHistoryGuildMarkToWeb(LPVOID pParam);    // thread: the pvp history guilds' marks from the web
    void FUN_141976e00(CString strXml);                         // the web answer: store the guilds' marks

private:
    MS2_LAYOUT_FRIEND;
    CStringW m_strName;                                         // +0x180
    CStringW m_strDesc;                                         // +0x188
    CString m_strRankUrl;                                       // +0x190 "maview:/Rank/Guild"
    CString m_strRealtimeRankUrl;                               // +0x198
    CString m_strPvpRankUrl;                                    // +0x1a0
    int m_nTab;                                                 // +0x1a8 "lastTabIndex"
    int m_nMemberSort;                                          // +0x1ac "lastMemberSortindex"
    std::set<int> m_1b0;                                        // +0x1b0
    std::set<int> m_1c0;                                        // +0x1c0
    std::multimap<unsigned int, unsigned int> m_requests;       // +0x1d0 expiry time -> event id
    bool m_bMarksPending;                                       // +0x1e0
    CLockCriticalSection m_lock;                                // +0x1e8
    CString m_strMarkRequestIds;                                // +0x218 guild ids of the mark web request
    std::map<unsigned __int64, CString> m_marks;                // +0x220 guild id -> mark image (v2525: pair forwarding ctor 0x141978e60)
    bool m_bLoading;                                            // +0x230
    int m_nSearchPage;                                          // +0x234
    int m_nAcceptPage;                                          // +0x238
    CString m_strStorageName;                                   // +0x240 "GuildDialog_storageItems"
    MS2Ptr<ASUIComponent> m_createPage;                         // +0x248
    MS2Ptr<ASUIComponent> m_joinPage;                           // +0x258
    MS2Ptr<ASUIComponent> m_infoPage;                           // +0x268
    MS2Ptr<ASUIComponent> m_memberPage;                         // +0x278
    MS2Ptr<ASUIComponent> m_managePage;                         // +0x288
    MS2Ptr<ASUIComponent> m_championshipPage;                   // +0x298
    MS2Ptr<ASUIComponent> m_pvpHistoryPage;                     // +0x2a8
    MS2Ptr<ASUIComponent> m_acceptRequestPage;                  // +0x2b8
    MS2Ptr<ASUIComponent> m_page2c8;                            // +0x2c8
    MS2Ptr<ASUIComponent> m_skillPage;                          // +0x2d8
    MS2Ptr<ASUIComponent> m_skillPage2;                         // +0x2e8
    MS2Ptr<ASUIComponent> m_eventPage;                          // +0x2f8
    MS2Ptr<ASUIComponent> m_housePage;                          // +0x308
    MS2Ptr<ASUIComponent> m_storagePage;                        // +0x318
    MS2Ptr<ASUIComponent> m_raidPage;                           // +0x328
    MS2Ptr<ASMovieClip> m_eventVsGame;                          // +0x338 "m_guildEventVsGame"
    MS2Ptr<ASLoader> m_eventLoader;                             // +0x348
    MS2Ptr<ASMovieClip> m_eventImageArea;                       // +0x358 "m_guildEventImageArea"
    MS2Ptr<ASButton> m_button368;                               // +0x368
    MS2Ptr<ASButton> m_button378;                               // +0x378
};
MS2_CHECK_SIZE(UIGuildDialog, 0x388);
MS2_CHECK_OFFSET(UIGuildDialog, m_strName, 0x180);
MS2_CHECK_OFFSET(UIGuildDialog, m_nTab, 0x1a8);
MS2_CHECK_OFFSET(UIGuildDialog, m_requests, 0x1d0);
MS2_CHECK_OFFSET(UIGuildDialog, m_lock, 0x1e8);
MS2_CHECK_OFFSET(UIGuildDialog, m_marks, 0x220);
MS2_CHECK_OFFSET(UIGuildDialog, m_strStorageName, 0x240);
MS2_CHECK_OFFSET(UIGuildDialog, m_raidPage, 0x328);
MS2_CHECK_OFFSET(UIGuildDialog, m_button378, 0x378);
