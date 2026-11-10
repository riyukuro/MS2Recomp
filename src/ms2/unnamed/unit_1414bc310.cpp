// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). NiVisualTracker graph callbacks of the performance overlay.
// MS2-UNIT: unit_1414bc310
// MS2-RANGE: 0x1414bc310-0x1414bc6c0 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "unit_1414bc310.h"
#include <efd/SmartPointer.h>
#include <efd/IBase.h>
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// The service whose averaged frame time is sampled (reached through the game's service manager).
class Unk_FrameTimeSource : public efd::IBase
{
};
class MS2SceneService   // C3: member view (ms2sceneservice.h needs PhysX without min/max)
{
public:
    float TakeAverageSimulateTime();                        // 0x1415040f0: average since the last call (resets the accumulator)
};

#include <efd/ServiceManager.h>
class Unk_ServiceManager* GetServiceManager();   // C3: was GetServiceManager
class Unk_PhysXSceneView; template <> Unk_PhysXSceneView* efd::ServiceManager::GetSystemServiceAs<Unk_PhysXSceneView>() const;   // 0x1411d15f0, entityworldmanager's scene service

// @0x1414bc310
ElapsedTimeUpdate::ElapsedTimeUpdate()
    : m_fElapsed(0.0f)
{
}

// @0x1414bc350
ElapsedTimeUpdate::ElapsedTimeUpdate(float fStart)
    : m_fElapsed(fStart)
{
}

// @0x1414bc3a0
float ElapsedTimeUpdate::TakeSample(float fTime)
{
    m_fElapsed += fTime / 1000.0f;
    return m_fElapsed;
}
MS2_REPLACE_METHOD(0x1414bc3a0, ElapsedTimeUpdate, TakeSample, 63, 0x85E2C484);

// @0x1414bc3f0
FrameEventUpdate::FrameEventUpdate()
{
}

// @0x1414bc430
float FrameEventUpdate::TakeSample(float fTime)
{
    efd::SmartPointer<Unk_FrameTimeSource> spSource(reinterpret_cast<Unk_FrameTimeSource*>(reinterpret_cast<efd::ServiceManager*>(GetServiceManager())->GetSystemServiceAs<Unk_PhysXSceneView>()));
    if (spSource)
        return reinterpret_cast<MS2SceneService*>(spSource.operator->())->TakeAverageSimulateTime() * 1000.0f;
    return 0.0f;
}
MS2_REPLACE_METHOD(0x1414bc430, FrameEventUpdate, TakeSample, 146, 0x3FA1487C);
