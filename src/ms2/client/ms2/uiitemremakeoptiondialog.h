// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Header name assumed.
// UIItemRemakeOptionDialog: the item option remake window ("ItemRemakeOptionDialog", packet 0x75). Size 0x228 (the factory
// allocates 0x228). Derives the enchant window base UIItemModifyDialogBase (uiitemenchantdialog.h) and the item event listener.
#pragma once
#include <atlcoll.h>
#include "ms2/client/ms2/uiitemenchantdialog.h"
#include "ms2/placeholder/uiitemeventlistener.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/citem.h"

class ASData;
class CInPacket;
class CMsgBoxData;
class NotifyObject;
class Unk_EnButton;
class Unk_EnSlot;

class UIItemRemakeOptionDialog : public UIItemModifyDialogBase, public UIItemEventListener {
public:
    UIItemRemakeOptionDialog();                                 // 0x14129cfa0
    virtual ~UIItemRemakeOptionDialog();                        // 0x14129d100
    virtual CString vfunc_1();                                  // 0x14129d220 "ItemRemakeOptionDialog"
    virtual CString vfunc_7();                                  // 0x14129d270 "ItemEnchantDialog"
    virtual void OnLoadComplete();                              // 0x14129d2c0
    virtual int vfunc_13();                                     // 0x14129dbe0
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 0x14129d4d0
    virtual int vfunc_48();                                     // 0x1412a40c0 the dialog id 0x4eeb
    virtual void vfunc_67();                                    // 0x14129d870
    virtual void vfunc_79(void* pPacket);                       // 0x14129daa0 CInPacket opcode 200 (remake option)

    void FUN_14129dc60(NotifyObject* pNotify);                  // 0x14129dc60 "NotifyGameEventChanged" (SaleRemake)
    void FUN_14129dd50();                                       // 0x14129dd50 fill the item bag
    void FUN_14129e190(ASData* pData);                          // 0x14129e190 onClickForceRemake
    void FUN_14129e530(ASData* pData);                          // 0x14129e530 onClickCompareEnchant
    void FUN_14129e950(ASData* pData);                          // 0x14129e950 onClickRemake
    void FUN_14129ed90(ASData* pData);                          // 0x14129ed90 onClickApply
    void FUN_14129f360(ASData* pData);                          // 0x14129f360 GetEnableLockOption
    void FUN_14129f6f0();                                       // 0x14129f6f0 onEndRemakeAni
    void SendChangeAttributesMode4(unsigned __int64 uid);                   // 0x14129f740 onSelectItem
    void FUN_14129f940(CInPacket* pPacket);                     // 0x14129f940 packet kind 4: the item is accepted
    void FUN_1412a0460(const Scaleform::GFx::FunctionHandler::Params& params);   // 0x1412a0460 debug: fill the ingredients
    void FUN_1412a0550(const Scaleform::GFx::FunctionHandler::Params& params);   // 0x1412a0550 debug: fill the ingredient unit (10)
    bool FUN_1412a0650(int nResult, const CMsgBoxData& box);    // 0x1412a0650 high rank item confirm
    CString FUN_1412a0720(CItem* item, CString key, CAtlArray<CString>& names);   // 0x1412a0720 bind the item to a slot key
    void FUN_1412a0800();                                       // 0x1412a0800 release the bound slot keys
    Unk_EnSlot* FUN_1412a0900(const CString& name);             // 0x1412a0900 slot by name
    bool FUN_1412a0940(MS2Ptr<CItem> item);                     // 0x1412a0940 can the player pay the remake price
    void FUN_1412a0cd0(ASObj& obj, MS2Ptr<CItem> item);         // 0x1412a0cd0 "enchantItem"
    void FUN_1412a0e30(ASObj& obj, MS2Ptr<CItem> item, CIngredientContainer* ingredients);   // 0x1412a0e30 sale desc / ingredients
    void FUN_1412a1600(MS2Ptr<CItem> item);                     // 0x1412a1600 re-select the item
    void FUN_1412a1650(MS2Ptr<CItem> item);                     // 0x1412a1650 swap the remade item in
    void FUN_1412a1790(MS2Ptr<CItem> cur, MS2Ptr<CItem> next);  // 0x1412a1790 show the remake result
    void FUN_1412a1c40(int nState);                             // 0x1412a1c40
    int FUN_1412a1c60();                                        // 0x1412a1c60
    int FUN_1412a1c80(MS2Ptr<CItem> item);                      // 0x1412a1c80 how many of the item the player owns
    void FUN_1412a1d40(unsigned __int64 uid, int nOption, bool bConfirm);   // 0x1412a1d40 start a remake (asks for high SA items)
    void FUN_1412a2380(unsigned __int64 uid, int nOption, bool bConfirm);   // 0x1412a2380 send the remake request
    bool FUN_1412a2a50(int nResult, const CMsgBoxData& box);    // 0x1412a2a50
    void FUN_1412a2ac0();                                       // 0x1412a2ac0 reset the selection
    void FUN_1412a2b40(unsigned nItemId);                       // 0x1412a2b40 "previous option item does not exist" notice
    void FUN_1412a2c50(CInPacket* pPacket);                     // 0x1412a2c50 packet kind 6
    void FUN_1412a30f0(CInPacket* pPacket);                     // 0x1412a30f0 packet kind 1
    void FUN_1412a3330(CInPacket* pPacket);                     // 0x1412a3330 packet kind 2
    void FUN_1412a3460(CInPacket* pPacket);                     // 0x1412a3460 packet kind 8 (the packet is unused)
    void FUN_1412a34f0(CInPacket* pPacket);                     // 0x1412a34f0 packet kind 5 (error)
protected:
    MS2_LAYOUT_FRIEND;
    CAtlArray<CString> m_names198;                              // +0x198 slot keys of the item bags
    CAtlArray<CString> m_names1b8;                              // +0x1b8 slot keys of the ingredient bags
    MS2Ptr<CItem> m_cur;                                        // +0x1d8 the selected item
    MS2Ptr<CItem> m_new;                                        // +0x1e8 the remade item
    int m_state;                                                // +0x1f8
    int m_remakeMode;                                           // +0x1fc (init 2)
    MS2Ptr<Unk_EnButton> m_debugBtnFillIngredientUnit;          // +0x200
    MS2Ptr<Unk_EnButton> m_debugBtnFillIngredient;              // +0x210
    int m_optionCount;                                           // +0x220
};
MS2_CHECK_SIZE(UIItemRemakeOptionDialog, 0x228);
MS2_CHECK_OFFSET(UIItemRemakeOptionDialog, m_names198, 0x198);
MS2_CHECK_OFFSET(UIItemRemakeOptionDialog, m_cur, 0x1d8);
MS2_CHECK_OFFSET(UIItemRemakeOptionDialog, m_state, 0x1f8);
MS2_CHECK_OFFSET(UIItemRemakeOptionDialog, m_optionCount, 0x220);
