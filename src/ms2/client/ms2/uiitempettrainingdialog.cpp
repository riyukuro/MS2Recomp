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

// The own static (the binding tag of the transfer message box), then the sort type names of the header statics.
static CStringW s_strTrainingBindPet(L"trainingBindPet");
static CString s_strSortTypeNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};

// ---- unit-local views of exe objects ----

// The exe's delegate types take the slot by reference (RTTI names them so); ItemScrollSlot's setters are bound by name.
typedef Delegate<void(ItemScrollSlot&)> PtRemoveFn;
typedef Delegate<void(ItemScrollSlot&, DragSlot*)> PtDropFn;
void FUN_140d428a0(ItemScrollSlot* pSlot, MS2Ptr<CItem> spItem);   // ItemScrollSlot::SetItem
void FUN_140d42bc0(ItemScrollSlot* pSlot, PtRemoveFn fn);      // ItemScrollSlot::SetRemoveFn
void FUN_140d42b70(ItemScrollSlot* pSlot, PtDropFn fn);        // ItemScrollSlot::SetDropFn

extern Unk_Inventory DAT_143ab2a90;

class Unk_PtPackets
{
public:
    void FUN_140da5180(int nPacket, Delegate<void(CInPacket&)> fn);     // register a packet handler
    void FUN_140da51e0(int nPacket, Delegate<void(CInPacket&)> fn);     // unregister it
};
Unk_PtPackets* FUN_140bccd50();
class Unk_PtGameRule { public: __int64 FUN_140353930(unsigned short nLevel, int nRank, unsigned short nKind); };   // exp of a level
Unk_PtGameRule* FUN_1404a1bb0();
class Unk_PtValue { public: unsigned* FUN_1401d7c10(); };
class Unk_PtConfig { public: unsigned char m_pad[0x84c0]; Unk_PtValue m_petMaxLevel; };
Unk_PtConfig* FUN_1401d3200();
class Unk_PtAttr { public: unsigned FUN_14054c530(const CStringW& strKey, const int& nDefault); };
#define PT_ATTR(p) reinterpret_cast<Unk_PtAttr*>(reinterpret_cast<char*>((p)) + 0x320)
class Unk_PtPetRowTable { public: MS2Ptr<Unk_PetRow> FUN_1407290f0(int nPetId); };
Unk_PtPetRowTable* FUN_14052d210();
class Unk_PetRow : public CPtred { public: int m_n18; };

class CMsgBoxData : public CPtred
{
public:
    void FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)> fn);
    void FUN_141a01600(__int64 n);
    void FUN_141a01ee0(MS2Ptr<CItem> spItem, const CStringW& strName, int nA, int nB, int nC, int nD, int nE);   // item entry
    void FUN_141a01700(int nA, int nB, int nC);
};

WorldService* FUN_1403ed2d0();
CStringW FUN_14028b8e0(const CStringW& strKey);                 // string table text
CStringW FUN_1405c2690(CStringW strKey, const CStringW& strArg);
CStringW FUN_1409404f0(__int64 n);
CStringW FUN_141b71910(__int64 nValue);
CStringW FUN_1406c6bd0(const wchar_t* pszFormat, const __int64& nArg);     // "{0}" formatter
CString FUN_140540050(const char* szFormat, const CString& strArg);
void FUN_1412751f0(const CStringW& text, int nA, int nB);
void FUN_1412761e0(MS2Ptr<AScript> spScript, int n);
MS2Ptr<CMsgBoxData> FUN_140d73d20(int nType, CStringW text, int nUnk, CStringW tag);
void FUN_140d73c60(MS2Ptr<CMsgBoxData> box);
NotifyContext::BindData* FUN_1422c8e90(const CString& strName);
ItemScrollSlot* FUN_140d42c30(NotifyContext::BindData* p);
void FUN_140d42540(const CString& strName, unsigned __int64 nOwner, MS2Ptr<CItem> spItem);
void FUN_140d42630(const CString& strName);
MS2DragSlot* FUN_140a50b50(NotifyContext::BindData* p);
__int64 FUN_141405a10(MS2DragSlot* pSlot);
CStringW FUN_14028dfa0(CStringW strKey, const fmt::ArgList& args);        // the string table formatter
FMT_VARIADIC_W(CStringW, FUN_14028dfa0, CStringW)

// @0x140e56eb0
UIItemPetTrainingDialog::UIItemPetTrainingDialog()
    : m_strSlot(), m_nOwner(0), m_spBox(0), m_spPet(0), m_nOffsetExp(0), m_bDone(0)
{
    FUN_141924170(1);
    m_164 = 1;
    FUN_140bccd50()->FUN_140da5180(0xcc, Delegate<void(CInPacket&)>(this, &UIItemPetTrainingDialog::FUN_140e57cb0));
}

