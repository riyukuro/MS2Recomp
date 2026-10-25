// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// CubeMapInformationService EntityID-to-property map equal-range helpers.
// MS2-UNIT: unit_1410e7310
// MS2-RANGE: 0x1410e7310-0x1410e75e0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$_Eqrange@VEntityID@egf@@@?$_Tree@V?$_Tmap_traits@VEntityID@egf@@VUnk_CMISPropPtr@@U?$less@VEntityID@egf@@@std@@V?$CustomAllocator@U?$pair@$$CBVEntityID@egf@@VUnk_CMISPropPtr@@@std@@@efd@@$0A@@std@@@std@@IEBA?AU?$pair@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBVEntityID@egf@@VUnk_CMISPropPtr@@@std@@@std@@@std@@@std@@V12@@1@AEBVEntityID@egf@@@Z 0x1410e73a0 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/client/ms2/cubemapinformationservice_tail.h"

// Instantiate the real service container without constructing DLL-local state.
void Unk_CMISRange1410e7310(Unk_CMISMapProp& map, const egf::EntityID& key)
{
    (void)map.equal_range(key);
}
