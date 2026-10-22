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

#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asdisplayobject.h"
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

// ---- unit-local placeholders (names invented; promote to src/ms2/placeholder/ when shared) ----

class Unk_1401cd100 { public: Unk_1401cd100(void*); private: void* m_p; };

// The dialog movie's root (an ASDialog): "bagID" / "owner" are plain members of the movie, the drag events are methods.
class ASDialog : public ASDisplayObject
{
public:
    void FUN_1407cba60(const char* szName, CString str);    // set a string member
    void FUN_1407cb9c0(const char* szName, bool b);         // set a bool member
};

// The inventory dialog (UI id 0x4e2d).
class Unk_FdInventory : public UIDialog
{
};
Unk_FdInventory* FUN_1405344f0(int nUiId);

// The world / UI manager singletons.
class Unk_FdWorld
{
public:
    PC* FUN_141bd0cc0();                                    // the local player
    void* FUN_141bd1530(__int64 nId);                       // the actor of an id
};
Unk_FdWorld* FUN_1403ed2d0();

class Unk_FdUiMgr
{
public:
    int FUN_141adc940(int nUiId);                           // the UI object is registered
    void FUN_141adc530(int nUiId);                          // open the UI object
};
Unk_FdUiMgr* FUN_1403ed2b0();

// The item / dialog event registries.
class Unk_FdItemEvents;
Unk_FdItemEvents* FUN_140a6a840();
void FUN_1419cae20(Unk_FdItemEvents*, UIItemEventListener*);
void FUN_1419caeb0(Unk_FdItemEvents*, UIItemEventListener*);
class Unk_FdDlgEvents;
Unk_FdDlgEvents* FUN_14140ea40();
void FUN_141928050(Unk_FdDlgEvents*, UIDialogEventListener*);
void FUN_1419280e0(Unk_FdDlgEvents*, UIDialogEventListener*);

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

// A button of the movie ("m_transform").
class Unk_LdButton : public ASDisplayObject
{
public:
    Unk_LdButton(const Scaleform::GFx::Value& v, int nMovieId);
    void FUN_1422c1fe0(int bEnabled);                       // enable / disable
};

// The player's inventory (global 0x143ab2a90) and the item behind a drag source.
class Unk_FdInventoryItems { public: MS2Ptr<CItem> FUN_140a5d680(__int64 nItemUid); };
extern Unk_FdInventoryItems DAT_143ab2a90;
void* FUN_140a50b50(void* pSlot);                           // the item slot behind a drag source
__int64 FUN_141405a10(void* pItemSlot);                     // its item uid

// The data of the doll's plot (global registry 0x143b059e8): the doll's record and its owner.
class Unk_FdPlot
{
public:
    char m_pad_0[0x50];
    int m_nKeyA;                                            // +0x50
    int m_nKeyB;                                            // +0x54
};
class Unk_FdPlotMgr {};
extern char DAT_143b059e8;
Unk_FdPlotMgr* FUN_1401cd040(void* pRegistry);
void* FUN_14123c460(FittingDollPC* pDoll, void* pOut);
Unk_FdPlot* FUN_1410b8c90(Unk_FdPlotMgr* pMgr, void* pKey);
__int64 FUN_1410c8030(Unk_FdPlotMgr* pMgr, int nA, int nB);

// The doll / player helpers.
FittingDollPC* FUN_140884db0(void* pActor);                 // efd::DynamicCast<FittingDollPC>
int FUN_140967160(FittingDollPC* pDoll);                    // the doll's item id
int FUN_141658e60(PC* pPC);                                 // the player's gender / model
__int64 FUN_141656ad0(PC* pPC);                             // the owner id of the player's plot
int FUN_14123c580(PC* pPC);                                 // the player's home id
int FUN_14166c930(PC* pPC);                                 // the action id
void FUN_14121e670(const CString& strDialog, int nHomeId, __int64 nDollId, bool bEquip);
void FUN_14121e760(const CString& strDialog);
void FUN_14121b840(int nError);                             // show the message of an error code
struct Unk_PickXY { float x, y; };                            // dialog offset
extern Unk_PickXY DAT_143b02320;                              // zero offset
void FUN_141275c30(UISwfEntity* pLeft, UISwfEntity* pRight, Unk_PickXY offLeft, Unk_PickXY offRight);

