// maplesurvival.cpp - Mushking Royale (Maple Survival) restore. NOT recovered KMS code and not byte-matched: the KMS
// 2022 client dropped the feature's manager, storm handler and tables. Rebuilt from the unprotected GMS 2019 x86 client;
// the "GMS 0x..." VAs in the comments are that exe's (image base 0x400000), not KMS VAs.
// Build: MS2-NO-EXE puts the unit in the full-exe link only (tools/fullexe/plan.py places it at the VA below); the
// byte-match gates and the headline totals list it as "stubbed (excluded)", and the hook DLL gets an empty TU.
// The unit hooks itself in at run time (MushkingRestoreInit, called from CGameApp::InitInstance): the recv ops through
// PacketHandlerManager::RegisterHandler, the GameEvent switches through the ClassObject registry. KMS code paths are
// unchanged: the raw server never sends Survival / SurvivalEvent packets, so nothing here runs against it.
// MS2-UNIT: maplesurvival
// MS2-NO-EXE: 0x140db5391 Mushking Royale restore (restore/mushking only)
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"

#ifndef MS2_HOOK_DLL

#include <set>
#include "ms2/client/ms2/maplesurvival.h"
#include "ms2/client/ms2/maplesurvivalui.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/notifyobject.h"
#include "ms2/placeholder/notifysystem.h"
#include "ms2/placeholder/packethandlermanager.h"
#include "ms2/placeholder/classobject.h"
#include "ms2/placeholder/stringxmlproc.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/tixmlelement.h"
#include "ms2/commonfiles/filesystem.h"
#include "ms2/commonfiles/gameevent.h"
#include "ms2/client/ms2/uimessageboxdata.h"
#include "ms2/client/ms2/notifychangebuff.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/client/ms2/pcbase.h"
#include "ms2/placeholder/fittingdollpc.h"
#include "ms2/client/ms2/partymanager.h"

// ---- KMS helpers (declarations as their other callers have them) ----
CStringW GetStringCommonByKey(const CStringW& strKey);
CStringW GetStringCommon(int nId);
void ShowSystemNotice(const CStringW& strText, int nType, int nFlag);   // GMS 0xa1fd00 (text, 2, 1)
int PlaySystemSound(const CString& strName, const CString& strExtra);
void FUN_140710590(COutPacket& packet);                                  // send
bool SendPacketThrottled(COutPacket* packet, int key, int delay);
MS2Ptr<CMsgBoxData> FUN_140d73f20(CStringW text, int type);             // a new message box
void FUN_140d73c60(MS2Ptr<CMsgBoxData> box);                            // show it
void FUN_141a60f00(int nObjectId);                                        // UINameTag 0x4e5a: refresh the actor's tag
class Unk_SingletonObj* FUN_140939a10();                                 // the notify system
struct Unk_XmlElement;
bool IsElementAvailable(struct Unk_XmlElement* pElem);                          // locale + feature check (GMS 0x466c20)
int XmlGetAttr(class TiXmlElement*, char const*, int&);
int XmlGetAttr(class TiXmlElement*, char const*, CStringW&);
int XmlGetAttr(class TiXmlElement*, char const*, CStringA&);
CString GetXmlPath(const CString& strDir, const CString& strFile);
class Unk_XmlNode
{
public:
    class Unk_XmlNode* FirstChild(char const*);
    class Unk_XmlNode* NextSibling(char const*);
};
unsigned __int64 ParseUInt64W(const CStringW& text);

