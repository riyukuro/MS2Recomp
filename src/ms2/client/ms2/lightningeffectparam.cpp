// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The "Lightning" effect: param + runtime effect.
// MS2-UNIT: ?\lightningeffectparam.cpp
// MS2-RANGE: 0x1400f7340-0x1400f73f0 .text$di
// MS2-RANGE: 0x14144b790-0x14144df10 .text$mn
// manual pins (identical-body SmartPointer COMDATs tplpin cannot tell apart)
// MS2-PIN: ??0?$SmartPointer@VNiSortAdjustNode@@@efd@@QEAA@PEAVNiSortAdjustNode@@@Z 0x14144db00
// MS2-PIN: ??1?$SmartPointer@VNiSortAdjustNode@@@efd@@QEAA@XZ 0x14144db90
// MS2-PIN: ??B?$SmartPointer@VNiSortAdjustNode@@@efd@@QEBAPEAVNiSortAdjustNode@@XZ 0x14144dcf0
// MS2-PIN: ??C?$SmartPointer@VNiSortAdjustNode@@@efd@@QEBAPEAVNiSortAdjustNode@@XZ 0x14144dd00
// MS2-PIN: ??A?$CAtlArray@UUnk_StreamPoint@@V?$CElementTraits@UUnk_StreamPoint@@@ATL@@@ATL@@QEAAAEAUUnk_StreamPoint@@_K@Z 0x14144dcb0
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??0?$MS2Ptr@VLightningEffectParam@@@@QEAA@PEAVLightningEffectParam@@@Z 0x14144db40 ; unique
// MS2-PIN: ?AssignRaw@?$MS2Ptr@VLightningEffectParam@@@@QEAAAEAV1@PEAVLightningEffectParam@@@Z 0x14144dc40 ; unique
// MS2-PIN: ?SetSortingMode@NiSortAdjustNode@@QEAAXW4SortingMode@1@@Z 0x14144dde0 ; unique
// MS2-PINS-END tplpin
#ifndef NOMINMAX
#define NOMINMAX
#endif
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\lightningeffectparam.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "lightningeffectparam.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/postprocesseffect.h"      // Unk_PPSmartC
#include "ms2/client/ms2/cameramode.h"              // Unk_CameraManager
#include <efd/MemoryDefines.h>
#include <NiNode.h>
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
#include <NiSortAdjustNode.h>
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- out-of-unit types and callees (bound to the exe by their FUN_<va> names / symbols) ----
// Game TinyXML element and attribute helpers (commonfiles\tinyxmlhelper.cpp).
class Unk_140165cf0;
const char* FUN_14086f4b0(Unk_140165cf0* pNode, const char* pszName);
int FUN_140873360(Unk_140165cf0* pNode, const char* pszName, float& fOut);
int FUN_1408732a0(Unk_140165cf0* pNode, const char* pszName, unsigned int& nOut);
int FUN_1408730a0(Unk_140165cf0* pNode, const char* pszName, bool& bOut);
CString FUN_140188f50(const char* psz, int n);                      // null-safe CString
int FUN_1401788f0(Unk_140165cf0* pNode, const char* pszName, ATL::CAtlArray<CString>& arr);   // split to list

bool FUN_14028d470(float a, float b);                               // nearly equal
class Unk_GameClock { public: double FUN_141473280(); };
Unk_GameClock* FUN_14086d260();
void* FUN_1409849b0(void* pHandle);                                 // handle -> node pointer
void* FUN_14098d8d0(const void* pRtti, void* pObj);                 // dynamic cast through an NiRTTI
const Unk_StreamPoint& FUN_140947900(void* pNode);                  // world translate
void FUN_141d16040(void* pNode, float fTime, bool bUpdateControllers);    // NiAVObject::Update
void FUN_140a0b2a0(void* pNode);                                    // detach the node from its parent
void FUN_140a0b300(void* pNode, bool bCulled);                      // NiAVObject::SetAppCulled
bool FUN_14098dad0(void* pNode);                                    // node is app-culled
class Unk_1403ed280 { public: void* FUN_1411a6b10(); };             // the effect manager: scene root
Unk_1403ed280* FUN_1403ed280();

// Random float (about -1..1), tick counter, camera direction.
float FUN_14109ace0();
unsigned int FUN_140869420();

// Resource manager (singleton 0x140a0afd0): texture load by path. 0x140cc2ba0 joins directory + file name.
class Unk_ResourceMgr
{
public:
    Unk_PPSmartC FUN_141552f90(CString strPath, int nFlags);
};
Unk_ResourceMgr* FUN_140a0afd0();
CString FUN_140cc2ba0(const CString& strDir, const CString& strName);

