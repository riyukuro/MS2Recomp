// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Dungeon rewards.
// MS2-UNIT: client\ms2\uidungeonrewarddialog.cpp
// MS2-RANGE: 0x140e20ae0-0x140e26c20 .text$mn
// MS2-RANGE: 0x1400d7740-0x1400d78e0 .text$di
// MS2-RANGE: 0x142ca6520-0x142ca65c5 .text$yd
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVUIDungeonRewardDialog@@P81@EAAXAEAVCInPacket@@@Z@std@@@?$Delegate@$$A6AXAEAVCInPacket@@@Z@@QEAA@AEBV01@@Z 0x140e26450
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVUIDungeonRewardDialog@@P81@EAAXAEAVCInPacket@@@Z@std@@@?$Delegate@$$A6AXAEAVCInPacket@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x140e26880
// MS2-PIN: ??_GUIDungeonRewardDialog@@UEAAPEAXI@Z 0x140e267c0
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVUIDungeonRewardDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@QEAA@AEBV01@@Z 0x140e264f0
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVUIDungeonRewardDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x140e268e0
// MS2-PIN: ?vfunc_2@?$DelegateImpl@U?$pair@PEAVUIDungeonRewardDialog@@P81@EAAXAEAVCInPacket@@@Z@std@@@?$Delegate@$$A6AXAEAVCInPacket@@@Z@@UEAAXAEAVCInPacket@@@Z 0x140e26940
// MS2-PIN: ?vfunc_2@?$DelegateImpl@U?$pair@PEAVUIDungeonRewardDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z 0x140e26970
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVUIDungeonRewardDialog@@P81@EAAXAEAVCInPacket@@@Z@std@@@?$Delegate@$$A6AXAEAVCInPacket@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x140e26a20
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVUIDungeonRewardDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x140e26a80
// MS2-PIN: ??$Call@VUIDungeonRewardDialog@@P81@EAAXAEAVCInPacket@@@Z@?$DelegateImpl@U?$pair@PEAVUIDungeonRewardDialog@@P81@EAAXAEAVCInPacket@@@Z@std@@@?$Delegate@$$A6AXAEAVCInPacket@@@Z@@CAXAEAU?$pair@PEAVUIDungeonRewardDialog@@P81@EAAXAEAVCInPacket@@@Z@std@@AEAVCInPacket@@@Z 0x140e269a0
// MS2-PIN: ??$Call@VUIDungeonRewardDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@?$DelegateImpl@U?$pair@PEAVUIDungeonRewardDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@CAXAEAU?$pair@PEAVUIDungeonRewardDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@AEBUParams@FunctionHandler@GFx@Scaleform@@@Z 0x140e269e0
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uidungeonrewarddialog.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "uidungeonrewarddialog.h"
#include "ms2/placeholder/header_statics_a.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/gfxexception.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/commonfiles/itemgift.h"
#include "ms2/ms2format.h"
static CString s_winSound="BattleField_Win";
void FUN_1422bce70(Scaleform::GFx::Value*,const char*);
class Unk_RewardStream {
public: virtual bool vfunc_0(); virtual unsigned char vfunc_1(); virtual short vfunc_2(); virtual int vfunc_3();
 void FUN_14070f300(bool&);
};
class CInPacket { public: void* m_0; void* m_stream; };
MS2_CHECK_OFFSET(CInPacket,m_stream,8);
class Unk_RewardPackets {
public: void FUN_140da5180(int,Delegate<void(CInPacket&)>); void FUN_140da51e0(int,Delegate<void(CInPacket&)>);
};
Unk_RewardPackets* FUN_140bccd50();
void FUN_14141f970(const CString&);
class Unk_RewardText : public AScript { public: void FUN_1422c4cd0(const CStringW&); };
class Unk_RewardClip : public AScript {
public:
 virtual void vfunc_1();
 virtual void vfunc_2();
 virtual void vfunc_3(int);
 virtual void vfunc_4(bool);
 virtual void vfunc_5();
 virtual void vfunc_6();
 virtual void vfunc_7();
 virtual void vfunc_8();
 virtual void vfunc_9();
 virtual void vfunc_10();
 virtual void vfunc_11();
 virtual void vfunc_12(int);
 virtual void vfunc_13();
 virtual void vfunc_14();
 virtual void vfunc_15(const CString&);
 Unk_RewardPtr<Unk_RewardButton> FUN_140bbe640(const CString&,Unk_RewardPtr<Unk_RewardButton>&);
 Unk_RewardPtr<Unk_RewardClip> FUN_1409b4560(const CString&);
 void FUN_1422bffe0(int,int);
 Scaleform::GFx::Value FUN_1409ba0d0(const char*,int,int);
 Scaleform::GFx::Value FUN_140e262c0(const char*,const char*);
 const Scaleform::GFx::Value& FUN_1422bb890() const;
 Unk_RewardPtr<Unk_RewardText> FUN_140d01e20(const CString&);
 Unk_RewardPtr<Unk_RewardText> FUN_1409b4620(const CString&);
 Unk_RewardPtr<Unk_RewardClip> FUN_140bc7450(const CString&);
 Scaleform::GFx::Value FUN_1422c6900(Scaleform::GFx::Value);
 void FUN_1422c0e20(int); float FUN_1422c10a0(); void FUN_1422c0420(float);
};
class Unk_RewardLabelClip : public Unk_RewardClip { public: Unk_RewardLabelClip(CString,int); private: void* m_40; void* m_48; void* m_50; void* m_58; void* m_60; void* m_68; void* m_70; void* m_78; };
MS2_CHECK_SIZE(Unk_RewardLabelClip,0x80);
class Unk_RewardButton : public Unk_RewardClip {
public: void FUN_1422ce240(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>&,int);
 void FUN_1422cdfb0(const CStringW&);
};
class Unk_RewardEntryList;
class Unk_RewardMission { public: void FUN_140c9ce80(Unk_RewardEntryList&); int FUN_140c9ceb0(); int FUN_140c9cf50(); unsigned int FUN_140c9cff0(); };
class Unk_RewardMissionPtr {
public: ~Unk_RewardMissionPtr(); bool operator==(Unk_RewardMission*) const; Unk_RewardMission* get() const {return m_p;} Unk_RewardMission* operator->() const;
private: void* m_0;Unk_RewardMission* m_p;
};
class Unk_RewardMissions { public: Unk_RewardMissionPtr FUN_140d9f4e0(); };
Unk_RewardMissions* FUN_140931510();
CString FUN_140e1c880(const char*,const char*,const char*,const int&,const char*);

