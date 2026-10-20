// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). GameEventManagerCli: the client's running game events.
// See ms2/placeholder/gameeventmanagercli.h.
// MS2-UNIT: client\ms2\gameeventmanagercli.cpp
// MS2-RANGE: 0x140ceaa70-0x140cfad00 .text$mn
// MS2-RANGE: 0x1400d1640-0x1400d16f0 .text$di
// MS2-PIN: ?CompareElementsOrdered@?$CDefaultCompareTraits@H@ATL@@SAHAEBH0@Z 0x140cf99f0 ; the CGameMenuTable TU's own copy (0x140212de0 is another TU's)
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\gameeventmanagercli.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/gameeventmanagercli.h"
#include "ms2/commonfiles/gameevent.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/classobject.h"
#include "ms2/placeholder/notifysystem.h"
#include "ms2/placeholder/notifygameeventchanged.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/placeholder/cgamemenutable.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/cmeratmarketman.h"
#include "ms2/placeholder/uipaybackdialog.h"
#include "ms2/commonfiles/featuremanager.h"
#include "ms2/commonfiles/seasondatatable.h"
#include "uiservice.h"
#include "uigamemenudialog.h"
#include "uiattendgiftdialog.h"
#include "uicashattenddialog.h"
#include "uidailymissiondialog.h"
#include "uileveluppackagedialog.h"
#include "uimentoringrewardpage.h"
#include "uitimeruneventdialog.h"
#include "ms2/unnamed/unit_140bd7e10.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// Namespace-scope statics of a shared game header (see ms2/placeholder/header_statics_a.h; this unit has only these).
static CString s_strSkill = "skill";
static CString s_strStun = "stun";
static Unk_1402a9d70 s_unk1402a9d70(17, 0.75f, 0.25f, 2.25f, 10);

NotifySystem* FUN_140939a10();                                  // TSingleton<NotifySystem>::GetInstance
GameEventManagerCli* FUN_14015a050();                           // TSingleton<GameEventManagerCli>::GetInstance
CFeatureManager* FUN_140166410();                               // TSingleton<CFeatureManager>::GetInstance
CMeratMarketMan* FUN_140939a00();                               // TSingleton<CMeratMarketMan>::GetInstance
CSeasonDataTable* FUN_1404f4540();                              // TSingleton<CSeasonDataTable>::GetInstance
CUIService* FUN_1403ed2b0();                                    // TSingleton<CUIService>::GetInstance
UIGameMenuDialog* FUN_140938b90(int nUiId);                     // the dialog lookups of other units (same template)
UIMentoringDialog* FUN_140b72e80(int nUiId);
UIPaybackDialog* FUN_140a8c5f0(int nUiId);
UIAttendGiftDialog* FUN_140c053e0(int nUiId);
UICashAttendDialog* FUN_140ce8130(int nUiId);
int Parse_14021b830(const CStringA& value);                     // a game menu entry id by name (commonenum.cpp)
int FUN_140718200(const CStringW& str);                         // _wtoi
bool FUN_14028f710(Unk_140165cf0* pElem);                       // the element is enabled for this build
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);   // Table/<file>
class Unk_GmFiles { public: int FUN_1403974b0(TiXmlDocument* pDoc, const char* szPath, int nEncoding, bool bWarn, bool bLocalOnly); };
Unk_GmFiles* FUN_140166420();                                   // CFileSystem
class Unk_GmLog;
Unk_GmLog* FUN_140166440();                                     // CLogString
void FUN_14015eb90(Unk_GmLog* pLog, int nLevel, int nCategory, const wchar_t* szFormat, const CString& arg);

// @0x140ceaa70
GameEventManagerCli::GameEventManagerCli()
{
}

// @0x140ceab00
GameEventManagerCli::~GameEventManagerCli()
{
}

// Not hooked: Dispatch/Packet0-3, CGameMenuItem::Load and CGameMenuTable::Init/RegisterDefs/LoadXml construct polymorphic
// objects (NotifyGameEventChanged, CGameMenuDef/CGameMenuItem, ClassFunHandler) that would carry the DLL's vftable copies.
// @0x140ceab50
void GameEventManagerCli::Dispatch(CInPacket& packet)
{
    int nType = packet.vfunc_o8_1();
    switch (nType)
    {
    case 0:
        Packet0(packet);
        break;
    case 1:
        Packet1(packet);
        break;
    case 2:
        Packet2(packet);
        break;
    case 3:
        Packet3(packet);
        break;
    }
}

// @0x140ceac00
void GameEventManagerCli::Clear()
{
    for (POSITION pos = m_events.GetStartPosition(); pos != 0; m_events.GetNext(pos))
    {
        MS2Ptr<GameEvent> gameEvent = m_events.GetValueAt(pos);
        gameEvent->vfunc_6();
    }
    m_events.RemoveAll();
    m_states.clear();
}
MS2_REPLACE_METHOD(0x140CEAC00, GameEventManagerCli, Clear, 191, 0xC18D56BF);

// @0x140ceacd0
MS2Ptr<GameEvent> GameEventManagerCli::Find(int nId)
{
    MS2Ptr<GameEvent> gameEvent;
    if (m_events.Lookup(nId, gameEvent))
        return gameEvent;
    return MS2Ptr<GameEvent>(0);
}
MS2_REPLACE_METHOD(0x140CEACD0, GameEventManagerCli, Find, 166, 0x4B03AC33);

// @0x140cead80
bool GameEventManagerCli::IsEnabled(CStringW strName)
{
    std::map<CStringW, unsigned int>::iterator it = m_states.find(strName);
    if (it == m_states.end())
        return false;
    return it->second > 0;
}
MS2_REPLACE_METHOD(0x140CEAD80, GameEventManagerCli, IsEnabled, 179, 0x6B213D7B);

// @0x140ceae40
void GameEventManagerCli::Packet0(CInPacket& packet)
{
    int nCount = packet.vfunc_o8_3();
    for (int i = 0; i < nCount; ++i)
    {
        CStringW strName = packet.vfunc_o8_8();
        MS2Ptr<GameEvent> gameEvent(Create(strName));
        if (gameEvent.get())
        {
            gameEvent->vfunc_4(reinterpret_cast<Unk_GEIn*>(&packet));
            Add(gameEvent);
        }
        else
        {
            MS2_ASSERT_AT(MS2_LINE(82), 0);
            return;
        }
    }
}

// @0x140ceaff0
void GameEventManagerCli::Packet1(CInPacket& packet)
{
    int nCount = packet.vfunc_o8_3();
    for (int i = 0; i < nCount; ++i)
    {
        CStringW strName = packet.vfunc_o8_8();
        MS2Ptr<GameEvent> gameEvent(Create(strName));
        if (gameEvent.get())
        {
            gameEvent->vfunc_4(reinterpret_cast<Unk_GEIn*>(&packet));
            if (Add(gameEvent))
                FUN_140939a10()->Post(MS2Ptr<NotifyObject>(new NotifyGameEventChanged(gameEvent->GetID(), strName, 0)));
        }
        else
        {
            MS2_ASSERT_AT(MS2_LINE(103), 0);
            return;
        }
    }
}

// @0x140ceb2a0
void GameEventManagerCli::Packet2(CInPacket& packet)
{
    int nCount = packet.vfunc_o8_3();
    for (int i = 0; i < nCount; ++i)
    {
        int nId = packet.vfunc_o8_3();
        MS2Ptr<GameEvent> gameEvent = Find(nId);
        if (gameEvent.get())
        {
            Remove(gameEvent);
            FUN_140939a10()->Post(MS2Ptr<NotifyObject>(new NotifyGameEventChanged(nId, gameEvent->GetName(), 1)));
        }
    }
}

