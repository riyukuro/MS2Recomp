// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Upper target HP bars.
// MS2-UNIT: client\ms2\uiupperhpbar.cpp
// MS2-RANGE: 0x141b4a150-0x141b4f220 .text$mn
// MS2-RANGE: 0x14011f180-0x14011f460 .text$di
// MS2-RANGE: 0x142cc3340-0x142cc3455 .text$yd
// MS2-PIN: ??__Fs_unk1402a9d70@@YAXXZ 0x142cc33b0
// MS2-PIN: ??__Fcondition@Unk_UpperHeaderStatics@@YAXXZ 0x142cc3440
// MS2-PIN: ?vfunc_48@UIUpperHpBar@@UEAAHXZ 0x141b4e460
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiupperhpbar.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "uiupperhpbar.h"
#include "ms2/placeholder/header_statics_a.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
// The recovered initializer run contains two copies of the header's static data.
namespace Unk_UpperHeaderStatics {
static CString sortNames[]={"None","Buy","Like","PriceLow","PriceHigh","Create","EnumEnd"};
static CString skill="skill";static CString stun="stun";
static Unk_1402a9d70 condition(17,0.75f,0.25f,2.25f,10);
}
class Unk_UpperClip : public ASDisplayObject {
public: bool FUN_1422ba9a0();void FUN_1407cbbe0(const char*,bool);
 void FUN_1422c7290(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>&,int);
 void FUN_1422c7310(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>&,int);
 Unk_UpperPtr<Unk_UpperText> FUN_1409b4560(const CString&);
};
class Unk_UpperHpText : public ASDisplayObject {};
class Unk_UpperText : public ASDisplayObject {
public:Scaleform::GFx::Value FUN_1422c6b70(Scaleform::GFx::Value);Scaleform::GFx::Value FUN_1422c6900(Scaleform::GFx::Value);
 Unk_UpperPtr<Unk_UpperHpText> FUN_1409b4620(const CString&);
};
class Unk_UpperEvents {public:void FUN_1419308c0(UIEntityEventListener*);void FUN_141930950(UIEntityEventListener*);};
Unk_UpperEvents* FUN_140c607b0();
class Unk_UpperConfigData {public:int m_0;short m_4;char m_6;bool m_hp;char m_8;bool m_buff;};
class Unk_UpperConfig {public:Unk_UpperConfigData* FUN_140b123b0();};Unk_UpperConfig* FUN_1409a8b10();
class Unk_UpperAS {public:Unk_UpperAS(int);~Unk_UpperAS();void FUN_1407cbbe0(const char*,bool);Scaleform::GFx::Value& FUN_1422bb870();
private:void* m_0;void* m_8;void* m_10;void* m_18;void* m_20;void* m_28;void* m_30;void* m_38;};
MS2_CHECK_SIZE(Unk_UpperAS,0x40);
CString FUN_140b62550(int);
class Unk_UpperEvt {public:Unk_UpperEvt(const Unk_UpperEvt&);private:void* m_0;};
class Unk_UpperPlayer {public:void* FUN_141bd1320(int);void* FUN_141bd1180(int);void* FUN_141bd0fa0(Unk_UpperEvt);};Unk_UpperPlayer* FUN_1403ed2d0();
class Unk_UpperActor;class Unk_UpperBuff {public:Unk_UpperActor* FUN_14096d280();int FUN_14096d260();char* FUN_14096d810();};
class Unk_UpperMgr {public:int FUN_141adc890(int);};Unk_UpperMgr* FUN_1403ed2b0();
Unk_UpperPtr<Unk_UpperClip> FUN_140acca70(int,const Scaleform::GFx::Value&);
void FUN_1409b58f0(ASDisplayObject*,bool);
class ASGameEntity : public ASDisplayObject {};
MS2Ptr<ASGameEntity> FUN_140ba77e0(int,const Scaleform::GFx::Value&);
class Unk_UpperNpcData {public:bool FUN_1406cd200(int);int FUN_1406cd040();int FUN_1406cd310();};

