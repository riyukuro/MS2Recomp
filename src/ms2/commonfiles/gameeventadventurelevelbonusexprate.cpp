// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The first part of the COMDAT tail of commonfiles/gameevent.cpp
// (sorted by mangled name): the dtors of the GameEvent subclasses / *Context types and the container glue over their
// element types (sibling of unit_1403e9650, which holds the ??_G deleting dtors and the rest). The vftables are
// emitted by the instantiations below, which pull in the dtor COMDATs.
// MS2-UNIT: ?\gameeventadventurelevelbonusexprate.cpp
// MS2-RANGE: 0x1403e4a90-0x1403e8230 .text$mn
// MS2-GUESS-LOOKALIKES
// MS2-PIN: ??1BurningLevelupContext@@UEAA@XZ 0x1403e58e0
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??1?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@QEAA@XZ 0x1403e5800 ; prop
// MS2-PIN: ??1CNode@?$CAtlMap@HV?$MS2Ptr@VTreeWatering_TreeResource@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VTreeWatering_TreeResource@@@@@3@@ATL@@QEAA@XZ 0x1403e59c0 ; prop
// MS2-PIN: ??1CNode@?$CAtlMap@HV?$MS2Ptr@VTreeWatering_TreeStep@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VTreeWatering_TreeStep@@@@@3@@ATL@@QEAA@XZ 0x1403e59e0 ; prop
// MS2-PIN: ??1CNode@?$CAtlMap@IV?$MS2Ptr@UQuestContext@TimeRunEventContext@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@UQuestContext@TimeRunEventContext@@@@@3@@ATL@@QEAA@XZ 0x1403e5a00 ; prop
// MS2-PIN: ??1CNode@?$CAtlMap@IV?$MS2Ptr@VDungeonExtraRewardCountCtx@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VDungeonExtraRewardCountCtx@@@@@3@@ATL@@QEAA@XZ 0x1403e5a20 ; prop
// MS2-PIN: ??4?$MS2Ptr@VBonusGameBlueMarbleSlot@@@@QEAAAEAV0@AEBV0@@Z 0x1403e7300 ; prop
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\gameevent.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <afx.h>
#include <atlcoll.h>
#include <new>
#include <vector>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/commonfiles/gameevent.h"
#include "ms2/commonfiles/itemgift.h"
#include "ms2/commonfiles/gameeventcontext.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/placeholder/cgameeventvaluemanager.h"
#include "ms2/placeholder/cgamerule.h"
#include "ms2/placeholder/cshopeventmanager.h"
#include "ms2/placeholder/cshutdownevent.h"
#include "ms2/placeholder/gameeventuservaluenametable.h"
#include "ms2/client/ms2/effectservice.h"
#include "ms2/client/ms2/guildmanager.h"
#include "ms2/client/ms2/uiservice.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/ms2recover.h"

