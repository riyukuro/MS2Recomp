// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The "Light" effect: param, keyframe and runtime effect.
// MS2-UNIT: ?\lighteffectparam.cpp
// MS2-RANGE: 0x1400f7290-0x1400f7340 .text$di
// MS2-RANGE: 0x1414494d0-0x14144b790 .text$mn
// w4s11-manual-pins-begin (identical-body SmartPointer COMDATs tplpin cannot tell apart)
// MS2-PIN: ??0?$SmartPointer@VLightEffectTransitionData@@@efd@@QEAA@PEAVLightEffectTransitionData@@@Z 0x14144b190
// MS2-PIN: ??1?$SmartPointer@VLightEffectTransitionData@@@efd@@QEAA@XZ 0x14144b270
// MS2-PIN: ??B?$SmartPointer@VLightEffectTransitionData@@@efd@@QEBAPEAVLightEffectTransitionData@@XZ 0x14144b390
// MS2-PIN: ??C?$SmartPointer@VLightEffectTransitionData@@@efd@@QEBAPEAVLightEffectTransitionData@@XZ 0x14144b3a0
// w4s11-manual-pins-end
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#ifndef NOMINMAX
#define NOMINMAX
#endif
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\lighteffectparam.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "lighteffectparam.h"
#include "entityworldmanager.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include <efd/MemoryDefines.h>
#include <efd/utf8string.h>
#include <egf/Entity.h>
#include <egf/EntityIDFactory.h>
#include <ecr/SceneGraphService.h>
#include <NiNode.h>
#include <NiAVObject.h>
#include <NiTransform.h>
#include <NiFixedString.h>
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- out-of-unit types and callees (bound to the exe by their FUN_<va> names / symbols) ----
// Game TinyXML element.
class Unk_140165cf0
{
public:
    Unk_140165cf0* FUN_140165cf0(const char* pszName);              // FirstChildElement(name)
    Unk_140165cf0* FUN_140168650(const char* pszName);              // NextSiblingElement(name)
};
const char* FUN_14086f4b0(Unk_140165cf0* pNode, const char* pszName);
int FUN_140873360(Unk_140165cf0* pNode, const char* pszName, float& fOut);
int FUN_1408730a0(Unk_140165cf0* pNode, const char* pszName, bool& bOut);
int FUN_1408733e0(Unk_140165cf0* pNode, const char* pszName, CString& strOut);
int FUN_140874670(Unk_140165cf0* pNode, const char* pszName, Unk_StreamPoint& kOut);
CString FUN_140188f50(const char* psz, int n);                      // null-safe CString
void FUN_140177e10(const CString& str, ATL::CAtlArray<unsigned int>& arr, const char* pszDelim);   // split to uints
void FUN_14185f0b0(TransitionData* pData, Unk_140165cf0* pNode, float* pfTime);    // type / duration / start time

Unk_LightUpdateBits* FUN_140314670(Unk_LightUpdateBits* pBits, unsigned nPos, bool bValue);    // set one bit
bool FUN_1411fe0e0(const Unk_LightUpdateBits* pBits);               // any bit set
bool FUN_140afc5a0(const Unk_LightUpdateBits* pBits);               // all bits set
bool FUN_14028d470(float a, float b);                               // nearly equal
class Unk_GameClock { public: double FUN_141473280(); };
Unk_GameClock* FUN_14086d260();

void* FUN_1409849b0(void* pHandle);                                 // handle -> node pointer
void* FUN_14098d8d0(const void* pRtti, void* pObj);                 // dynamic cast through an NiRTTI
void FUN_140a0b2a0(void* pNode);                                    // detach the node from its parent
void FUN_141d16040(void* pNode, float fTime, bool bUpdateControllers);    // NiAVObject::Update
const Unk_StreamPoint& FUN_140947900(void* pNode);                  // world translate
void FUN_1414737d0(Unk_Entity* pEntity);                            // remove the entity from the world
extern char DAT_143b059e8;                                          // service lookup cell
ecr::SceneGraphService* FUN_1410a68f0(char* pCell);

