// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// MS2-UNIT: ?\taileffectobject.cpp
// MS2-RANGE: 0x140aced60-0x140ad1860 .text$mn
// MS2-PIN: memcpy_s 0x140ad1740
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
void* FUN_14123c460(GameObject* pOwner, void* pTmp);        // fills the 16-byte model key
void* FUN_141b6ef70(void* p);                               // key -> shadow-node key
void* FUN_141b6efc0(void* p);                               // entity -> its scene root key
void* FUN_14098d8d0(void* pTable, void* pKey);              // table lookup -> node
int FUN_14166ce30(GameObject* pOwner);                      // non-zero while the owner is alive
bool FUN_14028d470(float a, float b);                       // nearly equal
void FUN_140a0b2a0(void* pNode);                            // detach the node from its parent
void FUN_14098b3e0(void* pNode, float fAlpha, int nFlags);  // apply an alpha to the node tree
void FUN_140a01250(NiPoint3 kAngles, NiPoint3* pForward, NiPoint3* pRight);   // euler angles -> axes
void FUN_140a0b080(NiPoint3* pOut, const NiPoint3& kFrom, const NiPoint3& kTo, const void* pUp);  // look-at angles

// Spawn request handed to the effect manager (0x78 bytes).
struct Unk_TeRequest
{
    CString m_strName;                      // +0x00 effect path
    int m_nOwnerId;                         // +0x08
    int m_nPad_0c;
    void* m_spNode;                         // +0x10 node smart pointer slot
    NiTransform* m_pTransform;              // +0x18 placement for fire-and-forget effects
    char m_pad_20[0x78 - 0x20];
};
MS2_CHECK_SIZE(Unk_TeRequest, 0x78);
void FUN_140a52ef0(Unk_TeRequest* p);                       // construct
void FUN_140a53190(Unk_TeRequest* p, int nOwnerId);         // set owner
void FUN_1405a89e0(Unk_TeRequest* p);                       // destroy
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

// The world scale of a node (0x140ad0db0).
// @0x140ad0db0
static float FUN_140ad0db0(NiAVObject* pNode)
{
    return pNode->GetWorldScale();
}

// in-unit helpers
// @0x140ad02c0
int FUN_140ad02c0(int a, int b)
{
    int r = b;
    if (b < a)
        r = a;
    return r;
}

// @0x140ad02f0
int FUN_140ad02f0(int a, int b)
{
    int r = b;
    if (a < b)
        r = a;
    return r;
}

// @0x140ad0d60
int FUN_140ad0d60(int n, int nMin, int nMax)
{
    return FUN_140ad02f0(FUN_140ad02c0(n, nMin), nMax);
}

// @0x140ad0c10
static NiPoint3& FUN_140ad0c10(NiPoint3& v, float f)
{
    v.x = v.x * f;
    v.y = v.y * f;
    v.z = v.z * f;
    return v;
}

typedef CTailEffectObject::TailEffectInfo Unk_TeInfo;

// @0x140ad08b0
CTailEffectObject::TailEffectInfo::TailEffectInfo()
{
}

// @0x140ad0320
Unk_TeInfo* FUN_140ad0320()
{
    void* p = operator new(0x28);
    if (p == 0)
        return 0;
    memset(p, 0, 0x28);
    return new (p) Unk_TeInfo();
}

// @0x140ad0e80
static Unk_TeInfo* FUN_140ad0e80()
{
    return static_cast<Unk_TeInfo*>(FUN_1401ba820(FUN_140ad0320()));
}

// MS2-FUNCTIONAL: ResetNew is a private member of the exe's smart pointer; reached through a friend here
struct Unk_TePtrAccess
{
    // @0x140ad0e50
    static void ResetNew(MS2Ptr<Unk_TeInfo>& sp)
    {
        sp.Release();
        sp.m_p = FUN_140ad0e80();
    }
};

