// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The item option remake window ("ItemRemakeOptionDialog", packet 0x75)
// and the UIItemModifyDialogBase destructor / vfunc_86 (the base class is declared in uiitemenchantdialog.h).
// MS2-UNIT: unit_14129cfa0
// MS2-RANGE: 0x1400ece40-0x1400ed130 .text$di
// MS2-RANGE: 0x14129cfa0-0x1412a4590 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??__Es_strSortTypeNames2@@YAXXZ 0x1400ece40 ; probe
// MS2-PIN: ??__Es_itemChoice@@YAXXZ 0x1400ecf00 ; probe
// MS2-PIN: ??__Es_progress@@YAXXZ 0x1400ecf30 ; probe
// MS2-PIN: ??__Es_strSkill@@YAXXZ 0x1400ecfe0 ; probe
// MS2-PIN: ??__Es_strStun@@YAXXZ 0x1400ed010 ; probe
// MS2-PIN: ??__Es_successEffect@@YAXXZ 0x1400ed040 ; probe
// MS2-PIN: ??__Es_strSortTypeNames@@YAXXZ 0x1400ed070 ; probe
// MS2-PIN: ??$?0VUIItemRemakeOptionDialog@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@QEAA@AEBQEAVUIItemRemakeOptionDialog@@AEBQ81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@Z 0x1412a37e0 ; unique
// MS2-PIN: ??$?8PEAVUIItemRemakeOptionDialog@@P80@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@YA_NAEBU?$pair@PEAVUIItemRemakeOptionDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@0@0@Z 0x1412a3a10 ; prop
// MS2-PIN: ??$?8PEAVUIItemRemakeOptionDialog@@P80@EAAXPEAVNotifyObject@@@Z@std@@YA_NAEBU?$pair@PEAVUIItemRemakeOptionDialog@@P81@EAAXPEAVNotifyObject@@@Z@0@0@Z 0x1412a3a80 ; prop
// MS2-PIN: ??$?8PEAVUIItemRemakeOptionDialog@@P80@EAA_NHAEBVCMsgBoxData@@@Z@std@@YA_NAEBU?$pair@PEAVUIItemRemakeOptionDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@0@0@Z 0x1412a3af0 ; prop
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVUIItemRemakeOptionDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@QEAA@AEBV01@@Z 0x1412a3d30 ; unique
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVUIItemRemakeOptionDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x1412a40d0 ; unique
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVUIItemRemakeOptionDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x1412a4130 ; unique
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVUIItemRemakeOptionDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x1412a4190 ; unique
// MS2-PIN: ?vfunc_2@?$DelegateImpl@U?$pair@PEAVUIItemRemakeOptionDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z 0x1412a41f0 ; unique
// MS2-PIN: ?vfunc_2@?$DelegateImpl@U?$pair@PEAVUIItemRemakeOptionDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEAAXPEAVNotifyObject@@@Z 0x1412a4220 ; unique
// MS2-PIN: ??$Call@VUIItemRemakeOptionDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@?$DelegateImpl@U?$pair@PEAVUIItemRemakeOptionDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@CAXAEAU?$pair@PEAVUIItemRemakeOptionDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@AEBUParams@FunctionHandler@GFx@Scaleform@@@Z 0x1412a4290 ; prop
// MS2-PIN: ??$Call@VUIItemRemakeOptionDialog@@P81@EAAXPEAVNotifyObject@@@Z@?$DelegateImpl@U?$pair@PEAVUIItemRemakeOptionDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@CAXAEAU?$pair@PEAVUIItemRemakeOptionDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@PEAVNotifyObject@@@Z 0x1412a42d0 ; prop
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVUIItemRemakeOptionDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x1412a4350 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVUIItemRemakeOptionDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x1412a43b0 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVUIItemRemakeOptionDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x1412a4410 ; unique
// MS2-PINS-END tplpin
//
// Status: see progress/status.tsv. Callees that are not recovered yet are declared below ("unit-local
// placeholders") or in src/ms2/placeholder/; their names are Ghidra's (FUN_<va>) unless evident.
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"

#include "ms2/client/ms2/uiitemremakeoptiondialog.h"
#include "ms2/placeholder/header_statics_a.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/notifyobject.h"
#include "ms2/placeholder/notifygameeventchanged.h"
#include "ms2/placeholder/mypc.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/placeholder/cinputkeyhandler.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/citemremakeoptionpacket.h"
#include "ms2/commonfiles/commonstruct_wa.h"
#include "ms2/client/ms2/uimessageboxdata.h"

#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- the unit's header statics ----
static UICommon::CMyPCKeyInputController s_keyInput;
static CString s_itemChoice("Enchant_ItemChoice");
static CString s_progress("Enchant_Progress");
static CString s_successEffect("Enchant_SuccessEffect");
static CString s_strSortTypeNames2[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};

// ---- unit-local placeholders (unrecovered singletons / helpers) ----
using ATL::CAtlArray;

// The inventory (global 0x143ab2a90).
class Unk_Inventory
{
public:
    MS2Ptr<CItem> FUN_140a5d680(__int64 uid);
    int FUN_140a5f780(int itemId, int a);
    void FUN_140a5d530(CItem* item);
    int FUN_140a5f7b0(int itemId, unsigned a);
    void FUN_140a60880(int tab, CAtlArray<MS2Ptr<CItem> >& out);
};
extern Unk_Inventory DAT_143ab2a90;
extern int DAT_143ab2914;

// Backup (equipped) item record.
class Unk_BackUpItem : public CPtred
{
public:
    MS2Ptr<CItem> FUN_1411dc7a0();
    void FUN_1411dd6d0(CItem* item);
    void FUN_1411dd280();
};
class Unk_PCItems
{
public:
    MS2Ptr<Unk_BackUpItem> FUN_1411e1580(unsigned __int64 uid);
};
Unk_PCItems* FUN_1416561a0(MyPC* pc);
void FUN_1411e1ce0(Unk_PCItems* items, ATL::CAtlList<MS2Ptr<Unk_BackUpItem> >* out, int a);

class Unk_CinWorld
{
public:
    MyPC* FUN_141bd0cc0();
};
Unk_CinWorld* FUN_1403ed2d0();

