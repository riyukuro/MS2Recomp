// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). AdditionalEffectEventCtx: CPtred-derived record of
// additional-effect event parameters (class name from RTTI, vftable 0x142d15a48; slot 0 = ??_G at 0x14027f9f0 in
// another unit). Member names invented.
// MS2-UNIT: unit_140267670
// MS2-RANGE: 0x140267670-0x140267ba0 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include <atlcoll.h>

// Refcounted-pointer wrapper (commonstruct_2.cpp): {unknown, pointer}; destroyed by the out-of-line Release.
struct Unk_Ref16 { void* m_unknown; void* m_p; };
struct Unk_RefT : Unk_Ref16 { Unk_RefT(); ~Unk_RefT(); };     // ctor 0x14027cb10, dtor 0x14027e000
// Another instantiation of the same wrapper (copy ctor 0x14027caa0, dtor 0x14027dfd0); passed by value.
struct Unk_RefA : Unk_Ref16 { Unk_RefA(const Unk_RefA&); ~Unk_RefA(); };

// Event list owner (size 0x48); ctor 0x14027d780 and dtor live in commonstruct_2.cpp. The ctor is implicit: new T() zero-fills.
struct Unk_List;
Unk_List* FUN_14027c650(Unk_List* l, int blockSize) noexcept;
struct Unk_AEList { void* pad[6]; Unk_AEList() { FUN_14027c650((Unk_List*)this, 10); } };
enum Unk_AdditionalEventValue { Unk_AdditionalEventValue_None = 0 };   // as commonstructptred.h
typedef ATL::CAtlList<Unk_AdditionalEventValue> Unk_AEValueList;
struct CAdditionalEvent : CPtred {
    Unk_AEList events;
    void Add(Unk_AdditionalEventValue value);   // 0x1402804b0
    virtual ~CAdditionalEvent();
};
MS2_CHECK_SIZE(CAdditionalEvent, 0x48);

class AdditionalEffectEventCtx;
Unk_Ref16* FUN_14027e9d0(Unk_Ref16* t, void* p);
bool FUN_14027ece0(Unk_Ref16* t, void* p);
// The pointer reads are MS2Ptr<T>::operator T* (0x14027f2e0 / 0x14027f2f0) over the {unknown, pointer} wrapper.
#define FUN_14027f2e0(t) ((AdditionalEffectEventCtx*)*reinterpret_cast<MS2Ptr<AdditionalEffectEventCtx>*>(t))
#define FUN_14027f2f0(t) ((CAdditionalEvent*)*reinterpret_cast<MS2Ptr<CAdditionalEvent>*>(t))

class AdditionalEffectEventCtx : public CPtred
{
public:
    AdditionalEffectEventCtx();                     // 0x140267670
    AdditionalEffectEventCtx(int value);            // 0x1402676d0
    AdditionalEffectEventCtx(Unk_RefA other);     // 0x140267750
    virtual ~AdditionalEffectEventCtx();            // 0x1402677e0 (??_G 0x14027f9f0)
    void Init();                                    // 0x140267820
    void CopyFrom(Unk_RefA other);                // 0x140267960

    __int64 m_18;
    __int64 m_20;
    __int64 m_28;
    __int64 m_30;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
    float m_48;
    int m_4c;
    int m_50;
    short m_54;
    int m_58;
    int m_5c;
    int m_60;
    Unk_RefT m_events;                              // +0x68
};
MS2_CHECK_SIZE(AdditionalEffectEventCtx, 0x78);

// @0x140267670
AdditionalEffectEventCtx::AdditionalEffectEventCtx()
{
    Init();
}

// @0x1402676d0
AdditionalEffectEventCtx::AdditionalEffectEventCtx(int value)
{
    Init();
    FUN_14027f2f0(&m_events)->Add((Unk_AdditionalEventValue)value);
}

// @0x140267750
AdditionalEffectEventCtx::AdditionalEffectEventCtx(Unk_RefA other)
{
    CopyFrom(other);
}

// @0x1402677e0
AdditionalEffectEventCtx::~AdditionalEffectEventCtx() {}

// @0x140267820
void AdditionalEffectEventCtx::Init()
{
    m_18 = 0;
    m_20 = 0;
    m_28 = 0;
    m_30 = 0;
    m_38 = 0;
    m_3c = 0;
    m_40 = 0;
    m_44 = 0;
    m_48 = 1.0f;
    m_4c = 1;
    m_50 = 0;
    m_54 = 0;
    m_58 = 0;
    m_5c = 0;
    m_60 = 0;
    FUN_14027e9d0(&m_events, new CAdditionalEvent());
}

// @0x140267960
void AdditionalEffectEventCtx::CopyFrom(Unk_RefA other)
{
    if (FUN_14027ece0(&other, 0) != 0)
        return;
    m_18 = FUN_14027f2e0(&other)->m_18;
    m_20 = FUN_14027f2e0(&other)->m_20;
    m_28 = FUN_14027f2e0(&other)->m_28;
    m_30 = FUN_14027f2e0(&other)->m_30;
    m_38 = FUN_14027f2e0(&other)->m_38;
    m_3c = FUN_14027f2e0(&other)->m_3c;
    m_40 = FUN_14027f2e0(&other)->m_40;
    m_44 = FUN_14027f2e0(&other)->m_44;
    m_48 = FUN_14027f2e0(&other)->m_48;
    m_4c = FUN_14027f2e0(&other)->m_4c;
    m_50 = FUN_14027f2e0(&other)->m_50;
    m_54 = FUN_14027f2e0(&other)->m_54;
    m_58 = FUN_14027f2e0(&other)->m_58;
    m_5c = FUN_14027f2e0(&other)->m_5c;
    m_60 = FUN_14027f2e0(&other)->m_60;
    FUN_14027e9d0(&m_events, new CAdditionalEvent());
    reinterpret_cast<Unk_AEValueList&>(FUN_14027f2f0(&m_events)->events).AddTailList(&reinterpret_cast<Unk_AEValueList&>(FUN_14027f2f0(&FUN_14027f2e0(&other)->m_events)->events));
}
