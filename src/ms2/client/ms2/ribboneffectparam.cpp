// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The "Ribbon" effect (effect XML type 0xd): the param and the
// runtime CRibbonEffect, a textured strip along the Catmull-Rom curve through the target's points (see
// ribboneffectparam.h). Also holds this unit's unreferenced CRT memcpy_s copy.
// MS2-UNIT: ?\ribboneffectparam.cpp
// MS2-RANGE: 0x1400ff2b0-0x1400ff360 .text$di
// MS2-RANGE: 0x141701380-0x141703a70 .text$mn
// MS2-PIN: ??1CRibbonEffectParam@@UEAA@XZ 0x1417037e0
// MS2-PIN: ??_GCRibbonEffect@@UEAAPEAXI@Z 0x141703860
// MS2-PIN: ??_GCRibbonEffectParam@@UEAAPEAXI@Z 0x1417038c0
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??A?$CAtlArray@VPoint3@efd@@V?$CElementTraits@VPoint3@efd@@@ATL@@@ATL@@QEAAAEAVPoint3@efd@@_K@Z 0x141703820 ; unique
// MS2-PINS-END tplpin
#ifndef NOMINMAX
#define NOMINMAX
#endif
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\ribboneffectparam.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ribboneffectparam.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/postprocesseffect.h"      // efd::SmartPointer<NiTexture>
#include "ms2/client/ms2/cameramode.h"              // CCameraMode, Unk_CameraSetting
#include <errno.h>
#include <new>
#include <string.h>
#include <efd/MemoryDefines.h>
#include <NiNode.h>
#include <NiMesh.h>
#include <NiAVObject.h>
#include <NiFixedString.h>
#include <NiCommonSemantics.h>
#include <NiColor.h>
#include <NiPoint2.h>
#include <NiPoint3.h>
#include <NiAlphaProperty.h>
#include <NiVertexColorProperty.h>
#include <NiFogProperty.h>
#include <NiWireframeProperty.h>
#include <NiStencilProperty.h>
#include <NiZBufferProperty.h>
#include <NiTexturingProperty.h>
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/cmainsystem.h"
#include "ms2/client/ms2/nifeffectparam.h"
#include "ms2/client/ms2/effectservice.h"   // C3: EffectNode (the ribbon root)
#include <efd/EEMath.h>   // C3: efd::Clamp was FUN_140a17940
template <class T> class TSingleton;
class CameraMgr;
template <> class TSingleton<CameraMgr> { public: static CameraMgr* GetInstance(); };   // C3: 0x1409478c0, as camera.h declares it
class TiXmlElement;
#include "ms2/placeholder/tixmlelement.h"   // C3 #12: was a local TiXml view





// ---- out-of-unit types and callees (bound to the exe by their FUN_<va> names / symbols) ----
// Game TinyXML element.
// C3 #12: was a local TiXml view




int XmlGetAttr(class TiXmlElement*, char const*, float&);   // C3: was FUN_140873360
int XmlGetAttr(class TiXmlElement*, char const*, int&);   // C3: was FUN_1408731e0
int XmlGetAttr(class TiXmlElement*, char const*, CStringA&);   // C3: was FUN_1408733e0
CString FUN_140188f50(const char* psz, int n);                      // null-safe CString
CString FUN_140cc2ba0(const CString& strDir, const CString& strName);

bool IsNearlyEqual(float a, float b);                               // nearly equal
// The camera manager's position getter returns the NiPoint3 that UpdateMesh slices into its Vector3 local.
class CameraMgr { public: NiPoint3 FUN_140af0250(); };
void DetachFromParent(NiAVObject* pObj);                               // detach from the parent
class NoticeMessage   // C3: member view for the former free stand-ins
{
public:
    class NiNode* GetRoot();
};
void PrepareLoadedNif(NiAVObject* pObj, bool bFlag);
// Time controller / extra data helpers.
// Property list of an NiMesh (hash/list walk with a position cursor).
// The Catmull-Rom point between four control points (beameffect.cpp).
Vector3 FUN_140a0adf0(const Vector3& p0, const Vector3& p1, const Vector3& p2, const Vector3& p3, float fT);

