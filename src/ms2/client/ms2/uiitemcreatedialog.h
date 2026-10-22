// uiitemcreatedialog.h - UIItemCreateDialog (RTTI .?AVUIItemCreateDialog@@, UI type 0x4e25, 0x1c8 bytes), ItemOptionDebug
// (RTTI .?AVItemOptionDebug@@, 0x50) and the item option simulator: the GM "create item" window of the KMS2_DEV client
// and the dump of the server's simulated option rolls. NOT an original header (unit ?\uiitemcreatedialog.cpp,
// .text$mn 0x1419b3c50-0x1419bc730). Every name except the RTTI class names is invented from use.
//
// UIItemCreateDialog lists every item of the item table (filtered by a group, the job / gender check boxes and a search
// text: words joined by '&' must all match, words joined by '|' any of them), and sends the create (0x15), compare
// (0x8f) and repeat (0x9a) item packets. Its context menu opens the drop info of a box item.
// The simulator (owned by CSceneStateGame, see scenestategame.cpp) collects the rolled CItemOption of the "repeat"
// answers per item id / rank and writes min / max / histogram tables to ../Debug/itemOptionRepeat.xml.
#pragma once

#include <afx.h>
#include <atlcoll.h>
#include <set>

#include "ms2/ms2layout.h"
#include "ms2/client/ms2/uidialog.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/tixmldocument.h"

class CItemData;
class CItemOption;
class CCCreateItemPacket;
class CCCompareItemPacket;
class Unk_IcButton;
class Unk_IcList;
class Unk_IcCombo;
class Unk_IcCheck;
class Unk_IcInput;
class TiXmlElement;

class UIItemCreateDialog : public UIDialog
{
public:
    UIItemCreateDialog();                                       // 0x1419b3c50
    // implicit virtual dtor: 0x1419ba080 (no vptr store; ??_G 0x1419ba2c0)
    virtual CString vfunc_1();                                  //  1 0x1419b3d10 "ItemCreateDialog"
    virtual int vfunc_13();                                     // 13 0x1419b3f60 Enter / Tab; Ctrl+C copies the item id
    virtual void OnLoadComplete();                              // 22 0x1419b3d60
    virtual void vfunc_26();                                    // 26 0x1419b3f10 drop the bound children
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
                                                                // 28 0x1419b4130 movie callbacks
    virtual int vfunc_48() { return 0x4e25; }                   // 48 0x1419baa80 UI type id
    virtual void vfunc_49(Scaleform::GFx::Value* pRetVal, ASData* pArgs);   // 49 0x1419b4a00 the item tooltip

    void FUN_1419b4c70();                                       // collect the items of the item table (once)
    void FUN_1419b4dd0(const Scaleform::GFx::FunctionHandler::Params& params);   // "m_clearInven" click
    void FUN_1419b4e30(const Scaleform::GFx::FunctionHandler::Params& params);   // context menu item click
    int FUN_1419b5080();                                        // the item id of the selected list row
    int FUN_1419b51a0();                                        // the selected rank
    unsigned FUN_1419b5280(int nItemId, unsigned nLevel);       // the enchant level clamp of an item
    void SendRequestItemCreate(CCCreateItemPacket& packet);             // send "create item" (0x15)
    void FUN_1419b53d0(CCCompareItemPacket& packet);            // send "compare item" (0x8f)
    void FUN_1419b54a0(CCCompareItemPacket& packet);            // send "repeat item" (0x9a)
    void FUN_1419b5560(int nItemId, int nRank);                 // the picked item changed
    void FUN_1419b5730(const CString& strGroup, const CStringW& strSearch);   // fill the item list
    void FUN_1419b6350();                                       // build the context menu
    void FUN_1419b6790();                                       // fill the function list
    MS2Ptr<Unk_IcButton> FUN_140bb4b10(const CString& strName); // child "m_clearInven" (UISwfEntity::GetChild<button>)
    MS2Ptr<Unk_IcList> FUN_140c02900(const CString& strName);   // child "m_items" / "m_contextMenu" / "m_function"
    MS2Ptr<Unk_IcCombo> FUN_140c28560(const CString& strName);  // child "m_itemGrade"
    MS2Ptr<Unk_IcInput> FUN_140e35bd0(const CString& strName);  // child "m_periodInput"
    MS2Ptr<Unk_IcCheck> FUN_140e52670(const CString& strName);  // child "m_checkJob" / "m_checkGender"

protected:
    MS2_LAYOUT_FRIEND;
    ATL::CAtlArray<MS2Ptr<CItemData> > m_items;                 // +0x178 the item rows of the list
    MS2Ptr<Unk_IcButton> m_spClearInven;                        // +0x198
    MS2Ptr<Unk_IcList> m_spContextMenu;                         // +0x1a8
    std::set<CStringW> m_functions;                             // +0x1b8 the item function names
};
MS2_CHECK_SIZE(UIItemCreateDialog, 0x1c8);
MS2_CHECK_OFFSET(UIItemCreateDialog, m_items, 0x178);
MS2_CHECK_OFFSET(UIItemCreateDialog, m_spContextMenu, 0x1a8);
MS2_CHECK_OFFSET(UIItemCreateDialog, m_functions, 0x1b8);

