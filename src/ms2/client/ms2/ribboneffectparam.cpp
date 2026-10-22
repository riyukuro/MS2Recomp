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
// MS2-PIN: ??A?$CAtlArray@UUnk_StreamPoint@@V?$CElementTraits@UUnk_StreamPoint@@@ATL@@@ATL@@QEAAAEAUUnk_StreamPoint@@_K@Z 0x141703820 ; unique
// MS2-PINS-END tplpin
#ifndef NOMINMAX
#define NOMINMAX
#endif
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\ribboneffectparam.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ribboneffectparam.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/postprocesseffect.h"      // Unk_PPSmartC
#include "ms2/client/ms2/cameramode.h"              // Unk_CameraManager
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

// ---- out-of-unit types and callees (bound to the exe by their FUN_<va> names / symbols) ----
// Game TinyXML element.
class Unk_140165cf0
{
public:
    Unk_140165cf0* FUN_140165cf0(const char* pszName);
};
const char* FUN_14086f4b0(Unk_140165cf0* pNode, const char* pszName);
int FUN_140873360(Unk_140165cf0* pNode, const char* pszName, float& fOut);
int FUN_1408731e0(Unk_140165cf0* pNode, const char* pszName, int& nOut);
int FUN_1408733e0(Unk_140165cf0* pNode, const char* pszName, CString& strOut);
CString FUN_140188f50(const char* psz, int n);                      // null-safe CString
CString FUN_140cc2ba0(const CString& strDir, const CString& strName);

bool FUN_14028d470(float a, float b);                               // nearly equal
class Unk_GameClock { public: double FUN_141473280(); };
Unk_GameClock* FUN_14086d260();
void* FUN_1409849b0(void* pHandle);                                 // handle -> node pointer
void* FUN_14098d8d0(const void* pRtti, void* pObj);                 // dynamic cast through an NiRTTI
const Vector3& FUN_140947900(void* pNode);                  // world translate
bool FUN_14098dad0(void* pNode);                                    // node is app-culled
void FUN_141d16040(void* pNode, float fTime, bool bUpdateControllers);    // NiAVObject::Update
void FUN_140a0b2a0(NiAVObject* pObj);                               // detach from the parent
void FUN_140a0b300(NiAVObject* pObj, bool bCulled);                 // SetAppCulled
bool FUN_14109a9a0(const NiRTTI* pRtti, void* pObj);                // object is of the type
NiNode* FUN_140a533d0(Unk_EffectTarget* pTarget);                   // the target's owner node (or the effect scene root)
void FUN_140980200(NiAVObject* pObj, NiProperty* pProp);            // NiAVObject::AttachProperty
void FUN_140980880(NiTexturingProperty* pProp, void* pTexture);     // SetBaseTexture
void FUN_1409807b0(NiTexturingProperty* pProp, int n);
void FUN_1409805c0(NiTexturingProperty* pProp, int n);
void FUN_1409806e0(NiTexturingProperty* pProp, int n);
void FUN_140980560(NiAlphaProperty* pProp, bool b);                 // SetAlphaBlending
void FUN_140980f60(NiAlphaProperty* pProp, int nMode);              // source blend mode
void FUN_140980af0(NiAlphaProperty* pProp, int nMode);              // destination blend mode
void FUN_140980f20(NiVertexColorProperty* pProp, int n);
void FUN_140980e60(NiVertexColorProperty* pProp, int n);
void FUN_1409a9b90(NiFogProperty* pProp, int n);
void FUN_140981100(NiZBufferProperty* pProp, int n);
void FUN_140a0b6c0(NiWireframeProperty* pProp, bool b);             // SetWireframe
void FUN_1415672e0(NiAVObject* pObj, int n);
float FUN_140a17940(float f, float fMin, float fMax);               // clamp
// Time controller / extra data helpers.
NiTimeController* FUN_14098dc80(NiObjectNET* pObj);                 // first controller
NiTimeController* FUN_14098de40(NiTimeController* pCtrl);           // next controller
void FUN_1416f18b0(NiTimeController* pCtrl, int n);
void FUN_141d18aa0(NiObjectNET* pObj, NiTimeController* pCtrl);     // NiObjectNET::SetControllers
unsigned short FUN_14106bc50(NiObjectNET* pObj);                    // extra data count
NiExtraData* FUN_14106bc30(NiObjectNET* pObj, unsigned short i);    // extra data by index
// Property list of an NiMesh (hash/list walk with a position cursor).
class Unk_PropList;
Unk_PropList* FUN_14127cc40(NiMesh* pMesh);
void* FUN_14098ddb0(Unk_PropList* pList);                           // head position
void* FUN_14098de00(Unk_PropList* pList, void** ppPos);             // slot at the position, advances it
NiProperty* FUN_140993f00(void* pSlot);                             // slot -> property
// The Catmull-Rom point between four control points (beameffect.cpp).
Vector3 FUN_140a0adf0(const Vector3& p0, const Vector3& p1, const Vector3& p2, const Vector3& p3, float fT);

