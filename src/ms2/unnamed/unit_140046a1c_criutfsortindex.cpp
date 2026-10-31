// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CRI Middleware UTF table reader (statically linked vendor code),
// part 2: the sort-index table (create / free) with its qsort value comparator, and the stored-column size sum.
// Names are invented from use.
// MS2-UNIT: unit_140046a1c
// MS2-RANGE: 0x140046a1c-0x140046e04 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include <stdlib.h>
#include <string.h>
#include "ms2/ms2recover.h"
#include "ms2/ms2layout.h"
#include "hook/ms2hook.h"

#pragma optimize("gsy", on)                                       // statically linked CRI library: built with /O2, not /Od

// ---- unit-local views (the full layouts live in unit_140046e04) ----------------------------------------------------------
struct Unk_CriUtfColumn                                         // 0x30 bytes
{
    unsigned type;                                              // +0x00 (low nibble = value type)
    unsigned pad_04[3];
    unsigned char kind;                                         // +0x10
    unsigned char flag;                                         // +0x11 (nonzero: column stores a per-row value)
    unsigned short rowOffset;                                   // +0x12
    unsigned pad_14[7];
};
MS2_CHECK_SIZE(Unk_CriUtfColumn, 0x30);

struct Unk_CriUtfValue                                          // a decoded cell
{
    unsigned char type;                                         // +0x00
    union
    {
        unsigned char u8;
        char s8;
        unsigned short u16;
        short s16;
        unsigned u32;
        int s32;
        long long s64;
        float f32;
        double f64;
    } v;                                                        // +0x08
    unsigned long long v2;                                      // +0x10
};

struct Unk_CriUtfIdxSlot
{
    unsigned key;                                               // column the index is sorted by, or -1
    unsigned pad;
    unsigned* value;                                            // row permutation (heap block)
};

struct Unk_CriUtfSortTable
{
    void* m_heap;                                               // +0x00 (0: not set up)
    unsigned char pad_08[0x18];
    int m_nRows;                                                // +0x20
    unsigned char pad_24[0x3c];
    Unk_CriUtfColumn* m_columns;                                // +0x60
    Unk_CriUtfIdxSlot m_slots[4];                               // +0x68
};

extern Unk_CriUtfSortTable* DAT_143ba9d40;                      // table / column being sorted (qsort has no context argument)
extern unsigned DAT_143ba9d48;

int FUN_140038ddc(int level, const char* msg);
int FUN_140038e24(int level, const char* code, int err);
long criUtfRtv_GetCellVal(struct CriUtfRtvView const*, unsigned long, unsigned long, struct CriUtfRtvCell*);   // C3: was FUN_14003af50
char const* criUtfRtv_GetDataStr(struct CriUtfRtvView const*, unsigned long, unsigned long);   // C3: was FUN_14003a7f4
unsigned long FUN_14003a45c(struct CriUtfRtvView const*);   // C3: was FUN_14003a45c
void* criUtfHeap_Alloc(void*, unsigned long, char const*, long, long);   // C3: was FUN_14003a0d0
void FUN_14003a0ec(void* heap, void* p);
unsigned FUN_140047158(unsigned type);

