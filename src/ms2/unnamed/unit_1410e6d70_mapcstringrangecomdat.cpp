// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). std::map<CString, V>::equal_range and its _Eqrange helper; V is a stand-in.
// MS2-UNIT: unit_1410e6d70
// MS2-RANGE: 0x1410e6d70-0x1410e7040 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include <map>
#include "ms2/ms2recover.h"

struct Unk_Eqrange1410e6d70Value { int v; };

typedef std::map<CString, Unk_Eqrange1410e6d70Value> Unk_Eqrange1410e6d70Map;

void Unk_Eqrange1410e6d70Anchor()
{
    Unk_Eqrange1410e6d70Map m;
    (void)m.equal_range(CString());
}