class Unk_RewardRoom { public: void* m_0;
 void* m_8;
 void* m_10;
 int m_18; int m_1c;
 void* m_20;
 void* m_28;
 void* m_30;
 void* m_38;
 void* m_40;
 void* m_48;
 void* m_50;
 void* m_58;
 void* m_60;
 void* m_68;
 void* m_70;
 void* m_78;
 void* m_80;
 void* m_88;
 void* m_90;
 void* m_98;
 void* m_a0;
 void* m_a8;
 void* m_b0;
 void* m_b8;
 void* m_c0;
 void* m_c8;
 void* m_d0;
 void* m_d8;
 void* m_e0;
 void* m_e8;
 void* m_f0;
 void* m_f8;
 void* m_100;
 void* m_108;
 void* m_110;
 void* m_118;
 void* m_120;
 void* m_128;
 void* m_130;
 void* m_138;
 void* m_140;
 void* m_148;
 void* m_150;
 void* m_158;
 void* m_160;
 void* m_168;
 void* m_170;
 void* m_178;
 void* m_180;
 void* m_188;
 void* m_190;
 void* m_198;
 void* m_1a0;
 void* m_1a8;
 unsigned short m_1b0; bool m_leave; unsigned int FUN_14031ddf0(); };
MS2_CHECK_OFFSET(Unk_RewardRoom,m_leave,0x1b2);
class Unk_RewardOtherDialog : public UIDialog {
public: bool FUN_140e26860(); void FUN_1419f6eb0(); void FUN_1419f6a70(int,CStringW,int);
};
Unk_RewardOtherDialog* FUN_140e01890(int);
class Unk_RewardState { public: void FUN_1416d0740(); }; Unk_RewardState* FUN_140764020();
class Unk_RewardParty { public: void FUN_14162be10(); }; Unk_RewardParty* FUN_1409670d0();
class ASTooltip : public AScript {
public: ASTooltip(int,int); virtual ~ASTooltip(); int FUN_1409e26b0(const CStringW&);
private: void* m_40; void* m_48; void* m_50; void* m_58;
};
bool FUN_140184310(const CString&,const char*);
class Unk_RewardThing {public: void FUN_141270610();};
struct Unk_RewardVector
{
    Unk_RewardVector();
    float x, y, z;
    Unk_RewardVector& operator+=(const Unk_RewardVector&);
};
MS2_CHECK_SIZE(Unk_RewardVector, 12);
struct Unk_RewardCameraData
{
    Unk_RewardCameraData();
    void FUN_141b48530();
    Unk_RewardVector eye, target;
    float f18, f1c, f20;
    int n24, n28, n2c;
};
MS2_CHECK_SIZE(Unk_RewardCameraData, 0x30);
class Unk_RewardActor
{
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12(int);
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual Unk_RewardVector vfunc_18();
    void FUN_1410885b0(bool);
    Unk_RewardThing* FUN_14165f460();
};
class Unk_RewardCamera
{
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12(int);
    virtual void vfunc_13(const Unk_RewardCameraData&);
};
class Unk_RewardCameraPtr
{
public:
    ~Unk_RewardCameraPtr();
    Unk_RewardCamera* operator->() const;
private:
    Unk_RewardCamera* m_p;
};
MS2_CHECK_SIZE(Unk_RewardCameraPtr, 8);
class Unk_RewardAvatar
{
public:
    virtual void vfunc_0();
    virtual void vfunc_1(IUIAvatarEventListener*);
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12(int);
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual Unk_RewardActor* vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual int vfunc_27(const char*, const Scaleform::GFx::Value*, unsigned int);
    virtual void vfunc_28(void*, TPtr<Unk_UISwfEntity_25>, void*, void*);
    void FUN_1418bc790(int,int);
    Unk_RewardActor* FUN_1418bd1d0();
    void FUN_1418ba340(int);
    int FUN_1418b9b80();
    void FUN_1418bce80(int);
    void FUN_1418bcf60(int, unsigned short);
    Unk_RewardCameraPtr FUN_1418b9bc0();
};
class UIAvatarPC : public Unk_RewardAvatar
{
public:
    UIAvatarPC(void*, bool);
private:
    void* m_8;
    void* m_10;
    void* m_18;
    void* m_20;
    void* m_28;
    void* m_30;
    void* m_38;
    void* m_40;
    void* m_48;
    void* m_50;
    void* m_58;
    void* m_60;
    void* m_68;
    void* m_70;
    void* m_78;
    void* m_80;
    void* m_88;
    void* m_90;
    void* m_98;
    void* m_a0;
    void* m_a8;
    void* m_b0;
    void* m_b8;
    void* m_c0;
    void* m_c8;
    void* m_d0;
    void* m_d8;
    void* m_e0;
    void* m_e8;
};
MS2_CHECK_SIZE(UIAvatarPC, 0xf0);
class Unk_RewardIntArray {public:size_t FUN_140191110() const;int& FUN_140297cb0(size_t);};
void* FUN_1401d3200();
int FUN_140768010(int,int);
class Unk_RewardPActor;
class Unk_RewardPlayer {public:Unk_RewardPActor* FUN_141bd0cc0();};
Unk_RewardPlayer* FUN_1403ed2d0();


