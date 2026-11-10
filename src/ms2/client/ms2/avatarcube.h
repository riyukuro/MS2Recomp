// avatarcube.h - AvatarCube (RTTI "AvatarCube", efd class id 0x06200047, size 0x1a0 = CloneCube): the cube/furnishing
// preview object of the avatar model views (UIAvatarCube, CUgcViewerCube). Owning unit: ?\avatarcube.cpp
// (0x1409f2670-0x1409f3370). Header name assumed.
//
// vftable 0x142dc0xxx (IBase) and CallbackObject vftable (dtor thunk vfunc_o8_0 0x1409f2d9c); ctor 0x1409f2960,
// dtor 0x1409f27e0, ??_G 0x1409f2db0, GetClassDesc 0x1409f2f50, TypeCast 0x1409f3130 / 0x1409f3180, ClassInfo 0x143ab4800.
#pragma once
#include "ms2/client/ms2/clonecube.h"

class AvatarCube : public CloneCube
{
    EE_DECLARE_CLASS1(AvatarCube, 0x06200047, GameObject);

public:
    // spData by value in the exe (copied for CloneCube's by-value parameter); the model path is the empty UGC cube.
    AvatarCube(CItemData* pData);                             // 0x1409f2960 (raw pointer: MS2Ptr(T*) 0x1401bf970 builds the by-value argument)
    virtual ~AvatarCube();                                  // 0x1409f27e0

    virtual void vfunc_12();                                // 12 0x1409f2820 starts the idle animation
    virtual void vfunc_59(MS2Ptr<CItem> spItem);            // 59 0x1409f2a00 loads the UGC texture of the item
};
MS2_CHECK_SIZE(AvatarCube, 0x1a0);

unsigned int FUN_1409f2cd0();   // 0x1409f2cd0
// Creates an AvatarCube for spData with a free object id (0x410..0x419), rotated 90 degrees; null when none is free.
AvatarCube* CreateAvatarCube(CItemData* pData);   // 0x1409f2670
