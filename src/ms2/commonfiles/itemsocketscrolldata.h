// itemsocketscrolldata.h - CItemSocketScrollData / CItemSocketScrollDataServer / CItemSocketScrollTable (RTTI names):
// the item socket scroll table read from Table/itemSocketScroll.xml (<scroll id type minLv maxLv slot rank usePart
// tradableCountDeduction .../>). Header name assumed. Member names are invented from use.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/ccachedata.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/cvaliddata.h"
#include "ms2/commonfiles/itemdroptable.h"         // ItemDropPicker

class Unk_140165cf0;                    // the tinyxml element wrapper (FUN_140165cf0 = FirstChildElement)

// The xml "type" attribute (read through the enum reader, so it is an enum). Only the value 1 is told apart.
enum ItemSocketScrollType
{
    ITEM_SOCKET_SCROLL_TYPE_0 = 0,
    ITEM_SOCKET_SCROLL_TYPE_1 = 1,      // the server data reads successProb / openCount for it
};

// One <scroll> row. RTTI CItemSocketScrollData, 0x70 bytes, base CPtred; vftable slot 0 the deleting destructor,
// slot 1 the xml reader.
class CItemSocketScrollData : public CPtred
{
public:
    CItemSocketScrollData();                // 0x140624700
    virtual ~CItemSocketScrollData();       // 0x140624790
    virtual void Read(Unk_140165cf0* pElem);    // 0x140624810

    ItemSocketScrollType m_eType;           // +0x18 "type"
    int m_nUnk1c;                           // +0x1c (1 by default; not read from the xml)
    unsigned short m_nMinLv;                // +0x20 "minLv"
    unsigned short m_nMaxLv;                // +0x22 "maxLv"
    ATL::CAtlArray<unsigned int> m_arrSlot; // +0x28 "slot"
    ATL::CAtlArray<unsigned int> m_arrRank; // +0x48 "rank"
    bool m_bTradableCountDeduction;         // +0x68 "tradableCountDeduction"
};
MS2_CHECK_SIZE(CItemSocketScrollData, 0x70);
MS2_CHECK_OFFSET(CItemSocketScrollData, m_arrSlot, 0x28);
MS2_CHECK_OFFSET(CItemSocketScrollData, m_arrRank, 0x48);
MS2_CHECK_OFFSET(CItemSocketScrollData, m_bTradableCountDeduction, 0x68);

typedef MS2Ptr<CItemSocketScrollData> CItemSocketScrollDataPtr;

// RTTI CItemSocketScrollDataServer: the data plus the success probability / open count.
class CItemSocketScrollDataServer : public CItemSocketScrollData
{
public:
    CItemSocketScrollDataServer();          // 0x140624a10
    virtual ~CItemSocketScrollDataServer(); // 0x140624a80
    virtual void Read(Unk_140165cf0* pElem);    // 0x140624ac0

    unsigned int m_nSuccessProb;            // +0x70 "successProb" (type 1 only)
    unsigned int m_nOpenCount;              // +0x74 "openCount" (type 1 only)
    ItemDropPicker<int> m_unk78;            // +0x78 (ctor 0x1402fc040, dtor 0x1402febe0)
};
MS2_CHECK_OFFSET(CItemSocketScrollDataServer, m_nSuccessProb, 0x70);
MS2_CHECK_OFFSET(CItemSocketScrollDataServer, m_unk78, 0x78);

// The table. RTTI CItemSocketScrollTable, 0xb0 bytes: TSingleton +0, CCacheData +8, CValidData +0x30, the lock +0x38
// and the id -> row map +0x68. Created by CGameApp::InitInstance (?\ms2.cpp).
class CItemSocketScrollTable : public TSingleton<CItemSocketScrollTable>,
                               public CCacheData,
                               public CValidData<CItemSocketScrollTable>
{
public:
    CItemSocketScrollTable();               // 0x140624b30
    virtual ~CItemSocketScrollTable();      // 0x140624c00

    int Load();                             // 0x140624cc0 parses the xml into the map (always 1)
    int Reload();                           // 0x1406250e0 reloads when the xml changed on disk
    CItemSocketScrollDataPtr GetData(unsigned int nId);     // 0x140625180 the row for an id (null when missing)

    static void CheckInit();                // 0x140625830
    static void SetInit(bool b);            // 0x140626700

    static bool s_bInit;                    // DAT_143aaffe0

private:
    MS2_LAYOUT_FRIEND;
    CLockCriticalSection m_lock;                                    // +0x38
    ATL::CAtlMap<unsigned int, CItemSocketScrollDataPtr> m_map;     // +0x68 id -> row
};
MS2_CHECK_SIZE(CItemSocketScrollTable, 0xb0);
MS2_CHECK_OFFSET(CItemSocketScrollTable, m_lock, 0x38);
MS2_CHECK_OFFSET(CItemSocketScrollTable, m_map, 0x68);
