// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIBossRewardPreviewDialog: see uibossrewardpreviewdialog.h.
// MS2-UNIT: ?\uibossrewardpreviewdialog.cpp
// MS2-RANGE: 0x1400de4a0-0x1400de680 .text$di
// MS2-RANGE: 0x140f24e40-0x140f26990 .text$mn
// MS2-PIN: ??_7Slot@UIBossRewardPreviewDialog@@6BBindData@NotifyContext@@@ 0x142e73d68 ; hand: primary vftable
//
// File name assumed (the class name; the exe has no assert path for it).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uibossrewardpreviewdialog.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"
#include "uibossrewardpreviewdialog.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/asslot.h"
#include "ms2/placeholder/astextfield.h"
#include "ms2/placeholder/astooltip.h"
#include "ms2/placeholder/asuicomponent.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/commonfiles/npcdata.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include <efd/MemHint.h>
#include <efd/MemObject.h>

// ---- unit-local views of exe objects ----

class ASDialog : public ASDisplayObject
{
};

// AScript with the string member setter (ASObj::FUN_1407cba60 is folded with it).
class Unk_BrmAS : public AScript
{
public:
    void FUN_1407cba60(const char* szName, CString str);
};

// The game context (FUN_1403ed2d0): its FUN_141bd0cc0 returns the local player.
class Unk_BrmGameCtx
{
public:
    void* FUN_141bd0cc0();
};
Unk_BrmGameCtx* FUN_1403ed2d0();

// A reward entry: an id holder (a vftable object, slot 1 = the item id) and the count.
class Unk_BrmIdHolder
{
public:
    virtual int vfunc_0();
    virtual int vfunc_1();
};
class Unk_BrmEntry : public CPtred
{
public:
    Unk_BrmIdHolder m_id;                               // +0x18
    int m_nCount;                                       // +0x20
};
// The list of the reward entries of a reward row (CAtlList-like, block size 10).
class Unk_BrmList
{
public:
    Unk_BrmList(int nBlockSize);                        // 0x140dc5a60
    ~Unk_BrmList();                                     // 0x140dc5fd0
    POSITION FUN_140dc6f30();                           // head
    Unk_BrmEntry* FUN_140dc6dc0(POSITION pos);          // the entry at pos
    void FUN_140dc7030(POSITION* pPos);                 // next
private:
    char m_pad[0x20];
};
// A reward row of the boss reward table.
class Unk_BrmReward : public CPtred
{
public:
    void FUN_140dc3950(void* pPlayer, Unk_BrmList& list);   // collect the reward entries for the player
};
// The boss reward table (DAT_143ac48f8).
class Unk_SingletonObj
{
public:
    MS2Ptr<Unk_BrmReward> FUN_140dc3c70(int nNpcId);
};
extern Unk_SingletonObj* DAT_143ac48f8;

MS2Ptr<CNpcData> FUN_1406cd330(int nNpcId);
CStringW FUN_1401aa6a0(int nId);                        // npc name
CStringW FUN_1409e9ed0(CStringW strKey, const CStringW& a1, const unsigned short& a2);
CStringW FUN_14028dfa0(CStringW strKey, const fmt::ArgList& args);   // string table text, formatted
int FUN_1409e13a0(ASTooltip* pTip, CItem* pCompare, CItem* pItem);   // item tooltip (the member in astooltip.h is declared void)

// The slot registry (see unit_1400d2c20.cpp / itemlockslot.cpp).
void FUN_1422c8f10(const CString& strName, NotifyContext::BindData* pBag);
NotifyContext::BindData* FUN_1422c8e90(const CString& strName);
void FUN_1422c8f70(const CString& strName);
void FUN_1422cc9e0(DragSlotBag* pBag);
UIBossRewardPreviewDialog::SlotBag* FUN_140f260d0(NotifyContext::BindData* p);
void FUN_140f250b0(const CString& strName, int nCount, int nNpcId);
void FUN_140f25170(const CString& strName);
Unk_SingletonObj* FUN_140f26650();

EE_IMPLEMENT_CONCRETE_CLASS_INFO(UIBossRewardPreviewDialog::Slot);
EE_IMPLEMENT_CONCRETE_CLASS_INFO(UIBossRewardPreviewDialog::SlotBag);

// File statics (the .text$di order: the two class infos, "iconPath", then the shared header's).
static CString s_strIconPath = "iconPath";
#include "ms2/placeholder/header_statics_a.h"