// ---- declarations for the reward population routines ----
class CItem {
public:
    CItem();
    int FUN_14052b130(int nId, int nRarity, int nFlag);
    void FUN_140526c70(int nCount);
private:
    void* m_0; void* m_8; void* m_10; void* m_18; void* m_20; void* m_28; void* m_30; void* m_38;
    void* m_40; void* m_48; void* m_50; void* m_58; void* m_60; void* m_68; void* m_70; void* m_78;
    void* m_80; void* m_88; void* m_90; void* m_98; void* m_a0; void* m_a8; void* m_b0; void* m_b8;
    void* m_c0; void* m_c8; void* m_d0; void* m_d8; void* m_e0; void* m_e8; void* m_f0; void* m_f8;
    void* m_100; void* m_108; void* m_110; void* m_118; void* m_120; void* m_128; void* m_130; void* m_138;
    void* m_140; void* m_148; void* m_150; void* m_158; void* m_160; void* m_168; void* m_170; void* m_178;
    void* m_180; void* m_188; void* m_190; void* m_198;
};
MS2_CHECK_SIZE(CItem, 0x1a0);
class Unk_RewardRoomMgr { public: Unk_RewardPtr<Unk_RewardRoom> FUN_1403206b0(unsigned int); };
Unk_RewardRoomMgr* FUN_14031c2a0();
class Unk_RewardSound { public: void FUN_141276180(const CString&); };
extern Unk_RewardSound g_unkRewardSound; // 0x143ac5988
CStringW GetStringCommonByKey(const CStringW&);
CStringW FUN_1405c2690(CStringW,const CStringW&);
CStringW FUN_1409404f0(__int64);
CStringW FUN_1409eb450(int);
CStringW FUN_140811740(int,const int&,const int&);
CStringW FUN_140e14d70(unsigned int);
void FUN_140cfee80(const Scaleform::GFx::Value&,CString,CStringW);
void FUN_140cff1b0(const Scaleform::GFx::Value&,CString,CStringW);
void FUN_140cff310(const Scaleform::GFx::Value&,CString,CString,CStringW);
void FUN_140cffca0(const Scaleform::GFx::Value&,CString,CString);
void FUN_14141f770(CString&,unsigned int,const ATL::CAtlArray<MS2Ptr<CItem> >&,MS2Ptr<CItem>(*)(const ATL::CAtlArray<MS2Ptr<CItem> >&,int),int,int);
MS2Ptr<CItem> FUN_141420330(const ATL::CAtlArray<MS2Ptr<CItem> >&,int);
enum Unk_ClosingJob { Unk_ClosingJob_None };   // same enum as uidungeonclosingphotodialog.cpp (job id; StringFormat<Unk_ClosingJob> 0x140e10af0)
class Unk_RewardPActor {
public:
 virtual void vfunc_0();
 virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9();
 virtual void vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15(); virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19();
 virtual void vfunc_20(); virtual void vfunc_21(); virtual void vfunc_22(); virtual void vfunc_23(); virtual void vfunc_24(); virtual void vfunc_25(); virtual void vfunc_26(); virtual void vfunc_27(); virtual void vfunc_28(); virtual void vfunc_29();
 virtual void vfunc_30(); virtual void vfunc_31(); virtual void vfunc_32(); virtual void vfunc_33(); virtual void vfunc_34(); virtual void vfunc_35(); virtual void vfunc_36(); virtual void vfunc_37(); virtual void vfunc_38(); virtual void vfunc_39();
 virtual void vfunc_40(); virtual void vfunc_41(); virtual void vfunc_42(); virtual void vfunc_43(); virtual void vfunc_44(); virtual void vfunc_45(); virtual void vfunc_46(); virtual void vfunc_47(); virtual void vfunc_48(); virtual void vfunc_49();
 virtual void vfunc_50(); virtual void vfunc_51(); virtual void vfunc_52(); virtual void vfunc_53(); virtual void vfunc_54(); virtual void vfunc_55(); virtual void vfunc_56(); virtual void vfunc_57(); virtual void vfunc_58(); virtual void vfunc_59();
 virtual void vfunc_60(); virtual void vfunc_61(); virtual void vfunc_62(); virtual void vfunc_63(); virtual void vfunc_64(); virtual void vfunc_65(); virtual void vfunc_66(); virtual void vfunc_67(); virtual void vfunc_68(); virtual void vfunc_69();
 virtual void vfunc_70(); virtual void vfunc_71(); virtual void vfunc_72(); virtual void vfunc_73(); virtual void vfunc_74(); virtual void vfunc_75(); virtual void vfunc_76();
 virtual CStringW vfunc_77();
 Unk_ClosingJob FUN_141654730();
};
class Unk_RewardEntry { public: CStringW FUN_140b1e060(); unsigned short FUN_140b1e030(); unsigned short FUN_140b1e010(); };
class Unk_RewardEntryPtr {
public: Unk_RewardEntryPtr(const Unk_RewardEntryPtr&); ~Unk_RewardEntryPtr(); bool operator==(Unk_RewardEntry*) const; Unk_RewardEntry* operator->() const;
private: void* m_0; Unk_RewardEntry* m_p;
};
class Unk_RewardEntryList {
public: Unk_RewardEntryList(); ~Unk_RewardEntryList(); size_t FUN_140c9f760(); Unk_RewardEntryPtr& FUN_140c9eb50(size_t);
private: void* m_0; void* m_8; void* m_10;
};
CString FUN_14031c9d0(unsigned int);

// @0x140e26860
// MS2: the exe reads one byte at +0xa8, which UIDialog declares as the first pointer of a vector (m_a8); the real owner of this flag is unproven.
bool Unk_RewardOtherDialog::FUN_140e26860() { return *reinterpret_cast<const bool*>(&m_a8); }
MS2_REPLACE_METHOD(0x140E26860, Unk_RewardOtherDialog, FUN_140e26860, 18, 0x2CB8DA8D);
// @0x140e26660
bool Unk_RewardMissionPtr::operator==(Unk_RewardMission* p) const { return m_p==p; }
MS2_REPLACE_METHOD(0x140E26660, Unk_RewardMissionPtr, operator==, 55, 0x3A11F2EB);
// @0x140e262c0
Scaleform::GFx::Value Unk_RewardClip::FUN_140e262c0(const char* method,const char* arg) {
 ASArgList args;
 args.FUN_1409b2800(1);
 FUN_1422bce70(args.FUN_1409b1f70(0),arg);
 return FUN_1422bb8f0(method,args);
}
MS2_REPLACE_METHOD(0x140E262C0, Unk_RewardClip, FUN_140e262c0, 148, 0x7E9B9EE2);
// @0x140e20ae0
UIDungeonRewardDialog::UIDungeonRewardDialog() {
 FUN_140e25610(); m_268="DungeonReward_gainItems"; m_2c=0x1b;
 FUN_140bccd50()->FUN_140da5180(0x1b,Delegate<void(CInPacket&)>(this,&UIDungeonRewardDialog::FUN_140e22130));
}
// @0x140e20da0
UIDungeonRewardDialog::~UIDungeonRewardDialog() {
 FUN_14141f970(m_268);
 FUN_140bccd50()->FUN_140da51e0(0x1b,Delegate<void(CInPacket&)>(this,&UIDungeonRewardDialog::FUN_140e22130));
}
// @0x140e21000
CString UIDungeonRewardDialog::GetTypeName() { return "DungeonRewardDialog"; }
MS2_REPLACE_METHOD(0x140E21000, UIDungeonRewardDialog, GetTypeName, 61, 0x76DD8AEE);

// @0x140e21050
void UIDungeonRewardDialog::vfunc_26() { UIDialog::vfunc_26(); m_labels.FUN_140bcfb70(); FUN_140e25610(); }
MS2_REPLACE_METHOD(0x140E21050, UIDungeonRewardDialog, vfunc_26, 53, 0x294469C5);

