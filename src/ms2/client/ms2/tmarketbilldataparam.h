// tmarketbilldataparam.h - TMarketBillDataParam (RTTI .?AVTMarketBillDataParam@@, base CPtred; 0xe0 bytes): the argument
// block of the merat market's purchase dialog (what to buy, the callbacks that run on "buy" / "gift" / "tooltip").
// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13); header name assumed, member names invented (layout cross-
// checked with the xr2 tree's TMarketBillDataParam.h). Ctor 0x140bbf8d0. The definitions live in the exe; only the layout
// is declared here.
//
// The callbacks are Delegates stored by value: buy (+0xc0), gift (+0xc8, four-argument form), cancel (+0xd0), tooltip (+0xd8).
// The tooltip callback is the three-argument Delegate<bool(Value*, ASData&, MS2Ptr<TMarketBillDataParam>)>; delegate.h only
// has the partial specialization shell for three arguments, so the complete class is specialized here (bound member form,
// copied from the one- and two-argument forms; the bodies are inline COMDATs of the unit that builds the delegate).
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include <utility>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/delegate.h"

#include "ms2/placeholder/asbilldata.h"

class TMarketBillDataParam;

// ePayType: the payment kinds of the merat market (values not recovered).
enum ePayType { ePayTypeUnspecified = 0 };

template <>
class Delegate<bool(Scaleform::GFx::Value*, ASData&, MS2Ptr<TMarketBillDataParam>)>
{
public:
    typedef bool (*Sig)(Scaleform::GFx::Value*, ASData&, MS2Ptr<TMarketBillDataParam>);

    class DelegateImplBase
    {
    public:
        DelegateImplBase();
        virtual ~DelegateImplBase();                                // 0
        virtual DelegateImplBase* vfunc_1() const = 0;              // 1 clone
        virtual bool vfunc_2(Scaleform::GFx::Value* a1, ASData& a2, MS2Ptr<TMarketBillDataParam> a3) = 0;   // 2 Invoke
        virtual bool vfunc_3(const DelegateImplBase* p) const = 0;  // 3 equals
    };

    template <class F>
    class DelegateImpl : public DelegateImplBase
    {
    public:
        DelegateImpl(const DelegateImpl& o) : m_f(o.m_f) {}
        DelegateImpl(const F& f) : m_f(f) {}
        virtual DelegateImplBase* vfunc_1() const { return new DelegateImpl(*this); }
        virtual bool vfunc_2(Scaleform::GFx::Value* a1, ASData& a2, MS2Ptr<TMarketBillDataParam> a3) { return Call(m_f, a1, a2, a3); }
        virtual bool vfunc_3(const DelegateImplBase* p) const
        {
            const DelegateImpl* o = dynamic_cast<const DelegateImpl*>(p);
            if (!o)
                return false;
            return m_f == o->m_f;
        }

    private:
        template <class C, class M>
        static bool Call(std::pair<C*, M>& p, Scaleform::GFx::Value* a1, ASData& a2, MS2Ptr<TMarketBillDataParam> a3)
        {
            return (p.first->*p.second)(a1, a2, a3);
        }

        F m_f;
    };

    Delegate() : m_pImpl(0) {}
    template <class C>
    Delegate(C* const& obj, bool (C::*const& f)(Scaleform::GFx::Value*, ASData&, MS2Ptr<TMarketBillDataParam>))
        : m_pImpl(new DelegateImpl<std::pair<C*, bool (C::*)(Scaleform::GFx::Value*, ASData&, MS2Ptr<TMarketBillDataParam>)> >(std::make_pair(obj, f)))
    {
    }
    Delegate(const Delegate& o);
    ~Delegate();
    Delegate& operator=(const Delegate& o);
    bool IsNull() const { return m_pImpl == 0; }
    bool operator()(Scaleform::GFx::Value* a1, ASData& a2, MS2Ptr<TMarketBillDataParam> a3) const;

private:
    DelegateImplBase* m_pImpl;          // +0x00
};

// The gift callback (+0xc8): Delegate<bool(MS2Ptr<TMarketBillDataParam>, const PaymentMap&, CStringW, CStringW)> (the recipient
// name and the message). Four-argument form, specialized here like the tooltip one; operator() is defined by the unit that
// owns the COMDAT (uimarketbilldialog.cpp).
template <>
class Delegate<bool(MS2Ptr<TMarketBillDataParam>, const ATL::CAtlMap<ePayType, __int64>&, CStringW, CStringW)>
{
public:
    typedef ATL::CAtlMap<ePayType, __int64> PaymentMap;

