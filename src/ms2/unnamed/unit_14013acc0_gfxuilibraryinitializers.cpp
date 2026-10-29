// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Dynamic initializers of the next GFx UI-library translation
// units in the final .text$di run (split out of unit_140120880 by w520). Their code lives in the unqueued GFx UI library
// (0x1422b0000-0x142304000, no __FILE__ there), so the CU names are unknown; the initializers are kept together here in
// exe (definition) order:
//   GFxMovieEventHandler::ms_RTTI; (0x14013acf0-0x14013ad80: UISwfEntity's three, owned by gfxui/uiswfentity.cpp); the
//   setTextAutoSize mode names (FUN_1422e51c0 maps 0..4 to them); the widget-layout XML loader delegate (set by
//   FUN_1422e6e20) and GFxService::ms_ClassInfo with its efd::Category; the four XML loader delegates FUN_1422eb940
//   reads, and the name FUN_1422ebc80 compares against; the ms_RTTI of the five GFxMovieEventHandler movies;
//   UniqueSwfIDCreator::ms_ClassInfo; two empty strings; NiGFxOverlayClick::ms_RTTI. The atexit thunks of the destructible
//   statics follow in .text$yd.
// 0x14013b180 (CryptoPP::AAD_CHANNEL = "AAD", cryptlib.cpp, /O2: tail-jumps to atexit) and its atexit thunk 0x142cc8bb0
// belong to the CryptoPP library block that follows (lib_di_tail_140120880), not to this unit.
// All static names below are invented except the ms_ClassInfo / ms_RTTI members and DAT_143b0d350 (unit_140cff310 binds
// that name).
// MS2-UNIT: unit_14013acc0
// MS2-RANGE: 0x14013acc0-0x14013acf0 .text$di
// MS2-RANGE: 0x14013ad80-0x14013b180 .text$di
// MS2-RANGE: 0x142cc89f0-0x142cc8bb0 .text$yd
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include <efd/Category.h>
#include <NiRenderClick.h>
#include "ms2/placeholder/gfxservice.h"
#include "ms2/placeholder/gfxmovie.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/gfxui/nigfxlocalizemanager.h"
class TiXmlDocument;

// The movies GFxUIService creates (vftables in the GFx UI library); only their RTTI is recovered here.
class GFxMovieMain : public GFxMovieEventHandler
{
public:
    static const NiRTTI ms_RTTI;            // 0x143b0d7c0
};
class GFxMovieTooltip : public GFxMovieEventHandler
{
public:
    static const NiRTTI ms_RTTI;            // 0x143b0d7d0
};
class GFxMovieMouseCursor : public GFxMovieEventHandler
{
public:
    static const NiRTTI ms_RTTI;            // 0x143b0d7e0
};
class GFxMovieHeadUpDisplay : public GFxMovieEventHandler
{
public:
    static const NiRTTI ms_RTTI;            // 0x143b0d7f0
};
class GFxMoviePostDisplay : public GFxMovieEventHandler
{
public:
    static const NiRTTI ms_RTTI;            // 0x143b0d800
};

// efd class "UniqueSwfIDCreator" (class id 0x6202715, SetupClassInfo 0x1422f70b0, no parent class info).
class UniqueSwfIDCreator
{
public:
    static const efd::ClassInfo ms_ClassInfo;                                   // 0x143b0d820
    static void SetupClassInfo(efd::ClassInfo* pClassInfo, size_t offsetFromClass);
};

// The Scaleform overlay render click (NiRenderClick subclass).
class NiGFxOverlayClick : public NiRenderClick
{
public:
    static const NiRTTI ms_RTTI;            // 0x143b0dc38
};

// @0x14013acc0
const NiRTTI GFxMovieEventHandler::ms_RTTI("GFxMovieEventHandler", &GFxMovie::ms_RTTI);

