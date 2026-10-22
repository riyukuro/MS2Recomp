// NotifyObject subclasses dispatched by name when a player property changes (GetTypeName returns the notice name).
// Each carries one 8-byte payload at +0x18 (the player the change applies to). Owner unit unrecovered.
#pragma once
#include <afx.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/notifyobject.h"
class PCBase;

class NotifyChangeJob : public NotifyObject
{
public:
    virtual ~NotifyChangeJob();         // 0x140db5760
    virtual CStringW GetTypeName();         // 0x140db4df0
    PCBase* m_pc;                       // +0x18
};
MS2_CHECK_SIZE(NotifyChangeJob, 0x20);

class NotifyChangeEquipment : public NotifyObject
{
public:
    NotifyChangeEquipment(PCBase* pc);        // 0x140db4ef0
    virtual ~NotifyChangeEquipment();         // 0x140db5740
    virtual CStringW GetTypeName();         // 0x140db4ea0
    PCBase* m_pc;                       // +0x18
};
MS2_CHECK_SIZE(NotifyChangeEquipment, 0x20);

class NotifyChangeLevel : public NotifyObject
{
public:
    virtual ~NotifyChangeLevel();         // 0x140db5780
    virtual CStringW GetTypeName();         // 0x140db4f50
    PCBase* m_pc;                       // +0x18
};
MS2_CHECK_SIZE(NotifyChangeLevel, 0x20);

class NotifyChangeTitle : public NotifyObject
{
public:
    virtual ~NotifyChangeTitle();         // 0x140db57c0
    virtual CStringW GetTypeName();         // 0x140db5000
    PCBase* m_pc;                       // +0x18
};
MS2_CHECK_SIZE(NotifyChangeTitle, 0x20);

class NotifyChangePcRidee : public NotifyObject
{
public:
    virtual ~NotifyChangePcRidee();         // 0x140db57a0
    virtual CStringW GetTypeName();         // 0x140db5110
    PCBase* m_pc;                       // +0x18
};
MS2_CHECK_SIZE(NotifyChangePcRidee, 0x20);
