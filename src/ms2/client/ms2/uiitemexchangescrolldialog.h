// uiitemexchangescrolldialog.h - UIItemExchangeScrollDialog (RTTI .?AVUIItemExchangeScrollDialog@@, 0x230 bytes, UIDialog +
// UIStatusEventListener at +0x178, UI id 0x4f14, swf "ItemExchangeScrollDialog"): the item exchange scroll window. The
// scroll item (m_uidScroll, from FUN_140f51490) names a row of Table/ItemExchangeScrollTable.xml (m_spExchange); the row's
// type decides the page: 1 exchange (a recipe item + ingredients -> an item), 2 upgrade (the server sends the target item and
// its ingredients, packet 0x9b / 0), 3 trading. "onOk" sends packet 0x9b / 1 (ExchangeRequest). Packet 0x9b answers: kind 0
// target chosen (FUN_140f52ca0), 2 result code (FUN_140f55670), 3 ingredient counts changed (FUN_140f53300).
// Owning unit: ?\uiitemexchangescrolldialog.cpp. Header name assumed from the unit path; member names are invented.
#pragma once
#include <afx.h>
#include <atlcoll.h>

#include "ms2/ms2layout.h"
#include "ms2/client/ms2/uidialog.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/ms2svrptr.h"
#include "ms2/placeholder/uistatuseventlistener.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/commonfiles/itemexchangescrolltable.h"
#include "ms2/commonfiles/commonstruct_wa.h"

class ASData;
class ASObj;
class CItem;
class CInPacket;
class Unk_140acd6e0;

class UIItemExchangeScrollDialog : public UIDialog, public UIStatusEventListener
{
public:
    UIItemExchangeScrollDialog();                                   // 0x140f50d60
    virtual ~UIItemExchangeScrollDialog();                          //  0 0x140f566d0 (??_G 0x140f56920)
    virtual CString vfunc_1();                                      //  1 0x140f50eb0 "ItemExchangeScrollDialog"
    virtual void vfunc_15();                                        // 15 0x140f51350
    virtual void OnLoadComplete();                                  // 22 0x140f51150
    virtual void vfunc_26();                                        // 26 0x140f50f80 unbind the slots, drop the listener
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x140f51280 onOk
    virtual int vfunc_48() { return 0x4f14; }                       // 48 0x140f56970
    virtual int vfunc_65();                                         // 65 0x140f50f00
    virtual void vfunc_67();                                        // 67 0x140f50f30
    virtual void vfunc_72();                                        // 72 0x140f50f50 vfunc_55()
    virtual void vfunc_79(void* p);                                 // 79 0x140f51360 packet 0x9b
    virtual void vfunc_oa0_11(void* p) override;                    // UIStatusEventListener 0x140f51460 -> FUN_140f56180

