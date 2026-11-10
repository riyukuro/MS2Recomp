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
#include "ms2/placeholder/cmainsystem.h"
#include "ms2/client/ms2/entityworldmanager.h"
#include "ms2/client/ms2/effectservice.h"
#include "ms2/client/ms2/worldservice.h"
#include <NiAVObject.h>
class Unk_XmlNode   // C3: member view for the former element stand-ins
{
public:
    class Unk_XmlNode* FirstChild(char const*);
    class Unk_XmlNode* NextSibling(char const*);
};

// ---- out-of-unit types and callees (bound to the exe by their FUN_<va> names / symbols) ----
// Game TinyXML element.
#include "ms2/placeholder/tixmlelement.h"   // C3 #12: was a local TiXml view





// C3 #12: was a local TiXml view




int XmlGetAttr(class TiXmlElement*, char const*, float&);   // C3: was FUN_140873360
int XmlGetAttr(class TiXmlElement*, char const*, bool&);   // C3: was FUN_1408730a0
int XmlGetAttr(class TiXmlElement*, char const*, CStringA&);   // C3: was FUN_1408733e0
int XmlGetAttr(class TiXmlElement*, char const*, efd::Point3&);   // C3: was FUN_140874670 (0x140874670, xmlattr's Point3 reader)
CString FUN_140188f50(const char* psz, int n);                      // null-safe CString
template <class C> void XmlSplit(const CString& str, C& out, const char* pszDelim);   // C3: was FUN_140177e10 (CAtlArray<unsigned>)
void ReadTransitionData(TransitionData* pData, TiXmlElement* pNode, float* pfTime);    // type / duration / start time

// C3: m_update is bitset.h's Unk_Bitset<3> (Set 0x140314670, any 0x1411fe0e0, all 0x140afc5a0)
//
//
//
//
//
//
//
//
//
//
//
bool IsNearlyEqual(float a, float b);                               // nearly equal

void DetachFromParent(class NiAVObject*);   // C3: was DetachFromParent
namespace egf { class ScriptContext; extern ScriptContext g_bapiContext; }
#define DAT_143b059e8 (*(char*)&egf::g_bapiContext)          // C3: was extern char DAT_143b059e8 (service lookup cell)
struct Unk_CcSvcCell;
#include "ms2/placeholder/scriptcontext.h"   // egf::ScriptContext g_bapiContext (was a local framework view)

// The effect manager singleton (0x1403ed280): the effect root.

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

// The effect target (CEffect::vfunc_3's second argument), the part this unit reads.
struct Unk_LightTarget
{
    char m_pad_00[0x10];
    void* m_hNode;                  // +0x10 handle of the owner's scene node
    const NiTransform* m_pPreData;  // +0x18 transform before the animation (usePreDataTransform)
};
MS2_CHECK_OFFSET(Unk_LightTarget, m_pPreData, 0x18);

// The entity: property setters by hash.
void SetCachedBoolProperty(class Unk_CachedEntity*, unsigned int, bool const&);   // C3: was FUN_14098c6e0

class Unk_CachedEntity : public egf::Entity   // as propertycache.h declares it
{
public:
    template <class T> egf::PropertyResult SetPropertyValue(egf::PropertyID nProp, const T& value);   // 0x1409457c0 for float
};

void FUN_140b27f00(void*, unsigned int, void*);   // C3: the colour property setter's signature
class Unk_Entity
{
public:
};

#include "ms2/guess/separatenode.h"   // SeparateNode (was a local view)
//
//
//
//
//
//
//

#ifndef MS2_HOOK_DLL
// File statics of this TU (initialised by the .text$di entries).
const NiRTTI CLightEffect::ms_RTTI("CLightEffect", &TransitionEffect::ms_RTTI);     // @0x1400f7290
static CString s_str143adc8f8("skill");                                              // @0x1400f72c0
static CString s_str143adc8f0("stun");                                               // @0x1400f72f0
#include <egf/EntityID.h>   // B22: was class Unk_BuddyHandle (ctor 0x1401cd100 = egf::EntityID(efd::UInt64))
static egf::EntityID s_dat_143adc8e8(0);                                       // @0x1400f7320
#else
const NiRTTI CLightEffect::ms_RTTI("CLightEffect", &TransitionEffect::ms_RTTI);
#endif

// @0x14144b240
Unk_BitRef::Unk_BitRef(Unk_LightUpdateBits* pBits, unsigned nPos)
    : m_pBits(pBits), m_nPos(nPos)
{
}