// @0x140ceb480
void GameEventManagerCli::Packet3(CInPacket& packet)
{
    int nCount = packet.vfunc_o8_3();
    for (int i = 0; i < nCount; ++i)
    {
        CStringW strName = packet.vfunc_o8_8();
        MS2Ptr<GameEvent> gameEvent(Create(strName));
        if (gameEvent.get())
        {
            gameEvent->vfunc_4(reinterpret_cast<Unk_GEIn*>(&packet));
            Update(gameEvent);
            FUN_140939a10()->Post(MS2Ptr<NotifyObject>(new NotifyGameEventChanged(gameEvent->GetID(), strName, 2)));
        }
        else
        {
            MS2_ASSERT_AT(MS2_LINE(141), 0);
            return;
        }
    }
}

// @0x140ceb730
bool GameEventManagerCli::Add(MS2Ptr<GameEvent> gameEvent)
{
    MS2_ASSERT_AT(MS2_LINE(149), gameEvent->GetID() != 0);
    if (m_events.Lookup(gameEvent->GetID()) != 0)
        return false;
    gameEvent->vfunc_5();
    m_events.SetAt(gameEvent->GetID(), gameEvent);
    ++m_states[gameEvent->GetName()];
    return true;
}
MS2_REPLACE_METHOD(0x140CEB730, GameEventManagerCli, Add, 324, 0x68C780EB);

// @0x140ceb880
void GameEventManagerCli::Remove(MS2Ptr<GameEvent> gameEvent)
{
    MS2_ASSERT_AT(MS2_LINE(164), gameEvent->GetID() != 0);
    gameEvent->vfunc_6();
    m_events.RemoveKey(gameEvent->GetID());
    if (m_states.find(gameEvent->GetName()) != m_states.end())
        --m_states[gameEvent->GetName()];
    else
        MS2_ASSERT_AT(MS2_LINE(173), 0);
}
MS2_REPLACE_METHOD(0x140CEB880, GameEventManagerCli, Remove, 452, 0x99473B08);

// @0x140ceba50
void GameEventManagerCli::Update(MS2Ptr<GameEvent> gameEvent)
{
    MS2Ptr<GameEvent> prevEvent;
    m_events.Lookup(gameEvent->GetID(), prevEvent);
    m_events.SetAt(gameEvent->GetID(), gameEvent);
    gameEvent->vfunc_7(prevEvent);
}
MS2_REPLACE_METHOD(0x140CEBA50, GameEventManagerCli, Update, 205, 0xAE581E6D);

// @0x140cebb30
GameEvent* GameEventManagerCli::Create(CStringW strName)
{
    GameEvent* gameEvent = static_cast<GameEvent*>(FUN_1401f7f50(StringFormat(L"GameEvent{0}Cli", strName)));
    if (gameEvent == 0)
        gameEvent = static_cast<GameEvent*>(FUN_1401f7f50(StringFormat(L"GameEvent{0}", strName)));
    if (gameEvent == 0)
        return 0;
    gameEvent->SetName(strName);
    return gameEvent;
}
MS2_REPLACE_METHOD(0x140CEBB30, GameEventManagerCli, Create, 231, 0x86E873F2);

// @0x140cedbf0
inline NotifyGameEventChanged::NotifyGameEventChanged(int id, CStringW eventName, int type)
    : m_id(id), m_eventName(eventName), m_type(type)
{
}

// End of the original gameeventmanagercli.cpp COMDAT tail: its UCRT memmove_s copy. The CGameMenuTable code after it
// (0x140cf08d0..) is a second original TU that units.tsv merged into this range.
// @0x140cf07b0
MS2_EMIT_CRT_MEMMOVE_S_COPY(1);

// ==== CGameMenuTable (second original TU of the range; see ms2/placeholder/cgamemenutable.h) ====

// The dialog lookup behind the four COMDATs at 0x140cf81a0..0x140cf8380 (CUIService object by class id, then a cast).
template <class T> T* FindUIDialog(int nId)
{
    if (FUN_1403ed2b0())
    {
        MS2Ptr<UIObject> p = FUN_1403ed2b0()->FUN_141adcea0((eUIClassID)nId);
        if (p.get())
            return dynamic_cast<T*>((UIObject*)p);
    }
    return 0;
}

// @0x140cf08d0
CGameMenuItem::CGameMenuItem()
    : m_nId(0), m_nRow(0), m_nCol(0), m_nOnlyRPG(0), m_eFilterType(GAMEMENU_FILTER_NONE), m_nFilterEventId(0)
{
}

// @0x140cf0970
void CGameMenuItem::Load(Unk_140165cf0* pElem)
{
    XmlEnumName<int, Parse_14021b830>(pElem, "id", m_nId);
    XmlEnumName<EGameMenuFilter, ParseGameMenuFilter>(pElem, "filterType", m_eFilterType);
    FUN_140873420(pElem, "filterValue", m_strFilterValue);
    FUN_1408731e0(pElem, "onlyRPG", m_nOnlyRPG);
    FUN_1408731e0(pElem, "row", m_nRow);
    FUN_1408731e0(pElem, "col", m_nCol);
    if (!m_strFilterValue.IsEmpty())
        m_nFilterEventId = FUN_140718200(m_strFilterValue);
    for (Unk_140165cf0* pChild = pElem->FUN_140165cf0("child"); pChild != 0; pChild = pChild->FUN_140168650("child"))
    {
        if (!FUN_14028f710(pChild))
            continue;
        {
            MS2Ptr<CGameMenuItem> spChild(new CGameMenuItem());
            spChild->Load(pChild);
            m_children.Add(spChild);
        }
    }
}

// @0x140cf0b50
bool CGameMenuItem::HasId(int nId)
{
    if (m_nId == nId)
        return true;
    for (unsigned int i = 0; i < m_children.GetCount(); ++i)
    {
        if (m_children[i]->HasId(nId))
            return true;
    }
    return false;
}
MS2_REPLACE_METHOD(0x140CF0B50, CGameMenuItem, HasId, 144, 0xCEC3A800);

// @0x140cf0bf0
bool CGameMenuItem::IsVisible()
{
    if (m_eFilterType == GAMEMENU_FILTER_NONE)
        return true;
    switch (m_eFilterType)
    {
    case GAMEMENU_FILTER_EVENT_ID:
        if (FUN_14015a050()->Find(m_nFilterEventId).get() != 0)
            return true;
        break;
    case GAMEMENU_FILTER_EVENT_TYPE:
        if (FUN_14015a050()->IsEnabled(m_strFilterValue))
            return true;
        break;
    case GAMEMENU_FILTER_ATTEND_GIFT:
    {
        UIAttendGiftDialog* pDialog = FUN_140c053e0(0x4eb8);
        if (pDialog && pDialog->FUN_14102cb60())
            return true;
        break;
    }
    case GAMEMENU_FILTER_CASH_ATTEND:
    {
        UICashAttendDialog* pDialog = FUN_140ce8130(0x4eb9);
        if (pDialog && pDialog->FUN_140bc4030())
            return true;
        break;
    }
    case GAMEMENU_FILTER_SEASON:
        if (FUN_1404f4540()->GetCurrent(FUN_1404f4540()->GetType(CStringA(m_strFilterValue))).get() != 0)
            return true;
        break;
    }
    return false;
}
MS2_REPLACE_METHOD(0x140CF0BF0, CGameMenuItem, IsVisible, 661, 0xBFA8165F);