// The vftables (and with them the ??_G deleting dtors) of these classes are emitted by gameevent.cpp's out-of-line
// ctors, which are not part of this unit. Instantiating the implicit copy ctors emits the same COMDATs here (a ctor
// stores the vftable pointer, so the vftable and its slot-0 ??_G come with it) without defining an exe symbol: the exe
// has no copy ctors of these classes. Not exe code.
template <class T>
void Unk_GameEventCopy(void* p, const T& o)
{
    new (p) T(o);
}
template void Unk_GameEventCopy<BurningLevelupContext>(void*, const BurningLevelupContext&);
template void Unk_GameEventCopy<GalleryContext::Card>(void*, const GalleryContext::Card&);
template void Unk_GameEventCopy<CoupleDanceContext>(void*, const CoupleDanceContext&);
template void Unk_GameEventCopy<EnchantRateEventContext>(void*, const EnchantRateEventContext&);
template void Unk_GameEventCopy<EventQuestContext>(void*, const EventQuestContext&);
template void Unk_GameEventCopy<GameEventAdventureLevelBonusExpRate>(void*, const GameEventAdventureLevelBonusExpRate&);
template void Unk_GameEventCopy<GameEventArcadeOpen>(void*, const GameEventArcadeOpen&);
template void Unk_GameEventCopy<GameEventBattlePetSpawn>(void*, const GameEventBattlePetSpawn&);
template void Unk_GameEventCopy<GameEventBingoEvent>(void*, const GameEventBingoEvent&);
template void Unk_GameEventCopy<GameEventBlackMarketFeeDiscount>(void*, const GameEventBlackMarketFeeDiscount&);
template void Unk_GameEventCopy<GameEventBlueMarble>(void*, const GameEventBlueMarble&);
template void Unk_GameEventCopy<GameEventBurningLevelup>(void*, const GameEventBurningLevelup&);
template void Unk_GameEventCopy<GameEventCollectItemGroup>(void*, const GameEventCollectItemGroup&);
template void Unk_GameEventCopy<GameEventCoupleDance>(void*, const GameEventCoupleDance&);
template void Unk_GameEventCopy<GameEventDeleteUrlCache>(void*, const GameEventDeleteUrlCache&);
template void Unk_GameEventCopy<GameEventDungeonBonusReward>(void*, const GameEventDungeonBonusReward&);
template void Unk_GameEventCopy<GameEventDungeonEnterTimeLimit>(void*, const GameEventDungeonEnterTimeLimit&);
template void Unk_GameEventCopy<GameEventDungeonOpenPeriod>(void*, const GameEventDungeonOpenPeriod&);
template void Unk_GameEventCopy<GameEventDungeonRoomShutdown>(void*, const GameEventDungeonRoomShutdown&);
template void Unk_GameEventCopy<GameEventEnchantRate>(void*, const GameEventEnchantRate&);
template void Unk_GameEventCopy<GameEventEpicRestart>(void*, const GameEventEpicRestart&);
template void Unk_GameEventCopy<GameEventEventFieldPopup>(void*, const GameEventEventFieldPopup&);
template void Unk_GameEventCopy<GameEventFestival>(void*, const GameEventFestival&);
template void Unk_GameEventCopy<GameEventFieldEffect>(void*, const GameEventFieldEffect&);
template void Unk_GameEventCopy<GameEventFieldShutdown>(void*, const GameEventFieldShutdown&);
template void Unk_GameEventCopy<GameEventFindDungeonHelperBonus>(void*, const GameEventFindDungeonHelperBonus&);
template void Unk_GameEventCopy<GameEventFinishPayback>(void*, const GameEventFinishPayback&);
template void Unk_GameEventCopy<GameEventFreeAirTaxi>(void*, const GameEventFreeAirTaxi&);
template void Unk_GameEventCopy<GameEventGallery>(void*, const GameEventGallery&);
template void Unk_GameEventCopy<GameEventGameMenuPopup>(void*, const GameEventGameMenuPopup&);
template void Unk_GameEventCopy<GameEventGuildChampionship>(void*, const GameEventGuildChampionship&);
template void Unk_GameEventCopy<GameEventGuildCoin>(void*, const GameEventGuildCoin&);
template void Unk_GameEventCopy<GameEventGuildEventFund>(void*, const GameEventGuildEventFund&);
template void Unk_GameEventCopy<GameEventGuildExp>(void*, const GameEventGuildExp&);
template void Unk_GameEventCopy<GameEventGuildFund>(void*, const GameEventGuildFund&);
template void Unk_GameEventCopy<GameEventGuildPersonalSkillSale>(void*, const GameEventGuildPersonalSkillSale&);
template void Unk_GameEventCopy<GameEventGuildSkillSale>(void*, const GameEventGuildSkillSale&);
template void Unk_GameEventCopy<GameEventGuildVsGameOpen>(void*, const GameEventGuildVsGameOpen&);
template void Unk_GameEventCopy<GameEventItemBox>(void*, const GameEventItemBox&);
template void Unk_GameEventCopy<GameEventItemBuff>(void*, const GameEventItemBuff&);
template void Unk_GameEventCopy<GameEventLevelUpPackage>(void*, const GameEventLevelUpPackage&);
template void Unk_GameEventCopy<GameEventLongTermAttendGift>(void*, const GameEventLongTermAttendGift&);
template void Unk_GameEventCopy<GameEventMasteryReduce>(void*, const GameEventMasteryReduce&);
template void Unk_GameEventCopy<GameEventMasteryReward>(void*, const GameEventMasteryReward&);
template void Unk_GameEventCopy<GameEventMeratMarketNotice>(void*, const GameEventMeratMarketNotice&);
template void Unk_GameEventCopy<GameEventMeratMarketOpenTab>(void*, const GameEventMeratMarketOpenTab&);
template void Unk_GameEventCopy<GameEventMesoRevival>(void*, const GameEventMesoRevival&);
template void Unk_GameEventCopy<GameEventNpcEventDrop>(void*, const GameEventNpcEventDrop&);
template void Unk_GameEventCopy<GameEventNpcShopGivePoint>(void*, const GameEventNpcShopGivePoint&);
template void Unk_GameEventCopy<GameEventNpcShopResetPriceSale>(void*, const GameEventNpcShopResetPriceSale&);
template void Unk_GameEventCopy<GameEventNpcShopTalk>(void*, const GameEventNpcShopTalk&);
template void Unk_GameEventCopy<GameEventOntime>(void*, const GameEventOntime&);
template void Unk_GameEventCopy<GameEventSAHotTime>(void*, const GameEventSAHotTime&);
template void Unk_GameEventCopy<GameEventPCBangSAHotTime>(void*, const GameEventPCBangSAHotTime&);
template void Unk_GameEventCopy<GameEventPetBattleExp>(void*, const GameEventPetBattleExp&);
template void Unk_GameEventCopy<GameEventPetComposeSale>(void*, const GameEventPetComposeSale&);
template void Unk_GameEventCopy<GameEventPetMastery>(void*, const GameEventPetMastery&);
template void Unk_GameEventCopy<GameEventPremiumMarketSale>(void*, const GameEventPremiumMarketSale&);
template void Unk_GameEventCopy<GameEventPublicTest>(void*, const GameEventPublicTest&);
template void Unk_GameEventCopy<GameEventQuestAdditionalReward>(void*, const GameEventQuestAdditionalReward&);
template void Unk_GameEventCopy<GameEventQuestTag>(void*, const GameEventQuestTag&);
template void Unk_GameEventCopy<GameEventRankDuel>(void*, const GameEventRankDuel&);
template void Unk_GameEventCopy<GameEventReactor>(void*, const GameEventReactor&);
template void Unk_GameEventCopy<GameEventRps>(void*, const GameEventRps&);
template void Unk_GameEventCopy<GameEventSaleAutoFishing>(void*, const GameEventSaleAutoFishing&);
template void Unk_GameEventCopy<GameEventSaleAutoPlayInstrument>(void*, const GameEventSaleAutoPlayInstrument&);
template void Unk_GameEventCopy<GameEventSaleBeautyShop>(void*, const GameEventSaleBeautyShop&);
template void Unk_GameEventCopy<GameEventSaleChat>(void*, const GameEventSaleChat&);
template void Unk_GameEventCopy<GameEventSaleEnchant>(void*, const GameEventSaleEnchant&);
template void Unk_GameEventCopy<GameEventSaleGemStoneUpgrade>(void*, const GameEventSaleGemStoneUpgrade&);
template void Unk_GameEventCopy<GameEventSaleLapenshardUpgradeRGB>(void*, const GameEventSaleLapenshardUpgradeRGB&);
template void Unk_GameEventCopy<GameEventSalePetCrystal>(void*, const GameEventSalePetCrystal&);
template void Unk_GameEventCopy<GameEventSaleRemake>(void*, const GameEventSaleRemake&);
template void Unk_GameEventCopy<GameEventSaleSkillUpgrade>(void*, const GameEventSaleSkillUpgrade&);
template void Unk_GameEventCopy<GameEventSaleUGCDesign>(void*, const GameEventSaleUGCDesign&);
template void Unk_GameEventCopy<GameEventShutdownBillboard>(void*, const GameEventShutdownBillboard&);
template void Unk_GameEventCopy<GameEventShutdownDummy>(void*, const GameEventShutdownDummy&);
template void Unk_GameEventCopy<GameEventShutdownFunctionItem>(void*, const GameEventShutdownFunctionItem&);
template void Unk_GameEventCopy<GameEventShutdownInteractObjectId>(void*, const GameEventShutdownInteractObjectId&);
template void Unk_GameEventCopy<GameEventShutdownSkillItem>(void*, const GameEventShutdownSkillItem&);
template void Unk_GameEventCopy<GameEventShutdownUGCBanner>(void*, const GameEventShutdownUGCBanner&);
template void Unk_GameEventCopy<GameEventSnowman>(void*, const GameEventSnowman&);
template void Unk_GameEventCopy<GameEventStampEvent>(void*, const GameEventStampEvent&);
template void Unk_GameEventCopy<GameEventStampEventChar>(void*, const GameEventStampEventChar&);
template void Unk_GameEventCopy<GameEventStarShop>(void*, const GameEventStarShop&);
template void Unk_GameEventCopy<GameEventTimeRunEvent>(void*, const GameEventTimeRunEvent&);
template void Unk_GameEventCopy<GameEventTrafficOptimizer>(void*, const GameEventTrafficOptimizer&);
template void Unk_GameEventCopy<GameEventTransferItemBound>(void*, const GameEventTransferItemBound&);
template void Unk_GameEventCopy<GameEventTreeWatering>(void*, const GameEventTreeWatering&);
template void Unk_GameEventCopy<GameEventUGCMapContractSale>(void*, const GameEventUGCMapContractSale&);
template void Unk_GameEventCopy<GameEventUGCMapExtensionSale>(void*, const GameEventUGCMapExtensionSale&);
template void Unk_GameEventCopy<GameEventUGCMapSaleCoupon>(void*, const GameEventUGCMapSaleCoupon&);
template void Unk_GameEventCopy<GameEventUgcMapCommendationGM>(void*, const GameEventUgcMapCommendationGM&);
template void Unk_GameEventCopy<GameEventUpdateString>(void*, const GameEventUpdateString&);
template void Unk_GameEventCopy<GameEventUserCondition>(void*, const GameEventUserCondition&);
template void Unk_GameEventCopy<GameEventWorldmapIcon>(void*, const GameEventWorldmapIcon&);
template void Unk_GameEventCopy<MesoRevivalEventContext>(void*, const MesoRevivalEventContext&);
template void Unk_GameEventCopy<NpcEventDropEventContext>(void*, const NpcEventDropEventContext&);
template void Unk_GameEventCopy<OntimeEventContext>(void*, const OntimeEventContext&);
template void Unk_GameEventCopy<PreminmMarketSaleEventContext>(void*, const PreminmMarketSaleEventContext&);
template void Unk_GameEventCopy<TimeRunEventContext::QuestContext>(void*, const TimeRunEventContext::QuestContext&);
template void Unk_GameEventCopy<LongTermAttendGiftContext::Reward>(void*, const LongTermAttendGiftContext::Reward&);
template void Unk_GameEventCopy<StampEventContext::Reward>(void*, const StampEventContext::Reward&);
template void Unk_GameEventCopy<SAHotTimeEventContext>(void*, const SAHotTimeEventContext&);
template void Unk_GameEventCopy<SaleCube>(void*, const SaleCube&);
template void Unk_GameEventCopy<SkillUpgradeSaleEventContext>(void*, const SkillUpgradeSaleEventContext&);
template void Unk_GameEventCopy<StampEventContext::Stamp>(void*, const StampEventContext::Stamp&);
template void Unk_GameEventCopy<TreeWatering_EmotionDay>(void*, const TreeWatering_EmotionDay&);
template void Unk_GameEventCopy<TreeWatering_TreeResource>(void*, const TreeWatering_TreeResource&);
template void Unk_GameEventCopy<TreeWatering_TreeStep>(void*, const TreeWatering_TreeStep&);
// The same for the classes with non-copyable (CAtlArray / CAtlMap) members, through the implicit default ctor. Not exe
// code.
template <class T>
void Unk_GameEventConstruct(void* p)
{
    new (p) T;
}
template void Unk_GameEventConstruct<GameEventExchangeScrollSale>(void*);
template void Unk_GameEventConstruct<GameEventItemTradeRestriction>(void*);
// These have the gameevent.cpp ctor only; their header-only tag ctors emit the vftable.
template <class T>
void Unk_GameEventConstructTagged(void* p)
{
    new (p) T(Unk_VftableEmitTag());
}
template void Unk_GameEventConstructTagged<GameEventDungeonExtraReward>(void*);
template void Unk_GameEventConstructTagged<GameEventSaleHousing>(void*);
template void Unk_GameEventConstructTagged<StampEventContext>(void*);
template void Unk_GameEventConstructTagged<GameEventMassiveConstructionEvent>(void*);
template void Unk_GameEventConstructTagged<GameEventConstructShowItem>(void*);
template void Unk_GameEventConstructTagged<GameEventSaleItemsRestricted>(void*);
template void Unk_GameEventConstructTagged<GameEventShutdownUGCUpload>(void*);
template void Unk_GameEventConstructTagged<GameEventChatFiltering>(void*);
template void Unk_GameEventConstructTagged<GameEventIgnoreConstructionLockEvent>(void*);
template void Unk_GameEventConstructTagged<GalleryContext>(void*);
template void Unk_GameEventConstructTagged<SnowmanContext>(void*);
template void Unk_GameEventConstructTagged<RpsContext>(void*);
template void Unk_GameEventConstructTagged<GameEventCustomTriggerString>(void*);
template void Unk_GameEventConstructTagged<ReactorContext>(void*);
template void Unk_GameEventConstructTagged<RpsContext::RewardData>(void*);
template void Unk_GameEventConstructTagged<SnowmanContext::Snowman>(void*);
template void Unk_GameEventConstructTagged<TreeWateringContext>(void*);


