// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Item lock / unlock window ("ItemLockDialog").
// MS2-UNIT: ?\uiitemlockdialog.cpp
// MS2-RANGE: 0x140f56ab0-0x140f58080 .text$mn
// MS2-RANGE: 0x1400e0020-0x1400e0110 .text$di
//
// Status: see progress/status.tsv. Callees that are not recovered yet are declared below ("unit-local
// placeholders") or in src/ms2/placeholder/; their names are Ghidra's (FUN_<va>) unless evident.
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiitemlockdialog.cpp"
#include "ms2/placeholder/ms2stdafx.h"

#include "uiitemlockdialog.h"

#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/clientconstants.h"
#include "ms2/placeholder/imessagelistener.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/client/ms2/uimessagebox.h"

#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local placeholders (names invented; promote to src/ms2/placeholder/ when shared) ----

class ASDialog : public ASDisplayObject
{
public:
    int FUN_1422c10a0();                                    // x
    float FUN_1422c1110();                                  // y
    void FUN_1422c00f0(float x, float y);                   // set the position
};

// The inventory dialog (UI id 0x4e2d).
class UIInventoryDialog : public UIDialog
{
public:
    void FUN_141999f60();
    void FUN_141999e00();
};
UIInventoryDialog* FUN_1405344f0(int nUiId);

// The item bag control of the movie: "bagId" names the bag shown.
class Unk_LdItemBag : public ASMovieClip
{
public:
    Unk_LdItemBag(const Scaleform::GFx::Value& v, int nMovieId);        // 0x1422cf330
#define LD_V(n) virtual void vfunc_##n();
    LD_V(16) LD_V(17) LD_V(18) LD_V(19) LD_V(20) LD_V(21) LD_V(22) LD_V(23)
#undef LD_V
    virtual void vfunc_24(int nShow);                                   // 24 (+0xc0) refresh
    void FUN_1407cba60(const char* szName, CString str);                // set the bag id
private:
    unsigned char m_pad_80[8];
};
MS2_CHECK_SIZE(Unk_LdItemBag, 0x88);

// A button of the movie ("m_lock" / "m_unLock").
class Unk_LdButton : public ASDisplayObject
{
public:
    Unk_LdButton(const Scaleform::GFx::Value& v, int nMovieId);
    void FUN_1422c1fe0(int bEnabled);                       // enable / disable
};

// The item lock manager (global 0x143aaf308, CItemLockManager of unit_1406125d0).
class Unk_LdLockMgr
{
public:
    void FUN_1406126f0();
    void FUN_140612780();
    int FUN_140612da0();                                    // any slot locked
    void FUN_140612e10();
    void FUN_1406132f0();
    int FUN_140614b50();                                    // the tab (0 lock, 1 unlock)
    char m_pad_0[0x48];
    int m_nTab;                                             // +0x48
};
extern Unk_LdLockMgr* DAT_143aaf308;
inline Unk_LdLockMgr* FUN_140535310() { return DAT_143aaf308; }

// The sound event sink (FUN_140d8ee90).
class Unk_LdSound { public: void FUN_140a1f970(const CString& strEvent, const CString& strArg); };
Unk_LdSound* FUN_140d8ee90();

// The item event registry (FUN_140a6a840).
class Unk_LdItemEvents;
Unk_LdItemEvents* FUN_140a6a840();
void FUN_1419cae20(Unk_LdItemEvents*, UIItemEventListener*);
void FUN_1419caeb0(Unk_LdItemEvents*, UIItemEventListener*);

// The "openWindowPos" UI message.
class Unk_LdUIMsg : public UIMsg
{
public:
    Unk_LdUIMsg();                                          // 0x1422e4490
    ~Unk_LdUIMsg();                                         // 0x140c30570
    void FUN_1422b82b0(const char* pszMethod);
    void FUN_1422b7f70(int n);
    void* m_pad[10];
};

// The message box machinery (unit_140d73aa0.cpp) and the string tables.
void FUN_140d73aa0(CStringW text, int nType, void* p, CStringW tag);
void FUN_14151f200();
class Unk_LdStringMgr { public: CStringW FUN_1422b0570(const CString& strKey); };
Unk_LdStringMgr* FUN_14025e7a0();
CStringW FUN_1401ceea0(const wchar_t* pszFormat, const int& nArg);

void FUN_140d42100(const CString& strName);
void FUN_140d42050(const CString& strName);
void FUN_141415600(const CString& strName);
void FUN_141415450(const CString& strName, MS2Ptr<CItem> spItem, int a, int b, int c);

void FUN_140f57f40(Unk_LdLockMgr* pMgr, int nTab);

// "itemlock_confirm" (message box tag) and the sort-type name table of the item header (only this part of the shared
// header statics is present in this unit's .text$di).
static CStringW s_strItemLockConfirm = L"itemlock_confirm";
static CString s_strSortTypeNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};