// Depth-first walker over a scene graph (0x38 bytes; unrecovered class).
class Unk_SceneWalker
{
public:
    Unk_SceneWalker(NiObject* pkRoot);              // 0x14098cb80
    ~Unk_SceneWalker();                             // 0x14098cf00
    NiAVObject* Next(bool bDescend);                // 0x14098e0d0
private:
    void* m_pad_00; void* m_pad_08; void* m_pad_10; void* m_pad_18; void* m_pad_20; void* m_pad_28; void* m_pad_30;
};
MS2_CHECK_SIZE(Unk_SceneWalker, 0x38);

// The resource manager (singleton, instance pointer at 0x143ab5bc8): model / texture cache by path.
class Unk_ResourceMgr
{
public:
    Unk_PPSmartC FUN_141552f90(CString strPath, int nFlags);                    // texture load
    NiAVObjectPtr FUN_141551ea0(CString strPath, bool bA, int nB, int nC, int nD);   // model load
    void FUN_1415525d0(CString strPath, int nA, int nB);                        // preload
};
Unk_ResourceMgr* FUN_140a0afd0();

// The effect node (400 bytes) carries the effect-space point.
class Unk_EffectNode : public NiNode
{
public:
    Unk_EffectNode(int nA, int nB);                                 // 0x1411a34b0
    char m_pad_node[400 - sizeof(NiNode)];
};
MS2_CHECK_SIZE(Unk_EffectNode, 400);

#ifndef MS2_HOOK_DLL
// File statics of this TU (initialised by the .text$di entries).
const NiRTTI CRibbonEffect::ms_RTTI("CRibbonEffect", &CEffect::ms_RTTI);        // @0x1400ff2b0
static CString s_str143ae6a00("skill");                                          // @0x1400ff2e0
static CString s_str143ae69f8("stun");                                           // @0x1400ff310
class Unk_Handle1401cd100 { public: Unk_Handle1401cd100(int nNull); void* m_p; };     // ctor 0x1401cd100
static Unk_Handle1401cd100 s_dat_143ae6a08(0);                                   // @0x1400ff340
#else
const NiRTTI CRibbonEffect::ms_RTTI("CRibbonEffect", &CEffect::ms_RTTI);
#endif

// @0x141701380
CRibbonEffectParam::CRibbonEffectParam()
    : CEffectParam(0xd), m_fWidth(10.0f), m_nQuality(4), m_nAlphaMode(0)
{
}

// @0x141701410
void CRibbonEffectParam::vfunc_1(Unk_140165cf0* pNode)
{
    CEffectParam::vfunc_1(pNode);
    FUN_1408733e0(pNode, "texturePath", m_strTexturePath);
    FUN_1408733e0(pNode, "nifPath", m_strNifPath);
    FUN_140873360(pNode, "width", m_fWidth);
    FUN_1408731e0(pNode, "quality", m_nQuality);
    CString strAlpha = FUN_140188f50(FUN_14086f4b0(pNode, "alphaMode"), 0);
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
        FUN_140a0afd0()->FUN_1415525d0(FUN_140cc2ba0("Effect", m_strNifPath), 0, n);
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
    FUN_1409f76f0(&m_spOwner, 0);
}

