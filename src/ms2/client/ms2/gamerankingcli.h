// gamerankingcli.h - the client side of the game ranking service: the ranking rows of the web service
// (GameRankingItem::*), the parsed answers (GameRanking::*), the request (CGameRankingParam), the raw web answer
// (CGameRankingWebResult), the row of the ranking dialog (CGameRankingData) and the cache singleton (CGameRankingCli).
// NOT an original header. Class names are RTTI names (TD of GameRankingItem::*, GameRanking::*, CGameRankingParam,
// CGameRankingWebResult, TPtredDummy<CGameRankingData>, CGameRankingCli); the method and member names are inferred
// (cross-checked against the third-party v2525 headers, whose VAs are the same as ours).
//
// The unit (?\gamerankingcli.cpp, 0x140b287b0-0x140b498e0) holds two original objs: gamerankingcli.cpp (CGameRankingCli,
// CGameRankingData; up to 0x140b31bf0) and the ranking item / answer obj after it. src/ms2/placeholder/gamerankingcli.h
// is the older placeholder that UIGameRankingDialog and CGameApp use; a unit must include only one of the two.
#pragma once

#include <afx.h>
#include <atlcoll.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/tptreddummy.h"
#include "ms2/placeholder/tptrvalue.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/commonfiles/os.h"
#include "ms2/commonfiles/stream.h"

class CGameRankingParam;

