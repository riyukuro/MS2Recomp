// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Cube fitting doll window ("FittingDollDialog").
// MS2-UNIT: ?\uifittingdolldialog.cpp
// MS2-RANGE: 0x141933270-0x141935200 .text$mn
// MS2-RANGE: 0x140113330-0x1401135b0 .text$di
//
// Status: see progress/status.tsv. Callees that are not recovered yet are declared below ("unit-local
// placeholders") or in src/ms2/placeholder/; their names are Ghidra's (FUN_<va>) unless evident.
// MS2-GUESS-LOOKALIKES
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uifittingdolldialog.cpp"
#include "ms2/placeholder/ms2stdafx.h"

#include "uifittingdolldialog.h"

#include <atlcoll.h>
#include <efd/Point2.h>

#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asbutton.h"
#include "ms2/placeholder/astextfield.h"
#include "ms2/placeholder/cequipitem.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/fittingdollpc.h"
#include "ms2/placeholder/imessagelistener.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/unk_1402a9d70.h"

#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/client/ms2/inventory.h"
#include "ms2/client/ms2/uiservice.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/placeholder/uidialogeventdispatcher.h"
#include "ms2/client/ms2/equipment.h"
#include "ms2/placeholder/ascript.h"

// ---- unit-local placeholders (names invented; promote to src/ms2/placeholder/ when shared) ----

#include <egf/EntityID.h>   // B22: was class Unk_BuddyHandle (ctor 0x1401cd100 = egf::EntityID(efd::UInt64))

// The dialog movie's root (an ASDialog): "bagID" / "owner" are plain members of the movie, the drag events are methods.
class ASDialog : public ASDisplayObject
{
public:
};

// The inventory dialog (UI id 0x4e2d).
class Unk_FdInventory : public UIDialog
{
};
class UIInventoryDialog;
template<class T> T* Unk_BreakDialog(int);   // C3: was Unk_FdInventory* FUN_1405344f0 (calls cast back)

// The world / UI manager singletons.


// The item / dialog event registries.
class Unk_FdItemEvents;
class Unk_InventoryListener* GetItemEventDispatcher();   // C3: was GetItemEventDispatcher
class Unk_ItemEventSystem   // C3: member view for the former free stand-ins
{
public:
    void FUN_1419cae20(class UIItemEventListener*);
    void FUN_1419caeb0(class UIItemEventListener*);
};
class Unk_FdDlgEvents;

// The "openWindowPos" UI message.
typedef UIMsg Unk_LdUIMsg;

// The "m_transform" button.
template <> MS2Ptr<ASButton> UISwfEntity::GetChild<ASButton>(const CString& strName);   // 0x140bb4b10, owned by uiinventorydialog

// The player's inventory (global 0x143ab2a90) and the item behind a drag source.
extern Unk_Inventory g_143ab2a90;
namespace NotifyContext { class BindData; }
class MS2DragSlot;
MS2DragSlot* AsDragSlot(NotifyContext::BindData* p);   // C3: the real def (displayslot.cpp), TypeCast(0x6200023)
class InvenSlot   // C3: member view for the former free stand-ins
{
public:
    __int64 GetItemUid();
};

// The data of the doll's plot (global registry 0x143b059e8): the doll's record and its owner.
class Unk_FdPlot
{
public:
    char m_pad_0[0x50];
    int m_nKeyA;                                            // +0x50
    int m_nKeyB;                                            // +0x54
};
class Unk_FdPlotMgr {};
namespace egf { class ScriptContext; extern ScriptContext g_bapiContext; }
#define DAT_143b059e8 (*(char*)&egf::g_bapiContext)          // C3: was extern char DAT_143b059e8
#include "ms2/placeholder/scriptcontext.h"   // egf::ScriptContext g_bapiContext (was a local framework view)
// C3: FUN_1410b8c90 is the CubeMapInformationService member below (key by value, the exe builds it in an argument temp)
class CubeMapInformationService   // C3: member view for the former free stand-ins
{
public:
    __int64 GetOwnerId(int, int);
    class Cube* FUN_1410b8c90(egf::EntityID kId);
};

