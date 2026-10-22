// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). See gamerankingcli.h.
// MS2-UNIT: ?\gamerankingcli.cpp
// MS2-RANGE: 0x140b287b0-0x140b498e0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
// MS2-PIN: ??8Key@CGameRankingParam@@QEBA_NAEBU01@@Z 0x140b2e100
// MS2-PIN: ??4?$MS2Ptr@VUgcMapCommendation@GameRankingItem@@@@QEAAAEAV0@AEBV0@@Z 0x140b447f0
// MS2-PIN: ??4?$MS2Ptr@VUserPvp@GameRankingItem@@@@QEAAAEAV0@AEBV0@@Z 0x140b44830
// MS2-PIN: ??4?$MS2Ptr@VUserTrophy@GameRankingItem@@@@QEAAAEAV0@AEBV0@@Z 0x140b44870
// MS2-PIN: ??4?$MS2Ptr@VWorldChampion@GameRankingItem@@@@QEAAAEAV0@AEBV0@@Z 0x140b448b0
//
// Two original objs: gamerankingcli.cpp (CGameRankingData, CGameRankingCli; COMDATs up to its memmove_s at
// 0x140b31ad0) and the ranking item / answer obj from 0x140b31bf0 (GameRankingItem::*, GameRanking::*,
// CGameRankingParam, CGameRankingWebResult). The answer obj's COMDAT tail continues past 0x140b498e0 (unit_140b498e0).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\gamerankingcli.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "gamerankingcli.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/mstime.h"
#include "ms2/placeholder/csoapclient.h"
#include "ms2/commonfiles/timeutil.h"
#include "ms2/commonfiles/dungeonroom.h"
#include "ms2/client/ms2/uiobject.h"
#include "ms2/client/ms2/uidialog.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- out-of-unit callees and data (bound to the exe by their FUN_<va> / DAT_<va> names) ----

extern unsigned DAT_143ab2830;                      // the own character's type
extern __int64 DAT_143ab2820;                       // the own account id
extern __int64 DAT_143ab2828;                       // the own character id
extern int DAT_1439f4d94;                           // lifetime of a personal / daily board answer (seconds)
extern int DAT_1439f4d98;                           // lifetime of the other board answers (minutes)

class Unk_GrSettings { public: bool FUN_14036d570(int nFeature); };         // the content switches
Unk_GrSettings* FUN_140166410();
class Unk_GrBanFlags { public: int FUN_1402c4c90(int nFlag); };             // blocked-action flag set
struct Unk_GrConfig { char m_pad[8]; Unk_GrBanFlags m_8; };
Unk_GrConfig* FUN_14025e7b0();                                              // global client config
void FUN_141b6de20();                                                       // thread start-up
class Unk_UtilLogScope
{
public:
    Unk_UtilLogScope(CStringA kTag);                            // 0x141b721f0
    ~Unk_UtilLogScope();                                        // 0x141b722b0
private:
    DWORD m_dwThread;
    CStringA m_kTag;
};
class Unk_GrUIManager { public: MS2Ptr<UIObject> FUN_141adcea0(int nClass); };
Unk_GrUIManager* FUN_1403ed2b0();                                           // the UI service
class Unk_GrGuildInfo { public: __int64 FUN_1404ccbd0(); };                // the guild id
class Unk_GrGuildManager { public: int FUN_1413b6160(); char m_pad[8]; Unk_GrGuildInfo m_8; };
Unk_GrGuildManager* FUN_1403ed290();                                        // the guild manager (+8: the own guild)
class Unk_GrStrings { public: CStringW FUN_141811980(int nTable, int nId); };
Unk_GrStrings* FUN_1401a9d70();                                             // the string tables
DungeonRoomTable* FUN_14031c2a0();
CStringW FUN_140811740(int nId, const int& n0, const int& n1);              // a string table text with two numbers
CStringW FUN_14083bdc0(const CMsTime& t, bool bSeconds, CStringW strSep, CStringW strSep2);    // date + time text
CString FUN_14016a600(const wchar_t* psz, int nCodePage);                   // narrows a string
CString FUN_141028be0(__int64 nId, const CString& strName, int bNoDownload, CString strUrl);   // profile image path
CString FUN_141029590(unsigned __int64 nGuildId, const CString& strName, const CString& strUrl, CString strDefault);
                                                                            // guild mark path

// The ranking dialog (only the members the cache calls).
class UIGameRankingDialog : public UIDialog
{
public:
    void FUN_140e31910(int nFlag);                                          // push the rank info
    void FUN_140e32f30(int nPush, int nForce, CStringW strSearch);          // request the page
    void FUN_140e34ce0(int nPage, int nPages);                              // "setButtonPage"
    void FUN_140e34eb0(MS2Ptr<GameRanking::Page> spPage);                   // a page arrived
};

// Helpers of the answer obj (defined below).
int FUN_140b3e210(CGameRankingParam::Key key);
int FUN_140b3e700(int nType);
int FUN_140b3df90(__int64 nTime, int nMonths);
int FUN_140b3e150();
MS2Ptr<GameRanking::IResponse> FUN_140b35ad0(int nType);
CStringW FUN_140b3f4e0(CByteBuffer& s);
__int64 FUN_140b3f610(CByteBuffer& s);

// ---- CGameRankingData ----

// MS2-FUNCTIONAL: the exe builds the by-value CString("") argument address before strUrl; frame/temp order differs
// @0x140b287b0
void CGameRankingData::Convert(int nType, MS2Ptr<GameRankingItem::IRankItem> spItem)
{
    Clear();
    CGameRankingParam::Key key;
    key.m_type = nType;
    m_category = FUN_140b3e210(key);
    if (nType >= 0xb && nType <= 0xe) {
        if (GameRankingItem::GuildTrophy* p = static_cast<GameRankingItem::GuildTrophy*>(spItem.get())) {
            m_20 = p->m_id;
            m_rank = p->m_rank;
            m_point = p->m_40;
            m_48 = p->m_name;
            m_50 = p->m_38;
            m_image = p->m_30;
            CString strUrl("");
            FUN_141029590(p->m_id, FUN_14016a600(p->m_30, 0), strUrl, CString(""));
        }
    }
    else if (nType >= 0x15 && nType <= 0x18) {
        if (GameRankingItem::UserTrophy* p = static_cast<GameRankingItem::UserTrophy*>(spItem.get())) {
            m_id = p->m_id;
            m_rank = p->m_rank;
            m_point = p->m_38;
            m_name = p->m_name;
            m_image = p->m_30;
            FUN_141028be0(p->m_id, FUN_14016a600(p->m_30, 0), 1, CString(""));
        }
    }
    else if (nType >= 0x1f && nType <= 0x22) {
        if (GameRankingItem::DarkStream* p = static_cast<GameRankingItem::DarkStream*>(spItem.get())) {
            m_id = p->m_id;
            m_rank = p->m_rank;
            m_point = p->m_40;
            m_name = p->m_name;
            m_date = FormatTime(p->m_time);
            m_image = p->m_30;
            FUN_141028be0(p->m_id, FUN_14016a600(p->m_30, 0), 1, CString(""));
        }
    }
    else if (nType >= 0x29 && nType <= 0x2c) {
        if (GameRankingItem::UserPvp* p = static_cast<GameRankingItem::UserPvp*>(spItem.get())) {
            m_id = p->m_id;
            m_rank = p->m_rank;
            m_point = p->m_38;
            m_name = p->m_name;
            m_image = p->m_30;
            FUN_141028be0(p->m_id, FUN_14016a600(p->m_30, 0), 1, CString(""));
        }
    }
    else if (nType >= 0x33 && nType <= 0x36) {
        if (GameRankingItem::GuildPvp* p = static_cast<GameRankingItem::GuildPvp*>(spItem.get())) {
            m_20 = p->m_id;
            m_rank = p->m_rank;
            m_point = p->m_40;
            m_48 = p->m_name;
            m_50 = p->m_38;
            m_70 = FUN_1401a9d70()->FUN_141811980(0x2d, p->m_44);
            m_image = p->m_30;
            CString strUrl("");
            FUN_141029590(p->m_id, FUN_14016a600(p->m_30, 0), strUrl, CString(""));
        }
    }
    else if (nType >= 0x3d && nType <= 0x40) {
        if (GameRankingItem::UgcMapCommendation* p = static_cast<GameRankingItem::UgcMapCommendation*>(spItem.get())) {
            m_id = p->m_id;
            m_rank = p->m_rank;
            m_point = p->m_38;
            m_name = p->m_name;
            m_80 = p->m_48;
            m_image = p->m_30;
            m_28 = p->m_40;
            FUN_141028be0(p->m_id, FUN_14016a600(p->m_30, 0), 1, CString(""));
        }
    }
    else if (nType >= 0x47 && nType <= 0x48) {
        if (GameRankingItem::BossKillCount* p = static_cast<GameRankingItem::BossKillCount*>(spItem.get())) {
            m_id = p->m_id;
            m_rank = p->m_rank;
            m_point = p->m_3c;
            m_name = p->m_name;
            m_image = p->m_30;
            FUN_141028be0(p->m_id, FUN_14016a600(p->m_30, 0), 1, CString(""));
        }
    }
    else if (nType >= 0x51 && nType <= 0x5b) {
        if (GameRankingItem::BossKillRecord* p = static_cast<GameRankingItem::BossKillRecord*>(spItem.get())) {
            m_id = p->m_leaderId;
            m_rank = p->m_rank;
            m_40 = p->LeaderName();
            m_date = FormatTime(p->m_time);
            int nSecond = p->m_38 % 60;
            int nMinute = p->m_38 / 60;
            m_time = FUN_140811740(0x97e, nMinute, nSecond);
            for (int i = 0; i < 10; i++)
                m_members[i] = p->m_members[i];
        }
    }
    else if (nType >= 0x65 && nType <= 0x68) {
        if (GameRankingItem::Arcade* p = static_cast<GameRankingItem::Arcade*>(spItem.get())) {
            m_id = p->m_id;
            m_rank = p->m_rank;
            m_point = p->m_48;
            m_name = p->m_name;
            m_image = p->m_30;
            FUN_141028be0(p->m_id, FUN_14016a600(p->m_30, 0), 1, CString(""));
        }
    }
    else if (nType >= 0x6f && nType <= 0x70) {
        if (GameRankingItem::BossDamageCount* p = static_cast<GameRankingItem::BossDamageCount*>(spItem.get())) {
            m_id = p->m_id;
            m_rank = p->m_rank;
            m_point = p->m_3c;
            m_name = p->m_name;
            m_image = p->m_30;
            FUN_141028be0(p->m_id, FUN_14016a600(p->m_30, 0), 1, CString(""));
        }
    }
    else if (nType == 0x79) {
        if (GameRankingItem::BossDamageDate* p = static_cast<GameRankingItem::BossDamageDate*>(spItem.get())) {
            m_id = p->m_leaderId;
            m_rank = p->m_rank;
            m_40 = p->LeaderName();
            m_date = FormatTime(p->m_time);
            m_point = p->m_38;
            for (int i = 0; i < 10; i++)
                m_members[i] = p->m_members[i];
        }
    }
    else if (nType >= 0x83 && nType <= 0x84) {
        if (GameRankingItem::BossDamageAmount* p = static_cast<GameRankingItem::BossDamageAmount*>(spItem.get())) {
            m_id = p->m_leaderId;
            m_rank = p->m_rank;
            m_40 = p->LeaderName();
            m_date = FormatTime(p->m_time);
            m_point = p->m_50;
            m_10 = p->m_60;
            m_image = p->LeaderImage();
            FUN_141028be0(p->m_leaderId, FUN_14016a600(m_image, 0), 1, CString(""));
            for (int i = 0; i < 10; i++)
                m_members[i] = p->m_members[i];
        }
    }
    else if (nType >= 0x8d && nType <= 0x8e) {
        if (GameRankingItem::BossRumbleCount* p = static_cast<GameRankingItem::BossRumbleCount*>(spItem.get())) {
            m_id = p->m_id;
            m_rank = p->m_rank;
            m_point = p->m_3c;
            m_name = p->m_name;
            m_image = p->m_30;
            FUN_141028be0(p->m_id, FUN_14016a600(p->m_30, 0), 1, CString(""));
        }
    }
    else if (nType >= 0x97 && nType <= 0xa2) {
        if (GameRankingItem::BossRumbleRecord* p = static_cast<GameRankingItem::BossRumbleRecord*>(spItem.get())) {
            m_id = p->m_30;
            m_rank = p->m_rank;
            m_40 = p->m_38;
            m_date = FormatTime(p->m_time);
            int nSecond = p->m_50 % 60;
            int nMinute = p->m_50 / 60;
            m_time = FUN_140811740(0x97e, nMinute, nSecond);
            m_image = p->m_40;
            FUN_141028be0(p->m_30, FUN_14016a600(p->m_40, 0), 1, CString(""));
            m_members[0].m_name = p->m_38;
            m_members[0].m_level = p->m_4c;
            m_members[0].m_job = p->m_48;
        }
    }
    else if (nType >= 0xb5 && nType <= 0xb8) {
        if (GameRankingItem::WorldChampion* p = static_cast<GameRankingItem::WorldChampion*>(spItem.get())) {
            m_id = p->m_id;
            m_rank = p->m_rank;
            m_point = p->m_48;
            m_name = p->m_name;
            m_image = p->m_30;
            FUN_141028be0(p->m_id, FUN_14016a600(p->m_30, 0), 1, CString(""));
        }
    }
    else if (nType >= 0xc9 && nType <= 0xcc) {
        if (GameRankingItem::BossColosseum* p = static_cast<GameRankingItem::BossColosseum*>(spItem.get())) {
            m_id = p->m_id;
            m_rank = p->m_rank;
            m_point = p->m_48;
            int nSecond = p->m_4c % 60;
            int nMinute = p->m_4c / 60;
            m_time = FUN_140811740(0x97e, nMinute, nSecond);
            m_name = p->m_name;
            m_image = p->m_30;
            FUN_141028be0(p->m_id, FUN_14016a600(p->m_30, 0), 1, CString(""));
        }
    }
}
MS2_REPLACE_METHOD(0x140b287b0, CGameRankingData, Convert, 7849, 0xB14681DC);