// Depth-first walker over a scene graph (0x38 bytes; unrecovered class).
class Unk_NodeQueue
{
public:
    Unk_NodeQueue(NiAVObject* pkRoot);              // 0x14098cb80
    ~Unk_NodeQueue();                             // 0x14098cf00
    NiAVObject* Next(bool bDescend);                // 0x14098e0d0
private:
    void* m_pad_00; void* m_pad_08; void* m_pad_10; void* m_pad_18; void* m_pad_20; void* m_pad_28; void* m_pad_30;
};
typedef Unk_NodeQueue Unk_SceneWalker;   // C3: was a local stand-in for Unk_NodeQueue
MS2_CHECK_SIZE(Unk_SceneWalker, 0x38);

// The resource manager (singleton, instance pointer at 0x143ab5bc8): model / texture cache by path.
class Unk_ResourceMgr : public CNifLoadingService
{
public:
};
Unk_ResourceMgr* GetNifLoadingService();

// The effect node (400 bytes) carries the effect-space point.

#ifndef MS2_HOOK_DLL
// File statics of this TU (initialised by the .text$di entries).
const NiRTTI CRibbonEffect::ms_RTTI("CRibbonEffect", &CEffect::ms_RTTI);        // @0x1400ff2b0
static CString s_str143ae6a00("skill");                                          // @0x1400ff2e0
static CString s_str143ae69f8("stun");                                           // @0x1400ff310
#include <egf/EntityID.h>   // B22: was class Unk_BuddyHandle (ctor 0x1401cd100 = egf::EntityID(efd::UInt64))
static egf::EntityID s_dat_143ae6a08(0);                                   // @0x1400ff340
#else
const NiRTTI CRibbonEffect::ms_RTTI("CRibbonEffect", &CEffect::ms_RTTI);
#endif

// @0x141701380
CRibbonEffectParam::CRibbonEffectParam()
    : CEffectParam(0xd), m_fWidth(10.0f), m_nQuality(4), m_nAlphaMode(0)
{
}

// @0x141701410
void CRibbonEffectParam::vfunc_1(TiXmlElement* pNode)
{
    CEffectParam::vfunc_1(pNode);
    XmlGetAttr((class TiXmlElement*)(pNode), "texturePath", m_strTexturePath);
    XmlGetAttr((class TiXmlElement*)(pNode), "nifPath", m_strNifPath);
    XmlGetAttr((class TiXmlElement*)(pNode), "width", m_fWidth);
    XmlGetAttr((class TiXmlElement*)(pNode), "quality", m_nQuality);
    CString strAlpha = FUN_140188f50(((class TiXmlElement*)(class TiXmlElement*)(pNode))->Attribute("alphaMode"), 0);
    if (strAlpha.GetLength() > 0)
    {
        if (strAlpha.CompareNoCase("SWOOSH") == 0)
            m_nAlphaMode = 0;
        if (strAlpha.CompareNoCase("STANDARD") == 0)
            m_nAlphaMode = 1;
        if (strAlpha.CompareNoCase("ADD") == 0)
            m_nAlphaMode = 2;
    }
}

// @0x141701560
bool CRibbonEffectParam::vfunc_5(int n)
{
    if (!m_strNifPath.IsEmpty())
        GetNifLoadingService()->Preload(FUN_140cc2ba0("Effect", m_strNifPath), false, n);
    return true;
}

// @0x141701610
// Not hooked: constructs CRibbonEffect with its (exe) constructor.
CEffectPtr CRibbonEffectParam::vfunc_6()
{
    return new (efd::MemHint(efd::MemHint::NONE)) CRibbonEffect;
}

// @0x1417016b0
CRibbonEffect::CRibbonEffect()
    : m_spOwner(0), m_spRoot(0), m_spUnused40(0), m_spMesh(0), m_spTarget(0)
{
    m_nUVSets = 1;
    m_fFadeStart = 0.0f;
    m_fFadeEnd = 1.0f;
    m_fAlphaFrom = 1.0f;
    m_fAlphaTo = 1.0f;
}

// @0x1417017a0
CRibbonEffect::~CRibbonEffect()
{
    vfunc_7();
    m_spOwner = (NiNode*)0;
}

