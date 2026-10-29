// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// MS2-UNIT: ?\taileffectobject.cpp
// MS2-RANGE: 0x140aced60-0x140ad1860 .text$mn
// MS2-PIN: memcpy_s 0x140ad1740
// MS2-PIN: ??0Unk_TeRequest@@QEAA@XZ 0x140a52ef0
// MS2-PIN: ??1Unk_TeRequest@@QEAA@XZ 0x1405a89e0
// MS2-PIN: ?GetScale@NiAVObject@@QEBAMXZ 0x140ad0db0
// MS2-PIN: ??0?$MS2Ptr@UTailEffectInfo@CTailEffectObject@@@@QEAA@XZ 0x140ad06c0
// MS2-PIN: ??0?$MS2SvrPtr@VTailEffectData@@@@QEAA@AEBV0@@Z 0x140ad0640
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??7?$MS2SvrPtr@VTailEffectData@@@@QEBA_NXZ 0x140ad09e0 ; unique
// MS2-PIN: ?IsNull@?$MS2Ptr@UTailEffectInfo@CTailEffectObject@@@@QEBA_NXZ 0x140ad0a10 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\taileffectobject.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "taileffectobject.h"
#include "gameobject.h"
#include "ms2/placeholder/socketptr.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/commonfiles/blackmarketitemoption.h"  // Unk_BmNewTag
#include <NiNode.h>
#include <NiAVObject.h>
#include <NiTransform.h>
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- exe callees (recovered elsewhere / not yet) ----
extern char DAT_143afa4d8;                                  // shadow-node table (see FUN_14098d8d0)
extern char DAT_143a08cf8;                                  // the up axis handed to FUN_140a0b080
float FUN_14123c260(GameObject* pOwner);                    // the owner's model scale
void* FUN_14123c410(GameObject* pOwner);                    // the owner's entity

NiAVObject* FUN_141b6ef70(egf::EntityID id);                // entity -> its scene graph root (util.cpp)
void* FUN_141b6efc0(void* p);                               // entity -> its scene root key
void* FUN_14098d8d0(void* pTable, void* pKey);              // table lookup -> node
int FUN_14166ce30(GameObject* pOwner);                      // non-zero while the owner is alive
bool FUN_14028d470(float a, float b);                       // nearly equal
void FUN_140a0b2a0(void* pNode);                            // detach the node from its parent
void FUN_14098b3e0(void* pNode, float fAlpha, int nFlags);  // apply an alpha to the node tree
void FUN_140a01250(efd::Point3 kAngles, efd::Point3* pForward, efd::Point3* pRight);   // euler angles -> axes
NiPoint3 FUN_140a0b080(const NiPoint3& kFrom, const NiPoint3& kTo, const void* pUp);  // look-at angles

// Spawn request handed to the effect manager (0x70 bytes, the frames of FUN_140acf570 / FUN_140acee90 leave no more).
struct Unk_TeRequest
{
    Unk_TeRequest();                        // 0x140a52ef0
    ~Unk_TeRequest();                       // 0x1405a89e0
    CString m_strName;                      // +0x00 effect path
    int m_nOwnerId;                         // +0x08
    int m_nPad_0c;
    void* m_spNode;                         // +0x10 node smart pointer slot
    NiTransform* m_pTransform;              // +0x18 placement for fire-and-forget effects
    char m_pad_20[0x70 - 0x20];
};
MS2_CHECK_SIZE(Unk_TeRequest, 0x70);
void FUN_140a53190(Unk_TeRequest* p, int nOwnerId);         // set owner
void FUN_1409fabf0(void* pSmartPointer, void* pNode);       // efd::SmartPointer<NiAVObject>::operator=

// The effect manager singleton (0x1403ed280).
class Unk_TeEffectMgr
{
public:
    void* FUN_1411a6b10();                                  // the effect root NiNode
    int FUN_1411a49c0(Unk_TeRequest* pRequest);             // spawn, returns the handle
    void FUN_1411a4a00(Unk_TeRequest* pRequest);            // fire and forget
    void FUN_1411a6060(int nHandle);                        // release
    void FUN_1411a68f0(int nHandle, bool bVisible);
};
Unk_TeEffectMgr* FUN_1403ed280();

// The tail table singleton accessor (0x140ad0da0).
// @0x140ad0da0
CTailEffectDataTable* FUN_140ad0da0()
{
    return static_cast<CTailEffectDataTable*>(TSingleton<CTailEffectDataTable>::s_instance);
}


// in-unit helpers
// @0x140ad02c0
int FUN_140ad02c0(int a, int b)
{
    return a > b ? a : b;
}

// @0x140ad02f0
int FUN_140ad02f0(int a, int b)
{
    return a < b ? a : b;
}

