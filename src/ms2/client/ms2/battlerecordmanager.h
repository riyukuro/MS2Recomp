// Battle record types named by RTTI; field and Unk_ helper names are inferred.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include <atlfile.h>
#include "ms2/placeholder/cptred.h"
#include "ms2/commonfiles/os.h"
template<class T> class Unk_BattlePtr {
public:
    Unk_BattlePtr() : p(0) {} Unk_BattlePtr(int) : p(0) {}
    Unk_BattlePtr(T* value) : p(value) { AddRef(); }
    Unk_BattlePtr(const Unk_BattlePtr& o) : p(o.p) { AddRef(); }
    Unk_BattlePtr(Unk_BattlePtr&& o) : p(o.p) { o.p=0; }
    ~Unk_BattlePtr() { Release(); }
    Unk_BattlePtr& operator=(const Unk_BattlePtr& o) { o.AddRef(); Release(); p=o.p; return *this; }
    Unk_BattlePtr& operator=(int) { Release(); return *this; }
    Unk_BattlePtr& operator=(T* v) { Unk_BattlePtr temp(v); T* old=p; p=temp.p; temp.p=old; return *this; }
    bool operator==(T* v) const { return p==v; }
    T* get() const { return p; } T* operator->() const { return p; }
private:
    void AddRef() const { if(p) AddRefImpl(0); }
    static void Reference(T* v) { CPtred::AddRefPtred(v); }
    void AddRefImpl(void*) const { Reference(p); }
    void Release() { if(p) { ReleaseImpl(0); p=0; } }
    void ReleaseImpl(void*) { if(CPtred::ReleasePtred(p)==0) { Reference(p); CPtred::DeletePtred(p); } }
    void* pad; T* p;
};
class CBattleRecord : public CPtred {
public:
    CBattleRecord(__int64); virtual ~CBattleRecord();
    __int64 GetId(); __int64 GetAmount(int); void AddAmount(int,__int64); void Reset();
    __int64 id; __int64 counts[8];
};
MS2_CHECK_SIZE(CBattleRecord,0x60);
MS2_CHECK_OFFSET(CBattleRecord,id,0x18);
MS2_CHECK_OFFSET(CBattleRecord,counts,0x20);
MS2_CHECK_SIZE(ATL::CAtlFile,16);
class CBattleRecordGroup : public CPtred {
public:
    typedef Unk_BattlePtr<CBattleRecord> Ptr;
    CBattleRecordGroup(int); virtual ~CBattleRecordGroup();
    void Clear(); void StartIfInactive(); void Start(); void Stop(); int IsActive(); unsigned FUN_140a03600();
    void AddRecord(__int64); void RemoveRecord(__int64); int HasRecord(__int64); Ptr GetRecord(__int64);
    void RecordAmount(Ptr,int,__int64); void RecordAmountById(__int64,int,__int64);
    void OpenLogFile(); void WriteLogLine(const CString&); void CloseLogFile(); void LogAmount(__int64,int,__int64);
    int active; unsigned start;
    ATL::CAtlMap<__int64,Ptr> records;
    int type; ATL::CAtlFile file;
};
MS2_CHECK_SIZE(CBattleRecordGroup,0x80);
MS2_CHECK_OFFSET(CBattleRecordGroup,records,0x20);
MS2_CHECK_OFFSET(CBattleRecordGroup,type,0x68);
MS2_CHECK_OFFSET(CBattleRecordGroup,file,0x70);
struct Unk_BattleDamage;
class CBattleRecordManager : public TSingleton<CBattleRecordManager> {
public:
    typedef Unk_BattlePtr<CBattleRecordGroup> Ptr;
    CBattleRecordManager(); virtual ~CBattleRecordManager();
    void StartGroupIfInactive(int); void StartGroup(int); void StopGroup(int); int IsGroupActive(int); unsigned GetGroupStartTick(int);
    Ptr GetGroup(int); void AddRecord(int,__int64); void RemoveRecord(int,__int64); int HasRecord(int,__int64);
    CBattleRecordGroup::Ptr GetRecord(int,__int64);
    CStringW GetRecordValueText(int,__int64,int); CStringW FUN_140a04830(int,__int64,int); CStringW GetElapsedTimeText(int);
    static CStringW FUN_140a04bc0(int);
    void RecordDamage(Unk_BattleDamage*); void FUN_140a05490(__int64,__int64); void FUN_140a05550(__int64,__int64);
    void ClearPartyGroups(); void AddPartyMemberRecord(__int64); void RemovePartyMemberRecord(__int64);
    Ptr groups[3];
};
MS2_CHECK_SIZE(CBattleRecordManager,0x38);
MS2_CHECK_OFFSET(CBattleRecordManager,groups,8);
MS2_CHECK_SIZE(CBattleRecordGroup::Ptr,16);
