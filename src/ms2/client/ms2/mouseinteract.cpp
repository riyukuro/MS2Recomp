// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// MS2-UNIT: ?\mouseinteract.cpp
// MS2-RANGE: 0x140a78f70-0x140a7bb20 .text$mn
// MS2-PIN: ??0Unk_MiVec3@@QEAA@AEBUUnk_Vec3@@@Z 0x14027dcf0
// MS2-PIN: ??0Unk_MiVec3@@QEAA@AEBVNiPoint3@@@Z 0x14027dcf0
// MS2-PIN: ??0Unk_MiNpcRecPtr@@QEAA@AEBUUnk_MiNpcDataPtr@@@Z 0x1406cf850
// MS2-PIN: ??1Unk_MiNpcRecPtr@@QEAA@XZ 0x14035e5b0
// MS2-PIN: ??1Unk_MiNpcDataPtr@@QEAA@XZ 0x1406d5390
// MS2-PIN: ??0Unk_PortalHit@@QEAA@H@Z 0x140964110
// MS2-PIN: ??1Unk_PortalHit@@QEAA@XZ 0x140964a70
// MS2-PIN: ??CUnk_PortalHit@@QEAAPEAUUnk_Portal@@XZ 0x140965960
// MS2-PIN: ??0Unk_IdArray@@QEAA@XZ 0x140182ea0
// MS2-PIN: ??1Unk_IdArray@@QEAA@XZ 0x140183b60
// MS2-PIN: ??0Unk_MiCompRef@@QEAA@PEAX@Z 0x1408b6680
// MS2-PIN: ??1Unk_MiCompRef@@QEAA@XZ 0x1408a8720
// MS2-PIN: ??0Unk_ObjectHit@@QEAA@H@Z 0x140963fd0
// MS2-PIN: ??1Unk_ObjectHit@@QEAA@XZ 0x1409649b0
// MS2-PIN: ??CUnk_ObjectHit@@QEAAPEAUUnk_ObjectEnt@@XZ 0x140965920
// MS2-PIN: ??0Unk_ObjArray@@QEAA@XZ 0x140963a20
// MS2-PIN: ??1Unk_ObjArray@@QEAA@XZ 0x140964700
// MS2-PIN: ??1Unk_DataRef@@QEAA@XZ 0x140520fc0
// MS2-PIN: ??CUnk_DataRef@@QEAAPEADXZ 0x1405212e0
// MS2-PIN: ??0Unk_WeaponHit@@QEAA@H@Z 0x140964170
// MS2-PIN: ??0Unk_WeaponHit@@QEAA@AEBU0@@Z 0x140884f70
// MS2-PIN: ??1Unk_WeaponHit@@QEAA@XZ 0x140885120
// MS2-PIN: ??CUnk_WeaponHit@@QEAAPEAUUnk_WeaponEnt@@XZ 0x140885350
// MS2-PIN: ??1Unk_DmIter@@QEAA@XZ 0x1409f20e0
// MS2-PIN: ??CUnk_DmIter@@QEAAPEAUUnk_DmList@@XZ 0x1409f2190
// MS2-PIN: ??0Unk_MiDmRef@@QEAA@PEAX@Z 0x1408a7ed0
// MS2-PIN: ??1Unk_MiDmRef@@QEAA@XZ 0x1408a8720
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\mouseinteract.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "mouseinteract.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "uiobject.h"
#include "pcbase.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/cnpc.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/client/ms2/uiservice.h"
#include "ms2/client/ms2/worldservice.h"

// ---- RTTI-only action classes (the picker compares the player's current action against the picked object) ----
class ActionKeyObject { public: virtual ~ActionKeyObject(); };
class TalkAction : public ActionKeyObject { public: char m_pad[0x10]; int m_nNpcId; };                  // +0x18
class HoldAction : public ActionKeyObject { public: char m_pad[0x18]; int m_nNpcId; };                  // +0x20
struct PortalAction : public ActionKeyObject { char m_pad[0x10]; int FUN_140956110(); };   // a struct (.?AUPortalAction@@): as a class the cast never matched
class InteractAction : public ActionKeyObject { public: char m_pad[0x10]; CStringA m_strObjectId; };    // +0x18
class PullObjectWeaponAction : public ActionKeyObject { public: char m_pad[0x10]; char m_hit[16]; };    // +0x18
class UITalkCinematic : public UIObject {};

// ---- exe callees ----
struct Unk_MiPlayer;
struct Unk_MiActionState;
CStringW GetStringCommon(int nStringId);
CStringW GetStringCommonByKey(const CStringW& str);
CStringW FUN_1405c2690(CStringW fmt, const CStringW& arg);
CStringW FUN_1408f71a0(CStringW fmt, const CStringW& a, const CStringW& b);
       // npc name (member: this=rcx, hidden return=rdx)
unsigned FUN_141092fa0(PCBase* pNpc);                    // npc id
int FUN_141093c60(PCBase* pNpc);
void FUN_140194470(Unk_Vec3* pDst, const Unk_Vec3* pSrc);
// the exe's vector type has a copy ctor (0x14027dcf0); a ctor-less float struct local would get a /GS cookie
struct Unk_MiVec3 { float x, y, z; Unk_MiVec3(const Unk_Vec3& v); Unk_MiVec3(const NiPoint3& v); };
bool FUN_14147ad10(const struct Unk_MiVec3& vOrigin, const struct Unk_MiVec3& vEnd, const struct Unk_MiVec3& vCenter, float fRadius);
bool FUN_14028d470(float a, float b);
extern char DAT_143b01a60;

