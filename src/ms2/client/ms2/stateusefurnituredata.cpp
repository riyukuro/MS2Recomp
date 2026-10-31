// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). StateUseFurniture / StateUseFurnitureData: the actor state of a
// player sitting or lying on a housing furniture cube and the MS2Ptr<StateUseFurnitureData> glue it instantiates.
// See stateusefurnituredata.h.
// MS2-UNIT: ?\stateusefurnituredata.cpp
// MS2-RANGE: 0x141282a50-0x141284ac0 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\stateusefurnituredata.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"

#include <new>
#include <string.h>
#include <egf/Entity.h>
#include <efd/utf8string.h>
#include <NiNode.h>
#include <NiActorManager.h>
#include <NiControllerSequence.h>

#ifdef __clang__
// vfunc_4 assigns the position from the address of vfunc_18's returned temporary (an MSVC extension).
#pragma clang diagnostic ignored "-Waddress-of-temporary"
#endif

#include "stateusefurnituredata.h"

#include "ms2/client/ms2/pcbase.h"
#include "ms2/placeholder/chomeprivilege.h"
#include "ms2/client/ms2/mypc.h"
#include "ms2/client/ms2/functioncubeobject.h"
#include "ms2/placeholder/effectquery.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/client/ms2/effectservice.h"

// ---- unit-local views of unrecovered callees ------------------------------------------------------------------------

// The state-sync record (slots 1/2 of StateData): the key is kept at +0x70.
class Unk_StateDataArg
{
public:
    char m_pad_00[0x70];
    CString m_str70;                                         // +0x70
    char m_pad_78[0xb8 - 0x78];
};
MS2_CHECK_OFFSET(Unk_StateDataArg, m_str70, 0x70);

extern Vector3 DAT_143b01a60;                       // the zero point
extern NiRTTI DAT_143afa4d8;                                // RTTI NiNode

// The skill record of a ride / sit target (CPtred, a point at +0x50 where the player is put).
class Unk_PCBaseComp_b18 : public CPtred
{
public:
    char m_pad_18[0x38];
    Vector3 m_vPos50;                                // +0x50
};
class CSkillRecord : public Unk_PCBaseComp_b18 {};

// The direction as the buff set returns it; vfunc_22 gets a sliced copy of the
// return temporary.
struct Unk_UfDirRet : public efd::Point3
{
};

// The buff set of the actor.
class Unk_UfBuff
{
public:
    bool FUN_141682fe0(int nId);                             // has a buff
    bool FUN_141683100(int nId);                             // has a buff (kind)
    Unk_UfDirRet FUN_141683290();                            // the knock-back direction
};

CFunctionCubeService* FUN_1409670b0();
bool FUN_1402a5b40(const CString& a, const char* b);       // CString != C string

// The effect manager: plays an effect for a request (returns its id), stops it by id.
class Unk_UfEffectMgr
{
public:
    unsigned FUN_1411a49c0(Unk_EffectQuery* pQuery);
    void FUN_1411a4a00(Unk_EffectQuery* pQuery);
};

// The animation service: the name of the sequence of an actor, the cached actor manager.
class Unk_UfAnimSvc
{
public:
    efd::utf8string FUN_1409a1790(const egf::EntityID& kId, unsigned int nSeq);
};
Unk_UfAnimSvc* FUN_141b6f910();
NiActorManager* FUN_140999440(Unk_UfAnimSvc* pSvc, const egf::EntityID& kId);   // cached actor manager
float FUN_140a53fa0(NiControllerSequence* pSeq);             // NiControllerSequence::m_fOffset

// The data row of a furniture cube (an inline copy of the exe at 0x140ca6580 in the homemade unit).
class Unk_HmCube : public CFunctionCubeObject
{
public:
    MS2Ptr<FunctionCubeData> FUN_140ca6580();
};

// The use request of one cube (id + count), serialized by FUN_1401fc610.
struct Unk_UfUseInfo
{
    Unk_UfUseInfo() : m_nCount(0) {}                         // 0x140ac2e80
    ~Unk_UfUseInfo() {}                                      // 0x140ac3050
    CString m_strId;                                         // +0x00
    int m_nCount;                                            // +0x08
    int m_nPad0c;
};
void FUN_1401fc610(Unk_UfUseInfo* pInfo, COutPacket* pPacket);

