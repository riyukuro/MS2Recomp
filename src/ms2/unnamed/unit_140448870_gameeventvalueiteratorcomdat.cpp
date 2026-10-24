// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). COMDATs of commonfiles\gameeventvalue.cpp's real TU
// (0x140422c10-0x14046c710), sorted by mangled name: the tree iterators' operator++ for the event value maps
// (_Tree_const_iterator ++/++(int) for 12 maps, _Tree_iterator ++ for 9 and ++(int) for one, and the
// _Tree_unchecked_const_iterator ++ that the const ones call). gameeventvalue.cpp's bodies reference them; they are
// emitted here through explicit instantiations. The copies are byte-identical, so every one is pinned by name order.
// MS2-UNIT: unit_140448870
// MS2-RANGE: 0x140448870-0x1404495e0 .text$mn
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VArcadeOpenContext@@@@@std@@@std@@@std@@@std@@QEAA?AV01@H@Z 0x140448870
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VArcadeOpenContext@@@@@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x1404488c0
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@@std@@QEAA?AV01@H@Z 0x1404488e0
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x140448930
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VBurningLevelupContext@@@@@std@@@std@@@std@@@std@@QEAA?AV01@H@Z 0x140448950
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VBurningLevelupContext@@@@@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x1404489a0
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VCollectItemGroupContext@@@@@std@@@std@@@std@@@std@@QEAA?AV01@H@Z 0x1404489c0
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VCollectItemGroupContext@@@@@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x140448a10
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VEventShopNpcContext@@@@@std@@@std@@@std@@@std@@QEAA?AV01@H@Z 0x140448a30
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VEventShopNpcContext@@@@@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x140448a80
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemBoxEventContext@@@@@std@@@std@@@std@@@std@@QEAA?AV01@H@Z 0x140448aa0
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemBoxEventContext@@@@@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x140448af0
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VLimitedQuantityContext@@@@@std@@@std@@@std@@@std@@QEAA?AV01@H@Z 0x140448b10
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VLimitedQuantityContext@@@@@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x140448b60
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBKV?$map@U?$pair@HK@std@@HU?$less@U?$pair@HK@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@HK@std@@H@std@@@2@@std@@@std@@@std@@@std@@@std@@QEAA?AV01@H@Z 0x140448b80
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBKV?$map@U?$pair@HK@std@@HU?$less@U?$pair@HK@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@HK@std@@H@std@@@2@@std@@@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x140448bd0
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBKV?$map@_KIU?$less@_K@std@@V?$allocator@U?$pair@$$CB_KI@std@@@2@@std@@@std@@@std@@@std@@@std@@QEAA?AV01@H@Z 0x140448bf0
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBKV?$map@_KIU?$less@_K@std@@V?$allocator@U?$pair@$$CB_KI@std@@@2@@std@@@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x140448c40
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HK@std@@H@std@@@std@@@std@@@std@@QEAA?AV01@H@Z 0x140448c60
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HK@std@@H@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x140448cb0
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_DungeonGroupType@@U?$pair@HH@std@@@std@@@std@@@std@@@std@@QEAA?AV01@H@Z 0x140448cd0
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_DungeonGroupType@@U?$pair@HH@std@@@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x140448d20
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KI@std@@@std@@@std@@@std@@QEAA?AV01@H@Z 0x140448d40
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KI@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x140448d90
// MS2-PIN: ??E?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VArcadeOpenContext@@@@@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x140448db0
// MS2-PIN: ??E?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x140448dd0
// MS2-PIN: ??E?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VBurningLevelupContext@@@@@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x140448df0
// MS2-PIN: ??E?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VCollectItemGroupContext@@@@@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x140448e10
// MS2-PIN: ??E?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemBoxEventContext@@@@@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x140448e30
// MS2-PIN: ??E?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VLimitedQuantityContext@@@@@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x140448e50
// MS2-PIN: ??E?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBKV?$map@U?$pair@HK@std@@HU?$less@U?$pair@HK@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@HK@std@@H@std@@@2@@std@@@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x140448e70
// MS2-PIN: ??E?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_DungeonGroupType@@U?$pair@HH@std@@@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x140448e90
// MS2-PIN: ??E?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KI@std@@@std@@@std@@@std@@QEAA?AV01@H@Z 0x140448eb0
// MS2-PIN: ??E?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KI@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x140448f00
// MS2-PIN: ??E?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VArcadeOpenContext@@@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ 0x140448f20
// MS2-PIN: ??E?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBII@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ 0x140448fb0
// MS2-PIN: ??E?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VBurningLevelupContext@@@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ 0x140449040
// MS2-PIN: ??E?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VCollectItemGroupContext@@@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ 0x1404490d0
// MS2-PIN: ??E?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VEventShopNpcContext@@@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ 0x140449160
// MS2-PIN: ??E?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VItemBoxEventContext@@@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ 0x1404491f0
// MS2-PIN: ??E?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VLimitedQuantityContext@@@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ 0x140449280
// MS2-PIN: ??E?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBKV?$map@U?$pair@HK@std@@HU?$less@U?$pair@HK@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@HK@std@@H@std@@@2@@std@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ 0x140449310
// MS2-PIN: ??E?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBKV?$map@_KIU?$less@_K@std@@V?$allocator@U?$pair@$$CB_KI@std@@@2@@std@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ 0x1404493a0
// MS2-PIN: ??E?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@HK@std@@H@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ 0x140449430
// MS2-PIN: ??E?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_DungeonGroupType@@U?$pair@HH@std@@@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ 0x1404494c0
// MS2-PIN: ??E?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KI@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAAAEAV01@XZ 0x140449550
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\gameeventvalue.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <afx.h>
#include <atlcoll.h>
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/commonfiles/gameeventvalue.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

