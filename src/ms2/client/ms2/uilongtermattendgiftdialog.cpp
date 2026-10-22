// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Long-term attendance gift event dialog.
// MS2-UNIT: client\ms2\uilongtermattendgiftdialog.cpp
// MS2-RANGE: 0x1400ce500-0x1400ce910 .text$di
// MS2-RANGE: 0x140c6b300-0x140c6e3a0 .text$mn
// MS2-PIN: ?vfunc_48@UILongTermAttendGiftDialog@@UEAAHXZ 0x140c6e000
// MS2-PIN: ?vfunc_2@?$DelegateImpl@U?$pair@PEAVUILongTermAttendGiftDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEAAXPEAVNotifyObject@@@Z 0x140c6e0d0
// MS2-PIN: ??$Call@VUILongTermAttendGiftDialog@@P81@EAAXPEAVNotifyObject@@@Z@?$DelegateImpl@U?$pair@PEAVUILongTermAttendGiftDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@CAXAEAU?$pair@PEAVUILongTermAttendGiftDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@PEAVNotifyObject@@@Z 0x140c6e140
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$?8PEAVUILongTermAttendGiftDialog@@P80@EAAXPEAVNotifyObject@@@Z@std@@YA_NAEBU?$pair@PEAVUILongTermAttendGiftDialog@@P81@EAAXPEAVNotifyObject@@@Z@0@0@Z 0x140c6d7f0 ; prop
// MS2-PIN: ??$?8PEAVUILongTermAttendGiftDialog@@P80@EAA_NHAEBVCMsgBoxData@@@Z@std@@YA_NAEBU?$pair@PEAVUILongTermAttendGiftDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@0@0@Z 0x140c6d860 ; prop
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVUILongTermAttendGiftDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@QEAA@AEBV01@@Z 0x140c6ddb0 ; unique
// MS2-PIN: ??_G?$DelegateImpl@U?$pair@PEAVUILongTermAttendGiftDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEAAPEAXI@Z 0x140c6df40 ; prop
// MS2-PIN: ??_G?$DelegateImpl@U?$pair@PEAVUILongTermAttendGiftDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEAAPEAXI@Z 0x140c6df80 ; prop
// MS2-PIN: ??_GUILongTermAttendGiftDialog@@UEAAPEAXI@Z 0x140c6dfc0 ; unique
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVUILongTermAttendGiftDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x140c6e010 ; unique
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVUILongTermAttendGiftDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x140c6e070 ; unique
// MS2-PIN: ?Invoke@?$DelegateImpl@U?$pair@PEAVUILongTermAttendGiftDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEAA_NHAEBVCMsgBoxData@@@Z 0x140c6e100 ; unique
// MS2-PIN: ??$Call@VUILongTermAttendGiftDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@?$DelegateImpl@U?$pair@PEAVUILongTermAttendGiftDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@CA_NAEAU?$pair@PEAVUILongTermAttendGiftDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@HAEBVCMsgBoxData@@@Z 0x140c6e180 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVUILongTermAttendGiftDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x140c6e1c0 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVUILongTermAttendGiftDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x140c6e220 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uilongtermattendgiftdialog.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "uilongtermattendgiftdialog.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/astooltip.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/mstime.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/notifyobject.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/commonfiles/itemgift.h"
#include "ms2/client/ms2/uimessageboxdata.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

MS2_EMIT_CRT_MEMMOVE_S();

// ---- header statics (the exe runs them in this order; every group is its own copy of an unidentified header) ----

