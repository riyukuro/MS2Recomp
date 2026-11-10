// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): battle statistics and logging.
// MS2-PIN: ?get@?$Unk_BattlePtr@VCBattleRecord@@@@QEBAPEAVCBattleRecord@@XZ 0x140a05c20
// MS2-PIN: ?abs@@YA_J_J@Z 0x140a07180
// MS2-UNIT: client\ms2\battlerecordmanager.cpp
// MS2-RANGE: 0x140a03090-0x140a071a0 .text$mn
// MS2-RANGE: 0x1400c2b20-0x1400c2c90 .text$di
// MS2-RANGE: 0x142c9ed50-0x142c9ede0 .text$yd
// The map's next initializer (1400c2c90) registers CBeamEffect and belongs to beameffect.cpp.
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\battlerecordmanager.cpp"
extern "C" long long __cdecl llabs(long long);
#pragma function(llabs)
#include "ms2/placeholder/ms2stdafx.h"
#include "battlerecordmanager.h"
#include "ms2/placeholder/header_statics_a.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/cnpc.h"
#include "ms2/commonfiles/dungeonroom.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/client/ms2/skillrecord.h"
#include "ms2/placeholder/fittingdollpc.h"
#include <Shlwapi.h>
#include <cstdlib>

extern int DAT_143ab5b00;
extern int DAT_143ab2884;
unsigned long GetTickCountMs2();   // C3: was FUN_140869420
float FUN_14028d280(unsigned);
CStringW FUN_140719a00(__int64);
CStringW FUN_1407197a0(float);
float FUN_140718480(const CStringW&);
CStringW FUN_14083cb20(const CStringW&);
template <class A> CStringW FormatStringId(int nStringId, const A& a);
CStringW GetStringCommonByKey(const CStringW&);
void FUN_141b70810(unsigned,CStringW&);
CString FUN_1401d4330(const wchar_t*,int);
class Unk_BattleActor {
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
    virtual void vfunc_12();
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
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual void vfunc_28();
    virtual void vfunc_29();
    virtual void vfunc_30();
    virtual void vfunc_31();
    virtual void vfunc_32();
    virtual void vfunc_33();
    virtual void vfunc_34();
    virtual void vfunc_35();
    virtual void vfunc_36();
    virtual void vfunc_37();
    virtual void vfunc_38();
    virtual void vfunc_39();
    virtual void vfunc_40();
    virtual void vfunc_41();
    virtual void vfunc_42();
    virtual void vfunc_43();
    virtual void vfunc_44();
    virtual void vfunc_45();
    virtual void vfunc_46();
    virtual void vfunc_47();
    virtual void vfunc_48();
    virtual void vfunc_49();
    virtual void vfunc_50();
    virtual void vfunc_51();
    virtual void vfunc_52();
    virtual void vfunc_53();
    virtual void vfunc_54();
    virtual void vfunc_55();
    virtual void vfunc_56();
    virtual void vfunc_57();
    virtual void vfunc_58();
    virtual void vfunc_59();
    virtual void vfunc_60();
    virtual void vfunc_61();
    virtual void vfunc_62();
    virtual void vfunc_63();
    virtual void vfunc_64();
    virtual void vfunc_65();
    virtual void vfunc_66();
    virtual void vfunc_67();
    virtual void vfunc_68();
    virtual void vfunc_69();
    virtual void vfunc_70();
    virtual void vfunc_71();
    virtual void vfunc_72();
    virtual void vfunc_73();
    virtual void vfunc_74();
    virtual void vfunc_75();
    virtual void vfunc_76();
    virtual CStringW vfunc_77();
};
struct Unk_BattleDamage {
    unsigned __int64 pad_0;
    unsigned __int64 pad_8;
    unsigned __int64 pad_10;
    unsigned __int64 pad_18;
    unsigned __int64 pad_20;
    unsigned target,source;
    unsigned __int64 pad_30;
    unsigned __int64 pad_38;
    unsigned __int64 pad_40;
    unsigned __int64 pad_48;
    unsigned __int64 pad_50;
    unsigned __int64 pad_58;
    unsigned __int64 pad_60;
    unsigned __int64 pad_68;
    unsigned __int64 pad_70;
    unsigned __int64 pad_78;
    unsigned __int64 pad_80;
    unsigned __int64 pad_88;
    ATL::CAtlArray<int> hitTypes;
    // The damage values array is queried only for its length; preserve the original accessor ABI.
    ATL::CAtlArray<__int64> values;
};
MS2_CHECK_OFFSET(Unk_BattleDamage,target,0x28);
MS2_CHECK_OFFSET(Unk_BattleDamage,source,0x2c);
MS2_CHECK_OFFSET(Unk_BattleDamage,hitTypes,0x90);
MS2_CHECK_OFFSET(Unk_BattleDamage,values,0xb0);

