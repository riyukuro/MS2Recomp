// Dynamic banned-word filter types from RTTI; Unk_ helper names are inferred.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include "ms2/placeholder/cptred.h"
#include "os.h"
#include "commonstringtable.h"   // TextFilterUnit
class Unk_BanReader { public: virtual void vfunc_0(); virtual unsigned char vfunc_1(); virtual unsigned short vfunc_2(); virtual unsigned vfunc_3(); virtual __int64 vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual CStringW vfunc_8(); };
class Unk_BanWriter { public: virtual void vfunc_0(); virtual void vfunc_1(unsigned char); virtual void vfunc_2(unsigned short); virtual void vfunc_3(unsigned); virtual void vfunc_4(__int64); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(const CStringW&); };
class BannedWordData : public CPtred {
public:
    BannedWordData(); BannedWordData(int,int,const CStringW&,const CStringW&); BannedWordData(Unk_BanReader&);
    virtual ~BannedWordData() = default;
    void FUN_140348e90(Unk_BanWriter&) const; void FUN_140348f30(Unk_BanReader&);
    bool FUN_140349010(const BannedWordData& o) const;
    bool operator==(const BannedWordData& o) const { return (id==o.id && type==o.type && word==o.word && replacement==o.replacement) ? 1 : 0; }
    int id,type; CStringW word,replacement;
};
MS2_CHECK_SIZE(BannedWordData,0x30);
struct Unk_BanChange {
    Unk_BanChange() : mode(0) {} Unk_BanChange(const BannedWordData& v,int m) : data(v),mode(m) {}
    void FUN_140349040(Unk_BanWriter&) const; void FUN_140349090(Unk_BanReader&);
    BannedWordData data; int mode;
};
MS2_CHECK_SIZE(Unk_BanChange,0x38);
template<class T> class Unk_BanPtr {
public:
    Unk_BanPtr(int) : p(0) {} Unk_BanPtr(T* value) : p(value) { AddRef(); }
    Unk_BanPtr(T* value,int ref) : p(value) { if(ref) AddRef(); }
    Unk_BanPtr(const Unk_BanPtr& o) : p(o.p) { AddRef(); }
    Unk_BanPtr(Unk_BanPtr&& o) : p(o.p) { o.p=0; }
    ~Unk_BanPtr() { Release(); }
    Unk_BanPtr& operator=(const Unk_BanPtr& o) { o.AddRef(); Release(); p=o.p; return *this; }
    bool operator==(T* v) const { return p==v; }
    T* get() const { return p; } T* operator->() const { return p; } T& operator*() const { return *p; }
private:
    void AddRef() const { if(p) AddRefImpl(0); }
    static void Reference(T* v) { CPtred::AddRefPtred(reinterpret_cast<CPtred*>(v)); }
    void AddRefImpl(void*) const { Reference(p); }
    void Release() { if(p) { ReleaseImpl(0); p=0; } }
    void ReleaseImpl(void*) { if(CPtred::ReleasePtred(reinterpret_cast<CPtred*>(p))==0) { Reference(p); CPtred::DeletePtred(reinterpret_cast<CPtred*>(p)); } }
    void* pad; T* p;
};
template<> inline void Unk_BanPtr<BannedWordData>::ReleaseImpl(void*) { BannedWordData* value=p; if(CPtred::ReleasePtred(reinterpret_cast<CPtred*>(value))==0) { Reference(value); CPtred::DeletePtred(reinterpret_cast<CPtred*>(value)); } }
class CBannedWordFilter : public CPtred {
public:
    typedef Unk_BanPtr<BannedWordData> WordPtr;
    typedef ATL::CRBMap<long,WordPtr> Map;
    typedef ATL::CAtlArray<WordPtr> Words;
    typedef ATL::CAtlArray<Unk_BanChange> Changes;
    CBannedWordFilter(__int64,const Words&); CBannedWordFilter(__int64,Unk_BanReader&);
    virtual ~CBannedWordFilter() = default;
    void FUN_140349200(Unk_BanWriter&) const;
    int FUN_140349230(const CStringW&,CStringW&);
    const Map& FUN_1403493e0() const; __int64 FUN_140349400() const;
    static void DiffFilter(const Unk_BanPtr<CBannedWordFilter>&,const Unk_BanPtr<CBannedWordFilter>&,Changes&);
    static Unk_BanPtr<CBannedWordFilter> FUN_140349800(__int64,const Unk_BanPtr<CBannedWordFilter>&,const Changes&);
    void FUN_140349b10(Unk_BanWriter&) const; void FUN_140349bd0(Unk_BanReader&); void FUN_140349d00(const Words&);
    __int64 version; Map words; TextFilterUnit filter;
};
MS2_CHECK_SIZE(CBannedWordFilter,0xc8);
class Unk_BanLock { public: Unk_BanLock(); ~Unk_BanLock(); private: void* vf; CRITICAL_SECTION section; };
class Unk_BanGuard { public: Unk_BanGuard(Unk_BanLock&); ~Unk_BanGuard(); operator int(); private: void* p; };
class CDynamicBanWordManager : public TSingleton<CDynamicBanWordManager> {
public:
    typedef Unk_BanPtr<CBannedWordFilter> Ptr;
    CDynamicBanWordManager(); virtual ~CDynamicBanWordManager() = default;
    void FUN_140349fb0(const Ptr&); Ptr FUN_14034a020(); void FUN_14034a0b0(const Ptr&); Ptr FUN_14034a120();
    __int64 FUN_14034a1b0(); int FUN_14034a230(const CStringW&,CStringW&); void FUN_14034a2c0(Unk_BanReader&);
    Unk_BanLock lock; Ptr current,next;
};
MS2_CHECK_SIZE(CDynamicBanWordManager,0x58);
