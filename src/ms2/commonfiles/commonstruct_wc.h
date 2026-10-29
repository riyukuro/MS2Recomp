// commonstruct_wc.h - slice C (0x140274970-0x140278a30) of commonfiles\commonstruct.cpp#1: declarations only.
// Loose-typed externs for functions outside the slice (ATL/STL/smart-pointer helpers at 0x14027c...-0x14028b...).
// Every extern is declared with __int64/pointer stand-ins; rx2 reconciles duplicates at integration.
#pragma once
#include "ms2/commonfiles/commonstruct.h"
#include "ms2/ms2format.h"

typedef __int64 i64;
typedef unsigned __int64 u64;
// Empty tag object of the STL iterator-dispatch overloads (_Scalar/_Nonscalar_ptr_iterator_tag, _Zero_then_variadic_args_t ...).
struct Unk_StlTag {};

// Owner of the string getter 0x1402728f0 (slice B); `this` in rcx, CStringW result through the hidden pointer.
struct Unk_CwObj { CStringW FUN_1402728f0(); };

// ---- externs outside the slice (all i64 parameters unless noted) ----
void FUN_1412751b0(const CStringW&, int);
i64 FUN_14027d550(i64); i64 FUN_14027d560(i64); i64 FUN_14027d570(i64); i64 FUN_14027d580(i64);
i64 FUN_14027d590(i64); i64 FUN_14027d5a0(i64); i64 FUN_14027d5b0(i64);
i64 FUN_14027cf10(i64); i64 FUN_14027d0b0(i64); i64 FUN_14027d410(i64); i64 FUN_14027d450(i64);
i64 FUN_14027d490(i64); i64 FUN_14027d4d0(i64); i64 FUN_14027d510(i64);
i64* FUN_14027c1b0(i64); i64* FUN_14027c220(i64); i64 FUN_14027c1c0(i64);
char* FUN_140162f70(i64); char* FUN_140162f10(i64);
i64 FUN_14015e600(i64, Unk_StlTag);
u64 FUN_14027c1f0(i64); u64 FUN_14027c360(i64); u64 FUN_14027c380(i64); u64 FUN_14027c3a0(i64); u64 FUN_14027c3c0(i64);
i64 FUN_14027c410(i64); unsigned* FUN_14027c270(i64);
void FUN_14027c110(void*, const void*, void*);
void FUN_1401855a0(void* list, unsigned id);
void FUN_14028b2d0(void* vec, const CString&);
CString FUN_14015efc0(const CString&);
int FUN_140873890(void*, const char*, int&);
i64 FUN_14027cd50(i64);
i64 FUN_14027f550(i64); i64 FUN_14027f700(i64);
// vector / list internals (0x14027a..0x14028b)
i64 FUN_14027bc40(i64, i64); i64 FUN_14027bca0(i64, i64); u64 FUN_1401a4580(i64);
i64 FUN_140288c60(i64); i64 FUN_140288ce0(i64);
u64 FUN_14028b430(i64); u64 FUN_14028b540(i64); u64 FUN_14028a2c0(i64); u64 FUN_14028a3d0(i64);
u64 FUN_14028b090(i64); u64 FUN_14028b1d0(i64);
void FUN_140289ea0(); void FUN_140289f20(); void FUN_140289f00(); void FUN_140289ec0(); void FUN_140289ee0();
i64 FUN_140286ec0(i64, u64); i64 FUN_140287100(i64, u64);
i64* FUN_140288980(i64); i64* FUN_140288ae0(i64); i64* FUN_140288a80(i64); i64* FUN_140288be0(i64);
i64 FUN_1402875b0(i64, i64, i64); i64 FUN_1402876b0(i64, i64, i64);
i64 FUN_1402882f0(i64); i64 FUN_1402883f0(i64);
i64 FUN_14028a7d0(i64, i64, u64); i64 FUN_14028a890(i64, i64, u64);
i64 FUN_140286a60(i64, i64); i64 FUN_140286b50(i64, i64);
i64 FUN_14027a8c0(i64, i64, i64, i64); i64 FUN_14027a940(i64, i64, i64, i64);
i64 FUN_14027c420(i64, u64); i64 FUN_14027c450(i64, u64);
i64 FUN_140286de0(i64); i64 FUN_140286d20(i64, i64, i64);
i64 FUN_140162f40(i64); i64 FUN_14027c230(i64); i64 FUN_140162ef0(i64);
// map<int,int> node value (pair<const int,int>); addressof() takes it by reference.
struct Unk_TreeValue { int key; int value; };
i64 FUN_14027b540(Unk_TreeValue&); i64 FUN_140288290(i64); i64 FUN_14027b790(i64, i64, i64, i64, i64);
i64 FUN_140288250(i64); i64 FUN_14027c1e0(i64); i64 FUN_14027b550(i64&); i64 FUN_14027bac0(i64, i64, i64);
void FUN_140287df0(i64, i64); void FUN_14028a770(i64, i64, i64);
i64 FUN_14027eaf0(i64, i64);
char FUN_14027a520(i64*, i64*); char FUN_14027a5e0(i64*, i64*);
i64 FUN_14027a990(i64); i64 FUN_14027a9a0(i64); i64 FUN_14027a9b0(i64); i64 FUN_14027a9c0(i64); i64 FUN_14027a980(i64);
i64 FUN_14027bb90(i64, i64); i64 FUN_14027bbc0(i64, i64); i64 FUN_14027bbe0(i64, i64); i64 FUN_14027bc20(i64, i64);
i64 FUN_14027c170(i64); i64 FUN_14027c180(i64); i64 FUN_140180940(i64); i64 FUN_14027c190(i64); i64 FUN_14027c1a0(i64);
i64 FUN_14027c200(i64); i64 FUN_140180c50(i64); i64 FUN_14027c210(i64); i64 FUN_14027c1d0(i64);
i64 FUN_14027b840(i64, i64, i64); i64 FUN_14027b890(i64, i64, i64); i64 FUN_14027b930(i64, i64, i64);
i64 FUN_14027b9d0(i64, i64, i64); i64 FUN_14027bb10(i64, i64, i64); i64 FUN_14027b8e0(i64, i64, i64);
i64 FUN_14027b980(i64, i64, i64); i64 FUN_14027ba70(i64, i64, i64); i64 FUN_14027ba20(i64, i64, i64);
i64* FUN_140288ba0(i64); i64* FUN_140288b20(i64); i64* FUN_140288b60(i64); i64* FUN_140288a40(i64); i64* FUN_1402889c0(i64);
i64* FUN_140288a00(i64);
i64 FUN_1402883b0(i64); i64 FUN_140288330(i64); i64 FUN_140288370(i64);
i64 FUN_140288d20(i64, i64, i64); i64 FUN_140288d00(i64, i64, i64); i64 FUN_140288d10(i64, i64, i64);
i64 FUN_14028b500(i64); i64 FUN_14028b180(i64); i64 FUN_14028b470(i64); i64 FUN_14028b0e0(i64);
i64 FUN_14028b4c0(i64); i64 FUN_14028b130(i64);
u64 FUN_140287070(i64, i64); u64 FUN_140286f50(i64, i64); u64 FUN_140286fe0(i64, i64);
i64 FUN_14028a050(i64, u64); i64 FUN_140289ff0(i64, u64); i64 FUN_14028a020(i64, u64);
i64 FUN_140289cc0(i64, i64, i64, i64); i64 FUN_140289c00(i64, i64, i64, i64); i64 FUN_140289c60(i64, i64, i64, i64);
i64 FUN_140289b00(void* vec, i64 first, i64 last, i64 dest); i64 FUN_140289a80(i64, i64, i64, i64);
i64 FUN_140289ac0(i64, i64, i64, i64);
i64 FUN_1402873b0(i64, i64, i64, u64); i64 FUN_140287190(i64, i64, i64, u64); i64 FUN_1402872a0(i64, i64, i64, u64);
void FUN_140287670(i64, i64, i64); void FUN_14028a860(i64, i64, u64);
void FUN_1402875f0(i64, i64, i64); void FUN_14028a800(i64, i64, u64); void FUN_140287630(i64, i64, i64); void FUN_14028a830(i64, i64, u64);
i64 FUN_14027b520(i64); i64 FUN_14027b530(i64); i64 FUN_14027bb60(i64*, i64); i64 FUN_14027bb70(i64*, i64);
i64 FUN_14028a710(i64*, i64, i64); i64 FUN_14028a740(i64*, i64, i64);
i64 FUN_140289e90(i64);
i64 FUN_140288560(i64, i64);

