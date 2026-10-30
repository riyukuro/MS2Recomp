// store.h - CStore, the client's item container for the player's bank / account store, recovered from
// MapleStory2.exe KMS2_DEV x64 (2022-04-13). Header name assumed (the unit is client\ms2\store.cpp); class and member
// names are invented from their use (assert text and packet shapes give the rest). Constructor, destructor, Initialize
// and Clear live in unit_140de0f70 (0x140de0f70-0x140de11a0) and are only declared here.
#pragma once

#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/placeholder/citem.h"

class CInPacket;

class CStore
{
public:
    struct LoadRequest { LoadRequest(); __int64 m_id; };                                    // 8 bytes
    struct MoveRequest { MoveRequest(); __int64 m_id; __int64 m_item; short m_slot; int m_count; };   // 0x18 bytes

    CStore();
    ~CStore();
    void Initialize();
    void Clear();                                                       // 0x140de1070
    int Add(CItem* pItem);                                              // 0x140de11a0
    void Remove(__int64 nId);                                           // 0x140de1380
    MS2Ptr<CItem> Find(__int64 nId);                                    // 0x140de1490
    MS2Ptr<CItem> FindType(int nType);                                  // 0x140de1540
    MS2Ptr<CItem> FindTypeCount(int nType, unsigned nCount);            // 0x140de1680
    int HasCount(int nType, int nCount);                               // 0x140de17e0
    int CountType(int nType);                                           // 0x140de1830
    int FreeTypeCount(int nType);                                       // 0x140de1950
    MS2Ptr<CItem> Slot(int nSlot);                                      // 0x140de1af0
    int Count();                                                        // 0x140de1c00
    int Capacity();                                                     // 0x140de1c30
    int Swap(int nA, int nB);                                           // 0x140de1c50
    int Move(int nSlot, MS2Ptr<CItem> pItem);                           // 0x140de1dd0
    void Append(ATL::CAtlArray<MS2Ptr<CItem> >& rItems);                // 0x140de1fd0
    int EmptySlot();                                                    // 0x140de20a0
    int AvailableSlot(MS2Ptr<CItem> pItem, int nCount);                 // 0x140de21a0
    int NeedsSort();                                                    // 0x140de2270
    int Allowed(int nType);                                             // 0x140de2490
    int CanMerge();                                                     // 0x140de2580
    __int64 Id();                                                       // 0x140de27c0
    void SetId(__int64 nId, int nType);                                 // 0x140de27e0
    int Ready();                                                        // 0x140de2860
    void SetReady(int nReady);                                          // 0x140de2880
    void Extend(int nExtended);                                         // 0x140de28a0
    int WithinCapacity();                                              // 0x140de2970
    int CurrentCapacity();                                              // 0x140de29b0
    void Reset();                                                       // 0x140de2a00
    void ResetId(__int64 nId, int nType);                               // 0x140de2a30
    void SetReceived(int nReceived);                                    // 0x140de2b10
    int Received();                                                     // 0x140de2b30
    __int64 Value4558();                                                // 0x140de2a80
    __int64 Value45b0();                                                // 0x140de2ab0
    __int64 Value4500();                                                // 0x140de2ae0
    void RequestLoad();                                                 // 0x140de2b50
    void RequestClose();                                                // 0x140de2bd0
    void RequestAction(int nAction, __int64 nId);             // 0x140de2c40
    void RequestExtend();                                               // 0x140de2ce0
    void RequestSort();                                                 // 0x140de2d60
    void Dispatch(CInPacket* pPacket);                                  // 0x140de3480
    void OnClear(CInPacket* pPacket);                                                     // 0x140de3610
    void OnBegin(CInPacket* pPacket);                                   // 0x140de3640
    void OnItems(CInPacket* pPacket);                                   // 0x140de3740
    void OnAdd(CInPacket* pPacket);                                     // 0x140de3870
    void OnRemove(CInPacket* pPacket);                                  // 0x140de3910
    void OnCount(CInPacket* pPacket);                                   // 0x140de3a50
    void OnCurrency(CInPacket* pPacket);                                // 0x140de3bc0
    void OnExtend(CInPacket* pPacket);                                  // 0x140de3c60
    void OnClose(CInPacket* pPacket);                                                     // 0x140de3ce0
    void OnSwap(CInPacket* pPacket);                                    // 0x140de3d40
    void OnList(CInPacket* pPacket);                                    // 0x140de4030
    void OnReset(CInPacket* pPacket);                                                     // 0x140de4320
    void OnError(CInPacket* pPacket);                                   // 0x140de4360
    void ReadItem(CInPacket* pPacket);                                  // 0x140de4690

    int m_capacity;                                                     // +0x00
    int m_extended;                                                     // +0x04
    __int64 m_id;                                                       // +0x08
    int m_type;                                                         // +0x10
    int m_ready;                                                        // +0x14
    int m_received;                                                     // +0x18
    CLockCriticalSection m_lock;                                        // +0x20
    ATL::CRBMap<__int64, MS2Ptr<CItem> > m_items;                       // +0x50
    ATL::CAtlArray<MS2Ptr<CItem> > m_slots;                             // +0x80
};
MS2_CHECK_SIZE(CStore, 0xa0);
MS2_CHECK_OFFSET(CStore, m_lock, 0x20);
MS2_CHECK_OFFSET(CStore, m_items, 0x50);
MS2_CHECK_OFFSET(CStore, m_slots, 0x80);

// The one CStore instance (the store table) at 0x143ab2d80 (unit_1400be790 defines it).
extern CStore DAT_143ab2d80;
#define MS2_STORE_TABLE DAT_143ab2d80
// Free functions of store.cpp taking the store table as first argument (put in / take out of the bank + play the sound).
void FUN_140de2dc0(void*, __int64 nId, int nSlot, int nCount, MS2Ptr<CItemData> pSound);       // 0x140de2dc0
void FUN_140de31f0(CStore* pStore, __int64 nId, int nSlot, int nCount, MS2Ptr<CItemData> pSound);   // 0x140de31f0