// @0x140b2a660
CStringW CGameRankingData::FormatTime(__int64 nTime)
{
    CMsTime t(nTime);
    CStringW strTime;
    strTime = FUN_14083bdc0(t, true, CStringW(L"/"), CStringW(L":"));
    return strTime;
}
MS2_REPLACE_METHOD(0x140b2a660, CGameRankingData, FormatTime, 293, 0xF8E7B919);

// ---- CGameRankingCli ----

// @0x140b2a790
CGameRankingCli::CGameRankingCli()
    : m_params(10), m_responses(10), m_personal(10)
{
    m_38 = 0;
    m_searchPage = 0;
    m_pending = 0;
}

// @0x140b2a8a0
CGameRankingCli::~CGameRankingCli()
{
    Clear();
    m_searchPage = 0;
    m_pending = 0;
    m_pendingPersonal = 0;
}

// @0x140b2a9b0
void CGameRankingCli::Update()
{
    if (!FUN_140166410()->FUN_14036d570(0x3f))
        return;
    DeliverRows();
    DeliverPersonal();
    DeliverSearch();
}
MS2_REPLACE_METHOD(0x140b2a9b0, CGameRankingCli, Update, 71, 0x466CB188);

// @0x140b2aa00
void CGameRankingCli::SetPending(MS2Ptr<GameRanking::IResponse> spResponse)
{
    if (Unk_LockGuard guard = m_lock) {}
    else
        m_pending = spResponse;
}
MS2_REPLACE_METHOD(0x140b2aa00, CGameRankingCli, SetPending, 111, 0x5CB2C711);

// @0x140b2aa80
void CGameRankingCli::SetPersonalPending(MS2Ptr<GameRanking::IResponse> spResponse)
{
    if (Unk_LockGuard guard = m_lock) {}
    else
        m_pendingPersonal = spResponse;
}
MS2_REPLACE_METHOD(0x140b2aa80, CGameRankingCli, SetPersonalPending, 113, 0xD5C6AF6C);

// @0x140b2ab00
void CGameRankingCli::ClearPersonal()
{
    if (Unk_LockGuard guard = m_lock) {}
    else
        m_personal.RemoveAll();
}
MS2_REPLACE_METHOD(0x140b2ab00, CGameRankingCli, ClearPersonal, 92, 0xD92C87C2);

// @0x140b2ab70
void CGameRankingCli::OnPacket(CByteBuffer& packet)
{
    if (!FUN_140166410()->FUN_14036d570(0x3f))
        return;
    int nMode = packet.ReadUInt8();
    if (nMode == 0x1f) {
        DAT_1439f4d94 = packet.ReadInt32();
        DAT_1439f4d98 = packet.ReadInt32();
    }
}
MS2_REPLACE_METHOD(0x140b2ab70, CGameRankingCli, OnPacket, 177, 0x548BC5EE);

// @0x140b2ac30
MS2Ptr<GameRanking::IResponse> CGameRankingCli::QueryPrevious(const Key& key, int bCheckValid)
{
    MS2Ptr<GameRanking::IResponse> spResponse(0);
    int bPersonal = FUN_140b3e700(key.m_type);
    if (Unk_LockGuard guard = m_lock) {}
    else {
        if (bPersonal != 0) {
            m_personal.Lookup(key, spResponse);
            if (bCheckValid == 1 && spResponse.get() != 0 && spResponse->IsValid() == 0) {
                m_personal.RemoveKey(key);
                spResponse = 0;
            }
        }
        else {
            m_responses.Lookup(key, spResponse);
            if (bCheckValid == 1 && spResponse.get() != 0 && spResponse->IsValid() == 0) {
                m_responses.RemoveKey(key);
                spResponse = 0;
            }
        }
    }
    return spResponse;
}
MS2_REPLACE_METHOD(0x140b2ac30, CGameRankingCli, QueryPrevious, 396, 0xC7C67A6E);

// @0x140b2add0
MS2Ptr<GameRanking::Page> CGameRankingCli::Query(const Key& key, int nPage, int bCheckValid)
{
    if (nPage <= 0)
        return 0;
    MS2Ptr<GameRanking::Page> spPage(0);
    if (Unk_LockGuard guard = m_lock) {}
    else {
        MS2Ptr<GameRanking::IResponse> spResponse = QueryPrevious(key, bCheckValid);
        if (spResponse == 0)
            return 0;
        spPage = spResponse->GetPage(nPage);
    }
    return spPage;
}
MS2_REPLACE_METHOD(0x140b2add0, CGameRankingCli, Query, 438, 0x02FB1AB0);

// @0x140b2af90
MS2Ptr<GameRanking::Page> CGameRankingCli::Search(const Key& key, CStringW strName, int bCheckValid)
{
    if (strName.GetLength() == 0)
        return 0;
    MS2Ptr<GameRanking::Page> spPage(0);
    if (Unk_LockGuard guard = m_lock) {}
    else {
        MS2Ptr<GameRanking::IResponse> spResponse = QueryPrevious(key, bCheckValid);
        if (spResponse == 0)
            return 0;
        spPage = spResponse->Search(strName);
        if (spPage.get() != 0)
            m_searchPage = spPage;
    }
    return spPage;
}
MS2_REPLACE_METHOD(0x140b2af90, CGameRankingCli, Search, 572, 0xD351A227);

// @0x140b2b1e0
TPtrValue<CGameRankingData> CGameRankingCli::GetData(const Key& key, int nRank, int bCheckValid)
{
    if (nRank < 1)
        return 0;
    if (nRank > 200)
        return 0;
    int nPage = nRank / 10;
    if (nRank % 10 != 0)
        nPage++;
    MS2Ptr<GameRanking::Page> spPage = Query(key, nPage, bCheckValid);
    if (spPage == 0)
        return 0;
    MS2Ptr<GameRankingItem::IRankItem> spItem = spPage->GetItem(nRank);
    if (spItem == 0)
        return 0;
    TPtrValue<CGameRankingData> spData(Unk_GrNewTag(0));
    spData->Convert(key.m_type, spItem);
    return spData;
}
MS2_REPLACE_METHOD(0x140b2b1e0, CGameRankingCli, GetData, 600, 0x2C4A9534);

// @0x140b2b440
int CGameRankingCli::Read(const Key& key, int nPage, ATL::CAtlArray<TPtrValue<CGameRankingData> >& rows,
                          CStringW strName, int bCheckValid)
{
    ATL::CAtlArray<MS2Ptr<GameRankingItem::IRankItem> > arrUnused;
    MS2Ptr<GameRanking::Page> spPage(0);
    if (strName.GetLength() == 0) {
        spPage = Query(key, nPage, bCheckValid);
        if (spPage == 0)
            return 0;
        for (int i = spPage->First(); i <= spPage->Last(); i++) {
            MS2Ptr<GameRankingItem::IRankItem> spItem = spPage->GetItem(i);
            if (spItem.get() != 0) {
                TPtrValue<CGameRankingData> spData(Unk_GrNewTag(0));
                spData->Convert(key.m_type, spItem);
                rows.Add(spData);
            }
        }
    }
    else {
        spPage = Search(key, strName, bCheckValid);
        if (spPage == 0)
            return 0;
        MS2Ptr<GameRankingItem::IRankItem> spItem = spPage->GetFirstItem();
        if (spItem.get() != 0) {
            TPtrValue<CGameRankingData> spData(Unk_GrNewTag(0));
            spData->Convert(key.m_type, spItem);
            rows.Add(spData);
        }
    }
    return 1;
}
MS2_REPLACE_METHOD(0x140b2b440, CGameRankingCli, Read, 1054, 0xC111026D);

// @0x140b2b870
void CGameRankingCli::BuildKey(Key& key, int nBoard, int nSub, int nMode, int nDate)
{
    if (nBoard == 1) {
        key.m_type = 0xe;
        key.m_date = FUN_140b3e150();
    }
    else if (nBoard == 2) {
        key.m_type = 0x18;
        key.m_date = FUN_140b3e150();
    }
    else if (nBoard == 3) {
        if (nMode == 0) {
            key.m_type = 0x21;
            key.m_sub = nSub;
        }
        else {
            key.m_type = 0x22;
            key.m_sub = nSub;
            key.m_date = nDate;
        }
    }
    else if (nBoard == 4) {
        if (nMode == 0)
            key.m_type = 0x2b;
        else {
            key.m_type = 0x2c;
            key.m_date = nDate;
        }
    }
    else if (nBoard == 5) {
        if (nMode == 0)
            key.m_type = 0x35;
        else {
            key.m_type = 0x36;
            key.m_date = nDate;
        }
    }
    else if (nBoard == 6) {
        if (nMode == 0)
            key.m_type = 0x3f;
        else {
            key.m_type = 0x40;
            key.m_date = FUN_140b3df90(GetServerTime(), nMode);
        }
    }
    else if (nBoard == 7 || nBoard == 8 || nBoard == 9 || nBoard == 0xf || nBoard == 0x11) {
        if (nMode == 0)
            key.m_type = 0x48;
        else if (nMode == 1)
            key.m_type = 0x51;
        else if (nMode == 2)
            key.m_type = 0x5b;
        key.m_sub = nSub;
    }
    else if (nBoard == 10) {
        if (nMode == 0) {
            key.m_type = 0x67;
            key.m_date = nDate;
        }
        else {
            key.m_type = 0x68;
            key.m_date = nDate;
        }
        key.m_sub = nSub;
    }
    else if (nBoard == 0xb) {
        if (nMode == 0)
            key.m_type = 0x70;
        else if (nMode == 1)
            key.m_type = 0x79;
        else if (nMode == 2)
            key.m_type = 0x84;
        key.m_sub = nSub;
    }
    else if (nBoard == 0xc) {
        if (nMode == 0)
            key.m_type = 0x8e;
        else if (nMode == 1)
            key.m_type = 0x97;
        else if (nMode == 2)
            key.m_type = 0xa2;
        key.m_sub = nSub;
    }
    else if (nBoard == 0xe) {
        if (nDate == 0) {
            key.m_type = 0xb7;
            return;
        }
        if (nMode == 0) {
            key.m_type = 0xb7;
            key.m_sub = nSub;
        }
        else {
            key.m_type = 0xb8;
            key.m_sub = nSub;
            key.m_date = nDate;
        }
    }
    else if (nBoard == 0x10) {
        if (nMode == 0) {
            key.m_type = 0xcb;
            key.m_sub = nSub;
        }
        else {
            key.m_type = 0xcc;
            key.m_sub = nSub;
            key.m_date = nDate;
        }
    }
}
MS2_REPLACE_METHOD(0x140b2b870, CGameRankingCli, BuildKey, 884, 0xF36DD656);

// The key of the own rank on a board.
// @0x140b2bbf0
void CGameRankingCli::BuildMyRankKey(Key& key, int nBoard, int nSub, int nMode, int nDate)
{
    if (nBoard == 1) {
        key.m_type = 0xc;
        key.m_date = FUN_140b3e150();
    }
    else if (nBoard == 2) {
        key.m_type = 0x16;
        key.m_date = FUN_140b3e150();
    }
    else if (nBoard == 3) {
        if (nMode == 0) {
            key.m_type = 0x1f;
            key.m_sub = nSub;
        }
        else {
            key.m_type = 0x20;
            key.m_sub = nSub;
            key.m_date = nDate;
        }
    }
    else if (nBoard == 4) {
        if (nMode == 0)
            key.m_type = 0x29;
        else {
            key.m_type = 0x2a;
            key.m_date = nDate;
        }
    }
    else if (nBoard == 5) {
        if (nMode == 0)
            key.m_type = 0x33;
        else {
            key.m_type = 0x34;
            key.m_date = nDate;
        }
    }
    else if (nBoard == 6) {
        if (nMode == 0)
            key.m_type = 0x3d;
        else {
            key.m_type = 0x3e;
            key.m_date = FUN_140b3df90(GetServerTime(), nMode);
        }
    }
    else if (nBoard == 7 || nBoard == 8 || nBoard == 9 || nBoard == 0xf || nBoard == 0x11) {
        if (nMode == 0)
            key.m_type = 0x47;
        key.m_sub = nSub;
    }
    else if (nBoard == 10) {
        if (nMode == 0) {
            key.m_type = 0x65;
            key.m_date = nDate;
        }
        else {
            key.m_type = 0x66;
            key.m_date = nDate;
        }
        key.m_sub = nSub;
    }
    else if (nBoard == 0xb) {
        if (nMode == 0)
            key.m_type = 0x6f;
        else if (nMode == 1) {
        }
        else if (nMode == 2)
            key.m_type = 0x83;
        key.m_sub = nSub;
    }
    else if (nBoard == 0xc) {
        if (nMode == 0)
            key.m_type = 0x8d;
        else if (nMode == 1) {
        }
        else if (nMode == 2)
            key.m_type = 0xa1;
        key.m_sub = nSub;
    }
    else if (nBoard == 0xe) {
        if (nDate == 0) {
            key.m_type = 0xb5;
            return;
        }
        if (nMode == 0) {
            key.m_type = 0xb5;
            key.m_sub = nSub;
        }
        else {
            key.m_type = 0xb6;
            key.m_sub = nSub;
            key.m_date = nDate;
        }
    }
    else if (nBoard == 0x10) {
        if (nMode == 0) {
            key.m_type = 0xc9;
            key.m_sub = nSub;
        }
        else {
            key.m_type = 0xca;
            key.m_sub = nSub;
            key.m_date = nDate;
        }
    }
}
MS2_REPLACE_METHOD(0x140b2bbf0, CGameRankingCli, BuildMyRankKey, 822, 0xFEE617A6);