// The scene graph of an entity and the NiNode helpers the exe calls out of line.
NiAVObject* FUN_141b6efc0(void* pEntity);                    // the scene root of an entity
NiTransform* FUN_140a35c30(NiTransform* pDst, const NiTransform& kSrc);   // NiTransform::operator=
void FUN_140a35bd0(NiTransform* pDst, const NiTransform* pSrc);           // NiTransform assignment
// NiTransform::operator* (a view of the transform; the result is returned by value).
struct Unk_UfXform
{
    NiTransform FUN_140a33de0(const NiTransform& kOther) const;
};
void FUN_140b86230(const Vector3& kEuler, Unk_NiMatrix3& kOut);   // matrix of euler angles (degrees)
void FUN_140a0b1f0(const Unk_NiMatrix3& kRot, Vector3* pOut);

// Explicit views of the MS2Ptr members instantiated by earlier objs (FunctionCubeData / CFunctionCubeObject).
template <> MS2Ptr<CFunctionCubeObject>::MS2Ptr();                              // 0x14111e8c0
template <> MS2Ptr<CFunctionCubeObject>::~MS2Ptr();                             // 0x1409648f0
template <> CFunctionCubeObject* MS2Ptr<CFunctionCubeObject>::operator->() const;   // 0x1409658e0
template <> CFunctionCubeObject* MS2Ptr<CFunctionCubeObject>::get() const;      // 0x1409657b0
template <> bool MS2Ptr<CFunctionCubeObject>::operator==(CFunctionCubeObject* p) const;   // 0x140965280
template <> MS2Ptr<CFunctionCubeObject>& MS2Ptr<CFunctionCubeObject>::operator=(const MS2Ptr& o);   // 0x140dd7170
template <> MS2Ptr<CFunctionCubeObject>& MS2Ptr<CFunctionCubeObject>::operator=(int);   // 0x141126230
template <> MS2Ptr<FunctionCubeData>::MS2Ptr(const MS2Ptr& o);                  // 0x140ca60f0
template <> MS2Ptr<FunctionCubeData>::~MS2Ptr();                                // 0x140ca62a0
template <> FunctionCubeData* MS2Ptr<FunctionCubeData>::operator->() const;     // 0x1409658d0

// NiPoint3 with the exe's out-of-line conversion ctor and move assignment.
struct Unk_CamNiPoint3
{
    Unk_CamNiPoint3(const Vector3& pt);                                 // 0x14027dcf0
    Unk_CamNiPoint3& operator=(Unk_CamNiPoint3&& pt);                   // 0x14097faa0
    float x, y, z;
};

int FUN_140de9280(const efd::utf8string& s, const char* psz);   // compare

// @0x141284840
inline bool UfEqual(const char* psz, const efd::utf8string& s)
{
    return FUN_140de9280(s, psz) == 0;
}

// ---- StateUseFurnitureData ----

// @0x141282a50
StateUseFurnitureData::StateUseFurnitureData()
{
}

// @0x141282aa0
StateUseFurnitureData::StateUseFurnitureData(CString strKey) : m_strKey(strKey)
{
}

// @0x141282b10
void StateUseFurnitureData::vfunc_1(Unk_StateDataArg* p)
{
    StateData::vfunc_1(p);
    p->m_str70 = m_strKey;
}

// @0x141282b60
void StateUseFurnitureData::vfunc_2(Unk_StateDataArg* p)
{
    StateData::vfunc_2(p);
    m_strKey = p->m_str70;
}

// ---- StateUseFurniture ----

// @0x141282bb0
StateUseFurniture::StateUseFurniture(PCBase* pOwner) : State(pOwner), m_nEffect(0), m_n64(0)
{
    m_n14 = 0;
}

// @0x141282c50
StateUseFurniture::~StateUseFurniture()
{
}