static CString s_strSortTypeNamesLtaA[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkillLtaA = "skill";
static CString s_strStunLtaA = "stun";

static CString s_strSortTypeNamesLtaB[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};

static CString s_strSortTypeNamesLtaC[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkillLtaC = "skill";
static CString s_strStunLtaC = "stun";
static Unk_1402a9d70 s_unk1402a9d70Lta(17, 0.75f, 0.25f, 2.25f, 10);

static CString s_strSortTypeNamesLtaD[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};

// ---- unit-local helper types ----

// One attendance day of the event: the day number and the two reward items (ItemEntity at +0x20 / +0x50).
class Unk_LtaRecord : public CPtred {
public:
    int m_day;
    int m_pad_1c;
    ItemEntity m_20;
    ItemEntity m_50;
};
MS2_CHECK_OFFSET(Unk_LtaRecord, m_day, 0x18);
MS2_CHECK_OFFSET(Unk_LtaRecord, m_20, 0x20);
MS2_CHECK_OFFSET(Unk_LtaRecord, m_50, 0x50);
MS2_CHECK_SIZE(Unk_LtaRecord, 0x80);

class Unk_LtaRecordArray {
public:
    size_t FUN_140412e80() const;
    MS2Ptr<Unk_LtaRecord>& FUN_140410eb0(size_t index);
private:
    void* m_0; void* m_8; void* m_10; void* m_18;
};
MS2_CHECK_SIZE(Unk_LtaRecordArray, 0x20);

// The event record (a game event; fetched from the event manager).
class Unk_LtaEvent : public CPtred {
public:
    int m_id;
    int m_pad_1c;
    Unk_LtaRecordArray m_rewards;
    void* m_pad_40; void* m_pad_48;
    CMsTime m_start;
    CMsTime m_end;
    CStringW m_frame;
    CStringW m_title;
    unsigned int m_days;
    int m_meratCost;
};
MS2_CHECK_OFFSET(Unk_LtaEvent, m_id, 0x18);
MS2_CHECK_OFFSET(Unk_LtaEvent, m_rewards, 0x20);
MS2_CHECK_OFFSET(Unk_LtaEvent, m_start, 0x50);
MS2_CHECK_OFFSET(Unk_LtaEvent, m_end, 0x60);
MS2_CHECK_OFFSET(Unk_LtaEvent, m_frame, 0x70);
MS2_CHECK_OFFSET(Unk_LtaEvent, m_title, 0x78);
MS2_CHECK_OFFSET(Unk_LtaEvent, m_days, 0x80);
MS2_CHECK_OFFSET(Unk_LtaEvent, m_meratCost, 0x84);

class Unk_LtaEventMgr {
public:
    MS2Ptr<Unk_LtaEvent> FUN_14047ce70();
};
Unk_LtaEventMgr* FUN_1401c0d90();

class Unk_LtaItem : public CPtred { public: CString FUN_14053fdd0(); };
MS2Ptr<Unk_LtaItem> FUN_14053f870(int);

// The list control of the movie (the AS list with clear / append).
class Unk_LtaList : public AScript
{
public:
    virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
    virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11();
    virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15();
    virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19();
    virtual void vfunc_20(); virtual void vfunc_21(); virtual void vfunc_22(); virtual void vfunc_23();
    virtual void vfunc_24(bool bRefresh);
    void FUN_1422dd1d0();                                           // clear
    void FUN_1422dd230(const ASObj& row);                           // append a row
};

// The global table of strings / ints keyed by (kind, id): global at 0x143ab2fc0, map at +0x18, entry value at +0x20
// (text), +0x28 (expiry).
struct Unk_LtaKey
{
    Unk_LtaKey(int n1, int n2);             // 0x14041eee0
    int m_0; int m_4;
};
class Unk_LtaValue;
class Unk_LtaIter                           // 24 bytes; ctor 0x140420170, dtor 0x140420290
{
public:
    Unk_LtaIter();
    ~Unk_LtaIter();
    Unk_LtaValue* FUN_140420460();          // the entry
private:
    void* m_pad_00; void* m_pad_08; void* m_pad_10;
};
MS2_CHECK_SIZE(Unk_LtaIter, 0x18);
class Unk_LtaMap { public: bool FUN_140420bb0(const Unk_LtaKey& key, Unk_LtaIter& it); };
int FUN_140718200(const CStringW& str);
CStringW FUN_140718600(const CStringW& str);
__int64 FUN_140869440();                         // the current time source
class Unk_LtaValue
{
public:
    int FUN_140c6da60(const int& nDefault) const;
    CStringW FUN_140c6dac0(const CStringW& strDefault) const;
private:
    void* m_pad_00; void* m_pad_08; void* m_pad_10; void* m_pad_18;
    CStringW m_20;                          // +0x20 stored text
    CMsTime m_28;                           // +0x28 expiry
};
class Unk_LtaTable
{
public:
    int FUN_140c6d8d0(int nKind, int nId, const int& nDefault);
    CStringW FUN_140c6d980(int nKind, int nId, const CStringW& strDefault);
private:
    void* m_pad_00; void* m_pad_08; void* m_pad_10;
    Unk_LtaMap m_18;                        // +0x18
};
extern Unk_LtaTable g_ltaTable;             // 0x143ab2fc0

// The wallet / account object (0x140d86260 singleton): only two slots are used here.
class Unk_LtaWallet
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
    virtual int vfunc_40(int nCost);
    virtual void vfunc_41(); virtual void vfunc_42(); virtual void vfunc_43(); virtual void vfunc_44();
    virtual void vfunc_45();
};
Unk_LtaWallet* FUN_140d86260();

class Unk_LtaPlayer { public: bool FUN_141bcb0a0(); };
class Unk_LtaPlayerMgr { public: void* FUN_141bd0cc0(); };
Unk_LtaPlayerMgr* FUN_1403ed2d0();
bool FUN_141bcb0a0(Unk_LtaPlayerMgr*);

class Unk_LtaOptions { public: bool FUN_14036d570(int nId); };
Unk_LtaOptions* FUN_140166410();

class Unk_LtaNotices { public: void FUN_140da4e40(CStringW, Delegate<void(NotifyObject*)>); };
Unk_LtaNotices* FUN_140939a10();

MS2Ptr<CMsgBoxData> FUN_140d74390(CStringW text, int nType, Delegate<bool(int, const CMsgBoxData&)> cb);
void FUN_140d73aa0(CStringW text, int nType, void* p, CStringW tag);
void FUN_140d73cd0();
CStringW FUN_14028b8e0(const CStringW& key);
CStringW FUN_140938ae0(CStringW strKey, const int& n);
CStringW FUN_1408f71a0(CStringW strKey, const CStringW& a, const CStringW& b);
CStringW FUN_14083bab0(const CMsTime& time, CStringW strSep);
int FUN_14086bd40(CMsTime a, CMsTime b);
const int* FUN_1402fbd20(const int* a, const int* b);   // std::min<int>
CString FUN_14016a600(const wchar_t*, int);             // narrow copy of a wide string
void FUN_1401d9a30(const CStringW&, ATL::CAtlArray<int>&, const wchar_t*);
int FUN_1402bacf0(ATL::CAtlArray<int>&, const unsigned int&);
void FUN_140710590(COutPacket&);
bool FUN_140184310(const CString&, const char*);

void FUN_1422bcea0(Scaleform::GFx::Value* pValue, const wchar_t* sz);
void FUN_1422bcd10(Scaleform::GFx::Value* pValue, unsigned int n);
void FUN_1422bcc70(Scaleform::GFx::Value* pValue, Scaleform::GFx::Value v);
void FUN_14052b420(CItem* pItem, int n);               // CItem member (not yet in citem.h)

// @0x140c6db60 (inline COMDAT)
inline Scaleform::GFx::Value AScript::Invoke(const char* szMethod, CStringW a1, CStringW a2, int a3, Scaleform::GFx::Value a4)
{
    ASArgList args;
    args.FUN_1409b2800(4);
    FUN_1422bcea0(args.FUN_1409b1f70(0), a1);
    FUN_1422bcea0(args.FUN_1409b1f70(1), a2);
    FUN_1422bcd10(args.FUN_1409b1f70(2), a3);
    FUN_1422bcc70(args.FUN_1409b1f70(3), a4);
    return FUN_1422bb8f0(szMethod, args);
}

// ---- table lookups (inline COMDATs of this unit) ----

// @0x140c6da60
inline int Unk_LtaValue::FUN_140c6da60(const int& nDefault) const
{
    CMsTime now(FUN_140869440());
    if (m_28 <= now)
        return nDefault;
    return FUN_140718200(m_20);
}

// @0x140c6dac0
inline CStringW Unk_LtaValue::FUN_140c6dac0(const CStringW& strDefault) const
{
    CMsTime now(FUN_140869440());
    if (m_28 <= now)
        return strDefault;
    return FUN_140718600(m_20);
}

// @0x140c6d8d0
inline int Unk_LtaTable::FUN_140c6d8d0(int nKind, int nId, const int& nDefault)
{
    Unk_LtaKey key(nKind, nId);
    Unk_LtaIter it;
    if (m_18.FUN_140420bb0(key, it))
        return it.FUN_140420460()->FUN_140c6da60(nDefault);
    return nDefault;
}

// @0x140c6d980
inline CStringW Unk_LtaTable::FUN_140c6d980(int nKind, int nId, const CStringW& strDefault)
{
    Unk_LtaKey key(nKind, nId);
    Unk_LtaIter it;
    if (m_18.FUN_140420bb0(key, it))
        return it.FUN_140420460()->FUN_140c6dac0(strDefault);
    return strDefault;
}

// ---- the dialog ----

// @0x140c6b300
UILongTermAttendGiftDialog::UILongTermAttendGiftDialog()
    : m_178(0)
{
    FUN_141924170(1);
    FUN_141926980(false);
    FUN_140939a10()->FUN_140da4e40(L"NotifyGameStart", Delegate<void(NotifyObject*)>(this, &UILongTermAttendGiftDialog::SendEventRewardMode27));
}

// @0x140c6b450
UILongTermAttendGiftDialog::~UILongTermAttendGiftDialog()
{
}

// @0x140c6b4a0
CString UILongTermAttendGiftDialog::GetTypeName()
{
    return "LongTermAttendGiftDialog";
}

// @0x140c6b4f0
int UILongTermAttendGiftDialog::vfunc_65()
{
    if (!UIDialog::vfunc_65())
        return 0;
    return 1;
}

// @0x140c6b520
void UILongTermAttendGiftDialog::vfunc_67()
{
    UIDialog::vfunc_67();
    m_178 = 0;
}

// @0x140c6b560
void UILongTermAttendGiftDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    if (!FUN_140c6cbf0())
        vfunc_67();
    else
        FUN_140c6c8e0();
}

