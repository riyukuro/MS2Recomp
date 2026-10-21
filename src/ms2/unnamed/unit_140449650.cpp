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

// ---- callees defined outside this unit ----
void* FUN_140465540(void* pNode);
void* FUN_140465570(void* pNode);
void* FUN_1404655a0(void* pNode);
void* FUN_1404655d0(void* pNode);
void* FUN_140465600(void* pNode);
void* FUN_140465630(void* pNode);
void* FUN_140465660(void* pNode);
void* FUN_140465690(void* pNode);
void* FUN_1404656c0(void* pNode);
void* FUN_1404656f0(void* pNode);
void* FUN_140465720(void* pNode);
void* FUN_140465750(void* pNode);
void* FUN_140465780(void* pNode);
void* FUN_14033e2b0(void* pNode);
void  FUN_14042ca70(void* pA, void* pB);

void  FUN_1403e51b0(void* p);
void  FUN_140446470(void* p);
void  FUN_140446590(void* p);
void  FUN_140446c80(void* p);
void  FUN_140446ca0(void* p);
void  FUN_140446cc0(void* p);
void  FUN_140446ce0(void* p);
void  FUN_140446d00(void* p);
void  FUN_140446d20(void* p);
void  FUN_140446d40(void* p);
void  FUN_140446d60(void* p);
void  FUN_140446d80(void* p);

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
        *pIter = (Unk_TreeNode*)FUN_140465540((*pIter)->m_pLeft);
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
        *pIter = (Unk_TreeNode*)FUN_140465570((*pIter)->m_pLeft);
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
        *pIter = (Unk_TreeNode*)FUN_1404655a0((*pIter)->m_pLeft);
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
        *pIter = (Unk_TreeNode*)FUN_1404655d0((*pIter)->m_pLeft);
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
        *pIter = (Unk_TreeNode*)FUN_140465600((*pIter)->m_pLeft);
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
        *pIter = (Unk_TreeNode*)FUN_140465630((*pIter)->m_pLeft);
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
        *pIter = (Unk_TreeNode*)FUN_140465660((*pIter)->m_pLeft);
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
        *pIter = (Unk_TreeNode*)FUN_140465690((*pIter)->m_pLeft);
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
        *pIter = (Unk_TreeNode*)FUN_1404656c0((*pIter)->m_pLeft);
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
        *pIter = (Unk_TreeNode*)FUN_1404656f0((*pIter)->m_pLeft);
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
        *pIter = (Unk_TreeNode*)FUN_140465720((*pIter)->m_pLeft);
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
        *pIter = (Unk_TreeNode*)FUN_140465750((*pIter)->m_pLeft);
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
        *pIter = (Unk_TreeNode*)FUN_140465780((*pIter)->m_pLeft);
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
        *pIter = (Unk_TreeNode*)FUN_14033e2b0((*pIter)->m_pLeft);
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
    FUN_14042ca70(pA, pB);
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
    FUN_1403e51b0(p);
    if ((nFlags & 1) != 0)
        operator delete(p, 0x10);
    return p;
}

// @0x14044a5c0
void* FUN_14044a5c0(void* p, unsigned int nFlags)
{
    FUN_140446470(p);
    if ((nFlags & 1) != 0)
        operator delete(p, 0x10);
    return p;
}

// @0x14044a600
void* FUN_14044a600(void* p, unsigned int nFlags)
{
    FUN_140446590(p);
    if ((nFlags & 1) != 0)
        operator delete(p, 0x48);
    return p;
}

// @0x14044a640
void* FUN_14044a640(void* p, unsigned int nFlags)
{
    FUN_140446c80(p);
    if ((nFlags & 1) != 0)
        operator delete(p, 0x18);
    return p;
}

// @0x14044a680
void* FUN_14044a680(void* p, unsigned int nFlags)
{
    FUN_140446ca0(p);
    if ((nFlags & 1) != 0)
        operator delete(p, 0x18);
    return p;
}

// @0x14044a6c0
void* FUN_14044a6c0(void* p, unsigned int nFlags)
{
    FUN_140446cc0(p);
    if ((nFlags & 1) != 0)
        operator delete(p, 0x18);
    return p;
}

// @0x14044a700
void* FUN_14044a700(void* p, unsigned int nFlags)
{
    FUN_140446ce0(p);
    if ((nFlags & 1) != 0)
        operator delete(p, 0x18);
    return p;
}

// @0x14044a740
void* FUN_14044a740(void* p, unsigned int nFlags)
{
    FUN_140446d00(p);
    if ((nFlags & 1) != 0)
        operator delete(p, 0x18);
    return p;
}

// @0x14044a780
void* FUN_14044a780(void* p, unsigned int nFlags)
{
    FUN_140446d20(p);
    if ((nFlags & 1) != 0)
        operator delete(p, 0x18);
    return p;
}

// @0x14044a7c0
void* FUN_14044a7c0(void* p, unsigned int nFlags)
{
    FUN_140446d40(p);
    if ((nFlags & 1) != 0)
        operator delete(p, 0x18);
    return p;
}

// @0x14044a800
void* FUN_14044a800(void* p, unsigned int nFlags)
{
    FUN_140446d60(p);
    if ((nFlags & 1) != 0)
        operator delete(p, 0x18);
    return p;
}

// @0x14044a840
void* FUN_14044a840(void* p, unsigned int nFlags)
{
    FUN_140446d80(p);
    if ((nFlags & 1) != 0)
        operator delete(p, 0x18);
    return p;
}