// @0x140e21090
void UIDungeonRewardDialog::OnLoadComplete() {
 UIDialog::OnLoadComplete();
 m_180=FUN_140ba7930("m_rewardAvatar");
 Unk_RewardPtr<Unk_RewardClip> reward=FUN_140ba7930("m_rewardAni");
 m_190=reward->FUN_1409b4560("m_rewardInfo");
 Unk_RewardPtr<Unk_RewardClip> rank=FUN_140ba7930("m_rankAni");
 m_1a0=rank->FUN_1409b4560("m_rankInfo");
 if(Unk_RewardPtr<Unk_RewardClip> buttons=FUN_140ba7930("m_buttonArea")) {
 do { buttons->FUN_140bbe640("m_closeButton",m_1c0);
 if(m_1c0==0) throw new GfxExceptionSwfLoad(FUN_140e1c880("GfxError:{0} {1}({2}) function:{3}","SwfLoadError",MS2_THIS_FILE,116,__FUNCTION__)); } while(0);
 do { buttons->FUN_140bbe640("m_partyLeaveButton",m_1d0);
 if(m_1d0==0) throw new GfxExceptionSwfLoad(FUN_140e1c880("GfxError:{0} {1}({2}) function:{3}","SwfLoadError",MS2_THIS_FILE,117,__FUNCTION__)); } while(0);
 m_1c0->FUN_1422ce240(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this,&UIDungeonRewardDialog::FUN_140e22740),0);
 if((m_room.get()?true:false)&&m_room->m_leave)m_1c0->FUN_1422cdfb0(L"$s_dungeonReward_leave");
 m_1d0->FUN_1422ce240(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this,&UIDungeonRewardDialog::FUN_140e22780),0);
 m_1d0->vfunc_4(false);
 }
 m_1b0=FUN_140ba7930("m_title");
 m_timer1.FUN_1408687f0();m_timer2.FUN_1408687f0();
 FUN_140e25420();FUN_140e25170();FUN_140e22820();
 switch(m_type) {case 1:FUN_140e22d70();break;case 2:FUN_140e24e80();break;case 3:FUN_140e25050();break;case 4:FUN_140e250e0();break;}
 Unk_RewardMissionPtr mission=FUN_140931510()->FUN_140d9f4e0();
 if(mission.get()&&mission->FUN_140c9cf50()>0) {FUN_140e24060();FUN_140e24c50(true);}else FUN_140e24c50(false);
 Unk_RewardOtherDialog* dialog=FUN_140e01890(20044);
 if(dialog&&dialog->FUN_140e26860()) {dialog->vfunc_8(0);m_restore=true;}
}
MS2_REPLACE_METHOD(0x140E21090, UIDungeonRewardDialog, OnLoadComplete, 2637, 0xE1F9D4BE);
// @0x140e21b30
void UIDungeonRewardDialog::vfunc_67() {
 bool restore=m_restore; UIDialog::vfunc_67(); Unk_RewardOtherDialog* dialog=FUN_140e01890(20044);
 if(dialog) { if(restore) { if(dialog->FUN_140e26860()) { dialog->vfunc_8(1);m_restore=false; } } dialog->FUN_1419f6eb0(); }
 FUN_140764020()->FUN_1416d0740();
}
MS2_REPLACE_METHOD(0x140E21B30, UIDungeonRewardDialog, vfunc_67, 145, 0x23BD740F);

// @0x140e21bd0
void UIDungeonRewardDialog::vfunc_72() {
 UIDialog::vfunc_72();
 if(m_timer1.FUN_140868c00()) { const int delay=1000; m_timer1.FUN_1408687f0(); Unk_RewardOtherDialog* dialog=FUN_140e01890(20044);
 if(dialog) dialog->FUN_1419f6a70(3,L"",delay); m_timer2.FUN_140868750(delay);
 } else if(m_timer2.FUN_140868c00()) {m_timer2.FUN_1408687f0();FUN_140e23690();}
}
MS2_REPLACE_METHOD(0x140E21BD0, UIDungeonRewardDialog, vfunc_72, 238, 0x43986A41);

// @0x140e21cd0
void UIDungeonRewardDialog::vfunc_45(Scaleform::GFx::Value* out,const CString& method,ASData* args) {
 if(FUN_140184310(method,"getTooltip")) { CString name=args->FUN_1422b8d30();
 if(FUN_140184310(name,"m_bonusDetail")) { ASTooltip tip(1,2); if(tip.FUN_1409e26b0(m_tip)) *out=tip.FUN_1422bb870();return;} }
}
MS2_REPLACE_METHOD(0x140E21CD0, UIDungeonRewardDialog, vfunc_45, 233, 0xE42702C8);

// @0x140e21dc0
void UIDungeonRewardDialog::vfunc_25(void* p1,TPtr<Unk_UISwfEntity_25> p2,void* p3,void* p4) {
 if(m_avatar==0)return;
 Unk_RewardActor* actor=m_avatar->vfunc_24();if(!actor)return;
 m_avatar->vfunc_28(p1,p2,p3,p4);
 Unk_RewardCameraData data;data.FUN_141b48530();data.f1c=300.0f;
 data.target+=actor->vfunc_18();data.eye+=data.target;m_avatar->FUN_1418b9bc0()->vfunc_13(data);
 switch(m_type) {case 1:case 4:
 if(m_win)m_avatar->FUN_1418bc790(14,85);
 else if(reinterpret_cast<Unk_RewardIntArray*>(static_cast<char*>(FUN_1401d3200())+0xe7e0)->FUN_140191110()>0) {
 int index=FUN_140768010(static_cast<int>(reinterpret_cast<Unk_RewardIntArray*>(static_cast<char*>(FUN_1401d3200())+0xe7e0)->FUN_140191110()),0);
 m_avatar->FUN_1418bce80(reinterpret_cast<Unk_RewardIntArray*>(static_cast<char*>(FUN_1401d3200())+0xe7e0)->FUN_140297cb0(index));
 }
 break; }
}
// @0x140e220c0
void UIDungeonRewardDialog::vfunc_16() { UISwfEntity::vfunc_16(); FUN_140e255b0(); }
MS2_REPLACE_METHOD(0x140E220C0, UIDungeonRewardDialog, vfunc_16, 34, 0xEF7B9CCD);

// @0x140e220f0
bool UIDungeonRewardDialog::vfunc_17() { if(!UIDialog::vfunc_17())return false;FUN_140e25540();return true; }
MS2_REPLACE_METHOD(0x140E220F0, UIDungeonRewardDialog, vfunc_17, 47, 0xFB4D1030);

