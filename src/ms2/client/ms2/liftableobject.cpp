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

// ---- unrecovered helpers (declared with their exe signatures) ----

// The effect / sound manager and its 0x78-byte play request (same shapes as functioncubeobject.cpp).
struct Unk_LiftSoundReq
{
    Unk_LiftSoundReq();                                             // 0x140a52ef0
    ~Unk_LiftSoundReq();                                            // 0x1405a89e0
    CString m_strName;                                              // +0x00
    int m_nType;                                                    // +0x08
    int m_nPad0c;                                                   // +0x0c
    void* m_unk[13];                                                // +0x10 (constructed by FUN_1409fabf0)
};
class Unk_LiftFxMgr
{
public:
    int FUN_1411a49c0(Unk_LiftSoundReq* pRequest);                  // play, returns the handle
    void FUN_1411a6060(int nHandle);                                // stop
};
void FUN_1409fabf0(void* pSub, void* pAnchor);                      // construct the 0x68 block from an anchor
extern char DAT_143afa4d8;
void* FUN_141b6efc0(Unk_Entity* pEntity);                           // the scene-graph root of an entity
class Unk_SingletonObj* FUN_1401d31f0();   // C3: was FUN_1401d31f0

// The physics helper (singleton): collision group of the lifted prop.
class CPhysXHelper;
class Unk_AvPhysicsSvc* FUN_1409f7ca0();   // C3: was FUN_1409f7ca0
void FUN_141689ec0(CPhysXHelper* pHelper, Unk_Entity* pEntity, short nKind, int nArg, int bFlag);

// Entity properties read by hash.
int FUN_140961880(Unk_Entity* pEntity, unsigned nHash, float* pValue);
int FUN_1408a20a0(Unk_Entity* pEntity, unsigned nHash, bool* pValue);
int FUN_1409618c0(Unk_Entity* pEntity, unsigned nHash, Vector3* pValue);
int FUN_140ae11a0(Unk_Entity* pEntity, unsigned nHash, int* pValue);
void FUN_14098c6e0(class Unk_CachedEntity*, unsigned int, bool const&);   // C3: was FUN_14098c6e0

// The entity's model name (a 32-byte string object).
struct Unk_LiftName
{
    void* m_p[4];
};
void FUN_1408a8700(Unk_LiftName* p);                                // construct
void FUN_1408a8900(Unk_LiftName* p);                                // destroy
void FUN_140ae1f60(void* pModel, Unk_LiftName* pName);
void FUN_1401d3700(CString* p);

// The item service handed out by the global at 0x143b059e8 (reference counted) and its cube lookup.
class Unk_LiftCube : public Cube
{
};
class Unk_LiftSvc
{
public:
    virtual ~Unk_LiftSvc();
    virtual void vfunc_1();                                         // AddRef
    virtual void vfunc_2();                                         // Release
    Unk_LiftCube* FUN_1410b8b00(int nKey);
};
struct Unk_LiftSvcPtr
{
    Unk_LiftSvc* m_p;
};
extern char DAT_143b059e8;
class Unk_Service6100017* FUN_1401cd040(struct Unk_EntityAppFramework*);   // C3: was FUN_1401cd040
void FUN_1401cd0b0(Unk_LiftSvcPtr* pThis, Unk_LiftSvc* p);          // construct
Unk_LiftSvc* FUN_1401cd1a0(Unk_LiftSvcPtr* pThis);                  // operator->
void FUN_1401cd150(Unk_LiftSvcPtr* pThis);                          // destroy
Vector3 FUN_1408a1430(Vector3 pt);
int FUN_1408a03c0(Vector3 pt);

// The "lift state changed" notice posted through the notify manager.
struct Unk_LiftNotifyPtr
{
    void* m_a;
    void* m_b;
};
void* FUN_140db4ab0(void* pMem, CLiftableObject* pOwner);          // construct the notice
Unk_LiftNotifyPtr* FUN_140938f40(Unk_LiftNotifyPtr* pPtr, void* pNotice);   // smart pointer from raw
void FUN_140da4fe0(void* pMgr, Unk_LiftNotifyPtr* pNotice);         // post

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
void FUN_140764310(const CString& strA, const CString& strB, QuestMask* pMask);

