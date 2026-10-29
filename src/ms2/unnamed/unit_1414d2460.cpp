// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). MS2OuterGlowMaterialSwapProcessor::PreRenderProcessList and
// the std::map<NiNodePtr, int> lookup glue it instantiates.
// MS2-UNIT: unit_1414d2460
// MS2-RANGE: 0x1414d2460-0x1414d3120 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??C?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$SmartPointer@VNiNode@@@efd@@H@std@@@std@@@std@@@std@@QEBAPEAU?$pair@$$CBV?$SmartPointer@VNiNode@@@efd@@H@1@XZ 0x1414d2ba0 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\ms2renderlistprocessor.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <map>
#include "ms2/client/ms2/ms2outerglowmaterialswapprocessor.h"
#include "hook/ms2hook.h"
#include "ms2/ms2recover.h"
#include <NiRenderer.h>
#include <NiRenderObject.h>
#include <NiNode.h>
#include <NiVisibleArray.h>
#include <NiFloatExtraData.h>
#include <NiZBufferProperty.h>
#include <NiPropertyState.h>

// ---- out-of-unit callees (the same ones ?\ms2renderlistprocessor.cpp uses) ----
// The post-processing service: the mode of every scene root.
class Unk_OgPostProcessSvc
{
public:
    char m_pad0[0x68];
    std::map<NiNodePtr, int> m_kRootModes;                  // +0x68
};
Unk_OgPostProcessSvc* FUN_1409a8b20();
// A material-table entry; only its state word (+0x540) is read here.
struct Unk_OgMaterialTable;                                 // DAT_143d69198 (MS2StandardMaterial RTTI)
struct Unk_OgMaterialEntry
{
    char m_pad[0x540];
    unsigned m_nState;
    bool IsActive() const { return m_nState - 1 <= 2; }
};
extern Unk_OgMaterialTable DAT_143d69198;
Unk_OgMaterialEntry* FUN_140a17af0(Unk_OgMaterialTable* pTable, const NiMaterial* pMaterial);   // table lookup, NULL-safe
int FUN_140ef4dd0(Unk_OgMaterialEntry* pEntry);             // colour-shift mode refresh
extern const NiRTTI DAT_143afbfd0;
extern const NiRTTI DAT_143afa620;                          // NiFloatExtraData::ms_RTTI
extern NiFixedString DAT_143ae5130;                         // colour-shift float extra data
extern NiFixedString DAT_143ae5138;                         // colour-shift float extra data
NiObject* FUN_14098d8d0(const NiRTTI* pRTTI, NiObject* pObject);    // dynamic cast through an NiRTTI
NiNode* FUN_141d15010(NiAVObject* pkObject);                // topmost ancestor of the object

// @0x1414d2460
void MS2OuterGlowMaterialSwapProcessor::PreRenderProcessList(const NiVisibleArray* pkInput, NiVisibleArray& kOutput, void* pvExtraData)
{
    NiVisibleArray kRest;
    NiVisibleArray kGlow;
    unsigned int uiCount = pkInput->GetCount();
    NiRenderer* pkRenderer = NiRenderer::GetRenderer();
    for (unsigned int ui = 0; ui < uiCount; ui++)
    {
        NiRenderObject* pkObject = &pkInput->GetAt(ui);
        Unk_OgMaterialEntry* pkEntry = FUN_140a17af0(&DAT_143d69198, pkObject->GetActiveMaterial());
        if (pkEntry != 0 && pkEntry->IsActive())
        {
            kGlow.Add(*pkObject);
            continue;
        }
        if (FUN_14098d8d0(&DAT_143afbfd0, pkObject) != 0)
        {
            kRest.Add(*pkObject);
            continue;
        }
        Unk_OgMaterialEntry* pkEntry2 = FUN_140a17af0(&DAT_143d69198, pkObject->GetActiveMaterial());
        if (pkEntry2 != 0 && !pkEntry2->IsActive())
        {
            kRest.Add(*pkObject);
            continue;
        }
        std::map<NiNodePtr, int>::const_iterator it = FUN_1409a8b20()->m_kRootModes.find(FUN_141d15010(pkObject));
        if (it == FUN_1409a8b20()->m_kRootModes.end())
        {
            kRest.Add(*pkObject);
            continue;
        }
        int iMode = it->second;
        if (0 <= iMode && iMode < 7)
        {
            if (iMode == 4)
            {
                if (FUN_14098d8d0(&DAT_143afa620, pkObject->GetExtraData(DAT_143ae5130)) == 0)
                    pkObject->AddExtraData(DAT_143ae5130, NiNew NiFloatExtraData(0.3f));
                if (FUN_14098d8d0(&DAT_143afa620, pkObject->GetExtraData(DAT_143ae5138)) == 0)
                    pkObject->AddExtraData(DAT_143ae5138, NiNew NiFloatExtraData(0.7f));
                Unk_OgMaterialEntry* pkEntry3 = FUN_140a17af0(&DAT_143d69198, pkObject->GetActiveMaterial());
                if (pkEntry3 != 0 && FUN_140ef4dd0(pkEntry3) == 2)
                    iMode = 5;
            }
            kGlow.Add(*pkObject);
            continue;
        }
        kRest.Add(*pkObject);
    }
    MS2RenderListProcessor::PreRenderProcessList(&kRest, kOutput, pvExtraData);
    for (unsigned int uj = 0; uj < kGlow.GetCount(); uj++)
    {
        NiRenderObject* pkObject = &kGlow.GetAt(uj);
        const NiMaterial* pkOriginal = pkObject->GetActiveMaterial();
        NiPropertyState* pkState = pkObject->GetPropertyState();
        NiZBufferProperty* pkZBuffer = pkState->GetZBuffer();
        bool bZWrite = pkZBuffer->GetZBufferWrite();
        pkZBuffer->SetZBufferWrite(false);
        pkObject->ApplyAndSetActiveMaterial(m_spGlowMaterial);
        pkObject->RenderImmediate(pkRenderer);
        pkZBuffer->SetZBufferWrite(bZWrite);
        pkObject->SetActiveMaterial(pkOriginal);
        kOutput.Add(*pkObject);
    }
    kGlow.RemoveAll();
}
MS2_REPLACE_METHOD(0x1414D2460, MS2OuterGlowMaterialSwapProcessor, PreRenderProcessList, 1377, 0x94F35BB3);

// @0x1414d3000
MS2_EMIT_CRT_MEMMOVE_S();