// The effect manager singleton (0x1403ed280): the effect root.
class Unk_1403ed280 { public: void* FUN_1411a6b10(); };
Unk_1403ed280* FUN_1403ed280();
EntityWorldManager* FUN_1409670f0();

// The world object behind an entity (slot 7: class id).
class Unk_LightWorldObj
{
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual int GetClassId();
};
class Unk_LightWorld { public: Unk_LightWorldObj* FUN_141bd0f50(egf::Entity* pEntity); };
Unk_LightWorld* FUN_1403ed2d0();

// The effect target (CEffect::vfunc_3's second argument), the part this unit reads.
struct Unk_LightTarget
{
    char m_pad_00[0x10];
    void* m_hNode;                  // +0x10 handle of the owner's scene node
    const NiTransform* m_pPreData;  // +0x18 transform before the animation (usePreDataTransform)
};
MS2_CHECK_OFFSET(Unk_LightTarget, m_pPreData, 0x18);

// The entity: property setters by hash.
class Unk_Entity
{
public:
    void FUN_14098c6e0(unsigned nProp, const bool* pValue);
    void FUN_1409457c0(unsigned nProp, const float* pValue);
    void FUN_140b27f00(unsigned nProp, const Unk_LightColor& rValue);
    void FUN_140a38a50(unsigned nProp, const Unk_StreamPoint& rValue);
};

// Scene nodes of the effect system. EffectNode (400 bytes) carries the effect-space point; SeparateNode (0x138) follows
// only the selected parts of its parent's transform.
class Unk_EffectNode : public NiNode
{
public:
    Unk_EffectNode(int nA, int nB);                                 // 0x1411a34b0
    void FUN_1411a4040(const Unk_StreamPoint& rPoint);
    char m_pad_node[400 - sizeof(NiNode)];
};
MS2_CHECK_SIZE(Unk_EffectNode, 400);
class Unk_SeparateNode : public NiNode
{
public:
    explicit Unk_SeparateNode(unsigned char nFlags);                // 0x141751470
    char m_pad_node[0x138 - sizeof(NiNode)];
};
MS2_CHECK_SIZE(Unk_SeparateNode, 0x138);

#ifndef MS2_HOOK_DLL
// File statics of this TU (initialised by the .text$di entries).
const NiRTTI CLightEffect::ms_RTTI("CLightEffect", &TransitionEffect::ms_RTTI);     // @0x1400f7290
static CString s_str143adc8f8("skill");                                              // @0x1400f72c0
static CString s_str143adc8f0("stun");                                               // @0x1400f72f0
class Unk_Handle1401cd100 { public: Unk_Handle1401cd100(int nNull); void* m_p; };     // ctor 0x1401cd100
static Unk_Handle1401cd100 s_dat_143adc8e8(0);                                       // @0x1400f7320
#else
const NiRTTI CLightEffect::ms_RTTI("CLightEffect", &TransitionEffect::ms_RTTI);
#endif

// "r,g,b" (0..255) attribute -> colour, white when it does not have three components.
static Unk_LightColor ParseColor(Unk_140165cf0* pNode, const char* pszName)
{
    CString str = FUN_140188f50(FUN_14086f4b0(pNode, pszName), 0);
    ATL::CAtlArray<unsigned int> arr;
    FUN_140177e10(str, arr, ",");
    if (arr.GetCount() < 3)
        return Unk_LightColor(1.0f, 1.0f, 1.0f);
    float fB = (float)arr[2] / 255.0f;
    float fG = (float)arr[1] / 255.0f;
    return Unk_LightColor((float)arr[0] / 255.0f, fG, fB);
}

// @0x14144b240
Unk_BitRef::Unk_BitRef(Unk_LightUpdateBits* pBits, unsigned nPos)
    : m_pBits(pBits), m_nPos(nPos)
{
}

