// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Template zone of the boxed-pointer TU, part 1: the
// uninitialized copy / move machinery of the std::vector<T> instantiations of unit_1415d3570 (std::_Idl_distance(1),
// std::_Ptr_copy_cat / _Ptr_move_cat, std::_Seek_wrapped, std::_Uninitialized_copy / _Uninitialized_move and their
// _al_unchecked workers, vector::_Ucopy / _Umove, _Unfancy), a std::map _Insert_at / _Insert_nohint / _Lbound and
// std::string find_first_not_of / find_first_of. Element types are Unk_StlElem<sizeof(T)> (ms2/unnamed/unk_stlglue.h).
// MS2-UNIT: unit_1415dad30
// MS2-RANGE: 0x1415dad30-0x1415e1550 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include <type_traits>
#include <iterator>
#include <set>
#include <string>
#include "ms2/unnamed/unk_stlglue.h"

// Callees in other units (unwrap helpers, accessors, backout members, memmove copy).
extern Unk_StlElem<0x10>* FUN_1415d26a0(Unk_StlElem<0x10>* pFirst, Unk_StlElem<0x10>* pLast, Unk_StlElem<0x10>* pDest);
extern Unk_StlElem<0x18>* FUN_1415d2710(Unk_StlElem<0x18>* pFirst, Unk_StlElem<0x18>* pLast, Unk_StlElem<0x18>* pDest);
extern void FUN_1415d4850(Unk_StlBackout<Unk_StlElem<0x58>>* pThis, Unk_StlElem<0x58>* pVal);
extern void FUN_1415d48b0(Unk_StlBackout<Unk_StlElem<0x30>>* pThis, Unk_StlElem<0x30>* pVal);
extern void FUN_1415d4910(Unk_StlBackout<Unk_StlElem<0x98>>* pThis, Unk_StlElem<0x98>* pVal);
extern void FUN_1415d4980(Unk_StlBackout<Unk_StlElem<0x220>>* pThis, Unk_StlElem<0x220>* pVal);
extern void FUN_1415d49f0(Unk_StlBackout<Unk_StlElem<0x128>>* pThis, Unk_StlElem<0x128>* pVal);
extern void FUN_1415d4a60(Unk_StlBackout<Unk_StlElem<0x118>>* pThis, Unk_StlElem<0x118>* pVal);
extern void FUN_1415d4ad0(Unk_StlBackout<Unk_StlElem<0x580>>* pThis, Unk_StlElem<0x580>* pVal);
extern void FUN_1415d4b40(Unk_StlBackout<Unk_StlElem<0x18>>* pThis, Unk_StlElem<0x18>* pVal);
extern void FUN_1415d4ba0(Unk_StlBackout<Unk_StlElem<0x14a8>>* pThis, Unk_StlElem<0x14a8>* pVal);
extern void FUN_1415d4c10(Unk_StlBackout<Unk_StlElem<0x18>>* pThis, Unk_StlElem<0x18>* pVal);
extern void FUN_1415d4c70(Unk_StlBackout<Unk_StlElem<0x190>>* pThis, Unk_StlElem<0x190>* pVal);
extern void FUN_1415d4ce0(Unk_StlBackout<Unk_StlElem<0xb8>>* pThis, Unk_StlElem<0xb8>* pVal);
extern void FUN_1415d4d50(Unk_StlBackout<Unk_StlElem<0x58>>* pThis, Unk_StlElem<0x58>* pVal);
extern void FUN_1415d4db0(Unk_StlBackout<Unk_StlElem<0xae8>>* pThis, Unk_StlElem<0xae8>* pVal);
extern void FUN_1415d4e20(Unk_StlBackout<Unk_StlElem<0xec8>>* pThis, Unk_StlElem<0xec8>* pVal);
extern void FUN_1415d4e90(Unk_StlBackout<Unk_StlElem<0xc8>>* pThis, Unk_StlElem<0xc8>* pVal);
extern void FUN_1415d4f00(Unk_StlBackout<Unk_StlElem<0xf8>>* pThis, Unk_StlElem<0xf8>* pVal);
extern void FUN_1415d4f70(Unk_StlBackout<Unk_StlElem<0x490>>* pThis, Unk_StlElem<0x490>* pVal);
extern void FUN_1415d4fe0(Unk_StlBackout<Unk_StlElem<0x20>>* pThis, Unk_StlElem<0x20>* pVal);
extern void FUN_1415d5040(Unk_StlBackout<Unk_StlElem<0x30>>* pThis, Unk_StlElem<0x30>* pVal);
extern void FUN_1415d50b0(Unk_StlBackout<Unk_StlElem<0x58>>* pThis, Unk_StlElem<0x58>* pVal);
extern void FUN_1415d5110(Unk_StlBackout<Unk_StlElem<0x30>>* pThis, Unk_StlElem<0x30>* pVal);
extern void FUN_1415d5170(Unk_StlBackout<Unk_StlElem<0x98>>* pThis, Unk_StlElem<0x98>* pVal);
extern void FUN_1415d51e0(Unk_StlBackout<Unk_StlElem<0x220>>* pThis, Unk_StlElem<0x220>* pVal);
extern void FUN_1415d5250(Unk_StlBackout<Unk_StlElem<0x128>>* pThis, Unk_StlElem<0x128>* pVal);
extern void FUN_1415d52c0(Unk_StlBackout<Unk_StlElem<0x118>>* pThis, Unk_StlElem<0x118>* pVal);
extern void FUN_1415d5330(Unk_StlBackout<Unk_StlElem<0xe0>>* pThis, Unk_StlElem<0xe0>* pVal);
extern void FUN_1415d53a0(Unk_StlBackout<Unk_StlElem<0x580>>* pThis, Unk_StlElem<0x580>* pVal);
extern void FUN_1415d5410(Unk_StlBackout<Unk_StlElem<0x18>>* pThis, Unk_StlElem<0x18>* pVal);
extern void FUN_1415d5470(Unk_StlBackout<Unk_StlElem<0x14a8>>* pThis, Unk_StlElem<0x14a8>* pVal);
extern void FUN_1415d54e0(Unk_StlBackout<Unk_StlElem<0x18>>* pThis, Unk_StlElem<0x18>* pVal);
extern void FUN_1415d5540(Unk_StlBackout<Unk_StlElem<0x190>>* pThis, Unk_StlElem<0x190>* pVal);
extern void FUN_1415d55b0(Unk_StlBackout<Unk_StlElem<0xb8>>* pThis, Unk_StlElem<0xb8>* pVal);
extern void FUN_1415d5620(Unk_StlBackout<Unk_StlElem<0x58>>* pThis, Unk_StlElem<0x58>* pVal);
extern void FUN_1415d5680(Unk_StlBackout<Unk_StlElem<0x68>>* pThis, Unk_StlElem<0x68>* pVal);
extern void FUN_1415d56e0(Unk_StlBackout<Unk_StlElem<0xae8>>* pThis, Unk_StlElem<0xae8>* pVal);
extern void FUN_1415d5750(Unk_StlBackout<Unk_StlElem<0xec8>>* pThis, Unk_StlElem<0xec8>* pVal);
extern void FUN_1415d57c0(Unk_StlBackout<Unk_StlElem<0xc8>>* pThis, Unk_StlElem<0xc8>* pVal);
extern void FUN_1415d5830(Unk_StlBackout<Unk_StlElem<0xf8>>* pThis, Unk_StlElem<0xf8>* pVal);
extern void FUN_1415d58a0(Unk_StlBackout<Unk_StlElem<0x490>>* pThis, Unk_StlElem<0x490>* pVal);
extern void FUN_1415d5910(Unk_StlBackout<Unk_StlElem<0x20>>* pThis, Unk_StlElem<0x20>* pVal);
extern Unk_StlElem<0x30>* FUN_1415da9e0(Unk_StlElem<0x30>* p);
extern Unk_StlElem<0x10>* FUN_1415da9f0(Unk_StlElem<0x10>* p);
extern Unk_StlElem<0x18>* FUN_1415daa00(Unk_StlElem<0x18>* p);
extern Unk_StlElem<0x58>* FUN_1415daa70(Unk_StlElem<0x58>* p);
extern Unk_StlElem<0x30>* FUN_1415daa80(Unk_StlElem<0x30>* p);
extern Unk_StlElem<0x98>* FUN_1415daa90(Unk_StlElem<0x98>* p);
extern Unk_StlElem<0x220>* FUN_1415daaa0(Unk_StlElem<0x220>* p);
extern Unk_StlElem<0x128>* FUN_1415daab0(Unk_StlElem<0x128>* p);
extern Unk_StlElem<0x118>* FUN_1415daac0(Unk_StlElem<0x118>* p);
extern Unk_StlElem<0xe0>* FUN_1415daad0(Unk_StlElem<0xe0>* p);
extern Unk_StlElem<0x580>* FUN_1415daae0(Unk_StlElem<0x580>* p);
extern Unk_StlElem<0x18>* FUN_1415daaf0(Unk_StlElem<0x18>* p);
extern Unk_StlElem<0x14a8>* FUN_1415dab00(Unk_StlElem<0x14a8>* p);
extern Unk_StlElem<0x18>* FUN_1415dab10(Unk_StlElem<0x18>* p);
extern Unk_StlElem<0x190>* FUN_1415dab20(Unk_StlElem<0x190>* p);
extern Unk_StlElem<0xb8>* FUN_1415dab30(Unk_StlElem<0xb8>* p);
extern Unk_StlElem<0x58>* FUN_1415dab40(Unk_StlElem<0x58>* p);
extern Unk_StlElem<0x68>* FUN_1415dab50(Unk_StlElem<0x68>* p);
extern Unk_StlElem<0xae8>* FUN_1415dab60(Unk_StlElem<0xae8>* p);
extern Unk_StlElem<0xec8>* FUN_1415dab70(Unk_StlElem<0xec8>* p);
extern Unk_StlElem<0xc8>* FUN_1415dab80(Unk_StlElem<0xc8>* p);
extern Unk_StlElem<0xf8>* FUN_1415dab90(Unk_StlElem<0xf8>* p);
extern Unk_StlElem<0x490>* FUN_1415daba0(Unk_StlElem<0x490>* p);
extern Unk_StlElem<0x20>* FUN_1415dabb0(Unk_StlElem<0x20>* p);
extern Unk_StlElem<0x10>* FUN_1415dabc0(Unk_StlElem<0x10>* p, ptrdiff_t n);
extern Unk_StlElem<0x18>* FUN_1415dabd0(Unk_StlElem<0x18>* p, ptrdiff_t n);
extern Unk_StlElem<0x58>* FUN_1415dabe0(Unk_StlElem<0x58>* p, ptrdiff_t n);
extern Unk_StlElem<0x30>* FUN_1415dabf0(Unk_StlElem<0x30>* p, ptrdiff_t n);
extern Unk_StlElem<0x98>* FUN_1415dac00(Unk_StlElem<0x98>* p, ptrdiff_t n);
extern Unk_StlElem<0x220>* FUN_1415dac10(Unk_StlElem<0x220>* p, ptrdiff_t n);
extern Unk_StlElem<0x128>* FUN_1415dac20(Unk_StlElem<0x128>* p, ptrdiff_t n);
extern Unk_StlElem<0x118>* FUN_1415dac30(Unk_StlElem<0x118>* p, ptrdiff_t n);
extern Unk_StlElem<0xe0>* FUN_1415dac40(Unk_StlElem<0xe0>* p, ptrdiff_t n);
extern Unk_StlElem<0x580>* FUN_1415dac50(Unk_StlElem<0x580>* p, ptrdiff_t n);
extern Unk_StlElem<0x18>* FUN_1415dac60(Unk_StlElem<0x18>* p, ptrdiff_t n);
extern Unk_StlElem<0x14a8>* FUN_1415dac70(Unk_StlElem<0x14a8>* p, ptrdiff_t n);
extern Unk_StlElem<0x18>* FUN_1415dac80(Unk_StlElem<0x18>* p, ptrdiff_t n);
extern Unk_StlElem<0x190>* FUN_1415dac90(Unk_StlElem<0x190>* p, ptrdiff_t n);
extern void* FUN_1415daca0(void* p, ptrdiff_t n);
extern Unk_StlElem<0x58>* FUN_1415dacb0(Unk_StlElem<0x58>* p, ptrdiff_t n);
extern Unk_StlElem<0x68>* FUN_1415dacc0(Unk_StlElem<0x68>* p, ptrdiff_t n);
extern Unk_StlElem<0xae8>* FUN_1415dacd0(Unk_StlElem<0xae8>* p, ptrdiff_t n);
extern Unk_StlElem<0xec8>* FUN_1415dace0(Unk_StlElem<0xec8>* p, ptrdiff_t n);
extern Unk_StlElem<0xc8>* FUN_1415dacf0(Unk_StlElem<0xc8>* p, ptrdiff_t n);
extern Unk_StlElem<0xf8>* FUN_1415dad00(Unk_StlElem<0xf8>* p, ptrdiff_t n);
extern Unk_StlElem<0x490>* FUN_1415dad10(Unk_StlElem<0x490>* p, ptrdiff_t n);
extern Unk_StlElem<0x20>* FUN_1415dad20(Unk_StlElem<0x20>* p, ptrdiff_t n);
extern Unk_StlElem<0x58>* FUN_1415e51e0(Unk_StlElem<0x58>* p);
extern Unk_StlElem<0x30>* FUN_1415e51f0(Unk_StlElem<0x30>* p);
extern Unk_StlElem<0x98>* FUN_1415e5200(Unk_StlElem<0x98>* p);
extern Unk_StlElem<0x220>* FUN_1415e5210(Unk_StlElem<0x220>* p);
extern Unk_StlElem<0x128>* FUN_1415e5220(Unk_StlElem<0x128>* p);
extern Unk_StlElem<0x118>* FUN_1415e5230(Unk_StlElem<0x118>* p);
extern Unk_StlElem<0xe0>* FUN_1415e5240(Unk_StlElem<0xe0>* p);
extern Unk_StlElem<0x580>* FUN_1415e5250(Unk_StlElem<0x580>* p);
extern Unk_StlElem<0x18>* FUN_1415e5260(Unk_StlElem<0x18>* p);
extern Unk_StlElem<0x14a8>* FUN_1415e5270(Unk_StlElem<0x14a8>* p);
extern Unk_StlElem<0x18>* FUN_1415e5280(Unk_StlElem<0x18>* p);
extern Unk_StlElem<0x190>* FUN_1415e5290(Unk_StlElem<0x190>* p);
extern Unk_StlElem<0xb8>* FUN_1415e52a0(Unk_StlElem<0xb8>* p);
extern Unk_StlElem<0x58>* FUN_1415e52b0(Unk_StlElem<0x58>* p);
extern Unk_StlElem<0x68>* FUN_1415e52c0(Unk_StlElem<0x68>* p);
extern Unk_StlElem<0xae8>* FUN_1415e52d0(Unk_StlElem<0xae8>* p);
extern Unk_StlElem<0xec8>* FUN_1415e52e0(Unk_StlElem<0xec8>* p);
extern Unk_StlElem<0xc8>* FUN_1415e52f0(Unk_StlElem<0xc8>* p);
extern Unk_StlElem<0xf8>* FUN_1415e5300(Unk_StlElem<0xf8>* p);
extern Unk_StlElem<0x490>* FUN_1415e5310(Unk_StlElem<0x490>* p);
extern Unk_StlElem<0x20>* FUN_1415e5320(Unk_StlElem<0x20>* p);
extern void* FUN_141601ad0(void* pThis);
extern void* FUN_141601b10(void* pThis);
extern void* FUN_141601b50(void* pThis);
extern void* FUN_141601b90(void* pThis);
extern void* FUN_141601bd0(void* pThis);
extern void* FUN_141601c10(void* pThis);
extern void* FUN_141601c50(void* pThis);
extern void* FUN_141601c90(void* pThis);
extern void* FUN_141601d10(void* pThis);
extern void* FUN_141601d50(void* pThis);
extern void* FUN_141601d90(void* pThis);
extern void* FUN_141601dd0(void* pThis);
extern void* FUN_141601e10(void* pThis);
extern void* FUN_141601e50(void* pThis);
extern void* FUN_141601e90(void* pThis);
extern void* FUN_141601f10(void* pThis);
extern void* FUN_141601f50(void* pThis);
extern void* FUN_141601f90(void* pThis);
extern void* FUN_141601fd0(void* pThis);
extern void* FUN_141602010(void* pThis);
extern void* FUN_141602050(void* pThis);
extern Unk_StlElem<0x58>* FUN_141604390(Unk_StlBackout<Unk_StlElem<0x58>>* pThis);
extern Unk_StlElem<0x30>* FUN_1416043b0(Unk_StlBackout<Unk_StlElem<0x30>>* pThis);
extern Unk_StlElem<0x98>* FUN_1416043d0(Unk_StlBackout<Unk_StlElem<0x98>>* pThis);
extern Unk_StlElem<0x220>* FUN_1416043f0(Unk_StlBackout<Unk_StlElem<0x220>>* pThis);
extern Unk_StlElem<0x128>* FUN_141604410(Unk_StlBackout<Unk_StlElem<0x128>>* pThis);
extern Unk_StlElem<0x118>* FUN_141604430(Unk_StlBackout<Unk_StlElem<0x118>>* pThis);
extern Unk_StlElem<0xe0>* FUN_141604450(Unk_StlBackout<Unk_StlElem<0xe0>>* pThis);
extern Unk_StlElem<0x580>* FUN_141604470(Unk_StlBackout<Unk_StlElem<0x580>>* pThis);
extern Unk_StlElem<0x18>* FUN_141604490(Unk_StlBackout<Unk_StlElem<0x18>>* pThis);
extern Unk_StlElem<0x14a8>* FUN_1416044b0(Unk_StlBackout<Unk_StlElem<0x14a8>>* pThis);
extern Unk_StlElem<0x18>* FUN_1416044d0(Unk_StlBackout<Unk_StlElem<0x18>>* pThis);
extern Unk_StlElem<0x190>* FUN_1416044f0(Unk_StlBackout<Unk_StlElem<0x190>>* pThis);
extern void* FUN_141604510(void* pThis);
extern Unk_StlElem<0x58>* FUN_141604530(Unk_StlBackout<Unk_StlElem<0x58>>* pThis);
extern Unk_StlElem<0x68>* FUN_141604550(Unk_StlBackout<Unk_StlElem<0x68>>* pThis);
extern Unk_StlElem<0xae8>* FUN_141604570(Unk_StlBackout<Unk_StlElem<0xae8>>* pThis);
extern Unk_StlElem<0xec8>* FUN_141604590(Unk_StlBackout<Unk_StlElem<0xec8>>* pThis);
extern Unk_StlElem<0xc8>* FUN_1416045b0(Unk_StlBackout<Unk_StlElem<0xc8>>* pThis);
extern Unk_StlElem<0xf8>* FUN_1416045d0(Unk_StlBackout<Unk_StlElem<0xf8>>* pThis);
extern Unk_StlElem<0x490>* FUN_1416045f0(Unk_StlBackout<Unk_StlElem<0x490>>* pThis);
extern Unk_StlElem<0x20>* FUN_141604610(Unk_StlBackout<Unk_StlElem<0x20>>* pThis);

// The std::set<unsigned char> (key compare std::less<unsigned char>) of _Insert_at / _Insert_nohint and the tree of
// _Lbound. Node layout is std::_Tree_node; the tree members are free functions taking the tree first, and the iterator /
// pair results are returned through an explicit result pointer (the exe's member sret ABI: this rcx, result rdx).
typedef std::_Tree_node<unsigned char, void*> Unk_TreeNode;

// std::_Tree_val: the head node and the element count
struct Unk_TreeData
{
    Unk_TreeNode* m_pHead;
    size_t m_nSize;
};

// std::_Tree_iterator (only the node pointer)
struct Unk_TreeIter
{
    Unk_TreeNode* m_pNode;
};

// std::pair<iterator, bool>
struct Unk_TreePairib
{
    Unk_TreeIter m_it;
    bool m_bInserted;
};

enum Unk_TreeColor
{
    Unk_TreeRed,
    Unk_TreeBlack,
};

extern Unk_TreeData* FUN_141600e10(void* pThis);                                 // _Get_data
extern Unk_TreeNode*& FUN_141600e40(void* pThis);                                // _Myhead (the _Lbound tree)
extern size_t FUN_14160a970(void* pThis);                                        // max_size
extern void FUN_141600710(void* pThis, Unk_TreeNode* pNode);                     // _Destroy_if_node
extern const unsigned char* FUN_1415e4bd0(const unsigned char* pVal);            // std::forward
extern Unk_TreeNode* FUN_1415d25c0(void* pThis, Unk_TreeNode* pNode, const unsigned char* pVal);   // _Buy_if_not_node
extern Unk_TreeNode*& FUN_141604650(Unk_TreeData* pData);                        // _Root
extern Unk_TreeNode*& FUN_141602850(Unk_TreeData* pData);                        // _Lmost
extern Unk_TreeNode*& FUN_141604630(Unk_TreeData* pData);                        // _Rmost
extern void FUN_141602860(Unk_TreeData* pData, Unk_TreeNode* pNode);             // _Lrotate
extern void FUN_141604670(Unk_TreeData* pData, Unk_TreeNode* pNode);             // _Rrotate
extern const void* FUN_1415e1750(Unk_TreeData* pData);                           // std::addressof
extern void FUN_1415e5cf0(Unk_TreeIter* pThis, Unk_TreeNode* pNode, const void* pData);   // iterator(node, data)
extern const std::less<unsigned char>& FUN_141602090(void* pThis);               // _Getcomp
extern const unsigned char& FUN_141602800(void* pThis, Unk_TreeNode* pNode);     // _Key
extern const unsigned char& FUN_141602830(void* pThis, const unsigned char* pVal);   // _Kfn
extern Unk_TreeIter* FUN_141607780(void* pThis, Unk_TreeIter* pResult);          // begin
extern bool FUN_1415f2a60(const Unk_TreeIter* pThis, const Unk_TreeIter* pOther);   // iterator ==
extern Unk_TreeIter* FUN_1415f46a0(Unk_TreeIter* pThis);                         // iterator --
extern void FUN_1415ce4c0(Unk_TreePairib* pThis, Unk_TreeIter* pIt, bool* pInserted);   // pair(iterator&&, bool&&)
extern void FUN_1415ce380(Unk_TreePairib* pThis, Unk_TreeIter* pIt, bool* pInserted);   // pair(iterator&, bool&&)
extern bool FUN_1415ffc30(void* pThis, const unsigned char& key, const unsigned char& keyVal);   // _Lbound compare
extern void FUN_141604750(void* pIt, void* pUnwrapped);                          // iterator _Seek_to

