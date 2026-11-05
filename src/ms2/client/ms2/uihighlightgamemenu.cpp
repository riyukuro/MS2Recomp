// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIHighlightGameMenu: see uihighlightgamemenu.h.
// MS2-UNIT: ?\uihighlightgamemenu.cpp
// MS2-RANGE: 0x140c220d0-0x140c26440 .text$mn
// MS2-RANGE: 0x1400cc590-0x1400cc7a0 .text$di
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?vfunc_48@UIHighlightGameMenu@@UEAAHXZ 0x140c25180 ; unique
// MS2-PIN: ?vfunc_3@UIItemEventListener@@UEAAXPEAX_N@Z 0x140c255d0 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ??_G?$DelegateImpl@U?$pair@PEAVUIHighlightGameMenu@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEAAPEAXI@Z 0x140c24b10
// MS2-GUESS-LOOKALIKES
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uihighlightgamemenu.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"

#include "uihighlightgamemenu.h"
#include "uiitemsocketsystemdialog.h"

#include <errno.h>
#include <stdlib.h>
#include <string.h>

#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/astooltip.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/cgamemenutable.h"
#include "ms2/placeholder/citem.h"

#include "ms2/placeholder/header_statics_a.h"

#include "ms2/ms2recover.h"
#include "ms2/ms2format.h"  // C3: StringFormat<CString>
#include "ms2/commonfiles/usermail.h"  // C3: CUserMail, Unk_MailPtr<CMailInfo>
#include "hook/ms2hook.h"
#include "ms2/placeholder/notifysystem.h"
#include "ms2/commonfiles/featuremanager.h"
#include "ms2/placeholder/citemdata.h"  // C3: was a local member view
#include "ms2/commonfiles/itemsocket.h"  // C3: was a local member view
#include "ms2/placeholder/uibottomcenteralignmanager.h"  // C3: was a local member view
#include "ms2/commonfiles/itemenchantlimittable.h"  // C3: was a local member view
#include "ms2/placeholder/mstime.h"  // C3: was a local member view
#include "ms2/client/ms2/uiservice.h"  // C3: CUIService::ToggleDialog
#include "ms2/placeholder/clientconstants.h"  // C3: Common::Constants::Value<unsigned int>::Get
#include "ms2/placeholder/cgameoption.h"  // C3: CGameOption::FUN_140b123b0
#include "ms2/client/ms2/equipment.h"  // C3: CEquipment::CollectShownItemsInLayer
#include "ms2/client/ms2/equipitem.h"  // C3: CEquipItem::GetItem
#include "ms2/commonfiles/enchantscrolldata.h"  // C3: CEnchantScrollTable::FindScroll
#include "ms2/commonfiles/itemgemstonedata.h"  // C3: CItemGemStoneUpgradeTable::FindData
#include "ms2/commonfiles/timeutil.h"  // C3: GetServerTime
#include "ms2/commonfiles/os.h"
#include "ms2/client/ms2/inventory.h"  // C3: Unk_Inventory (was Unk_HlDb members)
#include "ms2/client/ms2/statpointmanager.h"  // C3: CStatPointManager::GetRemaining
class CItemData;   // C3: MS2Ptr<CItemData>::operator->

// The key-input controller singleton of this unit.
static UICommon::CMyPCKeyInputController s_keyInputController;

// Two zero-initialised handles (static initialised by the ctor 0x1401cd100 on &DAT, 0).
struct Unk_RegMarker {};
class Unk_BuddyHandle { public: Unk_BuddyHandle(void*); private: void* m_p; };   // ctor 0x1401cd100 (C3: was a FUN_1401cd100 declaration)
static void* s_dat_143abe528;
static Unk_RegMarker s_init_143abe528 = (reinterpret_cast<Unk_BuddyHandle*>(&s_dat_143abe528)->Unk_BuddyHandle::Unk_BuddyHandle(0), Unk_RegMarker());
static void* s_dat_143abe530;
static Unk_RegMarker s_init_143abe530 = (reinterpret_cast<Unk_BuddyHandle*>(&s_dat_143abe530)->Unk_BuddyHandle::Unk_BuddyHandle(0), Unk_RegMarker());

static CString s_strSortNames8[] = {"None", "Buy", "PriceLow", "PriceHigh", "Create", "ChartOrder", "BuyTotal", "EnumEnd"};

// ---- unit-local views of unrecovered callees -------------------------------------------------------------------------

typedef void* P;

class ASDialog : public ASDisplayObject {};

class MyPC   // C3: member view (the real header pulls in the PC tree)
{
public:
    MS2Ptr<CItem> FUN_14152e2f0(MS2Ptr<CItem> spItem);       // the worn item spItem would replace
    int FUN_14152e970(int nId);                              // the free skill points of nId
};

class CItem;
int UseItem(MS2Ptr<CItem> spItem, int n);                  // 0x140d1bd60

