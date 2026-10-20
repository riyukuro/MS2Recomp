// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Item enchant window ("ItemEnchantDialog", ophelia / peachy exp mode),
// its base UIItemModifyDialogBase and the UIItemEventDispatcher singleton that fans the item events out to the listeners.
// MS2-UNIT: client\ms2\uiitemenchantdialog.cpp
// MS2-RANGE: 0x1419be700-0x1419ccd00 .text$mn
// MS2-RANGE: 0x140115690-0x1401158f0 .text$di
// MS2-RANGE: 0x142cbeec0-0x142cbeff0 .text$yd
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$?0VUIItemEnchantDialog@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@QEAA@AEBQEAVUIItemEnchantDialog@@AEBQ81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@Z 0x1419c96e0 ; unique
// MS2-PIN: ??$?8PEAVUIItemEnchantDialog@@P80@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@YA_NAEBU?$pair@PEAVUIItemEnchantDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@0@0@Z 0x1419c9910 ; prop
// MS2-PIN: ??$?8PEAVUIItemEnchantDialog@@P80@EAAXPEAVNotifyObject@@@Z@std@@YA_NAEBU?$pair@PEAVUIItemEnchantDialog@@P81@EAAXPEAVNotifyObject@@@Z@0@0@Z 0x1419c9980 ; prop
// MS2-PIN: ??$?8PEAVUIItemEnchantDialog@@P80@EAA_NHAEBVCMsgBoxData@@@Z@std@@YA_NAEBU?$pair@PEAVUIItemEnchantDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@0@0@Z 0x1419c99f0 ; prop
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVUIItemEnchantDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@QEAA@AEBV01@@Z 0x1419ca480 ; unique
// MS2-PIN: ?AssignRaw@?$MS2Ptr@VCEnchantOption@@@@QEAAAEAV1@PEAVCEnchantOption@@@Z 0x1419ca670 ; unique
// MS2-PIN: ??8?$Unk_EnchantPtr@VCItemEnchantInfo@@@@QEBA_NPEAVCItemEnchantInfo@@@Z 0x1419ca6e0 ; unique
// MS2-PIN: ??_EUIItemEnchantDialog@@WBJA@EAAPEAXI@Z 0x1419ca730 ; unique
// MS2-PIN: ??_EUIItemEnchantDialog@@WBJI@EAAPEAXI@Z 0x1419ca73c ; unique
// MS2-PIN: ??_G?$DelegateImpl@U?$pair@PEAVUIItemEnchantDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEAAPEAXI@Z 0x1419ca750 ; prop
// MS2-PIN: ??_G?$DelegateImpl@U?$pair@PEAVUIItemEnchantDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEAAPEAXI@Z 0x1419ca7d0 ; prop
// MS2-PIN: ??_GUIItemEnchantDialog@@UEAAPEAXI@Z 0x1419ca810 ; unique
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVUIItemEnchantDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x1419ca860 ; unique
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVUIItemEnchantDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x1419ca8c0 ; unique
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVUIItemEnchantDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x1419ca920 ; unique
// MS2-PIN: ?vfunc_2@?$DelegateImpl@U?$pair@PEAVUIItemEnchantDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z 0x1419ca980 ; unique
// MS2-PIN: ?vfunc_2@?$DelegateImpl@U?$pair@PEAVUIItemEnchantDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEAAXPEAVNotifyObject@@@Z 0x1419ca9b0 ; unique
// MS2-PIN: ?Invoke@?$DelegateImpl@U?$pair@PEAVUIItemEnchantDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEAA_NHAEBVCMsgBoxData@@@Z 0x1419ca9e0 ; unique
// MS2-PIN: ??$Call@VUIItemEnchantDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@?$DelegateImpl@U?$pair@PEAVUIItemEnchantDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@CAXAEAU?$pair@PEAVUIItemEnchantDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@AEBUParams@FunctionHandler@GFx@Scaleform@@@Z 0x1419caa20 ; prop
// MS2-PIN: ??$Call@VUIItemEnchantDialog@@P81@EAAXPEAVNotifyObject@@@Z@?$DelegateImpl@U?$pair@PEAVUIItemEnchantDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@CAXAEAU?$pair@PEAVUIItemEnchantDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@PEAVNotifyObject@@@Z 0x1419caa60 ; prop
// MS2-PIN: ??$Call@VUIItemEnchantDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@?$DelegateImpl@U?$pair@PEAVUIItemEnchantDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@CA_NAEAU?$pair@PEAVUIItemEnchantDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@HAEBVCMsgBoxData@@@Z 0x1419caaa0 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVUIItemEnchantDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x1419caae0 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVUIItemEnchantDialog@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x1419cab40 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVUIItemEnchantDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x1419caba0 ; unique
// MS2-PIN: ??C?$MS2Ptr@VCEnchantOption@@@@QEBAPEAVCEnchantOption@@XZ 0x1419ca720
// MS2-PIN: memmove_s 0x1419cac00
// MS2-PINS-END tplpin
//
// Status: see progress/status.tsv. Callees that are not recovered yet are declared below ("unit-local
// placeholders") or in src/ms2/placeholder/; their names are Ghidra's (FUN_<va>) unless evident.
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiitemenchantdialog.cpp"
#include "ms2/placeholder/ms2stdafx.h"

#include "uiitemenchantdialog.h"
#include "ms2/placeholder/header_statics_a.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/notifyobject.h"
#include "ms2/placeholder/mypc.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/cccreateitempacket.h"
#include "ms2/guess/usercommandcli.h"

#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- the unit's header statics ----
static UICommon::CMyPCKeyInputController s_keyInput;
static CString s_failEffect("Enchant_FailEffect");
static CString s_itemChoice("Enchant_ItemChoice");
static CString s_progress("Enchant_Progress");
static CString s_successEffect("Enchant_SuccessEffect");

// ---- unit-local placeholders (unrecovered singletons / helpers) ----
using ATL::CAtlArray;

// The localized-string formatter FUN_14028dfa0(key, args...) with its own MakeValue copies.
CStringW FUN_14028dfa0(const CStringW&, const fmt::ArgList&);
namespace fmt { namespace internal {
struct Unk_WcFormatter { typedef wchar_t Char; };
struct Unk_WcArgType {
    ULongLong type;
    Unk_WcArgType() : type(0) {}
    template <typename T> Unk_WcArgType(const T& arg) : type(MakeValue<Unk_WcFormatter>::type(arg)) {}
};
template <typename T> inline ULongLong wc_make_type(const T& arg) { return MakeValue<Unk_WcFormatter>::type(arg); }
inline ULongLong wc_make_type(Unk_WcArgType t0 = Unk_WcArgType(), Unk_WcArgType t1 = Unk_WcArgType(), Unk_WcArgType t2 = Unk_WcArgType(),
                              Unk_WcArgType t3 = Unk_WcArgType(), Unk_WcArgType t4 = Unk_WcArgType(), Unk_WcArgType t5 = Unk_WcArgType(),
                              Unk_WcArgType t6 = Unk_WcArgType(), Unk_WcArgType t7 = Unk_WcArgType(), Unk_WcArgType t8 = Unk_WcArgType(),
                              Unk_WcArgType t9 = Unk_WcArgType(), Unk_WcArgType t10 = Unk_WcArgType(), Unk_WcArgType t11 = Unk_WcArgType(),
                              Unk_WcArgType t12 = Unk_WcArgType(), Unk_WcArgType t13 = Unk_WcArgType(), Unk_WcArgType t14 = Unk_WcArgType()) {
    return t0.type | (t1.type << 4) | (t2.type << 8) | (t3.type << 12) | (t4.type << 16) | (t5.type << 20) |
           (t6.type << 24) | (t7.type << 28) | (t8.type << 32) | (t9.type << 36) | (t10.type << 40) |
           (t11.type << 44) | (t12.type << 48) | (t13.type << 52) | (t14.type << 56);
}
} }
#define WC_REF(n) fmt::internal::MakeValue<fmt::internal::Unk_WcFormatter>(v##n)
#define WC_WRAP(n) \
    template <FMT_GEN(n, FMT_MAKE_TEMPLATE_ARG)> \
    inline CStringW FUN_14028dfa0(CStringW arg1, FMT_GEN(n, FMT_MAKE_ARG)) { \
        const fmt::internal::ArgArray<n>::Type array = {FMT_GEN(n, WC_REF)}; \
        return FUN_14028dfa0(arg1, fmt::ArgList(fmt::internal::wc_make_type(FMT_GEN(n, FMT_MAKE_REF2)), array)); \
    }
WC_WRAP(1)
WC_WRAP(2)
WC_WRAP(3)

// The inventory (global 0x143ab2a90).
class Unk_Inventory
{
public:
    MS2Ptr<CItem> FUN_140a5d680(__int64 uid);
    void FUN_140a5d530(CItem* item);
    int FUN_140a5f780(int itemId, int a);
    void FUN_140a60880(int tab, CAtlArray<MS2Ptr<CItem> >& out);
};
extern Unk_Inventory DAT_143ab2a90;
extern int DAT_143ab2914;

// Backup (equipped) item record.
class Unk_BackUpItem : public CPtred
{
public:
    void FUN_1411dd6d0(CItem* item);
    void FUN_1411dd280();
    MS2Ptr<CItem> FUN_1411dc7a0();
};
class Unk_PCItems
{
public:
    MS2Ptr<Unk_BackUpItem> FUN_1411e1580(unsigned __int64 uid);
};
Unk_PCItems* FUN_1416561a0(MyPC* pc);
void FUN_1411e1ce0(Unk_PCItems* items, ATL::CAtlList<MS2Ptr<Unk_BackUpItem> >* out, int a);
float FUN_1411e1110(Unk_PCItems* items, int id);

class Unk_EnPC : public MyPC
{
public:
    MS2Ptr<Unk_BackUpItem> FUN_141655c30(unsigned __int64 uid);
    int FUN_14166c930();
    int FUN_14166ccb0();
    int FUN_141662eb0(CItem* item);
};
__int64 FUN_141656a80(PCBase* pc);
void FUN_1417fca60(int a, int b);

class Unk_CinWorld
{
public:
    MyPC* FUN_141bd0cc0();
};
Unk_CinWorld* FUN_1403ed2d0();
void* FUN_1403ed2b0();
void FUN_141adc190(void*);

// AS script views.
class Unk_EnButton : public ASDisplayObject
{
public:
    void FUN_1422ce240(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb, size_t n);
};
class Unk_EnBag : public ASObj
{
};
class ASDialog : public ASDisplayObject
{
};
class Unk_EnScript : public AScript
{
public:
    Scaleform::GFx::Value FUN_1419ca1f0(const char* name, int a, bool b);                   // "initData"
    Scaleform::GFx::Value FUN_1419ca130(const char* name, const AScript& obj, bool b);      // "onModifiedExp"
    void FUN_1422bac00(const char* name, CString& out);                                    // string member by name
};
class Unk_EnArray : public ASArray
{
public:
    void FUN_1422bbf00(const ASObj& obj);                   // push an object
    void FUN_1422bbfe0(const wchar_t* text);                // push a string
};

// Inventory window / item slots.
class Unk_EnInvDialog
{
public:
    int FUN_141b1d3d0();
    int FUN_141b1d460();
    void FUN_141b1be50();
    void FUN_141b1ac40(CAtlArray<MS2Ptr<CItem> >& items, const CStringW& title, int a, int b, __int64 c);
};
Unk_EnInvDialog* FUN_140a7b2b0(int id);
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

// Client config (global singleton).
class Unk_1402056b0 { public: int* FUN_1402056b0(); void* m_unknown; };
class Unk_EnCfgInt { public: unsigned* FUN_1401d7c10(); void* m_unknown; };
struct Unk_ClientConfig
{
    char m_pad_0[0x69a0];
    Unk_1402056b0 m_69a0;
    char m_pad_69b0[0x9828 - 0x69b0];
    Unk_EnCfgInt m_9828;
    char m_pad_9838[0x99e0 - 0x9838];
    Unk_EnCfgInt m_99e0;
};
Unk_ClientConfig* FUN_1401d3200();
class Unk_GEManagerA;
Unk_GEManagerA* FUN_1401c0d90();
int FUN_14047e370(Unk_GEManagerA* mgr, int level);
int FUN_140478b60(Unk_GEManagerA* mgr);

// Ingredient / string tables.
class Unk_IngTable { public: CStringW FUN_140556a40(int rank); };   // member: this=rcx, hidden return=rdx
Unk_IngTable* FUN_140281980();
unsigned FUN_1405569f0(Unk_IngTable* t, int rank);
CStringW FUN_14183e930(CStringW text, unsigned color);
CStringW FUN_14183e9c0(CStringW text, int rank);
class Unk_ItemStr { public: CStringW FUN_141813150(int); CStringW FUN_141811980(int, int); };
Unk_ItemStr* FUN_1401a9d70();
CStringW FUN_141902320(int a, int b);
CStringW FUN_1419021b0(int a, int b);
CStringW FUN_141b71910(__int64 v);
int FUN_14053feb0(int id);
float FUN_14028aed0(float v);
bool FUN_14028d470(float a, float b);
__int64 FUN_140632990(__int64 v, float f);
CStringW FUN_14082f090(unsigned key);
CStringW FUN_14052bd00(int id, const CStringW& arg);
CStringW FUN_1409404f0(__int64 v);
CStringW FUN_140938ae0(CStringW key, const int& v);
CStringW FUN_140298ea0(CStringW key);
CStringW FUN_1409eaa20(CStringW key, const CStringW& a, const CStringW& b, const CStringW& c);
CStringW FUN_14062b4f0(CStringW key, const int* v);
CStringW FUN_1405c2690(CStringW key, const CStringW& arg);
CStringW FUN_140bfa7f0(CStringW key, CStringW name, const int& v);
CStringW FUN_14028b8e0(const CStringW& key);
CStringW FUN_14028de60(int id);
bool FUN_1403b3c40(const CStringW& s, const wchar_t* w);
bool FUN_140e45240(const CStringW& s, const char* c);
unsigned __int64 FUN_140718350(const CString& s);