// @0x140e57030
UIItemPetTrainingDialog::~UIItemPetTrainingDialog()
{
    FUN_140bccd50()->FUN_140da51e0(0xcc, Delegate<void(CInPacket&)>(this, &UIItemPetTrainingDialog::FUN_140e57cb0));
}

// @0x140e57150
CString UIItemPetTrainingDialog::GetTypeName()
{
    return "ItemPetTrainingDialog";
}

// @0x140e571a0
// MS2-FUNCTIONAL: exe call-result temporaries / branch layout differ (source form not found)
void UIItemPetTrainingDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    m_strSlot = FUN_140540050("{0}.slot", GetTypeName());
    FUN_140d42540(m_strSlot, m_nOwner, m_spPet);
    ItemScrollSlot* pSlot = FUN_140e57e50(m_strSlot);
    if (pSlot != 0)
    {
        FUN_140d42bc0(pSlot, PtRemoveFn(this, &UIItemPetTrainingDialog::FUN_140e58280));
        FUN_140d42b70(pSlot, PtDropFn(this, &UIItemPetTrainingDialog::FUN_140e58300));
    }
    m_spBox = DAT_143ab2a90.FUN_140a5d680(m_nOwner);
    if (!(m_spBox == 0))
    {
        if (m_spBox->FUN_140527840() != 0)
        {
            int nDefault = 0;
            m_nOffsetExp = PT_ATTR(m_spBox->FUN_140527840())->FUN_14054c530(CStringW(L"offsetExp"), nDefault);
            if (m_nOffsetExp != 0)
            {
                FUN_1412761e0(m_30, 1);
                CStringW strDesc = FUN_1405c2690(CStringW(L"s_pet_training_dialog_exp_desc"), FUN_1409404f0(m_nOffsetExp));
                ASObj obj(2);
                obj.FUN_1407cba60("bindID", CString(m_strSlot));
                obj.FUN_1407cbb20("trainingItemName", m_spBox->FUN_140527b10());
                obj.FUN_1407cbb20("trainingExpDesc", CStringW(strDesc));
                obj.FUN_1409c1180("offsetExp", m_nOffsetExp);
                m_30->Invoke("setData", obj);
            }
        }
    }
}

// @0x140e577c0
// MS2-FUNCTIONAL: exe call-result temporaries / branch layout differ (source form not found)
int UIItemPetTrainingDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (_stricmp(szMethod, "onClickConfirm") == 0)
    {
        PC* pPC = static_cast<PC*>(FUN_1403ed2d0()->FUN_141bd0cc0());
        if (pPC == 0)
            return 0;
        if (reinterpret_cast<CItemTransfer*>(m_spPet->FUN_140527930())->FUN_140635100() != 0)
        {
            if (reinterpret_cast<CItemTransfer*>(m_spPet->FUN_140527930())->FUN_140635120() == 0)
            {
                CStringW strMessage = FUN_1405c2690(CStringW(L"s_msg_transfer_bind_pet_training"), pPC->vfunc_77());
                MS2Ptr<CMsgBoxData> box = FUN_140d73d20(0x11, CStringW(strMessage), 0, CStringW(s_strTrainingBindPet));
                if (box.get() != 0)
                {
                    box->FUN_141a01600(m_spPet->FUN_140526a50());
                    box->FUN_141a01ee0(MS2Ptr<CItem>(m_spPet), m_spPet->FUN_140527b10(), 1, 0, -1, -1, 1);
                    box->FUN_141a01700(0x477, 0x478, 0);
                    FUN_140d73c60(box);
                    return 1;
                }
            }
        }
        FUN_140e57d60();
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
    int nCode = packet.vfunc_o8_1();
    if (nCode == 0xd)
    {
        m_30->Invoke("complete");
        m_bDone = 1;
    }
}

// @0x140e57d60
void UIItemPetTrainingDialog::FUN_140e57d60()
{
    if (m_30 == 0)
        return;
    if (m_spBox == 0 || m_spPet == 0)
        return;
    __int64 nUid = m_spPet->FUN_140526a50();
    DAT_143ab2a90.FUN_140a63880(m_spBox.get(), FUN_1406c6bd0(L"{0}", nUid));
}

// @0x140e57e50
ItemScrollSlot* UIItemPetTrainingDialog::FUN_140e57e50(CString strName)
{
    ItemScrollSlot* pSlot = FUN_140d42c30(FUN_1422c8e90(strName));
    if (pSlot != 0)
        return pSlot;
    return 0;
}

