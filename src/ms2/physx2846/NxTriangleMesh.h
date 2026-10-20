// PhysX 2.8.4.6 NxTriangleMesh vtable fix (include-path overlay, see NxScene.h here). The exe calls
// NxTriangleMesh::getReferenceCount through slot 16 (+0x80; NiPhysXActorDesc::RemoveActor 0x141ef0f20 and the MS2
// CreateActor 0x141eef6d0), where the 2.8.4.4 SDK header has it at slot 15 (+0x78); getCount/getBase/getStride (+0x10,
// +0x20, +0x28) are unchanged, and NxConvexMesh::getReferenceCount stays at +0x38. So 2.8.4.6 has one more virtual
// somewhere between getPageCount (slot 6) and getReferenceCount. Its name and exact position are unknown (2.8.4.6
// headers are not available); nothing in the engine or the game calls slots 6..15, so it is declared right before
// getReferenceCount. The stock header stays untouched: the macro below expands its getReferenceCount declaration into
// the missing pure virtual plus the original one (NxTriangleMesh.h itself includes no other getReferenceCount owner).
#ifndef MS2_PHYSX2846_NXTRIANGLEMESH_H
#define MS2_PHYSX2846_NXTRIANGLEMESH_H

#define getReferenceCount \
    ms2_physx2846_unknownTriangleMeshVirtual() = 0; \
    virtual NxU32 getReferenceCount
#include <Physics/include/NxTriangleMesh.h>
#undef getReferenceCount

#endif
