// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Overdraw-visualisation render-list processor.
// MS2-UNIT: ?\ms2overdrawprocessor.cpp
// MS2-RANGE: 0x1414d4e20-0x1414d6c20 .text$mn
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2overdrawprocessor.h"
#include "hook/ms2hook.h"
#include <vector>
#include <NiRenderObject.h>
#include <NiAVObject.h>
#include <NiRenderer.h>

struct Unk_Colc { float x, y, z; Unk_Colc(float x, float y, float z); };   // ctor 0x140a56db0

// ---- out-of-unit callees ----
class NiMaterialLibrary   // C3: member view for the former free stand-ins
{
public:
    static class NiMaterial* CreateMaterial(class NiFixedString const&);
};
void FUN_1410479a0(class NiObjectNET*, class NiFixedString const&, class NiColor const&);   // C3: was FUN_1410479a0
NiRenderer* GetNiRenderer();                                 // the active renderer
extern char DAT_143ae5210, DAT_143ae50f0;

// The per-object state saved while the overdraw material/properties are applied: the object, its active material
// and its z-buffer / alpha properties (detached while the processor's own are attached).
struct Unk_OverdrawState
{
    NiAVObject* m_pObj;
    const NiMaterial* m_pMaterial;
    NiPropertyPtr m_spZBuffer;
    NiPropertyPtr m_spAlpha;

    // @0x1414d5290
    explicit Unk_OverdrawState(NiRenderObject* obj)
    {
        m_pObj = obj;
        m_pMaterial = obj->GetActiveMaterial();
        m_spZBuffer = obj->GetProperty(NiProperty::ZBUFFER);
        m_spAlpha = obj->GetProperty(NiProperty::ALPHA);
        if (m_spZBuffer)
            m_pObj->DetachProperty(m_spZBuffer);
        if (m_spAlpha)
            m_pObj->DetachProperty(m_spAlpha);
    }

    // @0x1414d53b0
    void Restore()
    {
        static_cast<NiRenderObject*>(m_pObj)->SetActiveMaterial(m_pMaterial);
        m_pObj->DetachProperty(m_pObj->GetProperty(NiProperty::ZBUFFER));
        m_pObj->DetachProperty(m_pObj->GetProperty(NiProperty::ALPHA));
        if (m_spZBuffer)
            m_pObj->AttachProperty(m_spZBuffer);
        if (m_spAlpha)
            m_pObj->AttachProperty(m_spAlpha);
        m_pObj->UpdateProperties();
    }
};

// @0x1414d4e20
MS2OverdrawProcessor::MS2OverdrawProcessor()
{
    m_spOverdrawMaterial = NiMaterialLibrary::CreateMaterial(*(class NiFixedString const*)(&DAT_143ae5210));

    m_spZBuffer = NiNew NiZBufferProperty;
    m_spZBuffer->SetZBufferTest(false);
    m_spZBuffer->SetZBufferWrite(false);

    m_spAlpha = NiNew NiAlphaProperty;
    m_spAlpha->SetAlphaBlending(true);
    m_spAlpha->SetAlphaTesting(false);
    m_spAlpha->SetDestBlendMode((NiAlphaProperty::AlphaFunction)0);
    m_spAlpha->SetSrcBlendMode((NiAlphaProperty::AlphaFunction)0);
}

// @0x1414d5070
void MS2OverdrawProcessor::PreRenderProcessList(const NiVisibleArray* pkInput, NiVisibleArray& kOutput, void* pvExtraData)
{
    if (pkInput == NULL)
        return;

    unsigned count = ((class NiVisibleArray*)(class NiVisibleArray const*)(pkInput))->GetCount();
    std::vector<Unk_OverdrawState> saved;
    for (unsigned i = 0; i < count; ++i) {
        NiRenderObject* obj = ((class NiRenderObject*)&((class NiVisibleArray*)(class NiVisibleArray const*)(pkInput))->GetAt(i));
        Unk_OverdrawState state(obj);
        saved.push_back(state);
        FUN_1410479a0((class NiObjectNET*)(obj), *(class NiFixedString const*)(&DAT_143ae50f0), reinterpret_cast<const NiColor&>(static_cast<const Unk_Colc&>(Unk_Colc(0.003921569f, 0.0f, 0.0f))));
        obj->PurgeRendererData(GetNiRenderer());
        obj->ApplyAndSetActiveMaterial(m_spOverdrawMaterial, 0xffffffff);
        obj->AttachProperty(m_spZBuffer);
        obj->AttachProperty(m_spAlpha);
        obj->UpdateProperties();
    }

    MS2RenderListProcessor::PreRenderProcessList(pkInput, kOutput, pvExtraData);

    for (std::vector<Unk_OverdrawState>::iterator it = saved.begin(); it != saved.end(); ++it)
        it->Restore();
}

MS2_REPLACE_METHOD(0x1414d5070, MS2OverdrawProcessor, PreRenderProcessList, 525, 0xAE0D4DE1);

// @0x1414d6400
const NiRTTI* MS2OverdrawProcessor::GetRTTI() const { return &ms_RTTI; }
