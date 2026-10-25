// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). std::map<int, V>::equal_range and its _Eqrange helper; V is a stand-in.
// MS2-UNIT: unit_1410e75e0
// MS2-RANGE: 0x1410e75e0-0x1410e78b0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$_Eqrange@H@?$_Tree@V?$_Tmap_traits@HUUnk_Eqrange1410e75e0Value@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_Eqrange1410e75e0Value@@@std@@@3@$0A@@std@@@std@@IEBA?AU?$pair@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_Eqrange1410e75e0Value@@@std@@@std@@@std@@@std@@V12@@1@AEBH@Z 0x1410e7670 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include <map>
#include "ms2/ms2recover.h"

struct Unk_Eqrange1410e75e0Value { int v; };

typedef std::map<int, Unk_Eqrange1410e75e0Value> Unk_Eqrange1410e75e0Map;

void Unk_Eqrange1410e75e0Anchor()
{
    Unk_Eqrange1410e75e0Map m;
    (void)m.equal_range(0);
}