// this unit, in exe order
ptrdiff_t FUN_1415dad30(Unk_StlElem<0x10>* const& pFirst, Unk_StlElem<0x10>* const& pLast, std::random_access_iterator_tag);
ptrdiff_t FUN_1415dad60(Unk_StlElem<0x18>* const& pFirst, Unk_StlElem<0x18>* const& pLast, std::random_access_iterator_tag);
ptrdiff_t FUN_1415dad90(Unk_StlElem<0x58>* const& pFirst, Unk_StlElem<0x58>* const& pLast, std::random_access_iterator_tag);
ptrdiff_t FUN_1415dadc0(Unk_StlElem<0x30>* const& pFirst, Unk_StlElem<0x30>* const& pLast, std::random_access_iterator_tag);
ptrdiff_t FUN_1415dadf0(Unk_StlElem<0x98>* const& pFirst, Unk_StlElem<0x98>* const& pLast, std::random_access_iterator_tag);
ptrdiff_t FUN_1415dae20(Unk_StlElem<0x220>* const& pFirst, Unk_StlElem<0x220>* const& pLast, std::random_access_iterator_tag);
ptrdiff_t FUN_1415dae50(Unk_StlElem<0x128>* const& pFirst, Unk_StlElem<0x128>* const& pLast, std::random_access_iterator_tag);
ptrdiff_t FUN_1415dae80(Unk_StlElem<0x118>* const& pFirst, Unk_StlElem<0x118>* const& pLast, std::random_access_iterator_tag);
ptrdiff_t FUN_1415daeb0(Unk_StlElem<0xe0>* const& pFirst, Unk_StlElem<0xe0>* const& pLast, std::random_access_iterator_tag);
ptrdiff_t FUN_1415daee0(Unk_StlElem<0x580>* const& pFirst, Unk_StlElem<0x580>* const& pLast, std::random_access_iterator_tag);
ptrdiff_t FUN_1415daf10(Unk_StlElem<0x18>* const& pFirst, Unk_StlElem<0x18>* const& pLast, std::random_access_iterator_tag);
ptrdiff_t FUN_1415daf40(Unk_StlElem<0x14a8>* const& pFirst, Unk_StlElem<0x14a8>* const& pLast, std::random_access_iterator_tag);
ptrdiff_t FUN_1415daf70(Unk_StlElem<0x18>* const& pFirst, Unk_StlElem<0x18>* const& pLast, std::random_access_iterator_tag);
ptrdiff_t FUN_1415dafa0(Unk_StlElem<0x190>* const& pFirst, Unk_StlElem<0x190>* const& pLast, std::random_access_iterator_tag);
ptrdiff_t FUN_1415dafd0(Unk_StlElem<0xb8>* const& pFirst, Unk_StlElem<0xb8>* const& pLast, std::random_access_iterator_tag);
ptrdiff_t FUN_1415db000(Unk_StlElem<0x58>* const& pFirst, Unk_StlElem<0x58>* const& pLast, std::random_access_iterator_tag);
ptrdiff_t FUN_1415db030(Unk_StlElem<0x68>* const& pFirst, Unk_StlElem<0x68>* const& pLast, std::random_access_iterator_tag);
ptrdiff_t FUN_1415db060(Unk_StlElem<0xae8>* const& pFirst, Unk_StlElem<0xae8>* const& pLast, std::random_access_iterator_tag);
ptrdiff_t FUN_1415db090(Unk_StlElem<0xec8>* const& pFirst, Unk_StlElem<0xec8>* const& pLast, std::random_access_iterator_tag);
ptrdiff_t FUN_1415db0c0(Unk_StlElem<0xc8>* const& pFirst, Unk_StlElem<0xc8>* const& pLast, std::random_access_iterator_tag);
ptrdiff_t FUN_1415db0f0(Unk_StlElem<0xf8>* const& pFirst, Unk_StlElem<0xf8>* const& pLast, std::random_access_iterator_tag);
ptrdiff_t FUN_1415db120(Unk_StlElem<0x490>* const& pFirst, Unk_StlElem<0x490>* const& pLast, std::random_access_iterator_tag);
ptrdiff_t FUN_1415db150(Unk_StlElem<0x20>* const& pFirst, Unk_StlElem<0x20>* const& pLast, std::random_access_iterator_tag);
ptrdiff_t FUN_1415db180(Unk_StlElem<0x30>* const& pFirst, Unk_StlElem<0x30>* const& pLast, std::random_access_iterator_tag);
ptrdiff_t FUN_1415db1b0(Unk_StlElem<0x10>* const& pFirst, Unk_StlElem<0x10>* const& pLast);
ptrdiff_t FUN_1415db1e0(Unk_StlElem<0x18>* const& pFirst, Unk_StlElem<0x18>* const& pLast);
ptrdiff_t FUN_1415db210(Unk_StlElem<0x58>* const& pFirst, Unk_StlElem<0x58>* const& pLast);
ptrdiff_t FUN_1415db240(Unk_StlElem<0x30>* const& pFirst, Unk_StlElem<0x30>* const& pLast);
ptrdiff_t FUN_1415db270(Unk_StlElem<0x98>* const& pFirst, Unk_StlElem<0x98>* const& pLast);
ptrdiff_t FUN_1415db2a0(Unk_StlElem<0x220>* const& pFirst, Unk_StlElem<0x220>* const& pLast);
ptrdiff_t FUN_1415db2d0(Unk_StlElem<0x128>* const& pFirst, Unk_StlElem<0x128>* const& pLast);
ptrdiff_t FUN_1415db300(Unk_StlElem<0x118>* const& pFirst, Unk_StlElem<0x118>* const& pLast);
ptrdiff_t FUN_1415db330(Unk_StlElem<0xe0>* const& pFirst, Unk_StlElem<0xe0>* const& pLast);
ptrdiff_t FUN_1415db360(Unk_StlElem<0x580>* const& pFirst, Unk_StlElem<0x580>* const& pLast);
ptrdiff_t FUN_1415db390(Unk_StlElem<0x18>* const& pFirst, Unk_StlElem<0x18>* const& pLast);
ptrdiff_t FUN_1415db3c0(Unk_StlElem<0x14a8>* const& pFirst, Unk_StlElem<0x14a8>* const& pLast);
ptrdiff_t FUN_1415db3f0(Unk_StlElem<0x18>* const& pFirst, Unk_StlElem<0x18>* const& pLast);
ptrdiff_t FUN_1415db420(Unk_StlElem<0x190>* const& pFirst, Unk_StlElem<0x190>* const& pLast);
ptrdiff_t FUN_1415db450(Unk_StlElem<0xb8>* const& pFirst, Unk_StlElem<0xb8>* const& pLast);
ptrdiff_t FUN_1415db480(Unk_StlElem<0x58>* const& pFirst, Unk_StlElem<0x58>* const& pLast);
ptrdiff_t FUN_1415db4b0(Unk_StlElem<0x68>* const& pFirst, Unk_StlElem<0x68>* const& pLast);
ptrdiff_t FUN_1415db4e0(Unk_StlElem<0xae8>* const& pFirst, Unk_StlElem<0xae8>* const& pLast);
ptrdiff_t FUN_1415db510(Unk_StlElem<0xec8>* const& pFirst, Unk_StlElem<0xec8>* const& pLast);
ptrdiff_t FUN_1415db540(Unk_StlElem<0xc8>* const& pFirst, Unk_StlElem<0xc8>* const& pLast);
ptrdiff_t FUN_1415db570(Unk_StlElem<0xf8>* const& pFirst, Unk_StlElem<0xf8>* const& pLast);
ptrdiff_t FUN_1415db5a0(Unk_StlElem<0x490>* const& pFirst, Unk_StlElem<0x490>* const& pLast);
ptrdiff_t FUN_1415db5d0(Unk_StlElem<0x20>* const& pFirst, Unk_StlElem<0x20>* const& pLast);
ptrdiff_t FUN_1415db600(Unk_StlElem<0x30>* const& pFirst, Unk_StlElem<0x30>* const& pLast);
void FUN_1415dbe50(void* const& pFirst, void* const& pLast);
void FUN_1415dbe80(void* const& pFirst, void* const& pLast, std::input_iterator_tag);
void FUN_1415dbe90(void* const& pFirst, void* const& pLast);
void FUN_1415dbec0(void* const& pFirst, void* const& pLast, std::input_iterator_tag);
void FUN_1415dbed0(void* const& pFirst, void* const& pLast);
void FUN_1415dbf00(void* const& pFirst, void* const& pLast, std::input_iterator_tag);
void FUN_1415dbf10(void* const& pFirst, void* const& pLast);
void FUN_1415dbf40(void* const& pFirst, void* const& pLast, std::input_iterator_tag);
void FUN_1415dbf50(void* const& pFirst, void* const& pLast);
void FUN_1415dbf80(void* const& pFirst, void* const& pLast, std::input_iterator_tag);
void FUN_1415dbf90(void* const& pFirst, void* const& pLast);
void FUN_1415dbfc0(void* const& pFirst, void* const& pLast, std::input_iterator_tag);
void FUN_1415dbfd0(void* const& pFirst, void* const& pLast);
void FUN_1415dc000(void* const& pFirst, void* const& pLast, std::input_iterator_tag);
void FUN_1415dc010(void* const& pFirst, void* const& pLast);
void FUN_1415dc040(void* const& pFirst, void* const& pLast, std::input_iterator_tag);
void FUN_1415dc050(void* const& pFirst, void* const& pLast);
void FUN_1415dc080(void* const& pFirst, void* const& pLast, std::input_iterator_tag);
void FUN_1415dc090(void* const& pFirst, void* const& pLast);
void FUN_1415dc0c0(void* const& pFirst, void* const& pLast, std::input_iterator_tag);
void FUN_1415dc0d0(void* const& pFirst, void* const& pLast);
void FUN_1415dc100(void* const& pFirst, void* const& pLast, std::input_iterator_tag);
void FUN_1415dc110(void* const& pFirst, void* const& pLast);
void FUN_1415dc140(void* const& pFirst, void* const& pLast, std::input_iterator_tag);
void FUN_1415dc150(void* const& pFirst, void* const& pLast);
void FUN_1415dc180(void* const& pFirst, void* const& pLast, std::input_iterator_tag);
void FUN_1415dc190(void* const& pFirst, void* const& pLast);
void FUN_1415dc1c0(void* const& pFirst, void* const& pLast, std::input_iterator_tag);
void FUN_1415dc1d0(void* const& pFirst, void* const& pLast);
void FUN_1415dc200(void* const& pFirst, void* const& pLast, std::input_iterator_tag);
void FUN_1415dc210(void* const& pFirst, void* const& pLast);
void FUN_1415dc240(void* const& pFirst, void* const& pLast, std::input_iterator_tag);
void FUN_1415dc250(void* const& pFirst, void* const& pLast);
void FUN_1415dc280(void* const& pFirst, void* const& pLast, std::input_iterator_tag);
std::_General_ptr_iterator_tag FUN_1415dc290(Unk_StlElem<0x30>* const& pSrc, Unk_StlElem<0x30>* const& pDest);
std::_Really_trivial_ptr_iterator_tag FUN_1415dc2c0(Unk_StlElem<0x10>* const& pSrc, Unk_StlElem<0x10>* const& pDest);
std::_Really_trivial_ptr_iterator_tag FUN_1415dc2e0(Unk_StlElem<0x18>* const& pSrc, Unk_StlElem<0x18>* const& pDest);
std::_General_ptr_iterator_tag FUN_1415dc300(Unk_StlElem<0x58>* const& pSrc, Unk_StlElem<0x58>* const& pDest);
std::_General_ptr_iterator_tag FUN_1415dc330(Unk_StlElem<0x30>* const& pSrc, Unk_StlElem<0x30>* const& pDest);
std::_General_ptr_iterator_tag FUN_1415dc360(Unk_StlElem<0x98>* const& pSrc, Unk_StlElem<0x98>* const& pDest);
std::_General_ptr_iterator_tag FUN_1415dc390(Unk_StlElem<0x220>* const& pSrc, Unk_StlElem<0x220>* const& pDest);
std::_General_ptr_iterator_tag FUN_1415dc3c0(Unk_StlElem<0x128>* const& pSrc, Unk_StlElem<0x128>* const& pDest);
std::_General_ptr_iterator_tag FUN_1415dc3f0(Unk_StlElem<0x118>* const& pSrc, Unk_StlElem<0x118>* const& pDest);
std::_General_ptr_iterator_tag FUN_1415dc420(Unk_StlElem<0x580>* const& pSrc, Unk_StlElem<0x580>* const& pDest);
std::_General_ptr_iterator_tag FUN_1415dc450(Unk_StlElem<0x18>* const& pSrc, Unk_StlElem<0x18>* const& pDest);
std::_General_ptr_iterator_tag FUN_1415dc480(Unk_StlElem<0x14a8>* const& pSrc, Unk_StlElem<0x14a8>* const& pDest);
std::_General_ptr_iterator_tag FUN_1415dc4b0(Unk_StlElem<0x18>* const& pSrc, Unk_StlElem<0x18>* const& pDest);
std::_General_ptr_iterator_tag FUN_1415dc4e0(Unk_StlElem<0x190>* const& pSrc, Unk_StlElem<0x190>* const& pDest);
std::_General_ptr_iterator_tag FUN_1415dc510(Unk_StlElem<0xb8>* const& pSrc, Unk_StlElem<0xb8>* const& pDest);
std::_General_ptr_iterator_tag FUN_1415dc540(Unk_StlElem<0x58>* const& pSrc, Unk_StlElem<0x58>* const& pDest);
std::_General_ptr_iterator_tag FUN_1415dc570(Unk_StlElem<0xae8>* const& pSrc, Unk_StlElem<0xae8>* const& pDest);
std::_General_ptr_iterator_tag FUN_1415dc5a0(Unk_StlElem<0xec8>* const& pSrc, Unk_StlElem<0xec8>* const& pDest);
std::_General_ptr_iterator_tag FUN_1415dc5d0(Unk_StlElem<0xc8>* const& pSrc, Unk_StlElem<0xc8>* const& pDest);
std::_General_ptr_iterator_tag FUN_1415dc600(Unk_StlElem<0xf8>* const& pSrc, Unk_StlElem<0xf8>* const& pDest);
std::_General_ptr_iterator_tag FUN_1415dc630(Unk_StlElem<0x490>* const& pSrc, Unk_StlElem<0x490>* const& pDest);
std::_General_ptr_iterator_tag FUN_1415dc660(Unk_StlElem<0x20>* const& pSrc, Unk_StlElem<0x20>* const& pDest);
std::_Really_trivial_ptr_iterator_tag FUN_1415dc690(Unk_StlElem<0x10>* const& pSrc, Unk_StlElem<0x10>* const& pDest);
std::_Really_trivial_ptr_iterator_tag FUN_1415dc6b0(Unk_StlElem<0x18>* const& pSrc, Unk_StlElem<0x18>* const& pDest);
std::_General_ptr_iterator_tag FUN_1415dc6d0(Unk_StlElem<0x58>* const& pSrc, Unk_StlElem<0x58>* const& pDest);
std::_General_ptr_iterator_tag FUN_1415dc700(Unk_StlElem<0x30>* const& pSrc, Unk_StlElem<0x30>* const& pDest);
std::_General_ptr_iterator_tag FUN_1415dc730(Unk_StlElem<0x98>* const& pSrc, Unk_StlElem<0x98>* const& pDest);
std::_General_ptr_iterator_tag FUN_1415dc760(Unk_StlElem<0x220>* const& pSrc, Unk_StlElem<0x220>* const& pDest);
std::_General_ptr_iterator_tag FUN_1415dc790(Unk_StlElem<0x128>* const& pSrc, Unk_StlElem<0x128>* const& pDest);
std::_General_ptr_iterator_tag FUN_1415dc7c0(Unk_StlElem<0x118>* const& pSrc, Unk_StlElem<0x118>* const& pDest);
std::_General_ptr_iterator_tag FUN_1415dc7f0(Unk_StlElem<0xe0>* const& pSrc, Unk_StlElem<0xe0>* const& pDest);
std::_General_ptr_iterator_tag FUN_1415dc820(Unk_StlElem<0x580>* const& pSrc, Unk_StlElem<0x580>* const& pDest);
std::_General_ptr_iterator_tag FUN_1415dc850(Unk_StlElem<0x18>* const& pSrc, Unk_StlElem<0x18>* const& pDest);
std::_General_ptr_iterator_tag FUN_1415dc880(Unk_StlElem<0x14a8>* const& pSrc, Unk_StlElem<0x14a8>* const& pDest);
std::_General_ptr_iterator_tag FUN_1415dc8b0(Unk_StlElem<0x18>* const& pSrc, Unk_StlElem<0x18>* const& pDest);
std::_General_ptr_iterator_tag FUN_1415dc8e0(Unk_StlElem<0x190>* const& pSrc, Unk_StlElem<0x190>* const& pDest);
std::_General_ptr_iterator_tag FUN_1415dc910(Unk_StlElem<0xb8>* const& pSrc, Unk_StlElem<0xb8>* const& pDest);
std::_General_ptr_iterator_tag FUN_1415dc940(Unk_StlElem<0x58>* const& pSrc, Unk_StlElem<0x58>* const& pDest);
std::_General_ptr_iterator_tag FUN_1415dc970(Unk_StlElem<0x68>* const& pSrc, Unk_StlElem<0x68>* const& pDest);
std::_General_ptr_iterator_tag FUN_1415dc9a0(Unk_StlElem<0xae8>* const& pSrc, Unk_StlElem<0xae8>* const& pDest);
std::_General_ptr_iterator_tag FUN_1415dc9d0(Unk_StlElem<0xec8>* const& pSrc, Unk_StlElem<0xec8>* const& pDest);
std::_General_ptr_iterator_tag FUN_1415dca00(Unk_StlElem<0xc8>* const& pSrc, Unk_StlElem<0xc8>* const& pDest);
std::_General_ptr_iterator_tag FUN_1415dca30(Unk_StlElem<0xf8>* const& pSrc, Unk_StlElem<0xf8>* const& pDest);
std::_General_ptr_iterator_tag FUN_1415dca60(Unk_StlElem<0x490>* const& pSrc, Unk_StlElem<0x490>* const& pDest);
std::_General_ptr_iterator_tag FUN_1415dca90(Unk_StlElem<0x20>* const& pSrc, Unk_StlElem<0x20>* const& pDest);
void FUN_1415dcac0(Unk_StlElem<0x10>*& pIt, Unk_StlElem<0x10>* const pUnwrapped);
void FUN_1415dcae0(Unk_StlElem<0x18>*& pIt, Unk_StlElem<0x18>* const pUnwrapped);
void FUN_1415dcb30(Unk_StlElem<0x58>*& pIt, Unk_StlElem<0x58>* const pUnwrapped);
void FUN_1415dcb50(Unk_StlElem<0x30>*& pIt, Unk_StlElem<0x30>* const pUnwrapped);
void FUN_1415dcb70(Unk_StlElem<0x98>*& pIt, Unk_StlElem<0x98>* const pUnwrapped);
void FUN_1415dcb90(Unk_StlElem<0x220>*& pIt, Unk_StlElem<0x220>* const pUnwrapped);
void FUN_1415dcbb0(Unk_StlElem<0x128>*& pIt, Unk_StlElem<0x128>* const pUnwrapped);
void FUN_1415dcbd0(Unk_StlElem<0x118>*& pIt, Unk_StlElem<0x118>* const pUnwrapped);
void FUN_1415dcbf0(Unk_StlElem<0xe0>*& pIt, Unk_StlElem<0xe0>* const pUnwrapped);
void FUN_1415dcc10(Unk_StlElem<0x580>*& pIt, Unk_StlElem<0x580>* const pUnwrapped);
void FUN_1415dcc30(Unk_StlElem<0x18>*& pIt, Unk_StlElem<0x18>* const pUnwrapped);
void FUN_1415dcc50(Unk_StlElem<0x14a8>*& pIt, Unk_StlElem<0x14a8>* const pUnwrapped);
void FUN_1415dcc70(Unk_StlElem<0x18>*& pIt, Unk_StlElem<0x18>* const pUnwrapped);
void FUN_1415dcc90(Unk_StlElem<0x190>*& pIt, Unk_StlElem<0x190>* const pUnwrapped);
void FUN_1415dccb0(Unk_StlElem<0xb8>*& pIt, Unk_StlElem<0xb8>* const pUnwrapped);
void FUN_1415dccd0(Unk_StlElem<0x58>*& pIt, Unk_StlElem<0x58>* const pUnwrapped);
void FUN_1415dccf0(Unk_StlElem<0x68>*& pIt, Unk_StlElem<0x68>* const pUnwrapped);
void FUN_1415dcd10(Unk_StlElem<0xae8>*& pIt, Unk_StlElem<0xae8>* const pUnwrapped);
void FUN_1415dcd30(Unk_StlElem<0xec8>*& pIt, Unk_StlElem<0xec8>* const pUnwrapped);
void FUN_1415dcd50(Unk_StlElem<0xc8>*& pIt, Unk_StlElem<0xc8>* const pUnwrapped);
void FUN_1415dcd70(Unk_StlElem<0xf8>*& pIt, Unk_StlElem<0xf8>* const pUnwrapped);
void FUN_1415dcd90(Unk_StlElem<0x490>*& pIt, Unk_StlElem<0x490>* const pUnwrapped);
void FUN_1415dcdb0(Unk_StlElem<0x20>*& pIt, Unk_StlElem<0x20>* const pUnwrapped);
Unk_StlElem<0x10>* FUN_1415dd240(void* pThis, Unk_StlElem<0x10>* pFirst, Unk_StlElem<0x10>* pLast, Unk_StlElem<0x10>* pDest);
Unk_StlElem<0x18>* FUN_1415dd280(void* pThis, Unk_StlElem<0x18>* pFirst, Unk_StlElem<0x18>* pLast, Unk_StlElem<0x18>* pDest);
Unk_StlElem<0x58>* FUN_1415dd2c0(void* pThis, Unk_StlElem<0x58>* pFirst, Unk_StlElem<0x58>* pLast, Unk_StlElem<0x58>* pDest);
Unk_StlElem<0x30>* FUN_1415dd300(void* pThis, Unk_StlElem<0x30>* pFirst, Unk_StlElem<0x30>* pLast, Unk_StlElem<0x30>* pDest);
Unk_StlElem<0x98>* FUN_1415dd340(void* pThis, Unk_StlElem<0x98>* pFirst, Unk_StlElem<0x98>* pLast, Unk_StlElem<0x98>* pDest);
Unk_StlElem<0x220>* FUN_1415dd380(void* pThis, Unk_StlElem<0x220>* pFirst, Unk_StlElem<0x220>* pLast, Unk_StlElem<0x220>* pDest);
Unk_StlElem<0x128>* FUN_1415dd3c0(void* pThis, Unk_StlElem<0x128>* pFirst, Unk_StlElem<0x128>* pLast, Unk_StlElem<0x128>* pDest);
Unk_StlElem<0x118>* FUN_1415dd400(void* pThis, Unk_StlElem<0x118>* pFirst, Unk_StlElem<0x118>* pLast, Unk_StlElem<0x118>* pDest);
Unk_StlElem<0x580>* FUN_1415dd440(void* pThis, Unk_StlElem<0x580>* pFirst, Unk_StlElem<0x580>* pLast, Unk_StlElem<0x580>* pDest);
Unk_StlElem<0x18>* FUN_1415dd480(void* pThis, Unk_StlElem<0x18>* pFirst, Unk_StlElem<0x18>* pLast, Unk_StlElem<0x18>* pDest);
Unk_StlElem<0x14a8>* FUN_1415dd4c0(void* pThis, Unk_StlElem<0x14a8>* pFirst, Unk_StlElem<0x14a8>* pLast, Unk_StlElem<0x14a8>* pDest);
Unk_StlElem<0x18>* FUN_1415dd500(void* pThis, Unk_StlElem<0x18>* pFirst, Unk_StlElem<0x18>* pLast, Unk_StlElem<0x18>* pDest);
Unk_StlElem<0x190>* FUN_1415dd540(void* pThis, Unk_StlElem<0x190>* pFirst, Unk_StlElem<0x190>* pLast, Unk_StlElem<0x190>* pDest);
Unk_StlElem<0xb8>* FUN_1415dd580(void* pThis, Unk_StlElem<0xb8>* pFirst, Unk_StlElem<0xb8>* pLast, Unk_StlElem<0xb8>* pDest);
Unk_StlElem<0x58>* FUN_1415dd5c0(void* pThis, Unk_StlElem<0x58>* pFirst, Unk_StlElem<0x58>* pLast, Unk_StlElem<0x58>* pDest);
Unk_StlElem<0xae8>* FUN_1415dd600(void* pThis, Unk_StlElem<0xae8>* pFirst, Unk_StlElem<0xae8>* pLast, Unk_StlElem<0xae8>* pDest);
Unk_StlElem<0xec8>* FUN_1415dd640(void* pThis, Unk_StlElem<0xec8>* pFirst, Unk_StlElem<0xec8>* pLast, Unk_StlElem<0xec8>* pDest);
Unk_StlElem<0xc8>* FUN_1415dd680(void* pThis, Unk_StlElem<0xc8>* pFirst, Unk_StlElem<0xc8>* pLast, Unk_StlElem<0xc8>* pDest);
Unk_StlElem<0xf8>* FUN_1415dd6c0(void* pThis, Unk_StlElem<0xf8>* pFirst, Unk_StlElem<0xf8>* pLast, Unk_StlElem<0xf8>* pDest);
Unk_StlElem<0x490>* FUN_1415dd700(void* pThis, Unk_StlElem<0x490>* pFirst, Unk_StlElem<0x490>* pLast, Unk_StlElem<0x490>* pDest);
Unk_StlElem<0x20>* FUN_1415dd740(void* pThis, Unk_StlElem<0x20>* pFirst, Unk_StlElem<0x20>* pLast, Unk_StlElem<0x20>* pDest);
Unk_StlElem<0x30>* FUN_1415dd780(void* pThis, Unk_StlElem<0x30>* pFirst, Unk_StlElem<0x30>* pLast, Unk_StlElem<0x30>* pDest);
Unk_StlElem<0x10>* FUN_1415dd7c0(Unk_StlElem<0x10>* p);
Unk_StlElem<0x18>* FUN_1415dd7d0(Unk_StlElem<0x18>* p);
Unk_StlElem<0x58>* FUN_1415dd7e0(Unk_StlElem<0x58>* p);
Unk_StlElem<0x30>* FUN_1415dd7f0(Unk_StlElem<0x30>* p);
Unk_StlElem<0x98>* FUN_1415dd800(Unk_StlElem<0x98>* p);
Unk_StlElem<0x220>* FUN_1415dd810(Unk_StlElem<0x220>* p);
Unk_StlElem<0x128>* FUN_1415dd820(Unk_StlElem<0x128>* p);
Unk_StlElem<0x118>* FUN_1415dd830(Unk_StlElem<0x118>* p);
Unk_StlElem<0xe0>* FUN_1415dd840(Unk_StlElem<0xe0>* p);
Unk_StlElem<0x580>* FUN_1415dd850(Unk_StlElem<0x580>* p);
Unk_StlElem<0x18>* FUN_1415dd860(Unk_StlElem<0x18>* p);
Unk_StlElem<0x14a8>* FUN_1415dd870(Unk_StlElem<0x14a8>* p);
Unk_StlElem<0x18>* FUN_1415dd880(Unk_StlElem<0x18>* p);
Unk_StlElem<0x190>* FUN_1415dd890(Unk_StlElem<0x190>* p);
Unk_StlElem<0xb8>* FUN_1415dd8a0(Unk_StlElem<0xb8>* p);
Unk_StlElem<0x58>* FUN_1415dd8b0(Unk_StlElem<0x58>* p);
Unk_StlElem<0x68>* FUN_1415dd8c0(Unk_StlElem<0x68>* p);
Unk_StlElem<0xae8>* FUN_1415dd8d0(Unk_StlElem<0xae8>* p);
Unk_StlElem<0xec8>* FUN_1415dd8e0(Unk_StlElem<0xec8>* p);
Unk_StlElem<0xc8>* FUN_1415dd8f0(Unk_StlElem<0xc8>* p);
Unk_StlElem<0xf8>* FUN_1415dd900(Unk_StlElem<0xf8>* p);
Unk_StlElem<0x490>* FUN_1415dd910(Unk_StlElem<0x490>* p);
Unk_StlElem<0x20>* FUN_1415dd920(Unk_StlElem<0x20>* p);
Unk_StlElem<0x10>* FUN_1415dd930(Unk_StlElem<0x10>* const pFirst, Unk_StlElem<0x10>* const pLast, Unk_StlElem<0x10>* pDest, void* pAl);
Unk_StlElem<0x18>* FUN_1415dd9e0(Unk_StlElem<0x18>* const pFirst, Unk_StlElem<0x18>* const pLast, Unk_StlElem<0x18>* pDest, void* pAl);
Unk_StlElem<0x58>* FUN_1415dda90(Unk_StlElem<0x58>* const pFirst, Unk_StlElem<0x58>* const pLast, Unk_StlElem<0x58>* pDest, void* pAl);
Unk_StlElem<0x30>* FUN_1415ddb60(Unk_StlElem<0x30>* const pFirst, Unk_StlElem<0x30>* const pLast, Unk_StlElem<0x30>* pDest, void* pAl);
Unk_StlElem<0x98>* FUN_1415ddc30(Unk_StlElem<0x98>* const pFirst, Unk_StlElem<0x98>* const pLast, Unk_StlElem<0x98>* pDest, void* pAl);
Unk_StlElem<0x220>* FUN_1415ddd00(Unk_StlElem<0x220>* const pFirst, Unk_StlElem<0x220>* const pLast, Unk_StlElem<0x220>* pDest, void* pAl);
Unk_StlElem<0x128>* FUN_1415dddd0(Unk_StlElem<0x128>* const pFirst, Unk_StlElem<0x128>* const pLast, Unk_StlElem<0x128>* pDest, void* pAl);
Unk_StlElem<0x118>* FUN_1415ddea0(Unk_StlElem<0x118>* const pFirst, Unk_StlElem<0x118>* const pLast, Unk_StlElem<0x118>* pDest, void* pAl);
Unk_StlElem<0x580>* FUN_1415ddf70(Unk_StlElem<0x580>* const pFirst, Unk_StlElem<0x580>* const pLast, Unk_StlElem<0x580>* pDest, void* pAl);
Unk_StlElem<0x18>* FUN_1415de040(Unk_StlElem<0x18>* const pFirst, Unk_StlElem<0x18>* const pLast, Unk_StlElem<0x18>* pDest, void* pAl);
Unk_StlElem<0x14a8>* FUN_1415de110(Unk_StlElem<0x14a8>* const pFirst, Unk_StlElem<0x14a8>* const pLast, Unk_StlElem<0x14a8>* pDest, void* pAl);
Unk_StlElem<0x18>* FUN_1415de1e0(Unk_StlElem<0x18>* const pFirst, Unk_StlElem<0x18>* const pLast, Unk_StlElem<0x18>* pDest, void* pAl);
Unk_StlElem<0x190>* FUN_1415de2b0(Unk_StlElem<0x190>* const pFirst, Unk_StlElem<0x190>* const pLast, Unk_StlElem<0x190>* pDest, void* pAl);
Unk_StlElem<0xb8>* FUN_1415de380(Unk_StlElem<0xb8>* const pFirst, Unk_StlElem<0xb8>* const pLast, Unk_StlElem<0xb8>* pDest, void* pAl);
Unk_StlElem<0x58>* FUN_1415de450(Unk_StlElem<0x58>* const pFirst, Unk_StlElem<0x58>* const pLast, Unk_StlElem<0x58>* pDest, void* pAl);
Unk_StlElem<0xae8>* FUN_1415de520(Unk_StlElem<0xae8>* const pFirst, Unk_StlElem<0xae8>* const pLast, Unk_StlElem<0xae8>* pDest, void* pAl);
Unk_StlElem<0xec8>* FUN_1415de5f0(Unk_StlElem<0xec8>* const pFirst, Unk_StlElem<0xec8>* const pLast, Unk_StlElem<0xec8>* pDest, void* pAl);
Unk_StlElem<0xc8>* FUN_1415de6c0(Unk_StlElem<0xc8>* const pFirst, Unk_StlElem<0xc8>* const pLast, Unk_StlElem<0xc8>* pDest, void* pAl);
Unk_StlElem<0xf8>* FUN_1415de790(Unk_StlElem<0xf8>* const pFirst, Unk_StlElem<0xf8>* const pLast, Unk_StlElem<0xf8>* pDest, void* pAl);
Unk_StlElem<0x490>* FUN_1415de860(Unk_StlElem<0x490>* const pFirst, Unk_StlElem<0x490>* const pLast, Unk_StlElem<0x490>* pDest, void* pAl);
Unk_StlElem<0x20>* FUN_1415de930(Unk_StlElem<0x20>* const pFirst, Unk_StlElem<0x20>* const pLast, Unk_StlElem<0x20>* pDest, void* pAl);
Unk_StlElem<0x30>* FUN_1415dea00(Unk_StlElem<0x30>* const pFirst, Unk_StlElem<0x30>* const pLast, Unk_StlElem<0x30>* pDest, void* pAl);
Unk_StlElem<0x58>* FUN_1415dead0(Unk_StlElem<0x58>* pFirst, Unk_StlElem<0x58>* const pLast, Unk_StlElem<0x58>* const pDest, void* pAl, std::_General_ptr_iterator_tag, std::_Any_tag);
Unk_StlElem<0x30>* FUN_1415deb60(Unk_StlElem<0x30>* pFirst, Unk_StlElem<0x30>* const pLast, Unk_StlElem<0x30>* const pDest, void* pAl, std::_General_ptr_iterator_tag, std::_Any_tag);
Unk_StlElem<0x98>* FUN_1415debf0(Unk_StlElem<0x98>* pFirst, Unk_StlElem<0x98>* const pLast, Unk_StlElem<0x98>* const pDest, void* pAl, std::_General_ptr_iterator_tag, std::_Any_tag);
Unk_StlElem<0x220>* FUN_1415dec80(Unk_StlElem<0x220>* pFirst, Unk_StlElem<0x220>* const pLast, Unk_StlElem<0x220>* const pDest, void* pAl, std::_General_ptr_iterator_tag, std::_Any_tag);
Unk_StlElem<0x128>* FUN_1415ded10(Unk_StlElem<0x128>* pFirst, Unk_StlElem<0x128>* const pLast, Unk_StlElem<0x128>* const pDest, void* pAl, std::_General_ptr_iterator_tag, std::_Any_tag);
Unk_StlElem<0x118>* FUN_1415deda0(Unk_StlElem<0x118>* pFirst, Unk_StlElem<0x118>* const pLast, Unk_StlElem<0x118>* const pDest, void* pAl, std::_General_ptr_iterator_tag, std::_Any_tag);
Unk_StlElem<0x580>* FUN_1415dee30(Unk_StlElem<0x580>* pFirst, Unk_StlElem<0x580>* const pLast, Unk_StlElem<0x580>* const pDest, void* pAl, std::_General_ptr_iterator_tag, std::_Any_tag);
Unk_StlElem<0x18>* FUN_1415deec0(Unk_StlElem<0x18>* pFirst, Unk_StlElem<0x18>* const pLast, Unk_StlElem<0x18>* const pDest, void* pAl, std::_General_ptr_iterator_tag, std::_Any_tag);
Unk_StlElem<0x14a8>* FUN_1415def50(Unk_StlElem<0x14a8>* pFirst, Unk_StlElem<0x14a8>* const pLast, Unk_StlElem<0x14a8>* const pDest, void* pAl, std::_General_ptr_iterator_tag, std::_Any_tag);
Unk_StlElem<0x18>* FUN_1415defe0(Unk_StlElem<0x18>* pFirst, Unk_StlElem<0x18>* const pLast, Unk_StlElem<0x18>* const pDest, void* pAl, std::_General_ptr_iterator_tag, std::_Any_tag);
Unk_StlElem<0x190>* FUN_1415df070(Unk_StlElem<0x190>* pFirst, Unk_StlElem<0x190>* const pLast, Unk_StlElem<0x190>* const pDest, void* pAl, std::_General_ptr_iterator_tag, std::_Any_tag);
Unk_StlElem<0xb8>* FUN_1415df100(Unk_StlElem<0xb8>* pFirst, Unk_StlElem<0xb8>* const pLast, Unk_StlElem<0xb8>* const pDest, void* pAl, std::_General_ptr_iterator_tag, std::_Any_tag);
Unk_StlElem<0x58>* FUN_1415df190(Unk_StlElem<0x58>* pFirst, Unk_StlElem<0x58>* const pLast, Unk_StlElem<0x58>* const pDest, void* pAl, std::_General_ptr_iterator_tag, std::_Any_tag);
Unk_StlElem<0xae8>* FUN_1415df220(Unk_StlElem<0xae8>* pFirst, Unk_StlElem<0xae8>* const pLast, Unk_StlElem<0xae8>* const pDest, void* pAl, std::_General_ptr_iterator_tag, std::_Any_tag);
Unk_StlElem<0xec8>* FUN_1415df2b0(Unk_StlElem<0xec8>* pFirst, Unk_StlElem<0xec8>* const pLast, Unk_StlElem<0xec8>* const pDest, void* pAl, std::_General_ptr_iterator_tag, std::_Any_tag);
Unk_StlElem<0xc8>* FUN_1415df340(Unk_StlElem<0xc8>* pFirst, Unk_StlElem<0xc8>* const pLast, Unk_StlElem<0xc8>* const pDest, void* pAl, std::_General_ptr_iterator_tag, std::_Any_tag);
Unk_StlElem<0xf8>* FUN_1415df3d0(Unk_StlElem<0xf8>* pFirst, Unk_StlElem<0xf8>* const pLast, Unk_StlElem<0xf8>* const pDest, void* pAl, std::_General_ptr_iterator_tag, std::_Any_tag);
Unk_StlElem<0x490>* FUN_1415df460(Unk_StlElem<0x490>* pFirst, Unk_StlElem<0x490>* const pLast, Unk_StlElem<0x490>* const pDest, void* pAl, std::_General_ptr_iterator_tag, std::_Any_tag);
Unk_StlElem<0x20>* FUN_1415df4f0(Unk_StlElem<0x20>* pFirst, Unk_StlElem<0x20>* const pLast, Unk_StlElem<0x20>* const pDest, void* pAl, std::_General_ptr_iterator_tag, std::_Any_tag);
Unk_StlElem<0x30>* FUN_1415df580(Unk_StlElem<0x30>* pFirst, Unk_StlElem<0x30>* const pLast, Unk_StlElem<0x30>* const pDest, void* pAl, std::_General_ptr_iterator_tag, std::_Any_tag);
Unk_StlElem<0x10>* FUN_1415df610(Unk_StlElem<0x10>* const pFirst, Unk_StlElem<0x10>* const pLast, Unk_StlElem<0x10>* const pDest, void* pAl, std::_Really_trivial_ptr_iterator_tag, std::true_type);
Unk_StlElem<0x18>* FUN_1415df650(Unk_StlElem<0x18>* const pFirst, Unk_StlElem<0x18>* const pLast, Unk_StlElem<0x18>* const pDest, void* pAl, std::_Really_trivial_ptr_iterator_tag, std::true_type);
Unk_StlElem<0x10>* FUN_1415df690(Unk_StlElem<0x10>* const pFirst, Unk_StlElem<0x10>* const pLast, Unk_StlElem<0x10>* pDest, void* pAl);
Unk_StlElem<0x18>* FUN_1415df740(Unk_StlElem<0x18>* const pFirst, Unk_StlElem<0x18>* const pLast, Unk_StlElem<0x18>* pDest, void* pAl);
Unk_StlElem<0x58>* FUN_1415df7f0(Unk_StlElem<0x58>* const pFirst, Unk_StlElem<0x58>* const pLast, Unk_StlElem<0x58>* pDest, void* pAl);
Unk_StlElem<0x30>* FUN_1415df8c0(Unk_StlElem<0x30>* const pFirst, Unk_StlElem<0x30>* const pLast, Unk_StlElem<0x30>* pDest, void* pAl);
Unk_StlElem<0x98>* FUN_1415df990(Unk_StlElem<0x98>* const pFirst, Unk_StlElem<0x98>* const pLast, Unk_StlElem<0x98>* pDest, void* pAl);
Unk_StlElem<0x220>* FUN_1415dfa60(Unk_StlElem<0x220>* const pFirst, Unk_StlElem<0x220>* const pLast, Unk_StlElem<0x220>* pDest, void* pAl);
Unk_StlElem<0x128>* FUN_1415dfb30(Unk_StlElem<0x128>* const pFirst, Unk_StlElem<0x128>* const pLast, Unk_StlElem<0x128>* pDest, void* pAl);
Unk_StlElem<0x118>* FUN_1415dfc00(Unk_StlElem<0x118>* const pFirst, Unk_StlElem<0x118>* const pLast, Unk_StlElem<0x118>* pDest, void* pAl);
Unk_StlElem<0xe0>* FUN_1415dfcd0(Unk_StlElem<0xe0>* const pFirst, Unk_StlElem<0xe0>* const pLast, Unk_StlElem<0xe0>* pDest, void* pAl);
Unk_StlElem<0x580>* FUN_1415dfda0(Unk_StlElem<0x580>* const pFirst, Unk_StlElem<0x580>* const pLast, Unk_StlElem<0x580>* pDest, void* pAl);
Unk_StlElem<0x18>* FUN_1415dfe70(Unk_StlElem<0x18>* const pFirst, Unk_StlElem<0x18>* const pLast, Unk_StlElem<0x18>* pDest, void* pAl);
Unk_StlElem<0x14a8>* FUN_1415dff40(Unk_StlElem<0x14a8>* const pFirst, Unk_StlElem<0x14a8>* const pLast, Unk_StlElem<0x14a8>* pDest, void* pAl);
Unk_StlElem<0x18>* FUN_1415e0010(Unk_StlElem<0x18>* const pFirst, Unk_StlElem<0x18>* const pLast, Unk_StlElem<0x18>* pDest, void* pAl);
Unk_StlElem<0x190>* FUN_1415e00e0(Unk_StlElem<0x190>* const pFirst, Unk_StlElem<0x190>* const pLast, Unk_StlElem<0x190>* pDest, void* pAl);
Unk_StlElem<0xb8>* FUN_1415e01b0(Unk_StlElem<0xb8>* const pFirst, Unk_StlElem<0xb8>* const pLast, Unk_StlElem<0xb8>* pDest, void* pAl);
Unk_StlElem<0x58>* FUN_1415e0280(Unk_StlElem<0x58>* const pFirst, Unk_StlElem<0x58>* const pLast, Unk_StlElem<0x58>* pDest, void* pAl);
Unk_StlElem<0x68>* FUN_1415e0350(Unk_StlElem<0x68>* const pFirst, Unk_StlElem<0x68>* const pLast, Unk_StlElem<0x68>* pDest, void* pAl);
Unk_StlElem<0xae8>* FUN_1415e0420(Unk_StlElem<0xae8>* const pFirst, Unk_StlElem<0xae8>* const pLast, Unk_StlElem<0xae8>* pDest, void* pAl);
Unk_StlElem<0xec8>* FUN_1415e04f0(Unk_StlElem<0xec8>* const pFirst, Unk_StlElem<0xec8>* const pLast, Unk_StlElem<0xec8>* pDest, void* pAl);
Unk_StlElem<0xc8>* FUN_1415e05c0(Unk_StlElem<0xc8>* const pFirst, Unk_StlElem<0xc8>* const pLast, Unk_StlElem<0xc8>* pDest, void* pAl);
Unk_StlElem<0xf8>* FUN_1415e0690(Unk_StlElem<0xf8>* const pFirst, Unk_StlElem<0xf8>* const pLast, Unk_StlElem<0xf8>* pDest, void* pAl);
Unk_StlElem<0x490>* FUN_1415e0760(Unk_StlElem<0x490>* const pFirst, Unk_StlElem<0x490>* const pLast, Unk_StlElem<0x490>* pDest, void* pAl);
Unk_StlElem<0x20>* FUN_1415e0830(Unk_StlElem<0x20>* const pFirst, Unk_StlElem<0x20>* const pLast, Unk_StlElem<0x20>* pDest, void* pAl);
Unk_StlElem<0x58>* FUN_1415e0900(Unk_StlElem<0x58>* pFirst, Unk_StlElem<0x58>* const pLast, Unk_StlElem<0x58>* const pDest, void* pAl, std::_General_ptr_iterator_tag, std::_Any_tag);
Unk_StlElem<0x30>* FUN_1415e0990(Unk_StlElem<0x30>* pFirst, Unk_StlElem<0x30>* const pLast, Unk_StlElem<0x30>* const pDest, void* pAl, std::_General_ptr_iterator_tag, std::_Any_tag);
Unk_StlElem<0x98>* FUN_1415e0a20(Unk_StlElem<0x98>* pFirst, Unk_StlElem<0x98>* const pLast, Unk_StlElem<0x98>* const pDest, void* pAl, std::_General_ptr_iterator_tag, std::_Any_tag);
Unk_StlElem<0x220>* FUN_1415e0ab0(Unk_StlElem<0x220>* pFirst, Unk_StlElem<0x220>* const pLast, Unk_StlElem<0x220>* const pDest, void* pAl, std::_General_ptr_iterator_tag, std::_Any_tag);
Unk_StlElem<0x128>* FUN_1415e0b40(Unk_StlElem<0x128>* pFirst, Unk_StlElem<0x128>* const pLast, Unk_StlElem<0x128>* const pDest, void* pAl, std::_General_ptr_iterator_tag, std::_Any_tag);
Unk_StlElem<0x118>* FUN_1415e0bd0(Unk_StlElem<0x118>* pFirst, Unk_StlElem<0x118>* const pLast, Unk_StlElem<0x118>* const pDest, void* pAl, std::_General_ptr_iterator_tag, std::_Any_tag);
Unk_StlElem<0xe0>* FUN_1415e0c60(Unk_StlElem<0xe0>* pFirst, Unk_StlElem<0xe0>* const pLast, Unk_StlElem<0xe0>* const pDest, void* pAl, std::_General_ptr_iterator_tag, std::_Any_tag);
Unk_StlElem<0x580>* FUN_1415e0cf0(Unk_StlElem<0x580>* pFirst, Unk_StlElem<0x580>* const pLast, Unk_StlElem<0x580>* const pDest, void* pAl, std::_General_ptr_iterator_tag, std::_Any_tag);
Unk_StlElem<0x18>* FUN_1415e0d80(Unk_StlElem<0x18>* pFirst, Unk_StlElem<0x18>* const pLast, Unk_StlElem<0x18>* const pDest, void* pAl, std::_General_ptr_iterator_tag, std::_Any_tag);
Unk_StlElem<0x14a8>* FUN_1415e0e10(Unk_StlElem<0x14a8>* pFirst, Unk_StlElem<0x14a8>* const pLast, Unk_StlElem<0x14a8>* const pDest, void* pAl, std::_General_ptr_iterator_tag, std::_Any_tag);
Unk_StlElem<0x18>* FUN_1415e0ea0(Unk_StlElem<0x18>* pFirst, Unk_StlElem<0x18>* const pLast, Unk_StlElem<0x18>* const pDest, void* pAl, std::_General_ptr_iterator_tag, std::_Any_tag);
Unk_StlElem<0x190>* FUN_1415e0f30(Unk_StlElem<0x190>* pFirst, Unk_StlElem<0x190>* const pLast, Unk_StlElem<0x190>* const pDest, void* pAl, std::_General_ptr_iterator_tag, std::_Any_tag);
Unk_StlElem<0xb8>* FUN_1415e0fc0(Unk_StlElem<0xb8>* pFirst, Unk_StlElem<0xb8>* const pLast, Unk_StlElem<0xb8>* const pDest, void* pAl, std::_General_ptr_iterator_tag, std::_Any_tag);
Unk_StlElem<0x58>* FUN_1415e1050(Unk_StlElem<0x58>* pFirst, Unk_StlElem<0x58>* const pLast, Unk_StlElem<0x58>* const pDest, void* pAl, std::_General_ptr_iterator_tag, std::_Any_tag);
Unk_StlElem<0x68>* FUN_1415e10e0(Unk_StlElem<0x68>* pFirst, Unk_StlElem<0x68>* const pLast, Unk_StlElem<0x68>* const pDest, void* pAl, std::_General_ptr_iterator_tag, std::_Any_tag);
Unk_StlElem<0xae8>* FUN_1415e1170(Unk_StlElem<0xae8>* pFirst, Unk_StlElem<0xae8>* const pLast, Unk_StlElem<0xae8>* const pDest, void* pAl, std::_General_ptr_iterator_tag, std::_Any_tag);
Unk_StlElem<0xec8>* FUN_1415e1200(Unk_StlElem<0xec8>* pFirst, Unk_StlElem<0xec8>* const pLast, Unk_StlElem<0xec8>* const pDest, void* pAl, std::_General_ptr_iterator_tag, std::_Any_tag);
Unk_StlElem<0xc8>* FUN_1415e1290(Unk_StlElem<0xc8>* pFirst, Unk_StlElem<0xc8>* const pLast, Unk_StlElem<0xc8>* const pDest, void* pAl, std::_General_ptr_iterator_tag, std::_Any_tag);
Unk_StlElem<0xf8>* FUN_1415e1320(Unk_StlElem<0xf8>* pFirst, Unk_StlElem<0xf8>* const pLast, Unk_StlElem<0xf8>* const pDest, void* pAl, std::_General_ptr_iterator_tag, std::_Any_tag);
Unk_StlElem<0x490>* FUN_1415e13b0(Unk_StlElem<0x490>* pFirst, Unk_StlElem<0x490>* const pLast, Unk_StlElem<0x490>* const pDest, void* pAl, std::_General_ptr_iterator_tag, std::_Any_tag);
Unk_StlElem<0x20>* FUN_1415e1440(Unk_StlElem<0x20>* pFirst, Unk_StlElem<0x20>* const pLast, Unk_StlElem<0x20>* const pDest, void* pAl, std::_General_ptr_iterator_tag, std::_Any_tag);
Unk_StlElem<0x10>* FUN_1415e14d0(Unk_StlElem<0x10>* const pFirst, Unk_StlElem<0x10>* const pLast, Unk_StlElem<0x10>* const pDest, void* pAl, std::_Really_trivial_ptr_iterator_tag, std::true_type);
Unk_StlElem<0x18>* FUN_1415e1510(Unk_StlElem<0x18>* const pFirst, Unk_StlElem<0x18>* const pLast, Unk_StlElem<0x18>* const pDest, void* pAl, std::_Really_trivial_ptr_iterator_tag, std::true_type);