struct Unk_NpcTree;
class Unk_MiWorld
{
public:
    Unk_MiPlayer* FUN_141bd0cc0();                          // the local player
    Unk_NpcTree* FUN_141bd36d0();                           // npc tree
    void FUN_141bc2980(struct Unk_IdArray& out);            // portal ids
    struct Unk_PortalHit FUN_141bc2800(unsigned nId);
    void FUN_141bc5f10(struct Unk_ObjArray& out);            // interactable objects
    struct Unk_DmIter FUN_141bd0420(unsigned nKey);
};
Unk_MiActionState* Unk_PlayerActionState(Unk_MiPlayer* pPlayer);
int FUN_140953530(Unk_MiActionState* p);                    // current action type
ActionKeyObject* FUN_140953550(Unk_MiActionState* p);       // current action
void FUN_140953310(Unk_MiActionState* p);                   // cancel
int FUN_141527160(Unk_MiPlayer* pPlayer, int nFlag);
int FUN_14166c930(Unk_MiPlayer* pPlayer);
bool FUN_1401c0090(const CStringA* a, const CStringA* b);
void* FUN_1409331e0();
int FUN_14138c900(void* p, int n);
void* FUN_140967100();
int FUN_141b211d0(void* p);
int FUN_14123c660(PCBase* p);
int FUN_140855d10(unsigned nId);

// smart pointer to the data record of an npc (16 bytes)
struct Unk_DataRef                                          // object component data smart pointer
{
    void* m_pad;
    void* m_p;
    ~Unk_DataRef();                                         // 0x140520fc0
    bool FUN_140965160();                                   // null test
    char* operator->();                                     // 0x1405212e0
};
struct Unk_MiNpcData { int FUN_1406cd020(); };
struct Unk_MiNpcDataPtr                                     // MS2Ptr<npc data> returned by the npc (16 bytes)
{
    void* m_pad;
    Unk_MiNpcData* m_p;
    Unk_MiNpcDataPtr(const Unk_MiNpcDataPtr& sp);
    ~Unk_MiNpcDataPtr();                                    // 0x1406d5390
    Unk_MiNpcData* FUN_140965990();                         // operator->
};
struct Unk_MiNpcRecPtr                                      // the npc's model record handle (16 bytes)
{
    void* m_pad;
    void* m_p;
    Unk_MiNpcRecPtr(const Unk_MiNpcDataPtr& sp);            // 0x1406cf850
    ~Unk_MiNpcRecPtr();                                     // 0x14035e5b0
    bool FUN_14035e9b0();                                   // null test
    char* FUN_14035eb90();                                  // operator->
};
struct Unk_MiNpcRef { Unk_MiNpcDataPtr FUN_141093270(); };  // npc data (member: this=rcx, hidden return=rdx)


// ---- npc list iteration (a red-black tree of smart pointers, root at +0, nil node at +0x28) ----
// CAtlRBTree CNode: key +0, value (PCBaseRef) +8, color +0x10, left +0x18, right +0x20, parent +0x28 (exe 0x140a7b980
// reads [p+0x18], 0x140a7b9f0 [p+0x20]/[p+0x28])
struct Unk_NpcNode { char m_pad_00[0x18]; Unk_NpcNode* m_pLeft; Unk_NpcNode* m_pRight; Unk_NpcNode* m_pParent; };
struct PCBaseRef
{
    PCBase* m_p;
    // @0x140a7b390
    PCBaseRef(const PCBaseRef& r) : m_p(r.m_p) { if (m_p) m_p->IncRefCount(); }
    // @0x140a7b530
    ~PCBaseRef() { if (m_p) m_p->DecRefCount(); }
    // @0x140a7b650
    operator PCBase*() const { return m_p; }
    // @0x140a7b660
    PCBase* operator->() const { return m_p; }
};
void AtlThrow(long hr);
struct Unk_NpcTree
{
    Unk_NpcNode* m_pRoot;
    char m_pad_08[0x20];
    Unk_NpcNode* m_pNil;
    Unk_NpcNode* Begin();
    Unk_NpcNode* GetNext(Unk_NpcNode*& pos);
    PCBaseRef* GetAt(Unk_NpcNode* pos);
    bool IsNil(Unk_NpcNode* p);
    Unk_NpcNode* Minimum(Unk_NpcNode* p);
    Unk_NpcNode* Successor(Unk_NpcNode* p);
};
// @0x140a7b840
Unk_NpcNode* Unk_NpcTree::Begin()
{
    return Minimum(m_pRoot);
}
// @0x140a7b860
Unk_NpcNode* Unk_NpcTree::GetNext(Unk_NpcNode*& pos)
{
    Unk_NpcNode* pCur = pos;
    pos = Successor(pCur);
    return pCur;
}
// @0x140a7b8e0
PCBaseRef* Unk_NpcTree::GetAt(Unk_NpcNode* pos)
{
    do                                                      // ATLENSURE(pos != NULL)
    {
        int nCond = !!(pos != 0);
        do {} while (0);
        if (!nCond)
            AtlThrow(0x80004005L);
    } while (0);
    return reinterpret_cast<PCBaseRef*>(reinterpret_cast<char*>(pos) + 8);
}
// @0x140a7b940
bool Unk_NpcTree::IsNil(Unk_NpcNode* p)
{
    return p == m_pNil;
}
// @0x140a7b980
Unk_NpcNode* Unk_NpcTree::Minimum(Unk_NpcNode* p)
{
    if (p == 0 || IsNil(p))
        return 0;
    Unk_NpcNode* pCur = p;
    while (!IsNil(pCur->m_pLeft))
        pCur = pCur->m_pLeft;
    return pCur;
}
// @0x140a7b9f0
Unk_NpcNode* Unk_NpcTree::Successor(Unk_NpcNode* p)
{
    Unk_NpcNode* pNext;
    if (p == 0)
        return 0;
    if (!IsNil(p->m_pRight))
        return Minimum(p->m_pRight);
    pNext = p->m_pParent;
    Unk_NpcNode* pChild = p;
    while (!IsNil(pNext) && pChild == pNext->m_pRight) {
        pChild = pNext;
        pNext = pNext->m_pParent;
    }
    if (IsNil(pNext))
        pNext = 0;
    return pNext;
}