// @0x140cf0e90
bool CGameMenuItem::IsAffectedBy(NotifyGameEventChanged* pNotify)
{
    switch (m_eFilterType)
    {
    case GAMEMENU_FILTER_EVENT_ID:
        return m_nFilterEventId == pNotify->m_id;
    case GAMEMENU_FILTER_EVENT_TYPE:
        return m_strFilterValue == pNotify->m_eventName;
    case GAMEMENU_FILTER_ATTEND_GIFT:
        return pNotify->m_eventName == L"AttendGift";
    case GAMEMENU_FILTER_CASH_ATTEND:
        return pNotify->m_eventName == L"CashAttend";
    default:
        for (unsigned int i = 0; i < m_children.GetCount(); ++i)
        {
            if (m_children[i]->IsAffectedBy(pNotify))
                return true;
        }
        return false;
    }
}
MS2_REPLACE_METHOD(0x140CF0E90, CGameMenuItem, IsAffectedBy, 305, 0x2DDB94EB);

// @0x140cf0fd0
CGameMenuTable::CGameMenuTable()
    : m_defs(10)
{
}

// @0x140cf1060
CGameMenuTable::~CGameMenuTable()
{
}

// @0x140cf10d0
int CGameMenuTable::Init()
{
    if (RegisterDefs() == 0)
        return 0;
    if (LoadXml() == 0)
        return 0;
    return 1;
}

