// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIItemAutoUseOptionDialog: the pet auto-use settings window.
// See uiitemautouseoptiondialog.h. Member and local names are invented from the use.
// MS2-UNIT: ?\uiitemautouseoptiondialog.cpp
// MS2-RANGE: 0x140f4dfd0-0x140f50d60 .text$mn
// MS2-RANGE: 0x1400dfd80-0x1400dff60 .text$di
// MS2-PIN: ??_7Slot@UIItemAutoUseOptionDialog@@6BBindData@NotifyContext@@@ 0x142e7b9c8 ; hand: primary vftable
//
// File name assumed (the class name; the exe has no assert path for it).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiitemautouseoptiondialog.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"
#include "uiitemautouseoptiondialog.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/asslot.h"
#include "ms2/placeholder/astextfield.h"
#include "ms2/placeholder/astooltip.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/cpetmanager.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/client/ms2/inventory.h"
#include "ms2/client/ms2/petslot.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/uistatuseventdispatcher.h"
#include "ms2/client/ms2/skillsystem.h"
#include <efd/MemHint.h>
#include <efd/MemObject.h>

// ---- unit-local views of exe objects ----

class Unk_ItemEquipData : public CItemData { };          // CItem::FUN_140527840's record

extern Unk_Inventory DAT_143ab2a90;
extern unsigned DAT_1439ed000;                            // number of rows of the window
extern int DAT_1439ed004;                                 // number of drop-down entries (the last one = off)

class Unk_BreakSelected* FUN_140535320();   // C3: was FUN_140535320

class ASDialog : public ASDisplayObject
{
};

// The local player and its views (see petslot.cpp). Slot 78 (+0x270) of the player is its level.
class Unk_AuSkills : public CSkillSystem
{
};
class Unk_AuPlayer
{
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual void vfunc_28();
    virtual void vfunc_29();
    virtual void vfunc_30();
    virtual void vfunc_31();
    virtual void vfunc_32();
    virtual void vfunc_33();
    virtual void vfunc_34();
    virtual void vfunc_35();
    virtual void vfunc_36();
    virtual void vfunc_37();
    virtual void vfunc_38();
    virtual void vfunc_39();
    virtual void vfunc_40();
    virtual void vfunc_41();
    virtual void vfunc_42();
    virtual void vfunc_43();
    virtual void vfunc_44();
    virtual void vfunc_45();
    virtual void vfunc_46();
    virtual void vfunc_47();
    virtual void vfunc_48();
    virtual void vfunc_49();
    virtual void vfunc_50();
    virtual void vfunc_51();
    virtual void vfunc_52();
    virtual void vfunc_53();
    virtual void vfunc_54();
    virtual void vfunc_55();
    virtual void vfunc_56();
    virtual void vfunc_57();
    virtual void vfunc_58();
    virtual void vfunc_59();
    virtual void vfunc_60();
    virtual void vfunc_61();
    virtual void vfunc_62();
    virtual void vfunc_63();
    virtual void vfunc_64();
    virtual void vfunc_65();
    virtual void vfunc_66();
    virtual void vfunc_67();
    virtual void vfunc_68();
    virtual void vfunc_69();
    virtual void vfunc_70();
    virtual void vfunc_71();
    virtual void vfunc_72();
    virtual void vfunc_73();
    virtual void vfunc_74();
    virtual void vfunc_75();
    virtual void vfunc_76();
    virtual void vfunc_77();
    virtual unsigned short vfunc_78();                    // the level
    Unk_AuSkills* FUN_141523bc0();                        // the skill system
    MS2Ptr<CItem> FUN_14152e2f0(MS2Ptr<CItem> spItem);    // the worn item spItem would replace
};
#define AU_PLAYER_LEVEL(p) ((p)->vfunc_78())
class Unk_AuWorld
{
public:
    Unk_AuPlayer* FUN_141bd0cc0();                        // the local player
};
class WorldService   // C3: member view for the former free stand-ins
{
public:
    static class WorldService* GetInstance();
};
void* FUN_141676a10(void* pPlayer);                       // the player's pet part (null: none)