// The doll / player helpers.
class MyPC* GetMyPC(class Unk_QueryObj*);   // C3: was GetMyPC
class Unk_AkoFittingDoll   // C3: member view for the former free stand-ins
{
public:
    int FUN_140967160();
};
void CreateSlotBag(const CString& strDialog, int nHomeId, unsigned __int64 nDollId, bool bEquip);
void FUN_14121e760(const CString& strDialog);
void FUN_14121b840(int nError);                             // show the message of an error code
void FUN_141275c30(UISwfEntity* pLeft, UISwfEntity* pRight, efd::Point2 offLeft, efd::Point2 offRight);

// The equipment lists of the doll and of the player.
typedef ATL::CAtlList<MS2Ptr<CEquipItem> > Unk_FdEquipList;

// The message box machinery.
class CMsgBoxData : public CPtred
{
public:
    void SetCallback(Delegate<bool(int, const CMsgBoxData&)> cb);
    char m_pad[0x2a0 - 0x18];
};
MS2_CHECK_SIZE(CMsgBoxData, 0x2a0);
MS2Ptr<CMsgBoxData> FUN_140d73e40(int nType, int nStrId, void* p, CStringW tag);
void FUN_140d73c60(MS2Ptr<CMsgBoxData> box);

void FUN_140710590(COutPacket& packet);                     // send the packet
CString Name_14021c050(int nSlotType);                      // slot type -> slot name

extern __int64 DAT_143af25f0;                               // the id of the doll shown
extern int DAT_143af25f8;                                   // set after a fitting doll's equipment changed

// ---- dynamic initializers (.text$di) ----

// @0x140113330
static CString s_sortNames1[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};

// @0x1401133f0
static CString s_strSkill("skill");

// @0x140113420
static CString s_strStun("stun");

// @0x140113450
static egf::EntityID s_pointer(0);

// @0x140113470
static Unk_1402a9d70 s_condition(17, 0.75f, 0.25f, 2.25f, 10);

// @0x1401134c0
static CString s_sortNames2[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};

// @0x140113580
static UICommon::CMyPCKeyInputController s_keyInput;

// @0x141933270
UIFittingDollDialog::UIFittingDollDialog()
    : m_nTransforming(0)
{
    SetTweenEnabled(1);
    m_164 = 1;
}

// @0x141933340
CString UIFittingDollDialog::GetTypeName()
{
    return "FittingDollDialog";
}

// @0x141933390
void UIFittingDollDialog::SendFittingDoll()
{
    PC* pPlayer = reinterpret_cast<PC*>(reinterpret_cast<WorldService*>(WorldService::GetInstance())->GetLocalPlayer());
    if (pPlayer == 0)
        return;
    COutPacket packet(static_cast<int>(SendOp::FittingDoll), 0);
    packet.WriteUInt8(3);
    packet.WriteInt64(DAT_143af25f0);
    FUN_140710590(packet);
    if (MS2Ptr<ASButton> spButton = GetChild<ASButton>("m_transform"))
    {
        m_nTransforming = 1;
        spButton->SetEnabled(0);
    }
}

// @0x1419334b0
int UIFittingDollDialog::vfunc_65()
{
    if (UIDialog::vfunc_65() == 0)
        return 0;
    ((class UIDialogEventDispatcher*)(class Unk_FdDlgEvents*)(reinterpret_cast<Unk_FdDlgEvents*>(TSingleton<UIDialogEventDispatcher>::GetInstance())))->AddListener(static_cast<UIDialogEventListener*>(this));
    return 1;
}

// @0x141933510
void UIFittingDollDialog::vfunc_67()
{
    DAT_143af25f0 = 0;
    FUN_14121e760(GetTypeName());
    ((class Unk_ItemEventSystem*)(class Unk_FdItemEvents*)(((class Unk_FdItemEvents*)GetItemEventDispatcher())))->FUN_1419caeb0(static_cast<UIItemEventListener*>(this));
    ((class UIDialogEventDispatcher*)(class Unk_FdDlgEvents*)(reinterpret_cast<Unk_FdDlgEvents*>(TSingleton<UIDialogEventDispatcher>::GetInstance())))->RemoveListener(static_cast<UIDialogEventListener*>(this));
    UIDialog::vfunc_67();
}