// @0x140e22130
void UIDungeonRewardDialog::FUN_140e22130(CInPacket& packet) {
 if(FUN_141924630()) vfunc_68(); FUN_140e25610();
 int type=reinterpret_cast<Unk_RewardStream*>(&packet.m_stream)->vfunc_1();switch(type) {case 0:FUN_140e22210(packet);break;case 1:FUN_140e225a0(packet);break;case 2:FUN_140e22650(packet);break;case 3:FUN_140e226b0(packet);break;}
}
MS2_REPLACE_METHOD(0x140E22130, UIDungeonRewardDialog, FUN_140e22130, 207, 0xFEDD4A03);

// @0x140e225a0
void UIDungeonRewardDialog::FUN_140e225a0(CInPacket& packet) {
 m_type=2; m_round=reinterpret_cast<Unk_RewardStream*>(&packet.m_stream)->vfunc_3();
 m_stage=reinterpret_cast<Unk_RewardStream*>(&packet.m_stream)->vfunc_3();
 m_1e8.FUN_14026c900(packet); FUN_141924680();
}
MS2_REPLACE_METHOD(0x140E225A0, UIDungeonRewardDialog, FUN_140e225a0, 158, 0x20BABF9A);

// @0x140e22650
void UIDungeonRewardDialog::FUN_140e22650(CInPacket& packet) { m_type=3;m_1e8.FUN_14026c900(packet);FUN_140e22820();FUN_140e25050(); }
MS2_REPLACE_METHOD(0x140E22650, UIDungeonRewardDialog, FUN_140e22650, 78, 0x7488FBD7);

// @0x140e226b0
void UIDungeonRewardDialog::FUN_140e226b0(CInPacket& packet) {
 m_type=4; reinterpret_cast<Unk_RewardStream*>(&packet.m_stream)->FUN_14070f300(m_win);
 m_1e8.FUN_14026c900(packet);if(FUN_141924630())vfunc_68();FUN_141924680();
}
MS2_REPLACE_METHOD(0x140E226B0, UIDungeonRewardDialog, FUN_140e226b0, 129, 0xC00E4923);

// @0x140e22740
void UIDungeonRewardDialog::FUN_140e22740(const Scaleform::GFx::FunctionHandler::Params&) { if(m_30==0)return; FUN_140e25790(); }
MS2_REPLACE_METHOD(0x140E22740, UIDungeonRewardDialog, FUN_140e22740, 57, 0x917EAC9F);

// @0x140e22780
void UIDungeonRewardDialog::FUN_140e22780(const Scaleform::GFx::FunctionHandler::Params&) { if(m_30==0)return; if(!m_party)return;FUN_1409670d0()->FUN_14162be10();SendDungeonReward(); }
MS2_REPLACE_METHOD(0x140E22780, UIDungeonRewardDialog, FUN_140e22780, 88, 0x89DB46B2);

// @0x140e227e0
int UIDungeonRewardDialog::vfunc_o178_1(void* avatar) { if(!avatar)return 0;FUN_140e25540();return 1; }
MS2_REPLACE_METHOD_VIA(0x140E227E0, UIDungeonRewardDialog, IUIAvatarEventListener, vfunc_o178_1, 55, 0x208A69DD);

// @0x140e24060
// MS2-FUNCTIONAL: ~29 bytes larger than exe; stack-slot/CString-temp ordering of the gauge section differs
void UIDungeonRewardDialog::FUN_140e24060() {
 if(m_1a0==0)return;
 Unk_RewardMissionPtr mission=FUN_140931510()->FUN_140d9f4e0();
 if(mission==0)return;
 Unk_RewardEntryList entries;
 mission->FUN_140c9ce80(entries);
 int cur=mission->FUN_140c9ceb0();
 int max=mission->FUN_140c9cf50();
 int rank=mission->FUN_140c9cff0();
 CString rankName=FUN_14031c9d0(rank);
 Unk_RewardPtr<Unk_RewardClip> gauge=m_1a0->FUN_1409b4560("m_rankGauge");
 if(gauge) {
  const int fullWidth=0x126;
  float ratio=(float)cur/(float)max;
  if(ratio<0.0f)ratio=0.0f;
  if(1.0f<ratio)ratio=1.0f;
  int width=(int)(ratio*294.0f);
  Unk_RewardPtr<Unk_RewardClip> mask=gauge->FUN_1409b4560("m_mask");
  if(mask) mask->FUN_1422c0e20(width);
  Unk_RewardPtr<Unk_RewardClip> eff=gauge->FUN_1409b4560("m_eff");
  if(eff) {
   float base=(float)width;
   float x=(base+mask->FUN_1422c10a0())-10.0f;
   eff->FUN_1422c0420(x);
  }
 }
 Unk_RewardPtr<Unk_RewardClip> movie=m_1a0->FUN_1409b4560("m_rankMovie");
 Unk_RewardPtr<Unk_RewardClip> rankClip=movie->FUN_1409b4560("m_rank");
 Unk_RewardPtr<Unk_RewardClip> rankEffect=movie->FUN_1409b4560("m_rankEffect");
 rankClip->vfunc_15(rankName);
 rankEffect->vfunc_15(rankName);
 Unk_RewardPtr<Unk_RewardClip> s1=movie->FUN_1409b4560("m_RankSEffect1");
 Unk_RewardPtr<Unk_RewardClip> s2=movie->FUN_1409b4560("m_RankSEffect2");
 if(s1&&s2) {
  bool show=3<rank;
  s1->vfunc_4(show);
  s2->vfunc_4(show);
 }
 Unk_RewardPtr<Unk_RewardClip> sa=movie->FUN_1409b4560("m_rankSAEffect");
 if(sa) {
  bool show=2<rank;
  sa->vfunc_4(show);
 }
 Unk_RewardPtr<Unk_RewardClip> rec=movie->FUN_1409b4560("m_effNewRecord");
 if(rec) {
  bool show=m_294<m_298;
  rec->vfunc_4(show);
 }
 Unk_RewardPtr<Unk_RewardText> total=m_1a0->FUN_1409b4620("m_missionScoreTotal");
 if(total) total->FUN_1422c4cd0(StringFormat(L"{0}/{1}",cur,max));
 FUN_140e25dc0(entries.FUN_140c9f760());
 for(size_t i=0;i<m_labels.FUN_140bd0940();i++) {
  Unk_RewardPtr<Unk_RewardClip> label=m_labels.FUN_140bcc370(i);
  if(label==0)continue;
  if(i<entries.FUN_140c9f760()) {
   Unk_RewardPtr<Unk_RewardText> name=label->FUN_1409b4620("m_missionName");
   Unk_RewardPtr<Unk_RewardText> score=label->FUN_1409b4620("m_missionScore");
   if(name==0||score==0)continue;
   Unk_RewardEntryPtr entry=entries.FUN_140c9eb50(i);
   if(entry==0)continue;
   name->FUN_1422c4cd0(entry->FUN_140b1e060());
   unsigned short a=entry->FUN_140b1e030();
   unsigned short b=entry->FUN_140b1e010();
   score->FUN_1422c4cd0(StringFormat(L"{0}/{1}",b,a));
  } else label->vfunc_4(false);
 }
}
MS2_REPLACE_METHOD(0x140E24060, UIDungeonRewardDialog, FUN_140e24060, 3047, 0x98D9CB8A);

