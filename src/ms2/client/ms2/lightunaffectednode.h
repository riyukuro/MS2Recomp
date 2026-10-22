// LightUnaffectedNode (RTTI name): an NiNode that registers itself with every dynamic light as unaffected.
#pragma once
#include "ms2/ms2layout.h"
#include "ms2/placeholder/ninode.h"

// Light-like effect (FUN_140afe6c0 yields them from the global list); names inferred (NiLight::AttachAffectedNode etc.).
class Unk_LUNLight {
public:
    void FUN_141175880(NiNode* node);
    void FUN_1411758d0(NiNode* node);
    void FUN_141175a10(NiNode* node);
    void FUN_141175a70(NiNode* node);
    void FUN_141176660(bool flag);
};
// Intrusive list of lights hanging off a global (FUN_140afe770 = DAT_143afa980 + 400).
struct Unk_LUNList;
Unk_LUNList* FUN_140afe770();
void* FUN_140afe720(Unk_LUNList* list);                         // head position
Unk_LUNLight** FUN_140afe730(Unk_LUNList* list, void** pos);    // advance, returns entry
Unk_LUNLight* FUN_140afe6c0(Unk_LUNLight** entry);              // entry -> light

// Stand-in for the unrecovered class of the second static (0x143adc950, constructed by 0x1401cd100).
class Unk_LUNHolder {
public:
    Unk_LUNHolder(void* p);
    void* m_p;
};

class LightUnaffectedNode : public NiNode {
public:
    LightUnaffectedNode(bool affectsLights, bool isTemplate);       // 0x14144e030
    virtual ~LightUnaffectedNode();                                 // 0x14144e110
    virtual const NiRTTI* GetRTTI() const;                          // slot 2, 0x14144e2d0
    virtual NiObject* CreateClone(NiCloningProcess& kCloning);   // slot 3, 0x14144df10
    virtual void UpdateEffectsDownward(NiDynamicEffectState* pkParentState);   // slot 31, 0x14144e210
    void CopyMembers(LightUnaffectedNode* pkDest, NiCloningProcess& kCloning);   // 0x14144dfd0
    bool IsTemplate();
    static const NiRTTI ms_RTTI;                                    // 0x143adc938

    bool m_bUpdateEffects;                                          // +0x130
    bool m_bTemplate;                                               // +0x131
};
MS2_CHECK_SIZE(LightUnaffectedNode, 0x138);
MS2_CHECK_OFFSET(LightUnaffectedNode, m_bUpdateEffects, 0x130);
errno_t FUN_14144e2e0(void* dst, rsize_t dstSize, const void* src, rsize_t srcSize);