// ---- hit-result wrappers (16 bytes: unknown qword + the pointer at +8) ----
struct Unk_Portal { char m_pad[0x4c]; float m_fRadius; CStringW FUN_14169c3b0(); NiPoint3 FUN_14169d2f0(); int FUN_14169d280(); };   // cursor text (member: this=rcx, hidden return=rdx)
struct Unk_PortalHit
{
    void* m_pad;
    Unk_Portal* m_p;
    Unk_PortalHit(int n);                                   // 0x140964110
    Unk_PortalHit(Unk_PortalHit&& r);
    ~Unk_PortalHit();                                       // 0x140964a70
    bool FUN_140965190();                                   // null test
    bool FUN_1409652c0(Unk_Portal* p);                      // m_p == p
    Unk_Portal* operator->();                               // 0x140965960
};

struct Unk_ObjectEnt { virtual int vf0(); virtual int vf1(); virtual int vf2(); virtual int vf3(); virtual int vf4(); virtual int vf5();
    CStringA FUN_140967060();
    NiPoint3 FUN_1409673c0();
    unsigned FUN_140967110();
    struct Unk_DataRef FUN_140966e00(); };   // object id (member: this=rcx, hidden return=rdx)
struct Unk_ObjectHit
{
    void* m_pad;
    Unk_ObjectEnt* m_p;
    Unk_ObjectHit(int n);                                   // 0x140963fd0
    Unk_ObjectHit(const Unk_ObjectHit& r);
    Unk_ObjectHit(Unk_ObjectHit&& r);
    ~Unk_ObjectHit();                                       // 0x1409649b0
    bool IsNil();
    void AddRefIfSet();
    void AddRef(void* pUnused);
    Unk_ObjectEnt* operator->();                            // 0x140965920
};
struct Unk_IdArray
{
    void* m_pad[3];
    Unk_IdArray();                                          // 0x140182ea0
    ~Unk_IdArray();                                         // 0x140183b60
    size_t FUN_1401910d0();                                 // GetCount
    unsigned& FUN_1404f0a10(size_t i);                      // operator[]
};
struct Unk_ObjArray
{
    void* m_pad[4];
    Unk_ObjArray();                                         // 0x140963a20
    ~Unk_ObjArray();                                        // 0x140964700
    size_t FUN_140966d80();                                 // GetCount
    Unk_ObjectHit& FUN_140965610(size_t i);                 // operator[]
};


struct Unk_DmList
{
    void* FUN_1409f2490();                                  // GetHeadPosition
    void* FUN_1409f23c0(void* pos);                         // GetAt
    void FUN_1409f24c0(void*& pos);                         // GetNext
};
struct Unk_DmIter                                           // smart pointer to the model list
{
    void* m_pad;
    Unk_DmList* m_p;
    ~Unk_DmIter();                                          // 0x1409f20e0
    Unk_DmList* operator->();                               // 0x1409f2190
};
struct Unk_MiDmRef                                          // model entity smart pointer
{
    void* m_p;
    Unk_MiDmRef(void* p);                                   // 0x1408a7ed0
    ~Unk_MiDmRef();                                         // 0x1408a8720
    void* FUN_1408a9090();                                  // get
    void* FUN_1408a9280();                                  // operator->
};
struct Unk_DmNodeRef { void* m_p; };
void* FUN_1409670f0();
void* FUN_1411cf440(void* pSvc, void* pKey);                    // EntityWorldManager: entity by id (rax)
struct Unk_MiCompRef                                        // entity component smart pointer (8 bytes)
{
    void* m_p;
    Unk_MiCompRef(void* pEntity);                           // 0x1408b6680 (AddRef)
    ~Unk_MiCompRef();                                       // 0x1408a8720
    void* FUN_1408a9090();                                  // get
    void* FUN_1408a9280();                                  // operator->
};
void* FUN_1408a9280(Unk_DmNodeRef* p);
void FUN_1409618c0(void* pObj, unsigned nHash, Unk_Vec3* pOut);

// ---- weapon objects ----
struct Unk_WeaponEnt { char m_pad_00[0x18]; unsigned long long m_qwId; char m_pad_20[0x28]; int m_n48; char m_pad_4c[4]; int m_n50;
    NiPoint3 FUN_1408b5370(); };
