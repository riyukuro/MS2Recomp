// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CUGCMapItem (one owned UGC item) and the cube stock
// that keys them by uid (an ATL CRBMap), with the ATL/MS2Ptr instantiations they pull in.
// MS2-UNIT: client\ms2\ugcmapitem.cpp
// MS2-RANGE: 0x140dfc1b0-0x140dfee10 .text$mn
// MS2-RANGE: 0x1400beab0-0x1400bead1 .text$di
// MS2-RANGE: 0x142c9cf70-0x142c9cf85 .text$yd
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\ugcmapitem.cpp"
#include "ms2/placeholder/ms2stdafx.h"

#include "ugcmapitem.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/cugcmanager.h"
#include "ms2/commonfiles/item.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

MS2Ptr<CItemData> FUN_14053f870(int nItemId);
CUgcManager* FUN_14052d220();
void FUN_140892da0(CUgcItemLook* pDest, const CUgcItemLook* pSource);
extern bool FUN_14026d4d0(void*, int, __int64);

// @0x140dfc1b0
CUGCMapItem::CUGCMapItem()
    : m_n18(1), m_nItemId(0), m_nUid(0), m_nCount(0), m_spLook(0)
{
}

// @0x140dfc240
CUGCMapItem::~CUGCMapItem()
{
}

// @0x140dfc280
void CUGCMapItem::FUN_140dfc280(int n)
{
    m_n18 = n;
}

// @0x140dfc2a0
void CUGCMapItem::SetItemId(int nItemId)
{
    m_nItemId = nItemId;
}

// @0x140dfc2c0
void CUGCMapItem::SetUid(__int64 nUid)
{
    m_nUid = nUid;
}

// @0x140dfc2e0
void CUGCMapItem::SetCount(__int64 nCount)
{
    m_nCount = nCount;
}

// @0x140dfc300
void CUGCMapItem::SetLook(MS2Ptr<CUgcItemLook> spLook)
{
    m_spLook = spLook;
}

// @0x140dfc350
int CUGCMapItem::FUN_140dfc350()
{
    return m_n18;
}

// @0x140dfc370
int CUGCMapItem::GetItemId()
{
    return m_nItemId;
}

// @0x140dfc390
__int64 CUGCMapItem::GetUid()
{
    return m_nUid;
}

// @0x140dfc3b0
__int64 CUGCMapItem::GetCount()
{
    return m_nCount;
}

// @0x140dfc3d0
MS2Ptr<CUgcItemLook> CUGCMapItem::GetLook()
{
    return m_spLook;
}

// @0x140dfc420
__int64 CUGCMapItem::FUN_140dfc420()
{
    __int64 n;
    if (m_spLook.get() != 0)
        n = m_spLook->m_n18;
    else
        n = 0;
    return n;
}

// @0x140dfc480
Unk_CubeStock::Unk_CubeStock()
{
}

// @0x140dfc4b0
Unk_CubeStock::~Unk_CubeStock()
{
}

// @0x140dfc4e0
void Unk_CubeStock::FUN_140dfc4e0()
{
}

// @0x140dfc4f0
void Unk_CubeStock::FUN_140dfc4f0()
{
    m_map.RemoveAll();
}

// @0x140dfc520
int Unk_CubeStock::FUN_140dfc520(CUGCMapItem* pItem)
{
    if (m_map.Lookup(pItem->GetUid()) != 0)
        return 0x11;
    {
        MS2Ptr<CUGCMapItem> spItem(pItem);
        m_map.SetAt(pItem->GetUid(), spItem);
    }
    MS2Ptr<CUgcItemLook> spLook = pItem->GetLook();
    bool bName = (spLook.get() ? true : false) && spLook->GetLocalPath().GetLength() > 0;
    if (bName)
        FUN_14052d220()->FUN_1418841f0(spLook, MS2Ptr<CItem>(0), 0);
    return 0;
}

// @0x140dfc6e0
void Unk_CubeStock::FUN_140dfc6e0(unsigned __int64 nUid)
{
    MS2Ptr<CUGCMapItem> spItem;
    if (m_map.Lookup(nUid, spItem))
        m_map.RemoveKey(nUid);
}

// @0x140dfc750
void Unk_CubeStock::FUN_140dfc750(ATL::CAtlArray<MS2Ptr<CUGCMapItem> >& out)
{
    for (POSITION pos = m_map.GetHeadPosition(); pos != NULL; m_map.GetNext(pos))
    {
        MS2Ptr<CUGCMapItem> spItem = m_map.GetValueAt(pos);
        if (spItem == 0)
            continue;
        out.Add(spItem);
    }
}

