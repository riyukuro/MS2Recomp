// Recovered dungeon reward dialog. Unk_ names are local reconstruction names.
#pragma once
#include "uiskillpreviewdialog.h"
#include "ms2/placeholder/delegate.h"
class CInPacket;
class CItem;
#include <atlcoll.h>
#include <assert.h>
extern "C" _ACRTIMP void __cdecl _wassert(wchar_t const* _Message, wchar_t const* _File, unsigned _Line);
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/astextfield.h"
#include "ms2/placeholder/asbutton.h"
#include "ms2/commonfiles/dungeonroom.h"
#include "ms2/commonfiles/timer.h"
class UIAvatarPC;
struct ItemEntity;
class DungeonRewardInfo {
public: DungeonRewardInfo(); virtual ~DungeonRewardInfo(); void Clear(); void Read(CInPacket&);
 __int64 FUN_14026ccf0(); __int64 FUN_14026cbf0(); unsigned GetReward(unsigned); bool HasRewards();
private:
 void* m_8;
 void* m_10;
 void* m_18;
 void* m_20;
public:
 std::vector<ItemEntity> m_28;
};
MS2_CHECK_SIZE(DungeonRewardInfo,0x40);
class Unk_RewardStream;
// bitset<32> (commonfiles\bitset.inl): bytes, bit pos%8 of byte pos/8.
#define RWD_BIT_ASSERT(line,str,expr) (void)((!!(expr))||(_wassert(str,L"e:\\build\\kr\\22_04\\ms2code\\commonfiles\\bitset.inl",line),0))
class Unk_RewardBits {
public:
 class Ref {
 public: Ref(Unk_RewardBits* b,int p):m_b(b),m_p(p){}
  operator bool() const {return m_b->IsBitSet(m_p);}
 private: Unk_RewardBits* m_b; int m_p;
 };
 Unk_RewardBits(){SetAll(0);}
 Ref operator[](int pos){RWD_BIT_ASSERT(0x98,L"UINT(pos) < UINT(T)",(unsigned)pos<32u);return Ref(this,pos);}
 // @0x140e26ae0
 bool IsBitSet(int pos) const {
  if((unsigned)pos>=32u){RWD_BIT_ASSERT(0x194,L"0",0); return false;}
  return (m_d[pos/8]&(1<<(pos%8)))!=0;
 }
 // @0x140e26b80
 void SetAll(unsigned char v){for(int i=3;i>=0;i--)m_d[i]=v; if(v)FUN_140e26be0();}
 // @0x140e26be0
 void FUN_140e26be0(){if(0)return;m_d[3]&=0;}
 void Read(Unk_RewardStream*);
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
 void OnPacket(CInPacket&); void OnRewardPacket(CInPacket&);
 void OnRoundPacket(CInPacket&); void FUN_140e22650(CInPacket&); void FUN_140e226b0(CInPacket&);
 void OnCloseButton(const Scaleform::GFx::FunctionHandler::Params&);
 void OnPartyLeaveButton(const Scaleform::GFx::FunctionHandler::Params&);
 void FUN_140e22820();
 void FUN_140e22d70();
 void FUN_140e23690();
 void FUN_140e23e10(bool);
 void FUN_140e24060();
 void UpdateMinigameStage();
 void SetMinigameRound();
 void FUN_140e24fc0();
 void ShowMinigame();
 void FUN_140e250e0();
 void SetCharacterInfo();
 void CreateAvatar();
 void LoadRenderTarget();
 void UnloadRenderTarget();
 void ResetState();
 void RequestClose();
 void SendDungeonReward();
 void FUN_140e24c50(bool);
 CStringW FUN_140e25840(int);
 void BuildRewardItems(ATL::CAtlArray<MS2Ptr<CItem> >&,DungeonRewardInfo&); void CreateMissionLabels(size_t);
private:
 MS2_LAYOUT_FRIEND;
 MS2Ptr<ASMovieClip> m_180,m_190,m_1a0,m_1b0;
 MS2Ptr<ASButton> m_1c0,m_1d0;
 int m_type; bool m_win;
 DungeonRewardInfo m_1e8,m_228;
 CString m_268;
 int m_round,m_stage,m_278;
 MS2Ptr<DungeonRoom> m_room;
 bool m_party; int m_294,m_298;
 Unk_RewardBits m_bits;
 MS2Ptr<UIAvatarPC> m_avatar;
 CStringW m_tip;
 Timer m_timer1,m_timer2;
 bool m_restore;
 std::vector<MS2Ptr<ASMovieClip> > m_labels;
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
