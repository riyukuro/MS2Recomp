// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). COMDATs of commonfiles\gameeventvalue.cpp's real TU
// (0x140422c10-0x14046c710), sorted by mangled name: the `??1` (destructors) and `??4` (MS2Ptr copy / NULL assignment)
// part of its tail. The queue's guessed name "gameeventvalueidipevent.cpp" is not a separate file: these are the
// instantiations the event value classes of gameeventvalue.h make (CAtlMap / CRBTree nodes, the std::map / list
// members and their pairs, the context smart pointers, the nested context classes' implicit destructors).
// gameeventvalue.cpp's bodies reference them; they are emitted here through explicit instantiations and the
// Unk_GameEventValueTailInstances anchor (not exe code).
// MS2-GUESS-LOOKALIKES
// MS2-UNIT: ?\gameeventvalueidipevent.cpp
// MS2-RANGE: 0x140446320-0x1404475d0 .text$mn
// MS2-PIN: ??4?$MS2Ptr@VCNpcShopGivePointContextBase@@@@QEAAAEAV0@AEBV0@@Z 0x1404471b0
// MS2-PIN: ??4?$MS2Ptr@VEventShopNpcContext@@@@QEAAAEAV0@AEBV0@@Z 0x140447360
// MS2-PIN: ??4?$MS2Ptr@VLimitedQuantityContext@@@@QEAAAEAV0@AEBV0@@Z 0x140447420
// MS2-PIN: ??4?$MS2Ptr@VIDIPEventContext@CGameEventValueIDIPEvent@@@@QEAAAEAV0@AEBV0@@Z 0x140447510
// MS2-PIN: ??1?$MS2Ptr@VLimitedQuantityContext@@@@QEAA@XZ 0x1404464a0
// MS2-PIN: ??1CPair@?$CAtlMap@IV?$MS2Ptr@VUnk_FieldObjectDropListContext@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VUnk_FieldObjectDropListContext@@@@@3@@ATL@@QEAA@XZ 0x140446fe0
// MS2-PIN: ??1CPair@?$CAtlMap@IV?$MS2Ptr@VSpawnContext@CGameEventValueBattlePetSpawn@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VSpawnContext@CGameEventValueBattlePetSpawn@@@@@3@@ATL@@QEAA@XZ 0x140447000
// MS2-PIN: ??1CPair@?$CAtlMap@IV?$MS2Ptr@VUnk_DayItemContext@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2Ptr@VUnk_DayItemContext@@@@@3@@ATL@@QEAA@XZ 0x140447040
// MS2-PIN: ??4?$MS2Ptr@VItemBoxEventContext@@@@QEAAAEAV0@AEBV0@@Z 0x1404473a0
// MS2-PIN: ??4?$MS2Ptr@VMentoringContext@@@@QEAAAEAV0@AEBV0@@Z 0x1404474a0
// MS2-PIN: ??4?$MS2Ptr@VFestivalContext@@@@QEAAAEAV0@AEBV0@@Z 0x1404472e0
// MS2-PIN: ??1?$MS2Ptr@VEventShopNpcContext@@@@QEAA@XZ 0x140446470
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\gameeventvalue.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <afx.h>
#include <atlcoll.h>
#include <new>
#include <list>
#include <map>
#include <vector>
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/tptreddummy.h"
#include "ms2/commonfiles/gameeventvalue.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// The ATL containers whose destructor, CNode or CPair destructor this part of the tail holds.
template class ATL::CAtlMap<unsigned, unsigned short>;
template class ATL::CAtlMap<unsigned, bool>;
template class ATL::CAtlMap<unsigned, MS2Ptr<FestivalContext> >;
template class ATL::CAtlMap<unsigned, Unk_FieldIdListPtr>;
template class ATL::CAtlMap<unsigned, MS2Ptr<CNpcShopGivePointContextBase> >;
template class ATL::CAtlMap<unsigned, MS2Ptr<CGameEventValueIDIPEvent::IDIPEventContext> >;
template class ATL::CAtlMap<unsigned, MS2Ptr<CGameEventValueBattlePetSpawn::SpawnContext> >;
template class ATL::CAtlMap<unsigned, MS2Ptr<Unk_DayItemContext> >;
template class ATL::CAtlMap<unsigned, MS2Ptr<Unk_FieldObjectDropContext> >;
template class ATL::CAtlMap<unsigned, MS2Ptr<Unk_FieldObjectDropListContext> >;
template class ATL::CAtlMap<CStringW, Unk_FieldTimeSpan, ATL::CStringElementTraits<CStringW> >;
template class ATL::CRBTree<unsigned, unsigned>;
template class ATL::CRBTree<unsigned, MS2Ptr<CGameEventValueItemTradeRestriction::RestrictionData> >;

