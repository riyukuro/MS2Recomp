// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIUnlimitedEnchantDialog (class name "UnlimitedEnchantDialog",
// UI type 0x4f97, 0x1d8 bytes): see uiunlimitedenchantdialog.h. The swf calls "OnSelect" / "OnRetry" (ask the server for a
// preview of the item, packet 0xbc sub 0) and "OnEnchant" (packet 0xbc sub 1); the answers arrive through the
// FUN_140fb6310 (preview) and FUN_140fb6b00 (result) members.
// MS2-UNIT: ?\uiunlimitedenchantdialog.cpp
// MS2-RANGE: 0x1400e2230-0x1400e2540 .text$di
// MS2-RANGE: 0x140fb5ca0-0x140fb7dc0 .text$mn
// MS2-RANGE: 0x142caa8a0-0x142caa9e0 .text$yd
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??__Es_unk1402a9d70@@YAXXZ 0x1400e2350 ; prop
// MS2-PIN: ??__Es_unk1402a9d70_2@@YAXXZ 0x1400e24f0 ; prop
// MS2-PINS-END tplpin
// MS2-PIN: ??_GUIUnlimitedEnchantDialog@@UEAAPEAXI@Z 0x140fb7c50
// MS2-PIN: ??$FUN_14028dfa0@W4Unk_UnlimitedEnchantError@@@@YA?AV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V01@AEBW4Unk_UnlimitedEnchantError@@@Z 0x140fb7a20
// MS2-PIN: ??$format_arg@_WW4Unk_UnlimitedEnchantError@@@fmt@@YAXAEAV?$BasicFormatter@_W@0@AEAPEB_WAEBW4Unk_UnlimitedEnchantError@@@Z 0x140fb7ad0
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiunlimitedenchantdialog.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"

#include "uiunlimitedenchantdialog.h"

