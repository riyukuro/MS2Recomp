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
#include <Shlwapi.h>
#include <cstdlib>

extern int DAT_143ab5b00;
extern int DAT_143ab2884;
unsigned FUN_140869420();
float FUN_14028d280(unsigned);
CStringW FUN_140719a00(__int64);
CStringW FUN_1407197a0(float);
float FUN_140718480(const CStringW&);
CStringW FUN_14083cb20(const CStringW&);
CStringW FUN_1401e8510(const wchar_t*,const CStringW&);
CStringW FUN_14052bd00(int,const CStringW&);
CStringW GetStringCommonByKey(const CStringW&);
void FUN_141b70810(unsigned,CStringW&);
CString FUN_1401d4330(const wchar_t*,int);
class Unk_BattleBytes {
public: Unk_BattleBytes(const CString&) noexcept; // ctor 0x1402923c0
     ~Unk_BattleBytes(); // dtor 0x140297740
     int FUN_140298f20() noexcept; const void* FUN_140297d10() noexcept;
private: void* data;
};
MS2_CHECK_SIZE(Unk_BattleBytes,8);
class Unk_BattleRoom {
public:
    unsigned __int64 pad_0;
    unsigned __int64 pad_8;
    unsigned __int64 pad_10;
    unsigned __int64 pad_18;
    unsigned __int64 pad_20;
    unsigned __int64 pad_28;
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
    unsigned __int64 pad_90;
    unsigned __int64 pad_98;
    unsigned __int64 pad_a0;
    unsigned __int64 pad_a8;
    unsigned __int64 pad_b0;
    unsigned __int64 pad_b8;
    unsigned __int64 pad_c0;
    unsigned __int64 pad_c8;
    unsigned __int64 pad_d0;
    unsigned __int64 pad_d8;
    unsigned __int64 pad_e0;
    unsigned __int64 pad_e8;
    unsigned __int64 pad_f0;
    unsigned __int64 pad_f8;
    unsigned __int64 pad_100;
    unsigned __int64 pad_108;
    unsigned __int64 pad_110;
    unsigned __int64 pad_118;
    unsigned __int64 pad_120;
    unsigned __int64 pad_128;
    unsigned __int64 pad_130;
    unsigned __int64 pad_138;
    unsigned __int64 pad_140;
    unsigned __int64 pad_148;
    unsigned __int64 pad_150;
    unsigned __int64 pad_158;
    unsigned __int64 pad_160;
    unsigned __int64 pad_168;
    unsigned __int64 pad_170;
    unsigned __int64 pad_178;
    unsigned __int64 pad_180;
    unsigned pad188; bool enabled;
};
MS2_CHECK_OFFSET(Unk_BattleRoom,enabled,0x18c);
class Unk_BattleRoomPtr {
public: ~Unk_BattleRoomPtr(); bool operator==(Unk_BattleRoom*) const; Unk_BattleRoom* operator->() const;
private: void* pad; Unk_BattleRoom* p;
};
MS2_CHECK_SIZE(Unk_BattleRoomPtr,16);
class Unk_BattleRoomMgr { public: Unk_BattleRoomPtr FUN_1403206b0(int); };
Unk_BattleRoomMgr* FUN_14031c2a0();
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
    unsigned FUN_141654700();
};
class Unk_BattleNpc { public: unsigned FUN_141094f40(); int FUN_1410934c0(); };
class Unk_BattleWorld {
public: Unk_BattleActor* FUN_141bd1530(__int64); __int64 FUN_141bd1980(unsigned); Unk_BattleNpc* FUN_141bd13a0(unsigned); Unk_BattleNpc* FUN_141bd1320(unsigned);
};
Unk_BattleWorld* FUN_1403ed2d0();
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
    struct Values { size_t FUN_1401b8910() const; void* p; size_t count; size_t capacity; int grow; } values;
    __int64 FUN_14175ac30();
};
MS2_CHECK_OFFSET(Unk_BattleDamage,target,0x28);
MS2_CHECK_OFFSET(Unk_BattleDamage,source,0x2c);
MS2_CHECK_OFFSET(Unk_BattleDamage,hitTypes,0x90);
MS2_CHECK_OFFSET(Unk_BattleDamage,values,0xb0);