// @0x141282ca0
void StateUseFurniture::vfunc_4(StateData* pData)
{
    State::vfunc_4(pData);
    m_n64 = 0;
    m_spFurniture.AssignRaw(dynamic_cast<StateUseFurnitureData*>(pData));
    if (m_spFurniture.get())
    {
        m_spCube = FUN_1409670b0()->FUN_141230c00(m_spFurniture->m_strKey);
    }
    else
    {
        m_spFurniture.AssignRaw(new StateUseFurnitureData());
        PCBase* pMe = FUN_1417b8370();
        if (pMe != 0)
            m_spCube = FUN_1409670b0()->FUN_141230c00(m_spFurniture->m_strKey);
    }
    if (m_spCube.get())
    {
        bool bAction = !static_cast<Unk_HmCube*>(m_spCube.operator->())->FUN_140ca6580()->m_strB8.IsEmpty();
        if (bAction)
            m_pOwner->FUN_14166ef10(static_cast<Unk_HmCube*>(m_spCube.operator->())->FUN_140ca6580()->m_strB8, 1, 0, false);
        bool bModel = FUN_1402a5b40(static_cast<Unk_HmCube*>(m_spCube.operator->())->FUN_140ca6580()->m_strModel, "");
        if (bModel)
            m_pOwner->FUN_14166dd20((const char*)static_cast<Unk_HmCube*>(m_spCube.operator->())->FUN_140ca6580()->m_strModel, 1.0f, false, false);
        bool bEffect = FUN_1402a5b40(static_cast<Unk_HmCube*>(m_spCube.operator->())->FUN_140ca6580()->m_strC0, "");
        if (bEffect)
        {
            Unk_EffectQuery kQuery;
            kQuery.m_strName = static_cast<Unk_HmCube*>(m_spCube.operator->())->FUN_140ca6580()->m_strC0;
            kQuery.m_nObject = (FUN_1417b8560() != 0) ? 1 : 3;
            kQuery.SetActor(m_pOwner->FUN_14123c580());
            m_nEffect = reinterpret_cast<Unk_UfEffectMgr*>(TSingleton<CEffectService>::GetInstance())->FUN_1411a49c0(&kQuery);
        }
    }
    PCBase* pPC = FUN_1417b8370();
    if (pPC != 0)
        m_vPos = *reinterpret_cast<const Vector3*>(&pPC->vfunc_18());
}

