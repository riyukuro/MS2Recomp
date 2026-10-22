// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). See gameeventshutdown.h.
// MS2-UNIT: ?\gameeventshutdown.cpp
// MS2-RANGE: 0x1400b8890-0x1400b8cf0 .text$di
// MS2-RANGE: 0x14041d470-0x14041e930 .text$mn
// MS2-PINS-BEGIN tplpin
// The first and the last registration call a factory that lives in a neighbouring unit, so they carry no rel32 the
// call-graph propagation could use: pinned by hand from the exe (0x14041d460 / 0x14041e930 at 1400b88b5 / 1400b8cc5).
// MS2-PIN: ??__Es_regShutdown@@YAXXZ 0x1400b8890 ; manual: calls the out-of-unit factory 0x14041d460
// MS2-PIN: ??__Es_regDesignersMarket@@YAXXZ 0x1400b88e0 ; prop
// MS2-PIN: ??__Es_regDungeonMatch@@YAXXZ 0x1400b8930 ; prop
// MS2-PIN: ??__Es_regEnchantScroll@@YAXXZ 0x1400b8980 ; prop
// MS2-PIN: ??__Es_regItemSocketTarget@@YAXXZ 0x1400b89d0 ; prop
// MS2-PIN: ??__Es_regItemSocketTargetGemStone@@YAXXZ 0x1400b8a20 ; prop
// MS2-PIN: ??__Es_regMastery@@YAXXZ 0x1400b8a70 ; prop
// MS2-PIN: ??__Es_regMasteryReward@@YAXXZ 0x1400b8ac0 ; prop
// MS2-PIN: ??__Es_regMusicScoreMarket@@YAXXZ 0x1400b8b10 ; prop
// MS2-PIN: ??__Es_regNoParam@@YAXXZ 0x1400b8b60 ; prop
// MS2-PIN: ??__Es_regNpcTalk@@YAXXZ 0x1400b8bb0 ; prop
// MS2-PIN: ??__Es_regShop@@YAXXZ 0x1400b8c00 ; prop
// MS2-PIN: ??__Es_regUGCDownload@@YAXXZ 0x1400b8c50 ; prop
// MS2-PIN: ??__Es_regStringBoard@@YAXXZ 0x1400b8ca0 ; manual: calls the out-of-unit factory 0x14041e930
// MS2-PIN: ??_GGameEventShutdown@@UEAAPEAXI@Z 0x14041e5f0 ; prop
// MS2-PIN: ??_GGameEventShutdownNoParam@@UEAAPEAXI@Z 0x14041e830 ; prop
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\gameeventshutdown.cpp"

#include "ms2/placeholder/ms2stdafx.h"
#include "gameeventshutdown.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// Out-of-unit helpers.
// The factory registrar: its ctor (0x140316aa0, commonfiles\dungeonmissiondata.cpp) registers the factory under the
// name; the by-value CString is destroyed by the callee.
struct Unk_GEFactoryRegistry {
    Unk_GEFactoryRegistry(CStringW name, GameEvent* (*create)());
    char m_pad;
};

// The two registrations of this file whose factory lives in a neighbouring unit.
GameEvent* FUN_14041d460();   // ?\gameeventreturnuser.cpp: the base class takes an id, so it has no factory of its own
GameEvent* FUN_14041e930();   // ?\gameeventstringboard.cpp

// The factories of this unit (they are defined further down, in exe order).
GameEvent* FUN_14041d6a0();
GameEvent* FUN_14041d810();
GameEvent* FUN_14041d900();
GameEvent* FUN_14041dab0();
GameEvent* FUN_14041dba0();
GameEvent* FUN_14041dc90();
GameEvent* FUN_14041dd80();
GameEvent* FUN_14041de70();
GameEvent* FUN_14041df60();
GameEvent* FUN_14041e050();
GameEvent* FUN_14041e140();
GameEvent* FUN_14041e230();

