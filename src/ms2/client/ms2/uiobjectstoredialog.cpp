// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Object store bag window ("ObjectStoreDialog").
// MS2-UNIT: ?\uiobjectstoredialog.cpp
// MS2-RANGE: 0x141a72480-0x141a732e0 .text$mn
//
// Status: see progress/status.tsv. Callees that are not recovered yet are declared below ("unit-local
// placeholders") or in src/ms2/placeholder/; their names are Ghidra's (FUN_<va>) unless evident.
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiobjectstoredialog.cpp"
#include "ms2/placeholder/ms2stdafx.h"

#include "uiobjectstoredialog.h"

#include "ms2/commonfiles/banktable.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/placeholder/imessagelistener.h"
#include "ms2/placeholder/ms2ptr_impl.h"

#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local placeholders (names invented; promote to src/ms2/placeholder/ when shared) ----

class ASDialog : public ASDisplayObject { };

// The inventory dialog (UI id 0x4e2d): the store window is placed next to it.
class UIInventoryDialog : public UIDialog { };
UIInventoryDialog* FUN_1405344f0(int nUiId);

// The UI message ("openWindowPos"): an ActionScript call (ASData + type, 0x50 bytes).
class Unk_OsUIMsg : public UIMsg
{
public:
    Unk_OsUIMsg();                                          // 0x1422e4490
    ~Unk_OsUIMsg();                                         // 0x140c30570
    void FUN_1422b82b0(const char* pszMethod);
    void FUN_1422b7f70(int n);
    void* m_pad[10];
};

// The status-listener registry (singleton 0x140aa6d40).
class Unk_OsStatusMgr
{
public:
    void FUN_141b0cd00(UIStatusEventListener* pListener);   // register
    void FUN_141b0cd90(UIStatusEventListener* pListener);   // unregister
};
Unk_OsStatusMgr* FUN_140aa6d40();

// The item bag control (RTTI name unknown) of the movie: "bagId" names the bag shown.
class Unk_OsItemBag : public ASMovieClip
{
public:
    Unk_OsItemBag(const Scaleform::GFx::Value& v, int nMovieId);        // 0x1422cf330
#define OS_V(n) virtual void vfunc_##n();
    OS_V(16) OS_V(17) OS_V(18) OS_V(19) OS_V(20) OS_V(21) OS_V(22) OS_V(23)
#undef OS_V
    virtual void vfunc_24(int nShow);                                   // 24 (+0xc0) refresh
    void FUN_1407cba60(const char* szName, CString str);                // set the bag id
private:
    unsigned char m_pad_80[8];
};
MS2_CHECK_SIZE(Unk_OsItemBag, 0x88);

// The bound slot bag of a bag id (StoreSlotBag) and the control state it keeps.
class Unk_OsBind;
class Unk_OsSlotBag;
Unk_OsBind* FUN_1422c8e90(const CString& strBagId);                     // the bound object of the id
Unk_OsSlotBag* FUN_14180b940(Unk_OsBind* pBind);                        // the slot bag of it (NULL when unbound)
void FUN_1422cca90(Unk_OsSlotBag* pBag);                                // refresh the slots
void FUN_14180b230(CString* pBagId);                                    // drop the bag bound to the id
void FUN_14180b170(CString* pBagId, int nSlot, int nSize);              // create the bag (StoreSlotBag)
int FUN_1408b6200(int nItemType);                                       // the slot count of an item type's bank

// The object store state (global 0x143ab2d80): the sort button sends packet 0x18 / 8.
extern char DAT_143ab2d80;
int FUN_140de2860(void* pState);
void FUN_140de2b50(void* pState);
void FUN_140de2bd0(void* pState);

// The item amount shown ("current count" global 0x143ab28f8).
extern __int64 DAT_143ab28f8;
CStringW FUN_140719a00(__int64 n);

struct Unk_PickXY { float x, y; };                                      // dialog offset
extern Unk_PickXY DAT_143b02320;                                        // zero offset
void FUN_141275c30(UISwfEntity* pLeft, UISwfEntity* pRight, Unk_PickXY offLeft, Unk_PickXY offRight);

CStringTable* GetStringTable();
void FUN_140710590(COutPacket& packet);
void FUN_141901390(int nRelease, int nUiType);