// Misc singletons.
class Unk_Feature { public: unsigned char FUN_14036d570(int id); };
Unk_Feature* FUN_140166410();
class Unk_Flags { public: void* m_0; unsigned char FUN_14116d720(); };
Unk_Flags* FUN_14025e7c0();
unsigned char FUN_14116d720(Unk_Flags* f);
class Unk_ItemRules { public: int FUN_14058df90(CItem* item); int FUN_14058e230(CItem* item); };
Unk_ItemRules* FUN_1409eece0();
class Unk_UIHolder { public: int FUN_141b213c0(); int FUN_141b212f0(); void FUN_141b1feb0(); };
Unk_UIHolder* FUN_140967100();
class Unk_Sound { public: void FUN_140a1f970(CString a, CString b); };
Unk_Sound* FUN_140d8ee90();
void FUN_141276180(const CString& a, const CString& b);
void FUN_14151f460(int v);
int FUN_141902660(MS2Ptr<CItem> item);
unsigned FUN_141924630();
MS2Ptr<CItemData> FUN_14053f870(int id);
class Unk_DTNotices { public: void FUN_140da4e40(CStringW name, Delegate<void(NotifyObject*)> cb); void FUN_140da4eb0(CStringW name, Delegate<void(NotifyObject*)> cb); };
Unk_DTNotices* FUN_140939a10();

// Scroll table.
class Unk_EnScroll : public CPtred { public: int FUN_14034d370(); char m_pad[0x1c - 0x18]; int m_1c; };
class Unk_EnScrollRef
{
public:
    ~Unk_EnScrollRef();
    Unk_EnScroll* operator->() const { return m_p; }
    Unk_EnScroll* get() const { return m_p; }
    Unk_EnScroll* m_p;
};
class Unk_PreloadServiceC { public: Unk_EnScrollRef FUN_14034e360(unsigned id); };
Unk_PreloadServiceC* FUN_14034f780();

// Item sub-objects returned by the CItem accessors.
class Unk_ItemEnchantData
{
public:
    int FUN_14062ffb0(unsigned key, int a, int b);
    float FUN_1406303e0(unsigned key);
    CItemEnchantInfo* FUN_140630d60();
};
class Unk_EnOwner { public: __int64 FUN_14052d1c0(); };
class Unk_ItemOwnerRef { public: Unk_EnOwner* FUN_140635160(); };

// The enchant result option container (RTTI CEnchantOption : CPtred, 0x68).
class CEnchantOption : public CPtred
{
public:
    CEnchantOption();
    void FUN_14058d5c0(CInPacket& pkt);
    char m_pad_18[0x20 - 0x18];
    ATL::CAtlMap<Unk_PacketOptionB, Unk_PayloadPtr<BaseOption> > m_options;     // +0x20
    char m_pad_48[0x68 - 0x48];
};

#include "ms2/placeholder/notifygameeventchanged.h"

// The message box record (MS2Ptr<CMsgBoxData> members are bound to the exe copies in symbols.tsv).
class CMsgBoxData : public CPtred
{
public:
    CStringW FUN_141a02d50() const;
    __int64 FUN_141a02f10(int a, __int64 b) const;
    int FUN_141a02e50(int a, int b) const;
    void FUN_141a01800(int n);
    void FUN_141a020b0(int itemId, int rank, int count);
    void FUN_141a024e0(CStringW text, bool b);
    void FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)> cb);
    template <class T> void Append(T v);
};
extern template class MS2Ptr<CMsgBoxData>;
MS2Ptr<CMsgBoxData> FUN_140d73d20(int nType, CStringW strText, void* p, CStringW strTag);
void FUN_140d73c60(MS2Ptr<CMsgBoxData> box);
void FUN_141a024a0(CMsgBoxData* box, int v);

// Packet send.
template <> void CMsgBoxData::Append<int>(int);
template <> void CMsgBoxData::Append<__int64>(__int64);

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

void FUN_1422bccb0(Scaleform::GFx::Value* pValue, int n);
void FUN_1422bcce0(Scaleform::GFx::Value* pValue, bool b);
void FUN_1422bce40(Scaleform::GFx::Value* pValue, const AScript& obj);


// The exe keeps these MS2Ptr instances in other units.
extern template class MS2Ptr<CItem>;
extern template class MS2Ptr<CItemData>;
extern template class MS2Ptr<CMsgBoxData>;
extern template class MS2Ptr<ASMovieClip>;
extern template class MS2Ptr<Unk_BackUpItem>;

static inline CItemData* ItemData(CItem* item)
{
    return reinterpret_cast<CItemData*>(item->FUN_140527840());
}
// @0x1419be700
MS2Ptr<CItem> FUN_1419be700(unsigned __int64 uid)
{
    MS2Ptr<CItem> item = DAT_143ab2a90.FUN_140a5d680(uid);
    if (item.get() == 0) {
        Unk_EnPC* pc = static_cast<Unk_EnPC*>(FUN_1403ed2d0()->FUN_141bd0cc0());
        if (pc == 0)
            return 0;
        MS2Ptr<Unk_BackUpItem> equip = pc->FUN_141655c30(uid);
        if (equip.get() == 0)
            return 0;
        return equip->FUN_1411dc7a0();
    }
    return item;
}

// @0x1419be860
UIItemModifyDialogBase::UIItemModifyDialogBase()
    : m_mode(0), m_enchantAni(0)
{
    m_2c = 0x1b;
}

// @0x1419be8e0
void UIItemModifyDialogBase::vfunc_43()
{
    ASDialog* dialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (dialog != 0) {
        Unk_EnInvDialog* inv = FUN_140a7b2b0(0x4e40);
        if (inv != 0) {
            int x = inv->FUN_141b1d3d0();
            int y = inv->FUN_141b1d460();
            if (x != -1 && y - 0x50 != -1) {
                dialog->vfunc_2(5, y - 0x50, x - dialog->FUN_1422c13b0());
                return;
            }
        }
    }
    dialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (dialog != 0)
        dialog->vfunc_2(1, 0, 0);
}

// @0x1419bea10
void UIItemModifyDialogBase::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    vfunc_84();
    m_enchantAni = FUN_140ba7930("m_enchantAni");
    if (m_enchantAni == 0) {
        vfunc_67();
    } else {
        unsigned char bDebug = FUN_14116d720(FUN_14025e7c0());
        MS2Ptr<Unk_EnButton> forceEnchant = m_enchantAni->FUN_140acce30<Unk_EnButton>("m_forceEnchant");
        if (forceEnchant.get() != 0)
            forceEnchant->vfunc_3(bDebug);
        MS2Ptr<Unk_EnButton> compareEnchant = m_enchantAni->FUN_140acce30<Unk_EnButton>("m_compareEnchant");
        if (compareEnchant.get() != 0)
            compareEnchant->vfunc_3(0);
        MS2Ptr<ASMovieClip> debugCount = m_enchantAni->FUN_1409b4560("m_debugEnchantCount");
        if (debugCount.get() != 0)
            debugCount->vfunc_3(0);
        FUN_141adc190(FUN_1403ed2b0());
    }
}

// @0x1419bed80
int UIItemModifyDialogBase::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    return UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0;
}

// @0x1419bedd0
void UIItemModifyDialogBase::vfunc_67()
{
    UIDialog::vfunc_67();
    m_enchantAni = 0;
}

// @0x1419bee10
void UIItemModifyDialogBase::vfunc_84()
{
    unsigned char bFlag = FUN_140166410()->FUN_14036d570(0x86);
    ((Unk_EnScript*)(AScript*)m_30)->FUN_1419ca1f0("initData", m_mode, bFlag);
}

// @0x1419bee80
void UIItemModifyDialogBase::vfunc_85(int nType)
{
    COutPacket pkt(0x22, 0);
    pkt.Encode1(4);
    pkt.Encode2((short)nType);
    FUN_140710590(pkt);
}

// @0x1419beef0
bool UIItemModifyDialogBase::FUN_1419beef0(unsigned __int64 uid)
{
    MS2Ptr<CItem> item = DAT_143ab2a90.FUN_140a5d680(uid);
    if (item.get() != 0)
        return true;
    return false;
}

// @0x1419bef70
MS2Ptr<CItem> UIItemModifyDialogBase::FUN_1419bef70(unsigned __int64 uid)
{
    return FUN_1419be700(uid);
}

// @0x1419befc0
UIItemEnchantDialog::UIItemEnchantDialog()
{
    m_mode = 1;
    m_expMode = 1;
    FUN_1419c6420();
}

// @0x1419bf160
UIItemEnchantDialog::~UIItemEnchantDialog()
{
}

// @0x1419bf2c0
CString UIItemEnchantDialog::vfunc_1()
{
    return CString("ItemEnchantDialog");
}

// @0x1419bf310
void UIItemEnchantDialog::OnLoadInit()
{
    UIObject::OnLoadInit();
    FUN_1419c6420();
    if (m_expMode == 1)
        FUN_140d8ee90()->FUN_140a1f970(CString("dialog_open"), CString("enchant_ophelia"));
    else if (m_expMode == 2)
        FUN_140d8ee90()->FUN_140a1f970(CString("dialog_open"), CString("enchant_peachy"));
}

// @0x1419bf410
void UIItemEnchantDialog::OnLoadComplete()
{
    UIItemModifyDialogBase::OnLoadComplete();
    COutPacket pkt(0x5e, 0);
    pkt.Encode1(0);
    FUN_140710590(pkt);
    FUN_1419bfd70();
    FUN_140a6a840()->FUN_1419cae20(static_cast<UIItemEventListener*>(this));
    FUN_140939a10()->FUN_140da4e40(CStringW(L"NotifyGameEventChanged"),
        Delegate<void(NotifyObject*)>(this, &UIItemEnchantDialog::FUN_1419c6380));
    m_state = 0;
}

// @0x1419bf590
void UIItemEnchantDialog::vfunc_67()
{
    UIItemModifyDialogBase::vfunc_67();
    if (m_expMode == 1)
        FUN_140d8ee90()->FUN_140a1f970(CString("dialog_close"), CString("enchant_ophelia"));
    else if (m_expMode == 2)
        FUN_140d8ee90()->FUN_140a1f970(CString("dialog_close"), CString("enchant_peachy"));
    FUN_14151f460(1);
    FUN_141414e50(vfunc_1());
    FUN_141414e50(Unk_SocketFormat("{0}.equip", vfunc_1()));
    FUN_1419c77a0();
    FUN_1419c4050();
    FUN_1419c6420();
    m_debugBtnFillIngredientUnit = 0;
    m_debugBtnFillIngredient = 0;
    m_debugBtnFillFailStack = 0;
    m_debugBtnUseAllFailStack = 0;
    FUN_140a6a840()->FUN_1419caeb0(static_cast<UIItemEventListener*>(this));
    FUN_140939a10()->FUN_140da4eb0(CStringW(L"NotifyGameEventChanged"),
        Delegate<void(NotifyObject*)>(this, &UIItemEnchantDialog::FUN_1419c6380));
}

// @0x1419bf910
int UIItemEnchantDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIItemModifyDialogBase::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (_stricmp(szMethod, "onSelectItem") == 0) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
            FUN_1419c0d40(&data);
        return 1;
    }
    if (_stricmp(szMethod, "onEnchant") == 0) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
            FUN_1419c0440(&data);
        return 1;
    }
    if (_stricmp(szMethod, "onRetry") == 0) {
        FUN_1419c11e0();
        return 1;
    }
    if (_stricmp(szMethod, "onComplete") == 0) {
        FUN_1419c10e0();
        return 1;
    }
    if (_stricmp(szMethod, "onForceEnchant") == 0) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
            FUN_1419c0360(&data);
        return 1;
    }
    if (_stricmp(szMethod, "onSelectEquipIngredient") == 0) {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
            FUN_1419c1220(&data);
        return 1;
    }
    if (_stricmp(szMethod, "onClickFailStackUp") == 0)
        FUN_1419c15c0();
    else if (_stricmp(szMethod, "onClickFailStackDown") == 0)
        FUN_1419c1630();
    return 0;
}

// @0x1419bfc20
void UIItemEnchantDialog::vfunc_43()
{
    UIItemModifyDialogBase::vfunc_43();
}

// @0x1419bfc40
int UIItemEnchantDialog::vfunc_13()
{
    return 0;
}

// @0x1419bfc50
int UIItemEnchantDialog::OnMessage(UISwfEntity* pSender, UIMsg* pMsg)
{
    return UIDialog::OnMessage(pSender, pMsg) != 0;
}

// @0x1419bfca0
void UIItemEnchantDialog::vfunc_85(int nType)
{
    if (FUN_140967100()->FUN_141b213c0() == 0) {
        UIItemModifyDialogBase::vfunc_85(nType);
    } else {
        int id = FUN_140967100()->FUN_141b212f0();
        COutPacket pkt(0x22, 0);
        pkt.Encode1(6);
        pkt.Encode4(id);
        pkt.Encode4(*FUN_1401d3200()->m_69a0.FUN_1402056b0());
        pkt.Encode2((short)nType);
        FUN_140710590(pkt);
    }
}

// @0x1419bfd70
void UIItemEnchantDialog::FUN_1419bfd70()
{
    if (!(m_enchantAni == 0)) {
        ATL::CAtlArray<unsigned __int64> uids;
        FUN_1419c1a40(uids);
        FUN_141414e50(vfunc_1());
        FUN_141414d60(vfunc_1(), uids);
        MS2Ptr<Unk_EnBag> bag = m_enchantAni->FUN_140accef0<Unk_EnBag>("m_itemBag");
        if (bag.get() != 0)
            bag->FUN_1407cba60("bagId", vfunc_1());
    }
}

// @0x1419bff60
void UIItemEnchantDialog::FUN_1419bff60()
{
    MyPC* pc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pc == 0)
        return;
    CString bagName = Unk_SocketFormat("{0}.equip", vfunc_1());
    FUN_141414e50(bagName);
    if (m_result.vfunc_o18_0() == 0)
        return;
    MS2Ptr<CItem> item = FUN_1419bef70(m_selectedUid);
    if (!item)
        return;
    ATL::CAtlArray<unsigned __int64> uids;
    ATL::CAtlArray<MS2Ptr<CItem> > items;
    DAT_143ab2a90.FUN_140a60880(0, items);
    DAT_143ab2a90.FUN_140a60880(3, items);
    for (size_t i = 0; i < items.GetCount(); ++i) {
        MS2Ptr<CItem> cand = items[i];
        if (FUN_1419c9260(item.get(), cand.get()) != 0)
            uids.Add(cand->FUN_140526a50());
    }
    FUN_141414d60(bagName, uids);
    MS2Ptr<Unk_EnBag> bag = m_enchantAni->FUN_140accef0<Unk_EnBag>("m_ingredientBag");
    if (bag.get() != 0)
        bag->FUN_1407cba60("bagId", CString(bagName));
}