// @0x14144b2f0
Unk_BitRef& Unk_BitRef::operator=(bool bValue)
{
    m_pBits->Set(m_nPos, bValue);
    return *this;
}

// @0x14144b330
template <int T> Unk_BitRef Unk_Bitset<T>::operator[](int pos)   // generic body; here only T = 3
{
    MS2_BITSET_ASSERT(152, UINT(pos) < UINT(T));
    return Unk_BitRef(this, pos);
}

// @0x14144b630
static bool FUN_14144b630(const Unk_LightUpdateBits* pBits)
{
    return !pBits->FUN_1411fe0e0();
}

// (0x14144b3f0 / 0x14144b480: efd::Color::operator- / operator+ from Color.inl, pinned at the end)
//
//
//
//
//
//
//
//

//
//
//
//
//
//
//
//
//

// @0x1414494d0
CLightEffectParam::CLightEffectParam()
    : TransitionEffectParam(9), m_strParentNode(""), m_ptTranslate(0.0f, 0.0f, 0.0f), m_clrDiffuse(0.0f, 0.0f, 0.0f),
      m_clrSpecular(0.0f, 0.0f, 0.0f), m_fDimmer(1.0f),
      m_fRange(1000.0f), m_fAttConstant(1.0f), m_fAttLinear(0.0f), m_fAttQuadratic(0.0f), m_bUsePreDataTransform(false)
{
}

// "r,g,b" (0..255) attribute -> colour, white when it does not have three components
// (written out at each use in the exe).
#define LIGHT_PARSE_COLOR(dst, pNode, pszName, str, arr)                                        \
    CString str = FUN_140188f50(((class TiXmlElement*)(class TiXmlElement*)(pNode))->Attribute(pszName), 0);                              \
    XmlSplit(str, arr, ",");                                                               \
    dst = arr.GetCount() < 3 ? efd::Color(1.0f, 1.0f, 1.0f)                                 \
        : efd::Color((float)arr[0] / 255.0f, (float)arr[1] / 255.0f, (float)arr[2] / 255.0f)

