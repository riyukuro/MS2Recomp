// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// CubeMapInformationService nearest-cell map equal-range helpers.
// MS2-UNIT: unit_1410e5420
// MS2-RANGE: 0x1410e5420-0x1410e56f0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$_Eqrange@H@?$_Tree@V?$_Tmap_traits@HUUnk_Int3@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_Int3@@@std@@@3@$0A@@std@@@std@@IEBA?AU?$pair@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_Int3@@@std@@@std@@@std@@@std@@V12@@1@AEBH@Z 0x1410e54b0 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/client/ms2/cubemapinformationservice_tail.h"

// Instantiate the real service container without constructing DLL-local state.
void Unk_CMISRange1410e5420(Unk_CMISMapNear& map, const int& key)
{
    (void)map.equal_range(key);
}
