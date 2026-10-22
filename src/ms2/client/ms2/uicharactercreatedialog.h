// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: client\ms2\uicharactercreatedialog.h (name assumed:
// the class name; it shares the unit ?\uicameraeditdialog.cpp).
//
// UICharacterCreateDialog is the character creation page of the lobby (UI id 0x4e26): gender, hair / face / makeup /
// skin / cap pickers that preview on the lobby actor through the item customize controller (Customize, from
// uibeautyshopstyledialog.h), a name input box, and the CreateCharacter request (opcode 9). RTTI
// .?AVUICharacterCreateDialog@@, 0x278 bytes, vftables at +0 / +0x18 (IMessageListener) / +0x178 (UIItemEventListener)
// / +0x180 (IItemCustomizeEventListener). Names: virtuals are Ghidra's vfunc_<slot>; members are invented from use.
#pragma once

#include <afx.h>
#include <atlcoll.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/uiitemeventlistener.h"
#include "ms2/client/ms2/uibeautyshopstyledialog.h"     // IItemCustomizeEventListener, Customize
#include "ms2/client/ms2/scenestatemulti.h"
#include "ms2/client/ms2/uicameraeditdialog.h"
#include "ms2/client/ms2/uidialog.h"
#include "ms2/commonfiles/itemdefaultdata.h"         // DefaultItemData (the rows of the item list)

class CInPacket;
class CMsgBoxData;
class CEquipItem;
class CSceneStateMulti;

// The items the lobby actor wears (item id -> the item), a CAtlMap<int, MS2Ptr<CItem> > at +0x1d8 (0x48 bytes).
typedef ATL::CAtlMap<int, MS2Ptr<CItem> > Unk_CcItemMap;

class UICharacterCreateDialog : public UIDialog, public UIItemEventListener, public IItemCustomizeEventListener
{
public:
    UICharacterCreateDialog();                                  // 0x1418e20a0
    virtual ~UICharacterCreateDialog();                         //  0 0x1418e22b0 (??_G 0x1418e80d0)
    virtual CString vfunc_1();                                  //  1 0x1418e23e0 "CharacterCreateDialog"
    virtual void vfunc_12();                                    // 12 0x1418e3160 reload the customize controller
    virtual int vfunc_13();                                     // 13 0x1418e3050 enter key
    virtual void vfunc_15();                                    // 15 0x1418e2e90 per-frame
    virtual void OnLoadComplete();                              // 22 0x1418e2430
    virtual void vfunc_26();                                    // 26 0x1418e3120
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
                                                                // 28 0x1418e2770
    virtual int vfunc_48();                                     // 48 0x1418e8430 0x4e26
    virtual void vfunc_67();                                    // 67 0x1418e37d0 Close
    virtual void vfunc_79(void* p);                             // 79 0x1418e2f90 server packets
    virtual void vfunc_84();                                    // 84 (new) 0x1418e7830 rebuild the item list
    virtual void vfunc_85();                                    // 85 (new) 0x1418e78b0 refresh the preview

    // UIItemEventListener override
    virtual void vfunc_26(int nItemId);                         // 0x1418e3280 (o178 slot 26)
    // IItemCustomizeEventListener overrides
    virtual int vfunc_1(void* p);                               // 0x1418e33e0
    virtual int vfunc_2(void* p, float fValue, int nIndex);     // 0x1418e34c0
    virtual int vfunc_3(void* p, float fValue);                 // 0x1418e36b0

    void FUN_1418e3910();                                       // popdown
    void FUN_1418e3980(CInPacket* pPacket);                     // the CreateCharacter answer
    int FUN_1418e3f50(const CStringW& strName);                 // send the create request
    void FUN_1418e4250(CItemData* pData, int* pnCategory, int* pnTab);
    int FUN_1418e4380(int nTab, int nCategory, MS2Ptr<CItemData> spData);
    bool FUN_1418e4600(int nTab, int nCategory, int nItemId);
    int FUN_1418e46c0(int nTab);                                // tab -> equip slot kind
    void FUN_1418e4750();                                       // reset the loaded flags and the item map
    void FUN_1418e47e0(int nTab, int nCategory);                // collect the list rows
    void FUN_1418e4a80(int nTab, int nCategory);                // buildItems
    void FUN_1418e4f50();                                       // buildCurrentItems
    void FUN_1418e5580(MS2Ptr<CItemData> spData);               // buildColors
    void FUN_1418e5a10(MS2Ptr<CItemData> spData);               // buildCustom
    void OnSceneLobbySelect();                                       // OnSceneLobbySelect
    void OnCreate();                                       // OnCreate: ask for the name
    bool FUN_1418e6430(const CStringW& strName);                // validate the name and create
    void FUN_1418e6680(int nRandom);                            // OnRandom
    void FUN_1418e6730(int nGender);                            // OnChangeGender
    int FUN_1418e6950(int nItemId, int nTab, int nCategory);
    int FUN_1418e6ab0(int nTab, int nCategory);                 // the category is loaded
    void FUN_1418e6b10();                                       // empty
    void FUN_1418e6b20(int nTab);                               // OnChangeTab
    void FUN_1418e6bf0(int nTab, int nCategory);                // OnChangeCategory
    void FUN_1418e6d80(int nItemId);                            // OnChangeItem
    void FUN_1418e6fc0(int nColor);                             // OnChangeColor
    void FUN_1418e7040(int nPos);                               // OnChangePosition
    void FUN_1418e7110(int nIndex, float fSize);                // OnChangeSize
    void FUN_1418e7260(float fDegree);                          // OnChangeDegree
    void FUN_1418e7340();                                       // vfunc_55 through the vftable (result dropped)
    void FUN_1418e7380(int nItemId);                            // remember the worn item
    void FUN_1418e74c0(MS2Ptr<CItemData> spData);               // updateCurrentItem
    bool FUN_1418e7790(int nResult, const CMsgBoxData& data);   // the name input answer

    MS2_LAYOUT_FRIEND;
    ATL::CAtlArray<int> m_aLoaded;                              // +0x198 per tab: the list is built (7 tabs)
    ATL::CAtlArray<MS2Ptr<DefaultItemData> > m_aRows;           // +0x1b8 the rows of the shown list
    Unk_CcItemMap m_items;                                      // +0x1d8 item id -> the lobby actor's item
    MS2Ptr<Customize> m_spCustomize;                            // +0x220
    int m_nCurItemId;                                           // +0x230
    int m_nTab;                                                 // +0x234 -1
    int m_nCategory;                                            // +0x238 -1
    int m_bCurrentBuilt;                                        // +0x23c
    int m_bTabChanged;                                          // +0x240
    int m_bGuideOpened;                                         // +0x244
    UICameraEditDialog* m_pCamera;                              // +0x248 the camera overlay (UI 0x4ef2)
    MS2Ptr<CSceneStateMulti::BackUpCharacterInfo> m_spBackUp;   // +0x250
    double m_dOpenTime;                                         // +0x260 the clock at OnLoadComplete
    double m_dElapsed;                                          // +0x268
    unsigned m_nChangedMask;                                    // +0x270 genders already changed (bit per gender)
    int m_nState;                                               // +0x274 0 closed, 1 input, 3 creating, 4 popdown
};
MS2_CHECK_SIZE(UICharacterCreateDialog, 0x278);
