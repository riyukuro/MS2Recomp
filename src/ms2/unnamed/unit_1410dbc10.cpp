// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). COMDAT/glue tail between the house-mark and cube-map units: the
// egf::Entity int property write with the client's property cache, efd::DynamicCast / GenericFactory / message-wrapper
// instantiations for EntityChangeMessage and SceneGraphAddedMessage, the UI lookups for the house demolish dialog and the
// house mark, and three tiny factory / constant helpers.
// MS2-UNIT: unit_1410dbc10
// MS2-RANGE: 0x1410dbc10-0x1410dc420 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
// MS2-PIN: ??$DynamicCast@VUnk_Service6100017@@VISystemService@efd@@@efd@@YAPEAVUnk_Service6100017@@PEAVISystemService@0@@Z 0x1410dbdf0
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\cubemapinformationservice.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2layout.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include <string.h>
#include <new>
#include <efd/IBase.h>
#include <efd/IMessage.h>
#include <efd/ISystemService.h>
#include <egf/Entity.h>
#include <egf/EntityChangeMessage.h>
#include <ecr/CoreRuntimeMessages.h>
#include "ms2/client/ms2/uiservice.h"
#include "ms2/client/ms2/uihousemark.h"
#include "ms2/unnamed/unit_14134fc90.h"
#include "ms2/placeholder/cptred.h"

// ---- unrecovered helpers ----

// The property cache of the client's entities: a map keyed by property id (+0xd0) that is only kept when the flag at +0xc8 is set.
CUIService* FUN_1403ed2b0();                                                    // the UI service
unsigned FUN_1408a1ff0();                                                       // class id of int
struct Unk_PropIt { void* p; };
struct Unk_PropRec { unsigned __int64 a, b, c; };
void* FUN_1409481f0(void* tbl, Unk_PropIt* out);                                      // end()
void* FUN_140948250(void* tbl, Unk_PropIt* out, unsigned* pId);                       // find(id)
char FUN_140947540(void* a, void* b);                                           // iterator ==
void* FUN_140947580(void* tbl, unsigned* pId);                                  // operator[](id)
void* FUN_140947490(Unk_PropRec* out, unsigned id, void* p, unsigned nType);          // property record (0x18)
void* FUN_140876480(void* out, int nCategory);                                  // memory category helper, returns the category
void* FUN_14208a860(unsigned __int64 nSize, unsigned nCategory);                // category allocation

struct Unk_EntityPropertyAccess : egf::Entity
{
    using egf::Entity::GetPropertyValueUnsafe;
    using egf::Entity::SetPropertyValueUnsafe;
};

// The service that owns the cube-map information (class id 0x06100017), the same stand-in as unit_140fa9eb0's.
class Unk_Service6100017 : public efd::ISystemService {
public:
    static const efd::ClassID CLASS_ID = 0x06100017;
};

class SalesInfo : public CPtred                         // house sale marker record (0x38, ctor 0x1411232e0)
{
public:
    SalesInfo();
    virtual ~SalesInfo();
};

struct Unk_CMISDemolishUI;
class Unk_CMISHouseMark;

// @0x1410dbc10
// MS2-FUNCTIONAL: the exe frame has no /GS cookie or unwind handler (our locals whose address is passed get one); behaviour identical.
void FUN_1410dbc10(egf::Entity* e, unsigned id, const int* pVal)
{
    Unk_EntityPropertyAccess* pEnt = (Unk_EntityPropertyAccess*)e;
    if (*((char*)e + 0xc8) == 0)
        return;
    void* pTbl = (char*)e + 0xd0;
    Unk_PropIt itEnd, itFind;
    void* pEnd = FUN_1409481f0(pTbl, &itEnd);
    void* pFind = FUN_140948250(pTbl, &itFind, &id);
    if (FUN_140947540(pFind, pEnd) != 0) {
        int nValue;
        pEnt->GetPropertyValueUnsafe(id, &nValue, FUN_1408a1ff0());
        int* pCopy = (int*)operator new(4);
        if (pCopy != 0)
            *pCopy = nValue;
        Unk_PropRec rec;
        void* r = FUN_140947490(&rec, id, pCopy, FUN_1408a1ff0());
        memcpy(FUN_140947580(pTbl, &id), r, 0x18);
    }
}

