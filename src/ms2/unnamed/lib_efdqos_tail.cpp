// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Foundation (efd) functions the engine stage leaves
// unpaired: the efd::AssetLoaderThreadFunctor constructor and thread loop, and efd::QOSCompare's config reader with its
// two enum lookups and the DataDrivenEnum<UInt32>::FindEnumValue instance they call. Free functions under the exe's own
// FUN_<va> names, so they cannot collide with the engine-stage efd definitions.
// MS2-UNIT: lib_efdqos_tail
// MS2-RANGE: 0x1420e5f50-0x1420e5fcc .text$mn
// MS2-RANGE: 0x1420e6090-0x1420e60e7 .text$mn
// MS2-RANGE: 0x1420e62a0-0x1420e636c .text$mn
// MS2-RANGE: 0x1420e6380-0x1420e6d15 .text$mn
// MS2-FLAGS: gamebryo
// MS2-PIN: ?FindEnumValue@?$DataDrivenEnum@I@efd@@QEAA_NAEBVutf8string@2@AEAI@Z 0x1420e62a0
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include <efd/QOSCompare.h>
#include <efd/efdQualityOfService.h>
#include <efd/efdVirtualQualityOfService.h>
#include <efd/IConfigManager.h>
#include <efd/EnumManager.h>
#include <efd/DataDrivenEnum.h>
#include <efd/efdLogIDs.h>
#include <efd/Logger.h>
#include <windows.h>
#include <stdlib.h>

// efd::AssetLoaderThreadFunctor: ThreadFunctor at +0, the background AssetFactoryManager at +0x10.
struct AssetLoaderThreadFunctorLayout
{
    void** vftable;              // ThreadFunctor
    char pad08[0x08];
    void** managerVftable;       // AssetFactoryManager
    char pad18[0xd0 - 0x18];
    volatile bool m_shutdown;
};
void FUN_1420af780(void* self);                                                     // ThreadFunctor::ThreadFunctor
void FUN_14209f570(void* self, size_t requestQueueSize, efd::UInt32 sleepInterval, void* pFore);   // AssetFactoryManager::AssetFactoryManager
extern "C" void* DAT_1430d1b68[];   // AssetLoaderThreadFunctor vftable (ThreadFunctor part)
extern "C" void* DAT_1430d1b80[];   // AssetLoaderThreadFunctor vftable (AssetFactoryManager part)

// AssetLoaderThreadFunctor::AssetLoaderThreadFunctor(requestQueueSize, pForeAssetFactoryManager): a background
// AssetFactoryManager that takes the foreground manager's sleep interval (+0xb8).
// MS2-FUNCTIONAL: the exe gives the ctor an EH frame that unwinds the ThreadFunctor base if the AssetFactoryManager
// base throws; this raw-layout version constructs both bases through their out-of-line ctors without one.
// @0x1420e5f50
AssetLoaderThreadFunctorLayout* FUN_1420e5f50(AssetLoaderThreadFunctorLayout* self, efd::UInt32 requestQueueSize,
    const char* pForeAssetFactoryManager)
{
    FUN_1420af780(self);
    FUN_14209f570(&self->managerVftable, requestQueueSize,
        *(const efd::UInt32*)(pForeAssetFactoryManager + 0xb8), (void*)pForeAssetFactoryManager);
    self->vftable = DAT_1430d1b68;
    self->managerVftable = DAT_1430d1b80;
    self->m_shutdown = false;
    return self;
}

// AssetLoaderThreadFunctor::Execute: ticks the background manager (vftable +0x68, OnTick) until shut down, then calls
// DoShutdown (vftable +0x10). MS2's YieldThread sleeps for 1 ms.
// @0x1420e6090
efd::UInt32 FUN_1420e6090(AssetLoaderThreadFunctorLayout* self, void* pArg)
{
    while (!self->m_shutdown)
    {
        ((void (*)(void*))self->managerVftable[0x68 / 8])(&self->managerVftable);
        Sleep(1);
    }
    ((void (*)(void*))self->vftable[0x10 / 8])(self);
    return 0;
}

// The out-of-line instance the QOS lookups call.
// MS2-FUNCTIONAL: codegen only: the exe keeps std::less<utf8string> (0x140999060) out of line and uses an r11 frame.
template bool efd::DataDrivenEnum<efd::UInt32>::FindEnumValue(const efd::utf8string&, efd::UInt32&);   // 0x1420e62a0

// QOSCompare.cpp's file statics and QOSCompare's static members.
extern "C" const char* DAT_143a0eae8;   // kConfigSection "QualityOfService"
extern "C" const char* DAT_143a0eaf0;   // kVirtualQOSEnum "efdVirtualQualityOfService"
extern "C" const char* DAT_143a0eaf8;   // kPhysicalQOSEnum "efdQualityOfService"
extern "C" efd::QualityOfService DAT_143a0eae0;   // QOSCompare::ms_defaultQualityOfService
extern "C" bool DAT_143b05548;                    // QOSCompare::ms_configRead
extern "C" efd::map<efd::QualityOfService, efd::QualityOfService> DAT_143b05550;   // QOSCompare::ms_virtualToPhysical