// @0x140ad0d60
int FUN_140ad0d60(int n, int nMin, int nMax)
{
    n = FUN_140ad02c0(n, nMin);
    n = FUN_140ad02f0(n, nMax);
    return n;
}

// @0x140ad0c10
static efd::Point3& FUN_140ad0c10(efd::Point3& v, float f)
{
    v.x = v.x * f;
    v.y = v.y * f;
    v.z = v.z * f;
    return v;
}

typedef CTailEffectObject::TailEffectInfo Unk_TeInfo;

// @0x140ad0320
Unk_TeInfo* FUN_140ad0320(void*)
{
    return new Unk_TeInfo();
}

// @0x140ad0e80
static Unk_TeInfo* FUN_140ad0e80(void*)
{
    return static_cast<Unk_TeInfo*>(FUN_1401ba820(FUN_140ad0320(0)));
}

struct Unk_TePtrAccess
{
    // @0x140ad0e50
    static void ResetNew(MS2Ptr<Unk_TeInfo>& sp)
    {
        sp.Release();
        sp.m_p = FUN_140ad0e80(0);
    }
};

// @0x140ad0d30
static MS2Ptr<Unk_TeInfo>& FUN_140ad0d30(MS2Ptr<Unk_TeInfo>& sp, const Unk_BmNewTag&)
{
    Unk_TePtrAccess::ResetNew(sp);
    return sp;
}

// @0x140aced60
CTailEffectObject::CTailEffectObject(GameObject* pOwner, MS2SvrPtr<TailEffectData> spData)
    : m_pOwner(pOwner), m_spData(static_cast<const MS2SvrPtr<TailEffectData>&>(spData)), m_fAlpha(1.0f), m_bVisible(true), m_bDestroyed(false), m_nCount(0)
{
}

// @0x140acee20
CTailEffectObject::~CTailEffectObject()
{
    m_bDestroyed = true;
    FUN_140ad01d0();
}

// @0x140acee90
// MS2-FUNCTIONAL: code identical; the exe places kBase above kRequest in the frame (frame 8 bytes larger)
void CTailEffectObject::FUN_140acee90()
{
    if (!m_spData)
        return;
    if (m_pOwner == 0)
        return;

    const CString& strPath = m_spData->m_strEffectPath;
    float fScale = FUN_14123c260(m_pOwner);
    float fSpacing = m_spData->m_fDistance * fScale;

    Unk_NodePtr spNode(NiNew NiNode(0));
    if (m_pOwner->GetClassID() == 0x6200044)
    {
        NiNode* pRoot = static_cast<NiNode*>(FUN_14098d8d0(&DAT_143afa4d8, FUN_141b6efc0(FUN_14123c410(m_pOwner))));
        pRoot->AttachChild(static_cast<NiAVObject*>(FUN_1409475d0(&spNode)), false);
    }
    else
    {
        NiNode* pRoot = static_cast<NiNode*>(FUN_1403ed280()->FUN_1411a6b10());
        pRoot->AttachChild(static_cast<NiAVObject*>(FUN_1409475d0(&spNode)), false);
    }

    Unk_TeRequest kRequest;
    kRequest.m_strName = strPath;
    kRequest.m_nOwnerId = 0;
    FUN_140a53190(&kRequest, m_pOwner->FUN_14123c580());
    FUN_1409fabf0(&kRequest.m_spNode, FUN_1409475d0(&spNode));
    int nHandle = FUN_1403ed280()->FUN_1411a49c0(&kRequest);
    FUN_1403ed280()->FUN_1411a68f0(nHandle, m_bVisible);

    MS2Ptr<TailEffectInfo> spInfo;
    FUN_140ad0d30(spInfo, Unk_BmNewTag(0));
    spInfo->m_spNode = spNode;
    spInfo->m_nEffectId = nHandle;

    Unk_NodePtr spBase(FUN_14098d8d0(&DAT_143afa4d8, FUN_141b6ef70(m_pOwner->FUN_14123c460())));
    if (!FUN_1409475d0(&spBase))
        return;

    efd::Point3 ptBase = static_cast<NiAVObject*>(FUN_1409475f0(&spBase))->GetWorldTranslate();
    do
    {
        if (m_listInfo.empty())
            break;
        MS2Ptr<TailEffectInfo> spLast(m_listInfo.back());
        if (spLast.IsNull())
        {
            (void)((!!(0)) || (_wassert(L"0", _CRT_WIDE(MS2_THIS_FILE), 0x5b), 0));
            break;
        }
        spBase = spLast->m_spNode;
        ptBase = static_cast<NiAVObject*>(FUN_1409475f0(&spLast->m_spNode))->GetWorldTranslate();
    } while (0);
    if (!FUN_1409475d0(&spBase))
        return;

    NiTransform kBase = static_cast<NiAVObject*>(FUN_1409475f0(&spBase))->GetWorldTransform();
    efd::Point3 kEuler;
    kBase.m_Rotate.ToEulerAnglesXYZ(kEuler.x, kEuler.y, kEuler.z);
    FUN_140ad0c10(kEuler, -57.2957764f);
    efd::Point3 kForward;
    efd::Point3 kRight;
    FUN_140a01250(kEuler, &kForward, &kRight);
    kBase.m_Translate = ptBase + kForward * fSpacing * -1.0f;
    kBase.m_fScale = fScale;

    static_cast<NiAVObject*>(FUN_1409475f0(&spNode))->SetWorldTranslate(kBase.m_Translate);
    static_cast<NiAVObject*>(FUN_1409475f0(&spNode))->SetWorldRotate(kBase.m_Rotate);
    static_cast<NiAVObject*>(FUN_1409475f0(&spNode))->SetLocalFromWorldTransform(kBase);
    FUN_14098b3e0(FUN_1409475d0(&spNode), m_fAlpha, 0);
    m_listInfo.push_back(spInfo);
}

