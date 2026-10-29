// rootrotateinterpolator.h - RootRotateInterpolator (RTTI "RootRotateInterpolator" 0x143ac49a8, 0x90 bytes,
// NiTransformInterpolator): rotates the root node by a fixed euler offset (m_rotation, degrees) on top of the animated
// transform. Owning unit: ?\rootrotateinterpolator.cpp. Header name assumed from the unit path; member names are invented.
#pragma once
#include <NiTransformInterpolator.h>
#include "ms2/ms2layout.h"

struct Unk_RrPoint3 { float x, y, z; };
struct Unk_RrMatrix3 { float m[9]; };

class RootRotateInterpolator : public NiTransformInterpolator
{
    NiDeclareRTTI;                                              // GetRTTI 0x140dca0a0
public:
    RootRotateInterpolator();                                   // 0x140dc9b30 (always-update off)
    RootRotateInterpolator(const void* pUnused);                // 0x140dc9bd0 (always-update on; the 8-byte arg is never read)
    // virtual ~RootRotateInterpolator();                       // 0x140dca000 (??_G 0x140dca020) implicit: the exe dtor stores no vptr
    virtual bool Update(float fTime, NiObjectNET* pkInterpTarget, NiQuatTransform& kValue);   // 0x140dc9c80
    virtual bool AlwaysUpdate() const;                          // 0x140dca080

    void FUN_140dc9e40(Unk_RrPoint3* pRotation);                // set the euler offset (degrees), rebuild the matrix
    void FUN_140dc9fb0(const Unk_RrPoint3* pValue);             // set the raw point at +0x50

private:
    MS2_LAYOUT_FRIEND;
    Unk_RrPoint3 m_axis;                                        // +0x50 rotation axis of the animated turn
    Unk_RrPoint3 m_rotation;                                    // +0x5c euler offset in degrees
    Unk_RrMatrix3 m_matrix;                                     // +0x68
    bool m_bAlwaysUpdate;                                       // +0x8c
};
MS2_CHECK_SIZE(RootRotateInterpolator, 0x90);
MS2_CHECK_OFFSET(RootRotateInterpolator, m_matrix, 0x68);
