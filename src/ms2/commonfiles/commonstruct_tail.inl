// commonstruct_tail.inl - the template instantiations of commonstruct.cpp's COMDAT tail (parts #3 and #4,
// 0x14027f2d0-0x14028b820). NOT an original file. The original TU instantiated these implicitly from its member
// functions (recovered in commonstruct.cpp / commonstruct_wa..wd.cpp, which call the copies through their exe
// addresses); here they are instantiated explicitly over the same element types. The linker sorted the tail by
// mangled name, so the parts interleave every container; both part sources include this file and pair their own range.
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include <vector>
#include <list>
#include <map>
#include <atlcoll.h>
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/tptrvalue.h"
#include "ms2/placeholder/commonstructptred.h"
#include "ms2/commonfiles/commonstruct.h"
#include "ms2/commonfiles/commonstruct_wa.h"
#include "ms2/commonfiles/commonpricerecord.h"
#include "ms2/placeholder/packetlogqueue.h"
#include "ms2/commonfiles/questmasktable.h"
#include "ms2/commonfiles/skillcompactcontroltable.h"
#include "ms2/placeholder/invokeeffectoption.h"
#include "ms2/placeholder/mstime.h"
#include "ms2/commonfiles/logstring.h"
#include "ms2/commonfiles/os.h"

class CItemDataTable;

// The value of LockedIntMap's map (unit_140268010.cpp): 4 bytes, one byte on the wire; an enum, so CAtlMap passes it by
// reference.
enum Unk_LimitValue { Unk_LimitValue_Zero = 0 };

// ---- smart pointers (TPtr<T> = MS2Ptr<T>) ----
template class MS2Ptr<AdditionalEffectEventCtx>;
template class MS2Ptr<CAdditionalEvent>;
template class MS2Ptr<ChangeableProductInfo>;
template class MS2Ptr<CIngredientInfo>;
template class MS2Ptr<CPtred>;
template class MS2Ptr<CUserChangeableItemHistory>;
template class MS2Ptr<CUserLimitHistory>;
template class MS2Ptr<InvokeEffectOption>;
template class MS2Ptr<NpcShopItemLife>;
template class MS2Ptr<TPtredDummy<ATL::CAtlList<MS2Ptr<CCompactControlSkill> > > >;
template class TPtrValue<CUserLimitGroup::HistoryList>;

// ---- header inlines whose first copy is in this TU (referenced through selectany pointers, the
// MS2_EMIT_CRT_MEMMOVE_S idiom, so the compiler emits them here) ----
__declspec(selectany) extern void (CAdditionalEvent::* const ms2_pfnCsAdditionalEventAdd)(Unk_AdditionalEventValue) = &CAdditionalEvent::Add;
__declspec(selectany) extern void (CLogString::* const ms2_pfnCsLogText)(unsigned __int64, unsigned __int64, int, const wchar_t*) =
    &CLogString::FUN_1402804e0;
__declspec(selectany) extern __time64_t (CMsTime::* const ms2_pfnCsMsTimeGet)() const = &CMsTime::Get;
template CItemDataTable* TSingleton<CItemDataTable>::GetInstance();

// ---- STL ----
template class std::vector<CStringA>;
template class std::vector<MS2Ptr<CIngredientInfo> >;
template class std::vector<MS2Ptr<CPtred> >;
template class std::vector<ItemEntity>;
template class std::vector<__int64>;
template class std::list<MS2Ptr<CUserChangeableItemHistory> >;
template class std::map<int, int>;
template class std::_Vector_iterator<std::_Vector_val<std::_Simple_types<ItemEntity> > >;
template class std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<ItemEntity> > >;
template class std::reverse_iterator<std::vector<ItemEntity>::iterator>;
template class std::_Vector_iterator<std::_Vector_val<std::_Simple_types<MS2Ptr<CIngredientInfo> > > >;
template class std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<MS2Ptr<CIngredientInfo> > > >;

// ---- ATL ----
template class ATL::CAtlArray<Unk_CommonPrice>;
template class ATL::CAtlArray<Unk_CommonPriceRecord>;
template class ATL::CAtlArray<Unk_Z16i>;
// The quest-mask range as the exe's CAtlArray<Unk_Z16i>::CallConstructors (0x140280770) constructs it: with an
// out-of-line zeroing ctor (0x14027dcb0). questmasktable.h's Unk_Z16i is ctor-less (its users zero it by hand through
// FUN_14027dcb0), so the constructing member is instantiated over this element.
struct Unk_QuestMaskRange : Unk_Z16i { Unk_QuestMaskRange(); };
template void ATL::CAtlArray<Unk_QuestMaskRange>::CallConstructors(Unk_QuestMaskRange*, size_t);
template class ATL::CAtlArray<__int64>;
template class ATL::CAtlArray<int>;
template class ATL::CAtlArray<Unk_CommonPacketLogEntry>;
// Unk_CommonResendQueue::CopyAfter's result array (move-only element: only Add)
template size_t ATL::CAtlArray<Unk_CommonCachedPacket>::Add(const Unk_CommonCachedPacket&);
template class ATL::CAtlList<Unk_AdditionalEventValue>;
// The resend queue's list (Unk_CommonResendQueue): its element is move-only, so only the members the queue uses.
template ATL::CAtlList<Unk_CommonCachedPacket>::~CAtlList();
template POSITION ATL::CAtlList<Unk_CommonCachedPacket>::AddTail(const Unk_CommonCachedPacket&);
template Unk_CommonCachedPacket& ATL::CAtlList<Unk_CommonCachedPacket>::GetAt(POSITION);
template Unk_CommonCachedPacket& ATL::CAtlList<Unk_CommonCachedPacket>::GetHead();
template Unk_CommonCachedPacket& ATL::CAtlList<Unk_CommonCachedPacket>::GetNext(POSITION&);
template bool ATL::CAtlList<Unk_CommonCachedPacket>::IsEmpty() const;
template void ATL::CAtlList<Unk_CommonCachedPacket>::RemoveAll();
template Unk_CommonCachedPacket ATL::CAtlList<Unk_CommonCachedPacket>::RemoveHead();
template void ATL::CAtlList<Unk_CommonCachedPacket>::RemoveHeadNoReturn();
template class ATL::CAtlList<MS2Ptr<CUserLimitHistory> >;
template class ATL::CAtlMap<int, int>;
template class ATL::CAtlMap<int, Unk_LimitValue>;
template class ATL::CAtlMap<int, __int64>;
template class ATL::CRBTree<unsigned __int64, TPtrValue<CUserLimitGroup::HistoryList> >;
template class ATL::CRBMap<unsigned __int64, TPtrValue<CUserLimitGroup::HistoryList> >;