// @0x140cf1110
int CGameMenuTable::RegisterDefs()
{
    UIGameMenuDialog* pGameMenu = FUN_140938b90(0x4e28);
    {
        CGameMenuDef* pDef = new CGameMenuDef();
        pDef->m_nId = 1;
        pDef->m_strName = "worldmap";
        pDef->m_strLabel = "$s_gamemenu_btn_worldmap";
        pDef->m_strTooltip = L"s_tooltip_gamemenu_worldmap";
        pDef->m_nKeyBind = 400006;
        pDef->m_nUiId = 0x4e42;
        m_defs.SetAt(pDef->m_nId, pDef);
    }
    {
        CGameMenuDef* pDef = new CGameMenuDef();
        pDef->m_nId = 2;
        pDef->m_strName = "mail";
        pDef->m_strLabel = "$s_gamemenu_btn_mail";
        pDef->m_strTooltip = L"s_tooltip_gamemenu_mail";
        pDef->m_nKeyBind = 400013;
        pDef->m_nUiId = 0x4e49;
        m_defs.SetAt(pDef->m_nId, pDef);
    }
    {
        CGameMenuDef* pDef = new CGameMenuDef();
        pDef->m_nId = 3;
        pDef->m_strName = "community";
        pDef->m_strLabel = "$s_gamemenu_btn_community";
        pDef->m_strTooltip = L"s_tooltip_gamemenu_community";
        pDef->m_nKeyBind = 400012;
        pDef->m_nUiId = 0x4e4d;
        m_defs.SetAt(pDef->m_nId, pDef);
    }
    {
        CGameMenuDef* pDef = new CGameMenuDef();
        pDef->m_nId = 4;
        pDef->m_strName = "guild";
        pDef->m_strLabel = "$s_gamemenu_popup_guild";
        pDef->m_strTooltip = L"s_tooltip_gamemenu_guild";
        pDef->m_nKeyBind = 400014;
        pDef->m_nUiId = 0x4e4f;
        m_defs.SetAt(pDef->m_nId, pDef);
    }
    {
        CGameMenuDef* pDef = new CGameMenuDef();
        pDef->m_nId = 5;
        pDef->m_strName = "levelup";
        pDef->m_strLabel = "$s_gamemenu_popup_levelup";
        pDef->m_strTooltip = L"s_tooltip_gamemenu_levelup";
        pDef->m_nKeyBind = 400022;
        pDef->m_nUiId = 0x4efa;
        m_defs.SetAt(pDef->m_nId, pDef);
    }
    if (FUN_140166410()->FUN_14036d570(27))
    {
        CGameMenuDef* pDef = new CGameMenuDef();
        pDef->m_nId = 6;
        pDef->m_strName = "arcade";
        pDef->m_strLabel = "$s_gamemenu_popup_arcade";
        pDef->m_strTooltip = L"s_tooltip_gamemenu_arcade";
        pDef->m_nKeyBind = 400023;
        pDef->m_nUiId = 0x4efd;
        m_defs.SetAt(pDef->m_nId, pDef);
    }
    {
        CGameMenuDef* pDef = new CGameMenuDef();
        pDef->m_nId = 7;
        pDef->m_strName = "option";
        pDef->m_strLabel = "$s_gamemenu_btn_gameoption";
        pDef->m_strTooltip = L"s_tooltip_gamemenu_gameoption";
        pDef->m_nKeyBind = 0;
        pDef->m_nUiId = 0x4e21;
        m_defs.SetAt(pDef->m_nId, pDef);
    }
    {
        CGameMenuDef* pDef = new CGameMenuDef();
        pDef->m_nId = 8;
        pDef->m_strName = "characterinfo";
        pDef->m_strLabel = "$s_gamemenu_btn_userinfo";
        pDef->m_strTooltip = L"s_tooltip_gamemenu_userinfo";
        pDef->m_nKeyBind = 400002;
        pDef->m_nUiId = 0x2711;
        m_defs.SetAt(pDef->m_nId, pDef);
    }
    {
        CGameMenuDef* pDef = new CGameMenuDef();
        pDef->m_nId = 9;
        pDef->m_strName = "inven";
        pDef->m_strLabel = "$s_gamemenu_btn_inven";
        pDef->m_strTooltip = L"s_tooltip_gamemenu_inven";
        pDef->m_nKeyBind = 400001;
        pDef->m_nUiId = 0x4e2d;
        m_defs.SetAt(pDef->m_nId, pDef);
    }
    {
        CGameMenuDef* pDef = new CGameMenuDef();
        pDef->m_nId = 10;
        pDef->m_strName = "skillbook";
        pDef->m_strLabel = "$s_gamemenu_btn_skillbook";
        pDef->m_strTooltip = L"s_tooltip_gamemenu_skillbook";
        pDef->m_nKeyBind = 400005;
        pDef->m_nUiId = 0x4f2d;
        m_defs.SetAt(pDef->m_nId, pDef);
    }
    {
        CGameMenuDef* pDef = new CGameMenuDef();
        pDef->m_nId = 11;
        pDef->m_strName = "quest";
        pDef->m_strLabel = "$s_gamemenu_btn_quest";
        pDef->m_strTooltip = L"s_tooltip_gamemenu_quest";
        pDef->m_nKeyBind = 400007;
        pDef->m_nUiId = 0x4e3e;
        m_defs.SetAt(pDef->m_nId, pDef);
    }
    {
        CGameMenuDef* pDef = new CGameMenuDef();
        pDef->m_nId = 12;
        pDef->m_strName = "achievement";
        pDef->m_strLabel = "$s_gamemenu_btn_achievement";
        pDef->m_strTooltip = L"s_tooltip_gamemenu_acheivement";
        pDef->m_nKeyBind = 400009;
        pDef->m_nUiId = 0x4e73;
        m_defs.SetAt(pDef->m_nId, pDef);
    }
    {
        CGameMenuDef* pDef = new CGameMenuDef();
        pDef->m_nId = 13;
        pDef->m_strName = "dungeonSearch";
        pDef->m_strLabel = "$s_gamemenu_btn_dungeonSearch";
        pDef->m_strTooltip = L"s_tooltip_gamemenu_dungeonSearch";
        pDef->m_nKeyBind = 400018;
        pDef->m_onClick.Bind(pGameMenu, &UIGameMenuDialog::FUN_14193d5e0);
        m_defs.SetAt(pDef->m_nId, pDef);
    }
    if (FUN_140166410()->FUN_14036d570(59) == true)
    {
        CGameMenuDef* pDef = new CGameMenuDef();
        pDef->m_nId = 14;
        pDef->m_strName = "maver";
        pDef->m_strLabel = "$s_gamemenu_popup_maview";
        pDef->m_strTooltip = L"s_tooltip_gamemenu_maview";
        pDef->m_nKeyBind = 400015;
        pDef->m_nUiId = 0x4e6a;
        m_defs.SetAt(pDef->m_nId, pDef);
    }
    {
        CGameMenuDef* pDef = new CGameMenuDef();
        pDef->m_nId = 15;
        pDef->m_strName = "ugcshop";
        pDef->m_strLabel = "$s_gamemenu_btn_ugc_shop";
        pDef->m_strTooltip = L"s_tooltip_gamemenu_ugc_shop";
        pDef->m_nKeyBind = 400016;
        pDef->m_nUiId = 0x4ec1;
        pDef->m_onClick.Bind(pGameMenu, &UIGameMenuDialog::FUN_14193b630);
        pDef->m_hasNew.Bind(FUN_140939a00(), reinterpret_cast<int (CMeratMarketMan::*)()>(&CMeratMarketMan::FUN_140d5b6b0));
        m_defs.SetAt(pDef->m_nId, pDef);
    }
    {
        CGameMenuDef* pDef = new CGameMenuDef();
        pDef->m_nId = 16;
        pDef->m_strName = "cashshop";
        pDef->m_strLabel = "$s_gamemenu_btn_cashshop";
        pDef->m_strTooltip = L"s_tooltip_gamemenu_cashshop";
        pDef->m_nKeyBind = 400017;
        pDef->m_nUiId = 0x4ebc;
        pDef->m_onClick.Bind(pGameMenu, &UIGameMenuDialog::FUN_14193b5b0);
        m_defs.SetAt(pDef->m_nId, pDef);
    }
    {
        CGameMenuDef* pDef = new CGameMenuDef();
        pDef->m_nId = 17;
        pDef->m_strName = "beauty";
        pDef->m_strLabel = "$s_gamemenu_popup_beauty";
        pDef->m_strTooltip = L"s_tooltip_gamemenu_beauty";
        pDef->m_nKeyBind = 400024;
        pDef->m_nUiId = 0x4efe;
        m_defs.SetAt(pDef->m_nId, pDef);
    }
    {
        CGameMenuDef* pDef = new CGameMenuDef();
        pDef->m_nId = 18;
        pDef->m_strName = "blackmarket";
        pDef->m_strLabel = "$s_gamemenu_popup_blackmarket";
        pDef->m_strTooltip = L"s_tooltip_gamemenu_blackmarket";
        pDef->m_nKeyBind = 400021;
        pDef->m_nUiId = 0x4e97;
        m_defs.SetAt(pDef->m_nId, pDef);
    }
    {
        CGameMenuDef* pDef = new CGameMenuDef();
        pDef->m_nId = 19;
        pDef->m_strName = "individualbattle";
        pDef->m_strLabel = "$s_gamemenu_popup_individualbattle";
        pDef->m_strTooltip = L"s_tooltip_gamemenu_individualbattle";
        pDef->m_nKeyBind = 400020;
        pDef->m_nUiId = 0x4f04;
        pDef->m_onClick.Bind(pGameMenu, &UIGameMenuDialog::FUN_14193b670);
        m_defs.SetAt(pDef->m_nId, pDef);
    }
    {
        CGameMenuDef* pDef = new CGameMenuDef();
        pDef->m_nId = 20;
        pDef->m_strName = "characterability";
        pDef->m_strLabel = "$s_gamemenu_popup_characterability";
        pDef->m_strTooltip = L"s_tooltip_gamemenu_enable_characterability";
        pDef->m_nKeyBind = 400025;
        pDef->m_nUiId = 0x4f0c;
        m_defs.SetAt(pDef->m_nId, pDef);
    }
    {
        CGameMenuDef* pDef = new CGameMenuDef();
        pDef->m_nId = 21;
        pDef->m_strName = "design";
        pDef->m_strLabel = "$s_gamemenu_btn_design";
        pDef->m_strTooltip = L"s_tooltip_gamemenu_design";
        pDef->m_nUiId = 0x4e69;
        pDef->m_nKeyBind = 400028;
        pDef->m_onClick.Bind(pGameMenu, &UIGameMenuDialog::FUN_14193bbe0);
        m_defs.SetAt(pDef->m_nId, pDef);
    }
    {
        CGameMenuDef* pDef = new CGameMenuDef();
        pDef->m_nId = 22;
        pDef->m_strName = "home";
        pDef->m_strLabel = "$s_gamemenu_btn_home";
        pDef->m_strTooltip = L"s_tooltip_gamemenu_home";
        pDef->m_strDisabledTooltip = L"s_returnhome_disable";
        pDef->m_nKeyBind = 300035;
        pDef->m_onClick.Bind(pGameMenu, &UIGameMenuDialog::FUN_14193b750);
        m_defs.SetAt(pDef->m_nId, pDef);
    }
    if (FUN_140166410()->FUN_14036d570(74) == true)
    {
        CGameMenuDef* pDef = new CGameMenuDef();
        pDef->m_nId = 23;
        pDef->m_strName = "vip";
        pDef->m_strLabel = "$s_gamemenu_btn_vip";
        pDef->m_strTooltip = L"s_tooltip_gamemenu_vip";
        pDef->m_nKeyBind = 400026;
        pDef->m_nUiId = 0x4f1b;
        pDef->m_onClick.Bind(pGameMenu, &UIGameMenuDialog::FUN_14193bda0);
        m_defs.SetAt(pDef->m_nId, pDef);
    }
    {
        CGameMenuDef* pDef = new CGameMenuDef();
        pDef->m_nId = 24;
        pDef->m_strName = "mastery";
        pDef->m_strLabel = "$s_gamemenu_btn_mastery";
        pDef->m_strTooltip = L"s_tooltip_gamemenu_mastery";
        pDef->m_nUiId = 0x4f1e;
        pDef->m_nKeyBind = 400029;
        m_defs.SetAt(pDef->m_nId, pDef);
    }
    {
        CGameMenuDef* pDef = new CGameMenuDef();
        pDef->m_nId = 25;
        pDef->m_strName = "partysearch";
        pDef->m_strLabel = "$s_gamemenu_btn_partysearch";
        pDef->m_strTooltip = L"s_tooltip_gamemenu_partysearch";
        pDef->m_nKeyBind = 400027;
        pDef->m_nUiId = 0x4eda;
        m_defs.SetAt(pDef->m_nId, pDef);
    }
    {
        CGameMenuDef* pDef = new CGameMenuDef();
        pDef->m_nId = 26;
        pDef->m_strName = "learning";
        pDef->m_strLabel = "$s_gamemenu_btn_learning";
        pDef->m_strTooltip = L"s_tooltip_gamemenu_learning_quest";
        pDef->m_nUiId = 0x4f18;
        pDef->m_nKeyBind = 400030;
        pDef->m_onClick.Bind(pGameMenu, &UIGameMenuDialog::FUN_14193bdf0);
        m_defs.SetAt(pDef->m_nId, pDef);
    }
    {
        CGameMenuDef* pDef = new CGameMenuDef();
        pDef->m_nId = 27;
        pDef->m_strName = "compactkey";
        pDef->m_strLabel = "$s_gamemenu_btn_compactkey";
        pDef->m_strTooltip = L"s_tooltip_gamemenu_compactkey";
        pDef->m_nUiId = 0x4ef6;
        pDef->m_nKeyBind = 400031;
        m_defs.SetAt(pDef->m_nId, pDef);
    }
    {
        CGameMenuDef* pDef = new CGameMenuDef();
        pDef->m_nId = 28;
        pDef->m_strName = "dictionary";
        pDef->m_strLabel = "$s_gamemenu_btn_dictionary";
        pDef->m_strTooltip = L"s_tooltip_gamemenu_dictionary";
        pDef->m_nUiId = 0x4f0b;
        pDef->m_nKeyBind = 400032;
        m_defs.SetAt(pDef->m_nId, pDef);
    }
    {
        CGameMenuDef* pDef = new CGameMenuDef();
        pDef->m_nId = 29;
        pDef->m_strName = "ranking";
        pDef->m_strLabel = "$s_gamemenu_btn_ranking";
        pDef->m_strTooltip = L"s_tooltip_gamemenu_ranking";
        pDef->m_nKeyBind = 400033;
        pDef->m_nUiId = 0x4f24;
        m_defs.SetAt(pDef->m_nId, pDef);
    }
    {
        CGameMenuDef* pDef = new CGameMenuDef();
        pDef->m_nId = 30;
        pDef->m_strName = "beauty_hair";
        pDef->m_strLabel = "$s_gamemenu_btn_beauty_hair";
        pDef->m_strTooltip = L"s_tooltip_gamemenu_beauty_hair";
        pDef->m_nKeyBind = 300042;
        pDef->m_onClick.Bind(pGameMenu, &UIGameMenuDialog::FUN_14193bf70);
        m_defs.SetAt(pDef->m_nId, pDef);
    }
    {
        CGameMenuDef* pDef = new CGameMenuDef();
        pDef->m_nId = 31;
        pDef->m_strName = "beauty_item";
        pDef->m_strLabel = "$s_gamemenu_btn_beauty_item";
        pDef->m_strTooltip = L"s_tooltip_gamemenu_beauty_item";
        pDef->m_nKeyBind = 300043;
        pDef->m_onClick.Bind(pGameMenu, &UIGameMenuDialog::FUN_14193bfd0);
        m_defs.SetAt(pDef->m_nId, pDef);
    }
    {
        CGameMenuDef* pDef = new CGameMenuDef();
        pDef->m_nId = 32;
        pDef->m_strName = "beauty_skin";
        pDef->m_strLabel = "$s_gamemenu_btn_beauty_skin";
        pDef->m_strTooltip = L"s_tooltip_gamemenu_beauty_skin";
        pDef->m_nKeyBind = 300044;
        pDef->m_onClick.Bind(pGameMenu, &UIGameMenuDialog::FUN_14193bfa0);
        m_defs.SetAt(pDef->m_nId, pDef);
    }
    {
        CGameMenuDef* pDef = new CGameMenuDef();
        pDef->m_nId = 33;
        pDef->m_strName = "club";
        pDef->m_strLabel = "$s_gamemenu_btn_club";
        pDef->m_strTooltip = L"s_tooltip_gamemenu_club";
        pDef->m_nKeyBind = 400034;
        pDef->m_nUiId = 0x4f25;
        m_defs.SetAt(pDef->m_nId, pDef);
    }
    {
        CGameMenuDef* pDef = new CGameMenuDef();
        pDef->m_nId = 34;
        pDef->m_strName = "epic_restart";
        pDef->m_strLabel = "$s_gamemenu_btn_epic_restart";
        pDef->m_strTooltip = L"s_tooltip_gamemenu_epic_restart";
        pDef->m_onClick.Bind(pGameMenu, &UIGameMenuDialog::FUN_14193c000);
        m_defs.SetAt(pDef->m_nId, pDef);
    }
    UILevelUpPackageDialog* pLevelUpPackage = FindUIDialog<UILevelUpPackageDialog>(0x4f2f);
    {
        CGameMenuDef* pDef = new CGameMenuDef();
        pDef->m_nId = 35;
        pDef->m_strName = "levelup_package";
        pDef->m_strLabel = "$s_gamemenu_btn_levelup_package";
        pDef->m_strTooltip = L"s_tooltip_gamemenu_levelup_package";
        pDef->m_nUiId = 0x4f2f;
        pDef->m_onClick.Bind(pGameMenu, &UIGameMenuDialog::FUN_14193c3c0);
        pDef->m_isEnabled.Bind(pLevelUpPackage, &UILevelUpPackageDialog::FUN_140ea4b70);
        m_defs.SetAt(pDef->m_nId, pDef);
    }
    if (FUN_140166410()->FUN_14036d570(92) == true)
    {
        CGameMenuDef* pDef = new CGameMenuDef();
        pDef->m_nId = 36;
        pDef->m_strName = "maver";
        pDef->m_strLabel = "$s_gamemenu_popup_adventurebar";
        pDef->m_strTooltip = L"s_tooltip_gamemenu_adventurebar";
        pDef->m_nKeyBind = 400015;
        pDef->m_nUiId = 0x4e6a;
        m_defs.SetAt(pDef->m_nId, pDef);
    }
    {
        CGameMenuDef* pDef = new CGameMenuDef();
        pDef->m_nId = 37;
        pDef->m_strName = "stamp";
        pDef->m_strLabel = "$s_gamemenu_popup_stampevent";
        pDef->m_strTooltip = L"s_tooltip_gamemenu_stampevent";
        pDef->m_nUiId = 0x4f33;
        pDef->m_onClick.Bind(pGameMenu, &UIGameMenuDialog::FUN_14193c550);
        m_defs.SetAt(pDef->m_nId, pDef);
    }
    {
        CGameMenuDef* pDef = new CGameMenuDef();
        pDef->m_nId = 38;
        pDef->m_strName = "attend";
        pDef->m_strLabel = "$s_gamemenu_popup_attendgift";
        pDef->m_strTooltip = L"s_tooltip_gamemenu_attendgift";
        pDef->m_nUiId = 0x4eb8;
        pDef->m_onClick.Bind(pGameMenu, &UIGameMenuDialog::FUN_14193c630);
        m_defs.SetAt(pDef->m_nId, pDef);
    }
    if (FUN_140166410()->FUN_14036d570(140) == true)
    {
        CGameMenuDef* pDef = new CGameMenuDef();
        pDef->m_nId = 39;
        pDef->m_strName = "pet";
        pDef->m_strLabel = "$s_gamemenu_btn_pet";
        pDef->m_strTooltip = L"s_tooltip_gamemenu_pet";
        pDef->m_nKeyBind = 400035;
        pDef->m_nUiId = 0x4f38;
        pDef->m_onClick.Bind(pGameMenu, &UIGameMenuDialog::FUN_14193c730);
        m_defs.SetAt(pDef->m_nId, pDef);
    }
    {
        CGameMenuDef* pDef = new CGameMenuDef();
        pDef->m_nId = 40;
        pDef->m_strName = "live";
        pDef->m_strLabel = "$s_gamemenu_btn_live_cam";
        pDef->m_strTooltip = L"s_tooltip_gamemenu_live_cam";
        pDef->m_nKeyBind = 400015;
        pDef->m_nUiId = 0x4e6a;
        pDef->m_onClick.Bind(pGameMenu, &UIGameMenuDialog::FUN_14193c780);
        m_defs.SetAt(pDef->m_nId, pDef);
    }
    UITimeRunEventDialog* pTimeRun = FindUIDialog<UITimeRunEventDialog>(0x4f43);
    {
        CGameMenuDef* pDef = new CGameMenuDef();
        pDef->m_nId = 41;
        pDef->m_strName = "timerun";
        pDef->m_strLabel = "$s_gamemenu_btn_time_run_event";
        pDef->m_strTooltip = L"s_tooltip_gamemenu_time_run_event";
        pDef->m_nUiId = 0x4f43;
        pDef->m_onClick.Bind(pGameMenu, &UIGameMenuDialog::FUN_14193c800);
        pDef->m_isEnabled.Bind(pTimeRun, &UITimeRunEventDialog::FUN_140ee3290);
        m_defs.SetAt(pDef->m_nId, pDef);
    }
    UIMentoringDialog* pMentoring = FUN_140b72e80(0x4f4b);
    {
        CGameMenuDef* pDef = new CGameMenuDef();
        pDef->m_nId = 42;
        pDef->m_strName = "mentoring";
        pDef->m_strLabel = "$s_gamemenu_btn_mentoring";
        pDef->m_strTooltip = L"s_tooltip_gamemenu_mentoring";
        pDef->m_nUiId = 0x4f4b;
        pDef->m_onClick.Bind(pGameMenu, &UIGameMenuDialog::FUN_14193c930);
        pDef->m_isEnabled.Bind(pMentoring, &UIMentoringDialog::IsAvailable);
        m_defs.SetAt(pDef->m_nId, pDef);
    }
    UIDailyMissionDialog* pDailyMission = FindUIDialog<UIDailyMissionDialog>(0x4f53);
    {
        CGameMenuDef* pDef = new CGameMenuDef();
        pDef->m_nId = 43;
        pDef->m_strName = "dailymission";
        pDef->m_strLabel = "$s_gamemenu_popup_dailymission";
        pDef->m_strTooltip = L"s_tooltip_gamemenu_dailymission";
        pDef->m_nKeyBind = 400036;
        pDef->m_nUiId = 0x4f53;
        pDef->m_isEnabled.Bind(pDailyMission, reinterpret_cast<int (UIDailyMissionDialog::*)()>(&UIDailyMissionDialog::FUN_140bffff0));
        m_defs.SetAt(pDef->m_nId, pDef);
    }
    {
        CGameMenuDef* pDef = new CGameMenuDef();
        pDef->m_nId = 44;
        pDef->m_strName = "fame";
        pDef->m_strLabel = "$s_gamemenu_popup_fame";
        pDef->m_strTooltip = L"s_tooltip_gamemenu_fame";
        pDef->m_nUiId = 0x4f54;
        pDef->m_onClick.Bind(pGameMenu, &UIGameMenuDialog::FUN_14193cea0);
        m_defs.SetAt(pDef->m_nId, pDef);
    }
    {
        CGameMenuDef* pDef = new CGameMenuDef();
        pDef->m_nId = 45;
        pDef->m_strName = "gallery";
        pDef->m_strLabel = "$s_gamemenu_popup_galleryevent";
        pDef->m_strTooltip = L"s_tooltip_gamemenu_gallery";
        pDef->m_nUiId = 0x4f59;
        pDef->m_onClick.Bind(pGameMenu, &UIGameMenuDialog::FUN_14193cf60);
        m_defs.SetAt(pDef->m_nId, pDef);
    }
    {
        CGameMenuDef* pDef = new CGameMenuDef();
        pDef->m_nId = 46;
        pDef->m_strName = "skyFortress";
        pDef->m_strLabel = "$s_gamemenu_popup_sky_fortress";
        pDef->m_strTooltip = L"s_tooltip_gamemenu_sky_fortress";
        pDef->m_onClick.Bind(pGameMenu, &UIGameMenuDialog::FUN_14193d030);
        m_defs.SetAt(pDef->m_nId, pDef);
    }
    {
        CGameMenuDef* pDef = new CGameMenuDef();
        pDef->m_nId = 47;
        pDef->m_strName = "rps";
        pDef->m_strLabel = "$s_gamemenu_popup_rps";
        pDef->m_strTooltip = L"s_tooltip_gamemenu_rps";
        pDef->m_nUiId = 0x4f5f;
        pDef->m_onClick.Bind(pGameMenu, &UIGameMenuDialog::FUN_14193d250);
        m_defs.SetAt(pDef->m_nId, pDef);
    }
    {
        CGameMenuDef* pDef = new CGameMenuDef();
        pDef->m_nId = 48;
        pDef->m_strName = "characterSelect";
        pDef->m_strLabel = "$s_gamemenu_popup_characterselect";
        pDef->m_strTooltip = L"s_tooltip_gamemenu_characterselect";
        pDef->m_onClick.Bind(pGameMenu, &UIGameMenuDialog::FUN_14193d3d0);
        m_defs.SetAt(pDef->m_nId, pDef);
    }
    {
        CGameMenuDef* pDef = new CGameMenuDef();
        pDef->m_nId = 49;
        pDef->m_strName = "end";
        pDef->m_strLabel = "$s_gamemenu_popup_end";
        pDef->m_strTooltip = L"s_tooltip_gamemenu_end";
        pDef->m_onClick.Bind(pGameMenu, &UIGameMenuDialog::FUN_14193d400);
        m_defs.SetAt(pDef->m_nId, pDef);
    }
    {
        CGameMenuDef* pDef = new CGameMenuDef();
        pDef->m_nId = 51;
        pDef->m_strName = "adventure_level";
        pDef->m_strLabel = "$s_gamemenu_popup_adventure_level";
        pDef->m_strTooltip = L"s_tooltip_gamemenu_adventure_level";
        if (FUN_140166410()->FUN_14036d570(251))
            pDef->m_nUiId = 0x4f67;
        else
            pDef->m_nUiId = 0x4f87;
        m_defs.SetAt(pDef->m_nId, pDef);
    }
    if (FUN_140166410()->FUN_14036d570(199))
    {
        CGameMenuDef* pDef = new CGameMenuDef();
        pDef->m_nId = 52;
        pDef->m_strName = "world_champion";
        pDef->m_strLabel = "$s_gamemenu_popup_world_champion";
        pDef->m_strTooltip = L"s_tooltip_gamemenu_world_champion";
        pDef->m_onClick.Bind(pGameMenu, &UIGameMenuDialog::FUN_14193d520);
        m_defs.SetAt(pDef->m_nId, pDef);
    }
    {
        CGameMenuDef* pDef = new CGameMenuDef();
        pDef->m_nId = 53;
        pDef->m_strName = "cashAttend";
        pDef->m_strLabel = "$s_gamemenu_popup_cashAttend";
        pDef->m_strTooltip = L"s_tooltip_gamemenu_cashAttend";
        pDef->m_nUiId = 0x4eb9;
        pDef->m_onClick.Bind(pGameMenu, &UIGameMenuDialog::FUN_14193d560);
        m_defs.SetAt(pDef->m_nId, pDef);
    }
    UIChangeJobDialog* pChangeJob = FindUIDialog<UIChangeJobDialog>(0x4f6b);
    {
        CGameMenuDef* pDef = new CGameMenuDef();
        pDef->m_nId = 54;
        pDef->m_strName = "jobchange";
        pDef->m_strLabel = "$s_gamemenu_popup_changejob";
        pDef->m_strTooltip = L"s_tooltip_gamemenu_changejob";
        pDef->m_onClick.Bind(pGameMenu, &UIGameMenuDialog::FUN_14193d590);
        pDef->m_isEnabled.Bind(pChangeJob, &UIChangeJobDialog::FUN_140bd88e0);
        m_defs.SetAt(pDef->m_nId, pDef);
    }
    if (FUN_140166410()->FUN_14036d570(211))
    {
        CGameMenuDef* pDef = new CGameMenuDef();
        pDef->m_nId = 55;
        pDef->m_strName = "lapenshard";
        pDef->m_strLabel = "$s_gamemenu_btn_lapenshard";
        pDef->m_strTooltip = L"s_tooltip_gamemenu_lapenshard";
        pDef->m_nUiId = 0x4f6d;
        m_defs.SetAt(pDef->m_nId, pDef);
    }
    {
        CGameMenuDef* pDef = new CGameMenuDef();
        pDef->m_nId = 57;
        pDef->m_strName = "coupledance";
        pDef->m_strLabel = "$s_gamemenu_popup_coupledance";
        pDef->m_strTooltip = L"s_tooltip_gamemenu_coupledance";
        pDef->m_nUiId = 0x4f71;
        pDef->m_onClick.Bind(pGameMenu, &UIGameMenuDialog::FUN_14193d320);
        m_defs.SetAt(pDef->m_nId, pDef);
    }
    {
        CGameMenuDef* pDef = new CGameMenuDef();
        pDef->m_nId = 59;
        pDef->m_strName = "pssbshop";
        pDef->m_strLabel = "$s_gamemenu_btn_pssbshop";
        pDef->m_strTooltip = L"s_tooltip_gamemenu_pssbshop";
        pDef->m_onClick.Bind(pGameMenu, &UIGameMenuDialog::FUN_14193d5c0);
        m_defs.SetAt(pDef->m_nId, pDef);
    }
    {
        CGameMenuDef* pDef = new CGameMenuDef();
        pDef->m_nId = 60;
        pDef->m_strName = "collectitemgroupevent";
        pDef->m_strLabel = "$s_gamemenu_btn_collectitemgroupevent";
        pDef->m_strTooltip = L"s_tooltip_gamemenu_collectitemgroupevent";
        pDef->m_nUiId = 0x4f81;
        m_defs.SetAt(pDef->m_nId, pDef);
    }
    {
        CGameMenuDef* pDef = new CGameMenuDef();
        pDef->m_nId = 61;
        pDef->m_strName = "bingoevent";
        pDef->m_strLabel = "$s_gamemenu_btn_bingoevent";
        pDef->m_strTooltip = L"s_tooltip_gamemenu_bingoevent";
        pDef->m_nUiId = 0x4f83;
        m_defs.SetAt(pDef->m_nId, pDef);
    }
    UIPaybackDialog* pPayback = FUN_140a8c5f0(0x4f93);
    {
        CGameMenuDef* pDef = new CGameMenuDef();
        pDef->m_nId = 62;
        pDef->m_strName = "payback";
        pDef->m_strLabel = "$s_gamemenu_btn_payback";
        pDef->m_strTooltip = L"s_tooltip_gamemenu_payback";
        pDef->m_onClick.Bind(pGameMenu, &UIGameMenuDialog::FUN_14193d700);
        pDef->m_nUiId = 0x4f93;
        pDef->m_isEnabled.Bind(pPayback, &UIPaybackDialog::FUN_140e6f890);
        m_defs.SetAt(pDef->m_nId, pDef);
    }
    {
        CGameMenuDef* pDef = new CGameMenuDef();
        pDef->m_nId = 63;
        pDef->m_strName = "wedding";
        pDef->m_strLabel = "$s_gamemenu_btn_wedding";
        pDef->m_strTooltip = L"s_tooltip_gamemenu_wedding";
        pDef->m_nUiId = 0x4f8c;
        m_defs.SetAt(pDef->m_nId, pDef);
    }
    {
        CGameMenuDef* pDef = new CGameMenuDef();
        pDef->m_nId = 64;
        pDef->m_strName = "longtermattendgift";
        pDef->m_strLabel = "$s_gamemenu_popup_longtermattendgift";
        pDef->m_strTooltip = L"s_tooltip_gamemenu_longtermattendgift";
        pDef->m_nUiId = 0x4f98;
        pDef->m_onClick.Bind(pGameMenu, &UIGameMenuDialog::FUN_14193c660);
        m_defs.SetAt(pDef->m_nId, pDef);
    }
    {
        CGameMenuDef* pDef = new CGameMenuDef();
        pDef->m_nId = 1000;
        pDef->m_strName = "marketgroup";
        pDef->m_strLabel = "$s_gamemenu_btn_market_group";
        m_defs.SetAt(pDef->m_nId, pDef);
    }
    {
        CGameMenuDef* pDef = new CGameMenuDef();
        pDef->m_nId = 1001;
        pDef->m_strName = "charactergroup";
        pDef->m_strLabel = "$s_gamemenu_btn_character_group";
        m_defs.SetAt(pDef->m_nId, pDef);
    }
    {
        CGameMenuDef* pDef = new CGameMenuDef();
        pDef->m_nId = 1002;
        pDef->m_strName = "contentsgroup";
        pDef->m_strLabel = "$s_gamemenu_btn_contents_group";
        m_defs.SetAt(pDef->m_nId, pDef);
    }
    {
        CGameMenuDef* pDef = new CGameMenuDef();
        pDef->m_nId = 1004;
        pDef->m_strName = "communitygroup";
        pDef->m_strLabel = "$s_gamemenu_btn_community_group";
        m_defs.SetAt(pDef->m_nId, pDef);
    }
    {
        CGameMenuDef* pDef = new CGameMenuDef();
        pDef->m_nId = 1003;
        pDef->m_strName = "gamegroup";
        pDef->m_strLabel = "$s_gamemenu_btn_game_group";
        m_defs.SetAt(pDef->m_nId, pDef);
    }
    {
        CGameMenuDef* pDef = new CGameMenuDef();
        pDef->m_nId = 2000;
        pDef->m_strName = "optiongroup_gamepad";
        pDef->m_strLabel = "$s_gamemenu_btn_systemgroup";
        m_defs.SetAt(pDef->m_nId, pDef);
    }
    {
        CGameMenuDef* pDef = new CGameMenuDef();
        pDef->m_nId = 2001;
        pDef->m_strName = "charactergroup_gamepad";
        pDef->m_strLabel = "$s_gamemenu_btn_character_group";
        m_defs.SetAt(pDef->m_nId, pDef);
    }
    {
        CGameMenuDef* pDef = new CGameMenuDef();
        pDef->m_nId = 2002;
        pDef->m_strName = "contentsgroup_gamepad";
        pDef->m_strLabel = "$s_gamemenu_btn_contents_group";
        m_defs.SetAt(pDef->m_nId, pDef);
    }
    {
        CGameMenuDef* pDef = new CGameMenuDef();
        pDef->m_nId = 2003;
        pDef->m_strName = "gamegroup_gamepad";
        pDef->m_strLabel = "$s_gamemenu_btn_game_group";
        m_defs.SetAt(pDef->m_nId, pDef);
    }
    {
        CGameMenuDef* pDef = new CGameMenuDef();
        pDef->m_nId = 2004;
        pDef->m_strName = "communitygroup_gamepad";
        pDef->m_strLabel = "$s_gamemenu_btn_community_group";
        m_defs.SetAt(pDef->m_nId, pDef);
    }
    {
        CGameMenuDef* pDef = new CGameMenuDef();
        pDef->m_nId = 2005;
        pDef->m_strName = "marketgroup_gamepad";
        pDef->m_strLabel = "$s_gamemenu_btn_market_group";
        m_defs.SetAt(pDef->m_nId, pDef);
    }
    return 1;
}