#include "ms2/placeholder/header_statics_a.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/placeholder/mypc.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/commonfiles/commonstruct_wa.h"
#include "ms2/client/ms2/inventory.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- the unit's header statics: header_statics_a.h above, a key controller, then a second copy of the four ---------------
static UICommon::CMyPCKeyInputController s_keyInput;
static CString s_strSortTypeNames2[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill2 = "skill";
static CString s_strStun2 = "stun";
static Unk_1402a9d70 s_unk1402a9d70_2(17, 0.75f, 0.25f, 2.25f, 10);

// ---- unit-local views of unrecovered callees ------------------------------------------------------------------------

class ASDialog : public ASDisplayObject {};

// The item list control of the movie.
class Unk_UeBag : public AScript
{
public:
    virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
    virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11();
    virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15();
    virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19();
    virtual void vfunc_20(); virtual void vfunc_21(); virtual void vfunc_22(); virtual void vfunc_23();
    virtual void vfunc_24(bool bRefresh);
    void FUN_1407cba60(const char* szName, CString str);             // set a string member
    void FUN_1422dcca0(int nIndex);                                  // select an entry (-1: none)
    void FUN_1422dd1d0();                                            // clear
};

// A dialog's position record (the maid dialog's, UI type 0x4e40).
class Unk_UeRefPos { public: int FUN_141b1d3d0(); int FUN_141b1d460(); };
Unk_UeRefPos* FUN_140a7b2b0(int nId);

class Unk_BackUpItem : public CPtred { public: MS2Ptr<CItem> FUN_1411dc7a0(); };
class Unk_PCItems { public: };
Unk_PCItems* FUN_1416561a0(MyPC* pc);
void FUN_1411e1ce0(Unk_PCItems* items, ATL::CAtlList<MS2Ptr<Unk_BackUpItem> >* out, int a);

class Unk_UeWorld { public: MyPC* FUN_141bd0cc0(); };
Unk_UeWorld* FUN_1403ed2d0();

// The enchant limit table (one of the CItem checks of the itemenchantlimittable unit).
class Unk_UeLimitTable { public: int FUN_14058e3a0(CItem* pItem); };
Unk_UeLimitTable* FUN_1409eece0();

class UIInventoryDialog;
UIInventoryDialog* FUN_1405344f0(int nId);
void FUN_140c3fe30(UIInventoryDialog* pDialog, int n);

MS2Ptr<CItem> FUN_1419be700(unsigned __int64 nUid);              // the inventory item with this uid
int FUN_140a5f780_1(Unk_Inventory* pInv, int nTag, int nRarity); // how many of the ingredient the player has
int FUN_14053feb0(unsigned nItemId);                             // default rank of an item
MS2Ptr<CItem> FUN_141420330(const ATL::CAtlArray<MS2Ptr<CItem> >& items, int nIndex);
void FUN_14141f970(const CString& strBag);                       // drop an item bag
void FUN_14141f770(const CString& strBag, unsigned int nCount, const ATL::CAtlArray<MS2Ptr<CItem> >& items,
                   MS2Ptr<CItem>(*pfnGetItem)(const ATL::CAtlArray<MS2Ptr<CItem> >&, int), int n1, int n2);
void FUN_140710590(COutPacket& packet);                          // send
unsigned __int64 FUN_140718370(const CStringW& str);             // text -> uid
CStringW FUN_14028b8e0(const CStringW& strKey);                  // string table text
CStringW FUN_14028dfa0(CStringW strKey, const fmt::ArgList& args);   // string table text, formatted
FMT_VARIADIC_W(CStringW, FUN_14028dfa0, CStringW)
void FUN_1412751f0(const CStringW& text, int nA, int nB);
CStringW FUN_1419021b0(int nHave, int nNeed);                    // "have/need"
CStringW FUN_1409404f0(__int64 nValue);                          // money text
CStringW FUN_1405c2690(CStringW strKey, const CStringW& strArg);
void* FUN_140967100();
void FUN_141b1feb0(void* pService);

extern Unk_Inventory DAT_143ab2a90;

#include "ms2/placeholder/gfxvalue.h"
extern template class MS2Ptr<CItem>;
extern template class MS2Ptr<CItemData>;
template <> MS2Ptr<Unk_UeBag>::MS2Ptr(int nNull);                    // 0x140acd430
template <> MS2Ptr<Unk_UeBag>::~MS2Ptr();                           // 0x140acd710
template <> Unk_UeBag* MS2Ptr<Unk_UeBag>::get() const;              // 0x140acd9d0
template <> Unk_UeBag* MS2Ptr<Unk_UeBag>::operator->() const;       // 0x140acd9f0

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// @0x140fb5ca0
UIUnlimitedEnchantDialog::UIUnlimitedEnchantDialog()
    : m_binder(vfunc_1())
{
    m_2c = 0x1b;
    FUN_1422dc3b0(1);
    FUN_141924170(1);
}

// @0x140fb5d70
UIUnlimitedEnchantDialog::~UIUnlimitedEnchantDialog()
{
}

// @0x140fb5de0
CString UIUnlimitedEnchantDialog::vfunc_1()
{
    return "UnlimitedEnchantDialog";
}
MS2_REPLACE_METHOD(0x140FB5DE0, UIUnlimitedEnchantDialog, vfunc_1, 61, 0x717F4FF3);

// @0x140fb5e30
int UIUnlimitedEnchantDialog::vfunc_65()
{
    return UIDialog::vfunc_65();
}

// @0x140fb5e50
void UIUnlimitedEnchantDialog::vfunc_67()
{
    FUN_14141f970(vfunc_1());
    UIDialog::vfunc_67();
    FUN_141b1feb0(FUN_140967100());
}

// @0x140fb5ec0
void UIUnlimitedEnchantDialog::vfunc_72()
{
    UIDialog::vfunc_72();
}

// @0x140fb5ee0
void UIUnlimitedEnchantDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    FUN_140fb6ed0();
}