// Elements of the target's point list (CAtlArray operator[] / GetCount instances of another obj).
Unk_StreamPoint* FUN_140a0af70(ATL::CAtlArray<Unk_StreamPoint>* pArr, __int64 nIndex);
int FUN_140a0afb0(ATL::CAtlArray<Unk_StreamPoint>* pArr);

// NiProperty setters (NiMain inline members the exe instantiated in other objs).
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
void FUN_140a0b6c0(NiWireframeProperty* pProp, int n);
void FUN_140a0b450(NiStencilProperty* pProp, int n);
void FUN_140981100(NiZBufferProperty* pProp, int n);
void FUN_1415672e0(NiAVObject* pObj, int n);

// The effect node (400 bytes) carries the effect-space point.
class Unk_EffectNode : public NiNode
{
public:
    Unk_EffectNode(int nA, int nB);                                 // 0x1411a34b0
    char m_pad_node[400 - sizeof(NiNode)];
};
MS2_CHECK_SIZE(Unk_EffectNode, 400);

// The effect target (CEffect::vfunc_3's second argument), the part this unit reads.
struct Unk_LightningTarget
{
    char m_pad_00[0x10];
    void* m_hNode;                                  // +0x10 handle of the owner's scene node
    char m_pad_18[0x10];
    ATL::CAtlArray<Unk_StreamPoint>* m_pPoints;     // +0x28 the two (or more) end points
};
MS2_CHECK_OFFSET(Unk_LightningTarget, m_hNode, 0x10);
MS2_CHECK_OFFSET(Unk_LightningTarget, m_pPoints, 0x28);

#ifndef MS2_HOOK_DLL
// File statics of this TU (initialised by the .text$di entries).
const NiRTTI LightningEffect::ms_RTTI("LightningEffect", &CEffect::ms_RTTI);        // @0x1400f7340
static CString s_str143adc918("skill");                                              // @0x1400f7370
static CString s_str143adc910("stun");                                               // @0x1400f73a0
class Unk_Handle1401cd100 { public: Unk_Handle1401cd100(int nNull); void* m_p; };     // ctor 0x1401cd100
static Unk_Handle1401cd100 s_dat_143adc920(0);                                       // @0x1400f73d0
#else
const NiRTTI LightningEffect::ms_RTTI("LightningEffect", &CEffect::ms_RTTI);
#endif

// @0x14144b790
LightningEffectParam::LightningEffectParam()
    : CEffectParam(0x10), m_fSpread(1.0f), m_fJointLen(32.0f), m_fWidth(10.0f), m_nAlphaMode(0), m_nSortingMode(0),
      m_nTextureChangeTick(0), m_bTextureSequence(false)
{
}

// @0x14144b880
void LightningEffectParam::vfunc_1(Unk_140165cf0* pNode)
{
    CEffectParam::vfunc_1(pNode);
    FUN_1401788f0(pNode, "texturePathA", m_arrTexture[0]);
    FUN_1401788f0(pNode, "texturePathB", m_arrTexture[1]);
    FUN_1401788f0(pNode, "texturePathC", m_arrTexture[2]);
    FUN_140873360(pNode, "spread", m_fSpread);
    FUN_140873360(pNode, "jointLen", m_fJointLen);
    FUN_140873360(pNode, "width", m_fWidth);
    FUN_1408732a0(pNode, "textureChangeTick", m_nTextureChangeTick);
    FUN_1408730a0(pNode, "textureSequence", m_bTextureSequence);
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
    CString strSorting = FUN_140188f50(FUN_14086f4b0(pNode, "sortingMode"), 0);
    if (strSorting.GetLength() > 0)
    {
        if (strSorting.CompareNoCase("INHERIT") == 0)
        {
            m_nSortingMode = 1;
        }
        else
        {
            if (strSorting.CompareNoCase("OFF") == 0)
                m_nSortingMode = 0;
        }
    }
}

// @0x14144bb00
CEffectPtr LightningEffectParam::vfunc_6()
{
    return new (efd::MemHint(efd::MemHint::NONE)) LightningEffect;
}

// @0x14144bba0
LightningEffect::LightningEffect()
    : m_spRoot(0), m_sp38(0), m_spMesh(0), m_spTarget(0), m_nUVSets(1), m_bSequence(false), m_nSequence(0),
      m_nTick(0), m_nLastTick(0), m_spTexProp(0)
{
}

// @0x14144bce0
LightningEffect::~LightningEffect()
{
    vfunc_7();
    m_spTexProp = 0;
}