// @0x1419c02e0
void UIItemEnchantDialog::FUN_1419c02e0(CString name)
{
    if (name == "expMode") {
        m_expMode = 2;
        m_mode = 4;
    } else {
        m_expMode = 1;
        m_mode = 3;
    }
}

// @0x1419c0360
void UIItemEnchantDialog::FUN_1419c0360(ASData*)
{
    if (0x31 < DAT_143ab2914) {
        COutPacket pkt(0x5e, 0);
        pkt.Encode1(0xf);
        FUN_140710590(pkt);
    }
}

// @0x1419c03d0
void UIItemEnchantDialog::FUN_1419c03d0(ASData*)
{
    if (0x31 < DAT_143ab2914) {
        COutPacket pkt(0x5e, 0);
        pkt.Encode1(0x13);
        FUN_140710590(pkt);
    }
}

// @0x1419c0440
void UIItemEnchantDialog::FUN_1419c0440(ASData* pData)
{
    MyPC* pc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pc == 0)
        return;
    unsigned __int64 uid = FUN_140718350(pData->FUN_1422b8d30());
    MS2Ptr<CItem> item = FUN_1419bef70(uid);
    if (!item)
        return;
    if (FUN_141902660(item) != 0)
        return;
    if (m_expMode == 2) {
        if (!FUN_140166410()->FUN_14036d570(0x87) || FUN_1419c89b0(uid) == 0 || FUN_1419c8b80(uid) != 0) {
            FUN_1419c0c70(uid);
        } else {
            CStringW charName = pc->vfunc_77();
            CStringW text = FUN_1405c2690(CStringW(L"s_itemenchant_binding_character"), charName);
            MS2Ptr<CMsgBoxData> box = FUN_140d73d20(1, CStringW(text), 0, CStringW(L""));
            if (box.get() != 0) {
                box->Append<__int64>(uid);
                FUN_141a024a0(box.operator->(), 0);
                box->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &UIItemEnchantDialog::FUN_1419c5d90));
                FUN_140d73c60(box);
            }
        }
    } else {
        if (FUN_14028d470(m_230, 0)) {
            FUN_1419c7a30(uid, 0);
            m_state = 0;
        } else {
            MS2Ptr<CItem> ingredient = DAT_143ab2a90.FUN_140a5d680(m_220);
            if (ingredient.get() == 0) {
                FUN_1419c4360(uid);
            } else {
                int a = (int)m_230;
                int b = 100 - (int)m_23c;
                int c = (int)m_23c;
                int d = item->FUN_140526fc0() + 1;
                CStringW text = StringFormat((LPCWSTR)FUN_14028de60(0x95f), d, c, b, a);
                MS2Ptr<CMsgBoxData> box = FUN_140d73d20(0x1a, CStringW(text), 0, CStringW(L""));
                if (box.get() != 0) {
                    int rank = ingredient->FUN_140526bd0();
                    int itemId = ingredient->FUN_1405276c0();
                    box->FUN_141a020b0(itemId, rank, 1);
                    box->FUN_141a01800(1);
                    box->FUN_141a024e0(FUN_14028de60(0x961), 0);
                    box->Append<__int64>(uid);
                    FUN_141a024a0(box.operator->(), 0);
                    box->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &UIItemEnchantDialog::FUN_1419c5890));
                    FUN_140d73c60(box);
                }
            }
        }
        FUN_1419c19d0();
    }
}

// @0x1419c0c70
void UIItemEnchantDialog::FUN_1419c0c70(unsigned __int64 uid)
{
    MS2Ptr<CItem> item = FUN_1419bef70(uid);
    if (item == 0)
        return;
    COutPacket pkt(0x5e, 0);
    pkt.Encode1(6);
    pkt.Encode8(uid);
    FUN_140710590(pkt);
    vfunc_85(2);
}

// @0x1419c0d40
void UIItemEnchantDialog::FUN_1419c0d40(ASData* pData)
{
    unsigned __int64 uid = FUN_140718350(pData->FUN_1422b8d30());
    unsigned int flag = pData->FUN_1422b8a90();
    MS2Ptr<CItem> item = FUN_1419bef70(uid);
    if (item == 0)
        return;
    if (FUN_141902660(item) != 0)
        return;
    Unk_EnchantPtr<CItemEnchantInfo> info(item->FUN_1405278a0()->FUN_140630d60());
    if (info == 0)
        return;
    int lock = item->FUN_140527030();
    if (FUN_1409eece0()->FUN_14058df90(item.get()) == 0 || lock != 0) {
        if (m_enchantAni == 0)
            return;
        FUN_1419c77a0();
        m_enchantAni->Invoke("initEnchantSlot");
    } else {
        COutPacket pkt(0x5e, 0);
        pkt.Encode1(1);
        pkt.Encode1((unsigned char)m_expMode);
        pkt.Encode8(item->FUN_140526a50());
        FUN_140710590(pkt);
    }
    COutPacket pkt(0x22, 0);
    if (FUN_140967100()->FUN_141b213c0() == 0) {
        pkt.Encode1(4);
        pkt.Encode2(1);
    } else {
        int id = FUN_140967100()->FUN_141b212f0();
        pkt.Encode1(6);
        pkt.Encode4(id);
        pkt.Encode4(*FUN_1401d3200()->m_69a0.FUN_1402056b0());
        pkt.Encode2(1);
    }
    pkt.Encode8(item->FUN_140526a50());
    FUN_140710590(pkt);
}

#ifndef MS2_HOOK_DLL
// @0x1419c10e0
void UIItemEnchantDialog::FUN_1419c10e0()
{
    FUN_1419c4050();
    FUN_1419bfd70();
    if (m_expMode == 1) {
        FUN_141276180(s_successEffect, CString(""));
        Unk_EnInvDialog* inv = FUN_140a7b2b0(0x4e40);
        if (inv != 0)
            inv->FUN_141b1be50();
    } else if (m_expMode == 2) {
        FUN_141276180(s_failEffect, CString(""));
    }
    FUN_1419c19d0();
}
#endif

// @0x1419c11e0
void UIItemEnchantDialog::FUN_1419c11e0()
{
    FUN_1419c77a0();
    vfunc_85(4);
}

// @0x1419c1220
void UIItemEnchantDialog::FUN_1419c1220(ASData* pData)
{
    if (FUN_1419c1d60() == 0)
        return;
    unsigned __int64 uid = FUN_140718350(pData->FUN_1422b8d30());
    unsigned char flag = pData->FUN_1422b8a90();
    CItem* held = FUN_1419bef70(m_selectedUid).get();
    CItem* picked = FUN_1419bef70(uid).get();
    if (held != 0 && picked != 0) {
        if (flag == 0 || FUN_1419c9490(held, picked) == 0) {
            FUN_1419c16c0(uid, flag);
        } else {
            CStringW key(L"s_itemenchant_over_enchanted_item");
            MS2Ptr<CMsgBoxData> box = FUN_140d73d20(1, FUN_14028b8e0(key), 0, CStringW(L""));
            if (box.get() != 0) {
                box->Append<__int64>(uid);
                FUN_141a024a0(box.operator->(), 0);
                box->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &UIItemEnchantDialog::FUN_1419c5f00));
                FUN_140d73c60(box);
            }
        }
    }
}

// @0x1419c15c0
void UIItemEnchantDialog::FUN_1419c15c0()
{
    COutPacket pkt(0x5e, 0);
    pkt.Encode1(3);
    pkt.Encode4(m_failStack + 1);
    FUN_140710590(pkt);
}

// @0x1419c1630
void UIItemEnchantDialog::FUN_1419c1630()
{
    COutPacket pkt(0x5e, 0);
    pkt.Encode1(3);
    pkt.Encode4(m_failStack - 1);
    FUN_140710590(pkt);
}

// @0x1419c16a0
unsigned __int64 UIItemEnchantDialog::FUN_1419c16a0()
{
    return m_selectedUid;
}

// @0x1419c16c0
void UIItemEnchantDialog::FUN_1419c16c0(unsigned __int64 uid, int flag)
{
    MS2Ptr<CItem> item = DAT_143ab2a90.FUN_140a5d680(uid);
    if (!item)
        return;
    if (flag != 0 && item->FUN_140526fc0() > 0) {
        CStringW key(L"s_itemenchant_enchanted_item");
        MS2Ptr<CMsgBoxData> box = FUN_140d73d20(1, FUN_14028b8e0(key), 0, CStringW(L""));
        if (box.get() != 0) {
            box->Append<__int64>(uid);
            FUN_141a024a0(box.operator->(), 0);
            box->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &UIItemEnchantDialog::FUN_1419c5de0));
            FUN_140d73c60(box);
            return;
        }
    }
    COutPacket pkt(0x5e, 0);
    pkt.Encode1(2);
    pkt.Encode8(uid);
    pkt.Encode1((unsigned char)flag);
    FUN_140710590(pkt);
}

// @0x1419c19d0
void UIItemEnchantDialog::FUN_1419c19d0()
{
    MyPC* pc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pc != 0) {
        if (static_cast<Unk_EnPC*>(pc)->FUN_14166c930() == 0x16)
            FUN_1417fca60(static_cast<Unk_EnPC*>(pc)->FUN_14166ccb0(), m_state);
    }
}

// @0x1419c1a40
void UIItemEnchantDialog::FUN_1419c1a40(ATL::CAtlArray<unsigned __int64>& out)
{
    MyPC* pc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pc == 0)
        return;
    ATL::CAtlArray<MS2Ptr<CItem> > items;
    DAT_143ab2a90.FUN_140a60880(0, items);
    for (size_t i = 0; i < items.GetCount(); ++i) {
        if (items[i]->FUN_140525c60() == 0 && items[i]->FUN_140527270() < 1) {
            if (FUN_1409eece0()->FUN_14058e230(items[i].get()) != 0)
                out.Add(items[i]->FUN_140526a50());
        }
    }
    ATL::CAtlList<MS2Ptr<Unk_BackUpItem> > list(10);
    FUN_1411e1ce0(FUN_1416561a0(pc), &list, 0);
    POSITION pos = list.GetHeadPosition();
    while (pos != 0) {
        MS2Ptr<Unk_BackUpItem> equip = list.GetAt(pos);
        if (equip.get() != 0) {
            MS2Ptr<CItem> item = equip->FUN_1411dc7a0();
            if (!(!item)) {
                if (item->FUN_140525c60() == 0 && item->FUN_140527270() < 1) {
                    if (FUN_1409eece0()->FUN_14058e230(item.get()) != 0)
                        out.Add(item->FUN_140526a50());
                }
            }
        }
        list.GetNext(pos);
    }
}

// @0x1419c1d60
int UIItemEnchantDialog::FUN_1419c1d60()
{
    switch (m_expMode) {
    case 1:
        if (m_mode != 3)
            return 0;
        break;
    case 2:
        if (m_mode != 4)
            return 0;
        break;
    default:
        return 0;
    }
    if (m_result.vfunc_o18_0() == 0)
        return 0;
    return 1;
}

// @0x1419c1e00
unsigned UIItemEnchantDialog::FUN_1419c1e00()
{
    if (m_expMode == 1) {
        if (m_mode == 3)
            return m_2b8;
        return 0;
    }
    return 0;
}

// @0x1419c1e40
CString UIItemEnchantDialog::FUN_1419c1e40()
{
    switch (m_expMode) {
    case 1: {
        const char* name = FUN_1419c1e00() == 0 ? "Enchant" : "EnchantFailStack";
        return CString(name);
    }
    case 2:
        return CString("EnchantExpGauge");
    default:
        return CString("Enchant");
    }
}

