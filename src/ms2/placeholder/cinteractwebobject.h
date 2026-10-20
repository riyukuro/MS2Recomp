// cinteractwebobject.h - CInteractWebObject (RTTI .?AVCInteractWebObject@@): the interact object that opens a web page.
// NOT an original header. CInteractObject + vftable 0x142ffed30 overriding slot 0 (the implicit dtor, ??_G 0x141bfa170)
// and slot 5 (the kind id, 0x141c002d0). Ctor 0x141bf3570 (COMDAT of ?\worldservice.cpp#4, made by the interact object
// factory 0x141bcda90); the dtor 0x141bf6030 does not re-store the vptr (implicit).
#pragma once
#include "ms2/ms2layout.h"
#include "ms2/client/ms2/interactobject.h"

class CInteractWebObject : public CInteractObject
{
public:
    virtual int vfunc_5();                                      // 5 0x141c002d0 kind id
};
MS2_CHECK_SIZE(CInteractWebObject, sizeof(CInteractObject));