// @0x14144bdf0
// MS2-FUNCTIONAL: frame 0x10 smaller than the exe (temporaries of the eight new-expressions are laid out differently).
bool LightningEffect::vfunc_3(const CEffectParam* pParam, Unk_EffectTarget* pTarget)
{
    if (!CEffect::vfunc_3(pParam, pTarget))
        return false;
    const LightningEffectParam* pLightning = static_cast<const LightningEffectParam*>(pParam);
    FUN_1409f76f0(&m_spTarget, FUN_14098d8d0(&NiNode::ms_RTTI, FUN_1409849b0(const_cast<void**>(&reinterpret_cast<const Unk_LightningTarget*>(pTarget)->m_hNode))));
    m_pPoints = reinterpret_cast<const Unk_LightningTarget*>(pTarget)->m_pPoints;
    m_fSpread = pLightning->m_fSpread;
    m_fJointLen = pLightning->m_fJointLen;
    m_fWidth = pLightning->m_fWidth;
    m_bSequence = pLightning->m_bTextureSequence;
    m_nTick = pLightning->m_nTextureChangeTick;
    if (m_spTarget.FUN_1409f77a0(0) || m_pPoints == 0)
        return false;

    m_spParam.AssignRaw(const_cast<LightningEffectParam*>(pLightning));

    NiPointer<Unk_EffectNode> spRoot = new (efd::MemHint(efd::MemHint::NONE)) Unk_EffectNode(0, 0);
    spRoot->SetName("Effect Root");
    FUN_1409f76f0(&m_spRoot, spRoot);

    m_spMesh = new (efd::MemHint(efd::MemHint::NONE)) CMesh(false, true, m_nUVSets, 0x1f42, 8000, 0x15);
    m_spMesh->GetMesh()->SetName("LightningEffect");

    m_spTexProp = new (efd::MemHint(efd::MemHint::NONE)) NiTexturingProperty;
    FUN_1409807b0(m_spTexProp, 0);
    FUN_1409805c0(m_spTexProp, 1);
    FUN_1409806e0(m_spTexProp, 0);
    FUN_140980200(m_spMesh->GetMesh(), m_spTexProp);

    NiVertexColorProperty* pVertexColor = new (efd::MemHint(efd::MemHint::NONE)) NiVertexColorProperty;
    FUN_140980f20(pVertexColor, 1);
    FUN_140980e60(pVertexColor, 0);
    FUN_140980200(m_spMesh->GetMesh(), pVertexColor);

    NiAlphaProperty* pAlpha = new (efd::MemHint(efd::MemHint::NONE)) NiAlphaProperty;
    FUN_140980560(pAlpha, true);
    if (pLightning->m_nAlphaMode == 0)
    {
        FUN_140980f60(pAlpha, 6);
        FUN_140980af0(pAlpha, 0);
    }
    else if (pLightning->m_nAlphaMode == 1)
    {
        FUN_140980f60(pAlpha, 6);
        FUN_140980af0(pAlpha, 7);
    }
    else if (pLightning->m_nAlphaMode == 2)
    {
        FUN_140980f60(pAlpha, 0);
        FUN_140980af0(pAlpha, 0);
    }
    FUN_140980200(m_spMesh->GetMesh(), pAlpha);

    NiFogProperty* pFog = new (efd::MemHint(efd::MemHint::NONE)) NiFogProperty;
    FUN_1409a9b90(pFog, 0);
    FUN_140980200(m_spMesh->GetMesh(), pFog);

    NiWireframeProperty* pWireframe = new (efd::MemHint(efd::MemHint::NONE)) NiWireframeProperty;
    FUN_140a0b6c0(pWireframe, 0);
    FUN_140980200(m_spMesh->GetMesh(), pWireframe);

    NiStencilProperty* pStencil = new (efd::MemHint(efd::MemHint::NONE)) NiStencilProperty;
    FUN_140a0b450(pStencil, 3);
    FUN_140980200(m_spMesh->GetMesh(), pStencil);

    NiZBufferProperty* pZBuffer = new (efd::MemHint(efd::MemHint::NONE)) NiZBufferProperty;
    FUN_140981100(pZBuffer, 0);
    FUN_140980200(m_spMesh->GetMesh(), pZBuffer);

    m_spMesh->UpdateBound();
    FUN_1415672e0(m_spMesh->GetMesh(), 0);
    static_cast<NiNode*>(FUN_1409475f0(&m_spRoot))->AttachChild(m_spMesh->GetMesh(), false);

    NiPointer<NiSortAdjustNode> spSort = new (efd::MemHint(efd::MemHint::NONE)) NiSortAdjustNode;
    if (pLightning->m_nSortingMode == 1)
        spSort->SetSortingMode(NiSortAdjustNode::SORTING_INHERIT);
    else
        spSort->SetSortingMode(NiSortAdjustNode::SORTING_OFF);
    static_cast<NiNode*>(FUN_1409475f0(&m_spRoot))->AttachChild(spSort, false);
    spSort->AttachChild(m_spMesh->GetMesh(), false);

    if (FUN_14028d470(pLightning->m_fStartDelay, 0.0f))
        vfunc_4();
    return true;
}