// @0x140c6b5b0
int UILongTermAttendGiftDialog::vfunc_13()
{
    return UIDialog::vfunc_13();
}

// @0x140c6b5d0
// MS2-FUNCTIONAL: behaviour-equivalent; codegen (temporaries / branch layout) not byte-identical to the exe
void UILongTermAttendGiftDialog::vfunc_45(Scaleform::GFx::Value* result, const CString& method, ASData* args)
{
    UIObject::vfunc_45(result, method, args);
    if (FUN_140184310(method, "getTooltipItem")) {
        int id = args->FUN_1422b8b10();
        int rank = args->FUN_1422b8b10();
        void* owner = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (owner) {
            MS2Ptr<CItem> item(new CItem);
            if (item == 0)
                return;
            if (item->FUN_14052b130(id, rank, 0)) {
                FUN_14052b420(item.operator->(), 0);
                ASTooltip tooltip(owner, 0x20, 2);
                if (tooltip.FUN_1409e0d40(item))
                    *result = tooltip.FUN_1422bb870();
            }
        }
    } else if (FUN_140184310(method, "getTooltip")) {
        CString name = args->FUN_1422b8d30();
        if (FUN_140184310(name, "m_infoIcon")) {
            CStringW text = FUN_14028b8e0(L"s_longtermattendgift_dialog_desc");
            ASTooltip tooltip(1, 2);
            tooltip.FUN_1409c6dc0(1);
            if (tooltip.FUN_1409e26b0(text))
                *result = tooltip.FUN_1422bb870();
        }
    }
}

