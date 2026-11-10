// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIItemPetTrainingDialog: see uiitempettrainingdialog.h.
// MS2-UNIT: ?\uiitempettrainingdialog.cpp
// MS2-RANGE: 0x1400d8940-0x1400d8a30 .text$di
// MS2-RANGE: 0x140e56eb0-0x140e59a00 .text$mn
// MS2-GUESS-LOOKALIKES
// MS2-PIN: ?GetTypeName@?$DelegateImpl@U?$pair@PEAVUIItemPetTrainingDialog@@P81@EAAXAEAVCInPacket@@@Z@std@@@?$Delegate@$$A6AXAEAVCInPacket@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x140e59660
// MS2-PIN: ??$FUN_14028dfa0@GV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V12@@@YA?AV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V01@AEBGAEBV01@2@Z 0x140e58e50
// MS2-PIN: ??_GUIItemPetTrainingDialog@@UEAAPEAXI@Z 0x140e59610
//
// File name assumed (the class name; the exe has no assert path for it).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiitempettrainingdialog.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"
#include "uiitempettrainingdialog.h"
#include "itemscrollslot.h"
#include "inventory.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/fittingdollpc.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/fmt/format.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/commonfiles/exptable.h"
#include "ms2/placeholder/packethandlermanager.h"  // C3: PacketHandlerManager::RegisterHandler/UnregisterHandler
#include "ms2/placeholder/clientconstants.h"  // C3: Common::Constants::Value<unsigned int>::Get
#include "ms2/placeholder/cpetdatatable.h"  // C3: CPetDataTable::Find

// The own static (the binding tag of the transfer message box), then the sort type names of the header statics.
static CStringW s_strTrainingBindPet(L"trainingBindPet");
static CString s_strSortTypeNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};

// ---- unit-local views of exe objects ----

// The exe's delegate types take the slot by reference (RTTI names them so); ItemScrollSlot's setters are bound by name.
typedef Delegate<void(ItemScrollSlot&)> PtRemoveFn;
typedef Delegate<void(ItemScrollSlot&, DragSlot*)> PtDropFn;

extern Unk_Inventory g_143ab2a90;

class Unk_PtPackets
{
public:
    void FUN_140da5180(int nPacket, Delegate<void(CInPacket&)> fn);     // register a packet handler
    void FUN_140da51e0(int nPacket, Delegate<void(CInPacket&)> fn);     // unregister it
};
class Unk_140bccd50* GetPacketHandlerManager();   // C3: was FUN_140bccd50
   // exp of a level
void* GetExpTable();   // C3: was GetExpTable
class Unk_PtValue { public: };
class Unk_PtConfig { public: unsigned char m_pad[0x84c0]; Unk_PtValue m_petMaxLevel; };
// C3: was FUN_1401d3200 (= TSingleton<Client::Constants>::GetInstance, GetClientConstants())
#define PT_ATTR(p) reinterpret_cast<CXmlData*>(reinterpret_cast<char*>((p)) + 0x320)

class CMsgBoxData : public CPtred
{
public:
    void SetCallback(Delegate<bool(int, const CMsgBoxData&)> fn);
    void SetItemUid(__int64 n);
    void SetItemEntry(MS2Ptr<CItem> spItem, const CStringW& strName, int nA, int nB, int nC, int nD, int nE);   // item entry
    void SetButtonLabelIds(int nA, int nB, int nC);
};

