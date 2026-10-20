// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). NotifySwfEntity, the notify handler of the SWF entities'
// ActionScript callbacks. See notifyswfentity.h.
// MS2-UNIT: ?\notifyswfentity.cpp
// MS2-RANGE: 0x142302df0-0x142303440 .text$mn
//
// The unit name and directory are assumed (the GFx UI library has no __FILE__ strings).
#include "ms2/placeholder/ms2stdafx.h"

#include "ms2/gfxui/notifyswfentity.h"
#include "ms2/gfxui/uiswfentity.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/gfxmanager.h"
#include "ms2/placeholder/uiswfentitymanager.h"
#include "hook/ms2hook.h"

using Scaleform::GFx::Value;

// @0x142302df0
NotifySwfEntity::NotifySwfEntity(Unk_NotifyContext* pContext)
    : NotifyHandler(pContext)
{
    m_callbacks.SetAt("getUserData", &getUserDataImpl);
    m_callbacks.SetAt("playSound", &playSoundImpl);
}

// @0x142302ed0
void NotifySwfEntity::getUserData(const Params& params)
{
    CString strEntity(params.pArgs[0].GetString());
    CString strMethod(params.pArgs[1].GetString());
    ASData args;
    for (unsigned int i = 2; i < params.ArgCount; i++) {
        if (params.pArgs[i].IsBool())
            args.FUN_1422b7fd0(params.pArgs[i].GetBool());
        else if (params.pArgs[i].IsInt())
            args.FUN_1422b7f70(params.pArgs[i].GetInt());
        else if (params.pArgs[i].IsUInt())
            args.FUN_1422b8090(params.pArgs[i].GetUInt());
        else if (params.pArgs[i].IsNumber())
            args.FUN_1422b8160(params.pArgs[i].GetNumber());
        else if (params.pArgs[i].IsString())
            args.FUN_1422b82b0(params.pArgs[i].GetString());
        else if (params.pArgs[i].IsStringW())
            args.FUN_1422b8310(params.pArgs[i].GetStringW());
        else
            args.FUN_1422b83f0(params.pArgs[i]);
    }

    MS2Ptr<UISwfEntity> spEntity = FUN_140b632f0()->FUN_1422d41b0(strEntity);
    if (spEntity.get()) {
        Scaleform::GFx::Movie* pMovie = params.pMovie;
        if (pMovie) {
            pMovie->CreateObject(params.pRetVal, 0, 0, 0);
            spEntity->vfunc_45(params.pRetVal, strMethod, &args);
        }
    }
}

// @0x142303260
void NotifySwfEntity::playSound(const Params& params)
{
    if (params.ArgCount < 1)
        return;
    CString strSound(params.pArgs[0].GetString());
    CString strArg;
    if (params.ArgCount > 1)
        strArg = params.pArgs[1].GetString();
    if (!strSound.IsEmpty())
        FUN_14025e7a0()->FUN_1422b0610(strSound, strArg);
}

// @0x142303340
void NotifySwfEntity::getUserDataImpl(NotifyHandler* pHandler, const Params& params)
{
    NotifySwfEntity* pThis = static_cast<NotifySwfEntity*>(pHandler);
    if (pThis)
        pThis->getUserData(params);
}

// @0x142303380
void NotifySwfEntity::playSoundImpl(NotifyHandler* pHandler, const Params& params)
{
    NotifySwfEntity* pThis = static_cast<NotifySwfEntity*>(pHandler);
    if (pThis)
        pThis->playSound(params);
}

MS2_REPLACE_METHOD(0x142302ED0, NotifySwfEntity, getUserData, 893, 0x7CC96DE8);
MS2_REPLACE_METHOD(0x142303260, NotifySwfEntity, playSound, 213, 0x4F7DFD0D);
MS2_REPLACE(0x142303340, NotifySwfEntity::getUserDataImpl, 52, 0x32B13CD4);
MS2_REPLACE(0x142303380, NotifySwfEntity::playSoundImpl, 52, 0xE95B9AA1);

// MS2-PIN: ??_GNotifySwfEntity@@UEAAPEAXI@Z 0x1423033e0