// @0x1415dad30
ptrdiff_t FUN_1415dad30(Unk_StlElem<0x10>* const& pFirst, Unk_StlElem<0x10>* const& pLast, std::random_access_iterator_tag)
{
    return pLast - pFirst;
}

// @0x1415dad60
ptrdiff_t FUN_1415dad60(Unk_StlElem<0x18>* const& pFirst, Unk_StlElem<0x18>* const& pLast, std::random_access_iterator_tag)
{
    return pLast - pFirst;
}

// @0x1415dad90
ptrdiff_t FUN_1415dad90(Unk_StlElem<0x58>* const& pFirst, Unk_StlElem<0x58>* const& pLast, std::random_access_iterator_tag)
{
    return pLast - pFirst;
}

// @0x1415dadc0
ptrdiff_t FUN_1415dadc0(Unk_StlElem<0x30>* const& pFirst, Unk_StlElem<0x30>* const& pLast, std::random_access_iterator_tag)
{
    return pLast - pFirst;
}

// @0x1415dadf0
ptrdiff_t FUN_1415dadf0(Unk_StlElem<0x98>* const& pFirst, Unk_StlElem<0x98>* const& pLast, std::random_access_iterator_tag)
{
    return pLast - pFirst;
}

// @0x1415dae20
ptrdiff_t FUN_1415dae20(Unk_StlElem<0x220>* const& pFirst, Unk_StlElem<0x220>* const& pLast, std::random_access_iterator_tag)
{
    return pLast - pFirst;
}

