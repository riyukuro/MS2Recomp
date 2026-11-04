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
class Unk_XmlNode   // C3: member view for the former Unk_140165cf0 stand-ins
{
public:
    class Unk_XmlNode* FirstChild(char const*);
    class Unk_XmlNode* NextSibling(char const*);
};

// ---- out-of-unit types and callees (bound to the exe by their FUN_<va> names / symbols) ----
// Game TinyXML element.
class Unk_140165cf0
{
public:
    Unk_140165cf0* FUN_140165cf0(const char* pszName);              // FirstChildElement(name)
    Unk_140165cf0* FUN_140168650(const char* pszName);              // NextSiblingElement(name)
};
class TiXmlElement   // C3: member view for the former free stand-ins
{
public:
    char const* Attribute(char const*) const;
};
int XmlGetAttr(class TiXmlElement*, char const*, float&);   // C3: was FUN_140873360
int XmlGetAttr(class TiXmlElement*, char const*, bool&);   // C3: was FUN_1408730a0
int XmlGetAttr(class TiXmlElement*, char const*, CStringA&);   // C3: was FUN_1408733e0
int FUN_140874670(Unk_140165cf0* pNode, const char* pszName, Vector3& kOut);
CString FUN_140188f50(const char* psz, int n);                      // null-safe CString
template <class C> void XmlSplit(const CString& str, C& out, const char* pszDelim);   // C3: was FUN_140177e10 (CAtlArray<unsigned>)
void FUN_14185f0b0(TransitionData* pData, Unk_140165cf0* pNode, float* pfTime);    // type / duration / start time

Unk_LightUpdateBits* FUN_140314670(Unk_LightUpdateBits* pBits, unsigned nPos, bool bValue);    // set one bit
class Unk_SetEffectBits   // C3: member view for the former free stand-ins
{
public:
    bool FUN_1411fe0e0() const;
};
class Unk_CamMoveBits   // C3: member view for the former free stand-ins
{
public:
    bool FUN_140afc5a0() const;
};
bool FUN_14028d470(float a, float b);                               // nearly equal

void FUN_140a0b2a0(class NiAVObject*);   // C3: was FUN_140a0b2a0
namespace egf { class ScriptContext; extern ScriptContext g_bapiContext; }
#define DAT_143b059e8 (*(char*)&egf::g_bapiContext)          // C3: was extern char DAT_143b059e8 (service lookup cell)
struct Unk_CcSvcCell;
class Unk_AnimSvc;
Unk_AnimSvc*FUN_1410a68f0(Unk_CcSvcCell*);

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
void FUN_14098c6e0(class Unk_CachedEntity*, unsigned int, bool const&);   // C3: was FUN_14098c6e0

class Unk_CachedEntity : public egf::Entity   // as propertycache.h declares it
{
public:
    template <class T> egf::PropertyResult SetPropertyValue(egf::PropertyID nProp, const T& value);   // 0x1409457c0 for float
};

class Unk_Entity
{
public:
    void FUN_140b27f00(unsigned nProp, const Unk_LightColor& rValue);
    void FUN_140a38a50(unsigned nProp, const Vector3& rValue);
};

// Scene node of the effect system: SeparateNode (0x138) follows only the selected parts of its parent's transform.
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
class Unk_BuddyHandle { public: Unk_BuddyHandle(void*); private: void* m_p; };
static Unk_BuddyHandle s_dat_143adc8e8(0);                                       // @0x1400f7320
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
    return !((class Unk_SetEffectBits*)(struct Unk_LightUpdateBits const*)(pBits))->FUN_1411fe0e0();
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
    CString str = FUN_140188f50(((class TiXmlElement*)(class Unk_140165cf0*)(pNode))->Attribute(pszName), 0);                              \
    XmlSplit(str, arr, ",");                                                               \
    dst = arr.GetCount() < 3 ? Unk_LightColor(1.0f, 1.0f, 1.0f)                                 \
        : Unk_LightColor((float)arr[0] / 255.0f, (float)arr[1] / 255.0f, (float)arr[2] / 255.0f)