// @0x140b2bf30
void CGameRankingCli::Request(const CGameRankingParam* pParam)
{
    if (FUN_14025e7b0()->m_8.FUN_1402c4c90(0x32) == 1)
        return;
    if (!FUN_140166410()->FUN_14036d570(0x3f))
        return;
    MS2Ptr<CGameRankingParam> spParam = AddParam(pParam);
    if (spParam.get() != 0)
        AfxBeginThread(RequestWeb, spParam.get(), 0, 0, 0, 0);
}
MS2_REPLACE_METHOD(0x140b2bf30, CGameRankingCli, Request, 179, 0xBF4AE991);

// @0x140b2bff0
void CGameRankingCli::ReceiveWeb(MS2Ptr<CGameRankingParam> spParam, MS2Ptr<CGameRankingWebResult> spResult)
{
    if (spParam == 0)
        return;
    if (spResult == 0)
        return;
    RemoveParam(spParam->m_key);
    if (spResult->m_result == 0) {
        MS2Ptr<GameRanking::IResponse> spResponse = FUN_140b35ad0(spParam->m_key.m_type);
        if (spResponse == 0)
            return;
        if (spResponse->Read(spResult->m_buffer) == 0)
            return;
        if (spParam->m_search.GetLength() > 0)
            ReceiveSearch(spParam, spResponse);
        else {
            CGameRankingParam::Key key(spParam.get());
            SetResponse(key, spResponse);
            if (FUN_140b3e700(spParam->m_key.m_type) == 1)
                SetPersonalPending(spResponse);
            else
                SetPending(spResponse);
        }
    }
}
MS2_REPLACE_METHOD(0x140b2bff0, CGameRankingCli, ReceiveWeb, 830, 0xF8A0CE45);

// @0x140b2c340
void CGameRankingCli::ReceiveSearch(MS2Ptr<CGameRankingParam> spParam, MS2Ptr<GameRanking::IResponse> spResponse)
{
    if (spParam == 0)
        return;
    if (spResponse == 0)
        return;
    CGameRankingParam::Key key = spParam->m_key;
    if (Unk_LockGuard guard = m_lock) {}
    else {
        MS2Ptr<GameRanking::IResponse> spPrevious = QueryPrevious(key, 0);
        if (spPrevious.get() != 0) {
            spPrevious->Merge(spParam->m_search, spResponse.get());
            m_searchPage = spPrevious->Search(spParam->m_search);
        }
        else
            m_searchPage = spResponse->GetPage(1);
    }
}
MS2_REPLACE_METHOD(0x140b2c340, CGameRankingCli, ReceiveSearch, 731, 0x444995E5);

// @0x140b2c630
void CGameRankingCli::SetResponse(const Key& key, MS2Ptr<GameRanking::IResponse> spResponse)
{
    int bPersonal = FUN_140b3e700(key.m_type);
    if (Unk_LockGuard guard = m_lock) {}
    else {
        if (bPersonal == 1)
            m_personal.SetAt(key, spResponse);
        else
            m_responses.SetAt(key, spResponse);
    }
}
MS2_REPLACE_METHOD(0x140b2c630, CGameRankingCli, SetResponse, 177, 0x1A42FE44);

// @0x140b2c6f0
__int64 CGameRankingCli::OwnerId(int nBoard)
{
    __int64 nId = 0;
    if (nBoard == 1 || nBoard == 5) {
        if (FUN_1403ed290()->FUN_1413b6160() == 0)
            return 0;
        nId = FUN_1403ed290()->m_8.FUN_1404ccbd0();
    }
    else if (nBoard == 2 || nBoard == 3 || nBoard == 4 || nBoard == 7 || nBoard == 8 || nBoard == 9 || nBoard == 0xf ||
             nBoard == 0x11 || nBoard == 0xb || nBoard == 0xc || nBoard == 10 || nBoard == 0xe || nBoard == 0x10)
        nId = DAT_143ab2828;
    else if (nBoard == 6)
        nId = DAT_143ab2820;
    return nId;
}
MS2_REPLACE_METHOD(0x140b2c6f0, CGameRankingCli, OwnerId, 218, 0x9A7387E3);

// @0x140b2c7d0
void CGameRankingCli::Clear()
{
    m_params.RemoveAll();
    m_responses.RemoveAll();
    m_personal.RemoveAll();
}
MS2_REPLACE_METHOD(0x140b2c7d0, CGameRankingCli, Clear, 69, 0x9D5A4764);

// @0x140b2c820
MS2Ptr<CGameRankingParam> CGameRankingCli::AddParam(const CGameRankingParam* pParam)
{
    MS2Ptr<CGameRankingParam> spParam(0);
    CGameRankingParam::Key key(pParam);
    if (Unk_LockGuard guard = m_lock) {}
    else {
        if (m_params.Lookup(key) != NULL)
            return 0;
        spParam.AssignRaw(new CGameRankingParam);
        spParam->Copy(pParam);
        m_params.SetAt(key, spParam);
    }
    return spParam;
}
MS2_REPLACE_METHOD(0x140b2c820, CGameRankingCli, AddParam, 418, 0x2D53F44A);

// @0x140b2c9d0
void CGameRankingCli::RemoveParam(const Key& key)
{
    if (Unk_LockGuard guard = m_lock) {}
    else
        m_params.RemoveKey(key);
}
MS2_REPLACE_METHOD(0x140b2c9d0, CGameRankingCli, RemoveParam, 100, 0xB2407F34);

// The ranking dialog, when it is open.
// @0x140b2d030
static UIGameRankingDialog* FUN_140b2d030(int nClass)
{
    if (FUN_1403ed2b0() != 0) {
        MS2Ptr<UIObject> spObj = FUN_1403ed2b0()->FUN_141adcea0(nClass);
        if (spObj.get() != 0)
            return dynamic_cast<UIGameRankingDialog*>(spObj.operator->());
    }
    return 0;
}

// @0x140b2ca40
void CGameRankingCli::DeliverRows()
{
    MS2Ptr<GameRanking::IResponse> spResponse(0);
    if (Unk_LockGuard guard = m_lock) {}
    else {
        if (m_pending == 0)
            return;
        spResponse = m_pending;
        m_pending = 0;
    }
    UIGameRankingDialog* pDialog = FUN_140b2d030(0x4f24);
    if (pDialog != 0 && pDialog->vfunc_55() == 0) {
        MS2Ptr<GameRanking::Page> spPage = spResponse->GetPage(1);
        if (spPage.get() != 0) {
            pDialog->FUN_140e34ce0(1, spPage->Total());
            pDialog->FUN_140e31910(0);
            if (spPage->Total() != 0)
                pDialog->FUN_140e32f30(1, 0, CStringW(L""));
        }
    }
}
MS2_REPLACE_METHOD(0x140b2ca40, CGameRankingCli, DeliverRows, 457, 0xFBB6DF5B);

// @0x140b2cc10
void CGameRankingCli::DeliverSearch()
{
    MS2Ptr<GameRanking::Page> spPage(0);
    if (Unk_LockGuard guard = m_lock) {}
    else {
        if (m_searchPage == 0)
            return;
        spPage = m_searchPage;
        m_searchPage = 0;
    }
    UIGameRankingDialog* pDialog = FUN_140b2d030(0x4f24);
    if (pDialog != 0 && pDialog->vfunc_55() == 0)
        pDialog->FUN_140e34eb0(spPage);
}
MS2_REPLACE_METHOD(0x140b2cc10, CGameRankingCli, DeliverSearch, 299, 0xA7DC09DF);

// @0x140b2cd50
void CGameRankingCli::DeliverPersonal()
{
    MS2Ptr<GameRanking::IResponse> spResponse(0);
    if (Unk_LockGuard guard = m_lock) {}
    else {
        if (m_pendingPersonal == 0)
            return;
        spResponse = m_pendingPersonal;
        m_pendingPersonal = 0;
    }
    UIGameRankingDialog* pDialog = FUN_140b2d030(0x4f24);
    if (pDialog != 0 && pDialog->vfunc_55() == 0)
        pDialog->FUN_140e31910(0);
}
MS2_REPLACE_METHOD(0x140b2cd50, CGameRankingCli, DeliverPersonal, 251, 0xD6D41476);

// @0x140b2ce60
unsigned int __cdecl CGameRankingCli::RequestWeb(void* pParam)
{
    FUN_141b6de20();
    Unk_UtilLogScope scope(CString("CGameRankingCli::RequestWeb"));
    MS2Ptr<CGameRankingParam> spParam(static_cast<CGameRankingParam*>(pParam));
    if (spParam == 0)
        return 1;
    if (CSoapClient::GetInstance() != 0) {
        MS2Ptr<CGameRankingWebResult> spResult = CSoapClient::GetInstance()->FUN_141770670(spParam);
        if (spResult.get() != 0) {
            if (GetInstance() != 0)
                GetInstance()->ReceiveWeb(spParam, spResult);
        }
    }
    return 0;
}

// ---- CGameRankingData (inline in the exe) ----

// @0x140b319a0
void CGameRankingData::Clear()
{
    m_18 = 0;
    m_category = 0;
    m_10 = 0;
    m_id = 0;
    m_20 = 0;
    m_14 = 0;
    m_point = 0;
    m_rank = 0;
    m_name = m_40 = m_48 = m_50 = m_date = m_time = m_70 = m_image = m_80 = m_60 = L"";
}

// @0x140b31ad0
MS2_EMIT_CRT_MEMMOVE_S();


// ---- GameRankingItem ----

// @0x140b31bf0
GameRankingItem::GuildTrophy::GuildTrophy()
{
    m_rank = 0;
    m_id = 0;
    m_name.Empty();
    m_30.Empty();
    m_38.Empty();
    m_40 = 0;
    for (int i = 0; i < 3; i++)
        m_values[i] = 0;
}

// @0x140b31cf0
void GameRankingItem::GuildTrophy::Read(CByteBuffer& s)
{
    m_rank = s.ReadInt32();
    m_id = s.ReadInt64();
    m_name = FUN_140b3f4e0(s);
    m_30 = FUN_140b3f4e0(s);
    m_38 = FUN_140b3f4e0(s);
    m_40 = s.ReadInt32();
    m_values[1] = s.ReadInt32();
    m_values[2] = s.ReadInt32();
    m_values[0] = s.ReadInt32();
}

// @0x140b31f60
GameRankingItem::UserTrophy::UserTrophy()
{
    m_rank = 0;
    m_id = 0;
    m_name.Empty();
    m_30.Empty();
    m_38 = 0;
    for (int i = 0; i < 3; i++)
        m_values[i] = 0;
}

// @0x140b32030
void GameRankingItem::UserTrophy::Read(CByteBuffer& s)
{
    m_rank = s.ReadInt32();
    m_id = s.ReadInt64();
    m_name = FUN_140b3f4e0(s);
    m_30 = FUN_140b3f4e0(s);
    m_38 = s.ReadInt32();
    m_values[1] = s.ReadInt32();
    m_values[2] = s.ReadInt32();
    m_values[0] = s.ReadInt32();
}

// @0x140b32240
GameRankingItem::DarkStream::DarkStream()
{
    m_rank = 0;
    m_id = 0;
    m_name.Empty();
    m_30.Empty();
    m_38 = 0;
    m_3c = 0;
    m_40 = 0;
    m_time = 0;
}

// @0x140b32310
void GameRankingItem::DarkStream::Read(CByteBuffer& s)
{
    m_rank = s.ReadInt32();
    m_id = s.ReadInt64();
    m_name = FUN_140b3f4e0(s);
    m_30 = FUN_140b3f4e0(s);
    m_38 = s.ReadInt32();
    m_3c = s.ReadInt32();
    m_40 = s.ReadInt32();
    m_time = FUN_140b3f610(s);
}

// @0x140b324e0
GameRankingItem::UserPvp::UserPvp()
{
    m_rank = 0;
    m_id = 0;
    m_name.Empty();
    m_30.Empty();
    m_38 = 0;
    m_3c = 0;
    m_40 = 0;
}

// @0x140b325a0
void GameRankingItem::UserPvp::Read(CByteBuffer& s)
{
    m_rank = s.ReadInt32();
    m_id = s.ReadInt64();
    m_name = FUN_140b3f4e0(s);
    m_30 = FUN_140b3f4e0(s);
    m_38 = s.ReadInt32();
    m_3c = s.ReadInt32();
}

// @0x140b32730
GameRankingItem::GuildPvp::GuildPvp()
{
    m_rank = 0;
    m_id = 0;
    m_name.Empty();
    m_30.Empty();
    m_38.Empty();
    m_40 = 0;
    m_44 = 0;
    m_48 = 0;
}

// @0x140b32810
void GameRankingItem::GuildPvp::Read(CByteBuffer& s)
{
    m_rank = s.ReadInt32();
    m_id = s.ReadInt64();
    m_name = FUN_140b3f4e0(s);
    m_30 = FUN_140b3f4e0(s);
    m_38 = FUN_140b3f4e0(s);
    m_40 = s.ReadInt32();
    m_44 = s.ReadInt32();
}

// @0x140b329f0
GameRankingItem::UgcMapCommendation::UgcMapCommendation()
{
    m_rank = 0;
    m_id = 0;
    m_name.Empty();
    m_30.Empty();
    m_38 = 0;
    m_3c = 0;
    m_40 = 0;
    m_48.Empty();
}

