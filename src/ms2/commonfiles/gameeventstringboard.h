// gameeventstringboard.h - the string board family of GameEvent: the board event itself (GameEventStringBoard) and the
// link event that resets it (GameEventStringBoardLink). Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13); the
// unit is `?\gameeventstringboard.cpp` (0x14041e930-0x14041eeb0 .text$mn, 0x1400b8cf0-0x1400b8d40 .text$di,
// dir commonfiles). Header name assumed; member names invented from their use.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/gameevent.h"   // GameEvent

// 0xd8. The inherited string field m_68 is the board's xml; vfunc_2 turns it into the string id at +0xd0, and vfunc_3 /
// vfunc_4 stream the id and the inherited m_80 (the board's key).
class GameEventStringBoard : public GameEvent
{
public:
    GameEventStringBoard();                     // 0x14041e9e0
    // Implicit dtor only (the exe's 0x14041edf0 has no vptable store, so an empty user body does not match).
    virtual ~GameEventStringBoard() = default;  // 0x14041edf0

    virtual CStringW vfunc_1();                 // 0x14041e990: "GameEventStringBoard"
    virtual void vfunc_2();                     // 0x14041ea50: m_nId = the string id of m_68
    virtual void vfunc_3(Unk_GEOut* out);       // 0x14041eaa0
    virtual void vfunc_4(Unk_GEIn* in);         // 0x14041eb00
    virtual void OnStart();                     // 0x14041eb60 (empty)
    virtual void vfunc_6();                     // 0x14041eb70 (empty)

    int m_nId;                                  // +0xd0 the string id FUN_140718200 derives from m_68
};
MS2_CHECK_SIZE(GameEventStringBoard, 0xd8);

// 0xd0 (no extra storage). vfunc_2 does nothing and vfunc_3 / vfunc_4 stream the inherited m_68 itself; OnStart hands
// it to CGameRule (link the board) and vfunc_6 hands over the empty string (unlink it).
class GameEventStringBoardLink : public GameEvent
{
public:
    GameEventStringBoardLink();                 // 0x14041ec30
    virtual ~GameEventStringBoardLink() = default;   // 0x14041ee10 (implicit: the exe body has no vptable store)

    virtual CStringW vfunc_1();                 // 0x14041ebe0: "GameEventStringBoardLink"
    virtual void vfunc_2();                     // 0x14041ec90 (empty)
    virtual void vfunc_3(Unk_GEOut* out);       // 0x14041eca0
    virtual void vfunc_4(Unk_GEIn* in);         // 0x14041ece0
    virtual void OnStart();                     // 0x14041ed30
    virtual void vfunc_6();                     // 0x14041ed90
};
MS2_CHECK_SIZE(GameEventStringBoardLink, 0xd0);