// The drop-down child of the movie.
class Unk_AuCombo : public ASDisplayObject
{
public:
#define AU_V(n) virtual void vfunc_##n();
    AU_V(6) AU_V(7) AU_V(8) AU_V(9) AU_V(10) AU_V(11) AU_V(12) AU_V(13) AU_V(14) AU_V(15) AU_V(16) AU_V(17) AU_V(18)
    AU_V(19) AU_V(20) AU_V(21) AU_V(22) AU_V(23)
#undef AU_V
    virtual void vfunc_24(bool bShow);                    // 24 (+0xc0) refresh
    void FUN_1422c1fe0(int bEnabled);                     // enable / disable
    int FUN_1422df6c0();                                  // the selected index
    void FUN_1422df690(int nIndex);                       // select
    void FUN_1422dfc10();                                 // clear the entries
    void FUN_1422dfc70(ASObj& entry);                     // add an entry
};

// The dialog's child lookups.
class Unk_AuEntity : public UIDialog
{
public:
    MS2Ptr<ASTextField> FUN_140bb4cf0(const CString& strName);
    MS2Ptr<Unk_AuCombo> FUN_140c28560(const CString& strName);   // exe: no callee dtor, by reference
};

// The status listener registry.


CString FUN_140513200(const char* szFormat, const int& n);          // format one number
CString FUN_1402bad60(const char* szFormat, const int* pn);        // the same format, a second copy
CStringW GetStringCommon(int nStringId);                              // string table text
CStringW GetStringCommonByKey(const CStringW& strKey);                     // string table text by key
CStringW FUN_1409e97f0(int nId, const int& nArg);                   // string table entry, one argument
void FUN_140d73bc0(int nTable, int nId, void* pListener, CStringW strExtra);
void FUN_140d73aa0(CStringW text, int nType, void* p, CStringW tag);
void FUN_140710590(COutPacket& packet);                             // send
bool FUN_140534e50(MS2Ptr<CItem>* pItem);                           // the item is expired / unusable
void* FUN_140a50b50(DragSlot* pSlot);                               // the item slot behind a drag source
class InvenSlot   // C3: member view for the former free stand-ins
{
public:
    int FUN_141405980();
};
void FUN_1414048f0(int nItemId);
void FUN_141404ce0(int nType, void* pArr, Scaleform::GFx::Value* pValue);
void FUN_1414050c0(int nType, void* pArr, Scaleform::GFx::Value* pValue);
void FUN_140d2cfc0(MS2Ptr<CItem> spItem);                           // item link / popup for the item
unsigned FUN_1422ccd20(DragSlotBag* pBag);                          // slot count of the bag
void FUN_1422c8f10(const CString& strName, NotifyContext::BindData* pBag);
NotifyContext::BindData* FUN_1422c8e90(const CString& strName);
void FUN_1422c8f70(const CString& strName);
PetSlot* FUN_140dbc0d0(DragSlot* p);
UIItemAutoUseOptionDialog* FUN_140cbe1c0(int nId);                  // the open dialog with this UI id

UIItemAutoUseOptionDialog::Slot* FUN_140f507b0(NotifyContext::BindData* p);
UIItemAutoUseOptionDialog::SlotBag* FUN_140f50800(NotifyContext::BindData* p);
DragSlotBag* FUN_140c544d0(NotifyContext::BindData* p);              // DragSlotBag cast (class id 0x6202736)

EE_IMPLEMENT_CONCRETE_CLASS_INFO(UIItemAutoUseOptionDialog::Slot);
EE_IMPLEMENT_CONCRETE_CLASS_INFO(UIItemAutoUseOptionDialog::SlotBag);

static CString s_strOnCooldownEnd = "onCooldownEnd";

// Header-defined statics (same in every obj that includes the shared item header).
#include "ms2/placeholder/header_statics_a.h"

// @0x140f4dfd0
UIItemAutoUseOptionDialog::Slot::Slot(const CString& strName, int nIndex, int nItemId)
    : MS2DragSlot(strName, nIndex)
{
    m_nItemId = nItemId;
}

// @0x140f4e040
UIItemAutoUseOptionDialog::Slot::~Slot()
{
}

