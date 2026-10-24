// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The first two functions after the item-enchant code, static
// members of CItemDefaultData (RTTI name; its own file follows at 0x140583fa0): the range check of a default-table index
// and the lookup of the default value 2 in the table of that index.
// MS2-UNIT: unit_140583f00
// MS2-RANGE: 0x140583f00-0x140583fa0 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include <atlcoll.h>
#include "ms2/ms2recover.h"

// The key of a default table (name invented; the enum value 2 is looked up).
enum Unk_ItemDefaultKind { kItemDefaultKind2 = 2 };

// Members used here only; the class is recovered with ?\itemdefaultdata.cpp.
class CItemDefaultData
{
public:
    static int FUN_140583f00(int nTable);           // default value of kind 2 in the table, 0 if the index is out of range
    static int FUN_140583f70(int nTable);           // 1 if nTable is 0 or 1
    static void FUN_140587a50();                    // message box "<class> is not initialized" until the tables are loaded
    static ATL::CAtlMap<Unk_ItemDefaultKind, int> ms_aMaps[2];      // 0x143aafa40, 0x48 bytes each
};

// @0x140583f00
int CItemDefaultData::FUN_140583f00(int nTable)
{
    FUN_140587a50();
    if (FUN_140583f70(nTable) == 0) {
        return 0;
    }
    int nValue = 0;
    Unk_ItemDefaultKind eKind = kItemDefaultKind2;
    ms_aMaps[nTable].Lookup(eKind, nValue);
    return nValue;
}

// @0x140583f70
int CItemDefaultData::FUN_140583f70(int nTable)
{
    if (nTable < 0 || nTable >= 2) {
        return 0;
    }
    return 1;
}