// The rows of the web service, one class per ranking board. Read() decodes one row of the answer (CByteBuffer of
// CGameRankingWebResult); strings are length-prefixed UTF-16, dates "yyyy-mm-dd hh:mm:ss" strings.
namespace GameRankingItem {

class IRankItem : public CPtred
{
public:
    virtual void Read(CByteBuffer& s) = 0;                  // 1
};
MS2_CHECK_SIZE(IRankItem, 0x18);

class GuildTrophy : public IRankItem
{
public:
    GuildTrophy();                                          // 0x140b31bf0
    void Read(CByteBuffer& s) override;                     // 0x140b31cf0
    int m_rank;                                             // +0x18
    __int64 m_id;                                           // +0x20
    CStringW m_name;                                        // +0x28
    CStringW m_30;
    CStringW m_38;
    int m_40;
    int m_values[3];                                        // +0x44
};
MS2_CHECK_SIZE(GuildTrophy, 0x50);

class UserTrophy : public IRankItem
{
public:
    UserTrophy();                                           // 0x140b31f60
    void Read(CByteBuffer& s) override;                     // 0x140b32030
    int m_rank;
    __int64 m_id;
    CStringW m_name;
    CStringW m_30;
    int m_38;
    int m_values[3];                                        // +0x3c
};
MS2_CHECK_SIZE(UserTrophy, 0x48);

class DarkStream : public IRankItem
{
public:
    DarkStream();                                           // 0x140b32240
    void Read(CByteBuffer& s) override;                     // 0x140b32310
    int m_rank;
    __int64 m_id;
    CStringW m_name;
    CStringW m_30;
    int m_38;
    int m_3c;
    int m_40;
    __int64 m_time;                                         // +0x48
};
MS2_CHECK_SIZE(DarkStream, 0x50);

class UserPvp : public IRankItem
{
public:
    UserPvp();                                              // 0x140b324e0
    void Read(CByteBuffer& s) override;                     // 0x140b325a0
    int m_rank;
    __int64 m_id;
    CStringW m_name;
    CStringW m_30;
    int m_38;
    int m_3c;
    int m_40;
};
MS2_CHECK_SIZE(UserPvp, 0x48);

class GuildPvp : public IRankItem
{
public:
    GuildPvp();                                             // 0x140b32730
    void Read(CByteBuffer& s) override;                     // 0x140b32810
    int m_rank;
    __int64 m_id;
    CStringW m_name;
    CStringW m_30;
    CStringW m_38;
    int m_40;
    int m_44;
    int m_48;
};
MS2_CHECK_SIZE(GuildPvp, 0x50);

class UgcMapCommendation : public IRankItem
{
public:
    UgcMapCommendation();                                   // 0x140b329f0
    void Read(CByteBuffer& s) override;                     // 0x140b32ad0
    int m_rank;
    __int64 m_id;
    CStringW m_name;
    CStringW m_30;
    int m_38;
    int m_3c;
    __int64 m_40;
    CStringW m_48;
};
MS2_CHECK_SIZE(UgcMapCommendation, 0x50);

class BossKillCount : public IRankItem
{
public:
    BossKillCount();                                        // 0x140b32ce0
    void Read(CByteBuffer& s) override;                     // 0x140b32da0
    int m_rank;
    __int64 m_id;
    CStringW m_name;
    CStringW m_30;
    int m_38;
    int m_3c;
    int m_40;
};
MS2_CHECK_SIZE(BossKillCount, 0x48);

// A party member of the party boards (10 per row, also in CGameRankingData).
class BossKillPartyMember : public CPtred
{
public:
    BossKillPartyMember();                                  // 0x140b32f60
    void Clear();                                           // 0x140b32fd0
    __int64 m_id;                                           // +0x18
    CStringW m_name;                                        // +0x20
    CStringW m_image;                                       // +0x28
    int m_job;                                              // +0x30
    int m_level;                                            // +0x34
    int m_38;
};
MS2_CHECK_SIZE(BossKillPartyMember, 0x40);

class BossKillRecord : public IRankItem
{
public:
    BossKillRecord();                                       // 0x140b33040
    void Read(CByteBuffer& s) override;                     // 0x140b33130
    CStringW LeaderName();                                  // 0x140b33440
    int m_rank;                                             // +0x18
    __int64 m_20;
    int m_28;
    __int64 m_leaderId;                                     // +0x30
    int m_38;
    __int64 m_time;                                         // +0x40
    BossKillPartyMember m_members[10];                      // +0x48
};
MS2_CHECK_SIZE(BossKillRecord, 0x2c8);

class Arcade : public IRankItem
{
public:
    Arcade();                                               // 0x140b33520
    void Read(CByteBuffer& s) override;                     // 0x140b33600
    int m_rank;
    __int64 m_id;
    CStringW m_name;
    CStringW m_30;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
    int m_48;
    __int64 m_time;                                         // +0x50
};
MS2_CHECK_SIZE(Arcade, 0x58);

class BossDamageCount : public IRankItem
{
public:
    BossDamageCount();                                      // 0x140b33840
    void Read(CByteBuffer& s) override;                     // 0x140b33900
    int m_rank;
    __int64 m_id;
    CStringW m_name;
    CStringW m_30;
    int m_38;
    int m_3c;
    int m_40;
};
MS2_CHECK_SIZE(BossDamageCount, 0x48);

class BossDamageDate : public IRankItem
{
public:
    BossDamageDate();                                       // 0x140b33ac0
    void Read(CByteBuffer& s) override;                     // 0x140b33bb0
    CStringW LeaderName();                                  // 0x140b33ec0
    int m_rank;
    __int64 m_20;
    int m_28;
    __int64 m_leaderId;                                     // +0x30
    __int64 m_38;
    __int64 m_time;                                         // +0x40
    BossKillPartyMember m_members[10];                      // +0x48
};
MS2_CHECK_SIZE(BossDamageDate, 0x2c8);

class BossDamageAmount : public IRankItem
{
public:
    BossDamageAmount();                                     // 0x140b33fa0
    void Read(CByteBuffer& s) override;                     // 0x140b340d0
    CStringW LeaderName();                                  // 0x140b34500
    CStringW LeaderImage();                                 // 0x140b345e0
    int m_rank;
    __int64 m_20;
    __int64 m_leaderId;                                     // +0x28
    int m_30;
    __int64 m_38;
    __int64 m_40;
    __int64 m_48;
    __int64 m_50;
    __int64 m_58;
    int m_60;
    __int64 m_time;                                         // +0x68
    BossKillPartyMember m_members[10];                      // +0x70
};
MS2_CHECK_SIZE(BossDamageAmount, 0x2f0);

class BossRumbleCount : public IRankItem
{
public:
    BossRumbleCount();                                      // 0x140b346c0
    void Read(CByteBuffer& s) override;                     // 0x140b34780
    int m_rank;
    __int64 m_id;
    CStringW m_name;
    CStringW m_30;
    int m_38;
    int m_3c;
    int m_40;
};
MS2_CHECK_SIZE(BossRumbleCount, 0x48);

class BossRumbleRecord : public IRankItem
{
public:
    BossRumbleRecord();                                     // 0x140b34940
    void Read(CByteBuffer& s) override;                     // 0x140b34a20
    int m_rank;
    __int64 m_20;
    int m_28;
    __int64 m_30;
    CStringW m_38;
    CStringW m_40;
    int m_48;
    int m_4c;
    int m_50;
    __int64 m_time;                                         // +0x58
};
MS2_CHECK_SIZE(BossRumbleRecord, 0x60);

class Survival : public IRankItem
{
public:
    Survival();                                             // 0x140b34c60
    void Read(CByteBuffer& s) override;                     // 0x140b34d70
    int m_rank;
    __int64 m_id;
    CStringW m_name;
    CStringW m_30;
    int m_38;
    __int64 m_40;
    int m_48;
    int m_4c;
    int m_50;
    int m_54;
    int m_58;
    __int64 m_60;
    __int64 m_time;                                         // +0x68
    int m_70;
};
MS2_CHECK_SIZE(Survival, 0x78);

class WorldChampion : public IRankItem
{
public:
    WorldChampion();                                        // 0x140b35060
    void Read(CByteBuffer& s) override;                     // 0x140b35140
    int m_rank;
    __int64 m_id;
    CStringW m_name;
    CStringW m_30;
    int m_38;
    __int64 m_40;
    __int64 m_48;
    __int64 m_50;
    __int64 m_58;
    int m_60;
};
MS2_CHECK_SIZE(WorldChampion, 0x68);

class BossColosseum : public IRankItem
{
public:
    BossColosseum();                                        // 0x140b35330
    void Read(CByteBuffer& s) override;                     // 0x140b35440
    int m_rank;
    __int64 m_id;
    CStringW m_name;
    CStringW m_30;
    int m_38;
    int m_3c;
    __int64 m_40;
    int m_48;
    int m_4c;
    int m_50;
    __int64 m_58;
    __int64 m_60;
    int m_68;
};
MS2_CHECK_SIZE(BossColosseum, 0x70);

} // namespace GameRankingItem