// @0x140a03090
CBattleRecord::CBattleRecord(__int64 value) : id(value) { Reset(); }
// @0x140a030f0
CBattleRecord::~CBattleRecord() {}
// @0x140a03120
__int64 CBattleRecord::GetId() { return id; }
MS2_REPLACE_METHOD(0x140a03120, CBattleRecord, GetId, 15, 0xBBB219C9);
// @0x140a03140
__int64 CBattleRecord::GetAmount(int type) { return counts[type]; }
MS2_REPLACE_METHOD(0x140a03140, CBattleRecord, GetAmount, 25, 0x46F3D0E0);
// @0x140a03160
void CBattleRecord::AddAmount(int type,__int64 amount) { counts[type]+=amount; }
MS2_REPLACE_METHOD(0x140a03160, CBattleRecord, AddAmount, 50, 0xA1A69779);
// @0x140a031a0
void CBattleRecord::Reset() { memset(counts,0,sizeof(counts)); }
MS2_REPLACE_METHOD(0x140a031a0, CBattleRecord, Reset, 29, 0x5DA57EF7);
// @0x140a031d0
CBattleRecordGroup::CBattleRecordGroup(int value) : active(0),start(0),type(value) { file.m_h=INVALID_HANDLE_VALUE; }
// @0x140a03290
CBattleRecordGroup::~CBattleRecordGroup() { Clear(); }
// @0x140a03300
void CBattleRecordGroup::Clear() { active=0;start=0;records.RemoveAll();CloseLogFile(); }
MS2_REPLACE_METHOD(0x140a03300, CBattleRecordGroup, Clear, 65, 0x1D6A58BF);
// @0x140a03350
void CBattleRecordGroup::StartIfInactive() { if(active) return; Start(); }
MS2_REPLACE_METHOD(0x140a03350, CBattleRecordGroup, StartIfInactive, 37, 0x9642D72B);
// @0x140a03380
void CBattleRecordGroup::Start() {
    OpenLogFile(); active=1; start=GetTickCountMs2();
    for(POSITION pos=records.GetStartPosition();pos;records.GetNext(pos)) { Ptr record=records.GetValueAt(pos); if(record==0) continue; record->Reset(); }
}
MS2_REPLACE_METHOD(0x140a03380, CBattleRecordGroup, Start, 210, 0x7DD15DA7);
// @0x140a03460
void CBattleRecordGroup::Stop() {
    active=0; start=0;
    for(POSITION pos=records.GetStartPosition();pos;records.GetNext(pos)) { Ptr record=records.GetValueAt(pos); if(record==0) continue; record->Reset(); }
}
MS2_REPLACE_METHOD(0x140a03460, CBattleRecordGroup, Stop, 199, 0xEAC73EAE);
// @0x140a03530
int CBattleRecordGroup::IsActive() {
    if(type==2) { int roomId=DAT_143ab2884; if(!roomId) return 0; DungeonRoomPtr room=TSingleton<DungeonRoomTable>::GetInstance()->GetRoom(roomId); if(room==0) return 0; if(!room->m_chaosDamageMeter) return 0; }
    return active;
}
MS2_REPLACE_METHOD(0x140a03530, CBattleRecordGroup, IsActive, 192, 0x1BC023A0);
// @0x140a03600
unsigned CBattleRecordGroup::FUN_140a03600() { return start; }
MS2_REPLACE_METHOD(0x140a03600, CBattleRecordGroup, FUN_140a03600, 14, 0x8AEE455B);
// Hook deferred: this path allocates a persistent CBattleRecord with DLL-local RTTI.
// @0x140a03620
void CBattleRecordGroup::AddRecord(__int64 id) { if(HasRecord(id)) return; { Ptr record(new CBattleRecord(id)); records.SetAt(id,record); } }
// @0x140a036d0
void CBattleRecordGroup::RemoveRecord(__int64 id) { records.RemoveKey(id); }
MS2_REPLACE_METHOD(0x140a036d0, CBattleRecordGroup, RemoveRecord, 41, 0xAA469CB0);
// @0x140a03700
int CBattleRecordGroup::HasRecord(__int64 id) { return records.Lookup(id)!=0; }
MS2_REPLACE_METHOD(0x140a03700, CBattleRecordGroup, HasRecord, 68, 0x857B9A3E);
// @0x140a03750
CBattleRecordGroup::Ptr CBattleRecordGroup::GetRecord(__int64 id) { Ptr record(0); records.Lookup(id,record); return record; }
MS2_REPLACE_METHOD(0x140a03750, CBattleRecordGroup, GetRecord, 122, 0xA692EB0C);
// @0x140a037d0
void CBattleRecordGroup::RecordAmount(Ptr record,int type,__int64 amount) { if(record==0) return; record->AddAmount(type,amount); LogAmount(record->GetId(),type,amount); }
MS2_REPLACE_METHOD(0x140a037d0, CBattleRecordGroup, RecordAmount, 148, 0xD1C80987);
// @0x140a03870
void CBattleRecordGroup::RecordAmountById(__int64 id,int type,__int64 amount) { Ptr record=GetRecord(id); if(record==0) return; RecordAmount(record,type,amount); }
MS2_REPLACE_METHOD(0x140a03870, CBattleRecordGroup, RecordAmountById, 162, 0x91A3E014);
// @0x140a03920
void CBattleRecordGroup::OpenLogFile() {
    if(!DAT_143ab5b00) return; {
        CloseLogFile(); SYSTEMTIME time; GetLocalTime(&time);
        CString filename; filename.Format("battlerecord_%04d%02d%02d_%02d%02d%02d%03d.txt",time.wYear,time.wMonth,time.wDay,time.wHour,time.wMinute,time.wSecond,time.wMilliseconds);
        const char* dir=".\\log"; char full[MAX_PATH]={0}; char path[MAX_PATH]={0};
        if(!GetFullPathNameA(dir,MAX_PATH,full,0)) { MS2_ASSERT_AT(227,0); return; }
        if(!PathIsDirectoryA(full)) CreateDirectoryA(full,0);
        PathCombineA(path,full,filename);
        file.Create(path,GENERIC_WRITE,3,OPEN_ALWAYS,FILE_ATTRIBUTE_NORMAL,0,0);
        file.Seek(0,FILE_END);
    }
}
MS2_REPLACE_METHOD(0x140a03920, CBattleRecordGroup, OpenLogFile, 517, 0xD0AF2240);
// @0x140a03b30
void CBattleRecordGroup::WriteLogLine(const CString& text) {
    if(!DAT_143ab5b00) return; {
        SYSTEMTIME time; GetLocalTime(&time); CString line; line.Format("%02d:%02d:%02d\t",time.wHour,time.wMinute,time.wSecond); line.Append(text);
        CAtlStringA bytes(line); file.Write(bytes.GetString(),bytes.GetLength(),(DWORD*)0);
    }
}
MS2_REPLACE_METHOD(0x140a03b30, CBattleRecordGroup, WriteLogLine, 246, 0x2A052D05);
// @0x140a03c30
void CBattleRecordGroup::CloseLogFile() { if(file.m_h!=INVALID_HANDLE_VALUE) { file.Flush(); file.Close(); file.m_h=INVALID_HANDLE_VALUE; } }
MS2_REPLACE_METHOD(0x140a03c30, CBattleRecordGroup, CloseLogFile, 73, 0xC1B25F1F);
// @0x140a03c80
void CBattleRecordGroup::LogAmount(__int64 id,int type,__int64 amount) {
    Unk_BattleActor* actor=reinterpret_cast<Unk_BattleActor*>(WorldService::GetInstance()->FUN_141bd1530(id));
    if(!actor) return; { CString text; text.Format("%s\t%d\t%d\t%u\r\n",(const char*)FUN_1401d4330(actor->vfunc_77(),0),reinterpret_cast<PC*>(actor)->GetJobGroupId(),type,amount); WriteLogLine(text); }
}
MS2_REPLACE_METHOD(0x140a03c80, CBattleRecordGroup, LogAmount, 321, 0xCE2B9BD6);
// @0x140a03dd0
CBattleRecordManager::CBattleRecordManager() { for(unsigned i=0;i<3;++i) groups[i]=new CBattleRecordGroup(i); }
// @0x140a03ec0
CBattleRecordManager::~CBattleRecordManager() { for(unsigned i=0;i<3;++i) groups[i]=0; }
// @0x140a03f60
void CBattleRecordManager::StartGroupIfInactive(int type) { groups[type]->StartIfInactive(); }
MS2_REPLACE_METHOD(0x140a03f60, CBattleRecordManager, StartGroupIfInactive, 53, 0xE5F28C1A);
// @0x140a03fa0
void CBattleRecordManager::StartGroup(int type) { groups[type]->Start(); }
MS2_REPLACE_METHOD(0x140a03fa0, CBattleRecordManager, StartGroup, 53, 0x9931178A);
// @0x140a03fe0
void CBattleRecordManager::StopGroup(int type) { groups[type]->Stop(); }
MS2_REPLACE_METHOD(0x140a03fe0, CBattleRecordManager, StopGroup, 53, 0x8B5A3BF5);
// @0x140a04020
int CBattleRecordManager::IsGroupActive(int type) { return groups[type]->IsActive(); }
MS2_REPLACE_METHOD(0x140a04020, CBattleRecordManager, IsGroupActive, 53, 0xE9013C0A);
// @0x140a04060
unsigned CBattleRecordManager::GetGroupStartTick(int type) { return groups[type]->FUN_140a03600(); }
MS2_REPLACE_METHOD(0x140a04060, CBattleRecordManager, GetGroupStartTick, 53, 0xE667A18B);
// @0x140a040a0
CBattleRecordManager::Ptr CBattleRecordManager::GetGroup(int type) { return groups[type]; }
MS2_REPLACE_METHOD(0x140a040a0, CBattleRecordManager, GetGroup, 80, 0xF5A012A2);
// Hook deferred: this path allocates a persistent CBattleRecord with DLL-local RTTI.
// @0x140a04100
void CBattleRecordManager::AddRecord(int type,__int64 id) { groups[type]->AddRecord(id); }
// @0x140a04150
void CBattleRecordManager::RemoveRecord(int type,__int64 id) { groups[type]->RemoveRecord(id); }
MS2_REPLACE_METHOD(0x140a04150, CBattleRecordManager, RemoveRecord, 63, 0x5491EF71);
// @0x140a041a0
int CBattleRecordManager::HasRecord(int type,__int64 id) { return groups[type]->HasRecord(id); }
MS2_REPLACE_METHOD(0x140a041a0, CBattleRecordManager, HasRecord, 63, 0xFF8FB621);
// @0x140a041f0
CBattleRecordGroup::Ptr CBattleRecordManager::GetRecord(int type,__int64 id) { return groups[type]->GetRecord(id); }
MS2_REPLACE_METHOD(0x140a041f0, CBattleRecordManager, GetRecord, 98, 0xFB4FF94A);
// @0x140a04260
CStringW CBattleRecordManager::GetRecordValueText(int group,__int64 id,int type) {
    CBattleRecordGroup::Ptr record=groups[group]->GetRecord(id); if(record==0) return CStringW();
    switch(type) {
    case 0: return FUN_140719a00(record->GetAmount(0));
    case 1: return FUN_140719a00(record->GetAmount(7));
    case 2: { __int64 damage=record->GetAmount(0); float duration=FUN_14028d280(GetTickCountMs2()-groups[group]->FUN_140a03600()); __int64 rate=(damage==0 || duration==0.0f) ? 0.0f : (float)damage/duration; return FUN_140719a00(rate); }
    case 3: { __int64 damage=record->GetAmount(7); float duration=FUN_14028d280(GetTickCountMs2()-groups[group]->FUN_140a03600()); __int64 rate=(damage==0 || duration==0.0f) ? 0.0f : (float)damage/duration; return FUN_140719a00(rate); }
    case 4: { __int64 total=record->GetAmount(2); __int64 hits=record->GetAmount(3); float rate=total!=0 ? (100.0f/(float)total)*(float)hits : 0.0f; return FUN_1407197a0(rate); }
    case 5: { __int64 hits=record->GetAmount(3); __int64 crit=record->GetAmount(4); float rate=hits!=0 ? (100.0f/(float)hits)*(float)crit : 0.0f; return FUN_1407197a0(rate); }
    case 6: return FUN_140719a00(record->GetAmount(1));
    case 7: return FUN_140719a00(record->GetAmount(5));
    case 8: return FUN_140719a00(record->GetAmount(6));
    }
    return CStringW();
}
MS2_REPLACE_METHOD(0x140a04260, CBattleRecordManager, GetRecordValueText, 1436, 0x11C326EA);
// @0x140a04830
CStringW CBattleRecordManager::FUN_140a04830(int group,__int64 id,int type) {
    CBattleRecordGroup::Ptr record=groups[group]->GetRecord(id); if(record==0) return CStringW();
    switch(type) {
    case 0: case 1: case 2: case 3: case 6: case 7: case 8: return StringFormat<CStringW>(L"{0}",FUN_14083cb20(GetRecordValueText(group,id,type)));
    case 4: case 5: return FormatStringId(0x98e,StringFormat(L"{0:0.2f}",FUN_140718480(GetRecordValueText(group,id,type))));
    }
    return CStringW();
}
MS2_REPLACE_METHOD(0x140a04830, CBattleRecordManager, FUN_140a04830, 666, 0x5FE78C60);
// @0x140a04b00
CStringW CBattleRecordManager::GetElapsedTimeText(int group) { CStringW text; unsigned elapsed=0; elapsed=GetTickCountMs2()-groups[group]->FUN_140a03600(); FUN_141b70810(elapsed,text); return text; }
MS2_REPLACE_METHOD(0x140a04b00, CBattleRecordManager, GetElapsedTimeText, 171, 0xE1199823);
// @0x140a04bc0
CStringW CBattleRecordManager::FUN_140a04bc0(int type) {
    switch(type) {
    case 0: return GetStringCommonByKey(L"s_dps_type_caster_damage");
    case 1: return GetStringCommonByKey(L"s_dps_type_caster_damage_boss");
    case 6: return GetStringCommonByKey(L"s_dps_type_target_damage");
    case 2: return GetStringCommonByKey(L"s_dps_type_dps");
    case 3: return GetStringCommonByKey(L"s_dps_type_dps_boss");
    case 4: return GetStringCommonByKey(L"s_dps_type_hit_rate");
    case 5: return GetStringCommonByKey(L"s_dps_type_critical_rate");
    case 7: return GetStringCommonByKey(L"s_dps_type_gain_exp");
    case 8: return GetStringCommonByKey(L"s_dps_type_gain_meso");
    default: return CStringW();
    }
}
MS2_REPLACE(0x140a04bc0, CBattleRecordManager::FUN_140a04bc0, 762, 0x64D39263);
// @0x140a04ef0
void CBattleRecordManager::RecordDamage(Unk_BattleDamage* damage) {
    if(!damage) return;
    __int64 source=WorldService::GetInstance()->FUN_141bd1980(damage->source);
    if(!source) { CNpc* npc=reinterpret_cast<CNpc*>(WorldService::GetInstance()->FUN_141bd13a0(damage->source)); if(npc && npc->GetOwnerId()) source=WorldService::GetInstance()->FUN_141bd1980(npc->GetOwnerId()); }
    __int64 target=WorldService::GetInstance()->FUN_141bd1980(damage->target);
    for(unsigned i=0;i<3;++i) {
        Ptr group=groups[i]; if(!group->IsActive()) continue;
        CBattleRecordGroup::Ptr record=group->GetRecord(source);
        if(record.get()) {
            unsigned count=(unsigned)damage->values.GetCount();
            group->RecordAmount(record,2,count);
            group->RecordAmount(record,0,std::abs(reinterpret_cast<CDamageRecord*>(damage)->GetTotalDamage()));
            CNpc* npc=reinterpret_cast<CNpc*>(WorldService::GetInstance()->FUN_141bd1320(damage->target));
            if(npc && npc->FUN_1410934c0()==6) group->RecordAmount(record,7,std::abs(reinterpret_cast<CDamageRecord*>(damage)->GetTotalDamage()));
            for(unsigned j=0;j<count;++j) {
                int hit=damage->hitTypes[j]; switch(hit) {
                case 0: group->RecordAmount(record,3,1); break;
                case 1: group->RecordAmount(record,3,1); group->RecordAmount(record,4,1); break;
                }
            }
        }
        CBattleRecordGroup::Ptr victim=group->GetRecord(target);
        if(victim.get()) group->RecordAmount(victim,1,std::abs(reinterpret_cast<CDamageRecord*>(damage)->GetTotalDamage()));
    }
}
MS2_REPLACE_METHOD(0x140a04ef0, CBattleRecordManager, RecordDamage, 1432, 0x2FA35BAE);
// @0x140a05490
void CBattleRecordManager::FUN_140a05490(__int64 id,__int64 amount) { for(unsigned i=0;i<3;++i) { Ptr group=groups[i]; if(!group->IsActive()) continue; group->RecordAmountById(id,5,amount); } }
MS2_REPLACE_METHOD(0x140a05490, CBattleRecordManager, FUN_140a05490, 176, 0xCCD842A2);
// @0x140a05550
void CBattleRecordManager::FUN_140a05550(__int64 id,__int64 amount) { for(unsigned i=0;i<3;++i) { Ptr group=groups[i]; if(!group->IsActive()) continue; group->RecordAmountById(id,6,amount); } }
MS2_REPLACE_METHOD(0x140a05550, CBattleRecordManager, FUN_140a05550, 176, 0xCE2A1E75);
// @0x140a05610
void CBattleRecordManager::ClearPartyGroups() { groups[1]->Clear();groups[2]->Clear(); }
MS2_REPLACE_METHOD(0x140a05610, CBattleRecordManager, ClearPartyGroups, 84, 0xDC07BEA9);
// Hook deferred: this path allocates a persistent CBattleRecord with DLL-local RTTI.
// @0x140a05670
void CBattleRecordManager::AddPartyMemberRecord(__int64 id) { AddRecord(1,id);AddRecord(2,id); }
// @0x140a056c0
void CBattleRecordManager::RemovePartyMemberRecord(__int64 id) { RemoveRecord(1,id);RemoveRecord(2,id); }
MS2_REPLACE_METHOD(0x140a056c0, CBattleRecordManager, RemovePartyMemberRecord, 59, 0x7B519FA5);
