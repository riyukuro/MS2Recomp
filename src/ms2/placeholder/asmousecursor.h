// asmousecursor.h - PLACEHOLDER for ASMouseCursor (RTTI .?AVASMouseCursor@@, vftable 0x14310d408, the ASGameEntity slots):
// the ActionScript mouse cursor clip of the GFx UI library (GFxMovie::m_30, gfxmovie.h). NOT an original header; the
// code is in src/ms2/gfxui/asmousecursor.cpp (?\asmousecursor.cpp, 0x1422ceb80-0x1422cf290). 0x90 bytes: the ctor
// 0x1422ceb80 clears two ints after the 0x88-byte ASGameEntity.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/placeholder/asgameentity.h"

// The AS cursor type passed to "changeType" (its own Invoke instance 0x1422cef80, so a distinct enum).
enum Unk_MouseCursorType : int
{
};

class ASMouseCursor : public ASGameEntity
{
public:
    ASMouseCursor(const Scaleform::GFx::Value& v, int nMovieId);   // 0x1422ceb80
    virtual ~ASMouseCursor();                                       // 0 0x1422cebf0 (scalar deleting 0x1422cf020)
    void FUN_1422cec40(int bShow);                                  // hide the system cursor / restore the cursor mode
    void FUN_1422cecb0(int nMode);                                  // cursor mode: 2 = system cursor, 1 = the AS clip
    void FUN_1422cedb0();                                           // lock()
    void FUN_1422cee00();                                           // unlock()
    void FUN_1422cee50(Unk_MouseCursorType eType);                  // changeType(type)
    void FUN_1422ceea0(const CStringW& strText);                    // setText(text)
    int FUN_1422cef10();                                            // getCursorType()

private:
    MS2_LAYOUT_FRIEND;
    int m_bDisabled;                                                // +0x88 set: the AS clip is not used (no AS calls)
    int m_nMode;                                                    // +0x8c the cursor mode (0 = none, 1 = AS clip, 2 = system)
};
MS2_CHECK_SIZE(ASMouseCursor, 0x90);