// The entity's collision / highlight components and their calls.
float FUN_14028d280(unsigned nMs);                                  // milliseconds -> seconds
struct Unk_LiftHandle
{
    Unk_LiftHandle(void* pSrc);                                     // 0x1408b6b20
    Unk_LiftHandle(const Unk_LiftHandle& other);                    // never called: the by-value args are built in place
    void* m_a;
    void* m_b;
};
void FUN_141b71e70(Unk_LiftHandle kHandle, bool bOn, int nArg, bool bFlag);   // the handle by value
void FUN_140ae1e80(void* pComp, float fA, float fB, float fC, float fD, Unk_LiftHandle kHandle);
void FUN_14098b3e0(void* pComp, float fA, int nB);
void FUN_141567330(class NiAVObject*, bool);   // C3: was FUN_141567330
int FUN_140ae1c10();
void* FUN_140ae1c00();
class CGraphicOptionTable   // C3: member view for the former free stand-ins
{
public:
    int GetShadowOption(int);
};

// @0x141447080
CLiftableObject::CLiftableObject() : m_ent(0), m_bC2(true)
{
    m_ent.FUN_1408b6ec0(0);
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
        reinterpret_cast<Unk_LiftFxMgr*>(TSingleton<CEffectService>::GetInstance())->FUN_1411a6060(m_nEffect);
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
int CLiftableObject::FUN_141447340() const
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
int CLiftableObject::FUN_141447390(Unk_Entity* pEntity, bool bFixed, int nKind)
{
    m_nKind = nKind;
    m_bC0 = 0;
    m_bC1 = 1;
    m_bFixed = bFixed;
    FUN_141447b00(0);
    FUN_141447410(pEntity);
    return 1;
}

// @0x141447410
// MS2-FUNCTIONAL: written from the decompile; the callbacks' temporaries are not matched
void CLiftableObject::FUN_141447410(Unk_Entity* pEntity)
{
    m_ent.FUN_1408b6ec0(pEntity);
    if (m_ent.FUN_1408b70b0(0) == 0)
    {
        if (m_bFixed == 0)
        {
            Unk_LiftName name;
            FUN_1408a8700(&name);
            FUN_140ae1f60(((void*)&((egf::Entity*)(class Unk_Entity*)(m_ent.FUN_1408a9280()))->GetDataFileID()), &name);
            m_strName = ((efd::utf8string*)(struct Unk_LiftName*)(&name))->c_str();
            FUN_1401d3700(&m_strName);
            FUN_1408a8900(&name);
        }
        float fRange = 150.0f;
        if (FUN_140961880(m_ent.FUN_1408a9280(), 0xf39fa2a1, &fRange) == 0)
            m_fRange = fRange;
        FUN_1408a20a0(m_ent.FUN_1408a9280(), 0xd89e9b12, (bool*)&m_b108);
        FUN_1409618c0(m_ent.FUN_1408a9280(), 0xfd95ca52, &m_vC4);
        FUN_1409618c0(m_ent.FUN_1408a9280(), 0x68c7c29d, &m_v10c);
        if (m_bFixed == 0)
        {
            FUN_140ae11a0(pEntity, 0x2e687f77, &m_nA8);
        }
        else
        {
            Vector3 pt;
            FUN_1409618c0(pEntity, 0xfd95ca52, &pt);
            Unk_LiftSvcPtr spSvc;
            FUN_1401cd0b0(&spSvc, ((class Unk_LiftSvc*)FUN_1401cd040((struct Unk_EntityAppFramework*)(&DAT_143b059e8))));
            Vector3 cell = FUN_1408a1430(pt);
            int nKey = FUN_1408a03c0(cell);
            Unk_LiftCube* pCube = FUN_1401cd1a0(&spSvc)->FUN_1410b8b00(nKey);
            if (pCube != 0)
                m_nA8 = pCube->FUN_1408b4f20();
            FUN_1401cd150(&spSvc);
        }
        FUN_141447de0();
        void* pNotice = ::operator new(0x20);
        void* pBuilt = pNotice ? FUN_140db4ab0(pNotice, this) : 0;
        Unk_LiftNotifyPtr spNotice;
        FUN_140da4fe0(NotifySystem::GetInstance(), FUN_140938f40(&spNotice, pBuilt));
    }
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
void CLiftableObject::FUN_1414478b0(bool bValue)
{
    if (bValue == m_bC0)
        return;
    m_bC0 = bValue;
}

// @0x1414478f0
bool CLiftableObject::FUN_1414478f0() const
{
    return m_bC0;
}

// @0x141447910
void CLiftableObject::FUN_141447910(bool bOn)
{
    if (m_ent.FUN_1408b70b0(0) != 0)
        return;
    if (bOn && m_nEffect == 0)
    {
        Unk_LiftSoundReq kReq;
        kReq.m_strName = *(CString*)((char*)((void*)FUN_1401d31f0()) + 0x350);
        kReq.m_nType = 0;
        FUN_1409fabf0(kReq.m_unk, ((void*)NiObject::DynamicCast((class NiRTTI const*)(&DAT_143afa4d8), (class NiObject const*)(FUN_141b6efc0(m_ent.FUN_1408a9090())))));
        m_nEffect = reinterpret_cast<Unk_LiftFxMgr*>(TSingleton<CEffectService>::GetInstance())->FUN_1411a49c0(&kReq);
    }
    else if (!bOn && m_nEffect != 0)
    {
        reinterpret_cast<Unk_LiftFxMgr*>(TSingleton<CEffectService>::GetInstance())->FUN_1411a6060(m_nEffect);
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
void CLiftableObject::FUN_141447b00(int nState)
{
    m_nState = nState;
    if (m_ent.FUN_1408b70b0(0) != 0)
        return;
    switch (m_nState)
    {
    case 0:
    case 2:
        FUN_141689ec0(((class CPhysXHelper*)FUN_1409f7ca0()), m_ent.FUN_1408a9090(), 9, 0, 1);
        FUN_141447ec0(1);
        break;
    case 1:
        FUN_141689ec0(((class CPhysXHelper*)FUN_1409f7ca0()), m_ent.FUN_1408a9090(), 5, 0, 1);
        FUN_141447ec0(0);
        break;
    }
    FUN_141447de0();
}

// @0x141447c10
void CLiftableObject::FUN_141447c10()
{
    if (m_timer.FUN_140868c00() != 0)
    {
        m_timer.FUN_1408687f0();
        bool bOff = false;
        FUN_14098c6e0((class Unk_CachedEntity*)(m_ent.FUN_1408a9280()), 0xa0b6b179, *(bool const*)(&bOff));
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
void CLiftableObject::FUN_141447ce0()
{
    m_ent.FUN_1408a9090();
}

// @0x141447d10
int CLiftableObject::FUN_141447d10() const
{
    return m_bFixed ? 0 : 1;
}

// @0x141447d50
void CLiftableObject::FUN_141447d50(int nOn)
{
    if (m_ent.FUN_1408a9090() == 0)
        return;
    FUN_141b71e70(((void*)&((egf::Entity*)(class Unk_Entity*)(m_ent.FUN_1408a9280()))->GetEntityID()), nOn ? true : false, 1, 0);
}

// @0x141447de0
void CLiftableObject::FUN_141447de0()
{
    if ((&((struct Unk_LiftQuestMgr*)FUN_140764020())->m_cond)->vfunc_23(&m_maskA))
        FUN_1414478b0(1);
    else
        FUN_1414478b0(0);
    if (m_bC2 != 0 && (&((struct Unk_LiftQuestMgr*)FUN_140764020())->m_cond)->vfunc_23(&m_maskB) && FUN_141447340() != 0)
    {
        FUN_141447910(1);
        return;
    }
    FUN_141447910(0);
}

// @0x141447ec0
void CLiftableObject::FUN_141447ec0(bool bActive)
{
    m_bC1 = bActive;
    if (bActive)
    {
        if (m_ent.FUN_1408a9090() != 0)
        {
            bool bOn = true;
            FUN_14098c6e0((class Unk_CachedEntity*)(m_ent.FUN_1408a9280()), 0xa0b6b179, *(bool const*)(&bOn));
            void* pComp = FUN_141b6efc0(m_ent.FUN_1408a9090());
            if (pComp != 0)
                FUN_14098b3e0(pComp, 1.0f, 0);
        }
    }
    else
    {
        if (m_ent.FUN_1408a9090() != 0)
        {
            void* pComp = FUN_141b6efc0(m_ent.FUN_1408a9090());
            if (pComp != 0)
                FUN_140ae1e80(pComp, 1.0f, 0.0f, 0.0f, FUN_14028d280(500), ((void*)&((egf::Entity*)(class Unk_Entity*)(m_ent.FUN_1408a9280()))->GetEntityID()));
        }
        m_timer.FUN_140868750(500);
    }
    FUN_141448050(bActive);
}

// @0x141448050
void CLiftableObject::FUN_141448050(bool bActive)
{
    if (m_ent.FUN_1408b70b0(0) != 0)
        return;
    if (bActive)
    {
        void* pComp = FUN_141b6efc0(m_ent.FUN_1408a9090());
        if (pComp != 0 && m_b108 != 0)
        {
            bool bOn = FUN_140ae1c10() >= ((class CGraphicOptionTable*)(void*)(FUN_140ae1c00()))->GetShadowOption(5);
            FUN_141567330((class NiAVObject*)(pComp), bOn);
        }
    }
    else
    {
        void* pComp = FUN_141b6efc0(m_ent.FUN_1408a9090());
        if (pComp != 0)
            FUN_141567330((class NiAVObject*)(pComp), false);
    }
}
