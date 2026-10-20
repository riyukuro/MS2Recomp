// notifyworld.h - the NotifyObject messages WorldService posts (RTTI .?AVNotifyChangeServer@@ etc.). NOT an original
// header. Each is NotifyObject + vftable { scalar deleting dtor, vfunc_1 = the notice name }; the dtors do not re-store
// the vptr (implicit). Ctors are COMDATs of ?\worldservice.cpp#4 (0x141bf4790..0x141bf4820), the names (slot 1) live
// in the NotifyObject subclass unit around 0x140db4300.
#pragma once
#include <afx.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/notifyobject.h"

class NotifyChangeServer : public NotifyObject
{
public:
    NotifyChangeServer() {}                     // 0x141bf4790 (vftable 0x142ffedd8)
    virtual CStringW vfunc_1();                 // 0x140db4310
};
MS2_CHECK_SIZE(NotifyChangeServer, 0x18);

class NotifyCreateMyPC : public NotifyObject
{
public:
    NotifyCreateMyPC() {}                       // 0x141bf47c0 (vftable 0x142ffee08)
    virtual CStringW vfunc_1();                 // 0x140db44f0
};
MS2_CHECK_SIZE(NotifyCreateMyPC, 0x18);

class NotifyGameStart : public NotifyObject
{
public:
    NotifyGameStart() {}                        // 0x141bf47f0 (vftable 0x142ffedc0)
    virtual CStringW vfunc_1();                 // 0x140db42b0
};
MS2_CHECK_SIZE(NotifyGameStart, 0x18);

class NotifyRemoveGameObject : public NotifyObject
{
public:
    NotifyRemoveGameObject(int nObjectId) { m_nObjectId = nObjectId; }   // 0x141bf4820 (vftable 0x142ffedf0)
    virtual CStringW vfunc_1();                 // 0x140db4430
    int m_nObjectId;                            // +0x18 the removed object's id
};
MS2_CHECK_SIZE(NotifyRemoveGameObject, 0x20);