// @0x140f26120 the string table text formatted with the npc name and a literal
CStringW FUN_140f26120(CStringW strKey, const CStringW& strName, const wchar_t (&sz)[3])
{
    return FUN_14028dfa0(strKey, fmt::ArgList(fmt::internal::make_type(strName, sz),
        fmt::internal::ArgArray<2>::Type{fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(strName),
                                         fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(sz)}));
}   // MS2-FUNCTIONAL: fmt argument array layout

// ---- Slot ----

// @0x140f24e40
UIBossRewardPreviewDialog::Slot::Slot(const CString& strName, int nIndex, MS2Ptr<CItem> spItem)
    : MS2DragSlot(strName, nIndex), m_spItem(spItem)
{
}

// @0x140f26450
UIBossRewardPreviewDialog::Slot::~Slot()
{
}

// @0x140f24ed0 (ITooltip::vfunc_0)
int UIBossRewardPreviewDialog::Slot::vfunc_0(void* p)
{
    if (m_spItem == 0)
    {
        void* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pPlayer == 0)
            return 0;
        ASTooltip tip(pPlayer, 0x800, 2);
        if (FUN_1409e13a0(&tip, 0, m_spItem.get()) == 0)
            return 0;
        *static_cast<Scaleform::GFx::Value*>(p) = tip.FUN_1422bb870();
        return 1;
    }
    return 0;
}

// @0x140f24fd0
int UIBossRewardPreviewDialog::Slot::vfunc_8(void* p)
{
    void* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return 0;
    ASSlot slot(2);
    if (slot.FUN_1409c3860(m_spItem.get(), pPlayer, 0x401) == 0)
        return 0;
    *static_cast<Scaleform::GFx::Value*>(p) = slot.FUN_1422bb870();
    return 1;
}

// ---- SlotBag ----

// @0x140f250b0 create the bag of the npc's reward items and register it under the name
void FUN_140f250b0(const CString& strName, int nCount, int nNpcId)
{
    UIBossRewardPreviewDialog::SlotBag* pBag =
        new (efd::MemHint(efd::MemHint::NONE)) UIBossRewardPreviewDialog::SlotBag(strName, nNpcId);
    if (pBag)
    {
        static_cast<DragSlotBag*>(pBag)->vfunc_10(nCount);
        FUN_1422c8f10(strName, pBag);
    }
}

// @0x140f25170 destroy the registered bag
void FUN_140f25170(const CString& strName)
{
    UIBossRewardPreviewDialog::SlotBag* pBag = FUN_140f260d0(FUN_1422c8e90(strName));
    if (pBag)
    {
        FUN_1422cc9e0(pBag);
        FUN_1422c8f70(strName);
    }
}

// @0x140f251c0
UIBossRewardPreviewDialog::SlotBag::SlotBag(const CString& strName, int nNpcId)
    : DragSlotBag(strName), m_nNpcId(nNpcId)
{
    FUN_140f25400();
}

// @0x140f26480
UIBossRewardPreviewDialog::SlotBag::~SlotBag()
{
}

// @0x140f25240
DragSlot* UIBossRewardPreviewDialog::SlotBag::vfunc_16(int nIndex)
{
    MS2Ptr<CItem> spItem(0);
    if ((size_t)nIndex < m_items.GetCount())
        spItem = m_items.GetAt(nIndex);
    return new (efd::MemHint(efd::MemHint::NONE)) Slot(vfunc_15(nIndex), nIndex, spItem);
}

// @0x140f25400
void UIBossRewardPreviewDialog::SlotBag::FUN_140f25400()
{
    void* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return;
    MS2Ptr<Unk_BrmReward> spReward = FUN_140f26650()->FUN_140dc3c70(m_nNpcId);
    if (!(spReward == 0))
    {
        Unk_BrmList list(10);
        spReward->FUN_140dc3950(pPlayer, list);
        POSITION pos = list.FUN_140dc6f30();
        while (pos != 0)
        {
            Unk_BrmEntry* pEntry = list.FUN_140dc6dc0(pos);
            MS2Ptr<CItem> spItem(new CItem());
            if (spItem->FUN_14052b130(pEntry->m_nCount, (&pEntry->m_id)->vfunc_1(), 0) != 0)
                m_items.Add(spItem);
            list.FUN_140dc7030(&pos);
        }
    }
}

// ---- UIBossRewardPreviewDialog ----

// @0x140f255e0
UIBossRewardPreviewDialog::UIBossRewardPreviewDialog()
    : m_spExp(0), m_spMeso(0), m_spTitle(0), m_spMesoIcon(0), m_nNpcId(0), m_strBag(vfunc_1())
{
}

