// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CWireframeManager: see wireframemanager.h.
// MS2-UNIT: ?\wireframemanager.cpp
// MS2-RANGE: 0x141b93fd0-0x141b94cb0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
// MS2-PIN: ?CompareElements@Unk_WfEntTraits@@SA_NAEBUUnk_EntRef@@0@Z 0x141b945b0
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
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local views of exe objects ----

ecr::SceneGraphService* FUN_1413f98b0();                                // the scene graph service
CQuestManager* FUN_140764020();                                         // the quest manager

// The dungeon room table: a record handle (released through FUN_14031c0f0) and the room's open period.
void FUN_14031c0f0(struct Unk_WfRoomRef* pRoom);
struct Unk_WfRoomRef { void* m_0; void* m_8; ~Unk_WfRoomRef() { FUN_14031c0f0(this); } };
struct Unk_WfSpan
{
    __int64 m_nStart;
    __int64 m_nEnd;
    Unk_WfSpan();                                                       // declared only (keeps the temporary out of /GS)
    bool FUN_140837280();                                               // the time is inside the period
};
struct Unk_WfPeriodVal
{
    char m_data[16];
    Unk_WfSpan FUN_1402e4e80(int nTime);                                // the period relative to the time
};
struct Unk_WfPeriod { char m_pad[0x106]; Unk_WfPeriodVal m_period; };
class Unk_WfRoomTable { public: Unk_WfRoomRef FUN_1403206b0(int nRoomId); };
Unk_WfRoomTable* FUN_14031c2a0();
void* FUN_14031c160(Unk_WfRoomRef* pRoom);                               // the handle is valid
Unk_WfPeriod* FUN_1403347d0(Unk_WfRoomRef* pRoom);                      // the room record
bool FUN_140b91330(void* pPeriod);                                      // the period is unlimited

// An entry that can be gated by a dungeon room and a quest (the tail of this unit's range).
struct Unk_WfGate
{
    char m_pad[0x70];
    int m_nRoomId;                                                      // +0x70
    int m_nQuestId;                                                     // +0x74
    int FUN_141b94b90();                                                // the gate is open
};

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
    FUN_141b94090();
}

// @0x141b94090
void CWireframeManager::FUN_141b94090()
{
    m_entities.RemoveAll();
}

// @0x141b940c0
void CWireframeManager::FUN_141b940c0(egf::Entity* pEntity)
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
        Unk_EntRef ref(reinterpret_cast<Unk_Entity*>(pEntity));
        m_entities.AddTail(ref);
    }
}

// @0x141b941f0
void CWireframeManager::FUN_141b941f0(egf::Entity* pEntity)
{
    POSITION pos;
    {
        Unk_EntRef ref(reinterpret_cast<Unk_Entity*>(pEntity));
        pos = m_entities.Find(ref, 0);
    }
    if (pos != 0)
        m_entities.RemoveAt(pos);
}

// @0x141b94260
void CWireframeManager::FUN_141b94260(bool bWireframe)
{
    m_bWireframe = bWireframe;
    POSITION pos = m_entities.GetHeadPosition();
    while (pos != 0)
    {
        Unk_EntRef ref = m_entities.GetNext(pos);
        if (ref != 0)
        {
            NiAVObject* pObject = FUN_1413f98b0()->GetSceneGraphFromEntity(reinterpret_cast<egf::Entity*>(ref.FUN_1408a9090()));
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
void CWireframeManager::FUN_141b94370()
{
    FUN_141b94260(!m_bWireframe);
}

// @0x141b947e0
const void* CWireframeManager::vfunc_2()
{
    return &g_wireframeRegistrar;
}

// @0x141b94a70
MS2_EMIT_CRT_MEMMOVE_S_COPY(1);

// @0x141b94b90
int Unk_WfGate::FUN_141b94b90()
{
    if (m_nRoomId != 0)
    {
        Unk_WfRoomRef room = FUN_14031c2a0()->FUN_1403206b0(m_nRoomId);
        if (FUN_14031c160(&room) ? true : false)
        {
            if (!FUN_140b91330(&FUN_1403347d0(&room)->m_period))
            {
                int nNow = GetServerDayOfWeek();
                if (!FUN_1403347d0(&room)->m_period.FUN_1402e4e80(nNow).FUN_140837280())
                    return 0;
            }
        }
    }
    if (m_nQuestId != 0)
    {
        if (FUN_140764020()->FUN_140745590(m_nQuestId) == 0)
            return 0;
    }
    return 1;
}
