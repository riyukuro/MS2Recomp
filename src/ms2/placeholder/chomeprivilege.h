// chomeprivilege.h - CHomePrivilege (RTTI .?AVCHomePrivilege@@, CPtred, 0x20 bytes): what the local player may use in
// the house he stands in (npc / portal / interact lists and the taxi of the house's Unk_UGCGroup). NOT an original
// header (the member names are invented); defined in commonfiles\homeprivilege.cpp.
#pragma once
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"

class MyPC;

class CHomePrivilege : public CPtred
{
public:
    CHomePrivilege();                                       // 0x14050d4c0
    virtual ~CHomePrivilege();                              // 0x14050d500
    void SetOwner(MyPC* pOwner);                       // attach to the owner
    int FUN_14050d550(int nNpcId);                          // the house lets the player use this npc
    int FUN_14050d6f0(int nPortalId);                       // ... this portal
    int FUN_14050d890(int nInteractId);                     // ... this interact object
    int FUN_14050da30();                                    // ... the taxi

    MyPC* m_pOwner;                                         // +0x18
};
MS2_CHECK_SIZE(CHomePrivilege, 0x20);