// @0x140c6b8b0
// MS2-FUNCTIONAL: behaviour-equivalent; codegen (temporaries / branch layout) not byte-identical to the exe
int UILongTermAttendGiftDialog::vfunc_28(const char* method, const Scaleform::GFx::Value* args, unsigned int count)
{
    if (UIDialog::vfunc_28(method, args, count))
        return 1;
    if (!_stricmp(method, "onClickAttendance")) {
        FUN_140c6cd00();
        return 1;
    }
    if (!_stricmp(method, "onClickReward")) {
        ASData data;
        if (data.FUN_1422b9620(args, count)) {
            SendEventRewardMode25(data.FUN_1422b8a10());
            return 1;
        }
    }
    return 0;
}

// @0x140c6b9d0
// MS2-FUNCTIONAL: behaviour-equivalent; codegen (temporaries / branch layout) not byte-identical to the exe
void UILongTermAttendGiftDialog::FUN_140c6b9d0()
{
    if (!m_30.IsNull() && FUN_140c6cbf0())
        FUN_140c6c4a0();
}

// @0x140c6ba20
void UILongTermAttendGiftDialog::SendEventRewardMode27(NotifyObject*)
{
    if (!FUN_140c6cbf0())
        return;
    if (FUN_141bcb0a0(FUN_1403ed2d0()))
        return;
    if (vfunc_55())
        FUN_141924680();
    COutPacket packet(0x97, 0);
    packet.Encode1(0x1b);
    FUN_140710590(packet);
}

