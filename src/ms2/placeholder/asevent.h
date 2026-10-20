// asevent.h - PLACEHOLDER for ASEvent (RTTI .?AVASEvent@@, an AScript wrapping a new flash.events.Event; vftable
// 0x143114c90, 0x40 bytes) and its CLIK event wrappers ASTextEvent / ASListEvent / ASIndexEvent (built from the
// Params of an AS callback: the event is argument 0). NOT an original header; the code is the ?\asevent.cpp unit
// (0x1422e2080-0x1422e2cd0). Declarations only.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"

class ASEvent : public AScript
{
public:
    ASEvent(const CString& strType, bool bBubbles, bool bCancelable, int nMovieId);   // 0x1422e2080
    ASEvent(const Scaleform::GFx::Value& v, int nMovieId);          // 0x1422e21f0
    ASEvent(const Scaleform::GFx::FunctionHandler::Params& params); // 0x1422e2240 (movie id 2)
    virtual ~ASEvent();                                             // 0x1422e22a0

    CString FUN_1422e22d0();                                        // type
    Scaleform::GFx::Value FUN_1422e2360();                          // target
    Scaleform::GFx::Value FUN_1422e23b0();                          // currentTarget
    bool FUN_1422e2400();                                           // cancelable
    bool FUN_1422e2460();                                           // bubbles
    bool FUN_1422e24c0();                                           // isDefaultPrevented()
    void FUN_1422e2520();                                           // preventDefault()
    void FUN_1422e2560();                                           // stopImmediatePropagation()
    void FUN_1422e25a0();                                           // stopPropagation()
    CString FUN_1422e25e0();                                        // toString()
};
MS2_CHECK_SIZE(ASEvent, 0x40);

// Implicit dtor 0x1422e2bb0.
class ASTextEvent : public ASEvent
{
public:
    ASTextEvent(const Scaleform::GFx::FunctionHandler::Params& params); // 0x1422e2670
    CString FUN_1422e26b0();                                        // text
};
MS2_CHECK_SIZE(ASTextEvent, 0x40);

// Implicit dtor 0x140f83bb0 (first emitted elsewhere).
class ASListEvent : public ASEvent
{
public:
    ASListEvent(const Scaleform::GFx::FunctionHandler::Params& params); // 0x1422e2740
    Scaleform::GFx::Value FUN_1422e2780();                          // itemData
    Scaleform::GFx::Value FUN_1422e27d0();                          // itemRenderer
    int FUN_1422e2820();                                            // index
    int FUN_1422e2880();                                            // columnIndex
    int FUN_1422e28e0();                                            // rowIndex
    unsigned int FUN_1422e2940();                                   // controllerIdx
    unsigned int FUN_1422e29a0();                                   // buttonIdx
    bool FUN_1422e2a00();                                           // isKeyboard
};
MS2_CHECK_SIZE(ASListEvent, 0x40);

// Implicit dtor 0x140be35b0 (first emitted elsewhere).
class ASIndexEvent : public ASEvent
{
public:
    ASIndexEvent(const Scaleform::GFx::FunctionHandler::Params& params); // 0x1422e2a60
    int FUN_1422e2aa0();                                            // index
    int FUN_1422e2b00();                                            // lastIndex
    Scaleform::GFx::Value FUN_1422e2b60();                          // data
};
MS2_CHECK_SIZE(ASIndexEvent, 0x40);
