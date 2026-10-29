// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Slice D of commonstruct.cpp#1: std::map<int,int> tree
// internals, vector<16-byte smart pointer>::_Insert(range) and the _Move/_Ptr_cat/_Ucopy/_Uninitialized_copy helpers.
// MS2-UNIT: commonfiles\commonstruct.cpp#1.wd
// MS2-RANGE: 0x140278a30-0x14027b180 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\commonstruct.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "commonstruct_wd.h"
#include "ms2/ms2recover.h"
#include <utility>

// @0x140278a30
// std::_Tree<map<int,int>>::_Insert_at(bool addleft, _Nodeptr where, _Valty&& val, _Nodeptr newnode)
i64 FUN_140278a30(void* tree, Unk_TIter* out, unsigned char addleft, Unk_TNode* where, i64 val, Unk_TNode* newnode)
{
    Unk_TVal* h = FUN_140287eb0(tree);
    if ((u64)(FUN_14028b050(tree) - 1) <= h->size) {
        FUN_1402876f0(tree, newnode);
        std::_Xlength_error("map/set<T> too long");
    }
    {
        Unk_TNode* node = FUN_140276fe0(tree, newnode, FUN_14027c160(val));
        h->size = h->size + 1;
        node->parent = where;
        if (where == h->head) {
            *FUN_1402894c0(h) = node;
            *FUN_140288630(h) = node;
            *FUN_1402894a0(h) = node;
        } else if (addleft) {
            where->left = node;
            if (where == *FUN_140288630(h))
                *FUN_140288630(h) = node;
        } else {
            where->right = node;
            if (where == *FUN_1402894a0(h))
                *FUN_1402894a0(h) = node;
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
                        FUN_140288640(h, cur);
                    }
                    cur->parent->color = 1;
                    cur->parent->parent->color = 0;
                    FUN_1402894e0(h, cur->parent->parent);
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
                        FUN_1402894e0(h, cur);
                    }
                    cur->parent->color = 1;
                    cur->parent->parent->color = 0;
                    FUN_140288640(h, cur->parent->parent);
                }
            }
        }
        (*FUN_1402894c0(h))->color = 1;
        FUN_14027d010(out, node, FUN_14027b570(h));
        return (i64)out;
    }
}
// @0x140278d90
// MS2-FUNCTIONAL: _Insert_hint: exe is 3124 bytes with C++ EH (flags=3) and debug-iterator branches; this version has no EH state and is 1763 bytes
// std::_Tree<map<int,int>>::_Insert_hint(const_iterator where, _Valty&& val, _Nodeptr newnode)
Unk_TIter* FUN_140278d90(void* tree, Unk_TIter* out, Unk_TIter where, i64 val, Unk_TNode* newnode)
{
    Unk_TIter next;
    FUN_14027cff0(&next);
    Unk_TVal* h = FUN_140287eb0(tree);
    if (FUN_14028b3f0(tree) == 0) {
        i64 v = FUN_14027c160(val);
        FUN_140278a30(tree, out, 1, h->head, v, newnode);
        return out;
    }
    Unk_TIter t38, t30, t28, t20[2];
    char atbegin = FUN_14027ee20(&where, FUN_14028a130(tree, &t38));
    if (atbegin == 0) {
        char atend = FUN_14027ee20(&where, FUN_14028a910(tree, &t30));
        if (atend == 0) {
            i64 a8 = FUN_1402885e0(tree, where.node);
            i64 a0 = FUN_140288610(tree, val);
            char before = FUN_14027f870(FUN_140288430(tree), a0, a8);
            if (before != 0) {
                next = where;
                i64 k90 = FUN_140288610(tree, val);
                Unk_TIter* prev = FUN_14027f720(&next);
                i64 k88 = FUN_1402885e0(tree, prev->node);
                char after = FUN_14027f870(FUN_140288430(tree), k88, k90);
                if (after != 0) {
                    if (next.node->right->isnil != 0) {
                        i64 v = FUN_14027c160(val);
                        FUN_140278a30(tree, out, 0, next.node, v, newnode);
                        return out;
                    }
                    i64 v = FUN_14027c160(val);
                    FUN_140278a30(tree, out, 1, where.node, v, newnode);
                    return out;
                }
            }
            i64 k80 = FUN_140288610(tree, val);
            i64 k78 = FUN_1402885e0(tree, where.node);
            char afterw = FUN_14027f870(FUN_140288430(tree), k78, k80);
            if (afterw != 0) {
                next = where;
                Unk_TIter* nx = FUN_14027f600(&next);
                char atend2 = FUN_14027ee20(nx, FUN_14028a910(tree, &t28));
                if (atend2 == 0) {
                    i64 k68 = FUN_1402885e0(tree, next.node);
                    i64 k60 = FUN_140288610(tree, val);
                    char lt = FUN_14027f870(FUN_140288430(tree), k60, k68);
                    if (lt == 0) goto nohint;
                }
                if (where.node->right->isnil != 0) {
                    i64 v = FUN_14027c160(val);
                    FUN_140278a30(tree, out, 0, where.node, v, newnode);
                    return out;
                }
                i64 v = FUN_14027c160(val);
                FUN_140278a30(tree, out, 1, next.node, v, newnode);
                return out;
            }
        } else {
            i64 c0 = FUN_140288610(tree, val);
            Unk_TNode** rm = FUN_1402894a0(h);
            i64 b8 = FUN_1402885e0(tree, *rm);
            char lt = FUN_14027f870(FUN_140288430(tree), b8, c0);
            if (lt != 0) {
                Unk_TNode** rm2 = FUN_1402894a0(h);
                i64 v = FUN_14027c160(val);
                FUN_140278a30(tree, out, 0, *rm2, v, newnode);
                return out;
            }
        }
    } else {
        i64 d8 = FUN_1402885e0(tree, where.node);
        i64 d0 = FUN_140288610(tree, val);
        char lt = FUN_14027f870(FUN_140288430(tree), d0, d8);
        if (lt != 0) {
            i64 v = FUN_14027c160(val);
            FUN_140278a30(tree, out, 1, where.node, v, newnode);
            return out;
        }
    }
nohint:
    i64 v = FUN_14027c160(val);
    Unk_TIterBool* r = FUN_1402799d0(tree, (Unk_TIterBool*)t20, 0, v, newnode);
    out->node = r->node;
    return out;
}
// @0x1402799d0
// MS2-FUNCTIONAL: exe keeps the STL's _TRY_BEGIN/_CATCH_ALL(_Destroy_if_not_nil(newnode)) frame (EH -2 slot, return jumps through the try end); a real try/catch here spills every local differently, so the guard is left out
// std::_Tree<map<int,int>>::_Insert_nohint(bool leftish, _Valty&& val, _Nodeptr newnode); 1036 bytes (Ghidra's 1024 is truncated)
Unk_TIterBool* FUN_1402799d0(void* tree, Unk_TIterBool* out, bool leftish, i64 val, Unk_TNode* newnode)
{
    Unk_TVal* h = FUN_140287eb0(tree);
    Unk_TNode* where = h->head;
    Unk_TNode* trynode = where->parent;
    bool addleft = true;
    while (!trynode->isnil) {
        where = trynode;
        if (leftish) {
            i64 kv = FUN_140288610(tree, val);
            i64 kt = FUN_1402885e0(tree, trynode);
            bool lt = FUN_14027f870(FUN_140288430(tree), kt, kv);
            addleft = !lt;
        } else {
            i64 kt = FUN_1402885e0(tree, trynode);
            i64 kv = FUN_140288610(tree, val);
            bool lt = FUN_14027f870(FUN_140288430(tree), kv, kt);
            addleft = lt;
        }
        trynode = addleft ? trynode->left : trynode->right;
    }
    if (0) {
        bool yes = true;
        Unk_TIter t;
        i64 r = FUN_140278a30(tree, &t, addleft, where, FUN_14027c160(val), newnode);
        FUN_140274d10(out, (Unk_TIter*)r, &yes);
        return out;
    } else {
        Unk_TIter res;
        FUN_14027d010(&res, where, FUN_14027b570(h));
        if (!addleft)
            ;
        else {
            Unk_TIter b;
            bool atbegin = FUN_14027ee20(&res, FUN_14028a130(tree, &b));
            if (atbegin) {
                bool yes = true;
                Unk_TIter t;
                i64 r = FUN_140278a30(tree, &t, 1, where, FUN_14027c160(val), newnode);
                FUN_140274d10(out, (Unk_TIter*)r, &yes);
                return out;
            } else
                FUN_14027f740(&res);
        }
        i64 kv = FUN_140288610(tree, val);
        i64 kw = FUN_1402885e0(tree, res.node);
        bool lt = FUN_14027f870(FUN_140288430(tree), kw, kv);
        if (lt) {
            bool yes = true;
            Unk_TIter t;
            i64 r = FUN_140278a30(tree, &t, addleft, where, FUN_14027c160(val), newnode);
            FUN_140274d10(out, (Unk_TIter*)r, &yes);
            return out;
        } else {
            FUN_1402876f0(tree, newnode);
            bool no = false;
            FUN_140274b10(out, &res, &no);
            return out;
        }
    }
}
// @0x140279de0
// MS2-FUNCTIONAL: vector::_Insert(range): exe carries EH state/_Reallocate guard layout (1158 bytes) that this straight version (1096) does not reproduce
// std::vector<16-byte smart pointer>::_Insert(const_iterator where, _Iter first, _Iter last, forward_iterator_tag)
void FUN_140279de0(void* vec, Unk_E16* where, i64 first, i64 last)
{
    i64 dist = FUN_14027bc70(first, last);
    u64 count = FUN_1401a4580(dist);
    Unk_E16** pfirst = (Unk_E16**)FUN_140288a40(vec);
    i64 whereoff = where - *pfirst;
    bool onebback;
    if (count == 1 && where == *(Unk_E16**)FUN_140288ba0(vec))
        onebback = true;
    else
        onebback = false;
    if (count != 0) {
        if (FUN_140289e50(vec) < count) {
            i64 size = FUN_14028b500(vec);
            i64 max = FUN_14028b180(vec);
            if ((u64)(max - size) < count)
                FUN_140289f00();
            u64 newcap = FUN_140287070(vec, size + count);
            void* al = FUN_1402883b0(vec);
            Unk_E16* newvec = FUN_14028a050(al, newcap);
            FUN_14027a900(vec, first, last, (i64)&newvec[whereoff]);
            if (onebback) {
                i64* l = FUN_140288ba0(vec);
                i64* f = FUN_140288a40(vec);
                FUN_140289cc0(vec, *f, *l, (i64)newvec);
            } else {
                i64* f = FUN_140288a40(vec);
                FUN_140289b00(vec, *f, (i64)where, (i64)newvec);
                i64* l = FUN_140288ba0(vec);
                FUN_140289b00(vec, (i64)where, *l, (i64)(newvec + whereoff + count));
            }
            FUN_1402873b0(vec, newvec, size + count, newcap);
        } else {
            Unk_E16* oldlast = *(Unk_E16**)FUN_140288ba0(vec);
            if (count < (u64)(oldlast - where)) {
                i64 nl = FUN_140289b00(vec, (i64)(oldlast - count), (i64)oldlast, (i64)oldlast);
                *FUN_140288ba0(vec) = nl;
                FUN_14027a390((i64)where, (i64)(oldlast - count), (i64)oldlast);
                FUN_140287670(vec, (i64)where, (i64)&where[count]);
                FUN_14027a900(vec, first, last, (i64)where);
            } else {
                i64 nl = FUN_140289b00(vec, (i64)where, (i64)oldlast, (i64)&where[count]);
                *FUN_140288ba0(vec) = nl;
                FUN_140287670(vec, (i64)where, (i64)oldlast);
                FUN_14027a900(vec, first, last, (i64)where);
            }
            FUN_140288d20(vec, (i64)where, (i64)oldlast);
        }
    }
}
// @0x14027a270
i64 FUN_14027a270(i64 p) { return p; }
// @0x14027a280
// std::_Tree<map<int,int>>::_Lbound(const int& key)
Unk_TNode* FUN_14027a280(void* tree, i64 key)
{
    Unk_TNode* where = FUN_140287ee0(tree)->head;
    Unk_TNode* trynode = where->parent;
    while (trynode->isnil == 0) {
        if (FUN_1402874c0(tree, FUN_1402885e0(tree, trynode), key)) {
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
i64 FUN_14027a320(i64 first, i64 last, i64 dest, Unk_StlTag)
{
    while (first != last) {
        last = last - 0x10;
        dest = dest - 0x10;
        FUN_14027e950(dest, FUN_14027c400(last));
    }
    return dest;
}
// @0x14027a390
void FUN_14027a390(i64 first, i64 last, i64 dest)
{
    char tag = FUN_14027a670(&first, &dest);
    FUN_14027a320(first, last, dest, *(Unk_StlTag*)&tag);
}
// @0x14027a3e0
// std::_Move_unchecked(first, last, dest) for the 16-byte element
i64 FUN_14027a3e0(i64 first, i64 last, i64 dest, Unk_StlTag)
{
    for (; first != last; dest += 0x10, first += 0x10)
        FUN_14027e950(dest, FUN_14027c400(first));
    return dest;
}
// @0x14027a450
void FUN_14027a450(i64 first, i64 last, i64 dest)
{
    char tag = FUN_14027a670(&first, &dest);
    FUN_14027a3e0(first, last, dest, *(Unk_StlTag*)&tag);
}
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
char FUN_14027a670(i64*, i64*) { Unk_StlTag tag = {}; return *(char*)&tag; }
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
void FUN_14027a740(i64 it, i64* p) { FUN_1402895c0(it, *p); }
// @0x14027a770
// std::map<int,int>::try_emplace(const int& key, ...)  [Ghidra's 0x147 is exact]
Unk_TIterBool* FUN_14027a770(void* tree, Unk_TIterBool* out, i64 key)
{
    Unk_TIter lb;
    Unk_TIter end;
    Unk_TIter res;
    Unk_TIter tup;
    bool ins;
    bool found;
    char pad;
    FUN_14028af20(tree, &lb, key);
    if (FUN_14027ee20(&lb, FUN_14028a910(tree, &end)) != 0 ||
        FUN_14027f870(FUN_140288430(tree), key, FUN_1402885e0(tree, lb.node)) != 0) {
        ins = true;
        Unk_TNode* hint = lb.node;
        void* vt = FUN_140162f80(&pad);
        FUN_140274d10(out, FUN_14027be90(tree, &res, hint, &std::piecewise_construct,
                                         FUN_14027c240(&tup, FUN_14027c1f0(key)), vt), &ins);
        return out;
    } else {
        found = false;
        FUN_140274b10(out, &lb, &found);
        return out;
    }
}
// @0x14027a8c0
void FUN_14027a8c0(void* vec, i64 first, i64 last, i64 dest) { FUN_14027a9d0(first, last, dest, FUN_1402882f0(vec)); }

// @0x14027a900
void FUN_14027a900(void* vec, i64 first, i64 last, i64 dest) { FUN_14027ac40(first, last, dest, (i64)FUN_1402883b0(vec)); }

// @0x14027a940
void FUN_14027a940(void* vec, i64 first, i64 last, i64 dest) { FUN_14027ad10(first, last, dest, FUN_1402883f0(vec)); }

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
        FUN_140277690(&bo, first);
    return FUN_140289090(&bo);
}

// @0x14027ae70
// std::_Uninitialized_copy_al_unchecked(first, last, dest, al, _Really_trivial..., _General_ptr_iterator_tag)
i64 FUN_14027ae70(i64 first, i64 last, i64 dest, i64 al, char, char)
{
    Unk_BackoutB bo(dest, al);
    for (; first != last; first += 0x30)
        FUN_1402776f0(&bo, first);
    return FUN_1402890b0(&bo);
}

// @0x14027af00
// std::_Uninitialized_copy_al_unchecked(first, last, dest, al, _Really_trivial..., _General_ptr_iterator_tag)
i64 FUN_14027af00(i64 first, i64 last, i64 dest, i64 al, char, char)
{
    Unk_BackoutC bo(dest, al);
    for (; first != last; first += 0x8)
        FUN_140277750(&bo, first);
    return FUN_1402890d0(&bo);
}

// @0x14027af90
// std::_Uninitialized_copy_al_unchecked(first, last, dest, al, _Really_trivial..., _General_ptr_iterator_tag)
i64 FUN_14027af90(i64 first, i64 last, i64 dest, i64 al, char, char)
{
    Unk_BackoutD bo(dest, al);
    for (; first != last; first += 0x10)
        FUN_1402777b0(&bo, first);
    return FUN_1402890f0(&bo);
}

// @0x14027b020
// std::_Uninitialized_copy_al_unchecked(first, last, dest, al, _Really_trivial..., _General_ptr_iterator_tag)
i64 FUN_14027b020(i64 first, i64 last, i64 dest, i64 al, char, char)
{
    Unk_BackoutE bo(dest, al);
    for (; first != last; first += 0x10)
        FUN_140277810(&bo, first);
    return FUN_140289110(&bo);
}