// AS script views.
class Unk_EnButton : public ASDisplayObject
{
public:
    void FUN_1422ce240(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)> cb, size_t n);
};
class Unk_EnBag : public ASObj
{
};
class Unk_EnScript : public AScript
{
public:
    void FUN_1422bac00(const char* name, CString& out);
};
class Unk_EnArray : public ASArray
{
public:
    void FUN_1422bbf00(const ASObj& obj);
    void FUN_1422bbfe0(const wchar_t* text);
};
class Unk_EnSlotArgs { public: void* m_0; unsigned char m_8[1]; };
class Unk_EnSlot
{
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4();
    virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9();
    virtual void vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14();
    virtual void vfunc_15(); virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19();
    virtual void vfunc_20(); virtual void vfunc_21(); virtual void vfunc_22(); virtual void vfunc_23(); virtual void vfunc_24();
    virtual MS2Ptr<CItem> vfunc_25();
    void FUN_141416740(int nHave, int nCount);
};
Unk_EnSlot* FUN_140f6e830(const CString& name);
void FUN_141415600(const CString& key);
void FUN_141415450(const CString& key, MS2Ptr<CItem> item, int a, int b, int c);
void FUN_140165270(CAtlArray<CString>& arr, const CString& s);
void FUN_1402c2890(CAtlArray<CString>& arr);
void FUN_141414e50(const CString& name);
void FUN_141414d60(const CString& name, const CAtlArray<unsigned __int64>& uids);

// Strings / messages.
CStringW FUN_14028b8e0(const CStringW& key);
CStringW FUN_140298ea0(CStringW key);
CStringW FUN_14062b4f0(CStringW key, const int* v);
CStringW FUN_1405c2690(CStringW key, const CStringW& arg);
bool FUN_140841300(const CStringW& s, const char* c);
unsigned __int64 FUN_140718350(const CString& s);
void FUN_1412751f0(const CStringW& text, int a, int b);
void FUN_141276180(const CString& a, const CString& b);
void FUN_14151f460(int v);
class Unk_DTNotices { public: void FUN_140da4e40(CStringW name, Delegate<void(NotifyObject*)> cb); void FUN_140da4eb0(CStringW name, Delegate<void(NotifyObject*)> cb); };
Unk_DTNotices* FUN_140939a10();
Delegate<bool(int, const CMsgBoxData&)> FUN_140b240b0();
MS2Ptr<CMsgBoxData> FUN_140d74390(CStringW text, int nType, Delegate<bool(int, const CMsgBoxData&)> cb);
MS2Ptr<CMsgBoxData> FUN_140d74230(Delegate<bool(int, const CMsgBoxData&)> cb, CStringW text);
void FUN_1412761e0(MS2Ptr<AScript> pScript, int bShow);
class Unk_PetDialog : public UIDialog { public: };
Unk_PetDialog* FUN_140b99ba0(int nId);
CInputKeyHandler* FUN_14025e7c0();

// The item event hub as the game's FUN_140a6a840 singleton accessor sees it (the same object as UIItemEventDispatcher).
class Unk_ItemEventSystem
{
public:
    void FUN_1419cae20(UIItemEventListener* listener);      // register (once)
    void FUN_1419caeb0(UIItemEventListener* listener);      // unregister
    void* m_vfptr;
    ATL::CAtlArray<UIItemEventListener*> m_listeners;       // +0x08
};
Unk_ItemEventSystem* FUN_140a6a840();

// The remake stat of an item (the 0x20 byte record the stat text is built from).
class Unk_RemakeStat
{
public:
    Unk_RemakeStat(unsigned mode, MS2Ptr<CItem> item, bool bFinal);   // 0x140617de0
    ~Unk_RemakeStat();                                                // 0x14061ac50
    bool FUN_140619290(int index, Unk_LockOpt& opt, int& value);
    unsigned m_mode;
    int m_pad4;
    MS2Ptr<CItem> m_item;
    char m_pad18[8];
};
MS2_CHECK_SIZE(Unk_RemakeStat, 0x20);
int FUN_140616dd0(MS2Ptr<CItem> item);
unsigned FUN_140616f10(MS2Ptr<CItem> item);
CStringW FUN_140619760(int a, unsigned b);
CStringW FUN_140617e50(const CStringW& key, Unk_RemakeStat& stat, unsigned* pCount);
bool FUN_140616fd0(MS2Ptr<CItem> item);
int FUN_140616b60(MS2Ptr<CItemData> data, unsigned* pDiscount, unsigned rate);
int FUN_140616d40(int a, unsigned b);
CString FUN_140719530(unsigned __int64 uid);
void FUN_1409e4950(MS2Ptr<CItem> item, CStringW& out, char* pFlag);
void FUN_140f73320(CMsgBoxData* box, bool b);
void FUN_1411e7660(Unk_PCItems* items);
class Unk_ItemStr { public: CStringW FUN_141811980(int a, int b); };
Unk_ItemStr* FUN_1401a9d70();
void FUN_1412752d0(const CStringW& key, int a);
void FUN_1412751b0(const CStringW& text, int a);
void FUN_140d73aa0(CStringW text, int a, void* b, CStringW c);
CStringW FUN_140b99120(CStringW key, const unsigned& a, const int& b);
CStringW FUN_14042cb90(CStringW key, const float& v);
CStringW FUN_1419021b0(int a, int b);
CStringW FUN_1409404f0(__int64 v);
int FUN_14053feb0(unsigned itemId);
float FUN_1411e1110(Unk_PCItems* items, int a);   // returns in xmm0
extern __int64 DAT_143ab2898;
MS2Ptr<CItem> FUN_1419be700(unsigned __int64 uid);
MS2Ptr<CMsgBoxData> FUN_140d73d20(int type, CStringW text, int a, CStringW b);
void FUN_140d73c60(MS2Ptr<CMsgBoxData> box);
#define NOTICE(expr) do { CStringW noticeText_ = (expr); MS2Ptr<CMsgBoxData> noticeBox_ = FUN_140d74390(CStringW(noticeText_), 0, FUN_140b240b0()); } while (0)

// CItem members the header declares with another signature.
int FUN_140526470(CItem* item, unsigned mode);

#include "ms2/placeholder/gfxvalue.h"
extern template class MS2Ptr<CItem>;
extern template class MS2Ptr<CItemData>;
extern template class MS2Ptr<CMsgBoxData>;
extern template class MS2Ptr<ASMovieClip>;
extern template class MS2Ptr<Unk_BackUpItem>;

// @0x14129cfa0
UIItemRemakeOptionDialog::UIItemRemakeOptionDialog()
    : m_cur(0), m_new(0), m_state(0), m_remakeMode(2), m_optionCount(0)
{
    m_7c = 1;
    m_80 = 1;
    m_164 = 1;
    m_mode = 2;
}

// @0x14129d100
UIItemRemakeOptionDialog::~UIItemRemakeOptionDialog()
{
    m_enchantAni = 0;
    FUN_1412a2ac0();
    FUN_1412a0800();
}

// @0x14129d220
CString UIItemRemakeOptionDialog::vfunc_1()
{
    return CString("ItemRemakeOptionDialog");
}

// @0x14129d270
CString UIItemRemakeOptionDialog::vfunc_7()
{
    return CString("ItemEnchantDialog");
}