class Unk_UpperNpc;
// ---- recovered callee shapes for the buff/target handlers (names invented; FUN_ names are exe addresses) ----
void FUN_1409b57b0(ASDisplayObject*,int,int);void FUN_1409b5810(ASDisplayObject*,int,int);void FUN_1409b58b0(ASDisplayObject*,int);
void FUN_1409b5890(ASDisplayObject*,int);void FUN_1409b5940(ASDisplayObject*,Unk_UpperPtr<Unk_UpperBuff>);
void FUN_1409b5aa0(ASDisplayObject*,Unk_UpperPtr<Unk_UpperBuff>);void FUN_1409b5b60(ASDisplayObject*,int);void FUN_1409b5610(ASDisplayObject*);
Unk_UpperPtr<ASDisplayObject> FUN_140e6cd80(int,CString,int,int);
bool FUN_14087ddc0(void*,int);
class Unk_UpperActor {public:
 virtual ~Unk_UpperActor();virtual void vfunc_1();virtual void vfunc_2();virtual void vfunc_3();virtual void vfunc_4();virtual void vfunc_5();virtual void* vfunc_6();
 virtual void vfunc_7();virtual void vfunc_8();virtual void vfunc_9();virtual void vfunc_10();virtual void vfunc_11();virtual void vfunc_12();virtual void vfunc_13();virtual void vfunc_14();virtual void vfunc_15();virtual void vfunc_16();virtual void vfunc_17();virtual void vfunc_18();virtual void vfunc_19();virtual void vfunc_20();virtual void vfunc_21();virtual void vfunc_22();virtual void vfunc_23();virtual void vfunc_24();virtual void vfunc_25();virtual void vfunc_26();virtual void vfunc_27();virtual void vfunc_28();virtual void vfunc_29();virtual void vfunc_30();virtual void vfunc_31();virtual void vfunc_32();virtual void vfunc_33();virtual void vfunc_34();virtual void vfunc_35();virtual void vfunc_36();virtual void vfunc_37();virtual void vfunc_38();virtual void vfunc_39();virtual void vfunc_40();virtual void vfunc_41();virtual void vfunc_42();virtual void vfunc_43();virtual void vfunc_44();virtual void vfunc_45();virtual void vfunc_46();virtual void vfunc_47();virtual void vfunc_48();virtual void vfunc_49();virtual void vfunc_50();virtual void vfunc_51();virtual void vfunc_52();virtual void vfunc_53();virtual void vfunc_54();virtual void vfunc_55();virtual void vfunc_56();virtual void vfunc_57();virtual void vfunc_58();virtual void vfunc_59();virtual void vfunc_60();virtual void vfunc_61();virtual void vfunc_62();virtual void vfunc_63();virtual void vfunc_64();virtual int vfunc_65();virtual void vfunc_66();virtual void vfunc_67();virtual void vfunc_68();virtual void vfunc_69();virtual void vfunc_70();virtual void vfunc_71();virtual void vfunc_72();virtual void vfunc_73();virtual void vfunc_74();virtual void vfunc_75();virtual void vfunc_76();virtual CStringW vfunc_77();virtual void vfunc_78();virtual short vfunc_79();
 __int64 FUN_141670a60(int);int FUN_14166ce30();__int64 FUN_141670a00(int);__int64 FUN_141670a30(int);
 __int64 FUN_141095270();int FUN_141092fa0();int FUN_141093030();};
CStringW FUN_140ba7890(const wchar_t*,const __int64&);
CStringW FUN_1401aa6a0(int);CStringW FUN_1405c2690(CStringW,const CStringW&);
class Unk_UpperSub {public:Unk_UpperPtr<Unk_UpperBuff> FUN_140972690();};Unk_UpperSub* FUN_1416749a0(void*);
class Unk_UpperTargetUI : public UIHeadUpDisplay {public:void FUN_140c5f8f0(Unk_UpperPtr<Unk_UpperBuff>);Unk_UpperPtr<Unk_UpperBuff> FUN_140c5f990();void FUN_140c5faf0();};
Unk_UpperTargetUI* FUN_140974280(int);
Unk_UpperActor* FUN_1409ffd30(void*);Unk_UpperNpc* FUN_140a38a00(void*);
void FUN_1422bcdd0(Scaleform::GFx::Value*,__int64);void FUN_1422bcea0(Scaleform::GFx::Value*,const wchar_t*);void FUN_1422bccb0(Scaleform::GFx::Value*,int);

