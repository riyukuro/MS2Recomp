// banktable.h - CBankTable / CBankData / CBankItemDefine (RTTI names): the storage ("bank") tables read from
// Table/itemDefine.xml (which item belongs to which bank slot type) and Table/bankType.xml (per bank: id, slot count,
// cash use, storable slot types). Header name assumed; member and helper names are invented from use.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/cvaliddata.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/commonfiles/os.h"

class TiXmlElement;    // xml element (declared where the loader is)

// One <key> row of itemDefine.xml, 0x28 bytes; vftable has the deleting dtor only.
class CBankItemDefine : public CPtred
{
public:
    CBankItemDefine();                  // 0x1401b3c70
    virtual ~CBankItemDefine();         // 0x1401b3ce0

    int m_nId;                          // +0x18 "id" (the bank id)
    int m_nSlot;                        // +0x1c "slot" (enum parsed from its name)
    int m_nType;                        // +0x20 "type"
    int m_nSubType;                     // +0x24 "subType"
};
MS2_CHECK_SIZE(CBankItemDefine, 0x28);
MS2_CHECK_OFFSET(CBankItemDefine, m_nSubType, 0x24);

// One <bankType> row of bankType.xml, 0x48 bytes.
class CBankData : public CPtred
{
public:
    CBankData();                        // 0x1401b3d10
    virtual ~CBankData();               // 0x1401b3df0

    void SetSlots(CStringA strList);    // 0x1401b3e30 marks the comma separated bank ids as allowed
    int IsStorable(int nItemId);        // 0x1401b3f40

    int m_nId;                          // +0x18 "id"
    int m_nSlotCount;                   // +0x1c "slotCount"
    int m_nUseCash;                     // +0x20 "useCash"
    ATL::CAtlArray<int> m_slots;        // +0x28 allowed flag per bank id (0 .. max id)
};
MS2_CHECK_SIZE(CBankData, 0x48);
MS2_CHECK_OFFSET(CBankData, m_slots, 0x28);

class Unk_BankItem;
int ReadSlotAttr(TiXmlElement* pElem, const char* pszName, int* pnOut);

// RTTI CBankTable, 0xa8 bytes: TSingleton at +0, CValidData at +8.
class CBankTable : public TSingleton<CBankTable>, public CValidData<CBankTable>
{
public:
    typedef MS2Ptr<CBankData> DataPtr;
    typedef MS2Ptr<CBankItemDefine> DefinePtr;
    typedef ATL::CRBMap<unsigned, DataPtr> DataMap;
    typedef ATL::CAtlList<DefinePtr> DefineList;

    CBankTable();                       // 0x1401b3fb0
    virtual ~CBankTable();              // 0x1401b4060

    int Load();                        // 0x1401b4110 both files, stops at the first failure
    DataPtr GetBankData(unsigned nId);  // 0x1401b4160
    int GetMaxId();                     // 0x1401b4220
    int FindBankId(int nItemId);        // 0x1401b4240 bank id an item belongs to (-1 when none)
    int LoadItemDefine();              // 0x1401b4460 itemDefine.xml
    int LoadBankType();                // 0x1401b47a0 bankType.xml

    static void CheckInit();            // 0x1401b5570
    static void SetInit(bool b);        // 0x1401b6910

    static bool s_bInit;                // 0x143aac2b8

private:
    MS2_LAYOUT_FRIEND;
    CLockCriticalSection m_lock;        // +0x10
    DataMap m_banks;                    // +0x40
    DefineList m_defines;               // +0x70
    int m_nMaxId;                       // +0xa0 largest itemDefine id
};
MS2_CHECK_SIZE(CBankTable, 0xa8);
MS2_CHECK_OFFSET(CBankTable, m_lock, 0x10);
MS2_CHECK_OFFSET(CBankTable, m_banks, 0x40);
MS2_CHECK_OFFSET(CBankTable, m_defines, 0x70);
MS2_CHECK_OFFSET(CBankTable, m_nMaxId, 0xa0);
