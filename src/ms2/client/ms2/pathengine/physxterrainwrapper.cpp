// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). PathEngine glue: cPhysXTerrainWrapper (a PhysX height
// field shape as an iFaceVertexMesh). File name assumed (no __FILE__ in the range). The class comes from the SDK
// sample header (in place, see pathengineglue.h); the client's constructor differs from the SDK sample (it never
// calls NxHeightField::saveCells: the sample buffer is only allocated and pointed to, and has no asserts), so the
// bodies are recovered from the exe.
// MS2-UNIT: unit_141649870
// MS2-RANGE: 0x141649870-0x14164c5a0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$_Emplace_back_with_unused_capacity@AEBJ@?$vector@JV?$allocator@J@std@@@std@@AEAAXAEBJ@Z 0x14164a230 ; prop
// MS2-PIN: ??$_Emplace_back_with_unused_capacity@J@?$vector@JV?$allocator@J@std@@@std@@AEAAX$$QEAJ@Z 0x14164a2f0 ; prop
// MS2-PIN: ??$_Emplace_reallocate@AEBJ@?$vector@JV?$allocator@J@std@@@std@@QEAAPEAJQEAJAEBJ@Z 0x14164a3b0 ; prop
// MS2-PIN: ??$_Emplace_reallocate@J@?$vector@JV?$allocator@J@std@@@std@@QEAAPEAJQEAJ$$QEAJ@Z 0x14164a5f0 ; prop
// MS2-PIN: ??$construct@JAEBJ@?$_Default_allocator_traits@V?$allocator@J@std@@@std@@SAXAEAV?$allocator@J@1@QEAJAEBJ@Z 0x14164abe0 ; prop
// MS2-PIN: ??$emplace_back@AEBJ@?$vector@JV?$allocator@J@std@@@std@@QEAAXAEBJ@Z 0x14164add0 ; unique
// MS2-PIN: ??$emplace_back@J@?$vector@JV?$allocator@J@std@@@std@@QEAAX$$QEAJ@Z 0x14164ae40 ; unique
// MS2-PIN: ??$forward@J@std@@YA$$QEAJAEAJ@Z 0x14164af40 ; prop
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\pathengine\\physxterrainwrapper.cpp"
#define NOMINMAX
#include "ms2/placeholder/ms2stdafx.h"
#include "pathengineglue.h"

#include <NxPhysics.h>
#include <NxHeightFieldShape.h>
#include <NxHeightFieldShapeDesc.h>
#include <NxHeightField.h>
#include <NxHeightFieldDesc.h>
#include <NxHeightFieldSample.h>
#include <NxMat34.h>

#include "ms2/ms2layout.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

MS2_CHECK_SIZE(cPhysXTerrainWrapper, 0x60);

// @0x141649870
cPhysXTerrainWrapper::cPhysXTerrainWrapper(const NxHeightFieldShape& shape, const cCoordinateMapping& mapping, float scale)
{
    NxMat34 pose = shape.getGlobalPose();
    pose.M *= scale;
    pose.t *= scale;

    NxHeightFieldShapeDesc shapeDesc;
    shape.saveToDesc(shapeDesc);

    const NxHeightField& field = shape.getHeightField();
    NxHeightFieldDesc fieldDesc;
    field.saveToDesc(fieldDesc);

    _stride = fieldDesc.nbColumns;
    _strides = fieldDesc.nbRows;
    tSigned32 count = _stride * _strides;
    std::vector<char> cells(count * fieldDesc.sampleStride);
    fieldDesc.samples = (void*)(&cells[0]);

    _pointCoords.reserve(count * 3);
    _tessellationFlags.reserve(count);
    const char* cursor = (const char*)(fieldDesc.samples);
    tSigned32 face = 0;
    for (tSigned32 r = 0; r != _strides; ++r)
    {
        NxVec3 local;
        local.x = static_cast<NxReal>(r) * shapeDesc.rowScale;
        for (tSigned32 c = 0; c != _stride; ++c)
        {
            const NxHeightFieldSample* p = (NxHeightFieldSample*)cursor;
            const NxHeightFieldSample& cell = *p;
            local.y = static_cast<NxReal>(cell.height) * shapeDesc.heightScale;
            local.z = static_cast<NxReal>(c) * shapeDesc.rowScale;
            NxVec3 world;
            pose.multiply(local, world);
            _pointCoords.push_back(static_cast<tSigned32>(world.x));
            _pointCoords.push_back(static_cast<tSigned32>(world.y));
            _pointCoords.push_back(static_cast<tSigned32>(world.z));
            _tessellationFlags.push_back(cell.tessFlag);
            if (r + 1 != _strides && c + 1 != _stride)
            {
                if (cell.materialIndex0 != shapeDesc.holeMaterial)
                {
                    _holesRemap.push_back(face);
                }
                if (cell.materialIndex1 != shapeDesc.holeMaterial)
                {
                    _holesRemap.push_back(face + 1);
                }
            }
            face += 2;
            cursor += fieldDesc.sampleStride;
        }
    }

    for (tSigned32 v = 0; v != count; ++v)
    {
        mapping.applyTo(&_pointCoords[v * 3]);
    }
}