class Unk_UpperNpc : public Unk_UpperActor {public:Unk_UpperPtr<Unk_UpperNpcData> FUN_141093270();};
class Unk_UpperPC {public:int FUN_141654730();};
Unk_UpperNpc* FUN_14096e110(void*);Unk_UpperPC* FUN_140974230(void*);
class Unk_UpperStrings {public:CStringW FUN_141811980(int,int);};Unk_UpperStrings* FUN_1401a9d70();
int FUN_14123c580(void*);
extern int g_upperTargetId;
// Remaining target-stat calculation and buff population routines are declarations above.
// @0x141b4a150
void FUN_141b4a150(Unk_UpperActor* actor,bool flag,int* stage,__int64* cur,__int64* max,CStringW* hpText,CStringW* shieldText){
 if(actor==0)return;
 *max=actor->FUN_141670a60(4);
 __int64 base;
 if(actor->FUN_14166ce30()!=0)base=0;else base=actor->FUN_141670a00(4);
 *cur=base;
 *hpText=FUN_140ba7890(L"{0}",*cur);
 *stage=0;
 if(flag==true){
 Unk_UpperNpc* npc=FUN_14096e110(actor);
 bool isBoss=npc&&npc->FUN_141093270()->FUN_1406cd200(5);
 if(isBoss){
  const __int64& total=npc->FUN_141095270();
  const __int64& unit=npc->FUN_141670a30(4);
  *stage=(int)(total/unit+1);
  if(total>unit){
   __int64 over=total-unit;
   *cur=over%unit;
   *hpText=FUN_140ba7890(L"{0}",over);
   *shieldText=FUN_1405c2690(L"s_upper_hp_bar_accum_damage",FUN_1401aa6a0(npc->FUN_141092fa0()));
  }else{
   __int64 rest=unit-total;
   *cur=rest;
   *hpText=FUN_140ba7890(L"{0}",*cur);
   *shieldText=FUN_1405c2690(L"s_upper_hp_bar_accum_damage_shield",FUN_1401aa6a0(npc->FUN_141092fa0()));
  }
  *max=*cur;
 }
 }
}
MS2_REPLACE(0x141B4A150, FUN_141b4a150, 1256, 0x1B6E404C);
// @0x141b4a640
UpperHpBarEntity::UpperHpBarEntity():m_id(0),m_hp(0),m_kind(3),m_visible(false),m_pending(17,.75f,.25f,2.25f,10),m_buffs(17,.75f,.25f,2.25f,10){}
// @0x141b4a740
UpperHpBarEntity::~UpperHpBarEntity(){FUN_141b4a840();}
// @0x141b4a7d0
void UpperHpBarEntity::FUN_141b4a7d0(const CString& name,const int& kind){m_name=name;m_kind=kind;}
MS2_REPLACE_METHOD(0x141B4A7D0, UpperHpBarEntity, FUN_141b4a7d0, 62, 0x117F1A56);

// @0x141b4a820
const CString& UpperHpBarEntity::FUN_141b4a820(){return m_name;}
MS2_REPLACE_METHOD(0x141B4A820, UpperHpBarEntity, FUN_141b4a820, 15, 0x271C8F51);

// @0x141b4a840
void UpperHpBarEntity::FUN_141b4a840(){FUN_141b4b3f0();m_clip=0;m_gauge=0;m_pending.FUN_1419f4f30();m_buffs.RemoveAll();}
MS2_REPLACE_METHOD(0x141B4A840, UpperHpBarEntity, FUN_141b4a840, 98, 0x735A1D01);

// @0x141b4a8b0
void UpperHpBarEntity::FUN_141b4a8b0(Unk_UpperPtr<Unk_UpperClip> clip){
 if(clip==0||clip->FUN_1422ba9a0()==true)return;
 m_clip=clip;m_visible=m_clip->FUN_1422bfca0();
 clip->FUN_1422c7290(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this,&UpperHpBarEntity::FUN_141b4bca0),0);
 clip->FUN_1422c7310(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this,&UpperHpBarEntity::FUN_141b4bce0),0);
 m_gauge=clip->FUN_1409b4560("m_gauge");
 for(POSITION pos=m_pending.FUN_1419f4790();pos;m_pending.FUN_1419f4620(pos)){FUN_141b4ac50(m_pending.FUN_1419f4810(pos));}m_pending.FUN_1419f4f30();
}
MS2_REPLACE_METHOD(0x141B4A8B0, UpperHpBarEntity, FUN_141b4a8b0, 686, 0x8A562DEA);

// @0x141b4ab70
bool UpperHpBarEntity::FUN_141b4ab70(const int& id){if(m_id!=id)return false;m_id=0;m_hp=0;if(m_clip.get())m_clip->Invoke("destroyEntity",FUN_140b62550(id));return true;}
MS2_REPLACE_METHOD(0x141B4AB70, UpperHpBarEntity, FUN_141b4ab70, 215, 0xE47BB395);

// @0x141b4ac50
void UpperHpBarEntity::FUN_141b4ac50(Unk_UpperPtr<Unk_UpperBuff> buff){
 if(buff==0||buff->FUN_14096d280()==0){MS2_ASSERT_AT(89,0);return;}
  if(m_clip==0){m_pending.FUN_1419f5260(buff->FUN_14096d260(),buff);return;}
  const int& key=FUN_14123c580(buff->FUN_14096d280());
  Unk_UpperPtr<ASDisplayObject> obj;
  if(!m_buffs.Lookup(key,obj)){
   obj=FUN_140e6cd80(2,"flash.display.MovieClip",0,0);
   if(m_kind==0){FUN_1409b57b0(obj.operator->(),0x5c,0x5a);FUN_1409b5810(obj.operator->(),0x1a6,0x5a);FUN_1409b58b0(obj.operator->(),7);}
   else if(m_kind==1){FUN_1409b57b0(obj.operator->(),0x48,-32);FUN_1409b5810(obj.operator->(),0x48,0x56);}
   else{FUN_1409b57b0(obj.operator->(),0x2e,-42);FUN_1409b5810(obj.operator->(),0x2e,0x34);}
   FUN_1409b5890(obj.operator->(),0xf);
   if(FUN_14087ddc0(buff->FUN_14096d280()?buff->FUN_14096d280()->vfunc_6():0,0x6200028)){Unk_UpperConfigData* cfg=FUN_1409a8b10()->FUN_140b123b0();FUN_1409b58f0(obj.operator->(),cfg->m_buff);}
   m_gauge->FUN_1422c6900(obj->FUN_1422bb870());
   m_buffs.SetAt(key,obj);
  }
  FUN_1409b5940(obj.operator->(),buff);
}
MS2_REPLACE_METHOD(0x141B4AC50, UpperHpBarEntity, FUN_141b4ac50, 1137, 0xA5388BA2);
// @0x141b4b3f0
void UpperHpBarEntity::FUN_141b4b3f0(){for(POSITION pos=m_buffs.GetStartPosition();pos;m_buffs.GetNext(pos)){Unk_UpperPtr<ASDisplayObject> buff=m_buffs.GetValueAt(pos);m_gauge->FUN_1422c6b70(buff->FUN_1422bb870());}}
MS2_REPLACE_METHOD(0x141B4B3F0, UpperHpBarEntity, FUN_141b4b3f0, 259, 0x54C4F728);