// @0x140f264b0
UIBossRewardPreviewDialog::~UIBossRewardPreviewDialog()
{
}

// @0x140f256b0
CString UIBossRewardPreviewDialog::vfunc_1()
{
    return "BossRewardPreviewDialog";
}

// @0x140f25700
void UIBossRewardPreviewDialog::vfunc_67()
{
    m_nNpcId = 0;
    m_spExp = 0;
    m_spMeso = 0;
    m_spTitle = 0;
    m_spMesoIcon = 0;
    FUN_140f25170(m_strBag);
    UIDialog::vfunc_67();
}

// @0x140f257a0
void UIBossRewardPreviewDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDialog != 0)
    {
        FUN_140e48d80<ASTextField>("m_title", m_spTitle);
        MS2Ptr<CNpcData> spNpc = FUN_1406cd330(m_nNpcId);
        if (spNpc.get() != 0)
            static_cast<Unk_BrmAS*>(static_cast<AScript*>(pDialog))->FUN_1407cba60(s_strIconPath, CString(spNpc->m_strPortrait));
    }
    MS2Ptr<ASUIComponent> spPreview = GetChild<ASUIComponent>("m_rewardPreview");
    if (spPreview.get() != 0)
    {
        spPreview->FUN_140beaf20<ASTextField>("m_exp", m_spExp);
        spPreview->FUN_140beaf20<ASTextField>("m_meso", m_spMeso);
        spPreview->FUN_140bc71c0<ASMovieClip>("m_mesoIcon", m_spMesoIcon);
    }
    FUN_140f25bf0();
}

// @0x140f25ad0
int UIBossRewardPreviewDialog::FUN_140f25ad0(int nNpcId)
{
    MS2Ptr<CNpcData> spNpc = FUN_1406cd330(nNpcId);
    if (!(spNpc == 0))
    {
        if (spNpc->m_nClass != 4 && spNpc->m_nClass != 6)
            return 0;
        MS2Ptr<Unk_BrmReward> spReward = FUN_140f26650()->FUN_140dc3c70(nNpcId);
        if (!(spReward == 0))
        {
            m_nNpcId = nNpcId;
            return 1;
        }
        return 0;
    }
    return 0;
}

// @0x140f25bf0
void UIBossRewardPreviewDialog::FUN_140f25bf0()
{
    MS2Ptr<CNpcData> spNpc = FUN_1406cd330(m_nNpcId);
    if (spNpc == 0)
        return;
    if (spNpc->m_nClass != 4 && spNpc->m_nClass != 6)
        return;
    if (m_spTitle.get() != 0)
    {
        if (!spNpc->HasPropertyTag(3))
        {
            unsigned short nLevel = spNpc->GetLevel();
            m_spTitle->FUN_1422c4cd0(FUN_1409e9ed0(CStringW(L"s_worldmap_search_map_title"), FUN_1401aa6a0(m_nNpcId), nLevel));
        }
        else
        {
            m_spTitle->FUN_1422c4cd0(FUN_140f26120(CStringW(L"s_worldmap_search_map_title"), FUN_1401aa6a0(m_nNpcId), L"??"));
        }
    }
    MS2Ptr<Unk_BrmReward> spReward = FUN_140f26650()->FUN_140dc3c70(m_nNpcId);
    if (!(spReward == 0))
    {
        if (m_spExp.get() != 0)
            m_spExp->vfunc_3(0);
        if (m_spMeso.get() != 0)
        {
            m_spMeso->vfunc_3(0);
            if (m_spMesoIcon.get() != 0)
                m_spMesoIcon->vfunc_3(0);
        }
        ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
        if (pDialog != 0)
        {
            FUN_140f25170(m_strBag);
            FUN_140f250b0(m_strBag, 0x12, m_nNpcId);
            static_cast<Unk_BrmAS*>(m_30.operator->())->FUN_1407cba60("rewardId", vfunc_1());
        }
    }
}

// @0x140f260d0
UIBossRewardPreviewDialog::SlotBag* FUN_140f260d0(NotifyContext::BindData* p)
{
    UIBossRewardPreviewDialog::SlotBag* pBag = 0;
    if (p != 0 && p->TypeCast(0x620006e, (void**)&pBag))
        return pBag;
    return 0;
}

// @0x140f26650
Unk_SingletonObj* FUN_140f26650()
{
    return DAT_143ac48f8;
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca9020-0x142ca90d0 .text$yd