// @0x1410dbd50 / 0x1410dbda0 / 0x1410dbdf0
template const egf::EntityChangeMessage* efd::DynamicCast<const egf::EntityChangeMessage, efd::IMessage>(const efd::IMessage*);
template const ecr::SceneGraphAddedMessage* efd::DynamicCast<const ecr::SceneGraphAddedMessage, efd::IMessage>(const efd::IMessage*);
template Unk_Service6100017* efd::DynamicCast<Unk_Service6100017, efd::ISystemService>(efd::ISystemService*);

// @0x1410dbe40 / 0x1410dbee0
template efd::SmartPointer<efd::IMessage> efd::GenericFactory<efd::SmartPointer<efd::IMessage>, unsigned>::GenerateFactoryMethod<egf::EntityChangeMessage>();
template efd::SmartPointer<efd::IMessage> efd::GenericFactory<efd::SmartPointer<efd::IMessage>, unsigned>::GenerateFactoryMethod<ecr::SceneGraphAddedMessage>();

// @0x1410dbf80
//   the house demolish dialog (class id given), null when it is not open
Unk_CMISDemolishUI* FUN_1410dbf80(unsigned nId)
{
    if (FUN_1403ed2b0() != 0) {
        MS2Ptr<UIObject> sp = FUN_1403ed2b0()->FUN_141adcea0((eUIClassID)nId);
        if (sp.get() != 0)
            return reinterpret_cast<Unk_CMISDemolishUI*>(dynamic_cast<UIHouseDemolishDialog*>(sp.operator->()));
    }
    return 0;
}

// @0x1410dc020   the house mark dialog
unsigned FUN_14112e2a0();
Unk_CMISHouseMark* FUN_1410dc020()
{
    CUIService* pUI = FUN_1403ed2b0();
    if (pUI == 0)
        return 0;
    MS2Ptr<UIObject> sp = pUI->FUN_141adcea0((eUIClassID)FUN_14112e2a0());
    if (sp.IsNull())
        return 0;
    return reinterpret_cast<Unk_CMISHouseMark*>(dynamic_cast<UIHouseMark*>(sp.operator->()));
}

// @0x1410dc0d0 / 0x1410dc0e0
unsigned FUN_1410dc0d0() { return 0xffffffffu; }
unsigned FUN_1410dc0e0() { return 0x7ffffffu; }

// @0x1410dc0f0
template void efd::RegisterMessageWrapperFactory<egf::EntityChangeMessage, 0x203d>(efd::GenericFactory<efd::SmartPointer<efd::IMessage>, unsigned>*);

// @0x1410dc360   egf::Entity::SetPropertyValue<int>: refreshes the client cache before the engine write
template <> egf::PropertyResult egf::Entity::SetPropertyValue<int>(egf::PropertyID propID, const int& data)
{
    FUN_1410dbc10(this, propID, &data);
    return SetPropertyValueUnsafe(propID, &data, FUN_1408a1ff0());
}

// @0x1410dc3b0   house sale marker record factory
// MS2-FUNCTIONAL 0x1410dc3b0: the exe is a value-initializing `new SalesInfo()` (memset 0x38, then the implicit ctor 0x1411232e0 under
//   the new-expression's EH frame); here SalesInfo's ctor is user-provided (defined out of line by unit_141121cf0), so value-init
//   would skip the memset - written as operator new + memset + placement new instead.
void* FUN_1410dc3b0(void* pTag)
{
    SalesInfo* p = (SalesInfo*)operator new(0x38);
    if (p == 0)
        return 0;
    memset(p, 0, 0x38);
    return new (p) SalesInfo();
}