// @0x141b4b0d0
void UpperHpBarEntity::FUN_141b4b0d0(Unk_UpperPtr<Unk_UpperBuff> buff){
 if(buff==0||buff->FUN_14096d280()==0){MS2_ASSERT_AT(140,0);return;}
 if(m_clip==0){m_pending.FUN_1419f5260(buff->FUN_14096d260(),buff);return;}
 Unk_UpperPtr<ASDisplayObject> obj;
 if(m_buffs.Lookup(FUN_14123c580(buff->FUN_14096d280()),obj))FUN_1409b5aa0(obj.operator->(),buff);
}
MS2_REPLACE_METHOD(0x141B4B0D0, UpperHpBarEntity, FUN_141b4b0d0, 354, 0x44015F7B);
// @0x141b4b240
void UpperHpBarEntity::FUN_141b4b240(Unk_UpperActor* actor,const int& id){
 if(m_clip==0){m_pending.FUN_1419f5130(id);}
 else{
  Unk_UpperPtr<ASDisplayObject> obj;
  if(m_buffs.Lookup(FUN_14123c580(actor),obj))FUN_1409b5b60(obj.operator->(),id);
  Unk_UpperPtr<Unk_UpperBuff> ref=FUN_1416749a0(actor)->FUN_140972690();
  if(ref.get()!=0){
   if(ref->FUN_14096d260()==id){
    Unk_UpperTargetUI* ui=FUN_140974280(0x4f73);
    if(ui!=0){
     if(ui->FUN_141986d30()!=0){
      Unk_UpperPtr<Unk_UpperBuff> cur=ui->FUN_140c5f990();
      if(cur.get()!=0){if(cur->FUN_14096d260()==ref->FUN_14096d260())ui->FUN_140c5faf0();}
     }
    }
   }
  }
 }
}
MS2_REPLACE_METHOD(0x141B4B240, UpperHpBarEntity, FUN_141b4b240, 422, 0xB9F4F251);
// @0x141b4b500
void UpperHpBarEntity::FUN_141b4b500(){
 if(m_clip==0)return;
 if(m_id==0)return;
 if(!GetVisible())return;
 {
  Unk_UpperActor* actor=FUN_1409ffd30(FUN_1403ed2d0()->FUN_141bd1180(m_id));
  if(actor==0){m_id=0;m_hp=0;}
  else{
   Unk_UpperPtr<ASDisplayObject> obj;
   if(m_buffs.Lookup(m_id,obj))FUN_1409b5610(obj.operator->());
   __int64 cur=0;__int64 max=0;CStringW hp;CStringW shield;int stage=0;
   bool normal=(m_kind==0);
   FUN_141b4a150(actor,normal,&stage,&cur,&max,&hp,&shield);
   if(m_hp==cur){
    Unk_UpperNpc* npc=FUN_14096e110(actor);
    if(npc!=0&&cur>0&&npc->FUN_141093030()!=0&&npc->vfunc_65()!=0)m_clip.operator->()->FUN_1407cbbe0("m_delayHide",true);
    return;
   }
   m_clip.operator->()->Invoke("update",cur,hp,stage,shield);
   m_hp=cur;
  }
 }
}
MS2_REPLACE_METHOD(0x141B4B500, UpperHpBarEntity, FUN_141b4b500, 847, 0xC9E245A6);
// @0x141b4b860
void UpperHpBarEntity::FUN_141b4b860(){for(POSITION pos=m_buffs.GetStartPosition();pos;m_buffs.GetNext(pos)){int id=m_buffs.GetKeyAt(pos);Unk_UpperPtr<ASDisplayObject> buff=m_buffs.GetValueAt(pos);buff->vfunc_4(id==m_id);}}
MS2_REPLACE_METHOD(0x141B4B860, UpperHpBarEntity, FUN_141b4b860, 230, 0x137E47DF);

