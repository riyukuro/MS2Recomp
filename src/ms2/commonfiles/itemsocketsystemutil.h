// itemsocketsystemutil.h - the item socket tables (RTTI names CItemSocketData, CItemSocketDataContainer, CItemSocketTable)
// loaded from Table/itemSocket.xml (<itemSocket id grade maxCount openType randomOpenRange fixOpenCount/>), and the
// EnableSocketUnlockFunction record of CItemSocketSystemUtil. Header name assumed from the unit path; member names are
// invented from the xml attributes and use.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ccachedata.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/citem.h"

class Unk_140165cf0;    // xml element (declared where the loader is)

// A min / max pair (the exe's ctor is 0x1402fc100, the setter 0x140303060 in dungeonmatch.cpp).
struct Unk_SocketRange
{
    // @0x1402fc100
    Unk_SocketRange() : m_nMin(0), m_nMax(0) {}
    int m_nMin;
    int m_nMax;
};
MS2_CHECK_SIZE(Unk_SocketRange, 8);

// One <itemSocket> row, 0x30 bytes.
class CItemSocketData : public CPtred
{
public:
    CItemSocketData();                      // 0x14062c7b0
    virtual ~CItemSocketData();             // 0x14062c830

    int m_nGrade;                           // +0x18 "grade"
    unsigned m_nMaxCount;                   // +0x1c "maxCount"
    int m_nOpenType;                        // +0x20 "openType": 0 fixed count, 1 random range
    Unk_SocketRange m_range;                // +0x24 "fixOpenCount" (min = max) / "randomOpenRange"
};
MS2_CHECK_SIZE(CItemSocketData, 0x30);
MS2_CHECK_OFFSET(CItemSocketData, m_nOpenType, 0x20);
MS2_CHECK_OFFSET(CItemSocketData, m_range, 0x24);

// All the rows of one item id (one per grade), 0x38 bytes.
class CItemSocketDataContainer : public CPtred
{
public:
    CItemSocketDataContainer();             // 0x14062c860
    virtual ~CItemSocketDataContainer();    // 0x14062c8b0

    MS2Ptr<CItemSocketData> Find(int nGrade);   // 0x14062c900 the row of a grade, else the grade 0 default row

    ATL::CAtlArray<MS2Ptr<CItemSocketData> > m_rows;   // +0x18
};
MS2_CHECK_SIZE(CItemSocketDataContainer, 0x38);
MS2_CHECK_OFFSET(CItemSocketDataContainer, m_rows, 0x18);

// RTTI CItemSocketTable, 0xa8 bytes: TSingleton at +0, the CCacheData at +8.
class CItemSocketTable : public TSingleton<CItemSocketTable>, public CCacheData
{
public:
    typedef MS2Ptr<CItemSocketDataContainer> ContainerPtr;
    typedef ATL::CAtlMap<unsigned, ContainerPtr> ContainerMap;

    CItemSocketTable();                     // 0x14062caa0
    virtual ~CItemSocketTable();            // 0x14062cb50

    int Load();                             // 0x14062cbc0 Table/itemSocket.xml
    MS2Ptr<CItemSocketData> Find(unsigned nItemId, int nGrade);     // 0x14062d330
    unsigned GetMaxSocketCount(int nSocketId, int nGrade, MS2Ptr<CItemData> spData);    // 0x14062d4b0 the most sockets an item can have
    unsigned GetInitialSocketCount(int nSocketId, int nGrade, MS2Ptr<CItemData> spData);    // 0x14062d6f0 the sockets it has from the start
    bool FUN_14062d890(int nArg1, int nArg2, int nArg3, MS2Ptr<CItem> spItem);     // 0x14062d890 always true (no caller)
    bool IsSocketFeatureEnabled(MS2Ptr<CItemData> spData);                   // 0x14062d8d0 sockets are enabled for the item's kind
    bool FUN_14062d980(MS2Ptr<CItemData> spData, int nGrade);       // 0x14062d980 the item cannot take more sockets
    int Reload();                    // 0x14062db50 reload the table

private:
    MS2_LAYOUT_FRIEND;
    CLockCriticalSection m_lock;            // +0x30
    ContainerMap m_items;                   // +0x60 item id -> its rows
};
MS2_CHECK_SIZE(CItemSocketTable, 0xa8);
MS2_CHECK_OFFSET(CItemSocketTable, m_lock, 0x30);
MS2_CHECK_OFFSET(CItemSocketTable, m_items, 0x60);

// The unlock record of the socket system (CItemSocketSystemUtil::EnableSocketUnlockFunction), 0x38 bytes.
namespace CItemSocketSystemUtil
{
struct EnableSocketUnlockFunction : public CPtred
{
public:
    EnableSocketUnlockFunction();           // 0x140626a20
    virtual ~EnableSocketUnlockFunction() = default;    // 0x14062c160 (implicit: the exe stores no vftable)

    bool Init(MS2Ptr<CItem> pItem, int nSocketMode, int nUnlockMode);   // 0x140626aa0 take the item's identity
    bool Matches(MS2Ptr<CItem> pItem);      // 0x140626bc0 the item is another one of the same kind and can be unlocked
    bool InitPair(MS2Ptr<CItem> pItem, MS2Ptr<CItem> pOther, int nSocketMode, int nUnlockMode);   // 0x140626e20

    int m_n18;                              // +0x18 the item data's kind (FUN_14053c560 of its data record)
    int m_n1C;                              // +0x1c the item id
    unsigned __int64 m_n20;                 // +0x20 the item uid
    int m_n28;                              // +0x28 the enhance record's level
    int m_nSocketMode;                      // +0x2c
    int m_nUnlockMode;                      // +0x30
};
MS2_CHECK_SIZE(EnableSocketUnlockFunction, 0x38);
}