// ---- slice-C functions called before their definition ----
i64* FUN_140274d60(i64*, i64, i64, Unk_StlTag, Unk_StlTag);
// _Compressed_pair<_Empty, pointer> whose (_One_then_variadic_args_t) ctor stores the pointer at offset 0.
struct Unk_WcPtrPair { i64 m_0; Unk_WcPtrPair* FUN_140274c50(i64); };
i64 FUN_140274cb0(i64, Unk_StlTag, i64);
int FUN_140274f40(CStringW&);
CString FUN_140274f70(CStringW&);
void FUN_140277230(i64, i64, i64);
void FUN_140277280(i64, i64, i64);
i64 FUN_140277170(i64, i64, i64, Unk_StlTag);
i64 FUN_1402771d0(i64, i64, i64, Unk_StlTag);
void FUN_1402772d0(i64, i64, i64, Unk_StlTag);
void FUN_1402772f0(i64, i64, i64, Unk_StlTag);
void FUN_140277350(i64, i64, i64, Unk_StlTag);
void FUN_1402773b0(i64, i64, i64, Unk_StlTag);
void FUN_140277410(i64, i64, i64, Unk_StlTag);
void FUN_1402768f0(i64, i64, Unk_StlTag); void FUN_140276900(i64, i64, Unk_StlTag); void FUN_140276910(i64, i64, Unk_StlTag);
i64 FUN_140277000(i64, i64, i64, i64);
i64 FUN_1402770d0(i64, i64, i64, i64);
i64 FUN_140278800(i64*, i64*, Unk_StlTag);
i64 FUN_1402787d0(i64*, i64*, Unk_StlTag); i64 FUN_140278830(i64*, i64*, Unk_StlTag);
i64 FUN_140278860(i64*, i64*, Unk_StlTag); i64 FUN_140278890(i64*, i64*, Unk_StlTag);
i64 FUN_1402749f0(i64, char);
CString FUN_14016a600(const wchar_t*, int);
