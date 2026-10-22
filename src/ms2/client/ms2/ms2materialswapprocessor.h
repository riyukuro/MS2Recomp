// ms2materialswapprocessor.h - MS2MaterialSwapProcessor: render-list processor (0x108 bytes) that temporarily swaps an
// override material onto every visible object accepted by a predicate, renders the list, then restores the originals.
// Owning unit: ?\ms2materialswapprocessor.cpp (0x1414cf940-0x1414d2460, dir client\ms2). Field names inferred.
#pragma once
#include "ms2/ms2layout.h"
#include "ms2/client/ms2/ms2renderlistprocessor.h"
#include <NiMaterial.h>
#include <NiSmartPointer.h>
#include <NiRefObject.h>
#include <NiTPointerMap.h>
#include <vector>

class NiRenderObject;

// Decides whether a swapper applies to an object (returns non-zero to accept it).
typedef int (*MaterialSwapPredicate)(NiRenderObject* pObj);

// One override rule: a material, an optional predicate and an enable flag.
class MaterialSwapper : public NiRefObject
{
public:
    MaterialSwapper(MaterialSwapPredicate pfnPredicate, NiMaterial* pMaterial);     // 0x1414cf9b0
    virtual ~MaterialSwapper();                             // 0x1414d14e0, ??_G 0x1414d1780

    bool FUN_1414cf940() const { return m_bEnabled; }       // enabled
    MaterialSwapPredicate FUN_1414cf960() const { return m_pfnPredicate; }
    NiMaterial* FUN_1414cf980() { return m_spMaterial; }

public:
    MaterialSwapPredicate m_pfnPredicate;                   // +0x10
    NiPointer<NiMaterial> m_spMaterial;                     // +0x18
    bool m_bEnabled;                                        // +0x20
};
MS2_CHECK_SIZE(MaterialSwapper, 0x28);
MS2_CHECK_OFFSET(MaterialSwapper, m_pfnPredicate, 0x10);
MS2_CHECK_OFFSET(MaterialSwapper, m_bEnabled, 0x20);

typedef NiTPointerMap<NiRenderObject*, const NiMaterial*> MaterialSwapSavedMap;

class MS2MaterialSwapProcessor : public MS2RenderListProcessor
{
public:
    static const NiRTTI ms_RTTI;                            // 0x143ae0ac8
    virtual const NiRTTI* GetRTTI() const;                  // 0x1414d19a0

public:
    MS2MaterialSwapProcessor(NiMaterial* pMaterial, MaterialSwapPredicate pfnPredicate);   // 0x1414cfa40
    explicit MS2MaterialSwapProcessor(const std::vector<NiPointer<MaterialSwapper> >& swappers);   // 0x1414cfb40
    virtual ~MS2MaterialSwapProcessor();                    // 0x1414d14b0, ??_G 0x1414d1720
    virtual void PreRenderProcessList(const NiVisibleArray* pkInput, NiVisibleArray& kOutput, void* pvExtraData);   // 0x1414cfc00

    void SetUseMS2List(int bUseMS2List);                    // set the use-MS2-list flag
    std::vector<NiPointer<MaterialSwapper> >& FUN_1414cfbe0();   // the swapper list
    void FUN_1414cfce0(const NiVisibleArray* pkInput, NiVisibleArray& kList, MaterialSwapSavedMap& kSaved);   // apply
    void FUN_1414cfe70(MaterialSwapSavedMap& kSaved);                                                         // restore

public:
    std::vector<NiPointer<MaterialSwapper> > m_swappers;    // +0xe8
    int m_nUseMS2List;                                      // +0x100
};
MS2_CHECK_SIZE(MS2MaterialSwapProcessor, 0x108);
MS2_CHECK_OFFSET(MS2MaterialSwapProcessor, m_swappers, 0xe8);
MS2_CHECK_OFFSET(MS2MaterialSwapProcessor, m_nUseMS2List, 0x100);