// @0x140b32ad0
void GameRankingItem::UgcMapCommendation::Read(CByteBuffer& s)
{
    m_rank = s.ReadInt32();
    m_id = s.ReadInt64();
    m_name = FUN_140b3f4e0(s);
    m_30 = FUN_140b3f4e0(s);
    m_38 = s.ReadInt32();
    m_3c = s.ReadInt32();
    m_40 = s.ReadInt64();
    m_48 = FUN_140b3f4e0(s);
}

// @0x140b32ce0
GameRankingItem::BossKillCount::BossKillCount()
{
    m_rank = 0;
    m_id = 0;
    m_name.Empty();
    m_30.Empty();
    m_40 = 0;
    m_38 = 0;
    m_3c = 0;
}

// @0x140b32da0
void GameRankingItem::BossKillCount::Read(CByteBuffer& s)
{
    m_rank = s.ReadInt32();
    m_id = s.ReadInt64();
    m_name = FUN_140b3f4e0(s);
    m_30 = FUN_140b3f4e0(s);
    m_38 = s.ReadInt32();
    m_3c = s.ReadInt32();
    m_40 = s.ReadInt32();
}

// @0x140b32f60
GameRankingItem::BossKillPartyMember::BossKillPartyMember()
{
    Clear();
}

// @0x140b32fd0
void GameRankingItem::BossKillPartyMember::Clear()
{
    m_id = 0;
    m_name.Empty();
    m_image.Empty();
    m_job = 0;
    m_level = 0;
    m_38 = 0;
}

// @0x140b33040
GameRankingItem::BossKillRecord::BossKillRecord()
{
    m_rank = 0;
    m_20 = 0;
    m_28 = 0;
    m_leaderId = 0;
    m_38 = 0;
    m_time = 0;
    for (int i = 0; i < 10; i++)
        m_members[i].Clear();
}

// @0x140b33130
void GameRankingItem::BossKillRecord::Read(CByteBuffer& s)
{
    m_rank = s.ReadInt32();
    m_20 = s.ReadInt64();
    m_leaderId = s.ReadInt64();
    m_28 = s.ReadInt32();
    m_38 = s.ReadInt32();
    m_time = FUN_140b3f610(s);
    int nCount = s.ReadInt32();
    for (int i = 0; i < nCount; i++) {
        BossKillPartyMember member;
        member.m_id = s.ReadInt64();
        member.m_name = FUN_140b3f4e0(s);
        member.m_image = FUN_140b3f4e0(s);
        member.m_level = s.ReadInt32();
        member.m_job = s.ReadInt32();
        if (i < 10)
            m_members[i] = member;
    }
}

// @0x140b33440
CStringW GameRankingItem::BossKillRecord::LeaderName()
{
    CStringW str = m_members[0].m_name;
    for (int i = 0; i < 10; i++) {
        if (m_members[i].m_id == m_leaderId) {
            str = m_members[i].m_name;
            break;
        }
    }
    return str;
}

// @0x140b33520
GameRankingItem::Arcade::Arcade()
{
    m_rank = 0;
    m_id = 0;
    m_name.Empty();
    m_30.Empty();
    m_38 = 0;
    m_3c = 0;
    m_40 = 0;
    m_44 = 0;
    m_48 = 0;
    m_time = 0;
}

// @0x140b33600
void GameRankingItem::Arcade::Read(CByteBuffer& s)
{
    m_rank = s.ReadInt32();
    m_id = s.ReadInt64();
    m_name = FUN_140b3f4e0(s);
    m_30 = FUN_140b3f4e0(s);
    m_38 = s.ReadInt32();
    m_44 = s.ReadInt32();
    m_3c = s.ReadInt32();
    m_40 = s.ReadInt32();
    m_48 = s.ReadInt32();
    m_time = FUN_140b3f610(s);
}

// @0x140b33840
GameRankingItem::BossDamageCount::BossDamageCount()
{
    m_rank = 0;
    m_id = 0;
    m_name.Empty();
    m_30.Empty();
    m_40 = 0;
    m_38 = 0;
    m_3c = 0;
}

// @0x140b33900
void GameRankingItem::BossDamageCount::Read(CByteBuffer& s)
{
    m_rank = s.ReadInt32();
    m_id = s.ReadInt64();
    m_name = FUN_140b3f4e0(s);
    m_30 = FUN_140b3f4e0(s);
    m_38 = s.ReadInt32();
    m_3c = s.ReadInt32();
    m_40 = s.ReadInt32();
}

// @0x140b33ac0
GameRankingItem::BossDamageDate::BossDamageDate()
{
    m_rank = 0;
    m_20 = 0;
    m_28 = 0;
    m_leaderId = 0;
    m_38 = 0;
    m_time = 0;
    for (int i = 0; i < 10; i++)
        m_members[i].Clear();
}

// @0x140b33bb0
void GameRankingItem::BossDamageDate::Read(CByteBuffer& s)
{
    m_rank = s.ReadInt32();
    m_20 = s.ReadInt64();
    m_leaderId = s.ReadInt64();
    m_28 = s.ReadInt32();
    m_38 = s.ReadInt64();
    m_time = FUN_140b3f610(s);
    int nCount = s.ReadInt32();
    for (int i = 0; i < nCount; i++) {
        BossKillPartyMember member;
        member.m_id = s.ReadInt64();
        member.m_name = FUN_140b3f4e0(s);
        member.m_image = FUN_140b3f4e0(s);
        member.m_level = s.ReadInt32();
        member.m_job = s.ReadInt32();
        if (i < 10)
            m_members[i] = member;
    }
}

// @0x140b33ec0
CStringW GameRankingItem::BossDamageDate::LeaderName()
{
    CStringW str = m_members[0].m_name;
    for (int i = 0; i < 10; i++) {
        if (m_members[i].m_id == m_leaderId) {
            str = m_members[i].m_name;
            break;
        }
    }
    return str;
}

// @0x140b33fa0
GameRankingItem::BossDamageAmount::BossDamageAmount()
{
    m_rank = 0;
    m_20 = 0;
    m_30 = 0;
    m_38 = 0;
    m_40 = 0;
    m_48 = 0;
    m_50 = 0;
    m_58 = 0;
    m_60 = 0;
    m_time = 0;
    for (int i = 0; i < 10; i++)
        m_members[i].Clear();
}

// @0x140b340d0
void GameRankingItem::BossDamageAmount::Read(CByteBuffer& s)
{
    m_rank = s.ReadInt32();
    m_20 = s.ReadInt64();
    m_leaderId = s.ReadInt64();
    m_38 = s.ReadInt64();
    m_30 = s.ReadInt32();
    m_40 = s.ReadInt64();
    m_48 = s.ReadInt64();
    m_50 = s.ReadInt64();
    m_58 = s.ReadInt64();
    m_60 = s.ReadInt32();
    m_time = FUN_140b3f610(s);
    int nCount = s.ReadInt32();
    for (int i = 0; i < nCount; i++) {
        BossKillPartyMember member;
        member.m_id = s.ReadInt64();
        member.m_name = FUN_140b3f4e0(s);
        member.m_image = FUN_140b3f4e0(s);
        member.m_level = s.ReadInt32();
        member.m_job = s.ReadInt32();
        if (i < 10)
            m_members[i] = member;
    }
}

// @0x140b34500
CStringW GameRankingItem::BossDamageAmount::LeaderName()
{
    CStringW str = m_members[0].m_name;
    for (int i = 0; i < 10; i++) {
        if (m_members[i].m_id == m_leaderId) {
            str = m_members[i].m_name;
            break;
        }
    }
    return str;
}

// @0x140b345e0
CStringW GameRankingItem::BossDamageAmount::LeaderImage()
{
    CStringW str = m_members[0].m_image;
    for (int i = 0; i < 10; i++) {
        if (m_members[i].m_id == m_leaderId) {
            str = m_members[i].m_image;
            break;
        }
    }
    return str;
}

// @0x140b346c0
GameRankingItem::BossRumbleCount::BossRumbleCount()
{
    m_rank = 0;
    m_id = 0;
    m_name.Empty();
    m_30.Empty();
    m_40 = 0;
    m_38 = 0;
    m_3c = 0;
}

// @0x140b34780
void GameRankingItem::BossRumbleCount::Read(CByteBuffer& s)
{
    m_rank = s.ReadInt32();
    m_id = s.ReadInt64();
    m_name = FUN_140b3f4e0(s);
    m_30 = FUN_140b3f4e0(s);
    m_38 = s.ReadInt32();
    m_3c = s.ReadInt32();
    m_40 = s.ReadInt32();
}

// @0x140b34940
GameRankingItem::BossRumbleRecord::BossRumbleRecord()
{
    m_rank = 0;
    m_20 = 0;
    m_28 = 0;
    m_30 = 0;
    m_38.Empty();
    m_40.Empty();
    m_48 = 0;
    m_4c = 0;
    m_50 = 0;
    m_time = 0;
}

// @0x140b34a20
void GameRankingItem::BossRumbleRecord::Read(CByteBuffer& s)
{
    m_rank = s.ReadInt32();
    m_20 = s.ReadInt64();
    m_30 = s.ReadInt64();
    m_38 = FUN_140b3f4e0(s);
    m_40 = FUN_140b3f4e0(s);
    m_4c = s.ReadInt32();
    m_48 = s.ReadInt32();
    m_28 = s.ReadInt32();
    m_50 = s.ReadInt32();
    m_time = FUN_140b3f610(s);
}

// @0x140b34c60
GameRankingItem::Survival::Survival()
{
    m_rank = 0;
    m_id = 0;
    m_name.Empty();
    m_30.Empty();
    m_38 = 0;
    m_40 = 0;
    m_48 = 0;
    m_4c = 0;
    m_50 = 0;
    m_54 = 0;
    m_58 = 0;
    m_60 = 0;
    m_time = 0;
    m_70 = 0;
}

// @0x140b34d70
void GameRankingItem::Survival::Read(CByteBuffer& s)
{
    m_rank = s.ReadInt32();
    m_id = s.ReadInt64();
    m_name = FUN_140b3f4e0(s);
    m_30 = FUN_140b3f4e0(s);
    m_38 = s.ReadInt32();
    m_40 = s.ReadInt64();
    m_48 = s.ReadInt32();
    m_4c = s.ReadInt32();
    m_50 = s.ReadInt32();
    m_54 = s.ReadInt32();
    m_58 = s.ReadInt32();
    m_60 = s.ReadInt64();
    m_time = FUN_140b3f610(s);
}

// @0x140b35060
GameRankingItem::WorldChampion::WorldChampion()
{
    m_rank = 0;
    m_id = 0;
    m_name.Empty();
    m_30.Empty();
    m_38 = 0;
    m_40 = 0;
    m_48 = 0;
    m_50 = 0;
    m_58 = 0;
    m_60 = 0;
}

// @0x140b35140
void GameRankingItem::WorldChampion::Read(CByteBuffer& s)
{
    m_rank = s.ReadInt32();
    m_id = s.ReadInt64();
    m_name = FUN_140b3f4e0(s);
    m_30 = FUN_140b3f4e0(s);
    m_38 = s.ReadInt32();
    m_40 = s.ReadInt64();
    m_48 = s.ReadInt64();
    m_50 = FUN_140b3f610(s);
    m_58 = FUN_140b3f610(s);
}

// @0x140b35330
GameRankingItem::BossColosseum::BossColosseum()
{
    m_rank = 0;
    m_id = 0;
    m_name.Empty();
    m_30.Empty();
    m_38 = 0;
    m_3c = 0;
    m_40 = 0;
    m_48 = 0;
    m_4c = 0;
    m_50 = 0;
    m_58 = 0;
    m_60 = 0;
    m_68 = 0;
}

// @0x140b35440
void GameRankingItem::BossColosseum::Read(CByteBuffer& s)
{
    m_rank = s.ReadInt32();
    m_id = s.ReadInt64();
    m_name = FUN_140b3f4e0(s);
    m_30 = FUN_140b3f4e0(s);
    m_38 = s.ReadInt32();
    m_3c = s.ReadInt32();
    m_40 = s.ReadInt64();
    m_48 = s.ReadInt32();
    m_4c = s.ReadInt32();
    m_50 = s.ReadInt32();
    m_58 = FUN_140b3f610(s);
    m_60 = FUN_140b3f610(s);
}

// ---- CGameRankingParam::Key ----

// @0x140b356e0
CGameRankingParam::Key::Key()
{
    Clear();
}

// @0x140b35710
CGameRankingParam::Key::Key(const CGameRankingParam* pParam)
{
    Clear();
    if (pParam == 0)
        return;
    m_type = pParam->m_key.m_type;
    m_sub = pParam->m_key.m_sub;
    m_date = pParam->m_key.m_date;
}

// @0x140b35780
CGameRankingParam::Key::~Key()
{
    Clear();
}

// @0x140b357b0
void CGameRankingParam::Key::Clear()
{
    m_type = 0;
    m_sub = 0;
    m_date = 0;
}

// @0x140b357e0
int CGameRankingParam::Key::GetCategory() const
{
    return FUN_140b3e210(*this);
}

// @0x140b35820
CGameRankingParam::Key& CGameRankingParam::Key::operator=(const Key& o)
{
    m_type = o.m_type;
    m_sub = o.m_sub;
    m_date = o.m_date;
    return *this;
}

// ---- GameRanking::IResponse ----

// @0x140b35870
GameRanking::IResponse::IResponse(unsigned int nType)
{
    m_type = nType;
    m_result = 1;
    m_time = 0;
}