CStringW GetStringCommonByKey(const CStringW& strKey);                 // string table text
template <class A> CStringW FUN_14028dfa0(CStringW strKey, const A& a1);
CStringW FUN_1409404f0(__int64 n);
CStringW FUN_141b71910(__int64 nValue);
void ShowSystemNotice(const CStringW& text, int nA, int nB);
void FUN_1412761e0(MS2Ptr<AScript> spScript, int n);
MS2Ptr<CMsgBoxData> CreateMessageBox(int nType, CStringW text, void* pListener, CStringW tag);
void FUN_140d73c60(MS2Ptr<CMsgBoxData> box);
#include "ms2/gfxui/notifyhandler.h"   // C3: Unk_NotifyContext::FUN_1422c8e90/f10/f70
ItemScrollSlot* FUN_140d42c30(NotifyContext::BindData* p);
void FUN_140d42540(const CString& strName, unsigned __int64 nOwner, MS2Ptr<CItem> spItem);
void FUN_140d42630(const CString& strName);
MS2DragSlot* AsDragSlot(NotifyContext::BindData* p);
class InvenSlot   // C3: member view for the former free stand-ins
{
public:
    __int64 GetItemUid();
};
CStringW FUN_14028dfa0(const CStringW& strKey, const fmt::ArgList& args);        // the string table formatter
FMT_VARIADIC_W(CStringW, FUN_14028dfa0, CStringW)

// @0x140e56eb0
UIItemPetTrainingDialog::UIItemPetTrainingDialog()
    : m_strSlot(), m_nOwner(0), m_spBox(0), m_spPet(0), m_nOffsetExp(0), m_bDone(0)
{
    SetTweenEnabled(1);
    m_164 = 1;
    ((class PacketHandlerManager*)GetPacketHandlerManager())->RegisterHandler(0xcc, Delegate<void(CInPacket&)>(this, &UIItemPetTrainingDialog::FUN_140e57cb0));
}

// @0x140e57030
UIItemPetTrainingDialog::~UIItemPetTrainingDialog()
{
    ((class PacketHandlerManager*)GetPacketHandlerManager())->UnregisterHandler(0xcc, Delegate<void(CInPacket&)>(this, &UIItemPetTrainingDialog::FUN_140e57cb0));
}

// @0x140e57150
CString UIItemPetTrainingDialog::GetTypeName()
{
    return "ItemPetTrainingDialog";
}

// @0x140e571a0
void UIItemPetTrainingDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    m_strSlot = StringFormat<CString>("{0}.slot", GetTypeName());
    FUN_140d42540(m_strSlot, m_nOwner, m_spPet);
    ItemScrollSlot* pSlot = FUN_140e57e50(m_strSlot);
    if (pSlot != 0)
    {
        pSlot->SetRemoveFn(PtRemoveFn(this, &UIItemPetTrainingDialog::FUN_140e58280));
        pSlot->SetDropFn(PtDropFn(this, &UIItemPetTrainingDialog::FUN_140e58300));
    }
    m_spBox = g_143ab2a90.FindItemByUid(m_nOwner);
    if (m_spBox == 0)
        return;
    if (m_spBox->GetData() == 0)
        return;
    int nDefault = 0;
    m_nOffsetExp = (unsigned)PT_ATTR(m_spBox->GetData())->GetInt(L"offsetExp", nDefault);
    if (m_nOffsetExp == 0)
        return;
    FUN_1412761e0(m_30, 1);
    CStringW strDesc = FUN_14028dfa0<CStringW>(CStringW(L"s_pet_training_dialog_exp_desc"), FUN_1409404f0(m_nOffsetExp));
    ASObj obj(2);
    obj.SetStringMember("bindID", CString(m_strSlot));
    ((class AScript&)(obj)).SetWStringMember("trainingItemName", m_spBox->FUN_140527b10());
    ((class AScript&)(obj)).SetWStringMember("trainingExpDesc", CStringW(strDesc));
    obj.FUN_1409c1180("offsetExp", m_nOffsetExp);
    m_30->Invoke("setData", obj);
}