namespace {

void PostNotify(NotifyObject* p)
{
    reinterpret_cast<NotifySystem*>(FUN_140939a10())->Post(MS2Ptr<NotifyObject>(p));
}

void SystemLine(const CStringW& text)
{
    ShowSystemNotice(text, 2, 1);
}

void Sound(const char* name)
{
    PlaySystemSound(CString(name), CString(""));
}

CStringW Key(const wchar_t* key)
{
    return GetStringCommonByKey(CStringW(key));
}

CStringW FormatArg0(const CStringW& text, int n)
{
    CStringW s(text), v;
    v.Format(L"%d", n);
    s.Replace(L"{0}", v);
    return s;
}

void SendMode(unsigned char mode)
{
    COutPacket packet(MS2_SENDOP_MAPLESURVIVAL, 0);
    packet.WriteUInt8(mode);
    FUN_140710590(packet);
}

__int64 LocalCharacterId()
{
    WorldService* ws = WorldService::GetInstance();
    if (ws == 0)
        return 0;
    PCBase* pc = static_cast<PCBase*>(ws->GetLocalPlayer());
    return pc ? pc->FUN_141656a80() : 0;   // GMS 0xb86100 on the local PC
}

// The GMS GameFinish notify carries whether the local character is in the finish list (GMS 0x6e2e40).
class NotifySurvivalGameFinishEx : public NotifySurvivalGameFinish
{
public:
    explicit NotifySurvivalGameFinishEx(bool b) : m_bLocalInList(b) {}
    bool m_bLocalInList;
};

// ---- XML ----
TiXmlElement* Child(TiXmlElement* p, const char* name)
{
    return (TiXmlElement*)((Unk_XmlNode*)p)->FirstChild(name);
}
TiXmlElement* Next(TiXmlElement* p, const char* name)
{
    return (TiXmlElement*)((Unk_XmlNode*)p)->NextSibling(name);
}
int AttrInt(TiXmlElement* p, const char* name)
{
    int n = 0;
    XmlGetAttr(p, name, n);
    return n;
}
CStringW AttrW(TiXmlElement* p, const char* name)
{
    CStringW s;
    XmlGetAttr(p, name, s);
    return s;
}
CStringA AttrA(TiXmlElement* p, const char* name)
{
    CStringA s;
    XmlGetAttr(p, name, s);
    return s;
}

// Loads table/<na or root>/<file>; false (and no rows) when the pack lacks it.
template <class F> bool ForEachRow(const char* file, const char* element, F fn)
{
    const char* dirs[] = { "Table/na", "Table" };
    for (int i = 0; i < 2; i++)
    {
        CString strPath = GetXmlPath(dirs[i], file);
        TiXmlDocument doc;
        if (GetFileSystem()->LoadXmlFile(&doc, strPath, 0, true, false) == 0)
            continue;
        TiXmlElement* pRoot = Child(reinterpret_cast<TiXmlElement*>(&doc), "ms2");
        if (pRoot == 0)
            return false;
        for (TiXmlElement* p = Child(pRoot, element); p != 0; p = Next(p, element))
        {
            if (!IsElementAvailable(reinterpret_cast<Unk_XmlElement*>(p)))
                continue;
            fn(p);
        }
        return true;
    }
    return false;
}

std::set<int> s_shutdown[4];   // GMS 0x602280.. sets: 0 survival, 1 squad, 2 pass, 3 observer
struct { __int64 a, b; int c; bool on; } s_passBundle;   // GMS 0x4e76d0 global bundle info

}   // namespace

// ================= tables =================

CMapleSurvivalTable& CMapleSurvivalTable::Get()
{
    static CMapleSurvivalTable s;
    return s;
}

// GMS 0x6268e0, 0x626d20, 0x6286b0, 0x626fa0, 0x627460
void CMapleSurvivalTable::Load()
{
    if (m_bLoaded)
        return;
    m_bLoaded = true;
    ForEachRow("survivalLevel.xml", "survivalLevelExp", [this](TiXmlElement* p) {
        SurvivalLevelData d;
        d.level = AttrInt(p, "level");
        d.reqExp = (__int64)ParseUInt64W(AttrW(p, "reqExp"));
        d.grade = AttrInt(p, "grade");
        m_levels[d.level] = d;
    });
    ForEachRow("survivalLevelReward.xml", "survivalLevelReward", [this](TiXmlElement* p) {
        SurvivalLevelReward d;
        d.level = AttrInt(p, "level");
        char name[32];
        for (int i = 0; i < 3; i++)
        {
            sprintf_s(name, "rewardItemID%d", i + 1);    d.itemId[i] = AttrInt(p, name);
            sprintf_s(name, "rewardItemRank%d", i + 1);  d.itemRank[i] = AttrInt(p, name);
            sprintf_s(name, "rewardItemCount%d", i + 1); d.itemCount[i] = AttrInt(p, name);
        }
        m_levelRewards[d.level] = d;
    });
    struct PassLoader
    {
        std::map<int, SurvivalPassReward>* out;
        void operator()(TiXmlElement* p) const
        {
            SurvivalPassReward d;
            d.id = AttrInt(p, "id");
            d.level = AttrInt(p, "level");
            d.bSpecial = AttrInt(p, "isSpecial") != 0;
            char name[16];
            for (int i = 0; i < 2; i++)
            {
                sprintf_s(name, "type%d", i + 1);  d.entry[i].type = AttrW(p, name);
                sprintf_s(name, "id%d", i + 1);    d.entry[i].id = AttrW(p, name);
                sprintf_s(name, "value%d", i + 1); d.entry[i].value = AttrW(p, name);
                sprintf_s(name, "count%d", i + 1); d.entry[i].count = AttrW(p, name);
            }
            (*out)[d.level] = d;
        }
    };
    PassLoader free_ = { &m_passRewards }, paid = { &m_passRewardsPaid };
    ForEachRow("survivalPassReward.xml", "survivalPassReward", free_);
    ForEachRow("survivalPassReward_paid.xml", "survivalPassReward", paid);
    ForEachRow("mapleSurvivalOpenPeriod.xml", "period", [this](TiXmlElement* p) {
        SurvivalOpenPeriod d;
        d.id = AttrInt(p, "id");
        d.levelId = AttrInt(p, "survivalLevelID");
        d.rewardId = AttrInt(p, "survivalRewardID");
        d.startTime = AttrW(p, "startTime");
        d.endTime = AttrW(p, "endTime");
        d.passPrice = AttrInt(p, "passPrice");
        m_periods[d.id] = d;
    });
    ForEachRow("mapleSurvivalSkinInfo.xml", "skinInfo", [this](TiXmlElement* p) {
        SurvivalSkinInfo d;
        d.id = AttrInt(p, "id");
        d.type = AttrW(p, "type");
        d.imagePath = AttrA(p, "imagePath");
        d.mainImagePath = AttrA(p, "mainImagePath");
        d.value1 = AttrInt(p, "value1");
        d.effectId = AttrInt(p, "additionalEffectId");
        d.effectLevel = AttrInt(p, "additionalEffectLevel");
        m_skins[d.id] = d;
    });
}