// @0x140046a1c
// qsort comparator over two row numbers: orders by the sort column's value, descending for numbers, ascending for text.
// MS2-FUNCTIONAL: branch layout and flag reuse differ from the exe's signed-compare chains
int FUN_140046a1c(const unsigned* pA, const unsigned* pB)
{
    unsigned rowA = *pA;
    unsigned rowB = *pB;
    Unk_CriUtfValue a, b;
    criUtfRtv_GetCellVal((struct CriUtfRtvView const*)(DAT_143ba9d40), rowA, DAT_143ba9d48, (struct CriUtfRtvCell*)(&a));
    criUtfRtv_GetCellVal((struct CriUtfRtvView const*)(DAT_143ba9d40), rowB, DAT_143ba9d48, (struct CriUtfRtvCell*)(&b));
    switch (a.type)
    {
    case 0:
        return a.v.u8 < b.v.u8 ? 1 : (b.v.u8 < a.v.u8 ? -1 : 0);
    case 1:
        return a.v.s8 < b.v.s8 ? 1 : (a.v.s8 == b.v.s8 ? 0 : -1);
    case 2:
        return a.v.u16 < b.v.u16 ? 1 : (b.v.u16 < a.v.u16 ? -1 : 0);
    case 3:
        return a.v.s16 < b.v.s16 ? 1 : (a.v.s16 == b.v.s16 ? 0 : -1);
    case 4:
        return a.v.u32 < b.v.u32 ? 1 : (b.v.u32 < a.v.u32 ? -1 : 0);
    case 5:
        return a.v.s32 < b.v.s32 ? 1 : (a.v.s32 == b.v.s32 ? 0 : -1);
    case 6:
    case 7:
        return a.v.s64 < b.v.s64 ? 1 : (a.v.s64 == b.v.s64 ? 0 : -1);
    case 8:
        if (b.v.f32 > a.v.f32)
            return 1;
        return a.v.f32 > b.v.f32 ? -1 : 0;                         // unordered (NaN) compares equal
    case 9:
        if (b.v.f64 > a.v.f64)
            return 1;
        return a.v.f64 > b.v.f64 ? -1 : 0;                         // unordered (NaN) compares equal
    case 10:
    {
        const char* strA = criUtfRtv_GetDataStr((struct CriUtfRtvView const*)(DAT_143ba9d40), rowA, DAT_143ba9d48);
        const char* strB = criUtfRtv_GetDataStr((struct CriUtfRtvView const*)(DAT_143ba9d40), rowB, DAT_143ba9d48);
        return strcmp(strA, strB);
    }
    default:
        return 0;
    }
}

// @0x140046c0c
// MS2-FUNCTIONAL: same checks, allocation and sort as the exe; /Ox register allocation differs (r12/r14/r15 roles)
unsigned long long FUN_140046c0c(Unk_CriUtfSortTable* table, unsigned slot, unsigned column)
{
    if (table->m_heap == 0)
    {
        FUN_140038ddc(0, "E08070301:No Heap");
        return 0;
    }
    if (slot >= 4)
    {
        FUN_140038ddc(0, "E08012801:Invalid table no");
        return 0;
    }
    if (table->m_slots[slot].key != (unsigned)-1)
    {
        FUN_140038ddc(0, "E08012802:Not Empty Index Table");
        return 0;
    }
    if (table->m_slots[slot].value != 0)
    {
        FUN_140038ddc(0, "E08012803:Internal Error");
        return 0;
    }
    unsigned n = FUN_14003a45c((struct CriUtfRtvView const*)(table));
    table->m_slots[slot].value = (unsigned*)criUtfHeap_Alloc(table->m_heap, n << 2, "UtfRtvIdxTbl", 4, table->m_nRows);
    if (table->m_slots[slot].value == 0)
    {
        FUN_140038e24(0, "E06100300", -3);
        return 0;
    }
    memset(table->m_slots[slot].value, 0, (long long)(int)(n << 2));
    table->m_slots[slot].key = column;
    for (unsigned i = 0; i < n; i++)
        table->m_slots[slot].value[i] = i;
    DAT_143ba9d40 = table;
    DAT_143ba9d48 = column;
    qsort(table->m_slots[slot].value, n, 4, (int (*)(const void*, const void*))FUN_140046a1c);
    return 1;
}

// @0x140046d50
void FUN_140046d50(Unk_CriUtfSortTable* table, unsigned slot)
{
    const char* err;
    if (slot < 4)
    {
        if (table->m_slots[slot].value != 0)
        {
            if (table->m_heap != 0)
                FUN_14003a0ec(table->m_heap, table->m_slots[slot].value);
            table->m_slots[slot].key = (unsigned)-1;
            table->m_slots[slot].value = 0;
            return;
        }
        err = "E08012805:Internal Error";
    }
    else
        err = "E08012804:Invalid table no";
    FUN_140038ddc(0, err);
}

// @0x140046dbc
// sum of the stored sizes of the first nColumns columns that keep a per-row value
int FUN_140046dbc(Unk_CriUtfSortTable* table, unsigned nColumns)
{
    const Unk_CriUtfColumn* col = table->m_columns;
    int sum = 0;
    for (unsigned i = 0; i < nColumns; i++, col++)
    {
        if (col->flag != 0)
            sum += FUN_140047158(col->type);
    }
    return sum;
}