// @0x141b4b950
void UpperHpBarEntity::FUN_141b4b950(bool show){for(POSITION pos=m_buffs.GetStartPosition();pos;m_buffs.GetNext(pos)){int id=m_buffs.GetKeyAt(pos);void* actor=FUN_1403ed2d0()->FUN_141bd1320(id);if(!actor)continue;{Unk_UpperPtr<ASDisplayObject> buff=m_buffs.GetValueAt(pos);FUN_1409b58f0(buff.operator->(),show);}}}
MS2_REPLACE_METHOD(0x141B4B950, UpperHpBarEntity, FUN_141b4b950, 228, 0xB7CA5092);

// @0x141b4ba40
void UpperHpBarEntity::FUN_141b4ba40(bool show){if(m_clip==0)return;if(m_gauge==0)return;Unk_UpperPtr<Unk_UpperHpText> hp=m_gauge->FUN_1409b4620("m_hp");if(hp.get())hp->vfunc_4(show);}
MS2_REPLACE_METHOD(0x141B4BA40, UpperHpBarEntity, FUN_141b4ba40, 217, 0x79C61FFD);

// @0x141b4bb20
void UpperHpBarEntity::FUN_141b4bb20(bool show){if(m_clip==0)return;if(m_visible!=show)m_clip->vfunc_4(show);m_visible=show;}
MS2_REPLACE_METHOD(0x141B4BB20, UpperHpBarEntity, FUN_141b4bb20, 120, 0xBFBA21E5);

// @0x141b4bba0
bool UpperHpBarEntity::GetVisible(){return m_visible;}
MS2_REPLACE_METHOD(0x141B4BBA0, UpperHpBarEntity, GetVisible, 15, 0x4AD18319);

// @0x141b4bbc0
const int& UpperHpBarEntity::FUN_141b4bbc0(){return m_kind;}
MS2_REPLACE_METHOD(0x141B4BBC0, UpperHpBarEntity, FUN_141b4bbc0, 15, 0x770B1889);

// @0x141b4bbe0
const int& UpperHpBarEntity::FUN_141b4bbe0(){return m_id;}
MS2_REPLACE_METHOD(0x141B4BBE0, UpperHpBarEntity, FUN_141b4bbe0, 11, 0x3BE09B6E);

// @0x141b4bc00
Unk_UpperPtr<Unk_UpperClip> UpperHpBarEntity::GetClip(){return m_clip;}
MS2_REPLACE_METHOD(0x141B4BC00, UpperHpBarEntity, GetClip, 65, 0x3F666686);

// @0x141b4bc50
void UpperHpBarEntity::FUN_141b4bc50(const int& id){m_id=id;}
MS2_REPLACE_METHOD(0x141B4BC50, UpperHpBarEntity, FUN_141b4bc50, 25, 0x7B199341);

// @0x141b4bc70
void UpperHpBarEntity::FUN_141b4bc70(const __int64& hp){m_hp=hp;}
MS2_REPLACE_METHOD(0x141B4BC70, UpperHpBarEntity, FUN_141b4bc70, 28, 0x6A7EEDBD);

// @0x141b4bca0
void UpperHpBarEntity::FUN_141b4bca0(const Scaleform::GFx::FunctionHandler::Params&){if(m_clip==0)return;m_visible=true;}
MS2_REPLACE_METHOD(0x141B4BCA0, UpperHpBarEntity, FUN_141b4bca0, 56, 0x3CEAE047);

// @0x141b4bce0
void UpperHpBarEntity::FUN_141b4bce0(const Scaleform::GFx::FunctionHandler::Params&){if(m_clip==0)return;m_visible=false;}
MS2_REPLACE_METHOD(0x141B4BCE0, UpperHpBarEntity, FUN_141b4bce0, 56, 0x7673962E);

// @0x141b4bd20
UIUpperHpBar::UIUpperHpBar():m_current(0){m_58=0;m_2c=18;FUN_141b4c4c0("m_accumDamage",0);FUN_141b4c4c0("m_boss",1);FUN_141b4c4c0("m_elite",2);FUN_141b4c4c0("m_normal",3);}
// @0x141b4bf00
UIUpperHpBar::~UIUpperHpBar(){}
// @0x141b4bf90
CString UIUpperHpBar::vfunc_1(){return "UpperHpBar";}
MS2_REPLACE_METHOD(0x141B4BF90, UIUpperHpBar, vfunc_1, 61, 0x046B9C17);

// @0x141b4bfe0
void UIUpperHpBar::OnLoadComplete(){UIObject::OnLoadComplete();FUN_140c607b0()->FUN_1419308c0(this);Unk_UpperAS data(2);bool showHp=FUN_1409a8b10()->FUN_140b123b0()->m_hp;data.FUN_1407cbbe0("displayHpValue",showHp);m_30->Invoke("initData",data.FUN_1422bb870());m_current=0;FUN_141b4ceb0(FUN_1409a8b10()->FUN_140b123b0()->m_buff);}
MS2_REPLACE_METHOD(0x141B4BFE0, UIUpperHpBar, OnLoadComplete, 326, 0xF892494F);

