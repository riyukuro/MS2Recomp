// Recovered copy construction for the session-member serializer record.
// MS2-UNIT: unit_1415eb020
// MS2-RANGE: 0x1415eb020-0x1415eb200 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmfunc.h"
#include <new>

// MS2-PIN: ??0CNMSessionMemberInfo@@QEAA@AEBV0@@Z 0x1415eb110
// MS2-PIN: ?FUN_1415eb020@@YAPEAVCNMSessionMemberInfo@@PEAV1@PEBV1@@Z 0x1415eb020

// MS2-FUNCTIONAL: copies the recovered 0xf8-byte member layout; the compiler emits a different bulk-copy sequence.
// @0x1415eb110
CNMSessionMemberInfo::CNMSessionMemberInfo(const CNMSessionMemberInfo& r) = default;

// MS2-FUNCTIONAL: forwards the duplicate executable copy-constructor body through the recovered copy constructor.
CNMSessionMemberInfo* FUN_1415eb020(CNMSessionMemberInfo* dst, const CNMSessionMemberInfo* src)
{
    return new (dst) CNMSessionMemberInfo(*src);
}