// @0x140b358d0
int GameRanking::IResponse::Read(CByteBuffer& s)
{
    unsigned int nType = s.ReadInt32();
    if (nType != m_type)
        return 0;
    m_result = s.ReadInt32();
    m_time = FUN_140b3f610(s);
    return 1;
}

// @0x140b35970
int GameRanking::IResponse::IsValid()
{
    if (m_type == 0xd || m_type == 0x17 || m_type == 0x21 || m_type == 0x3f || m_type == 0x48 || m_type == 0x51 ||
        m_type == 0x5b || m_type == 0x67 || m_type == 0x70 || m_type == 0x79 || m_type == 0x84 || m_type == 0x8e ||
        m_type == 0x97 || m_type == 0xa2 || m_type == 0xb7 || m_type == 0xcb || FUN_140b3e700(m_type) == 1) {
        __int64 nElapsed = GetServerTime() - m_time;
        if (nElapsed >= DAT_1439f4d94)
            return 0;
    }
    else {
        __int64 nElapsed = GetServerTime() - m_time;
        if (nElapsed >= DAT_1439f4d98 * 60)
            return 0;
    }
    return 1;
}

// The answer object of a board type.
// @0x140b35ad0
MS2Ptr<GameRanking::IResponse> FUN_140b35ad0(int nType)
{
    MS2Ptr<GameRanking::IResponse> spResponse(0);
    switch (nType) {
    case 0xb: spResponse.AssignRaw(new GameRanking::MyRank(nType)); break;
    case 0xc: spResponse.AssignRaw(new GameRanking::MyRank(nType)); break;
    case 0xd: spResponse.AssignRaw(new GameRanking::GuildTrophy(nType)); break;
    case 0xe: spResponse.AssignRaw(new GameRanking::GuildTrophy(nType)); break;
    case 0x15: spResponse.AssignRaw(new GameRanking::MyRank(nType)); break;
    case 0x16: spResponse.AssignRaw(new GameRanking::MyRank(nType)); break;
    case 0x17: spResponse.AssignRaw(new GameRanking::UserTrophy(nType)); break;
    case 0x18: spResponse.AssignRaw(new GameRanking::UserTrophy(nType)); break;
    case 0x1f: spResponse.AssignRaw(new GameRanking::MyRank(nType)); break;
    case 0x20: spResponse.AssignRaw(new GameRanking::MyRank(nType)); break;
    case 0x21: spResponse.AssignRaw(new GameRanking::DarkStream(nType)); break;
    case 0x22: spResponse.AssignRaw(new GameRanking::DarkStream(nType)); break;
    case 0x29: spResponse.AssignRaw(new GameRanking::MyRank(nType)); break;
    case 0x2a: spResponse.AssignRaw(new GameRanking::MyRank(nType)); break;
    case 0x2b: spResponse.AssignRaw(new GameRanking::UserPvp(nType)); break;
    case 0x2c: spResponse.AssignRaw(new GameRanking::UserPvp(nType)); break;
    case 0x33: spResponse.AssignRaw(new GameRanking::MyRank(nType)); break;
    case 0x34: spResponse.AssignRaw(new GameRanking::MyRank(nType)); break;
    case 0x35: spResponse.AssignRaw(new GameRanking::GuildPvp(nType)); break;
    case 0x36: spResponse.AssignRaw(new GameRanking::GuildPvp(nType)); break;
    case 0x3d: spResponse.AssignRaw(new GameRanking::MyRank(nType)); break;
    case 0x3e: spResponse.AssignRaw(new GameRanking::MyRank(nType)); break;
    case 0x3f: spResponse.AssignRaw(new GameRanking::UgcMapCommendation(nType)); break;
    case 0x40: spResponse.AssignRaw(new GameRanking::UgcMapCommendation(nType)); break;
    case 0x47: spResponse.AssignRaw(new GameRanking::MyRank(nType)); break;
    case 0x48: spResponse.AssignRaw(new GameRanking::BossKillCount(nType)); break;
    case 0x51: spResponse.AssignRaw(new GameRanking::BossKillRecord(nType)); break;
    case 0x5b: spResponse.AssignRaw(new GameRanking::BossKillRecord(nType)); break;
    case 0x65: spResponse.AssignRaw(new GameRanking::MyRank(nType)); break;
    case 0x66: spResponse.AssignRaw(new GameRanking::MyRank(nType)); break;
    case 0x67: spResponse.AssignRaw(new GameRanking::Arcade(nType)); break;
    case 0x68: spResponse.AssignRaw(new GameRanking::Arcade(nType)); break;
    case 0x6f: spResponse.AssignRaw(new GameRanking::MyRank(nType)); break;
    case 0x70: spResponse.AssignRaw(new GameRanking::BossDamageCount(nType)); break;
    case 0x79: spResponse.AssignRaw(new GameRanking::BossDamageDate(nType)); break;
    case 0x83: spResponse.AssignRaw(new GameRanking::MyRank(nType)); break;
    case 0x84: spResponse.AssignRaw(new GameRanking::BossDamageAmount(nType)); break;
    case 0x8d: spResponse.AssignRaw(new GameRanking::MyRank(nType)); break;
    case 0x8e: spResponse.AssignRaw(new GameRanking::BossRumbleCount(nType)); break;
    case 0x97: spResponse.AssignRaw(new GameRanking::BossRumbleRecord(nType)); break;
    case 0xa1: spResponse.AssignRaw(new GameRanking::MyRank(nType)); break;
    case 0xa2: spResponse.AssignRaw(new GameRanking::BossRumbleRecord(nType)); break;
    case 0xb5: spResponse.AssignRaw(new GameRanking::MyRankPercent(nType)); break;
    case 0xb6: spResponse.AssignRaw(new GameRanking::MyRankPercent(nType)); break;
    case 0xb7: spResponse.AssignRaw(new GameRanking::WorldChampion(nType)); break;
    case 0xb8: spResponse.AssignRaw(new GameRanking::WorldChampion(nType)); break;
    case 0xc9: spResponse.AssignRaw(new GameRanking::MyRank(nType)); break;
    case 0xca: spResponse.AssignRaw(new GameRanking::MyRank(nType)); break;
    case 0xcb: spResponse.AssignRaw(new GameRanking::BossColosseum(nType)); break;
    case 0xcc: spResponse.AssignRaw(new GameRanking::BossColosseum(nType)); break;
    }
    return spResponse;
}

// ---- GameRanking::MyRank / MyRankPercent ----

// @0x140b37240
GameRanking::MyRank::MyRank(unsigned int nType)
    : IResponse(nType)
{
    m_rank = 0;
}

// MS2-FUNCTIONAL: the exe frame is 0x10 larger (an unused slot); the code is identical
// @0x140b37290
int GameRanking::MyRank::Read(CByteBuffer& s)
{
    try {
        if (IResponse::Read(s) == 0)
            return 0;
        m_rank = s.ReadInt32();
    }
    catch (...) {
        return 0;
    }
    return 1;
}

// @0x140b37310
GameRanking::MyRankPercent::MyRankPercent(unsigned int nType)
    : IResponse(nType)
{
    m_kind = 0;
    m_rank = 0;
}

// @0x140b37370
int GameRanking::MyRankPercent::Read(CByteBuffer& s)
{
    try {
        if (IResponse::Read(s) == 0)
            return 0;
        m_kind = s.ReadInt32();
        m_rank = s.ReadInt32();
    }
    catch (...) {
        return 0;
    }
    return 1;
}

// ---- the board answers ----

// @0x140b37430
GameRanking::GuildTrophy::GuildTrophy(unsigned int nType)
    : IResponse(nType)
{
}

// @0x140b374a0
int GameRanking::GuildTrophy::Read(CByteBuffer& s)
{
    try {
        if (IResponse::Read(s) == 0)
            return 0;
        int nCount = s.ReadInt32();
        for (int i = 0; i < nCount; i++) {
            MS2Ptr<GameRankingItem::GuildTrophy> spItem(new GameRankingItem::GuildTrophy);
            spItem->Read(s);
            m_ranks.SetAt(spItem->m_rank, spItem);
            m_names.SetAt(spItem->m_name, spItem);
        }
    }
    catch (...) {
        return 0;
    }
    return 1;
}

// @0x140b37670
MS2Ptr<GameRanking::Page> GameRanking::GuildTrophy::GetPage(int nPage)
{
    MS2Ptr<Page> spPage(new Page(m_type, nPage));
    spPage->SetTotal((int)m_ranks.GetCount());
    for (int i = spPage->First(); i <= spPage->Last(); i++) {
        MS2Ptr<GameRankingItem::GuildTrophy> spItem(0);
        m_ranks.Lookup(i, spItem);
        if (spItem.get() != 0)
            spPage->Add(i, spItem.get());
    }
    return spPage;
}

// @0x140b37820
MS2Ptr<GameRanking::Page> GameRanking::GuildTrophy::Search(CStringW strName)
{
    MS2Ptr<Page> spPage(new Page(m_type, 1));
    spPage->SetTotal(1);
    MS2Ptr<GameRankingItem::GuildTrophy> spItem(0);
    m_names.Lookup(strName, spItem);
    if (spItem == 0)
        return 0;
    spPage->Add(spItem->m_rank, spItem);
    return spPage;
}

// @0x140b379e0
void GameRanking::GuildTrophy::Merge(CStringW strName, IResponse* pOther)
{
    if (m_names.Lookup(strName) == NULL) {
        GuildTrophy* pList = static_cast<GuildTrophy*>(pOther);
        if (pList != NULL) {
            if (pList->m_ranks.GetCount() == 0) {
                MS2Ptr<GameRankingItem::GuildTrophy> spItem(new GameRankingItem::GuildTrophy);
                m_names.SetAt(strName, spItem);
            }
            else {
                for (POSITION pos = pList->m_ranks.GetHeadPosition(); pos != NULL; pList->m_ranks.GetNext(pos))
                    m_names.SetAt(strName, pList->m_ranks.GetValueAt(pos));
            }
        }
    }
}

// @0x140b37b40
GameRanking::UserTrophy::UserTrophy(unsigned int nType)
    : IResponse(nType)
{
}

// @0x140b37bb0
int GameRanking::UserTrophy::Read(CByteBuffer& s)
{
    try {
        if (IResponse::Read(s) == 0)
            return 0;
        int nCount = s.ReadInt32();
        for (int i = 0; i < nCount; i++) {
            MS2Ptr<GameRankingItem::UserTrophy> spItem(new GameRankingItem::UserTrophy);
            spItem->Read(s);
            m_ranks.SetAt(spItem->m_rank, spItem);
            m_names.SetAt(spItem->m_name, spItem);
        }
    }
    catch (...) {
        return 0;
    }
    return 1;
}

// @0x140b37d90
MS2Ptr<GameRanking::Page> GameRanking::UserTrophy::GetPage(int nPage)
{
    MS2Ptr<Page> spPage(new Page(m_type, nPage));
    spPage->SetTotal((int)m_ranks.GetCount());
    for (int i = spPage->First(); i <= spPage->Last(); i++) {
        MS2Ptr<GameRankingItem::UserTrophy> spItem(0);
        m_ranks.Lookup(i, spItem);
        if (spItem.get() != 0)
            spPage->Add(i, spItem.get());
    }
    return spPage;
}

// @0x140b37f40
MS2Ptr<GameRanking::Page> GameRanking::UserTrophy::Search(CStringW strName)
{
    MS2Ptr<Page> spPage(new Page(m_type, 1));
    spPage->SetTotal(1);
    MS2Ptr<GameRankingItem::UserTrophy> spItem(0);
    m_names.Lookup(strName, spItem);
    if (spItem == 0)
        return 0;
    spPage->Add(spItem->m_rank, spItem);
    return spPage;
}

// @0x140b38110
void GameRanking::UserTrophy::Merge(CStringW strName, IResponse* pOther)
{
    if (m_names.Lookup(strName) == NULL) {
        UserTrophy* pList = static_cast<UserTrophy*>(pOther);
        if (pList != NULL) {
            if (pList->m_ranks.GetCount() == 0) {
                MS2Ptr<GameRankingItem::UserTrophy> spItem(new GameRankingItem::UserTrophy);
                m_names.SetAt(strName, spItem);
            }
            else {
                for (POSITION pos = pList->m_ranks.GetHeadPosition(); pos != NULL; pList->m_ranks.GetNext(pos))
                    m_names.SetAt(strName, pList->m_ranks.GetValueAt(pos));
            }
        }
    }
}

// @0x140b382a0
GameRanking::DarkStream::DarkStream(unsigned int nType)
    : IResponse(nType)
{
}

// @0x140b38310
int GameRanking::DarkStream::Read(CByteBuffer& s)
{
    try {
        if (IResponse::Read(s) == 0)
            return 0;
        int nCount = s.ReadInt32();
        for (int i = 0; i < nCount; i++) {
            MS2Ptr<GameRankingItem::DarkStream> spItem(new GameRankingItem::DarkStream);
            spItem->Read(s);
            m_ranks.SetAt(spItem->m_rank, spItem);
            m_names.SetAt(spItem->m_name, spItem);
        }
    }
    catch (...) {
        return 0;
    }
    return 1;
}

// @0x140b384f0
MS2Ptr<GameRanking::Page> GameRanking::DarkStream::GetPage(int nPage)
{
    MS2Ptr<Page> spPage(new Page(m_type, nPage));
    spPage->SetTotal((int)m_ranks.GetCount());
    for (int i = spPage->First(); i <= spPage->Last(); i++) {
        MS2Ptr<GameRankingItem::DarkStream> spItem(0);
        m_ranks.Lookup(i, spItem);
        if (spItem.get() != 0)
            spPage->Add(i, spItem.get());
    }
    return spPage;
}

