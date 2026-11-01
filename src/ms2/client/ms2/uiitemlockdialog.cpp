// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Item lock / unlock window ("ItemLockDialog").
// MS2-UNIT: ?\uiitemlockdialog.cpp
// MS2-RANGE: 0x140f56ab0-0x140f58080 .text$mn
// MS2-RANGE: 0x1400e0020-0x1400e0110 .text$di
//
// Status: see progress/status.tsv. Callees that are not recovered yet are declared below ("unit-local
// placeholders") or in src/ms2/placeholder/; their names are Ghidra's (FUN_<va>) unless evident.
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiitemlockdialog.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/astilelist.h"

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
#include "ms2/client/ms2/bigdatalogsystem.h"
#include "ms2/ms2format.h"   // C3: StringFormat<int> (was FUN_1401ceea0)

// ---- unit-local placeholders (names invented; promote to src/ms2/placeholder/ when shared) ----

class ASDialog : public ASDisplayObject
{
};

// The inventory dialog (UI id 0x4e2d).
class UIInventoryDialog : public UIDialog
{
public:
    void FUN_141999f60();
    void FUN_141999e00();
};
template<class T> T* Unk_BreakDialog(int);   // C3: was FUN_1405344f0


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
    char m_pad_0[0x48];
    int m_nTab;                                             // +0x48
};
// C3: the real members of CItemLockManager (unit_1406125d0.h redefines this unit's dialog classes, so a local view).
enum Unk_LockMode : int;
class CItemLockManager
{
public:
    void SendRequestItemLockMode0();
    void FUN_140612780();
    int FUN_140612da0();                                    // any slot locked
    int SendRequestItemLockMode3();
    void FUN_1406132f0();
    Unk_LockMode GetMode() const;                           // the tab (0 lock, 1 unlock)
};
extern Unk_LdLockMgr* DAT_143aaf308;
inline Unk_LdLockMgr* FUN_140535310() { return DAT_143aaf308; }

// The sound event sink (TSingleton<CBigDataLogSystem>::GetInstance).

// The item event registry (FUN_140a6a840).
class Unk_LdItemEvents;
class Unk_InventoryListener* FUN_140a6a840();   // C3: was FUN_140a6a840
class Unk_ItemEventSystem   // C3: member view for the former free stand-ins
{
public:
    void FUN_1419cae20(class UIItemEventListener*);
    void FUN_1419caeb0(class UIItemEventListener*);
};

// The "openWindowPos" UI message.
typedef UIMsg Unk_LdUIMsg;

// The message box machinery (unit_140d73aa0.cpp) and the string tables.
void FUN_140d73aa0(CStringW text, int nType, void* p, CStringW tag);
void FUN_14151f200();
class GFxManager { public: CStringW FUN_1422b0570(const CString& strKey); };   // C3: the real member (0x1422b0570, a $-key's localized string)
class Unk_AltStringMgr* FUN_14025e7a0();   // C3: the GFxManager (calls cast back)

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
CString UIItemLockDialog::GetTypeName()
{
    return "ItemLockDialog";
}

// @0x140f56c80
void UIItemLockDialog::FUN_140f56c80()
{
    FUN_140d42100(GetTypeName());
    FUN_140d42050(GetTypeName());
    if (MS2Ptr<ASTileList> spBag = GetChild<ASTileList>("m_itemBag"))
        spBag->FUN_1407cba60("bagId", GetTypeName());
    FUN_140f56e00();
}

// @0x140f56e00
void UIItemLockDialog::FUN_140f56e00()
{
    if (MS2Ptr<Unk_LdButton> spLock = GetChild<Unk_LdButton>("m_lock"))
        spLock->FUN_1422c1fe0(reinterpret_cast<CItemLockManager*>(FUN_140535310())->FUN_140612da0());
    if (MS2Ptr<Unk_LdButton> spUnLock = GetChild<Unk_LdButton>("m_unLock"))
        spUnLock->FUN_1422c1fe0(reinterpret_cast<CItemLockManager*>(FUN_140535310())->FUN_140612da0());
}

// @0x140f56f50
int UIItemLockDialog::FUN_140f56f50()
{
    if (m_30 == 0)
        return 0;
    if (MS2Ptr<ASMovieClip> spBag = m_30->FUN_1409b4560("m_itemBag"))
        return spBag->FUN_1422bfca0();
    return 0;
}

// @0x140f57030
void UIItemLockDialog::OnLoadInit()
{
    UIObject::OnLoadInit();
    CString strArg("item_lock");
    CString strEvent("dialog_open");
    TSingleton<CBigDataLogSystem>::GetInstance()->SendLog(strEvent, strArg);
}

// @0x140f570b0
void UIItemLockDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    FUN_140f56c80();
    ((class Unk_ItemEventSystem*)(class Unk_LdItemEvents*)(((class Unk_LdItemEvents*)FUN_140a6a840())))->FUN_1419cae20(static_cast<UIItemEventListener*>(this));
    FUN_140f57f40(FUN_140535310(), 0);
    reinterpret_cast<CItemLockManager*>(FUN_140535310())->SendRequestItemLockMode0();
    UIInventoryDialog* pInv = Unk_BreakDialog<UIInventoryDialog>(0x4e2d);
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
    UIInventoryDialog* pInv = Unk_BreakDialog<UIInventoryDialog>(0x4e2d);
    if (pInv != 0)
    {
        pInv->FUN_141999f60();
        pInv->FUN_141999e00();
    }
    FUN_140d42100(GetTypeName());
}

