// classobject.h - PLACEHOLDER for ClassObject (RTTI .?AVClassObject@@): the CPtred-derived base of the client's
// XML-loaded script objects (TriggerActionCli, TriggerConditionCli, ...). The owning unit ?\classobject.cpp
// (ctor 0x1401f7ee0, dtor 0x1401f7f20, vftable 0x142cf1398: slot 0 deleting dtor 0x1401f8220, slot 1 0x1401f8450 =
// CStringW class name) is not recovered yet; this declares only what derived units need. NOT an original header.
#pragma once

#include <atlstr.h>
#include <atlcoll.h>
#include "ms2/placeholder/cptred.h"

class ClassObject : public CPtred
{
public:
    ClassObject();                          // 0x1401f7ee0
    virtual ~ClassObject();                 // 0x1401f7f20 (slot 0)
    virtual CStringW GetTypeName();             // slot 1 0x1401f8450: the class name
};
MS2_CHECK_SIZE(ClassObject, 0x18);

// The factory registry (?\classobject.cpp): class name -> CreateObject.
typedef ClassObject* (*ClassObjectCreateFn)();
typedef ATL::CAtlMap<CStringW, ClassObjectCreateFn, ATL::CStringElementTraitsI<CStringW>> ClassObjectFactoryMap;
ClassObjectFactoryMap* FUN_1401f7fe0();                     // the registry (function-local static)
ClassObject* FUN_1401f7f50(CStringW strName);               // creates the registered class; NULL if unknown

// Registers a factory from a 1-byte static (dynamic initializer). Inline: its COMDAT is in the first unit that
// registers (0x140316aa0, commonfiles\dungeonmissiondata.cpp; the GameEvent units bind it as Unk_GEFactoryRegistry).
// The name is invented.
struct ClassObjectRegistrar
{
    ClassObjectRegistrar(CStringW strName, ClassObjectCreateFn pfnCreate) { FUN_1401f7fe0()->SetAt(strName, pfnCreate); }
};
