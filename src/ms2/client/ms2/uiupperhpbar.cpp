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
#include "ms2/placeholder/cstringtable.h"
#include "ms2/placeholder/fittingdollpc.h"
#include "ms2/client/ms2/uiservice.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/placeholder/cgameoption.h"
#include "ms2/placeholder/wcformat.h"
#include "ms2/client/ms2/pcbase.h"  // C3: PCBase (efd::DynamicCast<PCBase, GameObject>)
#include "ms2/client/ms2/additionalcli.h"
#include "ms2/client/ms2/additionalclilist.h"
#include "ms2/client/ms2/aseffect.h"
#include "ms2/placeholder/asuicomponent.h"
#include "ms2/placeholder/asgameentity.h"
#include "ms2/placeholder/cnpc.h"
#include "ms2/ms2format.h"
// The recovered initializer run contains two copies of the header's static data.
namespace Unk_UpperHeaderStatics {
static CString sortNames[]={"None","Buy","Like","PriceLow","PriceHigh","Create","EnumEnd"};
static CString skill="skill";static CString stun="stun";
static Unk_1402a9d70 condition(17,0.75f,0.25f,2.25f,10);
}
class Unk_UpperEvents {public:void FUN_1419308c0(UIEntityEventListener*);void FUN_141930950(UIEntityEventListener*);};
class Unk_LsEntityEvents* FUN_140c607b0();   // C3: was FUN_140c607b0
class Unk_UpperConfigData {public:int m_0;short m_4;char m_6;bool m_hp;char m_8;bool m_buff;};
CString FUN_140b62550(unsigned int);
class Unk_WsC_GameObj : public GameObject {};   // C3: WorldService::FUN_141bd1180 result (static_cast to GameObject)
template<class T> MS2Ptr<T> Unk_ASCreate(int,const Scaleform::GFx::Value&);
MS2Ptr<ASGameEntity> FUN_140ba77e0(int,const Scaleform::GFx::Value&);

// ---- recovered callee shapes for the buff/target handlers (names invented; FUN_ names are exe addresses) ----
MS2Ptr<ASEffectManager> FUN_140e6cd80(int,CString,__int64,int);
template <> MS2Ptr<ASEffectManager>::MS2Ptr(const MS2Ptr& o) { m_p = o.m_p; AddRef(); }   // 0x141b4dd40
// Slot 6 of the actor vftable (the class info getter); PCBase does not declare it.
class Unk_UpperActor {public:
 virtual ~Unk_UpperActor();virtual void vfunc_1();virtual void vfunc_2();virtual void vfunc_3();virtual void vfunc_4();virtual void vfunc_5();virtual void* vfunc_6();};
CStringW FUN_1401aa6a0(int);
class UILapenshardShieldBar : public UIHeadUpDisplay {public:void FUN_140c5f8f0(MS2Ptr<AdditionalCli>);MS2Ptr<AdditionalCli> GetBuff();void FUN_140c5faf0();};
template<class T> T* Unk_AcFindUI(eUIClassID);
class Unk_CameraTargetEntity* FUN_140a38a00(class Unk_BossObject*);   // C3: was FUN_140a38a00
void FUN_1422bcdd0(Scaleform::GFx::Value*,__int64);void FUN_1422bcea0(Scaleform::GFx::Value*,const wchar_t*);void FUN_1422bccb0(Scaleform::GFx::Value*,int);

