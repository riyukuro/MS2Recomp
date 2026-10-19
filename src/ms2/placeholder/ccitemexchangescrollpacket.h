// ccitemexchangescrollpacket.h - PLACEHOLDER for the records of packet 0x9b (item exchange scroll): RTTI-named
// CCItemExchangeScrollPacket::ExchangeRequest and ::ForceFillIngredient (nested in the class in the exe; here a namespace,
// which mangles the same). NOT an original header. Both are 0x30 bytes: CPtred (0x18) + two __int64 (+0x18 the uid of
// the scroll, +0x20 the uid of the target item) + an int (+0x28: the make count / the amount to add). Ctors 0x140f565b0 /
// 0x140f56610, dtors 0x140f56690 / 0x140f566b0 (CPtred::~CPtred only; ??_G 0x140f568a0 / 0x140f568e0) are COMDATs of
// uiitemexchangescrolldialog.cpp. The vftable holds only the deleting destructor; the encoders are FUN_140202470 /
// FUN_140202580 (free functions of the packet unit that take the record and the stream).
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"

namespace CCItemExchangeScrollPacket {

class ExchangeRequest : public CPtred {
public:
    ExchangeRequest() : m_uidScroll(0), m_uidTarget(0), m_nMakeCount(0) {}      // 0x140f565b0
    virtual ~ExchangeRequest() = default;                                       // 0x140f56690
    __int64 m_uidScroll;                                                        // +0x18
    __int64 m_uidTarget;                                                        // +0x20
    int m_nMakeCount;                                                           // +0x28
};
MS2_CHECK_SIZE(ExchangeRequest, 0x30);

class ForceFillIngredient : public CPtred {
public:
    ForceFillIngredient() : m_uidScroll(0), m_uidTarget(0), m_nCount(0) {}      // 0x140f56610
    virtual ~ForceFillIngredient() = default;                                   // 0x140f566b0
    __int64 m_uidScroll;                                                        // +0x18
    __int64 m_uidTarget;                                                        // +0x20
    int m_nCount;                                                               // +0x28
};
MS2_CHECK_SIZE(ForceFillIngredient, 0x30);

}   // namespace CCItemExchangeScrollPacket