// @0x14144b2f0
Unk_BitRef& Unk_BitRef::operator=(bool bValue)
{
    FUN_140314670(m_pBits, m_nPos, bValue);
    return *this;
}

// @0x14144b330
Unk_BitRef Unk_LightUpdateBits::operator[](unsigned nPos)
{
    (void)((!!(nPos < 3)) || (_wassert(L"UINT(pos) < UINT(T)", L"e:\\build\\kr\\22_04\\ms2code\\commonfiles\\bitset.inl", 0x98), 0));
    return Unk_BitRef(this, nPos);
}

// @0x14144b630
static bool FUN_14144b630(const Unk_LightUpdateBits* pBits)
{
    return !FUN_1411fe0e0(pBits);
}

// @0x14144b3f0
Unk_LightColor Unk_LightColor::operator-(const Unk_LightColor& o) const
{
    Unk_LightColor t = *this;
    t.r -= o.r;
    t.g -= o.g;
    t.b -= o.b;
    return t;
}

// @0x14144b480
Unk_LightColor Unk_LightColor::operator+(const Unk_LightColor& o) const
{
    Unk_LightColor t = *this;
    t.r += o.r;
    t.g += o.g;
    t.b += o.b;
    return t;
}

// @0x14144b1d0
LightEffectTransitionData::LightEffectTransitionData()
    : m_clrDiffuse(0.0f, 0.0f, 0.0f), m_clrSpecular(0.0f, 0.0f, 0.0f)
{
}

// @0x1414494d0
CLightEffectParam::CLightEffectParam()
    : TransitionEffectParam(9), m_strParentNode(""), m_ptTranslate(0.0f, 0.0f, 0.0f), m_clrDiffuse(0.0f, 0.0f, 0.0f),
      m_clrSpecular(0.0f, 0.0f, 0.0f), m_fDimmer(1.0f),
      m_fRange(1000.0f), m_fAttConstant(1.0f), m_fAttLinear(0.0f), m_fAttQuadratic(0.0f), m_bUsePreDataTransform(false)
{
}

// @0x141449600
// MS2-FUNCTIONAL: not byte-matched (colour temporaries, inlined bitset proxies)
void CLightEffectParam::vfunc_1(Unk_140165cf0* pNode)
{
    CEffectParam::vfunc_1(pNode);
    Unk_140165cf0* pTransform = pNode->FUN_140165cf0("transform");
    if (pTransform != 0)
        FUN_140874670(pTransform, "translate", m_ptTranslate);
    Unk_140165cf0* pAttach = pNode->FUN_140165cf0("attachInfo");
    if (pAttach != 0)
        FUN_1408733e0(pAttach, "parentNode", m_strParentNode);

    bool bTranslate = false, bRotation = false, bScale = false;
    Unk_140165cf0* pUpdate = pNode->FUN_140165cf0("update");
    if (pUpdate != 0)
    {
        FUN_1408730a0(pUpdate, "translate", bTranslate);
        FUN_1408730a0(pUpdate, "rotation", bRotation);
        FUN_1408730a0(pUpdate, "scale", bScale);
    }
    if (bTranslate)
        m_update[0] = true;
    if (bRotation)
        m_update[1] = true;
    if (bScale)
        m_update[2] = true;

    Unk_140165cf0* pLight = pNode->FUN_140165cf0("light");
    if (pLight != 0)
    {
        m_clrDiffuse = ParseColor(pLight, "diffuse");
        m_clrSpecular = ParseColor(pLight, "specular");
        FUN_140873360(pLight, "dimmer", m_fDimmer);
        FUN_140873360(pLight, "range", m_fRange);
        FUN_1408730a0(pLight, "usePreDataTransform", m_bUsePreDataTransform);
    }
    Unk_140165cf0* pAtt = pNode->FUN_140165cf0("attenuation");
    if (pAtt != 0)
    {
        FUN_140873360(pAtt, "constant", m_fAttConstant);
        FUN_140873360(pAtt, "linear", m_fAttLinear);
        FUN_140873360(pAtt, "quadratic", m_fAttQuadratic);
    }

    float fTime = m_fStartDelay;
    for (Unk_140165cf0* pKey = pNode->FUN_140165cf0("transition"); pKey != 0; pKey = pKey->FUN_140168650("transition"))
    {
        NiPointer<LightEffectTransitionData> spData(new (efd::MemHint(efd::MemHint::NONE)) LightEffectTransitionData);
        FUN_14185f0b0(spData.operator->(), pKey, &fTime);
        spData->m_clrDiffuse = ParseColor(pKey, "diffuse");
        spData->m_clrSpecular = ParseColor(pKey, "specular");
        FUN_140873360(pKey, "dimmer", spData->m_fDimmer);
        FUN_140873360(pKey, "range", spData->m_fRange);
        CString strLoop = FUN_140188f50(FUN_14086f4b0(pKey, "loop"), 0);
        if (strLoop.CompareNoCase("true") == 0 && m_nLoopIndex == -1)
            m_nLoopIndex = (int)m_arrData.GetCount();
        m_arrData.Add(NiPointer<TransitionData>(spData));
    }
}

