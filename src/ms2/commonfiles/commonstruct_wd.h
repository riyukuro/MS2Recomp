// commonstruct_wd.h - slice D (0x140278a30-0x14027b180) of commonfiles\commonstruct.cpp#1: declarations only.
// The slice is the tail of the unit's COMDATs: the std::map<int,int> tree internals (_Insert_at/_Insert_hint/
// _Insert_nohint/_Lbound/try_emplace), vector<16-byte smart pointer>::_Insert(range), _Move/_Move_backward,
// _Ptr_cat tags, _Seek_wrapped setters, _Ucopy and _Uninitialized_copy(+_al_unchecked) of five element types.
// Loose types (i64 / raw pointers): rx2 reconciles with the other slices' headers at integration.
#pragma once
#include "ms2/commonfiles/commonstruct.h"
#include "ms2/commonfiles/commonstruct_backout.h"

typedef __int64 i64;
typedef unsigned __int64 u64;
// Empty tag object of the STL iterator-dispatch overloads (same spelling as commonstruct_wc.h).
struct Unk_StlTag {};

// std::_Tree_node header of map<int,int> (value pair<const int,int> at +0x1c); node size 0x28.
struct Unk_TNode { Unk_TNode* left; Unk_TNode* parent; Unk_TNode* right; char color; char isnil; };
// std::_Tree_val: head node pointer + element count.
struct Unk_TVal { Unk_TNode* head; u64 size; };
// _Tree_const_iterator / _Tree_iterator (release build: just the node pointer).
struct Unk_TIter { Unk_TNode* node; };
// pair<iterator,bool> result of _Insert_nohint / try_emplace.
struct Unk_TIterBool { Unk_TNode* node; bool inserted; };
// 16-byte vector element (intrusive smart pointer: unknown, pointer).
struct Unk_E16 { i64 a, b; };

// ---- tree helpers outside the slice ----
Unk_TVal* FUN_140287eb0(void* tree); Unk_TVal* FUN_140287ee0(void* tree);
i64 FUN_14028b050(void* tree); i64 FUN_14028b3f0(void* tree);
Unk_TNode** FUN_1402894c0(Unk_TVal*); Unk_TNode** FUN_140288630(Unk_TVal*); Unk_TNode** FUN_1402894a0(Unk_TVal*);
void FUN_140288640(Unk_TVal*, Unk_TNode*); void FUN_1402894e0(Unk_TVal*, Unk_TNode*);
Unk_TVal* FUN_14027b570(Unk_TVal*);
Unk_TIter* FUN_14027d010(Unk_TIter* out, Unk_TNode* node, Unk_TVal* val);
void FUN_1402876f0(void* tree, Unk_TNode* node);
i64 FUN_14027c160(i64 v); i64 FUN_14027c1f0(i64 v); i64 FUN_14027c240(void* out, i64 v);
Unk_TNode* FUN_140276fe0(void* tree, Unk_TNode* node, i64 val);
Unk_TIter* FUN_14027cff0(Unk_TIter*);
Unk_TIter* FUN_14028a130(void* tree, Unk_TIter* out); Unk_TIter* FUN_14028a910(void* tree, Unk_TIter* out);
bool FUN_14027ee20(Unk_TIter* a, Unk_TIter* b);
i64 FUN_1402885e0(void* tree, Unk_TNode* node); i64 FUN_140288610(void* tree, i64 val);
i64 FUN_140288430(void* tree);
bool FUN_14027f870(i64 comp, i64 a, i64 b);
unsigned char FUN_1402874c0(void* tree, i64 a, i64 b);
Unk_TIter* FUN_14027f720(Unk_TIter*); Unk_TIter* FUN_14027f600(Unk_TIter*); void FUN_14027f740(Unk_TIter*);
Unk_TIter* FUN_14028af20(void* tree, Unk_TIter* out, i64 key);
Unk_TIterBool* FUN_140274b10(Unk_TIterBool* out, Unk_TIter* it, bool* flag);
Unk_TIterBool* FUN_140274d10(Unk_TIterBool* out, Unk_TIter* it, bool* flag);
Unk_TIter* FUN_14027be90(void* tree, Unk_TIter* out, Unk_TNode* where, const void* piecewise, i64 keytuple, void* valtuple);
void* FUN_140162f80(void*); char* FUN_140177620(char*, char*);