// ================= the manager =================

CMapleSurvivalManager* CMapleSurvivalManager::GetInstance()
{
    static CMapleSurvivalManager* s = new CMapleSurvivalManager;   // GMS global 0x1ad6704, lives for the process
    return s;
}

CMapleSurvivalManager::CMapleSurvivalManager()
    : m_state(0), m_seasonId(0), m_seasonValue(0), m_exp(0), m_level(0), m_1a(0), m_1c(0), m_1e(0), m_20(0)
{
    memset(m_result.r, 0, sizeof(m_result.r));
    memset(m_result.f, 0, sizeof(m_result.f));
    m_season.id = m_season.active = m_season.value = 0;
    m_season.time = 0;
    memset(m_season.extra, 0, sizeof(m_season.extra));
    m_record0 = m_record7 = 0;
    m_record1 = 0;
    m_alive = m_killA = m_killB = 0;
    memset(m_passGain, 0, sizeof(m_passGain));
    for (int i = 0; i < 3; i++)
        m_skinSlots[i].equipped = 0;
}

// GMS 0x6e2a90: store, refresh the game menu (UIGameMenuDialog listens to the notify), post NotifySurvivalState.
void CMapleSurvivalManager::SetState(int nState)
{
    m_state = nState;
    MushkingUI::Lobby_OnState();   // GMS refreshes one of the two (0x79dac0, or 0x79f8e0 under feature 0xaf): both
    MushkingUI::Pass_OnState();    // do nothing while closed
    PostNotify(new NotifySurvivalState);
}

// GMS OnPacket modes 2 / 6: the matched box (text + first-match bind note, 5 s or 15 s, join / cancel).
void CMapleSurvivalManager::ShowMatchBox(__int64 charId, bool bShort, bool bRejoin)
{
    CStringW strText = Key(L"s_maple_survival_matching_complete");
    if (charId == 0)
    {
        strText += L"\n";
        strText += Key(L"s_maple_survival_ui_notice_firstmatch_char_bind");
    }
    MS2Ptr<CMsgBoxData> box = FUN_140d73f20(strText, 1);
    if (box.get() == 0)
        return;
    if (bRejoin)
        box->SetCallback(Delegate<bool(int, const CMsgBoxData&)>(this, &CMapleSurvivalManager::OnRejoinBox));
    else
        box->SetCallback(Delegate<bool(int, const CMsgBoxData&)>(this, &CMapleSurvivalManager::OnMatchBox));
    box->SetTimer(bShort ? 5 : 0xf, 1, GetStringCommon(0x2b8));
    box->FUN_141a02460(1);
    box->SetModaless(1);
    box->FUN_141a024a0(0);
    box->FUN_141a024c0();
    box->SetButtonLabels(Key(L"s_rank_duel_immediately_join"), Key(L"s_word_cancel"), L"");
    FUN_140d73c60(box);
}

// GMS 0x6e2110: join -> mode 1; cancel / timeout -> mode 3 + u8 0.
// Restore deviation: the box text says the player enters when the timer runs out, so a timeout (the timer's
// m_nButton set, as the party invite box 0x1419fb930 reads it) joins (mode 1) instead of refusing.
bool CMapleSurvivalManager::OnMatchBox(int result, const CMsgBoxData& box)
{
    if (box.GetTimer().m_nButton != 0 || result == 0)
        AcceptMatch();
    else
        RefuseMatch(0);
    return true;
}