// @0x141283340
// MS2-FUNCTIONAL: same calls as the exe; stack slots, the vfunc_19 arg copies (exe copies kPos twice) and the scale arg loads differ
void StateUseFurniture::vfunc_3(double fTime)
{
    State::vfunc_3(fTime);
    if (m_spCube == 0)
        return;
    if (m_n64 != 0)
    {
        bool bModel = FUN_1402a5b40(static_cast<Unk_HmCube*>(m_spCube.operator->())->FUN_140ca6580()->m_strModel, "");
        if (bModel)
        {
            NiActorManager* pMgr = FUN_140999440(FUN_141b6f910(), m_spCube->FUN_141226eb0());
            if (pMgr != 0)
            {
                NiControllerSequence* pSeq = pMgr->GetActiveSequence(static_cast<NiActorManager*>(pMgr)->GetCurAnimation(), true, true);
                if (pSeq != 0)
                {
                    float fLen = FUN_140a53fa0(pSeq);
                    m_pOwner->FUN_14166de50(fLen);
                    m_n64 = 0;
                }
            }
        }
    }
    int nType = static_cast<Unk_HmCube*>(m_spCube.operator->())->FUN_140ca6580()->m_n90;
    if (nType != 0)
    {
        Unk_EntRef kEnt = m_spCube->GetEnt();
        NiNode* pNode = static_cast<NiNode*>(NiObject::DynamicCast(&DAT_143afa4d8, FUN_141b6efc0(kEnt.FUN_1408a9090())));
        if (pNode)
        {
            NiNode* pChild = static_cast<NiNode*>(NiObject::DynamicCast(&DAT_143afa4d8, pNode->GetObjectByName((const char*)static_cast<Unk_HmCube*>(m_spCube.get())->FUN_140ca6580()->m_strStr98)));
            if (pChild)
            {
                NiTransform kXf = static_cast<NiAVObject*>(pChild)->GetLocalTransform();
                NiTransform kParent;
                kParent.MakeIdentity();
                if (static_cast<NiAVObject*>(pChild)->GetParent() != 0)
                    FUN_140a35c30(&kParent, static_cast<NiAVObject*>(static_cast<NiAVObject*>(pChild)->GetParent())->GetWorldTransform());
                FUN_140a35bd0(&kXf, &reinterpret_cast<const Unk_UfXform*>(&kParent)->FUN_140a33de0(kXf));
                Vector3 kPos = *reinterpret_cast<const Vector3*>(&kXf.m_Translate);
                Unk_NiMatrix3 kRot = *reinterpret_cast<const Unk_NiMatrix3*>(&kXf.m_Rotate);
                Vector3 kDir;
                Vector3 kEuler = DAT_143b01a60;
                kEuler = Vector3(static_cast<Unk_HmCube*>(m_spCube.operator->())->FUN_140ca6580()->m_vAC.x,
                    static_cast<Unk_HmCube*>(m_spCube.operator->())->FUN_140ca6580()->m_vAC.y,
                    static_cast<Unk_HmCube*>(m_spCube.operator->())->FUN_140ca6580()->m_vAC.z);
                Unk_NiMatrix3 kAdd;
                FUN_140b86230(kEuler, kAdd);
                Unk_NiMatrix3 kProd(kRot.FUN_140a33480(kAdd));
                kRot = kProd;
                FUN_140a0b1f0(kRot, &kDir);
                Vector3 kCol0;
                kRot.FUN_140a01190(0, kCol0);
                kCol0.FUN_140968990();
                Vector3 kCol1;
                kRot.FUN_140a01190(1, kCol1);
                kCol1.FUN_140968990();
                Vector3 kCol2;
                kRot.FUN_140a01190(2, kCol2);
                kCol2.FUN_140968990();
                reinterpret_cast<Unk_CamNiPoint3&>(kPos) = Unk_CamNiPoint3(kPos.FUN_14097fd50(
                    kCol1.FUN_14097fc90(-static_cast<Unk_HmCube*>(m_spCube.operator->())->FUN_140ca6580()->m_vA0.y)));
                reinterpret_cast<Unk_CamNiPoint3&>(kPos) = Unk_CamNiPoint3(kPos.FUN_14097fd50(
                    kCol0.FUN_14097fc90(static_cast<Unk_HmCube*>(m_spCube.operator->())->FUN_140ca6580()->m_vA0.x)));
                reinterpret_cast<Unk_CamNiPoint3&>(kPos) = Unk_CamNiPoint3(kPos.FUN_14097fd50(
                    kCol2.FUN_14097fc90(static_cast<Unk_HmCube*>(m_spCube.operator->())->FUN_140ca6580()->m_vA0.z)));
                m_pOwner->vfunc_19(reinterpret_cast<const efd::Point3&>(kPos));
                m_pOwner->vfunc_21(reinterpret_cast<const efd::Point3&>(kDir));
            }
        }
        else
        {
            NiPoint3 kPos = m_pOwner->vfunc_18();
            kPos.z = kPos.z - static_cast<Unk_HmCube*>(m_spCube.get())->FUN_140ca6580()->m_vA0.z;
            m_pOwner->vfunc_59(1, 0, 0, 0);
        }
    }
}

// @0x141283d80
// MS2-FUNCTIONAL: vfunc_22 takes efd::Point3 by value in the exe (16-aligned arg copy at 0x70, ours 0x68)
void StateUseFurniture::vfunc_8(double fTime)
{
    State::vfunc_8(fTime);
    MyPC* pPC = FUN_1417b84b0();
    if (pPC == 0)
        return;
    Unk_UfBuff* pBuff = (Unk_UfBuff*)pPC->FUN_14166d240();
    pPC->vfunc_22(efd::Point3(pBuff->FUN_141683290()));
    if (pBuff->FUN_141683100(0x30d41))
        pPC->FUN_1415248d0(1, 0);
    else if (pBuff->FUN_141683100(0x30d42))
        pPC->FUN_1415248d0(2, 0);
    else if (pPC->FUN_141671a30() != 0 && pBuff->FUN_141682fe0(0x493e1))
        pPC->vfunc_59(6, 0, 0x25, 0);
    else if (m_pOwner->FUN_1416749c0())
        pPC->vfunc_59(2, 0, 0, 0);
    else if (pBuff->FUN_141682fe0(0x493e5))
        pPC->vfunc_59(3, 0, 0, 0);
    else
    {
        MS2Ptr<Unk_PCBaseComp_b18> spRec = pPC->vfunc_104(true, false, false);
        if (spRec.get() != 0)
        {
            spRec->m_vPos50 = m_vPos;
            pPC->vfunc_19(reinterpret_cast<const efd::Point3&>(m_vPos));
            pPC->vfunc_102(reinterpret_cast<MS2Ptr<CSkillRecord>&>(spRec));
        }
    }
}