// @0x140f56ab0
UIItemLockDialog::UIItemLockDialog()
    : m_lstSlots(10)
{
    FUN_141924170(1);
    m_164 = 1;
}

// @0x140f56b90
UIItemLockDialog::~UIItemLockDialog()
{
}

// @0x140f56c30
CString UIItemLockDialog::vfunc_1()
{
    return "ItemLockDialog";
}

// @0x140f56c80
void UIItemLockDialog::FUN_140f56c80()
{
    FUN_140d42100(vfunc_1());
    FUN_140d42050(vfunc_1());
    if (MS2Ptr<Unk_LdItemBag> spBag = GetChild<Unk_LdItemBag>("m_itemBag"))
        spBag->FUN_1407cba60("bagId", vfunc_1());
    FUN_140f56e00();
}

// @0x140f56e00
void UIItemLockDialog::FUN_140f56e00()
{
    if (MS2Ptr<Unk_LdButton> spLock = GetChild<Unk_LdButton>("m_lock"))
        spLock->FUN_1422c1fe0(FUN_140535310()->FUN_140612da0());
    if (MS2Ptr<Unk_LdButton> spUnLock = GetChild<Unk_LdButton>("m_unLock"))
        spUnLock->FUN_1422c1fe0(FUN_140535310()->FUN_140612da0());
}

// @0x140f56f50
// MS2-FUNCTIONAL: the exe keeps three copies of the child-lookup result pointer (larger frame)
int UIItemLockDialog::FUN_140f56f50()
{
    if (m_30 == 0)
        return 0;
    MS2Ptr<ASMovieClip> spBag = m_30->FUN_1409b4560("m_itemBag");
    if (spBag.get() == 0)
        return 0;
    return spBag->FUN_1422bfca0();
}

// @0x140f57030
void UIItemLockDialog::OnLoadInit()
{
    UIObject::OnLoadInit();
    CString strArg("item_lock");
    CString strEvent("dialog_open");
    FUN_140d8ee90()->FUN_140a1f970(strEvent, strArg);
}

// @0x140f570b0
void UIItemLockDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    FUN_140f56c80();
    FUN_1419cae20(FUN_140a6a840(), static_cast<UIItemEventListener*>(this));
    FUN_140f57f40(FUN_140535310(), 0);
    FUN_140535310()->FUN_1406126f0();
    UIInventoryDialog* pInv = FUN_1405344f0(0x4e2d);
    if (pInv != 0)
    {
        pInv->FUN_141999f60();
        pInv->FUN_141999e00();
    }
}

// @0x140f57160
void UIItemLockDialog::vfunc_26()
{
    UIDialog::vfunc_26();
    UIInventoryDialog* pInv = FUN_1405344f0(0x4e2d);
    if (pInv != 0)
    {
        pInv->FUN_141999f60();
        pInv->FUN_141999e00();
    }
    FUN_140d42100(vfunc_1());
}

// @0x140f571f0
void UIItemLockDialog::vfunc_67()
{
    UIDialog::vfunc_67();
    FUN_140f57e30();
    FUN_1419caeb0(FUN_140a6a840(), static_cast<UIItemEventListener*>(this));
    FUN_140535310()->FUN_140612780();
    CString strArg("item_lock");
    CString strEvent("dialog_close");
    FUN_140d8ee90()->FUN_140a1f970(strEvent, strArg);
}

// @0x140f572c0
void UIItemLockDialog::vfunc_45(Scaleform::GFx::Value* pRetVal, const CString& strMethod, ASData* pArgs)
{
}

// @0x140f572e0
// MS2-FUNCTIONAL: message box text/tag temporaries are built with extra pointer copies in the exe (frame 0x1d8 vs 0x1e8)
int UIItemLockDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (_stricmp(szMethod, "OnItemLock") == 0)
    {
        if (FUN_140535310()->FUN_140612da0() != 0)
        {
            if (FUN_140535310()->FUN_140614b50() == 0)
            {
                FUN_140d73aa0(s_strItemLockConfirm, 0x21, 0, L"");
            }
            else if (FUN_140535310()->FUN_140614b50() == 1)
            {
                CStringW strMsg = FUN_14025e7a0()->FUN_1422b0570("$s_itemlock_msgbox_unlock_confirm");
                int nSeconds = (int)*FUN_1401d3200()->ItemUnLockTime.Get();
                int nHours = nSeconds / 0xe10;
                strMsg = FUN_1401ceea0(strMsg, nHours);
                FUN_140d73aa0(strMsg, 1, static_cast<IMessageListener*>(this), L"");
            }
            return 1;
        }
    }
    else if (_stricmp(szMethod, "OnItemUnLock") == 0)
    {
        if (FUN_140535310()->FUN_140612da0() != 0)
        {
            if (FUN_140535310()->FUN_140614b50() == 0)
            {
                FUN_140d73aa0(s_strItemLockConfirm, 0x21, 0, L"");
            }
            else if (FUN_140535310()->FUN_140614b50() == 1)
            {
                CStringW strMsg = FUN_14025e7a0()->FUN_1422b0570("$s_itemlock_msgbox_unlock_confirm");
                int nSeconds = (int)*FUN_1401d3200()->ItemUnLockTime.Get();
                int nHours = nSeconds / 0xe10;
                strMsg = FUN_1401ceea0(strMsg, nHours);
                FUN_140d73aa0(strMsg, 1, static_cast<IMessageListener*>(this), L"");
            }
            return 1;
        }
    }
    else if (_stricmp(szMethod, "OnChangeTab") == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
        {
            int nTab = data.FUN_1422b8a10();
            if (FUN_140535310()->FUN_140612da0() != 0)
            {
                FUN_140535310()->FUN_140612780();
                FUN_140f56c80();
            }
            FUN_140f57f40(FUN_140535310(), nTab);
            UIInventoryDialog* pInv = FUN_1405344f0(0x4e2d);
            if (pInv != 0 && pInv->vfunc_55() == 0)
                pInv->FUN_141999e00();
        }
    }
    return 0;
}