// @0x140f4e080
float UIItemAutoUseOptionDialog::Slot::FUN_140f4e080()
{
    Unk_AuPlayer* pPlayer = ((class Unk_AuWorld*)WorldService::GetInstance())->FUN_141bd0cc0();
    if (pPlayer == 0)
        return 0;
    return pPlayer->FUN_141523bc0()->FUN_141765fe0(FUN_140f4e0e0(), 0);
}

// @0x140f4e0e0
int UIItemAutoUseOptionDialog::Slot::FUN_140f4e0e0()
{
    MS2Ptr<CItem> spItem = ((class CPetManager*)FUN_140535320())->FUN_140c8b430()->FUN_140c892c0(FUN_140f4e180());
    if (spItem.get() != 0)
        return spItem->FUN_140527840()->FUN_14053dc20();
    return 0;
}

// @0x140f4e180
int UIItemAutoUseOptionDialog::Slot::FUN_140f4e180()
{
    return m_nItemId;
}

// @0x140f4e1a0
void UIItemAutoUseOptionDialog::Slot::FUN_140f4e1a0(int nItemId)
{
    m_nItemId = nItemId;
}

// @0x140f4e1c0
int UIItemAutoUseOptionDialog::Slot::FUN_140f4e1c0(int nItemId)
{
    UIItemAutoUseOptionDialog* pDlg = FUN_140cbe1c0(0x4ef4);
    if (pDlg != 0 && pDlg->FUN_141924630() != 0)
        return pDlg->FUN_140f4faf0(nItemId);
    return 0;
}

// @0x140f4e210
void UIItemAutoUseOptionDialog::Slot::vfunc_6(void* p)
{
    CString str;
    str.Format("%d", FUN_140f4e180());
    ((ATL::CAtlArray<ATL::CStringT<char, StrTraitMFC_DLL<char, ATL::ChTraitsCRT<char>>>, ATL::CElementTraits<ATL::CStringT<char, StrTraitMFC_DLL<char, ATL::ChTraitsCRT<char>>>>>*)(void*)(p))->Add(str);
}

// @0x140f4e280
int UIItemAutoUseOptionDialog::Slot::vfunc_11()
{
    if (((Scaleform::GFx::Value*)&(m_value18))->IsObject())
        m_value18.Invoke((const char*)s_strOnCooldownEnd, 0);
    m_nItemId = 0;
    return DragSlot::vfunc_11();
}

// @0x140f4e2f0
int UIItemAutoUseOptionDialog::Slot::vfunc_13()
{
    return 0;
}

// @0x140f4e300
int UIItemAutoUseOptionDialog::Slot::vfunc_14()
{
    FUN_140f4f100(2);
    return vfunc_11();
}

// @0x140f4e340
int UIItemAutoUseOptionDialog::Slot::vfunc_15()
{
    MS2Ptr<CItem> spItem = ((class CPetManager*)FUN_140535320())->FUN_140c8b430()->FUN_140c892c0(FUN_140f4e180());
    if (spItem.get() != 0)
        FUN_140d2cfc0(spItem);
    return DragSlot::vfunc_15();
}

// @0x140f4e3e0
int UIItemAutoUseOptionDialog::Slot::vfunc_17()
{
    return vfunc_11();
}