// @0x1419335f0
void UIFittingDollDialog::vfunc_72()
{
    vfunc_55();
}

// @0x141933620
void UIFittingDollDialog::vfunc_dl_3(void* pSlot)
{
    void* pItemSlot = AsDragSlot(static_cast<NotifyContext::BindData*>(pSlot));
    if (pItemSlot != 0)
    {
        MS2Ptr<CItem> spItem = g_143ab2a90.FindItemByUid(((class InvenSlot*)(void*)(pItemSlot))->GetItemUid());
        if (spItem.get() != 0)
        {
            ASDialog* pDlg = dynamic_cast<ASDialog*>((AScript*)m_30);
            if (pDlg != 0)
                pDlg->Invoke("onDragStart", Name_14021c050(spItem->FUN_140526c30()));
        }
    }
}

// @0x141933740
void UIFittingDollDialog::vfunc_dl_4(void* p)
{
    ASDialog* pDlg = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDlg != 0)
        pDlg->Invoke("onDragEnd");
}

// @0x1419337c0
void UIFittingDollDialog::vfunc_66()
{
    UIDialog::vfunc_66();
    Unk_FdInventory* pInv = reinterpret_cast<Unk_FdInventory*>(Unk_BreakDialog<UIInventoryDialog>(0x4e2d));
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
        else
        {
            FUN_141275c30(this, pInv, efd::Point2::ZERO, efd::Point2::ZERO);
        }
    }
}

// @0x141933910
void UIFittingDollDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    ((class Unk_ItemEventSystem*)(class Unk_FdItemEvents*)(((class Unk_FdItemEvents*)GetItemEventDispatcher())))->FUN_1419cae20(static_cast<UIItemEventListener*>(this));
    SetDollInfo();
    FUN_141934070();
    if (TSingleton<CUIService>::GetInstance()->IsDialogClosed((eUIClassID)0x4e2d) != 0)
    {
        (((CUIService*)(TSingleton<CUIService>::GetInstance()))->OpenDialog((eUIClassID)(0x4e2d)));
    }
    else
    {
        Unk_FdInventory* pInv = reinterpret_cast<Unk_FdInventory*>(Unk_BreakDialog<UIInventoryDialog>(0x4e2d));
        if (pInv != 0)
            pInv->FUN_1422dc450();
    }
}

// @0x1419339d0
int UIFittingDollDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (_stricmp("OnTransform", szMethod) == 0)
    {
        PC* pPlayer = reinterpret_cast<PC*>(reinterpret_cast<WorldService*>(WorldService::GetInstance())->GetLocalPlayer());
        if (pPlayer == 0)
            return 0;
        int nResult = CanWearEquipment();
        if (nResult == 0)
            SendFittingDoll();
        else if (nResult != 0x16)
            FUN_14121b840(nResult);
        return 1;
    }
    return 0;
}

// @0x141933a90
void UIFittingDollDialog::vfunc_15()
{
    EnableTransformButton();
    if (DAT_143af25f8 != 0)
    {
        FUN_141934070();
        DAT_143af25f8 = 0;
    }
}

// @0x141933ad0
void UIFittingDollDialog::vfunc_33(int nClassId, int n)
{
    if (nClassId == 0x6200046)
        DAT_143af25f8 = 1;
}