// A ranking request: the board key plus the owner (guild / character / account) and an optional search name.
class CGameRankingParam : public CPtred
{
public:
    // The 12-byte key of a board: (board type, sub board, season / date). Ordered field by field (CRBMap key).
    struct Key
    {
        Key();                                              // 0x140b356e0
        Key(const CGameRankingParam* pParam);               // 0x140b35710
        ~Key();                                             // 0x140b35780
        void Clear();                                       // 0x140b357b0
        int GetCategory() const;                            // 0x140b357e0 (the board group of the type)
        Key& operator=(const Key& o);                       // 0x140b35820
        bool operator==(const Key& o) const
        {
            if (m_type == o.m_type && m_sub == o.m_sub && m_date == o.m_date)
                return true;
            return false;
        }
        bool operator<(const Key& o) const
        {
            if (m_type != o.m_type)
                return m_type < o.m_type;
            else if (m_sub != o.m_sub)
                return m_sub < o.m_sub;
            else
                return m_date < o.m_date;
        }
        int m_type;                                         // +0x00
        int m_sub;                                          // +0x04
        int m_date;                                         // +0x08
    };

    CGameRankingParam();                                    // 0x140b3dd70
    void Copy(const CGameRankingParam* pParam);             // 0x140b3de40

    Key m_key;                                              // +0x18
    int m_24;
    __int64 m_28;
    __int64 m_30;
    __int64 m_38;
    CStringW m_search;                                      // +0x40
};
MS2_CHECK_SIZE(CGameRankingParam, 0x48);
MS2_CHECK_OFFSET(CGameRankingParam, m_key, 0x18);