// The per-kind shut-down value (gameeventvalue.cpp): OnStart takes a reference on an id, vfunc_6 releases it again.
class Unk_ShutdownEventValue;
class CGameEventValueManager;
CGameEventValueManager* FUN_140302b00();                                   // TSingleton<CGameEventValueManager>::GetInstance
Unk_ShutdownEventValue* FUN_14046d0d0(CGameEventValueManager* pManager, int nValueId);
void FUN_1407d10e0(Unk_ShutdownEventValue* pValue, int nId);
void FUN_1407d1160(Unk_ShutdownEventValue* pValue, int nId);

// The comma splitter (commonstringtable.cpp) and the token reader.
void FUN_140274fc0(const CStringW& text, ATL::CAtlArray<unsigned>& ids, const wchar_t* delims);
void FUN_14025a680(CStringW& src, ATL::CAtlArray<CStringW>& out, const wchar_t* pszSep);
int FUN_140218e60(const CStringW& str);

// ---- dynamic initializers ----
// The 14 registrations, in .text$di order (0x1400b8890..0x1400b8ca0); the two NULL factories are the classes whose
// ctor takes the object kind (0x14041d460 is in gameeventreturnuser.cpp).
#ifndef MS2_HOOK_DLL
static Unk_GEFactoryRegistry s_regShutdown(L"GameEventShutdown", FUN_14041d460);                                       // 0x143aaeec5
static Unk_GEFactoryRegistry s_regDesignersMarket(L"GameEventShutdownDesignersMarket", FUN_14041dab0);                 // 0x143aaeec9
static Unk_GEFactoryRegistry s_regDungeonMatch(L"GameEventShutdownDungeonMatch", FUN_14041d900);                       // 0x143aaeec8
static Unk_GEFactoryRegistry s_regEnchantScroll(L"GameEventShutdownEnchantScroll", FUN_14041df60);                     // 0x143aaeece
static Unk_GEFactoryRegistry s_regItemSocketTarget(L"GameEventShutdownItemSocketTarget", FUN_14041e050);               // 0x143aaeecf
static Unk_GEFactoryRegistry s_regItemSocketTargetGemStone(L"GameEventShutdownItemSocketTargetGemStone", FUN_14041e140); // 0x143aaeed0
static Unk_GEFactoryRegistry s_regMastery(L"GameEventShutdownMastery", FUN_14041dd80);                                 // 0x143aaeecc
static Unk_GEFactoryRegistry s_regMasteryReward(L"GameEventShutdownMasteryReward", FUN_14041de70);                     // 0x143aaeecd
static Unk_GEFactoryRegistry s_regMusicScoreMarket(L"GameEventShutdownMusicScoreMarket", FUN_14041dba0);               // 0x143aaeeca
static Unk_GEFactoryRegistry s_regNoParam(L"GameEventShutdownNoParam", FUN_14041d6a0);                                 // 0x143aaeec6
static Unk_GEFactoryRegistry s_regNpcTalk(L"GameEventShutdownNpcTalk", FUN_14041dc90);                                 // 0x143aaeecb
static Unk_GEFactoryRegistry s_regShop(L"GameEventShutdownShop", FUN_14041d810);                                       // 0x143aaeec7
static Unk_GEFactoryRegistry s_regUGCDownload(L"GameEventShutdownUGCDownload", FUN_14041e230);                         // 0x143aaeed1
static Unk_GEFactoryRegistry s_regStringBoard(L"GameEventStringBoard", FUN_14041e930);                                 // 0x143aaeed2
#endif

// ---- GameEventShutdown ----------------------------------------------------------------------------------------------

// @0x14041d470
CStringW GameEventShutdown::vfunc_1() { return CStringW(L"GameEventShutdown"); }

// @0x14041d4c0
GameEventShutdown::GameEventShutdown(int nId) : m_nId(nId)
{
    FUN_1402e3480(1);
}

// @0x14041d540
void GameEventShutdown::vfunc_2() { FUN_140274fc0(m_68, m_items, L","); }

// @0x14041d580
void GameEventShutdown::OnStart()
{
    for (size_t i = 0; i < m_items.GetCount(); i++)
        FUN_1407d10e0(FUN_14046d0d0(FUN_140302b00(), m_nId), m_items[i]);
}