// @0x141933b00
void UIFittingDollDialog::SetDollInfo()
{
    FittingDollPC* pDoll = ((class FittingDollPC*)GetMyPC((class Unk_QueryObj*)(reinterpret_cast<void*>(WorldService::GetInstance()->FUN_141bd1530(DAT_143af25f0)))));
    if (pDoll == 0)
        return;
    int nItemId = ((class Unk_AkoFittingDoll*)(class FittingDollPC*)(pDoll))->FUN_140967160();

    if (MS2Ptr<ASTextField> spName = GetChild<ASTextField>("m_name"))
        spName->SetTextW(TSingleton<CStringTable>::GetInstance()->FUN_141811980(1, nItemId));

    if (MS2Ptr<ASTextField> spDesc = GetChild<ASTextField>("m_desc"))
        spDesc->SetTextW(TSingleton<CStringTable>::GetInstance()->GetItemDescription(nItemId, CString("functionDescription")));

    if (MS2Ptr<ASMovieClip> spCharacter = GetChild<ASMovieClip>("m_character"))
    {
        CString strFrame;
        strFrame.AppendFormat("%s_%d", pDoll->FUN_14121c710() != 0 ? "skin" : "game", (unsigned)((class PC*)(class PC*)(pDoll))->GetGender());
        spCharacter->vfunc_13(strFrame);
    }

    if (MS2Ptr<ASMovieClip> spEquip = GetChild<ASMovieClip>("m_equip"))
    {
        CString strFrame;
        strFrame.AppendFormat("_%d", (unsigned)(pDoll->FUN_14121c710() != 0));
        spEquip->vfunc_13(strFrame);
    }

    if (MS2Ptr<ASMovieClip> spEmblem = GetChild<ASMovieClip>("m_emblem"))
    {
        CString strFrame;
        strFrame.AppendFormat("_%d", (unsigned)((class PC*)(class PC*)(pDoll))->GetGender());
        spEmblem->vfunc_13(strFrame);
    }
}

// @0x141934070
void UIFittingDollDialog::FUN_141934070()
{
    PC* pMe = reinterpret_cast<PC*>(reinterpret_cast<WorldService*>(WorldService::GetInstance())->GetLocalPlayer());
    if (pMe == 0)
        return;
    FittingDollPC* pDoll = ((class FittingDollPC*)GetMyPC((class Unk_QueryObj*)(reinterpret_cast<void*>(WorldService::GetInstance()->FUN_141bd1530(DAT_143af25f0)))));
    if (pDoll == 0)
        return;
    int bOwner = 0;
    Unk_FdPlotMgr* pMgr = ((class Unk_FdPlotMgr*)egf::g_bapiContext.GetSystemServiceAs<CubeMapInformationService>());
    Unk_FdPlot* pPlot = reinterpret_cast<Unk_FdPlot*>(((class CubeMapInformationService*)(class Unk_FdPlotMgr*)(pMgr))->FUN_1410b8c90(pDoll->GetEntityID()));
    if (pPlot != 0)
        bOwner = ((class CubeMapInformationService*)(class Unk_FdPlotMgr*)(pMgr))->GetOwnerId(pPlot->m_nKeyA, pPlot->m_nKeyB) == ((class PC*)(class PC*)(pMe))->GetAccountId();
    bool bEquip = pDoll->FUN_14121c710() == 1;
    CreateSlotBag(GetTypeName(), ((class GameObject*)(class PC*)(pMe))->GetObjectId(), DAT_143af25f0, bEquip);
    ASDialog* pDlg = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDlg != 0)
    {
        pDlg->SetStringMember("bagID", GetTypeName());
        reinterpret_cast<AScript*>(pDlg)->SetIntMember("owner", bOwner);
    }
}

// @0x1419342e0
void UIFittingDollDialog::FUN_1419342e0()
{
    FUN_14121e760(GetTypeName());
}

// @0x141934340
void UIFittingDollDialog::EnableTransformButton()
{
    if (m_nTransforming == 0)
        return;
    PC* pMe = reinterpret_cast<PC*>(reinterpret_cast<WorldService*>(WorldService::GetInstance())->GetLocalPlayer());
    if (pMe == 0)
        return;
    if (((class PCBase*)(class PC*)(pMe))->GetCurStateId() == 0x22)
        return;
    if (MS2Ptr<ASButton> spButton = GetChild<ASButton>("m_transform"))
    {
        m_nTransforming = 0;
        spButton->SetEnabled(1);
    }
}

