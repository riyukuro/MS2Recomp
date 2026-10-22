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

// Out-of-unit helpers.
// Constructor at 0x140316aa0: registers the factory under the name (the by-value CString is destroyed by the callee).
struct Unk_GEFactoryRegistry {
    Unk_GEFactoryRegistry(CStringW name, GameEvent* (*create)());
    char m_pad;
};
// The string id of a GameEvent string field (commonutil).
int FUN_140718200(CStringW* text);
// Stream helpers (CInputStream / COutputStream operator<< / >> overloads, packet.cpp).
Unk_GEOut* FUN_14070f9a0(Unk_GEOut* out, int value);
Unk_GEOut* FUN_14070fae0(Unk_GEOut* out, const CStringW* text);
Unk_GEReader* FUN_14070f480(Unk_GEReader* in, int* value);
Unk_GEReader* FUN_14070f5f0(Unk_GEReader* in, CStringW* text);
CGameRule* FUN_1401c0d90();   // TSingleton<CGameRule>::GetInstance

// The factories of this unit (they are defined further down, in exe order).
GameEvent* FUN_14041e930();
GameEvent* FUN_14041eb80();

// ---- dynamic initializers ----
// The registration of the link event (GameEventStringBoard itself is registered by the neighbouring shut-down unit,
// which holds 0x14041e930 as an out-of-unit factory).
#ifndef MS2_HOOK_DLL
static Unk_GEFactoryRegistry s_regStringBoardLink(L"GameEventStringBoardLink", FUN_14041eb80);   // 0x143aaeed3
#endif

// ---- GameEventStringBoard --------------------------------------------------------------------------------------------

// @0x14041e930
GameEvent* FUN_14041e930() { return new GameEventStringBoard; }

// @0x14041e990
CStringW GameEventStringBoard::vfunc_1() { return CStringW(L"GameEventStringBoard"); }

// @0x14041e9e0
GameEventStringBoard::GameEventStringBoard() : m_nId(0)
{
    FUN_1402e3480(1);
    FUN_1402e3480(3);
}

// The id is only derived when the xml field is set (an empty m_68 leaves m_nId at 0).
// @0x14041ea50
void GameEventStringBoard::vfunc_2()
{
    if (!m_68.IsEmpty())
        m_nId = FUN_140718200(&m_68);
}

// @0x14041eaa0
void GameEventStringBoard::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    FUN_14070f9a0(out, m_nId);
    FUN_14070fae0(out, &m_80);
}

// @0x14041eb00
void GameEventStringBoard::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    FUN_14070f480(&in->reader, &m_nId);
    FUN_14070f5f0(&in->reader, &m_80);
}

// @0x14041eb60
void GameEventStringBoard::OnStart() {}

// @0x14041eb70
void GameEventStringBoard::vfunc_6() {}

// ---- GameEventStringBoardLink ----------------------------------------------------------------------------------------

// @0x14041eb80
GameEvent* FUN_14041eb80() { return new GameEventStringBoardLink; }

// @0x14041ebe0
CStringW GameEventStringBoardLink::vfunc_1() { return CStringW(L"GameEventStringBoardLink"); }

// @0x14041ec30
GameEventStringBoardLink::GameEventStringBoardLink()
{
    FUN_1402e3480(1);
    FUN_1402e3480(3);
}

// @0x14041ec90
void GameEventStringBoardLink::vfunc_2() {}

// @0x14041eca0
void GameEventStringBoardLink::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    FUN_14070fae0(out, &m_68);
}

// @0x14041ece0
void GameEventStringBoardLink::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    FUN_14070f5f0(&in->reader, &m_68);
}

// @0x14041ed30
void GameEventStringBoardLink::OnStart() { FUN_1401c0d90()->FUN_14047dae0(m_68); }

// @0x14041ed90
void GameEventStringBoardLink::vfunc_6() { FUN_1401c0d90()->FUN_14047dae0(CStringW(L"")); }