// @0x14144a0f0
// Not hooked: constructs CLightEffect with its (DLL) constructor and vftable.
CEffectPtr CLightEffectParam::vfunc_6()
{
    return new (efd::MemHint(efd::MemHint::NONE)) CLightEffect;
}

// @0x14144a190
CLightEffect::CLightEffect()
    : m_spParent(0), m_spOuter(0), m_spLightNode(0), m_entity(0), m_fDimmer(0.0f)
{
}

// @0x14144a240
CLightEffect::~CLightEffect()
{
    CLightEffect::vfunc_7();
}

// @0x14144a2d0
// MS2-FUNCTIONAL: not byte-matched (scene node and property temporaries)
// Not hooked: constructs CLightEffect-owned nodes with this unit's helpers.
bool CLightEffect::vfunc_3(const CEffectParam* pParam, Unk_EffectTarget* pTarget)
{
    if (!TransitionEffect::vfunc_3(pParam, pTarget))
        return false;
    const CLightEffectParam* pLightParam = static_cast<const CLightEffectParam*>(pParam);
    const Unk_LightTarget* pTgt = reinterpret_cast<const Unk_LightTarget*>(pTarget);

    NiAVObject* pShadow = static_cast<NiAVObject*>(FUN_14098d8d0(&NiNode::ms_RTTI, FUN_1409849b0(const_cast<void**>(&pTgt->m_hNode))));
    if (!(m_unk_18 >= 0 && (m_unk_18 < 2 || m_unk_18 == 6)))
        return false;

    if (pShadow != 0)
    {
        efd::SmartPointer<ecr::SceneGraphService> spService(FUN_1410a68f0(&DAT_143b059e8));
        egf::Entity* pOwner = spService->GetEntityFromSceneGraphNode(pShadow);
        if (pOwner != 0)
        {
            Unk_LightWorldObj* pObj = FUN_1403ed2d0()->FUN_141bd0f50(pOwner);
            if (pObj != 0 && pObj->GetClassId() == 0x6200044)
                return false;
        }
    }

    m_ptTranslate = pLightParam->m_ptTranslate;
    m_fDimmer = pLightParam->m_fDimmer;

    Unk_EffectNode* spNode = new (efd::MemHint(efd::MemHint::NONE)) Unk_EffectNode(1, 0);
    Unk_NodePtr kNodeRef(spNode);
    spNode->SetName("Light Effect Root");
    FUN_1409f76f0(&m_spOuter, spNode);
    FUN_1409f76f0(&m_spLightNode, spNode);

    if (!pLightParam->m_bUsePreDataTransform || pTgt->m_pPreData == 0)
    {
        spNode->FUN_1411a4040(m_ptTranslate);
    }
    else
    {
        NiTransform kXform = *pTgt->m_pPreData;
        kXform.m_Translate.x += m_ptTranslate.x;
        kXform.m_Translate.y += m_ptTranslate.y;
        kXform.m_Translate.z += m_ptTranslate.z;
        spNode->SetLocalTransform(kXform);
    }

    if (pShadow == 0)
    {
        FUN_1409f76f0(&m_spParent, FUN_1403ed280()->FUN_1411a6b10());
    }
    else
    {
        NiAVObject* pFound = pShadow->GetObjectByName(NiFixedString(pLightParam->m_strParentNode));
        FUN_1409f76f0(&m_spParent, FUN_14098d8d0(&NiNode::ms_RTTI, pFound));
        if (m_spParent.FUN_1409f77a0(0))
            FUN_1409f76f0(&m_spParent, pShadow);
        if (!FUN_140afc5a0(&pLightParam->m_update) && !FUN_14144b630(&pLightParam->m_update))
        {
            Unk_SeparateNode* spSep = new (efd::MemHint(efd::MemHint::NONE)) Unk_SeparateNode(pLightParam->m_update.m_bits);
            Unk_NodePtr kSepRef(spSep);
            spSep->AttachChild(static_cast<NiAVObject*>(FUN_1409475d0(&m_spOuter)), false);
            FUN_1409f76f0(&m_spOuter, spSep);
        }
    }

    NiAVObject* pParent = static_cast<NiAVObject*>(FUN_1409475f0(&m_spParent));
    NiAVObject* pLight = static_cast<NiAVObject*>(FUN_1409475f0(&m_spLightNode));
    NiTransform kWorld = pParent->GetWorldTransform() * pLight->GetLocalTransform();

    egf::EntityID id = egf::EntityIDFactory::GetNextID();
    efd::utf8string strModel("EffectPointLight");
    egf::EntityPtr spEntity = FUN_1409670f0()->FUN_1411cec80(strModel, id, true);
    m_entity.FUN_1408b6ec0(reinterpret_cast<Unk_Entity*>(static_cast<egf::Entity*>(spEntity)));
    if (m_entity.FUN_1408b70b0(0))
        return false;

    Unk_Entity* pEntity = m_entity.FUN_1408a9280();
    bool bFalse = false, bTrue = true;
    float fFifty = 50.0f;
    pEntity->FUN_14098c6e0(0x2a7fd9f4, &bFalse);
    pEntity->FUN_1409457c0(0x9109875b, &fFifty);
    pEntity->FUN_14098c6e0(0xef627d53, &bTrue);
    pEntity->FUN_14098c6e0(0x78e546ab, &bFalse);
    pEntity->FUN_140b27f00(0x2d8cf386, pLightParam->m_clrDiffuse);
    pEntity->FUN_140b27f00(0xc3f0329e, pLightParam->m_clrSpecular);
    pEntity->FUN_1409457c0(0x18f5d90e, &pLightParam->m_fDimmer);
    pEntity->FUN_1409457c0(0x4871503b, &pLightParam->m_fRange);
    pEntity->FUN_1409457c0(0x4dcec447, &pLightParam->m_fAttConstant);
    pEntity->FUN_1409457c0(0x8cd1ae89, &pLightParam->m_fAttLinear);
    pEntity->FUN_1409457c0(0x9f7d1fa7, &pLightParam->m_fAttQuadratic);
    Unk_StreamPoint ptWorld(kWorld.m_Translate.x, kWorld.m_Translate.y, kWorld.m_Translate.z);
    pEntity->FUN_140a38a50(0xfd95ca52, ptWorld);
    FUN_1409670f0()->FUN_1411cf2d0(reinterpret_cast<egf::Entity*>(m_entity.FUN_1408a9090()), 0);
    if (FUN_14028d470(pLightParam->m_fStartDelay, 0.0f))
        vfunc_4();
    return true;
}