// @0x140f4e410
int UIItemAutoUseOptionDialog::Slot::vfunc_18(void* p)
{
    Unk_AuPlayer* pPlayer = ((class Unk_AuWorld*)WorldService::GetInstance())->FUN_141bd0cc0();
    if (pPlayer == 0)
        return static_cast<DragSlot*>(p)->vfunc_10();
    Slot* pFrom = FUN_140f507b0(static_cast<DragSlot*>(p));
    if (pFrom != 0)
    {
        int nOld = pFrom->FUN_140f4e180();
        pFrom->FUN_140f4e1a0(m_nItemId);
        FUN_140f4e1a0(nOld);
        FUN_140f4f030(pFrom->GetIndex());
        vfunc_10();
    }
    else if (PetSlot* pPet = FUN_140dbc0d0(static_cast<DragSlot*>(p)))
    {
        MS2Ptr<CItem> spItem = ((class CPetManager*)FUN_140535320())->FUN_140c8b430()->FUN_140c892c0(pPet->FUN_140dbafc0());
        if (FUN_140534e50(&spItem) != 0)
            return static_cast<DragSlot*>(p)->vfunc_10();
        if (FUN_140f4e1c0(spItem->FUN_1405276c0()) != 0)
        {
            FUN_140d73bc0(0xc1d, 0, 0, CStringW(L""));
            return static_cast<DragSlot*>(p)->vfunc_10();
        }
        if (!spItem->FUN_140527840()->FUN_14053d270())
        {
            FUN_140d73bc0(0xc1c, 0, 0, CStringW(L""));
            return static_cast<DragSlot*>(p)->vfunc_10();
        }
        if (((class CItem*)(class CItem*)(spItem.get()))->FUN_140526810(AU_PLAYER_LEVEL(pPlayer)) == 0)
        {
            FUN_140d73aa0(GetStringCommonByKey(L"s_err_not_enough_level"), 0, 0, CStringW(L""));
            return 1;
        }
        m_nItemId = pPet->FUN_140dbafc0();
        FUN_1414048f0(m_nItemId);
        vfunc_10();
    }
    else if (void* pItemSlot = FUN_140a50b50(static_cast<DragSlot*>(p)))
    {
        MS2Ptr<CItem> spItem = ((class CPetManager*)FUN_140535320())->FUN_140c8b430()->FUN_140c892c0(((class InvenSlot*)(void*)(pItemSlot))->FUN_141405980());
        if (FUN_140534e50(&spItem) != 0)
            return static_cast<DragSlot*>(p)->vfunc_10();
        if (FUN_140f4e1c0(spItem->FUN_1405276c0()) != 0)
        {
            FUN_140d73bc0(0xc1d, 0, 0, CStringW(L""));
            return static_cast<DragSlot*>(p)->vfunc_10();
        }
        if (!spItem->FUN_140527840()->FUN_14053d270())
        {
            FUN_140d73bc0(0xc1c, 0, 0, CStringW(L""));
            return static_cast<DragSlot*>(p)->vfunc_10();
        }
        if (((class CItem*)(class CItem*)(spItem.get()))->FUN_140526810(AU_PLAYER_LEVEL(pPlayer)) == 0)
        {
            FUN_140d73aa0(GetStringCommonByKey(L"s_err_not_enough_level"), 0, 0, CStringW(L""));
            return 1;
        }
        m_nItemId = ((class InvenSlot*)(void*)(pItemSlot))->FUN_141405980();
        FUN_1414048f0(m_nItemId);
        vfunc_10();
    }
    return static_cast<DragSlot*>(p)->vfunc_10();
}

// @0x140f4eb30
void UIItemAutoUseOptionDialog::Slot::vfunc_23(void* p)
{
    FUN_141404ce0(FUN_140f4e0e0(), p, &m_value18);
}

// @0x140f4eb80
void UIItemAutoUseOptionDialog::Slot::vfunc_24(void* p)
{
    FUN_1414050c0(FUN_140f4e0e0(), p, &m_value18);
}

// @0x140f4ebd0 (ITooltip::vfunc_0)
int UIItemAutoUseOptionDialog::Slot::vfunc_0(void* p)
{
    Unk_AuPlayer* pPlayer = ((class Unk_AuWorld*)WorldService::GetInstance())->FUN_141bd0cc0();
    if (pPlayer == 0)
        return 0;
    MS2Ptr<CItem> spItem = ((class CPetManager*)FUN_140535320())->FUN_140c8b430()->FUN_140c892c0(FUN_140f4e180());
    if (FUN_140534e50(&spItem) != 0)
        return 0;
    MS2Ptr<CItem> spWorn = pPlayer->FUN_14152e2f0(spItem);
    if (spWorn.get() != 0 ? true : false)
    {
        if (spWorn->FUN_140526a50() == spItem->FUN_140526a50())
            return 0;
    }
    ASTooltip tip(pPlayer, 0x80, 2);
    if (tip.FUN_1409e13a0(spWorn.get(), spItem.get()) != 0)
    {
        *static_cast<Scaleform::GFx::Value*>(p) = tip.FUN_1422bb870();
        return 1;
    }
    return 0;
}

