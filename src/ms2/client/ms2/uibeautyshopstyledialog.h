// uibeautyshopstyledialog.h - the beauty shop's "my style" page (RTTI UIBeautyShopStyleDialog, UI id 0x4f03): the saved
// hair styles of the player (slots bought with merets), save / apply / delete / extend, and the fee bill. Also the
// item customize listener interface (RTTI IItemCustomizeEventListener) and the bill dialog's data (RTTI
// UIBillDialog::TData), both defined inside this unit's range. NOT an original header (the unit is
// ?\uibeautyshopstyledialog.cpp). Member and helper names are invented from use.
#pragma once
#include <afx.h>
#include <vector>
#include <algorithm>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/uiitemeventlistener.h"
#include "ms2/placeholder/imessagelistener.h"
#include "ms2/client/ms2/uiattendgiftdialog.h"     // Unk_14102fe10 (the AS list holder)
#include "ms2/client/ms2/uimodaldialog.h"          // UIBillDialog base
#include "ms2/client/ms2/customize.h"

class CItem;
class CInPacket;
class CMsgBoxData;
class NotifyObject;
class ASGameEntity;
class ASMovieClip;
class Unk_140bfc2e0;        // the AS list of the style slots ("m_items")
class Unk_BSPartHandle;     // a handle to the part the customize controller edits (uibeautyshopdialog.cpp)

// The item customize listener (vftable 0x142e6f3a0, 6 slots, no virtual destructor): the customize controller
// (Customize) reports to it. 0x18 bytes.
class IItemCustomizeEventListener
{
public:
    IItemCustomizeEventListener() : m_08(0), m_0c(1), m_10(0), m_14(-1) {}     // 0x140f0b090
    // @0x140f0b6e0
    virtual int vfunc_0(void*, int) { return 1; }
    // @0x140f0b700
    virtual int vfunc_1(void*) { return 1; }
    // @0x140f0b6a0
    virtual int vfunc_2(void*, float, int) { return 1; }
    // @0x140f0b660
    virtual int vfunc_3(void*, float) { return 1; }
    // @0x140f0b680
    virtual int vfunc_4(void*, void*) { return 1; }
    // @0x140f0b6c0
    virtual int vfunc_5(void*, void*) { return 1; }
    // @0x140f0b710
    void FUN_140f0b710(int n) { m_0c = n; }
    // @0x141922e80
    void FUN_141922e80(int n) { m_08 = n; }     // set the shop id (uibeautyshopdevdialog.cpp)
    // Inline getters, first emitted by ?\customize.cpp (Customize::Equipment's packets).
    // @0x140cd60e0
    int GetShopId() { return m_08; }        // the shop id
    // @0x140cd5db0
    int IsSendEnabled() { return m_0c; }        // send the changes (0: preview only)
    // @0x140cd5e30
    int GetCurrency() { return m_10; }
    // @0x140cd5950 uses one of the m_14 free tries (-1: unlimited, then m_10)
    int UseFreeTry()
    {
        if (m_14 == -1)
            return GetCurrency();
        int nOld = m_14--;
        m_14 = (std::max)(0, m_14);
        return nOld > 0;
    }

    MS2_LAYOUT_FRIEND;
    int m_08;
    int m_0c;                                   // +0x0c 1
    int m_10;
    int m_14;                                   // +0x14 -1
};
MS2_CHECK_SIZE(IItemCustomizeEventListener, 0x18);

// The customize controller (Customize): ms2/client/ms2/customize.h.

// The beauty shop camera (UI 0x4ef2's object).
class Unk_BSCamera : public CPtred
{
public:
    void FUN_1418dda30(int n);
};

// The shop fee row (CBeautyShopDataCli::FUN_1406e3dc0).
class Unk_BSFee : public CPtred
{
public:
    Unk_BSFee& operator=(const Unk_BSFee& o);   // 0x1418cc890
    const CString& FUN_1406dc4b0();             // the fee's currency name
    int FUN_1406dc4d0();                        // currency type
    int FUN_1406dc4f0();                        // fee
    int FUN_1406dc510();                        // fee type

    MS2_LAYOUT_FRIEND;
    CString m_18;                               // +0x18 currency name
    int m_20;
    int m_24;
    __int64 m_28;
    int m_30;
};
MS2_CHECK_SIZE(Unk_BSFee, 0x38);

