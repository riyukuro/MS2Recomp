// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// MS2-UNIT: ?\mouseinteract.cpp
// MS2-RANGE: 0x140a78f70-0x140a7bb20 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\mouseinteract.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "mouseinteract.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "uiobject.h"
#include "pcbase.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// MS2-FUNCTIONAL: unit-wide; the picker bodies (vfunc_1/2/3, FindTarget) and the hit / iterator helpers use opaque externs and
// Ghidra-level approximations of unrecovered smart-pointer types, so most non-trivial functions are not byte-identical.
// Picker vfuncs (imported by unnamed/unit_140ad1860): the exe's hit results (Unk_PortalHit / Unk_ObjectHit / Unk_WeaponHit)
// are 16-byte counted handles with dtors (0x140964a70 / 0x1409649b0 / ...) that FindTarget returns by value (sret, EH frame,
// IsNull tests return bool); here they are raw structs with explicit helper calls (char results, GS cookie, no EH).
// MS2-FUNCTIONAL 0x140a79090: CMouseInteractNpc::vfunc_1 - raw PCBase*/hit structs instead of the handle temporaries (2 extra helper calls)
// MS2-FUNCTIONAL 0x140a79a00: CMouseInteractPortal::vfunc_1 - Unk_PortalHit as a raw struct (GS frame, no EH dtor state)
// MS2-FUNCTIONAL 0x140a79c00: CMouseInteractPortal::vfunc_2 - same: exe early-returns 0 after the bool IsNull test, hit dtor via EH
// MS2-FUNCTIONAL 0x140a7a0c0: CMouseInteractObject::vfunc_1 - Unk_ObjectHit as a raw struct (GS frame, no EH dtor state)
// MS2-FUNCTIONAL 0x140a7a250: CMouseInteractObject::vfunc_2 - same handle-type gap as vfunc_1
// MS2-FUNCTIONAL 0x140a7ad80: CMouseInteractWeaponObject::vfunc_1 - Unk_WeaponHit as a raw struct (GS frame, no EH dtor state)
// MS2-FUNCTIONAL 0x140a7ae80: CMouseInteractWeaponObject::vfunc_2 - same handle-type gap as vfunc_1
// ---- RTTI-only action classes (the picker compares the player's current action against the picked object) ----
class ActionKeyObject { public: virtual ~ActionKeyObject(); };
class TalkAction : public ActionKeyObject { public: char m_pad[0x10]; int m_nNpcId; };                  // +0x18
class HoldAction : public ActionKeyObject { public: char m_pad[0x18]; int m_nNpcId; };                  // +0x20
class PortalAction : public ActionKeyObject { public: char m_pad[0x10]; };
class InteractAction : public ActionKeyObject { public: char m_pad[0x10]; CStringA m_strObjectId; };    // +0x18
class PullObjectWeaponAction : public ActionKeyObject { public: char m_pad[0x10]; char m_hit[16]; };    // +0x18
class UITalkCinematic : public UIObject {};

// ---- exe callees ----
struct Unk_MiPlayer;
struct Unk_MiActionState;
struct Unk_MiTextMgr { CStringW FUN_141811980(int nType, int nId); };
Unk_MiTextMgr* FUN_1401a9d70();
CStringW FUN_14028de60(int nStringId);
CStringW FUN_14028b8e0(const CStringW& str);
CStringW FUN_1405c2690(CStringW fmt, const CStringW& arg);
CStringW FUN_1408f71a0(CStringW fmt, const CStringW& a, const CStringW& b);
struct Unk_MiNpcView { CStringW FUN_141093310(); };       // npc name (member: this=rcx, hidden return=rdx)
unsigned FUN_141092fa0(PCBase* pNpc);                    // npc id
int FUN_141093c60(PCBase* pNpc);
void FUN_140194470(Unk_Vec3* pDst, const Unk_Vec3* pSrc);
Unk_Vec3* FUN_14027dcf0(Unk_Vec3* pDst, const Unk_Vec3* pSrc);
bool FUN_14147ad10(const Unk_Vec3* pOrigin, const Unk_Vec3* pEnd, const Unk_Vec3* pCenter, float fRadius);
bool FUN_14028d470(float a, float b);
extern char DAT_143b01a60;

