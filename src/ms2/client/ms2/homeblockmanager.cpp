// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// MS2-UNIT: ?\homeblockmanager.cpp
// MS2-RANGE: 0x140a46ab0-0x140a4c470 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$?0AEA_JAEAV?$Unk_PayloadPtr@VHomeBlockInfo@@@@$0A@@?$pair@_JV?$Unk_PayloadPtr@VHomeBlockInfo@@@@@std@@QEAA@AEA_JAEAV?$Unk_PayloadPtr@VHomeBlockInfo@@@@@Z 0x140a48100 ; unique
// MS2-PIN: ??$?0_JV?$Unk_PayloadPtr@VHomeBlockInfo@@@@$0A@@?$pair@$$CB_KV?$Unk_PayloadPtr@VHomeBlockInfo@@@@@std@@QEAA@$$QEAU?$pair@_JV?$Unk_PayloadPtr@VHomeBlockInfo@@@@@1@@Z 0x140a481f0 ; unique
// MS2-PIN: ??$make_pair@AEA_JAEAV?$Unk_PayloadPtr@VHomeBlockInfo@@@@@std@@YA?AU?$pair@_JV?$Unk_PayloadPtr@VHomeBlockInfo@@@@@0@AEA_JAEAV?$Unk_PayloadPtr@VHomeBlockInfo@@@@@Z 0x140a49bd0 ; unique
// MS2-PIN: ??_G?$TSingleton@VHomeBlockManager@@@@UEAAPEAXI@Z 0x140a4a6b0 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\homeblockmanager.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "homeblockmanager.h"
#include "buddymanager.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/ms2format.h"
#include "hook/ms2hook.h"

// Earlier object owns this specialization (0x140979fc0).
template<> Unk_PayloadPtr<CBuddy>::~Unk_PayloadPtr();
template<> void Unk_PayloadPtr<CBuddy>::Reference(CBuddy*);
// Two-argument scoped lock helper shared with ugcmappackageinfo.
class Unk_1401b4ec0 { public: Unk_1401b4ec0(CLockCriticalSection&,int); ~Unk_1401b4ec0(); private: void* m_p; };
MS2_CHECK_SIZE(Unk_1401b4ec0,8);
__int64 FUN_141656a80(PCBase*);
void FUN_141275260(int,int,int);
void FUN_141275460(int,int,int,const fmt::ArgList&);
// Notification interface observed at the buddy/home service singleton.
class Unk_HomeNotifications {
public:
    virtual void slot0();
    virtual void slot1(__int64); virtual void slot2(__int64);
    virtual void slot3(__int64); virtual void slot4(__int64,int);
    virtual void slot5(__int64); virtual void slot6(__int64);
    virtual void slot7(__int64); virtual void slot8(__int64);
    virtual void slot9(__int64); virtual void slot10(__int64,int);
    virtual void slot11(__int64); virtual void slot12(__int64);
    virtual void slot13(__int64); virtual void slot14();
};
MS2_CHECK_SIZE(Unk_HomeNotifications,8);
Unk_HomeNotifications* FUN_140a4a7b0();
extern Unk_HomeNotifications* DAT_143ab6878;
template<class T> inline void HomeMessage(int id,int a,int b,const T& value) {
    const fmt::internal::ArgArray<1>::Type values={fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t>>(value)};
    FUN_141275460(id,a,b,fmt::ArgList(fmt::internal::make_type(value),values));
}

