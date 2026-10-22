// Mentoring dialog and reward page; field/helper names are inferred.
#pragma once
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/delegate.h"
#include <atlcoll.h>
#include <vector>
#include "ms2/client/ms2/uigalleryeventdialog.h"
class CInPacket;
void FUN_14015b020(CPtred*);int FUN_140159bc0(CPtred*);void FUN_140159ba0(CPtred*);
template<class T> class Unk_MentorPtr {
public:
 Unk_MentorPtr():p(0){} Unk_MentorPtr(int):p(0){} Unk_MentorPtr(T* q):p(q){AddRef();}
 Unk_MentorPtr(const Unk_MentorPtr& q):p(q.p){AddRef();} Unk_MentorPtr(Unk_MentorPtr&& q):p(q.p){q.p=0;}
 ~Unk_MentorPtr(){Release();}
 Unk_MentorPtr& operator=(const Unk_MentorPtr& q){q.AddRef();Release();p=q.p;return *this;}
 Unk_MentorPtr& operator=(int){Release();return *this;}
 Unk_MentorPtr& operator=(T* q){Unk_MentorPtr tmp(q);T* old=p;p=tmp.p;tmp.p=old;return *this;}
 bool IsNull()const{return p==0;} bool operator==(T* q)const{return p==q;}
 T* get()const{return p;} T* operator->()const{return p;} operator T*()const{return p;}
private:
 void AddRef()const{if(p)ReferenceImpl((void*)0);} static void Reference(T* q){FUN_14015b020(q);}
 void ReferenceImpl(void*)const{Reference(p);} void Release(){if(p){ReleaseImpl((void*)0);p=0;}}
 void ReleaseImpl(void*){if(FUN_140159bc0(p)==0){Reference(p);FUN_140159ba0(p);}}
 void* m_0;T* p;
};
class UIMentoringDialog;
class Unk_MentorEntry;
class UIMentoringPage:public CPtred {
public:
 UIMentoringPage(UIMentoringDialog*);virtual ~UIMentoringPage();
 virtual int vfunc_1();virtual void vfunc_2();virtual void vfunc_3(Scaleform::GFx::Value*,const CString&,ASData*);
 virtual void vfunc_4(Scaleform::GFx::Value*,ASData*);virtual int vfunc_5(const char*,const Scaleform::GFx::Value*,unsigned);
 virtual CString vfunc_6()=0;virtual CStringW vfunc_7();virtual int vfunc_8();virtual void vfunc_9();
 MS2Ptr<AScript> GetScript();UIMentoringDialog* GetOwner();
 void FUN_140c6f190();void FUN_140c71ce0();void FUN_140c6f7a0(CString,MS2Ptr<Unk_MentorEntry>);void FUN_140c71ee0(CString,MS2Ptr<Unk_MentorEntry>,int);
private:friend class UIMentoringMissionPage;friend class UIMentoringBuffPage;MS2Ptr<AScript> m_script;UIMentoringDialog* m_owner;
};
MS2_CHECK_SIZE(UIMentoringPage,0x30);
class UIMentoringBuffPage:public UIMentoringPage {public:UIMentoringBuffPage(UIMentoringDialog*);virtual ~UIMentoringBuffPage();virtual int vfunc_1();virtual void vfunc_2();virtual int vfunc_5(const char*,const Scaleform::GFx::Value*,unsigned);virtual CString vfunc_6();virtual CStringW vfunc_7();};
MS2_CHECK_SIZE(UIMentoringBuffPage,0x30);
class ASMentoringMenteePage;
class UIMentoringMenteePage:public UIMentoringPage {
public:UIMentoringMenteePage(UIMentoringDialog*);virtual ~UIMentoringMenteePage();virtual int vfunc_1();virtual void vfunc_2();virtual int vfunc_5(const char*,const Scaleform::GFx::Value*,unsigned);virtual CString vfunc_6();virtual CStringW vfunc_7();virtual int vfunc_8();virtual void vfunc_9();
private:Unk_MentorPtr<ASMentoringMenteePage> m_mentee;
};
MS2_CHECK_SIZE(UIMentoringMenteePage,0x40);
class ASMentoringMentorPage;
class UIMentoringMentorPage:public UIMentoringPage {
public:UIMentoringMentorPage(UIMentoringDialog*);virtual ~UIMentoringMentorPage();virtual int vfunc_1();virtual void vfunc_2();virtual int vfunc_5(const char*,const Scaleform::GFx::Value*,unsigned);virtual CString vfunc_6();virtual CStringW vfunc_7();virtual void vfunc_9();
private:Unk_MentorPtr<ASMentoringMentorPage> m_mentor;
};
MS2_CHECK_SIZE(UIMentoringMentorPage,0x40);
class CMsgBoxData;
class UIMentoringMenteeRegisterPage:public UIMentoringPage {
public:UIMentoringMenteeRegisterPage(UIMentoringDialog*);virtual ~UIMentoringMenteeRegisterPage();virtual int vfunc_1();virtual void vfunc_2();virtual int vfunc_5(const char*,const Scaleform::GFx::Value*,unsigned);virtual CString vfunc_6();virtual CStringW vfunc_7();
 bool SendMentor(int,const CMsgBoxData&);
};
MS2_CHECK_SIZE(UIMentoringMenteeRegisterPage,0x30);
class UIMentoringMentorRegisterPage:public UIMentoringPage {
public:UIMentoringMentorRegisterPage(UIMentoringDialog*);virtual ~UIMentoringMentorRegisterPage();virtual int vfunc_1();virtual void vfunc_2();virtual int vfunc_5(const char*,const Scaleform::GFx::Value*,unsigned);virtual CString vfunc_6();virtual CStringW vfunc_7();
 bool SendMentor(int,const CMsgBoxData&);
};
MS2_CHECK_SIZE(UIMentoringMentorRegisterPage,0x30);
class ASObj;class Unk_MentorInstance;class Unk_MentorIdArray;
class UIMentoringMissionPage:public UIMentoringPage,public UIQuestEventListener {
public:UIMentoringMissionPage(UIMentoringDialog*);virtual ~UIMentoringMissionPage();virtual int vfunc_1();virtual void vfunc_2();virtual void vfunc_3(Scaleform::GFx::Value*,const CString&,ASData*);virtual void vfunc_4(Scaleform::GFx::Value*,ASData*);virtual int vfunc_5(const char*,const Scaleform::GFx::Value*,unsigned);virtual CString vfunc_6();virtual CStringW vfunc_7();virtual int vfunc_8();virtual int vfunc_10(int);virtual void vfunc_o178_11(void*);
 void FUN_140c74170(ASObj&,Unk_MentorInstance*);void FUN_140c74450(int);int FUN_140c74660();__int64 FUN_140c74720();void FUN_140c74850(Unk_MentorIdArray&,int);void FUN_140c74970();
};
MS2_CHECK_SIZE(UIMentoringMissionPage,0x38);
class Unk_MentorMission:public UIMentoringPage {public:Unk_MentorMission(UIMentoringDialog*);CString vfunc_6();private:void* p30;};
class UIMentoringDialog:public UIDialog {
public:
 UIMentoringDialog();virtual ~UIMentoringDialog();virtual CString GetTypeName();virtual void vfunc_67();virtual void OnLoadComplete();
 virtual void vfunc_45(Scaleform::GFx::Value*,const CString&,ASData*);virtual void vfunc_49(Scaleform::GFx::Value*,ASData*);
 virtual void vfunc_79(void*);virtual int vfunc_28(const char*,const Scaleform::GFx::Value*,unsigned);virtual int vfunc_48(){return 0x4f4b;}
 Unk_MentorPtr<UIMentoringPage> GetPage();void Refresh();int Count();void RefreshPage();void Notify();void UpdateCounts();int IsAvailable();
 void SetTabs(ATL::CAtlArray<CString>&);void GetTabs(ATL::CAtlArray<CString>&);
 void OnUpdate(CInPacket&);void OnPacket(CInPacket&);void AddPage(Unk_MentorPtr<UIMentoringPage>);
private:MS2_LAYOUT_FRIEND;
 Unk_MentorPtr<UIMentoringPage> m_page;
 ATL::CAtlMap<CString,Unk_MentorPtr<UIMentoringPage>,ATL::CStringElementTraits<CString>> m_pages;
 std::vector<Unk_MentorPtr<UIMentoringPage>> m_tabs;
};
MS2_CHECK_SIZE(UIMentoringDialog,0x1e8);
MS2_CHECK_OFFSET(UIMentoringDialog,m_page,0x178);
MS2_CHECK_OFFSET(UIMentoringDialog,m_pages,0x188);
MS2_CHECK_OFFSET(UIMentoringDialog,m_tabs,0x1d0);
class Unk_MentorButton:public ASDisplayObject {public:void FUN_1422ce240(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>&,int);void FUN_1422c1fe0(unsigned);};
class Unk_MentorText:public ASDisplayObject {public:void FUN_1422c4c80(const CString&);void FUN_1422c4cd0(const CStringW&);};
class ASMentoringRewardPage:public CPtred {
public:ASMentoringRewardPage(UIMentoringPage*);virtual ~ASMentoringRewardPage();void OnInit();void Refresh();void OnReward(const Scaleform::GFx::FunctionHandler::Params&);
private:MS2_LAYOUT_FRIEND;UIMentoringPage* m_owner;MS2Ptr<AScript> m_script;MS2Ptr<Unk_MentorButton> m_button;MS2Ptr<Unk_MentorText> m_coin,m_text;MS2Ptr<ASMovieClip> m_effect1,m_effect2,m_effect3;
};
MS2_CHECK_SIZE(ASMentoringRewardPage,0x90);
MS2_CHECK_OFFSET(ASMentoringRewardPage,m_script,0x20);
class ASMentoringMenteePage:public CPtred {
public:ASMentoringMenteePage(UIMentoringPage*);virtual ~ASMentoringMenteePage();void OnInit();void Refresh();
private:MS2_LAYOUT_FRIEND;UIMentoringPage* m_owner;MS2Ptr<AScript> m_script;MS2Ptr<Unk_MentorText> m_coin;
};
MS2_CHECK_SIZE(ASMentoringMenteePage,0x40);
MS2_CHECK_OFFSET(ASMentoringMenteePage,m_script,0x20);
MS2_CHECK_OFFSET(ASMentoringMenteePage,m_coin,0x30);
class UIMentoringRewardPage:public UIMentoringPage {
public:UIMentoringRewardPage(UIMentoringDialog*);virtual ~UIMentoringRewardPage();virtual int vfunc_1();virtual void vfunc_2();virtual CString vfunc_6();virtual CStringW vfunc_7();virtual int vfunc_8();virtual void vfunc_9();
private:Unk_MentorPtr<ASMentoringRewardPage> m_reward;
};
MS2_CHECK_SIZE(UIMentoringRewardPage,0x40);
class ASMentoringMentorPage:public CPtred {
public:ASMentoringMentorPage(UIMentoringPage*);virtual ~ASMentoringMentorPage();void OnInit();void Refresh();
private:MS2_LAYOUT_FRIEND;UIMentoringPage* m_owner;MS2Ptr<AScript> m_script;MS2Ptr<Unk_MentorText> m_coin;
};
MS2_CHECK_SIZE(ASMentoringMentorPage,0x40);
MS2_CHECK_OFFSET(ASMentoringMentorPage,m_script,0x20);
MS2_CHECK_OFFSET(ASMentoringMentorPage,m_coin,0x30);