// @0x1415dae50
ptrdiff_t FUN_1415dae50(Unk_StlElem<0x128>* const& pFirst, Unk_StlElem<0x128>* const& pLast, std::random_access_iterator_tag)
{
    return pLast - pFirst;
}

// @0x1415dae80
ptrdiff_t FUN_1415dae80(Unk_StlElem<0x118>* const& pFirst, Unk_StlElem<0x118>* const& pLast, std::random_access_iterator_tag)
{
    return pLast - pFirst;
}

// @0x1415daeb0
ptrdiff_t FUN_1415daeb0(Unk_StlElem<0xe0>* const& pFirst, Unk_StlElem<0xe0>* const& pLast, std::random_access_iterator_tag)
{
    return pLast - pFirst;
}

// @0x1415daee0
ptrdiff_t FUN_1415daee0(Unk_StlElem<0x580>* const& pFirst, Unk_StlElem<0x580>* const& pLast, std::random_access_iterator_tag)
{
    return pLast - pFirst;
}

// @0x1415daf10
ptrdiff_t FUN_1415daf10(Unk_StlElem<0x18>* const& pFirst, Unk_StlElem<0x18>* const& pLast, std::random_access_iterator_tag)
{
    return pLast - pFirst;
}

// @0x1415daf40
ptrdiff_t FUN_1415daf40(Unk_StlElem<0x14a8>* const& pFirst, Unk_StlElem<0x14a8>* const& pLast, std::random_access_iterator_tag)
{
    return pLast - pFirst;
}

// @0x1415daf70
ptrdiff_t FUN_1415daf70(Unk_StlElem<0x18>* const& pFirst, Unk_StlElem<0x18>* const& pLast, std::random_access_iterator_tag)
{
    return pLast - pFirst;
}

// @0x1415dafa0
ptrdiff_t FUN_1415dafa0(Unk_StlElem<0x190>* const& pFirst, Unk_StlElem<0x190>* const& pLast, std::random_access_iterator_tag)
{
    return pLast - pFirst;
}

// @0x1415dafd0
ptrdiff_t FUN_1415dafd0(Unk_StlElem<0xb8>* const& pFirst, Unk_StlElem<0xb8>* const& pLast, std::random_access_iterator_tag)
{
    return pLast - pFirst;
}

// @0x1415db000
ptrdiff_t FUN_1415db000(Unk_StlElem<0x58>* const& pFirst, Unk_StlElem<0x58>* const& pLast, std::random_access_iterator_tag)
{
    return pLast - pFirst;
}

// @0x1415db030
ptrdiff_t FUN_1415db030(Unk_StlElem<0x68>* const& pFirst, Unk_StlElem<0x68>* const& pLast, std::random_access_iterator_tag)
{
    return pLast - pFirst;
}

// @0x1415db060
ptrdiff_t FUN_1415db060(Unk_StlElem<0xae8>* const& pFirst, Unk_StlElem<0xae8>* const& pLast, std::random_access_iterator_tag)
{
    return pLast - pFirst;
}

// @0x1415db090
ptrdiff_t FUN_1415db090(Unk_StlElem<0xec8>* const& pFirst, Unk_StlElem<0xec8>* const& pLast, std::random_access_iterator_tag)
{
    return pLast - pFirst;
}

// @0x1415db0c0
ptrdiff_t FUN_1415db0c0(Unk_StlElem<0xc8>* const& pFirst, Unk_StlElem<0xc8>* const& pLast, std::random_access_iterator_tag)
{
    return pLast - pFirst;
}

// @0x1415db0f0
ptrdiff_t FUN_1415db0f0(Unk_StlElem<0xf8>* const& pFirst, Unk_StlElem<0xf8>* const& pLast, std::random_access_iterator_tag)
{
    return pLast - pFirst;
}

// @0x1415db120
ptrdiff_t FUN_1415db120(Unk_StlElem<0x490>* const& pFirst, Unk_StlElem<0x490>* const& pLast, std::random_access_iterator_tag)
{
    return pLast - pFirst;
}

// @0x1415db150
ptrdiff_t FUN_1415db150(Unk_StlElem<0x20>* const& pFirst, Unk_StlElem<0x20>* const& pLast, std::random_access_iterator_tag)
{
    return pLast - pFirst;
}

// @0x1415db180
ptrdiff_t FUN_1415db180(Unk_StlElem<0x30>* const& pFirst, Unk_StlElem<0x30>* const& pLast, std::random_access_iterator_tag)
{
    return pLast - pFirst;
}

// @0x1415db1b0
ptrdiff_t FUN_1415db1b0(Unk_StlElem<0x10>* const& pFirst, Unk_StlElem<0x10>* const& pLast)
{
    return FUN_1415dad30(pFirst, pLast, std::random_access_iterator_tag());
}

// @0x1415db1e0
ptrdiff_t FUN_1415db1e0(Unk_StlElem<0x18>* const& pFirst, Unk_StlElem<0x18>* const& pLast)
{
    return FUN_1415dad60(pFirst, pLast, std::random_access_iterator_tag());
}

// @0x1415db210
ptrdiff_t FUN_1415db210(Unk_StlElem<0x58>* const& pFirst, Unk_StlElem<0x58>* const& pLast)
{
    return FUN_1415dad90(pFirst, pLast, std::random_access_iterator_tag());
}

// @0x1415db240
ptrdiff_t FUN_1415db240(Unk_StlElem<0x30>* const& pFirst, Unk_StlElem<0x30>* const& pLast)
{
    return FUN_1415dadc0(pFirst, pLast, std::random_access_iterator_tag());
}

// @0x1415db270
ptrdiff_t FUN_1415db270(Unk_StlElem<0x98>* const& pFirst, Unk_StlElem<0x98>* const& pLast)
{
    return FUN_1415dadf0(pFirst, pLast, std::random_access_iterator_tag());
}

// @0x1415db2a0
ptrdiff_t FUN_1415db2a0(Unk_StlElem<0x220>* const& pFirst, Unk_StlElem<0x220>* const& pLast)
{
    return FUN_1415dae20(pFirst, pLast, std::random_access_iterator_tag());
}

// @0x1415db2d0
ptrdiff_t FUN_1415db2d0(Unk_StlElem<0x128>* const& pFirst, Unk_StlElem<0x128>* const& pLast)
{
    return FUN_1415dae50(pFirst, pLast, std::random_access_iterator_tag());
}

// @0x1415db300
ptrdiff_t FUN_1415db300(Unk_StlElem<0x118>* const& pFirst, Unk_StlElem<0x118>* const& pLast)
{
    return FUN_1415dae80(pFirst, pLast, std::random_access_iterator_tag());
}

// @0x1415db330
ptrdiff_t FUN_1415db330(Unk_StlElem<0xe0>* const& pFirst, Unk_StlElem<0xe0>* const& pLast)
{
    return FUN_1415daeb0(pFirst, pLast, std::random_access_iterator_tag());
}

// @0x1415db360
ptrdiff_t FUN_1415db360(Unk_StlElem<0x580>* const& pFirst, Unk_StlElem<0x580>* const& pLast)
{
    return FUN_1415daee0(pFirst, pLast, std::random_access_iterator_tag());
}

// @0x1415db390
ptrdiff_t FUN_1415db390(Unk_StlElem<0x18>* const& pFirst, Unk_StlElem<0x18>* const& pLast)
{
    return FUN_1415daf10(pFirst, pLast, std::random_access_iterator_tag());
}

// @0x1415db3c0
ptrdiff_t FUN_1415db3c0(Unk_StlElem<0x14a8>* const& pFirst, Unk_StlElem<0x14a8>* const& pLast)
{
    return FUN_1415daf40(pFirst, pLast, std::random_access_iterator_tag());
}

// @0x1415db3f0
ptrdiff_t FUN_1415db3f0(Unk_StlElem<0x18>* const& pFirst, Unk_StlElem<0x18>* const& pLast)
{
    return FUN_1415daf70(pFirst, pLast, std::random_access_iterator_tag());
}

// @0x1415db420
ptrdiff_t FUN_1415db420(Unk_StlElem<0x190>* const& pFirst, Unk_StlElem<0x190>* const& pLast)
{
    return FUN_1415dafa0(pFirst, pLast, std::random_access_iterator_tag());
}

// @0x1415db450
ptrdiff_t FUN_1415db450(Unk_StlElem<0xb8>* const& pFirst, Unk_StlElem<0xb8>* const& pLast)
{
    return FUN_1415dafd0(pFirst, pLast, std::random_access_iterator_tag());
}

// @0x1415db480
ptrdiff_t FUN_1415db480(Unk_StlElem<0x58>* const& pFirst, Unk_StlElem<0x58>* const& pLast)
{
    return FUN_1415db000(pFirst, pLast, std::random_access_iterator_tag());
}

// @0x1415db4b0
ptrdiff_t FUN_1415db4b0(Unk_StlElem<0x68>* const& pFirst, Unk_StlElem<0x68>* const& pLast)
{
    return FUN_1415db030(pFirst, pLast, std::random_access_iterator_tag());
}

// @0x1415db4e0
ptrdiff_t FUN_1415db4e0(Unk_StlElem<0xae8>* const& pFirst, Unk_StlElem<0xae8>* const& pLast)
{
    return FUN_1415db060(pFirst, pLast, std::random_access_iterator_tag());
}

// @0x1415db510
ptrdiff_t FUN_1415db510(Unk_StlElem<0xec8>* const& pFirst, Unk_StlElem<0xec8>* const& pLast)
{
    return FUN_1415db090(pFirst, pLast, std::random_access_iterator_tag());
}

// @0x1415db540
ptrdiff_t FUN_1415db540(Unk_StlElem<0xc8>* const& pFirst, Unk_StlElem<0xc8>* const& pLast)
{
    return FUN_1415db0c0(pFirst, pLast, std::random_access_iterator_tag());
}

// @0x1415db570
ptrdiff_t FUN_1415db570(Unk_StlElem<0xf8>* const& pFirst, Unk_StlElem<0xf8>* const& pLast)
{
    return FUN_1415db0f0(pFirst, pLast, std::random_access_iterator_tag());
}

// @0x1415db5a0
ptrdiff_t FUN_1415db5a0(Unk_StlElem<0x490>* const& pFirst, Unk_StlElem<0x490>* const& pLast)
{
    return FUN_1415db120(pFirst, pLast, std::random_access_iterator_tag());
}

// @0x1415db5d0
ptrdiff_t FUN_1415db5d0(Unk_StlElem<0x20>* const& pFirst, Unk_StlElem<0x20>* const& pLast)
{
    return FUN_1415db150(pFirst, pLast, std::random_access_iterator_tag());
}

// @0x1415db600
ptrdiff_t FUN_1415db600(Unk_StlElem<0x30>* const& pFirst, Unk_StlElem<0x30>* const& pLast)
{
    return FUN_1415db180(pFirst, pLast, std::random_access_iterator_tag());
}

// @0x1415db630
// MS2-FUNCTIONAL: free-function form of std::_Tree::_Insert_at (explicit result pointer); not tuned against the exe.
Unk_TreeIter* FUN_1415db630(void* pThis, Unk_TreeIter* pResult, bool bAddLeft, Unk_TreeNode* pWhere, const unsigned char* pVal, Unk_TreeNode* pNode)
{
    Unk_TreeData* pData = FUN_141600e10(pThis);
    if (FUN_14160a970(pThis) - 1 <= pData->m_nSize)
    {
        FUN_141600710(pThis, pNode);
        std::_Xlength_error("map/set<T> too long");
    }
    Unk_TreeNode* pNewNode = FUN_1415d25c0(pThis, pNode, FUN_1415e4bd0(pVal));
    ++pData->m_nSize;
    pNewNode->_Parent = pWhere;
    if (pWhere == pData->m_pHead)
    {
        FUN_141604650(pData) = pNewNode;
        FUN_141602850(pData) = pNewNode;
        FUN_141604630(pData) = pNewNode;
    }
    else if (bAddLeft)
    {
        pWhere->_Left = pNewNode;
        if (pWhere == FUN_141602850(pData))
            FUN_141602850(pData) = pNewNode;
    }
    else
    {
        pWhere->_Right = pNewNode;
        if (pWhere == FUN_141604630(pData))
            FUN_141604630(pData) = pNewNode;
    }
    for (Unk_TreeNode* pNode2 = pNewNode; pNode2->_Parent->_Color == Unk_TreeRed;)
    {
        if (pNode2->_Parent == pNode2->_Parent->_Parent->_Left)
        {
            pWhere = pNode2->_Parent->_Parent->_Right;
            if (pWhere->_Color == Unk_TreeRed)
            {
                pNode2->_Parent->_Color = Unk_TreeBlack;
                pWhere->_Color = Unk_TreeBlack;
                pNode2->_Parent->_Parent->_Color = Unk_TreeRed;
                pNode2 = pNode2->_Parent->_Parent;
            }
            else
            {
                if (pNode2 == pNode2->_Parent->_Right)
                {
                    pNode2 = pNode2->_Parent;
                    FUN_141602860(pData, pNode2);
                }
                pNode2->_Parent->_Color = Unk_TreeBlack;
                pNode2->_Parent->_Parent->_Color = Unk_TreeRed;
                FUN_141604670(pData, pNode2->_Parent->_Parent);
            }
        }
        else
        {
            pWhere = pNode2->_Parent->_Parent->_Left;
            if (pWhere->_Color == Unk_TreeRed)
            {
                pNode2->_Parent->_Color = Unk_TreeBlack;
                pWhere->_Color = Unk_TreeBlack;
                pNode2->_Parent->_Parent->_Color = Unk_TreeRed;
                pNode2 = pNode2->_Parent->_Parent;
            }
            else
            {
                if (pNode2 == pNode2->_Parent->_Left)
                {
                    pNode2 = pNode2->_Parent;
                    FUN_141604670(pData, pNode2);
                }
                pNode2->_Parent->_Color = Unk_TreeBlack;
                pNode2->_Parent->_Parent->_Color = Unk_TreeRed;
                FUN_141602860(pData, pNode2->_Parent->_Parent);
            }
        }
    }
    FUN_141604650(pData)->_Color = Unk_TreeBlack;
    FUN_1415e5cf0(pResult, pNewNode, FUN_1415e1750(pData));
    return pResult;
}

// @0x1415db990
// MS2-FUNCTIONAL: free-function form of std::_Tree::_Insert_nohint (explicit result pointer, same catch-all that frees
// the node and rethrows); not tuned against the exe.
Unk_TreePairib* FUN_1415db990(void* pThis, Unk_TreePairib* pResult, bool bLeftish, const unsigned char* pVal, Unk_TreeNode* pNewNode)
{
    Unk_TreeData* pData = FUN_141600e10(pThis);
    try
    {
        Unk_TreeNode* pWhere = pData->m_pHead;
        Unk_TreeNode* pTry = pWhere->_Parent;
        bool bAddLeft = true;
        while (!pTry->_Isnil)
        {
            pWhere = pTry;
            if (bLeftish)
                bAddLeft = !FUN_141602090(pThis)(FUN_141602800(pThis, pTry), FUN_141602830(pThis, pVal));
            else
                bAddLeft = FUN_141602090(pThis)(FUN_141602830(pThis, pVal), FUN_141602800(pThis, pTry));
            pTry = bAddLeft ? pTry->_Left : pTry->_Right;
        }
        Unk_TreeIter where;
        FUN_1415e5cf0(&where, pWhere, FUN_1415e1750(pData));
        if (bAddLeft)
        {
            Unk_TreeIter begin;
            if (FUN_1415f2a60(&where, FUN_141607780(pThis, &begin)))
            {
                Unk_TreeIter it;
                bool bInserted = true;
                FUN_1415ce4c0(pResult, FUN_1415db630(pThis, &it, true, pWhere, FUN_1415e4bd0(pVal), pNewNode), &bInserted);
                return pResult;
            }
            FUN_1415f46a0(&where);
        }
        if (FUN_141602090(pThis)(FUN_141602800(pThis, where.m_pNode), FUN_141602830(pThis, pVal)))
        {
            Unk_TreeIter it;
            bool bInserted = true;
            FUN_1415ce4c0(pResult, FUN_1415db630(pThis, &it, bAddLeft, pWhere, FUN_1415e4bd0(pVal), pNewNode), &bInserted);
            return pResult;
        }
        FUN_141600710(pThis, pNewNode);
        bool bInserted = false;
        FUN_1415ce380(pResult, &where, &bInserted);
        return pResult;
    }
    catch (...)
    {
        FUN_141600710(pThis, pNewNode);
        throw;
    }
}

// @0x1415dbda0
void* FUN_1415dbda0(void* p)
{
    return p;
}

// @0x1415dbdb0
// std::_Tree::_Lbound: the leftmost node not less than the key
Unk_TreeNode* FUN_1415dbdb0(void* pThis, const unsigned char& keyVal)
{
    Unk_TreeNode* pWhere = FUN_141600e40(pThis);
    Unk_TreeNode* pNode = pWhere->_Parent;
    while (!pNode->_Isnil)
    {
        if (FUN_1415ffc30(pThis, FUN_141602800(pThis, pNode), keyVal))
        {
            pNode = pNode->_Right;
        }
        else
        {
            pWhere = pNode;
            pNode = pNode->_Left;
        }
    }
    return pWhere;
}

// @0x1415dbe50
void FUN_1415dbe50(void* const& pFirst, void* const& pLast)
{
    FUN_1415dbe80(pFirst, pLast, std::input_iterator_tag());
}

// @0x1415dbe80
void FUN_1415dbe80(void* const& pFirst, void* const& pLast, std::input_iterator_tag)
{
}

// @0x1415dbe90
void FUN_1415dbe90(void* const& pFirst, void* const& pLast)
{
    FUN_1415dbec0(pFirst, pLast, std::input_iterator_tag());
}

// @0x1415dbec0
void FUN_1415dbec0(void* const& pFirst, void* const& pLast, std::input_iterator_tag)
{
}

// @0x1415dbed0
void FUN_1415dbed0(void* const& pFirst, void* const& pLast)
{
    FUN_1415dbf00(pFirst, pLast, std::input_iterator_tag());
}

// @0x1415dbf00
void FUN_1415dbf00(void* const& pFirst, void* const& pLast, std::input_iterator_tag)
{
}

// @0x1415dbf10
void FUN_1415dbf10(void* const& pFirst, void* const& pLast)
{
    FUN_1415dbf40(pFirst, pLast, std::input_iterator_tag());
}