// @0x141b4c130
void UIUpperHpBar::vfunc_26(){UIObject::vfunc_26();FUN_140c607b0()->FUN_141930950(this);{UpperHpBarEntity* entities=m_entities;for(unsigned int i=0;i<4;++i){UpperHpBarEntity& entity=entities[static_cast<int>(i)];entity.FUN_141b4a840();}}m_current=0;}
MS2_REPLACE_METHOD(0x141B4C130, UIUpperHpBar, vfunc_26, 172, 0x8CC6B376);

// @0x141b4c1f0
void UIUpperHpBar::vfunc_41(const Scaleform::GFx::Value& root){m_30=FUN_140ba77e0(m_28,root);}
MS2_REPLACE_METHOD(0x141B4C1F0, UIUpperHpBar, vfunc_41, 99, 0x7DE369B1);

// @0x141b4c260
void UIUpperHpBar::vfunc_43(){MS2Ptr<ASGameEntity> root(dynamic_cast<ASGameEntity*>(static_cast<AScript*>(m_30)));if(root.get()){root->vfunc_2(1,0,0);root->vfunc_4(true);}}
MS2_REPLACE_METHOD(0x141B4C260, UIUpperHpBar, vfunc_43, 187, 0x941B81CC);

// @0x141b4c330
void UIUpperHpBar::vfunc_15(){UISwfEntity::vfunc_15();if(m_30==0)return;{UpperHpBarEntity* entities=m_entities;for(unsigned int i=0;i<4;++i){UpperHpBarEntity& entity=entities[static_cast<int>(i)];entity.FUN_141b4b500();}}}
MS2_REPLACE_METHOD(0x141B4C330, UIUpperHpBar, vfunc_15, 133, 0x4E60939D);

// @0x141b4c3c0
void UIUpperHpBar::vfunc_3(){UIHeadUpDisplay::vfunc_3();}
MS2_REPLACE_METHOD(0x141B4C3C0, UIUpperHpBar, vfunc_3, 24, 0x9F9232CC);

// @0x141b4c3e0
void UIUpperHpBar::vfunc_o70_2(const Unk_UpperEvt& evt){
 if(m_30==0)return;
 Unk_UpperActor* actor=FUN_1409ffd30(FUN_1403ed2d0()->FUN_141bd0fa0(evt));
 if(actor==0)return;
 UpperHpBarEntity& entity=FUN_141b4d170(actor);
 int kind=FUN_14123c580(actor);
 if(entity.FUN_141b4ab70(kind))m_current=0;
}
MS2_REPLACE_METHOD_VIA(0x141B4C3E0, UIUpperHpBar, UIEntityEventListener, vfunc_o70_2, 203, 0xF66E7D53);
// @0x141b4c510
void UIUpperHpBar::FUN_141b4c510(Unk_UpperActor* actor,int kind){
 if(m_30==0)return;
 if(FUN_1403ed2b0()->FUN_141adc890(0x4e96)!=0||FUN_1403ed2b0()->FUN_141adc890(0x4ec4)!=0)return;
 UpperHpBarEntity& e=FUN_141b4d170(actor);
 if(!FUN_141b4d630(e,kind,FUN_14123c580(actor)))return;
 if(!FUN_141b4d320(e))return;
 if(e.GetClip()==0){
  Scaleform::GFx::Value created=m_30->Invoke("createHpBar",e.FUN_141b4a820());
  Unk_UpperPtr<Unk_UpperClip> clip=FUN_140acca70(FUN_1422db730(),created);
  e.FUN_141b4a8b0(clip);
 }
 __int64 cur=0;__int64 max=0;int stage=0;CStringW hp;CStringW shield;
 bool normal=false;if(e.FUN_141b4bbc0()==0)normal=true;
 FUN_141b4a150(actor,normal,&stage,&cur,&max,&hp,&shield);
 bool timer=true;
 Unk_UpperNpc* npc=FUN_14096e110(actor);
 bool isBoss=npc&&npc->FUN_141093270()->FUN_1406cd200(4);
 if(isBoss)timer=false;
 ASObj args(2);
 args.FUN_1407cba60("id",FUN_141b4d690(actor));
 args.FUN_1409c1180("prev",max);
 args.FUN_1409c1180("cur",cur);
 args.FUN_1409c1180("max",actor->FUN_141670a30(4));
 args.FUN_1407cbb20("strName",actor->vfunc_77());
 args.FUN_1407cbb20("strType",FUN_141b4d710(actor));
 args.FUN_1409c48f0("level",actor->vfunc_79());
 args.FUN_1407cbbe0("timer",timer);
 args.FUN_1407cbbe0("isShowTag",FUN_141b4d860(actor));
 args.FUN_1407cbb20("tagName",shield);
 args.FUN_1409c0d20("jobCode",FUN_141b4d8a0(actor));
 args.FUN_1407cb9c0("step",stage);
 args.FUN_1407cbb20("hpText",hp);
 e.FUN_141b4bc50(FUN_14123c580(actor));
 e.FUN_141b4bc70(cur);
 Unk_UpperClip* gauge=e.GetClip().get();
 if(gauge!=0){
  e.GetClip()->Invoke("setHP",args);
  e.FUN_141b4b860();
 }
 Unk_UpperTargetUI* ui=FUN_140974280(0x4f73);
 if(ui!=0){
  Unk_UpperPtr<Unk_UpperBuff> buff=FUN_1416749a0(actor)->FUN_140972690();
  bool changed=ui->FUN_141986d30()!=0&&buff.get()!=ui->FUN_140c5f990().get();
  if(changed)ui->vfunc_3();
  if(buff.get()!=0){
   if(*(int*)(buff.operator->()->FUN_14096d810()+0x2b0)!=0)ui->FUN_140c5f8f0(buff);
  }
 }
 m_current=&e;
}
MS2_REPLACE_METHOD(0x141B4C510, UIUpperHpBar, FUN_141b4c510, 2307, 0x2E7D8AFC);
// @0x141b4c4c0
void UIUpperHpBar::FUN_141b4c4c0(const CString& name,const int& kind){m_entities[kind].FUN_141b4a7d0(name,kind);}
MS2_REPLACE_METHOD(0x141B4C4C0, UIUpperHpBar, FUN_141b4c4c0, 67, 0xCFED0236);

