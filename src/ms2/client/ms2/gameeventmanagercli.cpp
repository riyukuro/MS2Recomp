// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). GameEventManagerCli: the client's running game events.
// See ms2/placeholder/gameeventmanagercli.h.
// MS2-UNIT: client\ms2\gameeventmanagercli.cpp
// MS2-RANGE: 0x140ceaa70-0x140cfad00 .text$mn
// MS2-RANGE: 0x1400d1640-0x1400d16f0 .text$di
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\gameeventmanagercli.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/gameeventmanagercli.h"
#include "ms2/commonfiles/gameevent.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/classobject.h"
#include "ms2/placeholder/notifysystem.h"
#include "ms2/placeholder/notifygameeventchanged.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// Namespace-scope statics of a shared game header (see ms2/placeholder/header_statics_a.h; this unit has only these).
static CString s_strSkill = "skill";
static CString s_strStun = "stun";
static Unk_1402a9d70 s_unk1402a9d70(17, 0.75f, 0.25f, 2.25f, 10);

NotifySystem* FUN_140939a10();                                  // TSingleton<NotifySystem>::GetInstance

// @0x140ceaa70
GameEventManagerCli::GameEventManagerCli()
{
}

// @0x140ceab00
GameEventManagerCli::~GameEventManagerCli()
{
}

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

// @0x140ceacd0
MS2Ptr<GameEvent> GameEventManagerCli::Find(int nId)
{
    MS2Ptr<GameEvent> gameEvent;
    if (m_events.Lookup(nId, gameEvent))
        return gameEvent;
    return MS2Ptr<GameEvent>(0);
}

// @0x140cead80
bool GameEventManagerCli::IsEnabled(CStringW strName)
{
    std::map<CStringW, unsigned int>::iterator it = m_states.find(strName);
    if (it == m_states.end())
        return false;
    return it->second > 0;
}

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

// @0x140ceba50
void GameEventManagerCli::Update(MS2Ptr<GameEvent> gameEvent)
{
    MS2Ptr<GameEvent> prevEvent;
    m_events.Lookup(gameEvent->GetID(), prevEvent);
    m_events.SetAt(gameEvent->GetID(), gameEvent);
    gameEvent->vfunc_7(prevEvent);
}

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

// @0x140cedbf0
inline NotifyGameEventChanged::NotifyGameEventChanged(int id, CStringW eventName, int type)
    : m_id(id), m_eventName(eventName), m_type(type)
{
}

// End of the original gameeventmanagercli.cpp COMDAT tail: its UCRT memmove_s copy. The CGameMenuTable code after it
// (0x140cf08d0..) is a second original TU that units.tsv merged into this range.
// @0x140cf07b0
MS2_EMIT_CRT_MEMMOVE_S_COPY(1);
