// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Unnamed unit unit_140449650: the out-of-line glue of one
// family of std::map / std::set instantiations. Fourteen red-black-tree iterator steps (identical code, one per
// node type: the node is _Left +0x00 / _Parent +0x08 / _Right +0x10 / _Isnil +0x19), fourteen `operator++`-style
// forwards over them, thirteen more forwards over those, a two-argument forwarding shim, an unsigned "less"
// comparator, and the twelve scalar deleting destructors of the unit's boxed types (each runs the real destructor
// then sized-`operator delete`s the box: 0x10, 0x48 or 0x18 bytes). All names invented from shape.
// MS2-UNIT: unit_140449650
// MS2-RANGE: 0x140449650-0x14044a880 .text$mn
#define MS2_THIS_FILE ""
#include <new>

#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include <list>
#include <map>
#include "ms2/commonfiles/gameevent.h"
#include "ms2/commonfiles/gameeventcontext.h"
#include "ms2/placeholder/dungeongrouptype.h"
#include "ms2/placeholder/tptreddummy.h"

// ---- the types whose _Max helpers and destructors this unit reaches ----
typedef std::_Tree_val<std::_Tree_simple_types<__int64> > Unk_Tv_14033e2b0;
typedef MS2Ptr<CollectItemGroupContext> Unk_Dt_1403e51b0;
typedef MS2Ptr<EventShopNpcContext> Unk_Dt_140446470;
typedef TPtredDummy<ATL::CAtlList<unsigned int, ATL::CElementTraits<unsigned int> > > Unk_Dt_140446590;
typedef std::pair<int const, MS2Ptr<ArcadeOpenContext> > Unk_Dt_140446c80;
typedef std::pair<unsigned int const, MS2Ptr<BurningLevelupContext> > Unk_Dt_140446ca0;
typedef std::pair<unsigned int const, MS2Ptr<CollectItemGroupContext> > Unk_Dt_140446cc0;
typedef std::pair<unsigned int const, MS2Ptr<EventShopNpcContext> > Unk_Dt_140446ce0;
typedef std::pair<unsigned int const, MS2Ptr<ItemBoxEventContext> > Unk_Dt_140446d00;
typedef std::pair<unsigned int const, MS2Ptr<LimitedQuantityContext> > Unk_Dt_140446d20;
typedef std::pair<unsigned long const, std::list<MS2Ptr<EventShopNpcContext>, std::allocator<MS2Ptr<EventShopNpcContext> > > > Unk_Dt_140446d40;
typedef std::pair<unsigned long const, std::map<std::pair<int, unsigned long>, int, std::less<std::pair<int, unsigned long> >, std::allocator<std::pair<std::pair<int, unsigned long> const, int> > > > Unk_Dt_140446d60;
typedef std::pair<unsigned long const, std::map<unsigned __int64, unsigned int, std::less<unsigned __int64>, std::allocator<std::pair<unsigned __int64 const, unsigned int> > > > Unk_Dt_140446d80;
typedef std::_Tree_val<std::_Tree_simple_types<std::pair<int const, MS2Ptr<ArcadeOpenContext> > > > Unk_Tv_140465540;
typedef std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned long const, unsigned long> > > Unk_Tv_140465570;
typedef std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned long const, MS2Ptr<BurningLevelupContext> > > > Unk_Tv_1404655a0;
typedef std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned long const, MS2Ptr<CollectItemGroupContext> > > > Unk_Tv_1404655d0;
typedef std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned long const, MS2Ptr<EventShopNpcContext> > > > Unk_Tv_140465600;
typedef std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned long const, MS2Ptr<ItemBoxEventContext> > > > Unk_Tv_140465630;
typedef std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned long const, MS2Ptr<LimitedQuantityContext> > > > Unk_Tv_140465660;
typedef std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned long const, std::list<MS2Ptr<EventShopNpcContext>, std::allocator<MS2Ptr<EventShopNpcContext> > > > > > Unk_Tv_140465690;
typedef std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned long const, std::map<std::pair<int, unsigned long>, int, std::less<std::pair<int, unsigned long> >, std::allocator<std::pair<std::pair<int, unsigned long> const, int> > > > > > Unk_Tv_1404656c0;
typedef std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned long const, std::map<unsigned __int64, unsigned int, std::less<unsigned __int64>, std::allocator<std::pair<unsigned __int64 const, unsigned int> > > > > > Unk_Tv_1404656f0;
typedef std::_Tree_val<std::_Tree_simple_types<std::pair<std::pair<int, unsigned long> const, int> > > Unk_Tv_140465720;
typedef std::_Tree_val<std::_Tree_simple_types<std::pair<Unk_DungeonGroupType const, std::pair<int, int> > > > Unk_Tv_140465750;
typedef std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned __int64 const, unsigned int> > > Unk_Tv_140465780;