// @0x140acf570
void CTailEffectObject::FUN_140acf570()
{
    if (m_listInfo.empty())
        return;

    MS2Ptr<TailEffectInfo> spInfo(m_listInfo.back());
    if (spInfo.IsNull())
        return;

    FUN_1403ed280()->FUN_1411a6060(spInfo->m_nEffectId);
    do
    {
        if (m_bDestroyed)
            break;
        if (!m_spData)
            break;
        if (!FUN_1409475d0(&spInfo->m_spNode))
            break;
        NiTransform kXform;
        kXform.m_Rotate.MakeIdentity();
        kXform.m_Translate = static_cast<NiAVObject*>(FUN_1409475f0(&spInfo->m_spNode))->GetWorldTranslate();
        kXform.m_fScale = static_cast<NiAVObject*>(FUN_1409475f0(&spInfo->m_spNode))->GetScale();
        Unk_TeRequest kRequest;
        kRequest.m_strName = m_spData->m_strEndEffectPath;
        kRequest.m_pTransform = &kXform;
        kRequest.m_nOwnerId = 0;
        FUN_1403ed280()->FUN_1411a4a00(&kRequest);
    } while (0);
    FUN_140a0b2a0(FUN_1409475d0(&spInfo->m_spNode));
    m_listInfo.pop_back();
}

// @0x140acf7b0
void CTailEffectObject::FUN_140acf7b0()
{
    if (m_listInfo.empty())
        return;
    int nCount = (int)m_listInfo.size();
    for (int i = 0; i < nCount; ++i)
        FUN_140acf570();
}

// @0x140acf820
void CTailEffectObject::FUN_140acf820()
{
    if (!m_spData)
        return;
    int nWanted = m_nCount;
    int bGrow = nWanted > (int)m_listInfo.size() ? 1 : 0;
    int nSteps = abs(nWanted - (int)m_listInfo.size());
    for (int i = 0; i < nSteps; ++i)
    {
        if (bGrow)
            FUN_140acee90();
        else
            FUN_140acf570();
    }
}

// @0x140acf8f0
void CTailEffectObject::FUN_140acf8f0()
{
    if (!m_spData)
        return;
    if (m_pOwner == 0)
        return;
    if (m_pOwner->GetClassID() == 0x6200044)
        return;

    float fSpeed = m_spData->m_fSpeed;
    float fScale = FUN_14123c260(m_pOwner);
    float fDist = m_spData->m_fDistance * fScale;

    Unk_NodePtr spPrev(FUN_14098d8d0(&DAT_143afa4d8, FUN_141b6ef70(m_pOwner->FUN_14123c460())));
    std::list<MS2Ptr<TailEffectInfo> >& rList = m_listInfo;
    for (std::list<MS2Ptr<TailEffectInfo> >::const_iterator itEnd = rList.end(), it = rList.begin(); it != itEnd; ++it)
    {
        MS2Ptr<TailEffectInfo> spInfo(*it);
        if (!FUN_1409475d0(&spPrev))
            continue;
        if (spInfo.IsNull())
            continue;

        Unk_NodePtr spCur(spInfo->m_spNode);
        if (!FUN_1409475d0(&spCur))
            continue;

        NiTransform kPrev = static_cast<NiAVObject*>(FUN_1409475f0(&spPrev))->GetWorldTransform();
        NiTransform kCur = static_cast<NiAVObject*>(FUN_1409475f0(&spCur))->GetWorldTransform();
        spPrev = spCur;

        float fLength = (kPrev.m_Translate - kCur.m_Translate).Length();
        if (fDist - fLength >= -1.0f)
            continue;

        NiPoint3 kLook = FUN_140a0b080(kPrev.m_Translate, kCur.m_Translate, &DAT_143a08cf8);
        efd::Point3 kDir = kPrev.m_Translate - kCur.m_Translate;
        kDir.Unitize();
        float fOver = fLength - fDist;
        float fStep = fOver / fDist * fSpeed;
        kCur.m_Rotate.FromEulerAnglesXYZ(0.0f, 0.0f, -kLook.z * 3.1415927f / 180.0f);
        kCur.m_Translate = kCur.m_Translate + kDir * fStep;
        kCur.m_fScale = fScale;
        static_cast<NiAVObject*>(FUN_1409475f0(&spCur))->SetWorldTranslate(kCur.m_Translate);
        static_cast<NiAVObject*>(FUN_1409475f0(&spCur))->SetWorldRotate(kCur.m_Rotate);
        static_cast<NiAVObject*>(FUN_1409475f0(&spCur))->SetWorldScale(kCur.m_fScale);
        static_cast<NiAVObject*>(FUN_1409475f0(&spCur))->SetLocalFromWorldTransform(kCur);
    }
}