// @0x140f4ee10
int UIItemAutoUseOptionDialog::Slot::vfunc_8(void* p)
{
    Unk_AuPlayer* pPlayer = ((class Unk_AuWorld*)WorldService::GetInstance())->FUN_141bd0cc0();
    if (pPlayer == 0)
        return 0;
    MS2Ptr<CItem> spItem = ((class CPetManager*)FUN_140535320())->FUN_140c8b430()->FUN_140c892c0(FUN_140f4e180());
    if (spItem.get() != 0)
    {
        FUN_140f4f100(1);
        ASSlot slot(2);
        if (slot.FUN_1409c3860(spItem.get(), pPlayer, 0x1c01f) != 0)
        {
            slot.FUN_1409c2190(((class CPetManager*)FUN_140535320())->FUN_140c8b430()->FUN_140c89440(spItem->FUN_1405276c0(), 0));
            *static_cast<Scaleform::GFx::Value*>(p) = slot.FUN_1422bb870();
        }
    }
    else
    {
        FUN_140f4f100(0);
        Unk_PetOption opt;
        if (((class CPetManager*)FUN_140535320())->FUN_140c8b450()->options.map.Lookup(m_nIndex, opt))
        {
            ASSlot slot(2);
            if (slot.FUN_1409c4510(opt.enabled, 1, 0) != 0)
            {
                slot.FUN_1409c1e80(1);
                *static_cast<Scaleform::GFx::Value*>(p) = slot.FUN_1422bb870();
            }
        }
    }
    return 1;
}

// @0x140f4f030 swap the option rows of this slot and nOtherIndex
void UIItemAutoUseOptionDialog::Slot::FUN_140f4f030(int nOtherIndex)
{
    Unk_PetOption kThis;
    Unk_PetOption kOther;
    ((class CPetManager*)FUN_140535320())->FUN_140c8b450()->options.map.Lookup(m_nIndex, kThis);
    ((class CPetManager*)FUN_140535320())->FUN_140c8b450()->options.map.Lookup(nOtherIndex, kOther);
    ((class CPetManager*)FUN_140535320())->FUN_140c8b450()->options.map.SetAt(m_nIndex, kOther);
    ((class CPetManager*)FUN_140535320())->FUN_140c8b450()->options.map.SetAt(nOtherIndex, kThis);
}

// @0x140f4f100
void UIItemAutoUseOptionDialog::Slot::FUN_140f4f100(int nState)
{
    UIItemAutoUseOptionDialog* pDlg = FUN_140cbe1c0(0x4ef4);
    if (pDlg != 0)
    {
        if (pDlg->FUN_141924630() != 0)
            pDlg->FUN_140f50090(nState, m_nIndex);
    }
}

// @0x140f4f160 create the bag and register it under the name
void FUN_140f4f160(const CString& strName, int nCount)
{
    UIItemAutoUseOptionDialog::SlotBag* pBag =
        new (efd::MemHint(efd::MemHint::NONE)) UIItemAutoUseOptionDialog::SlotBag(strName);
    if (pBag)
    {
        static_cast<DragSlotBag*>(pBag)->vfunc_10(nCount);
        FUN_1422c8f10(strName, pBag);
    }
}

// @0x140f4f210 destroy the registered bag
void FUN_140f4f210(const CString& strName)
{
    UIItemAutoUseOptionDialog::SlotBag* pBag = FUN_140f50800(FUN_1422c8e90(strName));
    if (pBag)
    {
        ((class DragSlotBag*)(class DragSlotBag*)(pBag))->FUN_1422cc9e0();
        FUN_1422c8f70(strName);
    }
}

// @0x140f4f260
UIItemAutoUseOptionDialog::SlotBag::SlotBag(const CString& strName)
    : DragSlotBag(strName)
{
}

// @0x140f4f2a0
UIItemAutoUseOptionDialog::SlotBag::~SlotBag()
{
}

// @0x140f4f2d0
DragSlot* UIItemAutoUseOptionDialog::SlotBag::vfunc_16(int nIndex)
{
    CString strName = vfunc_15(nIndex);
    Unk_PetOption opt;
    if (((class CPetManager*)FUN_140535320())->FUN_140c8b450()->options.map.Lookup(nIndex, opt))
        return new (efd::MemHint(efd::MemHint::NONE)) Slot(strName, nIndex, opt.enabled);
    return new (efd::MemHint(efd::MemHint::NONE)) Slot(strName, nIndex, 0);
}