// @0x141b4ce20
void UIUpperHpBar::FUN_141b4ce20(bool show){if(m_30==0)return;{UpperHpBarEntity* entities=m_entities;for(unsigned int i=0;i<4;++i){UpperHpBarEntity& entity=entities[static_cast<int>(i)];entity.FUN_141b4ba40(show);}}}
MS2_REPLACE_METHOD(0x141B4CE20, UIUpperHpBar, FUN_141b4ce20, 132, 0xE0E175AB);

// @0x141b4ceb0
void UIUpperHpBar::FUN_141b4ceb0(bool show){if(m_30==0)return;{UpperHpBarEntity* entities=m_entities;for(unsigned int i=0;i<4;++i){UpperHpBarEntity& entity=entities[static_cast<int>(i)];entity.FUN_141b4b950(show);}}}
MS2_REPLACE_METHOD(0x141B4CEB0, UIUpperHpBar, FUN_141b4ceb0, 132, 0xE3C6703A);

// @0x141b4cf40
void UIUpperHpBar::FUN_141b4cf40(Unk_UpperPtr<Unk_UpperBuff> buff){FUN_141b4d170(buff->FUN_14096d280()).FUN_141b4ac50(buff);}
MS2_REPLACE_METHOD(0x141B4CF40, UIUpperHpBar, FUN_141b4cf40, 124, 0xCE7E3D09);

// @0x141b4cfd0
void UIUpperHpBar::FUN_141b4cfd0(Unk_UpperPtr<Unk_UpperBuff> buff){FUN_141b4d170(buff->FUN_14096d280()).FUN_141b4b0d0(buff);}
MS2_REPLACE_METHOD(0x141B4CFD0, UIUpperHpBar, FUN_141b4cfd0, 124, 0xCF63FB8F);

// @0x141b4d060
void UIUpperHpBar::FUN_141b4d060(Unk_UpperActor* actor,int id){FUN_141b4d170(actor).FUN_141b4b240(actor,id);}
MS2_REPLACE_METHOD(0x141B4D060, UIUpperHpBar, FUN_141b4d060, 57, 0xEA91662F);

// @0x141b4d0a0
void UIUpperHpBar::FUN_141b4d0a0(){if(FUN_1422dc430()){UpperHpBarEntity* entities=m_entities;for(unsigned int i=0;i<4;++i){UpperHpBarEntity& entity=entities[static_cast<int>(i)];entity.FUN_141b4b3f0();}}}
MS2_REPLACE_METHOD(0x141B4D0A0, UIUpperHpBar, FUN_141b4d0a0, 109, 0x0D08AA72);

// @0x141b4d120
int UIUpperHpBar::vfunc_28(const char* method,const Scaleform::GFx::Value* args,unsigned int count){if(UISwfEntity::vfunc_28(method,args,count))return 1;return 0;}
MS2_REPLACE_METHOD(0x141B4D120, UIUpperHpBar, vfunc_28, 67, 0xCDAB7DE3);