// The item / record tables (DAT_143ab2a90) and their callees.
extern Unk_Inventory g_143ab2a90;   // C3: was DAT_143ab2a90
extern CUserMail g_143ab2ee0;   // C3: was extern char DAT_143ab2ee0[]

class Unk_HlAS : public AScript
{
public:
};
void FUN_140614800(Scaleform::GFx::Value* v);               // ~Value
CStringW GetStringCommonByKey(const CStringW& str);

class Unk_SingletonObj* FUN_140939a10();   // C3: was NotifySystem*

class Unk_140166410* FUN_140166410();   // C3: was CFeatureManager*

class Unk_ItemEventSystem { public: void FUN_1419cae20(UIItemEventListener* pListener); void FUN_1419caeb0(UIItemEventListener* pListener); };
class Unk_InventoryListener* FUN_140a6a840();   // C3: was FUN_140a6a840

class WorldService   // C3: member view
{
public:
    static WorldService* GetInstance();
    void* FUN_141bd0cc0();
};
// The stat point manager at player+0x1120 is held in an MS2Ptr<CStatPointManager> (copy ctor 0x140c24920, dtor
// 0x140c24a50, operator-> 0x140c24af0, AddRef 0x140c25e00, AddRefImpl 0x140c25e50, Reference 0x140c25e30, Release
// 0x140c25e80, ReleaseImpl 0x140c25ec0: the ms2ptr_impl.h bodies).

// The local player: slot 78 returns the level.
class Unk_HlPc
{
public:
    MS2Ptr<CStatPointManager> FUN_140c25130();             // copy of the stat point manager handle
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
    virtual unsigned short vfunc_78();

    char m_pad_08[0x1120 - 8];
    MS2Ptr<CStatPointManager> m_statRef;                   // +0x1120
};
int FUN_1418dd0d0();

// The menu table (see uigamepadmenudialog.cpp) and the inventory / socket dialogs.
class Unk_HlMenu
{
public:
    char m_pad_00[0x30];
    char m_tail[8];                                         // +0x30
    char m_pad_38[0x30];
    int m_nUiId;                                            // +0x68
};
struct Unk_HlMenuRef { void* m_unk_00; Unk_HlMenu* m_p; };
class Unk_GpDb* FUN_140c1d2f0();   // C3: was FUN_140c1d2f0
void FUN_140cf7470(P pDb, Unk_HlMenuRef* pOut, CString strName);
P FUN_140c1cd90(Unk_HlMenuRef* p);
Unk_HlMenu* FUN_140c1cda0(Unk_HlMenuRef* p);
void FUN_140c1ccf0(Unk_HlMenuRef* p);
char FUN_14098d930(void* pTail);
void FUN_14098d150(void* pTail);
class CUIService;
class UIInventoryDialog;
template<class T> T* Unk_BreakDialog(int);   // C3: was UIDialog* FUN_1405344f0 (calls cast back)
class UIInventoryDialog   // C3: member view for the former free stand-ins
{
public:
    void FUN_141999d40(int);
};
P FUN_140c24650();
int FUN_140c25190();


// item handles / records

// the player
class JobSystemCli;
class PC   // C3: member view
{
public:
    JobSystemCli* FUN_1416546d0();
    int FUN_141654700();
    int FUN_141654730();                                    // job code
    struct Unk_PCEquipSet* FUN_1416561a0();
};
class JobTable   // C3: member view
{
public:
    int GetJobRank(int nJob);
};
class JobSystem   // C3: member view
{
public:
    int GetUsedPoint(int nId);
};
class CLua   // C3: member view
{
public:
    int CalcAvailableSkillPoint(unsigned short nLevel);
};
class Unk_SingletonObj1* FUN_1401d3200();   // C3: was FUN_1401d3200
class CGameOption;

// lists, arrays, item records
class Unk_CommandArgs   // C3: member view for the former free stand-ins
{
public:
    int FUN_1408d1f60(unsigned int, int);
};
void AddMinutes(class CMsTime&, int);   // C3: was FUN_14086a880
template <class T> int Unk_ArrayFind(const ATL::CAtlArray<T>& rArray, const T& value);   // C3: was FUN_140408410


// ---- tiny in-unit helpers ---------------------------------------------------------------------------------------------

// @0x140c24ef0
P FUN_140c24ef0()
{
    return TSingleton<UIBottomCenterAlignManager>::s_instance;
}

// @0x140c25190
int FUN_140c25190()
{
    return 0x4f0a;
}

// @0x140c25130
MS2Ptr<CStatPointManager> Unk_HlPc::FUN_140c25130()
{
    return m_statRef;
}

// @0x140c25330
bool FUN_140c25330(void* p)
{
    return *(__int64*)((char*)p + 0x10) == 0;
}

struct Unk_HlArr { __int64 m_pData; unsigned __int64 m_nSize; };