struct Unk_WeaponHit
{
    void* m_pad;
    Unk_WeaponEnt* m_p;
    Unk_WeaponHit(int n);                                   // 0x140964170
    Unk_WeaponHit(const Unk_WeaponHit& r);                  // 0x140884f70
    Unk_WeaponHit(Unk_WeaponHit&& r);
    ~Unk_WeaponHit();                                       // 0x140885120
    Unk_WeaponEnt* FUN_140885330();                         // get
    Unk_WeaponEnt* operator->();                            // 0x140885350
};
bool FUN_140885220(void* p);                            // MS2Ptr<Cube>::operator!
Unk_WeaponEnt* FUN_140885350(void* p);
void FUN_1408a20a0(void* pDst, unsigned nHash, bool* pOut);
void FUN_1408a2020(void* pDst, unsigned nHash, int* pOut);
struct Unk_WeaponMgr { void FUN_1410d59c0(struct Unk_WeaponArray& out); };
Unk_WeaponMgr* FUN_1401cd040(void* p);
extern char DAT_143b059e8;

// ---- CAtlArray<Unk_WeaponHit>-like array: data, size, max, grow ----
struct Unk_WeaponArray
{
    Unk_WeaponHit* m_pData;
    size_t m_nSize;
    size_t m_nMaxSize;
    int m_nGrowBy;
    Unk_WeaponArray();
    ~Unk_WeaponArray();
    size_t GetCount();
    Unk_WeaponHit* GetAt(size_t i);
    static void CallDestructors(Unk_WeaponHit* p, size_t n) throw();
};
Unk_WeaponHit* Unk_WeaponHitDelDtor(Unk_WeaponHit* p, unsigned nFlags);
void FUN_140885120(Unk_WeaponHit* p);                  // the dtor, as the deleting dtor calls it
void FUN_140159b70(long hr);

// @0x140a7b350
Unk_WeaponArray::Unk_WeaponArray()
{
    m_pData = 0;
    m_nSize = 0;
    m_nMaxSize = 0;
    m_nGrowBy = 0;
}
// @0x140a7b4f0
Unk_WeaponArray::~Unk_WeaponArray()
{
    if (m_pData != 0) {
        CallDestructors(m_pData, m_nSize);
        free(m_pData);
    }
}
// @0x140a7b830
size_t Unk_WeaponArray::GetCount()
{
    return m_nSize;
}
// @0x140a7b610
Unk_WeaponHit* Unk_WeaponArray::GetAt(size_t i)
{
    if (i >= m_nSize)
        FUN_140159b70(0x80070057L);
    return m_pData + i;
}
// @0x140a7b7b0
void Unk_WeaponArray::CallDestructors(Unk_WeaponHit* p, size_t n) throw()
{
    for (size_t i = 0; i < n; i++)
        Unk_WeaponHitDelDtor(p + i, 0);
}
// @0x140a7b670
Unk_WeaponHit* Unk_WeaponHitDelDtor(Unk_WeaponHit* p, unsigned nFlags)
{
    FUN_140885120(p);
    if ((nFlags & 1) != 0)
        operator delete(p, sizeof(Unk_WeaponHit));
    return p;
}

// move helpers: take the pointer out of the source
// @0x140a7b3e0
Unk_ObjectHit::Unk_ObjectHit(Unk_ObjectHit&& r)
{
    m_p = r.m_p;
    r.m_p = 0;
}
// @0x140a7b410
Unk_ObjectHit::Unk_ObjectHit(const Unk_ObjectHit& r)
{
    m_p = r.m_p;
    AddRefIfSet();
}
// @0x140a7b450
Unk_PortalHit::Unk_PortalHit(Unk_PortalHit&& r)
{
    m_p = r.m_p;
    r.m_p = 0;
}
// @0x140a7b480
Unk_WeaponHit::Unk_WeaponHit(Unk_WeaponHit&& r)
{
    m_p = r.m_p;
    r.m_p = 0;
}
// @0x140a7b5e0
bool Unk_ObjectHit::IsNil()
{
    return m_p == 0;
}
void FUN_140968e90(Unk_ObjectEnt* p);
// @0x140a7baf0
void Unk_ObjectHit::AddRef(void* pUnused)
{
    FUN_140968e90(m_p);
}
// @0x140a7bac0
void Unk_ObjectHit::AddRefIfSet()
{
    if (m_p != 0)
        AddRef(0);
}

struct Unk_MiPlayer { char m_pad[0x1338]; char m_actionState[8]; };
// @0x140a7b810
Unk_MiActionState* Unk_PlayerActionState(Unk_MiPlayer* pPlayer)
{
    return reinterpret_cast<Unk_MiActionState*>(pPlayer->m_actionState);
}

// @0x140a78f70
CMouseInteract::CMouseInteract()
{
}
// @0x140a78fb0
CMouseInteract::~CMouseInteract()
{
}
// @0x140a78fe0
int CMouseInteract::vfunc_1(Unk_MouseRay* pRay)
{
    return false;
}
// @0x140a79000
int CMouseInteract::vfunc_2(Unk_MouseRay* pRay)
{
    return false;
}
// @0x140a79020
int CMouseInteract::vfunc_3()
{
    return false;
}
// @0x140a79030
int CMouseInteract::vfunc_4()
{
    Unk_MiPlayer* pPlayer = reinterpret_cast<Unk_MiWorld*>(WorldService::GetInstance())->FUN_141bd0cc0();
    if (pPlayer == 0)
        return 0;
    FUN_140953310(Unk_PlayerActionState(pPlayer));
    return 1;
}
// @0x140a79080
void CMouseInteract::vfunc_5()
{
}
// @0x140a7b8a0
int CMouseInteract::vfunc_6()
{
    return 0;
}

