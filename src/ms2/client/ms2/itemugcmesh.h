// itemugcmesh.h - CItemUgcMesh and CItemUgcMeshContainer (RTTI names), the UGC (user-made texture) mesh list of an
// item model. Owning unit: ?\itemugcmesh.cpp (0x141423xxx-0x141427xxx, not recovered). Header name assumed.
//
// - CItemUgcMesh (0x30, base CPtred, vftable 0x142f119f8, 1 slot: ??_G 0x141427800). Ctor 0x141427500 (out of line,
//   itemugcmesh.cpp): CString +0x18, NiAVObjectPtr +0x20 (ctor 0x14097eba0), NiTexturePtr +0x28 (ctor 0x14097ed60).
// - CItemUgcMeshContainer (0x38, base CPtred, vftable 0x142ea73f8, 1 slot: ??_G 0x141086480). Its ctor (0x141086220),
//   dtor (0x141086340), ??_G and the CAtlArray<MS2Ptr<CItemUgcMesh>> instances are inline COMDATs first emitted by
//   ?\clonecube.cpp (CloneCube creates the container: new 0x38). The members are out of line in itemugcmesh.cpp.
// - Both are held through MS2Ptr<T> (ascript.h); include ms2ptr_impl.h where the MS2Ptr members must instantiate.
#pragma once
#include <atlcoll.h>
#include <NiAVObject.h>
#include <NiTexture.h>
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/ms2layout.h"

class CItemData;
class CEquipItem;

class CItemUgcMesh : public CPtred
{
public:
    CItemUgcMesh();                                         // 0x141427500
    // implicit virtual ~CItemUgcMesh()                     // 0x141427620 (??_G 0x141427800)

    MS2_LAYOUT_FRIEND;
    CString m_str18;                                        // +0x18
    NiAVObjectPtr m_spObject;                               // +0x20 mesh object
    NiTexturePtr m_spTexture;                               // +0x28 UGC texture (CloneCube::FUN_141085700 returns it)
};
MS2_CHECK_SIZE(CItemUgcMesh, 0x30);
MS2_CHECK_OFFSET(CItemUgcMesh, m_spObject, 0x20);
MS2_CHECK_OFFSET(CItemUgcMesh, m_spTexture, 0x28);

class CItemUgcMeshContainer : public CPtred
{
public:
    // @0x141086220
    CItemUgcMeshContainer() {}
    // Implicit virtual dtor (0x141086340, pinned in clonecube.cpp): no vptr store, just ~CAtlArray + ~CPtred.

    void FUN_141426140();                                   // 0x141426140 m_meshes.RemoveAll()
    // Rebuilds the mesh list for spData under spRoot; false if either is null or nothing was found. Both by value.
    bool FUN_141426540(MS2Ptr<CItemData> spData, NiAVObjectPtr spRoot);   // 0x141426540
    void FUN_141426980();                                   // 0x141426980 re-applies the texture of every mesh
    NiTexturePtr FUN_141426d40();                           // 0x141426d40 texture of the first mesh (or null)
    // itemugcmesh.cpp (appended by w79): rebuild from an equip item's parts, helpers
    bool FUN_141426170(MS2Ptr<CEquipItem> spItem);          // 0x141426170
    void FUN_141426750(CAtlArray<CString>& aNames, void* pItemData);   // 0x141426750 part names of the item data
    void FUN_141426810(NiTexture* pTexture);                // 0x141426810 sets the texture on every mesh
    MS2Ptr<CItemUgcMesh> FUN_141426af0(const CString& strName, NiAVObjectPtr spRoot);   // 0x141426af0
    NiTexturePtr FUN_141426e30();                           // 0x141426e30 decal texture of the first mesh's object

    MS2_LAYOUT_FRIEND;
    ATL::CAtlArray<MS2Ptr<CItemUgcMesh> > m_meshes;         // +0x18
};
MS2_CHECK_SIZE(CItemUgcMeshContainer, 0x38);
MS2_CHECK_OFFSET(CItemUgcMeshContainer, m_meshes, 0x18);