// @0x14144acc0
bool CLightEffect::vfunc_9()
{
    if (TransitionEffect::vfunc_9())
    {
        FUN_14144b0d0();
        return true;
    }
    return false;
}
MS2_REPLACE_METHOD(0x14144ACC0, CLightEffect, vfunc_9, 47, 0xF589CDE5);

// @0x14144ad00
void CLightEffect::vfunc_4()
{
    if ((bool)FUN_1409475d0(&m_spParent) && !m_b2e)
    {
        NiNode* pParent = static_cast<NiNode*>(FUN_1409475f0(&m_spParent));
        pParent->AttachChild(static_cast<NiAVObject*>(FUN_1409475d0(&m_spOuter)), true);
        FUN_141d16040(FUN_1409475f0(&m_spOuter), (float)FUN_14086d260()->FUN_141473280(), true);
    }
    m_b2e = true;
}
MS2_REPLACE_METHOD(0x14144AD00, CLightEffect, vfunc_4, 221, 0xFE4D83F7);

// @0x14144adf0
void CLightEffect::vfunc_7()
{
    FUN_140a0b2a0(FUN_1409475d0(&m_spOuter));
    if (m_entity.FUN_1408a9090() != 0)
    {
        FUN_1414737d0(m_entity.FUN_1408a9090());
        m_entity.FUN_1408b6ec0(0);
    }
}
MS2_REPLACE_METHOD(0x14144ADF0, CLightEffect, vfunc_7, 105, 0xFE245DC8);

