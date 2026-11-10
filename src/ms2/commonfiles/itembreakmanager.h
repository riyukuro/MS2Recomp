// Item breaking manager and records. Unk_ names are inferred, not original symbols.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/delegate.h"
#include "os.h"
class Unk_BreakInput { public: virtual void vfunc_0(); virtual unsigned char vfunc_1(); virtual unsigned short vfunc_2(); virtual unsigned vfunc_3(); virtual __int64 vfunc_4(); };
class Unk_BreakPacket { public: void* p0; Unk_BreakInput input; };
class Unk_BreakOutput { public: virtual void vfunc_0(); virtual void vfunc_1(unsigned char); virtual void vfunc_2(unsigned short); virtual void vfunc_3(unsigned); };
namespace ItemBreakCommon {
class BreakItem : public CPtred {
public:
    BreakItem(); BreakItem(__int64,int); virtual ~BreakItem() = default;
    void FUN_1405306f0(); void FUN_140530720(__int64,int); bool FUN_140530750() const;
    __int64 id; int count;
};
struct Unk_PreviewAmount { int low,high; };
class BreakPreview : public CPtred {
public:
    BreakPreview(); virtual ~BreakPreview() = default;
    BreakPreview FUN_1405307e0(const Unk_PreviewAmount&); BreakPreview FUN_140530860(int);
    void FUN_1405308d0(Unk_BreakOutput&) const; void FUN_140530920(Unk_BreakPacket&);
    int FUN_140530990() const; int FUN_1405309d0() const;
    int low,high;
};
typedef MS2Ptr<BreakItem> Ptr;   // C3: was the Unk_BreakPtr stand-in (same COMDATs as MS2Ptr<CMsgBoxData>)
typedef ATL::CAtlArray<Ptr> Items;
int FUN_140530a10(const Items&,__int64); void FUN_140530b00(Items&,unsigned); bool FUN_140530b40(Items&,int,__int64,int);
}
MS2_CHECK_SIZE(ItemBreakCommon::BreakItem,0x28);
MS2_CHECK_SIZE(ItemBreakCommon::BreakPreview,0x20);
class CItem;
typedef MS2Ptr<CItem> Unk_BreakItemPtr;   // C3: was a unit-local pointer class
MS2_CHECK_SIZE(Unk_BreakItemPtr,0x10);
MS2_CHECK_SIZE(ItemBreakCommon::Ptr,0x10);
MS2_CHECK_OFFSET(Unk_BreakPacket,input,8);
class CMsgBoxData;
class CItemBreakManager : public TSingleton<CItemBreakManager> {
public:
    typedef Unk_BreakItemPtr ItemPtr;
    CItemBreakManager(); virtual ~CItemBreakManager();
    int CanBreakItem(ItemPtr); int FUN_140531510(ItemPtr); int FUN_140531630(ItemPtr); bool FUN_1405316d0(ItemPtr); bool FUN_140531850(ItemPtr);
    int CanAddItem(ItemPtr); int IsBreakDialogOpen(); void SendItemDismantleMode0(int); void ResetBreakMode(); ItemPtr GetSlotItemClone(int);
    void RemoveMissingItems(); void RefreshActiveDialog(); void UpdateActiveDialogSlot(int); void ForwardPacketToDialog(Unk_BreakPacket&); void FUN_140532220();
    void OnItemDismantlePacket(Unk_BreakPacket&); int FUN_140532ab0(); int HasBreakItems(); int GetMaxItemRarity(); int SendItemDismantleMode3();
    int TryAddItem(ItemPtr,int); void SendItemDismantleMode1(__int64,int,int); void SendItemDismantleMode6(int,int); int RequestRemoveItem(ItemPtr);
    void AddItemWithConfirm(ItemPtr,int); bool OnDismantleCountMsgBox(int,const CMsgBoxData&); bool OnConfirmMessageBoxResult(int,const CMsgBoxData&); unsigned GetLastItemIndex();
    ItemBreakCommon::Items items; ATL::CAtlArray<unsigned __int64> pending; int type;
};
MS2_CHECK_SIZE(CItemBreakManager,0x50);
