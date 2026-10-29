// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// MS2-UNIT: ?\randomtargeteffect.cpp
// MS2-RANGE: 0x140aaadb0-0x140aace60 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?SetLocalFromWorldTransform@NiAVObject@@QEAAXAEBVNiTransform@@@Z 0x140aacaa0 ; unique
// MS2-PIN: ?SetLocalTransform@NiAVObject@@QEAAXAEBVNiTransform@@@Z 0x140aacb60 ; unique
// MS2-PIN: ?SetWorldRotate@NiAVObject@@QEAAXAEBVNiMatrix3@@@Z 0x140aacbb0 ; unique
// MS2-PIN: ?SetWorldScale@NiAVObject@@QEAAXM@Z 0x140aacbe0 ; unique
// MS2-PIN: ?SetWorldTranslate@NiAVObject@@QEAAXAEBVNiPoint3@@@Z 0x140aacc00 ; unique
// MS2-PINS-END tplpin
// w4s3-manual-pins-begin
// MS2-PIN: ??1?$CComPtrBase@UUnk_RtePlayer@@@ATL@@QEAA@XZ 0x140aac150
// MS2-PIN: ??4?$CComPtr@VUnk_UpperNpc@@@ATL@@QEAAPEAVUnk_UpperNpc@@AEBV01@@Z 0x140aac1c0
// MS2-PIN: ??4?$CComPtr@UUnk_RtePlayer@@@ATL@@QEAAPEAUUnk_RtePlayer@@AEBV01@@Z 0x140aac2b0
// MS2-PIN: ??9Unk_NodePtr@@QEBA_NH@Z 0x140aac3e0
// MS2-PIN: ??B?$CComPtrBase@UUnk_RtePlayer@@@ATL@@QEBAPEAUUnk_RtePlayer@@XZ 0x140aac420
// MS2-PIN: ??B?$CComPtrBase@VUnk_UpperNpc@@@ATL@@QEBAPEAVUnk_UpperNpc@@XZ 0x140aac440
// MS2-PIN: ?IsNil@?$CRBTree@IV?$CComPtr@UUnk_RtePlayer@@@ATL@@V?$CElementTraits@I@2@V?$CElementTraits@V?$CComPtr@UUnk_RtePlayer@@@ATL@@@2@@ATL@@AEBA_NPEAVCNode@12@@Z 0x140aac740
// MS2-PIN: ?AddRefImpl@?$MS2Ptr@VCRandomTargetEffect@@@@AEBAXPEAX@Z 0x140aacc80
// MS2-PIN: ??4Unk_NodePtr@@QEAAAEAU0@AEBU0@@Z 0x140aac240
// MS2-PIN: ?Maximum@?$CRBTree@IV?$CComPtr@VUnk_UpperNpc@@@ATL@@V?$CElementTraits@I@2@V?$CElementTraits@V?$CComPtr@VUnk_UpperNpc@@@ATL@@@2@@ATL@@IEBAPEAVCNode@12@PEAV312@@Z 0x140aac820
// MS2-PIN: ?Predecessor@?$CRBTree@IV?$CComPtr@VUnk_UpperNpc@@@ATL@@V?$CElementTraits@I@2@V?$CElementTraits@V?$CComPtr@VUnk_UpperNpc@@@ATL@@@2@@ATL@@IEBAPEAVCNode@12@PEAV312@@Z 0x140aac900
// MS2-PIN: ?Maximum@?$CRBTree@IV?$CComPtr@UUnk_RtePlayer@@@ATL@@V?$CElementTraits@I@2@V?$CElementTraits@V?$CComPtr@UUnk_RtePlayer@@@ATL@@@2@@ATL@@IEBAPEAVCNode@12@PEAV312@@Z 0x140aac890
// w4s3-manual-pins-end
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\randomtargeteffect.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "randomtargeteffect.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/effectquery.h"
#include <egf/Entity.h>
#include <NiNode.h>
#include <NiAVObject.h>
#include <NiTransform.h>
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- exe callees (recovered elsewhere / not yet) ----
extern char DAT_143afa4d8;                                  // NiNode::ms_RTTI
unsigned FUN_140869420();                                   // GetTickCount-like millisecond clock
bool FUN_14028d470(float a, float b);                       // nearly equal
int FUN_14123c580(void* pOwner);                            // owner -> object id
// The owner game object: its entity id (by value) and the scene object of an entity id.
class Unk_RteOwner { public: egf::EntityID FUN_14123c460(); };
void* FUN_141b6ef70(egf::EntityID kId);
void* FUN_14098d8d0(void* pRtti, void* pObject);            // NiObject::DynamicCast
void FUN_140a0b2a0(void* pNode);                            // detach the node from its parent
void FUN_14098b3e0(void* pNode, float fScale, int nFlags);  // apply a uniform scale to the node
void* FUN_140a0b000(void* pNode);                           // parent

