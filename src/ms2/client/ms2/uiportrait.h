// uiportrait.h - UIPortrait (RTTI .?AVUIPortrait@@, 0x60 bytes): the UIRenderView that draws the local player's head
// portrait. It adds no members; it overrides the tick (camera in front of the head), the actor setup and the light /
// camera creation. Unit `?\uiportrait.cpp` (.text$mn 0x141a90500-0x141a911b0, vftables 0x142fd56b0 / 0x142fd5740);
// every name except the RTTI class names is invented from its use.
#pragma once

#include "ms2/client/ms2/uirenderview.h"

class UIPortrait : public UIRenderView
{
public:
    UIPortrait(unsigned int uiWidth, unsigned int uiHeight, GameObject* pObject, float fLightDimmer);   // 0x141a90b60
    virtual ~UIPortrait();                                  // 0x141a90500 (scalar deleting 0x141a91150)

    virtual void vfunc_2();                                 // 2 0x141a905f0 camera in front of the player's head
    virtual void vfunc_3();                                 // 3 0x141a907e0
    virtual void vfunc_11(ATL::CAtlArray<efd::SmartPointer<NiActorManager> >& arrActors);   // 11 0x141a90800
    virtual int vfunc_14();                                 // 14 0x141a90bd0
    virtual int vfunc_15();                                 // 15 0x141a90ed0
};
MS2_CHECK_SIZE(UIPortrait, 0x60);
