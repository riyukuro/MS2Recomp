// Recovered upper HP bar; Unk_ names are invented from local uses.
#pragma once
#include "ms2/placeholder/uiheadupdisplay.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/delegate.h"
#include <atlcoll.h>
#include "ms2/placeholder/uientityeventlistener.h"
class PCBase;class ASUIComponent;class AdditionalCli;class ASEffectManager;
class UpperHpBarEntity {
public:
 UpperHpBarEntity();~UpperHpBarEntity();
 void SetNameAndKind(const CString&,const int&);const CString& GetName();
 void Reset();void SetClip(MS2Ptr<ASUIComponent>);
 bool DestroyEntity(const int&);void AddBuff(MS2Ptr<AdditionalCli>);void UpdateBuff(MS2Ptr<AdditionalCli>);
 void RemoveBuff(PCBase*,const int&);void RemoveBuffDisplays();void UpdateHp();
 void FUN_141b4b860();void FUN_141b4b950(bool);void SetHpTextVisible(bool);void SetVisible(bool);
 bool GetVisible();const int& GetKind();const int& GetId();
 MS2Ptr<ASUIComponent> GetClip();
 void SetId(const int&);void SetHp(const __int64&);
 void OnShow(const Scaleform::GFx::FunctionHandler::Params&);void OnHide(const Scaleform::GFx::FunctionHandler::Params&);
private:MS2_LAYOUT_FRIEND;
 int m_id;__int64 m_hp;int m_kind;bool m_visible;CString m_name;
 MS2Ptr<ASUIComponent> m_clip;
 MS2Ptr<ASMovieClip> m_gauge;
 ATL::CAtlMap<int,MS2Ptr<AdditionalCli> > m_pending;
 ATL::CAtlMap<unsigned,MS2Ptr<ASEffectManager> > m_buffs;
};
MS2_CHECK_SIZE(UpperHpBarEntity,0xd0);
MS2_CHECK_OFFSET(UpperHpBarEntity,m_pending,0x40);
MS2_CHECK_OFFSET(UpperHpBarEntity,m_buffs,0x88);
class UIUpperHpBar : public UIHeadUpDisplay,public UIEntityEventListener {
public:
 UIUpperHpBar();virtual ~UIUpperHpBar();virtual CString GetTypeName();virtual void OnLoadComplete();virtual void vfunc_26();
 virtual void vfunc_41(const Scaleform::GFx::Value&);virtual void vfunc_43();virtual void vfunc_15();virtual void vfunc_3();
 virtual void vfunc_o70_2(const void* pId); // UIEntityEventListener slot 2 (Ghidra vfunc_o70_2): the egf::EntityID
 virtual int vfunc_28(const char*,const Scaleform::GFx::Value*,unsigned int);
 virtual int vfunc_48(){return 20029;}
 void FUN_141b4c4c0(const CString&,const int&);void FUN_141b4c510(PCBase*,int);
 void FUN_141b4ce20(bool);void FUN_141b4ceb0(bool);void AddBuff(MS2Ptr<AdditionalCli>);void UpdateBuff(MS2Ptr<AdditionalCli>);
 void RemoveBuff(PCBase*,int);void FUN_141b4d0a0();UpperHpBarEntity& GetEntity(void*);bool TryShowEntity(UpperHpBarEntity&);void HideAllEntities();
 bool FUN_141b4d630(UpperHpBarEntity&,int,int);CString FUN_141b4d690(void*);CStringW FUN_141b4d710(void*);bool IsNpc(void*);int FUN_141b4d8a0(void*);
 // @0x140976440
 UpperHpBarEntity* GetCurrentEntity(){return m_current;} // the shown entity (additionalcli.cpp)
private:MS2_LAYOUT_FRIEND;UpperHpBarEntity m_entities[4];UpperHpBarEntity* m_current;
};
MS2_CHECK_SIZE(UIUpperHpBar,0x3c0);
MS2_CHECK_OFFSET(UIUpperHpBar,m_entities,0x78);
MS2_CHECK_OFFSET(UIUpperHpBar,m_current,0x3b8);