// @0x140a03090
CBattleRecord::CBattleRecord(__int64 value) : id(value) { FUN_140a031a0(); }
// @0x140a030f0
CBattleRecord::~CBattleRecord() {}
// @0x140a03120
__int64 CBattleRecord::FUN_140a03120() { return id; }
MS2_REPLACE_METHOD(0x140a03120, CBattleRecord, FUN_140a03120, 15, 0xBBB219C9);
// @0x140a03140
__int64 CBattleRecord::FUN_140a03140(int type) { return counts[type]; }
MS2_REPLACE_METHOD(0x140a03140, CBattleRecord, FUN_140a03140, 25, 0x46F3D0E0);
// @0x140a03160
void CBattleRecord::FUN_140a03160(int type,__int64 amount) { counts[type]+=amount; }
MS2_REPLACE_METHOD(0x140a03160, CBattleRecord, FUN_140a03160, 50, 0xA1A69779);
// @0x140a031a0
void CBattleRecord::FUN_140a031a0() { memset(counts,0,sizeof(counts)); }
MS2_REPLACE_METHOD(0x140a031a0, CBattleRecord, FUN_140a031a0, 29, 0x5DA57EF7);
// @0x140a031d0
CBattleRecordGroup::CBattleRecordGroup(int value) : active(0),start(0),type(value) { file.handle=INVALID_HANDLE_VALUE; }
// @0x140a03290
CBattleRecordGroup::~CBattleRecordGroup() { FUN_140a03300(); }
// @0x140a03300
void CBattleRecordGroup::FUN_140a03300() { active=0;start=0;records.RemoveAll();FUN_140a03c30(); }
MS2_REPLACE_METHOD(0x140a03300, CBattleRecordGroup, FUN_140a03300, 65, 0x1D6A58BF);
// @0x140a03350
void CBattleRecordGroup::FUN_140a03350() { if(active) return; FUN_140a03380(); }
MS2_REPLACE_METHOD(0x140a03350, CBattleRecordGroup, FUN_140a03350, 37, 0x9642D72B);
// @0x140a03380
void CBattleRecordGroup::FUN_140a03380() {
    FUN_140a03920(); active=1; start=FUN_140869420();
    for(POSITION pos=records.GetStartPosition();pos;records.GetNext(pos)) { Ptr record=records.GetValueAt(pos); if(record==0) continue; record->FUN_140a031a0(); }
}
MS2_REPLACE_METHOD(0x140a03380, CBattleRecordGroup, FUN_140a03380, 210, 0x7DD15DA7);
// @0x140a03460
void CBattleRecordGroup::FUN_140a03460() {
    active=0; start=0;
    for(POSITION pos=records.GetStartPosition();pos;records.GetNext(pos)) { Ptr record=records.GetValueAt(pos); if(record==0) continue; record->FUN_140a031a0(); }
}
MS2_REPLACE_METHOD(0x140a03460, CBattleRecordGroup, FUN_140a03460, 199, 0xEAC73EAE);
// @0x140a03530
int CBattleRecordGroup::FUN_140a03530() {
    if(type==2) { int roomId=DAT_143ab2884; if(!roomId) return 0; Unk_BattleRoomPtr room=FUN_14031c2a0()->FUN_1403206b0(roomId); if(room==0) return 0; if(!room->enabled) return 0; }
    return active;
}
MS2_REPLACE_METHOD(0x140a03530, CBattleRecordGroup, FUN_140a03530, 192, 0x1BC023A0);
// @0x140a03600
unsigned CBattleRecordGroup::FUN_140a03600() { return start; }
MS2_REPLACE_METHOD(0x140a03600, CBattleRecordGroup, FUN_140a03600, 14, 0x8AEE455B);
// Hook deferred: this path allocates a persistent CBattleRecord with DLL-local RTTI.
// @0x140a03620
void CBattleRecordGroup::FUN_140a03620(__int64 id) { if(FUN_140a03700(id)) return; { Ptr record(new CBattleRecord(id)); records.SetAt(id,record); } }
// @0x140a036d0
void CBattleRecordGroup::FUN_140a036d0(__int64 id) { records.RemoveKey(id); }
MS2_REPLACE_METHOD(0x140a036d0, CBattleRecordGroup, FUN_140a036d0, 41, 0xAA469CB0);
// @0x140a03700
int CBattleRecordGroup::FUN_140a03700(__int64 id) { return records.Lookup(id)!=0; }
MS2_REPLACE_METHOD(0x140a03700, CBattleRecordGroup, FUN_140a03700, 68, 0x857B9A3E);
// @0x140a03750
CBattleRecordGroup::Ptr CBattleRecordGroup::FUN_140a03750(__int64 id) { Ptr record(0); records.Lookup(id,record); return record; }
MS2_REPLACE_METHOD(0x140a03750, CBattleRecordGroup, FUN_140a03750, 122, 0xA692EB0C);
// @0x140a037d0
void CBattleRecordGroup::FUN_140a037d0(Ptr record,int type,__int64 amount) { if(record==0) return; record->FUN_140a03160(type,amount); FUN_140a03c80(record->FUN_140a03120(),type,amount); }
MS2_REPLACE_METHOD(0x140a037d0, CBattleRecordGroup, FUN_140a037d0, 148, 0xD1C80987);
// @0x140a03870
void CBattleRecordGroup::FUN_140a03870(__int64 id,int type,__int64 amount) { Ptr record=FUN_140a03750(id); if(record==0) return; FUN_140a037d0(record,type,amount); }
MS2_REPLACE_METHOD(0x140a03870, CBattleRecordGroup, FUN_140a03870, 162, 0x91A3E014);
// @0x140a03920
void CBattleRecordGroup::FUN_140a03920() {
    if(!DAT_143ab5b00) return; {
        FUN_140a03c30(); SYSTEMTIME time; GetLocalTime(&time);
        CString filename; filename.Format("battlerecord_%04d%02d%02d_%02d%02d%02d%03d.txt",time.wYear,time.wMonth,time.wDay,time.wHour,time.wMinute,time.wSecond,time.wMilliseconds);
        const char* dir=".\\log"; char full[MAX_PATH]={0}; char path[MAX_PATH]={0};
        if(!GetFullPathNameA(dir,MAX_PATH,full,0)) { MS2_ASSERT_AT(227,0); return; }
        if(!PathIsDirectoryA(full)) CreateDirectoryA(full,0);
        PathCombineA(path,full,filename);
        file.FUN_1402989b0(path,GENERIC_WRITE,3,OPEN_ALWAYS,FILE_ATTRIBUTE_NORMAL,0,0);
        file.FUN_140299c20(0,FILE_END);
    }
}
MS2_REPLACE_METHOD(0x140a03920, CBattleRecordGroup, FUN_140a03920, 517, 0xD0AF2240);
// MS2-FUNCTIONAL: Equivalent log formatting/write path; cl omits an intermediate DWORD argument register copy (2 bytes).
// @0x140a03b30
void CBattleRecordGroup::FUN_140a03b30(const CString& text) {
    if(!DAT_143ab5b00) return; {
        SYSTEMTIME time; GetLocalTime(&time); CString line; line.Format("%02d:%02d:%02d\t",time.wHour,time.wMinute,time.wSecond); line.Append(text);
        Unk_BattleBytes bytes(line); int length=bytes.FUN_140298f20(); file.FUN_140299dc0(bytes.FUN_140297d10(),(unsigned)length,0);
    }
}
MS2_REPLACE_METHOD(0x140a03b30, CBattleRecordGroup, FUN_140a03b30, 246, 0x2A052D05);
// @0x140a03c30
void CBattleRecordGroup::FUN_140a03c30() { if(file.handle!=INVALID_HANDLE_VALUE) { file.FUN_140717be0(); file.FUN_1402988c0(); file.handle=INVALID_HANDLE_VALUE; } }
MS2_REPLACE_METHOD(0x140a03c30, CBattleRecordGroup, FUN_140a03c30, 73, 0xC1B25F1F);
// @0x140a03c80
void CBattleRecordGroup::FUN_140a03c80(__int64 id,int type,__int64 amount) {
    Unk_BattleActor* actor=FUN_1403ed2d0()->FUN_141bd1530(id);
    if(!actor) return; { CString text; text.Format("%s\t%d\t%d\t%u\r\n",(const char*)FUN_1401d4330(actor->vfunc_77(),0),actor->FUN_141654700(),type,amount); FUN_140a03b30(text); }
}
MS2_REPLACE_METHOD(0x140a03c80, CBattleRecordGroup, FUN_140a03c80, 321, 0xCE2B9BD6);
// @0x140a03dd0
CBattleRecordManager::CBattleRecordManager() { for(unsigned i=0;i<3;++i) groups[i]=new CBattleRecordGroup(i); }
// @0x140a03ec0
CBattleRecordManager::~CBattleRecordManager() { for(unsigned i=0;i<3;++i) groups[i]=0; }
// @0x140a03f60
void CBattleRecordManager::FUN_140a03f60(int type) { groups[type]->FUN_140a03350(); }
MS2_REPLACE_METHOD(0x140a03f60, CBattleRecordManager, FUN_140a03f60, 53, 0xE5F28C1A);
// @0x140a03fa0
void CBattleRecordManager::FUN_140a03fa0(int type) { groups[type]->FUN_140a03380(); }
MS2_REPLACE_METHOD(0x140a03fa0, CBattleRecordManager, FUN_140a03fa0, 53, 0x9931178A);
// @0x140a03fe0
void CBattleRecordManager::FUN_140a03fe0(int type) { groups[type]->FUN_140a03460(); }
MS2_REPLACE_METHOD(0x140a03fe0, CBattleRecordManager, FUN_140a03fe0, 53, 0x8B5A3BF5);
// @0x140a04020
int CBattleRecordManager::FUN_140a04020(int type) { return groups[type]->FUN_140a03530(); }
MS2_REPLACE_METHOD(0x140a04020, CBattleRecordManager, FUN_140a04020, 53, 0xE9013C0A);
// @0x140a04060
unsigned CBattleRecordManager::FUN_140a04060(int type) { return groups[type]->FUN_140a03600(); }
MS2_REPLACE_METHOD(0x140a04060, CBattleRecordManager, FUN_140a04060, 53, 0xE667A18B);
// @0x140a040a0
CBattleRecordManager::Ptr CBattleRecordManager::FUN_140a040a0(int type) { return groups[type]; }
MS2_REPLACE_METHOD(0x140a040a0, CBattleRecordManager, FUN_140a040a0, 80, 0xF5A012A2);
// Hook deferred: this path allocates a persistent CBattleRecord with DLL-local RTTI.
// @0x140a04100
void CBattleRecordManager::FUN_140a04100(int type,__int64 id) { groups[type]->FUN_140a03620(id); }
// @0x140a04150
void CBattleRecordManager::FUN_140a04150(int type,__int64 id) { groups[type]->FUN_140a036d0(id); }
MS2_REPLACE_METHOD(0x140a04150, CBattleRecordManager, FUN_140a04150, 63, 0x5491EF71);
// @0x140a041a0
int CBattleRecordManager::FUN_140a041a0(int type,__int64 id) { return groups[type]->FUN_140a03700(id); }
MS2_REPLACE_METHOD(0x140a041a0, CBattleRecordManager, FUN_140a041a0, 63, 0xFF8FB621);
// @0x140a041f0
CBattleRecordGroup::Ptr CBattleRecordManager::FUN_140a041f0(int type,__int64 id) { return groups[type]->FUN_140a03750(id); }
MS2_REPLACE_METHOD(0x140a041f0, CBattleRecordManager, FUN_140a041f0, 98, 0xFB4FF94A);
// @0x140a04260
CStringW CBattleRecordManager::FUN_140a04260(int group,__int64 id,int type) {
    CBattleRecordGroup::Ptr record=groups[group]->FUN_140a03750(id); if(record==0) return CStringW();
    switch(type) {
    case 0: return FUN_140719a00(record->FUN_140a03140(0));
    case 1: return FUN_140719a00(record->FUN_140a03140(7));
    case 2: { __int64 damage=record->FUN_140a03140(0); float duration=FUN_14028d280(FUN_140869420()-groups[group]->FUN_140a03600()); __int64 rate=(damage==0 || duration==0.0f) ? 0.0f : (float)damage/duration; return FUN_140719a00(rate); }
    case 3: { __int64 damage=record->FUN_140a03140(7); float duration=FUN_14028d280(FUN_140869420()-groups[group]->FUN_140a03600()); __int64 rate=(damage==0 || duration==0.0f) ? 0.0f : (float)damage/duration; return FUN_140719a00(rate); }
    case 4: { __int64 total=record->FUN_140a03140(2); __int64 hits=record->FUN_140a03140(3); float rate=total!=0 ? (100.0f/(float)total)*(float)hits : 0.0f; return FUN_1407197a0(rate); }
    case 5: { __int64 hits=record->FUN_140a03140(3); __int64 crit=record->FUN_140a03140(4); float rate=hits!=0 ? (100.0f/(float)hits)*(float)crit : 0.0f; return FUN_1407197a0(rate); }
    case 6: return FUN_140719a00(record->FUN_140a03140(1));
    case 7: return FUN_140719a00(record->FUN_140a03140(5));
    case 8: return FUN_140719a00(record->FUN_140a03140(6));
    }
    return CStringW();
}
MS2_REPLACE_METHOD(0x140a04260, CBattleRecordManager, FUN_140a04260, 1436, 0x11C326EA);
// @0x140a04830
CStringW CBattleRecordManager::FUN_140a04830(int group,__int64 id,int type) {
    CBattleRecordGroup::Ptr record=groups[group]->FUN_140a03750(id); if(record==0) return CStringW();
    switch(type) {
    case 0: case 1: case 2: case 3: case 6: case 7: case 8: return FUN_1401e8510(L"{0}",FUN_14083cb20(FUN_140a04260(group,id,type)));
    case 4: case 5: return FUN_14052bd00(0x98e,StringFormat(L"{0:0.2f}",FUN_140718480(FUN_140a04260(group,id,type))));
    }
    return CStringW();
}
MS2_REPLACE_METHOD(0x140a04830, CBattleRecordManager, FUN_140a04830, 666, 0x5FE78C60);
// @0x140a04b00
CStringW CBattleRecordManager::FUN_140a04b00(int group) { CStringW text; unsigned elapsed=0; elapsed=FUN_140869420()-groups[group]->FUN_140a03600(); FUN_141b70810(elapsed,text); return text; }
MS2_REPLACE_METHOD(0x140a04b00, CBattleRecordManager, FUN_140a04b00, 171, 0xE1199823);
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
// MS2-FUNCTIONAL: All damage-event branches recovered; cl omits an intermediate owner-ID argument register copy (2 bytes).
// @0x140a04ef0
void CBattleRecordManager::FUN_140a04ef0(Unk_BattleDamage* damage) {
    if(!damage) return;
    __int64 source=FUN_1403ed2d0()->FUN_141bd1980(damage->source);
    if(!source) { Unk_BattleNpc* npc=FUN_1403ed2d0()->FUN_141bd13a0(damage->source); if(npc && npc->FUN_141094f40()) { unsigned owner=npc->FUN_141094f40(); source=FUN_1403ed2d0()->FUN_141bd1980((unsigned long)owner); } }
    __int64 target=FUN_1403ed2d0()->FUN_141bd1980(damage->target);
    for(unsigned i=0;i<3;++i) {
        Ptr group=groups[i]; if(!group->FUN_140a03530()) continue;
        CBattleRecordGroup::Ptr record=group->FUN_140a03750(source);
        if(record.get()) {
            unsigned count=(unsigned)damage->values.FUN_1401b8910();
            group->FUN_140a037d0(record,2,count);
            group->FUN_140a037d0(record,0,std::abs(damage->FUN_14175ac30()));
            Unk_BattleNpc* npc=FUN_1403ed2d0()->FUN_141bd1320(damage->target);
            if(npc && npc->FUN_1410934c0()==6) group->FUN_140a037d0(record,7,std::abs(damage->FUN_14175ac30()));
            for(unsigned j=0;j<count;++j) {
                int hit=damage->hitTypes[j]; switch(hit) {
                case 0: group->FUN_140a037d0(record,3,1); break;
                case 1: group->FUN_140a037d0(record,3,1); group->FUN_140a037d0(record,4,1); break;
                }
            }
        }
        CBattleRecordGroup::Ptr victim=group->FUN_140a03750(target);
        if(victim.get()) group->FUN_140a037d0(victim,1,std::abs(damage->FUN_14175ac30()));
    }
}
MS2_REPLACE_METHOD(0x140a04ef0, CBattleRecordManager, FUN_140a04ef0, 1432, 0x2FA35BAE);
// @0x140a05490
void CBattleRecordManager::FUN_140a05490(__int64 id,__int64 amount) { for(unsigned i=0;i<3;++i) { Ptr group=groups[i]; if(!group->FUN_140a03530()) continue; group->FUN_140a03870(id,5,amount); } }
MS2_REPLACE_METHOD(0x140a05490, CBattleRecordManager, FUN_140a05490, 176, 0xCCD842A2);
// @0x140a05550
void CBattleRecordManager::FUN_140a05550(__int64 id,__int64 amount) { for(unsigned i=0;i<3;++i) { Ptr group=groups[i]; if(!group->FUN_140a03530()) continue; group->FUN_140a03870(id,6,amount); } }
MS2_REPLACE_METHOD(0x140a05550, CBattleRecordManager, FUN_140a05550, 176, 0xCE2A1E75);
// @0x140a05610
void CBattleRecordManager::FUN_140a05610() { groups[1]->FUN_140a03300();groups[2]->FUN_140a03300(); }
MS2_REPLACE_METHOD(0x140a05610, CBattleRecordManager, FUN_140a05610, 84, 0xDC07BEA9);
// Hook deferred: this path allocates a persistent CBattleRecord with DLL-local RTTI.
// @0x140a05670
void CBattleRecordManager::FUN_140a05670(__int64 id) { FUN_140a04100(1,id);FUN_140a04100(2,id); }
// @0x140a056c0
void CBattleRecordManager::FUN_140a056c0(__int64 id) { FUN_140a04150(1,id);FUN_140a04150(2,id); }
MS2_REPLACE_METHOD(0x140a056c0, CBattleRecordManager, FUN_140a056c0, 59, 0x7B519FA5);
