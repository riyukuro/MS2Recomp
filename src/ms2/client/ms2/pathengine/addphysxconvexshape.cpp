// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). PathEngine glue: PhysX shapes -> PathEngine content
// processing input. The range holds two original TUs (file names assumed, no __FILE__): the client's versions of the
// SDK sample's AddPhysXConvexShape.cpp (0x141637d50: box/convex/sphere shapes as convex solids; the client rounds
// with its own float->int helper and defines the dispatcher first) and CP3DSnapshotFromPhysX.cpp (0x14163a270: the
// whole scene; the client skips dynamic non-kinematic actors and entities with flat model 0xd3b04f05 and flags
// triangle meshes of PhysX group 8). See pathengineglue.h.
// MS2-UNIT: unit_141637d50
// MS2-RANGE: 0x141637d50-0x14163bc10 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\pathengine\\addphysxconvexshape.cpp"
#define NOMINMAX
#include "ms2/placeholder/ms2stdafx.h"
#include "pathengineglue.h"

// NxMath::cos/sin call the CRT through the exe's IAT.
#include <math.h>
extern "C" float (__cdecl* __imp_cosf)(float);
extern "C" float (__cdecl* __imp_sinf)(float);
#define cosf(x) __imp_cosf(x)
#define sinf(x) __imp_sinf(x)

#include <NxPhysics.h>
#include <NxConvexShape.h>
#include <NxConvexMesh.h>
#include <NxConvexMeshDesc.h>
#include <NxBoxShape.h>
#include <NxBoxShapeDesc.h>
#include <NxSphereShape.h>
#include <NxTriangleMeshShape.h>
#include <NxHeightFieldShape.h>
#include <egf/Entity.h>
#include <egf/FlatModel.h>
#include <egfPhysX/EntityActorData.h>

#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

int FUN_140291d90(float value);   // the client's round-half-away-from-zero float -> int

static void GetPoints(const NxBoxShape& shape, float scale, std::vector<NxVec3>& addTo);
static void GetPoints(const NxConvexShape& shape, float scale, std::vector<NxVec3>& addTo);
static void GetPoints(const NxSphereShape& shape, float scale, std::vector<NxVec3>& addTo);

// @0x141637d50
bool AddPhysXConvexShape(const NxShape& shape, float scale, cSolidObjects& addTo)
{
    std::vector<NxVec3> vertices;
    NxShapeType type = shape.getType();
    if (type == NX_SHAPE_BOX)
    {
        GetPoints(*shape.isBox(), scale, vertices);
    }
    else if (type == NX_SHAPE_CONVEX)
    {
        GetPoints(*shape.isConvexMesh(), scale, vertices);
    }
    else if (type == NX_SHAPE_SPHERE)
    {
        GetPoints(*shape.isSphere(), scale, vertices);
    }
    else
    {
        return false;
    }

    std::vector<tSigned32> coords(vertices.size() * 3);
    tSigned32 i;
    for (i = 0; i != static_cast<tSigned32>(vertices.size()); ++i)
    {
        coords[i * 3 + 0] = FUN_140291d90(vertices[i].x);
        coords[i * 3 + 1] = FUN_140291d90(vertices[i].y);
        coords[i * 3 + 2] = FUN_140291d90(vertices[i].z);
    }
    addTo.add(coords);
    return true;
}

// The 8 box corners.
// @0x141637f90
static void GetPoints(const NxBoxShape& shape, float scale, std::vector<NxVec3>& addTo)
{
    NxMat34 pose = shape.getGlobalPose();
    pose.M *= scale;
    pose.t *= scale;
    NxBoxShapeDesc desc;
    shape.saveToDesc(desc);
    NxVec3 half = desc.dimensions;
    for (tSigned32 i = 0; i != 8; ++i)
    {
        NxVec3 corner;
        corner.x = i < 4 ? -half.x : half.x;
        corner.y = (i & 3) < 2 ? -half.y : half.y;
        corner.z = (i & 1) < 1 ? -half.z : half.z;
        NxVec3 world;
        pose.multiply(corner, world);
        addTo.push_back(world);
    }
}

// The hull vertices of the convex mesh.
// @0x141638170
static void GetPoints(const NxConvexShape& shape, float scale, std::vector<NxVec3>& addTo)
{
    NxMat34 pose = shape.getGlobalPose();
    pose.M *= scale;
    pose.t *= scale;
    NxConvexMeshDesc desc;
    shape.getConvexMesh().saveToDesc(desc);
    const char* base = (const char*)(desc.points);
    tSigned32 count = static_cast<tSigned32>(desc.numVertices);
    for (tSigned32 i = 0; i != count; ++i)
    {
        const NxVec3* p = (const NxVec3*)(base + i * desc.pointStrideBytes);
        const NxVec3& onSphere = *p;
        NxVec3 world;
        pose.multiply(onSphere, world);
        addTo.push_back(world);
    }
}