// @0x140c24ea0
P FUN_140c24ea0(__int64* pArr, unsigned __int64 n)
{
    if (!(n < ((Unk_HlArr*)pArr)->m_nSize))
        ATL::AtlThrowImpl(0x80070057);
    return (P)(n * 0x10 + *pArr);
}

// ---- the bit set ------------------------------------------------------------------------------------------------------

extern "C" _ACRTIMP void __cdecl _wassert(wchar_t const* _Message, wchar_t const* _File, unsigned _Line);
#define HL_BITSET_ASSERT(line) _wassert(L"0", L"e:\\build\\kr\\22_04\\ms2code\\commonfiles\\bitset.inl", line)

// @0x140c249d0
Unk_HlBitRef::Unk_HlBitRef(Unk_HlBits* pBits, int nPos)
{
    m_pBits = pBits;
    m_nPos = nPos;
}

// @0x140c24ac0
bool Unk_HlBitRef::FUN_140c24ac0()
{
    return m_pBits->FUN_140c261e0(m_nPos);
}

// @0x140c25f10
Unk_HlBitRef Unk_HlBits::FUN_140c25f10(int nPos)
{
    return Unk_HlBitRef(this, nPos);
}

// @0x140c260a0
Unk_HlBits& Unk_HlBits::FUN_140c260a0(int nPos, bool bSet)
{
    if ((unsigned)nPos >= 1)
        (void)((!!0) || (HL_BITSET_ASSERT(0xf3), 0));
    if (bSet)
        m_a[nPos / 8] |= 1 << nPos % 8;
    else
        m_a[nPos / 8] &= ~(1 << nPos % 8);
    return *this;
}

// @0x140c261e0
bool Unk_HlBits::FUN_140c261e0(int nPos) const
{
    if ((unsigned)nPos >= 1)
    {
        (void)((!!0) || (HL_BITSET_ASSERT(0x194), 0));
        return false;
    }
    return (m_a[nPos / 8] & (1 << nPos % 8)) != 0;
}

// @0x140c262e0
void Unk_HlBits::FUN_140c262e0()
{
    if (0 != 1) {} else
        m_a[0] &= (1 << 1 % 8) - 1;
}

// @0x140c26280
void Unk_HlBits::FUN_140c26280(unsigned char nFill)
{
    for (int i = 0; 0 <= i; --i)
        m_a[i] = nFill;
    if (nFill != 0)
        FUN_140c262e0();
}

// @0x140c24770
Unk_HlBits& Unk_HlBits::FUN_140c24770()
{
    FUN_140c26280(0);
    return *this;
}

// @0x140c261c0
Unk_HlBits& Unk_HlBits::FUN_140c261c0()
{
    FUN_140c26280((unsigned char)0xff);
    return *this;
}

// @0x140c26080
Unk_HlBits& Unk_HlBits::FUN_140c26080()
{
    FUN_140c26280(0);
    return *this;
}

// ---- the dialog -------------------------------------------------------------------------------------------------------

// @0x140c220d0
UIHighlightGameMenu::UIHighlightGameMenu()
    : m_actions(17, 0.75f, 0.25f, 2.25f, 10)
{
    m_nScrollItem = 0;
    m_nTargetItem = 0;
    m_nCount = 0;
    m_nMargin = 0;
    m_bActive = false;
    m_bitsGem.FUN_140c24770();
    m_bitsSocket.FUN_140c24770();
    m_2c = 0xe;
    FUN_141925e70(0, 1);
    m_actions.SetAt("characterinfo", &UIHighlightGameMenu::FUN_140c236f0);
    m_actions.SetAt("skillbook", &UIHighlightGameMenu::FUN_140c234d0);
    m_actions.SetAt("inven", &UIHighlightGameMenu::FUN_140c231b0);
    m_actions.SetAt("mail", &UIHighlightGameMenu::FUN_140c235d0);
    if (((CFeatureManager*)FUN_140166410())->IsRegionNA())
        m_actions.SetAt("enchantscroll", &UIHighlightGameMenu::FUN_140c237a0);
    m_actions.SetAt("gemstone", &UIHighlightGameMenu::FUN_140c23f10);
    ((NotifySystem*)FUN_140939a10())->RegisterNotify(CStringW(L"NotifyGameStart"),
        Delegate<void(NotifyObject*)>(this, &UIHighlightGameMenu::FUN_140c24470));
}

// @0x140c22550
UIHighlightGameMenu::~UIHighlightGameMenu()
{
    ((NotifySystem*)FUN_140939a10())->UnregisterNotify(CStringW(L"NotifyGameStart"),
        Delegate<void(NotifyObject*)>(this, &UIHighlightGameMenu::FUN_140c24470));
}

// @0x140c22690
CString UIHighlightGameMenu::GetTypeName()
{
    return "HighlightGameMenu";
}

// @0x140c226e0
void UIHighlightGameMenu::vfunc_67()
{
    UIDialog::vfunc_67();
}