struct Unk_NpcTree;
class Unk_MiWorld
{
public:
    Unk_MiPlayer* FUN_141bd0cc0();                          // the local player
    Unk_NpcTree* FUN_141bd36d0();                           // npc tree
    void FUN_141bc2980(struct Unk_IdArray* pOut);           // portal ids
    void FUN_141bc2800(struct Unk_PortalHit* pOut, unsigned nId);
    void FUN_141bc5f10(struct Unk_ObjArray* pOut);          // interactable objects
    void FUN_141bd0420(struct Unk_DmIter* pOut, unsigned nKey);
};
Unk_MiWorld* FUN_1403ed2d0();
Unk_MiActionState* Unk_PlayerActionState(Unk_MiPlayer* pPlayer);
int FUN_140953530(Unk_MiActionState* p);                    // current action type
ActionKeyObject* FUN_140953550(Unk_MiActionState* p);       // current action
void FUN_140953310(Unk_MiActionState* p);                   // cancel
int FUN_141527160(Unk_MiPlayer* pPlayer, int nFlag);
int FUN_14166c930(Unk_MiPlayer* pPlayer);
bool FUN_1401c0090(const CStringA* a, const CStringA* b);
int FUN_140956110(PortalAction* p);
void* FUN_1409331e0();
int FUN_14138c900(void* p, int n);
void* FUN_140967100();
int FUN_141b211d0(void* p);
int FUN_14123c660(PCBase* p);
int FUN_140855d10(unsigned nId);

// smart pointer to the data record of an npc (16 bytes)
struct Unk_DataRef { char raw[16]; };
Unk_DataRef* FUN_141093270(PCBase* pNpc, Unk_DataRef* pOut);
void FUN_1406cf850(Unk_DataRef* pDst, Unk_DataRef* pSrc);
void FUN_1406d5390(Unk_DataRef* p);
char FUN_14035e9b0(Unk_DataRef* p);
void FUN_14035e5b0(Unk_DataRef* p);
char* FUN_14035eb90(Unk_DataRef* p);
void* FUN_140965990(Unk_DataRef* p);
int FUN_1406cd020(void* p);


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
    if (pos == 0)
        AtlThrow(0x80004005L);
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
    Unk_NpcNode* pCur = p;
    if (p == 0 || IsNil(p))
        return 0;
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
    Unk_NpcNode* pChild = p;
    for (pNext = p->m_pParent; !IsNil(pNext) && pChild == pNext->m_pRight; pNext = pNext->m_pParent)
        pChild = pNext;
    if (IsNil(pNext))
        pNext = 0;
    return pNext;
}

// ---- hit-result wrappers (16 bytes: unknown qword + the pointer at +8) ----
struct Unk_Portal { char m_pad[0x4c]; float m_fRadius; CStringW FUN_14169c3b0(); };   // cursor text (member: this=rcx, hidden return=rdx)
struct Unk_PortalHit { void* m_pad; Unk_Portal* m_p; };
Unk_PortalHit* FUN_140964110(Unk_PortalHit* p, int n);
char FUN_140965190(Unk_PortalHit* p);
char FUN_1409652c0(Unk_PortalHit* p, void* pCmp);           // p->m_p == pCmp
Unk_Portal* FUN_140965960(Unk_PortalHit* p);
void FUN_140964a70(Unk_PortalHit* p);
Unk_Vec3* FUN_14169d2f0(Unk_Portal* p, Unk_Vec3* pTmp);
int FUN_14169d280(Unk_Portal* p);

struct Unk_ObjectEnt { virtual int vf0(); virtual int vf1(); virtual int vf2(); virtual int vf3(); virtual int vf4(); virtual int vf5();
    CStringA FUN_140967060(); };   // object id (member: this=rcx, hidden return=rdx)
struct Unk_ObjectHit { void* m_pad; Unk_ObjectEnt* m_p; };
Unk_ObjectHit* FUN_140963fd0(Unk_ObjectHit* p, int n);
Unk_ObjectEnt* FUN_140965920(Unk_ObjectHit* p);
void FUN_1409649b0(Unk_ObjectHit* p);
Unk_Vec3* FUN_1409673c0(Unk_ObjectEnt* p, Unk_Vec3* pTmp);
unsigned FUN_140967110(Unk_ObjectEnt* p);
struct Unk_IdArray { char raw[0x20]; };
struct Unk_ObjArray { char raw[0x20]; };
void FUN_140182ea0(Unk_IdArray* p);
size_t FUN_1401910d0(Unk_IdArray* p);
unsigned* FUN_1404f0a10(Unk_IdArray* p, size_t i);
void FUN_140183b60(Unk_IdArray* p);
size_t FUN_140966d80(Unk_ObjArray* p);
void* FUN_140965610(Unk_ObjArray* p, size_t i);
Unk_DataRef* FUN_140966e00(Unk_ObjectEnt* p, Unk_DataRef* pOut);
void FUN_140963a20(Unk_ObjArray* p);
void FUN_140964700(Unk_ObjArray* p);
char FUN_140965160(Unk_DataRef* p);
char* FUN_1405212e0(Unk_DataRef* p);
void FUN_140520fc0(Unk_DataRef* p);