// @0x140e24c50
void UIDungeonRewardDialog::FUN_140e24c50(bool show) {
 Unk_RewardPtr<Unk_RewardClip> avatar=FUN_140ba7930("m_rewardAvatar");
 Unk_RewardPtr<Unk_RewardClip> reward=FUN_140ba7930("m_rewardAni");
 Unk_RewardPtr<Unk_RewardClip> rank=FUN_140ba7930("m_rankAni");
 if(avatar==0||reward==0||rank==0)return;
 if(show) {rank->vfunc_4(true);avatar->FUN_1422bffe0(484,242);reward->FUN_1422bffe0(896,242);rank->FUN_1422bffe0(1516,242);}
 else {rank->vfunc_4(false);avatar->FUN_1422bffe0(714,242);reward->FUN_1422bffe0(1126,242);}
}
MS2_REPLACE_METHOD(0x140E24C50, UIDungeonRewardDialog, FUN_140e24c50, 547, 0x1EAF7A1A);

// @0x140e24e80
void UIDungeonRewardDialog::FUN_140e24e80() { if(m_type!=2)return;if(m_stage==1)FUN_140e24fc0();else FUN_140e24ed0(); }
MS2_REPLACE_METHOD(0x140E24E80, UIDungeonRewardDialog, FUN_140e24e80, 66, 0x3D1638AF);

// @0x140e24ed0
void UIDungeonRewardDialog::FUN_140e24ed0() { if(m_190==0)return;m_190->vfunc_15("_minigame_stage"); reinterpret_cast<Unk_RewardClip*>(m_30.operator->())->FUN_1409ba0d0("setRound",m_round,m_stage); }
MS2_REPLACE_METHOD(0x140E24ED0, UIDungeonRewardDialog, FUN_140e24ed0, 221, 0x65C5AAE8);

// @0x140e24fc0
void UIDungeonRewardDialog::FUN_140e24fc0() { if(m_190==0)return;m_190->vfunc_15("_minigame"); }
MS2_REPLACE_METHOD(0x140E24FC0, UIDungeonRewardDialog, FUN_140e24fc0, 129, 0x3BA1C82D);

// @0x140e25050
void UIDungeonRewardDialog::FUN_140e25050() { if(m_190==0)return;m_190->vfunc_15("_minigame"); }
MS2_REPLACE_METHOD(0x140E25050, UIDungeonRewardDialog, FUN_140e25050, 129, 0x8315C59C);

// @0x140e250e0
void UIDungeonRewardDialog::FUN_140e250e0() { if(m_190==0)return;m_190->vfunc_15("_minigame"); }
MS2_REPLACE_METHOD(0x140E250E0, UIDungeonRewardDialog, FUN_140e250e0, 129, 0x95081669);

// @0x140e25420
void UIDungeonRewardDialog::FUN_140e25420() {
 void* actor=FUN_1403ed2d0()->FUN_141bd0cc0();if(!actor)return;
 UIAvatarPC* avatar=new UIAvatarPC(actor,false);
 avatar->FUN_1418bd1d0()->FUN_1410885b0(1);
 avatar->FUN_1418bd1d0()->FUN_14165f460()->FUN_141270610();
 m_avatar=avatar;m_avatar->vfunc_1(this);
}
MS2_REPLACE_METHOD(0x140E25420, UIDungeonRewardDialog, FUN_140e25420, 281, 0x730F075B);

// @0x140e25540
void UIDungeonRewardDialog::FUN_140e25540() { if(m_180.get())m_180->FUN_140e262c0("loadRenderTarget",""); }
MS2_REPLACE_METHOD(0x140E25540, UIDungeonRewardDialog, FUN_140e25540, 94, 0x191710D4);

// @0x140e255b0
void UIDungeonRewardDialog::FUN_140e255b0() { if(m_180.get())m_180->Invoke("unloadRenderTarget"); }
MS2_REPLACE_METHOD(0x140E255B0, UIDungeonRewardDialog, FUN_140e255b0, 87, 0xC69DB589);

// @0x140e25610
void UIDungeonRewardDialog::FUN_140e25610() {
 m_avatar=0; m_1e8.FUN_14026cdf0();m_228.FUN_14026cdf0();m_tip.Empty();FUN_140e255b0();
 m_180=0;m_190=0;m_1a0=0;m_1b0=0;m_1c0=0;m_1d0=0;m_type=0;m_room=0;m_party=false;
 m_278=0;m_294=0;m_298=0;m_win=true;m_round=0;m_stage=0;m_restore=false;
}
MS2_REPLACE_METHOD(0x140E25610, UIDungeonRewardDialog, FUN_140e25610, 376, 0x95F7B099);

// @0x140e25790
void UIDungeonRewardDialog::FUN_140e25790() { if((m_room.get()?true:false)&&m_room->m_leave)SendDungeonReward();else reinterpret_cast<Unk_RewardClip*>(m_30.operator->())->FUN_140e262c0("gotoAndPlay","close"); }
MS2_REPLACE_METHOD(0x140E25790, UIDungeonRewardDialog, FUN_140e25790, 155, 0xBA656490);

// @0x140e25ff0
void UIDungeonRewardDialog::SendDungeonReward() { COutPacket packet(static_cast<int>(SendOp::DungeonReward),0);packet.Encode1(6);FUN_140710590(packet); }
MS2_REPLACE_METHOD(0x140E25FF0, UIDungeonRewardDialog, SendDungeonReward, 75, 0x31064D84);

