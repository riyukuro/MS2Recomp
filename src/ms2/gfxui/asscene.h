// asscene.h - ASScene (RTTI .?AVASScene@@, base ASGameEntity, vftable 0x14311a6c0, 26 slots, no overrides besides the
// dtor): the AS scene object of UISceneEntity. Header name and directory assumed (the GFx UI library has no __FILE__
// strings). Method names are invented from the AS methods they call.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/asgameentity.h"

class ASScene : public ASGameEntity
{
public:
    ASScene(const Scaleform::GFx::Value& v, int nMovieId);     // 0x1422f7310
    virtual ~ASScene();                                         // 0x1422f7360 (scalar deleting 0x1422f7480)
    void Enter();                                               // 0x1422f7390 "enter"
    void Leave();                                               // 0x1422f73d0 "leave"
    void WorldLoadComplete();                                   // 0x1422f7410 "worldLoadComplete"
    void WorldUnLoadComplete();                                 // 0x1422f7450 "worldUnLoadComplete"
};
MS2_CHECK_SIZE(ASScene, 0x88);
