// ugcmapitem.h - the housing cube stock of the client (client\ms2\ugcmapitem.cpp). NOT an original header (names
// assumed: CUGCMapItem is the RTTI name of the element, the stock class name is invented).
#pragma once

#include <afx.h>
#include <atlcoll.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/cubeiteminfo.h"

class CItem;
class COutPacket;

// One entry of the cube stock: a UGC item the player owns (0x40, vftable from CPtred's virtual dtor).
class CUGCMapItem : public CPtred
{
public:
    CUGCMapItem();                                          // 0x140dfc1b0
    ~CUGCMapItem();                                         // 0x140dfc240
    void FUN_140dfc280(int n);
    void SetItemId(int nItemId);
    void SetUid(__int64 nUid);
    void SetCount(__int64 nCount);
    void SetLook(MS2Ptr<CUgcItemLook> spLook);
    int FUN_140dfc350();                                    // m_n18
    int GetItemId();                                    // the item id
    __int64 GetUid();                                // the uid
    __int64 GetCount();                                // the count
    MS2Ptr<CUgcItemLook> GetLook();                   // the look
    __int64 FUN_140dfc420();                                // the id of the look (0 without one)
    int m_n18;                                              // +0x18
    int m_nItemId;                                          // +0x1c
    __int64 m_nUid;                                         // +0x20
    __int64 m_nCount;                                       // +0x28
    MS2Ptr<CUgcItemLook> m_spLook;                          // +0x30
};
MS2_CHECK_SIZE(CUGCMapItem, 0x40);

// The stock: the items keyed by uid (an ATL red-black map with the default block size 10).
class Unk_CubeStock
{
public:
    typedef ATL::CRBMap<unsigned __int64, MS2Ptr<CUGCMapItem> > Map;
    Map m_map;                                              // +0x00
    Unk_CubeStock();                                        // 0x140dfc480
    ~Unk_CubeStock();                                       // 0x140dfc4b0
    void FUN_140dfc4e0();
    void FUN_140dfc4f0();                                   // remove all
    int FUN_140dfc520(CUGCMapItem* pItem);                  // add (0x11 when the uid is in the stock)
    void FUN_140dfc6e0(unsigned __int64 nUid);              // remove
    void FUN_140dfc750(ATL::CAtlArray<MS2Ptr<CUGCMapItem> >& out);   // every item
    MS2Ptr<CUGCMapItem> FUN_140dfc800(int nItemId);         // the first item with this item id
    MS2Ptr<CUGCMapItem> FUN_140dfc8f0(unsigned __int64 nUid);   // by uid
    MS2Ptr<CUGCMapItem> FUN_140dfc9b0(unsigned __int64 nUid);   // by uid (via Lookup's result)
    int FUN_140dfca60();                                    // number of items
    int FUN_140dfcb00(int nItemId);                         // total count of an item id
    int FUN_140dfcbf0(int nItemId, __int64 nLookId);        // total count of an item id with this look
    void FUN_140dfcd00(void* pFilter, ATL::CAtlArray<MS2Ptr<CItem> >& out);   // the stock as items
};
extern Unk_CubeStock DAT_143ab2e50;
