// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Game-entity and currency conversions.
// MS2-UNIT: commonfiles\gameentitycommon.cpp
// MS2-RANGE: 0x1403ba180-0x1403bb510 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\gameentitycommon.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "gameentitycommon.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
// The copy is this unit's COMDAT (0x1403bb3b0).
template<> inline MS2Ptr<CItemData>::MS2Ptr(const MS2Ptr& o) { m_p = o.m_p; AddRef(); }
MS2Ptr<CItemData> FUN_14053f870(int);

// @0x1403ba180
int FUN_1403ba180(int value) {
    switch (value) {
    case 1:
        return 0;
    case 3:
        return 2;
    case 4:
        return 3;
    case 5:
        return 4;
    case 6:
        return 5;
    case 7:
        return 6;
    case 8:
        return 7;
    case 9:
        return 8;
    case 12:
        return 9;
    case 13:
        return 10;
    case 14:
        return 11;
    case 15:
        return 12;
    case 10:
        return 2;
    case 16:
        return 13;
    default: return 14;
    }
}
MS2_REPLACE(0x1403BA180, FUN_1403ba180, 157, 0x30D841B3);

// @0x1403ba270
int FUN_1403ba270(int value) {
    int kind = FUN_1403baee0(value);
    return FUN_1403ba180(kind);
}
MS2_REPLACE(0x1403BA270, FUN_1403ba270, 35, 0x6A061A7F);

// @0x1403ba2a0
int FUN_1403ba2a0(const CStringW& name) {
    if (name.CompareNoCase(L"Honor") == 0) return 3;
    else if (name.CompareNoCase(L"Karma") == 0) return 4;
    else if (name.CompareNoCase(L"lu") == 0) return 5;
    else if (name.CompareNoCase(L"habi") == 0) return 6;
    else if (name.CompareNoCase(L"reverseCoin") == 0) return 9;
    else if (name.CompareNoCase(L"starPoint") == 0) return 12;
    else if (name.CompareNoCase(L"mentor") == 0) return 10;
    else if (name.CompareNoCase(L"mentee") == 0) return 11;
    else if (name.CompareNoCase(L"meso") == 0) return 0;
    else if (name.CompareNoCase(L"merat") == 0) return 2;
    else if (name.CompareNoCase(L"meratred") == 0) return 8;
    else if (name.CompareNoCase(L"mesoMarketToken") == 0) return 13;
    return 14;
}
MS2_REPLACE(0x1403BA2A0, FUN_1403ba2a0, 385, 0xBEA91F92);

// @0x1403ba480
bool FUN_1403ba480(int value) {
    int currency = 14;
    int color = 99;
    return FUN_1403ba590(value, currency, color);
}
MS2_REPLACE(0x1403BA480, FUN_1403ba480, 48, 0xEEB2064C);

// @0x1403ba4c0
bool FUN_1403ba4c0(const int& value) {
    int kind = FUN_1403ba790(value);
    return FUN_1403ba480(kind);
}
MS2_REPLACE(0x1403BA4C0, FUN_1403ba4c0, 39, 0x7B6E4561);

// @0x1403ba4f0
int FUN_1403ba4f0(int value) {
    int kind = FUN_1403ba790(value);
    int currency = 14;
    int color = 99;
    FUN_1403ba590(kind, currency, color);
    return currency;
}
MS2_REPLACE(0x1403BA4F0, FUN_1403ba4f0, 65, 0xF6C19741);

// @0x1403ba540
bool FUN_1403ba540(int value, int& currency) {
    currency = FUN_1403ba180(value);
    return currency != 14;
}
MS2_REPLACE(0x1403BA540, FUN_1403ba540, 67, 0x96D3D661);