// Poles plus 7 rings of 16 vertices.
// @0x1416382c0
static void GetPoints(const NxSphereShape& shape, float scale, std::vector<NxVec3>& addTo)
{
    NxMat34 pose = shape.getGlobalPose();
    pose.M *= scale;
    pose.t *= scale;
    NxReal r = shape.getRadius();

    const tSigned32 around = 16;
    const tSigned32 up = 8;

    NxVec3 world;
    {
        const NxVec3 top(0, 0, r);
        pose.multiply(top, world);
        addTo.push_back(world);
    }
    {
        const NxVec3 bottom(0, 0, -r);
        pose.multiply(bottom, world);
        addTo.push_back(world);
    }

    NxReal stepUp = static_cast<NxReal>(3.14159 / up);
    NxReal stepAround = static_cast<NxReal>(3.14159 * 2 / around);
    for (tSigned32 i = 1; i != up; ++i)
    {
        NxReal angleUp = stepUp * static_cast<NxReal>(i);
        NxReal z = r * NxMath::cos(angleUp);
        NxReal ringRadius = r * NxMath::sin(angleUp);
        for (tSigned32 j = 0; j != around; ++j)
        {
            NxReal angleAround = stepAround * static_cast<NxReal>(j);
            NxReal x = ringRadius * NxMath::sin(angleAround);
            NxReal y = ringRadius * NxMath::cos(angleAround);
            const NxVec3 onSphere(x, y, z);
            pose.multiply(onSphere, world);
            addTo.push_back(world);
        }
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// CP3DSnapshotFromPhysX

// @0x14163a270
void BuildCP3DSnapshotFromPhysX(NxScene* scene, std::vector<const iFaceVertexMesh*>& meshes,
                                iSolidObjects*& solids, const cCoordinateMapping& mapping,
                                float scale, bool includeDynamicComponents)
{
    tSigned32 actorCount = scene->getNbActors();
    NxActor** sceneActors = scene->getActors();
    cSolidObjects* collected = new cSolidObjects;
    solids = collected;
    for (tSigned32 i = 0; i != actorCount; ++i)
    {
        NxActor& current = *sceneActors[i];
        if (!includeDynamicComponents && current.isDynamic() && !current.readBodyFlag(NX_BF_KINEMATIC))
        {
            continue;
        }
        if (current.userData)
        {
            egfPhysX::EntityActorData* pData = static_cast<egfPhysX::EntityActorData*>(current.userData);
            if (pData && pData->GetEntity() != NULL && pData->GetEntity()->GetModel()
                && pData->GetEntity()->GetModel()->ContainsModel(0xd3b04f05))
            {
                continue;
            }
        }
        tSigned32 shapeCount = current.getNbShapes();
        NxShape* const* shapes = current.getShapes();
        for (tSigned32 j = 0; j != shapeCount; ++j)
        {
            NxShape& shape = *shapes[j];
            bool isConvex = AddPhysXConvexShape(shape, scale, *collected);
            if (isConvex)
            {
                continue;
            }
            NxShapeType type = shape.getType();
            if (type == NX_SHAPE_MESH)
            {
                NxTriangleMeshShape* pMesh = shape.isTriangleMesh();
                cPhysXTriangleMeshWrapper* pWrapper = new cPhysXTriangleMeshWrapper(*pMesh, mapping, scale);
                if (shape.getGroup() == 8)
                {
                    pWrapper->SetFlag(true);
                }
                const iFaceVertexMesh* pFaceVertexMesh = pWrapper;
                meshes.push_back(pFaceVertexMesh);
            }
            else if (type == NX_SHAPE_HEIGHTFIELD)
            {
                NxHeightFieldShape* pField = shape.isHeightField();
                meshes.push_back(new cPhysXTerrainWrapper(*pField, mapping, scale));
            }
        }
    }
    collected->applyCoordinateMapping(mapping);
}

// @0x14163a7b0
void DeleteCP3DSnapshotFromPhysX(std::vector<const iFaceVertexMesh*>& meshes, iSolidObjects*& solids)
{
    for (tSigned32 i = 0; i != static_cast<tSigned32>(meshes.size()); ++i)
    {
        delete meshes[i];
    }
    delete solids;
}

typedef void tGetBoxPoints(const NxBoxShape&, float, std::vector<NxVec3>&);
typedef void tGetConvexPoints(const NxConvexShape&, float, std::vector<NxVec3>&);
typedef void tGetSpherePoints(const NxSphereShape&, float, std::vector<NxVec3>&);

MS2_REPLACE(0x141637D50, AddPhysXConvexShape, 563, 0x1DFB6EB1);
MS2_REPLACE_OVERLOAD(0x141637F90, tGetBoxPoints, GetPoints, 461, 0x2A0E0160);
MS2_REPLACE_OVERLOAD(0x141638170, tGetConvexPoints, GetPoints, 329, 0x4369C015);
MS2_REPLACE_OVERLOAD(0x1416382C0, tGetSpherePoints, GetPoints, 672, 0xC0E8F31E);
MS2_REPLACE(0x14163A270, BuildCP3DSnapshotFromPhysX, 1323, 0x091D4DA7);
MS2_REPLACE(0x14163A7B0, DeleteCP3DSnapshotFromPhysX, 204, 0xE6A36883);
