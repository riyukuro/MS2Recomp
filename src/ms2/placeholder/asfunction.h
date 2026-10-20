// asfunction.h - PLACEHOLDER for ASFunction (RTTI .?AVASFunction@@, an AScript wrapping an AS function object that
// calls back into C++; 0x48 bytes) and its GFx function handler ASFunctionHandlerCtx (0x18 bytes). NOT an original
// header; the code is the ?\asfunction.cpp unit (src/ms2/gfxui/asfunction.cpp, 0x1422c8390-0x1422c88e0). Several
// older units carry unit-local copies with other user-value types (void*, int, CItem*); they must not include this
// header. Declarations only.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/delegate.h"

// The FunctionHandler an ASFunction registers with the movie: Call() forwards the AS call to the delegate.
class ASFunctionHandlerCtx : public Scaleform::GFx::FunctionHandler
{
public:
    ASFunctionHandlerCtx(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)> cb);   // 0x1422c8390 (cb by value)
    // implicit virtual dtor 0x1422c8660 (no vftable store; scalar deleting 0x1422c8760)
    virtual void Call(const Params& params);                        // 1 0x1422c8400

private:
    MS2_LAYOUT_FRIEND;
    Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)> m_cb;    // +0x10
};
MS2_CHECK_SIZE(ASFunctionHandlerCtx, 0x18);

class ASFunction : public AScript
{
public:
    // nUser: the pointer-sized user data handed back with the call (Params::pUserData)
    ASFunction(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb, __int64 nUser, int nMovieId);   // 0x1422c8430
    virtual ~ASFunction();                                          // 0 0x1422c85b0 (scalar deleting 0x1422c8720)

private:
    MS2_LAYOUT_FRIEND;
    Scaleform::Ptr<Scaleform::GFx::FunctionHandler> m_spHandler;    // +0x40
};
MS2_CHECK_SIZE(ASFunction, 0x48);
