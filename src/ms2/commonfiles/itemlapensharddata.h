// itemlapensharddata.h - CItemLapenshardData / CItemLapenshardTable (RTTI names): the rows of Table/itemLapenshardUpgrade.xml
// (a lapenshard item, its group and level, the item it upgrades to, the ingredients and the equip parts it fits) and the
// singleton that loads and queries them, plus the packet bodies of the lapenshard messages that sit in the same TU.
// Header name assumed from the unit path; member and helper names are invented from the xml attributes and use.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ccachedata.h"
#include "ms2/placeholder/cvaliddata.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/placeholder/ms2svrptr.h"
#include "ms2/placeholder/tptrvalue.h"
#include "ms2/commonfiles/os.h"
#include "ms2/commonfiles/commonstruct_wa.h"

class COutputStream;
class CInPacket;

// One row, 0x48 bytes (CPtred base, the ingredient container pointer is at +0x38).
class CItemLapenshardData : public CPtred
{
public:
    CItemLapenshardData();                  // 0x1405b4080
    virtual ~CItemLapenshardData();         // 0x1405b4170
    MS2SvrPtr<CIngredientContainer> GetIngredients(int nScale);   // 0x1405b41b0 the ingredients, money scaled by nScale

    int m_nGroup;                           // +0x18 "LapenGroupID"
    unsigned short m_nLevel;                // +0x1c "LapenLevel"
    int m_nNext;                            // +0x20 "NextItemID": the item this one upgrades to (0 = none)
    unsigned m_nMask;                       // +0x24 "EquipPart" bit mask (default 7)
    int m_nMinCount;                        // +0x28 "GroupLapenshardMinCount"
    __int64 m_nMeso;                        // +0x30 "meso"
    MS2SvrPtr<CIngredientContainer> m_spIngredients;    // +0x38 "IngredientItemID1..4" / "IngredientCount1..4"
};
MS2_CHECK_SIZE(CItemLapenshardData, 0x48);
MS2_CHECK_OFFSET(CItemLapenshardData, m_nGroup, 0x18);
MS2_CHECK_OFFSET(CItemLapenshardData, m_nLevel, 0x1c);
MS2_CHECK_OFFSET(CItemLapenshardData, m_nNext, 0x20);
MS2_CHECK_OFFSET(CItemLapenshardData, m_nMask, 0x24);
MS2_CHECK_OFFSET(CItemLapenshardData, m_nMinCount, 0x28);
MS2_CHECK_OFFSET(CItemLapenshardData, m_nMeso, 0x30);
MS2_CHECK_OFFSET(CItemLapenshardData, m_spIngredients, 0x38);

