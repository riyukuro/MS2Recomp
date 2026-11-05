// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Item breaking selection and requests.
// MS2-UNIT: commonfiles\itembreakmanager.cpp
// MS2-RANGE: 0x1400b9410-0x1400b9690 .text$di
// MS2-RANGE: 0x140530640-0x140535bc0 .text$mn
// MS2-RANGE: 0x142c9ab70-0x142c9ac70 .text$yd
// MS2-PIN: ??0?$MS2Ptr@VCMsgBoxData@@@@QEAA@AEBV0@@Z 0x140534b80
// MS2-PIN: ??1?$MS2Ptr@VCMsgBoxData@@@@QEAA@XZ 0x140534d60
// MS2-PIN: ??B?$MS2Ptr@VCMsgBoxData@@@@QEBAPEAVCMsgBoxData@@XZ 0x140534fc0
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
#include "ms2/commonfiles/featuremanager.h"
#include "ms2/commonfiles/itemsocket.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/citemdata.h"  // C3: CItemData members
#include "ms2/commonfiles/luautil.h"
#include "ms2/placeholder/ms2ptr_impl.h"  // C3: MS2Ptr<CMsgBoxData> bodies (COMDATs 0x140534b80..0x140535920)
#include "ms2/client/ms2/uimessageboxdata.h"  // C3: the real CMsgBoxData (was a unit-local 0x2a0 view, args at +0x228)
#include "ms2/placeholder/cpetmanager.h"
#include "ms2/client/ms2/uiservice.h"
#include "ms2/commonfiles/item.h"   // C3: CItemBreakIngredientTable::GetBreakItem
static const CString s_breakSort[]={"None","Buy","PriceLow","PriceHigh","Create","ChartOrder","BuyTotal","EnumEnd"};
static const CString s_breakShopSort[]={"None","Buy","Like","PriceLow","PriceHigh","Create","EnumEnd"};
static UICommon::CMyPCKeyInputController s_breakKeys;
static const CString s_breakJob("jobCode");
static const CString s_breakSortValue("sortValue");
static const CString s_breakTab("tabIndex");
static const CString s_breakSound("Extract_ItemChoice");
class Unk_BreakTemplate {
public:   // C3: GetSkinType, GetSellPrice, FUN_14053cbc0 are CItemData's (cast at the call)
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
class Unk_BreakEnhance : public CItemSocket { };
class CIngredientInfo;
template <> MS2Ptr<CIngredientInfo>::~MS2Ptr();   // C3: defined elsewhere (CIngredientInfo is incomplete here; keeps ms2ptr_impl.h from instantiating it)
class Unk_BreakIngredient { public: void* p0; void* p8; void* p10; int p18,id; unsigned count; };
class Unk_BreakIngredients {
    // C3: size/empty/operator[] are std::vector<MS2Ptr<CIngredientInfo>>'s
private: void* p0; void* p8; void* p10;
};
class CIngredientContainer : public CPtred {
public:
    CIngredientContainer(); virtual ~CIngredientContainer();
    size_t FUN_14026bee0(); bool FUN_14026bf40(); MS2Ptr<CIngredientInfo> FUN_14026bdc0(size_t);
    class Unk_IngVec* FUN_14026c230(); void FUN_14026c250(CIngredientContainer*);
    Unk_BreakIngredients ingredients;
};
MS2_CHECK_SIZE(CIngredientContainer,0x30);
class Unk_BreakRecipe : public CLua { };
class Unk_BmPriceMgr* FUN_1401c0db0();   // C3: was FUN_1401c0db0
void FUN_140628390(int,unsigned short,int,CIngredientContainer*);
class CContentShutdown { public: enum Content {}; int Get(Content); };   // C3: member view
class Unk_BreakFlags { public: void* p0; CContentShutdown flags; };
struct Unk_BanConfig* FUN_14025e7b0();   // C3: was FUN_14025e7b0
class Unk_BreakSelected : public CPetManager { };
class Unk_BreakRules { public: };
class CItemLockManager { public: int FUN_140613160(CItem* pItem); };   // C3: unit-local view (unit_1406125d0.h)
class CItemBreakIngredientTable;
class CItemLockManager;
class CPetManager;
class Unk_BreakRecipes;
inline Unk_BreakRecipes* FUN_140535300() { return reinterpret_cast<Unk_BreakRecipes*>(TSingleton<CItemBreakIngredientTable>::s_instance); }
inline Unk_BreakRules* FUN_140535310() { return reinterpret_cast<Unk_BreakRules*>(TSingleton<CItemLockManager>::s_instance); }
inline Unk_BreakSelected* FUN_140535320() { return reinterpret_cast<Unk_BreakSelected*>(TSingleton<CPetManager>::s_instance); }
bool FUN_140633bf0(Unk_BreakItemPtr);
class Unk_Inventory { public: MS2Ptr<CItem> FUN_140a5d680(__int64); };   // C3: minimal view (was Unk_BreakInventory)
extern Unk_Inventory g_143ab2a90;   // C3: the real global (0x143ab2a90)
class UIInventoryDialog : public UIDialog { public: void FUN_14199a3f0(__int64); };
class UIItemBreakBase : public UIDialog { public: void FUN_1419a1430(); void FUN_1419a1d20(int); };   // C3: member view
class UIItemBreakDialog : public UIItemBreakBase {
public:
    virtual void vfunc_84(Unk_BreakPacket&); virtual void vfunc_85(bool,int); virtual int vfunc_86();
    void ResetBreak(); void FUN_1419a44d0(class CInPacket*);
    int FUN_1405352d0() { return field188; }
    static int Id() { return 0x4e8d; }
    void* p178; void* p180; int field188;
};
class UIItemBreakDonationDialog : public UIItemBreakDialog {};
class UIShopDialog : public UIDialog { public: void UpdateGachaCoin(); };
template<class T> inline T* Unk_BreakDialog(int id) {
    if(TSingleton<CUIService>::GetInstance()) { MS2Ptr<UIObject> p=TSingleton<CUIService>::GetInstance()->FindObject((eUIClassID)id); if(p.get()) return dynamic_cast<T*>(p.operator->()); }
    return 0;
}
template<class T> inline T* Unk_BreakDialog() {
    CUIService* manager=TSingleton<CUIService>::GetInstance(); if(!manager) return 0; MS2Ptr<UIObject> p=manager->FindObject((eUIClassID)T::Id()); if(p.IsNull()) return 0; return dynamic_cast<T*>(p.operator->());
}
template<> inline bool MS2Ptr<UIObject>::IsNull() const { return m_p==0; }

template<class T> inline int Unk_BreakFind(const ATL::CAtlArray<T>& values,const T& value) {
    for(int i=0;i<(int)values.GetCount();++i) if(values.GetAt(i)==value) return i; return -1;
}
CStringW GetStringCommonByKey(const CStringW&);
void FUN_1412751f0(const CStringW&,int,int);
void FUN_141275260(int,int,int);
void FUN_141275460(int,int,int,const fmt::ArgList&);
void FUN_140d73aa0(CStringW,int,void*,CStringW);
int FUN_141276180(const CString&,const CString&);
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
CStringW FUN_140719630(int); CStringW FUN_1407196b0(long); CStringW FUN_140719a80(unsigned __int64);
MS2_CHECK_OFFSET(Unk_BreakTemplate,category,0x138);
MS2_CHECK_OFFSET(Unk_BreakIngredient,count,0x20);
template<> inline void CMsgBoxData::Append(int v) { m_args.Add(FUN_140719630(v)); }
template<> inline void CMsgBoxData::Append(unsigned v) { m_args.Add(FUN_1407196b0(v)); }
template<> inline void CMsgBoxData::Append(__int64 v) { m_args.Add(FUN_140719a80(v)); }
MS2Ptr<CMsgBoxData> FUN_140d73d20(int,CStringW,void*,CStringW);
void FUN_140d73c60(MS2Ptr<CMsgBoxData>);
int FUN_141902660(Unk_BreakItemPtr);
void FUN_1409e4950(Unk_BreakItemPtr,CStringW&,bool*);
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
// @0x140530c90
void FUN_140530c90(MS2Ptr<CItemData> item,int grade,int enhance,CIngredientContainer& output) {
    if(item==0) return;
    if(TSingleton<CFeatureManager>::GetInstance()->FUN_14036d570(0x3a)) { int level=item->GetSkinType(); if(level) {
    unsigned short category=((Unk_BreakTemplate*)item.operator->())->category;
    __int64 value=item->GetSellPrice(grade);
    ((class Unk_BreakRecipe*)FUN_1401c0db0())->CalcMeratSkinItemBreakReward(category,grade,value,level,output);
    if(enhance>0) {
        CIngredientContainer extra; FUN_140628390(grade,category,level,&extra);
        if(!extra.FUN_14026bf40()) {
            int percent=((class Unk_BreakRecipe*)FUN_1401c0db0())->CalcMeratSkinItemBreakRefundPercent();
            for(size_t i=0;i<extra.FUN_14026bee0();++i) { MS2Ptr<CIngredientInfo> p=extra.FUN_14026bdc0(i); if(p==0) continue;
                unsigned amount=(reinterpret_cast<Unk_BreakIngredient*>(p.operator->())->count*percent)/100<1?1:(reinterpret_cast<Unk_BreakIngredient*>(p.operator->())->count*percent)/100; if(percent==0) amount=0; reinterpret_cast<Unk_BreakIngredient*>(p.operator->())->count=amount*enhance;
            }
            for(size_t i=0;i<reinterpret_cast<const std::vector<MS2Ptr<CIngredientInfo>>&>(output.ingredients).size();++i) for(size_t j=0;j<extra.FUN_14026bee0();++j) {
                MS2Ptr<CIngredientInfo> p=extra.FUN_14026bdc0(j); if(p==0) continue;
                if(reinterpret_cast<Unk_BreakIngredient*>((reinterpret_cast<std::vector<MS2Ptr<CIngredientInfo>>&>(output.ingredients)[i]).operator->())->id==reinterpret_cast<Unk_BreakIngredient*>(p.operator->())->id) { reinterpret_cast<Unk_BreakIngredient*>((reinterpret_cast<std::vector<MS2Ptr<CIngredientInfo>>&>(output.ingredients)[i]).operator->())->count+=reinterpret_cast<Unk_BreakIngredient*>(p.operator->())->count; reinterpret_cast<Unk_BreakIngredient*>(p.operator->())->count=0; }
            }
            output.FUN_14026c250(&extra);
        }
    }
    } }
}
MS2_REPLACE(0x140530C90, FUN_140530c90, 1004, 0x6E41BE6D);
// @0x140531090
void FUN_140531090(Unk_BreakItemPtr item,CIngredientContainer& output) {
    if(item==0 || ((Unk_BreakEnhance*)item->GetSocket())==0) return; FUN_140530c90(MS2Ptr<CItemData>(((CItemData*)item->FUN_140527840())),item->GetRarity(),((Unk_BreakEnhance*)item->GetSocket())->GetOpenSlotCount(),output);
}
// @0x140531180
CItemBreakManager::CItemBreakManager() : type(0) { pending.RemoveAll(); ItemBreakCommon::FUN_140530b00(items,100); }
// @0x140531220
CItemBreakManager::~CItemBreakManager() {}
// @0x140531270
int CItemBreakManager::CanBreakItem(ItemPtr item) {
    if(!item) return 0; if(item->FUN_140528e20()==true) return 0;
    if(FUN_140531510(item)==1) return 1;
    if(!FUN_140531630(item)) return 0; if(!FUN_140633bf0(item)) return 0; if(!FUN_140531850(item)) return 0;
    if(item->HasCubeTextureMesh()!=0) { if(TSingleton<CFeatureManager>::GetInstance()->IsRegionJP()) { if(((Unk_BreakEnhance*)item->GetSocket())!=0 && ((Unk_BreakEnhance*)item->GetSocket())->GetOpenSlotCount()>0) return 0; } }
    return 1;
}
MS2_REPLACE_METHOD(0x140531270, CItemBreakManager, CanBreakItem, 653, 0xB1394540);
// @0x140531510
int CItemBreakManager::FUN_140531510(ItemPtr item) {
    MS2Ptr<CItemData> data(((CItemData*)item->FUN_140527840())); if(data==0) return 0;
    if(item->FUN_140526190()==1) { if(((class Unk_BreakFlags*)FUN_14025e7b0())->flags.Get((CContentShutdown::Content)0x71)!=0) return 0; return 1; } return 0;
}
MS2_REPLACE_METHOD(0x140531510, CItemBreakManager, FUN_140531510, 269, 0x665F5D7D);
// @0x140531630
int CItemBreakManager::FUN_140531630(ItemPtr item) { unsigned __int64 id=FUN_140535320()->GetSummonUid(); if(id==0) return 1; if(id==item->GetItemUid()) return 0; return 1; }
MS2_REPLACE_METHOD(0x140531630, CItemBreakManager, FUN_140531630, 149, 0x879E8F78);
// @0x1405316d0
bool CItemBreakManager::FUN_1405316d0(ItemPtr item) {
    if(item->FUN_140526fc0()>0) return true; if(item->GetEnchantCharge()>0) return true; if(item->GetPlusLevel()>0) return true;
    if(item->FUN_140528c20()>1) return true; if(item->FUN_140528b90()>0) return true; if(((unsigned)item->FUN_140528bd0())>0) return true; if(item->FUN_140528c60()!=0) return true; return false;
}
MS2_REPLACE_METHOD(0x1405316D0, CItemBreakManager, FUN_1405316d0, 373, 0x79429692);
// @0x140531850
bool CItemBreakManager::FUN_140531850(ItemPtr item) {
    if(item==0) return false; if(!item->HasSkin()) return true;
    MS2SvrPtr<CIngredientContainer> p=reinterpret_cast<CItemBreakIngredientTable*>(FUN_140535300())->GetBreakItem(item->FUN_1405276c0());
    if(p.get()) { const Unk_BreakIngredients& list=*reinterpret_cast<const Unk_BreakIngredients*>(p->FUN_14026c230()); if(!reinterpret_cast<const std::vector<MS2Ptr<CIngredientInfo>>&>(list).empty()) return true; }
    int level=((CItemData*)item->FUN_140527840())->GetSkinType(); if(level) {
        unsigned short category=((unsigned short)item->GetRequiredLevel()); int grade=item->GetRarity(); __int64 value=item->GetSellPrice(); CIngredientContainer result;
        ((class Unk_BreakRecipe*)FUN_1401c0db0())->CalcMeratSkinItemBreakReward(category,grade,value,level,result); if(!reinterpret_cast<const std::vector<MS2Ptr<CIngredientInfo>>&>(result.ingredients).empty()) return true;
    } return false;
}
MS2_REPLACE_METHOD(0x140531850, CItemBreakManager, FUN_140531850, 571, 0xE5EDB101);
// @0x140531aa0
int CItemBreakManager::CanAddItem(ItemPtr item) { if(!CanBreakItem(item)) return 0; if(ItemBreakCommon::FUN_140530a10(items,item->GetItemUid())!=-1) return 0; return 1; }
MS2_REPLACE_METHOD(0x140531AA0, CItemBreakManager, CanAddItem, 187, 0x4B7E2A6A);
// @0x140531b70
int CItemBreakManager::IsBreakDialogOpen() {
    if(type==0) { MS2_ASSERT_AT(1642,"m_type != ItemBreakTypeNone" && 0); return 0; }
    UIItemBreakDialog* a=Unk_BreakDialog<UIItemBreakDialog>(0x4e8d); if(a && a->FUN_141924630()) return 1;
    UIItemBreakDonationDialog* b=Unk_BreakDialog<UIItemBreakDonationDialog>(0x4e8e); if(b && b->FUN_141924630()) return 1; return 0;
}
MS2_REPLACE_METHOD(0x140531B70, CItemBreakManager, IsBreakDialogOpen, 165, 0xC7E57465);
// @0x140531c20
void CItemBreakManager::SendItemDismantleMode0(int value) { type=value; pending.RemoveAll(); ItemBreakCommon::FUN_140530b00(items,100); COutPacket packet(static_cast<int>(SendOp::ItemDismantle),0); packet.Encode1(0); packet.Encode1((unsigned char)type); FUN_140710590(packet); }
MS2_REPLACE_METHOD(0x140531C20, CItemBreakManager, SendItemDismantleMode0, 149, 0xDC547EA6);
// @0x140531cc0
void CItemBreakManager::ResetBreakMode() { SendItemDismantleMode0(0); }
MS2_REPLACE_METHOD(0x140531CC0, CItemBreakManager, ResetBreakMode, 26, 0x3DB3E087);
// @0x140531ce0
CItemBreakManager::ItemPtr CItemBreakManager::GetSlotItemClone(int index) {
    if(index<0 || index>=(int)items.GetCount()) return ItemPtr(0);
    ItemBreakCommon::Ptr p=items[index]; if(p==0) return ItemPtr(0);
    unsigned __int64 id=p->id; ItemPtr item=g_143ab2a90.FUN_140a5d680(id); if(item==0) return ItemPtr(0);
    int count=p->count; ItemPtr clone=item->Clone(); clone->SetCountClamped(count); return clone;
}
MS2_REPLACE_METHOD(0x140531CE0, CItemBreakManager, GetSlotItemClone, 482, 0xE8C92A3B);
// @0x140531ed0
void CItemBreakManager::RemoveMissingItems() {
    for(size_t i=0;i<items.GetCount();++i) { ItemBreakCommon::Ptr p=items[i]; if(p==0 || p->FUN_140530750()) continue;
        unsigned __int64 id=p->id; ItemPtr item=g_143ab2a90.FUN_140a5d680(id); if(item==0) { if(Unk_BreakFind(pending,id)==-1) {
            COutPacket packet(static_cast<int>(SendOp::ItemDismantle),0); packet.Encode1(2); packet.FUN_14020ae50(id); FUN_140710590(packet); pending.Add(id);
        } }
    }
}
MS2_REPLACE_METHOD(0x140531ED0, CItemBreakManager, RemoveMissingItems, 392, 0x2F50DB8C);
// @0x140532060
void CItemBreakManager::RefreshActiveDialog() {
    switch(type) { case 1: { UIItemBreakDialog* p=Unk_BreakDialog<UIItemBreakDialog>(0x4e8d); if(p) p->FUN_1419a1430(); } break;
    case 2: { UIItemBreakDonationDialog* p=Unk_BreakDialog<UIItemBreakDonationDialog>(0x4e8e); if(p) p->FUN_1419a1430(); }
    }
}
MS2_REPLACE_METHOD(0x140532060, CItemBreakManager, RefreshActiveDialog, 110, 0x1A85706E);
// @0x1405320e0
void CItemBreakManager::UpdateActiveDialogSlot(int index) {
    switch(type) { case 1: { UIItemBreakDialog* p=Unk_BreakDialog<UIItemBreakDialog>(0x4e8d); if(p) p->FUN_1419a1d20(index); } break;
    case 2: { UIItemBreakDonationDialog* p=Unk_BreakDialog<UIItemBreakDonationDialog>(0x4e8e); if(p) p->FUN_1419a1d20(index); }
    }
}
MS2_REPLACE_METHOD(0x1405320E0, CItemBreakManager, UpdateActiveDialogSlot, 122, 0x94B746AD);
// @0x140532160
void CItemBreakManager::ForwardPacketToDialog(Unk_BreakPacket& packet) {
    switch(type) { case 1: { UIItemBreakDialog* p=Unk_BreakDialog<UIItemBreakDialog>(0x4e8d); if(p) p->vfunc_84(packet);
        UIShopDialog* shop=Unk_BreakDialog<UIShopDialog>(0x4e3b); if(shop) shop->UpdateGachaCoin(); } break;
    case 2: { UIItemBreakDonationDialog* p=Unk_BreakDialog<UIItemBreakDonationDialog>(0x4e8e); if(p) p->vfunc_84(packet); }
    }
}
MS2_REPLACE_METHOD(0x140532160, CItemBreakManager, ForwardPacketToDialog, 179, 0x46F57F72);
// @0x140532220
void CItemBreakManager::FUN_140532220() {
    switch(type) { case 1: { UIItemBreakDialog* p=Unk_BreakDialog<UIItemBreakDialog>(0x4e8d); if(p) p->vfunc_85(1,0); } break;
    case 2: { UIItemBreakDonationDialog* p=Unk_BreakDialog<UIItemBreakDonationDialog>(0x4e8e); if(p) p->vfunc_85(1,0); }
    }
}
MS2_REPLACE_METHOD(0x140532220, CItemBreakManager, FUN_140532220, 138, 0xD7B9754F);
// @0x1405322b0
void CItemBreakManager::OnItemDismantlePacket(Unk_BreakPacket& packet) {
    if(!IsBreakDialogOpen()) return;
    unsigned char mode=(&packet.input)->vfunc_1();
    if(mode==1) {
        unsigned __int64 id=(&packet.input)->vfunc_4(); int index=(&packet.input)->vfunc_2(); int count=(&packet.input)->vfunc_3();
        if(index<0 || index>=100) return;
        ItemPtr item=g_143ab2a90.FUN_140a5d680(id); if(item.get()) { ItemBreakCommon::FUN_140530b40(items,index,id,count); UpdateActiveDialogSlot(index); FUN_141276180(s_breakSound,""); }
        UIInventoryDialog* p=Unk_BreakDialog<UIInventoryDialog>(0x4e2d); if(p) p->FUN_14199a3f0(id);
    } else if(mode==2) {
        unsigned __int64 id=(&packet.input)->vfunc_4(); int index=ItemBreakCommon::FUN_140530a10(items,id);
        if(index>=0) { ItemBreakCommon::Ptr p=items[index]; if(p.get()) p->FUN_1405306f0(); }
        for(size_t i=0;i<pending.GetCount();++i) if(pending.GetAt(i)==id) { pending.GetAt(i)=0; break; }
        UpdateActiveDialogSlot(index); UIInventoryDialog* p=Unk_BreakDialog<UIInventoryDialog>(0x4e2d); if(p) p->FUN_14199a3f0(id);
    } else if(mode==3) {
        int value=(&packet.input)->vfunc_1(); if(type!=value) { MS2_ASSERT_AT(1306,"m_type == type" && 0); return; }
        ItemBreakCommon::FUN_140530b00(items,100); ForwardPacketToDialog(packet); RefreshActiveDialog();
    } else if(mode==4) {
        Unk_BreakResult result=(Unk_BreakResult)(&packet.input)->vfunc_3();
        if(result==1) FUN_141275260(0x8f6,1,1);
        else if(result==2) FUN_141275260(0x8f7,1,1);
        else if(result==3) FUN_141275260(0x43,1,1);
        else if(result==4) {}
        else if(result==5) FUN_1412751f0(GetStringCommonByKey(L"s_itembreak_empty"),1,1); else Unk_BreakMessage(0x8f8,1,1,result);
        UIItemBreakDialog* p=Unk_BreakDialog<UIItemBreakDialog>(); if(p && p->FUN_1405352d0()) p->ResetBreak(); FUN_140532220();
    } else if(mode==5) {
        UIItemBreakDialog* p=Unk_BreakDialog<UIItemBreakDialog>(); if(p) p->FUN_1419a44d0(reinterpret_cast<CInPacket*>(&packet));
    } else if(mode==6) {
        UIInventoryDialog* p=Unk_BreakDialog<UIInventoryDialog>(0x4e2d); unsigned count=(&packet.input)->vfunc_3();
        for(unsigned i=0;i<count;++i) { int index=(&packet.input)->vfunc_2(); unsigned __int64 id=(&packet.input)->vfunc_4(); int amount=(&packet.input)->vfunc_3();
            if(index<0 || index>=100) return; ItemPtr item=g_143ab2a90.FUN_140a5d680(id);
            if(item.get()) { ItemBreakCommon::FUN_140530b40(items,index,id,amount); UpdateActiveDialogSlot(index); } if(p) p->FUN_14199a3f0(id);
        }
        if(count!=0) FUN_141276180(s_breakSound,"");
    }
}
MS2_REPLACE_METHOD(0x1405322B0, CItemBreakManager, OnItemDismantlePacket, 2038, 0xDDEEFAB8);
// @0x140532ab0
int CItemBreakManager::FUN_140532ab0() {
    switch(type) { case 1: { UIItemBreakDialog* p=Unk_BreakDialog<UIItemBreakDialog>(0x4e8d); if(p && p->FUN_141924630()) return p->vfunc_86(); } break;
    case 2: { UIItemBreakDonationDialog* p=Unk_BreakDialog<UIItemBreakDonationDialog>(0x4e8e); if(p && p->FUN_141924630()) return p->vfunc_86(); }
    } return 0;
}
MS2_REPLACE_METHOD(0x140532AB0, CItemBreakManager, FUN_140532ab0, 162, 0x5FF33FB6);
// @0x140532b60
int CItemBreakManager::HasBreakItems() {
    for(size_t i=0;i<items.GetCount();++i) { ItemBreakCommon::Ptr p=items[i]; if(p==0 || p->FUN_140530750()) continue; return 1; } return 0;
}
MS2_REPLACE_METHOD(0x140532B60, CItemBreakManager, HasBreakItems, 192, 0xFD11FFEE);
// @0x140532c30
int CItemBreakManager::GetMaxItemRarity() {
    int grade=0; for(size_t i=0;i<items.GetCount();++i) { ItemBreakCommon::Ptr p=items[i]; if(p==0 || p->FUN_140530750()) continue;
        ItemPtr item=g_143ab2a90.FUN_140a5d680(p->id); if(!item) continue; if(item->GetRarity()>grade) grade=item->GetRarity();
    } return grade;
}
MS2_REPLACE_METHOD(0x140532C30, CItemBreakManager, GetMaxItemRarity, 329, 0x048AC1F8);
// @0x140532d80
int CItemBreakManager::SendItemDismantleMode3() { COutPacket packet(static_cast<int>(SendOp::ItemDismantle),0); packet.Encode1(3); FUN_140710590(packet); return 1; }
MS2_REPLACE_METHOD(0x140532D80, CItemBreakManager, SendItemDismantleMode3, 86, 0xCDB63F78);
// @0x140532de0
int CItemBreakManager::TryAddItem(ItemPtr item,int arg) {
    if(item==0) return 0;
    if(FUN_140535310() && !((CItemLockManager*)FUN_140535310())->FUN_140613160(item.get())) return 0;
    if(ItemBreakCommon::FUN_140530a10(items,item->GetItemUid())!=-1) { FUN_1412751f0(GetStringCommonByKey(L"s_itembreak_selected_item"),1,1); return 0; }
    Unk_BreakEnhance* enhance=((Unk_BreakEnhance*)item->GetSocket()); if(enhance && !enhance->CheckGemsBreakable()) { FUN_140d73aa0(GetStringCommonByKey(L"s_itembreak_usedgemstone_item"),0,0,L""); return 0; }
    if(type==2) { if(!CanBreakItem(item)) { FUN_141275260(0x8f7,1,1); return 0; }
        if(!((CItemData*)item->FUN_140527840())->FUN_14053cbc0() && !item->HasSkin()) { FUN_141275260(0x8f7,1,1); return 0; }
    } else if(!CanBreakItem(item)) { FUN_141275260(0x8f6,1,1); return 0; }
    AddItemWithConfirm(item,arg); return 1;
}
MS2_REPLACE_METHOD(0x140532DE0, CItemBreakManager, TryAddItem, 1057, 0xA15485BD);
// @0x140533210
void CItemBreakManager::SendItemDismantleMode1(__int64 id,int count,int arg) { COutPacket packet(static_cast<int>(SendOp::ItemDismantle),0); packet.Encode1(1); packet.Encode4(arg); packet.FUN_14020ae50(id); packet.Encode4(count); FUN_140710590(packet); }
MS2_REPLACE_METHOD(0x140533210, CItemBreakManager, SendItemDismantleMode1, 139, 0x0CBD71F0);
// @0x1405332b0
void CItemBreakManager::SendItemDismantleMode6(int a,int b) { if(!FUN_140532ab0()) return; { COutPacket packet(static_cast<int>(SendOp::ItemDismantle),0); packet.Encode1(6); packet.Encode1((unsigned char)a); packet.Encode1((unsigned char)b); FUN_140710590(packet); } }
MS2_REPLACE_METHOD(0x1405332B0, CItemBreakManager, SendItemDismantleMode6, 133, 0xB5BB3AAC);
// @0x140533340
int CItemBreakManager::RequestRemoveItem(ItemPtr item) {
    if(!CanBreakItem(item)) { FUN_141275260(0x8f6,1,1); return 0; } COutPacket packet(static_cast<int>(SendOp::ItemDismantle),0); packet.Encode1(2); packet.FUN_14020ae50(item->GetItemUid()); FUN_140710590(packet); return 1;
}
MS2_REPLACE_METHOD(0x140533340, CItemBreakManager, RequestRemoveItem, 248, 0x31B0FB01);
// @0x140533440
void CItemBreakManager::AddItemWithConfirm(ItemPtr item,int arg) {
    if(item==0) return; if(FUN_141902660(item)!=0) return;
    if(item->IsStackable()!=0 && ((unsigned)item->GetCount())>1) {
        if(MS2Ptr<CMsgBoxData> box=FUN_140d73d20(5,GetStringCommonByKey(L"s_msg_item_break"),0,L"")) {
            unsigned count=((unsigned)item->GetCount()); CStringW text; text.Format(L"%d",count);
            box->SetInput(1,text,count,0,0);
            box->SetCallback(Delegate<bool(int,const CMsgBoxData&)>(this,&CItemBreakManager::OnDismantleCountMsgBox));
            box->Append(arg); box->Append(item->GetItemUid()); box->Append((int)count); FUN_140d73c60(box);
        }
    } else {
        CStringW option; bool flag=false; FUN_1409e4950(item,option,&flag);
        if(item->GetRarity()>=5 && flag==1) {
            CStringW warning=GetStringCommonByKey(L"s_itembreak_high_sa_option_item"); CStringW text; text.Append(option); text.Append(L"\n"); text.Append(warning);
            MS2Ptr<CMsgBoxData> box=FUN_140d73d20(0x11,text,0,L"");
            if(box) { box->SetCallback(Delegate<bool(int,const CMsgBoxData&)>(this,&CItemBreakManager::OnConfirmMessageBoxResult));
                box->FUN_141a01600(item->GetItemUid()); box->FUN_141a01ee0(item,item->FUN_140527b10(),1,0,-1,-1,1); box->SetButtonLabelIds(0x475,0x476,0);
                box->Append(arg); box->Append(item->GetItemUid()); box->Append(((unsigned)item->GetCount())); FUN_140d73c60(box);
            }
        } else SendItemDismantleMode1(item->GetItemUid(),((unsigned)item->GetCount()),arg);
    }
}
MS2_REPLACE_METHOD(0x140533440, CItemBreakManager, AddItemWithConfirm, 2061, 0x4207F585);
// @0x140533c60
bool CItemBreakManager::OnDismantleCountMsgBox(int result,const CMsgBoxData& box) {
    if(result==0) { int arg=box.FUN_141a02e50(0,0); unsigned __int64 id=box.FUN_141a02f10(1,0); int max=box.FUN_141a02e50(2,0); int raw=_wtoi(box.FUN_141a02d50().Trim(L',')); int count=raw;
        if(raw==0 || count>max) { int min=1; Unk_BreakMessage(0xee,1,1,min,max); return false; } SendItemDismantleMode1(id,count,arg);
    } return true;
}
MS2_REPLACE_METHOD(0x140533C60, CItemBreakManager, OnDismantleCountMsgBox, 303, 0xEA21C368);
// @0x140533da0
bool CItemBreakManager::OnConfirmMessageBoxResult(int result,const CMsgBoxData& box) {
    if(result==0) { int arg=box.FUN_141a02e50(0,0); unsigned __int64 id=box.FUN_141a02f10(1,0); int count=box.FUN_141a02e50(2,0); SendItemDismantleMode1(id,count,arg); } return true;
}
MS2_REPLACE_METHOD(0x140533DA0, CItemBreakManager, OnConfirmMessageBoxResult, 121, 0x0F93C2D3);
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
