// gameeventshutdown.h - the shutdown family of GameEvent: the base event carrying the object-kind id and the list of
// the ids to shut down, plus one subclass per feature (shop, dungeon match, designers market, ...). Recovered from
// MapleStory2.exe KMS2_DEV x64 (2022-04-13); the unit is `?\gameeventshutdown.cpp`
// (0x14041d470-0x14041e930 .text$mn, 0x1400b8890-0x1400b8cf0 .text$di, dir commonfiles). Header name assumed; member
// names invented from their use.
//
// GameEventShutdown and GameEventShutdownNoParam take their object kind as a ctor argument, so neither is default
// constructible: the exe registers both names with a factory that just returns NULL (0x14041d460 and 0x14041d6a0).
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/gameevent.h"   // GameEvent

// 0xf8. The object kind at +0xd0 and the comma separated id list parsed out of m_68 at +0xd8. OnStart takes a
// reference on every id of the list and vfunc_6 releases it.
class GameEventShutdown : public GameEvent
{
public:
    GameEventShutdown(int nId);                 // 0x14041d4c0
    virtual ~GameEventShutdown();               // 0x14041e430

    virtual CStringW vfunc_1();                 // 0x14041d470: "GameEventShutdown"
    virtual void vfunc_2();                     // 0x14041d540: parse m_items out of m_68
    virtual void OnStart();                     // 0x14041d580
    virtual void vfunc_6();                     // 0x14041d610

    int m_nId;                                  // +0xd0 the object kind the ids belong to
    ATL::CAtlArray<unsigned> m_items;           // +0xd8 the object ids to shut down
};
MS2_CHECK_SIZE(GameEventShutdown, 0xf8);

// 0xf8. The same storage, but vfunc_2 does nothing and OnStart / vfunc_6 act on the event id itself instead of the
// list (the shout-down applies to the event, not to objects the xml names).
class GameEventShutdownNoParam : public GameEvent
{
public:
    GameEventShutdownNoParam(int nId);          // 0x14041d700
    virtual ~GameEventShutdownNoParam();        // 0x14041e560

    virtual CStringW vfunc_1();                 // 0x14041d6b0: "GameEventShutdownNoParam"
    virtual void vfunc_2();                     // 0x14041d780 (empty)
    virtual void OnStart();                     // 0x14041d790
    virtual void vfunc_6();                     // 0x14041d7d0

    int m_nId;                                  // +0xd0 the object kind
    ATL::CAtlArray<unsigned> m_items;           // +0xd8 unused by this variant
};
MS2_CHECK_SIZE(GameEventShutdownNoParam, 0xf8);

#define MS2_DECL_SHUTDOWN_CLASS(name, base)     \
    class name : public base                    \
    {                                           \
    public:                                     \
        name();                                 \
        virtual CStringW vfunc_1();             \
    }

MS2_DECL_SHUTDOWN_CLASS(GameEventShutdownShop, GameEventShutdown);                          // 0x14041d8c0: kind 1

// 0xf8. Reads the ids of the dungeon match out of m_68 by hand (one "id:count" token per match).
class GameEventShutdownDungeonMatch : public GameEventShutdown
{
public:
    GameEventShutdownDungeonMatch();            // 0x14041d9b0: kind 2

    virtual CStringW vfunc_1();                 // 0x14041d960: "GameEventShutdownDungeonMatch"
    virtual void vfunc_2();                     // 0x14041d9f0
};

MS2_DECL_SHUTDOWN_CLASS(GameEventShutdownDesignersMarket, GameEventShutdownNoParam);        // 0x14041db60: kind 3
MS2_DECL_SHUTDOWN_CLASS(GameEventShutdownMusicScoreMarket, GameEventShutdownNoParam);       // 0x14041dc50: kind 4
MS2_DECL_SHUTDOWN_CLASS(GameEventShutdownNpcTalk, GameEventShutdown);                       // 0x14041dd40: kind 5
MS2_DECL_SHUTDOWN_CLASS(GameEventShutdownMastery, GameEventShutdown);                       // 0x14041de30: kind 6
MS2_DECL_SHUTDOWN_CLASS(GameEventShutdownMasteryReward, GameEventShutdown);                 // 0x14041df20: kind 7
MS2_DECL_SHUTDOWN_CLASS(GameEventShutdownEnchantScroll, GameEventShutdown);                 // 0x14041e010: kind 8
MS2_DECL_SHUTDOWN_CLASS(GameEventShutdownItemSocketTarget, GameEventShutdown);              // 0x14041e100: kind 9
MS2_DECL_SHUTDOWN_CLASS(GameEventShutdownItemSocketTargetGemStone, GameEventShutdown);      // 0x14041e1f0: kind 10

#undef MS2_DECL_SHUTDOWN_CLASS

// 0xf8. The UGC download shutdown: it also streams the string it is built from (the reader's slot 8) and re-parses it.
class GameEventShutdownUGCDownload : public GameEventShutdown
{
public:
    GameEventShutdownUGCDownload();             // 0x14041e2e0: kind 11

    virtual CStringW vfunc_1();                 // 0x14041e290: "GameEventShutdownUGCDownload"
    virtual void vfunc_3(Unk_GEOut* out);       // 0x14041e340
    virtual void vfunc_4(Unk_GEIn* in);         // 0x14041e390
};

MS2_CHECK_SIZE(GameEventShutdownShop, 0xf8);
MS2_CHECK_SIZE(GameEventShutdownDungeonMatch, 0xf8);
MS2_CHECK_SIZE(GameEventShutdownDesignersMarket, 0xf8);
MS2_CHECK_SIZE(GameEventShutdownMusicScoreMarket, 0xf8);
MS2_CHECK_SIZE(GameEventShutdownNpcTalk, 0xf8);
MS2_CHECK_SIZE(GameEventShutdownMastery, 0xf8);
MS2_CHECK_SIZE(GameEventShutdownMasteryReward, 0xf8);
MS2_CHECK_SIZE(GameEventShutdownEnchantScroll, 0xf8);
MS2_CHECK_SIZE(GameEventShutdownItemSocketTarget, 0xf8);
MS2_CHECK_SIZE(GameEventShutdownItemSocketTargetGemStone, 0xf8);
MS2_CHECK_SIZE(GameEventShutdownUGCDownload, 0xf8);