void FUN_1422bce70(Scaleform::GFx::Value* pValue, const char* psz);
void FUN_1422bcea0(Scaleform::GFx::Value* pValue, const wchar_t* psz);
void FUN_1422bccb0(Scaleform::GFx::Value* pValue, int n);
MS2Ptr<CItemData> FUN_14053f870(int nItemId);

// The initData call of the movie root (a COMDAT-less AScript member of this unit).
// @0x141a730c0
Scaleform::GFx::Value AScript::Invoke(const char* szMethod, CString a1, CStringW a2, CStringW a3, CStringW a4, int a5, int a6)
{
    ASArgList args;
    args.FUN_1409b2800(6);
    FUN_1422bce70(args.FUN_1409b1f70(0), (const char*)a1);
    FUN_1422bcea0(args.FUN_1409b1f70(1), (const wchar_t*)a2);
    FUN_1422bcea0(args.FUN_1409b1f70(2), (const wchar_t*)a3);
    FUN_1422bcea0(args.FUN_1409b1f70(3), (const wchar_t*)a4);
    FUN_1422bccb0(args.FUN_1409b1f70(4), a5);
    FUN_1422bccb0(args.FUN_1409b1f70(5), a6);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x141a72480
UIObjectStoreDialog::UIObjectStoreDialog()
    : m_180(GetTypeName())
    , m_188(0)
{
    FUN_141924170(1);
    m_164 = 1;
}

// @0x141a72550
UIObjectStoreDialog::~UIObjectStoreDialog()
{
}

// @0x141a725e0
CString UIObjectStoreDialog::GetTypeName()
{
    return "ObjectStoreDialog";
}

// @0x141a72630
void UIObjectStoreDialog::vfunc_84(const CString& strKey, int nItemType)
{
    if (vfunc_55() == 0) {
        m_190 = strKey;
        m_198 = nItemType;
    }
}

// @0x141a72690
int UIObjectStoreDialog::vfunc_65()
{
    if (UIDialog::vfunc_65() == 0) {
        vfunc_68();
        if (UIDialog::vfunc_65() == 0)
            return 0;
    }
    return 1;
}

// @0x141a726e0
void UIObjectStoreDialog::vfunc_66()
{
    UIDialog::vfunc_66();
    UIInventoryDialog* pInv = FUN_1405344f0(0x4e2d);
    if (pInv != 0) {
        m_188 = pInv->vfunc_55() == 0 ? 1 : 0;
        if (m_188 == 0) {
            ASDialog* pDlg = dynamic_cast<ASDialog*>((AScript*)m_30);
            if (pDlg != 0) {
                Unk_OsUIMsg msg;
                msg.FUN_1422b82b0("openWindowPos");
                msg.FUN_1422b7f70(vfunc_48());
                pInv->OnMessage(this, &msg);
            }
        } else {
            FUN_141275c30(this, pInv, DAT_143b02320, DAT_143b02320);
        }
    }
}

// @0x141a72860
void UIObjectStoreDialog::vfunc_67()
{
    COutPacket packet(0x2e, 0);
    packet.vfunc_o10_1(7);
    packet.vfunc_o10_6(m_190);
    FUN_140710590(packet);
    FUN_140aa6d40()->FUN_141b0cd90(static_cast<UIStatusEventListener*>(this));
    FUN_14180b230(&m_180);
    UIDialog::vfunc_67();
    m_80 = 1;
    m_190 = "";
    m_198 = 0;
    FUN_141901390(1, vfunc_48());
}

// @0x141a729a0
int UIObjectStoreDialog::vfunc_54(void* pCfg)
{
    return UIDialog::vfunc_54(pCfg);
}

// @0x141a729d0
void UIObjectStoreDialog::OnLoadInit()
{
    UIObject::OnLoadInit();
    FUN_140aa6d40()->FUN_141b0cd00(static_cast<UIStatusEventListener*>(this));
    if (FUN_140de2860(&DAT_143ab2d80) == 0)
        FUN_140de2b50(&DAT_143ab2d80);
    FUN_141901390(0, vfunc_48());
}

// @0x141a72a60
void UIObjectStoreDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    if (m_30.get() != 0) {
        FUN_141a72f80(0);
        CStringW strName = GetStringTable()->FUN_141811980(1, m_198);
        CStringW strNum = FUN_140719a00(DAT_143ab28f8);
        int nSlots = 0;
        {
            MS2Ptr<CItemData> spItem = FUN_14053f870(m_198);
            if (spItem.get() != 0) {
                unsigned int nBankId = spItem->FUN_14053dce0();
                CBankTable::DataPtr spBank = TSingleton<CBankTable>::GetInstance()->GetBankData(nBankId);
                if (spBank.get() != 0)
                    nSlots = spBank->m_nSlotCount / 6;
            }
        }
        m_30->Invoke("initData", m_180, strNum, strName,
                     GetStringTable()->GetItemDescription(m_198, CString("functionDescription")), 1, nSlots);
    }
}

