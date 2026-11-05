// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Slice D of commonstruct.cpp#1: std::map<int,int> tree
// internals, vector<16-byte smart pointer>::_Insert(range) and the _Move/_Ptr_cat/_Ucopy/_Uninitialized_copy helpers.
// MS2-UNIT: commonfiles\commonstruct.cpp#1.wd
// MS2-RANGE: 0x140278a30-0x14027b180 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\commonstruct.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "commonstruct_wd.h"
#include "ms2/ms2recover.h"
#include <utility>
#include <map>
#include <vector>
#include "ms2/commonfiles/itemgift.h"
#include "ms2/commonfiles/probability.h"
#include "ms2/commonfiles/itemoptiondata.h"
#include "ms2/placeholder/itemremakeoption.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/packetlogqueue.h"
// The STL instances behind the slice's tree/vector views (C3: the calls go to their members).
typedef std::map<int, int> MapII;
typedef MapII::_Mybase TreeII;
typedef std::_Tree_val<std::_Tree_simple_types<std::pair<const int, int>>> TValII;
typedef TValII::_Nodeptr NodeII; struct WdTreeAcc : TreeII { using TreeII::_Destroy_if_node; using TreeII::_Key; };   // the protected _Tree members
typedef MS2Ptr<CIngredientInfo> PIng;
typedef MS2Ptr<Probability::LogContext> PLog;
typedef std::vector<PIng> VIng;
typedef std::vector<PLog> VLog;
typedef std::vector<MS2Ptr<CPtred>> VPtred;
typedef std::vector<Unk_RemakeLockOpt> VRemake;

