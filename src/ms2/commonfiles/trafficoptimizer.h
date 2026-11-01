// Recovered CTrafficOptimizer (RTTI name). Unk_* names are inferred from behaviour.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "os.h"

// The exe's CAtlMap<unsigned,unsigned> takes its in-args by const reference.
struct Unk_TOTraits : ATL::CElementTraits<unsigned int> {
    typedef const unsigned int& INARGTYPE;
    // Own copies: the exe has per-unit duplicates of the ATL default traits, which would collide in the symbol map.
    static ULONG Hash(INARGTYPE element) throw() { return ULONG(ULONG_PTR(element)); }
    static bool CompareElements(INARGTYPE a, INARGTYPE b) { return (a == b) != 0; }
};
// Entity-like object whose slot 6 returns a list of 0x20-byte records (id at +0).
struct Unk_TORecord { unsigned id; unsigned pad_04; void* pad_08; void* pad_10; void* pad_18; };
MS2_CHECK_SIZE(Unk_TORecord, 0x20);
struct Unk_TOList { unsigned count; unsigned pad_04; Unk_TORecord records[1]; };
class Unk_TOEntity {
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5();
    virtual Unk_TOList* vfunc_6();
    int FUN_14166c930();
};
class Unk_TOField { public: bool FUN_140375270(); };
template <class T> class Unk_TOPtr {
public:
    ~Unk_TOPtr();  // FUN_1402fec60
    T* operator->() const { return p; }
private:
    void* pad; T* p;
};

class Unk_TOSession;
Unk_TOPtr<Unk_TOField> FUN_140374140(unsigned id);
Unk_TOSession* FUN_1403ed2d0();
unsigned FUN_141bd3060(Unk_TOSession*);

class CTrafficOptimizer : public TSingleton<CTrafficOptimizer> {
public:
    typedef ATL::CAtlMap<unsigned int, unsigned int, Unk_TOTraits, ATL::CElementTraits<unsigned int> > Map;
    static const unsigned MIN_TRAFFIC;
    CTrafficOptimizer();
    virtual ~CTrafficOptimizer();
    unsigned FUN_14087d2f0(Unk_TOEntity* entity);
    unsigned FUN_14087d410(Unk_TOEntity* entity);
    unsigned FUN_14087d500(Unk_TOEntity* entity);
    unsigned FUN_14087d540(Unk_TOEntity* entity);
    void SetTraffic(unsigned key, unsigned value);
    unsigned GetTraffic(unsigned key);
    int FUN_14087d630(unsigned id);
private:
    Map m_map;
};
MS2_CHECK_SIZE(CTrafficOptimizer, 0x50);
