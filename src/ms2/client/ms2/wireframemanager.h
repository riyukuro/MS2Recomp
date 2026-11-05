// wireframemanager.h - CWireframeManager (RTTI .?AVCWireframeManager@@, 0x48 bytes, NiRefObject): the world service's
// "show wireframe" switch. It keeps the entities that were switched to wireframe (an NiWireframeProperty on their scene
// graph) and flips the property of all of them at once. Owned by the WorldService (m_340). Owning unit:
// ?\wireframemanager.cpp (0x141b93fd0-0x141b94cb0, dir client\ms2); header name assumed from the unit path.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include <NiRefObject.h>
#include "ms2/ms2layout.h"
#include "ms2/client/ms2/cubespawnobject.h"

namespace egf { class Entity; }

// The list's element traits: the entity handles compare through efd::SmartPointer<egf::Entity>::operator==
// (0x14168af30).
struct Unk_WfEntTraits : public ATL::CElementTraitsBase<egf::EntityPtr>
{
    // MS2-FUNCTIONAL: the exe copy loads the result through a movzx/cmp pair
    static bool CompareElements(const egf::EntityPtr& a, const egf::EntityPtr& b)
    {
        return (a == b) != 0;
    }
};

// C3: the TU's "registrar" is the class's NiRTTI: its ctor 0x141d16b90 is NiRTTI::NiRTTI(const char*, const NiRTTI*)
// ([this] = m_pcName, [this+8] = m_pkBaseRTTI), and vfunc_2 returns its address (GetRTTI).
#include <NiRTTI.h>
//
//
//
//
//
extern NiRTTI g_wireframeRegistrar;           // 0x143af8110

class CWireframeManager : public NiRefObject
{
public:
    CWireframeManager();                                        // 0x141b93fd0
    virtual ~CWireframeManager();                               //  0 0x141b94030 (??_G 0x141b944d0)
    virtual const void* vfunc_2();                              //  2 0x141b947e0 the registrar object of the class

    void FUN_141b94090();                                       // forget every entity
    void FUN_141b940c0(egf::Entity* pEntity);                   // add an entity: give it a wireframe property
    void FUN_141b941f0(egf::Entity* pEntity);                   // remove an entity
    void FUN_141b94260(bool bWireframe);                        // switch every entity
    void FUN_141b94370();                                       // flip the switch

private:
    MS2_LAYOUT_FRIEND;
    ATL::CAtlList<egf::EntityPtr, Unk_WfEntTraits> m_entities;      // +0x10 (block size 10)
    bool m_bWireframe;                                          // +0x40
};
MS2_CHECK_OFFSET(CWireframeManager, m_entities, 0x10);
MS2_CHECK_OFFSET(CWireframeManager, m_bWireframe, 0x40);
MS2_CHECK_SIZE(CWireframeManager, 0x48);