// @0x14144b0d0
void CLightEffect::FUN_14144b0d0()
{
    if ((bool)m_entity.FUN_1408a9090() && (bool)FUN_1409475d0(&m_spLightNode))
    {
        Unk_StreamPoint pt = FUN_140947900(FUN_1409475f0(&m_spLightNode));
        m_entity.FUN_1408a9280()->FUN_140a38a50(0xfd95ca52, pt);
    }
}
MS2_REPLACE_METHOD(0x14144B0D0, CLightEffect, FUN_14144b0d0, 182, 0x87513DBB);

// @0x14144ae60
void CLightEffect::vfunc_13(TransitionData* pFromBase, TransitionData* pToBase, float fT)
{
    LightEffectTransitionData* pFrom = static_cast<LightEffectTransitionData*>(pFromBase);
    LightEffectTransitionData* pTo = static_cast<LightEffectTransitionData*>(pToBase);
    m_entity.FUN_1408a9280()->FUN_140b27f00(0x2d8cf386, pFrom->m_clrDiffuse + fT * (pTo->m_clrDiffuse - pFrom->m_clrDiffuse));
    m_entity.FUN_1408a9280()->FUN_140b27f00(0xc3f0329e, pFrom->m_clrSpecular + fT * (pTo->m_clrSpecular - pFrom->m_clrSpecular));
    float fDimmer = pFrom->m_fDimmer + fT * (pTo->m_fDimmer - pFrom->m_fDimmer);
    m_entity.FUN_1408a9280()->FUN_1409457c0(0x18f5d90e, &fDimmer);
    float fRange = pFrom->m_fRange + fT * (pTo->m_fRange - pFrom->m_fRange);
    m_entity.FUN_1408a9280()->FUN_1409457c0(0x4871503b, &fRange);
}
MS2_REPLACE_METHOD(0x14144AE60, CLightEffect, vfunc_13, 495, 0x7A080091);

// @0x14144b060
void CLightEffect::vfunc_10(bool bVisible)
{
    float fDimmer = bVisible ? m_fDimmer : 0.0f;
    m_entity.FUN_1408a9280()->FUN_1409457c0(0x18f5d90e, &fDimmer);
}
MS2_REPLACE_METHOD(0x14144B060, CLightEffect, vfunc_10, 101, 0xB6B47526);

// @0x14144b610
int CLightEffect::vfunc_12()
{
    return 9;
}
MS2_REPLACE_METHOD(0x14144B610, CLightEffect, vfunc_12, 11, 0x653B09E8);
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cb2460-0x142cb24a0 .text$yd

// hk1 2026-10-20: hooks for the remaining recovered functions (work/hk1/report.md)
MS2_REPLACE(0x14144b630, FUN_14144b630, 54, 0x526C0295);

