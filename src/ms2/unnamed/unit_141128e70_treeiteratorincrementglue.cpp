// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Unnamed unit unit_141128e70: the out-of-line iterator
// glue of a family of red-black-tree containers (one per element type). Four bodies repeat, byte for byte, over 102
// symbols:
//   * A (28x, 0x41): the post-increment wrapper. It copies the iterator the caller passes in rcx, advances it with
//     the matching B entry, stores the pre-increment copy through the return slot in rdx and hands that slot back
//     in rax. The exe homes r8d as well, so the source carries an unused third (int) parameter - the shape MSVC
//     emits for `iterator operator++(int)`.
//   * B (47x, 0x1d): the plain `++` wrapper: call the matching C entry on the iterator and return its address.
//   * C (25x, 0x8f): the tree `_Inc` step. `if ((*p)->_Right->_Isnil)`: climb - node = node->_Parent while that
//     parent is not the nil header and node is still its right child, then park on the parent; otherwise
//     node = the per-type _Min helper (FUN_1411488c0 + 0x30 * index) of the right child.
//   * D (2x, 0x1f): a list-node step: node += 8, iterator returned.
// The iterator is a single node pointer; a node is {left, parent, right, colour, isnil} and the nil flag is the
// signed byte at +0x19 (the exe loads it with movsx, so it is a char, not a bool). All names invented from shape;
// the four external callees (FUN_1408853c0, FUN_140965a60, FUN_14063ef60) live outside this unit.
// MS2-UNIT: unit_141128e70
// MS2-RANGE: 0x141128e70-0x14112ab60 .text$mn
#define MS2_THIS_FILE ""

#include "ms2/placeholder/ms2stdafx.h"

#include "ms2/ms2recover.h"

typedef __int64 i64;
typedef unsigned __int64 u64;

// ---- unit-local views of the shapes this unit walks ----
struct Unk_TreeNode {
    Unk_TreeNode* m_pLeft;      // +0x00
    Unk_TreeNode* m_pParent;    // +0x08
    Unk_TreeNode* m_pRight;     // +0x10
    char m_chColor;             // +0x18
    char m_chIsNil;             // +0x19 the header flag
};

struct Unk_TreeIter { Unk_TreeNode* m_pNode; };

// The list-node view the two D entries step over (one 8-byte link per element).
struct Unk_ListNode { void* m_pNext; };

// ---- the per-type _Min helpers and the four callees outside this unit ----
Unk_TreeNode* FUN_1411488c0(Unk_TreeNode* pNode);
Unk_TreeNode* FUN_1411488f0(Unk_TreeNode* pNode);
Unk_TreeNode* FUN_141148920(Unk_TreeNode* pNode);
Unk_TreeNode* FUN_141148950(Unk_TreeNode* pNode);
Unk_TreeNode* FUN_141148980(Unk_TreeNode* pNode);
Unk_TreeNode* FUN_1411489b0(Unk_TreeNode* pNode);
Unk_TreeNode* FUN_1411489e0(Unk_TreeNode* pNode);
Unk_TreeNode* FUN_141148a10(Unk_TreeNode* pNode);
Unk_TreeNode* FUN_141148a40(Unk_TreeNode* pNode);
Unk_TreeNode* FUN_141148a70(Unk_TreeNode* pNode);
Unk_TreeNode* FUN_141148aa0(Unk_TreeNode* pNode);
Unk_TreeNode* FUN_141148ad0(Unk_TreeNode* pNode);
Unk_TreeNode* FUN_141148b00(Unk_TreeNode* pNode);
Unk_TreeNode* FUN_141148b30(Unk_TreeNode* pNode);
Unk_TreeNode* FUN_141148b60(Unk_TreeNode* pNode);
Unk_TreeNode* FUN_141148b90(Unk_TreeNode* pNode);
Unk_TreeNode* FUN_141148bc0(Unk_TreeNode* pNode);
Unk_TreeNode* FUN_141148bf0(Unk_TreeNode* pNode);
Unk_TreeNode* FUN_141148c20(Unk_TreeNode* pNode);
Unk_TreeNode* FUN_141148c50(Unk_TreeNode* pNode);
Unk_TreeNode* FUN_141148c80(Unk_TreeNode* pNode);
Unk_TreeNode* FUN_141148cb0(Unk_TreeNode* pNode);
Unk_TreeNode* FUN_141148ce0(Unk_TreeNode* pNode);
Unk_TreeNode* FUN_141148d10(Unk_TreeNode* pNode);
Unk_TreeNode* FUN_141148d40(Unk_TreeNode* pNode);

void* FUN_1408853c0(Unk_TreeIter* pIter);
void* FUN_140965a60(Unk_TreeIter* pIter);
void* FUN_14063ef60(Unk_TreeIter* pIter);

// ---- forward declarations of this unit's 102 entries ----