// @0x140acfda0
void CTailEffectObject::FUN_140acfda0()
{
    if (m_bVisible)
        return;
    m_bVisible = true;
    std::list<MS2Ptr<TailEffectInfo> >& rList = m_listInfo;
    for (std::list<MS2Ptr<TailEffectInfo> >::const_iterator itEnd = rList.end(), it = rList.begin(); it != itEnd; ++it)
    {
        MS2Ptr<TailEffectInfo> spInfo(*it);
        if (spInfo.IsNull())
            continue;
        FUN_1403ed280()->FUN_1411a68f0(spInfo->m_nEffectId, true);
    }
}

// @0x140acfeb0
void CTailEffectObject::FUN_140acfeb0()
{
    if (!m_bVisible)
        return;
    m_bVisible = false;
    std::list<MS2Ptr<TailEffectInfo> >& rList = m_listInfo;
    for (std::list<MS2Ptr<TailEffectInfo> >::const_iterator itEnd = rList.end(), it = rList.begin(); it != itEnd; ++it)
    {
        MS2Ptr<TailEffectInfo> spInfo(*it);
        if (spInfo.IsNull())
            continue;
        FUN_1403ed280()->FUN_1411a68f0(spInfo->m_nEffectId, false);
    }
}

// @0x140acffc0
void CTailEffectObject::FUN_140acffc0(float fAlpha)
{
    if (FUN_14028d470(m_fAlpha, fAlpha))
        return;
    m_fAlpha = fAlpha;
    std::list<MS2Ptr<TailEffectInfo> >& rList = m_listInfo;
    for (std::list<MS2Ptr<TailEffectInfo> >::const_iterator itEnd = rList.end(), it = rList.begin(); it != itEnd; ++it)
    {
        MS2Ptr<TailEffectInfo> spInfo(*it);
        if (spInfo.IsNull())
            continue;
        FUN_14098b3e0(FUN_1409475d0(&spInfo->m_spNode), fAlpha, 0);
    }
}

// @0x140ad00e0
void CTailEffectObject::FUN_140ad00e0(int nCount)
{
    m_nCount = FUN_140ad0d60(nCount, 0, 30);
}

// @0x140ad0120
void CTailEffectObject::FUN_140ad0120(int nTailId)
{
    MS2SvrPtr<TailEffectData> spNew = FUN_140ad0da0()->GetData(nTailId);
    if (spNew == 0)
        return;
    FUN_140acf7b0();
    m_spData = spNew;
    for (int i = 0; i < m_nCount; ++i)
        FUN_140acee90();
}

// @0x140ad01d0
void CTailEffectObject::FUN_140ad01d0()
{
    m_nCount = 0;
    FUN_140acf7b0();
}

// @0x140ad0200
void CTailEffectObject::FUN_140ad0200()
{
    if (vfunc_1())
        FUN_140acf7b0();
    else
    {
        FUN_140acf820();
        FUN_140acf8f0();
    }
}

// @0x140ad0250
bool CTailEffectObject::vfunc_1()
{
    if (m_pOwner == 0)
        return false;
    if (FUN_14166ce30(m_pOwner))
        return true;
    return false;
}

// MS2-PIN: ?FUN_140ad02c0@@YAHHH@Z 0x140ad02c0
// MS2-PIN: ?FUN_140ad02f0@@YAHHH@Z 0x140ad02f0
// MS2-PIN: ?FUN_140ad0d60@@YAHHHH@Z 0x140ad0d60