// @0x14144c9e0
bool LightningEffect::vfunc_9()
{
    if (CEffect::vfunc_9())
    {
        if (FUN_1409475d0(&m_spRoot) ? true : false)
        {
            if (FUN_14098dad0(FUN_1409475f0(&m_spRoot)))
                return true;
        }
        Rebuild();
        return true;
    }
    return false;
}

// @0x14144ca70
void LightningEffect::vfunc_4()
{
    static_cast<NiNode*>(FUN_1403ed280()->FUN_1411a6b10())->AttachChild(static_cast<NiAVObject*>(FUN_1409475d0(&m_spRoot)), true);
    static_cast<NiAVObject*>(FUN_1409475f0(&m_spRoot))->UpdateEffects();
    static_cast<NiAVObject*>(FUN_1409475f0(&m_spRoot))->UpdateProperties();
    FUN_141d16040(FUN_1409475f0(&m_spRoot), (float)FUN_14086d260()->FUN_141473280(), true);
    m_b2e = true;
}

// @0x14144cb50
void LightningEffect::vfunc_7()
{
    FUN_140a0b2a0(FUN_1409475d0(&m_spRoot));
}

// @0x14144cb80
void LightningEffect::vfunc_10(bool bVisible)
{
    FUN_140a0b300(FUN_1409475f0(&m_spRoot), !bVisible);
}

// @0x14144cbd0
int LightningEffect::vfunc_8(void* p)
{
    if (FUN_1409475d0(&m_spTarget) != 0)
    {
        *static_cast<Unk_StreamPoint*>(p) = FUN_140947900(FUN_1409475f0(&m_spTarget));
        return 1;
    }
    return 0;
}