// GMS 0x6e2140: join -> mode 6.
bool CMapleSurvivalManager::OnRejoinBox(int result, const CMsgBoxData& box)
{
    if (result == 0 && box.GetTimer().m_nButton == 0)
        AcceptRejoin();
    return true;
}

// GMS 0x6e2810: the Pass dialog's skin tab (0x7a27e0) and the Skin dialog (0x7a5b90).
void CMapleSurvivalManager::RefreshSkins()
{
    MushkingUI::Pass_OnSkins();
    MushkingUI::Skin_OnSkins();
}

void CMapleSurvivalManager::RequestMatch()
{
    if (m_state == 2)
    {
        SystemLine(Key(L"s_maple_survival_matching_rejoin"));
        return;
    }
    SendMode(0);
}
void CMapleSurvivalManager::AcceptMatch() { SendMode(1); }
void CMapleSurvivalManager::CancelMatch() { SendMode(2); }
void CMapleSurvivalManager::RefuseMatch(unsigned char reason)
{
    COutPacket packet(MS2_SENDOP_MAPLESURVIVAL, 0);
    packet.WriteUInt8(3);
    packet.WriteUInt8(reason);
    FUN_140710590(packet);
}
// GMS 0x6e21f0: in a party only the chief may register the squad, and a squad has fewer than 5 members. Each refusal is
// a system notice (GMS 0xa1fd00 type 1). GMS then refuses with s_maple_survival_ui_cant_now when a registered flag
// (0x6019a0, +0x38 of an object not identified) is set; the party's squad flag stands in for it here. GMS also requires
// an open season period (0x625f80, else cant_now) and passes a place check (0x4ab510, else
// s_maple_survival_error_not_here); neither is restored, so the server decides those.
bool CMapleSurvivalManager::RequestSquadMatch()
{
    CPartyManager* pParty = TSingleton<CPartyManager>::GetInstance();
    const wchar_t* szError = 0;
    if (pParty->IsInParty() && !pParty->IsLocalPlayerLeader())
        szError = L"s_maple_survival_error_squad_register_only_party_chief";
    else if (pParty->GetMemberCount() >= 5)
        szError = L"s_maple_survival_error_squad_register_over_count";
    else if (pParty->IsSurvivalSquadRegistered())
        szError = L"s_maple_survival_ui_cant_now";
    if (szError != 0)
    {
        ShowSystemNotice(Key(szError), 1, 1);
        return false;
    }
    COutPacket packet(MS2_SENDOP_MAPLESURVIVAL, 0);
    packet.WriteUInt8(4);
    SendPacketThrottled(&packet, 4, 1000);   // GMS 0x5cefa0(4, 1000)
    return true;
}
void CMapleSurvivalManager::RequestSeasonRecord()
{
    COutPacket packet(MS2_SENDOP_MAPLESURVIVAL, 0);
    packet.WriteUInt8(5);
    SendPacketThrottled(&packet, 5, 1000);   // key = mode, as GMS 0x5cefa0(mode, ms)
}
void CMapleSurvivalManager::AcceptRejoin() { SendMode(6); }
void CMapleSurvivalManager::EquipSkin(unsigned char slot, int skin)
{
    COutPacket packet(MS2_SENDOP_MAPLESURVIVAL, 0);
    packet.WriteUInt8(8);
    packet.WriteUInt8(slot);
    packet.WriteInt32(skin);
    FUN_140710590(packet);
}
void CMapleSurvivalManager::RequestRefresh()
{
    COutPacket packet(MS2_SENDOP_MAPLESURVIVAL, 0);
    packet.WriteUInt8(0x12);
    SendPacketThrottled(&packet, 0x12, 500);
}
void CMapleSurvivalManager::BuyPass(bool bPaid, __int64 price)
{
    COutPacket packet(MS2_SENDOP_MAPLESURVIVAL, 0);
    packet.WriteUInt8(0x22);
    packet.WriteBool(bPaid);
    packet.WriteInt64(price);
    SendPacketThrottled(&packet, 0x22, 1000);   // GMS throttles the buy (0x79ed70 / 0x7a03d0)
}
void CMapleSurvivalManager::ClaimRewards(int a, int b)
{
    COutPacket packet(MS2_SENDOP_MAPLESURVIVAL, 0);
    packet.WriteUInt8(0x23);
    packet.WriteInt32(a);
    packet.WriteInt32(b);
    FUN_140710590(packet);
}