// ---- npc ----
// @0x140a79090
int CMouseInteractNpc::vfunc_1(Unk_MouseRay* pRay)
{
    PCBase* pNpc = FindTarget(&pRay->vOrigin, &pRay->vEnd);
    if (pNpc != 0) {
        FUN_140194470(&pRay->vPick, reinterpret_cast<const Unk_Vec3*>(&static_cast<const NiPoint3&>(pNpc->vfunc_18())));
        if (pNpc->vfunc_117() != 0) {
            pRay->strCursor = FUN_1405c2690(CStringW(L"s_mouse_interact_hold"), reinterpret_cast<CNpc*>(pNpc)->FUN_141093310());
        } else {
            CStringW strName = TSingleton<CStringTable>::GetInstance()->FUN_141811980(0xe, FUN_141092fa0(pNpc));
            if (strName.GetLength() == 0)
                strName = GetStringCommon(0x62d);
            pRay->strCursor = FUN_1408f71a0(CStringW(L"s_mouse_interact_talk"), strName, reinterpret_cast<CNpc*>(pNpc)->FUN_141093310());
        }
        return true;
    }
    return false;
}
// @0x140a79340
int CMouseInteractNpc::vfunc_2(Unk_MouseRay* pRay)
{
    PCBase* pNpc = FindTarget(&pRay->vOrigin, &pRay->vEnd);
    if (pNpc != 0) {
        FUN_140194470(&pRay->vPick, reinterpret_cast<const Unk_Vec3*>(&static_cast<const NiPoint3&>(pNpc->vfunc_18())));
        if (pNpc->vfunc_117() != 0)
            m_nAction = 6;
        else
            m_nAction = 0x14;
        m_nNpcId = FUN_141092fa0(pNpc);
        return true;
    }
    return false;
}
// @0x140a79400
int CMouseInteractNpc::vfunc_3()
{
    Unk_MiPlayer* pPlayer = reinterpret_cast<Unk_MiWorld*>(WorldService::GetInstance())->FUN_141bd0cc0();
    if (pPlayer == 0)
        return false;
    if (FUN_140953530(Unk_PlayerActionState(pPlayer)) != m_nAction)
        return false;
    if (m_nAction == 0x14) {
        TalkAction* pAct = dynamic_cast<TalkAction*>(FUN_140953550(Unk_PlayerActionState(pPlayer)));
        if (pAct == 0)
            return false;
        return pAct->m_nNpcId == m_nNpcId;
    } else if (m_nAction == 6) {
        HoldAction* pAct = dynamic_cast<HoldAction*>(FUN_140953550(Unk_PlayerActionState(pPlayer)));
        if (pAct == 0)
            return false;
        return pAct->m_nNpcId == m_nNpcId;
    }
    return false;
}
// @0x140a79550
void CMouseInteractNpc::vfunc_5()
{
    m_nAction = 0x1e;
    m_nNpcId = 0;
}
// @0x140a79580
PCBase* CMouseInteractNpc::FindTarget(const Unk_Vec3* pOrigin, const Unk_Vec3* pEnd)
{
    Unk_MiPlayer* pPlayer = reinterpret_cast<Unk_MiWorld*>(WorldService::GetInstance())->FUN_141bd0cc0();
    if (pPlayer == 0)
        return 0;
    int bTalk = 1;
    int bHold = 1;
    if (FUN_14138c900(FUN_1409331e0(), 2) != 0)
        bTalk = 0;
    if (FUN_141b211d0(FUN_140967100()) == 0)
        bTalk = 0;
    if (FUN_14166c930(pPlayer) == 0x20)
        bHold = 0;
    Unk_NpcTree* pTree = reinterpret_cast<Unk_MiWorld*>(WorldService::GetInstance())->FUN_141bd36d0();
    for (Unk_NpcNode* pos = pTree->Begin(); pos != 0; pTree->GetNext(pos)) {
        PCBaseRef ref(*pTree->GetAt(pos));
        if (FUN_14123c660(ref.operator->()) != 0)
            continue;
        if (ref->vfunc_116() == 0)
            continue;
        Unk_MiNpcRecPtr spRec(reinterpret_cast<Unk_MiNpcRef*>(ref.operator->())->FUN_141093270());
        if (spRec.FUN_14035e9b0())
            continue;
        int bPick = 0;
        if (reinterpret_cast<Unk_MiNpcRef*>(ref.operator->())->FUN_141093270().FUN_140965990()->FUN_1406cd020() != 0 && bTalk != 0)
            bPick = 1;
        if (FUN_140855d10(FUN_141092fa0(ref.operator->())) != 0 && bTalk != 0)
            bPick = 1;
        if (FUN_141093c60(ref.operator->()) != 4 && bTalk != 0)
            bPick = 1;
        if (ref->vfunc_117() != 0 && bHold != 0)
            bPick = 1;
        if (bPick == 0)
            continue;
        float fSize = *(float*)(spRec.FUN_14035eb90() + 0x2dc);
        Unk_MiVec3 vCenter(ref->vfunc_18());
        vCenter.z += fSize * 0.5;
        if (FUN_14147ad10(*pOrigin, *pEnd, vCenter, (float)(fSize * 0.5)))
            return ref;
    }
    return 0;
}

