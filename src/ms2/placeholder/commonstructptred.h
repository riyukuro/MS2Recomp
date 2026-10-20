// commonstructptred.h - PLACEHOLDER for the small CPtred records of commonstruct.cpp that had no shared header:
// CUserLimitHistory, CUserLimitGroup, CMarketBuyLimitProduct, CAdditionalEvent and AdditionalEffectEventCtx.
// NOT an original header. Class names are the exe's RTTI names; member names are invented. Layouts from the ctors
// (sizes are the allocation sizes) and the v2525 snapshot's headers (work/ext/v2525, same VAs).
// unit_140269160.cpp / unit_140269440.cpp / unit_140267670.cpp keep older unit-local copies of some of these; do not
// include this header next to them.
#pragma once
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/tptrvalue.h"

class COutputStream;
class CInPacket;

// RTTI CUserLimitHistory (vftable 0x142d15a98, 4 slots: ??_G, Reset 0x1402691b0, Write 0x140269220, Read 0x1402692f0;
// ctor 0x140269160). One purchase-limit record of an account/character.
class CUserLimitHistory : public CPtred
{
public:
    CUserLimitHistory();
    virtual void Reset();
    virtual void Write(COutputStream* pOut);
    virtual void Read(CInPacket& in);

    __int64 m_accountId;                // +0x18
    __int64 m_characterId;              // +0x20
    __int64 m_28;                       // +0x28
    int m_type;                         // +0x30
    __int64 m_productId;                // +0x38 the CUserLimitGroup map key
    int m_count;                        // +0x40
    __int64 m_expireTime;               // +0x48 (0x1402694f0 drops expired records)
};
MS2_CHECK_SIZE(CUserLimitHistory, 0x50);

// RTTI CUserLimitGroup (ctor 0x140269440, dtor 0x1402694a0): the histories of one limit group by product id. The map
// value is the boxed list (RTTI TPtredDummy<CAtlList<TPtr<CUserLimitHistory>>>, vftable 0x142d15c08).
class CUserLimitGroup : public CPtred
{
public:
    typedef ATL::CAtlList<MS2Ptr<CUserLimitHistory> > HistoryList;

    CUserLimitGroup(int groupId);
    ~CUserLimitGroup();
    void RemoveExpired(__int64 now);
    void Add(MS2Ptr<CUserLimitHistory> history);
    int GetCount(__int64 productId);

    int m_groupId;                                              // +0x18
    ATL::CRBMap<unsigned __int64, TPtrValue<HistoryList> > m_histories;  // +0x20 (unsigned key: CompareElementsOrdered 0x140212e20)
};
MS2_CHECK_SIZE(CUserLimitGroup, 0x50);

// RTTI CMarketBuyLimitProduct (ctor 0x140269020, Reset 0x140269070, Write/Read 0x1402690a0/0x1402690f0).
class CMarketBuyLimitProduct : public CPtred
{
public:
    CMarketBuyLimitProduct();
    void Reset();
    void Write(COutputStream* pOut);
    void Read(CInPacket& in);

    int m_productId;                    // +0x18
    int m_count;                        // +0x1c
};
MS2_CHECK_SIZE(CMarketBuyLimitProduct, 0x20);

// RTTI CAdditionalEvent (vftable 0x142d159f8; implicit ctor 0x14027d780 builds the list with block size 10; allocated
// with 0x48 bytes in 0x140267820). Add is 0x1402804b0.
// The list element is a 4-byte non-primitive (an enum: CAtlList passes it by reference, Add 0x1402804b0 takes the
// address of its int argument).
enum Unk_AdditionalEventValue { Unk_AdditionalEventValue_None = 0 };
class CAdditionalEvent : public CPtred
{
public:
    void Add(Unk_AdditionalEventValue value) { m_values.AddTail(value); }

    ATL::CAtlList<Unk_AdditionalEventValue> m_values;   // +0x18
};
MS2_CHECK_SIZE(CAdditionalEvent, 0x48);

// RTTI AdditionalEffectEventCtx (vftable 0x142d15a48; ctors 0x140267670/0x1402676d0/0x140267750, dtor 0x1402677e0,
// Reset 0x140267820, CopyFrom 0x140267960).
class AdditionalEffectEventCtx : public CPtred
{
public:
    AdditionalEffectEventCtx();
    AdditionalEffectEventCtx(int value);
    AdditionalEffectEventCtx(MS2Ptr<AdditionalEffectEventCtx> other);
    ~AdditionalEffectEventCtx();
    void Reset();
    void CopyFrom(MS2Ptr<AdditionalEffectEventCtx> other);

    __int64 m_18;                       // +0x18
    __int64 m_20;                       // +0x20
    __int64 m_28;                       // +0x28
    __int64 m_30;                       // +0x30
    int m_38;                           // +0x38
    int m_3c;                           // +0x3c
    int m_40;                           // +0x40
    int m_44;                           // +0x44
    float m_rate;                       // +0x48
    int m_count;                        // +0x4c (1 after Reset)
    int m_50;                           // +0x50
    short m_54;                         // +0x54
    int m_58;                           // +0x58
    int m_5c;                           // +0x5c
    int m_60;                           // +0x60
    MS2Ptr<CAdditionalEvent> m_event;   // +0x68
};
MS2_CHECK_SIZE(AdditionalEffectEventCtx, 0x78);