// setTextAutoSize modes (FUN_1422e51c0: 0 none, 1 top, 2 center, 3 bottom, else ""); "shrink" is passed directly.
// @0x14013ad80
CString DAT_143b0d350("shrink");
#ifndef MS2_HOOK_DLL   // s_strAutoSizeBottom: the exe's object at 0x143b0d348, which other units reach as DAT_143b0d348 (the hook DLL binds it)
// @0x14013adb0
CString DAT_143b0d348("bottom");
#else
extern CString DAT_143b0d348;
#endif
#ifndef MS2_HOOK_DLL   // s_strAutoSizeCenter: the exe's object at 0x143b0d340, which other units reach as DAT_143b0d340 (the hook DLL binds it)
// @0x14013ade0
CString DAT_143b0d340("center");
#else
extern CString DAT_143b0d340;
#endif
#ifndef MS2_HOOK_DLL   // s_strAutoSizeNone: the exe's object at 0x143b0d330, which other units reach as DAT_143b0d330 (the hook DLL binds it)
// @0x14013ae10
CString DAT_143b0d330("none");
#else
extern CString DAT_143b0d330;
#endif
#ifndef MS2_HOOK_DLL   // s_strAutoSizeTop: the exe's object at 0x143b0d338, which other units reach as DAT_143b0d338 (the hook DLL binds it)
// @0x14013ae40
CString DAT_143b0d338("top");
#else
extern CString DAT_143b0d338;
#endif

// Loads the widget-layout document ("widget" offsetX/offsetY ...); set by FUN_1422e6e20.
// @0x14013ae70
static Delegate<bool(TiXmlDocument&)> s_widgetXmlLoader;

// @0x14013aea0
EE_IMPLEMENT_CONCRETE_CLASS_INFO(GFxService);

#ifndef MS2_HOOK_DLL   // s_cat_7f00004: the exe's object at 0x143b0d778, which other units reach as DAT_143b0d778 (the hook DLL binds it)
// @0x14013aec0
extern const efd::Category DAT_143b0d778(efd::UniversalID::ECU_Any, 0xfff, 0x07f00004);
#else
extern const efd::Category DAT_143b0d778;
#endif

// NiGFxLocalizeManager's four XML documents (FUN_1422eb940 loads them in the order 7a0, 7a8, 7b0, 7b8) and its locale,
// which FUN_1422ebc80 compares a node's name against (CompareNoCase). The hook DLL binds the exe's objects (symbols
// rows) instead of DLL-local copies.
#ifndef MS2_HOOK_DLL
// @0x14013aef0
Delegate<bool(TiXmlDocument&)> NiGFxLocalizeManager::ms_kXmlLoader4;
// @0x14013af20
Delegate<bool(TiXmlDocument&)> NiGFxLocalizeManager::ms_kXmlLoader1;
// @0x14013af50
Delegate<bool(TiXmlDocument&)> NiGFxLocalizeManager::ms_kXmlLoader3;
// @0x14013af80
Delegate<bool(TiXmlDocument&)> NiGFxLocalizeManager::ms_kXmlLoader2;
// @0x14013afb0
CString NiGFxLocalizeManager::ms_strLocale;
#endif

// @0x14013afe0
const NiRTTI GFxMovieMain::ms_RTTI("GFxMovieMain", &GFxMovieEventHandler::ms_RTTI);
// @0x14013b010
const NiRTTI GFxMovieTooltip::ms_RTTI("GFxMovieTooltip", &GFxMovieEventHandler::ms_RTTI);
// @0x14013b040
const NiRTTI GFxMovieMouseCursor::ms_RTTI("GFxMovieMouseCursor", &GFxMovieEventHandler::ms_RTTI);
// @0x14013b070
const NiRTTI GFxMovieHeadUpDisplay::ms_RTTI("GFxMovieHeadUpDisplay", &GFxMovieEventHandler::ms_RTTI);
// @0x14013b0a0
const NiRTTI GFxMoviePostDisplay::ms_RTTI("GFxMoviePostDisplay", &GFxMovieEventHandler::ms_RTTI);

// @0x14013b0d0
EE_IMPLEMENT_CONCRETE_CLASS_INFO(UniqueSwfIDCreator);

#ifndef MS2_HOOK_DLL   // s_strEmpty1: the exe's object at 0x143b0dc30, which other units reach as DAT_143b0dc30 (the hook DLL binds it)
// @0x14013b0f0
CString DAT_143b0dc30("");
#else
extern CString DAT_143b0dc30;
#endif
#ifndef MS2_HOOK_DLL   // s_strEmpty2: the exe's object at 0x143b0dc28, which other units reach as DAT_143b0dc28 (the hook DLL binds it)
// @0x14013b120
CString DAT_143b0dc28("");
#else
extern CString DAT_143b0dc28;
#endif

// @0x14013b150
const NiRTTI NiGFxOverlayClick::ms_RTTI("NiGFxOverlayClick", &NiRenderClick::ms_RTTI);