// @0x1415dbf40
void FUN_1415dbf40(void* const& pFirst, void* const& pLast, std::input_iterator_tag)
{
}

// @0x1415dbf50
void FUN_1415dbf50(void* const& pFirst, void* const& pLast)
{
    FUN_1415dbf80(pFirst, pLast, std::input_iterator_tag());
}

// @0x1415dbf80
void FUN_1415dbf80(void* const& pFirst, void* const& pLast, std::input_iterator_tag)
{
}

// @0x1415dbf90
void FUN_1415dbf90(void* const& pFirst, void* const& pLast)
{
    FUN_1415dbfc0(pFirst, pLast, std::input_iterator_tag());
}

// @0x1415dbfc0
void FUN_1415dbfc0(void* const& pFirst, void* const& pLast, std::input_iterator_tag)
{
}

// @0x1415dbfd0
void FUN_1415dbfd0(void* const& pFirst, void* const& pLast)
{
    FUN_1415dc000(pFirst, pLast, std::input_iterator_tag());
}

// @0x1415dc000
void FUN_1415dc000(void* const& pFirst, void* const& pLast, std::input_iterator_tag)
{
}

// @0x1415dc010
void FUN_1415dc010(void* const& pFirst, void* const& pLast)
{
    FUN_1415dc040(pFirst, pLast, std::input_iterator_tag());
}

// @0x1415dc040
void FUN_1415dc040(void* const& pFirst, void* const& pLast, std::input_iterator_tag)
{
}

// @0x1415dc050
void FUN_1415dc050(void* const& pFirst, void* const& pLast)
{
    FUN_1415dc080(pFirst, pLast, std::input_iterator_tag());
}

// @0x1415dc080
void FUN_1415dc080(void* const& pFirst, void* const& pLast, std::input_iterator_tag)
{
}

// @0x1415dc090
void FUN_1415dc090(void* const& pFirst, void* const& pLast)
{
    FUN_1415dc0c0(pFirst, pLast, std::input_iterator_tag());
}

// @0x1415dc0c0
void FUN_1415dc0c0(void* const& pFirst, void* const& pLast, std::input_iterator_tag)
{
}

// @0x1415dc0d0
void FUN_1415dc0d0(void* const& pFirst, void* const& pLast)
{
    FUN_1415dc100(pFirst, pLast, std::input_iterator_tag());
}

// @0x1415dc100
void FUN_1415dc100(void* const& pFirst, void* const& pLast, std::input_iterator_tag)
{
}

// @0x1415dc110
void FUN_1415dc110(void* const& pFirst, void* const& pLast)
{
    FUN_1415dc140(pFirst, pLast, std::input_iterator_tag());
}

// @0x1415dc140
void FUN_1415dc140(void* const& pFirst, void* const& pLast, std::input_iterator_tag)
{
}

// @0x1415dc150
void FUN_1415dc150(void* const& pFirst, void* const& pLast)
{
    FUN_1415dc180(pFirst, pLast, std::input_iterator_tag());
}

// @0x1415dc180
void FUN_1415dc180(void* const& pFirst, void* const& pLast, std::input_iterator_tag)
{
}

// @0x1415dc190
void FUN_1415dc190(void* const& pFirst, void* const& pLast)
{
    FUN_1415dc1c0(pFirst, pLast, std::input_iterator_tag());
}

// @0x1415dc1c0
void FUN_1415dc1c0(void* const& pFirst, void* const& pLast, std::input_iterator_tag)
{
}

// @0x1415dc1d0
void FUN_1415dc1d0(void* const& pFirst, void* const& pLast)
{
    FUN_1415dc200(pFirst, pLast, std::input_iterator_tag());
}

// @0x1415dc200
void FUN_1415dc200(void* const& pFirst, void* const& pLast, std::input_iterator_tag)
{
}

// @0x1415dc210
void FUN_1415dc210(void* const& pFirst, void* const& pLast)
{
    FUN_1415dc240(pFirst, pLast, std::input_iterator_tag());
}

// @0x1415dc240
void FUN_1415dc240(void* const& pFirst, void* const& pLast, std::input_iterator_tag)
{
}

// @0x1415dc250
void FUN_1415dc250(void* const& pFirst, void* const& pLast)
{
    FUN_1415dc280(pFirst, pLast, std::input_iterator_tag());
}

// @0x1415dc280
void FUN_1415dc280(void* const& pFirst, void* const& pLast, std::input_iterator_tag)
{
}

// @0x1415dc290
std::_General_ptr_iterator_tag FUN_1415dc290(Unk_StlElem<0x30>* const& pSrc, Unk_StlElem<0x30>* const& pDest)
{
    return {};
}

// @0x1415dc2c0
std::_Really_trivial_ptr_iterator_tag FUN_1415dc2c0(Unk_StlElem<0x10>* const& pSrc, Unk_StlElem<0x10>* const& pDest)
{
    return {};
}

// @0x1415dc2e0
std::_Really_trivial_ptr_iterator_tag FUN_1415dc2e0(Unk_StlElem<0x18>* const& pSrc, Unk_StlElem<0x18>* const& pDest)
{
    return {};
}

// @0x1415dc300
std::_General_ptr_iterator_tag FUN_1415dc300(Unk_StlElem<0x58>* const& pSrc, Unk_StlElem<0x58>* const& pDest)
{
    return {};
}

// @0x1415dc330
std::_General_ptr_iterator_tag FUN_1415dc330(Unk_StlElem<0x30>* const& pSrc, Unk_StlElem<0x30>* const& pDest)
{
    return {};
}

// @0x1415dc360
std::_General_ptr_iterator_tag FUN_1415dc360(Unk_StlElem<0x98>* const& pSrc, Unk_StlElem<0x98>* const& pDest)
{
    return {};
}

// @0x1415dc390
std::_General_ptr_iterator_tag FUN_1415dc390(Unk_StlElem<0x220>* const& pSrc, Unk_StlElem<0x220>* const& pDest)
{
    return {};
}

// @0x1415dc3c0
std::_General_ptr_iterator_tag FUN_1415dc3c0(Unk_StlElem<0x128>* const& pSrc, Unk_StlElem<0x128>* const& pDest)
{
    return {};
}

// @0x1415dc3f0
std::_General_ptr_iterator_tag FUN_1415dc3f0(Unk_StlElem<0x118>* const& pSrc, Unk_StlElem<0x118>* const& pDest)
{
    return {};
}

// @0x1415dc420
std::_General_ptr_iterator_tag FUN_1415dc420(Unk_StlElem<0x580>* const& pSrc, Unk_StlElem<0x580>* const& pDest)
{
    return {};
}

// @0x1415dc450
std::_General_ptr_iterator_tag FUN_1415dc450(Unk_StlElem<0x18>* const& pSrc, Unk_StlElem<0x18>* const& pDest)
{
    return {};
}

// @0x1415dc480
std::_General_ptr_iterator_tag FUN_1415dc480(Unk_StlElem<0x14a8>* const& pSrc, Unk_StlElem<0x14a8>* const& pDest)
{
    return {};
}

// @0x1415dc4b0
std::_General_ptr_iterator_tag FUN_1415dc4b0(Unk_StlElem<0x18>* const& pSrc, Unk_StlElem<0x18>* const& pDest)
{
    return {};
}

// @0x1415dc4e0
std::_General_ptr_iterator_tag FUN_1415dc4e0(Unk_StlElem<0x190>* const& pSrc, Unk_StlElem<0x190>* const& pDest)
{
    return {};
}

// @0x1415dc510
std::_General_ptr_iterator_tag FUN_1415dc510(Unk_StlElem<0xb8>* const& pSrc, Unk_StlElem<0xb8>* const& pDest)
{
    return {};
}

// @0x1415dc540
std::_General_ptr_iterator_tag FUN_1415dc540(Unk_StlElem<0x58>* const& pSrc, Unk_StlElem<0x58>* const& pDest)
{
    return {};
}

// @0x1415dc570
std::_General_ptr_iterator_tag FUN_1415dc570(Unk_StlElem<0xae8>* const& pSrc, Unk_StlElem<0xae8>* const& pDest)
{
    return {};
}

// @0x1415dc5a0
std::_General_ptr_iterator_tag FUN_1415dc5a0(Unk_StlElem<0xec8>* const& pSrc, Unk_StlElem<0xec8>* const& pDest)
{
    return {};
}

// @0x1415dc5d0
std::_General_ptr_iterator_tag FUN_1415dc5d0(Unk_StlElem<0xc8>* const& pSrc, Unk_StlElem<0xc8>* const& pDest)
{
    return {};
}

// @0x1415dc600
std::_General_ptr_iterator_tag FUN_1415dc600(Unk_StlElem<0xf8>* const& pSrc, Unk_StlElem<0xf8>* const& pDest)
{
    return {};
}

// @0x1415dc630
std::_General_ptr_iterator_tag FUN_1415dc630(Unk_StlElem<0x490>* const& pSrc, Unk_StlElem<0x490>* const& pDest)
{
    return {};
}

// @0x1415dc660
std::_General_ptr_iterator_tag FUN_1415dc660(Unk_StlElem<0x20>* const& pSrc, Unk_StlElem<0x20>* const& pDest)
{
    return {};
}

// @0x1415dc690
std::_Really_trivial_ptr_iterator_tag FUN_1415dc690(Unk_StlElem<0x10>* const& pSrc, Unk_StlElem<0x10>* const& pDest)
{
    return {};
}

// @0x1415dc6b0
std::_Really_trivial_ptr_iterator_tag FUN_1415dc6b0(Unk_StlElem<0x18>* const& pSrc, Unk_StlElem<0x18>* const& pDest)
{
    return {};
}

// @0x1415dc6d0
std::_General_ptr_iterator_tag FUN_1415dc6d0(Unk_StlElem<0x58>* const& pSrc, Unk_StlElem<0x58>* const& pDest)
{
    return {};
}

// @0x1415dc700
std::_General_ptr_iterator_tag FUN_1415dc700(Unk_StlElem<0x30>* const& pSrc, Unk_StlElem<0x30>* const& pDest)
{
    return {};
}

// @0x1415dc730
std::_General_ptr_iterator_tag FUN_1415dc730(Unk_StlElem<0x98>* const& pSrc, Unk_StlElem<0x98>* const& pDest)
{
    return {};
}

// @0x1415dc760
std::_General_ptr_iterator_tag FUN_1415dc760(Unk_StlElem<0x220>* const& pSrc, Unk_StlElem<0x220>* const& pDest)
{
    return {};
}

// @0x1415dc790
std::_General_ptr_iterator_tag FUN_1415dc790(Unk_StlElem<0x128>* const& pSrc, Unk_StlElem<0x128>* const& pDest)
{
    return {};
}

// @0x1415dc7c0
std::_General_ptr_iterator_tag FUN_1415dc7c0(Unk_StlElem<0x118>* const& pSrc, Unk_StlElem<0x118>* const& pDest)
{
    return {};
}

// @0x1415dc7f0
std::_General_ptr_iterator_tag FUN_1415dc7f0(Unk_StlElem<0xe0>* const& pSrc, Unk_StlElem<0xe0>* const& pDest)
{
    return {};
}

// @0x1415dc820
std::_General_ptr_iterator_tag FUN_1415dc820(Unk_StlElem<0x580>* const& pSrc, Unk_StlElem<0x580>* const& pDest)
{
    return {};
}

// @0x1415dc850
std::_General_ptr_iterator_tag FUN_1415dc850(Unk_StlElem<0x18>* const& pSrc, Unk_StlElem<0x18>* const& pDest)
{
    return {};
}

// @0x1415dc880
std::_General_ptr_iterator_tag FUN_1415dc880(Unk_StlElem<0x14a8>* const& pSrc, Unk_StlElem<0x14a8>* const& pDest)
{
    return {};
}

// @0x1415dc8b0
std::_General_ptr_iterator_tag FUN_1415dc8b0(Unk_StlElem<0x18>* const& pSrc, Unk_StlElem<0x18>* const& pDest)
{
    return {};
}

// @0x1415dc8e0
std::_General_ptr_iterator_tag FUN_1415dc8e0(Unk_StlElem<0x190>* const& pSrc, Unk_StlElem<0x190>* const& pDest)
{
    return {};
}

// @0x1415dc910
std::_General_ptr_iterator_tag FUN_1415dc910(Unk_StlElem<0xb8>* const& pSrc, Unk_StlElem<0xb8>* const& pDest)
{
    return {};
}

// @0x1415dc940
std::_General_ptr_iterator_tag FUN_1415dc940(Unk_StlElem<0x58>* const& pSrc, Unk_StlElem<0x58>* const& pDest)
{
    return {};
}

// @0x1415dc970
std::_General_ptr_iterator_tag FUN_1415dc970(Unk_StlElem<0x68>* const& pSrc, Unk_StlElem<0x68>* const& pDest)
{
    return {};
}

// @0x1415dc9a0
std::_General_ptr_iterator_tag FUN_1415dc9a0(Unk_StlElem<0xae8>* const& pSrc, Unk_StlElem<0xae8>* const& pDest)
{
    return {};
}

// @0x1415dc9d0
std::_General_ptr_iterator_tag FUN_1415dc9d0(Unk_StlElem<0xec8>* const& pSrc, Unk_StlElem<0xec8>* const& pDest)
{
    return {};
}

// @0x1415dca00
std::_General_ptr_iterator_tag FUN_1415dca00(Unk_StlElem<0xc8>* const& pSrc, Unk_StlElem<0xc8>* const& pDest)
{
    return {};
}

// @0x1415dca30
std::_General_ptr_iterator_tag FUN_1415dca30(Unk_StlElem<0xf8>* const& pSrc, Unk_StlElem<0xf8>* const& pDest)
{
    return {};
}

// @0x1415dca60
std::_General_ptr_iterator_tag FUN_1415dca60(Unk_StlElem<0x490>* const& pSrc, Unk_StlElem<0x490>* const& pDest)
{
    return {};
}

// @0x1415dca90
std::_General_ptr_iterator_tag FUN_1415dca90(Unk_StlElem<0x20>* const& pSrc, Unk_StlElem<0x20>* const& pDest)
{
    return {};
}

// @0x1415dcac0
void FUN_1415dcac0(Unk_StlElem<0x10>*& pIt, Unk_StlElem<0x10>* const pUnwrapped)
{
    pIt = pUnwrapped;
}

// @0x1415dcae0
void FUN_1415dcae0(Unk_StlElem<0x18>*& pIt, Unk_StlElem<0x18>* const pUnwrapped)
{
    pIt = pUnwrapped;
}

// @0x1415dcb00
// std::_Seek_wrapped for a checked iterator: _It._Seek_to(_UIt)
void FUN_1415dcb00(void* pIt, void* const& pUnwrapped)
{
    FUN_141604750(pIt, pUnwrapped);
}

// std::string find_first_not_of / find_first_of workers (bitmap and serial)
template size_t std::_Traits_find_first_not_of<std::char_traits<char>>(const char* const, const size_t, const size_t, const char* const, const size_t, std::true_type) noexcept;
template size_t std::_Traits_find_first_not_of<std::char_traits<char>>(const char* const, const size_t, const size_t, const char* const, const size_t, std::false_type) noexcept;
template size_t std::_Traits_find_first_of<std::char_traits<char>>(const char* const, const size_t, const size_t, const char* const, const size_t, std::true_type) noexcept;
template size_t std::_Traits_find_first_of<std::char_traits<char>>(const char* const, const size_t, const size_t, const char* const, const size_t, std::false_type) noexcept;

// @0x1415dcb30
void FUN_1415dcb30(Unk_StlElem<0x58>*& pIt, Unk_StlElem<0x58>* const pUnwrapped)
{
    pIt = pUnwrapped;
}

// @0x1415dcb50
void FUN_1415dcb50(Unk_StlElem<0x30>*& pIt, Unk_StlElem<0x30>* const pUnwrapped)
{
    pIt = pUnwrapped;
}

// @0x1415dcb70
void FUN_1415dcb70(Unk_StlElem<0x98>*& pIt, Unk_StlElem<0x98>* const pUnwrapped)
{
    pIt = pUnwrapped;
}

// @0x1415dcb90
void FUN_1415dcb90(Unk_StlElem<0x220>*& pIt, Unk_StlElem<0x220>* const pUnwrapped)
{
    pIt = pUnwrapped;
}

// @0x1415dcbb0
void FUN_1415dcbb0(Unk_StlElem<0x128>*& pIt, Unk_StlElem<0x128>* const pUnwrapped)
{
    pIt = pUnwrapped;
}

// @0x1415dcbd0
void FUN_1415dcbd0(Unk_StlElem<0x118>*& pIt, Unk_StlElem<0x118>* const pUnwrapped)
{
    pIt = pUnwrapped;
}

// @0x1415dcbf0
void FUN_1415dcbf0(Unk_StlElem<0xe0>*& pIt, Unk_StlElem<0xe0>* const pUnwrapped)
{
    pIt = pUnwrapped;
}

// @0x1415dcc10
void FUN_1415dcc10(Unk_StlElem<0x580>*& pIt, Unk_StlElem<0x580>* const pUnwrapped)
{
    pIt = pUnwrapped;
}

// @0x1415dcc30
void FUN_1415dcc30(Unk_StlElem<0x18>*& pIt, Unk_StlElem<0x18>* const pUnwrapped)
{
    pIt = pUnwrapped;
}

// @0x1415dcc50
void FUN_1415dcc50(Unk_StlElem<0x14a8>*& pIt, Unk_StlElem<0x14a8>* const pUnwrapped)
{
    pIt = pUnwrapped;
}

// @0x1415dcc70
void FUN_1415dcc70(Unk_StlElem<0x18>*& pIt, Unk_StlElem<0x18>* const pUnwrapped)
{
    pIt = pUnwrapped;
}

// @0x1415dcc90
void FUN_1415dcc90(Unk_StlElem<0x190>*& pIt, Unk_StlElem<0x190>* const pUnwrapped)
{
    pIt = pUnwrapped;
}

// @0x1415dccb0
void FUN_1415dccb0(Unk_StlElem<0xb8>*& pIt, Unk_StlElem<0xb8>* const pUnwrapped)
{
    pIt = pUnwrapped;
}

// @0x1415dccd0
void FUN_1415dccd0(Unk_StlElem<0x58>*& pIt, Unk_StlElem<0x58>* const pUnwrapped)
{
    pIt = pUnwrapped;
}

// @0x1415dccf0
void FUN_1415dccf0(Unk_StlElem<0x68>*& pIt, Unk_StlElem<0x68>* const pUnwrapped)
{
    pIt = pUnwrapped;
}

// @0x1415dcd10
void FUN_1415dcd10(Unk_StlElem<0xae8>*& pIt, Unk_StlElem<0xae8>* const pUnwrapped)
{
    pIt = pUnwrapped;
}

// @0x1415dcd30
void FUN_1415dcd30(Unk_StlElem<0xec8>*& pIt, Unk_StlElem<0xec8>* const pUnwrapped)
{
    pIt = pUnwrapped;
}

// @0x1415dcd50
void FUN_1415dcd50(Unk_StlElem<0xc8>*& pIt, Unk_StlElem<0xc8>* const pUnwrapped)
{
    pIt = pUnwrapped;
}

// @0x1415dcd70
void FUN_1415dcd70(Unk_StlElem<0xf8>*& pIt, Unk_StlElem<0xf8>* const pUnwrapped)
{
    pIt = pUnwrapped;
}

// @0x1415dcd90
void FUN_1415dcd90(Unk_StlElem<0x490>*& pIt, Unk_StlElem<0x490>* const pUnwrapped)
{
    pIt = pUnwrapped;
}

// @0x1415dcdb0
void FUN_1415dcdb0(Unk_StlElem<0x20>*& pIt, Unk_StlElem<0x20>* const pUnwrapped)
{
    pIt = pUnwrapped;
}

// @0x1415dd240
Unk_StlElem<0x10>* FUN_1415dd240(void* pThis, Unk_StlElem<0x10>* pFirst, Unk_StlElem<0x10>* pLast, Unk_StlElem<0x10>* pDest)
{
    return FUN_1415dd930(pFirst, pLast, pDest, FUN_141601ad0(pThis));
}

// @0x1415dd280
Unk_StlElem<0x18>* FUN_1415dd280(void* pThis, Unk_StlElem<0x18>* pFirst, Unk_StlElem<0x18>* pLast, Unk_StlElem<0x18>* pDest)
{
    return FUN_1415dd9e0(pFirst, pLast, pDest, FUN_141601b10(pThis));
}

// @0x1415dd2c0
Unk_StlElem<0x58>* FUN_1415dd2c0(void* pThis, Unk_StlElem<0x58>* pFirst, Unk_StlElem<0x58>* pLast, Unk_StlElem<0x58>* pDest)
{
    return FUN_1415dda90(pFirst, pLast, pDest, FUN_141601b50(pThis));
}

// @0x1415dd300
Unk_StlElem<0x30>* FUN_1415dd300(void* pThis, Unk_StlElem<0x30>* pFirst, Unk_StlElem<0x30>* pLast, Unk_StlElem<0x30>* pDest)
{
    return FUN_1415ddb60(pFirst, pLast, pDest, FUN_141601b90(pThis));
}

// @0x1415dd340
Unk_StlElem<0x98>* FUN_1415dd340(void* pThis, Unk_StlElem<0x98>* pFirst, Unk_StlElem<0x98>* pLast, Unk_StlElem<0x98>* pDest)
{
    return FUN_1415ddc30(pFirst, pLast, pDest, FUN_141601bd0(pThis));
}

// @0x1415dd380
Unk_StlElem<0x220>* FUN_1415dd380(void* pThis, Unk_StlElem<0x220>* pFirst, Unk_StlElem<0x220>* pLast, Unk_StlElem<0x220>* pDest)
{
    return FUN_1415ddd00(pFirst, pLast, pDest, FUN_141601c10(pThis));
}

// @0x1415dd3c0
Unk_StlElem<0x128>* FUN_1415dd3c0(void* pThis, Unk_StlElem<0x128>* pFirst, Unk_StlElem<0x128>* pLast, Unk_StlElem<0x128>* pDest)
{
    return FUN_1415dddd0(pFirst, pLast, pDest, FUN_141601c50(pThis));
}

// @0x1415dd400
Unk_StlElem<0x118>* FUN_1415dd400(void* pThis, Unk_StlElem<0x118>* pFirst, Unk_StlElem<0x118>* pLast, Unk_StlElem<0x118>* pDest)
{
    return FUN_1415ddea0(pFirst, pLast, pDest, FUN_141601c90(pThis));
}

// @0x1415dd440
Unk_StlElem<0x580>* FUN_1415dd440(void* pThis, Unk_StlElem<0x580>* pFirst, Unk_StlElem<0x580>* pLast, Unk_StlElem<0x580>* pDest)
{
    return FUN_1415ddf70(pFirst, pLast, pDest, FUN_141601d10(pThis));
}

// @0x1415dd480
Unk_StlElem<0x18>* FUN_1415dd480(void* pThis, Unk_StlElem<0x18>* pFirst, Unk_StlElem<0x18>* pLast, Unk_StlElem<0x18>* pDest)
{
    return FUN_1415de040(pFirst, pLast, pDest, FUN_141601d50(pThis));
}