// @0x140ad0d30
static MS2Ptr<Unk_TeInfo>& FUN_140ad0d30(MS2Ptr<Unk_TeInfo>& sp)
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
// MS2-FUNCTIONAL: efd::Point3 / NiTransform temporaries are inlined here, the exe calls out-of-line helpers
void CTailEffectObject::FUN_140acee90()
{
    if (!m_spData || m_pOwner == 0)
        return;

    const CString& strPath = m_spData->m_strEffectPath;
    float fScale = FUN_14123c260(m_pOwner);
    float fSpacing = m_spData->m_fDistance * fScale;

    NiNode* pNode = NiNew NiNode(0);
    Unk_NodePtr spNode(pNode);
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

    alignas(8) char kRequestBuf[sizeof(Unk_TeRequest)];   // FUN_140a52ef0 / FUN_1405a89e0 construct and destroy it: no implicit dtor
    Unk_TeRequest& kRequest = *reinterpret_cast<Unk_TeRequest*>(kRequestBuf);
    FUN_140a52ef0(&kRequest);
    kRequest.m_strName = strPath;
    kRequest.m_nOwnerId = 0;
    FUN_140a53190(&kRequest, m_pOwner->FUN_14123c580());
    FUN_1409fabf0(&kRequest.m_spNode, FUN_1409475d0(&spNode));
    int nHandle = FUN_1403ed280()->FUN_1411a49c0(&kRequest);
    FUN_1403ed280()->FUN_1411a68f0(nHandle, m_bVisible);

    MS2Ptr<TailEffectInfo> spInfo;
    FUN_140ad0d30(spInfo);
    static_cast<Unk_NodePtr&>(spInfo->m_spNode) = spNode;
    spInfo->m_nEffectId = nHandle;

    char aTmp[16];
    Unk_NodePtr spBase(FUN_14098d8d0(&DAT_143afa4d8, FUN_141b6ef70(FUN_14123c460(m_pOwner, aTmp))));
    if (FUN_1409475d0(&spBase) == 0)
    {
        FUN_1405a89e0(&kRequest);   // the exe destroys the request on this exit too (raw storage: no implicit dtor)
        return;
    }

    NiPoint3 ptBase = static_cast<NiAVObject*>(FUN_1409475f0(&spBase))->GetWorldTranslate();
    if (!m_listInfo.empty())
    {
        MS2Ptr<TailEffectInfo> spLast = m_listInfo.back();
        if (spLast.IsNull())
        {
            (void)((!!(0)) || (_wassert(L"0", _CRT_WIDE(MS2_THIS_FILE), 0x5b), 0));
        }
        else
        {
            spBase = spLast->m_spNode;
            ptBase = static_cast<NiAVObject*>(FUN_1409475f0(&spLast->m_spNode))->GetWorldTranslate();
        }
    }
    if (FUN_1409475d0(&spBase) == 0)
    {
        FUN_1405a89e0(&kRequest);   // the exe destroys the request on this exit too (raw storage: no implicit dtor)
        return;
    }

    NiTransform kBase = static_cast<NiAVObject*>(FUN_1409475f0(&spBase))->GetWorldTransform();
    NiPoint3 kEuler;
    kBase.m_Rotate.ToEulerAnglesXYZ(kEuler.x, kEuler.y, kEuler.z);
    FUN_140ad0c10(kEuler, -57.2957764f);
    NiPoint3 kForward;
    NiPoint3 kRight;
    FUN_140a01250(kEuler, &kForward, &kRight);
    NiPoint3 kPos = ptBase + (kForward * fSpacing) * -1.0f;
    kBase.m_Translate = kPos;
    kBase.m_fScale = fScale;

    NiAVObject* pNew = static_cast<NiAVObject*>(FUN_1409475f0(&spNode));
    pNew->SetWorldTranslate(kBase.m_Translate);
    pNew->SetWorldRotate(kBase.m_Rotate);
    pNew->SetLocalFromWorldTransform(kBase);
    FUN_14098b3e0(FUN_1409475d0(&spNode), m_fAlpha, 0);
    m_listInfo.push_back(spInfo);
    FUN_1405a89e0(&kRequest);
}

// @0x140acf570
// MS2-FUNCTIONAL: efd::Point3 / NiTransform temporaries are inlined here, the exe calls out-of-line helpers
void CTailEffectObject::FUN_140acf570()
{
    if (m_listInfo.empty())
        return;

    MS2Ptr<TailEffectInfo> spInfo = m_listInfo.back();
    if (spInfo.IsNull())
        return;

    FUN_1403ed280()->FUN_1411a6060(spInfo->m_nEffectId);
    if (!m_bDestroyed && !!m_spData)
    {
        if (FUN_1409475d0(&spInfo->m_spNode) != 0)
        {
            NiTransform kXform;
            kXform.MakeIdentity();
            NiAVObject* pNode = static_cast<NiAVObject*>(FUN_1409475f0(&spInfo->m_spNode));
            kXform.m_Translate = pNode->GetWorldTranslate();
            kXform.m_fScale = FUN_140ad0db0(pNode);

            alignas(8) char kRequestBuf[sizeof(Unk_TeRequest)];   // FUN_140a52ef0 / FUN_1405a89e0 construct and destroy it: no implicit dtor
            Unk_TeRequest& kRequest = *reinterpret_cast<Unk_TeRequest*>(kRequestBuf);
            FUN_140a52ef0(&kRequest);
            kRequest.m_strName = m_spData->m_strEndEffectPath;
            kRequest.m_pTransform = &kXform;
            kRequest.m_nOwnerId = 0;
            FUN_1403ed280()->FUN_1411a4a00(&kRequest);
            FUN_1405a89e0(&kRequest);
        }
    }
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
    int nHave = (int)m_listInfo.size();
    int nDiff = nWanted - (int)m_listInfo.size();
    int nSteps = nDiff < 0 ? -nDiff : nDiff;
    for (int i = 0; i < nSteps; ++i)
    {
        if (nHave < nWanted)
            FUN_140acee90();
        else
            FUN_140acf570();
    }
}