// @0x14041d610
void GameEventShutdown::vfunc_6()
{
    for (size_t i = 0; i < m_items.GetCount(); i++)
        FUN_1407d1160(FUN_14046d0d0(FUN_140302b00(), m_nId), m_items[i]);
}

// @0x14041e430
GameEventShutdown::~GameEventShutdown() {}

// ---- GameEventShutdownNoParam ---------------------------------------------------------------------------------------

// @0x14041d6a0
GameEvent* FUN_14041d6a0() { return 0; }

// @0x14041d6b0
CStringW GameEventShutdownNoParam::vfunc_1() { return CStringW(L"GameEventShutdownNoParam"); }

// @0x14041d700
GameEventShutdownNoParam::GameEventShutdownNoParam(int nId) : m_nId(nId)
{
    FUN_1402e3480(1);
}

// @0x14041d780
void GameEventShutdownNoParam::vfunc_2() {}

// @0x14041d790
void GameEventShutdownNoParam::OnStart()
{
    FUN_1407d10e0(FUN_14046d0d0(FUN_140302b00(), m_nId), m_id);
}

// @0x14041d7d0
void GameEventShutdownNoParam::vfunc_6()
{
    FUN_1407d1160(FUN_14046d0d0(FUN_140302b00(), m_nId), m_id);
}

// @0x14041e560
GameEventShutdownNoParam::~GameEventShutdownNoParam() {}

// ---- GameEventShutdownShop ------------------------------------------------------------------------------------------

// @0x14041d810
GameEvent* FUN_14041d810() { return new GameEventShutdownShop; }

// @0x14041d870
CStringW GameEventShutdownShop::vfunc_1() { return CStringW(L"GameEventShutdownShop"); }

// @0x14041d8c0
GameEventShutdownShop::GameEventShutdownShop() : GameEventShutdown(1) {}

// ---- GameEventShutdownDungeonMatch ----------------------------------------------------------------------------------

// @0x14041d900
GameEvent* FUN_14041d900() { return new GameEventShutdownDungeonMatch; }

// @0x14041d960
CStringW GameEventShutdownDungeonMatch::vfunc_1() { return CStringW(L"GameEventShutdownDungeonMatch"); }

// @0x14041d9b0
GameEventShutdownDungeonMatch::GameEventShutdownDungeonMatch() : GameEventShutdown(2) {}

// @0x14041d9f0
void GameEventShutdownDungeonMatch::vfunc_2()
{
    ATL::CAtlArray<CStringW> tokens;

    FUN_14025a680(m_68, tokens, L",");
    for (size_t i = 0; i < tokens.GetCount(); i++) {
        int nId = FUN_140218e60(tokens[i]);
        if (nId != 0)
            m_items.Add((unsigned)nId);
    }
}

// ---- GameEventShutdownDesignersMarket -------------------------------------------------------------------------------

// @0x14041dab0
GameEvent* FUN_14041dab0() { return new GameEventShutdownDesignersMarket; }

// @0x14041db10
CStringW GameEventShutdownDesignersMarket::vfunc_1() { return CStringW(L"GameEventShutdownDesignersMarket"); }

// @0x14041db60
GameEventShutdownDesignersMarket::GameEventShutdownDesignersMarket() : GameEventShutdownNoParam(3) {}

// ---- GameEventShutdownMusicScoreMarket ------------------------------------------------------------------------------

// @0x14041dba0
GameEvent* FUN_14041dba0() { return new GameEventShutdownMusicScoreMarket; }

// @0x14041dc00
CStringW GameEventShutdownMusicScoreMarket::vfunc_1() { return CStringW(L"GameEventShutdownMusicScoreMarket"); }

// @0x14041dc50
GameEventShutdownMusicScoreMarket::GameEventShutdownMusicScoreMarket() : GameEventShutdownNoParam(4) {}

// ---- GameEventShutdownNpcTalk ---------------------------------------------------------------------------------------

// @0x14041dc90
GameEvent* FUN_14041dc90() { return new GameEventShutdownNpcTalk; }