// @0x140cf6ef0
int CGameMenuTable::LoadXml()
{
    CString strPath = FUN_14071a5b0("Table", "gameMenu.xml");
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return 0;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_14015eb90(FUN_140166440(), 1, 0x13, L"xml \xd615\xc2dd\xc774 \xc798\xbabb \xb418\xc5c8\xc2b5\xb2c8\xb2e4[<ms2> {0}]", strPath);
        return 0;
    }
    for (Unk_140165cf0* pSet = pRoot->FUN_140165cf0("menuSet"); pSet != 0; pSet = pSet->FUN_140168650("menuSet"))
    {
        if (!FUN_14028f710(pSet))
            continue;
        {
            EGameMenuSet eSet = GAMEMENU_SET_GAME;
            XmlEnumName<EGameMenuSet, ParseGameMenuSet>(pSet, "type", eSet);
            for (Unk_140165cf0* pMenu = pSet->FUN_140165cf0("menu"); pMenu != 0; pMenu = pMenu->FUN_140168650("menu"))
            {
                if (!FUN_14028f710(pMenu))
                    continue;
                {
                    MS2Ptr<CGameMenuItem> spItem(new CGameMenuItem());
                    spItem->Load(pMenu);
                    m_sets[eSet].Add(spItem);
                }
            }
        }
    }
    return 1;
}

