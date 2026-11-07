// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The "Lightning" effect: param + runtime effect.
// MS2-UNIT: ?\lightningeffectparam.cpp
// MS2-RANGE: 0x1400f7340-0x1400f73f0 .text$di
// MS2-RANGE: 0x14144b790-0x14144df10 .text$mn
// manual pins (identical-body SmartPointer COMDATs tplpin cannot tell apart)
// MS2-PIN: ??0?$SmartPointer@VNiSortAdjustNode@@@efd@@QEAA@PEAVNiSortAdjustNode@@@Z 0x14144db00
// MS2-PIN: ??1?$SmartPointer@VNiSortAdjustNode@@@efd@@QEAA@XZ 0x14144db90
// MS2-PIN: ??B?$SmartPointer@VNiSortAdjustNode@@@efd@@QEBAPEAVNiSortAdjustNode@@XZ 0x14144dcf0
// MS2-PIN: ??C?$SmartPointer@VNiSortAdjustNode@@@efd@@QEBAPEAVNiSortAdjustNode@@XZ 0x14144dd00
// MS2-PIN: ??A?$CAtlArray@VPoint3@efd@@V?$CElementTraits@VPoint3@efd@@@ATL@@@ATL@@QEAAAEAVPoint3@efd@@_K@Z 0x14144dcb0
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
#include "ms2/placeholder/postprocesseffect.h"      // efd::SmartPointer<NiTexture>
#include "ms2/client/ms2/cameramode.h"              // CCameraMode, Unk_CameraSetting
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
#include "ms2/placeholder/cmainsystem.h"
#include "ms2/client/ms2/effectservice.h"
#include "ms2/client/ms2/nifeffectparam.h"   // C3: CNifLoadingService::GetTexture
#include "ms2/placeholder/xmlattr.h"         // C3: XmlTokenList
#include <NiTexturingProperty.h>
#include <NiAVObject.h>
class CameraMgr;
template <> class TSingleton<CameraMgr> { public: static CameraMgr* GetInstance(); };   // C3: 0x1409478c0, as camera.h declares it

// ---- out-of-unit types and callees (bound to the exe by their FUN_<va> names / symbols) ----
// Game TinyXML element and attribute helpers (commonfiles\tinyxmlhelper.cpp).
class TiXmlElement;
#include "ms2/placeholder/tixmlelement.h"   // C3: was a local TiXml view; the shared reduced view has the same names
//
//
//
//
int XmlGetAttr(class TiXmlElement*, char const*, float&);   // C3: was FUN_140873360
int XmlGetAttr(class TiXmlElement*, char const*, unsigned long&);   // C3: was FUN_1408732a0
int XmlGetAttr(class TiXmlElement*, char const*, bool&);   // C3: was FUN_1408730a0
CString FUN_140188f50(const char* psz, int n);                      // null-safe CString
Vector3* FUN_140a0af70(ATL::CAtlArray<Vector3>* pArr, __int64 nIndex);

bool FUN_14028d470(float a, float b);                               // nearly equal
class CMainSystem;
// The camera direction 0x140af0250 returns NiPoint3; BuildPath keeps only its efd::Point3 part (a slicing copy).
class CameraMgr { public: NiPoint3 FUN_140af0250(); };
void FUN_140a0b2a0(class NiAVObject*);   // C3: was FUN_140a0b2a0

// Random float (about -1..1), tick counter, camera direction.
float FUN_14109ace0();
unsigned long GetTickCountMs2();   // C3: was FUN_140869420

// Resource manager (singleton 0x140a0afd0): texture load by path. 0x140cc2ba0 joins directory + file name.
class Unk_ResourceMgr* FUN_140a0afd0();
CString FUN_140cc2ba0(const CString& strDir, const CString& strName);

// Elements of the target's point list (CAtlArray operator[] / GetCount instances of another obj).

// NiProperty setters (NiMain inline members the exe instantiated in other objs).
void FUN_1415672e0(NiAVObject*, bool);


// The effect target (CEffect::vfunc_3's second argument), the part this unit reads.
struct Unk_LightningTarget
{
    char m_pad_00[0x10];
    NiAVObjectPtr m_hNode;                          // +0x10 the owner's scene node
    char m_pad_18[0x10];
    ATL::CAtlArray<Vector3>* m_pPoints;     // +0x28 the two (or more) end points
};
MS2_CHECK_OFFSET(Unk_LightningTarget, m_hNode, 0x10);
MS2_CHECK_OFFSET(Unk_LightningTarget, m_pPoints, 0x28);

