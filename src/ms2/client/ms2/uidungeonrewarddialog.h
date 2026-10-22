// Recovered dungeon reward dialog. Unk_ names are local reconstruction names.
#pragma once
#include "uiskillpreviewdialog.h"
#include "ms2/placeholder/delegate.h"
class CInPacket;
class CItem;
#include <atlcoll.h>
#include <assert.h>
extern "C" _ACRTIMP void __cdecl _wassert(wchar_t const* _Message, wchar_t const* _File, unsigned _Line);
class Unk_RewardClip;
class Unk_RewardButton;
class Unk_RewardRoom;
class Unk_RewardAvatar;
template<class T> class Unk_RewardPtr {
public:
 Unk_RewardPtr(); ~Unk_RewardPtr();
 Unk_RewardPtr(const Unk_RewardPtr&);
 Unk_RewardPtr& operator=(const Unk_RewardPtr&);
 Unk_RewardPtr& operator=(T*);
 Unk_RewardPtr& operator=(int n) { Release(); return *this; }
 void Release();
 T* get() const;
 T* operator->() const;
 T& operator*() const;
 Unk_RewardPtr(T*);
 bool operator==(T*) const;
 operator T*() const;
private: void* m_0; T* m_p;
};
template<> Unk_RewardPtr<Unk_RewardClip>& Unk_RewardPtr<Unk_RewardClip>::operator=(int);
template<> Unk_RewardPtr<Unk_RewardButton>& Unk_RewardPtr<Unk_RewardButton>::operator=(int);
struct ItemEntity;
class Unk_RewardItemIter {
public: bool operator!=(const Unk_RewardItemIter&) const; Unk_RewardItemIter& operator++(); ItemEntity& operator*() const;
private: ItemEntity* m_p;
};
class Unk_RewardItemVec {
public: Unk_RewardItemIter FUN_140419db0(); Unk_RewardItemIter FUN_14041a4e0();
private: void* m_0; void* m_8; void* m_10;
};
class DungeonRewardInfo {
public: DungeonRewardInfo(); ~DungeonRewardInfo(); void FUN_14026cdf0(); void FUN_14026c900(CInPacket&);
 __int64 FUN_14026ccf0(); __int64 FUN_14026cbf0(); int FUN_14026cd70(int); bool FUN_14026ce30();
private:
 void* m_0;
 void* m_8;
 void* m_10;
 void* m_18;
 void* m_20;
public:
 Unk_RewardItemVec m_28;
};
MS2_CHECK_SIZE(DungeonRewardInfo,0x40);
class Timer {
public: Timer(); ~Timer(); void FUN_1408687f0(); int FUN_140868c00(); void FUN_140868750(unsigned int);
private:
 void* m_0;
 void* m_8;
 void* m_10;
 void* m_18;
 void* m_20;
 void* m_28;
 void* m_30;
};
MS2_CHECK_SIZE(Timer,0x38);
class Unk_RewardLabels {
public: Unk_RewardLabels(); ~Unk_RewardLabels(); void FUN_140bcfb70(); size_t FUN_140bd0940(); Unk_RewardPtr<Unk_RewardClip>& FUN_140bcc370(size_t); void FUN_140bd0800(const Unk_RewardPtr<Unk_RewardClip>&);
private: void* m_0; void* m_8; void* m_10;
};
class Unk_RewardStream;
// bitset<32> (commonfiles\bitset.inl): bytes, bit pos%8 of byte pos/8.
#define RWD_BIT_ASSERT(line,str,expr) (void)((!!(expr))||(_wassert(str,L"e:\\build\\kr\\22_04\\ms2code\\commonfiles\\bitset.inl",line),0))
class Unk_RewardBits {
public:
 class Ref {
 public: Ref(Unk_RewardBits* b,int p):m_b(b),m_p(p){}
  operator bool() const {return m_b->FUN_140e26ae0(m_p);}
 private: Unk_RewardBits* m_b; int m_p;
 };
 Unk_RewardBits(){FUN_140e26b80(0);}
 Ref operator[](int pos){RWD_BIT_ASSERT(0x98,L"UINT(pos) < UINT(T)",(unsigned)pos<32u);return Ref(this,pos);}
 // @0x140e26ae0
 bool FUN_140e26ae0(int pos) const {
  if((unsigned)pos>=32u){RWD_BIT_ASSERT(0x194,L"0",0); return false;}
  return (m_d[pos/8]&(1<<(pos%8)))!=0;
 }
 // @0x140e26b80
 void FUN_140e26b80(unsigned char v){for(int i=3;i>=0;i--)m_d[i]=v; if(v)FUN_140e26be0();}
 // @0x140e26be0
 void FUN_140e26be0(){if(0)return;m_d[3]&=0;}
 void FUN_140e26800(Unk_RewardStream*);
private: unsigned char m_d[4];
};
MS2_CHECK_SIZE(Unk_RewardBits,4);
class UIDungeonRewardDialog : public UIDialog, public IUIAvatarEventListener {
public:
 UIDungeonRewardDialog(); virtual ~UIDungeonRewardDialog();
 virtual CString GetTypeName(); virtual void vfunc_26(); virtual void OnLoadComplete();
 virtual void vfunc_67(); virtual void vfunc_72();
 virtual void vfunc_45(Scaleform::GFx::Value*,const CString&,ASData*);
 virtual void vfunc_25(void*,TPtr<Unk_UISwfEntity_25>,void*,void*);
 virtual void vfunc_16(); virtual bool vfunc_17(); virtual int vfunc_o178_1(void*);
 // @0x140e26850
 virtual int vfunc_48() { return 20217; }
 void FUN_140e22130(CInPacket&); void FUN_140e22210(CInPacket&);
 void FUN_140e225a0(CInPacket&); void FUN_140e22650(CInPacket&); void FUN_140e226b0(CInPacket&);
 void FUN_140e22740(const Scaleform::GFx::FunctionHandler::Params&);
 void FUN_140e22780(const Scaleform::GFx::FunctionHandler::Params&);
 void FUN_140e22820();
 void FUN_140e22d70();
 void FUN_140e23690();
 void FUN_140e23e10(bool);
 void FUN_140e24060();
 void FUN_140e24e80();
 void FUN_140e24ed0();
 void FUN_140e24fc0();
 void FUN_140e25050();
 void FUN_140e250e0();
 void FUN_140e25170();
 void FUN_140e25420();
 void FUN_140e25540();
 void FUN_140e255b0();
 void FUN_140e25610();
 void FUN_140e25790();
 void SendDungeonReward();
 void FUN_140e24c50(bool);
 CStringW FUN_140e25840(int);
 void FUN_140e25c30(ATL::CAtlArray<MS2Ptr<CItem> >&,DungeonRewardInfo&); void FUN_140e25dc0(size_t);
 Unk_RewardPtr<Unk_RewardClip> FUN_140ba7930(const CString&);
private:
 MS2_LAYOUT_FRIEND;
 Unk_RewardPtr<Unk_RewardClip> m_180,m_190,m_1a0,m_1b0;
 Unk_RewardPtr<Unk_RewardButton> m_1c0,m_1d0;
 int m_type; bool m_win;
 DungeonRewardInfo m_1e8,m_228;
 CString m_268;
 int m_round,m_stage,m_278;
 Unk_RewardPtr<Unk_RewardRoom> m_room;
 bool m_party; int m_294,m_298;
 Unk_RewardBits m_bits;
 Unk_RewardPtr<Unk_RewardAvatar> m_avatar;
 CStringW m_tip;
 Timer m_timer1,m_timer2;
 bool m_restore;
 Unk_RewardLabels m_labels;
};
MS2_CHECK_SIZE(UIDungeonRewardDialog,0x348);
MS2_CHECK_OFFSET(UIDungeonRewardDialog,m_180,0x180);
MS2_CHECK_OFFSET(UIDungeonRewardDialog,m_1e8,0x1e8);
MS2_CHECK_OFFSET(UIDungeonRewardDialog,m_room,0x280);
MS2_CHECK_OFFSET(UIDungeonRewardDialog,m_avatar,0x2a0);
MS2_CHECK_OFFSET(UIDungeonRewardDialog,m_tip,0x2b0);
MS2_CHECK_OFFSET(UIDungeonRewardDialog,m_timer1,0x2b8);
MS2_CHECK_OFFSET(UIDungeonRewardDialog,m_timer2,0x2f0);
MS2_CHECK_OFFSET(UIDungeonRewardDialog,m_restore,0x328);
MS2_CHECK_OFFSET(UIDungeonRewardDialog,m_labels,0x330);