// @0x141449600
void CLightEffectParam::vfunc_1(Unk_140165cf0* pNode)
{
    CEffectParam::vfunc_1(pNode);
    Unk_140165cf0* pTransform = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pNode))->FirstChild("transform"));
    if (pTransform != 0)
        FUN_140874670(pTransform, "translate", m_ptTranslate);
    Unk_140165cf0* pAttach = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pNode))->FirstChild("attachInfo"));
    if (pAttach != 0)
        XmlGetAttr((class TiXmlElement*)(pAttach), "parentNode", m_strParentNode);

    bool bTranslate = false, bRotation = false, bScale = false;
    Unk_140165cf0* pUpdate = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pNode))->FirstChild("update"));
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

    Unk_140165cf0* pLight = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pNode))->FirstChild("light"));
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
    Unk_140165cf0* pAtt = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pNode))->FirstChild("attenuation"));
    if (pAtt != 0)
    {
        XmlGetAttr((class TiXmlElement*)(pAtt), "constant", m_fAttConstant);
        XmlGetAttr((class TiXmlElement*)(pAtt), "linear", m_fAttLinear);
        XmlGetAttr((class TiXmlElement*)(pAtt), "quadratic", m_fAttQuadratic);
    }

    float fTime = m_fStartDelay;
    for (Unk_140165cf0* pKey = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pNode))->FirstChild("transition")); pKey != 0; pKey = ((class Unk_140165cf0*)((class Unk_XmlNode*)(pKey))->NextSibling("transition")))
    {
        NiPointer<LightEffectTransitionData> spData(new (efd::MemHint(efd::MemHint::NONE)) LightEffectTransitionData());
        FUN_14185f0b0(spData.operator->(), pKey, &fTime);
        ATL::CAtlArray<unsigned int> arrDiffuse;
        ATL::CAtlArray<unsigned int> arrSpecular;
        LIGHT_PARSE_COLOR(spData->m_clrDiffuse, pKey, "diffuse", strDiffuse, arrDiffuse);
        LIGHT_PARSE_COLOR(spData->m_clrSpecular, pKey, "specular", strSpecular, arrSpecular);
        XmlGetAttr((class TiXmlElement*)(pKey), "dimmer", spData->m_fDimmer);
        XmlGetAttr((class TiXmlElement*)(pKey), "range", spData->m_fRange);
        CString strLoop = FUN_140188f50(((class TiXmlElement*)(class Unk_140165cf0*)(pKey))->Attribute("loop"), 0);
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
        efd::SmartPointer<ecr::SceneGraphService> spService(reinterpret_cast<ecr::SceneGraphService *>(FUN_1410a68f0(reinterpret_cast<Unk_CcSvcCell *>(&DAT_143b059e8))));
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
        if (!((class Unk_CamMoveBits*)(struct Unk_LightUpdateBits const*)(&pLightParam->m_update))->FUN_140afc5a0() && !FUN_14144b630(&pLightParam->m_update))
        {
            Unk_SeparateNode* pSep = new (efd::MemHint(efd::MemHint::NONE)) Unk_SeparateNode(pLightParam->m_update.m_bits);
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
    FUN_14098c6e0((class Unk_CachedEntity*)(reinterpret_cast<Unk_Entity*>(reinterpret_cast<egf::EntityPtr&>(m_entity).operator->())), 0x2a7fd9f4, bFalse);
    float fFifty = 50.0f;
    static_cast<Unk_CachedEntity*>(reinterpret_cast<egf::EntityPtr&>(m_entity).operator->())->SetPropertyValue<float>(0x9109875b, fFifty);
    bool bTrue = true;
    FUN_14098c6e0((class Unk_CachedEntity*)(reinterpret_cast<Unk_Entity*>(reinterpret_cast<egf::EntityPtr&>(m_entity).operator->())), 0xef627d53, bTrue);
    bool bFalse2 = false;
    FUN_14098c6e0((class Unk_CachedEntity*)(reinterpret_cast<Unk_Entity*>(reinterpret_cast<egf::EntityPtr&>(m_entity).operator->())), 0x78e546ab, bFalse2);
    reinterpret_cast<Unk_Entity*>(reinterpret_cast<egf::EntityPtr&>(m_entity).operator->())->FUN_140b27f00(0x2d8cf386, pLightParam->m_clrDiffuse);
    reinterpret_cast<Unk_Entity*>(reinterpret_cast<egf::EntityPtr&>(m_entity).operator->())->FUN_140b27f00(0xc3f0329e, pLightParam->m_clrSpecular);
    static_cast<Unk_CachedEntity*>(reinterpret_cast<egf::EntityPtr&>(m_entity).operator->())->SetPropertyValue<float>(0x18f5d90e, pLightParam->m_fDimmer);
    static_cast<Unk_CachedEntity*>(reinterpret_cast<egf::EntityPtr&>(m_entity).operator->())->SetPropertyValue<float>(0x4871503b, pLightParam->m_fRange);
    static_cast<Unk_CachedEntity*>(reinterpret_cast<egf::EntityPtr&>(m_entity).operator->())->SetPropertyValue<float>(0x4dcec447, pLightParam->m_fAttConstant);
    static_cast<Unk_CachedEntity*>(reinterpret_cast<egf::EntityPtr&>(m_entity).operator->())->SetPropertyValue<float>(0x8cd1ae89, pLightParam->m_fAttLinear);
    static_cast<Unk_CachedEntity*>(reinterpret_cast<egf::EntityPtr&>(m_entity).operator->())->SetPropertyValue<float>(0x9f7d1fa7, pLightParam->m_fAttQuadratic);
    Vector3 ptWorld = reinterpret_cast<const Vector3&>(kWorld.m_Translate);
    reinterpret_cast<Unk_Entity*>(reinterpret_cast<egf::EntityPtr&>(m_entity).operator->())->FUN_140a38a50(0xfd95ca52, ptWorld);
    TSingleton<EntityWorldManager>::GetInstance()->FUN_1411cf2d0((egf::Entity*)reinterpret_cast<egf::EntityPtr&>(m_entity), 0);
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
    if ((bool)(NiNode*)m_spParent && !m_b2e)
    {
        NiNode* pParent = static_cast<NiNode*>(m_spParent.operator->());
        pParent->AttachChild(static_cast<NiAVObject*>((NiNode*)m_spOuter), true);
        m_spOuter->Update((float)TSingleton<CMainSystem>::GetInstance()->FUN_141473280(), true);
    }
    m_b2e = true;
}
MS2_REPLACE_METHOD(0x14144AD00, CLightEffect, vfunc_4, 221, 0xFE4D83F7);

// @0x14144adf0
void CLightEffect::vfunc_7()
{
    FUN_140a0b2a0((class NiAVObject*)((NiNode*)m_spOuter));
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
        reinterpret_cast<Unk_Entity*>(reinterpret_cast<egf::EntityPtr&>(m_entity).operator->())->FUN_140a38a50(0xfd95ca52, pt);
    }
}
MS2_REPLACE_METHOD(0x14144B0D0, CLightEffect, FUN_14144b0d0, 182, 0x87513DBB);

// @0x14144ae60
void CLightEffect::vfunc_13(TransitionData* pFromBase, TransitionData* pToBase, float fT)
{
    LightEffectTransitionData* pFrom = static_cast<LightEffectTransitionData*>(pFromBase);
    LightEffectTransitionData* pTo = static_cast<LightEffectTransitionData*>(pToBase);
    reinterpret_cast<Unk_Entity*>(reinterpret_cast<egf::EntityPtr&>(m_entity).operator->())->FUN_140b27f00(0x2d8cf386, pFrom->m_clrDiffuse + fT * (pTo->m_clrDiffuse - pFrom->m_clrDiffuse));
    reinterpret_cast<Unk_Entity*>(reinterpret_cast<egf::EntityPtr&>(m_entity).operator->())->FUN_140b27f00(0xc3f0329e, pFrom->m_clrSpecular + fT * (pTo->m_clrSpecular - pFrom->m_clrSpecular));
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

