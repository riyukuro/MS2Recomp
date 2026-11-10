// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: client\ms2\uieventintroduce.h (name assumed: the
// .cpp's __FILE__ string is not in the exe for this unit).
//
// UIEventIntroduce ("EventIntroduce", UI type 0x4f06, RTTI .?AVUIEventIntroduce@@, 0x70 bytes): the HUD the event
// minigame shows while it introduces the round (the banner the micro-games' driver updates). It is a plain
// UIHeadUpDisplay with no fields of its own (the ctor only writes the inherited m_2c = 0x1e), and its non-virtual
// members forward the round's result to the movie's root object ("onWin", "onLose", ...). Names: virtuals are
// Ghidra's vfunc_<slot>; FUN_<va> are non-virtual members.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/uiheadupdisplay.h"

class UIEventIntroduce : public UIHeadUpDisplay
{
public:
    UIEventIntroduce();                                             // 0x140f40ce0 (m_2c = 0x1e)
    virtual ~UIEventIntroduce();                                    //  0 0x140f40d30 (??_G 0x140f41200)
    virtual CString GetTypeName();                                      //  1 0x140f40d70 "EventIntroduce"
    virtual void vfunc_2();                                         //  2 0x140f40dc0 show: load the movie (depth m_2c)
    virtual void vfunc_3();                                         //  3 0x140f40e00 hide: unload it
    virtual void OnLoadInit();                                      // 20 0x140f40e30 the base's
    virtual void vfunc_43();                                        // 43 0x140f40e50 validate the movie's root entity
    virtual int vfunc_48() { return 0x4f06; }                       // 48 0x140f41240 UI type id

    void OnWin(int n);                                      // 0x140f40ef0 the movie's "onWin" with the score
    void OnLose(int n);                                      // 0x140f40f60 "onLose"
    void OnDraw(int n);                                      // 0x140f40fd0 "onDraw"
    void OnPerfect(int n);                                      // 0x140f41040 "onPerfect"
    void OnFight(int n);                                      // 0x140f410b0 "onFight"
    void OnFinalRound(int n);                                      // 0x140f41120 "onFinalRound"
    void OnRound(int a1, int a2);                             // 0x140f41190 "onRound" (the round number and its goal)
};
MS2_CHECK_SIZE(UIEventIntroduce, 0x70);