// The non-virtual ??_G of the container elements (allocator<T>::destroy / CAtlMap::FreeNode call `??_G(p, 0)`); the
// maps are destroyed whole (CNode is private), which emits the ??_GCNode through RemoveAll / FreeNode.
template <class T>
void Unk_GameEventDestroyElem(T* p)
{
    p->~T();
}
template void Unk_GameEventDestroyElem<MS2Ptr<GalleryContext::Card> >(MS2Ptr<GalleryContext::Card>*);
template void Unk_GameEventDestroyElem<MS2Ptr<StampEventContext::Reward> >(MS2Ptr<StampEventContext::Reward>*);
template void Unk_GameEventDestroyElem<MS2Ptr<RpsContext::RewardData> >(MS2Ptr<RpsContext::RewardData>*);
template void Unk_GameEventDestroyElem<MS2Ptr<SnowmanContext::Snowman> >(MS2Ptr<SnowmanContext::Snowman>*);
template void Unk_GameEventDestroyElem<MS2Ptr<StampEventContext::Stamp> >(MS2Ptr<StampEventContext::Stamp>*);
template void Unk_GameEventDestroyElem<MS2Ptr<EventTimeLimitDungeonContext> >(MS2Ptr<EventTimeLimitDungeonContext>*);
template void Unk_GameEventDestroyElem<MS2Ptr<TreeWatering_EmotionDay> >(MS2Ptr<TreeWatering_EmotionDay>*);
template void Unk_GameEventDestroyElem<std::vector<ItemEntity> >(std::vector<ItemEntity>*);
template void Unk_GameEventDestroyElem<CAtlMap<int, MS2Ptr<TreeWatering_TreeResource> >>(CAtlMap<int, MS2Ptr<TreeWatering_TreeResource> >*);
template void Unk_GameEventDestroyElem<CAtlMap<int, MS2Ptr<TreeWatering_TreeStep> >>(CAtlMap<int, MS2Ptr<TreeWatering_TreeStep> >*);
template void Unk_GameEventDestroyElem<CAtlMap<unsigned int, MS2Ptr<TimeRunEventContext::QuestContext> >>(CAtlMap<unsigned int, MS2Ptr<TimeRunEventContext::QuestContext> >*);
template void Unk_GameEventDestroyElem<CAtlMap<unsigned int, MS2Ptr<DungeonExtraRewardCountCtx> >>(CAtlMap<unsigned int, MS2Ptr<DungeonExtraRewardCountCtx> >*);
template void Unk_GameEventDestroyElem<CRBMultiMap<Unk_SaleHousingKey, MS2Ptr<SaleCube> > >(CRBMultiMap<Unk_SaleHousingKey, MS2Ptr<SaleCube> >*);
template void Unk_GameEventDestroyElem<Unk_GameEventStrPair>(Unk_GameEventStrPair*);

