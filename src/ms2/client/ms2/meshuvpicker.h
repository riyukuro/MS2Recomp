// meshuvpicker.h - CMeshUVPicker (RTTI .?AVCMeshUVPicker@@, 0x98 bytes, NiRefObject): finds the texture coordinate under a
// screen position by rendering a mesh with a UV-visualising material into three half-float render targets and reading one
// pixel back through a system-memory texture. The unit is `?\meshuvpicker.cpp` (0x14147e6e0-0x141480c70); the header name is
// assumed and the method names are invented from their use. vftable 0x142f18678 (scalar deleting dtor 0x1414804a0,
// DeleteThis 0x141d16bf0).
#pragma once

#include "ms2/ms2layout.h"

#include <NiRefObject.h>
#include <NiRenderTargetGroup.h>
#include <NiRenderedTexture.h>
#include <NiMaterial.h>
#include <NiPropertyState.h>
#include <NiRenderObject.h>
#include <NiCamera.h>
#include <NiPoint2.h>
#include <NiPoint3.h>
#include <d3d9.h>

#include <atlcoll.h>

#include "ms2/placeholder/postprocesseffect.h"
#include "ms2/client/ms2/frustumcollision.h"

class NiDX9Renderer;

// The 16-byte value read back from a texel (four floats; the base is the shader constant of the same shape).
class Unk_ShaderVec4
{
public:
    Unk_ShaderVec4() {}                         // 0x141480230
    float GetComponent(int nIndex) const;      // component getter
    void Assign(float x, float y, float z, float w);   // 0x14135e000
private:
    float m_f0, m_f1, m_f2, m_f3;
};
MS2_CHECK_SIZE(Unk_ShaderVec4, 0x10);

// 16-aligned in the exe: the texel local of the pick functions sits on a 16-byte slot.
class __declspec(align(16)) Unk_UVTexel : public Unk_ShaderVec4
{
public:
    Unk_UVTexel() {}                            // 0x141480210
};
MS2_CHECK_SIZE(Unk_UVTexel, 0x10);

class CMeshUVPicker : public NiRefObject
{
public:
    CMeshUVPicker();                                            // 0x14147e6e0
    virtual ~CMeshUVPicker();                                   // 0x14147e840 (scalar deleting 0x1414804a0)

    int Init();                                        // create the targets and the render states
    bool PickUV(NiRenderObject* pMesh, NiCamera* pCamera, float fX, float fY, float* pU, float* pV,
                       CAtlArray<NiRenderObject*>* pExtras);    // texel at (fX, fY): the UV
    bool PickUVAndPosition(NiRenderObject* pMesh, NiCamera* pCamera, float fX, float fY, Unk_FcPoint3* pPos0, Unk_FcPoint3* pPos1,
                       NiPoint2* pUV, float* pIndex, CAtlArray<NiRenderObject*>* pExtras);
    void RenderPickPass(NiRenderObject* pMesh, CAtlArray<NiRenderObject*>* pExtras, NiCamera* pCamera, float fX, float fY,
                       bool bSecond);                           // render the three targets
    bool CreateResources();                                       // create the render targets and read-back textures
    void CreatePropertyState();                                       // create the property state
    void ReleaseResources();                                       // release everything
    bool OnRendererReset(bool bBeforeReset);                      // device reset notification
    bool ReadTexel(int nTarget, Unk_ShaderVec4* pTexel);       // read one texel back
    NiMaterial* FUN_1414800a0(bool bSecond);                    // the (lazily created) UV material

    static bool OnRendererResetThunk(bool bBeforeReset, void* pPicker);
    static void SetColorExtraData(NiObjectNET* pObject, const NiFixedString& kKey, const NiColorA& kColor);   // set the colour extra data   // reset notification callback

    unsigned m_10;                              // +0x10 format of the read-back surface
    bool m_14;                                  // +0x14 initialised
    int m_18;                                   // +0x18 reset notification index (-1 = none)
    NiPropertyStatePtr m_20;
    NiMaterialPtr m_28;
    NiMaterialPtr m_30;
    NiRenderTargetGroupPtr m_38;
    NiRenderTargetGroupPtr m_40;
    IDirect3DDevice9* m_48;
    efd::SmartPointer<NiRenderedTexture> m_50[3];                       // the three float render targets (efd::SmartPointer<NiRenderedTexture>)
    IDirect3DTexture9* m_68[3];
    IDirect3DTexture9* m_80[3];
};
MS2_CHECK_SIZE(CMeshUVPicker, 0x98);
MS2_CHECK_OFFSET(CMeshUVPicker, m_20, 0x20);
MS2_CHECK_OFFSET(CMeshUVPicker, m_50, 0x50);
MS2_CHECK_OFFSET(CMeshUVPicker, m_68, 0x68);
MS2_CHECK_OFFSET(CMeshUVPicker, m_80, 0x80);