// @0x140e577c0
int UIItemPetTrainingDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (_stricmp(szMethod, "onClickConfirm") == 0)
    {
        PC* pPC = static_cast<PC*>(WorldService::GetInstance()->GetLocalPlayer());
        if (pPC == 0)
            return 0;
        if (reinterpret_cast<CItemTransfer*>(m_spPet->GetTransfer())->HasBindingRule() != 0)
        {
            if (reinterpret_cast<CItemTransfer*>(m_spPet->GetTransfer())->HasBinding() == 0)
            {
                CStringW strMessage = FUN_14028dfa0<CStringW>(CStringW(L"s_msg_transfer_bind_pet_training"), pPC->vfunc_77());
                MS2Ptr<CMsgBoxData> box = CreateMessageBox(0x11, CStringW(strMessage), 0, CStringW(s_strTrainingBindPet));
                if (box.get() != 0)
                {
                    box->SetItemUid(m_spPet->GetItemUid());
                    box->SetItemEntry(MS2Ptr<CItem>(m_spPet), m_spPet->FUN_140527b10(), 1, 0, -1, -1, 1);
                    box->SetButtonLabelIds(0x477, 0x478, 0);
                    FUN_140d73c60(box);
                    return 1;
                }
            }
        }
        SendTrainingRequest();
        return 1;
    }
    return 0;
}

// @0x140e57bb0
int UIItemPetTrainingDialog::vfunc_65()
{
    return UIDialog::vfunc_65();
}

// @0x140e57bd0
void UIItemPetTrainingDialog::vfunc_67()
{
    UIDialog::vfunc_67();
    m_nOwner = 0;
    FUN_140d42630(m_strSlot);
    m_strSlot = "";
    m_spPet = 0;
    m_spBox = 0;
    m_nOffsetExp = 0;
    m_bDone = 0;
}

// @0x140e57c80
void UIItemPetTrainingDialog::SetOwner(unsigned __int64 nOwner)
{
    m_nOwner = nOwner;
}

// @0x140e57cb0
void UIItemPetTrainingDialog::FUN_140e57cb0(CInPacket& packet)
{
    if (m_30 == 0)
        return;
    int nCode = packet.ReadUInt8();
    if (nCode == 0xd)
    {
        m_30->Invoke("complete");
        m_bDone = 1;
    }
}

// @0x140e57d60
void UIItemPetTrainingDialog::SendTrainingRequest()
{
    if (m_30 == 0)
        return;
    if (m_spBox == 0 || m_spPet == 0)
        return;
    __int64 nUid = m_spPet->GetItemUid();
    g_143ab2a90.FUN_140a63880(m_spBox.get(), StringFormat<unsigned __int64>(L"{0}", reinterpret_cast<const unsigned __int64&>(nUid)));
}

// @0x140e57e50
ItemScrollSlot* UIItemPetTrainingDialog::FUN_140e57e50(CString strName)
{
    ItemScrollSlot* pSlot = FUN_140d42c30(Unk_NotifyContext::FindBinding(strName));
    if (pSlot != 0)
        return pSlot;
    return 0;
}

// @0x140e57ed0
int UIItemPetTrainingDialog::FUN_140e57ed0(MS2Ptr<CItem> spPet, int bMessage)
{
    if (spPet == 0)
        return 0;
    if (spPet->IsPetItem() == 0)
    {
        if (bMessage != 0)
            ShowSystemNotice(GetStringCommonByKey(L"s_pet_training_dialog_invalid_item"), 1, 0);
        return 0;
    }
    if ((unsigned)spPet->GetPetLevel() == *reinterpret_cast<Common::Constants::Value<unsigned int>*>(&((class Unk_PtConfig*)GetClientConstants())->m_petMaxLevel)->Get())
    {
        if (bMessage != 0)
            ShowSystemNotice(GetStringCommonByKey(L"s_pet_training_dialog_max_level"), 1, 0);
        return 0;
    }
    MS2Ptr<CPetData> spRow = TSingleton<CPetDataTable>::GetInstance()->Find(reinterpret_cast<CItemData*>(spPet->GetData())->GetPetId());
    if (spRow == 0)
    {
        if (bMessage != 0)
            ShowSystemNotice(GetStringCommonByKey(L"s_pet_training_dialog_invalid_item"), 1, 0);
        return 0;
    }
    if (spRow->m_nType != 1)
    {
        if (bMessage != 0)
            ShowSystemNotice(GetStringCommonByKey(L"s_pet_training_dialog_invalid_item"), 1, 0);
        return 0;
    }
    return 1;
}

