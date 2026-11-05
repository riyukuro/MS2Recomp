// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). See liftableobject.h.
// MS2-UNIT: ?\liftableobject.cpp
// MS2-RANGE: 0x141447080-0x141448190 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\liftableobject.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "liftableobject.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/cube.h"
#include "ms2/client/ms2/effectservice.h"
#include "ms2/placeholder/notifysystem.h"
#include <efd/SmartPointer.h>   // C3: efd::SmartPointer<CubeMapInformationService>::operator->
#include <egf/Entity.h>  // C3: egf::Entity::GetPropertyValue<bool>
#include <efd/ParseHelper.h>   // C3: ParseHelper<ID128>::ToString
#include <NiNode.h>   // C3: NiNode::ms_RTTI
#include <new>
#include "ms2/client/ms2/notifychangebuff.h"   // C3: NotifyAddLiftable
#include "ms2/client/ms2/cubemapinformationservice_3.h"   // C3: CubeMapInformationService::GetCubeByKey
class NoticeMessage   // C3: unit-local view (ctor 0x140a52ef0, dtor 0x1405a89e0, 0x70 bytes)
{
public:
    NoticeMessage();
    ~NoticeMessage();
    void* m_storage[14];
};
class CubeMapInformationService;   // C3: efd::SmartPointer<CubeMapInformationService>::operator->

// ---- unrecovered helpers (declared with their exe signatures) ----

// The effect / sound manager and its 0x78-byte play request (same shapes as functioncubeobject.cpp).
struct Unk_LiftSoundReq
{
    Unk_LiftSoundReq();                                             // 0x140a52ef0
    ~Unk_LiftSoundReq();                                            // 0x1405a89e0
    CString m_strName;                                              // +0x00
    int m_nType;                                                    // +0x08
    int m_nPad0c;                                                   // +0x0c
    void* m_unk[12];                                                // +0x10 node (assigned by SmartPointer<NiAVObject>::operator=, 0x1409fabf0) .. +0x68; 0x70 bytes (NoticeMessage)
};
NiAVObject* FUN_141b6efc0(egf::Entity* pEntity);                           // the scene-graph root of an entity
class Unk_SingletonObj* FUN_1401d31f0();   // C3: was FUN_1401d31f0

// The physics helper (singleton): collision group of the lifted prop.
class CPhysXHelper;
class Unk_AvPhysicsSvc* FUN_1409f7ca0();   // C3: was FUN_1409f7ca0
class NxGroupsMask;
class CPhysXHelper   // C3: member view for the former free stand-in
{
public:
    void FUN_141689ec0(egf::Entity* pEntity, unsigned short nGroup, const NxGroupsMask* pMask, int bRefresh);
};

// Entity properties read by hash.
void FUN_14098c6e0(class Unk_CachedEntity*, unsigned int, bool const&);   // C3: was FUN_14098c6e0

void FUN_1401d3700(CString& str);

// The item service handed out by the global at 0x143b059e8 (reference counted) and its cube lookup.
class Unk_LiftCube : public Cube
{
};
template <> efd::SmartPointer<CubeMapInformationService>::SmartPointer(CubeMapInformationService* pObject);     // 0x1401cd0b0
template <> efd::SmartPointer<CubeMapInformationService>::~SmartPointer();                               // 0x1401cd150
namespace egf { class ScriptContext; extern ScriptContext g_bapiContext; }
#include "ms2/placeholder/scriptcontext.h"   // egf::ScriptContext g_bapiContext (was a local framework view)
Unk_Int3 FUN_1408a1430(NiPoint3 kPos);   // C3: actionkeyobject.cpp's declaration (0x1408a1430)
int FUN_1408a03c0(Unk_Int3 pt);

// The "lift state changed" notice posted through the notify manager.

// Quest-mask checks (the quest manager's condition interface sits at +0x10).
struct Unk_LiftQuestCond
{
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual int vfunc_23(QuestMask* pMask);                         // 0xb8 the mask's condition holds
};
struct Unk_LiftQuestMgr
{
    char m_pad[0x10];
    Unk_LiftQuestCond m_cond;                                       // +0x10
};
void* FUN_140764020();   // C3: was FUN_140764020
int FUN_140764310(const CString& strA, const CString& strB, QuestMask* pMask);

// The entity's collision / highlight components and their calls.
float FUN_14028d280(unsigned nMs);                                  // milliseconds -> seconds
void FUN_141b71e70(egf::EntityID kId, bool bOn, unsigned int nArg, bool bFlag);   // the id by value
void FUN_140ae1e80(NiAVObject* pComp, float fA, float fB, float fC, float fD, egf::EntityID kId);
void FUN_14098b3e0(NiAVObject* pComp, float fA, bool bB);
void FUN_141567330(class NiAVObject*, bool);   // C3: was FUN_141567330
int FUN_140ae1c10();
class CGraphicOptionTable   // C3: member view for the former free stand-ins
{
public:
    int GetShadowOption(int);
};