#ifndef MS2_HOOK_DLL
// File statics of this TU (initialised by the .text$di entries).
const NiRTTI LightningEffect::ms_RTTI("LightningEffect", &CEffect::ms_RTTI);        // @0x1400f7340
static CString s_str143adc918("skill");                                              // @0x1400f7370
static CString s_str143adc910("stun");                                               // @0x1400f73a0
#include <egf/EntityID.h>   // B22: was class Unk_BuddyHandle (ctor 0x1401cd100 = egf::EntityID(efd::UInt64))
static egf::EntityID s_dat_143adc920(0);                                         // @0x1400f73d0
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
void LightningEffectParam::vfunc_1(TiXmlElement* pNode)
{
    CEffectParam::vfunc_1(pNode);
    XmlTokenList(pNode, "texturePathA", m_arrTexture[0]);
    XmlTokenList(pNode, "texturePathB", m_arrTexture[1]);
    XmlTokenList(pNode, "texturePathC", m_arrTexture[2]);
    XmlGetAttr((class TiXmlElement*)(pNode), "spread", m_fSpread);
    XmlGetAttr((class TiXmlElement*)(pNode), "jointLen", m_fJointLen);
    XmlGetAttr((class TiXmlElement*)(pNode), "width", m_fWidth);
    XmlGetAttr((class TiXmlElement*)(pNode), "textureChangeTick", *(unsigned long*)&(m_nTextureChangeTick));
    XmlGetAttr((class TiXmlElement*)(pNode), "textureSequence", m_bTextureSequence);
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
    CString strSorting = FUN_140188f50(((class TiXmlElement*)(class TiXmlElement*)(pNode))->Attribute("sortingMode"), 0);
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
bool LightningEffect::vfunc_3(const CEffectParam* pParam, Unk_EffectTarget* pTarget)
{
    if (!CEffect::vfunc_3(pParam, pTarget))
        return false;
    const LightningEffectParam* pLightning = static_cast<const LightningEffectParam*>(pParam);
    m_spTarget = reinterpret_cast<NiNode*>(((void*)NiObject::DynamicCast((class NiRTTI const*)(&NiNode::ms_RTTI), (class NiObject const*)((NiAVObject*)reinterpret_cast<const Unk_LightningTarget*>(pTarget)->m_hNode))));
    m_pPoints = reinterpret_cast<const Unk_LightningTarget*>(pTarget)->m_pPoints;
    m_fSpread = pLightning->m_fSpread;
    m_fJointLen = pLightning->m_fJointLen;
    m_fWidth = pLightning->m_fWidth;
    m_bSequence = pLightning->m_bTextureSequence;
    m_nTick = pLightning->m_nTextureChangeTick;
    if (m_spTarget == (NiNode*)0 || m_pPoints == 0)
        return false;

    m_spParam.AssignRaw(const_cast<LightningEffectParam*>(pLightning));

    NiPointer<EffectNode> spRoot = new (efd::MemHint(efd::MemHint::NONE)) EffectNode(false, false);
    spRoot->SetName("Effect Root");
    m_spRoot = spRoot;

    m_spMesh = new (efd::MemHint(efd::MemHint::NONE)) CMesh(false, true, m_nUVSets, 0x1f42, 8000, 0x15);
    m_spMesh->GetMesh()->SetName("LightningEffect");

    m_spTexProp = new (efd::MemHint(efd::MemHint::NONE)) NiTexturingProperty;
    reinterpret_cast<NiTexturingProperty*>(m_spTexProp.operator->())->SetBaseFilterMode((NiTexturingProperty::FilterMode)0);
    reinterpret_cast<NiTexturingProperty*>(m_spTexProp.operator->())->SetApplyMode((NiTexturingProperty::ApplyMode)1);
    reinterpret_cast<NiTexturingProperty*>(m_spTexProp.operator->())->SetBaseClampMode((NiTexturingProperty::ClampMode)0);
    m_spMesh->GetMesh()->AttachProperty(m_spTexProp);

    NiVertexColorProperty* pVertexColor = new (efd::MemHint(efd::MemHint::NONE)) NiVertexColorProperty;
    pVertexColor->SetSourceMode(NiVertexColorProperty::SOURCE_EMISSIVE);
    pVertexColor->SetLightingMode(NiVertexColorProperty::LIGHTING_E);
    m_spMesh->GetMesh()->AttachProperty(pVertexColor);

    NiAlphaProperty* pAlpha = new (efd::MemHint(efd::MemHint::NONE)) NiAlphaProperty;
    ((class NiAlphaProperty*)(class NiAlphaProperty*)(pAlpha))->SetAlphaBlending(true);
    switch (pLightning->m_nAlphaMode)
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
    m_spMesh->GetMesh()->AttachProperty(pAlpha);

    NiFogProperty* pFog = new (efd::MemHint(efd::MemHint::NONE)) NiFogProperty;
    pFog->SetFog(false);
    m_spMesh->GetMesh()->AttachProperty(pFog);

    NiWireframeProperty* pWireframe = new (efd::MemHint(efd::MemHint::NONE)) NiWireframeProperty;
    pWireframe->SetWireframe((bool)0);
    m_spMesh->GetMesh()->AttachProperty(pWireframe);

    NiStencilProperty* pStencil = new (efd::MemHint(efd::MemHint::NONE)) NiStencilProperty;
    pStencil->SetDrawMode((NiStencilProperty::DrawMode)3);
    m_spMesh->GetMesh()->AttachProperty(pStencil);

    NiZBufferProperty* pZBuffer = new (efd::MemHint(efd::MemHint::NONE)) NiZBufferProperty;
    pZBuffer->SetZBufferWrite(false);
    m_spMesh->GetMesh()->AttachProperty(pZBuffer);

    m_spMesh->UpdateBound();
    FUN_1415672e0(m_spMesh->GetMesh(), (bool)0);
    m_spRoot->AttachChild(m_spMesh->GetMesh(), false);

    NiPointer<NiSortAdjustNode> spSort = new (efd::MemHint(efd::MemHint::NONE)) NiSortAdjustNode;
    if (pLightning->m_nSortingMode == 1)
        spSort->SetSortingMode(NiSortAdjustNode::SORTING_INHERIT);
    else
        spSort->SetSortingMode(NiSortAdjustNode::SORTING_OFF);
    m_spRoot->AttachChild(spSort, false);
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
        if ((NiNode*)m_spRoot ? true : false)
        {
            if (m_spRoot->GetAppCulled())
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
    static_cast<NiNode*>(reinterpret_cast<CEffectService*>(TSingleton<CEffectService>::GetInstance())->GetLeastLoadedRoot())->AttachChild(static_cast<NiAVObject*>((NiNode*)m_spRoot), true);
    m_spRoot->UpdateEffects();
    m_spRoot->UpdateProperties();
    m_spRoot->Update((float)TSingleton<CMainSystem>::GetInstance()->FUN_141473280(), true);
    m_b2e = true;
}

// @0x14144cb50
void LightningEffect::vfunc_7()
{
    FUN_140a0b2a0((class NiAVObject*)((NiNode*)m_spRoot));
}

// @0x14144cb80
void LightningEffect::vfunc_10(bool bVisible)
{
    m_spRoot->SetAppCulled(!bVisible);
}

// @0x14144cbd0
int LightningEffect::vfunc_8(void* p)
{
    if ((NiNode*)m_spTarget != 0)
    {
        *static_cast<Vector3*>(p) = reinterpret_cast<const Vector3&>(m_spTarget->GetWorldTranslate());
        return 1;
    }
    return 0;
}

// @0x14144cc30
// Picks a texture for the distance class (<=256 near, <=512 mid, far) and every m_nTick ms rebuilds the jagged path
// from the first to the last point of the target's list and the strip mesh (two vertex rows, left / right edge).
void LightningEffect::Rebuild()
{
    int nPoints = (int)m_pPoints->GetCount();
    if (nPoints < 2)
        return;
    Vector3 kFirst = *FUN_140a0af70(m_pPoints, 0);
    Vector3 kLast = *FUN_140a0af70(m_pPoints, nPoints - 1);
    float fDist = (kLast - kFirst).Length();
    int nClass = 2;
    if (!(fDist > 256.0f))
        nClass = 0;
    else if (!(fDist > 512.0f))
        nClass = 1;
    bool bUpdate = true;
    if (m_nTick != 0)
    {
        unsigned int nNow = GetTickCountMs2();
        if (nNow < m_nLastTick + m_nTick)
            bUpdate = false;
        else
            m_nLastTick = nNow;
    }
    if (!bUpdate)
        return;
    unsigned __int64 nIndex = 0;
    unsigned __int64 nTextures = m_spParam->m_arrTexture[nClass].GetCount();
    if (nTextures > 0)
    {
        if (m_bSequence)
        {
            nIndex = (m_nSequence + 1) % nTextures;
            m_nSequence = nIndex;
        }
        else
        {
            nIndex = (unsigned __int64)(__int64)rand() % nTextures;
        }
    }
    CString strName = m_spParam->m_arrTexture[nClass][(size_t)nIndex];
    ((class NiTexturingProperty*)(class NiTexturingProperty*)(m_spTexProp))->SetBaseTexture((class NiTexture*)(((class CNifLoadingService*)FUN_140a0afd0())->GetTexture(FUN_140cc2ba0("Effect/Textures", strName), 5).operator NiTexture*()));
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
        pPos[i] = reinterpret_cast<const efd::Point3&>(m_arrLeft[i]);
        pCol[i] = kWhite;
        pPos[i + nCount] = reinterpret_cast<const efd::Point3&>(m_arrRight[i]);
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

// @0x14144d670
// Random walk from kStart toward kEnd in steps of m_fJointLen (at most 100 points); then the two edge lines are the
// path offset by +-width/2 along the horizontal direction crossed with the camera direction.
void LightningEffect::BuildPath(Vector3 kStart, Vector3 kEnd)
{
    m_arrPath.RemoveAll();
    Vector3 kLast;
    Vector3 kCur = kStart;
    Vector3 kStep;
    Vector3 kDelta = (kEnd - kStart);
    Vector3 kDir = kDelta;
    kDir.Unitize();
    m_arrPath.Add(kStart);
    float fAlong = 0.0f;
    float fRemain;
    do
    {
        kLast = kCur;
        kStep = (kEnd - kLast);
        float fDx = FUN_14109ace0() * m_fSpread * kStep.y;
        kStep.y = kStep.y + FUN_14109ace0() * m_fSpread * kStep.x;
        kStep.x = kStep.x + fDx;
        kStep.Unitize();
        kStep.x = kStep.x * m_fJointLen;
        kStep.y = kStep.y * m_fJointLen;
        kCur.x = kCur.x + kStep.x;
        kCur.y = kCur.y + kStep.y;
        Vector3 kRel = (kCur - kStart);
        fAlong = reinterpret_cast<const efd::Point3&>(kDir).Dot(reinterpret_cast<const efd::Point3&>(kRel));
        kCur.z = kStart.z + kDir.z * fAlong;
        m_arrPath.Add(kCur);
        if (m_arrPath.GetCount() >= 100)
            break;
        fRemain = (kEnd - kCur).Length();
    } while (!(fRemain <= m_fJointLen * 2.0f || fAlong <= 0.0f));
    m_arrPath.Add(kEnd);
    m_arrLeft.RemoveAll();
    m_arrRight.RemoveAll();
    Vector3 kFlat = kDelta;
    kFlat.z = 0.0f;
    kFlat.Unitize();
    Vector3 kCamera = reinterpret_cast<const Vector3&>(static_cast<const NiPoint3&>(TSingleton<CameraMgr>::GetInstance()->FUN_140af0250()));
    efd::Point3 kSide = reinterpret_cast<const efd::Point3&>(kFlat).Cross(reinterpret_cast<const efd::Point3&>(kCamera));
    for (int i = 0; i < (int)m_arrPath.GetCount(); ++i)
    {
        Vector3 kPoint = m_arrPath[i];
        m_arrLeft.Add(reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(reinterpret_cast<const efd::Point3&>(kPoint) + reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(reinterpret_cast<Vector3&>(kSide))) * m_fWidth * 0.5f)));
        m_arrRight.Add(reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(reinterpret_cast<const efd::Point3&>(kPoint) + reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(reinterpret_cast<Vector3&>(kSide))) * m_fWidth * (-0.5f))));
    }
}

// @0x14144ddc0
int LightningEffect::vfunc_12()
{
    return 0x10;
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cb24a0-0x142cb24e0 .text$yd

// hk1 2026-10-20: hooks for the remaining recovered functions (work/hk1/report.md)
MS2_REPLACE_METHOD(0x14144b880, LightningEffectParam, vfunc_1, 623, 0x10D3A731);
MS2_REPLACE_METHOD(0x14144c9e0, LightningEffect, vfunc_9, 126, 0xCD7206DD);
MS2_REPLACE_METHOD(0x14144ca70, LightningEffect, vfunc_4, 203, 0x2B931FA5);
MS2_REPLACE_METHOD(0x14144cb50, LightningEffect, vfunc_7, 39, 0x13C258DE);
MS2_REPLACE_METHOD(0x14144cb80, LightningEffect, vfunc_10, 69, 0x07968EFD);
MS2_REPLACE_METHOD(0x14144cbd0, LightningEffect, vfunc_8, 88, 0x4DB0CF7F);
MS2_REPLACE_METHOD(0x14144cc30, LightningEffect, Rebuild, 2605, 0x023C7402);
MS2_REPLACE_METHOD(0x14144ddc0, LightningEffect, vfunc_12, 11, 0x55CF9663);

