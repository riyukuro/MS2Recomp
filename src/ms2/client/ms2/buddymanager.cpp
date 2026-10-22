// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Buddy collection and protocol handling.
// MS2-UNIT: client\ms2\buddymanager.cpp
// MS2-RANGE: 0x140ae2d20-0x140ae7940 .text$mn
// MS2-RANGE: 0x1400c6490-0x1400c6520 .text$di
// MS2-RANGE: 0x142ca02d0-0x142ca0330 .text$yd
// MS2-PIN: ??0Unk_BuddyRequest@@QEAA@XZ 0x140ae5c70
// MS2-PIN: ??1Unk_BuddyRequest@@QEAA@XZ 0x140ae5e60
// MS2-PIN: ?GetCount@?$CAtlList@V?$Unk_BuddyPtr@VCBuddy@@@@V?$CElementTraits@V?$Unk_BuddyPtr@VCBuddy@@@@@ATL@@@ATL@@QEBA_KXZ 0x140ae6560
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\buddymanager.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "buddymanager.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
static const CString s_buddyAgree("buddy_agree");
static const CString s_buddyDeny("buddy_deny");
static const CString s_buddyRequest("buddy_request");
struct Unk_BuddySettings { int unknown; bool autoReject; };
class Unk_BuddyOptions { public: Unk_BuddySettings& GetSettings() { return settings; } private:
    void* pad_0;
    void* pad_8;
    void* pad_10;
    void* pad_18;
    void* pad_20;
    void* pad_28;
    void* pad_30;
    void* pad_38;
    void* pad_40;
    void* pad_48;
    void* pad_50;
    void* pad_58;
    void* pad_60;
    void* pad_68;
    void* pad_70;
    void* pad_78;
    void* pad_80;
    void* pad_88;
    void* pad_90;
    void* pad_98;
    void* pad_a0;
    void* pad_a8;
    void* pad_b0;
    void* pad_b8;
    void* pad_c0;
    void* pad_c8;
    void* pad_d0;
    void* pad_d8;
    void* pad_e0;
    void* pad_e8;
    void* pad_f0;
    void* pad_f8;
    void* pad_100;
    void* pad_108;
    void* pad_110;
    void* pad_118;
    void* pad_120;
    void* pad_128;
    void* pad_130;
    void* pad_138;
    Unk_BuddySettings settings;
};
Unk_BuddyOptions* FUN_1409a8b10();
// @0x140ae2d20
CBuddyManager::CBuddyManager() {}
// @0x140ae2e10
CBuddyManager::~CBuddyManager() {}
class Unk_BuddyStream {
public:
    virtual void vfunc_0(); virtual unsigned char vfunc_1(); virtual void vfunc_2(); virtual unsigned vfunc_3(); virtual __int64 vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual CStringW vfunc_8();
};
class Unk_BuddyInput { public: virtual unsigned vfunc_0(); void FUN_140715280(unsigned); Unk_BuddyStream stream; };
class Unk_BuddyNotifications {
public:
    virtual void vfunc_0(); virtual void vfunc_1(__int64); virtual void vfunc_2(__int64); virtual void vfunc_3(__int64); virtual void vfunc_4(__int64,int); virtual void vfunc_5(__int64); virtual void vfunc_6(__int64); virtual void vfunc_7(__int64); virtual void vfunc_8(__int64); virtual void vfunc_9(__int64); virtual void vfunc_10(__int64,int); virtual void vfunc_11(__int64);
};
Unk_BuddyNotifications* FUN_140a4a7b0();
CStringW FUN_14052bd00(int,const CStringW&);
CStringW FUN_14028de60(int);
CStringW FUN_1409eec40(int);
void FUN_140961010(int,int,int,const CStringW&);
void FUN_1412751b0(const CStringW&,int);
void FUN_141276180(const CString&,const CString&);
bool FUN_140841300(const CStringW&,const char*);
void FUN_140d73aa0(CStringW,int,__int64,CStringW);
#include "ms2/placeholder/uidialog.h"
class UICommunityDialog : public UIDialog { public: int FUN_1418d6960(); void FUN_1418d6430(int); };
class UICommunityQueryDialog : public UIDialog {};
class Unk_BuddyPopup : public UIDialog { public: void FUN_141937e70(unsigned char); };
Unk_BuddyPopup* FUN_140938b90(int);
UICommunityDialog* FUN_140ae5990(int);
UICommunityQueryDialog* FUN_140ae5a30(int);
// @0x140ae2e90
void CBuddyManager::FUN_140ae2e90(Unk_BuddyInput& input) {
    unsigned position=input.vfunc_0();
    Unk_BuddyResponse response; response.FUN_1407a3cc0(input); input.FUN_140715280(position);
    Ptr buddy(0); int field=0; int channel=0;
    (&input.stream)->vfunc_1();
    if(response.protocol==1) {
        unsigned count=(&input.stream)->vfunc_3();
        for(unsigned i=0;i<count;++i) { buddy=new CBuddy; if(buddy.get()) { buddy->FUN_1401cc7c0(input); FUN_140ae5630(buddy); } }
    } else if(response.protocol==8 || response.protocol==9) {
        unsigned position=input.vfunc_0(); __int64 id=(&input.stream)->vfunc_4(); input.FUN_140715280(position);
        buddy=FUN_140ae4b70(id);
        if(buddy==0) {
            buddy=new CBuddy;
            if(buddy.get()) {
                buddy->FUN_1401cc7c0(input);
                if(response.protocol==9 && FUN_1409a8b10()->GetSettings().autoReject && buddy->FUN_1401cc5d0()) {
                    Unk_BuddyRequest request; request.protocol=4; request.id=id; FUN_140ae4820(request); return;
                }
                FUN_140ae5630(buddy); buddy->FUN_1401cc4b0(1);
            }
        } else { field=buddy->FUN_1401cc3e0(); channel=buddy->FUN_1401cc3a0(); buddy->FUN_1401cc7c0(input); }
    } else if(response.protocol==15) FUN_140ae5190();
    switch(response.protocol) {
    case 2: if(response.result==0) FUN_140961010(0x600,1,1,response.name); break;
    case 3:
        if(response.result==0) { buddy=FUN_140ae4b70(response.id); if(buddy.get()) {
            buddy->flags&=~1u; buddy->FUN_1401cc4b0(1); FUN_141276180(s_buddyAgree,"");
            CStringW message=FUN_14052bd00(0x5fd,buddy->name); FUN_1412751b0(message,12);
            Unk_BuddyNotifications* events=FUN_140a4a7b0(); events->vfunc_3(buddy->id);
        }} break;
    case 4:
        if(response.result==0) { buddy=FUN_140ae4b70(response.id); if(buddy.get()) {
            FUN_141276180(s_buddyDeny,""); CStringW message=FUN_14052bd00(0x601,buddy->name); FUN_1412751b0(message,12);
            Unk_BuddyNotifications* events=FUN_140a4a7b0(); events->vfunc_2(buddy->id); FUN_140ae5850(buddy);
        }} break;
    case 5:
        if(response.result==0) { buddy=FUN_140ae4b70(response.id); if(buddy.get()) {
            buddy->flags|=4; buddy->FUN_1401cc4b0(1); CStringW message=FUN_14052bd00(0x5fe,buddy->name); FUN_1412751b0(message,12);
            Unk_BuddyNotifications* events=FUN_140a4a7b0(); events->vfunc_4(buddy->id,1);
        }} break;
    case 6:
        if(response.result==0) { buddy=FUN_140ae4b70(response.id); if(buddy.get()) {
            CStringW message=FUN_14052bd00(0x606,buddy->name); FUN_1412751b0(message,12);
            Unk_BuddyNotifications* events=FUN_140a4a7b0(); events->vfunc_6(buddy->id);
            __int64 id=buddy->FUN_1401cc230(); FUN_140ae5850(buddy); Unk_BuddyNotifications* next=FUN_140a4a7b0(); next->vfunc_7(id);
        }} break;
    case 7:
        if(response.result==0) { buddy=FUN_140ae4b70(response.id); if(buddy.get()) {
            if(buddy->FUN_1401cc660()) FUN_140961010(0x602,1,1,buddy->name);
            else { CStringW message(L""); if(buddy->FUN_1401cc5d0()) message=FUN_14052bd00(0x603,buddy->name); else message=FUN_14052bd00(0x605,buddy->name); FUN_1412751b0(message,12); }
            Unk_BuddyNotifications* events=FUN_140a4a7b0(); events->vfunc_5(buddy->id); FUN_140ae5850(buddy);
        }} break;
    case 8:
        if(buddy.get()) { Unk_BuddyNotifications* events=FUN_140a4a7b0(); events->vfunc_9(buddy->FUN_1401cc2f0()); }
        if(buddy->FUN_1401cc5f0() && (field!=buddy->FUN_1401cc3e0() || channel!=buddy->FUN_1401cc3a0())) { Unk_BuddyNotifications* events=FUN_140a4a7b0(); events->vfunc_10(buddy->FUN_1401cc2f0(),field); } break;
    case 9:
        if(response.result==0) {
            if((buddy->flags>>1)&1) { Unk_BuddyNotifications* events=FUN_140a4a7b0(); events->vfunc_3(buddy->id); }
            else if(buddy->flags&1) { FUN_141276180(s_buddyRequest,""); FUN_1412751b0(FUN_14028de60(0x607),12); Unk_BuddyNotifications* events=FUN_140a4a7b0(); events->vfunc_1(buddy->id); }
            else if((buddy->flags>>2)&1) { Unk_BuddyNotifications* events=FUN_140a4a7b0(); events->vfunc_4(buddy->id,0); }
        } break;
    case 10:
        buddy=FUN_140ae4b70(response.id); if(response.result==0) { FUN_140961010(0x5ff,1,1,response.name); if(buddy.get()) { buddy->memo=response.memo; Unk_BuddyNotifications* events=FUN_140a4a7b0(); events->vfunc_11(buddy->id); } } break;
    case 11:
        buddy=FUN_140ae4b70(response.id); if(buddy.get()) { buddy->flags&=~2u; buddy->FUN_1401cc4b0(1); CStringW message=FUN_14052bd00(0x5fd,buddy->name); FUN_1412751b0(message,12); Unk_BuddyNotifications* events=FUN_140a4a7b0(); events->vfunc_3(buddy->id); } break;
    case 12:
        if(response.result==0) { CStringW message=FUN_14052bd00(0x5fe,response.name); FUN_1412751b0(message,12); } else if(response.result==10) FUN_140961010(0x61b,1,1,response.name); break;
    case 13: {
        unsigned count=(&input.stream)->vfunc_3();
        for(unsigned i=0;i<count;++i) { CStringW message; CStringW name=(&input.stream)->vfunc_8(); CStringW action=(&input.stream)->vfunc_8(); __int64 id=(&input.stream)->vfunc_4();
            if(FUN_140841300(action,"approved")) { buddy=FUN_140ae4950(name); if(buddy.get()) buddy->FUN_1401cc4b0(1); message=FUN_14052bd00(0x5fd,name); }
            else if(FUN_140841300(action,"declined")) message=FUN_14052bd00(0x602,name);
            else if(FUN_140841300(action,"removed")) message=FUN_14052bd00(0x605,name);
            FUN_1412751b0(message,12);
        } break;
    }
    case 14: { CStringW message; switch(response.flag) { case 0:message=FUN_14052bd00(0x608,response.name);break; case 1:message=FUN_14052bd00(0x609,response.name);break; } FUN_1412751b0(message,12); break; }
    case 17:
        if(response.result==0) { buddy=FUN_140ae4b70(response.id); if(buddy.get()) { CStringW message=FUN_14052bd00(0x604,buddy->name); FUN_1412751b0(message,12); Unk_BuddyNotifications* events=FUN_140a4a7b0(); events->vfunc_8(buddy->id); FUN_140ae5850(buddy); } } break;
    case 18: {
        UICommunityQueryDialog* query=FUN_140ae5a30(0x4e4e); if(query && !query->vfunc_55()) query->vfunc_67();
        UICommunityDialog* community=FUN_140ae5990(0x4e4d); if(community) community->FUN_1418d6430(community->FUN_1418d6960());
        FUN_140d73aa0(FUN_1409eec40(0x8ba),0,0,L""); break;
    }
    case 20: SendBuddyMode20(); break;
    }
    Unk_BuddyPopup* popup=FUN_140938b90(0x4e28); if(popup && !popup->vfunc_55()) popup->FUN_141937e70(response.protocol);
}