// The rolled options of one simulated item id / rank. Groups (nGroup) are the option blocks of CItemOption (0 constant,
// 1 static, 2 random); nStat is a stat type (0..0x22) or a special ability (1..0xce).
typedef ATL::CRBMap<float, int> Unk_IcRateCounts;               // rolled rate -> count
typedef ATL::CRBMap<__int64, int> Unk_IcValueCounts;            // rolled value -> count

class ItemOptionDebug : public CPtred
{
public:
    ItemOptionDebug();                                          // 0x1419b68e0 (implicit dtor 0x1419ba050, ??_G 0x1419ba280)
    float FUN_1419b6940(int nGroup, int nStat);                 // smallest stat rate
    float FUN_1419b6a90(int nGroup, int nStat);                 // largest stat rate
    void FUN_1419b6be0(int nGroup, int nStat, Unk_IcRateCounts& counts);
    __int64 FUN_1419b6d40(int nGroup, int nStat);               // smallest stat value
    __int64 FUN_1419b6e80(int nGroup, int nStat);               // largest stat value
    void FUN_1419b6fc0(int nGroup, int nStat, Unk_IcValueCounts& counts);
    float FUN_1419b7120(int nGroup, unsigned nSpecial);         // smallest special rate
    float FUN_1419b7270(int nGroup, unsigned nSpecial);         // largest special rate
    void FUN_1419b73c0(int nGroup, unsigned nSpecial, Unk_IcRateCounts& counts);
    float FUN_1419b7520(int nGroup, unsigned nSpecial);         // smallest special value
    float FUN_1419b7670(int nGroup, unsigned nSpecial);         // largest special value
    void FUN_1419b77c0(int nGroup, unsigned nSpecial, Unk_IcRateCounts& counts);
    int FUN_1419b7920(int nGroup, int nStat);                   // a stat rate was rolled
    int FUN_1419b79a0(int nGroup, int nStat);                   // a stat value was rolled
    int FUN_1419b7a10(int nGroup, unsigned nSpecial);           // a special rate was rolled
    int FUN_1419b7a90(int nGroup, unsigned nSpecial);           // a special value was rolled
    TiXmlElement* FUN_1419b7b10(int nGroup, int nStat);     // <rate name min max><output option count/>..
    TiXmlElement* FUN_1419b7e00(int nGroup, int nStat);     // <value ...>
    TiXmlElement* FUN_1419b80e0(int nGroup, unsigned nSpecial);
    TiXmlElement* FUN_1419b83d0(int nGroup, unsigned nSpecial);

    int m_nItemId;                                              // +0x18
    int m_nRank;                                                // +0x1c
    ATL::CAtlList<MS2Ptr<CItemOption> > m_options;              // +0x20
};
MS2_CHECK_SIZE(ItemOptionDebug, 0x50);

class Unk_ItemOptionSimulator
{
public:
    Unk_ItemOptionSimulator();                                  // 0x1419b86c0
    void FUN_1419b8730();                                       // start ("Item Simulate Start")
    void FUN_1419b8810();                                       // finish (save the document)
    void FUN_1419b9030(int nItemId, int nRank, MS2Ptr<CItemOption> spOption);   // add one rolled option
    MS2Ptr<ItemOptionDebug> FUN_1419b91f0(int nItemId, int nRank);

    CString m_strFile;                                          // +0x00
    TiXmlDocument m_doc;                                        // +0x08
    ATL::CRBMultiMap<unsigned, MS2Ptr<ItemOptionDebug> > m_mapItems;   // +0x78 (item id -> rolls per rank)
};
MS2_CHECK_OFFSET(Unk_ItemOptionSimulator, m_mapItems, 0x78);
MS2_CHECK_SIZE(Unk_ItemOptionSimulator, 0xa8);
