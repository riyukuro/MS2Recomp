// itemdefaultdata.h - CItemDefaultData (the default items of the character creation, Table/defaultItems.xml) and its
// row types DefaultItemData / CItemDefaultData::TDefaultItems (RTTI .?AUDefaultItemData@@,
// .?AUTDefaultItems@CItemDefaultData@@). Header name assumed (?\itemdefaultdata.cpp); member and method names are invented
// unless noted. Layouts from the ctors (0x140586e50, 0x140585730) and the operator new sizes (0x28, 0x1d0).
#pragma once

#include <afx.h>
#include <atlcoll.h>
#include <typeinfo>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/tptrvalue.h"

class TCreateCharInfo;
CString FUN_14016a5c0(const char* psz, int nCodePage);         // narrows a string (the RTTI name in CheckInit)

// The equipment slot of a default item (the "slot" attribute; the 18 slots 1..18 of the slot table 0x142d5f5f0). An enum:
// the maps take it by const reference and the log formats it as a custom argument. The name is the one unit_140583f00
// gave it (ms_aMaps' mangled name in symbols-manual.tsv); slot 8 is the one whose full-body items also fill slot 9.
enum Unk_ItemDefaultKind { kItemDefaultKind2 = 2, kItemDefaultKind8 = 8, kItemDefaultKind9 = 9 };

// One default item: the item id, its sale tag and whether the creation dialog preselects it.
struct DefaultItemData : public CPtred
{
    DefaultItemData(int nItemId, int nSaleTag) : m_nItemId(nItemId), m_nSaleTag(nSaleTag), m_bSelect(false) {}
    // ~DefaultItemData 0x140587170 (implicit), ??_G 0x1405877b0

    int m_nItemId;                                              // +0x18
    int m_nSaleTag;                                             // +0x1c
    bool m_bSelect;                                             // +0x20 "select"
};
MS2_CHECK_SIZE(DefaultItemData, 0x28);

typedef ATL::CAtlArray<MS2Ptr<DefaultItemData> > Unk_DefaultItemArray;

class CItemDefaultData
{
public:
    // The default items of one job code (0 = every job), per gender (0 male, 1 female).
    struct TDefaultItems : public CPtred
    {
        explicit TDefaultItems(int nJobCode);                   // 0x140585730
        // ~TDefaultItems 0x140587190 (implicit), ??_G 0x1405877f0

        void Clear();                                           // 0x140585820
        void Init();                                            // 0x1405858b0: an empty list per gender and slot
        void AddItem(int nGender, MS2Ptr<DefaultItemData> spItem);                              // 0x140585970
        void AddSlotItem(int nGender, Unk_ItemDefaultKind eSlot, MS2Ptr<DefaultItemData> spItem);   // 0x1405859f0
        void Add(int nGender, Unk_ItemDefaultKind eSlot, MS2Ptr<DefaultItemData> spItem);   // 0x140585c40 (gender 2 = both)
        int HasItem(int nGender, int nItemId);                  // 0x140585e30
        int GetItems(int nGender, Unk_DefaultItemArray& aItems);                                // 0x140585ed0
        int GetSlotItems(int nGender, Unk_ItemDefaultKind eSlot, Unk_DefaultItemArray& aItems); // 0x140585f90
        MS2Ptr<DefaultItemData> GetSelected(int nGender, Unk_ItemDefaultKind eSlot);           // 0x140586040

        int m_nJobCode;                                                                         // +0x18
        ATL::CAtlMap<Unk_ItemDefaultKind, MS2Ptr<DefaultItemData> > m_mapSelected[2];          // +0x20 per slot
        ATL::CAtlMap<Unk_ItemDefaultKind, TPtrValue<Unk_DefaultItemArray> > m_mapSlotItems[2]; // +0xb0 per slot
        ATL::CAtlMap<int, MS2Ptr<DefaultItemData> > m_mapItems[2];                              // +0x140 by item id
    };

    static void Load();                                                                         // 0x140583fa0
    static int IsDefaultItem(int nJobCode, int nGender, int nItemId);                           // 0x140584790
    static int GetItems(int nJobCode, int nGender, Unk_DefaultItemArray& aItems);               // 0x1405848d0
    static int GetSlotItems(int nJobCode, int nGender, Unk_ItemDefaultKind eSlot, Unk_DefaultItemArray& aItems);  // 0x1405849c0
    static void GetRandomItems(int nJobCode, int nGender, ATL::CAtlArray<unsigned>& aItemIds);  // 0x140584ad0
    static void GetCreateItems(TCreateCharInfo* pInfo, ATL::CAtlArray<unsigned>& aItemIds);     // 0x140584ff0

    static int FUN_140583f00(int nGender);                      // unit_140583f00
    static int FUN_140583f70(int nGender);                      // unit_140583f00: 1 for gender 0 or 1
    // 0x140587a50 (CValidData-style check: a message box until Load ran)
    static void CheckInit()
    {
        if (!s_bInit) {
            CString msg;
            msg.Format("%s is not initialized", (const char*)FUN_14016a5c0(typeid(CItemDefaultData).name(), 0));
            MessageBoxA(0, msg, "Error", 0);
        }
    }
    static void SetInit(bool bInit) { s_bInit = bInit; }        // 0x14058ba40

    static bool s_bInit;                                                                        // 0x143aaf9ac
    static ATL::CAtlMap<int, MS2Ptr<TDefaultItems> > ms_mapJobItems;                            // 0x143aaf9f0
    static ATL::CAtlMap<Unk_ItemDefaultKind, int> ms_aMaps[2];                                 // 0x143aafa40 slot -> base item id
};
MS2_CHECK_SIZE(CItemDefaultData::TDefaultItems, 0x1d0);
MS2_CHECK_OFFSET(CItemDefaultData::TDefaultItems, m_mapSelected, 0x20);
MS2_CHECK_OFFSET(CItemDefaultData::TDefaultItems, m_mapSlotItems, 0xb0);
MS2_CHECK_OFFSET(CItemDefaultData::TDefaultItems, m_mapItems, 0x140);
