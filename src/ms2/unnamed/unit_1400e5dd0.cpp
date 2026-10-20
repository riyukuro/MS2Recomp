// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Dynamic initializers of header statics of two neighbouring
// TUs (market sort-type names, skill/stun labels, null handle, condition object), then the CubeMapInformationService
// class-info registration and its two message-handler statics.
// MS2-UNIT: unit_1400e5dd0
// MS2-RANGE: 0x1400e5dd0-0x1400e6230 .text$di
// MS2-GUESS-LOOKALIKES
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/client/ms2/cubemapinformationservice_tail.h"
#include <efd/MessageService.h>
#include <egf/EntityChangeMessage.h>
#include <ecr/CoreRuntimeMessages.h>

// first TU's statics
static CString s_strSortTypeNames1[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill1 = "skill";
static CString s_strStun1 = "stun";
static Unk_1401cd100 s_pointer1(NULL);
static Unk_1402a9d70 s_condition1(17, 0.75f, 0.25f, 2.25f, 10);

// next TU
static CString s_strSkill2 = "skill";
static CString s_strStun2 = "stun";
static Unk_1401cd100 s_pointer2(NULL);
static CString s_strSortTypeNames2[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill3 = "skill";
static CString s_strStun3 = "stun";
static Unk_1402a9d70 s_condition2(17, 0.75f, 0.25f, 2.25f, 10);

#ifndef MS2_HOOK_DLL
EE_IMPLEMENT_CONCRETE_CLASS_INFO(CubeMapInformationService);

EE_HANDLER_WRAP(CubeMapInformationService, FUN_1410cef70, egf::EntityChangeMessage, 8253);
static efd::MessageHandlerImpl<CubeMapInformationService, ecr::SceneGraphAddedMessage>
    s_sceneGraphAddedHandler(reinterpret_cast<void (CubeMapInformationService::*)(const ecr::SceneGraphAddedMessage*, efd::Category)>(
        &CubeMapInformationService::FUN_1410cf130));
#endif
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cabfe0-0x142cac180 .text$yd