// @0x140c6bac0
// MS2-FUNCTIONAL: behaviour-equivalent; codegen (temporaries / branch layout) not byte-identical to the exe
void UILongTermAttendGiftDialog::FUN_140c6bac0(int nType, CInPacket&)
{
    if (vfunc_55()) {
        FUN_141924680();
        return;
    }
    if (!FUN_140c6cbf0()) {
        vfunc_67();
    } else if (nType == 0x19) {
        FUN_140c6c4a0();
    } else if (nType == 0x1a) {
        FUN_140c6c920();
        FUN_140c6c4a0();
        FUN_140c6bdb0();
    } else if (nType == 0x1b) {
        FUN_140c6bdb0();
    }
}

// @0x140c6bb80
// MS2-FUNCTIONAL: behaviour-equivalent; codegen (temporaries / branch layout) not byte-identical to the exe
bool UILongTermAttendGiftDialog::SendEventRewardMode26(int nResult, const CMsgBoxData&)
{
    if (nResult == 0) {
        Unk_LtaWallet* wallet = FUN_140d86260();
        if (!wallet->vfunc_40(m_178->m_meratCost)) {
            FUN_140d74390(FUN_14028b8e0(CStringW(L"s_err_lack_merat_ask")), 1, Delegate<bool(int, const CMsgBoxData&)>(this, &UILongTermAttendGiftDialog::FUN_140c6bd40));
        } else {
            COutPacket packet(0x97, 0);
            packet.Encode1(0x1a);
            packet.Encode1(1);
            FUN_140710590(packet);
        }
    }
    return true;
}

// @0x140c6bd40
bool UILongTermAttendGiftDialog::FUN_140c6bd40(int nResult, const CMsgBoxData&)
{
    if (nResult == 0) {
        if (!FUN_140166410()->FUN_14036d570(0xc2)) {
            FUN_140d73cd0();
            return true;
        }
        FUN_140d86260()->vfunc_45();
        return true;
    }
    return true;
}

// @0x140c6bdb0
void UILongTermAttendGiftDialog::FUN_140c6bdb0()
{
    if (m_30.IsNull())
        return;
    int nAttendPoint = FUN_140c6d520();
    unsigned int nPossible = FUN_140c6d570();
    int nCatchUp = FUN_140c6d130();
    CStringW strPoint = FUN_140938ae0(CStringW(L"s_longtermattendgift_dialog_point"), nAttendPoint);
    CStringW strDays = FUN_140938ae0(CStringW(L"s_longtermattendgift_dialog_point"), nCatchUp);
    ASObj info(2);
    info.FUN_1407cbb20("title", FUN_1408f71a0(m_178->m_title, FUN_14083bab0(m_178->m_start, L"."), FUN_14083bab0(m_178->m_end, L".")));
    info.FUN_1407cbb20("curAttendancePoint", strPoint);
    info.FUN_1407cbb20("possibleAttendanceDays", strDays);
    info.FUN_1407cbbe0("enableAttendance", nPossible < m_178->m_days);
    info.FUN_1407cbb20("frame", m_178->m_frame);
    m_30->Invoke("setData", info.FUN_1422bb870());
}

// @0x140c6c250
// MS2-FUNCTIONAL: behaviour-equivalent; codegen (temporaries / branch layout) not byte-identical to the exe
void UILongTermAttendGiftDialog::FUN_140c6c250()
{
    if (m_30.IsNull())
        return;
    unsigned int nCur = FUN_140c6d570();
    int nCatchUp = FUN_140c6d130();
    ASDataProvider days(2);
    unsigned int nDays = m_178->m_days;
    for (unsigned __int64 i = 1; i <= nDays; ++i) {
        ASObj row(2);
        row.FUN_1407cba60("frame", FUN_140c6d470());
        row.FUN_1407cba60("state", FUN_140c6d200((unsigned int)i, nCur, nCatchUp));
        days.FUN_1422bc050(row.FUN_1422bb870());
    }
    m_30->Invoke("setAttendance", days.FUN_1422bb870());
}