// @0x1415dd4c0
Unk_StlElem<0x14a8>* FUN_1415dd4c0(void* pThis, Unk_StlElem<0x14a8>* pFirst, Unk_StlElem<0x14a8>* pLast, Unk_StlElem<0x14a8>* pDest)
{
    return FUN_1415de110(pFirst, pLast, pDest, FUN_141601d90(pThis));
}

// @0x1415dd500
Unk_StlElem<0x18>* FUN_1415dd500(void* pThis, Unk_StlElem<0x18>* pFirst, Unk_StlElem<0x18>* pLast, Unk_StlElem<0x18>* pDest)
{
    return FUN_1415de1e0(pFirst, pLast, pDest, FUN_141601dd0(pThis));
}

// @0x1415dd540
Unk_StlElem<0x190>* FUN_1415dd540(void* pThis, Unk_StlElem<0x190>* pFirst, Unk_StlElem<0x190>* pLast, Unk_StlElem<0x190>* pDest)
{
    return FUN_1415de2b0(pFirst, pLast, pDest, FUN_141601e10(pThis));
}

// @0x1415dd580
Unk_StlElem<0xb8>* FUN_1415dd580(void* pThis, Unk_StlElem<0xb8>* pFirst, Unk_StlElem<0xb8>* pLast, Unk_StlElem<0xb8>* pDest)
{
    return FUN_1415de380(pFirst, pLast, pDest, FUN_141601e50(pThis));
}

// @0x1415dd5c0
Unk_StlElem<0x58>* FUN_1415dd5c0(void* pThis, Unk_StlElem<0x58>* pFirst, Unk_StlElem<0x58>* pLast, Unk_StlElem<0x58>* pDest)
{
    return FUN_1415de450(pFirst, pLast, pDest, FUN_141601e90(pThis));
}

// @0x1415dd600
Unk_StlElem<0xae8>* FUN_1415dd600(void* pThis, Unk_StlElem<0xae8>* pFirst, Unk_StlElem<0xae8>* pLast, Unk_StlElem<0xae8>* pDest)
{
    return FUN_1415de520(pFirst, pLast, pDest, FUN_141601f10(pThis));
}

// @0x1415dd640
Unk_StlElem<0xec8>* FUN_1415dd640(void* pThis, Unk_StlElem<0xec8>* pFirst, Unk_StlElem<0xec8>* pLast, Unk_StlElem<0xec8>* pDest)
{
    return FUN_1415de5f0(pFirst, pLast, pDest, FUN_141601f50(pThis));
}

// @0x1415dd680
Unk_StlElem<0xc8>* FUN_1415dd680(void* pThis, Unk_StlElem<0xc8>* pFirst, Unk_StlElem<0xc8>* pLast, Unk_StlElem<0xc8>* pDest)
{
    return FUN_1415de6c0(pFirst, pLast, pDest, FUN_141601f90(pThis));
}

// @0x1415dd6c0
Unk_StlElem<0xf8>* FUN_1415dd6c0(void* pThis, Unk_StlElem<0xf8>* pFirst, Unk_StlElem<0xf8>* pLast, Unk_StlElem<0xf8>* pDest)
{
    return FUN_1415de790(pFirst, pLast, pDest, FUN_141601fd0(pThis));
}

// @0x1415dd700
Unk_StlElem<0x490>* FUN_1415dd700(void* pThis, Unk_StlElem<0x490>* pFirst, Unk_StlElem<0x490>* pLast, Unk_StlElem<0x490>* pDest)
{
    return FUN_1415de860(pFirst, pLast, pDest, FUN_141602010(pThis));
}

// @0x1415dd740
Unk_StlElem<0x20>* FUN_1415dd740(void* pThis, Unk_StlElem<0x20>* pFirst, Unk_StlElem<0x20>* pLast, Unk_StlElem<0x20>* pDest)
{
    return FUN_1415de930(pFirst, pLast, pDest, FUN_141602050(pThis));
}

// @0x1415dd780
Unk_StlElem<0x30>* FUN_1415dd780(void* pThis, Unk_StlElem<0x30>* pFirst, Unk_StlElem<0x30>* pLast, Unk_StlElem<0x30>* pDest)
{
    return FUN_1415dea00(pFirst, pLast, pDest, FUN_141601e50(pThis));
}

// @0x1415dd7c0
Unk_StlElem<0x10>* FUN_1415dd7c0(Unk_StlElem<0x10>* p)
{
    return p;
}

// @0x1415dd7d0
Unk_StlElem<0x18>* FUN_1415dd7d0(Unk_StlElem<0x18>* p)
{
    return p;
}

// @0x1415dd7e0
Unk_StlElem<0x58>* FUN_1415dd7e0(Unk_StlElem<0x58>* p)
{
    return p;
}

// @0x1415dd7f0
Unk_StlElem<0x30>* FUN_1415dd7f0(Unk_StlElem<0x30>* p)
{
    return p;
}

// @0x1415dd800
Unk_StlElem<0x98>* FUN_1415dd800(Unk_StlElem<0x98>* p)
{
    return p;
}

// @0x1415dd810
Unk_StlElem<0x220>* FUN_1415dd810(Unk_StlElem<0x220>* p)
{
    return p;
}

// @0x1415dd820
Unk_StlElem<0x128>* FUN_1415dd820(Unk_StlElem<0x128>* p)
{
    return p;
}

// @0x1415dd830
Unk_StlElem<0x118>* FUN_1415dd830(Unk_StlElem<0x118>* p)
{
    return p;
}

// @0x1415dd840
Unk_StlElem<0xe0>* FUN_1415dd840(Unk_StlElem<0xe0>* p)
{
    return p;
}

// @0x1415dd850
Unk_StlElem<0x580>* FUN_1415dd850(Unk_StlElem<0x580>* p)
{
    return p;
}

// @0x1415dd860
Unk_StlElem<0x18>* FUN_1415dd860(Unk_StlElem<0x18>* p)
{
    return p;
}

// @0x1415dd870
Unk_StlElem<0x14a8>* FUN_1415dd870(Unk_StlElem<0x14a8>* p)
{
    return p;
}

// @0x1415dd880
Unk_StlElem<0x18>* FUN_1415dd880(Unk_StlElem<0x18>* p)
{
    return p;
}

// @0x1415dd890
Unk_StlElem<0x190>* FUN_1415dd890(Unk_StlElem<0x190>* p)
{
    return p;
}

// @0x1415dd8a0
Unk_StlElem<0xb8>* FUN_1415dd8a0(Unk_StlElem<0xb8>* p)
{
    return p;
}

// @0x1415dd8b0
Unk_StlElem<0x58>* FUN_1415dd8b0(Unk_StlElem<0x58>* p)
{
    return p;
}

// @0x1415dd8c0
Unk_StlElem<0x68>* FUN_1415dd8c0(Unk_StlElem<0x68>* p)
{
    return p;
}

// @0x1415dd8d0
Unk_StlElem<0xae8>* FUN_1415dd8d0(Unk_StlElem<0xae8>* p)
{
    return p;
}

// @0x1415dd8e0
Unk_StlElem<0xec8>* FUN_1415dd8e0(Unk_StlElem<0xec8>* p)
{
    return p;
}

// @0x1415dd8f0
Unk_StlElem<0xc8>* FUN_1415dd8f0(Unk_StlElem<0xc8>* p)
{
    return p;
}

// @0x1415dd900
Unk_StlElem<0xf8>* FUN_1415dd900(Unk_StlElem<0xf8>* p)
{
    return p;
}

// @0x1415dd910
Unk_StlElem<0x490>* FUN_1415dd910(Unk_StlElem<0x490>* p)
{
    return p;
}

// @0x1415dd920
Unk_StlElem<0x20>* FUN_1415dd920(Unk_StlElem<0x20>* p)
{
    return p;
}

// @0x1415dd930
Unk_StlElem<0x10>* FUN_1415dd930(Unk_StlElem<0x10>* const pFirst, Unk_StlElem<0x10>* const pLast, Unk_StlElem<0x10>* pDest, void* pAl)
{
    Unk_StlElem<0x10>* const pUFirst = FUN_1415da9f0(pFirst);
    Unk_StlElem<0x10>* const pULast = FUN_1415da9f0(pLast);
    Unk_StlElem<0x10>* const pUDest = FUN_1415dabc0(pDest, FUN_1415db1b0(pUFirst, pULast));
    FUN_1415dcac0(pDest, FUN_1415df610(pUFirst, pULast, pUDest, pAl, FUN_1415dc2c0(pUFirst, pUDest), std::true_type()));
    return pDest;
}

// @0x1415dd9e0
Unk_StlElem<0x18>* FUN_1415dd9e0(Unk_StlElem<0x18>* const pFirst, Unk_StlElem<0x18>* const pLast, Unk_StlElem<0x18>* pDest, void* pAl)
{
    Unk_StlElem<0x18>* const pUFirst = FUN_1415daa00(pFirst);
    Unk_StlElem<0x18>* const pULast = FUN_1415daa00(pLast);
    Unk_StlElem<0x18>* const pUDest = FUN_1415dabd0(pDest, FUN_1415db1e0(pUFirst, pULast));
    FUN_1415dcae0(pDest, FUN_1415df650(pUFirst, pULast, pUDest, pAl, FUN_1415dc2e0(pUFirst, pUDest), std::true_type()));
    return pDest;
}

// @0x1415dda90
Unk_StlElem<0x58>* FUN_1415dda90(Unk_StlElem<0x58>* const pFirst, Unk_StlElem<0x58>* const pLast, Unk_StlElem<0x58>* pDest, void* pAl)
{
    Unk_StlElem<0x58>* const pUFirst = FUN_1415daa70(pFirst);
    Unk_StlElem<0x58>* const pULast = FUN_1415daa70(pLast);
    Unk_StlElem<0x58>* const pUDest = FUN_1415dabe0(pDest, FUN_1415db210(pUFirst, pULast));
    FUN_1415dcb30(pDest, FUN_1415dead0(pUFirst, pULast, pUDest, pAl, FUN_1415dc300(pUFirst, pUDest), std::false_type()));
    return pDest;
}

// @0x1415ddb60
Unk_StlElem<0x30>* FUN_1415ddb60(Unk_StlElem<0x30>* const pFirst, Unk_StlElem<0x30>* const pLast, Unk_StlElem<0x30>* pDest, void* pAl)
{
    Unk_StlElem<0x30>* const pUFirst = FUN_1415daa80(pFirst);
    Unk_StlElem<0x30>* const pULast = FUN_1415daa80(pLast);
    Unk_StlElem<0x30>* const pUDest = FUN_1415dabf0(pDest, FUN_1415db240(pUFirst, pULast));
    FUN_1415dcb50(pDest, FUN_1415deb60(pUFirst, pULast, pUDest, pAl, FUN_1415dc330(pUFirst, pUDest), std::false_type()));
    return pDest;
}

// @0x1415ddc30
Unk_StlElem<0x98>* FUN_1415ddc30(Unk_StlElem<0x98>* const pFirst, Unk_StlElem<0x98>* const pLast, Unk_StlElem<0x98>* pDest, void* pAl)
{
    Unk_StlElem<0x98>* const pUFirst = FUN_1415daa90(pFirst);
    Unk_StlElem<0x98>* const pULast = FUN_1415daa90(pLast);
    Unk_StlElem<0x98>* const pUDest = FUN_1415dac00(pDest, FUN_1415db270(pUFirst, pULast));
    FUN_1415dcb70(pDest, FUN_1415debf0(pUFirst, pULast, pUDest, pAl, FUN_1415dc360(pUFirst, pUDest), std::false_type()));
    return pDest;
}

// @0x1415ddd00
Unk_StlElem<0x220>* FUN_1415ddd00(Unk_StlElem<0x220>* const pFirst, Unk_StlElem<0x220>* const pLast, Unk_StlElem<0x220>* pDest, void* pAl)
{
    Unk_StlElem<0x220>* const pUFirst = FUN_1415daaa0(pFirst);
    Unk_StlElem<0x220>* const pULast = FUN_1415daaa0(pLast);
    Unk_StlElem<0x220>* const pUDest = FUN_1415dac10(pDest, FUN_1415db2a0(pUFirst, pULast));
    FUN_1415dcb90(pDest, FUN_1415dec80(pUFirst, pULast, pUDest, pAl, FUN_1415dc390(pUFirst, pUDest), std::false_type()));
    return pDest;
}

// @0x1415dddd0
Unk_StlElem<0x128>* FUN_1415dddd0(Unk_StlElem<0x128>* const pFirst, Unk_StlElem<0x128>* const pLast, Unk_StlElem<0x128>* pDest, void* pAl)
{
    Unk_StlElem<0x128>* const pUFirst = FUN_1415daab0(pFirst);
    Unk_StlElem<0x128>* const pULast = FUN_1415daab0(pLast);
    Unk_StlElem<0x128>* const pUDest = FUN_1415dac20(pDest, FUN_1415db2d0(pUFirst, pULast));
    FUN_1415dcbb0(pDest, FUN_1415ded10(pUFirst, pULast, pUDest, pAl, FUN_1415dc3c0(pUFirst, pUDest), std::false_type()));
    return pDest;
}

// @0x1415ddea0
Unk_StlElem<0x118>* FUN_1415ddea0(Unk_StlElem<0x118>* const pFirst, Unk_StlElem<0x118>* const pLast, Unk_StlElem<0x118>* pDest, void* pAl)
{
    Unk_StlElem<0x118>* const pUFirst = FUN_1415daac0(pFirst);
    Unk_StlElem<0x118>* const pULast = FUN_1415daac0(pLast);
    Unk_StlElem<0x118>* const pUDest = FUN_1415dac30(pDest, FUN_1415db300(pUFirst, pULast));
    FUN_1415dcbd0(pDest, FUN_1415deda0(pUFirst, pULast, pUDest, pAl, FUN_1415dc3f0(pUFirst, pUDest), std::false_type()));
    return pDest;
}

// @0x1415ddf70
Unk_StlElem<0x580>* FUN_1415ddf70(Unk_StlElem<0x580>* const pFirst, Unk_StlElem<0x580>* const pLast, Unk_StlElem<0x580>* pDest, void* pAl)
{
    Unk_StlElem<0x580>* const pUFirst = FUN_1415daae0(pFirst);
    Unk_StlElem<0x580>* const pULast = FUN_1415daae0(pLast);
    Unk_StlElem<0x580>* const pUDest = FUN_1415dac50(pDest, FUN_1415db360(pUFirst, pULast));
    FUN_1415dcc10(pDest, FUN_1415dee30(pUFirst, pULast, pUDest, pAl, FUN_1415dc420(pUFirst, pUDest), std::false_type()));
    return pDest;
}

// @0x1415de040
Unk_StlElem<0x18>* FUN_1415de040(Unk_StlElem<0x18>* const pFirst, Unk_StlElem<0x18>* const pLast, Unk_StlElem<0x18>* pDest, void* pAl)
{
    Unk_StlElem<0x18>* const pUFirst = FUN_1415daaf0(pFirst);
    Unk_StlElem<0x18>* const pULast = FUN_1415daaf0(pLast);
    Unk_StlElem<0x18>* const pUDest = FUN_1415dac60(pDest, FUN_1415db390(pUFirst, pULast));
    FUN_1415dcc30(pDest, FUN_1415deec0(pUFirst, pULast, pUDest, pAl, FUN_1415dc450(pUFirst, pUDest), std::false_type()));
    return pDest;
}

// @0x1415de110
Unk_StlElem<0x14a8>* FUN_1415de110(Unk_StlElem<0x14a8>* const pFirst, Unk_StlElem<0x14a8>* const pLast, Unk_StlElem<0x14a8>* pDest, void* pAl)
{
    Unk_StlElem<0x14a8>* const pUFirst = FUN_1415dab00(pFirst);
    Unk_StlElem<0x14a8>* const pULast = FUN_1415dab00(pLast);
    Unk_StlElem<0x14a8>* const pUDest = FUN_1415dac70(pDest, FUN_1415db3c0(pUFirst, pULast));
    FUN_1415dcc50(pDest, FUN_1415def50(pUFirst, pULast, pUDest, pAl, FUN_1415dc480(pUFirst, pUDest), std::false_type()));
    return pDest;
}

// @0x1415de1e0
Unk_StlElem<0x18>* FUN_1415de1e0(Unk_StlElem<0x18>* const pFirst, Unk_StlElem<0x18>* const pLast, Unk_StlElem<0x18>* pDest, void* pAl)
{
    Unk_StlElem<0x18>* const pUFirst = FUN_1415dab10(pFirst);
    Unk_StlElem<0x18>* const pULast = FUN_1415dab10(pLast);
    Unk_StlElem<0x18>* const pUDest = FUN_1415dac80(pDest, FUN_1415db3f0(pUFirst, pULast));
    FUN_1415dcc70(pDest, FUN_1415defe0(pUFirst, pULast, pUDest, pAl, FUN_1415dc4b0(pUFirst, pUDest), std::false_type()));
    return pDest;
}

// @0x1415de2b0
Unk_StlElem<0x190>* FUN_1415de2b0(Unk_StlElem<0x190>* const pFirst, Unk_StlElem<0x190>* const pLast, Unk_StlElem<0x190>* pDest, void* pAl)
{
    Unk_StlElem<0x190>* const pUFirst = FUN_1415dab20(pFirst);
    Unk_StlElem<0x190>* const pULast = FUN_1415dab20(pLast);
    Unk_StlElem<0x190>* const pUDest = FUN_1415dac90(pDest, FUN_1415db420(pUFirst, pULast));
    FUN_1415dcc90(pDest, FUN_1415df070(pUFirst, pULast, pUDest, pAl, FUN_1415dc4e0(pUFirst, pUDest), std::false_type()));
    return pDest;
}

// @0x1415de380
Unk_StlElem<0xb8>* FUN_1415de380(Unk_StlElem<0xb8>* const pFirst, Unk_StlElem<0xb8>* const pLast, Unk_StlElem<0xb8>* pDest, void* pAl)
{
    Unk_StlElem<0xb8>* const pUFirst = FUN_1415dab30(pFirst);
    Unk_StlElem<0xb8>* const pULast = FUN_1415dab30(pLast);
    Unk_StlElem<0xb8>* const pUDest = static_cast<Unk_StlElem<0xb8>*>(FUN_1415daca0(pDest, FUN_1415db450(pUFirst, pULast)));
    FUN_1415dccb0(pDest, FUN_1415df100(pUFirst, pULast, pUDest, pAl, FUN_1415dc510(pUFirst, pUDest), std::false_type()));
    return pDest;
}

// @0x1415de450
Unk_StlElem<0x58>* FUN_1415de450(Unk_StlElem<0x58>* const pFirst, Unk_StlElem<0x58>* const pLast, Unk_StlElem<0x58>* pDest, void* pAl)
{
    Unk_StlElem<0x58>* const pUFirst = FUN_1415dab40(pFirst);
    Unk_StlElem<0x58>* const pULast = FUN_1415dab40(pLast);
    Unk_StlElem<0x58>* const pUDest = FUN_1415dacb0(pDest, FUN_1415db480(pUFirst, pULast));
    FUN_1415dccd0(pDest, FUN_1415df190(pUFirst, pULast, pUDest, pAl, FUN_1415dc540(pUFirst, pUDest), std::false_type()));
    return pDest;
}

// @0x1415de520
Unk_StlElem<0xae8>* FUN_1415de520(Unk_StlElem<0xae8>* const pFirst, Unk_StlElem<0xae8>* const pLast, Unk_StlElem<0xae8>* pDest, void* pAl)
{
    Unk_StlElem<0xae8>* const pUFirst = FUN_1415dab60(pFirst);
    Unk_StlElem<0xae8>* const pULast = FUN_1415dab60(pLast);
    Unk_StlElem<0xae8>* const pUDest = FUN_1415dacd0(pDest, FUN_1415db4e0(pUFirst, pULast));
    FUN_1415dcd10(pDest, FUN_1415df220(pUFirst, pULast, pUDest, pAl, FUN_1415dc570(pUFirst, pUDest), std::false_type()));
    return pDest;
}

// @0x1415de5f0
Unk_StlElem<0xec8>* FUN_1415de5f0(Unk_StlElem<0xec8>* const pFirst, Unk_StlElem<0xec8>* const pLast, Unk_StlElem<0xec8>* pDest, void* pAl)
{
    Unk_StlElem<0xec8>* const pUFirst = FUN_1415dab70(pFirst);
    Unk_StlElem<0xec8>* const pULast = FUN_1415dab70(pLast);
    Unk_StlElem<0xec8>* const pUDest = FUN_1415dace0(pDest, FUN_1415db510(pUFirst, pULast));
    FUN_1415dcd30(pDest, FUN_1415df2b0(pUFirst, pULast, pUDest, pAl, FUN_1415dc5a0(pUFirst, pUDest), std::false_type()));
    return pDest;
}

// @0x1415de6c0
Unk_StlElem<0xc8>* FUN_1415de6c0(Unk_StlElem<0xc8>* const pFirst, Unk_StlElem<0xc8>* const pLast, Unk_StlElem<0xc8>* pDest, void* pAl)
{
    Unk_StlElem<0xc8>* const pUFirst = FUN_1415dab80(pFirst);
    Unk_StlElem<0xc8>* const pULast = FUN_1415dab80(pLast);
    Unk_StlElem<0xc8>* const pUDest = FUN_1415dacf0(pDest, FUN_1415db540(pUFirst, pULast));
    FUN_1415dcd50(pDest, FUN_1415df340(pUFirst, pULast, pUDest, pAl, FUN_1415dc5d0(pUFirst, pUDest), std::false_type()));
    return pDest;
}

// @0x1415de790
Unk_StlElem<0xf8>* FUN_1415de790(Unk_StlElem<0xf8>* const pFirst, Unk_StlElem<0xf8>* const pLast, Unk_StlElem<0xf8>* pDest, void* pAl)
{
    Unk_StlElem<0xf8>* const pUFirst = FUN_1415dab90(pFirst);
    Unk_StlElem<0xf8>* const pULast = FUN_1415dab90(pLast);
    Unk_StlElem<0xf8>* const pUDest = FUN_1415dad00(pDest, FUN_1415db570(pUFirst, pULast));
    FUN_1415dcd70(pDest, FUN_1415df3d0(pUFirst, pULast, pUDest, pAl, FUN_1415dc600(pUFirst, pUDest), std::false_type()));
    return pDest;
}

// @0x1415de860
Unk_StlElem<0x490>* FUN_1415de860(Unk_StlElem<0x490>* const pFirst, Unk_StlElem<0x490>* const pLast, Unk_StlElem<0x490>* pDest, void* pAl)
{
    Unk_StlElem<0x490>* const pUFirst = FUN_1415daba0(pFirst);
    Unk_StlElem<0x490>* const pULast = FUN_1415daba0(pLast);
    Unk_StlElem<0x490>* const pUDest = FUN_1415dad10(pDest, FUN_1415db5a0(pUFirst, pULast));
    FUN_1415dcd90(pDest, FUN_1415df460(pUFirst, pULast, pUDest, pAl, FUN_1415dc630(pUFirst, pUDest), std::false_type()));
    return pDest;
}