// Bases (RTTI): TSingleton at +0, CCacheData at +0x8, CValidData at +0x30; 0x1b8 bytes.
class CItemLapenshardTable : public TSingleton<CItemLapenshardTable>, public CCacheData,
                             public CValidData<CItemLapenshardTable>
{
public:
    // The six lapenshard equip slots and the three colours (kind masks) they belong to (InitEquipParts 0x1405b4740).
    enum Slot { Red1 = 1, Red2, Blue1, Blue2, Green1, Green2 };
    enum Kind { Red = 1, Blue = 2, Green = 4 };
    typedef MS2Ptr<CItemLapenshardData> DataPtr;
    typedef ATL::CAtlMap<int, DataPtr> DataMap;
    typedef ATL::CAtlMap<unsigned short, unsigned> LevelMap;

    CItemLapenshardTable();                                     // 0x1405b44b0
    virtual ~CItemLapenshardTable();                            // 0x1405b4660 (??_G 0x1405b7250)

    void InitEquipParts();                                      // 0x1405b4740
    void AddEquipPart(Kind part, Slot index);                   // 0x1405b47e0
    int Load();                                                 // 0x1405b4880 itemLapenshardUpgrade.xml
    int Reload();                                               // 0x1405b5610 clears the rows and loads again
    DataPtr Get(int nItemId);                                   // 0x1405b56a0 find a row (an empty pointer for none)
    unsigned short GetLevel(int nItemId);                       // 0x1405b5780
    Kind GetEquipPart(Slot index);                              // 0x1405b5810
    unsigned GetEquipMask(int nItemId);                         // 0x1405b5890
    void GetEquipParts(Kind part, ATL::CAtlArray<Slot>& slots); // 0x1405b5910
    int GetGroup(int nItemId);                                  // 0x1405b59d0
    int HasUpgrade(int nItemId);                               // 0x1405b5a50
    unsigned GetFirstItem(int nGroup);                          // 0x1405b5af0
    unsigned GetItem(int nGroup, unsigned short nLevel);        // 0x1405b5ba0
    static void CheckInit();                                    // 0x1405b7430
    static void SetInit(bool b);                                // 0x1405bccd0

    static bool s_bInit;                                        // 0x143aafda0
private:
    MS2_LAYOUT_FRIEND;
    CLockCriticalSection m_lock;                                // +0x38
    DataMap m_rows;                                             // +0x68 item id -> row
    ATL::CAtlMap<Slot, Kind> m_slotKinds;                       // +0xb0 equip slot -> colour
    ATL::CRBMultiMap<Kind, Slot> m_kindSlots;                   // +0xf8 colour -> equip slots
    ATL::CAtlMap<unsigned, unsigned> m_firstItems;              // +0x128 group -> first (level 1) item
    ATL::CAtlMap<unsigned, TPtrValue<LevelMap> > m_groups;      // +0x170 group -> (level -> item)
};
MS2_CHECK_SIZE(CItemLapenshardTable, 0x1b8);
MS2_CHECK_OFFSET(CItemLapenshardTable, m_lock, 0x38);
MS2_CHECK_OFFSET(CItemLapenshardTable, m_rows, 0x68);
MS2_CHECK_OFFSET(CItemLapenshardTable, m_slotKinds, 0xb0);
MS2_CHECK_OFFSET(CItemLapenshardTable, m_kindSlots, 0xf8);
MS2_CHECK_OFFSET(CItemLapenshardTable, m_firstItems, 0x128);
MS2_CHECK_OFFSET(CItemLapenshardTable, m_groups, 0x170);

// Prefixes of the lapenshard messages (names invented from the packet roles; each pair is Write / Read).
struct Unk_LapenEquip                   // slot + item uid
{
    int m_nSlot; __int64 m_nUid;
    void Write(COutputStream* s) const; // 0x1405b5cc0
    void Read(CInPacket& p);            // 0x1405b5d10
};
struct Unk_LapenEquipped                // slot + item id at +0x10
{
    int m_nSlot; char m_pad_04[0xc]; int m_nItem;
    void Write(COutputStream* s) const; // 0x1405b5d80
    void Read(CInPacket& p);            // 0x1405b5dd0
};
struct Unk_LapenUnequip                 // slot
{
    int m_nSlot;
    void Write(COutputStream* s) const; // 0x1405b5e40
    void Read(CInPacket& p);            // 0x1405b5e70
};
struct Unk_LapenItem                    // uid + item id + slot
{
    __int64 m_nUid; int m_nItem; int m_nSlot;
    void Write(COutputStream* s) const; // 0x1405b5ec0
    void Read(CInPacket& p);            // 0x1405b5f30
};
struct Unk_LapenUpgrade : Unk_LapenItem // + fodder map (uid -> amount) at +0x10 and a trailing value at +0x5c
{
    ATL::CAtlMap<unsigned __int64, unsigned> m_fodder; char m_pad_58[4]; unsigned m_nTail;
    void Write(COutputStream* s) const; // 0x1405b5fd0
    void Read(CInPacket& p);            // 0x1405b60e0
};
struct Unk_LapenUpgradeResult : Unk_LapenItem   // + success flag at +0x58
{
    char m_pad_10[0x48]; bool m_bSuccess;
    void Write(COutputStream* s) const; // 0x1405b61e0
    void Read(CInPacket& p);            // 0x1405b6220
};
struct Unk_LapenAddFodder : Unk_LapenItem       // + amount at +0x14
{
    char m_pad_10[4]; int m_nAmount;
    void Write(COutputStream* s) const; // 0x1405b6280
    void Read(CInPacket& p);            // 0x1405b62c0
};
struct Unk_LapenPreview                 // rate at +0x10
{
    char m_pad_00[0x10]; int m_nRate;
    void Write(COutputStream* s) const; // 0x1405b6320
    void Read(CInPacket& p);            // 0x1405b6360
};