// The raw answer of the web service.
class CGameRankingWebResult : public CPtred
{
public:
    CGameRankingWebResult();                                // 0x140b3deb0
    CGameRankingWebResult(int nResult);                     // 0x140b3df20
    int m_result;                                           // +0x18 (0 = success)
    CByteBuffer m_buffer;                                   // +0x20
};
MS2_CHECK_SIZE(CGameRankingWebResult, 0x60);

// The parsed answers of the web service and their pages.
namespace GameRanking {

// One page (10 rows) of a board.
class Page : public CPtred
{
public:
    Page(int nType, int nPage);                             // 0x140b3dae0
    ~Page();                                                // 0x140b3db80
    void Add(int nRank, GameRankingItem::IRankItem* pItem); // 0x140b3dbd0
    MS2Ptr<GameRankingItem::IRankItem> GetItem(int nRank);  // 0x140b3dc40
    MS2Ptr<GameRankingItem::IRankItem> GetFirstItem();      // 0x140b3dcc0
    int Last() { return m_last; }                           // 0x140b2e9a0
    int First() { return m_first; }                         // 0x140b2e9b0
    int Total() { return m_total; }                         // 0x140b2e9c0
    void SetTotal(int nTotal) { m_total = nTotal; }         // 0x140b5f110
    int m_type;                                             // +0x18
    int m_page;                                             // +0x1c
    int m_first;                                            // +0x20
    int m_last;                                             // +0x24
    int m_total;                                            // +0x28
    ATL::CRBMap<int, MS2Ptr<GameRankingItem::IRankItem> > m_items;  // +0x30
};
MS2_CHECK_SIZE(Page, 0x60);

class IResponse : public CPtred
{
public:
    IResponse(unsigned int nType);                          // 0x140b35870
    virtual int Read(CByteBuffer& s);                       // 1 0x140b358d0
    virtual int IsPercent() { return 0; }                   // 2 0x140b4b690
    virtual int GetRank() { return 0; }                     // 3 0x140b49040
    virtual MS2Ptr<Page> Search(CStringW strName) { return 0; }    // 4 0x140b493b0
    virtual MS2Ptr<Page> GetPage(int nPage) { return 0; }          // 5 0x140b49370
    virtual void Merge(CStringW strName, IResponse* pOther) {}      // 6 0x140b45f70
    int IsValid();                                          // 0x140b35970
    unsigned int m_type;                                    // +0x18
    unsigned int m_result;                                  // +0x1c
    __int64 m_time;                                         // +0x20
};
MS2_CHECK_SIZE(IResponse, 0x28);

class MyRank : public IResponse
{
public:
    MyRank(unsigned int nType);                             // 0x140b37240
    int Read(CByteBuffer& s) override;                      // 0x140b37290
    int GetRank() override { return m_rank; }               // 0x140b49050
    int m_rank;                                             // +0x28
};
MS2_CHECK_SIZE(MyRank, 0x30);

class MyRankPercent : public IResponse
{
public:
    MyRankPercent(unsigned int nType);                      // 0x140b37310
    int Read(CByteBuffer& s) override;                      // 0x140b37370
    int IsPercent() override { return m_kind == 2; }        // 0x140b4b6a0
    int GetRank() override { return m_rank; }               // 0x140b49060
    int m_kind;                                             // +0x28
    int m_rank;                                             // +0x2c
};
MS2_CHECK_SIZE(MyRankPercent, 0x30);

// The boards answered as a rank -> row map plus a name -> row map (searchable; all but GuildTrophy key the names
// with CStringElementTraits).
#define MS2_GAMERANKING_LIST(Name, NameTraits)                                                        \
    class Name : public IResponse                                                           \
    {                                                                                       \
    public:                                                                                 \
        Name(unsigned int nType);                                                           \
        int Read(CByteBuffer& s) override;                                                  \
        MS2Ptr<Page> Search(CStringW strName) override;                                     \
        MS2Ptr<Page> GetPage(int nPage) override;                                           \
        void Merge(CStringW strName, IResponse* pOther) override;                           \
        ATL::CRBMap<int, MS2Ptr<GameRankingItem::Name> > m_ranks;          /* +0x28 */      \
        ATL::CRBMap<CStringW, MS2Ptr<GameRankingItem::Name>, NameTraits> m_names;  /* +0x58 */  \
    };                                                                                      \
    MS2_CHECK_SIZE(Name, 0x88)

// The boards answered as a rank -> row map only.
#define MS2_GAMERANKING_RECORD(Name)                                                        \
    class Name : public IResponse                                                           \
    {                                                                                       \
    public:                                                                                 \
        Name(unsigned int nType);                                                           \
        int Read(CByteBuffer& s) override;                                                  \
        MS2Ptr<Page> GetPage(int nPage) override;                                           \
        ATL::CRBMap<int, MS2Ptr<GameRankingItem::Name> > m_ranks;          /* +0x28 */      \
    };                                                                                      \
    MS2_CHECK_SIZE(Name, 0x58)

MS2_GAMERANKING_LIST(GuildTrophy, ATL::CElementTraits<CStringW>);
MS2_GAMERANKING_LIST(UserTrophy, ATL::CStringElementTraits<CStringW>);
MS2_GAMERANKING_LIST(DarkStream, ATL::CStringElementTraits<CStringW>);
MS2_GAMERANKING_LIST(UserPvp, ATL::CStringElementTraits<CStringW>);
MS2_GAMERANKING_LIST(GuildPvp, ATL::CStringElementTraits<CStringW>);
MS2_GAMERANKING_LIST(UgcMapCommendation, ATL::CStringElementTraits<CStringW>);
MS2_GAMERANKING_LIST(BossKillCount, ATL::CStringElementTraits<CStringW>);
MS2_GAMERANKING_RECORD(BossKillRecord);
MS2_GAMERANKING_LIST(Arcade, ATL::CStringElementTraits<CStringW>);
MS2_GAMERANKING_LIST(BossDamageCount, ATL::CStringElementTraits<CStringW>);
MS2_GAMERANKING_RECORD(BossDamageDate);
MS2_GAMERANKING_RECORD(BossDamageAmount);
MS2_GAMERANKING_LIST(BossRumbleCount, ATL::CStringElementTraits<CStringW>);
MS2_GAMERANKING_RECORD(BossRumbleRecord);
MS2_GAMERANKING_LIST(WorldChampion, ATL::CStringElementTraits<CStringW>);
MS2_GAMERANKING_LIST(BossColosseum, ATL::CStringElementTraits<CStringW>);

#undef MS2_GAMERANKING_LIST
#undef MS2_GAMERANKING_RECORD

} // namespace GameRanking