// @0x140e57ed0
// MS2-FUNCTIONAL: exe call-result temporaries / branch layout differ (source form not found)
int UIItemPetTrainingDialog::FUN_140e57ed0(MS2Ptr<CItem> spPet, int bMessage)
{
    if (spPet == 0)
        return 0;
    if (spPet->FUN_140525640() == 0)
    {
        if (bMessage != 0)
            FUN_1412751f0(FUN_14028b8e0(CStringW(L"s_pet_training_dialog_invalid_item")), 1, 0);
        return 0;
    }
    if ((unsigned)spPet->FUN_140528c20() == *FUN_1401d3200()->m_petMaxLevel.FUN_1401d7c10())
    {
        if (bMessage != 0)
            FUN_1412751f0(FUN_14028b8e0(CStringW(L"s_pet_training_dialog_max_level")), 1, 0);
        return 0;
    }
    MS2Ptr<Unk_PetRow> spRow = FUN_14052d210()->FUN_1407290f0(reinterpret_cast<CItemData*>(spPet->FUN_140527840())->FUN_14053dc60());
    if (!(spRow == 0))
    {
        if (spRow->m_n18 == 1)
            return 1;
        if (bMessage != 0)
            FUN_1412751f0(FUN_14028b8e0(CStringW(L"s_pet_training_dialog_invalid_item")), 1, 0);
        return 0;
    }
    if (bMessage != 0)
        FUN_1412751f0(FUN_14028b8e0(CStringW(L"s_pet_training_dialog_invalid_item")), 1, 0);
    return 0;
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
// MS2-FUNCTIONAL: exe call-result temporaries / branch layout differ (source form not found)
void UIItemPetTrainingDialog::FUN_140e58300(ItemScrollSlot& slot, DragSlot* pDrag)
{
    MS2DragSlot* pSrc;
    if (m_30 == 0 || m_nOwner == 0 || m_bDone != 0 || (pSrc = FUN_140a50b50(pDrag)) == 0)
        return;
    MS2Ptr<CItem> spPet = DAT_143ab2a90.FUN_140a5d680(FUN_141405a10(pSrc));
    if (FUN_140e57ed0(spPet, 1) == 0)
        return;
    MS2Ptr<CItem> spBox = DAT_143ab2a90.FUN_140a5d680(m_nOwner);
    if (!(spBox == 0) && spBox->FUN_140527840() != 0)
    {
        FUN_140d428a0(&slot, spPet);
        slot.vfunc_10();
        m_spPet = spPet;
        unsigned short nLevel = spPet->FUN_140528c20();
        unsigned short nKind = spPet->FUN_1405282d0();
        int nRank = spPet->FUN_140526bd0();
        __int64 nNeed = FUN_1404a1bb0()->FUN_140353930(nLevel, nRank, nKind);
        __int64 nCur = spPet->FUN_140528b90();
        nCur = nCur + m_nOffsetExp;
        unsigned short nUp = 0;
        while (nNeed <= nCur)
        {
            nCur = nCur - nNeed;
            nUp = nUp + 1;
            nNeed = FUN_1404a1bb0()->FUN_140353930((unsigned short)((unsigned)nLevel + (unsigned)nUp), spPet->FUN_140526bd0(), spPet->FUN_1405282d0());
        }
        nLevel = nLevel + nUp;
        nNeed = FUN_1404a1bb0()->FUN_140353930(nLevel, spPet->FUN_140526bd0(), spPet->FUN_1405282d0());
        if (*FUN_1401d3200()->m_petMaxLevel.FUN_1401d7c10() <= (unsigned)nLevel)
        {
            nLevel = (unsigned short)*FUN_1401d3200()->m_petMaxLevel.FUN_1401d7c10();
            nCur = FUN_1404a1bb0()->FUN_140353930((unsigned short)(nLevel - 1), spPet->FUN_140526bd0(), spPet->FUN_1405282d0());
            nNeed = FUN_1404a1bb0()->FUN_140353930((unsigned short)(nLevel - 1), spPet->FUN_140526bd0(), spPet->FUN_1405282d0());
        }
        CStringW strName = spPet->FUN_140528160();
        CStringW strExp = FUN_14028dfa0(CStringW(L"s_pet_training_dialog_pet_exp"), nLevel, FUN_1409404f0(nCur), FUN_1409404f0(nNeed));
        ASObj obj(2);
        obj.FUN_1407cbb20("petName", CStringW(strName));
        obj.FUN_1407cbb20("petGUID", FUN_141b71910(spPet->FUN_140526a50()));
        obj.FUN_1407cbb20("petExp", CStringW(strExp));
        obj.FUN_1409c1180("petCurrentExp", nCur);
        obj.FUN_1409c1180("petMaxExp", nNeed);
        m_30->Invoke("selectPet", obj.FUN_1422bb870());
    }
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca6c80-0x142ca6cd0 .text$yd