// ---- this unit's own forward declarations ----
void* FUN_140449650(void* pIter);
void* FUN_140449670(void* pIter);
void* FUN_140449690(void* pIter);
void* FUN_1404496b0(void* pIter);
void* FUN_1404496d0(void* pIter);
void* FUN_1404496f0(void* pIter);
void* FUN_140449710(void* pIter);
void* FUN_140449730(void* pIter);
void* FUN_140449750(void* pIter);
void* FUN_140449770(void* pIter);
void* FUN_140449790(void* pIter);
void* FUN_1404497b0(void* pIter);
void* FUN_1404497d0(void* pIter);

// The red-black-tree node this unit's iterators point into: _Left +0x00, _Parent +0x08, _Right +0x10,
// _Isnil +0x19 (the MSVC std::_Tree_node layout).
struct Unk_TreeNode
{
    Unk_TreeNode* m_pLeft;
    Unk_TreeNode* m_pParent;
    Unk_TreeNode* m_pRight;
    char          m_Color;
    char          m_Isnil;
};
MS2_CHECK_OFFSET(Unk_TreeNode, m_Isnil, 0x19);

// ---- the per-type iterator steps ----
void* FUN_1404499b0(Unk_TreeNode** pIter);
void* FUN_140449a80(Unk_TreeNode** pIter);
void* FUN_140449b50(Unk_TreeNode** pIter);
void* FUN_140449c20(Unk_TreeNode** pIter);
void* FUN_140449cf0(Unk_TreeNode** pIter);
void* FUN_140449dc0(Unk_TreeNode** pIter);
void* FUN_140449e90(Unk_TreeNode** pIter);
void* FUN_140449f60(Unk_TreeNode** pIter);
void* FUN_14044a030(Unk_TreeNode** pIter);
void* FUN_14044a100(Unk_TreeNode** pIter);
void* FUN_14044a1d0(Unk_TreeNode** pIter);
void* FUN_14044a2a0(Unk_TreeNode** pIter);
void* FUN_14044a370(Unk_TreeNode** pIter);
void* FUN_14044a440(Unk_TreeNode** pIter);

// ---------------------------------------------------------------------------
// operator++ forwards: step the iterator in place and hand the same iterator back
// ---------------------------------------------------------------------------
// @0x140449650
void* FUN_140449650(void* pIter) { FUN_1404499b0((Unk_TreeNode**)pIter); return pIter; }
// @0x140449670
void* FUN_140449670(void* pIter) { FUN_140449a80((Unk_TreeNode**)pIter); return pIter; }
// @0x140449690
void* FUN_140449690(void* pIter) { FUN_140449b50((Unk_TreeNode**)pIter); return pIter; }
// @0x1404496b0
void* FUN_1404496b0(void* pIter) { FUN_140449c20((Unk_TreeNode**)pIter); return pIter; }
// @0x1404496d0
void* FUN_1404496d0(void* pIter) { FUN_140449cf0((Unk_TreeNode**)pIter); return pIter; }
// @0x1404496f0
void* FUN_1404496f0(void* pIter) { FUN_140449dc0((Unk_TreeNode**)pIter); return pIter; }
// @0x140449710
void* FUN_140449710(void* pIter) { FUN_140449e90((Unk_TreeNode**)pIter); return pIter; }
// @0x140449730
void* FUN_140449730(void* pIter) { FUN_140449f60((Unk_TreeNode**)pIter); return pIter; }
// @0x140449750
void* FUN_140449750(void* pIter) { FUN_14044a030((Unk_TreeNode**)pIter); return pIter; }
// @0x140449770
void* FUN_140449770(void* pIter) { FUN_14044a100((Unk_TreeNode**)pIter); return pIter; }
// @0x140449790
void* FUN_140449790(void* pIter) { FUN_14044a1d0((Unk_TreeNode**)pIter); return pIter; }
// @0x1404497b0
void* FUN_1404497b0(void* pIter) { FUN_14044a2a0((Unk_TreeNode**)pIter); return pIter; }
// @0x1404497d0
void* FUN_1404497d0(void* pIter) { FUN_14044a370((Unk_TreeNode**)pIter); return pIter; }
// @0x1404497f0
void* FUN_1404497f0(void* pIter) { FUN_14044a440((Unk_TreeNode**)pIter); return pIter; }