// The row of the ranking dialog, converted from a GameRankingItem row (boxed: TPtrValue<CGameRankingData>).
struct CGameRankingData
{
    CGameRankingData()                                      // 0x140b2d680
    {
        Clear();
        for (int i = 0; i < 10; i++)
            m_members[i].Clear();
    }
    void Clear();                                           // 0x140b319a0
    void Convert(int nType, MS2Ptr<GameRankingItem::IRankItem> spItem);    // 0x140b287b0
    CStringW FormatTime(__int64 nTime);                     // 0x140b2a660
    int m_rank;                                             // +0x00
    int m_category;                                         // +0x04
    __int64 m_point;                                        // +0x08
    int m_10;
    int m_14;
    int m_18;
    __int64 m_20;
    __int64 m_28;
    __int64 m_id;                                           // +0x30
    CStringW m_name;                                        // +0x38
    CStringW m_40;
    CStringW m_48;
    CStringW m_50;
    CStringW m_date;                                        // +0x58
    CStringW m_60;
    CStringW m_time;                                        // +0x68
    CStringW m_70;
    CStringW m_image;                                       // +0x78
    CStringW m_80;
    GameRankingItem::BossKillPartyMember m_members[10];     // +0x88
};
MS2_CHECK_SIZE(CGameRankingData, 0x308);
MS2_CHECK_OFFSET(CGameRankingData, m_name, 0x38);
MS2_CHECK_OFFSET(CGameRankingData, m_members, 0x88);