void* FUN_141128e70(Unk_TreeIter* pIter, Unk_TreeIter* pRet, int);
void* FUN_141128ec0(Unk_TreeIter* pIter);
void* FUN_141128ee0(Unk_TreeIter* pIter, Unk_TreeIter* pRet, int);
void* FUN_141128f30(Unk_TreeIter* pIter);
void* FUN_141128f50(Unk_TreeIter* pIter, Unk_TreeIter* pRet, int);
void* FUN_141128fa0(Unk_TreeIter* pIter);
void* FUN_141128fc0(Unk_TreeIter* pIter, Unk_TreeIter* pRet, int);
void* FUN_141129010(Unk_TreeIter* pIter);
void* FUN_141129030(Unk_TreeIter* pIter, Unk_TreeIter* pRet, int);
void* FUN_141129080(Unk_TreeIter* pIter);
void* FUN_1411290a0(Unk_TreeIter* pIter, Unk_TreeIter* pRet, int);
void* FUN_1411290f0(Unk_TreeIter* pIter);
void* FUN_141129110(Unk_TreeIter* pIter, Unk_TreeIter* pRet, int);
void* FUN_141129160(Unk_TreeIter* pIter);
void* FUN_141129180(Unk_TreeIter* pIter, Unk_TreeIter* pRet, int);
void* FUN_1411291d0(Unk_TreeIter* pIter);
void* FUN_1411291f0(Unk_TreeIter* pIter, Unk_TreeIter* pRet, int);
void* FUN_141129240(Unk_TreeIter* pIter);
void* FUN_141129260(Unk_TreeIter* pIter, Unk_TreeIter* pRet, int);
void* FUN_1411292b0(Unk_TreeIter* pIter);
void* FUN_1411292d0(Unk_TreeIter* pIter, Unk_TreeIter* pRet, int);
void* FUN_141129320(Unk_TreeIter* pIter);
void* FUN_141129340(Unk_TreeIter* pIter, Unk_TreeIter* pRet, int);
void* FUN_141129390(Unk_TreeIter* pIter);
void* FUN_1411293b0(Unk_TreeIter* pIter, Unk_TreeIter* pRet, int);
void* FUN_141129400(Unk_TreeIter* pIter);
void* FUN_141129420(Unk_TreeIter* pIter, Unk_TreeIter* pRet, int);
void* FUN_141129470(Unk_TreeIter* pIter);
void* FUN_141129490(Unk_TreeIter* pIter, Unk_TreeIter* pRet, int);
void* FUN_1411294e0(Unk_TreeIter* pIter);
void* FUN_141129500(Unk_TreeIter* pIter, Unk_TreeIter* pRet, int);
void* FUN_141129550(Unk_TreeIter* pIter);
void* FUN_141129570(Unk_TreeIter* pIter, Unk_TreeIter* pRet, int);
void* FUN_1411295c0(Unk_TreeIter* pIter);
void* FUN_1411295e0(Unk_TreeIter* pIter, Unk_TreeIter* pRet, int);
void* FUN_141129630(Unk_TreeIter* pIter);
void* FUN_141129650(Unk_TreeIter* pIter, Unk_TreeIter* pRet, int);
void* FUN_1411296a0(Unk_TreeIter* pIter);
void* FUN_1411296c0(Unk_TreeIter* pIter, Unk_TreeIter* pRet, int);
void* FUN_141129710(Unk_TreeIter* pIter);
void* FUN_141129730(Unk_TreeIter* pIter, Unk_TreeIter* pRet, int);
void* FUN_141129780(Unk_TreeIter* pIter);
void* FUN_1411297a0(Unk_TreeIter* pIter, Unk_TreeIter* pRet, int);
void* FUN_1411297f0(Unk_TreeIter* pIter);
void* FUN_141129810(Unk_TreeIter* pIter, Unk_TreeIter* pRet, int);
void* FUN_141129860(Unk_TreeIter* pIter, Unk_TreeIter* pRet, int);
void* FUN_1411298b0(Unk_TreeIter* pIter, Unk_TreeIter* pRet, int);
void* FUN_141129900(Unk_TreeIter* pIter);
void* FUN_141129920(Unk_TreeIter* pIter, Unk_TreeIter* pRet, int);
void* FUN_141129970(Unk_TreeIter* pIter);
void* FUN_141129990(Unk_TreeIter* pIter, Unk_TreeIter* pRet, int);
void* FUN_1411299e0(Unk_TreeIter* pIter);
void* FUN_141129a00(Unk_TreeIter* pIter);
void* FUN_141129a20(Unk_TreeIter* pIter);
void* FUN_141129a40(Unk_TreeIter* pIter);
void* FUN_141129a60(Unk_TreeIter* pIter);
void* FUN_141129a80(Unk_TreeIter* pIter);
void* FUN_141129aa0(Unk_TreeIter* pIter);
void* FUN_141129ac0(Unk_TreeIter* pIter);
void* FUN_141129ae0(Unk_TreeIter* pIter);
void* FUN_141129b00(Unk_TreeIter* pIter, Unk_TreeIter* pRet, int);
void* FUN_141129b50(Unk_TreeIter* pIter);
void* FUN_141129b70(Unk_TreeIter* pIter);
void* FUN_141129b90(Unk_TreeIter* pIter);
void* FUN_141129bb0(Unk_TreeIter* pIter);
void* FUN_141129bd0(Unk_TreeIter* pIter);
void* FUN_141129bf0(Unk_TreeIter* pIter);
void* FUN_141129c10(Unk_TreeIter* pIter);
void* FUN_141129c30(Unk_TreeIter* pIter);
void* FUN_141129c50(Unk_TreeIter* pIter);
void* FUN_141129c70(Unk_TreeIter* pIter);
void* FUN_141129c90(Unk_TreeIter* pIter);
void* FUN_141129cb0(Unk_TreeIter* pIter);
void* FUN_141129cd0(Unk_TreeIter* pIter);
void* FUN_141129cf0(Unk_TreeIter* pIter);
void* FUN_141129d10(Unk_TreeIter* pIter);
void* FUN_141129da0(Unk_TreeIter* pIter);
void* FUN_141129e30(Unk_TreeIter* pIter);
void* FUN_141129ec0(Unk_TreeIter* pIter);
void* FUN_141129f50(Unk_TreeIter* pIter);
void* FUN_141129fe0(Unk_TreeIter* pIter);
void* FUN_14112a070(Unk_TreeIter* pIter);
void* FUN_14112a100(Unk_TreeIter* pIter);
void* FUN_14112a190(Unk_TreeIter* pIter);
void* FUN_14112a220(Unk_TreeIter* pIter);
void* FUN_14112a2b0(Unk_TreeIter* pIter);
void* FUN_14112a340(Unk_TreeIter* pIter);
void* FUN_14112a3d0(Unk_TreeIter* pIter);
void* FUN_14112a460(Unk_TreeIter* pIter);
void* FUN_14112a4f0(Unk_TreeIter* pIter);
void* FUN_14112a580(Unk_TreeIter* pIter);
void* FUN_14112a610(Unk_TreeIter* pIter);
void* FUN_14112a6a0(Unk_TreeIter* pIter);
void* FUN_14112a730(Unk_TreeIter* pIter);
void* FUN_14112a7c0(Unk_TreeIter* pIter);
void* FUN_14112a850(Unk_TreeIter* pIter);
void* FUN_14112a8e0(Unk_TreeIter* pIter);
void* FUN_14112a970(Unk_TreeIter* pIter);
void* FUN_14112aa00(Unk_TreeIter* pIter);
void* FUN_14112aa90(Unk_TreeIter* pIter);
void* FUN_14112ab20(Unk_ListNode** pIter);
void* FUN_14112ab40(Unk_ListNode** pIter);