// @0x141934430
int UIFittingDollDialog::CanWearEquipment()
{
    FittingDollPC* pDoll = ((class FittingDollPC*)GetMyPC((class Unk_QueryObj*)(reinterpret_cast<void*>(WorldService::GetInstance()->FUN_141bd1530(DAT_143af25f0)))));
    if (pDoll == 0)
        return 0xd;
    PC* pMe = reinterpret_cast<PC*>(reinterpret_cast<WorldService*>(WorldService::GetInstance())->GetLocalPlayer());
    if (pMe == 0)
        return 0xd;
    Unk_FdPlotMgr* pMgr = ((class Unk_FdPlotMgr*)egf::g_bapiContext.GetSystemServiceAs<CubeMapInformationService>());
    Unk_FdPlot* pPlot = reinterpret_cast<Unk_FdPlot*>(((class CubeMapInformationService*)(class Unk_FdPlotMgr*)(pMgr))->FUN_1410b8c90(pDoll->GetEntityID()));
    if (pPlot == 0)
        return 0xd;
    if (((class CubeMapInformationService*)(class Unk_FdPlotMgr*)(pMgr))->GetOwnerId(pPlot->m_nKeyA, pPlot->m_nKeyB) != ((class PC*)(class PC*)(pMe))->GetAccountId())
        return 2;

    Unk_FdEquipList list(10);
    reinterpret_cast<CEquipment*>(pDoll->GetEquipment())->CollectShownItems(list);
    bool bBound = false;
    for (POSITION pos = list.GetHeadPosition(); pos != 0; list.GetNext(pos))
    {
        MS2Ptr<CEquipItem> spEquip = list.GetAt(pos);
        bool bSkip = static_cast<bool>(spEquip->GetItem().get()) && reinterpret_cast<CItemData*>(spEquip->GetItem()->GetData())->FUN_14053d550();
        if (bSkip)
            continue;
        int nResult = pDoll->FUN_14121c870(list.GetAt(pos)->GetItem().get());
        if (nResult != 0)
            return nResult;
        void* pTransfer;
        void* pDead = pTransfer = spEquip->GetItem()->GetTransfer();
        if (pTransfer != 0 && ((class CItemTransfer*)(void*)(pTransfer))->HasBindingRule() != 0 && ((class CItemTransfer*)(void*)(pTransfer))->HasBinding() == 0)
            bBound = true;
    }
    list.RemoveAll();

    reinterpret_cast<CEquipment*>(pMe->GetEquipment())->FUN_1411e22c0(reinterpret_cast<ATL::CAtlList<MS2Ptr<CEquipItem> >&>(list), 1);
    int nType = pDoll->FUN_14121c710();
    for (POSITION pos = list.GetHeadPosition(); pos != 0; list.GetNext(pos))
    {
        MS2Ptr<CItem> spItem = list.GetAt(pos)->GetItem();
        if (nType != 0 && !reinterpret_cast<CItemData*>(spItem->GetData())->FUN_14053c810())
            continue;
        if (nType == 0 && !reinterpret_cast<CItemData*>(spItem->GetData())->FUN_14053c870())
            continue;
        if (spItem->HasSkin() != nType)
            continue;
        int nResult = pDoll->FUN_14121c910(list.GetAt(pos)->GetItem().get());
        if (nResult != 0)
            return nResult;
    }

    if (bBound)
    {
        {
            MS2Ptr<CMsgBoxData> spBox = FUN_140d73e40(1, 0x303, 0, CStringW(L""));
            if (spBox.get() != 0)
            {
                spBox->SetCallback(Delegate<bool(int, const CMsgBoxData&)>(this, &UIFittingDollDialog::OnConfirmTransform));
                FUN_140d73c60(spBox);
            }
        }
        return 0x16;
    }
    return 0;
}

// @0x141934c10
bool UIFittingDollDialog::OnConfirmTransform(int nResult, const CMsgBoxData& box)
{
    if (nResult == 0)
        SendFittingDoll();
    return true;
}

MS2_EMIT_CRT_MEMMOVE_S();
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cbdfa0-0x142cbe080 .text$yd