// @0x140f4f460
UIItemAutoUseOptionDialog::UIItemAutoUseOptionDialog()
    : m_strBag(GetTypeName())
{
    m_164 = 1;
    FUN_141924170(1);
    for (int n = DAT_1439ed004 - 1; n >= 0; n--)
        m_thresholds.Add(n * 10);
}

// @0x140f4f560
UIItemAutoUseOptionDialog::~UIItemAutoUseOptionDialog()
{
}

// @0x140f4f5f0
CString UIItemAutoUseOptionDialog::GetTypeName()
{
    return "ItemAutoUseOptionDialog";
}

// @0x140f4f640
int UIItemAutoUseOptionDialog::vfunc_65()
{
    if (UIDialog::vfunc_65() == 0)
        return 0;
    ((class UIStatusEventDispatcher*)TSingleton<UIStatusEventDispatcher>::GetInstance())->FUN_141b0cd00(static_cast<UIStatusEventListener*>(this));
    return 0;
}

// @0x140f4f6a0
void UIItemAutoUseOptionDialog::vfunc_67()
{
    FUN_140f4f210(m_strBag);
    ((class UIStatusEventDispatcher*)TSingleton<UIStatusEventDispatcher>::GetInstance())->FUN_141b0cd90(static_cast<UIStatusEventListener*>(this));
    UIDialog::vfunc_67();
}

// @0x140f4f710
void UIItemAutoUseOptionDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    if (MS2Ptr<ASTextField> spText1 = ((Unk_AuEntity*)this)->FUN_140bb4cf0("m_textFieldItem1"))
        spText1->FUN_1422c4cd0(GetStringCommon(0xc08));
    if (MS2Ptr<ASTextField> spText2 = ((Unk_AuEntity*)this)->FUN_140bb4cf0("m_textFieldItem2"))
        spText2->FUN_1422c4cd0(GetStringCommon(0xc08));
    for (unsigned i = 0; i < DAT_1439ed000; i++)
    {
        int nNumber = i + 1;
        CString strName = FUN_140513200("m_dropdownItem{0}", nNumber);
        FUN_140f50230(((Unk_AuEntity*)this)->FUN_140c28560(strName).get(), i);
    }
    FUN_140f50190();
}

// @0x140f4f990
void UIItemAutoUseOptionDialog::vfunc_15()
{
    UISwfEntity::vfunc_15();
    FUN_1419235d0();
}

// @0x140f4f9c0
int UIItemAutoUseOptionDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (_stricmp("OnClickOk", szMethod) == 0)
    {
        OnClickOk();
        return 1;
    }
    return 0;
}

// @0x140f4fa30
void UIItemAutoUseOptionDialog::vfunc_oa0_25(void* p)
{
    DragSlotBag* pBag = FUN_140c544d0(FUN_1422c8e90(m_strBag));        // the exe casts to the base DragSlotBag here
    if (pBag != 0)
        pBag->vfunc_11(p);
}

// @0x140f4fa90
void UIItemAutoUseOptionDialog::vfunc_oa0_26(void* p)
{
    DragSlotBag* pBag = FUN_140c544d0(FUN_1422c8e90(m_strBag));        // the exe casts to the base DragSlotBag here
    if (pBag != 0)
        pBag->vfunc_12(p);
}

// @0x140f4faf0
int UIItemAutoUseOptionDialog::FUN_140f4faf0(int nItemId)
{
    Unk_AuPlayer* pPlayer = ((class Unk_AuWorld*)WorldService::GetInstance())->FUN_141bd0cc0();
    if (pPlayer == 0)
        return 0;
    SlotBag* pBag = FUN_140f50800(FUN_1422c8e90(m_strBag));
    if (pBag != 0)
    {
        for (unsigned i = 0; i < FUN_1422ccd20(pBag); i++)
        {
            Slot* pSlot = FUN_140f507b0(((class DragSlotBag*)(class DragSlotBag*)(pBag))->FUN_1422cd070(i));
            if (pSlot == 0)
                continue;
            MS2Ptr<CItem> spItem = ((class CPetManager*)FUN_140535320())->FUN_140c8b430()->FUN_140c892c0(pSlot->FUN_140f4e180());
            if (spItem == 0)
                continue;
            if (spItem->FUN_1405276c0() == nItemId)
                return 1;
        }
    }
    return 0;
}