// @0x140c22700
void UIHighlightGameMenu::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    ((class Unk_ItemEventSystem*)FUN_140a6a840())->FUN_1419cae20(static_cast<UIItemEventListener*>(this));
    FUN_140c22f50();
}

// @0x140c22760
void UIHighlightGameMenu::vfunc_43()
{
    ASDialog* pDlg = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDlg != 0)
    {
        int nHeight = FUN_1418dd0d0() + 0x24;
        pDlg->vfunc_2(2, 8, -1 * nHeight + m_nMargin);
    }
}

// @0x140c22800
int UIHighlightGameMenu::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (_stricmp(szMethod, "enchantscroll") == 0)
    {
        MS2Ptr<CItem> spItem = g_143ab2a90.FUN_140a5d680(m_nScrollItem);
        if (spItem.get() != 0)
        {
            UseItem(spItem, 0);
            UIDialog* pInv = reinterpret_cast<UIDialog*>(Unk_BreakDialog<UIInventoryDialog>(0x4e2d));
            if (pInv != 0)
            {
                ((class UIInventoryDialog*)(class UIDialog*)(pInv))->FUN_141999d40(0);
                if (pInv->FUN_141924630() == 0)
                    pInv->FUN_141924680();
            }
        }
        return 1;
    }
    else if (_stricmp(szMethod, "gemstone") == 0)
    {
        P pDlg = FUN_140c24650();
        if (pDlg != 0)
        {
            int nArg = 1;
            ((class UIItemSocketSystemDialog*)(void*)(pDlg))->FUN_140f69c10(*(int const*)(&nArg));
        }
        return 1;
    }
    else
    {
        MS2Ptr<CGameMenuDef> spMenu = ((class CGameMenuTable*)FUN_140c1d2f0())->FindByName(CString(szMethod));
        if (spMenu.get() != 0)
        {
            if (spMenu->m_nUiId == 0x4e2d)
            {
                if (((CUIService*)(TSingleton<CUIService>::GetInstance()))->FUN_141adc940((eUIClassID)0x4e2d) != 0)
                {
                    UIDialog* pInv = reinterpret_cast<UIDialog*>(Unk_BreakDialog<UIInventoryDialog>(0x4e2d));
                    if (pInv != 0)
                        ((class UIInventoryDialog*)(class UIDialog*)(pInv))->FUN_141999d40(0);
                }
            }
            if (!spMenu->m_onClick.IsNull())
                spMenu->m_onClick();
            else if (spMenu->m_nUiId != 0)
                (((CUIService*)(TSingleton<CUIService>::GetInstance()))->ToggleDialog((eUIClassID)(spMenu->m_nUiId)));
            return 1;
        }
    }
    return 0;
}

// @0x140c22ae0
void UIHighlightGameMenu::vfunc_72()
{
    UIDialog::vfunc_72();
    if (m_timer.Check(1000) != 0)
        FUN_140c22f50();
}

// @0x140c22b30
void UIHighlightGameMenu::vfunc_49(Scaleform::GFx::Value* pRetVal, ASData* pArgs)
{
    CStringW strKey = StringFormat(L"s_highlightgamemenu_{0}", pArgs->FUN_1422b8d30());
    ASTooltip tip(1, 2);
    int nOk = tip.ApplyTextTooltip(GetStringCommonByKey(strKey));
    if (nOk != 0)
    {
        tip.SetTooltipAlign(1);
        tip.SetOnDelay(0);
        tip.SetOffDelay(0);
        *pRetVal = tip.FUN_1422bb870();
    }
}

// @0x140c22c60
void UIHighlightGameMenu::vfunc_26()
{
    UIDialog::vfunc_26();
    ((class Unk_ItemEventSystem*)FUN_140a6a840())->FUN_1419caeb0(static_cast<UIItemEventListener*>(this));
}

// @0x140c22d00
void UIHighlightGameMenu::vfunc_5(void* pItem, int nCount)
{
    if ((*(const MS2Ptr<AScript>*)(&m_30) == 0) != 0) {} else
    {
        if (nCount == 0 || pItem == 0 || !((class CItemData*)(void*)(((void*)((class CItem*)(void*)(pItem))->FUN_140527840())))->FUN_14053d840()) {} else
            m_bitsGem.FUN_140c260a0(0, true);
    }
}

// @0x140c22d80
void UIHighlightGameMenu::vfunc_2(void* pItem)
{
    if ((*(const MS2Ptr<AScript>*)(&m_30) == 0) != 0) {} else
    {
        if (pItem == 0 || !((class CItemData*)(void*)(((void*)((class CItem*)(void*)(pItem))->FUN_140527840())))->FUN_14053d840()) {} else
            m_bitsGem.FUN_140c260a0(0, true);
    }
}

