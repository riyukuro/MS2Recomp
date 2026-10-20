// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). ASFunction, an AS function object of the GFx UI library
// whose calls go to a C++ delegate (through its FunctionHandler ASFunctionHandlerCtx).
// MS2-UNIT: ?\asfunction.cpp
// MS2-RANGE: 0x1422c8390-0x1422c88e0 .text$mn
//
// The unit name and directory are assumed (the GFx UI library 0x1422b0000-0x142304000 has no __FILE__ strings). Both
// classes are declared in src/ms2/placeholder/asfunction.h. The obj's COMDAT tail is the Scaleform Ptr<FunctionHandler>
// instance (0x1422c85f0-0x1422c8710), the deleting dtors and the CRT memmove_s copy 0x1422c87c0.
#define MS2_THIS_FILE "asfunction.cpp"
#include "ms2/placeholder/ms2stdafx.h"

#include "ms2/placeholder/asfunction.h"

#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

Scaleform::GFx::Movie* FUN_1422bb8b0(int nMovieId);            // the GFx movie of a movie id (null if not loaded)

// @0x1422c8390
ASFunctionHandlerCtx::ASFunctionHandlerCtx(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)> cb)
    : m_cb(cb)
{
}

// @0x1422c8400
void ASFunctionHandlerCtx::Call(const Params& params)
{
    m_cb(params);
}

// @0x1422c8430
ASFunction::ASFunction(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb, __int64 nUser, int nMovieId)
    : AScript(nMovieId)
{
    m_value.SetNull();
    Scaleform::GFx::Movie* pMovie = FUN_1422bb8b0(m_nMovieId);
    if (pMovie) {
        Scaleform::Ptr<Scaleform::GFx::FunctionHandler> spHandler = *new ASFunctionHandlerCtx(cb);
        m_spHandler = spHandler;
        pMovie->CreateFunction(&m_value, m_spHandler, (void*)nUser);
    }
}

// @0x1422c85b0
ASFunction::~ASFunction()
{
}

// @0x1422c87c0
MS2_EMIT_CRT_MEMMOVE_S();

// MS2-PIN: ??1ASFunctionHandlerCtx@@UEAA@XZ 0x1422c8660
// MS2-PIN: ??_GASFunctionHandlerCtx@@UEAAPEAXI@Z 0x1422c8760
// MS2-PIN: ??_GASFunction@@UEAAPEAXI@Z 0x1422c8720
// MS2-PIN: ??0?$Ptr@VFunctionHandler@GFx@Scaleform@@@Scaleform@@QEAA@AEAVFunctionHandler@GFx@1@@Z 0x1422c85f0
// MS2-PIN: ??0?$Ptr@VFunctionHandler@GFx@Scaleform@@@Scaleform@@QEAA@XZ 0x1422c8610
// MS2-PIN: ??1?$Ptr@VFunctionHandler@GFx@Scaleform@@@Scaleform@@QEAA@XZ 0x1422c8630
// MS2-PIN: ??4?$Ptr@VFunctionHandler@GFx@Scaleform@@@Scaleform@@QEAAAEBV01@AEBV01@@Z 0x1422c8690
// MS2-PIN: ??B?$Ptr@VFunctionHandler@GFx@Scaleform@@@Scaleform@@QEBAPEAVFunctionHandler@GFx@1@XZ 0x1422c8700
// MS2-PIN: ??C?$Ptr@VFunctionHandler@GFx@Scaleform@@@Scaleform@@QEBAPEAVFunctionHandler@GFx@1@XZ 0x1422c8710
