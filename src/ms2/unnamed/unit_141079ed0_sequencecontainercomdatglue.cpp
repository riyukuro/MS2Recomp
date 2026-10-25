// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Unnamed unit unit_141079ed0: the out-of-line glue of a
// family of small sequence containers. Four shapes repeat:
//   * 16 forwards that hand a raw node pointer and an uninitialised one-byte scratch to a per-type helper and pass
//     the helper's result straight back (0x141074140..0x141074320);
//   * 7 forwards that re-read a node through a per-type accessor and push it through one of the 16 (0x141072db0..);
//   * 10 "clamp to the global limit" wrappers: min(FUN_140190260(), <accessor>(<node getter>(p)));
//   * 10 "number of elements" wrappers returning the distance between two node-pointer getters divided by the
//     element size (1, 8, 16 or 24 bytes; 24 goes through a real idiv), plus the 0x0fffffffffffffff sentinel and a
//     handful of downcasts/upcasts that forward to 0x141062xxx / 0x141063xxx.
// The exe reads the one-byte scratch before anything writes it, so the source declares it uninitialised (C4700).
// All names invented from shape; the callee prototypes live in the neighbouring unit.
// MS2-UNIT: unit_141079ed0
// MS2-RANGE: 0x141079ed0-0x14107ac30 .text$mn
#define MS2_THIS_FILE ""

#include "ms2/placeholder/ms2stdafx.h"

#include "ms2/ms2recover.h"

#include <utility>                               // std::_Min_value

typedef __int64 i64;
typedef unsigned __int64 u64;

// ---- unit-local views of the node shapes the accessors read ----
struct Unk_Node0 { i64 m_nValue; };              // the field at +0
struct Unk_Node8 { i64 m_pad_00; i64 m_nValue; };// the field at +8

// ---- the container helpers this unit forwards to (defined outside it) ----
u64 FUN_141074140(void*, bool);                  // per-list insert; the flag is the uninitialised scratch
u64 FUN_141074160(void*, bool);
u64 FUN_141074180(void*, bool);
u64 FUN_1410741a0(void*, bool);
u64 FUN_1410741c0(void*, bool);
u64 FUN_1410741e0(void*, bool);
u64 FUN_141074200(void*, bool);
u64 FUN_141074220(void*, bool);
u64 FUN_141074240(void*, bool);
u64 FUN_141074260(void*, bool);
u64 FUN_141074280(void*, bool);
u64 FUN_1410742a0(void*, bool);
u64 FUN_1410742c0(void*, bool);
u64 FUN_1410742e0(void*, bool);
u64 FUN_141074300(void*, bool);
u64 FUN_141074320(void*, bool);

void* FUN_141072db0(void*);                      // per-type node accessors (forward 1)
void* FUN_141072e10(void*);
void* FUN_141072e70(void*);
void* FUN_141072ed0(void*);
void* FUN_141072f30(void*);
void* FUN_141072f90(void*);
void* FUN_141072ff0(void*);

void* FUN_141073040(void*);                      // per-type node accessors (forward 2)
void* FUN_141073080(void*);
void* FUN_1410730c0(void*);
void* FUN_141073100(void*);
void* FUN_141073140(void*);
void* FUN_141073180(void*);
void* FUN_1410731c0(void*);
void* FUN_141073200(void*);
void* FUN_141073240(void*);
void* FUN_141073280(void*);

Unk_Node8* FUN_1410722e0(void*);                 // per-type node accessors reading +8
Unk_Node8* FUN_141072340(void*);
Unk_Node8* FUN_1410723a0(void*);
Unk_Node8* FUN_141072490(void*);
Unk_Node8* FUN_1410724f0(void*);

void FUN_141062850(void*);                       // the upcasts / downcasts
void FUN_141062870(void*);
void FUN_141062880(void*);
void FUN_141062890(void*);
void FUN_141062780(void*);
void FUN_141063bb0(void*, void*);
void FUN_141063c20(void*, void*);
void FUN_141063c90(void*, void*);
void FUN_141063d00(void*, void*);
void FUN_141063d70(void*, void*);
void FUN_141063de0(void*, void*);
void FUN_141063e50(void*, void*);
void FUN_141063ec0(void*, void*);
void FUN_141063f30(void*, void*);
void FUN_141063fa0(void*, void*);
void* FUN_141064a80(void*);
void* FUN_141064a90(void*);
void* FUN_141064aa0(void*);
void* FUN_141064ab0(void*);
void* FUN_141064ae0(void*);
void* FUN_141064af0(void*);

void FUN_141075730(void*, void*, bool);          // the flag-setting helpers
void FUN_141075770(void*, void*, bool);
void FUN_1410757b0(void*, void*, bool);
void FUN_1410757f0(void*, void*, bool);
void FUN_141075830(void*, void*, bool);
void FUN_141075870(void*, void*, bool);