// @0x140f4fc40
void UIItemAutoUseOptionDialog::FUN_140f4fc40(int nItemId)
{
    Unk_AuPlayer* pPlayer = ((class Unk_AuWorld*)WorldService::GetInstance())->FUN_141bd0cc0();
    if (pPlayer == 0)
        return;
    MS2Ptr<CItem> spItem = ((class CPetManager*)FUN_140535320())->FUN_140c8b430()->FUN_140c892c0(nItemId);
    if (spItem == 0)
        return;
    if (!spItem->FUN_140527840()->FUN_14053d270())
    {
        FUN_140d73bc0(0xc1c, 0, 0, CStringW(L""));
        return;
    }
    if (FUN_140f4faf0(spItem->FUN_1405276c0()) != 0)
    {
        FUN_140d73bc0(0xc1d, 0, 0, CStringW(L""));
        return;
    }
    if (((class CItem*)(class CItem*)(spItem.get()))->FUN_140526810(AU_PLAYER_LEVEL(pPlayer)) == 0)
    {
        FUN_140d73aa0(GetStringCommonByKey(L"s_err_not_enough_level"), 0, 0, CStringW(L""));
        return;
    }
    SlotBag* pBag = FUN_140f50800(FUN_1422c8e90(m_strBag));
    if (pBag != 0)
    {
        unsigned nCount = FUN_1422ccd20(pBag);
        for (unsigned i = 0; i < nCount; i++)
        {
            Slot* pSlot = FUN_140f507b0(((class DragSlotBag*)(class DragSlotBag*)(pBag))->FUN_1422cd070(i));
            if (pSlot == 0)
                continue;
            if (pSlot->FUN_140f4e180() == 0)
            {
                pSlot->FUN_140f4e1a0(nItemId);
                pSlot->vfunc_10();
                return;
            }
        }
        for (unsigned i = 0; i < nCount; i++)
        {
            Slot* pSlot = FUN_140f507b0(((class DragSlotBag*)(class DragSlotBag*)(pBag))->FUN_1422cd070(i));
            if (pSlot == 0)
                continue;
            MS2Ptr<CItem> spOld = ((class CPetManager*)FUN_140535320())->FUN_140c8b430()->FUN_140c892c0(pSlot->FUN_140f4e180());
            if (spOld == 0)
            {
                pSlot->FUN_140f4e1a0(nItemId);
                pSlot->vfunc_10();
                return;
            }
        }
        Slot* pFirst = FUN_140f507b0(((class DragSlotBag*)(class DragSlotBag*)(pBag))->FUN_1422cd070(0));
        if (pFirst != 0)
        {
            pFirst->FUN_140f4e1a0(nItemId);
            pFirst->vfunc_10();
        }
    }
}

// @0x140f50090
void UIItemAutoUseOptionDialog::FUN_140f50090(int nState, int nIndex)
{
    int nNumber = nIndex + 1;
    CString strName = FUN_1402bad60("m_dropdownItem{0}", &nNumber);
    MS2Ptr<Unk_AuCombo> spCombo = ((Unk_AuEntity*)this)->FUN_140c28560(strName);
    if (spCombo)
    {
        if (nState == 0)
            spCombo.get()->FUN_1422c1fe0(0);
        else if (nState == 1)
            spCombo.get()->FUN_1422c1fe0(1);
        else if (nState == 2)
        {
            spCombo.get()->FUN_1422df690(DAT_1439ed004 - 1);
            spCombo.get()->FUN_1422c1fe0(0);
        }
    }
}

// @0x140f50190
void UIItemAutoUseOptionDialog::FUN_140f50190()
{
    FUN_140f4f210(m_strBag);
    FUN_140f4f160(m_strBag, DAT_1439ed000);
    ASDialog* pDlg = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDlg != 0)
        pDlg->Invoke("createSlotBag");
}