// @0x141701850
// MS2-FUNCTIONAL: frame differs from the exe (temporaries of the new-expressions are laid out differently).
// Builds the root node and the strip mesh: either a plain textured strip (param texturePath) or a copy of the first mesh
// of the param's nif (its properties, controllers and extra data are moved over).
bool CRibbonEffect::vfunc_3(const CEffectParam* pParam, Unk_EffectTarget* pTarget)
{
    if (!CEffect::vfunc_3(pParam, pTarget))
        return false;
    const CRibbonEffectParam* pRibbon = static_cast<const CRibbonEffectParam*>(pParam);
    const Unk_RibbonTarget* pRibbonTarget = reinterpret_cast<const Unk_RibbonTarget*>(pTarget);
    FUN_1409f76f0(&m_spTarget, FUN_14098d8d0(&NiNode::ms_RTTI, FUN_1409849b0(const_cast<void**>(&pRibbonTarget->m_hNode))));
    m_pPoints = pRibbonTarget->m_pPoints;
    FUN_1409f76f0(&m_spOwner, FUN_140a533d0(pTarget));
    if (m_spTarget.FUN_1409f77a0(0) || m_pPoints == 0)
        return false;

    m_fHalfWidth = pRibbon->m_fWidth * 0.5f;
    m_nQuality = pRibbon->m_nQuality;

    NiPointer<Unk_EffectNode> spRoot = new (efd::MemHint(efd::MemHint::NONE)) Unk_EffectNode(0, 0);
    spRoot->SetName("Effect Root");
    FUN_1409f76f0(&m_spRoot, spRoot);

    if ((const char*)pRibbon->m_strNifPath == 0)
    {
        m_spMesh = new (efd::MemHint(efd::MemHint::NONE)) CMesh(false, true, m_nUVSets, 0x1f42, 8000, 0x15);
        m_spMesh->GetMesh()->SetName("RibbonEffect");
        NiPointer<NiTexturingProperty> spTexture = new (efd::MemHint(efd::MemHint::NONE)) NiTexturingProperty;
        FUN_1409807b0(spTexture.operator->(), 0);
        FUN_1409805c0(spTexture.operator->(), 1);
        FUN_1409806e0(spTexture.operator->(), 0);
        {
            CString strDir("Effect/Textures");
            Unk_PPSmartC spImage = FUN_140a0afd0()->FUN_141552f90(CString((const char*)FUN_140cc2ba0(strDir, pRibbon->m_strTexturePath)), 5);
            FUN_140980880(spTexture.operator->(), spImage.Get());
        }
        FUN_140980200(m_spMesh->GetMesh(), spTexture);

        NiPointer<NiVertexColorProperty> spVertexColor = new (efd::MemHint(efd::MemHint::NONE)) NiVertexColorProperty;
        FUN_140980f20(spVertexColor.operator->(), 2);
        FUN_140980e60(spVertexColor.operator->(), 1);
        FUN_140980200(m_spMesh->GetMesh(), spVertexColor);

        NiPointer<NiAlphaProperty> spAlpha = new (efd::MemHint(efd::MemHint::NONE)) NiAlphaProperty;
        FUN_140980560(spAlpha.operator->(), true);
        int nAlphaMode = pRibbon->m_nAlphaMode;
        if (nAlphaMode == 0)
        {
            FUN_140980f60(spAlpha.operator->(), 6);
            FUN_140980af0(spAlpha.operator->(), 0);
        }
        else if (nAlphaMode == 1)
        {
            FUN_140980f60(spAlpha.operator->(), 6);
            FUN_140980af0(spAlpha.operator->(), 7);
        }
        else if (nAlphaMode == 2)
        {
            FUN_140980f60(spAlpha.operator->(), 0);
            FUN_140980af0(spAlpha.operator->(), 0);
        }
        FUN_140980200(m_spMesh->GetMesh(), spAlpha);

        NiPointer<NiFogProperty> spFog = new (efd::MemHint(efd::MemHint::NONE)) NiFogProperty;
        FUN_1409a9b90(spFog.operator->(), 0);
        FUN_140980200(m_spMesh->GetMesh(), spFog);

        NiPointer<NiWireframeProperty> spWireframe = new (efd::MemHint(efd::MemHint::NONE)) NiWireframeProperty;
        FUN_140a0b6c0(spWireframe.operator->(), false);
        FUN_140980200(m_spMesh->GetMesh(), spWireframe);

        NiPointer<NiStencilProperty> spStencil = new (efd::MemHint(efd::MemHint::NONE)) NiStencilProperty;
        spStencil->SetDrawMode(NiStencilProperty::DRAW_BOTH);
        FUN_140980200(m_spMesh->GetMesh(), spStencil);

        NiPointer<NiZBufferProperty> spZBuffer = new (efd::MemHint(efd::MemHint::NONE)) NiZBufferProperty;
        FUN_140981100(spZBuffer.operator->(), 0);
        FUN_140980200(m_spMesh->GetMesh(), spZBuffer);
    }
    else
    {
        CString strDir("Effect");
        NiAVObjectPtr spModel = FUN_140a0afd0()->FUN_141551ea0(FUN_140cc2ba0(strDir, pRibbon->m_strNifPath), false, 5, 0, 0);
        NiMesh* pFound = 0;
        Unk_SceneWalker kWalker(static_cast<NiObject*>(FUN_1409849b0(&spModel)));
        for (;;)
        {
            NiAVObject* pObj = kWalker.Next(true);
            if (pObj == 0)
                break;
            if (FUN_14109a9a0(&NiMesh::ms_RTTI, pObj))
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
        Unk_PropList* pList = FUN_14127cc40(pFound);
        void* pPos = FUN_14098ddb0(pList);
        while (pPos != 0)
        {
            NiProperty* pProp = FUN_140993f00(FUN_14098de00(pList, &pPos));
            if (FUN_14109a9a0(&NiTexturingProperty::ms_RTTI, pProp))
            {
                for (NiTimeController* pCtrl = FUN_14098dc80(pProp); pCtrl != 0; pCtrl = FUN_14098de40(pCtrl))
                    FUN_1416f18b0(pCtrl, 0);
            }
            FUN_140980200(pMeshObj, pProp);
        }
        if (pMeshObj->GetProperty(9) != 0)
            pMeshObj->RemoveProperty(9);
        NiPointer<NiVertexColorProperty> spVertexColor = new (efd::MemHint(efd::MemHint::NONE)) NiVertexColorProperty;
        FUN_140980f20(spVertexColor.operator->(), 2);
        FUN_140980e60(spVertexColor.operator->(), 1);
        FUN_140980200(pMeshObj, spVertexColor);
        if (pMeshObj->GetProperty(7) == 0)
        {
            NiPointer<NiStencilProperty> spStencil = new (efd::MemHint(efd::MemHint::NONE)) NiStencilProperty;
            spStencil->SetDrawMode(NiStencilProperty::DRAW_BOTH);
            FUN_140980200(pMeshObj, spStencil);
        }
        if (pMeshObj->GetProperty(0xb) == 0)
        {
            NiPointer<NiZBufferProperty> spZBuffer = new (efd::MemHint(efd::MemHint::NONE)) NiZBufferProperty;
            FUN_140981100(spZBuffer.operator->(), 0);
            FUN_140980200(pMeshObj, spZBuffer);
        }
        unsigned short nExtra = FUN_14106bc50(pFound);
        for (unsigned short i = 0; i < nExtra; ++i)
        {
            NiExtraData* pExtra = FUN_14106bc30(pFound, i);
            m_spMesh->GetMesh()->AddExtraData(pExtra);
        }
        FUN_141d18aa0(m_spMesh->GetMesh(), FUN_14098dc80(pFound));
    }
    m_spMesh->UpdateBound();
    FUN_1415672e0(m_spMesh->GetMesh(), 0);
    static_cast<NiNode*>(FUN_1409475f0(&m_spRoot))->AttachChild(m_spMesh->GetMesh(), false);
    if (FUN_14028d470(pRibbon->m_fStartDelay, 0.0f))
        vfunc_4();
    return true;
}

// @0x141702a50
bool CRibbonEffect::vfunc_9()
{
    if (CEffect::vfunc_9())
    {
        if ((FUN_1409475d0(&m_spRoot) ? true : false) && FUN_14098dad0(FUN_1409475f0(&m_spRoot)))
            return true;
        UpdateMesh();
        return true;
    }
    return false;
}

// @0x141702ae0
void CRibbonEffect::vfunc_4()
{
    if (FUN_1409475d0(&m_spOwner) != 0)
        static_cast<NiNode*>(FUN_1409475f0(&m_spOwner))->AttachChild(static_cast<NiAVObject*>(FUN_1409475d0(&m_spRoot)), true);
    static_cast<NiAVObject*>(FUN_1409475f0(&m_spRoot))->UpdateEffects();
    static_cast<NiAVObject*>(FUN_1409475f0(&m_spRoot))->UpdateProperties();
    FUN_141d16040(FUN_1409475f0(&m_spRoot), (float)FUN_14086d260()->FUN_141473280(), true);
    m_b2e = true;
}

// @0x141702bd0
void CRibbonEffect::vfunc_7()
{
    FUN_140a0b2a0(static_cast<NiAVObject*>(FUN_1409475d0(&m_spRoot)));
}

// @0x141702c00
void CRibbonEffect::vfunc_10(bool bVisible)
{
    FUN_140a0b300(static_cast<NiAVObject*>(FUN_1409475f0(&m_spRoot)), !bVisible);
}

// @0x141702c50
int CRibbonEffect::vfunc_8(void* p)
{
    *static_cast<Vector3*>(p) = FUN_140947900(FUN_1409475f0(&m_spRoot));
    return 1;
}

// @0x141702d00
// MS2-FUNCTIONAL: frame and temporaries differ from the exe.
// Samples the Catmull-Rom curve through the points (m_nQuality samples per segment), then rewrites the strip: two
// vertex rows (the curve offset by half the width to both sides along the camera-facing side vector) with an alpha
// ramp along the strip, the uv rows and the 2 triangles per curve segment.
void CRibbonEffect::UpdateMesh()
{
    unsigned nPoints = (unsigned)m_pPoints->GetCount();
    if (3 < nPoints)
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
        Vector3 kCamera = Unk_CameraManager::FUN_1409478c0()->FUN_140af0250();
        efd::vector<Vector3> kMinus;
        efd::vector<Vector3> kPlus;
        for (unsigned i = 0; i < kCurve.size(); ++i)
        {
            Vector3 kDir;
            if (i == 0)
                kDir = kCurve[1].FUN_140965c40(kCurve[0]);
            else if (i == kCurve.size() - 1)
                kDir = kCurve[i].FUN_140965c40(kCurve[i - 1]);
            else
                kDir = kCurve[i + 1].FUN_140965c40(kCurve[i - 1]);
            kDir.FUN_140968990();
            Vector3 kSide = kDir.FUN_140a00e10(kCamera);
            kMinus.push_back(kCurve[i].FUN_140965c40(FUN_1409ab5c0(m_fHalfWidth, kSide)));
            kPlus.push_back(kCurve[i].FUN_14097fd50(FUN_1409ab5c0(m_fHalfWidth, kSide)));
        }

        unsigned short nCount = (unsigned short)kMinus.size();
        NiPoint3* pPos = (NiPoint3*)m_spMesh->Lock(NiCommonSemantics::POSITION(), 0, 2);
        NiColorA* pCol = (NiColorA*)m_spMesh->Lock(NiCommonSemantics::COLOR(), 0, 2);
        for (int i = 0; i < (int)nCount; ++i)
        {
            float fU = (float)i / (float)nCount;
            float fRamp = FUN_140a17940((fU - m_fFadeStart) / (m_fFadeEnd - m_fFadeStart), 0.0f, 1.0f);
            float fAlpha = m_fAlphaFrom + fRamp * (m_fAlphaTo - m_fAlphaFrom);
            NiColorA kColor(0.0f, 0.0f, 0.0f, fAlpha);
            pPos[i] = NiPoint3(kMinus[i].x, kMinus[i].y, kMinus[i].z);
            pCol[i] = kColor;
            pPos[i + nCount] = NiPoint3(kPlus[i].x, kPlus[i].y, kPlus[i].z);
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
