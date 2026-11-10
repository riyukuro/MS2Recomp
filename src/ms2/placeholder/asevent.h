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

    CString GetType();                                        // type
    Scaleform::GFx::Value GetTarget();                          // target
    Scaleform::GFx::Value GetCurrentTarget();                          // currentTarget
    bool IsCancelable();                                           // cancelable
    bool IsBubbles();                                           // bubbles
    bool IsDefaultPrevented();                                           // isDefaultPrevented()
    void PreventDefault();                                           // preventDefault()
    void StopImmediatePropagation();                                           // stopImmediatePropagation()
    void StopPropagation();                                           // stopPropagation()
    CString ToString();                                        // toString()
};
MS2_CHECK_SIZE(ASEvent, 0x40);

// Implicit dtor 0x1422e2bb0.
class ASTextEvent : public ASEvent
{
public:
    ASTextEvent(const Scaleform::GFx::FunctionHandler::Params& params); // 0x1422e2670
    CString GetText();                                        // text
};
MS2_CHECK_SIZE(ASTextEvent, 0x40);

// Implicit dtor 0x140f83bb0 (first emitted elsewhere).
class ASListEvent : public ASEvent
{
public:
    ASListEvent(const Scaleform::GFx::FunctionHandler::Params& params); // 0x1422e2740
    Scaleform::GFx::Value GetItemData();                          // itemData
    Scaleform::GFx::Value GetItemRenderer();                          // itemRenderer
    int GetIndex();                                            // index
    int GetColumnIndex();                                            // columnIndex
    int GetRowIndex();                                            // rowIndex
    unsigned int GetControllerIdx();                                   // controllerIdx
    unsigned int GetButtonIdx();                                   // buttonIdx
    bool IsKeyboard();                                           // isKeyboard
};
MS2_CHECK_SIZE(ASListEvent, 0x40);

// Implicit dtor 0x140be35b0 (first emitted elsewhere).
class ASIndexEvent : public ASEvent
{
public:
    ASIndexEvent(const Scaleform::GFx::FunctionHandler::Params& params); // 0x1422e2a60
    int GetIndex();                                            // index
    int GetLastIndex();                                            // lastIndex
    Scaleform::GFx::Value GetData();                          // data
};
MS2_CHECK_SIZE(ASIndexEvent, 0x40);