// ---------------------------------------------------------------------------
// the 102 entries, in address order
// ---------------------------------------------------------------------------

// @0x141128e70
void* FUN_141128e70(Unk_TreeIter* pIter, Unk_TreeIter* pRet, int)
{
    Unk_TreeIter kOld = *pIter;
    FUN_141128ec0(pIter);
    *pRet = kOld;
    return pRet;
}

// @0x141128ec0
void* FUN_141128ec0(Unk_TreeIter* pIter)
{
    FUN_141129d10(pIter);
    return pIter;
}

// @0x141128ee0
void* FUN_141128ee0(Unk_TreeIter* pIter, Unk_TreeIter* pRet, int)
{
    Unk_TreeIter kOld = *pIter;
    FUN_141128f30(pIter);
    *pRet = kOld;
    return pRet;
}

// @0x141128f30
void* FUN_141128f30(Unk_TreeIter* pIter)
{
    FUN_141129da0(pIter);
    return pIter;
}

// @0x141128f50
void* FUN_141128f50(Unk_TreeIter* pIter, Unk_TreeIter* pRet, int)
{
    Unk_TreeIter kOld = *pIter;
    FUN_141128fa0(pIter);
    *pRet = kOld;
    return pRet;
}

// @0x141128fa0
void* FUN_141128fa0(Unk_TreeIter* pIter)
{
    FUN_141129e30(pIter);
    return pIter;
}

// @0x141128fc0
void* FUN_141128fc0(Unk_TreeIter* pIter, Unk_TreeIter* pRet, int)
{
    Unk_TreeIter kOld = *pIter;
    FUN_141129010(pIter);
    *pRet = kOld;
    return pRet;
}

// @0x141129010
void* FUN_141129010(Unk_TreeIter* pIter)
{
    FUN_141129ec0(pIter);
    return pIter;
}

// @0x141129030
void* FUN_141129030(Unk_TreeIter* pIter, Unk_TreeIter* pRet, int)
{
    Unk_TreeIter kOld = *pIter;
    FUN_141129080(pIter);
    *pRet = kOld;
    return pRet;
}

// @0x141129080
void* FUN_141129080(Unk_TreeIter* pIter)
{
    FUN_141129f50(pIter);
    return pIter;
}

// @0x1411290a0
void* FUN_1411290a0(Unk_TreeIter* pIter, Unk_TreeIter* pRet, int)
{
    Unk_TreeIter kOld = *pIter;
    FUN_1411290f0(pIter);
    *pRet = kOld;
    return pRet;
}

// @0x1411290f0
void* FUN_1411290f0(Unk_TreeIter* pIter)
{
    FUN_141129fe0(pIter);
    return pIter;
}

// @0x141129110
void* FUN_141129110(Unk_TreeIter* pIter, Unk_TreeIter* pRet, int)
{
    Unk_TreeIter kOld = *pIter;
    FUN_141129160(pIter);
    *pRet = kOld;
    return pRet;
}

// @0x141129160
void* FUN_141129160(Unk_TreeIter* pIter)
{
    FUN_14112a070(pIter);
    return pIter;
}

// @0x141129180
void* FUN_141129180(Unk_TreeIter* pIter, Unk_TreeIter* pRet, int)
{
    Unk_TreeIter kOld = *pIter;
    FUN_1411291d0(pIter);
    *pRet = kOld;
    return pRet;
}

