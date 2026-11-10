// minimapviewport.h - MinimapViewport (0x90), the minimap's camera: it mirrors the map's CMinimap camera settings into
// a 4x4 world-to-minimap matrix (BuildMatrix/GetCameraAxes) and projects world positions onto the minimap image
// (FUN_141486450). gfxmoviebackground.cpp holds one (m_spViewport). Recovered from MapleStory2.exe KMS2_DEV x64
// (2022-04-13); the unit is `?\minimapviewport.cpp` (0x1414856d0-0x141486df0, dir client\ms2). Header name assumed;
// member names invented from their use.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/client/ms2/fielddatacli.h"   // NiPoint3 / Unk_Rect4 / NiFrustum / CMinimap / CFieldDataCli
#include <NiRefObject.h>
class NiPoint3;

// NiRect<float>::GetHeight / GetWidth over the 16-byte screen rect. The exe copies are the tail of this unit's range
// (0x141486d30 / 0x141486d90) and are reached as free functions: a member's thiscall (object in rcx) is the same
// calling convention as a first reference parameter, so the call sites still byte-match.
float GetRectHeight(const Unk_Rect4& rc);   // GetHeight
float GetRectWidth(const Unk_Rect4& rc);   // GetWidth

// CMinimap::m_vecCamRot read as a trivially copyable point: the exe copies it with rep movsb, with no copy ctor. The
// members are private so /GS does not treat a local of it as a buffer.
class Unk_MvRot3 { friend class MinimapViewport; float x, y, z; };

// efd::Matrix3 / NiMatrix3 (0x24), the rotation the view matrix is built from. Its default ctor is the exe's
// 0x1409f72e0, called explicitly (see the .cpp), so the view itself declares none.
struct Unk_MvMatrix3
{
    void FUN_142083d40(float fX, float fY, float fZ);           // 0x142083d40 efd::Matrix3::FromEulerAnglesXYZ (radians)
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
    unsigned InitFromFieldMinimap(int nScale);                                             // 0x141485770
    // Builds m_afMatrix from the camera position and the three rotation axes.
    void BuildMatrix(const NiPoint3& kCamPos, const NiPoint3& kAxisX, const NiPoint3& kAxisY,
                       const NiPoint3& kAxisZ);                                     // 0x141485a50
    // Extracts the three axes of the rotation matrix (in degrees) and unitizes them.
    void GetCameraAxes(Unk_MvRot3 kRot, NiPoint3& kAxisX, NiPoint3& kAxisY, NiPoint3& kAxisZ);   // 0x141486a20
    void ResetScale();                                                           // 0x1414863e0 (m_fScale = 1)
    // Projects a world position onto the minimap with the current zoom.
    bool WorldToMinimap(const NiPoint3& kPos, NiPoint3& kOut);                       // 0x141486410 (returns the in-view flag)
    bool FUN_141486450(const NiPoint3& kPos, NiPoint3& kOut, float fScale);         // 0x141486450
    // Transforms a world position by m_afMatrix; false (and FLT_MAX outputs) when it is behind the camera.
    bool ProjectPoint(const NiPoint3& kPos, float& fX, float& fY, float& fZ);      // 0x141486550

private:
    NiFrustum m_kFrustum;           // +0x10 the minimap camera frustum (m_bOrtho at +0x28)
    Unk_Rect4 m_rcImage;            // +0x2c <image l r t b>
    Unk_Rect4 m_rcScreen;           // +0x3c <screen l r t b>
    float m_afMatrix[4][4];         // +0x4c world -> minimap, rows (v' = v * M, w = row 3)
    float m_fScale;                 // +0x8c zoom factor
};
MS2_CHECK_SIZE(MinimapViewport, 0x90);