// @0x140fb5f10
int UIUnlimitedEnchantDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (_stricmp(szMethod, "OnEnchant") == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
        {
            unsigned __int64 nUid = FUN_140718370(data.FUN_1422b8f40());
            FUN_140fb7570(nUid);
            return 1;
        }
    }
    else if (_stricmp(szMethod, "OnSelect") == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
        {
            unsigned __int64 nUid = FUN_140718370(data.FUN_1422b8f40());
            FUN_140fb7450(nUid);
            return 1;
        }
    }
    else if (_stricmp(szMethod, "OnRetry") == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
        {
            unsigned __int64 nUid = FUN_140718370(data.FUN_1422b8f40());
            FUN_140fb7450(nUid);
            return 1;
        }
    }
    return 0;
}

// Placed beside the maid dialog's reference point when that is open, else at the origin.
// @0x140fb61e0
// MS2-FUNCTIONAL: temp/frame layout differs from the exe
void UIUnlimitedEnchantDialog::vfunc_43()
{
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    Unk_UeRefPos* pRef;
    if (pDialog != 0 && (pRef = FUN_140a7b2b0(0x4e40)) != 0)
    {
        int nX = pRef->FUN_141b1d3d0();
        int nY = pRef->FUN_141b1d460();
        if (nX != -1 && nY - 0x50 != -1)
        {
            pDialog->vfunc_2(5, nY - 0x50, nX - pDialog->FUN_1422c13b0());
            return;
        }
    }
    pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDialog != 0)
        pDialog->vfunc_2(1, 0, 0);
}

// The server's preview of an enchant: the item as it would be afterwards and the ingredients it costs.
// @0x140fb6310
// MS2-FUNCTIONAL: temp/frame layout differs from the exe
void UIUnlimitedEnchantDialog::FUN_140fb6310(CInPacket* pPacket)
{
    unsigned __int64 nUid = pPacket->vfunc_o8_4();
    CIngredientContainer ingredients;
    ingredients.FUN_14026c0b0(*pPacket);
    MS2Ptr<CItem> spTarget = FUN_1419be700(nUid);
    if (!(spTarget == 0))
    {
        MS2Ptr<CItem> spResult(new CItem());
        int nItemId = spTarget->FUN_140526bd0();
        int nRank = spTarget->FUN_1405276c0();
        if (spResult->FUN_140523c40(nRank, nItemId, 0) != 0)
        {
            spResult->FUN_140524eb0(*pPacket);
            m_binder.FUN_140d43990();
            FUN_140d432d0(&m_binder, 0x525);
            FUN_140d432f0(&m_binder, 8);
            ASObj data(2);
            data.FUN_1407cba60("targetBinding", m_binder.FUN_140d43790(spTarget.get()));
            data.FUN_1407cba60("resultBinding", m_binder.FUN_140d43790(spResult.get()));
            data.FUN_1407cbb20("targetItemName", spTarget->FUN_140527b10());
            data.FUN_1407cbb20("resultItemName", spResult->FUN_140527b10());
            __int64 nFee = 0;
            ASArray list(2);
            for (size_t i = 0; i < ingredients.FUN_14026bee0(); ++i)
            {
                Unk_IngRef ref = ingredients.FUN_14026bdc0(i);
                unsigned nIngredientId = ref->FUN_14026b500();
                int nCount = ref->m_c;
                int nHave = FUN_140a5f780_1(&DAT_143ab2a90, ref->m_b, 0);
                int nIngredientRank = FUN_14053feb0(nIngredientId);
                MS2Ptr<CItem> spIngredient(new CItem());
                if (spIngredient->FUN_14052b2e0(nIngredientId, nIngredientRank, 0, nCount) != 0)
                {
                    ASObj entry(2);
                    entry.FUN_1407cba60("binding", m_binder.FUN_140d43790(spIngredient.get()));
                    entry.FUN_1407cbb20("countText", FUN_1419021b0(nHave, nCount));
                    list.FUN_1422bbf00(entry);
                }
                if (ref->m_b == 0x60 && nHave < nCount)
                    nFee = (__int64)((nCount - nHave) * 1000);
            }
            data.FUN_1409eb1d0("ingredient", list);
            data.FUN_1407cbb20("fee", FUN_1405c2690(CStringW(L"s_itemenchant_fee"), FUN_1409404f0(nFee)));
            m_30->FUN_140acd1f0("setData", data);
        }
    }
}