// @0x141a72d80
int UIObjectStoreDialog::OnMessage(UISwfEntity* pSender, UIMsg* pMsg)
{
    if (UIDialog::OnMessage(pSender, pMsg) != 0)
        return 1;
    return 0;
}

// @0x141a72dd0
int UIObjectStoreDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (_stricmp("OnSort", szMethod) == 0) {
        FUN_140de2bd0(&DAT_143ab2d80);
        return 1;
    }
    return 0;
}

// @0x141a72e50
int UIObjectStoreDialog::vfunc_oa0_1()
{
    if (vfunc_55() != 0)
        return 0;
    return 1;
}

// @0x141a72ea0
void UIObjectStoreDialog::vfunc_oa0_9(unsigned short a1)
{
    if (FUN_1422dc390() != 0) {
        Unk_OsSlotBag* pBag = FUN_14180b940(FUN_1422c8e90(m_180));
        if (pBag != 0)
            FUN_1422cca90(pBag);
    }
}

// @0x141a72f00
void UIObjectStoreDialog::vfunc_oa0_7(int a1, CStringW s)
{
    if (FUN_1422dc390() != 0) {
        Unk_OsSlotBag* pBag = FUN_14180b940(FUN_1422c8e90(m_180));
        if (pBag != 0)
            FUN_1422cca90(pBag);
    }
}

// @0x141a72f80
void UIObjectStoreDialog::FUN_141a72f80(int bBind)
{
    int nSlots = FUN_1408b6200(m_198);
    FUN_14180b230(&m_180);
    FUN_14180b170(&m_180, 0, nSlots);
    if (bBind != 0) {
        if (MS2Ptr<Unk_OsItemBag> spBag = GetChild<Unk_OsItemBag>("m_itemBag"))
            spBag->FUN_1407cba60("bagId", m_180);
    }
}
MS2_REPLACE_METHOD(0x141A725E0, UIObjectStoreDialog, GetTypeName, 61, 0x2433FD6F);
MS2_REPLACE_METHOD(0x141A72630, UIObjectStoreDialog, vfunc_84, 87, 0x3C22E54B);
MS2_REPLACE_METHOD(0x141A72690, UIObjectStoreDialog, vfunc_65, 70, 0x508246C9);
MS2_REPLACE_METHOD(0x141A726E0, UIObjectStoreDialog, vfunc_66, 370, 0x4CEE281C);
MS2_REPLACE_METHOD(0x141A72860, UIObjectStoreDialog, vfunc_67, 299, 0x447B5756);
MS2_REPLACE_METHOD(0x141A729A0, UIObjectStoreDialog, vfunc_54, 34, 0x8BFBDEE0);
MS2_REPLACE_METHOD(0x141A729D0, UIObjectStoreDialog, OnLoadInit, 133, 0x28B2AE05);
MS2_REPLACE_METHOD(0x141A72A60, UIObjectStoreDialog, OnLoadComplete, 787, 0x8A566F02);
MS2_REPLACE_METHOD(0x141A72D80, UIObjectStoreDialog, OnMessage, 60, 0x41DC81D8);
MS2_REPLACE_METHOD(0x141A72DD0, UIObjectStoreDialog, vfunc_28, 107, 0xF4DC82BC);
MS2_REPLACE_METHOD(0x141A72E50, UIObjectStoreDialog, vfunc_oa0_1, 69, 0x93DD6E81);
MS2_REPLACE_METHOD(0x141A72EA0, UIObjectStoreDialog, vfunc_oa0_9, 90, 0x304FDB38);
MS2_REPLACE_METHOD(0x141A72F00, UIObjectStoreDialog, vfunc_oa0_7, 115, 0xAA792801);
MS2_REPLACE_METHOD(0x141A72F80, UIObjectStoreDialog, FUN_141a72f80, 309, 0x242510C7);