// @0x14129d2c0
void UIItemRemakeOptionDialog::OnLoadComplete()
{
    UIItemModifyDialogBase::OnLoadComplete();
    FUN_1412a1c40(0);
    FUN_14129dd50();
    FUN_140a6a840()->FUN_1419cae20(static_cast<UIItemEventListener*>(this));
    FUN_140939a10()->FUN_140da4e40(CStringW(L"NotifyGameEventChanged"),
        Delegate<void(NotifyObject*)>(this, &UIItemRemakeOptionDialog::FUN_14129dc60));
    Unk_PetDialog* pane = FUN_140b99ba0(0x4f38);
    if (pane != 0) {
        if (pane->FUN_141924630() != 0)
            pane->vfunc_67();
    }
    FUN_1412761e0(MS2Ptr<AScript>(m_30), 0);
    COutPacket pkt(0x75, 0);
    pkt.vfunc_o10_1(6);
    pkt.vfunc_o10_1(1);
    FUN_140710590(pkt);
}

// @0x14129d4d0
int UIItemRemakeOptionDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIItemModifyDialogBase::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (_stricmp(szMethod, "onSelectItem") == 0) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0) {
            unsigned __int64 uid = FUN_140718350(data.FUN_1422b8d30());
            unsigned int bSelected = data.FUN_1422b8a90();
            SendChangeAttributesMode4(uid);
        }
        return 1;
    }
    if (_stricmp("onClickRemake", szMethod) == 0) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
            FUN_14129e950(&data);
        return 1;
    }
    if (_stricmp("onEndRemakeAni", szMethod) == 0) {
        OnEndRemakeAni();
        return 1;
    }
    if (_stricmp("onClickApply", szMethod) == 0) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
            FUN_14129ed90(&data);
        return 1;
    }
    if (_stricmp("onClickForceRemake", szMethod) == 0) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
            FUN_14129e190(&data);
    } else if (_stricmp("onClickCompareEnchant", szMethod) == 0) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
            FUN_14129e530(&data);
    } else if (_stricmp("GetEnableLockOption", szMethod) == 0) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
            FUN_14129f360(&data);
    }
    return 0;
}

// @0x14129d870
void UIItemRemakeOptionDialog::vfunc_67()
{
    UIItemModifyDialogBase::vfunc_67();
    FUN_14151f460(1);
    FUN_141414e50(vfunc_1());
    FUN_1412a0800();
    m_remakeMode = 2;
    m_enchantAni = 0;
    FUN_1412a1c40(0);
    m_debugBtnFillIngredient = 0;
    m_debugBtnFillIngredientUnit = 0;
    m_optionCount = 0;
    m_cur = 0;
    m_new = 0;
    FUN_140a6a840()->FUN_1419caeb0(static_cast<UIItemEventListener*>(this));
    FUN_140939a10()->FUN_140da4eb0(CStringW(L"NotifyGameEventChanged"),
        Delegate<void(NotifyObject*)>(this, &UIItemRemakeOptionDialog::FUN_14129dc60));
}

// @0x14129daa0
void UIItemRemakeOptionDialog::vfunc_79(void* pPacket)
{
    if (static_cast<CInPacket*>(pPacket)->FUN_14070fe80() != 200)
        return;
    if (m_enchantAni == 0)
        return;
    FUN_1412761e0(MS2Ptr<AScript>(m_30), 1);
    int kind = static_cast<CInPacket*>(pPacket)->vfunc_o8_1();
    if (kind == 6)
        FUN_1412a2c50(static_cast<CInPacket*>(pPacket));
    else if (kind == 4)
        FUN_14129f940(static_cast<CInPacket*>(pPacket));
    else if (kind == 1)
        FUN_1412a30f0(static_cast<CInPacket*>(pPacket));
    else if (kind == 2)
        FUN_1412a3330(static_cast<CInPacket*>(pPacket));
    else if (kind == 8)
        FUN_1412a3460(static_cast<CInPacket*>(pPacket));
    else if (kind == 5)
        FUN_1412a34f0(static_cast<CInPacket*>(pPacket));
}

// @0x14129dbe0
int UIItemRemakeOptionDialog::vfunc_13()
{
    if (m_enchantAni == 0)
        return 0;
    if ((FUN_14025e7c0()->FUN_14116dd30(0x493e2, 0, 0) || FUN_14025e7c0()->FUN_14116d840()) && FUN_1412a1c60() == 3)
        return 1;
    return 0;
}

// @0x14129dc60
void UIItemRemakeOptionDialog::FUN_14129dc60(NotifyObject* pNotify)
{
    if (m_enchantAni == 0)
        return;
    if (FUN_1412a1c60() != 2 || m_cur == 0)
        return;
    NotifyGameEventChanged* changed = dynamic_cast<NotifyGameEventChanged*>(pNotify);
    if (changed != 0 && FUN_140841300(changed->m_eventName, "SaleRemake"))
        FUN_1412a1600(MS2Ptr<CItem>(m_cur));
}

// @0x14129dd50
void UIItemRemakeOptionDialog::FUN_14129dd50()
{
    if (!(m_enchantAni == 0)) {
        CAtlArray<unsigned __int64> uids;
        CAtlArray<MS2Ptr<CItem> > items;
        DAT_143ab2a90.FUN_140a60880(0, items);
        for (size_t i = 0; i < items.GetCount(); ++i) {
            MS2Ptr<CItem> item = items[i];
            if (!(item == 0)) {
                if (FUN_140526470(item.get(), m_remakeMode) != 0)
                    uids.Add(items.GetAt(i)->FUN_140526a50());
            }
        }
        MyPC* pc = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pc != 0) {
            ATL::CAtlList<MS2Ptr<Unk_BackUpItem> > equips(10);
            FUN_1411e1ce0(FUN_1416561a0(pc), &equips, 0);
            POSITION pos = equips.GetHeadPosition();
            while (pos != 0) {
                MS2Ptr<Unk_BackUpItem> equip = equips.GetAt(pos);
                if (!(equip == 0)) {
                    MS2Ptr<CItem> item = equip->FUN_1411dc7a0();
                    if (!(item == 0)) {
                        if (FUN_140526470(item.get(), m_remakeMode) != 0)
                            uids.Add(item->FUN_140526a50());
                    }
                }
                equips.GetNext(pos);
            }
        }
        FUN_141414e50(vfunc_1());
        FUN_141414d60(vfunc_1(), uids);
        MS2Ptr<Unk_EnBag> bag = m_enchantAni->FUN_140accef0<Unk_EnBag>("m_itemBag");
        if (bag.get() != 0)
            bag->FUN_1407cba60("bagId", vfunc_1());
    }
}