// @0x140c6c4a0
// MS2-FUNCTIONAL: behaviour-equivalent; codegen (temporaries / branch layout) not byte-identical to the exe
void UILongTermAttendGiftDialog::FUN_140c6c4a0()
{
    if (m_30.IsNull())
        return;
    MS2Ptr<Unk_LtaList> list = FUN_140c02900(CString("m_reward"));
    if (list.get() != 0) {
        list->FUN_1422dd1d0();
        CString strFrame = FUN_140c6d470();
        for (size_t i = 0; i < m_178->m_rewards.FUN_140412e80(); ++i) {
            MS2Ptr<Unk_LtaRecord> rec = m_178->m_rewards.FUN_140410eb0(i);
            ASObj row(2);
            row.FUN_1407cb9c0("count", rec->m_day);
            row.FUN_1407cba60("frame", FUN_140c6d470());
            row.FUN_1407cb9c0("state", FUN_140c6d040(rec->m_day));
            row.FUN_1409c0d20("slotID01", rec->m_20.m_itemId);
            row.FUN_1409c0d20("slotID02", rec->m_50.m_itemId);
            ItemAble* reward1 = &rec->m_20;
            row.FUN_1409adc90("slotRank01", reward1->vfunc_o18_1());
            ItemAble* reward2 = &rec->m_50;
            row.FUN_1409adc90("slotRank02", reward2->vfunc_o18_1());
            row.FUN_1409c0d20("slotID02", rec->m_50.m_itemId);
            row.FUN_1407cba60("slotIcon01", FUN_140c6d390(rec->m_20.m_itemId));
            row.FUN_1407cba60("slotIcon02", FUN_140c6d390(rec->m_50.m_itemId));
            row.FUN_1409c0d20("slotItemCount01", rec->m_20.m_count);
            row.FUN_1409c0d20("slotItemCount02", rec->m_50.m_count);
            list->FUN_1422dd230(row);
        }
        list->vfunc_24(true);
    }
}

// @0x140c6c8e0
void UILongTermAttendGiftDialog::FUN_140c6c8e0()
{
    FUN_140c6bdb0();
    FUN_140c6c250();
    FUN_140c6c4a0();
}

// @0x140c6c920
void UILongTermAttendGiftDialog::FUN_140c6c920()
{
    int nAttendPoint = FUN_140c6d520();
    int nCur = FUN_140c6d570();
    int nCatchUp = FUN_140c6d130();
    CStringW strPoint = FUN_140938ae0(CStringW(L"s_longtermattendgift_dialog_point"), nAttendPoint);
    CStringW strDays = FUN_140938ae0(CStringW(L"s_longtermattendgift_dialog_point"), nCatchUp);
    ASObj info(2);
    info.FUN_1407cba60("frame", FUN_140c6d470());
    info.FUN_1407cba60("state", FUN_140c6d200(nCur, nCur, nCatchUp));
    m_30->Invoke("updateAttendance", CStringW(strPoint), CStringW(strDays), nCur - 1, info.FUN_1422bb870());
}

// @0x140c6cbf0
bool UILongTermAttendGiftDialog::FUN_140c6cbf0()
{
    m_178 = FUN_1401c0d90()->FUN_14047ce70();
    return m_178.get() != 0;
}

// @0x140c6cc80
// MS2-FUNCTIONAL: behaviour-equivalent; codegen (temporaries / branch layout) not byte-identical to the exe
void UILongTermAttendGiftDialog::SendEventRewardMode25(int nDay)
{
    if (FUN_140c6d040(nDay) == 1) {
        COutPacket packet(0x97, 0);
        packet.Encode1(0x19);
        packet.Encode4(nDay);
        FUN_140710590(packet);
    }
}