// @0x140f578f0
void UIItemLockDialog::vfunc_66()
{
    UIDialog::vfunc_66();
    UIInventoryDialog* pInv = FUN_1405344f0(0x4e2d);
    if (pInv != 0)
    {
        if (pInv->vfunc_55() != 0)
        {
            ASDialog* pDlg = dynamic_cast<ASDialog*>((AScript*)m_30);
            if (pDlg != 0)
            {
                Unk_LdUIMsg msg;
                msg.FUN_1422b82b0("openWindowPos");
                msg.FUN_1422b7f70(vfunc_48());
                pInv->OnMessage(this, &msg);
            }
        }
    }
}

// @0x140f57a20 (IMessageListener::OnMessage)
int UIItemLockDialog::OnMessage(UISwfEntity* pSender, UIMsg* pMsg)
{
    if (pMsg->FUN_1422e4520() == 0)
    {
        if (dynamic_cast<UIMessageBox*>(pSender) != 0)
        {
            int nResult = pMsg->FUN_1422b8a10();
            if (nResult == 0)
                FUN_140535310()->FUN_140612e10();
        }
        FUN_14151f200();
        return 1;
    }
    return 0;
}

// @0x140f57ab0
// MS2-FUNCTIONAL: the exe keeps the first dynamic_cast result in a second slot (copied after the cast)
void UIItemLockDialog::vfunc_43()
{
    UIInventoryDialog* pInv = FUN_1405344f0(0x4e2d);
    if (pInv != 0 && pInv->FUN_141924630() != 0)
    {
        float fX = 0.0f;
        float fY = 0.0f;
        {
            ASDialog* pInvDlg = dynamic_cast<ASDialog*>((AScript*)pInv->FUN_1422dba00());
            if (pInvDlg != 0)
            {
                fX = (float)pInvDlg->FUN_1422c10a0();
                fY = pInvDlg->FUN_1422c1110();
            }
        }
        ASDialog* pDlg = dynamic_cast<ASDialog*>((AScript*)m_30);
        if (pDlg != 0)
        {
            int nWidth = pDlg->FUN_1422c1340();
            pDlg->FUN_1422c00f0(fX - (float)nWidth, fY);
            return;
        }
    }
    UIDialog::vfunc_43();
}

// @0x140f57c20
void UIItemLockDialog::vfunc_15()
{
    if (vfunc_55() != 0)
    {
    }
    else
        FUN_140535310()->FUN_1406132f0();
}

// @0x140f57c60
CString UIItemLockDialog::FUN_140f57c60(unsigned nItemId, int nRarity)
{
    CItem* pItem = new CItem;
    if (pItem->FUN_140523c40(nItemId, nRarity, 0))
    {
        CString strName;
        strName.Format("%s_%d", (const char*)vfunc_1(), nItemId);
        FUN_141415450(strName, MS2Ptr<CItem>(pItem), 0, 0x401, 0);
        m_lstSlots.AddTail(strName);
        return strName;
    }
    return "";
}

// @0x140f57e30
void UIItemLockDialog::FUN_140f57e30()
{
    for (POSITION pos = m_lstSlots.GetHeadPosition(); pos != 0; m_lstSlots.GetNext(pos))
    {
        CString strName = m_lstSlots.GetAt(pos);
        FUN_141415600(strName);
    }
    m_lstSlots.RemoveAll();
}

// @0x140f57f40
void FUN_140f57f40(Unk_LdLockMgr* pMgr, int nTab)
{
    pMgr->m_nTab = nTab;
}

MS2_EMIT_CRT_MEMMOVE_S();
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca9af0-0x142ca9b40 .text$yd