// @0x140b386a0
MS2Ptr<GameRanking::Page> GameRanking::DarkStream::Search(CStringW strName)
{
    MS2Ptr<Page> spPage(new Page(m_type, 1));
    spPage->SetTotal(1);
    MS2Ptr<GameRankingItem::DarkStream> spItem(0);
    m_names.Lookup(strName, spItem);
    if (spItem == 0)
        return 0;
    spPage->Add(spItem->m_rank, spItem);
    return spPage;
}

// @0x140b38870
void GameRanking::DarkStream::Merge(CStringW strName, IResponse* pOther)
{
    if (m_names.Lookup(strName) == NULL) {
        DarkStream* pList = static_cast<DarkStream*>(pOther);
        if (pList != NULL) {
            if (pList->m_ranks.GetCount() == 0) {
                MS2Ptr<GameRankingItem::DarkStream> spItem(new GameRankingItem::DarkStream);
                m_names.SetAt(strName, spItem);
            }
            else {
                for (POSITION pos = pList->m_ranks.GetHeadPosition(); pos != NULL; pList->m_ranks.GetNext(pos))
                    m_names.SetAt(strName, pList->m_ranks.GetValueAt(pos));
            }
        }
    }
}

// @0x140b38a00
GameRanking::UserPvp::UserPvp(unsigned int nType)
    : IResponse(nType)
{
}

// @0x140b38a70
int GameRanking::UserPvp::Read(CByteBuffer& s)
{
    try {
        if (IResponse::Read(s) == 0)
            return 0;
        int nCount = s.ReadInt32();
        for (int i = 0; i < nCount; i++) {
            MS2Ptr<GameRankingItem::UserPvp> spItem(new GameRankingItem::UserPvp);
            spItem->Read(s);
            m_ranks.SetAt(spItem->m_rank, spItem);
            m_names.SetAt(spItem->m_name, spItem);
        }
    }
    catch (...) {
        return 0;
    }
    return 1;
}

// @0x140b38c50
MS2Ptr<GameRanking::Page> GameRanking::UserPvp::GetPage(int nPage)
{
    MS2Ptr<Page> spPage(new Page(m_type, nPage));
    spPage->SetTotal((int)m_ranks.GetCount());
    for (int i = spPage->First(); i <= spPage->Last(); i++) {
        MS2Ptr<GameRankingItem::UserPvp> spItem(0);
        m_ranks.Lookup(i, spItem);
        if (spItem.get() != 0)
            spPage->Add(i, spItem.get());
    }
    return spPage;
}

// @0x140b38e00
MS2Ptr<GameRanking::Page> GameRanking::UserPvp::Search(CStringW strName)
{
    MS2Ptr<Page> spPage(new Page(m_type, 1));
    spPage->SetTotal(1);
    MS2Ptr<GameRankingItem::UserPvp> spItem(0);
    m_names.Lookup(strName, spItem);
    if (spItem == 0)
        return 0;
    spPage->Add(spItem->m_rank, spItem);
    return spPage;
}

// @0x140b38fd0
void GameRanking::UserPvp::Merge(CStringW strName, IResponse* pOther)
{
    if (m_names.Lookup(strName) == NULL) {
        UserPvp* pList = static_cast<UserPvp*>(pOther);
        if (pList != NULL) {
            if (pList->m_ranks.GetCount() == 0) {
                MS2Ptr<GameRankingItem::UserPvp> spItem(new GameRankingItem::UserPvp);
                m_names.SetAt(strName, spItem);
            }
            else {
                for (POSITION pos = pList->m_ranks.GetHeadPosition(); pos != NULL; pList->m_ranks.GetNext(pos))
                    m_names.SetAt(strName, pList->m_ranks.GetValueAt(pos));
            }
        }
    }
}

// @0x140b39160
GameRanking::GuildPvp::GuildPvp(unsigned int nType)
    : IResponse(nType)
{
}

// @0x140b391d0
int GameRanking::GuildPvp::Read(CByteBuffer& s)
{
    try {
        if (IResponse::Read(s) == 0)
            return 0;
        int nCount = s.ReadInt32();
        for (int i = 0; i < nCount; i++) {
            MS2Ptr<GameRankingItem::GuildPvp> spItem(new GameRankingItem::GuildPvp);
            spItem->Read(s);
            m_ranks.SetAt(spItem->m_rank, spItem);
            m_names.SetAt(spItem->m_name, spItem);
        }
    }
    catch (...) {
        return 0;
    }
    return 1;
}

// @0x140b393b0
MS2Ptr<GameRanking::Page> GameRanking::GuildPvp::GetPage(int nPage)
{
    MS2Ptr<Page> spPage(new Page(m_type, nPage));
    spPage->SetTotal((int)m_ranks.GetCount());
    for (int i = spPage->First(); i <= spPage->Last(); i++) {
        MS2Ptr<GameRankingItem::GuildPvp> spItem(0);
        m_ranks.Lookup(i, spItem);
        if (spItem.get() != 0)
            spPage->Add(i, spItem.get());
    }
    return spPage;
}

// @0x140b39560
MS2Ptr<GameRanking::Page> GameRanking::GuildPvp::Search(CStringW strName)
{
    MS2Ptr<Page> spPage(new Page(m_type, 1));
    spPage->SetTotal(1);
    MS2Ptr<GameRankingItem::GuildPvp> spItem(0);
    m_names.Lookup(strName, spItem);
    if (spItem == 0)
        return 0;
    spPage->Add(spItem->m_rank, spItem);
    return spPage;
}

// @0x140b39730
void GameRanking::GuildPvp::Merge(CStringW strName, IResponse* pOther)
{
    if (m_names.Lookup(strName) == NULL) {
        GuildPvp* pList = static_cast<GuildPvp*>(pOther);
        if (pList != NULL) {
            if (pList->m_ranks.GetCount() == 0) {
                MS2Ptr<GameRankingItem::GuildPvp> spItem(new GameRankingItem::GuildPvp);
                m_names.SetAt(strName, spItem);
            }
            else {
                for (POSITION pos = pList->m_ranks.GetHeadPosition(); pos != NULL; pList->m_ranks.GetNext(pos))
                    m_names.SetAt(strName, pList->m_ranks.GetValueAt(pos));
            }
        }
    }
}

// @0x140b398c0
GameRanking::UgcMapCommendation::UgcMapCommendation(unsigned int nType)
    : IResponse(nType)
{
}

// @0x140b39930
int GameRanking::UgcMapCommendation::Read(CByteBuffer& s)
{
    try {
        if (IResponse::Read(s) == 0)
            return 0;
        int nCount = s.ReadInt32();
        for (int i = 0; i < nCount; i++) {
            MS2Ptr<GameRankingItem::UgcMapCommendation> spItem(new GameRankingItem::UgcMapCommendation);
            spItem->Read(s);
            m_ranks.SetAt(spItem->m_rank, spItem);
            m_names.SetAt(spItem->m_name, spItem);
        }
    }
    catch (...) {
        return 0;
    }
    return 1;
}

// @0x140b39b10
MS2Ptr<GameRanking::Page> GameRanking::UgcMapCommendation::GetPage(int nPage)
{
    MS2Ptr<Page> spPage(new Page(m_type, nPage));
    spPage->SetTotal((int)m_ranks.GetCount());
    for (int i = spPage->First(); i <= spPage->Last(); i++) {
        MS2Ptr<GameRankingItem::UgcMapCommendation> spItem(0);
        m_ranks.Lookup(i, spItem);
        if (spItem.get() != 0)
            spPage->Add(i, spItem.get());
    }
    return spPage;
}

// @0x140b39cc0
MS2Ptr<GameRanking::Page> GameRanking::UgcMapCommendation::Search(CStringW strName)
{
    MS2Ptr<Page> spPage(new Page(m_type, 1));
    spPage->SetTotal(1);
    MS2Ptr<GameRankingItem::UgcMapCommendation> spItem(0);
    m_names.Lookup(strName, spItem);
    if (spItem == 0)
        return 0;
    spPage->Add(spItem->m_rank, spItem);
    return spPage;
}

// @0x140b39e90
void GameRanking::UgcMapCommendation::Merge(CStringW strName, IResponse* pOther)
{
    if (m_names.Lookup(strName) == NULL) {
        UgcMapCommendation* pList = static_cast<UgcMapCommendation*>(pOther);
        if (pList != NULL) {
            if (pList->m_ranks.GetCount() == 0) {
                MS2Ptr<GameRankingItem::UgcMapCommendation> spItem(new GameRankingItem::UgcMapCommendation);
                m_names.SetAt(strName, spItem);
            }
            else {
                for (POSITION pos = pList->m_ranks.GetHeadPosition(); pos != NULL; pList->m_ranks.GetNext(pos))
                    m_names.SetAt(strName, pList->m_ranks.GetValueAt(pos));
            }
        }
    }
}

// @0x140b3a020
GameRanking::BossKillCount::BossKillCount(unsigned int nType)
    : IResponse(nType)
{
}

// @0x140b3a090
int GameRanking::BossKillCount::Read(CByteBuffer& s)
{
    try {
        if (IResponse::Read(s) == 0)
            return 0;
        int nCount = s.ReadInt32();
        for (int i = 0; i < nCount; i++) {
            MS2Ptr<GameRankingItem::BossKillCount> spItem(new GameRankingItem::BossKillCount);
            spItem->Read(s);
            m_ranks.SetAt(spItem->m_rank, spItem);
            m_names.SetAt(spItem->m_name, spItem);
        }
    }
    catch (...) {
        return 0;
    }
    return 1;
}

// @0x140b3a270
MS2Ptr<GameRanking::Page> GameRanking::BossKillCount::GetPage(int nPage)
{
    MS2Ptr<Page> spPage(new Page(m_type, nPage));
    spPage->SetTotal((int)m_ranks.GetCount());
    for (int i = spPage->First(); i <= spPage->Last(); i++) {
        MS2Ptr<GameRankingItem::BossKillCount> spItem(0);
        m_ranks.Lookup(i, spItem);
        if (spItem.get() != 0)
            spPage->Add(i, spItem.get());
    }
    return spPage;
}

// @0x140b3a420
MS2Ptr<GameRanking::Page> GameRanking::BossKillCount::Search(CStringW strName)
{
    MS2Ptr<Page> spPage(new Page(m_type, 1));
    spPage->SetTotal(1);
    MS2Ptr<GameRankingItem::BossKillCount> spItem(0);
    m_names.Lookup(strName, spItem);
    if (spItem == 0)
        return 0;
    spPage->Add(spItem->m_rank, spItem);
    return spPage;
}

// @0x140b3a5f0
void GameRanking::BossKillCount::Merge(CStringW strName, IResponse* pOther)
{
    if (m_names.Lookup(strName) == NULL) {
        BossKillCount* pList = static_cast<BossKillCount*>(pOther);
        if (pList != NULL) {
            if (pList->m_ranks.GetCount() == 0) {
                MS2Ptr<GameRankingItem::BossKillCount> spItem(new GameRankingItem::BossKillCount);
                m_names.SetAt(strName, spItem);
            }
            else {
                for (POSITION pos = pList->m_ranks.GetHeadPosition(); pos != NULL; pList->m_ranks.GetNext(pos))
                    m_names.SetAt(strName, pList->m_ranks.GetValueAt(pos));
            }
        }
    }
}

// @0x140b3a780
GameRanking::BossKillRecord::BossKillRecord(unsigned int nType)
    : IResponse(nType)
{
}

// MS2-FUNCTIONAL: the exe frame is 0x10 larger (an unused slot); the code is identical
// @0x140b3a7d0
int GameRanking::BossKillRecord::Read(CByteBuffer& s)
{
    try {
        if (IResponse::Read(s) == 0)
            return 0;
        int nCount = s.ReadInt32();
        for (int i = 0; i < nCount; i++) {
            MS2Ptr<GameRankingItem::BossKillRecord> spItem(new GameRankingItem::BossKillRecord);
            spItem->Read(s);
            m_ranks.SetAt(spItem->m_rank, spItem);
        }
    }
    catch (...) {
        return 0;
    }
    return 1;
}

// @0x140b3a970
MS2Ptr<GameRanking::Page> GameRanking::BossKillRecord::GetPage(int nPage)
{
    MS2Ptr<Page> spPage(new Page(m_type, nPage));
    spPage->SetTotal((int)m_ranks.GetCount());
    for (int i = spPage->First(); i <= spPage->Last(); i++) {
        MS2Ptr<GameRankingItem::BossKillRecord> spItem(0);
        m_ranks.Lookup(i, spItem);
        if (spItem.get() != 0)
            spPage->Add(i, spItem.get());
    }
    return spPage;
}

// @0x140b3ab20
GameRanking::Arcade::Arcade(unsigned int nType)
    : IResponse(nType)
{
}

// @0x140b3ab90
int GameRanking::Arcade::Read(CByteBuffer& s)
{
    try {
        if (IResponse::Read(s) == 0)
            return 0;
        int nCount = s.ReadInt32();
        for (int i = 0; i < nCount; i++) {
            MS2Ptr<GameRankingItem::Arcade> spItem(new GameRankingItem::Arcade);
            spItem->Read(s);
            m_ranks.SetAt(spItem->m_rank, spItem);
            m_names.SetAt(spItem->m_name, spItem);
        }
    }
    catch (...) {
        return 0;
    }
    return 1;
}

// @0x140b3ad70
MS2Ptr<GameRanking::Page> GameRanking::Arcade::GetPage(int nPage)
{
    MS2Ptr<Page> spPage(new Page(m_type, nPage));
    spPage->SetTotal((int)m_ranks.GetCount());
    for (int i = spPage->First(); i <= spPage->Last(); i++) {
        MS2Ptr<GameRankingItem::Arcade> spItem(0);
        m_ranks.Lookup(i, spItem);
        if (spItem.get() != 0)
            spPage->Add(i, spItem.get());
    }
    return spPage;
}

