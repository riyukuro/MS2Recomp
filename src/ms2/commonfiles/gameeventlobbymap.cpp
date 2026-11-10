// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). GameEvent subclasses: LobbyMap, LoginNotice,
// CharacterCountRestricted, OnlinePatch (+ the registration of ReturnUser, whose class follows this range).
// MS2-UNIT: ?\gameeventlobbymap.cpp
// MS2-RANGE: 0x1400b8700-0x1400b8890 .text$di
// MS2-RANGE: 0x14041c1a0-0x14041cb50 .text$mn
// MS2-PIN: ??__Es_regCharacterCountRestricted@@YAXXZ 0x1400b8700
// MS2-PIN: ??__Es_regLobbyMap@@YAXXZ 0x1400b8750
// MS2-PIN: ??__Es_regLoginNotice@@YAXXZ 0x1400b87a0
// MS2-PIN: ??__Es_regOnlinePatch@@YAXXZ 0x1400b87f0
// MS2-PIN: ??__Es_regReturnUser@@YAXXZ 0x1400b8840
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\gameeventlobbymap.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "gameeventlobbymap.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/classobject.h"   // C3: ClassObjectRegistrar (0x140316aa0)
#include "ms2/placeholder/cgameeventvaluemanager.h"

// Out-of-unit helpers.
GameEvent* CreateGameEventReturnUser();   // ReturnUser factory (next unit)
int FUN_140718200(const CStringW& text);
COutputStream & FUN_14070f9a0(COutputStream &, unsigned int);  // C3: the definition's signature

struct Unk_GESub { char m_pad; };
class Unk_GameEventValue408   // C3: member view for the former free stand-ins
{
public:
    void Reset();
    void SetValue(unsigned int);
};
class Unk_GEManagerB {
public:
    // @0x14041cb30
    Unk_GESub* GetSub() { return &m_sub; }
private:
    char m_pad[0x408];
    Unk_GESub m_sub;
};
struct Unk_GEManagerA { char m_pad[0x8e8]; int m_lobbyMap; };
void* GetGameRule();   // C3: was GetGameRule
class CGameRule   // C3: member view for the former free stand-ins
{
public:
    void SetLobbyMap(int);
    void SetLoginNotice(bool, class CMsTime const&);
};

GameEvent* CreateGameEventLobbyMap();
GameEvent* CreateGameEventLoginNotice();
GameEvent* CreateGameEventCharacterCountRestricted();
GameEvent* CreateGameEventOnlinePatch();

#ifndef MS2_HOOK_DLL
// Registration of the event factories by name (dynamic initializers).
static ClassObjectRegistrar s_regCharacterCountRestricted(L"GameEventCharacterCountRestricted", (ClassObjectCreateFn)CreateGameEventCharacterCountRestricted);   // 0x143aaeec2
static ClassObjectRegistrar s_regLobbyMap(L"GameEventLobbyMap", (ClassObjectCreateFn)CreateGameEventLobbyMap);                                  // 0x143aaeec0
static ClassObjectRegistrar s_regLoginNotice(L"GameEventLoginNotice", (ClassObjectCreateFn)CreateGameEventLoginNotice);                            // 0x143aaeec1
static ClassObjectRegistrar s_regOnlinePatch(L"GameEventOnlinePatch", (ClassObjectCreateFn)CreateGameEventOnlinePatch);                            // 0x143aaeec3
static ClassObjectRegistrar s_regReturnUser(L"GameEventReturnUser", (ClassObjectCreateFn)CreateGameEventReturnUser);                              // 0x143aaeec4
#endif

// @0x14041c1a0
GameEvent* CreateGameEventLobbyMap() { return new GameEventLobbyMap; }

// @0x14041c200
CStringW GameEventLobbyMap::GetTypeName() { return CStringW(L"GameEventLobbyMap"); }

// @0x14041c250
GameEventLobbyMap::GameEventLobbyMap() : m_mapId(0)
{
    SetFlag(2);
    SetFlag(3);
}

// @0x14041c2c0
void GameEventLobbyMap::vfunc_2() { m_mapId = FUN_140718200(m_68); }

// @0x14041c2f0
void GameEventLobbyMap::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteInt(m_mapId);
}