// @0x141649d60
tSigned32 cPhysXTerrainWrapper::faces() const
{
    return static_cast<tSigned32>(_holesRemap.size());
}

// @0x141649d90
tSigned32 cPhysXTerrainWrapper::vertices() const
{
    return _stride * _strides;
}

// Two triangles per cell; the tessellation flag picks the diagonal. Corner 0..3 = (x,y), (x+1,y), (x+1,y+1), (x,y+1).
// @0x141649db0
tSigned32 cPhysXTerrainWrapper::vertexIndex(tSigned32 face, tSigned32 vertexInFace) const
{
    tSigned32 cellFace = _holesRemap[face];
    tSigned32 cellIndex = cellFace / 2;
    tSigned32 half = (cellFace & 1);
    tSigned32 corner;
    if (_tessellationFlags[cellIndex])
    {
        const tSigned32 corners[] = {0, 3, 1, 1, 3, 2};
        corner = corners[half * 3 + vertexInFace];
    }
    else
    {
        const tSigned32 corners[] = {0, 2, 1, 0, 3, 2};
        corner = corners[half * 3 + vertexInFace];
    }
    tSigned32 vertex = cellIndex;
    switch (corner)
    {
    default:
    case 0:
        break;
    case 1:
        ++vertex;
        break;
    case 2:
        vertex += 1 + _stride;
        break;
    case 3:
        vertex += _stride;
        break;
    }
    return vertex;
}

// @0x141649f40
tSigned32 cPhysXTerrainWrapper::vertexX(tSigned32 vertex) const
{
    return _pointCoords[vertex * 3];
}

// @0x141649f80
tSigned32 cPhysXTerrainWrapper::vertexY(tSigned32 vertex) const
{
    return _pointCoords[vertex * 3 + 1];
}

// @0x141649fc0
float cPhysXTerrainWrapper::vertexZ(tSigned32 vertex) const
{
    return static_cast<float>(_pointCoords[vertex * 3 + 2]);
}

// Every terrain face is in section 0.
// @0x14164a000
tSigned32 cPhysXTerrainWrapper::faceAttribute(tSigned32, tSigned32 attributeIndex) const
{
    if (attributeIndex == PE_FaceAttribute_SectionID)
    {
        return 0;
    }
    return -1;
}


MS2_REPLACE_METHOD(0x141649D60, cPhysXTerrainWrapper, faces, 31, 0x74563419);
MS2_REPLACE_METHOD(0x141649D90, cPhysXTerrainWrapper, vertices, 23, 0x2CD4B1E3);
MS2_REPLACE_METHOD(0x141649DB0, cPhysXTerrainWrapper, vertexIndex, 386, 0xAAA96DAF);
MS2_REPLACE_METHOD(0x141649F40, cPhysXTerrainWrapper, vertexX, 44, 0xF32E19CC);
MS2_REPLACE_METHOD(0x141649F80, cPhysXTerrainWrapper, vertexY, 46, 0x442D623D);
MS2_REPLACE_METHOD(0x141649FC0, cPhysXTerrainWrapper, vertexZ, 49, 0x2B37BCC3);
MS2_REPLACE_METHOD(0x14164A000, cPhysXTerrainWrapper, faceAttribute, 31, 0x90C68695);