// The server's answer to the enchant: read the new item, refresh the bag.
// @0x140fb6b00
void UIUnlimitedEnchantDialog::FUN_140fb6b00(CInPacket* pPacket)
{
    unsigned __int64 nUid = pPacket->vfunc_o8_4();
    MS2Ptr<CItem> spItem = FUN_1419be700(nUid);
    if (spItem == 0)
        return;
    spItem->FUN_140524eb0(*pPacket);
    m_30->Invoke("onEnchant");
    UIInventoryDialog* pInventory = FUN_1405344f0(0x4e2d);
    if (pInventory != 0)
        FUN_140c3fe30(pInventory, 7);
    FUN_140fb7690(nUid);
}
MS2_REPLACE_METHOD(0x140FB6B00, UIUnlimitedEnchantDialog, FUN_140fb6b00, 289, 0xA0816445);

// @0x140fb6c30
// MS2-FUNCTIONAL: fmt enum argument glue (format_arg / FUN_14028dfa0 instances) differs from the exe's
void UIUnlimitedEnchantDialog::FUN_140fb6c30(Unk_UnlimitedEnchantError nError)
{
    if (nError == 1)
        FUN_1412751f0(FUN_14028b8e0(CStringW(L"s_unlimited_enchant_err_invalid_item")), 1, 1);
    else if (nError == 2)
        FUN_1412751f0(FUN_14028b8e0(CStringW(L"s_unlimited_enchant_err_lack_ingredient")), 1, 1);
    else if (nError == 3)
        FUN_1412751f0(FUN_14028b8e0(CStringW(L"s_unlimited_enchant_err_lack_meso")), 1, 1);
    else if (nError == 4)
        FUN_1412751f0(FUN_14028dfa0(CStringW(L"s_unlimited_enchant_err_system"), nError), 1, 1);
    else if (nError == 5)
        FUN_1412751f0(FUN_14028b8e0(CStringW(L"s_unlimited_enchant_err_max_unlimited_grade")), 1, 1);
}

// Collects the enchantable items of the inventory and the equipment and hands them to the item bag.
// @0x140fb6ed0
// MS2-FUNCTIONAL: temp/frame layout differs from the exe
void UIUnlimitedEnchantDialog::FUN_140fb6ed0()
{
    MyPC* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPC != 0)
    {
        m_items.RemoveAll();
        ATL::CAtlArray<unsigned __int64> uids;
        DAT_143ab2a90.FUN_140a609a0(0, uids);
        for (unsigned i = 0; i < uids.GetCount(); i++)
        {
            MS2Ptr<CItem> spItem = FUN_1419be700(uids[i]);
            if (!(spItem == 0))
            {
                if (FUN_140fb7870(MS2Ptr<CItem>(spItem)) == 0)
                    m_items.Add(spItem);
            }
        }
        ATL::CAtlList<MS2Ptr<Unk_BackUpItem> > equips(10);
        FUN_1411e1ce0(FUN_1416561a0(pPC), &equips, 0);
        POSITION pos = equips.GetHeadPosition();
        while (pos != 0)
        {
            MS2Ptr<Unk_BackUpItem> spEquip = equips.GetAt(pos);
            if (!(spEquip == 0))
            {
                MS2Ptr<CItem> spItem = spEquip->FUN_1411dc7a0();
                if (!(spItem == 0))
                {
                    if (FUN_140fb7870(MS2Ptr<CItem>(spItem)) == 0)
                        m_items.Add(spItem);
                }
            }
            equips.GetNext(pos);
        }
        FUN_14141f970(vfunc_1());
        MS2Ptr<CItem> (*pfnGetItem)(const ATL::CAtlArray<MS2Ptr<CItem> >&, int) = FUN_141420330;
        FUN_14141f770(vfunc_1(), (unsigned)m_items.GetCount(), m_items, pfnGetItem, 0x535, 8);
        MS2Ptr<Unk_UeBag> spBag = FUN_140ba4b70("m_itemBag");
        if (spBag.get() != 0)
        {
            spBag->FUN_1422dcca0(-1);
            spBag->FUN_1422dd1d0();
            spBag->FUN_1407cba60("bagId", vfunc_1());
            spBag->vfunc_24(true);
        }
    }
}