// @0x1419c1f20
void UIItemEnchantDialog::FUN_1419c1f20(CInPacket& pkt)
{
    FUN_1419c77a0();
    FUN_1419c6420();
    if (m_enchantAni == 0)
        return;
    MyPC* pc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pc == 0)
        return;
    if (m_expMode != pkt.vfunc_o8_2()) {
        vfunc_67();
        FUN_140967100()->FUN_141b1feb0();
        return;
    }
    m_selectedUid = pkt.vfunc_o8_4();
    m_ingredients.FUN_14026c0b0(pkt);
    m_2b0 = pkt.vfunc_o8_2();
    m_option.AssignRaw(new CEnchantOption);
    m_option->FUN_14058d5c0(pkt);
    if (m_expMode == 1) {
        m_228 = pkt.vfunc_o8_5();
        m_22c = pkt.vfunc_o8_5();
        m_230 = pkt.vfunc_o8_5();
        m_234 = pkt.vfunc_o8_5();
        m_238 = pkt.vfunc_o8_5();
        __int64 id0 = pkt.vfunc_o8_4();
        __int64 id1 = pkt.vfunc_o8_4();
        m_2b8 = pkt.vfunc_o8_1();
        m_result.m_itemId = pkt.vfunc_o8_3();
        m_result.FUN_14026b1c0(pkt.vfunc_o8_2());
        m_result.m_count = pkt.vfunc_o8_3();
        MS2Ptr<CItem> first = DAT_143ab2a90.FUN_140a5d680(id0);
        if (first.get() != 0) {
            m_208 = first->FUN_1405276c0();
            m_210 = id0;
        }
        MS2Ptr<CItem> second = DAT_143ab2a90.FUN_140a5d680(id1);
        if (second.get() != 0) {
            m_218 = second->FUN_1405276c0();
            m_220 = id1;
        }
        m_2b4 = (float)FUN_140478b60(FUN_1401c0d90()) / 10000.0f;
        m_2b4 = m_2b4 + FUN_1411e1110(FUN_1416561a0(pc), 0x41);
    } else if (m_expMode == 2) {
        m_228 = 100.0f;
        m_23c = 100.0f;
        m_result.m_itemId = pkt.vfunc_o8_3();
        m_result.FUN_14026b1c0(pkt.vfunc_o8_2());
        m_result.m_count = pkt.vfunc_o8_3();
        m_2b4 = (float)FUN_140478b60(FUN_1401c0d90()) / 10000.0f;
        m_2b4 = m_2b4 + FUN_1411e1110(FUN_1416561a0(pc), 0x41);
    }
    FUN_1419c81a0();
    FUN_1419bff60();
    FUN_141276180(s_itemChoice, CString(""));
    MS2Ptr<ASMovieClip> list = m_enchantAni->FUN_1409b4560("enchantListSelected");
    if (list) {
        bool bDebug = FUN_14116d720(FUN_14025e7c0()) != 0;
        m_debugBtnFillIngredientUnit = list->FUN_140acce30<Unk_EnButton>("m_debugBtnFillIngredientUnit");
        if (m_debugBtnFillIngredientUnit) {
            m_debugBtnFillIngredientUnit->vfunc_3(bDebug);
            if (bDebug)
                m_debugBtnFillIngredientUnit->FUN_1422ce240(
                    Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &UIItemEnchantDialog::FUN_1419c6270), 0);
        }
        m_debugBtnFillIngredient = list->FUN_140acce30<Unk_EnButton>("m_debugBtnFillIngredient");
        if (m_debugBtnFillIngredient) {
            m_debugBtnFillIngredient->vfunc_3(bDebug);
            if (bDebug)
                m_debugBtnFillIngredient->FUN_1422ce240(
                    Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &UIItemEnchantDialog::FUN_1419c6160), 0);
        }
        m_debugBtnFillFailStack = list->FUN_140acce30<Unk_EnButton>("m_debugBtnFillFailStack");
        if (m_debugBtnFillFailStack) {
            m_debugBtnFillFailStack->vfunc_3(bDebug);
            if (bDebug)
                m_debugBtnFillFailStack->FUN_1422ce240(
                    Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &UIItemEnchantDialog::FUN_1419c5f60), 0);
        }
        m_debugBtnUseAllFailStack = list->FUN_140acce30<Unk_EnButton>("m_debugBtnUseAllFailStack");
        if (m_debugBtnUseAllFailStack) {
            m_debugBtnUseAllFailStack->vfunc_3(bDebug);
            if (bDebug)
                m_debugBtnUseAllFailStack->FUN_1422ce240(
                    Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &UIItemEnchantDialog::FUN_1419c6060), 0);
        }
    }
}
// @0x1419c2e30
void UIItemEnchantDialog::FUN_1419c2e30(CItem* item, int prevLevel, CInPacket& pkt)
{
    if ((m_item == 0) || (m_enchantAni == 0))
        return;
    int a = pkt.vfunc_o8_3();
    int b = pkt.vfunc_o8_3();
    __int64 c = pkt.vfunc_o8_4();
    int failType = pkt.vfunc_o8_3();
    ASObj obj(2);
    obj.FUN_1407cb9c0("success", 0);
    obj.FUN_1407cbb20("itemName", FUN_1419c7e20(item));
    obj.FUN_1407cbbe0("diff", prevLevel != m_item->FUN_140526fc0());
    obj.FUN_1407cbb20("prevLevel", FUN_1419c7ec0(prevLevel, item->FUN_140526bd0()));
    obj.FUN_1407cbb20("curLevel", FUN_1419c7ec0(m_item->FUN_140526fc0(), item->FUN_140526bd0()));
    obj.FUN_1407cba60("binding", FUN_1419c78a0(m_item.get(), Unk_SocketFormat("{0}.resultItem", vfunc_1()), m_bag0));
    obj.FUN_1407cbb20("failDesc", FUN_1419c7f50(m_item.get(), failType));
    obj.FUN_1407cbbe0("protect", !((m_208 == 0) && (m_218 == 0)));
    m_enchantAni->Invoke("setEnchantResult", obj);
    FUN_141276180(s_progress, CString(""));
    FUN_1419c90b0(a, b, c);
    m_state = 2;
}

// @0x1419c3390
void UIItemEnchantDialog::FUN_1419c3390(CItem* item, CEnchantOption* stat, int prevLevel)
{
    if ((m_item == 0) || (m_enchantAni == 0))
        return;
    ASObj obj(2);
    obj.FUN_1407cb9c0("success", 1);
    obj.FUN_1407cbb20("itemName", FUN_1419c7e20(item));
    obj.FUN_1407cbbe0("diff", prevLevel != m_item->FUN_140526fc0());
    obj.FUN_1407cbb20("prevLevel", FUN_1419c7ec0(prevLevel, item->FUN_140526bd0()));
    obj.FUN_1407cbb20("curLevel", FUN_1419c7ec0(m_item->FUN_140526fc0(), item->FUN_140526bd0()));
    obj.FUN_1407cbb20("enchantStat", FUN_1419c65b0(MS2Ptr<CItem>(item), stat));
    obj.FUN_1407cba60("binding", FUN_1419c78a0(m_item.get(), Unk_SocketFormat("{0}.resultItem", vfunc_1()), m_bag0));
    m_enchantAni->Invoke("setEnchantResult", obj);
    FUN_141276180(s_progress, CString(""));
    m_state = 1;
}

// @0x1419c37f0
void UIItemEnchantDialog::FUN_1419c37f0(unsigned __int64 uid, Unk_EnSlotArgs* slot)
{
    if (FUN_141924630() == 0) {
        MS2Ptr<CItem> item = FUN_1419bef70(uid);
        if (item.get() != 0)
            item->FUN_140524eb0(*reinterpret_cast<CInputStream*>(&slot->m_8));
    } else {
        MS2Ptr<CItem> item = FUN_1419bef70(uid);
        if (item.get() != 0) {
            m_item = item->FUN_140524250();
            m_item->FUN_140524eb0(*reinterpret_cast<CInputStream*>(&slot->m_8));
        }
    }
}

// @0x1419c3950
void UIItemEnchantDialog::FUN_1419c3950(CInPacket& pkt)
{
    unsigned __int64 uid = pkt.vfunc_o8_4();
    int level = pkt.vfunc_o8_3();
    MS2Ptr<CItem> item = FUN_1419be700(uid);
    if (!item)
        return;
    int oldLevel = item->FUN_1405270a0();
    item->FUN_140527110(level);
    if (m_enchantAni == 0)
        return;
    m_failStackUids.RemoveAll();
    m_2bc = 0;
    ASObj obj(2);
    FUN_1419c6cd0(obj, &m_ingredients);
    FUN_1419c74e0(obj, item.get());
    FUN_1419c7140(obj);
    ((Unk_EnScript*)(AScript*)m_enchantAni.operator->())->FUN_1419ca130("onModifiedExp", obj, oldLevel < level);
    FUN_1419bfd70();
    FUN_1419bff60();
}

// @0x1419c3b90
void UIItemEnchantDialog::FUN_1419c3b90(CInPacket& pkt)
{
    if (!m_enchantAni)
        return;
    MS2Ptr<CItem> item = FUN_1419bef70(m_selectedUid);
    if (!item)
        return;
    m_failStackUids.RemoveAll();
    m_failStack = pkt.vfunc_o8_3();
    m_2bc = pkt.vfunc_o8_3();
    int n = pkt.vfunc_o8_3();
    for (int i = 0; i < n; i++)
        m_failStackUids.Add(pkt.vfunc_o8_4());
    m_228 = pkt.vfunc_o8_5();
    m_22c = pkt.vfunc_o8_5();
    m_230 = pkt.vfunc_o8_5();
    m_234 = pkt.vfunc_o8_5();
    m_238 = pkt.vfunc_o8_5();
    FUN_1419c8070(item.get());
}

// @0x1419c3e70
void UIItemEnchantDialog::FUN_1419c3e70(CInPacket& pkt)
{
    if (!m_enchantAni)
        return;
    MS2Ptr<CItem> item = FUN_1419bef70(m_selectedUid);
    if (!item)
        return;
    m_failStackUids.RemoveAll();
    m_2bc = pkt.vfunc_o8_3();
    int n = pkt.vfunc_o8_3();
    for (int i = 0; i < n; i++)
        m_failStackUids.Add(pkt.vfunc_o8_4());
    FUN_1419c8070(item.get());
}

// @0x1419c3fd0
void UIItemEnchantDialog::FUN_1419c3fd0(void*, void*, void*)
{
    COutPacket pkt(0x5e, 0);
    pkt.Encode1(1);
    pkt.Encode1((unsigned char)m_expMode);
    pkt.Encode8(m_selectedUid);
    FUN_140710590(pkt);
}

// @0x1419c4050
void UIItemEnchantDialog::FUN_1419c4050()
{
    if (m_item.get() == 0)
        return;
    unsigned __int64 uid = m_item->FUN_140526a50();
    if (FUN_1419beef0(uid) == 0) {
        MyPC* pc = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pc != 0) {
            uid = m_item->FUN_140526a50();
            MS2Ptr<Unk_BackUpItem> backup = FUN_1416561a0(pc)->FUN_1411e1580(uid);
            if (backup.get() != 0) {
                backup->FUN_1411dd6d0(m_item.get());
                backup->FUN_1411dd280();
            }
        }
    } else {
        DAT_143ab2a90.FUN_140a5d530(m_item.get());
    }
    m_item = 0;
}

// @0x1419c41b0
void UIItemEnchantDialog::FUN_1419c41b0()
{
    if (!(m_enchantAni == 0) && (0x31 < DAT_143ab2914) && !(m_enchantAni == 0)) {
        unsigned __int64 n = m_bag1.GetCount();
        for (unsigned __int64 i = 0; i < n; i++) {
            Unk_EnSlot* slot = FUN_1419c8160(m_bag1[i]);
            if (slot != 0) {
                MS2Ptr<CItem> item = slot->vfunc_25();
                if (item == 0)
                    continue;
                int count = item->FUN_140526c50();
                if (count == 0)
                    continue;
                int v = DAT_143ab2a90.FUN_140a5f780(ItemData(item.operator->())->FUN_14053c6f0(), 0);
                slot->FUN_141416740(v, count);
            }
        }
        FUN_1419bff60();
    }
}

// @0x1419c4360
void UIItemEnchantDialog::FUN_1419c4360(unsigned __int64 uid)
{
    MS2Ptr<CItem> item = FUN_1419bef70(uid);
    if (item == 0)
        return;
    MS2Ptr<CItem> second = DAT_143ab2a90.FUN_140a5d680(m_210);
    if (second.get() == 0) {
        int v230 = (int)m_230;
        int v23c = (int)m_23c;
        int pct = 100 - (int)m_23c;
        int lvl = item->FUN_140526fc0() + 1;
        CStringW text = StringFormat((LPCWSTR)FUN_14028de60(0x95f), lvl, v23c, pct, v230);
        MS2Ptr<CMsgBoxData> box = FUN_140d73d20(1, text, 0, CStringW(L""));
        if (box.get() != 0) {
            box->Append<__int64>(uid);
            box->Append<int>(0);
            FUN_141a024a0(box.operator->(), 0);
            box->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &UIItemEnchantDialog::FUN_1419c5d20));
            FUN_140d73c60(box);
        }
    } else {
        int v230 = (int)m_230;
        int v23c = (int)m_23c;
        int pct = 100 - (int)m_23c;
        int lvl = item->FUN_140526fc0() + 1;
        CStringW text = StringFormat((LPCWSTR)FUN_14028de60(0x95f), lvl, v23c, pct, v230);
        MS2Ptr<CMsgBoxData> box = FUN_140d73d20(0x1a, text, 0, CStringW(L""));
        if (box.get() != 0) {
            int rank = second->FUN_140526bd0();
            int itemId = second->FUN_1405276c0();
            box->FUN_141a020b0(itemId, rank, 1);
            box->FUN_141a01800(1);
            box->FUN_141a024e0(FUN_14028de60(0x961), 0);
            box->Append<__int64>(uid);
            FUN_141a024a0(box.operator->(), 0);
            box->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &UIItemEnchantDialog::FUN_1419c4e00));
            FUN_140d73c60(box);
        }
    }
}

// @0x1419c4a50
bool UIItemEnchantDialog::FUN_1419c4a50(int result, const CMsgBoxData& box)
{
    if (result == 0) {
        __int64 uid = box.FUN_141a02f10(0, 0);
        MS2Ptr<CItem> prot = DAT_143ab2a90.FUN_140a5d680(m_210);
        if (!(!prot)) {
            MS2Ptr<CItemData> data(ItemData(prot));
            if (!(!data)) {
                int count = FUN_1419c8830(data->FUN_14053c510());
                CStringW fmt = FUN_1419c7e20(prot.get());
                CStringW text = FUN_140bfa7f0(CStringW(L"s_itemenchant_protector_use_warn"), fmt, count);
                MS2Ptr<CMsgBoxData> msg = FUN_140d73d20(1, text, 0, CStringW(L""));
                if (msg.get() != 0) {
                    msg->Append<__int64>(uid);
                    msg->Append<int>(1);
                    FUN_141a024a0(msg.operator->(), 0);
                    msg->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &UIItemEnchantDialog::FUN_1419c5d20));
                    FUN_140d73c60(msg);
                }
            }
        }
    }
    return true;
}

// @0x1419c4e00
bool UIItemEnchantDialog::FUN_1419c4e00(int result, const CMsgBoxData& box)
{
    if (result != 0)
        return true;
    __int64 uid = box.FUN_141a02f10(0, 0);
    CStringW answer = box.FUN_141a02d50();
    if (answer.Find(L"true", 0) == -1) {
        MS2Ptr<CMsgBoxData> msg = FUN_140d73d20(1, FUN_140298ea0(CStringW(L"s_itemenchant_protector_dont_use_warn")), 0, CStringW(L""));
        if (msg.get() != 0) {
            msg->Append<__int64>(uid);
            msg->Append<int>(0);
            FUN_141a024a0(msg.operator->(), 0);
            msg->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &UIItemEnchantDialog::FUN_1419c5d20));
            FUN_140d73c60(msg);
        }
        return true;
    }
    MS2Ptr<CItem> item = FUN_1419bef70(uid);
    MS2Ptr<CItemData> data = FUN_14053f870(m_208);
    if (item.get() == 0 || data.get() == 0)
        return true;
    MS2Ptr<CItem> prot = DAT_143ab2a90.FUN_140a5d680(m_210);
    if (!prot)
        return true;
    int rank = item->FUN_140526bd0();
    int need = FUN_1419c86b0(m_208);
    if (rank < need) {
        CStringW rankA = FUN_14183e930(FUN_1401a9d70()->FUN_141813150(rank), FUN_1405569f0(FUN_140281980(), rank));
        CStringW rankB = FUN_14183e930(FUN_1401a9d70()->FUN_141813150(need), FUN_1405569f0(FUN_140281980(), need));
        CStringW name = FUN_1419c7e20(prot.get());
        CStringW text = FUN_1409eaa20(CStringW(L"s_itemenchant_protector_rank_warn"), rankA, rankB, name);
        MS2Ptr<CMsgBoxData> msg = FUN_140d73d20(1, text, 0, CStringW(L""));
        if (msg.get() != 0) {
            msg->FUN_141a01800(1);
            msg->Append<__int64>(uid);
            FUN_141a024a0(msg.operator->(), 0);
            msg->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &UIItemEnchantDialog::FUN_1419c4a50));
            FUN_140d73c60(msg);
        }
    } else {
        int count = FUN_1419c8830(m_208);
        CStringW text = FUN_140bfa7f0(CStringW(L"s_itemenchant_protector_use_warn"), FUN_1419c7e20(prot.get()), count);
        MS2Ptr<CMsgBoxData> msg = FUN_140d73d20(1, text, 0, CStringW(L""));
        if (msg.get() != 0) {
            msg->Append<__int64>(uid);
            msg->Append<int>(1);
            FUN_141a024a0(msg.operator->(), 0);
            msg->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &UIItemEnchantDialog::FUN_1419c5d20));
            FUN_140d73c60(msg);
        }
    }
    return true;
}