// @0x14129e190
void UIItemRemakeOptionDialog::FUN_14129e190(ASData* pData)
{
    if (0x31 < DAT_143ab2914) {
        unsigned __int64 uid = FUN_140718350(pData->FUN_1422b8d30());
        int option = pData->FUN_1422b8a10();
        if (uid != 0) {
            MS2Ptr<CItem> item = FUN_1419bef70(uid);
            if (!(item == 0) && item->FUN_140527840() != 0) {
                CCItemRemakeOptionPacket::RemakeOptionDebug dbg;
                dbg.m_kind = 1;
                dbg.m_value = 300;
                dbg.m_18 = uid;
                FUN_1412a1c40(3);
                Unk_LockOpt lockOpt;
                int lockValue;
                if (-1 < option) {
                    if (m_optionCount < 2) {
                        NOTICE(FUN_140298ea0(CStringW(L"s_itemremake_notice_disable_lock_item_option_error_count")));
                        return;
                    }
                    Unk_RemakeStat stat(m_remakeMode, MS2Ptr<CItem>(item), false);
                    if (stat.FUN_140619290(option, lockOpt, lockValue))
                        dbg.m_options.FUN_140b9b410(lockOpt);
                }
                COutPacket pkt(0x75, 0);
                pkt.Encode1(7);
                dbg.vfunc_1(pkt);
                FUN_140710590(pkt);
                return;
            }
            FUN_1412751f0(FUN_14028b8e0(CStringW(L"s_itemremake_error_server_not_in_inven")), 1, 1);
        }
    }
}

// @0x14129e530
void UIItemRemakeOptionDialog::FUN_14129e530(ASData* pData)
{
    if (0x31 < DAT_143ab2914) {
        unsigned __int64 uid = FUN_140718350(pData->FUN_1422b8d30());
        int option = pData->FUN_1422b8a10();
        CString valueText = pData->FUN_1422b8d30();
        valueText.Replace(",", "");
        int value = FUN_1407181d0(&valueText);
        if (uid != 0) {
            MS2Ptr<CItem> item = FUN_1419bef70(uid);
            if (!(item == 0) && item->FUN_140527840() != 0) {
                CCItemRemakeOptionPacket::RemakeOptionDebug dbg;
                dbg.m_18 = uid;
                dbg.m_kind = 2;
                if (value == 0)
                    dbg.m_value = 100000;
                else
                    dbg.m_value = value;
                FUN_1412a1c40(3);
                Unk_LockOpt lockOpt;
                int lockValue;
                if (-1 < option) {
                    if (m_optionCount < 2) {
                        NOTICE(FUN_140298ea0(CStringW(L"s_itemremake_notice_disable_lock_item_option_error_count")));
                        return;
                    }
                    Unk_RemakeStat stat(m_remakeMode, MS2Ptr<CItem>(item), false);
                    if (stat.FUN_140619290(option, lockOpt, lockValue))
                        dbg.m_options.FUN_140b9b410(lockOpt);
                }
                COutPacket pkt(0x75, 0);
                pkt.Encode1(7);
                dbg.vfunc_1(pkt);
                FUN_140710590(pkt);
                return;
            }
            FUN_1412751f0(FUN_14028b8e0(CStringW(L"s_itemremake_error_server_not_in_inven")), 1, 1);
        }
    }
}

// @0x14129e950
void UIItemRemakeOptionDialog::FUN_14129e950(ASData* pData)
{
    unsigned __int64 uid = FUN_140718350(pData->FUN_1422b8d30());
    int option = pData->FUN_1422b8a10();
    if (option < 0) {
        FUN_1412a1d40(uid, option, true);
        return;
    }
    MS2Ptr<CItem> item = FUN_1419bef70(uid);
    if (!(item == 0) && item->FUN_140527840() != 0) {
        if (!FUN_1412a0940(MS2Ptr<CItem>(item)))
            return;
        int lockId = FUN_140616dd0(MS2Ptr<CItem>(item));
        if (lockId == 0) {
            FUN_1412751f0(FUN_14028b8e0(CStringW(L"s_itemremake_error_server_impossible")), 1, 1);
            return;
        }
        unsigned lockLevel = FUN_140616f10(MS2Ptr<CItem>(item));
        CStringW lockText = FUN_140619760(lockId, lockLevel);
        CStringW ask = FUN_1405c2690(CStringW(L"s_itemremake_ask_lock_item_option"), lockText);
        MS2Ptr<CMsgBoxData> box = FUN_140d74230(
            Delegate<bool(int, const CMsgBoxData&)>(this, &UIItemRemakeOptionDialog::FUN_1412a2a50), CStringW(ask));
        if (box.get() != 0) {
            box->FUN_1405340b0(uid);
            box->FUN_140533ff0(option);
        }
        return;
    }
    FUN_1412751f0(FUN_14028b8e0(CStringW(L"s_itemremake_error_server_not_in_inven")), 1, 1);
}

// @0x14129ed90
void UIItemRemakeOptionDialog::FUN_14129ed90(ASData* pData)
{
    if (!(m_enchantAni == 0)) {
        FUN_1412a1c40(4);
        int select = pData->FUN_1422b8a10();
        if (select == -1) {
            FUN_1412751f0(FUN_14028b8e0(CStringW(L"s_itemremake_error_server_fail_apply_option")), 1, 1);
        } else {
            MS2Ptr<CItem>& source = (select == 0) ? m_cur : m_new;
            MS2Ptr<CItem> picked = source;
            bool bApplied = (picked == m_new.get());
            if (!bApplied) {
                COutPacket pkt(0x75, 0);
                pkt.Encode1(3);
                pkt.Encode1(1);
                FUN_140710590(pkt);
            } else {
                CCItemRemakeOptionPacket::ApplyOptionClient apply;
                apply.m_uid = picked->FUN_140526a50();
                COutPacket pkt(0x75, 0);
                pkt.Encode1(2);
                apply.vfunc_1(pkt);
                FUN_140710590(pkt);
            }
            Unk_RemakeStat stat(m_remakeMode, MS2Ptr<CItem>(picked), true);
            CStringW finalText = FUN_140617e50(CStringW(L"s_itemremake_final_random_option"), stat, 0);
            ASObj obj(2);
            obj.FUN_1407cbb20("remakeStatFinal", CStringW(finalText));
            obj.FUN_1407cba60("binding", FUN_1412a0720(picked.get(), Unk_SocketFormat("{0}.resultItem", vfunc_1()), m_names198));
            m_enchantAni->Invoke("selectComplete", obj.FUN_1422bb870());
            FUN_1412a1650(MS2Ptr<CItem>(picked));
            FUN_14129dd50();
            vfunc_85(0x67);
            FUN_141276180(s_successEffect, CString(""));
            if (!bApplied) {
                m_new = 0;
                m_cur = 0;
            }
        }
    }
}

