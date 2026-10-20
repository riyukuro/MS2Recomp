// tmeratmarketbilldataparam.h - TMeratMarketBillDataParam (RTTI .?AVTMeratMarketBillDataParam@@, base TMarketBillDataParam;
// 0x118 bytes): the purchase dialog's argument block for a merat market product. Recovered from MapleStory2.exe KMS2_DEV x64
// (2022-04-13); header name assumed, member names invented. Ctor 0x140bbfa10, dtor 0x140bbff60 (sized delete 0x140bc0880).
// The definitions live in the exe; only the layout is declared here.
#pragma once
#include "ms2/client/ms2/tmarketbilldataparam.h"

class TMeratMarketBillDataParam : public TMarketBillDataParam
{
public:
    TMeratMarketBillDataParam();                                    // 0x140bbfa10
    // ~TMeratMarketBillDataParam (slot 0, 0x140bbff60) is the implicit one: the exe copy does not reset the vfptr.

    void SetSourceKind(int nKind);                                  // 0x140bc0b10 m_nSourceKind = nKind
    bool FUN_140eacf70() const { return m_bGift; }                  // 0x140eacf70 (inline COMDAT, uimarketbilldialog.cpp)
    void SetGift(bool bGift);                                       // 0x140bc0b30 m_bGift = bGift

    bool m_bGift;                                                   // +0xe0
    int m_nSourceKind;                                              // +0xe4 where the purchase starts (1 = the limited offer dialog)
    MS2Ptr<CPtred> m_spE8;                                          // +0xe8
    MS2Ptr<CPtred> m_spF8;                                          // +0xf8
    MS2Ptr<CPtred> m_sp108;                                         // +0x108
};
MS2_CHECK_SIZE(TMeratMarketBillDataParam, 0x118);
MS2_CHECK_OFFSET(TMeratMarketBillDataParam, m_bGift, 0xe0);
MS2_CHECK_OFFSET(TMeratMarketBillDataParam, m_nSourceKind, 0xe4);
MS2_CHECK_OFFSET(TMeratMarketBillDataParam, m_spE8, 0xe8);
MS2_CHECK_OFFSET(TMeratMarketBillDataParam, m_spF8, 0xf8);
MS2_CHECK_OFFSET(TMeratMarketBillDataParam, m_sp108, 0x108);
