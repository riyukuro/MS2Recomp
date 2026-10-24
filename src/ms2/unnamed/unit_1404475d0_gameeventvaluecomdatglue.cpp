// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Seven COMDATs of commonfiles\gameeventvalue.cpp's real TU
// (0x140422c10-0x14046c710), sorted by mangled name: the map<pair<int, DWORD>, int> copy assignment that
// CGameEventValueMasteryReward::Load uses, and the MS2Ptr<T> operator! / operator==(T*) of five event contexts.
// gameeventvalue.cpp's bodies reference them; the members are emitted here through explicit instantiations.
// MS2-UNIT: unit_1404475d0
// MS2-RANGE: 0x1404475d0-0x1404477b0 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\gameeventvalue.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <afx.h>
#include <atlcoll.h>
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/commonfiles/gameeventvalue.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// MS2-PIN: ??4?$_Tree@V?$_Tmap_traits@U?$pair@HK@std@@HU?$less@U?$pair@HK@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@HK@std@@H@std@@@2@$0A@@std@@@std@@QEAAAEAV01@AEBV01@@Z 0x1404475d0
// MS2-PIN: ??4?$map@U?$pair@HK@std@@HU?$less@U?$pair@HK@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@HK@std@@H@std@@@2@@std@@QEAAAEAV01@AEBV01@@Z 0x140447650
// MS2-PIN: ??7?$MS2Ptr@VLimitedQuantityContext@@@@QEBA_NXZ 0x140447680
// MS2-PIN: ??8?$MS2Ptr@VBingoContext@@@@QEBA_NPEAVBingoContext@@@Z 0x1404476b0
// MS2-PIN: ??8?$MS2Ptr@VBurningLevelupContext@@@@QEBA_NPEAVBurningLevelupContext@@@Z 0x1404476f0
// MS2-PIN: ??8?$MS2Ptr@VDungeonBuffEventCtx@@@@QEBA_NPEAVDungeonBuffEventCtx@@@Z 0x140447730
// MS2-PIN: ??8?$MS2Ptr@VMentoringContext@@@@QEBA_NPEAVMentoringContext@@@Z 0x140447770

// @0x140447650 (map::operator=), @0x1404475d0 (_Tree::operator=)
template std::map<std::pair<int, unsigned long>, int>& std::map<std::pair<int, unsigned long>, int>::operator=(
    const std::map<std::pair<int, unsigned long>, int>&);
// @0x140447680
template bool MS2Ptr<LimitedQuantityContext>::operator!() const;
// @0x1404476b0
template bool MS2Ptr<BingoContext>::operator==(BingoContext*) const;
// @0x1404476f0
template bool MS2Ptr<BurningLevelupContext>::operator==(BurningLevelupContext*) const;
// @0x140447730
template bool MS2Ptr<DungeonBuffEventCtx>::operator==(DungeonBuffEventCtx*) const;
// @0x140447770
template bool MS2Ptr<MentoringContext>::operator==(MentoringContext*) const;