// @0x140278a30
// std::_Tree<map<int,int>>::_Insert_at(bool addleft, _Nodeptr where, _Valty&& val, _Nodeptr newnode)
i64 FUN_140278a30(void* tree, Unk_TIter* out, unsigned char addleft, Unk_TNode* where, i64 val, Unk_TNode* newnode)
{
    Unk_TVal* h = (Unk_TVal*)&reinterpret_cast<TreeII*>(tree)->_Get_data();
    if ((u64)(reinterpret_cast<TreeII*>(tree)->max_size() - 1) <= h->size) {
        static_cast<WdTreeAcc*>(reinterpret_cast<TreeII*>(tree))->_Destroy_if_node(reinterpret_cast<NodeII>(newnode));
        std::_Xlength_error("map/set<T> too long");
    }
    {
        Unk_TNode* node = (Unk_TNode*)FUN_140276fe0((__int64)tree, (__int64)newnode, FUN_14027c160(val));
        h->size = h->size + 1;
        node->parent = where;
        if (where == h->head) {
            *(Unk_TNode**)&reinterpret_cast<TValII*>(h)->_Root() = node;
            *(Unk_TNode**)reinterpret_cast<ATL::CAtlArray<Unk_CommonPacketLogEntry>*>(h)->GetData() = node;
            *(Unk_TNode**)&reinterpret_cast<TValII*>(h)->_Rmost() = node;
        } else if (addleft) {
            where->left = node;
            if (where == *(Unk_TNode**)reinterpret_cast<ATL::CAtlArray<Unk_CommonPacketLogEntry>*>(h)->GetData())
                *(Unk_TNode**)reinterpret_cast<ATL::CAtlArray<Unk_CommonPacketLogEntry>*>(h)->GetData() = node;
        } else {
            where->right = node;
            if (where == *(Unk_TNode**)&reinterpret_cast<TValII*>(h)->_Rmost())
                *(Unk_TNode**)&reinterpret_cast<TValII*>(h)->_Rmost() = node;
        }
        Unk_TNode* cur = node;
        while (cur->parent->color == 0) {
            if (cur->parent == cur->parent->parent->left) {
                where = cur->parent->parent->right;
                if (where->color == 0) {
                    cur->parent->color = 1;
                    where->color = 1;
                    cur->parent->parent->color = 0;
                    cur = cur->parent->parent;
                } else {
                    if (cur == cur->parent->right) {
                        cur = cur->parent;
                        reinterpret_cast<TValII*>(h)->_Lrotate((NodeII)(cur));
                    }
                    cur->parent->color = 1;
                    cur->parent->parent->color = 0;
                    reinterpret_cast<TValII*>(h)->_Rrotate((NodeII)(cur->parent->parent));
                }
            } else {
                where = cur->parent->parent->left;
                if (where->color == 0) {
                    cur->parent->color = 1;
                    where->color = 1;
                    cur->parent->parent->color = 0;
                    cur = cur->parent->parent;
                } else {
                    if (cur == cur->parent->left) {
                        cur = cur->parent;
                        reinterpret_cast<TValII*>(h)->_Rrotate((NodeII)(cur));
                    }
                    cur->parent->color = 1;
                    cur->parent->parent->color = 0;
                    reinterpret_cast<TValII*>(h)->_Lrotate((NodeII)(cur->parent->parent));
                }
            }
        }
        (*(Unk_TNode**)&reinterpret_cast<TValII*>(h)->_Root())->color = 1;
        FUN_14027d010(out, (__int64)node, FUN_14027b570((__int64)h));
        return (i64)out;
    }
}
// _Insert_hint's repeated pieces: _Key(node), _Kfn(val), _DEBUG_LT_PRED(_Getcomp(), l, r), _Insert_at(leftish, node, forward(val), newnode)
#define WD_KEY(n) (static_cast<WdTreeAcc*>(reinterpret_cast<TreeII*>(tree))->_Key(reinterpret_cast<NodeII>(n)))
#define WD_KFN() (*(const int*)FUN_140288610(tree, val))
#define WD_LT(l, r) reinterpret_cast<TreeII*>(tree)->_Getcomp()(l, r)
#define WD_INSERT_AT(left, n) FUN_140278a30(tree, out, left, (n), FUN_14027c160(val), newnode)
#define WD_PREV(it) ((Unk_TIter*)&--*reinterpret_cast<MapII::const_iterator*>(&(it)))
#define WD_CIT(it) (*reinterpret_cast<MapII::const_iterator*>(&(it)))
// @0x140278d90
// std::_Tree<map<int,int>>::_Insert_hint(const_iterator where, _Valty&& val, _Nodeptr newnode) (VS2017 15.8 shape: _Multi branch kept, try/catch(...) frees newnode)
Unk_TIter* FUN_140278d90(void* tree, Unk_TIter* out, Unk_TIter where, i64 val, Unk_TNode* newnode)
{
    Unk_TIter next;
    FUN_14027cff0(&next);
    bool leftish = false;
    Unk_TVal* h = (Unk_TVal*)&reinterpret_cast<TreeII*>(tree)->_Get_data();
    try {
        if (reinterpret_cast<TreeII*>(tree)->size() == 0) {
            WD_INSERT_AT(true, h->head);
            return out;
        } else if (TreeII::_Multi) {
            if (WD_CIT(where) == reinterpret_cast<TreeII*>(tree)->begin()) {
                if (!WD_LT(WD_KEY(where.node), WD_KFN())) {
                    WD_INSERT_AT(true, where.node);
                    return out;
                }
                leftish = true;
            } else if (WD_CIT(where) == reinterpret_cast<TreeII*>(tree)->end()) {
                if (!WD_LT(WD_KFN(), WD_KEY(*(Unk_TNode**)&reinterpret_cast<TValII*>(h)->_Rmost()))) {
                    WD_INSERT_AT(false, *(Unk_TNode**)&reinterpret_cast<TValII*>(h)->_Rmost());
                    return out;
                }
            } else if (!WD_LT(WD_KEY(where.node), WD_KFN()) && !WD_LT(WD_KFN(), WD_KEY(WD_PREV(next = where)->node))) {
                if (next.node->right->isnil) {
                    WD_INSERT_AT(false, next.node);
                    return out;
                } else {
                    WD_INSERT_AT(true, where.node);
                    return out;
                }
            } else if (!WD_LT(WD_KFN(), WD_KEY(where.node)) && (++WD_CIT(next = where) == reinterpret_cast<TreeII*>(tree)->end() || !WD_LT(WD_KEY(next.node), WD_KFN()))) {
                if (where.node->right->isnil) {
                    WD_INSERT_AT(false, where.node);
                    return out;
                } else {
                    WD_INSERT_AT(true, next.node);
                    return out;
                }
            } else
                leftish = true;
        } else {
            if (WD_CIT(where) == reinterpret_cast<TreeII*>(tree)->begin()) {
                if (WD_LT(WD_KFN(), WD_KEY(where.node))) {
                    WD_INSERT_AT(true, where.node);
                    return out;
                }
            } else if (WD_CIT(where) == reinterpret_cast<TreeII*>(tree)->end()) {
                if (WD_LT(WD_KEY(*(Unk_TNode**)&reinterpret_cast<TValII*>(h)->_Rmost()), WD_KFN())) {
                    WD_INSERT_AT(false, *(Unk_TNode**)&reinterpret_cast<TValII*>(h)->_Rmost());
                    return out;
                }
            } else if (WD_LT(WD_KFN(), WD_KEY(where.node)) && WD_LT(WD_KEY(WD_PREV(next = where)->node), WD_KFN())) {
                if (next.node->right->isnil) {
                    WD_INSERT_AT(false, next.node);
                    return out;
                } else {
                    WD_INSERT_AT(true, where.node);
                    return out;
                }
            } else if (WD_LT(WD_KEY(where.node), WD_KFN()) && (++WD_CIT(next = where) == reinterpret_cast<TreeII*>(tree)->end() || WD_LT(WD_KFN(), WD_KEY(next.node)))) {
                if (where.node->right->isnil) {
                    WD_INSERT_AT(false, where.node);
                    return out;
                } else {
                    WD_INSERT_AT(true, next.node);
                    return out;
                }
            }
        }
    } catch (...) {
        static_cast<WdTreeAcc*>(reinterpret_cast<TreeII*>(tree))->_Destroy_if_node(reinterpret_cast<NodeII>(newnode));
        throw;
    }
    Unk_TIterBool r;
    *out = *(Unk_TIter*)FUN_1402799d0(tree, &r, leftish, FUN_14027c160(val), newnode);
    return out;
}
// @0x1402799d0
// std::_Tree<map<int,int>>::_Insert_nohint(bool leftish, _Valty&& val, _Nodeptr newnode) (VS2017 15.8 shape: _Multi branch kept, try/catch(...) frees newnode)
Unk_TIterBool* FUN_1402799d0(void* tree, Unk_TIterBool* out, bool leftish, i64 val, Unk_TNode* newnode)
{
    Unk_TVal* h = (Unk_TVal*)&reinterpret_cast<TreeII*>(tree)->_Get_data();
    try {
        Unk_TNode* wherenode = h->head;
        Unk_TNode* trynode = wherenode->parent;
        bool addleft = true;
        while (!trynode->isnil) {
            wherenode = trynode;
            if (leftish)
                addleft = !WD_LT(WD_KEY(trynode), WD_KFN());
            else
                addleft = WD_LT(WD_KFN(), WD_KEY(trynode));
            trynode = addleft ? trynode->left : trynode->right;
        }
        if (TreeII::_Multi) {
            bool yes = true;
            Unk_TIter t;
            FUN_140274d10((__int64*)out, FUN_140278a30(tree, &t, addleft, wherenode, FUN_14027c160(val), newnode), (__int64)&yes);
            return out;
        } else {
            Unk_TIter where;
            FUN_14027d010(&where, (__int64)wherenode, FUN_14027b570((__int64)h));
            if (!addleft)
                ;
            else if (reinterpret_cast<MapII::const_iterator&>(where) == reinterpret_cast<TreeII*>(tree)->begin()) {
                bool yes = true;
                Unk_TIter t;
                FUN_140274d10((__int64*)out, FUN_140278a30(tree, &t, true, wherenode, FUN_14027c160(val), newnode), (__int64)&yes);
                return out;
            } else
                --*reinterpret_cast<MapII::iterator*>(&where);
            if (WD_LT(WD_KEY(where.node), WD_KFN())) {
                bool yes = true;
                Unk_TIter t;
                FUN_140274d10((__int64*)out, FUN_140278a30(tree, &t, addleft, wherenode, FUN_14027c160(val), newnode), (__int64)&yes);
                return out;
            } else {
                static_cast<WdTreeAcc*>(reinterpret_cast<TreeII*>(tree))->_Destroy_if_node(reinterpret_cast<NodeII>(newnode));
                bool no = false;
                FUN_140274b10((__int64*)out, (__int64)&where, (__int64)&no);
                return out;
            }
        }
    } catch (...) {
        static_cast<WdTreeAcc*>(reinterpret_cast<TreeII*>(tree))->_Destroy_if_node(reinterpret_cast<NodeII>(newnode));
        throw;
    }
}
#undef WD_KEY
#undef WD_KFN
#undef WD_LT
#undef WD_INSERT_AT
#undef WD_PREV
#undef WD_CIT
// @0x140279de0
// std::vector<MS2Ptr<CIngredientInfo>>::_Insert_range<PIng*>(.., forward_iterator_tag), reached from insert 0x14027c290
template void VIng::_Insert_range<PIng*>(VIng::const_iterator, PIng*, PIng*, std::forward_iterator_tag);












































































