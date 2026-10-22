// uibeautyshopdialog.h - the beauty shop page (RTTI UIBeautyShopDialog, UI id 0x4eee): the hair / makeup / skin
// shops of the beauty salon. The player previews an item on the character (Customize), the page prices the change
// (fee row, sale event, coupon) and sends it through the bill dialog (UIBillDialog, defined next door in
// uibeautyshopstyledialog.h). NOT an original header (the unit is ?\uibeautyshopdialog.cpp). Member and helper names
// are invented from use.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include <utility>
#include "ms2/placeholder/asobj.h"
#include "ms2/client/ms2/uibeautyshopstyledialog.h"     // IItemCustomizeEventListener, Customize, CBeautyShopDataCli, UIBillDialog

class CInPacket;
class CMsgBoxData;
class NotifyObject;
class CItem;
class Unk_BSPriceRow;                                   // a row of the shop (CBeautyShopItem)
class Unk_140acd6e0;                                    // the "m_probInfo" child
class Unk_BSPartObj;
class ASTextField;
class ASMovieClip;

class UIBeautyShopDialog : public UIDialog, public UIItemEventListener, public IItemCustomizeEventListener
{
public:
    UIBeautyShopDialog();                               // 0x1418c3630
    virtual ~UIBeautyShopDialog();                      // 0x1418c3950
    virtual CString vfunc_1();
    virtual int vfunc_13();
    virtual void vfunc_15();
    virtual void OnLoadInit();
    virtual void OnLoadComplete();
    virtual void vfunc_26();
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
    virtual void vfunc_45(Scaleform::GFx::Value* pRetVal, const CString& strMethod, ASData* pArgs);
    virtual int vfunc_46();
    // @0x1418ccb60
    virtual int vfunc_48() { return 0x4eee; }
    virtual void vfunc_67();
    virtual int vfunc_74(int a1, void* p2, void* p3);
    virtual int OnMessage(UISwfEntity* pSender, UIMsg* pMsg);
    virtual void vfunc_84();                            // 84 (new) refresh the page
    virtual void vfunc_85();                            // 85 (new) refresh the page (second entry)
    virtual void vfunc_86();                            // 86 (new) build the current item (skin)
    virtual void vfunc_87();                            // 87 (new) build the item list

    // UIItemEventListener overrides
    virtual void vfunc_21(void* p);
    virtual void vfunc_22(void* p);
    virtual void vfunc_24(void* p);
    virtual void vfunc_25(void* p);
    // IItemCustomizeEventListener overrides
    virtual int vfunc_0(void* p, int);
    virtual int vfunc_1(void* p);
    virtual int vfunc_2(void* p, float fValue, int nIndex);
    virtual int vfunc_3(void* p, float fValue);

