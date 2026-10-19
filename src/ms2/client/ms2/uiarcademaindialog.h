// uiarcademaindialog.h - UIArcadeMainDialog (RTTI .?AVUIArcadeMainDialog@@, 0x2e8 bytes: UIDialog + the game buttons and the
// ranking board), the arcade minigame lobby ("ArcadeMainDialog", UI type 0x4efd). Recovered from MapleStory2.exe KMS2_DEV
// x64 (2022-04-13); the unit is `?\uiarcademaindialog.cpp` (0x140ef5640-0x140f004b0 .text$mn, dir client\ms2). Header/unit
// name assumed. Member names are invented from use.
//
// Bases: UIDialog (src/ms2/client/ms2/uidialog.h) with the IMessageListener at +0x18. Overridden slots: 1 (movie name),
// 20 (OnLoadInit), 22 (OnLoadComplete: bind the nine game buttons + the ranking view), 26 (release the bound children),
// 48 (UI type 0x4efd), 72 (per-frame poll of the ranking worker).
//
// The ranking board is fetched on a worker thread (RequestInGameRanking through the game ranking service, or RequestWebRanking
// through the "api:/rank/arcade" url) which hands the answer back under m_resultLock; vfunc_72 picks it up and applies it.
#pragma once

#include <afx.h>
#include <atlcoll.h>

#include <map>
#include <utility>
#include <vector>

#include "ms2/ms2layout.h"
#include "ms2/client/ms2/uidialog.h"
#include "ms2/placeholder/carcadedatatable.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/placeholder/gamerankingcli.h"
#include "ms2/placeholder/tptrvalue.h"

class CInPacket;
class CMsgBoxData;
class Unk_140acd6e0;
class ASMovieClip;

class UIArcadeMainDialog : public UIDialog
{
public:
    // The cached ranking of one arcade game: the ten best (score, name) rows.
    struct RankPage { std::pair<int, CStringW> m_rows[10]; };
    typedef TPtrValue<ATL::CAtlArray<Unk_RankDataPtr> > RankingList;                // the rows of one board
    typedef std::vector<std::pair<int, RankingList> > RankingResults;               // arcade id -> rows, from the worker

    UIArcadeMainDialog();                                           // 0x140ef5640
    virtual ~UIArcadeMainDialog();                                  //  0 0x140ef58d0 (??_G 0x140efd300)
    virtual CString vfunc_1();                                      //  1 0x140ef5af0 "ArcadeMainDialog"
    virtual void OnLoadInit();                                      // 20 0x140ef5b40
    virtual void OnLoadComplete();                                  // 22 0x140ef5b60
    virtual void vfunc_26();                                        // 26 0x140ef6750
    virtual int vfunc_48();                                         // 48 0x140efd620: 0x4efd
    virtual void vfunc_72();                                        // 72 0x140ef65f0 take the finished ranking

    void FUN_140ef67f0();                                           // 0x140ef67f0 take the in-game ranking result
    void FUN_140ef6920();                                           // 0x140ef6920 forget the game list answer
    void FUN_140ef6960(const Scaleform::GFx::FunctionHandler::Params& params);   // a game button was clicked
    void FUN_140ef6a60(const Scaleform::GFx::FunctionHandler::Params& params);   // the enter button was clicked
    void FUN_140ef6dd0();                                           // 0x140ef6dd0 merge the npc records into the ranking
    void FUN_140ef7230();                                           // 0x140ef7230 fill the ranking view
    bool FUN_140ef7ab0(int nResult, const CMsgBoxData& box);        // 0x140ef7ab0 the map-change confirm box result
    bool FUN_140ef7b00(int nArcadeId);                              // 0x140ef7b00 request to enter the game
    void FUN_140ef7d30(int nMode, CInPacket& packet);               // 0x140ef7d30 mode 9: the last played game and the scores
    void FUN_140ef7e70();                                           // 0x140ef7e70 clear the ranking
    void FUN_140ef7ea0();                                           // 0x140ef7ea0 start the ranking request
    void FUN_140ef7fc0(CStringW strResponse);                       // 0x140ef7fc0 the worker stores the web answer
    void FUN_140ef8040(int nArcadeId, RankingList list);            // 0x140ef8040 the worker stores one board
    void FUN_140ef80f0(CStringW strXml);                            // 0x140ef80f0 parse the web ranking
    void FUN_140ef8380(RankingResults results);                     // 0x140ef8380 apply the in-game ranking
    MS2Ptr<ASMovieClip> FUN_140ba7930(const CString& strName);      // 0x140ba7930 bind a movie clip child
    MS2Ptr<Unk_140acd6e0> FUN_140bb4b10(const CString& strName);    // 0x140bb4b10 bind a button child
    static unsigned OnRequestRanking(void* pArg);                   // 0x140ef85b0 worker: the web ranking
    static unsigned OnRequestRankingFromInGameRanking(void* pArg);  // 0x140ef87e0 worker: the in-game ranking service

private:
    MS2_LAYOUT_FRIEND;
    MS2Ptr<Unk_140acd6e0> m_buttons[9];                             // +0x178 "m_game1".."m_game9"
    MS2Ptr<ASMovieClip> m_rankView;                                 // +0x208 "m_rankingInfo"
    MS2Ptr<ASMovieClip> m_emptyView;                                // +0x218 "m_rankingEmpty"
    MS2Ptr<Unk_140acd6e0> m_enter;                                  // +0x228 "m_enter"
    std::vector<MS2SvrPtr<CArcadeMainData> > m_games;               // +0x238 the games shown on the buttons
    CStringW m_bannerPath;                                          // +0x250 "./Data/Resource/Image/Map/Arcade/"
    int m_nSelected;                                                // +0x258 the selected button (-1 none)
    std::map<int, RankPage> m_ranks;                                // +0x260 by arcade id
    std::map<int, int> m_scores;                                    // +0x270 own best score by arcade id
    int m_nRegion;                                                  // +0x280 the region the scores belong to
    unsigned m_nRequestTick;                                        // +0x284 last request time
    CString m_strUrl;                                               // +0x288 "api:/rank/arcade"
    CWinThread* m_pWorker;                                          // +0x290 the ranking thread
    CStringW m_strResponse;                                         // +0x298 the web answer
    RankingResults m_results;                                       // +0x2a0 the in-game answer
    CLockCriticalSection m_resultLock;                              // +0x2b8
};
MS2_CHECK_SIZE(UIArcadeMainDialog, 0x2e8);
MS2_CHECK_OFFSET(UIArcadeMainDialog, m_rankView, 0x208);
MS2_CHECK_OFFSET(UIArcadeMainDialog, m_games, 0x238);
MS2_CHECK_OFFSET(UIArcadeMainDialog, m_ranks, 0x260);
MS2_CHECK_OFFSET(UIArcadeMainDialog, m_strUrl, 0x288);
MS2_CHECK_OFFSET(UIArcadeMainDialog, m_results, 0x2a0);
MS2_CHECK_OFFSET(UIArcadeMainDialog, m_resultLock, 0x2b8);
