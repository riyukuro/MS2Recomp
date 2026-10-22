// PhysX 2.8.4.6 actor descriptor (include-path overlay, see NxScene.h here). Our own declaration, used instead of the
// SDK's NxActorDesc.h: it takes that header's include guard, so the SDK headers that include it (Nxp.h, NxPhysics.h, ...)
// see this one. Only what the engine and the game use is declared.
//
// Why: the exe's NxActorDesc is 0x90 bytes, not the 2.8.4.4 SDK's 0x88. Between the base part (0x70 bytes) and the shape
// array (+0x78) the 2.8.4.6 constructor stores a pointer to that array, obtained through an identity call (exe ctor
// 0x140ae1400 per TU: memset 0x90, setToDefault, type = 1, [+0x70] = FUN_140ae2490(&shapes); dtor / setToDefault use the
// array at +0x78). The shipped PhysXCore64.dll reads the array at +0x78. The real names of that member and of the helper
// are unknown (2.8.4.6 headers are not available).
//
// Layout (x64): globalPose +0x00 (NxMat34), body +0x30, density +0x38, flags +0x3c, group +0x40, dominanceGroup +0x42,
// contactReportFlags +0x44, forceFieldMaterial +0x48, userData +0x50, name +0x58, compartment +0x60, type +0x68,
// [NxActorDesc] shapes pointer +0x70, shapes +0x78; sizeof 0x90.
#ifndef NX_PHYSICS_NXACTORDESC
#define NX_PHYSICS_NXACTORDESC

#include "NxBodyDesc.h"
#include "NxShapeDesc.h"

class NxCompartment;

// the identity call of the 2.8.4.6 NxActorDesc constructor (0x140ae2490 per TU; real name unknown)
template<class T> NX_INLINE T* NxMs2Physx2846Self(T& r) { return &r; }

// which concrete descriptor a NxActorDescBase is (createActor dispatches on it)
enum NxActorDescType
{
    NX_ADT_SHAPELESS,
    NX_ADT_DEFAULT,
    NX_ADT_ALLOCATOR,
    NX_ADT_LIST,
    NX_ADT_POINTER
};

class NxActorDescBase
{
public:
    NxMat34             globalPose;
    const NxBodyDesc*   body;               // NULL: static actor
    NxReal              density;
    NxU32               flags;              // NxActorFlag
    NxActorGroup        group;
    NxDominanceGroup    dominanceGroup;
    NxU32               contactReportFlags;
    NxU16               forceFieldMaterial;
    void*               userData;
    const char*         name;
    NxCompartment*      compartment;

    NX_INLINE void setToDefault();
    NX_INLINE bool isValid() const { return !checkValid(); }
    NX_INLINE NxU32 checkValid() const;
    NX_INLINE NxActorDescType getType() const { return type; }

protected:
    NX_INLINE NxActorDescBase() {}
    NX_INLINE bool isValidInternal(bool hasSolidShape) const;

    NxActorDescType     type;
};

class NxActorDesc : public NxActorDescBase
{
public:
    NxArray<NxShapeDesc*, NxAllocatorDefault>*  ms2_physx2846_shapesPtr;    // +0x70, see the top of the file
    NxArray<NxShapeDesc*, NxAllocatorDefault>   shapes;                     // +0x78

    NX_INLINE NxActorDesc();
    NX_INLINE void setToDefault();
    NX_INLINE bool isValid() const { return !checkValid(); }
    NX_INLINE NxU32 checkValid() const;
};

// Inline bodies: the exe inlines them, so statement order follows the exe's code.

NX_INLINE void NxActorDescBase::setToDefault()
{
    body = NULL;
    density = 0.0f;
    globalPose.id();
    flags = 0;
    userData = NULL;
    name = NULL;
    group = 0;
    dominanceGroup = 0;
    contactReportFlags = 0;
    forceFieldMaterial = 0;
    compartment = NULL;
}

// 0 when valid, otherwise a small error code
NX_INLINE NxU32 NxActorDescBase::checkValid() const
{
    if (density < 0)
        return 1;
    if (body && !body->isValid())
        return 2;
    if (!globalPose.isFinite())
        return 3;
    if (!body && dominanceGroup)    // a static actor stays in dominance group 0
        return 4;
    return 0;
}

// mass properties must come from exactly one source: density + solid shapes, a mass + solid shapes, or mass + tensor
NX_INLINE bool NxActorDescBase::isValidInternal(bool hasSolidShape) const
{
    bool byDensity = density != 0.0f;
    bool byMass = body && body->mass != 0.0f;
    bool byTensor = body && !(body->massSpaceInertia.isZero() > 0.0f);
    if (hasSolidShape && byDensity && !byMass && !byTensor)
        return true;
    else if (hasSolidShape && !byDensity && byMass && !byTensor)
        return true;
    else if (!byDensity && byMass && byTensor)
        return true;
    else
        return false;
}

NX_INLINE NxActorDesc::NxActorDesc()
{
    memset(this, 0, sizeof(NxActorDesc));
    setToDefault();
    type = NX_ADT_DEFAULT;
    ms2_physx2846_shapesPtr = NxMs2Physx2846Self(shapes);
}

NX_INLINE void NxActorDesc::setToDefault()
{
    NxActorDescBase::setToDefault();
    shapes.clear();
}

// base errors scaled by 4, shape errors as code + 0x100 * shape index, 2 / 3 for a body without usable mass
NX_INLINE NxU32 NxActorDesc::checkValid() const
{
    NxU32 baseError = NxActorDescBase::checkValid();
    if (baseError)
        return 4 * baseError;

    unsigned int solidShapes = 0;
    if (!body && shapes.size() > 0)     // static actor with shapes: nothing more to check
        return 0;
    for (unsigned i = 0; i < shapes.size(); i++)
    {
        NxU32 shapeError = shapes[i]->checkValid();
        if (shapeError)
            return shapeError + 0x100 * i;
        if ((shapes[i]->shapeFlags & NX_TRIGGER_ENABLE) == 0)
            solidShapes++;
    }
    if (solidShapes == 0 && body && !(body->flags & NX_BF_KINEMATIC) && (body->mass < 0 || body->massSpaceInertia.isZero()))
        return 2;
    if (!NxActorDescBase::isValidInternal(solidShapes > 0))
        return 3;
    return 0;
}

#endif