// @0x1411291d0
void* FUN_1411291d0(Unk_TreeIter* pIter)
{
    FUN_14112a100(pIter);
    return pIter;
}

// @0x1411291f0
void* FUN_1411291f0(Unk_TreeIter* pIter, Unk_TreeIter* pRet, int)
{
    Unk_TreeIter kOld = *pIter;
    FUN_141129240(pIter);
    *pRet = kOld;
    return pRet;
}

// @0x141129240
void* FUN_141129240(Unk_TreeIter* pIter)
{
    FUN_14112a190(pIter);
    return pIter;
}

// @0x141129260
void* FUN_141129260(Unk_TreeIter* pIter, Unk_TreeIter* pRet, int)
{
    Unk_TreeIter kOld = *pIter;
    FUN_1411292b0(pIter);
    *pRet = kOld;
    return pRet;
}

// @0x1411292b0
void* FUN_1411292b0(Unk_TreeIter* pIter)
{
    FUN_14112a220(pIter);
    return pIter;
}

// @0x1411292d0
void* FUN_1411292d0(Unk_TreeIter* pIter, Unk_TreeIter* pRet, int)
{
    Unk_TreeIter kOld = *pIter;
    FUN_141129320(pIter);
    *pRet = kOld;
    return pRet;
}

// @0x141129320
void* FUN_141129320(Unk_TreeIter* pIter)
{
    FUN_14112a2b0(pIter);
    return pIter;
}

// @0x141129340
void* FUN_141129340(Unk_TreeIter* pIter, Unk_TreeIter* pRet, int)
{
    Unk_TreeIter kOld = *pIter;
    FUN_141129390(pIter);
    *pRet = kOld;
    return pRet;
}

// @0x141129390
void* FUN_141129390(Unk_TreeIter* pIter)
{
    FUN_14112a340(pIter);
    return pIter;
}

// @0x1411293b0
void* FUN_1411293b0(Unk_TreeIter* pIter, Unk_TreeIter* pRet, int)
{
    Unk_TreeIter kOld = *pIter;
    FUN_141129400(pIter);
    *pRet = kOld;
    return pRet;
}

// @0x141129400
void* FUN_141129400(Unk_TreeIter* pIter)
{
    FUN_14112a3d0(pIter);
    return pIter;
}

// @0x141129420
void* FUN_141129420(Unk_TreeIter* pIter, Unk_TreeIter* pRet, int)
{
    Unk_TreeIter kOld = *pIter;
    FUN_141129470(pIter);
    *pRet = kOld;
    return pRet;
}

// @0x141129470
void* FUN_141129470(Unk_TreeIter* pIter)
{
    FUN_14112a460(pIter);
    return pIter;
}

// @0x141129490
void* FUN_141129490(Unk_TreeIter* pIter, Unk_TreeIter* pRet, int)
{
    Unk_TreeIter kOld = *pIter;
    FUN_1411294e0(pIter);
    *pRet = kOld;
    return pRet;
}

// @0x1411294e0
void* FUN_1411294e0(Unk_TreeIter* pIter)
{
    FUN_14112a4f0(pIter);
    return pIter;
}

// @0x141129500
void* FUN_141129500(Unk_TreeIter* pIter, Unk_TreeIter* pRet, int)
{
    Unk_TreeIter kOld = *pIter;
    FUN_141129550(pIter);
    *pRet = kOld;
    return pRet;
}

// @0x141129550
void* FUN_141129550(Unk_TreeIter* pIter)
{
    FUN_14112a580(pIter);
    return pIter;
}

// @0x141129570
void* FUN_141129570(Unk_TreeIter* pIter, Unk_TreeIter* pRet, int)
{
    Unk_TreeIter kOld = *pIter;
    FUN_1411295c0(pIter);
    *pRet = kOld;
    return pRet;
}

// @0x1411295c0
void* FUN_1411295c0(Unk_TreeIter* pIter)
{
    FUN_14112a610(pIter);
    return pIter;
}

// @0x1411295e0
void* FUN_1411295e0(Unk_TreeIter* pIter, Unk_TreeIter* pRet, int)
{
    Unk_TreeIter kOld = *pIter;
    FUN_141129630(pIter);
    *pRet = kOld;
    return pRet;
}

// @0x141129630
void* FUN_141129630(Unk_TreeIter* pIter)
{
    FUN_14112a6a0(pIter);
    return pIter;
}

// @0x141129650
void* FUN_141129650(Unk_TreeIter* pIter, Unk_TreeIter* pRet, int)
{
    Unk_TreeIter kOld = *pIter;
    FUN_1411296a0(pIter);
    *pRet = kOld;
    return pRet;
}

// @0x1411296a0
void* FUN_1411296a0(Unk_TreeIter* pIter)
{
    FUN_14112a730(pIter);
    return pIter;
}

// @0x1411296c0
void* FUN_1411296c0(Unk_TreeIter* pIter, Unk_TreeIter* pRet, int)
{
    Unk_TreeIter kOld = *pIter;
    FUN_141129710(pIter);
    *pRet = kOld;
    return pRet;
}

// @0x141129710
void* FUN_141129710(Unk_TreeIter* pIter)
{
    FUN_14112a7c0(pIter);
    return pIter;
}