// @0x14027a270
i64 FUN_14027a270(i64 p) { return p; }
// @0x14027a280
// std::_Tree<map<int,int>>::_Lbound(const int& key)
Unk_TNode* FUN_14027a280(void* tree, i64 key)
{
    Unk_TNode* where = FUN_140287ee0(tree)->head;
    Unk_TNode* trynode = where->parent;
    while (trynode->isnil == 0) {
        if (FUN_1402874c0(tree, (i64)&static_cast<WdTreeAcc*>(reinterpret_cast<TreeII*>(tree))->_Key(reinterpret_cast<NodeII>(trynode)), key)) {
            trynode = trynode->right;
        } else {
            where = trynode;
            trynode = trynode->left;
        }
    }
    return where;
}
// @0x14027a320
// std::_Move_backward_unchecked(first, last, dest) for the 16-byte element
template PIng* std::_Move_backward_unchecked1<PIng*, PIng*>(PIng*, PIng*, PIng*, std::_General_ptr_iterator_tag);








// @0x14027a390
template PIng* std::_Move_backward_unchecked<PIng*, PIng*>(PIng*, PIng*, PIng*);




// @0x14027a3e0
// std::_Move_unchecked(first, last, dest) for the 16-byte element
template PIng* std::_Move_unchecked1<PIng*, PIng*>(PIng*, PIng*, PIng*, std::_General_ptr_iterator_tag);