// @0x141701850
// Builds the root node and the strip mesh: either a plain textured strip (param texturePath) or a copy of the first mesh
// of the param's nif (its properties, controllers and extra data are moved over).
bool CRibbonEffect::vfunc_3(const CEffectParam* pParam, Unk_EffectTarget* pTarget)
{
    if (!CEffect::vfunc_3(pParam, pTarget))
        return false;
    const CRibbonEffectParam* pRibbon = static_cast<const CRibbonEffectParam*>(pParam);
    m_spTarget = (NiNode*)NiObject::DynamicCast((class NiRTTI const*)(&NiNode::ms_RTTI), (class NiObject const*)((NiAVObject*)reinterpret_cast<const NiAVObjectPtr&>(reinterpret_cast<const Unk_RibbonTarget*>(pTarget)->m_hNode)));
    m_pPoints = reinterpret_cast<const Unk_RibbonTarget*>(pTarget)->m_pPoints;
    m_spOwner = ((class NoticeMessage*)(class Unk_EffectTarget*)(pTarget))->GetRoot();
    if (m_spTarget == 0 || m_pPoints == 0)
        return false;

    m_fHalfWidth = 0.5f * pRibbon->m_fWidth;
    m_nQuality = pRibbon->m_nQuality;

    NiPointer<EffectNode> spRoot = new (efd::MemHint(efd::MemHint::NONE)) EffectNode(false, false);
    spRoot->SetName("Effect Root");
    m_spRoot = spRoot;

    if ((const char*)pRibbon->m_strNifPath != 0)
    {
        NiAVObjectPtr spModel = GetNifLoadingService()->Load(FUN_140cc2ba0("Effect", pRibbon->m_strNifPath), false, 5, 0, 0);
        NiMesh* pFound = 0;
        Unk_SceneWalker kWalker((NiAVObject*)spModel);
        NiAVObject* pObj;
        while ((pObj = kWalker.Next(true)) != 0)
        {
            if (NiObject::IsExactKindOf(&NiMesh::ms_RTTI, (class NiObject const*)(pObj)))
            {
                pFound = static_cast<NiMesh*>(pObj);
                break;
            }
        }
        if (pFound == 0)
            return false;
        m_nUVSets = pFound->GetSemanticCount(NiCommonSemantics::TEXCOORD());
        m_spMesh = new (efd::MemHint(efd::MemHint::NONE)) CMesh(false, true, m_nUVSets, 0x1f42, 8000, 0x15);
        NiAVObject* pMeshObj = m_spMesh->GetMesh();
        pMeshObj->SetName("RibbonEffect");
        NiPropertyList* pList = &((class NiAVObject*)(class NiMesh*)(pFound))->GetPropertyList();
        NiTListIterator pPos = pList->GetHeadPos();
        while (pPos != 0)
        {
            NiProperty* pProp = pList->GetNext(pPos);
            if (NiObject::IsExactKindOf(&NiTexturingProperty::ms_RTTI, (class NiObject const*)(pProp)))
            {
                NiTimeController* pCtrl = ((class NiObjectNET*)(class NiObjectNET*)(pProp))->GetControllers();
                while (pCtrl != 0)
                {
                    pCtrl->SetCycleType(NiTimeController::LOOP);
                    pCtrl = ((class NiTimeController*)(class NiTimeController*)(pCtrl))->GetNext();
                }
            }
            ((class NiAVObject*)(class NiAVObject*)(pMeshObj))->AttachProperty(pProp);
        }
        if (pMeshObj->GetProperty(9) != 0)
            pMeshObj->RemoveProperty(9);
        NiVertexColorProperty* pVertexColor = new (efd::MemHint(efd::MemHint::NONE)) NiVertexColorProperty;
        pVertexColor->SetSourceMode(NiVertexColorProperty::SOURCE_AMB_DIFF);
        pVertexColor->SetLightingMode(NiVertexColorProperty::LIGHTING_E_A_D);
        ((class NiAVObject*)(class NiAVObject*)(pMeshObj))->AttachProperty(pVertexColor);
        if (pMeshObj->GetProperty(7) == 0)
        {
            NiStencilProperty* pStencil = new (efd::MemHint(efd::MemHint::NONE)) NiStencilProperty;
            pStencil->SetDrawMode(NiStencilProperty::DRAW_BOTH);
            ((class NiAVObject*)(class NiAVObject*)(pMeshObj))->AttachProperty(pStencil);
        }
        if (pMeshObj->GetProperty(0xb) == 0)
        {
            NiZBufferProperty* pZBuffer = new (efd::MemHint(efd::MemHint::NONE)) NiZBufferProperty;
            pZBuffer->SetZBufferWrite(false);
            ((class NiAVObject*)(class NiAVObject*)(pMeshObj))->AttachProperty(pZBuffer);
        }
        unsigned short nExtra = ((class NiObjectNET*)(class NiObjectNET*)(pFound))->GetExtraDataSize();
        for (unsigned short i = 0; i < nExtra; ++i)
        {
            NiExtraData* pExtra = ((class NiObjectNET*)(class NiObjectNET*)(pFound))->GetExtraDataAt(i);
            m_spMesh->GetMesh()->AddExtraData(pExtra);
        }
        NiTimeController* pControllers = ((class NiObjectNET*)(class NiObjectNET*)(pFound))->GetControllers();
        m_spMesh->GetMesh()->SetControllers(pControllers);
    }
    else
    {
        m_spMesh = new (efd::MemHint(efd::MemHint::NONE)) CMesh(false, true, m_nUVSets, 0x1f42, 8000, 0x15);
        m_spMesh->GetMesh()->SetName("RibbonEffect");
        NiPointer<NiTexturingProperty> spTexture = new (efd::MemHint(efd::MemHint::NONE)) NiTexturingProperty;
        spTexture->SetBaseFilterMode((NiTexturingProperty::FilterMode)0);
        spTexture->SetApplyMode((NiTexturingProperty::ApplyMode)1);
        spTexture->SetBaseClampMode((NiTexturingProperty::ClampMode)0);
        ((class NiTexturingProperty*)(class NiTexturingProperty*)(spTexture.operator->()))->SetBaseTexture((class NiTexture*)(GetNifLoadingService()->GetTexture(CString((const char*)FUN_140cc2ba0("Effect/Textures", pRibbon->m_strTexturePath)), 5)));
        ((class NiAVObject*)(class NiAVObject*)(m_spMesh->GetMesh()))->AttachProperty(spTexture);

        NiVertexColorProperty* pVertexColor = new (efd::MemHint(efd::MemHint::NONE)) NiVertexColorProperty;
        pVertexColor->SetSourceMode(NiVertexColorProperty::SOURCE_AMB_DIFF);
        pVertexColor->SetLightingMode(NiVertexColorProperty::LIGHTING_E_A_D);
        ((class NiAVObject*)(class NiAVObject*)(m_spMesh->GetMesh()))->AttachProperty(pVertexColor);

        NiAlphaProperty* pAlpha = new (efd::MemHint(efd::MemHint::NONE)) NiAlphaProperty;
        ((class NiAlphaProperty*)(class NiAlphaProperty*)(pAlpha))->SetAlphaBlending(true);
        switch (pRibbon->m_nAlphaMode)
        {
        case 0:
            pAlpha->SetSrcBlendMode((NiAlphaProperty::AlphaFunction)6);
            pAlpha->SetDestBlendMode((NiAlphaProperty::AlphaFunction)0);
            break;
        case 1:
            pAlpha->SetSrcBlendMode((NiAlphaProperty::AlphaFunction)6);
            pAlpha->SetDestBlendMode((NiAlphaProperty::AlphaFunction)7);
            break;
        case 2:
            pAlpha->SetSrcBlendMode((NiAlphaProperty::AlphaFunction)0);
            pAlpha->SetDestBlendMode((NiAlphaProperty::AlphaFunction)0);
            break;
        }
        ((class NiAVObject*)(class NiAVObject*)(m_spMesh->GetMesh()))->AttachProperty(pAlpha);

        NiFogProperty* pFog = new (efd::MemHint(efd::MemHint::NONE)) NiFogProperty;
        pFog->SetFog(false);
        ((class NiAVObject*)(class NiAVObject*)(m_spMesh->GetMesh()))->AttachProperty(pFog);

        NiWireframeProperty* pWireframe = new (efd::MemHint(efd::MemHint::NONE)) NiWireframeProperty;
        ((class NiWireframeProperty*)(class NiWireframeProperty*)(pWireframe))->SetWireframe(false);
        ((class NiAVObject*)(class NiAVObject*)(m_spMesh->GetMesh()))->AttachProperty(pWireframe);

        NiStencilProperty* pStencil = new (efd::MemHint(efd::MemHint::NONE)) NiStencilProperty;
        pStencil->SetDrawMode(NiStencilProperty::DRAW_BOTH);
        ((class NiAVObject*)(class NiAVObject*)(m_spMesh->GetMesh()))->AttachProperty(pStencil);

        NiZBufferProperty* pZBuffer = new (efd::MemHint(efd::MemHint::NONE)) NiZBufferProperty;
        pZBuffer->SetZBufferWrite(false);
        ((class NiAVObject*)(class NiAVObject*)(m_spMesh->GetMesh()))->AttachProperty(pZBuffer);
    }
    m_spMesh->UpdateBound();
    PrepareLoadedNif(m_spMesh->GetMesh(), (bool)0);
    m_spRoot->AttachChild(m_spMesh->GetMesh(), false);
    if (IsNearlyEqual(pRibbon->m_fStartDelay, 0.0f))
        vfunc_4();
    return true;
}