// @0x141449600
void CLightEffectParam::vfunc_1(TiXmlElement* pNode)
{
    CEffectParam::vfunc_1(pNode);
    TiXmlElement* pTransform = ((class TiXmlElement*)((class Unk_XmlNode*)(pNode))->FirstChild("transform"));
    if (pTransform != 0)
        XmlGetAttr((class TiXmlElement*)(pTransform), "translate", reinterpret_cast<efd::Point3&>(m_ptTranslate));
    TiXmlElement* pAttach = ((class TiXmlElement*)((class Unk_XmlNode*)(pNode))->FirstChild("attachInfo"));
    if (pAttach != 0)
        XmlGetAttr((class TiXmlElement*)(pAttach), "parentNode", m_strParentNode);

    bool bTranslate = false, bRotation = false, bScale = false;
    TiXmlElement* pUpdate = ((class TiXmlElement*)((class Unk_XmlNode*)(pNode))->FirstChild("update"));
    if (pUpdate != 0)
    {
        XmlGetAttr((class TiXmlElement*)(pUpdate), "translate", bTranslate);
        XmlGetAttr((class TiXmlElement*)(pUpdate), "rotation", bRotation);
        XmlGetAttr((class TiXmlElement*)(pUpdate), "scale", bScale);
    }
    if (bTranslate)
        m_update[0] = true;
    if (bRotation)
        m_update[1] = true;
    if (bScale)
        m_update[2] = true;

    TiXmlElement* pLight = ((class TiXmlElement*)((class Unk_XmlNode*)(pNode))->FirstChild("light"));
    if (pLight != 0)
    {
        ATL::CAtlArray<unsigned int> arrDiffuse;
        ATL::CAtlArray<unsigned int> arrSpecular;
        LIGHT_PARSE_COLOR(m_clrDiffuse, pLight, "diffuse", strDiffuse, arrDiffuse);
        LIGHT_PARSE_COLOR(m_clrSpecular, pLight, "specular", strSpecular, arrSpecular);
        XmlGetAttr((class TiXmlElement*)(pLight), "dimmer", m_fDimmer);
        XmlGetAttr((class TiXmlElement*)(pLight), "range", m_fRange);
        XmlGetAttr((class TiXmlElement*)(pLight), "usePreDataTransform", m_bUsePreDataTransform);
    }
    TiXmlElement* pAtt = ((class TiXmlElement*)((class Unk_XmlNode*)(pNode))->FirstChild("attenuation"));
    if (pAtt != 0)
    {
        XmlGetAttr((class TiXmlElement*)(pAtt), "constant", m_fAttConstant);
        XmlGetAttr((class TiXmlElement*)(pAtt), "linear", m_fAttLinear);
        XmlGetAttr((class TiXmlElement*)(pAtt), "quadratic", m_fAttQuadratic);
    }

    float fTime = m_fStartDelay;
    for (TiXmlElement* pKey = ((class TiXmlElement*)((class Unk_XmlNode*)(pNode))->FirstChild("transition")); pKey != 0; pKey = ((class TiXmlElement*)((class Unk_XmlNode*)(pKey))->NextSibling("transition")))
    {
        NiPointer<LightEffectTransitionData> spData(new (efd::MemHint(efd::MemHint::NONE)) LightEffectTransitionData());
        ReadTransitionData(spData.operator->(), pKey, &fTime);
        ATL::CAtlArray<unsigned int> arrDiffuse;
        ATL::CAtlArray<unsigned int> arrSpecular;
        LIGHT_PARSE_COLOR(spData->m_clrDiffuse, pKey, "diffuse", strDiffuse, arrDiffuse);
        LIGHT_PARSE_COLOR(spData->m_clrSpecular, pKey, "specular", strSpecular, arrSpecular);
        XmlGetAttr((class TiXmlElement*)(pKey), "dimmer", spData->m_fDimmer);
        XmlGetAttr((class TiXmlElement*)(pKey), "range", spData->m_fRange);
        CString strLoop = FUN_140188f50(((class TiXmlElement*)(class TiXmlElement*)(pKey))->Attribute("loop"), 0);
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
// Not hooked: constructs CLightEffect-owned nodes with this unit's helpers.
bool CLightEffect::vfunc_3(const CEffectParam* pParam, Unk_EffectTarget* pTarget)
{
    if (!TransitionEffect::vfunc_3(pParam, pTarget))
        return false;
    const CLightEffectParam* pLightParam = static_cast<const CLightEffectParam*>(pParam);
    bool bValid = false;

    NiNode* pShadow = static_cast<NiNode*>(((void*)NiObject::DynamicCast((class NiRTTI const*)(&NiNode::ms_RTTI), (class NiObject const*)((NiAVObject*)reinterpret_cast<const NiAVObjectPtr&>(reinterpret_cast<const Unk_LightTarget*>(pTarget)->m_hNode)))));
    switch (m_unk_18)
    {
    case 0:
    case 1:
    case 6:
        bValid = true;
    }
    if (!bValid)
        return false;

    if (pShadow != 0)
    {
        efd::SmartPointer<ecr::SceneGraphService> spService(egf::g_bapiContext.GetSystemServiceAs<ecr::SceneGraphService>());
        egf::Entity* pOwner = spService->GetEntityFromSceneGraphNode(pShadow);
        if (pOwner != 0)
        {
            Unk_LightWorldObj* pObj = reinterpret_cast<Unk_LightWorldObj*>(WorldService::GetInstance()->FUN_141bd0f50(reinterpret_cast<class Unk_WsC_GameObj*>(pOwner)));
            if (pObj != 0 && pObj->GetClassId() == 0x6200044)
                return false;
        }
    }

    m_ptTranslate = pLightParam->m_ptTranslate;
    m_fDimmer = pLightParam->m_fDimmer;

    efd::SmartPointer<EffectNode> spNode = new (efd::MemHint(efd::MemHint::NONE)) EffectNode(true, false);
    spNode->SetName("Light Effect Root");
    m_spOuter = spNode;
    m_spLightNode = spNode;

    if (pLightParam->m_bUsePreDataTransform && reinterpret_cast<const Unk_LightTarget*>(pTarget)->m_pPreData != 0)
    {
        NiTransform kXform;
        kXform = *reinterpret_cast<const Unk_LightTarget*>(pTarget)->m_pPreData;
        static_cast<efd::Point3&>(kXform.m_Translate) += reinterpret_cast<const efd::Point3&>(m_ptTranslate);
        spNode->SetLocalTransform(kXform);
    }
    else
    {
        spNode->SetTranslation(reinterpret_cast<const efd::Point3&>(m_ptTranslate));
    }

    if (pShadow != 0)
    {
        m_spParent = static_cast<NiNode*>(((void*)NiObject::DynamicCast((class NiRTTI const*)(&NiNode::ms_RTTI), (class NiObject const*)(pShadow->GetObjectByName((const char*)pLightParam->m_strParentNode)))));
        if (m_spParent == (NiNode*)0)
            m_spParent = pShadow;
        if (!pLightParam->m_update.FUN_140afc5a0() && !FUN_14144b630(&pLightParam->m_update))
        {
            SeparateNode* pSep = new (efd::MemHint(efd::MemHint::NONE)) SeparateNode(pLightParam->m_update);
            pSep->AttachChild(static_cast<NiAVObject*>((NiNode*)m_spOuter), false);
            m_spOuter = pSep;
        }
    }
    else
    {
        m_spParent = reinterpret_cast<NiNode*>(reinterpret_cast<CEffectService*>(TSingleton<CEffectService>::GetInstance())->GetLeastLoadedRoot());
    }

    NiTransform kWorld = m_spParent->GetWorldTransform() * m_spLightNode->GetLocalTransform();

    egf::EntityID id = egf::EntityIDFactory::GetNextID();
    reinterpret_cast<egf::EntityPtr&>(m_entity) = static_cast<const egf::EntityPtr&>(TSingleton<EntityWorldManager>::GetInstance()->FactoryEntity("EffectPointLight", id, true));
    if (reinterpret_cast<egf::EntityPtr&>(m_entity) == (egf::Entity*)0)
        return false;

    bool bFalse = false;
    SetCachedBoolProperty((class Unk_CachedEntity*)(reinterpret_cast<Unk_Entity*>(reinterpret_cast<egf::EntityPtr&>(m_entity).operator->())), 0x2a7fd9f4, bFalse);
    float fFifty = 50.0f;
    static_cast<Unk_CachedEntity*>(reinterpret_cast<egf::EntityPtr&>(m_entity).operator->())->SetPropertyValue<float>(0x9109875b, fFifty);
    bool bTrue = true;
    SetCachedBoolProperty((class Unk_CachedEntity*)(reinterpret_cast<Unk_Entity*>(reinterpret_cast<egf::EntityPtr&>(m_entity).operator->())), 0xef627d53, bTrue);
    bool bFalse2 = false;
    SetCachedBoolProperty((class Unk_CachedEntity*)(reinterpret_cast<Unk_Entity*>(reinterpret_cast<egf::EntityPtr&>(m_entity).operator->())), 0x78e546ab, bFalse2);
    FUN_140b27f00(reinterpret_cast<Unk_Entity*>(reinterpret_cast<egf::EntityPtr&>(m_entity).operator->()), 0x2d8cf386, const_cast<efd::Color*>(&pLightParam->m_clrDiffuse));
    FUN_140b27f00(reinterpret_cast<Unk_Entity*>(reinterpret_cast<egf::EntityPtr&>(m_entity).operator->()), 0xc3f0329e, const_cast<efd::Color*>(&pLightParam->m_clrSpecular));
    static_cast<Unk_CachedEntity*>(reinterpret_cast<egf::EntityPtr&>(m_entity).operator->())->SetPropertyValue<float>(0x18f5d90e, pLightParam->m_fDimmer);
    static_cast<Unk_CachedEntity*>(reinterpret_cast<egf::EntityPtr&>(m_entity).operator->())->SetPropertyValue<float>(0x4871503b, pLightParam->m_fRange);
    static_cast<Unk_CachedEntity*>(reinterpret_cast<egf::EntityPtr&>(m_entity).operator->())->SetPropertyValue<float>(0x4dcec447, pLightParam->m_fAttConstant);
    static_cast<Unk_CachedEntity*>(reinterpret_cast<egf::EntityPtr&>(m_entity).operator->())->SetPropertyValue<float>(0x8cd1ae89, pLightParam->m_fAttLinear);
    static_cast<Unk_CachedEntity*>(reinterpret_cast<egf::EntityPtr&>(m_entity).operator->())->SetPropertyValue<float>(0x9f7d1fa7, pLightParam->m_fAttQuadratic);
    Vector3 ptWorld = reinterpret_cast<const Vector3&>(kWorld.m_Translate);
    reinterpret_cast<egf::EntityPtr&>(m_entity).operator->()->SetPropertyValue<efd::Point3>(0xfd95ca52, reinterpret_cast<const efd::Point3&>(ptWorld));
    TSingleton<EntityWorldManager>::GetInstance()->AddEntity((egf::Entity*)reinterpret_cast<egf::EntityPtr&>(m_entity), 0);
    if (IsNearlyEqual(pLightParam->m_fStartDelay, 0.0f))
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
    if ((bool)(NiNode*)m_spParent && !m_b2e)
    {
        NiNode* pParent = static_cast<NiNode*>(m_spParent.operator->());
        pParent->AttachChild(static_cast<NiAVObject*>((NiNode*)m_spOuter), true);
        m_spOuter->Update((float)TSingleton<CMainSystem>::GetInstance()->GetGameTime(), true);
    }
    m_b2e = true;
}
MS2_REPLACE_METHOD(0x14144AD00, CLightEffect, vfunc_4, 221, 0xFE4D83F7);

// @0x14144adf0
void CLightEffect::vfunc_7()
{
    DetachFromParent((class NiAVObject*)((NiNode*)m_spOuter));
    if ((egf::Entity*)reinterpret_cast<egf::EntityPtr&>(m_entity) != 0)
    {
        CMainSystem::DestroyEntity((egf::Entity*)reinterpret_cast<egf::EntityPtr&>(m_entity));
        reinterpret_cast<egf::EntityPtr&>(m_entity) = (egf::Entity*)0;
    }
}
MS2_REPLACE_METHOD(0x14144ADF0, CLightEffect, vfunc_7, 105, 0xFE245DC8);

// @0x14144b0d0
void CLightEffect::FUN_14144b0d0()
{
    if ((bool)(egf::Entity*)reinterpret_cast<egf::EntityPtr&>(m_entity) && (bool)(NiNode*)m_spLightNode)
    {
        Vector3 pt = reinterpret_cast<const Vector3&>(m_spLightNode->GetWorldTranslate());
        reinterpret_cast<egf::EntityPtr&>(m_entity).operator->()->SetPropertyValue<efd::Point3>(0xfd95ca52, reinterpret_cast<const efd::Point3&>(pt));
    }
}
MS2_REPLACE_METHOD(0x14144B0D0, CLightEffect, FUN_14144b0d0, 182, 0x87513DBB);

// @0x14144ae60
void CLightEffect::vfunc_13(TransitionData* pFromBase, TransitionData* pToBase, float fT)
{
    LightEffectTransitionData* pFrom = static_cast<LightEffectTransitionData*>(pFromBase);
    LightEffectTransitionData* pTo = static_cast<LightEffectTransitionData*>(pToBase);
    FUN_140b27f00(reinterpret_cast<Unk_Entity*>(reinterpret_cast<egf::EntityPtr&>(m_entity).operator->()), 0x2d8cf386, const_cast<efd::Color*>(&static_cast<const efd::Color&>(pFrom->m_clrDiffuse + fT * (pTo->m_clrDiffuse - pFrom->m_clrDiffuse))));
    FUN_140b27f00(reinterpret_cast<Unk_Entity*>(reinterpret_cast<egf::EntityPtr&>(m_entity).operator->()), 0xc3f0329e, const_cast<efd::Color*>(&static_cast<const efd::Color&>(pFrom->m_clrSpecular + fT * (pTo->m_clrSpecular - pFrom->m_clrSpecular))));
    float fDimmer = pFrom->m_fDimmer + fT * (pTo->m_fDimmer - pFrom->m_fDimmer);
    static_cast<Unk_CachedEntity*>(reinterpret_cast<egf::EntityPtr&>(m_entity).operator->())->SetPropertyValue<float>(0x18f5d90e, fDimmer);
    float fRange = pFrom->m_fRange + fT * (pTo->m_fRange - pFrom->m_fRange);
    static_cast<Unk_CachedEntity*>(reinterpret_cast<egf::EntityPtr&>(m_entity).operator->())->SetPropertyValue<float>(0x4871503b, fRange);
}
MS2_REPLACE_METHOD(0x14144AE60, CLightEffect, vfunc_13, 495, 0x7A080091);

// @0x14144b060
void CLightEffect::vfunc_10(bool bVisible)
{
    float fDimmer = bVisible ? m_fDimmer : 0.0f;
    static_cast<Unk_CachedEntity*>(reinterpret_cast<egf::EntityPtr&>(m_entity).operator->())->SetPropertyValue<float>(0x18f5d90e, fDimmer);
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
// MS2-PIN: ??GColor@efd@@QEBA?AV01@AEBV01@@Z 0x14144b3f0
// MS2-PIN: ??HColor@efd@@QEBA?AV01@AEBV01@@Z 0x14144b480
// MS2-PIN: ??Defd@@YA?AVColor@0@MAEBV10@@Z 0x14144b3b0