// @0x141447080
CLiftableObject::CLiftableObject() : m_ent(0), m_bC2(true)
{
    m_ent = 0;
    m_nKind = 0;
    m_bFixed = 0;
    m_nA8 = 0;
    m_fRange = 150.0f;
    m_nEffect = 0;
}

// @0x1414471b0
CLiftableObject::~CLiftableObject()
{
    if (m_nEffect != 0)
    {
        TSingleton<CEffectService>::GetInstance()->FUN_1411a6060(m_nEffect);
        m_nEffect = 0;
    }
    m_ent = 0;
}

// @0x1414472a0
CString CLiftableObject::GetName() const
{
    return m_strName;
}

// @0x1414472f0
void CLiftableObject::SetName(CString strName)
{
    m_strName = strName;
}

// @0x141447340
int CLiftableObject::CanLift() const
{
    if (m_bC0 == 0)
        return 0;
    if (m_nKind <= 0)
        return 0;
    if (m_nState != 0)
        return 0;
    return 1;
}

// @0x141447390
int CLiftableObject::Init(Unk_Entity* pEntity, bool bFixed, int nKind)
{
    m_nKind = nKind;
    m_bC0 = 0;
    m_bC1 = 1;
    m_bFixed = bFixed;
    SetState(0);
    BindEntity(pEntity);
    return 1;
}

// @0x141447410
void CLiftableObject::BindEntity(Unk_Entity* pEntity)
{
    m_ent = (egf::Entity*)pEntity;
    if (m_ent == 0 != 0)
        return;
    if (m_bFixed == 0)
    {
        efd::utf8string name;
        efd::ParseHelper<efd::ID128>::ToString(((egf::Entity*)(class Unk_Entity*)(m_ent.operator->()))->GetDataFileID(), name);
        m_strName = name.c_str();
        FUN_1401d3700(m_strName);
    }
    float fRange = 150.0f;
    if (m_ent->GetPropertyValue<float>(0xf39fa2a1, fRange) == 0)
        m_fRange = fRange;
    m_ent->GetPropertyValue(0xd89e9b12, m_b108);
    m_ent->GetPropertyValue<efd::Point3>(0xfd95ca52, (efd::Point3&)(m_vC4));
    m_ent->GetPropertyValue<efd::Point3>(0x68c7c29d, (efd::Point3&)(m_v10c));
    if (m_bFixed == 0)
    {
        reinterpret_cast<egf::Entity*>(pEntity)->GetPropertyValue<unsigned int>(0x2e687f77, (unsigned int&)(m_nA8));
    }
    else
    {
        Vector3 pt;
        reinterpret_cast<egf::Entity*>(pEntity)->GetPropertyValue<efd::Point3>(0xfd95ca52, (efd::Point3&)(pt));
        efd::SmartPointer<CubeMapInformationService> spSvc(egf::g_bapiContext.GetSystemServiceAs<CubeMapInformationService>());
        Unk_Int3 cell = FUN_1408a1430(reinterpret_cast<const NiPoint3&>(pt));
        Unk_LiftCube* pCube = (Unk_LiftCube*)reinterpret_cast<CubeMapInformationService*>(spSvc.operator->())->GetCubeByKey(FUN_1408a03c0(cell));
        if (pCube != 0)
            m_nA8 = pCube->FUN_1408b4f20();
    }
    UpdateConditions();
    NotifySystem::GetInstance()->Post(MS2Ptr<NotifyObject>(new NotifyAddLiftable(this)));
}

// @0x1414477f0
void CLiftableObject::FUN_1414477f0(CString strA, CString strB)
{
    FUN_140764310(strA, strB, &m_maskA);
}

// @0x141447850
void CLiftableObject::FUN_141447850(CString strA, CString strB)
{
    FUN_140764310(strA, strB, &m_maskB);
}

// @0x1414478b0
void CLiftableObject::SetLiftEnabled(bool bValue)
{
    if (bValue == m_bC0)
        return;
    m_bC0 = bValue;
}

// @0x1414478f0
bool CLiftableObject::IsLiftEnabled() const
{
    return m_bC0;
}

// @0x141447910
void CLiftableObject::SetEffectEnabled(bool bOn)
{
    if (m_ent == 0 != 0)
        return;
    if (bOn && m_nEffect == 0)
    {
        NoticeMessage kReq;   // C3: was Unk_LiftSoundReq
        ((Unk_LiftSoundReq&)(kReq)).m_strName = *(CString*)((char*)((void*)FUN_1401d31f0()) + 0x350);
        ((Unk_LiftSoundReq&)(kReq)).m_nType = 0;
        *reinterpret_cast<efd::SmartPointer<NiAVObject>*>(((Unk_LiftSoundReq&)(kReq)).m_unk) = (NiAVObject*)NiObject::DynamicCast(&NiNode::ms_RTTI, (class NiObject const*)(FUN_141b6efc0(reinterpret_cast<egf::Entity*>(m_ent.data()))));
        m_nEffect = TSingleton<CEffectService>::GetInstance()->FUN_1411a49c0((Unk_EffectTarget&)(kReq));
    }
    else if (!bOn && m_nEffect != 0)
    {
        TSingleton<CEffectService>::GetInstance()->FUN_1411a6060(m_nEffect);
        m_nEffect = 0;
    }
}