Unk_Node0* FUN_1410749b0(void*);                 // the two node-pointer getters of a distance pair
Unk_Node0* FUN_141074730(void*);
Unk_Node0* FUN_1410749f0(void*);
Unk_Node0* FUN_141074770(void*);
Unk_Node0* FUN_141074a30(void*);
Unk_Node0* FUN_1410747b0(void*);
Unk_Node0* FUN_141074a70(void*);
Unk_Node0* FUN_1410747f0(void*);
Unk_Node0* FUN_141074ab0(void*);
Unk_Node0* FUN_141074830(void*);
Unk_Node0* FUN_141074af0(void*);
Unk_Node0* FUN_141074870(void*);
Unk_Node0* FUN_141074b30(void*);
Unk_Node0* FUN_1410748b0(void*);
Unk_Node0* FUN_141074b70(void*);
Unk_Node0* FUN_1410748f0(void*);
Unk_Node0* FUN_141074bb0(void*);
Unk_Node0* FUN_141074930(void*);
Unk_Node0* FUN_141074bf0(void*);
Unk_Node0* FUN_141074970(void*);

u64 FUN_140190260(void);                         // the global element limit

// ---------------------------------------------------------------------------
// the sentinel and the 16 flag-passing forwards
// ---------------------------------------------------------------------------

// @0x141079ed0
u64 FUN_141079ed0(void* p)
{
    return 0x0fffffffffffffff;
}

// @0x141079ee0
u64 FUN_141079ee0(void* p)
{
    bool bFlag;
    return FUN_141074140(p, bFlag);
}

// @0x141079f00
u64 FUN_141079f00(void* p)
{
    bool bFlag;
    return FUN_141074160(p, bFlag);
}

// @0x141079f20
u64 FUN_141079f20(void* p)
{
    bool bFlag;
    return FUN_141074180(p, bFlag);
}

// @0x141079f40
u64 FUN_141079f40(void* p)
{
    bool bFlag;
    return FUN_1410741a0(p, bFlag);
}

// @0x141079f60
u64 FUN_141079f60(void* p)
{
    bool bFlag;
    return FUN_1410741c0(p, bFlag);
}

// @0x141079f80
u64 FUN_141079f80(void* p)
{
    bool bFlag;
    return FUN_1410741e0(p, bFlag);
}

// @0x141079fa0
u64 FUN_141079fa0(void* p)
{
    bool bFlag;
    return FUN_141074200(p, bFlag);
}

// @0x141079fc0
u64 FUN_141079fc0(void* p)
{
    bool bFlag;
    return FUN_141074220(p, bFlag);
}

// @0x141079fe0
u64 FUN_141079fe0(void* p)
{
    bool bFlag;
    return FUN_141074240(p, bFlag);
}

// @0x14107a000
u64 FUN_14107a000(void* p)
{
    bool bFlag;
    return FUN_141074260(p, bFlag);
}

// @0x14107a020
u64 FUN_14107a020(void* p)
{
    bool bFlag;
    return FUN_141074280(p, bFlag);
}

// @0x14107a040
u64 FUN_14107a040(void* p)
{
    bool bFlag;
    return FUN_1410742a0(p, bFlag);
}

// @0x14107a060
u64 FUN_14107a060(void* p)
{
    bool bFlag;
    return FUN_1410742c0(p, bFlag);
}

// @0x14107a080
u64 FUN_14107a080(void* p)
{
    bool bFlag;
    return FUN_1410742e0(p, bFlag);
}

// @0x14107a0a0
u64 FUN_14107a0a0(void* p)
{
    bool bFlag;
    return FUN_141074300(p, bFlag);
}

// @0x14107a0c0
u64 FUN_14107a0c0(void* p)
{
    bool bFlag;
    return FUN_141074320(p, bFlag);
}

// ---------------------------------------------------------------------------
// forwards through a per-type node accessor
// ---------------------------------------------------------------------------

// @0x14107a0e0
u64 FUN_14107a0e0(void* p)
{
    return FUN_141079f80(FUN_141072db0(p));
}

// @0x14107a100
u64 FUN_14107a100(void* p)
{
    return FUN_141079fe0(FUN_141072e10(p));
}

// @0x14107a120
u64 FUN_14107a120(void* p)
{
    return FUN_14107a000(FUN_141072e70(p));
}

// @0x14107a140
u64 FUN_14107a140(void* p)
{
    return FUN_141079fa0(FUN_141072ed0(p));
}

// @0x14107a160
u64 FUN_14107a160(void* p)
{
    return FUN_141079fc0(FUN_141072f30(p));
}