// ---- vector<Unk_E16> helpers outside the slice ----
i64 FUN_14027bc70(i64 first, i64 last); u64 FUN_1401a4580(i64);
i64* FUN_140288a40(void* vec); i64* FUN_140288ba0(void* vec);
u64 FUN_140289e50(void* vec); i64 FUN_14028b500(void* vec); i64 FUN_14028b180(void* vec);
void FUN_140289f00(); u64 FUN_140287070(void* vec, u64 n);
void* FUN_1402883b0(void* vec); Unk_E16* FUN_14028a050(void* alloc, u64 n);
i64 FUN_140289cc0(void* vec, i64 first, i64 last, i64 dest);
i64 FUN_140289b00(void* vec, i64 first, i64 last, i64 dest);
void FUN_1402873b0(void* vec, Unk_E16* newvec, u64 size, u64 cap);
void FUN_140287670(void* vec, i64 first, i64 last);
void FUN_140288d20(void* vec, i64 first, i64 last);
i64 FUN_14027c400(i64); void FUN_14027e950(i64 dest, i64 src);
// ---- allocator / unchecked-iterator helpers ----
i64 FUN_1402882f0(void* vec); i64 FUN_1402883f0(void* vec);
void FUN_1402895c0(i64 it, i64 ptr);
i64 FUN_140278710(i64); i64 FUN_140278720(i64); i64 FUN_140278730(i64); i64 FUN_140278740(i64); i64 FUN_140278750(i64);
i64 FUN_140278780(i64, i64); i64 FUN_140278790(i64, i64); i64 FUN_1402787a0(i64, i64); i64 FUN_1402787b0(i64, i64); i64 FUN_1402787c0(i64, i64);
i64 FUN_1402788c0(i64*, i64*); i64 FUN_1402788f0(i64*, i64*); i64 FUN_140278920(i64*, i64*); i64 FUN_140278950(i64*, i64*); i64 FUN_140278980(i64*, i64*);
void FUN_140277690(Unk_BackoutA*, i64); void FUN_1402776f0(Unk_BackoutB*, i64); void FUN_140277750(Unk_BackoutC*, i64);
void FUN_1402777b0(Unk_BackoutD*, i64); void FUN_140277810(Unk_BackoutE*, i64);
i64 FUN_140289090(Unk_BackoutA*); i64 FUN_1402890b0(Unk_BackoutB*); i64 FUN_1402890d0(Unk_BackoutC*);
i64 FUN_1402890f0(Unk_BackoutD*); i64 FUN_140289110(Unk_BackoutE*);
i64 FUN_14027b320(i64, i64, i64, i64, char, char);

// ---- defined in this slice (declared for forward references) ----
i64 FUN_140278a30(void* tree, Unk_TIter* out, unsigned char addleft, Unk_TNode* where, i64 val, Unk_TNode* newnode);
Unk_TIter* FUN_140278d90(void* tree, Unk_TIter* out, Unk_TIter where, i64 val, Unk_TNode* newnode);
Unk_TIterBool* FUN_1402799d0(void* tree, Unk_TIterBool* out, bool leftish, i64 val, Unk_TNode* newnode);
i64 FUN_14027a270(i64 p);
Unk_TNode* FUN_14027a280(void* tree, i64 key);
i64 FUN_14027a320(i64 first, i64 last, i64 dest, Unk_StlTag);
void FUN_14027a390(i64 first, i64 last, i64 dest);
i64 FUN_14027a3e0(i64 first, i64 last, i64 dest, Unk_StlTag);
void FUN_14027a450(i64 first, i64 last, i64 dest);
void FUN_14027a4d0(i64, i64, Unk_StlTag); void FUN_14027a510(i64, i64, Unk_StlTag);
char FUN_14027a520(i64*, i64*); char FUN_14027a550(i64*, i64*); char FUN_14027a580(i64*, i64*); char FUN_14027a5b0(i64*, i64*);
char FUN_14027a5e0(i64*, i64*); char FUN_14027a610(i64*, i64*); char FUN_14027a640(i64*, i64*); char FUN_14027a670(i64*, i64*);
void FUN_14027a6a0(i64*, i64); void FUN_14027a6c0(i64*, i64); void FUN_14027a6e0(i64*, i64); void FUN_14027a700(i64*, i64); void FUN_14027a720(i64*, i64);
void FUN_14027a8c0(void* vec, i64 first, i64 last, i64 dest); void FUN_14027a900(void* vec, i64 first, i64 last, i64 dest);
void FUN_14027a940(void* vec, i64 first, i64 last, i64 dest);
void FUN_14027a740(i64 it, i64* p);
Unk_TIterBool* FUN_14027a770(void* tree, Unk_TIterBool* out, i64 key);
i64 FUN_14027a980(i64); i64 FUN_14027a990(i64); i64 FUN_14027a9a0(i64); i64 FUN_14027a9b0(i64); i64 FUN_14027a9c0(i64);
i64 FUN_14027a9d0(i64, i64, i64, i64); i64 FUN_14027aaa0(i64, i64, i64, i64); i64 FUN_14027ab70(i64, i64, i64, i64);
i64 FUN_14027ac40(i64, i64, i64, i64); i64 FUN_14027ad10(i64, i64, i64, i64); i64 FUN_14027b0b0(i64, i64, i64, i64);
i64 FUN_14027ade0(i64, i64, i64, i64, char, char); i64 FUN_14027ae70(i64, i64, i64, i64, char, char);
i64 FUN_14027af00(i64, i64, i64, i64, char, char); i64 FUN_14027af90(i64, i64, i64, i64, char, char);
i64 FUN_14027b020(i64, i64, i64, i64, char, char);
