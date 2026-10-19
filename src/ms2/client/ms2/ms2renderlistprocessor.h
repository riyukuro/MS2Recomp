// ms2renderlistprocessor.h - MS2RenderListProcessor: the game's NiShaderSortProcessor subclass (0xe8 bytes; vftable
// 0x142f22e78: ??_G 0x1414e5d30, DeleteThis, GetRTTI 0x1414e6700, PreRenderProcessList 0x1414dc0d0,
// PostRenderProcessList 0x141d28230, ReleaseCaches). Base of MS2OverdrawProcessor, MS2MaterialSwapProcessor,
// MS2OuterGlowMaterialSwapProcessor, MS2AfterImageRenderListProcessor and MS2RenderViewRenderListProcessor.
// Owning unit: ?\ms2renderlistprocessor.cpp (0x1414dbf30-0x1414ea3d0). The NiImplementRTTI of the class lives in an
// optimised TU (its NiRTTI initialiser is 0x140122680), so only the declaration is here. Member and helper names are
// invented (the exe only has the class names).
#pragma once
#include "ms2/ms2layout.h"
#include "ms2/client/ms2/alphacomponent.h"
#include <NiShaderSortProcessor.h>
#include <NiTPointerMap.h>
#include <NiMaterial.h>
#include <NiRenderObject.h>
#include <NiPropertyState.h>
#include <NiAlphaProperty.h>
#include <efd/StdContainers.h>

class NiRenderer;
class NiRenderObject;
class NiAVObject;

// Saved active material of every object whose material was swapped for the frame.
typedef NiTPointerMap<NiRenderObject*, const NiMaterial*> MS2SavedMaterialMap;
// Alpha shell groups keyed by the object's shell-group integer extra data.
typedef efd::map<int, AlphaShellComposite> MS2AlphaShellMap;
// Render groups keyed by the object's float extra data (unused debug path).
typedef efd::map<float, efd::vector<NiRenderObject*>*> MS2RenderGroupMap;

class MS2RenderListProcessor : public NiShaderSortProcessor
{
    NiDeclareRTTI;

public:
    MS2RenderListProcessor();                               // 0x1414dbf30
    virtual ~MS2RenderListProcessor();                      // 0x1414dc020, ??_G 0x1414e5d30
    virtual void PreRenderProcessList(const NiVisibleArray* pkInput, NiVisibleArray& kOutput, void* pvExtraData);   // 0x1414dc0d0

    // Renders the outlined objects twice: once with their outline material (stencil DRAW_CW), once normally.
    void RenderOutlines(NiVisibleArray& kList, NiRenderer* pkRenderer);                 // 0x1414dce40
    // Debug path: renders the objects grouped by a float extra data in two blend passes (no caller in the exe).
    void RenderGroups(const NiVisibleArray* pkInput);                                     // 0x1414dd110
    // Applies the post-processing material of the object's scene root (or the colour-shift extra data).
    void ApplyEffectMaterial(NiRenderObject* pkObject, MS2SavedMaterialMap& kSaved);      // 0x1414dd570
    void RestoreMaterials(MS2SavedMaterialMap& kSaved);                                   // 0x1414dd840
    void SaveMaterial(MS2SavedMaterialMap& kSaved, NiRenderObject* pkObject);             // 0x1414dd8c0
    void CompleteModifiers(NiAVObject* pkObject);                                         // 0x1414dd920 (no caller)
    void DisableOutlineColor();                                                           // 0x1414dd9b0
    float ComputeDepth(const NiRenderObject& kGeometry, const NiPoint3& kDir);            // 0x1414dd9d0
    void RenderNoSortList(NiRenderer* pkRenderer);                                        // 0x1414dda60
    void RenderAlphaList(unsigned int uiCount, MS2AlphaShellMap& kShells, NiPoint3 kDir); // 0x1414ddaf0

    // The game's build of NiAlphaSortProcessor::IsTransparent (0x1414e67e0): alpha blending only, NULL-safe, no
    // no-sorter / sort-object checks.
    bool IsTransparent(const NiRenderObject& kObject)
    {
        const NiPropertyState* pkPropState = kObject.GetPropertyState();
        if (pkPropState)
        {
            const NiAlphaProperty* pkAlphaProp = pkPropState->GetAlpha();
            if (pkAlphaProp)
                return pkAlphaProp->GetAlphaBlending();
        }
        return false;
    }

protected:
    AlphaComponent** m_ppkSortedAlpha;                      // +0xb0 NiAlloc'd, m_uiAllocatedAlpha entries
    AlphaObject* m_pkAlphaObjects;                          // +0xb8 NiNew[] m_uiAllocatedAlpha
    std::list<AlphaObject> m_kExtraAlphaObjects;             // +0xc0 alpha objects with an explicit sort mode
    unsigned int m_uiAllocatedAlpha;                        // +0xd0
    NiMaterialPtr m_spMaterial;                             // +0xd8
    bool m_bOutlineColor;                                   // +0xe0
};
MS2_CHECK_SIZE(MS2RenderListProcessor, 0xe8);

// Render-list processor of the UI render views (ctor 0x141ab8300 / dtor 0x141ab83a0 in ?\uirenderview.cpp).
class MS2RenderViewRenderListProcessor : public MS2RenderListProcessor
{
    // no RTTI of its own: vftable slot 2 is MS2RenderListProcessor::GetRTTI (0x1414e6700)
public:
    MS2RenderViewRenderListProcessor();                     // 0x141ab8300
    virtual ~MS2RenderViewRenderListProcessor();            // 0x141ab83a0
    virtual void PreRenderProcessList(const NiVisibleArray* pkInput, NiVisibleArray& kOutput, void* pvExtraData);   // 0x1414ddce0
};
MS2_CHECK_SIZE(MS2RenderViewRenderListProcessor, 0xe8);

// MS2AfterImageRenderListProcessor is declared in ms2afterimagerenderlistprocessor.h (afterimageitem.h has its own copy).