// @0x141b4d170
UpperHpBarEntity& UIUpperHpBar::FUN_141b4d170(void* actor){
 Unk_UpperNpc* npc=FUN_14096e110(actor);
 if(npc){if(npc->FUN_141093270()->FUN_1406cd200(5))return m_entities[0];
 int kind=npc->FUN_141093270()->FUN_1406cd040();switch(kind){case 4:case 6:return m_entities[1];case 3:case 7:return m_entities[2];default:return m_entities[3];}}
 Unk_UpperPC* pc=FUN_140974230(actor);if(pc)return m_entities[1];return m_entities[3];
}
MS2_REPLACE_METHOD(0x141B4D170, UIUpperHpBar, FUN_141b4d170, 411, 0xEE28EACC);
// @0x141b4d320
bool UIUpperHpBar::FUN_141b4d320(UpperHpBarEntity& target){
 if(m_current!=0&&m_current->GetVisible()==true){
  Unk_UpperNpc* npc=FUN_140a38a00(FUN_1403ed2d0()->FUN_141bd1180(m_current->FUN_141b4bbe0()));
  bool isBoss=npc&&npc->FUN_141093270()->FUN_1406cd200(4);
  if(isBoss)return false;
 }
 int kind=target.FUN_141b4bbc0();
 if(kind==3){
  if(m_entities[1].GetVisible()){Unk_UpperNpc* npc1=FUN_140a38a00(FUN_1403ed2d0()->FUN_141bd1180(m_entities[1].FUN_141b4bbe0()));if(npc1!=0)return false;}
  if(m_entities[0].GetVisible()){Unk_UpperNpc* npc0=FUN_140a38a00(FUN_1403ed2d0()->FUN_141bd1180(m_entities[0].FUN_141b4bbe0()));if(npc0!=0)return false;}
  if(m_entities[2].GetVisible())return false;
 }
 FUN_141b4d5c0();
 m_entities[kind].FUN_141b4bb20(true);
 return true;
}
MS2_REPLACE_METHOD(0x141B4D320, UIUpperHpBar, FUN_141b4d320, 660, 0xFDBB1952);
// @0x141b4d5c0
void UIUpperHpBar::FUN_141b4d5c0(){{UpperHpBarEntity* entities=m_entities;for(unsigned int i=0;i<4;++i){UpperHpBarEntity& entity=entities[static_cast<int>(i)];entity.FUN_141b4bb20(false);}}}
MS2_REPLACE_METHOD(0x141B4D5C0, UIUpperHpBar, FUN_141b4d5c0, 97, 0xA3A3684D);

// @0x141b4d630
bool UIUpperHpBar::FUN_141b4d630(UpperHpBarEntity& entity,int kind,int id){if(kind==g_upperTargetId)return true;if(entity.GetVisible()&&entity.FUN_141b4bbe0()==id)return true;return false;}
MS2_REPLACE_METHOD(0x141B4D630, UIUpperHpBar, FUN_141b4d630, 86, 0xFD636C18);
// @0x141b4d690
CString UIUpperHpBar::FUN_141b4d690(void* actor){CString id=FUN_140b62550(FUN_14123c580(actor));return id;}
MS2_REPLACE_METHOD(0x141B4D690, UIUpperHpBar, FUN_141b4d690, 107, 0xEA6EC0D6);

// @0x141b4d710
CStringW UIUpperHpBar::FUN_141b4d710(void* actor){Unk_UpperPC* pc=FUN_140974230(actor);if(pc){return FUN_1401a9d70()->FUN_141811980(6,pc->FUN_141654730());}else{Unk_UpperNpc* npc=FUN_14096e110(actor);if(npc)return FUN_1401a9d70()->FUN_141811980(17,npc->FUN_141093270()->FUN_1406cd310());}return L"";}
MS2_REPLACE_METHOD(0x141B4D710, UIUpperHpBar, FUN_141b4d710, 322, 0x42472180);
// @0x141b4d860
bool UIUpperHpBar::FUN_141b4d860(void* actor){return FUN_14096e110(actor)!=0;}
MS2_REPLACE_METHOD(0x141B4D860, UIUpperHpBar, FUN_141b4d860, 57, 0xEC468757);

// @0x141b4d8a0
int UIUpperHpBar::FUN_141b4d8a0(void* actor){Unk_UpperPC* pc=FUN_140974230(actor);if(!pc)return 0;return pc->FUN_141654730();}
MS2_REPLACE_METHOD(0x141B4D8A0, UIUpperHpBar, FUN_141b4d8a0, 56, 0xE9446796);

// @0x141b4da00
inline Scaleform::GFx::Value AScript::Invoke(const char* szMethod,__int64 a1,CStringW a2,int a3,CStringW a4){
 ASArgList args;
 args.FUN_1409b2800(4);
 FUN_1422bcdd0(args.FUN_1409b1f70(0),a1);
 FUN_1422bcea0(args.FUN_1409b1f70(1),a2);
 FUN_1422bccb0(args.FUN_1409b1f70(2),a3);
 FUN_1422bcea0(args.FUN_1409b1f70(3),a4);
 return FUN_1422bb8f0(szMethod,args);
}