// @0x1403ba590
bool FUN_1403ba590(int value, int& currency, int& color) {
    currency = 14;
    color = 99;
    switch (value) {
    case 6: currency = 0; return true;
    case 10: currency = 2; color = 0; return true;
    case 11: currency = 2; color = 1; return true;
    case 12: currency = 2; color = 2; return true;
    case 13: currency = 2; color = 3; return true;
    case 14: currency = 3; return true;
    case 15: currency = 4; return true;
    case 16: currency = 5; return true;
    case 17: currency = 6; return true;
    case 18: currency = 7; return true;
    case 19: currency = 8; color = 0; return true;
    case 20: currency = 9; return true;
    case 21: currency = 10; return true;
    case 22: currency = 11; return true;
    case 23: currency = 12; return true;
    case 24: currency = 13; return true;
    default: return false;
    }
}
MS2_REPLACE(0x1403BA590, FUN_1403ba590, 415, 0x525A0179);

// @0x1403ba790
int FUN_1403ba790(unsigned int value) {
    switch (value) {
    case 90000001: case 90000002: case 90000003: return 6;
    case 90000011: return 10;
    case 90000004: return 11;
    case 90000015: return 12;
    case 90000016: return 13;
    case 90000006: return 14;
    case 90000017: return 15;
    case 90000013: return 16;
    case 90000014: return 17;
    case 90000018: return 18;
    case 90000020: return 19;
    case 90000022: return 20;
    case 90000023: return 21;
    case 90000024: return 22;
    case 90000025: return 23;
    case 90000027: return 24;
    default: return 0;
    }
}
MS2_REPLACE(0x1403BA790, FUN_1403ba790, 177, 0x87532FF8);

// @0x1403ba8c0
int FUN_1403ba8c0(int id) {
    MS2Ptr<CItemData> item = FUN_14053f870(id);
    if (item == NULL) return 0;
    return FUN_1403ba950(item);
}
MS2_REPLACE(0x1403BA8C0, FUN_1403ba8c0, 138, 0xA458837E);

// @0x1403ba950
int FUN_1403ba950(MS2Ptr<CItemData> item) {
    if (item == NULL) return 0;
    int id = item->GetItemId();
    if (id == 0) return 0;
    int type = item->GetType();
    if (type == 4) {
        int kind = FUN_1403ba790(id);
        if (kind != 0) return kind;
    }
    switch (type) {
    case 1:
        if (item->FUN_14053ce80()) return 8;
        else if (item->HasSkinType()) return 25;
        return 1;
    case 2:
        return 2;
    case 3:
        return 3;
    case 5:
        return 5;
    case 6:
        return 28;
    case 9:
        return 9;
    case 8:
    case 12:
    case 23:
        return 7;
    case 13:
    case 14:
        return 26;
    case 15:
    case 19:
        return 27;
    case 16:
        return 29;
    case 11:
        return 30;
    case 21:
        return 33;
    case 20:
        return 31;
    case 7:
        return 32;
    case 27:
        return 34;
    }
    return 4;
}
MS2_REPLACE(0x1403BA950, FUN_1403ba950, 866, 0x66FD1FFD);

// @0x1403bad30
int FUN_1403bad30(int value) {
    switch (value) {
    case 2: return 3;
    case 0: case 1: case 3: case 4: case 5: case 6: case 7:
    case 8: case 9: case 10: case 11: case 12: case 13: return 0;
    default: MS2_ASSERT_AT(348, FALSE); return 0;
    }
}
MS2_REPLACE(0x1403BAD30, FUN_1403bad30, 105, 0x0614FD8A);

// @0x1403badc0
bool FUN_1403badc0(int value) {
    return value >= 0 && value < 4;
}
MS2_REPLACE(0x1403BADC0, FUN_1403badc0, 47, 0x5F160D43);

// @0x1403bae00
int FUN_1403bae00(int value) {
    switch (value) {
    case 0:
        return 1;
    case 2:
        return 3;
    case 3:
        return 4;
    case 4:
        return 5;
    case 5:
        return 6;
    case 6:
        return 7;
    case 7:
        return 8;
    case 8:
        return 9;
    case 9:
        return 12;
    case 10:
        return 13;
    case 11:
        return 14;
    case 12:
        return 15;
    case 13:
        return 16;
    default: return 17;
    }
}
MS2_REPLACE(0x1403BAE00, FUN_1403bae00, 145, 0x252D44B5);