// @0x14129f360
void UIItemRemakeOptionDialog::FUN_14129f360(ASData* pData)
{
    if (m_enchantAni == 0 || m_cur == 0)
        return;
    const Scaleform::GFx::Value arg = pData->FUN_1422b9260();
    ASObj result(arg, 2);
    if (!result.FUN_1422ba9a0()) {
        unsigned char bEnable = 0;
        if (m_optionCount < 2) {
            NOTICE(FUN_14028b8e0(CStringW(L"s_itemremake_notice_disable_lock_item_option_error_count")));
        } else {
            int lockId = FUN_140616dd0(MS2Ptr<CItem>(m_cur));
            if (lockId != 0) {
                unsigned lockLevel = FUN_140616f10(MS2Ptr<CItem>(m_cur));
                int have = DAT_143ab2a90.FUN_140a5f7b0(lockId, lockLevel);
                if (have < 1) {
                    CStringW lockText = FUN_140619760(lockId, lockLevel);
                    NOTICE(FUN_1405c2690(CStringW(L"s_itemremake_notice_disable_lock_item_option"), lockText));
                } else {
                    bEnable = 1;
                }
            }
        }
        result.FUN_1407cbbe0("value", bEnable);
    }
}

// @0x14129f6f0
void UIItemRemakeOptionDialog::OnEndRemakeAni()
{
    if (m_enchantAni == 0)
        return;
    vfunc_85(0x66);
}

// @0x14129f740
void UIItemRemakeOptionDialog::SendChangeAttributesMode4(unsigned __int64 uid)
{
    if (FUN_1412a1c60() != 0) {
        MS2Ptr<CItem> item = FUN_1419bef70(uid);
        if (!(item == 0)) {
            if (FUN_140526470(item.get(), m_remakeMode) == 0) {
                FUN_1412751f0(FUN_14028b8e0(CStringW(L"s_itemremake_error_server_impossible")), 1, 1);
                FUN_1412a0800();
                m_enchantAni->Invoke("initEnchantSlot");
            } else {
                COutPacket pkt(0x75, 0);
                pkt.Encode1(4);
                pkt.Encode8(item->FUN_140526a50());
                FUN_140710590(pkt);
            }
        } else {
            FUN_1412751f0(FUN_14028b8e0(CStringW(L"s_itemremake_error_server_not_in_inven")), 1, 1);
        }
    }
}

// @0x14129f940
void UIItemRemakeOptionDialog::FUN_14129f940(CInPacket* pPacket)
{
    unsigned __int64 uid = pPacket->vfunc_o8_4();
    CIngredientContainer ingredients;
    ingredients.FUN_14026c0b0(*pPacket);
    FUN_1412a2ac0();
    FUN_1412a1c40(2);
    MS2Ptr<CItem> item = FUN_1419bef70(uid);
    if (!(item == 0)) {
        if (FUN_140526470(item.get(), m_remakeMode) == 0) {
            FUN_1412751f0(FUN_14028b8e0(CStringW(L"s_itemremake_error_server_impossible")), 1, 1);
            FUN_1412a0800();
            m_enchantAni->Invoke("initEnchantSlot");
            return;
        }
        FUN_1412a0800();
        m_cur = item;
        ASObj obj(2);
        obj.FUN_1407cbb20("itemName", item->FUN_140528160());
        int remakeCount = item->FUN_140527300();
        obj.FUN_1407cbb20("remakeCount", FUN_14062b4f0(CStringW(L"s_itemremake_remake_count"), &remakeCount));
        FUN_1412a0cd0(obj, MS2Ptr<CItem>(m_cur));
        FUN_1412a0e30(obj, MS2Ptr<CItem>(m_cur), &ingredients);
        unsigned optionCount = 0;
        Unk_RemakeStat stat(m_remakeMode, MS2Ptr<CItem>(m_cur), true);
        CStringW option = FUN_140617e50(CStringW(L"s_itemremake_cur_random_option"), stat, &optionCount);
        bool bEnableLock = FUN_140616fd0(MS2Ptr<CItem>(m_cur));
        m_optionCount = optionCount;
        CString guid = FUN_140719530(uid);
        obj.FUN_1407cbb20("option", CStringW(option));
        obj.FUN_1409c0d20("optionCount", optionCount);
        obj.FUN_1407cba60("guid", CString(guid));
        obj.FUN_1407cbbe0("enableLock", bEnableLock);
        m_enchantAni->Invoke("playEnchant", obj.FUN_1422bb870());
        vfunc_85(100);
        FUN_141276180(s_itemChoice, CString(""));
        MS2Ptr<ASMovieClip> info = m_enchantAni->FUN_1409b4560("remakeOptionInfo");
        if (info.get() != 0) {
            bool bDebug = FUN_14025e7c0()->IsDebugMode() != 0;
            m_debugBtnFillIngredientUnit = info->FUN_140acce30<Unk_EnButton>("m_debugBtnFillIngredientUnit");
            if (m_debugBtnFillIngredientUnit.get() != 0) {
                m_debugBtnFillIngredientUnit->vfunc_3(bDebug);
                if (bDebug)
                    m_debugBtnFillIngredientUnit->FUN_1422ce240(
                        Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &UIItemRemakeOptionDialog::FUN_1412a0550), 0);
            }
            m_debugBtnFillIngredient = info->FUN_140acce30<Unk_EnButton>("m_debugBtnFillIngredient");
            if (m_debugBtnFillIngredient.get() != 0) {
                m_debugBtnFillIngredient->vfunc_3(bDebug);
                if (bDebug)
                    m_debugBtnFillIngredient->FUN_1422ce240(
                        Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &UIItemRemakeOptionDialog::FUN_1412a0460), 0);
            }
        }
    } else {
        FUN_1412751f0(FUN_14028b8e0(CStringW(L"s_itemremake_error_server_not_in_inven")), 1, 1);
    }
}

// @0x1412a0460
void UIItemRemakeOptionDialog::FUN_1412a0460(const Scaleform::GFx::FunctionHandler::Params& params)
{
    if (m_cur == 0)
        return;
    if (DAT_143ab2914 < 0x32)
        return;
    if (FUN_1412a1c60() != 2)
        return;
    CCItemRemakeOptionPacket::ForceFillIngredient fill;
    fill.m_uid = m_cur->FUN_140526a50();
    COutPacket pkt(0x75, 0);
    pkt.Encode1(8);
    fill.vfunc_1(pkt);
    FUN_140710590(pkt);
}

// @0x1412a0550
void UIItemRemakeOptionDialog::FUN_1412a0550(const Scaleform::GFx::FunctionHandler::Params& params)
{
    if (m_cur == 0)
        return;
    if (DAT_143ab2914 < 0x32)
        return;
    if (FUN_1412a1c60() != 2)
        return;
    CCItemRemakeOptionPacket::ForceFillIngredient fill;
    fill.m_uid = m_cur->FUN_140526a50();
    fill.m_count = 10;
    COutPacket pkt(0x75, 0);
    pkt.Encode1(8);
    fill.vfunc_1(pkt);
    FUN_140710590(pkt);
}

