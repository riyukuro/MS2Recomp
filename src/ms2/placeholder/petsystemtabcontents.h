// petsystemtabcontents.h - PLACEHOLDER for PetSystemTabContents (RTTI .?AVPetSystemTabContents@@, 0x18 bytes: CPtred and
// nothing else), the base of the pet system dialog's tab pages (TabContentsPetEvolution). NOT an original header.
// vftable 0x142dd3cd8 (11 slots). The inline ctor 0x140acd650, the pure slots' neighbours' scalar deleting destructor
// (0x140acdb50) and the inline vfunc_9 (0x140ace4d0) are emitted by client\ms2\tabcontentspetevolution.cpp; the dtor and
// the empty default slots are in client\ms2\petsystemtabcontents.cpp (0x140c8ef00-0x140c8efe0, unrecovered).
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/asuicomponent.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/tptr.h"

class Unk_UISwfEntity_25;                                       // pointee of the TPtr handed to vfunc_7 (see uiswfentity.h)

class PetSystemTabContents : public CPtred
{
public:
    PetSystemTabContents();                                     // 0x140acd650 (inline)
    virtual ~PetSystemTabContents();                            //  0 0x140c8ef00 (??_G 0x140acdb50)
    virtual void vfunc_1();                                     //  1 0x140c8ef30 (empty)
    virtual void vfunc_2(int nTab);                             //  2 0x140c8ef40 (empty)
    virtual void vfunc_3(MS2Ptr<ASUIComponent> ui) = 0;         //  3 pure
    virtual void vfunc_4();                                     //  4 0x140c8ef50 (empty)
    virtual void vfunc_5(void* a1, void* a2, void* a3);         //  5 0x140c8ef60 (empty)
    virtual int vfunc_6(const char* szEvent, const Scaleform::GFx::Value* pArgs, unsigned nArgs);   //  6 0x140c8ef80 (returns 0)
    virtual void vfunc_7(void* a1, TPtr<Unk_UISwfEntity_25> a2, void* a3, void* a4);   //  7 0x140c8efa0 (a2 by value, the callee destroys it)
    virtual int vfunc_8() = 0;                                  //  8 pure
    virtual void vfunc_9(void*);                                //  9 0x140ace4d0 (inline)
    virtual void vfunc_10(void* a1, bool b);                    // 10 0x140c8efd0 (empty)
};
MS2_CHECK_SIZE(PetSystemTabContents, 0x18);
