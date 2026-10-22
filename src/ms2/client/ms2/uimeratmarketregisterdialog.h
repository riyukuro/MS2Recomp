// uimeratmarketregisterdialog.h - UIMeratMarketRegisterDialog (RTTI .?AVUIMeratMarketRegisterDialog@@, 0x240 bytes,
// UI id 0x4ec5, swf "MeratMarketRegisterDialog"): the modal dialog that lists an item the player made (a UGC design
// or a music score) on the Merat market, or lists an already sold one again. Owning unit:
// client\ms2\uimeratmarketregisterdialog.cpp (0x141317690-0x14131d910). Header name assumed from the unit path.
// Member and method names are invented from use.
#pragma once
#include "ms2/client/ms2/uimodaldialog.h"
#include "ms2/commonfiles/meratmarketbasketinfo.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/gfxvalue.h"
#include "ms2/placeholder/asdata.h"
#include <atlcoll.h>

class CMsgBoxData;
class ASObj;
class Unk_MrdInput;
class CItemData;

class UIMeratMarketRegisterDialog : public UIModalDialog
{
public:
    typedef ATL::CAtlArray<MS2Ptr<CItem> > ItemArray;

    UIMeratMarketRegisterDialog();                                      // 0x141317690
    virtual ~UIMeratMarketRegisterDialog();                             //  0 0x1413177f0 (??_G 0x14131d2f0)
    virtual CString GetTypeName();                                          //  1 0x1413178e0 "MeratMarketRegisterDialog"
    virtual int vfunc_13();                                             // 13 0x1413187d0 tab key
    virtual void vfunc_15();                                            // 15 0x141318970 per-frame: refresh the fee
    virtual void OnLoadComplete();                                      // 22 0x141317d60 initData
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x141318480
    virtual int vfunc_48() { return 0x4ec5; }                           // 48 0x14131d490
    virtual void vfunc_49(Scaleform::GFx::Value* pRetVal, ASData* pArgs);   // 49 0x141317a50 tooltips
    virtual int vfunc_65();                                             // 65 0x141317a10 open
    virtual void vfunc_67();                                            // 67 0x141317930 close

    void FUN_141318a20(MS2Ptr<CMeratMarketProduct> spProduct);          // a product changed: the fee is stale
    void FUN_141318aa0(MS2Ptr<CMeratMarketProduct> spProduct);          // a product was listed: move its item to the end
    void FUN_141318cc0();                                               // clear the three tag inputs
    void FUN_141318ef0(int nMaxChars);                                  // limit the three tag inputs
    void FUN_1413190c0(int nMode, Unk_MeratProductKey key);             // set mode and the product to list again
    bool FUN_141319100(int nButton, const CMsgBoxData& data);           // answer of the "fee changed" box: send the product
    bool FUN_141319180(int nButton, const CMsgBoxData& data);           // answer of the "fee changed" box: refresh the fee
    MS2Ptr<CItem> FUN_1413191f0(int nIndex);                            // item of the list by index
    bool FUN_1413192d0(__int64 nItemUid, MS2Ptr<CItem> spItem);         // the item can still be found
    int FUN_1413197a0(const CUgcMarketProduct* pProduct);               // list index of the product's item, -1 if none
    void FUN_141319920(ItemArray& arrItems);                            // collect the items that can be listed
    bool FUN_141319f10(MS2Ptr<CItem> spItem);                           // the item is already listed
    bool FUN_14131a100(Unk_MeratProductKey key);                        // open the list-again form of a sold product
    bool FUN_14131a880(CString& strItems, int nColumns, int nRows);     // build the item grid
    void FUN_14131aa90(MS2Ptr<CMeratMarketPacket::UgcAddProductBase> spProduct);   // send the request
    __int64 FUN_14131ac50();                                            // the base register fee
    __int64 FUN_14131ac80(char bAddBase, MS2Ptr<CItem> spItem, char bRecalc);   // the register fee of an item
    bool FUN_14131ae60(unsigned char bAddBase, bool bCheckStale, __int64* pFee);   // the fee, checked against the stock
    bool FUN_14131b0e0(const CStringW& strDescription, const CStringW& strName);   // validate the texts
    CStringW FUN_14131b420(__int64 nMin, __int64 nMax);                 // "price must be between"
    void FUN_14131b4e0(ASObj& obj, unsigned char bAddBase);             // put the fee texts into obj
    void FUN_14131b7e0();                                               // forget the selected item
    void FUN_14131b810(ASData& data);                                   // "OnClickRegister"
    void FUN_14131c010(ASData& data);                                   // "OnClickReRegister"
    void FUN_14131c4e0(ASData& data);                                   // "OnGetFee" / "OnGetTotalFee"
    void FUN_14131c570(ASData& data);                                   // "OnChangeSelectedIndex"
    void FUN_14131c9d0(ASData& data);                                   // "GetAlreadyRegistIndex"
    int FUN_14131ca80();                                                // tag input limit
    MS2Ptr<Unk_MrdInput> FUN_140e35bd0(const CString& strName);          // text input child lookup (UIDialog member)

private:
    MS2_LAYOUT_FRIEND;
    CString m_strKey;                                                   // +0x180 the movie's own name
    int m_nMode;                                                        // +0x188 0 = list a new product, else list a sold one again
    int m_nAlreadyIndex;                                                // +0x18c items before this one were listed already
    Unk_MeratProductKey m_keyResale;                                    // +0x190 the sold product (resale mode)
    bool m_bOnlyEnabled;                                                // +0x1a0 "onlyShowEnableDesigns"
    ItemArray m_items;                                                  // +0x1a8 the items the grid shows
    ATL::CAtlMap<__int64, MS2Ptr<CItem> > m_mapUgc;                     // +0x1c8 UGC uid -> item that is already offered
    MS2Ptr<CMeratMarketPacket::UgcAddProductBase> m_spRequest;          // +0x210 the request being filled
    int m_nFlags;                                                       // +0x220 bit 0: the fee is stale, bit 1: the movie shows it
    __int64 m_nFee;                                                     // +0x228 the cached register fee
    MS2Ptr<CItem> m_spSelected;                                         // +0x230 the item selected in the grid
};
MS2_CHECK_SIZE(UIMeratMarketRegisterDialog, 0x240);
MS2_CHECK_OFFSET(UIMeratMarketRegisterDialog, m_strKey, 0x180);
MS2_CHECK_OFFSET(UIMeratMarketRegisterDialog, m_nMode, 0x188);
MS2_CHECK_OFFSET(UIMeratMarketRegisterDialog, m_keyResale, 0x190);
MS2_CHECK_OFFSET(UIMeratMarketRegisterDialog, m_items, 0x1a8);
MS2_CHECK_OFFSET(UIMeratMarketRegisterDialog, m_mapUgc, 0x1c8);
MS2_CHECK_OFFSET(UIMeratMarketRegisterDialog, m_spRequest, 0x210);
MS2_CHECK_OFFSET(UIMeratMarketRegisterDialog, m_nFlags, 0x220);
MS2_CHECK_OFFSET(UIMeratMarketRegisterDialog, m_spSelected, 0x230);
