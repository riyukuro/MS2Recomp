// notifychangeactivemycoditab.h - NotifyChangeActiveMyCodiTab (RTTI, 0x20, vftable 0x142ec0418). Split out of
// notifychangebuff.h (which owns GetTypeName / CreateObject) so equipment.cpp can construct it without that header's
// AdditionalCli view. NOT an original header.
#pragma once
#include <afx.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/notifyobject.h"

// The codi (outfit) tab became active / inactive (ctor 0x1411f7160, implicit dtor 0x1411f7730: equipment.cpp).
class NotifyChangeActiveMyCodiTab : public NotifyObject
{
public:
    NotifyChangeActiveMyCodiTab(unsigned char nActive) : m_nActive(nActive) {}
    virtual CStringW GetTypeName();                     // 0x140db4d30
    static ClassObject* CreateObject();             // 0x140db4d20
    unsigned char m_nActive;                        // +0x18
};
MS2_CHECK_SIZE(NotifyChangeActiveMyCodiTab, 0x20);