typedef std::map<int, MS2Ptr<ArcadeOpenContext> > Unk_ArcadeMap;
typedef std::map<unsigned, unsigned> Unk_IdMap;
typedef std::map<unsigned, MS2Ptr<BurningLevelupContext> > Unk_BurningMap;
typedef std::map<unsigned, MS2Ptr<CollectItemGroupContext> > Unk_CollectMap;
typedef std::map<unsigned, MS2Ptr<EventShopNpcContext> > Unk_ShopNpcMap;
typedef std::map<unsigned, MS2Ptr<ItemBoxEventContext> > Unk_ItemBoxMap;
typedef std::map<unsigned, MS2Ptr<LimitedQuantityContext> > Unk_QuantityMap;
typedef std::map<std::pair<int, unsigned long>, int> Unk_RateMap;
typedef std::map<unsigned long, Unk_RateMap> Unk_RateEventMap;
typedef std::map<unsigned __int64, unsigned> Unk_CountMap;
typedef std::map<unsigned long, Unk_CountMap> Unk_BuffMap;
typedef std::map<Unk_DungeonGroupType, std::pair<int, int> > Unk_GroupMap;

#define MS2_CONST_INC(M) \
    template M::const_iterator& M::const_iterator::operator++(); \
    template M::const_iterator M::const_iterator::operator++(int);
#define MS2_INC(M) template M::iterator& M::iterator::operator++();

// @0x140448870 .. 0x140448d90 (the unchecked ones at 0x140448f20 .. 0x140449550)
MS2_CONST_INC(Unk_ArcadeMap)
MS2_CONST_INC(Unk_IdMap)
MS2_CONST_INC(Unk_BurningMap)
MS2_CONST_INC(Unk_CollectMap)
MS2_CONST_INC(Unk_ShopNpcMap)
MS2_CONST_INC(Unk_ItemBoxMap)
MS2_CONST_INC(Unk_QuantityMap)
MS2_CONST_INC(Unk_RateEventMap)
MS2_CONST_INC(Unk_BuffMap)
MS2_CONST_INC(Unk_RateMap)
MS2_CONST_INC(Unk_GroupMap)
MS2_CONST_INC(Unk_CountMap)
// @0x140448db0 .. 0x140448f00
MS2_INC(Unk_ArcadeMap)
MS2_INC(Unk_IdMap)
MS2_INC(Unk_BurningMap)
MS2_INC(Unk_CollectMap)
MS2_INC(Unk_ItemBoxMap)
MS2_INC(Unk_QuantityMap)
MS2_INC(Unk_RateEventMap)
MS2_INC(Unk_GroupMap)
MS2_INC(Unk_CountMap)
template Unk_CountMap::iterator Unk_CountMap::iterator::operator++(int);
