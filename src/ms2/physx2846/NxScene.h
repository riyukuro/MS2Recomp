// PhysX 2.8.4.6 NxScene vtable fix (include-path overlay, cmake/ms2-engine-flags.cmake; searched before the SDK's Physics/include).
// The game ships PhysXCore64.dll 2.8.4.6, whose Scene vtable has one virtual more than the 2.8.4.4 SDK headers we compile
// against (and 2.8.3, identical there): a 4-argument forwarder between linearOBBSweep and linearCapsuleSweep (2.8.4.6 DLL
// slot 120, 0x18012a1f0 -> inner scene slot 0x2a0). Every later NxScene slot is one higher in the exe (checkOverlapCapsule
// +0x3f0, not +0x3e8; the field getters 154-166 match one slot up), verified with work/fx22/vtcmp.py. The stock header
// stays untouched: the macro below expands its linearCapsuleSweep declaration into the missing pure virtual plus the
// original one. Its name is unknown (2.8.4.6 headers are not available); nothing calls it.
#ifndef MS2_PHYSX2846_NXSCENE_H
#define MS2_PHYSX2846_NXSCENE_H

#include <Physics/include/NxSceneQuery.h>   // the only other SDK class declaring linearCapsuleSweep: keep it out of the macro

#define linearCapsuleSweep \
    ms2_physx2846_unknownSweep(void*, void*, void*, void*) = 0; \
    virtual NxU32 linearCapsuleSweep
#include <Physics/include/NxScene.h>
#undef linearCapsuleSweep

#endif
