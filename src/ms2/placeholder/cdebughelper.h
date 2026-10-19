// cdebughelper.h - CDebugHelper (RTTI .?AVCDebugHelper@@, vftable at 0x14116bdc0's ctor): TSingleton that draws debug point /
// line meshes under the "Scene Root" node and keeps them alive in a list. NOT an original header (layout from the ctor).
#pragma once
#include <atlcoll.h>
#include <NiMesh.h>
#include <NiNode.h>
#include <NiColor.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/nipoint3.h"
#include "ms2/commonfiles/os.h"

class CDebugHelper : public TSingleton<CDebugHelper>
{
public:
    CDebugHelper();                                                 // 0x14116bdc0
    virtual ~CDebugHelper();                                        // 0x14116be20
    void FUN_14116be80();                                           // find the scene root
    void FUN_14116beb0(const NiPoint3* pPos, const NiColorA* pColor);   // one POINTS mesh
    void FUN_14116c580(const NiPoint3* pPos, const NiPoint3* pTarget, const void* pRot, const NiColorA* pColor);   // one LINES mesh
    void ClearMeshes();                                             // 0x14116cd50

    NiNode* m_pRoot;                                                // +0x8
    ATL::CAtlList<NiMeshPtr> m_meshes;                              // +0x10
};
MS2_CHECK_SIZE(CDebugHelper, 0x40);
MS2_CHECK_OFFSET(CDebugHelper, m_pRoot, 0x8);
MS2_CHECK_OFFSET(CDebugHelper, m_meshes, 0x10);