// @0x1412a0650
bool UIItemRemakeOptionDialog::FUN_1412a0650(int nResult, const CMsgBoxData& box)
{
    if (nResult == 0) {
        __int64 uid = box.FUN_141a02c20();
        int option = box.FUN_141a02e50(1, 0);
        bool bConfirm = box.FUN_141a02e10(2, 0);
        FUN_1412a2380(uid, option, bConfirm);
    } else {
        FUN_1412a2ac0();
        FUN_1412a0800();
        m_enchantAni->Invoke("initEnchantSlot");
    }
    return true;
}

// @0x1412a0720
CString UIItemRemakeOptionDialog::FUN_1412a0720(CItem* item, CString key, CAtlArray<CString>& names)
{
    FUN_141415600(key);
    int nFlags = 0x2020;
    FUN_141415450(key, MS2Ptr<CItem>(item), 0, 0x405, nFlags);
    FUN_140165270(names, key);
    return CString(key);
}

// @0x1412a0800
void UIItemRemakeOptionDialog::FUN_1412a0800()
{
    size_t count = m_names198.GetCount();
    for (size_t i = 0; i < count; ++i)
        FUN_141415600(m_names198[i]);
    FUN_1402c2890(m_names198);
    count = m_names1b8.GetCount();
    for (size_t i = 0; i < count; ++i)
        FUN_141415600(m_names1b8[i]);
    FUN_1402c2890(m_names1b8);
}

// @0x1412a0900
Unk_EnSlot* UIItemRemakeOptionDialog::FUN_1412a0900(const CString& name)
{
    Unk_EnSlot* slot = FUN_140f6e830(name);
    if (slot != 0)
        return slot;
    return 0;
}

// @0x1412a0940
bool UIItemRemakeOptionDialog::FUN_1412a0940(MS2Ptr<CItem> item)
{
    if (item == 0)
        return false;
    unsigned discount = 0;
    unsigned rate = 0;
    MyPC* pc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pc != 0)
        rate = (unsigned)(__int64)(FUN_1411e1110(FUN_1416561a0(pc), 0xa9) * 10000.0f);
    MS2Ptr<CItemData> equipData(reinterpret_cast<CItemData*>(item->FUN_140527840()));
    int bSale = FUN_140616b60(equipData, &discount, rate);
    __int64 fee = 0;
    size_t count = m_names1b8.GetCount();
    for (size_t i = 0; i < count; ++i) {
        Unk_EnSlot* slot = FUN_1412a0900(m_names1b8[i]);
        if (slot != 0) {
            MS2Ptr<CItem> slotItem = slot->vfunc_25();
            if (!(slotItem == 0) && slotItem->FUN_140527840() != 0) {
                int need = slotItem->FUN_140526c50();
                int price = need;
                if (bSale != 0)
                    price = FUN_140616d40(need, discount);
                int have = FUN_1412a1c80(MS2Ptr<CItem>(slotItem));
                if (have < price) {
                    if (slotItem->FUN_140526320() == 0) {
                        FUN_1412752d0(CStringW(L"s_itemremake_error_server_lack_price"), 1);
                        return false;
                    }
                    fee = (__int64)((price - have) * 1000);
                }
            }
        }
    }
    bool bEnough = fee <= DAT_143ab2898;
    if (!bEnough)
        FUN_1412752d0(CStringW(L"s_itemremake_error_server_lack_price"), 1);
    return bEnough;
}

// @0x1412a0cd0
void UIItemRemakeOptionDialog::FUN_1412a0cd0(ASObj& obj, MS2Ptr<CItem> item)
{
    if (item == 0)
        return;
    obj.FUN_1407cba60("enchantItem",
        FUN_1412a0720(item.get(), Unk_SocketFormat("{0}.selectedItem", vfunc_1()), m_names198));
}

// @0x1412a0e30
void UIItemRemakeOptionDialog::FUN_1412a0e30(ASObj& obj, MS2Ptr<CItem> item, CIngredientContainer* ingredients)
{
    if (!(item == 0) && item->FUN_140527840() != 0) {
        MS2Ptr<CItemData> equipData(reinterpret_cast<CItemData*>(item->FUN_140527840()));
        unsigned discount = 0;
        unsigned rate = 0;
        MyPC* pc = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pc != 0)
            rate = (unsigned)(__int64)(FUN_1411e1110(FUN_1416561a0(pc), 0xa9) * 10000.0f);
        __int64 fee = 0;
        int bSale = FUN_140616b60(MS2Ptr<CItemData>(equipData), &discount, rate);
        ASArray list(2);
        for (size_t i = 0; i < ingredients->FUN_14026bf10(); ++i) {
            Unk_IngRef ref = ingredients->FUN_14026be50(i);
            if (!(ref == 0)) {
                if (!ref->FUN_14026b350()) {
                    unsigned itemId = ref->FUN_14026b500();
                    int count = ref->m_c;
                    int type = ref->m_b;
                    int rank = FUN_14053feb0(itemId);
                    MS2Ptr<CItem> ingredient(new CItem());
                    if (ingredient->FUN_14052b2e0(itemId, rank, 0, count) != 0) {
                        int have = FUN_1412a1c80(MS2Ptr<CItem>(ingredient));
                        CString bagKey = StringFormat("{0}.ingredient.{1}", vfunc_1(), i);
                        ASObj entry(2);
                        entry.FUN_1407cba60("binding", FUN_1412a0720(ingredient.get(), CString(bagKey), m_names1b8));
                        entry.FUN_1407cbb20("countText", FUN_1419021b0(have, count));
                        reinterpret_cast<Unk_EnArray&>(list).FUN_1422bbf00(entry);
                        if (type == 0x60 && have < count)
                            fee = (__int64)((count - have) * 1000);
                    }
                }
            }
        }
        CStringW saleDesc;
        if (bSale == 1) {
            float rateText = (float)discount * 0.01;
            saleDesc = FUN_14042cb90(CStringW(L"s_itemremake_sale_desc"), rateText);
        } else if (bSale == 2) {
            float rateText = (float)discount * 0.01;
            saleDesc = FUN_14042cb90(CStringW(L"s_itemremake_sa_sale_desc"), rateText);
        }
        obj.FUN_1407cbb20("saleDesc", CStringW(saleDesc));
        obj.FUN_1409eb1d0("ingredient", list);
        if (0 < fee)
            obj.FUN_1407cbb20("remakeFee", FUN_1405c2690(CStringW(L"s_itemenchant_fee"), FUN_1409404f0(fee)));
    }
}

// @0x1412a1600
void UIItemRemakeOptionDialog::FUN_1412a1600(MS2Ptr<CItem> item)
{
    SendChangeAttributesMode4(item->FUN_140526a50());
}