// @0x1419c5890
bool UIItemEnchantDialog::FUN_1419c5890(int result, const CMsgBoxData& box)
{
    if (result != 0)
        return true;
    __int64 uid = box.FUN_141a02f10(0, 0);
    CStringW answer = box.FUN_141a02d50();
    MS2Ptr<CItem> item = FUN_1419bef70(uid);
    if (item == 0)
        return true;
    if (answer.Find(L"true", 0) == -1) {
        FUN_1419c4360(uid);
        return true;
    }
    MS2Ptr<CItemData> data = FUN_14053f870(m_218);
    if (data == 0)
        return true;
    MS2Ptr<CItem> sup = DAT_143ab2a90.FUN_140a5d680(m_220);
    if (sup == 0)
        return true;
    CStringW text = FUN_1405c2690(CStringW(L"s_itemenchant_super_protector_use_warn"), FUN_1419c7e20(sup.get()));
    MS2Ptr<CMsgBoxData> msg = FUN_140d73d20(1, text, 0, CStringW(L""));
    if (msg.get() != 0) {
        msg->Append<__int64>(uid);
        msg->Append<int>(2);
        FUN_141a024a0(msg.operator->(), 0);
        msg->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &UIItemEnchantDialog::FUN_1419c5d20));
        FUN_140d73c60(msg);
    }
    return true;
}

// @0x1419c5d20
bool UIItemEnchantDialog::FUN_1419c5d20(int result, const CMsgBoxData& box)
{
    if (result == 0) {
        __int64 uid = box.FUN_141a02f10(0, 0);
        int v = box.FUN_141a02e50(1, 0);
        FUN_1419c7a30(uid, v);
    }
    return true;
}

// @0x1419c5d90
bool UIItemEnchantDialog::FUN_1419c5d90(int result, const CMsgBoxData& box)
{
    if (result == 0) {
        __int64 uid = box.FUN_141a02f10(0, 0);
        FUN_1419c0c70(uid);
    }
    return true;
}

// @0x1419c5de0
bool UIItemEnchantDialog::FUN_1419c5de0(int result, const CMsgBoxData& box)
{
    if (result == 0) {
        __int64 uid = box.FUN_141a02f10(0, 0);
        COutPacket pkt(0x5e, 0);
        pkt.Encode1(2);
        pkt.Encode8(uid);
        pkt.Encode1(1);
        FUN_140710590(pkt);
    }
    return true;
}

// @0x1419c5e90
bool UIItemEnchantDialog::FUN_1419c5e90(int result, const CMsgBoxData& box)
{
    if (result == 0) {
        __int64 uid = box.FUN_141a02f10(0, 0);
        int v = box.FUN_141a02e50(1, 0);
        FUN_1419c7ce0(uid, v);
    }
    return true;
}

// @0x1419c5f00
bool UIItemEnchantDialog::FUN_1419c5f00(int result, const CMsgBoxData& box)
{
    if (result == 0) {
        __int64 uid = box.FUN_141a02f10(0, 0);
        FUN_1419c16c0(uid, 1);
    }
    return true;
}

// @0x1419c5f60
void UIItemEnchantDialog::FUN_1419c5f60(const Scaleform::GFx::FunctionHandler::Params&)
{
    if (!(m_enchantAni == 0) && (0x31 < DAT_143ab2914)) {
        CString guid;
        ((Unk_EnScript*)(AScript*)m_enchantAni.operator->())->FUN_1422bac00("m_lastGUID", guid);
        unsigned __int64 uid = FUN_140718350(guid);
        if (uid != 0) {
            COutPacket pkt(0x5e, 0);
            pkt.Encode1(0x11);
            pkt.Encode8(uid);
            FUN_140710590(pkt);
        }
    }
}

// @0x1419c6060
void UIItemEnchantDialog::FUN_1419c6060(const Scaleform::GFx::FunctionHandler::Params&)
{
    if (!(m_enchantAni == 0) && (0x31 < DAT_143ab2914)) {
        CString guid;
        ((Unk_EnScript*)(AScript*)m_enchantAni.operator->())->FUN_1422bac00("m_lastGUID", guid);
        unsigned __int64 uid = FUN_140718350(guid);
        if (uid != 0) {
            COutPacket pkt(0x5e, 0);
            pkt.Encode1(0x12);
            pkt.Encode8(uid);
            FUN_140710590(pkt);
        }
    }
}

// @0x1419c6160
void UIItemEnchantDialog::FUN_1419c6160(const Scaleform::GFx::FunctionHandler::Params&)
{
    if (!(m_enchantAni == 0) && (0x31 < DAT_143ab2914)) {
        CString guid;
        ((Unk_EnScript*)(AScript*)m_enchantAni.operator->())->FUN_1422bac00("m_lastGUID", guid);
        unsigned __int64 uid = FUN_140718350(guid);
        if (uid != 0) {
            COutPacket pkt(0x5e, 0);
            pkt.Encode1(0x10);
            pkt.Encode8(uid);
            pkt.Encode4(0);
            FUN_140710590(pkt);
        }
    }
}

// @0x1419c6270
void UIItemEnchantDialog::FUN_1419c6270(const Scaleform::GFx::FunctionHandler::Params&)
{
    if (!(m_enchantAni == 0) && (0x31 < DAT_143ab2914)) {
        CString guid;
        ((Unk_EnScript*)(AScript*)m_enchantAni.operator->())->FUN_1422bac00("m_lastGUID", guid);
        unsigned __int64 uid = FUN_140718350(guid);
        if (uid != 0) {
            COutPacket pkt(0x5e, 0);
            pkt.Encode1(0x10);
            pkt.Encode8(uid);
            pkt.Encode4(10);
            FUN_140710590(pkt);
        }
    }
}

// @0x1419c6380
void UIItemEnchantDialog::FUN_1419c6380(NotifyObject* pNotify)
{
    NotifyGameEventChanged* ev = dynamic_cast<NotifyGameEventChanged*>(pNotify);
    if ((ev != 0) && (FUN_140e45240(ev->m_eventName, "EnchantRate") == 0) && ((ev->m_type == 0) || (ev->m_type == 1))) {
        FUN_1419c81a0();
        FUN_14151f460(1);
    }
}

// @0x1419c6420
void UIItemEnchantDialog::FUN_1419c6420()
{
    m_selectedUid = 0;
    m_state = 0;
    m_item = 0;
    m_option = 0;
    m_23c = 0;
    m_228 = 0;
    m_22c = 0;
    m_230 = 0;
    m_234 = 0;
    m_238 = 0;
    m_208 = 0;
    m_210 = 0;
    m_218 = 0;
    m_220 = 0;
    m_2b0 = 0;
    m_2b4 = 0;
    m_2b8 = 0;
    m_failStack = 0;
    m_result.m_itemId = 0;
    m_result.FUN_14026b1c0(0);
    m_result.m_count = 0;
    m_2bc = 0;
    m_failStackUids.RemoveAll();
}

// @0x1419c65b0
CStringW UIItemEnchantDialog::FUN_1419c65b0(MS2Ptr<CItem> item, CEnchantOption* pOption)
{
    CStringW out;
    POSITION pos = pOption->m_options.GetStartPosition();
    while (pos != 0) {
        unsigned int key = pOption->m_options.GetKeyAt(pos);
        Unk_PayloadPtr<BaseOption> opt = pOption->m_options.GetValueAt(pos);
        if (!(!opt)) {
            if (opt->FUN_140266ce0()) {
                __int64 base = item->FUN_1405278a0()->FUN_14062ffb0(key, 0, 0);
                float extra = item->FUN_1405278a0()->FUN_1406303e0(key);
                float rate = opt->FUN_140266e10();
                __int64 value = FUN_140632990(base, extra + rate);
                out += StringFormat((LPCWSTR)FUN_14082f090(key), value);
                out += L",";
            }
        }
        pOption->m_options.GetNext(pos);
    }
    out.TrimRight(L",");
    return out;
}

// @0x1419c6840
void UIItemEnchantDialog::FUN_1419c6840(MS2Ptr<CItem> item, CEnchantOption* pOption, ASObj& dest)
{
    ASArray list(2);
    POSITION pos = pOption->m_options.GetStartPosition();
    while (pos != 0) {
        unsigned int key = pOption->m_options.GetKeyAt(pos);
        Unk_PayloadPtr<BaseOption> opt = pOption->m_options.GetValueAt(pos);
        if (!(!opt)) {
            if (opt->FUN_140266ce0()) {
                ASObj obj(2);
                __int64 base = item->FUN_1405278a0()->FUN_14062ffb0(key, 0, 0);
                float extra = item->FUN_1405278a0()->FUN_1406303e0(key);
                float rate = opt->FUN_140266e10();
                __int64 before = FUN_140632990(base, extra);
                __int64 after = FUN_140632990(base, extra + rate);
                obj.FUN_1407cbb20("statName", StringFormat((LPCWSTR)FUN_14082f090(key), before));
                obj.FUN_1407cbb20("afterStat", StringFormat(L"{0}", after));
                list.FUN_1422bc050(obj.FUN_1422bb870());
            }
        }
        pOption->m_options.GetNext(pos);
    }
    dest.FUN_1409eb1d0("options", list);
}

// @0x1419c6bb0
void UIItemEnchantDialog::FUN_1419c6bb0(ASObj& dest, CItem* item)
{
    if (item != 0)
        dest.FUN_1407cba60("enchantItem", FUN_1419c78a0(item, Unk_SocketFormat("{0}.selectedItem", vfunc_1()), m_bag0));
}

// @0x1419c6cd0
void UIItemEnchantDialog::FUN_1419c6cd0(ASObj& dest, CIngredientContainer* container)
{
    ASArray list(2);
    __int64 fee = 0;
    for (unsigned __int64 i = 0; i < container->FUN_14026bf10(); i++) {
        Unk_IngRef ing = container->FUN_14026be50(i);
        int type = ing->m_b;
        unsigned int itemId = ing->FUN_14026b500();
        int need = ing->m_c;
        int rank = FUN_14053feb0(itemId);
        CItem* ci = new CItem;
        if (ci->FUN_14052b2e0(itemId, rank, 0, need) != 0) {
            ASObj obj(2);
            int have = DAT_143ab2a90.FUN_140a5f780(ing->m_b, 0);
            obj.FUN_1407cba60("binding", FUN_1419c78a0(ci, StringFormat("{0}.ingredient.{1}", vfunc_1(), i), m_bag1));
            obj.FUN_1407cbb20("countText", FUN_1419021b0(have, need));
            reinterpret_cast<Unk_EnArray&>(list).FUN_1422bbf00(obj);
            if ((type == 0x60) && (have < need))
                fee = (__int64)((need - have) * 1000);
        }
    }
    dest.FUN_1409eb1d0("ingredient", list);
    if (0 < fee)
        dest.FUN_1407cbb20("enchantFee", FUN_1405c2690(CStringW(L"s_itemenchant_fee"), FUN_1409404f0(fee)));
}

// @0x1419c7140
void UIItemEnchantDialog::FUN_1419c7140(ASObj& dest)
{
    if (FUN_1419c1d60() == 0)
        return;
    ASObj obj(2);
    CItem* ci = new CItem;
    if (ci->FUN_14052b130(m_result.vfunc_o18_0(), m_result.vfunc_o18_1(), 0) != 0) {
        obj.FUN_1407cba60("binding", FUN_1419c78a0(ci, Unk_SocketFormat("{0}.equip_ingredient", vfunc_1()), m_bag1));
        obj.FUN_1407cbb20("countText", FUN_141902320(m_2bc, m_result.vfunc_o18_2()));
        dest.FUN_1409eb270("equipIngredient", obj);
    }
    ASArray list(2);
    for (unsigned __int64 i = 0; i < m_failStackUids.GetCount(); i++)
        reinterpret_cast<Unk_EnArray&>(list).FUN_1422bbfe0((LPCWSTR)FUN_141b71910(m_failStackUids[i]));
    dest.FUN_1409eb1d0("equipList", list);
}

// @0x1419c74e0
void UIItemEnchantDialog::FUN_1419c74e0(ASObj& dest, CItem* item)
{
    if (item == 0)
        return;
    int exp = item->FUN_1405270a0();
    int percent = (exp * 100) / 10000;
    int maxExp = 0;
    int curExp = 0;
    int divisor = item->FUN_140528f90((int)((__int64)(exp * 100) % 10000));
    if (0 < divisor) {
        maxExp = (int)(10000.0 / (float)divisor + 0.5);
        curExp = item->FUN_1405270a0();
        curExp = curExp / divisor;
    }
    CStringW text = StringFormat(L"{0} / {1}", curExp, maxExp);
    dest.FUN_1407cb9c0("expPercent", percent);
    dest.FUN_1407cbb20("expText", text);
}

// @0x1419c7610
void UIItemEnchantDialog::FUN_1419c7610(ASObj& dest)
{
    if (FUN_1419c1e00() == 0)
        return;
    MS2Ptr<CItem> item = FUN_1419bef70(m_selectedUid);
    if (!(!item)) {
        if (item->FUN_1405278a0() != 0) {
            CItemEnchantInfo* info = item->FUN_1405278a0()->FUN_140630d60();
            if (info != 0) {
                int limit = *FUN_1401d3200()->m_9828.FUN_1401d7c10();
                int cur = info->FUN_14058ccf0();
                int maxStack = (std::min)(cur, limit);
                ASObj obj(2);
                obj.FUN_1407cb9c0("current", m_failStack);
                obj.FUN_1407cb9c0("maximum", maxStack);
                dest.FUN_1409eb270("failStack", obj);
            }
        }
    }
}