// @0x140f571f0
void UIItemLockDialog::vfunc_67()
{
    UIDialog::vfunc_67();
    FUN_140f57e30();
    ((class Unk_ItemEventSystem*)(class Unk_LdItemEvents*)(((class Unk_LdItemEvents*)FUN_140a6a840())))->FUN_1419caeb0(static_cast<UIItemEventListener*>(this));
    reinterpret_cast<CItemLockManager*>(FUN_140535310())->FUN_140612780();
    CString strArg("item_lock");
    CString strEvent("dialog_close");
    TSingleton<CBigDataLogSystem>::GetInstance()->SendLog(strEvent, strArg);
}

// @0x140f572c0
void UIItemLockDialog::vfunc_45(Scaleform::GFx::Value* pRetVal, const CString& strMethod, ASData* pArgs)
{
}

// @0x140f572e0
int UIItemLockDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (_stricmp(szMethod, "OnItemLock") == 0)
    {
        if (reinterpret_cast<CItemLockManager*>(FUN_140535310())->FUN_140612da0() != 0)
        {
            if (reinterpret_cast<CItemLockManager*>(FUN_140535310())->GetMode() == 0)
            {
                FUN_140d73aa0(L"", 0x21, 0, s_strItemLockConfirm);
            }
            else if (reinterpret_cast<CItemLockManager*>(FUN_140535310())->GetMode() == 1)
            {
                CStringW strMsg = reinterpret_cast<GFxManager*>(FUN_14025e7a0())->FUN_1422b0570("$s_itemlock_msgbox_unlock_confirm");
                int nHours = (int)*FUN_1401d3200()->ItemUnLockTime.Get();
                nHours = nHours / 0xe10;
                strMsg = StringFormat<int>(strMsg, nHours);
                FUN_140d73aa0(strMsg, 1, static_cast<IMessageListener*>(this), L"");
            }
            return 1;
        }
    }
    else if (_stricmp(szMethod, "OnItemUnLock") == 0)
    {
        if (reinterpret_cast<CItemLockManager*>(FUN_140535310())->FUN_140612da0() != 0)
        {
            if (reinterpret_cast<CItemLockManager*>(FUN_140535310())->GetMode() == 0)
            {
                FUN_140d73aa0(L"", 0x21, 0, s_strItemLockConfirm);
            }
            else if (reinterpret_cast<CItemLockManager*>(FUN_140535310())->GetMode() == 1)
            {
                CStringW strMsg = reinterpret_cast<GFxManager*>(FUN_14025e7a0())->FUN_1422b0570("$s_itemlock_msgbox_unlock_confirm");
                int nHours = (int)*FUN_1401d3200()->ItemUnLockTime.Get();
                nHours = nHours / 0xe10;
                strMsg = StringFormat<int>(strMsg, nHours);
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
            if (reinterpret_cast<CItemLockManager*>(FUN_140535310())->FUN_140612da0() != 0)
            {
                reinterpret_cast<CItemLockManager*>(FUN_140535310())->FUN_140612780();
                FUN_140f56c80();
            }
            FUN_140f57f40(FUN_140535310(), nTab);
            UIInventoryDialog* pInv = Unk_BreakDialog<UIInventoryDialog>(0x4e2d);
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
    UIInventoryDialog* pInv = Unk_BreakDialog<UIInventoryDialog>(0x4e2d);
    if (pInv != 0)
    {
        if (pInv->vfunc_55() != 0)
        {
            ASDialog* pDlg = dynamic_cast<ASDialog*>((AScript*)m_30);
            if (pDlg != 0)
            {
                Unk_LdUIMsg msg;
                msg.AddString("openWindowPos");
                msg.AddInt(vfunc_48());
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
                reinterpret_cast<CItemLockManager*>(FUN_140535310())->SendRequestItemLockMode3();
        }
        FUN_14151f200();
        return 1;
    }
    return 0;
}

// @0x140f57ab0
void UIItemLockDialog::vfunc_43()
{
    UIInventoryDialog* pInv = Unk_BreakDialog<UIInventoryDialog>(0x4e2d);
    if (pInv != 0 && pInv->FUN_141924630() != 0)
    {
        float fX = 0.0f;
        float fY = 0.0f;
        {
            if (ASDialog* pInvDlg = dynamic_cast<ASDialog*>((AScript*)pInv->FUN_1422dba00()))
            {
                fX = pInvDlg->FUN_1422c10a0();
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
        reinterpret_cast<CItemLockManager*>(FUN_140535310())->FUN_1406132f0();
}

// @0x140f57c60
CString UIItemLockDialog::FUN_140f57c60(unsigned nItemId, int nRarity)
{
    CItem* pItem = new CItem;
    if (pItem->FUN_140523c40(nItemId, nRarity, 0))
    {
        CString strName;
        strName.Format("%s_%d", (const char*)GetTypeName(), nItemId);
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
