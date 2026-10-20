// notifychangedtokenmoney.h - PLACEHOLDER for NotifyChangedTokenMoney (RTTI .?AVNotifyChangedTokenMoney@@ : NotifyObject,
// 0x30 bytes). NOT an original header. The notice NotifySystem posts when a token currency changes (merat, meso
// market tokens, ...): scenestategame.cpp creates it (ctor inline there, dtor 0x141746c00, ??_G 0x1417478d0), vfunc_1
// (its name) is 0x140db4610 in unit_140da50e0.cpp. Listeners dynamic_cast the NotifyObject* they get and read m_nType
// (13 = the meso market token, uiblackmarketpagemeso.cpp). Older units (scenestategame, uishopdialog, unit_140da50e0)
// still carry unit-local copies of the same layout; new code should include this header.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/placeholder/notifyobject.h"

class NotifyChangedTokenMoney : public NotifyObject
{
public:
    virtual ~NotifyChangedTokenMoney();
    virtual CStringW vfunc_1();                             // 0x140db4610 L"NotifyChangedTokenMoney"
    int m_nType;                                            // +0x18 the token kind
    __int64 m_nValue;                                       // +0x20 the new amount
    __int64 m_nDelta;                                       // +0x28 the change
};
MS2_CHECK_SIZE(NotifyChangedTokenMoney, 0x30);
MS2_CHECK_OFFSET(NotifyChangedTokenMoney, m_nType, 0x18);