// the same step applied a second time per type
// @0x140449810
void* FUN_140449810(void* pIter) { FUN_140449650(pIter); return pIter; }
// @0x140449830
void* FUN_140449830(void* pIter) { FUN_140449670(pIter); return pIter; }
// @0x140449850
void* FUN_140449850(void* pIter) { FUN_140449690(pIter); return pIter; }
// @0x140449870
void* FUN_140449870(void* pIter) { FUN_1404496b0(pIter); return pIter; }
// @0x140449890
void* FUN_140449890(void* pIter) { FUN_1404496d0(pIter); return pIter; }
// @0x1404498b0
void* FUN_1404498b0(void* pIter) { FUN_1404496f0(pIter); return pIter; }
// @0x1404498d0
void* FUN_1404498d0(void* pIter) { FUN_140449710(pIter); return pIter; }
// @0x1404498f0
void* FUN_1404498f0(void* pIter) { FUN_140449730(pIter); return pIter; }
// @0x140449910
void* FUN_140449910(void* pIter) { FUN_140449750(pIter); return pIter; }
// @0x140449930
void* FUN_140449930(void* pIter) { FUN_140449770(pIter); return pIter; }
// @0x140449950
void* FUN_140449950(void* pIter) { FUN_140449790(pIter); return pIter; }
// @0x140449970
void* FUN_140449970(void* pIter) { FUN_1404497b0(pIter); return pIter; }
// @0x140449990
void* FUN_140449990(void* pIter) { FUN_1404497d0(pIter); return pIter; }

// ---------------------------------------------------------------------------
// the per-type iterator steps
// ---------------------------------------------------------------------------


// @0x1404499b0
void* FUN_1404499b0(Unk_TreeNode** pIter)
{
    Unk_TreeNode* p;
    if ((*pIter)->m_Isnil != 0)
    {
        *pIter = (*pIter)->m_pRight;
    }
    else if ((*pIter)->m_pLeft->m_Isnil != 0)
    {
        while ((p = (*pIter)->m_pParent)->m_Isnil == 0 && *pIter == p->m_pLeft)
            *pIter = p;
        if ((*pIter)->m_Isnil == 0)
            *pIter = p;
    }
    else
    {
        *pIter = (Unk_TreeNode*)Unk_Tv_140465540::_Max(reinterpret_cast<Unk_Tv_140465540::_Nodeptr>((*pIter)->m_pLeft));
    }
    return pIter;
}

// @0x140449a80
void* FUN_140449a80(Unk_TreeNode** pIter)
{
    Unk_TreeNode* p;
    if ((*pIter)->m_Isnil != 0)
    {
        *pIter = (*pIter)->m_pRight;
    }
    else if ((*pIter)->m_pLeft->m_Isnil != 0)
    {
        while ((p = (*pIter)->m_pParent)->m_Isnil == 0 && *pIter == p->m_pLeft)
            *pIter = p;
        if ((*pIter)->m_Isnil == 0)
            *pIter = p;
    }
    else
    {
        *pIter = (Unk_TreeNode*)Unk_Tv_140465570::_Max(reinterpret_cast<Unk_Tv_140465570::_Nodeptr>((*pIter)->m_pLeft));
    }
    return pIter;
}

// @0x140449b50
void* FUN_140449b50(Unk_TreeNode** pIter)
{
    Unk_TreeNode* p;
    if ((*pIter)->m_Isnil != 0)
    {
        *pIter = (*pIter)->m_pRight;
    }
    else if ((*pIter)->m_pLeft->m_Isnil != 0)
    {
        while ((p = (*pIter)->m_pParent)->m_Isnil == 0 && *pIter == p->m_pLeft)
            *pIter = p;
        if ((*pIter)->m_Isnil == 0)
            *pIter = p;
    }
    else
    {
        *pIter = (Unk_TreeNode*)Unk_Tv_1404655a0::_Max(reinterpret_cast<Unk_Tv_1404655a0::_Nodeptr>((*pIter)->m_pLeft));
    }
    return pIter;
}