// @0x14107a180
u64 FUN_14107a180(void* p)
{
    return FUN_141079f40(FUN_141072f90(p));
}

// @0x14107a1a0
u64 FUN_14107a1a0(void* p)
{
    return FUN_141079f60(FUN_141072ff0(p));
}

// ---------------------------------------------------------------------------
// clamped element counts: min(the global limit, the list's own count)
// (`std::_Min_value` is the STL helper the exe calls out of line here)
// ---------------------------------------------------------------------------

// @0x14107a1c0
u64 FUN_14107a1c0(void* p)
{
    u64 nValue = FUN_141079ee0(FUN_141073040(p));
    u64 nLimit = FUN_140190260();
    return std::_Min_value(nLimit, nValue);
}

// @0x14107a210
u64 FUN_14107a210(void* p)
{
    u64 nValue = FUN_141079f00(FUN_141073080(p));
    u64 nLimit = FUN_140190260();
    return std::_Min_value(nLimit, nValue);
}

// @0x14107a260
u64 FUN_14107a260(void* p)
{
    u64 nValue = FUN_141079f20(FUN_1410730c0(p));
    u64 nLimit = FUN_140190260();
    return std::_Min_value(nLimit, nValue);
}

// @0x14107a2b0
u64 FUN_14107a2b0(void* p)
{
    u64 nValue = FUN_141079ed0(FUN_141073100(p));
    u64 nLimit = FUN_140190260();
    return std::_Min_value(nLimit, nValue);
}

// @0x14107a300
u64 FUN_14107a300(void* p)
{
    u64 nValue = FUN_14107a020(FUN_141073140(p));
    u64 nLimit = FUN_140190260();
    return std::_Min_value(nLimit, nValue);
}

// @0x14107a350
u64 FUN_14107a350(void* p)
{
    u64 nValue = FUN_14107a040(FUN_141073180(p));
    u64 nLimit = FUN_140190260();
    return std::_Min_value(nLimit, nValue);
}

// @0x14107a3a0
u64 FUN_14107a3a0(void* p)
{
    u64 nValue = FUN_14107a060(FUN_1410731c0(p));
    u64 nLimit = FUN_140190260();
    return std::_Min_value(nLimit, nValue);
}

// @0x14107a3f0
u64 FUN_14107a3f0(void* p)
{
    u64 nValue = FUN_14107a080(FUN_141073200(p));
    u64 nLimit = FUN_140190260();
    return std::_Min_value(nLimit, nValue);
}

// @0x14107a440
u64 FUN_14107a440(void* p)
{
    u64 nValue = FUN_14107a0a0(FUN_141073240(p));
    u64 nLimit = FUN_140190260();
    return std::_Min_value(nLimit, nValue);
}

// @0x14107a490
u64 FUN_14107a490(void* p)
{
    u64 nValue = FUN_14107a0c0(FUN_141073280(p));
    u64 nLimit = FUN_140190260();
    return std::_Min_value(nLimit, nValue);
}

// ---------------------------------------------------------------------------
// the element-count shims
// ---------------------------------------------------------------------------

// @0x14107a4e0
void FUN_14107a4e0(void* p)
{
    FUN_141062850(p);
}

// @0x14107a500
void FUN_14107a500(void* p)
{
    FUN_141062870(p);
}

// @0x14107a520
void FUN_14107a520(void* p)
{
    FUN_141062880(p);
}

// @0x14107a540
void FUN_14107a540(void* p)
{
    FUN_141062890(p);
}

// @0x14107a560
void FUN_14107a560(void* p)
{
    FUN_141062780(p);
}

// @0x14107a580
void FUN_14107a580(void* p1, void* p2)
{
    FUN_141063bb0(p1, p2);
}

// @0x14107a5b0
void FUN_14107a5b0(void* p1, void* p2)
{
    FUN_141063c20(p1, p2);
}

// @0x14107a5e0
void FUN_14107a5e0(void* p1, void* p2)
{
    FUN_141063d70(p1, FUN_141064a80(p2));
}

// @0x14107a610
void FUN_14107a610(void* p1, void* p2)
{
    FUN_141063de0(p1, FUN_141064a90(p2));
}

// @0x14107a640
void FUN_14107a640(void* p1, void* p2)
{
    FUN_141063e50(p1, FUN_141064aa0(p2));
}

// @0x14107a670
void FUN_14107a670(void* p1, void* p2)
{
    FUN_141063ec0(p1, FUN_141064ab0(p2));
}

// @0x14107a6a0
void FUN_14107a6a0(void* p1, void* p2)
{
    FUN_141063f30(p1, FUN_141064ae0(p2));
}

