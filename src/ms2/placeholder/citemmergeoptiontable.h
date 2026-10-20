// citemmergeoptiontable.h - CItemMergeOptionTable (RTTI .?AVCItemMergeOptionTable@@, 0x20 bytes), the item merge option
// tables of Table/itemMergeOptionBase.xml (owner: commonfiles\itemmergeoptiontable.cpp). NOT an original header.
// Bases: TSingleton<CItemMergeOptionTable> at +0x0, CValidData<CItemMergeOptionTable> at +0x8. A TSingleton that
// CGameApp::InitInstance (?\ms2.cpp) creates; the xml is loaded by FUN_1405bfc70.
#pragma once

#include <map>

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/cvaliddata.h"
#include "ms2/placeholder/citemmergeoptionproxy.h"
#include "ms2/commonfiles/itemenchantinfo.h"

class CItemData;
class CItem;

class CItemMergeOptionTable : public TSingleton<CItemMergeOptionTable>,
                              public CValidData<CItemMergeOptionTable>
{
public:
    typedef MS2Ptr<CItemMergeOptionData> DataPtr;

    CItemMergeOptionTable();                                // 0x1405bfba0
    virtual ~CItemMergeOptionTable();                       // 0x1405bfc10

    void FUN_1405bfc70();                                   // loads the xml
    DataPtr FUN_1405c00e0(int nItemId, int nMaterialId);   // the slot data of a merge pair, null when it cannot merge
    bool FUN_1405c03d0(int nCategory, int* pNormal);          // the first normal option of an item's slot
    bool FUN_1405c04f0(int nCategory, int* pSpecial);         // the first special option of an item's slot
    CItemMergeOptionVariation* FUN_1405c0610(int nItemId, int nNormal);   // the whole-range variation of a normal option (null: none)
    CItemMergeOptionVariation* FUN_1405c0740(int nItemId, int nSpecial);  // the whole-range variation of a special option (null: none)
    bool FUN_1405c0870(int nItemId, int nMaterialId, bool bSpecial, int nOption, Unk_EnchantPtr<BaseOption> spValue);
    bool FUN_1405c0a70(int nItemId, int nMaterialId, bool bSpecial, int nOption, Unk_EnchantPtr<BaseOption> spValue);
    bool FUN_1405c0c70(int nItemId, int nMaterialId, bool bSpecial, int nOption, Unk_EnchantPtr<BaseOption> spValue);
    bool FUN_1405c0e80(int nItemId, int nMaterialId, bool bSpecial, int nOption, Unk_EnchantPtr<BaseOption> spValue);
    CStringW FUN_1405c1090(MS2Ptr<CItem> spItem, int nFlag);    // the description of an item's merge options
    DataPtr FUN_1405c1d20(int nItemId, int nMaterialId);
    DataPtr FUN_1405c1f40(int nCategory);

    static bool s_bInit;                                    // the "initialized" flag of CValidData
    static void CheckInit();                                // 0x1405c53b0
    static void SetInit(bool b);                            // 0x1405c79d0

private:
    MS2_LAYOUT_FRIEND;
    std::map<std::pair<int, int>, DataPtr> m_data;          // +0x10 (item category, part) -> slot data
};
MS2_CHECK_SIZE(CItemMergeOptionTable, 0x20);
