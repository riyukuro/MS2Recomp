// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Item breaking selection and requests.
// MS2-UNIT: commonfiles\itembreakmanager.cpp
// MS2-RANGE: 0x1400b9410-0x1400b9690 .text$di
// MS2-RANGE: 0x140530640-0x140535bc0 .text$mn
// MS2-RANGE: 0x142c9ab70-0x142c9ac70 .text$yd
// MS2-PIN: ??0?$Unk_BreakPtr@VCMsgBoxData@@@@QEAA@AEBV0@@Z 0x140534b80
// MS2-PIN: ??1?$Unk_BreakPtr@VCMsgBoxData@@@@QEAA@XZ 0x140534d60
// MS2-PIN: ??B?$Unk_BreakPtr@VCMsgBoxData@@@@QEBAPEAVCMsgBoxData@@XZ 0x140534fc0
// MS2-PIN: ??_G?$TSingleton@VCItemBreakManager@@@@UEAAPEAXI@Z 0x140535070
// MS2-PIN: ?FUN_1405352d0@UIItemBreakDialog@@QEAAHXZ 0x1405352d0
// MS2-PIN: ?Id@UIItemBreakDialog@@SAHXZ 0x140535330
// MS2-PIN: ??$Unk_BreakFind@_K@@YAHAEBV?$CAtlArray@_KV?$CElementTraits@_K@ATL@@@ATL@@AEB_K@Z 0x140534480
// MS2-PIN: ?GetAt@?$CAtlArray@_KV?$CElementTraits@_K@ATL@@@ATL@@QEBAAEB_K_K@Z 0x140534f70
// MS2-PIN: ??$Unk_BreakMessage@HH@@YAXHHHAEBH0@Z 0x140534110
// MS2-PIN: ?Invoke@?$DelegateImpl@U?$pair@PEAVCItemBreakManager@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEAA_NHAEBVCMsgBoxData@@@Z 0x1405359d0
// MS2-PIN: ??$Call@VCItemBreakManager@@P81@EAA_NHAEBVCMsgBoxData@@@Z@?$DelegateImpl@U?$pair@PEAVCItemBreakManager@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@CA_NAEAU?$pair@PEAVCItemBreakManager@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@HAEBVCMsgBoxData@@@Z 0x140535a10
// MS2-PIN: ??$Unk_BreakDialog@VUIItemBreakDialog@@@@YAPEAVUIItemBreakDialog@@XZ 0x140534630
// MS2-PIN: ?IsNull@?$MS2Ptr@VUIObject@@@@QEBA_NXZ 0x140534e80
// MS2-PIN: ??$Unk_BreakDialog@VUIInventoryDialog@@@@YAPEAVUIInventoryDialog@@H@Z 0x1405344f0
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVCItemBreakManager@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x140535970
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\itembreakmanager.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "itembreakmanager.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/ms2format.h"
#include <sstream>
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
static const CString s_breakSort[]={"None","Buy","PriceLow","PriceHigh","Create","ChartOrder","BuyTotal","EnumEnd"};
static const CString s_breakShopSort[]={"None","Buy","Like","PriceLow","PriceHigh","Create","EnumEnd"};
static UICommon::CMyPCKeyInputController s_breakKeys;
static const CString s_breakJob("jobCode");
static const CString s_breakSortValue("sortValue");
static const CString s_breakTab("tabIndex");
static const CString s_breakSound("Extract_ItemChoice");
class Unk_BreakTemplate {
public: int FUN_14053de40(); __int64 FUN_14053ea00(int); int FUN_14053cbc0();
    void* p0;
    void* p8;
    void* p10;
    void* p18;
    void* p20;
    void* p28;
    void* p30;
    void* p38;
    void* p40;
    void* p48;
    void* p50;
    void* p58;
    void* p60;
    void* p68;
    void* p70;
    void* p78;
    void* p80;
    void* p88;
    void* p90;
    void* p98;
    void* pa0;
    void* pa8;
    void* pb0;
    void* pb8;
    void* pc0;
    void* pc8;
    void* pd0;
    void* pd8;
    void* pe0;
    void* pe8;
    void* pf0;
    void* pf8;
    void* p100;
    void* p108;
    void* p110;
    void* p118;
    void* p120;
    void* p128;
    void* p130;
    unsigned short category;
};
class Unk_BreakEnhance { public: unsigned FUN_140620a20(); bool FUN_140622820(); };
class Unk_BreakItem {
public:
    Unk_BreakItemPtr FUN_140524250(); int FUN_1405257f0(); int FUN_1405258b0(); int FUN_140525f10(); int FUN_140526190();
    __int64 FUN_140526a50(); int FUN_140526bd0(); unsigned FUN_140526c50(); void FUN_140526c70(int);
    int FUN_140526fc0(); int FUN_1405270a0(); int FUN_140527270(); __int64 FUN_140527670(); int FUN_1405276c0(); unsigned short FUN_140527710();
    Unk_BreakTemplate* FUN_140527840(); Unk_BreakEnhance* FUN_1405279c0(); CStringW FUN_140527b10();
    __int64 FUN_140528b90(); unsigned FUN_140528bd0(); unsigned short FUN_140528c20(); int FUN_140528c60(); bool FUN_140528e20();
};
class Unk_BreakIngredient { public: void* p0; void* p8; void* p10; int p18,id; unsigned count; };
class Unk_BreakIngredients {
public: size_t FUN_14028b500() const; bool FUN_14028a8c0() const; MS2Ptr<Unk_BreakIngredient>& FUN_14027f1f0(size_t);
private: void* p0; void* p8; void* p10;
};
class CIngredientContainer {
public:
    CIngredientContainer(); ~CIngredientContainer();
    size_t FUN_14026bee0() const; bool FUN_14026bf40() const; MS2Ptr<Unk_BreakIngredient> FUN_14026bdc0(size_t);
    const Unk_BreakIngredients& FUN_14026c230() const; void FUN_14026c250(const CIngredientContainer&);
    void* p0; void* p8; void* p10; Unk_BreakIngredients ingredients;
};
MS2_CHECK_SIZE(CIngredientContainer,0x30);
class Unk_BreakFeature { public: bool FUN_14036d570(int); bool FUN_14036e5b0(); };
Unk_BreakFeature* FUN_140166410();
class Unk_BreakRecipe { public: void FUN_140677530(unsigned short,int,__int64,int,CIngredientContainer&); int FUN_140677910(); };
Unk_BreakRecipe* FUN_1401c0db0();
void FUN_140628390(int,unsigned short,int,CIngredientContainer&);
class Unk_BreakFlag { public: int FUN_1402c4c90(int); };
class Unk_BreakFlags { public: void* p0; Unk_BreakFlag flags; };
Unk_BreakFlags* FUN_14025e7b0();
class Unk_BreakSelected { public: __int64 FUN_140c8b2e0(); };
class Unk_BreakRules { public: int FUN_140613160(Unk_BreakItem*); };
class Unk_BreakRecipes { public: MS2Ptr<CIngredientContainer> FUN_14052e650(int); };
extern Unk_BreakRecipes* DAT_143aaf1e0;
extern Unk_BreakRules* DAT_143aaf308;
extern Unk_BreakSelected* DAT_143aaf310;
inline Unk_BreakRecipes* FUN_140535300() { return DAT_143aaf1e0; }
inline Unk_BreakRules* FUN_140535310() { return DAT_143aaf308; }
inline Unk_BreakSelected* FUN_140535320() { return DAT_143aaf310; }
bool FUN_140633bf0(Unk_BreakItemPtr);
class Unk_BreakInventory { public: Unk_BreakItemPtr FUN_140a5d680(__int64); };
extern Unk_BreakInventory DAT_143ab2a90;
class UIInventoryDialog : public UIDialog { public: void FUN_14199a3f0(__int64); };
class UIItemBreakDialog : public UIDialog {
public:
    virtual void vfunc_84(Unk_BreakPacket&); virtual void vfunc_85(bool,int); virtual int vfunc_86();
    void FUN_1419a1430(); void FUN_1419a1d20(int); void FUN_1419a4460(); void FUN_1419a44d0(Unk_BreakPacket&);
    int FUN_1405352d0() { return field188; }
    static int Id() { return 0x4e8d; }
    void* p178; void* p180; int field188;
};
class UIItemDonationDialog : public UIItemBreakDialog {};
class UIShopDialog : public UIDialog { public: void FUN_141afbd10(); };
class Unk_BreakUIManager { public: MS2Ptr<UIObject> FUN_141adcea0(int); };
Unk_BreakUIManager* FUN_1403ed2b0();
template<class T> inline T* Unk_BreakDialog(int id) {
    if(FUN_1403ed2b0()) { MS2Ptr<UIObject> p=FUN_1403ed2b0()->FUN_141adcea0(id); if(p.get()) return dynamic_cast<T*>(p.operator->()); }
    return 0;
}
template<class T> inline T* Unk_BreakDialog() {
    Unk_BreakUIManager* manager=FUN_1403ed2b0(); if(!manager) return 0; MS2Ptr<UIObject> p=manager->FUN_141adcea0(T::Id()); if(p.IsNull()) return 0; return dynamic_cast<T*>(p.operator->());
}
template<> inline bool MS2Ptr<UIObject>::IsNull() const { return m_p==0; }