// @0x140449c20
void* FUN_140449c20(Unk_TreeNode** pIter)
{
    Unk_TreeNode* p;
    if ((*pIter)->m_Isnil != 0)
    {
        *pIter = (*pIter)->m_pRight;
    }
    else if ((*pIter)->m_pLeft->m_Isnil != 0)
    {
        while ((p = (*pIter)->m_pParent)->m_Isnil == 0 && *pIter == p->m_pLeft)
            *pIter = p;
        if ((*pIter)->m_Isnil == 0)
            *pIter = p;
    }
    else
    {
        *pIter = (Unk_TreeNode*)Unk_Tv_1404655d0::_Max(reinterpret_cast<Unk_Tv_1404655d0::_Nodeptr>((*pIter)->m_pLeft));
    }
    return pIter;
}

// @0x140449cf0
void* FUN_140449cf0(Unk_TreeNode** pIter)
{
    Unk_TreeNode* p;
    if ((*pIter)->m_Isnil != 0)
    {
        *pIter = (*pIter)->m_pRight;
    }
    else if ((*pIter)->m_pLeft->m_Isnil != 0)
    {
        while ((p = (*pIter)->m_pParent)->m_Isnil == 0 && *pIter == p->m_pLeft)
            *pIter = p;
        if ((*pIter)->m_Isnil == 0)
            *pIter = p;
    }
    else
    {
        *pIter = (Unk_TreeNode*)Unk_Tv_140465600::_Max(reinterpret_cast<Unk_Tv_140465600::_Nodeptr>((*pIter)->m_pLeft));
    }
    return pIter;
}

// @0x140449dc0
void* FUN_140449dc0(Unk_TreeNode** pIter)
{
    Unk_TreeNode* p;
    if ((*pIter)->m_Isnil != 0)
    {
        *pIter = (*pIter)->m_pRight;
    }
    else if ((*pIter)->m_pLeft->m_Isnil != 0)
    {
        while ((p = (*pIter)->m_pParent)->m_Isnil == 0 && *pIter == p->m_pLeft)
            *pIter = p;
        if ((*pIter)->m_Isnil == 0)
            *pIter = p;
    }
    else
    {
        *pIter = (Unk_TreeNode*)Unk_Tv_140465630::_Max(reinterpret_cast<Unk_Tv_140465630::_Nodeptr>((*pIter)->m_pLeft));
    }
    return pIter;
}

// @0x140449e90
void* FUN_140449e90(Unk_TreeNode** pIter)
{
    Unk_TreeNode* p;
    if ((*pIter)->m_Isnil != 0)
    {
        *pIter = (*pIter)->m_pRight;
    }
    else if ((*pIter)->m_pLeft->m_Isnil != 0)
    {
        while ((p = (*pIter)->m_pParent)->m_Isnil == 0 && *pIter == p->m_pLeft)
            *pIter = p;
        if ((*pIter)->m_Isnil == 0)
            *pIter = p;
    }
    else
    {
        *pIter = (Unk_TreeNode*)Unk_Tv_140465660::_Max(reinterpret_cast<Unk_Tv_140465660::_Nodeptr>((*pIter)->m_pLeft));
    }
    return pIter;
}

// @0x140449f60
void* FUN_140449f60(Unk_TreeNode** pIter)
{
    Unk_TreeNode* p;
    if ((*pIter)->m_Isnil != 0)
    {
        *pIter = (*pIter)->m_pRight;
    }
    else if ((*pIter)->m_pLeft->m_Isnil != 0)
    {
        while ((p = (*pIter)->m_pParent)->m_Isnil == 0 && *pIter == p->m_pLeft)
            *pIter = p;
        if ((*pIter)->m_Isnil == 0)
            *pIter = p;
    }
    else
    {
        *pIter = (Unk_TreeNode*)Unk_Tv_140465690::_Max(reinterpret_cast<Unk_Tv_140465690::_Nodeptr>((*pIter)->m_pLeft));
    }
    return pIter;
}

// @0x14044a030
void* FUN_14044a030(Unk_TreeNode** pIter)
{
    Unk_TreeNode* p;
    if ((*pIter)->m_Isnil != 0)
    {
        *pIter = (*pIter)->m_pRight;
    }
    else if ((*pIter)->m_pLeft->m_Isnil != 0)
    {
        while ((p = (*pIter)->m_pParent)->m_Isnil == 0 && *pIter == p->m_pLeft)
            *pIter = p;
        if ((*pIter)->m_Isnil == 0)
            *pIter = p;
    }
    else
    {
        *pIter = (Unk_TreeNode*)Unk_Tv_1404656c0::_Max(reinterpret_cast<Unk_Tv_1404656c0::_Nodeptr>((*pIter)->m_pLeft));
    }
    return pIter;
}