// @0x1419c77a0
void UIItemEnchantDialog::FUN_1419c77a0()
{
    for (size_t i = 0; i < m_bag0.GetCount(); i++)
        FUN_141415600(m_bag0[i]);
    FUN_1402c2890(m_bag0);
    for (size_t i = 0; i < m_bag1.GetCount(); i++)
        FUN_141415600(m_bag1[i]);
    FUN_1402c2890(m_bag1);
}

// @0x1419c78a0
CString UIItemEnchantDialog::FUN_1419c78a0(CItem* item, CString key, CAtlArray<CString>& names)
{
    FUN_141415600(key);
    FUN_141415450(key, MS2Ptr<CItem>(item), 0, 0x405, 0);
    FUN_140165270(names, key);
    return key;
}

// @0x1419c7970
CStringW UIItemEnchantDialog::FUN_1419c7970(float rate)
{
    int percent = (int)FUN_14028aed0(rate);
    if (percent == 0)
        return FUN_14028de60(0x95d);
    return FUN_14052bd00(0x98e, StringFormat(L"{0}", percent));
}

// @0x1419c7a30
void UIItemEnchantDialog::FUN_1419c7a30(unsigned __int64 uid, int mode)
{
    MS2Ptr<CItem> item = FUN_1419bef70(uid);
    if (item == 0)
        return;
    if (item->FUN_1405270a0() < 1) {
        FUN_1419c7ce0(uid, mode);
        return;
    }
    MS2Ptr<CMsgBoxData> box = FUN_140d73d20(1, FUN_14028b8e0(CStringW(L"s_itemenchant_exp_payback")), 0, CStringW(L""));
    if (box.get() != 0) {
        box->Append<__int64>(uid);
        box->Append<int>(mode);
        FUN_141a024a0(box.operator->(), 0);
        box->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &UIItemEnchantDialog::FUN_1419c5e90));
        FUN_140d73c60(box);
    }
}

// @0x1419c7ce0
void UIItemEnchantDialog::FUN_1419c7ce0(unsigned __int64 uid, int mode)
{
    MS2Ptr<CItem> item = FUN_1419bef70(uid);
    if (item == 0)
        return;
    unsigned __int64 other = 0;
    if (mode == 1)
        other = m_210;
    else if (mode == 2)
        other = m_220;
    if (item.get() != 0) {
        COutPacket pkt(0x5e, 0);
        pkt.Encode1(4);
        pkt.Encode8(uid);
        pkt.Encode8(other);
        FUN_140710590(pkt);
        vfunc_85(2);
    }
}

// @0x1419c7e20
CStringW UIItemEnchantDialog::FUN_1419c7e20(CItem* item)
{
    int rank = item->FUN_140526bd0();
    int id = item->FUN_1405276c0();
    return FUN_14183e9c0(FUN_1401a9d70()->FUN_141811980(1, id), rank);
}

// @0x1419c7ec0
CStringW UIItemEnchantDialog::FUN_1419c7ec0(int level, int rank)
{
    return StringFormat(L"<font color='{0}'>+{1}</font>", FUN_140281980()->FUN_140556a40(rank), level);
}

// @0x1419c7f50
CStringW UIItemEnchantDialog::FUN_1419c7f50(CItem* item, int count)
{
    if (item == 0)
        return CStringW(L"");
    if (count < 1)
        return CStringW(L"");
    return FUN_14062b4f0(CStringW(L"s_itemenchant_fail_get_fail_stack_count"), &count);
}

// @0x1419c8020
CStringW UIItemEnchantDialog::FUN_1419c8020()
{
    return CStringW(L"");
}

// @0x1419c8070
void UIItemEnchantDialog::FUN_1419c8070(CItem* item)
{
    ASObj obj(2);
    obj.FUN_1407cbb20("prop", FUN_1419c8ce0(item));
    FUN_1419c7610(obj);
    FUN_1419c7140(obj);
    m_enchantAni->Invoke("updateEnchantIngredient", obj);
}

// @0x1419c8160
Unk_EnSlot* UIItemEnchantDialog::FUN_1419c8160(const CString& name)
{
    Unk_EnSlot* slot = FUN_140f6e830(name);
    if (slot == 0)
        slot = 0;
    return slot;
}

// @0x1419c81a0
void UIItemEnchantDialog::FUN_1419c81a0()
{
    if (m_enchantAni == 0)
        return;
    MS2Ptr<CItem> item = FUN_1419bef70(m_selectedUid);
    if (item.get() != 0) {
        ASObj obj(2);
        obj.FUN_1409c0d20("id", item->FUN_1405276c0());
        obj.FUN_1407cbb20("itemName", item->FUN_140528160());
        obj.FUN_1407cbb20("prop", FUN_1419c8ce0(item.get()));
        obj.FUN_1407cbb20("desc", FUN_1419c8020());
        obj.FUN_1407cbb20("guid", FUN_141b71910(m_selectedUid));
        obj.FUN_1407cba60("frame", FUN_1419c1e40());
        if (0.0f < m_2b4) {
            int sale = (int)((m_2b4 + 1e-06f) * 100.0);
            obj.FUN_1407cbb20("saleDesc", FUN_140938ae0(CStringW(L"s_itemenchant_sale"), sale));
        }
        FUN_1419c6840(MS2Ptr<CItem>(item), m_option.operator->(), obj);
        if (m_expMode == 1) {
            FUN_1419c6bb0(obj, item.get());
            FUN_1419c6cd0(obj, &m_ingredients);
            FUN_1419c7140(obj);
            FUN_1419c7610(obj);
        } else if (m_expMode == 2) {
            FUN_1419c6bb0(obj, item.get());
            FUN_1419c6cd0(obj, &m_ingredients);
            FUN_1419c7140(obj);
            FUN_1419c74e0(obj, item.get());
        }
        m_enchantAni->Invoke("setEnchantInfo", obj);
    }
    m_enchantAni->Invoke("playEnchant");
}

// @0x1419c86b0
int UIItemEnchantDialog::FUN_1419c86b0(int itemId)
{
    MS2Ptr<CItemData> data = FUN_14053f870(itemId);
    if (!data)
        return 0;
    if (FUN_1403b3c40(data->function.name, L"EnchantSuperProtect") == 0) {
        if (FUN_1403b3c40(data->function.name, L"EnchantScroll") != 0) {
            unsigned int arg = reinterpret_cast<Unk_CommandArgs*>(&data->function.parameter)->FUN_1408d1f60(0, 0);
            Unk_EnScrollRef ref = FUN_14034f780()->FUN_14034e360(arg);
            if (ref.get() != 0)
                return ref.operator->()->FUN_14034d370();
        }
        return 0;
    }
    return reinterpret_cast<Unk_CommandArgs*>(&data->function.parameter)->FUN_1408d1f60(0, 0);
}

// @0x1419c8830
int UIItemEnchantDialog::FUN_1419c8830(int itemId)
{
    MS2Ptr<CItemData> data = FUN_14053f870(itemId);
    if (!data)
        return 0;
    if (FUN_1403b3c40(data->function.name, L"EnchantSuperProtect") == 0) {
        if (FUN_1403b3c40(data->function.name, L"EnchantScroll") != 0) {
            unsigned int arg = reinterpret_cast<Unk_CommandArgs*>(&data->function.parameter)->FUN_1408d1f60(0, 0);
            Unk_EnScrollRef ref = FUN_14034f780()->FUN_14034e360(arg);
            if (ref.get() != 0)
                return ref.operator->()->m_1c;
        }
        return 0;
    }
    return reinterpret_cast<Unk_CommandArgs*>(&data->function.parameter)->FUN_1408d1f60(1, 0);
}

// @0x1419c89b0
bool UIItemEnchantDialog::FUN_1419c89b0(unsigned __int64 uid)
{
    MS2Ptr<CItem> item = FUN_1419bef70(uid);
    if (!item)
        return false;
    unsigned int level = item->FUN_140527710();
    if (level < *FUN_1401d3200()->m_99e0.FUN_1401d7c10())
        return false;
    bool hasCurrency = false;
    for (unsigned __int64 i = 0; i < m_ingredients.FUN_14026bee0(); i++) {
        Unk_IngRef ing = *m_ingredients.m_items.FUN_14027f1f0(i);
        int have = DAT_143ab2a90.FUN_140a5f780(ing->m_b, 0);
        if (have < ing->m_c)
            return false;
        if ((*m_ingredients.m_items.FUN_14027f1f0(i))->m_b == 99)
            hasCurrency = true;
    }
    return hasCurrency;
}

// @0x1419c8b80
bool UIItemEnchantDialog::FUN_1419c8b80(unsigned __int64 uid)
{
    MS2Ptr<CItem> item = FUN_1419bef70(uid);
    if (!item)
        return false;
    if (item->FUN_140527930() == 0)
        return false;
    Unk_EnOwner* owner = item->FUN_140527930()->FUN_140635160();
    if (owner == 0)
        return false;
    MyPC* pc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pc == 0)
        return false;
    return FUN_141656a80(pc) == owner->FUN_14052d1c0();
}

// @0x1419c8ce0
CStringW UIItemEnchantDialog::FUN_1419c8ce0(CItem* item)
{
    if (m_expMode != 1)
        return CStringW(L"");
    float chance = 0.0f;
    bool bonus = false;
    int level = item->FUN_140526fc0() + 1;
    int event = FUN_14047e370(FUN_1401c0d90(), level);
    if (event == 0) {
        chance = m_228;
    } else {
        chance = (float)((double)m_228 * ((double)event * 0.009999999776482582 + 1.0));
        if (100.0f < chance)
            chance = 100.0f;
        bonus = true;
    }
    m_23c = chance + m_234 + m_238;
    CStringW text = FUN_14028dfa0(CStringW(L"s_itemenchant_option_prop"), m_23c);
    if ((FUN_14028d470(m_234, 0) == 0) || (FUN_14028d470(m_238, 0) == 0))
        text += FUN_14028dfa0(CStringW(L"s_itemenchant_prop_detail"), chance, m_234, m_238);
    if (bonus) {
        text += "\n";
        text += FUN_14028dfa0(CStringW(L"s_itemenchant_option_prop_event"), m_228, chance);
    }
    return text;
}

// @0x1419c90b0
void UIItemEnchantDialog::FUN_1419c90b0(unsigned int itemId, int count, __int64 arg)
{
    CAtlArray<MS2Ptr<CItem>> list;
    if (0 < count) {
        MS2Ptr<CItem> ci(new CItem);
        int rank = FUN_14053feb0(itemId);
        if (ci->FUN_140523c40(itemId, rank, 0)) {
            ci->FUN_140526c70(count);
            list.Add(ci);
        }
    }
    if ((list.GetCount() != 0) || (arg != 0)) {
        Unk_EnInvDialog* inv = FUN_140a7b2b0(0x4e40);
        if (inv != 0)
            inv->FUN_141b1ac40(list, FUN_14028de60(0x956), 0, 0, arg);
    }
}

// @0x1419c9260
bool UIItemEnchantDialog::FUN_1419c9260(CItem* base, CItem* other)
{
    Unk_EnPC* pc = (Unk_EnPC*)FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pc == 0)
        return false;
    if (pc->FUN_141662eb0(other) == 0)
        return false;
    if (other->FUN_140528e20())
        return false;
    if (m_selectedUid == other->FUN_140526a50())
        return false;
    if ((int)m_result.vfunc_o18_0() == ItemData(other)->FUN_14053c560()) {
        if (m_result.vfunc_o18_1() == other->FUN_140526bd0())
            return true;
    }
    return FUN_1419c93a0(base, other) != 0;
}

// @0x1419c93a0
bool UIItemEnchantDialog::FUN_1419c93a0(CItem* base, CItem* other)
{
    int flag = 0;
    switch (base->FUN_140526bd0()) {
    case 1: flag = 0xcb; break;
    case 2: flag = 0xcc; break;
    case 3: flag = 0xcd; break;
    case 4: flag = 0xce; break;
    case 5: flag = 0xcf; break;
    case 6: flag = 0xd0; break;
    }
    if (!other->FUN_1405277e0(flag))
        return false;
    return other->FUN_140526c50() == 1;
}

// @0x1419c9490
bool UIItemEnchantDialog::FUN_1419c9490(CItem* base, CItem* other)
{
    if ((m_expMode == 2) && (FUN_1419c1d60() != 0)) {
        unsigned int have = FUN_1419c9530(base);
        if (have < m_result.m_count) {
            int add = FUN_1419c9630(base, other);
            if (m_result.m_count < have + add)
                return true;
        }
    }
    return false;
}

// @0x1419c9530
int UIItemEnchantDialog::FUN_1419c9530(CItem* base)
{
    int total = 0;
    if (base == 0)
        return 0;
    if (ItemData(base) == 0)
        return 0;
    for (unsigned __int64 i = 0; i < m_failStackUids.GetCount(); i++) {
        MS2Ptr<CItem> other = FUN_1419bef70(m_failStackUids[i]);
        total += FUN_1419c9630(base, other.get());
    }
    return total;
}

// @0x1419c9630
int UIItemEnchantDialog::FUN_1419c9630(CItem* base, CItem* other)
{
    if (other == 0)
        return 0;
    if (!ItemData(base)->FUN_14053d510())
        return 1;
    return FUN_1419c93a0(base, other) ? 2 : 1;
}

// @0x1419ca130
Scaleform::GFx::Value Unk_EnScript::FUN_1419ca130(const char* name, const AScript& obj, bool b)
{
    ASArgList args;
    args.FUN_1409b2800(2);
    FUN_1422bce40(args.FUN_1409b1f70(0), obj);
    FUN_1422bcce0(args.FUN_1409b1f70(1), b);
    return FUN_1422bb8f0(name, args);
}

// @0x1419ca1f0
Scaleform::GFx::Value Unk_EnScript::FUN_1419ca1f0(const char* name, int a, bool b)
{
    ASArgList args;
    args.FUN_1409b2800(2);
    FUN_1422bccb0(args.FUN_1409b1f70(0), a);
    FUN_1422bcce0(args.FUN_1409b1f70(1), b);
    return FUN_1422bb8f0(name, args);
}

