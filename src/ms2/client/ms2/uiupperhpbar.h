// Recovered upper HP bar; Unk_ names are invented from local uses.
#pragma once
#include "ms2/placeholder/uiheadupdisplay.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/delegate.h"
#include <atlcoll.h>
class Unk_UpperEvt;
class UIEntityEventListener {
public:UIEntityEventListener();virtual ~UIEntityEventListener();
 virtual void vfunc_1(void*);virtual void vfunc_o70_2(const Unk_UpperEvt&);virtual void vfunc_3(void*);virtual void vfunc_4(void*);virtual void vfunc_5(void*,int); // 3..5 get a by-value MS2Ptr<CProxyGameObject> (the callee destroys it)
};
MS2_CHECK_SIZE(UIEntityEventListener,8);
class Unk_UpperActor;class Unk_UpperEvt;class Unk_UpperHpText;class Unk_UpperClip;class Unk_UpperText;class Unk_UpperBuff;
template<class T> class Unk_UpperPtr {
public: Unk_UpperPtr();~Unk_UpperPtr();Unk_UpperPtr(T*);
 Unk_UpperPtr(const Unk_UpperPtr& o):m_p(o.m_p){AddRef();}
 Unk_UpperPtr& operator=(const Unk_UpperPtr&);
 Unk_UpperPtr& operator=(int);bool operator==(T*)const;
 T* get()const;T* operator->()const;
 void AddRef();
private:void* m_0;T* m_p;
};
class Unk_UpperBuffMap {
public:Unk_UpperBuffMap(unsigned int,float,float,float,unsigned int) throw();~Unk_UpperBuffMap();
 void FUN_1419f5260(int,const Unk_UpperPtr<Unk_UpperBuff>&);void FUN_1419f5130(int);void FUN_1419f4f30();POSITION FUN_1419f4790();const Unk_UpperPtr<Unk_UpperBuff>& FUN_1419f4810(POSITION);void FUN_1419f4620(POSITION&);
private:
 void* m_0;
 void* m_8;
 void* m_10;
 void* m_18;
 void* m_20;
 void* m_28;
 void* m_30;
 void* m_38;
 void* m_40;
};
class UpperHpBarEntity {
public:
 UpperHpBarEntity();~UpperHpBarEntity();
 void FUN_141b4a7d0(const CString&,const int&);const CString& FUN_141b4a820();
 void FUN_141b4a840();void FUN_141b4a8b0(Unk_UpperPtr<Unk_UpperClip>);
 bool FUN_141b4ab70(const int&);void FUN_141b4ac50(Unk_UpperPtr<Unk_UpperBuff>);void FUN_141b4b0d0(Unk_UpperPtr<Unk_UpperBuff>);
 void FUN_141b4b240(Unk_UpperActor*,const int&);void FUN_141b4b3f0();void FUN_141b4b500();
 void FUN_141b4b860();void FUN_141b4b950(bool);void FUN_141b4ba40(bool);void FUN_141b4bb20(bool);
 bool GetVisible();const int& FUN_141b4bbc0();const int& FUN_141b4bbe0();
 Unk_UpperPtr<Unk_UpperClip> GetClip();
 void FUN_141b4bc50(const int&);void FUN_141b4bc70(const __int64&);
 void FUN_141b4bca0(const Scaleform::GFx::FunctionHandler::Params&);void FUN_141b4bce0(const Scaleform::GFx::FunctionHandler::Params&);
private:MS2_LAYOUT_FRIEND;
 int m_id;__int64 m_hp;int m_kind;bool m_visible;CString m_name;
 Unk_UpperPtr<Unk_UpperClip> m_clip;
 Unk_UpperPtr<Unk_UpperText> m_gauge;
 Unk_UpperBuffMap m_pending;
 ATL::CAtlMap<unsigned,Unk_UpperPtr<ASDisplayObject> > m_buffs;
};
MS2_CHECK_SIZE(UpperHpBarEntity,0xd0);
MS2_CHECK_OFFSET(UpperHpBarEntity,m_pending,0x40);
MS2_CHECK_OFFSET(UpperHpBarEntity,m_buffs,0x88);
class UIUpperHpBar : public UIHeadUpDisplay,public UIEntityEventListener {
public:
 UIUpperHpBar();virtual ~UIUpperHpBar();virtual CString GetTypeName();virtual void OnLoadComplete();virtual void vfunc_26();
 virtual void vfunc_41(const Scaleform::GFx::Value&);virtual void vfunc_43();virtual void vfunc_15();virtual void vfunc_3();
 virtual void vfunc_o70_2(const Unk_UpperEvt&); // UIEntityEventListener slot 2 (Ghidra vfunc_o70_2)
 virtual int vfunc_28(const char*,const Scaleform::GFx::Value*,unsigned int);
 virtual int vfunc_48(){return 20029;}
 void FUN_141b4c4c0(const CString&,const int&);void FUN_141b4c510(Unk_UpperActor*,int);
 void FUN_141b4ce20(bool);void FUN_141b4ceb0(bool);void FUN_141b4cf40(Unk_UpperPtr<Unk_UpperBuff>);void FUN_141b4cfd0(Unk_UpperPtr<Unk_UpperBuff>);
 void FUN_141b4d060(Unk_UpperActor*,int);void FUN_141b4d0a0();UpperHpBarEntity& FUN_141b4d170(void*);bool FUN_141b4d320(UpperHpBarEntity&);void FUN_141b4d5c0();
 bool FUN_141b4d630(UpperHpBarEntity&,int,int);CString FUN_141b4d690(void*);CStringW FUN_141b4d710(void*);bool FUN_141b4d860(void*);int FUN_141b4d8a0(void*);
 // @0x140976440
 UpperHpBarEntity* FUN_140976440(){return m_current;} // the shown entity (additionalcli.cpp)
private:MS2_LAYOUT_FRIEND;UpperHpBarEntity m_entities[4];UpperHpBarEntity* m_current;
};
MS2_CHECK_SIZE(UIUpperHpBar,0x3c0);
MS2_CHECK_OFFSET(UIUpperHpBar,m_entities,0x78);
MS2_CHECK_OFFSET(UIUpperHpBar,m_current,0x3b8);