// @0x141129730
void* FUN_141129730(Unk_TreeIter* pIter, Unk_TreeIter* pRet, int)
{
    Unk_TreeIter kOld = *pIter;
    FUN_141129780(pIter);
    *pRet = kOld;
    return pRet;
}

// @0x141129780
void* FUN_141129780(Unk_TreeIter* pIter)
{
    FUN_14112a850(pIter);
    return pIter;
}

// @0x1411297a0
void* FUN_1411297a0(Unk_TreeIter* pIter, Unk_TreeIter* pRet, int)
{
    Unk_TreeIter kOld = *pIter;
    FUN_1411297f0(pIter);
    *pRet = kOld;
    return pRet;
}

// @0x1411297f0
void* FUN_1411297f0(Unk_TreeIter* pIter)
{
    FUN_14112a8e0(pIter);
    return pIter;
}

// @0x141129810
void* FUN_141129810(Unk_TreeIter* pIter, Unk_TreeIter* pRet, int)
{
    Unk_TreeIter kOld = *pIter;
    FUN_1408853c0(pIter);
    *pRet = kOld;
    return pRet;
}

// @0x141129860
void* FUN_141129860(Unk_TreeIter* pIter, Unk_TreeIter* pRet, int)
{
    Unk_TreeIter kOld = *pIter;
    FUN_140965a60(pIter);
    *pRet = kOld;
    return pRet;
}

// @0x1411298b0
void* FUN_1411298b0(Unk_TreeIter* pIter, Unk_TreeIter* pRet, int)
{
    Unk_TreeIter kOld = *pIter;
    FUN_141129900(pIter);
    *pRet = kOld;
    return pRet;
}

// @0x141129900
void* FUN_141129900(Unk_TreeIter* pIter)
{
    FUN_14112a970(pIter);
    return pIter;
}

// @0x141129920
void* FUN_141129920(Unk_TreeIter* pIter, Unk_TreeIter* pRet, int)
{
    Unk_TreeIter kOld = *pIter;
    FUN_141129970(pIter);
    *pRet = kOld;
    return pRet;
}

// @0x141129970
void* FUN_141129970(Unk_TreeIter* pIter)
{
    FUN_14112aa00(pIter);
    return pIter;
}

// @0x141129990
void* FUN_141129990(Unk_TreeIter* pIter, Unk_TreeIter* pRet, int)
{
    Unk_TreeIter kOld = *pIter;
    FUN_1411299e0(pIter);
    *pRet = kOld;
    return pRet;
}

// @0x1411299e0
void* FUN_1411299e0(Unk_TreeIter* pIter)
{
    FUN_14112aa90(pIter);
    return pIter;
}

// @0x141129a00
void* FUN_141129a00(Unk_TreeIter* pIter)
{
    FUN_14063ef60(pIter);
    return pIter;
}

// @0x141129a20
void* FUN_141129a20(Unk_TreeIter* pIter)
{
    FUN_141128ec0(pIter);
    return pIter;
}

// @0x141129a40
void* FUN_141129a40(Unk_TreeIter* pIter)
{
    FUN_141128f30(pIter);
    return pIter;
}

// @0x141129a60
void* FUN_141129a60(Unk_TreeIter* pIter)
{
    FUN_141128fa0(pIter);
    return pIter;
}

// @0x141129a80
void* FUN_141129a80(Unk_TreeIter* pIter)
{
    FUN_141129010(pIter);
    return pIter;
}

// @0x141129aa0
void* FUN_141129aa0(Unk_TreeIter* pIter)
{
    FUN_141129080(pIter);
    return pIter;
}

// @0x141129ac0
void* FUN_141129ac0(Unk_TreeIter* pIter)
{
    FUN_1411290f0(pIter);
    return pIter;
}

// @0x141129ae0
void* FUN_141129ae0(Unk_TreeIter* pIter)
{
    FUN_141129160(pIter);
    return pIter;
}

// @0x141129b00
void* FUN_141129b00(Unk_TreeIter* pIter, Unk_TreeIter* pRet, int)
{
    Unk_TreeIter kOld = *pIter;
    FUN_141129b50(pIter);
    *pRet = kOld;
    return pRet;
}

// @0x141129b50
void* FUN_141129b50(Unk_TreeIter* pIter)
{
    FUN_1411291d0(pIter);
    return pIter;
}

// @0x141129b70
void* FUN_141129b70(Unk_TreeIter* pIter)
{
    FUN_141129240(pIter);
    return pIter;
}

// @0x141129b90
void* FUN_141129b90(Unk_TreeIter* pIter)
{
    FUN_1411292b0(pIter);
    return pIter;
}

// @0x141129bb0
void* FUN_141129bb0(Unk_TreeIter* pIter)
{
    FUN_141129390(pIter);
    return pIter;
}

// @0x141129bd0
void* FUN_141129bd0(Unk_TreeIter* pIter)
{
    FUN_141129470(pIter);
    return pIter;
}

// @0x141129bf0
void* FUN_141129bf0(Unk_TreeIter* pIter)
{
    FUN_1411294e0(pIter);
    return pIter;
}

// @0x141129c10
void* FUN_141129c10(Unk_TreeIter* pIter)
{
    FUN_141129550(pIter);
    return pIter;
}

