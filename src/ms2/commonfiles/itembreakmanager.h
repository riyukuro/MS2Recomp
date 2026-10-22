// Item breaking manager and records. Unk_ names are inferred, not original symbols.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/delegate.h"
#include "os.h"
class Unk_BreakInput { public: virtual void vfunc_0(); virtual unsigned char vfunc_1(); virtual unsigned short vfunc_2(); virtual unsigned vfunc_3(); virtual __int64 vfunc_4(); };
class Unk_BreakPacket { public: void* p0; Unk_BreakInput input; };
class Unk_BreakOutput { public: virtual void vfunc_0(); virtual void vfunc_1(unsigned char); virtual void vfunc_2(unsigned short); virtual void vfunc_3(unsigned); };
class Unk_BreakRef { public: void FUN_14015b020(); int FUN_140159bc0(); void FUN_140159ba0(); };
template<class T> class Unk_BreakPtr {
public:
    Unk_BreakPtr() : p(0) {} Unk_BreakPtr(T* value) : p(value) { AddRef(); }
    Unk_BreakPtr(const Unk_BreakPtr& o) : p(o.p) { AddRef(); }
    ~Unk_BreakPtr() { Release(); }
    Unk_BreakPtr& operator=(const Unk_BreakPtr& o) { o.AddRef(); Release(); p=o.p; return *this; }
    bool operator==(T* v) const { return p==v; }
    operator T*() const { return p; } T* get() const { return p; } T* operator->() const { return p; }
private:
    void AddRef() const { if(p) AddRefImpl(0); }
    static void Reference(T* v) { reinterpret_cast<Unk_BreakRef*>(v)->FUN_14015b020(); }
    void AddRefImpl(void*) const { Reference(p); }
    void Release() { if(p) { ReleaseImpl(0); p=0; } }
    void ReleaseImpl(void*) { if(reinterpret_cast<Unk_BreakRef*>(p)->FUN_140159bc0()==0) { Reference(p); reinterpret_cast<Unk_BreakRef*>(p)->FUN_140159ba0(); } }
    void* pad; T* p;
};
namespace ItemBreakCommon {
class BreakItem : public CPtred {
public:
    BreakItem(); BreakItem(__int64,int); virtual ~BreakItem() = default;
    void FUN_1405306f0(); void FUN_140530720(__int64,int); bool FUN_140530750() const;
    __int64 id; int count;
};
struct Unk_PreviewAmount { int low,high; };
class BreakPreview : public CPtred {
public:
    BreakPreview(); virtual ~BreakPreview() = default;
    BreakPreview FUN_1405307e0(const Unk_PreviewAmount&); BreakPreview FUN_140530860(int);
    void FUN_1405308d0(Unk_BreakOutput&) const; void FUN_140530920(Unk_BreakPacket&);
    int FUN_140530990() const; int FUN_1405309d0() const;
    int low,high;
};
typedef Unk_BreakPtr<BreakItem> Ptr;
typedef ATL::CAtlArray<Ptr> Items;
int FUN_140530a10(const Items&,__int64); void FUN_140530b00(Items&,unsigned); bool FUN_140530b40(Items&,int,__int64,int);
}
MS2_CHECK_SIZE(ItemBreakCommon::BreakItem,0x28);
MS2_CHECK_SIZE(ItemBreakCommon::BreakPreview,0x20);
class Unk_BreakItem;
class Unk_BreakItemPtr {
public:
    Unk_BreakItemPtr(int); Unk_BreakItemPtr(const Unk_BreakItemPtr&); Unk_BreakItemPtr(Unk_BreakItemPtr&&); ~Unk_BreakItemPtr();
    Unk_BreakItem* operator->() const; Unk_BreakItem* get() const;
    bool operator==(Unk_BreakItem*) const;
    bool operator!() const { return p==0; }
private: void* pad; Unk_BreakItem* p;
};
MS2_CHECK_SIZE(Unk_BreakItemPtr,0x10);
MS2_CHECK_SIZE(ItemBreakCommon::Ptr,0x10);
MS2_CHECK_OFFSET(Unk_BreakPacket,input,8);
class CMsgBoxData;
class CItemBreakManager : public TSingleton<CItemBreakManager> {
public:
    typedef Unk_BreakItemPtr ItemPtr;
    CItemBreakManager(); virtual ~CItemBreakManager();
    int FUN_140531270(ItemPtr); int FUN_140531510(ItemPtr); int FUN_140531630(ItemPtr); bool FUN_1405316d0(ItemPtr); bool FUN_140531850(ItemPtr);
    int FUN_140531aa0(ItemPtr); int FUN_140531b70(); void SendItemDismantleMode0(int); void FUN_140531cc0(); ItemPtr FUN_140531ce0(int);
    void FUN_140531ed0(); void FUN_140532060(); void FUN_1405320e0(int); void FUN_140532160(Unk_BreakPacket&); void FUN_140532220();
    void FUN_1405322b0(Unk_BreakPacket&); int FUN_140532ab0(); int FUN_140532b60(); int FUN_140532c30(); int SendItemDismantleMode3();
    int FUN_140532de0(ItemPtr,int); void SendItemDismantleMode1(__int64,int,int); void SendItemDismantleMode6(int,int); int FUN_140533340(ItemPtr);
    void FUN_140533440(ItemPtr,int); bool FUN_140533c60(int,const CMsgBoxData&); bool FUN_140533da0(int,const CMsgBoxData&); unsigned FUN_140533e20();
    ItemBreakCommon::Items items; ATL::CAtlArray<unsigned __int64> pending; int type;
};
MS2_CHECK_SIZE(CItemBreakManager,0x50);
