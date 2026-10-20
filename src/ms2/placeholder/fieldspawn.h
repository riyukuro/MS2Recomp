// Field spawn records; layout proved by constructors and allocation sizes in fielddata.cpp.
#pragma once
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/billboardinfo.h"
class CStarting : public CPtred {
public:
    CStarting();
    // @0x140377790
    virtual ~CStarting() = default;
    int id;
    bool enabled;
    Unk_CommonPosition position, rotation;
};
MS2_CHECK_OFFSET(CStarting, position, 0x20);
MS2_CHECK_SIZE(CStarting, 0x38);
class CNpcSpawnData : public CPtred {
public:
    CNpcSpawnData();
    // @0x140377700
    virtual ~CNpcSpawnData() = default;
    int id, count, probability;
    CStringW tag;
};
MS2_CHECK_OFFSET(CNpcSpawnData, tag, 0x28);
MS2_CHECK_SIZE(CNpcSpawnData, 0x30);
class CFieldSpawnTag : public CPtred {
public:
    CFieldSpawnTag();
    // @0x140377670
    virtual ~CFieldSpawnTag() = default;
    unsigned mapCode;
    int spawnPointId;
    CStringW tag;
    int difficulty, difficultyMin, population, coolTime, removed, petPopulation;
    unsigned petSpawnProbability;
};
MS2_CHECK_OFFSET(CFieldSpawnTag, tag, 0x20);
MS2_CHECK_OFFSET(CFieldSpawnTag, removed, 0x38);
MS2_CHECK_SIZE(CFieldSpawnTag, 0x48);
struct Unk_FieldSpawnPair {
    Unk_FieldSpawnPair() : mapCode(0), spawnPointId(0) {}
    unsigned mapCode;
    int spawnPointId;
};
MS2_CHECK_SIZE(Unk_FieldSpawnPair, 8);

#include <atlcoll.h>
#include "ms2/placeholder/tptr.h"
#include "ms2/placeholder/socketptr.h"
// This RTTI-proven instantiation is the 16-byte CPtred pointer, unlike the
// eight-byte virtual-release TPtr instances used for actors.
template<> class TPtr<CFieldSpawnTag> {
public:
    TPtr() : p(0) {}
    TPtr(CFieldSpawnTag* v) : p(v) { AddRef(); }
    TPtr(const TPtr& v) : p(v.p) { AddRef(); }
    TPtr(TPtr&& v) : p(v.p) { v.p=0; }
    ~TPtr() { Release(); }
    TPtr& operator=(const TPtr& v) { v.AddRef(); Release(); p=v.p; return *this; }
    TPtr& operator=(CFieldSpawnTag* v) { TPtr tmp(v); CFieldSpawnTag* old=p; p=tmp.p; tmp.p=old; return *this; }
    CFieldSpawnTag* operator->() const { return p; }
private:
    static void Reference(CFieldSpawnTag* v) { CPtred::AddRefPtred(v); }
    void AddRef() const { if(p) AddRefImpl((void*)0); }
    void AddRefImpl(void*) const { Reference(p); }
    void Release() { if(p) { ReleaseImpl((void*)0); p=0; } }
    void ReleaseImpl(void*) { if(CPtred::ReleasePtred(p)==0) { Reference(p); CPtred::DeletePtred(p); } }
    void* pad;
    CFieldSpawnTag* p;
};
MS2_CHECK_SIZE(TPtr<CFieldSpawnTag>,16);
typedef ATL::CRBMap<int, TPtr<CFieldSpawnTag> > Unk_FieldSpawnMap;
template<> struct Unk_SocketRef<Unk_FieldSpawnMap> {
    static CPtred* Base(Unk_FieldSpawnMap* p) {
        CPtred* result;
        if (p == NULL) result = NULL;
        else result = CONTAINING_RECORD(p, TPtredDummy<Unk_FieldSpawnMap>, value);
        return result;
    }
    static TPtredDummy<Unk_FieldSpawnMap>* New(void*) { return new TPtredDummy<Unk_FieldSpawnMap>(); }
    static Unk_FieldSpawnMap* Value(CPtred* p) {
        Unk_FieldSpawnMap* result;
        if (p == NULL) result = NULL;
        else result = &static_cast<TPtredDummy<Unk_FieldSpawnMap>*>(p)->value;
        return result;
    }
    static Unk_FieldSpawnMap* Create(void*) { return Value(FUN_1401ba820(New(NULL))); }
};
MS2_SOCKETPTR_BOXED(Unk_FieldSpawnMap)
MS2_CHECK_SIZE(TPtredDummy<Unk_FieldSpawnMap>,0x48);
MS2_CHECK_OFFSET(TPtredDummy<Unk_FieldSpawnMap>,value,0x18);