// @0x1403baee0
int FUN_1403baee0(int value) {
    switch (value) {
    case 1:
        return 2;
    case 4:
        return 3;
    case 0:
        return 1;
    case 5:
        return 6;
    case 6:
        return 7;
    case 2:
        return 4;
    case 3:
        return 5;
    case 7:
        return 11;
    case 8:
        return 12;
    case 11:
        return 13;
    case 12:
        return 14;
    case 13:
        return 15;
    case 9:
        return 10;
    case 10:
        return 9;
    case 14:
        return 16;
    default: return 17;
    }
}
MS2_REPLACE(0x1403BAEE0, FUN_1403baee0, 163, 0x06096CF7);

// @0x1403bafd0
int FUN_1403bafd0(int id) {
    int currency = FUN_1403ba4f0(id);
    if (currency != 14) return FUN_1403bae00(currency);
    return 17;
}
MS2_REPLACE(0x1403BAFD0, FUN_1403bafd0, 49, 0x4B89AB50);

// @0x1403bb010
int FUN_1403bb010(int value, int color) {
    switch (value) {
    case 0: return 90000001;
    case 2:
        switch (color) {
        case 0: return 90000011;
        case 3: return 90000016;
        case 2: return 90000015;
        default: return 90000004;
        }
    case 3: return 90000006;
    case 4: return 90000017;
    case 5: return 90000013;
    case 6: return 90000014;
    case 7: return 90000018;
    case 8: return 90000020;
    case 9: return 90000022;
    case 10: return 90000023;
    case 11: return 90000024;
    case 12: return 90000025;
    case 13: return 90000027;
    default: return 0;
    }
}
MS2_REPLACE(0x1403BB010, FUN_1403bb010, 204, 0xA58C2F85);

// @0x1403bb120
int FUN_1403bb120(int value) {
    switch (value) {
    case 0:
        return 0;
    case 2:
        return 4;
    case 3:
        return 2;
    case 4:
        return 3;
    case 5:
        return 5;
    case 6:
        return 6;
    case 9:
        return 8;
    case 10:
        return 11;
    case 11:
        return 12;
    case 12:
        return 13;
    case 8:
        return 10;
    case 13:
        return 14;
    default: MS2_ASSERT_AT(485, FALSE); return 15;
    }
}
MS2_REPLACE(0x1403BB120, FUN_1403bb120, 172, 0xCBE933F8);

// @0x1403bb210
int FUN_1403bb210(int color, bool all) {
    if (color == 4 || color == 99 || all) return -1;
    switch (color) {
    case 0: return 1;
    case 1: return 2;
    case 2: return 4;
    case 3: return 8;
    default: MS2_ASSERT_AT(554, FALSE); return 0;
    }
}
MS2_REPLACE(0x1403BB210, FUN_1403bb210, 149, 0xC8A7FEBC);

// @0x1403bb2b0
int FUN_1403bb2b0(int color) {
    int mask = 0;
    do {
        mask |= 1;
        if (color == 0) break;
        mask |= 2;
        if (color == 1) break;
        mask |= 4;
        if (color == 2) break;
        mask |= 8;
        if (color == 3) break;
    } while (false);
    return mask;
}
MS2_REPLACE(0x1403BB2B0, FUN_1403bb2b0, 101, 0x12DDD303);

// @0x1403bb320
int FUN_1403bb320(int currency, unsigned int mask) {
    int color = 0;
    if (mask & 1) color = 0;
    if (mask & 2) color = 1;
    if (mask & 4) color = 2;
    if (mask & 8) color = 3;
    int maxColor = FUN_1403bad30(currency);
    if (color > maxColor) color = maxColor;
    return color;
}
MS2_REPLACE(0x1403BB320, FUN_1403bb320, 136, 0xB34AD0FF);

MS2_EMIT_CRT_MEMMOVE_S();