// @0x140cf71f0
int CGameMenuTable::IsChild(int nId, EGameMenuSet eSet) const
{
    int nTopId = FindTopId(nId, eSet);
    return nTopId != nId;
}
MS2_REPLACE_METHOD(0x140CF71F0, CGameMenuTable, IsChild, 78, 0x72C36741);

// @0x140cf7250
int CGameMenuTable::IsAffectedBy(NotifyGameEventChanged* pNotify, EGameMenuSet eSet) const
{
    const ATL::CAtlArray<MS2Ptr<CGameMenuItem> >& items = m_sets[eSet];
    for (size_t i = 0; i < items.GetCount(); ++i)
    {
        if (items[i]->IsAffectedBy(pNotify))
            return true;
    }
    return false;
}
MS2_REPLACE_METHOD(0x140CF7250, CGameMenuTable, IsAffectedBy, 143, 0x7CCF295F);

// @0x140cf72f0
int CGameMenuTable::FindTopId(int nId, EGameMenuSet eSet) const
{
    const ATL::CAtlArray<MS2Ptr<CGameMenuItem> >& items = m_sets[eSet];
    for (size_t i = 0; i < items.GetCount(); ++i)
    {
        if (items[i]->HasId(nId))
            return items[i]->m_nId;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x140CF72F0, CGameMenuTable, FindTopId, 162, 0x0251C249);

// @0x140cf73a0
int CGameMenuTable::FindIdByUiId(int nUiId)
{
    for (POSITION pos = m_defs.GetHeadPosition(); pos != 0; m_defs.GetNext(pos))
    {
        MS2Ptr<CGameMenuDef> spDef = m_defs.GetValueAt(pos);
        if (spDef->m_nUiId == nUiId)
            return m_defs.GetKeyAt(pos);
    }
    return 0;
}
MS2_REPLACE_METHOD(0x140CF73A0, CGameMenuTable, FindIdByUiId, 197, 0x2851240F);

// @0x140cf7470
MS2Ptr<CGameMenuDef> CGameMenuTable::FindByName(CString strName)
{
    for (POSITION pos = m_defs.GetHeadPosition(); pos != 0; m_defs.GetNext(pos))
    {
        MS2Ptr<CGameMenuDef> spDef = m_defs.GetValueAt(pos);
        if (spDef->m_strName == strName)
            return spDef;
    }
    return MS2Ptr<CGameMenuDef>(0);
}
MS2_REPLACE_METHOD(0x140CF7470, CGameMenuTable, FindByName, 278, 0x8F2F714A);

// @0x140cf7590
MS2Ptr<CGameMenuDef> CGameMenuTable::FindByUiId(int nUiId)
{
    for (POSITION pos = m_defs.GetHeadPosition(); pos != 0; m_defs.GetNext(pos))
    {
        MS2Ptr<CGameMenuDef> spDef = m_defs.GetValueAt(pos);
        if (spDef->m_nUiId == nUiId)
            return spDef;
    }
    return MS2Ptr<CGameMenuDef>(0);
}
MS2_REPLACE_METHOD(0x140CF7590, CGameMenuTable, FindByUiId, 236, 0xECABEF08);

// @0x140cf7690
MS2Ptr<CGameMenuDef> CGameMenuTable::Find(int nId)
{
    MS2Ptr<CGameMenuDef> spDef(0);
    m_defs.Lookup(nId, spDef);
    return spDef;
}
MS2_REPLACE_METHOD(0x140CF7690, CGameMenuTable, Find, 122, 0x24D2C2FC);

// @0x140cf7710
void CGameMenuTable::GetTopItems(ATL::CAtlArray<MS2Ptr<CGameMenuItem> >& out, EGameMenuSet eSet) const
{
    const ATL::CAtlArray<MS2Ptr<CGameMenuItem> >& items = m_sets[eSet];
    for (unsigned int i = 0; i < items.GetCount(); ++i)
        out.Add(items[i]);
}
MS2_REPLACE_METHOD(0x140CF7710, CGameMenuTable, GetTopItems, 128, 0x31E87B79);

// @0x140cf77a0
MS2Ptr<CGameMenuItem> CGameMenuTable::FindTopItem(int nId, EGameMenuSet eSet) const
{
    const ATL::CAtlArray<MS2Ptr<CGameMenuItem> >& items = m_sets[eSet];
    for (size_t i = 0; i < items.GetCount(); ++i)
    {
        MS2Ptr<CGameMenuItem> spItem = items[i];
        if (spItem->m_nId == nId)
            return spItem;
    }
    return MS2Ptr<CGameMenuItem>(0);
}
MS2_REPLACE_METHOD(0x140CF77A0, CGameMenuTable, FindTopItem, 245, 0x12C60E4B);

// @0x140cf78a0
MS2Ptr<CGameMenuItem> CGameMenuTable::FindItem(int nId, EGameMenuSet eSet) const
{
    const ATL::CAtlArray<MS2Ptr<CGameMenuItem> >& items = m_sets[eSet];
    for (size_t i = 0; i < items.GetCount(); ++i)
    {
        MS2Ptr<CGameMenuItem> spItem = items[i];
        if (spItem->m_nId == nId)
            return spItem;
        for (size_t j = 0; j < spItem->m_children.GetCount(); ++j)
        {
            if (spItem->m_children[j]->m_nId == nId)
                return spItem->m_children[j];
        }
    }
    return MS2Ptr<CGameMenuItem>(0);
}
MS2_REPLACE_METHOD(0x140CF78A0, CGameMenuTable, FindItem, 431, 0x11E7AC58);

// @0x140cf7a60
EGameMenuFilter ParseGameMenuFilter(const CStringA& str)
{
    if (str.IsEmpty())
        return GAMEMENU_FILTER_NONE;
    if (str.CompareNoCase("eventID") == 0)
        return GAMEMENU_FILTER_EVENT_ID;
    if (str.CompareNoCase("eventType") == 0)
        return GAMEMENU_FILTER_EVENT_TYPE;
    else if (str.CompareNoCase("attendGift") == 0)
        return GAMEMENU_FILTER_ATTEND_GIFT;
    else if (str.CompareNoCase("cashAttend") == 0)
        return GAMEMENU_FILTER_CASH_ATTEND;
    else if (str.CompareNoCase("season") == 0)
        return GAMEMENU_FILTER_SEASON;
    return GAMEMENU_FILTER_NONE;
}
MS2_REPLACE(0x140CF7A60, ParseGameMenuFilter, 186, 0x862A7B7E);

// @0x140cf7b30
EGameMenuSet ParseGameMenuSet(const CStringA& str)
{
    if (str.CompareNoCase("game") == 0)
        return GAMEMENU_SET_GAME;
    if (str.CompareNoCase("gamePad") == 0)
        return GAMEMENU_SET_GAMEPAD;
    else if (str.CompareNoCase("mushkingRoyal") == 0)
        return GAMEMENU_SET_MUSHKING_ROYAL;
    else if (str.CompareNoCase("mushkingRoyalPad") == 0)
        return GAMEMENU_SET_MUSHKING_ROYAL_PAD;
    return GAMEMENU_SET_GAME;
}
MS2_REPLACE(0x140CF7B30, ParseGameMenuSet, 129, 0x549128AE);
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca45d0-0x142ca4630 .text$yd
