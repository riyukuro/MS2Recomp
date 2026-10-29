// itemexchangescrolltable.h - CExchangeItemInfo / CItemExchangeScrollTable (RTTI names): the item exchange scroll table
// read from Table/ItemExchangeScrollTable.xml (<exchange id type maxGrade tradableCountDeduction><receipe/><exchange/>
// <requireEquip/><require meso><item id/></require></exchange>). Header name assumed. Member names are invented from use.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/commonfiles/commonstruct_wa.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/cvaliddata.h"

// The xml "type" attribute is given by name (FUN_14021a270 is its string converter).
enum ExchangeItemType
{
    EXCHANGE_ITEM_TYPE_0 = 0,
};

// An item reference of a recipe: id, rank, count (12 bytes).
struct Unk_ExchangeItemRef
{
    Unk_ExchangeItemRef();                  // 0x140595b80
    unsigned int m_nId;                     // "id"
    int m_nRank;                            // "rank"
    int m_nCount;                           // "count"
};
MS2_CHECK_SIZE(Unk_ExchangeItemRef, 12);

// One <exchange> row. RTTI CExchangeItemInfo, 0x90 bytes, base CPtred; vftable slot 0 the deleting destructor.
class CExchangeItemInfo : public CPtred
{
public:
    CExchangeItemInfo();                    // 0x140595ac0
    // ~CExchangeItemInfo() is implicit: the exe dtor 0x140595cd0 stores no vptr.

    __int64 GetMeso() const;                // 0x140595050 the meso price, reduced by the discount rate of the item's grade
    __int64 GetTotalMeso(int nCount) const; // 0x1405950b0

    int m_nId;                              // +0x18 "id"
    ExchangeItemType m_eType;               // +0x1c "type"
    int m_nMaxGrade;                        // +0x20 "maxGrade"
    __int64 m_nMeso;                        // +0x28 <require meso>
    Unk_ExchangeItemRef m_receipe;          // +0x30 <receipe>
    Unk_ExchangeItemRef m_exchange;         // +0x3c <exchange>
    Unk_ExchangeItemRef m_requireEquip;     // +0x48 <requireEquip>
    CIngredientContainer m_require;         // +0x58 <require><item id/>...
    int m_nTradableCountDeduction;          // +0x88 "tradableCountDeduction"
};
MS2_CHECK_SIZE(CExchangeItemInfo, 0x90);
MS2_CHECK_OFFSET(CExchangeItemInfo, m_nMeso, 0x28);
MS2_CHECK_OFFSET(CExchangeItemInfo, m_receipe, 0x30);
MS2_CHECK_OFFSET(CExchangeItemInfo, m_require, 0x58);
MS2_CHECK_OFFSET(CExchangeItemInfo, m_nTradableCountDeduction, 0x88);

typedef MS2Ptr<CExchangeItemInfo> CExchangeItemInfoPtr;

// The table. RTTI CItemExchangeScrollTable, 0x58 bytes: TSingleton +0, CValidData +8, the id -> row map +0x10.
// Created by CGameApp::InitInstance (?\ms2.cpp).
class CItemExchangeScrollTable : public TSingleton<CItemExchangeScrollTable>,
                                 public CValidData<CItemExchangeScrollTable>
{
public:
    CItemExchangeScrollTable();             // 0x1405950f0
    virtual ~CItemExchangeScrollTable();    // 0x140595190

    void Load();                            // 0x1405951f0 parses the xml into the map
    CExchangeItemInfoPtr GetData(unsigned int nId);     // 0x140595750 the row for an id (null when missing)

    static void CheckInit();                // 0x140595ee0
    static void SetInit(bool b);            // 0x140596db0

    static bool s_bInit;                    // DAT_143aafba0

private:
    MS2_LAYOUT_FRIEND;
    ATL::CAtlMap<unsigned int, CExchangeItemInfoPtr> m_map;     // +0x10 id -> row
};
MS2_CHECK_SIZE(CItemExchangeScrollTable, 0x58);
MS2_CHECK_OFFSET(CItemExchangeScrollTable, m_map, 0x10);