// @0x14044a100
void* FUN_14044a100(Unk_TreeNode** pIter)
{
    Unk_TreeNode* p;
    if ((*pIter)->m_Isnil != 0)
    {
        *pIter = (*pIter)->m_pRight;
    }
    else if ((*pIter)->m_pLeft->m_Isnil != 0)
    {
        while ((p = (*pIter)->m_pParent)->m_Isnil == 0 && *pIter == p->m_pLeft)
            *pIter = p;
        if ((*pIter)->m_Isnil == 0)
            *pIter = p;
    }
    else
    {
        *pIter = (Unk_TreeNode*)Unk_Tv_1404656f0::_Max(reinterpret_cast<Unk_Tv_1404656f0::_Nodeptr>((*pIter)->m_pLeft));
    }
    return pIter;
}

// @0x14044a1d0
void* FUN_14044a1d0(Unk_TreeNode** pIter)
{
    Unk_TreeNode* p;
    if ((*pIter)->m_Isnil != 0)
    {
        *pIter = (*pIter)->m_pRight;
    }
    else if ((*pIter)->m_pLeft->m_Isnil != 0)
    {
        while ((p = (*pIter)->m_pParent)->m_Isnil == 0 && *pIter == p->m_pLeft)
            *pIter = p;
        if ((*pIter)->m_Isnil == 0)
            *pIter = p;
    }
    else
    {
        *pIter = (Unk_TreeNode*)Unk_Tv_140465720::_Max(reinterpret_cast<Unk_Tv_140465720::_Nodeptr>((*pIter)->m_pLeft));
    }
    return pIter;
}

// @0x14044a2a0
void* FUN_14044a2a0(Unk_TreeNode** pIter)
{
    Unk_TreeNode* p;
    if ((*pIter)->m_Isnil != 0)
    {
        *pIter = (*pIter)->m_pRight;
    }
    else if ((*pIter)->m_pLeft->m_Isnil != 0)
    {
        while ((p = (*pIter)->m_pParent)->m_Isnil == 0 && *pIter == p->m_pLeft)
            *pIter = p;
        if ((*pIter)->m_Isnil == 0)
            *pIter = p;
    }
    else
    {
        *pIter = (Unk_TreeNode*)Unk_Tv_140465750::_Max(reinterpret_cast<Unk_Tv_140465750::_Nodeptr>((*pIter)->m_pLeft));
    }
    return pIter;
}

// @0x14044a370
void* FUN_14044a370(Unk_TreeNode** pIter)
{
    Unk_TreeNode* p;
    if ((*pIter)->m_Isnil != 0)
    {
        *pIter = (*pIter)->m_pRight;
    }
    else if ((*pIter)->m_pLeft->m_Isnil != 0)
    {
        while ((p = (*pIter)->m_pParent)->m_Isnil == 0 && *pIter == p->m_pLeft)
            *pIter = p;
        if ((*pIter)->m_Isnil == 0)
            *pIter = p;
    }
    else
    {
        *pIter = (Unk_TreeNode*)Unk_Tv_140465780::_Max(reinterpret_cast<Unk_Tv_140465780::_Nodeptr>((*pIter)->m_pLeft));
    }
    return pIter;
}

// @0x14044a440
void* FUN_14044a440(Unk_TreeNode** pIter)
{
    Unk_TreeNode* p;
    if ((*pIter)->m_Isnil != 0)
    {
        *pIter = (*pIter)->m_pRight;
    }
    else if ((*pIter)->m_pLeft->m_Isnil != 0)
    {
        while ((p = (*pIter)->m_pParent)->m_Isnil == 0 && *pIter == p->m_pLeft)
            *pIter = p;
        if ((*pIter)->m_Isnil == 0)
            *pIter = p;
    }
    else
    {
        *pIter = (Unk_TreeNode*)Unk_Tv_14033e2b0::_Max(reinterpret_cast<Unk_Tv_14033e2b0::_Nodeptr>((*pIter)->m_pLeft));
    }
    return pIter;
}

// ---------------------------------------------------------------------------
// the two remaining helpers
// ---------------------------------------------------------------------------

// Two-argument forwarding shim (its first argument is unused).
// @0x14044a510
void FUN_14044a510(void* pUnused, void* pA, void* pB)
{
    *reinterpret_cast<const std::pair<int, unsigned long>*>(pA) < *reinterpret_cast<const std::pair<int, unsigned long>*>(pB);
}