// ---- portal ----
// @0x140a79a00
int CMouseInteractPortal::vfunc_1(Unk_MouseRay* pRay)
{
    Unk_PortalHit hit = FindTarget(&pRay->vOrigin, &pRay->vEnd);
    if (hit.FUN_140965190())
        return false;
    FUN_140194470(&pRay->vPick, reinterpret_cast<const Unk_Vec3*>(&static_cast<const NiPoint3&>(hit->FUN_14169d2f0())));
    if (hit->FUN_14169d280() == 0)
        pRay->strCursor = hit->FUN_14169c3b0();
    else
        pRay->strCursor = FUN_1405c2690(CStringW(L"s_mouse_interact_portal"), TSingleton<CStringTable>::GetInstance()->FUN_141811980(3, hit->FUN_14169d280()));
    return true;
}
// @0x140a79c00
int CMouseInteractPortal::vfunc_2(Unk_MouseRay* pRay)
{
    Unk_PortalHit hit = FindTarget(&pRay->vOrigin, &pRay->vEnd);
    if (hit.FUN_140965190())
        return false;
    FUN_140194470(&pRay->vPick, reinterpret_cast<const Unk_Vec3*>(&static_cast<const NiPoint3&>(hit->FUN_14169d2f0())));
    m_nPortalId = hit->FUN_14169d280();
    return true;
}
// @0x140a79cd0
int CMouseInteractPortal::vfunc_3()
{
    Unk_MiPlayer* pPlayer = reinterpret_cast<Unk_MiWorld*>(WorldService::GetInstance())->FUN_141bd0cc0();
    if (pPlayer == 0)
        return false;
    if (FUN_140953530(Unk_PlayerActionState(pPlayer)) != 0x13)
        return false;
    PortalAction* pAct = dynamic_cast<PortalAction*>(FUN_140953550(Unk_PlayerActionState(pPlayer)));
    if (pAct == 0)
        return false;
    return pAct->FUN_140956110() == m_nPortalId;
}
// @0x140a79d90
void CMouseInteractPortal::vfunc_5()
{
    m_nPortalId = 0;
}
// @0x140a79db0
Unk_PortalHit CMouseInteractPortal::FindTarget(const Unk_Vec3* pOrigin, const Unk_Vec3* pEnd)
{
    Unk_IdArray aIds;
    reinterpret_cast<Unk_MiWorld*>(WorldService::GetInstance())->FUN_141bc2980(aIds);
    for (size_t i = 0; i < aIds.FUN_1401910d0(); i++) {
        const unsigned& nId = aIds.FUN_1404f0a10(i);
        Unk_PortalHit hit = reinterpret_cast<Unk_MiWorld*>(WorldService::GetInstance())->FUN_141bc2800(nId);
        if (hit.FUN_1409652c0(0))
            continue;
        Unk_MiCompRef comp(FUN_1411cf440(FUN_1409670f0(), reinterpret_cast<char*>(hit.operator->()) + 0x18));
        if (comp.FUN_1408a9090() == 0)
            continue;
        bool bFlag = false;
        FUN_1408a20a0(comp.FUN_1408a9280(), 0x14969c28, &bFlag);
        if (!bFlag)
            continue;
        int nState;
        FUN_1408a2020(comp.FUN_1408a9280(), 0x1b8b1161, &nState);
        if (nState == 1)
            continue;
        Unk_MiVec3 vCenter(hit->FUN_14169d2f0());
        vCenter.z += hit->m_fRadius * 0.5;
        float fRadius = hit->m_fRadius * 0.5;
        if (FUN_14147ad10(*pOrigin, *pEnd, vCenter, fRadius))
            return hit;
    }
    return 0;
}

// ---- object ----
// @0x140a7a0c0
int CMouseInteractObject::vfunc_1(Unk_MouseRay* pRay)
{
    Unk_ObjectHit hit = FindTarget(&pRay->vOrigin, &pRay->vEnd);
    if (hit.IsNil())
        return false;
    FUN_140194470(&pRay->vPick, reinterpret_cast<const Unk_Vec3*>(&static_cast<const NiPoint3&>(hit->FUN_1409673c0())));
    pRay->strCursor = FUN_1405c2690(CStringW(L"s_mouse_interact_object"), TSingleton<CStringTable>::GetInstance()->FUN_141811980(0xb, hit->FUN_140967110()));
    return true;
}
// @0x140a7a250
int CMouseInteractObject::vfunc_2(Unk_MouseRay* pRay)
{
    Unk_ObjectHit hit = FindTarget(&pRay->vOrigin, &pRay->vEnd);
    if (hit.IsNil())
        return false;
    FUN_140194470(&pRay->vPick, reinterpret_cast<const Unk_Vec3*>(&static_cast<const NiPoint3&>(hit->FUN_1409673c0())));
    switch (hit->vf5()) {
    case 8:
        m_nAction = 0x18;
        break;
    case 6:
        m_nAction = 4;
        break;
    default:
        m_nAction = 0x12;
        break;
    }
    m_strObjectId = hit->FUN_140967060();
    return true;
}
// @0x140a7a3d0
int CMouseInteractObject::vfunc_3()
{
    Unk_MiPlayer* pPlayer = reinterpret_cast<Unk_MiWorld*>(WorldService::GetInstance())->FUN_141bd0cc0();
    if (pPlayer == 0)
        return false;
    if (FUN_140953530(Unk_PlayerActionState(pPlayer)) != m_nAction)
        return false;
    if (FUN_141527160(pPlayer, 0x19) == 0)
        return false;
    InteractAction* pAct = dynamic_cast<InteractAction*>(FUN_140953550(Unk_PlayerActionState(pPlayer)));
    if (pAct == 0)
        return false;
    return FUN_1401c0090(&pAct->m_strObjectId, &m_strObjectId);
}
// @0x140a7a4a0
void CMouseInteractObject::vfunc_5()
{
    m_nAction = 0x1e;
    m_strObjectId.Empty();
}
// @0x140a7a4e0
Unk_ObjectHit CMouseInteractObject::FindTarget(const Unk_Vec3* pOrigin, const Unk_Vec3* pEnd)
{
    Unk_ObjArray aObjs;
    reinterpret_cast<Unk_MiWorld*>(WorldService::GetInstance())->FUN_141bc5f10(aObjs);
    for (size_t i = 0; i < aObjs.FUN_140966d80(); i++) {
        Unk_ObjectHit hit = aObjs.FUN_140965610(i);
        if (hit->vf4() == 0)
            continue;
        Unk_DataRef comp = hit->FUN_140966e00();
        if (comp.FUN_140965160())
            continue;
        float fSize = *(float*)(comp.operator->() + 0x90);
        if (FUN_14028d470(fSize, 0.0f))
            continue;
        Unk_MiVec3 vCenter(hit->FUN_1409673c0());
        vCenter.z += fSize * 0.5;
        float fRadius = fSize * 0.5;
        if (FUN_14147ad10(*pOrigin, *pEnd, vCenter, fRadius))
            return hit;
    }
    return 0;
}

