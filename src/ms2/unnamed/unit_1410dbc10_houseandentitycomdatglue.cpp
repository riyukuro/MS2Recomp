// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). COMDAT/glue tail between the house-mark and cube-map units: the
// egf::Entity int property write with the client's property cache, efd::DynamicCast / GenericFactory / message-wrapper
// instantiations for EntityChangeMessage and SceneGraphAddedMessage, the UI lookups for the house demolish dialog and the
// house mark, and three tiny factory / constant helpers.
// MS2-UNIT: unit_1410dbc10
// MS2-RANGE: 0x1410dbc10-0x1410dc420 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
// MS2-PIN: ??$DynamicCast@VCubeMapInformationService@@VISystemService@efd@@@efd@@YAPEAVCubeMapInformationService@@PEAVISystemService@0@@Z 0x1410dbdf0
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
#include "ms2/placeholder/propertycache.h"
#include "ms2/client/ms2/cubemapinformationservice_tail.h"

// ---- unrecovered helpers ----

void* FUN_140876480(void* out, int nCategory);                                  // memory category helper, returns the category
void* FUN_14208a860(unsigned __int64 nSize, unsigned nCategory);                // category allocation

struct Unk_EntityPropertyAccess : egf::Entity
{
    using egf::Entity::GetPropertyValueUnsafe;
    using egf::Entity::SetPropertyValueUnsafe;
};

// The service that owns the cube-map information (class id 0x06100017), the same stand-in as unit_140fa9eb0's.
// C3: Unk_Service6100017 was CubeMapInformationService (cubemapinformationservice_3.h)
//
//
//


struct Unk_CMISDemolishUI;
class Unk_CMISHouseMark;

// @0x1410dbc10
void FUN_1410dbc10(egf::Entity* e, unsigned id, const int* pVal)
{
    if (*((unsigned char*)e + 0xc8)) {
        if (((Unk_CachedEntity*)e)->m_mapCache.find(id) == ((Unk_CachedEntity*)e)->m_mapCache.end()) {
            int nValue;
            ((Unk_EntityPropertyAccess*)e)->GetPropertyValueUnsafe(id, &nValue, efd::GetClassIDFromType<int>());
            ((Unk_CachedEntity*)e)->m_mapCache[id] = Unk_PropertyCacheEntry(id, new int(nValue), efd::GetClassIDFromType<int>());
        }
    }
}

// @0x1410dbd50 / 0x1410dbda0 / 0x1410dbdf0
template const egf::EntityChangeMessage* efd::DynamicCast<const egf::EntityChangeMessage, efd::IMessage>(const efd::IMessage*);
template const ecr::SceneGraphAddedMessage* efd::DynamicCast<const ecr::SceneGraphAddedMessage, efd::IMessage>(const efd::IMessage*);
template CubeMapInformationService* efd::DynamicCast<CubeMapInformationService, efd::ISystemService>(efd::ISystemService*);

// @0x1410dbe40 / 0x1410dbee0
template efd::SmartPointer<efd::IMessage> efd::GenericFactory<efd::SmartPointer<efd::IMessage>, unsigned>::GenerateFactoryMethod<egf::EntityChangeMessage>();
template efd::SmartPointer<efd::IMessage> efd::GenericFactory<efd::SmartPointer<efd::IMessage>, unsigned>::GenerateFactoryMethod<ecr::SceneGraphAddedMessage>();

// @0x1410dbf80
//   the house demolish dialog (class id given), null when it is not open
Unk_CMISDemolishUI* FindHouseDemolishDialog(unsigned nId)
{
    if (TSingleton<CUIService>::GetInstance() != 0) {
        MS2Ptr<UIObject> sp = TSingleton<CUIService>::GetInstance()->FindObject((eUIClassID)nId);
        if (sp.get() != 0)
            return reinterpret_cast<Unk_CMISDemolishUI*>(dynamic_cast<UIHouseDemolishDialog*>(sp.operator->()));
    }
    return 0;
}

// @0x1410dc020   the house mark dialog
unsigned __int64 FUN_14112e2a0();
Unk_CMISHouseMark* FindHouseMark()
{
    CUIService* pUI = TSingleton<CUIService>::GetInstance();
    if (pUI == 0)
        return 0;
    MS2Ptr<UIObject> sp = pUI->FindObject((eUIClassID)FUN_14112e2a0());
    if (sp.IsNull())
        return 0;
    return reinterpret_cast<Unk_CMISHouseMark*>(dynamic_cast<UIHouseMark*>(sp.operator->()));
}

// @0x1410dc0d0 / 0x1410dc0e0
unsigned FUN_1410dc0d0() { return 0xffffffffu; }
unsigned FUN_1410dc0e0() { return 0x7ffffffu; }

// @0x1410dc0f0
template void efd::RegisterMessageWrapperFactory<egf::EntityChangeMessage, 0x203d>(efd::GenericFactory<efd::SmartPointer<efd::IMessage>, unsigned>*);

// The engine (egfLua SchedulerLua.cpp, built with MS2_ENTITY_PROPERTY_CACHE) instantiates the same body as a COMDAT;
// inline + noinline makes this one COMDAT-any too, so the full exe keeps a single copy instead of two strong
// definitions. The anchor below (no exe counterpart) makes this TU emit it.
// @0x1410dc360   egf::Entity::SetPropertyValue<int>: refreshes the client cache before the engine write
template <> inline __declspec(noinline) egf::PropertyResult egf::Entity::SetPropertyValue<int>(egf::PropertyID propID, const int& data)
{
    FUN_1410dbc10(this, propID, &data);
    return SetPropertyValueUnsafe(propID, &data, efd::GetClassIDFromType<int>());
}
egf::PropertyResult Unk_SetPropertyIntAnchor(egf::Entity* p, egf::PropertyID id, const int& n)
{ return p->SetPropertyValue<int>(id, n); }

// @0x1410dc3b0   house sale marker record factory
// The exe value-initializes: memset 0x38, then SalesInfo's implicit ctor (0x1411232e0).
void* CreateSalesInfo(void* pTag)
{
    return new SalesInfo();
}
