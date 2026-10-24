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

// Refcounted-pointer wrapper (commonstruct_2.cpp): {unknown, pointer}; destroyed by the out-of-line Release.
struct Unk_Ref16 { void* m_unknown; void* m_p; };
struct Unk_RefT : Unk_Ref16 { Unk_RefT(); ~Unk_RefT(); };     // ctor 0x14027cb10, dtor 0x14027e000
// Another instantiation of the same wrapper (copy ctor 0x14027caa0, dtor 0x14027dfd0); passed by value.
struct Unk_RefA : Unk_Ref16 { Unk_RefA(const Unk_RefA&); ~Unk_RefA(); };

// Event list owner (size 0x48); ctor 0x14027d780 and dtor live in commonstruct_2.cpp.
struct Unk_AEList { void* pad[6]; };
struct CAdditionalEvent : CPtred {
    Unk_AEList events;
    CAdditionalEvent();
    virtual ~CAdditionalEvent();
};
MS2_CHECK_SIZE(CAdditionalEvent, 0x48);

class AdditionalEffectEventCtx;
Unk_Ref16* FUN_14027e9d0(Unk_Ref16* t, void* p);
bool FUN_14027ece0(Unk_Ref16* t, void* p);
AdditionalEffectEventCtx* FUN_14027f2e0(Unk_Ref16* t);
CAdditionalEvent* FUN_14027f2f0(Unk_Ref16* t);
void FUN_1402804b0(CAdditionalEvent* e, int value);
void FUN_1402806b0(Unk_AEList* dst, Unk_AEList* src);

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
    FUN_1402804b0(FUN_14027f2f0(&m_events), value);
}

// @0x140267750
AdditionalEffectEventCtx::AdditionalEffectEventCtx(Unk_RefA other)
{
    CopyFrom(other);
}

// @0x1402677e0
AdditionalEffectEventCtx::~AdditionalEffectEventCtx() {}

// @0x140267820
// MS2-FUNCTIONAL: the exe zero-fills the 0x48-byte allocation inline (rep stosb) before the ctor; no source form found
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
    CAdditionalEvent* e = new CAdditionalEvent;
    FUN_14027e9d0(&m_events, e);
}

// @0x140267960
// MS2-FUNCTIONAL: same inline zero-fill of the new CAdditionalEvent as Init (rep stosb) is missing
void AdditionalEffectEventCtx::CopyFrom(Unk_RefA other)
{
    if (FUN_14027ece0(&other, 0) == 0) {
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
        CAdditionalEvent* e = new CAdditionalEvent;
        FUN_14027e9d0(&m_events, e);
        CAdditionalEvent* src = FUN_14027f2f0(&FUN_14027f2e0(&other)->m_events);
        CAdditionalEvent* dst = FUN_14027f2f0(&m_events);
        FUN_1402806b0(&dst->events, &src->events);
    }
}