// @0x141129c30
void* FUN_141129c30(Unk_TreeIter* pIter)
{
    FUN_1411295c0(pIter);
    return pIter;
}

// @0x141129c50
void* FUN_141129c50(Unk_TreeIter* pIter)
{
    FUN_141129630(pIter);
    return pIter;
}

// @0x141129c70
void* FUN_141129c70(Unk_TreeIter* pIter)
{
    FUN_1411296a0(pIter);
    return pIter;
}

// @0x141129c90
void* FUN_141129c90(Unk_TreeIter* pIter)
{
    FUN_141129710(pIter);
    return pIter;
}

// @0x141129cb0
void* FUN_141129cb0(Unk_TreeIter* pIter)
{
    FUN_141129780(pIter);
    return pIter;
}

// @0x141129cd0
void* FUN_141129cd0(Unk_TreeIter* pIter)
{
    FUN_1411297f0(pIter);
    return pIter;
}

// @0x141129cf0
void* FUN_141129cf0(Unk_TreeIter* pIter)
{
    FUN_140965a60(pIter);
    return pIter;
}

// @0x141129d10
void* FUN_141129d10(Unk_TreeIter* pIter)
{
    if (pIter->m_pNode->m_pRight->m_chIsNil != 0) {
        Unk_TreeNode* pNode;
        while ((pNode = pIter->m_pNode->m_pParent)->m_chIsNil == 0
                && pIter->m_pNode == pNode->m_pRight)
            pIter->m_pNode = pNode;
        pIter->m_pNode = pNode;
    } else {
        pIter->m_pNode = FUN_1411488c0(pIter->m_pNode->m_pRight);
    }
    return pIter;
}

// @0x141129da0
void* FUN_141129da0(Unk_TreeIter* pIter)
{
    if (pIter->m_pNode->m_pRight->m_chIsNil != 0) {
        Unk_TreeNode* pNode;
        while ((pNode = pIter->m_pNode->m_pParent)->m_chIsNil == 0
                && pIter->m_pNode == pNode->m_pRight)
            pIter->m_pNode = pNode;
        pIter->m_pNode = pNode;
    } else {
        pIter->m_pNode = FUN_1411488f0(pIter->m_pNode->m_pRight);
    }
    return pIter;
}

// @0x141129e30
void* FUN_141129e30(Unk_TreeIter* pIter)
{
    if (pIter->m_pNode->m_pRight->m_chIsNil != 0) {
        Unk_TreeNode* pNode;
        while ((pNode = pIter->m_pNode->m_pParent)->m_chIsNil == 0
                && pIter->m_pNode == pNode->m_pRight)
            pIter->m_pNode = pNode;
        pIter->m_pNode = pNode;
    } else {
        pIter->m_pNode = FUN_141148920(pIter->m_pNode->m_pRight);
    }
    return pIter;
}

// @0x141129ec0
void* FUN_141129ec0(Unk_TreeIter* pIter)
{
    if (pIter->m_pNode->m_pRight->m_chIsNil != 0) {
        Unk_TreeNode* pNode;
        while ((pNode = pIter->m_pNode->m_pParent)->m_chIsNil == 0
                && pIter->m_pNode == pNode->m_pRight)
            pIter->m_pNode = pNode;
        pIter->m_pNode = pNode;
    } else {
        pIter->m_pNode = FUN_141148950(pIter->m_pNode->m_pRight);
    }
    return pIter;
}

// @0x141129f50
void* FUN_141129f50(Unk_TreeIter* pIter)
{
    if (pIter->m_pNode->m_pRight->m_chIsNil != 0) {
        Unk_TreeNode* pNode;
        while ((pNode = pIter->m_pNode->m_pParent)->m_chIsNil == 0
                && pIter->m_pNode == pNode->m_pRight)
            pIter->m_pNode = pNode;
        pIter->m_pNode = pNode;
    } else {
        pIter->m_pNode = FUN_141148980(pIter->m_pNode->m_pRight);
    }
    return pIter;
}

// @0x141129fe0
void* FUN_141129fe0(Unk_TreeIter* pIter)
{
    if (pIter->m_pNode->m_pRight->m_chIsNil != 0) {
        Unk_TreeNode* pNode;
        while ((pNode = pIter->m_pNode->m_pParent)->m_chIsNil == 0
                && pIter->m_pNode == pNode->m_pRight)
            pIter->m_pNode = pNode;
        pIter->m_pNode = pNode;
    } else {
        pIter->m_pNode = FUN_1411489b0(pIter->m_pNode->m_pRight);
    }
    return pIter;
}

// @0x14112a070
void* FUN_14112a070(Unk_TreeIter* pIter)
{
    if (pIter->m_pNode->m_pRight->m_chIsNil != 0) {
        Unk_TreeNode* pNode;
        while ((pNode = pIter->m_pNode->m_pParent)->m_chIsNil == 0
                && pIter->m_pNode == pNode->m_pRight)
            pIter->m_pNode = pNode;
        pIter->m_pNode = pNode;
    } else {
        pIter->m_pNode = FUN_1411489e0(pIter->m_pNode->m_pRight);
    }
    return pIter;
}