// @0x1415de930
Unk_StlElem<0x20>* FUN_1415de930(Unk_StlElem<0x20>* const pFirst, Unk_StlElem<0x20>* const pLast, Unk_StlElem<0x20>* pDest, void* pAl)
{
    Unk_StlElem<0x20>* const pUFirst = FUN_1415dabb0(pFirst);
    Unk_StlElem<0x20>* const pULast = FUN_1415dabb0(pLast);
    Unk_StlElem<0x20>* const pUDest = FUN_1415dad20(pDest, FUN_1415db5d0(pUFirst, pULast));
    FUN_1415dcdb0(pDest, FUN_1415df4f0(pUFirst, pULast, pUDest, pAl, FUN_1415dc660(pUFirst, pUDest), std::false_type()));
    return pDest;
}

// @0x1415dea00
Unk_StlElem<0x30>* FUN_1415dea00(Unk_StlElem<0x30>* const pFirst, Unk_StlElem<0x30>* const pLast, Unk_StlElem<0x30>* pDest, void* pAl)
{
    Unk_StlElem<0x30>* const pUFirst = FUN_1415da9e0(pFirst);
    Unk_StlElem<0x30>* const pULast = FUN_1415da9e0(pLast);
    Unk_StlElem<0x30>* const pUDest = static_cast<Unk_StlElem<0x30>*>(FUN_1415daca0(pDest, FUN_1415db600(pUFirst, pULast)));
    FUN_1415dccb0(reinterpret_cast<Unk_StlElem<0xb8>*&>(pDest), reinterpret_cast<Unk_StlElem<0xb8>*>(FUN_1415df580(pUFirst, pULast, pUDest, pAl, FUN_1415dc290(pUFirst, pUDest), std::false_type())));   // folded with the Unk_StlElem<0xb8> instance
    return pDest;
}

// @0x1415dead0
Unk_StlElem<0x58>* FUN_1415dead0(Unk_StlElem<0x58>* pFirst, Unk_StlElem<0x58>* const pLast, Unk_StlElem<0x58>* const pDest, void* pAl, std::_General_ptr_iterator_tag, std::_Any_tag)
{
    Unk_StlBackout<Unk_StlElem<0x58>> backout{pDest, pAl};   // ctor 0x1415e5de0, dtor 0x1415eb840
    for (; pFirst != pLast; ++pFirst)
        FUN_1415d4850(&backout, pFirst);
    return FUN_141604390(&backout);
}

// @0x1415deb60
Unk_StlElem<0x30>* FUN_1415deb60(Unk_StlElem<0x30>* pFirst, Unk_StlElem<0x30>* const pLast, Unk_StlElem<0x30>* const pDest, void* pAl, std::_General_ptr_iterator_tag, std::_Any_tag)
{
    Unk_StlBackout<Unk_StlElem<0x30>> backout{pDest, pAl};   // ctor 0x1415e5e20, dtor 0x1415eb880
    for (; pFirst != pLast; ++pFirst)
        FUN_1415d48b0(&backout, pFirst);
    return FUN_1416043b0(&backout);
}

// @0x1415debf0
Unk_StlElem<0x98>* FUN_1415debf0(Unk_StlElem<0x98>* pFirst, Unk_StlElem<0x98>* const pLast, Unk_StlElem<0x98>* const pDest, void* pAl, std::_General_ptr_iterator_tag, std::_Any_tag)
{
    Unk_StlBackout<Unk_StlElem<0x98>> backout{pDest, pAl};   // ctor 0x1415e5e60, dtor 0x1415eb8c0
    for (; pFirst != pLast; ++pFirst)
        FUN_1415d4910(&backout, pFirst);
    return FUN_1416043d0(&backout);
}

// @0x1415dec80
Unk_StlElem<0x220>* FUN_1415dec80(Unk_StlElem<0x220>* pFirst, Unk_StlElem<0x220>* const pLast, Unk_StlElem<0x220>* const pDest, void* pAl, std::_General_ptr_iterator_tag, std::_Any_tag)
{
    Unk_StlBackout<Unk_StlElem<0x220>> backout{pDest, pAl};   // ctor 0x1415e5ea0, dtor 0x1415eb900
    for (; pFirst != pLast; ++pFirst)
        FUN_1415d4980(&backout, pFirst);
    return FUN_1416043f0(&backout);
}

// @0x1415ded10
Unk_StlElem<0x128>* FUN_1415ded10(Unk_StlElem<0x128>* pFirst, Unk_StlElem<0x128>* const pLast, Unk_StlElem<0x128>* const pDest, void* pAl, std::_General_ptr_iterator_tag, std::_Any_tag)
{
    Unk_StlBackout<Unk_StlElem<0x128>> backout{pDest, pAl};   // ctor 0x1415e5ee0, dtor 0x1415eb940
    for (; pFirst != pLast; ++pFirst)
        FUN_1415d49f0(&backout, pFirst);
    return FUN_141604410(&backout);
}

// @0x1415deda0
Unk_StlElem<0x118>* FUN_1415deda0(Unk_StlElem<0x118>* pFirst, Unk_StlElem<0x118>* const pLast, Unk_StlElem<0x118>* const pDest, void* pAl, std::_General_ptr_iterator_tag, std::_Any_tag)
{
    Unk_StlBackout<Unk_StlElem<0x118>> backout{pDest, pAl};   // ctor 0x1415e5f20, dtor 0x1415eb980
    for (; pFirst != pLast; ++pFirst)
        FUN_1415d4a60(&backout, pFirst);
    return FUN_141604430(&backout);
}

// @0x1415dee30
Unk_StlElem<0x580>* FUN_1415dee30(Unk_StlElem<0x580>* pFirst, Unk_StlElem<0x580>* const pLast, Unk_StlElem<0x580>* const pDest, void* pAl, std::_General_ptr_iterator_tag, std::_Any_tag)
{
    Unk_StlBackout<Unk_StlElem<0x580>> backout{pDest, pAl};   // ctor 0x1415e5fa0, dtor 0x1415eba00
    for (; pFirst != pLast; ++pFirst)
        FUN_1415d4ad0(&backout, pFirst);
    return FUN_141604470(&backout);
}

// @0x1415deec0
Unk_StlElem<0x18>* FUN_1415deec0(Unk_StlElem<0x18>* pFirst, Unk_StlElem<0x18>* const pLast, Unk_StlElem<0x18>* const pDest, void* pAl, std::_General_ptr_iterator_tag, std::_Any_tag)
{
    Unk_StlBackout<Unk_StlElem<0x18>> backout{pDest, pAl};   // ctor 0x1415e5fe0, dtor 0x1415eba40
    for (; pFirst != pLast; ++pFirst)
        FUN_1415d4b40(&backout, pFirst);
    return FUN_141604490(&backout);
}

// @0x1415def50
Unk_StlElem<0x14a8>* FUN_1415def50(Unk_StlElem<0x14a8>* pFirst, Unk_StlElem<0x14a8>* const pLast, Unk_StlElem<0x14a8>* const pDest, void* pAl, std::_General_ptr_iterator_tag, std::_Any_tag)
{
    Unk_StlBackout<Unk_StlElem<0x14a8>> backout{pDest, pAl};   // ctor 0x1415e6020, dtor 0x1415eba80
    for (; pFirst != pLast; ++pFirst)
        FUN_1415d4ba0(&backout, pFirst);
    return FUN_1416044b0(&backout);
}

// @0x1415defe0
Unk_StlElem<0x18>* FUN_1415defe0(Unk_StlElem<0x18>* pFirst, Unk_StlElem<0x18>* const pLast, Unk_StlElem<0x18>* const pDest, void* pAl, std::_General_ptr_iterator_tag, std::_Any_tag)
{
    Unk_StlBackout<Unk_StlElem<0x18>> backout{pDest, pAl};   // ctor 0x1415e6060, dtor 0x1415ebac0
    for (; pFirst != pLast; ++pFirst)
        FUN_1415d4c10(&backout, pFirst);
    return FUN_1416044d0(&backout);
}

// @0x1415df070
Unk_StlElem<0x190>* FUN_1415df070(Unk_StlElem<0x190>* pFirst, Unk_StlElem<0x190>* const pLast, Unk_StlElem<0x190>* const pDest, void* pAl, std::_General_ptr_iterator_tag, std::_Any_tag)
{
    Unk_StlBackout<Unk_StlElem<0x190>> backout{pDest, pAl};   // ctor 0x1415e60a0, dtor 0x1415ebb00
    for (; pFirst != pLast; ++pFirst)
        FUN_1415d4c70(&backout, pFirst);
    return FUN_1416044f0(&backout);
}

// @0x1415df100
Unk_StlElem<0xb8>* FUN_1415df100(Unk_StlElem<0xb8>* pFirst, Unk_StlElem<0xb8>* const pLast, Unk_StlElem<0xb8>* const pDest, void* pAl, std::_General_ptr_iterator_tag, std::_Any_tag)
{
    Unk_StlBackout<Unk_StlElem<0xb8>> backout{pDest, pAl};   // ctor 0x1415e60e0, dtor 0x1415ebb40
    for (; pFirst != pLast; ++pFirst)
        FUN_1415d4ce0(&backout, pFirst);
    return static_cast<Unk_StlElem<0xb8>*>(FUN_141604510(&backout));
}

// @0x1415df190
Unk_StlElem<0x58>* FUN_1415df190(Unk_StlElem<0x58>* pFirst, Unk_StlElem<0x58>* const pLast, Unk_StlElem<0x58>* const pDest, void* pAl, std::_General_ptr_iterator_tag, std::_Any_tag)
{
    Unk_StlBackout<Unk_StlElem<0x58>> backout{pDest, pAl};   // ctor 0x1415e6120, dtor 0x1415ebb80
    for (; pFirst != pLast; ++pFirst)
        FUN_1415d4d50(&backout, pFirst);
    return FUN_141604530(&backout);
}

// @0x1415df220
Unk_StlElem<0xae8>* FUN_1415df220(Unk_StlElem<0xae8>* pFirst, Unk_StlElem<0xae8>* const pLast, Unk_StlElem<0xae8>* const pDest, void* pAl, std::_General_ptr_iterator_tag, std::_Any_tag)
{
    Unk_StlBackout<Unk_StlElem<0xae8>> backout{pDest, pAl};   // ctor 0x1415e61a0, dtor 0x1415ebc00
    for (; pFirst != pLast; ++pFirst)
        FUN_1415d4db0(&backout, pFirst);
    return FUN_141604570(&backout);
}

// @0x1415df2b0
Unk_StlElem<0xec8>* FUN_1415df2b0(Unk_StlElem<0xec8>* pFirst, Unk_StlElem<0xec8>* const pLast, Unk_StlElem<0xec8>* const pDest, void* pAl, std::_General_ptr_iterator_tag, std::_Any_tag)
{
    Unk_StlBackout<Unk_StlElem<0xec8>> backout{pDest, pAl};   // ctor 0x1415e61e0, dtor 0x1415ebc40
    for (; pFirst != pLast; ++pFirst)
        FUN_1415d4e20(&backout, pFirst);
    return FUN_141604590(&backout);
}

// @0x1415df340
Unk_StlElem<0xc8>* FUN_1415df340(Unk_StlElem<0xc8>* pFirst, Unk_StlElem<0xc8>* const pLast, Unk_StlElem<0xc8>* const pDest, void* pAl, std::_General_ptr_iterator_tag, std::_Any_tag)
{
    Unk_StlBackout<Unk_StlElem<0xc8>> backout{pDest, pAl};   // ctor 0x1415e6220, dtor 0x1415ebc80
    for (; pFirst != pLast; ++pFirst)
        FUN_1415d4e90(&backout, pFirst);
    return FUN_1416045b0(&backout);
}

// @0x1415df3d0
Unk_StlElem<0xf8>* FUN_1415df3d0(Unk_StlElem<0xf8>* pFirst, Unk_StlElem<0xf8>* const pLast, Unk_StlElem<0xf8>* const pDest, void* pAl, std::_General_ptr_iterator_tag, std::_Any_tag)
{
    Unk_StlBackout<Unk_StlElem<0xf8>> backout{pDest, pAl};   // ctor 0x1415e6260, dtor 0x1415ebcc0
    for (; pFirst != pLast; ++pFirst)
        FUN_1415d4f00(&backout, pFirst);
    return FUN_1416045d0(&backout);
}

// @0x1415df460
Unk_StlElem<0x490>* FUN_1415df460(Unk_StlElem<0x490>* pFirst, Unk_StlElem<0x490>* const pLast, Unk_StlElem<0x490>* const pDest, void* pAl, std::_General_ptr_iterator_tag, std::_Any_tag)
{
    Unk_StlBackout<Unk_StlElem<0x490>> backout{pDest, pAl};   // ctor 0x1415e62a0, dtor 0x1415ebd00
    for (; pFirst != pLast; ++pFirst)
        FUN_1415d4f70(&backout, pFirst);
    return FUN_1416045f0(&backout);
}

// @0x1415df4f0
Unk_StlElem<0x20>* FUN_1415df4f0(Unk_StlElem<0x20>* pFirst, Unk_StlElem<0x20>* const pLast, Unk_StlElem<0x20>* const pDest, void* pAl, std::_General_ptr_iterator_tag, std::_Any_tag)
{
    Unk_StlBackout<Unk_StlElem<0x20>> backout{pDest, pAl};   // ctor 0x1415e62e0, dtor 0x1415ebd40
    for (; pFirst != pLast; ++pFirst)
        FUN_1415d4fe0(&backout, pFirst);
    return FUN_141604610(&backout);
}

// @0x1415df580
Unk_StlElem<0x30>* FUN_1415df580(Unk_StlElem<0x30>* pFirst, Unk_StlElem<0x30>* const pLast, Unk_StlElem<0x30>* const pDest, void* pAl, std::_General_ptr_iterator_tag, std::_Any_tag)
{
    Unk_StlBackout<Unk_StlElem<0x30>> backout{pDest, pAl};   // ctor 0x1415e60e0, dtor 0x1415ebb40
    for (; pFirst != pLast; ++pFirst)
        FUN_1415d5040(&backout, pFirst);
    return static_cast<Unk_StlElem<0x30>*>(FUN_141604510(&backout));
}

// @0x1415df610
Unk_StlElem<0x10>* FUN_1415df610(Unk_StlElem<0x10>* const pFirst, Unk_StlElem<0x10>* const pLast, Unk_StlElem<0x10>* const pDest, void* pAl, std::_Really_trivial_ptr_iterator_tag, std::true_type)
{
    return FUN_1415d26a0(pFirst, pLast, pDest);
}

// @0x1415df650
Unk_StlElem<0x18>* FUN_1415df650(Unk_StlElem<0x18>* const pFirst, Unk_StlElem<0x18>* const pLast, Unk_StlElem<0x18>* const pDest, void* pAl, std::_Really_trivial_ptr_iterator_tag, std::true_type)
{
    return FUN_1415d2710(pFirst, pLast, pDest);
}

// @0x1415df690
Unk_StlElem<0x10>* FUN_1415df690(Unk_StlElem<0x10>* const pFirst, Unk_StlElem<0x10>* const pLast, Unk_StlElem<0x10>* pDest, void* pAl)
{
    Unk_StlElem<0x10>* const pUFirst = FUN_1415da9f0(pFirst);
    Unk_StlElem<0x10>* const pULast = FUN_1415da9f0(pLast);
    Unk_StlElem<0x10>* const pUDest = FUN_1415dabc0(pDest, FUN_1415db1b0(pUFirst, pULast));
    FUN_1415dcac0(pDest, FUN_1415e14d0(pUFirst, pULast, pUDest, pAl, FUN_1415dc690(pUFirst, pUDest), std::true_type()));
    return pDest;
}

// @0x1415df740
Unk_StlElem<0x18>* FUN_1415df740(Unk_StlElem<0x18>* const pFirst, Unk_StlElem<0x18>* const pLast, Unk_StlElem<0x18>* pDest, void* pAl)
{
    Unk_StlElem<0x18>* const pUFirst = FUN_1415daa00(pFirst);
    Unk_StlElem<0x18>* const pULast = FUN_1415daa00(pLast);
    Unk_StlElem<0x18>* const pUDest = FUN_1415dabd0(pDest, FUN_1415db1e0(pUFirst, pULast));
    FUN_1415dcae0(pDest, FUN_1415e1510(pUFirst, pULast, pUDest, pAl, FUN_1415dc6b0(pUFirst, pUDest), std::true_type()));
    return pDest;
}

// @0x1415df7f0
Unk_StlElem<0x58>* FUN_1415df7f0(Unk_StlElem<0x58>* const pFirst, Unk_StlElem<0x58>* const pLast, Unk_StlElem<0x58>* pDest, void* pAl)
{
    Unk_StlElem<0x58>* const pUFirst = FUN_1415daa70(pFirst);
    Unk_StlElem<0x58>* const pULast = FUN_1415daa70(pLast);
    Unk_StlElem<0x58>* const pUDest = FUN_1415dabe0(pDest, FUN_1415db210(pUFirst, pULast));
    FUN_1415dcb30(pDest, FUN_1415e0900(pUFirst, pULast, pUDest, pAl, FUN_1415dc6d0(pUFirst, pUDest), std::false_type()));
    return pDest;
}

// @0x1415df8c0
Unk_StlElem<0x30>* FUN_1415df8c0(Unk_StlElem<0x30>* const pFirst, Unk_StlElem<0x30>* const pLast, Unk_StlElem<0x30>* pDest, void* pAl)
{
    Unk_StlElem<0x30>* const pUFirst = FUN_1415daa80(pFirst);
    Unk_StlElem<0x30>* const pULast = FUN_1415daa80(pLast);
    Unk_StlElem<0x30>* const pUDest = FUN_1415dabf0(pDest, FUN_1415db240(pUFirst, pULast));
    FUN_1415dcb50(pDest, FUN_1415e0990(pUFirst, pULast, pUDest, pAl, FUN_1415dc700(pUFirst, pUDest), std::false_type()));
    return pDest;
}

// @0x1415df990
Unk_StlElem<0x98>* FUN_1415df990(Unk_StlElem<0x98>* const pFirst, Unk_StlElem<0x98>* const pLast, Unk_StlElem<0x98>* pDest, void* pAl)
{
    Unk_StlElem<0x98>* const pUFirst = FUN_1415daa90(pFirst);
    Unk_StlElem<0x98>* const pULast = FUN_1415daa90(pLast);
    Unk_StlElem<0x98>* const pUDest = FUN_1415dac00(pDest, FUN_1415db270(pUFirst, pULast));
    FUN_1415dcb70(pDest, FUN_1415e0a20(pUFirst, pULast, pUDest, pAl, FUN_1415dc730(pUFirst, pUDest), std::false_type()));
    return pDest;
}

// @0x1415dfa60
Unk_StlElem<0x220>* FUN_1415dfa60(Unk_StlElem<0x220>* const pFirst, Unk_StlElem<0x220>* const pLast, Unk_StlElem<0x220>* pDest, void* pAl)
{
    Unk_StlElem<0x220>* const pUFirst = FUN_1415daaa0(pFirst);
    Unk_StlElem<0x220>* const pULast = FUN_1415daaa0(pLast);
    Unk_StlElem<0x220>* const pUDest = FUN_1415dac10(pDest, FUN_1415db2a0(pUFirst, pULast));
    FUN_1415dcb90(pDest, FUN_1415e0ab0(pUFirst, pULast, pUDest, pAl, FUN_1415dc760(pUFirst, pUDest), std::false_type()));
    return pDest;
}

// @0x1415dfb30
Unk_StlElem<0x128>* FUN_1415dfb30(Unk_StlElem<0x128>* const pFirst, Unk_StlElem<0x128>* const pLast, Unk_StlElem<0x128>* pDest, void* pAl)
{
    Unk_StlElem<0x128>* const pUFirst = FUN_1415daab0(pFirst);
    Unk_StlElem<0x128>* const pULast = FUN_1415daab0(pLast);
    Unk_StlElem<0x128>* const pUDest = FUN_1415dac20(pDest, FUN_1415db2d0(pUFirst, pULast));
    FUN_1415dcbb0(pDest, FUN_1415e0b40(pUFirst, pULast, pUDest, pAl, FUN_1415dc790(pUFirst, pUDest), std::false_type()));
    return pDest;
}

// @0x1415dfc00
Unk_StlElem<0x118>* FUN_1415dfc00(Unk_StlElem<0x118>* const pFirst, Unk_StlElem<0x118>* const pLast, Unk_StlElem<0x118>* pDest, void* pAl)
{
    Unk_StlElem<0x118>* const pUFirst = FUN_1415daac0(pFirst);
    Unk_StlElem<0x118>* const pULast = FUN_1415daac0(pLast);
    Unk_StlElem<0x118>* const pUDest = FUN_1415dac30(pDest, FUN_1415db300(pUFirst, pULast));
    FUN_1415dcbd0(pDest, FUN_1415e0bd0(pUFirst, pULast, pUDest, pAl, FUN_1415dc7c0(pUFirst, pUDest), std::false_type()));
    return pDest;
}

// @0x1415dfcd0
Unk_StlElem<0xe0>* FUN_1415dfcd0(Unk_StlElem<0xe0>* const pFirst, Unk_StlElem<0xe0>* const pLast, Unk_StlElem<0xe0>* pDest, void* pAl)
{
    Unk_StlElem<0xe0>* const pUFirst = FUN_1415daad0(pFirst);
    Unk_StlElem<0xe0>* const pULast = FUN_1415daad0(pLast);
    Unk_StlElem<0xe0>* const pUDest = FUN_1415dac40(pDest, FUN_1415db330(pUFirst, pULast));
    FUN_1415dcbf0(pDest, FUN_1415e0c60(pUFirst, pULast, pUDest, pAl, FUN_1415dc7f0(pUFirst, pUDest), std::false_type()));
    return pDest;
}

// @0x1415dfda0
Unk_StlElem<0x580>* FUN_1415dfda0(Unk_StlElem<0x580>* const pFirst, Unk_StlElem<0x580>* const pLast, Unk_StlElem<0x580>* pDest, void* pAl)
{
    Unk_StlElem<0x580>* const pUFirst = FUN_1415daae0(pFirst);
    Unk_StlElem<0x580>* const pULast = FUN_1415daae0(pLast);
    Unk_StlElem<0x580>* const pUDest = FUN_1415dac50(pDest, FUN_1415db360(pUFirst, pULast));
    FUN_1415dcc10(pDest, FUN_1415e0cf0(pUFirst, pULast, pUDest, pAl, FUN_1415dc820(pUFirst, pUDest), std::false_type()));
    return pDest;
}

// @0x1415dfe70
Unk_StlElem<0x18>* FUN_1415dfe70(Unk_StlElem<0x18>* const pFirst, Unk_StlElem<0x18>* const pLast, Unk_StlElem<0x18>* pDest, void* pAl)
{
    Unk_StlElem<0x18>* const pUFirst = FUN_1415daaf0(pFirst);
    Unk_StlElem<0x18>* const pULast = FUN_1415daaf0(pLast);
    Unk_StlElem<0x18>* const pUDest = FUN_1415dac60(pDest, FUN_1415db390(pUFirst, pULast));
    FUN_1415dcc30(pDest, FUN_1415e0d80(pUFirst, pULast, pUDest, pAl, FUN_1415dc850(pUFirst, pUDest), std::false_type()));
    return pDest;
}