// @0x14027a450
template PIng* std::_Move_unchecked<PIng*, PIng*>(PIng*, PIng*, PIng*);




// @0x14027a4a0
// std::_Pocca(_Wrap_alloc&, const _Wrap_alloc&)
void FUN_14027a4a0(i64 a, i64 b)
{
    Unk_StlTag tag;
    FUN_14027a4d0(a, b, tag);
}
// @0x14027a4d0
void FUN_14027a4d0(i64, i64, Unk_StlTag) {}
// @0x14027a4e0
void FUN_14027a4e0(i64 a, i64 b)
{
    Unk_StlTag tag;
    FUN_14027a510(a, b, tag);
}
// @0x14027a510
void FUN_14027a510(i64, i64, Unk_StlTag) {}
// @0x14027a520
char FUN_14027a520(i64*, i64*) { Unk_StlTag tag = {}; return *(char*)&tag; }
// @0x14027a550
char FUN_14027a550(i64*, i64*) { Unk_StlTag tag = {}; return *(char*)&tag; }
// @0x14027a580
char FUN_14027a580(i64*, i64*) { Unk_StlTag tag = {}; return *(char*)&tag; }
// @0x14027a5b0
char FUN_14027a5b0(i64*, i64*) { Unk_StlTag tag = {}; return *(char*)&tag; }
// @0x14027a5e0
char FUN_14027a5e0(i64*, i64*) { Unk_StlTag tag = {}; return *(char*)&tag; }
// @0x14027a610
char FUN_14027a610(i64*, i64*) { Unk_StlTag tag = {}; return *(char*)&tag; }
// @0x14027a640
char FUN_14027a640(i64*, i64*) { Unk_StlTag tag = {}; return *(char*)&tag; }
// @0x14027a670
template std::_General_ptr_iterator_tag std::_Ptr_move_cat<PIng, PIng>(PIng* const&, PIng* const&);
// @0x14027a6a0
void FUN_14027a6a0(i64* p, i64 v) { *p = v; }
// @0x14027a6c0
void FUN_14027a6c0(i64* p, i64 v) { *p = v; }
// @0x14027a6e0
void FUN_14027a6e0(i64* p, i64 v) { *p = v; }
// @0x14027a700
void FUN_14027a700(i64* p, i64 v) { *p = v; }
// @0x14027a720
void FUN_14027a720(i64* p, i64 v) { *p = v; }
// @0x14027a740
void FUN_14027a740(i64 it, i64* p) { reinterpret_cast<std::vector<ItemOptionValueRandom*>::const_iterator*>(it)->_Seek_to((ItemOptionValueRandom* const*)(*p)); }
// @0x14027a770
// std::map<int,int>::try_emplace(const int& key, ...)  [Ghidra's 0x147 is exact]
Unk_TIterBool* FUN_14027a770(void* tree, Unk_TIterBool* out, i64 key)
{
    MapII::iterator lb = reinterpret_cast<TreeII*>(tree)->lower_bound(*(const int*)key);
    //
    Unk_TIter res;
    Unk_TIter tup;
    bool ins;
    bool found;
    char pad;
    //
    if ((reinterpret_cast<MapII::const_iterator&>(lb) == reinterpret_cast<TreeII*>(tree)->end()) != 0 ||
        reinterpret_cast<TreeII*>(tree)->_Getcomp()(*(const int*)(key), static_cast<WdTreeAcc*>(reinterpret_cast<TreeII*>(tree))->_Key(lb._Ptr)) != 0) {
        ins = true;
        Unk_TNode* hint = (Unk_TNode*)lb._Ptr;
        void* vt = FUN_140162f80(&pad);
        FUN_140274d10((__int64*)out, FUN_14027be90((__int64)tree, (__int64)&res, (__int64)hint, (__int64)&std::piecewise_construct,
                                         FUN_14027c240((__int64)&tup, FUN_14027c1f0(key)), (__int64)vt), (__int64)&ins);
        return out;
    } else {
        found = false;
        FUN_140274b10((__int64*)out, (__int64)&lb, (__int64)&found);
        return out;
    }
}
// @0x14027a8c0
i64 FUN_14027a8c0(i64 vec, i64 first, i64 last, i64 dest) { return FUN_14027a9d0(first, last, dest, (i64)&reinterpret_cast<VRemake*>(vec)->_Getal()); }