// @0x14107a6d0
void FUN_14107a6d0(void* p1, void* p2)
{
    FUN_141063fa0(p1, FUN_141064af0(p2));
}

// @0x14107a700
void FUN_14107a700(void* p1, void* p2)
{
    FUN_141063c90(p1, p2);
}

// @0x14107a730
void FUN_14107a730(void* p1, void* p2)
{
    FUN_141063d00(p1, p2);
}

// @0x14107a760
void* FUN_14107a760(void* p1, void* p2)
{
    bool bFlag;
    int nState = 0;
    FUN_141075730(p1, p2, bFlag);
    nState |= 1;
    return p1;
}

// @0x14107a7a0
void* FUN_14107a7a0(void* p1, void* p2)
{
    bool bFlag;
    int nState = 0;
    FUN_141075770(p1, p2, bFlag);
    nState |= 1;
    return p1;
}

// @0x14107a7e0
void* FUN_14107a7e0(void* p1, void* p2)
{
    bool bFlag;
    int nState = 0;
    FUN_1410757b0(p1, p2, bFlag);
    nState |= 1;
    return p1;
}

// @0x14107a820
void* FUN_14107a820(void* p1, void* p2)
{
    bool bFlag;
    int nState = 0;
    FUN_1410757f0(p1, p2, bFlag);
    nState |= 1;
    return p1;
}

// @0x14107a860
void* FUN_14107a860(void* p1, void* p2)
{
    bool bFlag;
    int nState = 0;
    FUN_141075830(p1, p2, bFlag);
    nState |= 1;
    return p1;
}

// @0x14107a8a0
void* FUN_14107a8a0(void* p1, void* p2)
{
    bool bFlag;
    int nState = 0;
    FUN_141075870(p1, p2, bFlag);
    nState |= 1;
    return p1;
}

// ---------------------------------------------------------------------------
// the field-at-+8 readers
// ---------------------------------------------------------------------------

// @0x14107a8e0
i64 FUN_14107a8e0(void* p)
{
    return FUN_1410722e0(p)->m_nValue;
}

// @0x14107a900
i64 FUN_14107a900(void* p)
{
    return FUN_141072340(p)->m_nValue;
}

// @0x14107a920
i64 FUN_14107a920(void* p)
{
    return FUN_1410723a0(p)->m_nValue;
}

// @0x14107a940
i64 FUN_14107a940(void* p)
{
    return FUN_141072490(p)->m_nValue;
}

// @0x14107a960
i64 FUN_14107a960(void* p)
{
    return FUN_1410724f0(p)->m_nValue;
}

// ---------------------------------------------------------------------------
// the element distances: the two node pointers differ by whole elements, so the
// quotient is a real division (shifts for 8/16, an idiv for the 24-byte element)
// ---------------------------------------------------------------------------

// @0x14107a980
i64 FUN_14107a980(void* p)
{
    return FUN_1410749b0(p)->m_nValue - FUN_141074730(p)->m_nValue;
}

// @0x14107a9c0
i64 FUN_14107a9c0(void* p)
{
    return (FUN_1410749f0(p)->m_nValue - FUN_141074770(p)->m_nValue) >> 3;
}

// @0x14107aa00
i64 FUN_14107aa00(void* p)
{
    return (FUN_141074a30(p)->m_nValue - FUN_1410747b0(p)->m_nValue) >> 3;
}

// @0x14107aa40
i64 FUN_14107aa40(void* p)
{
    return (FUN_141074a70(p)->m_nValue - FUN_1410747f0(p)->m_nValue) >> 4;
}

// @0x14107aa80
i64 FUN_14107aa80(void* p)
{
    return (FUN_141074ab0(p)->m_nValue - FUN_141074830(p)->m_nValue) >> 4;
}

// @0x14107aac0
i64 FUN_14107aac0(void* p)
{
    return (FUN_141074af0(p)->m_nValue - FUN_141074870(p)->m_nValue) >> 4;
}

// @0x14107ab00
i64 FUN_14107ab00(void* p)
{
    return (FUN_141074b30(p)->m_nValue - FUN_1410748b0(p)->m_nValue) >> 4;
}

// @0x14107ab40
i64 FUN_14107ab40(void* p)
{
    return (FUN_141074b70(p)->m_nValue - FUN_1410748f0(p)->m_nValue) / 0x18;
}

// @0x14107ab90
i64 FUN_14107ab90(void* p)
{
    return (FUN_141074bb0(p)->m_nValue - FUN_141074930(p)->m_nValue) / 0x18;
}

// @0x14107abe0
i64 FUN_14107abe0(void* p)
{
    return (FUN_141074bf0(p)->m_nValue - FUN_141074970(p)->m_nValue) / 0x18;
}