// The effect manager singleton (0x1403ed280).
class Unk_1403ed280
{
public:
    void* FUN_1411a6b10();                                  // the effect root NiNode
    int FUN_1411a49c0(NoticeMessage* pRequest);             // spawn, returns the handle
    void FUN_1411a6060(int nHandle);                        // release
    void FUN_1411a68f0(int nHandle, bool bVisible);
};
Unk_1403ed280* FUN_1403ed280();


// The world service singleton (0x1403ed2d0, typed Unk_AttendAvatarMgr in the symbol table) and its object maps.
class Unk_AttendAvatarMgr;
Unk_AttendAvatarMgr* FUN_1403ed2d0();
struct Unk_WsV118;
struct Unk_WsV148;
class WorldService
{
public:
    ATL::CRBMap<unsigned, Unk_WsV118>* FUN_141bd36b0();     // &m_118
    ATL::CRBMap<unsigned, Unk_WsV148>* FUN_141bd36d0();     // &m_148
};
class Unk_UpperPlayer { public: void* FUN_141bd1180(int nId); };   // object by id (world service)
Unk_RtePlayer* FUN_14099eef0(void* pObj);                   // object -> player
Unk_UpperNpc* FUN_140a38a00(void* pObj);                    // object -> npc

// MS2-FUNCTIONAL: the exe's map value assign / dtor (0x140aac1c0, 0x140aac2b0, 0x140aac150) are older inline forms of
// CComPtr::operator= / ~CComPtrBase than the ATL we compile against (124 / 57 bytes vs our 97 / ..)
typedef ATL::CRBMap<unsigned, ATL::CComPtr<Unk_RtePlayer> > RtePlayerMap;
typedef ATL::CRBMap<unsigned, ATL::CComPtr<Unk_UpperNpc> > RteNpcMap;

// @0x140aac710
CRandomTargetEffect* Unk_RtePlayer::GetEffectPtr() const
{
    return m_spEffect.get();
}

// @0x140aac6c0
MS2Ptr<CRandomTargetEffect> Unk_UpperNpc::GetEffect()
{
    return m_spEffect;
}

// @0x140aaadb0
CRandomTargetEffect::CRandomTargetEffect(void* pOwner)
    : m_pOwner(pOwner), m_nEffectId(0), m_spNode(0), m_fScale(1.0f), m_bVisible(false)
{
}

// @0x140aaae40
CRandomTargetEffect::~CRandomTargetEffect()
{
    Destroy();
}

// @0x140aaaea0
void CRandomTargetEffect::Create(CString strName)
{
    if (m_nEffectId != 0)
        Destroy();

    Unk_NodePtr spNode(NiNew NiNode(0));
    NiNode* pRoot = static_cast<NiNode*>(FUN_1403ed280()->FUN_1411a6b10());
    pRoot->AttachChild(static_cast<NiAVObject*>(FUN_1409475d0(&spNode)), false);
    NoticeMessage kRequest;
    kRequest.m_strName = strName;
    kRequest.m_nObject = 0;
    kRequest.SetActor(FUN_14123c580(m_pOwner));
    kRequest.m_spNode = static_cast<NiAVObject*>(FUN_1409475d0(&spNode));
    m_nEffectId = FUN_1403ed280()->FUN_1411a49c0(&kRequest);
    m_spNode = spNode;
    FUN_14098b3e0(FUN_1409475d0(&spNode), m_fScale, 0);
    UpdatePosition();
    SetVisible(false);
}

// @0x140aab080
void CRandomTargetEffect::Destroy()
{
    Hide();
    FUN_1403ed280()->FUN_1411a6060(m_nEffectId);
    FUN_140a0b2a0(FUN_1409475d0(&m_spNode));
    m_nEffectId = 0;
    FUN_1409f76f0(&m_spNode, 0);
}

