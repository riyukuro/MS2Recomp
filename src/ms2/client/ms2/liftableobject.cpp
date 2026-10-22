// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). See liftableobject.h.
// MS2-UNIT: ?\liftableobject.cpp
// MS2-RANGE: 0x141447080-0x141448190 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\liftableobject.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "liftableobject.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unrecovered helpers (declared with their exe signatures) ----

// The effect / sound manager and its 0x78-byte play request (same shapes as functioncubeobject.cpp).
struct Unk_LiftSoundReq
{
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
Unk_LiftFxMgr* FUN_1403ed280();
void FUN_140a52ef0(Unk_LiftSoundReq* p);                            // construct
void FUN_1405a89e0(Unk_LiftSoundReq* p);                            // destroy
void FUN_1409fabf0(void* pSub, void* pAnchor);                      // construct the 0x68 block from an anchor
void* FUN_14098d8d0(void* pCell, void* pRoot);
extern char DAT_143afa4d8;
void* FUN_141b6efc0(Unk_Entity* pEntity);                           // the scene-graph root of an entity
void* FUN_1401d31f0();                                              // the string table (+0x350: the lift sound)

// The physics helper (singleton): collision group of the lifted prop.
class CPhysXHelper;
CPhysXHelper* FUN_1409f7ca0();
void FUN_141689ec0(CPhysXHelper* pHelper, Unk_Entity* pEntity, short nKind, int nArg, int bFlag);

// Entity properties read by hash.
int FUN_140961880(Unk_Entity* pEntity, unsigned nHash, float* pValue);
int FUN_1408a20a0(Unk_Entity* pEntity, unsigned nHash, bool* pValue);
int FUN_1409618c0(Unk_Entity* pEntity, unsigned nHash, Vector3* pValue);
int FUN_140ae11a0(Unk_Entity* pEntity, unsigned nHash, int* pValue);
void FUN_14098c6e0(Unk_Entity* pEntity, unsigned nHash, bool* pValue);

// The entity's model name (a 32-byte string object).
struct Unk_LiftName
{
    void* m_p[4];
};
void FUN_1408a8700(Unk_LiftName* p);                                // construct
void FUN_1408a8900(Unk_LiftName* p);                                // destroy
const char* FUN_1408ac310(Unk_LiftName* p);                         // c_str
void* FUN_140ae1be0(Unk_Entity* pEntity);
void FUN_140ae1f60(void* pModel, Unk_LiftName* pName);
void FUN_1401d3700(CString* p);

// The item service handed out by the global at 0x143b059e8 (reference counted) and its cube lookup.
class Unk_LiftCube
{
public:
    int FUN_1408b4f20();                                            // the item id
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
Unk_LiftSvc* FUN_1401cd040(char* pCell);
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
void* FUN_140939a10();                                              // the notify manager
void FUN_140da4fe0(void* pMgr, Unk_LiftNotifyPtr* pNotice);         // post

// Quest-mask checks (the quest manager's condition interface sits at +0x10).
void* FUN_140764020();
void FUN_140764310(const CString& strA, const CString& strB, QuestMask* pMask, void* pArg, long long nFlag);
static int Unk_LiftMaskCheck(void* pMgr, QuestMask* pMask)
{
    void* pIf = (char*)pMgr + 0x10;
    void** vt = *(void***)pIf;
    return ((int (*)(void*, QuestMask*))vt[0x17])(pIf, pMask);
}

// The entity's collision / highlight components and their calls.
float FUN_14028d280(unsigned nMs);                                  // milliseconds -> seconds
struct Unk_LiftHandle
{
    void* m_a;
    void* m_b;
    void* m_c;
};
void* FUN_1408b76f0(Unk_Entity* pEntity);
Unk_LiftHandle* FUN_1408b6b20(Unk_LiftHandle* pOut, void* pSrc);
void FUN_141b71e70(Unk_LiftHandle* pHandle, bool bOn, int nArg, bool bFlag);
void FUN_140ae1e80(void* pComp, float fA, float fB, float fC, float fD, Unk_LiftHandle* pHandle);
void FUN_14098b3e0(void* pComp, float fA, int nB);
void FUN_141567330(void* pComp, bool bOn);
int FUN_140ae1c10();
void* FUN_140ae1c00();
int FUN_141376880(void* pObj, int nKind);

// @0x141447080
CLiftableObject::CLiftableObject() : m_ent(0)
{
    m_bC2 = 1;
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
        FUN_1403ed280()->FUN_1411a6060(m_nEffect);
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
    if (m_nKind < 1)
        return 0;
    if (m_nState == 0)
        return 1;
    return 0;
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
            FUN_140ae1f60(FUN_140ae1be0(m_ent.FUN_1408a9280()), &name);
            m_strName = FUN_1408ac310(&name);
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
            FUN_1401cd0b0(&spSvc, FUN_1401cd040(&DAT_143b059e8));
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
        FUN_140da4fe0(FUN_140939a10(), FUN_140938f40(&spNotice, pBuilt));
    }
}

// @0x1414477f0
void CLiftableObject::FUN_1414477f0(CString strA, CString strB, void* pArg)
{
    FUN_140764310(strA, strB, &m_maskA, pArg, -2LL);
}

// @0x141447850
void CLiftableObject::FUN_141447850(CString strA, CString strB, void* pArg)
{
    FUN_140764310(strA, strB, &m_maskB, pArg, -2LL);
}

// @0x1414478b0
void CLiftableObject::FUN_1414478b0(char bValue)
{
    if (bValue != m_bC0)
        m_bC0 = bValue;
}

// @0x1414478f0
char CLiftableObject::FUN_1414478f0() const
{
    return m_bC0;
}

// @0x141447910
void CLiftableObject::FUN_141447910(char bOn)
{
    if (m_ent.FUN_1408b70b0(0) == 0)
    {
        if (bOn == 0 || m_nEffect != 0)
        {
            if (bOn == 0 && m_nEffect != 0)
            {
                FUN_1403ed280()->FUN_1411a6060(m_nEffect);
                m_nEffect = 0;
            }
        }
        else
        {
            Unk_LiftSoundReq kReq;
            FUN_140a52ef0(&kReq);
            kReq.m_strName = *(CString*)((char*)FUN_1401d31f0() + 0x350);
            kReq.m_nType = 0;
            FUN_1409fabf0(kReq.m_unk, FUN_14098d8d0(&DAT_143afa4d8, FUN_141b6efc0(m_ent.FUN_1408a9090())));
            m_nEffect = FUN_1403ed280()->FUN_1411a49c0(&kReq);
            FUN_1405a89e0(&kReq);
        }
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
void CLiftableObject::FUN_141447aa0(char bValue)
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
    int nCur = m_nState;
    if (nCur != 0)
    {
        if (nCur == 1)
        {
            FUN_141689ec0(FUN_1409f7ca0(), m_ent.FUN_1408a9090(), 5, 0, 1);
            FUN_141447ec0(0);
            goto done;
        }
        if (nCur != 2)
            goto done;
    }
    FUN_141689ec0(FUN_1409f7ca0(), m_ent.FUN_1408a9090(), 9, 0, 1);
    FUN_141447ec0(1);
done:
    FUN_141447de0();
}

// @0x141447c10
void CLiftableObject::FUN_141447c10()
{
    if (m_timer.FUN_140868c00() != 0)
    {
        m_timer.FUN_1408687f0();
        bool bOff = false;
        FUN_14098c6e0(m_ent.FUN_1408a9280(), 0xa0b6b179, &bOff);
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
bool CLiftableObject::FUN_141447d10() const
{
    return m_bFixed == 0;
}

// @0x141447d50
void CLiftableObject::FUN_141447d50(int nOn)
{
    if (m_ent.FUN_1408a9090() != 0)
    {
        Unk_LiftHandle kHandle;
        FUN_141b71e70(FUN_1408b6b20(&kHandle, FUN_1408b76f0(m_ent.FUN_1408a9280())), nOn != 0, 1, 0);
    }
}

// @0x141447de0
void CLiftableObject::FUN_141447de0()
{
    int nRes = Unk_LiftMaskCheck(FUN_140764020(), &m_maskA);
    if (nRes == 0)
        FUN_1414478b0(0);
    else
        FUN_1414478b0(1);
    if (m_bC2 != 0)
    {
        nRes = Unk_LiftMaskCheck(FUN_140764020(), &m_maskB);
        if (nRes != 0 && FUN_141447340() != 0)
        {
            FUN_141447910(1);
            return;
        }
    }
    FUN_141447910(0);
}

// @0x141447ec0
void CLiftableObject::FUN_141447ec0(char bActive)
{
    m_bC1 = bActive;
    if (bActive == 0)
    {
        if (m_ent.FUN_1408a9090() != 0)
        {
            void* pComp = FUN_141b6efc0(m_ent.FUN_1408a9090());
            if (pComp != 0)
            {
                Unk_LiftHandle kHandle;
                Unk_LiftHandle* pHandle = FUN_1408b6b20(&kHandle, FUN_1408b76f0(m_ent.FUN_1408a9280()));
                FUN_140ae1e80(pComp, 1.0f, 0.0f, 0.0f, FUN_14028d280(500), pHandle);
            }
        }
        m_timer.FUN_140868750(500);
    }
    else
    {
        if (m_ent.FUN_1408a9090() != 0)
        {
            bool bOn = true;
            FUN_14098c6e0(m_ent.FUN_1408a9280(), 0xa0b6b179, &bOn);
            void* pComp = FUN_141b6efc0(m_ent.FUN_1408a9090());
            if (pComp != 0)
                FUN_14098b3e0(pComp, 1.0f, 0);
        }
    }
    FUN_141448050(bActive);
}

// @0x141448050
void CLiftableObject::FUN_141448050(char bActive)
{
    if (m_ent.FUN_1408b70b0(0) == 0)
    {
        if (bActive == 0)
        {
            void* pComp = FUN_141b6efc0(m_ent.FUN_1408a9090());
            if (pComp != 0)
                FUN_141567330(pComp, false);
        }
        else
        {
            void* pComp = FUN_141b6efc0(m_ent.FUN_1408a9090());
            if (pComp != 0 && m_b108 != 0)
            {
                int nNow = FUN_140ae1c10();
                int nLimit = FUN_141376880(FUN_140ae1c00(), 5);
                FUN_141567330(pComp, nLimit <= nNow);
            }
        }
    }
}