// @0x140b3af20
MS2Ptr<GameRanking::Page> GameRanking::Arcade::Search(CStringW strName)
{
    MS2Ptr<Page> spPage(new Page(m_type, 1));
    spPage->SetTotal(1);
    MS2Ptr<GameRankingItem::Arcade> spItem(0);
    m_names.Lookup(strName, spItem);
    if (spItem == 0)
        return 0;
    spPage->Add(spItem->m_rank, spItem);
    return spPage;
}

// @0x140b3b0f0
void GameRanking::Arcade::Merge(CStringW strName, IResponse* pOther)
{
    if (m_names.Lookup(strName) == NULL) {
        Arcade* pList = static_cast<Arcade*>(pOther);
        if (pList != NULL) {
            if (pList->m_ranks.GetCount() == 0) {
                MS2Ptr<GameRankingItem::Arcade> spItem(new GameRankingItem::Arcade);
                m_names.SetAt(strName, spItem);
            }
            else {
                for (POSITION pos = pList->m_ranks.GetHeadPosition(); pos != NULL; pList->m_ranks.GetNext(pos))
                    m_names.SetAt(strName, pList->m_ranks.GetValueAt(pos));
            }
        }
    }
}

// @0x140b3b280
GameRanking::BossDamageCount::BossDamageCount(unsigned int nType)
    : IResponse(nType)
{
}

// @0x140b3b2f0
int GameRanking::BossDamageCount::Read(CByteBuffer& s)
{
    try {
        if (IResponse::Read(s) == 0)
            return 0;
        int nCount = s.ReadInt32();
        for (int i = 0; i < nCount; i++) {
            MS2Ptr<GameRankingItem::BossDamageCount> spItem(new GameRankingItem::BossDamageCount);
            spItem->Read(s);
            m_ranks.SetAt(spItem->m_rank, spItem);
            m_names.SetAt(spItem->m_name, spItem);
        }
    }
    catch (...) {
        return 0;
    }
    return 1;
}

// @0x140b3b4d0
MS2Ptr<GameRanking::Page> GameRanking::BossDamageCount::GetPage(int nPage)
{
    MS2Ptr<Page> spPage(new Page(m_type, nPage));
    spPage->SetTotal((int)m_ranks.GetCount());
    for (int i = spPage->First(); i <= spPage->Last(); i++) {
        MS2Ptr<GameRankingItem::BossDamageCount> spItem(0);
        m_ranks.Lookup(i, spItem);
        if (spItem.get() != 0)
            spPage->Add(i, spItem.get());
    }
    return spPage;
}

// @0x140b3b680
MS2Ptr<GameRanking::Page> GameRanking::BossDamageCount::Search(CStringW strName)
{
    MS2Ptr<Page> spPage(new Page(m_type, 1));
    spPage->SetTotal(1);
    MS2Ptr<GameRankingItem::BossDamageCount> spItem(0);
    m_names.Lookup(strName, spItem);
    if (spItem == 0)
        return 0;
    spPage->Add(spItem->m_rank, spItem);
    return spPage;
}

// @0x140b3b850
void GameRanking::BossDamageCount::Merge(CStringW strName, IResponse* pOther)
{
    if (m_names.Lookup(strName) == NULL) {
        BossDamageCount* pList = static_cast<BossDamageCount*>(pOther);
        if (pList != NULL) {
            if (pList->m_ranks.GetCount() == 0) {
                MS2Ptr<GameRankingItem::BossDamageCount> spItem(new GameRankingItem::BossDamageCount);
                m_names.SetAt(strName, spItem);
            }
            else {
                for (POSITION pos = pList->m_ranks.GetHeadPosition(); pos != NULL; pList->m_ranks.GetNext(pos))
                    m_names.SetAt(strName, pList->m_ranks.GetValueAt(pos));
            }
        }
    }
}

// @0x140b3b9e0
GameRanking::BossDamageDate::BossDamageDate(unsigned int nType)
    : IResponse(nType)
{
}

// MS2-FUNCTIONAL: the exe frame is 0x10 larger (an unused slot); the code is identical
// @0x140b3ba30
int GameRanking::BossDamageDate::Read(CByteBuffer& s)
{
    try {
        if (IResponse::Read(s) == 0)
            return 0;
        int nCount = s.ReadInt32();
        for (int i = 0; i < nCount; i++) {
            MS2Ptr<GameRankingItem::BossDamageDate> spItem(new GameRankingItem::BossDamageDate);
            spItem->Read(s);
            m_ranks.SetAt(spItem->m_rank, spItem);
        }
    }
    catch (...) {
        return 0;
    }
    return 1;
}

// @0x140b3bbd0
MS2Ptr<GameRanking::Page> GameRanking::BossDamageDate::GetPage(int nPage)
{
    MS2Ptr<Page> spPage(new Page(m_type, nPage));
    spPage->SetTotal((int)m_ranks.GetCount());
    for (int i = spPage->First(); i <= spPage->Last(); i++) {
        MS2Ptr<GameRankingItem::BossDamageDate> spItem(0);
        m_ranks.Lookup(i, spItem);
        if (spItem.get() != 0)
            spPage->Add(i, spItem.get());
    }
    return spPage;
}

// @0x140b3bd80
GameRanking::BossDamageAmount::BossDamageAmount(unsigned int nType)
    : IResponse(nType)
{
}

// MS2-FUNCTIONAL: the exe frame is 0x10 larger (an unused slot); the code is identical
// @0x140b3bdd0
int GameRanking::BossDamageAmount::Read(CByteBuffer& s)
{
    try {
        if (IResponse::Read(s) == 0)
            return 0;
        int nCount = s.ReadInt32();
        for (int i = 0; i < nCount; i++) {
            MS2Ptr<GameRankingItem::BossDamageAmount> spItem(new GameRankingItem::BossDamageAmount);
            spItem->Read(s);
            m_ranks.SetAt(spItem->m_rank, spItem);
        }
    }
    catch (...) {
        return 0;
    }
    return 1;
}

// @0x140b3bf70
MS2Ptr<GameRanking::Page> GameRanking::BossDamageAmount::GetPage(int nPage)
{
    MS2Ptr<Page> spPage(new Page(m_type, nPage));
    spPage->SetTotal((int)m_ranks.GetCount());
    for (int i = spPage->First(); i <= spPage->Last(); i++) {
        MS2Ptr<GameRankingItem::BossDamageAmount> spItem(0);
        m_ranks.Lookup(i, spItem);
        if (spItem.get() != 0)
            spPage->Add(i, spItem.get());
    }
    return spPage;
}

// @0x140b3c120
GameRanking::BossRumbleCount::BossRumbleCount(unsigned int nType)
    : IResponse(nType)
{
}

// @0x140b3c190
int GameRanking::BossRumbleCount::Read(CByteBuffer& s)
{
    try {
        if (IResponse::Read(s) == 0)
            return 0;
        int nCount = s.ReadInt32();
        for (int i = 0; i < nCount; i++) {
            MS2Ptr<GameRankingItem::BossRumbleCount> spItem(new GameRankingItem::BossRumbleCount);
            spItem->Read(s);
            m_ranks.SetAt(spItem->m_rank, spItem);
            m_names.SetAt(spItem->m_name, spItem);
        }
    }
    catch (...) {
        return 0;
    }
    return 1;
}

// @0x140b3c370
MS2Ptr<GameRanking::Page> GameRanking::BossRumbleCount::GetPage(int nPage)
{
    MS2Ptr<Page> spPage(new Page(m_type, nPage));
    spPage->SetTotal((int)m_ranks.GetCount());
    for (int i = spPage->First(); i <= spPage->Last(); i++) {
        MS2Ptr<GameRankingItem::BossRumbleCount> spItem(0);
        m_ranks.Lookup(i, spItem);
        if (spItem.get() != 0)
            spPage->Add(i, spItem.get());
    }
    return spPage;
}

// @0x140b3c520
MS2Ptr<GameRanking::Page> GameRanking::BossRumbleCount::Search(CStringW strName)
{
    MS2Ptr<Page> spPage(new Page(m_type, 1));
    spPage->SetTotal(1);
    MS2Ptr<GameRankingItem::BossRumbleCount> spItem(0);
    m_names.Lookup(strName, spItem);
    if (spItem == 0)
        return 0;
    spPage->Add(spItem->m_rank, spItem);
    return spPage;
}

// @0x140b3c6f0
void GameRanking::BossRumbleCount::Merge(CStringW strName, IResponse* pOther)
{
    if (m_names.Lookup(strName) == NULL) {
        BossRumbleCount* pList = static_cast<BossRumbleCount*>(pOther);
        if (pList != NULL) {
            if (pList->m_ranks.GetCount() == 0) {
                MS2Ptr<GameRankingItem::BossRumbleCount> spItem(new GameRankingItem::BossRumbleCount);
                m_names.SetAt(strName, spItem);
            }
            else {
                for (POSITION pos = pList->m_ranks.GetHeadPosition(); pos != NULL; pList->m_ranks.GetNext(pos))
                    m_names.SetAt(strName, pList->m_ranks.GetValueAt(pos));
            }
        }
    }
}

// @0x140b3c880
GameRanking::BossRumbleRecord::BossRumbleRecord(unsigned int nType)
    : IResponse(nType)
{
}

// MS2-FUNCTIONAL: the exe frame is 0x10 larger (an unused slot); the code is identical
// @0x140b3c8d0
int GameRanking::BossRumbleRecord::Read(CByteBuffer& s)
{
    try {
        if (IResponse::Read(s) == 0)
            return 0;
        int nCount = s.ReadInt32();
        for (int i = 0; i < nCount; i++) {
            MS2Ptr<GameRankingItem::BossRumbleRecord> spItem(new GameRankingItem::BossRumbleRecord);
            spItem->Read(s);
            m_ranks.SetAt(spItem->m_rank, spItem);
        }
    }
    catch (...) {
        return 0;
    }
    return 1;
}

// @0x140b3ca70
MS2Ptr<GameRanking::Page> GameRanking::BossRumbleRecord::GetPage(int nPage)
{
    MS2Ptr<Page> spPage(new Page(m_type, nPage));
    spPage->SetTotal((int)m_ranks.GetCount());
    for (int i = spPage->First(); i <= spPage->Last(); i++) {
        MS2Ptr<GameRankingItem::BossRumbleRecord> spItem(0);
        m_ranks.Lookup(i, spItem);
        if (spItem.get() != 0)
            spPage->Add(i, spItem.get());
    }
    return spPage;
}

// @0x140b3cc20
GameRanking::WorldChampion::WorldChampion(unsigned int nType)
    : IResponse(nType)
{
}

// @0x140b3cc90
int GameRanking::WorldChampion::Read(CByteBuffer& s)
{
    try {
        if (IResponse::Read(s) == 0)
            return 0;
        int nCount = s.ReadInt32();
        for (int i = 0; i < nCount; i++) {
            MS2Ptr<GameRankingItem::WorldChampion> spItem(new GameRankingItem::WorldChampion);
            spItem->Read(s);
            m_ranks.SetAt(spItem->m_rank, spItem);
            m_names.SetAt(spItem->m_name, spItem);
        }
    }
    catch (...) {
        return 0;
    }
    return 1;
}

// @0x140b3ce70
MS2Ptr<GameRanking::Page> GameRanking::WorldChampion::GetPage(int nPage)
{
    MS2Ptr<Page> spPage(new Page(m_type, nPage));
    spPage->SetTotal((int)m_ranks.GetCount());
    for (int i = spPage->First(); i <= spPage->Last(); i++) {
        MS2Ptr<GameRankingItem::WorldChampion> spItem(0);
        m_ranks.Lookup(i, spItem);
        if (spItem.get() != 0)
            spPage->Add(i, spItem.get());
    }
    return spPage;
}

// @0x140b3d020
MS2Ptr<GameRanking::Page> GameRanking::WorldChampion::Search(CStringW strName)
{
    MS2Ptr<Page> spPage(new Page(m_type, 1));
    spPage->SetTotal(1);
    MS2Ptr<GameRankingItem::WorldChampion> spItem(0);
    m_names.Lookup(strName, spItem);
    if (spItem == 0)
        return 0;
    spPage->Add(spItem->m_rank, spItem);
    return spPage;
}

// @0x140b3d1f0
void GameRanking::WorldChampion::Merge(CStringW strName, IResponse* pOther)
{
    if (m_names.Lookup(strName) == NULL) {
        WorldChampion* pList = static_cast<WorldChampion*>(pOther);
        if (pList != NULL) {
            if (pList->m_ranks.GetCount() == 0) {
                MS2Ptr<GameRankingItem::WorldChampion> spItem(new GameRankingItem::WorldChampion);
                m_names.SetAt(strName, spItem);
            }
            else {
                for (POSITION pos = pList->m_ranks.GetHeadPosition(); pos != NULL; pList->m_ranks.GetNext(pos))
                    m_names.SetAt(strName, pList->m_ranks.GetValueAt(pos));
            }
        }
    }
}

// @0x140b3d380
GameRanking::BossColosseum::BossColosseum(unsigned int nType)
    : IResponse(nType)
{
}

// @0x140b3d3f0
int GameRanking::BossColosseum::Read(CByteBuffer& s)
{
    try {
        if (IResponse::Read(s) == 0)
            return 0;
        int nCount = s.ReadInt32();
        for (int i = 0; i < nCount; i++) {
            MS2Ptr<GameRankingItem::BossColosseum> spItem(new GameRankingItem::BossColosseum);
            spItem->Read(s);
            m_ranks.SetAt(spItem->m_rank, spItem);
            m_names.SetAt(spItem->m_name, spItem);
        }
    }
    catch (...) {
        return 0;
    }
    return 1;
}