// The ranking cache: the open requests, the answers per board key and the pages waiting for the dialog.
class CGameRankingCli : public TSingleton<CGameRankingCli>
{
public:
    typedef CGameRankingParam::Key Key;

    CGameRankingCli();                                      // 0x140b2a790
    virtual ~CGameRankingCli();                             // 0x140b2a8a0
    void Update();                                          // 0x140b2a9b0
    void SetPending(MS2Ptr<GameRanking::IResponse> spResponse);         // 0x140b2aa00
    void SetPersonalPending(MS2Ptr<GameRanking::IResponse> spResponse);   // 0x140b2aa80
    void ClearPersonal();                                   // 0x140b2ab00
    void OnPacket(CByteBuffer& packet);                     // 0x140b2ab70
    MS2Ptr<GameRanking::IResponse> QueryPrevious(const Key& key, int bCheckValid);         // 0x140b2ac30
    MS2Ptr<GameRanking::Page> Query(const Key& key, int nPage, int bCheckValid);          // 0x140b2add0
    MS2Ptr<GameRanking::Page> Search(const Key& key, CStringW strName, int bCheckValid);  // 0x140b2af90
    TPtrValue<CGameRankingData> GetData(const Key& key, int nRank, int bCheckValid);       // 0x140b2b1e0
    int Read(const Key& key, int nPage, ATL::CAtlArray<TPtrValue<CGameRankingData> >& rows, CStringW strName,
             int bCheckValid);                              // 0x140b2b440
    void BuildKey(Key& key, int nBoard, int nSub, int nTab, int nDate);           // 0x140b2b870
    void BuildMyRankKey(Key& key, int nBoard, int nSub, int nTab, int nDate);   // 0x140b2bbf0
    void Request(const CGameRankingParam* pParam);          // 0x140b2bf30
    void ReceiveWeb(MS2Ptr<CGameRankingParam> spParam, MS2Ptr<CGameRankingWebResult> spResult);  // 0x140b2bff0
    void ReceiveSearch(MS2Ptr<CGameRankingParam> spParam, MS2Ptr<GameRanking::IResponse> spResponse);  // 0x140b2c340
    void SetResponse(const Key& key, MS2Ptr<GameRanking::IResponse> spResponse);   // 0x140b2c630
    __int64 OwnerId(int nBoard);                            // 0x140b2c6f0
    void Clear();                                           // 0x140b2c7d0
    MS2Ptr<CGameRankingParam> AddParam(const CGameRankingParam* pParam);           // 0x140b2c820
    void RemoveParam(const Key& key);                       // 0x140b2c9d0
    void DeliverRows();                                     // 0x140b2ca40
    void DeliverSearch();                                   // 0x140b2cc10
    void DeliverPersonal();                                  // 0x140b2cd50
    static unsigned int __cdecl RequestWeb(void* pParam);   // 0x140b2ce60 (worker thread)

    CLockCriticalSection m_lock;                            // +0x08
    int m_38;
    ATL::CRBMap<Key, MS2Ptr<CGameRankingParam> > m_params;  // +0x40 the requests in flight
    MS2Ptr<GameRanking::IResponse> m_pending;               // +0x70 the answer waiting for the dialog
    MS2Ptr<GameRanking::IResponse> m_pendingPersonal;            // +0x80
    ATL::CRBMap<Key, MS2Ptr<GameRanking::IResponse> > m_responses;         // +0x90
    ATL::CRBMap<Key, MS2Ptr<GameRanking::IResponse> > m_personal;          // +0xc0 the personal boards
    MS2Ptr<GameRanking::Page> m_searchPage;                 // +0xf0
};
MS2_CHECK_SIZE(CGameRankingCli, 0x100);
MS2_CHECK_OFFSET(CGameRankingCli, m_params, 0x40);
MS2_CHECK_OFFSET(CGameRankingCli, m_responses, 0x90);
MS2_CHECK_OFFSET(CGameRankingCli, m_searchPage, 0xf0);