// The context smart pointers: destructor, copy assignment, `p = NULL`.
template MS2Ptr<CGameEventValueIDIPEvent::IDIPEventContext>::~MS2Ptr();
template Unk_FieldIdListPtr::~Unk_FieldPtr();
template MS2Ptr<DungeonBuffEventCtx>::~MS2Ptr();
template MS2Ptr<EventShopNpcContext>::~MS2Ptr();
template MS2Ptr<LimitedQuantityContext>::~MS2Ptr();
template MS2Ptr<Unk_DayItemContext>::~MS2Ptr();
template MS2Ptr<CGameEventValueBattlePetSpawn::SpawnContext>::~MS2Ptr();
template MS2Ptr<Unk_FieldObjectDropListContext>::~MS2Ptr();
template MS2Ptr<Unk_FieldObjectDropContext>::~MS2Ptr();

template MS2Ptr<CNpcShopGivePointContextBase>& MS2Ptr<CNpcShopGivePointContextBase>::operator=(
    const MS2Ptr<CNpcShopGivePointContextBase>&);
template MS2Ptr<CGameEventValueItemTradeRestriction::RestrictionData>&
MS2Ptr<CGameEventValueItemTradeRestriction::RestrictionData>::operator=(
    const MS2Ptr<CGameEventValueItemTradeRestriction::RestrictionData>&);
template Unk_FieldIdListPtr& Unk_FieldIdListPtr::operator=(const Unk_FieldIdListPtr&);
template MS2Ptr<BingoContext>& MS2Ptr<BingoContext>::operator=(const MS2Ptr<BingoContext>&);
template MS2Ptr<BingoContext>& MS2Ptr<BingoContext>::operator=(int);
template MS2Ptr<FestivalContext>& MS2Ptr<FestivalContext>::operator=(const MS2Ptr<FestivalContext>&);
template MS2Ptr<CoupleDanceContext>& MS2Ptr<CoupleDanceContext>::operator=(const MS2Ptr<CoupleDanceContext>&);
template MS2Ptr<EventShopNpcContext>& MS2Ptr<EventShopNpcContext>::operator=(const MS2Ptr<EventShopNpcContext>&);
template MS2Ptr<FieldEffectContext>& MS2Ptr<FieldEffectContext>::operator=(const MS2Ptr<FieldEffectContext>&);
template MS2Ptr<ItemBoxEventContext>& MS2Ptr<ItemBoxEventContext>::operator=(const MS2Ptr<ItemBoxEventContext>&);
template MS2Ptr<LimitedQuantityContext>& MS2Ptr<LimitedQuantityContext>::operator=(
    const MS2Ptr<LimitedQuantityContext>&);
template MS2Ptr<Unk_DayItemContext>& MS2Ptr<Unk_DayItemContext>::operator=(const MS2Ptr<Unk_DayItemContext>&);
template MS2Ptr<MentoringContext>& MS2Ptr<MentoringContext>::operator=(const MS2Ptr<MentoringContext>&);
template MS2Ptr<MentoringContext>& MS2Ptr<MentoringContext>::operator=(int);
template MS2Ptr<CGameEventValueIDIPEvent::IDIPEventContext>& MS2Ptr<CGameEventValueIDIPEvent::IDIPEventContext>::
operator=(const MS2Ptr<CGameEventValueIDIPEvent::IDIPEventContext>&);
template MS2Ptr<CGameEventValueBattlePetSpawn::SpawnContext>& MS2Ptr<CGameEventValueBattlePetSpawn::SpawnContext>::
operator=(const MS2Ptr<CGameEventValueBattlePetSpawn::SpawnContext>&);
template MS2Ptr<Unk_FieldObjectDropListContext>& MS2Ptr<Unk_FieldObjectDropListContext>::operator=(
    const MS2Ptr<Unk_FieldObjectDropListContext>&);