class Unk_UpperPC : public PC { };
extern int g_upperTargetId;
// Remaining target-stat calculation and buff population routines are declarations above.
// @0x141b4a150
void FUN_141b4a150(PCBase* actor,bool flag,int* stage,__int64* cur,__int64* max,CStringW* hpText,CStringW* shieldText){
 if(actor==0)return;
 *max=actor->FUN_141670a60(4);
 __int64 base;
 if(actor->IsDead()!=0)base=0;else base=actor->FUN_141670a00(4);
 *cur=base;
 *hpText=StringFormat(L"{0}",*cur);
 *stage=0;
 if(flag==true){
 CNpc* npc=efd::DynamicCast<CNpc, PCBase>(reinterpret_cast<PCBase*>(actor));
 bool isBoss=npc&&npc->GetNpcData().operator->()->HasPropertyTag(5);
 if(isBoss){
  const __int64& total=npc->FUN_141095270();
  const __int64& unit=npc->FUN_141670a30(4);
  *stage=(int)(total/unit+1);
  if(total>unit){
   __int64 over=total-unit;
   *cur=over%unit;
   *hpText=StringFormat(L"{0}",over);
   *shieldText=FUN_14028dfa0<CStringW>(L"s_upper_hp_bar_accum_damage",FUN_1401aa6a0(npc->FUN_141092fa0()));
  }else{
   __int64 rest=unit-total;
   *cur=rest;
   *hpText=StringFormat(L"{0}",*cur);
   *shieldText=FUN_14028dfa0<CStringW>(L"s_upper_hp_bar_accum_damage_shield",FUN_1401aa6a0(npc->FUN_141092fa0()));
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
void UpperHpBarEntity::FUN_141b4a840(){FUN_141b4b3f0();m_clip=0;m_gauge=0;m_pending.RemoveAll();m_buffs.RemoveAll();}
MS2_REPLACE_METHOD(0x141B4A840, UpperHpBarEntity, FUN_141b4a840, 98, 0x735A1D01);

// @0x141b4a8b0
void UpperHpBarEntity::FUN_141b4a8b0(MS2Ptr<ASUIComponent> clip){
 if(clip==0||clip->IsUndefinedOrNull()==true)return;
 m_clip=clip;m_visible=m_clip->GetVisible();
 clip->AddShowHandler(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this,&UpperHpBarEntity::FUN_141b4bca0),0);
 clip->AddHideHandler(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this,&UpperHpBarEntity::FUN_141b4bce0),0);
 m_gauge=clip->FUN_1409b4560("m_gauge");
 for(POSITION pos=m_pending.GetStartPosition();pos;m_pending.GetNext(pos)){FUN_141b4ac50(m_pending.GetValueAt(pos));}m_pending.RemoveAll();
}
MS2_REPLACE_METHOD(0x141B4A8B0, UpperHpBarEntity, FUN_141b4a8b0, 686, 0x8A562DEA);

// @0x141b4ab70
bool UpperHpBarEntity::DestroyEntity(const int& id){if(m_id!=id)return false;m_id=0;m_hp=0;if(m_clip.get())m_clip->Invoke("destroyEntity",FUN_140b62550(id));return true;}
MS2_REPLACE_METHOD(0x141B4AB70, UpperHpBarEntity, DestroyEntity, 215, 0xE47BB395);

// @0x141b4ac50
void UpperHpBarEntity::FUN_141b4ac50(MS2Ptr<AdditionalCli> buff){
 if(buff==0||buff.operator->()->GetOwner()==0){MS2_ASSERT_AT(89,0);return;}
  if(m_clip==0){m_pending.SetAt(buff.operator->()->GetKey(),buff);return;}
  const int& key=((class GameObject*)(void*)(buff.operator->()->GetOwner()))->FUN_14123c580();
  MS2Ptr<ASEffectManager> obj;
  if(!m_buffs.Lookup(key,obj)){
   obj=FUN_140e6cd80(2,"flash.display.MovieClip",0,0);
   if(m_kind==0){((class ASEffectManager*)(class ASDisplayObject*)(obj.operator->()))->SetPosA(0x5c, 0x5a);((class ASEffectManager*)(class ASDisplayObject*)(obj.operator->()))->SetPosB(0x1a6, 0x5a);((class ASEffectManager*)(class ASDisplayObject*)(obj.operator->()))->SetColumns(7);}
   else if(m_kind==1){((class ASEffectManager*)(class ASDisplayObject*)(obj.operator->()))->SetPosA(0x48, -32);((class ASEffectManager*)(class ASDisplayObject*)(obj.operator->()))->SetPosB(0x48, 0x56);}
   else{((class ASEffectManager*)(class ASDisplayObject*)(obj.operator->()))->SetPosA(0x2e, -42);((class ASEffectManager*)(class ASDisplayObject*)(obj.operator->()))->SetPosB(0x2e, 0x34);}
   ((class ASEffectManager*)(class ASDisplayObject*)(obj.operator->()))->SetMax(0xf);
   if(efd::ClassInfo::IsKindOf((const efd::ClassInfo*)(buff.operator->()->GetOwner()?reinterpret_cast<Unk_UpperActor*>(buff.operator->()->GetOwner())->vfunc_6():0),0x6200028)){Unk_UpperConfigData* cfg=reinterpret_cast<Unk_UpperConfigData*>(TSingleton<CGameOption>::GetInstance()->FUN_140b123b0());((class ASEffectManager*)(class ASDisplayObject*)(obj.operator->()))->SetFilter(cfg->m_buff);}
   m_gauge->FUN_1422c6900(obj->FUN_1422bb870());
   m_buffs.SetAt(key,obj);
  }
  ((class ASEffectManager*)(class ASDisplayObject*)(obj.operator->()))->AddEffect(buff);
}
MS2_REPLACE_METHOD(0x141B4AC50, UpperHpBarEntity, FUN_141b4ac50, 1137, 0xA5388BA2);
// @0x141b4b3f0
void UpperHpBarEntity::FUN_141b4b3f0(){for(POSITION pos=m_buffs.GetStartPosition();pos;m_buffs.GetNext(pos)){MS2Ptr<ASEffectManager> buff=m_buffs.GetValueAt(pos);m_gauge->FUN_1422c6b70(buff->FUN_1422bb870());}}
MS2_REPLACE_METHOD(0x141B4B3F0, UpperHpBarEntity, FUN_141b4b3f0, 259, 0x54C4F728);

// @0x141b4b0d0
void UpperHpBarEntity::FUN_141b4b0d0(MS2Ptr<AdditionalCli> buff){
 if(buff==0||buff.operator->()->GetOwner()==0){MS2_ASSERT_AT(140,0);return;}
 if(m_clip==0){m_pending.SetAt(buff.operator->()->GetKey(),buff);return;}
 MS2Ptr<ASEffectManager> obj;
 if(m_buffs.Lookup(((class GameObject*)(void*)(buff.operator->()->GetOwner()))->FUN_14123c580(),obj))((class ASEffectManager*)(class ASDisplayObject*)(obj.operator->()))->UpdateEffect(buff);
}
MS2_REPLACE_METHOD(0x141B4B0D0, UpperHpBarEntity, FUN_141b4b0d0, 354, 0x44015F7B);
// @0x141b4b240
void UpperHpBarEntity::FUN_141b4b240(PCBase* actor,const int& id){
 if(m_clip==0){m_pending.RemoveKey(id);}
 else{
  MS2Ptr<ASEffectManager> obj;
  if(m_buffs.Lookup(((class GameObject*)(void*)(actor))->FUN_14123c580(),obj))((class ASEffectManager*)(class ASDisplayObject*)(obj.operator->()))->RemoveEffect(id);
  MS2Ptr<AdditionalCli> ref=reinterpret_cast<AdditionalCliList*>(((class PCBase*)(void*)(actor))->FUN_1416749a0())->GetShield();
  if(ref.get()!=0){
   if(ref->GetKey()==id){
    UILapenshardShieldBar* ui=Unk_AcFindUI<UILapenshardShieldBar>((eUIClassID)0x4f73);
    if(ui!=0){
     if(ui->FUN_141986d30()!=0){
      MS2Ptr<AdditionalCli> cur=ui->GetBuff();
      if(cur.get()!=0){if(cur->GetKey()==ref->GetKey())ui->FUN_140c5faf0();}
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
  PCBase* actor=efd::DynamicCast<PCBase, GameObject>(static_cast<GameObject*>(WorldService::GetInstance()->FindObjectById(m_id)));
  if(actor==0){m_id=0;m_hp=0;}
  else{
   MS2Ptr<ASEffectManager> obj;
   if(m_buffs.Lookup(m_id,obj))((class ASEffectManager*)(class ASDisplayObject*)(obj.operator->()))->Update();
   __int64 cur=0;__int64 max=0;CStringW hp;CStringW shield;int stage=0;
   bool normal=(m_kind==0);
   FUN_141b4a150(actor,normal,&stage,&cur,&max,&hp,&shield);
   if(m_hp==cur){
    CNpc* npc=efd::DynamicCast<CNpc, PCBase>(reinterpret_cast<PCBase*>(actor));
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
void UpperHpBarEntity::FUN_141b4b860(){for(POSITION pos=m_buffs.GetStartPosition();pos;m_buffs.GetNext(pos)){int id=m_buffs.GetKeyAt(pos);MS2Ptr<ASEffectManager> buff=m_buffs.GetValueAt(pos);buff->vfunc_4(id==m_id);}}
MS2_REPLACE_METHOD(0x141B4B860, UpperHpBarEntity, FUN_141b4b860, 230, 0x137E47DF);

// @0x141b4b950
void UpperHpBarEntity::FUN_141b4b950(bool show){for(POSITION pos=m_buffs.GetStartPosition();pos;m_buffs.GetNext(pos)){int id=m_buffs.GetKeyAt(pos);void* actor=WorldService::GetInstance()->FUN_141bd1320(id);if(!actor)continue;{MS2Ptr<ASEffectManager> buff=m_buffs.GetValueAt(pos);((class ASEffectManager*)(class ASDisplayObject*)(buff.operator->()))->SetFilter(show);}}}
MS2_REPLACE_METHOD(0x141B4B950, UpperHpBarEntity, FUN_141b4b950, 228, 0xB7CA5092);

// @0x141b4ba40
void UpperHpBarEntity::FUN_141b4ba40(bool show){if(m_clip==0)return;if(m_gauge==0)return;MS2Ptr<ASTextField> hp=m_gauge->FUN_1409b4620("m_hp");if(hp.get())hp->vfunc_4(show);}
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
MS2Ptr<ASUIComponent> UpperHpBarEntity::GetClip(){return m_clip;}
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
CString UIUpperHpBar::GetTypeName(){return "UpperHpBar";}
MS2_REPLACE_METHOD(0x141B4BF90, UIUpperHpBar, GetTypeName, 61, 0x046B9C17);

// @0x141b4bfe0
void UIUpperHpBar::OnLoadComplete(){UIObject::OnLoadComplete();((class Unk_UpperEvents*)FUN_140c607b0())->FUN_1419308c0(this);AScript data(2);bool showHp=reinterpret_cast<Unk_UpperConfigData*>(TSingleton<CGameOption>::GetInstance()->FUN_140b123b0())->m_hp;data.FUN_1407cbbe0("displayHpValue",showHp);m_30->Invoke("initData",data.FUN_1422bb870());m_current=0;FUN_141b4ceb0(reinterpret_cast<Unk_UpperConfigData*>(TSingleton<CGameOption>::GetInstance()->FUN_140b123b0())->m_buff);}
MS2_REPLACE_METHOD(0x141B4BFE0, UIUpperHpBar, OnLoadComplete, 326, 0xF892494F);

// @0x141b4c130
void UIUpperHpBar::vfunc_26(){UIObject::vfunc_26();((class Unk_UpperEvents*)FUN_140c607b0())->FUN_141930950(this);{UpperHpBarEntity* entities=m_entities;for(unsigned int i=0;i<4;++i){UpperHpBarEntity& entity=entities[static_cast<int>(i)];entity.FUN_141b4a840();}}m_current=0;}
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
void UIUpperHpBar::vfunc_o70_2(const void* pId){
 if(m_30==0)return;
 PCBase* actor=efd::DynamicCast<PCBase, GameObject>(static_cast<GameObject*>(WorldService::GetInstance()->FindObjectByEntityId(*static_cast<const egf::EntityID*>(pId))));
 if(actor==0)return;
 UpperHpBarEntity& entity=FUN_141b4d170(actor);
 int kind=((class GameObject*)(void*)(actor))->FUN_14123c580();
 if(entity.DestroyEntity(kind))m_current=0;
}
MS2_REPLACE_METHOD_VIA(0x141B4C3E0, UIUpperHpBar, UIEntityEventListener, vfunc_o70_2, 203, 0xF66E7D53);
// @0x141b4c510
void UIUpperHpBar::FUN_141b4c510(PCBase* actor,int kind){
 if(m_30==0)return;
 if((((CUIService*)(TSingleton<CUIService>::GetInstance()))->FUN_141adc890((eUIClassID)(0x4e96)))!=0||(((CUIService*)(TSingleton<CUIService>::GetInstance()))->FUN_141adc890((eUIClassID)(0x4ec4)))!=0)return;
 UpperHpBarEntity& e=FUN_141b4d170(actor);
 if(!FUN_141b4d630(e,kind,((class GameObject*)(void*)(actor))->FUN_14123c580()))return;
 if(!FUN_141b4d320(e))return;
 if(e.GetClip()==0){
  Scaleform::GFx::Value created=m_30->Invoke("createHpBar",e.FUN_141b4a820());
  MS2Ptr<ASUIComponent> clip=Unk_ASCreate<ASUIComponent>(FUN_1422db730(),created);
  e.FUN_141b4a8b0(clip);
 }
 __int64 cur=0;__int64 max=0;int stage=0;CStringW hp;CStringW shield;
 bool normal=false;if(e.FUN_141b4bbc0()==0)normal=true;
 FUN_141b4a150(actor,normal,&stage,&cur,&max,&hp,&shield);
 bool timer=true;
 CNpc* npc=efd::DynamicCast<CNpc, PCBase>(reinterpret_cast<PCBase*>(actor));
 bool isBoss=npc&&npc->GetNpcData().operator->()->HasPropertyTag(4);
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
 e.FUN_141b4bc50(((class GameObject*)(void*)(actor))->FUN_14123c580());
 e.FUN_141b4bc70(cur);
 ASUIComponent* gauge=e.GetClip().get();
 if(gauge!=0){
  e.GetClip()->Invoke("setHP",args);
  e.FUN_141b4b860();
 }
 UILapenshardShieldBar* ui=Unk_AcFindUI<UILapenshardShieldBar>((eUIClassID)0x4f73);
 if(ui!=0){
  MS2Ptr<AdditionalCli> buff=reinterpret_cast<AdditionalCliList*>(((class PCBase*)(void*)(actor))->FUN_1416749a0())->GetShield();
  bool changed=ui->FUN_141986d30()!=0&&buff.get()!=ui->GetBuff().get();
  if(changed)ui->vfunc_3();
  if(buff.get()!=0){
   if(*(int*)((char*)buff.operator->()->FUN_14096d810()+0x2b0)!=0)ui->FUN_140c5f8f0(buff);
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
void UIUpperHpBar::FUN_141b4cf40(MS2Ptr<AdditionalCli> buff){FUN_141b4d170(buff.operator->()->GetOwner()).FUN_141b4ac50(buff);}
MS2_REPLACE_METHOD(0x141B4CF40, UIUpperHpBar, FUN_141b4cf40, 124, 0xCE7E3D09);

// @0x141b4cfd0
void UIUpperHpBar::FUN_141b4cfd0(MS2Ptr<AdditionalCli> buff){FUN_141b4d170(buff.operator->()->GetOwner()).FUN_141b4b0d0(buff);}
MS2_REPLACE_METHOD(0x141B4CFD0, UIUpperHpBar, FUN_141b4cfd0, 124, 0xCF63FB8F);

// @0x141b4d060
void UIUpperHpBar::FUN_141b4d060(PCBase* actor,int id){FUN_141b4d170(actor).FUN_141b4b240(actor,id);}
MS2_REPLACE_METHOD(0x141B4D060, UIUpperHpBar, FUN_141b4d060, 57, 0xEA91662F);

// @0x141b4d0a0
void UIUpperHpBar::FUN_141b4d0a0(){if(FUN_1422dc430()){UpperHpBarEntity* entities=m_entities;for(unsigned int i=0;i<4;++i){UpperHpBarEntity& entity=entities[static_cast<int>(i)];entity.FUN_141b4b3f0();}}}
MS2_REPLACE_METHOD(0x141B4D0A0, UIUpperHpBar, FUN_141b4d0a0, 109, 0x0D08AA72);

// @0x141b4d120
int UIUpperHpBar::vfunc_28(const char* method,const Scaleform::GFx::Value* args,unsigned int count){if(UISwfEntity::vfunc_28(method,args,count))return 1;return 0;}
MS2_REPLACE_METHOD(0x141B4D120, UIUpperHpBar, vfunc_28, 67, 0xCDAB7DE3);

// @0x141b4d170
UpperHpBarEntity& UIUpperHpBar::FUN_141b4d170(void* actor){
 CNpc* npc=efd::DynamicCast<CNpc, PCBase>(reinterpret_cast<PCBase*>(actor));
 if(npc){if(npc->GetNpcData().operator->()->HasPropertyTag(5))return m_entities[0];
 int kind=npc->GetNpcData().operator->()->GetClass();switch(kind){case 4:case 6:return m_entities[1];case 3:case 7:return m_entities[2];default:return m_entities[3];}}
 Unk_UpperPC* pc=reinterpret_cast<Unk_UpperPC*>(efd::DynamicCast<PC, PCBase>(reinterpret_cast<PCBase*>(actor)));if(pc)return m_entities[1];return m_entities[3];
}
MS2_REPLACE_METHOD(0x141B4D170, UIUpperHpBar, FUN_141b4d170, 411, 0xEE28EACC);
// @0x141b4d320
bool UIUpperHpBar::FUN_141b4d320(UpperHpBarEntity& target){
 if(m_current!=0&&m_current->GetVisible()==true){
  CNpc* npc=((class CNpc*)FUN_140a38a00((class Unk_BossObject*)(WorldService::GetInstance()->FindObjectById(m_current->FUN_141b4bbe0()))));
  bool isBoss=npc&&npc->GetNpcData().operator->()->HasPropertyTag(4);
  if(isBoss)return false;
 }
 int kind=target.FUN_141b4bbc0();
 if(kind==3){
  if(m_entities[1].GetVisible()){CNpc* npc1=((class CNpc*)FUN_140a38a00((class Unk_BossObject*)(WorldService::GetInstance()->FindObjectById(m_entities[1].FUN_141b4bbe0()))));if(npc1!=0)return false;}
  if(m_entities[0].GetVisible()){CNpc* npc0=((class CNpc*)FUN_140a38a00((class Unk_BossObject*)(WorldService::GetInstance()->FindObjectById(m_entities[0].FUN_141b4bbe0()))));if(npc0!=0)return false;}
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
CString UIUpperHpBar::FUN_141b4d690(void* actor){CString id=FUN_140b62550(((class GameObject*)(void*)(actor))->FUN_14123c580());return id;}
MS2_REPLACE_METHOD(0x141B4D690, UIUpperHpBar, FUN_141b4d690, 107, 0xEA6EC0D6);

// @0x141b4d710
CStringW UIUpperHpBar::FUN_141b4d710(void* actor){Unk_UpperPC* pc=reinterpret_cast<Unk_UpperPC*>(efd::DynamicCast<PC, PCBase>(reinterpret_cast<PCBase*>(actor)));if(pc){return TSingleton<CStringTable>::GetInstance()->FUN_141811980(6,pc->FUN_141654730());}else{CNpc* npc=efd::DynamicCast<CNpc, PCBase>(reinterpret_cast<PCBase*>(actor));if(npc)return TSingleton<CStringTable>::GetInstance()->FUN_141811980(17,npc->GetNpcData().operator->()->GetRace());}return L"";}
MS2_REPLACE_METHOD(0x141B4D710, UIUpperHpBar, FUN_141b4d710, 322, 0x42472180);
// @0x141b4d860
bool UIUpperHpBar::FUN_141b4d860(void* actor){return efd::DynamicCast<CNpc, PCBase>(reinterpret_cast<PCBase*>(actor))!=0;}
MS2_REPLACE_METHOD(0x141B4D860, UIUpperHpBar, FUN_141b4d860, 57, 0xEC468757);

// @0x141b4d8a0
int UIUpperHpBar::FUN_141b4d8a0(void* actor){Unk_UpperPC* pc=reinterpret_cast<Unk_UpperPC*>(efd::DynamicCast<PC, PCBase>(reinterpret_cast<PCBase*>(actor)));if(!pc)return 0;return pc->FUN_141654730();}
MS2_REPLACE_METHOD(0x141B4D8A0, UIUpperHpBar, FUN_141b4d8a0, 56, 0xE9446796);

// @0x141b4da00
inline Scaleform::GFx::Value AScript::Invoke(const char* szMethod,__int64 a1,CStringW a2,int a3,CStringW a4){
 ASArgList args;
 args.resize(4);
 FUN_1422bcdd0(&args[0],a1);
 FUN_1422bcea0(&args[1],a2);
 FUN_1422bccb0(&args[2],a3);
 FUN_1422bcea0(&args[3],a4);
 return FUN_1422bb8f0(szMethod,args);
}