// @0x1419ca850
int UIItemEnchantDialog::vfunc_48()
{
    return 0x4e92;
}

// @0x1419cad20
UIItemEventListener::UIItemEventListener()
{
}

// @0x1419cad40
UIItemEventListener::~UIItemEventListener()
{
}

// @0x1419cad60
int UIItemEventListener::vfunc_il1()
{
    return 1;
}

// @0x1419cad80
UIItemEventDispatcher::UIItemEventDispatcher()
{
}

// @0x1419cadd0
UIItemEventDispatcher::~UIItemEventDispatcher()
{
    m_listeners.RemoveAll();
}

// @0x1419cae20
void Unk_ItemEventSystem::FUN_1419cae20(UIItemEventListener* listener)
{
    for (size_t i = 0; i < m_listeners.GetCount(); i++) {
        if (listener == m_listeners.GetAt(i))
            return;
    }
    m_listeners.Add(listener);
}

// @0x1419caeb0
void Unk_ItemEventSystem::FUN_1419caeb0(UIItemEventListener* listener)
{
    for (size_t i = 0; i < m_listeners.GetCount(); i++) {
        if (listener == m_listeners.GetAt(i)) {
            m_listeners.RemoveAt(i, 1);
            break;
        }
    }
}

// @0x1419caf40
void UIItemEventDispatcher::vfunc_1(void* a0)
{
    for (size_t i = 0; i < m_listeners.GetCount(); i++) {
        UIItemEventListener* listener = m_listeners.GetAt(i);
        if (listener != 0 && listener->vfunc_il1() != 0)
            listener->vfunc_2(a0);
    }
}

// @0x1419cafe0
void UIItemEventDispatcher::vfunc_2(void* a0, bool a1)
{
    for (size_t i = 0; i < m_listeners.GetCount(); i++) {
        UIItemEventListener* listener = m_listeners.GetAt(i);
        if (listener != 0 && listener->vfunc_il1() != 0)
            listener->vfunc_3(a0, a1);
    }
}

// @0x1419cb090
void UIItemEventDispatcher::vfunc_3(void* a0, int a1)
{
    for (size_t i = 0; i < m_listeners.GetCount(); i++) {
        UIItemEventListener* listener = m_listeners.GetAt(i);
        if (listener != 0 && listener->vfunc_il1() != 0)
            listener->vfunc_4(a0, a1);
    }
}

// @0x1419cb140
void UIItemEventDispatcher::vfunc_4(void* a0, int a1)
{
    for (size_t i = 0; i < m_listeners.GetCount(); i++) {
        UIItemEventListener* listener = m_listeners.GetAt(i);
        if (listener != 0 && listener->vfunc_il1() != 0)
            listener->vfunc_5(a0, a1);
    }
}

// @0x1419cb1f0
void UIItemEventDispatcher::vfunc_5(void* a0)
{
    for (size_t i = 0; i < m_listeners.GetCount(); i++) {
        UIItemEventListener* listener = m_listeners.GetAt(i);
        if (listener != 0 && listener->vfunc_il1() != 0)
            listener->vfunc_il6(a0);
    }
}

// @0x1419cb290
void UIItemEventDispatcher::vfunc_6(void* a0)
{
    for (size_t i = 0; i < m_listeners.GetCount(); i++) {
        UIItemEventListener* listener = m_listeners.GetAt(i);
        if (listener != 0 && listener->vfunc_il1() != 0)
            listener->vfunc_il7(a0);
    }
}

// @0x1419cb330
void UIItemEventDispatcher::vfunc_7(void* a0)
{
    for (size_t i = 0; i < m_listeners.GetCount(); i++) {
        UIItemEventListener* listener = m_listeners.GetAt(i);
        if (listener != 0 && listener->vfunc_il1() != 0)
            listener->vfunc_il8(a0);
    }
}

// @0x1419cb3d0
void UIItemEventDispatcher::vfunc_8(void* a0)
{
    for (size_t i = 0; i < m_listeners.GetCount(); i++) {
        UIItemEventListener* listener = m_listeners.GetAt(i);
        if (listener != 0 && listener->vfunc_il1() != 0)
            listener->vfunc_9(a0);
    }
}

// @0x1419cb470
void UIItemEventDispatcher::vfunc_9(void* a0)
{
    for (size_t i = 0; i < m_listeners.GetCount(); i++) {
        UIItemEventListener* listener = m_listeners.GetAt(i);
        if (listener != 0 && listener->vfunc_il1() != 0)
            listener->vfunc_10(a0);
    }
}

// @0x1419cb510
void UIItemEventDispatcher::vfunc_10(void* a0)
{
    for (size_t i = 0; i < m_listeners.GetCount(); i++) {
        UIItemEventListener* listener = m_listeners.GetAt(i);
        if (listener != 0 && listener->vfunc_il1() != 0)
            listener->vfunc_il11(a0);
    }
}

// @0x1419cb5b0
void UIItemEventDispatcher::vfunc_11()
{
    for (size_t i = 0; i < m_listeners.GetCount(); i++) {
        UIItemEventListener* listener = m_listeners.GetAt(i);
        if (listener != 0 && listener->vfunc_il1() != 0)
            listener->vfunc_12();
    }
}

// @0x1419cb640
void UIItemEventDispatcher::vfunc_12()
{
    for (size_t i = 0; i < m_listeners.GetCount(); i++) {
        UIItemEventListener* listener = m_listeners.GetAt(i);
        if (listener != 0 && listener->vfunc_il1() != 0)
            listener->vfunc_il13();
    }
}

// @0x1419cb6d0
void UIItemEventDispatcher::vfunc_13(void* a0)
{
    for (size_t i = 0; i < m_listeners.GetCount(); i++) {
        UIItemEventListener* listener = m_listeners.GetAt(i);
        if (listener != 0 && listener->vfunc_il1() != 0)
            listener->vfunc_14(a0);
    }
}

// @0x1419cb770
void UIItemEventDispatcher::vfunc_14(void* a0)
{
    for (size_t i = 0; i < m_listeners.GetCount(); i++) {
        UIItemEventListener* listener = m_listeners.GetAt(i);
        if (listener != 0 && listener->vfunc_il1() != 0)
            listener->vfunc_15(a0);
    }
}

// @0x1419cb810
void UIItemEventDispatcher::vfunc_15(void* a0)
{
    for (size_t i = 0; i < m_listeners.GetCount(); i++) {
        UIItemEventListener* listener = m_listeners.GetAt(i);
        if (listener != 0 && listener->vfunc_il1() != 0)
            listener->vfunc_16(a0);
    }
}

// @0x1419cb8b0
void UIItemEventDispatcher::vfunc_16(void* a0, int a1)
{
    for (size_t i = 0; i < m_listeners.GetCount(); i++) {
        UIItemEventListener* listener = m_listeners.GetAt(i);
        if (listener != 0 && listener->vfunc_il1() != 0)
            listener->vfunc_17(a0, a1);
    }
}

// @0x1419cb960
void UIItemEventDispatcher::vfunc_17(void* a0)
{
    for (size_t i = 0; i < m_listeners.GetCount(); i++) {
        UIItemEventListener* listener = m_listeners.GetAt(i);
        if (listener != 0 && listener->vfunc_il1() != 0)
            listener->vfunc_18(a0);
    }
}

// @0x1419cba00
void UIItemEventDispatcher::vfunc_18(void* a0)
{
    for (size_t i = 0; i < m_listeners.GetCount(); i++) {
        UIItemEventListener* listener = m_listeners.GetAt(i);
        if (listener != 0 && listener->vfunc_il1() != 0)
            listener->vfunc_19(a0);
    }
}

// @0x1419cbaa0
void UIItemEventDispatcher::vfunc_19(void* a0)
{
    for (size_t i = 0; i < m_listeners.GetCount(); i++) {
        UIItemEventListener* listener = m_listeners.GetAt(i);
        if (listener != 0 && listener->vfunc_il1() != 0)
            listener->vfunc_20(a0);
    }
}

// @0x1419cbb40
void UIItemEventDispatcher::vfunc_20(void* a0)
{
    for (size_t i = 0; i < m_listeners.GetCount(); i++) {
        UIItemEventListener* listener = m_listeners.GetAt(i);
        if (listener != 0 && listener->vfunc_il1() != 0)
            listener->vfunc_21(a0);
    }
}

// @0x1419cbbe0
void UIItemEventDispatcher::vfunc_21(void* a0)
{
    for (size_t i = 0; i < m_listeners.GetCount(); i++) {
        UIItemEventListener* listener = m_listeners.GetAt(i);
        if (listener != 0 && listener->vfunc_il1() != 0)
            listener->vfunc_22(a0);
    }
}

// @0x1419cbc80
void UIItemEventDispatcher::vfunc_22(void* a0)
{
    for (size_t i = 0; i < m_listeners.GetCount(); i++) {
        UIItemEventListener* listener = m_listeners.GetAt(i);
        if (listener != 0 && listener->vfunc_il1() != 0)
            listener->vfunc_23(a0);
    }
}

// @0x1419cbd20
void UIItemEventDispatcher::vfunc_23(void* a0)
{
    for (size_t i = 0; i < m_listeners.GetCount(); i++) {
        UIItemEventListener* listener = m_listeners.GetAt(i);
        if (listener != 0 && listener->vfunc_il1() != 0)
            listener->vfunc_24(a0);
    }
}

// @0x1419cbdc0
void UIItemEventDispatcher::vfunc_24(void* a0)
{
    for (size_t i = 0; i < m_listeners.GetCount(); i++) {
        UIItemEventListener* listener = m_listeners.GetAt(i);
        if (listener != 0 && listener->vfunc_il1() != 0)
            listener->vfunc_25(a0);
    }
}

// @0x1419cbe60
void UIItemEventDispatcher::vfunc_25(int a0)
{
    for (size_t i = 0; i < m_listeners.GetCount(); i++) {
        UIItemEventListener* listener = m_listeners.GetAt(i);
        if (listener != 0 && listener->vfunc_il1() != 0)
            listener->vfunc_26(a0);
    }
}

// @0x1419cbf00
void UIItemEventDispatcher::vfunc_26(int a0)
{
    for (size_t i = 0; i < m_listeners.GetCount(); i++) {
        UIItemEventListener* listener = m_listeners.GetAt(i);
        if (listener != 0 && listener->vfunc_il1() != 0)
            listener->vfunc_27(a0);
    }
}

// @0x1419cbfa0
void UIItemEventDispatcher::vfunc_27(void* a0)
{
    for (size_t i = 0; i < m_listeners.GetCount(); i++) {
        UIItemEventListener* listener = m_listeners.GetAt(i);
        if (listener != 0 && listener->vfunc_il1() != 0)
            listener->vfunc_28(a0);
    }
}

// @0x1419cc040
void UIItemEventDispatcher::vfunc_28(void* a0)
{
    for (size_t i = 0; i < m_listeners.GetCount(); i++) {
        UIItemEventListener* listener = m_listeners.GetAt(i);
        if (listener != 0 && listener->vfunc_il1() != 0)
            listener->vfunc_29(a0);
    }
}

// @0x1419cc0e0
void UIItemEventDispatcher::vfunc_29(void* a0)
{
    for (size_t i = 0; i < m_listeners.GetCount(); i++) {
        UIItemEventListener* listener = m_listeners.GetAt(i);
        if (listener != 0 && listener->vfunc_il1() != 0)
            listener->vfunc_30(a0);
    }
}

// @0x1419cc180
void UIItemEventDispatcher::vfunc_30(void* a0)
{
    for (size_t i = 0; i < m_listeners.GetCount(); i++) {
        UIItemEventListener* listener = m_listeners.GetAt(i);
        if (listener != 0 && listener->vfunc_il1() != 0)
            listener->vfunc_31(a0);
    }
}

// @0x1419cc220
void UIItemEventDispatcher::vfunc_31(void* a0, int a1, int a2)
{
    for (size_t i = 0; i < m_listeners.GetCount(); i++) {
        UIItemEventListener* listener = m_listeners.GetAt(i);
        if (listener != 0 && listener->vfunc_il1() != 0)
            listener->vfunc_32(a0, a1, a2);
    }
}

// @0x1419cc2e0
void UIItemEventDispatcher::vfunc_32(int a0, int a1)
{
    for (size_t i = 0; i < m_listeners.GetCount(); i++) {
        UIItemEventListener* listener = m_listeners.GetAt(i);
        if (listener != 0 && listener->vfunc_il1() != 0)
            listener->vfunc_33(a0, a1);
    }
}

// @0x1419cc390
void UIItemEventDispatcher::vfunc_33()
{
    for (size_t i = 0; i < m_listeners.GetCount(); i++) {
        UIItemEventListener* listener = m_listeners.GetAt(i);
        if (listener != 0 && listener->vfunc_il1() != 0)
            listener->vfunc_34();
    }
}


MS2_EMIT_CRT_MEMMOVE_S();
// @0x1419ccbe0
MS2_EMIT_CRT_MEMMOVE_S_COPY(2);