// The beauty shop's data (0xa8 bytes, ctor 0x1406e53e0, dtor 0x1406ef480; npcshopdata).
class CBeautyShopDataCli
{
public:
    CBeautyShopDataCli();
    ~CBeautyShopDataCli();
    void FUN_1406e3d30();                       // reset
    Unk_BSFee* FUN_1406e3dc0();                 // the fee row
    Unk_BSFee* FUN_1406e3de0();                 // the second fee row
    void FUN_1406e5420(CInPacket& packet);      // read the shop

    MS2_LAYOUT_FRIEND;
    char m_pad_00[0x18];
    int m_18;                                   // +0x18 the sale event id
    int m_1c;                                   // +0x1c shop kind (1: hair)
    int m_20;                                   // +0x20 the beauty coupon item id (0: none)
    int m_24;
    int m_28;                                   // +0x28 the returned coupon item id
    int m_2c;                                   // +0x2c the coupon's event id
    char m_30;                                  // +0x30 the page selects a style first
    char m_pad_31[0x88 - 0x11];
};
MS2_CHECK_SIZE(CBeautyShopDataCli, 0xa8);
MS2_CHECK_OFFSET(CBeautyShopDataCli, m_18, 0x18);

// The bill dialog (UI 0x4e7b): shows the price of a beauty shop change.
class UIBillDialog : public UIModalDialog
{
public:
    // The bill (0x68 bytes, vftable 0x142e6f7f0).
    class TData : public CPtred
    {
    public:
        TData() : m_18(0), m_20(0), m_30(0), m_34(0), m_38(0), m_48(0), m_60(0) {}    // 0x140f0b0e0
        virtual ~TData() {}                                                         // 0x140f0b270

        MS2_LAYOUT_FRIEND;
        IMessageListener* m_18;                 // +0x18 the owner (answered through OnMessage)
        MS2Ptr<AScript> m_20;                   // +0x20 the bill rows
        int m_30;                               // +0x30
        int m_34;                               // +0x34 fee type
        int m_38;                               // +0x38 currency type
        CString m_40;                           // +0x40 currency name
        int m_48;                               // +0x48 price
        CStringW m_50;
        CStringW m_58;
        int m_60;
    };

    UIBillDialog();                             // 0x1418cd0c0 (uibeautyshopdialog.cpp)
    virtual ~UIBillDialog();                    // 0x1418cd170
    virtual CString vfunc_1();                  // "BillDialog"
    virtual int vfunc_13();
    virtual void OnLoadComplete();
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
    virtual int vfunc_48() { return 0x4e7b; }   // @0x1418ce5d0
    virtual void vfunc_67();
    void FUN_1418cda20(MS2Ptr<TData> spData);
    void FUN_1418cda70(int nPrice);
    MS2Ptr<class Unk_BSCheckBox> FUN_140e52670(const CString& strName);     // check box child lookup (a UIDialog member)
    MS2Ptr<class ASTextField> FUN_140bb4cf0(const CString& strName);        // text field child lookup (a UIDialog member)

private:
    MS2_LAYOUT_FRIEND;
    CStringW m_180;                             // +0x180
    MS2Ptr<TData> m_188;                        // +0x188 the bill
    void* m_198;                                // +0x198 (never set)
};
MS2_CHECK_SIZE(UIBillDialog, 0x1a0);
MS2_CHECK_OFFSET(UIBillDialog, m_188, 0x188);
MS2_CHECK_SIZE(UIBillDialog::TData, 0x68);
MS2_CHECK_OFFSET(UIBillDialog::TData, m_20, 0x20);
MS2_CHECK_OFFSET(UIBillDialog::TData, m_40, 0x40);
MS2_CHECK_OFFSET(UIBillDialog::TData, m_60, 0x60);

class UIBeautyShopStyleDialog : public UIDialog, public UIItemEventListener, public IItemCustomizeEventListener
{
public:
    UIBeautyShopStyleDialog();
    virtual ~UIBeautyShopStyleDialog();
    virtual CString vfunc_1();
    virtual int vfunc_13();
    virtual void vfunc_15();
    virtual void OnLoadComplete();
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
    virtual void vfunc_45(Scaleform::GFx::Value* pRetVal, const CString& strMethod, ASData* pArgs);
    // @0x140f0b650
    virtual int vfunc_48() { return 0x4f03; }
    virtual void vfunc_67();
    virtual int OnMessage(UISwfEntity* pSender, UIMsg* pMsg);
    virtual bool vfunc_84();                    // 84 (new) the dialog is open