// @0x140c22df0
void UIHighlightGameMenu::vfunc_21(void* pItem)
{
    if ((*(const MS2Ptr<AScript>*)(&m_30) == 0) != 0) {} else
    {
        if (m_bitsSocket.FUN_140c25f10(0).FUN_140c24ac0() == true) {} else
        {
            if (pItem == 0 || ((void*)((class CItem*)(void*)(pItem))->GetSocket()) == 0) {} else
            {
                if (!((class CItemSocket*)(void*)(((void*)((class CItem*)(void*)(pItem))->GetSocket())))->HasEmptyOpenSlot()) {} else
                    m_bitsGem.FUN_140c260a0(0, true);
            }
        }
    }
}

// @0x140c22ea0
void UIHighlightGameMenu::vfunc_22(void* pItem)
{
    if ((*(const MS2Ptr<AScript>*)(&m_30) == 0) != 0) {} else
    {
        if (!m_bitsSocket.FUN_140c25f10(0).FUN_140c24ac0()) {} else
        {
            if (pItem == 0 || ((void*)((class CItem*)(void*)(pItem))->GetSocket()) == 0) {} else
            {
                if (!((class CItemSocket*)(void*)(((void*)((class CItem*)(void*)(pItem))->GetSocket())))->HasEmptyOpenSlot()) {} else
                    m_bitsGem.FUN_140c260a0(0, true);
            }
        }
    }
}

// @0x140c22f50
void UIHighlightGameMenu::FUN_140c22f50()
{
    if (((MS2Ptr<AScript>*)(void*)(&m_30))->IsNull())
        return;
    Unk_HlPc* pPc = (Unk_HlPc*)WorldService::GetInstance()->FUN_141bd0cc0();
    if (pPc == 0)
        return;
    if (pPc->vfunc_78() < *reinterpret_cast<Common::Constants::Value<unsigned int>*>((char*)((void*)FUN_1401d3200()) + 0xe558)->Get())
        return;
    ASArray names(2);
    if (*((unsigned char*)((void*)reinterpret_cast<CGameOption*>((TSingleton<CGameOption>::GetInstance()))->FUN_140b123b0()) + 0x15) == 0)
    {
        for (POSITION pos = m_actions.GetStartPosition(); pos != 0; m_actions.GetNext(pos))
        {
            Action pAction = m_actions.GetValueAt(pos);
            if ((this->*pAction)() != 0)
                names.PushString(m_actions.GetKeyAt(pos));
        }
    }
    int nCount = names.GetLength();
    if (m_nCount != nCount)
    {
        m_nCount = nCount;
        m_bActive = m_nCount != 0;
        if (FUN_140c24ef0() != 0)
            ((class UIBottomCenterAlignManager*)(void*)(FUN_140c24ef0()))->FUN_140bc1730();
    }
    reinterpret_cast<Unk_HlAS*>(((MS2Ptr<AScript>*)(&m_30))->operator->())->FUN_140bd2cb0("setMenu", names);
}

// @0x140c231b0
int UIHighlightGameMenu::FUN_140c231b0()
{
    Unk_HlPc* pPc = (Unk_HlPc*)WorldService::GetInstance()->FUN_141bd0cc0();
    if (pPc == 0)
        return false;
    ATL::CAtlArray<MS2Ptr<CItem> > bag;
    g_143ab2a90.FUN_140a60880(0, bag);
    CMsTime limit(GetServerTime());
    AddMinutes(limit, 0xfffffff6);
    for (unsigned __int64 i = 0; i < bag.GetCount(); ++i)
    {
        MS2Ptr<CItem> item = bag[i];
        if (item->GetCreationTime() < limit.Get())
            continue;
        if (g_143ab2a90.FUN_140a65770(item.get()) != 0)
            continue;
        MS2Ptr<CItemData> rec((CItemData*)item->FUN_140527840());
        if (!rec)
            continue;
        if (rec->limit.IsJobRecommended(((PC*)pPc)->FUN_141654700()) == 0)
            continue;
        MS2Ptr<CItem> worn = ((MyPC*)pPc)->FUN_14152e2f0(item);
        if (!worn)
            return true;
        if (item->FUN_140529070() > worn->FUN_140529070())
            return true;
    }
    return false;
}

// @0x140c234d0
int UIHighlightGameMenu::FUN_140c234d0()
{
    Unk_HlPc* pPc = (Unk_HlPc*)WorldService::GetInstance()->FUN_141bd0cc0();
    if (pPc == 0)
        return false;
    int nMax = TSingleton<JobTable>::GetInstance()->GetJobRank(((PC*)pPc)->FUN_141654730());
    for (int i = 1; i <= nMax; i++)
    {
        if ((unsigned)((MyPC*)pPc)->FUN_14152e970(i) <= 0)
            continue;
        if (i == 1)
        {
            unsigned nNeed = ((CLua*)FUN_1401c0db0())->CalcAvailableSkillPoint(pPc->vfunc_78());
            unsigned nUsed = ((JobSystem*)((PC*)pPc)->FUN_1416546d0())->GetUsedPoint(i);
            if (nUsed >= nNeed)
                continue;
        }
        return true;
    }
    return false;
}

