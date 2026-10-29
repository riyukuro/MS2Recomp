// CMirrored3DRenderView: Ni3DRenderView subclass (0x88 bytes) that renders a scene mirrored about a plane through
// m_kPlanePoint with normal +Z (water / floor reflections). SetCameraData rebuilds the renderer's view matrix.
#pragma once
#include "ms2/ms2layout.h"
#include <Ni3DRenderView.h>
#include <NiPoint3.h>

class CMirrored3DRenderView : public Ni3DRenderView {
    NiDeclareRTTI;

public:
    CMirrored3DRenderView(NiCamera* pkCamera, NiCullingProcess* pkCullingProcess, bool bAlwaysUseCameraViewport);
    // ~CMirrored3DRenderView is implicit (0x1414872a0): the exe dtor stores no vftable.
    virtual void SetCameraData(const NiRect<float>& kViewport);

    void SetMirrorPoints(const NiPoint3& kPoint, const NiPoint3& kNormal);

protected:
    NiPoint3 m_kPlanePoint;     // +0x70
    NiPoint3 m_kPlaneNormal;    // +0x7c
};
MS2_CHECK_SIZE(CMirrored3DRenderView, 0x88);