// @0x1412a1650
void UIItemRemakeOptionDialog::FUN_1412a1650(MS2Ptr<CItem> item)
{
    if (item.get() != 0) {
        if (FUN_1419beef0(item->FUN_140526a50()) == 0) {
            MyPC* pc = FUN_1403ed2d0()->FUN_141bd0cc0();
            if (pc != 0) {
                MS2Ptr<Unk_BackUpItem> equip = FUN_1416561a0(pc)->FUN_1411e1580(item->FUN_140526a50());
                if (equip.get() != 0) {
                    equip->FUN_1411dd6d0(item.get());
                    equip->FUN_1411dd280();
                    FUN_1411e7660(FUN_1416561a0(pc));
                }
            }
        } else {
            DAT_143ab2a90.FUN_140a5d530(item.get());
        }
    }
}

// @0x1412a1790
void UIItemRemakeOptionDialog::FUN_1412a1790(MS2Ptr<CItem> cur, MS2Ptr<CItem> next)
{
    if (!(m_enchantAni == 0)) {
        ASObj obj(2);
        obj.FUN_1407cbb20("itemName", cur->FUN_140528160());
        int remakeCount = cur->FUN_140527300();
        obj.FUN_1407cbb20("remakeCount", FUN_14062b4f0(CStringW(L"s_itemremake_remake_count"), &remakeCount));
        obj.FUN_1407cba60("binding", FUN_1412a0720(cur.get(), Unk_SocketFormat("{0}.resultItem", vfunc_1()), m_names198));
        CStringW keyCur(L"s_itemremake_cur_random_option");
        CStringW keyNew(L"s_itemremake_new_random_option");
        Unk_RemakeStat stat(m_remakeMode, MS2Ptr<CItem>(cur), true);
        obj.FUN_1407cbb20("remakeStat0", FUN_140617e50(keyCur, stat, 0));
        stat.m_item = next;
        obj.FUN_1407cbb20("remakeStat1", FUN_140617e50(keyNew, stat, 0));
        obj.FUN_1407cb9c0("selectedStatIndex", 0);
        m_enchantAni->Invoke("setEnchantResult", obj);
        FUN_141276180(s_progress, CString(""));
    }
}

// @0x1412a1c40
void UIItemRemakeOptionDialog::FUN_1412a1c40(int nState)
{
    m_state = nState;
}

// @0x1412a1c60
int UIItemRemakeOptionDialog::FUN_1412a1c60()
{
    return m_state;
}

// @0x1412a1c80
int UIItemRemakeOptionDialog::FUN_1412a1c80(MS2Ptr<CItem> item)
{
    if (item == 0 || item->FUN_140527840() == 0)
        return 0;
    int have = 0;
    int itemId = reinterpret_cast<CItemData*>(item->FUN_140527840())->FUN_14053c6f0();
    if (itemId != 0)
        have = DAT_143ab2a90.FUN_140a5f7b0(itemId, 0);
    return have;
}

// @0x1412a1d40
void UIItemRemakeOptionDialog::FUN_1412a1d40(unsigned __int64 uid, int nOption, bool bConfirm)
{
    MS2Ptr<CItem> item = FUN_1419bef70(uid);
    if (!(item == 0) && item->FUN_140527840() != 0) {
        unsigned mode = m_remakeMode;
        if (FUN_140526470(item.get(), mode) == 0) {
            FUN_1412751f0(FUN_14028b8e0(CStringW(L"s_itemremake_error_server_impossible")), 1, 1);
            return;
        }
        if (bConfirm) {
            if (!FUN_1412a0940(MS2Ptr<CItem>(item)))
                return;
        }
        CStringW highSa;
        char bHighSa = 0;
        FUN_1409e4950(MS2Ptr<CItem>(item), highSa, &bHighSa);
        if (item->FUN_140526bd0() < 5 || bHighSa != 1) {
            FUN_1412a2380(uid, nOption, bConfirm);
        } else {
            CStringW ask = FUN_14028b8e0(CStringW(L"s_itemremake_ask_high_sa_item_option"));
            CStringW text;
            text.Append(highSa);
            text.Append(L"\n");
            text.Append(ask);
            MS2Ptr<CMsgBoxData> box = FUN_140d73d20(0x11, CStringW(text), 0, CStringW(L""));
            if (box.get() != 0) {
                box->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &UIItemRemakeOptionDialog::FUN_1412a0650));
                box->FUN_141a01600(item->FUN_140526a50());
                box->FUN_141a01ee0(MS2Ptr<CItem>(item), item->FUN_140527b10(), 1, 0, -1, -1, 1);
                box->FUN_141a01700(0x475, 0x476, 0);
                box->FUN_1405340b0(uid);
                box->FUN_140533ff0(nOption);
                FUN_140f73320(box.operator->(), bConfirm);
                FUN_140d73c60(MS2Ptr<CMsgBoxData>(box));
            }
        }
        return;
    }
    FUN_1412751f0(FUN_14028b8e0(CStringW(L"s_itemremake_error_server_not_in_inven")), 1, 1);
}

// @0x1412a2380
void UIItemRemakeOptionDialog::FUN_1412a2380(unsigned __int64 uid, int nOption, bool bConfirm)
{
    MS2Ptr<CItem> item = FUN_1419bef70(uid);
    if (!(item == 0) && item->FUN_140527840() != 0) {
        unsigned mode = m_remakeMode;
        if (FUN_140526470(item.get(), mode) == 0) {
            FUN_1412751f0(FUN_14028b8e0(CStringW(L"s_itemremake_error_server_impossible")), 1, 1);
            return;
        }
        if (bConfirm) {
            if (!FUN_1412a0940(MS2Ptr<CItem>(item)))
                return;
        }
        CCItemRemakeOptionPacket::RemakeOption option;
        option.m_18 = uid;
        Unk_LockOpt lockOpt;
        int lockValue;
        if (-1 < nOption) {
            if (m_optionCount < 2) {
                NOTICE(FUN_140298ea0(CStringW(L"s_itemremake_notice_disable_lock_item_option_error_count")));
                return;
            }
            int lockId = FUN_140616dd0(MS2Ptr<CItem>(item));
            if (lockId == 0) {
                FUN_1412751f0(FUN_14028b8e0(CStringW(L"s_itemremake_error_server_impossible")), 1, 1);
                return;
            }
            unsigned lockLevel = FUN_140616f10(MS2Ptr<CItem>(item));
            int have = DAT_143ab2a90.FUN_140a5f7b0(lockId, lockLevel);
            if (have < 1) {
                CStringW lockText = FUN_140619760(lockId, lockLevel);
                NOTICE(FUN_1405c2690(CStringW(L"s_itemremake_notice_disable_lock_item_option_when_click_remake"), lockText));
                return;
            }
            Unk_RemakeStat stat(m_remakeMode, MS2Ptr<CItem>(item), false);
            if (stat.FUN_140619290(nOption, lockOpt, lockValue))
                option.m_options.FUN_140b9b410(lockOpt);
        }
        COutPacket pkt(0x75, 0);
        pkt.Encode1(0);
        option.vfunc_1(pkt);
        FUN_140710590(pkt);
        FUN_1412761e0(MS2Ptr<AScript>(m_30), 0);
        FUN_1412a1c40(3);
        return;
    }
    FUN_1412751f0(FUN_14028b8e0(CStringW(L"s_itemremake_error_server_not_in_inven")), 1, 1);
}