struct Unk_DmIter { char raw[16]; };
struct Unk_DmList;
Unk_DmList* FUN_1409f2190(Unk_DmIter* p);
void* FUN_1409f2490(Unk_DmList* p);
struct Unk_DmNodeRef { void* m_p; };
void* FUN_1409670f0();
void FUN_1411cf440(void* pSvc, void* pKey, Unk_DmNodeRef* pOut);
void* FUN_1409f23c0(Unk_DmList* p, void* pos);
void FUN_1409f24c0(Unk_DmList* p, void** pos);
void FUN_1409f20e0(Unk_DmIter* p);
void FUN_1408a7ed0(Unk_DmNodeRef* pDst, void* pSrc);
void* FUN_1408a9280(Unk_DmNodeRef* p);
void* FUN_1408a9090(Unk_DmNodeRef* p);
void FUN_1408a8720(Unk_DmNodeRef* p);
void FUN_1409618c0(void* pObj, unsigned nHash, Unk_Vec3* pOut);

// ---- weapon objects ----
struct Unk_WeaponEnt { char m_pad_00[0x18]; unsigned long long m_qwId; char m_pad_20[0x28]; int m_n48; char m_pad_4c[4]; int m_n50; };
struct Unk_WeaponHit { void* m_pad; Unk_WeaponEnt* m_p; };
Unk_WeaponHit* FUN_140884f70(Unk_WeaponHit* pDst, void* pSrc);
char FUN_140885220(void* p);
Unk_WeaponEnt* FUN_140885350(void* p);
Unk_WeaponEnt* FUN_140885330(void* p);
void FUN_140885120(Unk_WeaponHit* p);
Unk_WeaponHit* FUN_140964170(Unk_WeaponHit* p, int n);
Unk_Vec3* FUN_1408b5370(Unk_WeaponEnt* p, Unk_Vec3* pTmp);
void FUN_1408a20a0(void* pDst, unsigned nHash, char* pOut);
void FUN_1408a2020(void* pDst, unsigned nHash, int* pOut);
struct Unk_WeaponMgr { void FUN_1410d59c0(struct Unk_WeaponArray* pOut); };
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
    static void CallDestructors(Unk_WeaponHit* p, size_t n);
};
Unk_WeaponHit* Unk_WeaponHitDelDtor(Unk_WeaponHit* p, unsigned nFlags);
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
    if (!(m_nSize > i))
        FUN_140159b70(0x80070057L);
    return m_pData + i;
}
// @0x140a7b7b0
void Unk_WeaponArray::CallDestructors(Unk_WeaponHit* p, size_t n)
{
    for (size_t i = 0; i < n; i++)
        Unk_WeaponHitDelDtor(p + i, 0);
}
// @0x140a7b670
Unk_WeaponHit* Unk_WeaponHitDelDtor(Unk_WeaponHit* p, unsigned nFlags)
{
    FUN_140885120(p);
    if ((nFlags & 1) != 0)
        operator delete(p);
    return p;
}