// @0x14041dcf0
CStringW GameEventShutdownNpcTalk::vfunc_1() { return CStringW(L"GameEventShutdownNpcTalk"); }

// @0x14041dd40
GameEventShutdownNpcTalk::GameEventShutdownNpcTalk() : GameEventShutdown(5) {}

// ---- GameEventShutdownMastery ---------------------------------------------------------------------------------------

// @0x14041dd80
GameEvent* FUN_14041dd80() { return new GameEventShutdownMastery; }

// @0x14041dde0
CStringW GameEventShutdownMastery::vfunc_1() { return CStringW(L"GameEventShutdownMastery"); }

// @0x14041de30
GameEventShutdownMastery::GameEventShutdownMastery() : GameEventShutdown(6) {}

// ---- GameEventShutdownMasteryReward ---------------------------------------------------------------------------------

// @0x14041de70
GameEvent* FUN_14041de70() { return new GameEventShutdownMasteryReward; }

// @0x14041ded0
CStringW GameEventShutdownMasteryReward::vfunc_1() { return CStringW(L"GameEventShutdownMasteryReward"); }

// @0x14041df20
GameEventShutdownMasteryReward::GameEventShutdownMasteryReward() : GameEventShutdown(7) {}

// ---- GameEventShutdownEnchantScroll ---------------------------------------------------------------------------------

// @0x14041df60
GameEvent* FUN_14041df60() { return new GameEventShutdownEnchantScroll; }

// @0x14041dfc0
CStringW GameEventShutdownEnchantScroll::vfunc_1() { return CStringW(L"GameEventShutdownEnchantScroll"); }

// @0x14041e010
GameEventShutdownEnchantScroll::GameEventShutdownEnchantScroll() : GameEventShutdown(8) {}

// ---- GameEventShutdownItemSocketTarget ------------------------------------------------------------------------------

// @0x14041e050
GameEvent* FUN_14041e050() { return new GameEventShutdownItemSocketTarget; }

// @0x14041e0b0
CStringW GameEventShutdownItemSocketTarget::vfunc_1() { return CStringW(L"GameEventShutdownItemSocketTarget"); }

// @0x14041e100
GameEventShutdownItemSocketTarget::GameEventShutdownItemSocketTarget() : GameEventShutdown(9) {}

// ---- GameEventShutdownItemSocketTargetGemStone ----------------------------------------------------------------------

// @0x14041e140
GameEvent* FUN_14041e140() { return new GameEventShutdownItemSocketTargetGemStone; }

// @0x14041e1a0
CStringW GameEventShutdownItemSocketTargetGemStone::vfunc_1()
{
    return CStringW(L"GameEventShutdownItemSocketTargetGemStone");
}

// @0x14041e1f0
GameEventShutdownItemSocketTargetGemStone::GameEventShutdownItemSocketTargetGemStone() : GameEventShutdown(10) {}

// ---- GameEventShutdownUGCDownload -----------------------------------------------------------------------------------

// @0x14041e230
GameEvent* FUN_14041e230() { return new GameEventShutdownUGCDownload; }

// @0x14041e290
CStringW GameEventShutdownUGCDownload::vfunc_1() { return CStringW(L"GameEventShutdownUGCDownload"); }

// @0x14041e2e0
GameEventShutdownUGCDownload::GameEventShutdownUGCDownload() : GameEventShutdown(0xb)
{
    FUN_1402e3480(3);
}

// @0x14041e340
void GameEventShutdownUGCDownload::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    out->WriteStringW(m_68);
}

// @0x14041e390
void GameEventShutdownUGCDownload::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    // clang-cl devirtualizes the embedded-reader call into a direct call to an undefined function; go through an opaque
    // pointer there (the byte-matched cl build keeps the member call).
#ifdef __clang__
    CStringW strName = reinterpret_cast<Unk_GEReader*>(reinterpret_cast<char*>(in) + 8)->ReadStringW();
#else
    CStringW strName = in->reader.ReadStringW();
#endif
    m_68 = strName;
    vfunc_2();
}