// @0x1412a2a50
bool UIItemRemakeOptionDialog::FUN_1412a2a50(int nResult, const CMsgBoxData& box)
{
    if (nResult == 0) {
        __int64 uid = box.FUN_141a02f10(0, 0);
        int option = box.FUN_141a02e50(1, 0);
        FUN_1412a2380(uid, option, false);
    }
    return true;
}

// @0x1412a2ac0
void UIItemRemakeOptionDialog::FUN_1412a2ac0()
{
    m_cur = 0;
    m_new = 0;
    m_debugBtnFillIngredient = 0;
    m_debugBtnFillIngredientUnit = 0;
    m_optionCount = 0;
}

// @0x1412a2b40
void UIItemRemakeOptionDialog::FUN_1412a2b40(unsigned nItemId)
{
    CStringW name = FUN_1401a9d70()->FUN_141811980(1, nItemId);
    CStringW text = FUN_1405c2690(CStringW(L"s_itemremake_error_prev_option_item_not_exist"), name);
    FUN_140d73aa0(CStringW(text), 0, 0, CStringW(L""));
    FUN_1412751b0(text, 0x14);
}

// @0x1412a2c50
void UIItemRemakeOptionDialog::FUN_1412a2c50(CInPacket* pPacket)
{
    unsigned char bResult = pPacket->vfunc_o8_1();
    if (bResult == 0) {
        FUN_1412a1c40(1);
    } else {
        unsigned nErrorItem = pPacket->vfunc_o8_3();
        if (bResult == 2) {
            FUN_1412a2b40(nErrorItem);
            FUN_1412a1c40(1);
        } else {
            unsigned __int64 uid = pPacket->vfunc_o8_4();
            MS2Ptr<CItem> item = FUN_1419be700(uid);
            if (!(item == 0)) {
                if (FUN_140526470(item.get(), 2) == 0) {
                    FUN_1412751f0(FUN_140298ea0(CStringW(L"s_itemremake_error_server_impossible")), 1, 1);
                    FUN_1412a1c40(1);
                } else {
                    FUN_1412a1c40(3);
                    m_cur = item;
                    ASObj obj(2);
                    obj.FUN_1407cba60("lastItemGUID", FUN_140719530(m_cur->FUN_140526a50()));
                    m_enchantAni->Invoke("setLastItemGUID", obj);
                    m_new = m_cur->FUN_140524250();
                    CCItemRemakeOptionPacket::ApplyOptionClient apply;
                    apply.m_item = m_new;
                    apply.vfunc_2(*pPacket);
                    unsigned nCount = m_new->FUN_140527300();
                    m_cur->FUN_1405272e0(nCount);
                    FUN_1412a1790(MS2Ptr<CItem>(m_cur), MS2Ptr<CItem>(m_new));
                }
            } else {
                FUN_1412a2b40(nErrorItem);
                FUN_1412a1c40(1);
            }
        }
    }
}

// @0x1412a30f0
void UIItemRemakeOptionDialog::FUN_1412a30f0(CInPacket* pPacket)
{
    m_new = m_cur->FUN_140524250();
    CCItemRemakeOptionPacket::ApplyOptionClient apply;
    apply.m_item = m_new;
    apply.vfunc_2(*pPacket);
    unsigned nCount = m_new->FUN_140527300();
    m_cur->FUN_1405272e0(nCount);
    MS2Ptr<CItem> item = FUN_1419bef70(apply.m_uid);
    if (!(item == 0))
        FUN_1412a1790(MS2Ptr<CItem>(m_cur), MS2Ptr<CItem>(m_new));
    else
        FUN_1412751f0(FUN_14028b8e0(CStringW(L"s_itemremake_error_server_not_in_inven")), 1, 1);
}

// @0x1412a3330
void UIItemRemakeOptionDialog::FUN_1412a3330(CInPacket* pPacket)
{
    if (m_new == 0)
        return;
    CCItemRemakeOptionPacket::ApplyOptionClient apply;
    apply.m_item = m_new;
    apply.vfunc_2(*pPacket);
    if (apply.m_uid != m_new->FUN_140526a50())
        return;
    FUN_1412a1650(MS2Ptr<CItem>(m_new));
    m_new = 0;
    m_cur = 0;
}

// @0x1412a3460
void UIItemRemakeOptionDialog::FUN_1412a3460(CInPacket* pPacket)
{
    if (m_cur == 0)
        return;
    if (DAT_143ab2914 < 0x32)
        return;
    if (FUN_1412a1c60() != 2)
        return;
    FUN_1412a1600(MS2Ptr<CItem>(m_cur));
}

// @0x1412a34f0
void UIItemRemakeOptionDialog::FUN_1412a34f0(CInPacket* pPacket)
{
    unsigned bFlag = pPacket->vfunc_o8_1();
    int nCode = pPacket->vfunc_o8_3();
    if (FUN_1412a1c60() == 3 && bFlag == 0)
        FUN_1412a1c40(2);
    CStringW text;
    switch (nCode - 1) {
    case 0:
        text = L"s_itemremake_error_server_not_in_inven";
        break;
    case 1:
        text = L"s_itemremake_error_server_impossible";
        break;
    case 2:
    case 3:
        text = L"s_itemremake_error_server_null_status";
        break;
    case 4:
        text = L"s_itemremake_error_server_lack_price";
        break;
    case 5:
    case 6:
        text = L"s_itemremake_error_server_fail_apply_option";
        break;
    default:
        text = L"s_itemremake_error_server_default";
        break;
    case 8:
        text = L"s_itemremake_error_server_fail_lack_lock_consume_item";
        break;
    case 9:
        text = L"s_content_shutdown_notice";
    }
    FUN_1412751f0(FUN_140b99120(CStringW(text), bFlag, nCode), 1, 1);
}

// @0x1412a3ed0
UIItemModifyDialogBase::~UIItemModifyDialogBase()
{
}

// @0x1412a4070
MS2Ptr<ASMovieClip> UIItemModifyDialogBase::vfunc_86()
{
    return m_enchantAni;
}

// @0x1412a40c0
int UIItemRemakeOptionDialog::vfunc_48()
{
    return 0x4eeb;
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142caef40-0x142caf080 .text$yd