// @0x14112a100
void* FUN_14112a100(Unk_TreeIter* pIter)
{
    if (pIter->m_pNode->m_pRight->m_chIsNil != 0) {
        Unk_TreeNode* pNode;
        while ((pNode = pIter->m_pNode->m_pParent)->m_chIsNil == 0
                && pIter->m_pNode == pNode->m_pRight)
            pIter->m_pNode = pNode;
        pIter->m_pNode = pNode;
    } else {
        pIter->m_pNode = FUN_141148a10(pIter->m_pNode->m_pRight);
    }
    return pIter;
}

// @0x14112a190
void* FUN_14112a190(Unk_TreeIter* pIter)
{
    if (pIter->m_pNode->m_pRight->m_chIsNil != 0) {
        Unk_TreeNode* pNode;
        while ((pNode = pIter->m_pNode->m_pParent)->m_chIsNil == 0
                && pIter->m_pNode == pNode->m_pRight)
            pIter->m_pNode = pNode;
        pIter->m_pNode = pNode;
    } else {
        pIter->m_pNode = FUN_141148a40(pIter->m_pNode->m_pRight);
    }
    return pIter;
}

// @0x14112a220
void* FUN_14112a220(Unk_TreeIter* pIter)
{
    if (pIter->m_pNode->m_pRight->m_chIsNil != 0) {
        Unk_TreeNode* pNode;
        while ((pNode = pIter->m_pNode->m_pParent)->m_chIsNil == 0
                && pIter->m_pNode == pNode->m_pRight)
            pIter->m_pNode = pNode;
        pIter->m_pNode = pNode;
    } else {
        pIter->m_pNode = FUN_141148a70(pIter->m_pNode->m_pRight);
    }
    return pIter;
}

// @0x14112a2b0
void* FUN_14112a2b0(Unk_TreeIter* pIter)
{
    if (pIter->m_pNode->m_pRight->m_chIsNil != 0) {
        Unk_TreeNode* pNode;
        while ((pNode = pIter->m_pNode->m_pParent)->m_chIsNil == 0
                && pIter->m_pNode == pNode->m_pRight)
            pIter->m_pNode = pNode;
        pIter->m_pNode = pNode;
    } else {
        pIter->m_pNode = FUN_141148aa0(pIter->m_pNode->m_pRight);
    }
    return pIter;
}

// @0x14112a340
void* FUN_14112a340(Unk_TreeIter* pIter)
{
    if (pIter->m_pNode->m_pRight->m_chIsNil != 0) {
        Unk_TreeNode* pNode;
        while ((pNode = pIter->m_pNode->m_pParent)->m_chIsNil == 0
                && pIter->m_pNode == pNode->m_pRight)
            pIter->m_pNode = pNode;
        pIter->m_pNode = pNode;
    } else {
        pIter->m_pNode = FUN_141148ad0(pIter->m_pNode->m_pRight);
    }
    return pIter;
}

// @0x14112a3d0
void* FUN_14112a3d0(Unk_TreeIter* pIter)
{
    if (pIter->m_pNode->m_pRight->m_chIsNil != 0) {
        Unk_TreeNode* pNode;
        while ((pNode = pIter->m_pNode->m_pParent)->m_chIsNil == 0
                && pIter->m_pNode == pNode->m_pRight)
            pIter->m_pNode = pNode;
        pIter->m_pNode = pNode;
    } else {
        pIter->m_pNode = FUN_141148b00(pIter->m_pNode->m_pRight);
    }
    return pIter;
}

// @0x14112a460
void* FUN_14112a460(Unk_TreeIter* pIter)
{
    if (pIter->m_pNode->m_pRight->m_chIsNil != 0) {
        Unk_TreeNode* pNode;
        while ((pNode = pIter->m_pNode->m_pParent)->m_chIsNil == 0
                && pIter->m_pNode == pNode->m_pRight)
            pIter->m_pNode = pNode;
        pIter->m_pNode = pNode;
    } else {
        pIter->m_pNode = FUN_141148b30(pIter->m_pNode->m_pRight);
    }
    return pIter;
}

// @0x14112a4f0
void* FUN_14112a4f0(Unk_TreeIter* pIter)
{
    if (pIter->m_pNode->m_pRight->m_chIsNil != 0) {
        Unk_TreeNode* pNode;
        while ((pNode = pIter->m_pNode->m_pParent)->m_chIsNil == 0
                && pIter->m_pNode == pNode->m_pRight)
            pIter->m_pNode = pNode;
        pIter->m_pNode = pNode;
    } else {
        pIter->m_pNode = FUN_141148b60(pIter->m_pNode->m_pRight);
    }
    return pIter;
}

// @0x14112a580
void* FUN_14112a580(Unk_TreeIter* pIter)
{
    if (pIter->m_pNode->m_pRight->m_chIsNil != 0) {
        Unk_TreeNode* pNode;
        while ((pNode = pIter->m_pNode->m_pParent)->m_chIsNil == 0
                && pIter->m_pNode == pNode->m_pRight)
            pIter->m_pNode = pNode;
        pIter->m_pNode = pNode;
    } else {
        pIter->m_pNode = FUN_141148b90(pIter->m_pNode->m_pRight);
    }
    return pIter;
}

