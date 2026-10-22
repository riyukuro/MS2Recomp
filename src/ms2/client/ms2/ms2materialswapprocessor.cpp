// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Material-swapping render-list processor.
// MS2-UNIT: ?\ms2materialswapprocessor.cpp
// MS2-RANGE: 0x1414cf940-0x1414d2460 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?FUN_1414cf940@MaterialSwapper@@QEBA_NXZ 0x1414cf940 ; unique
// MS2-PIN: ?FUN_1414cf960@MaterialSwapper@@QEBAP6AHPEAVNiRenderObject@@@ZXZ 0x1414cf960 ; unique
// MS2-PIN: ?FUN_1414cf980@MaterialSwapper@@QEAAPEAVNiMaterial@@XZ 0x1414cf980 ; unique
// MS2-PIN: ??0?$SmartPointer@VMaterialSwapper@@@efd@@QEAA@PEAVMaterialSwapper@@@Z 0x1414d11f0
// MS2-PINS-END tplpin
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2materialswapprocessor.h"
#include "hook/ms2hook.h"
#include <NiRenderObject.h>
#include <NiAVObject.h>
#include <NiVisibleArray.h>
#include <NiRenderer.h>
#include <efd/FixedString.h>
#include <efd/MemHint.h>

// ---- out-of-unit callees ----
struct Unk_MaterialTable;                                                   // DAT_143d69198
// A material-table entry; only its state word (+0x540) is read here. Its exe accessor (0x1427542f0) lies in the
// statically linked runtime range that the hook DLL does not map, so it is expressed inline instead.
struct Unk_MaterialEntry
{
    char m_pad[0x540];
    unsigned m_nState;
    bool IsActive() const { return m_nState - 1 <= 2; }
};
extern Unk_MaterialTable DAT_143d69198;
extern int DAT_143ae2b34;
extern NiFixedString DAT_143ae51b0;                                         // extra-data key
extern bool DAT_143ae0ac0;
bool FUN_14098dfc0(NiAVObject* pObj);
bool FUN_141568c90(NiRenderObject* pObj);
int FUN_141568d50(NiAVObject* pObj);
bool FUN_141567260(NiAVObject* pObj);
void* FUN_141044450(NiProperty* pProp);
Unk_MaterialEntry* FUN_140a17af0(Unk_MaterialTable* pTable, const NiMaterial* pMaterial);   // table lookup, NULL-safe

// @0x1414cf9b0
MaterialSwapper::MaterialSwapper(MaterialSwapPredicate pfnPredicate, NiMaterial* pMaterial)
    : m_spMaterial((NiMaterial*)0)
{
    m_pfnPredicate = pfnPredicate;
    m_spMaterial = pMaterial;
    m_bEnabled = true;
}

// @0x1414cfa40
MS2MaterialSwapProcessor::MS2MaterialSwapProcessor(NiMaterial* pMaterial, MaterialSwapPredicate pfnPredicate)
{
    {
        NiPointer<MaterialSwapper> spSwapper(new (efd::MemHint(efd::MemHint::NONE)) MaterialSwapper(pfnPredicate, pMaterial));
        m_swappers.push_back(static_cast<NiPointer<MaterialSwapper>&&>(spSwapper));
    }
    m_nUseMS2List = 1;
}

// @0x1414cfb40
MS2MaterialSwapProcessor::MS2MaterialSwapProcessor(const std::vector<NiPointer<MaterialSwapper> >& swappers)
{
    m_swappers = swappers;
    m_nUseMS2List = 1;
}

// @0x1414cfbc0
void MS2MaterialSwapProcessor::SetUseMS2List(int bUseMS2List)
{
    m_nUseMS2List = bUseMS2List;
}

// @0x1414cfbe0
std::vector<NiPointer<MaterialSwapper> >& MS2MaterialSwapProcessor::FUN_1414cfbe0()
{
    return m_swappers;
}

// @0x1414cfc00
void MS2MaterialSwapProcessor::PreRenderProcessList(const NiVisibleArray* pkInput, NiVisibleArray& kOutput, void* pvExtraData)
{
    if (!pkInput)
        return;
    NiVisibleArray kList;
    MaterialSwapSavedMap kSaved(0x25);
    FUN_1414cfce0(pkInput, kList, kSaved);
    if (m_nUseMS2List)
        MS2RenderListProcessor::PreRenderProcessList(&kList, kOutput, pvExtraData);
    else
        NiShaderSortProcessor::PreRenderProcessList(&kList, kOutput, pvExtraData);
    FUN_1414cfe70(kSaved);
}

MS2_REPLACE_METHOD(0x1414CFC00, MS2MaterialSwapProcessor, PreRenderProcessList, 218, 0x484FF650);