// @0x141702a50
bool CRibbonEffect::vfunc_9()
{
    if (CEffect::vfunc_9())
    {
        if (((NiNode*)m_spRoot ? true : false) && ((class NiAVObject*)(void*)(m_spRoot.operator->()))->GetAppCulled())
            return true;
        UpdateMesh();
        return true;
    }
    return false;
}

// @0x141702ae0
void CRibbonEffect::vfunc_4()
{
    if ((NiNode*)m_spOwner != 0)
        m_spOwner->AttachChild(static_cast<NiAVObject*>(m_spRoot), true);
    m_spRoot->UpdateEffects();
    m_spRoot->UpdateProperties();
    ((class NiAVObject*)(void*)(m_spRoot.operator->()))->Update((float)TSingleton<CMainSystem>::GetInstance()->GetGameTime(), true);
    m_b2e = true;
}

// @0x141702bd0
void CRibbonEffect::vfunc_7()
{
    DetachFromParent(static_cast<NiAVObject*>(m_spRoot));
}

// @0x141702c00
void CRibbonEffect::vfunc_10(bool bVisible)
{
    ((class NiAVObject*)(class NiAVObject*)(static_cast<NiAVObject*>(m_spRoot.operator->())))->SetAppCulled(!bVisible);
}

// @0x141702c50
int CRibbonEffect::vfunc_8(void* p)
{
    *static_cast<Vector3*>(p) = reinterpret_cast<const Vector3&>(m_spRoot->GetWorldTranslate());   // C3: NiAVObject::GetWorldTranslate (0x140947900)
    return 1;
}