// @0x140aab0f0
void CRandomTargetEffect::UpdatePosition()
{
    if (m_nEffectId == 0)
        return;
    if (m_spNode.FUN_1409f77a0(0))
        return;

    Unk_NodePtr spTarget(FUN_14098d8d0(&DAT_143afa4d8, FUN_141b6ef70(static_cast<Unk_RteOwner*>(m_pOwner)->FUN_14123c460())));
    if (spTarget.FUN_1409f77a0(0))
        return;

    NiTransform kTarget = static_cast<NiAVObject*>(FUN_1409475f0(&spTarget))->GetWorldTransform();
    NiTransform kWorld = static_cast<NiAVObject*>(FUN_1409475f0(&m_spNode))->GetWorldTransform();
    kWorld = kTarget;
    kWorld.m_Translate.z += 150.0f;
    static_cast<NiAVObject*>(FUN_1409475f0(&m_spNode))->SetWorldTranslate(kWorld.m_Translate);
    static_cast<NiAVObject*>(FUN_1409475f0(&m_spNode))->SetWorldRotate(kWorld.m_Rotate);
    static_cast<NiAVObject*>(FUN_1409475f0(&m_spNode))->SetWorldScale(kWorld.m_fScale);
    static_cast<NiAVObject*>(FUN_1409475f0(&m_spNode))->SetLocalFromWorldTransform(kWorld);
}

// @0x140aab2e0
void CRandomTargetEffect::SetVisible(bool bVisible)
{
    if (bVisible)
        Show();
    else
        Hide();
}

// @0x140aab320
void CRandomTargetEffect::Show()
{
    if (m_nEffectId == 0)
        return;
    m_bVisible = true;
    FUN_1403ed280()->FUN_1411a68f0(m_nEffectId, m_bVisible);
}

// @0x140aab370
void CRandomTargetEffect::Hide()
{
    if (m_nEffectId == 0)
        return;
    m_bVisible = false;
    FUN_1403ed280()->FUN_1411a68f0(m_nEffectId, m_bVisible);
}

// @0x140aab3c0
// MS2-FUNCTIONAL: the exe returns the first call result without a spilled temporary (original expression form unknown)
bool CRandomTargetEffect::SetScale(float fScale)
{
    bool bResult = FUN_14028d470(m_fScale, fScale);
    if (!bResult)
    {
        m_fScale = fScale;
        bResult = m_spNode != 0;
    }
    return bResult;
}

// @0x140aab420
CRandomTargetEffectController::CRandomTargetEffectController()
    : m_nMode(0)
{
}

// @0x140aab4b0
CRandomTargetEffectController::~CRandomTargetEffectController()
{
}

// @0x140aab530
void CRandomTargetEffectController::Reset()
{
    m_aIdsA.RemoveAll();
    m_strEffectA.Empty();
    m_aIdsB.RemoveAll();
    m_strEffectB.Empty();
    m_nTick = 0;
    m_bToggle = false;
    m_nMode = 0;
}

// @0x140aab5b0
void CRandomTargetEffectController::StartSequence(const CAtlArray<unsigned>& aIds, CString strEffect)
{
    m_aIdsA.Copy(aIds);
    m_strEffectA = strEffect;
    for (size_t i = 0; i < m_aIdsA.GetCount(); ++i)
    {
        MS2Ptr<CRandomTargetEffect> spEffect = Find(m_aIdsA[i]);
        if (spEffect.get())
        {
            spEffect->Create(CString(m_strEffectA));
            spEffect->Hide();
        }
    }
    m_nTick = FUN_140869420();
    m_bToggle = false;
    m_nMode = 1;
    m_nIndex = 0;
}

// @0x140aab720
void CRandomTargetEffectController::StartFlicker(const CAtlArray<unsigned>& aIdsNew, CString strEffect)
{
    m_aIdsB.Copy(aIdsNew);
    m_strEffectB = strEffect;
    for (size_t i = 0; i < m_aIdsA.GetCount(); ++i)
    {
        MS2Ptr<CRandomTargetEffect> spEffect = Find(m_aIdsA[i]);
        if (spEffect.get())
            spEffect->Hide();
    }
    for (size_t i = 0; i < m_aIdsB.GetCount(); ++i)
    {
        MS2Ptr<CRandomTargetEffect> spEffect = Find(m_aIdsB[i]);
        if (spEffect.get())
        {
            spEffect->Create(CString(m_strEffectB));
            spEffect->Hide();
        }
    }
    m_nTick = FUN_140869420();
    m_bToggle = false;
    m_nMode = 2;
    m_nIndex = 0;
}

// @0x140aab950
void CRandomTargetEffectController::Stop()
{
    for (size_t i = 0; i < m_aIdsA.GetCount(); ++i)
    {
        MS2Ptr<CRandomTargetEffect> spEffect = Find(m_aIdsA[i]);
        if (spEffect.get())
        {
            spEffect->Hide();
            spEffect->Destroy();
        }
    }
    Reset();
    m_nTick = FUN_140869420();
    m_bToggle = false;
    m_nMode = 0;
    m_nIndex = 0;
}