// @0x140dfc800
MS2Ptr<CUGCMapItem> Unk_CubeStock::FUN_140dfc800(int nItemId)
{
    for (POSITION pos = m_map.GetHeadPosition(); pos != NULL; m_map.GetNext(pos))
    {
        MS2Ptr<CUGCMapItem> spItem = m_map.GetValueAt(pos);
        if (spItem->GetItemId() == nItemId)
            return spItem;
    }
    return MS2Ptr<CUGCMapItem>(0);
}

// @0x140dfc8f0
MS2Ptr<CUGCMapItem> Unk_CubeStock::FUN_140dfc8f0(unsigned __int64 nUid)
{
    MS2Ptr<CUGCMapItem> spItem;
    m_map.Lookup(nUid, spItem);
    if (spItem.get() != 0)
        return spItem;
    return MS2Ptr<CUGCMapItem>(0);
}

// @0x140dfc9b0
MS2Ptr<CUGCMapItem> Unk_CubeStock::FUN_140dfc9b0(unsigned __int64 nUid)
{
    MS2Ptr<CUGCMapItem> spItem;
    if (m_map.Lookup(nUid, spItem))
        return spItem;
    return MS2Ptr<CUGCMapItem>(0);
}

// @0x140dfca60
int Unk_CubeStock::FUN_140dfca60()
{
    int n = 0;
    for (POSITION pos = m_map.GetHeadPosition(); pos != NULL; m_map.GetNext(pos))
    {
        MS2Ptr<CUGCMapItem> spItem = m_map.GetValueAt(pos);
        if (spItem.get() != 0)
            n = n + 1;
    }
    return n;
}

// @0x140dfcb00
int Unk_CubeStock::FUN_140dfcb00(int nItemId)
{
    int n = 0;
    for (POSITION pos = m_map.GetHeadPosition(); pos != NULL; m_map.GetNext(pos))
    {
        MS2Ptr<CUGCMapItem> spItem = m_map.GetValueAt(pos);
        if (spItem == 0)
            continue;
        if (spItem->GetItemId() == nItemId)
            n = n + spItem->FUN_140dfc350();
    }
    return n;
}

// @0x140dfcbf0
int Unk_CubeStock::FUN_140dfcbf0(int nItemId, __int64 nLookId)
{
    int n = 0;
    for (POSITION pos = m_map.GetHeadPosition(); pos != NULL; m_map.GetNext(pos))
    {
        MS2Ptr<CUGCMapItem> spItem = m_map.GetValueAt(pos);
        if (spItem == 0)
            continue;
        if (spItem->GetItemId() == nItemId)
        {
            if (spItem->FUN_140dfc420() == nLookId)
                n = n + spItem->FUN_140dfc350();
        }
    }
    return n;
}

// @0x140dfcd00
void Unk_CubeStock::FUN_140dfcd00(void* pFilter, ATL::CAtlArray<MS2Ptr<CItem> >& out)
{
    for (POSITION pos = m_map.GetHeadPosition(); pos != NULL; m_map.GetNext(pos))
    {
        MS2Ptr<CUGCMapItem> spItem = m_map.GetValueAt(pos);
        if (spItem == 0 || spItem->GetLook() == 0)
            continue;
        const MS2Ptr<CUgcItemLook>& rLook = spItem->GetLook();
        if (!FUN_14026d4d0(pFilter, rLook->m_n34, rLook->m_n38))
            continue;
        int nItemId = spItem->GetItemId();
        MS2Ptr<CItemData> spData = FUN_14053f870(nItemId);
        if (spData == 0)
            continue;
        if (spData->limit.enableRegisterMeratMarket)
        {
            MS2Ptr<CItem> spNew(new CItem);
            if (spNew.get() != 0)
            {
                spNew->FUN_14052b130(nItemId, 1, 0);
                spNew->FUN_140526a70(spItem->GetUid());
                if (spNew->FUN_1405278d0() != 0)
                {
                    {
                        MS2Ptr<CUgcItemLook> spItemLook = spItem->GetLook();
                        if (spItemLook.get() != 0)
                            FUN_140892da0(&reinterpret_cast<CItemUgc*>(spNew->FUN_1405278d0())->m_look, spItemLook.get());
                    }
                    out.Add(spNew);
                }
            }
        }
    }
}

#ifndef MS2_HOOK_DLL   // the hook DLL binds the exe's stock (symbols.tsv); a local copy would stay empty
Unk_CubeStock DAT_143ab2e50;
#endif
