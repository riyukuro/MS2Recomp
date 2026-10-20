// minimapviewport.h - MinimapViewport (0x90), the minimap's camera: it mirrors the map's CMinimap camera settings into
// a 4x4 world-to-minimap matrix (FUN_141485a50/FUN_141486a20) and projects world positions onto the minimap image
// (FUN_141486450). gfxmoviebackground.cpp holds one (m_spViewport). Recovered from MapleStory2.exe KMS2_DEV x64
// (2022-04-13); the unit is `?\minimapviewport.cpp` (0x1414856d0-0x141486df0, dir client\ms2). Header name assumed;
// member names invented from their use.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/client/ms2/fielddatacli.h"   // Unk_GVec3 / Unk_Rect4 / Unk_Frustum / CMinimap / CFieldDataCli
#include <NiRefObject.h>
class NiPoint3;

// NiRect<float>::GetHeight / GetWidth over the 16-byte screen rect. The exe copies are the tail of this unit's range
// (0x141486d30 / 0x141486d90) and are reached as free functions: a member's thiscall (object in rcx) is the same
// calling convention as a first reference parameter, so the call sites still byte-match.
float FUN_141486d30(const Unk_Rect4& rc);   // GetHeight
float FUN_141486d90(const Unk_Rect4& rc);   // GetWidth

// efd::Point3's unary minus hands its result back through the hidden pointer in rdx, so it cannot be reached as a free
// function the way Dot / Unitize can; it is declared on a unit-local view of the 12-byte point instead (the view adds no
// data, so Unk_GVec3 and Unk_MvPoint3 are the same object).
struct Unk_MvPoint3 : Unk_GVec3
{
    Unk_MvPoint3 FUN_1409f7960() const;                         // 0x1409f7960 efd::Point3::operator- (unary)
    Unk_MvPoint3& FUN_140194470(Unk_MvPoint3&& kOther);         // 0x140194470 NiPoint3::operator=(NiPoint3&&)
};
MS2_CHECK_SIZE(Unk_MvPoint3, 12);

// efd::Matrix3 / NiMatrix3 (0x24), the rotation the view matrix is built from. Its default ctor is the exe's
// 0x1409f72e0 (called explicitly, see the .cpp).
struct Unk_MvMatrix3
{
    Unk_MvMatrix3() {}                                          // 0x1409f72e0 efd::Matrix3::Matrix3()
    void FUN_142083d40(float fX, float fY, float fZ);           // 0x142083d40 efd::Matrix3::FromEulerAnglesXYZ (radians)
    void FUN_140a01190(unsigned uiCol, Unk_GVec3& kCol) const;  // 0x140a01190 efd::Matrix3::GetCol
    float m_afEntry[3][3];
};
MS2_CHECK_SIZE(Unk_MvMatrix3, 0x24);

// 0x90 bytes; vftable 0x142f19830 (slot 0 = the scalar deleting dtor 0x141486cd0, slot 1 = NiRefObject::DeleteThis
// 0x141d16bf0), so the class declares no virtual function of its own beyond the destructor.
class MinimapViewport : public NiRefObject
{
public:
    MinimapViewport();                                                              // 0x1414856d0

    // Copies the map's minimap camera settings and rebuilds the view matrix; nScale > 0 overrides the zoom.
    unsigned FUN_141485770(int nScale);                                             // 0x141485770
    // Builds m_afMatrix from the camera position and the three rotation axes.
    void FUN_141485a50(const Unk_GVec3& kCamPos, const Unk_GVec3& kAxisX, const Unk_GVec3& kAxisY,
                       const Unk_GVec3& kAxisZ);                                    // 0x141485a50
    // Extracts the three axes of the rotation matrix (in degrees) and unitizes them.
    void FUN_141486a20(Unk_GVec3 kRot, Unk_GVec3& kAxisX, Unk_GVec3& kAxisY, Unk_GVec3& kAxisZ);   // 0x141486a20
    void FUN_1414863e0();                                                           // 0x1414863e0 (m_fScale = 1)
    // Projects a world position onto the minimap with the current zoom.
    void FUN_141486410(const Unk_GVec3& kPos, Unk_GVec3& kOut);                     // 0x141486410
    bool FUN_141486450(const Unk_GVec3& kPos, Unk_GVec3& kOut, float fScale);       // 0x141486450
    bool FUN_141486410(const NiPoint3& kPos, NiPoint3& kOut);                      // 0x141486410 (NiPoint3 form, returns the in-view flag; uiminimapentity.cpp)
    // Transforms a world position by m_afMatrix; false (and FLT_MAX outputs) when it is behind the camera.
    bool FUN_141486550(const Unk_GVec3& kPos, float& fX, float& fY, float& fZ);     // 0x141486550

private:
    Unk_Frustum m_kFrustum;         // +0x10 the minimap camera frustum (m_bOrtho at +0x28)
    Unk_Rect4 m_rcImage;            // +0x2c <image l r t b>
    Unk_Rect4 m_rcScreen;           // +0x3c <screen l r t b>
    float m_afMatrix[4][4];         // +0x4c world -> minimap, rows (v' = v * M, w = row 3)
    float m_fScale;                 // +0x8c zoom factor
};
MS2_CHECK_SIZE(MinimapViewport, 0x90);