// @0x1414cfce0
void MS2MaterialSwapProcessor::FUN_1414cfce0(const NiVisibleArray* pkInput, NiVisibleArray& kList, MaterialSwapSavedMap& kSaved)
{
    unsigned count = pkInput->GetCount();
    unsigned nSwappers = (unsigned)m_swappers.size();
    if (nSwappers > 0) {
        for (unsigned i = 0; i < count; ++i) {
            NiRenderObject* pObj = &pkInput->GetAt(i);
            if (!FUN_141568c90(pObj)) {
                for (unsigned j = 0; j < nSwappers; ++j) {
                    NiPointer<MaterialSwapper>& sp = m_swappers[j];
                    if (!sp->FUN_1414cf940())
                        continue;
                    if (sp->FUN_1414cf960() == 0 || sp->FUN_1414cf960()(pObj) != 0) {
                        const NiMaterial* pOriginal = pObj->GetActiveMaterial();
                        kSaved.SetAt(pObj, pOriginal);
                        pObj->ApplyAndSetActiveMaterial(sp->FUN_1414cf980(), 0xffffffff);
                        kList.Add(*pObj);
                        break;
                    }
                }
            }
        }
    }
}

// @0x1414cfe70
void MS2MaterialSwapProcessor::FUN_1414cfe70(MaterialSwapSavedMap& kSaved)
{
    if (m_swappers.size() > 0) {
        NiTMapIterator pos = kSaved.GetFirstPos();
        while (pos != 0) {
            NiRenderObject* pObj;
            const NiMaterial* pMaterial;
            kSaved.GetNext(pos, pObj, pMaterial);
            pObj->SetActiveMaterial(pMaterial);
        }
        kSaved.RemoveAll();
    }
}

// @0x1414cfef0
int FUN_1414cfef0(NiRenderObject* pObj)
{
    if (FUN_14098dfc0(pObj))
        return 0;
    if ((const char*)pObj->GetName() == 0)
        return 0;
    if (DAT_143ae2b34 != 0) {
        if (FUN_141568d50(pObj) != 0)
            return 0;
    } else {
        NiExtraData* pExtra = pObj->GetExtraData(DAT_143ae51b0);
        if (pExtra != 0)
            return 0;
    }
    const NiMaterial* pMaterial = pObj->GetActiveMaterial();
    Unk_MaterialEntry* pEntry = FUN_140a17af0(&DAT_143d69198, pMaterial);
    if (pEntry != 0 && pEntry->IsActive())
        return 0;
    return 1;
}

// @0x1414cffc0
int FUN_1414cffc0(NiRenderObject* pObj)
{
    if (FUN_14098dfc0(pObj))
        return 0;
    if (DAT_143ae0ac0 != 0) {
        NiProperty* pProp = pObj->GetProperty(NiProperty::TEXTURING);
        if (!(pProp != 0 && FUN_141044450(pProp) != 0))
            return 0;
    }
    if (FUN_141567260(pObj))
        return 0;
    return 1;
}

// @0x1414d0040
int FUN_1414d0040(NiRenderObject* pObj)
{
    if (FUN_14098dfc0(pObj))
        return 0;
    Unk_MaterialEntry* pEntry = FUN_140a17af0(&DAT_143d69198, pObj->GetActiveMaterial());
    if (pEntry != 0 && pEntry->IsActive())
        return 0;
    return 1;
}

// @0x1414d00b0
int FUN_1414d00b0(NiRenderObject* pObj)
{
    if (FUN_14098dfc0(pObj))
        return 0;
    Unk_MaterialEntry* pEntry = FUN_140a17af0(&DAT_143d69198, pObj->GetActiveMaterial());
    if (pEntry != 0 && pEntry->IsActive())
        return 1;
    return 0;
}

// @0x1414d0120
int FUN_1414d0120(NiRenderObject* pObj)
{
    NiExtraData* pData;
    {
        NiFixedString kKey("ICMED");
        pData = pObj->GetExtraData(kKey);
    }
    if (pData != 0)
        return 1;
    else
        return 0;
}

// @0x1414d0180
void FUN_1414d0180(bool bValue)
{
    DAT_143ae0ac0 = bValue;
}

// @0x1414d14b0
// MS2-FUNCTIONAL: the exe dtor does not store the class vftable before destroying members; cl always does here
MS2MaterialSwapProcessor::~MS2MaterialSwapProcessor()
{
}

// @0x1414d14e0
// MS2-FUNCTIONAL: the exe dtor does not store the class vftable before destroying members; cl always does here
MaterialSwapper::~MaterialSwapper()
{
}

// @0x1414d19a0
const NiRTTI* MS2MaterialSwapProcessor::GetRTTI() const { return &ms_RTTI; }