// @0x140a46ab0
HomeBlockManager::HomeBlockManager() {}
// @0x140a46b30
HomeBlockManager::~HomeBlockManager() {}
// @0x140a46b90
void HomeBlockManager::FUN_140a46b90(CInPacket& in) {
    int op=in.vfunc_o8_1();
    switch(op) {
    case 4: FUN_140a46c60(in); break;
    case 2: FUN_140a46f90(in); break;
    case 3: FUN_140a470d0(in); break;
    case 5: FUN_140a47130(in); break;
    case 6: FUN_140a47360(in); break;
    }
}
MS2_REPLACE_METHOD(0x140a46b90, HomeBlockManager, FUN_140a46b90, 188, 0x123F62F9);
// MS2-FUNCTIONAL: three pair/forward COMDATs differ only in the bound int64 forwarding helper.
// Shared HomeBlockInfo field types retained pending coordinator review.
// @0x140a46c60
void HomeBlockManager::FUN_140a46c60(CInPacket& in) {
    Unk_1401b4ec0 guard(m_lock,1);
    unsigned __int64 count=(unsigned)in.vfunc_o8_3();
    for(unsigned __int64 i=0;i<count;++i) {
        HomePtr p(new HomeBlockInfo);
        p->FUN_1402706f0(in);
        m_byId.insert(std::make_pair(p->m_18,p));
        m_byAccount.insert(std::make_pair(p->m_28,p));
    }
}
MS2_REPLACE_METHOD(0x140a46c60, HomeBlockManager, FUN_140a46c60, 483, 0x37E066E1);
// Not hooked: the actor-handle copy constructor has not been mapped.
// @0x140a46e50
void HomeBlockManager::FUN_140a46e50(Unk_SocketPtr<PCBase> actor,CStringW text) {
    COutPacket out(0xc1,0);
    out.vfunc_o10_1(2);
    out.vfunc_o10_4(FUN_141656a80(actor.operator->()));
    out.vfunc_o10_8(text);
    FUN_140710590(out);
}
// @0x140a46f00
void HomeBlockManager::FUN_140a46f00(__int64 id,CStringW text) {
    COutPacket out(0xc1,0);
    out.vfunc_o10_1(2);
    out.vfunc_o10_4(id);
    out.vfunc_o10_8(text);
    FUN_140710590(out);
}
MS2_REPLACE_METHOD(0x140a46f00, HomeBlockManager, FUN_140a46f00, 133, 0x708EE438);
// @0x140a46f90
void HomeBlockManager::FUN_140a46f90(CInPacket& in) {
    HomePtr p(new HomeBlockInfo);
    p->FUN_1402706f0(in);
    FUN_140a479a0(p);
}
MS2_REPLACE_METHOD(0x140a46f90, HomeBlockManager, FUN_140a46f90, 188, 0x29D623F7);
// @0x140a47060
void HomeBlockManager::FUN_140a47060(__int64 id) {
    COutPacket out(0xc1,0);
    out.vfunc_o10_1(3);
    out.vfunc_o10_4(id);
    FUN_140710590(out);
}
MS2_REPLACE_METHOD(0x140a47060, HomeBlockManager, FUN_140a47060, 95, 0x30674299);
// @0x140a470d0
void HomeBlockManager::FUN_140a470d0(CInPacket& in) {
    __int64 id=in.vfunc_o8_4();
    if(id==0) return;
    FUN_140a47b30(id);
}
MS2_REPLACE_METHOD(0x140a470d0, HomeBlockManager, FUN_140a470d0, 83, 0x4BE55B80);
// @0x140a47130
void HomeBlockManager::FUN_140a47130(CInPacket& in) {
    unsigned __int64 id=in.vfunc_o8_4();
    CStringW memo=in.vfunc_o8_8();
    if(id==0) return;
    Unk_1401b4ec0 guard(m_lock,1);
    auto it=m_byId.find(id);
    if(it==m_byId.end()) return;
    HomePtr p=it->second;
    if(p==0) return;
    HomeMessage(0xd59,1,1,p->m_30);
    p->m_50=(const wchar_t*)memo;
    Unk_HomeNotifications* events=FUN_140a4a7b0();
    events->slot13(p->m_18);
}
MS2_REPLACE_METHOD(0x140a47130, HomeBlockManager, FUN_140a47130, 540, 0xF1BE058B);
// @0x140a47360
void HomeBlockManager::FUN_140a47360(CInPacket& in) {
    int result=in.vfunc_o8_3();
    switch(result) {
    case 0: FUN_141275260(0xd5a,1,1); break;
    case 1: FUN_141275260(0xd5b,1,1); break;
    case 2: FUN_141275260(0xd5c,1,1); break;
    case 3: FUN_141275260(0xd5d,1,1); break;
    case 4: FUN_141275260(0xd5e,1,1); break;
    case 5: FUN_141275260(0xd5f,1,1); break;
    case 6: FUN_141275260(0xd60,1,1); break;
    }
}
MS2_REPLACE_METHOD(0x140a47360, HomeBlockManager, FUN_140a47360, 262, 0x6FA9B62B);
// @0x140a47490
HomeBlockManager::HomePtr HomeBlockManager::FUN_140a47490(unsigned __int64 id) {
    Unk_1401b4ec0 guard(m_lock,1);
    auto it=m_byId.find(id);
    if(it==m_byId.end()) return HomePtr(0);
    return it->second;
}
MS2_REPLACE_METHOD(0x140a47490, HomeBlockManager, FUN_140a47490, 232, 0xE93ABFD9);
// @0x140a47580
HomeBlockManager::HomePtr HomeBlockManager::FUN_140a47580(unsigned __int64 id) {
    Unk_1401b4ec0 guard(m_lock,1);
    auto it=m_byAccount.find(id);
    if(it==m_byAccount.end()) return HomePtr(0);
    return it->second;
}
MS2_REPLACE_METHOD(0x140a47580, HomeBlockManager, FUN_140a47580, 232, 0xDBF71D71);
// @0x140a47670
void HomeBlockManager::FUN_140a47670(std::vector<BuddyPtr>& out) {
    Unk_1401b4ec0 guard(m_lock,1);
    for(auto entry:m_byId) {
        if(entry.second==0) continue;
        BuddyPtr buddy=FUN_140a47d10(entry.second);
        if(buddy==0) continue;
        out.push_back(buddy);
    }
}
MS2_REPLACE_METHOD(0x140a47670, HomeBlockManager, FUN_140a47670, 363, 0x7E8CC0CD);
// @0x140a477f0
HomeBlockManager::BuddyPtr HomeBlockManager::FUN_140a477f0(__int64 id) {
    HomePtr p=FUN_140a47490(id);
    if(p==0) return BuddyPtr(0);
    BuddyPtr buddy=FUN_140a47d10(p);
    if(buddy==0) return BuddyPtr(0);
    return buddy;
}
MS2_REPLACE_METHOD(0x140a477f0, HomeBlockManager, FUN_140a477f0, 324, 0x745AB369);
// @0x140a47940
void HomeBlockManager::FUN_140a47940() {
    Unk_1401b4ec0 guard(m_lock,1);
    m_byId.clear();
    m_byAccount.clear();
}
MS2_REPLACE_METHOD(0x140a47940, HomeBlockManager, FUN_140a47940, 86, 0x0AB0FDD5);
// @0x140a479a0
void HomeBlockManager::FUN_140a479a0(HomePtr p) {
    Unk_1401b4ec0 guard(m_lock,1);
    m_byId.insert(std::make_pair(p->m_18,p));
    m_byAccount.insert(std::make_pair(p->m_28,p));
    HomeMessage(0xd57,1,1,p->m_30);
    Unk_HomeNotifications* events=FUN_140a4a7b0();
    events->slot12(p->m_18);
}
MS2_REPLACE_METHOD(0x140a479a0, HomeBlockManager, FUN_140a479a0, 379, 0x95F27FBB);
// @0x140a47b30
void HomeBlockManager::FUN_140a47b30(unsigned __int64 id) {
    Unk_1401b4ec0 guard(m_lock,1);
    auto it=m_byId.find(id);
    if(it==m_byId.end()) return;
    {
        HomePtr p=it->second;
        m_byId.erase(reinterpret_cast<const unsigned __int64&>(p->m_18));
        m_byAccount.erase(reinterpret_cast<const unsigned __int64&>(p->m_28));
        HomeMessage(0xd58,1,1,p->m_30);
        Unk_HomeNotifications* events=FUN_140a4a7b0();
        events->slot14();
    }
}
MS2_REPLACE_METHOD(0x140a47b30, HomeBlockManager, FUN_140a47b30, 317, 0x12A71FB8);
// @0x140a47c80
void HomeBlockManager::FUN_140a47c80(__int64 id,CStringW text) {
    COutPacket out(0xc1,0);
    out.vfunc_o10_1(5);
    out.vfunc_o10_4(id);
    out.vfunc_o10_8(text);
    FUN_140710590(out);
}
MS2_REPLACE_METHOD(0x140a47c80, HomeBlockManager, FUN_140a47c80, 133, 0x7835393B);
// @0x140a47d10
HomeBlockManager::BuddyPtr HomeBlockManager::FUN_140a47d10(HomePtr home) {
    if(home==0) return BuddyPtr(0);
    BuddyPtr buddy(new CBuddy);
    buddy->id=home->m_18;
    buddy->m_48=home->m_20;
    buddy->account=home->m_28;
    buddy->name=(const char*)home->m_30;
    buddy->m_98=home->m_38;
    buddy->m_a0=home->m_3c;
    buddy->m_a4=home->m_40;
    buddy->m_28=home->m_48;
    buddy->memo=(const char*)home->m_50;
    return buddy;
}
// @0x140a4a7b0
Unk_HomeNotifications* FUN_140a4a7b0() {
    return DAT_143ab6878;
}

// hk1 2026-10-20: hooks for the remaining recovered functions (work/hk1/report.md)
MS2_REPLACE(0x140a4a7b0, FUN_140a4a7b0, 8, 0xDB03878A);