// move helpers: take the pointer out of the source
// @0x140a7b3e0
Unk_ObjectHit* Unk_ObjectHitMove(Unk_ObjectHit* pDst, Unk_ObjectHit* pSrc)
{
    pDst->m_p = pSrc->m_p;
    pSrc->m_p = 0;
    return pDst;
}
// @0x140a7b410
void Unk_ObjectHitAddRefIfSet(Unk_ObjectHit* p);
Unk_ObjectHit* Unk_ObjectHitCopy(Unk_ObjectHit* pDst, Unk_ObjectHit* pSrc)
{
    pDst->m_p = pSrc->m_p;
    Unk_ObjectHitAddRefIfSet(pDst);
    return pDst;
}
// @0x140a7b450
Unk_PortalHit* Unk_PortalHitMove(Unk_PortalHit* pDst, Unk_PortalHit* pSrc)
{
    pDst->m_p = pSrc->m_p;
    pSrc->m_p = 0;
    return pDst;
}
// @0x140a7b480
Unk_WeaponHit* Unk_WeaponHitMove(Unk_WeaponHit* pDst, Unk_WeaponHit* pSrc)
{
    pDst->m_p = pSrc->m_p;
    pSrc->m_p = 0;
    return pDst;
}
// @0x140a7b5e0
bool Unk_ObjectHitIsNil(Unk_ObjectHit* p)
{
    return p->m_p == 0;
}
void FUN_140968e90(Unk_ObjectEnt* p);
// @0x140a7baf0
void Unk_ObjectHitAddRef(Unk_ObjectHit* p)
{
    FUN_140968e90(p->m_p);
}
// @0x140a7bac0
void Unk_ObjectHitAddRefIfSet(Unk_ObjectHit* p)
{
    if (p->m_p != 0)
        Unk_ObjectHitAddRef(p);
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
    Unk_MiPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
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
    if (pNpc == 0)
        return false;
    NiPoint3 vTmp = pNpc->vfunc_18();
    FUN_140194470(&pRay->vPick, reinterpret_cast<const Unk_Vec3*>(&vTmp));
    if (pNpc->vfunc_117() == 0) {
        unsigned nNpcId = FUN_141092fa0(pNpc);
        CStringW strName = FUN_1401a9d70()->FUN_141811980(0xe, nNpcId);
        if (strName.GetLength() == 0)
            strName = FUN_14028de60(0x62d);
        pRay->strCursor = FUN_1408f71a0(CStringW(L"s_mouse_interact_talk"), strName, reinterpret_cast<Unk_MiNpcView*>(pNpc)->FUN_141093310());
    } else {
        pRay->strCursor = FUN_1405c2690(CStringW(L"s_mouse_interact_hold"), reinterpret_cast<Unk_MiNpcView*>(pNpc)->FUN_141093310());
    }
    return true;
}
// @0x140a79340
int CMouseInteractNpc::vfunc_2(Unk_MouseRay* pRay)
{
    PCBase* pNpc = FindTarget(&pRay->vOrigin, &pRay->vEnd);
    if (pNpc == 0)
        return false;
    NiPoint3 vTmp = pNpc->vfunc_18();
    FUN_140194470(&pRay->vPick, reinterpret_cast<const Unk_Vec3*>(&vTmp));
    if (pNpc->vfunc_117() == 0)
        m_nAction = 0x14;
    else
        m_nAction = 6;
    m_nNpcId = FUN_141092fa0(pNpc);
    return true;
}
// @0x140a79400
int CMouseInteractNpc::vfunc_3()
{
    Unk_MiPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
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
// MS2-FUNCTIONAL: npc data-record smart pointer (16 bytes) and the player-state helpers are modelled as opaque externs
PCBase* CMouseInteractNpc::FindTarget(const Unk_Vec3* pOrigin, const Unk_Vec3* pEnd)
{
    Unk_MiPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
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
    Unk_NpcTree* pTree = FUN_1403ed2d0()->FUN_141bd36d0();
    Unk_NpcNode* pos = pTree->Begin();
    while (pos != 0) {
        PCBaseRef ref(*pTree->GetAt(pos));
        if (FUN_14123c660(ref.operator->()) == 0) {
            PCBase* pCand = ref.operator->();
            if (pCand->vfunc_116() != 0) {
                Unk_DataRef kTmp;
                Unk_DataRef kData;
                FUN_1406cf850(&kData, FUN_141093270(ref.operator->(), &kTmp));
                FUN_1406d5390(&kTmp);
                if (FUN_14035e9b0(&kData) == 0) {
                    int bPick = 0;
                    Unk_DataRef kTmp2;
                    FUN_141093270(ref.operator->(), &kTmp2);
                    int bType = FUN_1406cd020(FUN_140965990(&kTmp2)) != 0 && bTalk != 0;
                    FUN_1406d5390(&kTmp2);
                    if (bType)
                        bPick = 1;
                    if (FUN_140855d10(FUN_141092fa0(ref.operator->())) != 0 && bTalk != 0)
                        bPick = 1;
                    if (FUN_141093c60(ref.operator->()) != 4 && bTalk != 0)
                        bPick = 1;
                    PCBase* pHold = ref.operator->();
                    if (pHold->vfunc_117() != 0 && bHold != 0)
                        bPick = 1;
                    if (bPick == 0) {
                        FUN_14035e5b0(&kData);
                    } else {
                        float fSize = *(float*)(FUN_14035eb90(&kData) + 0x2dc);
                        PCBase* pPos = ref.operator->();
                        NiPoint3 vTmp = pPos->vfunc_18();
                        Unk_Vec3 vCenter;
                        FUN_14027dcf0(&vCenter, reinterpret_cast<const Unk_Vec3*>(&vTmp));
                        vCenter.z = vCenter.z + fSize * 0.5f;
                        Unk_Vec3 vEnd;
                        Unk_Vec3 vOrigin;
                        FUN_14027dcf0(&vEnd, pEnd);
                        FUN_14027dcf0(&vOrigin, pOrigin);
                        if (FUN_14147ad10(&vOrigin, &vEnd, &vCenter, fSize * 0.5f)) {
                            PCBase* pResult = ref.operator PCBase*();
                            FUN_14035e5b0(&kData);
                            return pResult;
                        }
                        FUN_14035e5b0(&kData);
                    }
                } else {
                    FUN_14035e5b0(&kData);
                }
            }
        }
        pTree->GetNext(pos);
    }
    return 0;
}

// ---- portal ----
// @0x140a79a00
int CMouseInteractPortal::vfunc_1(Unk_MouseRay* pRay)
{
    Unk_PortalHit hit;
    FindTarget(&hit, &pRay->vOrigin, &pRay->vEnd);
    if (FUN_140965190(&hit) != 0) {
        FUN_140964a70(&hit);
        return false;
    }
    Unk_Vec3 vTmp;
    FUN_140194470(&pRay->vPick, FUN_14169d2f0(FUN_140965960(&hit), &vTmp));
    if (FUN_14169d280(FUN_140965960(&hit)) == 0) {
        pRay->strCursor = FUN_140965960(&hit)->FUN_14169c3b0();
    } else {
        unsigned nId = FUN_14169d280(FUN_140965960(&hit));
        CStringW strName = FUN_1401a9d70()->FUN_141811980(3, nId);
        pRay->strCursor = FUN_1405c2690(CStringW(L"s_mouse_interact_portal"), strName);
    }
    FUN_140964a70(&hit);
    return true;
}
// @0x140a79c00
int CMouseInteractPortal::vfunc_2(Unk_MouseRay* pRay)
{
    Unk_PortalHit hit;
    FindTarget(&hit, &pRay->vOrigin, &pRay->vEnd);
    char bNil = FUN_140965190(&hit);
    if (bNil == 0) {
        Unk_Vec3 vTmp;
        FUN_140194470(&pRay->vPick, FUN_14169d2f0(FUN_140965960(&hit), &vTmp));
        m_nPortalId = FUN_14169d280(FUN_140965960(&hit));
    }
    FUN_140964a70(&hit);
    return bNil == 0;
}
// @0x140a79cd0
int CMouseInteractPortal::vfunc_3()
{
    Unk_MiPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return false;
    if (FUN_140953530(Unk_PlayerActionState(pPlayer)) != 0x13)
        return false;
    PortalAction* pAct = dynamic_cast<PortalAction*>(FUN_140953550(Unk_PlayerActionState(pPlayer)));
    if (pAct == 0)
        return false;
    return FUN_140956110(pAct) == m_nPortalId;
}
// @0x140a79d90
void CMouseInteractPortal::vfunc_5()
{
    m_nPortalId = 0;
}
// @0x140a79db0
// MS2-FUNCTIONAL: portal hit smart pointers and the scene component query are opaque externs
Unk_PortalHit* CMouseInteractPortal::FindTarget(Unk_PortalHit* pOut, const Unk_Vec3* pOrigin, const Unk_Vec3* pEnd)
{
    Unk_IdArray aIds;
    FUN_140182ea0(&aIds);
    FUN_1403ed2d0()->FUN_141bc2980(&aIds);
    for (size_t i = 0; ; i++) {
        if (FUN_1401910d0(&aIds) <= i) {
            FUN_140964110(pOut, 0);
            FUN_140183b60(&aIds);
            return pOut;
        }
        unsigned* pId = FUN_1404f0a10(&aIds, i);
        Unk_PortalHit hit;
        FUN_1403ed2d0()->FUN_141bc2800(&hit, *pId);
        if (FUN_1409652c0(&hit, 0) != 0) {
            FUN_140964a70(&hit);
            continue;
        }
        void* pKey = reinterpret_cast<char*>(FUN_140965960(&hit)) + 0x18;
        Unk_DmNodeRef comp;
        FUN_1411cf440(FUN_1409670f0(), pKey, &comp);
        if (FUN_1408a9090(&comp) == 0) {
            FUN_1408a8720(&comp);
            FUN_140964a70(&hit);
            continue;
        }
        char bFlag = 0;
        FUN_1408a20a0(FUN_1408a9280(&comp), 0x14969c28, &bFlag);
        if (bFlag == 0) {
            FUN_1408a8720(&comp);
            FUN_140964a70(&hit);
            continue;
        }
        int nState;
        FUN_1408a2020(FUN_1408a9280(&comp), 0x1b8b1161, &nState);
        if (nState == 1) {
            FUN_1408a8720(&comp);
            FUN_140964a70(&hit);
            continue;
        }
        Unk_Vec3 vTmp;
        Unk_Vec3 vCenter;
        FUN_14027dcf0(&vCenter, FUN_14169d2f0(FUN_140965960(&hit), &vTmp));
        vCenter.z = vCenter.z + FUN_140965960(&hit)->m_fRadius * 0.5f;
        float fRadius = FUN_140965960(&hit)->m_fRadius * 0.5f;
        Unk_Vec3 vEnd;
        Unk_Vec3 vOrigin;
        FUN_14027dcf0(&vEnd, pEnd);
        FUN_14027dcf0(&vOrigin, pOrigin);
        if (FUN_14147ad10(&vOrigin, &vEnd, &vCenter, fRadius)) {
            Unk_PortalHitMove(pOut, &hit);
            FUN_1408a8720(&comp);
            FUN_140964a70(&hit);
            FUN_140183b60(&aIds);
            return pOut;
        }
        FUN_1408a8720(&comp);
        FUN_140964a70(&hit);
    }
}

// ---- object ----
// @0x140a7a0c0
int CMouseInteractObject::vfunc_1(Unk_MouseRay* pRay)
{
    Unk_ObjectHit hit;
    FindTarget(&hit, &pRay->vOrigin, &pRay->vEnd);
    char bNil = Unk_ObjectHitIsNil(&hit);
    if (bNil == 0) {
        Unk_Vec3 vTmp;
        FUN_140194470(&pRay->vPick, FUN_1409673c0(FUN_140965920(&hit), &vTmp));
        unsigned nId = FUN_140967110(FUN_140965920(&hit));
        CStringW strName = FUN_1401a9d70()->FUN_141811980(0xb, nId);
        pRay->strCursor = FUN_1405c2690(CStringW(L"s_mouse_interact_object"), strName);
    }
    FUN_1409649b0(&hit);
    return bNil == 0;
}
// @0x140a7a250
int CMouseInteractObject::vfunc_2(Unk_MouseRay* pRay)
{
    Unk_ObjectHit hit;
    FindTarget(&hit, &pRay->vOrigin, &pRay->vEnd);
    if (Unk_ObjectHitIsNil(&hit) != 0) {
        FUN_1409649b0(&hit);
        return false;
    }
    Unk_Vec3 vTmp;
    FUN_140194470(&pRay->vPick, FUN_1409673c0(FUN_140965920(&hit), &vTmp));
    int nKind = FUN_140965920(&hit)->vf5();
    if (nKind == 6)
        m_nAction = 4;
    else if (nKind == 8)
        m_nAction = 0x18;
    else
        m_nAction = 0x12;
    m_strObjectId = FUN_140965920(&hit)->FUN_140967060();
    FUN_1409649b0(&hit);
    return true;
}
// @0x140a7a3d0
int CMouseInteractObject::vfunc_3()
{
    Unk_MiPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
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
// MS2-FUNCTIONAL: object hit smart pointers and the component handle are opaque externs
Unk_ObjectHit* CMouseInteractObject::FindTarget(Unk_ObjectHit* pOut, const Unk_Vec3* pOrigin, const Unk_Vec3* pEnd)
{
    Unk_ObjArray aObjs;
    FUN_140963a20(&aObjs);
    FUN_1403ed2d0()->FUN_141bc5f10(&aObjs);
    for (size_t i = 0; ; i++) {
        if (FUN_140966d80(&aObjs) <= i) {
            FUN_140963fd0(pOut, 0);
            FUN_140964700(&aObjs);
            return pOut;
        }
        Unk_ObjectHit hit;
        Unk_ObjectHitCopy(&hit, (Unk_ObjectHit*)FUN_140965610(&aObjs, i));
        Unk_ObjectEnt* pEnt = FUN_140965920(&hit);
        if (pEnt->vf4() == 0) {
            FUN_1409649b0(&hit);
            continue;
        }
        Unk_DataRef comp;
        FUN_140966e00(FUN_140965920(&hit), &comp);
        if (FUN_140965160(&comp) != 0) {
            FUN_140520fc0(&comp);
            FUN_1409649b0(&hit);
            continue;
        }
        float fSize = *(float*)(FUN_1405212e0(&comp) + 0x90);
        if (FUN_14028d470(fSize, 0.0f)) {
            FUN_140520fc0(&comp);
            FUN_1409649b0(&hit);
            continue;
        }
        Unk_Vec3 vTmp;
        Unk_Vec3 vCenter;
        FUN_14027dcf0(&vCenter, FUN_1409673c0(FUN_140965920(&hit), &vTmp));
        vCenter.z = vCenter.z + fSize * 0.5f;
        float fRadius = fSize * 0.5f;
        Unk_Vec3 vEnd;
        Unk_Vec3 vOrigin;
        FUN_14027dcf0(&vEnd, pEnd);
        FUN_14027dcf0(&vOrigin, pOrigin);
        if (FUN_14147ad10(&vOrigin, &vEnd, &vCenter, fRadius)) {
            Unk_ObjectHitMove(pOut, &hit);
            FUN_140520fc0(&comp);
            FUN_1409649b0(&hit);
            FUN_140964700(&aObjs);
            return pOut;
        }
        FUN_140520fc0(&comp);
        FUN_1409649b0(&hit);
    }
}

// ---- dynamic model (taxi / ugc banner) ----
// @0x140a7a780
int CMouseInteractDynamicModel::vfunc_1(Unk_MouseRay* pRay)
{
    bool bHit = vfunc_2(pRay);
    if (bHit)
        pRay->strCursor = FUN_14028b8e0(m_strCursor);
    return bHit;
}
// @0x140a7a810
int CMouseInteractDynamicModel::vfunc_2(Unk_MouseRay* pRay)
{
    void* pModel = FindTarget(&pRay->vOrigin, &pRay->vEnd);
    if (pModel != 0)
        FUN_1409618c0(pModel, 0xfd95ca52, &pRay->vPick);
    return pModel != 0;
}
// @0x140a7a880
int CMouseInteractDynamicModel::vfunc_3()
{
    Unk_MiPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return false;
    return FUN_140953530(Unk_PlayerActionState(pPlayer)) == m_nAction;
}
// @0x140a7a8e0
void* CMouseInteractDynamicModel::FindTarget(const Unk_Vec3* pOrigin, const Unk_Vec3* pEnd)
{
    Unk_DmIter it;
    FUN_1403ed2d0()->FUN_141bd0420(&it, m_dwModelKey);
    void* pos = FUN_1409f2490(FUN_1409f2190(&it));
    Unk_DmNodeRef ref;
    while (pos != 0) {
        FUN_1408a7ed0(&ref, FUN_1409f23c0(FUN_1409f2190(&it), pos));
        Unk_Vec3 vPos = *reinterpret_cast<Unk_Vec3*>(&DAT_143b01a60);
        FUN_1409618c0(FUN_1408a9280(&ref), 0xfd95ca52, &vPos);
        float fSize = m_fPickSize;
        Unk_Vec3 vCenter;
        FUN_14027dcf0(&vCenter, &vPos);
        vCenter.z = vCenter.z + fSize * 0.5f;
        float fRadius = fSize * 0.5f;
        Unk_Vec3 vEnd;
        Unk_Vec3 vOrigin;
        FUN_14027dcf0(&vEnd, pEnd);
        FUN_14027dcf0(&vOrigin, pOrigin);
        if (FUN_14147ad10(&vOrigin, &vEnd, &vCenter, fRadius))
            break;
        FUN_1408a8720(&ref);
        FUN_1409f24c0(FUN_1409f2190(&it), &pos);
    }
    if (pos == 0) {
        FUN_1409f20e0(&it);
        return 0;
    }
    void* pResult = FUN_1408a9090(&ref);
    FUN_1408a8720(&ref);
    FUN_1409f20e0(&it);
    return pResult;
}
// @0x140a7b4b0
CMouseInteractDynamicModel::CMouseInteractDynamicModel()
{
}
// @0x140a7b570
CMouseInteractDynamicModel::~CMouseInteractDynamicModel()
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
// @0x140a7b5a0
CMouseInteractTaxi::~CMouseInteractTaxi()
{
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
// @0x140a7b5c0
CMouseInteractUgcBanner::~CMouseInteractUgcBanner()
{
}
// @0x140a7b8d0
int CMouseInteractUgcBanner::vfunc_6()
{
    return 5;
}

// ---- talk cancel ----
class Unk_MiUiMgr { public: MS2Ptr<UIObject> FUN_141adcea0(int nId); };
Unk_MiUiMgr* FUN_1403ed2b0();
// @0x140a7b2b0
UITalkCinematic* FUN_140a7b2b0(int nId)
{
    if (FUN_1403ed2b0()) {
        MS2Ptr<UIObject> p = FUN_1403ed2b0()->FUN_141adcea0(nId);
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
    bool bHit = vfunc_2(pRay);
    if (bHit)
        pRay->strCursor = FUN_14028b8e0(CStringW(L"s_mouse_interact_talk_end"));
    return bHit;
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
    PCBase* pPlayer = reinterpret_cast<PCBase*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (pPlayer == 0)
        return false;
    NiPoint3 vTmp = pPlayer->vfunc_18();
    FUN_140194470(&pRay->vPick, reinterpret_cast<const Unk_Vec3*>(&vTmp));
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
    Unk_WeaponHit hit;
    FindTarget(&hit, &pRay->vOrigin, &pRay->vEnd);
    Unk_WeaponEnt* pEnt = FUN_140885330(&hit);
    if (pEnt != 0) {
        pRay->strCursor = FUN_14028de60(0x63c);
        Unk_Vec3 vTmp;
        FUN_140194470(&pRay->vPick, FUN_1408b5370(FUN_140885350(&hit), &vTmp));
    }
    FUN_140885120(&hit);
    return pEnt != 0;
}
// @0x140a7ae80
int CMouseInteractWeaponObject::vfunc_2(Unk_MouseRay* pRay)
{
    Unk_WeaponHit hit;
    FindTarget(&hit, &pRay->vOrigin, &pRay->vEnd);
    Unk_WeaponEnt* pEnt = FUN_140885330(&hit);
    if (pEnt != 0) {
        m_qwObjectId = FUN_140885350(&hit)->m_qwId;
        Unk_Vec3 vTmp;
        FUN_140194470(&pRay->vPick, FUN_1408b5370(FUN_140885350(&hit), &vTmp));
    }
    FUN_140885120(&hit);
    return pEnt != 0;
}
// @0x140a7af50
int CMouseInteractWeaponObject::vfunc_3()
{
    Unk_MiPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
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
// MS2-FUNCTIONAL: weapon hit smart pointers and the component flag queries are opaque externs
Unk_WeaponHit* CMouseInteractWeaponObject::FindTarget(Unk_WeaponHit* pOut, const Unk_Vec3* pOrigin, const Unk_Vec3* pEnd)
{
    Unk_WeaponArray aWeapons;
    FUN_1401cd040(&DAT_143b059e8)->FUN_1410d59c0(&aWeapons);
    for (size_t i = 0; ; i++) {
        if (aWeapons.GetCount() <= i) {
            FUN_140964170(pOut, 0);
            return pOut;
        }
        Unk_WeaponHit hit;
        FUN_140884f70(&hit, aWeapons.GetAt(i));
        char bFlag = 0;
        FUN_1408a20a0(FUN_1408a9280(reinterpret_cast<Unk_DmNodeRef*>(reinterpret_cast<char*>(FUN_140885350(&hit)) + 0x20)), 0xa0b6b179, &bFlag);
        if (bFlag == 0) {
            FUN_140885120(&hit);
            continue;
        }
        if (FUN_140885350(&hit)->m_n48 != 0) {
            FUN_140885120(&hit);
            continue;
        }
        if (FUN_140885350(&hit)->m_n50 != 0) {
            FUN_140885120(&hit);
            continue;
        }
        Unk_Vec3 vTmp;
        FUN_1408b5370(FUN_140885350(&hit), &vTmp);
        float fSize = 150.0f;
        Unk_Vec3 vCenter;
        FUN_14027dcf0(&vCenter, &vTmp);
        vCenter.z = vCenter.z + fSize * 0.5f;
        float fRadius = fSize * 0.5f;
        Unk_Vec3 vEnd;
        Unk_Vec3 vOrigin;
        FUN_14027dcf0(&vEnd, pEnd);
        FUN_14027dcf0(&vOrigin, pOrigin);
        if (FUN_14147ad10(&vOrigin, &vEnd, &vCenter, fRadius)) {
            Unk_WeaponHitMove(pOut, &hit);
            FUN_140885120(&hit);
            return pOut;
        }
        FUN_140885120(&hit);
    }
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