// GMS 0x6e3110. The dialogs (result, pass, skins, kill feed, season record) are not restored yet: the data is kept
// for them; where GMS refreshes a dialog this only stores.
void CMapleSurvivalManager::OnPacket(CInPacket& packet)
{
    unsigned char mode = packet.ReadUInt8();
    switch (mode)
    {
    case 0x00:   // matching started
        SetState(1);
        Sound("guildBattle_Apply");   // GMS plays its matching sound here (0xa1e3e0); the KMS rank-duel one stands in
        break;
    case 0x01:
    case 0x03:   // matching cancelled / refused
        SetState(0);
        break;
    case 0x02:   // matched: ask to join
    {
        __int64 charId = packet.ReadInt64();
        bool bShort = packet.ReadBool();
        SetState(2);
        ShowMatchBox(charId, bShort, false);
        Sound("guildBattle_MatchingSuccess");   // as the KMS rank-duel match
        break;
    }
    case 0x06:   // re-invite
    {
        __int64 charId = packet.ReadInt64();
        bool bShort = packet.ReadBool();
        ShowMatchBox(charId, bShort, true);
        break;
    }
    case 0x11:   // game result
    {
        for (int i = 0; i < 16; i++)
            m_result.r[i] = packet.ReadInt32();
        for (int i = 0; i < 4; i++)
            m_result.f[i] = packet.ReadFloat();
        int n = packet.ReadUInt8();
        m_result.items.clear();
        for (int i = 0; i < n; i++)
        {
            SurvivalResultItem it;
            it.id = packet.ReadInt32();
            it.rarity = packet.ReadInt16();
            it.count = packet.ReadInt32();
            for (int j = 0; j < 4; j++)
                it.flag[j] = packet.ReadBool();
            m_result.items.push_back(it);
        }
        MushkingUI::Result_Show();
        break;
    }
    case 0x12:
        m_1a = packet.ReadInt32();
        MushkingUI::Lobby_OnSeason();
        break;
    case 0x13:   // game start (GMS 0x6e2cf0)
        m_finishList.clear();
        // Restore choice (no GMS counterpart found): drop a previous game's zones and effects, so nothing stale is
        // left when a field change skipped storm mode 3. The window HUD closes itself on field leave.
        MushkingUI::StormFx_OnClear();
        CSurvivalStormManager::GetInstance()->m_zones.clear();
        MushkingUI::KillLog_OnGameStart();
        PostNotify(new NotifySurvivalGameStart);
        break;
    case 0x14:   // game finish (GMS 0x6e2e40)
    {
        bool bEnd = packet.ReadBool();
        int n = packet.ReadInt32();
        for (int i = 0; i < n; i++)
            m_finishList.push_back(packet.ReadInt64());
        if (bEnd)
            SetState(0);   // GMS 0x6e2850
        __int64 me = LocalCharacterId();
        bool bIn = false;
        for (size_t i = 0; i < m_finishList.size(); i++)
            if (m_finishList[i] == me)
                bIn = true;
        MushkingUI::Observer_OnGameFinish(bIn);
        PostNotify(new NotifySurvivalGameFinishEx(bIn));
        break;
    }
    case 0x15:
        m_exp = packet.ReadInt64();
        m_level = packet.ReadInt32();
        m_1a = packet.ReadInt32();
        MushkingUI::Lobby_OnSeason();
        break;
    case 0x16:   // season info
    {
        SurvivalSeasonInfo si;
        si.id = packet.ReadInt32();
        si.active = packet.ReadInt32();
        si.time = packet.ReadInt64();
        si.name = packet.ReadUnicodeString();
        si.value = packet.ReadInt32();
        for (int i = 0; i < 6; i++)
            si.extra[i] = packet.ReadInt32();
        if (si.active == 1)
        {
            m_seasonId = si.id;
            m_seasonValue = si.value;
            m_season = si;
        }
        MushkingUI::Pass_OnSeason();   // GMS: the Pass dialog under feature 0xaf, else the lobby
        MushkingUI::Lobby_OnSeason();
        break;
    }
    case 0x17:   // own record
        m_record0 = packet.ReadInt64();
        m_record1 = packet.ReadInt32();
        m_1c = packet.ReadUInt8();
        m_exp = packet.ReadInt64();
        m_level = packet.ReadInt32();
        m_1e = packet.ReadInt32();
        m_20 = packet.ReadInt32();
        m_record7 = packet.ReadInt64();
        MushkingUI::Pass_OnRecord();
        break;
    case 0x18:
        SystemLine(Key(L"s_maple_survival_ui_refresh_season_record"));
        MushkingUI::Pass_OnSeason();
        MushkingUI::Lobby_OnSeason();
        break;
    case 0x19:   // kill feed
    {
        SurvivalKillFeed k;
        k.type = packet.ReadUInt8();
        k.weapon = 0;
        k.value = 0;
        if (k.type == 1)
        {
            k.value = packet.ReadInt32();
            k.victim = packet.ReadUnicodeString();
        }
        else
        {
            k.killer = packet.ReadUnicodeString();
            k.victim = packet.ReadUnicodeString();
            k.weapon = packet.ReadUInt8();
            k.value = packet.ReadInt32();
        }
        m_killFeed.push_back(k);
        if (m_killFeed.size() > 8)
            m_killFeed.erase(m_killFeed.begin());
        MushkingUI::KillLog_OnKill(k);
        break;
    }
    case 0x1a:
        m_alive = packet.ReadInt32();
        MushkingUI::KillLog_OnAlive();
        break;
    case 0x1b:
    {
        m_killA = packet.ReadInt32();
        m_killB = packet.ReadInt32();
        bool bFlag = packet.ReadUInt8() == 1;
        MushkingUI::KillLog_OnCounts(bFlag);
        break;
    }
    case 0x1d:   // outside the safe zone (GMS 0x6e4469: skipped without a local PC or in PC states 0x3f / 0xc / 0x42)
    {
        WorldService* ws = WorldService::GetInstance();
        PCBase* pc = ws ? static_cast<PCBase*>(ws->GetLocalPlayer()) : 0;
        if (pc == 0)
            break;
        int st = pc->GetCurStateId();   // GMS 0xb98720
        if (st == 0x3f || st == 0xc || st == 0x42)
            break;
        SystemLine(Key(L"s_maple_survival_in_storm"));
        Sound("System_LazySpore_01");
        break;
    }
    case 0x1e:   // skin slots
    {
        int n = packet.ReadUInt8();
        for (int i = 0; i < n; i++)
        {
            int equipped = packet.ReadInt32();
            int cnt = packet.ReadInt32();
            std::vector<std::pair<int, __int64> > skins;
            for (int j = 0; j < cnt; j++)
            {
                int skin = packet.ReadInt32();
                __int64 expire = packet.ReadInt64();
                skins.push_back(std::make_pair(skin, expire));
            }
            if (i < 3)
            {
                m_skinSlots[i].equipped = equipped;
                m_skinSlots[i].skins.swap(skins);
            }
        }
        RefreshSkins();   // GMS 0x6e2810
        break;
    }
    case 0x1f:   // skin added
    {
        unsigned char slot = packet.ReadUInt8();
        if (slot > 2)
            break;
        int skin = packet.ReadInt32();
        __int64 expire = packet.ReadInt64();
        m_skinSlots[slot].skins.push_back(std::make_pair(skin, expire));
        RefreshSkins();   // GMS 0x6e2810
        break;
    }
    case 0x20:   // skin equipped
    {
        unsigned char slot = packet.ReadUInt8();
        if (slot > 2)
            break;
        m_skinSlots[slot].equipped = packet.ReadInt32();
        RefreshSkins();   // GMS 0x6e2810
        break;
    }
    case 0x21:   // skin learned (GMS formats the item name into s_maple_survival_learn_skin)
    {
        unsigned char slot = packet.ReadUInt8();
        if (slot > 2)
            break;
        packet.ReadInt32();
        SystemLine(Key(L"s_maple_survival_learn_skin"));
        break;
    }
    case 0x23:   // pass progress
    {
        int a = packet.ReadInt32();
        int b = packet.ReadInt32();
        int c = packet.ReadInt32();
        int d = packet.ReadInt32();
        m_passGain[0] = a; m_passGain[1] = b; m_passGain[2] = c; m_passGain[3] = d;
        if (a <= b)
            SystemLine(Key(L"s_maple_survival_pass_gain_normal"));
        if (d >= c)
            SystemLine(Key(L"s_maple_survival_pass_gain_paid"));
        break;
    }
    case 0x24:   // nametag symbol of a PC (GMS 0x6e4560: object id, u16 symbol id)
    {
        // GMS: 0xe027a0 finds the PC by object id, 0xb86fc0 stores the symbol id (PC +0x22ee) and refreshes its name
        // tag (0xd67120 -> UINameTag 0x4e5a). KMS keeps the symbol in PC::m_n10f8 (set by OnNametag, op 0xb1, together
        // with a second value this mode does not carry: keep it).
        int nId = packet.ReadInt32();
        unsigned short nSymbol = (unsigned short)packet.ReadInt16();
        PC* pPC = (PC*)WorldService::GetInstance()->FindPCById(nId);
        if (pPC == 0)
            break;
        pPC->FUN_141661dc0(nSymbol, ((PCBase*)pPC)->FUN_141661e20());
        FUN_141a60f00(nId);
        break;
    }
    default:
        break;
    }
}

