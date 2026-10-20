// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Dynamic initializers of the first GFx UI-library translation
// units in the final .text$di run (split out of unit_140120880 by w520). Their code lives in the unqueued GFx UI library
// (0x1422b0000-0x142304000, no __FILE__ there), so the CU names are unknown; the initializers are kept together here in
// exe (definition) order:
//   GFxSceneService::ms_ClassInfo (gfx scene service TU), the undefined GFx::Value the AS wrappers start from and the
//   "setData" method name, GFxMovie::ms_RTTI, the NotifyContext binding registry (a CRBMap of name -> BindData and two
//   name sets, used by 0x1422c8de0..0x1422c90d0), and the efd ClassInfo of NotifyContext::BindData, DragSlot and
//   DragSlotBag. The atexit thunks of the five destructible statics follow in .text$yd.
// All static names below are invented except the ms_ClassInfo / ms_RTTI members.
// MS2-UNIT: unit_140135ac0
// MS2-RANGE: 0x140135ac0-0x140135c50 .text$di
// MS2-RANGE: 0x142cc73c0-0x142cc7460 .text$yd
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include <set>
#include <atlcoll.h>
#include <NiSmartPointer.h>
#include "ms2/placeholder/gfxservice.h"
#include "ms2/placeholder/gfxmovie.h"
#include "ms2/gfxui/dragslot.h"

// @0x140135ac0
EE_IMPLEMENT_CONCRETE_CLASS_INFO(GFxSceneService);

// The undefined value ASMovieClip-style wrappers are constructed from (aseffect.cpp binds it by this name).
// @0x140135ae0
Scaleform::GFx::Value DAT_143b0ae18;

// @0x140135b10
static CString s_strSetData("setData");

// @0x140135b40
const NiRTTI GFxMovie::ms_RTTI("GFxMovie", 0);

// NotifyContext binding registry. Slot name -> bound slot; FUN_1422c8de0 logs "Unremoved binding slot : %s" for what is
// left in it at shutdown.
// @0x140135b60
static CRBMap<CString, NiPointer<NotifyContext::BindData> > s_bindings;
// Names skipped by the pending-name pass (FUN_1422c90d0 looks every binding's name up here).
// @0x140135b90
static std::set<CString> s_skipNames;
// Names whose bindings are refreshed by FUN_1422c90d0 (walked, then cleared).
// @0x140135bc0
static std::set<CString> s_pendingNames;

// @0x140135bf0
EE_IMPLEMENT_CONCRETE_CLASS_INFO(NotifyContext::BindData);
// @0x140135c10
EE_IMPLEMENT_CONCRETE_CLASS_INFO(DragSlot);
// @0x140135c30
EE_IMPLEMENT_CONCRETE_CLASS_INFO(DragSlotBag);
