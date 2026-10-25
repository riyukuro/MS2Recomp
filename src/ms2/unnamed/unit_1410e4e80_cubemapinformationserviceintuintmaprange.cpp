// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// CubeMapInformationService integer-to-unsigned map equal-range helpers.
// MS2-UNIT: unit_1410e4e80
// MS2-RANGE: 0x1410e4e80-0x1410e5150 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$_Eqrange@H@?$_Tree@V?$_Tmap_traits@HIU?$less@H@std@@V?$CustomAllocator@U?$pair@$$CBHI@std@@@efd@@$0A@@std@@@std@@IEBA?AU?$pair@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHI@std@@@std@@@std@@@std@@V12@@1@AEBH@Z 0x1410e4f10 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/client/ms2/cubemapinformationservice_tail.h"

// Instantiate the real service container without constructing DLL-local state.
void Unk_CMISRange1410e4e80(Unk_CMISMapIntUInt& map, const int& key)
{
    (void)map.equal_range(key);
}
