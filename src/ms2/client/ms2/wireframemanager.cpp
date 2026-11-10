// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CWireframeManager: see wireframemanager.h.
// MS2-UNIT: ?\wireframemanager.cpp
// MS2-RANGE: 0x141b93fd0-0x141b94cb0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
// MS2-PIN: ?CompareElements@Unk_WfEntTraits@@SA_NAEBV?$SmartPointer@VEntity@egf@@@efd@@0@Z 0x141b945b0
// MS2-GUESS-LOOKALIKES
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\wireframemanager.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"
#include "wireframemanager.h"
#include <NiAVObject.h>
#include <NiWireframeProperty.h>
#include <egf/Entity.h>
#include <ecr/SceneGraphService.h>
#include "ms2/client/ms2/questmanager_2.h"
#include "ms2/commonfiles/timeutil.h"
#include "ms2/commonfiles/dungeonroom.h"   // C3: DungeonRoomTable::GetRoom
#include "ms2/placeholder/uiworldmap.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local views of exe objects ----

ecr::SceneGraphService* FUN_1413f98b0();                                // the scene graph service
void* FUN_140764020();                                                  // the quest manager


// ---- CWireframeManager ----

// @0x141b93fd0
CWireframeManager::CWireframeManager()
    : m_entities(10)
{
    m_bWireframe = false;
}

// @0x141b94030
CWireframeManager::~CWireframeManager()
{
    ClearEntities();
}

// @0x141b94090
void CWireframeManager::ClearEntities()
{
    m_entities.RemoveAll();
}

// @0x141b940c0
void CWireframeManager::AddEntity(egf::Entity* pEntity)
{
    NiAVObject* pObject = FUN_1413f98b0()->GetSceneGraphFromEntity(pEntity);
    if (pObject)
    {
        NiWireframeProperty* pWire = NiDynamicCast(NiWireframeProperty, pObject->GetProperty(NiProperty::WIREFRAME));
        if (pWire == 0)
        {
            pWire = NiNew NiWireframeProperty;
            pObject->AttachProperty(pWire);
        }
        pWire->SetWireframe(m_bWireframe);
        egf::EntityPtr ref(reinterpret_cast<egf::Entity*>(pEntity));
        m_entities.AddTail(ref);
    }
}

// @0x141b941f0
void CWireframeManager::RemoveEntity(egf::Entity* pEntity)
{
    POSITION pos;
    {
        egf::EntityPtr ref(reinterpret_cast<egf::Entity*>(pEntity));
        pos = m_entities.Find(ref, 0);
    }
    if (pos != 0)
        m_entities.RemoveAt(pos);
}

// @0x141b94260
void CWireframeManager::SetWireframe(bool bWireframe)
{
    m_bWireframe = bWireframe;
    POSITION pos = m_entities.GetHeadPosition();
    while (pos != 0)
    {
        egf::EntityPtr ref = m_entities.GetNext(pos);
        if (ref != 0)
        {
            NiAVObject* pObject = FUN_1413f98b0()->GetSceneGraphFromEntity(reinterpret_cast<egf::Entity*>(ref.data()));
            if (pObject)
            {
                NiWireframeProperty* pWire = NiDynamicCast(NiWireframeProperty, pObject->GetProperty(NiProperty::WIREFRAME));
                if (pWire)
                    pWire->SetWireframe(m_bWireframe);
            }
        }
    }
}

// @0x141b94370
void CWireframeManager::ToggleWireframe()
{
    SetWireframe(!m_bWireframe);
}

// @0x141b947e0
const void* CWireframeManager::vfunc_2()
{
    return &g_wireframeRegistrar;
}

// @0x141b94a70
MS2_EMIT_CRT_MEMMOVE_S_COPY(1);

// @0x141b94b90
// A world map tile gated by a dungeon room (+0x70) and a quest (+0x74): shown unless either is closed.
int UIWorldMap::MapTile::FUN_141b94b90()
{
    if (m_70 != 0)
    {
        DungeonRoomPtr room = TSingleton<DungeonRoomTable>::GetInstance()->GetRoom(m_70);
        if (room.get() ? true : false)
        {
            if (!room->m_limitDayOfWeeks.FUN_140b91330())
            {
                int nNow = GetServerDayOfWeek();
                if (!room->m_limitDayOfWeeks[nNow])
                    return 0;
            }
        }
    }
    if (m_74 != 0)
    {
        if (reinterpret_cast<CQuestManager*>(FUN_140764020())->IsQuestRewarded(m_74) == 0)
            return 0;
    }
    return 1;
}