// The container instantiations behind the context Read/Write and lookup paths (SetAt / Lookup / RemoveKey / Add /
// SetCount / CallDestructors / Rehash).  gameevent.cpp's own bodies are not written yet, so the members are emitted
// through explicit instantiations; the exe keeps only the ones those bodies use.
// (Explicit class instantiations also emit members the exe never kept; they stay unpaired.)
// BlueMarbleEventContext holds two trees over one MS2Ptr value (AddRef 0x1403f3830, dtor 0x1403e4e20): +0x38 (key
// type unknown, int assumed) and the "reward"/"distance" map at +0xa8 (unsigned compare).  The value is assumed to be
// BonusGameBlueMarbleSlot (unconfirmed).
struct Unk_GameEventTokenId { int m_0; };  // 1403d7eb0 tokenizes a string into these (copied as a class)
MS2_CHECK_SIZE(Unk_GameEventTokenId, 4);

template class ATL::CAtlArray<MS2Ptr<GalleryContext::Card> >;
template class ATL::CAtlArray<MS2Ptr<LongTermAttendGiftContext::Reward> >;
template class ATL::CAtlArray<MS2Ptr<StampEventContext::Reward> >;
template class ATL::CAtlArray<MS2Ptr<RpsContext::RewardData> >;
template class ATL::CAtlArray<MS2Ptr<SnowmanContext::Snowman> >;
template class ATL::CAtlArray<MS2Ptr<StampEventContext::Stamp> >;
template class ATL::CAtlArray<MS2Ptr<EventTimeLimitDungeonContext> >;
template class ATL::CAtlArray<MS2Ptr<TreeWatering_EmotionDay> >;
template class ATL::CAtlArray<Unk_GameEventTokenId>;
template class ATL::CAtlArray<Unk_ItemTradeRestrictionType>;
template class ATL::CAtlArray<CStringW>;
template class ATL::CAtlArray<unsigned __int64>;
template class ATL::CAtlMap<int, MS2Ptr<TreeWatering_TreeResource> >;
template class ATL::CAtlMap<int, MS2Ptr<TreeWatering_TreeStep> >;
template class ATL::CAtlMap<unsigned int, MS2Ptr<TimeRunEventContext::QuestContext> >;
template class ATL::CAtlMap<unsigned int, MS2Ptr<DungeonExtraRewardCountCtx> >;
template class ATL::CRBTree<unsigned int, MS2Ptr<BonusGameBlueMarbleSlot> >;
template class ATL::CRBMap<unsigned int, MS2Ptr<BonusGameBlueMarbleSlot> >;
template class ATL::CRBTree<int, MS2Ptr<BonusGameBlueMarbleSlot> >;
template class ATL::CRBMap<int, MS2Ptr<BonusGameBlueMarbleSlot> >;
template class ATL::CRBTree<Unk_SaleHousingKey, MS2Ptr<SaleCube> >;
template class ATL::CRBMultiMap<Unk_SaleHousingKey, MS2Ptr<SaleCube> >;
// CStringW -> CStringW (Lookup called by 0x1403d8110 and gameeventvalue's 0x14042cad0).
template class ATL::CAtlMap<CStringW, CStringW, CStringElementTraits<CStringW> >;