// The unit's ordering predicate: unsigned "less" over the first field of two keys.
// @0x14044a540
bool FUN_14044a540(void* pUnused, unsigned __int64* pA, unsigned __int64* pB)
{
    return *pA < *pB;
}

// ---------------------------------------------------------------------------
// scalar deleting destructors: run the boxed type's destructor, then (flag bit 0) sized-free the box
// ---------------------------------------------------------------------------

// @0x14044a580
void* FUN_14044a580(void* p, unsigned int nFlags)
{
    reinterpret_cast<Unk_Dt_1403e51b0*>(p)->Unk_Dt_1403e51b0::~Unk_Dt_1403e51b0();
    if ((nFlags & 1) != 0)
        operator delete(p, 0x10);
    return p;
}

// @0x14044a5c0
void* FUN_14044a5c0(void* p, unsigned int nFlags)
{
    reinterpret_cast<Unk_Dt_140446470*>(p)->Unk_Dt_140446470::~Unk_Dt_140446470();
    if ((nFlags & 1) != 0)
        operator delete(p, 0x10);
    return p;
}

// @0x14044a600
void* FUN_14044a600(void* p, unsigned int nFlags)
{
    reinterpret_cast<Unk_Dt_140446590*>(p)->Unk_Dt_140446590::~Unk_Dt_140446590();
    if ((nFlags & 1) != 0)
        operator delete(p, 0x48);
    return p;
}

// @0x14044a640
void* FUN_14044a640(void* p, unsigned int nFlags)
{
    reinterpret_cast<Unk_Dt_140446c80*>(p)->Unk_Dt_140446c80::~Unk_Dt_140446c80();
    if ((nFlags & 1) != 0)
        operator delete(p, 0x18);
    return p;
}

// @0x14044a680
void* FUN_14044a680(void* p, unsigned int nFlags)
{
    reinterpret_cast<Unk_Dt_140446ca0*>(p)->Unk_Dt_140446ca0::~Unk_Dt_140446ca0();
    if ((nFlags & 1) != 0)
        operator delete(p, 0x18);
    return p;
}

// @0x14044a6c0
void* FUN_14044a6c0(void* p, unsigned int nFlags)
{
    reinterpret_cast<Unk_Dt_140446cc0*>(p)->Unk_Dt_140446cc0::~Unk_Dt_140446cc0();
    if ((nFlags & 1) != 0)
        operator delete(p, 0x18);
    return p;
}

// @0x14044a700
void* FUN_14044a700(void* p, unsigned int nFlags)
{
    reinterpret_cast<Unk_Dt_140446ce0*>(p)->Unk_Dt_140446ce0::~Unk_Dt_140446ce0();
    if ((nFlags & 1) != 0)
        operator delete(p, 0x18);
    return p;
}

// @0x14044a740
void* FUN_14044a740(void* p, unsigned int nFlags)
{
    reinterpret_cast<Unk_Dt_140446d00*>(p)->Unk_Dt_140446d00::~Unk_Dt_140446d00();
    if ((nFlags & 1) != 0)
        operator delete(p, 0x18);
    return p;
}

// @0x14044a780
void* FUN_14044a780(void* p, unsigned int nFlags)
{
    reinterpret_cast<Unk_Dt_140446d20*>(p)->Unk_Dt_140446d20::~Unk_Dt_140446d20();
    if ((nFlags & 1) != 0)
        operator delete(p, 0x18);
    return p;
}

// @0x14044a7c0
void* FUN_14044a7c0(void* p, unsigned int nFlags)
{
    reinterpret_cast<Unk_Dt_140446d40*>(p)->Unk_Dt_140446d40::~Unk_Dt_140446d40();
    if ((nFlags & 1) != 0)
        operator delete(p, 0x18);
    return p;
}

// @0x14044a800
void* FUN_14044a800(void* p, unsigned int nFlags)
{
    reinterpret_cast<Unk_Dt_140446d60*>(p)->Unk_Dt_140446d60::~Unk_Dt_140446d60();
    if ((nFlags & 1) != 0)
        operator delete(p, 0x18);
    return p;
}

// @0x14044a840
void* FUN_14044a840(void* p, unsigned int nFlags)
{
    reinterpret_cast<Unk_Dt_140446d80*>(p)->Unk_Dt_140446d80::~Unk_Dt_140446d80();
    if ((nFlags & 1) != 0)
        operator delete(p, 0x18);
    return p;
}
