// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// MS2-UNIT: client\ms2\roomtimermanager.cpp
// MS2-RANGE: 0x140b8c180-0x140b8d3e0 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\roomtimermanager.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "roomtimermanager.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
// RTTI-only declaration: this unit never constructs or accesses UITimerDialog fields.
class UITimerDialog : public UITimerBase { int m_188,m_18c; void* m_190; int m_198,m_19c; bool m_1a0; };
MS2_CHECK_SIZE(UITimerDialog,0x1a8);
class Unk_RoomUIManager { public: MS2Ptr<UIObject> FUN_141adcea0(int); };
Unk_RoomUIManager* FUN_1403ed2b0();
CStringW FUN_1408116a0(int,const int&);
CStringW GetStringCommon(int);
void FUN_1412751f0(const CStringW&,int,int);
template<class T> T* FindRoomUI(int id) {
    if(FUN_1403ed2b0()) {
        MS2Ptr<UIObject> p=FUN_1403ed2b0()->FUN_141adcea0(id);
        if(p.get()) return dynamic_cast<T*>((UIObject*)p);
    }
    return 0;
}
template<class K,class V> Unk_OSInput& ReadRoomMap(Unk_OSInput&,std::map<K,V>&);
// @0x140b8c180
RoomTimerManager::RoomTimerManager() : m_type(0),m_start(0),m_duration(0),m_offset(0) {}
// @0x140b8c210
RoomTimerManager::~RoomTimerManager() {}
// @0x140b8c260
void RoomTimerManager::Dispatch(Unk_RoomPacket& packet) {
    int type=packet.vfunc_1();
    switch(type) {
    case 0: Start(packet); break;
    case 1: Update(packet); break;
    case 2: Restart(packet); break;
    case 3: ReadValues(packet); break;
    case 4: Stop(packet); break;
    case 5: Cancel(packet); break;
    }
}
MS2_REPLACE_METHOD(0x140B8C260, RoomTimerManager, Dispatch, 199, 0x1121F277);
// @0x140b8c350
void RoomTimerManager::Start(Unk_RoomPacket& packet) {
    m_type=packet.vfunc_1();
    m_start=packet.vfunc_3();
    m_duration=packet.vfunc_3();
    m_offset=packet.vfunc_3();
    Close();
    if(m_duration<=0) return;
    if(m_type==0) return;
    m_timer=GetTimer(m_type);
    if(m_timer==0) return;
    m_timer->vfunc_84(m_start,m_duration,m_offset);
    m_timer->FUN_141924680();
}
MS2_REPLACE_METHOD(0x140B8C350, RoomTimerManager, Start, 505, 0xCCC30E31);
// @0x140b8c550
void RoomTimerManager::Update(Unk_RoomPacket& packet) {
    m_start=packet.vfunc_3();
    m_duration=packet.vfunc_3();
    int type=packet.vfunc_3();
    int delta=packet.vfunc_3();
    if(m_timer==0) return;
    if(m_duration<=0) { Close(); return; }
    m_timer->vfunc_84(m_start,m_duration,m_offset);
    if(type==1) {
        if(delta>0) {
            CStringW message=FUN_1408116a0(0x99f,delta/1000);
            FUN_1412751f0(message,4,1);
            m_timer->vfunc_85();
        } else if(delta<0) {
            CStringW message=FUN_1408116a0(0x9a1,abs(delta/1000));
            FUN_1412751f0(message,2,1);
            m_timer->vfunc_86();
        }
    } else if(type==2) {
        CStringW message=GetStringCommon(0x9a0);
        FUN_1412751f0(message,4,1);
        m_timer->vfunc_85();
    }
}
MS2_REPLACE_METHOD(0x140B8C550, RoomTimerManager, Update, 745, 0xA0260656);
// @0x140b8c840
void RoomTimerManager::Restart(Unk_RoomPacket& packet) {
    m_type=packet.vfunc_1();
    m_start=packet.vfunc_3();
    m_duration=packet.vfunc_3();
    m_offset=packet.vfunc_3();
    Close();
    if(m_duration<=0) return;
    m_timer=GetTimer(m_type);
    if(m_timer==0) return;
    m_timer->vfunc_84(m_start,m_duration,m_offset);
    m_timer->FUN_141924680();
}
MS2_REPLACE_METHOD(0x140B8C840, RoomTimerManager, Restart, 486, 0xE991608C);
// @0x140b8ca30
void RoomTimerManager::ReadValues(Unk_RoomPacket& packet) {
    m_values.clear();
    ReadRoomMap(packet,m_values);
    Unk_RoomPtr<UITimerBase> timer=GetTimer(m_type);
    if(timer==0) return;
    for(auto it=m_values.begin();it!=m_values.end();it++) timer->vfunc_87(it->first,it->second);
}
MS2_REPLACE_METHOD(0x140B8CA30, RoomTimerManager, ReadValues, 330, 0x674DF6FA);
// @0x140b8cb80
void RoomTimerManager::Stop(Unk_RoomPacket&) { Close();Reset(); }
MS2_REPLACE_METHOD(0x140B8CB80, RoomTimerManager, Stop, 39, 0xC1793661);
// @0x140b8cbb0
void RoomTimerManager::Cancel(Unk_RoomPacket&) { Close();Reset(); }
MS2_REPLACE_METHOD(0x140B8CBB0, RoomTimerManager, Cancel, 39, 0xD9240AD0);
// @0x140b8cbe0
void RoomTimerManager::Show() {
    if(IsActive()) {
        m_timer=GetTimer(m_type);
        if(m_timer==0) return;
        m_timer->FUN_141924680();
    }
}
MS2_REPLACE_METHOD(0x140B8CBE0, RoomTimerManager, Show, 165, 0xF04F0E57);
// @0x140b8cc90
bool RoomTimerManager::IsActive() { if(m_type==0) return false; if(m_start==0) return false; if(m_duration==0) return false; return true; }
MS2_REPLACE_METHOD(0x140B8CC90, RoomTimerManager, IsActive, 53, 0xABC62B3B);
// @0x140b8ccd0
void RoomTimerManager::Reset() { m_type=0;m_start=0;m_duration=0;m_timer=0; }
MS2_REPLACE_METHOD(0x140B8CCD0, RoomTimerManager, Reset, 69, 0x2B87988F);
// @0x140b8cd20
Unk_RoomPtr<UITimerBase> RoomTimerManager::GetTimer(int type) {
    switch(type) {
    case 1: return FindRoomUI<UITimerDialog>(0x4e3a);
    case 2: return FindRoomUI<UITimerGaugeDialog>(0x4f61);
    default: MS2_ASSERT_AT(203,0);return 0;
    }
}
MS2_REPLACE_METHOD(0x140B8CD20, RoomTimerManager, GetTimer, 200, 0x8A1B5D6E);
// @0x140b8cdf0
void RoomTimerManager::Close() {
    if(m_timer.get()) { m_timer->vfunc_68();m_timer=0; }
}
MS2_REPLACE_METHOD(0x140B8CDF0, RoomTimerManager, Close, 96, 0x78272173);
template<class K,class V>
Unk_OSInput& ReadRoomMap(Unk_OSInput& input,std::map<K,V>& values) {
    unsigned count=input.vfunc_3();
    for(unsigned i=0;i<count;i++) {
        K key;V value;
        input.Read6(key).Read4(value);
        values.insert(std::make_pair(key,value));
    }
    return input;
}