    class DelegateImplBase
    {
    public:
        DelegateImplBase();
        virtual ~DelegateImplBase();                                // 0
        virtual DelegateImplBase* vfunc_1() const = 0;              // 1 clone
        virtual bool vfunc_2(MS2Ptr<TMarketBillDataParam> a1, const PaymentMap& a2, CStringW a3, CStringW a4) = 0;   // 2 Invoke
        virtual bool vfunc_3(const DelegateImplBase* p) const = 0;  // 3 equals
    };

    Delegate() : m_pImpl(0) {}
    Delegate(const Delegate& o);
    ~Delegate();
    Delegate& operator=(const Delegate& o);
    bool IsNull() const { return m_pImpl == 0; }
    bool operator()(MS2Ptr<TMarketBillDataParam> a1, const PaymentMap& a2, CStringW a3, CStringW a4) const;

private:
    DelegateImplBase* m_pImpl;          // +0x00
};

class TMarketBillDataParam : public CPtred
{
public:
    typedef ATL::CAtlMap<ePayType, __int64> PaymentMap;
    typedef Delegate<bool(MS2Ptr<TMarketBillDataParam>, const PaymentMap&)> BuyCallback;
    typedef Delegate<bool(Scaleform::GFx::Value*, ASData&, MS2Ptr<TMarketBillDataParam>)> TooltipCallback;
    typedef Delegate<bool(MS2Ptr<TMarketBillDataParam>, const PaymentMap&, CStringW, CStringW)> GiftCallback;
    typedef Delegate<bool(MS2Ptr<TMarketBillDataParam>)> CancelCallback;

    TMarketBillDataParam();                                         // 0x140bbf8d0
    virtual ~TMarketBillDataParam();                                // 0

    void FUN_140eab940(bool b);                                     // 0x140eab940 m_b2c = b && feature 0x45
    void FUN_140eab9a0(unsigned __int64 n);                         // 0x140eab9a0 fixed price sum: m_b2d = true, m_n30 = n
    void FUN_140eab9d0(int n, unsigned __int64 v);                  // 0x140eab9d0 m_n38 = n, m_n40 = v (fixed payback)
    MS2Ptr<ASBillData> FUN_140eaba00(int nIndex);                   // 0x140eaba00 the bill row (null when out of range)
    bool FUN_140eacfc0() const { return m_b2d; }                    // 0x140eacfc0 (inline COMDAT, uimarketbilldialog.cpp)


    int m_nType;                                                    // +0x18 (set by the caller, e.g. 3)
    int m_nDialogId;                                                // +0x1c the dialog's vfunc_48 (UI type id)
    CStringA m_strMovie;                                            // +0x20 the movie name the bill dialog opens over
    int m_nCurrency;                                                // +0x28 1
    bool m_b2c;                                                     // +0x2c
    bool m_b2d;                                                     // +0x2d
    unsigned __int64 m_n30;                                         // +0x30
    int m_n38;                                                      // +0x38
    unsigned __int64 m_n40;                                         // +0x40
    ATL::CAtlArray<MS2Ptr<ASBillData> > m_bills;                    // +0x48 the rows of the bill
    int m_nShopId;                                                  // +0x68
    CStringW m_str70;                                               // +0x70
    ASData m_data;                                                  // +0x78
    BuyCallback m_dgBuy;                                            // +0xc0 runs on "buy" (the payment map)
    GiftCallback m_dgGift;                                          // +0xc8 runs on "gift" (the payment map, the recipient, the message)
    CancelCallback m_dgCancel;                                      // +0xd0 runs when the dialog is left by the buy button in basket mode
    TooltipCallback m_dgTooltip;                                    // +0xd8 fills the bill dialog's tooltip
};
MS2_CHECK_SIZE(TMarketBillDataParam, 0xe0);
MS2_CHECK_OFFSET(TMarketBillDataParam, m_nType, 0x18);
MS2_CHECK_OFFSET(TMarketBillDataParam, m_nDialogId, 0x1c);
MS2_CHECK_OFFSET(TMarketBillDataParam, m_strMovie, 0x20);
MS2_CHECK_OFFSET(TMarketBillDataParam, m_nCurrency, 0x28);
MS2_CHECK_OFFSET(TMarketBillDataParam, m_n30, 0x30);
MS2_CHECK_OFFSET(TMarketBillDataParam, m_bills, 0x48);
MS2_CHECK_OFFSET(TMarketBillDataParam, m_nShopId, 0x68);
MS2_CHECK_OFFSET(TMarketBillDataParam, m_str70, 0x70);
MS2_CHECK_OFFSET(TMarketBillDataParam, m_data, 0x78);
MS2_CHECK_OFFSET(TMarketBillDataParam, m_dgBuy, 0xc0);
MS2_CHECK_OFFSET(TMarketBillDataParam, m_dgGift, 0xc8);
MS2_CHECK_OFFSET(TMarketBillDataParam, m_dgCancel, 0xd0);
MS2_CHECK_OFFSET(TMarketBillDataParam, m_dgTooltip, 0xd8);