// @0x140f50230
void UIItemAutoUseOptionDialog::FUN_140f50230(void* pCombo, int nIndex)
{
    if (pCombo == 0)
        return;
    ((Unk_AuCombo*)pCombo)->FUN_1422dfc10();
    for (unsigned i = 0; i < m_thresholds.GetCount(); i++)
    {
        int nCond = m_thresholds[i];
        if (nCond == 0)
        {
            ASObj entry(2);
            entry.FUN_1409c0d20("condition", nCond);
            entry.FUN_1407cbb20("label", GetStringCommon(0x576));
            ((Unk_AuCombo*)pCombo)->FUN_1422dfc70(entry);
        }
        else
        {
            ASObj entry(2);
            entry.FUN_1409c0d20("condition", nCond);
            entry.FUN_1407cbb20("label", FUN_1409e97f0(0xc09, nCond));
            ((Unk_AuCombo*)pCombo)->FUN_1422dfc70(entry);
        }
    }
    ((Unk_AuCombo*)pCombo)->vfunc_24(true);
    Unk_PetOption opt;
    if (((class CPetManager*)FUN_140535320())->FUN_140c8b450()->options.map.Lookup(nIndex, opt))
        ((Unk_AuCombo*)pCombo)->FUN_1422df690(opt.type);
    else
        ((Unk_AuCombo*)pCombo)->FUN_1422df690(DAT_1439ed004 - 1);
}

// @0x140f50480
void UIItemAutoUseOptionDialog::OnClickOk()
{
    Unk_AuPlayer* pPlayer = ((class Unk_AuWorld*)WorldService::GetInstance())->FUN_141bd0cc0();
    if (pPlayer == 0)
        return;
    void* pPet = FUN_141676a10(pPlayer);
    if (pPet == 0)
        return;
    SlotBag* pBag = FUN_140f50800(FUN_1422c8e90(m_strBag));
    if (pBag == 0)
        return;
    int bBlocked = 0;
    Unk_PetOptions kOptions;
    for (unsigned i = 0; i < DAT_1439ed000; i++)
    {
        int nNumber = i + 1;
        CString strName = FUN_140513200("m_dropdownItem{0}", nNumber);
        MS2Ptr<Unk_AuCombo> spCombo = ((Unk_AuEntity*)this)->FUN_140c28560(strName);
        if (spCombo)
        {
            int nIdx = i;
            int nSel = spCombo->FUN_1422df6c0();
            Slot* pSlot = FUN_140f507b0(((class DragSlotBag*)(class DragSlotBag*)(pBag))->FUN_1422cd070(nIdx));
            if (pSlot != 0)
            {
                int nItemId = pSlot->FUN_140f4e180();
                if (nSel > -1 && nSel < (int)m_thresholds.GetCount())
                {
                    float fValue = (float)m_thresholds[nSel];
                    Unk_PetOption opt(nSel, fValue, nItemId);
                    kOptions.map.SetAt(nIdx, opt);
                }
                else if (nItemId != 0)
                    bBlocked = 1;
            }
        }
    }
    if (kOptions.FUN_1401ff680() != 0)
    {
        if (bBlocked != 0)
            FUN_140d73bc0(0xc1f, 0, 0, CStringW(L""));
        else
        {
            COutPacket packet(static_cast<int>(SendOp::RequestPet), 0);
            packet.WriteUInt8(5);
            kOptions.FUN_1401ff3f0(packet);
            FUN_140710590(packet);
            vfunc_67();
        }
    }
    else
        FUN_140d73bc0(0xc1e, 0, 0, CStringW(L""));
}

// @0x140f507b0
UIItemAutoUseOptionDialog::Slot* FUN_140f507b0(NotifyContext::BindData* p)
{
    UIItemAutoUseOptionDialog::Slot* pSlot = 0;
    if (p != 0 && p->TypeCast(0x6200068, (void**)&pSlot))
        return pSlot;
    else
        return 0;
}

// @0x140f50800
UIItemAutoUseOptionDialog::SlotBag* FUN_140f50800(NotifyContext::BindData* p)
{
    UIItemAutoUseOptionDialog::SlotBag* pBag = 0;
    if (p != 0 && p->TypeCast(0x6200069, (void**)&pBag))
        return pBag;
    else
        return 0;
}

MS2_EMIT_CRT_MEMMOVE_S();
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca9a10-0x142ca9ac0 .text$yd