// @0x14112a610
void* FUN_14112a610(Unk_TreeIter* pIter)
{
    if (pIter->m_pNode->m_pRight->m_chIsNil != 0) {
        Unk_TreeNode* pNode;
        while ((pNode = pIter->m_pNode->m_pParent)->m_chIsNil == 0
                && pIter->m_pNode == pNode->m_pRight)
            pIter->m_pNode = pNode;
        pIter->m_pNode = pNode;
    } else {
        pIter->m_pNode = FUN_141148bc0(pIter->m_pNode->m_pRight);
    }
    return pIter;
}

// @0x14112a6a0
void* FUN_14112a6a0(Unk_TreeIter* pIter)
{
    if (pIter->m_pNode->m_pRight->m_chIsNil != 0) {
        Unk_TreeNode* pNode;
        while ((pNode = pIter->m_pNode->m_pParent)->m_chIsNil == 0
                && pIter->m_pNode == pNode->m_pRight)
            pIter->m_pNode = pNode;
        pIter->m_pNode = pNode;
    } else {
        pIter->m_pNode = FUN_141148bf0(pIter->m_pNode->m_pRight);
    }
    return pIter;
}

// @0x14112a730
void* FUN_14112a730(Unk_TreeIter* pIter)
{
    if (pIter->m_pNode->m_pRight->m_chIsNil != 0) {
        Unk_TreeNode* pNode;
        while ((pNode = pIter->m_pNode->m_pParent)->m_chIsNil == 0
                && pIter->m_pNode == pNode->m_pRight)
            pIter->m_pNode = pNode;
        pIter->m_pNode = pNode;
    } else {
        pIter->m_pNode = FUN_141148c20(pIter->m_pNode->m_pRight);
    }
    return pIter;
}

// @0x14112a7c0
void* FUN_14112a7c0(Unk_TreeIter* pIter)
{
    if (pIter->m_pNode->m_pRight->m_chIsNil != 0) {
        Unk_TreeNode* pNode;
        while ((pNode = pIter->m_pNode->m_pParent)->m_chIsNil == 0
                && pIter->m_pNode == pNode->m_pRight)
            pIter->m_pNode = pNode;
        pIter->m_pNode = pNode;
    } else {
        pIter->m_pNode = FUN_141148c50(pIter->m_pNode->m_pRight);
    }
    return pIter;
}

// @0x14112a850
void* FUN_14112a850(Unk_TreeIter* pIter)
{
    if (pIter->m_pNode->m_pRight->m_chIsNil != 0) {
        Unk_TreeNode* pNode;
        while ((pNode = pIter->m_pNode->m_pParent)->m_chIsNil == 0
                && pIter->m_pNode == pNode->m_pRight)
            pIter->m_pNode = pNode;
        pIter->m_pNode = pNode;
    } else {
        pIter->m_pNode = FUN_141148c80(pIter->m_pNode->m_pRight);
    }
    return pIter;
}

// @0x14112a8e0
void* FUN_14112a8e0(Unk_TreeIter* pIter)
{
    if (pIter->m_pNode->m_pRight->m_chIsNil != 0) {
        Unk_TreeNode* pNode;
        while ((pNode = pIter->m_pNode->m_pParent)->m_chIsNil == 0
                && pIter->m_pNode == pNode->m_pRight)
            pIter->m_pNode = pNode;
        pIter->m_pNode = pNode;
    } else {
        pIter->m_pNode = FUN_141148cb0(pIter->m_pNode->m_pRight);
    }
    return pIter;
}

// @0x14112a970
void* FUN_14112a970(Unk_TreeIter* pIter)
{
    if (pIter->m_pNode->m_pRight->m_chIsNil != 0) {
        Unk_TreeNode* pNode;
        while ((pNode = pIter->m_pNode->m_pParent)->m_chIsNil == 0
                && pIter->m_pNode == pNode->m_pRight)
            pIter->m_pNode = pNode;
        pIter->m_pNode = pNode;
    } else {
        pIter->m_pNode = FUN_141148ce0(pIter->m_pNode->m_pRight);
    }
    return pIter;
}

// @0x14112aa00
void* FUN_14112aa00(Unk_TreeIter* pIter)
{
    if (pIter->m_pNode->m_pRight->m_chIsNil != 0) {
        Unk_TreeNode* pNode;
        while ((pNode = pIter->m_pNode->m_pParent)->m_chIsNil == 0
                && pIter->m_pNode == pNode->m_pRight)
            pIter->m_pNode = pNode;
        pIter->m_pNode = pNode;
    } else {
        pIter->m_pNode = FUN_141148d10(pIter->m_pNode->m_pRight);
    }
    return pIter;
}

// @0x14112aa90
void* FUN_14112aa90(Unk_TreeIter* pIter)
{
    if (pIter->m_pNode->m_pRight->m_chIsNil != 0) {
        Unk_TreeNode* pNode;
        while ((pNode = pIter->m_pNode->m_pParent)->m_chIsNil == 0
                && pIter->m_pNode == pNode->m_pRight)
            pIter->m_pNode = pNode;
        pIter->m_pNode = pNode;
    } else {
        pIter->m_pNode = FUN_141148d40(pIter->m_pNode->m_pRight);
    }
    return pIter;
}

// @0x14112ab20
void* FUN_14112ab20(Unk_ListNode** pIter)
{
    *pIter = *pIter + 1;
    return pIter;
}

// @0x14112ab40
void* FUN_14112ab40(Unk_ListNode** pIter)
{
    *pIter = *pIter + 1;
    return pIter;
}
