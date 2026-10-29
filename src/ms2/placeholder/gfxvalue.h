// gfxvalue.h - Scaleform::GFx::Value / FunctionHandler::Params and the rest of the GFx player API the game units use.
// They come from our recovered Scaleform tree (src/ms2/scaleform/include), so game units build without the SDK.
// Evidence: the result of AScript's Invoke helpers is destroyed by 0x140614800, which is Value::~Value() (IsManagedValue
// 0x140614b60 -> ReleaseManagedValue 0x140614ba0, then Type = 0 at +0x08); AScript (0x40 bytes) = CPtred (0x18) + 8 +
// Value (0x20) at +0x20; GFx::FunctionHandler appears in RTTI.
#pragma once

#include "ms2/ms2layout.h"

// The game's /Od units keep out-of-line COMDAT copies of these inlines (Value's copy ctor 0x1406146a0, ~Value
// 0x140614800, IsManagedValue, ...), so our inline bodies keep the call structure the exe has.
#include "ms2/scaleform/include/gfx/gfx_player.h"
#include "ms2/scaleform/include/gfx/gfx_loaderimpl.h"
#include "ms2/scaleform/include/gfx/gfx_asimemanager.h"
#include "ms2/scaleform/include/gfx/gfx_event.h"
#include "ms2/scaleform/include/gfx/gfx_valueinfo.h"
#include "ms2/placeholder/sfrendermatrix.h"

MS2_CHECK_SIZE(Scaleform::GFx::Value, 0x20);
MS2_CHECK_SIZE(Scaleform::GFx::FunctionHandler::Params, 0x38);