// @0x140ae4820
void CBuddyManager::FUN_140ae4820(Unk_BuddyRequest& request) { COutPacket packet(0x30,0); request.FUN_1401fc790(packet); FUN_140710590(packet); }
MS2_REPLACE_METHOD(0x140AE4820, CBuddyManager, FUN_140ae4820, 83, 0x6E66E430);
// @0x140ae4880
CBuddyManager::Ptr CBuddyManager::FUN_140ae4880(__int64 key) {{ if(Unk_BuddyGuard guard=lock) {} else { Ptr p; accounts.Lookup(key,p); return p; } }}
// @0x140ae4950
CBuddyManager::Ptr CBuddyManager::FUN_140ae4950(const CStringW& name) {{
    if(Unk_BuddyGuard guard=lock) {} else { Ptr p;
        for(POSITION pos=list.GetHeadPosition();pos;list.GetNext(pos)) { p=list.GetAt(pos); if(p->name.CompareNoCase(name)==0) return p; }
        return Ptr(0);
    }
}}
// @0x140ae4ad0
CBuddyManager::Ptr CBuddyManager::FUN_140ae4ad0() {{ if(Unk_BuddyGuard guard=lock) {} else { return list.GetTail();} }}
// @0x140ae4b70
CBuddyManager::Ptr CBuddyManager::FUN_140ae4b70(__int64 key) {{ if(Unk_BuddyGuard guard=lock) {} else { Ptr p; ids.Lookup(key,p); return p; } }}
// @0x140ae4c30
CBuddyManager::Ptr CBuddyManager::FUN_140ae4c30(__int64 id,__int64 account,const CStringW& name) {
    Ptr p=FUN_140ae4b70(id); if(p==0) { p=FUN_140ae4880(account); if(p==0) p=FUN_140ae4950(name); } return p;
}
MS2_REPLACE_METHOD(0x140AE4C30, CBuddyManager, FUN_140ae4c30, 302, 0x784E1087);
// @0x140ae4d70
bool CBuddyManager::FUN_140ae4d70(__int64 account) { { Ptr p=FUN_140ae4880(account); if(p.get() && p->FUN_1401cc5f0()) return true; } return false; }
MS2_REPLACE_METHOD(0x140AE4D70, CBuddyManager, FUN_140ae4d70, 120, 0x328D9A99);
// @0x140ae4df0
void CBuddyManager::FUN_140ae4df0(ATL::CAtlArray<Ptr>& out) {
    if(Unk_BuddyGuard guard=lock) {} else { Ptr p; for(POSITION pos=list.GetHeadPosition();pos;list.GetNext(pos)) { p=list.GetAt(pos); out.Add(p); } }
}
MS2_REPLACE_METHOD(0x140AE4DF0, CBuddyManager, FUN_140ae4df0, 210, 0xDAE8B35A);
// @0x140ae4ed0
unsigned CBuddyManager::FUN_140ae4ed0() {{ if(Unk_BuddyGuard guard=lock) {} else { return static_cast<unsigned>(list.GetCount());} }}
// @0x140ae4f50
int CBuddyManager::FUN_140ae4f50() { int count=0; { if(Unk_BuddyGuard guard=lock) {} else { Ptr p; for(POSITION pos=list.GetHeadPosition();pos;list.GetNext(pos)) { p=list.GetAt(pos); if((p.get()?true:false) && p->FUN_1401cc680()) ++count; } } } return count; }
MS2_REPLACE_METHOD(0x140AE4F50, CBuddyManager, FUN_140ae4f50, 273, 0xD93331C5);
// @0x140ae5070
int CBuddyManager::FUN_140ae5070() { int count=0; { if(Unk_BuddyGuard guard=lock) {} else { Ptr p; for(POSITION pos=list.GetHeadPosition();pos;list.GetNext(pos)) { p=list.GetAt(pos); if((p.get()?true:false) && p->FUN_1401cc5d0()) ++count; } } } return count; }
MS2_REPLACE_METHOD(0x140AE5070, CBuddyManager, FUN_140ae5070, 273, 0x235EB834);
// @0x140ae5190
void CBuddyManager::FUN_140ae5190() { FUN_140ae5910(); }
MS2_REPLACE_METHOD(0x140AE5190, CBuddyManager, FUN_140ae5190, 24, 0x2B25CE44);
// @0x140ae51b0
unsigned CBuddyManager::FUN_140ae51b0(__int64 account) { Ptr p=FUN_140ae4880(account); if(p.get()) return (p->flags>>2)&1; return 0; }
MS2_REPLACE_METHOD(0x140AE51B0, CBuddyManager, FUN_140ae51b0, 128, 0xB4C2B217);
// @0x140ae5240
unsigned CBuddyManager::FUN_140ae5240(const CStringW& name) { Ptr p=FUN_140ae4950(name); if(p.get()) return (p->flags>>2)&1; return 0; }
MS2_REPLACE_METHOD(0x140AE5240, CBuddyManager, FUN_140ae5240, 128, 0xC030A7B8);
// @0x140ae52d0
int CBuddyManager::FUN_140ae52d0(int field,int channel) { { if(Unk_BuddyGuard guard=lock) {} else { Ptr p; for(POSITION pos=list.GetHeadPosition();pos;list.GetNext(pos)) { p=list.GetAt(pos); if(!p) continue; if(p->FUN_1401cc3e0()==field && p->FUN_1401cc3a0()==channel) return 1; } } } return 0; }
MS2_REPLACE_METHOD(0x140AE52D0, CBuddyManager, FUN_140ae52d0, 310, 0x55F6200B);
// @0x140ae5410
int CBuddyManager::FUN_140ae5410(CStringW name) { { if(Unk_BuddyGuard guard=lock) {} else { Ptr p; for(POSITION pos=list.GetHeadPosition();pos;list.GetNext(pos)) { p=list.GetAt(pos); if(!p) continue; if(p->FUN_1401cc350()==name) return 1; } } } return 0; }
MS2_REPLACE_METHOD(0x140AE5410, CBuddyManager, FUN_140ae5410, 379, 0xD246D2B4);
// @0x140ae55a0
void CBuddyManager::SendBuddyMode20() { COutPacket packet(0x30,0); packet.Encode1(20); int reject=FUN_1409a8b10()->GetSettings().autoReject?1:0; packet.Encode4(reject); FUN_140710590(packet); }
MS2_REPLACE_METHOD(0x140AE55A0, CBuddyManager, SendBuddyMode20, 136, 0x33CF1841);
// @0x140ae5630
void CBuddyManager::FUN_140ae5630(Ptr p) { if(Unk_BuddyGuard guard=lock) {} else { if(ids.Lookup(p->id)) return; POSITION pos=list.AddTail(p); p->position=pos; ids.SetAt(p->id,p); accounts.SetAt(p->account,p); } }
MS2_REPLACE_METHOD(0x140AE5630, CBuddyManager, FUN_140ae5630, 268, 0x737F3292);
// @0x140ae5750
void CBuddyManager::FUN_140ae5750(__int64 id) { if(Unk_BuddyGuard guard=lock) {} else { Ptr pBuddy; ids.Lookup(id,pBuddy); MS2_ASSERT_AT(102,pBuddy); if(pBuddy.get()) FUN_140ae5850(pBuddy); } }
MS2_REPLACE_METHOD(0x140AE5750, CBuddyManager, FUN_140ae5750, 237, 0x8966D4E2);
// @0x140ae5850
void CBuddyManager::FUN_140ae5850(Ptr p) { if(Unk_BuddyGuard guard=lock) {} else { list.RemoveAt(p->position); ids.RemoveKey(p->id); accounts.RemoveKey(p->account); } }
MS2_REPLACE_METHOD(0x140AE5850, CBuddyManager, FUN_140ae5850, 178, 0xE4E576ED);
// @0x140ae5910
void CBuddyManager::FUN_140ae5910() { if(Unk_BuddyGuard guard=lock) {} else { list.RemoveAll(); ids.RemoveAll(); accounts.RemoveAll(); } }
MS2_REPLACE_METHOD(0x140AE5910, CBuddyManager, FUN_140ae5910, 128, 0x25C639A2);

class Unk_BuddyUIManager { public: MS2Ptr<UIObject> FUN_141adcea0(int); };
Unk_BuddyUIManager* FUN_1403ed2b0();
// @0x140ae5990
UICommunityDialog* FUN_140ae5990(int id) { if(FUN_1403ed2b0()) { MS2Ptr<UIObject> p=FUN_1403ed2b0()->FUN_141adcea0(id); if(p.get()) return dynamic_cast<UICommunityDialog*>(p.operator->()); } return 0; }
// @0x140ae5a30
UICommunityQueryDialog* FUN_140ae5a30(int id) { if(FUN_1403ed2b0()) { MS2Ptr<UIObject> p=FUN_1403ed2b0()->FUN_141adcea0(id); if(p.get()) return dynamic_cast<UICommunityQueryDialog*>(p.operator->()); } return 0; }