// @0x141702d00
// Samples the Catmull-Rom curve through the points (m_nQuality samples per segment), then rewrites the strip: two
// vertex rows (the curve offset by half the width to both sides along the camera-facing side vector) with an alpha
// ramp along the strip, the uv rows and the 2 triangles per curve segment.
void CRibbonEffect::UpdateMesh()
{
    unsigned nPoints = (unsigned)m_pPoints->GetCount();
    if (nPoints < 4)
        return;
    {
        efd::vector<Vector3> kCurve;
        for (unsigned i = 0; i < nPoints - 3; ++i)
        {
            for (unsigned j = 0; j < (unsigned)m_nQuality; ++j)
            {
                float fT = (float)j / (float)(unsigned)m_nQuality;
                kCurve.push_back(FUN_140a0adf0((*m_pPoints)[i], (*m_pPoints)[i + 1], (*m_pPoints)[i + 2], (*m_pPoints)[i + 3], fT));
            }
        }
        Vector3 kCamera = reinterpret_cast<const Vector3&>(static_cast<const NiPoint3&>(TSingleton<CameraMgr>::GetInstance()->FUN_140af0250()));
        efd::vector<Vector3> kMinus;
        efd::vector<Vector3> kPlus;
        for (unsigned i = 0; i < kCurve.size(); ++i)
        {
            Vector3 kDir;
            if (i == 0)
                kDir = (kCurve[i + 1] - kCurve[i]);
            else if (i == kCurve.size() - 1)
                kDir = (kCurve[i] - kCurve[i - 1]);
            else
                kDir = (kCurve[i + 1] - kCurve[i - 1]);
            kDir.Unitize();
            efd::Point3 kSide = reinterpret_cast<const efd::Point3&>(kDir).Cross(reinterpret_cast<const efd::Point3&>(kCamera));
            kMinus.push_back((kCurve[i] - (m_fHalfWidth * reinterpret_cast<Vector3&>(kSide))));
            kPlus.push_back(reinterpret_cast<Vector3&&>(static_cast<efd::Point3&&>(reinterpret_cast<const efd::Point3&>(kCurve[i]) + reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>((m_fHalfWidth * reinterpret_cast<Vector3&>(kSide)))))));
        }

        unsigned short nCount = (unsigned short)kMinus.size();
        NiPoint3* pPos = (NiPoint3*)m_spMesh->Lock(NiCommonSemantics::POSITION(), 0, 2);
        NiColorA* pCol = (NiColorA*)m_spMesh->Lock(NiCommonSemantics::COLOR(), 0, 2);
        for (int i = 0; i < (int)nCount; ++i)
        {
            float fU = (float)i / (float)nCount;
            float fRamp = efd::Clamp((fU - m_fFadeStart) / (m_fFadeEnd - m_fFadeStart), 0.0f, 1.0f);
            float fAlpha = m_fAlphaFrom + fRamp * (m_fAlphaTo - m_fAlphaFrom);
            NiColorA kColor(0.0f, 0.0f, 0.0f, fAlpha);
            pPos[i] = *(const efd::Point3*)&kMinus[i];
            pCol[i] = kColor;
            pPos[i + nCount] = *(const efd::Point3*)&kPlus[i];
            pCol[i + nCount] = kColor;
        }
        m_spMesh->Unlock(NiCommonSemantics::POSITION(), 0, 2);
        m_spMesh->Unlock(NiCommonSemantics::COLOR(), 0, 2);
        for (int nSet = 0; nSet < m_nUVSets; ++nSet)
        {
            NiPoint2* pUV = (NiPoint2*)m_spMesh->Lock(NiCommonSemantics::TEXCOORD(), nSet, 2);
            for (int j = 0; j < (int)nCount; ++j)
            {
                NiPoint2 kTop((float)j / (float)(int)(nCount - 1), 0.0f);
                NiPoint2 kBottom((float)j / (float)(int)(nCount - 1), 1.0f);
                pUV[j] = kTop;
                pUV[j + nCount] = kBottom;
            }
            m_spMesh->Unlock(NiCommonSemantics::TEXCOORD(), nSet, 2);
        }
        m_spMesh->SetVertexCount((unsigned int)nCount << 1);
        unsigned short nQuads = nCount - 1;
        unsigned short* pIdx = (unsigned short*)m_spMesh->Lock(NiCommonSemantics::INDEX(), 0, 2);
        for (unsigned short i = 0; i < nQuads; ++i)
        {
            pIdx[i * 3] = i;
            pIdx[i * 3 + 1] = i + nCount;
            pIdx[i * 3 + 2] = i + 1;
            pIdx[(i + nQuads) * 3] = i + 1;
            pIdx[(i + nQuads) * 3 + 1] = i + nCount;
            pIdx[(i + nQuads) * 3 + 2] = i + 1 + nCount;
        }
        m_spMesh->Unlock(NiCommonSemantics::INDEX(), 0, 2);
        m_spMesh->SetTriangleCount((unsigned int)nQuads * 6);
        m_spMesh->UpdateBound();
    }
}