// @0x14027a900
void FUN_14027a900(void* vec, i64 first, i64 last, i64 dest) { FUN_14027ac40(first, last, dest, (i64)&reinterpret_cast<VIng*>(vec)->_Getal()); }

// @0x14027a940
void FUN_14027a940(void* vec, i64 first, i64 last, i64 dest) { FUN_14027ad10(first, last, dest, (i64)&reinterpret_cast<VLog*>(vec)->_Getal()); }

// @0x14027a980
i64 FUN_14027a980(i64 p) { return p; }

// @0x14027a990
i64 FUN_14027a990(i64 p) { return p; }

// @0x14027a9a0
i64 FUN_14027a9a0(i64 p) { return p; }

// @0x14027a9b0
i64 FUN_14027a9b0(i64 p) { return p; }

// @0x14027a9c0
i64 FUN_14027a9c0(i64 p) { return p; }

// @0x14027a9d0
// std::_Uninitialized_copy(first, last, dest, al)
i64 FUN_14027a9d0(i64 first, i64 last, i64 dest, i64 al)
{
    i64 f = FUN_140278710(first);
    i64 l = FUN_140278710(last);
    i64 d = FUN_140278780(dest, FUN_1402788c0(&f, &l));
    char tag1;
    char pad;
    char* p = &tag1;
    char t = FUN_14027a520(&f, &d);
    FUN_14027a6a0(&dest, FUN_14027ade0(f, l, d, al, t, *FUN_140177620(p, &pad)));
    return dest;
}

// @0x14027aaa0
// std::_Uninitialized_copy(first, last, dest, al)
i64 FUN_14027aaa0(i64 first, i64 last, i64 dest, i64 al)
{
    i64 f = FUN_140278720(first);
    i64 l = FUN_140278720(last);
    i64 d = FUN_140278790(dest, FUN_1402788f0(&f, &l));
    char tag1;
    char pad;
    char* p = &tag1;
    char t = FUN_14027a550(&f, &d);
    FUN_14027a6c0(&dest, FUN_14027ae70(f, l, d, al, t, *FUN_140177620(p, &pad)));
    return dest;
}

// @0x14027ab70
// std::_Uninitialized_copy(first, last, dest, al)
i64 FUN_14027ab70(i64 first, i64 last, i64 dest, i64 al)
{
    i64 f = FUN_140278730(first);
    i64 l = FUN_140278730(last);
    i64 d = FUN_1402787a0(dest, FUN_140278920(&f, &l));
    char tag1;
    char pad;
    char* p = &tag1;
    char t = FUN_14027a580(&f, &d);
    FUN_14027a6e0(&dest, FUN_14027af00(f, l, d, al, t, *FUN_140177620(p, &pad)));
    return dest;
}