// "OnSelect" / "OnRetry": check the item, ask the server for the preview.
// @0x140fb7450
void UIUnlimitedEnchantDialog::FUN_140fb7450(unsigned __int64 nUid)
{
    MS2Ptr<CItem> spItem = FUN_1419be700(nUid);
    if (spItem == 0)
        return;
    Unk_UnlimitedEnchantError nError = FUN_140fb7870(MS2Ptr<CItem>(spItem));
    if (nError != 0)
    {
        FUN_140fb6c30(nError);
        return;
    }
    COutPacket packet(0xbc, 0);
    packet.vfunc_o10_1(0);
    packet.vfunc_o10_4(spItem->FUN_140526a50());
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x140FB7450, UIUnlimitedEnchantDialog, FUN_140fb7450, 273, 0x50680FB4);

// "OnEnchant": check the item, send the enchant.
// @0x140fb7570
void UIUnlimitedEnchantDialog::FUN_140fb7570(unsigned __int64 nUid)
{
    MS2Ptr<CItem> spItem = FUN_1419be700(nUid);
    if (spItem == 0)
        return;
    Unk_UnlimitedEnchantError nError = FUN_140fb7870(MS2Ptr<CItem>(spItem));
    if (nError != 0)
    {
        FUN_140fb6c30(nError);
        return;
    }
    COutPacket packet(0xbc, 0);
    packet.vfunc_o10_1(1);
    packet.vfunc_o10_4(spItem->FUN_140526a50());
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x140FB7570, UIUnlimitedEnchantDialog, FUN_140fb7570, 273, 0x50C15093);

// @0x140fb7690
// MS2-FUNCTIONAL: frame is 0x20 larger than the exe's (bool temp of the pointer test)
void UIUnlimitedEnchantDialog::FUN_140fb7690(__int64 nUid)
{
    unsigned nSelected = 0xffffffff;
    for (unsigned i = 0; i < m_items.GetCount(); i++)
    {
        MS2Ptr<CItem> spItem = m_items.GetAt(i);
        if (spItem.get() != 0)
        {
            if (spItem->FUN_140526a50() == nUid)
                nSelected = i;
        }
    }
    MS2Ptr<Unk_UeBag> spBag = FUN_140ba4b70("m_itemBag");
    if (spBag.get() != 0)
    {
        spBag->Invoke("update");
        spBag->FUN_1422dcca0(-1);
        spBag->vfunc_24(true);
        if (nSelected != 0xffffffff)
            spBag->FUN_1422dcca0(nSelected);
    }
}

// Why the item cannot be enchanted: 1 not an enchantable item, 5 already at the unlimited grade, 0 fine.
// @0x140fb7870
Unk_UnlimitedEnchantError UIUnlimitedEnchantDialog::FUN_140fb7870(MS2Ptr<CItem> spItem)
{
    MS2Ptr<CItemData> spData(reinterpret_cast<CItemData*>(spItem->FUN_140527840()));
    if (spData == 0)
        return UNLIMITED_ENCHANT_INVALID_ITEM;
    if (spData->FUN_14053e9e0() == 0)
        return UNLIMITED_ENCHANT_INVALID_ITEM;
    int nLevel = spItem->FUN_140527270();
    if (nLevel == 0)
    {
        if (FUN_1409eece0()->FUN_14058e3a0(spItem.get()) == 0)
            return UNLIMITED_ENCHANT_INVALID_ITEM;
    }
    if (nLevel == spData->FUN_14053e9e0())
        return UNLIMITED_ENCHANT_MAX_GRADE;
    return UNLIMITED_ENCHANT_OK;
}


MS2_EMIT_CRT_MEMMOVE_S();