// The equipment lists of the doll and of the player.
typedef ATL::CAtlList<MS2Ptr<CEquipItem> > Unk_FdEquipList;
void FUN_1411e1b80(Unk_PCEquipSet* pSet, Unk_FdEquipList* pList);
void FUN_1411e22c0(Unk_PCEquipSet* pSet, Unk_FdEquipList* pList, int n);
unsigned FUN_140635100(void* pItemTransfer);                // m_nRule & 8
int FUN_140635120(void* pItemTransfer);                     // has a binding

// The message box machinery.
class CMsgBoxData : public CPtred
{
public:
    void FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)> cb);
    char m_pad[0x2a0 - 0x18];
};
MS2_CHECK_SIZE(CMsgBoxData, 0x2a0);
MS2Ptr<CMsgBoxData> FUN_140d73e40(int nType, int nStrId, void* p, CStringW tag);
void FUN_140d73c60(MS2Ptr<CMsgBoxData> box);

void FUN_140710590(COutPacket& packet);                     // send the packet
CStringTable* FUN_1401a9d70();
CString FUN_14021c050(int nSlotType);                       // slot type -> slot name

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
static Unk_1401cd100 s_pointer(NULL);

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
    FUN_141924170(1);
    m_164 = 1;
}

// @0x141934eb0
UIFittingDollDialog::~UIFittingDollDialog()
{
}

// @0x141933340
CString UIFittingDollDialog::vfunc_1()
{
    return "FittingDollDialog";
}

// @0x141933390
void UIFittingDollDialog::SendFittingDoll()
{
    if (FUN_1403ed2d0()->FUN_141bd0cc0() != 0)
    {
        COutPacket packet(0x42, 0);
        packet.vfunc_o10_1(3);
        packet.vfunc_o10_4(DAT_143af25f0);
        FUN_140710590(packet);
        MS2Ptr<Unk_LdButton> spButton = GetChild<Unk_LdButton>("m_transform");
        if (spButton.get() != 0)
        {
            m_nTransforming = 1;
            spButton->FUN_1422c1fe0(0);
        }
    }
}

// @0x1419334b0
int UIFittingDollDialog::vfunc_65()
{
    if (UIDialog::vfunc_65() == 0)
        return 0;
    FUN_141928050(FUN_14140ea40(), static_cast<UIDialogEventListener*>(this));
    return 1;
}