// @0x140e22210
void UIDungeonRewardDialog::FUN_140e22210(CInPacket& packet) {
 m_type=1; m_tip.Empty();
 m_win=reinterpret_cast<Unk_RewardStream*>(&packet.m_stream)->vfunc_0();
 int roomId=reinterpret_cast<Unk_RewardStream*>(&packet.m_stream)->vfunc_3();
 m_room=FUN_14031c2a0()->FUN_1403206b0(roomId);
 m_party=reinterpret_cast<Unk_RewardStream*>(&packet.m_stream)->vfunc_0();
 m_278=reinterpret_cast<Unk_RewardStream*>(&packet.m_stream)->vfunc_3();
 m_294=reinterpret_cast<Unk_RewardStream*>(&packet.m_stream)->vfunc_3();
 m_298=reinterpret_cast<Unk_RewardStream*>(&packet.m_stream)->vfunc_3();
 m_bits.FUN_140e26800(reinterpret_cast<Unk_RewardStream*>(&packet.m_stream));
 m_1e8.FUN_14026c900(packet); m_228.FUN_14026c900(packet);
 for(int i=0;i<10;i++) {
  if(m_bits[i]) {
   CStringW text=FUN_140e25840(i);
   if(text.GetLength()>0) {
    if(m_tip.GetLength()>0) m_tip+="\n";
    m_tip+=text;
   }
  }
 }
 if(m_win) g_unkRewardSound.FUN_141276180("");
 FUN_140e22820(); FUN_140e22d70(); FUN_141924680();
}
MS2_REPLACE_METHOD(0x140E22210, UIDungeonRewardDialog, FUN_140e22210, 896, 0x03E608C4);

// @0x140e22820
void UIDungeonRewardDialog::FUN_140e22820() {
 if(m_190==0) return;
 {
  Unk_RewardPtr<Unk_RewardText> meso=m_190->FUN_140d01e20("m_mesoText");
  Unk_RewardPtr<Unk_RewardText> exp=m_190->FUN_140d01e20("m_expText");
  Unk_RewardPtr<Unk_RewardClip> bonus=m_190->FUN_1409b4560("m_bonusText");
  Unk_RewardPtr<Unk_RewardClip> detail=m_190->FUN_1409b4560("m_bonusDetail");
  if(meso.get()) meso->FUN_1422c4cd0(FUN_1409404f0(m_1e8.FUN_14026ccf0()));
  if(exp.get()) exp->FUN_1422c4cd0(FUN_1405c2690(L"s_format_exp",FUN_1409404f0(m_1e8.FUN_14026cbf0())));
  bool normal=false;
  if(m_type==1) normal=true;
  if(bonus.get()) bonus->vfunc_4(normal);
  if(detail.get()) detail->vfunc_4(normal);
  FUN_140e23e10(false);
  ATL::CAtlArray<MS2Ptr<CItem> > items;
  FUN_140e25c30(items,m_1e8);
  FUN_14141f970(m_268);
  MS2Ptr<CItem> (*getter)(const ATL::CAtlArray<MS2Ptr<CItem> >&,int)=FUN_141420330;
  FUN_14141f770(m_268,(unsigned)items.GetCount(),items,getter,0x415,0x800);
  ASObj obj(2);
  obj.FUN_1407cba60("bagId",m_268);
  m_30->Invoke("initRewardItemData",obj.FUN_1422bb870());
 }
}
MS2_REPLACE_METHOD(0x140E22820, UIDungeonRewardDialog, FUN_140e22820, 1343, 0x0E723790);

// @0x140e22d70
void UIDungeonRewardDialog::FUN_140e22d70() {
 if(m_190==0) return;
 {
  m_190->vfunc_15("_dungeon");
  {
   if(Unk_RewardPtr<Unk_RewardClip> timeMovie=m_190->FUN_1409b4560("m_timeMovie")) {
    int sec=m_278%60; int min=m_278/60;
    FUN_140cfee80((*timeMovie).FUN_1422bb890(),"textField",FUN_140811740(0x97e,min,sec));
   }
  }
  {
   if(Unk_RewardPtr<Unk_RewardClip> guild=m_190->FUN_1409b4560("m_rewardGuild")) {
    if((m_room.get()?true:false)&&m_room->m_1c==6) {
     guild->vfunc_3(1);
     FUN_140cfee80((*guild).FUN_1422bb890(),"m_guildFund",FUN_1409eb450(m_1e8.FUN_14026cd70(4)));
     FUN_140cfee80((*guild).FUN_1422bb890(),"m_guildExp",FUN_1409eb450(m_1e8.FUN_14026cd70(5)));
    } else guild->vfunc_3(0);
   }
  }
  if(m_228.FUN_14026ce30()) m_timer1.FUN_140868750(500);
  if(m_win) {
   FUN_140cff1b0((*m_1b0).FUN_1422bb890(),"m_name",GetStringCommonByKey(L"s_dungeon_reward_title_success"));
   FUN_140cff310((*m_190).FUN_1422bb890(),"m_timeMovie","m_clearTimeName",GetStringCommonByKey(L"s_dungeon_reward_clear_time"));
  } else {
   FUN_140cff1b0((*m_1b0).FUN_1422bb890(),"m_name",GetStringCommonByKey(L"s_dungeon_reward_title_fail"));
   FUN_140cff310((*m_190).FUN_1422bb890(),"m_timeMovie","m_clearTimeName",GetStringCommonByKey(L"s_dungeon_reward_fail_time"));
  }
  if(m_party) m_1d0->vfunc_4(true);
 }
}
MS2_REPLACE_METHOD(0x140E22D70, UIDungeonRewardDialog, FUN_140e22d70, 2325, 0x9AA3C1FA);

