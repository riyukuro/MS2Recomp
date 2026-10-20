// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). GfxException / GfxExceptionSwfLoad, the exceptions the GFx
// UI library throws by pointer (`throw new GfxExceptionSwfLoad(...)`, caught as GfxException* by UISwfEntity::vfunc_42).
// MS2-UNIT: ?\gfxexception.cpp
// MS2-RANGE: 0x1422e15e0-0x1422e1720 .text$mn
//
// The unit name and directory are assumed (the GFx UI library has no __FILE__ strings). The range starts at the
// GfxException ctor 0x1422e15e0, the first function after ASTextInput's ??_G 0x1422e15a0 (the queue's split put it at
// 0x1422e1620). Both destructors are implicit (no vptr store: they only call the base dtor) and come out as COMDATs
// in name order after the two constructors.
#include "ms2/placeholder/ms2stdafx.h"

#include "ms2/placeholder/gfxexception.h"

// @0x1422e15e0
GfxException::GfxException(const char* const& szMessage)
    : std::exception(szMessage)
{
}

// @0x1422e1620
GfxExceptionSwfLoad::GfxExceptionSwfLoad(const char* const& szMessage)
    : GfxException(szMessage)
{
}

// MS2-PIN: ??1GfxExceptionSwfLoad@@UEAA@XZ 0x1422e1680