// @0x141284050
void StateUseFurniture::vfunc_5(int n)
{
    State::vfunc_5(n);
    if (m_nEffect != 0)
        reinterpret_cast<CEffectService*>(reinterpret_cast<Unk_UfEffectMgr*>(TSingleton<CEffectService>::GetInstance()))->FUN_1411a6060(m_nEffect);
    bool bEffect = (m_spCube.get() != 0 ? true : false) &&
        FUN_1402a5b40(static_cast<Unk_HmCube*>(m_spCube.operator->())->FUN_140ca6580()->m_strC8, "");
    if (bEffect)
    {
        Unk_EffectQuery kQuery;
        kQuery.m_strName = static_cast<Unk_HmCube*>(m_spCube.operator->())->FUN_140ca6580()->m_strC8;
        kQuery.m_nObject = (FUN_1417b8560() != 0) ? 1 : 3;
        kQuery.SetActor(m_pOwner->FUN_14123c580());
        reinterpret_cast<Unk_UfEffectMgr*>(TSingleton<CEffectService>::GetInstance())->FUN_1411a4a00(&kQuery);
    }
    PCBase* pPC = FUN_1417b8370();
    if (pPC != 0)
    {
        if (m_spCube.get() != 0)
        {
            MyPC* pMe = FUN_1417b84b0();
            if (pMe != 0)
            {
                Unk_UfUseInfo kUse;
                kUse.m_strId = m_spCube->FUN_141226bd0();
                kUse.m_nCount = 1;
                COutPacket packet(static_cast<int>(SendOp::FunctionCube), 0);
                packet.Encode1(5);
                packet.Encode4(1);
                FUN_1401fc610(&kUse, &packet);
                FUN_140710590(packet);
            }
            pPC->vfunc_19(reinterpret_cast<const efd::Point3&>(m_vPos));
        }
        efd::Point3 kRot = reinterpret_cast<const efd::Point3&>(DAT_143b01a60);
        kRot.z = pPC->vfunc_20().z;
        pPC->FUN_14166d970(kRot);
    }
    m_spCube = 0;
    m_spFurniture = 0;
}

// @0x141284470
void StateUseFurniture::AnimActivated(NiActorManager* pkManager, unsigned int eSequenceID,
    NiControllerSequence* pkSeq, float fEventTime)
{
    if (m_spCube == 0)
        return;
    bool bNone = (static_cast<Unk_HmCube*>(m_spCube.get())->FUN_140ca6580() == 0);
    if (bNone)
        return;
    if (m_n64 == 0)
    {
        efd::utf8string kName = FUN_141b6f910()->FUN_1409a1790(m_pOwner->FUN_14123c460(), eSequenceID);
        if (UfEqual((const char*)static_cast<Unk_HmCube*>(m_spCube.get())->FUN_140ca6580()->m_strModel, kName))
            m_n64 = 1;
    }
}

// @0x141284620
CString StateUseFurniture::FUN_141284620()
{
    if (m_spFurniture.get() != 0)
        return m_spFurniture->m_strKey;
    return CString();
}

// @0x141284920
MS2Ptr<StateData> StateUseFurniture::vfunc_27()
{
    return MS2Ptr<StateData>(new StateUseFurnitureData());
}

// @0x1412849a0
int StateUseFurniture::vfunc_1()
{
    return 0x29;
}