// ================= the storm =================

CSurvivalStormManager* CSurvivalStormManager::GetInstance()
{
    static CSurvivalStormManager* s = new CSurvivalStormManager;
    return s;
}

// GMS 0xbe4750. The zone effects and minimap markers live in survivalstormfx.cpp (MushkingUI::StormFx_*), the zone
// dialog in stormbar.cpp.
void CSurvivalStormManager::OnPacket(CInPacket& packet)
{
    unsigned char mode = packet.ReadUInt8();
    switch (mode)
    {
    case 0:   // add a zone (GMS 0x74baa0)
    {
        SurvivalStormZone z;
        z.id = packet.ReadInt16();
        z.radius = packet.ReadInt16();
        z.step = packet.ReadInt16();
        for (int i = 0; i < 3; i++)
            z.pos[i] = packet.ReadFloat();
        z.previewRadius = packet.ReadInt16();
        for (int i = 0; i < 3; i++)
            z.preview[i] = packet.ReadFloat();
        m_zones[z.id] = z;
        MushkingUI::StormFx_OnAdd(z);
        MushkingUI::Storm_OnZones();
        break;
    }
    case 1:   // a zone's current circle shrinks (GMS 0x74b8d0): the float is the new radius, the vector the centre.
    {         // 0x74b290 rescales the nif; 0x899350 stores radius + centre in the zone dialog (no countdown here).
        short id = packet.ReadInt16();
        float r = packet.ReadFloat();
        float pos[3];
        for (int i = 0; i < 3; i++)
            pos[i] = packet.ReadFloat();
        std::map<short, SurvivalStormZone>::iterator it = m_zones.find(id);
        if (it != m_zones.end())
        {
            it->second.radius = (short)(int)(r + 0.5f);
            for (int i = 0; i < 3; i++)
                it->second.pos[i] = pos[i];
            MushkingUI::StormFx_OnUpdate(it->second);
        }
        MushkingUI::Storm_OnZones();
        break;
    }
    case 2:   // remove a zone (GMS 0x74b660)
    {
        short id = packet.ReadInt16();
        MushkingUI::StormFx_OnRemove(id);
        m_zones.erase(id);
        MushkingUI::Storm_OnZones();
        break;
    }
    case 3:   // clear (GMS 0x74b730)
        MushkingUI::StormFx_OnClear();
        m_zones.clear();
        MushkingUI::Storm_OnZones();
        break;
    case 4:   // the safe zone shrinks in n seconds
    {
        int n = (unsigned short)packet.ReadInt16();
        SystemLine(FormatArg0(Key(L"s_survival_event_reduce_safezone_ready"), n));
        break;
    }
    case 5:   // the safe zone shrinks now (GMS 0x74b3c0 loads the B01 effect once)
        m_bStormLoaded = true;
        MushkingUI::StormFx_OnShrinkStart();
        SystemLine(Key(L"s_survival_event_reduce_safezone_start"));
        break;
    case 6:   // countdown on the zone dialog (GMS 0x74ba20: ui 0x4f67 -> 0x8992f0(n)) + the "ready" message
    {
        int n = (unsigned short)packet.ReadInt16();
        MushkingUI::Storm_OnCountdown(n);
        SystemLine(FormatArg0(Key(L"s_survival_event_reduce_safezone_ready"), n));
        break;
    }
    default:
        break;
    }
}