template MS2Ptr<Unk_FieldObjectDropContext>& MS2Ptr<Unk_FieldObjectDropContext>::operator=(
    const MS2Ptr<Unk_FieldObjectDropContext>&);

// The implicit destructors (std containers, their pairs, the nested contexts, the id list box) are only emitted when
// called: a qualified call each, so none of them is virtual. Not exe code.
void Unk_GameEventValueTailInstances(void* p)
{
    typedef std::list<MS2Ptr<EventShopNpcContext> > ShopNpcList;
    typedef std::map<unsigned long, std::map<unsigned __int64, unsigned> > BuffMap;
    typedef std::map<unsigned long, CGameEventValueMasteryReward::Rates> RewardMap;
    typedef std::map<Unk_DungeonGroupType, std::pair<int, int> > DungeonGroupMap;
    typedef std::_Uninitialized_backout_al<MS2Ptr<CollectItemGroupContext>*,
        std::allocator<MS2Ptr<CollectItemGroupContext> > > CollectBackout;
    typedef TPtredDummy<Unk_FieldIdList> IdListBox;
    typedef CGameEventValueMasteryReward::Rates Rates;

    ((std::map<int, MS2Ptr<ArcadeOpenContext> >*)p)->~map();
    ((std::map<unsigned, unsigned>*)p)->~map();
    ((std::map<unsigned long, unsigned long>*)p)->~map();
    ((std::map<unsigned, MS2Ptr<BurningLevelupContext> >*)p)->~map();
    ((std::map<unsigned, MS2Ptr<CollectItemGroupContext> >*)p)->~map();
    ((std::map<unsigned, MS2Ptr<EventShopNpcContext> >*)p)->~map();
    ((std::map<unsigned, MS2Ptr<ItemBoxEventContext> >*)p)->~map();
    ((std::map<unsigned, MS2Ptr<LimitedQuantityContext> >*)p)->~map();
    ((std::map<unsigned __int64, unsigned>*)p)->~map();
    ((BuffMap*)p)->~BuffMap();
    ((RewardMap*)p)->~RewardMap();
    ((Rates*)p)->~Rates();
    ((DungeonGroupMap*)p)->~DungeonGroupMap();
    ((std::map<unsigned long, ShopNpcList>*)p)->~map();
    ((ShopNpcList*)p)->~ShopNpcList();

    ((std::pair<int, MS2Ptr<ArcadeOpenContext> >*)p)->~pair();
    ((std::pair<unsigned, MS2Ptr<BurningLevelupContext> >*)p)->~pair();
    ((std::pair<unsigned, MS2Ptr<CollectItemGroupContext> >*)p)->~pair();
    ((std::pair<unsigned long, ShopNpcList>*)p)->~pair();

    {
        std::allocator<MS2Ptr<CollectItemGroupContext> > al;
        CollectBackout backout((MS2Ptr<CollectItemGroupContext>*)p, al);
    }

    ((IdListBox*)p)->IdListBox::~IdListBox();
    ((CGameEventValueIDIPEvent::IDIPEventContext*)p)->CGameEventValueIDIPEvent::IDIPEventContext::~IDIPEventContext();
    ((CGameEventValueItemTradeRestriction::RestrictionData*)p)
        ->CGameEventValueItemTradeRestriction::RestrictionData::~RestrictionData();
    ((CGameEventValueBattlePetSpawn::SpawnContext*)p)->CGameEventValueBattlePetSpawn::SpawnContext::~SpawnContext();
}
// MS2-PIN: ??4?$MS2Ptr@VUnk_DayItemContext@@@@QEAAAEAV0@AEBV0@@Z 0x140447460 ; this TU's MS2Ptr<Unk_DayItemContext>::operator= copy