// @0x1415dff40
Unk_StlElem<0x14a8>* FUN_1415dff40(Unk_StlElem<0x14a8>* const pFirst, Unk_StlElem<0x14a8>* const pLast, Unk_StlElem<0x14a8>* pDest, void* pAl)
{
    Unk_StlElem<0x14a8>* const pUFirst = FUN_1415dab00(pFirst);
    Unk_StlElem<0x14a8>* const pULast = FUN_1415dab00(pLast);
    Unk_StlElem<0x14a8>* const pUDest = FUN_1415dac70(pDest, FUN_1415db3c0(pUFirst, pULast));
    FUN_1415dcc50(pDest, FUN_1415e0e10(pUFirst, pULast, pUDest, pAl, FUN_1415dc880(pUFirst, pUDest), std::false_type()));
    return pDest;
}

// @0x1415e0010
Unk_StlElem<0x18>* FUN_1415e0010(Unk_StlElem<0x18>* const pFirst, Unk_StlElem<0x18>* const pLast, Unk_StlElem<0x18>* pDest, void* pAl)
{
    Unk_StlElem<0x18>* const pUFirst = FUN_1415dab10(pFirst);
    Unk_StlElem<0x18>* const pULast = FUN_1415dab10(pLast);
    Unk_StlElem<0x18>* const pUDest = FUN_1415dac80(pDest, FUN_1415db3f0(pUFirst, pULast));
    FUN_1415dcc70(pDest, FUN_1415e0ea0(pUFirst, pULast, pUDest, pAl, FUN_1415dc8b0(pUFirst, pUDest), std::false_type()));
    return pDest;
}

// @0x1415e00e0
Unk_StlElem<0x190>* FUN_1415e00e0(Unk_StlElem<0x190>* const pFirst, Unk_StlElem<0x190>* const pLast, Unk_StlElem<0x190>* pDest, void* pAl)
{
    Unk_StlElem<0x190>* const pUFirst = FUN_1415dab20(pFirst);
    Unk_StlElem<0x190>* const pULast = FUN_1415dab20(pLast);
    Unk_StlElem<0x190>* const pUDest = FUN_1415dac90(pDest, FUN_1415db420(pUFirst, pULast));
    FUN_1415dcc90(pDest, FUN_1415e0f30(pUFirst, pULast, pUDest, pAl, FUN_1415dc8e0(pUFirst, pUDest), std::false_type()));
    return pDest;
}

// @0x1415e01b0
Unk_StlElem<0xb8>* FUN_1415e01b0(Unk_StlElem<0xb8>* const pFirst, Unk_StlElem<0xb8>* const pLast, Unk_StlElem<0xb8>* pDest, void* pAl)
{
    Unk_StlElem<0xb8>* const pUFirst = FUN_1415dab30(pFirst);
    Unk_StlElem<0xb8>* const pULast = FUN_1415dab30(pLast);
    Unk_StlElem<0xb8>* const pUDest = static_cast<Unk_StlElem<0xb8>*>(FUN_1415daca0(pDest, FUN_1415db450(pUFirst, pULast)));
    FUN_1415dccb0(pDest, FUN_1415e0fc0(pUFirst, pULast, pUDest, pAl, FUN_1415dc910(pUFirst, pUDest), std::false_type()));
    return pDest;
}

// @0x1415e0280
Unk_StlElem<0x58>* FUN_1415e0280(Unk_StlElem<0x58>* const pFirst, Unk_StlElem<0x58>* const pLast, Unk_StlElem<0x58>* pDest, void* pAl)
{
    Unk_StlElem<0x58>* const pUFirst = FUN_1415dab40(pFirst);
    Unk_StlElem<0x58>* const pULast = FUN_1415dab40(pLast);
    Unk_StlElem<0x58>* const pUDest = FUN_1415dacb0(pDest, FUN_1415db480(pUFirst, pULast));
    FUN_1415dccd0(pDest, FUN_1415e1050(pUFirst, pULast, pUDest, pAl, FUN_1415dc940(pUFirst, pUDest), std::false_type()));
    return pDest;
}

// @0x1415e0350
Unk_StlElem<0x68>* FUN_1415e0350(Unk_StlElem<0x68>* const pFirst, Unk_StlElem<0x68>* const pLast, Unk_StlElem<0x68>* pDest, void* pAl)
{
    Unk_StlElem<0x68>* const pUFirst = FUN_1415dab50(pFirst);
    Unk_StlElem<0x68>* const pULast = FUN_1415dab50(pLast);
    Unk_StlElem<0x68>* const pUDest = FUN_1415dacc0(pDest, FUN_1415db4b0(pUFirst, pULast));
    FUN_1415dccf0(pDest, FUN_1415e10e0(pUFirst, pULast, pUDest, pAl, FUN_1415dc970(pUFirst, pUDest), std::false_type()));
    return pDest;
}

// @0x1415e0420
Unk_StlElem<0xae8>* FUN_1415e0420(Unk_StlElem<0xae8>* const pFirst, Unk_StlElem<0xae8>* const pLast, Unk_StlElem<0xae8>* pDest, void* pAl)
{
    Unk_StlElem<0xae8>* const pUFirst = FUN_1415dab60(pFirst);
    Unk_StlElem<0xae8>* const pULast = FUN_1415dab60(pLast);
    Unk_StlElem<0xae8>* const pUDest = FUN_1415dacd0(pDest, FUN_1415db4e0(pUFirst, pULast));
    FUN_1415dcd10(pDest, FUN_1415e1170(pUFirst, pULast, pUDest, pAl, FUN_1415dc9a0(pUFirst, pUDest), std::false_type()));
    return pDest;
}

// @0x1415e04f0
Unk_StlElem<0xec8>* FUN_1415e04f0(Unk_StlElem<0xec8>* const pFirst, Unk_StlElem<0xec8>* const pLast, Unk_StlElem<0xec8>* pDest, void* pAl)
{
    Unk_StlElem<0xec8>* const pUFirst = FUN_1415dab70(pFirst);
    Unk_StlElem<0xec8>* const pULast = FUN_1415dab70(pLast);
    Unk_StlElem<0xec8>* const pUDest = FUN_1415dace0(pDest, FUN_1415db510(pUFirst, pULast));
    FUN_1415dcd30(pDest, FUN_1415e1200(pUFirst, pULast, pUDest, pAl, FUN_1415dc9d0(pUFirst, pUDest), std::false_type()));
    return pDest;
}

// @0x1415e05c0
Unk_StlElem<0xc8>* FUN_1415e05c0(Unk_StlElem<0xc8>* const pFirst, Unk_StlElem<0xc8>* const pLast, Unk_StlElem<0xc8>* pDest, void* pAl)
{
    Unk_StlElem<0xc8>* const pUFirst = FUN_1415dab80(pFirst);
    Unk_StlElem<0xc8>* const pULast = FUN_1415dab80(pLast);
    Unk_StlElem<0xc8>* const pUDest = FUN_1415dacf0(pDest, FUN_1415db540(pUFirst, pULast));
    FUN_1415dcd50(pDest, FUN_1415e1290(pUFirst, pULast, pUDest, pAl, FUN_1415dca00(pUFirst, pUDest), std::false_type()));
    return pDest;
}

// @0x1415e0690
Unk_StlElem<0xf8>* FUN_1415e0690(Unk_StlElem<0xf8>* const pFirst, Unk_StlElem<0xf8>* const pLast, Unk_StlElem<0xf8>* pDest, void* pAl)
{
    Unk_StlElem<0xf8>* const pUFirst = FUN_1415dab90(pFirst);
    Unk_StlElem<0xf8>* const pULast = FUN_1415dab90(pLast);
    Unk_StlElem<0xf8>* const pUDest = FUN_1415dad00(pDest, FUN_1415db570(pUFirst, pULast));
    FUN_1415dcd70(pDest, FUN_1415e1320(pUFirst, pULast, pUDest, pAl, FUN_1415dca30(pUFirst, pUDest), std::false_type()));
    return pDest;
}

// @0x1415e0760
Unk_StlElem<0x490>* FUN_1415e0760(Unk_StlElem<0x490>* const pFirst, Unk_StlElem<0x490>* const pLast, Unk_StlElem<0x490>* pDest, void* pAl)
{
    Unk_StlElem<0x490>* const pUFirst = FUN_1415daba0(pFirst);
    Unk_StlElem<0x490>* const pULast = FUN_1415daba0(pLast);
    Unk_StlElem<0x490>* const pUDest = FUN_1415dad10(pDest, FUN_1415db5a0(pUFirst, pULast));
    FUN_1415dcd90(pDest, FUN_1415e13b0(pUFirst, pULast, pUDest, pAl, FUN_1415dca60(pUFirst, pUDest), std::false_type()));
    return pDest;
}

// @0x1415e0830
Unk_StlElem<0x20>* FUN_1415e0830(Unk_StlElem<0x20>* const pFirst, Unk_StlElem<0x20>* const pLast, Unk_StlElem<0x20>* pDest, void* pAl)
{
    Unk_StlElem<0x20>* const pUFirst = FUN_1415dabb0(pFirst);
    Unk_StlElem<0x20>* const pULast = FUN_1415dabb0(pLast);
    Unk_StlElem<0x20>* const pUDest = FUN_1415dad20(pDest, FUN_1415db5d0(pUFirst, pULast));
    FUN_1415dcdb0(pDest, FUN_1415e1440(pUFirst, pULast, pUDest, pAl, FUN_1415dca90(pUFirst, pUDest), std::false_type()));
    return pDest;
}

// @0x1415e0900
Unk_StlElem<0x58>* FUN_1415e0900(Unk_StlElem<0x58>* pFirst, Unk_StlElem<0x58>* const pLast, Unk_StlElem<0x58>* const pDest, void* pAl, std::_General_ptr_iterator_tag, std::_Any_tag)
{
    Unk_StlBackout<Unk_StlElem<0x58>> backout{pDest, pAl};   // ctor 0x1415e5de0, dtor 0x1415eb840
    for (; pFirst != pLast; ++pFirst)
        FUN_1415d50b0(&backout, FUN_1415e51e0(pFirst));
    return FUN_141604390(&backout);
}

// @0x1415e0990
Unk_StlElem<0x30>* FUN_1415e0990(Unk_StlElem<0x30>* pFirst, Unk_StlElem<0x30>* const pLast, Unk_StlElem<0x30>* const pDest, void* pAl, std::_General_ptr_iterator_tag, std::_Any_tag)
{
    Unk_StlBackout<Unk_StlElem<0x30>> backout{pDest, pAl};   // ctor 0x1415e5e20, dtor 0x1415eb880
    for (; pFirst != pLast; ++pFirst)
        FUN_1415d5110(&backout, FUN_1415e51f0(pFirst));
    return FUN_1416043b0(&backout);
}

// @0x1415e0a20
Unk_StlElem<0x98>* FUN_1415e0a20(Unk_StlElem<0x98>* pFirst, Unk_StlElem<0x98>* const pLast, Unk_StlElem<0x98>* const pDest, void* pAl, std::_General_ptr_iterator_tag, std::_Any_tag)
{
    Unk_StlBackout<Unk_StlElem<0x98>> backout{pDest, pAl};   // ctor 0x1415e5e60, dtor 0x1415eb8c0
    for (; pFirst != pLast; ++pFirst)
        FUN_1415d5170(&backout, FUN_1415e5200(pFirst));
    return FUN_1416043d0(&backout);
}

// @0x1415e0ab0
Unk_StlElem<0x220>* FUN_1415e0ab0(Unk_StlElem<0x220>* pFirst, Unk_StlElem<0x220>* const pLast, Unk_StlElem<0x220>* const pDest, void* pAl, std::_General_ptr_iterator_tag, std::_Any_tag)
{
    Unk_StlBackout<Unk_StlElem<0x220>> backout{pDest, pAl};   // ctor 0x1415e5ea0, dtor 0x1415eb900
    for (; pFirst != pLast; ++pFirst)
        FUN_1415d51e0(&backout, FUN_1415e5210(pFirst));
    return FUN_1416043f0(&backout);
}

// @0x1415e0b40
Unk_StlElem<0x128>* FUN_1415e0b40(Unk_StlElem<0x128>* pFirst, Unk_StlElem<0x128>* const pLast, Unk_StlElem<0x128>* const pDest, void* pAl, std::_General_ptr_iterator_tag, std::_Any_tag)
{
    Unk_StlBackout<Unk_StlElem<0x128>> backout{pDest, pAl};   // ctor 0x1415e5ee0, dtor 0x1415eb940
    for (; pFirst != pLast; ++pFirst)
        FUN_1415d5250(&backout, FUN_1415e5220(pFirst));
    return FUN_141604410(&backout);
}

// @0x1415e0bd0
Unk_StlElem<0x118>* FUN_1415e0bd0(Unk_StlElem<0x118>* pFirst, Unk_StlElem<0x118>* const pLast, Unk_StlElem<0x118>* const pDest, void* pAl, std::_General_ptr_iterator_tag, std::_Any_tag)
{
    Unk_StlBackout<Unk_StlElem<0x118>> backout{pDest, pAl};   // ctor 0x1415e5f20, dtor 0x1415eb980
    for (; pFirst != pLast; ++pFirst)
        FUN_1415d52c0(&backout, FUN_1415e5230(pFirst));
    return FUN_141604430(&backout);
}

// @0x1415e0c60
Unk_StlElem<0xe0>* FUN_1415e0c60(Unk_StlElem<0xe0>* pFirst, Unk_StlElem<0xe0>* const pLast, Unk_StlElem<0xe0>* const pDest, void* pAl, std::_General_ptr_iterator_tag, std::_Any_tag)
{
    Unk_StlBackout<Unk_StlElem<0xe0>> backout{pDest, pAl};   // ctor 0x1415e5f60, dtor 0x1415eb9c0
    for (; pFirst != pLast; ++pFirst)
        FUN_1415d5330(&backout, FUN_1415e5240(pFirst));
    return FUN_141604450(&backout);
}

// @0x1415e0cf0
Unk_StlElem<0x580>* FUN_1415e0cf0(Unk_StlElem<0x580>* pFirst, Unk_StlElem<0x580>* const pLast, Unk_StlElem<0x580>* const pDest, void* pAl, std::_General_ptr_iterator_tag, std::_Any_tag)
{
    Unk_StlBackout<Unk_StlElem<0x580>> backout{pDest, pAl};   // ctor 0x1415e5fa0, dtor 0x1415eba00
    for (; pFirst != pLast; ++pFirst)
        FUN_1415d53a0(&backout, FUN_1415e5250(pFirst));
    return FUN_141604470(&backout);
}

// @0x1415e0d80
Unk_StlElem<0x18>* FUN_1415e0d80(Unk_StlElem<0x18>* pFirst, Unk_StlElem<0x18>* const pLast, Unk_StlElem<0x18>* const pDest, void* pAl, std::_General_ptr_iterator_tag, std::_Any_tag)
{
    Unk_StlBackout<Unk_StlElem<0x18>> backout{pDest, pAl};   // ctor 0x1415e5fe0, dtor 0x1415eba40
    for (; pFirst != pLast; ++pFirst)
        FUN_1415d5410(&backout, FUN_1415e5260(pFirst));
    return FUN_141604490(&backout);
}

// @0x1415e0e10
Unk_StlElem<0x14a8>* FUN_1415e0e10(Unk_StlElem<0x14a8>* pFirst, Unk_StlElem<0x14a8>* const pLast, Unk_StlElem<0x14a8>* const pDest, void* pAl, std::_General_ptr_iterator_tag, std::_Any_tag)
{
    Unk_StlBackout<Unk_StlElem<0x14a8>> backout{pDest, pAl};   // ctor 0x1415e6020, dtor 0x1415eba80
    for (; pFirst != pLast; ++pFirst)
        FUN_1415d5470(&backout, FUN_1415e5270(pFirst));
    return FUN_1416044b0(&backout);
}

// @0x1415e0ea0
Unk_StlElem<0x18>* FUN_1415e0ea0(Unk_StlElem<0x18>* pFirst, Unk_StlElem<0x18>* const pLast, Unk_StlElem<0x18>* const pDest, void* pAl, std::_General_ptr_iterator_tag, std::_Any_tag)
{
    Unk_StlBackout<Unk_StlElem<0x18>> backout{pDest, pAl};   // ctor 0x1415e6060, dtor 0x1415ebac0
    for (; pFirst != pLast; ++pFirst)
        FUN_1415d54e0(&backout, FUN_1415e5280(pFirst));
    return FUN_1416044d0(&backout);
}

// @0x1415e0f30
Unk_StlElem<0x190>* FUN_1415e0f30(Unk_StlElem<0x190>* pFirst, Unk_StlElem<0x190>* const pLast, Unk_StlElem<0x190>* const pDest, void* pAl, std::_General_ptr_iterator_tag, std::_Any_tag)
{
    Unk_StlBackout<Unk_StlElem<0x190>> backout{pDest, pAl};   // ctor 0x1415e60a0, dtor 0x1415ebb00
    for (; pFirst != pLast; ++pFirst)
        FUN_1415d5540(&backout, FUN_1415e5290(pFirst));
    return FUN_1416044f0(&backout);
}

// @0x1415e0fc0
Unk_StlElem<0xb8>* FUN_1415e0fc0(Unk_StlElem<0xb8>* pFirst, Unk_StlElem<0xb8>* const pLast, Unk_StlElem<0xb8>* const pDest, void* pAl, std::_General_ptr_iterator_tag, std::_Any_tag)
{
    Unk_StlBackout<Unk_StlElem<0xb8>> backout{pDest, pAl};   // ctor 0x1415e60e0, dtor 0x1415ebb40
    for (; pFirst != pLast; ++pFirst)
        FUN_1415d55b0(&backout, FUN_1415e52a0(pFirst));
    return static_cast<Unk_StlElem<0xb8>*>(FUN_141604510(&backout));
}

// @0x1415e1050
Unk_StlElem<0x58>* FUN_1415e1050(Unk_StlElem<0x58>* pFirst, Unk_StlElem<0x58>* const pLast, Unk_StlElem<0x58>* const pDest, void* pAl, std::_General_ptr_iterator_tag, std::_Any_tag)
{
    Unk_StlBackout<Unk_StlElem<0x58>> backout{pDest, pAl};   // ctor 0x1415e6120, dtor 0x1415ebb80
    for (; pFirst != pLast; ++pFirst)
        FUN_1415d5620(&backout, FUN_1415e52b0(pFirst));
    return FUN_141604530(&backout);
}

// @0x1415e10e0
Unk_StlElem<0x68>* FUN_1415e10e0(Unk_StlElem<0x68>* pFirst, Unk_StlElem<0x68>* const pLast, Unk_StlElem<0x68>* const pDest, void* pAl, std::_General_ptr_iterator_tag, std::_Any_tag)
{
    Unk_StlBackout<Unk_StlElem<0x68>> backout{pDest, pAl};   // ctor 0x1415e6160, dtor 0x1415ebbc0
    for (; pFirst != pLast; ++pFirst)
        FUN_1415d5680(&backout, FUN_1415e52c0(pFirst));
    return FUN_141604550(&backout);
}

// @0x1415e1170
Unk_StlElem<0xae8>* FUN_1415e1170(Unk_StlElem<0xae8>* pFirst, Unk_StlElem<0xae8>* const pLast, Unk_StlElem<0xae8>* const pDest, void* pAl, std::_General_ptr_iterator_tag, std::_Any_tag)
{
    Unk_StlBackout<Unk_StlElem<0xae8>> backout{pDest, pAl};   // ctor 0x1415e61a0, dtor 0x1415ebc00
    for (; pFirst != pLast; ++pFirst)
        FUN_1415d56e0(&backout, FUN_1415e52d0(pFirst));
    return FUN_141604570(&backout);
}

// @0x1415e1200
Unk_StlElem<0xec8>* FUN_1415e1200(Unk_StlElem<0xec8>* pFirst, Unk_StlElem<0xec8>* const pLast, Unk_StlElem<0xec8>* const pDest, void* pAl, std::_General_ptr_iterator_tag, std::_Any_tag)
{
    Unk_StlBackout<Unk_StlElem<0xec8>> backout{pDest, pAl};   // ctor 0x1415e61e0, dtor 0x1415ebc40
    for (; pFirst != pLast; ++pFirst)
        FUN_1415d5750(&backout, FUN_1415e52e0(pFirst));
    return FUN_141604590(&backout);
}

// @0x1415e1290
Unk_StlElem<0xc8>* FUN_1415e1290(Unk_StlElem<0xc8>* pFirst, Unk_StlElem<0xc8>* const pLast, Unk_StlElem<0xc8>* const pDest, void* pAl, std::_General_ptr_iterator_tag, std::_Any_tag)
{
    Unk_StlBackout<Unk_StlElem<0xc8>> backout{pDest, pAl};   // ctor 0x1415e6220, dtor 0x1415ebc80
    for (; pFirst != pLast; ++pFirst)
        FUN_1415d57c0(&backout, FUN_1415e52f0(pFirst));
    return FUN_1416045b0(&backout);
}

// @0x1415e1320
Unk_StlElem<0xf8>* FUN_1415e1320(Unk_StlElem<0xf8>* pFirst, Unk_StlElem<0xf8>* const pLast, Unk_StlElem<0xf8>* const pDest, void* pAl, std::_General_ptr_iterator_tag, std::_Any_tag)
{
    Unk_StlBackout<Unk_StlElem<0xf8>> backout{pDest, pAl};   // ctor 0x1415e6260, dtor 0x1415ebcc0
    for (; pFirst != pLast; ++pFirst)
        FUN_1415d5830(&backout, FUN_1415e5300(pFirst));
    return FUN_1416045d0(&backout);
}

// @0x1415e13b0
Unk_StlElem<0x490>* FUN_1415e13b0(Unk_StlElem<0x490>* pFirst, Unk_StlElem<0x490>* const pLast, Unk_StlElem<0x490>* const pDest, void* pAl, std::_General_ptr_iterator_tag, std::_Any_tag)
{
    Unk_StlBackout<Unk_StlElem<0x490>> backout{pDest, pAl};   // ctor 0x1415e62a0, dtor 0x1415ebd00
    for (; pFirst != pLast; ++pFirst)
        FUN_1415d58a0(&backout, FUN_1415e5310(pFirst));
    return FUN_1416045f0(&backout);
}

// @0x1415e1440
Unk_StlElem<0x20>* FUN_1415e1440(Unk_StlElem<0x20>* pFirst, Unk_StlElem<0x20>* const pLast, Unk_StlElem<0x20>* const pDest, void* pAl, std::_General_ptr_iterator_tag, std::_Any_tag)
{
    Unk_StlBackout<Unk_StlElem<0x20>> backout{pDest, pAl};   // ctor 0x1415e62e0, dtor 0x1415ebd40
    for (; pFirst != pLast; ++pFirst)
        FUN_1415d5910(&backout, FUN_1415e5320(pFirst));
    return FUN_141604610(&backout);
}

// @0x1415e14d0
Unk_StlElem<0x10>* FUN_1415e14d0(Unk_StlElem<0x10>* const pFirst, Unk_StlElem<0x10>* const pLast, Unk_StlElem<0x10>* const pDest, void* pAl, std::_Really_trivial_ptr_iterator_tag, std::true_type)
{
    return FUN_1415d26a0(pFirst, pLast, pDest);
}

// @0x1415e1510
Unk_StlElem<0x18>* FUN_1415e1510(Unk_StlElem<0x18>* const pFirst, Unk_StlElem<0x18>* const pLast, Unk_StlElem<0x18>* const pDest, void* pAl, std::_Really_trivial_ptr_iterator_tag, std::true_type)
{
    return FUN_1415d2710(pFirst, pLast, pDest);
}