// ---- dynamic model (taxi / ugc banner) ----
// @0x140a7a780
int CMouseInteractDynamicModel::vfunc_1(Unk_MouseRay* pRay)
{
    if (!vfunc_2(pRay))
        return 0;
    pRay->strCursor = GetStringCommonByKey(m_strCursor);
    return 1;
}
// @0x140a7a810
int CMouseInteractDynamicModel::vfunc_2(Unk_MouseRay* pRay)
{
    void* pModel = FindTarget(&pRay->vOrigin, &pRay->vEnd);
    if (pModel == 0)
        return 0;
    FUN_1409618c0(pModel, 0xfd95ca52, &pRay->vPick);
    return 1;
}
// @0x140a7a880
int CMouseInteractDynamicModel::vfunc_3()
{
    Unk_MiPlayer* pPlayer = reinterpret_cast<Unk_MiWorld*>(WorldService::GetInstance())->FUN_141bd0cc0();
    if (pPlayer == 0)
        return false;
    if (FUN_140953530(Unk_PlayerActionState(pPlayer)) != m_nAction)
        return false;
    return true;
}
// @0x140a7a8e0
void* CMouseInteractDynamicModel::FindTarget(const Unk_Vec3* pOrigin, const Unk_Vec3* pEnd)
{
    Unk_DmIter it = reinterpret_cast<Unk_MiWorld*>(WorldService::GetInstance())->FUN_141bd0420(m_dwModelKey);
    for (void* pos = it->FUN_1409f2490(); pos != 0; it->FUN_1409f24c0(pos)) {
        Unk_MiDmRef ref = it->FUN_1409f23c0(pos);
        NiPoint3 vPos = *reinterpret_cast<NiPoint3*>(&DAT_143b01a60);
        FUN_1409618c0(ref.FUN_1408a9280(), 0xfd95ca52, reinterpret_cast<Unk_Vec3*>(&vPos));
        float fSize = m_fPickSize;
        Unk_MiVec3 vCenter(vPos);
        vCenter.z += fSize * 0.5;
        float fRadius = fSize * 0.5;
        if (FUN_14147ad10(*pOrigin, *pEnd, vCenter, fRadius))
            return ref.FUN_1408a9090();
    }
    return 0;
}
// @0x140a7b4b0
CMouseInteractDynamicModel::CMouseInteractDynamicModel()
{
}
// @0x140a7b8b0
int CMouseInteractDynamicModel::vfunc_6()
{
    return 0;
}
// @0x140a7aad0
CMouseInteractTaxi::CMouseInteractTaxi()
{
    m_dwModelKey = 0x85359406;
    m_fPickSize = 150.0f;
    m_nAction = 8;
    m_strCursor = L"s_mouse_interact_taxi";
}
// @0x140a7b8c0
int CMouseInteractTaxi::vfunc_6()
{
    return 4;
}
// @0x140a7ab50
CMouseInteractUgcBanner::CMouseInteractUgcBanner()
{
    m_dwModelKey = 0xc7f9dd65;
    m_fPickSize = 225.0f;
    m_nAction = 0x10;
    m_strCursor = L"s_mouse_interact_ugcbanner";
}
// @0x140a7b8d0
int CMouseInteractUgcBanner::vfunc_6()
{
    return 5;
}

// ---- talk cancel ----
class Unk_MiUiMgr { public: MS2Ptr<UIObject> FUN_141adcea0(int nId); };
// @0x140a7b2b0
UITalkCinematic* FUN_140a7b2b0(int nId)
{
    if (reinterpret_cast<Unk_MiUiMgr*>(TSingleton<CUIService>::GetInstance())) {
        MS2Ptr<UIObject> p = reinterpret_cast<Unk_MiUiMgr*>(TSingleton<CUIService>::GetInstance())->FUN_141adcea0(nId);
        if (p.get())
            return dynamic_cast<UITalkCinematic*>((UIObject*)p);
    }
    return 0;
}
struct Unk_TalkUi { char m_pad[8]; };
Unk_TalkUi* FUN_1408e57f0();
int FUN_1422b9e00(Unk_TalkUi* p);
int FUN_141b1bfc0(UITalkCinematic* p);
void FUN_141b1feb0(void* p);
// @0x140a7abd0
int CMouseInteractTalkCancel::vfunc_1(Unk_MouseRay* pRay)
{
    if (!vfunc_2(pRay))
        return 0;
    pRay->strCursor = GetStringCommonByKey(L"s_mouse_interact_talk_end");
    return 1;
}
// @0x140a7ac80
int CMouseInteractTalkCancel::vfunc_2(Unk_MouseRay* pRay)
{
    if (FUN_1422b9e00(FUN_1408e57f0()) != 0x6200031)
        return false;
    UITalkCinematic* pUi = FUN_140a7b2b0(0x4e40);
    if (pUi == 0)
        return false;
    if (FUN_141b1bfc0(pUi) == 0)
        return false;
    PCBase* pPlayer = reinterpret_cast<PCBase*>(reinterpret_cast<Unk_MiWorld*>(WorldService::GetInstance())->FUN_141bd0cc0());
    if (pPlayer == 0)
        return false;
    FUN_140194470(&pRay->vPick, reinterpret_cast<const Unk_Vec3*>(&static_cast<const NiPoint3&>(pPlayer->vfunc_18())));
    return true;
}
// @0x140a7ad30
int CMouseInteractTalkCancel::vfunc_3()
{
    return true;
}
// @0x140a7ad50
int CMouseInteractTalkCancel::vfunc_4()
{
    FUN_141b1feb0(FUN_140967100());
    return true;
}

