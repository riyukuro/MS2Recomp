// cubemapinformationservice_statics.h - the statics of cubemapinformationservice.cpp#3 that sit between the shared header
// statics ("stun") and the condition (see ms2/placeholder/header_statics_a.h, MS2_STATICS_A_BEFORE_CONDITION): the
// service message category (0x143acfd58) and a null handle (0x143acf820, ctor 0x1401cd100).
#pragma once
#include <efd/Category.h>
#include "cubemapinformationservice_3.h"

// @0x1400e6350
static const efd::Category s_cubeMapCategory = efd::Category(efd::UniversalID::ECU_Any, efd::kNetID_Any, 0x07f00004);
#ifndef MS2_HOOK_DLL   // s_cubeMapNone: the exe's object at 0x143acf820, which other units reach as DAT_143acf820 (the hook DLL binds it)
// @0x1400e6380
Unk_1401cd100 g_cubeMapNone(NULL);
#else
extern Unk_1401cd100 g_cubeMapNone;
#endif
