// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). DT attendance popup.
// MS2-UNIT: client\ms2\uidtattendpopup.cpp
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVUIDTAttendPopup@@P81@EAAXAEAVCInPacket@@@Z@std@@@?$Delegate@$$A6AXAEAVCInPacket@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x140c08030
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVUIDTAttendPopup@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x140c08090
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVUIDTAttendPopup@@P81@EAAXPEAVGameEventVariable@@@Z@std@@@?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x140c080f0
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVUIDTAttendPopup@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x140c08150
// MS2-PIN: ?vfunc_2@?$DelegateImpl@U?$pair@PEAVUIDTAttendPopup@@P81@EAAXAEAVCInPacket@@@Z@std@@@?$Delegate@$$A6AXAEAVCInPacket@@@Z@@UEAAXAEAVCInPacket@@@Z 0x140c084c0
// MS2-PIN: ?vfunc_2@?$DelegateImpl@U?$pair@PEAVUIDTAttendPopup@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z 0x140c084f0
// MS2-PIN: ?vfunc_2@?$DelegateImpl@U?$pair@PEAVUIDTAttendPopup@@P81@EAAXPEAVGameEventVariable@@@Z@std@@@?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@UEAAXPEAVGameEventVariable@@@Z 0x140c08520
// MS2-PIN: ?vfunc_2@?$DelegateImpl@U?$pair@PEAVUIDTAttendPopup@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEAAXPEAVNotifyObject@@@Z 0x140c08550
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVUIDTAttendPopup@@P81@EAAXAEAVCInPacket@@@Z@std@@@?$Delegate@$$A6AXAEAVCInPacket@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x140c08680
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVUIDTAttendPopup@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x140c086e0
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVUIDTAttendPopup@@P81@EAAXPEAVGameEventVariable@@@Z@std@@@?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x140c08740
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVUIDTAttendPopup@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x140c087a0
// MS2-PIN: ??1?$DelegateImpl@U?$pair@PEAVUIDTAttendPopup@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEAA@XZ 0x140c06a20
// MS2-RANGE: 0x140c032b0-0x140c08990 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uidtattendpopup.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "uidtattendpopup.h"
#include "uiattendgiftdialog.h"
#include "ms2/placeholder/gfxexception.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
class Unk_DTEvents {public:void FUN_140da5430(int,Delegate<void(GameEventVariable*)>);void FUN_140da5490(int,Delegate<void(GameEventVariable*)>);};Unk_DTEvents* FUN_140933220();
class Unk_DTPackets {public:void FUN_140da5180(int,Delegate<void(CInPacket&)>);void FUN_140da51e0(int,Delegate<void(CInPacket&)>);};Unk_DTPackets* FUN_140bccd50();
class Unk_DTNotices {public:void FUN_140da4e40(CStringW,Delegate<void(NotifyObject*)>);void FUN_140da4eb0(CStringW,Delegate<void(NotifyObject*)>);};Unk_DTNotices* FUN_140939a10();
class Unk_DTInput {public:virtual bool vfunc_0();virtual unsigned char vfunc_1();};
struct Unk_DTInputPrefix {void* p0;Unk_DTInput stream;};
struct Unk_DTNoticePrefix {void* p0;void* p8;void* p10;int kind;};
class Unk_DTUIManager {public:MS2Ptr<UIObject> FUN_141adcea0(int);};Unk_DTUIManager* FUN_1403ed2b0();
template<class T> T* FindDTDialog(int id){if(FUN_1403ed2b0()){MS2Ptr<UIObject> p=FUN_1403ed2b0()->FUN_141adcea0(id);if(p.get())return dynamic_cast<T*>((UIObject*)p);}return 0;}
template<> inline bool MS2Ptr<Unk_DTReward>::operator==(Unk_DTReward* p)const{return m_p==p;}
// @0x140c032b0
UIDTAttendPopup::UIDTAttendPopup(){
 m_2c=0x19;m_80=1;FUN_141925e70(0,1);
 FUN_140933220()->FUN_140da5430(0x66,Delegate<void(GameEventVariable*)>(this,&UIDTAttendPopup::OnEvent));
 FUN_140bccd50()->FUN_140da5180(0x11,Delegate<void(CInPacket&)>(this,&UIDTAttendPopup::OnPacket));
 FUN_140939a10()->FUN_140da4e40(L"NotifyOpenDialogByScene",Delegate<void(NotifyObject*)>(this,&UIDTAttendPopup::OnNotify));
}
// @0x140c035d0
UIDTAttendPopup::~UIDTAttendPopup(){
 FUN_140933220()->FUN_140da5490(0x66,Delegate<void(GameEventVariable*)>(this,&UIDTAttendPopup::OnEvent));
 FUN_140bccd50()->FUN_140da51e0(0x11,Delegate<void(CInPacket&)>(this,&UIDTAttendPopup::OnPacket));
 FUN_140939a10()->FUN_140da4eb0(L"NotifyOpenDialogByScene",Delegate<void(NotifyObject*)>(this,&UIDTAttendPopup::OnNotify));
}
// @0x140c03850
CString UIDTAttendPopup::GetTypeName(){return "DTAttendPopup";}
MS2_REPLACE_METHOD(0x140C03850, UIDTAttendPopup, GetTypeName, 61, 0xD5D76746);
// @0x140c038a0
int UIDTAttendPopup::vfunc_65(){if(!UIDialog::vfunc_65())return 0;return 1;}
MS2_REPLACE_METHOD(0x140C038A0, UIDTAttendPopup, vfunc_65, 37, 0x630C43C0);
// @0x140c038d0
void UIDTAttendPopup::OnLoadComplete(){
 UIDialog::OnLoadComplete();FUN_141925fa0("m_dragBar");
 do{m_30->FUN_140bc71c0("m_item",m_item);if(m_item==0)throw new GfxExceptionSwfLoad(StringFormat("GfxError:{0} {1}({2}) function:{3}","SwfLoadError",MS2_THIS_FILE,MS2_LINE(49),__FUNCTION__));}while(0);
 do{m_item->FUN_140beaf20("m_time",m_time);if(m_time==0)throw new GfxExceptionSwfLoad(StringFormat("GfxError:{0} {1}({2}) function:{3}","SwfLoadError",MS2_THIS_FILE,MS2_LINE(50),__FUNCTION__));}while(0);
 do{m_item->FUN_140bc7100("m_icon",m_icon);if(m_icon==0)throw new GfxExceptionSwfLoad(StringFormat("GfxError:{0} {1}({2}) function:{3}","SwfLoadError",MS2_THIS_FILE,MS2_LINE(51),__FUNCTION__));}while(0);
 m_item->FUN_1422c2a70(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this,&UIDTAttendPopup::OnClick),0);
 Unk_DTPtr<Unk_DTEntry> e=GetCurrent();if(e.get()){UpdateIcon();SetTime(e->FUN_140ce3a20());}
}
MS2_REPLACE_METHOD(0x140C038D0, UIDTAttendPopup, OnLoadComplete, 1593, 0x97BC5526);
// @0x140c03f70
void UIDTAttendPopup::vfunc_26(){UIDialog::vfunc_26();m_item=0;m_time=0;m_icon=0;}
MS2_REPLACE_METHOD(0x140C03F70, UIDTAttendPopup, vfunc_26, 87, 0x322058B9);
// @0x140c03fd0
void UIDTAttendPopup::vfunc_72(){if(!FUN_141924630())return;if(!m_tick.FUN_140268870(1000))return;{Unk_DTPtr<Unk_DTEntry> e=GetCurrent();if(e==0||e->FUN_140ce35c0()){vfunc_67();return;}unsigned remain=e->FUN_140ce3a20();if(remain==0)Request();else SetTime(remain);}}
MS2_REPLACE_METHOD(0x140C03FD0, UIDTAttendPopup, vfunc_72, 233, 0xFA61125E);
// @0x140c040c0
void UIDTAttendPopup::AddEntry(Unk_DTPtr<Unk_DTEntry> e){if(!e->FUN_140ce3510())return;m_entries.insert(std::make_pair(e->FUN_1402e1d00(),e));RefreshVisibility();}
MS2_REPLACE_METHOD(0x140C040C0, UIDTAttendPopup, AddEntry, 207, 0x963AF570);
// @0x140c041a0
void UIDTAttendPopup::RemoveEntry(Unk_DTPtr<Unk_DTEntry> e){if(!e->FUN_140ce3510())return;m_entries.erase(e->FUN_1402e1d00());RefreshVisibility();}
MS2_REPLACE_METHOD(0x140C041A0, UIDTAttendPopup, RemoveEntry, 132, 0x8442B6F4);
// @0x140c04230
void UIDTAttendPopup::RefreshVisibility(){if(CanShow()){if(!FUN_141924630())FUN_141924680();}else if(FUN_141924630())vfunc_67();}
MS2_REPLACE_METHOD(0x140C04230, UIDTAttendPopup, RefreshVisibility, 90, 0xC83AE185);
// @0x140c04290
void UIDTAttendPopup::UpdateIcon(){if(m_item==0)return;Unk_DTPtr<Unk_DTEntry> e=GetCurrent();if(e==0)return;MS2Ptr<Unk_DTReward> reward=e->FUN_140ce3710(e->FUN_140ce3690());if(reward==0)return;m_icon->FUN_1409ba630(*reinterpret_cast<Unk_DTItemData*>(reinterpret_cast<char*>(reward.operator->())+0x18));}
MS2_REPLACE_METHOD(0x140C04290, UIDTAttendPopup, UpdateIcon, 275, 0xA850FFEE);
// @0x140c043b0
void UIDTAttendPopup::SetTime(unsigned sec){if(m_time==0)return;m_time->FUN_1422c4cd0(StringFormat(L"{0:02}:{1:02}",sec/60,sec%60));}
MS2_REPLACE_METHOD(0x140C043B0, UIDTAttendPopup, SetTime, 179, 0xFC1A1CC5);
// @0x140c04470
void UIDTAttendPopup::Request(){if(!m_requestTick.FUN_140268870(5000))return;if(m_entries.size()==0)return;Unk_DTPtr<Unk_DTEntry> e=GetCurrent();if(e->FUN_140ce35c0())return;COutPacket packet(static_cast<int>(SendOp::Attendance),0);packet.Encode1(0);FUN_140710590(packet);}
MS2_REPLACE_METHOD(0x140C04470, UIDTAttendPopup, Request, 207, 0xFE00C17A);
// @0x140c04550
bool UIDTAttendPopup::CanShow(){Unk_DTPtr<Unk_DTEntry> e=GetCurrent();if(e==0)return false;if(e->FUN_140ce3690()>=e->FUN_140ce3660())return false;return !e->FUN_140ce35c0();}
MS2_REPLACE_METHOD(0x140C04550, UIDTAttendPopup, CanShow, 220, 0x2442908C);
// @0x140c04640
void UIDTAttendPopup::OnPacket(CInPacket& p){int code=(&reinterpret_cast<Unk_DTInputPrefix*>(&p)->stream)->vfunc_1();if(code==3)RefreshVisibility();}
MS2_REPLACE_METHOD(0x140C04640, UIDTAttendPopup, OnPacket, 77, 0x9BCCDA46);
// @0x140c046a0
void UIDTAttendPopup::OnClick(const Scaleform::GFx::FunctionHandler::Params&){Unk_DTPtr<Unk_DTEntry> e=GetCurrent();if(e==0)return;UIAttendGiftDialog* dlg=FindDTDialog<UIAttendGiftDialog>(0x4eb8);if(dlg&&dlg->FUN_14102c7a0(e->FUN_1402e1d00()))dlg->FUN_141924680();}
MS2_REPLACE_METHOD(0x140C046A0, UIDTAttendPopup, OnClick, 156, 0x7C250258);
// @0x140c04750
void UIDTAttendPopup::OnEvent(GameEventVariable*){RefreshVisibility();}
MS2_REPLACE_METHOD(0x140C04750, UIDTAttendPopup, OnEvent, 29, 0x79304A3B);
// @0x140c04780
void UIDTAttendPopup::OnNotify(NotifyObject* p){Unk_DTNoticePrefix* notice=reinterpret_cast<Unk_DTNoticePrefix*>(p);if(notice->kind==0x620001d)RefreshVisibility();}
MS2_REPLACE_METHOD(0x140C04780, UIDTAttendPopup, OnNotify, 53, 0x2B5ACCBD);
// @0x140c047c0
Unk_DTPtr<Unk_DTEntry> UIDTAttendPopup::GetCurrent(){if(m_entries.size()==0)return 0;return m_entries.begin()->second;}
MS2_REPLACE_METHOD(0x140C047C0, UIDTAttendPopup, GetCurrent, 146, 0x89ECA329);
MS2_EMIT_CRT_MEMMOVE_S();
