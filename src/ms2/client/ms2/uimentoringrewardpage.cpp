// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Mentoring pages.
// MS2-UNIT: client\ms2\uimentoringrewardpage.cpp
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVASMentoringRewardPage@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x140e63ce0
// MS2-PIN: memmove_s 0x140e62070
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVUIMentoringDialog@@P81@EAAXAEAVCInPacket@@@Z@std@@@?$Delegate@$$A6AXAEAVCInPacket@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x140e61e40
// MS2-PIN: ?vfunc_2@?$DelegateImpl@U?$pair@PEAVASMentoringRewardPage@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z 0x140e63c80
// MS2-PIN: ?vfunc_2@?$DelegateImpl@U?$pair@PEAVUIMentoringDialog@@P81@EAAXAEAVCInPacket@@@Z@std@@@?$Delegate@$$A6AXAEAVCInPacket@@@Z@@UEAAXAEAVCInPacket@@@Z 0x140e61ed0
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVUIMentoringDialog@@P81@EAAXAEAVCInPacket@@@Z@std@@@?$Delegate@$$A6AXAEAVCInPacket@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x140e61f40
// MS2-PIN: ?vfunc_48@UIMentoringDialog@@UEAAHXZ 0x140e60a70
// MS2-RANGE: 0x1400d8e30-0x1400d8ee0 .text$di
// MS2-RANGE: 0x140e5db70-0x140e63e60 .text$mn
// MS2-RANGE: 0x142ca6e40-0x142ca6e95 .text$yd
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uimentoringrewardpage.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "uimentoringrewardpage.h"
#include "ms2/placeholder/header_statics_a.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/gfxexception.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
class Unk_MentorInput {public:virtual bool vfunc_0();virtual unsigned char vfunc_1();};
class CInPacket {public:void* p0;Unk_MentorInput stream;};
class Unk_MentorPacketManager {public:void FUN_140da5180(int,Delegate<void(CInPacket&)>);void FUN_140da51e0(int,Delegate<void(CInPacket&)>);};
Unk_MentorPacketManager* FUN_140bccd50();
class Unk_MentorUIManager {public:void FUN_141adc5d0(int);};Unk_MentorUIManager* FUN_1403ed2b0();
class Unk_MentorActor {public:int FUN_14165ffe0();};
class Unk_MentorWorld {public:Unk_MentorActor* FUN_141bd0cc0();};Unk_MentorWorld* FUN_1403ed2d0();
class Unk_MentorInfo {public:int FUN_140b71580();int FUN_140b715c0();bool FUN_140b71610();};Unk_MentorInfo* FUN_140c70240();
class Unk_MentorStatus {public:int FUN_140424de0();};class Unk_MentorConfig {public:Unk_MentorStatus* FUN_14041d160();};Unk_MentorConfig* FUN_140302b00();
class Unk_MentorFlag {public:int FUN_1402c4c90(int);};class Unk_MentorFlags {public:void* p0;Unk_MentorFlag flags;};Unk_MentorFlags* FUN_14025e7b0();
class Unk_MentorNotification {public:void FUN_141938ae0(int,int);};Unk_MentorNotification* FUN_140938b90(int);
void FUN_1413499b0(int);
class Unk_MentorTab:public ASDisplayObject {public:
 virtual void vfunc_6();virtual void vfunc_7();virtual void vfunc_8();virtual void vfunc_9();virtual void vfunc_10();virtual void vfunc_11();virtual void vfunc_12();virtual void vfunc_13();virtual void vfunc_14();virtual void vfunc_15();virtual void vfunc_16();virtual void vfunc_17();virtual void vfunc_18();virtual void vfunc_19();virtual void vfunc_20();virtual void vfunc_21();virtual void vfunc_22();virtual void vfunc_23();virtual void vfunc_24(bool);
 void FUN_1422e3460(const ASObj&);void FUN_1422e31e0(int);
};
CStringW GetStringCommonByKey(const CStringW&);
CStringW LocalizedMentorFormat(const CStringW&,const fmt::ArgList&);
FMT_VARIADIC_W(CStringW,LocalizedMentorFormat,CStringW)
class Unk_MentorRewards {public:void FUN_14069c070(std::vector<unsigned>&);};Unk_MentorRewards* FUN_1406c7610();
int FUN_140324070(const int&,int,int);CString FUN_140b62550(int);
void FUN_140cfee80(const Scaleform::GFx::Value&,CString,CStringW);
// @0x140e5db70
UIMentoringDialog::UIMentoringDialog():m_page(0),m_pages(17,0.75f,0.25f,2.25f,10) {
 FUN_141924170(1);
 AddPage(new UIMentoringBuffPage(this));AddPage(new UIMentoringMenteePage(this));AddPage(new UIMentoringMentorPage(this));
 AddPage(new UIMentoringMenteeRegisterPage(this));AddPage(new UIMentoringMentorRegisterPage(this));AddPage(new Unk_MentorMission(this));AddPage(new UIMentoringRewardPage(this));
 FUN_140bccd50()->FUN_140da5180(0x10a,Delegate<void(CInPacket&)>(this,&UIMentoringDialog::OnPacket));
 FUN_140bccd50()->FUN_140da5180(0x10b,Delegate<void(CInPacket&)>(this,&UIMentoringDialog::OnUpdate));
}
// @0x140e5e190
UIMentoringDialog::~UIMentoringDialog(){FUN_140bccd50()->FUN_140da51e0(0x10a,Delegate<void(CInPacket&)>(this,&UIMentoringDialog::OnPacket));FUN_140bccd50()->FUN_140da51e0(0x10b,Delegate<void(CInPacket&)>(this,&UIMentoringDialog::OnUpdate));}
// @0x140e5e330
CString UIMentoringDialog::GetTypeName(){return "MentoringDialog";}
MS2_REPLACE_METHOD(0x140E5E330, UIMentoringDialog, GetTypeName, 61, 0x24A44C72);
// @0x140e5e380
void UIMentoringDialog::vfunc_67(){UIDialog::vfunc_67();FUN_1403ed2b0()->FUN_141adc5d0(0x4f4c);}
MS2_REPLACE_METHOD(0x140E5E380, UIMentoringDialog, vfunc_67, 42, 0x2187958A);
// @0x140e5e3b0
void UIMentoringDialog::OnLoadComplete(){UIDialog::OnLoadComplete();Refresh();}
MS2_REPLACE_METHOD(0x140E5E3B0, UIMentoringDialog, OnLoadComplete, 34, 0x9CE62EF1);
// @0x140e5e3e0
void UIMentoringDialog::vfunc_45(Scaleform::GFx::Value* v,const CString& s,ASData* d){UIObject::vfunc_45(v,s,d);if(m_page.get())m_page->vfunc_3(v,s,d);}
MS2_REPLACE_METHOD(0x140E5E3E0, UIMentoringDialog, vfunc_45, 133, 0x01C990C0);
// @0x140e5e470
void UIMentoringDialog::vfunc_49(Scaleform::GFx::Value* v,ASData* d){UIObject::vfunc_49(v,d);if(m_page.get())m_page->vfunc_4(v,d);}
MS2_REPLACE_METHOD(0x140E5E470, UIMentoringDialog, vfunc_49, 118, 0x865A5280);
// @0x140e5e4f0
void UIMentoringDialog::vfunc_79(void* p){UIDialog::vfunc_79(p);}
MS2_REPLACE_METHOD(0x140E5E4F0, UIMentoringDialog, vfunc_79, 34, 0xEDA5A5B7);
// @0x140e5e520
int UIMentoringDialog::vfunc_28(const char* method,const Scaleform::GFx::Value* args,unsigned count){
 if(UIDialog::vfunc_28(method,args,count))return 1;
 if(_stricmp(method,"onAddPage")==0){ASData data;if(data.FUN_1422b9620(args,count)){CString name=data.FUN_1422b8d30();Unk_MentorPtr<UIMentoringPage> page(0);if(m_pages.Lookup(name,page)){m_page=page;page->vfunc_1();}}return 1;}
 else if(_stricmp(method,"onRemovePage")==0){ASData data;if(data.FUN_1422b9620(args,count)){CString name=data.FUN_1422b8d30();Unk_MentorPtr<UIMentoringPage> page(0);if(m_pages.Lookup(name,page)){page->vfunc_2();m_page=0;}}return 1;}
 else if(_stricmp(method,"onClickShop")==0){Unk_MentorActor* actor=FUN_1403ed2d0()->FUN_141bd0cc0();if(actor){int type=actor->FUN_14165ffe0();switch(type){case 1:case 2:FUN_1413499b0(6);break;case 4:case 5:FUN_1413499b0(7);break;}}}
 else if(m_page.get()){if(m_page->vfunc_5(method,args,count))return 1;}
 return 0;
}
MS2_REPLACE_METHOD(0x140E5E520, UIMentoringDialog, vfunc_28, 864, 0x56399EE2);
// @0x140e5e890
Unk_MentorPtr<UIMentoringPage> UIMentoringDialog::GetPage(){return m_page;}
MS2_REPLACE_METHOD(0x140E5E890, UIMentoringDialog, GetPage, 67, 0x9F7149C0);
// @0x140e5e8e0
void UIMentoringDialog::Refresh(){ATL::CAtlArray<CString> tabs;GetTabs(tabs);SetTabs(tabs);}
MS2_REPLACE_METHOD(0x140E5E8E0, UIMentoringDialog, Refresh, 75, 0x2DBEAD0D);
// @0x140e5e940
int UIMentoringDialog::Count(){ATL::CAtlArray<CString> tabs;GetTabs(tabs);int count=0;for(size_t i=0;i<tabs.GetCount();i++){Unk_MentorPtr<UIMentoringPage> page(0);if(m_pages.Lookup(tabs.GetAt(i),page))count+=page->vfunc_8();}return count;}
MS2_REPLACE_METHOD(0x140E5E940, UIMentoringDialog, Count, 257, 0x6E1D099F);
// @0x140e5ea50
void UIMentoringDialog::RefreshPage(){if(m_page.IsNull())return;if(m_page->vfunc_6()=="MentorPage"){UIMentoringPage* page=m_page;page->FUN_140c71ce0();}else if(m_page->vfunc_6()=="MenteePage"){UIMentoringPage* page=m_page;page->FUN_140c6f190();}}
MS2_REPLACE_METHOD(0x140E5EA50, UIMentoringDialog, RefreshPage, 315, 0x575E7804);
// @0x140e5eba0
void UIMentoringDialog::Notify(){UpdateCounts();if(m_page.get())m_page->vfunc_9();Unk_MentorNotification* p=FUN_140938b90(0x4e28);if(p)p->FUN_141938ae0(0x4f4b,0);}
MS2_REPLACE_METHOD(0x140E5EBA0, UIMentoringDialog, Notify, 129, 0x15D26F72);
// @0x140e5ec30
void UIMentoringDialog::UpdateCounts(){if(m_30==0)return;for(size_t i=0;i<m_tabs.size();i++)m_30->Invoke("setTabCount",m_tabs[i]->vfunc_6(),m_tabs[i]->vfunc_8());}
MS2_REPLACE_METHOD(0x140E5EC30, UIMentoringDialog, UpdateCounts, 352, 0x5ACF5D77);
// @0x140e5eda0
int UIMentoringDialog::IsAvailable(){Unk_MentorActor* actor=FUN_1403ed2d0()->FUN_141bd0cc0();if(!actor)return false;if(FUN_140302b00()->FUN_14041d160()->FUN_140424de0()==0)return false;if(FUN_14025e7b0()->flags.FUN_1402c4c90(0x4a))return false;return true;}
MS2_REPLACE_METHOD(0x140E5EDA0, UIMentoringDialog, IsAvailable, 108, 0x0726E828);
// @0x140e5ee20
void UIMentoringDialog::SetTabs(ATL::CAtlArray<CString>& tabs){m_tabs.clear();if(MS2Ptr<Unk_MentorTab> tab=GetChild<Unk_MentorTab>("m_tab")){for(size_t i=0;i<tabs.GetCount();i++){Unk_MentorPtr<UIMentoringPage> page(0);if(m_pages.Lookup(tabs.GetAt(i),page)){ASObj obj(2);obj.FUN_1407cba60("id",tabs.GetAt(i));obj.FUN_1407cbb20("label",page->vfunc_7());tab->FUN_1422e3460(obj);m_tabs.push_back(page);}}tab->vfunc_24(1);tab->FUN_1422e31e0(0);}UpdateCounts();}
MS2_REPLACE_METHOD(0x140E5EE20, UIMentoringDialog, SetTabs, 634, 0x149640E6);
// @0x140e5f0a0
void UIMentoringDialog::GetTabs(ATL::CAtlArray<CString>& tabs){int type=FUN_140c70240()->FUN_140b71580();switch(type){case 1:tabs.Add("MenteeRegisterPage");tabs.Add("BuffPage");break;case 4:tabs.Add("MentorRegisterPage");tabs.Add("BuffPage");break;case 2:tabs.Add("MenteePage");tabs.Add("RewardPage");tabs.Add("MissionPage");tabs.Add("BuffPage");break;case 5:tabs.Add("MentorPage");tabs.Add("BuffPage");break;}}
MS2_REPLACE_METHOD(0x140E5F0A0, UIMentoringDialog, GetTabs, 602, 0xB8D1BC8C);
// @0x140e5f300
void UIMentoringDialog::OnUpdate(CInPacket&){Notify();}
MS2_REPLACE_METHOD(0x140E5F300, UIMentoringDialog, OnUpdate, 29, 0xA4B92A11);
// @0x140e5f330
void UIMentoringDialog::OnPacket(CInPacket& p){int code=(&p.stream)->vfunc_1();switch(code){case 10:case 11:Notify();break;}}
MS2_REPLACE_METHOD(0x140E5F330, UIMentoringDialog, OnPacket, 94, 0xBEADBDB4);
// @0x140e5f3a0
void UIMentoringDialog::AddPage(Unk_MentorPtr<UIMentoringPage> p){m_pages.SetAt(p->vfunc_6(),p);}
MS2_REPLACE_METHOD(0x140E5F3A0, UIMentoringDialog, AddPage, 138, 0x68426DD8);
MS2_EMIT_CRT_MEMMOVE_S();
// @0x140e62190
ASMentoringRewardPage::ASMentoringRewardPage(UIMentoringPage* p):m_owner(p){}
// @0x140e62260
ASMentoringRewardPage::~ASMentoringRewardPage(){}
// @0x140e62310
void ASMentoringRewardPage::OnInit(){
 if(!m_owner)return;
 m_script=m_owner->GetScript();
 do{m_script->FUN_140bbe640("m_receiveButton",m_button);if(m_button==0)throw new GfxExceptionSwfLoad(StringFormat("GfxError:{0} {1}({2}) function:{3}","SwfLoadError",MS2_THIS_FILE,MS2_LINE(24),__FUNCTION__));}while(0);
 do{m_script->FUN_140beaf20("m_coin",m_coin);if(m_coin==0)throw new GfxExceptionSwfLoad(StringFormat("GfxError:{0} {1}({2}) function:{3}","SwfLoadError",MS2_THIS_FILE,MS2_LINE(25),__FUNCTION__));}while(0);
 do{m_script->FUN_140bc71c0("m_effect1",m_effect1);if(m_effect1==0)throw new GfxExceptionSwfLoad(StringFormat("GfxError:{0} {1}({2}) function:{3}","SwfLoadError",MS2_THIS_FILE,MS2_LINE(26),__FUNCTION__));}while(0);
 do{m_script->FUN_140bc71c0("m_effect2",m_effect2);if(m_effect2==0)throw new GfxExceptionSwfLoad(StringFormat("GfxError:{0} {1}({2}) function:{3}","SwfLoadError",MS2_THIS_FILE,MS2_LINE(27),__FUNCTION__));}while(0);
 do{m_script->FUN_140bc71c0("m_effect3",m_effect3);if(m_effect3==0)throw new GfxExceptionSwfLoad(StringFormat("GfxError:{0} {1}({2}) function:{3}","SwfLoadError",MS2_THIS_FILE,MS2_LINE(28),__FUNCTION__));}while(0);
 m_button->FUN_1422ce240(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this,&ASMentoringRewardPage::OnReward),0);Refresh();
}
MS2_REPLACE_METHOD(0x140E62310, ASMentoringRewardPage, OnInit, 2312, 0x91C5FF3B);
// @0x140e62cc0
void ASMentoringRewardPage::Refresh(){
 if(!FUN_1406c7610())return;UIMentoringDialog* owner=m_owner->GetOwner();if(!owner)return;
 const size_t count=3;std::vector<unsigned> values;FUN_1406c7610()->FUN_14069c070(values);if(values.size()!=count)return;
 FUN_140cfee80((*m_script).FUN_1422bb890(),"m_benefitDesc",LocalizedMentorFormat(L"s_mentoring_reward_coin_desc",values[0],values[1],values[2]));
 bool available=FUN_140c70240()->FUN_140b71610();int level=FUN_140c70240()->FUN_140b715c0();unsigned index=FUN_140324070(level,0,2);
 m_coin->FUN_1422c4c80(FUN_140b62550(values[index]));m_button->FUN_1422c1fe0((unsigned)available);
 m_effect1->vfunc_4(available);m_effect2->vfunc_4(available);m_effect3->vfunc_4(available);
}
MS2_REPLACE_METHOD(0x140E62CC0, ASMentoringRewardPage, Refresh, 822, 0x5E175E0C);
// @0x140e63000
void ASMentoringRewardPage::OnReward(const Scaleform::GFx::FunctionHandler::Params&){COutPacket packet(static_cast<int>(SendOp::Mentor),0);packet.Encode1(0);FUN_140710590(packet);}
MS2_REPLACE_METHOD(0x140E63000, ASMentoringRewardPage, OnReward, 80, 0xFF9C26BC);
// @0x140e63060
UIMentoringRewardPage::UIMentoringRewardPage(UIMentoringDialog* p):UIMentoringPage(p){}
// @0x140e630c0
UIMentoringRewardPage::~UIMentoringRewardPage(){}
// @0x140e63100
int UIMentoringRewardPage::vfunc_1(){if(!UIMentoringPage::vfunc_1())return 0;m_reward=new ASMentoringRewardPage(this);m_reward->OnInit();return 1;}
MS2_REPLACE_METHOD(0x140E63100, UIMentoringRewardPage, vfunc_1, 157, 0x9BFF5052);
// @0x140e631b0
void UIMentoringRewardPage::vfunc_2(){UIMentoringPage::vfunc_2();m_reward=0;}
MS2_REPLACE_METHOD(0x140E631B0, UIMentoringRewardPage, vfunc_2, 43, 0xA57B4674);
// @0x140e631f0
CString UIMentoringRewardPage::vfunc_6(){return "RewardPage";}
MS2_REPLACE_METHOD(0x140E631F0, UIMentoringRewardPage, vfunc_6, 61, 0x2670D946);
// @0x140e63240
CStringW UIMentoringRewardPage::vfunc_7(){return GetStringCommonByKey(L"s_mentoring_tab_reward");}
MS2_REPLACE_METHOD(0x140E63240, UIMentoringRewardPage, vfunc_7, 97, 0x97C1CD7B);
// @0x140e632b0
int UIMentoringRewardPage::vfunc_8(){if(FUN_140c70240()->FUN_140b71610())return 1;return 0;}
MS2_REPLACE_METHOD(0x140E632B0, UIMentoringRewardPage, vfunc_8, 43, 0xAE13A6CC);
// @0x140e632f0
void UIMentoringRewardPage::vfunc_9(){if(m_reward.get())m_reward->Refresh();}
MS2_REPLACE_METHOD(0x140E632F0, UIMentoringRewardPage, vfunc_9, 61, 0x050585A9);
// @0x140e63d40
MS2_EMIT_CRT_MEMMOVE_S_COPY(2);
