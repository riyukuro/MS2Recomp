// Battle record types named by RTTI; field and Unk_ helper names are inferred.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include "ms2/placeholder/cptred.h"
#include "ms2/commonfiles/os.h"
class Unk_BattleRef { public: void FUN_14015b020(); int FUN_140159bc0(); void FUN_140159ba0(); };
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
    static void Reference(T* v) { reinterpret_cast<Unk_BattleRef*>(v)->FUN_14015b020(); }
    void AddRefImpl(void*) const { Reference(p); }
    void Release() { if(p) { ReleaseImpl(0); p=0; } }
    void ReleaseImpl(void*) { if(reinterpret_cast<Unk_BattleRef*>(p)->FUN_140159bc0()==0) { Reference(p); reinterpret_cast<Unk_BattleRef*>(p)->FUN_140159ba0(); } }
    void* pad; T* p;
};
class CBattleRecord : public CPtred {
public:
    CBattleRecord(__int64); virtual ~CBattleRecord();
    __int64 FUN_140a03120(); __int64 FUN_140a03140(int); void AddAmount(int,__int64); void Reset();
    __int64 id; __int64 counts[8];
};
MS2_CHECK_SIZE(CBattleRecord,0x60);
MS2_CHECK_OFFSET(CBattleRecord,id,0x18);
MS2_CHECK_OFFSET(CBattleRecord,counts,0x20);
class Unk_BattleFile {
public:
    Unk_BattleFile() noexcept; ~Unk_BattleFile() noexcept;
    HRESULT FUN_1402989b0(const char*,DWORD,DWORD,DWORD,DWORD,LPSECURITY_ATTRIBUTES,HANDLE);
    HRESULT FUN_140299c20(__int64,DWORD);
    HRESULT FUN_140299dc0(const void*,DWORD,DWORD*) noexcept;
    HRESULT FUN_140717be0(); void FUN_1402988c0();
    HANDLE handle; void* transaction;
};
MS2_CHECK_SIZE(Unk_BattleFile,16);
class CBattleRecordGroup : public CPtred {
public:
    typedef Unk_BattlePtr<CBattleRecord> Ptr;
    CBattleRecordGroup(int); virtual ~CBattleRecordGroup();
    void Clear(); void StartIfInactive(); void Start(); void Stop(); int FUN_140a03530(); unsigned FUN_140a03600();
    void AddRecord(__int64); void RemoveRecord(__int64); int HasRecord(__int64); Ptr GetRecord(__int64);
    void FUN_140a037d0(Ptr,int,__int64); void FUN_140a03870(__int64,int,__int64);
    void FUN_140a03920(); void FUN_140a03b30(const CString&); void FUN_140a03c30(); void FUN_140a03c80(__int64,int,__int64);
    int active; unsigned start;
    ATL::CAtlMap<__int64,Ptr> records;
    int type; Unk_BattleFile file;
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
    void StartGroupIfInactive(int); void StartGroup(int); void StopGroup(int); int IsGroupActive(int); unsigned FUN_140a04060(int);
    Ptr GetGroup(int); void AddRecord(int,__int64); void RemoveRecord(int,__int64); int HasRecord(int,__int64);
    CBattleRecordGroup::Ptr FUN_140a041f0(int,__int64);
    CStringW FUN_140a04260(int,__int64,int); CStringW FUN_140a04830(int,__int64,int); CStringW FUN_140a04b00(int);
    static CStringW FUN_140a04bc0(int);
    void FUN_140a04ef0(Unk_BattleDamage*); void FUN_140a05490(__int64,__int64); void FUN_140a05550(__int64,__int64);
    void FUN_140a05610(); void FUN_140a05670(__int64); void FUN_140a056c0(__int64);
    Ptr groups[3];
};
MS2_CHECK_SIZE(CBattleRecordManager,0x38);
MS2_CHECK_OFFSET(CBattleRecordManager,groups,8);
MS2_CHECK_SIZE(CBattleRecordGroup::Ptr,16);