// @0x141447a60
void CLiftableObject::SetKind(int nKind)
{
    m_nKind = nKind;
}

// @0x141447a80
int CLiftableObject::GetKind() const
{
    return m_nKind;
}

// @0x141447aa0
void CLiftableObject::FUN_141447aa0(bool bValue)
{
    m_bC2 = bValue;
}

// @0x141447ac0
float CLiftableObject::GetRange() const
{
    return m_fRange;
}

// @0x141447ae0
int CLiftableObject::GetState() const
{
    return m_nState;
}

// @0x141447b00
void CLiftableObject::SetState(int nState)
{
    m_nState = nState;
    if (m_ent == 0 != 0)
        return;
    switch (m_nState)
    {
    case 0:
    case 2:
        ((class CPhysXHelper*)FUN_1409f7ca0())->FUN_141689ec0(reinterpret_cast<egf::Entity*>(m_ent.data()), 9, 0, 1);
        FUN_141447ec0(1);
        break;
    case 1:
        ((class CPhysXHelper*)FUN_1409f7ca0())->FUN_141689ec0(reinterpret_cast<egf::Entity*>(m_ent.data()), 5, 0, 1);
        FUN_141447ec0(0);
        break;
    }
    UpdateConditions();
}

// @0x141447c10
void CLiftableObject::FUN_141447c10()
{
    if (m_timer.FUN_140868c00() != 0)
    {
        m_timer.FUN_1408687f0();
        bool bOff = false;
        FUN_14098c6e0((class Unk_CachedEntity*)(m_ent.operator->()), 0xa0b6b179, *(bool const*)(&bOff));
    }
}

// @0x141447c80
Vector3 CLiftableObject::FUN_141447c80() const
{
    return m_vC4;
}

// @0x141447cc0
int CLiftableObject::FUN_141447cc0() const
{
    return m_nA8;
}

// @0x141447ce0
Unk_Entity* CLiftableObject::FUN_141447ce0()
{
    return (Unk_Entity*)m_ent.data();
}

// @0x141447d10
int CLiftableObject::IsNotFixed() const
{
    return m_bFixed ? 0 : 1;
}

// @0x141447d50
void CLiftableObject::FUN_141447d50(int nOn)
{
    if (m_ent.data() == 0)
        return;
    FUN_141b71e70(((egf::Entity*)(class Unk_Entity*)(m_ent.operator->()))->GetEntityID(), nOn ? true : false, 1, 0);
}

// @0x141447de0
void CLiftableObject::UpdateConditions()
{
    if ((&((struct Unk_LiftQuestMgr*)FUN_140764020())->m_cond)->vfunc_23(&m_maskA))
        SetLiftEnabled(1);
    else
        SetLiftEnabled(0);
    if (m_bC2 != 0 && (&((struct Unk_LiftQuestMgr*)FUN_140764020())->m_cond)->vfunc_23(&m_maskB) && CanLift() != 0)
    {
        SetEffectEnabled(1);
        return;
    }
    SetEffectEnabled(0);
}

// @0x141447ec0
void CLiftableObject::FUN_141447ec0(bool bActive)
{
    m_bC1 = bActive;
    if (bActive)
    {
        if (m_ent.data() != 0)
        {
            bool bOn = true;
            FUN_14098c6e0((class Unk_CachedEntity*)(m_ent.operator->()), 0xa0b6b179, *(bool const*)(&bOn));
            void* pComp = FUN_141b6efc0(reinterpret_cast<egf::Entity*>(m_ent.data()));
            if (pComp != 0)
                FUN_14098b3e0((NiAVObject*)pComp, 1.0f, false);
        }
    }
    else
    {
        if (m_ent.data() != 0)
        {
            void* pComp = FUN_141b6efc0(reinterpret_cast<egf::Entity*>(m_ent.data()));
            if (pComp != 0)
                FUN_140ae1e80((NiAVObject*)pComp, 1.0f, 0.0f, 0.0f, FUN_14028d280(500), ((egf::Entity*)(class Unk_Entity*)(m_ent.operator->()))->GetEntityID());
        }
        m_timer.FUN_140868750(500);
    }
    FUN_141448050(bActive);
}

// @0x141448050
void CLiftableObject::FUN_141448050(bool bActive)
{
    if (m_ent == 0 != 0)
        return;
    if (bActive)
    {
        void* pComp = FUN_141b6efc0(reinterpret_cast<egf::Entity*>(m_ent.data()));
        if (pComp != 0 && m_b108 != 0)
        {
            bool bOn = FUN_140ae1c10() >= ((class CGraphicOptionTable*)(void*)(((void*)TSingleton<CGraphicOptionTable>::GetInstance())))->GetShadowOption(5);
            FUN_141567330((class NiAVObject*)(pComp), bOn);
        }
    }
    else
    {
        void* pComp = FUN_141b6efc0(reinterpret_cast<egf::Entity*>(m_ent.data()));
        if (pComp != 0)
            FUN_141567330((class NiAVObject*)(pComp), false);
    }
}