    void FUN_140f05460(NotifyObject* pNotify);
    bool FUN_140f05640(int nResult, const CMsgBoxData& data);
    bool FUN_140f056e0(int nResult, const CMsgBoxData& data);
    bool FUN_140f05820(int nResult, const CMsgBoxData& data);
    bool FUN_140f05850(int nResult, const CMsgBoxData& data);
    bool FUN_140f05880(int nResult, const CMsgBoxData& data);
    void FUN_140f05a80(CInPacket& packet);
    int FUN_140f06e10();
    bool FUN_140f07310();
    void FUN_140f07520(Unk_BSFee* pFee, unsigned* pPrice);
    int FUN_140f07960();
    int FUN_140f07980();
    void FUN_140f079a0();
    void FUN_140f07a00();
    int FUN_140f07a60(MS2Ptr<CItem> spItem);
    void FUN_140f07cc0();
    void FUN_140f07e20();
    int FUN_140f08160();
    Unk_BSFee* FUN_140f08190(unsigned* pPrice);
    bool FUN_140f08220();
    void FUN_140f082d0();
    void FUN_140f08470();
    int FUN_140f084e0(AScript& out, unsigned* pPrice);
    void FUN_140f08950(int bPreview);
    void FUN_140f08a30(int bPreview);
    void FUN_140f08aa0(int bPreview);
    void FUN_140f08ae0(int nItemId, int nIndex);
    void FUN_140f08ba0();
    int FUN_140f08be0();
    void FUN_140f08f20(unsigned n);
    void FUN_140f08f70();
    MS2Ptr<CItem> FUN_140f09020(int nIndex);
    MS2Ptr<CItem> FUN_140f090d0(int nSlot);
    bool FUN_140f09230();
    int FUN_140f09260();
    void FUN_140f092b0();
    void FUN_140f092e0(bool b);
    void FUN_140f09380(NotifyObject* pNotify);
    bool FUN_140f09520(int nResult, const CMsgBoxData& data);
    bool FUN_140f09560();
    bool FUN_140f09630();
    MS2Ptr<ASMovieClip> FUN_140ba7930(const CString& strName);

private:
    MS2_LAYOUT_FRIEND;
    MS2Ptr<Customize> m_198;                    // +0x198 the customize controller (while the page is up)
    MS2Ptr<Unk_BSCamera> m_1a8;                 // +0x1a8 the camera
    CBeautyShopDataCli m_1b8;                   // +0x1b8 the shop
    bool m_260;                                 // +0x260 the saved styles arrived
    int m_264;                                  // +0x264 preview with the cap
    int m_268;                                  // +0x268 the player wears a cap
    int m_26c;                                  // +0x26c the shop mode (4: billable, 2: no confirm)
    MS2Ptr<ASGameEntity> m_270;                 // +0x270 "m_customStyle"
    Unk_14102fe10<Unk_140bfc2e0> m_items;       // +0x280 "m_items" of m_270
    unsigned m_290;                             // +0x290 open slots
    unsigned m_294;                             // +0x294 expected styles
    std::vector<MS2Ptr<CItem> > m_298;          // +0x298 the saved styles
    bool m_2b0;                                 // +0x2b0 an apply is pending
};
MS2_CHECK_SIZE(UIBeautyShopStyleDialog, 0x2b8);
MS2_CHECK_OFFSET(UIBeautyShopStyleDialog, m_198, 0x198);
MS2_CHECK_OFFSET(UIBeautyShopStyleDialog, m_1b8, 0x1b8);
MS2_CHECK_OFFSET(UIBeautyShopStyleDialog, m_260, 0x260);
MS2_CHECK_OFFSET(UIBeautyShopStyleDialog, m_270, 0x270);
MS2_CHECK_OFFSET(UIBeautyShopStyleDialog, m_items, 0x280);
MS2_CHECK_OFFSET(UIBeautyShopStyleDialog, m_290, 0x290);
MS2_CHECK_OFFSET(UIBeautyShopStyleDialog, m_298, 0x298);
MS2_CHECK_OFFSET(UIBeautyShopStyleDialog, m_2b0, 0x2b0);