// QOSCompare::GetPhysicalQOS: the named physical QOS from the "efdQualityOfService" enum, else atoi of the name.
// MS2-FUNCTIONAL: codegen only: the exe keeps the utf8string(const char*) ctor (0x1409989e0) out of line and uses an r11 frame.
// @0x1420e6380
efd::QualityOfService FUN_1420e6380(efd::EnumManager* pEnumManager, const efd::utf8string& stringName)
{
    efd::QualityOfService foundQOS = efd::QOS_INVALID;
    if (pEnumManager)
    {
        efd::DataDrivenEnumBase* pEnum = pEnumManager->FindOrLoadEnum(DAT_143a0eaf8);
        if (pEnum)
        {
            efd::SmartPointer< efd::DataDrivenEnum<efd::UInt32> > spQOSEnum = pEnum->CastTo<efd::UInt32>();
            if (spQOSEnum && spQOSEnum->FindEnumValue(stringName, foundQOS))
                return foundQOS;
        }
    }
    foundQOS = atoi(stringName.c_str());
    return foundQOS;
}

// QOSCompare::GetVirtualQOS: the same lookup in the "efdVirtualQualityOfService" enum.
// MS2-FUNCTIONAL: codegen only: the exe keeps the utf8string(const char*) ctor (0x1409989e0) out of line and uses an r11 frame.
// @0x1420e64b0
efd::QualityOfService FUN_1420e64b0(efd::EnumManager* pEnumManager, const efd::utf8string& stringName)
{
    efd::QualityOfService foundQOS = efd::QOS_INVALID;
    if (pEnumManager)
    {
        efd::DataDrivenEnumBase* pEnum = pEnumManager->FindOrLoadEnum(DAT_143a0eaf0);
        if (pEnum)
        {
            efd::SmartPointer< efd::DataDrivenEnum<efd::UInt32> > spVirtualEnum = pEnum->CastTo<efd::UInt32>();
            if (spVirtualEnum && spVirtualEnum->FindEnumValue(stringName, foundQOS))
                return foundQOS;
        }
    }
    foundQOS = atoi(stringName.c_str());
    return foundQOS;
}

#define QOS_FILE "d:\\dev\\gamebryo\\engine\\source\\foundation\\efd\\qoscompare.cpp"
#define QOS_FUNCTION "efd::QOSCompare::ReadConfig"

// QOSCompare::ReadConfig: maps virtual to physical QOS, once. Unreliable and connectionless default to their
// unreliable physical QOS; the [QualityOfService] config section can set the physical Default and add mappings.
// MS2-FUNCTIONAL: codegen only: the exe keeps the utf8string(const char*) ctor (0x1409989e0) and the map's
// std::less out of line, inlines GetVirtualQOS, and uses an r11 frame.
// @0x1420e65e0
void FUN_1420e65e0(efd::IConfigManager* pConfigManager, efd::EnumManager* pEnumManager)
{
    if (DAT_143b05548)
        return;
    DAT_143b05548 = true;

    DAT_143b05550[efd::QOS_UNRELIABLE] = efd::kQOS_Unreliable;
    DAT_143b05550[efd::QOS_CONNECTIONLESS] = efd::kQOS_UnreliableConnectionless;

    if (!pConfigManager)
        return;
    const efd::ISection* pRoot = pConfigManager->GetConfiguration();

    const efd::ISection* config = pRoot->FindSection(DAT_143a0eae8);
    if (config)
    {
        efd::utf8string defaultQOS = config->FindValue("Default");
        if (!defaultQOS.empty())
        {
            efd::QualityOfService physicalQOS = FUN_1420e6380(pEnumManager, defaultQOS);
            if (physicalQOS != efd::QOS_INVALID)
            {
                DAT_143a0eae0 = physicalQOS;
            }
            else
            {
                EE_LOG_AT(efd::kNetwork, efd::ILogger::kERR1,
                    ("%s> Invalid Default physical QualityOfService:%s", QOS_FUNCTION, defaultQOS.c_str()),
                    QOS_FILE, 124);
            }
        }
        efd::ValueIter end = config->GetEndValueIterator();
        efd::ValueIter i = config->GetBeginValueIterator();
        for (; i != end; ++i)
        {
            efd::QualityOfService virtualQOS = FUN_1420e64b0(pEnumManager, i->first);
            efd::QualityOfService physicalQOS = FUN_1420e6380(pEnumManager, i->second->GetValue());
            bool invalid = false;
            if (virtualQOS == efd::QOS_INVALID)
            {
                EE_LOG_AT(efd::kNetwork, efd::ILogger::kERR1,
                    ("%s> Invalid virtual QualityOfService:%s", QOS_FUNCTION, i->first.c_str()),
                    QOS_FILE, 142);
                invalid = true;
            }
            if (physicalQOS == efd::QOS_INVALID)
            {
                EE_LOG_AT(efd::kNetwork, efd::ILogger::kERR1,
                    ("%s> Invalid physical QualityOfService:%s", QOS_FUNCTION, i->second->GetValue().c_str()),
                    QOS_FILE, 152);
                invalid = true;
            }

            if (!invalid)
                DAT_143b05550[virtualQOS] = physicalQOS;
        }
    }
}