template<class T> inline int Unk_BreakFind(const ATL::CAtlArray<T>& values,const T& value) {
    for(int i=0;i<(int)values.GetCount();++i) if(values.GetAt(i)==value) return i; return -1;
}
CStringW GetStringCommonByKey(const CStringW&);
void FUN_1412751f0(const CStringW&,int,int);
void FUN_141275260(int,int,int);
void FUN_141275460(int,int,int,const fmt::ArgList&);
void FUN_140d73aa0(CStringW,int,int,CStringW);
void FUN_141276180(const CString&,const CString&);
// These are message-display wrappers over fmt; StringFormat is used for string-returning wrappers.
template<class A,class B> inline void Unk_BreakMessage(int id,int a,int b,const A& x,const B& y) {
    const fmt::internal::ArgArray<2>::Type values={fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t>>(x),fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t>>(y)};
    FUN_141275460(id,a,b,fmt::ArgList(fmt::internal::make_type(x,y),values));
}
template<class A> inline void Unk_BreakMessage(int id,int a,int b,const A& x) {
    const fmt::internal::ArgArray<1>::Type values={fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t>>(x)};
    FUN_141275460(id,a,b,fmt::ArgList(fmt::internal::make_type(x),values));
}
enum Unk_BreakResult : int { Unk_BreakResultNone=0, Unk_BreakResultInvalid=1, Unk_BreakResultDonation=2, Unk_BreakResultFull=3, Unk_BreakResultCancelled=4, Unk_BreakResultEmpty=5 };
// fmt's ostream formatting of a custom argument with the MS2 enum shortcut in front (same shape as
// additionalactionadditional.cpp 0x140180790): the stream branch is dead code for enums.
// @0x140534820
template <> inline void fmt::format_arg(BasicFormatter<wchar_t>& f, const wchar_t*& format_str, const Unk_BreakResult& value)
{
    internal::Arg arg;
    internal::Value& arg_value = arg;
    if (std::is_enum<Unk_BreakResult>::value)
    {
        arg.int_value = value;
        arg.type = internal::Arg::INT;
    }
    else
    {
        std::basic_ostringstream<wchar_t> os;
        os << value;
        std::basic_string<wchar_t> str = os.str();
        arg_value = internal::MakeValue<BasicFormatter<wchar_t> >(str);
        arg.type = internal::Arg::STRING;
    }
    format_str = f.format(format_str, arg);
}
CStringW FUN_140719630(int); CStringW FUN_1407196b0(unsigned); CStringW FUN_140719a80(__int64);
class CMsgBoxData {
public:
    int FUN_141a02e50(int,int) const; __int64 FUN_141a02f10(int,__int64) const; CStringW FUN_141a02d50() const;
    void FUN_141a01d30(int,const CStringW&,unsigned,int,int);
    void FUN_141a027c0(Delegate<bool(int,const CMsgBoxData&)>);
    void FUN_141a01600(__int64); void FUN_141a01ee0(Unk_BreakItemPtr,const CStringW&,int,int,int,int,int); void FUN_141a01700(int,int,int);
    template<class T> void Append(T value);
    void* p0;
    void* p8;
    void* p10;
    void* p18;
    void* p20;
    void* p28;
    void* p30;
    void* p38;
    void* p40;
    void* p48;
    void* p50;
    void* p58;
    void* p60;
    void* p68;
    void* p70;
    void* p78;
    void* p80;
    void* p88;
    void* p90;
    void* p98;
    void* pa0;
    void* pa8;
    void* pb0;
    void* pb8;
    void* pc0;
    void* pc8;
    void* pd0;
    void* pd8;
    void* pe0;
    void* pe8;
    void* pf0;
    void* pf8;
    void* p100;
    void* p108;
    void* p110;
    void* p118;
    void* p120;
    void* p128;
    void* p130;
    void* p138;
    void* p140;
    void* p148;
    void* p150;
    void* p158;
    void* p160;
    void* p168;
    void* p170;
    void* p178;
    void* p180;
    void* p188;
    void* p190;
    void* p198;
    void* p1a0;
    void* p1a8;
    void* p1b0;
    void* p1b8;
    void* p1c0;
    void* p1c8;
    void* p1d0;
    void* p1d8;
    void* p1e0;
    void* p1e8;
    void* p1f0;
    void* p1f8;
    void* p200;
    void* p208;
    void* p210;
    void* p218;
    void* p220;
    ATL::CAtlArray<CStringW> args;
};
MS2_CHECK_OFFSET(CMsgBoxData,args,0x228);
MS2_CHECK_OFFSET(Unk_BreakTemplate,category,0x138);
MS2_CHECK_OFFSET(Unk_BreakIngredient,count,0x20);
template<> inline void CMsgBoxData::Append(int v) { args.Add(FUN_140719630(v)); }
template<> inline void CMsgBoxData::Append(unsigned v) { args.Add(FUN_1407196b0(v)); }
template<> inline void CMsgBoxData::Append(__int64 v) { args.Add(FUN_140719a80(v)); }
Unk_BreakPtr<CMsgBoxData> FUN_140d73d20(int,CStringW,int,CStringW);
void FUN_140d73c60(Unk_BreakPtr<CMsgBoxData>);
int FUN_141902660(Unk_BreakItemPtr);
void FUN_1409e4950(Unk_BreakItemPtr,CStringW&,char*);
// @0x140530640
ItemBreakCommon::BreakItem::BreakItem() : id(0),count(0) {}
// @0x140530690
ItemBreakCommon::BreakItem::BreakItem(__int64 value,int n) : id(value),count(n) {}
// @0x1405306f0
void ItemBreakCommon::BreakItem::FUN_1405306f0() { id=0; count=0; }
MS2_REPLACE_METHOD(0x1405306F0, ItemBreakCommon::BreakItem, FUN_1405306f0, 31, 0xC0018581);
// @0x140530720
void ItemBreakCommon::BreakItem::FUN_140530720(__int64 value,int n) { id=value; count=n; }
MS2_REPLACE_METHOD(0x140530720, ItemBreakCommon::BreakItem, FUN_140530720, 42, 0x3380BA5F);
// @0x140530750
bool ItemBreakCommon::BreakItem::FUN_140530750() const { return id==0 || count==0; }
MS2_REPLACE_METHOD(0x140530750, ItemBreakCommon::BreakItem, FUN_140530750, 57, 0x5FB297E2);
// @0x140530790
ItemBreakCommon::BreakPreview::BreakPreview() : low(0),high(0) {}
// @0x1405307e0
ItemBreakCommon::BreakPreview ItemBreakCommon::BreakPreview::FUN_1405307e0(const Unk_PreviewAmount& value) { low+=value.low; high+=value.high; return *this; }
// @0x140530860
ItemBreakCommon::BreakPreview ItemBreakCommon::BreakPreview::FUN_140530860(int value) { low+=value; high+=value; return *this; }
// @0x1405308d0
void ItemBreakCommon::BreakPreview::FUN_1405308d0(Unk_BreakOutput& out) const { out.vfunc_3(low); out.vfunc_3(high); }
MS2_REPLACE_METHOD(0x1405308D0, ItemBreakCommon::BreakPreview, FUN_1405308d0, 67, 0xC1CB15E0);
// @0x140530920
void ItemBreakCommon::BreakPreview::FUN_140530920(Unk_BreakPacket& packet) { low=(&packet.input)->vfunc_3(); high=(&packet.input)->vfunc_3(); }
MS2_REPLACE_METHOD(0x140530920, ItemBreakCommon::BreakPreview, FUN_140530920, 103, 0x6067A3F8);
// @0x140530990
int ItemBreakCommon::BreakPreview::FUN_140530990() const { return low!=high ? 1 : 0; }
MS2_REPLACE_METHOD(0x140530990, ItemBreakCommon::BreakPreview, FUN_140530990, 51, 0x926A6D5B);
// @0x1405309d0
int ItemBreakCommon::BreakPreview::FUN_1405309d0() const { return low==0 && high==0 ? 0 : 1; }
MS2_REPLACE_METHOD(0x1405309D0, ItemBreakCommon::BreakPreview, FUN_1405309d0, 55, 0xBE5FA642);
// @0x140530a10
int ItemBreakCommon::FUN_140530a10(const Items& items,__int64 id) {
    if(items.IsEmpty()) return -1; { int count=(int)items.GetCount(); for(int i=0;i<count;++i) { Ptr p=items.GetAt(i); if(p==0) continue; if(p->id==id) return i; } }
    return -1;
}
MS2_REPLACE(0x140530A10, ItemBreakCommon::FUN_140530a10, 227, 0x0C480375);
// @0x140530b00
void ItemBreakCommon::FUN_140530b00(Items& items,unsigned count) { items.RemoveAll(); items.SetCount(count); }
MS2_REPLACE(0x140530B00, ItemBreakCommon::FUN_140530b00, 50, 0x7804D9FF);
// Hook deferred: allocating BreakItem would expose DLL-local vftables.
// @0x140530b40
bool ItemBreakCommon::FUN_140530b40(Items& items,int index,__int64 id,int count) {
    if(index<0 || index>=(int)items.GetCount()) return false; Ptr p=static_cast<const Items&>(items).GetAt(index); if(p.get()) p->FUN_140530720(id,count); else { Ptr next(new BreakItem(id,count)); items.SetAt(index,next); } return true;
}
// MS2-FUNCTIONAL: 734 unmasked bytes differ (length 1027 vs 1004); temps/frame layout, not hooked
// @0x140530c90
void FUN_140530c90(MS2Ptr<Unk_BreakTemplate> item,int grade,int enhance,CIngredientContainer& output) {
    if(item==0) return;
    if(!FUN_140166410()->FUN_14036d570(0x3a)) return;
    int level=item->FUN_14053de40(); if(!level) return;
    unsigned short category=item->category;
    __int64 value=item->FUN_14053ea00(grade);
    FUN_1401c0db0()->FUN_140677530(category,grade,value,level,output);
    if(enhance>0) {
        CIngredientContainer extra; FUN_140628390(grade,category,level,extra);
        if(!extra.FUN_14026bf40()) {
            int percent=FUN_1401c0db0()->FUN_140677910();
            for(size_t i=0;i<extra.FUN_14026bee0();++i) { MS2Ptr<Unk_BreakIngredient> p=extra.FUN_14026bdc0(i); if(p==0) continue;
                unsigned amount=(p->count*percent)/100==0?1:(p->count*percent)/100; if(percent==0) amount=0; p->count=amount*enhance;
            }
            for(size_t i=0;i<output.ingredients.FUN_14028b500();++i) for(size_t j=0;j<extra.FUN_14026bee0();++j) {
                MS2Ptr<Unk_BreakIngredient> p=extra.FUN_14026bdc0(j); if(p==0) continue;
                Unk_BreakIngredient* ingredient=output.ingredients.FUN_14027f1f0(i).operator->();
                if(ingredient->id==p->id) { output.ingredients.FUN_14027f1f0(i)->count+=p->count; p->count=0; }
            }
            output.FUN_14026c250(extra);
        }
    }
}
// @0x140531090
void FUN_140531090(Unk_BreakItemPtr item,CIngredientContainer& output) {
    if(item==0 || item->FUN_1405279c0()==0) return; FUN_140530c90(MS2Ptr<Unk_BreakTemplate>(item->FUN_140527840()),item->FUN_140526bd0(),item->FUN_1405279c0()->FUN_140620a20(),output);
}
// @0x140531180
CItemBreakManager::CItemBreakManager() : type(0) { pending.RemoveAll(); ItemBreakCommon::FUN_140530b00(items,100); }
// @0x140531220
CItemBreakManager::~CItemBreakManager() {}
// @0x140531270
int CItemBreakManager::FUN_140531270(ItemPtr item) {
    if(!item) return 0; if(item->FUN_140528e20()==true) return 0;
    if(FUN_140531510(item)==1) return 1;
    if(!FUN_140531630(item)) return 0; if(!FUN_140633bf0(item)) return 0; if(!FUN_140531850(item)) return 0;
    if(item->FUN_140525f10()!=0) { if(FUN_140166410()->FUN_14036e5b0()) { if(item->FUN_1405279c0()!=0 && item->FUN_1405279c0()->FUN_140620a20()>0) return 0; } }
    return 1;
}
MS2_REPLACE_METHOD(0x140531270, CItemBreakManager, FUN_140531270, 653, 0xB1394540);
// @0x140531510
int CItemBreakManager::FUN_140531510(ItemPtr item) {
    MS2Ptr<Unk_BreakTemplate> data(item->FUN_140527840()); if(data==0) return 0;
    if(item->FUN_140526190()==1) { if(FUN_14025e7b0()->flags.FUN_1402c4c90(0x71)!=0) return 0; return 1; } return 0;
}
MS2_REPLACE_METHOD(0x140531510, CItemBreakManager, FUN_140531510, 269, 0x665F5D7D);
// @0x140531630
int CItemBreakManager::FUN_140531630(ItemPtr item) { unsigned __int64 id=FUN_140535320()->FUN_140c8b2e0(); if(id==0) return 1; if(id==item->FUN_140526a50()) return 0; return 1; }
MS2_REPLACE_METHOD(0x140531630, CItemBreakManager, FUN_140531630, 149, 0x879E8F78);
// @0x1405316d0
bool CItemBreakManager::FUN_1405316d0(ItemPtr item) {
    if(item->FUN_140526fc0()>0) return true; if(item->FUN_1405270a0()>0) return true; if(item->FUN_140527270()>0) return true;
    if(item->FUN_140528c20()>1) return true; if(item->FUN_140528b90()>0) return true; if(item->FUN_140528bd0()>0) return true; if(item->FUN_140528c60()!=0) return true; return false;
}
MS2_REPLACE_METHOD(0x1405316D0, CItemBreakManager, FUN_1405316d0, 373, 0x79429692);
// @0x140531850
bool CItemBreakManager::FUN_140531850(ItemPtr item) {
    if(item==0) return false; if(!item->FUN_1405258b0()) return true;
    MS2Ptr<CIngredientContainer> p=FUN_140535300()->FUN_14052e650(item->FUN_1405276c0());
    if(p.get()) { const Unk_BreakIngredients& list=p->FUN_14026c230(); if(!list.FUN_14028a8c0()) return true; }
    int level=item->FUN_140527840()->FUN_14053de40(); if(level) {
        unsigned short category=item->FUN_140527710(); int grade=item->FUN_140526bd0(); __int64 value=item->FUN_140527670(); CIngredientContainer result;
        FUN_1401c0db0()->FUN_140677530(category,grade,value,level,result); if(!result.ingredients.FUN_14028a8c0()) return true;
    } return false;
}
MS2_REPLACE_METHOD(0x140531850, CItemBreakManager, FUN_140531850, 571, 0xE5EDB101);
// @0x140531aa0
int CItemBreakManager::FUN_140531aa0(ItemPtr item) { if(!FUN_140531270(item)) return 0; if(ItemBreakCommon::FUN_140530a10(items,item->FUN_140526a50())!=-1) return 0; return 1; }
MS2_REPLACE_METHOD(0x140531AA0, CItemBreakManager, FUN_140531aa0, 187, 0x4B7E2A6A);
// @0x140531b70
int CItemBreakManager::FUN_140531b70() {
    if(type==0) { MS2_ASSERT_AT(1642,"m_type != ItemBreakTypeNone" && 0); return 0; }
    UIItemBreakDialog* a=Unk_BreakDialog<UIItemBreakDialog>(0x4e8d); if(a && a->FUN_141924630()) return 1;
    UIItemDonationDialog* b=Unk_BreakDialog<UIItemDonationDialog>(0x4e8e); if(b && b->FUN_141924630()) return 1; return 0;
}
MS2_REPLACE_METHOD(0x140531B70, CItemBreakManager, FUN_140531b70, 165, 0xC7E57465);
// @0x140531c20
void CItemBreakManager::SendItemDismantleMode0(int value) { type=value; pending.RemoveAll(); ItemBreakCommon::FUN_140530b00(items,100); COutPacket packet(static_cast<int>(SendOp::ItemDismantle),0); packet.Encode1(0); packet.Encode1((unsigned char)type); FUN_140710590(packet); }
MS2_REPLACE_METHOD(0x140531C20, CItemBreakManager, SendItemDismantleMode0, 149, 0xDC547EA6);
// @0x140531cc0
void CItemBreakManager::FUN_140531cc0() { SendItemDismantleMode0(0); }
MS2_REPLACE_METHOD(0x140531CC0, CItemBreakManager, FUN_140531cc0, 26, 0x3DB3E087);
// MS2-FUNCTIONAL: clone return: exe copies the item handle into the sret (no move) and indexes via operator[] temps
// @0x140531ce0
CItemBreakManager::ItemPtr CItemBreakManager::FUN_140531ce0(int index) {
    if(index<0 || index>=(int)items.GetCount()) return ItemPtr(0);
    ItemBreakCommon::Ptr p=items[index]; if(p==0) return ItemPtr(0);
    ItemPtr item=DAT_143ab2a90.FUN_140a5d680(p->id); if(item==0) return ItemPtr(0);
    int count=p->count; ItemPtr clone=item->FUN_140524250(); clone->FUN_140526c70(count); return std::move(clone);
}
// @0x140531ed0
void CItemBreakManager::FUN_140531ed0() {
    for(size_t i=0;i<items.GetCount();++i) { ItemBreakCommon::Ptr p=items[i]; if(p==0 || p->FUN_140530750()) continue;
        unsigned __int64 id=p->id; ItemPtr item=DAT_143ab2a90.FUN_140a5d680(id); if(item==0) { if(Unk_BreakFind(pending,id)==-1) {
            COutPacket packet(static_cast<int>(SendOp::ItemDismantle),0); packet.Encode1(2); packet.FUN_14020ae50(id); FUN_140710590(packet); pending.Add(id);
        } }
    }
}
MS2_REPLACE_METHOD(0x140531ED0, CItemBreakManager, FUN_140531ed0, 392, 0x2F50DB8C);
// @0x140532060
void CItemBreakManager::FUN_140532060() {
    switch(type) { case 1: { UIItemBreakDialog* p=Unk_BreakDialog<UIItemBreakDialog>(0x4e8d); if(p) p->FUN_1419a1430(); } break;
    case 2: { UIItemDonationDialog* p=Unk_BreakDialog<UIItemDonationDialog>(0x4e8e); if(p) p->FUN_1419a1430(); }
    }
}
MS2_REPLACE_METHOD(0x140532060, CItemBreakManager, FUN_140532060, 110, 0x1A85706E);
// @0x1405320e0
void CItemBreakManager::FUN_1405320e0(int index) {
    switch(type) { case 1: { UIItemBreakDialog* p=Unk_BreakDialog<UIItemBreakDialog>(0x4e8d); if(p) p->FUN_1419a1d20(index); } break;
    case 2: { UIItemDonationDialog* p=Unk_BreakDialog<UIItemDonationDialog>(0x4e8e); if(p) p->FUN_1419a1d20(index); }
    }
}
MS2_REPLACE_METHOD(0x1405320E0, CItemBreakManager, FUN_1405320e0, 122, 0x94B746AD);
// @0x140532160
void CItemBreakManager::FUN_140532160(Unk_BreakPacket& packet) {
    switch(type) { case 1: { UIItemBreakDialog* p=Unk_BreakDialog<UIItemBreakDialog>(0x4e8d); if(p) p->vfunc_84(packet);
        UIShopDialog* shop=Unk_BreakDialog<UIShopDialog>(0x4e3b); if(shop) shop->FUN_141afbd10(); } break;
    case 2: { UIItemDonationDialog* p=Unk_BreakDialog<UIItemDonationDialog>(0x4e8e); if(p) p->vfunc_84(packet); }
    }
}
MS2_REPLACE_METHOD(0x140532160, CItemBreakManager, FUN_140532160, 179, 0x46F57F72);
// @0x140532220
void CItemBreakManager::FUN_140532220() {
    switch(type) { case 1: { UIItemBreakDialog* p=Unk_BreakDialog<UIItemBreakDialog>(0x4e8d); if(p) p->vfunc_85(1,0); } break;
    case 2: { UIItemDonationDialog* p=Unk_BreakDialog<UIItemDonationDialog>(0x4e8e); if(p) p->vfunc_85(1,0); }
    }
}
MS2_REPLACE_METHOD(0x140532220, CItemBreakManager, FUN_140532220, 138, 0xD7B9754F);
// MS2-FUNCTIONAL: 1282 unmasked bytes differ; branch layout/temps, not hooked
// @0x1405322b0
void CItemBreakManager::FUN_1405322b0(Unk_BreakPacket& packet) {
    if(!FUN_140531b70()) return;
    unsigned char mode=(&packet.input)->vfunc_1();
    if(mode==1) {
        unsigned __int64 id=(&packet.input)->vfunc_4(); int index=(&packet.input)->vfunc_2(); int count=(&packet.input)->vfunc_3();
        if(index>=0 && index<100) { ItemPtr item=DAT_143ab2a90.FUN_140a5d680(id); if(item.get()) { ItemBreakCommon::FUN_140530b40(items,index,id,count); FUN_1405320e0(index); FUN_141276180(s_breakSound,""); }
            UIInventoryDialog* p=Unk_BreakDialog<UIInventoryDialog>(0x4e2d); if(p) p->FUN_14199a3f0(id);
        }
    } else if(mode==2) {
        unsigned __int64 id=(&packet.input)->vfunc_4(); int index=ItemBreakCommon::FUN_140530a10(items,id);
        if(index>=0) { ItemBreakCommon::Ptr p=items[index]; if(p.get()) p->FUN_1405306f0(); }
        for(size_t i=0;i<pending.GetCount();++i) if(pending.GetAt(i)==id) { pending.GetAt(i)=0; break; }
        FUN_1405320e0(index); UIInventoryDialog* p=Unk_BreakDialog<UIInventoryDialog>(0x4e2d); if(p) p->FUN_14199a3f0(id);
    } else if(mode==3) {
        int value=(&packet.input)->vfunc_1(); if(type==value) { ItemBreakCommon::FUN_140530b00(items,100); FUN_140532160(packet); FUN_140532060(); }
        else { MS2_ASSERT_AT(1306,"m_type == type" && 0); }
    } else if(mode==4) {
        Unk_BreakResult result=(Unk_BreakResult)(&packet.input)->vfunc_3();
        if(result==1) FUN_141275260(0x8f6,1,1);
        else if(result==2) FUN_141275260(0x8f7,1,1);
        else if(result==3) FUN_141275260(0x43,1,1);
        else if(result!=4) { if(result==5) FUN_1412751f0(GetStringCommonByKey(L"s_itembreak_empty"),1,1); else Unk_BreakMessage(0x8f8,1,1,result); }
        UIItemBreakDialog* p=Unk_BreakDialog<UIItemBreakDialog>(); if(p && p->FUN_1405352d0()) p->FUN_1419a4460(); FUN_140532220();
    } else if(mode==5) {
        UIItemBreakDialog* p=Unk_BreakDialog<UIItemBreakDialog>(); if(p) p->FUN_1419a44d0(packet);
    } else if(mode==6) {
        UIInventoryDialog* p=Unk_BreakDialog<UIInventoryDialog>(0x4e2d); unsigned count=(&packet.input)->vfunc_3();
        for(unsigned i=0;i<count;++i) { int index=(&packet.input)->vfunc_2(); unsigned __int64 id=(&packet.input)->vfunc_4(); int amount=(&packet.input)->vfunc_3();
            if(index<0) return; if(index>99) return; ItemPtr item=DAT_143ab2a90.FUN_140a5d680(id);
            if(item.get()) { ItemBreakCommon::FUN_140530b40(items,index,id,amount); FUN_1405320e0(index); } if(p) p->FUN_14199a3f0(id);
        }
        if(count!=0) FUN_141276180(s_breakSound,"");
    }
}
// @0x140532ab0
int CItemBreakManager::FUN_140532ab0() {
    switch(type) { case 1: { UIItemBreakDialog* p=Unk_BreakDialog<UIItemBreakDialog>(0x4e8d); if(p && p->FUN_141924630()) return p->vfunc_86(); } break;
    case 2: { UIItemDonationDialog* p=Unk_BreakDialog<UIItemDonationDialog>(0x4e8e); if(p && p->FUN_141924630()) return p->vfunc_86(); }
    } return 0;
}
MS2_REPLACE_METHOD(0x140532AB0, CItemBreakManager, FUN_140532ab0, 162, 0x5FF33FB6);
// @0x140532b60
int CItemBreakManager::FUN_140532b60() {
    for(size_t i=0;i<items.GetCount();++i) { ItemBreakCommon::Ptr p=items[i]; if(p==0 || p->FUN_140530750()) continue; return 1; } return 0;
}
MS2_REPLACE_METHOD(0x140532B60, CItemBreakManager, FUN_140532b60, 192, 0xFD11FFEE);
// @0x140532c30
int CItemBreakManager::FUN_140532c30() {
    int grade=0; for(size_t i=0;i<items.GetCount();++i) { ItemBreakCommon::Ptr p=items[i]; if(p==0 || p->FUN_140530750()) continue;
        ItemPtr item=DAT_143ab2a90.FUN_140a5d680(p->id); if(!item) continue; if(item->FUN_140526bd0()>grade) grade=item->FUN_140526bd0();
    } return grade;
}
MS2_REPLACE_METHOD(0x140532C30, CItemBreakManager, FUN_140532c30, 329, 0x048AC1F8);
// @0x140532d80
int CItemBreakManager::SendItemDismantleMode3() { COutPacket packet(static_cast<int>(SendOp::ItemDismantle),0); packet.Encode1(3); FUN_140710590(packet); return 1; }
MS2_REPLACE_METHOD(0x140532D80, CItemBreakManager, SendItemDismantleMode3, 86, 0xCDB63F78);
// MS2-FUNCTIONAL: 300 unmasked bytes differ; temp ordering, not hooked
// @0x140532de0
int CItemBreakManager::FUN_140532de0(ItemPtr item,int arg) {
    if(item==0) return 0;
    if(FUN_140535310() && !FUN_140535310()->FUN_140613160(item.get())) return 0;
    if(ItemBreakCommon::FUN_140530a10(items,item->FUN_140526a50())!=-1) { FUN_1412751f0(GetStringCommonByKey(L"s_itembreak_selected_item"),1,1); return 0; }
    Unk_BreakEnhance* enhance=item->FUN_1405279c0(); if(enhance && !enhance->FUN_140622820()) { FUN_140d73aa0(GetStringCommonByKey(L"s_itembreak_usedgemstone_item"),0,0,L""); return 0; }
    if(type==2) { if(!FUN_140531270(item)) { FUN_141275260(0x8f7,1,1); return 0; }
        if(!item->FUN_140527840()->FUN_14053cbc0() && !item->FUN_1405258b0()) { FUN_141275260(0x8f7,1,1); return 0; }
    } else if(!FUN_140531270(item)) { FUN_141275260(0x8f6,1,1); return 0; }
    FUN_140533440(item,arg); return 1;
}
// @0x140533210
void CItemBreakManager::SendItemDismantleMode1(__int64 id,int count,int arg) { COutPacket packet(static_cast<int>(SendOp::ItemDismantle),0); packet.Encode1(1); packet.Encode4(arg); packet.FUN_14020ae50(id); packet.Encode4(count); FUN_140710590(packet); }
MS2_REPLACE_METHOD(0x140533210, CItemBreakManager, SendItemDismantleMode1, 139, 0x0CBD71F0);
// @0x1405332b0
void CItemBreakManager::SendItemDismantleMode6(int a,int b) { if(!FUN_140532ab0()) return; { COutPacket packet(static_cast<int>(SendOp::ItemDismantle),0); packet.Encode1(6); packet.Encode1((unsigned char)a); packet.Encode1((unsigned char)b); FUN_140710590(packet); } }
MS2_REPLACE_METHOD(0x1405332B0, CItemBreakManager, SendItemDismantleMode6, 133, 0xB5BB3AAC);
// @0x140533340
int CItemBreakManager::FUN_140533340(ItemPtr item) {
    if(!FUN_140531270(item)) { FUN_141275260(0x8f6,1,1); return 0; } COutPacket packet(static_cast<int>(SendOp::ItemDismantle),0); packet.Encode1(2); packet.FUN_14020ae50(item->FUN_140526a50()); FUN_140710590(packet); return 1;
}
MS2_REPLACE_METHOD(0x140533340, CItemBreakManager, FUN_140533340, 248, 0x31B0FB01);
// MS2-FUNCTIONAL: 1203 unmasked bytes differ; CMsgBoxData temps/frame slots, not hooked
// @0x140533440
void CItemBreakManager::FUN_140533440(ItemPtr item,int arg) {
    if(item==0) return; if(FUN_141902660(item)!=0) return;
    if(item->FUN_1405257f0()!=0 && item->FUN_140526c50()>1) {
        if(Unk_BreakPtr<CMsgBoxData> box=FUN_140d73d20(5,GetStringCommonByKey(L"s_msg_item_break"),0,L"")) {
            unsigned count=item->FUN_140526c50(); CStringW text; text.Format(L"%d",(unsigned __int64)count);
            box->FUN_141a01d30(1,text,count,0,0);
            box->FUN_141a027c0(Delegate<bool(int,const CMsgBoxData&)>(this,&CItemBreakManager::FUN_140533c60));
            box->Append(arg); box->Append(item->FUN_140526a50()); box->Append((int)count); FUN_140d73c60(box);
        }
    } else {
        CStringW option; char flag=0; FUN_1409e4950(item,option,&flag);
        if(item->FUN_140526bd0()<5 || flag!=1) SendItemDismantleMode1(item->FUN_140526a50(),item->FUN_140526c50(),arg);
        else {
            CStringW warning=GetStringCommonByKey(L"s_itembreak_high_sa_option_item"); CStringW text; text.Append(option); text.Append(L"\n"); text.Append(warning);
            Unk_BreakPtr<CMsgBoxData> box=FUN_140d73d20(0x11,text,0,L"");
            if(box) { box->FUN_141a027c0(Delegate<bool(int,const CMsgBoxData&)>(this,&CItemBreakManager::FUN_140533da0));
                box->FUN_141a01600(item->FUN_140526a50()); box->FUN_141a01ee0(item,item->FUN_140527b10(),1,0,-1,-1,1); box->FUN_141a01700(0x475,0x476,0);
                box->Append(arg); box->Append(item->FUN_140526a50()); box->Append(item->FUN_140526c50()); FUN_140d73c60(box);
            }
        }
    }
}
// MS2-FUNCTIONAL: callback: exe keeps an extra count temp and returns int-sized flag; same calls and arguments
// @0x140533c60
bool CItemBreakManager::FUN_140533c60(int result,const CMsgBoxData& box) {
    if(result==0) { int arg=box.FUN_141a02e50(0,0); unsigned __int64 id=box.FUN_141a02f10(1,0); int max=box.FUN_141a02e50(2,0); int count=_wtoi(box.FUN_141a02d50().Trim(L','));
        if(count==0 || max<count) { int min=1; Unk_BreakMessage(0xee,1,1,min,max); return false; } SendItemDismantleMode1(id,count,arg);
    } return true;
}
// @0x140533da0
bool CItemBreakManager::FUN_140533da0(int result,const CMsgBoxData& box) {
    if(result==0) { int arg=box.FUN_141a02e50(0,0); unsigned __int64 id=box.FUN_141a02f10(1,0); int count=box.FUN_141a02e50(2,0); SendItemDismantleMode1(id,count,arg); } return true;
}
MS2_REPLACE_METHOD(0x140533DA0, CItemBreakManager, FUN_140533da0, 121, 0x0F93C2D3);
// @0x140533e20
unsigned CItemBreakManager::FUN_140533e20() { unsigned index=0; for(size_t i=0;i<items.GetCount();++i) { if(items[i]==0) continue; index=(unsigned)i; } return index; }
MS2_REPLACE_METHOD(0x140533E20, CItemBreakManager, FUN_140533e20, 125, 0x4181B233);







// The shared Delegate supplies the bound-member implementation; its base is first emitted here.
// @0x140534c50
template<> Delegate<bool(int,const CMsgBoxData&)>::DelegateImplBase::DelegateImplBase() {}
// @0x140534cb0
template<> Delegate<bool(int,const CMsgBoxData&)>::~Delegate() { if(m_pImpl) delete m_pImpl; }
// @0x140534df0
template<> Delegate<bool(int,const CMsgBoxData&)>::DelegateImplBase::~DelegateImplBase() {}
MS2_EMIT_CRT_MEMMOVE_S();
