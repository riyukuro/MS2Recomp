// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Object store bag window ("ObjectStoreDialog").
// MS2-UNIT: ?\uiobjectstoredialog.cpp
// MS2-RANGE: 0x141a72480-0x141a732e0 .text$mn
//
// Status: see progress/status.tsv. Callees that are not recovered yet are declared below ("unit-local
// placeholders") or in src/ms2/placeholder/; their names are Ghidra's (FUN_<va>) unless evident.
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiobjectstoredialog.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/astilelist.h"

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
#include "ms2/placeholder/uistatuseventdispatcher.h"

// ---- unit-local placeholders (names invented; promote to src/ms2/placeholder/ when shared) ----

class ASDialog : public ASDisplayObject { };

// The inventory dialog (UI id 0x4e2d): the store window is placed next to it.
class UIInventoryDialog : public UIDialog { };
template<class T> T* Unk_BreakDialog(int);   // C3: was FUN_1405344f0

// The UI message ("openWindowPos"): an ActionScript call (ASData + type, 0x50 bytes).
typedef UIMsg Unk_OsUIMsg;

// The status-listener registry (singleton 0x140aa6d40).


// The bound slot bag of a bag id (StoreSlotBag) and the control state it keeps.
class Unk_OsBind;
class Unk_OsSlotBag;
namespace NotifyContext { class BindData; } class StoreSlotBag* FUN_14180b940(NotifyContext::BindData* pBind);                        // the slot bag of it (NULL when unbound)
class DragSlotBag   // C3: member view for the former free stand-ins
{
public:
    void FUN_1422cca90();
};
void FUN_14180b230(const CString& strBagId);                                    // drop the bag bound to the id
void FUN_14180b170(const CString& strBagId, int nSlot, int nSize);              // create the bag (StoreSlotBag)
int FUN_1408b6200(int nItemType);                                       // the slot count of an item type's bank

// The object store state (global 0x143ab2d80): the sort button sends packet 0x18 / 8.
#include "ms2/client/ms2/store.h"     // DAT_143ab2d80, the store table (CStore)
#include "ms2/gfxui/notifyhandler.h"   // C3: Unk_NotifyContext::FUN_1422c8e90/f10/f70

// The item amount shown ("current count" global 0x143ab28f8).
extern __int64 DAT_143ab28f8;
CStringW FUN_140719a00(__int64 n);

void FUN_141275c30(UISwfEntity* pLeft, UISwfEntity* pRight, efd::Point2 offLeft, efd::Point2 offRight);

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
    args.resize(6);
    FUN_1422bce70(&args[0], (const char*)a1);
    FUN_1422bcea0(&args[1], (const wchar_t*)a2);
    FUN_1422bcea0(&args[2], (const wchar_t*)a3);
    FUN_1422bcea0(&args[3], (const wchar_t*)a4);
    FUN_1422bccb0(&args[4], a5);
    FUN_1422bccb0(&args[5], a6);
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
    UIInventoryDialog* pInv = Unk_BreakDialog<UIInventoryDialog>(0x4e2d);
    if (pInv != 0) {
        m_188 = pInv->vfunc_55() == 0 ? 1 : 0;
        if (m_188 == 0) {
            ASDialog* pDlg = dynamic_cast<ASDialog*>((AScript*)m_30);
            if (pDlg != 0) {
                Unk_OsUIMsg msg;
                msg.AddString("openWindowPos");
                msg.AddInt(vfunc_48());
                pInv->OnMessage(this, &msg);
            }
        } else {
            FUN_141275c30(this, pInv, efd::Point2::ZERO, efd::Point2::ZERO);
        }
    }
}

// @0x141a72860
void UIObjectStoreDialog::vfunc_67()
{
    COutPacket packet(static_cast<int>(SendOp::FunctionCube), 0);
    packet.WriteUInt8(7);
    packet.WriteUnicodeStringA(m_190);
    FUN_140710590(packet);
    ((class UIStatusEventDispatcher*)TSingleton<UIStatusEventDispatcher>::GetInstance())->FUN_141b0cd90(static_cast<UIStatusEventListener*>(this));
    FUN_14180b230(m_180);
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
    ((class UIStatusEventDispatcher*)TSingleton<UIStatusEventDispatcher>::GetInstance())->FUN_141b0cd00(static_cast<UIStatusEventListener*>(this));
    if (DAT_143ab2d80.Ready() == 0)
        DAT_143ab2d80.RequestLoad();
    FUN_141901390(0, vfunc_48());
}

// @0x141a72a60
void UIObjectStoreDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    if (m_30.get() != 0) {
        FUN_141a72f80(0);
        CStringW strName = TSingleton<CStringTable>::GetInstance()->FUN_141811980(1, m_198);
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
                     TSingleton<CStringTable>::GetInstance()->GetItemDescription(m_198, CString("functionDescription")), 1, nSlots);
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
        DAT_143ab2d80.RequestClose();
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
        Unk_OsSlotBag* pBag = (Unk_OsSlotBag*)FUN_14180b940(Unk_NotifyContext::FUN_1422c8e90(m_180));
        if (pBag != 0)
            ((class DragSlotBag*)(class Unk_OsSlotBag*)(pBag))->FUN_1422cca90();
    }
}

// @0x141a72f00
void UIObjectStoreDialog::vfunc_oa0_7(int a1, CStringW s)
{
    if (FUN_1422dc390() != 0) {
        Unk_OsSlotBag* pBag = (Unk_OsSlotBag*)FUN_14180b940(Unk_NotifyContext::FUN_1422c8e90(m_180));
        if (pBag != 0)
            ((class DragSlotBag*)(class Unk_OsSlotBag*)(pBag))->FUN_1422cca90();
    }
}

// @0x141a72f80
void UIObjectStoreDialog::FUN_141a72f80(int bBind)
{
    int nSlots = FUN_1408b6200(m_198);
    FUN_14180b230(m_180);
    FUN_14180b170(m_180, 0, nSlots);
    if (bBind != 0) {
        if (MS2Ptr<ASTileList> spBag = GetChild<ASTileList>("m_itemBag"))
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