// @0x140e58280
void UIItemPetTrainingDialog::FUN_140e58280(ItemScrollSlot& slot)
{
    if (m_30 == 0)
        return;
    if (m_bDone != 0)
        return;
    m_30->Invoke("selectPet");
}

// @0x140e58300
void UIItemPetTrainingDialog::FUN_140e58300(ItemScrollSlot& slot, DragSlot* pDrag)
{
    if (m_30 == 0)
        return;
    if (m_nOwner == 0)
        return;
    if (m_bDone != 0)
        return;
    MS2DragSlot* pSrc = AsDragSlot(pDrag);
    if (pSrc != 0)
    {
        MS2Ptr<CItem> spPet = g_143ab2a90.FindItemByUid(((class InvenSlot*)(class MS2DragSlot*)(pSrc))->GetItemUid());
        if (FUN_140e57ed0(spPet, 1) == 0)
            return;
        MS2Ptr<CItem> spBox = g_143ab2a90.FindItemByUid(m_nOwner);
        if (spBox == 0 || spBox->GetData() == 0)
            return;
        {
            ((class ItemScrollSlot*)(class ItemScrollSlot*)(&slot))->SetItem(spPet);
            slot.vfunc_10();
            m_spPet = spPet;
            unsigned short nLevel = spPet->GetPetLevel();
            __int64 nNeed = ((class CExpTable*)GetExpTable())->GetPetExp(nLevel, spPet->GetRarity(), spPet->GetLevelLimit());
            __int64 nCur = spPet->GetPetExp() + m_nOffsetExp;
            unsigned short nUp = 0;
            while (nNeed <= nCur)
            {
                nCur = nCur - nNeed;
                ++nUp;
                nNeed = ((class CExpTable*)GetExpTable())->GetPetExp(nLevel + nUp, spPet->GetRarity(), spPet->GetLevelLimit());
            }
            nLevel += nUp;
            nNeed = ((class CExpTable*)GetExpTable())->GetPetExp(nLevel, spPet->GetRarity(), spPet->GetLevelLimit());
            if (nLevel >= *reinterpret_cast<Common::Constants::Value<unsigned int>*>(&((class Unk_PtConfig*)GetClientConstants())->m_petMaxLevel)->Get())
            {
                nLevel = (unsigned short)*reinterpret_cast<Common::Constants::Value<unsigned int>*>(&((class Unk_PtConfig*)GetClientConstants())->m_petMaxLevel)->Get();
                nCur = ((class CExpTable*)GetExpTable())->GetPetExp((unsigned short)(nLevel - 1), spPet->GetRarity(), spPet->GetLevelLimit());
                nNeed = ((class CExpTable*)GetExpTable())->GetPetExp((unsigned short)(nLevel - 1), spPet->GetRarity(), spPet->GetLevelLimit());
            }
            CStringW strName = spPet->FUN_140528160();
            CStringW strExp = FUN_14028dfa0(CStringW(L"s_pet_training_dialog_pet_exp"), nLevel, FUN_1409404f0(nCur), FUN_1409404f0(nNeed));
            ASObj obj(2);
            ((class AScript&)(obj)).SetWStringMember("petName", CStringW(strName));
            ((class AScript&)(obj)).SetWStringMember("petGUID", FUN_141b71910(spPet->GetItemUid()));
            ((class AScript&)(obj)).SetWStringMember("petExp", CStringW(strExp));
            obj.FUN_1409c1180("petCurrentExp", nCur);
            obj.FUN_1409c1180("petMaxExp", nNeed);
            m_30->Invoke("selectPet", obj.GetValue());
        }
    }
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca6c80-0x142ca6cd0 .text$yd