    int FUN_1418c6580(ASArray& out, int* pnItemId, int* pnIndex);      // the current item row
    bool FUN_1418c6870(ASObj& row, MS2Ptr<Unk_BSPriceRow> spRow, class Unk_BSPlayer* pPc, bool bFirst);
    int FUN_1418c6af0();
    void FUN_1418c6bc0(int nValue);
    void FUN_1418c6c80(int nValue);
    void FUN_1418c6d40(Unk_BSFee* pFee, unsigned* pPrice);             // show the fee
    void FUN_1418c7180(int nItemId);                    // show the item
    void FUN_1418c7400(int bPreview);
    Unk_BSFee* FUN_1418c74e0(unsigned* pPrice);         // the fee row and its price
    void FUN_1418c76d0(int nItemId);
    void FUN_1418c7750(int nPalette, int nColor);
    void FUN_1418c77c0(int nA, int nB);
    void FUN_1418c7830(int nPos);
    void FUN_1418c78d0(int nIndex, float fSize);
    void FUN_1418c79f0(float fDegree);
    void FUN_1418c7aa0(int);                            // empty
    void FUN_1418c7ab0();
    void FUN_1418c7ce0();
    void FUN_1418c7d20(int bPreview);
    void FUN_1418c7d90(int bPreview);
    void SendBeautyMode12(int nSlot);
    void FUN_1418c7fe0(int nSlot);
    void FUN_1418c80b0(CInPacket& packet);              // opcode 0x31
    int FUN_1418c8ee0();                                // init
    bool FUN_1418c9610();
    void FUN_1418c9780(NotifyObject* pNotify);
    bool FUN_1418c9960(int nResult, const CMsgBoxData& data);
    bool FUN_1418c9990(int nResult, const CMsgBoxData& data);
    bool FUN_1418c99e0(int nResult, const CMsgBoxData& data);
    bool FUN_1418c9ae0(int nResult, const CMsgBoxData& data);
    void FUN_1418c9b20(NotifyObject* pNotify);
    void FUN_1418c9cb0(int nPalette);
    int FUN_1418c9cd0();
    void FUN_1418c9d80();
    int FUN_1418c9f20();
    int FUN_1418ca240(void* p);
    void FUN_1418ca380();
    void FUN_1418ca400();
    void OnClickReset();
    int FUN_1418ca510(ASObj& out, unsigned* pPrice);
    void FUN_1418cae60();
    void FUN_1418caec0();
    int FUN_1418caf20(int nItemId);
    void FUN_1418cb000(MS2Ptr<CItem> spCur, MS2Ptr<CItem> spNew);
    void FUN_1418cb6a0(MS2Ptr<CItem> spItem);
    void FUN_1418cb6d0();
    void FUN_1418cb6e0(int n);
    void FUN_1418cb750(ASObj& out);
    CStringW FUN_1418cb920(int nShopKind, int nMode);
    CStringW FUN_1418cbb40(int nShopKind, int nMode);
    int FUN_1418cbbe0();                                // the shop kind
    bool FUN_1418cbc00(int n);
    bool FUN_1418cbc70();
    bool FUN_1418cbd30(int nItemId);
    int FUN_1418cbdc0(int nItemId);
    MS2Ptr<Unk_BSPriceRow> FUN_1418cbeb0(int nItemId);
    int FUN_1418ccb40();                                // the sale event id
    MS2Ptr<ASTextField> FUN_140bb4cf0(const CString& strName);          // text field child lookup (a UIDialog member)
    MS2Ptr<ASMovieClip> FUN_140ba7930(const CString& strName);          // movie clip child lookup (a UIDialog member)
    MS2Ptr<Unk_140acd6e0> FUN_140bb4b10(const CString& strName);        // bind a button child

private:
    MS2_LAYOUT_FRIEND;
    ATL::CAtlArray<MS2Ptr<Unk_BSPriceRow> > m_198;      // +0x198 the shop rows
    MS2Ptr<Customize> m_1b8;                            // +0x1b8 the customize controller
    Unk_BSCamera* m_1c8;                                // +0x1c8 the camera
    CBeautyShopDataCli m_1d0;                           // +0x1d0 the shop
    MS2Ptr<Unk_BSPriceRow> m_278;                       // +0x278 the selected row
    std::pair<int, int> m_288;                          // +0x288 (palette id, colour index)
    int m_290;                                          // +0x290 mode (0 none, 1 hair, 2 style save, 3, 4 skin)
    unsigned m_294;                                     // +0x294 owned style slots
    unsigned m_298;                                     // +0x298 used style slots
    __int64 m_2a0;                                      // +0x2a0
    int m_2a8;                                          // +0x2a8
    int m_2ac;                                          // +0x2ac preview with the cap
    int m_2b0;                                          // +0x2b0 the player wears a cap
    char m_2b4;
    char m_2b5;                                         // +0x2b5 the style select dialog is open
    MS2Ptr<CItem> m_2b8;
    MS2Ptr<CItem> m_2c8;
    char m_2d8;                                         // +0x2d8 an apply is pending
    int m_2dc;                                          // +0x2dc palette id
    int m_2e0;
    int m_2e4;                                          // +0x2e4 -1
    MS2Ptr<Unk_140acd6e0> m_2e8;                        // +0x2e8 "m_probInfo"
};
MS2_CHECK_SIZE(UIBeautyShopDialog, 0x2f8);
MS2_CHECK_OFFSET(UIBeautyShopDialog, m_198, 0x198);
MS2_CHECK_OFFSET(UIBeautyShopDialog, m_1b8, 0x1b8);
MS2_CHECK_OFFSET(UIBeautyShopDialog, m_1d0, 0x1d0);
MS2_CHECK_OFFSET(UIBeautyShopDialog, m_278, 0x278);
MS2_CHECK_OFFSET(UIBeautyShopDialog, m_290, 0x290);
MS2_CHECK_OFFSET(UIBeautyShopDialog, m_2b8, 0x2b8);
MS2_CHECK_OFFSET(UIBeautyShopDialog, m_2d8, 0x2d8);
MS2_CHECK_OFFSET(UIBeautyShopDialog, m_2e8, 0x2e8);
