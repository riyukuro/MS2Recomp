// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). std::map<std::pair<int,int>, V>::equal_range and its _Eqrange helper; V is a stand-in.
// MS2-UNIT: unit_1410e6aa0
// MS2-RANGE: 0x1410e6aa0-0x1410e6d70 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include <map>
#include "ms2/ms2recover.h"

struct Unk_Eqrange1410e6aa0Value { int v; };

typedef std::map<std::pair<int,int>, Unk_Eqrange1410e6aa0Value> Unk_Eqrange1410e6aa0Map;

void Unk_Eqrange1410e6aa0Anchor()
{
    Unk_Eqrange1410e6aa0Map m;
    (void)m.equal_range(std::pair<int,int>());
}