// @0x141933510
void UIFittingDollDialog::vfunc_67()
{
    DAT_143af25f0 = 0;
    FUN_14121e760(vfunc_1());
    FUN_1419caeb0(FUN_140a6a840(), static_cast<UIItemEventListener*>(this));
    FUN_1419280e0(FUN_14140ea40(), static_cast<UIDialogEventListener*>(this));
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
    void* pItemSlot = FUN_140a50b50(pSlot);
    if (pItemSlot != 0)
    {
        MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(FUN_141405a10(pItemSlot));
        if (spItem.get() != 0)
        {
            ASDialog* pDlg = dynamic_cast<ASDialog*>((AScript*)m_30);
            if (pDlg != 0)
                pDlg->Invoke("onDragStart", FUN_14021c050(spItem->FUN_140526c30()));
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
    Unk_FdInventory* pInv = FUN_1405344f0(0x4e2d);
    if (pInv != 0)
    {
        if (pInv->vfunc_55() == 0)
        {
            FUN_141275c30(this, pInv, DAT_143b02320, DAT_143b02320);
        }
        else
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

// @0x141933910
void UIFittingDollDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    FUN_1419cae20(FUN_140a6a840(), static_cast<UIItemEventListener*>(this));
    FUN_141933b00();
    FUN_141934070();
    if (FUN_1403ed2b0()->FUN_141adc940(0x4e2d) == 0)
    {
        Unk_FdInventory* pInv = FUN_1405344f0(0x4e2d);
        if (pInv != 0)
            pInv->FUN_1422dc450();
    }
    else
    {
        FUN_1403ed2b0()->FUN_141adc530(0x4e2d);
    }
}

// @0x1419339d0
int UIFittingDollDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (_stricmp("OnTransform", szMethod) == 0)
    {
        if (FUN_1403ed2d0()->FUN_141bd0cc0() == 0)
            return 0;
        int nResult = FUN_141934430();
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
    FUN_141934340();
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
// MS2-FUNCTIONAL: the exe copies each child lookup result through extra frame slots
void UIFittingDollDialog::FUN_141933b00()
{
    FittingDollPC* pDoll = FUN_140884db0(FUN_1403ed2d0()->FUN_141bd1530(DAT_143af25f0));
    if (pDoll == 0)
        return;
    int nItemId = FUN_140967160(pDoll);

    MS2Ptr<ASTextField> spName = GetChild<ASTextField>("m_name");
    if (spName.get() != 0)
        spName->FUN_1422c4cd0(FUN_1401a9d70()->FUN_141811980(1, nItemId));

    MS2Ptr<ASTextField> spDesc = GetChild<ASTextField>("m_desc");
    if (spDesc.get() != 0)
        spDesc->FUN_1422c4cd0(FUN_1401a9d70()->GetItemDescription(nItemId, CString("functionDescription")));

    MS2Ptr<ASMovieClip> spCharacter = GetChild<ASMovieClip>("m_character");
    if (spCharacter.get() != 0)
    {
        CString strFrame;
        const char* szKind = pDoll->FUN_14121c710() == 0 ? "game" : "skin";
        strFrame.AppendFormat("%s_%d", szKind, (unsigned)FUN_141658e60(pDoll));
        spCharacter->vfunc_13(strFrame);
    }

    MS2Ptr<ASMovieClip> spEquip = GetChild<ASMovieClip>("m_equip");
    if (spEquip.get() != 0)
    {
        CString strFrame;
        strFrame.AppendFormat("_%d", (unsigned)(pDoll->FUN_14121c710() != 0));
        spEquip->vfunc_13(strFrame);
    }

    MS2Ptr<ASMovieClip> spEmblem = GetChild<ASMovieClip>("m_emblem");
    if (spEmblem.get() != 0)
    {
        CString strFrame;
        strFrame.AppendFormat("_%d", (unsigned)FUN_141658e60(pDoll));
        spEmblem->vfunc_13(strFrame);
    }
}

// @0x141934070
void UIFittingDollDialog::FUN_141934070()
{
    PC* pMe = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pMe == 0)
        return;
    FittingDollPC* pDoll = FUN_140884db0(FUN_1403ed2d0()->FUN_141bd1530(DAT_143af25f0));
    if (pDoll == 0)
        return;
    bool bOwner = false;
    Unk_FdPlotMgr* pMgr = FUN_1401cd040(&DAT_143b059e8);
    char key[8];
    Unk_FdPlot* pPlot = FUN_1410b8c90(pMgr, FUN_14123c460(pDoll, key));
    if (pPlot != 0)
        bOwner = FUN_1410c8030(pMgr, pPlot->m_nKeyA, pPlot->m_nKeyB) == FUN_141656ad0(pMe);
    int nType = pDoll->FUN_14121c710();
    FUN_14121e670(vfunc_1(), FUN_14123c580(pMe), DAT_143af25f0, nType == 1);
    ASDialog* pDlg = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDlg != 0)
    {
        pDlg->FUN_1407cba60("bagID", vfunc_1());
        pDlg->FUN_1407cb9c0("owner", bOwner);
    }
}

// @0x1419342e0
void UIFittingDollDialog::FUN_1419342e0()
{
    FUN_14121e760(vfunc_1());
}

// @0x141934340
void UIFittingDollDialog::FUN_141934340()
{
    if (m_nTransforming != 0)
    {
        PC* pMe = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pMe != 0 && FUN_14166c930(pMe) != 0x22)
        {
            MS2Ptr<Unk_LdButton> spButton = GetChild<Unk_LdButton>("m_transform");
            if (spButton.get() != 0)
            {
                m_nTransforming = 0;
                spButton->FUN_1422c1fe0(1);
            }
        }
    }
}

// @0x141934430
// MS2-FUNCTIONAL: the exe keeps the equipment handles and the item copies in separate frame slots
int UIFittingDollDialog::FUN_141934430()
{
    FittingDollPC* pDoll = FUN_140884db0(FUN_1403ed2d0()->FUN_141bd1530(DAT_143af25f0));
    if (pDoll == 0)
        return 0xd;
    PC* pMe = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pMe == 0)
        return 0xd;
    Unk_FdPlotMgr* pMgr = FUN_1401cd040(&DAT_143b059e8);
    char key[8];
    Unk_FdPlot* pPlot = FUN_1410b8c90(pMgr, FUN_14123c460(pDoll, key));
    if (pPlot == 0)
        return 0xd;
    if (FUN_1410c8030(pMgr, pPlot->m_nKeyA, pPlot->m_nKeyB) != FUN_141656ad0(pMe))
        return 2;

    Unk_FdEquipList list(10);
    FUN_1411e1b80(pDoll->FUN_1416561a0(), &list);
    bool bBound = false;
    for (POSITION pos = list.GetHeadPosition(); pos != 0; list.GetNext(pos))
    {
        MS2Ptr<CEquipItem> spEquip = list.GetAt(pos);
        bool bSkip = false;
        {
            MS2Ptr<CItem> spItem = spEquip->FUN_1411dc7a0();
            if (spItem.get() != 0)
            {
                MS2Ptr<CItem> spItemAgain = spEquip->FUN_1411dc7a0();
                bSkip = reinterpret_cast<CItemData*>(spItemAgain->FUN_140527840())->FUN_14053d550();
            }
        }
        if (bSkip)
            continue;
        int nResult = pDoll->FUN_14121c870(spEquip->FUN_1411dc7a0().get());
        if (nResult != 0)
            return nResult;
        MS2Ptr<CItem> spBound = spEquip->FUN_1411dc7a0();
        void* pTransfer = spBound->FUN_140527930();
        if (pTransfer != 0 && FUN_140635100(pTransfer) != 0 && FUN_140635120(pTransfer) == 0)
            bBound = true;
    }
    list.RemoveAll();

    FUN_1411e22c0(pMe->FUN_1416561a0(), &list, 1);
    int nType = pDoll->FUN_14121c710();
    for (POSITION pos = list.GetHeadPosition(); pos != 0; list.GetNext(pos))
    {
        MS2Ptr<CItem> spItem = list.GetAt(pos)->FUN_1411dc7a0();
        CItemData* pData = reinterpret_cast<CItemData*>(spItem->FUN_140527840());
        if (nType == 0)
        {
            if (!pData->FUN_14053c870())
                continue;
        }
        else
        {
            if (!pData->FUN_14053c810())
                continue;
        }
        if (spItem->FUN_1405258b0() == nType)
        {
            int nResult = pDoll->FUN_14121c910(list.GetAt(pos)->FUN_1411dc7a0().get());
            if (nResult != 0)
                return nResult;
        }
    }

    if (bBound)
    {
        MS2Ptr<CMsgBoxData> spBox = FUN_140d73e40(1, 0x303, 0, CStringW(L""));
        if (spBox.get() != 0)
        {
            spBox->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &UIFittingDollDialog::FUN_141934c10));
            FUN_140d73c60(spBox);
        }
        return 0x16;
    }
    return 0;
}

// @0x141934c10
bool UIFittingDollDialog::FUN_141934c10(int nResult, const CMsgBoxData& box)
{
    if (nResult == 0)
        SendFittingDoll();
    return true;
}

MS2_EMIT_CRT_MEMMOVE_S();
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cbdfa0-0x142cbe080 .text$yd