// ---- weapon object ----
// @0x140a7ad80
int CMouseInteractWeaponObject::vfunc_1(Unk_MouseRay* pRay)
{
    Unk_WeaponHit hit = FindTarget(&pRay->vOrigin, &pRay->vEnd);
    if (hit.FUN_140885330()) {
        pRay->strCursor = GetStringCommon(0x63c);
        FUN_140194470(&pRay->vPick, reinterpret_cast<const Unk_Vec3*>(&static_cast<const NiPoint3&>(hit->FUN_1408b5370())));
        return true;
    }
    return false;
}
// @0x140a7ae80
int CMouseInteractWeaponObject::vfunc_2(Unk_MouseRay* pRay)
{
    Unk_WeaponHit hit = FindTarget(&pRay->vOrigin, &pRay->vEnd);
    if (hit.FUN_140885330()) {
        m_qwObjectId = hit->m_qwId;
        FUN_140194470(&pRay->vPick, reinterpret_cast<const Unk_Vec3*>(&static_cast<const NiPoint3&>(hit->FUN_1408b5370())));
        return true;
    }
    return false;
}
// @0x140a7af50
int CMouseInteractWeaponObject::vfunc_3()
{
    Unk_MiPlayer* pPlayer = reinterpret_cast<Unk_MiWorld*>(WorldService::GetInstance())->FUN_141bd0cc0();
    if (pPlayer == 0)
        return false;
    if (FUN_140953530(Unk_PlayerActionState(pPlayer)) != 0xd)
        return false;
    PullObjectWeaponAction* pAct = dynamic_cast<PullObjectWeaponAction*>(FUN_140953550(Unk_PlayerActionState(pPlayer)));
    if (pAct == 0)
        return false;
    if (FUN_140885220(pAct->m_hit) != 0)
        return false;
    return FUN_140885350(pAct->m_hit)->m_qwId == m_qwObjectId;
}
// @0x140a7b040
Unk_WeaponHit CMouseInteractWeaponObject::FindTarget(const Unk_Vec3* pOrigin, const Unk_Vec3* pEnd)
{
    Unk_WeaponArray aWeapons;
    Unk_WeaponMgr* pMgr = FUN_1401cd040(&DAT_143b059e8);
    pMgr->FUN_1410d59c0(aWeapons);
    for (size_t i = 0; i < aWeapons.GetCount(); i++) {
        Unk_WeaponHit hit = *aWeapons.GetAt(i);
        bool bFlag = false;
        FUN_1408a20a0(FUN_1408a9280(reinterpret_cast<Unk_DmNodeRef*>(reinterpret_cast<char*>(hit.operator->()) + 0x20)), 0xa0b6b179, &bFlag);
        if (!bFlag)
            continue;
        if (hit->m_n48 != 0)
            continue;
        if (hit->m_n50 != 0)
            continue;
        NiPoint3 vPos = hit->FUN_1408b5370();
        float fSize = 150.0f;
        Unk_MiVec3 vCenter(vPos);
        vCenter.z += fSize * 0.5;
        float fRadius = fSize * 0.5;
        if (FUN_14147ad10(*pOrigin, *pEnd, vCenter, fRadius))
            return hit;
    }
    return 0;
}


MS2_EMIT_CRT_MEMMOVE_S();

// The out-of-line ctor of the cursor ray (gap2: ps1 had split it off; the v2525 TU map starts this TU at 0x140a78f00).
// In the exe the three vectors are efd::Point3 (default ctor 0x1402bd040) and the pick slot starts at Point3::ZERO;
// Unk_MouseRay (mouseinteract.h) is the trivial view its users still aggregate-initialise (unit_140ad1860), so the
// ctor is written on a same-layout view here.
// MS2-RANGE: 0x140a78f00-0x140a78f70 .text$mn
#include <efd/Point3.h>
struct Unk_MouseRayInit
{
    Unk_MouseRayInit();
    efd::Point3 vOrigin;        // +0x00
    efd::Point3 vEnd;           // +0x0c
    efd::Point3 vPick;          // +0x18
    int m_pad_24;
    CStringW strCursor;         // +0x28
};
MS2_CHECK_SIZE(Unk_MouseRayInit, sizeof(Unk_MouseRay));

// @0x140a78f00
Unk_MouseRayInit::Unk_MouseRayInit()
    : vPick(efd::Point3::ZERO)
{
}
