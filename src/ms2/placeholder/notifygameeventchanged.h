// NotifyGameEventChanged: NotifyObject subclass dispatched by name "NotifyGameEventChanged" (owner: gameeventmanagercli.cpp).
// Layout from ctor 0x140cedbf0 (int id, CStringW eventName by value, int type); size 0x30. vfunc_1 is 0x140db4130.
#pragma once
#include <afx.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/notifyobject.h"
class NotifyGameEventChanged : public NotifyObject
{
public:
    NotifyGameEventChanged(int id, CStringW eventName, int type);   // 0x140cedbf0
    // implicit virtual dtor 0x140cedda0 (no vptr store in the exe)
    virtual CStringW vfunc_1();                                     // 0x140db4130
    int m_id;                                                       // +0x18
    CStringW m_eventName;                                           // +0x20
    int m_type;                                                     // +0x28
};
MS2_CHECK_SIZE(NotifyGameEventChanged, 0x30);