MS2_REPLACE(0x1419BE700, FUN_1419be700, 336, 0x2104D35F);
MS2_REPLACE_METHOD(0x1419BE8E0, UIItemModifyDialogBase, vfunc_43, 292, 0x604C2AD2);
MS2_REPLACE_METHOD(0x1419BEA10, UIItemModifyDialogBase, OnLoadComplete, 872, 0x37F5C4A6);
MS2_REPLACE_METHOD(0x1419BED80, UIItemModifyDialogBase, vfunc_28, 67, 0x436FDE43);
MS2_REPLACE_METHOD(0x1419BEDD0, UIItemModifyDialogBase, vfunc_67, 45, 0x8F4E6D41);
MS2_REPLACE_METHOD(0x1419BEE10, UIItemModifyDialogBase, vfunc_84, 104, 0x33C46F1A);
MS2_REPLACE_METHOD(0x1419BEE80, UIItemModifyDialogBase, vfunc_85, 94, 0x7B7F2CAF);
MS2_REPLACE_METHOD(0x1419BEEF0, UIItemModifyDialogBase, FUN_1419beef0, 112, 0xC4943258);
MS2_REPLACE_METHOD(0x1419BEF70, UIItemModifyDialogBase, FUN_1419bef70, 63, 0xD1B148BE);
MS2_REPLACE_METHOD(0x1419BF2C0, UIItemEnchantDialog, vfunc_1, 61, 0xC6492D8B);
MS2_REPLACE_METHOD(0x1419BF310, UIItemEnchantDialog, OnLoadInit, 249, 0x237BE92A);
MS2_REPLACE_METHOD(0x1419BF910, UIItemEnchantDialog, vfunc_28, 740, 0xBFB48C51);
MS2_REPLACE_METHOD(0x1419BFC20, UIItemEnchantDialog, vfunc_43, 24, 0x06E56BED);
MS2_REPLACE_METHOD(0x1419BFC40, UIItemEnchantDialog, vfunc_13, 8, 0x7F371472);
MS2_REPLACE_METHOD_VIA(0x1419BFC50, UIItemEnchantDialog, IMessageListener, OnMessage, 60, 0x03FA1972);
MS2_REPLACE_METHOD(0x1419BFCA0, UIItemEnchantDialog, vfunc_85, 202, 0xC1601B65);
MS2_REPLACE_METHOD(0x1419BFD70, UIItemEnchantDialog, FUN_1419bfd70, 475, 0xB5E37790);
MS2_REPLACE_METHOD(0x1419BFF60, UIItemEnchantDialog, FUN_1419bff60, 880, 0xA12611D3);
MS2_REPLACE_METHOD(0x1419C02E0, UIItemEnchantDialog, FUN_1419c02e0, 116, 0x837D935B);
MS2_REPLACE_METHOD(0x1419C0360, UIItemEnchantDialog, FUN_1419c0360, 91, 0xCB4750E9);
MS2_REPLACE_METHOD(0x1419C03D0, UIItemEnchantDialog, FUN_1419c03d0, 91, 0xD29906B8);
MS2_REPLACE_METHOD(0x1419C0C70, UIItemEnchantDialog, FUN_1419c0c70, 197, 0x173AAD5F);
MS2_REPLACE_METHOD(0x1419C11E0, UIItemEnchantDialog, FUN_1419c11e0, 48, 0x9599EC04);
MS2_REPLACE_METHOD(0x1419C15C0, UIItemEnchantDialog, FUN_1419c15c0, 100, 0x3ADF4CC0);
MS2_REPLACE_METHOD(0x1419C1630, UIItemEnchantDialog, FUN_1419c1630, 100, 0xA08A2C70);
MS2_REPLACE_METHOD(0x1419C16A0, UIItemEnchantDialog, FUN_1419c16a0, 18, 0x232FCD10);
MS2_REPLACE_METHOD(0x1419C19D0, UIItemEnchantDialog, FUN_1419c19d0, 91, 0x012443E8);
MS2_REPLACE_METHOD(0x1419C1A40, UIItemEnchantDialog, FUN_1419c1a40, 783, 0xA75C2F26);
MS2_REPLACE_METHOD(0x1419C1D60, UIItemEnchantDialog, FUN_1419c1d60, 140, 0xCE77794F);
MS2_REPLACE_METHOD(0x1419C1E00, UIItemEnchantDialog, FUN_1419c1e00, 53, 0x4E5EE7B9);
MS2_REPLACE_METHOD(0x1419C1E40, UIItemEnchantDialog, FUN_1419c1e40, 207, 0x82508001);
MS2_REPLACE_METHOD(0x1419C37F0, UIItemEnchantDialog, FUN_1419c37f0, 344, 0x26D73179);
MS2_REPLACE_METHOD(0x1419C3950, UIItemEnchantDialog, FUN_1419c3950, 558, 0x9A27A1DA);
MS2_REPLACE_METHOD(0x1419C3B90, UIItemEnchantDialog, FUN_1419c3b90, 723, 0xA88975ED);
MS2_REPLACE_METHOD(0x1419C3E70, UIItemEnchantDialog, FUN_1419c3e70, 341, 0x8DD13E96);
MS2_REPLACE_METHOD(0x1419C3FD0, UIItemEnchantDialog, FUN_1419c3fd0, 119, 0x84095DA5);
MS2_REPLACE_METHOD(0x1419C4050, UIItemEnchantDialog, FUN_1419c4050, 343, 0x8860A6F7);
MS2_REPLACE_METHOD(0x1419C41B0, UIItemEnchantDialog, FUN_1419c41b0, 422, 0x5183F1D2);
MS2_REPLACE_METHOD(0x1419C5D20, UIItemEnchantDialog, FUN_1419c5d20, 98, 0xD143B54F);
MS2_REPLACE_METHOD(0x1419C5D90, UIItemEnchantDialog, FUN_1419c5d90, 71, 0x14F87C35);
MS2_REPLACE_METHOD(0x1419C5DE0, UIItemEnchantDialog, FUN_1419c5de0, 157, 0x54490F9C);
MS2_REPLACE_METHOD(0x1419C5E90, UIItemEnchantDialog, FUN_1419c5e90, 98, 0x05CFFE46);
MS2_REPLACE_METHOD(0x1419C5F00, UIItemEnchantDialog, FUN_1419c5f00, 77, 0x21806692);
MS2_REPLACE_METHOD(0x1419C5F60, UIItemEnchantDialog, FUN_1419c5f60, 247, 0x545B198F);
MS2_REPLACE_METHOD(0x1419C6060, UIItemEnchantDialog, FUN_1419c6060, 247, 0x21FF4F46);
MS2_REPLACE_METHOD(0x1419C6160, UIItemEnchantDialog, FUN_1419c6160, 259, 0x2DAFAFCE);
MS2_REPLACE_METHOD(0x1419C6270, UIItemEnchantDialog, FUN_1419c6270, 262, 0x7AF130B8);
MS2_REPLACE_METHOD(0x1419C6380, UIItemEnchantDialog, FUN_1419c6380, 145, 0x2C1DD8AC);
MS2_REPLACE_METHOD(0x1419C6420, UIItemEnchantDialog, FUN_1419c6420, 391, 0xB7263E85);
MS2_REPLACE_METHOD(0x1419C65B0, UIItemEnchantDialog, FUN_1419c65b0, 641, 0x925F36DD);
MS2_REPLACE_METHOD(0x1419C6840, UIItemEnchantDialog, FUN_1419c6840, 865, 0xDA112076);
MS2_REPLACE_METHOD(0x1419C6BB0, UIItemEnchantDialog, FUN_1419c6bb0, 276, 0xEF182F86);
MS2_REPLACE_METHOD(0x1419C74E0, UIItemEnchantDialog, FUN_1419c74e0, 291, 0x8EF8E019);
MS2_REPLACE_METHOD(0x1419C7610, UIItemEnchantDialog, FUN_1419c7610, 391, 0x2B4CFA04);
MS2_REPLACE_METHOD(0x1419C77A0, UIItemEnchantDialog, FUN_1419c77a0, 240, 0x55BF1B8B);
MS2_REPLACE_METHOD(0x1419C78A0, UIItemEnchantDialog, FUN_1419c78a0, 197, 0x9CBFF8DE);
MS2_REPLACE_METHOD(0x1419C7970, UIItemEnchantDialog, FUN_1419c7970, 185, 0xD43FB7C3);
MS2_REPLACE_METHOD(0x1419C7CE0, UIItemEnchantDialog, FUN_1419c7ce0, 312, 0x332989F9);
MS2_REPLACE_METHOD(0x1419C7E20, UIItemEnchantDialog, FUN_1419c7e20, 144, 0x8DEEC429);
MS2_REPLACE_METHOD(0x1419C7EC0, UIItemEnchantDialog, FUN_1419c7ec0, 124, 0x8A08E7B7);
MS2_REPLACE_METHOD(0x1419C8020, UIItemEnchantDialog, FUN_1419c8020, 61, 0xED1B3BE4);
MS2_REPLACE_METHOD(0x1419C8070, UIItemEnchantDialog, FUN_1419c8070, 223, 0x791ACF47);
MS2_REPLACE_METHOD(0x1419C8160, UIItemEnchantDialog, FUN_1419c8160, 51, 0x5EC3538E);
MS2_REPLACE_METHOD(0x1419C86B0, UIItemEnchantDialog, FUN_1419c86b0, 373, 0x6160BCC0);
MS2_REPLACE_METHOD(0x1419C8830, UIItemEnchantDialog, FUN_1419c8830, 371, 0x835F76F0);
MS2_REPLACE_METHOD(0x1419C89B0, UIItemEnchantDialog, FUN_1419c89b0, 453, 0x213F73FA);
MS2_REPLACE_METHOD(0x1419C8B80, UIItemEnchantDialog, FUN_1419c8b80, 337, 0x6728CD4E);
MS2_REPLACE_METHOD(0x1419C9260, UIItemEnchantDialog, FUN_1419c9260, 307, 0xCED5AB88);
MS2_REPLACE_METHOD(0x1419C93A0, UIItemEnchantDialog, FUN_1419c93a0, 202, 0x0C6D37D6);
MS2_REPLACE_METHOD(0x1419C9490, UIItemEnchantDialog, FUN_1419c9490, 154, 0x4FD48B42);
MS2_REPLACE_METHOD(0x1419C9530, UIItemEnchantDialog, FUN_1419c9530, 239, 0xFFEEF296);
MS2_REPLACE_METHOD(0x1419C9630, UIItemEnchantDialog, FUN_1419c9630, 104, 0x8647A164);
MS2_REPLACE_METHOD(0x1419CA130, Unk_EnScript, FUN_1419ca130, 179, 0x97CB7D2C);
MS2_REPLACE_METHOD(0x1419CA1F0, Unk_EnScript, FUN_1419ca1f0, 178, 0xF9F572B2);
MS2_REPLACE_METHOD(0x1419CA850, UIItemEnchantDialog, vfunc_48, 11, 0x099F560B);
MS2_REPLACE_METHOD(0x1419CAE20, Unk_ItemEventSystem, FUN_1419cae20, 125, 0xEBE4410D);
MS2_REPLACE_METHOD(0x1419CAEB0, Unk_ItemEventSystem, FUN_1419caeb0, 131, 0x77EFEA86);
MS2_REPLACE_METHOD(0x1419CAF40, UIItemEventDispatcher, vfunc_1, 148, 0x25EFF991);
MS2_REPLACE_METHOD(0x1419CAFE0, UIItemEventDispatcher, vfunc_2, 159, 0x60C4FBE3);
MS2_REPLACE_METHOD(0x1419CB090, UIItemEventDispatcher, vfunc_3, 158, 0x0EE2A6EB);
MS2_REPLACE_METHOD(0x1419CB140, UIItemEventDispatcher, vfunc_4, 158, 0x01468249);
MS2_REPLACE_METHOD(0x1419CB1F0, UIItemEventDispatcher, vfunc_5, 148, 0xABB627DA);
MS2_REPLACE_METHOD(0x1419CB290, UIItemEventDispatcher, vfunc_6, 148, 0x77F1C037);
MS2_REPLACE_METHOD(0x1419CB330, UIItemEventDispatcher, vfunc_7, 148, 0x27E412E9);
MS2_REPLACE_METHOD(0x1419CB3D0, UIItemEventDispatcher, vfunc_8, 148, 0xE1066D02);
MS2_REPLACE_METHOD(0x1419CB470, UIItemEventDispatcher, vfunc_9, 148, 0x3DECEB13);
MS2_REPLACE_METHOD(0x1419CB510, UIItemEventDispatcher, vfunc_10, 148, 0x5AD18876);
MS2_REPLACE_METHOD(0x1419CB5B0, UIItemEventDispatcher, vfunc_11, 138, 0x9FF91611);
MS2_REPLACE_METHOD(0x1419CB640, UIItemEventDispatcher, vfunc_12, 138, 0x5072759B);
MS2_REPLACE_METHOD(0x1419CB6D0, UIItemEventDispatcher, vfunc_13, 148, 0x07D6C6C6);
MS2_REPLACE_METHOD(0x1419CB770, UIItemEventDispatcher, vfunc_14, 148, 0xFAE8F899);
MS2_REPLACE_METHOD(0x1419CB810, UIItemEventDispatcher, vfunc_15, 151, 0x44278524);
MS2_REPLACE_METHOD(0x1419CB8B0, UIItemEventDispatcher, vfunc_16, 161, 0xD13BDC3F);
MS2_REPLACE_METHOD(0x1419CB960, UIItemEventDispatcher, vfunc_17, 151, 0x14B56875);
MS2_REPLACE_METHOD(0x1419CBA00, UIItemEventDispatcher, vfunc_18, 151, 0xAECA19AC);
MS2_REPLACE_METHOD(0x1419CBAA0, UIItemEventDispatcher, vfunc_19, 151, 0xE76205D7);
MS2_REPLACE_METHOD(0x1419CBB40, UIItemEventDispatcher, vfunc_20, 151, 0xE5151B45);
MS2_REPLACE_METHOD(0x1419CBBE0, UIItemEventDispatcher, vfunc_21, 151, 0x4E3B816C);
MS2_REPLACE_METHOD(0x1419CBC80, UIItemEventDispatcher, vfunc_22, 151, 0x3178D7F3);
MS2_REPLACE_METHOD(0x1419CBD20, UIItemEventDispatcher, vfunc_23, 151, 0xEFB8229D);
MS2_REPLACE_METHOD(0x1419CBDC0, UIItemEventDispatcher, vfunc_24, 151, 0xB403CFA4);
MS2_REPLACE_METHOD(0x1419CBE60, UIItemEventDispatcher, vfunc_25, 149, 0xD28DC9E7);
MS2_REPLACE_METHOD(0x1419CBF00, UIItemEventDispatcher, vfunc_26, 149, 0xBDFA7A96);
MS2_REPLACE_METHOD(0x1419CBFA0, UIItemEventDispatcher, vfunc_27, 151, 0xEFFCAB85);
MS2_REPLACE_METHOD(0x1419CC040, UIItemEventDispatcher, vfunc_28, 151, 0x5666AD23);
MS2_REPLACE_METHOD(0x1419CC0E0, UIItemEventDispatcher, vfunc_29, 151, 0x0BF037C0);
MS2_REPLACE_METHOD(0x1419CC180, UIItemEventDispatcher, vfunc_30, 151, 0x3C85AD8D);
MS2_REPLACE_METHOD(0x1419CC220, UIItemEventDispatcher, vfunc_31, 174, 0x94CC1E81);
MS2_REPLACE_METHOD(0x1419CC2E0, UIItemEventDispatcher, vfunc_32, 159, 0xE350DD03);