// The smart pointer members over the element types (AssignRaw / copy assignment / get ...). Not exe code.
template class MS2Ptr<GalleryContext::Card>;
template class MS2Ptr<LongTermAttendGiftContext::Reward>;
template class MS2Ptr<StampEventContext::Reward>;
template class MS2Ptr<RpsContext::RewardData>;
template class MS2Ptr<SnowmanContext::Snowman>;
template class MS2Ptr<StampEventContext::Stamp>;
template class MS2Ptr<EventTimeLimitDungeonContext>;
template class MS2Ptr<TreeWatering_EmotionDay>;
template class MS2Ptr<TreeWatering_TreeResource>;
template class MS2Ptr<TreeWatering_TreeStep>;
template class MS2Ptr<TimeRunEventContext::QuestContext>;
template class MS2Ptr<DungeonExtraRewardCountCtx>;
template class MS2Ptr<SaleCube>;
template class MS2Ptr<BonusGameBlueMarbleSlot>;

// More smart pointer element types (brute force; the exe keeps only the ones its bodies use). Not exe code.
template class MS2Ptr<BurningLevelupContext>;
template class MS2Ptr<CoupleDanceContext>;
template class MS2Ptr<EnchantRateEventContext>;
template class MS2Ptr<EventQuestContext>;
template class MS2Ptr<GalleryContext>;
template class MS2Ptr<GameEventAdventureLevelBonusExpRate>;
template class MS2Ptr<GameEventArcadeOpen>;
template class MS2Ptr<GameEventBattlePetSpawn>;
template class MS2Ptr<GameEventBingoEvent>;
template class MS2Ptr<GameEventBlackMarketFeeDiscount>;
template class MS2Ptr<GameEventBlueMarble>;
template class MS2Ptr<GameEventBurningLevelup>;
template class MS2Ptr<GameEventChatFiltering>;
template class MS2Ptr<GameEventCollectItemGroup>;
template class MS2Ptr<GameEventConstructShowItem>;
template class MS2Ptr<GameEventCoupleDance>;
template class MS2Ptr<GameEventCustomTriggerString>;
template class MS2Ptr<GameEventDeleteUrlCache>;
template class MS2Ptr<GameEventDungeonBonusReward>;
template class MS2Ptr<GameEventDungeonEnterTimeLimit>;
template class MS2Ptr<GameEventDungeonExtraReward>;
template class MS2Ptr<GameEventDungeonOpenPeriod>;
template class MS2Ptr<GameEventDungeonRoomShutdown>;
template class MS2Ptr<GameEventEnchantRate>;
template class MS2Ptr<GameEventEpicRestart>;
template class MS2Ptr<GameEventEventFieldPopup>;
template class MS2Ptr<GameEventExchangeScrollSale>;
template class MS2Ptr<GameEventFestival>;
template class MS2Ptr<GameEventFieldEffect>;
template class MS2Ptr<GameEventFieldShutdown>;
template class MS2Ptr<GameEventFindDungeonHelperBonus>;
template class MS2Ptr<GameEventFinishPayback>;
template class MS2Ptr<GameEventFreeAirTaxi>;
template class MS2Ptr<GameEventGallery>;
template class MS2Ptr<GameEventGameMenuPopup>;
template class MS2Ptr<GameEventGuildChampionship>;
template class MS2Ptr<GameEventGuildCoin>;
template class MS2Ptr<GameEventGuildEventFund>;
template class MS2Ptr<GameEventGuildExp>;
template class MS2Ptr<GameEventGuildFund>;
template class MS2Ptr<GameEventGuildPersonalSkillSale>;
template class MS2Ptr<GameEventGuildSkillSale>;
template class MS2Ptr<GameEventGuildVsGameOpen>;
template class MS2Ptr<GameEventIgnoreConstructionLockEvent>;
template class MS2Ptr<GameEventItemBox>;
template class MS2Ptr<GameEventItemBuff>;
template class MS2Ptr<GameEventItemTradeRestriction>;
template class MS2Ptr<GameEventLevelUpPackage>;
template class MS2Ptr<GameEventLongTermAttendGift>;
template class MS2Ptr<GameEventMassiveConstructionEvent>;
template class MS2Ptr<GameEventMasteryReduce>;
template class MS2Ptr<GameEventMasteryReward>;
template class MS2Ptr<GameEventMeratMarketNotice>;
template class MS2Ptr<GameEventMeratMarketOpenTab>;
template class MS2Ptr<GameEventMesoRevival>;
template class MS2Ptr<GameEventNpcEventDrop>;
template class MS2Ptr<GameEventNpcShopGivePoint>;
template class MS2Ptr<GameEventNpcShopResetPriceSale>;
template class MS2Ptr<GameEventNpcShopTalk>;
template class MS2Ptr<GameEventOntime>;
template class MS2Ptr<GameEventPCBangSAHotTime>;
template class MS2Ptr<GameEventPetBattleExp>;
template class MS2Ptr<GameEventPetComposeSale>;
template class MS2Ptr<GameEventPetMastery>;
template class MS2Ptr<GameEventPremiumMarketSale>;
template class MS2Ptr<GameEventPublicTest>;
template class MS2Ptr<GameEventQuestAdditionalReward>;
template class MS2Ptr<GameEventQuestTag>;
template class MS2Ptr<GameEventRankDuel>;
template class MS2Ptr<GameEventReactor>;
template class MS2Ptr<GameEventRps>;
template class MS2Ptr<GameEventSAHotTime>;
template class MS2Ptr<GameEventSale>;
template class MS2Ptr<GameEventSaleAutoFishing>;
template class MS2Ptr<GameEventSaleAutoPlayInstrument>;
template class MS2Ptr<GameEventSaleBeautyShop>;
template class MS2Ptr<GameEventSaleChat>;
template class MS2Ptr<GameEventSaleEnchant>;
template class MS2Ptr<GameEventSaleGemStoneUpgrade>;
template class MS2Ptr<GameEventSaleHousing>;
template class MS2Ptr<GameEventSaleItemsRestricted>;
template class MS2Ptr<GameEventSaleLapenshardUpgradeRGB>;
template class MS2Ptr<GameEventSalePetCrystal>;
template class MS2Ptr<GameEventSaleRemake>;
template class MS2Ptr<GameEventSaleSkillUpgrade>;
template class MS2Ptr<GameEventSaleUGCDesign>;
template class MS2Ptr<GameEventShutdownBillboard>;
template class MS2Ptr<GameEventShutdownDummy>;
template class MS2Ptr<GameEventShutdownFunctionItem>;
template class MS2Ptr<GameEventShutdownInteractObjectId>;
template class MS2Ptr<GameEventShutdownSkillItem>;
template class MS2Ptr<GameEventShutdownUGCBanner>;
template class MS2Ptr<GameEventShutdownUGCUpload>;
template class MS2Ptr<GameEventSnowman>;
template class MS2Ptr<GameEventStampEvent>;
template class MS2Ptr<GameEventStampEventChar>;
template class MS2Ptr<GameEventStarShop>;
template class MS2Ptr<GameEventTimeRunEvent>;
template class MS2Ptr<GameEventTrafficOptimizer>;
template class MS2Ptr<GameEventTransferItemBound>;
template class MS2Ptr<GameEventTreeWatering>;
template class MS2Ptr<GameEventUGCMapContractSale>;
template class MS2Ptr<GameEventUGCMapExtensionSale>;
template class MS2Ptr<GameEventUGCMapSaleCoupon>;
template class MS2Ptr<GameEventUgcMapCommendationGM>;
template class MS2Ptr<GameEventUpdateString>;
template class MS2Ptr<GameEventUserCondition>;
template class MS2Ptr<GameEventWorldmapIcon>;
template class MS2Ptr<MesoRevivalEventContext>;
template class MS2Ptr<NpcEventDropEventContext>;
template class MS2Ptr<OntimeEventContext>;
template class MS2Ptr<PreminmMarketSaleEventContext>;
template class MS2Ptr<ReactorContext>;
template class MS2Ptr<RpsContext>;
template class MS2Ptr<SAHotTimeEventContext>;
template class MS2Ptr<SkillUpgradeSaleEventContext>;
template class MS2Ptr<SnowmanContext>;
template class MS2Ptr<StampEventContext>;
template class MS2Ptr<TreeWateringContext>;
template class MS2Ptr<ItemEntity>;