// @0x140c6cd00
// MS2-FUNCTIONAL: behaviour-equivalent; codegen (temporaries / branch layout) not byte-identical to the exe
void UILongTermAttendGiftDialog::FUN_140c6cd00()
{
    int nAttendPoint = FUN_140c6d520();
    int nCatchUp = FUN_140c6d130();
    if (nAttendPoint == 0) {
        if (nCatchUp == 0) {
            FUN_140d73aa0(FUN_14028b8e0(CStringW(L"s_longtermattendgift_dialog_err_msg_empty_point")), 0, 0, CStringW(L""));
        } else {
            CStringW strMsg = FUN_140938ae0(CStringW(L"s_longtermattendgift_dialog_use_merat"), m_178->m_meratCost);
            FUN_140d74390(strMsg, 1, Delegate<bool(int, const CMsgBoxData&)>(this, &UILongTermAttendGiftDialog::SendEventRewardMode26));
        }
    } else if (nCatchUp == 0) {
        FUN_140d73aa0(FUN_14028b8e0(CStringW(L"s_longtermattendgift_dialog_err_msg_attendance_full")), 0, 0, CStringW(L""));
    } else {
        COutPacket packet(0x97, 0);
        packet.Encode1(0x1a);
        packet.Encode1(0);
        FUN_140710590(packet);
    }
}

// @0x140c6d040
int UILongTermAttendGiftDialog::FUN_140c6d040(unsigned int nDay)
{
    unsigned int nCur = FUN_140c6d570();
    CStringW strDays = FUN_140c6d5c0();
    ATL::CAtlArray<int> claimed;
    FUN_1401d9a30(strDays, claimed, L",");
    if (FUN_1402bacf0(claimed, nDay) != -1)
        return 2;
    if (nDay <= nCur)
    {
        return 1;
    }
    return 0;
}

// @0x140c6d130
// MS2-FUNCTIONAL: behaviour-equivalent; codegen (temporaries / branch layout) not byte-identical to the exe
int UILongTermAttendGiftDialog::FUN_140c6d130()
{
    unsigned int nCur = FUN_140c6d570();
    int nDays = FUN_14086bd40(CMsTime(m_178->m_start), CMsTime(FUN_140869440())) + 1;
    int nMax = 0x50;
    const unsigned int* p = (const unsigned int*)FUN_1402fbd20(&nMax, &nDays);
    if (nCur < *p)
        return *p - nCur;
    return 0;
}

// @0x140c6d200
CString UILongTermAttendGiftDialog::FUN_140c6d200(unsigned int nDay, unsigned int nCur, int nCatchUp)
{
    CString strState;
    if (nDay <= nCur) {
        strState = "complete";
    } else {
        if (nDay <= nCur + nCatchUp)
            strState = "release";
        else
            strState = "disable";
    }
    bool bReward = false;
    for (size_t i = 0; i < m_178->m_rewards.FUN_140412e80(); ++i) {
        MS2Ptr<Unk_LtaRecord> rec = m_178->m_rewards.FUN_140410eb0(i);
        if (!((unsigned int)rec->m_day != nDay)) {
            bReward = true;
            break;
        }
    }
    if (bReward)
        strState += "_reward";
    return strState;
}

// @0x140c6d390
CString UILongTermAttendGiftDialog::FUN_140c6d390(int nItemId)
{
    if (!nItemId)
        return "";
    MS2Ptr<Unk_LtaItem> item = FUN_14053f870(nItemId);
    if (item.IsNull())
        return "";
    return item->FUN_14053fdd0();
}

// @0x140c6d470
CString UILongTermAttendGiftDialog::FUN_140c6d470()
{
    if (m_178 == 0)
        return "";
    return FUN_14016a600(m_178->m_frame, 0);
}

// @0x140c6d520
int UILongTermAttendGiftDialog::FUN_140c6d520()
{
    int nDefault = 0;
    return g_ltaTable.FUN_140c6d8d0(0xa8d, m_178->m_id, nDefault);
}

// @0x140c6d570
int UILongTermAttendGiftDialog::FUN_140c6d570()
{
    int nDefault = 0;
    return g_ltaTable.FUN_140c6d8d0(0xa8e, m_178->m_id, nDefault);
}

// @0x140c6d5c0
// MS2-FUNCTIONAL: behaviour-equivalent; codegen (temporaries / branch layout) not byte-identical to the exe
CStringW UILongTermAttendGiftDialog::FUN_140c6d5c0()
{
    return g_ltaTable.FUN_140c6d980(0xa8c, m_178->m_id, CStringW((const wchar_t*)0));
}

