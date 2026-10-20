// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). ASScene, the AS scene of a UISceneEntity.
// MS2-UNIT: ?\asscene.cpp
// MS2-RANGE: 0x1422f7310-0x1422f74c0 .text$mn
//
// The unit name and directory are assumed (the GFx UI library 0x1422b0000-0x142304000 has no __FILE__ strings).
#include "ms2/placeholder/ms2stdafx.h"

#include "ms2/gfxui/asscene.h"

#include "hook/ms2hook.h"

// @0x1422f7310
ASScene::ASScene(const Scaleform::GFx::Value& v, int nMovieId)
    : ASGameEntity(v, nMovieId)
{
}

// @0x1422f7360
ASScene::~ASScene()
{
}

// @0x1422f7390
void ASScene::Enter()
{
    Invoke("enter");
}
MS2_REPLACE_METHOD(0x1422F7390, ASScene, Enter, 46, 0x9BE7E39B);

// @0x1422f73d0
void ASScene::Leave()
{
    Invoke("leave");
}
MS2_REPLACE_METHOD(0x1422F73D0, ASScene, Leave, 46, 0xD68DDFF3);

// @0x1422f7410
void ASScene::WorldLoadComplete()
{
    Invoke("worldLoadComplete");
}
MS2_REPLACE_METHOD(0x1422F7410, ASScene, WorldLoadComplete, 46, 0x6D4A8C78);

// @0x1422f7450
void ASScene::WorldUnLoadComplete()
{
    Invoke("worldUnLoadComplete");
}
MS2_REPLACE_METHOD(0x1422F7450, ASScene, WorldUnLoadComplete, 46, 0x1E2A39B5);

// MS2-PIN: ??_GASScene@@UEAAPEAXI@Z 0x1422f7480