// @0x140e23690
void UIDungeonRewardDialog::FUN_140e23690() {
 if(m_190==0) return;
 {
  Unk_RewardPtr<Unk_RewardText> meso=m_190->FUN_140d01e20("m_mesoText");
  Unk_RewardPtr<Unk_RewardText> exp=m_190->FUN_140d01e20("m_expText");
  if(meso.get()) meso->FUN_1422c4cd0(FUN_1409404f0(m_1e8.FUN_14026ccf0()+m_228.FUN_14026ccf0()));
  if(exp.get()) exp->FUN_1422c4cd0(FUN_1405c2690(L"s_format_exp",FUN_1409404f0(m_1e8.FUN_14026cbf0()+m_228.FUN_14026cbf0())));
  {
   if(Unk_RewardPtr<Unk_RewardClip> guild=m_190->FUN_1409b4560("m_rewardGuild")) {
    if((m_room.get()?true:false)&&m_room->m_1c==6) {
     guild->vfunc_3(1);
     FUN_140cfee80((*guild).FUN_1422bb890(),"m_guildFund",FUN_1409eb450(m_1e8.FUN_14026cd70(4)+m_228.FUN_14026cd70(4)));
     FUN_140cfee80((*guild).FUN_1422bb890(),"m_guildExp",FUN_1409eb450(m_1e8.FUN_14026cd70(5)+m_228.FUN_14026cd70(5)));
    } else guild->vfunc_3(0);
   }
  }
  FUN_140e23e10(true);
  ATL::CAtlArray<MS2Ptr<CItem> > items;
  FUN_140e25c30(items,m_1e8);
  FUN_140e25c30(items,m_228);
  FUN_14141f970(m_268);
  MS2Ptr<CItem> (*getter)(const ATL::CAtlArray<MS2Ptr<CItem> >&,int)=FUN_141420330;
  FUN_14141f770(m_268,(unsigned)items.GetCount(),items,getter,0x415,0x800);
  ASObj obj(2);
  obj.FUN_1407cba60("bagId",m_268);
  m_30->Invoke("initRewardItemData",obj.FUN_1422bb870());
 }
}
MS2_REPLACE_METHOD(0x140E23690, UIDungeonRewardDialog, FUN_140e23690, 1905, 0x6596C708);

// @0x140e23e10
void UIDungeonRewardDialog::FUN_140e23e10(bool both) {
 Unk_RewardPtr<Unk_RewardClip> mesoEff=m_190->FUN_140bc7450("m_mesoEffect");
 Unk_RewardPtr<Unk_RewardClip> expEff=m_190->FUN_140bc7450("m_expEffect");
 bool showMeso=both&&m_228.FUN_14026ccf0()>0;
 bool showExp=both&&m_228.FUN_14026cbf0()>0;
 if(showMeso) {mesoEff->vfunc_4(true);mesoEff->vfunc_12(1);}
 else mesoEff->vfunc_4(false);
 if(showExp) {expEff->vfunc_4(true);expEff->vfunc_12(1);}
 else expEff->vfunc_4(false);
}
MS2_REPLACE_METHOD(0x140E23E10, UIDungeonRewardDialog, FUN_140e23e10, 573, 0x9C930F31);

// @0x140e25170
void UIDungeonRewardDialog::FUN_140e25170() {
 Unk_RewardPActor* actor=FUN_1403ed2d0()->FUN_141bd0cc0();
 if(!actor) return;
 if(m_180==0) return;
 Unk_RewardPtr<Unk_RewardClip> info=m_180->FUN_1409b4560("m_characterInfo");
 if(info==0) return;
 Unk_RewardPtr<Unk_RewardClip> charInfo=info->FUN_1409b4560("m_charInfo");
 if(charInfo.get()) {
  FUN_140cfee80((*charInfo).FUN_1422bb890(),"m_charName",actor->vfunc_77());
  Unk_ClosingJob job=actor->FUN_141654730();
  CString jobStr=StringFormat("_{0}",job);
  FUN_140cffca0((*charInfo).FUN_1422bb890(),"m_jobMovie",jobStr);
 }
}
MS2_REPLACE_METHOD(0x140E25170, UIDungeonRewardDialog, FUN_140e25170, 669, 0xC754DD4F);

// @0x140e25840
CStringW UIDungeonRewardDialog::FUN_140e25840(int kind) {
 switch(kind) {
 case 0: return L"";
 case 1:
  if(m_room.get()) { CStringW count=FUN_140e14d70(m_room->FUN_14031ddf0()); return FUN_1405c2690(L"s_dungeon_reward_dungeon_reward_count",count); }
 case 2: return GetStringCommonByKey(L"s_dungeon_reward_bonus_event");
 case 3: return GetStringCommonByKey(L"s_dungeon_reward_mission_rank");
 case 4: return GetStringCommonByKey(L"s_dungeon_reward_dungeon_helper");
 case 5: return GetStringCommonByKey(L"s_dungeon_reward_dungeon_helper_event");
 case 6: return GetStringCommonByKey(L"s_dungeon_reward_mentor");
 case 7: return GetStringCommonByKey(L"s_dungeon_reward_mentee");
 case 8: return GetStringCommonByKey(L"s_dungeon_reward_mentee_party_gift");
 case 9: return GetStringCommonByKey(L"s_dungeon_reward_united_weekly");
 default: MS2_ASSERT_AT(0x331,0); return L"";
 }
}
MS2_REPLACE_METHOD(0x140E25840, UIDungeonRewardDialog, FUN_140e25840, 956, 0x2638E62E);

// @0x140e25c30
void UIDungeonRewardDialog::FUN_140e25c30(ATL::CAtlArray<MS2Ptr<CItem> >& out,DungeonRewardInfo& info) {
 Unk_RewardItemVec& list=info.m_28;
 Unk_RewardItemIter end=list.FUN_14041a4e0();
 for(Unk_RewardItemIter it=list.FUN_140419db0();it!=end;++it) {
  ItemEntity entity(*it);
  MS2Ptr<CItem> item(new CItem);
  if(item->FUN_14052b130(entity.vfunc_o18_0(),entity.vfunc_o18_1(),0)) {
   item->FUN_140526c70(entity.vfunc_o18_2());
   out.Add(item);
  }
 }
}
MS2_REPLACE_METHOD(0x140E25C30, UIDungeonRewardDialog, FUN_140e25c30, 387, 0x4D9708E2);

// @0x140e25dc0
void UIDungeonRewardDialog::FUN_140e25dc0(size_t count) {
 if(m_labels.FUN_140bd0940()>count) return;
 if(m_1a0==0) return;
 const int top=0x115; const int step=0x24;
 CString name="UIDungeonRewardDialog_MissionLabel";
 for(size_t i=m_labels.FUN_140bd0940();i<count;i++) {
  Unk_RewardPtr<Unk_RewardClip> label(new Unk_RewardLabelClip(name,2));
  m_1a0->FUN_1422c6900((*label).FUN_1422bb890());
  label->FUN_1422bffe0(0,(int)i*step+top);
  m_labels.FUN_140bd0800(label);
 }
}
MS2_REPLACE_METHOD(0x140E25DC0, UIDungeonRewardDialog, FUN_140e25dc0, 549, 0xC23D10DF);

// @0x140e26800
void Unk_RewardBits::FUN_140e26800(Unk_RewardStream* s) { for(int i=0;i<4;i++) m_d[i]=s->vfunc_1(); }
MS2_REPLACE_METHOD(0x140E26800, Unk_RewardBits, FUN_140e26800, 77, 0x0478B94F);
