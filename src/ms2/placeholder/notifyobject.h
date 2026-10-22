// NotifyObject: CPtred base and the name virtual, from RTTI and 140939070.
#pragma once
#include <afx.h>
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/classobject.h"
class NotifyObject : public ClassObject {
public:
    NotifyObject();
    virtual ~NotifyObject();
    virtual CStringW GetTypeName();
};
MS2_CHECK_SIZE(NotifyObject, 0x18);