// @0x140aaba50
void CRandomTargetEffectController::Update()
{
    if (m_nMode == 0)
        return;

    unsigned nNow = FUN_140869420();
    if (m_nMode == 1 && nNow - m_nTick > 300)
    {
        m_bToggle = !m_bToggle;
        m_nTick = nNow;
        for (size_t i = 0; i < m_aIdsA.GetCount(); ++i)
        {
            MS2Ptr<CRandomTargetEffect> spEffect = Find(m_aIdsA[i]);
            if (spEffect.get())
            {
                spEffect->SetVisible(false);
                if (i == m_nIndex)
                    spEffect->SetVisible(true);
            }
        }
        ++m_nIndex;
        if (m_nIndex >= m_aIdsA.GetCount())
            m_nIndex = 0;
    }
    if (m_nMode == 2 && nNow - m_nTick > 100)
    {
        m_bToggle = !m_bToggle;
        m_nTick = nNow;
        for (size_t i = 0; i < m_aIdsB.GetCount(); ++i)
        {
            MS2Ptr<CRandomTargetEffect> spEffect = Find(m_aIdsB[i]);
            if (spEffect.get())
                spEffect->SetVisible(true);
        }
    }
}

// @0x140aabd10
MS2Ptr<CRandomTargetEffect> CRandomTargetEffectController::FindByPlayerMap(unsigned nId)
{
    MS2Ptr<CRandomTargetEffect> spResult(0);
    RtePlayerMap* pMap = reinterpret_cast<RtePlayerMap*>(
        reinterpret_cast<WorldService*>(FUN_1403ed2d0())->FUN_141bd36b0());
    ATL::CComPtr<Unk_RtePlayer> spObj(NULL);
    pMap->Lookup(nId, spObj);
    if (spObj)
        spResult.AssignRaw(spObj->GetEffectPtr());
    return spResult;
}

// @0x140aabde0
MS2Ptr<CRandomTargetEffect> CRandomTargetEffectController::FindByNpcMap(unsigned nId)
{
    MS2Ptr<CRandomTargetEffect> spResult(0);
    RteNpcMap* pMap = reinterpret_cast<RteNpcMap*>(
        reinterpret_cast<WorldService*>(FUN_1403ed2d0())->FUN_141bd36d0());
    ATL::CComPtr<Unk_UpperNpc> spObj(NULL);
    pMap->Lookup(nId, spObj);
    if (spObj)
        spResult = spObj->GetEffect();
    return spResult;
}

// @0x140aabee0
MS2Ptr<CRandomTargetEffect> CRandomTargetEffectController::Find(unsigned nId)
{
    MS2Ptr<CRandomTargetEffect> spResult(0);
    void* pObj = reinterpret_cast<Unk_UpperPlayer*>(FUN_1403ed2d0())->FUN_141bd1180(nId);
    if (Unk_RtePlayer* pPlayer = FUN_14099eef0(pObj))
        spResult.AssignRaw(pPlayer->GetEffectPtr());
    else if (Unk_UpperNpc* pNpc = FUN_140a38a00(pObj))
        spResult = pNpc->GetEffect();
    return spResult;
}

MS2_EMIT_CRT_MEMMOVE_S();

// ---- typed entry points other units declare for this unit's COMDATs ----
#include "ms2/placeholder/tptr.h"
class PC;
class PCBase;
// The intrusive pointee: TPtr releases through vftable slot 2.
struct Unk_RteTPtrTarget
{
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void Release();
};

// TPtr<PC>::~TPtr (TPtr<PCBase>'s body is the same COMDAT).
// MS2-FUNCTIONAL: the slot-2 release through a stand-in pointee type
template <> TPtr<PC>::~TPtr()
{
    if (m_p)
        ((Unk_RteTPtrTarget*)m_p)->Release();
}

// MS2-FUNCTIONAL: the slot-2 release through a stand-in pointee type
template <> TPtr<PCBase>::~TPtr()
{
    if (m_p)
        ((Unk_RteTPtrTarget*)m_p)->Release();
}

// pc.cpp's view of SetScale (it drops the result).
class Unk_PCRandomTargetView
{
public:
    void FUN_140aab3c0(float fAlpha);
};

// MS2-FUNCTIONAL: forwards to CRandomTargetEffect::SetScale
void Unk_PCRandomTargetView::FUN_140aab3c0(float fAlpha)
{
    ((CRandomTargetEffect*)this)->SetScale(fAlpha);
}