// @0x140c235d0
int UIHighlightGameMenu::FUN_140c235d0()
{
    if ((unsigned)g_143ab2ee0.FUN_1408e3520() > 0)
        return true;
    if (g_143ab2ee0.FUN_1408e48b0() != 0)
    {
        CUserMail::MailArray* pArr = &g_143ab2ee0.FUN_1408e3700();
        for (unsigned __int64 i = 0; i < pArr->GetCount(); ++i)
        {
            CUserMail::MailPtr kEntry(*(CUserMail::MailPtr*)FUN_140c24ea0((__int64*)pArr, i));
            if (kEntry.operator->()->FUN_140690370() >= 100 && kEntry.operator->()->FUN_140690370() < 0x71
                && kEntry.operator->()->FUN_140691130() == 0)
                return true;
        }
    }
    return false;
}

// @0x140c236f0
int UIHighlightGameMenu::FUN_140c236f0()
{
    Unk_HlPc* pPc = (Unk_HlPc*)WorldService::GetInstance()->FUN_141bd0cc0();
    if (pPc == 0)
        return false;
    bool bPoint = (unsigned)pPc->FUN_140c25130()->GetRemaining() > 0;
    if (bPoint)
        return true;
    return false;
}

// @0x140c237a0
int UIHighlightGameMenu::FUN_140c237a0()
{
    Unk_HlPc* pPc = (Unk_HlPc*)WorldService::GetInstance()->FUN_141bd0cc0();
    if (pPc == 0)
        return false;
    m_nScrollItem = 0;
    m_nTargetItem = 0;
    ATL::CAtlArray<unsigned int> ids;
    ids.Add(0x1d90b9a);
    ids.Add(0x1d90b9b);
    ids.Add(0x1d90b9c);
    MS2Ptr<CItem> scroll(0);
    for (unsigned __int64 i = 0; i < ids.GetCount(); ++i)
    {
        MS2Ptr<CItem> found = g_143ab2a90.FUN_140a5e2e0(ids[i]);
        if (found.get() != 0)
        {
            scroll = found;
            break;
        }
    }
    if (scroll == 0)
        return false;
    MS2Ptr<CItemData> rec((CItemData*)scroll->FUN_140527840());
    if (!rec)
        return false;
    if (rec->function.name != L"EnchantScroll")
        return false;
    int nKind = reinterpret_cast<Unk_CommandArgs&>(rec->function.parameter).FUN_1408d1f60(0, 0);
    MS2Ptr<CEnchantScrollData> ench = TSingleton<CEnchantScrollTable>::GetInstance()->FindScroll(nKind);
    if (ench.IsNull())
        return false;
    ATL::CAtlArray<MS2Ptr<CItem> > items;
    g_143ab2a90.FUN_140a60880(0, items);
    ATL::CAtlList<MS2Ptr<CEquipItem> > list(10);
    ((CEquipment*)((PC*)pPc)->FUN_1416561a0())->CollectShownItemsInLayer(list, 0);
    for (POSITION pos = list.GetHeadPosition(); pos != 0; list.GetNext(pos))
    {
        MS2Ptr<CEquipItem> spEquip = list.GetAt(pos);
        MS2Ptr<CItem> v = spEquip->GetItem();
        if (!v)
            continue;
        items.Add(v);
    }
    for (unsigned __int64 j = 0; j < items.GetCount(); ++j)
    {
        MS2Ptr<CItem> it = items[j];
        MS2Ptr<CItemData> data((CItemData*)it->FUN_140527840());
        if (!data)
            continue;
        if (it->GetRequiredLevel() < 0x32)
            continue;
        if (it->GetRarity() != 3)
            continue;
        int nId = data->GetEquipSubtype();
        if (Unk_ArrayFind<int>(reinterpret_cast<const ATL::CAtlArray<int>&>(ench->m_slots), nId) == -1)
            continue;
        if (TSingleton<CItemEnchantLimitTable>::GetInstance()->FUN_14058df90(it.get()) == 0)
            continue;
        int nGrade = it->FUN_140526fc0();
        if (nGrade >= ench->m_nGrade)
            continue;
        if (it->FUN_140527030() != 0)
            continue;
        m_nScrollItem = scroll->GetItemUid();
        m_nTargetItem = it->GetItemUid();
        return true;
    }
    return false;
}

