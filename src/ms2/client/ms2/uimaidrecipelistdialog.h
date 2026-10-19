// uimaidrecipelistdialog.h - the maid windows of the home manufacturing (RTTI UIMaidRecipeListDialog, UIManufactureStatus,
// UIMDEditDialog) and UIMDEditDialogCommon::CShop. NOT an original header (the unit is ?\uimaidrecipelistdialog.cpp; the
// exe has no assert path for it, so the three dialogs share one translation unit). Member names are invented from use.
// UI ids: UIMaidRecipeListDialog 0x4ecb, UIManufactureStatus 0x4ec9, UIMDEditDialog 0x4ebf (the merat designer edit tool).
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/client/ms2/uidialog.h"
#include "ms2/client/ms2/uimodaldialog.h"
#include "ms2/commonfiles/meratmarketbasketinfo.h"

class ASData;

// The recipe list of a maid (opened from the manufacture status window): one row per recipe of the maid's recipe book.
class UIMaidRecipeListDialog : public UIDialog
{
public:
    UIMaidRecipeListDialog();                               // 0x1412daa40
    virtual ~UIMaidRecipeListDialog();                      // 0x1412daae0
    virtual CString vfunc_1();
    virtual void OnLoadInit();
    virtual void OnLoadComplete();
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
    virtual void vfunc_43();
    virtual int vfunc_48() { return 0x4ecb; }
    virtual int vfunc_65();
    virtual void vfunc_67();

    void FUN_1412dac40();                                   // fill the list with the recipes of the book
    void FUN_1412db660(int nBook, float fX, float fY);      // open on a recipe book at a screen position
    void FUN_1412db6c0();                                   // move to the position and rebuild the list
    template <class T> MS2Ptr<T> FUN_140c02900(const CString& strName);     // bind a list child

private:
    MS2_LAYOUT_FRIEND;
    int m_178;                                              // +0x178 the recipe book id (0 = none)
    float m_17c;                                            // +0x17c x of the window
    float m_180;                                            // +0x180 y of the window
    int m_184;                                              // +0x184
    ATL::CAtlArray<CString> m_188;                          // +0x188 the item bag keys of the rows
};
MS2_CHECK_SIZE(UIMaidRecipeListDialog, 0x1a8);
MS2_CHECK_OFFSET(UIMaidRecipeListDialog, m_178, 0x178);
MS2_CHECK_OFFSET(UIMaidRecipeListDialog, m_17c, 0x17c);
MS2_CHECK_OFFSET(UIMaidRecipeListDialog, m_188, 0x188);

class UIManufactureStatus;
void FUN_1412dc3c0(UIManufactureStatus* pDlg);              // 0x1412dc3c0 clear the movie ("destoryAll") and send the maids again

// The progress window of the maids that are manufacturing.
class UIManufactureStatus : public UIDialog
{
    friend void FUN_1412dc3c0(UIManufactureStatus* pDlg);
public:
    UIManufactureStatus();                                  // 0x1412dba80
    virtual ~UIManufactureStatus();                         // 0x1412dbb10
    virtual CString vfunc_1();
    virtual void OnLoadComplete();
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
    virtual void vfunc_43();
    virtual int OnMessage(UISwfEntity* pSender, UIMsg* pMsg);
    virtual int vfunc_48() { return 0x4ec9; }
    virtual int vfunc_65();
    virtual void vfunc_67();
    virtual void vfunc_72();
    virtual void vfunc_79(void* p);

    void FUN_1412dc480();                                   // send the maids to the movie ("setData")

private:
    MS2_LAYOUT_FRIEND;
    ATL::CAtlArray<CString> m_178;                          // +0x178 the item bag keys of the rows
    unsigned m_198;                                         // +0x198 the time of the last progress update
    int m_19c;                                              // +0x19c a maid is still working (keep updating)
};
MS2_CHECK_SIZE(UIManufactureStatus, 0x1a0);
MS2_CHECK_OFFSET(UIManufactureStatus, m_178, 0x178);
MS2_CHECK_OFFSET(UIManufactureStatus, m_198, 0x198);

namespace UIMDEditDialogCommon
{
    // One shop of the merat designer edit tool: the products of a shop xml (in file order and by product id).
    class CShop : public CPtred
    {
    public:
        CShop();                                            // 0x1412e15b0
        virtual ~CShop();                                   // 0x1412e1730

        ATL::CAtlArray<MS2Ptr<CMeratMarketPremiumProduct> > m_products;     // +0x18
        ATL::CAtlMap<int, MS2Ptr<CMeratMarketPremiumProduct> > m_productMap;   // +0x38 by product id
    };
}

// The merat designer edit window (a developer tool of the KMS2_DEV client: exports the merat shop tables).
class UIMDEditDialog : public UIModalDialog
{
public:
    UIMDEditDialog();                                       // 0x1412dd900
    virtual ~UIMDEditDialog();                              // 0x1412dd9b0
    virtual CString vfunc_1();
    virtual int vfunc_13();
    virtual void OnLoadComplete();
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
    virtual void vfunc_45(Scaleform::GFx::Value* pRetVal, const CString& strMethod, ASData* pArgs);
    virtual int OnMessage(UISwfEntity* pSender, UIMsg* pMsg);
    virtual int vfunc_48() { return 0x4ebf; }
    virtual int vfunc_65();
    virtual void vfunc_67();
    virtual void vfunc_79(void* p);

    void FUN_1412dea90(CStringW strSearch);                 // fill the item list (the shop's items that match the search)
    template <class T> MS2Ptr<T> FUN_140f880c0(const CString& strName);     // bind a child control

private:
    MS2_LAYOUT_FRIEND;
    int m_180;                                              // +0x180 mode (1 merat shop, 2 cash shop)
    int m_184;                                              // +0x184 the cash shop list was filled
    int m_188;                                              // +0x188 the merat shop list was filled
};
MS2_CHECK_SIZE(UIMDEditDialog, 0x190);
MS2_CHECK_SIZE(UIMDEditDialogCommon::CShop, 0x80);
MS2_CHECK_OFFSET(UIMDEditDialog, m_180, 0x180);
MS2_CHECK_OFFSET(UIMDEditDialog, m_188, 0x188);
