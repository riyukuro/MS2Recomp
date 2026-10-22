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

// Out-of-unit helpers.
// Constructor at 0x140316aa0: registers the factory under the name (the by-value CString is destroyed by the callee).
struct Unk_GEFactoryRegistry {
    Unk_GEFactoryRegistry(CStringW name, GameEvent* (*create)());
    char m_pad;
};
GameEvent* FUN_14041cb50();   // ReturnUser factory (next unit)
int FUN_140718200(CStringW* text);
Unk_GEOut* FUN_14070f9a0(Unk_GEOut* out, int value);
Unk_GEReader* FUN_14070f480(Unk_GEReader* in, int* value);

struct Unk_GESub { char m_pad; };
void FUN_140424bc0(Unk_GESub* sub, int value);
void FUN_140424bf0(Unk_GESub* sub);
class Unk_GEManagerB {
public:
    // @0x14041cb30
    Unk_GESub* GetSub() { return &m_sub; }
private:
    char m_pad[0x408];
    Unk_GESub m_sub;
};
Unk_GEManagerB* FUN_140302b00();
struct Unk_GEManagerA { char m_pad[0x8e8]; int m_lobbyMap; };
Unk_GEManagerA* FUN_1401c0d90();
void FUN_14047b990(Unk_GEManagerA* mgr, int value);
void FUN_14047bb20(Unk_GEManagerA* mgr, bool on, CMsTime* notice);

GameEvent* FUN_14041c1a0();
GameEvent* FUN_14041c400();
GameEvent* FUN_14041c5a0();
GameEvent* FUN_14041c820();

#ifndef MS2_HOOK_DLL
// Registration of the event factories by name (dynamic initializers).
static Unk_GEFactoryRegistry s_regCharacterCountRestricted(L"GameEventCharacterCountRestricted", FUN_14041c5a0);   // 0x143aaeec2
static Unk_GEFactoryRegistry s_regLobbyMap(L"GameEventLobbyMap", FUN_14041c1a0);                                  // 0x143aaeec0
static Unk_GEFactoryRegistry s_regLoginNotice(L"GameEventLoginNotice", FUN_14041c400);                            // 0x143aaeec1
static Unk_GEFactoryRegistry s_regOnlinePatch(L"GameEventOnlinePatch", FUN_14041c820);                            // 0x143aaeec3
static Unk_GEFactoryRegistry s_regReturnUser(L"GameEventReturnUser", FUN_14041cb50);                              // 0x143aaeec4
#endif

// @0x14041c1a0
GameEvent* FUN_14041c1a0() { return new GameEventLobbyMap; }

// @0x14041c200
CStringW GameEventLobbyMap::vfunc_1() { return CStringW(L"GameEventLobbyMap"); }

// @0x14041c250
GameEventLobbyMap::GameEventLobbyMap() : m_mapId(0)
{
    FUN_1402e3480(2);
    FUN_1402e3480(3);
}

// @0x14041c2c0
void GameEventLobbyMap::vfunc_2() { m_mapId = FUN_140718200(&m_68); }

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
void GameEventLobbyMap::OnStart() { FUN_14047b990(FUN_1401c0d90(), m_mapId); }

// @0x14041c3d0
void GameEventLobbyMap::vfunc_6() { FUN_14047b990(FUN_1401c0d90(), 0); }

// @0x14041c400
GameEvent* FUN_14041c400() { return new GameEventLoginNotice; }

// @0x14041c460
CStringW GameEventLoginNotice::vfunc_1() { return CStringW(L"GameEventLoginNotice"); }

// @0x14041c4b0
GameEventLoginNotice::GameEventLoginNotice()
{
    FUN_1402e3480(2);
    FUN_1402e3480(3);
}

// @0x14041c510
void GameEventLoginNotice::vfunc_2() {}

// @0x14041c520
void GameEventLoginNotice::OnStart() { FUN_14047bb20(FUN_1401c0d90(), true, &m_38); }

// @0x14041c560
void GameEventLoginNotice::vfunc_6() { FUN_14047bb20(FUN_1401c0d90(), false, &m_38); }

// @0x14041c5a0
GameEvent* FUN_14041c5a0() { return new GameEventCharacterCountRestricted; }

// @0x14041c600
CStringW GameEventCharacterCountRestricted::vfunc_1() { return CStringW(L"GameEventCharacterCountRestricted"); }

// @0x14041c650
GameEventCharacterCountRestricted::GameEventCharacterCountRestricted() : m_limit(1)
{
    FUN_1402e3480(2);
    FUN_1402e3480(3);
}

// @0x14041c6c0
void GameEventCharacterCountRestricted::vfunc_2()
{
    if (!m_68.IsEmpty())
        m_limit = FUN_140718200(&m_68);
}

// @0x14041c710
void GameEventCharacterCountRestricted::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    FUN_14070f9a0(out, m_limit);
}

// @0x14041c750
void GameEventCharacterCountRestricted::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    FUN_14070f480(&in->reader, &m_limit);
}

// @0x14041c7a0
void GameEventCharacterCountRestricted::OnStart()
{
    if (m_limit == 0)
        return;
    FUN_140424bc0(FUN_140302b00()->GetSub(), m_limit);
}

// @0x14041c7f0
void GameEventCharacterCountRestricted::vfunc_6() { FUN_140424bf0(FUN_140302b00()->GetSub()); }

// @0x14041c820
GameEvent* FUN_14041c820() { return new GameEventOnlinePatch; }

// @0x14041c880
CStringW GameEventOnlinePatch::vfunc_1() { return CStringW(L"GameEventOnlinePatch"); }

// @0x14041c8d0
GameEventOnlinePatch::GameEventOnlinePatch()
{
    FUN_1402e3480(2);
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