// @0x140c23f10
int UIHighlightGameMenu::FUN_140c23f10()
{
    if (!m_bitsGem.FUN_140c25f10(0).FUN_140c24ac0())
    {
        bool bSocket = m_bitsSocket.FUN_140c25f10(0).FUN_140c24ac0();
        if (!bSocket)
            return false;
    }
    Unk_HlPc* pPc = (Unk_HlPc*)WorldService::GetInstance()->FUN_141bd0cc0();
    if (pPc == 0)
        return false;
    m_bitsGem.FUN_140c260a0(0, false);
    ATL::CAtlList<MS2Ptr<CEquipItem> > list(10);
    ((CEquipment*)((PC*)pPc)->FUN_1416561a0())->CollectShownItemsInLayer(list, 0);
    ((CEquipment*)((PC*)pPc)->FUN_1416561a0())->CollectShownItemsInLayer(list, 1);
    if (FUN_140c25330(&list) == 0)
    {
        unsigned nMask = 0;
        for (POSITION pos = list.GetHeadPosition(); pos != 0; list.GetNext(pos))
        {
            MS2Ptr<CEquipItem> h = list.GetAt(pos);
            if (h == 0 || h->GetItem() == 0)
                continue;
            MS2Ptr<CItem> it = h->GetItem();
            if (it->GetSocket() == 0 || it->GetSocket()->HasEmptyOpenSlot() == 0)
                continue;
            unsigned nBit = it->HasSkin() != 0 ? 8 : 7;
            nMask |= nBit;
            if (nMask >= 0xf)
                break;
        }
        if (nMask != 0)
        {
            ATL::CAtlArray<MS2Ptr<CItem> > gems;
            g_143ab2a90.FUN_140a60880(6, gems);
            for (unsigned __int64 k = 0; k < gems.GetCount(); ++k)
            {
                MS2Ptr<CItem> g = gems[k];
                if (g == 0 || g->FUN_140527840() == 0 || ((CItemData*)g->FUN_140527840())->FUN_14053d840() == 0)
                    continue;
                MS2Ptr<CItemGemStoneData> rec = TSingleton<CItemGemStoneUpgradeTable>::GetInstance()->FindData(g->FUN_1405276c0());
                if (rec == 0)
                    continue;
                if ((rec->m_nMask & nMask) > 0u)
                {
                    m_bitsSocket.FUN_140c260a0(0, true);
                    return true;
                }
            }
        }
    }
    m_bitsSocket.FUN_140c260a0(0, false);
    return false;
}

// @0x140c22ce0
bool UIHighlightGameMenu::IsActive()
{
    return m_bActive;
}

// @0x140c244b0
void UIHighlightGameMenu::FUN_140c244b0(int* pPos, bool bSet)
{
    if ((*(const MS2Ptr<AScript>*)(&m_30) == 0) != 0) {} else
        m_bitsSocket.FUN_140c260a0(*pPos, bSet);
}

// @0x140c26320
int FUN_140c26320(void* pDst, size_t nDstSize, const void* pSrc, size_t nCount)
{
    if (nCount == 0)
        return 0;
    // the CRT memmove_s validation (_CRT_MEMCPY_S_VALIDATE_RETURN_ERRCODE)
    {
        int _Expr_val = !!(pDst != 0);
        if (!(_Expr_val)) { *_errno() = EINVAL; _invalid_parameter_noinfo(); return EINVAL; }
    }
    {
        int _Expr_val = !!(pSrc != 0);
        if (!(_Expr_val)) { *_errno() = EINVAL; _invalid_parameter_noinfo(); return EINVAL; }
    }
    {
        int _Expr_val = !!(nDstSize >= nCount);
        if (!(_Expr_val)) { *_errno() = ERANGE; _invalid_parameter_noinfo(); return ERANGE; }
    }
    memmove(pDst, pSrc, nCount);
    return 0;
}

// @0x140c24470
void UIHighlightGameMenu::FUN_140c24470(NotifyObject* pObj)
{
    m_bitsGem.FUN_140c261c0();
    m_bitsSocket.FUN_140c26080();
}