// @0x141703900
int CRibbonEffect::vfunc_12()
{
    return 0xd;
}

// ---- the unreferenced CRT copy ----

// The UCRT's `static __inline memcpy_s` of this TU (unreferenced copy, kept alive by the pointer below).
// @0x141703920
#pragma function(memset, memcpy)
static __inline errno_t ms2_ribbon_memcpy_s(void* const d, size_t const dsz, void const* const s, size_t const ssz)
{
    if (ssz == 0) { return 0; }
    { int e = !!(d != NULL); if (!e) { errno = EINVAL; _invalid_parameter_noinfo(); return EINVAL; } }
    if (s == NULL || dsz < ssz)
    {
        memset(d, 0, dsz);
        { int e = !!(s != NULL); if (!e) { errno = EINVAL; _invalid_parameter_noinfo(); return EINVAL; } }
        { int e = !!(dsz >= ssz); if (!e) { errno = ERANGE; _invalid_parameter_noinfo(); return ERANGE; } }
        return EINVAL;
    }
    memcpy(d, s, ssz);
    return 0;
}
__declspec(selectany) extern errno_t(__cdecl* const ms2_pfnRibbonMemcpyS)(void*, size_t, const void*, size_t) = &ms2_ribbon_memcpy_s;
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cb5dc0-0x142cb5e00 .text$yd