// @0x14041c340
void GameEventLobbyMap::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    m_mapId = MS2_GE_READ_INT(in);
}

// @0x14041c3a0
void GameEventLobbyMap::OnStart() { ((class CGameRule*)(struct Unk_GEManagerA*)(((struct Unk_GEManagerA*)GetGameRule())))->SetLobbyMap(m_mapId); }

// @0x14041c3d0
void GameEventLobbyMap::vfunc_6() { ((class CGameRule*)(struct Unk_GEManagerA*)(((struct Unk_GEManagerA*)GetGameRule())))->SetLobbyMap(0); }

// @0x14041c400
GameEvent* CreateGameEventLoginNotice() { return new GameEventLoginNotice; }

// @0x14041c460
CStringW GameEventLoginNotice::GetTypeName() { return CStringW(L"GameEventLoginNotice"); }

// @0x14041c4b0
GameEventLoginNotice::GameEventLoginNotice()
{
    SetFlag(2);
    SetFlag(3);
}

// @0x14041c510
void GameEventLoginNotice::vfunc_2() {}

// @0x14041c520
void GameEventLoginNotice::OnStart() { ((class CGameRule*)(struct Unk_GEManagerA*)(((struct Unk_GEManagerA*)GetGameRule())))->SetLoginNotice(true, *(class CMsTime const*)(&m_38)); }

// @0x14041c560
void GameEventLoginNotice::vfunc_6() { ((class CGameRule*)(struct Unk_GEManagerA*)(((struct Unk_GEManagerA*)GetGameRule())))->SetLoginNotice(false, *(class CMsTime const*)(&m_38)); }

// @0x14041c5a0
GameEvent* CreateGameEventCharacterCountRestricted() { return new GameEventCharacterCountRestricted; }

// @0x14041c600
CStringW GameEventCharacterCountRestricted::GetTypeName() { return CStringW(L"GameEventCharacterCountRestricted"); }

// @0x14041c650
GameEventCharacterCountRestricted::GameEventCharacterCountRestricted() : m_limit(1)
{
    SetFlag(2);
    SetFlag(3);
}

// @0x14041c6c0
void GameEventCharacterCountRestricted::vfunc_2()
{
    if (!m_68.IsEmpty())
        m_limit = FUN_140718200(m_68);
}

// @0x14041c710
void GameEventCharacterCountRestricted::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    FUN_14070f9a0(*(COutputStream *)out, m_limit);
}

// @0x14041c750
void GameEventCharacterCountRestricted::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    ((class Unk_GEReader*)&((class Unk_OSInput*)(class Unk_GEReader*)(&in->reader))->Read6(*(unsigned int*)(&m_limit)));
}

// @0x14041c7a0
void GameEventCharacterCountRestricted::OnStart()
{
    if (m_limit == 0)
        return;
    ((class Unk_GameEventValue408*)(struct Unk_GESub*)(reinterpret_cast<Unk_GEManagerB*>(TSingleton<CGameEventValueManager>::GetInstance())->GetSub()))->SetValue(m_limit);
}

// @0x14041c7f0
void GameEventCharacterCountRestricted::vfunc_6() { ((class Unk_GameEventValue408*)(struct Unk_GESub*)(reinterpret_cast<Unk_GEManagerB*>(TSingleton<CGameEventValueManager>::GetInstance())->GetSub()))->Reset(); }

// @0x14041c820
GameEvent* CreateGameEventOnlinePatch() { return new GameEventOnlinePatch; }

// @0x14041c880
CStringW GameEventOnlinePatch::GetTypeName() { return CStringW(L"GameEventOnlinePatch"); }

// @0x14041c8d0
GameEventOnlinePatch::GameEventOnlinePatch()
{
    SetFlag(2);
}

// @0x14041c920
void GameEventOnlinePatch::vfunc_2() {}

// @0x14041c930
void GameEventOnlinePatch::vfunc_3(Unk_GEOut* out) { GameEvent::vfunc_3(out); }

// @0x14041c960
void GameEventOnlinePatch::vfunc_4(Unk_GEIn* in) { GameEvent::vfunc_4(in); }

// @0x14041c990
void GameEventOnlinePatch::OnStart() {}

// @0x14041c9a0
void GameEventOnlinePatch::vfunc_6() {}
