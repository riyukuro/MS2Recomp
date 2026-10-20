// ms2renderprocessors.h - render-list processors / clicks built by PostProcessingService's pre-process clicks.
// The ctors, dtors and ??_G of these classes are emitted in client\ms2\postprocessing\postprocessingservice.cpp;
// PreRenderProcessList lives in the unnamed units unit_14150c5e0 (shimmer) and unit_1415154d0 (velocity).
#pragma once
#include "ms2/ms2layout.h"
#include "ms2/client/ms2/ms2outlinepreprocessor.h"
#include <NiMaterialSwapProcessor.h>
#include <NiShaderSortProcessor.h>
#include <NiViewRenderClick.h>
#include <NiMaterialLibrary.h>

extern NiFixedString DAT_143ae52b0;     // shimmer material name
extern NiFixedString DAT_143ae52b8;     // shimmer (skinned) material name
int FUN_1414d3780(MS2OutlinePreProcessor* p);   // outline pre-processor object count

// Swaps the motion-blur velocity material onto every visible object (0x28 bytes).
class MS2VelocityMaterialSwapProcessor : public NiMaterialSwapProcessor
{
    NiDeclareRTTI;                      // ms_RTTI 0x143ae0e88

public:
    MS2VelocityMaterialSwapProcessor(NiMaterial* pkMaterial, unsigned int uiMaterialExtraData)    // 0x1416ae8a0
        : NiMaterialSwapProcessor(pkMaterial, uiMaterialExtraData)
    {
    }
    virtual ~MS2VelocityMaterialSwapProcessor()     // 0x1416af0e0, ??_G 0x1416b01b0
    {
    }
    virtual void PreRenderProcessList(const NiVisibleArray* pkInput, NiVisibleArray& kOutput, void* pvExtraData);   // 0x1415154d0

    void FUN_14135e060(int nMode);      // m_nMode setter (ICF-folded int setter)

    int m_nMode;                        // +0x20 (not set by the ctor)
};
MS2_CHECK_SIZE(MS2VelocityMaterialSwapProcessor, 0x28);

// Sorts the shimmering (refractive) objects with the two shimmer materials (0xc0 bytes).
class MS2ShimmerSortProcessor : public NiShaderSortProcessor
{
    NiDeclareRTTI;                      // ms_RTTI 0x143ae0e68

public:
    MS2ShimmerSortProcessor()           // 0x1416ae7e0
        : NiShaderSortProcessor(32, 37, 512, 128)
    {
        m_spMaterial = NiMaterialLibrary::CreateMaterial(DAT_143ae52b0);
        m_spSkinnedMaterial = NiMaterialLibrary::CreateMaterial(DAT_143ae52b8);
    }
    virtual ~MS2ShimmerSortProcessor()  // 0x1416af050, ??_G 0x1416b0150
    {
        m_spMaterial = 0;
        m_spSkinnedMaterial = 0;
    }
    virtual void PreRenderProcessList(const NiVisibleArray* pkInput, NiVisibleArray& kOutput, void* pvExtraData);   // 0x14150c5e0

    NiMaterialPtr m_spMaterial;         // +0xb0
    NiMaterialPtr m_spSkinnedMaterial;  // +0xb8
};
MS2_CHECK_SIZE(MS2ShimmerSortProcessor, 0xc0);

// The outline click: reports the outline pre-processor's object count as its draw count.
class OutlineRenderClick : public NiViewRenderClick
{
public:
    // implicit default ctor 0x1416ae980 (NiNew OutlineRenderClick() zero-fills first)
    virtual ~OutlineRenderClick()       // 0x1416af150, ??_G 0x1416b02d0
    {
    }
    virtual unsigned int GetNumObjectsDrawn() const     // 0x1416b0df0
    {
        return FUN_1414d3780((MS2OutlinePreProcessor*)GetProcessor());
    }
};
MS2_CHECK_SIZE(OutlineRenderClick, 0xd0);
