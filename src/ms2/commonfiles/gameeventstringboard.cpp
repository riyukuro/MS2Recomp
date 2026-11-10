// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). See gameeventstringboard.h.
// MS2-UNIT: ?\gameeventstringboard.cpp
// MS2-RANGE: 0x1400b8cf0-0x1400b8d40 .text$di
// MS2-RANGE: 0x14041e930-0x14041eeb0 .text$mn
// MS2-PIN: ??__Es_regStringBoardLink@@YAXXZ 0x1400b8cf0 ; manual: registers the out-of-unit factory name below
// MS2-PIN: ??1GameEventStringBoard@@UEAA@XZ 0x14041edf0 ; implicit dtor (header declares it `= default`)
// MS2-PIN: ??1GameEventStringBoardLink@@UEAA@XZ 0x14041ee10 ; implicit dtor
// MS2-PIN: ??_GGameEventStringBoard@@UEAAPEAXI@Z 0x14041ee30 ; prop
// MS2-PIN: ??_GGameEventStringBoardLink@@UEAAPEAXI@Z 0x14041ee70 ; prop
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\gameeventstringboard.cpp"

#include "ms2/placeholder/ms2stdafx.h"
#include "gameeventstringboard.h"
#include "ms2/placeholder/cgamerule.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/classobject.h"   // C3: ClassObjectRegistrar (0x140316aa0)

// Out-of-unit helpers.
// The string id of a GameEvent string field (commonutil).
int FUN_140718200(const CStringW& text);
// Stream helpers (CInputStream / COutputStream operator<< / >> overloads, packet.cpp).
COutputStream & FUN_14070f9a0(COutputStream &, unsigned int);  // C3: the definition's signature
COutputStream & WriteUnicodeString(COutputStream &, const CStringW &);  // C3: the definition's signature
void* GetGameRule();   // C3: was GetGameRule

// The factories of this unit (they are defined further down, in exe order).
GameEvent* CreateGameEventStringBoard();
GameEvent* CreateGameEventStringBoardLink();

// ---- dynamic initializers ----
// The registration of the link event (GameEventStringBoard itself is registered by the neighbouring shut-down unit,
// which holds 0x14041e930 as an out-of-unit factory).
#ifndef MS2_HOOK_DLL
static ClassObjectRegistrar s_regStringBoardLink(L"GameEventStringBoardLink", (ClassObjectCreateFn)CreateGameEventStringBoardLink);   // 0x143aaeed3
#endif

// ---- GameEventStringBoard --------------------------------------------------------------------------------------------

// @0x14041e930
GameEvent* CreateGameEventStringBoard() { return new GameEventStringBoard; }

// @0x14041e990
CStringW GameEventStringBoard::GetTypeName() { return CStringW(L"GameEventStringBoard"); }

// @0x14041e9e0
GameEventStringBoard::GameEventStringBoard() : m_nId(0)
{
    SetFlag(1);
    SetFlag(3);
}

// The id is only derived when the xml field is set (an empty m_68 leaves m_nId at 0).
// @0x14041ea50
void GameEventStringBoard::vfunc_2()
{
    if (!m_68.IsEmpty())
        m_nId = FUN_140718200(m_68);
}

// @0x14041eaa0
void GameEventStringBoard::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    FUN_14070f9a0(*(COutputStream *)out, m_nId);
    WriteUnicodeString(*(COutputStream *)out, m_80);
}

// @0x14041eb00
void GameEventStringBoard::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    ((class Unk_GEReader*)&((class Unk_OSInput*)(class Unk_GEReader*)(&in->reader))->Read6(*(unsigned int*)(&m_nId)));
    ((class Unk_OSInput*)(class Unk_GEReader*)(&in->reader))->Read11(m_80);
}

// @0x14041eb60
void GameEventStringBoard::OnStart() {}

// @0x14041eb70
void GameEventStringBoard::vfunc_6() {}

// ---- GameEventStringBoardLink ----------------------------------------------------------------------------------------

// @0x14041eb80
GameEvent* CreateGameEventStringBoardLink() { return new GameEventStringBoardLink; }

// @0x14041ebe0
CStringW GameEventStringBoardLink::GetTypeName() { return CStringW(L"GameEventStringBoardLink"); }

// @0x14041ec30
GameEventStringBoardLink::GameEventStringBoardLink()
{
    SetFlag(1);
    SetFlag(3);
}

// @0x14041ec90
void GameEventStringBoardLink::vfunc_2() {}

// @0x14041eca0
void GameEventStringBoardLink::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    WriteUnicodeString(*(COutputStream *)out, m_68);
}

// @0x14041ece0
void GameEventStringBoardLink::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    ((class Unk_OSInput*)(class Unk_GEReader*)(&in->reader))->Read11(m_68);
}

// @0x14041ed30
void GameEventStringBoardLink::OnStart() { ((class CGameRule*)GetGameRule())->FUN_14047dae0(m_68); }

// @0x14041ed90
void GameEventStringBoardLink::vfunc_6() { ((class CGameRule*)GetGameRule())->FUN_14047dae0(CStringW(L"")); }