MS2_REPLACE_METHOD(0x140C6B4A0, UILongTermAttendGiftDialog, GetTypeName, 61, 0xE157B792);
MS2_REPLACE_METHOD(0x140C6B4F0, UILongTermAttendGiftDialog, vfunc_65, 37, 0x0FF8B225);
MS2_REPLACE_METHOD(0x140C6B520, UILongTermAttendGiftDialog, vfunc_67, 45, 0xA4E5533B);
MS2_REPLACE_METHOD(0x140C6B560, UILongTermAttendGiftDialog, OnLoadComplete, 72, 0xA71A4DA1);
MS2_REPLACE_METHOD(0x140C6B5B0, UILongTermAttendGiftDialog, vfunc_13, 24, 0x8FA096B5);
MS2_REPLACE_METHOD(0x140C6B5D0, UILongTermAttendGiftDialog, vfunc_45, 730, 0xB19047B7);
MS2_REPLACE_METHOD(0x140C6B8B0, UILongTermAttendGiftDialog, vfunc_28, 274, 0x0945BA3B);
MS2_REPLACE_METHOD(0x140C6B9D0, UILongTermAttendGiftDialog, FUN_140c6b9d0, 69, 0xFBAD2347);
MS2_REPLACE_METHOD(0x140C6BA20, UILongTermAttendGiftDialog, SendEventRewardMode27, 154, 0xBA109B7F);
MS2_REPLACE_METHOD(0x140C6BAC0, UILongTermAttendGiftDialog, FUN_140c6bac0, 181, 0x81188338);
MS2_REPLACE_METHOD(0x140C6BB80, UILongTermAttendGiftDialog, SendEventRewardMode26, 438, 0x8E7D2C3E);
MS2_REPLACE_METHOD(0x140C6BD40, UILongTermAttendGiftDialog, FUN_140c6bd40, 99, 0x5A2F6464);
MS2_REPLACE_METHOD(0x140C6BDB0, UILongTermAttendGiftDialog, FUN_140c6bdb0, 1177, 0x034D4258);
MS2_REPLACE_METHOD(0x140C6C250, UILongTermAttendGiftDialog, FUN_140c6c250, 572, 0xF5C9411B);
MS2_REPLACE_METHOD(0x140C6C4A0, UILongTermAttendGiftDialog, FUN_140c6c4a0, 1073, 0x584D47AA);
MS2_REPLACE_METHOD(0x140C6C8E0, UILongTermAttendGiftDialog, FUN_140c6c8e0, 44, 0x62139651);
MS2_REPLACE_METHOD(0x140C6C920, UILongTermAttendGiftDialog, FUN_140c6c920, 714, 0x788EDB50);
MS2_REPLACE_METHOD(0x140C6CBF0, UILongTermAttendGiftDialog, FUN_140c6cbf0, 138, 0xF668AB87);
MS2_REPLACE_METHOD(0x140C6CC80, UILongTermAttendGiftDialog, SendEventRewardMode25, 114, 0x30A3C2F8);
MS2_REPLACE_METHOD(0x140C6CD00, UILongTermAttendGiftDialog, FUN_140c6cd00, 820, 0xFB296AB6);
MS2_REPLACE_METHOD(0x140C6D040, UILongTermAttendGiftDialog, FUN_140c6d040, 226, 0x5844E738);
MS2_REPLACE_METHOD(0x140C6D130, UILongTermAttendGiftDialog, FUN_140c6d130, 202, 0xB29E3DE9);
MS2_REPLACE_METHOD(0x140C6D200, UILongTermAttendGiftDialog, FUN_140c6d200, 385, 0x4B262771);
MS2_REPLACE_METHOD(0x140C6D390, UILongTermAttendGiftDialog, FUN_140c6d390, 211, 0xBB8C36B1);
MS2_REPLACE_METHOD(0x140C6D470, UILongTermAttendGiftDialog, FUN_140c6d470, 155, 0x943C6B11);
MS2_REPLACE_METHOD(0x140C6D520, UILongTermAttendGiftDialog, FUN_140c6d520, 67, 0xCDC430FA);
MS2_REPLACE_METHOD(0x140C6D570, UILongTermAttendGiftDialog, FUN_140c6d570, 67, 0xD9995042);
MS2_REPLACE_METHOD(0x140C6D5C0, UILongTermAttendGiftDialog, FUN_140c6d5c0, 133, 0xD53BE508);
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca33e0-0x142ca3540 .text$yd
