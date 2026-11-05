// Recovered serverpacketdef payload structs (names Unk_*, inferred from the (de)serialisers).
#pragma once
#include <afx.h>
#include "ms2/ms2layout.h"
#include "ms2/commonfiles/stream.h"
#include "ms2/commonfiles/constraints.h"

// Inclusive range constraint and the constrained byte read: unit_1401f9eb0's Unk_140203550<T> (ctor 0x140203550 for
// unsigned char) and Unk_Read8 (0x140202740). Declared only; unit_1401f9eb0 holds the definitions.
template<class T> struct Unk_140203550 { T minimum, maximum; Unk_140203550(T constraintMin, T constraintMax); bool Check(T value) const; };
template<class Constraint> unsigned char Unk_Read8(void* packet, Constraint constraint);
// Reader wrapper: CIOBuffer at +0, CInputStream at +8. Only the constrained read helpers used here are declared.
class Unk_SPDReader : public CIOBuffer, public CInputStream {
public:
    // the constrained byte read is the free Unk_Read8 (0x140202740); the wide read is Unk_PayloadReader::ReadWide (0x140202f40)
};
// The payload reader of unit_1401f9eb0 (same object: CIOBuffer + CInputStream at +8), which owns the constrained read templates.
struct Unk_PayloadReader : Unk_SPDReader { template<class C> CString ReadNarrowWrapper(C constraint); template<class C> CStringW ReadWide(C constraint); };

// Plain data record copied into Unk_SPDA.
struct Unk_SPD0 {
    unsigned char type; __int64 value; CStringW s1; CStringW s2;
};
MS2_CHECK_SIZE(Unk_SPD0, 0x20);

class Unk_SPDA {
public:
    Unk_SPDA();
    Unk_SPDA(const Unk_SPD0& src);
    void FUN_1407a3490(COutputStream* out);
    void FUN_1407a3640(Unk_SPDReader& in);
    __int64 m_00; unsigned char type; __int64 value; CStringW s1; CStringW s2;
};
MS2_CHECK_SIZE(Unk_SPDA, 0x28);

class Unk_SPDB {
public:
    void FUN_1407a3980(COutputStream* out);
    void FUN_1407a3cc0(Unk_SPDReader& in);
    unsigned char type; __int64 id; __int64 value; CStringW s1; CStringW s2; unsigned char kind; int flag; __int64 extra;
};
MS2_CHECK_SIZE(Unk_SPDB, 0x38);

class Unk_SPDC {
public:
    void FUN_1407a4380(COutputStream* out);
    void FUN_1407a4420(CInputStream* in);
    int a, b, c, d; unsigned char e;
};
MS2_CHECK_SIZE(Unk_SPDC, 0x14);

class Unk_SPDE {
public:
    void FUN_1407a44b0(COutputStream* out);
    void FUN_1407a4510(CInputStream* in);
    unsigned int kind; CStringW name;
};
MS2_CHECK_SIZE(Unk_SPDE, 0x10);

class Unk_SPDF {
public:
    void FUN_1407a45a0(COutputStream* out);
    void FUN_1407a4740(CInputStream* in);
    unsigned int a; int b; __int64 c; CStringW name; __int64 d; int e; unsigned int f; unsigned char g;
    __int64 h, i, j; int k, l; __int64 m;
};
MS2_CHECK_SIZE(Unk_SPDF, 0x58);

class Unk_SPDG {
public:
    void FUN_1407a4910(COutputStream* out);
    void FUN_1407a49a0(CInputStream* in);
    int a; __int64 b; __int64 c; CStringW d;
};
MS2_CHECK_SIZE(Unk_SPDG, 0x20);

class Unk_SPDH {
public:
    void FUN_1407a4a60(COutputStream* out);
    void FUN_1407a4ac0(CInputStream* in);
    __int64 a; CStringW b;
};
MS2_CHECK_SIZE(Unk_SPDH, 0x10);

struct Unk_NetworkTransfer {   // the server's transfer / popup answer (networkservice, uicharacterlistdialog); ctor/dtor MS2-PIN in networkservice.cpp
    Unk_NetworkTransfer():result(0x25),character(0),ip(0),port(0),token1(0),token2(0),field(0) {}   // 0x141540eb0
    void FUN_1407a4b50(COutputStream* out);
    void FUN_1407a4c60(CInputStream* in);
    unsigned char result; __int64 character; unsigned ip; unsigned short port; int token1, token2, field; CStringW message;
};
MS2_CHECK_SIZE(Unk_NetworkTransfer, 0x30);

class Unk_SPDJ {
public:
    void FUN_1407a4d90(COutputStream* out);
    void FUN_1407a4dc0(Unk_SPDReader& in);
    int a;
};

class Unk_SPDK {
public:
    void FUN_1407a4e10(COutputStream* out);
    void FUN_1407a4e80(Unk_SPDReader& in);
    __int64 a; unsigned int b; int c;
};
MS2_CHECK_SIZE(Unk_SPDK, 0x10);
