// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The SingletonObject base class and two function-local
// registries of callbacks (map from an 8-byte key to a list of void(*)() handlers) with the loops that invoke every handler.
// MS2-UNIT: ?\singletonobject.cpp
// MS2-RANGE: 0x1407dc950-0x1407dee30 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$?0AEBU?$less@_K@std@@U_Zero_then_variadic_args_t@1@@?$_Compressed_pair@U?$less@_K@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CB_KV?$vector@P6AXXZV?$allocator@P6AXXZ@std@@@std@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KV?$vector@P6AXXZV?$allocator@P6AXXZ@std@@@std@@@std@@@std@@@2@$00@2@$00@std@@QEAA@U_One_then_variadic_args_t@1@AEBU?$less@_K@1@$$QEAU_Zero_then_variadic_args_t@1@@Z 0x1407dcc70 ; unique
// MS2-PIN: ??F?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KV?$vector@P6AXXZV?$allocator@P6AXXZ@std@@@std@@@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x1407dd7d0 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"

#include <map>
#include <vector>

class SingletonObject
{
public:
    SingletonObject();                                      // 0x1407dc950
    virtual ~SingletonObject();                             // 0 0x1407dc970 (deleting 0x1407dd960)
    virtual bool vfunc_1();                                 // 1 0x1407dc990
};

typedef void (*GcCallbackFn)();
typedef std::vector<GcCallbackFn> GcCallbackList;
typedef std::map<unsigned __int64, GcCallbackList> GcCallbackMap;

// @0x1407dc950
SingletonObject::SingletonObject()
{
}

// @0x1407dc970
SingletonObject::~SingletonObject()
{
}

// @0x1407dc990
bool SingletonObject::vfunc_1()
{
    return true;
}

// @0x1407dc9a0
GcCallbackMap& GetCallbackMapA()
{
    static GcCallbackMap callbacks;
    return callbacks;
}

// @0x1407dca20
GcCallbackMap& GetCallbackMapB()
{
    static GcCallbackMap callbacks;
    return callbacks;
}

// @0x1407dcaa0
void RunCallbacksA()
{
    GcCallbackMap& callbacks = GetCallbackMapA();
    for (GcCallbackMap::iterator it = callbacks.begin(); it != callbacks.end(); it++) {
        GcCallbackList& list = it->second;
        for (GcCallbackList::iterator fn = list.begin(); fn != list.end(); fn++)
            (*fn)();
    }
}

// @0x1407dcb70
void RunCallbacksB()
{
    const GcCallbackMap& callbacks = GetCallbackMapB();
    for (GcCallbackMap::const_reverse_iterator it = callbacks.rbegin(); it != callbacks.rend(); it++) {
        const GcCallbackList& list = it->second;
        for (GcCallbackList::const_reverse_iterator fn = list.rbegin(); fn != list.rend(); fn++)
            (*fn)();
    }
}

// Anchors for COMDATs of this range that the registries' code reaches only through the exe's other users:
// the iterator predecrements and the UCRT header-inline memmove_s.
void Unk_GcRegistryAnchor(GcCallbackMap::iterator& itMap, GcCallbackList::iterator& itList, void* pDst, const void* pSrc)
{
    --itMap;
    --itList;
    memmove_s(pDst, 8, pSrc, 8);
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142c9bff0-0x142c9c030 .text$yd