// ================= GameEvent switches =================
// GMS vftables 0x170d4f4 / 0x170d520 / 0x170d54c / 0x170d578: OnStart adds m_id to a set, the end removes it
// (0x602280..0x602890). KMS registers these names nowhere; the GameEvent packet creates them by name.

namespace {

template <int Kind> class GameEventMapleSurvivalSwitch : public GameEvent
{
public:
    static const wchar_t* Name();
    virtual CStringW GetTypeName() { return CStringW(Name()); }
    virtual void vfunc_2() {}
    virtual void OnStart() { s_shutdown[Kind].insert(m_id); }
    virtual void vfunc_6() { s_shutdown[Kind].erase(m_id); }
    static ClassObject* Create() { return new GameEventMapleSurvivalSwitch<Kind>; }
};
template <> const wchar_t* GameEventMapleSurvivalSwitch<0>::Name() { return L"GameEventShutdownMapleSurvival"; }
template <> const wchar_t* GameEventMapleSurvivalSwitch<1>::Name() { return L"GameEventShutdownMapleSurvivalSquad"; }
template <> const wchar_t* GameEventMapleSurvivalSwitch<2>::Name() { return L"GameEventShutdownMapleSurvivalPass"; }
template <> const wchar_t* GameEventMapleSurvivalSwitch<3>::Name() { return L"GameEventShutdownSurvivalObserver"; }

// GMS vftable 0x170d8bc: value1 / value2 i64, value3 i32; OnStart 0x4e76d0 publishes them, the end 0x4e7710 clears.
class GameEventMapleSurvivalPassBundle : public GameEvent
{
public:
    GameEventMapleSurvivalPassBundle() : m_a(0), m_b(0), m_c(0) {}
    virtual CStringW GetTypeName() { return CStringW(L"GameEventMapleSurvivalPassBundle"); }
    virtual void vfunc_2()
    {
        m_a = (__int64)ParseUInt64W(m_68);
        m_b = (__int64)ParseUInt64W(m_70);
        m_c = _wtoi(m_78);
    }
    virtual void vfunc_3(Unk_GEOut* out)
    {
        out->WriteInt(m_id);
        out->WriteInt64(m_a);
        out->WriteInt64(m_b);
        out->WriteInt(m_c);
    }
    virtual void vfunc_4(Unk_GEIn* in)
    {
        Unk_GEReader* r = reinterpret_cast<Unk_GEReader*>(reinterpret_cast<char*>(in) + 8);
        m_id = r->ReadInt();
        m_a = r->ReadInt64();
        m_b = r->ReadInt64();
        m_c = r->ReadInt();
    }
    virtual void OnStart()
    {
        s_passBundle.a = m_a;
        s_passBundle.b = m_b;
        s_passBundle.c = m_c;
        s_passBundle.on = true;
        MushkingUI::BuyBundle_OnBundle();
    }
    virtual void vfunc_6()
    {
        s_passBundle.a = s_passBundle.b = 0;
        s_passBundle.c = 0;
        s_passBundle.on = false;
        MushkingUI::BuyBundle_OnBundle();
    }
    static ClassObject* Create() { return new GameEventMapleSurvivalPassBundle; }
    __int64 m_a, m_b;
    int m_c;
};

void OnSurvivalPacket(CInPacket& packet) { CMapleSurvivalManager::GetInstance()->OnPacket(packet); }
void OnStormPacket(CInPacket& packet) { CSurvivalStormManager::GetInstance()->OnPacket(packet); }

struct Unk_RestoreSink   // the handler delegates bind to an object
{
    void Survival(CInPacket& p) { OnSurvivalPacket(p); }
    void Storm(CInPacket& p) { OnStormPacket(p); }
};
Unk_RestoreSink s_sink;

}   // namespace