// @0x14144cc30
// MS2-FUNCTIONAL: 200 bytes longer than the exe (the texture / string temporaries are not recovered exactly).
// Picks a texture for the distance class (<=256 near, <=512 mid, far) and every m_nTick ms rebuilds the jagged path
// from the first to the last point of the target's list and the strip mesh (two vertex rows, left / right edge).
void LightningEffect::Rebuild()
{
    int nPoints = FUN_140a0afb0(m_pPoints);
    if (1 < nPoints)
    {
        Unk_StreamPoint kFirst = *FUN_140a0af70(m_pPoints, 0);
        Unk_StreamPoint kLast = *FUN_140a0af70(m_pPoints, nPoints - 1);
        float fDist = kLast.FUN_140965c40(kFirst).FUN_140967ac0();
        int nClass = 2;
        if (256.0f < fDist)
        {
            if (fDist <= 512.0f)
                nClass = 1;
        }
        else
        {
            nClass = 0;
        }
        bool bUpdate = true;
        if (m_nTick != 0)
        {
            unsigned int nNow = FUN_140869420();
            if (nNow < m_nLastTick + m_nTick)
                bUpdate = false;
            else
                m_nLastTick = nNow;
        }
        if (bUpdate)
        {
            unsigned __int64 nIndex = 0;
            ATL::CAtlArray<CString>& arrTex = m_spParam->m_arrTexture[nClass];
            unsigned __int64 nTextures = arrTex.GetCount();
            if (nTextures != 0)
            {
                if (!m_bSequence)
                {
                    nIndex = (unsigned __int64)(__int64)rand() % nTextures;
                }
                else
                {
                    nIndex = (m_nSequence + 1) % nTextures;
                    m_nSequence = nIndex;
                }
            }
            CString strName = arrTex[(size_t)nIndex];
            {
                CString strDir("Effect/Textures");
                Unk_PPSmartC spTexture = FUN_140a0afd0()->FUN_141552f90(FUN_140cc2ba0(strDir, strName), 5);
                FUN_140980880(m_spTexProp, spTexture.Get());
            }
            m_spMesh->GetMesh()->UpdateProperties();
            BuildPath(kFirst, kLast);

            unsigned short nCount = (unsigned short)m_arrLeft.GetCount();
            NiPoint3* pPos = (NiPoint3*)m_spMesh->Lock(NiCommonSemantics::POSITION(), 0, 2);
            if (pPos == 0)
                return;
            NiColorA* pCol = (NiColorA*)m_spMesh->Lock(NiCommonSemantics::COLOR(), 0, 2);
            if (pCol == 0)
            {
                m_spMesh->Unlock(NiCommonSemantics::POSITION(), 0, 2);
                return;
            }
            for (int i = 0; i < (int)nCount; ++i)
            {
                NiColorA kWhite(1.0f, 1.0f, 1.0f, 1.0f);
                pPos[i] = NiPoint3(m_arrLeft[i].x, m_arrLeft[i].y, m_arrLeft[i].z);
                pCol[i] = kWhite;
                pPos[i + nCount] = NiPoint3(m_arrRight[i].x, m_arrRight[i].y, m_arrRight[i].z);
                pCol[i + nCount] = kWhite;
            }
            m_spMesh->Unlock(NiCommonSemantics::POSITION(), 0, 2);
            m_spMesh->Unlock(NiCommonSemantics::COLOR(), 0, 2);
            for (int nSet = 0; nSet < m_nUVSets; ++nSet)
            {
                NiPoint2* pUV = (NiPoint2*)m_spMesh->Lock(NiCommonSemantics::TEXCOORD(), nSet, 2);
                if (pUV == 0)
                    return;
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
            if (pIdx == 0)
                return;
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
}

// @0x14144d670
// MS2-FUNCTIONAL: frame 0x10 smaller (the exe copies the camera direction out of a separate temporary).
// Random walk from kStart toward kEnd in steps of m_fJointLen (at most 100 points); then the two edge lines are the
// path offset by +-width/2 along the horizontal direction crossed with the camera direction.
void LightningEffect::BuildPath(Unk_StreamPoint kStart, Unk_StreamPoint kEnd)
{
    m_arrPath.RemoveAll();
    Unk_StreamPoint kLast;
    Unk_StreamPoint kCur = kStart;
    Unk_StreamPoint kStep;
    Unk_StreamPoint kDelta = kEnd.FUN_140965c40(kStart);
    Unk_StreamPoint kDir = kDelta;
    kDir.FUN_140968990();
    m_arrPath.Add(kStart);
    float fAlong = 0.0f;
    float fRemain;
    do
    {
        kLast = kCur;
        kStep = kEnd.FUN_140965c40(kLast);
        float fDx = FUN_14109ace0() * m_fSpread * kStep.y;
        kStep.y = kStep.y + FUN_14109ace0() * m_fSpread * kStep.x;
        kStep.x = kStep.x + fDx;
        kStep.FUN_140968990();
        kStep.x = kStep.x * m_fJointLen;
        kStep.y = kStep.y * m_fJointLen;
        kCur.x = kCur.x + kStep.x;
        kCur.y = kCur.y + kStep.y;
        Unk_StreamPoint kRel = kCur.FUN_140965c40(kStart);
        fAlong = kDir.FUN_140a00f20(kRel);
        kCur.z = kStart.z + kDir.z * fAlong;
        m_arrPath.Add(kCur);
        if (m_arrPath.GetCount() >= 100)
            break;
        fRemain = kEnd.FUN_140965c40(kCur).FUN_140967ac0();
    } while (!(fRemain <= m_fJointLen * 2.0f || fAlong <= 0.0f));
    m_arrPath.Add(kEnd);
    m_arrLeft.RemoveAll();
    m_arrRight.RemoveAll();
    Unk_StreamPoint kFlat = kDelta;
    kFlat.z = 0.0f;
    kFlat.FUN_140968990();
    Unk_StreamPoint kCamera = Unk_CameraManager::FUN_1409478c0()->FUN_140af0250();
    Unk_StreamPoint kSide = kFlat.FUN_140a00e10(kCamera);
    for (int i = 0; i < (int)m_arrPath.GetCount(); ++i)
    {
        Unk_StreamPoint kPoint = m_arrPath[i];
        m_arrLeft.Add(kPoint.FUN_14097fd50(kSide.FUN_14097fc90(m_fWidth).FUN_14097fc90(0.5f)));
        m_arrRight.Add(kPoint.FUN_14097fd50(kSide.FUN_14097fc90(m_fWidth).FUN_14097fc90(-0.5f)));
    }
}

// @0x14144ddc0
int LightningEffect::vfunc_12()
{
    return 0x10;
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cb24a0-0x142cb24e0 .text$yd
