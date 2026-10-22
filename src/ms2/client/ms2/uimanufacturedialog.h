// uimanufacturedialog.h - UIManufactureDialog (RTTI .?AVUIManufactureDialog@@, 0x220 bytes: UIDialog + the UIDialogEventListener
// at +0x178), the maid manufacture window ("ManufactureDialog", UI type 0x4ec0): the recipe list of the maid npc, the selected
// recipe with its ingredients and the progress of the running craft. Opened by CManufactureManager (manufacturemanager.cpp),
// which feeds the server results back through FUN_1412e6110 / FUN_1412e6850 / FUN_1412e6af0 / FUN_1412e6c30. Recovered from
// MapleStory2.exe KMS2_DEV x64 (2022-04-13); the unit is `?\uimanufacturedialog.cpp` (dir client\ms2). Header/unit name assumed.
// Member names are invented from use.
//
// Overridden slots: 1 (movie name), 13 (Tab key), 20 (OnLoadInit), 22 (OnLoadComplete), 28 (AS -> C++ commands), 43 (place the
// window next to the home panel), 48 (UI type), 67 (close), 72 (per frame: the progress gauge), IMessageListener 0 (the message
// box answer), UIDialogEventListener 0 (dtor thunk).
#pragma once

#include <afx.h>
#include <atlcoll.h>

#include "ms2/ms2layout.h"
#include "ms2/client/ms2/uidialog.h"
#include "ms2/placeholder/uidialogeventlistener.h"

class Unk_UmRecipeRow;

class UIManufactureDialog : public UIDialog, public UIDialogEventListener
{
public:
    UIManufactureDialog();                                                  // 0x1412e24f0
    virtual ~UIManufactureDialog();                                         //  0 0x1412e2660 (??_G 0x1412e8340)
    virtual CString vfunc_1();                                              //  1 0x1412e2730 "ManufactureDialog"
    virtual int vfunc_13();                                                 // 13 0x1412e2cf0
    virtual void OnLoadInit();                                              // 20 0x1412e28f0
    virtual void OnLoadComplete();                                          // 22 0x1412e2fc0
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x1412e2930
    virtual void vfunc_43();                                                // 43 0x1412e2d30
    virtual int vfunc_48() { return 0x4ec0; }                               // 48 0x1412e8380
    virtual void vfunc_67();                                                // 67 0x1412e2780
    virtual void vfunc_72();                                                // 72 0x1412e3010
    virtual int OnMessage(UISwfEntity* pSender, UIMsg* pMsg);               // IMessageListener 0 0x1412e2e70

    void FUN_1412e3480(int nNpcId, unsigned __int64 nManufactureId);        // 0x1412e3480 show another maid
    void FUN_1412e34c0();                                                   // 0x1412e34c0 "setTitle"
    void FUN_1412e3990(int bSelect);                                        // 0x1412e3990 fill the recipe list
    void FUN_1412e4240();                                                   // 0x1412e4240 "bindProgress" and the gauge
    void FUN_1412e48a0();                                                   // 0x1412e48a0 "selectItem": the selected recipe
    void FUN_1412e5c90();                                                   // 0x1412e5c90 a row was selected
    void FUN_1412e5dd0(int nRow);                                           // 0x1412e5dd0 craft the recipe of a row
    void FUN_1412e5f70(int nRow);                                           // 0x1412e5f70 craft the recipe of a row (admin)
    void FUN_1412e6110(int nResult);                                        // 0x1412e6110 result of the craft request
    void OnRecieve();                                                   // 0x1412e6250 receive the product
    void OnRecieveByMerat();                                                   // 0x1412e63b0 receive the product with merat
    void OnRecieveJackpot();                                                   // 0x1412e66f0 receive the jackpot
    void FUN_1412e6850(int nResult);                                        // 0x1412e6850 result of the receive request
    void FUN_1412e69a0();                                                   // 0x1412e69a0 cancel the craft
    void FUN_1412e6af0(int nResult);                                        // 0x1412e6af0 result of the cancel request
    void FUN_1412e6c30(int nItemId, int nRarity, int nAmount, int nExp, int nBonus, int nJackpot, int nMerat);   // 0x1412e6c30 the reward page
    int FUN_1412e7170(int nResult);                                         // 0x1412e7170 the result is 2 or 3
    template <class T> MS2Ptr<T> FUN_140c02900(const CString& strName);     // bind a list child

private:
    MS2_LAYOUT_FRIEND;
    int m_nNpcId;                                                           // +0x180 the maid npc's object id
    unsigned __int64 m_nManufactureId;                                      // +0x188 the manufacture record's key
    int m_nSelected;                                                        // +0x190 the selected row
    int m_194;                                                              // +0x194 (cleared when the movie is loaded)
    ATL::CAtlArray<CString> m_aRowKeys;                                     // +0x198 the item bag keys of the list rows
    CString m_strProductKey;                                                // +0x1b8 the item bag key of the product
    ATL::CAtlArray<CString> m_aIngredientKeys;                              // +0x1c0 the item bag keys of the ingredients
    CString m_strProgressKey;                                               // +0x1e0 the item bag key of the running craft
    int m_nState;                                                           // +0x1e8 0 idle, 1 crafting, 2 ready
    unsigned m_nLastTick;                                                   // +0x1ec the time of the last gauge update
    ATL::CRBMap<int, int> m_mapRecipes;                                     // +0x1f0 row -> recipe id
};
MS2_CHECK_SIZE(UIManufactureDialog, 0x220);
MS2_CHECK_OFFSET(UIManufactureDialog, m_nNpcId, 0x180);
MS2_CHECK_OFFSET(UIManufactureDialog, m_nManufactureId, 0x188);
MS2_CHECK_OFFSET(UIManufactureDialog, m_nSelected, 0x190);
MS2_CHECK_OFFSET(UIManufactureDialog, m_aRowKeys, 0x198);
MS2_CHECK_OFFSET(UIManufactureDialog, m_strProductKey, 0x1b8);
MS2_CHECK_OFFSET(UIManufactureDialog, m_aIngredientKeys, 0x1c0);
MS2_CHECK_OFFSET(UIManufactureDialog, m_strProgressKey, 0x1e0);
MS2_CHECK_OFFSET(UIManufactureDialog, m_nState, 0x1e8);
MS2_CHECK_OFFSET(UIManufactureDialog, m_mapRecipes, 0x1f0);