bool IsMapleSurvivalShutdown(int kind) { return kind >= 0 && kind < 4 && !s_shutdown[kind].empty(); }
bool GetMapleSurvivalPassBundle(__int64& a, __int64& b, int& c)
{
    a = s_passBundle.a;
    b = s_passBundle.b;
    c = s_passBundle.c;
    return s_passBundle.on;
}

void MushkingRegisterDialogs()
{
    static bool s_done = false;
    if (s_done)
        return;
    s_done = true;
    MushkingUI::RegisterLobbyDialogs();
    MushkingUI::RegisterPassDialogs();
    MushkingUI::RegisterGameDialogs();
}

void MushkingRestoreInit()
{
    static bool s_done = false;
    if (s_done)
        return;
    s_done = true;
    CMapleSurvivalTable::Get().Load();
    PacketHandlerManager::GetInstance()->RegisterHandler(MS2_RECVOP_SURVIVAL,
        Delegate<void(CInPacket&)>(&s_sink, &Unk_RestoreSink::Survival));
    PacketHandlerManager::GetInstance()->RegisterHandler(MS2_RECVOP_SURVIVALEVENT,
        Delegate<void(CInPacket&)>(&s_sink, &Unk_RestoreSink::Storm));
    ClassObjectRegistrar(CStringW(GameEventMapleSurvivalSwitch<0>::Name()), &GameEventMapleSurvivalSwitch<0>::Create);
    ClassObjectRegistrar(CStringW(GameEventMapleSurvivalSwitch<1>::Name()), &GameEventMapleSurvivalSwitch<1>::Create);
    ClassObjectRegistrar(CStringW(GameEventMapleSurvivalSwitch<2>::Name()), &GameEventMapleSurvivalSwitch<2>::Create);
    ClassObjectRegistrar(CStringW(GameEventMapleSurvivalSwitch<3>::Name()), &GameEventMapleSurvivalSwitch<3>::Create);
    ClassObjectRegistrar(CStringW(L"GameEventMapleSurvivalPassBundle"), &GameEventMapleSurvivalPassBundle::Create);
}

#endif   // MS2_HOOK_DLL