// @0x140c24650
P FUN_140c24650()
{
    P pUi = TSingleton<CUIService>::GetInstance();
    if (pUi == 0)
        return 0;
    MS2Ptr<UIObject> spUi = ((CUIService*)pUi)->FindObject((eUIClassID)FUN_140c25190());
    if (spUi.IsNull())
        return 0;
    return dynamic_cast<UIItemSocketSystemDialog*>(spUi.operator->());
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca2700-0x142ca27e0 .text$yd

// hk1 2026-10-20: hooks for the remaining recovered functions (work/hk1/report.md)
MS2_REPLACE(0x140c25190, FUN_140c25190, 6, 0x4D711B71);
MS2_REPLACE_DTOR(0x140c24a50, MS2Ptr<CStatPointManager>, 34, 0x1248047C);
MS2_REPLACE_IMPL(0x140c24920, static_cast<MS2Ptr<CStatPointManager>* (*)(MS2Ptr<CStatPointManager>*, const MS2Ptr<CStatPointManager>&)>([](MS2Ptr<CStatPointManager>* self, const MS2Ptr<CStatPointManager>& o) -> MS2Ptr<CStatPointManager>* { return ::new (static_cast<void*>(self)) MS2Ptr<CStatPointManager>(o); }), "MS2Ptr<CStatPointManager>::MS2Ptr", 52, 0x30756183);
MS2_REPLACE(0x140c25330, FUN_140c25330, 46, 0xDB14FB29);
MS2_REPLACE_IMPL(0x140c249d0, static_cast<Unk_HlBitRef* (*)(Unk_HlBitRef*, Unk_HlBits*, int)>([](Unk_HlBitRef* self, Unk_HlBits* pBits, int nPos) -> Unk_HlBitRef* { return ::new (static_cast<void*>(self)) Unk_HlBitRef(pBits, nPos); }), "Unk_HlBitRef::Unk_HlBitRef", 46, 0xDE5FA628);
MS2_REPLACE_METHOD(0x140c24ac0, Unk_HlBitRef, FUN_140c24ac0, 35, 0x60FDC12E);
MS2_REPLACE_METHOD(0x140c260a0, Unk_HlBits, FUN_140c260a0, 286, 0xA1414E44);
MS2_REPLACE_METHOD(0x140c261e0, Unk_HlBits, FUN_140c261e0, 159, 0x5962585B);
MS2_REPLACE_METHOD(0x140c262e0, Unk_HlBits, FUN_140c262e0, 53, 0xBAEEFFB1);
MS2_REPLACE_METHOD(0x140c26280, Unk_HlBits, FUN_140c26280, 84, 0x35672ED1);
MS2_REPLACE_METHOD(0x140c24770, Unk_HlBits, FUN_140c24770, 31, 0x01E54B59);
MS2_REPLACE_METHOD(0x140c261c0, Unk_HlBits, FUN_140c261c0, 31, 0x1E7F28C1);
MS2_REPLACE_METHOD(0x140c26080, Unk_HlBits, FUN_140c26080, 31, 0x54C06974);
MS2_REPLACE_METHOD(0x140c226e0, UIHighlightGameMenu, vfunc_67, 24, 0x0801D545);
MS2_REPLACE_METHOD(0x140c22700, UIHighlightGameMenu, OnLoadComplete, 87, 0xA3E8D7FA);
MS2_REPLACE_METHOD(0x140c22760, UIHighlightGameMenu, vfunc_43, 144, 0xDB0C7874);
MS2_REPLACE_METHOD(0x140c22800, UIHighlightGameMenu, vfunc_28, 706, 0x9AFEF6DC);
MS2_REPLACE_METHOD(0x140c22ae0, UIHighlightGameMenu, vfunc_72, 62, 0x2D4F1BD9);
MS2_REPLACE_METHOD(0x140c22b30, UIHighlightGameMenu, vfunc_49, 283, 0x551FB317);
MS2_REPLACE_METHOD(0x140c22c60, UIHighlightGameMenu, vfunc_26, 77, 0x6346B9B7);
MS2_REPLACE_METHOD_VIA(0x140c22d00, UIHighlightGameMenu, UIItemEventListener, vfunc_5, 118, 0x465C7266);
MS2_REPLACE_METHOD_VIA(0x140c22d80, UIHighlightGameMenu, UIItemEventListener, vfunc_2, 106, 0xB2FB668A);
MS2_REPLACE_METHOD_VIA(0x140c22df0, UIHighlightGameMenu, UIItemEventListener, vfunc_21, 166, 0xE9BAE25E);
MS2_REPLACE_METHOD_VIA(0x140c22ea0, UIHighlightGameMenu, UIItemEventListener, vfunc_22, 165, 0x2E310326);
MS2_REPLACE_METHOD(0x140c22f50, UIHighlightGameMenu, FUN_140c22f50, 593, 0x120A94CB);
MS2_REPLACE_METHOD(0x140c231b0, UIHighlightGameMenu, FUN_140c231b0, 790, 0xABA47B23);
MS2_REPLACE_METHOD(0x140c234d0, UIHighlightGameMenu, FUN_140c234d0, 244, 0x8051E676);
MS2_REPLACE_METHOD(0x140c235d0, UIHighlightGameMenu, FUN_140c235d0, 269, 0x2FC46449);
MS2_REPLACE_METHOD(0x140c236f0, UIHighlightGameMenu, FUN_140c236f0, 160, 0x1F3D47B4);
MS2_REPLACE_METHOD(0x140c237a0, UIHighlightGameMenu, FUN_140c237a0, 1887, 0xF7712921);
MS2_REPLACE_METHOD(0x140c23f10, UIHighlightGameMenu, FUN_140c23f10, 1367, 0x34257BD0);
MS2_REPLACE_METHOD(0x140c22ce0, UIHighlightGameMenu, IsActive, 18, 0xCD131F6C);
MS2_REPLACE_METHOD(0x140c244b0, UIHighlightGameMenu, FUN_140c244b0, 84, 0xB08B121C);
MS2_REPLACE(0x140c26320, FUN_140c26320, 271, 0x90034658);
MS2_REPLACE_METHOD(0x140c24470, UIHighlightGameMenu, FUN_140c24470, 57, 0xFC5E6E7C);

