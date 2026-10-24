// Recovered copy construction for the rejected-user serializer record.
// MS2-UNIT: unit_1415eaeb0
// MS2-RANGE: 0x1415eaeb0-0x1415eb020 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmfunc.h"
#include <new>

// MS2-PIN: ??0CNMRejectedUser@@QEAA@AEBV0@@Z 0x1415eaf30
// MS2-PIN: ?FUN_1415eaeb0@@YAPEAVCNMRejectedUser@@PEAV1@PEBV1@@Z 0x1415eaeb0
// MS2-PIN: ??0CNMSerializable@@QEAA@AEBV0@@Z 0x1415eafb0

CNMRejectedUser::CNMRejectedUser(const CNMRejectedUser& r) = default;
CNMSerializable::CNMSerializable(const CNMSerializable& r) noexcept = default;

// MS2-FUNCTIONAL: forwards the duplicate executable copy-constructor body through the recovered C++ copy constructor.
CNMRejectedUser* FUN_1415eaeb0(CNMRejectedUser* dst, const CNMRejectedUser* src)
{
    return new (dst) CNMRejectedUser(*src);
}