// @0x140acf8f0
// MS2-FUNCTIONAL: efd::Point3 / NiTransform temporaries are inlined here, the exe calls out-of-line helpers
void CTailEffectObject::FUN_140acf8f0()
{
    if (!m_spData || m_pOwner == 0 || m_pOwner->GetClassID() == 0x6200044)
        return;

    float fSpeed = m_spData->m_fSpeed;
    float fScale = FUN_14123c260(m_pOwner);
    float fDist = m_spData->m_fDistance * fScale;

    char aTmp[16];
    Unk_NodePtr spPrev(FUN_14098d8d0(&DAT_143afa4d8, FUN_141b6ef70(FUN_14123c460(m_pOwner, aTmp))));
    for (std::list<MS2Ptr<TailEffectInfo> >::iterator it = m_listInfo.begin(); it != m_listInfo.end(); ++it)
    {
        MS2Ptr<TailEffectInfo> spInfo = *it;
        if (FUN_1409475d0(&spPrev) == 0)
            continue;
        if (spInfo.IsNull())
            continue;

        Unk_NodePtr spCur(spInfo->m_spNode.m_p);
        if (FUN_1409475d0(&spCur) == 0)
            continue;

        NiTransform kPrev = static_cast<NiAVObject*>(FUN_1409475f0(&spPrev))->GetWorldTransform();
        NiTransform kCur = static_cast<NiAVObject*>(FUN_1409475f0(&spCur))->GetWorldTransform();
        spPrev = spCur;

        float fLength = (kPrev.m_Translate - kCur.m_Translate).Length();
        if (fDist - fLength < -1.0f)
        {
            NiPoint3 kLook;
            FUN_140a0b080(&kLook, kPrev.m_Translate, kCur.m_Translate, &DAT_143a08cf8);
            NiPoint3 kDir = kPrev.m_Translate - kCur.m_Translate;
            kDir.Unitize();
            float fOver = fLength - fDist;
            float fStep = (fOver / fDist) * fSpeed;
            kCur.m_Rotate.FromEulerAnglesXYZ(0.0f, 0.0f, (-kLook.z * 3.1415927f) / 180.0f);
            kCur.m_Translate = kCur.m_Translate + kDir * fStep;
            kCur.m_fScale = fScale;
            NiAVObject* pCur = static_cast<NiAVObject*>(FUN_1409475f0(&spCur));
            pCur->SetWorldTranslate(kCur.m_Translate);
            pCur->SetWorldRotate(kCur.m_Rotate);
            pCur->SetWorldScale(fScale);
            pCur->SetLocalFromWorldTransform(kCur);
        }
    }
}

// MS2-FUNCTIONAL: the list traversal is equivalent; our build inlines the list iterator helpers emitted out of line by the exe.
// @0x140acfda0
void CTailEffectObject::FUN_140acfda0()
{
    if (m_bVisible)
        return;
    m_bVisible = true;
    for (std::list<MS2Ptr<TailEffectInfo> >::iterator it = m_listInfo.begin(); it != m_listInfo.end(); ++it)
    {
        MS2Ptr<TailEffectInfo> spInfo = *it;
        if (!spInfo.IsNull())
            FUN_1403ed280()->FUN_1411a68f0(spInfo->m_nEffectId, true);
    }
}

// MS2-FUNCTIONAL: the list traversal is equivalent; our build inlines the list iterator helpers emitted out of line by the exe.
// @0x140acfeb0
void CTailEffectObject::FUN_140acfeb0()
{
    if (!m_bVisible)
        return;
    m_bVisible = false;
    for (std::list<MS2Ptr<TailEffectInfo> >::iterator it = m_listInfo.begin(); it != m_listInfo.end(); ++it)
    {
        MS2Ptr<TailEffectInfo> spInfo = *it;
        if (!spInfo.IsNull())
            FUN_1403ed280()->FUN_1411a68f0(spInfo->m_nEffectId, false);
    }
}

// MS2-FUNCTIONAL: the list traversal is equivalent; our build inlines the list iterator helpers emitted out of line by the exe.
// @0x140acffc0
void CTailEffectObject::FUN_140acffc0(float fAlpha)
{
    if (FUN_14028d470(m_fAlpha, fAlpha))
        return;
    m_fAlpha = fAlpha;
    for (std::list<MS2Ptr<TailEffectInfo> >::iterator it = m_listInfo.begin(); it != m_listInfo.end(); ++it)
    {
        MS2Ptr<TailEffectInfo> spInfo = *it;
        if (!spInfo.IsNull())
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
    if (!vfunc_1())
    {
        FUN_140acf820();
        FUN_140acf8f0();
    }
    else
    {
        FUN_140acf7b0();
    }
}

// @0x140ad0250
bool CTailEffectObject::vfunc_1()
{
    if (m_pOwner == 0)
        return false;
    return FUN_14166ce30(m_pOwner) != 0;
}

// MS2-PIN: ?FUN_140ad02c0@@YAHHH@Z 0x140ad02c0
// MS2-PIN: ?FUN_140ad02f0@@YAHHH@Z 0x140ad02f0
// MS2-PIN: ?FUN_140ad0d60@@YAHHHH@Z 0x140ad0d60
