// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The client's petsystemtabcontents.cpp: the base of the pet
// system dialog's tab pages. PetSystemTabContents is a CPtred with nothing but a vftable (0x18 bytes): every slot is an
// empty default the pages override (slot 3 and slot 8 are pure), so this file only carries the destructor and the seven
// default body-less overrides. The tab pages themselves (TabContentsPetEvolution, TabContentsPetCompose) live in their
// own units. See placeholder\petsystemtabcontents.h.
// MS2-UNIT: ?\petsystemtabcontents.cpp
// MS2-RANGE: 0x140c8ef00-0x140c8efe0 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\petsystemtabcontents.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"

#include "ms2/placeholder/petsystemtabcontents.h"

#include "hook/ms2hook.h"

// ---- unit-local views of unrecovered callees ------------------------------------------------------------------------

// @0x140c8ef00
PetSystemTabContents::~PetSystemTabContents()
{
}

// @0x140c8ef30
void PetSystemTabContents::vfunc_1()
{
}

// @0x140c8ef40
void PetSystemTabContents::vfunc_2(int nTab)
{
    (void)nTab;
}

// @0x140c8ef50
void PetSystemTabContents::vfunc_4()
{
}

// @0x140c8ef60
void PetSystemTabContents::vfunc_5(void* a1, void* a2, void* a3)
{
    (void)a1;
    (void)a2;
    (void)a3;
}

// @0x140c8ef80
int PetSystemTabContents::vfunc_6(const char* szEvent, const Scaleform::GFx::Value* pArgs, unsigned nArgs)
{
    (void)szEvent;
    (void)pArgs;
    (void)nArgs;
    return 0;
}

// @0x140c8efa0
void PetSystemTabContents::vfunc_7(void* a1, TPtr<Unk_UISwfEntity_25> a2, void* a3, void* a4)
{
    (void)a1;
    (void)a3;
    (void)a4;
}

// @0x140c8efd0
void PetSystemTabContents::vfunc_10(void* a1, bool b)
{
    (void)a1;
    (void)b;
}