// @0x140b3d5d0
MS2Ptr<GameRanking::Page> GameRanking::BossColosseum::GetPage(int nPage)
{
    MS2Ptr<Page> spPage(new Page(m_type, nPage));
    spPage->SetTotal((int)m_ranks.GetCount());
    for (int i = spPage->First(); i <= spPage->Last(); i++) {
        MS2Ptr<GameRankingItem::BossColosseum> spItem(0);
        m_ranks.Lookup(i, spItem);
        if (spItem.get() != 0)
            spPage->Add(i, spItem.get());
    }
    return spPage;
}

// @0x140b3d780
MS2Ptr<GameRanking::Page> GameRanking::BossColosseum::Search(CStringW strName)
{
    MS2Ptr<Page> spPage(new Page(m_type, 1));
    spPage->SetTotal(1);
    MS2Ptr<GameRankingItem::BossColosseum> spItem(0);
    m_names.Lookup(strName, spItem);
    if (spItem == 0)
        return 0;
    spPage->Add(spItem->m_rank, spItem);
    return spPage;
}

// @0x140b3d950
void GameRanking::BossColosseum::Merge(CStringW strName, IResponse* pOther)
{
    if (m_names.Lookup(strName) == NULL) {
        BossColosseum* pList = static_cast<BossColosseum*>(pOther);
        if (pList != NULL) {
            if (pList->m_ranks.GetCount() == 0) {
                MS2Ptr<GameRankingItem::BossColosseum> spItem(new GameRankingItem::BossColosseum);
                m_names.SetAt(strName, spItem);
            }
            else {
                for (POSITION pos = pList->m_ranks.GetHeadPosition(); pos != NULL; pList->m_ranks.GetNext(pos))
                    m_names.SetAt(strName, pList->m_ranks.GetValueAt(pos));
            }
        }
    }
}

// ---- GameRanking::Page ----

// @0x140b3dae0
GameRanking::Page::Page(int nType, int nPage)
    : m_items(10)
{
    m_type = nType;
    m_page = nPage;
    m_first = (nPage - 1) * 10 + 1;
    m_last = nPage * 10;
    m_total = 0;
}

// @0x140b3db80
GameRanking::Page::~Page()
{
    m_items.RemoveAll();
}

// @0x140b3dbd0
void GameRanking::Page::Add(int nRank, GameRankingItem::IRankItem* pItem)
{
    if (pItem == 0)
        return;
    MS2Ptr<GameRankingItem::IRankItem> spItem(pItem);
    m_items.SetAt(nRank, spItem);
}
MS2_REPLACE_METHOD(0x140b3dbd0, GameRanking::Page, Add, 95, 0x0EBDB178);

// @0x140b3dc40
MS2Ptr<GameRankingItem::IRankItem> GameRanking::Page::GetItem(int nRank)
{
    MS2Ptr<GameRankingItem::IRankItem> spItem(0);
    m_items.Lookup(nRank, spItem);
    return spItem;
}
MS2_REPLACE_METHOD(0x140b3dc40, GameRanking::Page, GetItem, 121, 0x57A94644);

// @0x140b3dcc0
MS2Ptr<GameRankingItem::IRankItem> GameRanking::Page::GetFirstItem()
{
    MS2Ptr<GameRankingItem::IRankItem> spItem(0);
    POSITION pos = m_items.GetHeadPosition();
    if (pos != 0)
        spItem = m_items.GetValueAt(pos);
    return spItem;
}
MS2_REPLACE_METHOD(0x140b3dcc0, GameRanking::Page, GetFirstItem, 155, 0x262B168D);

// ---- CGameRankingParam / CGameRankingWebResult ----

// @0x140b3dd70
CGameRankingParam::CGameRankingParam()
{
    m_key.Clear();
    m_24 = DAT_143ab2830;
    m_28 = DAT_143ab2820;
    m_30 = DAT_143ab2828;
    m_38 = 0;
    m_search = L"";
}

// @0x140b3de40
void CGameRankingParam::Copy(const CGameRankingParam* pParam)
{
    if (pParam == 0)
        return;
    m_key = pParam->m_key;
    m_38 = pParam->m_38;
    m_search = pParam->m_search;
}

// @0x140b3deb0
CGameRankingWebResult::CGameRankingWebResult()
{
    m_result = 1;
    m_buffer.FUN_140518490();
}

// @0x140b3df20
CGameRankingWebResult::CGameRankingWebResult(int nResult)
{
    m_result = nResult;
    m_buffer.FUN_140518490();
}

// ---- helpers ----

// The yyyymm month nMonths before the month of nTime.
// @0x140b3df90
int FUN_140b3df90(__int64 nTime, int nMonths)
{
    CMsTime t(nTime);
    int nYears = nMonths / 12;
    int nRest = nMonths % 12;
    int nYear = t.GetYear() - nYears;
    int nMonth = t.GetMonth() - nRest;
    if (nMonth > 12) {
        nYear = nYear + 1;
        nMonth = nMonth - 12;
    }
    else if (nMonth < 1) {
        nYear = nYear - 1;
        nMonth = nMonth + 12;
    }
    int nYearMonth = nYear * 100 + nMonth;
    return nYearMonth;
}

// The first and the last second of the yyyymm month.
// @0x140b3e050
void FUN_140b3e050(int nYearMonth, __int64& nBegin, __int64& nEnd)
{
    int nYear = nYearMonth / 100;
    int nMonth = nYearMonth % 100;
    CMsTime tBegin(nYear, nMonth, 1, 0, 0, 0);
    nBegin = tBegin.Get();
    nMonth++;
    if (nMonth > 12) {
        nYear++;
        nMonth = 1;
    }
    CMsTime tEnd(nYear, nMonth, 1, 0, 0, 0);
    nEnd = tEnd.Get() - 1;
}

// The yyyymmdd ranking day (it changes at 2 o'clock).
// @0x140b3e150
int FUN_140b3e150()
{
    CMsTime t(GetServerTime());
    if (t.GetHour() < 2) {
        ATL::CTimeSpan span(1, 0, 0, 0);
        t = t - span;
    }
    int nDay = t.GetYear() * 10000 + t.GetMonth() * 100 + t.GetDay();
    return nDay;
}

// The board (dialog tab) of a board type; the boss boards by the dungeon group of the room.
// @0x140b3e210
int FUN_140b3e210(CGameRankingParam::Key key)
{
    int nType = key.m_type;
    int nRoom = key.m_sub;
    if (nType == 0xb || nType == 0xc || nType == 0xd || nType == 0xe)
        return 1;
    else if (nType == 0x15 || nType == 0x16 || nType == 0x17 || nType == 0x18)
        return 2;
    else if (nType == 0x1f || nType == 0x20 || nType == 0x21 || nType == 0x22)
        return 3;
    else if (nType == 0x29 || nType == 0x2a || nType == 0x2b || nType == 0x2c)
        return 4;
    else if (nType == 0x33 || nType == 0x34 || nType == 0x35 || nType == 0x36)
        return 5;
    else if (nType == 0x3d || nType == 0x3e || nType == 0x3f || nType == 0x40)
        return 6;
    else if (nType == 0x47 || nType == 0x48 || nType == 0x51 || nType == 0x5b) {
        DungeonRoomPtr spRoom = FUN_14031c2a0()->GetRoom(nRoom);
        if (spRoom.get() != 0) {
            if (spRoom->m_groupType == 2)
                return 7;
            else if (spRoom->m_groupType == 3)
                return 8;
            else if (spRoom->m_groupType == 4)
                return 9;
            else if (spRoom->m_groupType == 5)
                return 0xf;
            else if (spRoom->m_gearScore == 0xe)
                return 0x11;
        }
        return 7;
    }
    else if (nType == 0x65 || nType == 0x66 || nType == 0x67 || nType == 0x68)
        return 10;
    else if (nType == 0x6f || nType == 0x70 || nType == 0x79 || nType == 0x83 || nType == 0x84)
        return 0xb;
    else if (nType == 0x8d || nType == 0x8e || nType == 0x97 || nType == 0xa1 || nType == 0xa2)
        return 0xc;
    else if (nType == 0xb5 || nType == 0xb6 || nType == 0xb7 || nType == 0xb8)
        return 0xe;
    else if (nType == 0xc9 || nType == 0xca || nType == 0xcb || nType == 0xcc)
        return 0x10;
    return 0;
}

// Whether the board type is a personal (own rank) board.
// @0x140b3e700
int FUN_140b3e700(int nType)
{
    if (nType == 0xb || nType == 0xc || nType == 0x15 || nType == 0x16 || nType == 0x1f || nType == 0x20 ||
        nType == 0x29 || nType == 0x2a || nType == 0x33 || nType == 0x34 || nType == 0x3d || nType == 0x3e ||
        nType == 0x47 || nType == 0x65 || nType == 0x66 || nType == 0x6f || nType == 0x83 || nType == 0x8d ||
        nType == 0xa1 || nType == 0xb5 || nType == 0xb6 || nType == 0xc9 || nType == 0xca)
        return 1;
    return 0;
}

// The row object of a board type.
// @0x140b3e7f0
MS2Ptr<GameRankingItem::IRankItem> FUN_140b3e7f0(int nType)
{
    MS2Ptr<GameRankingItem::IRankItem> spItem(0);
    switch (nType) {
    case 0xd: spItem.AssignRaw(new GameRankingItem::GuildTrophy); break;
    case 0xe: spItem.AssignRaw(new GameRankingItem::GuildTrophy); break;
    case 0x17: spItem.AssignRaw(new GameRankingItem::UserTrophy); break;
    case 0x18: spItem.AssignRaw(new GameRankingItem::UserTrophy); break;
    case 0x21: spItem.AssignRaw(new GameRankingItem::DarkStream); break;
    case 0x22: spItem.AssignRaw(new GameRankingItem::DarkStream); break;
    case 0x2b: spItem.AssignRaw(new GameRankingItem::UserPvp); break;
    case 0x2c: spItem.AssignRaw(new GameRankingItem::UserPvp); break;
    case 0x35: spItem.AssignRaw(new GameRankingItem::GuildPvp); break;
    case 0x36: spItem.AssignRaw(new GameRankingItem::GuildPvp); break;
    case 0x3f: spItem.AssignRaw(new GameRankingItem::UgcMapCommendation); break;
    case 0x40: spItem.AssignRaw(new GameRankingItem::UgcMapCommendation); break;
    case 0x48: spItem.AssignRaw(new GameRankingItem::BossKillCount); break;
    case 0x51: spItem.AssignRaw(new GameRankingItem::BossKillRecord); break;
    case 0x5b: spItem.AssignRaw(new GameRankingItem::BossKillRecord); break;
    case 0x67: spItem.AssignRaw(new GameRankingItem::Arcade); break;
    case 0x68: spItem.AssignRaw(new GameRankingItem::Arcade); break;
    case 0x70: spItem.AssignRaw(new GameRankingItem::BossDamageCount); break;
    case 0x79: spItem.AssignRaw(new GameRankingItem::BossDamageDate); break;
    case 0x84: spItem.AssignRaw(new GameRankingItem::BossDamageAmount); break;
    case 0x8e: spItem.AssignRaw(new GameRankingItem::BossRumbleCount); break;
    case 0x97: spItem.AssignRaw(new GameRankingItem::BossRumbleRecord); break;
    case 0xa2: spItem.AssignRaw(new GameRankingItem::BossRumbleRecord); break;
    case 0xb7: spItem.AssignRaw(new GameRankingItem::WorldChampion); break;
    case 0xb8: spItem.AssignRaw(new GameRankingItem::WorldChampion); break;
    case 0xcb: spItem.AssignRaw(new GameRankingItem::BossColosseum); break;
    case 0xcc: spItem.AssignRaw(new GameRankingItem::BossColosseum); break;
    }
    return spItem;
}

// The ranking dialog tab index of a board.
// @0x140b3f460
int FUN_140b3f460(int nBoard)
{
    if (nBoard == 10)
        return 4;
    else if (nBoard == 3)
        return 0;
    else if (nBoard == 5)
        return 2;
    else if (nBoard == 4)
        return 1;
    else if (nBoard == 6)
        return 3;
    else if (nBoard == 0xe)
        return 6;
    else if (nBoard == 0x10)
        return 8;
    return -1;
}

// A length-prefixed UTF-16 string of the answer.
// @0x140b3f4e0
CStringW FUN_140b3f4e0(CByteBuffer& s)
{
    int nLength = s.ReadInt32();
    unsigned char* pBuffer = new unsigned char[nLength + 2];
    memset(pBuffer, 0, nLength + 2);
    s.ReadBytes(pBuffer, nLength);
    CStringW str(reinterpret_cast<wchar_t*>(pBuffer));
    if (pBuffer != NULL) {
        delete[] pBuffer;
        pBuffer = NULL;
    }
    return str;
}

// A "yyyy-mm-dd hh:mm:ss" date of the answer.
// @0x140b3f610
__int64 FUN_140b3f610(CByteBuffer& s)
{
    CStringW str = FUN_140b3f4e0(s);
    int nYear = _wtoi(str.Mid(0, 4));
    int nMonth = _wtoi(str.Mid(5, 2));
    int nDay = _wtoi(str.Mid(8, 2));
    int nHour = _wtoi(str.Mid(11, 2));
    int nMinute = _wtoi(str.Mid(14, 2));
    int nSecond = _wtoi(str.Mid(17, 2));
    CMsTime t(nYear, nMonth, nDay, nHour, nMinute, nSecond);
    return t.Get();
}