// @0x14027ac40
// std::_Uninitialized_copy(first, last, dest, al)
i64 FUN_14027ac40(i64 first, i64 last, i64 dest, i64 al)
{
    i64 f = FUN_140278740(first);
    i64 l = FUN_140278740(last);
    i64 d = FUN_1402787b0(dest, FUN_140278950(&f, &l));
    char tag1;
    char pad;
    char* p = &tag1;
    char t = FUN_14027a5b0(&f, &d);
    FUN_14027a700(&dest, FUN_14027af90(f, l, d, al, t, *FUN_140177620(p, &pad)));
    return dest;
}

// @0x14027ad10
// std::_Uninitialized_copy(first, last, dest, al)
i64 FUN_14027ad10(i64 first, i64 last, i64 dest, i64 al)
{
    i64 f = FUN_140278750(first);
    i64 l = FUN_140278750(last);
    i64 d = FUN_1402787c0(dest, FUN_140278980(&f, &l));
    char tag1;
    char pad;
    char* p = &tag1;
    char t = FUN_14027a5e0(&f, &d);
    FUN_14027a720(&dest, FUN_14027b020(f, l, d, al, t, *FUN_140177620(p, &pad)));
    return dest;
}

// @0x14027b0b0
// std::_Uninitialized_copy(first, last, dest, al)
i64 FUN_14027b0b0(i64 first, i64 last, i64 dest, i64 al)
{
    i64 f = FUN_140278720(first);
    i64 l = FUN_140278720(last);
    i64 d = FUN_140278790(dest, FUN_1402788f0(&f, &l));
    char tag1;
    char pad;
    char* p = &tag1;
    char t = FUN_14027a610(&f, &d);
    FUN_14027a6c0(&dest, FUN_14027b320(f, l, d, al, t, *FUN_140177620(p, &pad)));
    return dest;
}

// @0x14027ade0
// std::_Uninitialized_copy_al_unchecked(first, last, dest, al, _Really_trivial..., _General_ptr_iterator_tag)
i64 FUN_14027ade0(i64 first, i64 last, i64 dest, i64 al, char, char)
{
    Unk_BackoutA bo(dest, al);
    for (; first != last; first += 0x8)
        FUN_140277690((__int64)&bo, first);
    return (i64)reinterpret_cast<std::_Uninitialized_backout_al<CString*, std::allocator<CString>>*>(&bo)->_Release();
}

// @0x14027ae70
// std::_Uninitialized_copy_al_unchecked(first, last, dest, al, _Really_trivial..., _General_ptr_iterator_tag)
i64 FUN_14027ae70(i64 first, i64 last, i64 dest, i64 al, char, char)
{
    Unk_BackoutB bo(dest, al);
    for (; first != last; first += 0x30)
        FUN_1402776f0((__int64)&bo, first);
    return (i64)reinterpret_cast<std::_Uninitialized_backout_al<ItemEntity*, std::allocator<ItemEntity>>*>(&bo)->_Release();
}

// @0x14027af00
// std::_Uninitialized_copy_al_unchecked(first, last, dest, al, _Really_trivial..., _General_ptr_iterator_tag)
i64 FUN_14027af00(i64 first, i64 last, i64 dest, i64 al, char, char)
{
    Unk_BackoutC bo(dest, al);
    for (; first != last; first += 0x8)
        FUN_140277750((__int64)&bo, first);
    return (i64)reinterpret_cast<std::_Uninitialized_backout_al<PIng*, std::allocator<PIng>>*>(&bo)->_Release();
}

// @0x14027af90
// std::_Uninitialized_copy_al_unchecked(first, last, dest, al, _Really_trivial..., _General_ptr_iterator_tag)
i64 FUN_14027af90(i64 first, i64 last, i64 dest, i64 al, char, char)
{
    Unk_BackoutD bo(dest, al);
    for (; first != last; first += 0x10)
        FUN_1402777b0((__int64)&bo, first);
    return (i64)reinterpret_cast<std::_Uninitialized_backout_al<MS2Ptr<CPtred>*, std::allocator<MS2Ptr<CPtred>>>*>(&bo)->_Release();
}

// @0x14027b020
// std::_Uninitialized_copy_al_unchecked(first, last, dest, al, _Really_trivial..., _General_ptr_iterator_tag)
i64 FUN_14027b020(i64 first, i64 last, i64 dest, i64 al, char, char)
{
    Unk_BackoutE bo(dest, al);
    for (; first != last; first += 0x10)
        FUN_140277810((__int64)&bo, first);
    return (i64)reinterpret_cast<std::_Uninitialized_backout_al<PLog*, std::allocator<PLog>>*>(&bo)->_Release();
}