    void FUN_140f51490(CItem* pScroll);                             // 0x140f51490 remember the scroll item
    // The slots: pRef the item (id, rank, count) with the count scaled by nMul; flags 1 count/enough text, 2 icon flag 0x800,
    // 4 level text, 8 drag slot, 0x10 count 0; spCur the item the recipe is applied to (upgrade page).
    void FUN_140f514c0(const Unk_ExchangeItemRef* pRef, CString strKey, ASObj& obj, unsigned char nFlags, int nMul,
                       MS2Ptr<CItem> spCur);                        // 0x140f514c0
    void FUN_140f51e90(CIngredientInfo* pIng, CString strKey, ASObj& obj, unsigned char nFlags, int nMul);   // 0x140f51e90
    bool FUN_140f524d0(unsigned nCount);                            // 0x140f524d0 FUN_140f52520(nCount) == 0
    unsigned FUN_140f52520(unsigned nCount);                        // 0x140f52520 0 ok, else the error code of the result text
    unsigned FUN_140f52610(__int64 nMeso, const Unk_ExchangeItemRef* pRecipe, CIngredientContainer* pRequire, unsigned nCount);   // 0x140f52610
    CItem* FUN_140f52810();                                         // 0x140f52810 the scroll item
    void FUN_140f52880();                                           // 0x140f52880 fill the page ("setData")
    void FUN_140f52c80();                                           // 0x140f52c80 refresh after the item changed
    void FUN_140f52ca0(CInPacket* pPacket);                         // 0x140f52ca0 packet kind 0: the upgrade target
    void FUN_140f53300(CInPacket* pPacket);                         // 0x140f53300 packet kind 3: ingredient counts
    void SendItemExchangeScrollMode1(ASData* pData);                              // 0x140f53950 onOk
    void FUN_140f53a70();                                           // 0x140f53a70 look up the table row of the scroll
    void FUN_140f53bb0(ASObj& obj, CExchangeItemInfo* pInfo);       // 0x140f53bb0 page type 1
    void FUN_140f54120(ASObj& obj, CExchangeItemInfo* pInfo);       // 0x140f54120 page type 2
    void FUN_140f544d0(ASObj& obj, CExchangeItemInfo* pInfo);       // 0x140f544d0 page type 3
    void FUN_140f54a20(const Scaleform::GFx::FunctionHandler::Params& params);   // 0x140f54a20 "updateCountFunction"
    unsigned FUN_140f55190();                                       // 0x140f55190 the make count of the movie
    int FUN_140f55220();                                            // 0x140f55220 the largest make count the player can pay
    bool FUN_140f55670(const int* pCode);                           // 0x140f55670 notice of a result code; true if it was an error
    void FUN_140f55b90(const Scaleform::GFx::FunctionHandler::Params& params);   // 0x140f55b90 debug: fill the ingredients
    void FUN_140f55c50(const Scaleform::GFx::FunctionHandler::Params& params);   // 0x140f55c50 debug: fill 10
    void FUN_140f55d10();                                           // 0x140f55d10 bind the debug buttons
    void FUN_140f56180();                                           // 0x140f56180 "updateData" (max count)

private:
    MS2_LAYOUT_FRIEND;
    __int64 m_uidScroll;                                            // +0x180 uid of the scroll item
    __int64 m_uidTarget;                                            // +0x188 uid of the upgrade target item
    ATL::CAtlArray<CString> m_infoKeys;                             // +0x190 "<name>_info_<n>" slot binds
    ATL::CAtlArray<CString> m_dragKeys;                             // +0x1b0 "<name>_drag_<n>" slot binds
    MS2Ptr<ASMovieClip> m_spScroll;                                 // +0x1d0 "m_scroll"
    MS2Ptr<Unk_140acd6e0> m_spOk;                                   // +0x1e0 "m_ok"
    MS2Ptr<CExchangeItemInfo> m_spExchange;                         // +0x1f0 the table row
    MS2SvrPtr<CIngredientContainer> m_spIngredients;                // +0x200 the ingredients the server sent (upgrade)
    MS2Ptr<Unk_140acd6e0> m_spDebugAddMax;                          // +0x210 "m_debugAddMax"
    MS2Ptr<Unk_140acd6e0> m_spDebugAdd10;                           // +0x220 "m_debugAdd10"
};
MS2_CHECK_SIZE(UIItemExchangeScrollDialog, 0x230);
MS2_CHECK_OFFSET(UIItemExchangeScrollDialog, m_uidScroll, 0x180);
MS2_CHECK_OFFSET(UIItemExchangeScrollDialog, m_infoKeys, 0x190);
MS2_CHECK_OFFSET(UIItemExchangeScrollDialog, m_spScroll, 0x1d0);
MS2_CHECK_OFFSET(UIItemExchangeScrollDialog, m_spExchange, 0x1f0);
MS2_CHECK_OFFSET(UIItemExchangeScrollDialog, m_spIngredients, 0x200);
MS2_CHECK_OFFSET(UIItemExchangeScrollDialog, m_spDebugAdd10, 0x220);
